#ifndef __SEATALK__MESSAGE_24__HPP__
#define __SEATALK__MESSAGE_24__HPP__

#include <marnav/seatalk/message.hpp>

namespace marnav
{
namespace seatalk
{

/// @brief Display units for Mileage and Speed
///
/// @code
/// 24 02 00 00 XX
///
/// XX:
///  0x00 : nautical miles (1852m), knots (nautical miles per hour)
///  0x06 : statute miles (1609.3m), statute miles per hour
///  0x86 : kilometers (1000m), kilometers per hour
/// @endcode
///
class message_24 : public message
{
public:
	constexpr static const message_id ID = message_id::display_units_mileage_speed;

	enum unit_type : uint8_t {
		nautical_miles = 0x00,
		knots = 0x00,
		statute_miles = 0x06,
		statute_miles_per_hour = 0x06,
		kilometers = 0x86,
		kilometers_per_hour = 0x86,
	};

	message_24();
	message_24(const message_24 &) = default;
	message_24 & operator=(const message_24 &) = default;

	virtual raw get_data() const override;

	static std::unique_ptr<message> parse(const raw & data) throw(std::invalid_argument);

private:
	unit_type unit;

public:
	unit_type get_unit() const { return unit; }

	void set_unit(unit_type t) { unit = t; }
};
}
}

#endif
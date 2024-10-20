#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <ctime>
#include <stdexcept>
#include <iostream>

enum class VehicleType { CAR, TRUCK, VAN, MOTORCYCLE, ELECTRIC };
enum class SpotType { COMPACT, LARGE, HANDICAPPED, MOTORCYCLE, ELECTRIC };
enum class PaymentType { CREDIT_CARD, CASH };
enum class TicketStatus { ACTIVE, PAID, LOST };
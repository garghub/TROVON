static inline T_1 F_1 ( struct V_1 V_2 )
{
return ( V_2 . V_3 << 8 )
| ( V_2 . V_4 << 6 )
| V_2 . V_5 ;
}
static inline T_1 F_2 ( struct V_1 V_2 )
{
return ( ( V_2 . V_5 - 2 ) << 16 )
| ( V_2 . V_4 << 10 )
| ( V_2 . V_3 - 2 ) ;
}
static inline T_1 F_3 ( struct V_1 V_2 )
{
return ( V_2 . V_5 << 16 )
| ( V_2 . V_4 << 10 )
| V_2 . V_3 ;
}
static inline void F_4 ( T_1 V_6 )
{
F_5 ( V_7 , 0x40 , 0x02 , 0x02 ) ;
F_6 ( V_7 , 0x46 , V_6 & 0xFF ) ;
F_6 ( V_7 , 0x47 , ( V_6 >> 8 ) & 0xFF ) ;
F_5 ( V_7 , 0x40 , 0x00 , 0x02 ) ;
}
static inline void F_7 ( T_1 V_6 )
{
F_5 ( V_7 , 0x40 , 0x02 , 0x02 ) ;
F_6 ( V_7 , 0x44 , V_6 & 0xFF ) ;
F_6 ( V_7 , 0x45 , ( V_6 >> 8 ) & 0xFF ) ;
F_6 ( V_7 , 0x46 , ( V_6 >> 16 ) & 0xFF ) ;
F_5 ( V_7 , 0x40 , 0x00 , 0x02 ) ;
}
static inline void F_8 ( T_1 V_6 )
{
F_5 ( V_7 , 0x40 , 0x04 , 0x04 ) ;
F_6 ( V_7 , 0x44 , V_6 & 0xFF ) ;
F_6 ( V_7 , 0x45 , ( V_6 >> 8 ) & 0xFF ) ;
F_5 ( V_7 , 0x40 , 0x00 , 0x04 ) ;
}
static inline void F_9 ( T_1 V_6 )
{
F_5 ( V_7 , 0x40 , 0x04 , 0x04 ) ;
F_6 ( V_7 , 0x4A , V_6 & 0xFF ) ;
F_6 ( V_7 , 0x4B , ( V_6 >> 8 ) & 0xFF ) ;
F_6 ( V_7 , 0x4C , ( V_6 >> 16 ) & 0xFF ) ;
F_5 ( V_7 , 0x40 , 0x00 , 0x04 ) ;
}
static inline void F_10 ( T_1 V_6 )
{
F_5 ( V_7 , 0x40 , 0x01 , 0x01 ) ;
F_6 ( V_7 , 0x47 , V_6 & 0xFF ) ;
F_6 ( V_7 , 0x48 , ( V_6 >> 8 ) & 0xFF ) ;
F_6 ( V_7 , 0x49 , ( V_6 >> 16 ) & 0xFF ) ;
F_5 ( V_7 , 0x40 , 0x00 , 0x01 ) ;
}
static void F_11 ( struct V_1 V_8 )
{
F_4 ( F_1 ( V_8 ) ) ;
}
static void F_12 ( struct V_1 V_8 )
{
F_7 ( F_2 ( V_8 ) ) ;
}
static void F_13 ( struct V_1 V_8 )
{
F_7 ( F_3 ( V_8 ) ) ;
}
static void F_14 ( struct V_1 V_8 )
{
F_8 ( F_1 ( V_8 ) ) ;
}
static void F_15 ( struct V_1 V_8 )
{
F_9 ( F_2 ( V_8 ) ) ;
}
static void F_16 ( struct V_1 V_8 )
{
F_9 ( F_3 ( V_8 ) ) ;
}
static void F_17 ( struct V_1 V_8 )
{
F_10 ( F_2 ( V_8 ) ) ;
}
static void F_18 ( struct V_1 V_8 )
{
F_10 ( F_3 ( V_8 ) ) ;
}
static void F_19 ( T_2 V_9 )
{
T_2 V_10 ;
switch ( V_9 ) {
case V_11 :
V_10 = 0x20 ;
break;
case V_12 :
V_10 = 0x00 ;
break;
default:
return;
}
F_5 ( V_7 , 0x2D , V_10 , 0x30 ) ;
}
static void F_20 ( T_2 V_9 )
{
T_2 V_10 ;
switch ( V_9 ) {
case V_11 :
V_10 = 0x08 ;
break;
case V_12 :
V_10 = 0x00 ;
break;
default:
return;
}
F_5 ( V_7 , 0x2D , V_10 , 0x0C ) ;
}
static void F_21 ( T_2 V_9 )
{
T_2 V_10 ;
switch ( V_9 ) {
case V_11 :
V_10 = 0x02 ;
break;
case V_12 :
V_10 = 0x00 ;
break;
default:
return;
}
F_5 ( V_7 , 0x2D , V_10 , 0x03 ) ;
}
static void F_22 ( T_2 V_9 )
{
T_2 V_10 ;
switch ( V_9 ) {
case V_11 :
V_10 = 0x20 ;
break;
case V_12 :
V_10 = 0x00 ;
break;
default:
return;
}
F_5 ( V_7 , 0x1B , V_10 , 0x30 ) ;
}
static void F_23 ( T_2 V_9 )
{
T_2 V_10 ;
switch ( V_9 ) {
case V_11 :
V_10 = 0x80 ;
break;
case V_12 :
V_10 = 0x00 ;
break;
default:
return;
}
F_5 ( V_7 , 0x1B , V_10 , 0xC0 ) ;
}
static inline T_2 F_24 ( enum V_13 V_14 , bool V_15 )
{
T_2 V_6 = 0 ;
switch ( V_14 ) {
case V_16 :
V_6 = 0x00 ;
break;
case V_17 :
V_6 = 0x02 ;
break;
case V_18 :
V_6 = 0x04 ;
break;
case V_19 :
V_6 = 0x0A ;
break;
case V_20 :
V_6 = 0xC ;
break;
case V_21 :
V_6 = 0x0E ;
break;
}
if ( ! V_15 )
V_6 |= 1 ;
return V_6 ;
}
static void F_25 ( enum V_13 V_14 , bool V_15 )
{
T_2 V_6 = F_24 ( V_14 , V_15 ) << 4 ;
F_5 ( V_22 , 0x6C , V_6 , 0xF0 ) ;
}
static void F_26 ( enum V_13 V_14 , bool V_15 )
{
T_2 V_6 = F_24 ( V_14 , V_15 ) ;
F_5 ( V_22 , 0x6C , V_6 , 0x0F ) ;
}
static void F_27 ( T_2 V_9 )
{
F_28 ( V_23 L_1 , V_24 ) ;
}
static void F_29 ( enum V_13 V_14 , bool V_15 )
{
F_28 ( V_23 L_2 , V_24 ) ;
}
static void F_30 ( T_2 V_9 )
{
F_28 ( V_23 L_3 , V_24 ) ;
}
static void F_31 ( struct V_1 V_8 )
{
F_28 ( V_23 L_4 , V_24 ) ;
}
static void F_32 ( T_2 V_9 )
{
}
void F_33 ( struct V_25 * clock , int V_26 )
{
switch ( V_26 ) {
case V_27 :
case V_28 :
clock -> F_22 = F_27 ;
clock -> F_25 = F_29 ;
clock -> F_19 = F_30 ;
clock -> V_29 = F_11 ;
clock -> F_23 = F_27 ;
clock -> F_26 = F_29 ;
clock -> F_20 = F_30 ;
clock -> V_30 = F_14 ;
clock -> F_21 = F_30 ;
clock -> V_31 = F_31 ;
break;
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
clock -> F_22 = F_22 ;
clock -> F_25 = F_25 ;
clock -> F_19 = F_19 ;
clock -> V_29 = F_12 ;
clock -> F_23 = F_23 ;
clock -> F_26 = F_26 ;
clock -> F_20 = F_20 ;
clock -> V_30 = F_15 ;
clock -> F_21 = F_21 ;
clock -> V_31 = F_17 ;
break;
case V_41 :
case V_42 :
clock -> F_22 = F_22 ;
clock -> F_25 = F_25 ;
clock -> F_19 = F_19 ;
clock -> V_29 = F_13 ;
clock -> F_23 = F_23 ;
clock -> F_26 = F_26 ;
clock -> F_20 = F_20 ;
clock -> V_30 = F_16 ;
clock -> F_21 = F_21 ;
clock -> V_31 = F_18 ;
break;
}
if ( F_34 () ) {
clock -> F_22 = F_32 ;
clock -> F_23 = F_32 ;
}
}

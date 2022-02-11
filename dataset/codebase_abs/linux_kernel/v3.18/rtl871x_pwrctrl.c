void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
if ( V_6 -> V_4 == V_3 ) {
if ( V_6 -> V_8 == 0 )
return;
}
if ( ( V_2 -> V_9 == true ) ||
( V_2 -> V_10 == true ) )
return;
V_4 = V_3 | V_6 -> V_11 ;
switch ( V_3 ) {
case V_12 :
V_6 -> V_13 = V_3 ;
break;
case V_14 :
case V_15 :
case V_16 :
V_6 -> V_13 = V_3 ;
break;
default:
break;
}
V_6 -> V_8 = 0 ;
V_6 -> V_4 = V_3 ;
F_2 ( V_2 , 0x1025FE58 , V_4 ) ;
V_6 -> V_11 += 0x80 ;
}
void F_3 ( struct V_1 * V_2 , T_2 V_17 , T_2 V_18 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
if ( V_17 > V_19 )
return;
if ( V_17 == V_20 )
V_18 = 0 ;
if ( ( V_6 -> V_21 != V_17 ) || ( V_6 -> V_18 != V_18 ) ) {
if ( V_6 -> V_21 == V_20 )
V_6 -> V_22 = true ;
else
V_6 -> V_22 = false ;
V_6 -> V_21 = V_17 ;
V_6 -> V_18 = V_18 ;
F_4 ( & V_6 -> V_23 ) ;
}
}
void F_5 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_5 * V_6 = & ( V_2 -> V_7 ) ;
struct V_26 * V_27 = & ( V_2 -> V_28 ) ;
if ( V_6 -> V_29 == ( ( V_25 -> V_30 ) & 0x80 ) )
return;
F_6 ( & V_2 -> V_7 . V_31 ) ;
F_7 ( & V_6 -> V_32 ) ;
V_6 -> V_13 = ( V_25 -> V_30 ) & 0xf ;
if ( V_6 -> V_13 >= V_14 ) {
if ( V_6 -> V_33 & V_34 )
F_8 ( & ( V_27 -> V_35 ) ) ;
}
V_6 -> V_29 = ( V_25 -> V_30 ) & 0x80 ;
F_8 ( & V_6 -> V_32 ) ;
}
static inline void F_9 ( struct V_5 * V_36 , T_2 V_37 )
{
V_36 -> V_33 |= V_37 ;
}
static inline void F_10 ( struct V_5 * V_36 , T_2 V_37 )
{
if ( V_36 -> V_33 & V_37 )
V_36 -> V_33 ^= V_37 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
if ( V_2 -> V_9 == true ||
V_2 -> V_10 == true )
return;
if ( V_6 -> V_13 != V_6 -> V_4 )
F_4 ( & V_6 -> V_38 ) ;
}
static void F_12 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_13 ( V_40 ,
struct V_5 , V_23 ) ;
struct V_1 * V_2 = F_13 ( V_6 ,
struct V_1 , V_7 ) ;
if ( ! V_6 -> V_22 ) {
F_7 ( & V_6 -> V_32 ) ;
if ( V_6 -> V_21 == V_20 )
F_1 ( V_2 , V_16 ) ;
F_8 ( & V_6 -> V_32 ) ;
}
}
static void F_14 ( struct V_39 * V_40 )
{
struct V_5 * V_6 = F_13 ( V_40 ,
struct V_5 , V_38 ) ;
struct V_1 * V_2 = F_13 ( V_6 ,
struct V_1 , V_7 ) ;
T_1 V_13 = V_6 -> V_13 ;
if ( V_6 -> V_13 != V_6 -> V_4 ) {
F_7 ( & V_6 -> V_32 ) ;
V_13 = F_15 ( V_2 , V_41 ) ;
V_6 -> V_8 = 1 ;
F_1 ( V_2 , V_6 -> V_4 ) ;
F_8 ( & V_6 -> V_32 ) ;
}
}
static void F_16 ( void * V_42 )
{
struct V_1 * V_43 = (struct V_1 * ) V_42 ;
F_11 ( V_43 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_7 = & V_2 -> V_7 ;
memset ( ( unsigned char * ) V_7 , 0 , sizeof( struct V_5 ) ) ;
F_18 ( & V_7 -> V_32 , 1 ) ;
V_7 -> V_13 = V_16 ;
V_7 -> V_21 = V_20 ;
V_7 -> V_18 = 0 ;
V_7 -> V_11 = 0x80 ;
F_2 ( V_2 , 0x1025FE58 , 0 ) ;
F_19 ( & V_7 -> V_23 , F_12 ) ;
F_19 ( & V_7 -> V_38 , F_14 ) ;
F_20 ( & ( V_7 -> V_31 ) ,
V_2 -> V_44 , F_16 , ( T_1 * ) V_2 ) ;
}
T_3 F_21 ( struct V_1 * V_2 )
{
T_2 V_45 = V_46 ;
struct V_5 * V_36 = & V_2 -> V_7 ;
F_7 ( & V_36 -> V_32 ) ;
F_9 ( V_36 , V_34 ) ;
if ( V_36 -> V_13 < V_14 ) {
F_1 ( V_2 , V_15 ) ;
V_45 = V_47 ;
}
F_8 ( & V_36 -> V_32 ) ;
return V_45 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_36 = & V_2 -> V_7 ;
F_7 ( & V_36 -> V_32 ) ;
F_10 ( V_36 , V_34 ) ;
if ( ( V_36 -> V_13 > V_14 ) &&
( V_36 -> V_21 > V_20 ) ) {
if ( ( V_36 -> V_33 == 0 ) &&
( F_23 ( & V_2 -> V_48 ,
V_49 ) != true ) ) {
F_1 ( V_2 , V_50 ) ;
}
}
F_8 ( & V_36 -> V_32 ) ;
}

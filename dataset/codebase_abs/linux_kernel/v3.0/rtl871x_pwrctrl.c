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
F_4 ( & ( V_6 -> V_23 ) ) ;
}
}
void F_5 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_5 * V_6 = & ( V_2 -> V_7 ) ;
struct V_26 * V_27 = & ( V_2 -> V_28 ) ;
struct V_29 * V_30 = & ( V_2 -> V_31 ) ;
if ( V_6 -> V_32 == ( ( V_25 -> V_33 ) & 0x80 ) )
return;
F_6 ( & V_2 -> V_7 . V_34 ) ;
F_7 ( & V_6 -> V_35 ) ;
V_6 -> V_13 = ( V_25 -> V_33 ) & 0xf ;
if ( V_6 -> V_13 >= V_14 ) {
if ( V_6 -> V_36 & V_37 )
F_8 ( & ( V_27 -> V_38 ) ) ;
if ( V_6 -> V_36 & V_39 )
F_8 ( & ( V_30 -> V_40 ) ) ;
}
V_6 -> V_32 = ( V_25 -> V_33 ) & 0x80 ;
F_8 ( & V_6 -> V_35 ) ;
}
static inline void F_9 ( struct V_5 * V_41 , T_2 V_42 )
{
V_41 -> V_36 |= V_42 ;
}
static inline void F_10 ( struct V_5 * V_41 , T_2 V_42 )
{
if ( V_41 -> V_36 & V_42 )
V_41 -> V_36 ^= V_42 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
if ( V_2 -> V_9 == true ||
V_2 -> V_10 == true )
return;
if ( V_6 -> V_13 != V_6 -> V_4 )
F_4 ( & ( V_6 -> V_43 ) ) ;
}
static void F_12 ( struct V_44 * V_45 )
{
struct V_5 * V_6 = F_13 ( V_45 ,
struct V_5 , V_23 ) ;
struct V_1 * V_2 = F_13 ( V_6 ,
struct V_1 , V_7 ) ;
F_7 ( & V_6 -> V_35 ) ;
if ( ! V_6 -> V_22 ) {
if ( V_6 -> V_21 == V_20 )
F_1 ( V_2 , V_16 ) ;
}
F_8 ( & V_6 -> V_35 ) ;
}
static void F_14 ( struct V_44 * V_45 )
{
struct V_5 * V_6 = F_13 ( V_45 ,
struct V_5 , V_43 ) ;
struct V_1 * V_2 = F_13 ( V_6 ,
struct V_1 , V_7 ) ;
T_1 V_13 = V_6 -> V_13 ;
F_7 ( & V_6 -> V_35 ) ;
if ( V_6 -> V_13 != V_6 -> V_4 ) {
V_13 = F_15 ( V_2 , V_46 ) ;
V_6 -> V_8 = 1 ;
F_1 ( V_2 , V_6 -> V_4 ) ;
}
F_8 ( & V_6 -> V_35 ) ;
}
static void F_16 ( void * V_47 )
{
struct V_1 * V_48 = (struct V_1 * ) V_47 ;
F_11 ( V_48 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_7 = & V_2 -> V_7 ;
memset ( ( unsigned char * ) V_7 , 0 , sizeof( struct V_5 ) ) ;
F_18 ( & V_7 -> V_35 , 1 ) ;
V_7 -> V_13 = V_16 ;
V_7 -> V_21 = V_20 ;
V_7 -> V_18 = 0 ;
V_7 -> V_11 = 0x80 ;
F_2 ( V_2 , 0x1025FE58 , 0 ) ;
F_19 ( & ( V_7 -> V_23 ) ,
F_12 , V_2 ) ;
F_19 ( & ( V_7 -> V_43 ) ,
F_14 , V_2 ) ;
F_20 ( & ( V_7 -> V_34 ) ,
V_2 -> V_49 , F_16 , ( T_1 * ) V_2 ) ;
}
T_3 F_21 ( struct V_1 * V_2 )
{
T_2 V_50 = V_51 ;
struct V_5 * V_41 = & V_2 -> V_7 ;
F_7 ( & V_41 -> V_35 ) ;
F_9 ( V_41 , V_37 ) ;
if ( V_41 -> V_13 < V_14 ) {
F_1 ( V_2 , V_15 ) ;
V_50 = V_52 ;
}
F_8 ( & V_41 -> V_35 ) ;
return V_50 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_41 = & V_2 -> V_7 ;
F_7 ( & V_41 -> V_35 ) ;
F_10 ( V_41 , V_37 ) ;
if ( ( V_41 -> V_13 > V_14 ) &&
( V_41 -> V_21 > V_20 ) ) {
if ( ( V_41 -> V_36 == 0 ) &&
( F_23 ( & V_2 -> V_53 ,
V_54 ) != true ) ) {
F_1 ( V_2 , V_55 ) ;
}
}
F_8 ( & V_41 -> V_35 ) ;
}

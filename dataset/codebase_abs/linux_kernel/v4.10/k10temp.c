static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , T_1 * V_5 )
{
F_2 ( & V_6 ) ;
F_3 ( V_2 -> V_7 , V_3 ,
0xb8 , V_4 ) ;
F_4 ( V_2 -> V_7 , V_3 ,
0xbc , V_5 ) ;
F_5 ( & V_6 ) ;
}
static T_2 F_6 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
T_1 V_13 ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
if ( V_14 . V_15 == 0x15 && V_14 . V_16 == 0x60 ) {
F_1 ( V_2 , F_8 ( 0 , 0 ) ,
V_17 ,
& V_13 ) ;
} else {
F_9 ( V_2 , V_18 , & V_13 ) ;
}
return sprintf ( V_12 , L_1 , ( V_13 >> 21 ) * 125 ) ;
}
static T_2 F_10 ( struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 )
{
return sprintf ( V_12 , L_2 , 70 * 1000 ) ;
}
static T_2 F_11 ( struct V_8 * V_9 ,
struct V_10 * V_19 , char * V_12 )
{
struct V_20 * V_11 = F_12 ( V_19 ) ;
int V_21 = V_11 -> V_22 ;
T_1 V_13 ;
int V_23 ;
F_9 ( F_7 ( V_9 ) ,
V_24 , & V_13 ) ;
V_23 = ( ( V_13 >> 16 ) & 0x7f ) * 500 + 52000 ;
if ( V_21 )
V_23 -= ( ( V_13 >> 24 ) & 0xf ) * 500 ;
return sprintf ( V_12 , L_2 , V_23 ) ;
}
static T_3 F_13 ( struct V_25 * V_26 ,
struct V_27 * V_11 , int V_22 )
{
struct V_8 * V_9 = F_14 ( V_26 , struct V_8 , V_26 ) ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
if ( V_22 >= 2 ) {
T_1 V_28 , V_29 ;
F_9 ( V_2 , V_30 ,
& V_28 ) ;
F_9 ( V_2 , V_24 ,
& V_29 ) ;
if ( ! ( V_28 & V_31 ) || ! ( V_29 & V_32 ) )
return 0 ;
}
return V_11 -> V_33 ;
}
static bool F_15 ( struct V_1 * V_2 )
{
T_1 V_34 , V_35 ;
if ( V_14 . V_15 != 0x10 )
return false ;
V_34 = F_16 ( 0x80000001 ) & V_36 ;
if ( V_34 == V_37 )
return true ;
if ( V_34 != V_38 )
return false ;
F_4 ( V_2 -> V_7 ,
F_8 ( F_17 ( V_2 -> V_3 ) , 2 ) ,
V_39 , & V_35 ) ;
if ( V_35 & V_40 )
return false ;
return V_14 . V_16 < 4 ||
( V_14 . V_16 == 4 && V_14 . V_41 <= 2 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
const struct V_42 * V_43 )
{
int V_44 = F_15 ( V_2 ) ;
struct V_8 * V_9 = & V_2 -> V_9 ;
struct V_8 * V_45 ;
if ( V_44 ) {
if ( ! V_46 ) {
F_19 ( V_9 ,
L_3 ) ;
return - V_47 ;
}
F_20 ( V_9 ,
L_4 ) ;
}
V_45 = F_21 ( V_9 , L_5 , V_2 ,
V_48 ) ;
return F_22 ( V_45 ) ;
}

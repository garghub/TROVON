static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 ) {
F_3 ( V_3 , V_5 -> V_6 + V_7 ) ;
F_3 ( V_8 ,
V_5 -> V_6 + V_9 + V_10 ) ;
F_3 ( V_11 ,
V_5 -> V_6 + V_12 + V_10 ) ;
} else {
F_3 ( V_8 ,
V_5 -> V_6 + V_9 + V_13 ) ;
F_3 ( V_11 ,
V_5 -> V_6 + V_12 + V_13 ) ;
}
}
static void F_4 ( struct V_14 * V_15 )
{
struct V_14 * V_16 =
F_5 ( L_1 , V_15 -> V_17 ) ;
if ( V_16 ) {
V_16 -> V_2 . V_18 = & V_15 -> V_2 ;
V_16 -> V_2 . V_19 = & V_20 ;
F_6 ( V_16 ) ;
}
}
static void F_4 ( struct V_14 * V_15 )
{
}
static int F_7 ( struct V_4 * V_5 )
{
int V_3 = 5000 ;
do {
if ( ! ( F_8 ( V_5 -> V_6 + V_21 ) &
( 0x80 << V_22 ) ) )
return 0 ;
F_9 ( 1 ) ;
} while ( -- V_3 > 0 );
return ( F_8 ( V_5 -> V_6 + V_21 ) &
( 0x80 << V_22 ) ) ? - V_23 : 0 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_26 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_26 = F_7 ( V_5 ) ;
if ( V_26 )
return V_26 ;
F_11 ( F_8 ( V_5 -> V_6 + V_27 ) , V_25 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_28 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_28 , V_5 -> V_6 + V_27 ) ;
return F_7 ( V_5 ) ;
}
static T_2 F_13 ( int V_29 , void * V_30 )
{
struct V_4 * V_5 = F_2 ( V_30 ) ;
T_1 V_31 = F_8 ( V_5 -> V_6 + V_9 ) ;
if ( V_31 & V_32 ) {
F_3 ( V_32 ,
V_5 -> V_6 + V_9 + V_13 ) ;
F_14 ( V_5 -> V_33 , 1 , V_34 | V_35 ) ;
return V_36 ;
}
return V_37 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_38 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_38 ) {
F_3 ( V_39 |
V_40 ,
V_5 -> V_6 + V_41 +
V_10 ) ;
F_3 ( V_42 ,
V_5 -> V_6 + V_9 + V_10 ) ;
} else {
F_3 ( V_39 |
V_40 ,
V_5 -> V_6 + V_41 +
V_13 ) ;
F_3 ( V_42 ,
V_5 -> V_6 + V_9 + V_13 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( F_8 ( V_5 -> V_6 + V_45 ) , & V_44 -> time ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
unsigned long V_28 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_18 ( & V_44 -> time , & V_28 ) ;
F_3 ( V_28 , V_5 -> V_6 + V_45 ) ;
F_15 ( V_2 , V_44 -> V_38 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_46 )
{
struct V_4 * V_5 = F_20 ( V_46 ) ;
if ( ! V_5 )
return 0 ;
F_3 ( V_42 ,
V_5 -> V_6 + V_9 + V_13 ) ;
return 0 ;
}
static int F_21 ( struct V_14 * V_46 )
{
struct V_4 * V_5 ;
struct V_47 * V_48 ;
T_1 V_49 ;
T_1 V_50 , V_51 ;
T_1 V_52 = 0 ;
int V_53 ;
V_5 = F_22 ( & V_46 -> V_2 , sizeof( * V_5 ) , V_54 ) ;
if ( ! V_5 )
return - V_55 ;
V_48 = F_23 ( V_46 , V_56 , 0 ) ;
if ( ! V_48 ) {
F_24 ( & V_46 -> V_2 , L_2 ) ;
return - V_57 ;
}
V_5 -> V_6 = F_25 ( & V_46 -> V_2 , V_48 -> V_58 , F_26 ( V_48 ) ) ;
if ( ! V_5 -> V_6 ) {
F_24 ( & V_46 -> V_2 , L_3 ) ;
return - V_59 ;
}
V_5 -> V_60 = F_27 ( V_46 , 0 ) ;
V_49 = F_8 ( V_5 -> V_6 + V_21 ) ;
if ( ! ( V_49 & V_61 ) ) {
F_24 ( & V_46 -> V_2 , L_4 ) ;
return - V_62 ;
}
F_28 ( V_46 , V_5 ) ;
V_53 = F_29 ( V_5 -> V_6 ) ;
if ( V_53 ) {
F_24 ( & V_46 -> V_2 , L_5 , V_53 ) ;
return V_53 ;
}
if ( V_49 & V_63 )
V_52 = 32000 ;
else if ( V_49 & V_64 )
V_52 = 32768 ;
F_30 ( V_46 -> V_2 . V_65 , L_6 ,
& V_52 ) ;
switch ( V_52 ) {
case 32000 :
V_50 = V_66 |
V_67 |
V_68 ;
V_51 = V_69 ;
break;
case 32768 :
V_50 = V_67 |
V_68 ;
V_51 = V_69 |
V_66 ;
break;
default:
F_31 ( & V_46 -> V_2 ,
L_7 ) ;
case 0 :
V_50 = V_69 ;
V_51 = V_67 |
V_68 ;
}
F_3 ( V_50 , V_5 -> V_6 + V_41 +
V_10 ) ;
F_3 ( V_39 |
V_40 |
V_70 | V_51 ,
V_5 -> V_6 + V_41 + V_13 ) ;
F_3 ( V_71 |
V_42 ,
V_5 -> V_6 + V_9 + V_13 ) ;
V_5 -> V_33 = F_32 ( & V_46 -> V_2 , V_46 -> V_72 ,
& V_73 , V_74 ) ;
if ( F_33 ( V_5 -> V_33 ) )
return F_34 ( V_5 -> V_33 ) ;
V_53 = F_35 ( & V_46 -> V_2 , V_5 -> V_60 ,
F_13 , 0 , L_8 , & V_46 -> V_2 ) ;
if ( V_53 ) {
F_24 ( & V_46 -> V_2 , L_9 ,
V_5 -> V_60 ) ;
return V_53 ;
}
F_4 ( V_46 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_29 ( V_5 -> V_6 ) ;
F_3 ( V_39 |
V_40 |
V_70 ,
V_5 -> V_6 + V_41 + V_13 ) ;
return 0 ;
}

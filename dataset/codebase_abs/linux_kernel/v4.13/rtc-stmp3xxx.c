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
int V_16 = - 1 ;
struct V_14 * V_17 =
F_5 ( L_1 , V_15 -> V_18 ) ;
if ( V_17 ) {
V_17 -> V_2 . V_19 = & V_15 -> V_2 ;
V_17 -> V_2 . V_20 = & V_21 ;
V_16 = F_6 ( V_17 ) ;
}
if ( V_16 )
F_7 ( & V_15 -> V_2 ,
L_2 ) ;
}
static void F_4 ( struct V_14 * V_15 )
{
}
static int F_8 ( struct V_4 * V_5 )
{
int V_3 = 5000 ;
do {
if ( ! ( F_9 ( V_5 -> V_6 + V_22 ) &
( 0x80 << V_23 ) ) )
return 0 ;
F_10 ( 1 ) ;
} while ( -- V_3 > 0 );
return ( F_9 ( V_5 -> V_6 + V_22 ) &
( 0x80 << V_23 ) ) ? - V_24 : 0 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_27 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_27 = F_8 ( V_5 ) ;
if ( V_27 )
return V_27 ;
F_12 ( F_9 ( V_5 -> V_6 + V_28 ) , V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_29 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_29 , V_5 -> V_6 + V_28 ) ;
return F_8 ( V_5 ) ;
}
static T_2 F_14 ( int V_30 , void * V_31 )
{
struct V_4 * V_5 = F_2 ( V_31 ) ;
T_1 V_32 = F_9 ( V_5 -> V_6 + V_9 ) ;
if ( V_32 & V_33 ) {
F_3 ( V_33 ,
V_5 -> V_6 + V_9 + V_13 ) ;
F_15 ( V_5 -> V_34 , 1 , V_35 | V_36 ) ;
return V_37 ;
}
return V_38 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_39 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_39 ) {
F_3 ( V_40 |
V_41 ,
V_5 -> V_6 + V_42 +
V_10 ) ;
F_3 ( V_43 ,
V_5 -> V_6 + V_9 + V_10 ) ;
} else {
F_3 ( V_40 |
V_41 ,
V_5 -> V_6 + V_42 +
V_13 ) ;
F_3 ( V_43 ,
V_5 -> V_6 + V_9 + V_13 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_12 ( F_9 ( V_5 -> V_6 + V_46 ) , & V_45 -> time ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
unsigned long V_29 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_19 ( & V_45 -> time , & V_29 ) ;
F_3 ( V_29 , V_5 -> V_6 + V_46 ) ;
F_16 ( V_2 , V_45 -> V_39 ) ;
return 0 ;
}
static int F_20 ( struct V_14 * V_47 )
{
struct V_4 * V_5 = F_21 ( V_47 ) ;
if ( ! V_5 )
return 0 ;
F_3 ( V_43 ,
V_5 -> V_6 + V_9 + V_13 ) ;
return 0 ;
}
static int F_22 ( struct V_14 * V_47 )
{
struct V_4 * V_5 ;
struct V_48 * V_49 ;
T_1 V_50 ;
T_1 V_51 , V_52 ;
T_1 V_53 = 0 ;
int V_54 ;
V_5 = F_23 ( & V_47 -> V_2 , sizeof( * V_5 ) , V_55 ) ;
if ( ! V_5 )
return - V_56 ;
V_49 = F_24 ( V_47 , V_57 , 0 ) ;
if ( ! V_49 ) {
F_7 ( & V_47 -> V_2 , L_3 ) ;
return - V_58 ;
}
V_5 -> V_6 = F_25 ( & V_47 -> V_2 , V_49 -> V_59 , F_26 ( V_49 ) ) ;
if ( ! V_5 -> V_6 ) {
F_7 ( & V_47 -> V_2 , L_4 ) ;
return - V_60 ;
}
V_5 -> V_61 = F_27 ( V_47 , 0 ) ;
V_50 = F_9 ( V_5 -> V_6 + V_22 ) ;
if ( ! ( V_50 & V_62 ) ) {
F_7 ( & V_47 -> V_2 , L_5 ) ;
return - V_63 ;
}
F_28 ( V_47 , V_5 ) ;
V_54 = F_29 ( V_5 -> V_6 ) ;
if ( V_54 ) {
F_7 ( & V_47 -> V_2 , L_6 , V_54 ) ;
return V_54 ;
}
if ( V_50 & V_64 )
V_53 = 32000 ;
else if ( V_50 & V_65 )
V_53 = 32768 ;
F_30 ( V_47 -> V_2 . V_66 , L_7 ,
& V_53 ) ;
switch ( V_53 ) {
case 32000 :
V_51 = V_67 |
V_68 |
V_69 ;
V_52 = V_70 ;
break;
case 32768 :
V_51 = V_68 |
V_69 ;
V_52 = V_70 |
V_67 ;
break;
default:
F_31 ( & V_47 -> V_2 ,
L_8 ) ;
case 0 :
V_51 = V_70 ;
V_52 = V_68 |
V_69 ;
}
F_3 ( V_51 , V_5 -> V_6 + V_42 +
V_10 ) ;
F_3 ( V_40 |
V_41 |
V_71 | V_52 ,
V_5 -> V_6 + V_42 + V_13 ) ;
F_3 ( V_72 |
V_43 ,
V_5 -> V_6 + V_9 + V_13 ) ;
V_5 -> V_34 = F_32 ( & V_47 -> V_2 , V_47 -> V_73 ,
& V_74 , V_75 ) ;
if ( F_33 ( V_5 -> V_34 ) )
return F_34 ( V_5 -> V_34 ) ;
V_54 = F_35 ( & V_47 -> V_2 , V_5 -> V_61 ,
F_14 , 0 , L_9 , & V_47 -> V_2 ) ;
if ( V_54 ) {
F_7 ( & V_47 -> V_2 , L_10 ,
V_5 -> V_61 ) ;
return V_54 ;
}
F_4 ( V_47 ) ;
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
F_3 ( V_40 |
V_41 |
V_71 ,
V_5 -> V_6 + V_42 + V_13 ) ;
return 0 ;
}

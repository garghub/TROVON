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
V_5 -> V_6 + V_33 ) ;
F_14 ( V_5 -> V_34 , 1 , V_35 | V_36 ) ;
return V_37 ;
}
return V_38 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned int V_39 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_39 ) {
F_3 ( V_40 |
V_41 ,
V_5 -> V_6 + V_42 ) ;
F_3 ( V_43 ,
V_5 -> V_6 + V_44 ) ;
} else {
F_3 ( V_40 |
V_41 ,
V_5 -> V_6 + V_45 ) ;
F_3 ( V_43 ,
V_5 -> V_6 + V_33 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_11 ( F_8 ( V_5 -> V_6 + V_48 ) , & V_47 -> time ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
unsigned long V_28 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_18 ( & V_47 -> time , & V_28 ) ;
F_3 ( V_28 , V_5 -> V_6 + V_48 ) ;
F_15 ( V_2 , V_47 -> V_39 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_49 )
{
struct V_4 * V_5 = F_20 ( V_49 ) ;
if ( ! V_5 )
return 0 ;
F_3 ( V_43 ,
V_5 -> V_6 + V_33 ) ;
return 0 ;
}
static int F_21 ( struct V_14 * V_49 )
{
struct V_4 * V_5 ;
struct V_50 * V_51 ;
T_1 V_52 ;
T_1 V_53 , V_54 ;
T_1 V_55 = 0 ;
int V_56 ;
V_5 = F_22 ( & V_49 -> V_2 , sizeof( * V_5 ) , V_57 ) ;
if ( ! V_5 )
return - V_58 ;
V_51 = F_23 ( V_49 , V_59 , 0 ) ;
if ( ! V_51 ) {
F_24 ( & V_49 -> V_2 , L_2 ) ;
return - V_60 ;
}
V_5 -> V_6 = F_25 ( & V_49 -> V_2 , V_51 -> V_61 , F_26 ( V_51 ) ) ;
if ( ! V_5 -> V_6 ) {
F_24 ( & V_49 -> V_2 , L_3 ) ;
return - V_62 ;
}
V_5 -> V_63 = F_27 ( V_49 , 0 ) ;
V_52 = F_8 ( V_5 -> V_6 + V_21 ) ;
if ( ! ( V_52 & V_64 ) ) {
F_24 ( & V_49 -> V_2 , L_4 ) ;
return - V_65 ;
}
F_28 ( V_49 , V_5 ) ;
V_56 = F_29 ( V_5 -> V_6 ) ;
if ( V_56 ) {
F_24 ( & V_49 -> V_2 , L_5 , V_56 ) ;
return V_56 ;
}
if ( V_52 & V_66 )
V_55 = 32000 ;
else if ( V_52 & V_67 )
V_55 = 32768 ;
F_30 ( V_49 -> V_2 . V_68 , L_6 ,
& V_55 ) ;
switch ( V_55 ) {
case 32000 :
V_53 = V_69 |
V_70 |
V_71 ;
V_54 = V_72 ;
break;
case 32768 :
V_53 = V_70 |
V_71 ;
V_54 = V_72 |
V_69 ;
break;
default:
F_31 ( & V_49 -> V_2 ,
L_7 ) ;
case 0 :
V_53 = V_72 ;
V_54 = V_70 |
V_71 ;
}
F_3 ( V_53 , V_5 -> V_6 + V_42 ) ;
F_3 ( V_40 |
V_41 |
V_73 | V_54 ,
V_5 -> V_6 + V_45 ) ;
F_3 ( V_74 |
V_43 ,
V_5 -> V_6 + V_33 ) ;
V_5 -> V_34 = F_32 ( & V_49 -> V_2 , V_49 -> V_75 ,
& V_76 , V_77 ) ;
if ( F_33 ( V_5 -> V_34 ) )
return F_34 ( V_5 -> V_34 ) ;
V_56 = F_35 ( & V_49 -> V_2 , V_5 -> V_63 ,
F_13 , 0 , L_8 , & V_49 -> V_2 ) ;
if ( V_56 ) {
F_24 ( & V_49 -> V_2 , L_9 ,
V_5 -> V_63 ) ;
return V_56 ;
}
F_4 ( V_49 ) ;
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
V_73 ,
V_5 -> V_6 + V_45 ) ;
return 0 ;
}

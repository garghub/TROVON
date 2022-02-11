static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = F_3 ( V_4 -> V_6 ) ;
F_4 () ;
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_7 , V_4 -> V_8 ) ;
F_4 () ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 = ( T_1 ) F_8 ( F_9 ( V_4 -> V_6 ) ) ;
F_4 () ;
return V_5 ;
}
static void F_10 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_11 ( F_12 ( ( V_9 ) V_7 ) , V_4 -> V_8 ) ;
F_4 () ;
}
static V_9 F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_9 V_5 = F_9 ( V_4 -> V_6 ) ;
F_4 () ;
return V_5 ;
}
static void F_14 ( struct V_1 * V_2 , const T_1 * V_10 , int V_11 )
{
int V_12 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
F_6 ( V_10 [ V_12 ] , V_4 -> V_8 ) ;
F_4 () ;
}
}
static void F_15 ( struct V_1 * V_2 , T_1 * V_10 , int V_11 )
{
int V_12 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
V_10 [ V_12 ] = F_3 ( V_4 -> V_6 ) ;
F_4 () ;
}
}
static void F_16 ( struct V_1 * V_2 , const T_1 * V_10 , int V_11 )
{
int V_12 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_9 * V_13 = ( V_9 * ) V_10 ;
V_11 >>= 1 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
F_11 ( V_13 [ V_12 ] , V_4 -> V_8 ) ;
F_4 () ;
}
}
static void F_17 ( struct V_1 * V_2 , T_1 * V_10 , int V_11 )
{
int V_12 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_9 * V_13 = ( V_9 * ) V_10 ;
V_11 >>= 1 ;
for ( V_12 = 0 ; V_12 < V_11 ; V_12 ++ ) {
V_13 [ V_12 ] = F_9 ( V_4 -> V_6 ) ;
F_4 () ;
}
}
static void F_18 ( struct V_1 * V_2 , int V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_19 ( V_4 , struct V_15 ,
V_17 ) ;
switch ( V_14 ) {
case V_18 :
V_4 -> V_8 = V_16 -> V_19 + V_20 ;
break;
case V_21 :
V_4 -> V_8 = V_16 -> V_19 + V_22 ;
break;
case V_23 :
V_4 -> V_8 = V_16 -> V_19 + V_24 ;
break;
case V_25 :
V_4 -> V_8 = V_16 -> V_19 + V_22 ;
F_20 ( 1 ) ;
break;
case V_26 :
F_21 ( ( 1 << ( 4 + V_16 -> V_27 ) ) , V_28 ) ;
break;
case V_29 :
F_21 ( 0 , V_28 ) ;
break;
}
V_4 -> V_6 = V_4 -> V_8 ;
F_4 () ;
}
int F_22 ( struct V_1 * V_2 )
{
return ( F_23 ( V_30 ) & 0x1 ) ? 1 : 0 ;
}
static void F_24 ( struct V_1 * V_2 , int V_17 )
{
}
static void F_25 ( struct V_1 * V_2 , unsigned V_31 , int V_32 , int V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_19 ( V_4 , struct V_15 ,
V_17 ) ;
int V_34 = 0 , V_12 ;
unsigned long V_35 = 0 ;
F_18 ( V_2 , V_18 ) ;
if ( V_31 == V_36 ) {
int V_37 ;
if ( V_32 >= V_2 -> V_38 ) {
V_32 -= V_2 -> V_38 ;
V_37 = V_39 ;
} else if ( V_32 < 256 ) {
V_37 = V_40 ;
} else {
V_32 -= 256 ;
V_37 = V_41 ;
}
V_16 -> V_42 ( V_2 , V_37 ) ;
}
V_16 -> V_42 ( V_2 , V_31 ) ;
F_18 ( V_2 , V_21 ) ;
if ( V_32 != - 1 || V_33 != - 1 ) {
F_18 ( V_2 , V_23 ) ;
if ( V_32 != - 1 ) {
if ( V_4 -> V_43 & V_44 &&
! F_26 ( V_31 ) )
V_32 >>= 1 ;
V_16 -> V_42 ( V_2 , V_32 ) ;
}
if ( V_33 != - 1 ) {
V_16 -> V_42 ( V_2 , ( V_45 ) ( V_33 & 0xff ) ) ;
if ( V_31 == V_40 ||
V_31 == V_41 ||
V_31 == V_39 ) {
V_34 = 1 ;
F_27 ( V_35 ) ;
F_18 ( V_2 , V_26 ) ;
}
V_16 -> V_42 ( V_2 , ( V_45 ) ( V_33 >> 8 ) ) ;
if ( V_4 -> V_46 > ( 32 << 20 ) )
V_16 -> V_42 ( V_2 ,
( ( V_33 >> 16 ) & 0x0f ) ) ;
}
F_18 ( V_2 , V_25 ) ;
}
switch ( V_31 ) {
case V_47 :
case V_48 :
case V_49 :
case V_36 :
case V_50 :
return;
case V_51 :
break;
case V_40 :
case V_41 :
case V_39 :
if ( F_28 ( ! V_34 ) )
break;
F_29 ( 100 ) ;
for ( V_12 = V_4 -> V_52 ; ! V_4 -> V_53 ( V_2 ) && V_12 > 0 ; -- V_12 )
F_20 ( 1 ) ;
F_18 ( V_2 , V_29 ) ;
F_30 ( V_35 ) ;
return;
}
F_29 ( 100 ) ;
while( ! V_4 -> V_53 ( V_2 ) ) ;
}
static int F_31 ( unsigned long V_54 )
{
void T_2 * V_19 =
( void T_2 * ) F_32 ( V_55 ) ;
unsigned long V_56 , V_57 , V_58 , V_59 , V_60 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < 4 ; V_12 ++ ) {
V_56 = 0x1000 + ( V_12 * 0x10 ) ;
V_57 = F_33 ( V_19 + V_56 + 0x08 ) ;
V_58 = ( V_57 << 4 ) & 0xfffc0000 ;
V_59 = ( V_57 << 18 ) & 0xfffc0000 ;
V_60 = ( V_58 | ( V_58 - 1 ) ) & ~ ( V_58 ^ V_59 ) ;
if ( ( V_54 >= V_58 ) && ( V_54 < V_60 ) )
return V_12 ;
}
return - V_61 ;
}
static int F_34 ( struct V_62 * V_63 )
{
struct V_64 * V_65 ;
struct V_15 * V_16 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_66 * V_67 ;
int V_5 , V_27 ;
V_65 = F_35 ( & V_63 -> V_68 ) ;
if ( ! V_65 ) {
F_36 ( & V_63 -> V_68 , L_1 ) ;
return - V_61 ;
}
V_16 = F_37 ( sizeof( * V_16 ) , V_69 ) ;
if ( ! V_16 )
return - V_70 ;
V_67 = F_38 ( V_63 , V_71 , 0 ) ;
if ( ! V_67 ) {
F_36 ( & V_63 -> V_68 , L_2 ) ;
V_5 = - V_61 ;
goto V_72;
}
if ( F_39 ( V_67 -> V_58 , F_40 ( V_67 ) , L_3 ) ) {
F_36 ( & V_63 -> V_68 , L_4 ) ;
V_5 = - V_70 ;
goto V_72;
}
V_16 -> V_19 = F_41 ( V_67 -> V_58 , 0x1000 ) ;
if ( ! V_16 -> V_19 ) {
F_36 ( & V_63 -> V_68 , L_5 ) ;
V_5 = - V_61 ;
goto V_73;
}
V_4 = & V_16 -> V_17 ;
V_2 = F_42 ( V_4 ) ;
V_2 -> V_68 . V_74 = & V_63 -> V_68 ;
V_27 = F_31 ( V_67 -> V_58 ) ;
if ( V_27 < 0 ) {
F_36 ( & V_63 -> V_68 , L_6 ) ;
V_5 = - V_61 ;
goto V_75;
}
V_16 -> V_27 = V_27 ;
V_4 -> V_53 = F_22 ;
V_4 -> V_76 = F_24 ;
V_4 -> V_77 = F_25 ;
V_4 -> V_52 = 30 ;
V_4 -> V_78 . V_79 = V_80 ;
if ( V_65 -> V_81 )
V_4 -> V_43 |= V_44 ;
V_4 -> V_82 = ( V_65 -> V_81 ) ? F_7 : F_1 ;
V_16 -> V_42 = ( V_65 -> V_81 ) ? F_10 : F_5 ;
V_4 -> V_83 = F_13 ;
V_4 -> V_84 = ( V_65 -> V_81 ) ? F_16 : F_14 ;
V_4 -> V_85 = ( V_65 -> V_81 ) ? F_17 : F_15 ;
V_5 = F_43 ( V_2 , 1 ) ;
if ( V_5 ) {
F_36 ( & V_63 -> V_68 , L_7 , V_5 ) ;
goto V_75;
}
F_44 ( V_2 , V_65 -> V_86 , V_65 -> V_87 ) ;
F_45 ( V_63 , V_16 ) ;
return 0 ;
V_75:
F_46 ( V_16 -> V_19 ) ;
V_73:
F_47 ( V_67 -> V_58 , F_40 ( V_67 ) ) ;
V_72:
F_48 ( V_16 ) ;
return V_5 ;
}
static int F_49 ( struct V_62 * V_63 )
{
struct V_15 * V_16 = F_50 ( V_63 ) ;
struct V_66 * V_67 = F_38 ( V_63 , V_71 , 0 ) ;
F_51 ( F_42 ( & V_16 -> V_17 ) ) ;
F_46 ( V_16 -> V_19 ) ;
F_47 ( V_67 -> V_58 , 0x1000 ) ;
F_48 ( V_16 ) ;
return 0 ;
}

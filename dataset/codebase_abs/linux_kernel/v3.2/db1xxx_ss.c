static int F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 ;
V_3 = F_2 ( V_4 ) ;
return V_3 & 1 << ( 8 + 2 * V_2 -> V_5 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return ! F_4 ( F_5 ( V_2 -> V_6 ) ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_7 ) {
case V_8 :
return F_1 ( V_2 ) ;
default:
return F_3 ( V_2 ) ;
}
}
static inline void F_7 ( struct V_1 * V_2 , int V_9 )
{
if ( V_2 -> V_10 != - 1 ) {
if ( V_9 )
F_8 ( V_2 -> V_10 ) ;
else
F_9 ( V_2 -> V_10 ) ;
}
}
static T_1 F_10 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
F_11 ( & V_2 -> V_13 , V_14 ) ;
return V_15 ;
}
static T_1 F_12 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
F_11 ( & V_2 -> V_13 , V_16 ) ;
return V_15 ;
}
static T_1 F_13 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
if ( V_11 == V_2 -> V_6 ) {
F_14 ( V_2 -> V_6 ) ;
F_8 ( V_2 -> V_17 ) ;
} else {
F_14 ( V_2 -> V_17 ) ;
F_8 ( V_2 -> V_6 ) ;
}
F_11 ( & V_2 -> V_13 , V_14 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_18 ;
if ( V_2 -> V_10 != - 1 ) {
V_18 = F_16 ( V_2 -> V_10 , F_12 ,
0 , L_1 , V_2 ) ;
if ( V_18 )
return V_18 ;
}
if ( V_2 -> V_7 == V_8 ) {
V_18 = F_16 ( V_2 -> V_6 , F_13 ,
V_19 , L_2 , V_2 ) ;
if ( V_18 )
goto V_20;
V_18 = F_16 ( V_2 -> V_17 , F_13 ,
V_19 , L_3 , V_2 ) ;
if ( V_18 ) {
F_17 ( V_2 -> V_6 , V_2 ) ;
goto V_20;
}
if ( F_1 ( V_2 ) )
F_8 ( V_2 -> V_17 ) ;
else
F_8 ( V_2 -> V_6 ) ;
} else {
F_18 ( V_2 -> V_6 , V_21 ) ;
V_18 = F_16 ( V_2 -> V_6 , F_10 ,
0 , L_4 , V_2 ) ;
if ( V_18 )
goto V_20;
}
return 0 ;
V_20:
if ( V_2 -> V_10 != - 1 )
F_17 ( V_2 -> V_10 , V_2 ) ;
return V_18 ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 != - 1 )
F_17 ( V_2 -> V_10 , V_2 ) ;
F_17 ( V_2 -> V_6 , V_2 ) ;
if ( V_2 -> V_17 != - 1 )
F_17 ( V_2 -> V_17 , V_2 ) ;
}
static int F_20 ( struct V_22 * V_23 ,
struct V_24 * V_25 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
unsigned short V_26 , V_27 ;
unsigned int V_28 ;
int V_29 , V_30 , V_18 ;
V_26 = ( 0xf << ( V_2 -> V_5 * 8 ) ) ;
V_27 = 0 ;
V_29 = V_30 = V_18 = 0 ;
switch ( V_25 -> V_31 ) {
case 50 :
++ V_29 ;
case 33 :
++ V_29 ;
case 0 :
break;
default:
F_22 ( V_32 L_5 ,
V_2 -> V_5 , V_25 -> V_31 ) ;
}
switch ( V_25 -> V_33 ) {
case 12 :
++ V_30 ;
case 33 :
case 50 :
++ V_30 ;
case 0 :
break;
default:
F_22 ( V_32 L_6 ,
V_2 -> V_5 , V_25 -> V_33 ) ;
}
if ( ( ( V_25 -> V_31 == 33 ) && ( V_25 -> V_33 == 50 ) ) ||
( ( V_25 -> V_31 == 50 ) && ( V_25 -> V_33 == 33 ) ) ) {
F_22 ( V_32 L_7 ,
V_2 -> V_5 , V_25 -> V_31 , V_25 -> V_33 ) ;
V_29 = V_30 = 0 ;
V_18 = - V_34 ;
}
V_27 |= ( ( V_29 << 2 ) | V_30 ) << ( V_2 -> V_5 * 8 ) ;
V_28 = V_25 -> V_35 ^ V_2 -> V_36 ;
if ( V_28 & V_37 ) {
if ( V_25 -> V_35 & V_37 ) {
F_7 ( V_2 , 0 ) ;
V_26 |= ( 1 << ( 7 + ( V_2 -> V_5 * 8 ) ) ) ;
V_26 |= ( 1 << ( 4 + ( V_2 -> V_5 * 8 ) ) ) ;
} else {
V_27 |= 1 << ( 7 + ( V_2 -> V_5 * 8 ) ) ;
V_27 |= 1 << ( 4 + ( V_2 -> V_5 * 8 ) ) ;
}
}
F_23 ( V_38 , V_26 , V_27 ) ;
V_2 -> V_36 = V_25 -> V_35 ;
if ( ( V_28 & V_37 ) && ! ( V_25 -> V_35 & V_37 ) ) {
F_24 ( 500 ) ;
F_7 ( V_2 , 1 ) ;
}
return V_18 ;
}
static int F_25 ( struct V_22 * V_23 ,
unsigned int * V_39 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
unsigned short V_40 , V_41 ;
unsigned int V_42 ;
V_42 = F_6 ( V_2 ) ? V_14 : 0 ;
V_40 = F_2 ( V_38 ) ;
V_41 = F_2 ( V_43 ) ;
if ( V_2 -> V_7 == V_44 )
V_41 >>= 4 ;
switch ( F_26 ( V_41 , V_2 -> V_5 ) ) {
case 0 :
case 2 :
V_42 |= V_45 ;
case 3 :
break;
default:
V_42 |= V_46 ;
}
V_42 |= F_27 ( V_40 , V_2 -> V_5 ) ? V_47 : 0 ;
V_42 |= ( F_28 ( V_40 , V_2 -> V_5 ) ) ? V_48 : V_37 ;
* V_39 = V_42 ;
return 0 ;
}
static int F_29 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_30 ( struct V_22 * V_23 )
{
return 0 ;
}
static int F_31 ( struct V_22 * V_23 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
V_50 -> V_51 = ( V_52 ) V_2 -> V_53 ;
V_50 -> V_54 = V_50 -> V_51 + V_55 ;
return 0 ;
}
static int F_32 ( struct V_22 * V_23 ,
struct V_56 * V_50 )
{
struct V_1 * V_2 = F_21 ( V_23 ) ;
if ( V_50 -> V_35 & V_57 )
V_50 -> V_58 = V_2 -> V_59 + V_50 -> V_60 ;
else
V_50 -> V_58 = V_2 -> V_61 + V_50 -> V_60 ;
return 0 ;
}
static int T_2 F_33 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
struct V_64 * V_65 ;
int V_18 , V_66 ;
V_2 = F_34 ( sizeof( struct V_1 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
V_2 -> V_5 = V_63 -> V_69 ;
V_66 = F_35 ( F_2 ( V_70 ) ) ;
switch ( V_66 ) {
case V_71 :
case V_72 :
case V_73 :
V_2 -> V_7 = V_44 ;
break;
case V_74 ... V_75 :
V_2 -> V_7 = V_76 ;
break;
case V_77 ... V_78 :
V_2 -> V_7 = V_8 ;
break;
default:
F_22 ( V_32 L_8 , V_66 ) ;
V_18 = - V_79 ;
goto V_80;
} ;
V_65 = F_36 ( V_63 , V_81 , L_9 ) ;
V_2 -> V_82 = V_65 ? V_65 -> V_51 : 0 ;
V_65 = F_36 ( V_63 , V_81 , L_10 ) ;
V_2 -> V_6 = V_65 ? V_65 -> V_51 : - 1 ;
V_65 = F_36 ( V_63 , V_81 , L_11 ) ;
V_2 -> V_10 = V_65 ? V_65 -> V_51 : - 1 ;
V_65 = F_36 ( V_63 , V_81 , L_12 ) ;
V_2 -> V_17 = V_65 ? V_65 -> V_51 : - 1 ;
V_18 = - V_79 ;
V_65 = F_36 ( V_63 , V_83 , L_13 ) ;
if ( ! V_65 ) {
F_22 ( V_84 L_14 ,
V_2 -> V_5 ) ;
goto V_80;
}
V_2 -> V_59 = V_65 -> V_51 ;
V_65 = F_36 ( V_63 , V_83 , L_15 ) ;
if ( ! V_65 ) {
F_22 ( V_84 L_16 ,
V_2 -> V_5 ) ;
goto V_80;
}
V_2 -> V_61 = V_65 -> V_51 ;
V_65 = F_36 ( V_63 , V_83 , L_17 ) ;
if ( ! V_65 ) {
F_22 ( V_84 L_18 ,
V_2 -> V_5 ) ;
goto V_80;
}
V_2 -> V_85 = V_65 -> V_51 ;
V_2 -> V_53 = ( void * ) ( F_37 ( V_2 -> V_85 , V_55 ) -
V_86 ) ;
if ( ! V_2 -> V_53 ) {
F_22 ( V_84 L_19 ,
V_2 -> V_5 ) ;
V_18 = - V_68 ;
goto V_80;
}
V_2 -> V_13 . V_87 = & V_88 ;
V_2 -> V_13 . V_89 = V_90 ;
V_2 -> V_13 . V_91 = V_2 -> V_82 ;
V_2 -> V_13 . V_92 = V_93 | V_94 ;
V_2 -> V_13 . V_95 = V_96 ;
V_2 -> V_13 . V_97 = ( unsigned long ) V_2 -> V_53 ;
V_2 -> V_13 . V_98 . V_99 = & V_63 -> V_98 ;
V_2 -> V_13 . V_100 = & V_101 ;
F_38 ( V_63 , V_2 ) ;
V_18 = F_15 ( V_2 ) ;
if ( V_18 ) {
F_22 ( V_84 L_20 ,
V_2 -> V_5 ) ;
goto V_20;
}
F_7 ( V_2 , 0 ) ;
V_18 = F_39 ( & V_2 -> V_13 ) ;
if ( V_18 ) {
F_22 ( V_84 L_21 , V_2 -> V_5 ) ;
goto V_102;
}
F_22 ( V_32 L_22
L_23
L_24 , V_2 -> V_5 , V_2 -> V_85 , V_2 -> V_53 ,
V_2 -> V_59 , V_2 -> V_61 , V_2 -> V_82 ,
V_2 -> V_6 , V_2 -> V_10 , V_2 -> V_17 ) ;
return 0 ;
V_102:
F_19 ( V_2 ) ;
V_20:
F_40 ( ( void * ) ( V_2 -> V_53 + ( V_52 ) V_86 ) ) ;
V_80:
F_41 ( V_2 ) ;
return V_18 ;
}
static int T_3 F_42 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_43 ( V_63 ) ;
F_19 ( V_2 ) ;
F_44 ( & V_2 -> V_13 ) ;
F_40 ( ( void * ) ( V_2 -> V_53 + ( V_52 ) V_86 ) ) ;
F_41 ( V_2 ) ;
return 0 ;
}
int T_4 F_45 ( void )
{
return F_46 ( & V_103 ) ;
}
void T_5 F_47 ( void )
{
F_48 ( & V_103 ) ;
}

static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) & ( 1 << 8 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
unsigned short V_4 ;
V_4 = F_2 ( V_3 ) ;
return V_4 & 1 << ( 8 + 2 * V_2 -> V_5 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return ! F_5 ( F_6 ( V_2 -> V_6 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_7 ) {
case V_8 :
return F_3 ( V_2 ) ;
case V_9 :
return F_1 ( V_2 ) ;
default:
return F_4 ( V_2 ) ;
}
}
static inline void F_8 ( struct V_1 * V_2 , int V_10 )
{
if ( V_2 -> V_11 != - 1 ) {
if ( V_10 )
F_9 ( V_2 -> V_11 ) ;
else
F_10 ( V_2 -> V_11 ) ;
}
}
static T_1 F_11 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_12 ( & V_2 -> V_14 , V_15 ) ;
return V_16 ;
}
static T_1 F_13 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_12 ( & V_2 -> V_14 , V_17 ) ;
return V_16 ;
}
static T_1 F_14 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
if ( V_12 == V_2 -> V_6 ) {
F_15 ( V_2 -> V_6 ) ;
F_9 ( V_2 -> V_18 ) ;
} else {
F_15 ( V_2 -> V_18 ) ;
F_9 ( V_2 -> V_6 ) ;
}
F_12 ( & V_2 -> V_14 , V_15 ) ;
return V_16 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_19 ;
if ( V_2 -> V_11 != - 1 ) {
V_19 = F_17 ( V_2 -> V_11 , F_13 ,
0 , L_1 , V_2 ) ;
if ( V_19 )
return V_19 ;
}
if ( ( V_2 -> V_7 == V_8 ) ||
( V_2 -> V_7 == V_9 ) ) {
V_19 = F_17 ( V_2 -> V_6 , F_14 ,
V_20 , L_2 , V_2 ) ;
if ( V_19 )
goto V_21;
V_19 = F_17 ( V_2 -> V_18 , F_14 ,
V_20 , L_3 , V_2 ) ;
if ( V_19 ) {
F_18 ( V_2 -> V_6 , V_2 ) ;
goto V_21;
}
if ( F_7 ( V_2 ) )
F_9 ( V_2 -> V_18 ) ;
else
F_9 ( V_2 -> V_6 ) ;
} else {
F_19 ( V_2 -> V_6 , V_22 ) ;
V_19 = F_17 ( V_2 -> V_6 , F_11 ,
0 , L_4 , V_2 ) ;
if ( V_19 )
goto V_21;
}
return 0 ;
V_21:
if ( V_2 -> V_11 != - 1 )
F_18 ( V_2 -> V_11 , V_2 ) ;
return V_19 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 != - 1 )
F_18 ( V_2 -> V_11 , V_2 ) ;
F_18 ( V_2 -> V_6 , V_2 ) ;
if ( V_2 -> V_18 != - 1 )
F_18 ( V_2 -> V_18 , V_2 ) ;
}
static int F_21 ( struct V_23 * V_24 ,
struct V_25 * V_26 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
unsigned short V_27 , V_28 ;
unsigned int V_29 ;
int V_30 , V_31 , V_19 ;
V_27 = ( 0xf << ( V_2 -> V_5 * 8 ) ) ;
V_28 = 0 ;
V_30 = V_31 = V_19 = 0 ;
switch ( V_26 -> V_32 ) {
case 50 :
++ V_30 ;
case 33 :
++ V_30 ;
case 0 :
break;
default:
F_23 ( V_33 L_5 ,
V_2 -> V_5 , V_26 -> V_32 ) ;
}
switch ( V_26 -> V_34 ) {
case 12 :
++ V_31 ;
case 33 :
case 50 :
++ V_31 ;
case 0 :
break;
default:
F_23 ( V_33 L_6 ,
V_2 -> V_5 , V_26 -> V_34 ) ;
}
if ( ( ( V_26 -> V_32 == 33 ) && ( V_26 -> V_34 == 50 ) ) ||
( ( V_26 -> V_32 == 50 ) && ( V_26 -> V_34 == 33 ) ) ) {
F_23 ( V_33 L_7 ,
V_2 -> V_5 , V_26 -> V_32 , V_26 -> V_34 ) ;
V_30 = V_31 = 0 ;
V_19 = - V_35 ;
}
if ( V_2 -> V_7 != V_9 )
V_28 |= ( ( V_30 << 2 ) | V_31 ) << ( V_2 -> V_5 * 8 ) ;
V_29 = V_26 -> V_36 ^ V_2 -> V_37 ;
if ( V_29 & V_38 ) {
if ( V_26 -> V_36 & V_38 ) {
F_8 ( V_2 , 0 ) ;
V_27 |= ( 1 << ( 7 + ( V_2 -> V_5 * 8 ) ) ) ;
V_27 |= ( 1 << ( 4 + ( V_2 -> V_5 * 8 ) ) ) ;
} else {
V_28 |= 1 << ( 7 + ( V_2 -> V_5 * 8 ) ) ;
V_28 |= 1 << ( 4 + ( V_2 -> V_5 * 8 ) ) ;
}
}
F_24 ( V_39 , V_27 , V_28 ) ;
V_2 -> V_37 = V_26 -> V_36 ;
if ( ( V_29 & V_38 ) && ! ( V_26 -> V_36 & V_38 ) ) {
F_25 ( 500 ) ;
F_8 ( V_2 , 1 ) ;
}
return V_19 ;
}
static int F_26 ( struct V_23 * V_24 ,
unsigned int * V_40 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
unsigned short V_41 , V_42 ;
unsigned int V_43 ;
V_43 = F_7 ( V_2 ) ? V_15 : 0 ;
V_41 = F_2 ( V_39 ) ;
V_42 = F_2 ( V_44 ) ;
if ( V_2 -> V_7 == V_45 )
V_42 >>= 4 ;
switch ( F_27 ( V_42 , V_2 -> V_5 ) ) {
case 0 :
case 2 :
V_43 |= V_46 ;
case 3 :
break;
default:
V_43 |= V_47 ;
}
V_43 |= F_28 ( V_41 , V_2 -> V_5 ) ? V_48 : 0 ;
if ( ( V_2 -> V_7 == V_9 ) && ( V_43 & V_15 ) )
V_43 = V_48 | V_46 | V_15 ;
V_43 |= ( F_29 ( V_41 , V_2 -> V_5 ) ) ? V_49 : V_38 ;
* V_40 = V_43 ;
return 0 ;
}
static int F_30 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_31 ( struct V_23 * V_24 )
{
return 0 ;
}
static int F_32 ( struct V_23 * V_24 ,
struct V_50 * V_51 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
V_51 -> V_52 = ( V_53 ) V_2 -> V_54 ;
V_51 -> V_55 = V_51 -> V_52 + V_56 ;
return 0 ;
}
static int F_33 ( struct V_23 * V_24 ,
struct V_57 * V_51 )
{
struct V_1 * V_2 = F_22 ( V_24 ) ;
if ( V_51 -> V_36 & V_58 )
V_51 -> V_59 = V_2 -> V_60 + V_51 -> V_61 ;
else
V_51 -> V_59 = V_2 -> V_62 + V_51 -> V_61 ;
return 0 ;
}
static int T_2 F_34 ( struct V_63 * V_64 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
int V_19 , V_67 ;
V_2 = F_35 ( sizeof( struct V_1 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_5 = V_64 -> V_70 ;
V_67 = F_36 ( F_2 ( V_71 ) ) ;
switch ( V_67 ) {
case V_72 :
case V_73 :
case V_74 :
V_2 -> V_7 = V_45 ;
break;
case V_75 ... V_76 :
V_2 -> V_7 = V_77 ;
break;
case V_78 ... V_79 :
V_2 -> V_7 = V_8 ;
break;
case V_80 :
V_2 -> V_7 = V_9 ;
break;
default:
F_23 ( V_33 L_8 , V_67 ) ;
V_19 = - V_81 ;
goto V_82;
} ;
V_66 = F_37 ( V_64 , V_83 , L_9 ) ;
V_2 -> V_84 = V_66 ? V_66 -> V_52 : 0 ;
V_66 = F_37 ( V_64 , V_83 , L_10 ) ;
V_2 -> V_6 = V_66 ? V_66 -> V_52 : - 1 ;
V_66 = F_37 ( V_64 , V_83 , L_11 ) ;
V_2 -> V_11 = V_66 ? V_66 -> V_52 : - 1 ;
V_66 = F_37 ( V_64 , V_83 , L_12 ) ;
V_2 -> V_18 = V_66 ? V_66 -> V_52 : - 1 ;
V_19 = - V_81 ;
V_66 = F_37 ( V_64 , V_85 , L_13 ) ;
if ( ! V_66 ) {
F_23 ( V_86 L_14 ,
V_2 -> V_5 ) ;
goto V_82;
}
V_2 -> V_60 = V_66 -> V_52 ;
V_66 = F_37 ( V_64 , V_85 , L_15 ) ;
if ( ! V_66 ) {
F_23 ( V_86 L_16 ,
V_2 -> V_5 ) ;
goto V_82;
}
V_2 -> V_62 = V_66 -> V_52 ;
V_66 = F_37 ( V_64 , V_85 , L_17 ) ;
if ( ! V_66 ) {
F_23 ( V_86 L_18 ,
V_2 -> V_5 ) ;
goto V_82;
}
V_2 -> V_87 = V_66 -> V_52 ;
V_2 -> V_54 = ( void * ) ( F_38 ( V_2 -> V_87 , V_56 ) -
V_88 ) ;
if ( ! V_2 -> V_54 ) {
F_23 ( V_86 L_19 ,
V_2 -> V_5 ) ;
V_19 = - V_69 ;
goto V_82;
}
V_2 -> V_14 . V_89 = & V_90 ;
V_2 -> V_14 . V_91 = V_92 ;
V_2 -> V_14 . V_93 = V_2 -> V_84 ;
V_2 -> V_14 . V_94 = V_95 | V_96 ;
V_2 -> V_14 . V_97 = V_98 ;
V_2 -> V_14 . V_99 = ( unsigned long ) V_2 -> V_54 ;
V_2 -> V_14 . V_100 . V_101 = & V_64 -> V_100 ;
V_2 -> V_14 . V_102 = & V_103 ;
F_39 ( V_64 , V_2 ) ;
V_19 = F_16 ( V_2 ) ;
if ( V_19 ) {
F_23 ( V_86 L_20 ,
V_2 -> V_5 ) ;
goto V_21;
}
F_8 ( V_2 , 0 ) ;
V_19 = F_40 ( & V_2 -> V_14 ) ;
if ( V_19 ) {
F_23 ( V_86 L_21 , V_2 -> V_5 ) ;
goto V_104;
}
F_23 ( V_33 L_22
L_23
L_24 , V_2 -> V_5 , V_2 -> V_87 , V_2 -> V_54 ,
V_2 -> V_60 , V_2 -> V_62 , V_2 -> V_84 ,
V_2 -> V_6 , V_2 -> V_11 , V_2 -> V_18 ) ;
return 0 ;
V_104:
F_20 ( V_2 ) ;
V_21:
F_41 ( ( void * ) ( V_2 -> V_54 + ( V_53 ) V_88 ) ) ;
V_82:
F_42 ( V_2 ) ;
return V_19 ;
}
static int T_3 F_43 ( struct V_63 * V_64 )
{
struct V_1 * V_2 = F_44 ( V_64 ) ;
F_20 ( V_2 ) ;
F_45 ( & V_2 -> V_14 ) ;
F_41 ( ( void * ) ( V_2 -> V_54 + ( V_53 ) V_88 ) ) ;
F_42 ( V_2 ) ;
return 0 ;
}
int T_4 F_46 ( void )
{
return F_47 ( & V_105 ) ;
}
void T_5 F_48 ( void )
{
F_49 ( & V_105 ) ;
}

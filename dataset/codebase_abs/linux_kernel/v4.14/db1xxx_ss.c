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
return ! F_5 ( V_2 -> V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
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
static inline void F_7 ( struct V_1 * V_2 , int V_10 )
{
if ( V_2 -> V_11 != - 1 ) {
if ( V_10 )
F_8 ( V_2 -> V_11 ) ;
else
F_9 ( V_2 -> V_11 ) ;
}
}
static T_1 F_10 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_11 ( & V_2 -> V_14 , V_15 ) ;
return V_16 ;
}
static T_1 F_12 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_11 ( & V_2 -> V_14 , V_17 ) ;
return V_16 ;
}
static T_1 F_13 ( int V_12 , void * V_13 )
{
F_14 ( V_12 ) ;
return V_18 ;
}
static T_1 F_15 ( int V_12 , void * V_13 )
{
struct V_1 * V_2 = V_13 ;
F_16 ( 100 ) ;
if ( V_12 == V_2 -> V_19 )
F_8 ( V_2 -> V_20 ) ;
else
F_8 ( V_2 -> V_19 ) ;
F_11 ( & V_2 -> V_14 , V_15 ) ;
return V_16 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_21 ;
if ( V_2 -> V_11 != - 1 ) {
V_21 = F_18 ( V_2 -> V_11 , F_12 ,
0 , L_1 , V_2 ) ;
if ( V_21 )
return V_21 ;
}
if ( ( V_2 -> V_7 == V_8 ) ||
( V_2 -> V_7 == V_9 ) ) {
V_21 = F_19 ( V_2 -> V_19 , F_13 ,
F_15 , 0 , L_2 , V_2 ) ;
if ( V_21 )
goto V_22;
V_21 = F_19 ( V_2 -> V_20 , F_13 ,
F_15 , 0 , L_3 , V_2 ) ;
if ( V_21 ) {
F_20 ( V_2 -> V_19 , V_2 ) ;
goto V_22;
}
if ( F_6 ( V_2 ) )
F_8 ( V_2 -> V_20 ) ;
else
F_8 ( V_2 -> V_19 ) ;
} else {
F_21 ( V_2 -> V_19 , V_23 ) ;
V_21 = F_18 ( V_2 -> V_19 , F_10 ,
0 , L_4 , V_2 ) ;
if ( V_21 )
goto V_22;
}
return 0 ;
V_22:
if ( V_2 -> V_11 != - 1 )
F_20 ( V_2 -> V_11 , V_2 ) ;
return V_21 ;
}
static void F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 != - 1 )
F_20 ( V_2 -> V_11 , V_2 ) ;
F_20 ( V_2 -> V_19 , V_2 ) ;
if ( V_2 -> V_20 != - 1 )
F_20 ( V_2 -> V_20 , V_2 ) ;
}
static int F_23 ( struct V_24 * V_25 ,
struct V_26 * V_27 )
{
struct V_1 * V_2 = F_24 ( V_25 ) ;
unsigned short V_28 , V_29 ;
unsigned int V_30 ;
int V_31 , V_32 , V_21 ;
V_28 = ( 0xf << ( V_2 -> V_5 * 8 ) ) ;
V_29 = 0 ;
V_31 = V_32 = V_21 = 0 ;
switch ( V_27 -> V_33 ) {
case 50 :
++ V_31 ;
case 33 :
++ V_31 ;
case 0 :
break;
default:
F_25 ( V_34 L_5 ,
V_2 -> V_5 , V_27 -> V_33 ) ;
}
switch ( V_27 -> V_35 ) {
case 12 :
++ V_32 ;
case 33 :
case 50 :
++ V_32 ;
case 0 :
break;
default:
F_25 ( V_34 L_6 ,
V_2 -> V_5 , V_27 -> V_35 ) ;
}
if ( ( ( V_27 -> V_33 == 33 ) && ( V_27 -> V_35 == 50 ) ) ||
( ( V_27 -> V_33 == 50 ) && ( V_27 -> V_35 == 33 ) ) ) {
F_25 ( V_34 L_7 ,
V_2 -> V_5 , V_27 -> V_33 , V_27 -> V_35 ) ;
V_31 = V_32 = 0 ;
V_21 = - V_36 ;
}
if ( V_2 -> V_7 != V_9 )
V_29 |= ( ( V_31 << 2 ) | V_32 ) << ( V_2 -> V_5 * 8 ) ;
V_30 = V_27 -> V_37 ^ V_2 -> V_38 ;
if ( V_30 & V_39 ) {
if ( V_27 -> V_37 & V_39 ) {
F_7 ( V_2 , 0 ) ;
V_28 |= ( 1 << ( 7 + ( V_2 -> V_5 * 8 ) ) ) ;
V_28 |= ( 1 << ( 4 + ( V_2 -> V_5 * 8 ) ) ) ;
} else {
V_29 |= 1 << ( 7 + ( V_2 -> V_5 * 8 ) ) ;
V_29 |= 1 << ( 4 + ( V_2 -> V_5 * 8 ) ) ;
}
}
F_26 ( V_40 , V_28 , V_29 ) ;
V_2 -> V_38 = V_27 -> V_37 ;
if ( ( V_30 & V_39 ) && ! ( V_27 -> V_37 & V_39 ) ) {
F_16 ( 500 ) ;
F_7 ( V_2 , 1 ) ;
}
return V_21 ;
}
static int F_27 ( struct V_24 * V_25 ,
unsigned int * V_41 )
{
struct V_1 * V_2 = F_24 ( V_25 ) ;
unsigned short V_42 , V_43 ;
unsigned int V_44 ;
V_44 = F_6 ( V_2 ) ? V_15 : 0 ;
V_42 = F_2 ( V_40 ) ;
V_43 = F_2 ( V_45 ) ;
if ( V_2 -> V_7 == V_46 )
V_43 >>= 4 ;
switch ( F_28 ( V_43 , V_2 -> V_5 ) ) {
case 0 :
case 2 :
V_44 |= V_47 ;
case 3 :
break;
default:
V_44 |= V_48 ;
}
V_44 |= F_29 ( V_42 , V_2 -> V_5 ) ? V_49 : 0 ;
if ( ( V_2 -> V_7 == V_9 ) && ( V_44 & V_15 ) )
V_44 = V_49 | V_47 | V_15 ;
V_44 |= ( F_30 ( V_42 , V_2 -> V_5 ) ) ? V_50 : V_39 ;
* V_41 = V_44 ;
return 0 ;
}
static int F_31 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_32 ( struct V_24 * V_25 )
{
return 0 ;
}
static int F_33 ( struct V_24 * V_25 ,
struct V_51 * V_52 )
{
struct V_1 * V_2 = F_24 ( V_25 ) ;
V_52 -> V_53 = ( V_54 ) V_2 -> V_55 ;
V_52 -> V_56 = V_52 -> V_53 + V_57 ;
return 0 ;
}
static int F_34 ( struct V_24 * V_25 ,
struct V_58 * V_52 )
{
struct V_1 * V_2 = F_24 ( V_25 ) ;
if ( V_52 -> V_37 & V_59 )
V_52 -> V_60 = V_2 -> V_61 + V_52 -> V_62 ;
else
V_52 -> V_60 = V_2 -> V_63 + V_52 -> V_62 ;
return 0 ;
}
static int F_35 ( struct V_64 * V_65 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 ;
int V_21 , V_68 ;
V_2 = F_36 ( sizeof( struct V_1 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
V_2 -> V_5 = V_65 -> V_71 ;
V_68 = F_37 ( F_2 ( V_72 ) ) ;
switch ( V_68 ) {
case V_73 :
case V_74 :
case V_75 :
V_2 -> V_7 = V_46 ;
break;
case V_76 ... V_77 :
V_2 -> V_7 = V_78 ;
break;
case V_79 ... V_80 :
V_2 -> V_7 = V_8 ;
break;
case V_81 :
V_2 -> V_7 = V_9 ;
break;
default:
F_25 ( V_34 L_8 , V_68 ) ;
V_21 = - V_82 ;
goto V_83;
} ;
V_67 = F_38 ( V_65 , V_84 , L_9 ) ;
V_2 -> V_85 = V_67 ? V_67 -> V_53 : 0 ;
V_67 = F_38 ( V_65 , V_84 , L_10 ) ;
V_2 -> V_19 = V_67 ? V_67 -> V_53 : - 1 ;
if ( V_2 -> V_7 == V_78 ) {
V_2 -> V_6 = V_67 ? V_67 -> V_53 : - 1 ;
V_2 -> V_19 = V_67 ? F_39 ( V_67 -> V_53 ) : - 1 ;
}
V_67 = F_38 ( V_65 , V_84 , L_11 ) ;
V_2 -> V_11 = V_67 ? V_67 -> V_53 : - 1 ;
V_67 = F_38 ( V_65 , V_84 , L_12 ) ;
V_2 -> V_20 = V_67 ? V_67 -> V_53 : - 1 ;
V_21 = - V_82 ;
V_67 = F_38 ( V_65 , V_86 , L_13 ) ;
if ( ! V_67 ) {
F_25 ( V_87 L_14 ,
V_2 -> V_5 ) ;
goto V_83;
}
V_2 -> V_61 = V_67 -> V_53 ;
V_67 = F_38 ( V_65 , V_86 , L_15 ) ;
if ( ! V_67 ) {
F_25 ( V_87 L_16 ,
V_2 -> V_5 ) ;
goto V_83;
}
V_2 -> V_63 = V_67 -> V_53 ;
V_67 = F_38 ( V_65 , V_86 , L_17 ) ;
if ( ! V_67 ) {
F_25 ( V_87 L_18 ,
V_2 -> V_5 ) ;
goto V_83;
}
V_2 -> V_88 = V_67 -> V_53 ;
V_2 -> V_55 = ( void * ) ( F_40 ( V_2 -> V_88 , V_57 ) -
V_89 ) ;
if ( ! V_2 -> V_55 ) {
F_25 ( V_87 L_19 ,
V_2 -> V_5 ) ;
V_21 = - V_70 ;
goto V_83;
}
V_2 -> V_14 . V_90 = & V_91 ;
V_2 -> V_14 . V_92 = V_93 ;
V_2 -> V_14 . V_94 = V_2 -> V_85 ;
V_2 -> V_14 . V_95 = V_96 | V_97 ;
V_2 -> V_14 . V_98 = V_99 ;
V_2 -> V_14 . V_100 = ( unsigned long ) V_2 -> V_55 ;
V_2 -> V_14 . V_101 . V_102 = & V_65 -> V_101 ;
V_2 -> V_14 . V_103 = & V_104 ;
F_41 ( V_65 , V_2 ) ;
V_21 = F_17 ( V_2 ) ;
if ( V_21 ) {
F_25 ( V_87 L_20 ,
V_2 -> V_5 ) ;
goto V_22;
}
F_7 ( V_2 , 0 ) ;
V_21 = F_42 ( & V_2 -> V_14 ) ;
if ( V_21 ) {
F_25 ( V_87 L_21 , V_2 -> V_5 ) ;
goto V_105;
}
F_25 ( V_34 L_22
L_23
L_24 , V_2 -> V_5 , V_2 -> V_88 , V_2 -> V_55 ,
V_2 -> V_61 , V_2 -> V_63 , V_2 -> V_85 ,
V_2 -> V_19 , V_2 -> V_11 , V_2 -> V_20 ) ;
return 0 ;
V_105:
F_22 ( V_2 ) ;
V_22:
F_43 ( ( void * ) ( V_2 -> V_55 + ( V_54 ) V_89 ) ) ;
V_83:
F_44 ( V_2 ) ;
return V_21 ;
}
static int F_45 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_46 ( V_65 ) ;
F_22 ( V_2 ) ;
F_47 ( & V_2 -> V_14 ) ;
F_43 ( ( void * ) ( V_2 -> V_55 + ( V_54 ) V_89 ) ) ;
F_44 ( V_2 ) ;
return 0 ;
}

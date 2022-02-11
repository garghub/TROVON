static int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 ;
int V_9 ;
V_9 = V_3 & 0x3 ;
V_4 = ( ( V_4 - 1 ) + V_9 ) & 0x3 ;
return V_6 -> V_10 [ V_4 ] ;
}
static int F_2 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 * V_13 )
{
T_2 * V_14 , V_15 , V_16 ;
if ( V_12 & 0x3 )
return - V_17 ;
if ( V_7 == 0 ) {
V_11 += ( 0x8 * 6 ) ;
} else if ( V_7 == V_18 ) {
V_7 = 0 ;
V_11 = 0 ;
}
V_16 = F_3 ( V_6 -> V_19 -> V_20 ) ;
F_4 ( V_6 -> V_19 -> V_20 , ( V_16 & ~ ( 0xf << 23 ) ) | ( V_7 << 23 ) ) ;
V_14 = ( T_2 * ) ( V_6 -> V_14 | ( V_11 << 8 ) | ( V_12 & 0xfc ) ) ;
V_15 = F_5 ( V_14 ) ;
if ( F_3 ( V_6 -> V_19 -> V_20 ) & V_21 ) {
* V_13 = 0xffffffff ;
V_15 = F_3 ( V_6 -> V_19 -> V_22 ) ;
F_6 ( V_6 , V_18 , 0 , V_23 , V_15 ) ;
} else {
* V_13 = F_7 ( V_15 ) ;
}
return 0 ;
}
static int F_8 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 * V_13 )
{
T_2 V_24 ;
int V_25 ;
if ( V_12 & 0x1 )
return - V_17 ;
V_25 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_24 ) ;
* V_13 = 0xffff & ( V_24 >> ( 8 * ( V_12 & 0x3 ) ) ) ;
return V_25 ;
}
static int F_9 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 * V_13 )
{
T_2 V_24 ;
int V_25 ;
V_25 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_24 ) ;
* V_13 = 0xff & ( V_24 >> ( 8 * ( V_12 & 3 ) ) ) ;
return V_25 ;
}
static int F_6 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
unsigned int * V_14 ;
T_2 V_16 ;
if ( V_12 & 0x3 )
return - V_17 ;
if ( V_7 == 0 ) {
V_11 += ( 0x8 * 6 ) ;
} else if ( V_7 == V_18 ) {
V_7 = 0 ;
V_11 = 0 ;
}
V_16 = F_3 ( V_6 -> V_19 -> V_20 ) ;
F_4 ( V_6 -> V_19 -> V_20 , ( V_16 & ~ ( 0xf << 23 ) ) | ( V_7 << 23 ) ) ;
V_14 = ( unsigned int * ) ( V_6 -> V_14 |
( V_11 << 8 ) | ( V_12 & 0xfc ) ) ;
F_10 ( V_14 , F_7 ( V_13 ) ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
int V_25 ;
T_2 V_24 ;
if ( V_12 & 0x1 )
return - V_17 ;
V_25 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 3 , & V_24 ) ;
if ( V_25 )
return V_25 ;
V_24 = ( V_24 & ~ ( 0xffff << ( 8 * ( V_12 & 0x3 ) ) ) ) |
( ( 0xffff & V_13 ) << ( 8 * ( V_12 & 0x3 ) ) ) ;
return F_6 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , V_24 ) ;
}
static int F_12 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned int V_11 , int V_12 , T_2 V_13 )
{
int V_25 ;
T_2 V_24 ;
V_25 = F_2 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , & V_24 ) ;
if ( V_25 != 0 )
return V_25 ;
V_24 = ( V_24 & ~ ( 0xff << ( 8 * ( V_12 & 0x3 ) ) ) ) |
( ( 0xff & V_13 ) << ( 8 * ( V_12 & 0x3 ) ) ) ;
return F_6 ( V_6 , V_7 , V_11 , V_12 & ~ 0x3 , V_24 ) ;
}
static int F_13 ( struct V_26 * V_7 , unsigned int V_11 ,
int V_12 , int V_27 , T_2 * V_13 )
{
struct V_5 * V_6 = V_28 ;
unsigned int V_29 = V_7 -> V_30 ;
int V_25 ;
if ( F_14 ( V_11 ) > 15 || V_29 > 15 ) {
* V_13 = ~ 0 ;
return 0 ;
}
switch ( V_27 ) {
case 1 :
V_25 = F_9 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
break;
case 2 :
V_25 = F_8 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
break;
case 4 :
V_25 = F_2 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
break;
default:
V_25 = - V_17 ;
break;
}
#ifdef F_15
F_16 ( V_31
L_1 ,
V_29 , F_14 ( V_11 ) , F_17 ( V_11 ) , V_12 , * V_13 , V_27 ) ;
#endif
return V_25 ;
}
static int F_18 ( struct V_26 * V_7 , unsigned int V_11 ,
int V_12 , int V_27 , T_2 V_13 )
{
struct V_5 * V_6 = V_28 ;
unsigned int V_29 = V_7 -> V_30 ;
if ( F_14 ( V_11 ) > 15 || V_29 > 15 )
return 0 ;
#ifdef F_15
F_16 ( V_31
L_2 ,
V_29 , F_14 ( V_11 ) , F_17 ( V_11 ) , V_12 , V_27 , V_13 ) ;
#endif
switch ( V_27 ) {
default:
return - V_17 ;
case 1 :
return F_12 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
case 2 :
return F_11 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
case 4 :
return F_6 ( V_6 , V_29 , V_11 , V_12 , V_13 ) ;
}
}
static void F_19 ( struct V_32 * V_33 )
{
T_2 V_34 ;
struct V_5 * V_6 = V_28 ;
V_34 = ( T_2 ) V_33 -> V_35 - 1 ;
if ( V_34 > 3 )
return;
V_34 += V_36 ;
F_4 ( V_6 -> V_19 -> V_37 , F_3 ( V_6 -> V_19 -> V_37 ) & ~ ( 1 << V_34 ) ) ;
}
static void F_20 ( struct V_32 * V_33 )
{
T_2 V_34 ;
struct V_5 * V_6 = V_28 ;
V_34 = ( T_2 ) V_33 -> V_35 - 1 ;
if ( V_34 > 3 )
return;
V_34 += V_36 ;
F_4 ( V_6 -> V_19 -> V_37 , F_3 ( V_6 -> V_19 -> V_37 ) | ( 1 << V_34 ) ) ;
}
static unsigned int F_21 ( struct V_32 * V_33 )
{
F_20 ( V_33 ) ;
return 0 ;
}
static void F_22 ( struct V_32 * V_33 )
{
F_19 ( V_33 ) ;
}
static void F_23 ( unsigned int V_37 , struct V_38 * V_39 )
{
struct V_5 * V_6 = V_28 ;
int V_40 , V_41 = 0 ;
unsigned int V_42 ;
V_42 = F_3 ( V_6 -> V_19 -> V_37 ) ;
V_42 = ( V_42 >> V_36 ) & V_42 ;
if ( V_42 & V_43 ) {
F_24 ( V_6 -> V_44 ) ;
V_41 = 1 ;
}
if ( V_42 & V_45 ) {
for ( V_40 = 0 ; V_40 < 4 ; V_40 ++ ) {
if ( V_42 & ( 1 << V_40 ) )
F_24 ( V_6 -> V_10 [ V_40 ] ) ;
}
V_41 = 1 ;
}
if ( V_41 )
V_39 -> V_32 . V_46 -> V_47 ( & V_39 -> V_32 ) ;
}
static unsigned int F_25 ( unsigned int V_37 )
{
unsigned int V_48 = 0 , V_49 ;
V_49 = 1 << 8 ;
V_48 = F_26 ( V_37 , V_49 ) ;
if ( V_48 == 0 )
goto V_50;
F_27 ( V_48 , & V_51 , V_52 ,
L_3 ) ;
F_28 ( V_48 , ( void * ) V_37 ) ;
V_50:
return V_48 ;
}
static void F_29 ( struct V_5 * V_6 )
{
T_2 V_53 , V_54 , V_33 , V_55 ;
struct V_56 T_3 * V_19 = V_6 -> V_19 ;
F_4 ( V_19 -> V_20 , V_6 -> V_57 & 0xf0000000 ) ;
V_53 = 0xf0000000 & ( T_2 ) F_30 ( F_31 ( ( unsigned long ) & V_58 ) ) ;
F_4 ( V_19 -> V_59 , V_53 ) ;
F_4 ( V_19 -> V_60 , F_3 ( V_19 -> V_60 ) & 0x0000ffff ) ;
F_4 ( V_19 -> V_37 , 0 ) ;
F_6 ( V_6 , V_18 , 0 , V_61 , 0xffffffff ) ;
F_2 ( V_6 , V_18 , 0 , V_61 , & V_54 ) ;
V_54 = ~ V_54 + 1 ;
V_55 = V_6 -> V_57 - V_54 ;
F_6 ( V_6 , V_18 , 0 , V_61 , V_55 ) ;
F_6 ( V_6 , V_18 , 0 , V_62 , V_53 ) ;
F_12 ( V_6 , V_18 , 0 , V_63 , 0xff ) ;
F_12 ( V_6 , V_18 , 0 , V_64 , 0x40 ) ;
F_2 ( V_6 , V_18 , 0 , V_23 , & V_33 ) ;
V_33 |= ( V_65 | V_66 ) ;
F_6 ( V_6 , V_18 , 0 , V_23 , V_33 ) ;
}
static T_4 F_32 ( int V_37 , void * V_67 )
{
struct V_5 * V_6 = V_67 ;
F_33 ( V_6 -> V_2 , L_4 ) ;
return V_68 ;
}
static T_4 F_34 ( int V_37 , void * V_67 )
{
struct V_5 * V_6 = V_67 ;
T_2 V_69 ;
F_8 ( V_6 , V_18 , 0 , V_70 , & V_69 ) ;
V_69 &= V_6 -> V_71 ;
if ( V_69 == 0 )
return V_68 ;
if ( V_69 & V_72 )
F_33 ( V_6 -> V_2 , L_5 ) ;
if ( V_69 & V_73 )
F_33 ( V_6 -> V_2 , L_6 ) ;
if ( V_69 & V_74 )
F_33 ( V_6 -> V_2 , L_7 ) ;
if ( V_69 & V_75 )
F_33 ( V_6 -> V_2 , L_8 ) ;
if ( V_69 & V_76 )
F_33 ( V_6 -> V_2 , L_9 ) ;
if ( V_69 & V_77 )
F_33 ( V_6 -> V_2 , L_10 ) ;
F_11 ( V_6 , V_18 , 0 , V_70 , V_69 ) ;
return V_78 ;
}
static int F_35 ( struct V_79 * V_80 )
{
struct V_56 T_3 * V_19 ;
struct V_5 * V_6 ;
int V_81 , V_82 ;
const int * V_15 ;
T_2 V_16 , V_27 , V_83 ;
struct V_84 * V_85 ;
if ( V_28 ) {
F_33 ( & V_80 -> V_2 , L_11 ) ;
return - V_86 ;
}
if ( V_80 -> V_87 < 3 ) {
F_33 ( & V_80 -> V_2 , L_12 ) ;
return - V_88 ;
}
V_6 = F_36 ( & V_80 -> V_2 , sizeof( * V_6 ) , V_89 ) ;
if ( ! V_6 ) {
F_33 ( & V_80 -> V_2 , L_13 ) ;
return - V_90 ;
}
F_37 ( V_80 , V_6 ) ;
V_6 -> V_2 = & V_80 -> V_2 ;
V_85 = F_38 ( V_80 , V_91 , 0 ) ;
V_19 = F_39 ( & V_80 -> V_2 , V_85 ) ;
if ( F_40 ( V_19 ) )
return F_41 ( V_19 ) ;
V_16 = F_3 ( V_19 -> V_20 ) ;
if ( ( V_16 & V_92 ) == 0 ) {
F_33 ( & V_80 -> V_2 , L_14 ) ;
return - V_88 ;
}
F_4 ( V_19 -> V_59 , 0xffffffff ) ;
V_27 = ~ F_3 ( V_19 -> V_59 ) + 1 ;
if ( V_27 < 0x10000000 ) {
F_33 ( & V_80 -> V_2 , L_15 ) ;
return - V_88 ;
}
if ( ( F_3 ( V_19 -> V_93 ) & V_94 ) == 0 ) {
F_33 ( & V_80 -> V_2 , L_16 ) ;
return - V_88 ;
}
V_6 -> V_19 = V_19 ;
V_6 -> V_37 = F_42 ( V_80 -> V_2 . V_95 , 0 ) ;
F_43 ( & V_80 -> V_2 , L_17 , V_19 , V_6 -> V_37 ) ;
V_6 -> V_57 = V_80 -> V_84 [ 1 ] . V_96 ;
V_6 -> V_97 = V_80 -> V_84 [ 1 ] . V_98 + 1 ;
V_6 -> V_99 = V_80 -> V_84 [ 2 ] . V_96 ;
V_6 -> V_14 = V_80 -> V_84 [ 2 ] . V_96 + 0x10000 ;
V_6 -> V_100 = V_6 -> V_14 + 0x10000 ;
V_6 -> V_101 = ( unsigned long ) F_44 ( V_6 -> V_99 , 0x10000 ) ;
if ( ! V_6 -> V_101 ) {
F_33 ( & V_80 -> V_2 , L_18 ) ;
return - V_88 ;
}
F_16 ( V_31
L_19
L_20
L_21 ,
V_6 -> V_57 , V_6 -> V_97 - 1 ,
V_6 -> V_99 , V_6 -> V_14 - 1 ,
V_6 -> V_14 , V_6 -> V_100 - 1 ) ;
V_6 -> V_102 . V_103 . V_104 = L_22 ;
V_6 -> V_102 . V_103 . V_96 = V_6 -> V_101 + 0x1000 ;
V_6 -> V_102 . V_103 . V_98 = V_6 -> V_101 + 0x10000 - 1 ;
V_6 -> V_102 . V_103 . V_105 = V_106 ;
V_6 -> V_102 . V_107 . V_104 = L_23 ;
V_6 -> V_102 . V_107 . V_96 = V_6 -> V_57 ;
V_6 -> V_102 . V_107 . V_98 = V_6 -> V_97 - 1 ;
V_6 -> V_102 . V_107 . V_105 = V_91 ;
if ( F_45 ( & V_108 , & V_6 -> V_102 . V_107 ) < 0 ) {
F_33 ( & V_80 -> V_2 , L_24 ) ;
V_81 = - V_90 ;
goto V_109;
}
if ( F_45 ( & V_110 , & V_6 -> V_102 . V_103 ) < 0 ) {
F_33 ( & V_80 -> V_2 , L_25 ) ;
V_81 = - V_90 ;
goto V_111;
}
V_6 -> V_102 . V_112 . V_104 = L_26 ;
V_6 -> V_102 . V_112 . V_96 = 0 ;
V_6 -> V_102 . V_112 . V_98 = 15 ;
V_28 = V_6 ;
F_29 ( V_6 ) ;
F_46 ( V_6 -> V_37 , F_23 , L_3 , 0 ) ;
V_6 -> V_10 [ 0 ] = F_25 ( 1 ) ;
V_6 -> V_10 [ 1 ] = F_25 ( 2 ) ;
V_6 -> V_10 [ 2 ] = F_25 ( 3 ) ;
V_6 -> V_10 [ 3 ] = F_25 ( 4 ) ;
V_6 -> V_44 = F_25 ( 5 ) ;
F_16 ( V_31 L_27 ,
V_6 -> V_10 [ 0 ] , V_6 -> V_10 [ 1 ] , V_6 -> V_10 [ 2 ] ,
V_6 -> V_10 [ 3 ] ) ;
V_81 = F_47 ( & V_80 -> V_2 , V_6 -> V_37 , F_32 , 0 ,
L_28 , V_6 ) ;
if ( V_81 ) {
F_33 ( & V_80 -> V_2 , L_29 , V_81 ) ;
goto V_113;
}
V_81 = F_47 ( & V_80 -> V_2 , V_6 -> V_44 ,
F_34 , V_114 , L_30 ,
V_6 ) ;
if ( V_81 ) {
F_33 ( & V_80 -> V_2 , L_31 , V_81 ) ;
goto V_113;
}
V_15 = F_48 ( V_80 -> V_2 . V_95 , L_32 , & V_82 ) ;
if ( V_15 && ( V_82 == 4 ) ) {
V_6 -> V_71 = V_115 ;
V_83 = V_43 << V_36 ;
} else {
V_6 -> V_71 = V_116 ;
V_83 = V_117 << V_36 ;
}
F_4 ( V_19 -> V_37 , V_83 ) ;
V_6 -> V_102 . V_118 = & V_119 ;
V_6 -> V_102 . V_120 = F_1 ;
F_49 ( V_80 , & V_6 -> V_102 ) ;
return 0 ;
V_113:
F_50 ( & V_6 -> V_102 . V_103 ) ;
V_111:
F_50 ( & V_6 -> V_102 . V_107 ) ;
V_109:
F_51 ( ( void T_3 * ) V_6 -> V_101 ) ;
V_28 = NULL ;
return V_81 ;
}
static int T_5 F_52 ( void )
{
return F_53 ( & V_121 ) ;
}

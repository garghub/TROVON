static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
T_2 V_5 , V_6 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_5 = F_3 ( V_2 , & V_4 ) ;
if ( V_5 & 7 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_4 ( V_2 , V_5 , V_4 , & V_6 , sizeof( V_6 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , 3 , L_1 , V_6 ) ;
F_7 ( V_2 -> V_14 , V_6 ) ;
F_8 ( V_2 , 0 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_2 V_15 ;
T_3 V_16 ;
int V_3 ;
T_1 V_4 ;
V_2 -> V_17 . V_18 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_15 = F_3 ( V_2 , & V_4 ) ;
if ( V_15 & 3 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_4 ( V_2 , V_15 , V_4 , & V_16 , sizeof( V_16 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
V_16 &= 0x7fffe000u ;
if ( F_10 ( V_2 -> V_14 , V_16 ) )
return F_2 ( V_2 , V_19 ) ;
F_11 ( V_2 , V_16 ) ;
F_12 ( V_2 , 1 , V_16 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_2 V_15 ;
T_3 V_16 ;
int V_3 ;
T_1 V_4 ;
V_2 -> V_17 . V_20 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_15 = F_3 ( V_2 , & V_4 ) ;
if ( V_15 & 3 )
return F_2 ( V_2 , V_13 ) ;
V_16 = F_14 ( V_2 ) ;
V_3 = F_15 ( V_2 , V_15 , V_4 , & V_16 , sizeof( V_16 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , 3 , L_2 , V_16 , V_15 ) ;
F_12 ( V_2 , 0 , V_16 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
T_4 V_21 = V_2 -> V_21 ;
T_2 V_22 ;
int V_3 ;
T_1 V_4 ;
V_2 -> V_17 . V_23 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_3 ( V_2 , & V_4 ) ;
if ( V_22 & 1 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_15 ( V_2 , V_22 , V_4 , & V_21 , sizeof( V_21 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , 3 , L_3 , V_21 , V_22 ) ;
F_17 ( V_2 , V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! ( V_2 -> V_7 . V_8 -> V_24 & ( V_25 | V_26 | V_27 ) ) )
return V_3 ;
V_3 = F_19 () ;
F_6 ( V_2 , 3 , L_4 , L_5 ) ;
F_20 ( V_2 ) ;
V_2 -> V_7 . V_8 -> V_24 &= ~ ( V_25 | V_26 | V_27 ) ;
return V_3 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_3 = F_18 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_17 . V_28 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
F_22 ( V_2 ) ;
F_6 ( V_2 , 4 , L_4 , L_6 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
V_2 -> V_17 . V_29 ++ ;
if ( F_24 ( V_2 -> V_7 . V_8 -> V_9 ) . V_30 )
return F_2 ( V_2 , V_12 ) ;
F_25 ( V_2 -> V_14 -> V_7 . V_31 , ! F_26 ( V_2 ) ) ;
F_22 ( V_2 ) ;
F_6 ( V_2 , 4 , L_4 , L_7 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
T_5 V_32 ;
int V_33 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
F_28 ( V_2 , NULL , & V_33 ) ;
V_32 = V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_33 ] & V_38 ;
V_32 = F_29 ( V_2 , V_32 ) ;
if ( F_30 ( V_2 , V_32 ) )
return F_31 ( V_2 , & V_2 -> V_7 . V_39 ) ;
V_32 = F_32 ( V_2 , V_32 ) ;
if ( F_10 ( V_2 -> V_14 , V_32 ) )
return F_2 ( V_2 , V_19 ) ;
if ( F_33 ( V_2 -> V_14 , V_32 , V_40 ) )
return - V_41 ;
F_8 ( V_2 , 0 ) ;
V_2 -> V_34 -> V_35 . V_36 . V_37 [ 0 ] = 0 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
unsigned long V_44 ;
T_3 V_45 [ 3 ] ;
int V_3 ;
T_2 V_32 ;
T_1 V_4 ;
V_32 = F_3 ( V_2 , & V_4 ) ;
if ( V_32 & 3 )
return F_2 ( V_2 , V_13 ) ;
V_43 = F_35 ( V_2 -> V_14 , V_2 -> V_7 . V_8 -> V_46 [ 6 ] , 0 ) ;
if ( ! V_43 ) {
F_8 ( V_2 , 0 ) ;
return 0 ;
}
V_45 [ 0 ] = V_43 -> V_47 . V_48 << 16 | V_43 -> V_47 . V_49 ;
V_45 [ 1 ] = V_43 -> V_47 . V_50 ;
V_45 [ 2 ] = V_43 -> V_47 . V_51 ;
if ( V_32 ) {
V_44 = sizeof( V_45 ) - 4 ;
V_3 = F_15 ( V_2 , V_32 , V_4 , & V_45 , V_44 ) ;
if ( V_3 ) {
V_3 = F_5 ( V_2 , V_3 ) ;
goto V_52;
}
} else {
V_44 = sizeof( V_45 ) ;
if ( F_36 ( V_2 , V_53 , & V_45 , V_44 ) ) {
V_3 = - V_41 ;
goto V_52;
}
}
F_37 ( V_43 ) ;
F_8 ( V_2 , 1 ) ;
return 0 ;
V_52:
if ( F_38 ( V_2 -> V_14 , V_43 ) ) {
F_37 ( V_43 ) ;
V_3 = - V_41 ;
}
return V_3 ? - V_41 : 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_42 * V_43 = NULL ;
const T_2 V_54 = 0xffUL << 24 ;
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ 1 ] )
V_43 = F_35 ( V_2 -> V_14 , V_54 ,
V_2 -> V_34 -> V_35 . V_36 . V_37 [ 1 ] ) ;
V_2 -> V_34 -> V_55 = V_56 ;
V_2 -> V_34 -> V_57 . V_58 = ! ! V_43 ;
if ( V_43 ) {
V_2 -> V_34 -> V_57 . V_48 = V_43 -> V_47 . V_48 ;
V_2 -> V_34 -> V_57 . V_49 = V_43 -> V_47 . V_49 ;
V_2 -> V_34 -> V_57 . V_50 = V_43 -> V_47 . V_50 ;
V_2 -> V_34 -> V_57 . V_51 = V_43 -> V_47 . V_51 ;
}
V_2 -> V_34 -> V_57 . V_59 = V_2 -> V_7 . V_8 -> V_59 ;
F_37 ( V_43 ) ;
return - V_60 ;
}
static int F_40 ( struct V_1 * V_2 )
{
F_6 ( V_2 , 4 , L_4 , L_8 ) ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( V_2 -> V_14 -> V_7 . V_61 ) {
if ( V_2 -> V_7 . V_8 -> V_62 == 0xb236 )
return F_34 ( V_2 ) ;
if ( V_2 -> V_7 . V_8 -> V_62 == 0xb235 )
return F_39 ( V_2 ) ;
return - V_63 ;
} else {
F_8 ( V_2 , 3 ) ;
return 0 ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_64 ;
V_2 -> V_17 . V_65 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_64 = * V_2 -> V_14 -> V_7 . V_66 . V_67 >> 32 ;
V_3 = F_36 ( V_2 , F_42 ( struct V_68 , V_69 ) ,
& V_64 , sizeof( V_64 ) ) ;
if ( V_3 )
return V_3 ;
F_6 ( V_2 , 3 , L_9 , V_64 ) ;
F_43 ( V_2 , V_64 ) ;
return 0 ;
}
int F_44 ( T_6 * V_70 )
{
if ( V_70 -> V_10 & V_71 )
return 0 ;
if ( ( V_70 -> V_10 & V_72 ) == V_73 ) {
if ( V_70 -> V_32 & ~ V_74 )
return 0 ;
}
if ( ! ( V_70 -> V_10 & V_72 ) && ( V_70 -> V_32 & ~ V_75 ) )
return 0 ;
if ( ( V_70 -> V_10 & V_72 ) == V_76 )
return 0 ;
if ( V_70 -> V_32 & 1 )
return 0 ;
return 1 ;
}
int F_45 ( struct V_1 * V_2 )
{
T_6 * V_9 = & V_2 -> V_7 . V_8 -> V_9 ;
T_7 V_77 ;
T_2 V_32 ;
int V_3 ;
T_1 V_4 ;
if ( V_9 -> V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_32 = F_3 ( V_2 , & V_4 ) ;
if ( V_32 & 7 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_4 ( V_2 , V_32 , V_4 , & V_77 , sizeof( V_77 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
if ( ! ( V_77 . V_10 & V_78 ) )
return F_2 ( V_2 , V_13 ) ;
V_9 -> V_10 = ( V_77 . V_10 & ~ V_78 ) << 32 ;
V_9 -> V_10 |= V_77 . V_32 & V_79 ;
V_9 -> V_32 = V_77 . V_32 & ~ V_79 ;
if ( ! F_44 ( V_9 ) )
return F_2 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
T_6 V_77 ;
T_2 V_32 ;
int V_3 ;
T_1 V_4 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_32 = F_3 ( V_2 , & V_4 ) ;
if ( V_32 & 7 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_4 ( V_2 , V_32 , V_4 , & V_77 , sizeof( V_77 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
V_2 -> V_7 . V_8 -> V_9 = V_77 ;
if ( ! F_44 ( & V_2 -> V_7 . V_8 -> V_9 ) )
return F_2 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
T_2 V_80 = V_2 -> V_14 -> V_7 . V_66 . V_81 ;
T_2 V_15 ;
int V_3 ;
T_1 V_4 ;
V_2 -> V_17 . V_82 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_15 = F_3 ( V_2 , & V_4 ) ;
if ( V_15 & 7 )
return F_2 ( V_2 , V_13 ) ;
V_3 = F_15 ( V_2 , V_15 , V_4 , & V_80 , sizeof( V_80 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
F_6 ( V_2 , 3 , L_10 , V_80 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 , struct V_83 * V_84 )
{
int V_85 = 0 ;
int V_86 ;
V_85 = F_49 ( & V_2 -> V_14 -> V_87 ) ;
if ( F_50 ( V_84 , 3 , 2 , 2 ) )
V_84 -> V_88 = 0 ;
if ( V_84 -> V_88 < 8 )
V_84 -> V_88 ++ ;
for ( V_86 = V_84 -> V_88 - 1 ; V_86 > 0 ; V_86 -- )
memcpy ( & V_84 -> V_89 [ V_86 ] , & V_84 -> V_89 [ V_86 - 1 ] , sizeof( V_84 -> V_89 [ 0 ] ) ) ;
memset ( & V_84 -> V_89 [ 0 ] , 0 , sizeof( V_84 -> V_89 [ 0 ] ) ) ;
V_84 -> V_89 [ 0 ] . V_90 = V_85 ;
V_84 -> V_89 [ 0 ] . V_91 = V_85 ;
V_84 -> V_89 [ 0 ] . V_92 = 0 ;
V_84 -> V_89 [ 0 ] . V_93 = 0 ;
V_84 -> V_89 [ 0 ] . V_94 = 1000 ;
memcpy ( V_84 -> V_89 [ 0 ] . V_95 , L_11 , 8 ) ;
F_51 ( V_84 -> V_89 [ 0 ] . V_95 , 8 ) ;
memcpy ( V_84 -> V_89 [ 0 ] . V_96 , L_12 , 16 ) ;
F_51 ( V_84 -> V_89 [ 0 ] . V_96 , 16 ) ;
}
static void F_52 ( struct V_1 * V_2 , T_2 V_32 , T_1 V_4 ,
T_8 V_97 , T_8 V_98 , T_4 V_99 )
{
V_2 -> V_34 -> V_55 = V_100 ;
V_2 -> V_34 -> V_101 . V_32 = V_32 ;
V_2 -> V_34 -> V_101 . V_4 = V_4 ;
V_2 -> V_34 -> V_101 . V_97 = V_97 ;
V_2 -> V_34 -> V_101 . V_98 = V_98 ;
V_2 -> V_34 -> V_101 . V_99 = V_99 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_97 = ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ 0 ] & 0xf0000000 ) >> 28 ;
int V_98 = V_2 -> V_34 -> V_35 . V_36 . V_37 [ 0 ] & 0xff ;
int V_99 = V_2 -> V_34 -> V_35 . V_36 . V_37 [ 1 ] & 0xffff ;
unsigned long V_84 = 0 ;
T_2 V_15 ;
int V_3 = 0 ;
T_1 V_4 ;
V_2 -> V_17 . V_102 ++ ;
F_6 ( V_2 , 3 , L_13 , V_97 , V_98 , V_99 ) ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( V_97 > 3 ) {
F_8 ( V_2 , 3 ) ;
return 0 ;
}
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ 0 ] & 0x0fffff00
|| V_2 -> V_34 -> V_35 . V_36 . V_37 [ 1 ] & 0xffff0000 )
return F_2 ( V_2 , V_13 ) ;
if ( V_97 == 0 ) {
V_2 -> V_34 -> V_35 . V_36 . V_37 [ 0 ] = 3 << 28 ;
F_8 ( V_2 , 0 ) ;
return 0 ;
}
V_15 = F_3 ( V_2 , & V_4 ) ;
if ( V_15 & 0xfff )
return F_2 ( V_2 , V_13 ) ;
switch ( V_97 ) {
case 1 :
case 2 :
V_84 = F_54 ( V_103 ) ;
if ( ! V_84 )
goto V_104;
if ( F_50 ( ( void * ) V_84 , V_97 , V_98 , V_99 ) )
goto V_104;
break;
case 3 :
if ( V_98 != 2 || V_99 != 2 )
goto V_104;
V_84 = F_54 ( V_103 ) ;
if ( ! V_84 )
goto V_104;
F_48 ( V_2 , ( void * ) V_84 ) ;
break;
}
V_3 = F_15 ( V_2 , V_15 , V_4 , ( void * ) V_84 , V_40 ) ;
if ( V_3 ) {
V_3 = F_5 ( V_2 , V_3 ) ;
goto V_105;
}
if ( V_2 -> V_14 -> V_7 . V_106 ) {
F_52 ( V_2 , V_15 , V_4 , V_97 , V_98 , V_99 ) ;
V_3 = - V_60 ;
}
F_55 ( V_2 , V_97 , V_98 , V_99 , V_15 ) ;
F_56 ( V_84 ) ;
F_8 ( V_2 , 0 ) ;
V_2 -> V_34 -> V_35 . V_36 . V_37 [ 0 ] = 0 ;
return V_3 ;
V_104:
F_8 ( V_2 , 3 ) ;
V_105:
F_56 ( V_84 ) ;
return V_3 ;
}
int F_57 ( struct V_1 * V_2 )
{
T_9 V_107 ;
V_107 = V_108 [ V_2 -> V_7 . V_8 -> V_62 & 0x00ff ] ;
if ( V_107 )
return V_107 ( V_2 ) ;
return - V_63 ;
}
static int F_58 ( struct V_1 * V_2 )
{
int V_109 , V_33 ;
F_28 ( V_2 , & V_109 , & V_33 ) ;
V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] &= 0xffffffff00000000UL ;
V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] |= V_2 -> V_7 . V_8 -> V_9 . V_10 >> 32 ;
if ( V_33 ) {
V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_33 ] &= 0xffffffff00000000UL ;
V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_33 ] |=
V_2 -> V_7 . V_8 -> V_9 . V_10 & 0x00000000ffffffffUL ;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
int V_109 , V_33 ;
unsigned long V_110 , V_111 ;
V_2 -> V_17 . V_112 ++ ;
F_28 ( V_2 , & V_109 , & V_33 ) ;
if ( ! F_60 ( V_2 -> V_14 , 8 ) )
return F_2 ( V_2 , V_113 ) ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_114 )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_115 &&
! F_60 ( V_2 -> V_14 , 14 ) )
return F_2 ( V_2 , V_13 ) ;
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & ( V_116 | V_117 ) )
return F_2 ( V_2 , V_13 ) ;
V_110 = V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_33 ] & V_38 ;
V_110 = F_29 ( V_2 , V_110 ) ;
switch ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_118 ) {
case 0x00000000 :
V_111 = ( V_110 + ( 1UL << 12 ) ) & ~ ( ( 1UL << 12 ) - 1 ) ;
break;
case 0x00001000 :
V_111 = ( V_110 + ( 1UL << 20 ) ) & ~ ( ( 1UL << 20 ) - 1 ) ;
break;
case 0x00002000 :
if ( ! F_60 ( V_2 -> V_14 , 78 ) ||
F_24 ( V_2 -> V_7 . V_8 -> V_9 ) . V_119 == V_120 )
return F_2 ( V_2 , V_13 ) ;
V_111 = ( V_110 + ( 1UL << 31 ) ) & ~ ( ( 1UL << 31 ) - 1 ) ;
break;
default:
return F_2 ( V_2 , V_13 ) ;
}
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_121 ) {
if ( F_30 ( V_2 , V_110 ) )
return F_31 ( V_2 , & V_2 -> V_7 . V_39 ) ;
}
while ( V_110 < V_111 ) {
unsigned long V_122 , V_123 ;
if ( ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_118 ) == 0 )
V_123 = F_32 ( V_2 , V_110 ) ;
else
V_123 = V_110 ;
V_122 = F_61 ( V_2 -> V_14 , F_62 ( V_123 ) ) ;
if ( F_63 ( V_122 ) )
return F_2 ( V_2 , V_19 ) ;
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_121 ) {
if ( F_64 ( ( void V_124 * ) V_122 , V_40 ) )
return F_2 ( V_2 , V_19 ) ;
}
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_125 ) {
int V_3 = F_18 ( V_2 ) ;
if ( V_3 )
return V_3 ;
if ( F_65 ( V_126 -> V_127 , V_122 ,
V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_128 ,
V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_115 ) )
return F_2 ( V_2 , V_19 ) ;
}
V_110 += V_40 ;
}
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_109 ] & V_118 )
V_2 -> V_34 -> V_35 . V_36 . V_37 [ V_33 ] = V_111 ;
return 0 ;
}
static int F_66 ( struct V_1 * V_2 )
{
int V_129 = ( V_2 -> V_7 . V_8 -> V_130 & ~ V_38 ) >> 3 ;
unsigned long * V_130 ;
struct V_131 * V_131 ;
int V_132 ;
F_6 ( V_2 , 4 , L_14 , V_129 ) ;
V_131 = V_2 -> V_7 . V_131 ;
V_2 -> V_17 . V_133 ++ ;
if ( ! V_2 -> V_14 -> V_7 . V_134 )
return F_2 ( V_2 , V_113 ) ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( ( ( V_2 -> V_7 . V_8 -> V_59 & 0xf0000000 ) >> 28 ) > 6 )
return F_2 ( V_2 , V_13 ) ;
F_22 ( V_2 ) ;
V_2 -> V_7 . V_8 -> V_130 &= V_38 ;
V_130 = F_67 ( V_2 -> V_7 . V_8 -> V_130 ) ;
F_68 ( & V_131 -> V_127 -> V_135 ) ;
for ( V_132 = 0 ; V_132 < V_129 ; ++ V_132 )
F_69 ( V_131 , V_130 [ V_132 ] ) ;
F_70 ( & V_131 -> V_127 -> V_135 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 )
{
T_9 V_107 ;
V_107 = V_136 [ V_2 -> V_7 . V_8 -> V_62 & 0x00ff ] ;
if ( V_107 )
return V_107 ( V_2 ) ;
return - V_63 ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_109 = ( V_2 -> V_7 . V_8 -> V_62 & 0x00f0 ) >> 4 ;
int V_137 = V_2 -> V_7 . V_8 -> V_62 & 0x000f ;
int V_138 , V_3 , V_139 ;
T_3 V_140 [ 16 ] ;
T_2 V_22 ;
T_1 V_4 ;
V_2 -> V_17 . V_141 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_73 ( V_2 , & V_4 ) ;
if ( V_22 & 3 )
return F_2 ( V_2 , V_13 ) ;
F_6 ( V_2 , 4 , L_15 , V_109 , V_137 , V_22 ) ;
F_74 ( V_2 , 0 , V_109 , V_137 , V_22 ) ;
V_139 = ( ( V_137 - V_109 ) & 0xf ) + 1 ;
V_3 = F_4 ( V_2 , V_22 , V_4 , V_140 , V_139 * sizeof( T_3 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
V_138 = V_109 ;
V_139 = 0 ;
do {
V_2 -> V_7 . V_8 -> V_46 [ V_138 ] &= 0xffffffff00000000ul ;
V_2 -> V_7 . V_8 -> V_46 [ V_138 ] |= V_140 [ V_139 ++ ] ;
if ( V_138 == V_137 )
break;
V_138 = ( V_138 + 1 ) % 16 ;
} while ( 1 );
F_75 ( V_142 , V_2 ) ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_109 = ( V_2 -> V_7 . V_8 -> V_62 & 0x00f0 ) >> 4 ;
int V_137 = V_2 -> V_7 . V_8 -> V_62 & 0x000f ;
int V_138 , V_3 , V_139 ;
T_3 V_140 [ 16 ] ;
T_2 V_22 ;
T_1 V_4 ;
V_2 -> V_17 . V_143 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_73 ( V_2 , & V_4 ) ;
if ( V_22 & 3 )
return F_2 ( V_2 , V_13 ) ;
F_6 ( V_2 , 4 , L_16 , V_109 , V_137 , V_22 ) ;
F_77 ( V_2 , 0 , V_109 , V_137 , V_22 ) ;
V_138 = V_109 ;
V_139 = 0 ;
do {
V_140 [ V_139 ++ ] = V_2 -> V_7 . V_8 -> V_46 [ V_138 ] ;
if ( V_138 == V_137 )
break;
V_138 = ( V_138 + 1 ) % 16 ;
} while ( 1 );
V_3 = F_15 ( V_2 , V_22 , V_4 , V_140 , V_139 * sizeof( T_3 ) ) ;
return V_3 ? F_5 ( V_2 , V_3 ) : 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_109 = ( V_2 -> V_7 . V_8 -> V_62 & 0x00f0 ) >> 4 ;
int V_137 = V_2 -> V_7 . V_8 -> V_62 & 0x000f ;
int V_138 , V_3 , V_139 ;
T_2 V_140 [ 16 ] ;
T_2 V_22 ;
T_1 V_4 ;
V_2 -> V_17 . V_144 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_79 ( V_2 , & V_4 ) ;
if ( V_22 & 7 )
return F_2 ( V_2 , V_13 ) ;
F_6 ( V_2 , 4 , L_17 , V_109 , V_137 , V_22 ) ;
F_74 ( V_2 , 1 , V_109 , V_137 , V_22 ) ;
V_139 = ( ( V_137 - V_109 ) & 0xf ) + 1 ;
V_3 = F_4 ( V_2 , V_22 , V_4 , V_140 , V_139 * sizeof( T_2 ) ) ;
if ( V_3 )
return F_5 ( V_2 , V_3 ) ;
V_138 = V_109 ;
V_139 = 0 ;
do {
V_2 -> V_7 . V_8 -> V_46 [ V_138 ] = V_140 [ V_139 ++ ] ;
if ( V_138 == V_137 )
break;
V_138 = ( V_138 + 1 ) % 16 ;
} while ( 1 );
F_75 ( V_142 , V_2 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 )
{
int V_109 = ( V_2 -> V_7 . V_8 -> V_62 & 0x00f0 ) >> 4 ;
int V_137 = V_2 -> V_7 . V_8 -> V_62 & 0x000f ;
int V_138 , V_3 , V_139 ;
T_2 V_140 [ 16 ] ;
T_2 V_22 ;
T_1 V_4 ;
V_2 -> V_17 . V_145 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
V_22 = F_79 ( V_2 , & V_4 ) ;
if ( V_22 & 7 )
return F_2 ( V_2 , V_13 ) ;
F_6 ( V_2 , 4 , L_18 , V_109 , V_137 , V_22 ) ;
F_77 ( V_2 , 1 , V_109 , V_137 , V_22 ) ;
V_138 = V_109 ;
V_139 = 0 ;
do {
V_140 [ V_139 ++ ] = V_2 -> V_7 . V_8 -> V_46 [ V_138 ] ;
if ( V_138 == V_137 )
break;
V_138 = ( V_138 + 1 ) % 16 ;
} while ( 1 );
V_3 = F_15 ( V_2 , V_22 , V_4 , V_140 , V_139 * sizeof( T_2 ) ) ;
return V_3 ? F_5 ( V_2 , V_3 ) : 0 ;
}
int F_81 ( struct V_1 * V_2 )
{
T_9 V_107 ;
V_107 = V_146 [ V_2 -> V_7 . V_8 -> V_59 & 0xff ] ;
if ( V_107 )
return V_107 ( V_2 ) ;
return - V_63 ;
}
static int F_82 ( struct V_1 * V_2 )
{
T_2 V_147 , V_148 ;
unsigned long V_149 , V_150 ;
int V_151 = 0 , V_152 = 0 ;
bool V_153 ;
T_1 V_4 ;
V_2 -> V_17 . V_154 ++ ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
F_83 ( V_2 , & V_147 , & V_148 , & V_4 , NULL ) ;
if ( V_148 & 0xf0 )
return - V_63 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_155 )
F_84 ( V_2 ) ;
V_151 = F_85 ( V_2 , V_147 , V_4 , & V_150 , V_156 ) ;
if ( V_151 == V_157 ) {
V_152 = 1 ;
V_151 = F_85 ( V_2 , V_147 , V_4 , & V_150 ,
V_158 ) ;
}
if ( V_151 ) {
if ( V_151 == V_19 || V_151 == V_159 ) {
V_151 = F_2 ( V_2 , V_151 ) ;
} else if ( V_151 > 0 ) {
F_8 ( V_2 , 3 ) ;
V_151 = 0 ;
}
goto V_160;
}
V_149 = F_86 ( V_2 -> V_14 , F_62 ( V_150 ) , & V_153 ) ;
if ( F_63 ( V_149 ) ) {
V_151 = F_2 ( V_2 , V_19 ) ;
} else {
if ( ! V_153 )
V_152 = 1 ;
F_8 ( V_2 , V_152 ) ;
}
V_160:
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_155 )
F_87 ( V_2 ) ;
return V_151 ;
}
int F_88 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_7 . V_8 -> V_62 & 0x00ff ) == 0x01 )
return F_82 ( V_2 ) ;
return - V_63 ;
}
static int F_89 ( struct V_1 * V_2 )
{
T_3 V_161 ;
if ( V_2 -> V_7 . V_8 -> V_9 . V_10 & V_11 )
return F_2 ( V_2 , V_12 ) ;
if ( V_2 -> V_34 -> V_35 . V_36 . V_37 [ 0 ] & 0x00000000ffff0000 )
return F_2 ( V_2 ,
V_13 ) ;
V_161 = V_2 -> V_34 -> V_35 . V_36 . V_37 [ 0 ] & 0x000000000000ffff ;
V_2 -> V_7 . V_8 -> V_162 = V_161 ;
return 0 ;
}
int F_90 ( struct V_1 * V_2 )
{
T_9 V_107 ;
V_107 = V_163 [ V_2 -> V_7 . V_8 -> V_62 & 0x00ff ] ;
if ( V_107 )
return V_107 ( V_2 ) ;
return - V_63 ;
}

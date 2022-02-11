static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 ,
unsigned int V_6 )
{
unsigned long V_7 ;
int V_8 = - V_9 ;
V_2 -> V_10 = V_3 ;
V_2 -> V_11 = V_4 ;
V_2 -> V_12 = V_5 ;
V_2 -> V_13 = V_6 ;
V_5 |= ( V_3 << 20 ) | ( V_4 << 8 ) ;
F_2 ( & V_2 -> V_14 , V_7 ) ;
if ( V_2 -> V_15 . V_16 < V_17 - 1 ) {
unsigned int V_18 = V_2 -> V_19 . V_18 + 1 ;
V_18 %= V_17 ;
V_2 -> V_19 . V_18 = V_18 ;
V_2 -> V_19 . V_20 [ V_18 * 2 ] = F_3 ( V_5 ) ;
V_2 -> V_19 . V_20 [ V_18 * 2 + 1 ] = F_3 ( V_6 ) ;
F_4 ( V_2 , V_21 , V_22 , V_18 ) ;
V_2 -> V_15 . V_16 ++ ;
F_5 () ;
V_8 = 0 ;
}
F_6 ( & V_2 -> V_14 , V_7 ) ;
return V_8 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned int V_23 ,
unsigned int V_24 )
{
F_8 ( V_2 , V_23 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned int V_25 , V_18 ;
T_1 V_23 , V_24 ;
V_18 = F_10 ( V_2 , V_21 , V_26 ) ;
if ( V_18 == V_2 -> V_15 . V_18 )
return;
V_2 -> V_15 . V_18 = V_18 ;
while ( V_2 -> V_15 . V_25 != V_18 ) {
V_2 -> V_15 . V_25 ++ ;
V_2 -> V_15 . V_25 %= V_17 ;
V_25 = V_2 -> V_15 . V_25 << 1 ;
V_24 = F_11 ( V_2 -> V_15 . V_20 [ V_25 + 1 ] ) ;
V_23 = F_11 ( V_2 -> V_15 . V_20 [ V_25 ] ) ;
if ( V_24 & V_27 )
F_7 ( V_2 , V_23 , V_24 ) ;
else if ( V_2 -> V_15 . V_16 ) {
V_2 -> V_23 = V_23 ;
V_2 -> V_24 = V_24 ;
F_5 () ;
V_2 -> V_15 . V_16 -- ;
}
}
}
static int F_12 ( struct V_1 * V_2 , unsigned int * V_28 ,
unsigned int * V_29 )
{
unsigned long V_30 ;
V_31:
V_30 = V_32 + F_13 ( 1000 ) ;
for (; ; ) {
if ( V_2 -> V_33 ) {
F_14 ( & V_2 -> V_14 ) ;
F_9 ( V_2 ) ;
F_15 ( & V_2 -> V_14 ) ;
}
if ( ! V_2 -> V_15 . V_16 ) {
* V_28 = V_2 -> V_23 ;
if ( V_29 )
* V_29 = V_2 -> V_24 ;
F_16 ( L_1 ,
V_2 -> V_23 , V_2 -> V_24 ) ;
if ( V_2 -> V_24 & V_34 ) {
F_17 ( V_2 -> V_35 -> V_36 , L_2
L_3 ,
V_2 -> V_10 ,
V_2 -> V_11 , V_2 -> V_12 ,
V_2 -> V_13 ) ;
return - V_9 ;
}
return 0 ;
}
if ( F_18 ( V_32 , V_30 ) )
break;
F_19 ( 20 ) ;
F_20 () ;
}
F_17 ( V_2 -> V_35 -> V_36 , L_4 ) ;
if ( ! V_2 -> V_33 ) {
F_17 ( V_2 -> V_35 -> V_36 , L_5 ) ;
V_2 -> V_33 = 1 ;
goto V_31;
}
return - V_9 ;
}
int F_21 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_6 )
{
F_16 ( L_6 ,
V_3 , V_4 , V_5 , V_6 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 ,
unsigned int V_5 , unsigned int V_6 ,
unsigned int * V_28 , unsigned int * V_29 )
{
int V_37 ;
F_16 ( L_7 ,
V_3 , V_4 , V_5 , V_6 ) ;
V_37 = F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_12 ( V_2 , V_28 , V_29 ) ;
return V_37 ;
}
int F_23 ( struct V_1 * V_2 )
{
unsigned int V_38 ;
return F_12 ( V_2 , & V_38 , NULL ) ;
}
static T_2 F_24 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
unsigned int V_41 , V_42 , V_43 , V_44 ;
int V_45 = 0 ;
int V_46 ;
V_41 = V_42 = V_43 = V_44 = 0 ;
F_25 ( & V_2 -> V_14 ) ;
for (; ; ) {
unsigned int V_47 , V_48 , V_49 ;
unsigned int V_50 ;
V_47 = F_26 ( V_2 , V_51 , V_52 ) ;
if ( ! V_47 || V_47 == - 1 )
break;
V_48 = F_26 ( V_2 , V_51 , V_53 ) ;
V_49 = F_26 ( V_2 , V_51 , V_54 ) ;
for ( V_46 = 0 ; V_48 && V_46 < V_2 -> V_55 [ V_56 ] . V_57 ; V_46 ++ ) {
if ( ! ( V_48 & ( 1 << V_46 ) ) )
continue;
V_48 &= ~ ( 1 << V_46 ) ;
V_50 = F_27 ( V_2 , V_46 , V_58 ) ;
if ( V_50 & V_59 )
V_43 |= ( 1 << V_46 ) ;
if ( V_50 & V_60 )
V_41 |= ( 1 << V_46 ) ;
F_28 ( V_2 , V_46 , V_58 , V_50 ) ;
}
for ( V_46 = 0 ; V_49 && V_46 < V_2 -> V_55 [ V_61 ] . V_57 ; V_46 ++ ) {
if ( ! ( V_49 & ( 1 << V_46 ) ) )
continue;
V_49 &= ~ ( 1 << V_46 ) ;
V_50 = F_27 ( V_2 , V_46 + V_62 , V_58 ) ;
if ( V_50 & V_59 )
V_44 |= ( 1 << V_46 ) ;
if ( V_50 & V_60 )
V_42 |= ( 1 << V_46 ) ;
F_28 ( V_2 , V_46 + V_62 , V_58 , V_50 ) ;
}
if ( V_47 & V_63 ) {
unsigned char V_64 ;
V_64 = F_29 ( V_2 , V_21 , V_65 ) ;
V_64 &= V_66 ;
if ( V_64 )
F_30 ( V_2 , V_21 , V_65 , V_64 ) ;
V_64 = F_29 ( V_2 , V_21 , V_67 ) ;
V_64 &= V_68 ;
if ( V_64 )
F_30 ( V_2 , V_21 , V_67 , V_64 ) ;
F_9 ( V_2 ) ;
}
if ( V_47 & ( V_69 | V_70 ) ) {
F_31 ( V_2 , V_51 , V_52 ,
( V_47 & ( V_69 | V_70 ) ) ) ;
}
V_45 = 1 ;
}
F_32 ( & V_2 -> V_14 ) ;
F_33 ( V_2 , & V_2 -> V_55 [ V_56 ] , V_41 ) ;
F_33 ( V_2 , & V_2 -> V_55 [ V_61 ] , V_42 ) ;
return F_34 ( V_45 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned int V_71 = F_26 ( V_2 , V_21 , V_72 ) ;
unsigned long V_73 ;
if ( V_71 ) {
F_31 ( V_2 , V_51 , V_74 , 0 ) ;
return 0 ;
}
V_2 -> V_75 = 1 ;
F_31 ( V_2 , V_21 , V_72 , V_76 ) ;
V_73 = V_32 + F_13 ( 200 ) ;
do {
F_36 ( 1 ) ;
V_71 = F_26 ( V_2 , V_21 , V_72 ) ;
if ( V_71 )
break;
} while ( F_37 ( V_32 , V_73 ) );
if ( ! V_71 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_8 ) ;
return - V_9 ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_2 )
{
unsigned int V_28 ;
V_28 = ( 1 << V_2 -> V_55 [ V_61 ] . V_57 ) - 1 ;
F_31 ( V_2 , V_51 , V_77 , V_28 ) ;
V_28 = ( 1 << V_2 -> V_55 [ V_56 ] . V_57 ) - 1 ;
F_31 ( V_2 , V_51 , V_78 , V_28 ) ;
V_28 = V_79 | V_63 | V_69 |
V_70 ;
F_31 ( V_2 , V_51 , V_80 , V_28 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
F_31 ( V_2 , V_51 , V_80 , 0 ) ;
F_31 ( V_2 , V_51 , V_78 , 0 ) ;
F_31 ( V_2 , V_51 , V_77 , 0 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned char V_38 ;
unsigned long V_73 ;
V_37 = F_42 ( V_81 ,
F_43 ( V_2 -> V_82 ) ,
V_83 , & V_2 -> V_84 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_19 . V_85 = V_2 -> V_84 . V_85 ;
V_2 -> V_19 . V_20 = ( T_1 * ) V_2 -> V_84 . V_86 ;
V_2 -> V_15 . V_85 = V_2 -> V_84 . V_85 + 2048 ;
V_2 -> V_15 . V_20 = ( T_1 * ) ( V_2 -> V_84 . V_86 + 2048 ) ;
F_30 ( V_2 , V_21 , V_87 , 0 ) ;
F_30 ( V_2 , V_21 , V_88 , 0 ) ;
V_73 = V_32 + F_13 ( 200 ) ;
do {
if ( ! F_29 ( V_2 , V_21 , V_87 ) &&
! F_29 ( V_2 , V_21 , V_88 ) )
break;
F_36 ( 1 ) ;
} while ( F_37 ( V_32 , V_73 ) );
F_31 ( V_2 , V_21 , V_89 , ( T_1 ) V_2 -> V_19 . V_85 ) ;
F_31 ( V_2 , V_21 , V_90 , F_44 ( V_2 -> V_19 . V_85 ) ) ;
F_30 ( V_2 , V_21 , V_91 , 0x02 ) ;
F_4 ( V_2 , V_21 , V_22 , 0 ) ;
F_4 ( V_2 , V_21 , V_92 , V_93 ) ;
F_30 ( V_2 , V_21 , V_88 , V_94 ) ;
V_38 = F_29 ( V_2 , V_21 , V_67 ) & V_68 ;
if ( V_38 )
F_30 ( V_2 , V_21 , V_67 , V_38 ) ;
V_2 -> V_19 . V_18 = 0 ;
F_31 ( V_2 , V_21 , V_95 , ( T_1 ) V_2 -> V_15 . V_85 ) ;
F_31 ( V_2 , V_21 , V_96 , F_44 ( V_2 -> V_15 . V_85 ) ) ;
F_30 ( V_2 , V_21 , V_97 , 0x02 ) ;
F_4 ( V_2 , V_21 , V_26 , V_93 ) ;
F_4 ( V_2 , V_21 , V_98 , 1 ) ;
F_30 ( V_2 , V_21 , V_87 , V_94 | V_99 ) ;
V_38 = F_29 ( V_2 , V_21 , V_65 ) & V_66 ;
if ( V_38 )
F_30 ( V_2 , V_21 , V_65 , V_38 ) ;
V_2 -> V_15 . V_25 = V_2 -> V_15 . V_16 = 0 ;
return 0 ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_21 , V_87 , 0 ) ;
F_30 ( V_2 , V_21 , V_88 , 0 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_2 , V_2 -> V_100 , true ) ;
F_48 ( V_2 , V_2 -> clock . V_101 ) ;
F_49 ( V_2 ) ;
F_50 ( V_2 , V_56 , false ) ;
F_51 ( V_2 , V_2 -> V_102 , false ) ;
F_50 ( V_2 , V_61 , false ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned int V_28 ;
int V_3 , V_37 ;
V_37 = F_53 ( V_2 , 0 , V_103 , & V_28 ) ;
if ( V_37 < 0 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_9 ) ;
return V_37 ;
}
V_28 >>= 16 ;
if ( V_28 != 0x1369 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_10 , V_28 ) ;
return - V_104 ;
}
V_37 = F_53 ( V_2 , 1 , V_105 , & V_28 ) ;
if ( V_37 < 0 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_11 ) ;
return V_37 ;
}
if ( V_28 != 1 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_12 , V_28 ) ;
return - V_104 ;
}
V_37 = F_53 ( V_2 , 1 , V_106 , & V_28 ) ;
if ( V_37 < 0 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_13 ) ;
return V_37 ;
}
V_2 -> V_107 = V_28 ;
V_2 -> V_108 [ V_56 ] . V_109 = F_54 ( V_2 -> V_107 ) ;
V_2 -> V_108 [ V_61 ] . V_109 = F_55 ( V_2 -> V_107 ) ;
F_56 ( V_2 -> V_35 -> V_36 , L_14 ,
V_2 -> V_107 ,
V_2 -> V_108 [ V_56 ] . V_109 , V_2 -> V_108 [ V_61 ] . V_109 ) ;
if ( V_2 -> V_108 [ V_56 ] . V_109 > V_110 ||
V_2 -> V_108 [ V_61 ] . V_109 > V_110 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_15 , V_28 ) ;
return - V_104 ;
}
V_3 = 0x02 ;
V_37 = F_57 ( V_2 , V_56 , & V_3 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_57 ( V_2 , V_61 , & V_3 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_58 ( V_2 , V_56 , & V_3 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_58 ( V_2 , V_61 , & V_3 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( F_59 ( V_2 -> V_107 ) ) {
V_37 = F_60 ( V_2 , V_3 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 ++ ;
}
if ( F_61 ( V_2 -> V_107 ) ) {
V_37 = F_62 ( V_2 , V_3 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 ++ ;
}
V_37 = F_49 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( ! V_2 -> V_75 ) {
F_46 ( V_2 ) ;
V_2 -> V_75 = 1 ;
} else {
if ( V_2 -> V_100 != V_111 )
F_47 ( V_2 , V_2 -> V_100 , true ) ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_45 ( V_2 ) ;
F_40 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( V_2 -> V_112 )
F_63 ( V_2 ) ;
F_65 ( V_2 ) ;
F_66 ( V_2 ) ;
if ( V_2 -> V_39 >= 0 )
F_67 ( V_2 -> V_39 , ( void * ) V_2 ) ;
if ( V_2 -> V_113 [ 0 ] . V_114 )
F_68 ( V_2 -> V_113 [ 0 ] . V_114 ) ;
if ( V_2 -> V_113 [ 1 ] . V_114 )
F_68 ( V_2 -> V_113 [ 1 ] . V_114 ) ;
if ( V_2 -> V_84 . V_86 )
F_69 ( & V_2 -> V_84 ) ;
F_70 ( V_2 -> V_82 ) ;
F_71 ( V_2 -> V_82 ) ;
F_72 ( V_2 ) ;
}
static int F_73 ( struct V_115 * V_116 )
{
F_64 ( V_116 -> V_117 ) ;
return 0 ;
}
static int F_74 ( struct V_118 * V_35 , struct V_119 * V_82 ,
int V_36 , struct V_1 * * V_120 )
{
struct V_1 * V_2 ;
int V_37 ;
unsigned int V_121 ;
static struct V_122 V_123 = {
. V_124 = F_73 ,
} ;
* V_120 = NULL ;
V_37 = F_75 ( V_82 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 = F_76 ( sizeof( * V_2 ) , V_125 ) ;
if ( ! V_2 ) {
F_71 ( V_82 ) ;
return - V_126 ;
}
F_77 ( & V_2 -> V_14 ) ;
F_78 ( & V_2 -> V_127 ) ;
V_2 -> V_35 = V_35 ;
V_2 -> V_82 = V_82 ;
V_2 -> V_39 = - 1 ;
V_2 -> V_100 = V_100 [ V_36 ] ;
switch ( V_2 -> V_100 ) {
case 8 :
V_2 -> V_128 = 48000 ;
break;
case 16 :
V_2 -> V_128 = 96000 ;
break;
case 32 :
V_2 -> V_128 = 192000 ;
break;
default:
F_17 ( V_2 -> V_35 -> V_36 ,
L_16 ,
V_2 -> V_100 , V_129 ) ;
V_2 -> V_100 = V_129 ;
V_2 -> V_128 = 192000 ;
break;
}
V_2 -> V_130 = V_130 [ V_36 ] ;
if ( V_2 -> V_130 > V_2 -> V_128 ) {
F_17 ( V_2 -> V_35 -> V_36 ,
L_17 ,
V_2 -> V_130 ) ;
V_2 -> V_130 = 16000 ;
}
V_37 = F_79 ( V_82 , V_131 ) ;
if ( V_37 < 0 ) {
F_72 ( V_2 ) ;
F_71 ( V_82 ) ;
return V_37 ;
}
V_2 -> V_113 [ 0 ] . V_85 = F_80 ( V_82 , 0 ) ;
V_2 -> V_113 [ 0 ] . V_114 = F_81 ( V_82 , 0 ) ;
V_2 -> V_113 [ 1 ] . V_85 = F_80 ( V_82 , 2 ) ;
V_2 -> V_113 [ 1 ] . V_114 = F_81 ( V_82 , 2 ) ;
if ( ! V_2 -> V_113 [ 0 ] . V_114 || ! V_2 -> V_113 [ 1 ] . V_114 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_18 ) ;
V_37 = - V_132 ;
goto V_133;
}
F_82 ( V_82 ) ;
V_37 = F_35 ( V_2 ) ;
if ( V_37 < 0 )
goto V_133;
if ( F_83 ( V_82 -> V_39 , F_24 , V_134 ,
V_135 , V_2 ) ) {
F_38 ( V_2 -> V_35 -> V_36 , L_19 , V_82 -> V_39 ) ;
V_37 = - V_136 ;
goto V_133;
}
V_2 -> V_39 = V_82 -> V_39 ;
F_84 ( V_2 -> V_39 ) ;
V_121 = F_26 ( V_2 , V_51 , V_137 ) ;
V_2 -> V_55 [ V_56 ] . V_57 = ( V_121 >> 0 ) & 0x3ff ;
V_2 -> V_55 [ V_61 ] . V_57 = ( V_121 >> 10 ) & 0x3ff ;
V_2 -> V_138 = ( V_121 >> 24 ) & 0xff ;
F_56 ( V_2 -> V_35 -> V_36 , L_20 ,
V_2 -> V_55 [ V_56 ] . V_57 , V_2 -> V_55 [ V_61 ] . V_57 ,
V_2 -> V_138 ) ;
if ( V_2 -> V_55 [ V_56 ] . V_57 > V_62 ||
V_2 -> V_55 [ V_61 ] . V_57 > V_139 ||
( ! V_2 -> V_55 [ V_56 ] . V_57 &&
! V_2 -> V_55 [ V_61 ] . V_57 ) ) {
F_38 ( V_2 -> V_35 -> V_36 , L_21 , V_121 ) ;
V_37 = - V_104 ;
goto V_133;
}
V_37 = F_41 ( V_2 ) ;
if ( V_37 < 0 )
goto V_133;
V_37 = F_85 ( V_35 , V_140 , V_2 , & V_123 ) ;
if ( V_37 < 0 ) {
F_38 ( V_2 -> V_35 -> V_36 , L_22 ) ;
goto V_133;
}
strcpy ( V_35 -> V_141 , L_23 ) ;
F_86 ( V_35 -> V_142 , L_24 , sizeof( V_35 -> V_142 ) ) ;
snprintf ( V_35 -> V_143 , sizeof( V_35 -> V_143 ) ,
L_25 ,
V_35 -> V_142 , V_2 -> V_113 [ 0 ] . V_85 , V_2 -> V_39 ) ;
strcpy ( V_35 -> V_144 , V_35 -> V_142 ) ;
F_39 ( V_2 ) ;
V_2 -> V_112 = 1 ;
* V_120 = V_2 ;
return 0 ;
V_133:
F_64 ( V_2 ) ;
return V_37 ;
}
static int F_87 ( struct V_119 * V_82 ,
const struct V_145 * V_146 )
{
static int V_36 ;
struct V_118 * V_35 ;
struct V_1 * V_2 ;
int V_37 ;
if ( V_36 >= V_147 )
return - V_148 ;
if ( ! V_149 [ V_36 ] ) {
V_36 ++ ;
return - V_150 ;
}
V_37 = F_88 ( & V_82 -> V_36 , V_151 [ V_36 ] , V_152 [ V_36 ] , V_153 ,
0 , & V_35 ) ;
if ( V_37 < 0 ) {
F_38 ( & V_82 -> V_36 , L_26 ) ;
return V_37 ;
}
V_37 = F_74 ( V_35 , V_82 , V_36 , & V_2 ) ;
if ( V_37 < 0 )
goto V_154;
V_35 -> V_155 = V_2 ;
V_37 = F_52 ( V_2 ) ;
if ( V_37 < 0 )
goto V_154;
V_37 = F_89 ( V_2 ) ;
if ( V_37 < 0 )
goto V_154;
V_37 = F_90 ( V_2 ) ;
if ( V_37 < 0 )
goto V_154;
F_91 ( V_2 ) ;
V_37 = F_92 ( V_35 ) ;
if ( V_37 < 0 )
goto V_154;
F_93 ( V_82 , V_35 ) ;
V_36 ++ ;
return V_37 ;
V_154:
F_94 ( V_35 ) ;
return V_37 ;
}
static void F_95 ( struct V_119 * V_82 )
{
F_94 ( F_96 ( V_82 ) ) ;
}

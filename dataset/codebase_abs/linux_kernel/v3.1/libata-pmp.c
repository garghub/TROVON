static unsigned int F_1 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_2 . V_9 ;
struct V_10 V_11 ;
unsigned int V_12 ;
F_2 ( V_8 , & V_11 ) ;
V_11 . V_13 = V_14 ;
V_11 . V_15 = V_16 ;
V_11 . V_17 |= V_18 | V_19 | V_20 ;
V_11 . V_21 = V_3 ;
V_11 . V_9 = V_2 -> V_22 ;
V_12 = F_3 ( V_8 , & V_11 , NULL , V_23 , NULL , 0 ,
V_24 ) ;
if ( V_12 )
return V_12 ;
* V_4 = V_11 . V_25 | V_11 . V_26 << 8 | V_11 . V_27 << 16 | V_11 . V_28 << 24 ;
return 0 ;
}
static unsigned int F_4 ( struct V_1 * V_2 , int V_3 , T_1 V_29 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_2 . V_9 ;
struct V_10 V_11 ;
F_2 ( V_8 , & V_11 ) ;
V_11 . V_13 = V_30 ;
V_11 . V_15 = V_16 ;
V_11 . V_17 |= V_18 | V_19 | V_20 ;
V_11 . V_21 = V_3 ;
V_11 . V_9 = V_2 -> V_22 ;
V_11 . V_25 = V_29 & 0xff ;
V_11 . V_26 = ( V_29 >> 8 ) & 0xff ;
V_11 . V_27 = ( V_29 >> 16 ) & 0xff ;
V_11 . V_28 = ( V_29 >> 24 ) & 0xff ;
return F_3 ( V_8 , & V_11 , NULL , V_23 , NULL , 0 ,
V_24 ) ;
}
int F_5 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_33 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_34 == NULL || V_6 -> V_34 == V_2 ) {
if ( V_6 -> V_35 == 0 || F_6 ( V_2 ) ) {
V_32 -> V_17 |= V_36 ;
return F_7 ( V_32 ) ;
}
V_6 -> V_34 = V_2 ;
}
return V_37 ;
}
int F_8 ( struct V_1 * V_2 , int V_3 , T_1 * V_4 )
{
unsigned int V_12 ;
if ( V_3 > V_38 )
return - V_39 ;
V_12 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_12 ) {
F_9 ( V_2 , L_1 ,
V_3 , V_12 ) ;
return - V_40 ;
}
return 0 ;
}
int F_10 ( struct V_1 * V_2 , int V_3 , T_1 V_29 )
{
unsigned int V_12 ;
if ( V_3 > V_38 )
return - V_39 ;
V_12 = F_4 ( V_2 , V_3 , V_29 ) ;
if ( V_12 ) {
F_9 ( V_2 , L_2 ,
V_3 , V_12 ) ;
return - V_40 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 , enum V_41 V_42 ,
unsigned V_43 )
{
return F_12 ( V_2 , V_42 , true ) ;
}
static int F_13 ( struct V_7 * V_33 , T_1 * V_44 )
{
static const int V_45 [] = { 0 , 1 , 2 , 32 , 33 , 64 , 96 } ;
int V_46 ;
for ( V_46 = 0 ; V_46 < F_14 ( V_45 ) ; V_46 ++ ) {
int V_3 = V_45 [ V_46 ] ;
unsigned int V_12 ;
V_12 = F_1 ( V_33 -> V_2 , V_3 , & V_44 [ V_3 ] ) ;
if ( V_12 ) {
F_15 ( V_33 , L_3 ,
V_3 , V_12 ) ;
return - V_40 ;
}
}
return 0 ;
}
static const char * F_16 ( const T_1 * V_44 )
{
T_1 V_47 = V_44 [ V_48 ] ;
if ( V_47 & ( 1 << 3 ) )
return L_4 ;
if ( V_47 & ( 1 << 2 ) )
return L_5 ;
if ( V_47 & ( 1 << 1 ) )
return L_6 ;
return L_7 ;
}
static int F_17 ( struct V_7 * V_33 , int V_49 )
{
struct V_5 * V_6 = V_33 -> V_2 -> V_6 ;
T_1 * V_44 = V_33 -> V_44 ;
T_2 V_50 = F_18 ( V_44 ) ;
T_2 V_51 = F_19 ( V_44 ) ;
unsigned int V_12 = 0 ;
const char * V_52 ;
int V_53 , V_54 ;
V_53 = F_20 ( V_44 ) ;
if ( V_53 <= 0 || V_53 > V_55 ) {
V_54 = - V_39 ;
V_52 = L_8 ;
goto V_56;
}
if ( ( V_6 -> V_17 & V_57 ) &&
( V_44 [ V_58 ] & V_59 ) )
V_33 -> V_17 |= V_60 ;
V_12 = F_4 ( V_33 -> V_2 , V_61 ,
V_62 ) ;
if ( V_12 ) {
V_54 = - V_40 ;
V_52 = L_9 ;
goto V_56;
}
if ( V_50 == 0x1095 && V_51 == 0x3726 ) {
T_1 V_3 ;
V_12 = F_1 ( & V_6 -> V_2 , V_63 , & V_3 ) ;
if ( V_12 ) {
V_54 = - V_40 ;
V_52 = L_10 ;
goto V_56;
}
V_3 &= ~ 0x1 ;
V_12 = F_4 ( & V_6 -> V_2 , V_63 , V_3 ) ;
if ( V_12 ) {
V_54 = - V_40 ;
V_52 = L_11 ;
goto V_56;
}
}
if ( V_49 ) {
F_21 ( V_33 , L_12
L_13 ,
F_16 ( V_44 ) , V_50 , V_51 ,
F_22 ( V_44 ) ,
V_53 , V_44 [ V_64 ] ,
V_44 [ V_58 ] ) ;
if ( ! ( V_33 -> V_17 & V_60 ) )
F_21 ( V_33 ,
L_14
L_15 ) ;
}
return 0 ;
V_56:
F_15 ( V_33 ,
L_16 ,
V_52 , V_12 ) ;
return V_54 ;
}
static int F_23 ( struct V_5 * V_6 , int V_53 )
{
struct V_1 * V_65 = V_6 -> V_65 ;
int V_46 , V_66 ;
if ( ! V_65 ) {
V_65 = F_24 ( sizeof( V_65 [ 0 ] ) * V_55 ,
V_67 ) ;
if ( ! V_65 )
return - V_68 ;
for ( V_46 = 0 ; V_46 < V_55 ; V_46 ++ )
F_25 ( V_6 , & V_65 [ V_46 ] , V_46 ) ;
V_6 -> V_65 = V_65 ;
for ( V_46 = 0 ; V_46 < V_55 ; V_46 ++ ) {
V_66 = F_26 ( & V_65 [ V_46 ] ) ;
if ( V_66 ) {
goto V_69;
}
}
}
for ( V_46 = 0 ; V_46 < V_53 ; V_46 ++ ) {
struct V_1 * V_2 = & V_65 [ V_46 ] ;
struct V_70 * V_71 = & V_2 -> V_72 ;
V_2 -> V_17 = 0 ;
V_71 -> V_46 . V_73 |= V_74 ;
V_71 -> V_46 . V_75 |= V_76 ;
}
return 0 ;
V_69:
while ( -- V_46 >= 0 )
F_27 ( & V_65 [ V_46 ] ) ;
F_28 ( V_65 ) ;
V_6 -> V_65 = NULL ;
return V_66 ;
}
static void F_29 ( struct V_5 * V_6 )
{
T_1 * V_44 = V_6 -> V_2 . V_9 -> V_44 ;
T_2 V_50 = F_18 ( V_44 ) ;
T_2 V_51 = F_19 ( V_44 ) ;
struct V_1 * V_2 ;
if ( V_50 == 0x1095 && V_51 == 0x3726 ) {
F_30 (link, ap, EDGE) {
V_2 -> V_17 |= V_77 ;
if ( V_2 -> V_22 < 5 )
V_2 -> V_17 |= V_78 |
V_79 ;
if ( V_2 -> V_22 == 5 )
V_2 -> V_17 |= V_78 |
V_80 ;
}
} else if ( V_50 == 0x1095 && V_51 == 0x4723 ) {
F_30 (link, ap, EDGE) {
V_2 -> V_17 |= V_77 ;
if ( V_2 -> V_22 < 2 )
V_2 -> V_17 |= V_79 ;
if ( V_2 -> V_22 == 2 )
V_2 -> V_17 |= V_78 |
V_79 ;
}
} else if ( V_50 == 0x1095 && V_51 == 0x4726 ) {
F_30 (link, ap, EDGE) {
V_2 -> V_17 |= V_77 ;
if ( V_2 -> V_22 <= 5 )
V_2 -> V_17 |= V_78 |
V_79 ;
if ( V_2 -> V_22 == 6 )
V_2 -> V_17 |= V_78 |
V_80 ;
}
} else if ( V_50 == 0x1095 && ( V_51 == 0x5723 || V_51 == 0x5733 ||
V_51 == 0x5734 || V_51 == 0x5744 ) ) {
V_6 -> V_65 [ V_6 -> V_81 - 1 ] . V_17 |= V_82 ;
} else if ( V_50 == 0x197b && V_51 == 0x2352 ) {
F_30 (link, ap, EDGE) {
V_2 -> V_17 |= V_77 |
V_78 |
V_79 ;
}
}
}
int F_31 ( struct V_7 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_17 ;
struct V_1 * V_83 ;
int V_54 ;
if ( ! F_32 ( V_6 ) ) {
F_15 ( V_33 , L_17 ) ;
return - V_39 ;
}
if ( ! F_33 ( V_2 ) ) {
F_15 ( V_33 , L_18 ) ;
return - V_39 ;
}
if ( V_33 -> V_84 ) {
F_15 ( V_33 , L_19 ) ;
return - V_39 ;
}
F_34 ( V_2 -> V_22 != 0 ) ;
V_2 -> V_22 = V_85 ;
V_54 = F_13 ( V_33 , V_33 -> V_44 ) ;
if ( V_54 )
goto V_56;
V_54 = F_17 ( V_33 , 1 ) ;
if ( V_54 )
goto V_56;
V_54 = F_23 ( V_6 , F_20 ( V_33 -> V_44 ) ) ;
if ( V_54 ) {
F_21 ( V_33 , L_20 ) ;
goto V_56;
}
F_35 ( V_6 -> V_86 , V_17 ) ;
F_34 ( V_6 -> V_81 ) ;
V_6 -> V_81 = F_20 ( V_33 -> V_44 ) ;
F_36 ( V_6 -> V_86 , V_17 ) ;
F_29 ( V_6 ) ;
if ( V_6 -> V_87 -> V_88 )
V_6 -> V_87 -> V_88 ( V_6 ) ;
F_30 (tlink, ap, EDGE)
F_37 ( V_83 ) ;
F_38 ( V_6 ) ;
return 0 ;
V_56:
V_2 -> V_22 = 0 ;
return V_54 ;
}
static void F_39 ( struct V_7 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_1 * V_83 ;
unsigned long V_17 ;
F_21 ( V_33 , L_21 ) ;
F_34 ( ! F_33 ( V_2 ) || V_33 -> V_84 ||
V_2 -> V_22 != V_85 ) ;
if ( V_6 -> V_87 -> V_89 )
V_6 -> V_87 -> V_89 ( V_6 ) ;
F_30 (tlink, ap, EDGE)
F_40 ( V_83 -> V_9 ) ;
F_35 ( V_6 -> V_86 , V_17 ) ;
V_6 -> V_81 = 0 ;
V_2 -> V_22 = 0 ;
F_36 ( V_6 -> V_86 , V_17 ) ;
F_38 ( V_6 ) ;
}
static int F_41 ( struct V_7 * V_33 , const T_1 * V_90 )
{
const T_1 * V_91 = V_33 -> V_44 ;
T_2 V_92 , V_93 , V_94 , V_95 ;
int V_96 , V_97 ;
V_92 = F_18 ( V_91 ) ;
V_93 = F_18 ( V_90 ) ;
V_94 = F_19 ( V_91 ) ;
V_95 = F_19 ( V_90 ) ;
V_96 = F_20 ( V_91 ) ;
V_97 = F_20 ( V_90 ) ;
if ( V_92 != V_93 ) {
F_21 ( V_33 ,
L_22 ,
V_92 , V_93 ) ;
return 0 ;
}
if ( V_94 != V_95 ) {
F_21 ( V_33 ,
L_23 ,
V_94 , V_95 ) ;
return 0 ;
}
if ( V_96 != V_97 ) {
F_21 ( V_33 ,
L_24 ,
V_96 , V_97 ) ;
return 0 ;
}
return 1 ;
}
static int F_42 ( struct V_7 * V_33 , unsigned int V_98 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 * V_44 = ( void * ) V_6 -> V_99 ;
int V_54 ;
F_43 ( L_25 ) ;
F_44 ( V_2 , NULL , V_100 ) ;
if ( ! F_45 ( V_33 ) ) {
V_54 = - V_101 ;
goto V_56;
}
if ( F_46 ( V_98 ) && V_98 != V_102 ) {
V_54 = - V_101 ;
goto V_56;
}
V_54 = F_13 ( V_33 , V_44 ) ;
if ( V_54 )
goto V_56;
if ( ! F_41 ( V_33 , V_44 ) ) {
V_54 = - V_101 ;
goto V_56;
}
memcpy ( V_33 -> V_44 , V_44 , sizeof( V_44 [ 0 ] ) * V_103 ) ;
V_54 = F_17 ( V_33 , 0 ) ;
if ( V_54 )
goto V_56;
F_47 ( V_2 , NULL , V_100 ) ;
F_43 ( L_26 ) ;
return 0 ;
V_56:
F_15 ( V_33 , L_27 , V_54 ) ;
F_43 ( L_28 , V_54 ) ;
return V_54 ;
}
static int F_48 ( struct V_7 * V_33 )
{
unsigned int V_12 ;
T_1 V_104 ;
V_12 = F_1 ( V_33 -> V_2 , V_105 , & V_104 ) ;
if ( V_12 ) {
F_15 ( V_33 ,
L_29 ,
V_12 ) ;
return - V_40 ;
}
if ( V_104 != V_33 -> V_44 [ V_105 ] ) {
F_15 ( V_33 , L_30 ) ;
return - V_40 ;
}
return 0 ;
}
static int F_49 ( struct V_5 * V_6 ,
T_3 V_106 , T_4 V_107 ,
T_4 V_108 , T_5 V_109 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_70 * V_71 = & V_2 -> V_72 ;
struct V_7 * V_33 = V_2 -> V_9 ;
int V_110 = V_111 ;
int V_112 = 0 , V_54 = 0 ;
int V_113 = 0 ;
F_43 ( L_25 ) ;
if ( V_33 -> V_17 & V_114 ) {
V_112 = 1 ;
goto V_56;
}
V_115:
V_71 -> V_116 [ 0 ] = V_117 ;
if ( V_71 -> V_46 . V_75 & V_76 ) {
struct V_1 * V_83 ;
V_54 = F_50 ( V_2 , 0 , V_106 , V_107 , V_108 ,
V_109 ) ;
if ( V_54 ) {
F_51 ( V_2 , L_31 ) ;
goto V_56;
}
F_30 (tlink, ap, EDGE) {
struct V_70 * V_71 = & V_83 -> V_72 ;
V_71 -> V_46 . V_73 |= V_74 ;
V_71 -> V_46 . V_75 |= V_76 ;
}
}
if ( V_71 -> V_46 . V_75 & V_100 )
V_54 = F_42 ( V_33 , V_71 -> V_116 [ 0 ] ) ;
else
V_54 = F_48 ( V_33 ) ;
if ( V_54 ) {
V_110 -- ;
if ( V_54 == - V_101 ) {
V_71 -> V_46 . V_73 |= V_74 ;
V_112 = 1 ;
V_110 = F_52 ( V_110 , 2 ) ;
}
if ( V_110 ) {
if ( V_113 )
F_53 ( V_2 , 0 ) ;
else
V_113 = 1 ;
V_71 -> V_46 . V_75 |= V_76 ;
goto V_115;
} else {
F_15 ( V_33 ,
L_32 ,
V_111 ) ;
goto V_56;
}
}
V_71 -> V_46 . V_17 = 0 ;
F_43 ( L_26 ) ;
return 0 ;
V_56:
F_39 ( V_33 ) ;
if ( V_112 )
F_40 ( V_33 ) ;
else
F_54 ( V_33 ) ;
F_43 ( L_28 , V_54 ) ;
return V_54 ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
unsigned long V_17 ;
int V_54 ;
F_35 ( V_6 -> V_86 , V_17 ) ;
F_30 (link, ap, EDGE) {
if ( ! ( V_2 -> V_17 & V_118 ) )
continue;
F_36 ( V_6 -> V_86 , V_17 ) ;
F_56 ( V_2 , V_119 ,
F_57 ( V_120 , V_121 ) ,
NULL , NULL ) ;
V_54 = F_58 ( V_2 , V_122 , V_62 ) ;
if ( V_54 ) {
F_51 ( V_2 ,
L_33 ,
V_54 ) ;
return V_54 ;
}
F_35 ( V_6 -> V_86 , V_17 ) ;
}
F_36 ( V_6 -> V_86 , V_17 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , int * V_123 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_17 ;
if ( V_123 [ V_2 -> V_22 ] && -- V_123 [ V_2 -> V_22 ] )
return 1 ;
if ( ! ( V_2 -> V_17 & V_118 ) ) {
F_9 ( V_2 ,
L_34 ,
V_124 ) ;
F_35 ( V_6 -> V_86 , V_17 ) ;
V_2 -> V_17 |= V_118 ;
F_36 ( V_6 -> V_86 , V_17 ) ;
}
F_54 ( V_2 -> V_9 ) ;
V_2 -> V_72 . V_46 . V_75 = 0 ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_125 * V_87 = V_6 -> V_87 ;
int V_126 , V_123 [ V_55 ] ;
struct V_1 * V_65 = & V_6 -> V_2 ;
struct V_7 * V_8 = V_65 -> V_9 ;
struct V_70 * V_127 = & V_65 -> V_72 ;
T_1 * V_44 = V_8 -> V_44 ;
struct V_1 * V_2 ;
struct V_7 * V_33 ;
unsigned int V_12 ;
T_1 V_128 , V_129 ;
int V_130 , V_54 ;
V_126 = V_111 ;
F_30 (link, ap, EDGE)
V_123 [ V_2 -> V_22 ] = V_124 ;
V_115:
if ( ! F_61 ( V_6 ) ) {
V_54 = F_62 ( V_6 , V_87 -> V_106 , V_87 -> V_107 ,
V_87 -> V_108 , V_87 -> V_109 , NULL ) ;
if ( V_54 ) {
F_63 (dev, &ap->link, ALL)
F_54 ( V_33 ) ;
return V_54 ;
}
if ( V_8 -> V_131 != V_102 )
return 0 ;
F_30 (link, ap, EDGE)
V_123 [ V_2 -> V_22 ] = V_124 ;
}
V_54 = F_49 ( V_6 , V_87 -> V_106 , V_87 -> V_107 ,
V_87 -> V_108 , V_87 -> V_109 ) ;
if ( V_54 )
goto V_132;
if ( V_44 [ V_64 ] & V_59 ) {
V_44 [ V_64 ] &= ~ V_59 ;
V_12 = F_4 ( V_65 , V_64 ,
V_44 [ V_64 ] ) ;
if ( V_12 ) {
F_9 ( V_65 ,
L_35 ,
V_12 ) ;
goto V_132;
}
}
V_54 = F_55 ( V_6 ) ;
if ( V_54 )
goto V_132;
V_54 = F_62 ( V_6 , V_87 -> V_133 , V_87 -> V_134 ,
V_87 -> V_135 , V_87 -> V_136 , & V_2 ) ;
if ( V_54 )
goto V_137;
V_54 = F_64 ( & V_6 -> V_2 , V_138 , & V_129 ) ;
if ( V_54 == 0 )
F_58 ( & V_6 -> V_2 , V_138 , V_129 ) ;
F_30 (link, ap, EDGE)
if ( V_2 -> V_139 > V_140 )
return 0 ;
if ( V_8 -> V_17 & V_60 ) {
V_44 [ V_64 ] |= V_59 ;
V_12 = F_4 ( V_65 , V_64 ,
V_44 [ V_64 ] ) ;
if ( V_12 ) {
F_15 ( V_8 ,
L_36 ,
V_12 ) ;
V_54 = - V_40 ;
goto V_132;
}
}
V_12 = F_1 ( V_65 , V_141 , & V_128 ) ;
if ( V_12 ) {
F_15 ( V_8 ,
L_37 ,
V_12 ) ;
V_54 = - V_40 ;
goto V_132;
}
V_130 = 0 ;
F_30 (link, ap, EDGE) {
if ( ! ( V_128 & ( 1 << V_2 -> V_22 ) ) )
continue;
if ( F_59 ( V_2 , V_123 ) ) {
F_65 ( & V_2 -> V_72 . V_46 ) ;
V_130 ++ ;
} else {
F_9 ( V_2 ,
L_38 ) ;
F_9 ( V_2 ,
L_39 ) ;
}
}
if ( V_130 ) {
F_66 ( V_6 ,
L_40 ) ;
goto V_115;
}
return 0 ;
V_137:
if ( F_59 ( V_2 , V_123 ) ) {
V_127 -> V_46 . V_75 |= V_76 ;
goto V_115;
}
V_132:
if ( V_6 -> V_142 & V_143 )
return V_54 ;
if ( ! F_61 ( V_6 ) )
goto V_115;
if ( -- V_126 ) {
V_127 -> V_46 . V_75 |= V_76 ;
goto V_115;
}
F_67 ( V_6 , L_32 ,
V_111 ) ;
F_39 ( V_8 ) ;
F_54 ( V_8 ) ;
return V_54 ;
}
void F_68 ( struct V_5 * V_6 )
{
F_69 ( V_6 ) ;
F_70 ( V_6 ) ;
F_60 ( V_6 ) ;
F_71 ( V_6 ) ;
}

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
F_9 ( V_2 , V_40 , L_1
L_2 , V_3 , V_12 ) ;
return - V_41 ;
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
F_9 ( V_2 , V_40 , L_3
L_2 , V_3 , V_12 ) ;
return - V_41 ;
}
return 0 ;
}
int F_11 ( struct V_1 * V_2 , enum V_42 V_43 ,
unsigned V_44 )
{
return F_12 ( V_2 , V_43 , true ) ;
}
static int F_13 ( struct V_7 * V_33 , T_1 * V_45 )
{
static const int V_46 [] = { 0 , 1 , 2 , 32 , 33 , 64 , 96 } ;
int V_47 ;
for ( V_47 = 0 ; V_47 < F_14 ( V_46 ) ; V_47 ++ ) {
int V_3 = V_46 [ V_47 ] ;
unsigned int V_12 ;
V_12 = F_1 ( V_33 -> V_2 , V_3 , & V_45 [ V_3 ] ) ;
if ( V_12 ) {
F_15 ( V_33 , V_48 , L_4
L_5 , V_3 , V_12 ) ;
return - V_41 ;
}
}
return 0 ;
}
static const char * F_16 ( const T_1 * V_45 )
{
T_1 V_49 = V_45 [ V_50 ] ;
if ( V_49 & ( 1 << 3 ) )
return L_6 ;
if ( V_49 & ( 1 << 2 ) )
return L_7 ;
if ( V_49 & ( 1 << 1 ) )
return L_8 ;
return L_9 ;
}
static int F_17 ( struct V_7 * V_33 , int V_51 )
{
struct V_5 * V_6 = V_33 -> V_2 -> V_6 ;
T_1 * V_45 = V_33 -> V_45 ;
T_2 V_52 = F_18 ( V_45 ) ;
T_2 V_53 = F_19 ( V_45 ) ;
unsigned int V_12 = 0 ;
const char * V_54 ;
int V_55 , V_56 ;
V_55 = F_20 ( V_45 ) ;
if ( V_55 <= 0 || V_55 > V_57 ) {
V_56 = - V_39 ;
V_54 = L_10 ;
goto V_58;
}
if ( ( V_6 -> V_17 & V_59 ) &&
( V_45 [ V_60 ] & V_61 ) )
V_33 -> V_17 |= V_62 ;
V_12 = F_4 ( V_33 -> V_2 , V_63 ,
V_64 ) ;
if ( V_12 ) {
V_56 = - V_41 ;
V_54 = L_11 ;
goto V_58;
}
if ( V_52 == 0x1095 && V_53 == 0x3726 ) {
T_1 V_3 ;
V_12 = F_1 ( & V_6 -> V_2 , V_65 , & V_3 ) ;
if ( V_12 ) {
V_56 = - V_41 ;
V_54 = L_12 ;
goto V_58;
}
V_3 &= ~ 0x1 ;
V_12 = F_4 ( & V_6 -> V_2 , V_65 , V_3 ) ;
if ( V_12 ) {
V_56 = - V_41 ;
V_54 = L_13 ;
goto V_58;
}
}
if ( V_51 ) {
F_15 ( V_33 , V_66 , L_14
L_15 ,
F_16 ( V_45 ) , V_52 , V_53 ,
F_21 ( V_45 ) ,
V_55 , V_45 [ V_67 ] ,
V_45 [ V_60 ] ) ;
if ( ! ( V_33 -> V_17 & V_62 ) )
F_15 ( V_33 , V_66 ,
L_16
L_17
L_18 ) ;
}
return 0 ;
V_58:
F_15 ( V_33 , V_48 ,
L_19 ,
V_54 , V_12 ) ;
return V_56 ;
}
static int F_22 ( struct V_5 * V_6 , int V_55 )
{
struct V_1 * V_68 = V_6 -> V_68 ;
int V_47 , V_69 ;
if ( ! V_68 ) {
V_68 = F_23 ( sizeof( V_68 [ 0 ] ) * V_57 ,
V_70 ) ;
if ( ! V_68 )
return - V_71 ;
for ( V_47 = 0 ; V_47 < V_57 ; V_47 ++ )
F_24 ( V_6 , & V_68 [ V_47 ] , V_47 ) ;
V_6 -> V_68 = V_68 ;
for ( V_47 = 0 ; V_47 < V_57 ; V_47 ++ ) {
V_69 = F_25 ( & V_68 [ V_47 ] ) ;
if ( V_69 ) {
goto V_72;
}
}
}
for ( V_47 = 0 ; V_47 < V_55 ; V_47 ++ ) {
struct V_1 * V_2 = & V_68 [ V_47 ] ;
struct V_73 * V_74 = & V_2 -> V_75 ;
V_2 -> V_17 = 0 ;
V_74 -> V_47 . V_76 |= V_77 ;
V_74 -> V_47 . V_78 |= V_79 ;
}
return 0 ;
V_72:
while ( -- V_47 >= 0 )
F_26 ( & V_68 [ V_47 ] ) ;
F_27 ( V_68 ) ;
V_6 -> V_68 = NULL ;
return V_69 ;
}
static void F_28 ( struct V_5 * V_6 )
{
T_1 * V_45 = V_6 -> V_2 . V_9 -> V_45 ;
T_2 V_52 = F_18 ( V_45 ) ;
T_2 V_53 = F_19 ( V_45 ) ;
struct V_1 * V_2 ;
if ( V_52 == 0x1095 && V_53 == 0x3726 ) {
F_29 (link, ap, EDGE) {
V_2 -> V_17 |= V_80 ;
if ( V_2 -> V_22 < 5 )
V_2 -> V_17 |= V_81 |
V_82 ;
if ( V_2 -> V_22 == 5 )
V_2 -> V_17 |= V_81 |
V_83 ;
}
} else if ( V_52 == 0x1095 && V_53 == 0x4723 ) {
F_29 (link, ap, EDGE) {
V_2 -> V_17 |= V_80 ;
if ( V_2 -> V_22 < 2 )
V_2 -> V_17 |= V_82 ;
if ( V_2 -> V_22 == 2 )
V_2 -> V_17 |= V_81 |
V_82 ;
}
} else if ( V_52 == 0x1095 && V_53 == 0x4726 ) {
F_29 (link, ap, EDGE) {
V_2 -> V_17 |= V_80 ;
if ( V_2 -> V_22 <= 5 )
V_2 -> V_17 |= V_81 |
V_82 ;
if ( V_2 -> V_22 == 6 )
V_2 -> V_17 |= V_81 |
V_83 ;
}
} else if ( V_52 == 0x1095 && ( V_53 == 0x5723 || V_53 == 0x5733 ||
V_53 == 0x5734 || V_53 == 0x5744 ) ) {
V_6 -> V_68 [ V_6 -> V_84 - 1 ] . V_17 |= V_85 ;
} else if ( V_52 == 0x197b && V_53 == 0x2352 ) {
F_29 (link, ap, EDGE) {
V_2 -> V_17 |= V_80 |
V_81 |
V_82 ;
}
}
}
int F_30 ( struct V_7 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_17 ;
struct V_1 * V_86 ;
int V_56 ;
if ( ! F_31 ( V_6 ) ) {
F_15 ( V_33 , V_48 ,
L_20 ) ;
return - V_39 ;
}
if ( ! F_32 ( V_2 ) ) {
F_15 ( V_33 , V_48 ,
L_21 ) ;
return - V_39 ;
}
if ( V_33 -> V_87 ) {
F_15 ( V_33 , V_48 ,
L_22 ) ;
return - V_39 ;
}
F_33 ( V_2 -> V_22 != 0 ) ;
V_2 -> V_22 = V_88 ;
V_56 = F_13 ( V_33 , V_33 -> V_45 ) ;
if ( V_56 )
goto V_58;
V_56 = F_17 ( V_33 , 1 ) ;
if ( V_56 )
goto V_58;
V_56 = F_22 ( V_6 , F_20 ( V_33 -> V_45 ) ) ;
if ( V_56 ) {
F_15 ( V_33 , V_66 ,
L_23 ) ;
goto V_58;
}
F_34 ( V_6 -> V_89 , V_17 ) ;
F_33 ( V_6 -> V_84 ) ;
V_6 -> V_84 = F_20 ( V_33 -> V_45 ) ;
F_35 ( V_6 -> V_89 , V_17 ) ;
F_28 ( V_6 ) ;
if ( V_6 -> V_90 -> V_91 )
V_6 -> V_90 -> V_91 ( V_6 ) ;
F_29 (tlink, ap, EDGE)
F_36 ( V_86 ) ;
F_37 ( V_6 ) ;
return 0 ;
V_58:
V_2 -> V_22 = 0 ;
return V_56 ;
}
static void F_38 ( struct V_7 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_1 * V_86 ;
unsigned long V_17 ;
F_15 ( V_33 , V_66 , L_24 ) ;
F_33 ( ! F_32 ( V_2 ) || V_33 -> V_87 ||
V_2 -> V_22 != V_88 ) ;
if ( V_6 -> V_90 -> V_92 )
V_6 -> V_90 -> V_92 ( V_6 ) ;
F_29 (tlink, ap, EDGE)
F_39 ( V_86 -> V_9 ) ;
F_34 ( V_6 -> V_89 , V_17 ) ;
V_6 -> V_84 = 0 ;
V_2 -> V_22 = 0 ;
F_35 ( V_6 -> V_89 , V_17 ) ;
F_37 ( V_6 ) ;
}
static int F_40 ( struct V_7 * V_33 , const T_1 * V_93 )
{
const T_1 * V_94 = V_33 -> V_45 ;
T_2 V_95 , V_96 , V_97 , V_98 ;
int V_99 , V_100 ;
V_95 = F_18 ( V_94 ) ;
V_96 = F_18 ( V_93 ) ;
V_97 = F_19 ( V_94 ) ;
V_98 = F_19 ( V_93 ) ;
V_99 = F_20 ( V_94 ) ;
V_100 = F_20 ( V_93 ) ;
if ( V_95 != V_96 ) {
F_15 ( V_33 , V_66 , L_25
L_26 ,
V_95 , V_96 ) ;
return 0 ;
}
if ( V_97 != V_98 ) {
F_15 ( V_33 , V_66 , L_25
L_27 ,
V_97 , V_98 ) ;
return 0 ;
}
if ( V_99 != V_100 ) {
F_15 ( V_33 , V_66 , L_25
L_28 ,
V_99 , V_100 ) ;
return 0 ;
}
return 1 ;
}
static int F_41 ( struct V_7 * V_33 , unsigned int V_101 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 * V_45 = ( void * ) V_6 -> V_102 ;
int V_56 ;
F_42 ( L_29 ) ;
F_43 ( V_2 , NULL , V_103 ) ;
if ( ! F_44 ( V_33 ) ) {
V_56 = - V_104 ;
goto V_58;
}
if ( F_45 ( V_101 ) && V_101 != V_105 ) {
V_56 = - V_104 ;
goto V_58;
}
V_56 = F_13 ( V_33 , V_45 ) ;
if ( V_56 )
goto V_58;
if ( ! F_40 ( V_33 , V_45 ) ) {
V_56 = - V_104 ;
goto V_58;
}
memcpy ( V_33 -> V_45 , V_45 , sizeof( V_45 [ 0 ] ) * V_106 ) ;
V_56 = F_17 ( V_33 , 0 ) ;
if ( V_56 )
goto V_58;
F_46 ( V_2 , NULL , V_103 ) ;
F_42 ( L_30 ) ;
return 0 ;
V_58:
F_15 ( V_33 , V_48 ,
L_31 , V_56 ) ;
F_42 ( L_32 , V_56 ) ;
return V_56 ;
}
static int F_47 ( struct V_7 * V_33 )
{
unsigned int V_12 ;
T_1 V_107 ;
V_12 = F_1 ( V_33 -> V_2 , V_108 , & V_107 ) ;
if ( V_12 ) {
F_15 ( V_33 , V_48 , L_33
L_2 , V_12 ) ;
return - V_41 ;
}
if ( V_107 != V_33 -> V_45 [ V_108 ] ) {
F_15 ( V_33 , V_48 , L_34 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_48 ( struct V_5 * V_6 ,
T_3 V_109 , T_4 V_110 ,
T_4 V_111 , T_5 V_112 )
{
struct V_1 * V_2 = & V_6 -> V_2 ;
struct V_73 * V_74 = & V_2 -> V_75 ;
struct V_7 * V_33 = V_2 -> V_9 ;
int V_113 = V_114 ;
int V_115 = 0 , V_56 = 0 ;
int V_116 = 0 ;
F_42 ( L_29 ) ;
if ( V_33 -> V_17 & V_117 ) {
V_115 = 1 ;
goto V_58;
}
V_118:
V_74 -> V_119 [ 0 ] = V_120 ;
if ( V_74 -> V_47 . V_78 & V_79 ) {
struct V_1 * V_86 ;
V_56 = F_49 ( V_2 , 0 , V_109 , V_110 , V_111 ,
V_112 ) ;
if ( V_56 ) {
F_9 ( V_2 , V_48 ,
L_35 ) ;
goto V_58;
}
F_29 (tlink, ap, EDGE) {
struct V_73 * V_74 = & V_86 -> V_75 ;
V_74 -> V_47 . V_76 |= V_77 ;
V_74 -> V_47 . V_78 |= V_79 ;
}
}
if ( V_74 -> V_47 . V_78 & V_103 )
V_56 = F_41 ( V_33 , V_74 -> V_119 [ 0 ] ) ;
else
V_56 = F_47 ( V_33 ) ;
if ( V_56 ) {
V_113 -- ;
if ( V_56 == - V_104 ) {
V_74 -> V_47 . V_76 |= V_77 ;
V_115 = 1 ;
V_113 = F_50 ( V_113 , 2 ) ;
}
if ( V_113 ) {
if ( V_116 )
F_51 ( V_2 , 0 ) ;
else
V_116 = 1 ;
V_74 -> V_47 . V_78 |= V_79 ;
goto V_118;
} else {
F_15 ( V_33 , V_48 , L_36
L_37 ,
V_114 ) ;
goto V_58;
}
}
V_74 -> V_47 . V_17 = 0 ;
F_42 ( L_30 ) ;
return 0 ;
V_58:
F_38 ( V_33 ) ;
if ( V_115 )
F_39 ( V_33 ) ;
else
F_52 ( V_33 ) ;
F_42 ( L_32 , V_56 ) ;
return V_56 ;
}
static int F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
unsigned long V_17 ;
int V_56 ;
F_34 ( V_6 -> V_89 , V_17 ) ;
F_29 (link, ap, EDGE) {
if ( ! ( V_2 -> V_17 & V_121 ) )
continue;
F_35 ( V_6 -> V_89 , V_17 ) ;
F_54 ( V_2 , V_122 ,
F_55 ( V_123 , V_124 ) ,
NULL , NULL ) ;
V_56 = F_56 ( V_2 , V_125 , V_64 ) ;
if ( V_56 ) {
F_9 ( V_2 , V_48 , L_38
L_39 , V_56 ) ;
return V_56 ;
}
F_34 ( V_6 -> V_89 , V_17 ) ;
}
F_35 ( V_6 -> V_89 , V_17 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , int * V_126 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
unsigned long V_17 ;
if ( V_126 [ V_2 -> V_22 ] && -- V_126 [ V_2 -> V_22 ] )
return 1 ;
if ( ! ( V_2 -> V_17 & V_121 ) ) {
F_9 ( V_2 , V_40 ,
L_40 ,
V_127 ) ;
F_34 ( V_6 -> V_89 , V_17 ) ;
V_2 -> V_17 |= V_121 ;
F_35 ( V_6 -> V_89 , V_17 ) ;
}
F_52 ( V_2 -> V_9 ) ;
V_2 -> V_75 . V_47 . V_78 = 0 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_128 * V_90 = V_6 -> V_90 ;
int V_129 , V_126 [ V_57 ] ;
struct V_1 * V_68 = & V_6 -> V_2 ;
struct V_7 * V_8 = V_68 -> V_9 ;
struct V_73 * V_130 = & V_68 -> V_75 ;
T_1 * V_45 = V_8 -> V_45 ;
struct V_1 * V_2 ;
struct V_7 * V_33 ;
unsigned int V_12 ;
T_1 V_131 , V_132 ;
int V_133 , V_56 ;
V_129 = V_114 ;
F_29 (link, ap, EDGE)
V_126 [ V_2 -> V_22 ] = V_127 ;
V_118:
if ( ! F_59 ( V_6 ) ) {
V_56 = F_60 ( V_6 , V_90 -> V_109 , V_90 -> V_110 ,
V_90 -> V_111 , V_90 -> V_112 , NULL ) ;
if ( V_56 ) {
F_61 (dev, &ap->link, ALL)
F_52 ( V_33 ) ;
return V_56 ;
}
if ( V_8 -> V_134 != V_105 )
return 0 ;
F_29 (link, ap, EDGE)
V_126 [ V_2 -> V_22 ] = V_127 ;
}
V_56 = F_48 ( V_6 , V_90 -> V_109 , V_90 -> V_110 ,
V_90 -> V_111 , V_90 -> V_112 ) ;
if ( V_56 )
goto V_135;
if ( V_45 [ V_67 ] & V_61 ) {
V_45 [ V_67 ] &= ~ V_61 ;
V_12 = F_4 ( V_68 , V_67 ,
V_45 [ V_67 ] ) ;
if ( V_12 ) {
F_9 ( V_68 , V_40 ,
L_41 ,
V_12 ) ;
goto V_135;
}
}
V_56 = F_53 ( V_6 ) ;
if ( V_56 )
goto V_135;
V_56 = F_60 ( V_6 , V_90 -> V_136 , V_90 -> V_137 ,
V_90 -> V_138 , V_90 -> V_139 , & V_2 ) ;
if ( V_56 )
goto V_140;
V_56 = F_62 ( & V_6 -> V_2 , V_141 , & V_132 ) ;
if ( V_56 == 0 )
F_56 ( & V_6 -> V_2 , V_141 , V_132 ) ;
F_29 (link, ap, EDGE)
if ( V_2 -> V_142 > V_143 )
return 0 ;
if ( V_8 -> V_17 & V_62 ) {
V_45 [ V_67 ] |= V_61 ;
V_12 = F_4 ( V_68 , V_67 ,
V_45 [ V_67 ] ) ;
if ( V_12 ) {
F_15 ( V_8 , V_48 , L_42
L_43 , V_12 ) ;
V_56 = - V_41 ;
goto V_135;
}
}
V_12 = F_1 ( V_68 , V_144 , & V_131 ) ;
if ( V_12 ) {
F_15 ( V_8 , V_48 , L_44
L_45 , V_12 ) ;
V_56 = - V_41 ;
goto V_135;
}
V_133 = 0 ;
F_29 (link, ap, EDGE) {
if ( ! ( V_131 & ( 1 << V_2 -> V_22 ) ) )
continue;
if ( F_57 ( V_2 , V_126 ) ) {
F_63 ( & V_2 -> V_75 . V_47 ) ;
V_133 ++ ;
} else {
F_9 ( V_2 , V_40 ,
L_46
L_47 ) ;
F_9 ( V_2 , V_40 ,
L_48 ) ;
}
}
if ( V_133 ) {
F_64 ( V_6 , V_66 , L_49
L_50 ) ;
goto V_118;
}
return 0 ;
V_140:
if ( F_57 ( V_2 , V_126 ) ) {
V_130 -> V_47 . V_78 |= V_79 ;
goto V_118;
}
V_135:
if ( V_6 -> V_145 & V_146 )
return V_56 ;
if ( ! F_59 ( V_6 ) )
goto V_118;
if ( -- V_129 ) {
V_130 -> V_47 . V_78 |= V_79 ;
goto V_118;
}
F_64 ( V_6 , V_48 ,
L_51 ,
V_114 ) ;
F_38 ( V_8 ) ;
F_52 ( V_8 ) ;
return V_56 ;
}
void F_65 ( struct V_5 * V_6 )
{
F_66 ( V_6 ) ;
F_67 ( V_6 ) ;
F_58 ( V_6 ) ;
F_68 ( V_6 ) ;
}

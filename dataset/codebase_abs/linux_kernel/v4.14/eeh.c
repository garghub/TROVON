static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) )
F_2 ( V_2 ) ;
else if ( ! strcmp ( V_1 , L_2 ) )
F_2 ( V_3 ) ;
return 1 ;
}
static T_2 F_3 ( struct V_4 * V_5 , char * V_6 , T_2 V_7 )
{
struct V_8 * V_9 = F_4 ( V_5 ) ;
T_3 V_10 ;
int V_11 , V_12 ;
int V_13 = 0 , V_14 = 0 ;
char V_15 [ 128 ] ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_3 ,
V_9 -> V_16 -> V_17 , V_9 -> V_18 ,
F_6 ( V_9 -> V_19 ) , F_7 ( V_9 -> V_19 ) ) ;
F_8 ( L_4 ,
V_9 -> V_16 -> V_17 , V_9 -> V_18 ,
F_6 ( V_9 -> V_19 ) , F_7 ( V_9 -> V_19 ) ) ;
V_20 -> V_21 ( V_9 , V_22 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_5 , V_10 ) ;
F_8 ( L_6 , V_10 ) ;
V_20 -> V_21 ( V_9 , V_23 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_7 , V_10 ) ;
F_8 ( L_8 , V_10 ) ;
if ( V_5 -> V_24 & V_25 ) {
V_20 -> V_21 ( V_9 , V_26 , 2 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_9 , V_10 ) ;
F_8 ( L_10 , V_10 ) ;
V_20 -> V_21 ( V_9 , V_27 , 2 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_11 , V_10 ) ;
F_8 ( L_12 , V_10 ) ;
}
V_11 = V_5 -> V_28 ;
if ( V_11 ) {
V_20 -> V_21 ( V_9 , V_11 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_13 , V_10 ) ;
F_8 ( L_14 , V_10 ) ;
V_20 -> V_21 ( V_9 , V_11 + 4 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_15 , V_10 ) ;
F_8 ( L_16 , V_10 ) ;
}
V_11 = V_5 -> V_29 ;
if ( V_11 ) {
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_17 ) ;
F_8 ( L_18 ) ;
for ( V_12 = 0 ; V_12 <= 8 ; V_12 ++ ) {
V_20 -> V_21 ( V_9 , V_11 + 4 * V_12 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_19 , 4 * V_12 , V_10 ) ;
if ( ( V_12 % 4 ) == 0 ) {
if ( V_12 != 0 )
F_8 ( L_20 , V_15 ) ;
V_14 = F_5 ( V_15 , sizeof( V_15 ) ,
L_21 ,
4 * V_12 , V_10 ) ;
} else {
V_14 += F_5 ( V_15 + V_14 , sizeof( V_15 ) - V_14 ,
L_22 , V_10 ) ;
}
}
F_8 ( L_20 , V_15 ) ;
}
V_11 = V_5 -> V_30 ;
if ( V_11 ) {
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_23 ) ;
F_8 ( L_24 ) ;
for ( V_12 = 0 ; V_12 <= 13 ; V_12 ++ ) {
V_20 -> V_21 ( V_9 , V_11 + 4 * V_12 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_19 , 4 * V_12 , V_10 ) ;
if ( ( V_12 % 4 ) == 0 ) {
if ( V_12 != 0 )
F_8 ( L_20 , V_15 ) ;
V_14 = F_5 ( V_15 , sizeof( V_15 ) ,
L_25 ,
4 * V_12 , V_10 ) ;
} else {
V_14 += F_5 ( V_15 + V_14 , sizeof( V_15 ) - V_14 ,
L_22 , V_10 ) ;
}
}
F_8 ( L_20 , V_15 ) ;
}
return V_13 ;
}
static void * F_9 ( void * V_31 , void * V_32 )
{
struct V_33 * V_34 = V_31 ;
struct V_4 * V_5 , * V_35 ;
T_2 * V_36 = V_32 ;
F_10 ( V_34 , V_5 , V_35 )
* V_36 += F_3 ( V_5 , V_37 + * V_36 ,
V_38 - * V_36 ) ;
return NULL ;
}
void F_11 ( struct V_33 * V_34 , int V_39 )
{
T_2 V_40 = 0 ;
if ( ! ( V_34 -> type & V_41 ) ) {
if ( F_12 ( V_42 ) ||
V_39 == V_43 )
F_13 ( V_34 , V_44 ) ;
V_20 -> V_45 ( V_34 ) ;
if ( ! ( V_34 -> V_46 & V_47 ) ) {
F_14 ( V_34 ) ;
V_37 [ 0 ] = 0 ;
F_15 ( V_34 , F_9 , & V_40 ) ;
}
}
V_20 -> V_48 ( V_34 , V_39 , V_37 , V_40 ) ;
}
static inline unsigned long F_16 ( unsigned long V_49 )
{
T_4 * V_50 ;
unsigned long V_51 ;
int V_52 ;
V_50 = F_17 ( V_49 , & V_52 ) ;
if ( ! V_50 )
return V_49 ;
F_18 ( V_52 ) ;
V_51 = F_19 ( * V_50 ) << V_53 ;
return V_51 | ( V_49 & ( V_54 - 1 ) ) ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_33 * V_55 ;
unsigned long V_56 ;
int V_57 ;
if ( ! F_12 ( V_58 ) )
return - V_59 ;
V_55 = F_21 ( V_34 -> V_16 ) ;
if ( ! V_55 ) {
F_8 ( L_26 ,
V_60 , V_34 -> V_16 -> V_17 ) ;
return - V_61 ;
}
F_22 ( & V_56 ) ;
if ( V_55 -> V_46 & V_62 ) {
V_57 = 0 ;
goto V_63;
}
V_57 = V_20 -> V_64 ( V_55 , NULL ) ;
if ( ( V_57 < 0 ) ||
( V_57 == V_65 ) ||
( V_57 & ( V_66 | V_67 ) ) ==
( V_66 | V_67 ) ) {
V_57 = 0 ;
goto V_63;
}
F_23 ( V_55 , V_62 ) ;
F_24 ( V_56 ) ;
F_25 ( L_27 ,
V_55 -> V_16 -> V_17 , F_26 ( V_55 ) ) ;
F_27 () ;
F_28 ( V_55 ) ;
return 1 ;
V_63:
F_24 ( V_56 ) ;
return V_57 ;
}
int F_29 ( struct V_4 * V_5 )
{
int V_57 ;
int V_68 = ( V_66 | V_67 ) ;
unsigned long V_56 ;
struct V_69 * V_70 ;
struct V_71 * V_72 ;
struct V_33 * V_34 , * V_73 , * V_55 ;
int V_74 = 0 ;
const char * V_75 = NULL ;
V_76 . V_77 ++ ;
if ( ! F_30 () )
return 0 ;
if ( ! V_5 ) {
V_76 . V_78 ++ ;
return 0 ;
}
V_72 = F_31 ( V_5 ) ;
V_34 = F_32 ( V_5 ) ;
if ( ! V_34 ) {
V_76 . V_79 ++ ;
F_33 ( L_28 ,
F_34 ( V_72 ) ) ;
return 0 ;
}
if ( ! V_34 -> V_80 && ! V_34 -> V_81 ) {
V_76 . V_82 ++ ;
return 0 ;
}
V_57 = F_20 ( V_34 ) ;
if ( V_57 > 0 )
return V_57 ;
if ( F_35 ( V_34 ) )
return 0 ;
F_22 ( & V_56 ) ;
V_74 = 1 ;
if ( V_34 -> V_46 & V_62 ) {
V_34 -> V_83 ++ ;
if ( V_34 -> V_83 % V_84 == 0 ) {
V_70 = F_36 ( V_72 ) ;
if ( V_70 )
V_75 = F_37 ( V_70 , L_29 ,
NULL ) ;
F_38 ( V_85 L_30
L_31 ,
V_34 -> V_83 ,
V_75 ? V_75 : L_32 ,
F_39 ( V_72 ) , F_34 ( V_72 ) ) ;
F_38 ( V_85 L_33 ,
F_39 ( V_72 ) ) ;
F_27 () ;
}
goto V_86;
}
V_57 = V_20 -> V_64 ( V_34 , NULL ) ;
if ( ( V_57 < 0 ) ||
( V_57 == V_65 ) ||
( ( V_57 & V_68 ) == V_68 ) ) {
V_76 . V_87 ++ ;
V_34 -> V_87 ++ ;
V_74 = 0 ;
goto V_86;
}
V_73 = V_34 -> V_88 ;
while ( V_73 ) {
if ( V_73 -> type & V_41 )
break;
V_57 = V_20 -> V_64 ( V_73 , NULL ) ;
if ( V_57 > 0 &&
( V_57 & V_68 ) != V_68 )
V_34 = V_73 ;
V_73 = V_73 -> V_88 ;
}
V_76 . V_89 ++ ;
F_23 ( V_34 , V_62 ) ;
F_24 ( V_56 ) ;
V_55 = F_21 ( V_34 -> V_16 ) ;
F_25 ( L_34 ,
V_34 -> V_16 -> V_17 , V_34 -> V_80 ) ;
F_25 ( L_35 ,
F_26 ( V_34 ) , F_26 ( V_55 ) ) ;
F_27 () ;
F_28 ( V_34 ) ;
return 1 ;
V_86:
F_24 ( V_56 ) ;
return V_74 ;
}
int F_40 ( const volatile void T_5 * V_49 )
{
unsigned long V_80 ;
struct V_4 * V_5 ;
V_80 = F_16 ( ( unsigned long V_90 ) V_49 ) ;
V_5 = F_41 ( V_80 ) ;
if ( ! V_5 ) {
V_76 . V_91 ++ ;
return 0 ;
}
return F_29 ( V_5 ) ;
}
int F_13 ( struct V_33 * V_34 , int V_92 )
{
int V_93 , V_74 ;
switch ( V_92 ) {
case V_44 :
V_93 = V_66 | V_94 ;
break;
case V_95 :
V_93 = V_67 ;
break;
case V_96 :
case V_97 :
case V_98 :
V_93 = 0 ;
break;
default:
F_8 ( L_36 ,
V_60 , V_92 ) ;
return - V_99 ;
}
if ( V_93 ) {
V_74 = V_20 -> V_64 ( V_34 , NULL ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_74 == V_65 )
return 0 ;
if ( V_74 & V_93 )
return 0 ;
}
V_74 = V_20 -> V_100 ( V_34 , V_92 ) ;
if ( V_74 )
F_8 ( L_37
L_38 ,
V_60 , V_92 , V_34 -> V_16 -> V_17 ,
V_34 -> V_80 , V_74 ) ;
if ( V_93 ) {
V_74 = V_20 -> V_101 ( V_34 , V_102 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_74 & V_93 )
return 0 ;
return - V_103 ;
}
return V_74 ;
}
static void * F_42 ( void * V_31 , void * V_104 )
{
struct V_4 * V_5 = V_31 ;
struct V_71 * V_105 = F_31 ( V_5 ) ;
struct V_71 * V_72 = V_104 ;
if ( ! V_105 || V_105 == V_72 )
return NULL ;
F_43 ( V_105 , V_106 ) ;
F_44 ( V_105 ) ;
F_45 ( V_105 , V_23 , V_107 ) ;
return NULL ;
}
static void * F_46 ( void * V_31 , void * V_104 )
{
struct V_4 * V_5 = V_31 ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_71 * V_105 = F_31 ( V_5 ) ;
struct V_71 * V_72 = V_104 ;
if ( ! V_105 )
return NULL ;
if ( V_9 && V_20 -> V_108 )
V_20 -> V_108 ( V_9 ) ;
if ( V_105 != V_72 )
F_47 ( V_105 ) ;
return NULL ;
}
int F_48 ( struct V_71 * V_72 , enum V_109 V_46 )
{
struct V_4 * V_5 = F_49 ( V_72 ) ;
struct V_33 * V_34 = F_32 ( V_5 ) ;
if ( ! V_34 ) {
F_25 ( L_39 ,
V_60 , F_50 ( V_72 ) ) ;
return - V_99 ;
}
switch ( V_46 ) {
case V_110 :
V_20 -> V_111 ( V_34 , V_112 ) ;
F_51 ( V_34 , false ) ;
if ( ! ( V_34 -> type & V_113 ) )
F_52 ( V_34 , V_47 ) ;
F_53 ( V_34 , F_46 , V_72 ) ;
F_52 ( V_34 , V_62 ) ;
break;
case V_114 :
F_54 ( V_34 , V_62 ) ;
V_20 -> V_100 ( V_34 , V_98 ) ;
F_53 ( V_34 , F_42 , V_72 ) ;
if ( ! ( V_34 -> type & V_113 ) )
F_23 ( V_34 , V_47 ) ;
V_20 -> V_111 ( V_34 , V_115 ) ;
break;
case V_116 :
F_54 ( V_34 , V_62 ) ;
V_20 -> V_100 ( V_34 , V_98 ) ;
F_53 ( V_34 , F_42 , V_72 ) ;
if ( ! ( V_34 -> type & V_113 ) )
F_23 ( V_34 , V_47 ) ;
V_20 -> V_111 ( V_34 , V_117 ) ;
break;
default:
F_52 ( V_34 , V_62 | V_47 ) ;
return - V_99 ;
} ;
return 0 ;
}
static void * F_55 ( void * V_31 , void * V_32 )
{
struct V_71 * V_72 ;
unsigned int * V_118 = ( unsigned int * ) V_32 ;
struct V_4 * V_5 = (struct V_4 * ) V_31 ;
V_72 = F_31 ( V_5 ) ;
if ( V_72 )
* V_118 |= V_72 -> V_119 ;
return NULL ;
}
int F_56 ( struct V_33 * V_34 )
{
int V_68 = ( V_66 | V_67 ) ;
int V_120 = ( V_121 | V_47 ) ;
int type = V_115 ;
unsigned int V_118 = 0 ;
int V_12 , V_46 , V_57 ;
F_53 ( V_34 , F_55 , & V_118 ) ;
if ( V_118 )
type = V_117 ;
F_23 ( V_34 , V_120 ) ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_57 = F_57 ( V_34 , type ) ;
if ( V_57 )
break;
V_57 = F_57 ( V_34 , V_112 ) ;
if ( V_57 )
break;
V_46 = V_20 -> V_101 ( V_34 , V_102 ) ;
if ( ( V_46 & V_68 ) == V_68 )
break;
if ( V_46 < 0 ) {
F_8 ( L_40 ,
V_60 , V_34 -> V_16 -> V_17 , V_34 -> V_80 ) ;
V_57 = - V_122 ;
break;
}
V_57 = - V_103 ;
F_8 ( L_41 ,
V_60 , V_46 , V_34 -> V_16 -> V_17 , V_34 -> V_80 , ( V_12 + 1 ) ) ;
}
F_52 ( V_34 , V_120 ) ;
return V_57 ;
}
void F_58 ( struct V_4 * V_5 )
{
struct V_8 * V_9 ;
int V_12 ;
V_9 = F_4 ( V_5 ) ;
if ( ! V_9 )
return;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
V_20 -> V_21 ( V_9 , V_12 * 4 , 4 , & V_5 -> V_123 [ V_12 ] ) ;
if ( V_5 -> V_24 & V_25 )
V_5 -> V_123 [ 1 ] |= V_124 ;
}
int T_1 F_59 ( struct V_20 * V_125 )
{
if ( ! V_125 -> V_126 ) {
F_8 ( L_42 ,
V_60 , V_125 ) ;
return - V_99 ;
}
if ( V_20 && V_20 != V_125 ) {
F_8 ( L_43 ,
V_60 , V_20 -> V_126 , V_125 -> V_126 ) ;
return - V_61 ;
}
V_20 = V_125 ;
return 0 ;
}
int T_6 F_60 ( const char * V_126 )
{
if ( ! V_126 || ! strlen ( V_126 ) ) {
F_8 ( L_44 ,
V_60 ) ;
return - V_99 ;
}
if ( V_20 && ! strcmp ( V_20 -> V_126 , V_126 ) ) {
V_20 = NULL ;
return 0 ;
}
return - V_61 ;
}
static int F_61 ( struct V_127 * V_128 ,
unsigned long V_129 , void * V_130 )
{
F_62 ( V_131 ) ;
return V_132 ;
}
int F_63 ( void )
{
struct V_133 * V_134 , * V_35 ;
struct V_8 * V_9 ;
static int V_135 = 0 ;
int V_57 = 0 ;
if ( F_64 ( V_136 ) && V_135 ++ <= 0 )
return V_57 ;
V_57 = F_65 ( & V_137 ) ;
if ( V_57 ) {
F_8 ( L_45 ,
V_60 , V_57 ) ;
return V_57 ;
}
if ( ! V_20 ) {
F_8 ( L_46 ,
V_60 ) ;
return - V_61 ;
} else if ( ( V_57 = V_20 -> V_138 () ) )
return V_57 ;
F_66 (hose, tmp, &hose_list, list_node)
F_67 ( V_134 ) ;
V_57 = F_68 () ;
if ( V_57 )
return V_57 ;
F_66 (hose, tmp, &hose_list, list_node) {
V_9 = V_134 -> V_139 ;
F_69 ( V_9 , V_20 -> V_140 , NULL ) ;
}
if ( V_20 -> V_141 ) {
V_57 = V_20 -> V_141 () ;
if ( V_57 )
return V_57 ;
}
if ( F_30 () )
F_70 ( L_47 ) ;
else
F_70 ( L_48 ) ;
return V_57 ;
}
void F_71 ( struct V_8 * V_9 )
{
struct V_133 * V_16 = V_9 ? V_9 -> V_16 : NULL ;
struct V_4 * V_5 = F_72 ( V_9 ) ;
if ( ! V_5 )
return;
if ( ! F_12 ( V_142 ) )
return;
if ( NULL == V_16 ||
( F_12 ( V_142 ) && 0 == V_16 -> V_143 ) )
return;
V_20 -> V_140 ( V_9 , NULL ) ;
}
void F_73 ( struct V_8 * V_9 )
{
struct V_8 * V_13 ;
if ( ! V_9 )
return;
F_74 (n, &pdn->child_list, list)
F_73 ( V_13 ) ;
F_71 ( V_9 ) ;
}
void F_75 ( struct V_71 * V_72 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
if ( ! V_72 || ! F_30 () )
return;
F_33 ( L_49 , F_50 ( V_72 ) ) ;
V_9 = F_76 ( V_72 -> V_144 , V_72 -> V_19 ) ;
V_5 = F_72 ( V_9 ) ;
if ( V_5 -> V_105 == V_72 ) {
F_33 ( L_50 ) ;
return;
}
if ( V_5 -> V_105 ) {
F_77 ( V_5 ) ;
F_78 ( V_5 -> V_105 ) ;
F_79 ( V_5 -> V_105 ) ;
V_5 -> V_24 &= ~ V_145 ;
V_5 -> V_24 |= V_146 ;
V_5 -> V_105 = NULL ;
V_72 -> V_72 . V_147 . V_5 = NULL ;
}
if ( F_12 ( V_58 ) )
V_20 -> V_140 ( V_9 , NULL ) ;
V_5 -> V_105 = V_72 ;
V_72 -> V_72 . V_147 . V_5 = V_5 ;
F_80 ( V_72 ) ;
}
void F_81 ( struct V_148 * V_144 )
{
struct V_71 * V_72 ;
F_74 (dev, &bus->devices, bus_list) {
F_75 ( V_72 ) ;
if ( V_72 -> V_149 == V_150 ) {
struct V_148 * V_151 = V_72 -> V_152 ;
if ( V_151 )
F_81 ( V_151 ) ;
}
}
}
void F_82 ( struct V_148 * V_144 )
{
struct V_71 * V_72 ;
F_74 (dev, &bus->devices, bus_list) {
F_83 ( V_72 ) ;
if ( V_72 -> V_149 == V_150 ) {
struct V_148 * V_151 = V_72 -> V_152 ;
if ( V_151 )
F_82 ( V_151 ) ;
}
}
}
void F_84 ( struct V_71 * V_72 )
{
struct V_4 * V_5 ;
if ( ! V_72 || ! F_30 () )
return;
V_5 = F_49 ( V_72 ) ;
F_33 ( L_51 , F_50 ( V_72 ) ) ;
if ( ! V_5 || ! V_5 -> V_105 || ! V_5 -> V_34 ) {
F_33 ( L_52 ) ;
return;
}
V_5 -> V_105 = NULL ;
V_5 -> V_153 = false ;
V_72 -> V_72 . V_147 . V_5 = NULL ;
if ( ! ( V_5 -> V_34 -> V_46 & V_154 ) )
F_77 ( V_5 ) ;
else
V_5 -> V_24 |= V_155 ;
V_5 -> V_24 |= V_146 ;
F_78 ( V_72 ) ;
F_79 ( V_72 ) ;
V_5 -> V_24 &= ~ V_145 ;
}
int F_51 ( struct V_33 * V_34 , bool V_156 )
{
int V_57 ;
V_57 = F_13 ( V_34 , V_44 ) ;
if ( V_57 ) {
F_8 ( L_53 ,
V_60 , V_57 , V_34 -> V_16 -> V_17 , V_34 -> V_80 ) ;
return V_57 ;
}
V_57 = F_13 ( V_34 , V_95 ) ;
if ( V_57 ) {
F_8 ( L_54 ,
V_60 , V_57 , V_34 -> V_16 -> V_17 , V_34 -> V_80 ) ;
return V_57 ;
}
if ( V_156 && ( V_34 -> V_46 & V_62 ) )
F_52 ( V_34 , V_62 ) ;
return V_57 ;
}
static int F_85 ( struct V_33 * V_34 )
{
struct V_4 * V_5 , * V_35 ;
struct V_71 * V_105 ;
struct V_157 * V_158 ;
int V_56 , V_57 ;
V_56 = ( V_66 | V_67 ) ;
V_57 = V_20 -> V_64 ( V_34 , NULL ) ;
if ( V_57 < 0 || V_57 == V_65 )
return 0 ;
if ( ( V_57 & V_56 ) == V_56 )
return 0 ;
F_10 (pe, edev, tmp) {
V_105 = F_31 ( V_5 ) ;
if ( ! V_105 )
continue;
for ( V_158 = & V_159 [ 0 ] ; V_158 -> V_160 != 0 ; V_158 ++ ) {
if ( V_158 -> V_160 != V_161 &&
V_158 -> V_160 != V_105 -> V_160 )
continue;
if ( V_158 -> V_162 != V_161 &&
V_158 -> V_162 != V_105 -> V_162 )
continue;
if ( V_158 -> V_163 != V_161 &&
V_158 -> V_163 != V_105 -> V_164 )
continue;
if ( V_158 -> V_165 != V_161 &&
V_158 -> V_165 != V_105 -> V_166 )
continue;
return F_86 ( V_34 ) ;
}
}
return F_51 ( V_34 , true ) ;
}
int F_87 ( struct V_71 * V_105 )
{
struct V_4 * V_5 ;
int V_57 = - V_167 ;
F_88 ( & V_168 ) ;
if ( ! V_105 )
goto V_63;
V_5 = F_49 ( V_105 ) ;
if ( ! V_5 || ! V_5 -> V_34 )
goto V_63;
V_57 = F_85 ( V_5 -> V_34 ) ;
if ( V_57 )
goto V_63;
F_89 ( & V_5 -> V_34 -> V_169 ) ;
F_90 ( & V_168 ) ;
return 0 ;
V_63:
F_90 ( & V_168 ) ;
return V_57 ;
}
void F_91 ( struct V_71 * V_105 )
{
struct V_4 * V_5 ;
F_88 ( & V_168 ) ;
if ( ! V_105 )
goto V_63;
V_5 = F_49 ( V_105 ) ;
if ( ! V_5 || ! V_5 -> V_34 || ! F_35 ( V_5 -> V_34 ) )
goto V_63;
F_18 ( F_92 ( & V_5 -> V_34 -> V_169 ) < 0 ) ;
F_85 ( V_5 -> V_34 ) ;
V_63:
F_90 ( & V_168 ) ;
}
static int F_93 ( struct V_162 * V_72 , void * V_31 )
{
struct V_71 * V_105 = F_94 ( V_72 ) ;
struct V_71 * * V_170 = V_31 ;
if ( ! V_72 )
return 0 ;
if ( V_72 -> V_171 ) {
* V_170 = V_105 ;
return 1 ;
}
return 0 ;
}
struct V_33 * F_95 ( struct V_171 * V_172 )
{
struct V_71 * V_105 = NULL ;
struct V_4 * V_5 ;
int V_57 ;
if ( ! V_172 )
return NULL ;
V_57 = F_96 ( V_172 , & V_105 , F_93 ) ;
if ( ! V_57 || ! V_105 )
return NULL ;
V_5 = F_49 ( V_105 ) ;
if ( ! V_5 || ! V_5 -> V_34 )
return NULL ;
return V_5 -> V_34 ;
}
int F_97 ( struct V_33 * V_34 , int V_173 )
{
int V_57 = 0 ;
if ( ! V_34 )
return - V_167 ;
switch ( V_173 ) {
case V_97 :
if ( F_30 () ) {
V_57 = F_85 ( V_34 ) ;
break;
}
V_57 = - V_103 ;
break;
case V_96 :
break;
case V_44 :
case V_95 :
case V_98 :
if ( ! V_20 || ! V_20 -> V_100 ) {
V_57 = - V_174 ;
break;
}
V_57 = F_13 ( V_34 , V_173 ) ;
break;
default:
F_33 ( L_55 ,
V_60 , V_173 , V_96 , V_95 ) ;
V_57 = - V_99 ;
}
return V_57 ;
}
int F_98 ( struct V_33 * V_34 )
{
int V_175 , V_57 = 0 ;
bool V_176 , V_177 , V_178 ;
if ( ! V_34 )
return - V_167 ;
if ( ! V_20 || ! V_20 -> V_64 )
return - V_174 ;
if ( V_34 -> V_88 &&
! ( V_34 -> V_46 & V_179 ) &&
( V_34 -> V_88 -> V_46 & ( V_62 | V_180 ) ) )
return V_181 ;
V_175 = V_20 -> V_64 ( V_34 , NULL ) ;
V_176 = ! ! ( V_175 & V_182 ) ;
V_177 = ! ! ( V_175 & V_183 ) ;
V_178 = ! ! ( V_175 & V_94 ) ;
if ( V_176 )
V_57 = V_184 ;
else if ( V_177 && V_178 )
V_57 = V_185 ;
else if ( ! V_177 && ! V_178 )
V_57 = V_186 ;
else if ( ! V_177 && V_178 )
V_57 = V_187 ;
else
V_57 = V_181 ;
return V_57 ;
}
static int F_99 ( struct V_33 * V_34 )
{
struct V_4 * V_5 , * V_35 ;
struct V_71 * V_105 ;
int V_57 = 0 ;
F_14 ( V_34 ) ;
F_10 (pe, edev, tmp) {
V_105 = F_31 ( V_5 ) ;
if ( ! V_105 )
continue;
V_57 = F_100 ( V_105 ) ;
if ( V_57 ) {
F_8 ( L_56 ,
V_60 , V_57 , F_50 ( V_105 ) ) ;
return V_57 ;
}
}
return F_51 ( V_34 , true ) ;
}
int F_57 ( struct V_33 * V_34 , int V_173 )
{
int V_57 = 0 ;
if ( ! V_34 )
return - V_167 ;
if ( ! V_20 || ! V_20 -> V_100 || ! V_20 -> V_111 )
return - V_174 ;
switch ( V_173 ) {
case V_112 :
V_57 = V_20 -> V_111 ( V_34 , V_173 ) ;
F_52 ( V_34 , V_47 ) ;
if ( V_57 )
break;
V_57 = F_99 ( V_34 ) ;
break;
case V_115 :
case V_117 :
V_20 -> V_100 ( V_34 , V_98 ) ;
F_23 ( V_34 , V_47 ) ;
V_57 = V_20 -> V_111 ( V_34 , V_173 ) ;
break;
default:
F_33 ( L_57 ,
V_60 , V_173 ) ;
V_57 = - V_99 ;
}
return V_57 ;
}
int F_101 ( struct V_33 * V_34 )
{
int V_57 = 0 ;
if ( ! V_34 )
return - V_167 ;
return V_57 ;
}
int F_102 ( struct V_33 * V_34 , int type , int V_188 ,
unsigned long V_80 , unsigned long V_189 )
{
if ( ! V_34 )
return - V_167 ;
if ( ! V_20 || ! V_20 -> V_190 )
return - V_174 ;
if ( type != V_191 && type != V_192 )
return - V_99 ;
if ( V_188 < V_193 || V_188 > V_194 )
return - V_99 ;
return V_20 -> V_190 ( V_34 , type , V_188 , V_80 , V_189 ) ;
}
static int F_103 ( struct V_195 * V_196 , void * V_197 )
{
if ( ! F_30 () ) {
F_104 ( V_196 , L_58 ) ;
F_104 ( V_196 , L_59 , V_76 . V_77 ) ;
} else {
F_104 ( V_196 , L_60 ) ;
F_104 ( V_196 ,
L_61
L_62
L_63
L_64
L_59
L_65
L_66 ,
V_76 . V_91 ,
V_76 . V_78 ,
V_76 . V_82 ,
V_76 . V_79 ,
V_76 . V_77 ,
V_76 . V_87 ,
V_76 . V_89 ) ;
}
return 0 ;
}
static int F_105 ( struct V_198 * V_198 , struct V_199 * V_199 )
{
return F_106 ( V_199 , F_103 , NULL ) ;
}
static int F_107 ( void * V_31 , T_7 V_200 )
{
if ( V_200 )
F_62 ( V_2 ) ;
else
F_2 ( V_2 ) ;
if ( V_20 -> V_141 )
V_20 -> V_141 () ;
return 0 ;
}
static int F_108 ( void * V_31 , T_7 * V_200 )
{
if ( F_30 () )
* V_200 = 0x1ul ;
else
* V_200 = 0x0ul ;
return 0 ;
}
static int F_109 ( void * V_31 , T_7 V_200 )
{
V_201 = V_200 ;
return 0 ;
}
static int F_110 ( void * V_31 , T_7 * V_200 )
{
* V_200 = V_201 ;
return 0 ;
}
static int T_1 F_111 ( void )
{
if ( F_64 ( V_202 ) || F_64 ( V_136 ) ) {
F_112 ( L_67 , 0 , NULL , & V_203 ) ;
#ifdef F_113
F_114 ( L_68 , 0600 ,
V_204 , NULL ,
& V_205 ) ;
F_114 ( L_69 , 0600 ,
V_204 , NULL ,
& V_206 ) ;
#endif
}
return 0 ;
}

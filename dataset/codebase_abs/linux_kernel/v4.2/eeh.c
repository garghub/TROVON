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
V_5 -> V_16 -> V_17 , V_9 -> V_18 ,
F_6 ( V_9 -> V_19 ) , F_7 ( V_9 -> V_19 ) ) ;
F_8 ( L_4 ,
V_5 -> V_16 -> V_17 , V_9 -> V_18 ,
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
if ( V_34 -> V_37 & V_38 )
return NULL ;
F_10 ( V_34 , V_5 , V_35 )
* V_36 += F_3 ( V_5 , V_39 + * V_36 ,
V_40 - * V_36 ) ;
return NULL ;
}
void F_11 ( struct V_33 * V_34 , int V_41 )
{
T_2 V_42 = 0 ;
if ( ! ( V_34 -> type & V_43 ) ) {
if ( F_12 ( V_44 ) )
F_13 ( V_34 , V_45 ) ;
V_20 -> V_46 ( V_34 ) ;
F_14 ( V_34 ) ;
V_39 [ 0 ] = 0 ;
F_15 ( V_34 , F_9 , & V_42 ) ;
}
V_20 -> V_47 ( V_34 , V_41 , V_39 , V_42 ) ;
}
static inline unsigned long F_16 ( unsigned long V_48 )
{
T_4 * V_49 ;
unsigned long V_50 ;
int V_51 ;
V_49 = F_17 ( V_52 . V_53 , V_48 , & V_51 ) ;
if ( ! V_49 )
return V_48 ;
F_18 ( V_51 ) ;
V_50 = F_19 ( * V_49 ) << V_54 ;
return V_50 | ( V_48 & ( V_55 - 1 ) ) ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_33 * V_56 ;
unsigned long V_57 ;
int V_58 ;
if ( ! F_12 ( V_59 ) )
return - V_60 ;
V_56 = F_21 ( V_34 -> V_16 ) ;
if ( ! V_56 ) {
F_8 ( L_26 ,
V_61 , V_34 -> V_16 -> V_17 ) ;
return - V_62 ;
}
F_22 ( & V_57 ) ;
if ( V_56 -> V_37 & V_63 ) {
V_58 = 0 ;
goto V_64;
}
V_58 = V_20 -> V_65 ( V_56 , NULL ) ;
if ( ( V_58 < 0 ) ||
( V_58 == V_66 ) ||
( V_58 & ( V_67 | V_68 ) ) ==
( V_67 | V_68 ) ) {
V_58 = 0 ;
goto V_64;
}
F_23 ( V_56 , V_63 ) ;
F_24 ( V_57 ) ;
F_25 ( L_27 ,
V_56 -> V_16 -> V_17 , F_26 ( V_56 ) ) ;
F_27 () ;
F_28 ( V_56 ) ;
return 1 ;
V_64:
F_24 ( V_57 ) ;
return V_58 ;
}
int F_29 ( struct V_4 * V_5 )
{
int V_58 ;
int V_69 = ( V_67 | V_68 ) ;
unsigned long V_57 ;
struct V_8 * V_9 ;
struct V_70 * V_71 ;
struct V_33 * V_34 , * V_72 , * V_56 ;
int V_73 = 0 ;
const char * V_74 = NULL ;
V_75 . V_76 ++ ;
if ( ! F_30 () )
return 0 ;
if ( ! V_5 ) {
V_75 . V_77 ++ ;
return 0 ;
}
V_71 = F_31 ( V_5 ) ;
V_34 = F_32 ( V_5 ) ;
if ( ! V_34 ) {
V_75 . V_78 ++ ;
F_33 ( L_28 ,
F_34 ( V_71 ) ) ;
return 0 ;
}
if ( ! V_34 -> V_79 && ! V_34 -> V_80 ) {
V_75 . V_81 ++ ;
return 0 ;
}
V_58 = F_20 ( V_34 ) ;
if ( V_58 > 0 )
return V_58 ;
if ( F_35 ( V_34 ) )
return 0 ;
F_22 ( & V_57 ) ;
V_73 = 1 ;
if ( V_34 -> V_37 & V_63 ) {
V_34 -> V_82 ++ ;
if ( V_34 -> V_82 % V_83 == 0 ) {
V_9 = F_4 ( V_5 ) ;
if ( V_9 -> V_84 )
V_74 = F_36 ( V_9 -> V_84 , L_29 , NULL ) ;
F_37 ( V_85 L_30
L_31 ,
V_34 -> V_82 ,
V_74 ? V_74 : L_32 ,
F_38 ( V_71 ) , F_34 ( V_71 ) ) ;
F_37 ( V_85 L_33 ,
F_38 ( V_71 ) ) ;
F_27 () ;
}
goto V_86;
}
V_58 = V_20 -> V_65 ( V_34 , NULL ) ;
if ( ( V_58 < 0 ) ||
( V_58 == V_66 ) ||
( ( V_58 & V_69 ) == V_69 ) ) {
V_75 . V_87 ++ ;
V_34 -> V_87 ++ ;
V_73 = 0 ;
goto V_86;
}
V_72 = V_34 -> V_88 ;
while ( V_72 ) {
if ( V_72 -> type & V_43 )
break;
V_58 = V_20 -> V_65 ( V_72 , NULL ) ;
if ( V_58 > 0 &&
( V_58 & V_69 ) != V_69 )
V_34 = V_72 ;
V_72 = V_72 -> V_88 ;
}
V_75 . V_89 ++ ;
F_23 ( V_34 , V_63 ) ;
F_24 ( V_57 ) ;
V_56 = F_21 ( V_34 -> V_16 ) ;
F_25 ( L_34 ,
V_34 -> V_16 -> V_17 , V_34 -> V_79 ) ;
F_25 ( L_35 ,
F_26 ( V_34 ) , F_26 ( V_56 ) ) ;
F_27 () ;
F_28 ( V_34 ) ;
return 1 ;
V_86:
F_24 ( V_57 ) ;
return V_73 ;
}
int F_39 ( const volatile void T_5 * V_48 )
{
unsigned long V_79 ;
struct V_4 * V_5 ;
V_79 = F_16 ( ( unsigned long V_90 ) V_48 ) ;
V_5 = F_40 ( V_79 ) ;
if ( ! V_5 ) {
V_75 . V_91 ++ ;
return 0 ;
}
return F_29 ( V_5 ) ;
}
int F_13 ( struct V_33 * V_34 , int V_92 )
{
int V_93 , V_73 ;
switch ( V_92 ) {
case V_45 :
V_93 = V_67 ;
break;
case V_94 :
V_93 = V_68 ;
break;
case V_95 :
case V_96 :
case V_97 :
V_93 = 0 ;
break;
default:
F_8 ( L_36 ,
V_61 , V_92 ) ;
return - V_98 ;
}
if ( V_93 ) {
V_73 = V_20 -> V_65 ( V_34 , NULL ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_73 == V_66 )
return 0 ;
if ( V_73 & V_93 )
return 0 ;
}
V_73 = V_20 -> V_99 ( V_34 , V_92 ) ;
if ( V_73 )
F_8 ( L_37
L_38 ,
V_61 , V_92 , V_34 -> V_16 -> V_17 ,
V_34 -> V_79 , V_73 ) ;
if ( V_93 ) {
V_73 = V_20 -> V_100 ( V_34 , V_101 ) ;
if ( V_73 <= 0 )
return V_73 ;
if ( V_73 & V_93 )
return 0 ;
return - V_102 ;
}
return V_73 ;
}
static void * F_41 ( void * V_31 , void * V_103 )
{
struct V_4 * V_5 = V_31 ;
struct V_70 * V_104 = F_31 ( V_5 ) ;
struct V_70 * V_71 = V_103 ;
if ( ! V_104 || V_104 == V_71 )
return NULL ;
F_42 ( V_104 , V_105 ) ;
F_43 ( V_104 ) ;
F_44 ( V_104 , V_23 , V_106 ) ;
return NULL ;
}
static void * F_45 ( void * V_31 , void * V_103 )
{
struct V_4 * V_5 = V_31 ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_70 * V_104 = F_31 ( V_5 ) ;
struct V_70 * V_71 = V_103 ;
if ( ! V_104 )
return NULL ;
if ( V_9 && V_20 -> V_107 )
V_20 -> V_107 ( V_9 ) ;
if ( V_104 != V_71 )
F_46 ( V_104 ) ;
return NULL ;
}
int F_47 ( struct V_70 * V_71 , enum V_108 V_37 )
{
struct V_4 * V_5 = F_48 ( V_71 ) ;
struct V_33 * V_34 = F_32 ( V_5 ) ;
if ( ! V_34 ) {
F_25 ( L_39 ,
V_61 , F_49 ( V_71 ) ) ;
return - V_98 ;
}
switch ( V_37 ) {
case V_109 :
V_20 -> V_110 ( V_34 , V_111 ) ;
F_50 ( V_34 , false ) ;
F_51 ( V_34 , V_38 ) ;
F_52 ( V_34 , F_45 , V_71 ) ;
F_51 ( V_34 , V_63 ) ;
break;
case V_112 :
F_23 ( V_34 , V_63 ) ;
V_20 -> V_99 ( V_34 , V_97 ) ;
F_52 ( V_34 , F_41 , V_71 ) ;
F_23 ( V_34 , V_38 ) ;
V_20 -> V_110 ( V_34 , V_113 ) ;
break;
case V_114 :
F_23 ( V_34 , V_63 ) ;
V_20 -> V_99 ( V_34 , V_97 ) ;
F_52 ( V_34 , F_41 , V_71 ) ;
F_23 ( V_34 , V_38 ) ;
V_20 -> V_110 ( V_34 , V_115 ) ;
break;
default:
F_51 ( V_34 , V_63 | V_38 ) ;
return - V_98 ;
} ;
return 0 ;
}
static void * F_53 ( void * V_31 , void * V_32 )
{
struct V_70 * V_71 ;
unsigned int * V_116 = ( unsigned int * ) V_32 ;
struct V_4 * V_5 = (struct V_4 * ) V_31 ;
V_71 = F_31 ( V_5 ) ;
if ( V_71 )
* V_116 |= V_71 -> V_117 ;
return NULL ;
}
static void F_54 ( struct V_33 * V_34 )
{
unsigned int V_116 = 0 ;
F_52 ( V_34 , F_53 , & V_116 ) ;
if ( V_116 )
V_20 -> V_110 ( V_34 , V_115 ) ;
else
V_20 -> V_110 ( V_34 , V_113 ) ;
V_20 -> V_110 ( V_34 , V_111 ) ;
}
int F_55 ( struct V_33 * V_34 )
{
int V_57 = ( V_67 | V_68 ) ;
int V_12 , V_37 , V_58 ;
F_23 ( V_34 , V_118 | V_38 ) ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
F_54 ( V_34 ) ;
V_37 = V_20 -> V_100 ( V_34 , V_101 ) ;
if ( ( V_37 & V_57 ) == V_57 ) {
V_58 = 0 ;
goto V_64;
}
if ( V_37 < 0 ) {
F_8 ( L_40 ,
V_61 , V_34 -> V_16 -> V_17 , V_34 -> V_79 ) ;
V_58 = - V_119 ;
goto V_64;
}
V_58 = - V_102 ;
F_8 ( L_41 ,
V_61 , V_37 , V_34 -> V_16 -> V_17 , V_34 -> V_79 , ( V_12 + 1 ) ) ;
}
V_64:
F_51 ( V_34 , V_118 | V_38 ) ;
return V_58 ;
}
void F_56 ( struct V_4 * V_5 )
{
struct V_8 * V_9 ;
int V_12 ;
V_9 = F_4 ( V_5 ) ;
if ( ! V_9 )
return;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
V_20 -> V_21 ( V_9 , V_12 * 4 , 4 , & V_5 -> V_120 [ V_12 ] ) ;
if ( V_5 -> V_24 & V_25 )
V_5 -> V_120 [ 1 ] |= V_121 ;
}
int T_1 F_57 ( struct V_20 * V_122 )
{
if ( ! V_122 -> V_123 ) {
F_8 ( L_42 ,
V_61 , V_122 ) ;
return - V_98 ;
}
if ( V_20 && V_20 != V_122 ) {
F_8 ( L_43 ,
V_61 , V_20 -> V_123 , V_122 -> V_123 ) ;
return - V_62 ;
}
V_20 = V_122 ;
return 0 ;
}
int T_6 F_58 ( const char * V_123 )
{
if ( ! V_123 || ! strlen ( V_123 ) ) {
F_8 ( L_44 ,
V_61 ) ;
return - V_98 ;
}
if ( V_20 && ! strcmp ( V_20 -> V_123 , V_123 ) ) {
V_20 = NULL ;
return 0 ;
}
return - V_62 ;
}
static int F_59 ( struct V_124 * V_125 ,
unsigned long V_126 , void * V_127 )
{
F_60 ( V_128 ) ;
return V_129 ;
}
int F_61 ( void )
{
struct V_130 * V_131 , * V_35 ;
struct V_8 * V_9 ;
static int V_132 = 0 ;
int V_58 = 0 ;
if ( F_62 ( V_133 ) && V_132 ++ <= 0 )
return V_58 ;
V_58 = F_63 ( & V_134 ) ;
if ( V_58 ) {
F_8 ( L_45 ,
V_61 , V_58 ) ;
return V_58 ;
}
if ( ! V_20 ) {
F_8 ( L_46 ,
V_61 ) ;
return - V_62 ;
} else if ( ( V_58 = V_20 -> V_135 () ) )
return V_58 ;
V_58 = F_64 () ;
if ( V_58 )
return V_58 ;
F_65 (hose, tmp, &hose_list, list_node) {
V_9 = V_131 -> V_136 ;
F_66 ( V_9 , V_20 -> V_137 , NULL ) ;
}
if ( V_20 -> V_138 ) {
V_58 = V_20 -> V_138 () ;
if ( V_58 )
return V_58 ;
}
if ( F_30 () )
F_67 ( L_47 ) ;
else
F_8 ( L_48 ) ;
return V_58 ;
}
void F_68 ( struct V_8 * V_9 )
{
struct V_130 * V_16 ;
struct V_4 * V_5 = F_69 ( V_9 ) ;
if ( ! V_5 || ! F_30 () )
return;
if ( ! F_12 ( V_139 ) )
return;
V_16 = V_5 -> V_16 ;
if ( NULL == V_16 ||
( F_12 ( V_139 ) && 0 == V_16 -> V_140 ) )
return;
V_20 -> V_137 ( V_9 , NULL ) ;
}
void F_70 ( struct V_8 * V_9 )
{
struct V_8 * V_13 ;
if ( ! V_9 )
return;
F_71 (n, &pdn->child_list, list)
F_70 ( V_13 ) ;
F_68 ( V_9 ) ;
}
void F_72 ( struct V_70 * V_71 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
if ( ! V_71 || ! F_30 () )
return;
F_33 ( L_49 , F_49 ( V_71 ) ) ;
V_9 = F_73 ( V_71 -> V_141 , V_71 -> V_19 ) ;
V_5 = F_69 ( V_9 ) ;
if ( V_5 -> V_104 == V_71 ) {
F_33 ( L_50 ) ;
return;
}
if ( F_12 ( V_59 ) )
V_20 -> V_137 ( V_9 , NULL ) ;
if ( V_5 -> V_104 ) {
F_74 ( V_5 ) ;
F_75 ( V_5 -> V_104 ) ;
F_76 ( V_5 -> V_104 ) ;
V_5 -> V_24 &= ~ V_142 ;
V_5 -> V_24 |= V_143 ;
V_5 -> V_104 = NULL ;
V_71 -> V_71 . V_144 . V_5 = NULL ;
}
V_5 -> V_104 = V_71 ;
V_71 -> V_71 . V_144 . V_5 = V_5 ;
F_77 ( V_71 ) ;
}
void F_78 ( struct V_145 * V_141 )
{
struct V_70 * V_71 ;
F_71 (dev, &bus->devices, bus_list) {
F_72 ( V_71 ) ;
if ( V_71 -> V_146 == V_147 ) {
struct V_145 * V_148 = V_71 -> V_149 ;
if ( V_148 )
F_78 ( V_148 ) ;
}
}
}
void F_79 ( struct V_145 * V_141 )
{
struct V_70 * V_71 ;
F_71 (dev, &bus->devices, bus_list) {
F_80 ( V_71 ) ;
if ( V_71 -> V_146 == V_147 ) {
struct V_145 * V_148 = V_71 -> V_149 ;
if ( V_148 )
F_79 ( V_148 ) ;
}
}
}
void F_81 ( struct V_70 * V_71 )
{
struct V_4 * V_5 ;
if ( ! V_71 || ! F_30 () )
return;
V_5 = F_48 ( V_71 ) ;
F_33 ( L_51 , F_49 ( V_71 ) ) ;
if ( ! V_5 || ! V_5 -> V_104 || ! V_5 -> V_34 ) {
F_33 ( L_52 ) ;
return;
}
V_5 -> V_104 = NULL ;
V_71 -> V_71 . V_144 . V_5 = NULL ;
if ( ! ( V_5 -> V_34 -> V_37 & V_150 ) )
F_74 ( V_5 ) ;
else
V_5 -> V_24 |= V_151 ;
V_5 -> V_24 |= V_143 ;
F_75 ( V_71 ) ;
F_76 ( V_71 ) ;
V_5 -> V_24 &= ~ V_142 ;
}
int F_50 ( struct V_33 * V_34 , bool V_152 )
{
int V_58 ;
V_58 = F_13 ( V_34 , V_45 ) ;
if ( V_58 ) {
F_8 ( L_53 ,
V_61 , V_58 , V_34 -> V_16 -> V_17 , V_34 -> V_79 ) ;
return V_58 ;
}
V_58 = F_13 ( V_34 , V_94 ) ;
if ( V_58 ) {
F_8 ( L_54 ,
V_61 , V_58 , V_34 -> V_16 -> V_17 , V_34 -> V_79 ) ;
return V_58 ;
}
if ( V_152 && ( V_34 -> V_37 & V_63 ) )
F_51 ( V_34 , V_63 ) ;
return V_58 ;
}
static int F_82 ( struct V_33 * V_34 )
{
struct V_4 * V_5 , * V_35 ;
struct V_70 * V_104 ;
struct V_153 * V_154 ;
int V_57 , V_58 ;
V_57 = ( V_67 | V_68 ) ;
V_58 = V_20 -> V_65 ( V_34 , NULL ) ;
if ( V_58 < 0 || V_58 == V_66 )
return 0 ;
if ( ( V_58 & V_57 ) == V_57 )
return 0 ;
F_10 (pe, edev, tmp) {
V_104 = F_31 ( V_5 ) ;
if ( ! V_104 )
continue;
for ( V_154 = & V_155 [ 0 ] ; V_154 -> V_156 != 0 ; V_154 ++ ) {
if ( V_154 -> V_156 != V_157 &&
V_154 -> V_156 != V_104 -> V_156 )
continue;
if ( V_154 -> V_158 != V_157 &&
V_154 -> V_158 != V_104 -> V_158 )
continue;
if ( V_154 -> V_159 != V_157 &&
V_154 -> V_159 != V_104 -> V_160 )
continue;
if ( V_154 -> V_161 != V_157 &&
V_154 -> V_161 != V_104 -> V_162 )
continue;
goto V_110;
}
}
return F_50 ( V_34 , true ) ;
V_110:
return F_83 ( V_34 ) ;
}
int F_84 ( struct V_70 * V_104 )
{
struct V_4 * V_5 ;
int V_58 = - V_163 ;
F_85 ( & V_164 ) ;
if ( ! V_104 )
goto V_64;
V_5 = F_48 ( V_104 ) ;
if ( ! V_5 || ! V_5 -> V_34 )
goto V_64;
V_58 = F_82 ( V_5 -> V_34 ) ;
if ( V_58 )
goto V_64;
F_86 ( & V_5 -> V_34 -> V_165 ) ;
F_87 ( & V_164 ) ;
return 0 ;
V_64:
F_87 ( & V_164 ) ;
return V_58 ;
}
void F_88 ( struct V_70 * V_104 )
{
struct V_4 * V_5 ;
F_85 ( & V_164 ) ;
if ( ! V_104 )
goto V_64;
V_5 = F_48 ( V_104 ) ;
if ( ! V_5 || ! V_5 -> V_34 || ! F_35 ( V_5 -> V_34 ) )
goto V_64;
F_89 ( & V_5 -> V_34 -> V_165 ) ;
F_18 ( F_90 ( & V_5 -> V_34 -> V_165 ) < 0 ) ;
F_82 ( V_5 -> V_34 ) ;
V_64:
F_87 ( & V_164 ) ;
}
static int F_91 ( struct V_158 * V_71 , void * V_31 )
{
struct V_70 * V_104 = F_92 ( V_71 ) ;
struct V_70 * * V_166 = V_31 ;
if ( ! V_71 )
return 0 ;
if ( V_71 -> V_167 ) {
* V_166 = V_104 ;
return 1 ;
}
return 0 ;
}
struct V_33 * F_93 ( struct V_167 * V_168 )
{
struct V_70 * V_104 = NULL ;
struct V_4 * V_5 ;
int V_58 ;
if ( ! V_168 )
return NULL ;
V_58 = F_94 ( V_168 , & V_104 , F_91 ) ;
if ( ! V_58 || ! V_104 )
return NULL ;
V_5 = F_48 ( V_104 ) ;
if ( ! V_5 || ! V_5 -> V_34 )
return NULL ;
return V_5 -> V_34 ;
}
int F_95 ( struct V_33 * V_34 , int V_169 )
{
int V_58 = 0 ;
if ( ! V_34 )
return - V_163 ;
switch ( V_169 ) {
case V_96 :
if ( F_30 () ) {
V_58 = F_82 ( V_34 ) ;
break;
}
V_58 = - V_102 ;
break;
case V_95 :
break;
case V_45 :
case V_94 :
if ( ! V_20 || ! V_20 -> V_99 ) {
V_58 = - V_170 ;
break;
}
V_58 = F_13 ( V_34 , V_169 ) ;
break;
default:
F_33 ( L_55 ,
V_61 , V_169 , V_95 , V_94 ) ;
V_58 = - V_98 ;
}
return V_58 ;
}
int F_96 ( struct V_33 * V_34 )
{
int V_171 , V_58 = 0 ;
bool V_172 , V_173 , V_174 ;
if ( ! V_34 )
return - V_163 ;
if ( ! V_20 || ! V_20 -> V_65 )
return - V_170 ;
V_171 = V_20 -> V_65 ( V_34 , NULL ) ;
V_172 = ! ! ( V_171 & V_175 ) ;
V_173 = ! ! ( V_171 & V_176 ) ;
V_174 = ! ! ( V_171 & V_177 ) ;
if ( V_172 )
V_58 = V_178 ;
else if ( V_173 && V_174 )
V_58 = V_179 ;
else if ( ! V_173 && ! V_174 )
V_58 = V_180 ;
else if ( ! V_173 && V_174 )
V_58 = V_181 ;
else
V_58 = V_182 ;
return V_58 ;
}
static int F_97 ( struct V_33 * V_34 )
{
struct V_4 * V_5 , * V_35 ;
struct V_70 * V_104 ;
int V_58 = 0 ;
F_14 ( V_34 ) ;
F_10 (pe, edev, tmp) {
V_104 = F_31 ( V_5 ) ;
if ( ! V_104 )
continue;
V_58 = F_98 ( V_104 ) ;
if ( V_58 ) {
F_8 ( L_56 ,
V_61 , V_58 , F_49 ( V_104 ) ) ;
return V_58 ;
}
}
return F_50 ( V_34 , true ) ;
}
int F_99 ( struct V_33 * V_34 , int V_169 )
{
int V_58 = 0 ;
if ( ! V_34 )
return - V_163 ;
if ( ! V_20 || ! V_20 -> V_99 || ! V_20 -> V_110 )
return - V_170 ;
switch ( V_169 ) {
case V_111 :
V_58 = V_20 -> V_110 ( V_34 , V_169 ) ;
F_51 ( V_34 , V_38 ) ;
if ( V_58 )
break;
V_58 = F_97 ( V_34 ) ;
break;
case V_113 :
case V_115 :
V_20 -> V_99 ( V_34 , V_97 ) ;
F_23 ( V_34 , V_38 ) ;
V_58 = V_20 -> V_110 ( V_34 , V_169 ) ;
break;
default:
F_33 ( L_57 ,
V_61 , V_169 ) ;
V_58 = - V_98 ;
}
return V_58 ;
}
int F_100 ( struct V_33 * V_34 )
{
int V_58 = 0 ;
if ( ! V_34 )
return - V_163 ;
return V_58 ;
}
int F_101 ( struct V_33 * V_34 , int type , int V_183 ,
unsigned long V_79 , unsigned long V_184 )
{
if ( ! V_34 )
return - V_163 ;
if ( ! V_20 || ! V_20 -> V_185 )
return - V_170 ;
if ( type != V_186 && type != V_187 )
return - V_98 ;
if ( V_183 < V_188 || V_183 > V_189 )
return - V_98 ;
return V_20 -> V_185 ( V_34 , type , V_183 , V_79 , V_184 ) ;
}
static int F_102 ( struct V_190 * V_191 , void * V_192 )
{
if ( ! F_30 () ) {
F_103 ( V_191 , L_58 ) ;
F_103 ( V_191 , L_59 , V_75 . V_76 ) ;
} else {
F_103 ( V_191 , L_60 ) ;
F_103 ( V_191 ,
L_61
L_62
L_63
L_64
L_59
L_65
L_66 ,
V_75 . V_91 ,
V_75 . V_77 ,
V_75 . V_81 ,
V_75 . V_78 ,
V_75 . V_76 ,
V_75 . V_87 ,
V_75 . V_89 ) ;
}
return 0 ;
}
static int F_104 ( struct V_193 * V_193 , struct V_194 * V_194 )
{
return F_105 ( V_194 , F_102 , NULL ) ;
}
static int F_106 ( void * V_31 , T_7 V_195 )
{
if ( V_195 )
F_60 ( V_2 ) ;
else
F_2 ( V_2 ) ;
if ( V_20 -> V_138 )
V_20 -> V_138 () ;
return 0 ;
}
static int F_107 ( void * V_31 , T_7 * V_195 )
{
if ( F_30 () )
* V_195 = 0x1ul ;
else
* V_195 = 0x0ul ;
return 0 ;
}
static int F_108 ( void * V_31 , T_7 V_195 )
{
V_196 = V_195 ;
return 0 ;
}
static int F_109 ( void * V_31 , T_7 * V_195 )
{
* V_195 = V_196 ;
return 0 ;
}
static int T_1 F_110 ( void )
{
if ( F_62 ( V_197 ) || F_62 ( V_133 ) ) {
F_111 ( L_67 , 0 , NULL , & V_198 ) ;
#ifdef F_112
F_113 ( L_68 , 0600 ,
V_199 , NULL ,
& V_200 ) ;
F_113 ( L_69 , 0600 ,
V_199 , NULL ,
& V_201 ) ;
#endif
}
return 0 ;
}

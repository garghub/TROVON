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
V_50 = F_17 ( V_53 . V_54 , V_49 ,
NULL , & V_52 ) ;
if ( ! V_50 )
return V_49 ;
F_18 ( V_52 ) ;
V_51 = F_19 ( * V_50 ) << V_55 ;
return V_51 | ( V_49 & ( V_56 - 1 ) ) ;
}
static int F_20 ( struct V_33 * V_34 )
{
struct V_33 * V_57 ;
unsigned long V_58 ;
int V_59 ;
if ( ! F_12 ( V_60 ) )
return - V_61 ;
V_57 = F_21 ( V_34 -> V_16 ) ;
if ( ! V_57 ) {
F_8 ( L_26 ,
V_62 , V_34 -> V_16 -> V_17 ) ;
return - V_63 ;
}
F_22 ( & V_58 ) ;
if ( V_57 -> V_46 & V_64 ) {
V_59 = 0 ;
goto V_65;
}
V_59 = V_20 -> V_66 ( V_57 , NULL ) ;
if ( ( V_59 < 0 ) ||
( V_59 == V_67 ) ||
( V_59 & ( V_68 | V_69 ) ) ==
( V_68 | V_69 ) ) {
V_59 = 0 ;
goto V_65;
}
F_23 ( V_57 , V_64 ) ;
F_24 ( V_58 ) ;
F_25 ( L_27 ,
V_57 -> V_16 -> V_17 , F_26 ( V_57 ) ) ;
F_27 () ;
F_28 ( V_57 ) ;
return 1 ;
V_65:
F_24 ( V_58 ) ;
return V_59 ;
}
int F_29 ( struct V_4 * V_5 )
{
int V_59 ;
int V_70 = ( V_68 | V_69 ) ;
unsigned long V_58 ;
struct V_8 * V_9 ;
struct V_71 * V_72 ;
struct V_33 * V_34 , * V_73 , * V_57 ;
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
V_59 = F_20 ( V_34 ) ;
if ( V_59 > 0 )
return V_59 ;
if ( F_35 ( V_34 ) )
return 0 ;
F_22 ( & V_58 ) ;
V_74 = 1 ;
if ( V_34 -> V_46 & V_64 ) {
V_34 -> V_83 ++ ;
if ( V_34 -> V_83 % V_84 == 0 ) {
V_9 = F_4 ( V_5 ) ;
if ( V_9 -> V_85 )
V_75 = F_36 ( V_9 -> V_85 , L_29 , NULL ) ;
F_37 ( V_86 L_30
L_31 ,
V_34 -> V_83 ,
V_75 ? V_75 : L_32 ,
F_38 ( V_72 ) , F_34 ( V_72 ) ) ;
F_37 ( V_86 L_33 ,
F_38 ( V_72 ) ) ;
F_27 () ;
}
goto V_87;
}
V_59 = V_20 -> V_66 ( V_34 , NULL ) ;
if ( ( V_59 < 0 ) ||
( V_59 == V_67 ) ||
( ( V_59 & V_70 ) == V_70 ) ) {
V_76 . V_88 ++ ;
V_34 -> V_88 ++ ;
V_74 = 0 ;
goto V_87;
}
V_73 = V_34 -> V_89 ;
while ( V_73 ) {
if ( V_73 -> type & V_41 )
break;
V_59 = V_20 -> V_66 ( V_73 , NULL ) ;
if ( V_59 > 0 &&
( V_59 & V_70 ) != V_70 )
V_34 = V_73 ;
V_73 = V_73 -> V_89 ;
}
V_76 . V_90 ++ ;
F_23 ( V_34 , V_64 ) ;
F_24 ( V_58 ) ;
V_57 = F_21 ( V_34 -> V_16 ) ;
F_25 ( L_34 ,
V_34 -> V_16 -> V_17 , V_34 -> V_80 ) ;
F_25 ( L_35 ,
F_26 ( V_34 ) , F_26 ( V_57 ) ) ;
F_27 () ;
F_28 ( V_34 ) ;
return 1 ;
V_87:
F_24 ( V_58 ) ;
return V_74 ;
}
int F_39 ( const volatile void T_5 * V_49 )
{
unsigned long V_80 ;
struct V_4 * V_5 ;
V_80 = F_16 ( ( unsigned long V_91 ) V_49 ) ;
V_5 = F_40 ( V_80 ) ;
if ( ! V_5 ) {
V_76 . V_92 ++ ;
return 0 ;
}
return F_29 ( V_5 ) ;
}
int F_13 ( struct V_33 * V_34 , int V_93 )
{
int V_94 , V_74 ;
switch ( V_93 ) {
case V_44 :
V_94 = V_68 | V_95 ;
break;
case V_96 :
V_94 = V_69 ;
break;
case V_97 :
case V_98 :
case V_99 :
V_94 = 0 ;
break;
default:
F_8 ( L_36 ,
V_62 , V_93 ) ;
return - V_100 ;
}
if ( V_94 ) {
V_74 = V_20 -> V_66 ( V_34 , NULL ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_74 == V_67 )
return 0 ;
if ( V_74 & V_94 )
return 0 ;
}
V_74 = V_20 -> V_101 ( V_34 , V_93 ) ;
if ( V_74 )
F_8 ( L_37
L_38 ,
V_62 , V_93 , V_34 -> V_16 -> V_17 ,
V_34 -> V_80 , V_74 ) ;
if ( V_94 ) {
V_74 = V_20 -> V_102 ( V_34 , V_103 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_74 & V_94 )
return 0 ;
return - V_104 ;
}
return V_74 ;
}
static void * F_41 ( void * V_31 , void * V_105 )
{
struct V_4 * V_5 = V_31 ;
struct V_71 * V_106 = F_31 ( V_5 ) ;
struct V_71 * V_72 = V_105 ;
if ( ! V_106 || V_106 == V_72 )
return NULL ;
F_42 ( V_106 , V_107 ) ;
F_43 ( V_106 ) ;
F_44 ( V_106 , V_23 , V_108 ) ;
return NULL ;
}
static void * F_45 ( void * V_31 , void * V_105 )
{
struct V_4 * V_5 = V_31 ;
struct V_8 * V_9 = F_4 ( V_5 ) ;
struct V_71 * V_106 = F_31 ( V_5 ) ;
struct V_71 * V_72 = V_105 ;
if ( ! V_106 )
return NULL ;
if ( V_9 && V_20 -> V_109 )
V_20 -> V_109 ( V_9 ) ;
if ( V_106 != V_72 )
F_46 ( V_106 ) ;
return NULL ;
}
int F_47 ( struct V_71 * V_72 , enum V_110 V_46 )
{
struct V_4 * V_5 = F_48 ( V_72 ) ;
struct V_33 * V_34 = F_32 ( V_5 ) ;
if ( ! V_34 ) {
F_25 ( L_39 ,
V_62 , F_49 ( V_72 ) ) ;
return - V_100 ;
}
switch ( V_46 ) {
case V_111 :
V_20 -> V_112 ( V_34 , V_113 ) ;
F_50 ( V_34 , false ) ;
if ( ! ( V_34 -> type & V_114 ) )
F_51 ( V_34 , V_47 ) ;
F_52 ( V_34 , F_45 , V_72 ) ;
F_51 ( V_34 , V_64 ) ;
break;
case V_115 :
F_53 ( V_34 , V_64 ) ;
V_20 -> V_101 ( V_34 , V_99 ) ;
F_52 ( V_34 , F_41 , V_72 ) ;
if ( ! ( V_34 -> type & V_114 ) )
F_23 ( V_34 , V_47 ) ;
V_20 -> V_112 ( V_34 , V_116 ) ;
break;
case V_117 :
F_53 ( V_34 , V_64 ) ;
V_20 -> V_101 ( V_34 , V_99 ) ;
F_52 ( V_34 , F_41 , V_72 ) ;
if ( ! ( V_34 -> type & V_114 ) )
F_23 ( V_34 , V_47 ) ;
V_20 -> V_112 ( V_34 , V_118 ) ;
break;
default:
F_51 ( V_34 , V_64 | V_47 ) ;
return - V_100 ;
} ;
return 0 ;
}
static void * F_54 ( void * V_31 , void * V_32 )
{
struct V_71 * V_72 ;
unsigned int * V_119 = ( unsigned int * ) V_32 ;
struct V_4 * V_5 = (struct V_4 * ) V_31 ;
V_72 = F_31 ( V_5 ) ;
if ( V_72 )
* V_119 |= V_72 -> V_120 ;
return NULL ;
}
int F_55 ( struct V_33 * V_34 )
{
int V_70 = ( V_68 | V_69 ) ;
int V_121 = ( V_122 | V_47 ) ;
int type = V_116 ;
unsigned int V_119 = 0 ;
int V_12 , V_46 , V_59 ;
F_52 ( V_34 , F_54 , & V_119 ) ;
if ( V_119 )
type = V_118 ;
F_23 ( V_34 , V_121 ) ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
V_59 = F_56 ( V_34 , type ) ;
if ( V_59 )
break;
V_59 = F_56 ( V_34 , V_113 ) ;
if ( V_59 )
break;
V_46 = V_20 -> V_102 ( V_34 , V_103 ) ;
if ( ( V_46 & V_70 ) == V_70 )
break;
if ( V_46 < 0 ) {
F_8 ( L_40 ,
V_62 , V_34 -> V_16 -> V_17 , V_34 -> V_80 ) ;
V_59 = - V_123 ;
break;
}
V_59 = - V_104 ;
F_8 ( L_41 ,
V_62 , V_46 , V_34 -> V_16 -> V_17 , V_34 -> V_80 , ( V_12 + 1 ) ) ;
}
F_51 ( V_34 , V_121 ) ;
return V_59 ;
}
void F_57 ( struct V_4 * V_5 )
{
struct V_8 * V_9 ;
int V_12 ;
V_9 = F_4 ( V_5 ) ;
if ( ! V_9 )
return;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
V_20 -> V_21 ( V_9 , V_12 * 4 , 4 , & V_5 -> V_124 [ V_12 ] ) ;
if ( V_5 -> V_24 & V_25 )
V_5 -> V_124 [ 1 ] |= V_125 ;
}
int T_1 F_58 ( struct V_20 * V_126 )
{
if ( ! V_126 -> V_127 ) {
F_8 ( L_42 ,
V_62 , V_126 ) ;
return - V_100 ;
}
if ( V_20 && V_20 != V_126 ) {
F_8 ( L_43 ,
V_62 , V_20 -> V_127 , V_126 -> V_127 ) ;
return - V_63 ;
}
V_20 = V_126 ;
return 0 ;
}
int T_6 F_59 ( const char * V_127 )
{
if ( ! V_127 || ! strlen ( V_127 ) ) {
F_8 ( L_44 ,
V_62 ) ;
return - V_100 ;
}
if ( V_20 && ! strcmp ( V_20 -> V_127 , V_127 ) ) {
V_20 = NULL ;
return 0 ;
}
return - V_63 ;
}
static int F_60 ( struct V_128 * V_129 ,
unsigned long V_130 , void * V_131 )
{
F_61 ( V_132 ) ;
return V_133 ;
}
int F_62 ( void )
{
struct V_134 * V_135 , * V_35 ;
struct V_8 * V_9 ;
static int V_136 = 0 ;
int V_59 = 0 ;
if ( F_63 ( V_137 ) && V_136 ++ <= 0 )
return V_59 ;
V_59 = F_64 ( & V_138 ) ;
if ( V_59 ) {
F_8 ( L_45 ,
V_62 , V_59 ) ;
return V_59 ;
}
if ( ! V_20 ) {
F_8 ( L_46 ,
V_62 ) ;
return - V_63 ;
} else if ( ( V_59 = V_20 -> V_139 () ) )
return V_59 ;
V_59 = F_65 () ;
if ( V_59 )
return V_59 ;
F_66 (hose, tmp, &hose_list, list_node) {
V_9 = V_135 -> V_140 ;
F_67 ( V_9 , V_20 -> V_141 , NULL ) ;
}
if ( V_20 -> V_142 ) {
V_59 = V_20 -> V_142 () ;
if ( V_59 )
return V_59 ;
}
if ( F_30 () )
F_68 ( L_47 ) ;
else
F_68 ( L_48 ) ;
return V_59 ;
}
void F_69 ( struct V_8 * V_9 )
{
struct V_134 * V_16 ;
struct V_4 * V_5 = F_70 ( V_9 ) ;
if ( ! V_5 )
return;
if ( ! F_12 ( V_143 ) )
return;
V_16 = V_5 -> V_16 ;
if ( NULL == V_16 ||
( F_12 ( V_143 ) && 0 == V_16 -> V_144 ) )
return;
V_20 -> V_141 ( V_9 , NULL ) ;
}
void F_71 ( struct V_8 * V_9 )
{
struct V_8 * V_13 ;
if ( ! V_9 )
return;
F_72 (n, &pdn->child_list, list)
F_71 ( V_13 ) ;
F_69 ( V_9 ) ;
}
void F_73 ( struct V_71 * V_72 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
if ( ! V_72 || ! F_30 () )
return;
F_33 ( L_49 , F_49 ( V_72 ) ) ;
V_9 = F_74 ( V_72 -> V_145 , V_72 -> V_19 ) ;
V_5 = F_70 ( V_9 ) ;
if ( V_5 -> V_106 == V_72 ) {
F_33 ( L_50 ) ;
return;
}
if ( V_5 -> V_106 ) {
F_75 ( V_5 ) ;
F_76 ( V_5 -> V_106 ) ;
F_77 ( V_5 -> V_106 ) ;
V_5 -> V_24 &= ~ V_146 ;
V_5 -> V_24 |= V_147 ;
V_5 -> V_106 = NULL ;
V_72 -> V_72 . V_148 . V_5 = NULL ;
}
if ( F_12 ( V_60 ) )
V_20 -> V_141 ( V_9 , NULL ) ;
V_5 -> V_106 = V_72 ;
V_72 -> V_72 . V_148 . V_5 = V_5 ;
F_78 ( V_72 ) ;
}
void F_79 ( struct V_149 * V_145 )
{
struct V_71 * V_72 ;
F_72 (dev, &bus->devices, bus_list) {
F_73 ( V_72 ) ;
if ( V_72 -> V_150 == V_151 ) {
struct V_149 * V_152 = V_72 -> V_153 ;
if ( V_152 )
F_79 ( V_152 ) ;
}
}
}
void F_80 ( struct V_149 * V_145 )
{
struct V_71 * V_72 ;
F_72 (dev, &bus->devices, bus_list) {
F_81 ( V_72 ) ;
if ( V_72 -> V_150 == V_151 ) {
struct V_149 * V_152 = V_72 -> V_153 ;
if ( V_152 )
F_80 ( V_152 ) ;
}
}
}
void F_82 ( struct V_71 * V_72 )
{
struct V_4 * V_5 ;
if ( ! V_72 || ! F_30 () )
return;
V_5 = F_48 ( V_72 ) ;
F_33 ( L_51 , F_49 ( V_72 ) ) ;
if ( ! V_5 || ! V_5 -> V_106 || ! V_5 -> V_34 ) {
F_33 ( L_52 ) ;
return;
}
V_5 -> V_106 = NULL ;
V_5 -> V_154 = false ;
V_72 -> V_72 . V_148 . V_5 = NULL ;
if ( ! ( V_5 -> V_34 -> V_46 & V_155 ) )
F_75 ( V_5 ) ;
else
V_5 -> V_24 |= V_156 ;
V_5 -> V_24 |= V_147 ;
F_76 ( V_72 ) ;
F_77 ( V_72 ) ;
V_5 -> V_24 &= ~ V_146 ;
}
int F_50 ( struct V_33 * V_34 , bool V_157 )
{
int V_59 ;
V_59 = F_13 ( V_34 , V_44 ) ;
if ( V_59 ) {
F_8 ( L_53 ,
V_62 , V_59 , V_34 -> V_16 -> V_17 , V_34 -> V_80 ) ;
return V_59 ;
}
V_59 = F_13 ( V_34 , V_96 ) ;
if ( V_59 ) {
F_8 ( L_54 ,
V_62 , V_59 , V_34 -> V_16 -> V_17 , V_34 -> V_80 ) ;
return V_59 ;
}
if ( V_157 && ( V_34 -> V_46 & V_64 ) )
F_51 ( V_34 , V_64 ) ;
return V_59 ;
}
static int F_83 ( struct V_33 * V_34 )
{
struct V_4 * V_5 , * V_35 ;
struct V_71 * V_106 ;
struct V_158 * V_159 ;
int V_58 , V_59 ;
V_58 = ( V_68 | V_69 ) ;
V_59 = V_20 -> V_66 ( V_34 , NULL ) ;
if ( V_59 < 0 || V_59 == V_67 )
return 0 ;
if ( ( V_59 & V_58 ) == V_58 )
return 0 ;
F_10 (pe, edev, tmp) {
V_106 = F_31 ( V_5 ) ;
if ( ! V_106 )
continue;
for ( V_159 = & V_160 [ 0 ] ; V_159 -> V_161 != 0 ; V_159 ++ ) {
if ( V_159 -> V_161 != V_162 &&
V_159 -> V_161 != V_106 -> V_161 )
continue;
if ( V_159 -> V_163 != V_162 &&
V_159 -> V_163 != V_106 -> V_163 )
continue;
if ( V_159 -> V_164 != V_162 &&
V_159 -> V_164 != V_106 -> V_165 )
continue;
if ( V_159 -> V_166 != V_162 &&
V_159 -> V_166 != V_106 -> V_167 )
continue;
return F_84 ( V_34 ) ;
}
}
return F_50 ( V_34 , true ) ;
}
int F_85 ( struct V_71 * V_106 )
{
struct V_4 * V_5 ;
int V_59 = - V_168 ;
F_86 ( & V_169 ) ;
if ( ! V_106 )
goto V_65;
V_5 = F_48 ( V_106 ) ;
if ( ! V_5 || ! V_5 -> V_34 )
goto V_65;
V_59 = F_83 ( V_5 -> V_34 ) ;
if ( V_59 )
goto V_65;
F_87 ( & V_5 -> V_34 -> V_170 ) ;
F_88 ( & V_169 ) ;
return 0 ;
V_65:
F_88 ( & V_169 ) ;
return V_59 ;
}
void F_89 ( struct V_71 * V_106 )
{
struct V_4 * V_5 ;
F_86 ( & V_169 ) ;
if ( ! V_106 )
goto V_65;
V_5 = F_48 ( V_106 ) ;
if ( ! V_5 || ! V_5 -> V_34 || ! F_35 ( V_5 -> V_34 ) )
goto V_65;
F_18 ( F_90 ( & V_5 -> V_34 -> V_170 ) < 0 ) ;
F_83 ( V_5 -> V_34 ) ;
V_65:
F_88 ( & V_169 ) ;
}
static int F_91 ( struct V_163 * V_72 , void * V_31 )
{
struct V_71 * V_106 = F_92 ( V_72 ) ;
struct V_71 * * V_171 = V_31 ;
if ( ! V_72 )
return 0 ;
if ( V_72 -> V_172 ) {
* V_171 = V_106 ;
return 1 ;
}
return 0 ;
}
struct V_33 * F_93 ( struct V_172 * V_173 )
{
struct V_71 * V_106 = NULL ;
struct V_4 * V_5 ;
int V_59 ;
if ( ! V_173 )
return NULL ;
V_59 = F_94 ( V_173 , & V_106 , F_91 ) ;
if ( ! V_59 || ! V_106 )
return NULL ;
V_5 = F_48 ( V_106 ) ;
if ( ! V_5 || ! V_5 -> V_34 )
return NULL ;
return V_5 -> V_34 ;
}
int F_95 ( struct V_33 * V_34 , int V_174 )
{
int V_59 = 0 ;
if ( ! V_34 )
return - V_168 ;
switch ( V_174 ) {
case V_98 :
if ( F_30 () ) {
V_59 = F_83 ( V_34 ) ;
break;
}
V_59 = - V_104 ;
break;
case V_97 :
break;
case V_44 :
case V_96 :
case V_99 :
if ( ! V_20 || ! V_20 -> V_101 ) {
V_59 = - V_175 ;
break;
}
V_59 = F_13 ( V_34 , V_174 ) ;
break;
default:
F_33 ( L_55 ,
V_62 , V_174 , V_97 , V_96 ) ;
V_59 = - V_100 ;
}
return V_59 ;
}
int F_96 ( struct V_33 * V_34 )
{
int V_176 , V_59 = 0 ;
bool V_177 , V_178 , V_179 ;
if ( ! V_34 )
return - V_168 ;
if ( ! V_20 || ! V_20 -> V_66 )
return - V_175 ;
if ( V_34 -> V_89 &&
! ( V_34 -> V_46 & V_180 ) &&
( V_34 -> V_89 -> V_46 & ( V_64 | V_181 ) ) )
return V_182 ;
V_176 = V_20 -> V_66 ( V_34 , NULL ) ;
V_177 = ! ! ( V_176 & V_183 ) ;
V_178 = ! ! ( V_176 & V_184 ) ;
V_179 = ! ! ( V_176 & V_95 ) ;
if ( V_177 )
V_59 = V_185 ;
else if ( V_178 && V_179 )
V_59 = V_186 ;
else if ( ! V_178 && ! V_179 )
V_59 = V_187 ;
else if ( ! V_178 && V_179 )
V_59 = V_188 ;
else
V_59 = V_182 ;
return V_59 ;
}
static int F_97 ( struct V_33 * V_34 )
{
struct V_4 * V_5 , * V_35 ;
struct V_71 * V_106 ;
int V_59 = 0 ;
F_14 ( V_34 ) ;
F_10 (pe, edev, tmp) {
V_106 = F_31 ( V_5 ) ;
if ( ! V_106 )
continue;
V_59 = F_98 ( V_106 ) ;
if ( V_59 ) {
F_8 ( L_56 ,
V_62 , V_59 , F_49 ( V_106 ) ) ;
return V_59 ;
}
}
return F_50 ( V_34 , true ) ;
}
int F_56 ( struct V_33 * V_34 , int V_174 )
{
int V_59 = 0 ;
if ( ! V_34 )
return - V_168 ;
if ( ! V_20 || ! V_20 -> V_101 || ! V_20 -> V_112 )
return - V_175 ;
switch ( V_174 ) {
case V_113 :
V_59 = V_20 -> V_112 ( V_34 , V_174 ) ;
F_51 ( V_34 , V_47 ) ;
if ( V_59 )
break;
V_59 = F_97 ( V_34 ) ;
break;
case V_116 :
case V_118 :
V_20 -> V_101 ( V_34 , V_99 ) ;
F_23 ( V_34 , V_47 ) ;
V_59 = V_20 -> V_112 ( V_34 , V_174 ) ;
break;
default:
F_33 ( L_57 ,
V_62 , V_174 ) ;
V_59 = - V_100 ;
}
return V_59 ;
}
int F_99 ( struct V_33 * V_34 )
{
int V_59 = 0 ;
if ( ! V_34 )
return - V_168 ;
return V_59 ;
}
int F_100 ( struct V_33 * V_34 , int type , int V_189 ,
unsigned long V_80 , unsigned long V_190 )
{
if ( ! V_34 )
return - V_168 ;
if ( ! V_20 || ! V_20 -> V_191 )
return - V_175 ;
if ( type != V_192 && type != V_193 )
return - V_100 ;
if ( V_189 < V_194 || V_189 > V_195 )
return - V_100 ;
return V_20 -> V_191 ( V_34 , type , V_189 , V_80 , V_190 ) ;
}
static int F_101 ( struct V_196 * V_197 , void * V_198 )
{
if ( ! F_30 () ) {
F_102 ( V_197 , L_58 ) ;
F_102 ( V_197 , L_59 , V_76 . V_77 ) ;
} else {
F_102 ( V_197 , L_60 ) ;
F_102 ( V_197 ,
L_61
L_62
L_63
L_64
L_59
L_65
L_66 ,
V_76 . V_92 ,
V_76 . V_78 ,
V_76 . V_82 ,
V_76 . V_79 ,
V_76 . V_77 ,
V_76 . V_88 ,
V_76 . V_90 ) ;
}
return 0 ;
}
static int F_103 ( struct V_199 * V_199 , struct V_200 * V_200 )
{
return F_104 ( V_200 , F_101 , NULL ) ;
}
static int F_105 ( void * V_31 , T_7 V_201 )
{
if ( V_201 )
F_61 ( V_2 ) ;
else
F_2 ( V_2 ) ;
if ( V_20 -> V_142 )
V_20 -> V_142 () ;
return 0 ;
}
static int F_106 ( void * V_31 , T_7 * V_201 )
{
if ( F_30 () )
* V_201 = 0x1ul ;
else
* V_201 = 0x0ul ;
return 0 ;
}
static int F_107 ( void * V_31 , T_7 V_201 )
{
V_202 = V_201 ;
return 0 ;
}
static int F_108 ( void * V_31 , T_7 * V_201 )
{
* V_201 = V_202 ;
return 0 ;
}
static int T_1 F_109 ( void )
{
if ( F_63 ( V_203 ) || F_63 ( V_137 ) ) {
F_110 ( L_67 , 0 , NULL , & V_204 ) ;
#ifdef F_111
F_112 ( L_68 , 0600 ,
V_205 , NULL ,
& V_206 ) ;
F_112 ( L_69 , 0600 ,
V_205 , NULL ,
& V_207 ) ;
#endif
}
return 0 ;
}

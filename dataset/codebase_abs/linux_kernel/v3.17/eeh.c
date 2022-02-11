static int T_1 F_1 ( char * V_1 )
{
if ( ! strcmp ( V_1 , L_1 ) )
F_2 ( V_2 ) ;
return 1 ;
}
static T_2 F_3 ( struct V_3 * V_4 , char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_4 ( V_4 ) ;
T_3 V_9 ;
int V_10 , V_11 ;
int V_12 = 0 , V_13 = 0 ;
char V_14 [ 128 ] ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_2 , V_8 -> V_15 ) ;
F_6 ( L_3 , V_8 -> V_15 ) ;
V_16 -> V_17 ( V_8 , V_18 , 4 , & V_9 ) ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_4 , V_9 ) ;
F_6 ( L_5 , V_9 ) ;
V_16 -> V_17 ( V_8 , V_19 , 4 , & V_9 ) ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_6 , V_9 ) ;
F_6 ( L_7 , V_9 ) ;
if ( V_4 -> V_20 & V_21 ) {
V_16 -> V_17 ( V_8 , V_22 , 2 , & V_9 ) ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_8 , V_9 ) ;
F_6 ( L_9 , V_9 ) ;
V_16 -> V_17 ( V_8 , V_23 , 2 , & V_9 ) ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_10 , V_9 ) ;
F_6 ( L_11 , V_9 ) ;
}
V_10 = V_4 -> V_24 ;
if ( V_10 ) {
V_16 -> V_17 ( V_8 , V_10 , 4 , & V_9 ) ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_12 , V_9 ) ;
F_6 ( L_13 , V_9 ) ;
V_16 -> V_17 ( V_8 , V_10 + 4 , 4 , & V_9 ) ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_14 , V_9 ) ;
F_6 ( L_15 , V_9 ) ;
}
V_10 = V_4 -> V_25 ;
if ( V_10 ) {
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_16 ) ;
F_6 ( L_17 ) ;
for ( V_11 = 0 ; V_11 <= 8 ; V_11 ++ ) {
V_16 -> V_17 ( V_8 , V_10 + 4 * V_11 , 4 , & V_9 ) ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_18 , 4 * V_11 , V_9 ) ;
if ( ( V_11 % 4 ) == 0 ) {
if ( V_11 != 0 )
F_6 ( L_2 , V_14 ) ;
V_13 = F_5 ( V_14 , sizeof( V_14 ) ,
L_19 ,
4 * V_11 , V_9 ) ;
} else {
V_13 += F_5 ( V_14 + V_13 , sizeof( V_14 ) - V_13 ,
L_20 , V_9 ) ;
}
}
F_6 ( L_2 , V_14 ) ;
}
V_10 = V_4 -> V_26 ;
if ( V_10 ) {
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_21 ) ;
F_6 ( L_22 ) ;
for ( V_11 = 0 ; V_11 <= 13 ; V_11 ++ ) {
V_16 -> V_17 ( V_8 , V_10 + 4 * V_11 , 4 , & V_9 ) ;
V_12 += F_5 ( V_5 + V_12 , V_6 - V_12 , L_18 , 4 * V_11 , V_9 ) ;
if ( ( V_11 % 4 ) == 0 ) {
if ( V_11 != 0 )
F_6 ( L_2 , V_14 ) ;
V_13 = F_5 ( V_14 , sizeof( V_14 ) ,
L_23 ,
4 * V_11 , V_9 ) ;
} else {
V_13 += F_5 ( V_14 + V_13 , sizeof( V_14 ) - V_13 ,
L_20 , V_9 ) ;
}
}
F_6 ( L_2 , V_14 ) ;
}
return V_12 ;
}
void F_7 ( struct V_27 * V_28 , int V_29 )
{
T_2 V_30 = 0 ;
struct V_3 * V_4 , * V_31 ;
if ( ! ( V_28 -> type & V_32 ) ) {
if ( F_8 ( V_33 ) )
F_9 ( V_28 , V_34 ) ;
V_16 -> V_35 ( V_28 ) ;
F_10 ( V_28 ) ;
V_36 [ 0 ] = 0 ;
F_11 (pe, edev, tmp) {
V_30 += F_3 ( V_4 , V_36 + V_30 ,
V_37 - V_30 ) ;
}
}
V_16 -> V_38 ( V_28 , V_29 , V_36 , V_30 ) ;
}
static inline unsigned long F_12 ( unsigned long V_39 )
{
T_4 * V_40 ;
unsigned long V_41 ;
int V_42 ;
V_40 = F_13 ( V_43 . V_44 , V_39 , & V_42 ) ;
if ( ! V_40 )
return V_39 ;
F_14 ( V_42 ) ;
V_41 = F_15 ( * V_40 ) << V_45 ;
return V_41 | ( V_39 & ( V_46 - 1 ) ) ;
}
static int F_16 ( struct V_27 * V_28 )
{
struct V_27 * V_47 ;
unsigned long V_48 ;
int V_49 ;
if ( ! F_8 ( V_50 ) )
return - V_51 ;
V_47 = F_17 ( V_28 -> V_52 ) ;
if ( ! V_47 ) {
F_6 ( L_24 ,
V_53 , V_28 -> V_52 -> V_54 ) ;
return - V_55 ;
}
F_18 ( & V_48 ) ;
if ( V_47 -> V_56 & V_57 ) {
V_49 = 0 ;
goto V_58;
}
V_49 = V_16 -> V_59 ( V_47 , NULL ) ;
if ( ( V_49 < 0 ) ||
( V_49 == V_60 ) ||
( V_49 & ( V_61 | V_62 ) ) ==
( V_61 | V_62 ) ) {
V_49 = 0 ;
goto V_58;
}
F_19 ( V_47 , V_57 ) ;
F_20 ( V_48 ) ;
F_21 ( L_25 ,
V_47 -> V_52 -> V_54 , F_22 ( V_47 ) ) ;
F_23 () ;
F_24 ( V_47 ) ;
return 1 ;
V_58:
F_20 ( V_48 ) ;
return V_49 ;
}
int F_25 ( struct V_3 * V_4 )
{
int V_49 ;
int V_63 = ( V_61 | V_62 ) ;
unsigned long V_48 ;
struct V_7 * V_8 ;
struct V_64 * V_65 ;
struct V_27 * V_28 , * V_66 , * V_47 ;
int V_67 = 0 ;
const char * V_68 ;
V_69 . V_70 ++ ;
if ( ! F_26 () )
return 0 ;
if ( ! V_4 ) {
V_69 . V_71 ++ ;
return 0 ;
}
V_8 = F_4 ( V_4 ) ;
V_65 = F_27 ( V_4 ) ;
V_28 = V_4 -> V_28 ;
if ( ! V_28 ) {
V_69 . V_72 ++ ;
F_28 ( L_26 ,
F_29 ( V_65 ) , V_8 -> V_15 ) ;
return 0 ;
}
if ( ! V_28 -> V_73 && ! V_28 -> V_74 ) {
V_69 . V_75 ++ ;
return 0 ;
}
V_49 = F_16 ( V_28 ) ;
if ( V_49 > 0 )
return V_49 ;
if ( F_30 ( V_28 ) )
return 0 ;
F_18 ( & V_48 ) ;
V_67 = 1 ;
if ( V_28 -> V_56 & V_57 ) {
V_28 -> V_76 ++ ;
if ( V_28 -> V_76 % V_77 == 0 ) {
V_68 = F_31 ( V_8 , L_27 , NULL ) ;
F_32 ( V_78 L_28
L_29 ,
V_28 -> V_76 , V_68 ,
F_33 ( V_65 ) , F_29 ( V_65 ) ) ;
F_32 ( V_78 L_30 ,
F_33 ( V_65 ) ) ;
F_23 () ;
}
goto V_79;
}
V_49 = V_16 -> V_59 ( V_28 , NULL ) ;
if ( ( V_49 < 0 ) ||
( V_49 == V_60 ) ||
( ( V_49 & V_63 ) == V_63 ) ) {
V_69 . V_80 ++ ;
V_28 -> V_80 ++ ;
V_67 = 0 ;
goto V_79;
}
V_66 = V_28 -> V_81 ;
while ( V_66 ) {
if ( V_66 -> type & V_32 )
break;
V_49 = V_16 -> V_59 ( V_66 , NULL ) ;
if ( V_49 > 0 &&
( V_49 & V_63 ) != V_63 )
V_28 = V_66 ;
V_66 = V_66 -> V_81 ;
}
V_69 . V_82 ++ ;
F_19 ( V_28 , V_57 ) ;
F_20 ( V_48 ) ;
V_47 = F_17 ( V_28 -> V_52 ) ;
F_21 ( L_31 ,
V_28 -> V_52 -> V_54 , V_28 -> V_73 ) ;
F_21 ( L_32 ,
F_22 ( V_28 ) , F_22 ( V_47 ) ) ;
F_23 () ;
F_24 ( V_28 ) ;
return 1 ;
V_79:
F_20 ( V_48 ) ;
return V_67 ;
}
unsigned long F_34 ( const volatile void T_5 * V_39 , unsigned long V_83 )
{
unsigned long V_73 ;
struct V_3 * V_4 ;
V_73 = F_12 ( ( unsigned long V_84 ) V_39 ) ;
V_4 = F_35 ( V_73 ) ;
if ( ! V_4 ) {
V_69 . V_85 ++ ;
return V_83 ;
}
F_25 ( V_4 ) ;
return V_83 ;
}
int F_9 ( struct V_27 * V_28 , int V_86 )
{
int V_67 , V_48 = ( V_61 | V_62 ) ;
if ( V_86 == V_34 ||
V_86 == V_87 ) {
V_67 = V_16 -> V_59 ( V_28 , NULL ) ;
if ( V_67 < 0 )
return V_67 ;
if ( ( V_67 == V_60 ) ||
( ( V_67 & V_48 ) == V_48 ) )
return 0 ;
}
V_67 = V_16 -> V_88 ( V_28 , V_86 ) ;
if ( V_67 )
F_6 ( L_33
L_34 ,
V_53 , V_86 , V_28 -> V_52 -> V_54 ,
V_28 -> V_73 , V_67 ) ;
V_67 = V_16 -> V_89 ( V_28 , V_90 ) ;
if ( V_67 <= 0 )
return V_67 ;
if ( ( V_86 == V_34 ) &&
( V_67 & V_91 ) )
return 0 ;
if ( ( V_86 == V_87 ) &&
( V_67 & V_92 ) )
return 0 ;
return V_67 ;
}
int F_36 ( struct V_64 * V_65 , enum V_93 V_56 )
{
struct V_3 * V_4 = F_37 ( V_65 ) ;
struct V_27 * V_28 = V_4 -> V_28 ;
if ( ! V_28 ) {
F_21 ( L_35 ,
V_53 , F_38 ( V_65 ) ) ;
return - V_94 ;
}
switch ( V_56 ) {
case V_95 :
V_16 -> V_96 ( V_28 , V_97 ) ;
break;
case V_98 :
V_16 -> V_96 ( V_28 , V_99 ) ;
break;
case V_100 :
V_16 -> V_96 ( V_28 , V_101 ) ;
break;
default:
return - V_94 ;
} ;
return 0 ;
}
static void * F_39 ( void * V_102 , void * V_103 )
{
struct V_64 * V_65 ;
unsigned int * V_104 = ( unsigned int * ) V_103 ;
struct V_3 * V_4 = (struct V_3 * ) V_102 ;
V_65 = F_27 ( V_4 ) ;
if ( V_65 )
* V_104 |= V_65 -> V_105 ;
return NULL ;
}
static void F_40 ( struct V_27 * V_28 )
{
unsigned int V_104 = 0 ;
F_41 ( V_28 , F_39 , & V_104 ) ;
if ( V_104 )
V_16 -> V_96 ( V_28 , V_101 ) ;
else
V_16 -> V_96 ( V_28 , V_99 ) ;
V_16 -> V_96 ( V_28 , V_97 ) ;
}
int F_42 ( struct V_27 * V_28 )
{
int V_48 = ( V_61 | V_62 ) ;
int V_11 , V_67 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
F_40 ( V_28 ) ;
V_67 = V_16 -> V_89 ( V_28 , V_90 ) ;
if ( ( V_67 & V_48 ) == V_48 )
return 0 ;
if ( V_67 < 0 ) {
F_21 ( L_36 ,
V_53 , V_28 -> V_52 -> V_54 , V_28 -> V_73 ) ;
return - 1 ;
}
F_21 ( L_37 ,
V_11 + 1 , V_28 -> V_52 -> V_54 , V_28 -> V_73 , V_67 ) ;
}
return - 1 ;
}
void F_43 ( struct V_3 * V_4 )
{
int V_11 ;
struct V_7 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_4 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_16 -> V_17 ( V_8 , V_11 * 4 , 4 , & V_4 -> V_106 [ V_11 ] ) ;
if ( V_4 -> V_20 & V_21 )
V_4 -> V_106 [ 1 ] |= V_107 ;
}
int T_1 F_44 ( struct V_16 * V_108 )
{
if ( ! V_108 -> V_109 ) {
F_6 ( L_38 ,
V_53 , V_108 ) ;
return - V_94 ;
}
if ( V_16 && V_16 != V_108 ) {
F_6 ( L_39 ,
V_53 , V_16 -> V_109 , V_108 -> V_109 ) ;
return - V_55 ;
}
V_16 = V_108 ;
return 0 ;
}
int T_6 F_45 ( const char * V_109 )
{
if ( ! V_109 || ! strlen ( V_109 ) ) {
F_6 ( L_40 ,
V_53 ) ;
return - V_94 ;
}
if ( V_16 && ! strcmp ( V_16 -> V_109 , V_109 ) ) {
V_16 = NULL ;
return 0 ;
}
return - V_55 ;
}
static int F_46 ( struct V_110 * V_111 ,
unsigned long V_112 , void * V_113 )
{
F_47 ( V_114 ) ;
return V_115 ;
}
int F_48 ( void )
{
struct V_116 * V_117 , * V_31 ;
struct V_7 * V_52 ;
static int V_118 = 0 ;
int V_49 = 0 ;
if ( F_49 ( V_119 ) && V_118 ++ <= 0 )
return V_49 ;
V_49 = F_50 ( & V_120 ) ;
if ( V_49 ) {
F_6 ( L_41 ,
V_53 , V_49 ) ;
return V_49 ;
}
if ( ! V_16 ) {
F_6 ( L_42 ,
V_53 ) ;
return - V_55 ;
} else if ( ( V_49 = V_16 -> V_121 () ) ) {
F_6 ( L_43 ,
V_53 , V_49 ) ;
return V_49 ;
}
V_49 = F_51 () ;
if ( V_49 )
return V_49 ;
if ( F_8 ( V_122 ) ) {
F_52 (hose, tmp,
&hose_list, list_node) {
V_52 = V_117 -> V_8 ;
F_53 ( V_52 , V_16 -> V_123 , NULL ) ;
}
} else if ( F_8 ( V_50 ) ) {
F_52 (hose, tmp,
&hose_list, list_node)
F_54 ( V_117 -> V_124 , V_16 -> V_125 , NULL ) ;
} else {
F_6 ( L_44 ,
V_53 , V_126 ) ;
return - V_94 ;
}
if ( V_16 -> V_127 ) {
V_49 = V_16 -> V_127 () ;
if ( V_49 )
return V_49 ;
}
if ( F_26 () )
F_55 ( L_45 ) ;
else
F_6 ( L_46 ) ;
return V_49 ;
}
void F_56 ( struct V_7 * V_8 )
{
struct V_116 * V_52 ;
if ( ! F_8 ( V_122 ) )
return;
if ( ! F_57 ( V_8 ) )
return;
V_52 = F_57 ( V_8 ) -> V_52 ;
if ( NULL == V_52 || 0 == V_52 -> V_128 )
return;
V_16 -> V_123 ( V_8 , NULL ) ;
}
void F_58 ( struct V_7 * V_8 )
{
struct V_7 * V_129 ;
F_59 (dn, sib)
F_58 ( V_129 ) ;
F_56 ( V_8 ) ;
}
void F_60 ( struct V_64 * V_65 )
{
struct V_7 * V_8 ;
struct V_3 * V_4 ;
if ( ! V_65 || ! F_26 () )
return;
F_28 ( L_47 , F_38 ( V_65 ) ) ;
V_8 = F_61 ( V_65 ) ;
V_4 = F_57 ( V_8 ) ;
if ( V_4 -> V_130 == V_65 ) {
F_28 ( L_48 ) ;
return;
}
if ( V_4 -> V_130 ) {
F_62 ( V_4 ) ;
F_63 ( V_4 -> V_130 ) ;
F_64 ( V_4 -> V_130 ) ;
V_4 -> V_20 &= ~ V_131 ;
V_4 -> V_20 |= V_132 ;
V_4 -> V_130 = NULL ;
V_65 -> V_65 . V_133 . V_4 = NULL ;
}
V_4 -> V_130 = V_65 ;
V_65 -> V_65 . V_133 . V_4 = V_4 ;
if ( F_8 ( V_50 ) )
V_16 -> V_125 ( V_65 , NULL ) ;
F_65 ( V_65 ) ;
}
void F_66 ( struct V_134 * V_124 )
{
struct V_64 * V_65 ;
F_67 (dev, &bus->devices, bus_list) {
F_60 ( V_65 ) ;
if ( V_65 -> V_135 == V_136 ) {
struct V_134 * V_137 = V_65 -> V_138 ;
if ( V_137 )
F_66 ( V_137 ) ;
}
}
}
void F_68 ( struct V_134 * V_124 )
{
struct V_64 * V_65 ;
F_67 (dev, &bus->devices, bus_list) {
F_69 ( V_65 ) ;
if ( V_65 -> V_135 == V_136 ) {
struct V_134 * V_137 = V_65 -> V_138 ;
if ( V_137 )
F_68 ( V_137 ) ;
}
}
}
void F_70 ( struct V_64 * V_65 )
{
struct V_3 * V_4 ;
if ( ! V_65 || ! F_26 () )
return;
V_4 = F_37 ( V_65 ) ;
F_28 ( L_49 , F_38 ( V_65 ) ) ;
if ( ! V_4 || ! V_4 -> V_130 || ! V_4 -> V_28 ) {
F_28 ( L_50 ) ;
return;
}
V_4 -> V_130 = NULL ;
V_65 -> V_65 . V_133 . V_4 = NULL ;
if ( ! ( V_4 -> V_28 -> V_56 & V_139 ) )
F_62 ( V_4 ) ;
else
V_4 -> V_20 |= V_140 ;
V_4 -> V_20 |= V_132 ;
F_63 ( V_65 ) ;
F_64 ( V_65 ) ;
V_4 -> V_20 &= ~ V_131 ;
}
int F_71 ( struct V_64 * V_130 )
{
struct V_3 * V_4 ;
F_72 ( & V_141 ) ;
if ( ! V_130 )
goto V_58;
V_4 = F_37 ( V_130 ) ;
if ( ! V_4 || ! V_4 -> V_28 )
goto V_58;
F_73 ( & V_4 -> V_28 -> V_142 ) ;
F_74 ( & V_141 ) ;
return 0 ;
V_58:
F_74 ( & V_141 ) ;
return - V_143 ;
}
void F_75 ( struct V_64 * V_130 )
{
struct V_3 * V_4 ;
F_72 ( & V_141 ) ;
if ( ! V_130 )
goto V_58;
V_4 = F_37 ( V_130 ) ;
if ( ! V_4 || ! V_4 -> V_28 || ! F_30 ( V_4 -> V_28 ) )
goto V_58;
F_76 ( & V_4 -> V_28 -> V_142 ) ;
F_14 ( F_77 ( & V_4 -> V_28 -> V_142 ) < 0 ) ;
V_58:
F_74 ( & V_141 ) ;
}
static int F_78 ( struct V_144 * V_65 , void * V_102 )
{
struct V_64 * V_130 = F_79 ( V_65 ) ;
struct V_64 * * V_145 = V_102 ;
struct V_146 * V_147 ;
if ( ! V_65 )
return 0 ;
V_147 = F_80 ( V_65 ) ;
if ( V_147 && V_147 -> V_148 ) {
* V_145 = V_130 ;
return 1 ;
}
return 0 ;
}
struct V_27 * F_81 ( struct V_149 * V_150 )
{
struct V_64 * V_130 = NULL ;
struct V_3 * V_4 ;
int V_49 ;
if ( ! V_150 )
return NULL ;
V_49 = F_82 ( V_150 , & V_130 , F_78 ) ;
if ( ! V_49 || ! V_130 )
return NULL ;
V_4 = F_37 ( V_130 ) ;
if ( ! V_4 || ! V_4 -> V_28 )
return NULL ;
return V_4 -> V_28 ;
}
int F_83 ( struct V_27 * V_28 , int V_151 )
{
int V_49 = 0 ;
if ( ! V_28 )
return - V_143 ;
switch ( V_151 ) {
case V_152 :
if ( F_26 () )
break;
V_49 = - V_153 ;
break;
case V_154 :
break;
case V_34 :
case V_87 :
if ( ! V_16 || ! V_16 -> V_88 ) {
V_49 = - V_155 ;
break;
}
V_49 = V_16 -> V_88 ( V_28 , V_151 ) ;
break;
default:
F_28 ( L_51 ,
V_53 , V_151 , V_154 , V_87 ) ;
V_49 = - V_94 ;
}
return V_49 ;
}
int F_84 ( struct V_27 * V_28 )
{
int V_156 , V_49 = 0 ;
bool V_157 , V_158 , V_159 ;
if ( ! V_28 )
return - V_143 ;
if ( ! V_16 || ! V_16 -> V_59 )
return - V_155 ;
V_156 = V_16 -> V_59 ( V_28 , NULL ) ;
V_157 = ! ! ( V_156 & V_160 ) ;
V_158 = ! ! ( V_156 & V_92 ) ;
V_159 = ! ! ( V_156 & V_91 ) ;
if ( V_157 )
V_49 = V_161 ;
else if ( V_158 && V_159 )
V_49 = V_162 ;
else if ( ! V_158 && ! V_159 )
V_49 = V_163 ;
else if ( ! V_158 && V_159 )
V_49 = V_164 ;
else
V_49 = V_165 ;
return V_49 ;
}
int F_85 ( struct V_27 * V_28 , int V_151 )
{
int V_49 = 0 ;
if ( ! V_28 )
return - V_143 ;
if ( ! V_16 || ! V_16 -> V_88 || ! V_16 -> V_96 )
return - V_155 ;
switch ( V_151 ) {
case V_97 :
V_49 = V_16 -> V_96 ( V_28 , V_151 ) ;
if ( V_49 )
break;
V_49 = V_16 -> V_88 ( V_28 , V_34 ) ;
if ( ! V_49 )
V_49 = V_16 -> V_88 ( V_28 , V_87 ) ;
if ( ! V_49 )
F_86 ( V_28 , V_57 ) ;
break;
case V_99 :
case V_101 :
V_49 = V_16 -> V_96 ( V_28 , V_151 ) ;
break;
default:
F_28 ( L_52 ,
V_53 , V_151 ) ;
V_49 = - V_94 ;
}
return V_49 ;
}
int F_87 ( struct V_27 * V_28 )
{
int V_49 = 0 ;
if ( ! V_28 )
return - V_143 ;
F_10 ( V_28 ) ;
return V_49 ;
}
static int F_88 ( struct V_166 * V_167 , void * V_168 )
{
if ( ! F_26 () ) {
F_89 ( V_167 , L_53 ) ;
F_89 ( V_167 , L_54 , V_69 . V_70 ) ;
} else {
F_89 ( V_167 , L_55 ) ;
F_89 ( V_167 ,
L_56
L_57
L_58
L_59
L_54
L_60
L_61 ,
V_69 . V_85 ,
V_69 . V_71 ,
V_69 . V_75 ,
V_69 . V_72 ,
V_69 . V_70 ,
V_69 . V_80 ,
V_69 . V_82 ) ;
}
return 0 ;
}
static int F_90 ( struct V_169 * V_169 , struct V_170 * V_170 )
{
return F_91 ( V_170 , F_88 , NULL ) ;
}
static int F_92 ( void * V_102 , T_7 V_83 )
{
if ( V_83 )
F_47 ( V_2 ) ;
else
F_2 ( V_2 ) ;
if ( V_16 -> V_127 )
V_16 -> V_127 () ;
return 0 ;
}
static int F_93 ( void * V_102 , T_7 * V_83 )
{
if ( F_26 () )
* V_83 = 0x1ul ;
else
* V_83 = 0x0ul ;
return 0 ;
}
static int T_1 F_94 ( void )
{
if ( F_49 ( V_171 ) || F_49 ( V_119 ) ) {
F_95 ( L_62 , 0 , NULL , & V_172 ) ;
#ifdef F_96
F_97 ( L_63 , 0600 ,
V_173 , NULL ,
& V_174 ) ;
#endif
}
return 0 ;
}

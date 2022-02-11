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
static void * F_7 ( void * V_27 , void * V_28 )
{
struct V_29 * V_30 = V_27 ;
struct V_3 * V_4 , * V_31 ;
T_2 * V_32 = V_28 ;
if ( V_30 -> V_33 & V_34 )
return NULL ;
F_8 ( V_30 , V_4 , V_31 )
* V_32 += F_3 ( V_4 , V_35 + * V_32 ,
V_36 - * V_32 ) ;
return NULL ;
}
void F_9 ( struct V_29 * V_30 , int V_37 )
{
T_2 V_38 = 0 ;
if ( ! ( V_30 -> type & V_39 ) ) {
if ( F_10 ( V_40 ) )
F_11 ( V_30 , V_41 ) ;
V_16 -> V_42 ( V_30 ) ;
F_12 ( V_30 ) ;
V_35 [ 0 ] = 0 ;
F_13 ( V_30 , F_7 , & V_38 ) ;
}
V_16 -> V_43 ( V_30 , V_37 , V_35 , V_38 ) ;
}
static inline unsigned long F_14 ( unsigned long V_44 )
{
T_4 * V_45 ;
unsigned long V_46 ;
int V_47 ;
V_45 = F_15 ( V_48 . V_49 , V_44 , & V_47 ) ;
if ( ! V_45 )
return V_44 ;
F_16 ( V_47 ) ;
V_46 = F_17 ( * V_45 ) << V_50 ;
return V_46 | ( V_44 & ( V_51 - 1 ) ) ;
}
static int F_18 ( struct V_29 * V_30 )
{
struct V_29 * V_52 ;
unsigned long V_53 ;
int V_54 ;
if ( ! F_10 ( V_55 ) )
return - V_56 ;
V_52 = F_19 ( V_30 -> V_57 ) ;
if ( ! V_52 ) {
F_6 ( L_24 ,
V_58 , V_30 -> V_57 -> V_59 ) ;
return - V_60 ;
}
F_20 ( & V_53 ) ;
if ( V_52 -> V_33 & V_61 ) {
V_54 = 0 ;
goto V_62;
}
V_54 = V_16 -> V_63 ( V_52 , NULL ) ;
if ( ( V_54 < 0 ) ||
( V_54 == V_64 ) ||
( V_54 & ( V_65 | V_66 ) ) ==
( V_65 | V_66 ) ) {
V_54 = 0 ;
goto V_62;
}
F_21 ( V_52 , V_61 ) ;
F_22 ( V_53 ) ;
F_23 ( L_25 ,
V_52 -> V_57 -> V_59 , F_24 ( V_52 ) ) ;
F_25 () ;
F_26 ( V_52 ) ;
return 1 ;
V_62:
F_22 ( V_53 ) ;
return V_54 ;
}
int F_27 ( struct V_3 * V_4 )
{
int V_54 ;
int V_67 = ( V_65 | V_66 ) ;
unsigned long V_53 ;
struct V_7 * V_8 ;
struct V_68 * V_69 ;
struct V_29 * V_30 , * V_70 , * V_52 ;
int V_71 = 0 ;
const char * V_72 ;
V_73 . V_74 ++ ;
if ( ! F_28 () )
return 0 ;
if ( ! V_4 ) {
V_73 . V_75 ++ ;
return 0 ;
}
V_8 = F_4 ( V_4 ) ;
V_69 = F_29 ( V_4 ) ;
V_30 = F_30 ( V_4 ) ;
if ( ! V_30 ) {
V_73 . V_76 ++ ;
F_31 ( L_26 ,
F_32 ( V_69 ) , V_8 -> V_15 ) ;
return 0 ;
}
if ( ! V_30 -> V_77 && ! V_30 -> V_78 ) {
V_73 . V_79 ++ ;
return 0 ;
}
V_54 = F_18 ( V_30 ) ;
if ( V_54 > 0 )
return V_54 ;
if ( F_33 ( V_30 ) )
return 0 ;
F_20 ( & V_53 ) ;
V_71 = 1 ;
if ( V_30 -> V_33 & V_61 ) {
V_30 -> V_80 ++ ;
if ( V_30 -> V_80 % V_81 == 0 ) {
V_72 = F_34 ( V_8 , L_27 , NULL ) ;
F_35 ( V_82 L_28
L_29 ,
V_30 -> V_80 , V_72 ,
F_36 ( V_69 ) , F_32 ( V_69 ) ) ;
F_35 ( V_82 L_30 ,
F_36 ( V_69 ) ) ;
F_25 () ;
}
goto V_83;
}
V_54 = V_16 -> V_63 ( V_30 , NULL ) ;
if ( ( V_54 < 0 ) ||
( V_54 == V_64 ) ||
( ( V_54 & V_67 ) == V_67 ) ) {
V_73 . V_84 ++ ;
V_30 -> V_84 ++ ;
V_71 = 0 ;
goto V_83;
}
V_70 = V_30 -> V_85 ;
while ( V_70 ) {
if ( V_70 -> type & V_39 )
break;
V_54 = V_16 -> V_63 ( V_70 , NULL ) ;
if ( V_54 > 0 &&
( V_54 & V_67 ) != V_67 )
V_30 = V_70 ;
V_70 = V_70 -> V_85 ;
}
V_73 . V_86 ++ ;
F_21 ( V_30 , V_61 ) ;
F_22 ( V_53 ) ;
V_52 = F_19 ( V_30 -> V_57 ) ;
F_23 ( L_31 ,
V_30 -> V_57 -> V_59 , V_30 -> V_77 ) ;
F_23 ( L_32 ,
F_24 ( V_30 ) , F_24 ( V_52 ) ) ;
F_25 () ;
F_26 ( V_30 ) ;
return 1 ;
V_83:
F_22 ( V_53 ) ;
return V_71 ;
}
int F_37 ( const volatile void T_5 * V_44 )
{
unsigned long V_77 ;
struct V_3 * V_4 ;
V_77 = F_14 ( ( unsigned long V_87 ) V_44 ) ;
V_4 = F_38 ( V_77 ) ;
if ( ! V_4 ) {
V_73 . V_88 ++ ;
return 0 ;
}
return F_27 ( V_4 ) ;
}
int F_11 ( struct V_29 * V_30 , int V_89 )
{
int V_90 , V_71 ;
switch ( V_89 ) {
case V_41 :
V_90 = V_65 ;
break;
case V_91 :
V_90 = V_66 ;
break;
case V_92 :
case V_93 :
case V_94 :
V_90 = 0 ;
break;
default:
F_6 ( L_33 ,
V_58 , V_89 ) ;
return - V_95 ;
}
if ( V_90 ) {
V_71 = V_16 -> V_63 ( V_30 , NULL ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_71 == V_64 )
return 0 ;
if ( V_71 & V_90 )
return 0 ;
}
V_71 = V_16 -> V_96 ( V_30 , V_89 ) ;
if ( V_71 )
F_6 ( L_34
L_35 ,
V_58 , V_89 , V_30 -> V_57 -> V_59 ,
V_30 -> V_77 , V_71 ) ;
if ( V_90 ) {
V_71 = V_16 -> V_97 ( V_30 , V_98 ) ;
if ( V_71 <= 0 )
return V_71 ;
if ( V_71 & V_90 )
return 0 ;
return - V_99 ;
}
return V_71 ;
}
int F_39 ( struct V_68 * V_69 , enum V_100 V_33 )
{
struct V_3 * V_4 = F_40 ( V_69 ) ;
struct V_29 * V_30 = F_30 ( V_4 ) ;
if ( ! V_30 ) {
F_23 ( L_36 ,
V_58 , F_41 ( V_69 ) ) ;
return - V_95 ;
}
switch ( V_33 ) {
case V_101 :
V_16 -> V_102 ( V_30 , V_103 ) ;
F_42 ( V_30 , V_34 ) ;
break;
case V_104 :
F_21 ( V_30 , V_34 ) ;
V_16 -> V_102 ( V_30 , V_105 ) ;
break;
case V_106 :
F_21 ( V_30 , V_34 ) ;
V_16 -> V_102 ( V_30 , V_107 ) ;
break;
default:
F_42 ( V_30 , V_34 ) ;
return - V_95 ;
} ;
return 0 ;
}
static void * F_43 ( void * V_27 , void * V_28 )
{
struct V_68 * V_69 ;
unsigned int * V_108 = ( unsigned int * ) V_28 ;
struct V_3 * V_4 = (struct V_3 * ) V_27 ;
V_69 = F_29 ( V_4 ) ;
if ( V_69 )
* V_108 |= V_69 -> V_109 ;
return NULL ;
}
static void F_44 ( struct V_29 * V_30 )
{
unsigned int V_108 = 0 ;
F_45 ( V_30 , F_43 , & V_108 ) ;
if ( V_108 )
V_16 -> V_102 ( V_30 , V_107 ) ;
else
V_16 -> V_102 ( V_30 , V_105 ) ;
V_16 -> V_102 ( V_30 , V_103 ) ;
}
int F_46 ( struct V_29 * V_30 )
{
int V_53 = ( V_65 | V_66 ) ;
int V_11 , V_71 ;
for ( V_11 = 0 ; V_11 < 3 ; V_11 ++ ) {
F_44 ( V_30 ) ;
V_71 = V_16 -> V_97 ( V_30 , V_98 ) ;
if ( ( V_71 & V_53 ) == V_53 )
return 0 ;
if ( V_71 < 0 ) {
F_23 ( L_37 ,
V_58 , V_30 -> V_57 -> V_59 , V_30 -> V_77 ) ;
return - 1 ;
}
F_23 ( L_38 ,
V_11 + 1 , V_30 -> V_57 -> V_59 , V_30 -> V_77 , V_71 ) ;
}
return - 1 ;
}
void F_47 ( struct V_3 * V_4 )
{
int V_11 ;
struct V_7 * V_8 ;
if ( ! V_4 )
return;
V_8 = F_4 ( V_4 ) ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ )
V_16 -> V_17 ( V_8 , V_11 * 4 , 4 , & V_4 -> V_110 [ V_11 ] ) ;
if ( V_4 -> V_20 & V_21 )
V_4 -> V_110 [ 1 ] |= V_111 ;
}
int T_1 F_48 ( struct V_16 * V_112 )
{
if ( ! V_112 -> V_113 ) {
F_6 ( L_39 ,
V_58 , V_112 ) ;
return - V_95 ;
}
if ( V_16 && V_16 != V_112 ) {
F_6 ( L_40 ,
V_58 , V_16 -> V_113 , V_112 -> V_113 ) ;
return - V_60 ;
}
V_16 = V_112 ;
return 0 ;
}
int T_6 F_49 ( const char * V_113 )
{
if ( ! V_113 || ! strlen ( V_113 ) ) {
F_6 ( L_41 ,
V_58 ) ;
return - V_95 ;
}
if ( V_16 && ! strcmp ( V_16 -> V_113 , V_113 ) ) {
V_16 = NULL ;
return 0 ;
}
return - V_60 ;
}
static int F_50 ( struct V_114 * V_115 ,
unsigned long V_116 , void * V_117 )
{
F_51 ( V_118 ) ;
return V_119 ;
}
int F_52 ( void )
{
struct V_120 * V_121 , * V_31 ;
struct V_7 * V_57 ;
static int V_122 = 0 ;
int V_54 = 0 ;
if ( F_53 ( V_123 ) && V_122 ++ <= 0 )
return V_54 ;
V_54 = F_54 ( & V_124 ) ;
if ( V_54 ) {
F_6 ( L_42 ,
V_58 , V_54 ) ;
return V_54 ;
}
if ( ! V_16 ) {
F_6 ( L_43 ,
V_58 ) ;
return - V_60 ;
} else if ( ( V_54 = V_16 -> V_125 () ) ) {
F_6 ( L_44 ,
V_58 , V_54 ) ;
return V_54 ;
}
V_54 = F_55 () ;
if ( V_54 )
return V_54 ;
if ( F_10 ( V_126 ) ) {
F_56 (hose, tmp,
&hose_list, list_node) {
V_57 = V_121 -> V_8 ;
F_57 ( V_57 , V_16 -> V_127 , NULL ) ;
}
} else if ( F_10 ( V_55 ) ) {
F_56 (hose, tmp,
&hose_list, list_node)
F_58 ( V_121 -> V_128 , V_16 -> V_129 , NULL ) ;
} else {
F_6 ( L_45 ,
V_58 , V_130 ) ;
return - V_95 ;
}
if ( V_16 -> V_131 ) {
V_54 = V_16 -> V_131 () ;
if ( V_54 )
return V_54 ;
}
if ( F_28 () )
F_59 ( L_46 ) ;
else
F_6 ( L_47 ) ;
return V_54 ;
}
void F_60 ( struct V_7 * V_8 )
{
struct V_120 * V_57 ;
if ( ! F_10 ( V_126 ) )
return;
if ( ! F_61 ( V_8 ) )
return;
V_57 = F_61 ( V_8 ) -> V_57 ;
if ( NULL == V_57 || 0 == V_57 -> V_132 )
return;
V_16 -> V_127 ( V_8 , NULL ) ;
}
void F_62 ( struct V_7 * V_8 )
{
struct V_7 * V_133 ;
F_63 (dn, sib)
F_62 ( V_133 ) ;
F_60 ( V_8 ) ;
}
void F_64 ( struct V_68 * V_69 )
{
struct V_7 * V_8 ;
struct V_3 * V_4 ;
if ( ! V_69 || ! F_28 () )
return;
F_31 ( L_48 , F_41 ( V_69 ) ) ;
V_8 = F_65 ( V_69 ) ;
V_4 = F_61 ( V_8 ) ;
if ( V_4 -> V_134 == V_69 ) {
F_31 ( L_49 ) ;
return;
}
if ( V_4 -> V_134 ) {
F_66 ( V_4 ) ;
F_67 ( V_4 -> V_134 ) ;
F_68 ( V_4 -> V_134 ) ;
V_4 -> V_20 &= ~ V_135 ;
V_4 -> V_20 |= V_136 ;
V_4 -> V_134 = NULL ;
V_69 -> V_69 . V_137 . V_4 = NULL ;
}
V_4 -> V_134 = V_69 ;
V_69 -> V_69 . V_137 . V_4 = V_4 ;
if ( F_10 ( V_55 ) )
V_16 -> V_129 ( V_69 , NULL ) ;
F_69 ( V_69 ) ;
}
void F_70 ( struct V_138 * V_128 )
{
struct V_68 * V_69 ;
F_71 (dev, &bus->devices, bus_list) {
F_64 ( V_69 ) ;
if ( V_69 -> V_139 == V_140 ) {
struct V_138 * V_141 = V_69 -> V_142 ;
if ( V_141 )
F_70 ( V_141 ) ;
}
}
}
void F_72 ( struct V_138 * V_128 )
{
struct V_68 * V_69 ;
F_71 (dev, &bus->devices, bus_list) {
F_73 ( V_69 ) ;
if ( V_69 -> V_139 == V_140 ) {
struct V_138 * V_141 = V_69 -> V_142 ;
if ( V_141 )
F_72 ( V_141 ) ;
}
}
}
void F_74 ( struct V_68 * V_69 )
{
struct V_3 * V_4 ;
if ( ! V_69 || ! F_28 () )
return;
V_4 = F_40 ( V_69 ) ;
F_31 ( L_50 , F_41 ( V_69 ) ) ;
if ( ! V_4 || ! V_4 -> V_134 || ! V_4 -> V_30 ) {
F_31 ( L_51 ) ;
return;
}
V_4 -> V_134 = NULL ;
V_69 -> V_69 . V_137 . V_4 = NULL ;
if ( ! ( V_4 -> V_30 -> V_33 & V_143 ) )
F_66 ( V_4 ) ;
else
V_4 -> V_20 |= V_144 ;
V_4 -> V_20 |= V_136 ;
F_67 ( V_69 ) ;
F_68 ( V_69 ) ;
V_4 -> V_20 &= ~ V_135 ;
}
int F_75 ( struct V_29 * V_30 , bool V_145 )
{
int V_54 ;
V_54 = F_11 ( V_30 , V_41 ) ;
if ( V_54 ) {
F_6 ( L_52 ,
V_58 , V_54 , V_30 -> V_57 -> V_59 , V_30 -> V_77 ) ;
return V_54 ;
}
V_54 = F_11 ( V_30 , V_91 ) ;
if ( V_54 ) {
F_6 ( L_53 ,
V_58 , V_54 , V_30 -> V_57 -> V_59 , V_30 -> V_77 ) ;
return V_54 ;
}
if ( V_145 && ( V_30 -> V_33 & V_61 ) )
F_42 ( V_30 , V_61 ) ;
return V_54 ;
}
static int F_76 ( struct V_29 * V_30 )
{
struct V_3 * V_4 , * V_31 ;
struct V_68 * V_134 ;
struct V_146 * V_147 ;
int V_53 , V_54 ;
V_53 = ( V_65 | V_66 ) ;
V_54 = V_16 -> V_63 ( V_30 , NULL ) ;
if ( V_54 < 0 || V_54 == V_64 )
return 0 ;
if ( ( V_54 & V_53 ) == V_53 )
return 0 ;
F_8 (pe, edev, tmp) {
V_134 = F_29 ( V_4 ) ;
if ( ! V_134 )
continue;
for ( V_147 = & V_148 [ 0 ] ; V_147 -> V_149 != 0 ; V_147 ++ ) {
if ( V_147 -> V_149 != V_150 &&
V_147 -> V_149 != V_134 -> V_149 )
continue;
if ( V_147 -> V_151 != V_150 &&
V_147 -> V_151 != V_134 -> V_151 )
continue;
if ( V_147 -> V_152 != V_150 &&
V_147 -> V_152 != V_134 -> V_153 )
continue;
if ( V_147 -> V_154 != V_150 &&
V_147 -> V_154 != V_134 -> V_155 )
continue;
goto V_102;
}
}
return F_75 ( V_30 , true ) ;
V_102:
return F_77 ( V_30 ) ;
}
int F_78 ( struct V_68 * V_134 )
{
struct V_3 * V_4 ;
int V_54 = - V_156 ;
F_79 ( & V_157 ) ;
if ( ! V_134 )
goto V_62;
V_4 = F_40 ( V_134 ) ;
if ( ! V_4 || ! V_4 -> V_30 )
goto V_62;
V_54 = F_76 ( V_4 -> V_30 ) ;
if ( V_54 )
goto V_62;
F_80 ( & V_4 -> V_30 -> V_158 ) ;
F_81 ( & V_157 ) ;
return 0 ;
V_62:
F_81 ( & V_157 ) ;
return V_54 ;
}
void F_82 ( struct V_68 * V_134 )
{
struct V_3 * V_4 ;
F_79 ( & V_157 ) ;
if ( ! V_134 )
goto V_62;
V_4 = F_40 ( V_134 ) ;
if ( ! V_4 || ! V_4 -> V_30 || ! F_33 ( V_4 -> V_30 ) )
goto V_62;
F_83 ( & V_4 -> V_30 -> V_158 ) ;
F_16 ( F_84 ( & V_4 -> V_30 -> V_158 ) < 0 ) ;
F_76 ( V_4 -> V_30 ) ;
V_62:
F_81 ( & V_157 ) ;
}
static int F_85 ( struct V_151 * V_69 , void * V_27 )
{
struct V_68 * V_134 = F_86 ( V_69 ) ;
struct V_68 * * V_159 = V_27 ;
struct V_160 * V_161 ;
if ( ! V_69 )
return 0 ;
V_161 = F_87 ( V_69 ) ;
if ( V_161 && V_161 -> V_162 ) {
* V_159 = V_134 ;
return 1 ;
}
return 0 ;
}
struct V_29 * F_88 ( struct V_163 * V_164 )
{
struct V_68 * V_134 = NULL ;
struct V_3 * V_4 ;
int V_54 ;
if ( ! V_164 )
return NULL ;
V_54 = F_89 ( V_164 , & V_134 , F_85 ) ;
if ( ! V_54 || ! V_134 )
return NULL ;
V_4 = F_40 ( V_134 ) ;
if ( ! V_4 || ! V_4 -> V_30 )
return NULL ;
return V_4 -> V_30 ;
}
int F_90 ( struct V_29 * V_30 , int V_165 )
{
int V_54 = 0 ;
if ( ! V_30 )
return - V_156 ;
switch ( V_165 ) {
case V_93 :
if ( F_28 () ) {
V_54 = F_76 ( V_30 ) ;
break;
}
V_54 = - V_99 ;
break;
case V_92 :
break;
case V_41 :
case V_91 :
if ( ! V_16 || ! V_16 -> V_96 ) {
V_54 = - V_166 ;
break;
}
V_54 = F_11 ( V_30 , V_165 ) ;
break;
default:
F_31 ( L_54 ,
V_58 , V_165 , V_92 , V_91 ) ;
V_54 = - V_95 ;
}
return V_54 ;
}
int F_91 ( struct V_29 * V_30 )
{
int V_167 , V_54 = 0 ;
bool V_168 , V_169 , V_170 ;
if ( ! V_30 )
return - V_156 ;
if ( ! V_16 || ! V_16 -> V_63 )
return - V_166 ;
V_167 = V_16 -> V_63 ( V_30 , NULL ) ;
V_168 = ! ! ( V_167 & V_171 ) ;
V_169 = ! ! ( V_167 & V_172 ) ;
V_170 = ! ! ( V_167 & V_173 ) ;
if ( V_168 )
V_54 = V_174 ;
else if ( V_169 && V_170 )
V_54 = V_175 ;
else if ( ! V_169 && ! V_170 )
V_54 = V_176 ;
else if ( ! V_169 && V_170 )
V_54 = V_177 ;
else
V_54 = V_178 ;
return V_54 ;
}
static int F_92 ( struct V_29 * V_30 )
{
struct V_3 * V_4 , * V_31 ;
struct V_68 * V_134 ;
int V_54 = 0 ;
F_12 ( V_30 ) ;
F_8 (pe, edev, tmp) {
V_134 = F_29 ( V_4 ) ;
if ( ! V_134 )
continue;
V_54 = F_93 ( V_134 ) ;
if ( V_54 ) {
F_6 ( L_55 ,
V_58 , V_54 , F_41 ( V_134 ) ) ;
return V_54 ;
}
}
return F_75 ( V_30 , true ) ;
}
int F_94 ( struct V_29 * V_30 , int V_165 )
{
int V_54 = 0 ;
if ( ! V_30 )
return - V_156 ;
if ( ! V_16 || ! V_16 -> V_96 || ! V_16 -> V_102 )
return - V_166 ;
switch ( V_165 ) {
case V_103 :
V_54 = V_16 -> V_102 ( V_30 , V_165 ) ;
F_42 ( V_30 , V_34 ) ;
if ( V_54 )
break;
V_54 = F_92 ( V_30 ) ;
break;
case V_105 :
case V_107 :
V_16 -> V_96 ( V_30 , V_94 ) ;
F_21 ( V_30 , V_34 ) ;
V_54 = V_16 -> V_102 ( V_30 , V_165 ) ;
break;
default:
F_31 ( L_56 ,
V_58 , V_165 ) ;
V_54 = - V_95 ;
}
return V_54 ;
}
int F_95 ( struct V_29 * V_30 )
{
int V_54 = 0 ;
if ( ! V_30 )
return - V_156 ;
return V_54 ;
}
static int F_96 ( struct V_179 * V_180 , void * V_181 )
{
if ( ! F_28 () ) {
F_97 ( V_180 , L_57 ) ;
F_97 ( V_180 , L_58 , V_73 . V_74 ) ;
} else {
F_97 ( V_180 , L_59 ) ;
F_97 ( V_180 ,
L_60
L_61
L_62
L_63
L_58
L_64
L_65 ,
V_73 . V_88 ,
V_73 . V_75 ,
V_73 . V_79 ,
V_73 . V_76 ,
V_73 . V_74 ,
V_73 . V_84 ,
V_73 . V_86 ) ;
}
return 0 ;
}
static int F_98 ( struct V_182 * V_182 , struct V_183 * V_183 )
{
return F_99 ( V_183 , F_96 , NULL ) ;
}
static int F_100 ( void * V_27 , T_7 V_184 )
{
if ( V_184 )
F_51 ( V_2 ) ;
else
F_2 ( V_2 ) ;
if ( V_16 -> V_131 )
V_16 -> V_131 () ;
return 0 ;
}
static int F_101 ( void * V_27 , T_7 * V_184 )
{
if ( F_28 () )
* V_184 = 0x1ul ;
else
* V_184 = 0x0ul ;
return 0 ;
}
static int T_1 F_102 ( void )
{
if ( F_53 ( V_185 ) || F_53 ( V_123 ) ) {
F_103 ( L_66 , 0 , NULL , & V_186 ) ;
#ifdef F_104
F_105 ( L_67 , 0600 ,
V_187 , NULL ,
& V_188 ) ;
#endif
}
return 0 ;
}

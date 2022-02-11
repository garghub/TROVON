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
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_3 , V_9 -> V_16 ) ;
F_6 ( L_4 , V_9 -> V_16 ) ;
V_17 -> V_18 ( V_9 , V_19 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_5 , V_10 ) ;
F_6 ( L_6 , V_10 ) ;
V_17 -> V_18 ( V_9 , V_20 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_7 , V_10 ) ;
F_6 ( L_8 , V_10 ) ;
if ( V_5 -> V_21 & V_22 ) {
V_17 -> V_18 ( V_9 , V_23 , 2 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_9 , V_10 ) ;
F_6 ( L_10 , V_10 ) ;
V_17 -> V_18 ( V_9 , V_24 , 2 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_11 , V_10 ) ;
F_6 ( L_12 , V_10 ) ;
}
V_11 = V_5 -> V_25 ;
if ( V_11 ) {
V_17 -> V_18 ( V_9 , V_11 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_13 , V_10 ) ;
F_6 ( L_14 , V_10 ) ;
V_17 -> V_18 ( V_9 , V_11 + 4 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_15 , V_10 ) ;
F_6 ( L_16 , V_10 ) ;
}
V_11 = V_5 -> V_26 ;
if ( V_11 ) {
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_17 ) ;
F_6 ( L_18 ) ;
for ( V_12 = 0 ; V_12 <= 8 ; V_12 ++ ) {
V_17 -> V_18 ( V_9 , V_11 + 4 * V_12 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_19 , 4 * V_12 , V_10 ) ;
if ( ( V_12 % 4 ) == 0 ) {
if ( V_12 != 0 )
F_6 ( L_3 , V_15 ) ;
V_14 = F_5 ( V_15 , sizeof( V_15 ) ,
L_20 ,
4 * V_12 , V_10 ) ;
} else {
V_14 += F_5 ( V_15 + V_14 , sizeof( V_15 ) - V_14 ,
L_21 , V_10 ) ;
}
}
F_6 ( L_3 , V_15 ) ;
}
V_11 = V_5 -> V_27 ;
if ( V_11 ) {
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_22 ) ;
F_6 ( L_23 ) ;
for ( V_12 = 0 ; V_12 <= 13 ; V_12 ++ ) {
V_17 -> V_18 ( V_9 , V_11 + 4 * V_12 , 4 , & V_10 ) ;
V_13 += F_5 ( V_6 + V_13 , V_7 - V_13 , L_19 , 4 * V_12 , V_10 ) ;
if ( ( V_12 % 4 ) == 0 ) {
if ( V_12 != 0 )
F_6 ( L_3 , V_15 ) ;
V_14 = F_5 ( V_15 , sizeof( V_15 ) ,
L_24 ,
4 * V_12 , V_10 ) ;
} else {
V_14 += F_5 ( V_15 + V_14 , sizeof( V_15 ) - V_14 ,
L_21 , V_10 ) ;
}
}
F_6 ( L_3 , V_15 ) ;
}
return V_13 ;
}
static void * F_7 ( void * V_28 , void * V_29 )
{
struct V_30 * V_31 = V_28 ;
struct V_4 * V_5 , * V_32 ;
T_2 * V_33 = V_29 ;
if ( V_31 -> V_34 & V_35 )
return NULL ;
F_8 ( V_31 , V_5 , V_32 )
* V_33 += F_3 ( V_5 , V_36 + * V_33 ,
V_37 - * V_33 ) ;
return NULL ;
}
void F_9 ( struct V_30 * V_31 , int V_38 )
{
T_2 V_39 = 0 ;
if ( ! ( V_31 -> type & V_40 ) ) {
if ( F_10 ( V_41 ) )
F_11 ( V_31 , V_42 ) ;
V_17 -> V_43 ( V_31 ) ;
F_12 ( V_31 ) ;
V_36 [ 0 ] = 0 ;
F_13 ( V_31 , F_7 , & V_39 ) ;
}
V_17 -> V_44 ( V_31 , V_38 , V_36 , V_39 ) ;
}
static inline unsigned long F_14 ( unsigned long V_45 )
{
T_4 * V_46 ;
unsigned long V_47 ;
int V_48 ;
V_46 = F_15 ( V_49 . V_50 , V_45 , & V_48 ) ;
if ( ! V_46 )
return V_45 ;
F_16 ( V_48 ) ;
V_47 = F_17 ( * V_46 ) << V_51 ;
return V_47 | ( V_45 & ( V_52 - 1 ) ) ;
}
static int F_18 ( struct V_30 * V_31 )
{
struct V_30 * V_53 ;
unsigned long V_54 ;
int V_55 ;
if ( ! F_10 ( V_56 ) )
return - V_57 ;
V_53 = F_19 ( V_31 -> V_58 ) ;
if ( ! V_53 ) {
F_6 ( L_25 ,
V_59 , V_31 -> V_58 -> V_60 ) ;
return - V_61 ;
}
F_20 ( & V_54 ) ;
if ( V_53 -> V_34 & V_62 ) {
V_55 = 0 ;
goto V_63;
}
V_55 = V_17 -> V_64 ( V_53 , NULL ) ;
if ( ( V_55 < 0 ) ||
( V_55 == V_65 ) ||
( V_55 & ( V_66 | V_67 ) ) ==
( V_66 | V_67 ) ) {
V_55 = 0 ;
goto V_63;
}
F_21 ( V_53 , V_62 ) ;
F_22 ( V_54 ) ;
F_23 ( L_26 ,
V_53 -> V_58 -> V_60 , F_24 ( V_53 ) ) ;
F_25 () ;
F_26 ( V_53 ) ;
return 1 ;
V_63:
F_22 ( V_54 ) ;
return V_55 ;
}
int F_27 ( struct V_4 * V_5 )
{
int V_55 ;
int V_68 = ( V_66 | V_67 ) ;
unsigned long V_54 ;
struct V_8 * V_9 ;
struct V_69 * V_70 ;
struct V_30 * V_31 , * V_71 , * V_53 ;
int V_72 = 0 ;
const char * V_73 ;
V_74 . V_75 ++ ;
if ( ! F_28 () )
return 0 ;
if ( ! V_5 ) {
V_74 . V_76 ++ ;
return 0 ;
}
V_9 = F_4 ( V_5 ) ;
V_70 = F_29 ( V_5 ) ;
V_31 = F_30 ( V_5 ) ;
if ( ! V_31 ) {
V_74 . V_77 ++ ;
F_31 ( L_27 ,
F_32 ( V_70 ) , V_9 -> V_16 ) ;
return 0 ;
}
if ( ! V_31 -> V_78 && ! V_31 -> V_79 ) {
V_74 . V_80 ++ ;
return 0 ;
}
V_55 = F_18 ( V_31 ) ;
if ( V_55 > 0 )
return V_55 ;
if ( F_33 ( V_31 ) )
return 0 ;
F_20 ( & V_54 ) ;
V_72 = 1 ;
if ( V_31 -> V_34 & V_62 ) {
V_31 -> V_81 ++ ;
if ( V_31 -> V_81 % V_82 == 0 ) {
V_73 = F_34 ( V_9 , L_28 , NULL ) ;
F_35 ( V_83 L_29
L_30 ,
V_31 -> V_81 , V_73 ,
F_36 ( V_70 ) , F_32 ( V_70 ) ) ;
F_35 ( V_83 L_31 ,
F_36 ( V_70 ) ) ;
F_25 () ;
}
goto V_84;
}
V_55 = V_17 -> V_64 ( V_31 , NULL ) ;
if ( ( V_55 < 0 ) ||
( V_55 == V_65 ) ||
( ( V_55 & V_68 ) == V_68 ) ) {
V_74 . V_85 ++ ;
V_31 -> V_85 ++ ;
V_72 = 0 ;
goto V_84;
}
V_71 = V_31 -> V_86 ;
while ( V_71 ) {
if ( V_71 -> type & V_40 )
break;
V_55 = V_17 -> V_64 ( V_71 , NULL ) ;
if ( V_55 > 0 &&
( V_55 & V_68 ) != V_68 )
V_31 = V_71 ;
V_71 = V_71 -> V_86 ;
}
V_74 . V_87 ++ ;
F_21 ( V_31 , V_62 ) ;
F_22 ( V_54 ) ;
V_53 = F_19 ( V_31 -> V_58 ) ;
F_23 ( L_32 ,
V_31 -> V_58 -> V_60 , V_31 -> V_78 ) ;
F_23 ( L_33 ,
F_24 ( V_31 ) , F_24 ( V_53 ) ) ;
F_25 () ;
F_26 ( V_31 ) ;
return 1 ;
V_84:
F_22 ( V_54 ) ;
return V_72 ;
}
int F_37 ( const volatile void T_5 * V_45 )
{
unsigned long V_78 ;
struct V_4 * V_5 ;
V_78 = F_14 ( ( unsigned long V_88 ) V_45 ) ;
V_5 = F_38 ( V_78 ) ;
if ( ! V_5 ) {
V_74 . V_89 ++ ;
return 0 ;
}
return F_27 ( V_5 ) ;
}
int F_11 ( struct V_30 * V_31 , int V_90 )
{
int V_91 , V_72 ;
switch ( V_90 ) {
case V_42 :
V_91 = V_66 ;
break;
case V_92 :
V_91 = V_67 ;
break;
case V_93 :
case V_94 :
case V_95 :
V_91 = 0 ;
break;
default:
F_6 ( L_34 ,
V_59 , V_90 ) ;
return - V_96 ;
}
if ( V_91 ) {
V_72 = V_17 -> V_64 ( V_31 , NULL ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_72 == V_65 )
return 0 ;
if ( V_72 & V_91 )
return 0 ;
}
V_72 = V_17 -> V_97 ( V_31 , V_90 ) ;
if ( V_72 )
F_6 ( L_35
L_36 ,
V_59 , V_90 , V_31 -> V_58 -> V_60 ,
V_31 -> V_78 , V_72 ) ;
if ( V_91 ) {
V_72 = V_17 -> V_98 ( V_31 , V_99 ) ;
if ( V_72 <= 0 )
return V_72 ;
if ( V_72 & V_91 )
return 0 ;
return - V_100 ;
}
return V_72 ;
}
int F_39 ( struct V_69 * V_70 , enum V_101 V_34 )
{
struct V_4 * V_5 = F_40 ( V_70 ) ;
struct V_30 * V_31 = F_30 ( V_5 ) ;
if ( ! V_31 ) {
F_23 ( L_37 ,
V_59 , F_41 ( V_70 ) ) ;
return - V_96 ;
}
switch ( V_34 ) {
case V_102 :
V_17 -> V_103 ( V_31 , V_104 ) ;
F_42 ( V_31 , V_35 ) ;
break;
case V_105 :
F_21 ( V_31 , V_35 ) ;
V_17 -> V_103 ( V_31 , V_106 ) ;
break;
case V_107 :
F_21 ( V_31 , V_35 ) ;
V_17 -> V_103 ( V_31 , V_108 ) ;
break;
default:
F_42 ( V_31 , V_35 ) ;
return - V_96 ;
} ;
return 0 ;
}
static void * F_43 ( void * V_28 , void * V_29 )
{
struct V_69 * V_70 ;
unsigned int * V_109 = ( unsigned int * ) V_29 ;
struct V_4 * V_5 = (struct V_4 * ) V_28 ;
V_70 = F_29 ( V_5 ) ;
if ( V_70 )
* V_109 |= V_70 -> V_110 ;
return NULL ;
}
static void F_44 ( struct V_30 * V_31 )
{
unsigned int V_109 = 0 ;
F_45 ( V_31 , F_43 , & V_109 ) ;
if ( V_109 )
V_17 -> V_103 ( V_31 , V_108 ) ;
else
V_17 -> V_103 ( V_31 , V_106 ) ;
V_17 -> V_103 ( V_31 , V_104 ) ;
}
int F_46 ( struct V_30 * V_31 )
{
int V_54 = ( V_66 | V_67 ) ;
int V_12 , V_34 , V_55 ;
F_21 ( V_31 , V_111 | V_35 ) ;
for ( V_12 = 0 ; V_12 < 3 ; V_12 ++ ) {
F_44 ( V_31 ) ;
V_34 = V_17 -> V_98 ( V_31 , V_99 ) ;
if ( ( V_34 & V_54 ) == V_54 ) {
V_55 = 0 ;
goto V_63;
}
if ( V_34 < 0 ) {
F_6 ( L_38 ,
V_59 , V_31 -> V_58 -> V_60 , V_31 -> V_78 ) ;
V_55 = - V_112 ;
goto V_63;
}
V_55 = - V_100 ;
F_6 ( L_39 ,
V_59 , V_34 , V_31 -> V_58 -> V_60 , V_31 -> V_78 , ( V_12 + 1 ) ) ;
}
V_63:
F_42 ( V_31 , V_111 | V_35 ) ;
return V_55 ;
}
void F_47 ( struct V_4 * V_5 )
{
int V_12 ;
struct V_8 * V_9 ;
if ( ! V_5 )
return;
V_9 = F_4 ( V_5 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
V_17 -> V_18 ( V_9 , V_12 * 4 , 4 , & V_5 -> V_113 [ V_12 ] ) ;
if ( V_5 -> V_21 & V_22 )
V_5 -> V_113 [ 1 ] |= V_114 ;
}
int T_1 F_48 ( struct V_17 * V_115 )
{
if ( ! V_115 -> V_116 ) {
F_6 ( L_40 ,
V_59 , V_115 ) ;
return - V_96 ;
}
if ( V_17 && V_17 != V_115 ) {
F_6 ( L_41 ,
V_59 , V_17 -> V_116 , V_115 -> V_116 ) ;
return - V_61 ;
}
V_17 = V_115 ;
return 0 ;
}
int T_6 F_49 ( const char * V_116 )
{
if ( ! V_116 || ! strlen ( V_116 ) ) {
F_6 ( L_42 ,
V_59 ) ;
return - V_96 ;
}
if ( V_17 && ! strcmp ( V_17 -> V_116 , V_116 ) ) {
V_17 = NULL ;
return 0 ;
}
return - V_61 ;
}
static int F_50 ( struct V_117 * V_118 ,
unsigned long V_119 , void * V_120 )
{
F_51 ( V_121 ) ;
return V_122 ;
}
int F_52 ( void )
{
struct V_123 * V_124 , * V_32 ;
struct V_8 * V_58 ;
static int V_125 = 0 ;
int V_55 = 0 ;
if ( F_53 ( V_126 ) && V_125 ++ <= 0 )
return V_55 ;
V_55 = F_54 ( & V_127 ) ;
if ( V_55 ) {
F_6 ( L_43 ,
V_59 , V_55 ) ;
return V_55 ;
}
if ( ! V_17 ) {
F_6 ( L_44 ,
V_59 ) ;
return - V_61 ;
} else if ( ( V_55 = V_17 -> V_128 () ) )
return V_55 ;
V_55 = F_55 () ;
if ( V_55 )
return V_55 ;
if ( F_10 ( V_129 ) ) {
F_56 (hose, tmp,
&hose_list, list_node) {
V_58 = V_124 -> V_9 ;
F_57 ( V_58 , V_17 -> V_130 , NULL ) ;
}
} else if ( F_10 ( V_56 ) ) {
F_56 (hose, tmp,
&hose_list, list_node)
F_58 ( V_124 -> V_131 , V_17 -> V_132 , NULL ) ;
} else {
F_6 ( L_45 ,
V_59 , V_133 ) ;
return - V_96 ;
}
if ( V_17 -> V_134 ) {
V_55 = V_17 -> V_134 () ;
if ( V_55 )
return V_55 ;
}
if ( F_28 () )
F_59 ( L_46 ) ;
else
F_6 ( L_47 ) ;
return V_55 ;
}
void F_60 ( struct V_8 * V_9 )
{
struct V_123 * V_58 ;
if ( ! F_10 ( V_129 ) )
return;
if ( ! F_61 ( V_9 ) )
return;
V_58 = F_61 ( V_9 ) -> V_58 ;
if ( NULL == V_58 || 0 == V_58 -> V_135 )
return;
V_17 -> V_130 ( V_9 , NULL ) ;
}
void F_62 ( struct V_8 * V_9 )
{
struct V_8 * V_136 ;
F_63 (dn, sib)
F_62 ( V_136 ) ;
F_60 ( V_9 ) ;
}
void F_64 ( struct V_69 * V_70 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 ;
if ( ! V_70 || ! F_28 () )
return;
F_31 ( L_48 , F_41 ( V_70 ) ) ;
V_9 = F_65 ( V_70 ) ;
V_5 = F_61 ( V_9 ) ;
if ( V_5 -> V_137 == V_70 ) {
F_31 ( L_49 ) ;
return;
}
if ( V_5 -> V_137 ) {
F_66 ( V_5 ) ;
F_67 ( V_5 -> V_137 ) ;
F_68 ( V_5 -> V_137 ) ;
V_5 -> V_21 &= ~ V_138 ;
V_5 -> V_21 |= V_139 ;
V_5 -> V_137 = NULL ;
V_70 -> V_70 . V_140 . V_5 = NULL ;
}
V_5 -> V_137 = V_70 ;
V_70 -> V_70 . V_140 . V_5 = V_5 ;
if ( F_10 ( V_56 ) )
V_17 -> V_132 ( V_70 , NULL ) ;
F_69 ( V_70 ) ;
}
void F_70 ( struct V_141 * V_131 )
{
struct V_69 * V_70 ;
F_71 (dev, &bus->devices, bus_list) {
F_64 ( V_70 ) ;
if ( V_70 -> V_142 == V_143 ) {
struct V_141 * V_144 = V_70 -> V_145 ;
if ( V_144 )
F_70 ( V_144 ) ;
}
}
}
void F_72 ( struct V_141 * V_131 )
{
struct V_69 * V_70 ;
F_71 (dev, &bus->devices, bus_list) {
F_73 ( V_70 ) ;
if ( V_70 -> V_142 == V_143 ) {
struct V_141 * V_144 = V_70 -> V_145 ;
if ( V_144 )
F_72 ( V_144 ) ;
}
}
}
void F_74 ( struct V_69 * V_70 )
{
struct V_4 * V_5 ;
if ( ! V_70 || ! F_28 () )
return;
V_5 = F_40 ( V_70 ) ;
F_31 ( L_50 , F_41 ( V_70 ) ) ;
if ( ! V_5 || ! V_5 -> V_137 || ! V_5 -> V_31 ) {
F_31 ( L_51 ) ;
return;
}
V_5 -> V_137 = NULL ;
V_70 -> V_70 . V_140 . V_5 = NULL ;
if ( ! ( V_5 -> V_31 -> V_34 & V_146 ) )
F_66 ( V_5 ) ;
else
V_5 -> V_21 |= V_147 ;
V_5 -> V_21 |= V_139 ;
F_67 ( V_70 ) ;
F_68 ( V_70 ) ;
V_5 -> V_21 &= ~ V_138 ;
}
int F_75 ( struct V_30 * V_31 , bool V_148 )
{
int V_55 ;
V_55 = F_11 ( V_31 , V_42 ) ;
if ( V_55 ) {
F_6 ( L_52 ,
V_59 , V_55 , V_31 -> V_58 -> V_60 , V_31 -> V_78 ) ;
return V_55 ;
}
V_55 = F_11 ( V_31 , V_92 ) ;
if ( V_55 ) {
F_6 ( L_53 ,
V_59 , V_55 , V_31 -> V_58 -> V_60 , V_31 -> V_78 ) ;
return V_55 ;
}
if ( V_148 && ( V_31 -> V_34 & V_62 ) )
F_42 ( V_31 , V_62 ) ;
return V_55 ;
}
static int F_76 ( struct V_30 * V_31 )
{
struct V_4 * V_5 , * V_32 ;
struct V_69 * V_137 ;
struct V_149 * V_150 ;
int V_54 , V_55 ;
V_54 = ( V_66 | V_67 ) ;
V_55 = V_17 -> V_64 ( V_31 , NULL ) ;
if ( V_55 < 0 || V_55 == V_65 )
return 0 ;
if ( ( V_55 & V_54 ) == V_54 )
return 0 ;
F_8 (pe, edev, tmp) {
V_137 = F_29 ( V_5 ) ;
if ( ! V_137 )
continue;
for ( V_150 = & V_151 [ 0 ] ; V_150 -> V_152 != 0 ; V_150 ++ ) {
if ( V_150 -> V_152 != V_153 &&
V_150 -> V_152 != V_137 -> V_152 )
continue;
if ( V_150 -> V_154 != V_153 &&
V_150 -> V_154 != V_137 -> V_154 )
continue;
if ( V_150 -> V_155 != V_153 &&
V_150 -> V_155 != V_137 -> V_156 )
continue;
if ( V_150 -> V_157 != V_153 &&
V_150 -> V_157 != V_137 -> V_158 )
continue;
goto V_103;
}
}
return F_75 ( V_31 , true ) ;
V_103:
return F_77 ( V_31 ) ;
}
int F_78 ( struct V_69 * V_137 )
{
struct V_4 * V_5 ;
int V_55 = - V_159 ;
F_79 ( & V_160 ) ;
if ( ! V_137 )
goto V_63;
V_5 = F_40 ( V_137 ) ;
if ( ! V_5 || ! V_5 -> V_31 )
goto V_63;
V_55 = F_76 ( V_5 -> V_31 ) ;
if ( V_55 )
goto V_63;
F_80 ( & V_5 -> V_31 -> V_161 ) ;
F_81 ( & V_160 ) ;
return 0 ;
V_63:
F_81 ( & V_160 ) ;
return V_55 ;
}
void F_82 ( struct V_69 * V_137 )
{
struct V_4 * V_5 ;
F_79 ( & V_160 ) ;
if ( ! V_137 )
goto V_63;
V_5 = F_40 ( V_137 ) ;
if ( ! V_5 || ! V_5 -> V_31 || ! F_33 ( V_5 -> V_31 ) )
goto V_63;
F_83 ( & V_5 -> V_31 -> V_161 ) ;
F_16 ( F_84 ( & V_5 -> V_31 -> V_161 ) < 0 ) ;
F_76 ( V_5 -> V_31 ) ;
V_63:
F_81 ( & V_160 ) ;
}
static int F_85 ( struct V_154 * V_70 , void * V_28 )
{
struct V_69 * V_137 = F_86 ( V_70 ) ;
struct V_69 * * V_162 = V_28 ;
struct V_163 * V_164 ;
if ( ! V_70 )
return 0 ;
V_164 = F_87 ( V_70 ) ;
if ( V_164 && V_164 -> V_165 ) {
* V_162 = V_137 ;
return 1 ;
}
return 0 ;
}
struct V_30 * F_88 ( struct V_166 * V_167 )
{
struct V_69 * V_137 = NULL ;
struct V_4 * V_5 ;
int V_55 ;
if ( ! V_167 )
return NULL ;
V_55 = F_89 ( V_167 , & V_137 , F_85 ) ;
if ( ! V_55 || ! V_137 )
return NULL ;
V_5 = F_40 ( V_137 ) ;
if ( ! V_5 || ! V_5 -> V_31 )
return NULL ;
return V_5 -> V_31 ;
}
int F_90 ( struct V_30 * V_31 , int V_168 )
{
int V_55 = 0 ;
if ( ! V_31 )
return - V_159 ;
switch ( V_168 ) {
case V_94 :
if ( F_28 () ) {
V_55 = F_76 ( V_31 ) ;
break;
}
V_55 = - V_100 ;
break;
case V_93 :
break;
case V_42 :
case V_92 :
if ( ! V_17 || ! V_17 -> V_97 ) {
V_55 = - V_169 ;
break;
}
V_55 = F_11 ( V_31 , V_168 ) ;
break;
default:
F_31 ( L_54 ,
V_59 , V_168 , V_93 , V_92 ) ;
V_55 = - V_96 ;
}
return V_55 ;
}
int F_91 ( struct V_30 * V_31 )
{
int V_170 , V_55 = 0 ;
bool V_171 , V_172 , V_173 ;
if ( ! V_31 )
return - V_159 ;
if ( ! V_17 || ! V_17 -> V_64 )
return - V_169 ;
V_170 = V_17 -> V_64 ( V_31 , NULL ) ;
V_171 = ! ! ( V_170 & V_174 ) ;
V_172 = ! ! ( V_170 & V_175 ) ;
V_173 = ! ! ( V_170 & V_176 ) ;
if ( V_171 )
V_55 = V_177 ;
else if ( V_172 && V_173 )
V_55 = V_178 ;
else if ( ! V_172 && ! V_173 )
V_55 = V_179 ;
else if ( ! V_172 && V_173 )
V_55 = V_180 ;
else
V_55 = V_181 ;
return V_55 ;
}
static int F_92 ( struct V_30 * V_31 )
{
struct V_4 * V_5 , * V_32 ;
struct V_69 * V_137 ;
int V_55 = 0 ;
F_12 ( V_31 ) ;
F_8 (pe, edev, tmp) {
V_137 = F_29 ( V_5 ) ;
if ( ! V_137 )
continue;
V_55 = F_93 ( V_137 ) ;
if ( V_55 ) {
F_6 ( L_55 ,
V_59 , V_55 , F_41 ( V_137 ) ) ;
return V_55 ;
}
}
return F_75 ( V_31 , true ) ;
}
int F_94 ( struct V_30 * V_31 , int V_168 )
{
int V_55 = 0 ;
if ( ! V_31 )
return - V_159 ;
if ( ! V_17 || ! V_17 -> V_97 || ! V_17 -> V_103 )
return - V_169 ;
switch ( V_168 ) {
case V_104 :
V_55 = V_17 -> V_103 ( V_31 , V_168 ) ;
F_42 ( V_31 , V_35 ) ;
if ( V_55 )
break;
V_55 = F_92 ( V_31 ) ;
break;
case V_106 :
case V_108 :
V_17 -> V_97 ( V_31 , V_95 ) ;
F_21 ( V_31 , V_35 ) ;
V_55 = V_17 -> V_103 ( V_31 , V_168 ) ;
break;
default:
F_31 ( L_56 ,
V_59 , V_168 ) ;
V_55 = - V_96 ;
}
return V_55 ;
}
int F_95 ( struct V_30 * V_31 )
{
int V_55 = 0 ;
if ( ! V_31 )
return - V_159 ;
return V_55 ;
}
static int F_96 ( struct V_182 * V_183 , void * V_184 )
{
if ( ! F_28 () ) {
F_97 ( V_183 , L_57 ) ;
F_97 ( V_183 , L_58 , V_74 . V_75 ) ;
} else {
F_97 ( V_183 , L_59 ) ;
F_97 ( V_183 ,
L_60
L_61
L_62
L_63
L_58
L_64
L_65 ,
V_74 . V_89 ,
V_74 . V_76 ,
V_74 . V_80 ,
V_74 . V_77 ,
V_74 . V_75 ,
V_74 . V_85 ,
V_74 . V_87 ) ;
}
return 0 ;
}
static int F_98 ( struct V_185 * V_185 , struct V_186 * V_186 )
{
return F_99 ( V_186 , F_96 , NULL ) ;
}
static int F_100 ( void * V_28 , T_7 V_187 )
{
if ( V_187 )
F_51 ( V_2 ) ;
else
F_2 ( V_2 ) ;
if ( V_17 -> V_134 )
V_17 -> V_134 () ;
return 0 ;
}
static int F_101 ( void * V_28 , T_7 * V_187 )
{
if ( F_28 () )
* V_187 = 0x1ul ;
else
* V_187 = 0x0ul ;
return 0 ;
}
static int T_1 F_102 ( void )
{
if ( F_53 ( V_188 ) || F_53 ( V_126 ) ) {
F_103 ( L_66 , 0 , NULL , & V_189 ) ;
#ifdef F_104
F_105 ( L_67 , 0600 ,
V_190 , NULL ,
& V_191 ) ;
#endif
}
return 0 ;
}

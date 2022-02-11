static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 0 ;
}
static T_1 F_3 ( struct V_6 * V_7 , T_1 V_8 )
{
return V_7 -> V_9 + F_4 ( V_7 -> V_10 , V_8 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 , T_1 V_11 ,
int V_12 )
{
return V_11 >> ( V_12 * V_7 -> V_13 ) ;
}
static void F_6 ( struct V_14 * V_15 , int V_16 )
{
struct V_17 * V_18 = (struct V_17 * ) V_15 -> V_19 ;
if ( V_16 == - V_20 )
return;
V_18 -> V_16 = V_16 ;
F_7 ( & V_18 -> V_21 ) ;
}
static inline int F_8 ( struct V_17 * V_18 , int V_22 )
{
switch ( V_22 ) {
case 0 :
break;
case - V_20 :
case - V_23 :
V_22 = F_9 ( & V_18 -> V_21 ) ;
if ( ! V_22 )
V_22 = V_18 -> V_16 ;
F_10 ( & V_18 -> V_21 ) ;
break;
default:
F_11 ( L_1 , V_22 ) ;
}
if ( F_12 ( V_22 < 0 ) )
F_11 ( L_2 , V_22 ) ;
return V_22 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_24 * V_25 ,
const T_2 * V_19 , T_3 V_26 ,
struct V_17 * V_18 )
{
struct V_27 V_28 ;
F_14 ( & V_28 , V_19 , V_26 ) ;
F_15 ( V_25 , & V_28 , NULL , V_26 ) ;
return F_8 ( V_18 , F_16 ( V_25 ) ) ;
}
static int F_17 ( struct V_6 * V_7 , struct V_24 * V_25 ,
struct V_17 * V_18 )
{
int V_29 ;
F_18 ( V_25 , V_7 -> V_30 ) ;
F_19 ( V_25 , V_31 |
V_32 ,
F_6 , ( void * ) V_18 ) ;
F_20 ( & V_18 -> V_21 ) ;
V_29 = F_8 ( V_18 , F_21 ( V_25 ) ) ;
if ( F_12 ( V_29 < 0 ) ) {
F_11 ( L_3 , V_29 ) ;
return V_29 ;
}
if ( F_22 ( V_7 -> V_33 && ( V_7 -> V_34 >= 1 ) ) )
V_29 = F_13 ( V_7 , V_25 , V_7 -> V_35 , V_7 -> V_33 , V_18 ) ;
return V_29 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_24 * V_25 ,
T_2 * V_36 , struct V_17 * V_18 )
{
int V_29 ;
if ( F_12 ( V_7 -> V_33 && ( ! V_7 -> V_34 ) ) ) {
V_29 = F_13 ( V_7 , V_25 , V_7 -> V_35 , V_7 -> V_33 , V_18 ) ;
if ( V_29 < 0 ) {
F_11 ( L_4 , V_29 ) ;
goto V_37;
}
}
F_15 ( V_25 , NULL , V_36 , 0 ) ;
V_29 = F_8 ( V_18 , F_24 ( V_25 ) ) ;
V_37:
return V_29 ;
}
int F_25 ( struct V_6 * V_7 , struct V_24 * V_25 ,
const T_2 * V_19 , T_3 V_26 , T_2 * V_36 )
{
int V_29 ;
struct V_17 V_18 ;
V_29 = F_17 ( V_7 , V_25 , & V_18 ) ;
if ( F_12 ( V_29 < 0 ) )
goto V_37;
V_29 = F_13 ( V_7 , V_25 , V_19 , V_26 , & V_18 ) ;
if ( F_12 ( V_29 < 0 ) )
goto V_37;
V_29 = F_23 ( V_7 , V_25 , V_36 , & V_18 ) ;
V_37:
return V_29 ;
}
static void F_26 ( struct V_6 * V_7 , T_1 V_11 , int V_12 ,
T_1 * V_38 , unsigned * V_39 )
{
T_1 V_40 = F_5 ( V_7 , V_11 , V_12 ) ;
unsigned V_41 ;
* V_38 = V_7 -> V_42 [ V_12 ] + ( V_40 >> V_7 -> V_13 ) ;
if ( ! V_39 )
return;
V_41 = V_40 & ( ( 1 << V_7 -> V_13 ) - 1 ) ;
if ( ! V_7 -> V_34 )
* V_39 = V_41 * V_7 -> V_43 ;
else
* V_39 = V_41 << ( V_7 -> V_44 - V_7 -> V_13 ) ;
}
static int F_27 ( struct V_6 * V_7 , enum V_45 type ,
unsigned long long V_11 )
{
char V_46 [ V_47 ] ;
char * V_48 [] = { V_46 , NULL } ;
const char * V_49 = L_5 ;
struct V_50 * V_51 = F_28 ( V_7 -> V_10 -> V_52 ) ;
V_7 -> V_53 = 1 ;
if ( V_7 -> V_54 >= V_55 )
goto V_37;
V_7 -> V_54 ++ ;
switch ( type ) {
case V_56 :
V_49 = L_6 ;
break;
case V_57 :
V_49 = L_7 ;
break;
default:
F_29 () ;
}
F_11 ( L_8 , V_7 -> V_58 -> V_59 , V_49 ,
V_11 ) ;
if ( V_7 -> V_54 == V_55 )
F_11 ( L_9 , V_7 -> V_58 -> V_59 ) ;
snprintf ( V_46 , V_47 , L_10 ,
V_60 , type , V_11 ) ;
F_30 ( & F_31 ( F_32 ( V_51 ) ) -> V_61 , V_62 , V_48 ) ;
V_37:
if ( V_7 -> V_63 == V_64 )
return 0 ;
if ( V_7 -> V_63 == V_65 )
F_33 ( L_11 ) ;
return 1 ;
}
static int F_34 ( struct V_6 * V_7 , struct V_66 * V_67 ,
T_1 V_11 , int V_12 , bool V_68 ,
T_2 * V_69 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_2 * V_19 ;
int V_29 ;
T_1 V_38 ;
unsigned V_39 ;
F_26 ( V_7 , V_11 , V_12 , & V_38 , & V_39 ) ;
V_19 = F_35 ( V_7 -> V_70 , V_38 , & V_2 ) ;
if ( F_36 ( V_19 ) )
return F_37 ( V_19 ) ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 ) {
if ( V_68 ) {
V_29 = 1 ;
goto V_71;
}
V_29 = F_25 ( V_7 , F_38 ( V_7 , V_67 ) ,
V_19 , 1 << V_7 -> V_44 ,
F_39 ( V_7 , V_67 ) ) ;
if ( F_12 ( V_29 < 0 ) )
goto V_71;
if ( F_22 ( memcmp ( F_39 ( V_7 , V_67 ) , V_69 ,
V_7 -> V_43 ) == 0 ) )
V_4 -> V_5 = 1 ;
else if ( F_40 ( V_7 , V_67 ,
V_57 ,
V_38 , V_19 , NULL ) == 0 )
V_4 -> V_5 = 1 ;
else if ( F_27 ( V_7 ,
V_57 ,
V_38 ) ) {
V_29 = - V_72 ;
goto V_71;
}
}
V_19 += V_39 ;
memcpy ( V_69 , V_19 , V_7 -> V_43 ) ;
V_29 = 0 ;
V_71:
F_41 ( V_2 ) ;
return V_29 ;
}
int F_42 ( struct V_6 * V_7 , struct V_66 * V_67 ,
T_1 V_11 , T_2 * V_36 , bool * V_73 )
{
int V_29 = 0 , V_74 ;
if ( F_22 ( V_7 -> V_75 ) ) {
V_29 = F_34 ( V_7 , V_67 , V_11 , 0 , true , V_36 ) ;
if ( F_22 ( V_29 <= 0 ) )
goto V_37;
}
memcpy ( V_36 , V_7 -> V_76 , V_7 -> V_43 ) ;
for ( V_74 = V_7 -> V_75 - 1 ; V_74 >= 0 ; V_74 -- ) {
V_29 = F_34 ( V_7 , V_67 , V_11 , V_74 , false , V_36 ) ;
if ( F_12 ( V_29 ) )
goto V_37;
}
V_37:
if ( ! V_29 && V_7 -> V_77 )
* V_73 = ! memcmp ( V_7 -> V_77 , V_36 , V_7 -> V_43 ) ;
else
* V_73 = false ;
return V_29 ;
}
int F_43 ( struct V_6 * V_7 , struct V_66 * V_67 ,
struct V_78 * V_79 , struct V_17 * V_18 )
{
unsigned int V_80 = 1 << V_7 -> V_81 ;
struct V_82 * V_82 = F_44 ( V_67 , V_7 -> V_10 -> V_83 ) ;
struct V_27 V_28 ;
struct V_24 * V_25 = F_38 ( V_7 , V_67 ) ;
do {
int V_29 ;
unsigned int V_26 ;
struct V_84 V_85 = F_45 ( V_82 , * V_79 ) ;
F_46 ( & V_28 , 1 ) ;
V_26 = V_85 . V_86 ;
if ( F_22 ( V_26 >= V_80 ) )
V_26 = V_80 ;
F_47 ( & V_28 , V_85 . V_87 , V_26 , V_85 . V_88 ) ;
F_15 ( V_25 , & V_28 , NULL , V_26 ) ;
V_29 = F_8 ( V_18 , F_16 ( V_25 ) ) ;
if ( F_12 ( V_29 < 0 ) ) {
F_11 ( L_12 , V_29 ) ;
return V_29 ;
}
F_48 ( V_82 , V_79 , V_26 ) ;
V_80 -= V_26 ;
} while ( V_80 );
return 0 ;
}
int F_49 ( struct V_6 * V_7 , struct V_66 * V_67 ,
struct V_78 * V_79 ,
int (* F_50)( struct V_6 * V_7 ,
struct V_66 * V_67 , T_2 * V_19 ,
T_3 V_26 ) )
{
unsigned V_80 = 1 << V_7 -> V_81 ;
struct V_82 * V_82 = F_44 ( V_67 , V_7 -> V_10 -> V_83 ) ;
do {
int V_29 ;
T_2 * V_89 ;
unsigned V_26 ;
struct V_84 V_85 = F_45 ( V_82 , * V_79 ) ;
V_89 = F_51 ( V_85 . V_87 ) ;
V_26 = V_85 . V_86 ;
if ( F_22 ( V_26 >= V_80 ) )
V_26 = V_80 ;
V_29 = F_50 ( V_7 , V_67 , V_89 + V_85 . V_88 , V_26 ) ;
F_52 ( V_89 ) ;
if ( V_29 < 0 )
return V_29 ;
F_48 ( V_82 , V_79 , V_26 ) ;
V_80 -= V_26 ;
} while ( V_80 );
return 0 ;
}
static int F_53 ( struct V_6 * V_7 , struct V_66 * V_67 ,
T_2 * V_19 , T_3 V_26 )
{
memset ( V_19 , 0 , V_26 ) ;
return 0 ;
}
static int F_54 ( struct V_66 * V_67 )
{
bool V_73 ;
struct V_6 * V_7 = V_67 -> V_7 ;
struct V_78 V_90 ;
unsigned V_91 ;
struct V_17 V_18 ;
for ( V_91 = 0 ; V_91 < V_67 -> V_92 ; V_91 ++ ) {
int V_29 ;
struct V_24 * V_25 = F_38 ( V_7 , V_67 ) ;
V_29 = F_42 ( V_7 , V_67 , V_67 -> V_11 + V_91 ,
F_55 ( V_7 , V_67 ) ,
& V_73 ) ;
if ( F_12 ( V_29 < 0 ) )
return V_29 ;
if ( V_73 ) {
V_29 = F_49 ( V_7 , V_67 , & V_67 -> V_79 ,
F_53 ) ;
if ( F_12 ( V_29 < 0 ) )
return V_29 ;
continue;
}
V_29 = F_17 ( V_7 , V_25 , & V_18 ) ;
if ( F_12 ( V_29 < 0 ) )
return V_29 ;
V_90 = V_67 -> V_79 ;
V_29 = F_43 ( V_7 , V_67 , & V_67 -> V_79 , & V_18 ) ;
if ( F_12 ( V_29 < 0 ) )
return V_29 ;
V_29 = F_23 ( V_7 , V_25 , F_39 ( V_7 , V_67 ) ,
& V_18 ) ;
if ( F_12 ( V_29 < 0 ) )
return V_29 ;
if ( F_22 ( memcmp ( F_39 ( V_7 , V_67 ) ,
F_55 ( V_7 , V_67 ) , V_7 -> V_43 ) == 0 ) )
continue;
else if ( F_40 ( V_7 , V_67 , V_56 ,
V_67 -> V_11 + V_91 , NULL , & V_90 ) == 0 )
continue;
else if ( F_27 ( V_7 , V_56 ,
V_67 -> V_11 + V_91 ) )
return - V_72 ;
}
return 0 ;
}
static void F_56 ( struct V_66 * V_67 , T_4 V_93 )
{
struct V_6 * V_7 = V_67 -> V_7 ;
struct V_82 * V_82 = F_44 ( V_67 , V_7 -> V_10 -> V_83 ) ;
V_82 -> V_94 = V_67 -> V_95 ;
V_82 -> V_96 = V_93 ;
F_57 ( V_67 ) ;
F_58 ( V_82 ) ;
}
static void F_59 ( struct V_97 * V_98 )
{
struct V_66 * V_67 = F_60 ( V_98 , struct V_66 , V_99 ) ;
F_56 ( V_67 , F_61 ( F_54 ( V_67 ) ) ) ;
}
static void F_62 ( struct V_82 * V_82 )
{
struct V_66 * V_67 = V_82 -> V_100 ;
if ( V_82 -> V_96 && ! F_63 ( V_67 -> V_7 ) ) {
F_56 ( V_67 , V_82 -> V_96 ) ;
return;
}
F_64 ( & V_67 -> V_99 , F_59 ) ;
F_65 ( V_67 -> V_7 -> V_101 , & V_67 -> V_99 ) ;
}
static void F_66 ( struct V_97 * V_99 )
{
struct V_102 * V_103 =
F_60 ( V_99 , struct V_102 , V_99 ) ;
struct V_6 * V_7 = V_103 -> V_7 ;
int V_74 ;
for ( V_74 = V_7 -> V_75 - 2 ; V_74 >= 0 ; V_74 -- ) {
T_1 V_104 ;
T_1 V_105 ;
F_26 ( V_7 , V_103 -> V_11 , V_74 , & V_104 , NULL ) ;
F_26 ( V_7 , V_103 -> V_11 + V_103 -> V_92 - 1 , V_74 , & V_105 , NULL ) ;
if ( ! V_74 ) {
unsigned V_106 = F_67 ( V_107 ) ;
V_106 >>= V_7 -> V_81 ;
if ( F_12 ( ! V_106 ) )
goto V_108;
if ( F_12 ( V_106 & ( V_106 - 1 ) ) )
V_106 = 1 << F_68 ( V_106 ) ;
V_104 &= ~ ( T_1 ) ( V_106 - 1 ) ;
V_105 |= V_106 - 1 ;
if ( F_12 ( V_105 >= V_7 -> V_109 ) )
V_105 = V_7 -> V_109 - 1 ;
}
V_108:
F_69 ( V_7 -> V_70 , V_104 ,
V_105 - V_104 + 1 ) ;
}
F_70 ( V_103 ) ;
}
static void F_71 ( struct V_6 * V_7 , struct V_66 * V_67 )
{
struct V_102 * V_103 ;
V_103 = F_72 ( sizeof( struct V_102 ) ,
V_110 | V_111 | V_112 | V_113 ) ;
if ( ! V_103 )
return;
F_64 ( & V_103 -> V_99 , F_66 ) ;
V_103 -> V_7 = V_7 ;
V_103 -> V_11 = V_67 -> V_11 ;
V_103 -> V_92 = V_67 -> V_92 ;
F_65 ( V_7 -> V_101 , & V_103 -> V_99 ) ;
}
static int F_73 ( struct V_114 * V_10 , struct V_82 * V_82 )
{
struct V_6 * V_7 = V_10 -> V_115 ;
struct V_66 * V_67 ;
V_82 -> V_116 = V_7 -> V_58 -> V_117 ;
V_82 -> V_118 . V_8 = F_3 ( V_7 , V_82 -> V_118 . V_8 ) ;
if ( ( ( unsigned ) V_82 -> V_118 . V_8 | F_74 ( V_82 ) ) &
( ( 1 << ( V_7 -> V_81 - V_119 ) ) - 1 ) ) {
F_75 ( L_13 ) ;
return V_120 ;
}
if ( F_76 ( V_82 ) >>
( V_7 -> V_81 - V_119 ) > V_7 -> V_121 ) {
F_75 ( L_14 ) ;
return V_120 ;
}
if ( F_77 ( V_82 ) == V_122 )
return V_120 ;
V_67 = F_78 ( V_82 , V_10 -> V_83 ) ;
V_67 -> V_7 = V_7 ;
V_67 -> V_95 = V_82 -> V_94 ;
V_67 -> V_11 = V_82 -> V_118 . V_8 >> ( V_7 -> V_81 - V_119 ) ;
V_67 -> V_92 = V_82 -> V_118 . V_123 >> V_7 -> V_81 ;
V_82 -> V_94 = F_62 ;
V_82 -> V_100 = V_67 ;
V_67 -> V_79 = V_82 -> V_118 ;
F_79 ( V_67 ) ;
F_71 ( V_7 , V_67 ) ;
F_80 ( V_82 ) ;
return V_124 ;
}
static void F_81 ( struct V_114 * V_10 , T_5 type ,
unsigned V_125 , char * V_126 , unsigned V_127 )
{
struct V_6 * V_7 = V_10 -> V_115 ;
unsigned args = 0 ;
unsigned V_128 = 0 ;
unsigned V_129 ;
switch ( type ) {
case V_130 :
F_82 ( L_15 , V_7 -> V_53 ? 'C' : 'V' ) ;
break;
case V_131 :
F_82 ( L_16 ,
V_7 -> V_34 ,
V_7 -> V_58 -> V_59 ,
V_7 -> V_132 -> V_59 ,
1 << V_7 -> V_81 ,
1 << V_7 -> V_44 ,
( unsigned long long ) V_7 -> V_121 ,
( unsigned long long ) V_7 -> V_133 ,
V_7 -> V_134
) ;
for ( V_129 = 0 ; V_129 < V_7 -> V_43 ; V_129 ++ )
F_82 ( L_17 , V_7 -> V_76 [ V_129 ] ) ;
F_82 ( L_18 ) ;
if ( ! V_7 -> V_33 )
F_82 ( L_19 ) ;
else
for ( V_129 = 0 ; V_129 < V_7 -> V_33 ; V_129 ++ )
F_82 ( L_17 , V_7 -> V_35 [ V_129 ] ) ;
if ( V_7 -> V_63 != V_135 )
args ++ ;
if ( F_63 ( V_7 ) )
args += V_136 ;
if ( V_7 -> V_77 )
args ++ ;
if ( ! args )
return;
F_82 ( L_20 , args ) ;
if ( V_7 -> V_63 != V_135 ) {
F_82 ( L_18 ) ;
switch ( V_7 -> V_63 ) {
case V_64 :
F_82 ( V_137 ) ;
break;
case V_65 :
F_82 ( V_138 ) ;
break;
default:
F_29 () ;
}
}
if ( V_7 -> V_77 )
F_82 ( L_18 V_139 ) ;
V_128 = F_83 ( V_7 , V_128 , V_126 , V_127 ) ;
break;
}
}
static int F_84 ( struct V_114 * V_10 ,
struct V_140 * * V_117 , T_6 * V_63 )
{
struct V_6 * V_7 = V_10 -> V_115 ;
* V_117 = V_7 -> V_58 -> V_117 ;
if ( V_7 -> V_9 ||
V_10 -> V_26 != F_85 ( V_7 -> V_58 -> V_117 -> V_141 ) >> V_119 )
return 1 ;
return 0 ;
}
static int F_86 ( struct V_114 * V_10 ,
T_7 V_142 , void * V_19 )
{
struct V_6 * V_7 = V_10 -> V_115 ;
return V_142 ( V_10 , V_7 -> V_58 , V_7 -> V_9 , V_10 -> V_26 , V_19 ) ;
}
static void F_87 ( struct V_114 * V_10 , struct V_143 * V_144 )
{
struct V_6 * V_7 = V_10 -> V_115 ;
if ( V_144 -> V_145 < 1 << V_7 -> V_81 )
V_144 -> V_145 = 1 << V_7 -> V_81 ;
if ( V_144 -> V_146 < 1 << V_7 -> V_81 )
V_144 -> V_146 = 1 << V_7 -> V_81 ;
F_88 ( V_144 , V_144 -> V_145 ) ;
}
static void F_89 ( struct V_114 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_115 ;
if ( V_7 -> V_101 )
F_90 ( V_7 -> V_101 ) ;
if ( V_7 -> V_70 )
F_91 ( V_7 -> V_70 ) ;
F_70 ( V_7 -> V_35 ) ;
F_70 ( V_7 -> V_76 ) ;
F_70 ( V_7 -> V_77 ) ;
if ( V_7 -> V_30 )
F_92 ( V_7 -> V_30 ) ;
F_70 ( V_7 -> V_134 ) ;
if ( V_7 -> V_132 )
F_93 ( V_10 , V_7 -> V_132 ) ;
if ( V_7 -> V_58 )
F_93 ( V_10 , V_7 -> V_58 ) ;
F_94 ( V_7 ) ;
F_70 ( V_7 ) ;
}
static int F_95 ( struct V_6 * V_7 )
{
int V_29 = - V_147 ;
struct V_24 * V_25 ;
T_2 * V_148 ;
V_7 -> V_77 = F_72 ( V_7 -> V_43 , V_149 ) ;
if ( ! V_7 -> V_77 )
return V_29 ;
V_25 = F_72 ( V_7 -> V_150 , V_149 ) ;
if ( ! V_25 )
return V_29 ;
V_148 = F_96 ( 1 << V_7 -> V_81 , V_149 ) ;
if ( ! V_148 )
goto V_37;
V_29 = F_25 ( V_7 , V_25 , V_148 , 1 << V_7 -> V_81 ,
V_7 -> V_77 ) ;
V_37:
F_70 ( V_25 ) ;
F_70 ( V_148 ) ;
return V_29 ;
}
static int F_97 ( struct V_151 * V_152 , struct V_6 * V_7 )
{
int V_29 ;
unsigned V_153 ;
struct V_114 * V_10 = V_7 -> V_10 ;
const char * V_154 ;
static struct V_155 V_156 [] = {
{ 0 , V_157 , L_21 } ,
} ;
V_29 = F_98 ( V_156 , V_152 , & V_153 , & V_10 -> error ) ;
if ( V_29 )
return - V_158 ;
if ( ! V_153 )
return 0 ;
do {
V_154 = F_99 ( V_152 ) ;
V_153 -- ;
if ( ! strcasecmp ( V_154 , V_137 ) ) {
V_7 -> V_63 = V_64 ;
continue;
} else if ( ! strcasecmp ( V_154 , V_138 ) ) {
V_7 -> V_63 = V_65 ;
continue;
} else if ( ! strcasecmp ( V_154 , V_139 ) ) {
V_29 = F_95 ( V_7 ) ;
if ( V_29 ) {
V_10 -> error = L_22 ;
return V_29 ;
}
continue;
} else if ( F_100 ( V_154 ) ) {
V_29 = F_101 ( V_152 , V_7 , & V_153 , V_154 ) ;
if ( V_29 )
return V_29 ;
continue;
}
V_10 -> error = L_23 ;
return - V_158 ;
} while ( V_153 && ! V_29 );
return V_29 ;
}
static int F_102 ( struct V_114 * V_10 , unsigned V_153 , char * * V_159 )
{
struct V_6 * V_7 ;
struct V_151 V_152 ;
unsigned int V_160 ;
unsigned long long V_161 ;
int V_29 ;
int V_74 ;
T_1 V_162 ;
char V_163 ;
V_7 = F_96 ( sizeof( struct V_6 ) , V_149 ) ;
if ( ! V_7 ) {
V_10 -> error = L_24 ;
return - V_147 ;
}
V_10 -> V_115 = V_7 ;
V_7 -> V_10 = V_10 ;
V_29 = F_103 ( V_7 ) ;
if ( V_29 )
goto V_164;
if ( ( F_104 ( V_10 -> V_52 ) & ~ V_165 ) ) {
V_10 -> error = L_25 ;
V_29 = - V_158 ;
goto V_164;
}
if ( V_153 < 10 ) {
V_10 -> error = L_26 ;
V_29 = - V_158 ;
goto V_164;
}
if ( sscanf ( V_159 [ 0 ] , L_27 , & V_160 , & V_163 ) != 1 ||
V_160 > 1 ) {
V_10 -> error = L_28 ;
V_29 = - V_158 ;
goto V_164;
}
V_7 -> V_34 = V_160 ;
V_29 = F_105 ( V_10 , V_159 [ 1 ] , V_165 , & V_7 -> V_58 ) ;
if ( V_29 ) {
V_10 -> error = L_29 ;
goto V_164;
}
V_29 = F_105 ( V_10 , V_159 [ 2 ] , V_165 , & V_7 -> V_132 ) ;
if ( V_29 ) {
V_10 -> error = L_30 ;
goto V_164;
}
if ( sscanf ( V_159 [ 3 ] , L_27 , & V_160 , & V_163 ) != 1 ||
! V_160 || ( V_160 & ( V_160 - 1 ) ) ||
V_160 < V_166 ( V_7 -> V_58 -> V_117 ) ||
V_160 > V_167 ) {
V_10 -> error = L_31 ;
V_29 = - V_158 ;
goto V_164;
}
V_7 -> V_81 = F_106 ( V_160 ) ;
if ( sscanf ( V_159 [ 4 ] , L_27 , & V_160 , & V_163 ) != 1 ||
! V_160 || ( V_160 & ( V_160 - 1 ) ) ||
V_160 < V_166 ( V_7 -> V_132 -> V_117 ) ||
V_160 > V_168 ) {
V_10 -> error = L_32 ;
V_29 = - V_158 ;
goto V_164;
}
V_7 -> V_44 = F_106 ( V_160 ) ;
if ( sscanf ( V_159 [ 5 ] , L_33 , & V_161 , & V_163 ) != 1 ||
( T_1 ) ( V_161 << ( V_7 -> V_81 - V_119 ) )
>> ( V_7 -> V_81 - V_119 ) != V_161 ) {
V_10 -> error = L_34 ;
V_29 = - V_158 ;
goto V_164;
}
V_7 -> V_121 = V_161 ;
if ( V_10 -> V_26 > ( V_7 -> V_121 << ( V_7 -> V_81 - V_119 ) ) ) {
V_10 -> error = L_35 ;
V_29 = - V_158 ;
goto V_164;
}
if ( sscanf ( V_159 [ 6 ] , L_33 , & V_161 , & V_163 ) != 1 ||
( T_1 ) ( V_161 << ( V_7 -> V_44 - V_119 ) )
>> ( V_7 -> V_44 - V_119 ) != V_161 ) {
V_10 -> error = L_36 ;
V_29 = - V_158 ;
goto V_164;
}
V_7 -> V_133 = V_161 ;
V_7 -> V_134 = F_107 ( V_159 [ 7 ] , V_149 ) ;
if ( ! V_7 -> V_134 ) {
V_10 -> error = L_37 ;
V_29 = - V_147 ;
goto V_164;
}
V_7 -> V_30 = F_108 ( V_7 -> V_134 , 0 , 0 ) ;
if ( F_36 ( V_7 -> V_30 ) ) {
V_10 -> error = L_38 ;
V_29 = F_37 ( V_7 -> V_30 ) ;
V_7 -> V_30 = NULL ;
goto V_164;
}
V_7 -> V_43 = F_109 ( V_7 -> V_30 ) ;
if ( ( 1 << V_7 -> V_44 ) < V_7 -> V_43 * 2 ) {
V_10 -> error = L_39 ;
V_29 = - V_158 ;
goto V_164;
}
V_7 -> V_150 = sizeof( struct V_24 ) +
F_110 ( V_7 -> V_30 ) ;
V_7 -> V_76 = F_72 ( V_7 -> V_43 , V_149 ) ;
if ( ! V_7 -> V_76 ) {
V_10 -> error = L_40 ;
V_29 = - V_147 ;
goto V_164;
}
if ( strlen ( V_159 [ 8 ] ) != V_7 -> V_43 * 2 ||
F_111 ( V_7 -> V_76 , V_159 [ 8 ] , V_7 -> V_43 ) ) {
V_10 -> error = L_41 ;
V_29 = - V_158 ;
goto V_164;
}
if ( strcmp ( V_159 [ 9 ] , L_19 ) ) {
V_7 -> V_33 = strlen ( V_159 [ 9 ] ) / 2 ;
V_7 -> V_35 = F_72 ( V_7 -> V_33 , V_149 ) ;
if ( ! V_7 -> V_35 ) {
V_10 -> error = L_42 ;
V_29 = - V_147 ;
goto V_164;
}
if ( strlen ( V_159 [ 9 ] ) != V_7 -> V_33 * 2 ||
F_111 ( V_7 -> V_35 , V_159 [ 9 ] , V_7 -> V_33 ) ) {
V_10 -> error = L_43 ;
V_29 = - V_158 ;
goto V_164;
}
}
V_159 += 10 ;
V_153 -= 10 ;
if ( V_153 ) {
V_152 . V_153 = V_153 ;
V_152 . V_159 = V_159 ;
V_29 = F_97 ( & V_152 , V_7 ) ;
if ( V_29 < 0 )
goto V_164;
}
V_7 -> V_13 =
F_68 ( ( 1 << V_7 -> V_44 ) / V_7 -> V_43 ) ;
V_7 -> V_75 = 0 ;
if ( V_7 -> V_121 )
while ( V_7 -> V_13 * V_7 -> V_75 < 64 &&
( unsigned long long ) ( V_7 -> V_121 - 1 ) >>
( V_7 -> V_13 * V_7 -> V_75 ) )
V_7 -> V_75 ++ ;
if ( V_7 -> V_75 > V_169 ) {
V_10 -> error = L_44 ;
V_29 = - V_170 ;
goto V_164;
}
V_162 = V_7 -> V_133 ;
for ( V_74 = V_7 -> V_75 - 1 ; V_74 >= 0 ; V_74 -- ) {
T_1 V_171 ;
V_7 -> V_42 [ V_74 ] = V_162 ;
V_171 = ( V_7 -> V_121 + ( ( T_1 ) 1 << ( ( V_74 + 1 ) * V_7 -> V_13 ) ) - 1 )
>> ( ( V_74 + 1 ) * V_7 -> V_13 ) ;
if ( V_162 + V_171 < V_162 ) {
V_10 -> error = L_45 ;
V_29 = - V_170 ;
goto V_164;
}
V_162 += V_171 ;
}
V_7 -> V_109 = V_162 ;
V_7 -> V_70 = F_112 ( V_7 -> V_132 -> V_117 ,
1 << V_7 -> V_44 , 1 , sizeof( struct V_3 ) ,
F_1 , NULL ) ;
if ( F_36 ( V_7 -> V_70 ) ) {
V_10 -> error = L_46 ;
V_29 = F_37 ( V_7 -> V_70 ) ;
V_7 -> V_70 = NULL ;
goto V_164;
}
if ( F_113 ( V_7 -> V_70 ) < V_7 -> V_109 ) {
V_10 -> error = L_47 ;
V_29 = - V_170 ;
goto V_164;
}
V_7 -> V_101 = F_114 ( L_48 , V_172 | V_173 | V_174 , F_115 () ) ;
if ( ! V_7 -> V_101 ) {
V_10 -> error = L_49 ;
V_29 = - V_147 ;
goto V_164;
}
V_10 -> V_83 = sizeof( struct V_66 ) +
V_7 -> V_150 + V_7 -> V_43 * 2 ;
V_29 = F_116 ( V_7 ) ;
if ( V_29 )
goto V_164;
V_10 -> V_83 = F_117 ( V_10 -> V_83 ,
F_118 ( struct V_66 ) ) ;
return 0 ;
V_164:
F_89 ( V_10 ) ;
return V_29 ;
}
static int T_8 F_119 ( void )
{
int V_29 ;
V_29 = F_120 ( & V_175 ) ;
if ( V_29 < 0 )
F_11 ( L_50 , V_29 ) ;
return V_29 ;
}
static void T_9 F_121 ( void )
{
F_122 ( & V_175 ) ;
}

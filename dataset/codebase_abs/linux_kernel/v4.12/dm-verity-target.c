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
static void F_56 ( struct V_66 * V_67 , int error )
{
struct V_6 * V_7 = V_67 -> V_7 ;
struct V_82 * V_82 = F_44 ( V_67 , V_7 -> V_10 -> V_83 ) ;
V_82 -> V_93 = V_67 -> V_94 ;
V_82 -> V_95 = error ;
F_57 ( V_67 ) ;
F_58 ( V_82 ) ;
}
static void F_59 ( struct V_96 * V_97 )
{
struct V_66 * V_67 = F_60 ( V_97 , struct V_66 , V_98 ) ;
F_56 ( V_67 , F_54 ( V_67 ) ) ;
}
static void F_61 ( struct V_82 * V_82 )
{
struct V_66 * V_67 = V_82 -> V_99 ;
if ( V_82 -> V_95 && ! F_62 ( V_67 -> V_7 ) ) {
F_56 ( V_67 , V_82 -> V_95 ) ;
return;
}
F_63 ( & V_67 -> V_98 , F_59 ) ;
F_64 ( V_67 -> V_7 -> V_100 , & V_67 -> V_98 ) ;
}
static void F_65 ( struct V_96 * V_98 )
{
struct V_101 * V_102 =
F_60 ( V_98 , struct V_101 , V_98 ) ;
struct V_6 * V_7 = V_102 -> V_7 ;
int V_74 ;
for ( V_74 = V_7 -> V_75 - 2 ; V_74 >= 0 ; V_74 -- ) {
T_1 V_103 ;
T_1 V_104 ;
F_26 ( V_7 , V_102 -> V_11 , V_74 , & V_103 , NULL ) ;
F_26 ( V_7 , V_102 -> V_11 + V_102 -> V_92 - 1 , V_74 , & V_104 , NULL ) ;
if ( ! V_74 ) {
unsigned V_105 = F_66 ( V_106 ) ;
V_105 >>= V_7 -> V_81 ;
if ( F_12 ( ! V_105 ) )
goto V_107;
if ( F_12 ( V_105 & ( V_105 - 1 ) ) )
V_105 = 1 << F_67 ( V_105 ) ;
V_103 &= ~ ( T_1 ) ( V_105 - 1 ) ;
V_104 |= V_105 - 1 ;
if ( F_12 ( V_104 >= V_7 -> V_108 ) )
V_104 = V_7 -> V_108 - 1 ;
}
V_107:
F_68 ( V_7 -> V_70 , V_103 ,
V_104 - V_103 + 1 ) ;
}
F_69 ( V_102 ) ;
}
static void F_70 ( struct V_6 * V_7 , struct V_66 * V_67 )
{
struct V_101 * V_102 ;
V_102 = F_71 ( sizeof( struct V_101 ) ,
V_109 | V_110 | V_111 | V_112 ) ;
if ( ! V_102 )
return;
F_63 ( & V_102 -> V_98 , F_65 ) ;
V_102 -> V_7 = V_7 ;
V_102 -> V_11 = V_67 -> V_11 ;
V_102 -> V_92 = V_67 -> V_92 ;
F_64 ( V_7 -> V_100 , & V_102 -> V_98 ) ;
}
static int F_72 ( struct V_113 * V_10 , struct V_82 * V_82 )
{
struct V_6 * V_7 = V_10 -> V_114 ;
struct V_66 * V_67 ;
V_82 -> V_115 = V_7 -> V_58 -> V_116 ;
V_82 -> V_117 . V_8 = F_3 ( V_7 , V_82 -> V_117 . V_8 ) ;
if ( ( ( unsigned ) V_82 -> V_117 . V_8 | F_73 ( V_82 ) ) &
( ( 1 << ( V_7 -> V_81 - V_118 ) ) - 1 ) ) {
F_74 ( L_13 ) ;
return - V_72 ;
}
if ( F_75 ( V_82 ) >>
( V_7 -> V_81 - V_118 ) > V_7 -> V_119 ) {
F_74 ( L_14 ) ;
return - V_72 ;
}
if ( F_76 ( V_82 ) == V_120 )
return - V_72 ;
V_67 = F_77 ( V_82 , V_10 -> V_83 ) ;
V_67 -> V_7 = V_7 ;
V_67 -> V_94 = V_82 -> V_93 ;
V_67 -> V_11 = V_82 -> V_117 . V_8 >> ( V_7 -> V_81 - V_118 ) ;
V_67 -> V_92 = V_82 -> V_117 . V_121 >> V_7 -> V_81 ;
V_82 -> V_93 = F_61 ;
V_82 -> V_99 = V_67 ;
V_67 -> V_79 = V_82 -> V_117 ;
F_78 ( V_67 ) ;
F_70 ( V_7 , V_67 ) ;
F_79 ( V_82 ) ;
return V_122 ;
}
static void F_80 ( struct V_113 * V_10 , T_4 type ,
unsigned V_123 , char * V_124 , unsigned V_125 )
{
struct V_6 * V_7 = V_10 -> V_114 ;
unsigned args = 0 ;
unsigned V_126 = 0 ;
unsigned V_127 ;
switch ( type ) {
case V_128 :
F_81 ( L_15 , V_7 -> V_53 ? 'C' : 'V' ) ;
break;
case V_129 :
F_81 ( L_16 ,
V_7 -> V_34 ,
V_7 -> V_58 -> V_59 ,
V_7 -> V_130 -> V_59 ,
1 << V_7 -> V_81 ,
1 << V_7 -> V_44 ,
( unsigned long long ) V_7 -> V_119 ,
( unsigned long long ) V_7 -> V_131 ,
V_7 -> V_132
) ;
for ( V_127 = 0 ; V_127 < V_7 -> V_43 ; V_127 ++ )
F_81 ( L_17 , V_7 -> V_76 [ V_127 ] ) ;
F_81 ( L_18 ) ;
if ( ! V_7 -> V_33 )
F_81 ( L_19 ) ;
else
for ( V_127 = 0 ; V_127 < V_7 -> V_33 ; V_127 ++ )
F_81 ( L_17 , V_7 -> V_35 [ V_127 ] ) ;
if ( V_7 -> V_63 != V_133 )
args ++ ;
if ( F_62 ( V_7 ) )
args += V_134 ;
if ( V_7 -> V_77 )
args ++ ;
if ( ! args )
return;
F_81 ( L_20 , args ) ;
if ( V_7 -> V_63 != V_133 ) {
F_81 ( L_18 ) ;
switch ( V_7 -> V_63 ) {
case V_64 :
F_81 ( V_135 ) ;
break;
case V_65 :
F_81 ( V_136 ) ;
break;
default:
F_29 () ;
}
}
if ( V_7 -> V_77 )
F_81 ( L_18 V_137 ) ;
V_126 = F_82 ( V_7 , V_126 , V_124 , V_125 ) ;
break;
}
}
static int F_83 ( struct V_113 * V_10 ,
struct V_138 * * V_116 , T_5 * V_63 )
{
struct V_6 * V_7 = V_10 -> V_114 ;
* V_116 = V_7 -> V_58 -> V_116 ;
if ( V_7 -> V_9 ||
V_10 -> V_26 != F_84 ( V_7 -> V_58 -> V_116 -> V_139 ) >> V_118 )
return 1 ;
return 0 ;
}
static int F_85 ( struct V_113 * V_10 ,
T_6 V_140 , void * V_19 )
{
struct V_6 * V_7 = V_10 -> V_114 ;
return V_140 ( V_10 , V_7 -> V_58 , V_7 -> V_9 , V_10 -> V_26 , V_19 ) ;
}
static void F_86 ( struct V_113 * V_10 , struct V_141 * V_142 )
{
struct V_6 * V_7 = V_10 -> V_114 ;
if ( V_142 -> V_143 < 1 << V_7 -> V_81 )
V_142 -> V_143 = 1 << V_7 -> V_81 ;
if ( V_142 -> V_144 < 1 << V_7 -> V_81 )
V_142 -> V_144 = 1 << V_7 -> V_81 ;
F_87 ( V_142 , V_142 -> V_143 ) ;
}
static void F_88 ( struct V_113 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_114 ;
if ( V_7 -> V_100 )
F_89 ( V_7 -> V_100 ) ;
if ( V_7 -> V_70 )
F_90 ( V_7 -> V_70 ) ;
F_69 ( V_7 -> V_35 ) ;
F_69 ( V_7 -> V_76 ) ;
F_69 ( V_7 -> V_77 ) ;
if ( V_7 -> V_30 )
F_91 ( V_7 -> V_30 ) ;
F_69 ( V_7 -> V_132 ) ;
if ( V_7 -> V_130 )
F_92 ( V_10 , V_7 -> V_130 ) ;
if ( V_7 -> V_58 )
F_92 ( V_10 , V_7 -> V_58 ) ;
F_93 ( V_7 ) ;
F_69 ( V_7 ) ;
}
static int F_94 ( struct V_6 * V_7 )
{
int V_29 = - V_145 ;
struct V_24 * V_25 ;
T_2 * V_146 ;
V_7 -> V_77 = F_71 ( V_7 -> V_43 , V_147 ) ;
if ( ! V_7 -> V_77 )
return V_29 ;
V_25 = F_71 ( V_7 -> V_148 , V_147 ) ;
if ( ! V_25 )
return V_29 ;
V_146 = F_95 ( 1 << V_7 -> V_81 , V_147 ) ;
if ( ! V_146 )
goto V_37;
V_29 = F_25 ( V_7 , V_25 , V_146 , 1 << V_7 -> V_81 ,
V_7 -> V_77 ) ;
V_37:
F_69 ( V_25 ) ;
F_69 ( V_146 ) ;
return V_29 ;
}
static int F_96 ( struct V_149 * V_150 , struct V_6 * V_7 )
{
int V_29 ;
unsigned V_151 ;
struct V_113 * V_10 = V_7 -> V_10 ;
const char * V_152 ;
static struct V_153 V_154 [] = {
{ 0 , V_155 , L_21 } ,
} ;
V_29 = F_97 ( V_154 , V_150 , & V_151 , & V_10 -> error ) ;
if ( V_29 )
return - V_156 ;
if ( ! V_151 )
return 0 ;
do {
V_152 = F_98 ( V_150 ) ;
V_151 -- ;
if ( ! strcasecmp ( V_152 , V_135 ) ) {
V_7 -> V_63 = V_64 ;
continue;
} else if ( ! strcasecmp ( V_152 , V_136 ) ) {
V_7 -> V_63 = V_65 ;
continue;
} else if ( ! strcasecmp ( V_152 , V_137 ) ) {
V_29 = F_94 ( V_7 ) ;
if ( V_29 ) {
V_10 -> error = L_22 ;
return V_29 ;
}
continue;
} else if ( F_99 ( V_152 ) ) {
V_29 = F_100 ( V_150 , V_7 , & V_151 , V_152 ) ;
if ( V_29 )
return V_29 ;
continue;
}
V_10 -> error = L_23 ;
return - V_156 ;
} while ( V_151 && ! V_29 );
return V_29 ;
}
static int F_101 ( struct V_113 * V_10 , unsigned V_151 , char * * V_157 )
{
struct V_6 * V_7 ;
struct V_149 V_150 ;
unsigned int V_158 ;
unsigned long long V_159 ;
int V_29 ;
int V_74 ;
T_1 V_160 ;
char V_161 ;
V_7 = F_95 ( sizeof( struct V_6 ) , V_147 ) ;
if ( ! V_7 ) {
V_10 -> error = L_24 ;
return - V_145 ;
}
V_10 -> V_114 = V_7 ;
V_7 -> V_10 = V_10 ;
V_29 = F_102 ( V_7 ) ;
if ( V_29 )
goto V_162;
if ( ( F_103 ( V_10 -> V_52 ) & ~ V_163 ) ) {
V_10 -> error = L_25 ;
V_29 = - V_156 ;
goto V_162;
}
if ( V_151 < 10 ) {
V_10 -> error = L_26 ;
V_29 = - V_156 ;
goto V_162;
}
if ( sscanf ( V_157 [ 0 ] , L_27 , & V_158 , & V_161 ) != 1 ||
V_158 > 1 ) {
V_10 -> error = L_28 ;
V_29 = - V_156 ;
goto V_162;
}
V_7 -> V_34 = V_158 ;
V_29 = F_104 ( V_10 , V_157 [ 1 ] , V_163 , & V_7 -> V_58 ) ;
if ( V_29 ) {
V_10 -> error = L_29 ;
goto V_162;
}
V_29 = F_104 ( V_10 , V_157 [ 2 ] , V_163 , & V_7 -> V_130 ) ;
if ( V_29 ) {
V_10 -> error = L_30 ;
goto V_162;
}
if ( sscanf ( V_157 [ 3 ] , L_27 , & V_158 , & V_161 ) != 1 ||
! V_158 || ( V_158 & ( V_158 - 1 ) ) ||
V_158 < V_164 ( V_7 -> V_58 -> V_116 ) ||
V_158 > V_165 ) {
V_10 -> error = L_31 ;
V_29 = - V_156 ;
goto V_162;
}
V_7 -> V_81 = F_105 ( V_158 ) ;
if ( sscanf ( V_157 [ 4 ] , L_27 , & V_158 , & V_161 ) != 1 ||
! V_158 || ( V_158 & ( V_158 - 1 ) ) ||
V_158 < V_164 ( V_7 -> V_130 -> V_116 ) ||
V_158 > V_166 ) {
V_10 -> error = L_32 ;
V_29 = - V_156 ;
goto V_162;
}
V_7 -> V_44 = F_105 ( V_158 ) ;
if ( sscanf ( V_157 [ 5 ] , L_33 , & V_159 , & V_161 ) != 1 ||
( T_1 ) ( V_159 << ( V_7 -> V_81 - V_118 ) )
>> ( V_7 -> V_81 - V_118 ) != V_159 ) {
V_10 -> error = L_34 ;
V_29 = - V_156 ;
goto V_162;
}
V_7 -> V_119 = V_159 ;
if ( V_10 -> V_26 > ( V_7 -> V_119 << ( V_7 -> V_81 - V_118 ) ) ) {
V_10 -> error = L_35 ;
V_29 = - V_156 ;
goto V_162;
}
if ( sscanf ( V_157 [ 6 ] , L_33 , & V_159 , & V_161 ) != 1 ||
( T_1 ) ( V_159 << ( V_7 -> V_44 - V_118 ) )
>> ( V_7 -> V_44 - V_118 ) != V_159 ) {
V_10 -> error = L_36 ;
V_29 = - V_156 ;
goto V_162;
}
V_7 -> V_131 = V_159 ;
V_7 -> V_132 = F_106 ( V_157 [ 7 ] , V_147 ) ;
if ( ! V_7 -> V_132 ) {
V_10 -> error = L_37 ;
V_29 = - V_145 ;
goto V_162;
}
V_7 -> V_30 = F_107 ( V_7 -> V_132 , 0 , 0 ) ;
if ( F_36 ( V_7 -> V_30 ) ) {
V_10 -> error = L_38 ;
V_29 = F_37 ( V_7 -> V_30 ) ;
V_7 -> V_30 = NULL ;
goto V_162;
}
V_7 -> V_43 = F_108 ( V_7 -> V_30 ) ;
if ( ( 1 << V_7 -> V_44 ) < V_7 -> V_43 * 2 ) {
V_10 -> error = L_39 ;
V_29 = - V_156 ;
goto V_162;
}
V_7 -> V_148 = sizeof( struct V_24 ) +
F_109 ( V_7 -> V_30 ) ;
V_7 -> V_76 = F_71 ( V_7 -> V_43 , V_147 ) ;
if ( ! V_7 -> V_76 ) {
V_10 -> error = L_40 ;
V_29 = - V_145 ;
goto V_162;
}
if ( strlen ( V_157 [ 8 ] ) != V_7 -> V_43 * 2 ||
F_110 ( V_7 -> V_76 , V_157 [ 8 ] , V_7 -> V_43 ) ) {
V_10 -> error = L_41 ;
V_29 = - V_156 ;
goto V_162;
}
if ( strcmp ( V_157 [ 9 ] , L_19 ) ) {
V_7 -> V_33 = strlen ( V_157 [ 9 ] ) / 2 ;
V_7 -> V_35 = F_71 ( V_7 -> V_33 , V_147 ) ;
if ( ! V_7 -> V_35 ) {
V_10 -> error = L_42 ;
V_29 = - V_145 ;
goto V_162;
}
if ( strlen ( V_157 [ 9 ] ) != V_7 -> V_33 * 2 ||
F_110 ( V_7 -> V_35 , V_157 [ 9 ] , V_7 -> V_33 ) ) {
V_10 -> error = L_43 ;
V_29 = - V_156 ;
goto V_162;
}
}
V_157 += 10 ;
V_151 -= 10 ;
if ( V_151 ) {
V_150 . V_151 = V_151 ;
V_150 . V_157 = V_157 ;
V_29 = F_96 ( & V_150 , V_7 ) ;
if ( V_29 < 0 )
goto V_162;
}
V_7 -> V_13 =
F_67 ( ( 1 << V_7 -> V_44 ) / V_7 -> V_43 ) ;
V_7 -> V_75 = 0 ;
if ( V_7 -> V_119 )
while ( V_7 -> V_13 * V_7 -> V_75 < 64 &&
( unsigned long long ) ( V_7 -> V_119 - 1 ) >>
( V_7 -> V_13 * V_7 -> V_75 ) )
V_7 -> V_75 ++ ;
if ( V_7 -> V_75 > V_167 ) {
V_10 -> error = L_44 ;
V_29 = - V_168 ;
goto V_162;
}
V_160 = V_7 -> V_131 ;
for ( V_74 = V_7 -> V_75 - 1 ; V_74 >= 0 ; V_74 -- ) {
T_1 V_169 ;
V_7 -> V_42 [ V_74 ] = V_160 ;
V_169 = ( V_7 -> V_119 + ( ( T_1 ) 1 << ( ( V_74 + 1 ) * V_7 -> V_13 ) ) - 1 )
>> ( ( V_74 + 1 ) * V_7 -> V_13 ) ;
if ( V_160 + V_169 < V_160 ) {
V_10 -> error = L_45 ;
V_29 = - V_168 ;
goto V_162;
}
V_160 += V_169 ;
}
V_7 -> V_108 = V_160 ;
V_7 -> V_70 = F_111 ( V_7 -> V_130 -> V_116 ,
1 << V_7 -> V_44 , 1 , sizeof( struct V_3 ) ,
F_1 , NULL ) ;
if ( F_36 ( V_7 -> V_70 ) ) {
V_10 -> error = L_46 ;
V_29 = F_37 ( V_7 -> V_70 ) ;
V_7 -> V_70 = NULL ;
goto V_162;
}
if ( F_112 ( V_7 -> V_70 ) < V_7 -> V_108 ) {
V_10 -> error = L_47 ;
V_29 = - V_168 ;
goto V_162;
}
V_7 -> V_100 = F_113 ( L_48 , V_170 | V_171 | V_172 , F_114 () ) ;
if ( ! V_7 -> V_100 ) {
V_10 -> error = L_49 ;
V_29 = - V_145 ;
goto V_162;
}
V_10 -> V_83 = sizeof( struct V_66 ) +
V_7 -> V_148 + V_7 -> V_43 * 2 ;
V_29 = F_115 ( V_7 ) ;
if ( V_29 )
goto V_162;
V_10 -> V_83 = F_116 ( V_10 -> V_83 ,
F_117 ( struct V_66 ) ) ;
return 0 ;
V_162:
F_88 ( V_10 ) ;
return V_29 ;
}
static int T_7 F_118 ( void )
{
int V_29 ;
V_29 = F_119 ( & V_173 ) ;
if ( V_29 < 0 )
F_11 ( L_50 , V_29 ) ;
return V_29 ;
}
static void T_8 F_120 ( void )
{
F_121 ( & V_173 ) ;
}

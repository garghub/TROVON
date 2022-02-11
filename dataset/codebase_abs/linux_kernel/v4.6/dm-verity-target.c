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
static int F_6 ( struct V_6 * V_7 , struct V_14 * V_15 )
{
int V_16 ;
V_15 -> V_17 = V_7 -> V_17 ;
V_15 -> V_18 = V_19 ;
V_16 = F_7 ( V_15 ) ;
if ( F_8 ( V_16 < 0 ) ) {
F_9 ( L_1 , V_16 ) ;
return V_16 ;
}
if ( F_10 ( V_7 -> V_20 >= 1 ) ) {
V_16 = F_11 ( V_15 , V_7 -> V_21 , V_7 -> V_22 ) ;
if ( F_8 ( V_16 < 0 ) ) {
F_9 ( L_2 , V_16 ) ;
return V_16 ;
}
}
return 0 ;
}
static int F_12 ( struct V_6 * V_7 , struct V_14 * V_15 ,
const T_2 * V_23 , T_3 V_24 )
{
int V_16 = F_11 ( V_15 , V_23 , V_24 ) ;
if ( F_8 ( V_16 < 0 ) )
F_9 ( L_2 , V_16 ) ;
return V_16 ;
}
static int F_13 ( struct V_6 * V_7 , struct V_14 * V_15 ,
T_2 * V_25 )
{
int V_16 ;
if ( F_8 ( ! V_7 -> V_20 ) ) {
V_16 = F_11 ( V_15 , V_7 -> V_21 , V_7 -> V_22 ) ;
if ( V_16 < 0 ) {
F_9 ( L_2 , V_16 ) ;
return V_16 ;
}
}
V_16 = F_14 ( V_15 , V_25 ) ;
if ( F_8 ( V_16 < 0 ) )
F_9 ( L_3 , V_16 ) ;
return V_16 ;
}
int F_15 ( struct V_6 * V_7 , struct V_14 * V_15 ,
const T_2 * V_23 , T_3 V_24 , T_2 * V_25 )
{
int V_16 ;
V_16 = F_6 ( V_7 , V_15 ) ;
if ( F_8 ( V_16 < 0 ) )
return V_16 ;
V_16 = F_12 ( V_7 , V_15 , V_23 , V_24 ) ;
if ( F_8 ( V_16 < 0 ) )
return V_16 ;
return F_13 ( V_7 , V_15 , V_25 ) ;
}
static void F_16 ( struct V_6 * V_7 , T_1 V_11 , int V_12 ,
T_1 * V_26 , unsigned * V_27 )
{
T_1 V_28 = F_5 ( V_7 , V_11 , V_12 ) ;
unsigned V_29 ;
* V_26 = V_7 -> V_30 [ V_12 ] + ( V_28 >> V_7 -> V_13 ) ;
if ( ! V_27 )
return;
V_29 = V_28 & ( ( 1 << V_7 -> V_13 ) - 1 ) ;
if ( ! V_7 -> V_20 )
* V_27 = V_29 * V_7 -> V_31 ;
else
* V_27 = V_29 << ( V_7 -> V_32 - V_7 -> V_13 ) ;
}
static int F_17 ( struct V_6 * V_7 , enum V_33 type ,
unsigned long long V_11 )
{
char V_34 [ V_35 ] ;
char * V_36 [] = { V_34 , NULL } ;
const char * V_37 = L_4 ;
struct V_38 * V_39 = F_18 ( V_7 -> V_10 -> V_40 ) ;
V_7 -> V_41 = 1 ;
if ( V_7 -> V_42 >= V_43 )
goto V_44;
V_7 -> V_42 ++ ;
switch ( type ) {
case V_45 :
V_37 = L_5 ;
break;
case V_46 :
V_37 = L_6 ;
break;
default:
F_19 () ;
}
F_9 ( L_7 , V_7 -> V_47 -> V_48 , V_37 ,
V_11 ) ;
if ( V_7 -> V_42 == V_43 )
F_9 ( L_8 , V_7 -> V_47 -> V_48 ) ;
snprintf ( V_34 , V_35 , L_9 ,
V_49 , type , V_11 ) ;
F_20 ( & F_21 ( F_22 ( V_39 ) ) -> V_50 , V_51 , V_36 ) ;
V_44:
if ( V_7 -> V_52 == V_53 )
return 0 ;
if ( V_7 -> V_52 == V_54 )
F_23 ( L_10 ) ;
return 1 ;
}
static int F_24 ( struct V_6 * V_7 , struct V_55 * V_56 ,
T_1 V_11 , int V_12 , bool V_57 ,
T_2 * V_58 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_2 * V_23 ;
int V_16 ;
T_1 V_26 ;
unsigned V_27 ;
F_16 ( V_7 , V_11 , V_12 , & V_26 , & V_27 ) ;
V_23 = F_25 ( V_7 -> V_59 , V_26 , & V_2 ) ;
if ( F_26 ( V_23 ) )
return F_27 ( V_23 ) ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 ) {
if ( V_57 ) {
V_16 = 1 ;
goto V_60;
}
V_16 = F_15 ( V_7 , F_28 ( V_7 , V_56 ) ,
V_23 , 1 << V_7 -> V_32 ,
F_29 ( V_7 , V_56 ) ) ;
if ( F_8 ( V_16 < 0 ) )
goto V_60;
if ( F_10 ( memcmp ( F_29 ( V_7 , V_56 ) , V_58 ,
V_7 -> V_31 ) == 0 ) )
V_4 -> V_5 = 1 ;
else if ( F_30 ( V_7 , V_56 ,
V_46 ,
V_26 , V_23 , NULL ) == 0 )
V_4 -> V_5 = 1 ;
else if ( F_17 ( V_7 ,
V_46 ,
V_26 ) ) {
V_16 = - V_61 ;
goto V_60;
}
}
V_23 += V_27 ;
memcpy ( V_58 , V_23 , V_7 -> V_31 ) ;
V_16 = 0 ;
V_60:
F_31 ( V_2 ) ;
return V_16 ;
}
int F_32 ( struct V_6 * V_7 , struct V_55 * V_56 ,
T_1 V_11 , T_2 * V_25 , bool * V_62 )
{
int V_16 = 0 , V_63 ;
if ( F_10 ( V_7 -> V_64 ) ) {
V_16 = F_24 ( V_7 , V_56 , V_11 , 0 , true , V_25 ) ;
if ( F_10 ( V_16 <= 0 ) )
goto V_44;
}
memcpy ( V_25 , V_7 -> V_65 , V_7 -> V_31 ) ;
for ( V_63 = V_7 -> V_64 - 1 ; V_63 >= 0 ; V_63 -- ) {
V_16 = F_24 ( V_7 , V_56 , V_11 , V_63 , false , V_25 ) ;
if ( F_8 ( V_16 ) )
goto V_44;
}
V_44:
if ( ! V_16 && V_7 -> V_66 )
* V_62 = ! memcmp ( V_7 -> V_66 , V_25 , V_7 -> V_31 ) ;
else
* V_62 = false ;
return V_16 ;
}
int F_33 ( struct V_6 * V_7 , struct V_55 * V_56 ,
struct V_67 * V_68 ,
int (* F_34)( struct V_6 * V_7 ,
struct V_55 * V_56 , T_2 * V_23 ,
T_3 V_24 ) )
{
unsigned V_69 = 1 << V_7 -> V_70 ;
struct V_71 * V_71 = F_35 ( V_56 , V_7 -> V_10 -> V_72 ) ;
do {
int V_16 ;
T_2 * V_73 ;
unsigned V_24 ;
struct V_74 V_75 = F_36 ( V_71 , * V_68 ) ;
V_73 = F_37 ( V_75 . V_76 ) ;
V_24 = V_75 . V_77 ;
if ( F_10 ( V_24 >= V_69 ) )
V_24 = V_69 ;
V_16 = F_34 ( V_7 , V_56 , V_73 + V_75 . V_78 , V_24 ) ;
F_38 ( V_73 ) ;
if ( V_16 < 0 )
return V_16 ;
F_39 ( V_71 , V_68 , V_24 ) ;
V_69 -= V_24 ;
} while ( V_69 );
return 0 ;
}
static int F_40 ( struct V_6 * V_7 , struct V_55 * V_56 ,
T_2 * V_23 , T_3 V_24 )
{
return F_12 ( V_7 , F_28 ( V_7 , V_56 ) , V_23 , V_24 ) ;
}
static int F_41 ( struct V_6 * V_7 , struct V_55 * V_56 ,
T_2 * V_23 , T_3 V_24 )
{
memset ( V_23 , 0 , V_24 ) ;
return 0 ;
}
static int F_42 ( struct V_55 * V_56 )
{
bool V_62 ;
struct V_6 * V_7 = V_56 -> V_7 ;
struct V_67 V_79 ;
unsigned V_80 ;
for ( V_80 = 0 ; V_80 < V_56 -> V_81 ; V_80 ++ ) {
int V_16 ;
struct V_14 * V_15 = F_28 ( V_7 , V_56 ) ;
V_16 = F_32 ( V_7 , V_56 , V_56 -> V_11 + V_80 ,
F_43 ( V_7 , V_56 ) ,
& V_62 ) ;
if ( F_8 ( V_16 < 0 ) )
return V_16 ;
if ( V_62 ) {
V_16 = F_33 ( V_7 , V_56 , & V_56 -> V_68 ,
F_41 ) ;
if ( F_8 ( V_16 < 0 ) )
return V_16 ;
continue;
}
V_16 = F_6 ( V_7 , V_15 ) ;
if ( F_8 ( V_16 < 0 ) )
return V_16 ;
V_79 = V_56 -> V_68 ;
V_16 = F_33 ( V_7 , V_56 , & V_56 -> V_68 , F_40 ) ;
if ( F_8 ( V_16 < 0 ) )
return V_16 ;
V_16 = F_13 ( V_7 , V_15 , F_29 ( V_7 , V_56 ) ) ;
if ( F_8 ( V_16 < 0 ) )
return V_16 ;
if ( F_10 ( memcmp ( F_29 ( V_7 , V_56 ) ,
F_43 ( V_7 , V_56 ) , V_7 -> V_31 ) == 0 ) )
continue;
else if ( F_30 ( V_7 , V_56 , V_45 ,
V_56 -> V_11 + V_80 , NULL , & V_79 ) == 0 )
continue;
else if ( F_17 ( V_7 , V_45 ,
V_56 -> V_11 + V_80 ) )
return - V_61 ;
}
return 0 ;
}
static void F_44 ( struct V_55 * V_56 , int error )
{
struct V_6 * V_7 = V_56 -> V_7 ;
struct V_71 * V_71 = F_35 ( V_56 , V_7 -> V_10 -> V_72 ) ;
V_71 -> V_82 = V_56 -> V_83 ;
V_71 -> V_84 = error ;
F_45 ( V_56 ) ;
F_46 ( V_71 ) ;
}
static void F_47 ( struct V_85 * V_86 )
{
struct V_55 * V_56 = F_48 ( V_86 , struct V_55 , V_87 ) ;
F_44 ( V_56 , F_42 ( V_56 ) ) ;
}
static void F_49 ( struct V_71 * V_71 )
{
struct V_55 * V_56 = V_71 -> V_88 ;
if ( V_71 -> V_84 && ! F_50 ( V_56 -> V_7 ) ) {
F_44 ( V_56 , V_71 -> V_84 ) ;
return;
}
F_51 ( & V_56 -> V_87 , F_47 ) ;
F_52 ( V_56 -> V_7 -> V_89 , & V_56 -> V_87 ) ;
}
static void F_53 ( struct V_85 * V_87 )
{
struct V_90 * V_91 =
F_48 ( V_87 , struct V_90 , V_87 ) ;
struct V_6 * V_7 = V_91 -> V_7 ;
int V_63 ;
for ( V_63 = V_7 -> V_64 - 2 ; V_63 >= 0 ; V_63 -- ) {
T_1 V_92 ;
T_1 V_93 ;
F_16 ( V_7 , V_91 -> V_11 , V_63 , & V_92 , NULL ) ;
F_16 ( V_7 , V_91 -> V_11 + V_91 -> V_81 - 1 , V_63 , & V_93 , NULL ) ;
if ( ! V_63 ) {
unsigned V_94 = F_54 ( V_95 ) ;
V_94 >>= V_7 -> V_70 ;
if ( F_8 ( ! V_94 ) )
goto V_96;
if ( F_8 ( V_94 & ( V_94 - 1 ) ) )
V_94 = 1 << F_55 ( V_94 ) ;
V_92 &= ~ ( T_1 ) ( V_94 - 1 ) ;
V_93 |= V_94 - 1 ;
if ( F_8 ( V_93 >= V_7 -> V_97 ) )
V_93 = V_7 -> V_97 - 1 ;
}
V_96:
F_56 ( V_7 -> V_59 , V_92 ,
V_93 - V_92 + 1 ) ;
}
F_57 ( V_91 ) ;
}
static void F_58 ( struct V_6 * V_7 , struct V_55 * V_56 )
{
struct V_90 * V_91 ;
V_91 = F_59 ( sizeof( struct V_90 ) ,
V_98 | V_99 | V_100 | V_101 ) ;
if ( ! V_91 )
return;
F_51 ( & V_91 -> V_87 , F_53 ) ;
V_91 -> V_7 = V_7 ;
V_91 -> V_11 = V_56 -> V_11 ;
V_91 -> V_81 = V_56 -> V_81 ;
F_52 ( V_7 -> V_89 , & V_91 -> V_87 ) ;
}
static int F_60 ( struct V_102 * V_10 , struct V_71 * V_71 )
{
struct V_6 * V_7 = V_10 -> V_103 ;
struct V_55 * V_56 ;
V_71 -> V_104 = V_7 -> V_47 -> V_105 ;
V_71 -> V_106 . V_8 = F_3 ( V_7 , V_71 -> V_106 . V_8 ) ;
if ( ( ( unsigned ) V_71 -> V_106 . V_8 | F_61 ( V_71 ) ) &
( ( 1 << ( V_7 -> V_70 - V_107 ) ) - 1 ) ) {
F_62 ( L_11 ) ;
return - V_61 ;
}
if ( F_63 ( V_71 ) >>
( V_7 -> V_70 - V_107 ) > V_7 -> V_108 ) {
F_62 ( L_12 ) ;
return - V_61 ;
}
if ( F_64 ( V_71 ) == V_109 )
return - V_61 ;
V_56 = F_65 ( V_71 , V_10 -> V_72 ) ;
V_56 -> V_7 = V_7 ;
V_56 -> V_83 = V_71 -> V_82 ;
V_56 -> V_11 = V_71 -> V_106 . V_8 >> ( V_7 -> V_70 - V_107 ) ;
V_56 -> V_81 = V_71 -> V_106 . V_110 >> V_7 -> V_70 ;
V_71 -> V_82 = F_49 ;
V_71 -> V_88 = V_56 ;
V_56 -> V_68 = V_71 -> V_106 ;
F_66 ( V_56 ) ;
F_58 ( V_7 , V_56 ) ;
F_67 ( V_71 ) ;
return V_111 ;
}
static void F_68 ( struct V_102 * V_10 , T_4 type ,
unsigned V_112 , char * V_113 , unsigned V_114 )
{
struct V_6 * V_7 = V_10 -> V_103 ;
unsigned args = 0 ;
unsigned V_115 = 0 ;
unsigned V_116 ;
switch ( type ) {
case V_117 :
F_69 ( L_13 , V_7 -> V_41 ? 'C' : 'V' ) ;
break;
case V_118 :
F_69 ( L_14 ,
V_7 -> V_20 ,
V_7 -> V_47 -> V_48 ,
V_7 -> V_119 -> V_48 ,
1 << V_7 -> V_70 ,
1 << V_7 -> V_32 ,
( unsigned long long ) V_7 -> V_108 ,
( unsigned long long ) V_7 -> V_120 ,
V_7 -> V_121
) ;
for ( V_116 = 0 ; V_116 < V_7 -> V_31 ; V_116 ++ )
F_69 ( L_15 , V_7 -> V_65 [ V_116 ] ) ;
F_69 ( L_16 ) ;
if ( ! V_7 -> V_22 )
F_69 ( L_17 ) ;
else
for ( V_116 = 0 ; V_116 < V_7 -> V_22 ; V_116 ++ )
F_69 ( L_15 , V_7 -> V_21 [ V_116 ] ) ;
if ( V_7 -> V_52 != V_122 )
args ++ ;
if ( F_50 ( V_7 ) )
args += V_123 ;
if ( V_7 -> V_66 )
args ++ ;
if ( ! args )
return;
F_69 ( L_18 , args ) ;
if ( V_7 -> V_52 != V_122 ) {
F_69 ( L_16 ) ;
switch ( V_7 -> V_52 ) {
case V_53 :
F_69 ( V_124 ) ;
break;
case V_54 :
F_69 ( V_125 ) ;
break;
default:
F_19 () ;
}
}
if ( V_7 -> V_66 )
F_69 ( L_16 V_126 ) ;
V_115 = F_70 ( V_7 , V_115 , V_113 , V_114 ) ;
break;
}
}
static int F_71 ( struct V_102 * V_10 ,
struct V_127 * * V_105 , T_5 * V_52 )
{
struct V_6 * V_7 = V_10 -> V_103 ;
* V_105 = V_7 -> V_47 -> V_105 ;
if ( V_7 -> V_9 ||
V_10 -> V_24 != F_72 ( V_7 -> V_47 -> V_105 -> V_128 ) >> V_107 )
return 1 ;
return 0 ;
}
static int F_73 ( struct V_102 * V_10 ,
T_6 V_129 , void * V_23 )
{
struct V_6 * V_7 = V_10 -> V_103 ;
return V_129 ( V_10 , V_7 -> V_47 , V_7 -> V_9 , V_10 -> V_24 , V_23 ) ;
}
static void F_74 ( struct V_102 * V_10 , struct V_130 * V_131 )
{
struct V_6 * V_7 = V_10 -> V_103 ;
if ( V_131 -> V_132 < 1 << V_7 -> V_70 )
V_131 -> V_132 = 1 << V_7 -> V_70 ;
if ( V_131 -> V_133 < 1 << V_7 -> V_70 )
V_131 -> V_133 = 1 << V_7 -> V_70 ;
F_75 ( V_131 , V_131 -> V_132 ) ;
}
static void F_76 ( struct V_102 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_103 ;
if ( V_7 -> V_89 )
F_77 ( V_7 -> V_89 ) ;
if ( V_7 -> V_59 )
F_78 ( V_7 -> V_59 ) ;
F_57 ( V_7 -> V_21 ) ;
F_57 ( V_7 -> V_65 ) ;
F_57 ( V_7 -> V_66 ) ;
if ( V_7 -> V_17 )
F_79 ( V_7 -> V_17 ) ;
F_57 ( V_7 -> V_121 ) ;
if ( V_7 -> V_119 )
F_80 ( V_10 , V_7 -> V_119 ) ;
if ( V_7 -> V_47 )
F_80 ( V_10 , V_7 -> V_47 ) ;
F_81 ( V_7 ) ;
F_57 ( V_7 ) ;
}
static int F_82 ( struct V_6 * V_7 )
{
int V_16 = - V_134 ;
struct V_14 * V_15 ;
T_2 * V_135 ;
V_7 -> V_66 = F_59 ( V_7 -> V_31 , V_136 ) ;
if ( ! V_7 -> V_66 )
return V_16 ;
V_15 = F_59 ( V_7 -> V_137 , V_136 ) ;
if ( ! V_15 )
return V_16 ;
V_135 = F_83 ( 1 << V_7 -> V_70 , V_136 ) ;
if ( ! V_135 )
goto V_44;
V_16 = F_15 ( V_7 , V_15 , V_135 , 1 << V_7 -> V_70 ,
V_7 -> V_66 ) ;
V_44:
F_57 ( V_15 ) ;
F_57 ( V_135 ) ;
return V_16 ;
}
static int F_84 ( struct V_138 * V_139 , struct V_6 * V_7 )
{
int V_16 ;
unsigned V_140 ;
struct V_102 * V_10 = V_7 -> V_10 ;
const char * V_141 ;
static struct V_142 V_143 [] = {
{ 0 , V_144 , L_19 } ,
} ;
V_16 = F_85 ( V_143 , V_139 , & V_140 , & V_10 -> error ) ;
if ( V_16 )
return - V_145 ;
if ( ! V_140 )
return 0 ;
do {
V_141 = F_86 ( V_139 ) ;
V_140 -- ;
if ( ! strcasecmp ( V_141 , V_124 ) ) {
V_7 -> V_52 = V_53 ;
continue;
} else if ( ! strcasecmp ( V_141 , V_125 ) ) {
V_7 -> V_52 = V_54 ;
continue;
} else if ( ! strcasecmp ( V_141 , V_126 ) ) {
V_16 = F_82 ( V_7 ) ;
if ( V_16 ) {
V_10 -> error = L_20 ;
return V_16 ;
}
continue;
} else if ( F_87 ( V_141 ) ) {
V_16 = F_88 ( V_139 , V_7 , & V_140 , V_141 ) ;
if ( V_16 )
return V_16 ;
continue;
}
V_10 -> error = L_21 ;
return - V_145 ;
} while ( V_140 && ! V_16 );
return V_16 ;
}
static int F_89 ( struct V_102 * V_10 , unsigned V_140 , char * * V_146 )
{
struct V_6 * V_7 ;
struct V_138 V_139 ;
unsigned int V_147 ;
unsigned long long V_148 ;
int V_16 ;
int V_63 ;
T_1 V_149 ;
char V_150 ;
V_7 = F_83 ( sizeof( struct V_6 ) , V_136 ) ;
if ( ! V_7 ) {
V_10 -> error = L_22 ;
return - V_134 ;
}
V_10 -> V_103 = V_7 ;
V_7 -> V_10 = V_10 ;
V_16 = F_90 ( V_7 ) ;
if ( V_16 )
goto V_151;
if ( ( F_91 ( V_10 -> V_40 ) & ~ V_152 ) ) {
V_10 -> error = L_23 ;
V_16 = - V_145 ;
goto V_151;
}
if ( V_140 < 10 ) {
V_10 -> error = L_24 ;
V_16 = - V_145 ;
goto V_151;
}
if ( sscanf ( V_146 [ 0 ] , L_25 , & V_147 , & V_150 ) != 1 ||
V_147 > 1 ) {
V_10 -> error = L_26 ;
V_16 = - V_145 ;
goto V_151;
}
V_7 -> V_20 = V_147 ;
V_16 = F_92 ( V_10 , V_146 [ 1 ] , V_152 , & V_7 -> V_47 ) ;
if ( V_16 ) {
V_10 -> error = L_27 ;
goto V_151;
}
V_16 = F_92 ( V_10 , V_146 [ 2 ] , V_152 , & V_7 -> V_119 ) ;
if ( V_16 ) {
V_10 -> error = L_27 ;
goto V_151;
}
if ( sscanf ( V_146 [ 3 ] , L_25 , & V_147 , & V_150 ) != 1 ||
! V_147 || ( V_147 & ( V_147 - 1 ) ) ||
V_147 < V_153 ( V_7 -> V_47 -> V_105 ) ||
V_147 > V_154 ) {
V_10 -> error = L_28 ;
V_16 = - V_145 ;
goto V_151;
}
V_7 -> V_70 = F_93 ( V_147 ) ;
if ( sscanf ( V_146 [ 4 ] , L_25 , & V_147 , & V_150 ) != 1 ||
! V_147 || ( V_147 & ( V_147 - 1 ) ) ||
V_147 < V_153 ( V_7 -> V_119 -> V_105 ) ||
V_147 > V_155 ) {
V_10 -> error = L_29 ;
V_16 = - V_145 ;
goto V_151;
}
V_7 -> V_32 = F_93 ( V_147 ) ;
if ( sscanf ( V_146 [ 5 ] , L_30 , & V_148 , & V_150 ) != 1 ||
( T_1 ) ( V_148 << ( V_7 -> V_70 - V_107 ) )
>> ( V_7 -> V_70 - V_107 ) != V_148 ) {
V_10 -> error = L_31 ;
V_16 = - V_145 ;
goto V_151;
}
V_7 -> V_108 = V_148 ;
if ( V_10 -> V_24 > ( V_7 -> V_108 << ( V_7 -> V_70 - V_107 ) ) ) {
V_10 -> error = L_32 ;
V_16 = - V_145 ;
goto V_151;
}
if ( sscanf ( V_146 [ 6 ] , L_30 , & V_148 , & V_150 ) != 1 ||
( T_1 ) ( V_148 << ( V_7 -> V_32 - V_107 ) )
>> ( V_7 -> V_32 - V_107 ) != V_148 ) {
V_10 -> error = L_33 ;
V_16 = - V_145 ;
goto V_151;
}
V_7 -> V_120 = V_148 ;
V_7 -> V_121 = F_94 ( V_146 [ 7 ] , V_136 ) ;
if ( ! V_7 -> V_121 ) {
V_10 -> error = L_34 ;
V_16 = - V_134 ;
goto V_151;
}
V_7 -> V_17 = F_95 ( V_7 -> V_121 , 0 , 0 ) ;
if ( F_26 ( V_7 -> V_17 ) ) {
V_10 -> error = L_35 ;
V_16 = F_27 ( V_7 -> V_17 ) ;
V_7 -> V_17 = NULL ;
goto V_151;
}
V_7 -> V_31 = F_96 ( V_7 -> V_17 ) ;
if ( ( 1 << V_7 -> V_32 ) < V_7 -> V_31 * 2 ) {
V_10 -> error = L_36 ;
V_16 = - V_145 ;
goto V_151;
}
V_7 -> V_137 =
sizeof( struct V_14 ) + F_97 ( V_7 -> V_17 ) ;
V_7 -> V_65 = F_59 ( V_7 -> V_31 , V_136 ) ;
if ( ! V_7 -> V_65 ) {
V_10 -> error = L_37 ;
V_16 = - V_134 ;
goto V_151;
}
if ( strlen ( V_146 [ 8 ] ) != V_7 -> V_31 * 2 ||
F_98 ( V_7 -> V_65 , V_146 [ 8 ] , V_7 -> V_31 ) ) {
V_10 -> error = L_38 ;
V_16 = - V_145 ;
goto V_151;
}
if ( strcmp ( V_146 [ 9 ] , L_17 ) ) {
V_7 -> V_22 = strlen ( V_146 [ 9 ] ) / 2 ;
V_7 -> V_21 = F_59 ( V_7 -> V_22 , V_136 ) ;
if ( ! V_7 -> V_21 ) {
V_10 -> error = L_39 ;
V_16 = - V_134 ;
goto V_151;
}
if ( strlen ( V_146 [ 9 ] ) != V_7 -> V_22 * 2 ||
F_98 ( V_7 -> V_21 , V_146 [ 9 ] , V_7 -> V_22 ) ) {
V_10 -> error = L_40 ;
V_16 = - V_145 ;
goto V_151;
}
}
V_146 += 10 ;
V_140 -= 10 ;
if ( V_140 ) {
V_139 . V_140 = V_140 ;
V_139 . V_146 = V_146 ;
V_16 = F_84 ( & V_139 , V_7 ) ;
if ( V_16 < 0 )
goto V_151;
}
V_7 -> V_13 =
F_55 ( ( 1 << V_7 -> V_32 ) / V_7 -> V_31 ) ;
V_7 -> V_64 = 0 ;
if ( V_7 -> V_108 )
while ( V_7 -> V_13 * V_7 -> V_64 < 64 &&
( unsigned long long ) ( V_7 -> V_108 - 1 ) >>
( V_7 -> V_13 * V_7 -> V_64 ) )
V_7 -> V_64 ++ ;
if ( V_7 -> V_64 > V_156 ) {
V_10 -> error = L_41 ;
V_16 = - V_157 ;
goto V_151;
}
V_149 = V_7 -> V_120 ;
for ( V_63 = V_7 -> V_64 - 1 ; V_63 >= 0 ; V_63 -- ) {
T_1 V_158 ;
V_7 -> V_30 [ V_63 ] = V_149 ;
V_158 = ( V_7 -> V_108 + ( ( T_1 ) 1 << ( ( V_63 + 1 ) * V_7 -> V_13 ) ) - 1 )
>> ( ( V_63 + 1 ) * V_7 -> V_13 ) ;
if ( V_149 + V_158 < V_149 ) {
V_10 -> error = L_42 ;
V_16 = - V_157 ;
goto V_151;
}
V_149 += V_158 ;
}
V_7 -> V_97 = V_149 ;
V_7 -> V_59 = F_99 ( V_7 -> V_119 -> V_105 ,
1 << V_7 -> V_32 , 1 , sizeof( struct V_3 ) ,
F_1 , NULL ) ;
if ( F_26 ( V_7 -> V_59 ) ) {
V_10 -> error = L_43 ;
V_16 = F_27 ( V_7 -> V_59 ) ;
V_7 -> V_59 = NULL ;
goto V_151;
}
if ( F_100 ( V_7 -> V_59 ) < V_7 -> V_97 ) {
V_10 -> error = L_44 ;
V_16 = - V_157 ;
goto V_151;
}
V_7 -> V_89 = F_101 ( L_45 , V_159 | V_160 | V_161 , F_102 () ) ;
if ( ! V_7 -> V_89 ) {
V_10 -> error = L_46 ;
V_16 = - V_134 ;
goto V_151;
}
V_10 -> V_72 = sizeof( struct V_55 ) +
V_7 -> V_137 + V_7 -> V_31 * 2 ;
V_16 = F_103 ( V_7 ) ;
if ( V_16 )
goto V_151;
V_10 -> V_72 = F_104 ( V_10 -> V_72 ,
F_105 ( struct V_55 ) ) ;
return 0 ;
V_151:
F_76 ( V_10 ) ;
return V_16 ;
}
static int T_7 F_106 ( void )
{
int V_16 ;
V_16 = F_107 ( & V_162 ) ;
if ( V_16 < 0 )
F_9 ( L_47 , V_16 ) ;
return V_16 ;
}
static void T_8 F_108 ( void )
{
F_109 ( & V_162 ) ;
}

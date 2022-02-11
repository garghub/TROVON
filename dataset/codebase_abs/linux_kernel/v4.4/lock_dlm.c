static inline void F_1 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 V_4 )
{
T_1 V_5 = V_4 - V_2 -> V_6 [ V_3 ] ;
V_2 -> V_6 [ V_3 ] += ( V_5 >> 3 ) ;
V_3 ++ ;
V_2 -> V_6 [ V_3 ] += ( ( abs ( V_5 ) - V_2 -> V_6 [ V_3 ] ) >> 2 ) ;
}
static inline void F_2 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
const unsigned V_11 = V_8 -> V_12 . V_13 ;
unsigned V_3 = F_3 ( V_14 , & V_8 -> V_15 ) ?
V_16 : V_17 ;
T_1 V_18 ;
F_4 () ;
V_18 = F_5 ( F_6 ( F_7 () , V_8 -> V_19 ) ) ;
V_10 = F_8 ( V_8 -> V_12 . V_20 -> V_21 ) ;
F_1 ( & V_8 -> V_22 , V_3 , V_18 ) ;
F_1 ( & V_10 -> V_23 [ V_11 ] , V_3 , V_18 ) ;
F_9 () ;
F_10 ( V_8 , V_18 ) ;
}
static inline void F_11 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
const unsigned V_11 = V_8 -> V_12 . V_13 ;
T_2 V_24 ;
T_1 V_25 ;
F_4 () ;
V_24 = V_8 -> V_19 ;
V_8 -> V_19 = F_7 () ;
V_25 = F_5 ( F_6 ( V_8 -> V_19 , V_24 ) ) ;
V_10 = F_8 ( V_8 -> V_12 . V_20 -> V_21 ) ;
F_1 ( & V_8 -> V_22 , V_26 , V_25 ) ;
F_1 ( & V_10 -> V_23 [ V_11 ] , V_26 , V_25 ) ;
F_9 () ;
}
static void F_12 ( void * V_27 )
{
struct V_7 * V_8 = V_27 ;
unsigned V_28 = V_8 -> V_29 ;
F_2 ( V_8 ) ;
F_13 ( V_8 -> V_30 . V_31 & V_32 ) ;
if ( ( V_8 -> V_30 . V_31 & V_33 ) && V_8 -> V_30 . V_34 )
memset ( V_8 -> V_30 . V_34 , 0 , V_35 ) ;
switch ( V_8 -> V_30 . V_36 ) {
case - V_37 :
F_14 ( V_8 ) ;
return;
case - V_38 :
V_28 |= V_39 ;
goto V_40;
case - V_41 :
case - V_42 :
goto V_40;
case - V_43 :
V_28 |= V_44 ;
goto V_40;
case 0 :
break;
default:
F_15 () ;
}
V_28 = V_8 -> V_45 ;
if ( V_8 -> V_30 . V_31 & V_46 ) {
if ( V_8 -> V_45 == V_47 )
V_28 = V_48 ;
else if ( V_8 -> V_45 == V_48 )
V_28 = V_47 ;
else
F_15 () ;
}
F_16 ( V_49 , & V_8 -> V_15 ) ;
F_17 ( V_8 , V_28 ) ;
return;
V_40:
if ( ! F_3 ( V_49 , & V_8 -> V_15 ) )
V_8 -> V_30 . V_50 = 0 ;
F_17 ( V_8 , V_28 ) ;
}
static void F_18 ( void * V_27 , int V_51 )
{
struct V_7 * V_8 = V_27 ;
switch ( V_51 ) {
case V_52 :
F_19 ( V_8 , V_53 ) ;
break;
case V_54 :
F_19 ( V_8 , V_48 ) ;
break;
case V_55 :
F_19 ( V_8 , V_47 ) ;
break;
default:
F_20 ( L_1 , V_51 ) ;
F_15 () ;
}
}
static int F_21 ( const unsigned int V_56 )
{
switch ( V_56 ) {
case V_53 :
return V_57 ;
case V_58 :
return V_52 ;
case V_48 :
return V_54 ;
case V_47 :
return V_55 ;
}
F_20 ( L_2 , V_56 ) ;
F_15 () ;
return - 1 ;
}
static T_3 F_22 ( struct V_7 * V_8 , const unsigned int V_59 ,
const int V_60 )
{
T_3 V_61 = 0 ;
if ( V_8 -> V_30 . V_34 )
V_61 |= V_62 ;
if ( V_59 & V_63 )
V_61 |= V_64 ;
if ( V_59 & V_65 ) {
V_61 |= V_64 ;
V_61 |= V_66 ;
}
if ( V_59 & V_67 ) {
V_61 |= V_68 ;
V_61 |= V_69 ;
}
if ( V_59 & V_70 ) {
if ( V_60 == V_55 )
V_61 |= V_71 ;
else if ( V_60 == V_54 )
V_61 |= V_72 ;
else
F_15 () ;
}
if ( V_8 -> V_30 . V_50 != 0 ) {
V_61 |= V_73 ;
if ( F_3 ( V_14 , & V_8 -> V_15 ) )
V_61 |= V_74 ;
}
return V_61 ;
}
static void F_23 ( char * V_75 , T_4 V_76 )
{
* V_75 = '0' ;
while ( V_76 ) {
* V_75 -- = V_77 [ V_76 & 0x0f ] ;
V_76 >>= 4 ;
}
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_78 ,
unsigned int V_79 )
{
struct V_80 * V_81 = & V_8 -> V_12 . V_20 -> V_82 ;
int V_60 ;
T_3 V_61 ;
char V_83 [ V_84 ] = L_3 ;
V_60 = F_21 ( V_78 ) ;
V_61 = F_22 ( V_8 , V_79 , V_60 ) ;
F_25 ( V_8 , V_85 ) ;
F_26 ( V_8 , V_85 ) ;
if ( V_8 -> V_30 . V_50 ) {
F_11 ( V_8 ) ;
} else {
memset ( V_83 , ' ' , V_84 - 1 ) ;
V_83 [ V_84 - 1 ] = '\0' ;
F_23 ( V_83 + 7 , V_8 -> V_12 . V_13 ) ;
F_23 ( V_83 + 23 , V_8 -> V_12 . V_86 ) ;
V_8 -> V_19 = F_7 () ;
}
return F_27 ( V_81 -> V_87 , V_60 , & V_8 -> V_30 , V_61 , V_83 ,
V_84 - 1 , 0 , F_12 , V_8 , F_18 ) ;
}
static void F_28 ( struct V_7 * V_8 )
{
struct V_88 * V_89 = V_8 -> V_12 . V_20 ;
struct V_80 * V_81 = & V_89 -> V_82 ;
int V_90 = 0 ;
int error ;
if ( V_8 -> V_30 . V_50 == 0 ) {
F_14 ( V_8 ) ;
return;
}
F_29 ( V_14 , & V_8 -> V_15 ) ;
F_25 ( V_8 , V_85 ) ;
F_26 ( V_8 , V_85 ) ;
F_11 ( V_8 ) ;
if ( V_8 -> V_30 . V_34 && ( V_8 -> V_29 == V_58 ) )
V_90 = 1 ;
if ( F_3 ( V_91 , & V_89 -> V_92 ) &&
! V_90 ) {
F_14 ( V_8 ) ;
return;
}
error = F_30 ( V_81 -> V_87 , V_8 -> V_30 . V_50 , V_62 ,
NULL , V_8 ) ;
if ( error ) {
F_20 ( L_4 ,
V_8 -> V_12 . V_13 ,
( unsigned long long ) V_8 -> V_12 . V_86 , error ) ;
return;
}
}
static void F_31 ( struct V_7 * V_8 )
{
struct V_80 * V_81 = & V_8 -> V_12 . V_20 -> V_82 ;
F_30 ( V_81 -> V_87 , V_8 -> V_30 . V_50 , V_93 , NULL , V_8 ) ;
}
static void F_32 ( struct V_80 * V_81 , T_5 * V_94 ,
char * V_95 )
{
T_6 V_96 ;
memcpy ( V_95 , V_81 -> V_97 , V_35 ) ;
memcpy ( & V_96 , V_95 , sizeof( T_6 ) ) ;
* V_94 = F_33 ( V_96 ) ;
}
static void F_34 ( struct V_80 * V_81 , T_5 V_94 ,
char * V_95 )
{
T_6 V_96 ;
memcpy ( V_81 -> V_97 , V_95 , V_35 ) ;
V_96 = F_35 ( V_94 ) ;
memcpy ( V_81 -> V_97 , & V_96 , sizeof( T_6 ) ) ;
}
static int F_36 ( char * V_98 )
{
return ! F_37 ( V_98 + V_99 , 0 ,
V_35 - V_99 ) ;
}
static void F_38 ( void * V_27 )
{
struct V_80 * V_81 = V_27 ;
F_39 ( & V_81 -> V_100 ) ;
}
static int F_40 ( struct V_88 * V_89 , struct V_101 * V_102 , char * V_103 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
int error ;
error = F_30 ( V_81 -> V_87 , V_102 -> V_50 , 0 , V_102 , V_81 ) ;
if ( error ) {
F_41 ( V_89 , L_5 ,
V_103 , V_102 -> V_50 , error ) ;
return error ;
}
F_42 ( & V_81 -> V_100 ) ;
if ( V_102 -> V_36 != - V_37 ) {
F_41 ( V_89 , L_6 ,
V_103 , V_102 -> V_50 , V_102 -> V_36 ) ;
return - 1 ;
}
return 0 ;
}
static int F_43 ( struct V_88 * V_89 , int V_51 , T_5 V_79 ,
unsigned int V_104 , struct V_101 * V_102 , char * V_103 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
char V_83 [ V_84 ] ;
int error , V_105 ;
memset ( V_83 , 0 , V_84 ) ;
snprintf ( V_83 , V_84 , L_7 , V_106 , V_104 ) ;
error = F_27 ( V_81 -> V_87 , V_51 , V_102 , V_79 ,
V_83 , V_84 - 1 ,
0 , F_38 , V_81 , NULL ) ;
if ( error ) {
F_41 ( V_89 , L_8 ,
V_103 , V_102 -> V_50 , V_79 , V_51 , error ) ;
return error ;
}
F_42 ( & V_81 -> V_100 ) ;
V_105 = V_102 -> V_36 ;
if ( V_105 && V_105 != - V_41 ) {
F_41 ( V_89 , L_9 ,
V_103 , V_102 -> V_50 , V_79 , V_51 , V_105 ) ;
}
return V_105 ;
}
static int F_44 ( struct V_88 * V_89 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
return F_40 ( V_89 , & V_81 -> V_107 , L_10 ) ;
}
static int F_45 ( struct V_88 * V_89 , int V_51 , T_5 V_79 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
return F_43 ( V_89 , V_51 , V_79 , V_108 ,
& V_81 -> V_107 , L_10 ) ;
}
static int F_46 ( struct V_88 * V_89 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
return F_40 ( V_89 , & V_81 -> V_109 , L_11 ) ;
}
static int F_47 ( struct V_88 * V_89 , int V_51 , T_5 V_79 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
return F_43 ( V_89 , V_51 , V_79 , V_110 ,
& V_81 -> V_109 , L_11 ) ;
}
static void F_48 ( struct V_111 * V_112 )
{
struct V_88 * V_89 = F_49 ( V_112 , struct V_88 , V_113 . V_112 ) ;
struct V_80 * V_81 = & V_89 -> V_82 ;
T_5 V_114 , V_115 , V_94 , V_79 ;
int V_116 = 0 ;
int V_117 = 0 ;
int V_118 ;
int V_119 , error ;
F_50 ( & V_81 -> V_120 ) ;
if ( ! F_3 ( V_121 , & V_81 -> V_122 ) ||
F_3 ( V_123 , & V_81 -> V_122 ) ) {
F_51 ( & V_81 -> V_120 ) ;
return;
}
V_114 = V_81 -> V_124 ;
V_115 = V_81 -> V_125 ;
F_51 ( & V_81 -> V_120 ) ;
if ( V_114 == V_115 )
return;
error = F_47 ( V_89 , V_52 , V_73 | V_62 ) ;
if ( error ) {
F_41 ( V_89 , L_12 , error ) ;
return;
}
F_32 ( V_81 , & V_94 , V_81 -> V_126 ) ;
F_50 ( & V_81 -> V_120 ) ;
if ( V_114 != V_81 -> V_124 ||
V_115 != V_81 -> V_125 ) {
F_52 ( V_89 , L_13 ,
V_115 , V_114 , V_81 -> V_124 ) ;
F_51 ( & V_81 -> V_120 ) ;
F_47 ( V_89 , V_57 , V_73 ) ;
return;
}
V_118 = V_81 -> V_127 ;
if ( V_94 <= V_115 ) {
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
if ( V_81 -> V_128 [ V_119 ] != V_129 )
continue;
V_81 -> V_128 [ V_119 ] = 0 ;
if ( ! F_53 ( V_119 , V_81 -> V_126 + V_99 ) )
continue;
F_54 ( V_119 , V_81 -> V_126 + V_99 ) ;
V_117 = 1 ;
}
}
if ( V_94 == V_115 ) {
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
if ( ! V_81 -> V_130 [ V_119 ] )
continue;
if ( V_81 -> V_130 [ V_119 ] < V_94 )
V_81 -> V_130 [ V_119 ] = 0 ;
}
} else if ( V_94 < V_115 ) {
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
if ( ! V_81 -> V_130 [ V_119 ] )
continue;
if ( V_81 -> V_130 [ V_119 ] < V_115 ) {
V_81 -> V_130 [ V_119 ] = 0 ;
F_55 ( V_119 , V_81 -> V_126 + V_99 ) ;
}
}
V_117 = 1 ;
} else {
}
F_51 ( & V_81 -> V_120 ) ;
if ( V_117 ) {
F_34 ( V_81 , V_115 , V_81 -> V_126 ) ;
V_79 = V_73 | V_62 ;
} else {
V_79 = V_73 ;
}
error = F_47 ( V_89 , V_57 , V_79 ) ;
if ( error ) {
F_41 ( V_89 , L_14 , error ) ;
return;
}
for ( V_119 = 0 ; V_119 < V_118 ; V_119 ++ ) {
if ( F_53 ( V_119 , V_81 -> V_126 + V_99 ) ) {
F_52 ( V_89 , L_15 ,
V_115 , V_119 ) ;
F_56 ( V_89 , V_119 ) ;
V_116 ++ ;
}
}
if ( V_116 )
return;
F_50 ( & V_81 -> V_120 ) ;
if ( V_81 -> V_124 == V_114 &&
V_81 -> V_125 == V_115 ) {
F_29 ( V_131 , & V_81 -> V_122 ) ;
F_51 ( & V_81 -> V_120 ) ;
F_52 ( V_89 , L_16 , V_115 ) ;
F_57 ( V_89 ) ;
} else {
F_52 ( V_89 , L_17 ,
V_115 , V_114 , V_81 -> V_124 ) ;
F_51 ( & V_81 -> V_120 ) ;
}
}
static int F_58 ( struct V_88 * V_89 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
T_5 V_115 , V_114 , V_132 , V_94 ;
int V_133 ;
int V_134 = 0 ;
int error ;
memset ( & V_81 -> V_107 , 0 , sizeof( struct V_101 ) ) ;
memset ( & V_81 -> V_109 , 0 , sizeof( struct V_101 ) ) ;
memset ( & V_81 -> V_97 , 0 , V_35 ) ;
V_81 -> V_109 . V_34 = V_81 -> V_97 ;
F_59 ( & V_81 -> V_100 ) ;
F_16 ( V_131 , & V_81 -> V_122 ) ;
error = F_47 ( V_89 , V_57 , V_62 ) ;
if ( error ) {
F_41 ( V_89 , L_18 , error ) ;
return error ;
}
error = F_45 ( V_89 , V_57 , 0 ) ;
if ( error ) {
F_41 ( V_89 , L_19 , error ) ;
F_46 ( V_89 ) ;
return error ;
}
V_133 = V_57 ;
V_135:
if ( V_134 ++ && F_60 ( V_136 ) ) {
error = - V_137 ;
goto V_138;
}
if ( V_133 != V_57 ) {
error = F_45 ( V_89 , V_57 , V_73 ) ;
if ( error )
goto V_138;
V_133 = V_57 ;
}
F_61 ( 500 ) ;
error = F_47 ( V_89 , V_52 , V_73 | V_64 | V_62 ) ;
if ( error == - V_41 ) {
goto V_135;
} else if ( error ) {
F_41 ( V_89 , L_20 , error ) ;
goto V_138;
}
error = F_45 ( V_89 , V_52 , V_73 | V_64 ) ;
if ( ! error ) {
V_133 = V_52 ;
goto V_139;
} else if ( error != - V_41 ) {
F_41 ( V_89 , L_21 , error ) ;
goto V_138;
}
error = F_45 ( V_89 , V_55 , V_73 | V_64 ) ;
if ( ! error ) {
V_133 = V_55 ;
goto V_139;
} else {
F_41 ( V_89 , L_22 , error ) ;
goto V_138;
}
V_139:
F_32 ( V_81 , & V_94 , V_81 -> V_126 ) ;
if ( V_94 == 0xFFFFFFFF ) {
F_41 ( V_89 , L_23 ) ;
error = - V_140 ;
goto V_138;
}
if ( V_133 == V_52 ) {
F_50 ( & V_81 -> V_120 ) ;
F_29 ( V_131 , & V_81 -> V_122 ) ;
F_16 ( V_121 , & V_81 -> V_122 ) ;
F_16 ( V_123 , & V_81 -> V_122 ) ;
F_51 ( & V_81 -> V_120 ) ;
F_52 ( V_89 , L_24 , V_94 ) ;
return 0 ;
}
error = F_47 ( V_89 , V_57 , V_73 ) ;
if ( error )
goto V_138;
if ( ! F_36 ( V_81 -> V_126 ) ) {
F_52 ( V_89 , L_25 ) ;
goto V_135;
}
F_50 ( & V_81 -> V_120 ) ;
V_114 = V_81 -> V_124 ;
V_115 = V_81 -> V_125 ;
V_132 = V_81 -> V_141 ;
if ( V_94 < V_132 ) {
F_52 ( V_89 , L_26
L_27 , V_114 , V_115 , V_132 ,
V_94 , V_81 -> V_122 ) ;
F_51 ( & V_81 -> V_120 ) ;
goto V_135;
}
if ( V_94 != V_115 ) {
F_52 ( V_89 , L_28
L_27 , V_114 , V_115 , V_132 ,
V_94 , V_81 -> V_122 ) ;
F_51 ( & V_81 -> V_120 ) ;
goto V_135;
}
if ( V_114 == V_115 ) {
F_52 ( V_89 , L_29
L_27 , V_114 , V_115 , V_132 ,
V_94 , V_81 -> V_122 ) ;
F_51 ( & V_81 -> V_120 ) ;
goto V_135;
}
F_29 ( V_131 , & V_81 -> V_122 ) ;
F_16 ( V_121 , & V_81 -> V_122 ) ;
memset ( V_81 -> V_130 , 0 , V_81 -> V_127 * sizeof( T_5 ) ) ;
memset ( V_81 -> V_128 , 0 , V_81 -> V_127 * sizeof( T_5 ) ) ;
F_51 ( & V_81 -> V_120 ) ;
return 0 ;
V_138:
F_44 ( V_89 ) ;
F_46 ( V_89 ) ;
return error ;
}
static int F_62 ( struct V_88 * V_89 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
T_5 V_115 , V_114 ;
int error ;
V_135:
F_50 ( & V_81 -> V_120 ) ;
V_115 = V_81 -> V_125 ;
V_114 = V_81 -> V_124 ;
if ( F_3 ( V_131 , & V_81 -> V_122 ) ||
! F_3 ( V_121 , & V_81 -> V_122 ) ||
! F_3 ( V_123 , & V_81 -> V_122 ) ) {
F_41 ( V_89 , L_30 ,
V_115 , V_114 , V_81 -> V_122 ) ;
F_51 ( & V_81 -> V_120 ) ;
F_46 ( V_89 ) ;
return - 1 ;
}
if ( V_115 == V_114 ) {
F_51 ( & V_81 -> V_120 ) ;
F_52 ( V_89 , L_31 , V_115 ) ;
F_63 ( & V_81 -> V_122 , V_142 ,
V_143 ) ;
goto V_135;
}
F_29 ( V_123 , & V_81 -> V_122 ) ;
F_16 ( V_144 , & V_81 -> V_122 ) ;
memset ( V_81 -> V_130 , 0 , V_81 -> V_127 * sizeof( T_5 ) ) ;
memset ( V_81 -> V_128 , 0 , V_81 -> V_127 * sizeof( T_5 ) ) ;
F_51 ( & V_81 -> V_120 ) ;
memset ( V_81 -> V_126 , 0 , V_35 ) ;
F_34 ( V_81 , V_115 , V_81 -> V_126 ) ;
error = F_45 ( V_89 , V_55 , V_73 ) ;
if ( error )
F_41 ( V_89 , L_32 , error ) ;
error = F_47 ( V_89 , V_57 , V_73 | V_62 ) ;
if ( error )
F_41 ( V_89 , L_33 , error ) ;
return error ;
}
static int F_64 ( struct V_88 * V_89 , struct V_145 * V_146 ,
int V_147 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
T_5 * V_148 = NULL ;
T_5 * V_149 = NULL ;
T_5 V_150 , V_151 ;
int V_119 , V_152 ;
if ( ! V_81 -> V_126 ) {
V_81 -> V_126 = F_65 ( V_35 , V_153 ) ;
if ( ! V_81 -> V_126 )
return - V_154 ;
}
V_152 = 0 ;
for ( V_119 = 0 ; V_119 < V_147 ; V_119 ++ ) {
if ( V_152 < V_146 [ V_119 ] . V_155 - 1 )
V_152 = V_146 [ V_119 ] . V_155 - 1 ;
}
V_150 = V_81 -> V_127 ;
if ( V_150 >= V_152 + 1 )
return 0 ;
V_151 = V_150 + V_156 ;
V_148 = F_66 ( V_151 , sizeof( T_5 ) , V_153 ) ;
V_149 = F_66 ( V_151 , sizeof( T_5 ) , V_153 ) ;
if ( ! V_148 || ! V_149 ) {
F_67 ( V_148 ) ;
F_67 ( V_149 ) ;
return - V_154 ;
}
F_50 ( & V_81 -> V_120 ) ;
memcpy ( V_148 , V_81 -> V_130 , V_150 * sizeof( T_5 ) ) ;
memcpy ( V_149 , V_81 -> V_128 , V_150 * sizeof( T_5 ) ) ;
F_67 ( V_81 -> V_130 ) ;
F_67 ( V_81 -> V_128 ) ;
V_81 -> V_130 = V_148 ;
V_81 -> V_128 = V_149 ;
V_81 -> V_127 = V_151 ;
F_51 ( & V_81 -> V_120 ) ;
return 0 ;
}
static void F_68 ( struct V_80 * V_81 )
{
F_67 ( V_81 -> V_126 ) ;
F_67 ( V_81 -> V_130 ) ;
F_67 ( V_81 -> V_128 ) ;
V_81 -> V_130 = NULL ;
V_81 -> V_128 = NULL ;
V_81 -> V_127 = 0 ;
}
static void F_69 ( void * V_27 )
{
struct V_88 * V_89 = V_27 ;
struct V_80 * V_81 = & V_89 -> V_82 ;
F_50 ( & V_81 -> V_120 ) ;
V_81 -> V_124 = V_81 -> V_125 ;
F_16 ( V_142 , & V_81 -> V_122 ) ;
if ( ! F_3 ( V_121 , & V_81 -> V_122 ) ||
F_3 ( V_123 , & V_81 -> V_122 ) ) {
F_51 ( & V_81 -> V_120 ) ;
return;
}
F_16 ( V_131 , & V_81 -> V_122 ) ;
F_51 ( & V_81 -> V_120 ) ;
}
static void F_70 ( void * V_27 , struct V_145 * V_155 )
{
struct V_88 * V_89 = V_27 ;
struct V_80 * V_81 = & V_89 -> V_82 ;
int V_157 = V_155 -> V_155 - 1 ;
F_50 ( & V_81 -> V_120 ) ;
if ( V_81 -> V_127 < V_157 + 1 ) {
F_41 ( V_89 , L_34 ,
V_157 , V_81 -> V_124 , V_81 -> V_127 ) ;
F_51 ( & V_81 -> V_120 ) ;
return;
}
if ( V_81 -> V_130 [ V_157 ] ) {
F_52 ( V_89 , L_35 ,
V_157 , V_81 -> V_124 , V_81 -> V_130 [ V_157 ] ) ;
}
V_81 -> V_130 [ V_157 ] = V_81 -> V_124 ;
F_51 ( & V_81 -> V_120 ) ;
}
static void F_71 ( void * V_27 , struct V_145 * V_146 , int V_147 ,
int V_158 , T_5 V_159 )
{
struct V_88 * V_89 = V_27 ;
struct V_80 * V_81 = & V_89 -> V_82 ;
F_64 ( V_89 , V_146 , V_147 ) ;
F_50 ( & V_81 -> V_120 ) ;
V_81 -> V_125 = V_159 ;
if ( ! V_81 -> V_141 ) {
V_81 -> V_141 = V_159 ;
V_81 -> V_160 = V_158 - 1 ;
}
if ( ! F_3 ( V_161 , & V_81 -> V_122 ) )
F_72 ( V_162 , & V_89 -> V_113 , 0 ) ;
F_29 ( V_142 , & V_81 -> V_122 ) ;
F_73 () ;
F_74 ( & V_81 -> V_122 , V_142 ) ;
F_51 ( & V_81 -> V_120 ) ;
}
static void F_75 ( struct V_88 * V_89 , unsigned int V_157 ,
unsigned int V_149 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
if ( F_3 ( V_163 , & V_81 -> V_122 ) )
return;
if ( V_157 == V_81 -> V_160 )
return;
F_50 ( & V_81 -> V_120 ) ;
if ( F_3 ( V_123 , & V_81 -> V_122 ) ) {
F_51 ( & V_81 -> V_120 ) ;
return;
}
if ( V_81 -> V_127 < V_157 + 1 ) {
F_41 ( V_89 , L_36 ,
V_157 , V_81 -> V_127 ) ;
F_51 ( & V_81 -> V_120 ) ;
return;
}
F_52 ( V_89 , L_37 , V_157 ,
V_149 == V_164 ? L_38 : L_39 ) ;
V_81 -> V_128 [ V_157 ] = V_149 ;
if ( ! F_3 ( V_161 , & V_81 -> V_122 ) )
F_72 ( V_162 , & V_89 -> V_113 ,
V_149 == V_164 ? V_165 : 0 ) ;
F_51 ( & V_81 -> V_120 ) ;
}
static int F_76 ( struct V_88 * V_89 , const char * V_166 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
char V_167 [ V_168 ] ;
const char * V_169 ;
T_5 V_79 ;
int error , V_170 ;
F_77 ( & V_89 -> V_113 , F_48 ) ;
F_78 ( & V_81 -> V_120 ) ;
V_81 -> V_122 = 0 ;
V_81 -> V_141 = 0 ;
V_81 -> V_125 = 0 ;
V_81 -> V_124 = 0 ;
V_81 -> V_127 = 0 ;
V_81 -> V_130 = NULL ;
V_81 -> V_128 = NULL ;
V_81 -> V_126 = NULL ;
error = F_64 ( V_89 , NULL , 0 ) ;
if ( error )
goto V_138;
V_169 = strchr ( V_166 , ':' ) ;
if ( ! V_169 ) {
F_52 ( V_89 , L_40 ) ;
error = - V_140 ;
goto V_171;
}
memset ( V_167 , 0 , sizeof( V_167 ) ) ;
memcpy ( V_167 , V_166 , strlen ( V_166 ) - strlen ( V_169 ) ) ;
V_169 ++ ;
V_79 = V_172 | V_173 ;
error = F_79 ( V_169 , V_167 , V_79 , V_35 ,
& V_174 , V_89 , & V_170 ,
& V_81 -> V_87 ) ;
if ( error ) {
F_41 ( V_89 , L_41 , error ) ;
goto V_171;
}
if ( V_170 < 0 ) {
F_52 ( V_89 , L_42 ) ;
F_68 ( V_81 ) ;
F_16 ( V_163 , & V_81 -> V_122 ) ;
return 0 ;
}
if ( ! F_3 ( V_175 , & V_89 -> V_92 ) ) {
F_41 ( V_89 , L_43 ) ;
error = - V_140 ;
goto V_176;
}
error = F_58 ( V_89 ) ;
if ( error ) {
F_41 ( V_89 , L_44 , error ) ;
goto V_176;
}
V_81 -> V_177 = ! ! F_3 ( V_123 , & V_81 -> V_122 ) ;
F_29 ( V_175 , & V_89 -> V_92 ) ;
F_73 () ;
F_74 ( & V_89 -> V_92 , V_175 ) ;
return 0 ;
V_176:
F_80 ( V_81 -> V_87 , 2 ) ;
V_171:
F_68 ( V_81 ) ;
V_138:
return error ;
}
static void F_81 ( struct V_88 * V_89 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
int error ;
if ( F_3 ( V_163 , & V_81 -> V_122 ) )
return;
error = F_62 ( V_89 ) ;
if ( error )
F_41 ( V_89 , L_45 , error ) ;
}
static void F_82 ( struct V_88 * V_89 )
{
struct V_80 * V_81 = & V_89 -> V_82 ;
if ( F_3 ( V_163 , & V_81 -> V_122 ) )
goto V_178;
F_50 ( & V_81 -> V_120 ) ;
F_16 ( V_161 , & V_81 -> V_122 ) ;
F_51 ( & V_81 -> V_120 ) ;
F_83 ( & V_89 -> V_113 ) ;
V_178:
if ( V_81 -> V_87 ) {
F_80 ( V_81 -> V_87 , 2 ) ;
V_81 -> V_87 = NULL ;
}
F_68 ( V_81 ) ;
}

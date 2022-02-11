static inline void F_1 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 V_4 )
{
T_1 V_5 = V_4 - V_2 -> V_6 [ V_3 ] ;
V_2 -> V_6 [ V_3 ] += ( V_5 >> 3 ) ;
V_3 ++ ;
V_2 -> V_6 [ V_3 ] += ( ( F_2 ( V_5 ) - V_2 -> V_6 [ V_3 ] ) >> 2 ) ;
}
static inline void F_3 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
const unsigned V_11 = V_8 -> V_12 . V_13 ;
unsigned V_3 = F_4 ( V_14 , & V_8 -> V_15 ) ?
V_16 : V_17 ;
T_1 V_18 ;
F_5 () ;
V_18 = F_6 ( F_7 ( F_8 () , V_8 -> V_19 ) ) ;
V_10 = F_9 ( V_8 -> V_20 -> V_21 ) ;
F_1 ( & V_8 -> V_22 , V_3 , V_18 ) ;
F_1 ( & V_10 -> V_23 [ V_11 ] , V_3 , V_18 ) ;
F_10 () ;
F_11 ( V_8 , V_18 ) ;
}
static inline void F_12 ( struct V_7 * V_8 )
{
struct V_9 * V_10 ;
const unsigned V_11 = V_8 -> V_12 . V_13 ;
T_2 V_24 ;
T_1 V_25 ;
F_5 () ;
V_24 = V_8 -> V_19 ;
V_8 -> V_19 = F_8 () ;
V_25 = F_6 ( F_7 ( V_8 -> V_19 , V_24 ) ) ;
V_10 = F_9 ( V_8 -> V_20 -> V_21 ) ;
F_1 ( & V_8 -> V_22 , V_26 , V_25 ) ;
F_1 ( & V_10 -> V_23 [ V_11 ] , V_26 , V_25 ) ;
F_10 () ;
}
static void F_13 ( void * V_27 )
{
struct V_7 * V_8 = V_27 ;
unsigned V_28 = V_8 -> V_29 ;
F_3 ( V_8 ) ;
F_14 ( V_8 -> V_30 . V_31 & V_32 ) ;
if ( ( V_8 -> V_30 . V_31 & V_33 ) && V_8 -> V_30 . V_34 )
memset ( V_8 -> V_30 . V_34 , 0 , V_35 ) ;
switch ( V_8 -> V_30 . V_36 ) {
case - V_37 :
F_15 ( V_8 ) ;
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
F_16 () ;
}
V_28 = V_8 -> V_45 ;
if ( V_8 -> V_30 . V_31 & V_46 ) {
if ( V_8 -> V_45 == V_47 )
V_28 = V_48 ;
else if ( V_8 -> V_45 == V_48 )
V_28 = V_47 ;
else
F_16 () ;
}
F_17 ( V_49 , & V_8 -> V_15 ) ;
F_18 ( V_8 , V_28 ) ;
return;
V_40:
if ( ! F_4 ( V_49 , & V_8 -> V_15 ) )
V_8 -> V_30 . V_50 = 0 ;
F_18 ( V_8 , V_28 ) ;
}
static void F_19 ( void * V_27 , int V_51 )
{
struct V_7 * V_8 = V_27 ;
switch ( V_51 ) {
case V_52 :
F_20 ( V_8 , V_53 ) ;
break;
case V_54 :
F_20 ( V_8 , V_48 ) ;
break;
case V_55 :
F_20 ( V_8 , V_47 ) ;
break;
default:
F_21 ( V_56 L_1 , V_51 ) ;
F_16 () ;
}
}
static int F_22 ( const unsigned int V_57 )
{
switch ( V_57 ) {
case V_53 :
return V_58 ;
case V_59 :
return V_52 ;
case V_48 :
return V_54 ;
case V_47 :
return V_55 ;
}
F_21 ( V_56 L_2 , V_57 ) ;
F_16 () ;
return - 1 ;
}
static T_3 F_23 ( struct V_7 * V_8 , const unsigned int V_60 ,
const int V_61 )
{
T_3 V_62 = 0 ;
if ( V_8 -> V_30 . V_34 )
V_62 |= V_63 ;
if ( V_60 & V_64 )
V_62 |= V_65 ;
if ( V_60 & V_66 ) {
V_62 |= V_65 ;
V_62 |= V_67 ;
}
if ( V_60 & V_68 ) {
V_62 |= V_69 ;
V_62 |= V_70 ;
}
if ( V_60 & V_71 ) {
if ( V_61 == V_55 )
V_62 |= V_72 ;
else if ( V_61 == V_54 )
V_62 |= V_73 ;
else
F_16 () ;
}
if ( V_8 -> V_30 . V_50 != 0 ) {
V_62 |= V_74 ;
if ( F_4 ( V_14 , & V_8 -> V_15 ) )
V_62 |= V_75 ;
}
return V_62 ;
}
static void F_24 ( char * V_76 , T_4 V_77 )
{
* V_76 = '0' ;
while ( V_77 ) {
* V_76 -- = V_78 [ V_77 & 0x0f ] ;
V_77 >>= 4 ;
}
}
static int F_25 ( struct V_7 * V_8 , unsigned int V_79 ,
unsigned int V_80 )
{
struct V_81 * V_82 = & V_8 -> V_20 -> V_83 ;
int V_61 ;
T_3 V_62 ;
char V_84 [ V_85 ] = L_3 ;
V_61 = F_22 ( V_79 ) ;
V_62 = F_23 ( V_8 , V_80 , V_61 ) ;
F_26 ( V_8 , V_86 ) ;
F_27 ( V_8 , V_86 ) ;
if ( V_8 -> V_30 . V_50 ) {
F_12 ( V_8 ) ;
} else {
memset ( V_84 , ' ' , V_85 - 1 ) ;
V_84 [ V_85 - 1 ] = '\0' ;
F_24 ( V_84 + 7 , V_8 -> V_12 . V_13 ) ;
F_24 ( V_84 + 23 , V_8 -> V_12 . V_87 ) ;
V_8 -> V_19 = F_8 () ;
}
return F_28 ( V_82 -> V_88 , V_61 , & V_8 -> V_30 , V_62 , V_84 ,
V_85 - 1 , 0 , F_13 , V_8 , F_19 ) ;
}
static void F_29 ( struct V_7 * V_8 )
{
struct V_89 * V_90 = V_8 -> V_20 ;
struct V_81 * V_82 = & V_90 -> V_83 ;
int V_91 = 0 ;
int error ;
if ( V_8 -> V_30 . V_50 == 0 ) {
F_15 ( V_8 ) ;
return;
}
F_30 ( V_14 , & V_8 -> V_15 ) ;
F_26 ( V_8 , V_86 ) ;
F_27 ( V_8 , V_86 ) ;
F_12 ( V_8 ) ;
if ( V_8 -> V_30 . V_34 && ( V_8 -> V_29 == V_59 ) )
V_91 = 1 ;
if ( F_4 ( V_92 , & V_90 -> V_93 ) &&
! V_91 ) {
F_15 ( V_8 ) ;
return;
}
error = F_31 ( V_82 -> V_88 , V_8 -> V_30 . V_50 , V_63 ,
NULL , V_8 ) ;
if ( error ) {
F_21 ( V_56 L_4 ,
V_8 -> V_12 . V_13 ,
( unsigned long long ) V_8 -> V_12 . V_87 , error ) ;
return;
}
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_81 * V_82 = & V_8 -> V_20 -> V_83 ;
F_31 ( V_82 -> V_88 , V_8 -> V_30 . V_50 , V_94 , NULL , V_8 ) ;
}
static void F_33 ( struct V_81 * V_82 , T_5 * V_95 ,
char * V_96 )
{
T_5 V_97 ;
memcpy ( V_96 , V_82 -> V_98 , V_35 ) ;
memcpy ( & V_97 , V_96 , sizeof( T_5 ) ) ;
* V_95 = F_34 ( V_97 ) ;
}
static void F_35 ( struct V_81 * V_82 , T_5 V_95 ,
char * V_96 )
{
T_5 V_97 ;
memcpy ( V_82 -> V_98 , V_96 , V_35 ) ;
V_97 = F_36 ( V_95 ) ;
memcpy ( V_82 -> V_98 , & V_97 , sizeof( T_5 ) ) ;
}
static int F_37 ( char * V_99 )
{
int V_100 ;
for ( V_100 = V_101 ; V_100 < V_35 ; V_100 ++ ) {
if ( V_99 [ V_100 ] )
return 0 ;
}
return 1 ;
}
static void F_38 ( void * V_27 )
{
struct V_81 * V_82 = V_27 ;
F_39 ( & V_82 -> V_102 ) ;
}
static int F_40 ( struct V_89 * V_90 , struct V_103 * V_104 , char * V_105 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
int error ;
error = F_31 ( V_82 -> V_88 , V_104 -> V_50 , 0 , V_104 , V_82 ) ;
if ( error ) {
F_41 ( V_90 , L_5 ,
V_105 , V_104 -> V_50 , error ) ;
return error ;
}
F_42 ( & V_82 -> V_102 ) ;
if ( V_104 -> V_36 != - V_37 ) {
F_41 ( V_90 , L_6 ,
V_105 , V_104 -> V_50 , V_104 -> V_36 ) ;
return - 1 ;
}
return 0 ;
}
static int F_43 ( struct V_89 * V_90 , int V_51 , T_5 V_80 ,
unsigned int V_106 , struct V_103 * V_104 , char * V_105 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
char V_84 [ V_85 ] ;
int error , V_107 ;
memset ( V_84 , 0 , V_85 ) ;
snprintf ( V_84 , V_85 , L_7 , V_108 , V_106 ) ;
error = F_28 ( V_82 -> V_88 , V_51 , V_104 , V_80 ,
V_84 , V_85 - 1 ,
0 , F_38 , V_82 , NULL ) ;
if ( error ) {
F_41 ( V_90 , L_8 ,
V_105 , V_104 -> V_50 , V_80 , V_51 , error ) ;
return error ;
}
F_42 ( & V_82 -> V_102 ) ;
V_107 = V_104 -> V_36 ;
if ( V_107 && V_107 != - V_41 ) {
F_41 ( V_90 , L_9 ,
V_105 , V_104 -> V_50 , V_80 , V_51 , V_107 ) ;
}
return V_107 ;
}
static int F_44 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
return F_40 ( V_90 , & V_82 -> V_109 , L_10 ) ;
}
static int F_45 ( struct V_89 * V_90 , int V_51 , T_5 V_80 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
return F_43 ( V_90 , V_51 , V_80 , V_110 ,
& V_82 -> V_109 , L_10 ) ;
}
static int F_46 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
return F_40 ( V_90 , & V_82 -> V_111 , L_11 ) ;
}
static int F_47 ( struct V_89 * V_90 , int V_51 , T_5 V_80 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
return F_43 ( V_90 , V_51 , V_80 , V_112 ,
& V_82 -> V_111 , L_11 ) ;
}
static void F_48 ( struct V_113 * V_114 )
{
struct V_89 * V_90 = F_49 ( V_114 , struct V_89 , V_115 . V_114 ) ;
struct V_81 * V_82 = & V_90 -> V_83 ;
char V_96 [ V_35 ] ;
T_5 V_116 , V_117 , V_95 , V_80 ;
int V_118 = 0 ;
int V_119 = 0 ;
int V_120 ;
int V_100 , error ;
F_50 ( & V_82 -> V_121 ) ;
if ( ! F_4 ( V_122 , & V_82 -> V_123 ) ||
F_4 ( V_124 , & V_82 -> V_123 ) ) {
F_51 ( & V_82 -> V_121 ) ;
return;
}
V_116 = V_82 -> V_125 ;
V_117 = V_82 -> V_126 ;
F_51 ( & V_82 -> V_121 ) ;
if ( V_116 == V_117 )
return;
error = F_47 ( V_90 , V_52 , V_74 | V_63 ) ;
if ( error ) {
F_41 ( V_90 , L_12 , error ) ;
return;
}
F_33 ( V_82 , & V_95 , V_96 ) ;
F_50 ( & V_82 -> V_121 ) ;
if ( V_116 != V_82 -> V_125 ||
V_117 != V_82 -> V_126 ) {
F_52 ( V_90 , L_13 ,
V_117 , V_116 , V_82 -> V_125 ) ;
F_51 ( & V_82 -> V_121 ) ;
F_47 ( V_90 , V_58 , V_74 ) ;
return;
}
V_120 = V_82 -> V_127 ;
if ( V_95 <= V_117 ) {
for ( V_100 = 0 ; V_100 < V_120 ; V_100 ++ ) {
if ( V_82 -> V_128 [ V_100 ] != V_129 )
continue;
V_82 -> V_128 [ V_100 ] = 0 ;
if ( ! F_53 ( V_100 , V_96 + V_101 ) )
continue;
F_54 ( V_100 , V_96 + V_101 ) ;
V_119 = 1 ;
}
}
if ( V_95 == V_117 ) {
for ( V_100 = 0 ; V_100 < V_120 ; V_100 ++ ) {
if ( ! V_82 -> V_130 [ V_100 ] )
continue;
if ( V_82 -> V_130 [ V_100 ] < V_95 )
V_82 -> V_130 [ V_100 ] = 0 ;
}
} else if ( V_95 < V_117 ) {
for ( V_100 = 0 ; V_100 < V_120 ; V_100 ++ ) {
if ( ! V_82 -> V_130 [ V_100 ] )
continue;
if ( V_82 -> V_130 [ V_100 ] < V_117 ) {
V_82 -> V_130 [ V_100 ] = 0 ;
F_55 ( V_100 , V_96 + V_101 ) ;
}
}
V_119 = 1 ;
} else {
}
F_51 ( & V_82 -> V_121 ) ;
if ( V_119 ) {
F_35 ( V_82 , V_117 , V_96 ) ;
V_80 = V_74 | V_63 ;
} else {
V_80 = V_74 ;
}
error = F_47 ( V_90 , V_58 , V_80 ) ;
if ( error ) {
F_41 ( V_90 , L_14 , error ) ;
return;
}
for ( V_100 = 0 ; V_100 < V_120 ; V_100 ++ ) {
if ( F_53 ( V_100 , V_96 + V_101 ) ) {
F_52 ( V_90 , L_15 ,
V_117 , V_100 ) ;
F_56 ( V_90 , V_100 ) ;
V_118 ++ ;
}
}
if ( V_118 )
return;
F_50 ( & V_82 -> V_121 ) ;
if ( V_82 -> V_125 == V_116 &&
V_82 -> V_126 == V_117 ) {
F_30 ( V_131 , & V_82 -> V_123 ) ;
F_51 ( & V_82 -> V_121 ) ;
F_52 ( V_90 , L_16 , V_117 ) ;
F_57 ( V_90 ) ;
} else {
F_52 ( V_90 , L_17 ,
V_117 , V_116 , V_82 -> V_125 ) ;
F_51 ( & V_82 -> V_121 ) ;
}
}
static int F_58 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
char V_96 [ V_35 ] ;
T_5 V_117 , V_116 , V_132 , V_95 ;
int V_133 ;
int V_134 = 0 ;
int error ;
memset ( & V_82 -> V_109 , 0 , sizeof( struct V_103 ) ) ;
memset ( & V_82 -> V_111 , 0 , sizeof( struct V_103 ) ) ;
memset ( & V_82 -> V_98 , 0 , V_35 ) ;
V_82 -> V_111 . V_34 = V_82 -> V_98 ;
F_59 ( & V_82 -> V_102 ) ;
F_17 ( V_131 , & V_82 -> V_123 ) ;
error = F_47 ( V_90 , V_58 , V_63 ) ;
if ( error ) {
F_41 ( V_90 , L_18 , error ) ;
return error ;
}
error = F_45 ( V_90 , V_58 , 0 ) ;
if ( error ) {
F_41 ( V_90 , L_19 , error ) ;
F_46 ( V_90 ) ;
return error ;
}
V_133 = V_58 ;
V_135:
if ( V_134 ++ && F_60 ( V_136 ) ) {
error = - V_137 ;
goto V_138;
}
if ( V_133 != V_58 ) {
error = F_45 ( V_90 , V_58 , V_74 ) ;
if ( error )
goto V_138;
V_133 = V_58 ;
}
F_61 ( 500 ) ;
error = F_47 ( V_90 , V_52 , V_74 | V_65 | V_63 ) ;
if ( error == - V_41 ) {
goto V_135;
} else if ( error ) {
F_41 ( V_90 , L_20 , error ) ;
goto V_138;
}
error = F_45 ( V_90 , V_52 , V_74 | V_65 ) ;
if ( ! error ) {
V_133 = V_52 ;
goto V_139;
} else if ( error != - V_41 ) {
F_41 ( V_90 , L_21 , error ) ;
goto V_138;
}
error = F_45 ( V_90 , V_55 , V_74 | V_65 ) ;
if ( ! error ) {
V_133 = V_55 ;
goto V_139;
} else {
F_41 ( V_90 , L_22 , error ) ;
goto V_138;
}
V_139:
F_33 ( V_82 , & V_95 , V_96 ) ;
if ( V_95 == 0xFFFFFFFF ) {
F_41 ( V_90 , L_23 ) ;
error = - V_140 ;
goto V_138;
}
if ( V_133 == V_52 ) {
F_50 ( & V_82 -> V_121 ) ;
F_30 ( V_131 , & V_82 -> V_123 ) ;
F_17 ( V_122 , & V_82 -> V_123 ) ;
F_17 ( V_124 , & V_82 -> V_123 ) ;
F_51 ( & V_82 -> V_121 ) ;
F_52 ( V_90 , L_24 , V_95 ) ;
return 0 ;
}
error = F_47 ( V_90 , V_58 , V_74 ) ;
if ( error )
goto V_138;
if ( ! F_37 ( V_96 ) ) {
F_52 ( V_90 , L_25 ) ;
goto V_135;
}
F_50 ( & V_82 -> V_121 ) ;
V_116 = V_82 -> V_125 ;
V_117 = V_82 -> V_126 ;
V_132 = V_82 -> V_141 ;
if ( V_95 < V_132 ) {
F_52 ( V_90 , L_26
L_27 , V_116 , V_117 , V_132 ,
V_95 , V_82 -> V_123 ) ;
F_51 ( & V_82 -> V_121 ) ;
goto V_135;
}
if ( V_95 != V_117 ) {
F_52 ( V_90 , L_28
L_27 , V_116 , V_117 , V_132 ,
V_95 , V_82 -> V_123 ) ;
F_51 ( & V_82 -> V_121 ) ;
goto V_135;
}
if ( V_116 == V_117 ) {
F_52 ( V_90 , L_29
L_27 , V_116 , V_117 , V_132 ,
V_95 , V_82 -> V_123 ) ;
F_51 ( & V_82 -> V_121 ) ;
goto V_135;
}
F_30 ( V_131 , & V_82 -> V_123 ) ;
F_17 ( V_122 , & V_82 -> V_123 ) ;
memset ( V_82 -> V_130 , 0 , V_82 -> V_127 * sizeof( T_5 ) ) ;
memset ( V_82 -> V_128 , 0 , V_82 -> V_127 * sizeof( T_5 ) ) ;
F_51 ( & V_82 -> V_121 ) ;
return 0 ;
V_138:
F_44 ( V_90 ) ;
F_46 ( V_90 ) ;
return error ;
}
static int F_62 ( void * V_142 )
{
F_63 () ;
return 0 ;
}
static int F_64 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
char V_96 [ V_35 ] ;
T_5 V_117 , V_116 ;
int error ;
V_135:
F_50 ( & V_82 -> V_121 ) ;
V_117 = V_82 -> V_126 ;
V_116 = V_82 -> V_125 ;
if ( F_4 ( V_131 , & V_82 -> V_123 ) ||
! F_4 ( V_122 , & V_82 -> V_123 ) ||
! F_4 ( V_124 , & V_82 -> V_123 ) ) {
F_41 ( V_90 , L_30 ,
V_117 , V_116 , V_82 -> V_123 ) ;
F_51 ( & V_82 -> V_121 ) ;
F_46 ( V_90 ) ;
return - 1 ;
}
if ( V_117 == V_116 ) {
F_51 ( & V_82 -> V_121 ) ;
F_52 ( V_90 , L_31 , V_117 ) ;
F_65 ( & V_82 -> V_123 , V_143 ,
F_62 , V_144 ) ;
goto V_135;
}
F_30 ( V_124 , & V_82 -> V_123 ) ;
F_17 ( V_145 , & V_82 -> V_123 ) ;
memset ( V_82 -> V_130 , 0 , V_82 -> V_127 * sizeof( T_5 ) ) ;
memset ( V_82 -> V_128 , 0 , V_82 -> V_127 * sizeof( T_5 ) ) ;
F_51 ( & V_82 -> V_121 ) ;
memset ( V_96 , 0 , sizeof( V_96 ) ) ;
F_35 ( V_82 , V_117 , V_96 ) ;
error = F_45 ( V_90 , V_55 , V_74 ) ;
if ( error )
F_41 ( V_90 , L_32 , error ) ;
error = F_47 ( V_90 , V_58 , V_74 | V_63 ) ;
if ( error )
F_41 ( V_90 , L_33 , error ) ;
return error ;
}
static int F_66 ( struct V_89 * V_90 , struct V_146 * V_147 ,
int V_148 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
T_5 * V_149 = NULL ;
T_5 * V_150 = NULL ;
T_5 V_151 , V_152 ;
int V_100 , V_153 ;
V_153 = 0 ;
for ( V_100 = 0 ; V_100 < V_148 ; V_100 ++ ) {
if ( V_153 < V_147 [ V_100 ] . V_154 - 1 )
V_153 = V_147 [ V_100 ] . V_154 - 1 ;
}
V_151 = V_82 -> V_127 ;
if ( V_151 >= V_153 + 1 )
return 0 ;
V_152 = V_151 + V_155 ;
V_149 = F_67 ( V_152 * sizeof( T_5 ) , V_156 ) ;
V_150 = F_67 ( V_152 * sizeof( T_5 ) , V_156 ) ;
if ( ! V_149 || ! V_150 ) {
F_68 ( V_149 ) ;
F_68 ( V_150 ) ;
return - V_157 ;
}
F_50 ( & V_82 -> V_121 ) ;
memcpy ( V_149 , V_82 -> V_130 , V_151 * sizeof( T_5 ) ) ;
memcpy ( V_150 , V_82 -> V_128 , V_151 * sizeof( T_5 ) ) ;
F_68 ( V_82 -> V_130 ) ;
F_68 ( V_82 -> V_128 ) ;
V_82 -> V_130 = V_149 ;
V_82 -> V_128 = V_150 ;
V_82 -> V_127 = V_152 ;
F_51 ( & V_82 -> V_121 ) ;
return 0 ;
}
static void F_69 ( struct V_81 * V_82 )
{
F_68 ( V_82 -> V_130 ) ;
F_68 ( V_82 -> V_128 ) ;
V_82 -> V_130 = NULL ;
V_82 -> V_128 = NULL ;
V_82 -> V_127 = 0 ;
}
static void F_70 ( void * V_27 )
{
struct V_89 * V_90 = V_27 ;
struct V_81 * V_82 = & V_90 -> V_83 ;
F_50 ( & V_82 -> V_121 ) ;
V_82 -> V_125 = V_82 -> V_126 ;
F_17 ( V_143 , & V_82 -> V_123 ) ;
if ( ! F_4 ( V_122 , & V_82 -> V_123 ) ||
F_4 ( V_124 , & V_82 -> V_123 ) ) {
F_51 ( & V_82 -> V_121 ) ;
return;
}
F_17 ( V_131 , & V_82 -> V_123 ) ;
F_51 ( & V_82 -> V_121 ) ;
}
static void F_71 ( void * V_27 , struct V_146 * V_154 )
{
struct V_89 * V_90 = V_27 ;
struct V_81 * V_82 = & V_90 -> V_83 ;
int V_158 = V_154 -> V_154 - 1 ;
F_50 ( & V_82 -> V_121 ) ;
if ( V_82 -> V_127 < V_158 + 1 ) {
F_41 ( V_90 , L_34 ,
V_158 , V_82 -> V_125 , V_82 -> V_127 ) ;
F_51 ( & V_82 -> V_121 ) ;
return;
}
if ( V_82 -> V_130 [ V_158 ] ) {
F_52 ( V_90 , L_35 ,
V_158 , V_82 -> V_125 , V_82 -> V_130 [ V_158 ] ) ;
}
V_82 -> V_130 [ V_158 ] = V_82 -> V_125 ;
F_51 ( & V_82 -> V_121 ) ;
}
static void F_72 ( void * V_27 , struct V_146 * V_147 , int V_148 ,
int V_159 , T_5 V_160 )
{
struct V_89 * V_90 = V_27 ;
struct V_81 * V_82 = & V_90 -> V_83 ;
F_66 ( V_90 , V_147 , V_148 ) ;
F_50 ( & V_82 -> V_121 ) ;
V_82 -> V_126 = V_160 ;
if ( ! V_82 -> V_141 ) {
V_82 -> V_141 = V_160 ;
V_82 -> V_161 = V_159 - 1 ;
}
if ( ! F_4 ( V_162 , & V_82 -> V_123 ) )
F_73 ( V_163 , & V_90 -> V_115 , 0 ) ;
F_30 ( V_143 , & V_82 -> V_123 ) ;
F_74 () ;
F_75 ( & V_82 -> V_123 , V_143 ) ;
F_51 ( & V_82 -> V_121 ) ;
}
static void F_76 ( struct V_89 * V_90 , unsigned int V_158 ,
unsigned int V_150 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
if ( F_4 ( V_164 , & V_82 -> V_123 ) )
return;
if ( V_158 == V_82 -> V_161 )
return;
F_50 ( & V_82 -> V_121 ) ;
if ( F_4 ( V_124 , & V_82 -> V_123 ) ) {
F_51 ( & V_82 -> V_121 ) ;
return;
}
if ( V_82 -> V_127 < V_158 + 1 ) {
F_41 ( V_90 , L_36 ,
V_158 , V_82 -> V_127 ) ;
F_51 ( & V_82 -> V_121 ) ;
return;
}
F_52 ( V_90 , L_37 , V_158 ,
V_150 == V_165 ? L_38 : L_39 ) ;
V_82 -> V_128 [ V_158 ] = V_150 ;
if ( ! F_4 ( V_162 , & V_82 -> V_123 ) )
F_73 ( V_163 , & V_90 -> V_115 ,
V_150 == V_165 ? V_166 : 0 ) ;
F_51 ( & V_82 -> V_121 ) ;
}
static int F_77 ( struct V_89 * V_90 , const char * V_167 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
char V_168 [ V_169 ] ;
const char * V_170 ;
T_5 V_80 ;
int error , V_171 ;
F_78 ( & V_90 -> V_115 , F_48 ) ;
F_79 ( & V_82 -> V_121 ) ;
V_82 -> V_123 = 0 ;
V_82 -> V_141 = 0 ;
V_82 -> V_126 = 0 ;
V_82 -> V_125 = 0 ;
V_82 -> V_127 = 0 ;
V_82 -> V_130 = NULL ;
V_82 -> V_128 = NULL ;
error = F_66 ( V_90 , NULL , 0 ) ;
if ( error )
goto V_138;
V_170 = strchr ( V_167 , ':' ) ;
if ( ! V_170 ) {
F_52 ( V_90 , L_40 ) ;
error = - V_140 ;
goto V_172;
}
memset ( V_168 , 0 , sizeof( V_168 ) ) ;
memcpy ( V_168 , V_167 , strlen ( V_167 ) - strlen ( V_170 ) ) ;
V_170 ++ ;
V_80 = V_173 | V_174 ;
error = F_80 ( V_170 , V_168 , V_80 , V_35 ,
& V_175 , V_90 , & V_171 ,
& V_82 -> V_88 ) ;
if ( error ) {
F_41 ( V_90 , L_41 , error ) ;
goto V_172;
}
if ( V_171 < 0 ) {
F_52 ( V_90 , L_42 ) ;
F_69 ( V_82 ) ;
F_17 ( V_164 , & V_82 -> V_123 ) ;
return 0 ;
}
if ( ! F_4 ( V_176 , & V_90 -> V_93 ) ) {
F_41 ( V_90 , L_43 ) ;
error = - V_140 ;
goto V_177;
}
error = F_58 ( V_90 ) ;
if ( error ) {
F_41 ( V_90 , L_44 , error ) ;
goto V_177;
}
V_82 -> V_178 = ! ! F_4 ( V_124 , & V_82 -> V_123 ) ;
F_30 ( V_176 , & V_90 -> V_93 ) ;
F_74 () ;
F_75 ( & V_90 -> V_93 , V_176 ) ;
return 0 ;
V_177:
F_81 ( V_82 -> V_88 , 2 ) ;
V_172:
F_69 ( V_82 ) ;
V_138:
return error ;
}
static void F_82 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
int error ;
if ( F_4 ( V_164 , & V_82 -> V_123 ) )
return;
error = F_64 ( V_90 ) ;
if ( error )
F_41 ( V_90 , L_45 , error ) ;
}
static void F_83 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
if ( F_4 ( V_164 , & V_82 -> V_123 ) )
goto V_179;
F_50 ( & V_82 -> V_121 ) ;
F_17 ( V_162 , & V_82 -> V_123 ) ;
F_51 ( & V_82 -> V_121 ) ;
F_84 ( & V_90 -> V_115 ) ;
V_179:
if ( V_82 -> V_88 ) {
F_81 ( V_82 -> V_88 , 2 ) ;
V_82 -> V_88 = NULL ;
}
F_69 ( V_82 ) ;
}

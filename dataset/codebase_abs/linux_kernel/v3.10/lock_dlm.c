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
return ! F_38 ( V_99 + V_100 , 0 ,
V_35 - V_100 ) ;
}
static void F_39 ( void * V_27 )
{
struct V_81 * V_82 = V_27 ;
F_40 ( & V_82 -> V_101 ) ;
}
static int F_41 ( struct V_89 * V_90 , struct V_102 * V_103 , char * V_104 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
int error ;
error = F_31 ( V_82 -> V_88 , V_103 -> V_50 , 0 , V_103 , V_82 ) ;
if ( error ) {
F_42 ( V_90 , L_5 ,
V_104 , V_103 -> V_50 , error ) ;
return error ;
}
F_43 ( & V_82 -> V_101 ) ;
if ( V_103 -> V_36 != - V_37 ) {
F_42 ( V_90 , L_6 ,
V_104 , V_103 -> V_50 , V_103 -> V_36 ) ;
return - 1 ;
}
return 0 ;
}
static int F_44 ( struct V_89 * V_90 , int V_51 , T_5 V_80 ,
unsigned int V_105 , struct V_102 * V_103 , char * V_104 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
char V_84 [ V_85 ] ;
int error , V_106 ;
memset ( V_84 , 0 , V_85 ) ;
snprintf ( V_84 , V_85 , L_7 , V_107 , V_105 ) ;
error = F_28 ( V_82 -> V_88 , V_51 , V_103 , V_80 ,
V_84 , V_85 - 1 ,
0 , F_39 , V_82 , NULL ) ;
if ( error ) {
F_42 ( V_90 , L_8 ,
V_104 , V_103 -> V_50 , V_80 , V_51 , error ) ;
return error ;
}
F_43 ( & V_82 -> V_101 ) ;
V_106 = V_103 -> V_36 ;
if ( V_106 && V_106 != - V_41 ) {
F_42 ( V_90 , L_9 ,
V_104 , V_103 -> V_50 , V_80 , V_51 , V_106 ) ;
}
return V_106 ;
}
static int F_45 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
return F_41 ( V_90 , & V_82 -> V_108 , L_10 ) ;
}
static int F_46 ( struct V_89 * V_90 , int V_51 , T_5 V_80 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
return F_44 ( V_90 , V_51 , V_80 , V_109 ,
& V_82 -> V_108 , L_10 ) ;
}
static int F_47 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
return F_41 ( V_90 , & V_82 -> V_110 , L_11 ) ;
}
static int F_48 ( struct V_89 * V_90 , int V_51 , T_5 V_80 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
return F_44 ( V_90 , V_51 , V_80 , V_111 ,
& V_82 -> V_110 , L_11 ) ;
}
static void F_49 ( struct V_112 * V_113 )
{
struct V_89 * V_90 = F_50 ( V_113 , struct V_89 , V_114 . V_113 ) ;
struct V_81 * V_82 = & V_90 -> V_83 ;
T_5 V_115 , V_116 , V_95 , V_80 ;
int V_117 = 0 ;
int V_118 = 0 ;
int V_119 ;
int V_120 , error ;
F_51 ( & V_82 -> V_121 ) ;
if ( ! F_4 ( V_122 , & V_82 -> V_123 ) ||
F_4 ( V_124 , & V_82 -> V_123 ) ) {
F_52 ( & V_82 -> V_121 ) ;
return;
}
V_115 = V_82 -> V_125 ;
V_116 = V_82 -> V_126 ;
F_52 ( & V_82 -> V_121 ) ;
if ( V_115 == V_116 )
return;
error = F_48 ( V_90 , V_52 , V_74 | V_63 ) ;
if ( error ) {
F_42 ( V_90 , L_12 , error ) ;
return;
}
F_33 ( V_82 , & V_95 , V_82 -> V_127 ) ;
F_51 ( & V_82 -> V_121 ) ;
if ( V_115 != V_82 -> V_125 ||
V_116 != V_82 -> V_126 ) {
F_53 ( V_90 , L_13 ,
V_116 , V_115 , V_82 -> V_125 ) ;
F_52 ( & V_82 -> V_121 ) ;
F_48 ( V_90 , V_58 , V_74 ) ;
return;
}
V_119 = V_82 -> V_128 ;
if ( V_95 <= V_116 ) {
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
if ( V_82 -> V_129 [ V_120 ] != V_130 )
continue;
V_82 -> V_129 [ V_120 ] = 0 ;
if ( ! F_54 ( V_120 , V_82 -> V_127 + V_100 ) )
continue;
F_55 ( V_120 , V_82 -> V_127 + V_100 ) ;
V_118 = 1 ;
}
}
if ( V_95 == V_116 ) {
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
if ( ! V_82 -> V_131 [ V_120 ] )
continue;
if ( V_82 -> V_131 [ V_120 ] < V_95 )
V_82 -> V_131 [ V_120 ] = 0 ;
}
} else if ( V_95 < V_116 ) {
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
if ( ! V_82 -> V_131 [ V_120 ] )
continue;
if ( V_82 -> V_131 [ V_120 ] < V_116 ) {
V_82 -> V_131 [ V_120 ] = 0 ;
F_56 ( V_120 , V_82 -> V_127 + V_100 ) ;
}
}
V_118 = 1 ;
} else {
}
F_52 ( & V_82 -> V_121 ) ;
if ( V_118 ) {
F_35 ( V_82 , V_116 , V_82 -> V_127 ) ;
V_80 = V_74 | V_63 ;
} else {
V_80 = V_74 ;
}
error = F_48 ( V_90 , V_58 , V_80 ) ;
if ( error ) {
F_42 ( V_90 , L_14 , error ) ;
return;
}
for ( V_120 = 0 ; V_120 < V_119 ; V_120 ++ ) {
if ( F_54 ( V_120 , V_82 -> V_127 + V_100 ) ) {
F_53 ( V_90 , L_15 ,
V_116 , V_120 ) ;
F_57 ( V_90 , V_120 ) ;
V_117 ++ ;
}
}
if ( V_117 )
return;
F_51 ( & V_82 -> V_121 ) ;
if ( V_82 -> V_125 == V_115 &&
V_82 -> V_126 == V_116 ) {
F_30 ( V_132 , & V_82 -> V_123 ) ;
F_52 ( & V_82 -> V_121 ) ;
F_53 ( V_90 , L_16 , V_116 ) ;
F_58 ( V_90 ) ;
} else {
F_53 ( V_90 , L_17 ,
V_116 , V_115 , V_82 -> V_125 ) ;
F_52 ( & V_82 -> V_121 ) ;
}
}
static int F_59 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
T_5 V_116 , V_115 , V_133 , V_95 ;
int V_134 ;
int V_135 = 0 ;
int error ;
memset ( & V_82 -> V_108 , 0 , sizeof( struct V_102 ) ) ;
memset ( & V_82 -> V_110 , 0 , sizeof( struct V_102 ) ) ;
memset ( & V_82 -> V_98 , 0 , V_35 ) ;
V_82 -> V_110 . V_34 = V_82 -> V_98 ;
F_60 ( & V_82 -> V_101 ) ;
F_17 ( V_132 , & V_82 -> V_123 ) ;
error = F_48 ( V_90 , V_58 , V_63 ) ;
if ( error ) {
F_42 ( V_90 , L_18 , error ) ;
return error ;
}
error = F_46 ( V_90 , V_58 , 0 ) ;
if ( error ) {
F_42 ( V_90 , L_19 , error ) ;
F_47 ( V_90 ) ;
return error ;
}
V_134 = V_58 ;
V_136:
if ( V_135 ++ && F_61 ( V_137 ) ) {
error = - V_138 ;
goto V_139;
}
if ( V_134 != V_58 ) {
error = F_46 ( V_90 , V_58 , V_74 ) ;
if ( error )
goto V_139;
V_134 = V_58 ;
}
F_62 ( 500 ) ;
error = F_48 ( V_90 , V_52 , V_74 | V_65 | V_63 ) ;
if ( error == - V_41 ) {
goto V_136;
} else if ( error ) {
F_42 ( V_90 , L_20 , error ) ;
goto V_139;
}
error = F_46 ( V_90 , V_52 , V_74 | V_65 ) ;
if ( ! error ) {
V_134 = V_52 ;
goto V_140;
} else if ( error != - V_41 ) {
F_42 ( V_90 , L_21 , error ) ;
goto V_139;
}
error = F_46 ( V_90 , V_55 , V_74 | V_65 ) ;
if ( ! error ) {
V_134 = V_55 ;
goto V_140;
} else {
F_42 ( V_90 , L_22 , error ) ;
goto V_139;
}
V_140:
F_33 ( V_82 , & V_95 , V_82 -> V_127 ) ;
if ( V_95 == 0xFFFFFFFF ) {
F_42 ( V_90 , L_23 ) ;
error = - V_141 ;
goto V_139;
}
if ( V_134 == V_52 ) {
F_51 ( & V_82 -> V_121 ) ;
F_30 ( V_132 , & V_82 -> V_123 ) ;
F_17 ( V_122 , & V_82 -> V_123 ) ;
F_17 ( V_124 , & V_82 -> V_123 ) ;
F_52 ( & V_82 -> V_121 ) ;
F_53 ( V_90 , L_24 , V_95 ) ;
return 0 ;
}
error = F_48 ( V_90 , V_58 , V_74 ) ;
if ( error )
goto V_139;
if ( ! F_37 ( V_82 -> V_127 ) ) {
F_53 ( V_90 , L_25 ) ;
goto V_136;
}
F_51 ( & V_82 -> V_121 ) ;
V_115 = V_82 -> V_125 ;
V_116 = V_82 -> V_126 ;
V_133 = V_82 -> V_142 ;
if ( V_95 < V_133 ) {
F_53 ( V_90 , L_26
L_27 , V_115 , V_116 , V_133 ,
V_95 , V_82 -> V_123 ) ;
F_52 ( & V_82 -> V_121 ) ;
goto V_136;
}
if ( V_95 != V_116 ) {
F_53 ( V_90 , L_28
L_27 , V_115 , V_116 , V_133 ,
V_95 , V_82 -> V_123 ) ;
F_52 ( & V_82 -> V_121 ) ;
goto V_136;
}
if ( V_115 == V_116 ) {
F_53 ( V_90 , L_29
L_27 , V_115 , V_116 , V_133 ,
V_95 , V_82 -> V_123 ) ;
F_52 ( & V_82 -> V_121 ) ;
goto V_136;
}
F_30 ( V_132 , & V_82 -> V_123 ) ;
F_17 ( V_122 , & V_82 -> V_123 ) ;
memset ( V_82 -> V_131 , 0 , V_82 -> V_128 * sizeof( T_5 ) ) ;
memset ( V_82 -> V_129 , 0 , V_82 -> V_128 * sizeof( T_5 ) ) ;
F_52 ( & V_82 -> V_121 ) ;
return 0 ;
V_139:
F_45 ( V_90 ) ;
F_47 ( V_90 ) ;
return error ;
}
static int F_63 ( void * V_143 )
{
F_64 () ;
return 0 ;
}
static int F_65 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
T_5 V_116 , V_115 ;
int error ;
V_136:
F_51 ( & V_82 -> V_121 ) ;
V_116 = V_82 -> V_126 ;
V_115 = V_82 -> V_125 ;
if ( F_4 ( V_132 , & V_82 -> V_123 ) ||
! F_4 ( V_122 , & V_82 -> V_123 ) ||
! F_4 ( V_124 , & V_82 -> V_123 ) ) {
F_42 ( V_90 , L_30 ,
V_116 , V_115 , V_82 -> V_123 ) ;
F_52 ( & V_82 -> V_121 ) ;
F_47 ( V_90 ) ;
return - 1 ;
}
if ( V_116 == V_115 ) {
F_52 ( & V_82 -> V_121 ) ;
F_53 ( V_90 , L_31 , V_116 ) ;
F_66 ( & V_82 -> V_123 , V_144 ,
F_63 , V_145 ) ;
goto V_136;
}
F_30 ( V_124 , & V_82 -> V_123 ) ;
F_17 ( V_146 , & V_82 -> V_123 ) ;
memset ( V_82 -> V_131 , 0 , V_82 -> V_128 * sizeof( T_5 ) ) ;
memset ( V_82 -> V_129 , 0 , V_82 -> V_128 * sizeof( T_5 ) ) ;
F_52 ( & V_82 -> V_121 ) ;
memset ( V_82 -> V_127 , 0 , V_35 ) ;
F_35 ( V_82 , V_116 , V_82 -> V_127 ) ;
error = F_46 ( V_90 , V_55 , V_74 ) ;
if ( error )
F_42 ( V_90 , L_32 , error ) ;
error = F_48 ( V_90 , V_58 , V_74 | V_63 ) ;
if ( error )
F_42 ( V_90 , L_33 , error ) ;
return error ;
}
static int F_67 ( struct V_89 * V_90 , struct V_147 * V_148 ,
int V_149 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
T_5 * V_150 = NULL ;
T_5 * V_151 = NULL ;
T_5 V_152 , V_153 ;
int V_120 , V_154 ;
if ( ! V_82 -> V_127 ) {
V_82 -> V_127 = F_68 ( V_35 , V_155 ) ;
if ( ! V_82 -> V_127 )
return - V_156 ;
}
V_154 = 0 ;
for ( V_120 = 0 ; V_120 < V_149 ; V_120 ++ ) {
if ( V_154 < V_148 [ V_120 ] . V_157 - 1 )
V_154 = V_148 [ V_120 ] . V_157 - 1 ;
}
V_152 = V_82 -> V_128 ;
if ( V_152 >= V_154 + 1 )
return 0 ;
V_153 = V_152 + V_158 ;
V_150 = F_68 ( V_153 * sizeof( T_5 ) , V_155 ) ;
V_151 = F_68 ( V_153 * sizeof( T_5 ) , V_155 ) ;
if ( ! V_150 || ! V_151 ) {
F_69 ( V_150 ) ;
F_69 ( V_151 ) ;
return - V_156 ;
}
F_51 ( & V_82 -> V_121 ) ;
memcpy ( V_150 , V_82 -> V_131 , V_152 * sizeof( T_5 ) ) ;
memcpy ( V_151 , V_82 -> V_129 , V_152 * sizeof( T_5 ) ) ;
F_69 ( V_82 -> V_131 ) ;
F_69 ( V_82 -> V_129 ) ;
V_82 -> V_131 = V_150 ;
V_82 -> V_129 = V_151 ;
V_82 -> V_128 = V_153 ;
F_52 ( & V_82 -> V_121 ) ;
return 0 ;
}
static void F_70 ( struct V_81 * V_82 )
{
F_69 ( V_82 -> V_127 ) ;
F_69 ( V_82 -> V_131 ) ;
F_69 ( V_82 -> V_129 ) ;
V_82 -> V_131 = NULL ;
V_82 -> V_129 = NULL ;
V_82 -> V_128 = 0 ;
}
static void F_71 ( void * V_27 )
{
struct V_89 * V_90 = V_27 ;
struct V_81 * V_82 = & V_90 -> V_83 ;
F_51 ( & V_82 -> V_121 ) ;
V_82 -> V_125 = V_82 -> V_126 ;
F_17 ( V_144 , & V_82 -> V_123 ) ;
if ( ! F_4 ( V_122 , & V_82 -> V_123 ) ||
F_4 ( V_124 , & V_82 -> V_123 ) ) {
F_52 ( & V_82 -> V_121 ) ;
return;
}
F_17 ( V_132 , & V_82 -> V_123 ) ;
F_52 ( & V_82 -> V_121 ) ;
}
static void F_72 ( void * V_27 , struct V_147 * V_157 )
{
struct V_89 * V_90 = V_27 ;
struct V_81 * V_82 = & V_90 -> V_83 ;
int V_159 = V_157 -> V_157 - 1 ;
F_51 ( & V_82 -> V_121 ) ;
if ( V_82 -> V_128 < V_159 + 1 ) {
F_42 ( V_90 , L_34 ,
V_159 , V_82 -> V_125 , V_82 -> V_128 ) ;
F_52 ( & V_82 -> V_121 ) ;
return;
}
if ( V_82 -> V_131 [ V_159 ] ) {
F_53 ( V_90 , L_35 ,
V_159 , V_82 -> V_125 , V_82 -> V_131 [ V_159 ] ) ;
}
V_82 -> V_131 [ V_159 ] = V_82 -> V_125 ;
F_52 ( & V_82 -> V_121 ) ;
}
static void F_73 ( void * V_27 , struct V_147 * V_148 , int V_149 ,
int V_160 , T_5 V_161 )
{
struct V_89 * V_90 = V_27 ;
struct V_81 * V_82 = & V_90 -> V_83 ;
F_67 ( V_90 , V_148 , V_149 ) ;
F_51 ( & V_82 -> V_121 ) ;
V_82 -> V_126 = V_161 ;
if ( ! V_82 -> V_142 ) {
V_82 -> V_142 = V_161 ;
V_82 -> V_162 = V_160 - 1 ;
}
if ( ! F_4 ( V_163 , & V_82 -> V_123 ) )
F_74 ( V_164 , & V_90 -> V_114 , 0 ) ;
F_30 ( V_144 , & V_82 -> V_123 ) ;
F_75 () ;
F_76 ( & V_82 -> V_123 , V_144 ) ;
F_52 ( & V_82 -> V_121 ) ;
}
static void F_77 ( struct V_89 * V_90 , unsigned int V_159 ,
unsigned int V_151 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
if ( F_4 ( V_165 , & V_82 -> V_123 ) )
return;
if ( V_159 == V_82 -> V_162 )
return;
F_51 ( & V_82 -> V_121 ) ;
if ( F_4 ( V_124 , & V_82 -> V_123 ) ) {
F_52 ( & V_82 -> V_121 ) ;
return;
}
if ( V_82 -> V_128 < V_159 + 1 ) {
F_42 ( V_90 , L_36 ,
V_159 , V_82 -> V_128 ) ;
F_52 ( & V_82 -> V_121 ) ;
return;
}
F_53 ( V_90 , L_37 , V_159 ,
V_151 == V_166 ? L_38 : L_39 ) ;
V_82 -> V_129 [ V_159 ] = V_151 ;
if ( ! F_4 ( V_163 , & V_82 -> V_123 ) )
F_74 ( V_164 , & V_90 -> V_114 ,
V_151 == V_166 ? V_167 : 0 ) ;
F_52 ( & V_82 -> V_121 ) ;
}
static int F_78 ( struct V_89 * V_90 , const char * V_168 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
char V_169 [ V_170 ] ;
const char * V_171 ;
T_5 V_80 ;
int error , V_172 ;
F_79 ( & V_90 -> V_114 , F_49 ) ;
F_80 ( & V_82 -> V_121 ) ;
V_82 -> V_123 = 0 ;
V_82 -> V_142 = 0 ;
V_82 -> V_126 = 0 ;
V_82 -> V_125 = 0 ;
V_82 -> V_128 = 0 ;
V_82 -> V_131 = NULL ;
V_82 -> V_129 = NULL ;
V_82 -> V_127 = NULL ;
error = F_67 ( V_90 , NULL , 0 ) ;
if ( error )
goto V_139;
V_171 = strchr ( V_168 , ':' ) ;
if ( ! V_171 ) {
F_53 ( V_90 , L_40 ) ;
error = - V_141 ;
goto V_173;
}
memset ( V_169 , 0 , sizeof( V_169 ) ) ;
memcpy ( V_169 , V_168 , strlen ( V_168 ) - strlen ( V_171 ) ) ;
V_171 ++ ;
V_80 = V_174 | V_175 ;
error = F_81 ( V_171 , V_169 , V_80 , V_35 ,
& V_176 , V_90 , & V_172 ,
& V_82 -> V_88 ) ;
if ( error ) {
F_42 ( V_90 , L_41 , error ) ;
goto V_173;
}
if ( V_172 < 0 ) {
F_53 ( V_90 , L_42 ) ;
F_70 ( V_82 ) ;
F_17 ( V_165 , & V_82 -> V_123 ) ;
return 0 ;
}
if ( ! F_4 ( V_177 , & V_90 -> V_93 ) ) {
F_42 ( V_90 , L_43 ) ;
error = - V_141 ;
goto V_178;
}
error = F_59 ( V_90 ) ;
if ( error ) {
F_42 ( V_90 , L_44 , error ) ;
goto V_178;
}
V_82 -> V_179 = ! ! F_4 ( V_124 , & V_82 -> V_123 ) ;
F_30 ( V_177 , & V_90 -> V_93 ) ;
F_75 () ;
F_76 ( & V_90 -> V_93 , V_177 ) ;
return 0 ;
V_178:
F_82 ( V_82 -> V_88 , 2 ) ;
V_173:
F_70 ( V_82 ) ;
V_139:
return error ;
}
static void F_83 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
int error ;
if ( F_4 ( V_165 , & V_82 -> V_123 ) )
return;
error = F_65 ( V_90 ) ;
if ( error )
F_42 ( V_90 , L_45 , error ) ;
}
static void F_84 ( struct V_89 * V_90 )
{
struct V_81 * V_82 = & V_90 -> V_83 ;
if ( F_4 ( V_165 , & V_82 -> V_123 ) )
goto V_180;
F_51 ( & V_82 -> V_121 ) ;
F_17 ( V_163 , & V_82 -> V_123 ) ;
F_52 ( & V_82 -> V_121 ) ;
F_85 ( & V_90 -> V_114 ) ;
V_180:
if ( V_82 -> V_88 ) {
F_82 ( V_82 -> V_88 , 2 ) ;
V_82 -> V_88 = NULL ;
}
F_70 ( V_82 ) ;
}

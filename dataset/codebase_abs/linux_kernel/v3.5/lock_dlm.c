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
if ( V_8 -> V_30 . V_31 & V_33 )
memset ( V_8 -> V_34 , 0 , V_35 ) ;
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
T_3 V_62 = V_63 ;
T_3 V_64 = V_8 -> V_30 . V_50 ;
if ( V_60 & V_65 )
V_62 |= V_66 ;
if ( V_60 & V_67 ) {
V_62 |= V_66 ;
V_62 |= V_68 ;
}
if ( V_60 & V_69 ) {
V_62 |= V_70 ;
V_62 |= V_71 ;
}
if ( V_60 & V_72 ) {
if ( V_61 == V_55 )
V_62 |= V_73 ;
else if ( V_61 == V_54 )
V_62 |= V_74 ;
else
F_16 () ;
}
if ( V_64 != 0 ) {
V_62 |= V_75 ;
if ( F_4 ( V_14 , & V_8 -> V_15 ) )
V_62 |= V_76 ;
}
return V_62 ;
}
static void F_24 ( char * V_77 , T_4 V_78 )
{
while ( V_78 ) {
* V_77 -- = V_79 [ V_78 & 0x0f ] ;
V_78 >>= 4 ;
}
}
static int F_25 ( struct V_7 * V_8 , unsigned int V_80 ,
unsigned int V_81 )
{
struct V_82 * V_83 = & V_8 -> V_20 -> V_84 ;
int V_61 ;
T_3 V_62 ;
char V_85 [ V_86 ] = L_3 ;
V_61 = F_22 ( V_80 ) ;
V_62 = F_23 ( V_8 , V_81 , V_61 ) ;
F_26 ( V_8 , V_87 ) ;
F_27 ( V_8 , V_87 ) ;
if ( V_8 -> V_30 . V_50 ) {
F_12 ( V_8 ) ;
} else {
memset ( V_85 , ' ' , V_86 - 1 ) ;
V_85 [ V_86 - 1 ] = '\0' ;
F_24 ( V_85 + 7 , V_8 -> V_12 . V_13 ) ;
F_24 ( V_85 + 23 , V_8 -> V_12 . V_88 ) ;
V_8 -> V_19 = F_8 () ;
}
return F_28 ( V_83 -> V_89 , V_61 , & V_8 -> V_30 , V_62 , V_85 ,
V_86 - 1 , 0 , F_13 , V_8 , F_19 ) ;
}
static void F_29 ( struct V_7 * V_8 )
{
struct V_90 * V_91 = V_8 -> V_20 ;
struct V_82 * V_83 = & V_91 -> V_84 ;
int error ;
if ( V_8 -> V_30 . V_50 == 0 ) {
F_15 ( V_8 ) ;
return;
}
F_30 ( V_14 , & V_8 -> V_15 ) ;
F_26 ( V_8 , V_87 ) ;
F_27 ( V_8 , V_87 ) ;
F_12 ( V_8 ) ;
error = F_31 ( V_83 -> V_89 , V_8 -> V_30 . V_50 , V_63 ,
NULL , V_8 ) ;
if ( error ) {
F_21 ( V_56 L_4 ,
V_8 -> V_12 . V_13 ,
( unsigned long long ) V_8 -> V_12 . V_88 , error ) ;
return;
}
}
static void F_32 ( struct V_7 * V_8 )
{
struct V_82 * V_83 = & V_8 -> V_20 -> V_84 ;
F_31 ( V_83 -> V_89 , V_8 -> V_30 . V_50 , V_92 , NULL , V_8 ) ;
}
static void F_33 ( struct V_82 * V_83 , T_5 * V_93 ,
char * V_94 )
{
T_5 V_95 ;
memcpy ( V_94 , V_83 -> V_96 , V_35 ) ;
memcpy ( & V_95 , V_94 , sizeof( T_5 ) ) ;
* V_93 = F_34 ( V_95 ) ;
}
static void F_35 ( struct V_82 * V_83 , T_5 V_93 ,
char * V_94 )
{
T_5 V_95 ;
memcpy ( V_83 -> V_96 , V_94 , V_35 ) ;
V_95 = F_36 ( V_93 ) ;
memcpy ( V_83 -> V_96 , & V_95 , sizeof( T_5 ) ) ;
}
static int F_37 ( char * V_97 )
{
int V_98 ;
for ( V_98 = V_99 ; V_98 < V_35 ; V_98 ++ ) {
if ( V_97 [ V_98 ] )
return 0 ;
}
return 1 ;
}
static void F_38 ( void * V_27 )
{
struct V_82 * V_83 = V_27 ;
F_39 ( & V_83 -> V_100 ) ;
}
static int F_40 ( struct V_90 * V_91 , struct V_101 * V_102 , char * V_103 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
int error ;
error = F_31 ( V_83 -> V_89 , V_102 -> V_50 , 0 , V_102 , V_83 ) ;
if ( error ) {
F_41 ( V_91 , L_5 ,
V_103 , V_102 -> V_50 , error ) ;
return error ;
}
F_42 ( & V_83 -> V_100 ) ;
if ( V_102 -> V_36 != - V_37 ) {
F_41 ( V_91 , L_6 ,
V_103 , V_102 -> V_50 , V_102 -> V_36 ) ;
return - 1 ;
}
return 0 ;
}
static int F_43 ( struct V_90 * V_91 , int V_51 , T_5 V_81 ,
unsigned int V_104 , struct V_101 * V_102 , char * V_103 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
char V_85 [ V_86 ] ;
int error , V_105 ;
memset ( V_85 , 0 , V_86 ) ;
snprintf ( V_85 , V_86 , L_7 , V_106 , V_104 ) ;
error = F_28 ( V_83 -> V_89 , V_51 , V_102 , V_81 ,
V_85 , V_86 - 1 ,
0 , F_38 , V_83 , NULL ) ;
if ( error ) {
F_41 ( V_91 , L_8 ,
V_103 , V_102 -> V_50 , V_81 , V_51 , error ) ;
return error ;
}
F_42 ( & V_83 -> V_100 ) ;
V_105 = V_102 -> V_36 ;
if ( V_105 && V_105 != - V_41 ) {
F_41 ( V_91 , L_9 ,
V_103 , V_102 -> V_50 , V_81 , V_51 , V_105 ) ;
}
return V_105 ;
}
static int F_44 ( struct V_90 * V_91 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
return F_40 ( V_91 , & V_83 -> V_107 , L_10 ) ;
}
static int F_45 ( struct V_90 * V_91 , int V_51 , T_5 V_81 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
return F_43 ( V_91 , V_51 , V_81 , V_108 ,
& V_83 -> V_107 , L_10 ) ;
}
static int F_46 ( struct V_90 * V_91 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
return F_40 ( V_91 , & V_83 -> V_109 , L_11 ) ;
}
static int F_47 ( struct V_90 * V_91 , int V_51 , T_5 V_81 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
return F_43 ( V_91 , V_51 , V_81 , V_110 ,
& V_83 -> V_109 , L_11 ) ;
}
static void F_48 ( struct V_111 * V_112 )
{
struct V_90 * V_91 = F_49 ( V_112 , struct V_90 , V_113 . V_112 ) ;
struct V_82 * V_83 = & V_91 -> V_84 ;
char V_94 [ V_35 ] ;
T_5 V_114 , V_115 , V_93 , V_81 ;
int V_116 = 0 ;
int V_117 = 0 ;
int V_118 ;
int V_98 , error ;
F_50 ( & V_83 -> V_119 ) ;
if ( ! F_4 ( V_120 , & V_83 -> V_121 ) ||
F_4 ( V_122 , & V_83 -> V_121 ) ) {
F_51 ( & V_83 -> V_119 ) ;
return;
}
V_114 = V_83 -> V_123 ;
V_115 = V_83 -> V_124 ;
F_51 ( & V_83 -> V_119 ) ;
if ( V_114 == V_115 )
return;
error = F_47 ( V_91 , V_52 , V_75 | V_63 ) ;
if ( error ) {
F_41 ( V_91 , L_12 , error ) ;
return;
}
F_33 ( V_83 , & V_93 , V_94 ) ;
F_50 ( & V_83 -> V_119 ) ;
if ( V_114 != V_83 -> V_123 ||
V_115 != V_83 -> V_124 ) {
F_52 ( V_91 , L_13 ,
V_115 , V_114 , V_83 -> V_123 ) ;
F_51 ( & V_83 -> V_119 ) ;
F_47 ( V_91 , V_58 , V_75 ) ;
return;
}
V_118 = V_83 -> V_125 ;
if ( V_93 <= V_115 ) {
for ( V_98 = 0 ; V_98 < V_118 ; V_98 ++ ) {
if ( V_83 -> V_126 [ V_98 ] != V_127 )
continue;
V_83 -> V_126 [ V_98 ] = 0 ;
if ( ! F_53 ( V_98 , V_94 + V_99 ) )
continue;
F_54 ( V_98 , V_94 + V_99 ) ;
V_117 = 1 ;
}
}
if ( V_93 == V_115 ) {
for ( V_98 = 0 ; V_98 < V_118 ; V_98 ++ ) {
if ( ! V_83 -> V_128 [ V_98 ] )
continue;
if ( V_83 -> V_128 [ V_98 ] < V_93 )
V_83 -> V_128 [ V_98 ] = 0 ;
}
} else if ( V_93 < V_115 ) {
for ( V_98 = 0 ; V_98 < V_118 ; V_98 ++ ) {
if ( ! V_83 -> V_128 [ V_98 ] )
continue;
if ( V_83 -> V_128 [ V_98 ] < V_115 ) {
V_83 -> V_128 [ V_98 ] = 0 ;
F_55 ( V_98 , V_94 + V_99 ) ;
}
}
V_117 = 1 ;
} else {
}
F_51 ( & V_83 -> V_119 ) ;
if ( V_117 ) {
F_35 ( V_83 , V_115 , V_94 ) ;
V_81 = V_75 | V_63 ;
} else {
V_81 = V_75 ;
}
error = F_47 ( V_91 , V_58 , V_81 ) ;
if ( error ) {
F_41 ( V_91 , L_14 , error ) ;
return;
}
for ( V_98 = 0 ; V_98 < V_118 ; V_98 ++ ) {
if ( F_53 ( V_98 , V_94 + V_99 ) ) {
F_52 ( V_91 , L_15 ,
V_115 , V_98 ) ;
F_56 ( V_91 , V_98 ) ;
V_116 ++ ;
}
}
if ( V_116 )
return;
F_50 ( & V_83 -> V_119 ) ;
if ( V_83 -> V_123 == V_114 &&
V_83 -> V_124 == V_115 ) {
F_30 ( V_129 , & V_83 -> V_121 ) ;
F_51 ( & V_83 -> V_119 ) ;
F_52 ( V_91 , L_16 , V_115 ) ;
F_57 ( V_91 ) ;
} else {
F_52 ( V_91 , L_17 ,
V_115 , V_114 , V_83 -> V_123 ) ;
F_51 ( & V_83 -> V_119 ) ;
}
}
static int F_58 ( struct V_90 * V_91 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
char V_94 [ V_35 ] ;
T_5 V_115 , V_114 , V_130 , V_93 ;
int V_131 ;
int V_132 = 0 ;
int error ;
memset ( & V_83 -> V_107 , 0 , sizeof( struct V_101 ) ) ;
memset ( & V_83 -> V_109 , 0 , sizeof( struct V_101 ) ) ;
memset ( & V_83 -> V_96 , 0 , V_35 ) ;
V_83 -> V_109 . V_133 = V_83 -> V_96 ;
F_59 ( & V_83 -> V_100 ) ;
F_17 ( V_129 , & V_83 -> V_121 ) ;
error = F_47 ( V_91 , V_58 , V_63 ) ;
if ( error ) {
F_41 ( V_91 , L_18 , error ) ;
return error ;
}
error = F_45 ( V_91 , V_58 , 0 ) ;
if ( error ) {
F_41 ( V_91 , L_19 , error ) ;
F_46 ( V_91 ) ;
return error ;
}
V_131 = V_58 ;
V_134:
if ( V_132 ++ && F_60 ( V_135 ) ) {
error = - V_136 ;
goto V_137;
}
if ( V_131 != V_58 ) {
error = F_45 ( V_91 , V_58 , V_75 ) ;
if ( error )
goto V_137;
V_131 = V_58 ;
}
F_61 ( 500 ) ;
error = F_47 ( V_91 , V_52 , V_75 | V_66 | V_63 ) ;
if ( error == - V_41 ) {
goto V_134;
} else if ( error ) {
F_41 ( V_91 , L_20 , error ) ;
goto V_137;
}
error = F_45 ( V_91 , V_52 , V_75 | V_66 ) ;
if ( ! error ) {
V_131 = V_52 ;
goto V_138;
} else if ( error != - V_41 ) {
F_41 ( V_91 , L_21 , error ) ;
goto V_137;
}
error = F_45 ( V_91 , V_55 , V_75 | V_66 ) ;
if ( ! error ) {
V_131 = V_55 ;
goto V_138;
} else {
F_41 ( V_91 , L_22 , error ) ;
goto V_137;
}
V_138:
F_33 ( V_83 , & V_93 , V_94 ) ;
if ( V_93 == 0xFFFFFFFF ) {
F_41 ( V_91 , L_23 ) ;
error = - V_139 ;
goto V_137;
}
if ( V_131 == V_52 ) {
F_50 ( & V_83 -> V_119 ) ;
F_30 ( V_129 , & V_83 -> V_121 ) ;
F_17 ( V_120 , & V_83 -> V_121 ) ;
F_17 ( V_122 , & V_83 -> V_121 ) ;
F_51 ( & V_83 -> V_119 ) ;
F_52 ( V_91 , L_24 , V_93 ) ;
return 0 ;
}
error = F_47 ( V_91 , V_58 , V_75 ) ;
if ( error )
goto V_137;
if ( ! F_37 ( V_94 ) ) {
F_52 ( V_91 , L_25 ) ;
goto V_134;
}
F_50 ( & V_83 -> V_119 ) ;
V_114 = V_83 -> V_123 ;
V_115 = V_83 -> V_124 ;
V_130 = V_83 -> V_140 ;
if ( V_93 < V_130 ) {
F_52 ( V_91 , L_26
L_27 , V_114 , V_115 , V_130 ,
V_93 , V_83 -> V_121 ) ;
F_51 ( & V_83 -> V_119 ) ;
goto V_134;
}
if ( V_93 != V_115 ) {
F_52 ( V_91 , L_28
L_27 , V_114 , V_115 , V_130 ,
V_93 , V_83 -> V_121 ) ;
F_51 ( & V_83 -> V_119 ) ;
goto V_134;
}
if ( V_114 == V_115 ) {
F_52 ( V_91 , L_29
L_27 , V_114 , V_115 , V_130 ,
V_93 , V_83 -> V_121 ) ;
F_51 ( & V_83 -> V_119 ) ;
goto V_134;
}
F_30 ( V_129 , & V_83 -> V_121 ) ;
F_17 ( V_120 , & V_83 -> V_121 ) ;
memset ( V_83 -> V_128 , 0 , V_83 -> V_125 * sizeof( T_5 ) ) ;
memset ( V_83 -> V_126 , 0 , V_83 -> V_125 * sizeof( T_5 ) ) ;
F_51 ( & V_83 -> V_119 ) ;
return 0 ;
V_137:
F_44 ( V_91 ) ;
F_46 ( V_91 ) ;
return error ;
}
static int F_62 ( void * V_141 )
{
F_63 () ;
return 0 ;
}
static int F_64 ( struct V_90 * V_91 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
char V_94 [ V_35 ] ;
T_5 V_115 , V_114 ;
int error ;
V_134:
F_50 ( & V_83 -> V_119 ) ;
V_115 = V_83 -> V_124 ;
V_114 = V_83 -> V_123 ;
if ( F_4 ( V_129 , & V_83 -> V_121 ) ||
! F_4 ( V_120 , & V_83 -> V_121 ) ||
! F_4 ( V_122 , & V_83 -> V_121 ) ) {
F_41 ( V_91 , L_30 ,
V_115 , V_114 , V_83 -> V_121 ) ;
F_51 ( & V_83 -> V_119 ) ;
F_46 ( V_91 ) ;
return - 1 ;
}
if ( V_115 == V_114 ) {
F_51 ( & V_83 -> V_119 ) ;
F_52 ( V_91 , L_31 , V_115 ) ;
F_65 ( & V_83 -> V_121 , V_142 ,
F_62 , V_143 ) ;
goto V_134;
}
F_30 ( V_122 , & V_83 -> V_121 ) ;
F_17 ( V_144 , & V_83 -> V_121 ) ;
memset ( V_83 -> V_128 , 0 , V_83 -> V_125 * sizeof( T_5 ) ) ;
memset ( V_83 -> V_126 , 0 , V_83 -> V_125 * sizeof( T_5 ) ) ;
F_51 ( & V_83 -> V_119 ) ;
memset ( V_94 , 0 , sizeof( V_94 ) ) ;
F_35 ( V_83 , V_115 , V_94 ) ;
error = F_45 ( V_91 , V_55 , V_75 ) ;
if ( error )
F_41 ( V_91 , L_32 , error ) ;
error = F_47 ( V_91 , V_58 , V_75 | V_63 ) ;
if ( error )
F_41 ( V_91 , L_33 , error ) ;
return error ;
}
static int F_66 ( struct V_90 * V_91 , struct V_145 * V_146 ,
int V_147 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
T_5 * V_148 = NULL ;
T_5 * V_149 = NULL ;
T_5 V_150 , V_151 ;
int V_98 , V_152 ;
V_152 = 0 ;
for ( V_98 = 0 ; V_98 < V_147 ; V_98 ++ ) {
if ( V_152 < V_146 [ V_98 ] . V_153 - 1 )
V_152 = V_146 [ V_98 ] . V_153 - 1 ;
}
V_150 = V_83 -> V_125 ;
if ( V_150 >= V_152 + 1 )
return 0 ;
V_151 = V_150 + V_154 ;
V_148 = F_67 ( V_151 * sizeof( T_5 ) , V_155 ) ;
V_149 = F_67 ( V_151 * sizeof( T_5 ) , V_155 ) ;
if ( ! V_148 || ! V_149 ) {
F_68 ( V_148 ) ;
F_68 ( V_149 ) ;
return - V_156 ;
}
F_50 ( & V_83 -> V_119 ) ;
memcpy ( V_148 , V_83 -> V_128 , V_150 * sizeof( T_5 ) ) ;
memcpy ( V_149 , V_83 -> V_126 , V_150 * sizeof( T_5 ) ) ;
F_68 ( V_83 -> V_128 ) ;
F_68 ( V_83 -> V_126 ) ;
V_83 -> V_128 = V_148 ;
V_83 -> V_126 = V_149 ;
V_83 -> V_125 = V_151 ;
F_51 ( & V_83 -> V_119 ) ;
return 0 ;
}
static void F_69 ( struct V_82 * V_83 )
{
F_68 ( V_83 -> V_128 ) ;
F_68 ( V_83 -> V_126 ) ;
V_83 -> V_128 = NULL ;
V_83 -> V_126 = NULL ;
V_83 -> V_125 = 0 ;
}
static void F_70 ( void * V_27 )
{
struct V_90 * V_91 = V_27 ;
struct V_82 * V_83 = & V_91 -> V_84 ;
F_50 ( & V_83 -> V_119 ) ;
V_83 -> V_123 = V_83 -> V_124 ;
F_17 ( V_142 , & V_83 -> V_121 ) ;
if ( ! F_4 ( V_120 , & V_83 -> V_121 ) ||
F_4 ( V_122 , & V_83 -> V_121 ) ) {
F_51 ( & V_83 -> V_119 ) ;
return;
}
F_17 ( V_129 , & V_83 -> V_121 ) ;
F_51 ( & V_83 -> V_119 ) ;
}
static void F_71 ( void * V_27 , struct V_145 * V_153 )
{
struct V_90 * V_91 = V_27 ;
struct V_82 * V_83 = & V_91 -> V_84 ;
int V_157 = V_153 -> V_153 - 1 ;
F_50 ( & V_83 -> V_119 ) ;
if ( V_83 -> V_125 < V_157 + 1 ) {
F_41 ( V_91 , L_34 ,
V_157 , V_83 -> V_123 , V_83 -> V_125 ) ;
F_51 ( & V_83 -> V_119 ) ;
return;
}
if ( V_83 -> V_128 [ V_157 ] ) {
F_52 ( V_91 , L_35 ,
V_157 , V_83 -> V_123 , V_83 -> V_128 [ V_157 ] ) ;
}
V_83 -> V_128 [ V_157 ] = V_83 -> V_123 ;
F_51 ( & V_83 -> V_119 ) ;
}
static void F_72 ( void * V_27 , struct V_145 * V_146 , int V_147 ,
int V_158 , T_5 V_159 )
{
struct V_90 * V_91 = V_27 ;
struct V_82 * V_83 = & V_91 -> V_84 ;
F_66 ( V_91 , V_146 , V_147 ) ;
F_50 ( & V_83 -> V_119 ) ;
V_83 -> V_124 = V_159 ;
if ( ! V_83 -> V_140 ) {
V_83 -> V_140 = V_159 ;
V_83 -> V_160 = V_158 - 1 ;
}
if ( ! F_4 ( V_161 , & V_83 -> V_121 ) )
F_73 ( V_162 , & V_91 -> V_113 , 0 ) ;
F_30 ( V_142 , & V_83 -> V_121 ) ;
F_74 () ;
F_75 ( & V_83 -> V_121 , V_142 ) ;
F_51 ( & V_83 -> V_119 ) ;
}
static void F_76 ( struct V_90 * V_91 , unsigned int V_157 ,
unsigned int V_149 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
if ( F_4 ( V_163 , & V_83 -> V_121 ) )
return;
if ( V_157 == V_83 -> V_160 )
return;
F_50 ( & V_83 -> V_119 ) ;
if ( F_4 ( V_122 , & V_83 -> V_121 ) ) {
F_51 ( & V_83 -> V_119 ) ;
return;
}
if ( V_83 -> V_125 < V_157 + 1 ) {
F_41 ( V_91 , L_36 ,
V_157 , V_83 -> V_125 ) ;
F_51 ( & V_83 -> V_119 ) ;
return;
}
F_52 ( V_91 , L_37 , V_157 ,
V_149 == V_164 ? L_38 : L_39 ) ;
V_83 -> V_126 [ V_157 ] = V_149 ;
if ( ! F_4 ( V_161 , & V_83 -> V_121 ) )
F_73 ( V_162 , & V_91 -> V_113 ,
V_149 == V_164 ? V_165 : 0 ) ;
F_51 ( & V_83 -> V_119 ) ;
}
static int F_77 ( struct V_90 * V_91 , const char * V_166 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
char V_167 [ V_168 ] ;
const char * V_169 ;
T_5 V_81 ;
int error , V_170 ;
F_78 ( & V_91 -> V_113 , F_48 ) ;
F_79 ( & V_83 -> V_119 ) ;
V_83 -> V_121 = 0 ;
V_83 -> V_140 = 0 ;
V_83 -> V_124 = 0 ;
V_83 -> V_123 = 0 ;
V_83 -> V_125 = 0 ;
V_83 -> V_128 = NULL ;
V_83 -> V_126 = NULL ;
error = F_66 ( V_91 , NULL , 0 ) ;
if ( error )
goto V_137;
V_169 = strchr ( V_166 , ':' ) ;
if ( ! V_169 ) {
F_52 ( V_91 , L_40 ) ;
error = - V_139 ;
goto V_171;
}
memset ( V_167 , 0 , sizeof( V_167 ) ) ;
memcpy ( V_167 , V_166 , strlen ( V_166 ) - strlen ( V_169 ) ) ;
V_169 ++ ;
V_81 = V_172 | V_173 ;
error = F_80 ( V_169 , V_167 , V_81 , V_35 ,
& V_174 , V_91 , & V_170 ,
& V_83 -> V_89 ) ;
if ( error ) {
F_41 ( V_91 , L_41 , error ) ;
goto V_171;
}
if ( V_170 < 0 ) {
F_52 ( V_91 , L_42 ) ;
F_69 ( V_83 ) ;
F_17 ( V_163 , & V_83 -> V_121 ) ;
return 0 ;
}
if ( ! F_4 ( V_175 , & V_91 -> V_176 ) ) {
F_41 ( V_91 , L_43 ) ;
error = - V_139 ;
goto V_177;
}
error = F_58 ( V_91 ) ;
if ( error ) {
F_41 ( V_91 , L_44 , error ) ;
goto V_177;
}
V_83 -> V_178 = ! ! F_4 ( V_122 , & V_83 -> V_121 ) ;
F_30 ( V_175 , & V_91 -> V_176 ) ;
F_74 () ;
F_75 ( & V_91 -> V_176 , V_175 ) ;
return 0 ;
V_177:
F_81 ( V_83 -> V_89 , 2 ) ;
V_171:
F_69 ( V_83 ) ;
V_137:
return error ;
}
static void F_82 ( struct V_90 * V_91 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
int error ;
if ( F_4 ( V_163 , & V_83 -> V_121 ) )
return;
error = F_64 ( V_91 ) ;
if ( error )
F_41 ( V_91 , L_45 , error ) ;
}
static void F_83 ( struct V_90 * V_91 )
{
struct V_82 * V_83 = & V_91 -> V_84 ;
if ( F_4 ( V_163 , & V_83 -> V_121 ) )
goto V_179;
F_50 ( & V_83 -> V_119 ) ;
F_17 ( V_161 , & V_83 -> V_121 ) ;
F_51 ( & V_83 -> V_119 ) ;
F_84 ( & V_91 -> V_113 ) ;
V_179:
if ( V_83 -> V_89 ) {
F_81 ( V_83 -> V_89 , 2 ) ;
V_83 -> V_89 = NULL ;
}
F_69 ( V_83 ) ;
}

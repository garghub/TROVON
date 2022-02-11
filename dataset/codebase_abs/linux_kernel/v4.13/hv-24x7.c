static bool F_1 ( unsigned V_1 )
{
switch ( V_1 ) {
#define F_2 ( T_1 , T_2 , T_3 , T_4 ) \
case HV_PERF_DOMAIN_##n: \
#include "hv-24x7-domains.h"
#undef F_2
return true ;
default:
return false ;
}
}
static bool F_3 ( unsigned V_1 )
{
switch ( V_1 ) {
#define F_2 ( T_1 , T_2 , T_3 , T_4 ) \
case HV_PERF_DOMAIN_##n: \
return c;
#include "hv-24x7-domains.h"
#undef F_2
default:
return false ;
}
}
static bool F_4 ( unsigned int V_1 )
{
return V_2 &&
( V_1 == V_3 ||
( V_1 >= V_4 &&
V_1 <= V_5 ) ) ;
}
static const char * F_5 ( unsigned V_1 )
{
if ( ! F_1 ( V_1 ) )
return NULL ;
switch ( V_1 ) {
case V_6 : return L_1 ;
case V_3 : return L_2 ;
case V_4 : return L_3 ;
case V_7 : return L_4 ;
case V_8 : return L_5 ;
case V_5 : return L_6 ;
}
F_6 ( V_1 ) ;
return NULL ;
}
static bool F_7 ( unsigned V_1 )
{
if ( V_9 == 1 )
return F_3 ( V_1 ) ;
else
return F_1 ( V_1 ) ;
}
static unsigned int F_8 ( int V_9 )
{
return ( V_10 - sizeof( struct V_11 ) )
/ F_9 ( V_9 ) ;
}
static char * F_10 ( struct V_12 * V_13 , int * V_14 )
{
* V_14 = F_11 ( V_13 -> V_15 ) - 2 ;
return ( char * ) V_13 -> V_16 ;
}
static char * F_12 ( struct V_12 * V_13 , int * V_14 )
{
unsigned V_17 = F_11 ( V_13 -> V_15 ) ;
T_5 * V_18 = ( T_5 * ) ( V_13 -> V_16 + V_17 - 2 ) ;
* V_14 = F_11 ( * V_18 ) - 2 ;
return ( char * ) V_13 -> V_16 + V_17 ;
}
static char * F_13 ( struct V_12 * V_13 , int * V_14 )
{
unsigned V_17 = F_11 ( V_13 -> V_15 ) ;
T_5 * V_19 = ( T_5 * ) ( V_13 -> V_16 + V_17 - 2 ) ;
unsigned V_18 = F_11 ( * V_19 ) ;
T_5 * V_20 = ( T_5 * ) ( V_13 -> V_16 + V_17 + V_18 - 2 ) ;
* V_14 = F_11 ( * V_20 ) - 2 ;
return ( char * ) V_13 -> V_16 + V_17 + V_18 ;
}
static bool F_14 ( struct V_12 * V_13 ,
void * V_21 )
{
void * V_22 = V_13 ;
return ( V_22 + F_15 ( struct V_12 , V_16 ) ) < V_21 ;
}
static void * F_16 ( struct V_12 * V_13 , void * V_21 )
{
void * V_22 = V_13 ;
T_5 * V_23 , * V_24 ;
unsigned V_25 , V_26 ;
unsigned V_17 = F_11 ( V_13 -> V_15 ) ;
if ( V_17 < 2 ) {
F_17 ( L_7 , V_27 , V_17 ) ;
return NULL ;
}
if ( V_22 + V_17 > V_21 ) {
F_17 ( L_8 ,
V_27 , V_22 , V_17 , V_21 ) ;
return NULL ;
}
V_23 = ( T_5 * ) ( V_13 -> V_16 + V_17 - 2 ) ;
if ( ! F_18 ( ( V_28 ) V_23 , 2 ) )
F_19 ( L_9 , V_23 ) ;
V_25 = F_11 ( * V_23 ) ;
if ( V_25 < 2 ) {
F_17 ( L_10 , V_27 , V_25 ) ;
return NULL ;
}
if ( V_22 + V_17 + V_25 > V_21 ) {
F_17 ( L_11 ,
V_27 , V_22 , V_17 , V_25 , V_22 + V_17 + V_25 , V_21 ) ;
return NULL ;
}
V_24 = ( T_5 * ) ( V_13 -> V_16 + V_17 + V_25 - 2 ) ;
if ( ! F_18 ( ( V_28 ) V_24 , 2 ) )
F_19 ( L_12 , V_24 ) ;
V_26 = F_11 ( * V_24 ) ;
if ( V_26 < 2 ) {
F_17 ( L_13 ,
V_27 , V_26 ) ;
return NULL ;
}
if ( V_22 + V_17 + V_25 + V_26 > V_21 ) {
F_17 ( L_14 ,
V_27 , V_22 , V_17 , V_25 , V_26 , V_21 ) ;
return NULL ;
}
return V_22 + V_17 + V_25 + V_26 ;
}
static long F_20 ( unsigned long V_29 ,
unsigned long V_30 , unsigned long V_31 )
{
F_21 ( L_15 ,
V_29 , V_30 , V_31 ) ;
F_22 ( ! F_18 ( V_29 , 4096 ) ) ;
return F_23 ( V_32 ,
V_29 , V_30 , V_31 ) ;
}
static long F_24 ( char V_33 [] , T_6 V_30 , T_7 V_31 )
{
return F_20 ( F_25 ( V_33 ) ,
V_30 , V_31 ) ;
}
static char * F_26 ( struct V_12 * V_34 , unsigned V_1 )
{
const char * V_35 ;
const char * V_36 ;
const char * V_37 ;
char V_38 [ 8 ] ;
switch ( V_1 ) {
case V_6 :
snprintf ( V_38 , sizeof( V_38 ) , L_16 , V_1 ) ;
V_37 = V_38 ;
V_36 = L_17 ;
V_35 = L_18 ;
break;
case V_3 :
V_37 = L_19 ;
V_36 = L_17 ;
V_35 = L_20 ;
break;
default:
V_37 = L_19 ;
V_36 = L_19 ;
V_35 = L_21 ;
}
return F_27 ( V_39 ,
L_22 ,
V_37 ,
F_11 ( V_34 -> V_40 ) +
F_11 ( V_34 -> V_41 ) ,
V_35 ,
V_36 ) ;
}
static char * F_28 ( char * V_42 , int V_43 , T_8 V_44 )
{
return F_27 ( V_44 , L_23 , V_43 , V_42 ) ;
}
static T_9 F_29 ( struct V_45 * V_46 ,
struct V_47 * V_48 , char * V_38 )
{
struct V_49 * V_50 ;
V_50 = F_30 ( V_48 , struct V_49 , V_48 ) ;
return sprintf ( V_38 , L_24 , ( char * ) V_50 -> V_51 ) ;
}
static struct V_52 * F_31 ( char * V_53 , char * V_54 )
{
struct V_49 * V_48 = F_32 ( sizeof( * V_48 ) , V_39 ) ;
if ( ! V_48 )
return NULL ;
F_33 ( & V_48 -> V_48 . V_48 ) ;
V_48 -> V_51 = V_54 ;
V_48 -> V_48 . V_48 . V_53 = V_53 ;
V_48 -> V_48 . V_48 . V_55 = 0444 ;
V_48 -> V_48 . V_56 = F_29 ;
return & V_48 -> V_48 . V_48 ;
}
static struct V_52 * F_34 ( char * V_53 , int V_57 ,
int V_58 ,
char * V_54 , T_10 V_59 )
{
char * T_1 ;
char * V_60 = F_28 ( V_54 , V_59 , V_39 ) ;
struct V_52 * V_61 ;
if ( ! V_60 )
return NULL ;
if ( ! V_58 )
T_1 = F_27 ( V_39 , L_23 , V_57 , V_53 ) ;
else
T_1 = F_27 ( V_39 , L_25 , V_57 , V_53 ,
V_58 ) ;
if ( ! T_1 )
goto V_62;
V_61 = F_31 ( T_1 , V_60 ) ;
if ( ! V_61 )
goto V_63;
return V_61 ;
V_63:
F_35 ( T_1 ) ;
V_62:
F_35 ( V_60 ) ;
return NULL ;
}
static struct V_52 * F_36 ( unsigned V_64 ,
struct V_12 * V_34 ,
unsigned V_1 ,
int V_65 )
{
int V_15 ;
char * V_66 , * V_67 , * V_68 ;
struct V_52 * V_48 ;
if ( ! F_1 ( V_1 ) ) {
F_19 ( L_26 ,
V_64 , V_1 ) ;
return NULL ;
}
V_68 = F_26 ( V_34 , V_1 ) ;
if ( ! V_68 )
return NULL ;
V_66 = F_10 ( V_34 , & V_15 ) ;
if ( ! V_65 )
V_67 = F_27 ( V_39 , L_23 ,
( int ) V_15 , V_66 ) ;
else
V_67 = F_27 ( V_39 , L_25 ,
( int ) V_15 , V_66 , V_65 ) ;
if ( ! V_67 )
goto V_69;
V_48 = F_31 ( V_67 , V_68 ) ;
if ( ! V_48 )
goto V_70;
return V_48 ;
V_70:
F_35 ( V_67 ) ;
V_69:
F_35 ( V_68 ) ;
return NULL ;
}
static struct V_52 * F_37 ( struct V_12 * V_34 ,
int V_65 )
{
int V_17 , V_25 ;
char * V_53 = F_10 ( V_34 , & V_17 ) ;
char * V_71 = F_12 ( V_34 , & V_25 ) ;
if ( ! V_25 )
return NULL ;
return F_34 ( V_53 , V_17 , V_65 , V_71 , V_25 ) ;
}
static struct V_52 *
F_38 ( struct V_12 * V_34 , int V_65 )
{
int V_17 , V_25 ;
char * V_53 = F_10 ( V_34 , & V_17 ) ;
char * V_71 = F_13 ( V_34 , & V_25 ) ;
if ( ! V_25 )
return NULL ;
return F_34 ( V_53 , V_17 , V_65 , V_71 , V_25 ) ;
}
static int F_39 ( unsigned V_64 , struct V_52 * * V_72 ,
struct V_12 * V_34 , int V_65 )
{
* V_72 = F_36 ( V_64 , V_34 , V_34 -> V_1 , V_65 ) ;
if ( ! * V_72 )
return - 1 ;
return 0 ;
}
static int F_40 ( const void * V_73 , T_10 V_74 , const void * V_75 , T_10 V_76 )
{
if ( V_74 < V_76 )
return 1 ;
if ( V_76 > V_74 )
return - 1 ;
return memcmp ( V_73 , V_75 , V_74 ) ;
}
static int F_41 ( const void * V_77 , T_10 V_74 , unsigned V_73 , const void * V_78 ,
T_10 V_76 , unsigned V_75 )
{
int V_79 = F_40 ( V_77 , V_74 , V_78 , V_76 ) ;
if ( V_79 )
return V_79 ;
if ( V_73 > V_75 )
return 1 ;
if ( V_75 > V_73 )
return - 1 ;
return 0 ;
}
static int F_42 ( struct V_80 * V_81 , const char * V_53 , int V_17 ,
unsigned V_1 )
{
struct V_82 * * V_83 = & ( V_81 -> V_82 ) , * V_84 = NULL ;
struct V_85 * V_86 ;
while ( * V_83 ) {
struct V_85 * V_87 ;
int V_88 ;
V_87 = F_30 ( * V_83 , struct V_85 , V_89 ) ;
V_88 = F_41 ( V_53 , V_17 , V_1 , V_87 -> V_53 , V_87 -> V_17 ,
V_87 -> V_1 ) ;
V_84 = * V_83 ;
if ( V_88 < 0 )
V_83 = & ( ( * V_83 ) -> V_90 ) ;
else if ( V_88 > 0 )
V_83 = & ( ( * V_83 ) -> V_91 ) ;
else {
V_87 -> V_92 ++ ;
F_43 ( L_27 , V_17 ,
V_53 , V_87 -> V_92 ) ;
return V_87 -> V_92 ;
}
}
V_86 = F_44 ( sizeof( * V_86 ) , V_39 ) ;
if ( ! V_86 )
return - V_93 ;
* V_86 = (struct V_85 ) {
. V_53 = V_53 ,
. V_17 = V_17 ,
. V_92 = 0 ,
. V_1 = V_1 ,
} ;
F_45 ( & V_86 -> V_89 , V_84 , V_83 ) ;
F_46 ( & V_86 -> V_89 , V_81 ) ;
return 0 ;
}
static void F_47 ( struct V_80 * V_81 )
{
struct V_85 * V_94 , * T_1 ;
F_48 (pos, n, root, node)
F_35 ( V_94 ) ;
}
static T_9 F_49 ( struct V_12 * V_34 ,
T_10 V_95 ,
T_10 V_96 ,
T_10 V_97 ,
T_10 V_98 , void * V_21 )
{
T_9 V_99 ;
void * V_100 , * V_101 ;
if ( V_98 >= V_96 )
return - 1 ;
if ( V_95 >= V_97 ) {
F_21 ( L_28 ,
V_96 - V_98 ) ;
return - 1 ;
}
if ( ! F_14 ( V_34 , V_21 ) ) {
F_19 ( L_29 ,
V_95 ) ;
return - 1 ;
}
V_99 = F_11 ( V_34 -> V_102 ) ;
if ( V_99 % 16 )
F_43 ( L_30 ,
V_95 , V_99 , V_34 ) ;
V_100 = ( V_103 * ) V_34 + V_99 ;
if ( V_100 > V_21 ) {
F_19 ( L_31 ,
V_95 , V_99 , V_100 , V_21 ,
V_98 ) ;
return - 1 ;
}
V_101 = F_16 ( V_34 , V_21 ) ;
if ( ! V_101 ) {
F_19 ( L_32 ,
V_95 , V_96 , V_34 , V_21 ,
V_98 ) ;
return - 1 ;
}
if ( V_101 > V_100 ) {
F_19 ( L_33 ,
V_95 , V_34 , V_100 , V_98 , V_101 ) ;
return - 1 ;
}
return V_99 ;
}
static int F_50 ( struct V_52 * * * V_104 ,
struct V_52 * * * V_105 ,
struct V_52 * * * V_106 )
{
long V_107 ;
T_10 V_108 , V_109 , V_97 ,
V_110 , V_111 ,
V_96 , V_112 , V_95 , V_113 , V_114 ,
V_115 , V_116 , V_117 , V_118 ;
T_9 V_92 , V_99 ;
T_11 V_119 ;
struct V_52 * * V_120 , * * V_121 , * * V_122 ;
struct V_123 * V_124 =
F_51 ( V_125 , V_39 ) ;
void * V_33 = V_124 ;
void * V_126 , * V_21 ;
struct V_12 * V_34 ;
struct V_80 V_127 = V_128 ;
int V_129 = 0 ;
if ( ! V_33 ) {
V_129 = - V_93 ;
goto V_130;
}
V_107 = F_24 ( V_33 , 0 , 0 ) ;
if ( V_107 ) {
V_129 = - V_131 ;
goto V_132;
}
V_119 = F_52 ( V_124 -> V_30 ) ;
V_109 = F_53 ( V_124 -> V_102 ) ;
if ( V_133 < V_109 ) {
F_54 ( L_34 , V_109 ) ;
V_129 = - V_131 ;
goto V_132;
}
V_108 = V_109 * 4096 ;
V_97 = F_11 ( V_124 -> V_97 ) ;
V_111 = F_11 ( V_124 -> V_111 ) ;
V_110 = F_11 ( V_124 -> V_110 ) ;
F_21 ( L_35 ,
V_119 , V_108 ,
V_97 , V_111 , V_110 ) ;
if ( ( V_133 < V_110 )
|| ( V_133 < V_111 )
|| ( V_133 - V_111 < V_110 ) ) {
F_54 ( L_36 ,
V_111 , V_110 ) ;
V_129 = - V_131 ;
goto V_132;
}
if ( ( V_111 + V_110 ) > V_109 ) {
F_54 ( L_37 ,
V_111 ,
V_111 + V_110 ,
V_109 ) ;
V_129 = - V_131 ;
goto V_132;
}
if ( V_134 - 1 < V_97 ) {
F_54 ( L_38 , V_97 ) ;
V_129 = - V_131 ;
goto V_132;
}
V_96 = V_110 * 4096 ;
V_126 = F_55 ( V_96 ) ;
if ( ! V_126 ) {
F_54 ( L_39 ) ;
V_129 = - V_93 ;
goto V_132;
}
V_21 = V_126 + V_96 ;
F_56 ( V_135 % 4096 ) ;
for ( V_114 = 0 ; V_114 < V_110 ; V_114 ++ ) {
V_107 = F_20 (
F_57 ( V_126 + V_114 * 4096 ) ,
V_119 ,
V_114 + V_111 ) ;
if ( V_107 ) {
F_54 ( L_40 ,
V_114 + V_111 , V_107 ) ;
V_129 = - V_131 ;
goto V_136;
}
}
for ( V_112 = 0 , V_34 = V_126 , V_95 = 0 , V_115 = 0 ;
;
V_95 ++ , V_34 = ( void * ) V_34 + V_99 ) {
T_10 V_98 = ( void * ) V_34 - ( void * ) V_126 ;
char * V_53 ;
int V_17 ;
V_99 = F_49 ( V_34 , V_95 ,
V_96 ,
V_97 ,
V_98 , V_21 ) ;
if ( V_99 < 0 )
break;
V_53 = F_10 ( V_34 , & V_17 ) ;
if ( V_34 -> V_137 == 0 ) {
F_21 ( L_41 ,
V_95 , V_17 , V_53 ) ;
V_112 ++ ;
continue;
}
if ( ! F_7 ( V_34 -> V_1 ) ) {
F_43 ( L_42 ,
V_95 , V_17 , V_53 , V_34 -> V_1 ) ;
V_112 ++ ;
continue;
}
V_115 ++ ;
}
V_116 = V_95 ;
if ( V_116 != V_97 )
F_19 ( L_43 ,
V_116 , V_97 , V_112 ) ;
V_120 = F_58 ( V_115 + 1 , sizeof( * V_120 ) , V_39 ) ;
if ( ! V_120 ) {
V_129 = - V_93 ;
goto V_136;
}
V_121 = F_58 ( V_95 + 1 , sizeof( * V_121 ) ,
V_39 ) ;
if ( ! V_121 ) {
V_129 = - V_93 ;
goto V_138;
}
V_122 = F_58 ( V_95 + 1 ,
sizeof( * V_122 ) , V_39 ) ;
if ( ! V_122 ) {
V_129 = - V_93 ;
goto V_139;
}
for ( V_112 = 0 , V_113 = 0 , V_117 = 0 , V_118 = 0 ,
V_34 = V_126 , V_95 = 0 ;
V_95 < V_116 ;
V_95 ++ , V_99 = F_11 ( V_34 -> V_102 ) ,
V_34 = ( void * ) V_34 + V_99 ) {
char * V_53 ;
int V_17 ;
int V_65 ;
if ( V_34 -> V_137 == 0 )
continue;
if ( ! F_7 ( V_34 -> V_1 ) )
continue;
V_53 = F_10 ( V_34 , & V_17 ) ;
V_65 = F_42 ( & V_127 , V_53 , V_17 , V_34 -> V_1 ) ;
V_92 = F_39 ( V_95 , V_120 + V_113 ,
V_34 , V_65 ) ;
if ( V_92 < 0 ) {
F_19 ( L_44 ,
V_95 , V_17 , V_53 ) ;
V_112 ++ ;
} else {
V_113 ++ ;
V_121 [ V_117 ] = F_37 ( V_34 , V_65 ) ;
if ( V_121 [ V_117 ] )
V_117 ++ ;
V_122 [ V_118 ] =
F_38 ( V_34 , V_65 ) ;
if ( V_122 [ V_118 ] )
V_118 ++ ;
}
}
F_43 ( L_45 ,
V_95 , V_113 , V_112 , V_117 ) ;
V_120 [ V_113 ] = NULL ;
V_121 [ V_117 ] = NULL ;
V_122 [ V_118 ] = NULL ;
F_47 ( & V_127 ) ;
F_59 ( V_126 ) ;
F_60 ( V_125 , V_33 ) ;
* V_104 = V_120 ;
* V_105 = V_121 ;
* V_106 = V_122 ;
return 0 ;
V_139:
F_35 ( V_121 ) ;
V_138:
F_35 ( V_120 ) ;
V_136:
F_59 ( V_126 ) ;
V_132:
F_60 ( V_125 , V_33 ) ;
V_130:
* V_104 = NULL ;
* V_105 = NULL ;
* V_106 = NULL ;
return V_129 ;
}
static T_9 F_61 ( struct V_140 * V_141 , struct V_142 * V_143 ,
struct V_144 * V_145 , char * V_38 ,
T_12 V_98 , T_10 V_146 )
{
long V_107 ;
T_9 V_129 = 0 ;
T_10 V_108 = 0 , V_109 = 0 ;
T_12 V_147 = 0 ;
T_12 V_148 ;
T_10 V_149 ;
T_11 V_119 = 0 ;
void * V_33 = F_51 ( V_125 , V_150 ) ;
struct V_123 * V_124 = V_33 ;
if ( ! V_33 )
return - V_93 ;
V_107 = F_24 ( V_33 , 0 , 0 ) ;
if ( V_107 ) {
V_129 = - V_131 ;
goto V_132;
}
V_119 = F_52 ( V_124 -> V_30 ) ;
V_109 = F_53 ( V_124 -> V_102 ) ;
V_108 = V_109 * 4096 ;
V_147 = V_98 / 4096 ;
V_148 = V_98 % 4096 ;
if ( V_147 >= V_109 )
goto V_132;
if ( V_147 != 0 ) {
V_107 = F_24 ( V_33 , V_119 ,
V_147 ) ;
if ( V_107 ) {
V_129 = - V_131 ;
goto V_132;
}
}
V_149 = 4096 - V_148 ;
if ( V_149 > V_146 )
V_149 = V_146 ;
memcpy ( V_38 , V_33 + V_148 , V_149 ) ;
V_129 = V_149 ;
V_132:
if ( V_107 )
F_54 ( L_46
L_47 ,
V_119 , V_147 , V_107 ) ;
F_60 ( V_125 , V_33 ) ;
F_21 ( L_48
L_49 , V_98 , V_147 ,
V_146 , V_108 , V_109 , V_129 ) ;
return V_129 ;
}
static T_9 F_62 ( struct V_45 * V_46 , struct V_47 * V_48 ,
char * V_33 )
{
int V_50 , T_1 , V_146 = 0 ;
const char * V_54 ;
for ( V_50 = 0 ; V_50 < V_151 ; V_50 ++ ) {
V_54 = F_5 ( V_50 ) ;
if ( ! V_54 )
continue;
T_1 = sprintf ( V_33 , L_50 , V_50 , V_54 ) ;
if ( T_1 < 0 )
break;
V_146 += T_1 ;
V_33 += T_1 ;
}
return V_146 ;
}
static void F_63 ( struct V_11 * V_152 ,
struct V_153 * V_154 )
{
memset ( V_152 , 0 , V_10 ) ;
memset ( V_154 , 0 , V_10 ) ;
V_152 -> V_9 = V_9 ;
}
static int F_64 ( struct V_11 * V_152 ,
struct V_153 * V_154 )
{
long V_129 ;
V_129 = F_23 ( V_155 ,
F_25 ( V_152 ) , V_10 ,
F_25 ( V_154 ) , V_10 ) ;
if ( V_129 ) {
struct V_156 * V_157 ;
V_157 = V_152 -> V_158 ;
F_65 ( L_51 ,
V_157 -> V_159 , V_157 -> V_160 ,
V_157 -> V_161 , V_157 -> V_162 ,
V_129 , V_129 , V_154 -> V_163 ,
V_154 -> V_164 ) ;
return - V_131 ;
}
return 0 ;
}
static int F_66 ( struct V_165 * V_34 ,
struct V_11 * V_152 )
{
T_13 V_166 ;
int V_114 ;
T_10 V_167 ;
struct V_156 * V_157 ;
if ( V_152 -> V_168 >=
F_8 ( V_152 -> V_9 ) ) {
F_21 ( L_52 ,
V_152 -> V_168 ) ;
return - V_169 ;
}
switch ( F_67 ( V_34 ) ) {
case V_6 :
V_166 = F_68 ( V_34 ) ;
break;
case V_3 :
V_166 = F_69 ( V_34 ) ;
break;
default:
V_166 = F_70 ( V_34 ) ;
}
V_167 = F_9 ( V_152 -> V_9 ) ;
V_114 = V_152 -> V_168 ++ ;
V_157 = ( void * ) V_152 -> V_158 + V_114 * V_167 ;
V_157 -> V_159 = F_67 ( V_34 ) ;
V_157 -> V_170 = F_71 ( 8 ) ;
V_157 -> V_160 = F_72 ( F_73 ( V_34 ) ) ;
V_157 -> V_162 = F_71 ( F_74 ( V_34 ) ) ;
V_157 -> V_171 = F_71 ( 1 ) ;
V_157 -> V_161 = F_71 ( V_166 ) ;
V_157 -> V_172 = F_71 ( 1 ) ;
if ( V_152 -> V_9 > 1 ) {
if ( F_4 ( V_157 -> V_159 ) )
V_157 -> V_173 = - 1 ;
else if ( V_157 -> V_159 != V_6 ) {
V_157 -> V_174 = V_166 % 2 ;
V_157 -> V_173 = 1 ;
}
}
return 0 ;
}
static int F_75 ( struct V_165 * V_34 ,
struct V_153 * V_175 ,
struct V_176 * V_177 , T_6 * V_178 ,
struct V_176 * * V_179 )
{
T_13 V_180 = F_11 ( V_177 -> V_181 ) ;
T_13 V_170 = F_11 ( V_177 -> V_182 ) ;
unsigned int V_160 ;
void * V_183 ;
int V_114 ;
T_6 V_146 ;
if ( ! V_180 ) {
F_17 ( L_53 ,
V_177 -> V_184 ) ;
if ( V_179 )
* V_179 = (struct V_176 * ) V_177 -> V_185 ;
return - V_186 ;
}
if ( V_180 != 1 &&
! F_4 ( F_67 ( V_34 ) ) ) {
F_54 ( L_54 ,
V_177 -> V_184 , V_180 ) ;
return - V_131 ;
}
if ( V_170 != sizeof( T_6 ) ) {
F_17 ( L_55 ,
V_177 -> V_184 , V_170 ) ;
return - V_187 ;
}
if ( V_175 -> V_9 == 1 )
V_160 = F_15 ( struct V_188 ,
V_183 ) ;
else
V_160 = F_15 ( struct V_189 ,
V_183 ) ;
for ( V_114 = V_146 = 0 , V_183 = V_177 -> V_185 + V_160 ;
V_114 < V_180 ;
V_114 ++ , V_183 += V_170 + V_160 )
V_146 += F_52 ( * ( ( T_6 * ) V_183 ) ) ;
* V_178 = V_146 ;
if ( V_179 )
* V_179 = V_183 - V_160 ;
return 0 ;
}
static int F_76 ( struct V_165 * V_34 , T_6 * V_146 )
{
int V_129 ;
struct V_11 * V_152 ;
struct V_153 * V_154 ;
F_56 ( sizeof( * V_152 ) > 4096 ) ;
F_56 ( sizeof( * V_154 ) > 4096 ) ;
V_152 = ( void * ) F_77 ( V_190 ) ;
V_154 = ( void * ) F_77 ( V_191 ) ;
F_63 ( V_152 , V_154 ) ;
V_129 = F_66 ( V_34 , V_152 ) ;
if ( V_129 )
goto V_192;
V_129 = F_64 ( V_152 , V_154 ) ;
if ( V_129 )
goto V_192;
V_129 = F_75 ( V_34 , V_154 ,
V_154 -> V_193 , V_146 , NULL ) ;
V_192:
F_78 ( V_190 ) ;
F_78 ( V_191 ) ;
return V_129 ;
}
static int F_79 ( struct V_165 * V_34 )
{
struct V_194 V_195 ;
unsigned V_1 ;
unsigned long V_107 ;
T_6 V_92 ;
if ( V_34 -> V_48 . type != V_34 -> V_196 -> type )
return - V_197 ;
if ( F_80 ( V_34 ) ||
F_81 ( V_34 ) ||
F_82 ( V_34 ) ) {
F_21 ( L_56 ,
V_34 -> V_48 . V_198 ,
F_80 ( V_34 ) ,
V_34 -> V_48 . V_199 ,
F_81 ( V_34 ) ,
V_34 -> V_48 . V_200 ,
F_82 ( V_34 ) ) ;
return - V_169 ;
}
if ( V_34 -> V_48 . V_201 ||
V_34 -> V_48 . V_202 ||
V_34 -> V_48 . V_203 ||
V_34 -> V_48 . V_204 ||
V_34 -> V_48 . V_205 ||
V_34 -> V_48 . V_206 )
return - V_169 ;
if ( F_83 ( V_34 ) )
return - V_207 ;
if ( F_73 ( V_34 ) % 8 ) {
F_21 ( L_57 ) ;
return - V_169 ;
}
V_1 = F_67 ( V_34 ) ;
if ( V_1 >= V_151 ) {
F_21 ( L_58 , V_1 ) ;
return - V_169 ;
}
V_107 = F_84 ( & V_195 ) ;
if ( V_107 ) {
F_21 ( L_59 , V_107 ) ;
return - V_131 ;
}
if ( ! V_195 . V_208 && ( F_3 ( V_1 ) ||
( F_74 ( V_34 ) != F_85 () ) ) ) {
F_21 ( L_60 ,
F_3 ( V_1 ) ,
F_74 ( V_34 ) ) ;
return - V_209 ;
}
if ( F_76 ( V_34 , & V_92 ) ) {
F_21 ( L_61 ) ;
return - V_131 ;
}
( void ) F_86 ( & V_34 -> V_210 . V_211 , V_92 ) ;
return 0 ;
}
static T_6 F_87 ( struct V_165 * V_34 )
{
T_6 V_92 ;
if ( F_76 ( V_34 , & V_92 ) )
return 0 ;
return V_92 ;
}
static void F_88 ( struct V_165 * V_34 , T_6 V_212 )
{
T_14 V_213 ;
V_213 = F_86 ( & V_34 -> V_210 . V_211 , V_212 ) ;
F_89 ( V_212 - V_213 , & V_34 -> V_146 ) ;
}
static void F_90 ( struct V_165 * V_34 )
{
T_6 V_212 ;
struct V_11 * V_152 ;
struct V_214 * V_215 ;
int V_216 ;
V_216 = F_91 ( V_217 ) ;
if ( V_216 & V_218 ) {
int V_114 ;
int V_129 ;
if ( F_91 ( V_219 ) )
return;
V_152 = ( void * ) F_77 ( V_190 ) ;
V_129 = F_66 ( V_34 , V_152 ) ;
if ( V_129 ) {
F_92 ( V_219 , V_129 ) ;
} else {
V_114 = V_152 -> V_168 - 1 ;
V_215 = & F_77 ( V_214 ) ;
V_215 -> V_120 [ V_114 ] = V_34 ;
F_78 ( V_215 ) ;
F_93 ( & V_34 -> V_146 , 0 ) ;
}
F_78 ( V_190 ) ;
} else {
V_212 = F_87 ( V_34 ) ;
F_88 ( V_34 , V_212 ) ;
}
}
static void F_94 ( struct V_165 * V_34 , int V_220 )
{
if ( V_220 & V_221 )
F_93 ( & V_34 -> V_210 . V_211 , F_87 ( V_34 ) ) ;
}
static void F_95 ( struct V_165 * V_34 , int V_220 )
{
F_90 ( V_34 ) ;
}
static int F_96 ( struct V_165 * V_34 , int V_220 )
{
if ( V_220 & V_222 )
F_94 ( V_34 , V_220 ) ;
return 0 ;
}
static void F_97 ( struct V_196 * V_196 , unsigned int V_220 )
{
struct V_11 * V_152 ;
struct V_153 * V_154 ;
F_6 ( F_91 ( V_217 ) ) ;
F_92 ( V_217 , V_220 ) ;
if ( V_220 & ~ V_218 )
return;
V_152 = ( void * ) F_77 ( V_190 ) ;
V_154 = ( void * ) F_77 ( V_191 ) ;
F_63 ( V_152 , V_154 ) ;
F_78 ( V_191 ) ;
F_78 ( V_190 ) ;
}
static void F_98 ( void )
{
F_92 ( V_217 , 0 ) ;
F_92 ( V_219 , 0 ) ;
}
static int F_99 ( struct V_196 * V_196 )
{
struct V_11 * V_152 ;
struct V_153 * V_154 ;
struct V_176 * V_177 , * V_223 ;
T_6 V_146 ;
int V_114 , V_129 , V_216 ;
struct V_214 * V_215 ;
V_216 = F_91 ( V_217 ) ;
F_6 ( ! V_216 ) ;
V_129 = 0 ;
if ( V_216 & ~ V_218 )
goto V_192;
V_129 = F_91 ( V_219 ) ;
if ( V_129 )
goto V_192;
V_152 = ( void * ) F_77 ( V_190 ) ;
V_154 = ( void * ) F_77 ( V_191 ) ;
V_129 = F_64 ( V_152 , V_154 ) ;
if ( V_129 )
goto V_224;
V_215 = & F_77 ( V_214 ) ;
for ( V_114 = 0 , V_177 = V_154 -> V_193 ;
V_114 < V_154 -> V_225 ; V_114 ++ , V_177 = V_223 ) {
struct V_165 * V_34 = V_215 -> V_120 [ V_177 -> V_184 ] ;
V_129 = F_75 ( V_34 , V_154 , V_177 , & V_146 ,
& V_223 ) ;
if ( V_129 )
break;
F_88 ( V_34 , V_146 ) ;
}
F_78 ( V_214 ) ;
V_224:
F_78 ( V_191 ) ;
F_78 ( V_190 ) ;
V_192:
F_98 () ;
return V_129 ;
}
static void F_100 ( struct V_196 * V_196 )
{
F_6 ( ! F_91 ( V_217 ) ) ;
F_98 () ;
}
static int F_101 ( void )
{
int V_79 ;
unsigned long V_107 ;
struct V_194 V_195 ;
if ( ! F_102 ( V_226 ) ) {
F_17 ( L_62 ) ;
return - V_227 ;
} else if ( ! V_228 -> V_229 )
return - V_227 ;
if ( ! strcmp ( V_228 -> V_229 , L_63 ) )
V_9 = 1 ;
else {
V_9 = 2 ;
if ( V_230 == 8 )
V_2 = true ;
}
V_107 = F_84 ( & V_195 ) ;
if ( V_107 ) {
F_17 ( L_64 ,
V_107 ) ;
return - V_227 ;
}
V_125 = F_103 ( L_65 , 4096 , 4096 , 0 , NULL ) ;
if ( ! V_125 )
return - V_93 ;
V_231 . V_232 |= V_233 ;
V_79 = F_50 ( & V_234 . V_72 ,
& V_235 . V_72 ,
& V_236 . V_72 ) ;
if ( V_79 )
return V_79 ;
V_79 = F_104 ( & V_231 , V_231 . V_53 , - 1 ) ;
if ( V_79 )
return V_79 ;
return 0 ;
}

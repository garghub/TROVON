static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
F_4 ( L_1 ,
V_8 -> type , V_8 -> V_9 , V_8 -> V_10 , V_8 -> V_11 ) ;
F_4 ( L_2 ) ;
F_5 ( V_5 -> V_12 . V_13 ) ;
return - V_14 ;
}
static int F_6 ( struct V_15 * V_12 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_16 * V_17 = V_5 -> V_18 -> V_17 ;
struct V_19 V_8 ;
int V_20 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_21 . type = V_22 ;
V_8 . V_21 . V_9 = V_23 ;
V_8 . V_21 . V_10 = V_24 ;
V_8 . V_21 . V_11 = F_8 ( V_12 ) ;
V_8 . V_25 = V_26 ;
V_8 . V_27 = V_28 ;
V_8 . V_29 = 0 ;
for ( V_20 = 0 ; V_20 < 6 ; V_20 ++ )
V_8 . V_30 |= ( V_31 ) V_17 -> V_32 [ V_20 ] << ( ( 5 - V_20 ) * 8 ) ;
V_8 . V_33 = V_34 ;
F_9 ( V_35 , L_3
L_4 ,
V_8 . V_25 , V_8 . V_27 ,
( unsigned long long ) V_8 . V_30 ,
V_8 . V_29 ,
( unsigned long long ) V_8 . V_33 ) ;
return F_10 ( V_12 , & V_8 , sizeof( V_8 ) ) ;
}
static int F_11 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
F_9 ( V_35 , L_5
L_4 ,
V_8 -> V_25 , V_8 -> V_27 ,
( unsigned long long ) V_8 -> V_30 ,
V_8 -> V_29 ,
( unsigned long long ) V_8 -> V_33 ) ;
V_8 -> V_21 . V_11 = F_8 ( V_12 ) ;
if ( V_8 -> V_25 != V_26 ||
V_8 -> V_27 != V_28 ||
V_8 -> V_33 != V_34 ) {
F_9 ( V_35 , L_6 ) ;
V_8 -> V_21 . V_9 = V_36 ;
( void ) F_10 ( V_12 , V_8 , sizeof( * V_8 ) ) ;
return - V_14 ;
} else {
F_9 ( V_35 , L_7 ) ;
V_8 -> V_21 . V_9 = V_37 ;
return F_10 ( V_12 , V_8 , sizeof( * V_8 ) ) ;
}
}
static int F_12 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
F_9 ( V_35 , L_8 ) ;
return 0 ;
}
static int F_13 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
F_9 ( V_35 , L_9 ) ;
return - V_14 ;
}
static int F_14 ( struct V_15 * V_12 , void * V_6 )
{
struct V_19 * V_8 = V_6 ;
switch ( V_8 -> V_21 . V_9 ) {
case V_23 :
return F_11 ( V_12 , V_8 ) ;
case V_37 :
return F_12 ( V_12 , V_8 ) ;
case V_36 :
return F_13 ( V_12 , V_8 ) ;
default:
return - V_14 ;
}
}
static void F_15 ( struct V_15 * V_12 )
{
struct V_1 * V_2 ;
V_2 = & V_12 -> V_38 [ V_39 ] ;
V_2 -> V_40 = V_2 -> V_41 = 1 ;
V_2 = & V_12 -> V_38 [ V_42 ] ;
V_2 -> V_40 = V_2 -> V_41 = 1 ;
}
static struct V_43 * F_16 ( struct V_16 * V_17 ,
unsigned int V_44 )
{
struct V_43 * V_45 = F_17 ( V_17 , V_44 + V_46 + 8 + 8 ) ;
unsigned long V_30 , V_47 ;
if ( F_18 ( ! V_45 ) )
return NULL ;
V_30 = ( unsigned long ) V_45 -> V_48 ;
V_47 = ( ( V_30 + 7UL ) & ~ 7UL ) - V_30 ;
if ( V_47 )
F_19 ( V_45 , V_47 ) ;
return V_45 ;
}
static int F_20 ( struct V_4 * V_5 , unsigned int V_44 ,
struct V_49 * V_50 , int V_51 )
{
struct V_16 * V_17 = V_5 -> V_18 -> V_17 ;
unsigned int V_52 ;
struct V_43 * V_45 ;
int V_53 ;
V_53 = - V_54 ;
if ( F_18 ( V_44 < V_55 || V_44 > V_34 ) ) {
V_17 -> V_56 . V_57 ++ ;
goto V_58;
}
V_45 = F_16 ( V_17 , V_44 ) ;
V_53 = - V_59 ;
if ( F_18 ( ! V_45 ) ) {
V_17 -> V_56 . V_60 ++ ;
goto V_58;
}
V_52 = ( V_44 + V_46 + 7U ) & ~ 7U ;
F_21 ( V_45 , V_52 ) ;
V_53 = F_22 ( V_5 -> V_12 . V_13 , V_61 ,
V_45 -> V_48 , V_52 , 0 ,
V_50 , V_51 ) ;
if ( F_18 ( V_53 < 0 ) ) {
V_17 -> V_56 . V_62 ++ ;
goto V_63;
}
F_23 ( V_45 , V_46 ) ;
F_24 ( V_45 , V_44 ) ;
V_45 -> V_64 = F_25 ( V_45 , V_17 ) ;
V_17 -> V_56 . V_65 ++ ;
V_17 -> V_56 . V_66 += V_44 ;
F_26 ( V_45 ) ;
return 0 ;
V_63:
F_27 ( V_45 ) ;
V_58:
V_17 -> V_56 . V_67 ++ ;
return V_53 ;
}
static int F_28 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_68 , T_1 V_69 , T_2 V_1 )
{
struct V_70 V_71 = {
. V_21 = {
. type = V_72 ,
. V_9 = V_37 ,
. V_10 = V_73 ,
. V_11 = F_8 ( & V_5 -> V_12 ) ,
} ,
. V_74 = V_2 -> V_75 ,
. V_76 = V_68 ,
. V_77 = V_69 ,
. V_78 = V_1 ,
} ;
int V_53 , V_79 ;
V_71 . V_80 = V_2 -> V_40 ;
V_79 = 1 ;
do {
V_53 = F_10 ( & V_5 -> V_12 , & V_71 , sizeof( V_71 ) ) ;
if ( V_53 > 0 ) {
V_2 -> V_40 ++ ;
break;
}
F_29 ( V_79 ) ;
if ( ( V_79 <<= 1 ) > 128 )
V_79 = 128 ;
} while ( V_53 == - V_81 );
return V_53 ;
}
static T_1 F_30 ( T_1 V_82 , struct V_1 * V_2 )
{
if ( ++ V_82 == V_2 -> V_83 )
V_82 = 0 ;
return V_82 ;
}
static T_1 F_31 ( T_1 V_82 , struct V_1 * V_2 )
{
if ( V_82 == 0 )
V_82 = V_2 -> V_83 - 1 ;
else
V_82 -- ;
return V_82 ;
}
static struct V_84 * F_32 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_85 )
{
struct V_84 * V_86 = V_5 -> V_12 . V_87 ;
int V_53 ;
V_53 = F_33 ( V_5 -> V_12 . V_13 , V_86 , V_2 -> V_88 ,
( V_85 * V_2 -> V_88 ) ,
V_2 -> V_50 , V_2 -> V_51 ) ;
if ( V_53 < 0 )
return F_34 ( V_53 ) ;
return V_86 ;
}
static int F_35 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_84 * V_86 ,
T_1 V_85 )
{
int V_53 ;
V_53 = F_36 ( V_5 -> V_12 . V_13 , V_86 , V_2 -> V_88 ,
( V_85 * V_2 -> V_88 ) ,
V_2 -> V_50 , V_2 -> V_51 ) ;
if ( V_53 < 0 )
return V_53 ;
return 0 ;
}
static int F_37 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_85 , int * V_89 )
{
struct V_84 * V_86 = F_32 ( V_5 , V_2 , V_85 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_53 ;
if ( F_38 ( V_86 ) )
return F_39 ( V_86 ) ;
F_9 ( V_90 , L_10 ,
V_86 -> V_71 . V_78 , V_86 -> V_71 . V_91 ,
V_86 -> V_92 , V_86 -> V_51 ,
V_86 -> V_50 [ 0 ] . V_93 ,
V_86 -> V_50 [ 0 ] . V_94 ) ;
if ( V_86 -> V_71 . V_78 != V_95 )
return 1 ;
V_53 = F_20 ( V_5 , V_86 -> V_92 , V_86 -> V_50 , V_86 -> V_51 ) ;
if ( V_53 == - V_14 )
return V_53 ;
V_86 -> V_71 . V_78 = V_96 ;
V_53 = F_35 ( V_5 , V_2 , V_86 , V_85 ) ;
if ( V_53 < 0 )
return V_53 ;
* V_89 = V_86 -> V_71 . V_91 ;
return 0 ;
}
static int F_40 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_68 , T_1 V_69 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_97 = - 1 , V_98 = - 1 ;
V_69 = ( V_69 == ( T_1 ) - 1 ) ? F_31 ( V_68 , V_2 ) : F_30 ( V_69 , V_2 ) ;
F_9 ( V_90 , L_11 , V_68 , V_69 ) ;
while ( V_68 != V_69 ) {
int V_91 = 0 , V_53 = F_37 ( V_5 , V_2 , V_68 , & V_91 ) ;
if ( V_53 == - V_14 )
return V_53 ;
if ( V_53 != 0 )
break;
if ( V_97 == - 1 )
V_97 = V_68 ;
V_98 = V_68 ;
V_68 = F_30 ( V_68 , V_2 ) ;
if ( V_91 && V_68 != V_69 ) {
V_53 = F_28 ( V_5 , V_2 , V_97 , V_98 ,
V_99 ) ;
if ( V_53 == - V_14 )
return V_53 ;
V_97 = - 1 ;
}
}
if ( F_18 ( V_97 == - 1 ) )
V_97 = V_98 = F_31 ( V_68 , V_2 ) ;
return F_28 ( V_5 , V_2 , V_97 , V_98 , V_100 ) ;
}
static int F_41 ( struct V_4 * V_5 , void * V_101 )
{
struct V_70 * V_8 = V_101 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_38 [ V_39 ] ;
struct V_15 * V_12 = & V_5 -> V_12 ;
F_9 ( V_90 , L_12 ,
V_8 -> V_21 . V_10 , V_8 -> V_80 , V_2 -> V_41 ) ;
if ( F_18 ( V_8 -> V_21 . V_10 != V_73 ) )
return 0 ;
if ( F_18 ( V_8 -> V_80 != V_2 -> V_41 ) ) {
F_4 ( L_13 ,
V_8 -> V_80 , V_2 -> V_41 ) ;
return 0 ;
}
V_2 -> V_41 ++ ;
return F_40 ( V_5 , V_2 , V_8 -> V_76 , V_8 -> V_77 ) ;
}
static int F_42 ( struct V_1 * V_2 , T_1 V_69 )
{
T_1 V_82 = V_2 -> V_102 ;
int V_103 = 0 ;
while ( V_82 != V_2 -> V_104 ) {
if ( V_82 == V_69 ) {
V_103 = 1 ;
break;
}
V_82 = F_30 ( V_82 , V_2 ) ;
}
return V_103 ;
}
static int F_43 ( struct V_4 * V_5 , void * V_101 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
struct V_70 * V_8 = V_101 ;
struct V_16 * V_17 ;
struct V_105 * V_18 ;
T_1 V_69 ;
if ( F_18 ( V_8 -> V_21 . V_10 != V_73 ) )
return 0 ;
V_69 = V_8 -> V_77 ;
if ( F_18 ( ! F_42 ( V_2 , V_69 ) ) )
return 0 ;
V_2 -> V_102 = F_30 ( V_69 , V_2 ) ;
V_18 = V_5 -> V_18 ;
V_17 = V_18 -> V_17 ;
if ( F_18 ( F_44 ( V_17 ) &&
F_1 ( V_2 ) >= F_45 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 , void * V_101 )
{
return 0 ;
}
static int F_47 ( struct V_4 * V_5 , void * V_101 )
{
struct V_106 * V_8 = V_101 ;
if ( V_8 -> V_21 . V_9 != V_37 )
F_4 ( L_14 ,
V_5 -> V_18 -> V_17 -> V_107 ,
V_8 -> V_21 . type ,
V_8 -> V_21 . V_9 ,
V_8 -> V_21 . V_10 ,
V_8 -> V_21 . V_11 ) ;
return 0 ;
}
static void F_48 ( struct V_105 * V_18 )
{
struct V_16 * V_17 = V_18 -> V_17 ;
F_49 ( V_17 ) ;
if ( F_50 ( F_44 ( V_17 ) ) ) {
struct V_4 * V_5 ;
int V_108 = 1 ;
F_51 (port, &vp->port_list, list) {
struct V_1 * V_2 ;
V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
if ( F_1 ( V_2 ) <
F_45 ( V_2 ) ) {
V_108 = 0 ;
break;
}
}
if ( V_108 )
F_52 ( V_17 ) ;
}
F_53 ( V_17 ) ;
}
static void F_54 ( void * V_6 , int V_109 )
{
struct V_4 * V_5 = V_6 ;
struct V_15 * V_12 = & V_5 -> V_12 ;
unsigned long V_110 ;
int V_111 , V_53 ;
F_55 ( & V_12 -> V_112 , V_110 ) ;
if ( F_18 ( V_109 == V_113 ||
V_109 == V_114 ) ) {
F_56 ( V_12 , V_109 ) ;
F_57 ( & V_12 -> V_112 , V_110 ) ;
if ( V_109 == V_113 )
F_58 ( V_12 ) ;
return;
}
if ( F_18 ( V_109 != V_115 ) ) {
F_59 ( L_15 , V_109 ) ;
F_57 ( & V_12 -> V_112 , V_110 ) ;
return;
}
V_111 = V_53 = 0 ;
while ( 1 ) {
union {
struct V_7 V_21 ;
V_31 V_116 [ 8 ] ;
} V_101 ;
V_53 = F_60 ( V_12 -> V_13 , & V_101 , sizeof( V_101 ) ) ;
if ( F_18 ( V_53 < 0 ) ) {
if ( V_53 == - V_14 )
F_61 ( V_12 ) ;
break;
}
if ( V_53 == 0 )
break;
F_9 ( V_90 , L_16 ,
V_101 . V_21 . type ,
V_101 . V_21 . V_9 ,
V_101 . V_21 . V_10 ,
V_101 . V_21 . V_11 ) ;
V_53 = F_62 ( V_12 , & V_101 . V_21 ) ;
if ( V_53 < 0 )
break;
if ( F_50 ( V_101 . V_21 . type == V_72 ) ) {
if ( V_101 . V_21 . V_9 == V_23 ) {
V_53 = F_41 ( V_5 , & V_101 ) ;
} else if ( V_101 . V_21 . V_9 == V_37 ) {
V_53 = F_43 ( V_5 , & V_101 ) ;
if ( V_53 > 0 )
V_111 |= V_53 ;
} else if ( V_101 . V_21 . V_9 == V_36 ) {
V_53 = F_46 ( V_5 , & V_101 ) ;
}
} else if ( V_101 . V_21 . type == V_22 ) {
if ( V_101 . V_21 . V_10 == V_117 )
V_53 = F_47 ( V_5 , & V_101 ) ;
else
V_53 = F_63 ( V_12 , & V_101 ) ;
if ( V_53 )
break;
} else {
V_53 = F_3 ( V_5 , & V_101 ) ;
}
if ( V_53 == - V_14 )
break;
}
F_64 ( & V_12 -> V_112 ) ;
if ( F_18 ( V_111 && V_53 != - V_14 ) )
F_48 ( V_5 -> V_18 ) ;
F_65 ( V_110 ) ;
}
static int F_66 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
struct V_70 V_71 = {
. V_21 = {
. type = V_72 ,
. V_9 = V_23 ,
. V_10 = V_73 ,
. V_11 = F_8 ( & V_5 -> V_12 ) ,
} ,
. V_74 = V_2 -> V_75 ,
. V_76 = V_2 -> V_104 ,
. V_77 = ( T_1 ) - 1 ,
} ;
int V_53 , V_79 ;
V_71 . V_80 = V_2 -> V_40 ;
V_79 = 1 ;
do {
V_53 = F_10 ( & V_5 -> V_12 , & V_71 , sizeof( V_71 ) ) ;
if ( V_53 > 0 ) {
V_2 -> V_40 ++ ;
break;
}
F_29 ( V_79 ) ;
if ( ( V_79 <<= 1 ) > 128 )
V_79 = 128 ;
} while ( V_53 == - V_81 );
return V_53 ;
}
struct V_4 * F_67 ( struct V_105 * V_18 , struct V_43 * V_45 )
{
unsigned int V_118 = F_68 ( V_45 -> V_48 ) ;
struct V_119 * V_120 = & V_18 -> V_121 [ V_118 ] ;
struct V_4 * V_5 ;
F_69 (port, hp, hash) {
if ( F_70 ( V_5 -> V_122 , V_45 -> V_48 ) )
return V_5 ;
}
V_5 = NULL ;
if ( ! F_71 ( & V_18 -> V_123 ) )
V_5 = F_72 ( V_18 -> V_123 . V_124 , struct V_4 , V_125 ) ;
return V_5 ;
}
struct V_4 * F_73 ( struct V_105 * V_18 , struct V_43 * V_45 )
{
struct V_4 * V_126 ;
unsigned long V_110 ;
F_55 ( & V_18 -> V_112 , V_110 ) ;
V_126 = F_67 ( V_18 , V_45 ) ;
F_57 ( & V_18 -> V_112 , V_110 ) ;
return V_126 ;
}
static int F_74 ( struct V_43 * V_45 , struct V_16 * V_17 )
{
struct V_105 * V_18 = F_75 ( V_17 ) ;
struct V_4 * V_5 = F_73 ( V_18 , V_45 ) ;
struct V_1 * V_2 ;
struct V_84 * V_127 ;
unsigned long V_110 ;
unsigned int V_44 ;
void * V_128 ;
int V_20 , V_53 ;
if ( F_18 ( ! V_5 ) )
goto V_58;
F_55 ( & V_5 -> V_12 . V_112 , V_110 ) ;
V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
if ( F_18 ( F_1 ( V_2 ) < 2 ) ) {
if ( ! F_44 ( V_17 ) ) {
F_76 ( V_17 ) ;
F_77 ( V_17 , L_17 ) ;
V_17 -> V_56 . V_129 ++ ;
}
F_57 ( & V_5 -> V_12 . V_112 , V_110 ) ;
return V_130 ;
}
V_127 = F_78 ( V_2 ) ;
V_128 = V_5 -> V_131 [ V_2 -> V_104 ] . V_132 ;
F_79 ( V_45 , V_128 + V_46 , V_45 -> V_44 ) ;
V_44 = V_45 -> V_44 ;
if ( V_44 < V_55 ) {
V_44 = V_55 ;
memset ( V_128 + V_46 + V_45 -> V_44 , 0 , V_44 - V_45 -> V_44 ) ;
}
V_127 -> V_71 . V_91 = V_133 ;
V_127 -> V_92 = V_44 ;
V_127 -> V_51 = V_5 -> V_131 [ V_2 -> V_104 ] . V_51 ;
for ( V_20 = 0 ; V_20 < V_127 -> V_51 ; V_20 ++ )
V_127 -> V_50 [ V_20 ] = V_5 -> V_131 [ V_2 -> V_104 ] . V_50 [ V_20 ] ;
F_80 () ;
V_127 -> V_71 . V_78 = V_95 ;
V_53 = F_66 ( V_5 ) ;
if ( F_18 ( V_53 < 0 ) ) {
F_81 ( V_17 , L_18 , V_53 ) ;
V_127 -> V_71 . V_78 = V_134 ;
V_17 -> V_56 . V_135 ++ ;
goto V_136;
}
V_17 -> V_56 . V_137 ++ ;
V_17 -> V_56 . V_138 += V_45 -> V_44 ;
V_2 -> V_104 = ( V_2 -> V_104 + 1 ) & ( V_3 - 1 ) ;
if ( F_18 ( F_1 ( V_2 ) < 2 ) ) {
F_76 ( V_17 ) ;
if ( F_1 ( V_2 ) > F_45 ( V_2 ) )
F_52 ( V_17 ) ;
}
F_57 ( & V_5 -> V_12 . V_112 , V_110 ) ;
F_82 ( V_45 ) ;
return V_139 ;
V_136:
F_57 ( & V_5 -> V_12 . V_112 , V_110 ) ;
V_58:
F_82 ( V_45 ) ;
V_17 -> V_56 . V_140 ++ ;
return V_139 ;
}
static void F_83 ( struct V_16 * V_17 )
{
}
static int F_84 ( struct V_16 * V_17 )
{
F_85 ( V_17 ) ;
F_86 ( V_17 ) ;
return 0 ;
}
static int F_87 ( struct V_16 * V_17 )
{
F_76 ( V_17 ) ;
F_88 ( V_17 ) ;
return 0 ;
}
static struct V_141 * F_89 ( struct V_105 * V_18 , T_2 * V_30 )
{
struct V_141 * V_142 ;
for ( V_142 = V_18 -> V_143 ; V_142 ; V_142 = V_142 -> V_124 ) {
if ( ! memcmp ( V_142 -> V_30 , V_30 , V_144 ) )
return V_142 ;
}
return NULL ;
}
static void F_90 ( struct V_105 * V_18 , struct V_16 * V_17 )
{
struct V_145 * V_146 ;
F_91 (ha, dev) {
struct V_141 * V_142 ;
V_142 = F_89 ( V_18 , V_146 -> V_30 ) ;
if ( V_142 ) {
V_142 -> V_147 = 1 ;
continue;
}
if ( ! V_142 ) {
V_142 = F_92 ( sizeof( * V_142 ) , V_148 ) ;
if ( ! V_142 )
continue;
memcpy ( V_142 -> V_30 , V_146 -> V_30 , V_144 ) ;
V_142 -> V_147 = 1 ;
V_142 -> V_124 = V_18 -> V_143 ;
V_18 -> V_143 = V_142 ;
}
}
}
static void F_93 ( struct V_105 * V_18 , struct V_4 * V_5 )
{
struct V_106 V_149 ;
struct V_141 * V_142 , * * V_150 ;
int V_151 ;
memset ( & V_149 , 0 , sizeof( V_149 ) ) ;
V_149 . V_21 . type = V_22 ;
V_149 . V_21 . V_9 = V_23 ;
V_149 . V_21 . V_10 = V_117 ;
V_149 . V_21 . V_11 = F_8 ( & V_5 -> V_12 ) ;
V_149 . V_152 = 1 ;
V_151 = 0 ;
for ( V_142 = V_18 -> V_143 ; V_142 ; V_142 = V_142 -> V_124 ) {
if ( V_142 -> V_153 )
continue;
V_142 -> V_153 = 1 ;
memcpy ( & V_149 . V_154 [ V_151 * V_144 ] ,
V_142 -> V_30 , V_144 ) ;
if ( ++ V_151 == V_155 ) {
V_149 . V_156 = V_151 ;
( void ) F_10 ( & V_5 -> V_12 , & V_149 ,
sizeof( V_149 ) ) ;
V_151 = 0 ;
}
}
if ( V_151 ) {
V_149 . V_156 = V_151 ;
( void ) F_10 ( & V_5 -> V_12 , & V_149 , sizeof( V_149 ) ) ;
}
V_149 . V_152 = 0 ;
V_151 = 0 ;
V_150 = & V_18 -> V_143 ;
while ( ( V_142 = * V_150 ) != NULL ) {
if ( V_142 -> V_147 ) {
V_142 -> V_147 = 0 ;
V_150 = & V_142 -> V_124 ;
continue;
}
memcpy ( & V_149 . V_154 [ V_151 * V_144 ] ,
V_142 -> V_30 , V_144 ) ;
if ( ++ V_151 == V_155 ) {
V_149 . V_156 = V_151 ;
( void ) F_10 ( & V_5 -> V_12 , & V_149 ,
sizeof( V_149 ) ) ;
V_151 = 0 ;
}
* V_150 = V_142 -> V_124 ;
F_94 ( V_142 ) ;
}
if ( V_151 ) {
V_149 . V_156 = V_151 ;
( void ) F_10 ( & V_5 -> V_12 , & V_149 , sizeof( V_149 ) ) ;
}
}
static void F_95 ( struct V_16 * V_17 )
{
struct V_105 * V_18 = F_75 ( V_17 ) ;
struct V_4 * V_5 ;
unsigned long V_110 ;
F_55 ( & V_18 -> V_112 , V_110 ) ;
if ( ! F_71 ( & V_18 -> V_123 ) ) {
V_5 = F_72 ( V_18 -> V_123 . V_124 , struct V_4 , V_125 ) ;
if ( V_5 -> V_157 ) {
F_90 ( V_18 , V_17 ) ;
F_93 ( V_18 , V_5 ) ;
}
}
F_57 ( & V_18 -> V_112 , V_110 ) ;
}
static int F_96 ( struct V_16 * V_17 , int V_158 )
{
if ( V_158 != V_159 )
return - V_160 ;
V_17 -> V_33 = V_158 ;
return 0 ;
}
static int F_97 ( struct V_16 * V_17 , void * V_161 )
{
return - V_160 ;
}
static void F_98 ( struct V_16 * V_17 ,
struct V_162 * V_149 )
{
F_99 ( V_149 -> V_163 , V_164 , sizeof( V_149 -> V_163 ) ) ;
F_99 ( V_149 -> V_165 , V_166 , sizeof( V_149 -> V_165 ) ) ;
}
static T_1 F_100 ( struct V_16 * V_17 )
{
struct V_105 * V_18 = F_75 ( V_17 ) ;
return V_18 -> V_167 ;
}
static void F_101 ( struct V_16 * V_17 , T_1 V_168 )
{
struct V_105 * V_18 = F_75 ( V_17 ) ;
V_18 -> V_167 = V_168 ;
}
static void F_102 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_20 ;
V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
if ( V_2 -> V_169 ) {
F_103 ( V_5 -> V_12 . V_13 , V_2 -> V_169 ,
( V_2 -> V_88 * V_2 -> V_83 ) ,
V_2 -> V_50 , V_2 -> V_51 ) ;
V_2 -> V_169 = NULL ;
V_2 -> V_88 = 0 ;
V_2 -> V_83 = 0 ;
V_2 -> V_170 = 0 ;
V_2 -> V_51 = 0 ;
}
for ( V_20 = 0 ; V_20 < V_3 ; V_20 ++ ) {
void * V_132 = V_5 -> V_131 [ V_20 ] . V_132 ;
if ( ! V_132 )
continue;
F_104 ( V_5 -> V_12 . V_13 ,
V_5 -> V_131 [ V_20 ] . V_50 ,
V_5 -> V_131 [ V_20 ] . V_51 ) ;
F_94 ( V_132 ) ;
V_5 -> V_131 [ V_20 ] . V_132 = NULL ;
}
}
static int F_105 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
int V_20 , V_53 , V_51 ;
void * V_171 ;
for ( V_20 = 0 ; V_20 < V_3 ; V_20 ++ ) {
void * V_132 = F_92 ( V_34 + 8 , V_172 ) ;
int V_173 = ( V_34 + 7 ) & ~ 7 ;
V_53 = - V_59 ;
if ( ! V_132 )
goto V_174;
V_53 = - V_175 ;
if ( ( unsigned long ) V_132 & ( 8UL - 1 ) ) {
F_4 ( L_19 ) ;
F_94 ( V_132 ) ;
goto V_174;
}
V_53 = F_106 ( V_5 -> V_12 . V_13 , V_132 , V_173 ,
V_5 -> V_131 [ V_20 ] . V_50 , 2 ,
( V_176 |
V_177 |
V_178 ) ) ;
if ( V_53 < 0 ) {
F_94 ( V_132 ) ;
goto V_174;
}
V_5 -> V_131 [ V_20 ] . V_132 = V_132 ;
V_5 -> V_131 [ V_20 ] . V_51 = V_53 ;
}
V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
V_44 = ( V_3 *
( sizeof( struct V_84 ) +
( sizeof( struct V_49 ) * 2 ) ) ) ;
V_51 = V_179 ;
V_171 = F_107 ( V_5 -> V_12 . V_13 , V_44 ,
V_2 -> V_50 , & V_51 ,
( V_176 |
V_177 |
V_178 ) ) ;
if ( F_38 ( V_171 ) ) {
V_53 = F_39 ( V_171 ) ;
goto V_174;
}
V_2 -> V_169 = V_171 ;
V_2 -> V_88 = ( sizeof( struct V_84 ) +
( sizeof( struct V_49 ) * 2 ) ) ;
V_2 -> V_83 = V_3 ;
V_2 -> V_104 = V_2 -> V_102 = 0 ;
V_2 -> V_170 = V_3 ;
V_2 -> V_51 = V_51 ;
return 0 ;
V_174:
F_102 ( V_5 ) ;
return V_53 ;
}
static struct V_105 * F_108 ( const V_31 * V_180 )
{
struct V_16 * V_17 ;
struct V_105 * V_18 ;
int V_53 , V_20 ;
V_17 = F_109 ( sizeof( * V_18 ) ) ;
if ( ! V_17 )
return F_34 ( - V_59 ) ;
for ( V_20 = 0 ; V_20 < V_144 ; V_20 ++ )
V_17 -> V_32 [ V_20 ] = ( * V_180 >> ( 5 - V_20 ) * 8 ) & 0xff ;
V_18 = F_75 ( V_17 ) ;
F_110 ( & V_18 -> V_112 ) ;
V_18 -> V_17 = V_17 ;
F_111 ( & V_18 -> V_123 ) ;
for ( V_20 = 0 ; V_20 < V_181 ; V_20 ++ )
F_112 ( & V_18 -> V_121 [ V_20 ] ) ;
F_111 ( & V_18 -> V_125 ) ;
V_18 -> V_180 = * V_180 ;
V_17 -> V_182 = & V_183 ;
V_17 -> V_184 = & V_185 ;
V_17 -> V_186 = V_187 ;
V_53 = F_113 ( V_17 ) ;
if ( V_53 ) {
F_4 ( L_20 ) ;
goto V_188;
}
F_81 ( V_17 , L_21 , V_17 -> V_32 ) ;
F_114 ( & V_18 -> V_125 , & V_189 ) ;
return V_18 ;
V_188:
F_115 ( V_17 ) ;
return F_34 ( V_53 ) ;
}
static struct V_105 * F_116 ( const V_31 * V_180 )
{
struct V_105 * V_190 , * V_18 ;
F_117 ( & V_191 ) ;
V_18 = NULL ;
F_51 (iter, &vnet_list, list) {
if ( V_190 -> V_180 == * V_180 ) {
V_18 = V_190 ;
break;
}
}
if ( ! V_18 )
V_18 = F_108 ( V_180 ) ;
F_118 ( & V_191 ) ;
return V_18 ;
}
static struct V_105 * F_119 ( struct V_192 * V_120 ,
V_31 V_193 )
{
const V_31 * V_180 = NULL ;
V_31 V_194 ;
F_120 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
V_31 V_195 = F_121 ( V_120 , V_194 ) ;
const char * V_107 ;
V_107 = F_122 ( V_120 , V_195 , L_22 , NULL ) ;
if ( ! V_107 || strcmp ( V_107 , L_23 ) )
continue;
V_180 = F_122 ( V_120 , V_195 ,
V_196 , NULL ) ;
if ( V_180 )
break;
}
if ( ! V_180 )
return F_34 ( - V_197 ) ;
return F_116 ( V_180 ) ;
}
static void F_123 ( void )
{
F_124 ( V_198 L_24 , V_165 ) ;
}
static int F_125 ( struct V_199 * V_200 , const struct V_201 * V_202 )
{
struct V_192 * V_120 ;
struct V_4 * V_5 ;
unsigned long V_110 ;
struct V_105 * V_18 ;
const V_31 * V_203 ;
int V_44 , V_20 , V_53 , V_157 ;
F_123 () ;
V_120 = F_126 () ;
V_18 = F_119 ( V_120 , V_200 -> V_204 ) ;
if ( F_38 ( V_18 ) ) {
F_4 ( L_25 ) ;
V_53 = F_39 ( V_18 ) ;
goto V_205;
}
V_203 = F_122 ( V_120 , V_200 -> V_204 , V_206 , & V_44 ) ;
V_53 = - V_197 ;
if ( ! V_203 ) {
F_4 ( L_26 , V_206 ) ;
goto V_205;
}
V_5 = F_92 ( sizeof( * V_5 ) , V_172 ) ;
V_53 = - V_59 ;
if ( ! V_5 )
goto V_205;
for ( V_20 = 0 ; V_20 < V_144 ; V_20 ++ )
V_5 -> V_122 [ V_20 ] = ( * V_203 >> ( 5 - V_20 ) * 8 ) & 0xff ;
V_5 -> V_18 = V_18 ;
V_53 = F_127 ( & V_5 -> V_12 , V_200 , V_207 ,
V_208 , F_128 ( V_208 ) ,
& V_209 , V_18 -> V_17 -> V_107 ) ;
if ( V_53 )
goto V_210;
V_53 = F_129 ( & V_5 -> V_12 , & V_211 , V_5 ) ;
if ( V_53 )
goto V_210;
V_53 = F_105 ( V_5 ) ;
if ( V_53 )
goto V_212;
F_130 ( & V_5 -> V_118 ) ;
F_111 ( & V_5 -> V_125 ) ;
V_157 = 0 ;
if ( F_122 ( V_120 , V_200 -> V_204 , L_27 , NULL ) != NULL )
V_157 = 1 ;
V_5 -> V_157 = V_157 ;
F_55 ( & V_18 -> V_112 , V_110 ) ;
if ( V_157 )
F_114 ( & V_5 -> V_125 , & V_18 -> V_123 ) ;
else
F_131 ( & V_5 -> V_125 , & V_18 -> V_123 ) ;
F_132 ( & V_5 -> V_118 , & V_18 -> V_121 [ F_68 ( V_5 -> V_122 ) ] ) ;
F_57 ( & V_18 -> V_112 , V_110 ) ;
F_133 ( & V_200 -> V_17 , V_5 ) ;
F_134 ( L_28 ,
V_18 -> V_17 -> V_107 , V_5 -> V_122 , V_157 ? L_29 : L_30 ) ;
F_58 ( & V_5 -> V_12 ) ;
F_135 ( V_120 ) ;
return 0 ;
V_212:
F_136 ( & V_5 -> V_12 ) ;
V_210:
F_94 ( V_5 ) ;
V_205:
F_135 ( V_120 ) ;
return V_53 ;
}
static int F_137 ( struct V_199 * V_200 )
{
struct V_4 * V_5 = F_138 ( & V_200 -> V_17 ) ;
if ( V_5 ) {
struct V_105 * V_18 = V_5 -> V_18 ;
unsigned long V_110 ;
F_139 ( & V_5 -> V_12 . V_213 ) ;
F_55 ( & V_18 -> V_112 , V_110 ) ;
F_140 ( & V_5 -> V_125 ) ;
F_141 ( & V_5 -> V_118 ) ;
F_57 ( & V_18 -> V_112 , V_110 ) ;
F_102 ( V_5 ) ;
F_136 ( & V_5 -> V_12 ) ;
F_133 ( & V_200 -> V_17 , NULL ) ;
F_94 ( V_5 ) ;
F_142 ( V_18 -> V_17 ) ;
}
return 0 ;
}
static int T_3 F_143 ( void )
{
return F_144 ( & V_214 ) ;
}
static void T_4 F_145 ( void )
{
F_146 ( & V_214 ) ;
}

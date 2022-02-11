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
int V_80 = 0 ;
V_71 . V_81 = V_2 -> V_40 ;
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
if ( V_80 ++ > V_82 ) {
F_30 ( L_10 ,
V_5 -> V_83 [ 0 ] , V_5 -> V_83 [ 1 ] ,
V_5 -> V_83 [ 2 ] , V_5 -> V_83 [ 3 ] ,
V_5 -> V_83 [ 4 ] , V_5 -> V_83 [ 5 ] ) ;
V_53 = - V_14 ;
}
} while ( V_53 == - V_84 );
return V_53 ;
}
static T_1 F_31 ( T_1 V_85 , struct V_1 * V_2 )
{
if ( ++ V_85 == V_2 -> V_86 )
V_85 = 0 ;
return V_85 ;
}
static T_1 F_32 ( T_1 V_85 , struct V_1 * V_2 )
{
if ( V_85 == 0 )
V_85 = V_2 -> V_86 - 1 ;
else
V_85 -- ;
return V_85 ;
}
static struct V_87 * F_33 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_88 )
{
struct V_87 * V_89 = V_5 -> V_12 . V_90 ;
int V_53 ;
V_53 = F_34 ( V_5 -> V_12 . V_13 , V_89 , V_2 -> V_91 ,
( V_88 * V_2 -> V_91 ) ,
V_2 -> V_50 , V_2 -> V_51 ) ;
if ( V_53 < 0 )
return F_35 ( V_53 ) ;
return V_89 ;
}
static int F_36 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_87 * V_89 ,
T_1 V_88 )
{
int V_53 ;
V_53 = F_37 ( V_5 -> V_12 . V_13 , V_89 , V_2 -> V_91 ,
( V_88 * V_2 -> V_91 ) ,
V_2 -> V_50 , V_2 -> V_51 ) ;
if ( V_53 < 0 )
return V_53 ;
return 0 ;
}
static int F_38 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_88 , int * V_92 )
{
struct V_87 * V_89 = F_33 ( V_5 , V_2 , V_88 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_53 ;
if ( F_39 ( V_89 ) )
return F_40 ( V_89 ) ;
if ( V_89 -> V_71 . V_78 != V_93 )
return 1 ;
F_41 () ;
F_9 ( V_94 , L_11 ,
V_89 -> V_71 . V_78 , V_89 -> V_71 . V_95 ,
V_89 -> V_96 , V_89 -> V_51 ,
V_89 -> V_50 [ 0 ] . V_97 ,
V_89 -> V_50 [ 0 ] . V_98 ) ;
V_53 = F_20 ( V_5 , V_89 -> V_96 , V_89 -> V_50 , V_89 -> V_51 ) ;
if ( V_53 == - V_14 )
return V_53 ;
V_89 -> V_71 . V_78 = V_99 ;
V_53 = F_36 ( V_5 , V_2 , V_89 , V_88 ) ;
if ( V_53 < 0 )
return V_53 ;
* V_92 = V_89 -> V_71 . V_95 ;
return 0 ;
}
static int F_42 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_68 , T_1 V_69 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_100 = - 1 , V_101 = - 1 ;
V_69 = ( V_69 == ( T_1 ) - 1 ) ? F_32 ( V_68 , V_2 ) : F_31 ( V_69 , V_2 ) ;
F_9 ( V_94 , L_12 , V_68 , V_69 ) ;
while ( V_68 != V_69 ) {
int V_95 = 0 , V_53 = F_38 ( V_5 , V_2 , V_68 , & V_95 ) ;
if ( V_53 == - V_14 )
return V_53 ;
if ( V_53 != 0 )
break;
if ( V_100 == - 1 )
V_100 = V_68 ;
V_101 = V_68 ;
V_68 = F_31 ( V_68 , V_2 ) ;
if ( V_95 && V_68 != V_69 ) {
V_53 = F_28 ( V_5 , V_2 , V_100 , V_101 ,
V_102 ) ;
if ( V_53 == - V_14 )
return V_53 ;
V_100 = - 1 ;
}
}
if ( F_18 ( V_100 == - 1 ) )
V_100 = V_101 = F_32 ( V_68 , V_2 ) ;
return F_28 ( V_5 , V_2 , V_100 , V_101 , V_103 ) ;
}
static int F_43 ( struct V_4 * V_5 , void * V_104 )
{
struct V_70 * V_8 = V_104 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_38 [ V_39 ] ;
struct V_15 * V_12 = & V_5 -> V_12 ;
F_9 ( V_94 , L_13 ,
V_8 -> V_21 . V_10 , V_8 -> V_81 , V_2 -> V_41 ) ;
if ( F_18 ( V_8 -> V_21 . V_10 != V_73 ) )
return 0 ;
if ( F_18 ( V_8 -> V_81 != V_2 -> V_41 ) ) {
F_4 ( L_14 ,
V_8 -> V_81 , V_2 -> V_41 ) ;
return 0 ;
}
V_2 -> V_41 ++ ;
return F_42 ( V_5 , V_2 , V_8 -> V_76 , V_8 -> V_77 ) ;
}
static int F_44 ( struct V_1 * V_2 , T_1 V_69 )
{
T_1 V_85 = V_2 -> V_105 ;
int V_106 = 0 ;
while ( V_85 != V_2 -> V_107 ) {
if ( V_85 == V_69 ) {
V_106 = 1 ;
break;
}
V_85 = F_31 ( V_85 , V_2 ) ;
}
return V_106 ;
}
static int F_45 ( struct V_4 * V_5 , void * V_104 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
struct V_70 * V_8 = V_104 ;
struct V_16 * V_17 ;
struct V_108 * V_18 ;
T_1 V_69 ;
if ( F_18 ( V_8 -> V_21 . V_10 != V_73 ) )
return 0 ;
V_69 = V_8 -> V_77 ;
if ( F_18 ( ! F_44 ( V_2 , V_69 ) ) )
return 0 ;
V_2 -> V_105 = F_31 ( V_69 , V_2 ) ;
V_18 = V_5 -> V_18 ;
V_17 = V_18 -> V_17 ;
if ( F_18 ( F_46 ( V_17 ) &&
F_1 ( V_2 ) >= F_47 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_48 ( struct V_4 * V_5 , void * V_104 )
{
return 0 ;
}
static int F_49 ( struct V_4 * V_5 , void * V_104 )
{
struct V_109 * V_8 = V_104 ;
if ( V_8 -> V_21 . V_9 != V_37 )
F_4 ( L_15 ,
V_5 -> V_18 -> V_17 -> V_110 ,
V_8 -> V_21 . type ,
V_8 -> V_21 . V_9 ,
V_8 -> V_21 . V_10 ,
V_8 -> V_21 . V_11 ) ;
return 0 ;
}
static void F_50 ( unsigned long V_111 )
{
struct V_108 * V_18 = (struct V_108 * ) V_111 ;
struct V_16 * V_17 = V_18 -> V_17 ;
F_51 ( V_17 ) ;
if ( F_52 ( F_46 ( V_17 ) ) ) {
struct V_4 * V_5 ;
int V_112 = 1 ;
F_53 (port, &vp->port_list, list) {
struct V_1 * V_2 ;
V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
if ( F_1 ( V_2 ) <
F_47 ( V_2 ) ) {
V_112 = 0 ;
break;
}
}
if ( V_112 )
F_54 ( V_17 ) ;
}
F_55 ( V_17 ) ;
}
static void F_56 ( void * V_6 , int V_113 )
{
struct V_4 * V_5 = V_6 ;
struct V_15 * V_12 = & V_5 -> V_12 ;
unsigned long V_114 ;
int V_115 , V_53 ;
F_57 ( & V_12 -> V_116 , V_114 ) ;
if ( F_18 ( V_113 == V_117 ||
V_113 == V_118 ) ) {
F_58 ( V_12 , V_113 ) ;
F_59 ( & V_12 -> V_116 , V_114 ) ;
if ( V_113 == V_117 )
F_60 ( V_12 ) ;
return;
}
if ( F_18 ( V_113 != V_119 ) ) {
F_61 ( L_16 , V_113 ) ;
F_59 ( & V_12 -> V_116 , V_114 ) ;
return;
}
V_115 = V_53 = 0 ;
while ( 1 ) {
union {
struct V_7 V_21 ;
V_31 V_120 [ 8 ] ;
} V_104 ;
V_53 = F_62 ( V_12 -> V_13 , & V_104 , sizeof( V_104 ) ) ;
if ( F_18 ( V_53 < 0 ) ) {
if ( V_53 == - V_14 )
F_63 ( V_12 ) ;
break;
}
if ( V_53 == 0 )
break;
F_9 ( V_94 , L_17 ,
V_104 . V_21 . type ,
V_104 . V_21 . V_9 ,
V_104 . V_21 . V_10 ,
V_104 . V_21 . V_11 ) ;
V_53 = F_64 ( V_12 , & V_104 . V_21 ) ;
if ( V_53 < 0 )
break;
if ( F_52 ( V_104 . V_21 . type == V_72 ) ) {
if ( V_104 . V_21 . V_9 == V_23 ) {
V_53 = F_43 ( V_5 , & V_104 ) ;
} else if ( V_104 . V_21 . V_9 == V_37 ) {
V_53 = F_45 ( V_5 , & V_104 ) ;
if ( V_53 > 0 )
V_115 |= V_53 ;
} else if ( V_104 . V_21 . V_9 == V_36 ) {
V_53 = F_48 ( V_5 , & V_104 ) ;
}
} else if ( V_104 . V_21 . type == V_22 ) {
if ( V_104 . V_21 . V_10 == V_121 )
V_53 = F_49 ( V_5 , & V_104 ) ;
else
V_53 = F_65 ( V_12 , & V_104 ) ;
if ( V_53 )
break;
} else {
V_53 = F_3 ( V_5 , & V_104 ) ;
}
if ( V_53 == - V_14 )
break;
}
F_66 ( & V_12 -> V_116 ) ;
if ( F_18 ( V_115 && V_53 != - V_14 ) )
F_67 ( & V_5 -> V_18 -> V_122 ) ;
F_68 ( V_114 ) ;
}
static int F_69 ( struct V_4 * V_5 )
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
. V_76 = V_2 -> V_107 ,
. V_77 = ( T_1 ) - 1 ,
} ;
int V_53 , V_79 ;
int V_80 = 0 ;
V_71 . V_81 = V_2 -> V_40 ;
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
if ( V_80 ++ > V_82 )
break;
} while ( V_53 == - V_84 );
return V_53 ;
}
static inline bool F_70 ( struct V_4 * V_108 )
{
struct V_15 * V_12 = & V_108 -> V_12 ;
return ! ! ( V_12 -> V_123 & V_124 ) ;
}
struct V_4 * F_71 ( struct V_108 * V_18 , struct V_43 * V_45 )
{
unsigned int V_125 = F_72 ( V_45 -> V_48 ) ;
struct V_126 * V_127 = & V_18 -> V_128 [ V_125 ] ;
struct V_4 * V_5 ;
F_73 (port, hp, hash) {
if ( ! F_70 ( V_5 ) )
continue;
if ( F_74 ( V_5 -> V_83 , V_45 -> V_48 ) )
return V_5 ;
}
F_53 (port, &vp->port_list, list) {
if ( ! V_5 -> V_129 )
continue;
if ( ! F_70 ( V_5 ) )
continue;
return V_5 ;
}
return NULL ;
}
struct V_4 * F_75 ( struct V_108 * V_18 , struct V_43 * V_45 )
{
struct V_4 * V_130 ;
unsigned long V_114 ;
F_57 ( & V_18 -> V_116 , V_114 ) ;
V_130 = F_71 ( V_18 , V_45 ) ;
F_59 ( & V_18 -> V_116 , V_114 ) ;
return V_130 ;
}
static int F_76 ( struct V_43 * V_45 , struct V_16 * V_17 )
{
struct V_108 * V_18 = F_77 ( V_17 ) ;
struct V_4 * V_5 = F_75 ( V_18 , V_45 ) ;
struct V_1 * V_2 ;
struct V_87 * V_131 ;
unsigned long V_114 ;
unsigned int V_44 ;
void * V_132 ;
int V_20 , V_53 ;
if ( F_18 ( ! V_5 ) )
goto V_58;
F_57 ( & V_5 -> V_12 . V_116 , V_114 ) ;
V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
if ( F_18 ( F_1 ( V_2 ) < 2 ) ) {
if ( ! F_46 ( V_17 ) ) {
F_78 ( V_17 ) ;
F_79 ( V_17 , L_18 ) ;
V_17 -> V_56 . V_133 ++ ;
}
F_59 ( & V_5 -> V_12 . V_116 , V_114 ) ;
return V_134 ;
}
V_131 = F_80 ( V_2 ) ;
V_132 = V_5 -> V_135 [ V_2 -> V_107 ] . V_136 ;
F_81 ( V_45 , V_132 + V_46 , V_45 -> V_44 ) ;
V_44 = V_45 -> V_44 ;
if ( V_44 < V_55 ) {
V_44 = V_55 ;
memset ( V_132 + V_46 + V_45 -> V_44 , 0 , V_44 - V_45 -> V_44 ) ;
}
V_131 -> V_71 . V_95 = V_137 ;
V_131 -> V_96 = V_44 ;
V_131 -> V_51 = V_5 -> V_135 [ V_2 -> V_107 ] . V_51 ;
for ( V_20 = 0 ; V_20 < V_131 -> V_51 ; V_20 ++ )
V_131 -> V_50 [ V_20 ] = V_5 -> V_135 [ V_2 -> V_107 ] . V_50 [ V_20 ] ;
F_82 () ;
V_131 -> V_71 . V_78 = V_93 ;
V_53 = F_69 ( V_5 ) ;
if ( F_18 ( V_53 < 0 ) ) {
F_83 ( V_17 , L_19 , V_53 ) ;
V_131 -> V_71 . V_78 = V_138 ;
V_17 -> V_56 . V_139 ++ ;
goto V_140;
}
V_17 -> V_56 . V_141 ++ ;
V_17 -> V_56 . V_142 += V_45 -> V_44 ;
V_2 -> V_107 = ( V_2 -> V_107 + 1 ) & ( V_3 - 1 ) ;
if ( F_18 ( F_1 ( V_2 ) < 2 ) ) {
F_78 ( V_17 ) ;
if ( F_1 ( V_2 ) > F_47 ( V_2 ) )
F_54 ( V_17 ) ;
}
F_59 ( & V_5 -> V_12 . V_116 , V_114 ) ;
F_84 ( V_45 ) ;
return V_143 ;
V_140:
F_59 ( & V_5 -> V_12 . V_116 , V_114 ) ;
V_58:
F_84 ( V_45 ) ;
V_17 -> V_56 . V_144 ++ ;
return V_143 ;
}
static void F_85 ( struct V_16 * V_17 )
{
}
static int F_86 ( struct V_16 * V_17 )
{
F_87 ( V_17 ) ;
F_88 ( V_17 ) ;
return 0 ;
}
static int F_89 ( struct V_16 * V_17 )
{
F_78 ( V_17 ) ;
F_90 ( V_17 ) ;
return 0 ;
}
static struct V_145 * F_91 ( struct V_108 * V_18 , T_2 * V_30 )
{
struct V_145 * V_146 ;
for ( V_146 = V_18 -> V_147 ; V_146 ; V_146 = V_146 -> V_148 ) {
if ( F_74 ( V_146 -> V_30 , V_30 ) )
return V_146 ;
}
return NULL ;
}
static void F_92 ( struct V_108 * V_18 , struct V_16 * V_17 )
{
struct V_149 * V_150 ;
F_93 (ha, dev) {
struct V_145 * V_146 ;
V_146 = F_91 ( V_18 , V_150 -> V_30 ) ;
if ( V_146 ) {
V_146 -> V_151 = 1 ;
continue;
}
if ( ! V_146 ) {
V_146 = F_94 ( sizeof( * V_146 ) , V_152 ) ;
if ( ! V_146 )
continue;
memcpy ( V_146 -> V_30 , V_150 -> V_30 , V_153 ) ;
V_146 -> V_151 = 1 ;
V_146 -> V_148 = V_18 -> V_147 ;
V_18 -> V_147 = V_146 ;
}
}
}
static void F_95 ( struct V_108 * V_18 , struct V_4 * V_5 )
{
struct V_109 V_154 ;
struct V_145 * V_146 , * * V_155 ;
int V_156 ;
memset ( & V_154 , 0 , sizeof( V_154 ) ) ;
V_154 . V_21 . type = V_22 ;
V_154 . V_21 . V_9 = V_23 ;
V_154 . V_21 . V_10 = V_121 ;
V_154 . V_21 . V_11 = F_8 ( & V_5 -> V_12 ) ;
V_154 . V_157 = 1 ;
V_156 = 0 ;
for ( V_146 = V_18 -> V_147 ; V_146 ; V_146 = V_146 -> V_148 ) {
if ( V_146 -> V_158 )
continue;
V_146 -> V_158 = 1 ;
memcpy ( & V_154 . V_159 [ V_156 * V_153 ] ,
V_146 -> V_30 , V_153 ) ;
if ( ++ V_156 == V_160 ) {
V_154 . V_161 = V_156 ;
( void ) F_10 ( & V_5 -> V_12 , & V_154 ,
sizeof( V_154 ) ) ;
V_156 = 0 ;
}
}
if ( V_156 ) {
V_154 . V_161 = V_156 ;
( void ) F_10 ( & V_5 -> V_12 , & V_154 , sizeof( V_154 ) ) ;
}
V_154 . V_157 = 0 ;
V_156 = 0 ;
V_155 = & V_18 -> V_147 ;
while ( ( V_146 = * V_155 ) != NULL ) {
if ( V_146 -> V_151 ) {
V_146 -> V_151 = 0 ;
V_155 = & V_146 -> V_148 ;
continue;
}
memcpy ( & V_154 . V_159 [ V_156 * V_153 ] ,
V_146 -> V_30 , V_153 ) ;
if ( ++ V_156 == V_160 ) {
V_154 . V_161 = V_156 ;
( void ) F_10 ( & V_5 -> V_12 , & V_154 ,
sizeof( V_154 ) ) ;
V_156 = 0 ;
}
* V_155 = V_146 -> V_148 ;
F_96 ( V_146 ) ;
}
if ( V_156 ) {
V_154 . V_161 = V_156 ;
( void ) F_10 ( & V_5 -> V_12 , & V_154 , sizeof( V_154 ) ) ;
}
}
static void F_97 ( struct V_16 * V_17 )
{
struct V_108 * V_18 = F_77 ( V_17 ) ;
struct V_4 * V_5 ;
unsigned long V_114 ;
F_57 ( & V_18 -> V_116 , V_114 ) ;
if ( ! F_98 ( & V_18 -> V_162 ) ) {
V_5 = F_99 ( V_18 -> V_162 . V_148 , struct V_4 , V_163 ) ;
if ( V_5 -> V_129 ) {
F_92 ( V_18 , V_17 ) ;
F_95 ( V_18 , V_5 ) ;
}
}
F_59 ( & V_18 -> V_116 , V_114 ) ;
}
static int F_100 ( struct V_16 * V_17 , int V_164 )
{
if ( V_164 != V_165 )
return - V_166 ;
V_17 -> V_33 = V_164 ;
return 0 ;
}
static int F_101 ( struct V_16 * V_17 , void * V_167 )
{
return - V_166 ;
}
static void F_102 ( struct V_16 * V_17 ,
struct V_168 * V_154 )
{
F_103 ( V_154 -> V_169 , V_170 , sizeof( V_154 -> V_169 ) ) ;
F_103 ( V_154 -> V_171 , V_172 , sizeof( V_154 -> V_171 ) ) ;
}
static T_1 F_104 ( struct V_16 * V_17 )
{
struct V_108 * V_18 = F_77 ( V_17 ) ;
return V_18 -> V_173 ;
}
static void F_105 ( struct V_16 * V_17 , T_1 V_174 )
{
struct V_108 * V_18 = F_77 ( V_17 ) ;
V_18 -> V_173 = V_174 ;
}
static void F_106 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_20 ;
V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
if ( V_2 -> V_175 ) {
F_107 ( V_5 -> V_12 . V_13 , V_2 -> V_175 ,
( V_2 -> V_91 * V_2 -> V_86 ) ,
V_2 -> V_50 , V_2 -> V_51 ) ;
V_2 -> V_175 = NULL ;
V_2 -> V_91 = 0 ;
V_2 -> V_86 = 0 ;
V_2 -> V_176 = 0 ;
V_2 -> V_51 = 0 ;
}
for ( V_20 = 0 ; V_20 < V_3 ; V_20 ++ ) {
void * V_136 = V_5 -> V_135 [ V_20 ] . V_136 ;
if ( ! V_136 )
continue;
F_108 ( V_5 -> V_12 . V_13 ,
V_5 -> V_135 [ V_20 ] . V_50 ,
V_5 -> V_135 [ V_20 ] . V_51 ) ;
F_96 ( V_136 ) ;
V_5 -> V_135 [ V_20 ] . V_136 = NULL ;
}
}
static int F_109 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_44 ;
int V_20 , V_53 , V_51 ;
void * V_177 ;
for ( V_20 = 0 ; V_20 < V_3 ; V_20 ++ ) {
void * V_136 = F_94 ( V_34 + 8 , V_178 ) ;
int V_179 = ( V_34 + 7 ) & ~ 7 ;
V_53 = - V_59 ;
if ( ! V_136 )
goto V_180;
V_53 = - V_181 ;
if ( ( unsigned long ) V_136 & ( 8UL - 1 ) ) {
F_4 ( L_20 ) ;
F_96 ( V_136 ) ;
goto V_180;
}
V_53 = F_110 ( V_5 -> V_12 . V_13 , V_136 , V_179 ,
V_5 -> V_135 [ V_20 ] . V_50 , 2 ,
( V_182 |
V_183 |
V_184 ) ) ;
if ( V_53 < 0 ) {
F_96 ( V_136 ) ;
goto V_180;
}
V_5 -> V_135 [ V_20 ] . V_136 = V_136 ;
V_5 -> V_135 [ V_20 ] . V_51 = V_53 ;
}
V_2 = & V_5 -> V_12 . V_38 [ V_42 ] ;
V_44 = ( V_3 *
( sizeof( struct V_87 ) +
( sizeof( struct V_49 ) * 2 ) ) ) ;
V_51 = V_185 ;
V_177 = F_111 ( V_5 -> V_12 . V_13 , V_44 ,
V_2 -> V_50 , & V_51 ,
( V_182 |
V_183 |
V_184 ) ) ;
if ( F_39 ( V_177 ) ) {
V_53 = F_40 ( V_177 ) ;
goto V_180;
}
V_2 -> V_175 = V_177 ;
V_2 -> V_91 = ( sizeof( struct V_87 ) +
( sizeof( struct V_49 ) * 2 ) ) ;
V_2 -> V_86 = V_3 ;
V_2 -> V_107 = V_2 -> V_105 = 0 ;
V_2 -> V_176 = V_3 ;
V_2 -> V_51 = V_51 ;
return 0 ;
V_180:
F_106 ( V_5 ) ;
return V_53 ;
}
static struct V_108 * F_112 ( const V_31 * V_186 )
{
struct V_16 * V_17 ;
struct V_108 * V_18 ;
int V_53 , V_20 ;
V_17 = F_113 ( sizeof( * V_18 ) ) ;
if ( ! V_17 )
return F_35 ( - V_59 ) ;
for ( V_20 = 0 ; V_20 < V_153 ; V_20 ++ )
V_17 -> V_32 [ V_20 ] = ( * V_186 >> ( 5 - V_20 ) * 8 ) & 0xff ;
V_18 = F_77 ( V_17 ) ;
F_114 ( & V_18 -> V_116 ) ;
F_115 ( & V_18 -> V_122 , F_50 , ( unsigned long ) V_18 ) ;
V_18 -> V_17 = V_17 ;
F_116 ( & V_18 -> V_162 ) ;
for ( V_20 = 0 ; V_20 < V_187 ; V_20 ++ )
F_117 ( & V_18 -> V_128 [ V_20 ] ) ;
F_116 ( & V_18 -> V_163 ) ;
V_18 -> V_186 = * V_186 ;
V_17 -> V_188 = & V_189 ;
V_17 -> V_190 = & V_191 ;
V_17 -> V_192 = V_193 ;
V_53 = F_118 ( V_17 ) ;
if ( V_53 ) {
F_4 ( L_21 ) ;
goto V_194;
}
F_83 ( V_17 , L_22 , V_17 -> V_32 ) ;
F_119 ( & V_18 -> V_163 , & V_195 ) ;
return V_18 ;
V_194:
F_120 ( V_17 ) ;
return F_35 ( V_53 ) ;
}
static struct V_108 * F_121 ( const V_31 * V_186 )
{
struct V_108 * V_196 , * V_18 ;
F_122 ( & V_197 ) ;
V_18 = NULL ;
F_53 (iter, &vnet_list, list) {
if ( V_196 -> V_186 == * V_186 ) {
V_18 = V_196 ;
break;
}
}
if ( ! V_18 )
V_18 = F_112 ( V_186 ) ;
F_123 ( & V_197 ) ;
return V_18 ;
}
static void F_124 ( void )
{
struct V_108 * V_18 ;
struct V_16 * V_17 ;
F_122 ( & V_197 ) ;
while ( ! F_98 ( & V_195 ) ) {
V_18 = F_125 ( & V_195 , struct V_108 , V_163 ) ;
F_126 ( & V_18 -> V_163 ) ;
V_17 = V_18 -> V_17 ;
F_127 ( & V_18 -> V_122 ) ;
F_128 ( ! F_98 ( & V_18 -> V_162 ) ) ;
F_129 ( V_17 ) ;
F_120 ( V_17 ) ;
}
F_123 ( & V_197 ) ;
}
static struct V_108 * F_130 ( struct V_198 * V_127 ,
V_31 V_199 )
{
const V_31 * V_186 = NULL ;
V_31 V_200 ;
F_131 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
V_31 V_201 = F_132 ( V_127 , V_200 ) ;
const char * V_110 ;
V_110 = F_133 ( V_127 , V_201 , L_23 , NULL ) ;
if ( ! V_110 || strcmp ( V_110 , L_24 ) )
continue;
V_186 = F_133 ( V_127 , V_201 ,
V_202 , NULL ) ;
if ( V_186 )
break;
}
if ( ! V_186 )
return F_35 ( - V_203 ) ;
return F_121 ( V_186 ) ;
}
static void F_134 ( void )
{
F_135 ( V_204 L_25 , V_171 ) ;
}
static int F_136 ( struct V_205 * V_206 , const struct V_207 * V_208 )
{
struct V_198 * V_127 ;
struct V_4 * V_5 ;
unsigned long V_114 ;
struct V_108 * V_18 ;
const V_31 * V_209 ;
int V_44 , V_20 , V_53 , V_129 ;
F_134 () ;
V_127 = F_137 () ;
V_18 = F_130 ( V_127 , V_206 -> V_210 ) ;
if ( F_39 ( V_18 ) ) {
F_4 ( L_26 ) ;
V_53 = F_40 ( V_18 ) ;
goto V_211;
}
V_209 = F_133 ( V_127 , V_206 -> V_210 , V_212 , & V_44 ) ;
V_53 = - V_203 ;
if ( ! V_209 ) {
F_4 ( L_27 , V_212 ) ;
goto V_211;
}
V_5 = F_94 ( sizeof( * V_5 ) , V_178 ) ;
V_53 = - V_59 ;
if ( ! V_5 )
goto V_211;
for ( V_20 = 0 ; V_20 < V_153 ; V_20 ++ )
V_5 -> V_83 [ V_20 ] = ( * V_209 >> ( 5 - V_20 ) * 8 ) & 0xff ;
V_5 -> V_18 = V_18 ;
V_53 = F_138 ( & V_5 -> V_12 , V_206 , V_213 ,
V_214 , F_139 ( V_214 ) ,
& V_215 , V_18 -> V_17 -> V_110 ) ;
if ( V_53 )
goto V_216;
V_53 = F_140 ( & V_5 -> V_12 , & V_217 , V_5 ) ;
if ( V_53 )
goto V_216;
V_53 = F_109 ( V_5 ) ;
if ( V_53 )
goto V_218;
F_141 ( & V_5 -> V_125 ) ;
F_116 ( & V_5 -> V_163 ) ;
V_129 = 0 ;
if ( F_133 ( V_127 , V_206 -> V_210 , L_28 , NULL ) != NULL )
V_129 = 1 ;
V_5 -> V_129 = V_129 ;
F_57 ( & V_18 -> V_116 , V_114 ) ;
if ( V_129 )
F_119 ( & V_5 -> V_163 , & V_18 -> V_162 ) ;
else
F_142 ( & V_5 -> V_163 , & V_18 -> V_162 ) ;
F_143 ( & V_5 -> V_125 , & V_18 -> V_128 [ F_72 ( V_5 -> V_83 ) ] ) ;
F_59 ( & V_18 -> V_116 , V_114 ) ;
F_144 ( & V_206 -> V_17 , V_5 ) ;
F_30 ( L_29 ,
V_18 -> V_17 -> V_110 , V_5 -> V_83 , V_129 ? L_30 : L_31 ) ;
F_60 ( & V_5 -> V_12 ) ;
F_145 ( V_127 ) ;
return 0 ;
V_218:
F_146 ( & V_5 -> V_12 ) ;
V_216:
F_96 ( V_5 ) ;
V_211:
F_145 ( V_127 ) ;
return V_53 ;
}
static int F_147 ( struct V_205 * V_206 )
{
struct V_4 * V_5 = F_148 ( & V_206 -> V_17 ) ;
if ( V_5 ) {
struct V_108 * V_18 = V_5 -> V_18 ;
unsigned long V_114 ;
F_149 ( & V_5 -> V_12 . V_219 ) ;
F_57 ( & V_18 -> V_116 , V_114 ) ;
F_126 ( & V_5 -> V_163 ) ;
F_150 ( & V_5 -> V_125 ) ;
F_59 ( & V_18 -> V_116 , V_114 ) ;
F_106 ( V_5 ) ;
F_146 ( & V_5 -> V_12 ) ;
F_144 ( & V_206 -> V_17 , NULL ) ;
F_96 ( V_5 ) ;
}
return 0 ;
}
static int T_3 F_151 ( void )
{
return F_152 ( & V_220 ) ;
}
static void T_4 F_153 ( void )
{
F_154 ( & V_220 ) ;
F_124 () ;
}

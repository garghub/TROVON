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
int V_20 = V_21 ;
int V_22 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_23 . type = V_24 ;
V_8 . V_23 . V_9 = V_25 ;
V_8 . V_23 . V_10 = V_26 ;
V_8 . V_23 . V_11 = F_8 ( V_12 ) ;
if ( F_9 ( V_12 , 1 , 2 ) )
V_8 . V_27 = V_28 ;
else
V_8 . V_27 = V_29 ;
V_8 . V_30 = V_31 ;
V_8 . V_32 = 0 ;
for ( V_22 = 0 ; V_22 < 6 ; V_22 ++ )
V_8 . V_33 |= ( V_34 ) V_17 -> V_35 [ V_22 ] << ( ( 5 - V_22 ) * 8 ) ;
if ( F_10 ( V_12 , 1 , 3 ) ) {
if ( V_5 -> V_36 ) {
V_5 -> V_36 = F_11 ( V_37 , V_5 -> V_36 ) ;
V_8 . V_38 = V_5 -> V_36 ;
} else {
V_5 -> V_36 = V_37 ;
V_8 . V_38 = V_5 -> V_36 ;
}
if ( F_12 ( V_12 , 1 , 6 ) )
V_8 . V_39 = V_40 ;
} else if ( F_9 ( V_12 , 1 , 3 ) ) {
V_8 . V_38 = V_20 ;
} else {
V_8 . V_38 = V_20 + V_41 ;
}
V_8 . V_42 = V_43 ;
V_8 . V_44 = 0 ;
F_13 ( V_45 , L_3
L_4
L_5 ,
V_8 . V_27 , V_8 . V_30 ,
( unsigned long long ) V_8 . V_33 ,
V_8 . V_32 , V_8 . V_42 , V_8 . V_39 ,
( unsigned long long ) V_8 . V_38 , V_8 . V_44 , V_8 . V_46 ) ;
return F_14 ( V_12 , & V_8 , sizeof( V_8 ) ) ;
}
static int F_15 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
V_34 V_47 ;
T_2 V_27 ;
F_13 ( V_45 , L_6
L_4
L_7 ,
V_8 -> V_27 , V_8 -> V_30 ,
( unsigned long long ) V_8 -> V_33 ,
V_8 -> V_32 , V_8 -> V_42 , V_8 -> V_39 ,
( unsigned long long ) V_8 -> V_38 , V_5 -> V_36 , V_8 -> V_44 ,
V_8 -> V_46 ) ;
V_8 -> V_23 . V_11 = F_8 ( V_12 ) ;
V_27 = V_8 -> V_27 ;
if ( F_9 ( V_12 , 1 , 2 ) && V_27 == V_28 )
V_27 = V_29 ;
if ( F_9 ( V_12 , 1 , 3 ) ) {
V_47 = V_21 ;
} else if ( F_10 ( V_12 , 1 , 3 ) ) {
V_47 = V_5 -> V_36 ? V_5 -> V_36 : V_37 ;
V_47 = F_11 ( V_8 -> V_38 , V_47 ) ;
V_8 -> V_38 = V_47 ;
} else {
V_47 = V_21 + V_41 ;
}
V_5 -> V_36 = V_47 ;
if ( F_12 ( V_12 , 1 , 6 ) ) {
V_8 -> V_27 = V_29 ;
V_8 -> V_39 = V_40 ;
}
if ( ! ( V_27 | V_29 ) ||
V_8 -> V_30 != V_31 ||
V_8 -> V_38 != V_47 ) {
F_13 ( V_45 , L_8 ) ;
V_8 -> V_23 . V_9 = V_48 ;
( void ) F_14 ( V_12 , V_8 , sizeof( * V_8 ) ) ;
return - V_14 ;
} else {
F_13 ( V_45 , L_9
L_10
L_11 ,
V_8 -> V_27 , V_8 -> V_30 ,
( unsigned long long ) V_8 -> V_33 ,
V_8 -> V_32 , V_8 -> V_42 , V_8 -> V_39 ,
( unsigned long long ) V_8 -> V_38 , V_5 -> V_36 , V_8 -> V_44 ,
V_8 -> V_46 ) ;
V_8 -> V_23 . V_9 = V_49 ;
return F_14 ( V_12 , V_8 , sizeof( * V_8 ) ) ;
}
}
static int F_16 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
F_13 ( V_45 , L_12 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
F_13 ( V_45 , L_13 ) ;
return - V_14 ;
}
static int F_18 ( struct V_15 * V_12 , void * V_6 )
{
struct V_19 * V_8 = V_6 ;
switch ( V_8 -> V_23 . V_9 ) {
case V_25 :
return F_15 ( V_12 , V_8 ) ;
case V_49 :
return F_16 ( V_12 , V_8 ) ;
case V_48 :
return F_17 ( V_12 , V_8 ) ;
default:
return - V_14 ;
}
}
static void F_19 ( struct V_15 * V_12 )
{
struct V_1 * V_2 ;
V_2 = & V_12 -> V_50 [ V_51 ] ;
V_2 -> V_52 = V_2 -> V_53 = 1 ;
V_2 = & V_12 -> V_50 [ V_54 ] ;
V_2 -> V_52 = V_2 -> V_53 = 1 ;
}
static struct V_55 * F_20 ( struct V_16 * V_17 ,
unsigned int V_56 )
{
struct V_55 * V_57 = F_21 ( V_17 , V_56 + V_58 + 8 + 8 ) ;
unsigned long V_33 , V_59 ;
if ( F_22 ( ! V_57 ) )
return NULL ;
V_33 = ( unsigned long ) V_57 -> V_60 ;
V_59 = ( ( V_33 + 7UL ) & ~ 7UL ) - V_33 ;
if ( V_59 )
F_23 ( V_57 , V_59 ) ;
return V_57 ;
}
static int F_24 ( struct V_4 * V_5 , unsigned int V_56 ,
struct V_61 * V_62 , int V_63 )
{
struct V_16 * V_17 = V_5 -> V_18 -> V_17 ;
unsigned int V_64 ;
struct V_55 * V_57 ;
int V_65 ;
V_65 = - V_66 ;
if ( F_22 ( V_56 < V_67 || V_56 > V_5 -> V_36 ) ) {
V_17 -> V_68 . V_69 ++ ;
goto V_70;
}
V_57 = F_20 ( V_17 , V_56 ) ;
V_65 = - V_71 ;
if ( F_22 ( ! V_57 ) ) {
V_17 -> V_68 . V_72 ++ ;
goto V_70;
}
V_64 = ( V_56 + V_58 + 7U ) & ~ 7U ;
F_25 ( V_57 , V_64 ) ;
V_65 = F_26 ( V_5 -> V_12 . V_13 , V_73 ,
V_57 -> V_60 , V_64 , 0 ,
V_62 , V_63 ) ;
if ( F_22 ( V_65 < 0 ) ) {
V_17 -> V_68 . V_74 ++ ;
goto V_75;
}
F_27 ( V_57 , V_58 ) ;
F_28 ( V_57 , V_56 ) ;
V_57 -> V_76 = F_29 ( V_57 , V_17 ) ;
V_17 -> V_68 . V_77 ++ ;
V_17 -> V_68 . V_78 += V_56 ;
F_30 ( V_57 ) ;
return 0 ;
V_75:
F_31 ( V_57 ) ;
V_70:
V_17 -> V_68 . V_79 ++ ;
return V_65 ;
}
static int F_32 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_80 , T_1 V_81 , T_2 V_1 )
{
struct V_82 V_83 = {
. V_23 = {
. type = V_84 ,
. V_9 = V_49 ,
. V_10 = V_85 ,
. V_11 = F_8 ( & V_5 -> V_12 ) ,
} ,
. V_86 = V_2 -> V_87 ,
. V_88 = V_80 ,
. V_89 = V_81 ,
. V_90 = V_1 ,
} ;
int V_65 , V_91 ;
int V_92 = 0 ;
V_83 . V_93 = V_2 -> V_52 ;
V_91 = 1 ;
do {
V_65 = F_14 ( & V_5 -> V_12 , & V_83 , sizeof( V_83 ) ) ;
if ( V_65 > 0 ) {
V_2 -> V_52 ++ ;
break;
}
F_33 ( V_91 ) ;
if ( ( V_91 <<= 1 ) > 128 )
V_91 = 128 ;
if ( V_92 ++ > V_94 ) {
F_34 ( L_14 ,
V_5 -> V_95 [ 0 ] , V_5 -> V_95 [ 1 ] ,
V_5 -> V_95 [ 2 ] , V_5 -> V_95 [ 3 ] ,
V_5 -> V_95 [ 4 ] , V_5 -> V_95 [ 5 ] ) ;
break;
}
} while ( V_65 == - V_96 );
if ( V_65 <= 0 && V_1 == V_97 ) {
V_5 -> V_98 = V_81 ;
V_5 -> V_99 = true ;
} else {
V_5 -> V_98 = 0 ;
V_5 -> V_99 = false ;
}
return V_65 ;
}
static T_1 F_35 ( T_1 V_100 , struct V_1 * V_2 )
{
if ( ++ V_100 == V_2 -> V_101 )
V_100 = 0 ;
return V_100 ;
}
static T_1 F_36 ( T_1 V_100 , struct V_1 * V_2 )
{
if ( V_100 == 0 )
V_100 = V_2 -> V_101 - 1 ;
else
V_100 -- ;
return V_100 ;
}
static struct V_102 * F_37 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_103 )
{
struct V_102 * V_104 = V_5 -> V_12 . V_105 ;
int V_65 ;
V_65 = F_38 ( V_5 -> V_12 . V_13 , V_104 , V_2 -> V_106 ,
( V_103 * V_2 -> V_106 ) ,
V_2 -> V_62 , V_2 -> V_63 ) ;
if ( V_65 < 0 )
return F_39 ( V_65 ) ;
return V_104 ;
}
static int F_40 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_102 * V_104 ,
T_1 V_103 )
{
int V_65 ;
V_65 = F_41 ( V_5 -> V_12 . V_13 , V_104 , V_2 -> V_106 ,
( V_103 * V_2 -> V_106 ) ,
V_2 -> V_62 , V_2 -> V_63 ) ;
if ( V_65 < 0 )
return V_65 ;
return 0 ;
}
static int F_42 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_103 , int * V_107 )
{
struct V_102 * V_104 = F_37 ( V_5 , V_2 , V_103 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_65 ;
if ( F_43 ( V_104 ) )
return F_44 ( V_104 ) ;
if ( V_104 -> V_83 . V_90 != V_108 )
return 1 ;
F_45 () ;
F_13 ( V_109 , L_15 ,
V_104 -> V_83 . V_90 , V_104 -> V_83 . V_110 ,
V_104 -> V_111 , V_104 -> V_63 ,
V_104 -> V_62 [ 0 ] . V_112 ,
V_104 -> V_62 [ 0 ] . V_113 ) ;
V_65 = F_24 ( V_5 , V_104 -> V_111 , V_104 -> V_62 , V_104 -> V_63 ) ;
if ( V_65 == - V_14 )
return V_65 ;
V_104 -> V_83 . V_90 = V_114 ;
V_65 = F_40 ( V_5 , V_2 , V_104 , V_103 ) ;
if ( V_65 < 0 )
return V_65 ;
* V_107 = V_104 -> V_83 . V_110 ;
return 0 ;
}
static int F_46 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_80 , T_1 V_81 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_115 = - 1 , V_116 = - 1 ;
V_81 = ( V_81 == ( T_1 ) - 1 ) ? F_36 ( V_80 , V_2 ) : F_35 ( V_81 , V_2 ) ;
F_13 ( V_109 , L_16 , V_80 , V_81 ) ;
while ( V_80 != V_81 ) {
int V_110 = 0 , V_65 = F_42 ( V_5 , V_2 , V_80 , & V_110 ) ;
if ( V_65 == - V_14 )
return V_65 ;
if ( V_65 != 0 )
break;
if ( V_115 == - 1 )
V_115 = V_80 ;
V_116 = V_80 ;
V_80 = F_35 ( V_80 , V_2 ) ;
if ( V_110 && V_80 != V_81 ) {
V_65 = F_32 ( V_5 , V_2 , V_115 , V_116 ,
V_117 ) ;
if ( V_65 == - V_14 )
return V_65 ;
V_115 = - 1 ;
}
}
if ( F_22 ( V_115 == - 1 ) )
V_115 = V_116 = F_36 ( V_80 , V_2 ) ;
return F_32 ( V_5 , V_2 , V_115 , V_116 , V_97 ) ;
}
static int F_47 ( struct V_4 * V_5 , void * V_118 )
{
struct V_82 * V_8 = V_118 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_50 [ V_51 ] ;
struct V_15 * V_12 = & V_5 -> V_12 ;
F_13 ( V_109 , L_17 ,
V_8 -> V_23 . V_10 , V_8 -> V_93 , V_2 -> V_53 ) ;
if ( F_22 ( V_8 -> V_23 . V_10 != V_85 ) )
return 0 ;
if ( F_22 ( V_8 -> V_93 != V_2 -> V_53 ) ) {
F_4 ( L_18 ,
V_8 -> V_93 , V_2 -> V_53 ) ;
return 0 ;
}
V_2 -> V_53 ++ ;
return F_46 ( V_5 , V_2 , V_8 -> V_88 , V_8 -> V_89 ) ;
}
static int F_48 ( struct V_1 * V_2 , T_1 V_81 )
{
T_1 V_100 = V_2 -> V_119 ;
int V_120 = 0 ;
while ( V_100 != V_2 -> V_121 ) {
if ( V_100 == V_81 ) {
V_120 = 1 ;
break;
}
V_100 = F_35 ( V_100 , V_2 ) ;
}
return V_120 ;
}
static int F_49 ( struct V_4 * V_5 , void * V_118 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_50 [ V_54 ] ;
struct V_82 * V_8 = V_118 ;
struct V_16 * V_17 ;
struct V_122 * V_18 ;
T_1 V_81 ;
struct V_102 * V_104 ;
if ( F_22 ( V_8 -> V_23 . V_10 != V_85 ) )
return 0 ;
V_81 = V_8 -> V_89 ;
if ( F_22 ( ! F_48 ( V_2 , V_81 ) ) )
return 0 ;
V_2 -> V_119 = F_35 ( V_81 , V_2 ) ;
V_104 = F_50 ( V_2 , V_2 -> V_119 ) ;
if ( V_104 -> V_83 . V_90 == V_108 && V_5 -> V_123 ) {
if ( F_51 ( V_5 , V_2 -> V_119 ) > 0 )
V_5 -> V_123 = false ;
else
V_5 -> V_123 = true ;
} else {
V_5 -> V_123 = true ;
}
V_18 = V_5 -> V_18 ;
V_17 = V_18 -> V_17 ;
if ( F_22 ( F_52 ( V_17 ) &&
F_1 ( V_2 ) >= F_53 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 , void * V_118 )
{
return 0 ;
}
static int F_55 ( struct V_4 * V_5 , void * V_118 )
{
struct V_124 * V_8 = V_118 ;
if ( V_8 -> V_23 . V_9 != V_49 )
F_4 ( L_19 ,
V_5 -> V_18 -> V_17 -> V_125 ,
V_8 -> V_23 . type ,
V_8 -> V_23 . V_9 ,
V_8 -> V_23 . V_10 ,
V_8 -> V_23 . V_11 ) ;
return 0 ;
}
static void F_56 ( unsigned long V_126 )
{
struct V_122 * V_18 = (struct V_122 * ) V_126 ;
struct V_16 * V_17 = V_18 -> V_17 ;
F_57 ( V_17 ) ;
if ( F_58 ( F_52 ( V_17 ) ) ) {
struct V_4 * V_5 ;
int V_127 = 1 ;
F_59 (port, &vp->port_list, list) {
struct V_1 * V_2 ;
V_2 = & V_5 -> V_12 . V_50 [ V_54 ] ;
if ( F_1 ( V_2 ) <
F_53 ( V_2 ) ) {
V_127 = 0 ;
break;
}
}
if ( V_127 )
F_60 ( V_17 ) ;
}
F_61 ( V_17 ) ;
}
static void F_62 ( void * V_6 , int V_128 )
{
struct V_4 * V_5 = V_6 ;
struct V_15 * V_12 = & V_5 -> V_12 ;
unsigned long V_129 ;
int V_130 , V_65 ;
F_63 ( & V_12 -> V_131 , V_129 ) ;
if ( F_22 ( V_128 == V_132 ||
V_128 == V_133 ) ) {
F_64 ( V_12 , V_128 ) ;
F_65 ( & V_12 -> V_131 , V_129 ) ;
if ( V_128 == V_132 ) {
V_5 -> V_36 = 0 ;
F_66 ( V_12 ) ;
}
return;
}
if ( F_22 ( V_128 != V_134 ) ) {
F_67 ( L_20 , V_128 ) ;
F_65 ( & V_12 -> V_131 , V_129 ) ;
return;
}
V_130 = V_65 = 0 ;
while ( 1 ) {
union {
struct V_7 V_23 ;
V_34 V_135 [ 8 ] ;
} V_118 ;
V_65 = F_68 ( V_12 -> V_13 , & V_118 , sizeof( V_118 ) ) ;
if ( F_22 ( V_65 < 0 ) ) {
if ( V_65 == - V_14 )
F_69 ( V_12 ) ;
break;
}
if ( V_65 == 0 )
break;
F_13 ( V_109 , L_21 ,
V_118 . V_23 . type ,
V_118 . V_23 . V_9 ,
V_118 . V_23 . V_10 ,
V_118 . V_23 . V_11 ) ;
V_65 = F_70 ( V_12 , & V_118 . V_23 ) ;
if ( V_65 < 0 )
break;
if ( F_58 ( V_118 . V_23 . type == V_84 ) ) {
if ( V_118 . V_23 . V_9 == V_25 ) {
V_65 = F_47 ( V_5 , & V_118 ) ;
} else if ( V_118 . V_23 . V_9 == V_49 ) {
V_65 = F_49 ( V_5 , & V_118 ) ;
if ( V_65 > 0 )
V_130 |= V_65 ;
} else if ( V_118 . V_23 . V_9 == V_48 ) {
V_65 = F_54 ( V_5 , & V_118 ) ;
}
} else if ( V_118 . V_23 . type == V_24 ) {
if ( V_118 . V_23 . V_10 == V_136 )
V_65 = F_55 ( V_5 , & V_118 ) ;
else
V_65 = F_71 ( V_12 , & V_118 ) ;
if ( V_65 )
break;
} else {
V_65 = F_3 ( V_5 , & V_118 ) ;
}
if ( V_65 == - V_14 )
break;
}
F_72 ( & V_12 -> V_131 ) ;
if ( F_22 ( V_130 && V_65 != - V_14 ) )
F_73 ( & V_5 -> V_18 -> V_137 ) ;
F_74 ( V_129 ) ;
}
static int F_51 ( struct V_4 * V_5 , T_1 V_80 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_50 [ V_54 ] ;
struct V_82 V_83 = {
. V_23 = {
. type = V_84 ,
. V_9 = V_25 ,
. V_10 = V_85 ,
. V_11 = F_8 ( & V_5 -> V_12 ) ,
} ,
. V_86 = V_2 -> V_87 ,
. V_88 = V_80 ,
. V_89 = ( T_1 ) - 1 ,
} ;
int V_65 , V_91 ;
int V_92 = 0 ;
if ( V_5 -> V_99 ) {
V_65 = F_32 ( V_5 ,
& V_5 -> V_12 . V_50 [ V_51 ] ,
V_5 -> V_98 , - 1 ,
V_97 ) ;
if ( V_65 <= 0 )
return V_65 ;
}
V_83 . V_93 = V_2 -> V_52 ;
V_91 = 1 ;
do {
V_65 = F_14 ( & V_5 -> V_12 , & V_83 , sizeof( V_83 ) ) ;
if ( V_65 > 0 ) {
V_2 -> V_52 ++ ;
break;
}
F_33 ( V_91 ) ;
if ( ( V_91 <<= 1 ) > 128 )
V_91 = 128 ;
if ( V_92 ++ > V_94 )
break;
} while ( V_65 == - V_96 );
return V_65 ;
}
static inline bool F_75 ( struct V_4 * V_122 )
{
struct V_15 * V_12 = & V_122 -> V_12 ;
return ! ! ( V_12 -> V_138 & V_139 ) ;
}
struct V_4 * F_76 ( struct V_122 * V_18 , struct V_55 * V_57 )
{
unsigned int V_140 = F_77 ( V_57 -> V_60 ) ;
struct V_141 * V_142 = & V_18 -> V_143 [ V_140 ] ;
struct V_4 * V_5 ;
F_78 (port, hp, hash) {
if ( ! F_75 ( V_5 ) )
continue;
if ( F_79 ( V_5 -> V_95 , V_57 -> V_60 ) )
return V_5 ;
}
F_59 (port, &vp->port_list, list) {
if ( ! V_5 -> V_144 )
continue;
if ( ! F_75 ( V_5 ) )
continue;
return V_5 ;
}
return NULL ;
}
struct V_4 * F_80 ( struct V_122 * V_18 , struct V_55 * V_57 )
{
struct V_4 * V_145 ;
unsigned long V_129 ;
F_63 ( & V_18 -> V_131 , V_129 ) ;
V_145 = F_76 ( V_18 , V_57 ) ;
F_65 ( & V_18 -> V_131 , V_129 ) ;
return V_145 ;
}
static struct V_55 * F_81 ( struct V_4 * V_5 ,
unsigned * V_146 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_50 [ V_54 ] ;
struct V_55 * V_57 = NULL ;
int V_22 , V_147 ;
* V_146 = 0 ;
V_147 = V_2 -> V_121 - 1 ;
if ( V_147 < 0 )
V_147 = V_3 - 1 ;
for ( V_22 = 0 ; V_22 < V_3 ; ++ V_22 ) {
struct V_102 * V_148 ;
V_148 = F_50 ( V_2 , V_147 ) ;
if ( V_148 -> V_83 . V_90 == V_114 ) {
if ( V_5 -> V_149 [ V_147 ] . V_57 ) {
F_82 ( V_5 -> V_149 [ V_147 ] . V_57 -> V_150 ) ;
V_5 -> V_149 [ V_147 ] . V_57 -> V_150 = V_57 ;
V_57 = V_5 -> V_149 [ V_147 ] . V_57 ;
V_5 -> V_149 [ V_147 ] . V_57 = NULL ;
F_83 ( V_5 -> V_12 . V_13 ,
V_5 -> V_149 [ V_147 ] . V_62 ,
V_5 -> V_149 [ V_147 ] . V_63 ) ;
}
V_148 -> V_83 . V_90 = V_151 ;
} else if ( V_148 -> V_83 . V_90 == V_108 ) {
( * V_146 ) ++ ;
} else if ( V_148 -> V_83 . V_90 == V_151 ) {
break;
}
-- V_147 ;
if ( V_147 < 0 )
V_147 = V_3 - 1 ;
}
return V_57 ;
}
static inline void F_84 ( struct V_55 * V_57 )
{
struct V_55 * V_150 ;
while ( V_57 ) {
V_150 = V_57 -> V_150 ;
V_57 -> V_150 = NULL ;
F_85 ( V_57 ) ;
V_57 = V_150 ;
}
}
static void F_86 ( unsigned long V_152 )
{
struct V_4 * V_5 = (struct V_4 * ) V_152 ;
struct V_55 * V_153 ;
unsigned V_146 ;
unsigned long V_129 ;
F_63 ( & V_5 -> V_12 . V_131 , V_129 ) ;
V_153 = F_81 ( V_5 , & V_146 ) ;
F_65 ( & V_5 -> V_12 . V_131 , V_129 ) ;
F_84 ( V_153 ) ;
if ( V_146 )
( void ) F_87 ( & V_5 -> V_154 ,
V_155 + V_156 ) ;
else
F_88 ( & V_5 -> V_154 ) ;
}
static inline struct V_55 * F_89 ( struct V_55 * V_57 , void * * V_157 ,
int * V_158 )
{
struct V_55 * V_159 ;
int V_56 , V_160 ;
V_56 = V_57 -> V_56 ;
V_160 = 0 ;
if ( V_56 < V_67 ) {
V_160 += V_67 - V_57 -> V_56 ;
V_56 += V_160 ;
}
V_56 += V_58 ;
V_160 += 8 - ( V_56 & 7 ) ;
V_56 += 8 - ( V_56 & 7 ) ;
if ( ( ( unsigned long ) V_57 -> V_60 & 7 ) != V_58 ||
F_90 ( V_57 ) < V_160 ||
F_91 ( V_57 ) < V_58 ) {
V_159 = F_20 ( V_57 -> V_17 , V_57 -> V_56 ) ;
F_23 ( V_159 , V_58 ) ;
if ( F_92 ( V_57 , 0 , V_159 -> V_60 , V_57 -> V_56 ) ) {
F_85 ( V_159 ) ;
F_85 ( V_57 ) ;
return NULL ;
}
( void ) F_25 ( V_159 , V_57 -> V_56 ) ;
F_85 ( V_57 ) ;
V_57 = V_159 ;
}
* V_157 = V_57 -> V_60 - V_58 ;
* V_158 = V_56 ;
return V_57 ;
}
static int F_93 ( struct V_55 * V_57 , struct V_16 * V_17 )
{
struct V_122 * V_18 = F_94 ( V_17 ) ;
struct V_4 * V_5 = F_80 ( V_18 , V_57 ) ;
struct V_1 * V_2 ;
struct V_102 * V_148 ;
unsigned long V_129 ;
unsigned int V_56 ;
struct V_55 * V_153 = NULL ;
int V_22 , V_65 , V_147 ;
void * V_80 = NULL ;
int V_161 = 0 ;
unsigned V_146 = 0 ;
if ( F_22 ( ! V_5 ) )
goto V_70;
V_57 = F_89 ( V_57 , & V_80 , & V_161 ) ;
if ( F_22 ( ! V_57 ) )
goto V_70;
if ( V_57 -> V_56 > V_5 -> V_36 ) {
unsigned long V_47 = V_5 -> V_36 - V_162 ;
if ( F_12 ( & V_5 -> V_12 , 1 , 3 ) )
V_47 -= V_41 ;
if ( V_57 -> V_76 == F_95 ( V_163 ) ) {
struct V_164 V_165 ;
struct V_166 * V_167 = NULL ;
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
V_165 . V_168 = V_17 -> V_169 ;
V_165 . V_170 = F_96 ( F_97 ( V_57 ) -> V_171 ) ;
V_165 . V_172 = F_97 ( V_57 ) -> V_172 ;
V_165 . V_173 = F_97 ( V_57 ) -> V_173 ;
V_167 = F_98 ( F_99 ( V_17 ) , & V_165 ) ;
if ( ! F_43 ( V_167 ) ) {
F_100 ( V_57 , & V_167 -> V_174 ) ;
F_101 ( V_57 , V_175 ,
V_176 ,
F_102 ( V_47 ) ) ;
}
}
#if F_103 ( V_177 )
else if ( V_57 -> V_76 == F_95 ( V_178 ) )
F_104 ( V_57 , V_179 , 0 , V_47 ) ;
#endif
goto V_70;
}
F_63 ( & V_5 -> V_12 . V_131 , V_129 ) ;
V_2 = & V_5 -> V_12 . V_50 [ V_54 ] ;
if ( F_22 ( F_1 ( V_2 ) < 1 ) ) {
if ( ! F_52 ( V_17 ) ) {
F_105 ( V_17 ) ;
F_106 ( V_17 , L_22 ) ;
V_17 -> V_68 . V_180 ++ ;
}
F_65 ( & V_5 -> V_12 . V_131 , V_129 ) ;
return V_181 ;
}
V_148 = F_107 ( V_2 ) ;
V_147 = V_2 -> V_121 ;
V_153 = F_81 ( V_5 , & V_146 ) ;
F_82 ( V_5 -> V_149 [ V_147 ] . V_57 ) ;
V_56 = V_57 -> V_56 ;
if ( V_56 < V_67 )
V_56 = V_67 ;
V_5 -> V_149 [ V_147 ] . V_57 = V_57 ;
V_57 = NULL ;
V_65 = F_108 ( V_5 -> V_12 . V_13 , V_80 , V_161 ,
V_5 -> V_149 [ V_147 ] . V_62 , V_182 ,
( V_183 | V_184 | V_185 ) ) ;
if ( V_65 < 0 ) {
F_109 ( V_17 , L_23 , V_65 ) ;
goto V_186;
}
V_5 -> V_149 [ V_147 ] . V_63 = V_65 ;
V_148 -> V_83 . V_110 = V_187 ;
V_148 -> V_111 = V_56 ;
V_148 -> V_63 = V_5 -> V_149 [ V_147 ] . V_63 ;
for ( V_22 = 0 ; V_22 < V_148 -> V_63 ; V_22 ++ )
V_148 -> V_62 [ V_22 ] = V_5 -> V_149 [ V_147 ] . V_62 [ V_22 ] ;
F_110 () ;
V_148 -> V_83 . V_90 = V_108 ;
if ( ! V_5 -> V_123 )
goto V_188;
V_65 = F_51 ( V_5 , V_2 -> V_119 ) ;
if ( F_22 ( V_65 < 0 ) ) {
F_109 ( V_17 , L_24 , V_65 ) ;
V_148 -> V_83 . V_90 = V_151 ;
V_17 -> V_68 . V_189 ++ ;
goto V_186;
}
V_188:
V_5 -> V_123 = false ;
V_17 -> V_68 . V_190 ++ ;
V_17 -> V_68 . V_191 += V_5 -> V_149 [ V_147 ] . V_57 -> V_56 ;
V_2 -> V_121 = ( V_2 -> V_121 + 1 ) & ( V_3 - 1 ) ;
if ( F_22 ( F_1 ( V_2 ) < 1 ) ) {
F_105 ( V_17 ) ;
if ( F_1 ( V_2 ) > F_53 ( V_2 ) )
F_60 ( V_17 ) ;
}
F_65 ( & V_5 -> V_12 . V_131 , V_129 ) ;
F_84 ( V_153 ) ;
( void ) F_87 ( & V_5 -> V_154 , V_155 + V_156 ) ;
return V_192 ;
V_186:
F_65 ( & V_5 -> V_12 . V_131 , V_129 ) ;
V_70:
if ( V_57 )
F_85 ( V_57 ) ;
F_84 ( V_153 ) ;
if ( V_146 )
( void ) F_87 ( & V_5 -> V_154 ,
V_155 + V_156 ) ;
else if ( V_5 )
F_88 ( & V_5 -> V_154 ) ;
V_17 -> V_68 . V_193 ++ ;
return V_192 ;
}
static void F_111 ( struct V_16 * V_17 )
{
}
static int F_112 ( struct V_16 * V_17 )
{
F_113 ( V_17 ) ;
F_114 ( V_17 ) ;
return 0 ;
}
static int F_115 ( struct V_16 * V_17 )
{
F_105 ( V_17 ) ;
F_116 ( V_17 ) ;
return 0 ;
}
static struct V_194 * F_117 ( struct V_122 * V_18 , T_2 * V_33 )
{
struct V_194 * V_195 ;
for ( V_195 = V_18 -> V_196 ; V_195 ; V_195 = V_195 -> V_150 ) {
if ( F_79 ( V_195 -> V_33 , V_33 ) )
return V_195 ;
}
return NULL ;
}
static void F_118 ( struct V_122 * V_18 , struct V_16 * V_17 )
{
struct V_197 * V_198 ;
F_119 (ha, dev) {
struct V_194 * V_195 ;
V_195 = F_117 ( V_18 , V_198 -> V_33 ) ;
if ( V_195 ) {
V_195 -> V_199 = 1 ;
continue;
}
if ( ! V_195 ) {
V_195 = F_120 ( sizeof( * V_195 ) , V_200 ) ;
if ( ! V_195 )
continue;
memcpy ( V_195 -> V_33 , V_198 -> V_33 , V_201 ) ;
V_195 -> V_199 = 1 ;
V_195 -> V_150 = V_18 -> V_196 ;
V_18 -> V_196 = V_195 ;
}
}
}
static void F_121 ( struct V_122 * V_18 , struct V_4 * V_5 )
{
struct V_124 V_202 ;
struct V_194 * V_195 , * * V_203 ;
int V_204 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_23 . type = V_24 ;
V_202 . V_23 . V_9 = V_25 ;
V_202 . V_23 . V_10 = V_136 ;
V_202 . V_23 . V_11 = F_8 ( & V_5 -> V_12 ) ;
V_202 . V_205 = 1 ;
V_204 = 0 ;
for ( V_195 = V_18 -> V_196 ; V_195 ; V_195 = V_195 -> V_150 ) {
if ( V_195 -> V_206 )
continue;
V_195 -> V_206 = 1 ;
memcpy ( & V_202 . V_207 [ V_204 * V_201 ] ,
V_195 -> V_33 , V_201 ) ;
if ( ++ V_204 == V_208 ) {
V_202 . V_209 = V_204 ;
( void ) F_14 ( & V_5 -> V_12 , & V_202 ,
sizeof( V_202 ) ) ;
V_204 = 0 ;
}
}
if ( V_204 ) {
V_202 . V_209 = V_204 ;
( void ) F_14 ( & V_5 -> V_12 , & V_202 , sizeof( V_202 ) ) ;
}
V_202 . V_205 = 0 ;
V_204 = 0 ;
V_203 = & V_18 -> V_196 ;
while ( ( V_195 = * V_203 ) != NULL ) {
if ( V_195 -> V_199 ) {
V_195 -> V_199 = 0 ;
V_203 = & V_195 -> V_150 ;
continue;
}
memcpy ( & V_202 . V_207 [ V_204 * V_201 ] ,
V_195 -> V_33 , V_201 ) ;
if ( ++ V_204 == V_208 ) {
V_202 . V_209 = V_204 ;
( void ) F_14 ( & V_5 -> V_12 , & V_202 ,
sizeof( V_202 ) ) ;
V_204 = 0 ;
}
* V_203 = V_195 -> V_150 ;
F_122 ( V_195 ) ;
}
if ( V_204 ) {
V_202 . V_209 = V_204 ;
( void ) F_14 ( & V_5 -> V_12 , & V_202 , sizeof( V_202 ) ) ;
}
}
static void F_123 ( struct V_16 * V_17 )
{
struct V_122 * V_18 = F_94 ( V_17 ) ;
struct V_4 * V_5 ;
unsigned long V_129 ;
F_63 ( & V_18 -> V_131 , V_129 ) ;
if ( ! F_124 ( & V_18 -> V_210 ) ) {
V_5 = F_125 ( V_18 -> V_210 . V_150 , struct V_4 , V_211 ) ;
if ( V_5 -> V_144 ) {
F_118 ( V_18 , V_17 ) ;
F_121 ( V_18 , V_5 ) ;
}
}
F_65 ( & V_18 -> V_131 , V_129 ) ;
}
static int F_126 ( struct V_16 * V_17 , int V_212 )
{
if ( V_212 < 68 || V_212 > 65535 )
return - V_213 ;
V_17 -> V_38 = V_212 ;
return 0 ;
}
static int F_127 ( struct V_16 * V_17 , void * V_214 )
{
return - V_213 ;
}
static void F_128 ( struct V_16 * V_17 ,
struct V_215 * V_202 )
{
F_129 ( V_202 -> V_216 , V_217 , sizeof( V_202 -> V_216 ) ) ;
F_129 ( V_202 -> V_218 , V_219 , sizeof( V_202 -> V_218 ) ) ;
}
static T_1 F_130 ( struct V_16 * V_17 )
{
struct V_122 * V_18 = F_94 ( V_17 ) ;
return V_18 -> V_220 ;
}
static void F_131 ( struct V_16 * V_17 , T_1 V_221 )
{
struct V_122 * V_18 = F_94 ( V_17 ) ;
V_18 -> V_220 = V_221 ;
}
static void F_132 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = & V_5 -> V_12 . V_50 [ V_54 ] ;
if ( V_2 -> V_222 ) {
F_133 ( V_5 -> V_12 . V_13 , V_2 -> V_222 ,
( V_2 -> V_106 * V_2 -> V_101 ) ,
V_2 -> V_62 , V_2 -> V_63 ) ;
V_2 -> V_222 = NULL ;
V_2 -> V_106 = 0 ;
V_2 -> V_101 = 0 ;
V_2 -> V_146 = 0 ;
V_2 -> V_63 = 0 ;
}
for ( V_22 = 0 ; V_22 < V_3 ; V_22 ++ ) {
struct V_102 * V_148 ;
void * V_57 = V_5 -> V_149 [ V_22 ] . V_57 ;
if ( ! V_57 )
continue;
V_148 = F_50 ( V_2 , V_22 ) ;
if ( V_148 -> V_83 . V_90 == V_108 )
F_67 ( L_25 ) ;
F_83 ( V_5 -> V_12 . V_13 ,
V_5 -> V_149 [ V_22 ] . V_62 ,
V_5 -> V_149 [ V_22 ] . V_63 ) ;
F_85 ( V_57 ) ;
V_5 -> V_149 [ V_22 ] . V_57 = NULL ;
V_148 -> V_83 . V_90 = V_151 ;
}
}
static int F_134 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_56 ;
int V_22 , V_65 , V_63 ;
void * V_223 ;
V_2 = & V_5 -> V_12 . V_50 [ V_54 ] ;
V_56 = ( V_3 *
( sizeof( struct V_102 ) +
( sizeof( struct V_61 ) * 2 ) ) ) ;
V_63 = V_224 ;
V_223 = F_135 ( V_5 -> V_12 . V_13 , V_56 ,
V_2 -> V_62 , & V_63 ,
( V_183 |
V_184 |
V_185 ) ) ;
if ( F_43 ( V_223 ) ) {
V_65 = F_44 ( V_223 ) ;
goto V_225;
}
V_2 -> V_222 = V_223 ;
V_2 -> V_106 = ( sizeof( struct V_102 ) +
( sizeof( struct V_61 ) * 2 ) ) ;
V_2 -> V_101 = V_3 ;
V_2 -> V_121 = V_2 -> V_119 = 0 ;
V_5 -> V_123 = true ;
V_2 -> V_146 = V_3 ;
V_2 -> V_63 = V_63 ;
for ( V_22 = 0 ; V_22 < V_3 ; ++ V_22 ) {
struct V_102 * V_148 ;
V_148 = F_50 ( V_2 , V_22 ) ;
V_148 -> V_83 . V_90 = V_151 ;
}
return 0 ;
V_225:
F_132 ( V_5 ) ;
return V_65 ;
}
static struct V_122 * F_136 ( const V_34 * V_226 )
{
struct V_16 * V_17 ;
struct V_122 * V_18 ;
int V_65 , V_22 ;
V_17 = F_137 ( sizeof( * V_18 ) ) ;
if ( ! V_17 )
return F_39 ( - V_71 ) ;
V_17 -> V_227 = V_58 + 8 ;
V_17 -> V_228 = 8 ;
for ( V_22 = 0 ; V_22 < V_201 ; V_22 ++ )
V_17 -> V_35 [ V_22 ] = ( * V_226 >> ( 5 - V_22 ) * 8 ) & 0xff ;
V_18 = F_94 ( V_17 ) ;
F_138 ( & V_18 -> V_131 ) ;
F_139 ( & V_18 -> V_137 , F_56 , ( unsigned long ) V_18 ) ;
V_18 -> V_17 = V_17 ;
F_140 ( & V_18 -> V_210 ) ;
for ( V_22 = 0 ; V_22 < V_229 ; V_22 ++ )
F_141 ( & V_18 -> V_143 [ V_22 ] ) ;
F_140 ( & V_18 -> V_211 ) ;
V_18 -> V_226 = * V_226 ;
V_17 -> V_230 = & V_231 ;
V_17 -> V_232 = & V_233 ;
V_17 -> V_234 = V_235 ;
V_65 = F_142 ( V_17 ) ;
if ( V_65 ) {
F_4 ( L_26 ) ;
goto V_236;
}
F_109 ( V_17 , L_27 , V_17 -> V_35 ) ;
F_143 ( & V_18 -> V_211 , & V_237 ) ;
return V_18 ;
V_236:
F_144 ( V_17 ) ;
return F_39 ( V_65 ) ;
}
static struct V_122 * F_145 ( const V_34 * V_226 )
{
struct V_122 * V_238 , * V_18 ;
F_146 ( & V_239 ) ;
V_18 = NULL ;
F_59 (iter, &vnet_list, list) {
if ( V_238 -> V_226 == * V_226 ) {
V_18 = V_238 ;
break;
}
}
if ( ! V_18 )
V_18 = F_136 ( V_226 ) ;
F_147 ( & V_239 ) ;
return V_18 ;
}
static void F_148 ( void )
{
struct V_122 * V_18 ;
struct V_16 * V_17 ;
F_146 ( & V_239 ) ;
while ( ! F_124 ( & V_237 ) ) {
V_18 = F_149 ( & V_237 , struct V_122 , V_211 ) ;
F_150 ( & V_18 -> V_211 ) ;
V_17 = V_18 -> V_17 ;
F_151 ( & V_18 -> V_137 ) ;
F_82 ( ! F_124 ( & V_18 -> V_210 ) ) ;
F_152 ( V_17 ) ;
F_144 ( V_17 ) ;
}
F_147 ( & V_239 ) ;
}
static struct V_122 * F_153 ( struct V_240 * V_142 ,
V_34 V_241 )
{
const V_34 * V_226 = NULL ;
V_34 V_242 ;
F_154 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
V_34 V_243 = F_155 ( V_142 , V_242 ) ;
const char * V_125 ;
V_125 = F_156 ( V_142 , V_243 , L_28 , NULL ) ;
if ( ! V_125 || strcmp ( V_125 , L_29 ) )
continue;
V_226 = F_156 ( V_142 , V_243 ,
V_244 , NULL ) ;
if ( V_226 )
break;
}
if ( ! V_226 )
return F_39 ( - V_245 ) ;
return F_145 ( V_226 ) ;
}
static void F_157 ( void )
{
F_158 ( V_246 L_30 , V_218 ) ;
}
static int F_159 ( struct V_247 * V_248 , const struct V_249 * V_250 )
{
struct V_240 * V_142 ;
struct V_4 * V_5 ;
unsigned long V_129 ;
struct V_122 * V_18 ;
const V_34 * V_251 ;
int V_56 , V_22 , V_65 , V_144 ;
F_157 () ;
V_142 = F_160 () ;
V_18 = F_153 ( V_142 , V_248 -> V_252 ) ;
if ( F_43 ( V_18 ) ) {
F_4 ( L_31 ) ;
V_65 = F_44 ( V_18 ) ;
goto V_253;
}
V_251 = F_156 ( V_142 , V_248 -> V_252 , V_254 , & V_56 ) ;
V_65 = - V_245 ;
if ( ! V_251 ) {
F_4 ( L_32 , V_254 ) ;
goto V_253;
}
V_5 = F_120 ( sizeof( * V_5 ) , V_255 ) ;
V_65 = - V_71 ;
if ( ! V_5 )
goto V_253;
for ( V_22 = 0 ; V_22 < V_201 ; V_22 ++ )
V_5 -> V_95 [ V_22 ] = ( * V_251 >> ( 5 - V_22 ) * 8 ) & 0xff ;
V_5 -> V_18 = V_18 ;
V_65 = F_161 ( & V_5 -> V_12 , V_248 , V_256 ,
V_257 , F_162 ( V_257 ) ,
& V_258 , V_18 -> V_17 -> V_125 ) ;
if ( V_65 )
goto V_259;
V_65 = F_163 ( & V_5 -> V_12 , & V_260 , V_5 ) ;
if ( V_65 )
goto V_259;
V_65 = F_134 ( V_5 ) ;
if ( V_65 )
goto V_261;
F_164 ( & V_5 -> V_140 ) ;
F_140 ( & V_5 -> V_211 ) ;
V_144 = 0 ;
if ( F_156 ( V_142 , V_248 -> V_252 , L_33 , NULL ) != NULL )
V_144 = 1 ;
V_5 -> V_144 = V_144 ;
F_63 ( & V_18 -> V_131 , V_129 ) ;
if ( V_144 )
F_143 ( & V_5 -> V_211 , & V_18 -> V_210 ) ;
else
F_165 ( & V_5 -> V_211 , & V_18 -> V_210 ) ;
F_166 ( & V_5 -> V_140 , & V_18 -> V_143 [ F_77 ( V_5 -> V_95 ) ] ) ;
F_65 ( & V_18 -> V_131 , V_129 ) ;
F_167 ( & V_248 -> V_17 , V_5 ) ;
F_34 ( L_34 ,
V_18 -> V_17 -> V_125 , V_5 -> V_95 , V_144 ? L_35 : L_36 ) ;
F_168 ( & V_5 -> V_154 , F_86 ,
( unsigned long ) V_5 ) ;
F_66 ( & V_5 -> V_12 ) ;
F_169 ( V_142 ) ;
return 0 ;
V_261:
F_170 ( & V_5 -> V_12 ) ;
V_259:
F_122 ( V_5 ) ;
V_253:
F_169 ( V_142 ) ;
return V_65 ;
}
static int F_171 ( struct V_247 * V_248 )
{
struct V_4 * V_5 = F_172 ( & V_248 -> V_17 ) ;
if ( V_5 ) {
struct V_122 * V_18 = V_5 -> V_18 ;
unsigned long V_129 ;
F_173 ( & V_5 -> V_12 . V_262 ) ;
F_173 ( & V_5 -> V_154 ) ;
F_63 ( & V_18 -> V_131 , V_129 ) ;
F_150 ( & V_5 -> V_211 ) ;
F_174 ( & V_5 -> V_140 ) ;
F_65 ( & V_18 -> V_131 , V_129 ) ;
F_132 ( V_5 ) ;
F_170 ( & V_5 -> V_12 ) ;
F_167 ( & V_248 -> V_17 , NULL ) ;
F_122 ( V_5 ) ;
}
return 0 ;
}
static int T_3 F_175 ( void )
{
return F_176 ( & V_263 ) ;
}
static void T_4 F_177 ( void )
{
F_178 ( & V_263 ) ;
F_148 () ;
}

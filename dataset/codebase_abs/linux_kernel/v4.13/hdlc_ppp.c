static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static inline struct V_5 * F_3 ( struct V_2 * V_3 , T_1 V_6 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
switch ( V_6 ) {
case V_7 :
return & V_1 -> V_8 [ V_9 ] ;
case V_10 :
return & V_1 -> V_8 [ V_11 ] ;
case V_12 :
return & V_1 -> V_8 [ V_13 ] ;
default:
return NULL ;
}
}
static inline const char * F_4 ( T_1 V_6 )
{
switch ( V_6 ) {
case V_7 :
return L_1 ;
case V_10 :
return L_2 ;
case V_12 :
return L_3 ;
default:
return NULL ;
}
}
static T_2 F_5 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
struct V_16 * V_17 = (struct V_16 * ) V_15 -> V_17 ;
if ( V_15 -> V_18 < sizeof( struct V_16 ) )
return F_6 ( V_19 ) ;
if ( V_17 -> V_20 != V_21 ||
V_17 -> V_22 != V_23 )
return F_6 ( V_19 ) ;
switch ( V_17 -> V_24 ) {
case F_7 ( V_25 ) :
F_8 ( V_15 , sizeof( struct V_16 ) ) ;
return F_6 ( V_26 ) ;
case F_7 ( V_27 ) :
F_8 ( V_15 , sizeof( struct V_16 ) ) ;
return F_6 ( V_28 ) ;
default:
return F_6 ( V_19 ) ;
}
}
static int F_9 ( struct V_14 * V_15 , struct V_2 * V_3 ,
T_1 type , const void * V_29 , const void * V_30 ,
unsigned int V_18 )
{
struct V_16 * V_17 ;
#if V_31
F_10 ( V_32 L_4 , V_3 -> V_33 ) ;
#endif
F_11 ( V_15 , sizeof( struct V_16 ) ) ;
V_17 = (struct V_16 * ) V_15 -> V_17 ;
V_17 -> V_20 = V_21 ;
V_17 -> V_22 = V_23 ;
switch ( type ) {
case V_26 :
V_17 -> V_24 = F_6 ( V_25 ) ;
break;
case V_28 :
V_17 -> V_24 = F_6 ( V_27 ) ;
break;
case V_7 :
case V_10 :
case V_12 :
V_17 -> V_24 = F_6 ( type ) ;
break;
default:
V_17 -> V_24 = 0 ;
}
return sizeof( struct V_16 ) ;
}
static void F_12 ( void )
{
struct V_14 * V_15 ;
while ( ( V_15 = F_13 ( & V_34 ) ) != NULL )
F_14 ( V_15 ) ;
}
static void F_15 ( struct V_2 * V_3 , T_1 V_6 , T_3 V_35 ,
T_3 V_36 , unsigned int V_18 , const void * V_17 )
{
struct V_14 * V_15 ;
struct V_37 * V_38 ;
unsigned int V_39 = 0 ;
static T_4 V_40 ;
#if V_41
int V_42 ;
char * V_43 ;
#endif
if ( V_6 == V_7 && ( V_35 == V_44 || V_35 == V_45 ) )
V_39 = sizeof( V_40 ) ;
V_15 = F_16 ( sizeof( struct V_16 ) +
sizeof( struct V_37 ) + V_39 + V_18 ) ;
if ( ! V_15 ) {
F_17 ( V_3 , L_5 ) ;
return;
}
F_18 ( V_15 , sizeof( struct V_16 ) ) ;
V_38 = F_19 ( V_15 , sizeof( struct V_37 ) ) ;
V_38 -> V_35 = V_35 ;
V_38 -> V_36 = V_36 ;
V_38 -> V_18 = F_6 ( sizeof( struct V_37 ) + V_39 + V_18 ) ;
if ( V_39 )
F_20 ( V_15 , & V_40 , V_39 ) ;
if ( V_18 )
F_20 ( V_15 , V_17 , V_18 ) ;
#if V_41
F_21 ( V_35 >= V_46 ) ;
V_43 = V_47 ;
* V_43 = '\x0' ;
for ( V_42 = 0 ; V_42 < F_22 (unsigned int, magic_len + len, DEBUG_CP) ; V_42 ++ ) {
sprintf ( V_43 , L_6 , V_15 -> V_17 [ sizeof( struct V_37 ) + V_42 ] ) ;
V_43 += strlen ( V_43 ) ;
}
F_10 ( V_32 L_7 , V_3 -> V_33 ,
F_4 ( V_6 ) , V_48 [ V_35 ] , V_36 , V_47 ) ;
#endif
F_9 ( V_15 , V_3 , V_6 , NULL , NULL , 0 ) ;
V_15 -> V_49 = V_50 ;
V_15 -> V_3 = V_3 ;
F_23 ( V_15 ) ;
F_24 ( & V_34 , V_15 ) ;
}
static void F_25 ( struct V_2 * V_3 , T_1 V_6 , T_1 V_51 , T_3 V_35 ,
T_3 V_36 , unsigned int V_18 , const void * V_17 )
{
int V_52 , V_53 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 , V_6 ) ;
V_52 = V_5 -> V_4 ;
F_21 ( V_52 >= V_54 ) ;
F_21 ( V_51 >= V_55 ) ;
#if V_56
F_10 ( V_32 L_8 , V_3 -> V_33 ,
F_4 ( V_6 ) , V_57 [ V_51 ] , V_58 [ V_5 -> V_4 ] ) ;
#endif
V_53 = V_59 [ V_51 ] [ V_52 ] ;
V_5 -> V_4 = V_53 & V_60 ;
if ( V_53 & ( V_61 | V_62 ) )
F_26 ( & V_5 -> V_63 , V_5 -> V_64 =
V_65 + V_1 -> V_66 * V_67 ) ;
if ( V_53 & V_68 )
V_5 -> V_69 = 0 ;
if ( V_53 & V_70 )
V_5 -> V_69 = ( V_5 -> V_4 == V_71 ) ?
V_1 -> V_72 : V_1 -> V_73 ;
if ( V_53 & V_61 )
F_15 ( V_3 , V_6 , V_74 , V_5 -> V_75 = ++ V_1 -> V_76 ,
0 , NULL ) ;
if ( V_53 & V_77 )
F_15 ( V_3 , V_6 , V_78 , V_36 , V_18 , V_17 ) ;
if ( V_53 & V_79 )
F_15 ( V_3 , V_6 , V_35 , V_36 , V_18 , V_17 ) ;
if ( V_53 & V_62 )
F_15 ( V_3 , V_6 , V_80 , ++ V_1 -> V_76 , 0 , NULL ) ;
if ( V_53 & V_81 )
F_15 ( V_3 , V_6 , V_82 , V_36 , 0 , NULL ) ;
if ( V_53 & V_83 )
F_15 ( V_3 , V_6 , V_84 , ++ V_1 -> V_76 , V_18 , V_17 ) ;
if ( V_52 != V_85 && V_5 -> V_4 == V_85 ) {
F_27 ( V_3 , L_9 , F_4 ( V_6 ) ) ;
if ( V_6 == V_7 ) {
F_28 ( V_3 ) ;
F_25 ( V_3 , V_10 , V_86 , 0 , 0 , 0 , NULL ) ;
F_25 ( V_3 , V_12 , V_86 , 0 , 0 , 0 , NULL ) ;
V_1 -> V_87 = V_65 ;
F_26 ( & V_5 -> V_63 , V_5 -> V_64 =
V_65 + V_1 -> V_88 * V_67 ) ;
}
}
if ( V_52 == V_85 && V_5 -> V_4 != V_85 ) {
F_27 ( V_3 , L_10 , F_4 ( V_6 ) ) ;
if ( V_6 == V_7 ) {
F_29 ( V_3 ) ;
F_25 ( V_3 , V_10 , V_89 , 0 , 0 , 0 , NULL ) ;
F_25 ( V_3 , V_12 , V_89 , 0 , 0 , 0 , NULL ) ;
}
}
if ( V_52 != V_90 && V_5 -> V_4 == V_90 )
F_30 ( & V_5 -> V_63 ) ;
#if V_56
F_10 ( V_32 L_11 , V_3 -> V_33 ,
F_4 ( V_6 ) , V_57 [ V_51 ] , V_58 [ V_5 -> V_4 ] ) ;
#endif
}
static void F_31 ( struct V_2 * V_3 , T_1 V_6 , T_3 V_36 ,
unsigned int V_91 , const T_3 * V_17 )
{
static T_3 const V_92 [ 6 ] = { V_93 , 6 , 0 , 0 , 0 , 0 } ;
const T_3 * V_94 ;
T_3 * V_95 ;
unsigned int V_18 = V_91 , V_96 = 0 , V_97 = 0 ;
if ( ! ( V_95 = F_32 ( V_18 , V_98 ) ) ) {
V_3 -> V_99 . V_100 ++ ;
return;
}
for ( V_94 = V_17 ; V_18 ; V_18 -= V_94 [ 1 ] , V_94 += V_94 [ 1 ] ) {
if ( V_18 < 2 || V_18 < V_94 [ 1 ] ) {
V_3 -> V_99 . V_101 ++ ;
F_33 ( V_95 ) ;
return;
}
if ( V_6 == V_7 )
switch ( V_94 [ 0 ] ) {
case V_102 :
continue;
case V_93 :
if ( ! memcmp ( V_94 , V_92 ,
sizeof( V_92 ) ) )
continue;
if ( ! V_97 ) {
memcpy ( V_95 + V_96 , V_92 ,
sizeof( V_92 ) ) ;
V_96 += sizeof( V_92 ) ;
continue;
}
break;
case V_103 :
if ( V_94 [ 1 ] != 6 || ( ! V_94 [ 2 ] && ! V_94 [ 3 ] &&
! V_94 [ 4 ] && ! V_94 [ 5 ] ) )
break;
continue;
}
memcpy ( V_95 + V_97 , V_94 , V_94 [ 1 ] ) ;
V_97 += V_94 [ 1 ] ;
}
if ( V_97 )
F_25 ( V_3 , V_6 , V_104 , V_105 , V_36 , V_97 , V_95 ) ;
else if ( V_96 )
F_25 ( V_3 , V_6 , V_104 , V_106 , V_36 , V_96 , V_95 ) ;
else
F_25 ( V_3 , V_6 , V_107 , V_78 , V_36 , V_91 , V_17 ) ;
F_33 ( V_95 ) ;
}
static int F_34 ( struct V_14 * V_15 )
{
struct V_16 * V_108 = (struct V_16 * ) V_15 -> V_17 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 ;
struct V_37 * V_38 ;
unsigned long V_109 ;
unsigned int V_18 ;
T_1 V_6 ;
#if V_41
int V_42 ;
char * V_43 ;
#endif
F_35 ( & V_1 -> V_110 , V_109 ) ;
if ( V_15 -> V_18 < sizeof( struct V_16 ) )
goto V_111;
V_38 = F_8 ( V_15 , sizeof( struct V_16 ) ) ;
if ( V_108 -> V_20 != V_21 ||
V_108 -> V_22 != V_23 )
goto V_111;
V_6 = F_36 ( V_108 -> V_24 ) ;
V_5 = F_3 ( V_3 , V_6 ) ;
if ( ! V_5 ) {
if ( V_1 -> V_8 [ V_9 ] . V_4 == V_85 )
F_15 ( V_3 , V_7 , V_112 ,
++ V_1 -> V_76 , V_15 -> V_18 + 2 , & V_108 -> V_24 ) ;
goto V_111;
}
V_18 = F_36 ( V_38 -> V_18 ) ;
if ( V_18 < sizeof( struct V_37 ) ||
V_15 -> V_18 < V_18 )
goto V_111;
F_8 ( V_15 , sizeof( struct V_37 ) ) ;
V_18 -= sizeof( struct V_37 ) ;
#if V_41
if ( V_38 -> V_35 < V_46 )
sprintf ( V_47 , L_12 , V_48 [ V_38 -> V_35 ] ,
V_38 -> V_36 ) ;
else
sprintf ( V_47 , L_13 , V_38 -> V_35 , V_38 -> V_36 ) ;
V_43 = V_47 + strlen ( V_47 ) ;
for ( V_42 = 0 ; V_42 < F_22 (unsigned int, len, DEBUG_CP) ; V_42 ++ ) {
sprintf ( V_43 , L_6 , V_15 -> V_17 [ V_42 ] ) ;
V_43 += strlen ( V_43 ) ;
}
F_10 ( V_32 L_14 , V_3 -> V_33 , F_4 ( V_6 ) ,
V_47 ) ;
#endif
if ( V_6 == V_7 )
switch ( V_38 -> V_35 ) {
case V_112 :
V_6 = F_36 ( * ( T_2 * ) V_15 -> V_17 ) ;
if ( V_6 == V_7 || V_6 == V_10 ||
V_6 == V_12 )
F_25 ( V_3 , V_6 , V_113 , 0 , 0 ,
0 , NULL ) ;
goto V_95;
case V_44 :
if ( V_18 >= 4 && V_5 -> V_4 == V_85 )
F_15 ( V_3 , V_7 , V_45 ,
V_38 -> V_36 , V_18 - 4 , V_15 -> V_17 + 4 ) ;
goto V_95;
case V_45 :
if ( V_38 -> V_36 == V_1 -> V_114 )
V_1 -> V_87 = V_65 ;
goto V_95;
case V_115 :
goto V_95;
}
switch ( V_38 -> V_35 ) {
case V_74 :
F_31 ( V_3 , V_6 , V_38 -> V_36 , V_18 , V_15 -> V_17 ) ;
break;
case V_78 :
if ( V_38 -> V_36 == V_5 -> V_75 )
F_25 ( V_3 , V_6 , V_116 , 0 , 0 , 0 , NULL ) ;
break;
case V_105 :
case V_106 :
if ( V_38 -> V_36 == V_5 -> V_75 )
F_25 ( V_3 , V_6 , V_117 , 0 , 0 , 0 , NULL ) ;
break;
case V_80 :
F_25 ( V_3 , V_6 , V_118 , 0 , V_38 -> V_36 , 0 , NULL ) ;
break;
case V_82 :
F_25 ( V_3 , V_6 , V_119 , 0 , 0 , 0 , NULL ) ;
break;
case V_84 :
F_25 ( V_3 , V_6 , V_113 , 0 , 0 , 0 , NULL ) ;
break;
default:
V_18 += sizeof( struct V_37 ) ;
if ( V_18 > V_3 -> V_120 )
V_18 = V_3 -> V_120 ;
F_25 ( V_3 , V_6 , V_121 , 0 , 0 , V_18 , V_38 ) ;
break;
}
goto V_95;
V_111:
V_3 -> V_99 . V_101 ++ ;
V_95:
F_37 ( & V_1 -> V_110 , V_109 ) ;
F_38 ( V_15 ) ;
F_12 () ;
return V_122 ;
}
static void F_39 ( unsigned long V_123 )
{
struct V_5 * V_5 = (struct V_5 * ) V_123 ;
struct V_1 * V_1 = F_1 ( V_5 -> V_3 ) ;
unsigned long V_109 ;
F_35 ( & V_1 -> V_110 , V_109 ) ;
switch ( V_5 -> V_4 ) {
case V_71 :
case V_124 :
case V_125 :
case V_126 :
if ( V_5 -> V_69 ) {
F_25 ( V_5 -> V_3 , V_5 -> V_6 , V_127 , 0 , 0 ,
0 , NULL ) ;
V_5 -> V_69 -- ;
} else
F_25 ( V_5 -> V_3 , V_5 -> V_6 , V_128 , 0 , 0 ,
0 , NULL ) ;
break;
case V_85 :
if ( V_5 -> V_6 != V_7 )
break;
if ( F_40 ( V_65 , V_1 -> V_87 +
V_1 -> V_129 * V_67 ) ) {
F_27 ( V_5 -> V_3 , L_15 ) ;
F_25 ( V_5 -> V_3 , V_7 , V_89 , 0 , 0 , 0 , NULL ) ;
F_25 ( V_5 -> V_3 , V_7 , V_86 , 0 , 0 , 0 , NULL ) ;
} else {
V_1 -> V_114 = ++ V_1 -> V_76 ;
F_15 ( V_5 -> V_3 , V_7 , V_44 ,
V_1 -> V_114 , 0 , NULL ) ;
V_5 -> V_63 . V_130 = V_65 +
V_1 -> V_88 * V_67 ;
F_41 ( & V_5 -> V_63 ) ;
}
break;
}
F_37 ( & V_1 -> V_110 , V_109 ) ;
F_12 () ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_131 ; V_42 ++ ) {
struct V_5 * V_5 = & V_1 -> V_8 [ V_42 ] ;
V_5 -> V_3 = V_3 ;
F_43 ( & V_5 -> V_63 ) ;
V_5 -> V_63 . V_132 = F_39 ;
V_5 -> V_63 . V_17 = ( unsigned long ) V_5 ;
V_5 -> V_4 = V_90 ;
}
V_1 -> V_8 [ V_9 ] . V_6 = V_7 ;
V_1 -> V_8 [ V_11 ] . V_6 = V_10 ;
V_1 -> V_8 [ V_13 ] . V_6 = V_12 ;
F_25 ( V_3 , V_7 , V_86 , 0 , 0 , 0 , NULL ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
F_25 ( V_3 , V_7 , V_89 , 0 , 0 , 0 , NULL ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
F_12 () ;
}
static int F_46 ( struct V_2 * V_3 , struct V_133 * V_134 )
{
T_5 * V_135 = F_2 ( V_3 ) ;
struct V_1 * V_1 ;
int V_136 ;
switch ( V_134 -> V_137 . type ) {
case V_138 :
if ( F_2 ( V_3 ) -> V_5 != & V_5 )
return - V_139 ;
V_134 -> V_137 . type = V_140 ;
return 0 ;
case V_140 :
if ( ! F_47 ( V_141 ) )
return - V_142 ;
if ( V_3 -> V_109 & V_143 )
return - V_144 ;
V_136 = V_135 -> V_145 ( V_3 , V_146 , V_147 ) ;
if ( V_136 )
return V_136 ;
V_136 = F_48 ( V_3 , & V_5 , sizeof( struct V_1 ) ) ;
if ( V_136 )
return V_136 ;
V_1 = F_1 ( V_3 ) ;
F_49 ( & V_1 -> V_110 ) ;
V_1 -> V_66 = 2 ;
V_1 -> V_73 = 10 ;
V_1 -> V_72 = 2 ;
V_1 -> V_88 = 10 ;
V_1 -> V_129 = 60 ;
V_3 -> V_148 = sizeof( struct V_16 ) ;
V_3 -> V_149 = & V_150 ;
V_3 -> type = V_151 ;
F_50 ( V_152 , V_3 ) ;
F_29 ( V_3 ) ;
return 0 ;
}
return - V_139 ;
}
static int T_6 F_51 ( void )
{
F_52 ( & V_34 ) ;
F_53 ( & V_5 ) ;
return 0 ;
}
static void T_7 F_54 ( void )
{
F_55 ( & V_5 ) ;
}

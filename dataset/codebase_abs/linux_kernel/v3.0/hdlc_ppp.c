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
F_10 ( V_46 L_5 ,
V_3 -> V_33 ) ;
return;
}
F_17 ( V_15 , sizeof( struct V_16 ) ) ;
V_38 = (struct V_37 * ) F_18 ( V_15 , sizeof( struct V_37 ) ) ;
V_38 -> V_35 = V_35 ;
V_38 -> V_36 = V_36 ;
V_38 -> V_18 = F_6 ( sizeof( struct V_37 ) + V_39 + V_18 ) ;
if ( V_39 )
memcpy ( F_18 ( V_15 , V_39 ) , & V_40 , V_39 ) ;
if ( V_18 )
memcpy ( F_18 ( V_15 , V_18 ) , V_17 , V_18 ) ;
#if V_41
F_19 ( V_35 >= V_47 ) ;
V_43 = V_48 ;
* V_43 = '\x0' ;
for ( V_42 = 0 ; V_42 < F_20 (unsigned int, magic_len + len, DEBUG_CP) ; V_42 ++ ) {
sprintf ( V_43 , L_6 , V_15 -> V_17 [ sizeof( struct V_37 ) + V_42 ] ) ;
V_43 += strlen ( V_43 ) ;
}
F_10 ( V_32 L_7 , V_3 -> V_33 ,
F_4 ( V_6 ) , V_49 [ V_35 ] , V_36 , V_48 ) ;
#endif
F_9 ( V_15 , V_3 , V_6 , NULL , NULL , 0 ) ;
V_15 -> V_50 = V_51 ;
V_15 -> V_3 = V_3 ;
F_21 ( V_15 ) ;
F_22 ( & V_34 , V_15 ) ;
}
static void F_23 ( struct V_2 * V_3 , T_1 V_6 , T_1 V_52 , T_3 V_35 ,
T_3 V_36 , unsigned int V_18 , const void * V_17 )
{
int V_53 , V_54 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_3 , V_6 ) ;
V_53 = V_5 -> V_4 ;
F_19 ( V_53 >= V_55 ) ;
F_19 ( V_52 >= V_56 ) ;
#if V_57
F_10 ( V_32 L_8 , V_3 -> V_33 ,
F_4 ( V_6 ) , V_58 [ V_52 ] , V_59 [ V_5 -> V_4 ] ) ;
#endif
V_54 = V_60 [ V_52 ] [ V_53 ] ;
V_5 -> V_4 = V_54 & V_61 ;
if ( V_54 & ( V_62 | V_63 ) )
F_24 ( & V_5 -> V_64 , V_5 -> V_65 =
V_66 + V_1 -> V_67 * V_68 ) ;
if ( V_54 & V_69 )
V_5 -> V_70 = 0 ;
if ( V_54 & V_71 )
V_5 -> V_70 = ( V_5 -> V_4 == V_72 ) ?
V_1 -> V_73 : V_1 -> V_74 ;
if ( V_54 & V_62 )
F_15 ( V_3 , V_6 , V_75 , V_5 -> V_76 = ++ V_1 -> V_77 ,
0 , NULL ) ;
if ( V_54 & V_78 )
F_15 ( V_3 , V_6 , V_79 , V_36 , V_18 , V_17 ) ;
if ( V_54 & V_80 )
F_15 ( V_3 , V_6 , V_35 , V_36 , V_18 , V_17 ) ;
if ( V_54 & V_63 )
F_15 ( V_3 , V_6 , V_81 , ++ V_1 -> V_77 , 0 , NULL ) ;
if ( V_54 & V_82 )
F_15 ( V_3 , V_6 , V_83 , V_36 , 0 , NULL ) ;
if ( V_54 & V_84 )
F_15 ( V_3 , V_6 , V_85 , ++ V_1 -> V_77 , V_18 , V_17 ) ;
if ( V_53 != V_86 && V_5 -> V_4 == V_86 ) {
F_10 ( V_87 L_9 , V_3 -> V_33 , F_4 ( V_6 ) ) ;
if ( V_6 == V_7 ) {
F_25 ( V_3 ) ;
F_23 ( V_3 , V_10 , V_88 , 0 , 0 , 0 , NULL ) ;
F_23 ( V_3 , V_12 , V_88 , 0 , 0 , 0 , NULL ) ;
V_1 -> V_89 = V_66 ;
F_24 ( & V_5 -> V_64 , V_5 -> V_65 =
V_66 + V_1 -> V_90 * V_68 ) ;
}
}
if ( V_53 == V_86 && V_5 -> V_4 != V_86 ) {
F_10 ( V_87 L_10 , V_3 -> V_33 , F_4 ( V_6 ) ) ;
if ( V_6 == V_7 ) {
F_26 ( V_3 ) ;
F_23 ( V_3 , V_10 , V_91 , 0 , 0 , 0 , NULL ) ;
F_23 ( V_3 , V_12 , V_91 , 0 , 0 , 0 , NULL ) ;
}
}
if ( V_53 != V_92 && V_5 -> V_4 == V_92 )
F_27 ( & V_5 -> V_64 ) ;
#if V_57
F_10 ( V_32 L_11 , V_3 -> V_33 ,
F_4 ( V_6 ) , V_58 [ V_52 ] , V_59 [ V_5 -> V_4 ] ) ;
#endif
}
static void F_28 ( struct V_2 * V_3 , T_1 V_6 , T_3 V_36 ,
unsigned int V_93 , const T_3 * V_17 )
{
static T_3 const V_94 [ 6 ] = { V_95 , 6 , 0 , 0 , 0 , 0 } ;
const T_3 * V_96 ;
T_3 * V_97 ;
unsigned int V_18 = V_93 , V_98 = 0 , V_99 = 0 ;
if ( ! ( V_97 = F_29 ( V_18 , V_100 ) ) ) {
V_3 -> V_101 . V_102 ++ ;
return;
}
for ( V_96 = V_17 ; V_18 ; V_18 -= V_96 [ 1 ] , V_96 += V_96 [ 1 ] ) {
if ( V_18 < 2 || V_18 < V_96 [ 1 ] ) {
V_3 -> V_101 . V_103 ++ ;
F_30 ( V_97 ) ;
return;
}
if ( V_6 == V_7 )
switch ( V_96 [ 0 ] ) {
case V_104 :
continue;
case V_95 :
if ( ! memcmp ( V_96 , V_94 ,
sizeof( V_94 ) ) )
continue;
if ( ! V_99 ) {
memcpy ( V_97 + V_98 , V_94 ,
sizeof( V_94 ) ) ;
V_98 += sizeof( V_94 ) ;
continue;
}
break;
case V_105 :
if ( V_96 [ 1 ] != 6 || ( ! V_96 [ 2 ] && ! V_96 [ 3 ] &&
! V_96 [ 4 ] && ! V_96 [ 5 ] ) )
break;
continue;
}
memcpy ( V_97 + V_99 , V_96 , V_96 [ 1 ] ) ;
V_99 += V_96 [ 1 ] ;
}
if ( V_99 )
F_23 ( V_3 , V_6 , V_106 , V_107 , V_36 , V_99 , V_97 ) ;
else if ( V_98 )
F_23 ( V_3 , V_6 , V_106 , V_108 , V_36 , V_98 , V_97 ) ;
else
F_23 ( V_3 , V_6 , V_109 , V_79 , V_36 , V_93 , V_17 ) ;
F_30 ( V_97 ) ;
}
static int F_31 ( struct V_14 * V_15 )
{
struct V_16 * V_110 = (struct V_16 * ) V_15 -> V_17 ;
struct V_2 * V_3 = V_15 -> V_3 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 ;
struct V_37 * V_38 ;
unsigned long V_111 ;
unsigned int V_18 ;
T_1 V_6 ;
#if V_41
int V_42 ;
char * V_43 ;
#endif
F_32 ( & V_1 -> V_112 , V_111 ) ;
if ( V_15 -> V_18 < sizeof( struct V_16 ) )
goto V_113;
V_38 = (struct V_37 * ) F_8 ( V_15 , sizeof( struct V_16 ) ) ;
if ( V_110 -> V_20 != V_21 ||
V_110 -> V_22 != V_23 )
goto V_113;
V_6 = F_33 ( V_110 -> V_24 ) ;
V_5 = F_3 ( V_3 , V_6 ) ;
if ( ! V_5 ) {
if ( V_1 -> V_8 [ V_9 ] . V_4 == V_86 )
F_15 ( V_3 , V_7 , V_114 ,
++ V_1 -> V_77 , V_15 -> V_18 + 2 , & V_110 -> V_24 ) ;
goto V_113;
}
V_18 = F_33 ( V_38 -> V_18 ) ;
if ( V_18 < sizeof( struct V_37 ) ||
V_15 -> V_18 < V_18 )
goto V_113;
F_8 ( V_15 , sizeof( struct V_37 ) ) ;
V_18 -= sizeof( struct V_37 ) ;
#if V_41
if ( V_38 -> V_35 < V_47 )
sprintf ( V_48 , L_12 , V_49 [ V_38 -> V_35 ] ,
V_38 -> V_36 ) ;
else
sprintf ( V_48 , L_13 , V_38 -> V_35 , V_38 -> V_36 ) ;
V_43 = V_48 + strlen ( V_48 ) ;
for ( V_42 = 0 ; V_42 < F_20 (unsigned int, len, DEBUG_CP) ; V_42 ++ ) {
sprintf ( V_43 , L_6 , V_15 -> V_17 [ V_42 ] ) ;
V_43 += strlen ( V_43 ) ;
}
F_10 ( V_32 L_14 , V_3 -> V_33 , F_4 ( V_6 ) ,
V_48 ) ;
#endif
if ( V_6 == V_7 )
switch ( V_38 -> V_35 ) {
case V_114 :
V_6 = F_33 ( * ( T_2 * ) V_15 -> V_17 ) ;
if ( V_6 == V_7 || V_6 == V_10 ||
V_6 == V_12 )
F_23 ( V_3 , V_6 , V_115 , 0 , 0 ,
0 , NULL ) ;
goto V_97;
case V_44 :
if ( V_18 >= 4 && V_5 -> V_4 == V_86 )
F_15 ( V_3 , V_7 , V_45 ,
V_38 -> V_36 , V_18 - 4 , V_15 -> V_17 + 4 ) ;
goto V_97;
case V_45 :
if ( V_38 -> V_36 == V_1 -> V_116 )
V_1 -> V_89 = V_66 ;
goto V_97;
case V_117 :
goto V_97;
}
switch ( V_38 -> V_35 ) {
case V_75 :
F_28 ( V_3 , V_6 , V_38 -> V_36 , V_18 , V_15 -> V_17 ) ;
goto V_97;
case V_79 :
if ( V_38 -> V_36 == V_5 -> V_76 )
F_23 ( V_3 , V_6 , V_118 , 0 , 0 , 0 , NULL ) ;
goto V_97;
case V_107 :
case V_108 :
if ( V_38 -> V_36 == V_5 -> V_76 )
F_23 ( V_3 , V_6 , V_119 , 0 , 0 , 0 , NULL ) ;
goto V_97;
case V_81 :
F_23 ( V_3 , V_6 , V_120 , 0 , V_38 -> V_36 , 0 , NULL ) ;
goto V_97;
case V_83 :
F_23 ( V_3 , V_6 , V_121 , 0 , 0 , 0 , NULL ) ;
goto V_97;
case V_85 :
F_23 ( V_3 , V_6 , V_115 , 0 , 0 , 0 , NULL ) ;
goto V_97;
default:
V_18 += sizeof( struct V_37 ) ;
if ( V_18 > V_3 -> V_122 )
V_18 = V_3 -> V_122 ;
F_23 ( V_3 , V_6 , V_123 , 0 , 0 , V_18 , V_38 ) ;
goto V_97;
}
goto V_97;
V_113:
V_3 -> V_101 . V_103 ++ ;
V_97:
F_34 ( & V_1 -> V_112 , V_111 ) ;
F_35 ( V_15 ) ;
F_12 () ;
return V_124 ;
}
static void F_36 ( unsigned long V_125 )
{
struct V_5 * V_5 = (struct V_5 * ) V_125 ;
struct V_1 * V_1 = F_1 ( V_5 -> V_3 ) ;
unsigned long V_111 ;
F_32 ( & V_1 -> V_112 , V_111 ) ;
switch ( V_5 -> V_4 ) {
case V_72 :
case V_126 :
case V_127 :
case V_128 :
if ( V_5 -> V_70 ) {
F_23 ( V_5 -> V_3 , V_5 -> V_6 , V_129 , 0 , 0 ,
0 , NULL ) ;
V_5 -> V_70 -- ;
} else
F_23 ( V_5 -> V_3 , V_5 -> V_6 , V_130 , 0 , 0 ,
0 , NULL ) ;
break;
case V_86 :
if ( V_5 -> V_6 != V_7 )
break;
if ( F_37 ( V_66 , V_1 -> V_89 +
V_1 -> V_131 * V_68 ) ) {
F_10 ( V_87 L_15 , V_5 -> V_3 -> V_33 ) ;
F_23 ( V_5 -> V_3 , V_7 , V_91 , 0 , 0 , 0 , NULL ) ;
F_23 ( V_5 -> V_3 , V_7 , V_88 , 0 , 0 , 0 , NULL ) ;
} else {
V_1 -> V_116 = ++ V_1 -> V_77 ;
F_15 ( V_5 -> V_3 , V_7 , V_44 ,
V_1 -> V_116 , 0 , NULL ) ;
V_5 -> V_64 . V_132 = V_66 +
V_1 -> V_90 * V_68 ;
F_38 ( & V_5 -> V_64 ) ;
}
break;
}
F_34 ( & V_1 -> V_112 , V_111 ) ;
F_12 () ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_133 ; V_42 ++ ) {
struct V_5 * V_5 = & V_1 -> V_8 [ V_42 ] ;
V_5 -> V_3 = V_3 ;
F_40 ( & V_5 -> V_64 ) ;
V_5 -> V_64 . V_134 = F_36 ;
V_5 -> V_64 . V_17 = ( unsigned long ) V_5 ;
V_5 -> V_4 = V_92 ;
}
V_1 -> V_8 [ V_9 ] . V_6 = V_7 ;
V_1 -> V_8 [ V_11 ] . V_6 = V_10 ;
V_1 -> V_8 [ V_13 ] . V_6 = V_12 ;
F_23 ( V_3 , V_7 , V_88 , 0 , 0 , 0 , NULL ) ;
}
static void F_41 ( struct V_2 * V_3 )
{
F_23 ( V_3 , V_7 , V_91 , 0 , 0 , 0 , NULL ) ;
}
static void F_42 ( struct V_2 * V_3 )
{
F_12 () ;
}
static int F_43 ( struct V_2 * V_3 , struct V_135 * V_136 )
{
T_5 * V_137 = F_2 ( V_3 ) ;
struct V_1 * V_1 ;
int V_138 ;
switch ( V_136 -> V_139 . type ) {
case V_140 :
if ( F_2 ( V_3 ) -> V_5 != & V_5 )
return - V_141 ;
V_136 -> V_139 . type = V_142 ;
return 0 ;
case V_142 :
if ( ! F_44 ( V_143 ) )
return - V_144 ;
if ( V_3 -> V_111 & V_145 )
return - V_146 ;
V_138 = V_137 -> V_147 ( V_3 , V_148 , V_149 ) ;
if ( V_138 )
return V_138 ;
V_138 = F_45 ( V_3 , & V_5 , sizeof( struct V_1 ) ) ;
if ( V_138 )
return V_138 ;
V_1 = F_1 ( V_3 ) ;
F_46 ( & V_1 -> V_112 ) ;
V_1 -> V_67 = 2 ;
V_1 -> V_74 = 10 ;
V_1 -> V_73 = 2 ;
V_1 -> V_90 = 10 ;
V_1 -> V_131 = 60 ;
V_3 -> V_150 = sizeof( struct V_16 ) ;
V_3 -> V_151 = & V_152 ;
V_3 -> type = V_153 ;
F_26 ( V_3 ) ;
return 0 ;
}
return - V_141 ;
}
static int T_6 F_47 ( void )
{
F_48 ( & V_34 ) ;
F_49 ( & V_5 ) ;
return 0 ;
}
static void T_7 F_50 ( void )
{
F_51 ( & V_5 ) ;
}

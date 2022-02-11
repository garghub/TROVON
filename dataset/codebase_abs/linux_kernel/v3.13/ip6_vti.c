static T_1 F_1 ( const struct V_1 * V_2 , const struct V_1 * V_3 )
{
T_1 V_4 = F_2 ( V_2 ) ^ F_2 ( V_3 ) ;
return F_3 ( V_4 , V_5 ) ;
}
static struct V_6 *
F_4 ( struct V_7 * V_7 , const struct V_1 * V_8 ,
const struct V_1 * V_9 )
{
unsigned int V_4 = F_1 ( V_8 , V_9 ) ;
struct V_6 * V_10 ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
F_6 (ip6n->tnls_r_l[hash]) {
if ( F_7 ( V_9 , & V_10 -> V_14 . V_15 ) &&
F_7 ( V_8 , & V_10 -> V_14 . V_16 ) &&
( V_10 -> V_17 -> V_18 & V_19 ) )
return V_10 ;
}
V_10 = F_8 ( V_12 -> V_20 [ 0 ] ) ;
if ( V_10 && ( V_10 -> V_17 -> V_18 & V_19 ) )
return V_10 ;
return NULL ;
}
static struct V_6 T_2 * *
F_9 ( struct V_11 * V_12 , const struct V_21 * V_22 )
{
const struct V_1 * V_8 = & V_22 -> V_16 ;
const struct V_1 * V_9 = & V_22 -> V_15 ;
unsigned int V_23 = 0 ;
int V_24 = 0 ;
if ( ! F_10 ( V_8 ) || ! F_10 ( V_9 ) ) {
V_24 = 1 ;
V_23 = F_1 ( V_8 , V_9 ) ;
}
return & V_12 -> V_25 [ V_24 ] [ V_23 ] ;
}
static void
F_11 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_26 = F_9 ( V_12 , & V_10 -> V_14 ) ;
F_12 ( V_10 -> V_27 , F_13 ( * V_26 ) ) ;
F_12 ( * V_26 , V_10 ) ;
}
static void
F_14 ( struct V_11 * V_12 , struct V_6 * V_10 )
{
struct V_6 T_2 * * V_26 ;
struct V_6 * V_28 ;
for ( V_26 = F_9 ( V_12 , & V_10 -> V_14 ) ;
( V_28 = F_13 ( * V_26 ) ) != NULL ;
V_26 = & V_28 -> V_27 ) {
if ( V_10 == V_28 ) {
F_12 ( * V_26 , V_10 -> V_27 ) ;
break;
}
}
}
static void F_15 ( struct V_29 * V_17 )
{
F_16 ( V_17 -> V_30 ) ;
F_17 ( V_17 ) ;
}
static int F_18 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_31 ;
V_31 = F_21 ( V_17 ) ;
if ( V_31 < 0 )
goto V_32;
V_31 = F_22 ( V_17 ) ;
if ( V_31 < 0 )
goto V_32;
strcpy ( V_10 -> V_14 . V_33 , V_17 -> V_33 ) ;
V_17 -> V_34 = & V_35 ;
F_23 ( V_17 ) ;
F_11 ( V_12 , V_10 ) ;
return 0 ;
V_32:
return V_31 ;
}
static struct V_6 * F_24 ( struct V_7 * V_7 , struct V_21 * V_22 )
{
struct V_29 * V_17 ;
struct V_6 * V_10 ;
char V_33 [ V_36 ] ;
int V_31 ;
if ( V_22 -> V_33 [ 0 ] )
F_25 ( V_33 , V_22 -> V_33 , V_36 ) ;
else
sprintf ( V_33 , L_1 ) ;
V_17 = F_26 ( sizeof( * V_10 ) , V_33 , V_37 ) ;
if ( V_17 == NULL )
goto V_38;
F_27 ( V_17 , V_7 ) ;
V_10 = F_19 ( V_17 ) ;
V_10 -> V_14 = * V_22 ;
V_10 -> V_7 = F_20 ( V_17 ) ;
V_31 = F_18 ( V_17 ) ;
if ( V_31 < 0 )
goto V_39;
return V_10 ;
V_39:
F_15 ( V_17 ) ;
V_38:
return NULL ;
}
static struct V_6 * F_28 ( struct V_7 * V_7 , struct V_21 * V_22 ,
int V_40 )
{
const struct V_1 * V_8 = & V_22 -> V_16 ;
const struct V_1 * V_9 = & V_22 -> V_15 ;
struct V_6 T_2 * * V_26 ;
struct V_6 * V_10 ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
for ( V_26 = F_9 ( V_12 , V_22 ) ;
( V_10 = F_13 ( * V_26 ) ) != NULL ;
V_26 = & V_10 -> V_27 ) {
if ( F_7 ( V_9 , & V_10 -> V_14 . V_15 ) &&
F_7 ( V_8 , & V_10 -> V_14 . V_16 ) )
return V_10 ;
}
if ( ! V_40 )
return NULL ;
return F_24 ( V_7 , V_22 ) ;
}
static void F_29 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_17 == V_12 -> V_41 )
F_30 ( V_12 -> V_20 [ 0 ] , NULL ) ;
else
F_14 ( V_12 , V_10 ) ;
F_31 ( V_10 ) ;
F_32 ( V_17 ) ;
}
static int F_33 ( struct V_42 * V_43 )
{
struct V_6 * V_10 ;
const struct V_44 * V_45 = F_34 ( V_43 ) ;
F_35 () ;
if ( ( V_10 = F_4 ( F_20 ( V_43 -> V_17 ) , & V_45 -> V_46 ,
& V_45 -> V_47 ) ) != NULL ) {
struct V_48 * V_30 ;
if ( V_10 -> V_14 . V_49 != V_50 && V_10 -> V_14 . V_49 != 0 ) {
F_36 () ;
goto V_51;
}
if ( ! F_37 ( NULL , V_52 , V_43 ) ) {
F_36 () ;
return 0 ;
}
if ( ! F_38 ( V_10 , & V_45 -> V_47 , & V_45 -> V_46 ) ) {
V_10 -> V_17 -> V_53 . V_54 ++ ;
F_36 () ;
goto V_51;
}
V_30 = F_39 ( V_10 -> V_17 -> V_30 ) ;
F_40 ( & V_30 -> V_55 ) ;
V_30 -> V_56 ++ ;
V_30 -> V_57 += V_43 -> V_58 ;
F_41 ( & V_30 -> V_55 ) ;
V_43 -> V_59 = 0 ;
F_42 ( V_43 ) ;
V_43 -> V_17 = V_10 -> V_17 ;
F_36 () ;
return 0 ;
}
F_36 () ;
return 1 ;
V_51:
F_43 ( V_43 ) ;
return 0 ;
}
static inline bool
F_44 ( const struct V_6 * V_10 , const struct V_44 * V_60 )
{
return F_7 ( & V_10 -> V_14 . V_16 , & V_60 -> V_46 ) ;
}
static int F_45 ( struct V_42 * V_43 , struct V_29 * V_17 )
{
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_61 * V_53 = & V_10 -> V_17 -> V_53 ;
struct V_62 * V_63 = NULL , * V_64 = NULL ;
struct V_65 V_66 ;
struct V_44 * V_45 = F_34 ( V_43 ) ;
struct V_29 * V_67 ;
int V_31 = - 1 ;
if ( ( V_10 -> V_14 . V_49 != V_50 && V_10 -> V_14 . V_49 != 0 ) ||
! F_46 ( V_10 ) || F_44 ( V_10 , V_45 ) )
return V_31 ;
V_63 = F_47 ( V_10 ) ;
if ( ! V_63 ) {
memcpy ( & V_66 , & V_10 -> V_68 . V_69 . V_70 , sizeof( V_66 ) ) ;
V_64 = F_48 ( V_7 , NULL , & V_66 ) ;
if ( V_64 -> error )
goto V_71;
V_64 = F_49 ( V_7 , V_64 , F_50 ( & V_66 ) , NULL , 0 ) ;
if ( F_51 ( V_64 ) ) {
V_31 = F_52 ( V_64 ) ;
V_64 = NULL ;
goto V_71;
}
V_63 = V_64 ;
}
if ( ! V_63 -> V_72 || V_63 -> V_72 -> V_73 . V_74 != V_75 )
goto V_71;
V_67 = V_63 -> V_17 ;
if ( V_67 == V_17 ) {
V_53 -> V_76 ++ ;
F_53 ( L_2 ,
V_10 -> V_14 . V_33 ) ;
goto V_77;
}
F_54 ( V_43 ) ;
F_55 ( V_43 , V_63 ) ;
F_56 ( V_43 , V_17 ) ;
if ( V_64 ) {
V_17 -> V_78 = F_57 ( V_64 ) ;
F_58 ( V_10 , V_64 ) ;
}
return 0 ;
V_71:
V_53 -> V_79 ++ ;
F_59 ( V_43 ) ;
V_77:
F_60 ( V_64 ) ;
return V_31 ;
}
static T_3
F_61 ( struct V_42 * V_43 , struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_61 * V_53 = & V_10 -> V_17 -> V_53 ;
int V_80 ;
switch ( V_43 -> V_81 ) {
case F_62 ( V_82 ) :
V_80 = F_45 ( V_43 , V_17 ) ;
break;
default:
goto V_83;
}
if ( V_80 < 0 )
goto V_83;
return V_84 ;
V_83:
V_53 -> V_85 ++ ;
V_53 -> V_86 ++ ;
F_43 ( V_43 ) ;
return V_84 ;
}
static void F_63 ( struct V_6 * V_10 )
{
struct V_62 * V_63 ;
struct V_29 * V_17 = V_10 -> V_17 ;
struct V_21 * V_22 = & V_10 -> V_14 ;
struct V_65 * V_66 = & V_10 -> V_68 . V_69 . V_70 ;
memcpy ( V_17 -> V_87 , & V_22 -> V_15 , sizeof( struct V_1 ) ) ;
memcpy ( V_17 -> V_88 , & V_22 -> V_16 , sizeof( struct V_1 ) ) ;
V_66 -> V_46 = V_22 -> V_15 ;
V_66 -> V_47 = V_22 -> V_16 ;
V_66 -> V_89 = V_22 -> V_90 ;
V_66 -> V_91 = F_64 ( V_22 -> V_92 ) ;
V_66 -> V_93 = V_22 -> V_49 ;
V_66 -> V_94 = 0 ;
V_22 -> V_18 &= ~ ( V_95 | V_96 |
V_97 ) ;
V_22 -> V_18 |= F_65 ( V_10 , & V_22 -> V_15 , & V_22 -> V_16 ) ;
if ( V_22 -> V_18 & V_95 && V_22 -> V_18 & V_96 )
V_17 -> V_18 |= V_98 ;
else
V_17 -> V_18 &= ~ V_98 ;
V_17 -> V_99 = V_22 -> V_90 ;
if ( V_22 -> V_18 & V_95 ) {
V_63 = F_48 ( F_20 ( V_17 ) , NULL , V_66 ) ;
if ( V_63 -> error )
return;
V_63 = F_49 ( F_20 ( V_17 ) , V_63 , F_50 ( V_66 ) ,
NULL , 0 ) ;
if ( F_51 ( V_63 ) )
return;
if ( V_63 -> V_17 ) {
V_17 -> V_100 = V_63 -> V_17 -> V_100 ;
V_17 -> V_78 = F_57 ( V_63 ) ;
if ( V_17 -> V_78 < V_101 )
V_17 -> V_78 = V_101 ;
}
F_60 ( V_63 ) ;
}
}
static int
F_66 ( struct V_6 * V_10 , const struct V_21 * V_22 )
{
V_10 -> V_14 . V_15 = V_22 -> V_15 ;
V_10 -> V_14 . V_16 = V_22 -> V_16 ;
V_10 -> V_14 . V_90 = V_22 -> V_90 ;
V_10 -> V_14 . V_92 = V_22 -> V_92 ;
V_10 -> V_14 . V_102 = V_22 -> V_102 ;
V_10 -> V_14 . V_49 = V_22 -> V_49 ;
F_31 ( V_10 ) ;
F_63 ( V_10 ) ;
return 0 ;
}
static int F_67 ( struct V_6 * V_10 , struct V_21 * V_22 )
{
struct V_7 * V_7 = F_20 ( V_10 -> V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_31 ;
F_14 ( V_12 , V_10 ) ;
F_68 () ;
V_31 = F_66 ( V_10 , V_22 ) ;
F_11 ( V_12 , V_10 ) ;
F_69 ( V_10 -> V_17 ) ;
return V_31 ;
}
static void
F_70 ( struct V_21 * V_22 , const struct V_103 * V_69 )
{
V_22 -> V_15 = V_69 -> V_15 ;
V_22 -> V_16 = V_69 -> V_16 ;
V_22 -> V_90 = V_69 -> V_90 ;
V_22 -> V_92 = V_69 -> V_92 ;
V_22 -> V_102 = V_69 -> V_102 ;
V_22 -> V_49 = V_69 -> V_49 ;
memcpy ( V_22 -> V_33 , V_69 -> V_33 , sizeof( V_69 -> V_33 ) ) ;
}
static void
F_71 ( struct V_103 * V_69 , const struct V_21 * V_22 )
{
V_69 -> V_15 = V_22 -> V_15 ;
V_69 -> V_16 = V_22 -> V_16 ;
V_69 -> V_90 = V_22 -> V_90 ;
V_69 -> V_92 = V_22 -> V_92 ;
V_69 -> V_102 = V_22 -> V_102 ;
V_69 -> V_49 = V_22 -> V_49 ;
memcpy ( V_69 -> V_33 , V_22 -> V_33 , sizeof( V_69 -> V_33 ) ) ;
}
static int
F_72 ( struct V_29 * V_17 , struct V_104 * V_105 , int V_106 )
{
int V_31 = 0 ;
struct V_103 V_22 ;
struct V_21 V_107 ;
struct V_6 * V_10 = NULL ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
switch ( V_106 ) {
case V_108 :
if ( V_17 == V_12 -> V_41 ) {
if ( F_73 ( & V_22 , V_105 -> V_109 . V_110 , sizeof( V_22 ) ) ) {
V_31 = - V_111 ;
break;
}
F_70 ( & V_107 , & V_22 ) ;
V_10 = F_28 ( V_7 , & V_107 , 0 ) ;
} else {
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
}
if ( V_10 == NULL )
V_10 = F_19 ( V_17 ) ;
F_71 ( & V_22 , & V_10 -> V_14 ) ;
if ( F_74 ( V_105 -> V_109 . V_110 , & V_22 , sizeof( V_22 ) ) )
V_31 = - V_111 ;
break;
case V_112 :
case V_113 :
V_31 = - V_114 ;
if ( ! F_75 ( V_7 -> V_115 , V_116 ) )
break;
V_31 = - V_111 ;
if ( F_73 ( & V_22 , V_105 -> V_109 . V_110 , sizeof( V_22 ) ) )
break;
V_31 = - V_117 ;
if ( V_22 . V_49 != V_50 && V_22 . V_49 != 0 )
break;
F_70 ( & V_107 , & V_22 ) ;
V_10 = F_28 ( V_7 , & V_107 , V_106 == V_112 ) ;
if ( V_17 != V_12 -> V_41 && V_106 == V_113 ) {
if ( V_10 != NULL ) {
if ( V_10 -> V_17 != V_17 ) {
V_31 = - V_118 ;
break;
}
} else
V_10 = F_19 ( V_17 ) ;
V_31 = F_67 ( V_10 , & V_107 ) ;
}
if ( V_10 ) {
V_31 = 0 ;
F_71 ( & V_22 , & V_10 -> V_14 ) ;
if ( F_74 ( V_105 -> V_109 . V_110 , & V_22 , sizeof( V_22 ) ) )
V_31 = - V_111 ;
} else
V_31 = ( V_106 == V_112 ? - V_119 : - V_120 ) ;
break;
case V_121 :
V_31 = - V_114 ;
if ( ! F_75 ( V_7 -> V_115 , V_116 ) )
break;
if ( V_17 == V_12 -> V_41 ) {
V_31 = - V_111 ;
if ( F_73 ( & V_22 , V_105 -> V_109 . V_110 , sizeof( V_22 ) ) )
break;
V_31 = - V_120 ;
F_70 ( & V_107 , & V_22 ) ;
V_10 = F_28 ( V_7 , & V_107 , 0 ) ;
if ( V_10 == NULL )
break;
V_31 = - V_114 ;
if ( V_10 -> V_17 == V_12 -> V_41 )
break;
V_17 = V_10 -> V_17 ;
}
V_31 = 0 ;
F_76 ( V_17 ) ;
break;
default:
V_31 = - V_117 ;
}
return V_31 ;
}
static int F_77 ( struct V_29 * V_17 , int V_122 )
{
if ( V_122 < V_101 )
return - V_117 ;
V_17 -> V_78 = V_122 ;
return 0 ;
}
static void V_37 ( struct V_29 * V_17 )
{
struct V_6 * V_10 ;
V_17 -> V_123 = & V_124 ;
V_17 -> V_125 = F_15 ;
V_17 -> type = V_126 ;
V_17 -> V_100 = V_127 + sizeof( struct V_44 ) ;
V_17 -> V_78 = V_128 ;
V_10 = F_19 ( V_17 ) ;
V_17 -> V_18 |= V_129 ;
V_17 -> V_130 = sizeof( struct V_1 ) ;
V_17 -> V_131 |= V_132 ;
V_17 -> V_133 &= ~ V_134 ;
}
static inline int F_78 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
int V_135 ;
V_10 -> V_17 = V_17 ;
V_10 -> V_7 = F_20 ( V_17 ) ;
V_17 -> V_30 = F_79 ( struct V_48 ) ;
if ( ! V_17 -> V_30 )
return - V_136 ;
F_80 (i) {
struct V_48 * V_53 ;
V_53 = F_81 ( V_17 -> V_30 , V_135 ) ;
F_82 ( & V_53 -> V_55 ) ;
}
return 0 ;
}
static int F_21 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
int V_31 = F_78 ( V_17 ) ;
if ( V_31 )
return V_31 ;
F_63 ( V_10 ) ;
return 0 ;
}
static int T_4 F_83 ( struct V_29 * V_17 )
{
struct V_6 * V_10 = F_19 ( V_17 ) ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
int V_31 = F_78 ( V_17 ) ;
if ( V_31 )
return V_31 ;
V_10 -> V_14 . V_49 = V_50 ;
F_23 ( V_17 ) ;
F_63 ( V_10 ) ;
F_12 ( V_12 -> V_20 [ 0 ] , V_10 ) ;
return 0 ;
}
static int F_84 ( struct V_137 * V_138 [] , struct V_137 * V_139 [] )
{
return 0 ;
}
static void F_85 ( struct V_137 * V_139 [] ,
struct V_21 * V_14 )
{
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
if ( ! V_139 )
return;
if ( V_139 [ V_140 ] )
V_14 -> V_90 = F_86 ( V_139 [ V_140 ] ) ;
if ( V_139 [ V_141 ] )
F_87 ( & V_14 -> V_15 , V_139 [ V_141 ] ,
sizeof( struct V_1 ) ) ;
if ( V_139 [ V_142 ] )
F_87 ( & V_14 -> V_16 , V_139 [ V_142 ] ,
sizeof( struct V_1 ) ) ;
if ( V_139 [ V_143 ] )
V_14 -> V_92 = F_88 ( V_139 [ V_143 ] ) ;
if ( V_139 [ V_144 ] )
V_14 -> V_102 = F_88 ( V_139 [ V_144 ] ) ;
}
static int F_89 ( struct V_7 * V_145 , struct V_29 * V_17 ,
struct V_137 * V_138 [] , struct V_137 * V_139 [] )
{
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_6 * V_146 ;
V_146 = F_19 ( V_17 ) ;
F_85 ( V_139 , & V_146 -> V_14 ) ;
V_146 -> V_14 . V_49 = V_50 ;
if ( F_28 ( V_7 , & V_146 -> V_14 , 0 ) )
return - V_118 ;
return F_18 ( V_17 ) ;
}
static int F_90 ( struct V_29 * V_17 , struct V_137 * V_138 [] ,
struct V_137 * V_139 [] )
{
struct V_6 * V_10 ;
struct V_21 V_22 ;
struct V_7 * V_7 = F_20 ( V_17 ) ;
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
if ( V_17 == V_12 -> V_41 )
return - V_117 ;
F_85 ( V_139 , & V_22 ) ;
V_10 = F_28 ( V_7 , & V_22 , 0 ) ;
if ( V_10 ) {
if ( V_10 -> V_17 != V_17 )
return - V_118 ;
} else
V_10 = F_19 ( V_17 ) ;
return F_67 ( V_10 , & V_22 ) ;
}
static T_5 F_91 ( const struct V_29 * V_17 )
{
return
F_92 ( 4 ) +
F_92 ( sizeof( struct V_1 ) ) +
F_92 ( sizeof( struct V_1 ) ) +
F_92 ( 4 ) +
F_92 ( 4 ) +
0 ;
}
static int F_93 ( struct V_42 * V_43 , const struct V_29 * V_17 )
{
struct V_6 * V_147 = F_19 ( V_17 ) ;
struct V_21 * V_148 = & V_147 -> V_14 ;
if ( F_94 ( V_43 , V_140 , V_148 -> V_90 ) ||
F_95 ( V_43 , V_141 , sizeof( struct V_1 ) ,
& V_148 -> V_15 ) ||
F_95 ( V_43 , V_142 , sizeof( struct V_1 ) ,
& V_148 -> V_16 ) ||
F_96 ( V_43 , V_143 , V_148 -> V_92 ) ||
F_96 ( V_43 , V_144 , V_148 -> V_102 ) )
goto V_149;
return 0 ;
V_149:
return - V_150 ;
}
static void T_6 F_97 ( struct V_11 * V_12 )
{
int V_23 ;
struct V_6 * V_10 ;
F_98 ( V_151 ) ;
for ( V_23 = 0 ; V_23 < V_152 ; V_23 ++ ) {
V_10 = F_13 ( V_12 -> V_153 [ V_23 ] ) ;
while ( V_10 != NULL ) {
F_99 ( V_10 -> V_17 , & V_151 ) ;
V_10 = F_13 ( V_10 -> V_27 ) ;
}
}
V_10 = F_13 ( V_12 -> V_20 [ 0 ] ) ;
F_99 ( V_10 -> V_17 , & V_151 ) ;
F_100 ( & V_151 ) ;
}
static int T_4 F_101 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
struct V_6 * V_10 = NULL ;
int V_31 ;
V_12 -> V_25 [ 0 ] = V_12 -> V_20 ;
V_12 -> V_25 [ 1 ] = V_12 -> V_153 ;
V_31 = - V_136 ;
V_12 -> V_41 = F_26 ( sizeof( struct V_6 ) , L_3 ,
V_37 ) ;
if ( ! V_12 -> V_41 )
goto V_154;
F_27 ( V_12 -> V_41 , V_7 ) ;
V_31 = F_83 ( V_12 -> V_41 ) ;
if ( V_31 < 0 )
goto V_155;
V_31 = F_102 ( V_12 -> V_41 ) ;
if ( V_31 < 0 )
goto V_155;
V_10 = F_19 ( V_12 -> V_41 ) ;
strcpy ( V_10 -> V_14 . V_33 , V_12 -> V_41 -> V_33 ) ;
return 0 ;
V_155:
F_15 ( V_12 -> V_41 ) ;
V_154:
return V_31 ;
}
static void T_6 F_103 ( struct V_7 * V_7 )
{
struct V_11 * V_12 = F_5 ( V_7 , V_13 ) ;
F_104 () ;
F_97 ( V_12 ) ;
F_105 () ;
}
static int T_7 F_106 ( void )
{
int V_31 ;
V_31 = F_107 ( & V_156 ) ;
if ( V_31 < 0 )
goto V_157;
V_31 = F_108 ( & V_158 ) ;
if ( V_31 < 0 ) {
F_109 ( L_4 , V_159 ) ;
goto V_32;
}
V_31 = F_110 ( & V_35 ) ;
if ( V_31 < 0 )
goto V_160;
return 0 ;
V_160:
F_111 ( & V_158 ) ;
V_32:
F_112 ( & V_156 ) ;
V_157:
return V_31 ;
}
static void T_8 F_113 ( void )
{
F_114 ( & V_35 ) ;
if ( F_111 ( & V_158 ) )
F_115 ( L_5 , V_159 ) ;
F_112 ( & V_156 ) ;
}

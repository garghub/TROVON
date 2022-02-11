static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_2 ( struct V_1 * V_2 )
{
}
static
struct V_3 * F_3 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
F_4 ( V_9 ) ;
if ( V_9 == NULL )
return NULL ;
V_10 = F_5 ( V_5 , & V_9 -> V_11 ,
& V_12 , V_7 ) ;
if ( V_10 ) {
F_6 ( V_9 ) ;
return NULL ;
}
return & V_9 -> V_11 ;
}
static
void F_7 ( struct V_4 * V_5 , struct V_3 * V_13 )
{
struct V_8 * V_9 = F_8 ( V_13 ) ;
if ( F_9 ( V_5 , V_13 ) )
return;
F_6 ( V_9 ) ;
F_10 ( & V_5 -> V_14 ) ;
F_11 ( V_5 ) ;
}
static
void F_12 ( struct V_3 * V_13 , struct V_15 * V_16 )
{
F_13 ( V_17 , & V_13 -> V_18 ) ;
F_14 ( & V_13 -> V_19 ) ;
F_15 ( & V_13 -> V_20 , V_16 ) ;
}
static
void F_16 ( struct V_3 * V_13 , struct V_15 * V_21 )
{
F_17 ( F_18 ( & V_13 -> V_22 -> V_23 ) ) ;
F_17 ( F_19 ( & V_13 -> V_19 ) > 0 ) ;
F_17 ( F_20 ( V_17 , & V_13 -> V_18 ) ) ;
F_17 ( ! F_21 ( & V_13 -> V_20 ) ) ;
F_22 ( V_17 , & V_13 -> V_18 ) ;
if ( F_23 ( & V_13 -> V_19 ) ) {
F_24 ( & V_13 -> V_20 ) ;
F_15 ( & V_13 -> V_20 , V_21 ) ;
} else {
F_25 ( & V_13 -> V_20 ) ;
}
}
static
int F_26 ( struct V_3 * V_13 ,
struct V_15 * V_21 )
{
if ( F_27 ( V_13 ) ) {
if ( V_21 )
F_16 ( V_13 , V_21 ) ;
return 1 ;
}
return 0 ;
}
static inline
int F_28 ( struct V_3 * V_13 ,
struct V_15 * V_21 )
{
F_17 ( V_13 -> V_22 ) ;
F_17 ( F_19 ( & V_13 -> V_19 ) > 0 ) ;
F_17 ( F_20 ( V_17 , & V_13 -> V_18 ) ) ;
return F_26 ( V_13 , V_21 ) ;
}
static inline
int F_29 ( struct V_3 * V_13 , struct V_6 * V_7 )
{
if ( ! V_13 -> V_24 -> V_25 )
return 1 ;
return V_13 -> V_24 -> V_25 ( V_13 , V_7 ) ;
}
static
void F_30 ( struct V_15 * V_26 )
{
struct V_3 * V_13 ;
while ( ! F_31 ( V_26 ) ) {
V_13 = F_32 ( V_26 -> V_27 , struct V_3 ,
V_20 ) ;
F_17 ( F_19 ( & V_13 -> V_19 ) == 0 ) ;
F_17 ( F_20 ( V_17 ,
& V_13 -> V_18 ) == 0 ) ;
F_25 ( & V_13 -> V_20 ) ;
F_7 ( V_13 -> V_22 , V_13 ) ;
}
}
static
int F_33 ( struct V_3 * V_13 )
{
if ( F_26 ( V_13 , NULL ) )
return 1 ;
if ( F_34 ( V_13 ) )
return 0 ;
return 1 ;
}
static
void F_35 ( struct V_3 * V_13 , int V_28 )
{
F_17 ( V_13 -> V_22 ) ;
F_17 ( F_19 ( & V_13 -> V_19 ) > 0 ) ;
F_36 ( V_13 ) ;
F_37 ( & V_13 -> V_22 -> V_23 ) ;
if ( F_38 ( V_17 , & V_13 -> V_18 ) ) {
F_17 ( ! F_21 ( & V_13 -> V_20 ) ) ;
F_17 ( F_19 ( & V_13 -> V_19 ) > 1 ) ;
F_25 ( & V_13 -> V_20 ) ;
if ( F_23 ( & V_13 -> V_19 ) )
F_39 () ;
}
F_40 ( & V_13 -> V_22 -> V_23 ) ;
}
static inline
unsigned int F_41 ( int V_29 , T_1 V_30 )
{
return ( unsigned int ) ( V_30 & ( ( T_1 ) V_29 - 1 ) ) ;
}
static
void F_42 ( struct V_1 * V_2 ,
struct V_3 * V_31 )
{
struct V_32 * V_33 ;
struct V_3 * V_13 ;
struct V_34 * V_35 ;
F_43 ( V_21 ) ;
unsigned int V_16 ;
V_33 = F_44 ( V_2 , struct V_32 , V_36 ) ;
V_16 = F_41 ( V_33 -> V_37 ,
( T_1 ) V_31 -> V_38 . V_39 ) ;
F_17 ( V_16 < V_33 -> V_37 ) ;
F_37 ( & V_2 -> V_40 . V_23 ) ;
F_45 (ctx, next,
&gsec_pf->gsp_chash[hash], cc_cache) {
if ( ! F_29 ( V_13 , & V_31 -> V_38 ) )
continue;
F_36 ( V_13 ) ;
F_16 ( V_13 , & V_21 ) ;
break;
}
F_12 ( V_31 , & V_33 -> V_41 [ V_16 ] ) ;
F_40 ( & V_2 -> V_40 . V_23 ) ;
F_30 ( & V_21 ) ;
}
static
int F_46 ( struct V_1 * V_2 ,
struct V_42 * V_43 )
{
struct V_6 V_7 ;
struct V_3 * V_44 ;
int V_10 ;
V_7 . V_39 = 0 ;
V_7 . V_45 = 0 ;
V_44 = F_3 ( & V_2 -> V_40 , & V_7 ) ;
if ( ! V_44 )
return - V_46 ;
V_10 = F_47 ( V_44 , V_43 ) ;
if ( V_10 ) {
F_7 ( V_44 -> V_22 , V_44 ) ;
return V_10 ;
}
F_42 ( V_2 , V_44 ) ;
return 0 ;
}
static
void F_48 ( struct V_32 * V_33 ,
struct V_15 * V_21 )
{
struct V_4 * V_5 ;
struct V_3 * V_13 ;
struct V_34 * V_35 ;
int V_47 ;
V_5 = & V_33 -> V_36 . V_40 ;
F_49 ( V_48 , L_1 , V_5 -> V_49 -> V_50 , V_5 ) ;
for ( V_47 = 0 ; V_47 < V_33 -> V_37 ; V_47 ++ ) {
F_45 (ctx, next,
&gsec_pf->gsp_chash[i], cc_cache)
F_28 ( V_13 , V_21 ) ;
}
V_5 -> V_51 = F_50 () + V_5 -> V_52 ;
}
static
struct V_4 * F_51 ( struct V_53 * V_54 ,
struct V_42 * V_13 ,
struct V_55 * V_56 )
{
struct V_32 * V_33 ;
int V_57 , V_58 , V_47 ;
#define F_52 (32)
if ( V_13 ||
V_56 -> V_59 & ( V_60 | V_61 ) )
V_58 = 1 ;
else
V_58 = F_52 ;
V_57 = sizeof( * V_33 ) +
sizeof( struct V_15 ) * V_58 ;
F_53 ( V_33 , V_57 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_37 = V_58 ;
for ( V_47 = 0 ; V_47 < V_58 ; V_47 ++ )
F_54 ( & V_33 -> V_41 [ V_47 ] ) ;
if ( F_55 ( & V_33 -> V_36 , & V_62 ,
V_54 , V_13 , V_56 ) )
goto V_63;
if ( V_13 == NULL ) {
if ( F_1 ( & V_33 -> V_36 ) )
goto V_64;
} else {
if ( F_46 ( & V_33 -> V_36 , V_13 ) )
goto V_64;
}
return & V_33 -> V_36 . V_40 ;
V_64:
F_56 ( & V_33 -> V_36 ) ;
V_63:
F_57 ( V_33 , V_57 ) ;
return NULL ;
}
static
void F_58 ( struct V_4 * V_5 )
{
struct V_32 * V_33 ;
struct V_1 * V_2 ;
F_59 ( L_2 , V_5 -> V_49 -> V_50 , V_5 ) ;
V_2 = F_44 ( V_5 , struct V_1 , V_40 ) ;
V_33 = F_44 ( V_2 , struct V_32 , V_36 ) ;
F_17 ( V_33 -> V_41 ) ;
F_17 ( V_33 -> V_37 ) ;
F_2 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 , sizeof( * V_33 ) +
sizeof( struct V_15 ) * V_33 -> V_37 ) ;
}
static
struct V_3 * F_60 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
int V_65 , int V_66 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_3 * V_13 = NULL , * V_31 = NULL ;
struct V_15 * V_67 ;
struct V_34 * V_35 ;
F_43 ( V_21 ) ;
unsigned int V_16 , V_68 = 0 , V_69 = 0 ;
F_61 () ;
V_2 = F_44 ( V_5 , struct V_1 , V_40 ) ;
V_33 = F_44 ( V_2 , struct V_32 , V_36 ) ;
V_16 = F_41 ( V_33 -> V_37 ,
( T_1 ) V_7 -> V_39 ) ;
V_67 = & V_33 -> V_41 [ V_16 ] ;
F_17 ( V_16 < V_33 -> V_37 ) ;
V_70:
F_37 ( & V_5 -> V_23 ) ;
if ( V_66 && V_5 -> V_51 &&
F_62 ( F_50 () , V_5 -> V_51 ) ) {
F_48 ( V_33 , & V_21 ) ;
V_68 = 1 ;
}
F_45 (ctx, next, hash_head, cc_cache) {
if ( V_68 == 0 &&
F_28 ( V_13 ,
V_66 ? & V_21 : NULL ) )
continue;
if ( F_29 ( V_13 , V_7 ) ) {
V_69 = 1 ;
break;
}
}
if ( V_69 ) {
if ( V_31 && V_31 != V_13 ) {
F_15 ( & V_31 -> V_20 , & V_21 ) ;
V_31 = NULL ;
}
if ( V_67 -> V_27 != & V_13 -> V_20 ) {
F_24 ( & V_13 -> V_20 ) ;
F_15 ( & V_13 -> V_20 , V_67 ) ;
}
} else {
if ( F_63 ( V_5 ) ) {
F_40 ( & V_5 -> V_23 ) ;
return NULL ;
}
if ( V_31 ) {
F_12 ( V_31 , V_67 ) ;
V_13 = V_31 ;
} else if ( V_65 ) {
F_40 ( & V_5 -> V_23 ) ;
V_31 = F_3 ( V_5 , V_7 ) ;
if ( V_31 ) {
F_22 ( V_71 , & V_31 -> V_18 ) ;
goto V_70;
}
} else {
V_13 = NULL ;
}
}
if ( V_13 )
F_14 ( & V_13 -> V_19 ) ;
F_40 ( & V_5 -> V_23 ) ;
if ( V_31 ) {
F_17 ( V_31 == V_13 ) ;
F_64 ( V_31 ) ;
}
F_30 ( & V_21 ) ;
return V_13 ;
}
static
void F_65 ( struct V_4 * V_5 ,
struct V_3 * V_13 ,
int V_72 )
{
F_17 ( F_20 ( V_17 , & V_13 -> V_18 ) == 0 ) ;
F_17 ( F_21 ( & V_13 -> V_20 ) ) ;
if ( ! V_72 )
F_22 ( V_73 , & V_13 -> V_18 ) ;
F_7 ( V_5 , V_13 ) ;
}
static
int F_66 ( struct V_4 * V_5 ,
T_2 V_74 ,
int V_28 , int V_75 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_3 * V_13 ;
struct V_34 * V_35 ;
F_43 ( V_21 ) ;
int V_47 , V_76 = 0 ;
F_67 ( V_28 ) ;
V_2 = F_44 ( V_5 , struct V_1 , V_40 ) ;
V_33 = F_44 ( V_2 , struct V_32 , V_36 ) ;
F_37 ( & V_5 -> V_23 ) ;
for ( V_47 = 0 ; V_47 < V_33 -> V_37 ; V_47 ++ ) {
F_45 (ctx, next,
&gsec_pf->gsp_chash[i],
cc_cache) {
F_17 ( F_19 ( & V_13 -> V_19 ) > 0 ) ;
if ( V_74 != - 1 && V_74 != V_13 -> V_38 . V_39 )
continue;
if ( F_19 ( & V_13 -> V_19 ) > 1 ) {
V_76 ++ ;
if ( ! V_75 )
continue;
F_59 ( L_3
L_4 ,
F_19 ( & V_13 -> V_19 ) ,
V_13 , V_13 -> V_38 . V_39 ,
F_68 ( V_13 -> V_22 ) , V_28 ) ;
}
F_16 ( V_13 , & V_21 ) ;
F_13 ( V_77 , & V_13 -> V_18 ) ;
if ( ! V_28 )
F_22 ( V_73 ,
& V_13 -> V_18 ) ;
}
}
F_40 ( & V_5 -> V_23 ) ;
F_30 ( & V_21 ) ;
return V_76 ;
}
static
int F_69 ( struct V_78 * V_79 )
{
return F_70 ( & V_62 , V_79 ) ;
}
static
int F_71 ( struct V_53 * V_54 ,
struct V_42 * V_13 )
{
struct V_4 * V_5 ;
int V_10 ;
V_5 = F_72 ( V_54 ) ;
F_17 ( V_5 ) ;
V_10 = F_46 ( F_73 ( V_5 ) , V_13 ) ;
F_11 ( V_5 ) ;
return V_10 ;
}
static inline
T_3 F_74 ( void )
{
return ( T_3 ) F_75 ( & V_80 ) ;
}
static inline
T_3 F_76 ( const char * V_81 )
{
F_17 ( ! strcmp ( V_81 , L_5 ) ) ;
return V_82 ;
}
static inline
void F_77 ( int V_83 )
{
F_37 ( & V_84 [ V_83 ] ) ;
}
static inline
void F_78 ( int V_83 )
{
F_40 ( & V_84 [ V_83 ] ) ;
}
static
void F_79 ( struct V_85 * V_86 )
{
T_3 V_83 = V_86 -> V_87 ;
F_77 ( V_83 ) ;
F_80 ( & V_86 -> V_88 , & V_89 [ V_83 ] ) ;
F_78 ( V_83 ) ;
}
static
void F_81 ( struct V_85 * V_86 )
{
T_3 V_83 = V_86 -> V_87 ;
F_77 ( V_83 ) ;
F_82 ( & V_86 -> V_88 ) ;
F_78 ( V_83 ) ;
}
static
void F_83 ( struct V_85 * V_90 )
{
F_17 ( F_19 ( & V_90 -> V_91 ) > 0 ) ;
if ( ! F_23 ( & V_90 -> V_91 ) ) {
return;
}
if ( V_90 -> V_92 ) {
F_84 ( & V_90 -> V_92 -> V_11 ) ;
F_85 ( & V_90 -> V_92 -> V_11 , 1 ) ;
V_90 -> V_92 = NULL ;
}
F_17 ( F_86 ( & V_90 -> V_88 ) ) ;
F_17 ( F_86 ( & V_90 -> V_93 . V_94 ) ) ;
F_6 ( V_90 ) ;
}
static
void F_87 ( struct V_85 * V_90 )
{
T_3 V_83 = V_90 -> V_87 ;
F_17 ( V_83 < V_95 ) ;
F_17 ( F_18 ( & V_84 [ V_83 ] ) ) ;
if ( F_86 ( & V_90 -> V_88 ) )
return;
F_82 ( & V_90 -> V_88 ) ;
F_17 ( F_19 ( & V_90 -> V_91 ) > 1 ) ;
F_10 ( & V_90 -> V_91 ) ;
}
static
void F_88 ( struct V_85 * V_90 )
{
T_3 V_83 = V_90 -> V_87 ;
F_17 ( V_83 < V_95 ) ;
F_77 ( V_83 ) ;
F_87 ( V_90 ) ;
F_78 ( V_83 ) ;
}
static
void F_89 ( struct V_85 * V_90 )
{
if ( V_90 -> V_92 ) {
struct V_3 * V_13 = & V_90 -> V_92 -> V_11 ;
F_17 ( F_19 ( & V_13 -> V_19 ) > 0 ) ;
F_90 ( V_13 ) ;
F_13 ( V_96 , & V_13 -> V_18 ) ;
}
}
static
struct V_85 * F_91 ( T_3 V_97 , T_3 V_98 )
{
struct V_85 * V_90 ;
F_77 ( V_97 ) ;
F_92 (gmsg, &upcall_lists[mechidx], gum_list) {
if ( V_90 -> V_99 . V_100 != V_98 )
continue;
F_17 ( F_19 ( & V_90 -> V_91 ) > 0 ) ;
F_17 ( V_90 -> V_87 == V_97 ) ;
F_14 ( & V_90 -> V_91 ) ;
F_78 ( V_97 ) ;
return V_90 ;
}
F_78 ( V_97 ) ;
return NULL ;
}
static
int F_93 ( char * * V_101 , T_3 * V_102 , void * V_103 , T_3 V_104 )
{
if ( * V_102 < V_104 ) {
F_94 ( L_6 , * V_102 , V_104 ) ;
return - V_105 ;
}
memcpy ( V_103 , * V_101 , V_104 ) ;
* V_101 += V_104 ;
* V_102 -= V_104 ;
return 0 ;
}
static
T_4 F_95 ( struct V_106 * V_107 , struct V_108 * V_86 ,
char * V_109 , T_5 V_102 )
{
char * V_110 = ( char * ) V_86 -> V_110 + V_86 -> V_111 ;
T_4 V_112 = V_86 -> V_113 ;
T_4 V_114 ;
if ( V_112 > V_102 )
V_112 = V_102 ;
V_114 = F_96 ( V_109 , V_110 , V_112 ) ;
if ( V_114 < 0 ) {
V_86 -> V_115 = V_114 ;
return V_114 ;
}
V_112 -= V_114 ;
V_86 -> V_111 += V_112 ;
V_86 -> V_115 = 0 ;
return V_112 ;
}
static
T_4 F_97 ( struct V_106 * V_107 , const char * V_116 , T_5 V_112 )
{
struct V_117 * V_118 = F_98 ( V_107 -> V_119 -> V_120 ) ;
struct V_85 * V_121 ;
struct V_3 * V_13 ;
struct V_8 * V_9 = NULL ;
char * V_101 , * V_110 ;
int V_122 ;
int V_123 , V_10 ;
T_3 V_97 , V_98 , V_124 ;
V_97 = ( T_3 ) ( long ) V_118 -> V_125 ;
F_17 ( V_97 < V_95 ) ;
F_53 ( V_101 , V_112 ) ;
if ( ! V_101 )
return - V_46 ;
if ( F_99 ( V_101 , V_116 , V_112 ) ) {
F_94 ( L_7 ) ;
GOTO ( V_126 , V_10 = - V_127 ) ;
}
V_110 = V_101 ;
V_122 = V_112 ;
if ( F_93 ( & V_110 , & V_122 , & V_98 , sizeof( V_98 ) ) ) {
F_94 ( L_8 ) ;
GOTO ( V_126 , V_10 = - V_127 ) ;
}
V_121 = F_91 ( V_97 , V_98 ) ;
if ( ! V_121 ) {
F_94 ( L_9 , V_98 ) ;
GOTO ( V_126 , V_10 = - V_105 ) ;
}
F_88 ( V_121 ) ;
V_9 = V_121 -> V_92 ;
F_17 ( V_9 ) ;
F_17 ( F_19 ( & V_9 -> V_11 . V_19 ) > 0 ) ;
if ( F_93 ( & V_110 , & V_122 , & V_123 , sizeof( V_123 ) ) )
GOTO ( V_128 , V_10 = - V_127 ) ;
if ( F_93 ( & V_110 , & V_122 , & V_9 -> V_129 ,
sizeof( V_9 -> V_129 ) ) )
GOTO ( V_128 , V_10 = - V_127 ) ;
if ( V_9 -> V_129 == 0 ) {
if ( F_93 ( & V_110 , & V_122 , & V_10 , sizeof( V_10 ) ) )
GOTO ( V_128 , V_10 = - V_127 ) ;
if ( F_93 ( & V_110 , & V_122 , & V_124 , sizeof( V_124 ) ) )
GOTO ( V_128 , V_10 = - V_127 ) ;
if ( V_10 == 0 && V_124 == V_130 ) {
F_59 ( L_10 ) ;
V_10 = - V_131 ;
}
} else {
T_6 V_132 ;
if ( F_100 ( & V_132 , ( T_3 * * ) & V_110 , & V_122 ) )
GOTO ( V_128 , V_10 = - V_127 ) ;
if ( F_101 ( & V_9 -> V_133 , & V_132 ) )
GOTO ( V_128 , V_10 = - V_46 ) ;
if ( F_100 ( & V_132 , ( T_3 * * ) & V_110 , & V_122 ) )
GOTO ( V_128 , V_10 = - V_127 ) ;
V_124 = F_102 ( & V_132 ,
V_121 -> V_134 -> V_135 ,
& V_9 -> V_136 ) ;
V_10 = 0 ;
}
if ( F_103 ( V_10 == 0 && V_124 == V_130 ) ) {
F_104 ( V_9 ) ;
} else {
V_13 = & V_9 -> V_11 ;
F_90 ( V_13 ) ;
if ( V_10 != - V_137 || V_124 != V_130 )
F_13 ( V_96 , & V_13 -> V_18 ) ;
F_94 ( L_11 ,
V_13 , V_13 -> V_38 . V_39 , V_10 , V_124 ,
F_20 ( V_96 , & V_13 -> V_18 ) ?
L_12 : L_13 ) ;
}
V_10 = V_112 ;
V_128:
F_83 ( V_121 ) ;
V_126:
F_57 ( V_101 , V_112 ) ;
V_10 = V_112 ;
return V_10 ;
}
static
void F_105 ( struct V_108 * V_86 )
{
struct V_85 * V_90 ;
struct V_138 * V_139 ;
static T_7 V_140 = 0 ;
F_17 ( F_86 ( & V_86 -> V_94 ) ) ;
if ( V_86 -> V_115 >= 0 ) {
return;
}
V_90 = F_44 ( V_86 , struct V_85 , V_93 ) ;
V_139 = & V_90 -> V_99 ;
F_17 ( F_19 ( & V_90 -> V_91 ) > 0 ) ;
F_94 ( L_14 V_141 L_15
L_16 , V_86 , V_139 -> V_100 , V_139 -> V_142 , V_139 -> V_143 ,
V_139 -> V_144 , ( int ) sizeof( V_139 -> V_145 ) ,
V_139 -> V_145 , V_86 -> V_115 ) ;
F_14 ( & V_90 -> V_91 ) ;
F_88 ( V_90 ) ;
if ( V_86 -> V_115 == - V_146 || V_86 -> V_115 == - V_147 ) {
T_7 V_148 = F_50 () ;
if ( F_62 ( V_148 , V_140 ) ) {
F_59 ( L_17 ) ;
V_140 = V_148 + 15 ;
}
}
F_89 ( V_90 ) ;
F_83 ( V_90 ) ;
}
static
void F_106 ( struct V_149 * V_149 )
{
struct V_117 * V_118 = F_98 ( V_149 ) ;
T_3 V_83 ;
V_83 = ( T_3 ) ( long ) V_118 -> V_125 ;
F_17 ( V_83 < V_95 ) ;
F_77 ( V_83 ) ;
while ( ! F_86 ( & V_89 [ V_83 ] ) ) {
struct V_85 * V_90 ;
struct V_138 * V_139 ;
V_90 = F_107 ( V_89 [ V_83 ] . V_35 ,
struct V_85 , V_88 ) ;
V_139 = & V_90 -> V_99 ;
F_17 ( F_86 ( & V_90 -> V_93 . V_94 ) ) ;
F_94 ( L_18
L_19 V_141 L_20 , V_90 ,
V_139 -> V_100 , V_139 -> V_142 , V_139 -> V_143 ,
V_139 -> V_144 , ( int ) sizeof( V_139 -> V_145 ) ,
V_139 -> V_145 ) ;
V_90 -> V_93 . V_115 = - V_147 ;
F_14 ( & V_90 -> V_91 ) ;
F_87 ( V_90 ) ;
F_89 ( V_90 ) ;
F_78 ( V_83 ) ;
F_83 ( V_90 ) ;
F_77 ( V_83 ) ;
}
F_78 ( V_83 ) ;
}
static
int F_108 ( struct V_3 * V_13 )
{
struct V_53 * V_54 ;
struct V_1 * V_2 ;
struct V_85 * V_90 ;
int V_10 = 0 ;
F_61 () ;
F_17 ( V_13 -> V_22 ) ;
F_17 ( V_13 -> V_22 -> V_150 ) ;
F_17 ( V_13 -> V_22 -> V_150 -> V_151 ) ;
V_54 = V_13 -> V_22 -> V_150 ;
if ( ! V_54 -> V_152 ) {
F_94 ( L_21 ) ;
return - V_105 ;
}
V_2 = F_44 ( V_13 -> V_22 , struct V_1 , V_40 ) ;
F_4 ( V_90 ) ;
if ( ! V_90 )
return - V_46 ;
F_109 ( & V_90 -> V_93 . V_94 ) ;
V_90 -> V_93 . V_110 = & V_90 -> V_99 ;
V_90 -> V_93 . V_113 = sizeof( V_90 -> V_99 ) ;
V_90 -> V_93 . V_111 = 0 ;
V_90 -> V_93 . V_115 = 0 ;
F_110 ( & V_90 -> V_91 , 1 ) ;
V_90 -> V_87 = F_76 ( V_2 -> V_135 -> V_153 ) ;
V_90 -> V_134 = V_2 ;
V_90 -> V_92 = F_44 ( F_111 ( V_13 ) ,
struct V_8 , V_11 ) ;
V_90 -> V_99 . V_100 = F_74 () ;
V_90 -> V_99 . V_142 = V_13 -> V_38 . V_39 ;
V_90 -> V_99 . V_154 = 0 ;
V_90 -> V_99 . V_143 = F_112 ( V_54 ) ;
V_90 -> V_99 . V_144 = V_54 -> V_152 -> V_155 . V_156 ;
strncpy ( V_90 -> V_99 . V_145 , V_54 -> V_151 -> V_157 ,
sizeof( V_90 -> V_99 . V_145 ) ) ;
if ( V_13 -> V_18 & V_158 ) {
F_59 ( L_22 ,
V_13 , V_13 -> V_38 . V_39 , F_68 ( V_13 -> V_22 ) ,
V_13 -> V_18 ) ;
F_17 ( ! ( V_13 -> V_18 & V_159 ) ) ;
V_13 -> V_18 |= V_160 | V_161 ;
V_10 = - V_162 ;
goto V_63;
}
F_79 ( V_90 ) ;
V_10 = F_113 ( V_163 [ V_90 -> V_87 ] -> V_120 ,
& V_90 -> V_93 ) ;
if ( V_10 ) {
F_94 ( L_23 , V_10 ) ;
F_81 ( V_90 ) ;
goto V_63;
}
return 0 ;
V_63:
F_6 ( V_90 ) ;
return V_10 ;
}
static
int F_64 ( struct V_3 * V_13 )
{
if ( V_13 -> V_38 . V_39 == 0 ) {
struct V_1 * V_2 ;
V_2 = F_44 ( V_13 -> V_22 , struct V_1 , V_40 ) ;
V_2 -> V_164 = F_114 () ;
}
return F_108 ( V_13 ) ;
}
static
int T_8 F_115 ( void )
{
struct V_165 * V_166 ;
V_166 = F_116 ( V_167 , NULL ) ;
if ( F_117 ( V_166 ) && F_118 ( V_166 ) != - V_168 ) {
F_94 ( L_24 , F_118 ( V_166 ) ) ;
return F_118 ( V_166 ) ;
}
V_166 = F_119 ( V_169 , ( void * ) V_82 , & V_170 ,
V_171 ) ;
if ( ! V_166 || F_117 ( V_166 ) ) {
F_94 ( L_25 ,
V_169 , F_118 ( V_166 ) ) ;
F_120 ( V_167 ) ;
return F_118 ( V_166 ) ;
}
V_163 [ V_82 ] = V_166 ;
F_109 ( & V_89 [ V_82 ] ) ;
F_121 ( & V_84 [ V_82 ] ) ;
return 0 ;
}
static
void T_9 F_122 ( void )
{
T_3 V_47 ;
for ( V_47 = 0 ; V_47 < V_95 ; V_47 ++ ) {
F_17 ( F_86 ( & V_89 [ V_47 ] ) ) ;
V_163 [ V_47 ] = NULL ;
}
F_123 ( V_169 ) ;
F_120 ( V_167 ) ;
}
int T_8 F_124 ( void )
{
int V_10 ;
V_10 = F_115 () ;
if ( V_10 )
return V_10 ;
V_10 = F_125 ( & V_62 ) ;
if ( V_10 ) {
F_122 () ;
return V_10 ;
}
return 0 ;
}
void T_9 F_126 ( void )
{
F_122 () ;
F_127 ( & V_62 ) ;
}

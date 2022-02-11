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
V_36 ;
V_33 = F_44 ( V_2 , struct V_32 , V_37 ) ;
V_16 = F_41 ( V_33 -> V_38 ,
( T_1 ) V_31 -> V_39 . V_40 ) ;
F_17 ( V_16 < V_33 -> V_38 ) ;
F_37 ( & V_2 -> V_41 . V_23 ) ;
F_45 (ctx, next,
&gsec_pf->gsp_chash[hash], cc_cache) {
if ( ! F_29 ( V_13 , & V_31 -> V_39 ) )
continue;
F_36 ( V_13 ) ;
F_16 ( V_13 , & V_21 ) ;
break;
}
F_12 ( V_31 , & V_33 -> V_42 [ V_16 ] ) ;
F_40 ( & V_2 -> V_41 . V_23 ) ;
F_30 ( & V_21 ) ;
EXIT ;
}
static
int F_46 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_6 V_7 ;
struct V_3 * V_45 ;
int V_10 ;
V_36 ;
V_7 . V_40 = 0 ;
V_7 . V_46 = 0 ;
V_45 = F_3 ( & V_2 -> V_41 , & V_7 ) ;
if ( ! V_45 )
RETURN ( - V_47 ) ;
V_10 = F_47 ( V_45 , V_44 ) ;
if ( V_10 ) {
F_7 ( V_45 -> V_22 , V_45 ) ;
RETURN ( V_10 ) ;
}
F_42 ( V_2 , V_45 ) ;
RETURN ( 0 ) ;
}
static
void F_48 ( struct V_32 * V_33 ,
struct V_15 * V_21 )
{
struct V_4 * V_5 ;
struct V_3 * V_13 ;
struct V_34 * V_35 ;
int V_48 ;
V_36 ;
V_5 = & V_33 -> V_37 . V_41 ;
F_49 ( V_49 , L_1 , V_5 -> V_50 -> V_51 , V_5 ) ;
for ( V_48 = 0 ; V_48 < V_33 -> V_38 ; V_48 ++ ) {
F_45 (ctx, next,
&gsec_pf->gsp_chash[i], cc_cache)
F_28 ( V_13 , V_21 ) ;
}
V_5 -> V_52 = F_50 () + V_5 -> V_53 ;
EXIT ;
}
static
struct V_4 * F_51 ( struct V_54 * V_55 ,
struct V_43 * V_13 ,
struct V_56 * V_57 )
{
struct V_32 * V_33 ;
int V_58 , V_59 , V_48 ;
V_36 ;
#define F_52 (32)
if ( V_13 ||
V_57 -> V_60 & ( V_61 | V_62 ) )
V_59 = 1 ;
else
V_59 = F_52 ;
V_58 = sizeof( * V_33 ) +
sizeof( struct V_15 ) * V_59 ;
F_53 ( V_33 , V_58 ) ;
if ( ! V_33 )
RETURN ( NULL ) ;
V_33 -> V_38 = V_59 ;
for ( V_48 = 0 ; V_48 < V_59 ; V_48 ++ )
F_54 ( & V_33 -> V_42 [ V_48 ] ) ;
if ( F_55 ( & V_33 -> V_37 , & V_63 ,
V_55 , V_13 , V_57 ) )
goto V_64;
if ( V_13 == NULL ) {
if ( F_1 ( & V_33 -> V_37 ) )
goto V_65;
} else {
if ( F_46 ( & V_33 -> V_37 , V_13 ) )
goto V_65;
}
RETURN ( & V_33 -> V_37 . V_41 ) ;
V_65:
F_56 ( & V_33 -> V_37 ) ;
V_64:
F_57 ( V_33 , V_58 ) ;
RETURN ( NULL ) ;
}
static
void F_58 ( struct V_4 * V_5 )
{
struct V_32 * V_33 ;
struct V_1 * V_2 ;
F_59 ( L_2 , V_5 -> V_50 -> V_51 , V_5 ) ;
V_2 = F_44 ( V_5 , struct V_1 , V_41 ) ;
V_33 = F_44 ( V_2 , struct V_32 , V_37 ) ;
F_17 ( V_33 -> V_42 ) ;
F_17 ( V_33 -> V_38 ) ;
F_2 ( V_2 ) ;
F_56 ( V_2 ) ;
F_57 ( V_2 , sizeof( * V_33 ) +
sizeof( struct V_15 ) * V_33 -> V_38 ) ;
}
static
struct V_3 * F_60 ( struct V_4 * V_5 ,
struct V_6 * V_7 ,
int V_66 , int V_67 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_3 * V_13 = NULL , * V_31 = NULL ;
struct V_15 * V_68 ;
struct V_34 * V_35 ;
F_43 ( V_21 ) ;
unsigned int V_16 , V_69 = 0 , V_70 = 0 ;
V_36 ;
F_61 () ;
V_2 = F_44 ( V_5 , struct V_1 , V_41 ) ;
V_33 = F_44 ( V_2 , struct V_32 , V_37 ) ;
V_16 = F_41 ( V_33 -> V_38 ,
( T_1 ) V_7 -> V_40 ) ;
V_68 = & V_33 -> V_42 [ V_16 ] ;
F_17 ( V_16 < V_33 -> V_38 ) ;
V_71:
F_37 ( & V_5 -> V_23 ) ;
if ( V_67 && V_5 -> V_52 &&
F_62 ( F_50 () , V_5 -> V_52 ) ) {
F_48 ( V_33 , & V_21 ) ;
V_69 = 1 ;
}
F_45 (ctx, next, hash_head, cc_cache) {
if ( V_69 == 0 &&
F_28 ( V_13 ,
V_67 ? & V_21 : NULL ) )
continue;
if ( F_29 ( V_13 , V_7 ) ) {
V_70 = 1 ;
break;
}
}
if ( V_70 ) {
if ( V_31 && V_31 != V_13 ) {
F_15 ( & V_31 -> V_20 , & V_21 ) ;
V_31 = NULL ;
}
if ( V_68 -> V_27 != & V_13 -> V_20 ) {
F_24 ( & V_13 -> V_20 ) ;
F_15 ( & V_13 -> V_20 , V_68 ) ;
}
} else {
if ( F_63 ( V_5 ) ) {
F_40 ( & V_5 -> V_23 ) ;
RETURN ( NULL ) ;
}
if ( V_31 ) {
F_12 ( V_31 , V_68 ) ;
V_13 = V_31 ;
} else if ( V_66 ) {
F_40 ( & V_5 -> V_23 ) ;
V_31 = F_3 ( V_5 , V_7 ) ;
if ( V_31 ) {
F_22 ( V_72 , & V_31 -> V_18 ) ;
goto V_71;
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
RETURN ( V_13 ) ;
}
static
void F_65 ( struct V_4 * V_5 ,
struct V_3 * V_13 ,
int V_73 )
{
F_17 ( F_20 ( V_17 , & V_13 -> V_18 ) == 0 ) ;
F_17 ( F_21 ( & V_13 -> V_20 ) ) ;
if ( ! V_73 )
F_22 ( V_74 , & V_13 -> V_18 ) ;
F_7 ( V_5 , V_13 ) ;
}
static
int F_66 ( struct V_4 * V_5 ,
T_2 V_75 ,
int V_28 , int V_76 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
struct V_3 * V_13 ;
struct V_34 * V_35 ;
F_43 ( V_21 ) ;
int V_48 , V_77 = 0 ;
V_36 ;
F_67 ( V_28 ) ;
V_2 = F_44 ( V_5 , struct V_1 , V_41 ) ;
V_33 = F_44 ( V_2 , struct V_32 , V_37 ) ;
F_37 ( & V_5 -> V_23 ) ;
for ( V_48 = 0 ; V_48 < V_33 -> V_38 ; V_48 ++ ) {
F_45 (ctx, next,
&gsec_pf->gsp_chash[i],
cc_cache) {
F_17 ( F_19 ( & V_13 -> V_19 ) > 0 ) ;
if ( V_75 != - 1 && V_75 != V_13 -> V_39 . V_40 )
continue;
if ( F_19 ( & V_13 -> V_19 ) > 1 ) {
V_77 ++ ;
if ( ! V_76 )
continue;
F_59 ( L_3
L_4 ,
F_19 ( & V_13 -> V_19 ) ,
V_13 , V_13 -> V_39 . V_40 ,
F_68 ( V_13 -> V_22 ) , V_28 ) ;
}
F_16 ( V_13 , & V_21 ) ;
F_13 ( V_78 , & V_13 -> V_18 ) ;
if ( ! V_28 )
F_22 ( V_74 ,
& V_13 -> V_18 ) ;
}
}
F_40 ( & V_5 -> V_23 ) ;
F_30 ( & V_21 ) ;
RETURN ( V_77 ) ;
}
static
int F_69 ( struct V_79 * V_80 )
{
return F_70 ( & V_63 , V_80 ) ;
}
static
int F_71 ( struct V_54 * V_55 ,
struct V_43 * V_13 )
{
struct V_4 * V_5 ;
int V_10 ;
V_5 = F_72 ( V_55 ) ;
F_17 ( V_5 ) ;
V_10 = F_46 ( F_73 ( V_5 ) , V_13 ) ;
F_11 ( V_5 ) ;
return V_10 ;
}
static inline
T_3 F_74 ( void )
{
return ( T_3 ) F_75 ( & V_81 ) ;
}
static inline
T_3 F_76 ( const char * V_82 )
{
F_17 ( ! strcmp ( V_82 , L_5 ) ) ;
return V_83 ;
}
static inline
void F_77 ( int V_84 )
{
F_37 ( & V_85 [ V_84 ] ) ;
}
static inline
void F_78 ( int V_84 )
{
F_40 ( & V_85 [ V_84 ] ) ;
}
static
void F_79 ( struct V_86 * V_87 )
{
T_3 V_84 = V_87 -> V_88 ;
F_77 ( V_84 ) ;
F_80 ( & V_87 -> V_89 , & V_90 [ V_84 ] ) ;
F_78 ( V_84 ) ;
}
static
void F_81 ( struct V_86 * V_87 )
{
T_3 V_84 = V_87 -> V_88 ;
F_77 ( V_84 ) ;
F_82 ( & V_87 -> V_89 ) ;
F_78 ( V_84 ) ;
}
static
void F_83 ( struct V_86 * V_91 )
{
V_36 ;
F_17 ( F_19 ( & V_91 -> V_92 ) > 0 ) ;
if ( ! F_23 ( & V_91 -> V_92 ) ) {
EXIT ;
return;
}
if ( V_91 -> V_93 ) {
F_84 ( & V_91 -> V_93 -> V_11 ) ;
F_85 ( & V_91 -> V_93 -> V_11 , 1 ) ;
V_91 -> V_93 = NULL ;
}
F_17 ( F_86 ( & V_91 -> V_89 ) ) ;
F_17 ( F_86 ( & V_91 -> V_94 . V_95 ) ) ;
F_6 ( V_91 ) ;
EXIT ;
}
static
void F_87 ( struct V_86 * V_91 )
{
T_3 V_84 = V_91 -> V_88 ;
F_17 ( V_84 < V_96 ) ;
F_17 ( F_18 ( & V_85 [ V_84 ] ) ) ;
if ( F_86 ( & V_91 -> V_89 ) )
return;
F_82 ( & V_91 -> V_89 ) ;
F_17 ( F_19 ( & V_91 -> V_92 ) > 1 ) ;
F_10 ( & V_91 -> V_92 ) ;
}
static
void F_88 ( struct V_86 * V_91 )
{
T_3 V_84 = V_91 -> V_88 ;
F_17 ( V_84 < V_96 ) ;
F_77 ( V_84 ) ;
F_87 ( V_91 ) ;
F_78 ( V_84 ) ;
}
static
void F_89 ( struct V_86 * V_91 )
{
if ( V_91 -> V_93 ) {
struct V_3 * V_13 = & V_91 -> V_93 -> V_11 ;
F_17 ( F_19 ( & V_13 -> V_19 ) > 0 ) ;
F_90 ( V_13 ) ;
F_13 ( V_97 , & V_13 -> V_18 ) ;
}
}
static
struct V_86 * F_91 ( T_3 V_98 , T_3 V_99 )
{
struct V_86 * V_91 ;
F_77 ( V_98 ) ;
F_92 (gmsg, &upcall_lists[mechidx], gum_list) {
if ( V_91 -> V_100 . V_101 != V_99 )
continue;
F_17 ( F_19 ( & V_91 -> V_92 ) > 0 ) ;
F_17 ( V_91 -> V_88 == V_98 ) ;
F_14 ( & V_91 -> V_92 ) ;
F_78 ( V_98 ) ;
return V_91 ;
}
F_78 ( V_98 ) ;
return NULL ;
}
static
int F_93 ( char * * V_102 , T_3 * V_103 , void * V_104 , T_3 V_105 )
{
if ( * V_103 < V_105 ) {
F_94 ( L_6 , * V_103 , V_105 ) ;
return - V_106 ;
}
memcpy ( V_104 , * V_102 , V_105 ) ;
* V_102 += V_105 ;
* V_103 -= V_105 ;
return 0 ;
}
static
T_4 F_95 ( struct V_107 * V_108 , struct V_109 * V_87 ,
char * V_110 , T_5 V_103 )
{
char * V_111 = ( char * ) V_87 -> V_111 + V_87 -> V_112 ;
T_4 V_113 = V_87 -> V_114 ;
T_4 V_115 ;
V_36 ;
if ( V_113 > V_103 )
V_113 = V_103 ;
V_115 = F_96 ( V_110 , V_111 , V_113 ) ;
if ( V_115 < 0 ) {
V_87 -> V_116 = V_115 ;
RETURN ( V_115 ) ;
}
V_113 -= V_115 ;
V_87 -> V_112 += V_113 ;
V_87 -> V_116 = 0 ;
RETURN ( V_113 ) ;
}
static
T_4 F_97 ( struct V_107 * V_108 , const char * V_117 , T_5 V_113 )
{
struct V_118 * V_119 = F_98 ( V_108 -> V_120 -> V_121 ) ;
struct V_86 * V_122 ;
struct V_3 * V_13 ;
struct V_8 * V_9 = NULL ;
char * V_102 , * V_111 ;
int V_123 ;
int V_124 , V_10 ;
T_3 V_98 , V_99 , V_125 ;
V_36 ;
V_98 = ( T_3 ) ( long ) V_119 -> V_126 ;
F_17 ( V_98 < V_96 ) ;
F_53 ( V_102 , V_113 ) ;
if ( ! V_102 )
RETURN ( - V_47 ) ;
if ( F_99 ( V_102 , V_117 , V_113 ) ) {
F_94 ( L_7 ) ;
GOTO ( V_127 , V_10 = - V_128 ) ;
}
V_111 = V_102 ;
V_123 = V_113 ;
if ( F_93 ( & V_111 , & V_123 , & V_99 , sizeof( V_99 ) ) ) {
F_94 ( L_8 ) ;
GOTO ( V_127 , V_10 = - V_128 ) ;
}
V_122 = F_91 ( V_98 , V_99 ) ;
if ( ! V_122 ) {
F_94 ( L_9 , V_99 ) ;
GOTO ( V_127 , V_10 = - V_106 ) ;
}
F_88 ( V_122 ) ;
V_9 = V_122 -> V_93 ;
F_17 ( V_9 ) ;
F_17 ( F_19 ( & V_9 -> V_11 . V_19 ) > 0 ) ;
if ( F_93 ( & V_111 , & V_123 , & V_124 , sizeof( V_124 ) ) )
GOTO ( V_129 , V_10 = - V_128 ) ;
if ( F_93 ( & V_111 , & V_123 , & V_9 -> V_130 ,
sizeof( V_9 -> V_130 ) ) )
GOTO ( V_129 , V_10 = - V_128 ) ;
if ( V_9 -> V_130 == 0 ) {
if ( F_93 ( & V_111 , & V_123 , & V_10 , sizeof( V_10 ) ) )
GOTO ( V_129 , V_10 = - V_128 ) ;
if ( F_93 ( & V_111 , & V_123 , & V_125 , sizeof( V_125 ) ) )
GOTO ( V_129 , V_10 = - V_128 ) ;
if ( V_10 == 0 && V_125 == V_131 ) {
F_59 ( L_10 ) ;
V_10 = - V_132 ;
}
} else {
T_6 V_133 ;
if ( F_100 ( & V_133 , ( T_3 * * ) & V_111 , & V_123 ) )
GOTO ( V_129 , V_10 = - V_128 ) ;
if ( F_101 ( & V_9 -> V_134 , & V_133 ) )
GOTO ( V_129 , V_10 = - V_47 ) ;
if ( F_100 ( & V_133 , ( T_3 * * ) & V_111 , & V_123 ) )
GOTO ( V_129 , V_10 = - V_128 ) ;
V_125 = F_102 ( & V_133 ,
V_122 -> V_135 -> V_136 ,
& V_9 -> V_137 ) ;
V_10 = 0 ;
}
if ( F_103 ( V_10 == 0 && V_125 == V_131 ) ) {
F_104 ( V_9 ) ;
} else {
V_13 = & V_9 -> V_11 ;
F_90 ( V_13 ) ;
if ( V_10 != - V_138 || V_125 != V_131 )
F_13 ( V_97 , & V_13 -> V_18 ) ;
F_94 ( L_11 ,
V_13 , V_13 -> V_39 . V_40 , V_10 , V_125 ,
F_20 ( V_97 , & V_13 -> V_18 ) ?
L_12 : L_13 ) ;
}
V_10 = V_113 ;
V_129:
F_83 ( V_122 ) ;
V_127:
F_57 ( V_102 , V_113 ) ;
V_10 = V_113 ;
RETURN ( V_10 ) ;
}
static
void F_105 ( struct V_109 * V_87 )
{
struct V_86 * V_91 ;
struct V_139 * V_140 ;
static T_7 V_141 = 0 ;
V_36 ;
F_17 ( F_86 ( & V_87 -> V_95 ) ) ;
if ( V_87 -> V_116 >= 0 ) {
EXIT ;
return;
}
V_91 = F_44 ( V_87 , struct V_86 , V_94 ) ;
V_140 = & V_91 -> V_100 ;
F_17 ( F_19 ( & V_91 -> V_92 ) > 0 ) ;
F_94 ( L_14 V_142 L_15
L_16 , V_87 , V_140 -> V_101 , V_140 -> V_143 , V_140 -> V_144 ,
V_140 -> V_145 , ( int ) sizeof( V_140 -> V_146 ) ,
V_140 -> V_146 , V_87 -> V_116 ) ;
F_14 ( & V_91 -> V_92 ) ;
F_88 ( V_91 ) ;
if ( V_87 -> V_116 == - V_147 || V_87 -> V_116 == - V_148 ) {
T_7 V_149 = F_50 () ;
if ( F_62 ( V_149 , V_141 ) ) {
F_59 ( L_17 ) ;
V_141 = V_149 + 15 ;
}
}
F_89 ( V_91 ) ;
F_83 ( V_91 ) ;
EXIT ;
}
static
void F_106 ( struct V_150 * V_150 )
{
struct V_118 * V_119 = F_98 ( V_150 ) ;
T_3 V_84 ;
V_36 ;
V_84 = ( T_3 ) ( long ) V_119 -> V_126 ;
F_17 ( V_84 < V_96 ) ;
F_77 ( V_84 ) ;
while ( ! F_86 ( & V_90 [ V_84 ] ) ) {
struct V_86 * V_91 ;
struct V_139 * V_140 ;
V_91 = F_107 ( V_90 [ V_84 ] . V_35 ,
struct V_86 , V_89 ) ;
V_140 = & V_91 -> V_100 ;
F_17 ( F_86 ( & V_91 -> V_94 . V_95 ) ) ;
F_94 ( L_18
L_19 V_142 L_20 , V_91 ,
V_140 -> V_101 , V_140 -> V_143 , V_140 -> V_144 ,
V_140 -> V_145 , ( int ) sizeof( V_140 -> V_146 ) ,
V_140 -> V_146 ) ;
V_91 -> V_94 . V_116 = - V_148 ;
F_14 ( & V_91 -> V_92 ) ;
F_87 ( V_91 ) ;
F_89 ( V_91 ) ;
F_78 ( V_84 ) ;
F_83 ( V_91 ) ;
F_77 ( V_84 ) ;
}
F_78 ( V_84 ) ;
EXIT ;
}
static
int F_108 ( struct V_3 * V_13 )
{
struct V_54 * V_55 ;
struct V_1 * V_2 ;
struct V_86 * V_91 ;
int V_10 = 0 ;
V_36 ;
F_61 () ;
F_17 ( V_13 -> V_22 ) ;
F_17 ( V_13 -> V_22 -> V_151 ) ;
F_17 ( V_13 -> V_22 -> V_151 -> V_152 ) ;
V_55 = V_13 -> V_22 -> V_151 ;
if ( ! V_55 -> V_153 ) {
F_94 ( L_21 ) ;
RETURN ( - V_106 ) ;
}
V_2 = F_44 ( V_13 -> V_22 , struct V_1 , V_41 ) ;
F_4 ( V_91 ) ;
if ( ! V_91 )
RETURN ( - V_47 ) ;
F_109 ( & V_91 -> V_94 . V_95 ) ;
V_91 -> V_94 . V_111 = & V_91 -> V_100 ;
V_91 -> V_94 . V_114 = sizeof( V_91 -> V_100 ) ;
V_91 -> V_94 . V_112 = 0 ;
V_91 -> V_94 . V_116 = 0 ;
F_110 ( & V_91 -> V_92 , 1 ) ;
V_91 -> V_88 = F_76 ( V_2 -> V_136 -> V_154 ) ;
V_91 -> V_135 = V_2 ;
V_91 -> V_93 = F_44 ( F_111 ( V_13 ) ,
struct V_8 , V_11 ) ;
V_91 -> V_100 . V_101 = F_74 () ;
V_91 -> V_100 . V_143 = V_13 -> V_39 . V_40 ;
V_91 -> V_100 . V_155 = 0 ;
V_91 -> V_100 . V_144 = F_112 ( V_55 ) ;
V_91 -> V_100 . V_145 = V_55 -> V_153 -> V_156 . V_157 ;
strncpy ( V_91 -> V_100 . V_146 , V_55 -> V_152 -> V_158 ,
sizeof( V_91 -> V_100 . V_146 ) ) ;
if ( V_13 -> V_18 & V_159 ) {
F_59 ( L_22 ,
V_13 , V_13 -> V_39 . V_40 , F_68 ( V_13 -> V_22 ) ,
V_13 -> V_18 ) ;
F_17 ( ! ( V_13 -> V_18 & V_160 ) ) ;
V_13 -> V_18 |= V_161 | V_162 ;
V_10 = - V_163 ;
goto V_64;
}
F_79 ( V_91 ) ;
V_10 = F_113 ( V_164 [ V_91 -> V_88 ] -> V_121 ,
& V_91 -> V_94 ) ;
if ( V_10 ) {
F_94 ( L_23 , V_10 ) ;
F_81 ( V_91 ) ;
goto V_64;
}
RETURN ( 0 ) ;
V_64:
F_6 ( V_91 ) ;
RETURN ( V_10 ) ;
}
static
int F_64 ( struct V_3 * V_13 )
{
if ( V_13 -> V_39 . V_40 == 0 ) {
struct V_1 * V_2 ;
V_2 = F_44 ( V_13 -> V_22 , struct V_1 , V_41 ) ;
V_2 -> V_165 = F_114 () ;
}
return F_108 ( V_13 ) ;
}
static
int T_8 F_115 ( void )
{
struct V_166 * V_167 ;
V_167 = F_116 ( V_168 , NULL ) ;
if ( F_117 ( V_167 ) && F_118 ( V_167 ) != - V_169 ) {
F_94 ( L_24 , F_118 ( V_167 ) ) ;
return F_118 ( V_167 ) ;
}
V_167 = F_119 ( V_170 , ( void * ) V_83 , & V_171 ,
V_172 ) ;
if ( ! V_167 || F_117 ( V_167 ) ) {
F_94 ( L_25 ,
V_170 , F_118 ( V_167 ) ) ;
F_120 ( V_168 ) ;
return F_118 ( V_167 ) ;
}
V_164 [ V_83 ] = V_167 ;
F_109 ( & V_90 [ V_83 ] ) ;
F_121 ( & V_85 [ V_83 ] ) ;
return 0 ;
}
static
void T_9 F_122 ( void )
{
T_3 V_48 ;
for ( V_48 = 0 ; V_48 < V_96 ; V_48 ++ ) {
F_17 ( F_86 ( & V_90 [ V_48 ] ) ) ;
V_164 [ V_48 ] = NULL ;
}
F_123 ( V_170 ) ;
F_120 ( V_168 ) ;
}
int T_8 F_124 ( void )
{
int V_10 ;
V_10 = F_115 () ;
if ( V_10 )
return V_10 ;
V_10 = F_125 ( & V_63 ) ;
if ( V_10 ) {
F_122 () ;
return V_10 ;
}
return 0 ;
}
void T_9 F_126 ( void )
{
F_122 () ;
F_127 ( & V_63 ) ;
}

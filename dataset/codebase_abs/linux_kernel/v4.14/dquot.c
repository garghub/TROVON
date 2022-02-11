void F_1 ( struct V_1 * V_2 , const char * V_3 ,
const char * V_4 , ... )
{
if ( F_2 () ) {
T_1 args ;
struct V_5 V_6 ;
va_start ( args , V_4 ) ;
V_6 . V_4 = V_4 ;
V_6 . V_7 = & args ;
F_3 ( V_8 L_1 ,
V_2 -> V_9 , V_3 , & V_6 ) ;
va_end ( args ) ;
}
}
int F_4 ( struct V_10 * V_4 )
{
F_5 ( & V_11 ) ;
V_4 -> V_12 = V_13 ;
V_13 = V_4 ;
F_6 ( & V_11 ) ;
return 0 ;
}
void F_7 ( struct V_10 * V_4 )
{
struct V_10 * * V_14 ;
F_5 ( & V_11 ) ;
for ( V_14 = & V_13 ; * V_14 && * V_14 != V_4 ;
V_14 = & ( * V_14 ) -> V_12 )
;
if ( * V_14 )
* V_14 = ( * V_14 ) -> V_12 ;
F_6 ( & V_11 ) ;
}
static struct V_10 * F_8 ( int V_15 )
{
struct V_10 * V_14 ;
F_5 ( & V_11 ) ;
for ( V_14 = V_13 ; V_14 && V_14 -> V_16 != V_15 ;
V_14 = V_14 -> V_12 )
;
if ( ! V_14 || ! F_9 ( V_14 -> V_17 ) ) {
int V_18 ;
F_6 ( & V_11 ) ;
for ( V_18 = 0 ; V_19 [ V_18 ] . V_20 &&
V_19 [ V_18 ] . V_20 != V_15 ; V_18 ++ )
;
if ( ! V_19 [ V_18 ] . V_20 ||
F_10 ( V_19 [ V_18 ] . V_21 ) )
return NULL ;
F_5 ( & V_11 ) ;
for ( V_14 = V_13 ; V_14 && V_14 -> V_16 != V_15 ;
V_14 = V_14 -> V_12 )
;
if ( V_14 && ! F_9 ( V_14 -> V_17 ) )
V_14 = NULL ;
}
F_6 ( & V_11 ) ;
return V_14 ;
}
static void F_11 ( struct V_10 * V_4 )
{
F_12 ( V_4 -> V_17 ) ;
}
static inline unsigned int
F_13 ( const struct V_1 * V_2 , struct V_22 V_23 )
{
unsigned int V_15 = F_14 ( & V_24 , V_23 ) ;
int type = V_23 . type ;
unsigned long V_25 ;
V_25 = ( ( ( unsigned long ) V_2 >> V_26 ) ^ V_15 ) * ( V_27 - type ) ;
return ( V_25 + ( V_25 >> V_28 ) ) & V_29 ;
}
static inline void F_15 ( struct V_30 * V_30 )
{
struct V_31 * V_32 ;
V_32 = V_33 + F_13 ( V_30 -> V_34 , V_30 -> V_35 ) ;
F_16 ( & V_30 -> V_36 , V_32 ) ;
}
static inline void F_17 ( struct V_30 * V_30 )
{
F_18 ( & V_30 -> V_36 ) ;
}
static struct V_30 * F_19 ( unsigned int V_37 , struct V_1 * V_2 ,
struct V_22 V_23 )
{
struct V_38 * V_39 ;
struct V_30 * V_30 ;
F_20 (node, dquot_hash+hashent) {
V_30 = F_21 ( V_39 , struct V_30 , V_36 ) ;
if ( V_30 -> V_34 == V_2 && F_22 ( V_30 -> V_35 , V_23 ) )
return V_30 ;
}
return NULL ;
}
static inline void F_23 ( struct V_30 * V_30 )
{
F_24 ( & V_30 -> V_40 , & V_41 ) ;
F_25 ( V_42 ) ;
}
static inline void F_26 ( struct V_30 * V_30 )
{
if ( F_27 ( & V_30 -> V_40 ) )
return;
F_28 ( & V_30 -> V_40 ) ;
F_29 ( V_42 ) ;
}
static inline void F_30 ( struct V_30 * V_30 )
{
F_24 ( & V_30 -> V_43 , & V_44 ) ;
F_25 ( V_45 ) ;
}
static inline void F_31 ( struct V_30 * V_30 )
{
F_29 ( V_45 ) ;
F_32 ( & V_30 -> V_43 ) ;
}
static void F_33 ( struct V_30 * V_30 )
{
F_34 ( & V_30 -> V_46 ) ;
F_35 ( & V_30 -> V_46 ) ;
}
static inline int F_36 ( struct V_30 * V_30 )
{
return F_37 ( V_47 , & V_30 -> V_48 ) ;
}
static inline int F_38 ( struct V_30 * V_30 )
{
return V_30 -> V_34 -> V_49 -> V_50 ( V_30 ) ;
}
int F_39 ( struct V_30 * V_30 )
{
int V_51 = 1 ;
if ( ! F_37 ( V_52 , & V_30 -> V_48 ) )
return 0 ;
if ( F_40 ( V_30 -> V_34 ) -> V_53 & V_54 )
return F_41 ( V_47 , & V_30 -> V_48 ) ;
if ( F_37 ( V_47 , & V_30 -> V_48 ) )
return 1 ;
F_5 ( & V_11 ) ;
if ( ! F_41 ( V_47 , & V_30 -> V_48 ) ) {
F_42 ( & V_30 -> V_55 , & F_40 ( V_30 -> V_34 ) ->
V_56 [ V_30 -> V_35 . type ] . V_57 ) ;
V_51 = 0 ;
}
F_6 ( & V_11 ) ;
return V_51 ;
}
static inline int F_43 ( struct V_30 * const * V_30 )
{
int V_51 , V_58 , V_59 ;
V_51 = V_58 = 0 ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( V_30 [ V_59 ] )
V_51 = F_38 ( V_30 [ V_59 ] ) ;
if ( ! V_58 )
V_58 = V_51 ;
}
return V_58 ;
}
static inline void F_44 ( struct V_30 * * V_30 )
{
unsigned int V_59 ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ )
F_45 ( V_30 [ V_59 ] ) ;
}
static inline int F_46 ( struct V_30 * V_30 )
{
if ( F_40 ( V_30 -> V_34 ) -> V_53 & V_54 )
return F_47 ( V_47 , & V_30 -> V_48 ) ;
F_5 ( & V_11 ) ;
if ( ! F_47 ( V_47 , & V_30 -> V_48 ) ) {
F_6 ( & V_11 ) ;
return 0 ;
}
F_28 ( & V_30 -> V_55 ) ;
F_6 ( & V_11 ) ;
return 1 ;
}
void F_48 ( struct V_1 * V_2 , int type )
{
F_5 ( & V_60 ) ;
F_40 ( V_2 ) -> V_56 [ type ] . V_61 |= V_62 ;
F_6 ( & V_60 ) ;
}
int F_49 ( struct V_30 * V_30 )
{
int V_51 = 0 , V_63 = 0 ;
struct V_64 * V_65 = F_40 ( V_30 -> V_34 ) ;
F_34 ( & V_30 -> V_46 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) )
V_51 = V_65 -> V_67 [ V_30 -> V_35 . type ] -> F_50 ( V_30 ) ;
if ( V_51 < 0 )
goto V_68;
F_51 () ;
F_52 ( V_66 , & V_30 -> V_48 ) ;
if ( ! F_37 ( V_52 , & V_30 -> V_48 ) && ! V_30 -> V_69 ) {
V_51 = V_65 -> V_67 [ V_30 -> V_35 . type ] -> F_53 ( V_30 ) ;
if ( F_54 ( & V_65 -> V_56 [ V_30 -> V_35 . type ] ) ) {
V_63 = V_65 -> V_67 [ V_30 -> V_35 . type ] -> F_55 (
V_30 -> V_34 , V_30 -> V_35 . type ) ;
}
if ( V_51 < 0 )
goto V_68;
if ( V_63 < 0 ) {
V_51 = V_63 ;
goto V_68;
}
}
F_51 () ;
F_52 ( V_52 , & V_30 -> V_48 ) ;
V_68:
F_35 ( & V_30 -> V_46 ) ;
return V_51 ;
}
int F_56 ( struct V_30 * V_30 )
{
int V_51 = 0 ;
struct V_64 * V_65 = F_40 ( V_30 -> V_34 ) ;
F_34 ( & V_30 -> V_46 ) ;
if ( ! F_46 ( V_30 ) )
goto V_70;
if ( F_37 ( V_52 , & V_30 -> V_48 ) )
V_51 = V_65 -> V_67 [ V_30 -> V_35 . type ] -> F_53 ( V_30 ) ;
else
V_51 = - V_71 ;
V_70:
F_35 ( & V_30 -> V_46 ) ;
return V_51 ;
}
int F_57 ( struct V_30 * V_30 )
{
int V_51 = 0 , V_63 = 0 ;
struct V_64 * V_65 = F_40 ( V_30 -> V_34 ) ;
F_34 ( & V_30 -> V_46 ) ;
if ( F_58 ( & V_30 -> V_72 ) > 1 )
goto V_73;
if ( V_65 -> V_67 [ V_30 -> V_35 . type ] -> V_74 ) {
V_51 = V_65 -> V_67 [ V_30 -> V_35 . type ] -> V_74 ( V_30 ) ;
if ( F_54 ( & V_65 -> V_56 [ V_30 -> V_35 . type ] ) ) {
V_63 = V_65 -> V_67 [ V_30 -> V_35 . type ] -> F_55 (
V_30 -> V_34 , V_30 -> V_35 . type ) ;
}
if ( V_51 >= 0 )
V_51 = V_63 ;
}
F_59 ( V_52 , & V_30 -> V_48 ) ;
V_73:
F_35 ( & V_30 -> V_46 ) ;
return V_51 ;
}
void F_60 ( struct V_30 * V_30 )
{
F_61 ( V_75 , V_30 ) ;
}
static inline void F_62 ( struct V_30 * V_30 )
{
V_30 -> V_34 -> V_49 -> V_76 ( V_30 ) ;
}
static void F_63 ( struct V_1 * V_2 , int type )
{
struct V_30 * V_30 , * V_25 ;
V_77:
F_5 ( & V_11 ) ;
F_64 (dquot, tmp, &inuse_list, dq_inuse) {
if ( V_30 -> V_34 != V_2 )
continue;
if ( V_30 -> V_35 . type != type )
continue;
if ( F_58 ( & V_30 -> V_72 ) ) {
F_65 ( V_30 ) ;
F_6 ( & V_11 ) ;
F_66 ( V_78 ,
F_58 ( & V_30 -> V_72 ) == 1 ) ;
F_45 ( V_30 ) ;
goto V_77;
}
F_17 ( V_30 ) ;
F_26 ( V_30 ) ;
F_31 ( V_30 ) ;
F_62 ( V_30 ) ;
}
F_6 ( & V_11 ) ;
}
int F_67 ( struct V_1 * V_2 ,
int (* F_68)( struct V_30 * V_30 , unsigned long V_79 ) ,
unsigned long V_79 )
{
struct V_30 * V_30 , * V_80 = NULL ;
int V_51 = 0 ;
F_69 ( ! F_70 ( & V_2 -> V_81 ) ) ;
F_5 ( & V_11 ) ;
F_71 (dquot, &inuse_list, dq_inuse) {
if ( ! F_37 ( V_52 , & V_30 -> V_48 ) )
continue;
if ( V_30 -> V_34 != V_2 )
continue;
F_72 ( & V_30 -> V_72 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
F_45 ( V_80 ) ;
V_80 = V_30 ;
F_33 ( V_30 ) ;
if ( F_37 ( V_52 , & V_30 -> V_48 ) ) {
V_51 = F_68 ( V_30 , V_79 ) ;
if ( V_51 < 0 )
goto V_83;
}
F_5 ( & V_11 ) ;
}
F_6 ( & V_11 ) ;
V_83:
F_45 ( V_80 ) ;
return V_51 ;
}
int F_73 ( struct V_1 * V_2 , int type )
{
struct V_84 * V_85 ;
struct V_30 * V_30 ;
struct V_64 * V_65 = F_40 ( V_2 ) ;
int V_59 ;
int V_58 , V_51 = 0 ;
F_69 ( ! F_70 ( & V_2 -> V_81 ) ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( type != - 1 && V_59 != type )
continue;
if ( ! F_74 ( V_2 , V_59 ) )
continue;
F_5 ( & V_11 ) ;
V_85 = & V_65 -> V_56 [ V_59 ] . V_57 ;
while ( ! F_27 ( V_85 ) ) {
V_30 = F_75 ( V_85 , struct V_30 ,
V_55 ) ;
F_76 ( ! F_37 ( V_52 , & V_30 -> V_48 ) ) ;
F_65 ( V_30 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
V_58 = V_2 -> V_49 -> V_86 ( V_30 ) ;
if ( ! V_51 && V_58 )
V_51 = V_58 ;
F_45 ( V_30 ) ;
F_5 ( & V_11 ) ;
}
F_6 ( & V_11 ) ;
}
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ )
if ( ( V_59 == type || type == - 1 ) && F_74 ( V_2 , V_59 )
&& F_54 ( & V_65 -> V_56 [ V_59 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_59 ) ;
F_25 ( V_88 ) ;
return V_51 ;
}
int F_77 ( struct V_1 * V_2 , int type )
{
struct V_64 * V_65 = F_40 ( V_2 ) ;
int V_59 ;
int V_51 ;
V_51 = F_73 ( V_2 , type ) ;
if ( V_51 )
return V_51 ;
if ( V_65 -> V_53 & V_89 )
return 0 ;
if ( V_2 -> V_90 -> V_91 )
V_2 -> V_90 -> V_91 ( V_2 , 1 ) ;
F_78 ( V_2 -> V_92 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( type != - 1 && V_59 != type )
continue;
if ( ! F_74 ( V_2 , V_59 ) )
continue;
F_79 ( V_65 -> V_93 [ V_59 ] ) ;
F_80 ( & V_65 -> V_93 [ V_59 ] -> V_94 , 0 ) ;
F_81 ( V_65 -> V_93 [ V_59 ] ) ;
}
return 0 ;
}
static unsigned long
F_82 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
struct V_84 * V_32 ;
struct V_30 * V_30 ;
unsigned long V_99 = 0 ;
F_5 ( & V_11 ) ;
V_32 = V_41 . V_100 ;
while ( V_32 != & V_41 && V_98 -> V_101 ) {
V_30 = F_83 ( V_32 , struct V_30 , V_40 ) ;
F_17 ( V_30 ) ;
F_26 ( V_30 ) ;
F_31 ( V_30 ) ;
F_62 ( V_30 ) ;
V_98 -> V_101 -- ;
V_99 ++ ;
V_32 = V_41 . V_100 ;
}
F_6 ( & V_11 ) ;
return V_99 ;
}
static unsigned long
F_84 ( struct V_95 * V_96 , struct V_97 * V_98 )
{
return F_85 (
F_86 ( & V_102 . V_103 [ V_42 ] ) ) ;
}
void F_45 ( struct V_30 * V_30 )
{
int V_51 ;
if ( ! V_30 )
return;
#ifdef F_87
if ( ! F_58 ( & V_30 -> V_72 ) ) {
F_88 ( V_30 -> V_34 , L_2 ,
V_104 [ V_30 -> V_35 . type ] ,
F_14 ( & V_24 , V_30 -> V_35 ) ) ;
F_89 () ;
}
#endif
F_25 ( V_105 ) ;
V_106:
F_5 ( & V_11 ) ;
if ( F_58 ( & V_30 -> V_72 ) > 1 ) {
F_90 ( & V_30 -> V_72 ) ;
if ( ! F_74 ( V_30 -> V_34 , V_30 -> V_35 . type ) &&
F_58 ( & V_30 -> V_72 ) == 1 )
F_91 ( & V_78 ) ;
F_6 ( & V_11 ) ;
return;
}
if ( F_36 ( V_30 ) ) {
F_6 ( & V_11 ) ;
V_51 = V_30 -> V_34 -> V_49 -> V_86 ( V_30 ) ;
if ( V_51 < 0 ) {
F_88 ( V_30 -> V_34 , L_3
L_4 ,
V_51 ) ;
F_46 ( V_30 ) ;
}
goto V_106;
}
if ( F_37 ( V_52 , & V_30 -> V_48 ) ) {
F_6 ( & V_11 ) ;
V_30 -> V_34 -> V_49 -> V_107 ( V_30 ) ;
goto V_106;
}
F_90 ( & V_30 -> V_72 ) ;
#ifdef F_87
F_92 ( ! F_27 ( & V_30 -> V_40 ) ) ;
#endif
F_23 ( V_30 ) ;
F_6 ( & V_11 ) ;
}
struct V_30 * F_93 ( struct V_1 * V_2 , int type )
{
return F_94 ( V_75 , V_108 ) ;
}
static struct V_30 * F_95 ( struct V_1 * V_2 , int type )
{
struct V_30 * V_30 ;
V_30 = V_2 -> V_49 -> V_109 ( V_2 , type ) ;
if( ! V_30 )
return NULL ;
F_96 ( & V_30 -> V_46 ) ;
F_97 ( & V_30 -> V_40 ) ;
F_97 ( & V_30 -> V_43 ) ;
F_98 ( & V_30 -> V_36 ) ;
F_97 ( & V_30 -> V_55 ) ;
V_30 -> V_34 = V_2 ;
V_30 -> V_35 = F_99 ( type ) ;
F_100 ( & V_30 -> V_72 , 1 ) ;
F_101 ( & V_30 -> V_110 ) ;
return V_30 ;
}
struct V_30 * F_102 ( struct V_1 * V_2 , struct V_22 V_23 )
{
unsigned int V_37 = F_13 ( V_2 , V_23 ) ;
struct V_30 * V_30 , * V_111 = NULL ;
if ( ! F_103 ( V_2 -> V_112 , V_23 ) )
return F_104 ( - V_113 ) ;
if ( ! F_74 ( V_2 , V_23 . type ) )
return F_104 ( - V_114 ) ;
V_106:
F_5 ( & V_11 ) ;
F_5 ( & V_115 ) ;
if ( ! F_74 ( V_2 , V_23 . type ) ) {
F_6 ( & V_115 ) ;
F_6 ( & V_11 ) ;
V_30 = F_104 ( - V_114 ) ;
goto V_83;
}
F_6 ( & V_115 ) ;
V_30 = F_19 ( V_37 , V_2 , V_23 ) ;
if ( ! V_30 ) {
if ( ! V_111 ) {
F_6 ( & V_11 ) ;
V_111 = F_95 ( V_2 , V_23 . type ) ;
if ( ! V_111 )
F_105 () ;
goto V_106;
}
V_30 = V_111 ;
V_111 = NULL ;
V_30 -> V_35 = V_23 ;
F_30 ( V_30 ) ;
F_15 ( V_30 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
} else {
if ( ! F_58 ( & V_30 -> V_72 ) )
F_26 ( V_30 ) ;
F_72 ( & V_30 -> V_72 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_116 ) ;
F_25 ( V_82 ) ;
}
F_33 ( V_30 ) ;
if ( ! F_37 ( V_52 , & V_30 -> V_48 ) ) {
int V_58 ;
V_58 = V_2 -> V_49 -> V_117 ( V_30 ) ;
if ( V_58 < 0 ) {
F_45 ( V_30 ) ;
V_30 = F_104 ( V_58 ) ;
goto V_83;
}
}
F_106 () ;
#ifdef F_87
F_92 ( ! V_30 -> V_34 ) ;
#endif
V_83:
if ( V_111 )
F_62 ( V_111 ) ;
return V_30 ;
}
static inline struct V_30 * * F_107 ( struct V_118 * V_118 )
{
return V_118 -> V_119 -> V_90 -> V_120 ( V_118 ) ;
}
static int F_108 ( struct V_118 * V_118 , int type )
{
struct V_30 * const * V_121 ;
int V_59 ;
if ( F_109 ( V_118 ) )
return 0 ;
V_121 = F_107 ( V_118 ) ;
if ( type != - 1 )
return ! V_121 [ type ] ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ )
if ( ! V_121 [ V_59 ] )
return 1 ;
return 0 ;
}
static void F_110 ( struct V_1 * V_2 , int type )
{
struct V_118 * V_118 , * V_122 = NULL ;
#ifdef F_87
int V_123 = 0 ;
#endif
F_5 ( & V_2 -> V_124 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_118 -> V_125 ) ;
if ( ( V_118 -> V_126 & ( V_127 | V_128 | V_129 ) ) ||
! F_58 ( & V_118 -> V_130 ) ||
! F_108 ( V_118 , type ) ) {
F_6 ( & V_118 -> V_125 ) ;
continue;
}
F_111 ( V_118 ) ;
F_6 ( & V_118 -> V_125 ) ;
F_6 ( & V_2 -> V_124 ) ;
#ifdef F_87
if ( F_112 ( F_113 ( V_118 ) > 0 ) )
V_123 = 1 ;
#endif
F_114 ( V_122 ) ;
F_115 ( V_118 , type ) ;
V_122 = V_118 ;
F_5 ( & V_2 -> V_124 ) ;
}
F_6 ( & V_2 -> V_124 ) ;
F_114 ( V_122 ) ;
#ifdef F_87
if ( V_123 ) {
F_88 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static void F_116 ( struct V_118 * V_118 , int type ,
struct V_84 * V_131 )
{
struct V_30 * * V_121 = F_107 ( V_118 ) ;
struct V_30 * V_30 = V_121 [ type ] ;
if ( ! V_30 )
return;
V_121 [ type ] = NULL ;
if ( F_27 ( & V_30 -> V_40 ) ) {
F_5 ( & V_11 ) ;
F_42 ( & V_30 -> V_40 , V_131 ) ;
F_6 ( & V_11 ) ;
} else {
F_45 ( V_30 ) ;
}
}
static void F_117 ( struct V_84 * V_131 )
{
struct V_84 * V_132 ;
struct V_30 * V_30 ;
V_132 = V_131 -> V_133 ;
while ( V_132 != V_131 ) {
V_30 = F_83 ( V_132 , struct V_30 , V_40 ) ;
V_132 = V_132 -> V_133 ;
F_28 ( & V_30 -> V_40 ) ;
F_45 ( V_30 ) ;
}
}
static void F_118 ( struct V_1 * V_2 , int type ,
struct V_84 * V_131 )
{
struct V_118 * V_118 ;
int V_123 = 0 ;
F_5 ( & V_2 -> V_124 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_60 ) ;
if ( ! F_109 ( V_118 ) ) {
if ( F_112 ( F_113 ( V_118 ) > 0 ) )
V_123 = 1 ;
F_116 ( V_118 , type , V_131 ) ;
}
F_6 ( & V_60 ) ;
}
F_6 ( & V_2 -> V_124 ) ;
#ifdef F_87
if ( V_123 ) {
F_3 ( V_134 L_8
L_9
L_10 , V_2 -> V_9 ) ;
}
#endif
}
static void F_119 ( struct V_1 * V_2 , int type )
{
F_120 ( V_131 ) ;
if ( V_2 -> V_49 ) {
F_118 ( V_2 , type , & V_131 ) ;
F_121 ( & V_135 ) ;
F_117 ( & V_131 ) ;
}
}
static inline
void F_122 ( struct V_30 * V_30 , T_2 V_136 )
{
if ( V_30 -> V_137 . V_138 >= V_136 )
V_30 -> V_137 . V_138 -= V_136 ;
else {
F_69 ( 1 ) ;
V_30 -> V_137 . V_138 = 0 ;
}
if ( V_30 -> V_137 . V_139 + V_30 -> V_137 . V_138 <=
V_30 -> V_137 . V_140 )
V_30 -> V_137 . V_141 = ( V_142 ) 0 ;
F_59 ( V_143 , & V_30 -> V_48 ) ;
}
static void F_123 ( struct V_30 * V_30 , T_2 V_136 )
{
if ( F_40 ( V_30 -> V_34 ) -> V_53 & V_144 ||
V_30 -> V_137 . V_145 >= V_136 )
V_30 -> V_137 . V_145 -= V_136 ;
else
V_30 -> V_137 . V_145 = 0 ;
if ( V_30 -> V_137 . V_145 <= V_30 -> V_137 . V_146 )
V_30 -> V_137 . V_147 = ( V_142 ) 0 ;
F_59 ( V_148 , & V_30 -> V_48 ) ;
}
static void F_124 ( struct V_30 * V_30 , T_2 V_136 )
{
if ( F_40 ( V_30 -> V_34 ) -> V_53 & V_144 ||
V_30 -> V_137 . V_139 >= V_136 )
V_30 -> V_137 . V_139 -= V_136 ;
else
V_30 -> V_137 . V_139 = 0 ;
if ( V_30 -> V_137 . V_139 + V_30 -> V_137 . V_138 <=
V_30 -> V_137 . V_140 )
V_30 -> V_137 . V_141 = ( V_142 ) 0 ;
F_59 ( V_143 , & V_30 -> V_48 ) ;
}
static int F_125 ( struct V_30 * V_30 , const int V_149 )
{
int V_150 = ( V_149 == V_151 ||
V_149 == V_152 ) ? V_143 :
( ( V_149 == V_153 ||
V_149 == V_154 ) ? V_148 : 0 ) ;
if ( ! V_150 )
return 0 ;
return F_41 ( V_150 , & V_30 -> V_48 ) ;
}
static int F_126 ( struct V_155 * V_156 )
{
if ( ! V_157 )
return 0 ;
switch ( V_156 -> V_158 . type ) {
case V_159 :
return F_127 ( F_128 () , V_156 -> V_158 . V_160 ) ;
case V_161 :
return F_129 ( V_156 -> V_158 . V_162 ) ;
case V_163 :
return 1 ;
}
return 0 ;
}
static void F_130 ( struct V_155 * V_156 )
{
char * V_164 = NULL ;
struct V_165 * V_166 ;
int V_149 = V_156 -> V_167 ;
if ( V_149 == V_168 ||
V_149 == V_169 ||
V_149 == V_170 ||
V_149 == V_171 || ! F_126 ( V_156 ) )
return;
V_166 = F_131 () ;
if ( ! V_166 )
return;
F_132 ( V_166 , V_156 -> V_172 -> V_9 ) ;
if ( V_149 == V_173 || V_149 == V_174 )
F_132 ( V_166 , L_11 ) ;
else
F_132 ( V_166 , L_12 ) ;
F_132 ( V_166 , V_104 [ V_156 -> V_158 . type ] ) ;
switch ( V_149 ) {
case V_153 :
V_164 = L_13 ;
break;
case V_154 :
V_164 = L_14 ;
break;
case V_173 :
V_164 = L_15 ;
break;
case V_151 :
V_164 = L_16 ;
break;
case V_152 :
V_164 = L_17 ;
break;
case V_174 :
V_164 = L_18 ;
break;
}
F_132 ( V_166 , V_164 ) ;
F_133 ( V_166 ) ;
}
static void F_134 ( struct V_155 * V_156 , struct V_30 * V_30 ,
int V_149 )
{
if ( F_125 ( V_30 , V_149 ) )
return;
V_156 -> V_167 = V_149 ;
V_156 -> V_172 = V_30 -> V_34 ;
V_156 -> V_158 = V_30 -> V_35 ;
}
static void F_135 ( struct V_155 * V_156 )
{
int V_175 ;
for ( V_175 = 0 ; V_175 < V_27 ; V_175 ++ ) {
if ( V_156 [ V_175 ] . V_167 == V_176 )
continue;
#ifdef F_136
F_130 ( & V_156 [ V_175 ] ) ;
#endif
F_137 ( V_156 [ V_175 ] . V_158 ,
V_156 [ V_175 ] . V_172 -> V_177 , V_156 [ V_175 ] . V_167 ) ;
}
}
static int F_138 ( struct V_30 * V_30 )
{
struct V_178 * V_56 = & F_40 ( V_30 -> V_34 ) -> V_56 [ V_30 -> V_35 . type ] ;
return F_139 ( V_179 ) &&
( V_56 -> V_180 -> V_16 != V_181 ||
! ( V_56 -> V_61 & V_182 ) ) ;
}
static int F_140 ( struct V_30 * V_30 , T_2 V_183 ,
struct V_155 * V_156 )
{
T_2 V_184 ;
int V_51 = 0 ;
F_5 ( & V_30 -> V_110 ) ;
V_184 = V_30 -> V_137 . V_145 + V_183 ;
if ( ! F_141 ( V_30 -> V_34 , V_30 -> V_35 . type ) ||
F_37 ( V_185 , & V_30 -> V_48 ) )
goto V_186;
if ( V_30 -> V_137 . V_187 &&
V_184 > V_30 -> V_137 . V_187 &&
! F_138 ( V_30 ) ) {
F_134 ( V_156 , V_30 , V_153 ) ;
V_51 = - V_188 ;
goto V_83;
}
if ( V_30 -> V_137 . V_146 &&
V_184 > V_30 -> V_137 . V_146 &&
V_30 -> V_137 . V_147 &&
F_142 () >= V_30 -> V_137 . V_147 &&
! F_138 ( V_30 ) ) {
F_134 ( V_156 , V_30 , V_154 ) ;
V_51 = - V_188 ;
goto V_83;
}
if ( V_30 -> V_137 . V_146 &&
V_184 > V_30 -> V_137 . V_146 &&
V_30 -> V_137 . V_147 == 0 ) {
F_134 ( V_156 , V_30 , V_173 ) ;
V_30 -> V_137 . V_147 = F_142 () +
F_40 ( V_30 -> V_34 ) -> V_56 [ V_30 -> V_35 . type ] . V_189 ;
}
V_186:
V_30 -> V_137 . V_145 = V_184 ;
V_83:
F_6 ( & V_30 -> V_110 ) ;
return V_51 ;
}
static int F_143 ( struct V_30 * V_30 , T_2 V_190 ,
T_2 V_191 , unsigned int V_53 ,
struct V_155 * V_156 )
{
T_2 V_192 ;
struct V_1 * V_2 = V_30 -> V_34 ;
int V_51 = 0 ;
F_5 ( & V_30 -> V_110 ) ;
if ( ! F_141 ( V_2 , V_30 -> V_35 . type ) ||
F_37 ( V_185 , & V_30 -> V_48 ) )
goto V_193;
V_192 = V_30 -> V_137 . V_139 + V_30 -> V_137 . V_138
+ V_190 + V_191 ;
if ( V_30 -> V_137 . V_194 &&
V_192 > V_30 -> V_137 . V_194 &&
! F_138 ( V_30 ) ) {
if ( V_53 & V_195 )
F_134 ( V_156 , V_30 , V_151 ) ;
V_51 = - V_188 ;
goto V_193;
}
if ( V_30 -> V_137 . V_140 &&
V_192 > V_30 -> V_137 . V_140 &&
V_30 -> V_137 . V_141 &&
F_142 () >= V_30 -> V_137 . V_141 &&
! F_138 ( V_30 ) ) {
if ( V_53 & V_195 )
F_134 ( V_156 , V_30 , V_152 ) ;
V_51 = - V_188 ;
goto V_193;
}
if ( V_30 -> V_137 . V_140 &&
V_192 > V_30 -> V_137 . V_140 &&
V_30 -> V_137 . V_141 == 0 ) {
if ( V_53 & V_195 ) {
F_134 ( V_156 , V_30 , V_174 ) ;
V_30 -> V_137 . V_141 = F_142 () +
F_40 ( V_2 ) -> V_56 [ V_30 -> V_35 . type ] . V_196 ;
} else {
V_51 = - V_188 ;
goto V_193;
}
}
V_193:
if ( V_53 & V_197 )
V_51 = 0 ;
if ( ! V_51 ) {
V_30 -> V_137 . V_138 += V_191 ;
V_30 -> V_137 . V_139 += V_190 ;
}
F_6 ( & V_30 -> V_110 ) ;
return V_51 ;
}
static int F_144 ( struct V_30 * V_30 , T_2 V_183 )
{
T_2 V_184 ;
if ( F_37 ( V_185 , & V_30 -> V_48 ) ||
V_30 -> V_137 . V_145 <= V_30 -> V_137 . V_146 ||
! F_141 ( V_30 -> V_34 , V_30 -> V_35 . type ) )
return V_176 ;
V_184 = V_30 -> V_137 . V_145 - V_183 ;
if ( V_184 <= V_30 -> V_137 . V_146 )
return V_169 ;
if ( V_30 -> V_137 . V_145 >= V_30 -> V_137 . V_187 &&
V_184 < V_30 -> V_137 . V_187 )
return V_168 ;
return V_176 ;
}
static int F_145 ( struct V_30 * V_30 , T_2 V_190 )
{
T_2 V_192 ;
V_192 = V_30 -> V_137 . V_139 + V_30 -> V_137 . V_138 ;
if ( F_37 ( V_185 , & V_30 -> V_48 ) ||
V_192 <= V_30 -> V_137 . V_140 )
return V_176 ;
if ( V_192 - V_190 <= V_30 -> V_137 . V_140 )
return V_171 ;
if ( V_192 >= V_30 -> V_137 . V_194 &&
V_192 - V_190 < V_30 -> V_137 . V_194 )
return V_170 ;
return V_176 ;
}
static int F_146 ( const struct V_118 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_119 ;
if ( F_109 ( V_118 ) )
return 0 ;
return F_147 ( V_2 ) & ~ F_148 ( V_2 ) ;
}
static int F_115 ( struct V_118 * V_118 , int type )
{
int V_59 , V_198 = 0 ;
struct V_30 * * V_121 , * V_199 [ V_27 ] = {} ;
struct V_1 * V_2 = V_118 -> V_119 ;
T_2 V_200 ;
int V_51 = 0 ;
if ( ! F_146 ( V_118 ) )
return 0 ;
V_121 = F_107 ( V_118 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
struct V_22 V_23 ;
T_3 V_201 ;
int V_202 ;
struct V_30 * V_30 ;
if ( type != - 1 && V_59 != type )
continue;
if ( V_121 [ V_59 ] )
continue;
if ( ! F_74 ( V_2 , V_59 ) )
continue;
V_198 = 1 ;
switch ( V_59 ) {
case V_159 :
V_23 = F_149 ( V_118 -> V_203 ) ;
break;
case V_161 :
V_23 = F_150 ( V_118 -> V_204 ) ;
break;
case V_163 :
V_202 = V_118 -> V_119 -> V_49 -> V_205 ( V_118 , & V_201 ) ;
if ( V_202 )
continue;
V_23 = F_151 ( V_201 ) ;
break;
}
V_30 = F_102 ( V_2 , V_23 ) ;
if ( F_152 ( V_30 ) ) {
if ( F_153 ( V_30 ) != - V_114 ) {
V_51 = F_153 ( V_30 ) ;
goto V_206;
}
V_30 = NULL ;
}
V_199 [ V_59 ] = V_30 ;
}
if ( ! V_198 )
return 0 ;
F_5 ( & V_60 ) ;
if ( F_109 ( V_118 ) )
goto V_70;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( type != - 1 && V_59 != type )
continue;
if ( ! F_74 ( V_2 , V_59 ) )
continue;
if ( ! V_199 [ V_59 ] )
continue;
if ( ! V_121 [ V_59 ] ) {
V_121 [ V_59 ] = V_199 [ V_59 ] ;
V_199 [ V_59 ] = NULL ;
V_200 = F_113 ( V_118 ) ;
if ( F_112 ( V_200 ) ) {
F_5 ( & V_118 -> V_125 ) ;
V_200 = F_154 ( V_118 ) ;
F_5 ( & V_121 [ V_59 ] -> V_110 ) ;
V_121 [ V_59 ] -> V_137 . V_138 += V_200 ;
F_6 ( & V_121 [ V_59 ] -> V_110 ) ;
F_6 ( & V_118 -> V_125 ) ;
}
}
}
V_70:
F_6 ( & V_60 ) ;
V_206:
F_44 ( V_199 ) ;
return V_51 ;
}
int F_155 ( struct V_118 * V_118 )
{
return F_115 ( V_118 , - 1 ) ;
}
bool F_156 ( struct V_118 * V_118 )
{
struct V_30 * * V_121 ;
int V_175 ;
if ( ! F_146 ( V_118 ) )
return false ;
V_121 = F_107 ( V_118 ) ;
for ( V_175 = 0 ; V_175 < V_27 ; V_175 ++ )
if ( ! V_121 [ V_175 ] && F_74 ( V_118 -> V_119 , V_175 ) )
return true ;
return false ;
}
static void F_157 ( struct V_118 * V_118 )
{
int V_59 ;
struct V_30 * * V_121 = F_107 ( V_118 ) ;
struct V_30 * V_207 [ V_27 ] ;
F_5 ( & V_60 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
V_207 [ V_59 ] = V_121 [ V_59 ] ;
V_121 [ V_59 ] = NULL ;
}
F_6 ( & V_60 ) ;
F_44 ( V_207 ) ;
}
void F_158 ( struct V_118 * V_118 )
{
struct V_30 * const * V_121 ;
int V_59 ;
if ( F_109 ( V_118 ) )
return;
V_121 = F_107 ( V_118 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( V_121 [ V_59 ] )
break;
}
if ( V_59 < V_27 )
F_157 ( V_118 ) ;
}
static T_2 * F_159 ( struct V_118 * V_118 )
{
F_92 ( ! V_118 -> V_119 -> V_49 -> V_208 ) ;
return V_118 -> V_119 -> V_49 -> V_208 ( V_118 ) ;
}
static T_2 F_154 ( struct V_118 * V_118 )
{
if ( ! V_118 -> V_119 -> V_49 -> V_208 )
return 0 ;
return * F_159 ( V_118 ) ;
}
static T_2 F_113 ( struct V_118 * V_118 )
{
T_2 V_51 ;
if ( ! V_118 -> V_119 -> V_49 -> V_208 )
return 0 ;
F_5 ( & V_118 -> V_125 ) ;
V_51 = F_154 ( V_118 ) ;
F_6 ( & V_118 -> V_125 ) ;
return V_51 ;
}
int F_160 ( struct V_118 * V_118 , T_2 V_136 , int V_53 )
{
int V_59 , V_51 = 0 , V_209 ;
struct V_155 V_156 [ V_27 ] ;
int V_210 = V_53 & V_211 ;
struct V_30 * * V_121 ;
if ( ! F_146 ( V_118 ) ) {
if ( V_210 ) {
F_5 ( & V_118 -> V_125 ) ;
* F_159 ( V_118 ) += V_136 ;
F_6 ( & V_118 -> V_125 ) ;
} else {
F_161 ( V_118 , V_136 ) ;
}
goto V_83;
}
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ )
V_156 [ V_59 ] . V_167 = V_176 ;
V_121 = F_107 ( V_118 ) ;
V_209 = F_162 ( & V_135 ) ;
F_5 ( & V_118 -> V_125 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( ! V_121 [ V_59 ] )
continue;
if ( V_53 & V_211 ) {
V_51 = F_143 ( V_121 [ V_59 ] , 0 , V_136 , V_53 ,
& V_156 [ V_59 ] ) ;
} else {
V_51 = F_143 ( V_121 [ V_59 ] , V_136 , 0 , V_53 ,
& V_156 [ V_59 ] ) ;
}
if ( V_51 ) {
for ( V_59 -- ; V_59 >= 0 ; V_59 -- ) {
if ( ! V_121 [ V_59 ] )
continue;
F_5 ( & V_121 [ V_59 ] -> V_110 ) ;
if ( V_53 & V_211 ) {
V_121 [ V_59 ] -> V_137 . V_138 -=
V_136 ;
} else {
V_121 [ V_59 ] -> V_137 . V_139 -=
V_136 ;
}
F_6 ( & V_121 [ V_59 ] -> V_110 ) ;
}
F_6 ( & V_118 -> V_125 ) ;
goto V_212;
}
}
if ( V_210 )
* F_159 ( V_118 ) += V_136 ;
else
F_163 ( V_118 , V_136 ) ;
F_6 ( & V_118 -> V_125 ) ;
if ( V_210 )
goto V_212;
F_43 ( V_121 ) ;
V_212:
F_164 ( & V_135 , V_209 ) ;
F_135 ( V_156 ) ;
V_83:
return V_51 ;
}
int F_165 ( struct V_118 * V_118 )
{
int V_59 , V_51 = 0 , V_209 ;
struct V_155 V_156 [ V_27 ] ;
struct V_30 * const * V_121 ;
if ( ! F_146 ( V_118 ) )
return 0 ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ )
V_156 [ V_59 ] . V_167 = V_176 ;
V_121 = F_107 ( V_118 ) ;
V_209 = F_162 ( & V_135 ) ;
F_5 ( & V_118 -> V_125 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( ! V_121 [ V_59 ] )
continue;
V_51 = F_140 ( V_121 [ V_59 ] , 1 , & V_156 [ V_59 ] ) ;
if ( V_51 ) {
for ( V_59 -- ; V_59 >= 0 ; V_59 -- ) {
if ( ! V_121 [ V_59 ] )
continue;
F_5 ( & V_121 [ V_59 ] -> V_110 ) ;
V_121 [ V_59 ] -> V_137 . V_145 -- ;
F_6 ( & V_121 [ V_59 ] -> V_110 ) ;
}
goto V_213;
}
}
V_213:
F_6 ( & V_118 -> V_125 ) ;
if ( V_51 == 0 )
F_43 ( V_121 ) ;
F_164 ( & V_135 , V_209 ) ;
F_135 ( V_156 ) ;
return V_51 ;
}
int F_166 ( struct V_118 * V_118 , T_2 V_136 )
{
struct V_30 * * V_121 ;
int V_59 , V_209 ;
if ( ! F_146 ( V_118 ) ) {
F_5 ( & V_118 -> V_125 ) ;
* F_159 ( V_118 ) -= V_136 ;
F_163 ( V_118 , V_136 ) ;
F_6 ( & V_118 -> V_125 ) ;
return 0 ;
}
V_121 = F_107 ( V_118 ) ;
V_209 = F_162 ( & V_135 ) ;
F_5 ( & V_118 -> V_125 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( V_121 [ V_59 ] ) {
struct V_30 * V_30 = V_121 [ V_59 ] ;
F_5 ( & V_30 -> V_110 ) ;
if ( F_69 ( V_30 -> V_137 . V_138 < V_136 ) )
V_136 = V_30 -> V_137 . V_138 ;
V_30 -> V_137 . V_139 += V_136 ;
V_30 -> V_137 . V_138 -= V_136 ;
F_6 ( & V_30 -> V_110 ) ;
}
}
* F_159 ( V_118 ) -= V_136 ;
F_163 ( V_118 , V_136 ) ;
F_6 ( & V_118 -> V_125 ) ;
F_43 ( V_121 ) ;
F_164 ( & V_135 , V_209 ) ;
return 0 ;
}
void F_167 ( struct V_118 * V_118 , T_2 V_136 )
{
struct V_30 * * V_121 ;
int V_59 , V_209 ;
if ( ! F_146 ( V_118 ) ) {
F_5 ( & V_118 -> V_125 ) ;
* F_159 ( V_118 ) += V_136 ;
F_168 ( V_118 , V_136 ) ;
F_6 ( & V_118 -> V_125 ) ;
return;
}
V_121 = F_107 ( V_118 ) ;
V_209 = F_162 ( & V_135 ) ;
F_5 ( & V_118 -> V_125 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( V_121 [ V_59 ] ) {
struct V_30 * V_30 = V_121 [ V_59 ] ;
F_5 ( & V_30 -> V_110 ) ;
if ( F_69 ( V_30 -> V_137 . V_139 < V_136 ) )
V_136 = V_30 -> V_137 . V_139 ;
V_30 -> V_137 . V_138 += V_136 ;
V_30 -> V_137 . V_139 -= V_136 ;
F_6 ( & V_30 -> V_110 ) ;
}
}
* F_159 ( V_118 ) += V_136 ;
F_168 ( V_118 , V_136 ) ;
F_6 ( & V_118 -> V_125 ) ;
F_43 ( V_121 ) ;
F_164 ( & V_135 , V_209 ) ;
return;
}
void F_169 ( struct V_118 * V_118 , T_2 V_136 , int V_53 )
{
unsigned int V_59 ;
struct V_155 V_156 [ V_27 ] ;
struct V_30 * * V_121 ;
int V_210 = V_53 & V_211 , V_209 ;
if ( ! F_146 ( V_118 ) ) {
if ( V_210 ) {
F_5 ( & V_118 -> V_125 ) ;
* F_159 ( V_118 ) -= V_136 ;
F_6 ( & V_118 -> V_125 ) ;
} else {
F_170 ( V_118 , V_136 ) ;
}
return;
}
V_121 = F_107 ( V_118 ) ;
V_209 = F_162 ( & V_135 ) ;
F_5 ( & V_118 -> V_125 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
int V_214 ;
V_156 [ V_59 ] . V_167 = V_176 ;
if ( ! V_121 [ V_59 ] )
continue;
F_5 ( & V_121 [ V_59 ] -> V_110 ) ;
V_214 = F_145 ( V_121 [ V_59 ] , V_136 ) ;
if ( V_214 != V_176 )
F_134 ( & V_156 [ V_59 ] , V_121 [ V_59 ] , V_214 ) ;
if ( V_210 )
F_122 ( V_121 [ V_59 ] , V_136 ) ;
else
F_124 ( V_121 [ V_59 ] , V_136 ) ;
F_6 ( & V_121 [ V_59 ] -> V_110 ) ;
}
if ( V_210 )
* F_159 ( V_118 ) -= V_136 ;
else
F_168 ( V_118 , V_136 ) ;
F_6 ( & V_118 -> V_125 ) ;
if ( V_210 )
goto V_215;
F_43 ( V_121 ) ;
V_215:
F_164 ( & V_135 , V_209 ) ;
F_135 ( V_156 ) ;
}
void F_171 ( struct V_118 * V_118 )
{
unsigned int V_59 ;
struct V_155 V_156 [ V_27 ] ;
struct V_30 * const * V_121 ;
int V_209 ;
if ( ! F_146 ( V_118 ) )
return;
V_121 = F_107 ( V_118 ) ;
V_209 = F_162 ( & V_135 ) ;
F_5 ( & V_118 -> V_125 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
int V_214 ;
V_156 [ V_59 ] . V_167 = V_176 ;
if ( ! V_121 [ V_59 ] )
continue;
F_5 ( & V_121 [ V_59 ] -> V_110 ) ;
V_214 = F_144 ( V_121 [ V_59 ] , 1 ) ;
if ( V_214 != V_176 )
F_134 ( & V_156 [ V_59 ] , V_121 [ V_59 ] , V_214 ) ;
F_123 ( V_121 [ V_59 ] , 1 ) ;
F_6 ( & V_121 [ V_59 ] -> V_110 ) ;
}
F_6 ( & V_118 -> V_125 ) ;
F_43 ( V_121 ) ;
F_164 ( & V_135 , V_209 ) ;
F_135 ( V_156 ) ;
}
int F_172 ( struct V_118 * V_118 , struct V_30 * * V_216 )
{
T_2 V_217 ;
T_2 V_191 = 0 ;
T_2 V_218 = 1 ;
struct V_30 * V_219 [ V_27 ] = {} ;
int V_59 , V_51 = 0 ;
char V_220 [ V_27 ] = {} ;
struct V_155 V_221 [ V_27 ] ;
struct V_155 V_222 [ V_27 ] ;
struct V_155 V_223 [ V_27 ] ;
if ( F_109 ( V_118 ) )
return 0 ;
if ( V_118 -> V_119 -> V_49 -> V_224 ) {
V_51 = V_118 -> V_119 -> V_49 -> V_224 ( V_118 , & V_218 ) ;
if ( V_51 )
return V_51 ;
}
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
V_221 [ V_59 ] . V_167 = V_176 ;
V_222 [ V_59 ] . V_167 = V_176 ;
V_223 [ V_59 ] . V_167 = V_176 ;
}
F_5 ( & V_60 ) ;
F_5 ( & V_118 -> V_125 ) ;
if ( F_109 ( V_118 ) ) {
F_6 ( & V_118 -> V_125 ) ;
F_6 ( & V_60 ) ;
return 0 ;
}
V_217 = F_173 ( V_118 ) ;
V_191 = F_154 ( V_118 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( ! V_216 [ V_59 ] )
continue;
if ( ! F_74 ( V_118 -> V_119 , V_59 ) )
continue;
V_220 [ V_59 ] = 1 ;
V_219 [ V_59 ] = F_107 ( V_118 ) [ V_59 ] ;
V_51 = F_140 ( V_216 [ V_59 ] , V_218 ,
& V_221 [ V_59 ] ) ;
if ( V_51 )
goto V_225;
V_51 = F_143 ( V_216 [ V_59 ] , V_217 , V_191 , 0 ,
& V_221 [ V_59 ] ) ;
if ( V_51 ) {
F_5 ( & V_216 [ V_59 ] -> V_110 ) ;
F_123 ( V_216 [ V_59 ] , V_218 ) ;
F_6 ( & V_216 [ V_59 ] -> V_110 ) ;
goto V_225;
}
}
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( ! V_220 [ V_59 ] )
continue;
if ( V_219 [ V_59 ] ) {
int V_214 ;
F_5 ( & V_219 [ V_59 ] -> V_110 ) ;
V_214 = F_144 ( V_219 [ V_59 ] , V_218 ) ;
if ( V_214 != V_176 )
F_134 ( & V_222 [ V_59 ] ,
V_219 [ V_59 ] , V_214 ) ;
V_214 = F_145 ( V_219 [ V_59 ] ,
V_217 + V_191 ) ;
if ( V_214 != V_176 )
F_134 ( & V_223 [ V_59 ] ,
V_219 [ V_59 ] , V_214 ) ;
F_123 ( V_219 [ V_59 ] , V_218 ) ;
F_124 ( V_219 [ V_59 ] , V_217 ) ;
F_122 ( V_219 [ V_59 ] ,
V_191 ) ;
F_6 ( & V_219 [ V_59 ] -> V_110 ) ;
}
F_107 ( V_118 ) [ V_59 ] = V_216 [ V_59 ] ;
}
F_6 ( & V_118 -> V_125 ) ;
F_6 ( & V_60 ) ;
F_43 ( V_219 ) ;
F_43 ( V_216 ) ;
F_135 ( V_221 ) ;
F_135 ( V_222 ) ;
F_135 ( V_223 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ )
if ( V_220 [ V_59 ] )
V_216 [ V_59 ] = V_219 [ V_59 ] ;
return 0 ;
V_225:
for ( V_59 -- ; V_59 >= 0 ; V_59 -- ) {
if ( ! V_220 [ V_59 ] )
continue;
F_5 ( & V_216 [ V_59 ] -> V_110 ) ;
F_123 ( V_216 [ V_59 ] , V_218 ) ;
F_124 ( V_216 [ V_59 ] , V_217 ) ;
F_122 ( V_216 [ V_59 ] , V_191 ) ;
F_6 ( & V_216 [ V_59 ] -> V_110 ) ;
}
F_6 ( & V_118 -> V_125 ) ;
F_6 ( & V_60 ) ;
F_135 ( V_221 ) ;
return V_51 ;
}
int F_174 ( struct V_118 * V_118 , struct V_226 * V_226 )
{
struct V_30 * V_216 [ V_27 ] = {} ;
struct V_30 * V_30 ;
struct V_1 * V_2 = V_118 -> V_119 ;
int V_51 ;
if ( ! F_146 ( V_118 ) )
return 0 ;
if ( V_226 -> V_227 & V_228 && ! F_127 ( V_226 -> V_229 , V_118 -> V_203 ) ) {
V_30 = F_102 ( V_2 , F_149 ( V_226 -> V_229 ) ) ;
if ( F_152 ( V_30 ) ) {
if ( F_153 ( V_30 ) != - V_114 ) {
V_51 = F_153 ( V_30 ) ;
goto V_206;
}
V_30 = NULL ;
}
V_216 [ V_159 ] = V_30 ;
}
if ( V_226 -> V_227 & V_230 && ! F_175 ( V_226 -> V_231 , V_118 -> V_204 ) ) {
V_30 = F_102 ( V_2 , F_150 ( V_226 -> V_231 ) ) ;
if ( F_152 ( V_30 ) ) {
if ( F_153 ( V_30 ) != - V_114 ) {
V_51 = F_153 ( V_30 ) ;
goto V_206;
}
V_30 = NULL ;
}
V_216 [ V_161 ] = V_30 ;
}
V_51 = F_172 ( V_118 , V_216 ) ;
V_206:
F_44 ( V_216 ) ;
return V_51 ;
}
int F_176 ( struct V_1 * V_2 , int type )
{
struct V_64 * V_65 = F_40 ( V_2 ) ;
return V_65 -> V_67 [ type ] -> F_55 ( V_2 , type ) ;
}
int F_177 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_64 * V_65 = F_40 ( V_2 ) ;
if ( ! F_74 ( V_2 , V_23 -> type ) )
return - V_114 ;
if ( ! V_65 -> V_67 [ V_23 -> type ] -> V_232 )
return - V_233 ;
return V_65 -> V_67 [ V_23 -> type ] -> V_232 ( V_2 , V_23 ) ;
}
int F_178 ( struct V_118 * V_118 , struct V_234 * V_234 )
{
int error ;
error = F_179 ( V_118 , V_234 ) ;
if ( ! error && ( V_234 -> V_235 & V_236 ) )
F_155 ( V_118 ) ;
return error ;
}
int F_180 ( struct V_1 * V_2 , int type , unsigned int V_53 )
{
int V_59 , V_51 = 0 ;
struct V_64 * V_65 = F_40 ( V_2 ) ;
struct V_118 * V_237 [ V_27 ] ;
if ( F_69 ( F_181 ( & V_2 -> V_81 ) ) )
F_182 ( & V_2 -> V_81 ) ;
if ( ( V_53 & V_238 && ! ( V_53 & V_239 ) )
|| ( V_53 & V_240 && V_53 & ( V_239 |
V_238 ) ) )
return - V_113 ;
if ( ! F_147 ( V_2 ) )
return 0 ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
V_237 [ V_59 ] = NULL ;
if ( type != - 1 && V_59 != type )
continue;
if ( ! F_183 ( V_2 , V_59 ) )
continue;
if ( V_53 & V_240 ) {
F_5 ( & V_115 ) ;
V_65 -> V_53 |=
F_184 ( V_240 , V_59 ) ;
F_6 ( & V_115 ) ;
} else {
F_5 ( & V_115 ) ;
V_65 -> V_53 &= ~ F_184 ( V_53 , V_59 ) ;
if ( ! F_183 ( V_2 , V_59 ) &&
F_185 ( V_2 , V_59 ) ) {
V_65 -> V_53 &= ~ F_184 (
V_240 , V_59 ) ;
F_6 ( & V_115 ) ;
F_114 ( V_65 -> V_93 [ V_59 ] ) ;
V_65 -> V_93 [ V_59 ] = NULL ;
continue;
}
F_6 ( & V_115 ) ;
}
if ( F_183 ( V_2 , V_59 ) && ! ( V_53 & V_240 ) )
continue;
F_119 ( V_2 , V_59 ) ;
F_63 ( V_2 , V_59 ) ;
if ( F_54 ( & V_65 -> V_56 [ V_59 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_59 ) ;
if ( V_65 -> V_67 [ V_59 ] -> V_241 )
V_65 -> V_67 [ V_59 ] -> V_241 ( V_2 , V_59 ) ;
F_11 ( V_65 -> V_56 [ V_59 ] . V_180 ) ;
V_237 [ V_59 ] = V_65 -> V_93 [ V_59 ] ;
if ( ! F_183 ( V_2 , V_59 ) )
V_65 -> V_93 [ V_59 ] = NULL ;
V_65 -> V_56 [ V_59 ] . V_61 = 0 ;
V_65 -> V_56 [ V_59 ] . V_189 = 0 ;
V_65 -> V_56 [ V_59 ] . V_196 = 0 ;
V_65 -> V_67 [ V_59 ] = NULL ;
}
if ( V_65 -> V_53 & V_89 )
goto V_242;
if ( V_2 -> V_90 -> V_91 )
V_2 -> V_90 -> V_91 ( V_2 , 1 ) ;
F_78 ( V_2 -> V_92 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ )
if ( V_237 [ V_59 ] && ! F_183 ( V_2 , V_59 ) ) {
F_79 ( V_237 [ V_59 ] ) ;
V_237 [ V_59 ] -> V_243 &= ~ V_244 ;
F_80 ( & V_237 [ V_59 ] -> V_94 , 0 ) ;
F_81 ( V_237 [ V_59 ] ) ;
F_186 ( V_237 [ V_59 ] ) ;
}
if ( V_2 -> V_92 )
F_187 ( V_2 -> V_92 ) ;
V_242:
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ )
if ( V_237 [ V_59 ] ) {
if ( ! ( V_53 & V_240 ) )
F_114 ( V_237 [ V_59 ] ) ;
else if ( ! V_237 [ V_59 ] -> V_245 )
V_51 = - V_246 ;
}
return V_51 ;
}
int F_188 ( struct V_1 * V_2 , int type )
{
return F_180 ( V_2 , type ,
V_238 | V_239 ) ;
}
static int F_189 ( struct V_118 * V_118 , int type , int V_247 ,
unsigned int V_53 )
{
struct V_10 * V_4 = F_8 ( V_247 ) ;
struct V_1 * V_2 = V_118 -> V_119 ;
struct V_64 * V_65 = F_40 ( V_2 ) ;
int error ;
if ( ! V_4 )
return - V_114 ;
if ( ! F_190 ( V_118 -> V_248 ) ) {
error = - V_249 ;
goto V_250;
}
if ( F_191 ( V_118 ) ) {
error = - V_251 ;
goto V_250;
}
if ( ! V_2 -> V_90 -> V_252 || ! V_2 -> V_90 -> V_253 ||
( type == V_163 && V_2 -> V_49 -> V_205 == NULL ) ) {
error = - V_113 ;
goto V_250;
}
if ( V_2 -> V_112 != & V_24 ) {
error = - V_113 ;
goto V_250;
}
if ( ! ( V_53 & V_238 ) ) {
error = - V_113 ;
goto V_250;
}
if ( F_183 ( V_2 , type ) ) {
error = - V_246 ;
goto V_250;
}
if ( ! ( V_65 -> V_53 & V_89 ) ) {
F_192 ( V_2 ) ;
F_187 ( V_2 -> V_92 ) ;
}
if ( ! ( V_65 -> V_53 & V_89 ) ) {
F_79 ( V_118 ) ;
V_118 -> V_243 |= V_244 ;
F_81 ( V_118 ) ;
F_157 ( V_118 ) ;
}
error = - V_71 ;
V_65 -> V_93 [ type ] = F_193 ( V_118 ) ;
if ( ! V_65 -> V_93 [ type ] )
goto V_254;
error = - V_113 ;
if ( ! V_4 -> V_255 -> V_256 ( V_2 , type ) )
goto V_257;
V_65 -> V_67 [ type ] = V_4 -> V_255 ;
V_65 -> V_56 [ type ] . V_180 = V_4 ;
V_65 -> V_56 [ type ] . V_258 = V_247 ;
F_97 ( & V_65 -> V_56 [ type ] . V_57 ) ;
error = V_65 -> V_67 [ type ] -> F_194 ( V_2 , type ) ;
if ( error < 0 )
goto V_257;
if ( V_65 -> V_53 & V_89 ) {
F_5 ( & V_60 ) ;
V_65 -> V_56 [ type ] . V_61 |= V_259 ;
F_6 ( & V_60 ) ;
}
F_5 ( & V_115 ) ;
V_65 -> V_53 |= F_184 ( V_53 , type ) ;
F_6 ( & V_115 ) ;
F_110 ( V_2 , type ) ;
return 0 ;
V_257:
V_65 -> V_93 [ type ] = NULL ;
F_114 ( V_118 ) ;
V_254:
F_79 ( V_118 ) ;
V_118 -> V_243 &= ~ V_244 ;
F_81 ( V_118 ) ;
V_250:
F_11 ( V_4 ) ;
return error ;
}
int F_195 ( struct V_1 * V_2 , int type )
{
struct V_64 * V_65 = F_40 ( V_2 ) ;
struct V_118 * V_118 ;
int V_51 = 0 , V_59 ;
unsigned int V_53 ;
if ( F_69 ( F_181 ( & V_2 -> V_81 ) ) )
F_182 ( & V_2 -> V_81 ) ;
for ( V_59 = 0 ; V_59 < V_27 ; V_59 ++ ) {
if ( type != - 1 && V_59 != type )
continue;
if ( ! F_185 ( V_2 , V_59 ) )
continue;
V_118 = V_65 -> V_93 [ V_59 ] ;
V_65 -> V_93 [ V_59 ] = NULL ;
F_5 ( & V_115 ) ;
V_53 = V_65 -> V_53 & F_184 ( V_238 |
V_239 ,
V_59 ) ;
V_65 -> V_53 &= ~ F_184 ( V_260 , V_59 ) ;
F_6 ( & V_115 ) ;
V_53 = F_196 ( V_53 , V_59 ) ;
V_51 = F_189 ( V_118 , V_59 ,
V_65 -> V_56 [ V_59 ] . V_258 , V_53 ) ;
F_114 ( V_118 ) ;
}
return V_51 ;
}
int F_197 ( struct V_1 * V_2 , int type , int V_247 ,
const struct V_261 * V_261 )
{
int error = F_198 ( V_261 -> V_262 ) ;
if ( error )
return error ;
if ( V_261 -> V_262 -> V_263 != V_2 )
error = - V_264 ;
else
error = F_189 ( F_199 ( V_261 -> V_262 ) , type ,
V_247 , V_238 |
V_239 ) ;
return error ;
}
int F_200 ( struct V_118 * V_118 , int type , int V_247 ,
unsigned int V_53 )
{
struct V_1 * V_2 = V_118 -> V_119 ;
F_92 ( V_53 & V_240 ) ;
if ( F_69 ( F_181 ( & V_2 -> V_81 ) ) )
F_182 ( & V_2 -> V_81 ) ;
if ( ! V_53 )
return 0 ;
if ( F_183 ( V_2 , type ) ) {
if ( V_53 & V_238 &&
F_201 ( V_2 , type ) )
return - V_246 ;
if ( V_53 & V_239 &&
F_141 ( V_2 , type ) )
return - V_246 ;
F_5 ( & V_115 ) ;
F_40 ( V_2 ) -> V_53 |= F_184 ( V_53 , type ) ;
F_6 ( & V_115 ) ;
return 0 ;
}
return F_189 ( V_118 , type , V_247 , V_53 ) ;
}
int F_202 ( struct V_1 * V_2 , char * V_265 ,
int V_247 , int type )
{
struct V_262 * V_262 ;
int error ;
V_262 = F_203 ( V_265 , V_2 -> V_266 , strlen ( V_265 ) ) ;
if ( F_152 ( V_262 ) )
return F_153 ( V_262 ) ;
if ( F_204 ( V_262 ) ) {
error = - V_267 ;
goto V_83;
}
error = F_198 ( V_262 ) ;
if ( ! error )
error = F_189 ( F_199 ( V_262 ) , type , V_247 ,
V_238 | V_239 ) ;
V_83:
F_205 ( V_262 ) ;
return error ;
}
static int F_206 ( struct V_1 * V_2 , unsigned int V_53 )
{
int V_51 ;
int type ;
struct V_64 * V_65 = F_40 ( V_2 ) ;
if ( ! ( V_65 -> V_53 & V_89 ) )
return - V_233 ;
V_53 &= ~ ( V_268 | V_269 | V_270 ) ;
if ( ! V_53 )
return - V_113 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! ( V_53 & F_207 ( type ) ) )
continue;
if ( ! F_201 ( V_2 , type ) )
return - V_113 ;
V_51 = F_200 ( V_65 -> V_93 [ type ] , type ,
V_65 -> V_56 [ type ] . V_258 ,
V_239 ) ;
if ( V_51 < 0 )
goto V_271;
}
return 0 ;
V_271:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_53 & F_207 ( type ) )
F_180 ( V_2 , type , V_239 ) ;
}
if ( V_51 == - V_246 )
V_51 = - V_272 ;
return V_51 ;
}
static int F_208 ( struct V_1 * V_2 , unsigned int V_53 )
{
int V_51 ;
int type ;
struct V_64 * V_65 = F_40 ( V_2 ) ;
if ( ! ( V_65 -> V_53 & V_89 ) )
return - V_233 ;
if ( V_53 &
( V_268 | V_269 | V_270 ) )
return - V_273 ;
for ( type = 0 ; type < V_27 ; type ++ )
if ( ! F_141 ( V_2 , type ) )
V_53 &= ~ F_207 ( type ) ;
if ( ! V_53 )
return - V_272 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( V_53 & F_207 ( type ) ) {
V_51 = F_180 ( V_2 , type , V_239 ) ;
if ( V_51 < 0 )
goto V_271;
}
}
return 0 ;
V_271:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_53 & F_207 ( type ) )
F_200 ( V_65 -> V_93 [ type ] , type ,
V_65 -> V_56 [ type ] . V_258 ,
V_239 ) ;
}
return V_51 ;
}
static void F_209 ( struct V_30 * V_30 , struct V_274 * V_275 )
{
struct V_276 * V_277 = & V_30 -> V_137 ;
memset ( V_275 , 0 , sizeof( * V_275 ) ) ;
F_5 ( & V_30 -> V_110 ) ;
V_275 -> V_278 = V_277 -> V_194 ;
V_275 -> V_279 = V_277 -> V_140 ;
V_275 -> V_280 = V_277 -> V_187 ;
V_275 -> V_281 = V_277 -> V_146 ;
V_275 -> V_282 = V_277 -> V_139 + V_277 -> V_138 ;
V_275 -> V_283 = V_277 -> V_145 ;
V_275 -> V_284 = V_277 -> V_141 ;
V_275 -> V_285 = V_277 -> V_147 ;
F_6 ( & V_30 -> V_110 ) ;
}
int F_210 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_274 * V_275 )
{
struct V_30 * V_30 ;
V_30 = F_102 ( V_2 , V_23 ) ;
if ( F_152 ( V_30 ) )
return F_153 ( V_30 ) ;
F_209 ( V_30 , V_275 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
int F_211 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_274 * V_275 )
{
struct V_30 * V_30 ;
int V_58 ;
if ( ! V_2 -> V_49 -> V_232 )
return - V_233 ;
V_58 = V_2 -> V_49 -> V_232 ( V_2 , V_23 ) ;
if ( V_58 < 0 )
return V_58 ;
V_30 = F_102 ( V_2 , * V_23 ) ;
if ( F_152 ( V_30 ) )
return F_153 ( V_30 ) ;
F_209 ( V_30 , V_275 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_212 ( struct V_30 * V_30 , struct V_274 * V_275 )
{
struct V_276 * V_277 = & V_30 -> V_137 ;
int V_286 = 0 , V_287 = 0 ;
struct V_178 * V_288 = & F_40 ( V_30 -> V_34 ) -> V_56 [ V_30 -> V_35 . type ] ;
if ( V_275 -> V_289 & ~ V_290 )
return - V_113 ;
if ( ( ( V_275 -> V_289 & V_291 ) &&
V_275 -> V_279 > V_288 -> V_292 ) ||
( ( V_275 -> V_289 & V_293 ) &&
V_275 -> V_278 > V_288 -> V_292 ) ||
( ( V_275 -> V_289 & V_294 ) &&
( V_275 -> V_281 > V_288 -> V_295 ) ) ||
( ( V_275 -> V_289 & V_296 ) &&
( V_275 -> V_280 > V_288 -> V_295 ) ) )
return - V_297 ;
F_5 ( & V_30 -> V_110 ) ;
if ( V_275 -> V_289 & V_298 ) {
V_277 -> V_139 = V_275 -> V_282 - V_277 -> V_138 ;
V_286 = 1 ;
F_52 ( V_299 + V_300 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_291 )
V_277 -> V_140 = V_275 -> V_279 ;
if ( V_275 -> V_289 & V_293 )
V_277 -> V_194 = V_275 -> V_278 ;
if ( V_275 -> V_289 & ( V_291 | V_293 ) ) {
V_286 = 1 ;
F_52 ( V_299 + V_301 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_302 ) {
V_277 -> V_145 = V_275 -> V_283 ;
V_287 = 1 ;
F_52 ( V_299 + V_303 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_294 )
V_277 -> V_146 = V_275 -> V_281 ;
if ( V_275 -> V_289 & V_296 )
V_277 -> V_187 = V_275 -> V_280 ;
if ( V_275 -> V_289 & ( V_294 | V_296 ) ) {
V_287 = 1 ;
F_52 ( V_299 + V_304 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_305 ) {
V_277 -> V_141 = V_275 -> V_284 ;
V_286 = 1 ;
F_52 ( V_299 + V_306 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_307 ) {
V_277 -> V_147 = V_275 -> V_285 ;
V_287 = 1 ;
F_52 ( V_299 + V_308 , & V_30 -> V_48 ) ;
}
if ( V_286 ) {
if ( ! V_277 -> V_140 ||
V_277 -> V_139 + V_277 -> V_138 < V_277 -> V_140 ) {
V_277 -> V_141 = 0 ;
F_59 ( V_143 , & V_30 -> V_48 ) ;
} else if ( ! ( V_275 -> V_289 & V_305 ) )
V_277 -> V_141 = F_142 () + V_288 -> V_196 ;
}
if ( V_287 ) {
if ( ! V_277 -> V_146 ||
V_277 -> V_145 < V_277 -> V_146 ) {
V_277 -> V_147 = 0 ;
F_59 ( V_148 , & V_30 -> V_48 ) ;
} else if ( ! ( V_275 -> V_289 & V_307 ) )
V_277 -> V_147 = F_142 () + V_288 -> V_189 ;
}
if ( V_277 -> V_194 || V_277 -> V_140 || V_277 -> V_187 ||
V_277 -> V_146 )
F_59 ( V_185 , & V_30 -> V_48 ) ;
else
F_52 ( V_185 , & V_30 -> V_48 ) ;
F_6 ( & V_30 -> V_110 ) ;
F_38 ( V_30 ) ;
return 0 ;
}
int F_213 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_274 * V_275 )
{
struct V_30 * V_30 ;
int V_202 ;
V_30 = F_102 ( V_2 , V_23 ) ;
if ( F_152 ( V_30 ) ) {
V_202 = F_153 ( V_30 ) ;
goto V_83;
}
V_202 = F_212 ( V_30 , V_275 ) ;
F_45 ( V_30 ) ;
V_83:
return V_202 ;
}
int F_214 ( struct V_1 * V_2 , struct V_309 * V_310 )
{
struct V_178 * V_311 ;
struct V_312 * V_313 ;
struct V_64 * V_65 = F_40 ( V_2 ) ;
int type ;
memset ( V_310 , 0 , sizeof( * V_310 ) ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! F_74 ( V_2 , type ) )
continue;
V_313 = V_310 -> V_314 + type ;
V_311 = F_40 ( V_2 ) -> V_56 + type ;
V_313 -> V_53 = V_315 ;
F_5 ( & V_60 ) ;
if ( V_311 -> V_61 & V_259 )
V_313 -> V_53 |= V_316 ;
if ( V_311 -> V_61 & V_182 )
V_313 -> V_53 |= V_317 ;
if ( F_141 ( V_2 , type ) )
V_313 -> V_53 |= V_318 ;
V_313 -> V_319 = V_311 -> V_196 ;
V_313 -> V_320 = V_311 -> V_189 ;
V_313 -> V_321 = V_65 -> V_93 [ type ] -> V_322 ;
V_313 -> V_323 = V_65 -> V_93 [ type ] -> V_324 ;
V_313 -> V_325 = 1 ;
F_6 ( & V_60 ) ;
}
return 0 ;
}
int F_215 ( struct V_1 * V_2 , int type , struct V_326 * V_327 )
{
struct V_178 * V_311 ;
int V_58 = 0 ;
if ( ( V_327 -> V_328 & V_329 ) ||
( V_327 -> V_328 & V_330 ) )
return - V_113 ;
if ( ! F_74 ( V_2 , type ) )
return - V_114 ;
V_311 = F_40 ( V_2 ) -> V_56 + type ;
if ( V_327 -> V_328 & V_331 ) {
if ( ( V_327 -> V_243 & V_317 &&
V_311 -> V_180 -> V_16 != V_181 ) )
return - V_113 ;
}
F_5 ( & V_60 ) ;
if ( V_327 -> V_328 & V_305 )
V_311 -> V_196 = V_327 -> V_332 ;
if ( V_327 -> V_328 & V_307 )
V_311 -> V_189 = V_327 -> V_333 ;
if ( V_327 -> V_328 & V_331 ) {
if ( V_327 -> V_243 & V_317 )
V_311 -> V_61 |= V_182 ;
else
V_311 -> V_61 &= ~ V_182 ;
}
F_6 ( & V_60 ) ;
F_48 ( V_2 , type ) ;
V_2 -> V_49 -> V_87 ( V_2 , type ) ;
return V_58 ;
}
static int F_216 ( struct V_334 * V_335 , int V_336 ,
void T_4 * V_337 , T_5 * V_338 , T_6 * V_339 )
{
unsigned int type = ( int * ) V_335 -> V_340 - V_102 . V_341 ;
V_102 . V_341 [ type ] =
F_217 ( & V_102 . V_103 [ type ] ) ;
return F_218 ( V_335 , V_336 , V_337 , V_338 , V_339 ) ;
}
static int T_7 F_219 ( void )
{
int V_175 , V_51 ;
unsigned long V_342 , V_343 ;
F_3 ( V_344 L_19 , V_345 ) ;
F_220 ( V_346 ) ;
V_75 = F_221 ( L_20 ,
sizeof( struct V_30 ) , sizeof( unsigned long ) * 4 ,
( V_347 | V_348 |
V_349 | V_350 ) ,
NULL ) ;
V_343 = 0 ;
V_33 = (struct V_31 * ) F_222 ( V_351 , V_343 ) ;
if ( ! V_33 )
F_223 ( L_21 ) ;
for ( V_175 = 0 ; V_175 < V_352 ; V_175 ++ ) {
V_51 = F_224 ( & V_102 . V_103 [ V_175 ] , 0 , V_353 ) ;
if ( V_51 )
F_223 ( L_22 ) ;
}
V_342 = ( 1UL << V_343 ) * V_354 / sizeof( struct V_31 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( V_342 >> V_28 );
V_28 -- ;
V_342 = 1UL << V_28 ;
V_29 = V_342 - 1 ;
for ( V_175 = 0 ; V_175 < V_342 ; V_175 ++ )
F_225 ( V_33 + V_175 ) ;
F_226 ( L_23
L_24 , V_342 , V_343 , ( V_354 << V_343 ) ) ;
F_227 ( & V_355 ) ;
return 0 ;
}

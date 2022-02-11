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
if ( F_37 ( V_47 , & V_30 -> V_48 ) )
return 1 ;
F_5 ( & V_11 ) ;
if ( ! F_40 ( V_47 , & V_30 -> V_48 ) ) {
F_41 ( & V_30 -> V_52 , & F_42 ( V_30 -> V_34 ) ->
V_53 [ V_30 -> V_35 . type ] . V_54 ) ;
V_51 = 0 ;
}
F_6 ( & V_11 ) ;
return V_51 ;
}
static inline int F_43 ( struct V_30 * const * V_30 )
{
int V_51 , V_55 , V_56 ;
V_51 = V_55 = 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_30 [ V_56 ] )
V_51 = F_38 ( V_30 [ V_56 ] ) ;
if ( ! V_55 )
V_55 = V_51 ;
}
return V_55 ;
}
static inline void F_44 ( struct V_30 * * V_30 )
{
unsigned int V_56 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
F_45 ( V_30 [ V_56 ] ) ;
}
static inline int F_46 ( struct V_30 * V_30 )
{
if ( ! F_47 ( V_47 , & V_30 -> V_48 ) )
return 0 ;
F_28 ( & V_30 -> V_52 ) ;
return 1 ;
}
void F_48 ( struct V_1 * V_2 , int type )
{
F_49 ( V_57 , & F_42 ( V_2 ) -> V_53 [ type ] . V_58 ) ;
}
int F_50 ( struct V_30 * V_30 )
{
int V_51 = 0 , V_59 = 0 ;
struct V_60 * V_61 = F_42 ( V_30 -> V_34 ) ;
F_34 ( & V_30 -> V_46 ) ;
F_34 ( & V_61 -> V_62 ) ;
if ( ! F_37 ( V_63 , & V_30 -> V_48 ) )
V_51 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_51 ( V_30 ) ;
if ( V_51 < 0 )
goto V_65;
F_49 ( V_63 , & V_30 -> V_48 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) && ! V_30 -> V_67 ) {
V_51 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_52 ( V_30 ) ;
if ( F_53 ( & V_61 -> V_53 [ V_30 -> V_35 . type ] ) ) {
V_59 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_54 (
V_30 -> V_34 , V_30 -> V_35 . type ) ;
}
if ( V_51 < 0 )
goto V_65;
if ( V_59 < 0 ) {
V_51 = V_59 ;
goto V_65;
}
}
F_49 ( V_66 , & V_30 -> V_48 ) ;
V_65:
F_35 ( & V_61 -> V_62 ) ;
F_35 ( & V_30 -> V_46 ) ;
return V_51 ;
}
int F_55 ( struct V_30 * V_30 )
{
int V_51 = 0 ;
struct V_60 * V_61 = F_42 ( V_30 -> V_34 ) ;
F_34 ( & V_61 -> V_62 ) ;
F_5 ( & V_11 ) ;
if ( ! F_46 ( V_30 ) ) {
F_6 ( & V_11 ) ;
goto V_68;
}
F_6 ( & V_11 ) ;
if ( F_37 ( V_66 , & V_30 -> V_48 ) )
V_51 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_52 ( V_30 ) ;
else
V_51 = - V_69 ;
V_68:
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_56 ( struct V_30 * V_30 )
{
int V_51 = 0 , V_59 = 0 ;
struct V_60 * V_61 = F_42 ( V_30 -> V_34 ) ;
F_34 ( & V_30 -> V_46 ) ;
if ( F_57 ( & V_30 -> V_70 ) > 1 )
goto V_71;
F_34 ( & V_61 -> V_62 ) ;
if ( V_61 -> V_64 [ V_30 -> V_35 . type ] -> V_72 ) {
V_51 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> V_72 ( V_30 ) ;
if ( F_53 ( & V_61 -> V_53 [ V_30 -> V_35 . type ] ) ) {
V_59 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_54 (
V_30 -> V_34 , V_30 -> V_35 . type ) ;
}
if ( V_51 >= 0 )
V_51 = V_59 ;
}
F_58 ( V_66 , & V_30 -> V_48 ) ;
F_35 ( & V_61 -> V_62 ) ;
V_71:
F_35 ( & V_30 -> V_46 ) ;
return V_51 ;
}
void F_59 ( struct V_30 * V_30 )
{
F_60 ( V_73 , V_30 ) ;
}
static inline void F_61 ( struct V_30 * V_30 )
{
V_30 -> V_34 -> V_49 -> V_74 ( V_30 ) ;
}
static void F_62 ( struct V_1 * V_2 , int type )
{
struct V_30 * V_30 , * V_25 ;
V_75:
F_5 ( & V_11 ) ;
F_63 (dquot, tmp, &inuse_list, dq_inuse) {
if ( V_30 -> V_34 != V_2 )
continue;
if ( V_30 -> V_35 . type != type )
continue;
if ( F_57 ( & V_30 -> V_70 ) ) {
F_64 ( V_76 ) ;
F_65 ( V_30 ) ;
F_66 ( & V_30 -> V_77 , & V_76 ,
V_78 ) ;
F_6 ( & V_11 ) ;
if ( F_57 ( & V_30 -> V_70 ) > 1 )
F_67 () ;
F_68 ( & V_30 -> V_77 , & V_76 ) ;
F_45 ( V_30 ) ;
goto V_75;
}
F_17 ( V_30 ) ;
F_26 ( V_30 ) ;
F_31 ( V_30 ) ;
F_61 ( V_30 ) ;
}
F_6 ( & V_11 ) ;
}
int F_69 ( struct V_1 * V_2 ,
int (* F_70)( struct V_30 * V_30 , unsigned long V_79 ) ,
unsigned long V_79 )
{
struct V_30 * V_30 , * V_80 = NULL ;
int V_51 = 0 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
F_5 ( & V_11 ) ;
F_71 (dquot, &inuse_list, dq_inuse) {
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) )
continue;
if ( V_30 -> V_34 != V_2 )
continue;
F_72 ( & V_30 -> V_70 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
F_45 ( V_80 ) ;
V_80 = V_30 ;
F_33 ( V_30 ) ;
if ( F_37 ( V_66 , & V_30 -> V_48 ) ) {
V_51 = F_70 ( V_30 , V_79 ) ;
if ( V_51 < 0 )
goto V_83;
}
F_5 ( & V_11 ) ;
}
F_6 ( & V_11 ) ;
V_83:
F_45 ( V_80 ) ;
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_51 ;
}
int F_73 ( struct V_1 * V_2 , int type )
{
struct V_84 * V_85 ;
struct V_30 * V_30 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int V_56 ;
int V_55 , V_51 = 0 ;
F_34 ( & V_61 -> V_81 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_74 ( V_2 , V_56 ) )
continue;
F_5 ( & V_11 ) ;
V_85 = & V_61 -> V_53 [ V_56 ] . V_54 ;
while ( ! F_27 ( V_85 ) ) {
V_30 = F_75 ( V_85 , struct V_30 ,
V_52 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) ) {
F_46 ( V_30 ) ;
continue;
}
F_65 ( V_30 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
V_55 = V_2 -> V_49 -> V_86 ( V_30 ) ;
if ( ! V_51 && V_55 )
V_51 = V_55 ;
F_45 ( V_30 ) ;
F_5 ( & V_11 ) ;
}
F_6 ( & V_11 ) ;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ( V_56 == type || type == - 1 ) && F_74 ( V_2 , V_56 )
&& F_53 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
F_25 ( V_88 ) ;
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
int F_76 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
int V_56 ;
int V_51 ;
V_51 = F_73 ( V_2 , type ) ;
if ( V_51 )
return V_51 ;
if ( V_61 -> V_89 & V_90 )
return 0 ;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_77 ( V_2 -> V_93 ) ;
F_34 ( & V_61 -> V_81 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_74 ( V_2 , V_56 ) )
continue;
F_34 ( & V_61 -> V_94 [ V_56 ] -> V_95 ) ;
F_78 ( & V_61 -> V_94 [ V_56 ] -> V_96 , 0 ) ;
F_35 ( & V_61 -> V_94 [ V_56 ] -> V_95 ) ;
}
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
static unsigned long
F_79 ( struct V_97 * V_98 , struct V_99 * V_100 )
{
struct V_84 * V_32 ;
struct V_30 * V_30 ;
unsigned long V_101 = 0 ;
F_5 ( & V_11 ) ;
V_32 = V_41 . V_102 ;
while ( V_32 != & V_41 && V_100 -> V_103 ) {
V_30 = F_80 ( V_32 , struct V_30 , V_40 ) ;
F_17 ( V_30 ) ;
F_26 ( V_30 ) ;
F_31 ( V_30 ) ;
F_61 ( V_30 ) ;
V_100 -> V_103 -- ;
V_101 ++ ;
V_32 = V_41 . V_102 ;
}
F_6 ( & V_11 ) ;
return V_101 ;
}
static unsigned long
F_81 ( struct V_97 * V_98 , struct V_99 * V_100 )
{
return F_82 (
F_83 ( & V_104 . V_105 [ V_42 ] ) ) ;
}
void F_45 ( struct V_30 * V_30 )
{
int V_51 ;
if ( ! V_30 )
return;
#ifdef F_84
if ( ! F_57 ( & V_30 -> V_70 ) ) {
F_85 ( V_30 -> V_34 , L_2 ,
V_106 [ V_30 -> V_35 . type ] ,
F_14 ( & V_24 , V_30 -> V_35 ) ) ;
F_86 () ;
}
#endif
F_25 ( V_107 ) ;
V_108:
F_5 ( & V_11 ) ;
if ( F_57 ( & V_30 -> V_70 ) > 1 ) {
F_87 ( & V_30 -> V_70 ) ;
if ( ! F_74 ( V_30 -> V_34 , V_30 -> V_35 . type ) &&
F_57 ( & V_30 -> V_70 ) == 1 )
F_88 ( & V_30 -> V_77 ) ;
F_6 ( & V_11 ) ;
return;
}
if ( F_37 ( V_66 , & V_30 -> V_48 ) && F_36 ( V_30 ) ) {
F_6 ( & V_11 ) ;
V_51 = V_30 -> V_34 -> V_49 -> V_86 ( V_30 ) ;
if ( V_51 < 0 ) {
F_85 ( V_30 -> V_34 , L_3
L_4 ,
V_51 ) ;
F_5 ( & V_11 ) ;
F_46 ( V_30 ) ;
F_6 ( & V_11 ) ;
}
goto V_108;
}
F_46 ( V_30 ) ;
if ( F_37 ( V_66 , & V_30 -> V_48 ) ) {
F_6 ( & V_11 ) ;
V_30 -> V_34 -> V_49 -> V_109 ( V_30 ) ;
goto V_108;
}
F_87 ( & V_30 -> V_70 ) ;
#ifdef F_84
F_89 ( ! F_27 ( & V_30 -> V_40 ) ) ;
#endif
F_23 ( V_30 ) ;
F_6 ( & V_11 ) ;
}
struct V_30 * F_90 ( struct V_1 * V_2 , int type )
{
return F_91 ( V_73 , V_110 ) ;
}
static struct V_30 * F_92 ( struct V_1 * V_2 , int type )
{
struct V_30 * V_30 ;
V_30 = V_2 -> V_49 -> V_111 ( V_2 , type ) ;
if( ! V_30 )
return NULL ;
F_93 ( & V_30 -> V_46 ) ;
F_94 ( & V_30 -> V_40 ) ;
F_94 ( & V_30 -> V_43 ) ;
F_95 ( & V_30 -> V_36 ) ;
F_94 ( & V_30 -> V_52 ) ;
F_96 ( & V_30 -> V_77 ) ;
V_30 -> V_34 = V_2 ;
V_30 -> V_35 = F_97 ( type ) ;
F_98 ( & V_30 -> V_70 , 1 ) ;
return V_30 ;
}
struct V_30 * F_99 ( struct V_1 * V_2 , struct V_22 V_23 )
{
unsigned int V_37 = F_13 ( V_2 , V_23 ) ;
struct V_30 * V_30 , * V_112 = NULL ;
if ( ! F_74 ( V_2 , V_23 . type ) )
return F_100 ( - V_113 ) ;
V_108:
F_5 ( & V_11 ) ;
F_5 ( & V_114 ) ;
if ( ! F_74 ( V_2 , V_23 . type ) ) {
F_6 ( & V_114 ) ;
F_6 ( & V_11 ) ;
V_30 = F_100 ( - V_113 ) ;
goto V_83;
}
F_6 ( & V_114 ) ;
V_30 = F_19 ( V_37 , V_2 , V_23 ) ;
if ( ! V_30 ) {
if ( ! V_112 ) {
F_6 ( & V_11 ) ;
V_112 = F_92 ( V_2 , V_23 . type ) ;
if ( ! V_112 )
F_67 () ;
goto V_108;
}
V_30 = V_112 ;
V_112 = NULL ;
V_30 -> V_35 = V_23 ;
F_30 ( V_30 ) ;
F_15 ( V_30 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
} else {
if ( ! F_57 ( & V_30 -> V_70 ) )
F_26 ( V_30 ) ;
F_72 ( & V_30 -> V_70 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_115 ) ;
F_25 ( V_82 ) ;
}
F_33 ( V_30 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) ) {
int V_55 ;
V_55 = V_2 -> V_49 -> V_116 ( V_30 ) ;
if ( V_55 < 0 ) {
F_45 ( V_30 ) ;
V_30 = F_100 ( V_55 ) ;
goto V_83;
}
}
#ifdef F_84
F_89 ( ! V_30 -> V_34 ) ;
#endif
V_83:
if ( V_112 )
F_61 ( V_112 ) ;
return V_30 ;
}
static inline struct V_30 * * F_101 ( struct V_117 * V_117 )
{
return V_117 -> V_118 -> V_91 -> V_119 ( V_117 ) ;
}
static int F_102 ( struct V_117 * V_117 , int type )
{
struct V_30 * const * V_120 ;
int V_56 ;
if ( F_103 ( V_117 ) )
return 0 ;
V_120 = F_101 ( V_117 ) ;
if ( type != - 1 )
return ! V_120 [ type ] ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ! V_120 [ V_56 ] )
return 1 ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 , int type )
{
struct V_117 * V_117 , * V_121 = NULL ;
#ifdef F_84
int V_122 = 0 ;
#endif
F_5 ( & V_2 -> V_123 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_117 -> V_124 ) ;
if ( ( V_117 -> V_125 & ( V_126 | V_127 | V_128 ) ) ||
! F_57 ( & V_117 -> V_129 ) ||
! F_102 ( V_117 , type ) ) {
F_6 ( & V_117 -> V_124 ) ;
continue;
}
F_105 ( V_117 ) ;
F_6 ( & V_117 -> V_124 ) ;
F_6 ( & V_2 -> V_123 ) ;
#ifdef F_84
if ( F_106 ( F_107 ( V_117 ) > 0 ) )
V_122 = 1 ;
#endif
F_108 ( V_121 ) ;
F_109 ( V_117 , type ) ;
V_121 = V_117 ;
F_5 ( & V_2 -> V_123 ) ;
}
F_6 ( & V_2 -> V_123 ) ;
F_108 ( V_121 ) ;
#ifdef F_84
if ( V_122 ) {
F_85 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static void F_110 ( struct V_117 * V_117 , int type ,
struct V_84 * V_130 )
{
struct V_30 * * V_120 = F_101 ( V_117 ) ;
struct V_30 * V_30 = V_120 [ type ] ;
if ( ! V_30 )
return;
V_120 [ type ] = NULL ;
if ( F_27 ( & V_30 -> V_40 ) ) {
F_5 ( & V_11 ) ;
F_41 ( & V_30 -> V_40 , V_130 ) ;
F_6 ( & V_11 ) ;
} else {
F_45 ( V_30 ) ;
}
}
static void F_111 ( struct V_84 * V_130 )
{
struct V_84 * V_131 ;
struct V_30 * V_30 ;
V_131 = V_130 -> V_132 ;
while ( V_131 != V_130 ) {
V_30 = F_80 ( V_131 , struct V_30 , V_40 ) ;
V_131 = V_131 -> V_132 ;
F_28 ( & V_30 -> V_40 ) ;
F_45 ( V_30 ) ;
}
}
static void F_112 ( struct V_1 * V_2 , int type ,
struct V_84 * V_130 )
{
struct V_117 * V_117 ;
int V_122 = 0 ;
F_5 ( & V_2 -> V_123 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_133 ) ;
if ( ! F_103 ( V_117 ) ) {
if ( F_106 ( F_107 ( V_117 ) > 0 ) )
V_122 = 1 ;
F_110 ( V_117 , type , V_130 ) ;
}
F_6 ( & V_133 ) ;
}
F_6 ( & V_2 -> V_123 ) ;
#ifdef F_84
if ( V_122 ) {
F_3 ( V_134 L_8
L_9
L_10 , V_2 -> V_9 ) ;
}
#endif
}
static void F_113 ( struct V_1 * V_2 , int type )
{
F_114 ( V_130 ) ;
if ( V_2 -> V_49 ) {
F_112 ( V_2 , type , & V_130 ) ;
F_115 ( & V_135 ) ;
F_111 ( & V_130 ) ;
}
}
static inline void F_116 ( struct V_30 * V_30 , T_2 V_136 )
{
V_30 -> V_137 . V_138 += V_136 ;
}
static inline void F_117 ( struct V_30 * V_30 , T_2 V_136 )
{
V_30 -> V_137 . V_139 += V_136 ;
}
static inline void F_118 ( struct V_30 * V_30 , T_2 V_136 )
{
V_30 -> V_137 . V_140 += V_136 ;
}
static void F_119 ( struct V_30 * V_30 , T_2 V_136 )
{
if ( V_30 -> V_137 . V_140 < V_136 ) {
F_120 ( 1 ) ;
V_136 = V_30 -> V_137 . V_140 ;
}
V_30 -> V_137 . V_139 += V_136 ;
V_30 -> V_137 . V_140 -= V_136 ;
}
static void F_121 ( struct V_30 * V_30 , T_2 V_136 )
{
if ( F_120 ( V_30 -> V_137 . V_139 < V_136 ) )
V_136 = V_30 -> V_137 . V_139 ;
V_30 -> V_137 . V_140 += V_136 ;
V_30 -> V_137 . V_139 -= V_136 ;
}
static inline
void F_122 ( struct V_30 * V_30 , T_2 V_136 )
{
if ( V_30 -> V_137 . V_140 >= V_136 )
V_30 -> V_137 . V_140 -= V_136 ;
else {
F_120 ( 1 ) ;
V_30 -> V_137 . V_140 = 0 ;
}
}
static void F_123 ( struct V_30 * V_30 , T_2 V_136 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_141 ||
V_30 -> V_137 . V_138 >= V_136 )
V_30 -> V_137 . V_138 -= V_136 ;
else
V_30 -> V_137 . V_138 = 0 ;
if ( V_30 -> V_137 . V_138 <= V_30 -> V_137 . V_142 )
V_30 -> V_137 . V_143 = ( V_144 ) 0 ;
F_58 ( V_145 , & V_30 -> V_48 ) ;
}
static void F_124 ( struct V_30 * V_30 , T_2 V_136 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_141 ||
V_30 -> V_137 . V_139 >= V_136 )
V_30 -> V_137 . V_139 -= V_136 ;
else
V_30 -> V_137 . V_139 = 0 ;
if ( V_30 -> V_137 . V_139 <= V_30 -> V_137 . V_146 )
V_30 -> V_137 . V_147 = ( V_144 ) 0 ;
F_58 ( V_148 , & V_30 -> V_48 ) ;
}
static int F_125 ( struct V_30 * V_30 , const int V_149 )
{
int V_150 = ( V_149 == V_151 ||
V_149 == V_152 ) ? V_148 :
( ( V_149 == V_153 ||
V_149 == V_154 ) ? V_145 : 0 ) ;
if ( ! V_150 )
return 0 ;
return F_40 ( V_150 , & V_30 -> V_48 ) ;
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
F_132 ( V_166 , V_106 [ V_156 -> V_158 . type ] ) ;
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
struct V_178 * V_53 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
return F_139 ( V_179 ) &&
( V_53 -> V_180 -> V_16 != V_181 ||
! ( V_53 -> V_58 & V_182 ) ) ;
}
static int F_140 ( struct V_30 * V_30 , T_2 V_183 ,
struct V_155 * V_156 )
{
T_2 V_184 = V_30 -> V_137 . V_138 + V_183 ;
if ( ! F_141 ( V_30 -> V_34 , V_30 -> V_35 . type ) ||
F_37 ( V_185 , & V_30 -> V_48 ) )
return 0 ;
if ( V_30 -> V_137 . V_186 &&
V_184 > V_30 -> V_137 . V_186 &&
! F_138 ( V_30 ) ) {
F_134 ( V_156 , V_30 , V_153 ) ;
return - V_187 ;
}
if ( V_30 -> V_137 . V_142 &&
V_184 > V_30 -> V_137 . V_142 &&
V_30 -> V_137 . V_143 &&
F_142 () >= V_30 -> V_137 . V_143 &&
! F_138 ( V_30 ) ) {
F_134 ( V_156 , V_30 , V_154 ) ;
return - V_187 ;
}
if ( V_30 -> V_137 . V_142 &&
V_184 > V_30 -> V_137 . V_142 &&
V_30 -> V_137 . V_143 == 0 ) {
F_134 ( V_156 , V_30 , V_173 ) ;
V_30 -> V_137 . V_143 = F_142 () +
F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] . V_188 ;
}
return 0 ;
}
static int F_143 ( struct V_30 * V_30 , T_2 V_189 , int V_190 ,
struct V_155 * V_156 )
{
T_2 V_191 ;
struct V_1 * V_2 = V_30 -> V_34 ;
if ( ! F_141 ( V_2 , V_30 -> V_35 . type ) ||
F_37 ( V_185 , & V_30 -> V_48 ) )
return 0 ;
V_191 = V_30 -> V_137 . V_139 + V_30 -> V_137 . V_140
+ V_189 ;
if ( V_30 -> V_137 . V_192 &&
V_191 > V_30 -> V_137 . V_192 &&
! F_138 ( V_30 ) ) {
if ( ! V_190 )
F_134 ( V_156 , V_30 , V_151 ) ;
return - V_187 ;
}
if ( V_30 -> V_137 . V_146 &&
V_191 > V_30 -> V_137 . V_146 &&
V_30 -> V_137 . V_147 &&
F_142 () >= V_30 -> V_137 . V_147 &&
! F_138 ( V_30 ) ) {
if ( ! V_190 )
F_134 ( V_156 , V_30 , V_152 ) ;
return - V_187 ;
}
if ( V_30 -> V_137 . V_146 &&
V_191 > V_30 -> V_137 . V_146 &&
V_30 -> V_137 . V_147 == 0 ) {
if ( ! V_190 ) {
F_134 ( V_156 , V_30 , V_174 ) ;
V_30 -> V_137 . V_147 = F_142 () +
F_42 ( V_2 ) -> V_53 [ V_30 -> V_35 . type ] . V_193 ;
}
else
return - V_187 ;
}
return 0 ;
}
static int F_144 ( struct V_30 * V_30 , T_2 V_183 )
{
T_2 V_184 ;
if ( F_37 ( V_185 , & V_30 -> V_48 ) ||
V_30 -> V_137 . V_138 <= V_30 -> V_137 . V_142 ||
! F_141 ( V_30 -> V_34 , V_30 -> V_35 . type ) )
return V_176 ;
V_184 = V_30 -> V_137 . V_138 - V_183 ;
if ( V_184 <= V_30 -> V_137 . V_142 )
return V_169 ;
if ( V_30 -> V_137 . V_138 >= V_30 -> V_137 . V_186 &&
V_184 < V_30 -> V_137 . V_186 )
return V_168 ;
return V_176 ;
}
static int F_145 ( struct V_30 * V_30 , T_2 V_189 )
{
if ( F_37 ( V_185 , & V_30 -> V_48 ) ||
V_30 -> V_137 . V_139 <= V_30 -> V_137 . V_146 )
return V_176 ;
if ( V_30 -> V_137 . V_139 - V_189 <= V_30 -> V_137 . V_146 )
return V_171 ;
if ( V_30 -> V_137 . V_139 >= V_30 -> V_137 . V_192 &&
V_30 -> V_137 . V_139 - V_189 < V_30 -> V_137 . V_192 )
return V_170 ;
return V_176 ;
}
static int F_146 ( const struct V_117 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_118 ;
if ( F_103 ( V_117 ) )
return 0 ;
return F_147 ( V_2 ) & ~ F_148 ( V_2 ) ;
}
static int F_109 ( struct V_117 * V_117 , int type )
{
int V_56 , V_194 = 0 ;
struct V_30 * * V_120 , * V_195 [ V_27 ] ;
struct V_1 * V_2 = V_117 -> V_118 ;
T_2 V_196 ;
int V_51 = 0 ;
if ( ! F_146 ( V_117 ) )
return 0 ;
V_120 = F_101 ( V_117 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
struct V_22 V_23 ;
T_3 V_197 ;
int V_198 ;
struct V_30 * V_30 ;
V_195 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( V_120 [ V_56 ] )
continue;
if ( ! F_74 ( V_2 , V_56 ) )
continue;
V_194 = 1 ;
switch ( V_56 ) {
case V_159 :
V_23 = F_149 ( V_117 -> V_199 ) ;
break;
case V_161 :
V_23 = F_150 ( V_117 -> V_200 ) ;
break;
case V_163 :
V_198 = V_117 -> V_118 -> V_49 -> V_201 ( V_117 , & V_197 ) ;
if ( V_198 )
continue;
V_23 = F_151 ( V_197 ) ;
break;
}
V_30 = F_99 ( V_2 , V_23 ) ;
if ( F_152 ( V_30 ) ) {
if ( F_153 ( V_30 ) != - V_113 ) {
V_51 = F_153 ( V_30 ) ;
goto V_202;
}
V_30 = NULL ;
}
V_195 [ V_56 ] = V_30 ;
}
if ( ! V_194 )
return 0 ;
F_5 ( & V_133 ) ;
if ( F_103 ( V_117 ) )
goto V_203;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_74 ( V_2 , V_56 ) )
continue;
if ( ! V_195 [ V_56 ] )
continue;
if ( ! V_120 [ V_56 ] ) {
V_120 [ V_56 ] = V_195 [ V_56 ] ;
V_195 [ V_56 ] = NULL ;
V_196 = F_107 ( V_117 ) ;
if ( F_106 ( V_196 ) )
F_118 ( V_120 [ V_56 ] , V_196 ) ;
}
}
V_203:
F_6 ( & V_133 ) ;
V_202:
F_44 ( V_195 ) ;
return V_51 ;
}
int F_154 ( struct V_117 * V_117 )
{
return F_109 ( V_117 , - 1 ) ;
}
static void F_155 ( struct V_117 * V_117 )
{
int V_56 ;
struct V_30 * * V_120 = F_101 ( V_117 ) ;
struct V_30 * V_204 [ V_27 ] ;
F_5 ( & V_133 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_204 [ V_56 ] = V_120 [ V_56 ] ;
V_120 [ V_56 ] = NULL ;
}
F_6 ( & V_133 ) ;
F_44 ( V_204 ) ;
}
void F_156 ( struct V_117 * V_117 )
{
struct V_30 * const * V_120 ;
int V_56 ;
if ( F_103 ( V_117 ) )
return;
V_120 = F_101 ( V_117 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_120 [ V_56 ] )
break;
}
if ( V_56 < V_27 )
F_155 ( V_117 ) ;
}
static T_2 * F_157 ( struct V_117 * V_117 )
{
F_89 ( ! V_117 -> V_118 -> V_49 -> V_205 ) ;
return V_117 -> V_118 -> V_49 -> V_205 ( V_117 ) ;
}
void F_158 ( struct V_117 * V_117 , T_2 V_136 )
{
F_5 ( & V_117 -> V_124 ) ;
* F_157 ( V_117 ) += V_136 ;
F_6 ( & V_117 -> V_124 ) ;
}
void F_159 ( struct V_117 * V_117 , T_2 V_136 )
{
F_5 ( & V_117 -> V_124 ) ;
* F_157 ( V_117 ) -= V_136 ;
F_160 ( V_117 , V_136 ) ;
F_6 ( & V_117 -> V_124 ) ;
}
void F_161 ( struct V_117 * V_117 , T_2 V_136 )
{
F_5 ( & V_117 -> V_124 ) ;
* F_157 ( V_117 ) += V_136 ;
F_162 ( V_117 , V_136 ) ;
F_6 ( & V_117 -> V_124 ) ;
}
void F_163 ( struct V_117 * V_117 , T_2 V_136 )
{
F_5 ( & V_117 -> V_124 ) ;
* F_157 ( V_117 ) -= V_136 ;
F_6 ( & V_117 -> V_124 ) ;
}
static T_2 F_107 ( struct V_117 * V_117 )
{
T_2 V_51 ;
if ( ! V_117 -> V_118 -> V_49 -> V_205 )
return 0 ;
F_5 ( & V_117 -> V_124 ) ;
V_51 = * F_157 ( V_117 ) ;
F_6 ( & V_117 -> V_124 ) ;
return V_51 ;
}
static void F_164 ( struct V_117 * V_117 , T_2 V_136 ,
int V_206 )
{
if ( V_206 )
F_158 ( V_117 , V_136 ) ;
else
F_165 ( V_117 , V_136 ) ;
}
static void F_166 ( struct V_117 * V_117 , T_2 V_136 , int V_206 )
{
if ( V_206 )
F_163 ( V_117 , V_136 ) ;
else
F_167 ( V_117 , V_136 ) ;
}
int F_168 ( struct V_117 * V_117 , T_2 V_136 , int V_89 )
{
int V_56 , V_51 = 0 , V_207 ;
struct V_155 V_156 [ V_27 ] ;
int V_206 = V_89 & V_208 ;
struct V_30 * * V_120 ;
if ( ! F_146 ( V_117 ) ) {
F_164 ( V_117 , V_136 , V_206 ) ;
goto V_83;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_156 [ V_56 ] . V_167 = V_176 ;
V_120 = F_101 ( V_117 ) ;
V_207 = F_169 ( & V_135 ) ;
F_5 ( & V_133 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_120 [ V_56 ] )
continue;
V_51 = F_143 ( V_120 [ V_56 ] , V_136 ,
! ( V_89 & V_209 ) , & V_156 [ V_56 ] ) ;
if ( V_51 && ! ( V_89 & V_210 ) ) {
F_6 ( & V_133 ) ;
goto V_211;
}
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_120 [ V_56 ] )
continue;
if ( V_206 )
F_118 ( V_120 [ V_56 ] , V_136 ) ;
else
F_117 ( V_120 [ V_56 ] , V_136 ) ;
}
F_164 ( V_117 , V_136 , V_206 ) ;
F_6 ( & V_133 ) ;
if ( V_206 )
goto V_211;
F_43 ( V_120 ) ;
V_211:
F_170 ( & V_135 , V_207 ) ;
F_135 ( V_156 ) ;
V_83:
return V_51 ;
}
int F_171 ( struct V_117 * V_117 )
{
int V_56 , V_51 = 0 , V_207 ;
struct V_155 V_156 [ V_27 ] ;
struct V_30 * const * V_120 ;
if ( ! F_146 ( V_117 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_156 [ V_56 ] . V_167 = V_176 ;
V_120 = F_101 ( V_117 ) ;
V_207 = F_169 ( & V_135 ) ;
F_5 ( & V_133 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_120 [ V_56 ] )
continue;
V_51 = F_140 ( V_120 [ V_56 ] , 1 , & V_156 [ V_56 ] ) ;
if ( V_51 )
goto V_212;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_120 [ V_56 ] )
continue;
F_116 ( V_120 [ V_56 ] , 1 ) ;
}
V_212:
F_6 ( & V_133 ) ;
if ( V_51 == 0 )
F_43 ( V_120 ) ;
F_170 ( & V_135 , V_207 ) ;
F_135 ( V_156 ) ;
return V_51 ;
}
int F_172 ( struct V_117 * V_117 , T_2 V_136 )
{
struct V_30 * * V_120 ;
int V_56 , V_207 ;
if ( ! F_146 ( V_117 ) ) {
F_159 ( V_117 , V_136 ) ;
return 0 ;
}
V_120 = F_101 ( V_117 ) ;
V_207 = F_169 ( & V_135 ) ;
F_5 ( & V_133 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_120 [ V_56 ] )
F_119 ( V_120 [ V_56 ] , V_136 ) ;
}
F_159 ( V_117 , V_136 ) ;
F_6 ( & V_133 ) ;
F_43 ( V_120 ) ;
F_170 ( & V_135 , V_207 ) ;
return 0 ;
}
void F_173 ( struct V_117 * V_117 , T_2 V_136 )
{
struct V_30 * * V_120 ;
int V_56 , V_207 ;
if ( ! F_146 ( V_117 ) ) {
F_161 ( V_117 , V_136 ) ;
return;
}
V_120 = F_101 ( V_117 ) ;
V_207 = F_169 ( & V_135 ) ;
F_5 ( & V_133 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_120 [ V_56 ] )
F_121 ( V_120 [ V_56 ] , V_136 ) ;
}
F_161 ( V_117 , V_136 ) ;
F_6 ( & V_133 ) ;
F_43 ( V_120 ) ;
F_170 ( & V_135 , V_207 ) ;
return;
}
void F_174 ( struct V_117 * V_117 , T_2 V_136 , int V_89 )
{
unsigned int V_56 ;
struct V_155 V_156 [ V_27 ] ;
struct V_30 * * V_120 ;
int V_206 = V_89 & V_208 , V_207 ;
if ( ! F_146 ( V_117 ) ) {
F_166 ( V_117 , V_136 , V_206 ) ;
return;
}
V_120 = F_101 ( V_117 ) ;
V_207 = F_169 ( & V_135 ) ;
F_5 ( & V_133 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_213 ;
V_156 [ V_56 ] . V_167 = V_176 ;
if ( ! V_120 [ V_56 ] )
continue;
V_213 = F_145 ( V_120 [ V_56 ] , V_136 ) ;
if ( V_213 != V_176 )
F_134 ( & V_156 [ V_56 ] , V_120 [ V_56 ] , V_213 ) ;
if ( V_206 )
F_122 ( V_120 [ V_56 ] , V_136 ) ;
else
F_124 ( V_120 [ V_56 ] , V_136 ) ;
}
F_166 ( V_117 , V_136 , V_206 ) ;
F_6 ( & V_133 ) ;
if ( V_206 )
goto V_214;
F_43 ( V_120 ) ;
V_214:
F_170 ( & V_135 , V_207 ) ;
F_135 ( V_156 ) ;
}
void F_175 ( struct V_117 * V_117 )
{
unsigned int V_56 ;
struct V_155 V_156 [ V_27 ] ;
struct V_30 * const * V_120 ;
int V_207 ;
if ( ! F_146 ( V_117 ) )
return;
V_120 = F_101 ( V_117 ) ;
V_207 = F_169 ( & V_135 ) ;
F_5 ( & V_133 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_213 ;
V_156 [ V_56 ] . V_167 = V_176 ;
if ( ! V_120 [ V_56 ] )
continue;
V_213 = F_144 ( V_120 [ V_56 ] , 1 ) ;
if ( V_213 != V_176 )
F_134 ( & V_156 [ V_56 ] , V_120 [ V_56 ] , V_213 ) ;
F_123 ( V_120 [ V_56 ] , 1 ) ;
}
F_6 ( & V_133 ) ;
F_43 ( V_120 ) ;
F_170 ( & V_135 , V_207 ) ;
F_135 ( V_156 ) ;
}
int F_176 ( struct V_117 * V_117 , struct V_30 * * V_215 )
{
T_2 V_189 , V_216 ;
T_2 V_217 = 0 ;
struct V_30 * V_218 [ V_27 ] = {} ;
int V_56 , V_51 = 0 ;
char V_219 [ V_27 ] = {} ;
struct V_155 V_220 [ V_27 ] ;
struct V_155 V_221 [ V_27 ] ;
struct V_155 V_222 [ V_27 ] ;
if ( F_103 ( V_117 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_220 [ V_56 ] . V_167 = V_176 ;
V_221 [ V_56 ] . V_167 = V_176 ;
V_222 [ V_56 ] . V_167 = V_176 ;
}
F_5 ( & V_133 ) ;
if ( F_103 ( V_117 ) ) {
F_6 ( & V_133 ) ;
return 0 ;
}
V_216 = F_177 ( V_117 ) ;
V_217 = F_107 ( V_117 ) ;
V_189 = V_216 + V_217 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_215 [ V_56 ] )
continue;
if ( ! F_74 ( V_117 -> V_118 , V_56 ) )
continue;
V_219 [ V_56 ] = 1 ;
V_218 [ V_56 ] = F_101 ( V_117 ) [ V_56 ] ;
V_51 = F_140 ( V_215 [ V_56 ] , 1 , & V_220 [ V_56 ] ) ;
if ( V_51 )
goto V_223;
V_51 = F_143 ( V_215 [ V_56 ] , V_189 , 0 , & V_220 [ V_56 ] ) ;
if ( V_51 )
goto V_223;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_219 [ V_56 ] )
continue;
if ( V_218 [ V_56 ] ) {
int V_213 ;
V_213 = F_144 ( V_218 [ V_56 ] , 1 ) ;
if ( V_213 != V_176 )
F_134 ( & V_221 [ V_56 ] ,
V_218 [ V_56 ] , V_213 ) ;
V_213 = F_145 ( V_218 [ V_56 ] , V_189 ) ;
if ( V_213 != V_176 )
F_134 ( & V_222 [ V_56 ] ,
V_218 [ V_56 ] , V_213 ) ;
F_123 ( V_218 [ V_56 ] , 1 ) ;
F_124 ( V_218 [ V_56 ] , V_216 ) ;
F_122 ( V_218 [ V_56 ] ,
V_217 ) ;
}
F_116 ( V_215 [ V_56 ] , 1 ) ;
F_117 ( V_215 [ V_56 ] , V_216 ) ;
F_118 ( V_215 [ V_56 ] , V_217 ) ;
F_101 ( V_117 ) [ V_56 ] = V_215 [ V_56 ] ;
}
F_6 ( & V_133 ) ;
F_43 ( V_218 ) ;
F_43 ( V_215 ) ;
F_135 ( V_220 ) ;
F_135 ( V_221 ) ;
F_135 ( V_222 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_219 [ V_56 ] )
V_215 [ V_56 ] = V_218 [ V_56 ] ;
return 0 ;
V_223:
F_6 ( & V_133 ) ;
F_135 ( V_220 ) ;
return V_51 ;
}
int F_178 ( struct V_117 * V_117 , struct V_224 * V_224 )
{
struct V_30 * V_215 [ V_27 ] = {} ;
struct V_30 * V_30 ;
struct V_1 * V_2 = V_117 -> V_118 ;
int V_51 ;
if ( ! F_146 ( V_117 ) )
return 0 ;
if ( V_224 -> V_225 & V_226 && ! F_127 ( V_224 -> V_227 , V_117 -> V_199 ) ) {
V_30 = F_99 ( V_2 , F_149 ( V_224 -> V_227 ) ) ;
if ( F_152 ( V_30 ) ) {
if ( F_153 ( V_30 ) != - V_113 ) {
V_51 = F_153 ( V_30 ) ;
goto V_202;
}
V_30 = NULL ;
}
V_215 [ V_159 ] = V_30 ;
}
if ( V_224 -> V_225 & V_228 && ! F_179 ( V_224 -> V_229 , V_117 -> V_200 ) ) {
V_30 = F_99 ( V_2 , F_150 ( V_224 -> V_229 ) ) ;
if ( F_152 ( V_30 ) ) {
if ( F_153 ( V_30 ) != - V_113 ) {
V_51 = F_153 ( V_30 ) ;
goto V_202;
}
V_30 = NULL ;
}
V_215 [ V_161 ] = V_30 ;
}
V_51 = F_176 ( V_117 , V_215 ) ;
V_202:
F_44 ( V_215 ) ;
return V_51 ;
}
int F_180 ( struct V_1 * V_2 , int type )
{
int V_51 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_34 ( & V_61 -> V_62 ) ;
V_51 = V_61 -> V_64 [ type ] -> F_54 ( V_2 , type ) ;
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_181 ( struct V_117 * V_117 , struct V_230 * V_230 )
{
int error ;
error = F_182 ( V_117 , V_230 ) ;
if ( ! error && ( V_230 -> V_231 & V_232 ) )
F_154 ( V_117 ) ;
return error ;
}
int F_183 ( struct V_1 * V_2 , int type , unsigned int V_89 )
{
int V_56 , V_51 = 0 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_117 * V_233 [ V_27 ] ;
if ( ( V_89 & V_234 && ! ( V_89 & V_235 ) )
|| ( V_89 & V_236 && V_89 & ( V_235 |
V_234 ) ) )
return - V_237 ;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_147 ( V_2 ) ) {
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_233 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_184 ( V_2 , V_56 ) )
continue;
if ( V_89 & V_236 ) {
F_5 ( & V_114 ) ;
V_61 -> V_89 |=
F_185 ( V_236 , V_56 ) ;
F_6 ( & V_114 ) ;
} else {
F_5 ( & V_114 ) ;
V_61 -> V_89 &= ~ F_185 ( V_89 , V_56 ) ;
if ( ! F_184 ( V_2 , V_56 ) &&
F_186 ( V_2 , V_56 ) ) {
V_61 -> V_89 &= ~ F_185 (
V_236 , V_56 ) ;
F_6 ( & V_114 ) ;
F_108 ( V_61 -> V_94 [ V_56 ] ) ;
V_61 -> V_94 [ V_56 ] = NULL ;
continue;
}
F_6 ( & V_114 ) ;
}
if ( F_184 ( V_2 , V_56 ) && ! ( V_89 & V_236 ) )
continue;
F_113 ( V_2 , V_56 ) ;
F_62 ( V_2 , V_56 ) ;
if ( F_53 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
if ( V_61 -> V_64 [ V_56 ] -> V_238 )
V_61 -> V_64 [ V_56 ] -> V_238 ( V_2 , V_56 ) ;
F_11 ( V_61 -> V_53 [ V_56 ] . V_180 ) ;
V_233 [ V_56 ] = V_61 -> V_94 [ V_56 ] ;
if ( ! F_184 ( V_2 , V_56 ) )
V_61 -> V_94 [ V_56 ] = NULL ;
V_61 -> V_53 [ V_56 ] . V_58 = 0 ;
V_61 -> V_53 [ V_56 ] . V_188 = 0 ;
V_61 -> V_53 [ V_56 ] . V_193 = 0 ;
V_61 -> V_64 [ V_56 ] = NULL ;
}
F_35 ( & V_61 -> V_81 ) ;
if ( V_61 -> V_89 & V_90 )
goto V_239;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_77 ( V_2 -> V_93 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_233 [ V_56 ] ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_184 ( V_2 , V_56 ) ) {
F_34 ( & V_233 [ V_56 ] -> V_95 ) ;
V_233 [ V_56 ] -> V_240 &= ~ ( V_241 |
V_242 | V_243 ) ;
F_78 ( & V_233 [ V_56 ] -> V_96 ,
0 ) ;
F_35 ( & V_233 [ V_56 ] -> V_95 ) ;
F_187 ( V_233 [ V_56 ] ) ;
}
F_35 ( & V_61 -> V_81 ) ;
}
if ( V_2 -> V_93 )
F_188 ( V_2 -> V_93 ) ;
V_239:
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_233 [ V_56 ] ) {
if ( ! ( V_89 & V_236 ) )
F_108 ( V_233 [ V_56 ] ) ;
else if ( ! V_233 [ V_56 ] -> V_244 )
V_51 = - V_245 ;
}
return V_51 ;
}
int F_189 ( struct V_1 * V_2 , int type )
{
return F_183 ( V_2 , type ,
V_234 | V_235 ) ;
}
static int F_190 ( struct V_117 * V_117 , int type , int V_246 ,
unsigned int V_89 )
{
struct V_10 * V_4 = F_8 ( V_246 ) ;
struct V_1 * V_2 = V_117 -> V_118 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int error ;
int V_247 = - 1 ;
if ( ! V_4 )
return - V_113 ;
if ( ! F_191 ( V_117 -> V_248 ) ) {
error = - V_249 ;
goto V_250;
}
if ( F_192 ( V_117 ) ) {
error = - V_251 ;
goto V_250;
}
if ( ! V_2 -> V_91 -> V_252 || ! V_2 -> V_91 -> V_253 ||
( type == V_163 && V_2 -> V_49 -> V_201 == NULL ) ) {
error = - V_237 ;
goto V_250;
}
if ( ! ( V_89 & V_234 ) ) {
error = - V_237 ;
goto V_250;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_193 ( V_2 ) ;
F_188 ( V_2 -> V_93 ) ;
}
F_34 ( & V_61 -> V_81 ) ;
if ( F_184 ( V_2 , type ) ) {
error = - V_245 ;
goto V_203;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_34 ( & V_117 -> V_95 ) ;
V_247 = V_117 -> V_240 & ( V_242 | V_241 |
V_243 ) ;
V_117 -> V_240 |= V_243 | V_242 | V_241 ;
F_35 ( & V_117 -> V_95 ) ;
F_155 ( V_117 ) ;
}
error = - V_69 ;
V_61 -> V_94 [ type ] = F_194 ( V_117 ) ;
if ( ! V_61 -> V_94 [ type ] )
goto V_203;
error = - V_237 ;
if ( ! V_4 -> V_254 -> V_255 ( V_2 , type ) )
goto V_256;
V_61 -> V_64 [ type ] = V_4 -> V_254 ;
V_61 -> V_53 [ type ] . V_180 = V_4 ;
V_61 -> V_53 [ type ] . V_257 = V_246 ;
F_94 ( & V_61 -> V_53 [ type ] . V_54 ) ;
F_34 ( & V_61 -> V_62 ) ;
error = V_61 -> V_64 [ type ] -> F_195 ( V_2 , type ) ;
if ( error < 0 ) {
F_35 ( & V_61 -> V_62 ) ;
goto V_256;
}
if ( V_61 -> V_89 & V_90 )
V_61 -> V_53 [ type ] . V_58 |= V_258 ;
F_35 ( & V_61 -> V_62 ) ;
F_5 ( & V_114 ) ;
V_61 -> V_89 |= F_185 ( V_89 , type ) ;
F_6 ( & V_114 ) ;
F_104 ( V_2 , type ) ;
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
V_256:
V_61 -> V_94 [ type ] = NULL ;
F_108 ( V_117 ) ;
V_203:
if ( V_247 != - 1 ) {
F_34 ( & V_117 -> V_95 ) ;
V_117 -> V_240 &= ~ ( V_242 | V_243 | V_241 ) ;
V_117 -> V_240 |= V_247 ;
F_35 ( & V_117 -> V_95 ) ;
}
F_35 ( & V_61 -> V_81 ) ;
V_250:
F_11 ( V_4 ) ;
return error ;
}
int F_196 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_117 * V_117 ;
int V_51 = 0 , V_56 ;
unsigned int V_89 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_186 ( V_2 , V_56 ) ) {
F_35 ( & V_61 -> V_81 ) ;
continue;
}
V_117 = V_61 -> V_94 [ V_56 ] ;
V_61 -> V_94 [ V_56 ] = NULL ;
F_5 ( & V_114 ) ;
V_89 = V_61 -> V_89 & F_185 ( V_234 |
V_235 ,
V_56 ) ;
V_61 -> V_89 &= ~ F_185 ( V_259 , V_56 ) ;
F_6 ( & V_114 ) ;
F_35 ( & V_61 -> V_81 ) ;
V_89 = F_197 ( V_89 , V_56 ) ;
V_51 = F_190 ( V_117 , V_56 ,
V_61 -> V_53 [ V_56 ] . V_257 , V_89 ) ;
F_108 ( V_117 ) ;
}
return V_51 ;
}
int F_198 ( struct V_1 * V_2 , int type , int V_246 ,
struct V_260 * V_260 )
{
int error = F_199 ( V_260 -> V_261 ) ;
if ( error )
return error ;
if ( V_260 -> V_261 -> V_262 != V_2 )
error = - V_263 ;
else
error = F_190 ( F_200 ( V_260 -> V_261 ) , type ,
V_246 , V_234 |
V_235 ) ;
return error ;
}
int F_201 ( struct V_117 * V_117 , int type , int V_246 ,
unsigned int V_89 )
{
int V_51 = 0 ;
struct V_1 * V_2 = V_117 -> V_118 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_89 ( V_89 & V_236 ) ;
if ( ! V_89 )
return 0 ;
if ( F_184 ( V_2 , type ) ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_184 ( V_2 , type ) ) {
F_35 ( & V_61 -> V_81 ) ;
goto V_264;
}
if ( V_89 & V_234 &&
F_202 ( V_2 , type ) ) {
V_51 = - V_245 ;
goto V_203;
}
if ( V_89 & V_235 &&
F_141 ( V_2 , type ) ) {
V_51 = - V_245 ;
goto V_203;
}
F_5 ( & V_114 ) ;
F_42 ( V_2 ) -> V_89 |= F_185 ( V_89 , type ) ;
F_6 ( & V_114 ) ;
V_203:
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
V_264:
return F_190 ( V_117 , type , V_246 , V_89 ) ;
}
int F_203 ( struct V_1 * V_2 , char * V_265 ,
int V_246 , int type )
{
struct V_261 * V_261 ;
int error ;
F_34 ( & F_200 ( V_2 -> V_266 ) -> V_95 ) ;
V_261 = F_204 ( V_265 , V_2 -> V_266 , strlen ( V_265 ) ) ;
F_35 ( & F_200 ( V_2 -> V_266 ) -> V_95 ) ;
if ( F_152 ( V_261 ) )
return F_153 ( V_261 ) ;
if ( F_205 ( V_261 ) ) {
error = - V_267 ;
goto V_83;
}
error = F_199 ( V_261 ) ;
if ( ! error )
error = F_190 ( F_200 ( V_261 ) , type , V_246 ,
V_234 | V_235 ) ;
V_83:
F_206 ( V_261 ) ;
return error ;
}
static int F_207 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_268 ;
V_89 &= ~ ( V_269 | V_270 | V_271 ) ;
if ( ! V_89 )
return - V_237 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! ( V_89 & F_208 ( type ) ) )
continue;
if ( ! F_202 ( V_2 , type ) )
return - V_237 ;
V_51 = F_201 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_257 ,
V_235 ) ;
if ( V_51 < 0 )
goto V_272;
}
return 0 ;
V_272:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_208 ( type ) )
F_183 ( V_2 , type , V_235 ) ;
}
if ( V_51 == - V_245 )
V_51 = - V_273 ;
return V_51 ;
}
static int F_209 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_268 ;
if ( V_89 &
( V_269 | V_270 | V_271 ) )
return - V_274 ;
for ( type = 0 ; type < V_27 ; type ++ )
if ( ! F_141 ( V_2 , type ) )
V_89 &= ~ F_208 ( type ) ;
if ( ! V_89 )
return - V_273 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( V_89 & F_208 ( type ) ) {
V_51 = F_183 ( V_2 , type , V_235 ) ;
if ( V_51 < 0 )
goto V_272;
}
}
return 0 ;
V_272:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_208 ( type ) )
F_201 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_257 ,
V_235 ) ;
}
return V_51 ;
}
static void F_210 ( struct V_30 * V_30 , struct V_275 * V_276 )
{
struct V_277 * V_278 = & V_30 -> V_137 ;
memset ( V_276 , 0 , sizeof( * V_276 ) ) ;
F_5 ( & V_133 ) ;
V_276 -> V_279 = V_278 -> V_192 ;
V_276 -> V_280 = V_278 -> V_146 ;
V_276 -> V_281 = V_278 -> V_186 ;
V_276 -> V_282 = V_278 -> V_142 ;
V_276 -> V_283 = V_278 -> V_139 + V_278 -> V_140 ;
V_276 -> V_284 = V_278 -> V_138 ;
V_276 -> V_285 = V_278 -> V_147 ;
V_276 -> V_286 = V_278 -> V_143 ;
F_6 ( & V_133 ) ;
}
int F_211 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_275 * V_276 )
{
struct V_30 * V_30 ;
V_30 = F_99 ( V_2 , V_23 ) ;
if ( F_152 ( V_30 ) )
return F_153 ( V_30 ) ;
F_210 ( V_30 , V_276 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_212 ( struct V_30 * V_30 , struct V_275 * V_276 )
{
struct V_277 * V_278 = & V_30 -> V_137 ;
int V_287 = 0 , V_288 = 0 ;
struct V_178 * V_289 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
if ( V_276 -> V_290 & ~ V_291 )
return - V_237 ;
if ( ( ( V_276 -> V_290 & V_292 ) &&
V_276 -> V_280 > V_289 -> V_293 ) ||
( ( V_276 -> V_290 & V_294 ) &&
V_276 -> V_279 > V_289 -> V_293 ) ||
( ( V_276 -> V_290 & V_295 ) &&
( V_276 -> V_282 > V_289 -> V_296 ) ) ||
( ( V_276 -> V_290 & V_297 ) &&
( V_276 -> V_281 > V_289 -> V_296 ) ) )
return - V_298 ;
F_5 ( & V_133 ) ;
if ( V_276 -> V_290 & V_299 ) {
V_278 -> V_139 = V_276 -> V_283 - V_278 -> V_140 ;
V_287 = 1 ;
F_49 ( V_300 + V_301 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_292 )
V_278 -> V_146 = V_276 -> V_280 ;
if ( V_276 -> V_290 & V_294 )
V_278 -> V_192 = V_276 -> V_279 ;
if ( V_276 -> V_290 & ( V_292 | V_294 ) ) {
V_287 = 1 ;
F_49 ( V_300 + V_302 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_303 ) {
V_278 -> V_138 = V_276 -> V_284 ;
V_288 = 1 ;
F_49 ( V_300 + V_304 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_295 )
V_278 -> V_142 = V_276 -> V_282 ;
if ( V_276 -> V_290 & V_297 )
V_278 -> V_186 = V_276 -> V_281 ;
if ( V_276 -> V_290 & ( V_295 | V_297 ) ) {
V_288 = 1 ;
F_49 ( V_300 + V_305 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_306 ) {
V_278 -> V_147 = V_276 -> V_285 ;
V_287 = 1 ;
F_49 ( V_300 + V_307 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_308 ) {
V_278 -> V_143 = V_276 -> V_286 ;
V_288 = 1 ;
F_49 ( V_300 + V_309 , & V_30 -> V_48 ) ;
}
if ( V_287 ) {
if ( ! V_278 -> V_146 ||
V_278 -> V_139 < V_278 -> V_146 ) {
V_278 -> V_147 = 0 ;
F_58 ( V_148 , & V_30 -> V_48 ) ;
} else if ( ! ( V_276 -> V_290 & V_306 ) )
V_278 -> V_147 = F_142 () + V_289 -> V_193 ;
}
if ( V_288 ) {
if ( ! V_278 -> V_142 ||
V_278 -> V_138 < V_278 -> V_142 ) {
V_278 -> V_143 = 0 ;
F_58 ( V_145 , & V_30 -> V_48 ) ;
} else if ( ! ( V_276 -> V_290 & V_308 ) )
V_278 -> V_143 = F_142 () + V_289 -> V_188 ;
}
if ( V_278 -> V_192 || V_278 -> V_146 || V_278 -> V_186 ||
V_278 -> V_142 )
F_58 ( V_185 , & V_30 -> V_48 ) ;
else
F_49 ( V_185 , & V_30 -> V_48 ) ;
F_6 ( & V_133 ) ;
F_38 ( V_30 ) ;
return 0 ;
}
int F_213 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_275 * V_276 )
{
struct V_30 * V_30 ;
int V_198 ;
V_30 = F_99 ( V_2 , V_23 ) ;
if ( F_152 ( V_30 ) ) {
V_198 = F_153 ( V_30 ) ;
goto V_83;
}
V_198 = F_212 ( V_30 , V_276 ) ;
F_45 ( V_30 ) ;
V_83:
return V_198 ;
}
int F_214 ( struct V_1 * V_2 , struct V_310 * V_311 )
{
struct V_178 * V_312 ;
struct V_313 * V_314 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int type ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
memset ( V_311 , 0 , sizeof( * V_311 ) ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! F_74 ( V_2 , type ) )
continue;
V_314 = V_311 -> V_315 + type ;
V_312 = F_42 ( V_2 ) -> V_53 + type ;
V_314 -> V_89 = V_316 ;
F_5 ( & V_133 ) ;
if ( V_312 -> V_58 & V_258 )
V_314 -> V_89 |= V_317 ;
if ( V_312 -> V_58 & V_182 )
V_314 -> V_89 |= V_318 ;
if ( F_141 ( V_2 , type ) )
V_314 -> V_89 |= V_319 ;
V_314 -> V_320 = V_312 -> V_193 ;
V_314 -> V_321 = V_312 -> V_188 ;
V_314 -> V_322 = V_61 -> V_94 [ type ] -> V_323 ;
V_314 -> V_324 = V_61 -> V_94 [ type ] -> V_325 ;
V_314 -> V_326 = 1 ;
F_6 ( & V_133 ) ;
}
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return 0 ;
}
int F_215 ( struct V_1 * V_2 , int type , struct V_327 * V_328 )
{
struct V_178 * V_312 ;
int V_55 = 0 ;
if ( ( V_328 -> V_329 & V_330 ) ||
( V_328 -> V_329 & V_331 ) )
return - V_237 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_74 ( V_2 , type ) ) {
V_55 = - V_113 ;
goto V_83;
}
V_312 = F_42 ( V_2 ) -> V_53 + type ;
if ( V_328 -> V_329 & V_332 ) {
if ( ( V_328 -> V_240 & V_318 &&
V_312 -> V_180 -> V_16 != V_181 ) ) {
V_55 = - V_237 ;
goto V_83;
}
}
F_5 ( & V_133 ) ;
if ( V_328 -> V_329 & V_306 )
V_312 -> V_193 = V_328 -> V_333 ;
if ( V_328 -> V_329 & V_308 )
V_312 -> V_188 = V_328 -> V_334 ;
if ( V_328 -> V_329 & V_332 ) {
if ( V_328 -> V_240 & V_318 )
V_312 -> V_58 |= V_182 ;
else
V_312 -> V_58 &= ~ V_182 ;
}
F_6 ( & V_133 ) ;
F_48 ( V_2 , type ) ;
V_2 -> V_49 -> V_87 ( V_2 , type ) ;
V_83:
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_55 ;
}
static int F_216 ( struct V_335 * V_336 , int V_337 ,
void T_4 * V_338 , T_5 * V_339 , T_6 * V_340 )
{
unsigned int type = ( int * ) V_336 -> V_341 - V_104 . V_342 ;
V_104 . V_342 [ type ] =
F_217 ( & V_104 . V_105 [ type ] ) ;
return F_218 ( V_336 , V_337 , V_338 , V_339 , V_340 ) ;
}
static int T_7 F_219 ( void )
{
int V_175 , V_51 ;
unsigned long V_343 , V_344 ;
F_3 ( V_345 L_19 , V_346 ) ;
F_220 ( V_347 ) ;
V_73 = F_221 ( L_20 ,
sizeof( struct V_30 ) , sizeof( unsigned long ) * 4 ,
( V_348 | V_349 |
V_350 | V_351 ) ,
NULL ) ;
V_344 = 0 ;
V_33 = (struct V_31 * ) F_222 ( V_352 , V_344 ) ;
if ( ! V_33 )
F_223 ( L_21 ) ;
for ( V_175 = 0 ; V_175 < V_353 ; V_175 ++ ) {
V_51 = F_224 ( & V_104 . V_105 [ V_175 ] , 0 , V_354 ) ;
if ( V_51 )
F_223 ( L_22 ) ;
}
V_343 = ( 1UL << V_344 ) * V_355 / sizeof( struct V_31 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( V_343 >> V_28 );
V_28 -- ;
V_343 = 1UL << V_28 ;
V_29 = V_343 - 1 ;
for ( V_175 = 0 ; V_175 < V_343 ; V_175 ++ )
F_225 ( V_33 + V_175 ) ;
F_226 ( L_23
L_24 , V_343 , V_344 , ( V_355 << V_344 ) ) ;
F_227 ( & V_356 ) ;
return 0 ;
}

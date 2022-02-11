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
F_52 () ;
F_49 ( V_63 , & V_30 -> V_48 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) && ! V_30 -> V_67 ) {
V_51 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_53 ( V_30 ) ;
if ( F_54 ( & V_61 -> V_53 [ V_30 -> V_35 . type ] ) ) {
V_59 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_55 (
V_30 -> V_34 , V_30 -> V_35 . type ) ;
}
if ( V_51 < 0 )
goto V_65;
if ( V_59 < 0 ) {
V_51 = V_59 ;
goto V_65;
}
}
F_52 () ;
F_49 ( V_66 , & V_30 -> V_48 ) ;
V_65:
F_35 ( & V_61 -> V_62 ) ;
F_35 ( & V_30 -> V_46 ) ;
return V_51 ;
}
int F_56 ( struct V_30 * V_30 )
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
V_51 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_53 ( V_30 ) ;
else
V_51 = - V_69 ;
V_68:
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_57 ( struct V_30 * V_30 )
{
int V_51 = 0 , V_59 = 0 ;
struct V_60 * V_61 = F_42 ( V_30 -> V_34 ) ;
F_34 ( & V_30 -> V_46 ) ;
if ( F_58 ( & V_30 -> V_70 ) > 1 )
goto V_71;
F_34 ( & V_61 -> V_62 ) ;
if ( V_61 -> V_64 [ V_30 -> V_35 . type ] -> V_72 ) {
V_51 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> V_72 ( V_30 ) ;
if ( F_54 ( & V_61 -> V_53 [ V_30 -> V_35 . type ] ) ) {
V_59 = V_61 -> V_64 [ V_30 -> V_35 . type ] -> F_55 (
V_30 -> V_34 , V_30 -> V_35 . type ) ;
}
if ( V_51 >= 0 )
V_51 = V_59 ;
}
F_59 ( V_66 , & V_30 -> V_48 ) ;
F_35 ( & V_61 -> V_62 ) ;
V_71:
F_35 ( & V_30 -> V_46 ) ;
return V_51 ;
}
void F_60 ( struct V_30 * V_30 )
{
F_61 ( V_73 , V_30 ) ;
}
static inline void F_62 ( struct V_30 * V_30 )
{
V_30 -> V_34 -> V_49 -> V_74 ( V_30 ) ;
}
static void F_63 ( struct V_1 * V_2 , int type )
{
struct V_30 * V_30 , * V_25 ;
V_75:
F_5 ( & V_11 ) ;
F_64 (dquot, tmp, &inuse_list, dq_inuse) {
if ( V_30 -> V_34 != V_2 )
continue;
if ( V_30 -> V_35 . type != type )
continue;
if ( F_58 ( & V_30 -> V_70 ) ) {
F_65 ( V_76 ) ;
F_66 ( V_30 ) ;
F_67 ( & V_30 -> V_77 , & V_76 ,
V_78 ) ;
F_6 ( & V_11 ) ;
if ( F_58 ( & V_30 -> V_70 ) > 1 )
F_68 () ;
F_69 ( & V_30 -> V_77 , & V_76 ) ;
F_45 ( V_30 ) ;
goto V_75;
}
F_17 ( V_30 ) ;
F_26 ( V_30 ) ;
F_31 ( V_30 ) ;
F_62 ( V_30 ) ;
}
F_6 ( & V_11 ) ;
}
int F_70 ( struct V_1 * V_2 ,
int (* F_71)( struct V_30 * V_30 , unsigned long V_79 ) ,
unsigned long V_79 )
{
struct V_30 * V_30 , * V_80 = NULL ;
int V_51 = 0 ;
F_72 ( ! F_73 ( & V_2 -> V_81 ) ) ;
F_5 ( & V_11 ) ;
F_74 (dquot, &inuse_list, dq_inuse) {
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) )
continue;
if ( V_30 -> V_34 != V_2 )
continue;
F_75 ( & V_30 -> V_70 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
F_45 ( V_80 ) ;
V_80 = V_30 ;
F_33 ( V_30 ) ;
if ( F_37 ( V_66 , & V_30 -> V_48 ) ) {
V_51 = F_71 ( V_30 , V_79 ) ;
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
int F_76 ( struct V_1 * V_2 , int type )
{
struct V_84 * V_85 ;
struct V_30 * V_30 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int V_56 ;
int V_55 , V_51 = 0 ;
F_72 ( ! F_73 ( & V_2 -> V_81 ) ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_77 ( V_2 , V_56 ) )
continue;
F_5 ( & V_11 ) ;
V_85 = & V_61 -> V_53 [ V_56 ] . V_54 ;
while ( ! F_27 ( V_85 ) ) {
V_30 = F_78 ( V_85 , struct V_30 ,
V_52 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) ) {
F_46 ( V_30 ) ;
continue;
}
F_66 ( V_30 ) ;
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
if ( ( V_56 == type || type == - 1 ) && F_77 ( V_2 , V_56 )
&& F_54 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
F_25 ( V_88 ) ;
return V_51 ;
}
int F_79 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
int V_56 ;
int V_51 ;
V_51 = F_76 ( V_2 , type ) ;
if ( V_51 )
return V_51 ;
if ( V_61 -> V_89 & V_90 )
return 0 ;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_80 ( V_2 -> V_93 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_77 ( V_2 , V_56 ) )
continue;
F_81 ( V_61 -> V_94 [ V_56 ] ) ;
F_82 ( & V_61 -> V_94 [ V_56 ] -> V_95 , 0 ) ;
F_83 ( V_61 -> V_94 [ V_56 ] ) ;
}
return 0 ;
}
static unsigned long
F_84 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
struct V_84 * V_32 ;
struct V_30 * V_30 ;
unsigned long V_100 = 0 ;
F_5 ( & V_11 ) ;
V_32 = V_41 . V_101 ;
while ( V_32 != & V_41 && V_99 -> V_102 ) {
V_30 = F_85 ( V_32 , struct V_30 , V_40 ) ;
F_17 ( V_30 ) ;
F_26 ( V_30 ) ;
F_31 ( V_30 ) ;
F_62 ( V_30 ) ;
V_99 -> V_102 -- ;
V_100 ++ ;
V_32 = V_41 . V_101 ;
}
F_6 ( & V_11 ) ;
return V_100 ;
}
static unsigned long
F_86 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
return F_87 (
F_88 ( & V_103 . V_104 [ V_42 ] ) ) ;
}
void F_45 ( struct V_30 * V_30 )
{
int V_51 ;
if ( ! V_30 )
return;
#ifdef F_89
if ( ! F_58 ( & V_30 -> V_70 ) ) {
F_90 ( V_30 -> V_34 , L_2 ,
V_105 [ V_30 -> V_35 . type ] ,
F_14 ( & V_24 , V_30 -> V_35 ) ) ;
F_91 () ;
}
#endif
F_25 ( V_106 ) ;
V_107:
F_5 ( & V_11 ) ;
if ( F_58 ( & V_30 -> V_70 ) > 1 ) {
F_92 ( & V_30 -> V_70 ) ;
if ( ! F_77 ( V_30 -> V_34 , V_30 -> V_35 . type ) &&
F_58 ( & V_30 -> V_70 ) == 1 )
F_93 ( & V_30 -> V_77 ) ;
F_6 ( & V_11 ) ;
return;
}
if ( F_37 ( V_66 , & V_30 -> V_48 ) && F_36 ( V_30 ) ) {
F_6 ( & V_11 ) ;
V_51 = V_30 -> V_34 -> V_49 -> V_86 ( V_30 ) ;
if ( V_51 < 0 ) {
F_90 ( V_30 -> V_34 , L_3
L_4 ,
V_51 ) ;
F_5 ( & V_11 ) ;
F_46 ( V_30 ) ;
F_6 ( & V_11 ) ;
}
goto V_107;
}
F_46 ( V_30 ) ;
if ( F_37 ( V_66 , & V_30 -> V_48 ) ) {
F_6 ( & V_11 ) ;
V_30 -> V_34 -> V_49 -> V_108 ( V_30 ) ;
goto V_107;
}
F_92 ( & V_30 -> V_70 ) ;
#ifdef F_89
F_94 ( ! F_27 ( & V_30 -> V_40 ) ) ;
#endif
F_23 ( V_30 ) ;
F_6 ( & V_11 ) ;
}
struct V_30 * F_95 ( struct V_1 * V_2 , int type )
{
return F_96 ( V_73 , V_109 ) ;
}
static struct V_30 * F_97 ( struct V_1 * V_2 , int type )
{
struct V_30 * V_30 ;
V_30 = V_2 -> V_49 -> V_110 ( V_2 , type ) ;
if( ! V_30 )
return NULL ;
F_98 ( & V_30 -> V_46 ) ;
F_99 ( & V_30 -> V_40 ) ;
F_99 ( & V_30 -> V_43 ) ;
F_100 ( & V_30 -> V_36 ) ;
F_99 ( & V_30 -> V_52 ) ;
F_101 ( & V_30 -> V_77 ) ;
V_30 -> V_34 = V_2 ;
V_30 -> V_35 = F_102 ( type ) ;
F_103 ( & V_30 -> V_70 , 1 ) ;
return V_30 ;
}
struct V_30 * F_104 ( struct V_1 * V_2 , struct V_22 V_23 )
{
unsigned int V_37 = F_13 ( V_2 , V_23 ) ;
struct V_30 * V_30 , * V_111 = NULL ;
if ( ! F_105 ( V_2 -> V_112 , V_23 ) )
return F_106 ( - V_113 ) ;
if ( ! F_77 ( V_2 , V_23 . type ) )
return F_106 ( - V_114 ) ;
V_107:
F_5 ( & V_11 ) ;
F_5 ( & V_115 ) ;
if ( ! F_77 ( V_2 , V_23 . type ) ) {
F_6 ( & V_115 ) ;
F_6 ( & V_11 ) ;
V_30 = F_106 ( - V_114 ) ;
goto V_83;
}
F_6 ( & V_115 ) ;
V_30 = F_19 ( V_37 , V_2 , V_23 ) ;
if ( ! V_30 ) {
if ( ! V_111 ) {
F_6 ( & V_11 ) ;
V_111 = F_97 ( V_2 , V_23 . type ) ;
if ( ! V_111 )
F_68 () ;
goto V_107;
}
V_30 = V_111 ;
V_111 = NULL ;
V_30 -> V_35 = V_23 ;
F_30 ( V_30 ) ;
F_15 ( V_30 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
} else {
if ( ! F_58 ( & V_30 -> V_70 ) )
F_26 ( V_30 ) ;
F_75 ( & V_30 -> V_70 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_116 ) ;
F_25 ( V_82 ) ;
}
F_33 ( V_30 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) ) {
int V_55 ;
V_55 = V_2 -> V_49 -> V_117 ( V_30 ) ;
if ( V_55 < 0 ) {
F_45 ( V_30 ) ;
V_30 = F_106 ( V_55 ) ;
goto V_83;
}
}
F_107 () ;
#ifdef F_89
F_94 ( ! V_30 -> V_34 ) ;
#endif
V_83:
if ( V_111 )
F_62 ( V_111 ) ;
return V_30 ;
}
static inline struct V_30 * * F_108 ( struct V_118 * V_118 )
{
return V_118 -> V_119 -> V_91 -> V_120 ( V_118 ) ;
}
static int F_109 ( struct V_118 * V_118 , int type )
{
struct V_30 * const * V_121 ;
int V_56 ;
if ( F_110 ( V_118 ) )
return 0 ;
V_121 = F_108 ( V_118 ) ;
if ( type != - 1 )
return ! V_121 [ type ] ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ! V_121 [ V_56 ] )
return 1 ;
return 0 ;
}
static void F_111 ( struct V_1 * V_2 , int type )
{
struct V_118 * V_118 , * V_122 = NULL ;
#ifdef F_89
int V_123 = 0 ;
#endif
F_5 ( & V_2 -> V_124 ) ;
F_74 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_118 -> V_125 ) ;
if ( ( V_118 -> V_126 & ( V_127 | V_128 | V_129 ) ) ||
! F_58 ( & V_118 -> V_130 ) ||
! F_109 ( V_118 , type ) ) {
F_6 ( & V_118 -> V_125 ) ;
continue;
}
F_112 ( V_118 ) ;
F_6 ( & V_118 -> V_125 ) ;
F_6 ( & V_2 -> V_124 ) ;
#ifdef F_89
if ( F_113 ( F_114 ( V_118 ) > 0 ) )
V_123 = 1 ;
#endif
F_115 ( V_122 ) ;
F_116 ( V_118 , type ) ;
V_122 = V_118 ;
F_5 ( & V_2 -> V_124 ) ;
}
F_6 ( & V_2 -> V_124 ) ;
F_115 ( V_122 ) ;
#ifdef F_89
if ( V_123 ) {
F_90 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static void F_117 ( struct V_118 * V_118 , int type ,
struct V_84 * V_131 )
{
struct V_30 * * V_121 = F_108 ( V_118 ) ;
struct V_30 * V_30 = V_121 [ type ] ;
if ( ! V_30 )
return;
V_121 [ type ] = NULL ;
if ( F_27 ( & V_30 -> V_40 ) ) {
F_5 ( & V_11 ) ;
F_41 ( & V_30 -> V_40 , V_131 ) ;
F_6 ( & V_11 ) ;
} else {
F_45 ( V_30 ) ;
}
}
static void F_118 ( struct V_84 * V_131 )
{
struct V_84 * V_132 ;
struct V_30 * V_30 ;
V_132 = V_131 -> V_133 ;
while ( V_132 != V_131 ) {
V_30 = F_85 ( V_132 , struct V_30 , V_40 ) ;
V_132 = V_132 -> V_133 ;
F_28 ( & V_30 -> V_40 ) ;
F_45 ( V_30 ) ;
}
}
static void F_119 ( struct V_1 * V_2 , int type ,
struct V_84 * V_131 )
{
struct V_118 * V_118 ;
int V_123 = 0 ;
F_5 ( & V_2 -> V_124 ) ;
F_74 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_134 ) ;
if ( ! F_110 ( V_118 ) ) {
if ( F_113 ( F_114 ( V_118 ) > 0 ) )
V_123 = 1 ;
F_117 ( V_118 , type , V_131 ) ;
}
F_6 ( & V_134 ) ;
}
F_6 ( & V_2 -> V_124 ) ;
#ifdef F_89
if ( V_123 ) {
F_3 ( V_135 L_8
L_9
L_10 , V_2 -> V_9 ) ;
}
#endif
}
static void F_120 ( struct V_1 * V_2 , int type )
{
F_121 ( V_131 ) ;
if ( V_2 -> V_49 ) {
F_119 ( V_2 , type , & V_131 ) ;
F_122 ( & V_136 ) ;
F_118 ( & V_131 ) ;
}
}
static inline void F_123 ( struct V_30 * V_30 , T_2 V_137 )
{
V_30 -> V_138 . V_139 += V_137 ;
}
static inline void F_124 ( struct V_30 * V_30 , T_2 V_137 )
{
V_30 -> V_138 . V_140 += V_137 ;
}
static inline void F_125 ( struct V_30 * V_30 , T_2 V_137 )
{
V_30 -> V_138 . V_141 += V_137 ;
}
static void F_126 ( struct V_30 * V_30 , T_2 V_137 )
{
if ( V_30 -> V_138 . V_141 < V_137 ) {
F_72 ( 1 ) ;
V_137 = V_30 -> V_138 . V_141 ;
}
V_30 -> V_138 . V_140 += V_137 ;
V_30 -> V_138 . V_141 -= V_137 ;
}
static void F_127 ( struct V_30 * V_30 , T_2 V_137 )
{
if ( F_72 ( V_30 -> V_138 . V_140 < V_137 ) )
V_137 = V_30 -> V_138 . V_140 ;
V_30 -> V_138 . V_141 += V_137 ;
V_30 -> V_138 . V_140 -= V_137 ;
}
static inline
void F_128 ( struct V_30 * V_30 , T_2 V_137 )
{
if ( V_30 -> V_138 . V_141 >= V_137 )
V_30 -> V_138 . V_141 -= V_137 ;
else {
F_72 ( 1 ) ;
V_30 -> V_138 . V_141 = 0 ;
}
}
static void F_129 ( struct V_30 * V_30 , T_2 V_137 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_142 ||
V_30 -> V_138 . V_139 >= V_137 )
V_30 -> V_138 . V_139 -= V_137 ;
else
V_30 -> V_138 . V_139 = 0 ;
if ( V_30 -> V_138 . V_139 <= V_30 -> V_138 . V_143 )
V_30 -> V_138 . V_144 = ( V_145 ) 0 ;
F_59 ( V_146 , & V_30 -> V_48 ) ;
}
static void F_130 ( struct V_30 * V_30 , T_2 V_137 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_142 ||
V_30 -> V_138 . V_140 >= V_137 )
V_30 -> V_138 . V_140 -= V_137 ;
else
V_30 -> V_138 . V_140 = 0 ;
if ( V_30 -> V_138 . V_140 <= V_30 -> V_138 . V_147 )
V_30 -> V_138 . V_148 = ( V_145 ) 0 ;
F_59 ( V_149 , & V_30 -> V_48 ) ;
}
static int F_131 ( struct V_30 * V_30 , const int V_150 )
{
int V_151 = ( V_150 == V_152 ||
V_150 == V_153 ) ? V_149 :
( ( V_150 == V_154 ||
V_150 == V_155 ) ? V_146 : 0 ) ;
if ( ! V_151 )
return 0 ;
return F_40 ( V_151 , & V_30 -> V_48 ) ;
}
static int F_132 ( struct V_156 * V_157 )
{
if ( ! V_158 )
return 0 ;
switch ( V_157 -> V_159 . type ) {
case V_160 :
return F_133 ( F_134 () , V_157 -> V_159 . V_161 ) ;
case V_162 :
return F_135 ( V_157 -> V_159 . V_163 ) ;
case V_164 :
return 1 ;
}
return 0 ;
}
static void F_136 ( struct V_156 * V_157 )
{
char * V_165 = NULL ;
struct V_166 * V_167 ;
int V_150 = V_157 -> V_168 ;
if ( V_150 == V_169 ||
V_150 == V_170 ||
V_150 == V_171 ||
V_150 == V_172 || ! F_132 ( V_157 ) )
return;
V_167 = F_137 () ;
if ( ! V_167 )
return;
F_138 ( V_167 , V_157 -> V_173 -> V_9 ) ;
if ( V_150 == V_174 || V_150 == V_175 )
F_138 ( V_167 , L_11 ) ;
else
F_138 ( V_167 , L_12 ) ;
F_138 ( V_167 , V_105 [ V_157 -> V_159 . type ] ) ;
switch ( V_150 ) {
case V_154 :
V_165 = L_13 ;
break;
case V_155 :
V_165 = L_14 ;
break;
case V_174 :
V_165 = L_15 ;
break;
case V_152 :
V_165 = L_16 ;
break;
case V_153 :
V_165 = L_17 ;
break;
case V_175 :
V_165 = L_18 ;
break;
}
F_138 ( V_167 , V_165 ) ;
F_139 ( V_167 ) ;
}
static void F_140 ( struct V_156 * V_157 , struct V_30 * V_30 ,
int V_150 )
{
if ( F_131 ( V_30 , V_150 ) )
return;
V_157 -> V_168 = V_150 ;
V_157 -> V_173 = V_30 -> V_34 ;
V_157 -> V_159 = V_30 -> V_35 ;
}
static void F_141 ( struct V_156 * V_157 )
{
int V_176 ;
for ( V_176 = 0 ; V_176 < V_27 ; V_176 ++ ) {
if ( V_157 [ V_176 ] . V_168 == V_177 )
continue;
#ifdef F_142
F_136 ( & V_157 [ V_176 ] ) ;
#endif
F_143 ( V_157 [ V_176 ] . V_159 ,
V_157 [ V_176 ] . V_173 -> V_178 , V_157 [ V_176 ] . V_168 ) ;
}
}
static int F_144 ( struct V_30 * V_30 )
{
struct V_179 * V_53 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
return F_145 ( V_180 ) &&
( V_53 -> V_181 -> V_16 != V_182 ||
! ( V_53 -> V_58 & V_183 ) ) ;
}
static int F_146 ( struct V_30 * V_30 , T_2 V_184 ,
struct V_156 * V_157 )
{
T_2 V_185 = V_30 -> V_138 . V_139 + V_184 ;
if ( ! F_147 ( V_30 -> V_34 , V_30 -> V_35 . type ) ||
F_37 ( V_186 , & V_30 -> V_48 ) )
return 0 ;
if ( V_30 -> V_138 . V_187 &&
V_185 > V_30 -> V_138 . V_187 &&
! F_144 ( V_30 ) ) {
F_140 ( V_157 , V_30 , V_154 ) ;
return - V_188 ;
}
if ( V_30 -> V_138 . V_143 &&
V_185 > V_30 -> V_138 . V_143 &&
V_30 -> V_138 . V_144 &&
F_148 () >= V_30 -> V_138 . V_144 &&
! F_144 ( V_30 ) ) {
F_140 ( V_157 , V_30 , V_155 ) ;
return - V_188 ;
}
if ( V_30 -> V_138 . V_143 &&
V_185 > V_30 -> V_138 . V_143 &&
V_30 -> V_138 . V_144 == 0 ) {
F_140 ( V_157 , V_30 , V_174 ) ;
V_30 -> V_138 . V_144 = F_148 () +
F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] . V_189 ;
}
return 0 ;
}
static int F_149 ( struct V_30 * V_30 , T_2 V_190 , int V_191 ,
struct V_156 * V_157 )
{
T_2 V_192 ;
struct V_1 * V_2 = V_30 -> V_34 ;
if ( ! F_147 ( V_2 , V_30 -> V_35 . type ) ||
F_37 ( V_186 , & V_30 -> V_48 ) )
return 0 ;
V_192 = V_30 -> V_138 . V_140 + V_30 -> V_138 . V_141
+ V_190 ;
if ( V_30 -> V_138 . V_193 &&
V_192 > V_30 -> V_138 . V_193 &&
! F_144 ( V_30 ) ) {
if ( ! V_191 )
F_140 ( V_157 , V_30 , V_152 ) ;
return - V_188 ;
}
if ( V_30 -> V_138 . V_147 &&
V_192 > V_30 -> V_138 . V_147 &&
V_30 -> V_138 . V_148 &&
F_148 () >= V_30 -> V_138 . V_148 &&
! F_144 ( V_30 ) ) {
if ( ! V_191 )
F_140 ( V_157 , V_30 , V_153 ) ;
return - V_188 ;
}
if ( V_30 -> V_138 . V_147 &&
V_192 > V_30 -> V_138 . V_147 &&
V_30 -> V_138 . V_148 == 0 ) {
if ( ! V_191 ) {
F_140 ( V_157 , V_30 , V_175 ) ;
V_30 -> V_138 . V_148 = F_148 () +
F_42 ( V_2 ) -> V_53 [ V_30 -> V_35 . type ] . V_194 ;
}
else
return - V_188 ;
}
return 0 ;
}
static int F_150 ( struct V_30 * V_30 , T_2 V_184 )
{
T_2 V_185 ;
if ( F_37 ( V_186 , & V_30 -> V_48 ) ||
V_30 -> V_138 . V_139 <= V_30 -> V_138 . V_143 ||
! F_147 ( V_30 -> V_34 , V_30 -> V_35 . type ) )
return V_177 ;
V_185 = V_30 -> V_138 . V_139 - V_184 ;
if ( V_185 <= V_30 -> V_138 . V_143 )
return V_170 ;
if ( V_30 -> V_138 . V_139 >= V_30 -> V_138 . V_187 &&
V_185 < V_30 -> V_138 . V_187 )
return V_169 ;
return V_177 ;
}
static int F_151 ( struct V_30 * V_30 , T_2 V_190 )
{
if ( F_37 ( V_186 , & V_30 -> V_48 ) ||
V_30 -> V_138 . V_140 <= V_30 -> V_138 . V_147 )
return V_177 ;
if ( V_30 -> V_138 . V_140 - V_190 <= V_30 -> V_138 . V_147 )
return V_172 ;
if ( V_30 -> V_138 . V_140 >= V_30 -> V_138 . V_193 &&
V_30 -> V_138 . V_140 - V_190 < V_30 -> V_138 . V_193 )
return V_171 ;
return V_177 ;
}
static int F_152 ( const struct V_118 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_119 ;
if ( F_110 ( V_118 ) )
return 0 ;
return F_153 ( V_2 ) & ~ F_154 ( V_2 ) ;
}
static int F_116 ( struct V_118 * V_118 , int type )
{
int V_56 , V_195 = 0 ;
struct V_30 * * V_121 , * V_196 [ V_27 ] = {} ;
struct V_1 * V_2 = V_118 -> V_119 ;
T_2 V_197 ;
int V_51 = 0 ;
if ( ! F_152 ( V_118 ) )
return 0 ;
V_121 = F_108 ( V_118 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
struct V_22 V_23 ;
T_3 V_198 ;
int V_199 ;
struct V_30 * V_30 ;
if ( type != - 1 && V_56 != type )
continue;
if ( V_121 [ V_56 ] )
continue;
if ( ! F_77 ( V_2 , V_56 ) )
continue;
V_195 = 1 ;
switch ( V_56 ) {
case V_160 :
V_23 = F_155 ( V_118 -> V_200 ) ;
break;
case V_162 :
V_23 = F_156 ( V_118 -> V_201 ) ;
break;
case V_164 :
V_199 = V_118 -> V_119 -> V_49 -> V_202 ( V_118 , & V_198 ) ;
if ( V_199 )
continue;
V_23 = F_157 ( V_198 ) ;
break;
}
V_30 = F_104 ( V_2 , V_23 ) ;
if ( F_158 ( V_30 ) ) {
if ( F_159 ( V_30 ) != - V_114 ) {
V_51 = F_159 ( V_30 ) ;
goto V_203;
}
V_30 = NULL ;
}
V_196 [ V_56 ] = V_30 ;
}
if ( ! V_195 )
return 0 ;
F_5 ( & V_134 ) ;
if ( F_110 ( V_118 ) )
goto V_204;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_77 ( V_2 , V_56 ) )
continue;
if ( ! V_196 [ V_56 ] )
continue;
if ( ! V_121 [ V_56 ] ) {
V_121 [ V_56 ] = V_196 [ V_56 ] ;
V_196 [ V_56 ] = NULL ;
V_197 = F_114 ( V_118 ) ;
if ( F_113 ( V_197 ) )
F_125 ( V_121 [ V_56 ] , V_197 ) ;
}
}
V_204:
F_6 ( & V_134 ) ;
V_203:
F_44 ( V_196 ) ;
return V_51 ;
}
int F_160 ( struct V_118 * V_118 )
{
return F_116 ( V_118 , - 1 ) ;
}
static void F_161 ( struct V_118 * V_118 )
{
int V_56 ;
struct V_30 * * V_121 = F_108 ( V_118 ) ;
struct V_30 * V_205 [ V_27 ] ;
F_5 ( & V_134 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_205 [ V_56 ] = V_121 [ V_56 ] ;
V_121 [ V_56 ] = NULL ;
}
F_6 ( & V_134 ) ;
F_44 ( V_205 ) ;
}
void F_162 ( struct V_118 * V_118 )
{
struct V_30 * const * V_121 ;
int V_56 ;
if ( F_110 ( V_118 ) )
return;
V_121 = F_108 ( V_118 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_121 [ V_56 ] )
break;
}
if ( V_56 < V_27 )
F_161 ( V_118 ) ;
}
static T_2 * F_163 ( struct V_118 * V_118 )
{
F_94 ( ! V_118 -> V_119 -> V_49 -> V_206 ) ;
return V_118 -> V_119 -> V_49 -> V_206 ( V_118 ) ;
}
void F_164 ( struct V_118 * V_118 , T_2 V_137 )
{
F_5 ( & V_118 -> V_125 ) ;
* F_163 ( V_118 ) += V_137 ;
F_6 ( & V_118 -> V_125 ) ;
}
void F_165 ( struct V_118 * V_118 , T_2 V_137 )
{
F_5 ( & V_118 -> V_125 ) ;
* F_163 ( V_118 ) -= V_137 ;
F_166 ( V_118 , V_137 ) ;
F_6 ( & V_118 -> V_125 ) ;
}
void F_167 ( struct V_118 * V_118 , T_2 V_137 )
{
F_5 ( & V_118 -> V_125 ) ;
* F_163 ( V_118 ) += V_137 ;
F_168 ( V_118 , V_137 ) ;
F_6 ( & V_118 -> V_125 ) ;
}
void F_169 ( struct V_118 * V_118 , T_2 V_137 )
{
F_5 ( & V_118 -> V_125 ) ;
* F_163 ( V_118 ) -= V_137 ;
F_6 ( & V_118 -> V_125 ) ;
}
static T_2 F_114 ( struct V_118 * V_118 )
{
T_2 V_51 ;
if ( ! V_118 -> V_119 -> V_49 -> V_206 )
return 0 ;
F_5 ( & V_118 -> V_125 ) ;
V_51 = * F_163 ( V_118 ) ;
F_6 ( & V_118 -> V_125 ) ;
return V_51 ;
}
static void F_170 ( struct V_118 * V_118 , T_2 V_137 ,
int V_207 )
{
if ( V_207 )
F_164 ( V_118 , V_137 ) ;
else
F_171 ( V_118 , V_137 ) ;
}
static void F_172 ( struct V_118 * V_118 , T_2 V_137 , int V_207 )
{
if ( V_207 )
F_169 ( V_118 , V_137 ) ;
else
F_173 ( V_118 , V_137 ) ;
}
int F_174 ( struct V_118 * V_118 , T_2 V_137 , int V_89 )
{
int V_56 , V_51 = 0 , V_208 ;
struct V_156 V_157 [ V_27 ] ;
int V_207 = V_89 & V_209 ;
struct V_30 * * V_121 ;
if ( ! F_152 ( V_118 ) ) {
F_170 ( V_118 , V_137 , V_207 ) ;
goto V_83;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_157 [ V_56 ] . V_168 = V_177 ;
V_121 = F_108 ( V_118 ) ;
V_208 = F_175 ( & V_136 ) ;
F_5 ( & V_134 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_121 [ V_56 ] )
continue;
V_51 = F_149 ( V_121 [ V_56 ] , V_137 ,
! ( V_89 & V_210 ) , & V_157 [ V_56 ] ) ;
if ( V_51 && ! ( V_89 & V_211 ) ) {
F_6 ( & V_134 ) ;
goto V_212;
}
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_121 [ V_56 ] )
continue;
if ( V_207 )
F_125 ( V_121 [ V_56 ] , V_137 ) ;
else
F_124 ( V_121 [ V_56 ] , V_137 ) ;
}
F_170 ( V_118 , V_137 , V_207 ) ;
F_6 ( & V_134 ) ;
if ( V_207 )
goto V_212;
F_43 ( V_121 ) ;
V_212:
F_176 ( & V_136 , V_208 ) ;
F_141 ( V_157 ) ;
V_83:
return V_51 ;
}
int F_177 ( struct V_118 * V_118 )
{
int V_56 , V_51 = 0 , V_208 ;
struct V_156 V_157 [ V_27 ] ;
struct V_30 * const * V_121 ;
if ( ! F_152 ( V_118 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_157 [ V_56 ] . V_168 = V_177 ;
V_121 = F_108 ( V_118 ) ;
V_208 = F_175 ( & V_136 ) ;
F_5 ( & V_134 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_121 [ V_56 ] )
continue;
V_51 = F_146 ( V_121 [ V_56 ] , 1 , & V_157 [ V_56 ] ) ;
if ( V_51 )
goto V_213;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_121 [ V_56 ] )
continue;
F_123 ( V_121 [ V_56 ] , 1 ) ;
}
V_213:
F_6 ( & V_134 ) ;
if ( V_51 == 0 )
F_43 ( V_121 ) ;
F_176 ( & V_136 , V_208 ) ;
F_141 ( V_157 ) ;
return V_51 ;
}
int F_178 ( struct V_118 * V_118 , T_2 V_137 )
{
struct V_30 * * V_121 ;
int V_56 , V_208 ;
if ( ! F_152 ( V_118 ) ) {
F_165 ( V_118 , V_137 ) ;
return 0 ;
}
V_121 = F_108 ( V_118 ) ;
V_208 = F_175 ( & V_136 ) ;
F_5 ( & V_134 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_121 [ V_56 ] )
F_126 ( V_121 [ V_56 ] , V_137 ) ;
}
F_165 ( V_118 , V_137 ) ;
F_6 ( & V_134 ) ;
F_43 ( V_121 ) ;
F_176 ( & V_136 , V_208 ) ;
return 0 ;
}
void F_179 ( struct V_118 * V_118 , T_2 V_137 )
{
struct V_30 * * V_121 ;
int V_56 , V_208 ;
if ( ! F_152 ( V_118 ) ) {
F_167 ( V_118 , V_137 ) ;
return;
}
V_121 = F_108 ( V_118 ) ;
V_208 = F_175 ( & V_136 ) ;
F_5 ( & V_134 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_121 [ V_56 ] )
F_127 ( V_121 [ V_56 ] , V_137 ) ;
}
F_167 ( V_118 , V_137 ) ;
F_6 ( & V_134 ) ;
F_43 ( V_121 ) ;
F_176 ( & V_136 , V_208 ) ;
return;
}
void F_180 ( struct V_118 * V_118 , T_2 V_137 , int V_89 )
{
unsigned int V_56 ;
struct V_156 V_157 [ V_27 ] ;
struct V_30 * * V_121 ;
int V_207 = V_89 & V_209 , V_208 ;
if ( ! F_152 ( V_118 ) ) {
F_172 ( V_118 , V_137 , V_207 ) ;
return;
}
V_121 = F_108 ( V_118 ) ;
V_208 = F_175 ( & V_136 ) ;
F_5 ( & V_134 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_214 ;
V_157 [ V_56 ] . V_168 = V_177 ;
if ( ! V_121 [ V_56 ] )
continue;
V_214 = F_151 ( V_121 [ V_56 ] , V_137 ) ;
if ( V_214 != V_177 )
F_140 ( & V_157 [ V_56 ] , V_121 [ V_56 ] , V_214 ) ;
if ( V_207 )
F_128 ( V_121 [ V_56 ] , V_137 ) ;
else
F_130 ( V_121 [ V_56 ] , V_137 ) ;
}
F_172 ( V_118 , V_137 , V_207 ) ;
F_6 ( & V_134 ) ;
if ( V_207 )
goto V_215;
F_43 ( V_121 ) ;
V_215:
F_176 ( & V_136 , V_208 ) ;
F_141 ( V_157 ) ;
}
void F_181 ( struct V_118 * V_118 )
{
unsigned int V_56 ;
struct V_156 V_157 [ V_27 ] ;
struct V_30 * const * V_121 ;
int V_208 ;
if ( ! F_152 ( V_118 ) )
return;
V_121 = F_108 ( V_118 ) ;
V_208 = F_175 ( & V_136 ) ;
F_5 ( & V_134 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_214 ;
V_157 [ V_56 ] . V_168 = V_177 ;
if ( ! V_121 [ V_56 ] )
continue;
V_214 = F_150 ( V_121 [ V_56 ] , 1 ) ;
if ( V_214 != V_177 )
F_140 ( & V_157 [ V_56 ] , V_121 [ V_56 ] , V_214 ) ;
F_129 ( V_121 [ V_56 ] , 1 ) ;
}
F_6 ( & V_134 ) ;
F_43 ( V_121 ) ;
F_176 ( & V_136 , V_208 ) ;
F_141 ( V_157 ) ;
}
int F_182 ( struct V_118 * V_118 , struct V_30 * * V_216 )
{
T_2 V_190 , V_217 ;
T_2 V_218 = 0 ;
struct V_30 * V_219 [ V_27 ] = {} ;
int V_56 , V_51 = 0 ;
char V_220 [ V_27 ] = {} ;
struct V_156 V_221 [ V_27 ] ;
struct V_156 V_222 [ V_27 ] ;
struct V_156 V_223 [ V_27 ] ;
if ( F_110 ( V_118 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_221 [ V_56 ] . V_168 = V_177 ;
V_222 [ V_56 ] . V_168 = V_177 ;
V_223 [ V_56 ] . V_168 = V_177 ;
}
F_5 ( & V_134 ) ;
if ( F_110 ( V_118 ) ) {
F_6 ( & V_134 ) ;
return 0 ;
}
V_217 = F_183 ( V_118 ) ;
V_218 = F_114 ( V_118 ) ;
V_190 = V_217 + V_218 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_216 [ V_56 ] )
continue;
if ( ! F_77 ( V_118 -> V_119 , V_56 ) )
continue;
V_220 [ V_56 ] = 1 ;
V_219 [ V_56 ] = F_108 ( V_118 ) [ V_56 ] ;
V_51 = F_146 ( V_216 [ V_56 ] , 1 , & V_221 [ V_56 ] ) ;
if ( V_51 )
goto V_224;
V_51 = F_149 ( V_216 [ V_56 ] , V_190 , 0 , & V_221 [ V_56 ] ) ;
if ( V_51 )
goto V_224;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_220 [ V_56 ] )
continue;
if ( V_219 [ V_56 ] ) {
int V_214 ;
V_214 = F_150 ( V_219 [ V_56 ] , 1 ) ;
if ( V_214 != V_177 )
F_140 ( & V_222 [ V_56 ] ,
V_219 [ V_56 ] , V_214 ) ;
V_214 = F_151 ( V_219 [ V_56 ] , V_190 ) ;
if ( V_214 != V_177 )
F_140 ( & V_223 [ V_56 ] ,
V_219 [ V_56 ] , V_214 ) ;
F_129 ( V_219 [ V_56 ] , 1 ) ;
F_130 ( V_219 [ V_56 ] , V_217 ) ;
F_128 ( V_219 [ V_56 ] ,
V_218 ) ;
}
F_123 ( V_216 [ V_56 ] , 1 ) ;
F_124 ( V_216 [ V_56 ] , V_217 ) ;
F_125 ( V_216 [ V_56 ] , V_218 ) ;
F_108 ( V_118 ) [ V_56 ] = V_216 [ V_56 ] ;
}
F_6 ( & V_134 ) ;
F_43 ( V_219 ) ;
F_43 ( V_216 ) ;
F_141 ( V_221 ) ;
F_141 ( V_222 ) ;
F_141 ( V_223 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_220 [ V_56 ] )
V_216 [ V_56 ] = V_219 [ V_56 ] ;
return 0 ;
V_224:
F_6 ( & V_134 ) ;
F_141 ( V_221 ) ;
return V_51 ;
}
int F_184 ( struct V_118 * V_118 , struct V_225 * V_225 )
{
struct V_30 * V_216 [ V_27 ] = {} ;
struct V_30 * V_30 ;
struct V_1 * V_2 = V_118 -> V_119 ;
int V_51 ;
if ( ! F_152 ( V_118 ) )
return 0 ;
if ( V_225 -> V_226 & V_227 && ! F_133 ( V_225 -> V_228 , V_118 -> V_200 ) ) {
V_30 = F_104 ( V_2 , F_155 ( V_225 -> V_228 ) ) ;
if ( F_158 ( V_30 ) ) {
if ( F_159 ( V_30 ) != - V_114 ) {
V_51 = F_159 ( V_30 ) ;
goto V_203;
}
V_30 = NULL ;
}
V_216 [ V_160 ] = V_30 ;
}
if ( V_225 -> V_226 & V_229 && ! F_185 ( V_225 -> V_230 , V_118 -> V_201 ) ) {
V_30 = F_104 ( V_2 , F_156 ( V_225 -> V_230 ) ) ;
if ( F_158 ( V_30 ) ) {
if ( F_159 ( V_30 ) != - V_114 ) {
V_51 = F_159 ( V_30 ) ;
goto V_203;
}
V_30 = NULL ;
}
V_216 [ V_162 ] = V_30 ;
}
V_51 = F_182 ( V_118 , V_216 ) ;
V_203:
F_44 ( V_216 ) ;
return V_51 ;
}
int F_186 ( struct V_1 * V_2 , int type )
{
int V_51 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_34 ( & V_61 -> V_62 ) ;
V_51 = V_61 -> V_64 [ type ] -> F_55 ( V_2 , type ) ;
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_187 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
int V_55 ;
if ( ! F_77 ( V_2 , V_23 -> type ) )
return - V_114 ;
if ( ! V_61 -> V_64 [ V_23 -> type ] -> V_231 )
return - V_232 ;
F_34 ( & V_61 -> V_62 ) ;
V_55 = V_61 -> V_64 [ V_23 -> type ] -> V_231 ( V_2 , V_23 ) ;
F_35 ( & V_61 -> V_62 ) ;
return V_55 ;
}
int F_188 ( struct V_118 * V_118 , struct V_233 * V_233 )
{
int error ;
error = F_189 ( V_118 , V_233 ) ;
if ( ! error && ( V_233 -> V_234 & V_235 ) )
F_160 ( V_118 ) ;
return error ;
}
int F_190 ( struct V_1 * V_2 , int type , unsigned int V_89 )
{
int V_56 , V_51 = 0 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_118 * V_236 [ V_27 ] ;
if ( F_72 ( F_191 ( & V_2 -> V_81 ) ) )
F_192 ( & V_2 -> V_81 ) ;
if ( ( V_89 & V_237 && ! ( V_89 & V_238 ) )
|| ( V_89 & V_239 && V_89 & ( V_238 |
V_237 ) ) )
return - V_113 ;
if ( ! F_153 ( V_2 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_236 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_193 ( V_2 , V_56 ) )
continue;
if ( V_89 & V_239 ) {
F_5 ( & V_115 ) ;
V_61 -> V_89 |=
F_194 ( V_239 , V_56 ) ;
F_6 ( & V_115 ) ;
} else {
F_5 ( & V_115 ) ;
V_61 -> V_89 &= ~ F_194 ( V_89 , V_56 ) ;
if ( ! F_193 ( V_2 , V_56 ) &&
F_195 ( V_2 , V_56 ) ) {
V_61 -> V_89 &= ~ F_194 (
V_239 , V_56 ) ;
F_6 ( & V_115 ) ;
F_115 ( V_61 -> V_94 [ V_56 ] ) ;
V_61 -> V_94 [ V_56 ] = NULL ;
continue;
}
F_6 ( & V_115 ) ;
}
if ( F_193 ( V_2 , V_56 ) && ! ( V_89 & V_239 ) )
continue;
F_120 ( V_2 , V_56 ) ;
F_63 ( V_2 , V_56 ) ;
if ( F_54 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
if ( V_61 -> V_64 [ V_56 ] -> V_240 )
V_61 -> V_64 [ V_56 ] -> V_240 ( V_2 , V_56 ) ;
F_11 ( V_61 -> V_53 [ V_56 ] . V_181 ) ;
V_236 [ V_56 ] = V_61 -> V_94 [ V_56 ] ;
if ( ! F_193 ( V_2 , V_56 ) )
V_61 -> V_94 [ V_56 ] = NULL ;
V_61 -> V_53 [ V_56 ] . V_58 = 0 ;
V_61 -> V_53 [ V_56 ] . V_189 = 0 ;
V_61 -> V_53 [ V_56 ] . V_194 = 0 ;
V_61 -> V_64 [ V_56 ] = NULL ;
}
if ( V_61 -> V_89 & V_90 )
goto V_241;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_80 ( V_2 -> V_93 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_236 [ V_56 ] && ! F_193 ( V_2 , V_56 ) ) {
F_81 ( V_236 [ V_56 ] ) ;
V_236 [ V_56 ] -> V_242 &= ~ ( V_243 |
V_244 | V_245 ) ;
F_82 ( & V_236 [ V_56 ] -> V_95 , 0 ) ;
F_83 ( V_236 [ V_56 ] ) ;
F_196 ( V_236 [ V_56 ] ) ;
}
if ( V_2 -> V_93 )
F_197 ( V_2 -> V_93 ) ;
V_241:
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_236 [ V_56 ] ) {
if ( ! ( V_89 & V_239 ) )
F_115 ( V_236 [ V_56 ] ) ;
else if ( ! V_236 [ V_56 ] -> V_246 )
V_51 = - V_247 ;
}
return V_51 ;
}
int F_198 ( struct V_1 * V_2 , int type )
{
return F_190 ( V_2 , type ,
V_237 | V_238 ) ;
}
static int F_199 ( struct V_118 * V_118 , int type , int V_248 ,
unsigned int V_89 )
{
struct V_10 * V_4 = F_8 ( V_248 ) ;
struct V_1 * V_2 = V_118 -> V_119 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int error ;
int V_249 = - 1 ;
if ( ! V_4 )
return - V_114 ;
if ( ! F_200 ( V_118 -> V_250 ) ) {
error = - V_251 ;
goto V_252;
}
if ( F_201 ( V_118 ) ) {
error = - V_253 ;
goto V_252;
}
if ( ! V_2 -> V_91 -> V_254 || ! V_2 -> V_91 -> V_255 ||
( type == V_164 && V_2 -> V_49 -> V_202 == NULL ) ) {
error = - V_113 ;
goto V_252;
}
if ( V_2 -> V_112 != & V_24 ) {
error = - V_113 ;
goto V_252;
}
if ( ! ( V_89 & V_237 ) ) {
error = - V_113 ;
goto V_252;
}
if ( F_193 ( V_2 , type ) ) {
error = - V_247 ;
goto V_252;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_202 ( V_2 ) ;
F_197 ( V_2 -> V_93 ) ;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_81 ( V_118 ) ;
V_249 = V_118 -> V_242 & ( V_244 | V_243 |
V_245 ) ;
V_118 -> V_242 |= V_245 | V_244 | V_243 ;
F_83 ( V_118 ) ;
F_161 ( V_118 ) ;
}
error = - V_69 ;
V_61 -> V_94 [ type ] = F_203 ( V_118 ) ;
if ( ! V_61 -> V_94 [ type ] )
goto V_256;
error = - V_113 ;
if ( ! V_4 -> V_257 -> V_258 ( V_2 , type ) )
goto V_259;
V_61 -> V_64 [ type ] = V_4 -> V_257 ;
V_61 -> V_53 [ type ] . V_181 = V_4 ;
V_61 -> V_53 [ type ] . V_260 = V_248 ;
F_99 ( & V_61 -> V_53 [ type ] . V_54 ) ;
F_34 ( & V_61 -> V_62 ) ;
error = V_61 -> V_64 [ type ] -> F_204 ( V_2 , type ) ;
if ( error < 0 ) {
F_35 ( & V_61 -> V_62 ) ;
goto V_259;
}
if ( V_61 -> V_89 & V_90 )
V_61 -> V_53 [ type ] . V_58 |= V_261 ;
F_35 ( & V_61 -> V_62 ) ;
F_5 ( & V_115 ) ;
V_61 -> V_89 |= F_194 ( V_89 , type ) ;
F_6 ( & V_115 ) ;
F_111 ( V_2 , type ) ;
return 0 ;
V_259:
V_61 -> V_94 [ type ] = NULL ;
F_115 ( V_118 ) ;
V_256:
if ( V_249 != - 1 ) {
F_81 ( V_118 ) ;
V_118 -> V_242 &= ~ ( V_244 | V_245 | V_243 ) ;
V_118 -> V_242 |= V_249 ;
F_83 ( V_118 ) ;
}
V_252:
F_11 ( V_4 ) ;
return error ;
}
int F_205 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_118 * V_118 ;
int V_51 = 0 , V_56 ;
unsigned int V_89 ;
if ( F_72 ( F_191 ( & V_2 -> V_81 ) ) )
F_192 ( & V_2 -> V_81 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_195 ( V_2 , V_56 ) )
continue;
V_118 = V_61 -> V_94 [ V_56 ] ;
V_61 -> V_94 [ V_56 ] = NULL ;
F_5 ( & V_115 ) ;
V_89 = V_61 -> V_89 & F_194 ( V_237 |
V_238 ,
V_56 ) ;
V_61 -> V_89 &= ~ F_194 ( V_262 , V_56 ) ;
F_6 ( & V_115 ) ;
V_89 = F_206 ( V_89 , V_56 ) ;
V_51 = F_199 ( V_118 , V_56 ,
V_61 -> V_53 [ V_56 ] . V_260 , V_89 ) ;
F_115 ( V_118 ) ;
}
return V_51 ;
}
int F_207 ( struct V_1 * V_2 , int type , int V_248 ,
const struct V_263 * V_263 )
{
int error = F_208 ( V_263 -> V_264 ) ;
if ( error )
return error ;
if ( V_263 -> V_264 -> V_265 != V_2 )
error = - V_266 ;
else
error = F_199 ( F_209 ( V_263 -> V_264 ) , type ,
V_248 , V_237 |
V_238 ) ;
return error ;
}
int F_210 ( struct V_118 * V_118 , int type , int V_248 ,
unsigned int V_89 )
{
struct V_1 * V_2 = V_118 -> V_119 ;
F_94 ( V_89 & V_239 ) ;
if ( F_72 ( F_191 ( & V_2 -> V_81 ) ) )
F_192 ( & V_2 -> V_81 ) ;
if ( ! V_89 )
return 0 ;
if ( F_193 ( V_2 , type ) ) {
if ( V_89 & V_237 &&
F_211 ( V_2 , type ) )
return - V_247 ;
if ( V_89 & V_238 &&
F_147 ( V_2 , type ) )
return - V_247 ;
F_5 ( & V_115 ) ;
F_42 ( V_2 ) -> V_89 |= F_194 ( V_89 , type ) ;
F_6 ( & V_115 ) ;
return 0 ;
}
return F_199 ( V_118 , type , V_248 , V_89 ) ;
}
int F_212 ( struct V_1 * V_2 , char * V_267 ,
int V_248 , int type )
{
struct V_264 * V_264 ;
int error ;
V_264 = F_213 ( V_267 , V_2 -> V_268 , strlen ( V_267 ) ) ;
if ( F_158 ( V_264 ) )
return F_159 ( V_264 ) ;
if ( F_214 ( V_264 ) ) {
error = - V_269 ;
goto V_83;
}
error = F_208 ( V_264 ) ;
if ( ! error )
error = F_199 ( F_209 ( V_264 ) , type , V_248 ,
V_237 | V_238 ) ;
V_83:
F_215 ( V_264 ) ;
return error ;
}
static int F_216 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_232 ;
V_89 &= ~ ( V_270 | V_271 | V_272 ) ;
if ( ! V_89 )
return - V_113 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! ( V_89 & F_217 ( type ) ) )
continue;
if ( ! F_211 ( V_2 , type ) )
return - V_113 ;
V_51 = F_210 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_260 ,
V_238 ) ;
if ( V_51 < 0 )
goto V_273;
}
return 0 ;
V_273:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_217 ( type ) )
F_190 ( V_2 , type , V_238 ) ;
}
if ( V_51 == - V_247 )
V_51 = - V_274 ;
return V_51 ;
}
static int F_218 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_232 ;
if ( V_89 &
( V_270 | V_271 | V_272 ) )
return - V_275 ;
for ( type = 0 ; type < V_27 ; type ++ )
if ( ! F_147 ( V_2 , type ) )
V_89 &= ~ F_217 ( type ) ;
if ( ! V_89 )
return - V_274 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( V_89 & F_217 ( type ) ) {
V_51 = F_190 ( V_2 , type , V_238 ) ;
if ( V_51 < 0 )
goto V_273;
}
}
return 0 ;
V_273:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_217 ( type ) )
F_210 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_260 ,
V_238 ) ;
}
return V_51 ;
}
static void F_219 ( struct V_30 * V_30 , struct V_276 * V_277 )
{
struct V_278 * V_279 = & V_30 -> V_138 ;
memset ( V_277 , 0 , sizeof( * V_277 ) ) ;
F_5 ( & V_134 ) ;
V_277 -> V_280 = V_279 -> V_193 ;
V_277 -> V_281 = V_279 -> V_147 ;
V_277 -> V_282 = V_279 -> V_187 ;
V_277 -> V_283 = V_279 -> V_143 ;
V_277 -> V_284 = V_279 -> V_140 + V_279 -> V_141 ;
V_277 -> V_285 = V_279 -> V_139 ;
V_277 -> V_286 = V_279 -> V_148 ;
V_277 -> V_287 = V_279 -> V_144 ;
F_6 ( & V_134 ) ;
}
int F_220 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_276 * V_277 )
{
struct V_30 * V_30 ;
V_30 = F_104 ( V_2 , V_23 ) ;
if ( F_158 ( V_30 ) )
return F_159 ( V_30 ) ;
F_219 ( V_30 , V_277 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
int F_221 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_276 * V_277 )
{
struct V_30 * V_30 ;
int V_55 ;
if ( ! V_2 -> V_49 -> V_231 )
return - V_232 ;
V_55 = V_2 -> V_49 -> V_231 ( V_2 , V_23 ) ;
if ( V_55 < 0 )
return V_55 ;
V_30 = F_104 ( V_2 , * V_23 ) ;
if ( F_158 ( V_30 ) )
return F_159 ( V_30 ) ;
F_219 ( V_30 , V_277 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_222 ( struct V_30 * V_30 , struct V_276 * V_277 )
{
struct V_278 * V_279 = & V_30 -> V_138 ;
int V_288 = 0 , V_289 = 0 ;
struct V_179 * V_290 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
if ( V_277 -> V_291 & ~ V_292 )
return - V_113 ;
if ( ( ( V_277 -> V_291 & V_293 ) &&
V_277 -> V_281 > V_290 -> V_294 ) ||
( ( V_277 -> V_291 & V_295 ) &&
V_277 -> V_280 > V_290 -> V_294 ) ||
( ( V_277 -> V_291 & V_296 ) &&
( V_277 -> V_283 > V_290 -> V_297 ) ) ||
( ( V_277 -> V_291 & V_298 ) &&
( V_277 -> V_282 > V_290 -> V_297 ) ) )
return - V_299 ;
F_5 ( & V_134 ) ;
if ( V_277 -> V_291 & V_300 ) {
V_279 -> V_140 = V_277 -> V_284 - V_279 -> V_141 ;
V_288 = 1 ;
F_49 ( V_301 + V_302 , & V_30 -> V_48 ) ;
}
if ( V_277 -> V_291 & V_293 )
V_279 -> V_147 = V_277 -> V_281 ;
if ( V_277 -> V_291 & V_295 )
V_279 -> V_193 = V_277 -> V_280 ;
if ( V_277 -> V_291 & ( V_293 | V_295 ) ) {
V_288 = 1 ;
F_49 ( V_301 + V_303 , & V_30 -> V_48 ) ;
}
if ( V_277 -> V_291 & V_304 ) {
V_279 -> V_139 = V_277 -> V_285 ;
V_289 = 1 ;
F_49 ( V_301 + V_305 , & V_30 -> V_48 ) ;
}
if ( V_277 -> V_291 & V_296 )
V_279 -> V_143 = V_277 -> V_283 ;
if ( V_277 -> V_291 & V_298 )
V_279 -> V_187 = V_277 -> V_282 ;
if ( V_277 -> V_291 & ( V_296 | V_298 ) ) {
V_289 = 1 ;
F_49 ( V_301 + V_306 , & V_30 -> V_48 ) ;
}
if ( V_277 -> V_291 & V_307 ) {
V_279 -> V_148 = V_277 -> V_286 ;
V_288 = 1 ;
F_49 ( V_301 + V_308 , & V_30 -> V_48 ) ;
}
if ( V_277 -> V_291 & V_309 ) {
V_279 -> V_144 = V_277 -> V_287 ;
V_289 = 1 ;
F_49 ( V_301 + V_310 , & V_30 -> V_48 ) ;
}
if ( V_288 ) {
if ( ! V_279 -> V_147 ||
V_279 -> V_140 < V_279 -> V_147 ) {
V_279 -> V_148 = 0 ;
F_59 ( V_149 , & V_30 -> V_48 ) ;
} else if ( ! ( V_277 -> V_291 & V_307 ) )
V_279 -> V_148 = F_148 () + V_290 -> V_194 ;
}
if ( V_289 ) {
if ( ! V_279 -> V_143 ||
V_279 -> V_139 < V_279 -> V_143 ) {
V_279 -> V_144 = 0 ;
F_59 ( V_146 , & V_30 -> V_48 ) ;
} else if ( ! ( V_277 -> V_291 & V_309 ) )
V_279 -> V_144 = F_148 () + V_290 -> V_189 ;
}
if ( V_279 -> V_193 || V_279 -> V_147 || V_279 -> V_187 ||
V_279 -> V_143 )
F_59 ( V_186 , & V_30 -> V_48 ) ;
else
F_49 ( V_186 , & V_30 -> V_48 ) ;
F_6 ( & V_134 ) ;
F_38 ( V_30 ) ;
return 0 ;
}
int F_223 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_276 * V_277 )
{
struct V_30 * V_30 ;
int V_199 ;
V_30 = F_104 ( V_2 , V_23 ) ;
if ( F_158 ( V_30 ) ) {
V_199 = F_159 ( V_30 ) ;
goto V_83;
}
V_199 = F_222 ( V_30 , V_277 ) ;
F_45 ( V_30 ) ;
V_83:
return V_199 ;
}
int F_224 ( struct V_1 * V_2 , struct V_311 * V_312 )
{
struct V_179 * V_313 ;
struct V_314 * V_315 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int type ;
memset ( V_312 , 0 , sizeof( * V_312 ) ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! F_77 ( V_2 , type ) )
continue;
V_315 = V_312 -> V_316 + type ;
V_313 = F_42 ( V_2 ) -> V_53 + type ;
V_315 -> V_89 = V_317 ;
F_5 ( & V_134 ) ;
if ( V_313 -> V_58 & V_261 )
V_315 -> V_89 |= V_318 ;
if ( V_313 -> V_58 & V_183 )
V_315 -> V_89 |= V_319 ;
if ( F_147 ( V_2 , type ) )
V_315 -> V_89 |= V_320 ;
V_315 -> V_321 = V_313 -> V_194 ;
V_315 -> V_322 = V_313 -> V_189 ;
V_315 -> V_323 = V_61 -> V_94 [ type ] -> V_324 ;
V_315 -> V_325 = V_61 -> V_94 [ type ] -> V_326 ;
V_315 -> V_327 = 1 ;
F_6 ( & V_134 ) ;
}
return 0 ;
}
int F_225 ( struct V_1 * V_2 , int type , struct V_328 * V_329 )
{
struct V_179 * V_313 ;
int V_55 = 0 ;
if ( ( V_329 -> V_330 & V_331 ) ||
( V_329 -> V_330 & V_332 ) )
return - V_113 ;
if ( ! F_77 ( V_2 , type ) )
return - V_114 ;
V_313 = F_42 ( V_2 ) -> V_53 + type ;
if ( V_329 -> V_330 & V_333 ) {
if ( ( V_329 -> V_242 & V_319 &&
V_313 -> V_181 -> V_16 != V_182 ) )
return - V_113 ;
}
F_5 ( & V_134 ) ;
if ( V_329 -> V_330 & V_307 )
V_313 -> V_194 = V_329 -> V_334 ;
if ( V_329 -> V_330 & V_309 )
V_313 -> V_189 = V_329 -> V_335 ;
if ( V_329 -> V_330 & V_333 ) {
if ( V_329 -> V_242 & V_319 )
V_313 -> V_58 |= V_183 ;
else
V_313 -> V_58 &= ~ V_183 ;
}
F_6 ( & V_134 ) ;
F_48 ( V_2 , type ) ;
V_2 -> V_49 -> V_87 ( V_2 , type ) ;
return V_55 ;
}
static int F_226 ( struct V_336 * V_337 , int V_338 ,
void T_4 * V_339 , T_5 * V_340 , T_6 * V_341 )
{
unsigned int type = ( int * ) V_337 -> V_342 - V_103 . V_343 ;
V_103 . V_343 [ type ] =
F_227 ( & V_103 . V_104 [ type ] ) ;
return F_228 ( V_337 , V_338 , V_339 , V_340 , V_341 ) ;
}
static int T_7 F_229 ( void )
{
int V_176 , V_51 ;
unsigned long V_344 , V_345 ;
F_3 ( V_346 L_19 , V_347 ) ;
F_230 ( V_348 ) ;
V_73 = F_231 ( L_20 ,
sizeof( struct V_30 ) , sizeof( unsigned long ) * 4 ,
( V_349 | V_350 |
V_351 | V_352 ) ,
NULL ) ;
V_345 = 0 ;
V_33 = (struct V_31 * ) F_232 ( V_353 , V_345 ) ;
if ( ! V_33 )
F_233 ( L_21 ) ;
for ( V_176 = 0 ; V_176 < V_354 ; V_176 ++ ) {
V_51 = F_234 ( & V_103 . V_104 [ V_176 ] , 0 , V_355 ) ;
if ( V_51 )
F_233 ( L_22 ) ;
}
V_344 = ( 1UL << V_345 ) * V_356 / sizeof( struct V_31 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( V_344 >> V_28 );
V_28 -- ;
V_344 = 1UL << V_28 ;
V_29 = V_344 - 1 ;
for ( V_176 = 0 ; V_176 < V_344 ; V_176 ++ )
F_235 ( V_33 + V_176 ) ;
F_236 ( L_23
L_24 , V_344 , V_345 , ( V_356 << V_345 ) ) ;
F_237 ( & V_357 ) ;
return 0 ;
}

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
struct V_30 * V_30 = NULL , * V_112 = NULL ;
if ( ! F_74 ( V_2 , V_23 . type ) )
return NULL ;
V_108:
F_5 ( & V_11 ) ;
F_5 ( & V_113 ) ;
if ( ! F_74 ( V_2 , V_23 . type ) ) {
F_6 ( & V_113 ) ;
F_6 ( & V_11 ) ;
goto V_83;
}
F_6 ( & V_113 ) ;
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
F_25 ( V_114 ) ;
F_25 ( V_82 ) ;
}
F_33 ( V_30 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) &&
V_2 -> V_49 -> V_115 ( V_30 ) < 0 ) {
F_45 ( V_30 ) ;
V_30 = NULL ;
goto V_83;
}
#ifdef F_84
F_89 ( ! V_30 -> V_34 ) ;
#endif
V_83:
if ( V_112 )
F_61 ( V_112 ) ;
return V_30 ;
}
static inline struct V_30 * * F_100 ( struct V_116 * V_116 )
{
return V_116 -> V_117 -> V_91 -> V_118 ( V_116 ) ;
}
static int F_101 ( struct V_116 * V_116 , int type )
{
struct V_30 * const * V_119 ;
int V_56 ;
if ( F_102 ( V_116 ) )
return 0 ;
V_119 = F_100 ( V_116 ) ;
if ( type != - 1 )
return ! V_119 [ type ] ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ! V_119 [ V_56 ] )
return 1 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 , int type )
{
struct V_116 * V_116 , * V_120 = NULL ;
#ifdef F_84
int V_121 = 0 ;
#endif
F_5 ( & V_122 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_116 -> V_123 ) ;
if ( ( V_116 -> V_124 & ( V_125 | V_126 | V_127 ) ) ||
! F_57 ( & V_116 -> V_128 ) ||
! F_101 ( V_116 , type ) ) {
F_6 ( & V_116 -> V_123 ) ;
continue;
}
F_104 ( V_116 ) ;
F_6 ( & V_116 -> V_123 ) ;
F_6 ( & V_122 ) ;
#ifdef F_84
if ( F_105 ( F_106 ( V_116 ) > 0 ) )
V_121 = 1 ;
#endif
F_107 ( V_120 ) ;
F_108 ( V_116 , type ) ;
V_120 = V_116 ;
F_5 ( & V_122 ) ;
}
F_6 ( & V_122 ) ;
F_107 ( V_120 ) ;
#ifdef F_84
if ( V_121 ) {
F_85 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static void F_109 ( struct V_116 * V_116 , int type ,
struct V_84 * V_129 )
{
struct V_30 * * V_119 = F_100 ( V_116 ) ;
struct V_30 * V_30 = V_119 [ type ] ;
if ( ! V_30 )
return;
V_119 [ type ] = NULL ;
if ( F_27 ( & V_30 -> V_40 ) ) {
F_5 ( & V_11 ) ;
F_41 ( & V_30 -> V_40 , V_129 ) ;
F_6 ( & V_11 ) ;
} else {
F_45 ( V_30 ) ;
}
}
static void F_110 ( struct V_84 * V_129 )
{
struct V_84 * V_130 ;
struct V_30 * V_30 ;
V_130 = V_129 -> V_131 ;
while ( V_130 != V_129 ) {
V_30 = F_80 ( V_130 , struct V_30 , V_40 ) ;
V_130 = V_130 -> V_131 ;
F_28 ( & V_30 -> V_40 ) ;
F_45 ( V_30 ) ;
}
}
static void F_111 ( struct V_1 * V_2 , int type ,
struct V_84 * V_129 )
{
struct V_116 * V_116 ;
int V_121 = 0 ;
F_5 ( & V_122 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_132 ) ;
if ( ! F_102 ( V_116 ) ) {
if ( F_105 ( F_106 ( V_116 ) > 0 ) )
V_121 = 1 ;
F_109 ( V_116 , type , V_129 ) ;
}
F_6 ( & V_132 ) ;
}
F_6 ( & V_122 ) ;
#ifdef F_84
if ( V_121 ) {
F_3 ( V_133 L_8
L_9
L_10 , V_2 -> V_9 ) ;
}
#endif
}
static void F_112 ( struct V_1 * V_2 , int type )
{
F_113 ( V_129 ) ;
if ( V_2 -> V_49 ) {
F_111 ( V_2 , type , & V_129 ) ;
F_114 ( & V_134 ) ;
F_110 ( & V_129 ) ;
}
}
static inline void F_115 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_137 += V_135 ;
}
static inline void F_116 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_138 += V_135 ;
}
static inline void F_117 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_139 += V_135 ;
}
static void F_118 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( V_30 -> V_136 . V_139 < V_135 ) {
F_119 ( 1 ) ;
V_135 = V_30 -> V_136 . V_139 ;
}
V_30 -> V_136 . V_138 += V_135 ;
V_30 -> V_136 . V_139 -= V_135 ;
}
static void F_120 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( F_119 ( V_30 -> V_136 . V_138 < V_135 ) )
V_135 = V_30 -> V_136 . V_138 ;
V_30 -> V_136 . V_139 += V_135 ;
V_30 -> V_136 . V_138 -= V_135 ;
}
static inline
void F_121 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( V_30 -> V_136 . V_139 >= V_135 )
V_30 -> V_136 . V_139 -= V_135 ;
else {
F_119 ( 1 ) ;
V_30 -> V_136 . V_139 = 0 ;
}
}
static void F_122 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_140 ||
V_30 -> V_136 . V_137 >= V_135 )
V_30 -> V_136 . V_137 -= V_135 ;
else
V_30 -> V_136 . V_137 = 0 ;
if ( V_30 -> V_136 . V_137 <= V_30 -> V_136 . V_141 )
V_30 -> V_136 . V_142 = ( V_143 ) 0 ;
F_58 ( V_144 , & V_30 -> V_48 ) ;
}
static void F_123 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_140 ||
V_30 -> V_136 . V_138 >= V_135 )
V_30 -> V_136 . V_138 -= V_135 ;
else
V_30 -> V_136 . V_138 = 0 ;
if ( V_30 -> V_136 . V_138 <= V_30 -> V_136 . V_145 )
V_30 -> V_136 . V_146 = ( V_143 ) 0 ;
F_58 ( V_147 , & V_30 -> V_48 ) ;
}
static int F_124 ( struct V_30 * V_30 , const int V_148 )
{
int V_149 = ( V_148 == V_150 ||
V_148 == V_151 ) ? V_147 :
( ( V_148 == V_152 ||
V_148 == V_153 ) ? V_144 : 0 ) ;
if ( ! V_149 )
return 0 ;
return F_40 ( V_149 , & V_30 -> V_48 ) ;
}
static int F_125 ( struct V_154 * V_155 )
{
if ( ! V_156 )
return 0 ;
switch ( V_155 -> V_157 . type ) {
case V_158 :
return F_126 ( F_127 () , V_155 -> V_157 . V_159 ) ;
case V_160 :
return F_128 ( V_155 -> V_157 . V_161 ) ;
case V_162 :
return 1 ;
}
return 0 ;
}
static void F_129 ( struct V_154 * V_155 )
{
char * V_163 = NULL ;
struct V_164 * V_165 ;
int V_148 = V_155 -> V_166 ;
if ( V_148 == V_167 ||
V_148 == V_168 ||
V_148 == V_169 ||
V_148 == V_170 || ! F_125 ( V_155 ) )
return;
V_165 = F_130 () ;
if ( ! V_165 )
return;
F_131 ( V_165 , V_155 -> V_171 -> V_9 ) ;
if ( V_148 == V_172 || V_148 == V_173 )
F_131 ( V_165 , L_11 ) ;
else
F_131 ( V_165 , L_12 ) ;
F_131 ( V_165 , V_106 [ V_155 -> V_157 . type ] ) ;
switch ( V_148 ) {
case V_152 :
V_163 = L_13 ;
break;
case V_153 :
V_163 = L_14 ;
break;
case V_172 :
V_163 = L_15 ;
break;
case V_150 :
V_163 = L_16 ;
break;
case V_151 :
V_163 = L_17 ;
break;
case V_173 :
V_163 = L_18 ;
break;
}
F_131 ( V_165 , V_163 ) ;
F_132 ( V_165 ) ;
}
static void F_133 ( struct V_154 * V_155 , struct V_30 * V_30 ,
int V_148 )
{
if ( F_124 ( V_30 , V_148 ) )
return;
V_155 -> V_166 = V_148 ;
V_155 -> V_171 = V_30 -> V_34 ;
V_155 -> V_157 = V_30 -> V_35 ;
}
static void F_134 ( struct V_154 * V_155 )
{
int V_174 ;
for ( V_174 = 0 ; V_174 < V_27 ; V_174 ++ ) {
if ( V_155 [ V_174 ] . V_166 == V_175 )
continue;
#ifdef F_135
F_129 ( & V_155 [ V_174 ] ) ;
#endif
F_136 ( V_155 [ V_174 ] . V_157 ,
V_155 [ V_174 ] . V_171 -> V_176 , V_155 [ V_174 ] . V_166 ) ;
}
}
static int F_137 ( struct V_30 * V_30 )
{
struct V_177 * V_53 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
return F_138 ( V_178 ) &&
( V_53 -> V_179 -> V_16 != V_180 ||
! ( V_53 -> V_58 & V_181 ) ) ;
}
static int F_139 ( struct V_30 * V_30 , T_2 V_182 ,
struct V_154 * V_155 )
{
T_2 V_183 = V_30 -> V_136 . V_137 + V_182 ;
if ( ! F_140 ( V_30 -> V_34 , V_30 -> V_35 . type ) ||
F_37 ( V_184 , & V_30 -> V_48 ) )
return 0 ;
if ( V_30 -> V_136 . V_185 &&
V_183 > V_30 -> V_136 . V_185 &&
! F_137 ( V_30 ) ) {
F_133 ( V_155 , V_30 , V_152 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_141 &&
V_183 > V_30 -> V_136 . V_141 &&
V_30 -> V_136 . V_142 &&
F_141 () >= V_30 -> V_136 . V_142 &&
! F_137 ( V_30 ) ) {
F_133 ( V_155 , V_30 , V_153 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_141 &&
V_183 > V_30 -> V_136 . V_141 &&
V_30 -> V_136 . V_142 == 0 ) {
F_133 ( V_155 , V_30 , V_172 ) ;
V_30 -> V_136 . V_142 = F_141 () +
F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] . V_187 ;
}
return 0 ;
}
static int F_142 ( struct V_30 * V_30 , T_2 V_188 , int V_189 ,
struct V_154 * V_155 )
{
T_2 V_190 ;
struct V_1 * V_2 = V_30 -> V_34 ;
if ( ! F_140 ( V_2 , V_30 -> V_35 . type ) ||
F_37 ( V_184 , & V_30 -> V_48 ) )
return 0 ;
V_190 = V_30 -> V_136 . V_138 + V_30 -> V_136 . V_139
+ V_188 ;
if ( V_30 -> V_136 . V_191 &&
V_190 > V_30 -> V_136 . V_191 &&
! F_137 ( V_30 ) ) {
if ( ! V_189 )
F_133 ( V_155 , V_30 , V_150 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_145 &&
V_190 > V_30 -> V_136 . V_145 &&
V_30 -> V_136 . V_146 &&
F_141 () >= V_30 -> V_136 . V_146 &&
! F_137 ( V_30 ) ) {
if ( ! V_189 )
F_133 ( V_155 , V_30 , V_151 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_145 &&
V_190 > V_30 -> V_136 . V_145 &&
V_30 -> V_136 . V_146 == 0 ) {
if ( ! V_189 ) {
F_133 ( V_155 , V_30 , V_173 ) ;
V_30 -> V_136 . V_146 = F_141 () +
F_42 ( V_2 ) -> V_53 [ V_30 -> V_35 . type ] . V_192 ;
}
else
return - V_186 ;
}
return 0 ;
}
static int F_143 ( struct V_30 * V_30 , T_2 V_182 )
{
T_2 V_183 ;
if ( F_37 ( V_184 , & V_30 -> V_48 ) ||
V_30 -> V_136 . V_137 <= V_30 -> V_136 . V_141 ||
! F_140 ( V_30 -> V_34 , V_30 -> V_35 . type ) )
return V_175 ;
V_183 = V_30 -> V_136 . V_137 - V_182 ;
if ( V_183 <= V_30 -> V_136 . V_141 )
return V_168 ;
if ( V_30 -> V_136 . V_137 >= V_30 -> V_136 . V_185 &&
V_183 < V_30 -> V_136 . V_185 )
return V_167 ;
return V_175 ;
}
static int F_144 ( struct V_30 * V_30 , T_2 V_188 )
{
if ( F_37 ( V_184 , & V_30 -> V_48 ) ||
V_30 -> V_136 . V_138 <= V_30 -> V_136 . V_145 )
return V_175 ;
if ( V_30 -> V_136 . V_138 - V_188 <= V_30 -> V_136 . V_145 )
return V_170 ;
if ( V_30 -> V_136 . V_138 >= V_30 -> V_136 . V_191 &&
V_30 -> V_136 . V_138 - V_188 < V_30 -> V_136 . V_191 )
return V_169 ;
return V_175 ;
}
static int F_145 ( const struct V_116 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_117 ;
if ( F_102 ( V_116 ) )
return 0 ;
return F_146 ( V_2 ) & ~ F_147 ( V_2 ) ;
}
static void F_108 ( struct V_116 * V_116 , int type )
{
int V_56 , V_193 = 0 ;
struct V_30 * * V_119 , * V_194 [ V_27 ] ;
struct V_1 * V_2 = V_116 -> V_117 ;
T_2 V_195 ;
if ( ! F_145 ( V_116 ) )
return;
V_119 = F_100 ( V_116 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
struct V_22 V_23 ;
T_3 V_196 ;
int V_197 ;
V_194 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( V_119 [ V_56 ] )
continue;
if ( ! F_74 ( V_2 , V_56 ) )
continue;
V_193 = 1 ;
switch ( V_56 ) {
case V_158 :
V_23 = F_148 ( V_116 -> V_198 ) ;
break;
case V_160 :
V_23 = F_149 ( V_116 -> V_199 ) ;
break;
case V_162 :
V_197 = V_116 -> V_117 -> V_49 -> V_200 ( V_116 , & V_196 ) ;
if ( V_197 )
continue;
V_23 = F_150 ( V_196 ) ;
break;
}
V_194 [ V_56 ] = F_99 ( V_2 , V_23 ) ;
}
if ( ! V_193 )
return;
F_5 ( & V_132 ) ;
if ( F_102 ( V_116 ) )
goto V_201;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_74 ( V_2 , V_56 ) )
continue;
if ( ! V_194 [ V_56 ] )
continue;
if ( ! V_119 [ V_56 ] ) {
V_119 [ V_56 ] = V_194 [ V_56 ] ;
V_194 [ V_56 ] = NULL ;
V_195 = F_106 ( V_116 ) ;
if ( F_105 ( V_195 ) )
F_117 ( V_119 [ V_56 ] , V_195 ) ;
}
}
V_201:
F_6 ( & V_132 ) ;
F_44 ( V_194 ) ;
}
void F_151 ( struct V_116 * V_116 )
{
F_108 ( V_116 , - 1 ) ;
}
static void F_152 ( struct V_116 * V_116 )
{
int V_56 ;
struct V_30 * * V_119 = F_100 ( V_116 ) ;
struct V_30 * V_202 [ V_27 ] ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_202 [ V_56 ] = V_119 [ V_56 ] ;
V_119 [ V_56 ] = NULL ;
}
F_6 ( & V_132 ) ;
F_44 ( V_202 ) ;
}
void F_153 ( struct V_116 * V_116 )
{
struct V_30 * const * V_119 ;
int V_56 ;
if ( F_102 ( V_116 ) )
return;
V_119 = F_100 ( V_116 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_119 [ V_56 ] )
break;
}
if ( V_56 < V_27 )
F_152 ( V_116 ) ;
}
static T_2 * F_154 ( struct V_116 * V_116 )
{
F_89 ( ! V_116 -> V_117 -> V_49 -> V_203 ) ;
return V_116 -> V_117 -> V_49 -> V_203 ( V_116 ) ;
}
void F_155 ( struct V_116 * V_116 , T_2 V_135 )
{
F_5 ( & V_116 -> V_123 ) ;
* F_154 ( V_116 ) += V_135 ;
F_6 ( & V_116 -> V_123 ) ;
}
void F_156 ( struct V_116 * V_116 , T_2 V_135 )
{
F_5 ( & V_116 -> V_123 ) ;
* F_154 ( V_116 ) -= V_135 ;
F_157 ( V_116 , V_135 ) ;
F_6 ( & V_116 -> V_123 ) ;
}
void F_158 ( struct V_116 * V_116 , T_2 V_135 )
{
F_5 ( & V_116 -> V_123 ) ;
* F_154 ( V_116 ) += V_135 ;
F_159 ( V_116 , V_135 ) ;
F_6 ( & V_116 -> V_123 ) ;
}
void F_160 ( struct V_116 * V_116 , T_2 V_135 )
{
F_5 ( & V_116 -> V_123 ) ;
* F_154 ( V_116 ) -= V_135 ;
F_6 ( & V_116 -> V_123 ) ;
}
static T_2 F_106 ( struct V_116 * V_116 )
{
T_2 V_51 ;
if ( ! V_116 -> V_117 -> V_49 -> V_203 )
return 0 ;
F_5 ( & V_116 -> V_123 ) ;
V_51 = * F_154 ( V_116 ) ;
F_6 ( & V_116 -> V_123 ) ;
return V_51 ;
}
static void F_161 ( struct V_116 * V_116 , T_2 V_135 ,
int V_204 )
{
if ( V_204 )
F_155 ( V_116 , V_135 ) ;
else
F_162 ( V_116 , V_135 ) ;
}
static void F_163 ( struct V_116 * V_116 , T_2 V_135 , int V_204 )
{
if ( V_204 )
F_160 ( V_116 , V_135 ) ;
else
F_164 ( V_116 , V_135 ) ;
}
int F_165 ( struct V_116 * V_116 , T_2 V_135 , int V_89 )
{
int V_56 , V_51 = 0 , V_205 ;
struct V_154 V_155 [ V_27 ] ;
int V_204 = V_89 & V_206 ;
struct V_30 * * V_119 ;
if ( ! F_145 ( V_116 ) ) {
F_161 ( V_116 , V_135 , V_204 ) ;
goto V_83;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_155 [ V_56 ] . V_166 = V_175 ;
V_119 = F_100 ( V_116 ) ;
V_205 = F_166 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_119 [ V_56 ] )
continue;
V_51 = F_142 ( V_119 [ V_56 ] , V_135 ,
! ( V_89 & V_207 ) , & V_155 [ V_56 ] ) ;
if ( V_51 && ! ( V_89 & V_208 ) ) {
F_6 ( & V_132 ) ;
goto V_209;
}
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_119 [ V_56 ] )
continue;
if ( V_204 )
F_117 ( V_119 [ V_56 ] , V_135 ) ;
else
F_116 ( V_119 [ V_56 ] , V_135 ) ;
}
F_161 ( V_116 , V_135 , V_204 ) ;
F_6 ( & V_132 ) ;
if ( V_204 )
goto V_209;
F_43 ( V_119 ) ;
V_209:
F_167 ( & V_134 , V_205 ) ;
F_134 ( V_155 ) ;
V_83:
return V_51 ;
}
int F_168 ( struct V_116 * V_116 )
{
int V_56 , V_51 = 0 , V_205 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * const * V_119 ;
if ( ! F_145 ( V_116 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_155 [ V_56 ] . V_166 = V_175 ;
V_119 = F_100 ( V_116 ) ;
V_205 = F_166 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_119 [ V_56 ] )
continue;
V_51 = F_139 ( V_119 [ V_56 ] , 1 , & V_155 [ V_56 ] ) ;
if ( V_51 )
goto V_210;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_119 [ V_56 ] )
continue;
F_115 ( V_119 [ V_56 ] , 1 ) ;
}
V_210:
F_6 ( & V_132 ) ;
if ( V_51 == 0 )
F_43 ( V_119 ) ;
F_167 ( & V_134 , V_205 ) ;
F_134 ( V_155 ) ;
return V_51 ;
}
int F_169 ( struct V_116 * V_116 , T_2 V_135 )
{
struct V_30 * * V_119 ;
int V_56 , V_205 ;
if ( ! F_145 ( V_116 ) ) {
F_156 ( V_116 , V_135 ) ;
return 0 ;
}
V_119 = F_100 ( V_116 ) ;
V_205 = F_166 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_119 [ V_56 ] )
F_118 ( V_119 [ V_56 ] , V_135 ) ;
}
F_156 ( V_116 , V_135 ) ;
F_6 ( & V_132 ) ;
F_43 ( V_119 ) ;
F_167 ( & V_134 , V_205 ) ;
return 0 ;
}
void F_170 ( struct V_116 * V_116 , T_2 V_135 )
{
struct V_30 * * V_119 ;
int V_56 , V_205 ;
if ( ! F_145 ( V_116 ) ) {
F_158 ( V_116 , V_135 ) ;
return;
}
V_119 = F_100 ( V_116 ) ;
V_205 = F_166 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_119 [ V_56 ] )
F_120 ( V_119 [ V_56 ] , V_135 ) ;
}
F_158 ( V_116 , V_135 ) ;
F_6 ( & V_132 ) ;
F_43 ( V_119 ) ;
F_167 ( & V_134 , V_205 ) ;
return;
}
void F_171 ( struct V_116 * V_116 , T_2 V_135 , int V_89 )
{
unsigned int V_56 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * * V_119 ;
int V_204 = V_89 & V_206 , V_205 ;
if ( ! F_145 ( V_116 ) ) {
F_163 ( V_116 , V_135 , V_204 ) ;
return;
}
V_119 = F_100 ( V_116 ) ;
V_205 = F_166 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_211 ;
V_155 [ V_56 ] . V_166 = V_175 ;
if ( ! V_119 [ V_56 ] )
continue;
V_211 = F_144 ( V_119 [ V_56 ] , V_135 ) ;
if ( V_211 != V_175 )
F_133 ( & V_155 [ V_56 ] , V_119 [ V_56 ] , V_211 ) ;
if ( V_204 )
F_121 ( V_119 [ V_56 ] , V_135 ) ;
else
F_123 ( V_119 [ V_56 ] , V_135 ) ;
}
F_163 ( V_116 , V_135 , V_204 ) ;
F_6 ( & V_132 ) ;
if ( V_204 )
goto V_212;
F_43 ( V_119 ) ;
V_212:
F_167 ( & V_134 , V_205 ) ;
F_134 ( V_155 ) ;
}
void F_172 ( struct V_116 * V_116 )
{
unsigned int V_56 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * const * V_119 ;
int V_205 ;
if ( ! F_145 ( V_116 ) )
return;
V_119 = F_100 ( V_116 ) ;
V_205 = F_166 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_211 ;
V_155 [ V_56 ] . V_166 = V_175 ;
if ( ! V_119 [ V_56 ] )
continue;
V_211 = F_143 ( V_119 [ V_56 ] , 1 ) ;
if ( V_211 != V_175 )
F_133 ( & V_155 [ V_56 ] , V_119 [ V_56 ] , V_211 ) ;
F_122 ( V_119 [ V_56 ] , 1 ) ;
}
F_6 ( & V_132 ) ;
F_43 ( V_119 ) ;
F_167 ( & V_134 , V_205 ) ;
F_134 ( V_155 ) ;
}
int F_173 ( struct V_116 * V_116 , struct V_30 * * V_213 )
{
T_2 V_188 , V_214 ;
T_2 V_215 = 0 ;
struct V_30 * V_216 [ V_27 ] = {} ;
int V_56 , V_51 = 0 ;
char V_217 [ V_27 ] = {} ;
struct V_154 V_218 [ V_27 ] ;
struct V_154 V_219 [ V_27 ] ;
struct V_154 V_220 [ V_27 ] ;
if ( F_102 ( V_116 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_218 [ V_56 ] . V_166 = V_175 ;
V_219 [ V_56 ] . V_166 = V_175 ;
V_220 [ V_56 ] . V_166 = V_175 ;
}
F_5 ( & V_132 ) ;
if ( F_102 ( V_116 ) ) {
F_6 ( & V_132 ) ;
return 0 ;
}
V_214 = F_174 ( V_116 ) ;
V_215 = F_106 ( V_116 ) ;
V_188 = V_214 + V_215 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_213 [ V_56 ] )
continue;
if ( ! F_74 ( V_116 -> V_117 , V_56 ) )
continue;
V_217 [ V_56 ] = 1 ;
V_216 [ V_56 ] = F_100 ( V_116 ) [ V_56 ] ;
V_51 = F_139 ( V_213 [ V_56 ] , 1 , & V_218 [ V_56 ] ) ;
if ( V_51 )
goto V_221;
V_51 = F_142 ( V_213 [ V_56 ] , V_188 , 0 , & V_218 [ V_56 ] ) ;
if ( V_51 )
goto V_221;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_217 [ V_56 ] )
continue;
if ( V_216 [ V_56 ] ) {
int V_211 ;
V_211 = F_143 ( V_216 [ V_56 ] , 1 ) ;
if ( V_211 != V_175 )
F_133 ( & V_219 [ V_56 ] ,
V_216 [ V_56 ] , V_211 ) ;
V_211 = F_144 ( V_216 [ V_56 ] , V_188 ) ;
if ( V_211 != V_175 )
F_133 ( & V_220 [ V_56 ] ,
V_216 [ V_56 ] , V_211 ) ;
F_122 ( V_216 [ V_56 ] , 1 ) ;
F_123 ( V_216 [ V_56 ] , V_214 ) ;
F_121 ( V_216 [ V_56 ] ,
V_215 ) ;
}
F_115 ( V_213 [ V_56 ] , 1 ) ;
F_116 ( V_213 [ V_56 ] , V_214 ) ;
F_117 ( V_213 [ V_56 ] , V_215 ) ;
F_100 ( V_116 ) [ V_56 ] = V_213 [ V_56 ] ;
}
F_6 ( & V_132 ) ;
F_43 ( V_216 ) ;
F_43 ( V_213 ) ;
F_134 ( V_218 ) ;
F_134 ( V_219 ) ;
F_134 ( V_220 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_217 [ V_56 ] )
V_213 [ V_56 ] = V_216 [ V_56 ] ;
return 0 ;
V_221:
F_6 ( & V_132 ) ;
F_134 ( V_218 ) ;
return V_51 ;
}
int F_175 ( struct V_116 * V_116 , struct V_222 * V_222 )
{
struct V_30 * V_213 [ V_27 ] = {} ;
struct V_1 * V_2 = V_116 -> V_117 ;
int V_51 ;
if ( ! F_145 ( V_116 ) )
return 0 ;
if ( V_222 -> V_223 & V_224 && ! F_126 ( V_222 -> V_225 , V_116 -> V_198 ) )
V_213 [ V_158 ] = F_99 ( V_2 , F_148 ( V_222 -> V_225 ) ) ;
if ( V_222 -> V_223 & V_226 && ! F_176 ( V_222 -> V_227 , V_116 -> V_199 ) )
V_213 [ V_160 ] = F_99 ( V_2 , F_149 ( V_222 -> V_227 ) ) ;
V_51 = F_173 ( V_116 , V_213 ) ;
F_44 ( V_213 ) ;
return V_51 ;
}
int F_177 ( struct V_1 * V_2 , int type )
{
int V_51 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_34 ( & V_61 -> V_62 ) ;
V_51 = V_61 -> V_64 [ type ] -> F_54 ( V_2 , type ) ;
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_178 ( struct V_116 * V_116 , struct V_228 * V_228 )
{
int error ;
error = F_179 ( V_116 , V_228 ) ;
if ( ! error && ( V_228 -> V_229 & V_230 ) )
F_151 ( V_116 ) ;
return error ;
}
int F_180 ( struct V_1 * V_2 , int type , unsigned int V_89 )
{
int V_56 , V_51 = 0 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_116 * V_231 [ V_27 ] ;
if ( ( V_89 & V_232 && ! ( V_89 & V_233 ) )
|| ( V_89 & V_234 && V_89 & ( V_233 |
V_232 ) ) )
return - V_235 ;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_146 ( V_2 ) ) {
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_231 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_181 ( V_2 , V_56 ) )
continue;
if ( V_89 & V_234 ) {
F_5 ( & V_113 ) ;
V_61 -> V_89 |=
F_182 ( V_234 , V_56 ) ;
F_6 ( & V_113 ) ;
} else {
F_5 ( & V_113 ) ;
V_61 -> V_89 &= ~ F_182 ( V_89 , V_56 ) ;
if ( ! F_181 ( V_2 , V_56 ) &&
F_183 ( V_2 , V_56 ) ) {
V_61 -> V_89 &= ~ F_182 (
V_234 , V_56 ) ;
F_6 ( & V_113 ) ;
F_107 ( V_61 -> V_94 [ V_56 ] ) ;
V_61 -> V_94 [ V_56 ] = NULL ;
continue;
}
F_6 ( & V_113 ) ;
}
if ( F_181 ( V_2 , V_56 ) && ! ( V_89 & V_234 ) )
continue;
F_112 ( V_2 , V_56 ) ;
F_62 ( V_2 , V_56 ) ;
if ( F_53 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
if ( V_61 -> V_64 [ V_56 ] -> V_236 )
V_61 -> V_64 [ V_56 ] -> V_236 ( V_2 , V_56 ) ;
F_11 ( V_61 -> V_53 [ V_56 ] . V_179 ) ;
V_231 [ V_56 ] = V_61 -> V_94 [ V_56 ] ;
if ( ! F_181 ( V_2 , V_56 ) )
V_61 -> V_94 [ V_56 ] = NULL ;
V_61 -> V_53 [ V_56 ] . V_58 = 0 ;
V_61 -> V_53 [ V_56 ] . V_187 = 0 ;
V_61 -> V_53 [ V_56 ] . V_192 = 0 ;
V_61 -> V_64 [ V_56 ] = NULL ;
}
F_35 ( & V_61 -> V_81 ) ;
if ( V_61 -> V_89 & V_90 )
goto V_237;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_77 ( V_2 -> V_93 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_231 [ V_56 ] ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_181 ( V_2 , V_56 ) ) {
F_34 ( & V_231 [ V_56 ] -> V_95 ) ;
V_231 [ V_56 ] -> V_238 &= ~ ( V_239 |
V_240 | V_241 ) ;
F_78 ( & V_231 [ V_56 ] -> V_96 ,
0 ) ;
F_35 ( & V_231 [ V_56 ] -> V_95 ) ;
F_184 ( V_231 [ V_56 ] ) ;
}
F_35 ( & V_61 -> V_81 ) ;
}
if ( V_2 -> V_93 )
F_185 ( V_2 -> V_93 ) ;
V_237:
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_231 [ V_56 ] ) {
if ( ! ( V_89 & V_234 ) )
F_107 ( V_231 [ V_56 ] ) ;
else if ( ! V_231 [ V_56 ] -> V_242 )
V_51 = - V_243 ;
}
return V_51 ;
}
int F_186 ( struct V_1 * V_2 , int type )
{
return F_180 ( V_2 , type ,
V_232 | V_233 ) ;
}
static int F_187 ( struct V_116 * V_116 , int type , int V_244 ,
unsigned int V_89 )
{
struct V_10 * V_4 = F_8 ( V_244 ) ;
struct V_1 * V_2 = V_116 -> V_117 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int error ;
int V_245 = - 1 ;
if ( ! V_4 )
return - V_246 ;
if ( ! F_188 ( V_116 -> V_247 ) ) {
error = - V_248 ;
goto V_249;
}
if ( F_189 ( V_116 ) ) {
error = - V_250 ;
goto V_249;
}
if ( ! V_2 -> V_91 -> V_251 || ! V_2 -> V_91 -> V_252 ||
( type == V_162 && V_2 -> V_49 -> V_200 == NULL ) ) {
error = - V_235 ;
goto V_249;
}
if ( ! ( V_89 & V_232 ) ) {
error = - V_235 ;
goto V_249;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_190 ( V_2 ) ;
F_185 ( V_2 -> V_93 ) ;
}
F_34 ( & V_61 -> V_81 ) ;
if ( F_181 ( V_2 , type ) ) {
error = - V_243 ;
goto V_253;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_34 ( & V_116 -> V_95 ) ;
V_245 = V_116 -> V_238 & ( V_240 | V_239 |
V_241 ) ;
V_116 -> V_238 |= V_241 | V_240 | V_239 ;
F_35 ( & V_116 -> V_95 ) ;
F_152 ( V_116 ) ;
}
error = - V_69 ;
V_61 -> V_94 [ type ] = F_191 ( V_116 ) ;
if ( ! V_61 -> V_94 [ type ] )
goto V_253;
error = - V_235 ;
if ( ! V_4 -> V_254 -> V_255 ( V_2 , type ) )
goto V_256;
V_61 -> V_64 [ type ] = V_4 -> V_254 ;
V_61 -> V_53 [ type ] . V_179 = V_4 ;
V_61 -> V_53 [ type ] . V_257 = V_244 ;
F_94 ( & V_61 -> V_53 [ type ] . V_54 ) ;
F_34 ( & V_61 -> V_62 ) ;
error = V_61 -> V_64 [ type ] -> F_192 ( V_2 , type ) ;
if ( error < 0 ) {
F_35 ( & V_61 -> V_62 ) ;
goto V_256;
}
if ( V_61 -> V_89 & V_90 )
V_61 -> V_53 [ type ] . V_58 |= V_258 ;
F_35 ( & V_61 -> V_62 ) ;
F_5 ( & V_113 ) ;
V_61 -> V_89 |= F_182 ( V_89 , type ) ;
F_6 ( & V_113 ) ;
F_103 ( V_2 , type ) ;
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
V_256:
V_61 -> V_94 [ type ] = NULL ;
F_107 ( V_116 ) ;
V_253:
if ( V_245 != - 1 ) {
F_34 ( & V_116 -> V_95 ) ;
V_116 -> V_238 &= ~ ( V_240 | V_241 | V_239 ) ;
V_116 -> V_238 |= V_245 ;
F_35 ( & V_116 -> V_95 ) ;
}
F_35 ( & V_61 -> V_81 ) ;
V_249:
F_11 ( V_4 ) ;
return error ;
}
int F_193 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_116 * V_116 ;
int V_51 = 0 , V_56 ;
unsigned int V_89 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_183 ( V_2 , V_56 ) ) {
F_35 ( & V_61 -> V_81 ) ;
continue;
}
V_116 = V_61 -> V_94 [ V_56 ] ;
V_61 -> V_94 [ V_56 ] = NULL ;
F_5 ( & V_113 ) ;
V_89 = V_61 -> V_89 & F_182 ( V_232 |
V_233 ,
V_56 ) ;
V_61 -> V_89 &= ~ F_182 ( V_259 , V_56 ) ;
F_6 ( & V_113 ) ;
F_35 ( & V_61 -> V_81 ) ;
V_89 = F_194 ( V_89 , V_56 ) ;
V_51 = F_187 ( V_116 , V_56 ,
V_61 -> V_53 [ V_56 ] . V_257 , V_89 ) ;
F_107 ( V_116 ) ;
}
return V_51 ;
}
int F_195 ( struct V_1 * V_2 , int type , int V_244 ,
struct V_260 * V_260 )
{
int error = F_196 ( V_260 -> V_261 ) ;
if ( error )
return error ;
if ( V_260 -> V_261 -> V_262 != V_2 )
error = - V_263 ;
else
error = F_187 ( F_197 ( V_260 -> V_261 ) , type ,
V_244 , V_232 |
V_233 ) ;
return error ;
}
int F_198 ( struct V_116 * V_116 , int type , int V_244 ,
unsigned int V_89 )
{
int V_51 = 0 ;
struct V_1 * V_2 = V_116 -> V_117 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_89 ( V_89 & V_234 ) ;
if ( ! V_89 )
return 0 ;
if ( F_181 ( V_2 , type ) ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_181 ( V_2 , type ) ) {
F_35 ( & V_61 -> V_81 ) ;
goto V_264;
}
if ( V_89 & V_232 &&
F_199 ( V_2 , type ) ) {
V_51 = - V_243 ;
goto V_253;
}
if ( V_89 & V_233 &&
F_140 ( V_2 , type ) ) {
V_51 = - V_243 ;
goto V_253;
}
F_5 ( & V_113 ) ;
F_42 ( V_2 ) -> V_89 |= F_182 ( V_89 , type ) ;
F_6 ( & V_113 ) ;
V_253:
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
V_264:
return F_187 ( V_116 , type , V_244 , V_89 ) ;
}
int F_200 ( struct V_1 * V_2 , char * V_265 ,
int V_244 , int type )
{
struct V_261 * V_261 ;
int error ;
F_34 ( & F_197 ( V_2 -> V_266 ) -> V_95 ) ;
V_261 = F_201 ( V_265 , V_2 -> V_266 , strlen ( V_265 ) ) ;
F_35 ( & F_197 ( V_2 -> V_266 ) -> V_95 ) ;
if ( F_202 ( V_261 ) )
return F_203 ( V_261 ) ;
if ( F_204 ( V_261 ) ) {
error = - V_267 ;
goto V_83;
}
error = F_196 ( V_261 ) ;
if ( ! error )
error = F_187 ( F_197 ( V_261 ) , type , V_244 ,
V_232 | V_233 ) ;
V_83:
F_205 ( V_261 ) ;
return error ;
}
static int F_206 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_268 ;
V_89 &= ~ ( V_269 | V_270 | V_271 ) ;
if ( ! V_89 )
return - V_235 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! ( V_89 & F_207 ( type ) ) )
continue;
if ( ! F_199 ( V_2 , type ) )
return - V_235 ;
V_51 = F_198 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_257 ,
V_233 ) ;
if ( V_51 < 0 )
goto V_201;
}
return 0 ;
V_201:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_207 ( type ) )
F_180 ( V_2 , type , V_233 ) ;
}
if ( V_51 == - V_243 )
V_51 = - V_272 ;
return V_51 ;
}
static int F_208 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_268 ;
if ( V_89 &
( V_269 | V_270 | V_271 ) )
return - V_273 ;
for ( type = 0 ; type < V_27 ; type ++ )
if ( ! F_140 ( V_2 , type ) )
V_89 &= ~ F_207 ( type ) ;
if ( ! V_89 )
return - V_272 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( V_89 & F_207 ( type ) ) {
V_51 = F_180 ( V_2 , type , V_233 ) ;
if ( V_51 < 0 )
goto V_201;
}
}
return 0 ;
V_201:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_207 ( type ) )
F_198 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_257 ,
V_233 ) ;
}
return V_51 ;
}
static void F_209 ( struct V_30 * V_30 , struct V_274 * V_275 )
{
struct V_276 * V_277 = & V_30 -> V_136 ;
memset ( V_275 , 0 , sizeof( * V_275 ) ) ;
F_5 ( & V_132 ) ;
V_275 -> V_278 = V_277 -> V_191 ;
V_275 -> V_279 = V_277 -> V_145 ;
V_275 -> V_280 = V_277 -> V_185 ;
V_275 -> V_281 = V_277 -> V_141 ;
V_275 -> V_282 = V_277 -> V_138 + V_277 -> V_139 ;
V_275 -> V_283 = V_277 -> V_137 ;
V_275 -> V_284 = V_277 -> V_146 ;
V_275 -> V_285 = V_277 -> V_142 ;
F_6 ( & V_132 ) ;
}
int F_210 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_274 * V_275 )
{
struct V_30 * V_30 ;
V_30 = F_99 ( V_2 , V_23 ) ;
if ( ! V_30 )
return - V_246 ;
F_209 ( V_30 , V_275 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_211 ( struct V_30 * V_30 , struct V_274 * V_275 )
{
struct V_276 * V_277 = & V_30 -> V_136 ;
int V_286 = 0 , V_287 = 0 ;
struct V_177 * V_288 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
if ( V_275 -> V_289 & ~ V_290 )
return - V_235 ;
if ( ( ( V_275 -> V_289 & V_291 ) &&
V_275 -> V_279 > V_288 -> V_292 ) ||
( ( V_275 -> V_289 & V_293 ) &&
V_275 -> V_278 > V_288 -> V_292 ) ||
( ( V_275 -> V_289 & V_294 ) &&
( V_275 -> V_281 > V_288 -> V_295 ) ) ||
( ( V_275 -> V_289 & V_296 ) &&
( V_275 -> V_280 > V_288 -> V_295 ) ) )
return - V_297 ;
F_5 ( & V_132 ) ;
if ( V_275 -> V_289 & V_298 ) {
V_277 -> V_138 = V_275 -> V_282 - V_277 -> V_139 ;
V_286 = 1 ;
F_49 ( V_299 + V_300 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_291 )
V_277 -> V_145 = V_275 -> V_279 ;
if ( V_275 -> V_289 & V_293 )
V_277 -> V_191 = V_275 -> V_278 ;
if ( V_275 -> V_289 & ( V_291 | V_293 ) ) {
V_286 = 1 ;
F_49 ( V_299 + V_301 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_302 ) {
V_277 -> V_137 = V_275 -> V_283 ;
V_287 = 1 ;
F_49 ( V_299 + V_303 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_294 )
V_277 -> V_141 = V_275 -> V_281 ;
if ( V_275 -> V_289 & V_296 )
V_277 -> V_185 = V_275 -> V_280 ;
if ( V_275 -> V_289 & ( V_294 | V_296 ) ) {
V_287 = 1 ;
F_49 ( V_299 + V_304 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_305 ) {
V_277 -> V_146 = V_275 -> V_284 ;
V_286 = 1 ;
F_49 ( V_299 + V_306 , & V_30 -> V_48 ) ;
}
if ( V_275 -> V_289 & V_307 ) {
V_277 -> V_142 = V_275 -> V_285 ;
V_287 = 1 ;
F_49 ( V_299 + V_308 , & V_30 -> V_48 ) ;
}
if ( V_286 ) {
if ( ! V_277 -> V_145 ||
V_277 -> V_138 < V_277 -> V_145 ) {
V_277 -> V_146 = 0 ;
F_58 ( V_147 , & V_30 -> V_48 ) ;
} else if ( ! ( V_275 -> V_289 & V_305 ) )
V_277 -> V_146 = F_141 () + V_288 -> V_192 ;
}
if ( V_287 ) {
if ( ! V_277 -> V_141 ||
V_277 -> V_137 < V_277 -> V_141 ) {
V_277 -> V_142 = 0 ;
F_58 ( V_144 , & V_30 -> V_48 ) ;
} else if ( ! ( V_275 -> V_289 & V_307 ) )
V_277 -> V_142 = F_141 () + V_288 -> V_187 ;
}
if ( V_277 -> V_191 || V_277 -> V_145 || V_277 -> V_185 ||
V_277 -> V_141 )
F_58 ( V_184 , & V_30 -> V_48 ) ;
else
F_49 ( V_184 , & V_30 -> V_48 ) ;
F_6 ( & V_132 ) ;
F_38 ( V_30 ) ;
return 0 ;
}
int F_212 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_274 * V_275 )
{
struct V_30 * V_30 ;
int V_197 ;
V_30 = F_99 ( V_2 , V_23 ) ;
if ( ! V_30 ) {
V_197 = - V_246 ;
goto V_83;
}
V_197 = F_211 ( V_30 , V_275 ) ;
F_45 ( V_30 ) ;
V_83:
return V_197 ;
}
int F_213 ( struct V_1 * V_2 , struct V_309 * V_310 )
{
struct V_177 * V_311 ;
struct V_312 * V_313 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int type ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
memset ( V_310 , 0 , sizeof( * V_310 ) ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! F_74 ( V_2 , type ) )
continue;
V_313 = V_310 -> V_314 + type ;
V_311 = F_42 ( V_2 ) -> V_53 + type ;
V_313 -> V_89 = V_315 ;
F_5 ( & V_132 ) ;
if ( V_311 -> V_58 & V_258 )
V_313 -> V_89 |= V_316 ;
if ( V_311 -> V_58 & V_181 )
V_313 -> V_89 |= V_317 ;
if ( F_140 ( V_2 , type ) )
V_313 -> V_89 |= V_318 ;
V_313 -> V_319 = V_311 -> V_192 ;
V_313 -> V_320 = V_311 -> V_187 ;
V_313 -> V_321 = V_61 -> V_94 [ type ] -> V_322 ;
V_313 -> V_323 = V_61 -> V_94 [ type ] -> V_324 ;
V_313 -> V_325 = 1 ;
F_6 ( & V_132 ) ;
}
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return 0 ;
}
int F_214 ( struct V_1 * V_2 , int type , struct V_326 * V_327 )
{
struct V_177 * V_311 ;
int V_55 = 0 ;
if ( ( V_327 -> V_328 & V_329 ) ||
( V_327 -> V_328 & V_330 ) )
return - V_235 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_74 ( V_2 , type ) ) {
V_55 = - V_246 ;
goto V_83;
}
V_311 = F_42 ( V_2 ) -> V_53 + type ;
if ( V_327 -> V_328 & V_331 ) {
if ( ( V_327 -> V_238 & V_317 &&
V_311 -> V_179 -> V_16 != V_180 ) ) {
V_55 = - V_235 ;
goto V_83;
}
}
F_5 ( & V_132 ) ;
if ( V_327 -> V_328 & V_305 )
V_311 -> V_192 = V_327 -> V_332 ;
if ( V_327 -> V_328 & V_307 )
V_311 -> V_187 = V_327 -> V_333 ;
if ( V_327 -> V_328 & V_331 ) {
if ( V_327 -> V_238 & V_317 )
V_311 -> V_58 |= V_181 ;
else
V_311 -> V_58 &= ~ V_181 ;
}
F_6 ( & V_132 ) ;
F_48 ( V_2 , type ) ;
V_2 -> V_49 -> V_87 ( V_2 , type ) ;
V_83:
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_55 ;
}
static int F_215 ( struct V_334 * V_335 , int V_336 ,
void T_4 * V_337 , T_5 * V_338 , T_6 * V_339 )
{
unsigned int type = ( int * ) V_335 -> V_340 - V_104 . V_341 ;
V_104 . V_341 [ type ] =
F_216 ( & V_104 . V_105 [ type ] ) ;
return F_217 ( V_335 , V_336 , V_337 , V_338 , V_339 ) ;
}
static int T_7 F_218 ( void )
{
int V_174 , V_51 ;
unsigned long V_342 , V_343 ;
F_3 ( V_344 L_19 , V_345 ) ;
F_219 ( V_346 ) ;
V_73 = F_220 ( L_20 ,
sizeof( struct V_30 ) , sizeof( unsigned long ) * 4 ,
( V_347 | V_348 |
V_349 | V_350 ) ,
NULL ) ;
V_343 = 0 ;
V_33 = (struct V_31 * ) F_221 ( V_351 , V_343 ) ;
if ( ! V_33 )
F_222 ( L_21 ) ;
for ( V_174 = 0 ; V_174 < V_352 ; V_174 ++ ) {
V_51 = F_223 ( & V_104 . V_105 [ V_174 ] , 0 , V_353 ) ;
if ( V_51 )
F_222 ( L_22 ) ;
}
V_342 = ( 1UL << V_343 ) * V_354 / sizeof( struct V_31 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( V_342 >> V_28 );
V_28 -- ;
V_342 = 1UL << V_28 ;
V_29 = V_342 - 1 ;
for ( V_174 = 0 ; V_174 < V_342 ; V_174 ++ )
F_224 ( V_33 + V_174 ) ;
F_225 ( L_23
L_24 , V_342 , V_343 , ( V_354 << V_343 ) ) ;
F_226 ( & V_355 ) ;
return 0 ;
}

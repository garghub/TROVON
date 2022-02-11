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
static int F_100 ( struct V_116 * V_116 , int type )
{
int V_56 ;
if ( F_101 ( V_116 ) )
return 0 ;
if ( type != - 1 )
return ! V_116 -> V_117 [ type ] ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ! V_116 -> V_117 [ V_56 ] )
return 1 ;
return 0 ;
}
static void F_102 ( struct V_1 * V_2 , int type )
{
struct V_116 * V_116 , * V_118 = NULL ;
#ifdef F_84
int V_119 = 0 ;
#endif
F_5 ( & V_120 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_116 -> V_121 ) ;
if ( ( V_116 -> V_122 & ( V_123 | V_124 | V_125 ) ) ||
! F_57 ( & V_116 -> V_126 ) ||
! F_100 ( V_116 , type ) ) {
F_6 ( & V_116 -> V_121 ) ;
continue;
}
F_103 ( V_116 ) ;
F_6 ( & V_116 -> V_121 ) ;
F_6 ( & V_120 ) ;
#ifdef F_84
if ( F_104 ( F_105 ( V_116 ) > 0 ) )
V_119 = 1 ;
#endif
F_106 ( V_118 ) ;
F_107 ( V_116 , type ) ;
V_118 = V_116 ;
F_5 ( & V_120 ) ;
}
F_6 ( & V_120 ) ;
F_106 ( V_118 ) ;
#ifdef F_84
if ( V_119 ) {
F_85 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static void F_108 ( struct V_116 * V_116 , int type ,
struct V_84 * V_127 )
{
struct V_30 * V_30 = V_116 -> V_117 [ type ] ;
V_116 -> V_117 [ type ] = NULL ;
if ( ! V_30 )
return;
if ( F_27 ( & V_30 -> V_40 ) ) {
F_5 ( & V_11 ) ;
F_41 ( & V_30 -> V_40 , V_127 ) ;
F_6 ( & V_11 ) ;
} else {
F_45 ( V_30 ) ;
}
}
static void F_109 ( struct V_84 * V_127 )
{
struct V_84 * V_128 ;
struct V_30 * V_30 ;
V_128 = V_127 -> V_129 ;
while ( V_128 != V_127 ) {
V_30 = F_80 ( V_128 , struct V_30 , V_40 ) ;
V_128 = V_128 -> V_129 ;
F_28 ( & V_30 -> V_40 ) ;
F_45 ( V_30 ) ;
}
}
static void F_110 ( struct V_1 * V_2 , int type ,
struct V_84 * V_127 )
{
struct V_116 * V_116 ;
int V_119 = 0 ;
F_5 ( & V_120 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_130 ) ;
if ( ! F_101 ( V_116 ) ) {
if ( F_104 ( F_105 ( V_116 ) > 0 ) )
V_119 = 1 ;
F_108 ( V_116 , type , V_127 ) ;
}
F_6 ( & V_130 ) ;
}
F_6 ( & V_120 ) ;
#ifdef F_84
if ( V_119 ) {
F_3 ( V_131 L_8
L_9
L_10 , V_2 -> V_9 ) ;
}
#endif
}
static void F_111 ( struct V_1 * V_2 , int type )
{
F_112 ( V_127 ) ;
if ( V_2 -> V_49 ) {
F_110 ( V_2 , type , & V_127 ) ;
F_113 ( & V_132 ) ;
F_109 ( & V_127 ) ;
}
}
static inline void F_114 ( struct V_30 * V_30 , T_2 V_133 )
{
V_30 -> V_134 . V_135 += V_133 ;
}
static inline void F_115 ( struct V_30 * V_30 , T_2 V_133 )
{
V_30 -> V_134 . V_136 += V_133 ;
}
static inline void F_116 ( struct V_30 * V_30 , T_2 V_133 )
{
V_30 -> V_134 . V_137 += V_133 ;
}
static void F_117 ( struct V_30 * V_30 , T_2 V_133 )
{
if ( V_30 -> V_134 . V_137 < V_133 ) {
F_118 ( 1 ) ;
V_133 = V_30 -> V_134 . V_137 ;
}
V_30 -> V_134 . V_136 += V_133 ;
V_30 -> V_134 . V_137 -= V_133 ;
}
static void F_119 ( struct V_30 * V_30 , T_2 V_133 )
{
if ( F_118 ( V_30 -> V_134 . V_136 < V_133 ) )
V_133 = V_30 -> V_134 . V_136 ;
V_30 -> V_134 . V_137 += V_133 ;
V_30 -> V_134 . V_136 -= V_133 ;
}
static inline
void F_120 ( struct V_30 * V_30 , T_2 V_133 )
{
if ( V_30 -> V_134 . V_137 >= V_133 )
V_30 -> V_134 . V_137 -= V_133 ;
else {
F_118 ( 1 ) ;
V_30 -> V_134 . V_137 = 0 ;
}
}
static void F_121 ( struct V_30 * V_30 , T_2 V_133 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_138 ||
V_30 -> V_134 . V_135 >= V_133 )
V_30 -> V_134 . V_135 -= V_133 ;
else
V_30 -> V_134 . V_135 = 0 ;
if ( V_30 -> V_134 . V_135 <= V_30 -> V_134 . V_139 )
V_30 -> V_134 . V_140 = ( V_141 ) 0 ;
F_58 ( V_142 , & V_30 -> V_48 ) ;
}
static void F_122 ( struct V_30 * V_30 , T_2 V_133 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_138 ||
V_30 -> V_134 . V_136 >= V_133 )
V_30 -> V_134 . V_136 -= V_133 ;
else
V_30 -> V_134 . V_136 = 0 ;
if ( V_30 -> V_134 . V_136 <= V_30 -> V_134 . V_143 )
V_30 -> V_134 . V_144 = ( V_141 ) 0 ;
F_58 ( V_145 , & V_30 -> V_48 ) ;
}
static int F_123 ( struct V_30 * V_30 , const int V_146 )
{
int V_147 = ( V_146 == V_148 ||
V_146 == V_149 ) ? V_145 :
( ( V_146 == V_150 ||
V_146 == V_151 ) ? V_142 : 0 ) ;
if ( ! V_147 )
return 0 ;
return F_40 ( V_147 , & V_30 -> V_48 ) ;
}
static int F_124 ( struct V_152 * V_153 )
{
if ( ! V_154 )
return 0 ;
switch ( V_153 -> V_155 . type ) {
case V_156 :
return F_125 ( F_126 () , V_153 -> V_155 . V_157 ) ;
case V_158 :
return F_127 ( V_153 -> V_155 . V_159 ) ;
case V_160 :
return 0 ;
}
return 0 ;
}
static void F_128 ( struct V_152 * V_153 )
{
char * V_161 = NULL ;
struct V_162 * V_163 ;
int V_146 = V_153 -> V_164 ;
if ( V_146 == V_165 ||
V_146 == V_166 ||
V_146 == V_167 ||
V_146 == V_168 || ! F_124 ( V_153 ) )
return;
V_163 = F_129 () ;
if ( ! V_163 )
return;
F_130 ( V_163 , V_153 -> V_169 -> V_9 ) ;
if ( V_146 == V_170 || V_146 == V_171 )
F_130 ( V_163 , L_11 ) ;
else
F_130 ( V_163 , L_12 ) ;
F_130 ( V_163 , V_106 [ V_153 -> V_155 . type ] ) ;
switch ( V_146 ) {
case V_150 :
V_161 = L_13 ;
break;
case V_151 :
V_161 = L_14 ;
break;
case V_170 :
V_161 = L_15 ;
break;
case V_148 :
V_161 = L_16 ;
break;
case V_149 :
V_161 = L_17 ;
break;
case V_171 :
V_161 = L_18 ;
break;
}
F_130 ( V_163 , V_161 ) ;
F_131 ( V_163 ) ;
}
static void F_132 ( struct V_152 * V_153 , struct V_30 * V_30 ,
int V_146 )
{
if ( F_123 ( V_30 , V_146 ) )
return;
V_153 -> V_164 = V_146 ;
V_153 -> V_169 = V_30 -> V_34 ;
V_153 -> V_155 = V_30 -> V_35 ;
}
static void F_133 ( struct V_152 * V_153 )
{
int V_172 ;
for ( V_172 = 0 ; V_172 < V_27 ; V_172 ++ ) {
if ( V_153 [ V_172 ] . V_164 == V_173 )
continue;
#ifdef F_134
F_128 ( & V_153 [ V_172 ] ) ;
#endif
F_135 ( V_153 [ V_172 ] . V_155 ,
V_153 [ V_172 ] . V_169 -> V_174 , V_153 [ V_172 ] . V_164 ) ;
}
}
static int F_136 ( struct V_30 * V_30 )
{
struct V_175 * V_53 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
return F_137 ( V_176 ) &&
( V_53 -> V_177 -> V_16 != V_178 ||
! ( V_53 -> V_58 & V_179 ) ) ;
}
static int F_138 ( struct V_30 * V_30 , T_2 V_180 ,
struct V_152 * V_153 )
{
T_2 V_181 = V_30 -> V_134 . V_135 + V_180 ;
if ( ! F_139 ( V_30 -> V_34 , V_30 -> V_35 . type ) ||
F_37 ( V_182 , & V_30 -> V_48 ) )
return 0 ;
if ( V_30 -> V_134 . V_183 &&
V_181 > V_30 -> V_134 . V_183 &&
! F_136 ( V_30 ) ) {
F_132 ( V_153 , V_30 , V_150 ) ;
return - V_184 ;
}
if ( V_30 -> V_134 . V_139 &&
V_181 > V_30 -> V_134 . V_139 &&
V_30 -> V_134 . V_140 &&
F_140 () >= V_30 -> V_134 . V_140 &&
! F_136 ( V_30 ) ) {
F_132 ( V_153 , V_30 , V_151 ) ;
return - V_184 ;
}
if ( V_30 -> V_134 . V_139 &&
V_181 > V_30 -> V_134 . V_139 &&
V_30 -> V_134 . V_140 == 0 ) {
F_132 ( V_153 , V_30 , V_170 ) ;
V_30 -> V_134 . V_140 = F_140 () +
F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] . V_185 ;
}
return 0 ;
}
static int F_141 ( struct V_30 * V_30 , T_2 V_186 , int V_187 ,
struct V_152 * V_153 )
{
T_2 V_188 ;
struct V_1 * V_2 = V_30 -> V_34 ;
if ( ! F_139 ( V_2 , V_30 -> V_35 . type ) ||
F_37 ( V_182 , & V_30 -> V_48 ) )
return 0 ;
V_188 = V_30 -> V_134 . V_136 + V_30 -> V_134 . V_137
+ V_186 ;
if ( V_30 -> V_134 . V_189 &&
V_188 > V_30 -> V_134 . V_189 &&
! F_136 ( V_30 ) ) {
if ( ! V_187 )
F_132 ( V_153 , V_30 , V_148 ) ;
return - V_184 ;
}
if ( V_30 -> V_134 . V_143 &&
V_188 > V_30 -> V_134 . V_143 &&
V_30 -> V_134 . V_144 &&
F_140 () >= V_30 -> V_134 . V_144 &&
! F_136 ( V_30 ) ) {
if ( ! V_187 )
F_132 ( V_153 , V_30 , V_149 ) ;
return - V_184 ;
}
if ( V_30 -> V_134 . V_143 &&
V_188 > V_30 -> V_134 . V_143 &&
V_30 -> V_134 . V_144 == 0 ) {
if ( ! V_187 ) {
F_132 ( V_153 , V_30 , V_171 ) ;
V_30 -> V_134 . V_144 = F_140 () +
F_42 ( V_2 ) -> V_53 [ V_30 -> V_35 . type ] . V_190 ;
}
else
return - V_184 ;
}
return 0 ;
}
static int F_142 ( struct V_30 * V_30 , T_2 V_180 )
{
T_2 V_181 ;
if ( F_37 ( V_182 , & V_30 -> V_48 ) ||
V_30 -> V_134 . V_135 <= V_30 -> V_134 . V_139 ||
! F_139 ( V_30 -> V_34 , V_30 -> V_35 . type ) )
return V_173 ;
V_181 = V_30 -> V_134 . V_135 - V_180 ;
if ( V_181 <= V_30 -> V_134 . V_139 )
return V_166 ;
if ( V_30 -> V_134 . V_135 >= V_30 -> V_134 . V_183 &&
V_181 < V_30 -> V_134 . V_183 )
return V_165 ;
return V_173 ;
}
static int F_143 ( struct V_30 * V_30 , T_2 V_186 )
{
if ( F_37 ( V_182 , & V_30 -> V_48 ) ||
V_30 -> V_134 . V_136 <= V_30 -> V_134 . V_143 )
return V_173 ;
if ( V_30 -> V_134 . V_136 - V_186 <= V_30 -> V_134 . V_143 )
return V_168 ;
if ( V_30 -> V_134 . V_136 >= V_30 -> V_134 . V_189 &&
V_30 -> V_134 . V_136 - V_186 < V_30 -> V_134 . V_189 )
return V_167 ;
return V_173 ;
}
static int F_144 ( const struct V_116 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_191 ;
if ( F_101 ( V_116 ) )
return 0 ;
return F_145 ( V_2 ) & ~ F_146 ( V_2 ) ;
}
static void F_107 ( struct V_116 * V_116 , int type )
{
int V_56 , V_192 = 0 ;
struct V_30 * V_193 [ V_27 ] ;
struct V_1 * V_2 = V_116 -> V_191 ;
T_2 V_194 ;
if ( ! F_144 ( V_116 ) )
return;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
struct V_22 V_23 ;
V_193 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( V_116 -> V_117 [ V_56 ] )
continue;
V_192 = 1 ;
switch ( V_56 ) {
case V_156 :
V_23 = F_147 ( V_116 -> V_195 ) ;
break;
case V_158 :
V_23 = F_148 ( V_116 -> V_196 ) ;
break;
}
V_193 [ V_56 ] = F_99 ( V_2 , V_23 ) ;
}
if ( ! V_192 )
return;
F_5 ( & V_130 ) ;
if ( F_101 ( V_116 ) )
goto V_197;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_74 ( V_2 , V_56 ) )
continue;
if ( ! V_193 [ V_56 ] )
continue;
if ( ! V_116 -> V_117 [ V_56 ] ) {
V_116 -> V_117 [ V_56 ] = V_193 [ V_56 ] ;
V_193 [ V_56 ] = NULL ;
V_194 = F_105 ( V_116 ) ;
if ( F_104 ( V_194 ) )
F_116 ( V_116 -> V_117 [ V_56 ] , V_194 ) ;
}
}
V_197:
F_6 ( & V_130 ) ;
F_44 ( V_193 ) ;
}
void F_149 ( struct V_116 * V_116 )
{
F_107 ( V_116 , - 1 ) ;
}
static void F_150 ( struct V_116 * V_116 )
{
int V_56 ;
struct V_30 * V_198 [ V_27 ] ;
F_5 ( & V_130 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_198 [ V_56 ] = V_116 -> V_117 [ V_56 ] ;
V_116 -> V_117 [ V_56 ] = NULL ;
}
F_6 ( & V_130 ) ;
F_44 ( V_198 ) ;
}
void F_151 ( struct V_116 * V_116 )
{
int V_56 ;
if ( F_101 ( V_116 ) )
return;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_116 -> V_117 [ V_56 ] )
break;
}
if ( V_56 < V_27 )
F_150 ( V_116 ) ;
}
static T_2 * F_152 ( struct V_116 * V_116 )
{
F_89 ( ! V_116 -> V_191 -> V_49 -> V_199 ) ;
return V_116 -> V_191 -> V_49 -> V_199 ( V_116 ) ;
}
void F_153 ( struct V_116 * V_116 , T_2 V_133 )
{
F_5 ( & V_116 -> V_121 ) ;
* F_152 ( V_116 ) += V_133 ;
F_6 ( & V_116 -> V_121 ) ;
}
void F_154 ( struct V_116 * V_116 , T_2 V_133 )
{
F_5 ( & V_116 -> V_121 ) ;
* F_152 ( V_116 ) -= V_133 ;
F_155 ( V_116 , V_133 ) ;
F_6 ( & V_116 -> V_121 ) ;
}
void F_156 ( struct V_116 * V_116 , T_2 V_133 )
{
F_5 ( & V_116 -> V_121 ) ;
* F_152 ( V_116 ) += V_133 ;
F_157 ( V_116 , V_133 ) ;
F_6 ( & V_116 -> V_121 ) ;
}
void F_158 ( struct V_116 * V_116 , T_2 V_133 )
{
F_5 ( & V_116 -> V_121 ) ;
* F_152 ( V_116 ) -= V_133 ;
F_6 ( & V_116 -> V_121 ) ;
}
static T_2 F_105 ( struct V_116 * V_116 )
{
T_2 V_51 ;
if ( ! V_116 -> V_191 -> V_49 -> V_199 )
return 0 ;
F_5 ( & V_116 -> V_121 ) ;
V_51 = * F_152 ( V_116 ) ;
F_6 ( & V_116 -> V_121 ) ;
return V_51 ;
}
static void F_159 ( struct V_116 * V_116 , T_2 V_133 ,
int V_200 )
{
if ( V_200 )
F_153 ( V_116 , V_133 ) ;
else
F_160 ( V_116 , V_133 ) ;
}
static void F_161 ( struct V_116 * V_116 , T_2 V_133 , int V_200 )
{
if ( V_200 )
F_158 ( V_116 , V_133 ) ;
else
F_162 ( V_116 , V_133 ) ;
}
int F_163 ( struct V_116 * V_116 , T_2 V_133 , int V_89 )
{
int V_56 , V_51 = 0 , V_201 ;
struct V_152 V_153 [ V_27 ] ;
struct V_30 * * V_202 = V_116 -> V_117 ;
int V_200 = V_89 & V_203 ;
if ( ! F_144 ( V_116 ) ) {
F_159 ( V_116 , V_133 , V_200 ) ;
goto V_83;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_153 [ V_56 ] . V_164 = V_173 ;
V_201 = F_164 ( & V_132 ) ;
F_5 ( & V_130 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
V_51 = F_141 ( V_202 [ V_56 ] , V_133 ,
! ( V_89 & V_204 ) , & V_153 [ V_56 ] ) ;
if ( V_51 && ! ( V_89 & V_205 ) ) {
F_6 ( & V_130 ) ;
goto V_206;
}
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
if ( V_200 )
F_116 ( V_202 [ V_56 ] , V_133 ) ;
else
F_115 ( V_202 [ V_56 ] , V_133 ) ;
}
F_159 ( V_116 , V_133 , V_200 ) ;
F_6 ( & V_130 ) ;
if ( V_200 )
goto V_206;
F_43 ( V_202 ) ;
V_206:
F_165 ( & V_132 , V_201 ) ;
F_133 ( V_153 ) ;
V_83:
return V_51 ;
}
int F_166 ( const struct V_116 * V_116 )
{
int V_56 , V_51 = 0 , V_201 ;
struct V_152 V_153 [ V_27 ] ;
struct V_30 * const * V_202 = V_116 -> V_117 ;
if ( ! F_144 ( V_116 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_153 [ V_56 ] . V_164 = V_173 ;
V_201 = F_164 ( & V_132 ) ;
F_5 ( & V_130 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
V_51 = F_138 ( V_202 [ V_56 ] , 1 , & V_153 [ V_56 ] ) ;
if ( V_51 )
goto V_207;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
F_114 ( V_202 [ V_56 ] , 1 ) ;
}
V_207:
F_6 ( & V_130 ) ;
if ( V_51 == 0 )
F_43 ( V_202 ) ;
F_165 ( & V_132 , V_201 ) ;
F_133 ( V_153 ) ;
return V_51 ;
}
int F_167 ( struct V_116 * V_116 , T_2 V_133 )
{
int V_56 , V_201 ;
if ( ! F_144 ( V_116 ) ) {
F_154 ( V_116 , V_133 ) ;
return 0 ;
}
V_201 = F_164 ( & V_132 ) ;
F_5 ( & V_130 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_116 -> V_117 [ V_56 ] )
F_117 ( V_116 -> V_117 [ V_56 ] ,
V_133 ) ;
}
F_154 ( V_116 , V_133 ) ;
F_6 ( & V_130 ) ;
F_43 ( V_116 -> V_117 ) ;
F_165 ( & V_132 , V_201 ) ;
return 0 ;
}
void F_168 ( struct V_116 * V_116 , T_2 V_133 )
{
int V_56 , V_201 ;
if ( ! F_144 ( V_116 ) ) {
F_156 ( V_116 , V_133 ) ;
return;
}
V_201 = F_164 ( & V_132 ) ;
F_5 ( & V_130 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_116 -> V_117 [ V_56 ] )
F_119 ( V_116 -> V_117 [ V_56 ] ,
V_133 ) ;
}
F_156 ( V_116 , V_133 ) ;
F_6 ( & V_130 ) ;
F_43 ( V_116 -> V_117 ) ;
F_165 ( & V_132 , V_201 ) ;
return;
}
void F_169 ( struct V_116 * V_116 , T_2 V_133 , int V_89 )
{
unsigned int V_56 ;
struct V_152 V_153 [ V_27 ] ;
struct V_30 * * V_202 = V_116 -> V_117 ;
int V_200 = V_89 & V_203 , V_201 ;
if ( ! F_144 ( V_116 ) ) {
F_161 ( V_116 , V_133 , V_200 ) ;
return;
}
V_201 = F_164 ( & V_132 ) ;
F_5 ( & V_130 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_208 ;
V_153 [ V_56 ] . V_164 = V_173 ;
if ( ! V_202 [ V_56 ] )
continue;
V_208 = F_143 ( V_202 [ V_56 ] , V_133 ) ;
if ( V_208 != V_173 )
F_132 ( & V_153 [ V_56 ] , V_202 [ V_56 ] , V_208 ) ;
if ( V_200 )
F_120 ( V_202 [ V_56 ] , V_133 ) ;
else
F_122 ( V_202 [ V_56 ] , V_133 ) ;
}
F_161 ( V_116 , V_133 , V_200 ) ;
F_6 ( & V_130 ) ;
if ( V_200 )
goto V_209;
F_43 ( V_202 ) ;
V_209:
F_165 ( & V_132 , V_201 ) ;
F_133 ( V_153 ) ;
}
void F_170 ( const struct V_116 * V_116 )
{
unsigned int V_56 ;
struct V_152 V_153 [ V_27 ] ;
struct V_30 * const * V_202 = V_116 -> V_117 ;
int V_201 ;
if ( ! F_144 ( V_116 ) )
return;
V_201 = F_164 ( & V_132 ) ;
F_5 ( & V_130 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_208 ;
V_153 [ V_56 ] . V_164 = V_173 ;
if ( ! V_202 [ V_56 ] )
continue;
V_208 = F_142 ( V_202 [ V_56 ] , 1 ) ;
if ( V_208 != V_173 )
F_132 ( & V_153 [ V_56 ] , V_202 [ V_56 ] , V_208 ) ;
F_121 ( V_202 [ V_56 ] , 1 ) ;
}
F_6 ( & V_130 ) ;
F_43 ( V_202 ) ;
F_165 ( & V_132 , V_201 ) ;
F_133 ( V_153 ) ;
}
int F_171 ( struct V_116 * V_116 , struct V_30 * * V_210 )
{
T_2 V_186 , V_211 ;
T_2 V_212 = 0 ;
struct V_30 * V_213 [ V_27 ] = {} ;
int V_56 , V_51 = 0 ;
char V_214 [ V_27 ] = {} ;
struct V_152 V_215 [ V_27 ] ;
struct V_152 V_216 [ V_27 ] ;
struct V_152 V_217 [ V_27 ] ;
if ( F_101 ( V_116 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_215 [ V_56 ] . V_164 = V_173 ;
V_216 [ V_56 ] . V_164 = V_173 ;
V_217 [ V_56 ] . V_164 = V_173 ;
}
F_5 ( & V_130 ) ;
if ( F_101 ( V_116 ) ) {
F_6 ( & V_130 ) ;
return 0 ;
}
V_211 = F_172 ( V_116 ) ;
V_212 = F_105 ( V_116 ) ;
V_186 = V_211 + V_212 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_210 [ V_56 ] )
continue;
if ( ! F_74 ( V_116 -> V_191 , V_56 ) )
continue;
V_214 [ V_56 ] = 1 ;
V_213 [ V_56 ] = V_116 -> V_117 [ V_56 ] ;
V_51 = F_138 ( V_210 [ V_56 ] , 1 , & V_215 [ V_56 ] ) ;
if ( V_51 )
goto V_218;
V_51 = F_141 ( V_210 [ V_56 ] , V_186 , 0 , & V_215 [ V_56 ] ) ;
if ( V_51 )
goto V_218;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_214 [ V_56 ] )
continue;
if ( V_213 [ V_56 ] ) {
int V_208 ;
V_208 = F_142 ( V_213 [ V_56 ] , 1 ) ;
if ( V_208 != V_173 )
F_132 ( & V_216 [ V_56 ] ,
V_213 [ V_56 ] , V_208 ) ;
V_208 = F_143 ( V_213 [ V_56 ] , V_186 ) ;
if ( V_208 != V_173 )
F_132 ( & V_217 [ V_56 ] ,
V_213 [ V_56 ] , V_208 ) ;
F_121 ( V_213 [ V_56 ] , 1 ) ;
F_122 ( V_213 [ V_56 ] , V_211 ) ;
F_120 ( V_213 [ V_56 ] ,
V_212 ) ;
}
F_114 ( V_210 [ V_56 ] , 1 ) ;
F_115 ( V_210 [ V_56 ] , V_211 ) ;
F_116 ( V_210 [ V_56 ] , V_212 ) ;
V_116 -> V_117 [ V_56 ] = V_210 [ V_56 ] ;
}
F_6 ( & V_130 ) ;
F_43 ( V_213 ) ;
F_43 ( V_210 ) ;
F_133 ( V_215 ) ;
F_133 ( V_216 ) ;
F_133 ( V_217 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_214 [ V_56 ] )
V_210 [ V_56 ] = V_213 [ V_56 ] ;
return 0 ;
V_218:
F_6 ( & V_130 ) ;
F_133 ( V_215 ) ;
return V_51 ;
}
int F_173 ( struct V_116 * V_116 , struct V_219 * V_219 )
{
struct V_30 * V_210 [ V_27 ] = {} ;
struct V_1 * V_2 = V_116 -> V_191 ;
int V_51 ;
if ( ! F_144 ( V_116 ) )
return 0 ;
if ( V_219 -> V_220 & V_221 && ! F_125 ( V_219 -> V_222 , V_116 -> V_195 ) )
V_210 [ V_156 ] = F_99 ( V_2 , F_147 ( V_219 -> V_222 ) ) ;
if ( V_219 -> V_220 & V_223 && ! F_174 ( V_219 -> V_224 , V_116 -> V_196 ) )
V_210 [ V_158 ] = F_99 ( V_2 , F_148 ( V_219 -> V_224 ) ) ;
V_51 = F_171 ( V_116 , V_210 ) ;
F_44 ( V_210 ) ;
return V_51 ;
}
int F_175 ( struct V_1 * V_2 , int type )
{
int V_51 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_34 ( & V_61 -> V_62 ) ;
V_51 = V_61 -> V_64 [ type ] -> F_54 ( V_2 , type ) ;
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_176 ( struct V_116 * V_116 , struct V_225 * V_225 )
{
int error ;
error = F_177 ( V_116 , V_225 ) ;
if ( ! error && ( V_225 -> V_226 & V_227 ) )
F_149 ( V_116 ) ;
return error ;
}
int F_178 ( struct V_1 * V_2 , int type , unsigned int V_89 )
{
int V_56 , V_51 = 0 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_116 * V_228 [ V_27 ] ;
if ( ( V_89 & V_229 && ! ( V_89 & V_230 ) )
|| ( V_89 & V_231 && V_89 & ( V_230 |
V_229 ) ) )
return - V_232 ;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_145 ( V_2 ) ) {
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_228 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_179 ( V_2 , V_56 ) )
continue;
if ( V_89 & V_231 ) {
F_5 ( & V_113 ) ;
V_61 -> V_89 |=
F_180 ( V_231 , V_56 ) ;
F_6 ( & V_113 ) ;
} else {
F_5 ( & V_113 ) ;
V_61 -> V_89 &= ~ F_180 ( V_89 , V_56 ) ;
if ( ! F_179 ( V_2 , V_56 ) &&
F_181 ( V_2 , V_56 ) ) {
V_61 -> V_89 &= ~ F_180 (
V_231 , V_56 ) ;
F_6 ( & V_113 ) ;
F_106 ( V_61 -> V_94 [ V_56 ] ) ;
V_61 -> V_94 [ V_56 ] = NULL ;
continue;
}
F_6 ( & V_113 ) ;
}
if ( F_179 ( V_2 , V_56 ) && ! ( V_89 & V_231 ) )
continue;
F_111 ( V_2 , V_56 ) ;
F_62 ( V_2 , V_56 ) ;
if ( F_53 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
if ( V_61 -> V_64 [ V_56 ] -> V_233 )
V_61 -> V_64 [ V_56 ] -> V_233 ( V_2 , V_56 ) ;
F_11 ( V_61 -> V_53 [ V_56 ] . V_177 ) ;
V_228 [ V_56 ] = V_61 -> V_94 [ V_56 ] ;
if ( ! F_179 ( V_2 , V_56 ) )
V_61 -> V_94 [ V_56 ] = NULL ;
V_61 -> V_53 [ V_56 ] . V_58 = 0 ;
V_61 -> V_53 [ V_56 ] . V_185 = 0 ;
V_61 -> V_53 [ V_56 ] . V_190 = 0 ;
V_61 -> V_64 [ V_56 ] = NULL ;
}
F_35 ( & V_61 -> V_81 ) ;
if ( V_61 -> V_89 & V_90 )
goto V_234;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_77 ( V_2 -> V_93 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_228 [ V_56 ] ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_179 ( V_2 , V_56 ) ) {
F_34 ( & V_228 [ V_56 ] -> V_95 ) ;
V_228 [ V_56 ] -> V_235 &= ~ ( V_236 |
V_237 | V_238 ) ;
F_78 ( & V_228 [ V_56 ] -> V_96 ,
0 ) ;
F_35 ( & V_228 [ V_56 ] -> V_95 ) ;
F_182 ( V_228 [ V_56 ] ) ;
}
F_35 ( & V_61 -> V_81 ) ;
}
if ( V_2 -> V_93 )
F_183 ( V_2 -> V_93 ) ;
V_234:
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_228 [ V_56 ] ) {
if ( ! ( V_89 & V_231 ) )
F_106 ( V_228 [ V_56 ] ) ;
else if ( ! V_228 [ V_56 ] -> V_239 )
V_51 = - V_240 ;
}
return V_51 ;
}
int F_184 ( struct V_1 * V_2 , int type )
{
return F_178 ( V_2 , type ,
V_229 | V_230 ) ;
}
static int F_185 ( struct V_116 * V_116 , int type , int V_241 ,
unsigned int V_89 )
{
struct V_10 * V_4 = F_8 ( V_241 ) ;
struct V_1 * V_2 = V_116 -> V_191 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int error ;
int V_242 = - 1 ;
if ( ! V_4 )
return - V_243 ;
if ( ! F_186 ( V_116 -> V_244 ) ) {
error = - V_245 ;
goto V_246;
}
if ( F_187 ( V_116 ) ) {
error = - V_247 ;
goto V_246;
}
if ( ! V_2 -> V_91 -> V_248 || ! V_2 -> V_91 -> V_249 ) {
error = - V_232 ;
goto V_246;
}
if ( ! ( V_89 & V_229 ) ) {
error = - V_232 ;
goto V_246;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_188 ( V_2 ) ;
F_183 ( V_2 -> V_93 ) ;
}
F_34 ( & V_61 -> V_81 ) ;
if ( F_179 ( V_2 , type ) ) {
error = - V_240 ;
goto V_250;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_34 ( & V_116 -> V_95 ) ;
V_242 = V_116 -> V_235 & ( V_237 | V_236 |
V_238 ) ;
V_116 -> V_235 |= V_238 | V_237 | V_236 ;
F_35 ( & V_116 -> V_95 ) ;
F_150 ( V_116 ) ;
}
error = - V_69 ;
V_61 -> V_94 [ type ] = F_189 ( V_116 ) ;
if ( ! V_61 -> V_94 [ type ] )
goto V_250;
error = - V_232 ;
if ( ! V_4 -> V_251 -> V_252 ( V_2 , type ) )
goto V_253;
V_61 -> V_64 [ type ] = V_4 -> V_251 ;
V_61 -> V_53 [ type ] . V_177 = V_4 ;
V_61 -> V_53 [ type ] . V_254 = V_241 ;
F_94 ( & V_61 -> V_53 [ type ] . V_54 ) ;
F_34 ( & V_61 -> V_62 ) ;
error = V_61 -> V_64 [ type ] -> F_190 ( V_2 , type ) ;
if ( error < 0 ) {
F_35 ( & V_61 -> V_62 ) ;
goto V_253;
}
if ( V_61 -> V_89 & V_90 )
V_61 -> V_53 [ type ] . V_58 |= V_255 ;
F_35 ( & V_61 -> V_62 ) ;
F_5 ( & V_113 ) ;
V_61 -> V_89 |= F_180 ( V_89 , type ) ;
F_6 ( & V_113 ) ;
F_102 ( V_2 , type ) ;
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
V_253:
V_61 -> V_94 [ type ] = NULL ;
F_106 ( V_116 ) ;
V_250:
if ( V_242 != - 1 ) {
F_34 ( & V_116 -> V_95 ) ;
V_116 -> V_235 &= ~ ( V_237 | V_238 | V_236 ) ;
V_116 -> V_235 |= V_242 ;
F_35 ( & V_116 -> V_95 ) ;
}
F_35 ( & V_61 -> V_81 ) ;
V_246:
F_11 ( V_4 ) ;
return error ;
}
int F_191 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_116 * V_116 ;
int V_51 = 0 , V_56 ;
unsigned int V_89 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_181 ( V_2 , V_56 ) ) {
F_35 ( & V_61 -> V_81 ) ;
continue;
}
V_116 = V_61 -> V_94 [ V_56 ] ;
V_61 -> V_94 [ V_56 ] = NULL ;
F_5 ( & V_113 ) ;
V_89 = V_61 -> V_89 & F_180 ( V_229 |
V_230 ,
V_56 ) ;
V_61 -> V_89 &= ~ F_180 ( V_256 , V_56 ) ;
F_6 ( & V_113 ) ;
F_35 ( & V_61 -> V_81 ) ;
V_89 = F_192 ( V_89 , V_56 ) ;
V_51 = F_185 ( V_116 , V_56 ,
V_61 -> V_53 [ V_56 ] . V_254 , V_89 ) ;
F_106 ( V_116 ) ;
}
return V_51 ;
}
int F_193 ( struct V_1 * V_2 , int type , int V_241 ,
struct V_257 * V_257 )
{
int error = F_194 ( V_257 -> V_258 ) ;
if ( error )
return error ;
if ( V_257 -> V_258 -> V_259 != V_2 )
error = - V_260 ;
else
error = F_185 ( V_257 -> V_258 -> V_261 , type ,
V_241 , V_229 |
V_230 ) ;
return error ;
}
int F_195 ( struct V_116 * V_116 , int type , int V_241 ,
unsigned int V_89 )
{
int V_51 = 0 ;
struct V_1 * V_2 = V_116 -> V_191 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_89 ( V_89 & V_231 ) ;
if ( ! V_89 )
return 0 ;
if ( F_179 ( V_2 , type ) ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_179 ( V_2 , type ) ) {
F_35 ( & V_61 -> V_81 ) ;
goto V_262;
}
if ( V_89 & V_229 &&
F_196 ( V_2 , type ) ) {
V_51 = - V_240 ;
goto V_250;
}
if ( V_89 & V_230 &&
F_139 ( V_2 , type ) ) {
V_51 = - V_240 ;
goto V_250;
}
F_5 ( & V_113 ) ;
F_42 ( V_2 ) -> V_89 |= F_180 ( V_89 , type ) ;
F_6 ( & V_113 ) ;
V_250:
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
V_262:
return F_185 ( V_116 , type , V_241 , V_89 ) ;
}
int F_197 ( struct V_1 * V_2 , char * V_263 ,
int V_241 , int type )
{
struct V_258 * V_258 ;
int error ;
F_34 ( & V_2 -> V_264 -> V_261 -> V_95 ) ;
V_258 = F_198 ( V_263 , V_2 -> V_264 , strlen ( V_263 ) ) ;
F_35 ( & V_2 -> V_264 -> V_261 -> V_95 ) ;
if ( F_199 ( V_258 ) )
return F_200 ( V_258 ) ;
if ( ! V_258 -> V_261 ) {
error = - V_265 ;
goto V_83;
}
error = F_194 ( V_258 ) ;
if ( ! error )
error = F_185 ( V_258 -> V_261 , type , V_241 ,
V_229 | V_230 ) ;
V_83:
F_201 ( V_258 ) ;
return error ;
}
static inline T_2 F_202 ( T_2 V_266 )
{
return V_266 << V_267 ;
}
static inline T_2 F_203 ( T_2 V_186 )
{
return ( V_186 + V_268 - 1 ) >> V_267 ;
}
static void F_204 ( struct V_30 * V_30 , struct V_269 * V_270 )
{
struct V_271 * V_272 = & V_30 -> V_134 ;
memset ( V_270 , 0 , sizeof( * V_270 ) ) ;
V_270 -> V_273 = V_274 ;
V_270 -> V_275 = V_30 -> V_35 . type == V_156 ?
V_276 : V_277 ;
V_270 -> V_278 = F_205 ( F_206 () , V_30 -> V_35 ) ;
F_5 ( & V_130 ) ;
V_270 -> V_279 = F_203 ( V_272 -> V_189 ) ;
V_270 -> V_280 = F_203 ( V_272 -> V_143 ) ;
V_270 -> V_281 = V_272 -> V_183 ;
V_270 -> V_282 = V_272 -> V_139 ;
V_270 -> V_283 = V_272 -> V_136 + V_272 -> V_137 ;
V_270 -> V_284 = V_272 -> V_135 ;
V_270 -> V_285 = V_272 -> V_144 ;
V_270 -> V_286 = V_272 -> V_140 ;
F_6 ( & V_130 ) ;
}
int F_207 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_269 * V_270 )
{
struct V_30 * V_30 ;
V_30 = F_99 ( V_2 , V_23 ) ;
if ( ! V_30 )
return - V_243 ;
F_204 ( V_30 , V_270 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_208 ( struct V_30 * V_30 , struct V_269 * V_270 )
{
struct V_271 * V_272 = & V_30 -> V_134 ;
int V_287 = 0 , V_288 = 0 ;
struct V_175 * V_289 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
if ( V_270 -> V_290 & ~ V_291 )
return - V_232 ;
if ( ( ( V_270 -> V_290 & V_292 ) &&
( V_270 -> V_280 > V_289 -> V_293 ) ) ||
( ( V_270 -> V_290 & V_294 ) &&
( V_270 -> V_279 > V_289 -> V_293 ) ) ||
( ( V_270 -> V_290 & V_295 ) &&
( V_270 -> V_282 > V_289 -> V_296 ) ) ||
( ( V_270 -> V_290 & V_297 ) &&
( V_270 -> V_281 > V_289 -> V_296 ) ) )
return - V_298 ;
F_5 ( & V_130 ) ;
if ( V_270 -> V_290 & V_299 ) {
V_272 -> V_136 = V_270 -> V_283 - V_272 -> V_137 ;
V_287 = 1 ;
F_49 ( V_300 + V_301 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_292 )
V_272 -> V_143 = F_202 ( V_270 -> V_280 ) ;
if ( V_270 -> V_290 & V_294 )
V_272 -> V_189 = F_202 ( V_270 -> V_279 ) ;
if ( V_270 -> V_290 & ( V_292 | V_294 ) ) {
V_287 = 1 ;
F_49 ( V_300 + V_302 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_303 ) {
V_272 -> V_135 = V_270 -> V_284 ;
V_288 = 1 ;
F_49 ( V_300 + V_304 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_295 )
V_272 -> V_139 = V_270 -> V_282 ;
if ( V_270 -> V_290 & V_297 )
V_272 -> V_183 = V_270 -> V_281 ;
if ( V_270 -> V_290 & ( V_295 | V_297 ) ) {
V_288 = 1 ;
F_49 ( V_300 + V_305 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_306 ) {
V_272 -> V_144 = V_270 -> V_285 ;
V_287 = 1 ;
F_49 ( V_300 + V_307 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_308 ) {
V_272 -> V_140 = V_270 -> V_286 ;
V_288 = 1 ;
F_49 ( V_300 + V_309 , & V_30 -> V_48 ) ;
}
if ( V_287 ) {
if ( ! V_272 -> V_143 ||
V_272 -> V_136 < V_272 -> V_143 ) {
V_272 -> V_144 = 0 ;
F_58 ( V_145 , & V_30 -> V_48 ) ;
} else if ( ! ( V_270 -> V_290 & V_306 ) )
V_272 -> V_144 = F_140 () + V_289 -> V_190 ;
}
if ( V_288 ) {
if ( ! V_272 -> V_139 ||
V_272 -> V_135 < V_272 -> V_139 ) {
V_272 -> V_140 = 0 ;
F_58 ( V_142 , & V_30 -> V_48 ) ;
} else if ( ! ( V_270 -> V_290 & V_308 ) )
V_272 -> V_140 = F_140 () + V_289 -> V_185 ;
}
if ( V_272 -> V_189 || V_272 -> V_143 || V_272 -> V_183 ||
V_272 -> V_139 )
F_58 ( V_182 , & V_30 -> V_48 ) ;
else
F_49 ( V_182 , & V_30 -> V_48 ) ;
F_6 ( & V_130 ) ;
F_38 ( V_30 ) ;
return 0 ;
}
int F_209 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_269 * V_270 )
{
struct V_30 * V_30 ;
int V_310 ;
V_30 = F_99 ( V_2 , V_23 ) ;
if ( ! V_30 ) {
V_310 = - V_243 ;
goto V_83;
}
V_310 = F_208 ( V_30 , V_270 ) ;
F_45 ( V_30 ) ;
V_83:
return V_310 ;
}
int F_210 ( struct V_1 * V_2 , int type , struct V_311 * V_312 )
{
struct V_175 * V_313 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_74 ( V_2 , type ) ) {
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return - V_243 ;
}
V_313 = F_42 ( V_2 ) -> V_53 + type ;
F_5 ( & V_130 ) ;
V_312 -> V_190 = V_313 -> V_190 ;
V_312 -> V_185 = V_313 -> V_185 ;
V_312 -> V_58 = V_313 -> V_58 & V_314 ;
V_312 -> V_315 = V_316 ;
F_6 ( & V_130 ) ;
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return 0 ;
}
int F_211 ( struct V_1 * V_2 , int type , struct V_311 * V_312 )
{
struct V_175 * V_313 ;
int V_55 = 0 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_74 ( V_2 , type ) ) {
V_55 = - V_243 ;
goto V_83;
}
V_313 = F_42 ( V_2 ) -> V_53 + type ;
F_5 ( & V_130 ) ;
if ( V_312 -> V_315 & V_317 )
V_313 -> V_190 = V_312 -> V_190 ;
if ( V_312 -> V_315 & V_318 )
V_313 -> V_185 = V_312 -> V_185 ;
if ( V_312 -> V_315 & V_319 )
V_313 -> V_58 = ( V_313 -> V_58 & ~ V_320 ) |
( V_312 -> V_58 & V_320 ) ;
F_6 ( & V_130 ) ;
F_48 ( V_2 , type ) ;
V_2 -> V_49 -> V_87 ( V_2 , type ) ;
V_83:
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_55 ;
}
static int F_212 ( struct V_321 * V_322 , int V_323 ,
void T_3 * V_324 , T_4 * V_325 , T_5 * V_326 )
{
unsigned int type = ( int * ) V_322 -> V_327 - V_104 . V_328 ;
V_104 . V_328 [ type ] =
F_213 ( & V_104 . V_105 [ type ] ) ;
return F_214 ( V_322 , V_323 , V_324 , V_325 , V_326 ) ;
}
static int T_6 F_215 ( void )
{
int V_172 , V_51 ;
unsigned long V_329 , V_330 ;
F_3 ( V_331 L_19 , V_332 ) ;
F_216 ( V_333 ) ;
V_73 = F_217 ( L_20 ,
sizeof( struct V_30 ) , sizeof( unsigned long ) * 4 ,
( V_334 | V_335 |
V_336 | V_337 ) ,
NULL ) ;
V_330 = 0 ;
V_33 = (struct V_31 * ) F_218 ( V_338 , V_330 ) ;
if ( ! V_33 )
F_219 ( L_21 ) ;
for ( V_172 = 0 ; V_172 < V_339 ; V_172 ++ ) {
V_51 = F_220 ( & V_104 . V_105 [ V_172 ] , 0 , V_340 ) ;
if ( V_51 )
F_219 ( L_22 ) ;
}
V_329 = ( 1UL << V_330 ) * V_341 / sizeof( struct V_31 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( V_329 >> V_28 );
V_28 -- ;
V_329 = 1UL << V_28 ;
V_29 = V_329 - 1 ;
for ( V_172 = 0 ; V_172 < V_329 ; V_172 ++ )
F_221 ( V_33 + V_172 ) ;
F_3 ( L_23 ,
V_329 , V_330 , ( V_341 << V_330 ) ) ;
F_222 ( & V_342 ) ;
return 0 ;
}

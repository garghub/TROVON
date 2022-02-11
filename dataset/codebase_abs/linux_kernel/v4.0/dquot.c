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
int V_56 ;
if ( F_102 ( V_116 ) )
return 0 ;
if ( type != - 1 )
return ! F_100 ( V_116 ) [ type ] ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ! F_100 ( V_116 ) [ V_56 ] )
return 1 ;
return 0 ;
}
static void F_103 ( struct V_1 * V_2 , int type )
{
struct V_116 * V_116 , * V_119 = NULL ;
#ifdef F_84
int V_120 = 0 ;
#endif
F_5 ( & V_121 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_116 -> V_122 ) ;
if ( ( V_116 -> V_123 & ( V_124 | V_125 | V_126 ) ) ||
! F_57 ( & V_116 -> V_127 ) ||
! F_101 ( V_116 , type ) ) {
F_6 ( & V_116 -> V_122 ) ;
continue;
}
F_104 ( V_116 ) ;
F_6 ( & V_116 -> V_122 ) ;
F_6 ( & V_121 ) ;
#ifdef F_84
if ( F_105 ( F_106 ( V_116 ) > 0 ) )
V_120 = 1 ;
#endif
F_107 ( V_119 ) ;
F_108 ( V_116 , type ) ;
V_119 = V_116 ;
F_5 ( & V_121 ) ;
}
F_6 ( & V_121 ) ;
F_107 ( V_119 ) ;
#ifdef F_84
if ( V_120 ) {
F_85 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static void F_109 ( struct V_116 * V_116 , int type ,
struct V_84 * V_128 )
{
struct V_30 * V_30 = F_100 ( V_116 ) [ type ] ;
F_100 ( V_116 ) [ type ] = NULL ;
if ( ! V_30 )
return;
if ( F_27 ( & V_30 -> V_40 ) ) {
F_5 ( & V_11 ) ;
F_41 ( & V_30 -> V_40 , V_128 ) ;
F_6 ( & V_11 ) ;
} else {
F_45 ( V_30 ) ;
}
}
static void F_110 ( struct V_84 * V_128 )
{
struct V_84 * V_129 ;
struct V_30 * V_30 ;
V_129 = V_128 -> V_130 ;
while ( V_129 != V_128 ) {
V_30 = F_80 ( V_129 , struct V_30 , V_40 ) ;
V_129 = V_129 -> V_130 ;
F_28 ( & V_30 -> V_40 ) ;
F_45 ( V_30 ) ;
}
}
static void F_111 ( struct V_1 * V_2 , int type ,
struct V_84 * V_128 )
{
struct V_116 * V_116 ;
int V_120 = 0 ;
F_5 ( & V_121 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_131 ) ;
if ( ! F_102 ( V_116 ) ) {
if ( F_105 ( F_106 ( V_116 ) > 0 ) )
V_120 = 1 ;
F_109 ( V_116 , type , V_128 ) ;
}
F_6 ( & V_131 ) ;
}
F_6 ( & V_121 ) ;
#ifdef F_84
if ( V_120 ) {
F_3 ( V_132 L_8
L_9
L_10 , V_2 -> V_9 ) ;
}
#endif
}
static void F_112 ( struct V_1 * V_2 , int type )
{
F_113 ( V_128 ) ;
if ( V_2 -> V_49 ) {
F_111 ( V_2 , type , & V_128 ) ;
F_114 ( & V_133 ) ;
F_110 ( & V_128 ) ;
}
}
static inline void F_115 ( struct V_30 * V_30 , T_2 V_134 )
{
V_30 -> V_135 . V_136 += V_134 ;
}
static inline void F_116 ( struct V_30 * V_30 , T_2 V_134 )
{
V_30 -> V_135 . V_137 += V_134 ;
}
static inline void F_117 ( struct V_30 * V_30 , T_2 V_134 )
{
V_30 -> V_135 . V_138 += V_134 ;
}
static void F_118 ( struct V_30 * V_30 , T_2 V_134 )
{
if ( V_30 -> V_135 . V_138 < V_134 ) {
F_119 ( 1 ) ;
V_134 = V_30 -> V_135 . V_138 ;
}
V_30 -> V_135 . V_137 += V_134 ;
V_30 -> V_135 . V_138 -= V_134 ;
}
static void F_120 ( struct V_30 * V_30 , T_2 V_134 )
{
if ( F_119 ( V_30 -> V_135 . V_137 < V_134 ) )
V_134 = V_30 -> V_135 . V_137 ;
V_30 -> V_135 . V_138 += V_134 ;
V_30 -> V_135 . V_137 -= V_134 ;
}
static inline
void F_121 ( struct V_30 * V_30 , T_2 V_134 )
{
if ( V_30 -> V_135 . V_138 >= V_134 )
V_30 -> V_135 . V_138 -= V_134 ;
else {
F_119 ( 1 ) ;
V_30 -> V_135 . V_138 = 0 ;
}
}
static void F_122 ( struct V_30 * V_30 , T_2 V_134 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_139 ||
V_30 -> V_135 . V_136 >= V_134 )
V_30 -> V_135 . V_136 -= V_134 ;
else
V_30 -> V_135 . V_136 = 0 ;
if ( V_30 -> V_135 . V_136 <= V_30 -> V_135 . V_140 )
V_30 -> V_135 . V_141 = ( V_142 ) 0 ;
F_58 ( V_143 , & V_30 -> V_48 ) ;
}
static void F_123 ( struct V_30 * V_30 , T_2 V_134 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_139 ||
V_30 -> V_135 . V_137 >= V_134 )
V_30 -> V_135 . V_137 -= V_134 ;
else
V_30 -> V_135 . V_137 = 0 ;
if ( V_30 -> V_135 . V_137 <= V_30 -> V_135 . V_144 )
V_30 -> V_135 . V_145 = ( V_142 ) 0 ;
F_58 ( V_146 , & V_30 -> V_48 ) ;
}
static int F_124 ( struct V_30 * V_30 , const int V_147 )
{
int V_148 = ( V_147 == V_149 ||
V_147 == V_150 ) ? V_146 :
( ( V_147 == V_151 ||
V_147 == V_152 ) ? V_143 : 0 ) ;
if ( ! V_148 )
return 0 ;
return F_40 ( V_148 , & V_30 -> V_48 ) ;
}
static int F_125 ( struct V_153 * V_154 )
{
if ( ! V_155 )
return 0 ;
switch ( V_154 -> V_156 . type ) {
case V_157 :
return F_126 ( F_127 () , V_154 -> V_156 . V_158 ) ;
case V_159 :
return F_128 ( V_154 -> V_156 . V_160 ) ;
case V_161 :
return 0 ;
}
return 0 ;
}
static void F_129 ( struct V_153 * V_154 )
{
char * V_162 = NULL ;
struct V_163 * V_164 ;
int V_147 = V_154 -> V_165 ;
if ( V_147 == V_166 ||
V_147 == V_167 ||
V_147 == V_168 ||
V_147 == V_169 || ! F_125 ( V_154 ) )
return;
V_164 = F_130 () ;
if ( ! V_164 )
return;
F_131 ( V_164 , V_154 -> V_170 -> V_9 ) ;
if ( V_147 == V_171 || V_147 == V_172 )
F_131 ( V_164 , L_11 ) ;
else
F_131 ( V_164 , L_12 ) ;
F_131 ( V_164 , V_106 [ V_154 -> V_156 . type ] ) ;
switch ( V_147 ) {
case V_151 :
V_162 = L_13 ;
break;
case V_152 :
V_162 = L_14 ;
break;
case V_171 :
V_162 = L_15 ;
break;
case V_149 :
V_162 = L_16 ;
break;
case V_150 :
V_162 = L_17 ;
break;
case V_172 :
V_162 = L_18 ;
break;
}
F_131 ( V_164 , V_162 ) ;
F_132 ( V_164 ) ;
}
static void F_133 ( struct V_153 * V_154 , struct V_30 * V_30 ,
int V_147 )
{
if ( F_124 ( V_30 , V_147 ) )
return;
V_154 -> V_165 = V_147 ;
V_154 -> V_170 = V_30 -> V_34 ;
V_154 -> V_156 = V_30 -> V_35 ;
}
static void F_134 ( struct V_153 * V_154 )
{
int V_173 ;
for ( V_173 = 0 ; V_173 < V_27 ; V_173 ++ ) {
if ( V_154 [ V_173 ] . V_165 == V_174 )
continue;
#ifdef F_135
F_129 ( & V_154 [ V_173 ] ) ;
#endif
F_136 ( V_154 [ V_173 ] . V_156 ,
V_154 [ V_173 ] . V_170 -> V_175 , V_154 [ V_173 ] . V_165 ) ;
}
}
static int F_137 ( struct V_30 * V_30 )
{
struct V_176 * V_53 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
return F_138 ( V_177 ) &&
( V_53 -> V_178 -> V_16 != V_179 ||
! ( V_53 -> V_58 & V_180 ) ) ;
}
static int F_139 ( struct V_30 * V_30 , T_2 V_181 ,
struct V_153 * V_154 )
{
T_2 V_182 = V_30 -> V_135 . V_136 + V_181 ;
if ( ! F_140 ( V_30 -> V_34 , V_30 -> V_35 . type ) ||
F_37 ( V_183 , & V_30 -> V_48 ) )
return 0 ;
if ( V_30 -> V_135 . V_184 &&
V_182 > V_30 -> V_135 . V_184 &&
! F_137 ( V_30 ) ) {
F_133 ( V_154 , V_30 , V_151 ) ;
return - V_185 ;
}
if ( V_30 -> V_135 . V_140 &&
V_182 > V_30 -> V_135 . V_140 &&
V_30 -> V_135 . V_141 &&
F_141 () >= V_30 -> V_135 . V_141 &&
! F_137 ( V_30 ) ) {
F_133 ( V_154 , V_30 , V_152 ) ;
return - V_185 ;
}
if ( V_30 -> V_135 . V_140 &&
V_182 > V_30 -> V_135 . V_140 &&
V_30 -> V_135 . V_141 == 0 ) {
F_133 ( V_154 , V_30 , V_171 ) ;
V_30 -> V_135 . V_141 = F_141 () +
F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] . V_186 ;
}
return 0 ;
}
static int F_142 ( struct V_30 * V_30 , T_2 V_187 , int V_188 ,
struct V_153 * V_154 )
{
T_2 V_189 ;
struct V_1 * V_2 = V_30 -> V_34 ;
if ( ! F_140 ( V_2 , V_30 -> V_35 . type ) ||
F_37 ( V_183 , & V_30 -> V_48 ) )
return 0 ;
V_189 = V_30 -> V_135 . V_137 + V_30 -> V_135 . V_138
+ V_187 ;
if ( V_30 -> V_135 . V_190 &&
V_189 > V_30 -> V_135 . V_190 &&
! F_137 ( V_30 ) ) {
if ( ! V_188 )
F_133 ( V_154 , V_30 , V_149 ) ;
return - V_185 ;
}
if ( V_30 -> V_135 . V_144 &&
V_189 > V_30 -> V_135 . V_144 &&
V_30 -> V_135 . V_145 &&
F_141 () >= V_30 -> V_135 . V_145 &&
! F_137 ( V_30 ) ) {
if ( ! V_188 )
F_133 ( V_154 , V_30 , V_150 ) ;
return - V_185 ;
}
if ( V_30 -> V_135 . V_144 &&
V_189 > V_30 -> V_135 . V_144 &&
V_30 -> V_135 . V_145 == 0 ) {
if ( ! V_188 ) {
F_133 ( V_154 , V_30 , V_172 ) ;
V_30 -> V_135 . V_145 = F_141 () +
F_42 ( V_2 ) -> V_53 [ V_30 -> V_35 . type ] . V_191 ;
}
else
return - V_185 ;
}
return 0 ;
}
static int F_143 ( struct V_30 * V_30 , T_2 V_181 )
{
T_2 V_182 ;
if ( F_37 ( V_183 , & V_30 -> V_48 ) ||
V_30 -> V_135 . V_136 <= V_30 -> V_135 . V_140 ||
! F_140 ( V_30 -> V_34 , V_30 -> V_35 . type ) )
return V_174 ;
V_182 = V_30 -> V_135 . V_136 - V_181 ;
if ( V_182 <= V_30 -> V_135 . V_140 )
return V_167 ;
if ( V_30 -> V_135 . V_136 >= V_30 -> V_135 . V_184 &&
V_182 < V_30 -> V_135 . V_184 )
return V_166 ;
return V_174 ;
}
static int F_144 ( struct V_30 * V_30 , T_2 V_187 )
{
if ( F_37 ( V_183 , & V_30 -> V_48 ) ||
V_30 -> V_135 . V_137 <= V_30 -> V_135 . V_144 )
return V_174 ;
if ( V_30 -> V_135 . V_137 - V_187 <= V_30 -> V_135 . V_144 )
return V_169 ;
if ( V_30 -> V_135 . V_137 >= V_30 -> V_135 . V_190 &&
V_30 -> V_135 . V_137 - V_187 < V_30 -> V_135 . V_190 )
return V_168 ;
return V_174 ;
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
int V_56 , V_192 = 0 ;
struct V_30 * V_193 [ V_27 ] ;
struct V_1 * V_2 = V_116 -> V_117 ;
T_2 V_194 ;
if ( ! F_145 ( V_116 ) )
return;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
struct V_22 V_23 ;
V_193 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( F_100 ( V_116 ) [ V_56 ] )
continue;
V_192 = 1 ;
switch ( V_56 ) {
case V_157 :
V_23 = F_148 ( V_116 -> V_195 ) ;
break;
case V_159 :
V_23 = F_149 ( V_116 -> V_196 ) ;
break;
}
V_193 [ V_56 ] = F_99 ( V_2 , V_23 ) ;
}
if ( ! V_192 )
return;
F_5 ( & V_131 ) ;
if ( F_102 ( V_116 ) )
goto V_197;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_74 ( V_2 , V_56 ) )
continue;
if ( ! V_193 [ V_56 ] )
continue;
if ( ! F_100 ( V_116 ) [ V_56 ] ) {
F_100 ( V_116 ) [ V_56 ] = V_193 [ V_56 ] ;
V_193 [ V_56 ] = NULL ;
V_194 = F_106 ( V_116 ) ;
if ( F_105 ( V_194 ) )
F_117 ( F_100 ( V_116 ) [ V_56 ] , V_194 ) ;
}
}
V_197:
F_6 ( & V_131 ) ;
F_44 ( V_193 ) ;
}
void F_150 ( struct V_116 * V_116 )
{
F_108 ( V_116 , - 1 ) ;
}
static void F_151 ( struct V_116 * V_116 )
{
int V_56 ;
struct V_30 * V_198 [ V_27 ] ;
F_5 ( & V_131 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_198 [ V_56 ] = F_100 ( V_116 ) [ V_56 ] ;
F_100 ( V_116 ) [ V_56 ] = NULL ;
}
F_6 ( & V_131 ) ;
F_44 ( V_198 ) ;
}
void F_152 ( struct V_116 * V_116 )
{
int V_56 ;
if ( F_102 ( V_116 ) )
return;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( F_100 ( V_116 ) [ V_56 ] )
break;
}
if ( V_56 < V_27 )
F_151 ( V_116 ) ;
}
static T_2 * F_153 ( struct V_116 * V_116 )
{
F_89 ( ! V_116 -> V_117 -> V_49 -> V_199 ) ;
return V_116 -> V_117 -> V_49 -> V_199 ( V_116 ) ;
}
void F_154 ( struct V_116 * V_116 , T_2 V_134 )
{
F_5 ( & V_116 -> V_122 ) ;
* F_153 ( V_116 ) += V_134 ;
F_6 ( & V_116 -> V_122 ) ;
}
void F_155 ( struct V_116 * V_116 , T_2 V_134 )
{
F_5 ( & V_116 -> V_122 ) ;
* F_153 ( V_116 ) -= V_134 ;
F_156 ( V_116 , V_134 ) ;
F_6 ( & V_116 -> V_122 ) ;
}
void F_157 ( struct V_116 * V_116 , T_2 V_134 )
{
F_5 ( & V_116 -> V_122 ) ;
* F_153 ( V_116 ) += V_134 ;
F_158 ( V_116 , V_134 ) ;
F_6 ( & V_116 -> V_122 ) ;
}
void F_159 ( struct V_116 * V_116 , T_2 V_134 )
{
F_5 ( & V_116 -> V_122 ) ;
* F_153 ( V_116 ) -= V_134 ;
F_6 ( & V_116 -> V_122 ) ;
}
static T_2 F_106 ( struct V_116 * V_116 )
{
T_2 V_51 ;
if ( ! V_116 -> V_117 -> V_49 -> V_199 )
return 0 ;
F_5 ( & V_116 -> V_122 ) ;
V_51 = * F_153 ( V_116 ) ;
F_6 ( & V_116 -> V_122 ) ;
return V_51 ;
}
static void F_160 ( struct V_116 * V_116 , T_2 V_134 ,
int V_200 )
{
if ( V_200 )
F_154 ( V_116 , V_134 ) ;
else
F_161 ( V_116 , V_134 ) ;
}
static void F_162 ( struct V_116 * V_116 , T_2 V_134 , int V_200 )
{
if ( V_200 )
F_159 ( V_116 , V_134 ) ;
else
F_163 ( V_116 , V_134 ) ;
}
int F_164 ( struct V_116 * V_116 , T_2 V_134 , int V_89 )
{
int V_56 , V_51 = 0 , V_201 ;
struct V_153 V_154 [ V_27 ] ;
struct V_30 * * V_202 = F_100 ( V_116 ) ;
int V_200 = V_89 & V_203 ;
if ( ! F_145 ( V_116 ) ) {
F_160 ( V_116 , V_134 , V_200 ) ;
goto V_83;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_154 [ V_56 ] . V_165 = V_174 ;
V_201 = F_165 ( & V_133 ) ;
F_5 ( & V_131 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
V_51 = F_142 ( V_202 [ V_56 ] , V_134 ,
! ( V_89 & V_204 ) , & V_154 [ V_56 ] ) ;
if ( V_51 && ! ( V_89 & V_205 ) ) {
F_6 ( & V_131 ) ;
goto V_206;
}
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
if ( V_200 )
F_117 ( V_202 [ V_56 ] , V_134 ) ;
else
F_116 ( V_202 [ V_56 ] , V_134 ) ;
}
F_160 ( V_116 , V_134 , V_200 ) ;
F_6 ( & V_131 ) ;
if ( V_200 )
goto V_206;
F_43 ( V_202 ) ;
V_206:
F_166 ( & V_133 , V_201 ) ;
F_134 ( V_154 ) ;
V_83:
return V_51 ;
}
int F_167 ( struct V_116 * V_116 )
{
int V_56 , V_51 = 0 , V_201 ;
struct V_153 V_154 [ V_27 ] ;
struct V_30 * const * V_202 = F_100 ( V_116 ) ;
if ( ! F_145 ( V_116 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_154 [ V_56 ] . V_165 = V_174 ;
V_201 = F_165 ( & V_133 ) ;
F_5 ( & V_131 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
V_51 = F_139 ( V_202 [ V_56 ] , 1 , & V_154 [ V_56 ] ) ;
if ( V_51 )
goto V_207;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
F_115 ( V_202 [ V_56 ] , 1 ) ;
}
V_207:
F_6 ( & V_131 ) ;
if ( V_51 == 0 )
F_43 ( V_202 ) ;
F_166 ( & V_133 , V_201 ) ;
F_134 ( V_154 ) ;
return V_51 ;
}
int F_168 ( struct V_116 * V_116 , T_2 V_134 )
{
int V_56 , V_201 ;
if ( ! F_145 ( V_116 ) ) {
F_155 ( V_116 , V_134 ) ;
return 0 ;
}
V_201 = F_165 ( & V_133 ) ;
F_5 ( & V_131 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( F_100 ( V_116 ) [ V_56 ] )
F_118 ( F_100 ( V_116 ) [ V_56 ] ,
V_134 ) ;
}
F_155 ( V_116 , V_134 ) ;
F_6 ( & V_131 ) ;
F_43 ( F_100 ( V_116 ) ) ;
F_166 ( & V_133 , V_201 ) ;
return 0 ;
}
void F_169 ( struct V_116 * V_116 , T_2 V_134 )
{
int V_56 , V_201 ;
if ( ! F_145 ( V_116 ) ) {
F_157 ( V_116 , V_134 ) ;
return;
}
V_201 = F_165 ( & V_133 ) ;
F_5 ( & V_131 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( F_100 ( V_116 ) [ V_56 ] )
F_120 ( F_100 ( V_116 ) [ V_56 ] ,
V_134 ) ;
}
F_157 ( V_116 , V_134 ) ;
F_6 ( & V_131 ) ;
F_43 ( F_100 ( V_116 ) ) ;
F_166 ( & V_133 , V_201 ) ;
return;
}
void F_170 ( struct V_116 * V_116 , T_2 V_134 , int V_89 )
{
unsigned int V_56 ;
struct V_153 V_154 [ V_27 ] ;
struct V_30 * * V_202 = F_100 ( V_116 ) ;
int V_200 = V_89 & V_203 , V_201 ;
if ( ! F_145 ( V_116 ) ) {
F_162 ( V_116 , V_134 , V_200 ) ;
return;
}
V_201 = F_165 ( & V_133 ) ;
F_5 ( & V_131 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_208 ;
V_154 [ V_56 ] . V_165 = V_174 ;
if ( ! V_202 [ V_56 ] )
continue;
V_208 = F_144 ( V_202 [ V_56 ] , V_134 ) ;
if ( V_208 != V_174 )
F_133 ( & V_154 [ V_56 ] , V_202 [ V_56 ] , V_208 ) ;
if ( V_200 )
F_121 ( V_202 [ V_56 ] , V_134 ) ;
else
F_123 ( V_202 [ V_56 ] , V_134 ) ;
}
F_162 ( V_116 , V_134 , V_200 ) ;
F_6 ( & V_131 ) ;
if ( V_200 )
goto V_209;
F_43 ( V_202 ) ;
V_209:
F_166 ( & V_133 , V_201 ) ;
F_134 ( V_154 ) ;
}
void F_171 ( struct V_116 * V_116 )
{
unsigned int V_56 ;
struct V_153 V_154 [ V_27 ] ;
struct V_30 * const * V_202 = F_100 ( V_116 ) ;
int V_201 ;
if ( ! F_145 ( V_116 ) )
return;
V_201 = F_165 ( & V_133 ) ;
F_5 ( & V_131 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_208 ;
V_154 [ V_56 ] . V_165 = V_174 ;
if ( ! V_202 [ V_56 ] )
continue;
V_208 = F_143 ( V_202 [ V_56 ] , 1 ) ;
if ( V_208 != V_174 )
F_133 ( & V_154 [ V_56 ] , V_202 [ V_56 ] , V_208 ) ;
F_122 ( V_202 [ V_56 ] , 1 ) ;
}
F_6 ( & V_131 ) ;
F_43 ( V_202 ) ;
F_166 ( & V_133 , V_201 ) ;
F_134 ( V_154 ) ;
}
int F_172 ( struct V_116 * V_116 , struct V_30 * * V_210 )
{
T_2 V_187 , V_211 ;
T_2 V_212 = 0 ;
struct V_30 * V_213 [ V_27 ] = {} ;
int V_56 , V_51 = 0 ;
char V_214 [ V_27 ] = {} ;
struct V_153 V_215 [ V_27 ] ;
struct V_153 V_216 [ V_27 ] ;
struct V_153 V_217 [ V_27 ] ;
if ( F_102 ( V_116 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_215 [ V_56 ] . V_165 = V_174 ;
V_216 [ V_56 ] . V_165 = V_174 ;
V_217 [ V_56 ] . V_165 = V_174 ;
}
F_5 ( & V_131 ) ;
if ( F_102 ( V_116 ) ) {
F_6 ( & V_131 ) ;
return 0 ;
}
V_211 = F_173 ( V_116 ) ;
V_212 = F_106 ( V_116 ) ;
V_187 = V_211 + V_212 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_210 [ V_56 ] )
continue;
if ( ! F_74 ( V_116 -> V_117 , V_56 ) )
continue;
V_214 [ V_56 ] = 1 ;
V_213 [ V_56 ] = F_100 ( V_116 ) [ V_56 ] ;
V_51 = F_139 ( V_210 [ V_56 ] , 1 , & V_215 [ V_56 ] ) ;
if ( V_51 )
goto V_218;
V_51 = F_142 ( V_210 [ V_56 ] , V_187 , 0 , & V_215 [ V_56 ] ) ;
if ( V_51 )
goto V_218;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_214 [ V_56 ] )
continue;
if ( V_213 [ V_56 ] ) {
int V_208 ;
V_208 = F_143 ( V_213 [ V_56 ] , 1 ) ;
if ( V_208 != V_174 )
F_133 ( & V_216 [ V_56 ] ,
V_213 [ V_56 ] , V_208 ) ;
V_208 = F_144 ( V_213 [ V_56 ] , V_187 ) ;
if ( V_208 != V_174 )
F_133 ( & V_217 [ V_56 ] ,
V_213 [ V_56 ] , V_208 ) ;
F_122 ( V_213 [ V_56 ] , 1 ) ;
F_123 ( V_213 [ V_56 ] , V_211 ) ;
F_121 ( V_213 [ V_56 ] ,
V_212 ) ;
}
F_115 ( V_210 [ V_56 ] , 1 ) ;
F_116 ( V_210 [ V_56 ] , V_211 ) ;
F_117 ( V_210 [ V_56 ] , V_212 ) ;
F_100 ( V_116 ) [ V_56 ] = V_210 [ V_56 ] ;
}
F_6 ( & V_131 ) ;
F_43 ( V_213 ) ;
F_43 ( V_210 ) ;
F_134 ( V_215 ) ;
F_134 ( V_216 ) ;
F_134 ( V_217 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_214 [ V_56 ] )
V_210 [ V_56 ] = V_213 [ V_56 ] ;
return 0 ;
V_218:
F_6 ( & V_131 ) ;
F_134 ( V_215 ) ;
return V_51 ;
}
int F_174 ( struct V_116 * V_116 , struct V_219 * V_219 )
{
struct V_30 * V_210 [ V_27 ] = {} ;
struct V_1 * V_2 = V_116 -> V_117 ;
int V_51 ;
if ( ! F_145 ( V_116 ) )
return 0 ;
if ( V_219 -> V_220 & V_221 && ! F_126 ( V_219 -> V_222 , V_116 -> V_195 ) )
V_210 [ V_157 ] = F_99 ( V_2 , F_148 ( V_219 -> V_222 ) ) ;
if ( V_219 -> V_220 & V_223 && ! F_175 ( V_219 -> V_224 , V_116 -> V_196 ) )
V_210 [ V_159 ] = F_99 ( V_2 , F_149 ( V_219 -> V_224 ) ) ;
V_51 = F_172 ( V_116 , V_210 ) ;
F_44 ( V_210 ) ;
return V_51 ;
}
int F_176 ( struct V_1 * V_2 , int type )
{
int V_51 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_34 ( & V_61 -> V_62 ) ;
V_51 = V_61 -> V_64 [ type ] -> F_54 ( V_2 , type ) ;
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_177 ( struct V_116 * V_116 , struct V_225 * V_225 )
{
int error ;
error = F_178 ( V_116 , V_225 ) ;
if ( ! error && ( V_225 -> V_226 & V_227 ) )
F_150 ( V_116 ) ;
return error ;
}
int F_179 ( struct V_1 * V_2 , int type , unsigned int V_89 )
{
int V_56 , V_51 = 0 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_116 * V_228 [ V_27 ] ;
if ( ( V_89 & V_229 && ! ( V_89 & V_230 ) )
|| ( V_89 & V_231 && V_89 & ( V_230 |
V_229 ) ) )
return - V_232 ;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_146 ( V_2 ) ) {
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_228 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_180 ( V_2 , V_56 ) )
continue;
if ( V_89 & V_231 ) {
F_5 ( & V_113 ) ;
V_61 -> V_89 |=
F_181 ( V_231 , V_56 ) ;
F_6 ( & V_113 ) ;
} else {
F_5 ( & V_113 ) ;
V_61 -> V_89 &= ~ F_181 ( V_89 , V_56 ) ;
if ( ! F_180 ( V_2 , V_56 ) &&
F_182 ( V_2 , V_56 ) ) {
V_61 -> V_89 &= ~ F_181 (
V_231 , V_56 ) ;
F_6 ( & V_113 ) ;
F_107 ( V_61 -> V_94 [ V_56 ] ) ;
V_61 -> V_94 [ V_56 ] = NULL ;
continue;
}
F_6 ( & V_113 ) ;
}
if ( F_180 ( V_2 , V_56 ) && ! ( V_89 & V_231 ) )
continue;
F_112 ( V_2 , V_56 ) ;
F_62 ( V_2 , V_56 ) ;
if ( F_53 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
if ( V_61 -> V_64 [ V_56 ] -> V_233 )
V_61 -> V_64 [ V_56 ] -> V_233 ( V_2 , V_56 ) ;
F_11 ( V_61 -> V_53 [ V_56 ] . V_178 ) ;
V_228 [ V_56 ] = V_61 -> V_94 [ V_56 ] ;
if ( ! F_180 ( V_2 , V_56 ) )
V_61 -> V_94 [ V_56 ] = NULL ;
V_61 -> V_53 [ V_56 ] . V_58 = 0 ;
V_61 -> V_53 [ V_56 ] . V_186 = 0 ;
V_61 -> V_53 [ V_56 ] . V_191 = 0 ;
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
if ( ! F_180 ( V_2 , V_56 ) ) {
F_34 ( & V_228 [ V_56 ] -> V_95 ) ;
V_228 [ V_56 ] -> V_235 &= ~ ( V_236 |
V_237 | V_238 ) ;
F_78 ( & V_228 [ V_56 ] -> V_96 ,
0 ) ;
F_35 ( & V_228 [ V_56 ] -> V_95 ) ;
F_183 ( V_228 [ V_56 ] ) ;
}
F_35 ( & V_61 -> V_81 ) ;
}
if ( V_2 -> V_93 )
F_184 ( V_2 -> V_93 ) ;
V_234:
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_228 [ V_56 ] ) {
if ( ! ( V_89 & V_231 ) )
F_107 ( V_228 [ V_56 ] ) ;
else if ( ! V_228 [ V_56 ] -> V_239 )
V_51 = - V_240 ;
}
return V_51 ;
}
int F_185 ( struct V_1 * V_2 , int type )
{
return F_179 ( V_2 , type ,
V_229 | V_230 ) ;
}
static int F_186 ( struct V_116 * V_116 , int type , int V_241 ,
unsigned int V_89 )
{
struct V_10 * V_4 = F_8 ( V_241 ) ;
struct V_1 * V_2 = V_116 -> V_117 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int error ;
int V_242 = - 1 ;
if ( ! V_4 )
return - V_243 ;
if ( ! F_187 ( V_116 -> V_244 ) ) {
error = - V_245 ;
goto V_246;
}
if ( F_188 ( V_116 ) ) {
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
F_189 ( V_2 ) ;
F_184 ( V_2 -> V_93 ) ;
}
F_34 ( & V_61 -> V_81 ) ;
if ( F_180 ( V_2 , type ) ) {
error = - V_240 ;
goto V_250;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_34 ( & V_116 -> V_95 ) ;
V_242 = V_116 -> V_235 & ( V_237 | V_236 |
V_238 ) ;
V_116 -> V_235 |= V_238 | V_237 | V_236 ;
F_35 ( & V_116 -> V_95 ) ;
F_151 ( V_116 ) ;
}
error = - V_69 ;
V_61 -> V_94 [ type ] = F_190 ( V_116 ) ;
if ( ! V_61 -> V_94 [ type ] )
goto V_250;
error = - V_232 ;
if ( ! V_4 -> V_251 -> V_252 ( V_2 , type ) )
goto V_253;
V_61 -> V_64 [ type ] = V_4 -> V_251 ;
V_61 -> V_53 [ type ] . V_178 = V_4 ;
V_61 -> V_53 [ type ] . V_254 = V_241 ;
F_94 ( & V_61 -> V_53 [ type ] . V_54 ) ;
F_34 ( & V_61 -> V_62 ) ;
error = V_61 -> V_64 [ type ] -> F_191 ( V_2 , type ) ;
if ( error < 0 ) {
F_35 ( & V_61 -> V_62 ) ;
goto V_253;
}
if ( V_61 -> V_89 & V_90 )
V_61 -> V_53 [ type ] . V_58 |= V_255 ;
F_35 ( & V_61 -> V_62 ) ;
F_5 ( & V_113 ) ;
V_61 -> V_89 |= F_181 ( V_89 , type ) ;
F_6 ( & V_113 ) ;
F_103 ( V_2 , type ) ;
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
V_253:
V_61 -> V_94 [ type ] = NULL ;
F_107 ( V_116 ) ;
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
int F_192 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_116 * V_116 ;
int V_51 = 0 , V_56 ;
unsigned int V_89 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_182 ( V_2 , V_56 ) ) {
F_35 ( & V_61 -> V_81 ) ;
continue;
}
V_116 = V_61 -> V_94 [ V_56 ] ;
V_61 -> V_94 [ V_56 ] = NULL ;
F_5 ( & V_113 ) ;
V_89 = V_61 -> V_89 & F_181 ( V_229 |
V_230 ,
V_56 ) ;
V_61 -> V_89 &= ~ F_181 ( V_256 , V_56 ) ;
F_6 ( & V_113 ) ;
F_35 ( & V_61 -> V_81 ) ;
V_89 = F_193 ( V_89 , V_56 ) ;
V_51 = F_186 ( V_116 , V_56 ,
V_61 -> V_53 [ V_56 ] . V_254 , V_89 ) ;
F_107 ( V_116 ) ;
}
return V_51 ;
}
int F_194 ( struct V_1 * V_2 , int type , int V_241 ,
struct V_257 * V_257 )
{
int error = F_195 ( V_257 -> V_258 ) ;
if ( error )
return error ;
if ( V_257 -> V_258 -> V_259 != V_2 )
error = - V_260 ;
else
error = F_186 ( V_257 -> V_258 -> V_261 , type ,
V_241 , V_229 |
V_230 ) ;
return error ;
}
int F_196 ( struct V_116 * V_116 , int type , int V_241 ,
unsigned int V_89 )
{
int V_51 = 0 ;
struct V_1 * V_2 = V_116 -> V_117 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_89 ( V_89 & V_231 ) ;
if ( ! V_89 )
return 0 ;
if ( F_180 ( V_2 , type ) ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_180 ( V_2 , type ) ) {
F_35 ( & V_61 -> V_81 ) ;
goto V_262;
}
if ( V_89 & V_229 &&
F_197 ( V_2 , type ) ) {
V_51 = - V_240 ;
goto V_250;
}
if ( V_89 & V_230 &&
F_140 ( V_2 , type ) ) {
V_51 = - V_240 ;
goto V_250;
}
F_5 ( & V_113 ) ;
F_42 ( V_2 ) -> V_89 |= F_181 ( V_89 , type ) ;
F_6 ( & V_113 ) ;
V_250:
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
V_262:
return F_186 ( V_116 , type , V_241 , V_89 ) ;
}
int F_198 ( struct V_1 * V_2 , char * V_263 ,
int V_241 , int type )
{
struct V_258 * V_258 ;
int error ;
F_34 ( & V_2 -> V_264 -> V_261 -> V_95 ) ;
V_258 = F_199 ( V_263 , V_2 -> V_264 , strlen ( V_263 ) ) ;
F_35 ( & V_2 -> V_264 -> V_261 -> V_95 ) ;
if ( F_200 ( V_258 ) )
return F_201 ( V_258 ) ;
if ( ! V_258 -> V_261 ) {
error = - V_265 ;
goto V_83;
}
error = F_195 ( V_258 ) ;
if ( ! error )
error = F_186 ( V_258 -> V_261 , type , V_241 ,
V_229 | V_230 ) ;
V_83:
F_202 ( V_258 ) ;
return error ;
}
static int F_203 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_266 ;
V_89 &= ~ ( V_267 | V_268 | V_269 ) ;
if ( ! V_89 )
return - V_232 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! ( V_89 & F_204 ( type ) ) )
continue;
if ( ! F_197 ( V_2 , type ) )
return - V_232 ;
V_51 = F_196 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_254 ,
V_230 ) ;
if ( V_51 < 0 )
goto V_197;
}
return 0 ;
V_197:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_204 ( type ) )
F_179 ( V_2 , type , V_230 ) ;
}
if ( V_51 == - V_240 )
V_51 = - V_270 ;
return V_51 ;
}
static int F_205 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_266 ;
if ( V_89 &
( V_267 | V_268 | V_269 ) )
return - V_271 ;
for ( type = 0 ; type < V_27 ; type ++ )
if ( ! F_140 ( V_2 , type ) )
V_89 &= ~ F_204 ( type ) ;
if ( ! V_89 )
return - V_270 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( V_89 & F_204 ( type ) ) {
V_51 = F_179 ( V_2 , type , V_230 ) ;
if ( V_51 < 0 )
goto V_197;
}
}
return 0 ;
V_197:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_204 ( type ) )
F_196 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_254 ,
V_230 ) ;
}
return V_51 ;
}
static void F_206 ( struct V_30 * V_30 , struct V_272 * V_273 )
{
struct V_274 * V_275 = & V_30 -> V_135 ;
memset ( V_273 , 0 , sizeof( * V_273 ) ) ;
F_5 ( & V_131 ) ;
V_273 -> V_276 = V_275 -> V_190 ;
V_273 -> V_277 = V_275 -> V_144 ;
V_273 -> V_278 = V_275 -> V_184 ;
V_273 -> V_279 = V_275 -> V_140 ;
V_273 -> V_280 = V_275 -> V_137 + V_275 -> V_138 ;
V_273 -> V_281 = V_275 -> V_136 ;
V_273 -> V_282 = V_275 -> V_145 ;
V_273 -> V_283 = V_275 -> V_141 ;
F_6 ( & V_131 ) ;
}
int F_207 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_272 * V_273 )
{
struct V_30 * V_30 ;
V_30 = F_99 ( V_2 , V_23 ) ;
if ( ! V_30 )
return - V_243 ;
F_206 ( V_30 , V_273 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_208 ( struct V_30 * V_30 , struct V_272 * V_273 )
{
struct V_274 * V_275 = & V_30 -> V_135 ;
int V_284 = 0 , V_285 = 0 ;
struct V_176 * V_286 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
if ( V_273 -> V_287 & ~ V_288 )
return - V_232 ;
if ( ( ( V_273 -> V_287 & V_289 ) &&
V_273 -> V_277 > V_286 -> V_290 ) ||
( ( V_273 -> V_287 & V_291 ) &&
V_273 -> V_276 > V_286 -> V_290 ) ||
( ( V_273 -> V_287 & V_292 ) &&
( V_273 -> V_279 > V_286 -> V_293 ) ) ||
( ( V_273 -> V_287 & V_294 ) &&
( V_273 -> V_278 > V_286 -> V_293 ) ) )
return - V_295 ;
F_5 ( & V_131 ) ;
if ( V_273 -> V_287 & V_296 ) {
V_275 -> V_137 = V_273 -> V_280 - V_275 -> V_138 ;
V_284 = 1 ;
F_49 ( V_297 + V_298 , & V_30 -> V_48 ) ;
}
if ( V_273 -> V_287 & V_289 )
V_275 -> V_144 = V_273 -> V_277 ;
if ( V_273 -> V_287 & V_291 )
V_275 -> V_190 = V_273 -> V_276 ;
if ( V_273 -> V_287 & ( V_289 | V_291 ) ) {
V_284 = 1 ;
F_49 ( V_297 + V_299 , & V_30 -> V_48 ) ;
}
if ( V_273 -> V_287 & V_300 ) {
V_275 -> V_136 = V_273 -> V_281 ;
V_285 = 1 ;
F_49 ( V_297 + V_301 , & V_30 -> V_48 ) ;
}
if ( V_273 -> V_287 & V_292 )
V_275 -> V_140 = V_273 -> V_279 ;
if ( V_273 -> V_287 & V_294 )
V_275 -> V_184 = V_273 -> V_278 ;
if ( V_273 -> V_287 & ( V_292 | V_294 ) ) {
V_285 = 1 ;
F_49 ( V_297 + V_302 , & V_30 -> V_48 ) ;
}
if ( V_273 -> V_287 & V_303 ) {
V_275 -> V_145 = V_273 -> V_282 ;
V_284 = 1 ;
F_49 ( V_297 + V_304 , & V_30 -> V_48 ) ;
}
if ( V_273 -> V_287 & V_305 ) {
V_275 -> V_141 = V_273 -> V_283 ;
V_285 = 1 ;
F_49 ( V_297 + V_306 , & V_30 -> V_48 ) ;
}
if ( V_284 ) {
if ( ! V_275 -> V_144 ||
V_275 -> V_137 < V_275 -> V_144 ) {
V_275 -> V_145 = 0 ;
F_58 ( V_146 , & V_30 -> V_48 ) ;
} else if ( ! ( V_273 -> V_287 & V_303 ) )
V_275 -> V_145 = F_141 () + V_286 -> V_191 ;
}
if ( V_285 ) {
if ( ! V_275 -> V_140 ||
V_275 -> V_136 < V_275 -> V_140 ) {
V_275 -> V_141 = 0 ;
F_58 ( V_143 , & V_30 -> V_48 ) ;
} else if ( ! ( V_273 -> V_287 & V_305 ) )
V_275 -> V_141 = F_141 () + V_286 -> V_186 ;
}
if ( V_275 -> V_190 || V_275 -> V_144 || V_275 -> V_184 ||
V_275 -> V_140 )
F_58 ( V_183 , & V_30 -> V_48 ) ;
else
F_49 ( V_183 , & V_30 -> V_48 ) ;
F_6 ( & V_131 ) ;
F_38 ( V_30 ) ;
return 0 ;
}
int F_209 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_272 * V_273 )
{
struct V_30 * V_30 ;
int V_307 ;
V_30 = F_99 ( V_2 , V_23 ) ;
if ( ! V_30 ) {
V_307 = - V_243 ;
goto V_83;
}
V_307 = F_208 ( V_30 , V_273 ) ;
F_45 ( V_30 ) ;
V_83:
return V_307 ;
}
int F_210 ( struct V_1 * V_2 , int type , struct V_308 * V_309 )
{
struct V_176 * V_310 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_74 ( V_2 , type ) ) {
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return - V_243 ;
}
V_310 = F_42 ( V_2 ) -> V_53 + type ;
F_5 ( & V_131 ) ;
V_309 -> V_191 = V_310 -> V_191 ;
V_309 -> V_186 = V_310 -> V_186 ;
V_309 -> V_58 = V_310 -> V_58 & V_311 ;
V_309 -> V_312 = V_313 ;
F_6 ( & V_131 ) ;
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return 0 ;
}
int F_211 ( struct V_1 * V_2 , int type , struct V_308 * V_309 )
{
struct V_176 * V_310 ;
int V_55 = 0 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_74 ( V_2 , type ) ) {
V_55 = - V_243 ;
goto V_83;
}
V_310 = F_42 ( V_2 ) -> V_53 + type ;
if ( V_309 -> V_312 & V_314 ) {
if ( V_309 -> V_58 & ~ V_315 ||
( V_309 -> V_58 & V_180 &&
V_310 -> V_178 -> V_16 != V_179 ) ) {
V_55 = - V_232 ;
goto V_83;
}
}
F_5 ( & V_131 ) ;
if ( V_309 -> V_312 & V_316 )
V_310 -> V_191 = V_309 -> V_191 ;
if ( V_309 -> V_312 & V_317 )
V_310 -> V_186 = V_309 -> V_186 ;
if ( V_309 -> V_312 & V_314 )
V_310 -> V_58 = ( V_310 -> V_58 & ~ V_315 ) |
( V_309 -> V_58 & V_315 ) ;
F_6 ( & V_131 ) ;
F_48 ( V_2 , type ) ;
V_2 -> V_49 -> V_87 ( V_2 , type ) ;
V_83:
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_55 ;
}
static int F_212 ( struct V_318 * V_319 , int V_320 ,
void T_3 * V_321 , T_4 * V_322 , T_5 * V_323 )
{
unsigned int type = ( int * ) V_319 -> V_324 - V_104 . V_325 ;
V_104 . V_325 [ type ] =
F_213 ( & V_104 . V_105 [ type ] ) ;
return F_214 ( V_319 , V_320 , V_321 , V_322 , V_323 ) ;
}
static int T_6 F_215 ( void )
{
int V_173 , V_51 ;
unsigned long V_326 , V_327 ;
F_3 ( V_328 L_19 , V_329 ) ;
F_216 ( V_330 ) ;
V_73 = F_217 ( L_20 ,
sizeof( struct V_30 ) , sizeof( unsigned long ) * 4 ,
( V_331 | V_332 |
V_333 | V_334 ) ,
NULL ) ;
V_327 = 0 ;
V_33 = (struct V_31 * ) F_218 ( V_335 , V_327 ) ;
if ( ! V_33 )
F_219 ( L_21 ) ;
for ( V_173 = 0 ; V_173 < V_336 ; V_173 ++ ) {
V_51 = F_220 ( & V_104 . V_105 [ V_173 ] , 0 , V_337 ) ;
if ( V_51 )
F_219 ( L_22 ) ;
}
V_326 = ( 1UL << V_327 ) * V_338 / sizeof( struct V_31 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( V_326 >> V_28 );
V_28 -- ;
V_326 = 1UL << V_28 ;
V_29 = V_326 - 1 ;
for ( V_173 = 0 ; V_173 < V_326 ; V_173 ++ )
F_221 ( V_33 + V_173 ) ;
F_222 ( L_23
L_24 , V_326 , V_327 , ( V_338 << V_327 ) ) ;
F_223 ( & V_339 ) ;
return 0 ;
}

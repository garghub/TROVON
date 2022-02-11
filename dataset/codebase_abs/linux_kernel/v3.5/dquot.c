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
F_13 ( const struct V_1 * V_2 , unsigned int V_15 , int type )
{
unsigned long V_22 ;
V_22 = ( ( ( unsigned long ) V_2 >> V_23 ) ^ V_15 ) * ( V_24 - type ) ;
return ( V_22 + ( V_22 >> V_25 ) ) & V_26 ;
}
static inline void F_14 ( struct V_27 * V_27 )
{
struct V_28 * V_29 ;
V_29 = V_30 + F_13 ( V_27 -> V_31 , V_27 -> V_32 , V_27 -> V_33 ) ;
F_15 ( & V_27 -> V_34 , V_29 ) ;
}
static inline void F_16 ( struct V_27 * V_27 )
{
F_17 ( & V_27 -> V_34 ) ;
}
static struct V_27 * F_18 ( unsigned int V_35 , struct V_1 * V_2 ,
unsigned int V_15 , int type )
{
struct V_36 * V_37 ;
struct V_27 * V_27 ;
F_19 (node, dquot_hash+hashent) {
V_27 = F_20 ( V_37 , struct V_27 , V_34 ) ;
if ( V_27 -> V_31 == V_2 && V_27 -> V_32 == V_15 &&
V_27 -> V_33 == type )
return V_27 ;
}
return NULL ;
}
static inline void F_21 ( struct V_27 * V_27 )
{
F_22 ( & V_27 -> V_38 , & V_39 ) ;
F_23 ( V_40 ) ;
}
static inline void F_24 ( struct V_27 * V_27 )
{
if ( F_25 ( & V_27 -> V_38 ) )
return;
F_26 ( & V_27 -> V_38 ) ;
F_27 ( V_40 ) ;
}
static inline void F_28 ( struct V_27 * V_27 )
{
F_22 ( & V_27 -> V_41 , & V_42 ) ;
F_23 ( V_43 ) ;
}
static inline void F_29 ( struct V_27 * V_27 )
{
F_27 ( V_43 ) ;
F_30 ( & V_27 -> V_41 ) ;
}
static void F_31 ( struct V_27 * V_27 )
{
F_32 ( & V_27 -> V_44 ) ;
F_33 ( & V_27 -> V_44 ) ;
}
static inline int F_34 ( struct V_27 * V_27 )
{
return F_35 ( V_45 , & V_27 -> V_46 ) ;
}
static inline int F_36 ( struct V_27 * V_27 )
{
return V_27 -> V_31 -> V_47 -> V_48 ( V_27 ) ;
}
int F_37 ( struct V_27 * V_27 )
{
int V_49 = 1 ;
if ( F_35 ( V_45 , & V_27 -> V_46 ) )
return 1 ;
F_5 ( & V_11 ) ;
if ( ! F_38 ( V_45 , & V_27 -> V_46 ) ) {
F_39 ( & V_27 -> V_50 , & F_40 ( V_27 -> V_31 ) ->
V_51 [ V_27 -> V_33 ] . V_52 ) ;
V_49 = 0 ;
}
F_6 ( & V_11 ) ;
return V_49 ;
}
static inline int F_41 ( struct V_27 * const * V_27 )
{
int V_49 , V_53 , V_54 ;
V_49 = V_53 = 0 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( V_27 [ V_54 ] )
V_49 = F_36 ( V_27 [ V_54 ] ) ;
if ( ! V_53 )
V_53 = V_49 ;
}
return V_53 ;
}
static inline void F_42 ( struct V_27 * * V_27 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
F_43 ( V_27 [ V_54 ] ) ;
}
static inline int F_44 ( struct V_27 * V_27 )
{
if ( ! F_45 ( V_45 , & V_27 -> V_46 ) )
return 0 ;
F_26 ( & V_27 -> V_50 ) ;
return 1 ;
}
void F_46 ( struct V_1 * V_2 , int type )
{
F_47 ( V_55 , & F_40 ( V_2 ) -> V_51 [ type ] . V_56 ) ;
}
int F_48 ( struct V_27 * V_27 )
{
int V_49 = 0 , V_57 = 0 ;
struct V_58 * V_59 = F_40 ( V_27 -> V_31 ) ;
F_32 ( & V_27 -> V_44 ) ;
F_32 ( & V_59 -> V_60 ) ;
if ( ! F_35 ( V_61 , & V_27 -> V_46 ) )
V_49 = V_59 -> V_62 [ V_27 -> V_33 ] -> F_49 ( V_27 ) ;
if ( V_49 < 0 )
goto V_63;
F_47 ( V_61 , & V_27 -> V_46 ) ;
if ( ! F_35 ( V_64 , & V_27 -> V_46 ) && ! V_27 -> V_65 ) {
V_49 = V_59 -> V_62 [ V_27 -> V_33 ] -> F_50 ( V_27 ) ;
if ( F_51 ( & V_59 -> V_51 [ V_27 -> V_33 ] ) ) {
V_57 = V_59 -> V_62 [ V_27 -> V_33 ] -> F_52 (
V_27 -> V_31 , V_27 -> V_33 ) ;
}
if ( V_49 < 0 )
goto V_63;
if ( V_57 < 0 ) {
V_49 = V_57 ;
goto V_63;
}
}
F_47 ( V_64 , & V_27 -> V_46 ) ;
V_63:
F_33 ( & V_59 -> V_60 ) ;
F_33 ( & V_27 -> V_44 ) ;
return V_49 ;
}
int F_53 ( struct V_27 * V_27 )
{
int V_49 = 0 ;
struct V_58 * V_59 = F_40 ( V_27 -> V_31 ) ;
F_32 ( & V_59 -> V_60 ) ;
F_5 ( & V_11 ) ;
if ( ! F_44 ( V_27 ) ) {
F_6 ( & V_11 ) ;
goto V_66;
}
F_6 ( & V_11 ) ;
if ( F_35 ( V_64 , & V_27 -> V_46 ) )
V_49 = V_59 -> V_62 [ V_27 -> V_33 ] -> F_50 ( V_27 ) ;
else
V_49 = - V_67 ;
V_66:
F_33 ( & V_59 -> V_60 ) ;
return V_49 ;
}
int F_54 ( struct V_27 * V_27 )
{
int V_49 = 0 , V_57 = 0 ;
struct V_58 * V_59 = F_40 ( V_27 -> V_31 ) ;
F_32 ( & V_27 -> V_44 ) ;
if ( F_55 ( & V_27 -> V_68 ) > 1 )
goto V_69;
F_32 ( & V_59 -> V_60 ) ;
if ( V_59 -> V_62 [ V_27 -> V_33 ] -> V_70 ) {
V_49 = V_59 -> V_62 [ V_27 -> V_33 ] -> V_70 ( V_27 ) ;
if ( F_51 ( & V_59 -> V_51 [ V_27 -> V_33 ] ) ) {
V_57 = V_59 -> V_62 [ V_27 -> V_33 ] -> F_52 (
V_27 -> V_31 , V_27 -> V_33 ) ;
}
if ( V_49 >= 0 )
V_49 = V_57 ;
}
F_56 ( V_64 , & V_27 -> V_46 ) ;
F_33 ( & V_59 -> V_60 ) ;
V_69:
F_33 ( & V_27 -> V_44 ) ;
return V_49 ;
}
void F_57 ( struct V_27 * V_27 )
{
F_58 ( V_71 , V_27 ) ;
}
static inline void F_59 ( struct V_27 * V_27 )
{
V_27 -> V_31 -> V_47 -> V_72 ( V_27 ) ;
}
static void F_60 ( struct V_1 * V_2 , int type )
{
struct V_27 * V_27 , * V_22 ;
V_73:
F_5 ( & V_11 ) ;
F_61 (dquot, tmp, &inuse_list, dq_inuse) {
if ( V_27 -> V_31 != V_2 )
continue;
if ( V_27 -> V_33 != type )
continue;
if ( F_55 ( & V_27 -> V_68 ) ) {
F_62 ( V_74 ) ;
F_63 ( & V_27 -> V_68 ) ;
F_64 ( & V_27 -> V_75 , & V_74 ,
V_76 ) ;
F_6 ( & V_11 ) ;
if ( F_55 ( & V_27 -> V_68 ) > 1 )
F_65 () ;
F_66 ( & V_27 -> V_75 , & V_74 ) ;
F_43 ( V_27 ) ;
goto V_73;
}
F_16 ( V_27 ) ;
F_24 ( V_27 ) ;
F_29 ( V_27 ) ;
F_59 ( V_27 ) ;
}
F_6 ( & V_11 ) ;
}
int F_67 ( struct V_1 * V_2 ,
int (* F_68)( struct V_27 * V_27 , unsigned long V_77 ) ,
unsigned long V_77 )
{
struct V_27 * V_27 , * V_78 = NULL ;
int V_49 = 0 ;
F_32 ( & F_40 ( V_2 ) -> V_79 ) ;
F_5 ( & V_11 ) ;
F_69 (dquot, &inuse_list, dq_inuse) {
if ( ! F_35 ( V_64 , & V_27 -> V_46 ) )
continue;
if ( V_27 -> V_31 != V_2 )
continue;
F_63 ( & V_27 -> V_68 ) ;
F_6 ( & V_11 ) ;
F_23 ( V_80 ) ;
F_43 ( V_78 ) ;
V_78 = V_27 ;
V_49 = F_68 ( V_27 , V_77 ) ;
if ( V_49 < 0 )
goto V_81;
F_5 ( & V_11 ) ;
}
F_6 ( & V_11 ) ;
V_81:
F_43 ( V_78 ) ;
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return V_49 ;
}
int F_70 ( struct V_1 * V_2 , int type , int V_74 )
{
struct V_82 * V_83 ;
struct V_27 * V_27 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
int V_54 ;
F_32 ( & V_59 -> V_79 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_71 ( V_2 , V_54 ) )
continue;
F_5 ( & V_11 ) ;
V_83 = & V_59 -> V_51 [ V_54 ] . V_52 ;
while ( ! F_25 ( V_83 ) ) {
V_27 = F_72 ( V_83 , struct V_27 ,
V_50 ) ;
if ( ! F_35 ( V_64 , & V_27 -> V_46 ) ) {
F_44 ( V_27 ) ;
continue;
}
F_63 ( & V_27 -> V_68 ) ;
F_6 ( & V_11 ) ;
F_23 ( V_80 ) ;
V_2 -> V_47 -> V_84 ( V_27 ) ;
F_43 ( V_27 ) ;
F_5 ( & V_11 ) ;
}
F_6 ( & V_11 ) ;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( ( V_54 == type || type == - 1 ) && F_71 ( V_2 , V_54 )
&& F_51 ( & V_59 -> V_51 [ V_54 ] ) )
V_2 -> V_47 -> V_85 ( V_2 , V_54 ) ;
F_23 ( V_86 ) ;
F_33 ( & V_59 -> V_79 ) ;
if ( ! V_74 || ( V_59 -> V_87 & V_88 ) )
return 0 ;
if ( V_2 -> V_89 -> V_90 )
V_2 -> V_89 -> V_90 ( V_2 , 1 ) ;
F_73 ( V_2 -> V_91 ) ;
F_32 ( & V_59 -> V_79 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_71 ( V_2 , V_54 ) )
continue;
F_32 ( & V_59 -> V_92 [ V_54 ] -> V_93 ) ;
F_74 ( & V_59 -> V_92 [ V_54 ] -> V_94 , 0 ) ;
F_33 ( & V_59 -> V_92 [ V_54 ] -> V_93 ) ;
}
F_33 ( & V_59 -> V_79 ) ;
return 0 ;
}
static void F_75 ( int V_95 )
{
struct V_82 * V_29 ;
struct V_27 * V_27 ;
V_29 = V_39 . V_96 ;
while ( V_29 != & V_39 && V_95 ) {
V_27 = F_76 ( V_29 , struct V_27 , V_38 ) ;
F_16 ( V_27 ) ;
F_24 ( V_27 ) ;
F_29 ( V_27 ) ;
F_59 ( V_27 ) ;
V_95 -- ;
V_29 = V_39 . V_96 ;
}
}
static int F_77 ( struct V_97 * V_98 ,
struct V_99 * V_100 )
{
int V_101 = V_100 -> V_102 ;
if ( V_101 ) {
F_5 ( & V_11 ) ;
F_75 ( V_101 ) ;
F_6 ( & V_11 ) ;
}
return ( ( unsigned )
F_78 ( & V_103 . V_104 [ V_40 ] )
/ 100 ) * V_105 ;
}
void F_43 ( struct V_27 * V_27 )
{
int V_49 ;
if ( ! V_27 )
return;
#ifdef F_79
if ( ! F_55 ( & V_27 -> V_68 ) ) {
F_80 ( V_27 -> V_31 , L_2 ,
V_106 [ V_27 -> V_33 ] , V_27 -> V_32 ) ;
F_81 () ;
}
#endif
F_23 ( V_107 ) ;
V_108:
F_5 ( & V_11 ) ;
if ( F_55 ( & V_27 -> V_68 ) > 1 ) {
F_82 ( & V_27 -> V_68 ) ;
if ( ! F_71 ( V_27 -> V_31 , V_27 -> V_33 ) &&
F_55 ( & V_27 -> V_68 ) == 1 )
F_83 ( & V_27 -> V_75 ) ;
F_6 ( & V_11 ) ;
return;
}
if ( F_35 ( V_64 , & V_27 -> V_46 ) && F_34 ( V_27 ) ) {
F_6 ( & V_11 ) ;
V_49 = V_27 -> V_31 -> V_47 -> V_84 ( V_27 ) ;
if ( V_49 < 0 ) {
F_80 ( V_27 -> V_31 , L_3
L_4 ,
V_49 ) ;
F_5 ( & V_11 ) ;
F_44 ( V_27 ) ;
F_6 ( & V_11 ) ;
}
goto V_108;
}
F_44 ( V_27 ) ;
if ( F_35 ( V_64 , & V_27 -> V_46 ) ) {
F_6 ( & V_11 ) ;
V_27 -> V_31 -> V_47 -> V_109 ( V_27 ) ;
goto V_108;
}
F_82 ( & V_27 -> V_68 ) ;
#ifdef F_79
F_84 ( ! F_25 ( & V_27 -> V_38 ) ) ;
#endif
F_21 ( V_27 ) ;
F_6 ( & V_11 ) ;
}
struct V_27 * F_85 ( struct V_1 * V_2 , int type )
{
return F_86 ( V_71 , V_110 ) ;
}
static struct V_27 * F_87 ( struct V_1 * V_2 , int type )
{
struct V_27 * V_27 ;
V_27 = V_2 -> V_47 -> V_111 ( V_2 , type ) ;
if( ! V_27 )
return NULL ;
F_88 ( & V_27 -> V_44 ) ;
F_89 ( & V_27 -> V_38 ) ;
F_89 ( & V_27 -> V_41 ) ;
F_90 ( & V_27 -> V_34 ) ;
F_89 ( & V_27 -> V_50 ) ;
F_91 ( & V_27 -> V_75 ) ;
V_27 -> V_31 = V_2 ;
V_27 -> V_33 = type ;
F_92 ( & V_27 -> V_68 , 1 ) ;
return V_27 ;
}
struct V_27 * F_93 ( struct V_1 * V_2 , unsigned int V_15 , int type )
{
unsigned int V_35 = F_13 ( V_2 , V_15 , type ) ;
struct V_27 * V_27 = NULL , * V_112 = NULL ;
if ( ! F_71 ( V_2 , type ) )
return NULL ;
V_108:
F_5 ( & V_11 ) ;
F_5 ( & V_113 ) ;
if ( ! F_71 ( V_2 , type ) ) {
F_6 ( & V_113 ) ;
F_6 ( & V_11 ) ;
goto V_81;
}
F_6 ( & V_113 ) ;
V_27 = F_18 ( V_35 , V_2 , V_15 , type ) ;
if ( ! V_27 ) {
if ( ! V_112 ) {
F_6 ( & V_11 ) ;
V_112 = F_87 ( V_2 , type ) ;
if ( ! V_112 )
F_65 () ;
goto V_108;
}
V_27 = V_112 ;
V_112 = NULL ;
V_27 -> V_32 = V_15 ;
F_28 ( V_27 ) ;
F_14 ( V_27 ) ;
F_6 ( & V_11 ) ;
F_23 ( V_80 ) ;
} else {
if ( ! F_55 ( & V_27 -> V_68 ) )
F_24 ( V_27 ) ;
F_63 ( & V_27 -> V_68 ) ;
F_6 ( & V_11 ) ;
F_23 ( V_114 ) ;
F_23 ( V_80 ) ;
}
F_31 ( V_27 ) ;
if ( ! F_35 ( V_64 , & V_27 -> V_46 ) &&
V_2 -> V_47 -> V_115 ( V_27 ) < 0 ) {
F_43 ( V_27 ) ;
V_27 = NULL ;
goto V_81;
}
#ifdef F_79
F_84 ( ! V_27 -> V_31 ) ;
#endif
V_81:
if ( V_112 )
F_59 ( V_112 ) ;
return V_27 ;
}
static int F_94 ( struct V_116 * V_116 , int type )
{
int V_54 ;
if ( F_95 ( V_116 ) )
return 0 ;
if ( type != - 1 )
return ! V_116 -> V_117 [ type ] ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( ! V_116 -> V_117 [ V_54 ] )
return 1 ;
return 0 ;
}
static void F_96 ( struct V_1 * V_2 , int type )
{
struct V_116 * V_116 , * V_118 = NULL ;
#ifdef F_79
int V_119 = 0 ;
#endif
F_5 ( & V_120 ) ;
F_69 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_116 -> V_121 ) ;
if ( ( V_116 -> V_122 & ( V_123 | V_124 | V_125 ) ) ||
! F_55 ( & V_116 -> V_126 ) ||
! F_94 ( V_116 , type ) ) {
F_6 ( & V_116 -> V_121 ) ;
continue;
}
F_97 ( V_116 ) ;
F_6 ( & V_116 -> V_121 ) ;
F_6 ( & V_120 ) ;
#ifdef F_79
if ( F_98 ( F_99 ( V_116 ) > 0 ) )
V_119 = 1 ;
#endif
F_100 ( V_118 ) ;
F_101 ( V_116 , type ) ;
V_118 = V_116 ;
F_5 ( & V_120 ) ;
}
F_6 ( & V_120 ) ;
F_100 ( V_118 ) ;
#ifdef F_79
if ( V_119 ) {
F_80 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static inline int F_102 ( struct V_27 * V_27 )
{
if ( F_55 ( & V_27 -> V_68 ) <= 1 )
return 1 ;
return 0 ;
}
static int F_103 ( struct V_116 * V_116 , int type ,
struct V_82 * V_127 )
{
struct V_27 * V_27 = V_116 -> V_117 [ type ] ;
V_116 -> V_117 [ type ] = NULL ;
if ( V_27 ) {
if ( F_102 ( V_27 ) ) {
#ifdef F_79
if ( F_55 ( & V_27 -> V_68 ) != 1 )
F_80 ( V_116 -> V_128 , L_8
L_9 ,
F_55 ( & V_27 -> V_68 ) ) ;
#endif
F_5 ( & V_11 ) ;
F_39 ( & V_27 -> V_38 , V_127 ) ;
F_6 ( & V_11 ) ;
return 1 ;
}
else
F_43 ( V_27 ) ;
}
return 0 ;
}
static void F_104 ( struct V_82 * V_127 )
{
struct V_82 * V_129 ;
struct V_27 * V_27 ;
V_129 = V_127 -> V_130 ;
while ( V_129 != V_127 ) {
V_27 = F_76 ( V_129 , struct V_27 , V_38 ) ;
V_129 = V_129 -> V_130 ;
F_26 ( & V_27 -> V_38 ) ;
F_43 ( V_27 ) ;
}
}
static void F_105 ( struct V_1 * V_2 , int type ,
struct V_82 * V_127 )
{
struct V_116 * V_116 ;
int V_119 = 0 ;
F_5 ( & V_120 ) ;
F_69 (inode, &sb->s_inodes, i_sb_list) {
if ( ! F_95 ( V_116 ) ) {
if ( F_98 ( F_99 ( V_116 ) > 0 ) )
V_119 = 1 ;
F_103 ( V_116 , type , V_127 ) ;
}
}
F_6 ( & V_120 ) ;
#ifdef F_79
if ( V_119 ) {
F_3 ( V_131 L_10
L_11
L_12 , V_2 -> V_9 ) ;
}
#endif
}
static void F_106 ( struct V_1 * V_2 , int type )
{
F_107 ( V_127 ) ;
if ( V_2 -> V_47 ) {
F_108 ( & F_40 ( V_2 ) -> V_132 ) ;
F_105 ( V_2 , type , & V_127 ) ;
F_109 ( & F_40 ( V_2 ) -> V_132 ) ;
F_104 ( & V_127 ) ;
}
}
static inline void F_110 ( struct V_27 * V_27 , T_2 V_133 )
{
V_27 -> V_134 . V_135 += V_133 ;
}
static inline void F_111 ( struct V_27 * V_27 , T_2 V_133 )
{
V_27 -> V_134 . V_136 += V_133 ;
}
static inline void F_112 ( struct V_27 * V_27 , T_2 V_133 )
{
V_27 -> V_134 . V_137 += V_133 ;
}
static void F_113 ( struct V_27 * V_27 , T_2 V_133 )
{
if ( V_27 -> V_134 . V_137 < V_133 ) {
F_114 ( 1 ) ;
V_133 = V_27 -> V_134 . V_137 ;
}
V_27 -> V_134 . V_136 += V_133 ;
V_27 -> V_134 . V_137 -= V_133 ;
}
static inline
void F_115 ( struct V_27 * V_27 , T_2 V_133 )
{
if ( V_27 -> V_134 . V_137 >= V_133 )
V_27 -> V_134 . V_137 -= V_133 ;
else {
F_114 ( 1 ) ;
V_27 -> V_134 . V_137 = 0 ;
}
}
static void F_116 ( struct V_27 * V_27 , T_2 V_133 )
{
if ( F_40 ( V_27 -> V_31 ) -> V_87 & V_138 ||
V_27 -> V_134 . V_135 >= V_133 )
V_27 -> V_134 . V_135 -= V_133 ;
else
V_27 -> V_134 . V_135 = 0 ;
if ( V_27 -> V_134 . V_135 <= V_27 -> V_134 . V_139 )
V_27 -> V_134 . V_140 = ( V_141 ) 0 ;
F_56 ( V_142 , & V_27 -> V_46 ) ;
}
static void F_117 ( struct V_27 * V_27 , T_2 V_133 )
{
if ( F_40 ( V_27 -> V_31 ) -> V_87 & V_138 ||
V_27 -> V_134 . V_136 >= V_133 )
V_27 -> V_134 . V_136 -= V_133 ;
else
V_27 -> V_134 . V_136 = 0 ;
if ( V_27 -> V_134 . V_136 <= V_27 -> V_134 . V_143 )
V_27 -> V_134 . V_144 = ( V_141 ) 0 ;
F_56 ( V_145 , & V_27 -> V_46 ) ;
}
static int F_118 ( struct V_27 * V_27 , const int V_146 )
{
int V_147 = ( V_146 == V_148 ||
V_146 == V_149 ) ? V_145 :
( ( V_146 == V_150 ||
V_146 == V_151 ) ? V_142 : 0 ) ;
if ( ! V_147 )
return 0 ;
return F_38 ( V_147 , & V_27 -> V_46 ) ;
}
static int F_119 ( struct V_152 * V_153 )
{
if ( ! V_154 )
return 0 ;
switch ( V_153 -> V_155 ) {
case V_156 :
return F_120 () == V_153 -> V_157 ;
case V_158 :
return F_121 ( V_153 -> V_157 ) ;
}
return 0 ;
}
static void F_122 ( struct V_152 * V_153 )
{
char * V_159 = NULL ;
struct V_160 * V_161 ;
int V_146 = V_153 -> V_162 ;
if ( V_146 == V_163 ||
V_146 == V_164 ||
V_146 == V_165 ||
V_146 == V_166 || ! F_119 ( V_153 ) )
return;
V_161 = F_123 () ;
if ( ! V_161 )
return;
F_124 ( V_161 , V_153 -> V_167 -> V_9 ) ;
if ( V_146 == V_168 || V_146 == V_169 )
F_124 ( V_161 , L_13 ) ;
else
F_124 ( V_161 , L_14 ) ;
F_124 ( V_161 , V_106 [ V_153 -> V_155 ] ) ;
switch ( V_146 ) {
case V_150 :
V_159 = L_15 ;
break;
case V_151 :
V_159 = L_16 ;
break;
case V_168 :
V_159 = L_17 ;
break;
case V_148 :
V_159 = L_18 ;
break;
case V_149 :
V_159 = L_19 ;
break;
case V_169 :
V_159 = L_20 ;
break;
}
F_124 ( V_161 , V_159 ) ;
F_125 ( V_161 ) ;
}
static void F_126 ( struct V_152 * V_153 , struct V_27 * V_27 ,
int V_146 )
{
if ( F_118 ( V_27 , V_146 ) )
return;
V_153 -> V_162 = V_146 ;
V_153 -> V_167 = V_27 -> V_31 ;
V_153 -> V_157 = V_27 -> V_32 ;
V_153 -> V_155 = V_27 -> V_33 ;
}
static void F_127 ( struct V_152 * V_153 )
{
int V_170 ;
for ( V_170 = 0 ; V_170 < V_24 ; V_170 ++ ) {
if ( V_153 [ V_170 ] . V_162 == V_171 )
continue;
#ifdef F_128
F_122 ( & V_153 [ V_170 ] ) ;
#endif
F_129 ( V_153 [ V_170 ] . V_155 , V_153 [ V_170 ] . V_157 ,
V_153 [ V_170 ] . V_167 -> V_172 , V_153 [ V_170 ] . V_162 ) ;
}
}
static int F_130 ( struct V_27 * V_27 )
{
struct V_173 * V_51 = & F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] ;
return F_131 ( V_174 ) &&
( V_51 -> V_175 -> V_16 != V_176 ||
! ( V_51 -> V_56 & V_177 ) ) ;
}
static int F_132 ( struct V_27 * V_27 , T_2 V_178 ,
struct V_152 * V_153 )
{
T_2 V_179 = V_27 -> V_134 . V_135 + V_178 ;
if ( ! F_133 ( V_27 -> V_31 , V_27 -> V_33 ) ||
F_35 ( V_180 , & V_27 -> V_46 ) )
return 0 ;
if ( V_27 -> V_134 . V_181 &&
V_179 > V_27 -> V_134 . V_181 &&
! F_130 ( V_27 ) ) {
F_126 ( V_153 , V_27 , V_150 ) ;
return - V_182 ;
}
if ( V_27 -> V_134 . V_139 &&
V_179 > V_27 -> V_134 . V_139 &&
V_27 -> V_134 . V_140 &&
F_134 () >= V_27 -> V_134 . V_140 &&
! F_130 ( V_27 ) ) {
F_126 ( V_153 , V_27 , V_151 ) ;
return - V_182 ;
}
if ( V_27 -> V_134 . V_139 &&
V_179 > V_27 -> V_134 . V_139 &&
V_27 -> V_134 . V_140 == 0 ) {
F_126 ( V_153 , V_27 , V_168 ) ;
V_27 -> V_134 . V_140 = F_134 () +
F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] . V_183 ;
}
return 0 ;
}
static int F_135 ( struct V_27 * V_27 , T_2 V_184 , int V_185 ,
struct V_152 * V_153 )
{
T_2 V_186 ;
struct V_1 * V_2 = V_27 -> V_31 ;
if ( ! F_133 ( V_2 , V_27 -> V_33 ) ||
F_35 ( V_180 , & V_27 -> V_46 ) )
return 0 ;
V_186 = V_27 -> V_134 . V_136 + V_27 -> V_134 . V_137
+ V_184 ;
if ( V_27 -> V_134 . V_187 &&
V_186 > V_27 -> V_134 . V_187 &&
! F_130 ( V_27 ) ) {
if ( ! V_185 )
F_126 ( V_153 , V_27 , V_148 ) ;
return - V_182 ;
}
if ( V_27 -> V_134 . V_143 &&
V_186 > V_27 -> V_134 . V_143 &&
V_27 -> V_134 . V_144 &&
F_134 () >= V_27 -> V_134 . V_144 &&
! F_130 ( V_27 ) ) {
if ( ! V_185 )
F_126 ( V_153 , V_27 , V_149 ) ;
return - V_182 ;
}
if ( V_27 -> V_134 . V_143 &&
V_186 > V_27 -> V_134 . V_143 &&
V_27 -> V_134 . V_144 == 0 ) {
if ( ! V_185 ) {
F_126 ( V_153 , V_27 , V_169 ) ;
V_27 -> V_134 . V_144 = F_134 () +
F_40 ( V_2 ) -> V_51 [ V_27 -> V_33 ] . V_188 ;
}
else
return - V_182 ;
}
return 0 ;
}
static int F_136 ( struct V_27 * V_27 , T_2 V_178 )
{
T_2 V_179 ;
if ( F_35 ( V_180 , & V_27 -> V_46 ) ||
V_27 -> V_134 . V_135 <= V_27 -> V_134 . V_139 ||
! F_133 ( V_27 -> V_31 , V_27 -> V_33 ) )
return V_171 ;
V_179 = V_27 -> V_134 . V_135 - V_178 ;
if ( V_179 <= V_27 -> V_134 . V_139 )
return V_164 ;
if ( V_27 -> V_134 . V_135 >= V_27 -> V_134 . V_181 &&
V_179 < V_27 -> V_134 . V_181 )
return V_163 ;
return V_171 ;
}
static int F_137 ( struct V_27 * V_27 , T_2 V_184 )
{
if ( F_35 ( V_180 , & V_27 -> V_46 ) ||
V_27 -> V_134 . V_136 <= V_27 -> V_134 . V_143 )
return V_171 ;
if ( V_27 -> V_134 . V_136 - V_184 <= V_27 -> V_134 . V_143 )
return V_166 ;
if ( V_27 -> V_134 . V_136 >= V_27 -> V_134 . V_187 &&
V_27 -> V_134 . V_136 - V_184 < V_27 -> V_134 . V_187 )
return V_165 ;
return V_171 ;
}
static int F_138 ( const struct V_116 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_128 ;
if ( F_95 ( V_116 ) )
return 0 ;
return F_139 ( V_2 ) & ~ F_140 ( V_2 ) ;
}
static void F_101 ( struct V_116 * V_116 , int type )
{
unsigned int V_15 = 0 ;
int V_54 ;
struct V_27 * V_189 [ V_24 ] ;
struct V_1 * V_2 = V_116 -> V_128 ;
T_2 V_190 ;
if ( ! F_138 ( V_116 ) )
return;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_189 [ V_54 ] = NULL ;
if ( type != - 1 && V_54 != type )
continue;
switch ( V_54 ) {
case V_156 :
V_15 = V_116 -> V_191 ;
break;
case V_158 :
V_15 = V_116 -> V_192 ;
break;
}
V_189 [ V_54 ] = F_93 ( V_2 , V_15 , V_54 ) ;
}
F_108 ( & F_40 ( V_2 ) -> V_132 ) ;
if ( F_95 ( V_116 ) )
goto V_193;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_71 ( V_2 , V_54 ) )
continue;
if ( ! V_189 [ V_54 ] )
continue;
if ( ! V_116 -> V_117 [ V_54 ] ) {
V_116 -> V_117 [ V_54 ] = V_189 [ V_54 ] ;
V_189 [ V_54 ] = NULL ;
V_190 = F_99 ( V_116 ) ;
if ( F_98 ( V_190 ) )
F_112 ( V_116 -> V_117 [ V_54 ] , V_190 ) ;
}
}
V_193:
F_109 ( & F_40 ( V_2 ) -> V_132 ) ;
F_42 ( V_189 ) ;
}
void F_141 ( struct V_116 * V_116 )
{
F_101 ( V_116 , - 1 ) ;
}
static void F_142 ( struct V_116 * V_116 )
{
int V_54 ;
struct V_27 * V_194 [ V_24 ] ;
F_108 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_194 [ V_54 ] = V_116 -> V_117 [ V_54 ] ;
V_116 -> V_117 [ V_54 ] = NULL ;
}
F_109 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_42 ( V_194 ) ;
}
void F_143 ( struct V_116 * V_116 )
{
int V_54 ;
if ( F_95 ( V_116 ) )
return;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( V_116 -> V_117 [ V_54 ] )
break;
}
if ( V_54 < V_24 )
F_142 ( V_116 ) ;
}
static T_2 * F_144 ( struct V_116 * V_116 )
{
F_84 ( ! V_116 -> V_128 -> V_47 -> V_195 ) ;
return V_116 -> V_128 -> V_47 -> V_195 ( V_116 ) ;
}
void F_145 ( struct V_116 * V_116 , T_2 V_133 )
{
F_5 ( & V_116 -> V_121 ) ;
* F_144 ( V_116 ) += V_133 ;
F_6 ( & V_116 -> V_121 ) ;
}
void F_146 ( struct V_116 * V_116 , T_2 V_133 )
{
F_5 ( & V_116 -> V_121 ) ;
* F_144 ( V_116 ) -= V_133 ;
F_147 ( V_116 , V_133 ) ;
F_6 ( & V_116 -> V_121 ) ;
}
void F_148 ( struct V_116 * V_116 , T_2 V_133 )
{
F_5 ( & V_116 -> V_121 ) ;
* F_144 ( V_116 ) -= V_133 ;
F_6 ( & V_116 -> V_121 ) ;
}
static T_2 F_99 ( struct V_116 * V_116 )
{
T_2 V_49 ;
if ( ! V_116 -> V_128 -> V_47 -> V_195 )
return 0 ;
F_5 ( & V_116 -> V_121 ) ;
V_49 = * F_144 ( V_116 ) ;
F_6 ( & V_116 -> V_121 ) ;
return V_49 ;
}
static void F_149 ( struct V_116 * V_116 , T_2 V_133 ,
int V_196 )
{
if ( V_196 )
F_145 ( V_116 , V_133 ) ;
else
F_150 ( V_116 , V_133 ) ;
}
static void F_151 ( struct V_116 * V_116 , T_2 V_133 , int V_196 )
{
if ( V_196 )
F_148 ( V_116 , V_133 ) ;
else
F_152 ( V_116 , V_133 ) ;
}
int F_153 ( struct V_116 * V_116 , T_2 V_133 , int V_87 )
{
int V_54 , V_49 = 0 ;
struct V_152 V_153 [ V_24 ] ;
struct V_27 * * V_197 = V_116 -> V_117 ;
int V_196 = V_87 & V_198 ;
if ( ! F_138 ( V_116 ) ) {
F_149 ( V_116 , V_133 , V_196 ) ;
goto V_81;
}
F_154 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
V_153 [ V_54 ] . V_162 = V_171 ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_197 [ V_54 ] )
continue;
V_49 = F_135 ( V_197 [ V_54 ] , V_133 ,
! ( V_87 & V_200 ) , & V_153 [ V_54 ] ) ;
if ( V_49 && ! ( V_87 & V_201 ) ) {
F_6 ( & V_199 ) ;
goto V_202;
}
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_197 [ V_54 ] )
continue;
if ( V_196 )
F_112 ( V_197 [ V_54 ] , V_133 ) ;
else
F_111 ( V_197 [ V_54 ] , V_133 ) ;
}
F_149 ( V_116 , V_133 , V_196 ) ;
F_6 ( & V_199 ) ;
if ( V_196 )
goto V_202;
F_41 ( V_197 ) ;
V_202:
F_155 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_127 ( V_153 ) ;
V_81:
return V_49 ;
}
int F_156 ( const struct V_116 * V_116 )
{
int V_54 , V_49 = 0 ;
struct V_152 V_153 [ V_24 ] ;
struct V_27 * const * V_197 = V_116 -> V_117 ;
if ( ! F_138 ( V_116 ) )
return 0 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
V_153 [ V_54 ] . V_162 = V_171 ;
F_154 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_197 [ V_54 ] )
continue;
V_49 = F_132 ( V_197 [ V_54 ] , 1 , & V_153 [ V_54 ] ) ;
if ( V_49 )
goto V_203;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_197 [ V_54 ] )
continue;
F_110 ( V_197 [ V_54 ] , 1 ) ;
}
V_203:
F_6 ( & V_199 ) ;
if ( V_49 == 0 )
F_41 ( V_197 ) ;
F_155 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_127 ( V_153 ) ;
return V_49 ;
}
int F_157 ( struct V_116 * V_116 , T_2 V_133 )
{
int V_54 ;
if ( ! F_138 ( V_116 ) ) {
F_146 ( V_116 , V_133 ) ;
return 0 ;
}
F_154 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( V_116 -> V_117 [ V_54 ] )
F_113 ( V_116 -> V_117 [ V_54 ] ,
V_133 ) ;
}
F_146 ( V_116 , V_133 ) ;
F_6 ( & V_199 ) ;
F_41 ( V_116 -> V_117 ) ;
F_155 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
return 0 ;
}
void F_158 ( struct V_116 * V_116 , T_2 V_133 , int V_87 )
{
unsigned int V_54 ;
struct V_152 V_153 [ V_24 ] ;
struct V_27 * * V_197 = V_116 -> V_117 ;
int V_196 = V_87 & V_198 ;
if ( ! F_138 ( V_116 ) ) {
F_151 ( V_116 , V_133 , V_196 ) ;
return;
}
F_154 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
int V_204 ;
V_153 [ V_54 ] . V_162 = V_171 ;
if ( ! V_197 [ V_54 ] )
continue;
V_204 = F_137 ( V_197 [ V_54 ] , V_133 ) ;
if ( V_204 != V_171 )
F_126 ( & V_153 [ V_54 ] , V_197 [ V_54 ] , V_204 ) ;
if ( V_196 )
F_115 ( V_197 [ V_54 ] , V_133 ) ;
else
F_117 ( V_197 [ V_54 ] , V_133 ) ;
}
F_151 ( V_116 , V_133 , V_196 ) ;
F_6 ( & V_199 ) ;
if ( V_196 )
goto V_205;
F_41 ( V_197 ) ;
V_205:
F_155 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_127 ( V_153 ) ;
}
void F_159 ( const struct V_116 * V_116 )
{
unsigned int V_54 ;
struct V_152 V_153 [ V_24 ] ;
struct V_27 * const * V_197 = V_116 -> V_117 ;
if ( ! F_138 ( V_116 ) )
return;
F_154 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
int V_204 ;
V_153 [ V_54 ] . V_162 = V_171 ;
if ( ! V_197 [ V_54 ] )
continue;
V_204 = F_136 ( V_197 [ V_54 ] , 1 ) ;
if ( V_204 != V_171 )
F_126 ( & V_153 [ V_54 ] , V_197 [ V_54 ] , V_204 ) ;
F_116 ( V_197 [ V_54 ] , 1 ) ;
}
F_6 ( & V_199 ) ;
F_41 ( V_197 ) ;
F_155 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_127 ( V_153 ) ;
}
int F_160 ( struct V_116 * V_116 , struct V_27 * * V_206 )
{
T_2 V_184 , V_207 ;
T_2 V_208 = 0 ;
struct V_27 * V_209 [ V_24 ] = {} ;
int V_54 , V_49 = 0 ;
char V_210 [ V_24 ] = {} ;
struct V_152 V_211 [ V_24 ] ;
struct V_152 V_212 [ V_24 ] ;
struct V_152 V_213 [ V_24 ] ;
if ( F_95 ( V_116 ) )
return 0 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_211 [ V_54 ] . V_162 = V_171 ;
V_212 [ V_54 ] . V_162 = V_171 ;
V_213 [ V_54 ] . V_162 = V_171 ;
}
F_108 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
if ( F_95 ( V_116 ) ) {
F_109 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
return 0 ;
}
F_5 ( & V_199 ) ;
V_207 = F_161 ( V_116 ) ;
V_208 = F_99 ( V_116 ) ;
V_184 = V_207 + V_208 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_206 [ V_54 ] )
continue;
if ( ! F_71 ( V_116 -> V_128 , V_54 ) )
continue;
V_210 [ V_54 ] = 1 ;
V_209 [ V_54 ] = V_116 -> V_117 [ V_54 ] ;
V_49 = F_132 ( V_206 [ V_54 ] , 1 , & V_211 [ V_54 ] ) ;
if ( V_49 )
goto V_214;
V_49 = F_135 ( V_206 [ V_54 ] , V_184 , 0 , & V_211 [ V_54 ] ) ;
if ( V_49 )
goto V_214;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_210 [ V_54 ] )
continue;
if ( V_209 [ V_54 ] ) {
int V_204 ;
V_204 = F_136 ( V_209 [ V_54 ] , 1 ) ;
if ( V_204 != V_171 )
F_126 ( & V_212 [ V_54 ] ,
V_209 [ V_54 ] , V_204 ) ;
V_204 = F_137 ( V_209 [ V_54 ] , V_184 ) ;
if ( V_204 != V_171 )
F_126 ( & V_213 [ V_54 ] ,
V_209 [ V_54 ] , V_204 ) ;
F_116 ( V_209 [ V_54 ] , 1 ) ;
F_117 ( V_209 [ V_54 ] , V_207 ) ;
F_115 ( V_209 [ V_54 ] ,
V_208 ) ;
}
F_110 ( V_206 [ V_54 ] , 1 ) ;
F_111 ( V_206 [ V_54 ] , V_207 ) ;
F_112 ( V_206 [ V_54 ] , V_208 ) ;
V_116 -> V_117 [ V_54 ] = V_206 [ V_54 ] ;
}
F_6 ( & V_199 ) ;
F_109 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_41 ( V_209 ) ;
F_41 ( V_206 ) ;
F_127 ( V_211 ) ;
F_127 ( V_212 ) ;
F_127 ( V_213 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_210 [ V_54 ] )
V_206 [ V_54 ] = V_209 [ V_54 ] ;
return 0 ;
V_214:
F_6 ( & V_199 ) ;
F_109 ( & F_40 ( V_116 -> V_128 ) -> V_132 ) ;
F_127 ( V_211 ) ;
return V_49 ;
}
int F_162 ( struct V_116 * V_116 , struct V_215 * V_215 )
{
struct V_27 * V_206 [ V_24 ] = {} ;
struct V_1 * V_2 = V_116 -> V_128 ;
int V_49 ;
if ( ! F_138 ( V_116 ) )
return 0 ;
if ( V_215 -> V_216 & V_217 && V_215 -> V_218 != V_116 -> V_191 )
V_206 [ V_156 ] = F_93 ( V_2 , V_215 -> V_218 , V_156 ) ;
if ( V_215 -> V_216 & V_219 && V_215 -> V_220 != V_116 -> V_192 )
V_206 [ V_158 ] = F_93 ( V_2 , V_215 -> V_220 , V_158 ) ;
V_49 = F_160 ( V_116 , V_206 ) ;
F_42 ( V_206 ) ;
return V_49 ;
}
int F_163 ( struct V_1 * V_2 , int type )
{
int V_49 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
F_32 ( & V_59 -> V_60 ) ;
V_49 = V_59 -> V_62 [ type ] -> F_52 ( V_2 , type ) ;
F_33 ( & V_59 -> V_60 ) ;
return V_49 ;
}
int F_164 ( struct V_116 * V_116 , struct V_221 * V_221 )
{
int error ;
error = F_165 ( V_116 , V_221 ) ;
if ( ! error && ( V_221 -> V_222 & V_223 ) )
F_141 ( V_116 ) ;
return error ;
}
int F_166 ( struct V_1 * V_2 , int type , unsigned int V_87 )
{
int V_54 , V_49 = 0 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
struct V_116 * V_224 [ V_24 ] ;
if ( ( V_87 & V_225 && ! ( V_87 & V_226 ) )
|| ( V_87 & V_227 && V_87 & ( V_226 |
V_225 ) ) )
return - V_228 ;
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_139 ( V_2 ) ) {
F_33 ( & V_59 -> V_79 ) ;
return 0 ;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_224 [ V_54 ] = NULL ;
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_167 ( V_2 , V_54 ) )
continue;
if ( V_87 & V_227 ) {
F_5 ( & V_113 ) ;
V_59 -> V_87 |=
F_168 ( V_227 , V_54 ) ;
F_6 ( & V_113 ) ;
} else {
F_5 ( & V_113 ) ;
V_59 -> V_87 &= ~ F_168 ( V_87 , V_54 ) ;
if ( ! F_167 ( V_2 , V_54 ) &&
F_169 ( V_2 , V_54 ) ) {
V_59 -> V_87 &= ~ F_168 (
V_227 , V_54 ) ;
F_6 ( & V_113 ) ;
F_100 ( V_59 -> V_92 [ V_54 ] ) ;
V_59 -> V_92 [ V_54 ] = NULL ;
continue;
}
F_6 ( & V_113 ) ;
}
if ( F_167 ( V_2 , V_54 ) && ! ( V_87 & V_227 ) )
continue;
F_106 ( V_2 , V_54 ) ;
F_60 ( V_2 , V_54 ) ;
if ( F_51 ( & V_59 -> V_51 [ V_54 ] ) )
V_2 -> V_47 -> V_85 ( V_2 , V_54 ) ;
if ( V_59 -> V_62 [ V_54 ] -> V_229 )
V_59 -> V_62 [ V_54 ] -> V_229 ( V_2 , V_54 ) ;
F_11 ( V_59 -> V_51 [ V_54 ] . V_175 ) ;
V_224 [ V_54 ] = V_59 -> V_92 [ V_54 ] ;
if ( ! F_167 ( V_2 , V_54 ) )
V_59 -> V_92 [ V_54 ] = NULL ;
V_59 -> V_51 [ V_54 ] . V_56 = 0 ;
V_59 -> V_51 [ V_54 ] . V_183 = 0 ;
V_59 -> V_51 [ V_54 ] . V_188 = 0 ;
V_59 -> V_62 [ V_54 ] = NULL ;
}
F_33 ( & V_59 -> V_79 ) ;
if ( V_59 -> V_87 & V_88 )
goto V_230;
if ( V_2 -> V_89 -> V_90 )
V_2 -> V_89 -> V_90 ( V_2 , 1 ) ;
F_73 ( V_2 -> V_91 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_224 [ V_54 ] ) {
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_167 ( V_2 , V_54 ) ) {
F_32 ( & V_224 [ V_54 ] -> V_93 ) ;
V_224 [ V_54 ] -> V_231 &= ~ ( V_232 |
V_233 | V_234 ) ;
F_74 ( & V_224 [ V_54 ] -> V_94 ,
0 ) ;
F_33 ( & V_224 [ V_54 ] -> V_93 ) ;
F_170 ( V_224 [ V_54 ] ) ;
}
F_33 ( & V_59 -> V_79 ) ;
}
if ( V_2 -> V_91 )
F_171 ( V_2 -> V_91 ) ;
V_230:
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_224 [ V_54 ] ) {
if ( ! ( V_87 & V_227 ) )
F_100 ( V_224 [ V_54 ] ) ;
else if ( ! V_224 [ V_54 ] -> V_235 )
V_49 = - V_236 ;
}
return V_49 ;
}
int F_172 ( struct V_1 * V_2 , int type )
{
return F_166 ( V_2 , type ,
V_225 | V_226 ) ;
}
static int F_173 ( struct V_116 * V_116 , int type , int V_237 ,
unsigned int V_87 )
{
struct V_10 * V_4 = F_8 ( V_237 ) ;
struct V_1 * V_2 = V_116 -> V_128 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
int error ;
int V_238 = - 1 ;
if ( ! V_4 )
return - V_239 ;
if ( ! F_174 ( V_116 -> V_240 ) ) {
error = - V_241 ;
goto V_242;
}
if ( F_175 ( V_116 ) ) {
error = - V_243 ;
goto V_242;
}
if ( ! V_2 -> V_89 -> V_244 || ! V_2 -> V_89 -> V_245 ) {
error = - V_228 ;
goto V_242;
}
if ( ! ( V_87 & V_225 ) ) {
error = - V_228 ;
goto V_242;
}
if ( ! ( V_59 -> V_87 & V_88 ) ) {
F_176 ( V_2 ) ;
F_171 ( V_2 -> V_91 ) ;
}
F_32 ( & V_59 -> V_79 ) ;
if ( F_167 ( V_2 , type ) ) {
error = - V_236 ;
goto V_246;
}
if ( ! ( V_59 -> V_87 & V_88 ) ) {
F_32 ( & V_116 -> V_93 ) ;
V_238 = V_116 -> V_231 & ( V_233 | V_232 |
V_234 ) ;
V_116 -> V_231 |= V_234 | V_233 | V_232 ;
F_33 ( & V_116 -> V_93 ) ;
F_142 ( V_116 ) ;
}
error = - V_67 ;
V_59 -> V_92 [ type ] = F_177 ( V_116 ) ;
if ( ! V_59 -> V_92 [ type ] )
goto V_246;
error = - V_228 ;
if ( ! V_4 -> V_247 -> V_248 ( V_2 , type ) )
goto V_249;
V_59 -> V_62 [ type ] = V_4 -> V_247 ;
V_59 -> V_51 [ type ] . V_175 = V_4 ;
V_59 -> V_51 [ type ] . V_250 = V_237 ;
F_89 ( & V_59 -> V_51 [ type ] . V_52 ) ;
F_32 ( & V_59 -> V_60 ) ;
error = V_59 -> V_62 [ type ] -> F_178 ( V_2 , type ) ;
if ( error < 0 ) {
F_33 ( & V_59 -> V_60 ) ;
goto V_249;
}
if ( V_59 -> V_87 & V_88 )
V_59 -> V_51 [ type ] . V_56 |= V_251 ;
F_33 ( & V_59 -> V_60 ) ;
F_5 ( & V_113 ) ;
V_59 -> V_87 |= F_168 ( V_87 , type ) ;
F_6 ( & V_113 ) ;
F_96 ( V_2 , type ) ;
F_33 ( & V_59 -> V_79 ) ;
return 0 ;
V_249:
V_59 -> V_92 [ type ] = NULL ;
F_100 ( V_116 ) ;
V_246:
if ( V_238 != - 1 ) {
F_32 ( & V_116 -> V_93 ) ;
V_116 -> V_231 &= ~ ( V_233 | V_234 | V_232 ) ;
V_116 -> V_231 |= V_238 ;
F_33 ( & V_116 -> V_93 ) ;
}
F_33 ( & V_59 -> V_79 ) ;
V_242:
F_11 ( V_4 ) ;
return error ;
}
int F_179 ( struct V_1 * V_2 , int type )
{
struct V_58 * V_59 = F_40 ( V_2 ) ;
struct V_116 * V_116 ;
int V_49 = 0 , V_54 ;
unsigned int V_87 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( type != - 1 && V_54 != type )
continue;
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_169 ( V_2 , V_54 ) ) {
F_33 ( & V_59 -> V_79 ) ;
continue;
}
V_116 = V_59 -> V_92 [ V_54 ] ;
V_59 -> V_92 [ V_54 ] = NULL ;
F_5 ( & V_113 ) ;
V_87 = V_59 -> V_87 & F_168 ( V_225 |
V_226 ,
V_54 ) ;
V_59 -> V_87 &= ~ F_168 ( V_252 , V_54 ) ;
F_6 ( & V_113 ) ;
F_33 ( & V_59 -> V_79 ) ;
V_87 = F_180 ( V_87 , V_54 ) ;
V_49 = F_173 ( V_116 , V_54 ,
V_59 -> V_51 [ V_54 ] . V_250 , V_87 ) ;
F_100 ( V_116 ) ;
}
return V_49 ;
}
int F_181 ( struct V_1 * V_2 , int type , int V_237 ,
struct V_253 * V_253 )
{
int error = F_182 ( V_253 -> V_254 ) ;
if ( error )
return error ;
if ( V_253 -> V_254 -> V_255 != V_2 )
error = - V_256 ;
else
error = F_173 ( V_253 -> V_254 -> V_257 , type ,
V_237 , V_225 |
V_226 ) ;
return error ;
}
int F_183 ( struct V_116 * V_116 , int type , int V_237 ,
unsigned int V_87 )
{
int V_49 = 0 ;
struct V_1 * V_2 = V_116 -> V_128 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
F_84 ( V_87 & V_227 ) ;
if ( ! V_87 )
return 0 ;
if ( F_167 ( V_2 , type ) ) {
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_167 ( V_2 , type ) ) {
F_33 ( & V_59 -> V_79 ) ;
goto V_258;
}
if ( V_87 & V_225 &&
F_184 ( V_2 , type ) ) {
V_49 = - V_236 ;
goto V_246;
}
if ( V_87 & V_226 &&
F_133 ( V_2 , type ) ) {
V_49 = - V_236 ;
goto V_246;
}
F_5 ( & V_113 ) ;
F_40 ( V_2 ) -> V_87 |= F_168 ( V_87 , type ) ;
F_6 ( & V_113 ) ;
V_246:
F_33 ( & V_59 -> V_79 ) ;
return V_49 ;
}
V_258:
return F_173 ( V_116 , type , V_237 , V_87 ) ;
}
int F_185 ( struct V_1 * V_2 , char * V_259 ,
int V_237 , int type )
{
struct V_254 * V_254 ;
int error ;
F_32 ( & V_2 -> V_260 -> V_257 -> V_93 ) ;
V_254 = F_186 ( V_259 , V_2 -> V_260 , strlen ( V_259 ) ) ;
F_33 ( & V_2 -> V_260 -> V_257 -> V_93 ) ;
if ( F_187 ( V_254 ) )
return F_188 ( V_254 ) ;
if ( ! V_254 -> V_257 ) {
error = - V_261 ;
goto V_81;
}
error = F_182 ( V_254 ) ;
if ( ! error )
error = F_173 ( V_254 -> V_257 , type , V_237 ,
V_225 | V_226 ) ;
V_81:
F_189 ( V_254 ) ;
return error ;
}
static inline T_2 F_190 ( T_2 V_262 )
{
return V_262 << V_263 ;
}
static inline T_2 F_191 ( T_2 V_184 )
{
return ( V_184 + V_264 - 1 ) >> V_263 ;
}
static void F_192 ( struct V_27 * V_27 , struct V_265 * V_266 )
{
struct V_267 * V_268 = & V_27 -> V_134 ;
memset ( V_266 , 0 , sizeof( * V_266 ) ) ;
V_266 -> V_269 = V_270 ;
V_266 -> V_271 = V_27 -> V_33 == V_156 ?
V_272 : V_273 ;
V_266 -> V_274 = V_27 -> V_32 ;
F_5 ( & V_199 ) ;
V_266 -> V_275 = F_191 ( V_268 -> V_187 ) ;
V_266 -> V_276 = F_191 ( V_268 -> V_143 ) ;
V_266 -> V_277 = V_268 -> V_181 ;
V_266 -> V_278 = V_268 -> V_139 ;
V_266 -> V_279 = V_268 -> V_136 + V_268 -> V_137 ;
V_266 -> V_280 = V_268 -> V_135 ;
V_266 -> V_281 = V_268 -> V_144 ;
V_266 -> V_282 = V_268 -> V_140 ;
F_6 ( & V_199 ) ;
}
int F_193 ( struct V_1 * V_2 , int type , T_3 V_15 ,
struct V_265 * V_266 )
{
struct V_27 * V_27 ;
V_27 = F_93 ( V_2 , V_15 , type ) ;
if ( ! V_27 )
return - V_239 ;
F_192 ( V_27 , V_266 ) ;
F_43 ( V_27 ) ;
return 0 ;
}
static int F_194 ( struct V_27 * V_27 , struct V_265 * V_266 )
{
struct V_267 * V_268 = & V_27 -> V_134 ;
int V_283 = 0 , V_284 = 0 ;
struct V_173 * V_285 = & F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] ;
if ( V_266 -> V_286 & ~ V_287 )
return - V_228 ;
if ( ( ( V_266 -> V_286 & V_288 ) &&
( V_266 -> V_276 > V_285 -> V_289 ) ) ||
( ( V_266 -> V_286 & V_290 ) &&
( V_266 -> V_275 > V_285 -> V_289 ) ) ||
( ( V_266 -> V_286 & V_291 ) &&
( V_266 -> V_278 > V_285 -> V_292 ) ) ||
( ( V_266 -> V_286 & V_293 ) &&
( V_266 -> V_277 > V_285 -> V_292 ) ) )
return - V_294 ;
F_5 ( & V_199 ) ;
if ( V_266 -> V_286 & V_295 ) {
V_268 -> V_136 = V_266 -> V_279 - V_268 -> V_137 ;
V_283 = 1 ;
F_47 ( V_296 + V_297 , & V_27 -> V_46 ) ;
}
if ( V_266 -> V_286 & V_288 )
V_268 -> V_143 = F_190 ( V_266 -> V_276 ) ;
if ( V_266 -> V_286 & V_290 )
V_268 -> V_187 = F_190 ( V_266 -> V_275 ) ;
if ( V_266 -> V_286 & ( V_288 | V_290 ) ) {
V_283 = 1 ;
F_47 ( V_296 + V_298 , & V_27 -> V_46 ) ;
}
if ( V_266 -> V_286 & V_299 ) {
V_268 -> V_135 = V_266 -> V_280 ;
V_284 = 1 ;
F_47 ( V_296 + V_300 , & V_27 -> V_46 ) ;
}
if ( V_266 -> V_286 & V_291 )
V_268 -> V_139 = V_266 -> V_278 ;
if ( V_266 -> V_286 & V_293 )
V_268 -> V_181 = V_266 -> V_277 ;
if ( V_266 -> V_286 & ( V_291 | V_293 ) ) {
V_284 = 1 ;
F_47 ( V_296 + V_301 , & V_27 -> V_46 ) ;
}
if ( V_266 -> V_286 & V_302 ) {
V_268 -> V_144 = V_266 -> V_281 ;
V_283 = 1 ;
F_47 ( V_296 + V_303 , & V_27 -> V_46 ) ;
}
if ( V_266 -> V_286 & V_304 ) {
V_268 -> V_140 = V_266 -> V_282 ;
V_284 = 1 ;
F_47 ( V_296 + V_305 , & V_27 -> V_46 ) ;
}
if ( V_283 ) {
if ( ! V_268 -> V_143 ||
V_268 -> V_136 < V_268 -> V_143 ) {
V_268 -> V_144 = 0 ;
F_56 ( V_145 , & V_27 -> V_46 ) ;
} else if ( ! ( V_266 -> V_286 & V_302 ) )
V_268 -> V_144 = F_134 () + V_285 -> V_188 ;
}
if ( V_284 ) {
if ( ! V_268 -> V_139 ||
V_268 -> V_135 < V_268 -> V_139 ) {
V_268 -> V_140 = 0 ;
F_56 ( V_142 , & V_27 -> V_46 ) ;
} else if ( ! ( V_266 -> V_286 & V_304 ) )
V_268 -> V_140 = F_134 () + V_285 -> V_183 ;
}
if ( V_268 -> V_187 || V_268 -> V_143 || V_268 -> V_181 ||
V_268 -> V_139 )
F_56 ( V_180 , & V_27 -> V_46 ) ;
else
F_47 ( V_180 , & V_27 -> V_46 ) ;
F_6 ( & V_199 ) ;
F_36 ( V_27 ) ;
return 0 ;
}
int F_195 ( struct V_1 * V_2 , int type , T_3 V_15 ,
struct V_265 * V_266 )
{
struct V_27 * V_27 ;
int V_306 ;
V_27 = F_93 ( V_2 , V_15 , type ) ;
if ( ! V_27 ) {
V_306 = - V_239 ;
goto V_81;
}
V_306 = F_194 ( V_27 , V_266 ) ;
F_43 ( V_27 ) ;
V_81:
return V_306 ;
}
int F_196 ( struct V_1 * V_2 , int type , struct V_307 * V_308 )
{
struct V_173 * V_309 ;
F_32 ( & F_40 ( V_2 ) -> V_79 ) ;
if ( ! F_71 ( V_2 , type ) ) {
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return - V_239 ;
}
V_309 = F_40 ( V_2 ) -> V_51 + type ;
F_5 ( & V_199 ) ;
V_308 -> V_188 = V_309 -> V_188 ;
V_308 -> V_183 = V_309 -> V_183 ;
V_308 -> V_56 = V_309 -> V_56 & V_310 ;
V_308 -> V_311 = V_312 ;
F_6 ( & V_199 ) ;
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return 0 ;
}
int F_197 ( struct V_1 * V_2 , int type , struct V_307 * V_308 )
{
struct V_173 * V_309 ;
int V_53 = 0 ;
F_32 ( & F_40 ( V_2 ) -> V_79 ) ;
if ( ! F_71 ( V_2 , type ) ) {
V_53 = - V_239 ;
goto V_81;
}
V_309 = F_40 ( V_2 ) -> V_51 + type ;
F_5 ( & V_199 ) ;
if ( V_308 -> V_311 & V_313 )
V_309 -> V_188 = V_308 -> V_188 ;
if ( V_308 -> V_311 & V_314 )
V_309 -> V_183 = V_308 -> V_183 ;
if ( V_308 -> V_311 & V_315 )
V_309 -> V_56 = ( V_309 -> V_56 & ~ V_316 ) |
( V_308 -> V_56 & V_316 ) ;
F_6 ( & V_199 ) ;
F_46 ( V_2 , type ) ;
V_2 -> V_47 -> V_85 ( V_2 , type ) ;
V_81:
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return V_53 ;
}
static int F_198 ( struct V_317 * V_318 , int V_319 ,
void T_4 * V_320 , T_5 * V_321 , T_6 * V_322 )
{
unsigned int type = ( int * ) V_318 -> V_323 - V_103 . V_324 ;
V_103 . V_324 [ type ] =
F_199 ( & V_103 . V_104 [ type ] ) ;
return F_200 ( V_318 , V_319 , V_320 , V_321 , V_322 ) ;
}
static int T_7 F_201 ( void )
{
int V_170 , V_49 ;
unsigned long V_325 , V_326 ;
F_3 ( V_327 L_21 , V_328 ) ;
F_202 ( V_329 ) ;
V_71 = F_203 ( L_22 ,
sizeof( struct V_27 ) , sizeof( unsigned long ) * 4 ,
( V_330 | V_331 |
V_332 | V_333 ) ,
NULL ) ;
V_326 = 0 ;
V_30 = (struct V_28 * ) F_204 ( V_334 , V_326 ) ;
if ( ! V_30 )
F_205 ( L_23 ) ;
for ( V_170 = 0 ; V_170 < V_335 ; V_170 ++ ) {
V_49 = F_206 ( & V_103 . V_104 [ V_170 ] , 0 ) ;
if ( V_49 )
F_205 ( L_24 ) ;
}
V_325 = ( 1UL << V_326 ) * V_336 / sizeof( struct V_28 ) ;
V_25 = 0 ;
do {
V_25 ++ ;
} while ( V_325 >> V_25 );
V_25 -- ;
V_325 = 1UL << V_25 ;
V_26 = V_325 - 1 ;
for ( V_170 = 0 ; V_170 < V_325 ; V_170 ++ )
F_207 ( V_30 + V_170 ) ;
F_3 ( L_25 ,
V_325 , V_326 , ( V_336 << V_326 ) ) ;
F_208 ( & V_337 ) ;
return 0 ;
}

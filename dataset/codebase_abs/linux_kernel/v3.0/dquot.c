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
if ( ! V_74 || ( F_40 ( V_2 ) -> V_87 & V_88 ) )
return 0 ;
if ( V_2 -> V_89 -> V_90 )
V_2 -> V_89 -> V_90 ( V_2 , 1 ) ;
F_73 ( V_2 -> V_91 ) ;
F_32 ( & F_40 ( V_2 ) -> V_79 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_71 ( V_2 , V_54 ) )
continue;
F_74 ( & F_40 ( V_2 ) -> V_92 [ V_54 ] -> V_93 ,
V_94 ) ;
F_75 ( & F_40 ( V_2 ) -> V_92 [ V_54 ] -> V_95 , 0 ) ;
F_33 ( & F_40 ( V_2 ) -> V_92 [ V_54 ] -> V_93 ) ;
}
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return 0 ;
}
static void F_76 ( int V_96 )
{
struct V_82 * V_29 ;
struct V_27 * V_27 ;
V_29 = V_39 . V_97 ;
while ( V_29 != & V_39 && V_96 ) {
V_27 = F_77 ( V_29 , struct V_27 , V_38 ) ;
F_16 ( V_27 ) ;
F_24 ( V_27 ) ;
F_29 ( V_27 ) ;
F_59 ( V_27 ) ;
V_96 -- ;
V_29 = V_39 . V_97 ;
}
}
static int F_78 ( struct V_98 * V_99 ,
struct V_100 * V_101 )
{
int V_102 = V_101 -> V_103 ;
if ( V_102 ) {
F_5 ( & V_11 ) ;
F_76 ( V_102 ) ;
F_6 ( & V_11 ) ;
}
return ( ( unsigned )
F_79 ( & V_104 . V_105 [ V_40 ] )
/ 100 ) * V_106 ;
}
void F_43 ( struct V_27 * V_27 )
{
int V_49 ;
if ( ! V_27 )
return;
#ifdef F_80
if ( ! F_55 ( & V_27 -> V_68 ) ) {
F_81 ( V_27 -> V_31 , L_2 ,
V_107 [ V_27 -> V_33 ] , V_27 -> V_32 ) ;
F_82 () ;
}
#endif
F_23 ( V_108 ) ;
V_109:
F_5 ( & V_11 ) ;
if ( F_55 ( & V_27 -> V_68 ) > 1 ) {
F_83 ( & V_27 -> V_68 ) ;
if ( ! F_71 ( V_27 -> V_31 , V_27 -> V_33 ) &&
F_55 ( & V_27 -> V_68 ) == 1 )
F_84 ( & V_27 -> V_75 ) ;
F_6 ( & V_11 ) ;
return;
}
if ( F_35 ( V_64 , & V_27 -> V_46 ) && F_34 ( V_27 ) ) {
F_6 ( & V_11 ) ;
V_49 = V_27 -> V_31 -> V_47 -> V_84 ( V_27 ) ;
if ( V_49 < 0 ) {
F_81 ( V_27 -> V_31 , L_3
L_4 ,
V_49 ) ;
F_5 ( & V_11 ) ;
F_44 ( V_27 ) ;
F_6 ( & V_11 ) ;
}
goto V_109;
}
F_44 ( V_27 ) ;
if ( F_35 ( V_64 , & V_27 -> V_46 ) ) {
F_6 ( & V_11 ) ;
V_27 -> V_31 -> V_47 -> V_110 ( V_27 ) ;
goto V_109;
}
F_83 ( & V_27 -> V_68 ) ;
#ifdef F_80
F_85 ( ! F_25 ( & V_27 -> V_38 ) ) ;
#endif
F_21 ( V_27 ) ;
F_6 ( & V_11 ) ;
}
struct V_27 * F_86 ( struct V_1 * V_2 , int type )
{
return F_87 ( V_71 , V_111 ) ;
}
static struct V_27 * F_88 ( struct V_1 * V_2 , int type )
{
struct V_27 * V_27 ;
V_27 = V_2 -> V_47 -> V_112 ( V_2 , type ) ;
if( ! V_27 )
return NULL ;
F_89 ( & V_27 -> V_44 ) ;
F_90 ( & V_27 -> V_38 ) ;
F_90 ( & V_27 -> V_41 ) ;
F_91 ( & V_27 -> V_34 ) ;
F_90 ( & V_27 -> V_50 ) ;
F_92 ( & V_27 -> V_75 ) ;
V_27 -> V_31 = V_2 ;
V_27 -> V_33 = type ;
F_93 ( & V_27 -> V_68 , 1 ) ;
return V_27 ;
}
struct V_27 * F_94 ( struct V_1 * V_2 , unsigned int V_15 , int type )
{
unsigned int V_35 = F_13 ( V_2 , V_15 , type ) ;
struct V_27 * V_27 = NULL , * V_113 = NULL ;
if ( ! F_71 ( V_2 , type ) )
return NULL ;
V_109:
F_5 ( & V_11 ) ;
F_5 ( & V_114 ) ;
if ( ! F_71 ( V_2 , type ) ) {
F_6 ( & V_114 ) ;
F_6 ( & V_11 ) ;
goto V_81;
}
F_6 ( & V_114 ) ;
V_27 = F_18 ( V_35 , V_2 , V_15 , type ) ;
if ( ! V_27 ) {
if ( ! V_113 ) {
F_6 ( & V_11 ) ;
V_113 = F_88 ( V_2 , type ) ;
if ( ! V_113 )
F_65 () ;
goto V_109;
}
V_27 = V_113 ;
V_113 = NULL ;
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
F_23 ( V_115 ) ;
F_23 ( V_80 ) ;
}
F_31 ( V_27 ) ;
if ( ! F_35 ( V_64 , & V_27 -> V_46 ) &&
V_2 -> V_47 -> V_116 ( V_27 ) < 0 ) {
F_43 ( V_27 ) ;
V_27 = NULL ;
goto V_81;
}
#ifdef F_80
F_85 ( ! V_27 -> V_31 ) ;
#endif
V_81:
if ( V_113 )
F_59 ( V_113 ) ;
return V_27 ;
}
static int F_95 ( struct V_117 * V_117 , int type )
{
int V_54 ;
if ( F_96 ( V_117 ) )
return 0 ;
if ( type != - 1 )
return ! V_117 -> V_118 [ type ] ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( ! V_117 -> V_118 [ V_54 ] )
return 1 ;
return 0 ;
}
static void F_97 ( struct V_1 * V_2 , int type )
{
struct V_117 * V_117 , * V_119 = NULL ;
#ifdef F_80
int V_120 = 0 ;
#endif
F_5 ( & V_121 ) ;
F_69 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_117 -> V_122 ) ;
if ( ( V_117 -> V_123 & ( V_124 | V_125 | V_126 ) ) ||
! F_55 ( & V_117 -> V_127 ) ||
! F_95 ( V_117 , type ) ) {
F_6 ( & V_117 -> V_122 ) ;
continue;
}
#ifdef F_80
if ( F_98 ( F_99 ( V_117 ) > 0 ) )
V_120 = 1 ;
#endif
F_100 ( V_117 ) ;
F_6 ( & V_117 -> V_122 ) ;
F_6 ( & V_121 ) ;
F_101 ( V_119 ) ;
F_102 ( V_117 , type ) ;
V_119 = V_117 ;
F_5 ( & V_121 ) ;
}
F_6 ( & V_121 ) ;
F_101 ( V_119 ) ;
#ifdef F_80
if ( V_120 ) {
F_81 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static inline int F_103 ( struct V_27 * V_27 )
{
if ( F_55 ( & V_27 -> V_68 ) <= 1 )
return 1 ;
return 0 ;
}
static int F_104 ( struct V_117 * V_117 , int type ,
struct V_82 * V_128 )
{
struct V_27 * V_27 = V_117 -> V_118 [ type ] ;
V_117 -> V_118 [ type ] = NULL ;
if ( V_27 ) {
if ( F_103 ( V_27 ) ) {
#ifdef F_80
if ( F_55 ( & V_27 -> V_68 ) != 1 )
F_81 ( V_117 -> V_129 , L_8
L_9 ,
F_55 ( & V_27 -> V_68 ) ) ;
#endif
F_5 ( & V_11 ) ;
F_39 ( & V_27 -> V_38 , V_128 ) ;
F_6 ( & V_11 ) ;
return 1 ;
}
else
F_43 ( V_27 ) ;
}
return 0 ;
}
static void F_105 ( struct V_82 * V_128 )
{
struct V_82 * V_130 ;
struct V_27 * V_27 ;
V_130 = V_128 -> V_131 ;
while ( V_130 != V_128 ) {
V_27 = F_77 ( V_130 , struct V_27 , V_38 ) ;
V_130 = V_130 -> V_131 ;
F_26 ( & V_27 -> V_38 ) ;
F_43 ( V_27 ) ;
}
}
static void F_106 ( struct V_1 * V_2 , int type ,
struct V_82 * V_128 )
{
struct V_117 * V_117 ;
int V_120 = 0 ;
F_5 ( & V_121 ) ;
F_69 (inode, &sb->s_inodes, i_sb_list) {
if ( ! F_96 ( V_117 ) ) {
if ( F_98 ( F_99 ( V_117 ) > 0 ) )
V_120 = 1 ;
F_104 ( V_117 , type , V_128 ) ;
}
}
F_6 ( & V_121 ) ;
#ifdef F_80
if ( V_120 ) {
F_3 ( V_132 L_10
L_11
L_12 , V_2 -> V_9 ) ;
}
#endif
}
static void F_107 ( struct V_1 * V_2 , int type )
{
F_108 ( V_128 ) ;
if ( V_2 -> V_47 ) {
F_109 ( & F_40 ( V_2 ) -> V_133 ) ;
F_106 ( V_2 , type , & V_128 ) ;
F_110 ( & F_40 ( V_2 ) -> V_133 ) ;
F_105 ( & V_128 ) ;
}
}
static inline void F_111 ( struct V_27 * V_27 , T_2 V_134 )
{
V_27 -> V_135 . V_136 += V_134 ;
}
static inline void F_112 ( struct V_27 * V_27 , T_2 V_134 )
{
V_27 -> V_135 . V_137 += V_134 ;
}
static inline void F_113 ( struct V_27 * V_27 , T_2 V_134 )
{
V_27 -> V_135 . V_138 += V_134 ;
}
static void F_114 ( struct V_27 * V_27 , T_2 V_134 )
{
if ( V_27 -> V_135 . V_138 < V_134 ) {
F_115 ( 1 ) ;
V_134 = V_27 -> V_135 . V_138 ;
}
V_27 -> V_135 . V_137 += V_134 ;
V_27 -> V_135 . V_138 -= V_134 ;
}
static inline
void F_116 ( struct V_27 * V_27 , T_2 V_134 )
{
if ( V_27 -> V_135 . V_138 >= V_134 )
V_27 -> V_135 . V_138 -= V_134 ;
else {
F_115 ( 1 ) ;
V_27 -> V_135 . V_138 = 0 ;
}
}
static void F_117 ( struct V_27 * V_27 , T_2 V_134 )
{
if ( F_40 ( V_27 -> V_31 ) -> V_87 & V_139 ||
V_27 -> V_135 . V_136 >= V_134 )
V_27 -> V_135 . V_136 -= V_134 ;
else
V_27 -> V_135 . V_136 = 0 ;
if ( V_27 -> V_135 . V_136 <= V_27 -> V_135 . V_140 )
V_27 -> V_135 . V_141 = ( V_142 ) 0 ;
F_56 ( V_143 , & V_27 -> V_46 ) ;
}
static void F_118 ( struct V_27 * V_27 , T_2 V_134 )
{
if ( F_40 ( V_27 -> V_31 ) -> V_87 & V_139 ||
V_27 -> V_135 . V_137 >= V_134 )
V_27 -> V_135 . V_137 -= V_134 ;
else
V_27 -> V_135 . V_137 = 0 ;
if ( V_27 -> V_135 . V_137 <= V_27 -> V_135 . V_144 )
V_27 -> V_135 . V_145 = ( V_142 ) 0 ;
F_56 ( V_146 , & V_27 -> V_46 ) ;
}
static int F_119 ( struct V_27 * V_27 , const int V_147 )
{
int V_148 = ( V_147 == V_149 ||
V_147 == V_150 ) ? V_146 :
( ( V_147 == V_151 ||
V_147 == V_152 ) ? V_143 : 0 ) ;
if ( ! V_148 )
return 0 ;
return F_38 ( V_148 , & V_27 -> V_46 ) ;
}
static int F_120 ( struct V_27 * V_27 )
{
if ( ! V_153 )
return 0 ;
switch ( V_27 -> V_33 ) {
case V_154 :
return F_121 () == V_27 -> V_32 ;
case V_155 :
return F_122 ( V_27 -> V_32 ) ;
}
return 0 ;
}
static void F_123 ( struct V_27 * V_27 , const int V_147 )
{
char * V_156 = NULL ;
struct V_157 * V_158 ;
if ( V_147 == V_159 ||
V_147 == V_160 ||
V_147 == V_161 ||
V_147 == V_162 || ! F_120 ( V_27 ) )
return;
V_158 = F_124 () ;
if ( ! V_158 )
return;
F_125 ( V_158 , V_27 -> V_31 -> V_9 ) ;
if ( V_147 == V_163 || V_147 == V_164 )
F_125 ( V_158 , L_13 ) ;
else
F_125 ( V_158 , L_14 ) ;
F_125 ( V_158 , V_107 [ V_27 -> V_33 ] ) ;
switch ( V_147 ) {
case V_151 :
V_156 = L_15 ;
break;
case V_152 :
V_156 = L_16 ;
break;
case V_163 :
V_156 = L_17 ;
break;
case V_149 :
V_156 = L_18 ;
break;
case V_150 :
V_156 = L_19 ;
break;
case V_164 :
V_156 = L_20 ;
break;
}
F_125 ( V_158 , V_156 ) ;
F_126 ( V_158 ) ;
}
static void F_127 ( struct V_27 * const * V_165 , char * V_147 )
{
struct V_27 * V_166 ;
int V_167 ;
for ( V_167 = 0 ; V_167 < V_24 ; V_167 ++ ) {
V_166 = V_165 [ V_167 ] ;
if ( V_166 && V_147 [ V_167 ] != V_168 &&
! F_119 ( V_166 , V_147 [ V_167 ] ) ) {
#ifdef F_128
F_123 ( V_166 , V_147 [ V_167 ] ) ;
#endif
F_129 ( V_166 -> V_33 , V_166 -> V_32 ,
V_166 -> V_31 -> V_169 , V_147 [ V_167 ] ) ;
}
}
}
static int F_130 ( struct V_27 * V_27 )
{
struct V_170 * V_51 = & F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] ;
return F_131 ( V_171 ) &&
( V_51 -> V_172 -> V_16 != V_173 ||
! ( V_51 -> V_56 & V_174 ) ) ;
}
static int F_132 ( struct V_27 * V_27 , T_2 V_175 , char * V_147 )
{
T_2 V_176 = V_27 -> V_135 . V_136 + V_175 ;
* V_147 = V_168 ;
if ( ! F_133 ( V_27 -> V_31 , V_27 -> V_33 ) ||
F_35 ( V_177 , & V_27 -> V_46 ) )
return 0 ;
if ( V_27 -> V_135 . V_178 &&
V_176 > V_27 -> V_135 . V_178 &&
! F_130 ( V_27 ) ) {
* V_147 = V_151 ;
return - V_179 ;
}
if ( V_27 -> V_135 . V_140 &&
V_176 > V_27 -> V_135 . V_140 &&
V_27 -> V_135 . V_141 &&
F_134 () >= V_27 -> V_135 . V_141 &&
! F_130 ( V_27 ) ) {
* V_147 = V_152 ;
return - V_179 ;
}
if ( V_27 -> V_135 . V_140 &&
V_176 > V_27 -> V_135 . V_140 &&
V_27 -> V_135 . V_141 == 0 ) {
* V_147 = V_163 ;
V_27 -> V_135 . V_141 = F_134 () +
F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] . V_180 ;
}
return 0 ;
}
static int F_135 ( struct V_27 * V_27 , T_2 V_181 , int V_182 , char * V_147 )
{
T_2 V_183 ;
struct V_1 * V_2 = V_27 -> V_31 ;
* V_147 = V_168 ;
if ( ! F_133 ( V_2 , V_27 -> V_33 ) ||
F_35 ( V_177 , & V_27 -> V_46 ) )
return 0 ;
V_183 = V_27 -> V_135 . V_137 + V_27 -> V_135 . V_138
+ V_181 ;
if ( V_27 -> V_135 . V_184 &&
V_183 > V_27 -> V_135 . V_184 &&
! F_130 ( V_27 ) ) {
if ( ! V_182 )
* V_147 = V_149 ;
return - V_179 ;
}
if ( V_27 -> V_135 . V_144 &&
V_183 > V_27 -> V_135 . V_144 &&
V_27 -> V_135 . V_145 &&
F_134 () >= V_27 -> V_135 . V_145 &&
! F_130 ( V_27 ) ) {
if ( ! V_182 )
* V_147 = V_150 ;
return - V_179 ;
}
if ( V_27 -> V_135 . V_144 &&
V_183 > V_27 -> V_135 . V_144 &&
V_27 -> V_135 . V_145 == 0 ) {
if ( ! V_182 ) {
* V_147 = V_164 ;
V_27 -> V_135 . V_145 = F_134 () +
F_40 ( V_2 ) -> V_51 [ V_27 -> V_33 ] . V_185 ;
}
else
return - V_179 ;
}
return 0 ;
}
static int F_136 ( struct V_27 * V_27 , T_2 V_175 )
{
T_2 V_176 ;
if ( F_35 ( V_177 , & V_27 -> V_46 ) ||
V_27 -> V_135 . V_136 <= V_27 -> V_135 . V_140 ||
! F_133 ( V_27 -> V_31 , V_27 -> V_33 ) )
return V_168 ;
V_176 = V_27 -> V_135 . V_136 - V_175 ;
if ( V_176 <= V_27 -> V_135 . V_140 )
return V_160 ;
if ( V_27 -> V_135 . V_136 >= V_27 -> V_135 . V_178 &&
V_176 < V_27 -> V_135 . V_178 )
return V_159 ;
return V_168 ;
}
static int F_137 ( struct V_27 * V_27 , T_2 V_181 )
{
if ( F_35 ( V_177 , & V_27 -> V_46 ) ||
V_27 -> V_135 . V_137 <= V_27 -> V_135 . V_144 )
return V_168 ;
if ( V_27 -> V_135 . V_137 - V_181 <= V_27 -> V_135 . V_144 )
return V_162 ;
if ( V_27 -> V_135 . V_137 >= V_27 -> V_135 . V_184 &&
V_27 -> V_135 . V_137 - V_181 < V_27 -> V_135 . V_184 )
return V_161 ;
return V_168 ;
}
static int F_138 ( const struct V_117 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_129 ;
if ( F_96 ( V_117 ) )
return 0 ;
return F_139 ( V_2 ) & ~ F_140 ( V_2 ) ;
}
static void F_102 ( struct V_117 * V_117 , int type )
{
unsigned int V_15 = 0 ;
int V_54 ;
struct V_27 * V_186 [ V_24 ] ;
struct V_1 * V_2 = V_117 -> V_129 ;
T_2 V_187 ;
if ( ! F_138 ( V_117 ) )
return;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_186 [ V_54 ] = NULL ;
if ( type != - 1 && V_54 != type )
continue;
switch ( V_54 ) {
case V_154 :
V_15 = V_117 -> V_188 ;
break;
case V_155 :
V_15 = V_117 -> V_189 ;
break;
}
V_186 [ V_54 ] = F_94 ( V_2 , V_15 , V_54 ) ;
}
F_109 ( & F_40 ( V_2 ) -> V_133 ) ;
if ( F_96 ( V_117 ) )
goto V_190;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_71 ( V_2 , V_54 ) )
continue;
if ( ! V_186 [ V_54 ] )
continue;
if ( ! V_117 -> V_118 [ V_54 ] ) {
V_117 -> V_118 [ V_54 ] = V_186 [ V_54 ] ;
V_186 [ V_54 ] = NULL ;
V_187 = F_99 ( V_117 ) ;
if ( F_98 ( V_187 ) )
F_113 ( V_117 -> V_118 [ V_54 ] , V_187 ) ;
}
}
V_190:
F_110 ( & F_40 ( V_2 ) -> V_133 ) ;
F_42 ( V_186 ) ;
}
void F_141 ( struct V_117 * V_117 )
{
F_102 ( V_117 , - 1 ) ;
}
static void F_142 ( struct V_117 * V_117 )
{
int V_54 ;
struct V_27 * V_191 [ V_24 ] ;
F_109 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_191 [ V_54 ] = V_117 -> V_118 [ V_54 ] ;
V_117 -> V_118 [ V_54 ] = NULL ;
}
F_110 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_42 ( V_191 ) ;
}
void F_143 ( struct V_117 * V_117 )
{
int V_54 ;
if ( F_96 ( V_117 ) )
return;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( V_117 -> V_118 [ V_54 ] )
break;
}
if ( V_54 < V_24 )
F_142 ( V_117 ) ;
}
static T_2 * F_144 ( struct V_117 * V_117 )
{
F_85 ( ! V_117 -> V_129 -> V_47 -> V_192 ) ;
return V_117 -> V_129 -> V_47 -> V_192 ( V_117 ) ;
}
void F_145 ( struct V_117 * V_117 , T_2 V_134 )
{
F_5 ( & V_117 -> V_122 ) ;
* F_144 ( V_117 ) += V_134 ;
F_6 ( & V_117 -> V_122 ) ;
}
void F_146 ( struct V_117 * V_117 , T_2 V_134 )
{
F_5 ( & V_117 -> V_122 ) ;
* F_144 ( V_117 ) -= V_134 ;
F_147 ( V_117 , V_134 ) ;
F_6 ( & V_117 -> V_122 ) ;
}
void F_148 ( struct V_117 * V_117 , T_2 V_134 )
{
F_5 ( & V_117 -> V_122 ) ;
* F_144 ( V_117 ) -= V_134 ;
F_6 ( & V_117 -> V_122 ) ;
}
static T_2 F_99 ( struct V_117 * V_117 )
{
T_2 V_49 ;
if ( ! V_117 -> V_129 -> V_47 -> V_192 )
return 0 ;
F_5 ( & V_117 -> V_122 ) ;
V_49 = * F_144 ( V_117 ) ;
F_6 ( & V_117 -> V_122 ) ;
return V_49 ;
}
static void F_149 ( struct V_117 * V_117 , T_2 V_134 ,
int V_193 )
{
if ( V_193 )
F_145 ( V_117 , V_134 ) ;
else
F_150 ( V_117 , V_134 ) ;
}
static void F_151 ( struct V_117 * V_117 , T_2 V_134 , int V_193 )
{
if ( V_193 )
F_148 ( V_117 , V_134 ) ;
else
F_152 ( V_117 , V_134 ) ;
}
int F_153 ( struct V_117 * V_117 , T_2 V_134 , int V_87 )
{
int V_54 , V_49 = 0 ;
char V_147 [ V_24 ] ;
int V_194 = V_87 & V_195 ;
int V_193 = V_87 & V_196 ;
int V_197 = V_87 & V_198 ;
if ( ! F_138 ( V_117 ) ) {
F_149 ( V_117 , V_134 , V_193 ) ;
goto V_81;
}
F_154 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
V_147 [ V_54 ] = V_168 ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_117 -> V_118 [ V_54 ] )
continue;
V_49 = F_135 ( V_117 -> V_118 [ V_54 ] , V_134 , ! V_194 ,
V_147 + V_54 ) ;
if ( V_49 && ! V_197 ) {
F_6 ( & V_199 ) ;
goto V_200;
}
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_117 -> V_118 [ V_54 ] )
continue;
if ( V_193 )
F_113 ( V_117 -> V_118 [ V_54 ] , V_134 ) ;
else
F_112 ( V_117 -> V_118 [ V_54 ] , V_134 ) ;
}
F_149 ( V_117 , V_134 , V_193 ) ;
F_6 ( & V_199 ) ;
if ( V_193 )
goto V_200;
F_41 ( V_117 -> V_118 ) ;
V_200:
F_127 ( V_117 -> V_118 , V_147 ) ;
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
V_81:
return V_49 ;
}
int F_156 ( const struct V_117 * V_117 )
{
int V_54 , V_49 = 0 ;
char V_147 [ V_24 ] ;
if ( ! F_138 ( V_117 ) )
return 0 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
V_147 [ V_54 ] = V_168 ;
F_154 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_117 -> V_118 [ V_54 ] )
continue;
V_49 = F_132 ( V_117 -> V_118 [ V_54 ] , 1 , V_147 + V_54 ) ;
if ( V_49 )
goto V_201;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_117 -> V_118 [ V_54 ] )
continue;
F_111 ( V_117 -> V_118 [ V_54 ] , 1 ) ;
}
V_201:
F_6 ( & V_199 ) ;
if ( V_49 == 0 )
F_41 ( V_117 -> V_118 ) ;
F_127 ( V_117 -> V_118 , V_147 ) ;
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
return V_49 ;
}
int F_157 ( struct V_117 * V_117 , T_2 V_134 )
{
int V_54 ;
if ( ! F_138 ( V_117 ) ) {
F_146 ( V_117 , V_134 ) ;
return 0 ;
}
F_154 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( V_117 -> V_118 [ V_54 ] )
F_114 ( V_117 -> V_118 [ V_54 ] ,
V_134 ) ;
}
F_146 ( V_117 , V_134 ) ;
F_6 ( & V_199 ) ;
F_41 ( V_117 -> V_118 ) ;
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
return 0 ;
}
void F_158 ( struct V_117 * V_117 , T_2 V_134 , int V_87 )
{
unsigned int V_54 ;
char V_147 [ V_24 ] ;
int V_193 = V_87 & V_196 ;
if ( ! F_138 ( V_117 ) ) {
F_151 ( V_117 , V_134 , V_193 ) ;
return;
}
F_154 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_117 -> V_118 [ V_54 ] )
continue;
V_147 [ V_54 ] = F_137 ( V_117 -> V_118 [ V_54 ] , V_134 ) ;
if ( V_193 )
F_116 ( V_117 -> V_118 [ V_54 ] , V_134 ) ;
else
F_118 ( V_117 -> V_118 [ V_54 ] , V_134 ) ;
}
F_151 ( V_117 , V_134 , V_193 ) ;
F_6 ( & V_199 ) ;
if ( V_193 )
goto V_202;
F_41 ( V_117 -> V_118 ) ;
V_202:
F_127 ( V_117 -> V_118 , V_147 ) ;
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
}
void F_159 ( const struct V_117 * V_117 )
{
unsigned int V_54 ;
char V_147 [ V_24 ] ;
if ( ! F_138 ( V_117 ) )
return;
F_154 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_5 ( & V_199 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_117 -> V_118 [ V_54 ] )
continue;
V_147 [ V_54 ] = F_136 ( V_117 -> V_118 [ V_54 ] , 1 ) ;
F_117 ( V_117 -> V_118 [ V_54 ] , 1 ) ;
}
F_6 ( & V_199 ) ;
F_41 ( V_117 -> V_118 ) ;
F_127 ( V_117 -> V_118 , V_147 ) ;
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
}
int F_160 ( struct V_117 * V_117 , struct V_27 * * V_203 )
{
T_2 V_181 , V_204 ;
T_2 V_205 = 0 ;
struct V_27 * V_206 [ V_24 ] = {} ;
int V_54 , V_49 = 0 ;
char V_207 [ V_24 ] = {} ;
char V_208 [ V_24 ] ;
char V_209 [ V_24 ] , V_210 [ V_24 ] ;
if ( F_96 ( V_117 ) )
return 0 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
V_208 [ V_54 ] = V_168 ;
F_109 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
if ( F_96 ( V_117 ) ) {
F_110 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
return 0 ;
}
F_5 ( & V_199 ) ;
V_204 = F_161 ( V_117 ) ;
V_205 = F_99 ( V_117 ) ;
V_181 = V_204 + V_205 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_203 [ V_54 ] )
continue;
if ( ! F_71 ( V_117 -> V_129 , V_54 ) )
continue;
V_207 [ V_54 ] = 1 ;
V_206 [ V_54 ] = V_117 -> V_118 [ V_54 ] ;
V_49 = F_132 ( V_203 [ V_54 ] , 1 , V_208 + V_54 ) ;
if ( V_49 )
goto V_211;
V_49 = F_135 ( V_203 [ V_54 ] , V_181 , 0 , V_208 + V_54 ) ;
if ( V_49 )
goto V_211;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_207 [ V_54 ] )
continue;
if ( V_206 [ V_54 ] ) {
V_209 [ V_54 ] =
F_136 ( V_206 [ V_54 ] , 1 ) ;
V_210 [ V_54 ] =
F_137 ( V_206 [ V_54 ] , V_181 ) ;
F_117 ( V_206 [ V_54 ] , 1 ) ;
F_118 ( V_206 [ V_54 ] , V_204 ) ;
F_116 ( V_206 [ V_54 ] ,
V_205 ) ;
}
F_111 ( V_203 [ V_54 ] , 1 ) ;
F_112 ( V_203 [ V_54 ] , V_204 ) ;
F_113 ( V_203 [ V_54 ] , V_205 ) ;
V_117 -> V_118 [ V_54 ] = V_203 [ V_54 ] ;
}
F_6 ( & V_199 ) ;
F_110 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_41 ( V_206 ) ;
F_41 ( V_203 ) ;
F_127 ( V_203 , V_208 ) ;
F_127 ( V_206 , V_209 ) ;
F_127 ( V_206 , V_210 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_207 [ V_54 ] )
V_203 [ V_54 ] = V_206 [ V_54 ] ;
return 0 ;
V_211:
F_6 ( & V_199 ) ;
F_110 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_127 ( V_203 , V_208 ) ;
return V_49 ;
}
int F_162 ( struct V_117 * V_117 , struct V_212 * V_212 )
{
struct V_27 * V_203 [ V_24 ] = {} ;
struct V_1 * V_2 = V_117 -> V_129 ;
int V_49 ;
if ( ! F_138 ( V_117 ) )
return 0 ;
if ( V_212 -> V_213 & V_214 && V_212 -> V_215 != V_117 -> V_188 )
V_203 [ V_154 ] = F_94 ( V_2 , V_212 -> V_215 , V_154 ) ;
if ( V_212 -> V_213 & V_216 && V_212 -> V_217 != V_117 -> V_189 )
V_203 [ V_155 ] = F_94 ( V_2 , V_212 -> V_217 , V_155 ) ;
V_49 = F_160 ( V_117 , V_203 ) ;
F_42 ( V_203 ) ;
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
int F_164 ( struct V_117 * V_117 , struct V_218 * V_218 )
{
int error ;
error = F_165 ( V_117 , V_218 ) ;
if ( ! error && ( V_218 -> V_219 & V_220 ) )
F_141 ( V_117 ) ;
return error ;
}
int F_166 ( struct V_1 * V_2 , int type , unsigned int V_87 )
{
int V_54 , V_49 = 0 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
struct V_117 * V_221 [ V_24 ] ;
if ( ( V_87 & V_222 && ! ( V_87 & V_223 ) )
|| ( V_87 & V_224 && V_87 & ( V_223 |
V_222 ) ) )
return - V_225 ;
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_139 ( V_2 ) ) {
F_33 ( & V_59 -> V_79 ) ;
return 0 ;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_221 [ V_54 ] = NULL ;
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_167 ( V_2 , V_54 ) )
continue;
if ( V_87 & V_224 ) {
F_5 ( & V_114 ) ;
V_59 -> V_87 |=
F_168 ( V_224 , V_54 ) ;
F_6 ( & V_114 ) ;
} else {
F_5 ( & V_114 ) ;
V_59 -> V_87 &= ~ F_168 ( V_87 , V_54 ) ;
if ( ! F_167 ( V_2 , V_54 ) &&
F_169 ( V_2 , V_54 ) ) {
V_59 -> V_87 &= ~ F_168 (
V_224 , V_54 ) ;
F_6 ( & V_114 ) ;
F_101 ( V_59 -> V_92 [ V_54 ] ) ;
V_59 -> V_92 [ V_54 ] = NULL ;
continue;
}
F_6 ( & V_114 ) ;
}
if ( F_167 ( V_2 , V_54 ) && ! ( V_87 & V_224 ) )
continue;
F_107 ( V_2 , V_54 ) ;
F_60 ( V_2 , V_54 ) ;
if ( F_51 ( & V_59 -> V_51 [ V_54 ] ) )
V_2 -> V_47 -> V_85 ( V_2 , V_54 ) ;
if ( V_59 -> V_62 [ V_54 ] -> V_226 )
V_59 -> V_62 [ V_54 ] -> V_226 ( V_2 , V_54 ) ;
F_11 ( V_59 -> V_51 [ V_54 ] . V_172 ) ;
V_221 [ V_54 ] = V_59 -> V_92 [ V_54 ] ;
if ( ! F_167 ( V_2 , V_54 ) )
V_59 -> V_92 [ V_54 ] = NULL ;
V_59 -> V_51 [ V_54 ] . V_56 = 0 ;
V_59 -> V_51 [ V_54 ] . V_180 = 0 ;
V_59 -> V_51 [ V_54 ] . V_185 = 0 ;
V_59 -> V_62 [ V_54 ] = NULL ;
}
F_33 ( & V_59 -> V_79 ) ;
if ( V_59 -> V_87 & V_88 )
goto V_227;
if ( V_2 -> V_89 -> V_90 )
V_2 -> V_89 -> V_90 ( V_2 , 1 ) ;
F_73 ( V_2 -> V_91 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_221 [ V_54 ] ) {
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_167 ( V_2 , V_54 ) ) {
F_74 ( & V_221 [ V_54 ] -> V_93 ,
V_94 ) ;
V_221 [ V_54 ] -> V_228 &= ~ ( V_229 |
V_230 | V_231 ) ;
F_75 ( & V_221 [ V_54 ] -> V_95 ,
0 ) ;
F_33 ( & V_221 [ V_54 ] -> V_93 ) ;
F_170 ( V_221 [ V_54 ] ) ;
}
F_33 ( & V_59 -> V_79 ) ;
}
if ( V_2 -> V_91 )
F_171 ( V_2 -> V_91 ) ;
V_227:
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_221 [ V_54 ] ) {
if ( ! ( V_87 & V_224 ) )
F_101 ( V_221 [ V_54 ] ) ;
else if ( ! V_221 [ V_54 ] -> V_232 )
V_49 = - V_233 ;
}
return V_49 ;
}
int F_172 ( struct V_1 * V_2 , int type )
{
return F_166 ( V_2 , type ,
V_222 | V_223 ) ;
}
static int F_173 ( struct V_117 * V_117 , int type , int V_234 ,
unsigned int V_87 )
{
struct V_10 * V_4 = F_8 ( V_234 ) ;
struct V_1 * V_2 = V_117 -> V_129 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
int error ;
int V_235 = - 1 ;
if ( ! V_4 )
return - V_236 ;
if ( ! F_174 ( V_117 -> V_237 ) ) {
error = - V_238 ;
goto V_239;
}
if ( F_175 ( V_117 ) ) {
error = - V_240 ;
goto V_239;
}
if ( ! V_2 -> V_89 -> V_241 || ! V_2 -> V_89 -> V_242 ) {
error = - V_225 ;
goto V_239;
}
if ( ! ( V_87 & V_222 ) ) {
error = - V_225 ;
goto V_239;
}
if ( ! ( V_59 -> V_87 & V_88 ) ) {
F_176 ( V_2 ) ;
F_171 ( V_2 -> V_91 ) ;
}
F_32 ( & V_59 -> V_79 ) ;
if ( F_167 ( V_2 , type ) ) {
error = - V_233 ;
goto V_243;
}
if ( ! ( V_59 -> V_87 & V_88 ) ) {
F_74 ( & V_117 -> V_93 , V_94 ) ;
V_235 = V_117 -> V_228 & ( V_230 | V_229 |
V_231 ) ;
V_117 -> V_228 |= V_231 | V_230 | V_229 ;
F_33 ( & V_117 -> V_93 ) ;
F_142 ( V_117 ) ;
}
error = - V_67 ;
V_59 -> V_92 [ type ] = F_177 ( V_117 ) ;
if ( ! V_59 -> V_92 [ type ] )
goto V_243;
error = - V_225 ;
if ( ! V_4 -> V_244 -> V_245 ( V_2 , type ) )
goto V_246;
V_59 -> V_62 [ type ] = V_4 -> V_244 ;
V_59 -> V_51 [ type ] . V_172 = V_4 ;
V_59 -> V_51 [ type ] . V_247 = V_234 ;
F_90 ( & V_59 -> V_51 [ type ] . V_52 ) ;
F_32 ( & V_59 -> V_60 ) ;
error = V_59 -> V_62 [ type ] -> F_178 ( V_2 , type ) ;
if ( error < 0 ) {
F_33 ( & V_59 -> V_60 ) ;
goto V_246;
}
F_33 ( & V_59 -> V_60 ) ;
F_5 ( & V_114 ) ;
V_59 -> V_87 |= F_168 ( V_87 , type ) ;
F_6 ( & V_114 ) ;
F_97 ( V_2 , type ) ;
F_33 ( & V_59 -> V_79 ) ;
return 0 ;
V_246:
V_59 -> V_92 [ type ] = NULL ;
F_101 ( V_117 ) ;
V_243:
if ( V_235 != - 1 ) {
F_74 ( & V_117 -> V_93 , V_94 ) ;
V_117 -> V_228 &= ~ ( V_230 | V_231 | V_229 ) ;
V_117 -> V_228 |= V_235 ;
F_33 ( & V_117 -> V_93 ) ;
}
F_33 ( & V_59 -> V_79 ) ;
V_239:
F_11 ( V_4 ) ;
return error ;
}
int F_179 ( struct V_1 * V_2 , int type )
{
struct V_58 * V_59 = F_40 ( V_2 ) ;
struct V_117 * V_117 ;
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
V_117 = V_59 -> V_92 [ V_54 ] ;
V_59 -> V_92 [ V_54 ] = NULL ;
F_5 ( & V_114 ) ;
V_87 = V_59 -> V_87 & F_168 ( V_222 |
V_223 ,
V_54 ) ;
V_59 -> V_87 &= ~ F_168 ( V_248 , V_54 ) ;
F_6 ( & V_114 ) ;
F_33 ( & V_59 -> V_79 ) ;
V_87 = F_180 ( V_87 , V_54 ) ;
V_49 = F_173 ( V_117 , V_54 ,
V_59 -> V_51 [ V_54 ] . V_247 , V_87 ) ;
F_101 ( V_117 ) ;
}
return V_49 ;
}
int F_181 ( struct V_1 * V_2 , int type , int V_234 ,
struct V_249 * V_249 )
{
int error = F_182 ( V_249 -> V_250 ) ;
if ( error )
return error ;
if ( V_249 -> V_251 -> V_252 != V_2 )
error = - V_253 ;
else
error = F_173 ( V_249 -> V_250 -> V_254 , type ,
V_234 , V_222 |
V_223 ) ;
return error ;
}
int F_183 ( struct V_117 * V_117 , int type , int V_234 ,
unsigned int V_87 )
{
int V_49 = 0 ;
struct V_1 * V_2 = V_117 -> V_129 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
F_85 ( V_87 & V_224 ) ;
if ( ! V_87 )
return 0 ;
if ( F_167 ( V_2 , type ) ) {
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_167 ( V_2 , type ) ) {
F_33 ( & V_59 -> V_79 ) ;
goto V_255;
}
if ( V_87 & V_222 &&
F_184 ( V_2 , type ) ) {
V_49 = - V_233 ;
goto V_243;
}
if ( V_87 & V_223 &&
F_133 ( V_2 , type ) ) {
V_49 = - V_233 ;
goto V_243;
}
F_5 ( & V_114 ) ;
F_40 ( V_2 ) -> V_87 |= F_168 ( V_87 , type ) ;
F_6 ( & V_114 ) ;
V_243:
F_33 ( & V_59 -> V_79 ) ;
return V_49 ;
}
V_255:
return F_173 ( V_117 , type , V_234 , V_87 ) ;
}
int F_185 ( struct V_1 * V_2 , char * V_256 ,
int V_234 , int type )
{
struct V_250 * V_250 ;
int error ;
F_32 ( & V_2 -> V_257 -> V_254 -> V_93 ) ;
V_250 = F_186 ( V_256 , V_2 -> V_257 , strlen ( V_256 ) ) ;
F_33 ( & V_2 -> V_257 -> V_254 -> V_93 ) ;
if ( F_187 ( V_250 ) )
return F_188 ( V_250 ) ;
if ( ! V_250 -> V_254 ) {
error = - V_258 ;
goto V_81;
}
error = F_182 ( V_250 ) ;
if ( ! error )
error = F_173 ( V_250 -> V_254 , type , V_234 ,
V_222 | V_223 ) ;
V_81:
F_189 ( V_250 ) ;
return error ;
}
static inline T_2 F_190 ( T_2 V_259 )
{
return V_259 << V_260 ;
}
static inline T_2 F_191 ( T_2 V_181 )
{
return ( V_181 + V_261 - 1 ) >> V_260 ;
}
static void F_192 ( struct V_27 * V_27 , struct V_262 * V_263 )
{
struct V_264 * V_265 = & V_27 -> V_135 ;
memset ( V_263 , 0 , sizeof( * V_263 ) ) ;
V_263 -> V_266 = V_267 ;
V_263 -> V_268 = V_27 -> V_33 == V_154 ?
V_269 : V_270 ;
V_263 -> V_271 = V_27 -> V_32 ;
F_5 ( & V_199 ) ;
V_263 -> V_272 = F_191 ( V_265 -> V_184 ) ;
V_263 -> V_273 = F_191 ( V_265 -> V_144 ) ;
V_263 -> V_274 = V_265 -> V_178 ;
V_263 -> V_275 = V_265 -> V_140 ;
V_263 -> V_276 = V_265 -> V_137 + V_265 -> V_138 ;
V_263 -> V_277 = V_265 -> V_136 ;
V_263 -> V_278 = V_265 -> V_145 ;
V_263 -> V_279 = V_265 -> V_141 ;
F_6 ( & V_199 ) ;
}
int F_193 ( struct V_1 * V_2 , int type , T_3 V_15 ,
struct V_262 * V_263 )
{
struct V_27 * V_27 ;
V_27 = F_94 ( V_2 , V_15 , type ) ;
if ( ! V_27 )
return - V_236 ;
F_192 ( V_27 , V_263 ) ;
F_43 ( V_27 ) ;
return 0 ;
}
static int F_194 ( struct V_27 * V_27 , struct V_262 * V_263 )
{
struct V_264 * V_265 = & V_27 -> V_135 ;
int V_280 = 0 , V_281 = 0 ;
struct V_170 * V_282 = & F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] ;
if ( V_263 -> V_283 & ~ V_284 )
return - V_225 ;
if ( ( ( V_263 -> V_283 & V_285 ) &&
( V_263 -> V_273 > V_282 -> V_286 ) ) ||
( ( V_263 -> V_283 & V_287 ) &&
( V_263 -> V_272 > V_282 -> V_286 ) ) ||
( ( V_263 -> V_283 & V_288 ) &&
( V_263 -> V_275 > V_282 -> V_289 ) ) ||
( ( V_263 -> V_283 & V_290 ) &&
( V_263 -> V_274 > V_282 -> V_289 ) ) )
return - V_291 ;
F_5 ( & V_199 ) ;
if ( V_263 -> V_283 & V_292 ) {
V_265 -> V_137 = V_263 -> V_276 - V_265 -> V_138 ;
V_280 = 1 ;
F_47 ( V_293 + V_294 , & V_27 -> V_46 ) ;
}
if ( V_263 -> V_283 & V_285 )
V_265 -> V_144 = F_190 ( V_263 -> V_273 ) ;
if ( V_263 -> V_283 & V_287 )
V_265 -> V_184 = F_190 ( V_263 -> V_272 ) ;
if ( V_263 -> V_283 & ( V_285 | V_287 ) ) {
V_280 = 1 ;
F_47 ( V_293 + V_295 , & V_27 -> V_46 ) ;
}
if ( V_263 -> V_283 & V_296 ) {
V_265 -> V_136 = V_263 -> V_277 ;
V_281 = 1 ;
F_47 ( V_293 + V_297 , & V_27 -> V_46 ) ;
}
if ( V_263 -> V_283 & V_288 )
V_265 -> V_140 = V_263 -> V_275 ;
if ( V_263 -> V_283 & V_290 )
V_265 -> V_178 = V_263 -> V_274 ;
if ( V_263 -> V_283 & ( V_288 | V_290 ) ) {
V_281 = 1 ;
F_47 ( V_293 + V_298 , & V_27 -> V_46 ) ;
}
if ( V_263 -> V_283 & V_299 ) {
V_265 -> V_145 = V_263 -> V_278 ;
V_280 = 1 ;
F_47 ( V_293 + V_300 , & V_27 -> V_46 ) ;
}
if ( V_263 -> V_283 & V_301 ) {
V_265 -> V_141 = V_263 -> V_279 ;
V_281 = 1 ;
F_47 ( V_293 + V_302 , & V_27 -> V_46 ) ;
}
if ( V_280 ) {
if ( ! V_265 -> V_144 ||
V_265 -> V_137 < V_265 -> V_144 ) {
V_265 -> V_145 = 0 ;
F_56 ( V_146 , & V_27 -> V_46 ) ;
} else if ( ! ( V_263 -> V_283 & V_299 ) )
V_265 -> V_145 = F_134 () + V_282 -> V_185 ;
}
if ( V_281 ) {
if ( ! V_265 -> V_140 ||
V_265 -> V_136 < V_265 -> V_140 ) {
V_265 -> V_141 = 0 ;
F_56 ( V_143 , & V_27 -> V_46 ) ;
} else if ( ! ( V_263 -> V_283 & V_301 ) )
V_265 -> V_141 = F_134 () + V_282 -> V_180 ;
}
if ( V_265 -> V_184 || V_265 -> V_144 || V_265 -> V_178 ||
V_265 -> V_140 )
F_56 ( V_177 , & V_27 -> V_46 ) ;
else
F_47 ( V_177 , & V_27 -> V_46 ) ;
F_6 ( & V_199 ) ;
F_36 ( V_27 ) ;
return 0 ;
}
int F_195 ( struct V_1 * V_2 , int type , T_3 V_15 ,
struct V_262 * V_263 )
{
struct V_27 * V_27 ;
int V_303 ;
V_27 = F_94 ( V_2 , V_15 , type ) ;
if ( ! V_27 ) {
V_303 = - V_236 ;
goto V_81;
}
V_303 = F_194 ( V_27 , V_263 ) ;
F_43 ( V_27 ) ;
V_81:
return V_303 ;
}
int F_196 ( struct V_1 * V_2 , int type , struct V_304 * V_305 )
{
struct V_170 * V_306 ;
F_32 ( & F_40 ( V_2 ) -> V_79 ) ;
if ( ! F_71 ( V_2 , type ) ) {
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return - V_236 ;
}
V_306 = F_40 ( V_2 ) -> V_51 + type ;
F_5 ( & V_199 ) ;
V_305 -> V_185 = V_306 -> V_185 ;
V_305 -> V_180 = V_306 -> V_180 ;
V_305 -> V_56 = V_306 -> V_56 & V_307 ;
V_305 -> V_308 = V_309 ;
F_6 ( & V_199 ) ;
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return 0 ;
}
int F_197 ( struct V_1 * V_2 , int type , struct V_304 * V_305 )
{
struct V_170 * V_306 ;
int V_53 = 0 ;
F_32 ( & F_40 ( V_2 ) -> V_79 ) ;
if ( ! F_71 ( V_2 , type ) ) {
V_53 = - V_236 ;
goto V_81;
}
V_306 = F_40 ( V_2 ) -> V_51 + type ;
F_5 ( & V_199 ) ;
if ( V_305 -> V_308 & V_310 )
V_306 -> V_185 = V_305 -> V_185 ;
if ( V_305 -> V_308 & V_311 )
V_306 -> V_180 = V_305 -> V_180 ;
if ( V_305 -> V_308 & V_312 )
V_306 -> V_56 = ( V_306 -> V_56 & ~ V_307 ) |
( V_305 -> V_56 & V_307 ) ;
F_6 ( & V_199 ) ;
F_46 ( V_2 , type ) ;
V_2 -> V_47 -> V_85 ( V_2 , type ) ;
V_81:
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return V_53 ;
}
static int F_198 ( struct V_313 * V_314 , int V_315 ,
void T_4 * V_316 , T_5 * V_317 , T_6 * V_318 )
{
unsigned int type = ( int * ) V_314 -> V_319 - V_104 . V_320 ;
V_104 . V_320 [ type ] =
F_199 ( & V_104 . V_105 [ type ] ) ;
return F_200 ( V_314 , V_315 , V_316 , V_317 , V_318 ) ;
}
static int T_7 F_201 ( void )
{
int V_167 , V_49 ;
unsigned long V_321 , V_322 ;
F_3 ( V_323 L_21 , V_324 ) ;
F_202 ( V_325 ) ;
V_71 = F_203 ( L_22 ,
sizeof( struct V_27 ) , sizeof( unsigned long ) * 4 ,
( V_326 | V_327 |
V_328 | V_329 ) ,
NULL ) ;
V_322 = 0 ;
V_30 = (struct V_28 * ) F_204 ( V_330 , V_322 ) ;
if ( ! V_30 )
F_205 ( L_23 ) ;
for ( V_167 = 0 ; V_167 < V_331 ; V_167 ++ ) {
V_49 = F_206 ( & V_104 . V_105 [ V_167 ] , 0 ) ;
if ( V_49 )
F_205 ( L_24 ) ;
}
V_321 = ( 1UL << V_322 ) * V_332 / sizeof( struct V_28 ) ;
V_25 = 0 ;
do {
V_25 ++ ;
} while ( V_321 >> V_25 );
V_25 -- ;
V_321 = 1UL << V_25 ;
V_26 = V_321 - 1 ;
for ( V_167 = 0 ; V_167 < V_321 ; V_167 ++ )
F_207 ( V_30 + V_167 ) ;
F_3 ( L_25 ,
V_321 , V_322 , ( V_332 << V_322 ) ) ;
F_208 ( & V_333 ) ;
return 0 ;
}

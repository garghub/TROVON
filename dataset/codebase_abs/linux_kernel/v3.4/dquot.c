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
static int F_120 ( struct V_153 * V_154 )
{
if ( ! V_155 )
return 0 ;
switch ( V_154 -> V_156 ) {
case V_157 :
return F_121 () == V_154 -> V_158 ;
case V_159 :
return F_122 ( V_154 -> V_158 ) ;
}
return 0 ;
}
static void F_123 ( struct V_153 * V_154 )
{
char * V_160 = NULL ;
struct V_161 * V_162 ;
int V_147 = V_154 -> V_163 ;
if ( V_147 == V_164 ||
V_147 == V_165 ||
V_147 == V_166 ||
V_147 == V_167 || ! F_120 ( V_154 ) )
return;
V_162 = F_124 () ;
if ( ! V_162 )
return;
F_125 ( V_162 , V_154 -> V_168 -> V_9 ) ;
if ( V_147 == V_169 || V_147 == V_170 )
F_125 ( V_162 , L_13 ) ;
else
F_125 ( V_162 , L_14 ) ;
F_125 ( V_162 , V_107 [ V_154 -> V_156 ] ) ;
switch ( V_147 ) {
case V_151 :
V_160 = L_15 ;
break;
case V_152 :
V_160 = L_16 ;
break;
case V_169 :
V_160 = L_17 ;
break;
case V_149 :
V_160 = L_18 ;
break;
case V_150 :
V_160 = L_19 ;
break;
case V_170 :
V_160 = L_20 ;
break;
}
F_125 ( V_162 , V_160 ) ;
F_126 ( V_162 ) ;
}
static void F_127 ( struct V_153 * V_154 , struct V_27 * V_27 ,
int V_147 )
{
if ( F_119 ( V_27 , V_147 ) )
return;
V_154 -> V_163 = V_147 ;
V_154 -> V_168 = V_27 -> V_31 ;
V_154 -> V_158 = V_27 -> V_32 ;
V_154 -> V_156 = V_27 -> V_33 ;
}
static void F_128 ( struct V_153 * V_154 )
{
int V_171 ;
for ( V_171 = 0 ; V_171 < V_24 ; V_171 ++ ) {
if ( V_154 [ V_171 ] . V_163 == V_172 )
continue;
#ifdef F_129
F_123 ( & V_154 [ V_171 ] ) ;
#endif
F_130 ( V_154 [ V_171 ] . V_156 , V_154 [ V_171 ] . V_158 ,
V_154 [ V_171 ] . V_168 -> V_173 , V_154 [ V_171 ] . V_163 ) ;
}
}
static int F_131 ( struct V_27 * V_27 )
{
struct V_174 * V_51 = & F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] ;
return F_132 ( V_175 ) &&
( V_51 -> V_176 -> V_16 != V_177 ||
! ( V_51 -> V_56 & V_178 ) ) ;
}
static int F_133 ( struct V_27 * V_27 , T_2 V_179 ,
struct V_153 * V_154 )
{
T_2 V_180 = V_27 -> V_135 . V_136 + V_179 ;
if ( ! F_134 ( V_27 -> V_31 , V_27 -> V_33 ) ||
F_35 ( V_181 , & V_27 -> V_46 ) )
return 0 ;
if ( V_27 -> V_135 . V_182 &&
V_180 > V_27 -> V_135 . V_182 &&
! F_131 ( V_27 ) ) {
F_127 ( V_154 , V_27 , V_151 ) ;
return - V_183 ;
}
if ( V_27 -> V_135 . V_140 &&
V_180 > V_27 -> V_135 . V_140 &&
V_27 -> V_135 . V_141 &&
F_135 () >= V_27 -> V_135 . V_141 &&
! F_131 ( V_27 ) ) {
F_127 ( V_154 , V_27 , V_152 ) ;
return - V_183 ;
}
if ( V_27 -> V_135 . V_140 &&
V_180 > V_27 -> V_135 . V_140 &&
V_27 -> V_135 . V_141 == 0 ) {
F_127 ( V_154 , V_27 , V_169 ) ;
V_27 -> V_135 . V_141 = F_135 () +
F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] . V_184 ;
}
return 0 ;
}
static int F_136 ( struct V_27 * V_27 , T_2 V_185 , int V_186 ,
struct V_153 * V_154 )
{
T_2 V_187 ;
struct V_1 * V_2 = V_27 -> V_31 ;
if ( ! F_134 ( V_2 , V_27 -> V_33 ) ||
F_35 ( V_181 , & V_27 -> V_46 ) )
return 0 ;
V_187 = V_27 -> V_135 . V_137 + V_27 -> V_135 . V_138
+ V_185 ;
if ( V_27 -> V_135 . V_188 &&
V_187 > V_27 -> V_135 . V_188 &&
! F_131 ( V_27 ) ) {
if ( ! V_186 )
F_127 ( V_154 , V_27 , V_149 ) ;
return - V_183 ;
}
if ( V_27 -> V_135 . V_144 &&
V_187 > V_27 -> V_135 . V_144 &&
V_27 -> V_135 . V_145 &&
F_135 () >= V_27 -> V_135 . V_145 &&
! F_131 ( V_27 ) ) {
if ( ! V_186 )
F_127 ( V_154 , V_27 , V_150 ) ;
return - V_183 ;
}
if ( V_27 -> V_135 . V_144 &&
V_187 > V_27 -> V_135 . V_144 &&
V_27 -> V_135 . V_145 == 0 ) {
if ( ! V_186 ) {
F_127 ( V_154 , V_27 , V_170 ) ;
V_27 -> V_135 . V_145 = F_135 () +
F_40 ( V_2 ) -> V_51 [ V_27 -> V_33 ] . V_189 ;
}
else
return - V_183 ;
}
return 0 ;
}
static int F_137 ( struct V_27 * V_27 , T_2 V_179 )
{
T_2 V_180 ;
if ( F_35 ( V_181 , & V_27 -> V_46 ) ||
V_27 -> V_135 . V_136 <= V_27 -> V_135 . V_140 ||
! F_134 ( V_27 -> V_31 , V_27 -> V_33 ) )
return V_172 ;
V_180 = V_27 -> V_135 . V_136 - V_179 ;
if ( V_180 <= V_27 -> V_135 . V_140 )
return V_165 ;
if ( V_27 -> V_135 . V_136 >= V_27 -> V_135 . V_182 &&
V_180 < V_27 -> V_135 . V_182 )
return V_164 ;
return V_172 ;
}
static int F_138 ( struct V_27 * V_27 , T_2 V_185 )
{
if ( F_35 ( V_181 , & V_27 -> V_46 ) ||
V_27 -> V_135 . V_137 <= V_27 -> V_135 . V_144 )
return V_172 ;
if ( V_27 -> V_135 . V_137 - V_185 <= V_27 -> V_135 . V_144 )
return V_167 ;
if ( V_27 -> V_135 . V_137 >= V_27 -> V_135 . V_188 &&
V_27 -> V_135 . V_137 - V_185 < V_27 -> V_135 . V_188 )
return V_166 ;
return V_172 ;
}
static int F_139 ( const struct V_117 * V_117 )
{
struct V_1 * V_2 = V_117 -> V_129 ;
if ( F_96 ( V_117 ) )
return 0 ;
return F_140 ( V_2 ) & ~ F_141 ( V_2 ) ;
}
static void F_102 ( struct V_117 * V_117 , int type )
{
unsigned int V_15 = 0 ;
int V_54 ;
struct V_27 * V_190 [ V_24 ] ;
struct V_1 * V_2 = V_117 -> V_129 ;
T_2 V_191 ;
if ( ! F_139 ( V_117 ) )
return;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_190 [ V_54 ] = NULL ;
if ( type != - 1 && V_54 != type )
continue;
switch ( V_54 ) {
case V_157 :
V_15 = V_117 -> V_192 ;
break;
case V_159 :
V_15 = V_117 -> V_193 ;
break;
}
V_190 [ V_54 ] = F_94 ( V_2 , V_15 , V_54 ) ;
}
F_109 ( & F_40 ( V_2 ) -> V_133 ) ;
if ( F_96 ( V_117 ) )
goto V_194;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_71 ( V_2 , V_54 ) )
continue;
if ( ! V_190 [ V_54 ] )
continue;
if ( ! V_117 -> V_118 [ V_54 ] ) {
V_117 -> V_118 [ V_54 ] = V_190 [ V_54 ] ;
V_190 [ V_54 ] = NULL ;
V_191 = F_99 ( V_117 ) ;
if ( F_98 ( V_191 ) )
F_113 ( V_117 -> V_118 [ V_54 ] , V_191 ) ;
}
}
V_194:
F_110 ( & F_40 ( V_2 ) -> V_133 ) ;
F_42 ( V_190 ) ;
}
void F_142 ( struct V_117 * V_117 )
{
F_102 ( V_117 , - 1 ) ;
}
static void F_143 ( struct V_117 * V_117 )
{
int V_54 ;
struct V_27 * V_195 [ V_24 ] ;
F_109 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_195 [ V_54 ] = V_117 -> V_118 [ V_54 ] ;
V_117 -> V_118 [ V_54 ] = NULL ;
}
F_110 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_42 ( V_195 ) ;
}
void F_144 ( struct V_117 * V_117 )
{
int V_54 ;
if ( F_96 ( V_117 ) )
return;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( V_117 -> V_118 [ V_54 ] )
break;
}
if ( V_54 < V_24 )
F_143 ( V_117 ) ;
}
static T_2 * F_145 ( struct V_117 * V_117 )
{
F_85 ( ! V_117 -> V_129 -> V_47 -> V_196 ) ;
return V_117 -> V_129 -> V_47 -> V_196 ( V_117 ) ;
}
void F_146 ( struct V_117 * V_117 , T_2 V_134 )
{
F_5 ( & V_117 -> V_122 ) ;
* F_145 ( V_117 ) += V_134 ;
F_6 ( & V_117 -> V_122 ) ;
}
void F_147 ( struct V_117 * V_117 , T_2 V_134 )
{
F_5 ( & V_117 -> V_122 ) ;
* F_145 ( V_117 ) -= V_134 ;
F_148 ( V_117 , V_134 ) ;
F_6 ( & V_117 -> V_122 ) ;
}
void F_149 ( struct V_117 * V_117 , T_2 V_134 )
{
F_5 ( & V_117 -> V_122 ) ;
* F_145 ( V_117 ) -= V_134 ;
F_6 ( & V_117 -> V_122 ) ;
}
static T_2 F_99 ( struct V_117 * V_117 )
{
T_2 V_49 ;
if ( ! V_117 -> V_129 -> V_47 -> V_196 )
return 0 ;
F_5 ( & V_117 -> V_122 ) ;
V_49 = * F_145 ( V_117 ) ;
F_6 ( & V_117 -> V_122 ) ;
return V_49 ;
}
static void F_150 ( struct V_117 * V_117 , T_2 V_134 ,
int V_197 )
{
if ( V_197 )
F_146 ( V_117 , V_134 ) ;
else
F_151 ( V_117 , V_134 ) ;
}
static void F_152 ( struct V_117 * V_117 , T_2 V_134 , int V_197 )
{
if ( V_197 )
F_149 ( V_117 , V_134 ) ;
else
F_153 ( V_117 , V_134 ) ;
}
int F_154 ( struct V_117 * V_117 , T_2 V_134 , int V_87 )
{
int V_54 , V_49 = 0 ;
struct V_153 V_154 [ V_24 ] ;
struct V_27 * * V_198 = V_117 -> V_118 ;
int V_197 = V_87 & V_199 ;
if ( ! F_139 ( V_117 ) ) {
F_150 ( V_117 , V_134 , V_197 ) ;
goto V_81;
}
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
V_154 [ V_54 ] . V_163 = V_172 ;
F_5 ( & V_200 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_198 [ V_54 ] )
continue;
V_49 = F_136 ( V_198 [ V_54 ] , V_134 ,
! ( V_87 & V_201 ) , & V_154 [ V_54 ] ) ;
if ( V_49 && ! ( V_87 & V_202 ) ) {
F_6 ( & V_200 ) ;
goto V_203;
}
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_198 [ V_54 ] )
continue;
if ( V_197 )
F_113 ( V_198 [ V_54 ] , V_134 ) ;
else
F_112 ( V_198 [ V_54 ] , V_134 ) ;
}
F_150 ( V_117 , V_134 , V_197 ) ;
F_6 ( & V_200 ) ;
if ( V_197 )
goto V_203;
F_41 ( V_198 ) ;
V_203:
F_156 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_128 ( V_154 ) ;
V_81:
return V_49 ;
}
int F_157 ( const struct V_117 * V_117 )
{
int V_54 , V_49 = 0 ;
struct V_153 V_154 [ V_24 ] ;
struct V_27 * const * V_198 = V_117 -> V_118 ;
if ( ! F_139 ( V_117 ) )
return 0 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
V_154 [ V_54 ] . V_163 = V_172 ;
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_5 ( & V_200 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_198 [ V_54 ] )
continue;
V_49 = F_133 ( V_198 [ V_54 ] , 1 , & V_154 [ V_54 ] ) ;
if ( V_49 )
goto V_204;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_198 [ V_54 ] )
continue;
F_111 ( V_198 [ V_54 ] , 1 ) ;
}
V_204:
F_6 ( & V_200 ) ;
if ( V_49 == 0 )
F_41 ( V_198 ) ;
F_156 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_128 ( V_154 ) ;
return V_49 ;
}
int F_158 ( struct V_117 * V_117 , T_2 V_134 )
{
int V_54 ;
if ( ! F_139 ( V_117 ) ) {
F_147 ( V_117 , V_134 ) ;
return 0 ;
}
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_5 ( & V_200 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( V_117 -> V_118 [ V_54 ] )
F_114 ( V_117 -> V_118 [ V_54 ] ,
V_134 ) ;
}
F_147 ( V_117 , V_134 ) ;
F_6 ( & V_200 ) ;
F_41 ( V_117 -> V_118 ) ;
F_156 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
return 0 ;
}
void F_159 ( struct V_117 * V_117 , T_2 V_134 , int V_87 )
{
unsigned int V_54 ;
struct V_153 V_154 [ V_24 ] ;
struct V_27 * * V_198 = V_117 -> V_118 ;
int V_197 = V_87 & V_199 ;
if ( ! F_139 ( V_117 ) ) {
F_152 ( V_117 , V_134 , V_197 ) ;
return;
}
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_5 ( & V_200 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
int V_205 ;
V_154 [ V_54 ] . V_163 = V_172 ;
if ( ! V_198 [ V_54 ] )
continue;
V_205 = F_138 ( V_198 [ V_54 ] , V_134 ) ;
if ( V_205 != V_172 )
F_127 ( & V_154 [ V_54 ] , V_198 [ V_54 ] , V_205 ) ;
if ( V_197 )
F_116 ( V_198 [ V_54 ] , V_134 ) ;
else
F_118 ( V_198 [ V_54 ] , V_134 ) ;
}
F_152 ( V_117 , V_134 , V_197 ) ;
F_6 ( & V_200 ) ;
if ( V_197 )
goto V_206;
F_41 ( V_198 ) ;
V_206:
F_156 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_128 ( V_154 ) ;
}
void F_160 ( const struct V_117 * V_117 )
{
unsigned int V_54 ;
struct V_153 V_154 [ V_24 ] ;
struct V_27 * const * V_198 = V_117 -> V_118 ;
if ( ! F_139 ( V_117 ) )
return;
F_155 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_5 ( & V_200 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
int V_205 ;
V_154 [ V_54 ] . V_163 = V_172 ;
if ( ! V_198 [ V_54 ] )
continue;
V_205 = F_137 ( V_198 [ V_54 ] , 1 ) ;
if ( V_205 != V_172 )
F_127 ( & V_154 [ V_54 ] , V_198 [ V_54 ] , V_205 ) ;
F_117 ( V_198 [ V_54 ] , 1 ) ;
}
F_6 ( & V_200 ) ;
F_41 ( V_198 ) ;
F_156 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_128 ( V_154 ) ;
}
int F_161 ( struct V_117 * V_117 , struct V_27 * * V_207 )
{
T_2 V_185 , V_208 ;
T_2 V_209 = 0 ;
struct V_27 * V_210 [ V_24 ] = {} ;
int V_54 , V_49 = 0 ;
char V_211 [ V_24 ] = {} ;
struct V_153 V_212 [ V_24 ] ;
struct V_153 V_213 [ V_24 ] ;
struct V_153 V_214 [ V_24 ] ;
if ( F_96 ( V_117 ) )
return 0 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_212 [ V_54 ] . V_163 = V_172 ;
V_213 [ V_54 ] . V_163 = V_172 ;
V_214 [ V_54 ] . V_163 = V_172 ;
}
F_109 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
if ( F_96 ( V_117 ) ) {
F_110 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
return 0 ;
}
F_5 ( & V_200 ) ;
V_208 = F_162 ( V_117 ) ;
V_209 = F_99 ( V_117 ) ;
V_185 = V_208 + V_209 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_207 [ V_54 ] )
continue;
if ( ! F_71 ( V_117 -> V_129 , V_54 ) )
continue;
V_211 [ V_54 ] = 1 ;
V_210 [ V_54 ] = V_117 -> V_118 [ V_54 ] ;
V_49 = F_133 ( V_207 [ V_54 ] , 1 , & V_212 [ V_54 ] ) ;
if ( V_49 )
goto V_215;
V_49 = F_136 ( V_207 [ V_54 ] , V_185 , 0 , & V_212 [ V_54 ] ) ;
if ( V_49 )
goto V_215;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( ! V_211 [ V_54 ] )
continue;
if ( V_210 [ V_54 ] ) {
int V_205 ;
V_205 = F_137 ( V_210 [ V_54 ] , 1 ) ;
if ( V_205 != V_172 )
F_127 ( & V_213 [ V_54 ] ,
V_210 [ V_54 ] , V_205 ) ;
V_205 = F_138 ( V_210 [ V_54 ] , V_185 ) ;
if ( V_205 != V_172 )
F_127 ( & V_214 [ V_54 ] ,
V_210 [ V_54 ] , V_205 ) ;
F_117 ( V_210 [ V_54 ] , 1 ) ;
F_118 ( V_210 [ V_54 ] , V_208 ) ;
F_116 ( V_210 [ V_54 ] ,
V_209 ) ;
}
F_111 ( V_207 [ V_54 ] , 1 ) ;
F_112 ( V_207 [ V_54 ] , V_208 ) ;
F_113 ( V_207 [ V_54 ] , V_209 ) ;
V_117 -> V_118 [ V_54 ] = V_207 [ V_54 ] ;
}
F_6 ( & V_200 ) ;
F_110 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_41 ( V_210 ) ;
F_41 ( V_207 ) ;
F_128 ( V_212 ) ;
F_128 ( V_213 ) ;
F_128 ( V_214 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_211 [ V_54 ] )
V_207 [ V_54 ] = V_210 [ V_54 ] ;
return 0 ;
V_215:
F_6 ( & V_200 ) ;
F_110 ( & F_40 ( V_117 -> V_129 ) -> V_133 ) ;
F_128 ( V_212 ) ;
return V_49 ;
}
int F_163 ( struct V_117 * V_117 , struct V_216 * V_216 )
{
struct V_27 * V_207 [ V_24 ] = {} ;
struct V_1 * V_2 = V_117 -> V_129 ;
int V_49 ;
if ( ! F_139 ( V_117 ) )
return 0 ;
if ( V_216 -> V_217 & V_218 && V_216 -> V_219 != V_117 -> V_192 )
V_207 [ V_157 ] = F_94 ( V_2 , V_216 -> V_219 , V_157 ) ;
if ( V_216 -> V_217 & V_220 && V_216 -> V_221 != V_117 -> V_193 )
V_207 [ V_159 ] = F_94 ( V_2 , V_216 -> V_221 , V_159 ) ;
V_49 = F_161 ( V_117 , V_207 ) ;
F_42 ( V_207 ) ;
return V_49 ;
}
int F_164 ( struct V_1 * V_2 , int type )
{
int V_49 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
F_32 ( & V_59 -> V_60 ) ;
V_49 = V_59 -> V_62 [ type ] -> F_52 ( V_2 , type ) ;
F_33 ( & V_59 -> V_60 ) ;
return V_49 ;
}
int F_165 ( struct V_117 * V_117 , struct V_222 * V_222 )
{
int error ;
error = F_166 ( V_117 , V_222 ) ;
if ( ! error && ( V_222 -> V_223 & V_224 ) )
F_142 ( V_117 ) ;
return error ;
}
int F_167 ( struct V_1 * V_2 , int type , unsigned int V_87 )
{
int V_54 , V_49 = 0 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
struct V_117 * V_225 [ V_24 ] ;
if ( ( V_87 & V_226 && ! ( V_87 & V_227 ) )
|| ( V_87 & V_228 && V_87 & ( V_227 |
V_226 ) ) )
return - V_229 ;
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_140 ( V_2 ) ) {
F_33 ( & V_59 -> V_79 ) ;
return 0 ;
}
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
V_225 [ V_54 ] = NULL ;
if ( type != - 1 && V_54 != type )
continue;
if ( ! F_168 ( V_2 , V_54 ) )
continue;
if ( V_87 & V_228 ) {
F_5 ( & V_114 ) ;
V_59 -> V_87 |=
F_169 ( V_228 , V_54 ) ;
F_6 ( & V_114 ) ;
} else {
F_5 ( & V_114 ) ;
V_59 -> V_87 &= ~ F_169 ( V_87 , V_54 ) ;
if ( ! F_168 ( V_2 , V_54 ) &&
F_170 ( V_2 , V_54 ) ) {
V_59 -> V_87 &= ~ F_169 (
V_228 , V_54 ) ;
F_6 ( & V_114 ) ;
F_101 ( V_59 -> V_92 [ V_54 ] ) ;
V_59 -> V_92 [ V_54 ] = NULL ;
continue;
}
F_6 ( & V_114 ) ;
}
if ( F_168 ( V_2 , V_54 ) && ! ( V_87 & V_228 ) )
continue;
F_107 ( V_2 , V_54 ) ;
F_60 ( V_2 , V_54 ) ;
if ( F_51 ( & V_59 -> V_51 [ V_54 ] ) )
V_2 -> V_47 -> V_85 ( V_2 , V_54 ) ;
if ( V_59 -> V_62 [ V_54 ] -> V_230 )
V_59 -> V_62 [ V_54 ] -> V_230 ( V_2 , V_54 ) ;
F_11 ( V_59 -> V_51 [ V_54 ] . V_176 ) ;
V_225 [ V_54 ] = V_59 -> V_92 [ V_54 ] ;
if ( ! F_168 ( V_2 , V_54 ) )
V_59 -> V_92 [ V_54 ] = NULL ;
V_59 -> V_51 [ V_54 ] . V_56 = 0 ;
V_59 -> V_51 [ V_54 ] . V_184 = 0 ;
V_59 -> V_51 [ V_54 ] . V_189 = 0 ;
V_59 -> V_62 [ V_54 ] = NULL ;
}
F_33 ( & V_59 -> V_79 ) ;
if ( V_59 -> V_87 & V_88 )
goto V_231;
if ( V_2 -> V_89 -> V_90 )
V_2 -> V_89 -> V_90 ( V_2 , 1 ) ;
F_73 ( V_2 -> V_91 ) ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_225 [ V_54 ] ) {
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_168 ( V_2 , V_54 ) ) {
F_74 ( & V_225 [ V_54 ] -> V_93 ,
V_94 ) ;
V_225 [ V_54 ] -> V_232 &= ~ ( V_233 |
V_234 | V_235 ) ;
F_75 ( & V_225 [ V_54 ] -> V_95 ,
0 ) ;
F_33 ( & V_225 [ V_54 ] -> V_93 ) ;
F_171 ( V_225 [ V_54 ] ) ;
}
F_33 ( & V_59 -> V_79 ) ;
}
if ( V_2 -> V_91 )
F_172 ( V_2 -> V_91 ) ;
V_231:
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ )
if ( V_225 [ V_54 ] ) {
if ( ! ( V_87 & V_228 ) )
F_101 ( V_225 [ V_54 ] ) ;
else if ( ! V_225 [ V_54 ] -> V_236 )
V_49 = - V_237 ;
}
return V_49 ;
}
int F_173 ( struct V_1 * V_2 , int type )
{
return F_167 ( V_2 , type ,
V_226 | V_227 ) ;
}
static int F_174 ( struct V_117 * V_117 , int type , int V_238 ,
unsigned int V_87 )
{
struct V_10 * V_4 = F_8 ( V_238 ) ;
struct V_1 * V_2 = V_117 -> V_129 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
int error ;
int V_239 = - 1 ;
if ( ! V_4 )
return - V_240 ;
if ( ! F_175 ( V_117 -> V_241 ) ) {
error = - V_242 ;
goto V_243;
}
if ( F_176 ( V_117 ) ) {
error = - V_244 ;
goto V_243;
}
if ( ! V_2 -> V_89 -> V_245 || ! V_2 -> V_89 -> V_246 ) {
error = - V_229 ;
goto V_243;
}
if ( ! ( V_87 & V_226 ) ) {
error = - V_229 ;
goto V_243;
}
if ( ! ( V_59 -> V_87 & V_88 ) ) {
F_177 ( V_2 ) ;
F_172 ( V_2 -> V_91 ) ;
}
F_32 ( & V_59 -> V_79 ) ;
if ( F_168 ( V_2 , type ) ) {
error = - V_237 ;
goto V_247;
}
if ( ! ( V_59 -> V_87 & V_88 ) ) {
F_74 ( & V_117 -> V_93 , V_94 ) ;
V_239 = V_117 -> V_232 & ( V_234 | V_233 |
V_235 ) ;
V_117 -> V_232 |= V_235 | V_234 | V_233 ;
F_33 ( & V_117 -> V_93 ) ;
F_143 ( V_117 ) ;
}
error = - V_67 ;
V_59 -> V_92 [ type ] = F_178 ( V_117 ) ;
if ( ! V_59 -> V_92 [ type ] )
goto V_247;
error = - V_229 ;
if ( ! V_4 -> V_248 -> V_249 ( V_2 , type ) )
goto V_250;
V_59 -> V_62 [ type ] = V_4 -> V_248 ;
V_59 -> V_51 [ type ] . V_176 = V_4 ;
V_59 -> V_51 [ type ] . V_251 = V_238 ;
F_90 ( & V_59 -> V_51 [ type ] . V_52 ) ;
F_32 ( & V_59 -> V_60 ) ;
error = V_59 -> V_62 [ type ] -> F_179 ( V_2 , type ) ;
if ( error < 0 ) {
F_33 ( & V_59 -> V_60 ) ;
goto V_250;
}
if ( V_59 -> V_87 & V_88 )
V_59 -> V_51 [ type ] . V_56 |= V_252 ;
F_33 ( & V_59 -> V_60 ) ;
F_5 ( & V_114 ) ;
V_59 -> V_87 |= F_169 ( V_87 , type ) ;
F_6 ( & V_114 ) ;
F_97 ( V_2 , type ) ;
F_33 ( & V_59 -> V_79 ) ;
return 0 ;
V_250:
V_59 -> V_92 [ type ] = NULL ;
F_101 ( V_117 ) ;
V_247:
if ( V_239 != - 1 ) {
F_74 ( & V_117 -> V_93 , V_94 ) ;
V_117 -> V_232 &= ~ ( V_234 | V_235 | V_233 ) ;
V_117 -> V_232 |= V_239 ;
F_33 ( & V_117 -> V_93 ) ;
}
F_33 ( & V_59 -> V_79 ) ;
V_243:
F_11 ( V_4 ) ;
return error ;
}
int F_180 ( struct V_1 * V_2 , int type )
{
struct V_58 * V_59 = F_40 ( V_2 ) ;
struct V_117 * V_117 ;
int V_49 = 0 , V_54 ;
unsigned int V_87 ;
for ( V_54 = 0 ; V_54 < V_24 ; V_54 ++ ) {
if ( type != - 1 && V_54 != type )
continue;
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_170 ( V_2 , V_54 ) ) {
F_33 ( & V_59 -> V_79 ) ;
continue;
}
V_117 = V_59 -> V_92 [ V_54 ] ;
V_59 -> V_92 [ V_54 ] = NULL ;
F_5 ( & V_114 ) ;
V_87 = V_59 -> V_87 & F_169 ( V_226 |
V_227 ,
V_54 ) ;
V_59 -> V_87 &= ~ F_169 ( V_253 , V_54 ) ;
F_6 ( & V_114 ) ;
F_33 ( & V_59 -> V_79 ) ;
V_87 = F_181 ( V_87 , V_54 ) ;
V_49 = F_174 ( V_117 , V_54 ,
V_59 -> V_51 [ V_54 ] . V_251 , V_87 ) ;
F_101 ( V_117 ) ;
}
return V_49 ;
}
int F_182 ( struct V_1 * V_2 , int type , int V_238 ,
struct V_254 * V_254 )
{
int error = F_183 ( V_254 -> V_255 ) ;
if ( error )
return error ;
if ( V_254 -> V_255 -> V_256 != V_2 )
error = - V_257 ;
else
error = F_174 ( V_254 -> V_255 -> V_258 , type ,
V_238 , V_226 |
V_227 ) ;
return error ;
}
int F_184 ( struct V_117 * V_117 , int type , int V_238 ,
unsigned int V_87 )
{
int V_49 = 0 ;
struct V_1 * V_2 = V_117 -> V_129 ;
struct V_58 * V_59 = F_40 ( V_2 ) ;
F_85 ( V_87 & V_228 ) ;
if ( ! V_87 )
return 0 ;
if ( F_168 ( V_2 , type ) ) {
F_32 ( & V_59 -> V_79 ) ;
if ( ! F_168 ( V_2 , type ) ) {
F_33 ( & V_59 -> V_79 ) ;
goto V_259;
}
if ( V_87 & V_226 &&
F_185 ( V_2 , type ) ) {
V_49 = - V_237 ;
goto V_247;
}
if ( V_87 & V_227 &&
F_134 ( V_2 , type ) ) {
V_49 = - V_237 ;
goto V_247;
}
F_5 ( & V_114 ) ;
F_40 ( V_2 ) -> V_87 |= F_169 ( V_87 , type ) ;
F_6 ( & V_114 ) ;
V_247:
F_33 ( & V_59 -> V_79 ) ;
return V_49 ;
}
V_259:
return F_174 ( V_117 , type , V_238 , V_87 ) ;
}
int F_186 ( struct V_1 * V_2 , char * V_260 ,
int V_238 , int type )
{
struct V_255 * V_255 ;
int error ;
F_32 ( & V_2 -> V_261 -> V_258 -> V_93 ) ;
V_255 = F_187 ( V_260 , V_2 -> V_261 , strlen ( V_260 ) ) ;
F_33 ( & V_2 -> V_261 -> V_258 -> V_93 ) ;
if ( F_188 ( V_255 ) )
return F_189 ( V_255 ) ;
if ( ! V_255 -> V_258 ) {
error = - V_262 ;
goto V_81;
}
error = F_183 ( V_255 ) ;
if ( ! error )
error = F_174 ( V_255 -> V_258 , type , V_238 ,
V_226 | V_227 ) ;
V_81:
F_190 ( V_255 ) ;
return error ;
}
static inline T_2 F_191 ( T_2 V_263 )
{
return V_263 << V_264 ;
}
static inline T_2 F_192 ( T_2 V_185 )
{
return ( V_185 + V_265 - 1 ) >> V_264 ;
}
static void F_193 ( struct V_27 * V_27 , struct V_266 * V_267 )
{
struct V_268 * V_269 = & V_27 -> V_135 ;
memset ( V_267 , 0 , sizeof( * V_267 ) ) ;
V_267 -> V_270 = V_271 ;
V_267 -> V_272 = V_27 -> V_33 == V_157 ?
V_273 : V_274 ;
V_267 -> V_275 = V_27 -> V_32 ;
F_5 ( & V_200 ) ;
V_267 -> V_276 = F_192 ( V_269 -> V_188 ) ;
V_267 -> V_277 = F_192 ( V_269 -> V_144 ) ;
V_267 -> V_278 = V_269 -> V_182 ;
V_267 -> V_279 = V_269 -> V_140 ;
V_267 -> V_280 = V_269 -> V_137 + V_269 -> V_138 ;
V_267 -> V_281 = V_269 -> V_136 ;
V_267 -> V_282 = V_269 -> V_145 ;
V_267 -> V_283 = V_269 -> V_141 ;
F_6 ( & V_200 ) ;
}
int F_194 ( struct V_1 * V_2 , int type , T_3 V_15 ,
struct V_266 * V_267 )
{
struct V_27 * V_27 ;
V_27 = F_94 ( V_2 , V_15 , type ) ;
if ( ! V_27 )
return - V_240 ;
F_193 ( V_27 , V_267 ) ;
F_43 ( V_27 ) ;
return 0 ;
}
static int F_195 ( struct V_27 * V_27 , struct V_266 * V_267 )
{
struct V_268 * V_269 = & V_27 -> V_135 ;
int V_284 = 0 , V_285 = 0 ;
struct V_174 * V_286 = & F_40 ( V_27 -> V_31 ) -> V_51 [ V_27 -> V_33 ] ;
if ( V_267 -> V_287 & ~ V_288 )
return - V_229 ;
if ( ( ( V_267 -> V_287 & V_289 ) &&
( V_267 -> V_277 > V_286 -> V_290 ) ) ||
( ( V_267 -> V_287 & V_291 ) &&
( V_267 -> V_276 > V_286 -> V_290 ) ) ||
( ( V_267 -> V_287 & V_292 ) &&
( V_267 -> V_279 > V_286 -> V_293 ) ) ||
( ( V_267 -> V_287 & V_294 ) &&
( V_267 -> V_278 > V_286 -> V_293 ) ) )
return - V_295 ;
F_5 ( & V_200 ) ;
if ( V_267 -> V_287 & V_296 ) {
V_269 -> V_137 = V_267 -> V_280 - V_269 -> V_138 ;
V_284 = 1 ;
F_47 ( V_297 + V_298 , & V_27 -> V_46 ) ;
}
if ( V_267 -> V_287 & V_289 )
V_269 -> V_144 = F_191 ( V_267 -> V_277 ) ;
if ( V_267 -> V_287 & V_291 )
V_269 -> V_188 = F_191 ( V_267 -> V_276 ) ;
if ( V_267 -> V_287 & ( V_289 | V_291 ) ) {
V_284 = 1 ;
F_47 ( V_297 + V_299 , & V_27 -> V_46 ) ;
}
if ( V_267 -> V_287 & V_300 ) {
V_269 -> V_136 = V_267 -> V_281 ;
V_285 = 1 ;
F_47 ( V_297 + V_301 , & V_27 -> V_46 ) ;
}
if ( V_267 -> V_287 & V_292 )
V_269 -> V_140 = V_267 -> V_279 ;
if ( V_267 -> V_287 & V_294 )
V_269 -> V_182 = V_267 -> V_278 ;
if ( V_267 -> V_287 & ( V_292 | V_294 ) ) {
V_285 = 1 ;
F_47 ( V_297 + V_302 , & V_27 -> V_46 ) ;
}
if ( V_267 -> V_287 & V_303 ) {
V_269 -> V_145 = V_267 -> V_282 ;
V_284 = 1 ;
F_47 ( V_297 + V_304 , & V_27 -> V_46 ) ;
}
if ( V_267 -> V_287 & V_305 ) {
V_269 -> V_141 = V_267 -> V_283 ;
V_285 = 1 ;
F_47 ( V_297 + V_306 , & V_27 -> V_46 ) ;
}
if ( V_284 ) {
if ( ! V_269 -> V_144 ||
V_269 -> V_137 < V_269 -> V_144 ) {
V_269 -> V_145 = 0 ;
F_56 ( V_146 , & V_27 -> V_46 ) ;
} else if ( ! ( V_267 -> V_287 & V_303 ) )
V_269 -> V_145 = F_135 () + V_286 -> V_189 ;
}
if ( V_285 ) {
if ( ! V_269 -> V_140 ||
V_269 -> V_136 < V_269 -> V_140 ) {
V_269 -> V_141 = 0 ;
F_56 ( V_143 , & V_27 -> V_46 ) ;
} else if ( ! ( V_267 -> V_287 & V_305 ) )
V_269 -> V_141 = F_135 () + V_286 -> V_184 ;
}
if ( V_269 -> V_188 || V_269 -> V_144 || V_269 -> V_182 ||
V_269 -> V_140 )
F_56 ( V_181 , & V_27 -> V_46 ) ;
else
F_47 ( V_181 , & V_27 -> V_46 ) ;
F_6 ( & V_200 ) ;
F_36 ( V_27 ) ;
return 0 ;
}
int F_196 ( struct V_1 * V_2 , int type , T_3 V_15 ,
struct V_266 * V_267 )
{
struct V_27 * V_27 ;
int V_307 ;
V_27 = F_94 ( V_2 , V_15 , type ) ;
if ( ! V_27 ) {
V_307 = - V_240 ;
goto V_81;
}
V_307 = F_195 ( V_27 , V_267 ) ;
F_43 ( V_27 ) ;
V_81:
return V_307 ;
}
int F_197 ( struct V_1 * V_2 , int type , struct V_308 * V_309 )
{
struct V_174 * V_310 ;
F_32 ( & F_40 ( V_2 ) -> V_79 ) ;
if ( ! F_71 ( V_2 , type ) ) {
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return - V_240 ;
}
V_310 = F_40 ( V_2 ) -> V_51 + type ;
F_5 ( & V_200 ) ;
V_309 -> V_189 = V_310 -> V_189 ;
V_309 -> V_184 = V_310 -> V_184 ;
V_309 -> V_56 = V_310 -> V_56 & V_311 ;
V_309 -> V_312 = V_313 ;
F_6 ( & V_200 ) ;
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return 0 ;
}
int F_198 ( struct V_1 * V_2 , int type , struct V_308 * V_309 )
{
struct V_174 * V_310 ;
int V_53 = 0 ;
F_32 ( & F_40 ( V_2 ) -> V_79 ) ;
if ( ! F_71 ( V_2 , type ) ) {
V_53 = - V_240 ;
goto V_81;
}
V_310 = F_40 ( V_2 ) -> V_51 + type ;
F_5 ( & V_200 ) ;
if ( V_309 -> V_312 & V_314 )
V_310 -> V_189 = V_309 -> V_189 ;
if ( V_309 -> V_312 & V_315 )
V_310 -> V_184 = V_309 -> V_184 ;
if ( V_309 -> V_312 & V_316 )
V_310 -> V_56 = ( V_310 -> V_56 & ~ V_317 ) |
( V_309 -> V_56 & V_317 ) ;
F_6 ( & V_200 ) ;
F_46 ( V_2 , type ) ;
V_2 -> V_47 -> V_85 ( V_2 , type ) ;
V_81:
F_33 ( & F_40 ( V_2 ) -> V_79 ) ;
return V_53 ;
}
static int F_199 ( struct V_318 * V_319 , int V_320 ,
void T_4 * V_321 , T_5 * V_322 , T_6 * V_323 )
{
unsigned int type = ( int * ) V_319 -> V_324 - V_104 . V_325 ;
V_104 . V_325 [ type ] =
F_200 ( & V_104 . V_105 [ type ] ) ;
return F_201 ( V_319 , V_320 , V_321 , V_322 , V_323 ) ;
}
static int T_7 F_202 ( void )
{
int V_171 , V_49 ;
unsigned long V_326 , V_327 ;
F_3 ( V_328 L_21 , V_329 ) ;
F_203 ( V_330 ) ;
V_71 = F_204 ( L_22 ,
sizeof( struct V_27 ) , sizeof( unsigned long ) * 4 ,
( V_331 | V_332 |
V_333 | V_334 ) ,
NULL ) ;
V_327 = 0 ;
V_30 = (struct V_28 * ) F_205 ( V_335 , V_327 ) ;
if ( ! V_30 )
F_206 ( L_23 ) ;
for ( V_171 = 0 ; V_171 < V_336 ; V_171 ++ ) {
V_49 = F_207 ( & V_104 . V_105 [ V_171 ] , 0 ) ;
if ( V_49 )
F_206 ( L_24 ) ;
}
V_326 = ( 1UL << V_327 ) * V_337 / sizeof( struct V_28 ) ;
V_25 = 0 ;
do {
V_25 ++ ;
} while ( V_326 >> V_25 );
V_25 -- ;
V_326 = 1UL << V_25 ;
V_26 = V_326 - 1 ;
for ( V_171 = 0 ; V_171 < V_326 ; V_171 ++ )
F_208 ( V_30 + V_171 ) ;
F_3 ( L_25 ,
V_326 , V_327 , ( V_337 << V_327 ) ) ;
F_209 ( & V_338 ) ;
return 0 ;
}

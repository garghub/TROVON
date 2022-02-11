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
F_65 ( & V_30 -> V_70 ) ;
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
F_65 ( & V_30 -> V_70 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
F_45 ( V_80 ) ;
V_80 = V_30 ;
V_51 = F_70 ( V_30 , V_79 ) ;
if ( V_51 < 0 )
goto V_83;
F_5 ( & V_11 ) ;
}
F_6 ( & V_11 ) ;
V_83:
F_45 ( V_80 ) ;
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_51 ;
}
int F_72 ( struct V_1 * V_2 , int type )
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
if ( ! F_73 ( V_2 , V_56 ) )
continue;
F_5 ( & V_11 ) ;
V_85 = & V_61 -> V_53 [ V_56 ] . V_54 ;
while ( ! F_27 ( V_85 ) ) {
V_30 = F_74 ( V_85 , struct V_30 ,
V_52 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) ) {
F_46 ( V_30 ) ;
continue;
}
F_65 ( & V_30 -> V_70 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
V_55 = V_2 -> V_49 -> V_86 ( V_30 ) ;
if ( ! V_51 && V_55 )
V_55 = V_51 ;
F_45 ( V_30 ) ;
F_5 ( & V_11 ) ;
}
F_6 ( & V_11 ) ;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ( V_56 == type || type == - 1 ) && F_73 ( V_2 , V_56 )
&& F_53 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
F_25 ( V_88 ) ;
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
int F_75 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
int V_56 ;
int V_51 ;
V_51 = F_72 ( V_2 , type ) ;
if ( V_51 )
return V_51 ;
if ( V_61 -> V_89 & V_90 )
return 0 ;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_76 ( V_2 -> V_93 ) ;
F_34 ( & V_61 -> V_81 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_73 ( V_2 , V_56 ) )
continue;
F_34 ( & V_61 -> V_94 [ V_56 ] -> V_95 ) ;
F_77 ( & V_61 -> V_94 [ V_56 ] -> V_96 , 0 ) ;
F_35 ( & V_61 -> V_94 [ V_56 ] -> V_95 ) ;
}
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
static void F_78 ( int V_97 )
{
struct V_84 * V_32 ;
struct V_30 * V_30 ;
V_32 = V_41 . V_98 ;
while ( V_32 != & V_41 && V_97 ) {
V_30 = F_79 ( V_32 , struct V_30 , V_40 ) ;
F_17 ( V_30 ) ;
F_26 ( V_30 ) ;
F_31 ( V_30 ) ;
F_61 ( V_30 ) ;
V_97 -- ;
V_32 = V_41 . V_98 ;
}
}
static int F_80 ( struct V_99 * V_100 ,
struct V_101 * V_102 )
{
int V_103 = V_102 -> V_104 ;
if ( V_103 ) {
F_5 ( & V_11 ) ;
F_78 ( V_103 ) ;
F_6 ( & V_11 ) ;
}
return ( ( unsigned )
F_81 ( & V_105 . V_106 [ V_42 ] )
/ 100 ) * V_107 ;
}
void F_45 ( struct V_30 * V_30 )
{
int V_51 ;
if ( ! V_30 )
return;
#ifdef F_82
if ( ! F_57 ( & V_30 -> V_70 ) ) {
F_83 ( V_30 -> V_34 , L_2 ,
V_108 [ V_30 -> V_35 . type ] ,
F_14 ( & V_24 , V_30 -> V_35 ) ) ;
F_84 () ;
}
#endif
F_25 ( V_109 ) ;
V_110:
F_5 ( & V_11 ) ;
if ( F_57 ( & V_30 -> V_70 ) > 1 ) {
F_85 ( & V_30 -> V_70 ) ;
if ( ! F_73 ( V_30 -> V_34 , V_30 -> V_35 . type ) &&
F_57 ( & V_30 -> V_70 ) == 1 )
F_86 ( & V_30 -> V_77 ) ;
F_6 ( & V_11 ) ;
return;
}
if ( F_37 ( V_66 , & V_30 -> V_48 ) && F_36 ( V_30 ) ) {
F_6 ( & V_11 ) ;
V_51 = V_30 -> V_34 -> V_49 -> V_86 ( V_30 ) ;
if ( V_51 < 0 ) {
F_83 ( V_30 -> V_34 , L_3
L_4 ,
V_51 ) ;
F_5 ( & V_11 ) ;
F_46 ( V_30 ) ;
F_6 ( & V_11 ) ;
}
goto V_110;
}
F_46 ( V_30 ) ;
if ( F_37 ( V_66 , & V_30 -> V_48 ) ) {
F_6 ( & V_11 ) ;
V_30 -> V_34 -> V_49 -> V_111 ( V_30 ) ;
goto V_110;
}
F_85 ( & V_30 -> V_70 ) ;
#ifdef F_82
F_87 ( ! F_27 ( & V_30 -> V_40 ) ) ;
#endif
F_23 ( V_30 ) ;
F_6 ( & V_11 ) ;
}
struct V_30 * F_88 ( struct V_1 * V_2 , int type )
{
return F_89 ( V_73 , V_112 ) ;
}
static struct V_30 * F_90 ( struct V_1 * V_2 , int type )
{
struct V_30 * V_30 ;
V_30 = V_2 -> V_49 -> V_113 ( V_2 , type ) ;
if( ! V_30 )
return NULL ;
F_91 ( & V_30 -> V_46 ) ;
F_92 ( & V_30 -> V_40 ) ;
F_92 ( & V_30 -> V_43 ) ;
F_93 ( & V_30 -> V_36 ) ;
F_92 ( & V_30 -> V_52 ) ;
F_94 ( & V_30 -> V_77 ) ;
V_30 -> V_34 = V_2 ;
V_30 -> V_35 = F_95 ( type ) ;
F_96 ( & V_30 -> V_70 , 1 ) ;
return V_30 ;
}
struct V_30 * F_97 ( struct V_1 * V_2 , struct V_22 V_23 )
{
unsigned int V_37 = F_13 ( V_2 , V_23 ) ;
struct V_30 * V_30 = NULL , * V_114 = NULL ;
if ( ! F_73 ( V_2 , V_23 . type ) )
return NULL ;
V_110:
F_5 ( & V_11 ) ;
F_5 ( & V_115 ) ;
if ( ! F_73 ( V_2 , V_23 . type ) ) {
F_6 ( & V_115 ) ;
F_6 ( & V_11 ) ;
goto V_83;
}
F_6 ( & V_115 ) ;
V_30 = F_19 ( V_37 , V_2 , V_23 ) ;
if ( ! V_30 ) {
if ( ! V_114 ) {
F_6 ( & V_11 ) ;
V_114 = F_90 ( V_2 , V_23 . type ) ;
if ( ! V_114 )
F_67 () ;
goto V_110;
}
V_30 = V_114 ;
V_114 = NULL ;
V_30 -> V_35 = V_23 ;
F_30 ( V_30 ) ;
F_15 ( V_30 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_82 ) ;
} else {
if ( ! F_57 ( & V_30 -> V_70 ) )
F_26 ( V_30 ) ;
F_65 ( & V_30 -> V_70 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_116 ) ;
F_25 ( V_82 ) ;
}
F_33 ( V_30 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) &&
V_2 -> V_49 -> V_117 ( V_30 ) < 0 ) {
F_45 ( V_30 ) ;
V_30 = NULL ;
goto V_83;
}
#ifdef F_82
F_87 ( ! V_30 -> V_34 ) ;
#endif
V_83:
if ( V_114 )
F_61 ( V_114 ) ;
return V_30 ;
}
static int F_98 ( struct V_118 * V_118 , int type )
{
int V_56 ;
if ( F_99 ( V_118 ) )
return 0 ;
if ( type != - 1 )
return ! V_118 -> V_119 [ type ] ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ! V_118 -> V_119 [ V_56 ] )
return 1 ;
return 0 ;
}
static void F_100 ( struct V_1 * V_2 , int type )
{
struct V_118 * V_118 , * V_120 = NULL ;
#ifdef F_82
int V_121 = 0 ;
#endif
F_5 ( & V_122 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_118 -> V_123 ) ;
if ( ( V_118 -> V_124 & ( V_125 | V_126 | V_127 ) ) ||
! F_57 ( & V_118 -> V_128 ) ||
! F_98 ( V_118 , type ) ) {
F_6 ( & V_118 -> V_123 ) ;
continue;
}
F_101 ( V_118 ) ;
F_6 ( & V_118 -> V_123 ) ;
F_6 ( & V_122 ) ;
#ifdef F_82
if ( F_102 ( F_103 ( V_118 ) > 0 ) )
V_121 = 1 ;
#endif
F_104 ( V_120 ) ;
F_105 ( V_118 , type ) ;
V_120 = V_118 ;
F_5 ( & V_122 ) ;
}
F_6 ( & V_122 ) ;
F_104 ( V_120 ) ;
#ifdef F_82
if ( V_121 ) {
F_83 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static inline int F_106 ( struct V_30 * V_30 )
{
if ( F_57 ( & V_30 -> V_70 ) <= 1 )
return 1 ;
return 0 ;
}
static int F_107 ( struct V_118 * V_118 , int type ,
struct V_84 * V_129 )
{
struct V_30 * V_30 = V_118 -> V_119 [ type ] ;
V_118 -> V_119 [ type ] = NULL ;
if ( V_30 ) {
if ( F_106 ( V_30 ) ) {
#ifdef F_82
if ( F_57 ( & V_30 -> V_70 ) != 1 )
F_83 ( V_118 -> V_130 , L_8
L_9 ,
F_57 ( & V_30 -> V_70 ) ) ;
#endif
F_5 ( & V_11 ) ;
F_41 ( & V_30 -> V_40 , V_129 ) ;
F_6 ( & V_11 ) ;
return 1 ;
}
else
F_45 ( V_30 ) ;
}
return 0 ;
}
static void F_108 ( struct V_84 * V_129 )
{
struct V_84 * V_131 ;
struct V_30 * V_30 ;
V_131 = V_129 -> V_132 ;
while ( V_131 != V_129 ) {
V_30 = F_79 ( V_131 , struct V_30 , V_40 ) ;
V_131 = V_131 -> V_132 ;
F_28 ( & V_30 -> V_40 ) ;
F_45 ( V_30 ) ;
}
}
static void F_109 ( struct V_1 * V_2 , int type ,
struct V_84 * V_129 )
{
struct V_118 * V_118 ;
int V_121 = 0 ;
F_5 ( & V_122 ) ;
F_71 (inode, &sb->s_inodes, i_sb_list) {
if ( ! F_99 ( V_118 ) ) {
if ( F_102 ( F_103 ( V_118 ) > 0 ) )
V_121 = 1 ;
F_107 ( V_118 , type , V_129 ) ;
}
}
F_6 ( & V_122 ) ;
#ifdef F_82
if ( V_121 ) {
F_3 ( V_133 L_10
L_11
L_12 , V_2 -> V_9 ) ;
}
#endif
}
static void F_110 ( struct V_1 * V_2 , int type )
{
F_111 ( V_129 ) ;
if ( V_2 -> V_49 ) {
F_112 ( & F_42 ( V_2 ) -> V_134 ) ;
F_109 ( V_2 , type , & V_129 ) ;
F_113 ( & F_42 ( V_2 ) -> V_134 ) ;
F_108 ( & V_129 ) ;
}
}
static inline void F_114 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_137 += V_135 ;
}
static inline void F_115 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_138 += V_135 ;
}
static inline void F_116 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_139 += V_135 ;
}
static void F_117 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( V_30 -> V_136 . V_139 < V_135 ) {
F_118 ( 1 ) ;
V_135 = V_30 -> V_136 . V_139 ;
}
V_30 -> V_136 . V_138 += V_135 ;
V_30 -> V_136 . V_139 -= V_135 ;
}
static inline
void F_119 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( V_30 -> V_136 . V_139 >= V_135 )
V_30 -> V_136 . V_139 -= V_135 ;
else {
F_118 ( 1 ) ;
V_30 -> V_136 . V_139 = 0 ;
}
}
static void F_120 ( struct V_30 * V_30 , T_2 V_135 )
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
static void F_121 ( struct V_30 * V_30 , T_2 V_135 )
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
static int F_122 ( struct V_30 * V_30 , const int V_148 )
{
int V_149 = ( V_148 == V_150 ||
V_148 == V_151 ) ? V_147 :
( ( V_148 == V_152 ||
V_148 == V_153 ) ? V_144 : 0 ) ;
if ( ! V_149 )
return 0 ;
return F_40 ( V_149 , & V_30 -> V_48 ) ;
}
static int F_123 ( struct V_154 * V_155 )
{
if ( ! V_156 )
return 0 ;
switch ( V_155 -> V_157 . type ) {
case V_158 :
return F_124 ( F_125 () , V_155 -> V_157 . V_159 ) ;
case V_160 :
return F_126 ( V_155 -> V_157 . V_161 ) ;
case V_162 :
return 0 ;
}
return 0 ;
}
static void F_127 ( struct V_154 * V_155 )
{
char * V_163 = NULL ;
struct V_164 * V_165 ;
int V_148 = V_155 -> V_166 ;
if ( V_148 == V_167 ||
V_148 == V_168 ||
V_148 == V_169 ||
V_148 == V_170 || ! F_123 ( V_155 ) )
return;
V_165 = F_128 () ;
if ( ! V_165 )
return;
F_129 ( V_165 , V_155 -> V_171 -> V_9 ) ;
if ( V_148 == V_172 || V_148 == V_173 )
F_129 ( V_165 , L_13 ) ;
else
F_129 ( V_165 , L_14 ) ;
F_129 ( V_165 , V_108 [ V_155 -> V_157 . type ] ) ;
switch ( V_148 ) {
case V_152 :
V_163 = L_15 ;
break;
case V_153 :
V_163 = L_16 ;
break;
case V_172 :
V_163 = L_17 ;
break;
case V_150 :
V_163 = L_18 ;
break;
case V_151 :
V_163 = L_19 ;
break;
case V_173 :
V_163 = L_20 ;
break;
}
F_129 ( V_165 , V_163 ) ;
F_130 ( V_165 ) ;
}
static void F_131 ( struct V_154 * V_155 , struct V_30 * V_30 ,
int V_148 )
{
if ( F_122 ( V_30 , V_148 ) )
return;
V_155 -> V_166 = V_148 ;
V_155 -> V_171 = V_30 -> V_34 ;
V_155 -> V_157 = V_30 -> V_35 ;
}
static void F_132 ( struct V_154 * V_155 )
{
int V_174 ;
for ( V_174 = 0 ; V_174 < V_27 ; V_174 ++ ) {
if ( V_155 [ V_174 ] . V_166 == V_175 )
continue;
#ifdef F_133
F_127 ( & V_155 [ V_174 ] ) ;
#endif
F_134 ( V_155 [ V_174 ] . V_157 ,
V_155 [ V_174 ] . V_171 -> V_176 , V_155 [ V_174 ] . V_166 ) ;
}
}
static int F_135 ( struct V_30 * V_30 )
{
struct V_177 * V_53 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
return F_136 ( V_178 ) &&
( V_53 -> V_179 -> V_16 != V_180 ||
! ( V_53 -> V_58 & V_181 ) ) ;
}
static int F_137 ( struct V_30 * V_30 , T_2 V_182 ,
struct V_154 * V_155 )
{
T_2 V_183 = V_30 -> V_136 . V_137 + V_182 ;
if ( ! F_138 ( V_30 -> V_34 , V_30 -> V_35 . type ) ||
F_37 ( V_184 , & V_30 -> V_48 ) )
return 0 ;
if ( V_30 -> V_136 . V_185 &&
V_183 > V_30 -> V_136 . V_185 &&
! F_135 ( V_30 ) ) {
F_131 ( V_155 , V_30 , V_152 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_141 &&
V_183 > V_30 -> V_136 . V_141 &&
V_30 -> V_136 . V_142 &&
F_139 () >= V_30 -> V_136 . V_142 &&
! F_135 ( V_30 ) ) {
F_131 ( V_155 , V_30 , V_153 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_141 &&
V_183 > V_30 -> V_136 . V_141 &&
V_30 -> V_136 . V_142 == 0 ) {
F_131 ( V_155 , V_30 , V_172 ) ;
V_30 -> V_136 . V_142 = F_139 () +
F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] . V_187 ;
}
return 0 ;
}
static int F_140 ( struct V_30 * V_30 , T_2 V_188 , int V_189 ,
struct V_154 * V_155 )
{
T_2 V_190 ;
struct V_1 * V_2 = V_30 -> V_34 ;
if ( ! F_138 ( V_2 , V_30 -> V_35 . type ) ||
F_37 ( V_184 , & V_30 -> V_48 ) )
return 0 ;
V_190 = V_30 -> V_136 . V_138 + V_30 -> V_136 . V_139
+ V_188 ;
if ( V_30 -> V_136 . V_191 &&
V_190 > V_30 -> V_136 . V_191 &&
! F_135 ( V_30 ) ) {
if ( ! V_189 )
F_131 ( V_155 , V_30 , V_150 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_145 &&
V_190 > V_30 -> V_136 . V_145 &&
V_30 -> V_136 . V_146 &&
F_139 () >= V_30 -> V_136 . V_146 &&
! F_135 ( V_30 ) ) {
if ( ! V_189 )
F_131 ( V_155 , V_30 , V_151 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_145 &&
V_190 > V_30 -> V_136 . V_145 &&
V_30 -> V_136 . V_146 == 0 ) {
if ( ! V_189 ) {
F_131 ( V_155 , V_30 , V_173 ) ;
V_30 -> V_136 . V_146 = F_139 () +
F_42 ( V_2 ) -> V_53 [ V_30 -> V_35 . type ] . V_192 ;
}
else
return - V_186 ;
}
return 0 ;
}
static int F_141 ( struct V_30 * V_30 , T_2 V_182 )
{
T_2 V_183 ;
if ( F_37 ( V_184 , & V_30 -> V_48 ) ||
V_30 -> V_136 . V_137 <= V_30 -> V_136 . V_141 ||
! F_138 ( V_30 -> V_34 , V_30 -> V_35 . type ) )
return V_175 ;
V_183 = V_30 -> V_136 . V_137 - V_182 ;
if ( V_183 <= V_30 -> V_136 . V_141 )
return V_168 ;
if ( V_30 -> V_136 . V_137 >= V_30 -> V_136 . V_185 &&
V_183 < V_30 -> V_136 . V_185 )
return V_167 ;
return V_175 ;
}
static int F_142 ( struct V_30 * V_30 , T_2 V_188 )
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
static int F_143 ( const struct V_118 * V_118 )
{
struct V_1 * V_2 = V_118 -> V_130 ;
if ( F_99 ( V_118 ) )
return 0 ;
return F_144 ( V_2 ) & ~ F_145 ( V_2 ) ;
}
static void F_105 ( struct V_118 * V_118 , int type )
{
int V_56 ;
struct V_30 * V_193 [ V_27 ] ;
struct V_1 * V_2 = V_118 -> V_130 ;
T_2 V_194 ;
if ( ! F_143 ( V_118 ) )
return;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
struct V_22 V_23 ;
V_193 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
switch ( V_56 ) {
case V_158 :
V_23 = F_146 ( V_118 -> V_195 ) ;
break;
case V_160 :
V_23 = F_147 ( V_118 -> V_196 ) ;
break;
}
V_193 [ V_56 ] = F_97 ( V_2 , V_23 ) ;
}
F_112 ( & F_42 ( V_2 ) -> V_134 ) ;
if ( F_99 ( V_118 ) )
goto V_197;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_73 ( V_2 , V_56 ) )
continue;
if ( ! V_193 [ V_56 ] )
continue;
if ( ! V_118 -> V_119 [ V_56 ] ) {
V_118 -> V_119 [ V_56 ] = V_193 [ V_56 ] ;
V_193 [ V_56 ] = NULL ;
V_194 = F_103 ( V_118 ) ;
if ( F_102 ( V_194 ) ) {
F_5 ( & V_198 ) ;
F_116 ( V_118 -> V_119 [ V_56 ] , V_194 ) ;
F_6 ( & V_198 ) ;
}
}
}
V_197:
F_113 ( & F_42 ( V_2 ) -> V_134 ) ;
F_44 ( V_193 ) ;
}
void F_148 ( struct V_118 * V_118 )
{
F_105 ( V_118 , - 1 ) ;
}
static void F_149 ( struct V_118 * V_118 )
{
int V_56 ;
struct V_30 * V_199 [ V_27 ] ;
F_112 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_199 [ V_56 ] = V_118 -> V_119 [ V_56 ] ;
V_118 -> V_119 [ V_56 ] = NULL ;
}
F_113 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_44 ( V_199 ) ;
}
void F_150 ( struct V_118 * V_118 )
{
int V_56 ;
if ( F_99 ( V_118 ) )
return;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_118 -> V_119 [ V_56 ] )
break;
}
if ( V_56 < V_27 )
F_149 ( V_118 ) ;
}
static T_2 * F_151 ( struct V_118 * V_118 )
{
F_87 ( ! V_118 -> V_130 -> V_49 -> V_200 ) ;
return V_118 -> V_130 -> V_49 -> V_200 ( V_118 ) ;
}
void F_152 ( struct V_118 * V_118 , T_2 V_135 )
{
F_5 ( & V_118 -> V_123 ) ;
* F_151 ( V_118 ) += V_135 ;
F_6 ( & V_118 -> V_123 ) ;
}
void F_153 ( struct V_118 * V_118 , T_2 V_135 )
{
F_5 ( & V_118 -> V_123 ) ;
* F_151 ( V_118 ) -= V_135 ;
F_154 ( V_118 , V_135 ) ;
F_6 ( & V_118 -> V_123 ) ;
}
void F_155 ( struct V_118 * V_118 , T_2 V_135 )
{
F_5 ( & V_118 -> V_123 ) ;
* F_151 ( V_118 ) -= V_135 ;
F_6 ( & V_118 -> V_123 ) ;
}
static T_2 F_103 ( struct V_118 * V_118 )
{
T_2 V_51 ;
if ( ! V_118 -> V_130 -> V_49 -> V_200 )
return 0 ;
F_5 ( & V_118 -> V_123 ) ;
V_51 = * F_151 ( V_118 ) ;
F_6 ( & V_118 -> V_123 ) ;
return V_51 ;
}
static void F_156 ( struct V_118 * V_118 , T_2 V_135 ,
int V_201 )
{
if ( V_201 )
F_152 ( V_118 , V_135 ) ;
else
F_157 ( V_118 , V_135 ) ;
}
static void F_158 ( struct V_118 * V_118 , T_2 V_135 , int V_201 )
{
if ( V_201 )
F_155 ( V_118 , V_135 ) ;
else
F_159 ( V_118 , V_135 ) ;
}
int F_160 ( struct V_118 * V_118 , T_2 V_135 , int V_89 )
{
int V_56 , V_51 = 0 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * * V_202 = V_118 -> V_119 ;
int V_201 = V_89 & V_203 ;
if ( ! F_143 ( V_118 ) ) {
F_156 ( V_118 , V_135 , V_201 ) ;
goto V_83;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_155 [ V_56 ] . V_166 = V_175 ;
F_161 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_5 ( & V_198 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
V_51 = F_140 ( V_202 [ V_56 ] , V_135 ,
! ( V_89 & V_204 ) , & V_155 [ V_56 ] ) ;
if ( V_51 && ! ( V_89 & V_205 ) ) {
F_6 ( & V_198 ) ;
goto V_206;
}
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
if ( V_201 )
F_116 ( V_202 [ V_56 ] , V_135 ) ;
else
F_115 ( V_202 [ V_56 ] , V_135 ) ;
}
F_156 ( V_118 , V_135 , V_201 ) ;
F_6 ( & V_198 ) ;
if ( V_201 )
goto V_206;
F_43 ( V_202 ) ;
V_206:
F_162 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_132 ( V_155 ) ;
V_83:
return V_51 ;
}
int F_163 ( const struct V_118 * V_118 )
{
int V_56 , V_51 = 0 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * const * V_202 = V_118 -> V_119 ;
if ( ! F_143 ( V_118 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_155 [ V_56 ] . V_166 = V_175 ;
F_161 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_5 ( & V_198 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
V_51 = F_137 ( V_202 [ V_56 ] , 1 , & V_155 [ V_56 ] ) ;
if ( V_51 )
goto V_207;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_202 [ V_56 ] )
continue;
F_114 ( V_202 [ V_56 ] , 1 ) ;
}
V_207:
F_6 ( & V_198 ) ;
if ( V_51 == 0 )
F_43 ( V_202 ) ;
F_162 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_132 ( V_155 ) ;
return V_51 ;
}
int F_164 ( struct V_118 * V_118 , T_2 V_135 )
{
int V_56 ;
if ( ! F_143 ( V_118 ) ) {
F_153 ( V_118 , V_135 ) ;
return 0 ;
}
F_161 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_5 ( & V_198 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_118 -> V_119 [ V_56 ] )
F_117 ( V_118 -> V_119 [ V_56 ] ,
V_135 ) ;
}
F_153 ( V_118 , V_135 ) ;
F_6 ( & V_198 ) ;
F_43 ( V_118 -> V_119 ) ;
F_162 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
return 0 ;
}
void F_165 ( struct V_118 * V_118 , T_2 V_135 , int V_89 )
{
unsigned int V_56 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * * V_202 = V_118 -> V_119 ;
int V_201 = V_89 & V_203 ;
if ( ! F_143 ( V_118 ) ) {
F_158 ( V_118 , V_135 , V_201 ) ;
return;
}
F_161 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_5 ( & V_198 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_208 ;
V_155 [ V_56 ] . V_166 = V_175 ;
if ( ! V_202 [ V_56 ] )
continue;
V_208 = F_142 ( V_202 [ V_56 ] , V_135 ) ;
if ( V_208 != V_175 )
F_131 ( & V_155 [ V_56 ] , V_202 [ V_56 ] , V_208 ) ;
if ( V_201 )
F_119 ( V_202 [ V_56 ] , V_135 ) ;
else
F_121 ( V_202 [ V_56 ] , V_135 ) ;
}
F_158 ( V_118 , V_135 , V_201 ) ;
F_6 ( & V_198 ) ;
if ( V_201 )
goto V_209;
F_43 ( V_202 ) ;
V_209:
F_162 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_132 ( V_155 ) ;
}
void F_166 ( const struct V_118 * V_118 )
{
unsigned int V_56 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * const * V_202 = V_118 -> V_119 ;
if ( ! F_143 ( V_118 ) )
return;
F_161 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_5 ( & V_198 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_208 ;
V_155 [ V_56 ] . V_166 = V_175 ;
if ( ! V_202 [ V_56 ] )
continue;
V_208 = F_141 ( V_202 [ V_56 ] , 1 ) ;
if ( V_208 != V_175 )
F_131 ( & V_155 [ V_56 ] , V_202 [ V_56 ] , V_208 ) ;
F_120 ( V_202 [ V_56 ] , 1 ) ;
}
F_6 ( & V_198 ) ;
F_43 ( V_202 ) ;
F_162 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_132 ( V_155 ) ;
}
int F_167 ( struct V_118 * V_118 , struct V_30 * * V_210 )
{
T_2 V_188 , V_211 ;
T_2 V_212 = 0 ;
struct V_30 * V_213 [ V_27 ] = {} ;
int V_56 , V_51 = 0 ;
char V_214 [ V_27 ] = {} ;
struct V_154 V_215 [ V_27 ] ;
struct V_154 V_216 [ V_27 ] ;
struct V_154 V_217 [ V_27 ] ;
if ( F_99 ( V_118 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_215 [ V_56 ] . V_166 = V_175 ;
V_216 [ V_56 ] . V_166 = V_175 ;
V_217 [ V_56 ] . V_166 = V_175 ;
}
F_112 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
if ( F_99 ( V_118 ) ) {
F_113 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
return 0 ;
}
F_5 ( & V_198 ) ;
V_211 = F_168 ( V_118 ) ;
V_212 = F_103 ( V_118 ) ;
V_188 = V_211 + V_212 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_210 [ V_56 ] )
continue;
if ( ! F_73 ( V_118 -> V_130 , V_56 ) )
continue;
V_214 [ V_56 ] = 1 ;
V_213 [ V_56 ] = V_118 -> V_119 [ V_56 ] ;
V_51 = F_137 ( V_210 [ V_56 ] , 1 , & V_215 [ V_56 ] ) ;
if ( V_51 )
goto V_218;
V_51 = F_140 ( V_210 [ V_56 ] , V_188 , 0 , & V_215 [ V_56 ] ) ;
if ( V_51 )
goto V_218;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_214 [ V_56 ] )
continue;
if ( V_213 [ V_56 ] ) {
int V_208 ;
V_208 = F_141 ( V_213 [ V_56 ] , 1 ) ;
if ( V_208 != V_175 )
F_131 ( & V_216 [ V_56 ] ,
V_213 [ V_56 ] , V_208 ) ;
V_208 = F_142 ( V_213 [ V_56 ] , V_188 ) ;
if ( V_208 != V_175 )
F_131 ( & V_217 [ V_56 ] ,
V_213 [ V_56 ] , V_208 ) ;
F_120 ( V_213 [ V_56 ] , 1 ) ;
F_121 ( V_213 [ V_56 ] , V_211 ) ;
F_119 ( V_213 [ V_56 ] ,
V_212 ) ;
}
F_114 ( V_210 [ V_56 ] , 1 ) ;
F_115 ( V_210 [ V_56 ] , V_211 ) ;
F_116 ( V_210 [ V_56 ] , V_212 ) ;
V_118 -> V_119 [ V_56 ] = V_210 [ V_56 ] ;
}
F_6 ( & V_198 ) ;
F_113 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_43 ( V_213 ) ;
F_43 ( V_210 ) ;
F_132 ( V_215 ) ;
F_132 ( V_216 ) ;
F_132 ( V_217 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_214 [ V_56 ] )
V_210 [ V_56 ] = V_213 [ V_56 ] ;
return 0 ;
V_218:
F_6 ( & V_198 ) ;
F_113 ( & F_42 ( V_118 -> V_130 ) -> V_134 ) ;
F_132 ( V_215 ) ;
return V_51 ;
}
int F_169 ( struct V_118 * V_118 , struct V_219 * V_219 )
{
struct V_30 * V_210 [ V_27 ] = {} ;
struct V_1 * V_2 = V_118 -> V_130 ;
int V_51 ;
if ( ! F_143 ( V_118 ) )
return 0 ;
if ( V_219 -> V_220 & V_221 && ! F_124 ( V_219 -> V_222 , V_118 -> V_195 ) )
V_210 [ V_158 ] = F_97 ( V_2 , F_146 ( V_219 -> V_222 ) ) ;
if ( V_219 -> V_220 & V_223 && ! F_170 ( V_219 -> V_224 , V_118 -> V_196 ) )
V_210 [ V_160 ] = F_97 ( V_2 , F_147 ( V_219 -> V_224 ) ) ;
V_51 = F_167 ( V_118 , V_210 ) ;
F_44 ( V_210 ) ;
return V_51 ;
}
int F_171 ( struct V_1 * V_2 , int type )
{
int V_51 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_34 ( & V_61 -> V_62 ) ;
V_51 = V_61 -> V_64 [ type ] -> F_54 ( V_2 , type ) ;
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_172 ( struct V_118 * V_118 , struct V_225 * V_225 )
{
int error ;
error = F_173 ( V_118 , V_225 ) ;
if ( ! error && ( V_225 -> V_226 & V_227 ) )
F_148 ( V_118 ) ;
return error ;
}
int F_174 ( struct V_1 * V_2 , int type , unsigned int V_89 )
{
int V_56 , V_51 = 0 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_118 * V_228 [ V_27 ] ;
if ( ( V_89 & V_229 && ! ( V_89 & V_230 ) )
|| ( V_89 & V_231 && V_89 & ( V_230 |
V_229 ) ) )
return - V_232 ;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_144 ( V_2 ) ) {
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_228 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_175 ( V_2 , V_56 ) )
continue;
if ( V_89 & V_231 ) {
F_5 ( & V_115 ) ;
V_61 -> V_89 |=
F_176 ( V_231 , V_56 ) ;
F_6 ( & V_115 ) ;
} else {
F_5 ( & V_115 ) ;
V_61 -> V_89 &= ~ F_176 ( V_89 , V_56 ) ;
if ( ! F_175 ( V_2 , V_56 ) &&
F_177 ( V_2 , V_56 ) ) {
V_61 -> V_89 &= ~ F_176 (
V_231 , V_56 ) ;
F_6 ( & V_115 ) ;
F_104 ( V_61 -> V_94 [ V_56 ] ) ;
V_61 -> V_94 [ V_56 ] = NULL ;
continue;
}
F_6 ( & V_115 ) ;
}
if ( F_175 ( V_2 , V_56 ) && ! ( V_89 & V_231 ) )
continue;
F_110 ( V_2 , V_56 ) ;
F_62 ( V_2 , V_56 ) ;
if ( F_53 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
if ( V_61 -> V_64 [ V_56 ] -> V_233 )
V_61 -> V_64 [ V_56 ] -> V_233 ( V_2 , V_56 ) ;
F_11 ( V_61 -> V_53 [ V_56 ] . V_179 ) ;
V_228 [ V_56 ] = V_61 -> V_94 [ V_56 ] ;
if ( ! F_175 ( V_2 , V_56 ) )
V_61 -> V_94 [ V_56 ] = NULL ;
V_61 -> V_53 [ V_56 ] . V_58 = 0 ;
V_61 -> V_53 [ V_56 ] . V_187 = 0 ;
V_61 -> V_53 [ V_56 ] . V_192 = 0 ;
V_61 -> V_64 [ V_56 ] = NULL ;
}
F_35 ( & V_61 -> V_81 ) ;
if ( V_61 -> V_89 & V_90 )
goto V_234;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_76 ( V_2 -> V_93 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_228 [ V_56 ] ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_175 ( V_2 , V_56 ) ) {
F_34 ( & V_228 [ V_56 ] -> V_95 ) ;
V_228 [ V_56 ] -> V_235 &= ~ ( V_236 |
V_237 | V_238 ) ;
F_77 ( & V_228 [ V_56 ] -> V_96 ,
0 ) ;
F_35 ( & V_228 [ V_56 ] -> V_95 ) ;
F_178 ( V_228 [ V_56 ] ) ;
}
F_35 ( & V_61 -> V_81 ) ;
}
if ( V_2 -> V_93 )
F_179 ( V_2 -> V_93 ) ;
V_234:
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_228 [ V_56 ] ) {
if ( ! ( V_89 & V_231 ) )
F_104 ( V_228 [ V_56 ] ) ;
else if ( ! V_228 [ V_56 ] -> V_239 )
V_51 = - V_240 ;
}
return V_51 ;
}
int F_180 ( struct V_1 * V_2 , int type )
{
return F_174 ( V_2 , type ,
V_229 | V_230 ) ;
}
static int F_181 ( struct V_118 * V_118 , int type , int V_241 ,
unsigned int V_89 )
{
struct V_10 * V_4 = F_8 ( V_241 ) ;
struct V_1 * V_2 = V_118 -> V_130 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int error ;
int V_242 = - 1 ;
if ( ! V_4 )
return - V_243 ;
if ( ! F_182 ( V_118 -> V_244 ) ) {
error = - V_245 ;
goto V_246;
}
if ( F_183 ( V_118 ) ) {
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
F_184 ( V_2 ) ;
F_179 ( V_2 -> V_93 ) ;
}
F_34 ( & V_61 -> V_81 ) ;
if ( F_175 ( V_2 , type ) ) {
error = - V_240 ;
goto V_250;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_34 ( & V_118 -> V_95 ) ;
V_242 = V_118 -> V_235 & ( V_237 | V_236 |
V_238 ) ;
V_118 -> V_235 |= V_238 | V_237 | V_236 ;
F_35 ( & V_118 -> V_95 ) ;
F_149 ( V_118 ) ;
}
error = - V_69 ;
V_61 -> V_94 [ type ] = F_185 ( V_118 ) ;
if ( ! V_61 -> V_94 [ type ] )
goto V_250;
error = - V_232 ;
if ( ! V_4 -> V_251 -> V_252 ( V_2 , type ) )
goto V_253;
V_61 -> V_64 [ type ] = V_4 -> V_251 ;
V_61 -> V_53 [ type ] . V_179 = V_4 ;
V_61 -> V_53 [ type ] . V_254 = V_241 ;
F_92 ( & V_61 -> V_53 [ type ] . V_54 ) ;
F_34 ( & V_61 -> V_62 ) ;
error = V_61 -> V_64 [ type ] -> F_186 ( V_2 , type ) ;
if ( error < 0 ) {
F_35 ( & V_61 -> V_62 ) ;
goto V_253;
}
if ( V_61 -> V_89 & V_90 )
V_61 -> V_53 [ type ] . V_58 |= V_255 ;
F_35 ( & V_61 -> V_62 ) ;
F_5 ( & V_115 ) ;
V_61 -> V_89 |= F_176 ( V_89 , type ) ;
F_6 ( & V_115 ) ;
F_100 ( V_2 , type ) ;
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
V_253:
V_61 -> V_94 [ type ] = NULL ;
F_104 ( V_118 ) ;
V_250:
if ( V_242 != - 1 ) {
F_34 ( & V_118 -> V_95 ) ;
V_118 -> V_235 &= ~ ( V_237 | V_238 | V_236 ) ;
V_118 -> V_235 |= V_242 ;
F_35 ( & V_118 -> V_95 ) ;
}
F_35 ( & V_61 -> V_81 ) ;
V_246:
F_11 ( V_4 ) ;
return error ;
}
int F_187 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_118 * V_118 ;
int V_51 = 0 , V_56 ;
unsigned int V_89 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_177 ( V_2 , V_56 ) ) {
F_35 ( & V_61 -> V_81 ) ;
continue;
}
V_118 = V_61 -> V_94 [ V_56 ] ;
V_61 -> V_94 [ V_56 ] = NULL ;
F_5 ( & V_115 ) ;
V_89 = V_61 -> V_89 & F_176 ( V_229 |
V_230 ,
V_56 ) ;
V_61 -> V_89 &= ~ F_176 ( V_256 , V_56 ) ;
F_6 ( & V_115 ) ;
F_35 ( & V_61 -> V_81 ) ;
V_89 = F_188 ( V_89 , V_56 ) ;
V_51 = F_181 ( V_118 , V_56 ,
V_61 -> V_53 [ V_56 ] . V_254 , V_89 ) ;
F_104 ( V_118 ) ;
}
return V_51 ;
}
int F_189 ( struct V_1 * V_2 , int type , int V_241 ,
struct V_257 * V_257 )
{
int error = F_190 ( V_257 -> V_258 ) ;
if ( error )
return error ;
if ( V_257 -> V_258 -> V_259 != V_2 )
error = - V_260 ;
else
error = F_181 ( V_257 -> V_258 -> V_261 , type ,
V_241 , V_229 |
V_230 ) ;
return error ;
}
int F_191 ( struct V_118 * V_118 , int type , int V_241 ,
unsigned int V_89 )
{
int V_51 = 0 ;
struct V_1 * V_2 = V_118 -> V_130 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_87 ( V_89 & V_231 ) ;
if ( ! V_89 )
return 0 ;
if ( F_175 ( V_2 , type ) ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_175 ( V_2 , type ) ) {
F_35 ( & V_61 -> V_81 ) ;
goto V_262;
}
if ( V_89 & V_229 &&
F_192 ( V_2 , type ) ) {
V_51 = - V_240 ;
goto V_250;
}
if ( V_89 & V_230 &&
F_138 ( V_2 , type ) ) {
V_51 = - V_240 ;
goto V_250;
}
F_5 ( & V_115 ) ;
F_42 ( V_2 ) -> V_89 |= F_176 ( V_89 , type ) ;
F_6 ( & V_115 ) ;
V_250:
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
V_262:
return F_181 ( V_118 , type , V_241 , V_89 ) ;
}
int F_193 ( struct V_1 * V_2 , char * V_263 ,
int V_241 , int type )
{
struct V_258 * V_258 ;
int error ;
F_34 ( & V_2 -> V_264 -> V_261 -> V_95 ) ;
V_258 = F_194 ( V_263 , V_2 -> V_264 , strlen ( V_263 ) ) ;
F_35 ( & V_2 -> V_264 -> V_261 -> V_95 ) ;
if ( F_195 ( V_258 ) )
return F_196 ( V_258 ) ;
if ( ! V_258 -> V_261 ) {
error = - V_265 ;
goto V_83;
}
error = F_190 ( V_258 ) ;
if ( ! error )
error = F_181 ( V_258 -> V_261 , type , V_241 ,
V_229 | V_230 ) ;
V_83:
F_197 ( V_258 ) ;
return error ;
}
static inline T_2 F_198 ( T_2 V_266 )
{
return V_266 << V_267 ;
}
static inline T_2 F_199 ( T_2 V_188 )
{
return ( V_188 + V_268 - 1 ) >> V_267 ;
}
static void F_200 ( struct V_30 * V_30 , struct V_269 * V_270 )
{
struct V_271 * V_272 = & V_30 -> V_136 ;
memset ( V_270 , 0 , sizeof( * V_270 ) ) ;
V_270 -> V_273 = V_274 ;
V_270 -> V_275 = V_30 -> V_35 . type == V_158 ?
V_276 : V_277 ;
V_270 -> V_278 = F_201 ( F_202 () , V_30 -> V_35 ) ;
F_5 ( & V_198 ) ;
V_270 -> V_279 = F_199 ( V_272 -> V_191 ) ;
V_270 -> V_280 = F_199 ( V_272 -> V_145 ) ;
V_270 -> V_281 = V_272 -> V_185 ;
V_270 -> V_282 = V_272 -> V_141 ;
V_270 -> V_283 = V_272 -> V_138 + V_272 -> V_139 ;
V_270 -> V_284 = V_272 -> V_137 ;
V_270 -> V_285 = V_272 -> V_146 ;
V_270 -> V_286 = V_272 -> V_142 ;
F_6 ( & V_198 ) ;
}
int F_203 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_269 * V_270 )
{
struct V_30 * V_30 ;
V_30 = F_97 ( V_2 , V_23 ) ;
if ( ! V_30 )
return - V_243 ;
F_200 ( V_30 , V_270 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_204 ( struct V_30 * V_30 , struct V_269 * V_270 )
{
struct V_271 * V_272 = & V_30 -> V_136 ;
int V_287 = 0 , V_288 = 0 ;
struct V_177 * V_289 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
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
F_5 ( & V_198 ) ;
if ( V_270 -> V_290 & V_299 ) {
V_272 -> V_138 = V_270 -> V_283 - V_272 -> V_139 ;
V_287 = 1 ;
F_49 ( V_300 + V_301 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_292 )
V_272 -> V_145 = F_198 ( V_270 -> V_280 ) ;
if ( V_270 -> V_290 & V_294 )
V_272 -> V_191 = F_198 ( V_270 -> V_279 ) ;
if ( V_270 -> V_290 & ( V_292 | V_294 ) ) {
V_287 = 1 ;
F_49 ( V_300 + V_302 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_303 ) {
V_272 -> V_137 = V_270 -> V_284 ;
V_288 = 1 ;
F_49 ( V_300 + V_304 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_295 )
V_272 -> V_141 = V_270 -> V_282 ;
if ( V_270 -> V_290 & V_297 )
V_272 -> V_185 = V_270 -> V_281 ;
if ( V_270 -> V_290 & ( V_295 | V_297 ) ) {
V_288 = 1 ;
F_49 ( V_300 + V_305 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_306 ) {
V_272 -> V_146 = V_270 -> V_285 ;
V_287 = 1 ;
F_49 ( V_300 + V_307 , & V_30 -> V_48 ) ;
}
if ( V_270 -> V_290 & V_308 ) {
V_272 -> V_142 = V_270 -> V_286 ;
V_288 = 1 ;
F_49 ( V_300 + V_309 , & V_30 -> V_48 ) ;
}
if ( V_287 ) {
if ( ! V_272 -> V_145 ||
V_272 -> V_138 < V_272 -> V_145 ) {
V_272 -> V_146 = 0 ;
F_58 ( V_147 , & V_30 -> V_48 ) ;
} else if ( ! ( V_270 -> V_290 & V_306 ) )
V_272 -> V_146 = F_139 () + V_289 -> V_192 ;
}
if ( V_288 ) {
if ( ! V_272 -> V_141 ||
V_272 -> V_137 < V_272 -> V_141 ) {
V_272 -> V_142 = 0 ;
F_58 ( V_144 , & V_30 -> V_48 ) ;
} else if ( ! ( V_270 -> V_290 & V_308 ) )
V_272 -> V_142 = F_139 () + V_289 -> V_187 ;
}
if ( V_272 -> V_191 || V_272 -> V_145 || V_272 -> V_185 ||
V_272 -> V_141 )
F_58 ( V_184 , & V_30 -> V_48 ) ;
else
F_49 ( V_184 , & V_30 -> V_48 ) ;
F_6 ( & V_198 ) ;
F_38 ( V_30 ) ;
return 0 ;
}
int F_205 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_269 * V_270 )
{
struct V_30 * V_30 ;
int V_310 ;
V_30 = F_97 ( V_2 , V_23 ) ;
if ( ! V_30 ) {
V_310 = - V_243 ;
goto V_83;
}
V_310 = F_204 ( V_30 , V_270 ) ;
F_45 ( V_30 ) ;
V_83:
return V_310 ;
}
int F_206 ( struct V_1 * V_2 , int type , struct V_311 * V_312 )
{
struct V_177 * V_313 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_73 ( V_2 , type ) ) {
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return - V_243 ;
}
V_313 = F_42 ( V_2 ) -> V_53 + type ;
F_5 ( & V_198 ) ;
V_312 -> V_192 = V_313 -> V_192 ;
V_312 -> V_187 = V_313 -> V_187 ;
V_312 -> V_58 = V_313 -> V_58 & V_314 ;
V_312 -> V_315 = V_316 ;
F_6 ( & V_198 ) ;
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return 0 ;
}
int F_207 ( struct V_1 * V_2 , int type , struct V_311 * V_312 )
{
struct V_177 * V_313 ;
int V_55 = 0 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_73 ( V_2 , type ) ) {
V_55 = - V_243 ;
goto V_83;
}
V_313 = F_42 ( V_2 ) -> V_53 + type ;
F_5 ( & V_198 ) ;
if ( V_312 -> V_315 & V_317 )
V_313 -> V_192 = V_312 -> V_192 ;
if ( V_312 -> V_315 & V_318 )
V_313 -> V_187 = V_312 -> V_187 ;
if ( V_312 -> V_315 & V_319 )
V_313 -> V_58 = ( V_313 -> V_58 & ~ V_320 ) |
( V_312 -> V_58 & V_320 ) ;
F_6 ( & V_198 ) ;
F_48 ( V_2 , type ) ;
V_2 -> V_49 -> V_87 ( V_2 , type ) ;
V_83:
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_55 ;
}
static int F_208 ( struct V_321 * V_322 , int V_323 ,
void T_3 * V_324 , T_4 * V_325 , T_5 * V_326 )
{
unsigned int type = ( int * ) V_322 -> V_327 - V_105 . V_328 ;
V_105 . V_328 [ type ] =
F_209 ( & V_105 . V_106 [ type ] ) ;
return F_210 ( V_322 , V_323 , V_324 , V_325 , V_326 ) ;
}
static int T_6 F_211 ( void )
{
int V_174 , V_51 ;
unsigned long V_329 , V_330 ;
F_3 ( V_331 L_21 , V_332 ) ;
F_212 ( V_333 ) ;
V_73 = F_213 ( L_22 ,
sizeof( struct V_30 ) , sizeof( unsigned long ) * 4 ,
( V_334 | V_335 |
V_336 | V_337 ) ,
NULL ) ;
V_330 = 0 ;
V_33 = (struct V_31 * ) F_214 ( V_338 , V_330 ) ;
if ( ! V_33 )
F_215 ( L_23 ) ;
for ( V_174 = 0 ; V_174 < V_339 ; V_174 ++ ) {
V_51 = F_216 ( & V_105 . V_106 [ V_174 ] , 0 ) ;
if ( V_51 )
F_215 ( L_24 ) ;
}
V_329 = ( 1UL << V_330 ) * V_340 / sizeof( struct V_31 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( V_329 >> V_28 );
V_28 -- ;
V_329 = 1UL << V_28 ;
V_29 = V_329 - 1 ;
for ( V_174 = 0 ; V_174 < V_329 ; V_174 ++ )
F_217 ( V_33 + V_174 ) ;
F_3 ( L_25 ,
V_329 , V_330 , ( V_340 << V_330 ) ) ;
F_218 ( & V_341 ) ;
return 0 ;
}

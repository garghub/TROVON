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
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
F_5 ( & V_11 ) ;
F_72 (dquot, &inuse_list, dq_inuse) {
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) )
continue;
if ( V_30 -> V_34 != V_2 )
continue;
F_73 ( & V_30 -> V_70 ) ;
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
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_51 ;
}
int F_74 ( struct V_1 * V_2 , int type )
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
if ( ! F_75 ( V_2 , V_56 ) )
continue;
F_5 ( & V_11 ) ;
V_85 = & V_61 -> V_53 [ V_56 ] . V_54 ;
while ( ! F_27 ( V_85 ) ) {
V_30 = F_76 ( V_85 , struct V_30 ,
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
if ( ( V_56 == type || type == - 1 ) && F_75 ( V_2 , V_56 )
&& F_54 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
F_25 ( V_88 ) ;
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
int F_77 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
int V_56 ;
int V_51 ;
V_51 = F_74 ( V_2 , type ) ;
if ( V_51 )
return V_51 ;
if ( V_61 -> V_89 & V_90 )
return 0 ;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_78 ( V_2 -> V_93 ) ;
F_34 ( & V_61 -> V_81 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_75 ( V_2 , V_56 ) )
continue;
F_79 ( V_61 -> V_94 [ V_56 ] ) ;
F_80 ( & V_61 -> V_94 [ V_56 ] -> V_95 , 0 ) ;
F_81 ( V_61 -> V_94 [ V_56 ] ) ;
}
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
static unsigned long
F_82 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
struct V_84 * V_32 ;
struct V_30 * V_30 ;
unsigned long V_100 = 0 ;
F_5 ( & V_11 ) ;
V_32 = V_41 . V_101 ;
while ( V_32 != & V_41 && V_99 -> V_102 ) {
V_30 = F_83 ( V_32 , struct V_30 , V_40 ) ;
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
F_84 ( struct V_96 * V_97 , struct V_98 * V_99 )
{
return F_85 (
F_86 ( & V_103 . V_104 [ V_42 ] ) ) ;
}
void F_45 ( struct V_30 * V_30 )
{
int V_51 ;
if ( ! V_30 )
return;
#ifdef F_87
if ( ! F_58 ( & V_30 -> V_70 ) ) {
F_88 ( V_30 -> V_34 , L_2 ,
V_105 [ V_30 -> V_35 . type ] ,
F_14 ( & V_24 , V_30 -> V_35 ) ) ;
F_89 () ;
}
#endif
F_25 ( V_106 ) ;
V_107:
F_5 ( & V_11 ) ;
if ( F_58 ( & V_30 -> V_70 ) > 1 ) {
F_90 ( & V_30 -> V_70 ) ;
if ( ! F_75 ( V_30 -> V_34 , V_30 -> V_35 . type ) &&
F_58 ( & V_30 -> V_70 ) == 1 )
F_91 ( & V_30 -> V_77 ) ;
F_6 ( & V_11 ) ;
return;
}
if ( F_37 ( V_66 , & V_30 -> V_48 ) && F_36 ( V_30 ) ) {
F_6 ( & V_11 ) ;
V_51 = V_30 -> V_34 -> V_49 -> V_86 ( V_30 ) ;
if ( V_51 < 0 ) {
F_88 ( V_30 -> V_34 , L_3
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
F_90 ( & V_30 -> V_70 ) ;
#ifdef F_87
F_92 ( ! F_27 ( & V_30 -> V_40 ) ) ;
#endif
F_23 ( V_30 ) ;
F_6 ( & V_11 ) ;
}
struct V_30 * F_93 ( struct V_1 * V_2 , int type )
{
return F_94 ( V_73 , V_109 ) ;
}
static struct V_30 * F_95 ( struct V_1 * V_2 , int type )
{
struct V_30 * V_30 ;
V_30 = V_2 -> V_49 -> V_110 ( V_2 , type ) ;
if( ! V_30 )
return NULL ;
F_96 ( & V_30 -> V_46 ) ;
F_97 ( & V_30 -> V_40 ) ;
F_97 ( & V_30 -> V_43 ) ;
F_98 ( & V_30 -> V_36 ) ;
F_97 ( & V_30 -> V_52 ) ;
F_99 ( & V_30 -> V_77 ) ;
V_30 -> V_34 = V_2 ;
V_30 -> V_35 = F_100 ( type ) ;
F_101 ( & V_30 -> V_70 , 1 ) ;
return V_30 ;
}
struct V_30 * F_102 ( struct V_1 * V_2 , struct V_22 V_23 )
{
unsigned int V_37 = F_13 ( V_2 , V_23 ) ;
struct V_30 * V_30 , * V_111 = NULL ;
if ( ! F_75 ( V_2 , V_23 . type ) )
return F_103 ( - V_112 ) ;
V_107:
F_5 ( & V_11 ) ;
F_5 ( & V_113 ) ;
if ( ! F_75 ( V_2 , V_23 . type ) ) {
F_6 ( & V_113 ) ;
F_6 ( & V_11 ) ;
V_30 = F_103 ( - V_112 ) ;
goto V_83;
}
F_6 ( & V_113 ) ;
V_30 = F_19 ( V_37 , V_2 , V_23 ) ;
if ( ! V_30 ) {
if ( ! V_111 ) {
F_6 ( & V_11 ) ;
V_111 = F_95 ( V_2 , V_23 . type ) ;
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
F_73 ( & V_30 -> V_70 ) ;
F_6 ( & V_11 ) ;
F_25 ( V_114 ) ;
F_25 ( V_82 ) ;
}
F_33 ( V_30 ) ;
if ( ! F_37 ( V_66 , & V_30 -> V_48 ) ) {
int V_55 ;
V_55 = V_2 -> V_49 -> V_115 ( V_30 ) ;
if ( V_55 < 0 ) {
F_45 ( V_30 ) ;
V_30 = F_103 ( V_55 ) ;
goto V_83;
}
}
F_104 () ;
#ifdef F_87
F_92 ( ! V_30 -> V_34 ) ;
#endif
V_83:
if ( V_111 )
F_62 ( V_111 ) ;
return V_30 ;
}
static inline struct V_30 * * F_105 ( struct V_116 * V_116 )
{
return V_116 -> V_117 -> V_91 -> V_118 ( V_116 ) ;
}
static int F_106 ( struct V_116 * V_116 , int type )
{
struct V_30 * const * V_119 ;
int V_56 ;
if ( F_107 ( V_116 ) )
return 0 ;
V_119 = F_105 ( V_116 ) ;
if ( type != - 1 )
return ! V_119 [ type ] ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( ! V_119 [ V_56 ] )
return 1 ;
return 0 ;
}
static void F_108 ( struct V_1 * V_2 , int type )
{
struct V_116 * V_116 , * V_120 = NULL ;
#ifdef F_87
int V_121 = 0 ;
#endif
F_5 ( & V_2 -> V_122 ) ;
F_72 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_116 -> V_123 ) ;
if ( ( V_116 -> V_124 & ( V_125 | V_126 | V_127 ) ) ||
! F_58 ( & V_116 -> V_128 ) ||
! F_106 ( V_116 , type ) ) {
F_6 ( & V_116 -> V_123 ) ;
continue;
}
F_109 ( V_116 ) ;
F_6 ( & V_116 -> V_123 ) ;
F_6 ( & V_2 -> V_122 ) ;
#ifdef F_87
if ( F_110 ( F_111 ( V_116 ) > 0 ) )
V_121 = 1 ;
#endif
F_112 ( V_120 ) ;
F_113 ( V_116 , type ) ;
V_120 = V_116 ;
F_5 ( & V_2 -> V_122 ) ;
}
F_6 ( & V_2 -> V_122 ) ;
F_112 ( V_120 ) ;
#ifdef F_87
if ( V_121 ) {
F_88 ( V_2 , L_5
L_6
L_7 ) ;
}
#endif
}
static void F_114 ( struct V_116 * V_116 , int type ,
struct V_84 * V_129 )
{
struct V_30 * * V_119 = F_105 ( V_116 ) ;
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
static void F_115 ( struct V_84 * V_129 )
{
struct V_84 * V_130 ;
struct V_30 * V_30 ;
V_130 = V_129 -> V_131 ;
while ( V_130 != V_129 ) {
V_30 = F_83 ( V_130 , struct V_30 , V_40 ) ;
V_130 = V_130 -> V_131 ;
F_28 ( & V_30 -> V_40 ) ;
F_45 ( V_30 ) ;
}
}
static void F_116 ( struct V_1 * V_2 , int type ,
struct V_84 * V_129 )
{
struct V_116 * V_116 ;
int V_121 = 0 ;
F_5 ( & V_2 -> V_122 ) ;
F_72 (inode, &sb->s_inodes, i_sb_list) {
F_5 ( & V_132 ) ;
if ( ! F_107 ( V_116 ) ) {
if ( F_110 ( F_111 ( V_116 ) > 0 ) )
V_121 = 1 ;
F_114 ( V_116 , type , V_129 ) ;
}
F_6 ( & V_132 ) ;
}
F_6 ( & V_2 -> V_122 ) ;
#ifdef F_87
if ( V_121 ) {
F_3 ( V_133 L_8
L_9
L_10 , V_2 -> V_9 ) ;
}
#endif
}
static void F_117 ( struct V_1 * V_2 , int type )
{
F_118 ( V_129 ) ;
if ( V_2 -> V_49 ) {
F_116 ( V_2 , type , & V_129 ) ;
F_119 ( & V_134 ) ;
F_115 ( & V_129 ) ;
}
}
static inline void F_120 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_137 += V_135 ;
}
static inline void F_121 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_138 += V_135 ;
}
static inline void F_122 ( struct V_30 * V_30 , T_2 V_135 )
{
V_30 -> V_136 . V_139 += V_135 ;
}
static void F_123 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( V_30 -> V_136 . V_139 < V_135 ) {
F_124 ( 1 ) ;
V_135 = V_30 -> V_136 . V_139 ;
}
V_30 -> V_136 . V_138 += V_135 ;
V_30 -> V_136 . V_139 -= V_135 ;
}
static void F_125 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( F_124 ( V_30 -> V_136 . V_138 < V_135 ) )
V_135 = V_30 -> V_136 . V_138 ;
V_30 -> V_136 . V_139 += V_135 ;
V_30 -> V_136 . V_138 -= V_135 ;
}
static inline
void F_126 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( V_30 -> V_136 . V_139 >= V_135 )
V_30 -> V_136 . V_139 -= V_135 ;
else {
F_124 ( 1 ) ;
V_30 -> V_136 . V_139 = 0 ;
}
}
static void F_127 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_140 ||
V_30 -> V_136 . V_137 >= V_135 )
V_30 -> V_136 . V_137 -= V_135 ;
else
V_30 -> V_136 . V_137 = 0 ;
if ( V_30 -> V_136 . V_137 <= V_30 -> V_136 . V_141 )
V_30 -> V_136 . V_142 = ( V_143 ) 0 ;
F_59 ( V_144 , & V_30 -> V_48 ) ;
}
static void F_128 ( struct V_30 * V_30 , T_2 V_135 )
{
if ( F_42 ( V_30 -> V_34 ) -> V_89 & V_140 ||
V_30 -> V_136 . V_138 >= V_135 )
V_30 -> V_136 . V_138 -= V_135 ;
else
V_30 -> V_136 . V_138 = 0 ;
if ( V_30 -> V_136 . V_138 <= V_30 -> V_136 . V_145 )
V_30 -> V_136 . V_146 = ( V_143 ) 0 ;
F_59 ( V_147 , & V_30 -> V_48 ) ;
}
static int F_129 ( struct V_30 * V_30 , const int V_148 )
{
int V_149 = ( V_148 == V_150 ||
V_148 == V_151 ) ? V_147 :
( ( V_148 == V_152 ||
V_148 == V_153 ) ? V_144 : 0 ) ;
if ( ! V_149 )
return 0 ;
return F_40 ( V_149 , & V_30 -> V_48 ) ;
}
static int F_130 ( struct V_154 * V_155 )
{
if ( ! V_156 )
return 0 ;
switch ( V_155 -> V_157 . type ) {
case V_158 :
return F_131 ( F_132 () , V_155 -> V_157 . V_159 ) ;
case V_160 :
return F_133 ( V_155 -> V_157 . V_161 ) ;
case V_162 :
return 1 ;
}
return 0 ;
}
static void F_134 ( struct V_154 * V_155 )
{
char * V_163 = NULL ;
struct V_164 * V_165 ;
int V_148 = V_155 -> V_166 ;
if ( V_148 == V_167 ||
V_148 == V_168 ||
V_148 == V_169 ||
V_148 == V_170 || ! F_130 ( V_155 ) )
return;
V_165 = F_135 () ;
if ( ! V_165 )
return;
F_136 ( V_165 , V_155 -> V_171 -> V_9 ) ;
if ( V_148 == V_172 || V_148 == V_173 )
F_136 ( V_165 , L_11 ) ;
else
F_136 ( V_165 , L_12 ) ;
F_136 ( V_165 , V_105 [ V_155 -> V_157 . type ] ) ;
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
F_136 ( V_165 , V_163 ) ;
F_137 ( V_165 ) ;
}
static void F_138 ( struct V_154 * V_155 , struct V_30 * V_30 ,
int V_148 )
{
if ( F_129 ( V_30 , V_148 ) )
return;
V_155 -> V_166 = V_148 ;
V_155 -> V_171 = V_30 -> V_34 ;
V_155 -> V_157 = V_30 -> V_35 ;
}
static void F_139 ( struct V_154 * V_155 )
{
int V_174 ;
for ( V_174 = 0 ; V_174 < V_27 ; V_174 ++ ) {
if ( V_155 [ V_174 ] . V_166 == V_175 )
continue;
#ifdef F_140
F_134 ( & V_155 [ V_174 ] ) ;
#endif
F_141 ( V_155 [ V_174 ] . V_157 ,
V_155 [ V_174 ] . V_171 -> V_176 , V_155 [ V_174 ] . V_166 ) ;
}
}
static int F_142 ( struct V_30 * V_30 )
{
struct V_177 * V_53 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
return F_143 ( V_178 ) &&
( V_53 -> V_179 -> V_16 != V_180 ||
! ( V_53 -> V_58 & V_181 ) ) ;
}
static int F_144 ( struct V_30 * V_30 , T_2 V_182 ,
struct V_154 * V_155 )
{
T_2 V_183 = V_30 -> V_136 . V_137 + V_182 ;
if ( ! F_145 ( V_30 -> V_34 , V_30 -> V_35 . type ) ||
F_37 ( V_184 , & V_30 -> V_48 ) )
return 0 ;
if ( V_30 -> V_136 . V_185 &&
V_183 > V_30 -> V_136 . V_185 &&
! F_142 ( V_30 ) ) {
F_138 ( V_155 , V_30 , V_152 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_141 &&
V_183 > V_30 -> V_136 . V_141 &&
V_30 -> V_136 . V_142 &&
F_146 () >= V_30 -> V_136 . V_142 &&
! F_142 ( V_30 ) ) {
F_138 ( V_155 , V_30 , V_153 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_141 &&
V_183 > V_30 -> V_136 . V_141 &&
V_30 -> V_136 . V_142 == 0 ) {
F_138 ( V_155 , V_30 , V_172 ) ;
V_30 -> V_136 . V_142 = F_146 () +
F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] . V_187 ;
}
return 0 ;
}
static int F_147 ( struct V_30 * V_30 , T_2 V_188 , int V_189 ,
struct V_154 * V_155 )
{
T_2 V_190 ;
struct V_1 * V_2 = V_30 -> V_34 ;
if ( ! F_145 ( V_2 , V_30 -> V_35 . type ) ||
F_37 ( V_184 , & V_30 -> V_48 ) )
return 0 ;
V_190 = V_30 -> V_136 . V_138 + V_30 -> V_136 . V_139
+ V_188 ;
if ( V_30 -> V_136 . V_191 &&
V_190 > V_30 -> V_136 . V_191 &&
! F_142 ( V_30 ) ) {
if ( ! V_189 )
F_138 ( V_155 , V_30 , V_150 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_145 &&
V_190 > V_30 -> V_136 . V_145 &&
V_30 -> V_136 . V_146 &&
F_146 () >= V_30 -> V_136 . V_146 &&
! F_142 ( V_30 ) ) {
if ( ! V_189 )
F_138 ( V_155 , V_30 , V_151 ) ;
return - V_186 ;
}
if ( V_30 -> V_136 . V_145 &&
V_190 > V_30 -> V_136 . V_145 &&
V_30 -> V_136 . V_146 == 0 ) {
if ( ! V_189 ) {
F_138 ( V_155 , V_30 , V_173 ) ;
V_30 -> V_136 . V_146 = F_146 () +
F_42 ( V_2 ) -> V_53 [ V_30 -> V_35 . type ] . V_192 ;
}
else
return - V_186 ;
}
return 0 ;
}
static int F_148 ( struct V_30 * V_30 , T_2 V_182 )
{
T_2 V_183 ;
if ( F_37 ( V_184 , & V_30 -> V_48 ) ||
V_30 -> V_136 . V_137 <= V_30 -> V_136 . V_141 ||
! F_145 ( V_30 -> V_34 , V_30 -> V_35 . type ) )
return V_175 ;
V_183 = V_30 -> V_136 . V_137 - V_182 ;
if ( V_183 <= V_30 -> V_136 . V_141 )
return V_168 ;
if ( V_30 -> V_136 . V_137 >= V_30 -> V_136 . V_185 &&
V_183 < V_30 -> V_136 . V_185 )
return V_167 ;
return V_175 ;
}
static int F_149 ( struct V_30 * V_30 , T_2 V_188 )
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
static int F_150 ( const struct V_116 * V_116 )
{
struct V_1 * V_2 = V_116 -> V_117 ;
if ( F_107 ( V_116 ) )
return 0 ;
return F_151 ( V_2 ) & ~ F_152 ( V_2 ) ;
}
static int F_113 ( struct V_116 * V_116 , int type )
{
int V_56 , V_193 = 0 ;
struct V_30 * * V_119 , * V_194 [ V_27 ] = {} ;
struct V_1 * V_2 = V_116 -> V_117 ;
T_2 V_195 ;
int V_51 = 0 ;
if ( ! F_150 ( V_116 ) )
return 0 ;
V_119 = F_105 ( V_116 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
struct V_22 V_23 ;
T_3 V_196 ;
int V_197 ;
struct V_30 * V_30 ;
if ( type != - 1 && V_56 != type )
continue;
if ( V_119 [ V_56 ] )
continue;
if ( ! F_75 ( V_2 , V_56 ) )
continue;
V_193 = 1 ;
switch ( V_56 ) {
case V_158 :
V_23 = F_153 ( V_116 -> V_198 ) ;
break;
case V_160 :
V_23 = F_154 ( V_116 -> V_199 ) ;
break;
case V_162 :
V_197 = V_116 -> V_117 -> V_49 -> V_200 ( V_116 , & V_196 ) ;
if ( V_197 )
continue;
V_23 = F_155 ( V_196 ) ;
break;
}
V_30 = F_102 ( V_2 , V_23 ) ;
if ( F_156 ( V_30 ) ) {
if ( F_157 ( V_30 ) != - V_112 ) {
V_51 = F_157 ( V_30 ) ;
goto V_201;
}
V_30 = NULL ;
}
V_194 [ V_56 ] = V_30 ;
}
if ( ! V_193 )
return 0 ;
F_5 ( & V_132 ) ;
if ( F_107 ( V_116 ) )
goto V_202;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_75 ( V_2 , V_56 ) )
continue;
if ( ! V_194 [ V_56 ] )
continue;
if ( ! V_119 [ V_56 ] ) {
V_119 [ V_56 ] = V_194 [ V_56 ] ;
V_194 [ V_56 ] = NULL ;
V_195 = F_111 ( V_116 ) ;
if ( F_110 ( V_195 ) )
F_122 ( V_119 [ V_56 ] , V_195 ) ;
}
}
V_202:
F_6 ( & V_132 ) ;
V_201:
F_44 ( V_194 ) ;
return V_51 ;
}
int F_158 ( struct V_116 * V_116 )
{
return F_113 ( V_116 , - 1 ) ;
}
static void F_159 ( struct V_116 * V_116 )
{
int V_56 ;
struct V_30 * * V_119 = F_105 ( V_116 ) ;
struct V_30 * V_203 [ V_27 ] ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_203 [ V_56 ] = V_119 [ V_56 ] ;
V_119 [ V_56 ] = NULL ;
}
F_6 ( & V_132 ) ;
F_44 ( V_203 ) ;
}
void F_160 ( struct V_116 * V_116 )
{
struct V_30 * const * V_119 ;
int V_56 ;
if ( F_107 ( V_116 ) )
return;
V_119 = F_105 ( V_116 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_119 [ V_56 ] )
break;
}
if ( V_56 < V_27 )
F_159 ( V_116 ) ;
}
static T_2 * F_161 ( struct V_116 * V_116 )
{
F_92 ( ! V_116 -> V_117 -> V_49 -> V_204 ) ;
return V_116 -> V_117 -> V_49 -> V_204 ( V_116 ) ;
}
void F_162 ( struct V_116 * V_116 , T_2 V_135 )
{
F_5 ( & V_116 -> V_123 ) ;
* F_161 ( V_116 ) += V_135 ;
F_6 ( & V_116 -> V_123 ) ;
}
void F_163 ( struct V_116 * V_116 , T_2 V_135 )
{
F_5 ( & V_116 -> V_123 ) ;
* F_161 ( V_116 ) -= V_135 ;
F_164 ( V_116 , V_135 ) ;
F_6 ( & V_116 -> V_123 ) ;
}
void F_165 ( struct V_116 * V_116 , T_2 V_135 )
{
F_5 ( & V_116 -> V_123 ) ;
* F_161 ( V_116 ) += V_135 ;
F_166 ( V_116 , V_135 ) ;
F_6 ( & V_116 -> V_123 ) ;
}
void F_167 ( struct V_116 * V_116 , T_2 V_135 )
{
F_5 ( & V_116 -> V_123 ) ;
* F_161 ( V_116 ) -= V_135 ;
F_6 ( & V_116 -> V_123 ) ;
}
static T_2 F_111 ( struct V_116 * V_116 )
{
T_2 V_51 ;
if ( ! V_116 -> V_117 -> V_49 -> V_204 )
return 0 ;
F_5 ( & V_116 -> V_123 ) ;
V_51 = * F_161 ( V_116 ) ;
F_6 ( & V_116 -> V_123 ) ;
return V_51 ;
}
static void F_168 ( struct V_116 * V_116 , T_2 V_135 ,
int V_205 )
{
if ( V_205 )
F_162 ( V_116 , V_135 ) ;
else
F_169 ( V_116 , V_135 ) ;
}
static void F_170 ( struct V_116 * V_116 , T_2 V_135 , int V_205 )
{
if ( V_205 )
F_167 ( V_116 , V_135 ) ;
else
F_171 ( V_116 , V_135 ) ;
}
int F_172 ( struct V_116 * V_116 , T_2 V_135 , int V_89 )
{
int V_56 , V_51 = 0 , V_206 ;
struct V_154 V_155 [ V_27 ] ;
int V_205 = V_89 & V_207 ;
struct V_30 * * V_119 ;
if ( ! F_150 ( V_116 ) ) {
F_168 ( V_116 , V_135 , V_205 ) ;
goto V_83;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_155 [ V_56 ] . V_166 = V_175 ;
V_119 = F_105 ( V_116 ) ;
V_206 = F_173 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_119 [ V_56 ] )
continue;
V_51 = F_147 ( V_119 [ V_56 ] , V_135 ,
! ( V_89 & V_208 ) , & V_155 [ V_56 ] ) ;
if ( V_51 && ! ( V_89 & V_209 ) ) {
F_6 ( & V_132 ) ;
goto V_210;
}
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_119 [ V_56 ] )
continue;
if ( V_205 )
F_122 ( V_119 [ V_56 ] , V_135 ) ;
else
F_121 ( V_119 [ V_56 ] , V_135 ) ;
}
F_168 ( V_116 , V_135 , V_205 ) ;
F_6 ( & V_132 ) ;
if ( V_205 )
goto V_210;
F_43 ( V_119 ) ;
V_210:
F_174 ( & V_134 , V_206 ) ;
F_139 ( V_155 ) ;
V_83:
return V_51 ;
}
int F_175 ( struct V_116 * V_116 )
{
int V_56 , V_51 = 0 , V_206 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * const * V_119 ;
if ( ! F_150 ( V_116 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
V_155 [ V_56 ] . V_166 = V_175 ;
V_119 = F_105 ( V_116 ) ;
V_206 = F_173 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_119 [ V_56 ] )
continue;
V_51 = F_144 ( V_119 [ V_56 ] , 1 , & V_155 [ V_56 ] ) ;
if ( V_51 )
goto V_211;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_119 [ V_56 ] )
continue;
F_120 ( V_119 [ V_56 ] , 1 ) ;
}
V_211:
F_6 ( & V_132 ) ;
if ( V_51 == 0 )
F_43 ( V_119 ) ;
F_174 ( & V_134 , V_206 ) ;
F_139 ( V_155 ) ;
return V_51 ;
}
int F_176 ( struct V_116 * V_116 , T_2 V_135 )
{
struct V_30 * * V_119 ;
int V_56 , V_206 ;
if ( ! F_150 ( V_116 ) ) {
F_163 ( V_116 , V_135 ) ;
return 0 ;
}
V_119 = F_105 ( V_116 ) ;
V_206 = F_173 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_119 [ V_56 ] )
F_123 ( V_119 [ V_56 ] , V_135 ) ;
}
F_163 ( V_116 , V_135 ) ;
F_6 ( & V_132 ) ;
F_43 ( V_119 ) ;
F_174 ( & V_134 , V_206 ) ;
return 0 ;
}
void F_177 ( struct V_116 * V_116 , T_2 V_135 )
{
struct V_30 * * V_119 ;
int V_56 , V_206 ;
if ( ! F_150 ( V_116 ) ) {
F_165 ( V_116 , V_135 ) ;
return;
}
V_119 = F_105 ( V_116 ) ;
V_206 = F_173 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( V_119 [ V_56 ] )
F_125 ( V_119 [ V_56 ] , V_135 ) ;
}
F_165 ( V_116 , V_135 ) ;
F_6 ( & V_132 ) ;
F_43 ( V_119 ) ;
F_174 ( & V_134 , V_206 ) ;
return;
}
void F_178 ( struct V_116 * V_116 , T_2 V_135 , int V_89 )
{
unsigned int V_56 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * * V_119 ;
int V_205 = V_89 & V_207 , V_206 ;
if ( ! F_150 ( V_116 ) ) {
F_170 ( V_116 , V_135 , V_205 ) ;
return;
}
V_119 = F_105 ( V_116 ) ;
V_206 = F_173 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_212 ;
V_155 [ V_56 ] . V_166 = V_175 ;
if ( ! V_119 [ V_56 ] )
continue;
V_212 = F_149 ( V_119 [ V_56 ] , V_135 ) ;
if ( V_212 != V_175 )
F_138 ( & V_155 [ V_56 ] , V_119 [ V_56 ] , V_212 ) ;
if ( V_205 )
F_126 ( V_119 [ V_56 ] , V_135 ) ;
else
F_128 ( V_119 [ V_56 ] , V_135 ) ;
}
F_170 ( V_116 , V_135 , V_205 ) ;
F_6 ( & V_132 ) ;
if ( V_205 )
goto V_213;
F_43 ( V_119 ) ;
V_213:
F_174 ( & V_134 , V_206 ) ;
F_139 ( V_155 ) ;
}
void F_179 ( struct V_116 * V_116 )
{
unsigned int V_56 ;
struct V_154 V_155 [ V_27 ] ;
struct V_30 * const * V_119 ;
int V_206 ;
if ( ! F_150 ( V_116 ) )
return;
V_119 = F_105 ( V_116 ) ;
V_206 = F_173 ( & V_134 ) ;
F_5 ( & V_132 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
int V_212 ;
V_155 [ V_56 ] . V_166 = V_175 ;
if ( ! V_119 [ V_56 ] )
continue;
V_212 = F_148 ( V_119 [ V_56 ] , 1 ) ;
if ( V_212 != V_175 )
F_138 ( & V_155 [ V_56 ] , V_119 [ V_56 ] , V_212 ) ;
F_127 ( V_119 [ V_56 ] , 1 ) ;
}
F_6 ( & V_132 ) ;
F_43 ( V_119 ) ;
F_174 ( & V_134 , V_206 ) ;
F_139 ( V_155 ) ;
}
int F_180 ( struct V_116 * V_116 , struct V_30 * * V_214 )
{
T_2 V_188 , V_215 ;
T_2 V_216 = 0 ;
struct V_30 * V_217 [ V_27 ] = {} ;
int V_56 , V_51 = 0 ;
char V_218 [ V_27 ] = {} ;
struct V_154 V_219 [ V_27 ] ;
struct V_154 V_220 [ V_27 ] ;
struct V_154 V_221 [ V_27 ] ;
if ( F_107 ( V_116 ) )
return 0 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_219 [ V_56 ] . V_166 = V_175 ;
V_220 [ V_56 ] . V_166 = V_175 ;
V_221 [ V_56 ] . V_166 = V_175 ;
}
F_5 ( & V_132 ) ;
if ( F_107 ( V_116 ) ) {
F_6 ( & V_132 ) ;
return 0 ;
}
V_215 = F_181 ( V_116 ) ;
V_216 = F_111 ( V_116 ) ;
V_188 = V_215 + V_216 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_214 [ V_56 ] )
continue;
if ( ! F_75 ( V_116 -> V_117 , V_56 ) )
continue;
V_218 [ V_56 ] = 1 ;
V_217 [ V_56 ] = F_105 ( V_116 ) [ V_56 ] ;
V_51 = F_144 ( V_214 [ V_56 ] , 1 , & V_219 [ V_56 ] ) ;
if ( V_51 )
goto V_222;
V_51 = F_147 ( V_214 [ V_56 ] , V_188 , 0 , & V_219 [ V_56 ] ) ;
if ( V_51 )
goto V_222;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( ! V_218 [ V_56 ] )
continue;
if ( V_217 [ V_56 ] ) {
int V_212 ;
V_212 = F_148 ( V_217 [ V_56 ] , 1 ) ;
if ( V_212 != V_175 )
F_138 ( & V_220 [ V_56 ] ,
V_217 [ V_56 ] , V_212 ) ;
V_212 = F_149 ( V_217 [ V_56 ] , V_188 ) ;
if ( V_212 != V_175 )
F_138 ( & V_221 [ V_56 ] ,
V_217 [ V_56 ] , V_212 ) ;
F_127 ( V_217 [ V_56 ] , 1 ) ;
F_128 ( V_217 [ V_56 ] , V_215 ) ;
F_126 ( V_217 [ V_56 ] ,
V_216 ) ;
}
F_120 ( V_214 [ V_56 ] , 1 ) ;
F_121 ( V_214 [ V_56 ] , V_215 ) ;
F_122 ( V_214 [ V_56 ] , V_216 ) ;
F_105 ( V_116 ) [ V_56 ] = V_214 [ V_56 ] ;
}
F_6 ( & V_132 ) ;
F_43 ( V_217 ) ;
F_43 ( V_214 ) ;
F_139 ( V_219 ) ;
F_139 ( V_220 ) ;
F_139 ( V_221 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_218 [ V_56 ] )
V_214 [ V_56 ] = V_217 [ V_56 ] ;
return 0 ;
V_222:
F_6 ( & V_132 ) ;
F_139 ( V_219 ) ;
return V_51 ;
}
int F_182 ( struct V_116 * V_116 , struct V_223 * V_223 )
{
struct V_30 * V_214 [ V_27 ] = {} ;
struct V_30 * V_30 ;
struct V_1 * V_2 = V_116 -> V_117 ;
int V_51 ;
if ( ! F_150 ( V_116 ) )
return 0 ;
if ( V_223 -> V_224 & V_225 && ! F_131 ( V_223 -> V_226 , V_116 -> V_198 ) ) {
V_30 = F_102 ( V_2 , F_153 ( V_223 -> V_226 ) ) ;
if ( F_156 ( V_30 ) ) {
if ( F_157 ( V_30 ) != - V_112 ) {
V_51 = F_157 ( V_30 ) ;
goto V_201;
}
V_30 = NULL ;
}
V_214 [ V_158 ] = V_30 ;
}
if ( V_223 -> V_224 & V_227 && ! F_183 ( V_223 -> V_228 , V_116 -> V_199 ) ) {
V_30 = F_102 ( V_2 , F_154 ( V_223 -> V_228 ) ) ;
if ( F_156 ( V_30 ) ) {
if ( F_157 ( V_30 ) != - V_112 ) {
V_51 = F_157 ( V_30 ) ;
goto V_201;
}
V_30 = NULL ;
}
V_214 [ V_160 ] = V_30 ;
}
V_51 = F_180 ( V_116 , V_214 ) ;
V_201:
F_44 ( V_214 ) ;
return V_51 ;
}
int F_184 ( struct V_1 * V_2 , int type )
{
int V_51 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_34 ( & V_61 -> V_62 ) ;
V_51 = V_61 -> V_64 [ type ] -> F_55 ( V_2 , type ) ;
F_35 ( & V_61 -> V_62 ) ;
return V_51 ;
}
int F_185 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
int V_55 ;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_75 ( V_2 , V_23 -> type ) ) {
V_55 = - V_112 ;
goto V_83;
}
if ( ! V_61 -> V_64 [ V_23 -> type ] -> V_229 ) {
V_55 = - V_230 ;
goto V_83;
}
F_34 ( & V_61 -> V_62 ) ;
V_55 = V_61 -> V_64 [ V_23 -> type ] -> V_229 ( V_2 , V_23 ) ;
F_35 ( & V_61 -> V_62 ) ;
V_83:
F_35 ( & V_61 -> V_81 ) ;
return V_55 ;
}
int F_186 ( struct V_116 * V_116 , struct V_231 * V_231 )
{
int error ;
error = F_187 ( V_116 , V_231 ) ;
if ( ! error && ( V_231 -> V_232 & V_233 ) )
F_158 ( V_116 ) ;
return error ;
}
int F_188 ( struct V_1 * V_2 , int type , unsigned int V_89 )
{
int V_56 , V_51 = 0 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_116 * V_234 [ V_27 ] ;
if ( ( V_89 & V_235 && ! ( V_89 & V_236 ) )
|| ( V_89 & V_237 && V_89 & ( V_236 |
V_235 ) ) )
return - V_238 ;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_151 ( V_2 ) ) {
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
}
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
V_234 [ V_56 ] = NULL ;
if ( type != - 1 && V_56 != type )
continue;
if ( ! F_189 ( V_2 , V_56 ) )
continue;
if ( V_89 & V_237 ) {
F_5 ( & V_113 ) ;
V_61 -> V_89 |=
F_190 ( V_237 , V_56 ) ;
F_6 ( & V_113 ) ;
} else {
F_5 ( & V_113 ) ;
V_61 -> V_89 &= ~ F_190 ( V_89 , V_56 ) ;
if ( ! F_189 ( V_2 , V_56 ) &&
F_191 ( V_2 , V_56 ) ) {
V_61 -> V_89 &= ~ F_190 (
V_237 , V_56 ) ;
F_6 ( & V_113 ) ;
F_112 ( V_61 -> V_94 [ V_56 ] ) ;
V_61 -> V_94 [ V_56 ] = NULL ;
continue;
}
F_6 ( & V_113 ) ;
}
if ( F_189 ( V_2 , V_56 ) && ! ( V_89 & V_237 ) )
continue;
F_117 ( V_2 , V_56 ) ;
F_63 ( V_2 , V_56 ) ;
if ( F_54 ( & V_61 -> V_53 [ V_56 ] ) )
V_2 -> V_49 -> V_87 ( V_2 , V_56 ) ;
if ( V_61 -> V_64 [ V_56 ] -> V_239 )
V_61 -> V_64 [ V_56 ] -> V_239 ( V_2 , V_56 ) ;
F_11 ( V_61 -> V_53 [ V_56 ] . V_179 ) ;
V_234 [ V_56 ] = V_61 -> V_94 [ V_56 ] ;
if ( ! F_189 ( V_2 , V_56 ) )
V_61 -> V_94 [ V_56 ] = NULL ;
V_61 -> V_53 [ V_56 ] . V_58 = 0 ;
V_61 -> V_53 [ V_56 ] . V_187 = 0 ;
V_61 -> V_53 [ V_56 ] . V_192 = 0 ;
V_61 -> V_64 [ V_56 ] = NULL ;
}
F_35 ( & V_61 -> V_81 ) ;
if ( V_61 -> V_89 & V_90 )
goto V_240;
if ( V_2 -> V_91 -> V_92 )
V_2 -> V_91 -> V_92 ( V_2 , 1 ) ;
F_78 ( V_2 -> V_93 ) ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_234 [ V_56 ] ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_189 ( V_2 , V_56 ) ) {
F_79 ( V_234 [ V_56 ] ) ;
V_234 [ V_56 ] -> V_241 &= ~ ( V_242 |
V_243 | V_244 ) ;
F_80 ( & V_234 [ V_56 ] -> V_95 ,
0 ) ;
F_81 ( V_234 [ V_56 ] ) ;
F_192 ( V_234 [ V_56 ] ) ;
}
F_35 ( & V_61 -> V_81 ) ;
}
if ( V_2 -> V_93 )
F_193 ( V_2 -> V_93 ) ;
V_240:
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ )
if ( V_234 [ V_56 ] ) {
if ( ! ( V_89 & V_237 ) )
F_112 ( V_234 [ V_56 ] ) ;
else if ( ! V_234 [ V_56 ] -> V_245 )
V_51 = - V_246 ;
}
return V_51 ;
}
int F_194 ( struct V_1 * V_2 , int type )
{
return F_188 ( V_2 , type ,
V_235 | V_236 ) ;
}
static int F_195 ( struct V_116 * V_116 , int type , int V_247 ,
unsigned int V_89 )
{
struct V_10 * V_4 = F_8 ( V_247 ) ;
struct V_1 * V_2 = V_116 -> V_117 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int error ;
int V_248 = - 1 ;
if ( ! V_4 )
return - V_112 ;
if ( ! F_196 ( V_116 -> V_249 ) ) {
error = - V_250 ;
goto V_251;
}
if ( F_197 ( V_116 ) ) {
error = - V_252 ;
goto V_251;
}
if ( ! V_2 -> V_91 -> V_253 || ! V_2 -> V_91 -> V_254 ||
( type == V_162 && V_2 -> V_49 -> V_200 == NULL ) ) {
error = - V_238 ;
goto V_251;
}
if ( ! ( V_89 & V_235 ) ) {
error = - V_238 ;
goto V_251;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_198 ( V_2 ) ;
F_193 ( V_2 -> V_93 ) ;
}
F_34 ( & V_61 -> V_81 ) ;
if ( F_189 ( V_2 , type ) ) {
error = - V_246 ;
goto V_202;
}
if ( ! ( V_61 -> V_89 & V_90 ) ) {
F_79 ( V_116 ) ;
V_248 = V_116 -> V_241 & ( V_243 | V_242 |
V_244 ) ;
V_116 -> V_241 |= V_244 | V_243 | V_242 ;
F_81 ( V_116 ) ;
F_159 ( V_116 ) ;
}
error = - V_69 ;
V_61 -> V_94 [ type ] = F_199 ( V_116 ) ;
if ( ! V_61 -> V_94 [ type ] )
goto V_202;
error = - V_238 ;
if ( ! V_4 -> V_255 -> V_256 ( V_2 , type ) )
goto V_257;
V_61 -> V_64 [ type ] = V_4 -> V_255 ;
V_61 -> V_53 [ type ] . V_179 = V_4 ;
V_61 -> V_53 [ type ] . V_258 = V_247 ;
F_97 ( & V_61 -> V_53 [ type ] . V_54 ) ;
F_34 ( & V_61 -> V_62 ) ;
error = V_61 -> V_64 [ type ] -> F_200 ( V_2 , type ) ;
if ( error < 0 ) {
F_35 ( & V_61 -> V_62 ) ;
goto V_257;
}
if ( V_61 -> V_89 & V_90 )
V_61 -> V_53 [ type ] . V_58 |= V_259 ;
F_35 ( & V_61 -> V_62 ) ;
F_5 ( & V_113 ) ;
V_61 -> V_89 |= F_190 ( V_89 , type ) ;
F_6 ( & V_113 ) ;
F_108 ( V_2 , type ) ;
F_35 ( & V_61 -> V_81 ) ;
return 0 ;
V_257:
V_61 -> V_94 [ type ] = NULL ;
F_112 ( V_116 ) ;
V_202:
if ( V_248 != - 1 ) {
F_79 ( V_116 ) ;
V_116 -> V_241 &= ~ ( V_243 | V_244 | V_242 ) ;
V_116 -> V_241 |= V_248 ;
F_81 ( V_116 ) ;
}
F_35 ( & V_61 -> V_81 ) ;
V_251:
F_11 ( V_4 ) ;
return error ;
}
int F_201 ( struct V_1 * V_2 , int type )
{
struct V_60 * V_61 = F_42 ( V_2 ) ;
struct V_116 * V_116 ;
int V_51 = 0 , V_56 ;
unsigned int V_89 ;
for ( V_56 = 0 ; V_56 < V_27 ; V_56 ++ ) {
if ( type != - 1 && V_56 != type )
continue;
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_191 ( V_2 , V_56 ) ) {
F_35 ( & V_61 -> V_81 ) ;
continue;
}
V_116 = V_61 -> V_94 [ V_56 ] ;
V_61 -> V_94 [ V_56 ] = NULL ;
F_5 ( & V_113 ) ;
V_89 = V_61 -> V_89 & F_190 ( V_235 |
V_236 ,
V_56 ) ;
V_61 -> V_89 &= ~ F_190 ( V_260 , V_56 ) ;
F_6 ( & V_113 ) ;
F_35 ( & V_61 -> V_81 ) ;
V_89 = F_202 ( V_89 , V_56 ) ;
V_51 = F_195 ( V_116 , V_56 ,
V_61 -> V_53 [ V_56 ] . V_258 , V_89 ) ;
F_112 ( V_116 ) ;
}
return V_51 ;
}
int F_203 ( struct V_1 * V_2 , int type , int V_247 ,
struct V_261 * V_261 )
{
int error = F_204 ( V_261 -> V_262 ) ;
if ( error )
return error ;
if ( V_261 -> V_262 -> V_263 != V_2 )
error = - V_264 ;
else
error = F_195 ( F_205 ( V_261 -> V_262 ) , type ,
V_247 , V_235 |
V_236 ) ;
return error ;
}
int F_206 ( struct V_116 * V_116 , int type , int V_247 ,
unsigned int V_89 )
{
int V_51 = 0 ;
struct V_1 * V_2 = V_116 -> V_117 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
F_92 ( V_89 & V_237 ) ;
if ( ! V_89 )
return 0 ;
if ( F_189 ( V_2 , type ) ) {
F_34 ( & V_61 -> V_81 ) ;
if ( ! F_189 ( V_2 , type ) ) {
F_35 ( & V_61 -> V_81 ) ;
goto V_265;
}
if ( V_89 & V_235 &&
F_207 ( V_2 , type ) ) {
V_51 = - V_246 ;
goto V_202;
}
if ( V_89 & V_236 &&
F_145 ( V_2 , type ) ) {
V_51 = - V_246 ;
goto V_202;
}
F_5 ( & V_113 ) ;
F_42 ( V_2 ) -> V_89 |= F_190 ( V_89 , type ) ;
F_6 ( & V_113 ) ;
V_202:
F_35 ( & V_61 -> V_81 ) ;
return V_51 ;
}
V_265:
return F_195 ( V_116 , type , V_247 , V_89 ) ;
}
int F_208 ( struct V_1 * V_2 , char * V_266 ,
int V_247 , int type )
{
struct V_262 * V_262 ;
int error ;
V_262 = F_209 ( V_266 , V_2 -> V_267 , strlen ( V_266 ) ) ;
if ( F_156 ( V_262 ) )
return F_157 ( V_262 ) ;
if ( F_210 ( V_262 ) ) {
error = - V_268 ;
goto V_83;
}
error = F_204 ( V_262 ) ;
if ( ! error )
error = F_195 ( F_205 ( V_262 ) , type , V_247 ,
V_235 | V_236 ) ;
V_83:
F_211 ( V_262 ) ;
return error ;
}
static int F_212 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_230 ;
V_89 &= ~ ( V_269 | V_270 | V_271 ) ;
if ( ! V_89 )
return - V_238 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! ( V_89 & F_213 ( type ) ) )
continue;
if ( ! F_207 ( V_2 , type ) )
return - V_238 ;
V_51 = F_206 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_258 ,
V_236 ) ;
if ( V_51 < 0 )
goto V_272;
}
return 0 ;
V_272:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_213 ( type ) )
F_188 ( V_2 , type , V_236 ) ;
}
if ( V_51 == - V_246 )
V_51 = - V_273 ;
return V_51 ;
}
static int F_214 ( struct V_1 * V_2 , unsigned int V_89 )
{
int V_51 ;
int type ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
if ( ! ( V_61 -> V_89 & V_90 ) )
return - V_230 ;
if ( V_89 &
( V_269 | V_270 | V_271 ) )
return - V_274 ;
for ( type = 0 ; type < V_27 ; type ++ )
if ( ! F_145 ( V_2 , type ) )
V_89 &= ~ F_213 ( type ) ;
if ( ! V_89 )
return - V_273 ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( V_89 & F_213 ( type ) ) {
V_51 = F_188 ( V_2 , type , V_236 ) ;
if ( V_51 < 0 )
goto V_272;
}
}
return 0 ;
V_272:
for ( type -- ; type >= 0 ; type -- ) {
if ( V_89 & F_213 ( type ) )
F_206 ( V_61 -> V_94 [ type ] , type ,
V_61 -> V_53 [ type ] . V_258 ,
V_236 ) ;
}
return V_51 ;
}
static void F_215 ( struct V_30 * V_30 , struct V_275 * V_276 )
{
struct V_277 * V_278 = & V_30 -> V_136 ;
memset ( V_276 , 0 , sizeof( * V_276 ) ) ;
F_5 ( & V_132 ) ;
V_276 -> V_279 = V_278 -> V_191 ;
V_276 -> V_280 = V_278 -> V_145 ;
V_276 -> V_281 = V_278 -> V_185 ;
V_276 -> V_282 = V_278 -> V_141 ;
V_276 -> V_283 = V_278 -> V_138 + V_278 -> V_139 ;
V_276 -> V_284 = V_278 -> V_137 ;
V_276 -> V_285 = V_278 -> V_146 ;
V_276 -> V_286 = V_278 -> V_142 ;
F_6 ( & V_132 ) ;
}
int F_216 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_275 * V_276 )
{
struct V_30 * V_30 ;
V_30 = F_102 ( V_2 , V_23 ) ;
if ( F_156 ( V_30 ) )
return F_157 ( V_30 ) ;
F_215 ( V_30 , V_276 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
int F_217 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_275 * V_276 )
{
struct V_30 * V_30 ;
int V_55 ;
if ( ! V_2 -> V_49 -> V_229 )
return - V_230 ;
V_55 = V_2 -> V_49 -> V_229 ( V_2 , V_23 ) ;
if ( V_55 < 0 )
return V_55 ;
V_30 = F_102 ( V_2 , * V_23 ) ;
if ( F_156 ( V_30 ) )
return F_157 ( V_30 ) ;
F_215 ( V_30 , V_276 ) ;
F_45 ( V_30 ) ;
return 0 ;
}
static int F_218 ( struct V_30 * V_30 , struct V_275 * V_276 )
{
struct V_277 * V_278 = & V_30 -> V_136 ;
int V_287 = 0 , V_288 = 0 ;
struct V_177 * V_289 = & F_42 ( V_30 -> V_34 ) -> V_53 [ V_30 -> V_35 . type ] ;
if ( V_276 -> V_290 & ~ V_291 )
return - V_238 ;
if ( ( ( V_276 -> V_290 & V_292 ) &&
V_276 -> V_280 > V_289 -> V_293 ) ||
( ( V_276 -> V_290 & V_294 ) &&
V_276 -> V_279 > V_289 -> V_293 ) ||
( ( V_276 -> V_290 & V_295 ) &&
( V_276 -> V_282 > V_289 -> V_296 ) ) ||
( ( V_276 -> V_290 & V_297 ) &&
( V_276 -> V_281 > V_289 -> V_296 ) ) )
return - V_298 ;
F_5 ( & V_132 ) ;
if ( V_276 -> V_290 & V_299 ) {
V_278 -> V_138 = V_276 -> V_283 - V_278 -> V_139 ;
V_287 = 1 ;
F_49 ( V_300 + V_301 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_292 )
V_278 -> V_145 = V_276 -> V_280 ;
if ( V_276 -> V_290 & V_294 )
V_278 -> V_191 = V_276 -> V_279 ;
if ( V_276 -> V_290 & ( V_292 | V_294 ) ) {
V_287 = 1 ;
F_49 ( V_300 + V_302 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_303 ) {
V_278 -> V_137 = V_276 -> V_284 ;
V_288 = 1 ;
F_49 ( V_300 + V_304 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_295 )
V_278 -> V_141 = V_276 -> V_282 ;
if ( V_276 -> V_290 & V_297 )
V_278 -> V_185 = V_276 -> V_281 ;
if ( V_276 -> V_290 & ( V_295 | V_297 ) ) {
V_288 = 1 ;
F_49 ( V_300 + V_305 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_306 ) {
V_278 -> V_146 = V_276 -> V_285 ;
V_287 = 1 ;
F_49 ( V_300 + V_307 , & V_30 -> V_48 ) ;
}
if ( V_276 -> V_290 & V_308 ) {
V_278 -> V_142 = V_276 -> V_286 ;
V_288 = 1 ;
F_49 ( V_300 + V_309 , & V_30 -> V_48 ) ;
}
if ( V_287 ) {
if ( ! V_278 -> V_145 ||
V_278 -> V_138 < V_278 -> V_145 ) {
V_278 -> V_146 = 0 ;
F_59 ( V_147 , & V_30 -> V_48 ) ;
} else if ( ! ( V_276 -> V_290 & V_306 ) )
V_278 -> V_146 = F_146 () + V_289 -> V_192 ;
}
if ( V_288 ) {
if ( ! V_278 -> V_141 ||
V_278 -> V_137 < V_278 -> V_141 ) {
V_278 -> V_142 = 0 ;
F_59 ( V_144 , & V_30 -> V_48 ) ;
} else if ( ! ( V_276 -> V_290 & V_308 ) )
V_278 -> V_142 = F_146 () + V_289 -> V_187 ;
}
if ( V_278 -> V_191 || V_278 -> V_145 || V_278 -> V_185 ||
V_278 -> V_141 )
F_59 ( V_184 , & V_30 -> V_48 ) ;
else
F_49 ( V_184 , & V_30 -> V_48 ) ;
F_6 ( & V_132 ) ;
F_38 ( V_30 ) ;
return 0 ;
}
int F_219 ( struct V_1 * V_2 , struct V_22 V_23 ,
struct V_275 * V_276 )
{
struct V_30 * V_30 ;
int V_197 ;
V_30 = F_102 ( V_2 , V_23 ) ;
if ( F_156 ( V_30 ) ) {
V_197 = F_157 ( V_30 ) ;
goto V_83;
}
V_197 = F_218 ( V_30 , V_276 ) ;
F_45 ( V_30 ) ;
V_83:
return V_197 ;
}
int F_220 ( struct V_1 * V_2 , struct V_310 * V_311 )
{
struct V_177 * V_312 ;
struct V_313 * V_314 ;
struct V_60 * V_61 = F_42 ( V_2 ) ;
int type ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
memset ( V_311 , 0 , sizeof( * V_311 ) ) ;
for ( type = 0 ; type < V_27 ; type ++ ) {
if ( ! F_75 ( V_2 , type ) )
continue;
V_314 = V_311 -> V_315 + type ;
V_312 = F_42 ( V_2 ) -> V_53 + type ;
V_314 -> V_89 = V_316 ;
F_5 ( & V_132 ) ;
if ( V_312 -> V_58 & V_259 )
V_314 -> V_89 |= V_317 ;
if ( V_312 -> V_58 & V_181 )
V_314 -> V_89 |= V_318 ;
if ( F_145 ( V_2 , type ) )
V_314 -> V_89 |= V_319 ;
V_314 -> V_320 = V_312 -> V_192 ;
V_314 -> V_321 = V_312 -> V_187 ;
V_314 -> V_322 = V_61 -> V_94 [ type ] -> V_323 ;
V_314 -> V_324 = V_61 -> V_94 [ type ] -> V_325 ;
V_314 -> V_326 = 1 ;
F_6 ( & V_132 ) ;
}
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return 0 ;
}
int F_221 ( struct V_1 * V_2 , int type , struct V_327 * V_328 )
{
struct V_177 * V_312 ;
int V_55 = 0 ;
if ( ( V_328 -> V_329 & V_330 ) ||
( V_328 -> V_329 & V_331 ) )
return - V_238 ;
F_34 ( & F_42 ( V_2 ) -> V_81 ) ;
if ( ! F_75 ( V_2 , type ) ) {
V_55 = - V_112 ;
goto V_83;
}
V_312 = F_42 ( V_2 ) -> V_53 + type ;
if ( V_328 -> V_329 & V_332 ) {
if ( ( V_328 -> V_241 & V_318 &&
V_312 -> V_179 -> V_16 != V_180 ) ) {
V_55 = - V_238 ;
goto V_83;
}
}
F_5 ( & V_132 ) ;
if ( V_328 -> V_329 & V_306 )
V_312 -> V_192 = V_328 -> V_333 ;
if ( V_328 -> V_329 & V_308 )
V_312 -> V_187 = V_328 -> V_334 ;
if ( V_328 -> V_329 & V_332 ) {
if ( V_328 -> V_241 & V_318 )
V_312 -> V_58 |= V_181 ;
else
V_312 -> V_58 &= ~ V_181 ;
}
F_6 ( & V_132 ) ;
F_48 ( V_2 , type ) ;
V_2 -> V_49 -> V_87 ( V_2 , type ) ;
V_83:
F_35 ( & F_42 ( V_2 ) -> V_81 ) ;
return V_55 ;
}
static int F_222 ( struct V_335 * V_336 , int V_337 ,
void T_4 * V_338 , T_5 * V_339 , T_6 * V_340 )
{
unsigned int type = ( int * ) V_336 -> V_341 - V_103 . V_342 ;
V_103 . V_342 [ type ] =
F_223 ( & V_103 . V_104 [ type ] ) ;
return F_224 ( V_336 , V_337 , V_338 , V_339 , V_340 ) ;
}
static int T_7 F_225 ( void )
{
int V_174 , V_51 ;
unsigned long V_343 , V_344 ;
F_3 ( V_345 L_19 , V_346 ) ;
F_226 ( V_347 ) ;
V_73 = F_227 ( L_20 ,
sizeof( struct V_30 ) , sizeof( unsigned long ) * 4 ,
( V_348 | V_349 |
V_350 | V_351 ) ,
NULL ) ;
V_344 = 0 ;
V_33 = (struct V_31 * ) F_228 ( V_352 , V_344 ) ;
if ( ! V_33 )
F_229 ( L_21 ) ;
for ( V_174 = 0 ; V_174 < V_353 ; V_174 ++ ) {
V_51 = F_230 ( & V_103 . V_104 [ V_174 ] , 0 , V_354 ) ;
if ( V_51 )
F_229 ( L_22 ) ;
}
V_343 = ( 1UL << V_344 ) * V_355 / sizeof( struct V_31 ) ;
V_28 = 0 ;
do {
V_28 ++ ;
} while ( V_343 >> V_28 );
V_28 -- ;
V_343 = 1UL << V_28 ;
V_29 = V_343 - 1 ;
for ( V_174 = 0 ; V_174 < V_343 ; V_174 ++ )
F_231 ( V_33 + V_174 ) ;
F_232 ( L_23
L_24 , V_343 , V_344 , ( V_355 << V_344 ) ) ;
F_233 ( & V_356 ) ;
return 0 ;
}

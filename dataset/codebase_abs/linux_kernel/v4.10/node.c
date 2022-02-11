static T_1 F_1 ( struct V_1 * V_2 , bool V_3 , char * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = F_3 ( V_6 -> V_2 . V_9 ) ;
F_4 ( ( V_10 / 32 * 9 ) > ( V_11 - 1 ) ) ;
return F_5 ( V_3 , V_4 , V_8 ) ;
}
static inline T_1 F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
return F_1 ( V_2 , false , V_4 ) ;
}
static inline T_1 F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
return F_1 ( V_2 , true , V_4 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
int V_14 ;
int V_15 = V_2 -> V_9 ;
struct V_16 * V_17 = F_9 ( V_15 ) ;
struct V_18 V_19 ;
F_10 ( & V_19 , V_15 ) ;
V_14 = sprintf ( V_4 ,
L_1
L_2
L_3
L_4
L_5
L_6
L_7
L_8
L_9
L_10
L_11 ,
V_15 , F_11 ( V_19 . V_20 ) ,
V_15 , F_11 ( V_19 . V_21 ) ,
V_15 , F_11 ( V_19 . V_20 - V_19 . V_21 ) ,
V_15 , F_11 ( F_12 ( V_17 , V_22 ) +
F_12 ( V_17 , V_23 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_24 ) +
F_12 ( V_17 , V_25 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_22 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_24 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_23 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_25 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_26 ) ) ,
V_15 , F_11 ( F_13 ( V_15 , V_27 ) ) ) ;
#ifdef F_14
V_14 += sprintf ( V_4 + V_14 ,
L_12
L_13
L_14
L_15 ,
V_15 , F_11 ( V_19 . V_28 ) ,
V_15 , F_11 ( V_19 . V_29 ) ,
V_15 , F_11 ( V_19 . V_20 - V_19 . V_28 ) ,
V_15 , F_11 ( V_19 . V_21 - V_19 . V_29 ) ) ;
#endif
V_14 += sprintf ( V_4 + V_14 ,
L_16
L_17
L_18
L_19
L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29
#ifdef F_15
L_30
L_31
L_32
#endif
,
V_15 , F_11 ( F_12 ( V_17 , V_30 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_31 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_32 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_33 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_34 ) ) ,
V_15 , F_11 ( V_19 . V_35 ) ,
V_15 , F_13 ( V_15 , V_36 ) ,
V_15 , F_11 ( F_13 ( V_15 , V_37 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_38 ) ) ,
V_15 , F_11 ( F_13 ( V_15 , V_39 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_40 ) ) ,
V_15 , F_11 ( F_13 ( V_15 , V_41 ) +
F_13 ( V_15 , V_42 ) ) ,
V_15 , F_11 ( F_13 ( V_15 , V_41 ) ) ,
#ifdef F_15
V_15 , F_11 ( F_13 ( V_15 , V_42 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_43 ) *
V_44 ) ,
V_15 , F_11 ( F_12 ( V_17 , V_45 ) *
V_44 ) ,
V_15 , F_11 ( F_12 ( V_17 , V_46 ) *
V_44 ) ) ;
#else
V_15 , F_11 ( F_13 ( V_15 , V_42 ) ) ) ;
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
return sprintf ( V_4 ,
L_33
L_34
L_35
L_36
L_37
L_38 ,
F_13 ( V_2 -> V_9 , V_47 ) ,
F_13 ( V_2 -> V_9 , V_48 ) ,
F_13 ( V_2 -> V_9 , V_49 ) ,
F_13 ( V_2 -> V_9 , V_50 ) ,
F_13 ( V_2 -> V_9 , V_51 ) ,
F_13 ( V_2 -> V_9 , V_52 ) ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
int V_15 = V_2 -> V_9 ;
struct V_16 * V_17 = F_9 ( V_15 ) ;
int V_19 ;
int V_14 = 0 ;
for ( V_19 = 0 ; V_19 < V_53 ; V_19 ++ )
V_14 += sprintf ( V_4 + V_14 , L_39 , V_54 [ V_19 ] ,
F_13 ( V_15 , V_19 ) ) ;
for ( V_19 = 0 ; V_19 < V_55 ; V_19 ++ )
V_14 += sprintf ( V_4 + V_14 , L_39 ,
V_54 [ V_19 + V_53 ] ,
F_12 ( V_17 , V_19 ) ) ;
return V_14 ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
int V_15 = V_2 -> V_9 ;
int V_56 = 0 ;
int V_19 ;
F_4 ( V_57 * 4 > V_11 ) ;
F_19 (i)
V_56 += sprintf ( V_4 + V_56 , L_40 , V_19 ? L_41 : L_42 , F_20 ( V_15 , V_19 ) ) ;
V_56 += sprintf ( V_4 + V_56 , L_43 ) ;
return V_56 ;
}
static inline bool F_21 ( struct V_5 * V_5 )
{
if ( V_58 &&
F_22 ( V_5 -> V_2 . V_9 , V_59 ) ) {
V_58 ( V_5 ) ;
return true ;
}
return false ;
}
static inline void F_23 ( struct V_5 * V_5 )
{
if ( V_60 )
V_60 ( V_5 ) ;
}
void F_24 ( T_2 V_61 ,
T_2 V_62 )
{
V_58 = V_61 ;
V_60 = V_62 ;
}
static inline void F_21 ( struct V_5 * V_5 ) {}
static inline void F_23 ( struct V_5 * V_5 ) {}
static void F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
#if F_26 ( V_63 ) && F_26 ( V_64 )
F_27 ( & V_5 -> V_65 ) ;
#endif
F_28 ( V_5 ) ;
}
static int F_29 ( struct V_5 * V_5 , int V_66 , struct V_5 * V_67 )
{
int error ;
V_5 -> V_2 . V_9 = V_66 ;
V_5 -> V_2 . V_68 = & V_69 ;
V_5 -> V_2 . V_70 = F_25 ;
V_5 -> V_2 . V_71 = V_72 ;
error = F_30 ( & V_5 -> V_2 ) ;
if ( ! error ) {
F_21 ( V_5 ) ;
F_31 ( V_5 ) ;
}
return error ;
}
void F_32 ( struct V_5 * V_5 )
{
F_23 ( V_5 ) ;
F_33 ( & V_5 -> V_2 ) ;
}
int F_34 ( unsigned int V_73 , unsigned int V_15 )
{
int V_74 ;
struct V_1 * V_75 ;
if ( ! F_35 ( V_15 ) )
return 0 ;
V_75 = F_36 ( V_73 ) ;
if ( ! V_75 )
return 0 ;
V_74 = F_37 ( & V_76 [ V_15 ] -> V_2 . V_77 ,
& V_75 -> V_77 ,
F_38 ( & V_75 -> V_77 ) ) ;
if ( V_74 )
return V_74 ;
return F_37 ( & V_75 -> V_77 ,
& V_76 [ V_15 ] -> V_2 . V_77 ,
F_38 ( & V_76 [ V_15 ] -> V_2 . V_77 ) ) ;
}
int F_39 ( unsigned int V_73 , unsigned int V_15 )
{
struct V_1 * V_75 ;
if ( ! F_35 ( V_15 ) )
return 0 ;
V_75 = F_36 ( V_73 ) ;
if ( ! V_75 )
return 0 ;
F_40 ( & V_76 [ V_15 ] -> V_2 . V_77 ,
F_38 ( & V_75 -> V_77 ) ) ;
F_40 ( & V_75 -> V_77 ,
F_38 ( & V_76 [ V_15 ] -> V_2 . V_77 ) ) ;
return 0 ;
}
static int T_3 F_41 ( unsigned long V_78 )
{
struct V_79 * V_79 ;
if ( ! F_42 ( V_78 ) )
return - 1 ;
#ifdef F_43
if ( V_80 == V_81 )
return F_44 ( V_78 ) ;
#endif
V_79 = F_45 ( V_78 ) ;
if ( ! F_46 ( V_79 ) )
return - 1 ;
return F_47 ( V_78 ) ;
}
int F_48 ( struct V_82 * V_83 , int V_15 )
{
int V_74 ;
unsigned long V_78 , V_84 , V_85 ;
if ( ! V_83 )
return - V_86 ;
if ( ! F_35 ( V_15 ) )
return 0 ;
V_84 = F_49 ( V_83 -> V_87 ) ;
V_85 = F_49 ( V_83 -> V_88 ) ;
V_85 += V_89 - 1 ;
for ( V_78 = V_84 ; V_78 <= V_85 ; V_78 ++ ) {
int V_90 ;
if ( ! F_50 ( V_78 ) ) {
V_78 = F_51 ( V_78 + V_89 ,
V_89 ) - 1 ;
continue;
}
V_90 = F_41 ( V_78 ) ;
if ( V_90 < 0 )
continue;
if ( V_90 != V_15 )
continue;
V_74 = F_52 ( & V_76 [ V_15 ] -> V_2 . V_77 ,
& V_83 -> V_2 . V_77 ,
F_38 ( & V_83 -> V_2 . V_77 ) ) ;
if ( V_74 )
return V_74 ;
return F_52 ( & V_83 -> V_2 . V_77 ,
& V_76 [ V_15 ] -> V_2 . V_77 ,
F_38 ( & V_76 [ V_15 ] -> V_2 . V_77 ) ) ;
}
return 0 ;
}
int F_53 ( struct V_82 * V_83 ,
unsigned long V_91 )
{
F_54 ( V_92 , V_93 , V_94 ) ;
unsigned long V_78 , V_84 , V_85 ;
if ( ! V_83 ) {
F_55 ( V_93 ) ;
return - V_86 ;
}
if ( ! V_93 )
return - V_95 ;
F_56 ( * V_93 ) ;
V_84 = F_49 ( V_91 ) ;
V_85 = V_84 + V_89 - 1 ;
for ( V_78 = V_84 ; V_78 <= V_85 ; V_78 ++ ) {
int V_15 ;
V_15 = F_41 ( V_78 ) ;
if ( V_15 < 0 )
continue;
if ( ! F_35 ( V_15 ) )
continue;
if ( F_57 ( V_15 , * V_93 ) )
continue;
F_40 ( & V_76 [ V_15 ] -> V_2 . V_77 ,
F_38 ( & V_83 -> V_2 . V_77 ) ) ;
F_40 ( & V_83 -> V_2 . V_77 ,
F_38 ( & V_76 [ V_15 ] -> V_2 . V_77 ) ) ;
}
F_55 ( V_93 ) ;
return 0 ;
}
static int F_58 ( int V_15 )
{
unsigned long V_96 = F_9 ( V_15 ) -> V_97 ;
unsigned long V_98 = V_96 + F_9 ( V_15 ) -> V_99 ;
unsigned long V_78 ;
struct V_82 * V_83 = NULL ;
int V_100 = 0 ;
for ( V_78 = V_96 ; V_78 < V_98 ; V_78 += V_89 ) {
unsigned long V_101 = F_59 ( V_78 ) ;
struct V_102 * V_103 ;
int V_74 ;
if ( ! F_60 ( V_101 ) )
continue;
V_103 = F_61 ( V_101 ) ;
if ( V_83 )
if ( ( V_101 >= V_83 -> V_87 ) &&
( V_101 <= V_83 -> V_88 ) )
continue;
V_83 = F_62 ( V_103 , V_83 ) ;
V_74 = F_48 ( V_83 , V_15 ) ;
if ( ! V_100 )
V_100 = V_74 ;
}
if ( V_83 )
F_63 ( & V_83 -> V_2 . V_77 ) ;
return V_100 ;
}
static void F_64 ( struct V_104 * V_105 )
{
struct V_5 * V_5 = F_65 ( V_105 , struct V_5 , V_65 ) ;
if ( ! F_21 ( V_5 ) )
F_23 ( V_5 ) ;
}
static void F_66 ( int V_15 )
{
F_67 ( & V_76 [ V_15 ] -> V_65 , F_64 ) ;
}
static int F_68 ( struct V_106 * V_107 ,
unsigned long V_108 , void * V_109 )
{
struct V_110 * V_111 = V_109 ;
int V_15 = V_111 -> V_112 ;
switch ( V_108 ) {
case V_113 :
case V_114 :
if ( V_15 != V_115 )
F_69 ( & V_76 [ V_15 ] -> V_65 ) ;
break;
case V_116 :
case V_117 :
case V_118 :
case V_119 :
default:
break;
}
return V_120 ;
}
static int F_58 ( int V_15 ) { return 0 ; }
static inline int F_68 ( struct V_106 * V_107 ,
unsigned long V_108 , void * V_109 )
{
return V_120 ;
}
static void F_66 ( int V_15 ) { }
int F_70 ( int V_15 )
{
int error = 0 ;
int V_73 ;
if ( F_35 ( V_15 ) ) {
int V_121 = F_71 ( V_15 ) ;
struct V_5 * V_67 = NULL ;
if ( V_121 != V_15 )
V_67 = V_76 [ V_121 ] ;
V_76 [ V_15 ] = F_72 ( sizeof( struct V_5 ) , V_94 ) ;
if ( ! V_76 [ V_15 ] )
return - V_95 ;
error = F_29 ( V_76 [ V_15 ] , V_15 , V_67 ) ;
F_73 (cpu) {
if ( F_74 ( V_73 ) == V_15 )
F_34 ( V_73 , V_15 ) ;
}
error = F_58 ( V_15 ) ;
F_66 ( V_15 ) ;
}
return error ;
}
void F_75 ( int V_15 )
{
if ( ! V_76 [ V_15 ] )
return;
F_32 ( V_76 [ V_15 ] ) ;
V_76 [ V_15 ] = NULL ;
}
static T_1 F_76 ( enum V_122 V_123 , char * V_4 )
{
int V_14 ;
V_14 = F_77 ( V_4 , V_11 - 1 , L_44 ,
F_78 ( & V_122 [ V_123 ] ) ) ;
V_4 [ V_14 ++ ] = '\n' ;
V_4 [ V_14 ] = '\0' ;
return V_14 ;
}
static T_1 F_79 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
struct V_124 * V_125 = F_65 ( V_13 , struct V_124 , V_13 ) ;
return F_76 ( V_125 -> V_123 , V_4 ) ;
}
static int T_4 F_80 ( void )
{
int V_74 ;
F_4 ( F_81 ( V_126 ) != V_127 ) ;
F_4 ( F_81 ( V_128 ) - 1 != V_127 ) ;
V_74 = F_82 ( & V_69 , V_129 ) ;
if ( ! V_74 ) {
static struct V_106 V_130 = {
. V_131 = F_68 ,
. V_132 = V_133 ,
} ;
F_83 ( & V_130 ) ;
}
return V_74 ;
}

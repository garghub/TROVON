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
struct V_16 V_17 ;
F_9 ( & V_17 , V_15 ) ;
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
V_15 , F_10 ( V_17 . V_18 ) ,
V_15 , F_10 ( V_17 . V_19 ) ,
V_15 , F_10 ( V_17 . V_18 - V_17 . V_19 ) ,
V_15 , F_10 ( F_11 ( V_15 , V_20 ) +
F_11 ( V_15 , V_21 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_22 ) +
F_11 ( V_15 , V_23 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_20 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_22 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_21 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_23 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_24 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_25 ) ) ) ;
#ifdef F_12
V_14 += sprintf ( V_4 + V_14 ,
L_12
L_13
L_14
L_15 ,
V_15 , F_10 ( V_17 . V_26 ) ,
V_15 , F_10 ( V_17 . V_27 ) ,
V_15 , F_10 ( V_17 . V_18 - V_17 . V_26 ) ,
V_15 , F_10 ( V_17 . V_19 - V_17 . V_27 ) ) ;
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
#ifdef F_13
L_30
#endif
,
V_15 , F_10 ( F_11 ( V_15 , V_28 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_29 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_30 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_31 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_32 ) ) ,
V_15 , F_10 ( V_17 . V_33 ) ,
V_15 , F_11 ( V_15 , V_34 ) *
V_35 / 1024 ,
V_15 , F_10 ( F_11 ( V_15 , V_36 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_37 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_38 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_39 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_40 ) +
F_11 ( V_15 , V_41 ) ) ,
V_15 , F_10 ( F_11 ( V_15 , V_40 ) ) ,
#ifdef F_13
V_15 , F_10 ( F_11 ( V_15 , V_41 ) )
, V_15 ,
F_10 ( F_11 ( V_15 , V_42 ) *
V_43 ) ) ;
#else
V_15 , F_10 ( F_11 ( V_15 , V_41 ) ) ) ;
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
return sprintf ( V_4 ,
L_31
L_32
L_33
L_34
L_35
L_36 ,
F_11 ( V_2 -> V_9 , V_44 ) ,
F_11 ( V_2 -> V_9 , V_45 ) ,
F_11 ( V_2 -> V_9 , V_46 ) ,
F_11 ( V_2 -> V_9 , V_47 ) ,
F_11 ( V_2 -> V_9 , V_48 ) ,
F_11 ( V_2 -> V_9 , V_49 ) ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
int V_15 = V_2 -> V_9 ;
int V_17 ;
int V_14 = 0 ;
for ( V_17 = 0 ; V_17 < V_50 ; V_17 ++ )
V_14 += sprintf ( V_4 + V_14 , L_37 , V_51 [ V_17 ] ,
F_11 ( V_15 , V_17 ) ) ;
return V_14 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
int V_15 = V_2 -> V_9 ;
int V_52 = 0 ;
int V_17 ;
F_4 ( V_53 * 4 > V_11 ) ;
F_17 (i)
V_52 += sprintf ( V_4 + V_52 , L_38 , V_17 ? L_39 : L_40 , F_18 ( V_15 , V_17 ) ) ;
V_52 += sprintf ( V_4 + V_52 , L_41 ) ;
return V_52 ;
}
static inline bool F_19 ( struct V_5 * V_5 )
{
if ( V_54 &&
F_20 ( V_5 -> V_2 . V_9 , V_55 ) ) {
V_54 ( V_5 ) ;
return true ;
}
return false ;
}
static inline void F_21 ( struct V_5 * V_5 )
{
if ( V_56 )
V_56 ( V_5 ) ;
}
void F_22 ( T_2 V_57 ,
T_2 V_58 )
{
V_54 = V_57 ;
V_56 = V_58 ;
}
static inline void F_19 ( struct V_5 * V_5 ) {}
static inline void F_21 ( struct V_5 * V_5 ) {}
static void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_5 = F_2 ( V_2 ) ;
#if F_24 ( V_59 ) && F_24 ( V_60 )
F_25 ( & V_5 -> V_61 ) ;
#endif
F_26 ( V_5 ) ;
}
static int F_27 ( struct V_5 * V_5 , int V_62 , struct V_5 * V_63 )
{
int error ;
V_5 -> V_2 . V_9 = V_62 ;
V_5 -> V_2 . V_64 = & V_65 ;
V_5 -> V_2 . V_66 = F_23 ;
error = F_28 ( & V_5 -> V_2 ) ;
if ( ! error ) {
F_29 ( & V_5 -> V_2 , & V_67 ) ;
F_29 ( & V_5 -> V_2 , & V_68 ) ;
F_29 ( & V_5 -> V_2 , & V_69 ) ;
F_29 ( & V_5 -> V_2 , & V_70 ) ;
F_29 ( & V_5 -> V_2 , & V_71 ) ;
F_29 ( & V_5 -> V_2 , & V_72 ) ;
F_19 ( V_5 ) ;
F_30 ( V_5 ) ;
}
return error ;
}
void F_31 ( struct V_5 * V_5 )
{
F_32 ( & V_5 -> V_2 , & V_67 ) ;
F_32 ( & V_5 -> V_2 , & V_68 ) ;
F_32 ( & V_5 -> V_2 , & V_69 ) ;
F_32 ( & V_5 -> V_2 , & V_70 ) ;
F_32 ( & V_5 -> V_2 , & V_71 ) ;
F_32 ( & V_5 -> V_2 , & V_72 ) ;
F_21 ( V_5 ) ;
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
static int F_41 ( unsigned long V_78 )
{
struct V_79 * V_79 ;
if ( ! F_42 ( V_78 ) )
return - 1 ;
V_79 = F_43 ( V_78 ) ;
if ( ! F_44 ( V_79 ) )
return - 1 ;
return F_45 ( V_78 ) ;
}
int F_46 ( struct V_80 * V_81 , int V_15 )
{
int V_74 ;
unsigned long V_78 , V_82 , V_83 ;
if ( ! V_81 )
return - V_84 ;
if ( ! F_35 ( V_15 ) )
return 0 ;
V_82 = F_47 ( V_81 -> V_85 ) ;
V_83 = F_47 ( V_81 -> V_86 ) ;
V_83 += V_87 - 1 ;
for ( V_78 = V_82 ; V_78 <= V_83 ; V_78 ++ ) {
int V_88 ;
V_88 = F_41 ( V_78 ) ;
if ( V_88 < 0 )
continue;
if ( V_88 != V_15 )
continue;
V_74 = F_48 ( & V_76 [ V_15 ] -> V_2 . V_77 ,
& V_81 -> V_2 . V_77 ,
F_38 ( & V_81 -> V_2 . V_77 ) ) ;
if ( V_74 )
return V_74 ;
return F_48 ( & V_81 -> V_2 . V_77 ,
& V_76 [ V_15 ] -> V_2 . V_77 ,
F_38 ( & V_76 [ V_15 ] -> V_2 . V_77 ) ) ;
}
return 0 ;
}
int F_49 ( struct V_80 * V_81 ,
unsigned long V_89 )
{
F_50 ( V_90 , V_91 , V_92 ) ;
unsigned long V_78 , V_82 , V_83 ;
if ( ! V_81 ) {
F_51 ( V_91 ) ;
return - V_84 ;
}
if ( ! V_91 )
return - V_93 ;
F_52 ( * V_91 ) ;
V_82 = F_47 ( V_89 ) ;
V_83 = V_82 + V_87 - 1 ;
for ( V_78 = V_82 ; V_78 <= V_83 ; V_78 ++ ) {
int V_15 ;
V_15 = F_41 ( V_78 ) ;
if ( V_15 < 0 )
continue;
if ( ! F_35 ( V_15 ) )
continue;
if ( F_53 ( V_15 , * V_91 ) )
continue;
F_40 ( & V_76 [ V_15 ] -> V_2 . V_77 ,
F_38 ( & V_81 -> V_2 . V_77 ) ) ;
F_40 ( & V_81 -> V_2 . V_77 ,
F_38 ( & V_76 [ V_15 ] -> V_2 . V_77 ) ) ;
}
F_51 ( V_91 ) ;
return 0 ;
}
static int F_54 ( int V_15 )
{
unsigned long V_94 = F_55 ( V_15 ) -> V_95 ;
unsigned long V_96 = V_94 + F_55 ( V_15 ) -> V_97 ;
unsigned long V_78 ;
struct V_80 * V_81 = NULL ;
int V_98 = 0 ;
for ( V_78 = V_94 ; V_78 < V_96 ; V_78 += V_87 ) {
unsigned long V_99 = F_56 ( V_78 ) ;
struct V_100 * V_101 ;
int V_74 ;
if ( ! F_57 ( V_99 ) )
continue;
V_101 = F_58 ( V_99 ) ;
if ( V_81 )
if ( ( V_99 >= V_81 -> V_85 ) &&
( V_99 <= V_81 -> V_86 ) )
continue;
V_81 = F_59 ( V_101 , V_81 ) ;
V_74 = F_46 ( V_81 , V_15 ) ;
if ( ! V_98 )
V_98 = V_74 ;
}
if ( V_81 )
F_60 ( & V_81 -> V_2 . V_77 ) ;
return V_98 ;
}
static void F_61 ( struct V_102 * V_103 )
{
struct V_5 * V_5 = F_62 ( V_103 , struct V_5 , V_61 ) ;
if ( ! F_19 ( V_5 ) )
F_21 ( V_5 ) ;
}
static void F_63 ( int V_15 )
{
F_64 ( & V_76 [ V_15 ] -> V_61 , F_61 ) ;
}
static int F_65 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
struct V_108 * V_109 = V_107 ;
int V_15 = V_109 -> V_110 ;
switch ( V_106 ) {
case V_111 :
case V_112 :
if ( V_15 != V_113 )
F_66 ( & V_76 [ V_15 ] -> V_61 ) ;
break;
case V_114 :
case V_115 :
case V_116 :
case V_117 :
default:
break;
}
return V_118 ;
}
static int F_54 ( int V_15 ) { return 0 ; }
static inline int F_65 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
return V_118 ;
}
static void F_63 ( int V_15 ) { }
int F_67 ( int V_15 )
{
int error = 0 ;
int V_73 ;
if ( F_35 ( V_15 ) ) {
int V_119 = F_68 ( V_15 ) ;
struct V_5 * V_63 = NULL ;
if ( V_119 != V_15 )
V_63 = V_76 [ V_119 ] ;
V_76 [ V_15 ] = F_69 ( sizeof( struct V_5 ) , V_92 ) ;
if ( ! V_76 [ V_15 ] )
return - V_93 ;
error = F_27 ( V_76 [ V_15 ] , V_15 , V_63 ) ;
F_70 (cpu) {
if ( F_71 ( V_73 ) == V_15 )
F_34 ( V_73 , V_15 ) ;
}
error = F_54 ( V_15 ) ;
F_63 ( V_15 ) ;
}
return error ;
}
void F_72 ( int V_15 )
{
if ( ! V_76 [ V_15 ] )
return;
F_31 ( V_76 [ V_15 ] ) ;
V_76 [ V_15 ] = NULL ;
}
static T_1 F_73 ( enum V_120 V_121 , char * V_4 )
{
int V_14 ;
V_14 = F_74 ( V_4 , V_11 - 1 , L_42 ,
F_75 ( & V_120 [ V_121 ] ) ) ;
V_4 [ V_14 ++ ] = '\n' ;
V_4 [ V_14 ] = '\0' ;
return V_14 ;
}
static T_1 F_76 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
struct V_122 * V_123 = F_62 ( V_13 , struct V_122 , V_13 ) ;
return F_73 ( V_123 -> V_121 , V_4 ) ;
}
static int T_3 F_77 ( void )
{
int V_74 ;
F_4 ( F_78 ( V_124 ) != V_125 ) ;
F_4 ( F_78 ( V_126 ) - 1 != V_125 ) ;
V_74 = F_79 ( & V_65 , V_127 ) ;
if ( ! V_74 ) {
static struct V_104 V_128 = {
. V_129 = F_65 ,
. V_130 = V_131 ,
} ;
F_80 ( & V_128 ) ;
}
return V_74 ;
}

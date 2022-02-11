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
V_5 -> V_2 . V_67 = V_68 ;
error = F_28 ( & V_5 -> V_2 ) ;
if ( ! error ) {
F_19 ( V_5 ) ;
F_29 ( V_5 ) ;
}
return error ;
}
void F_30 ( struct V_5 * V_5 )
{
F_21 ( V_5 ) ;
F_31 ( & V_5 -> V_2 ) ;
}
int F_32 ( unsigned int V_69 , unsigned int V_15 )
{
int V_70 ;
struct V_1 * V_71 ;
if ( ! F_33 ( V_15 ) )
return 0 ;
V_71 = F_34 ( V_69 ) ;
if ( ! V_71 )
return 0 ;
V_70 = F_35 ( & V_72 [ V_15 ] -> V_2 . V_73 ,
& V_71 -> V_73 ,
F_36 ( & V_71 -> V_73 ) ) ;
if ( V_70 )
return V_70 ;
return F_35 ( & V_71 -> V_73 ,
& V_72 [ V_15 ] -> V_2 . V_73 ,
F_36 ( & V_72 [ V_15 ] -> V_2 . V_73 ) ) ;
}
int F_37 ( unsigned int V_69 , unsigned int V_15 )
{
struct V_1 * V_71 ;
if ( ! F_33 ( V_15 ) )
return 0 ;
V_71 = F_34 ( V_69 ) ;
if ( ! V_71 )
return 0 ;
F_38 ( & V_72 [ V_15 ] -> V_2 . V_73 ,
F_36 ( & V_71 -> V_73 ) ) ;
F_38 ( & V_71 -> V_73 ,
F_36 ( & V_72 [ V_15 ] -> V_2 . V_73 ) ) ;
return 0 ;
}
static int T_3 F_39 ( unsigned long V_74 )
{
struct V_75 * V_75 ;
if ( ! F_40 ( V_74 ) )
return - 1 ;
#ifdef F_41
if ( V_76 == V_77 )
return F_42 ( V_74 ) ;
#endif
V_75 = F_43 ( V_74 ) ;
if ( ! F_44 ( V_75 ) )
return - 1 ;
return F_45 ( V_74 ) ;
}
int F_46 ( struct V_78 * V_79 , int V_15 )
{
int V_70 ;
unsigned long V_74 , V_80 , V_81 ;
if ( ! V_79 )
return - V_82 ;
if ( ! F_33 ( V_15 ) )
return 0 ;
V_80 = F_47 ( V_79 -> V_83 ) ;
V_81 = F_47 ( V_79 -> V_84 ) ;
V_81 += V_85 - 1 ;
for ( V_74 = V_80 ; V_74 <= V_81 ; V_74 ++ ) {
int V_86 ;
V_86 = F_39 ( V_74 ) ;
if ( V_86 < 0 )
continue;
if ( V_86 != V_15 )
continue;
V_70 = F_48 ( & V_72 [ V_15 ] -> V_2 . V_73 ,
& V_79 -> V_2 . V_73 ,
F_36 ( & V_79 -> V_2 . V_73 ) ) ;
if ( V_70 )
return V_70 ;
return F_48 ( & V_79 -> V_2 . V_73 ,
& V_72 [ V_15 ] -> V_2 . V_73 ,
F_36 ( & V_72 [ V_15 ] -> V_2 . V_73 ) ) ;
}
return 0 ;
}
int F_49 ( struct V_78 * V_79 ,
unsigned long V_87 )
{
F_50 ( V_88 , V_89 , V_90 ) ;
unsigned long V_74 , V_80 , V_81 ;
if ( ! V_79 ) {
F_51 ( V_89 ) ;
return - V_82 ;
}
if ( ! V_89 )
return - V_91 ;
F_52 ( * V_89 ) ;
V_80 = F_47 ( V_87 ) ;
V_81 = V_80 + V_85 - 1 ;
for ( V_74 = V_80 ; V_74 <= V_81 ; V_74 ++ ) {
int V_15 ;
V_15 = F_39 ( V_74 ) ;
if ( V_15 < 0 )
continue;
if ( ! F_33 ( V_15 ) )
continue;
if ( F_53 ( V_15 , * V_89 ) )
continue;
F_38 ( & V_72 [ V_15 ] -> V_2 . V_73 ,
F_36 ( & V_79 -> V_2 . V_73 ) ) ;
F_38 ( & V_79 -> V_2 . V_73 ,
F_36 ( & V_72 [ V_15 ] -> V_2 . V_73 ) ) ;
}
F_51 ( V_89 ) ;
return 0 ;
}
static int F_54 ( int V_15 )
{
unsigned long V_92 = F_55 ( V_15 ) -> V_93 ;
unsigned long V_94 = V_92 + F_55 ( V_15 ) -> V_95 ;
unsigned long V_74 ;
struct V_78 * V_79 = NULL ;
int V_96 = 0 ;
for ( V_74 = V_92 ; V_74 < V_94 ; V_74 += V_85 ) {
unsigned long V_97 = F_56 ( V_74 ) ;
struct V_98 * V_99 ;
int V_70 ;
if ( ! F_57 ( V_97 ) )
continue;
V_99 = F_58 ( V_97 ) ;
if ( V_79 )
if ( ( V_97 >= V_79 -> V_83 ) &&
( V_97 <= V_79 -> V_84 ) )
continue;
V_79 = F_59 ( V_99 , V_79 ) ;
V_70 = F_46 ( V_79 , V_15 ) ;
if ( ! V_96 )
V_96 = V_70 ;
}
if ( V_79 )
F_60 ( & V_79 -> V_2 . V_73 ) ;
return V_96 ;
}
static void F_61 ( struct V_100 * V_101 )
{
struct V_5 * V_5 = F_62 ( V_101 , struct V_5 , V_61 ) ;
if ( ! F_19 ( V_5 ) )
F_21 ( V_5 ) ;
}
static void F_63 ( int V_15 )
{
F_64 ( & V_72 [ V_15 ] -> V_61 , F_61 ) ;
}
static int F_65 ( struct V_102 * V_103 ,
unsigned long V_104 , void * V_105 )
{
struct V_106 * V_107 = V_105 ;
int V_15 = V_107 -> V_108 ;
switch ( V_104 ) {
case V_109 :
case V_110 :
if ( V_15 != V_111 )
F_66 ( & V_72 [ V_15 ] -> V_61 ) ;
break;
case V_112 :
case V_113 :
case V_114 :
case V_115 :
default:
break;
}
return V_116 ;
}
static int F_54 ( int V_15 ) { return 0 ; }
static inline int F_65 ( struct V_102 * V_103 ,
unsigned long V_104 , void * V_105 )
{
return V_116 ;
}
static void F_63 ( int V_15 ) { }
int F_67 ( int V_15 )
{
int error = 0 ;
int V_69 ;
if ( F_33 ( V_15 ) ) {
int V_117 = F_68 ( V_15 ) ;
struct V_5 * V_63 = NULL ;
if ( V_117 != V_15 )
V_63 = V_72 [ V_117 ] ;
V_72 [ V_15 ] = F_69 ( sizeof( struct V_5 ) , V_90 ) ;
if ( ! V_72 [ V_15 ] )
return - V_91 ;
error = F_27 ( V_72 [ V_15 ] , V_15 , V_63 ) ;
F_70 (cpu) {
if ( F_71 ( V_69 ) == V_15 )
F_32 ( V_69 , V_15 ) ;
}
error = F_54 ( V_15 ) ;
F_63 ( V_15 ) ;
}
return error ;
}
void F_72 ( int V_15 )
{
if ( ! V_72 [ V_15 ] )
return;
F_30 ( V_72 [ V_15 ] ) ;
V_72 [ V_15 ] = NULL ;
}
static T_1 F_73 ( enum V_118 V_119 , char * V_4 )
{
int V_14 ;
V_14 = F_74 ( V_4 , V_11 - 1 , L_42 ,
F_75 ( & V_118 [ V_119 ] ) ) ;
V_4 [ V_14 ++ ] = '\n' ;
V_4 [ V_14 ] = '\0' ;
return V_14 ;
}
static T_1 F_76 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
struct V_120 * V_121 = F_62 ( V_13 , struct V_120 , V_13 ) ;
return F_73 ( V_121 -> V_119 , V_4 ) ;
}
static int T_4 F_77 ( void )
{
int V_70 ;
F_4 ( F_78 ( V_122 ) != V_123 ) ;
F_4 ( F_78 ( V_124 ) - 1 != V_123 ) ;
V_70 = F_79 ( & V_65 , V_125 ) ;
if ( ! V_70 ) {
static struct V_102 V_126 = {
. V_127 = F_65 ,
. V_128 = V_129 ,
} ;
F_80 ( & V_126 ) ;
}
return V_70 ;
}

static T_1 F_1 ( struct V_1 * V_2 , int type , char * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 = F_3 ( V_5 -> V_2 . V_8 ) ;
int V_9 ;
F_4 ( ( V_10 / 32 * 9 ) > ( V_11 - 1 ) ) ;
V_9 = type ?
F_5 ( V_3 , V_11 - 2 , V_7 ) :
F_6 ( V_3 , V_11 - 2 , V_7 ) ;
V_3 [ V_9 ++ ] = '\n' ;
V_3 [ V_9 ] = '\0' ;
return V_9 ;
}
static inline T_1 F_7 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_3 )
{
return F_1 ( V_2 , 0 , V_3 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_3 )
{
return F_1 ( V_2 , 1 , V_3 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_3 )
{
int V_14 ;
int V_15 = V_2 -> V_8 ;
struct V_16 V_17 ;
F_10 ( & V_17 , V_15 ) ;
V_14 = sprintf ( V_3 ,
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
V_15 , F_11 ( V_17 . V_18 ) ,
V_15 , F_11 ( V_17 . V_19 ) ,
V_15 , F_11 ( V_17 . V_18 - V_17 . V_19 ) ,
V_15 , F_11 ( F_12 ( V_15 , V_20 ) +
F_12 ( V_15 , V_21 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_22 ) +
F_12 ( V_15 , V_23 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_20 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_22 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_21 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_23 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_24 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_25 ) ) ) ;
#ifdef F_13
V_14 += sprintf ( V_3 + V_14 ,
L_12
L_13
L_14
L_15 ,
V_15 , F_11 ( V_17 . V_26 ) ,
V_15 , F_11 ( V_17 . V_27 ) ,
V_15 , F_11 ( V_17 . V_18 - V_17 . V_26 ) ,
V_15 , F_11 ( V_17 . V_19 - V_17 . V_27 ) ) ;
#endif
V_14 += sprintf ( V_3 + V_14 ,
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
#ifdef F_14
L_30
#endif
,
V_15 , F_11 ( F_12 ( V_15 , V_28 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_29 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_30 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_31 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_32 ) ) ,
V_15 , F_11 ( V_17 . V_33 ) ,
V_15 , F_12 ( V_15 , V_34 ) *
V_35 / 1024 ,
V_15 , F_11 ( F_12 ( V_15 , V_36 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_37 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_38 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_39 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_40 ) +
F_12 ( V_15 , V_41 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_40 ) ) ,
#ifdef F_14
V_15 , F_11 ( F_12 ( V_15 , V_41 ) )
, V_15 ,
F_11 ( F_12 ( V_15 , V_42 ) *
V_43 ) ) ;
#else
V_15 , F_11 ( F_12 ( V_15 , V_41 ) ) ) ;
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_3 )
{
return sprintf ( V_3 ,
L_31
L_32
L_33
L_34
L_35
L_36 ,
F_12 ( V_2 -> V_8 , V_44 ) ,
F_12 ( V_2 -> V_8 , V_45 ) ,
F_12 ( V_2 -> V_8 , V_46 ) ,
F_12 ( V_2 -> V_8 , V_47 ) ,
F_12 ( V_2 -> V_8 , V_48 ) ,
F_12 ( V_2 -> V_8 , V_49 ) ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_3 )
{
int V_15 = V_2 -> V_8 ;
int V_17 ;
int V_14 = 0 ;
for ( V_17 = 0 ; V_17 < V_50 ; V_17 ++ )
V_14 += sprintf ( V_3 + V_14 , L_37 , V_51 [ V_17 ] ,
F_12 ( V_15 , V_17 ) ) ;
return V_14 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_3 )
{
int V_15 = V_2 -> V_8 ;
int V_9 = 0 ;
int V_17 ;
F_4 ( V_52 * 4 > V_11 ) ;
F_18 (i)
V_9 += sprintf ( V_3 + V_9 , L_38 , V_17 ? L_39 : L_40 , F_19 ( V_15 , V_17 ) ) ;
V_9 += sprintf ( V_3 + V_9 , L_41 ) ;
return V_9 ;
}
static inline bool F_20 ( struct V_4 * V_4 )
{
if ( V_53 &&
F_21 ( V_4 -> V_2 . V_8 , V_54 ) ) {
V_53 ( V_4 ) ;
return true ;
}
return false ;
}
static inline void F_22 ( struct V_4 * V_4 )
{
if ( V_55 )
V_55 ( V_4 ) ;
}
void F_23 ( T_2 V_56 ,
T_2 V_57 )
{
V_53 = V_56 ;
V_55 = V_57 ;
}
static inline void F_20 ( struct V_4 * V_4 ) {}
static inline void F_22 ( struct V_4 * V_4 ) {}
static void F_24 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
#if F_25 ( V_58 ) && F_25 ( V_59 )
F_26 ( & V_4 -> V_60 ) ;
#endif
F_27 ( V_4 ) ;
}
static int F_28 ( struct V_4 * V_4 , int V_61 , struct V_4 * V_62 )
{
int error ;
V_4 -> V_2 . V_8 = V_61 ;
V_4 -> V_2 . V_63 = & V_64 ;
V_4 -> V_2 . V_65 = F_24 ;
error = F_29 ( & V_4 -> V_2 ) ;
if ( ! error ) {
F_30 ( & V_4 -> V_2 , & V_66 ) ;
F_30 ( & V_4 -> V_2 , & V_67 ) ;
F_30 ( & V_4 -> V_2 , & V_68 ) ;
F_30 ( & V_4 -> V_2 , & V_69 ) ;
F_30 ( & V_4 -> V_2 , & V_70 ) ;
F_30 ( & V_4 -> V_2 , & V_71 ) ;
F_20 ( V_4 ) ;
F_31 ( V_4 ) ;
}
return error ;
}
void F_32 ( struct V_4 * V_4 )
{
F_33 ( & V_4 -> V_2 , & V_66 ) ;
F_33 ( & V_4 -> V_2 , & V_67 ) ;
F_33 ( & V_4 -> V_2 , & V_68 ) ;
F_33 ( & V_4 -> V_2 , & V_69 ) ;
F_33 ( & V_4 -> V_2 , & V_70 ) ;
F_33 ( & V_4 -> V_2 , & V_71 ) ;
F_22 ( V_4 ) ;
F_34 ( & V_4 -> V_2 ) ;
}
int F_35 ( unsigned int V_72 , unsigned int V_15 )
{
int V_73 ;
struct V_1 * V_74 ;
if ( ! F_36 ( V_15 ) )
return 0 ;
V_74 = F_37 ( V_72 ) ;
if ( ! V_74 )
return 0 ;
V_73 = F_38 ( & V_75 [ V_15 ] -> V_2 . V_76 ,
& V_74 -> V_76 ,
F_39 ( & V_74 -> V_76 ) ) ;
if ( V_73 )
return V_73 ;
return F_38 ( & V_74 -> V_76 ,
& V_75 [ V_15 ] -> V_2 . V_76 ,
F_39 ( & V_75 [ V_15 ] -> V_2 . V_76 ) ) ;
}
int F_40 ( unsigned int V_72 , unsigned int V_15 )
{
struct V_1 * V_74 ;
if ( ! F_36 ( V_15 ) )
return 0 ;
V_74 = F_37 ( V_72 ) ;
if ( ! V_74 )
return 0 ;
F_41 ( & V_75 [ V_15 ] -> V_2 . V_76 ,
F_39 ( & V_74 -> V_76 ) ) ;
F_41 ( & V_74 -> V_76 ,
F_39 ( & V_75 [ V_15 ] -> V_2 . V_76 ) ) ;
return 0 ;
}
static int F_42 ( unsigned long V_77 )
{
struct V_78 * V_78 ;
if ( ! F_43 ( V_77 ) )
return - 1 ;
V_78 = F_44 ( V_77 ) ;
if ( ! F_45 ( V_78 ) )
return - 1 ;
return F_46 ( V_77 ) ;
}
int F_47 ( struct V_79 * V_80 , int V_15 )
{
int V_73 ;
unsigned long V_77 , V_81 , V_82 ;
if ( ! V_80 )
return - V_83 ;
if ( ! F_36 ( V_15 ) )
return 0 ;
V_81 = F_48 ( V_80 -> V_84 ) ;
V_82 = F_48 ( V_80 -> V_85 ) ;
V_82 += V_86 - 1 ;
for ( V_77 = V_81 ; V_77 <= V_82 ; V_77 ++ ) {
int V_87 ;
V_87 = F_42 ( V_77 ) ;
if ( V_87 < 0 )
continue;
if ( V_87 != V_15 )
continue;
V_73 = F_49 ( & V_75 [ V_15 ] -> V_2 . V_76 ,
& V_80 -> V_2 . V_76 ,
F_39 ( & V_80 -> V_2 . V_76 ) ) ;
if ( V_73 )
return V_73 ;
return F_49 ( & V_80 -> V_2 . V_76 ,
& V_75 [ V_15 ] -> V_2 . V_76 ,
F_39 ( & V_75 [ V_15 ] -> V_2 . V_76 ) ) ;
}
return 0 ;
}
int F_50 ( struct V_79 * V_80 ,
unsigned long V_88 )
{
F_51 ( V_89 , V_90 , V_91 ) ;
unsigned long V_77 , V_81 , V_82 ;
if ( ! V_80 ) {
F_52 ( V_90 ) ;
return - V_83 ;
}
if ( ! V_90 )
return - V_92 ;
F_53 ( * V_90 ) ;
V_81 = F_48 ( V_88 ) ;
V_82 = V_81 + V_86 - 1 ;
for ( V_77 = V_81 ; V_77 <= V_82 ; V_77 ++ ) {
int V_15 ;
V_15 = F_42 ( V_77 ) ;
if ( V_15 < 0 )
continue;
if ( ! F_36 ( V_15 ) )
continue;
if ( F_54 ( V_15 , * V_90 ) )
continue;
F_41 ( & V_75 [ V_15 ] -> V_2 . V_76 ,
F_39 ( & V_80 -> V_2 . V_76 ) ) ;
F_41 ( & V_80 -> V_2 . V_76 ,
F_39 ( & V_75 [ V_15 ] -> V_2 . V_76 ) ) ;
}
F_52 ( V_90 ) ;
return 0 ;
}
static int F_55 ( int V_15 )
{
unsigned long V_93 = F_56 ( V_15 ) -> V_94 ;
unsigned long V_95 = V_93 + F_56 ( V_15 ) -> V_96 ;
unsigned long V_77 ;
struct V_79 * V_80 = NULL ;
int V_97 = 0 ;
for ( V_77 = V_93 ; V_77 < V_95 ; V_77 += V_86 ) {
unsigned long V_98 = F_57 ( V_77 ) ;
struct V_99 * V_100 ;
int V_73 ;
if ( ! F_58 ( V_98 ) )
continue;
V_100 = F_59 ( V_98 ) ;
if ( V_80 )
if ( ( V_98 >= V_80 -> V_84 ) &&
( V_98 <= V_80 -> V_85 ) )
continue;
V_80 = F_60 ( V_100 , V_80 ) ;
V_73 = F_47 ( V_80 , V_15 ) ;
if ( ! V_97 )
V_97 = V_73 ;
}
if ( V_80 )
F_61 ( & V_80 -> V_2 . V_76 ) ;
return V_97 ;
}
static void F_62 ( struct V_101 * V_102 )
{
struct V_4 * V_4 = F_63 ( V_102 , struct V_4 , V_60 ) ;
if ( ! F_20 ( V_4 ) )
F_22 ( V_4 ) ;
}
static void F_64 ( int V_15 )
{
F_65 ( & V_75 [ V_15 ] -> V_60 , F_62 ) ;
}
static int F_66 ( struct V_103 * V_104 ,
unsigned long V_105 , void * V_106 )
{
struct V_107 * V_108 = V_106 ;
int V_15 = V_108 -> V_109 ;
switch ( V_105 ) {
case V_110 :
case V_111 :
if ( V_15 != V_112 )
F_67 ( & V_75 [ V_15 ] -> V_60 ) ;
break;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
default:
break;
}
return V_117 ;
}
static int F_55 ( int V_15 ) { return 0 ; }
static inline int F_66 ( struct V_103 * V_104 ,
unsigned long V_105 , void * V_106 )
{
return V_117 ;
}
static void F_64 ( int V_15 ) { }
int F_68 ( int V_15 )
{
int error = 0 ;
int V_72 ;
if ( F_36 ( V_15 ) ) {
int V_118 = F_69 ( V_15 ) ;
struct V_4 * V_62 = NULL ;
if ( V_118 != V_15 )
V_62 = V_75 [ V_118 ] ;
V_75 [ V_15 ] = F_70 ( sizeof( struct V_4 ) , V_91 ) ;
if ( ! V_75 [ V_15 ] )
return - V_92 ;
error = F_28 ( V_75 [ V_15 ] , V_15 , V_62 ) ;
F_71 (cpu) {
if ( F_72 ( V_72 ) == V_15 )
F_35 ( V_72 , V_15 ) ;
}
error = F_55 ( V_15 ) ;
F_64 ( V_15 ) ;
}
return error ;
}
void F_73 ( int V_15 )
{
if ( ! V_75 [ V_15 ] )
return;
F_32 ( V_75 [ V_15 ] ) ;
V_75 [ V_15 ] = NULL ;
}
static T_1 F_74 ( enum V_119 V_120 , char * V_3 )
{
int V_14 ;
V_14 = F_75 ( V_3 , V_11 - 2 , V_119 [ V_120 ] ) ;
V_3 [ V_14 ++ ] = '\n' ;
V_3 [ V_14 ] = '\0' ;
return V_14 ;
}
static T_1 F_76 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_3 )
{
struct V_121 * V_122 = F_63 ( V_13 , struct V_121 , V_13 ) ;
return F_74 ( V_122 -> V_120 , V_3 ) ;
}
static int T_3 F_77 ( void )
{
int V_73 ;
F_4 ( F_78 ( V_123 ) != V_124 ) ;
F_4 ( F_78 ( V_125 ) - 1 != V_124 ) ;
V_73 = F_79 ( & V_64 , V_126 ) ;
if ( ! V_73 ) {
static struct V_103 V_127 = {
. V_128 = F_66 ,
. V_129 = V_130 ,
} ;
F_80 ( & V_127 ) ;
}
return V_73 ;
}

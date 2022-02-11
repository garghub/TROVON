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
#ifdef F_14
V_15 , F_11 ( F_12 ( V_15 , V_32 )
+ F_12 ( V_15 , V_33 ) *
V_34 ) ,
#else
V_15 , F_11 ( F_12 ( V_15 , V_32 ) ) ,
#endif
V_15 , F_11 ( F_12 ( V_15 , V_35 ) ) ,
V_15 , F_12 ( V_15 , V_36 ) *
V_37 / 1024 ,
V_15 , F_11 ( F_12 ( V_15 , V_38 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_39 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_40 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_41 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_42 ) +
F_12 ( V_15 , V_43 ) ) ,
V_15 , F_11 ( F_12 ( V_15 , V_42 ) ) ,
#ifdef F_14
V_15 , F_11 ( F_12 ( V_15 , V_43 ) )
, V_15 ,
F_11 ( F_12 ( V_15 , V_33 ) *
V_34 ) ) ;
#else
V_15 , F_11 ( F_12 ( V_15 , V_43 ) ) ) ;
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
int F_24 ( struct V_4 * V_4 , int V_58 , struct V_4 * V_59 )
{
int error ;
V_4 -> V_2 . V_8 = V_58 ;
V_4 -> V_2 . V_60 = & V_61 ;
error = F_25 ( & V_4 -> V_2 ) ;
if ( ! error ) {
F_26 ( & V_4 -> V_2 , & V_62 ) ;
F_26 ( & V_4 -> V_2 , & V_63 ) ;
F_26 ( & V_4 -> V_2 , & V_64 ) ;
F_26 ( & V_4 -> V_2 , & V_65 ) ;
F_26 ( & V_4 -> V_2 , & V_66 ) ;
F_26 ( & V_4 -> V_2 , & V_67 ) ;
F_27 ( V_4 ) ;
F_20 ( V_4 ) ;
F_28 ( V_4 ) ;
}
return error ;
}
void F_29 ( struct V_4 * V_4 )
{
F_30 ( & V_4 -> V_2 , & V_62 ) ;
F_30 ( & V_4 -> V_2 , & V_63 ) ;
F_30 ( & V_4 -> V_2 , & V_64 ) ;
F_30 ( & V_4 -> V_2 , & V_65 ) ;
F_30 ( & V_4 -> V_2 , & V_66 ) ;
F_30 ( & V_4 -> V_2 , & V_67 ) ;
F_31 ( V_4 ) ;
F_22 ( V_4 ) ;
F_32 ( & V_4 -> V_2 ) ;
}
int F_33 ( unsigned int V_68 , unsigned int V_15 )
{
int V_69 ;
struct V_1 * V_70 ;
if ( ! F_34 ( V_15 ) )
return 0 ;
V_70 = F_35 ( V_68 ) ;
if ( ! V_70 )
return 0 ;
V_69 = F_36 ( & V_71 [ V_15 ] . V_2 . V_72 ,
& V_70 -> V_72 ,
F_37 ( & V_70 -> V_72 ) ) ;
if ( V_69 )
return V_69 ;
return F_36 ( & V_70 -> V_72 ,
& V_71 [ V_15 ] . V_2 . V_72 ,
F_37 ( & V_71 [ V_15 ] . V_2 . V_72 ) ) ;
}
int F_38 ( unsigned int V_68 , unsigned int V_15 )
{
struct V_1 * V_70 ;
if ( ! F_34 ( V_15 ) )
return 0 ;
V_70 = F_35 ( V_68 ) ;
if ( ! V_70 )
return 0 ;
F_39 ( & V_71 [ V_15 ] . V_2 . V_72 ,
F_37 ( & V_70 -> V_72 ) ) ;
F_39 ( & V_70 -> V_72 ,
F_37 ( & V_71 [ V_15 ] . V_2 . V_72 ) ) ;
return 0 ;
}
static int F_40 ( unsigned long V_73 )
{
struct V_74 * V_74 ;
if ( ! F_41 ( V_73 ) )
return - 1 ;
V_74 = F_42 ( V_73 ) ;
if ( ! F_43 ( V_74 ) )
return - 1 ;
return F_44 ( V_73 ) ;
}
int F_45 ( struct V_75 * V_76 , int V_15 )
{
int V_69 ;
unsigned long V_73 , V_77 , V_78 ;
if ( ! V_76 )
return - V_79 ;
if ( ! F_34 ( V_15 ) )
return 0 ;
V_77 = F_46 ( V_76 -> V_80 ) ;
V_78 = F_46 ( V_76 -> V_81 ) ;
V_78 += V_82 - 1 ;
for ( V_73 = V_77 ; V_73 <= V_78 ; V_73 ++ ) {
int V_83 ;
V_83 = F_40 ( V_73 ) ;
if ( V_83 < 0 )
continue;
if ( V_83 != V_15 )
continue;
V_69 = F_47 ( & V_71 [ V_15 ] . V_2 . V_72 ,
& V_76 -> V_2 . V_72 ,
F_37 ( & V_76 -> V_2 . V_72 ) ) ;
if ( V_69 )
return V_69 ;
return F_47 ( & V_76 -> V_2 . V_72 ,
& V_71 [ V_15 ] . V_2 . V_72 ,
F_37 ( & V_71 [ V_15 ] . V_2 . V_72 ) ) ;
}
return 0 ;
}
int F_48 ( struct V_75 * V_76 ,
unsigned long V_84 )
{
F_49 ( V_85 , V_86 , V_87 ) ;
unsigned long V_73 , V_77 , V_78 ;
if ( ! V_76 ) {
F_50 ( V_86 ) ;
return - V_79 ;
}
if ( ! V_86 )
return - V_88 ;
F_51 ( * V_86 ) ;
V_77 = F_46 ( V_84 ) ;
V_78 = V_77 + V_82 - 1 ;
for ( V_73 = V_77 ; V_73 <= V_78 ; V_73 ++ ) {
int V_15 ;
V_15 = F_40 ( V_73 ) ;
if ( V_15 < 0 )
continue;
if ( ! F_34 ( V_15 ) )
continue;
if ( F_52 ( V_15 , * V_86 ) )
continue;
F_39 ( & V_71 [ V_15 ] . V_2 . V_72 ,
F_37 ( & V_76 -> V_2 . V_72 ) ) ;
F_39 ( & V_76 -> V_2 . V_72 ,
F_37 ( & V_71 [ V_15 ] . V_2 . V_72 ) ) ;
}
F_50 ( V_86 ) ;
return 0 ;
}
static int F_53 ( int V_15 )
{
unsigned long V_89 = F_54 ( V_15 ) -> V_90 ;
unsigned long V_91 = V_89 + F_54 ( V_15 ) -> V_92 ;
unsigned long V_73 ;
struct V_75 * V_76 = NULL ;
int V_93 = 0 ;
for ( V_73 = V_89 ; V_73 < V_91 ; V_73 += V_82 ) {
unsigned long V_94 = F_55 ( V_73 ) ;
struct V_95 * V_96 ;
int V_69 ;
if ( ! F_56 ( V_94 ) )
continue;
V_96 = F_57 ( V_94 ) ;
if ( V_76 )
if ( ( V_94 >= V_76 -> V_80 ) &&
( V_94 <= V_76 -> V_81 ) )
continue;
V_76 = F_58 ( V_96 , V_76 ) ;
V_69 = F_45 ( V_76 , V_15 ) ;
if ( ! V_93 )
V_93 = V_69 ;
}
if ( V_76 )
F_59 ( & V_76 -> V_2 . V_72 ) ;
return V_93 ;
}
static void F_60 ( struct V_97 * V_98 )
{
struct V_4 * V_4 = F_61 ( V_98 , struct V_4 , V_99 ) ;
if ( ! F_20 ( V_4 ) )
F_22 ( V_4 ) ;
}
static void F_62 ( int V_15 )
{
F_63 ( & V_71 [ V_15 ] . V_99 , F_60 ) ;
}
static int F_64 ( struct V_100 * V_101 ,
unsigned long V_102 , void * V_103 )
{
struct V_104 * V_105 = V_103 ;
int V_15 = V_105 -> V_106 ;
switch ( V_102 ) {
case V_107 :
case V_108 :
if ( V_15 != V_109 )
F_65 ( & V_71 [ V_15 ] . V_99 ) ;
break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
default:
break;
}
return V_114 ;
}
static int F_53 ( int V_15 ) { return 0 ; }
static inline int F_64 ( struct V_100 * V_101 ,
unsigned long V_102 , void * V_103 )
{
return V_114 ;
}
static void F_62 ( int V_15 ) { }
int F_66 ( int V_15 )
{
int error = 0 ;
int V_68 ;
if ( F_34 ( V_15 ) ) {
int V_115 = F_67 ( V_15 ) ;
struct V_4 * V_59 = NULL ;
if ( V_115 != V_15 )
V_59 = & V_71 [ V_115 ] ;
error = F_24 ( & V_71 [ V_15 ] , V_15 , V_59 ) ;
F_68 (cpu) {
if ( F_69 ( V_68 ) == V_15 )
F_33 ( V_68 , V_15 ) ;
}
error = F_53 ( V_15 ) ;
F_62 ( V_15 ) ;
}
return error ;
}
void F_70 ( int V_15 )
{
F_29 ( & V_71 [ V_15 ] ) ;
}
static T_1 F_71 ( enum V_116 V_117 , char * V_3 )
{
int V_14 ;
V_14 = F_72 ( V_3 , V_11 - 2 , V_116 [ V_117 ] ) ;
V_3 [ V_14 ++ ] = '\n' ;
V_3 [ V_14 ] = '\0' ;
return V_14 ;
}
static T_1 F_73 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_3 )
{
struct V_118 * V_119 = F_61 ( V_13 , struct V_118 , V_13 ) ;
return F_71 ( V_119 -> V_117 , V_3 ) ;
}
static int T_3 F_74 ( void )
{
int V_69 ;
F_4 ( F_75 ( V_120 ) != V_121 ) ;
F_4 ( F_75 ( V_122 ) - 1 != V_121 ) ;
V_69 = F_76 ( & V_61 , V_123 ) ;
if ( ! V_69 ) {
F_77 ( F_64 ,
V_124 ) ;
}
return V_69 ;
}

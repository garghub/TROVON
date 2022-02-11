static T_1 F_1 ( struct V_1 * V_2 , int type , char * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
const struct V_6 * V_7 = F_3 ( V_5 -> V_8 . V_9 ) ;
int V_10 ;
F_4 ( ( V_11 / 32 * 9 ) > ( V_12 - 1 ) ) ;
V_10 = type ?
F_5 ( V_3 , V_12 - 2 , V_7 ) :
F_6 ( V_3 , V_12 - 2 , V_7 ) ;
V_3 [ V_10 ++ ] = '\n' ;
V_3 [ V_10 ] = '\0' ;
return V_10 ;
}
static inline T_1 F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 , char * V_3 )
{
return F_1 ( V_2 , 0 , V_3 ) ;
}
static inline T_1 F_8 ( struct V_1 * V_2 ,
struct V_13 * V_14 , char * V_3 )
{
return F_1 ( V_2 , 1 , V_3 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_13 * V_14 , char * V_3 )
{
int V_15 ;
int V_16 = V_2 -> V_9 ;
struct V_17 V_18 ;
F_10 ( & V_18 , V_16 ) ;
V_15 = sprintf ( V_3 ,
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
V_16 , F_11 ( V_18 . V_19 ) ,
V_16 , F_11 ( V_18 . V_20 ) ,
V_16 , F_11 ( V_18 . V_19 - V_18 . V_20 ) ,
V_16 , F_11 ( F_12 ( V_16 , V_21 ) +
F_12 ( V_16 , V_22 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_23 ) +
F_12 ( V_16 , V_24 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_21 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_23 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_22 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_24 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_25 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_26 ) ) ) ;
#ifdef F_13
V_15 += sprintf ( V_3 + V_15 ,
L_12
L_13
L_14
L_15 ,
V_16 , F_11 ( V_18 . V_27 ) ,
V_16 , F_11 ( V_18 . V_28 ) ,
V_16 , F_11 ( V_18 . V_19 - V_18 . V_27 ) ,
V_16 , F_11 ( V_18 . V_20 - V_18 . V_28 ) ) ;
#endif
V_15 += sprintf ( V_3 + V_15 ,
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
V_16 , F_11 ( F_12 ( V_16 , V_29 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_30 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_31 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_32 ) ) ,
#ifdef F_14
V_16 , F_11 ( F_12 ( V_16 , V_33 )
+ F_12 ( V_16 , V_34 ) *
V_35 ) ,
#else
V_16 , F_11 ( F_12 ( V_16 , V_33 ) ) ,
#endif
V_16 , F_11 ( F_12 ( V_16 , V_36 ) ) ,
V_16 , F_12 ( V_16 , V_37 ) *
V_38 / 1024 ,
V_16 , F_11 ( F_12 ( V_16 , V_39 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_40 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_41 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_42 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_43 ) +
F_12 ( V_16 , V_44 ) ) ,
V_16 , F_11 ( F_12 ( V_16 , V_43 ) ) ,
#ifdef F_14
V_16 , F_11 ( F_12 ( V_16 , V_44 ) )
, V_16 ,
F_11 ( F_12 ( V_16 , V_34 ) *
V_35 ) ) ;
#else
V_16 , F_11 ( F_12 ( V_16 , V_44 ) ) ) ;
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_13 * V_14 , char * V_3 )
{
return sprintf ( V_3 ,
L_31
L_32
L_33
L_34
L_35
L_36 ,
F_12 ( V_2 -> V_9 , V_45 ) ,
F_12 ( V_2 -> V_9 , V_46 ) ,
F_12 ( V_2 -> V_9 , V_47 ) ,
F_12 ( V_2 -> V_9 , V_48 ) ,
F_12 ( V_2 -> V_9 , V_49 ) ,
F_12 ( V_2 -> V_9 , V_50 ) ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_13 * V_14 , char * V_3 )
{
int V_16 = V_2 -> V_9 ;
int V_18 ;
int V_15 = 0 ;
for ( V_18 = 0 ; V_18 < V_51 ; V_18 ++ )
V_15 += sprintf ( V_3 + V_15 , L_37 , V_52 [ V_18 ] ,
F_12 ( V_16 , V_18 ) ) ;
return V_15 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_13 * V_14 , char * V_3 )
{
int V_16 = V_2 -> V_9 ;
int V_10 = 0 ;
int V_18 ;
F_4 ( V_53 * 4 > V_12 ) ;
F_18 (i)
V_10 += sprintf ( V_3 + V_10 , L_38 , V_18 ? L_39 : L_40 , F_19 ( V_16 , V_18 ) ) ;
V_10 += sprintf ( V_3 + V_10 , L_41 ) ;
return V_10 ;
}
static inline bool F_20 ( struct V_4 * V_4 )
{
if ( V_54 &&
F_21 ( V_4 -> V_8 . V_9 , V_55 ) ) {
V_54 ( V_4 ) ;
return true ;
}
return false ;
}
static inline void F_22 ( struct V_4 * V_4 )
{
if ( V_56 )
V_56 ( V_4 ) ;
}
void F_23 ( T_2 V_57 ,
T_2 V_58 )
{
V_54 = V_57 ;
V_56 = V_58 ;
}
static inline void F_20 ( struct V_4 * V_4 ) {}
static inline void F_22 ( struct V_4 * V_4 ) {}
int F_24 ( struct V_4 * V_4 , int V_59 , struct V_4 * V_60 )
{
int error ;
V_4 -> V_8 . V_9 = V_59 ;
V_4 -> V_8 . V_61 = & V_62 ;
error = F_25 ( & V_4 -> V_8 ) ;
if ( ! error ) {
F_26 ( & V_4 -> V_8 , & V_63 ) ;
F_26 ( & V_4 -> V_8 , & V_64 ) ;
F_26 ( & V_4 -> V_8 , & V_65 ) ;
F_26 ( & V_4 -> V_8 , & V_66 ) ;
F_26 ( & V_4 -> V_8 , & V_67 ) ;
F_26 ( & V_4 -> V_8 , & V_68 ) ;
F_27 ( V_4 ) ;
F_20 ( V_4 ) ;
F_28 ( V_4 ) ;
}
return error ;
}
void F_29 ( struct V_4 * V_4 )
{
F_30 ( & V_4 -> V_8 , & V_63 ) ;
F_30 ( & V_4 -> V_8 , & V_64 ) ;
F_30 ( & V_4 -> V_8 , & V_65 ) ;
F_30 ( & V_4 -> V_8 , & V_66 ) ;
F_30 ( & V_4 -> V_8 , & V_67 ) ;
F_30 ( & V_4 -> V_8 , & V_68 ) ;
F_31 ( V_4 ) ;
F_22 ( V_4 ) ;
F_32 ( & V_4 -> V_8 ) ;
}
int F_33 ( unsigned int V_69 , unsigned int V_16 )
{
int V_70 ;
struct V_1 * V_71 ;
if ( ! F_34 ( V_16 ) )
return 0 ;
V_71 = F_35 ( V_69 ) ;
if ( ! V_71 )
return 0 ;
V_70 = F_36 ( & V_72 [ V_16 ] . V_8 . V_73 ,
& V_71 -> V_73 ,
F_37 ( & V_71 -> V_73 ) ) ;
if ( V_70 )
return V_70 ;
return F_36 ( & V_71 -> V_73 ,
& V_72 [ V_16 ] . V_8 . V_73 ,
F_37 ( & V_72 [ V_16 ] . V_8 . V_73 ) ) ;
}
int F_38 ( unsigned int V_69 , unsigned int V_16 )
{
struct V_1 * V_71 ;
if ( ! F_34 ( V_16 ) )
return 0 ;
V_71 = F_35 ( V_69 ) ;
if ( ! V_71 )
return 0 ;
F_39 ( & V_72 [ V_16 ] . V_8 . V_73 ,
F_37 ( & V_71 -> V_73 ) ) ;
F_39 ( & V_71 -> V_73 ,
F_37 ( & V_72 [ V_16 ] . V_8 . V_73 ) ) ;
return 0 ;
}
static int F_40 ( unsigned long V_74 )
{
struct V_75 * V_75 ;
if ( ! F_41 ( V_74 ) )
return - 1 ;
V_75 = F_42 ( V_74 ) ;
if ( ! F_43 ( V_75 ) )
return - 1 ;
return F_44 ( V_74 ) ;
}
int F_45 ( struct V_76 * V_77 , int V_16 )
{
int V_70 ;
unsigned long V_74 , V_78 , V_79 ;
if ( ! V_77 )
return - V_80 ;
if ( ! F_34 ( V_16 ) )
return 0 ;
V_78 = F_46 ( V_77 -> V_81 ) ;
V_79 = F_46 ( V_77 -> V_82 ) ;
V_79 += V_83 - 1 ;
for ( V_74 = V_78 ; V_74 <= V_79 ; V_74 ++ ) {
int V_84 ;
V_84 = F_40 ( V_74 ) ;
if ( V_84 < 0 )
continue;
if ( V_84 != V_16 )
continue;
V_70 = F_47 ( & V_72 [ V_16 ] . V_8 . V_73 ,
& V_77 -> V_8 . V_73 ,
F_37 ( & V_77 -> V_8 . V_73 ) ) ;
if ( V_70 )
return V_70 ;
return F_47 ( & V_77 -> V_8 . V_73 ,
& V_72 [ V_16 ] . V_8 . V_73 ,
F_37 ( & V_72 [ V_16 ] . V_8 . V_73 ) ) ;
}
return 0 ;
}
int F_48 ( struct V_76 * V_77 ,
unsigned long V_85 )
{
F_49 ( V_86 , V_87 , V_88 ) ;
unsigned long V_74 , V_78 , V_79 ;
if ( ! V_77 ) {
F_50 ( V_87 ) ;
return - V_80 ;
}
if ( ! V_87 )
return - V_89 ;
F_51 ( * V_87 ) ;
V_78 = F_46 ( V_85 ) ;
V_79 = V_78 + V_83 - 1 ;
for ( V_74 = V_78 ; V_74 <= V_79 ; V_74 ++ ) {
int V_16 ;
V_16 = F_40 ( V_74 ) ;
if ( V_16 < 0 )
continue;
if ( ! F_34 ( V_16 ) )
continue;
if ( F_52 ( V_16 , * V_87 ) )
continue;
F_39 ( & V_72 [ V_16 ] . V_8 . V_73 ,
F_37 ( & V_77 -> V_8 . V_73 ) ) ;
F_39 ( & V_77 -> V_8 . V_73 ,
F_37 ( & V_72 [ V_16 ] . V_8 . V_73 ) ) ;
}
F_50 ( V_87 ) ;
return 0 ;
}
static int F_53 ( int V_16 )
{
unsigned long V_90 = F_54 ( V_16 ) -> V_91 ;
unsigned long V_92 = V_90 + F_54 ( V_16 ) -> V_93 ;
unsigned long V_74 ;
struct V_76 * V_77 = NULL ;
int V_94 = 0 ;
for ( V_74 = V_90 ; V_74 < V_92 ; V_74 += V_83 ) {
unsigned long V_95 = F_55 ( V_74 ) ;
struct V_96 * V_97 ;
int V_70 ;
if ( ! F_56 ( V_95 ) )
continue;
V_97 = F_57 ( V_95 ) ;
V_77 = F_58 ( V_97 , V_77 ) ;
V_70 = F_45 ( V_77 , V_16 ) ;
if ( ! V_94 )
V_94 = V_70 ;
}
if ( V_77 )
F_59 ( & V_77 -> V_8 . V_73 ) ;
return V_94 ;
}
static void F_60 ( struct V_98 * V_99 )
{
struct V_4 * V_4 = F_61 ( V_99 , struct V_4 , V_100 ) ;
if ( ! F_20 ( V_4 ) )
F_22 ( V_4 ) ;
}
static void F_62 ( int V_16 )
{
F_63 ( & V_72 [ V_16 ] . V_100 , F_60 ) ;
}
static int F_64 ( struct V_101 * V_102 ,
unsigned long V_103 , void * V_104 )
{
struct V_105 * V_106 = V_104 ;
int V_16 = V_106 -> V_107 ;
switch ( V_103 ) {
case V_108 :
case V_109 :
if ( V_16 != V_110 )
F_65 ( & V_72 [ V_16 ] . V_100 ) ;
break;
case V_111 :
case V_112 :
case V_113 :
case V_114 :
default:
break;
}
return V_115 ;
}
static int F_53 ( int V_16 ) { return 0 ; }
static inline int F_64 ( struct V_101 * V_102 ,
unsigned long V_103 , void * V_104 )
{
return V_115 ;
}
static void F_62 ( int V_16 ) { }
int F_66 ( int V_16 )
{
int error = 0 ;
int V_69 ;
if ( F_34 ( V_16 ) ) {
int V_116 = F_67 ( V_16 ) ;
struct V_4 * V_60 = NULL ;
if ( V_116 != V_16 )
V_60 = & V_72 [ V_116 ] ;
error = F_24 ( & V_72 [ V_16 ] , V_16 , V_60 ) ;
F_68 (cpu) {
if ( F_69 ( V_69 ) == V_16 )
F_33 ( V_69 , V_16 ) ;
}
error = F_53 ( V_16 ) ;
F_62 ( V_16 ) ;
}
return error ;
}
void F_70 ( int V_16 )
{
F_29 ( & V_72 [ V_16 ] ) ;
}
static T_1 F_71 ( enum V_117 V_118 , char * V_3 )
{
int V_15 ;
V_15 = F_72 ( V_3 , V_12 , V_117 [ V_118 ] ) ;
if ( V_15 > 0 && V_12 > V_15 + 1 ) {
* ( V_3 + V_15 ++ ) = '\n' ;
* ( V_3 + V_15 ++ ) = '\0' ;
}
return V_15 ;
}
static T_1 F_73 ( struct V_119 * V_120 ,
struct V_121 * V_14 , char * V_3 )
{
struct V_122 * V_123 = F_61 ( V_14 , struct V_122 , V_14 ) ;
return F_71 ( V_123 -> V_118 , V_3 ) ;
}
static int T_3 F_74 ( void )
{
int V_70 ;
F_4 ( F_75 ( V_124 ) != V_125 ) ;
F_4 ( F_75 ( V_126 ) - 1 != V_125 ) ;
V_70 = F_76 ( & V_62 ) ;
if ( ! V_70 ) {
F_77 ( F_64 ,
V_127 ) ;
}
return V_70 ;
}

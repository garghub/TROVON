static T_1 F_1 ( struct V_1 * V_2 , bool V_3 , char * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_3 ( ( V_9 / 32 * 9 ) > ( V_10 - 1 ) ) ;
if ( ! F_4 ( & V_6 , V_11 ) )
return 0 ;
F_5 ( V_6 , F_6 ( V_8 -> V_2 . V_12 ) , V_13 ) ;
V_5 = F_7 ( V_3 , V_4 , V_6 ) ;
F_8 ( V_6 ) ;
return V_5 ;
}
static inline T_1 F_9 ( struct V_1 * V_2 ,
struct V_14 * V_15 , char * V_4 )
{
return F_1 ( V_2 , false , V_4 ) ;
}
static inline T_1 F_10 ( struct V_1 * V_2 ,
struct V_14 * V_15 , char * V_4 )
{
return F_1 ( V_2 , true , V_4 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_14 * V_15 , char * V_4 )
{
int V_5 ;
int V_16 = V_2 -> V_12 ;
struct V_17 * V_18 = F_12 ( V_16 ) ;
struct V_19 V_20 ;
F_13 ( & V_20 , V_16 ) ;
V_5 = sprintf ( V_4 ,
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
V_16 , F_14 ( V_20 . V_21 ) ,
V_16 , F_14 ( V_20 . V_22 ) ,
V_16 , F_14 ( V_20 . V_21 - V_20 . V_22 ) ,
V_16 , F_14 ( F_15 ( V_18 , V_23 ) +
F_15 ( V_18 , V_24 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_25 ) +
F_15 ( V_18 , V_26 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_23 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_25 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_24 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_26 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_27 ) ) ,
V_16 , F_14 ( F_16 ( V_16 , V_28 ) ) ) ;
#ifdef F_17
V_5 += sprintf ( V_4 + V_5 ,
L_12
L_13
L_14
L_15 ,
V_16 , F_14 ( V_20 . V_29 ) ,
V_16 , F_14 ( V_20 . V_30 ) ,
V_16 , F_14 ( V_20 . V_21 - V_20 . V_29 ) ,
V_16 , F_14 ( V_20 . V_22 - V_20 . V_30 ) ) ;
#endif
V_5 += sprintf ( V_4 + V_5 ,
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
#ifdef F_18
L_30
L_31
L_32
#endif
,
V_16 , F_14 ( F_15 ( V_18 , V_31 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_32 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_33 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_34 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_35 ) ) ,
V_16 , F_14 ( V_20 . V_36 ) ,
V_16 , F_16 ( V_16 , V_37 ) ,
V_16 , F_14 ( F_16 ( V_16 , V_38 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_39 ) ) ,
V_16 , F_14 ( F_16 ( V_16 , V_40 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_41 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_42 ) +
F_15 ( V_18 , V_43 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_42 ) ) ,
#ifdef F_18
V_16 , F_14 ( F_15 ( V_18 , V_43 ) ) ,
V_16 , F_14 ( F_15 ( V_18 , V_44 ) *
V_45 ) ,
V_16 , F_14 ( F_15 ( V_18 , V_46 ) *
V_45 ) ,
V_16 , F_14 ( F_15 ( V_18 , V_47 ) *
V_45 ) ) ;
#else
V_16 , F_14 ( F_15 ( V_18 , V_43 ) ) ) ;
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_14 * V_15 , char * V_4 )
{
return sprintf ( V_4 ,
L_33
L_34
L_35
L_36
L_37
L_38 ,
F_20 ( V_2 -> V_12 , V_48 ) ,
F_20 ( V_2 -> V_12 , V_49 ) ,
F_20 ( V_2 -> V_12 , V_50 ) ,
F_20 ( V_2 -> V_12 , V_51 ) ,
F_20 ( V_2 -> V_12 , V_52 ) ,
F_20 ( V_2 -> V_12 , V_53 ) ) ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
struct V_14 * V_15 , char * V_4 )
{
int V_16 = V_2 -> V_12 ;
struct V_17 * V_18 = F_12 ( V_16 ) ;
int V_20 ;
int V_5 = 0 ;
for ( V_20 = 0 ; V_20 < V_54 ; V_20 ++ )
V_5 += sprintf ( V_4 + V_5 , L_39 , V_55 [ V_20 ] ,
F_16 ( V_16 , V_20 ) ) ;
#ifdef F_22
for ( V_20 = 0 ; V_20 < V_56 ; V_20 ++ )
V_5 += sprintf ( V_4 + V_5 , L_39 ,
V_55 [ V_20 + V_54 ] ,
F_20 ( V_16 , V_20 ) ) ;
#endif
for ( V_20 = 0 ; V_20 < V_57 ; V_20 ++ )
V_5 += sprintf ( V_4 + V_5 , L_39 ,
V_55 [ V_20 + V_54 +
V_56 ] ,
F_15 ( V_18 , V_20 ) ) ;
return V_5 ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
struct V_14 * V_15 , char * V_4 )
{
int V_16 = V_2 -> V_12 ;
int V_58 = 0 ;
int V_20 ;
F_3 ( V_59 * 4 > V_10 ) ;
F_24 (i)
V_58 += sprintf ( V_4 + V_58 , L_40 , V_20 ? L_41 : L_42 , F_25 ( V_16 , V_20 ) ) ;
V_58 += sprintf ( V_4 + V_58 , L_43 ) ;
return V_58 ;
}
static inline bool F_26 ( struct V_7 * V_7 )
{
if ( V_60 &&
F_27 ( V_7 -> V_2 . V_12 , V_61 ) ) {
V_60 ( V_7 ) ;
return true ;
}
return false ;
}
static inline void F_28 ( struct V_7 * V_7 )
{
if ( V_62 )
V_62 ( V_7 ) ;
}
void F_29 ( T_3 V_63 ,
T_3 V_64 )
{
V_60 = V_63 ;
V_62 = V_64 ;
}
static inline void F_26 ( struct V_7 * V_7 ) {}
static inline void F_28 ( struct V_7 * V_7 ) {}
static void F_30 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_2 ( V_2 ) ;
#if F_31 ( V_65 ) && F_31 ( V_66 )
F_32 ( & V_7 -> V_67 ) ;
#endif
F_33 ( V_7 ) ;
}
static int F_34 ( struct V_7 * V_7 , int V_68 )
{
int error ;
V_7 -> V_2 . V_12 = V_68 ;
V_7 -> V_2 . V_69 = & V_70 ;
V_7 -> V_2 . V_71 = F_30 ;
V_7 -> V_2 . V_72 = V_73 ;
error = F_35 ( & V_7 -> V_2 ) ;
if ( ! error ) {
F_26 ( V_7 ) ;
F_36 ( V_7 ) ;
}
return error ;
}
void F_37 ( struct V_7 * V_7 )
{
F_28 ( V_7 ) ;
F_38 ( & V_7 -> V_2 ) ;
}
int F_39 ( unsigned int V_74 , unsigned int V_16 )
{
int V_75 ;
struct V_1 * V_76 ;
if ( ! F_40 ( V_16 ) )
return 0 ;
V_76 = F_41 ( V_74 ) ;
if ( ! V_76 )
return 0 ;
V_75 = F_42 ( & V_77 [ V_16 ] -> V_2 . V_78 ,
& V_76 -> V_78 ,
F_43 ( & V_76 -> V_78 ) ) ;
if ( V_75 )
return V_75 ;
return F_42 ( & V_76 -> V_78 ,
& V_77 [ V_16 ] -> V_2 . V_78 ,
F_43 ( & V_77 [ V_16 ] -> V_2 . V_78 ) ) ;
}
int F_44 ( unsigned int V_74 , unsigned int V_16 )
{
struct V_1 * V_76 ;
if ( ! F_40 ( V_16 ) )
return 0 ;
V_76 = F_41 ( V_74 ) ;
if ( ! V_76 )
return 0 ;
F_45 ( & V_77 [ V_16 ] -> V_2 . V_78 ,
F_43 ( & V_76 -> V_78 ) ) ;
F_45 ( & V_76 -> V_78 ,
F_43 ( & V_77 [ V_16 ] -> V_2 . V_78 ) ) ;
return 0 ;
}
static int T_4 F_46 ( unsigned long V_79 )
{
if ( ! F_47 ( V_79 ) )
return - 1 ;
#ifdef F_48
if ( V_80 < V_81 )
return F_49 ( V_79 ) ;
#endif
return F_50 ( V_79 ) ;
}
int F_51 ( struct V_82 * V_83 , int V_16 )
{
int V_75 ;
unsigned long V_79 , V_84 , V_85 ;
if ( ! V_83 )
return - V_86 ;
if ( ! F_40 ( V_16 ) )
return 0 ;
V_84 = F_52 ( V_83 -> V_87 ) ;
V_85 = F_52 ( V_83 -> V_88 ) ;
V_85 += V_89 - 1 ;
for ( V_79 = V_84 ; V_79 <= V_85 ; V_79 ++ ) {
int V_90 ;
if ( ! F_53 ( V_79 ) ) {
V_79 = F_54 ( V_79 + V_89 ,
V_89 ) - 1 ;
continue;
}
V_90 = F_46 ( V_79 ) ;
if ( V_90 < 0 )
continue;
if ( V_90 != V_16 )
continue;
V_75 = F_55 ( & V_77 [ V_16 ] -> V_2 . V_78 ,
& V_83 -> V_2 . V_78 ,
F_43 ( & V_83 -> V_2 . V_78 ) ) ;
if ( V_75 )
return V_75 ;
return F_55 ( & V_83 -> V_2 . V_78 ,
& V_77 [ V_16 ] -> V_2 . V_78 ,
F_43 ( & V_77 [ V_16 ] -> V_2 . V_78 ) ) ;
}
return 0 ;
}
int F_56 ( struct V_82 * V_83 ,
unsigned long V_91 )
{
F_57 ( V_92 , V_93 , V_11 ) ;
unsigned long V_79 , V_84 , V_85 ;
if ( ! V_83 ) {
F_58 ( V_93 ) ;
return - V_86 ;
}
if ( ! V_93 )
return - V_94 ;
F_59 ( * V_93 ) ;
V_84 = F_52 ( V_91 ) ;
V_85 = V_84 + V_89 - 1 ;
for ( V_79 = V_84 ; V_79 <= V_85 ; V_79 ++ ) {
int V_16 ;
V_16 = F_46 ( V_79 ) ;
if ( V_16 < 0 )
continue;
if ( ! F_40 ( V_16 ) )
continue;
if ( F_60 ( V_16 , * V_93 ) )
continue;
F_45 ( & V_77 [ V_16 ] -> V_2 . V_78 ,
F_43 ( & V_83 -> V_2 . V_78 ) ) ;
F_45 ( & V_83 -> V_2 . V_78 ,
F_43 ( & V_77 [ V_16 ] -> V_2 . V_78 ) ) ;
}
F_58 ( V_93 ) ;
return 0 ;
}
int F_61 ( int V_16 , unsigned long V_95 , unsigned long V_96 )
{
unsigned long V_97 = V_95 + V_96 ;
unsigned long V_79 ;
struct V_82 * V_83 = NULL ;
int V_98 = 0 ;
for ( V_79 = V_95 ; V_79 < V_97 ; V_79 += V_89 ) {
unsigned long V_99 = F_62 ( V_79 ) ;
struct V_100 * V_101 ;
int V_75 ;
if ( ! F_63 ( V_99 ) )
continue;
V_101 = F_64 ( V_99 ) ;
if ( V_83 )
if ( ( V_99 >= V_83 -> V_87 ) &&
( V_99 <= V_83 -> V_88 ) )
continue;
V_83 = F_65 ( V_101 , V_83 ) ;
V_75 = F_51 ( V_83 , V_16 ) ;
if ( ! V_98 )
V_98 = V_75 ;
}
if ( V_83 )
F_66 ( & V_83 -> V_2 . V_78 ) ;
return V_98 ;
}
static void F_67 ( struct V_102 * V_103 )
{
struct V_7 * V_7 = F_68 ( V_103 , struct V_7 , V_67 ) ;
if ( ! F_26 ( V_7 ) )
F_28 ( V_7 ) ;
}
static void F_69 ( int V_16 )
{
F_70 ( & V_77 [ V_16 ] -> V_67 , F_67 ) ;
}
static int F_71 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
struct V_108 * V_109 = V_107 ;
int V_16 = V_109 -> V_110 ;
switch ( V_106 ) {
case V_111 :
case V_112 :
if ( V_16 != V_113 )
F_72 ( & V_77 [ V_16 ] -> V_67 ) ;
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
static inline int F_71 ( struct V_104 * V_105 ,
unsigned long V_106 , void * V_107 )
{
return V_118 ;
}
static void F_69 ( int V_16 ) { }
int F_73 ( int V_16 )
{
int error ;
int V_74 ;
V_77 [ V_16 ] = F_74 ( sizeof( struct V_7 ) , V_11 ) ;
if ( ! V_77 [ V_16 ] )
return - V_94 ;
error = F_34 ( V_77 [ V_16 ] , V_16 ) ;
F_75 (cpu) {
if ( F_76 ( V_74 ) == V_16 )
F_39 ( V_74 , V_16 ) ;
}
F_69 ( V_16 ) ;
return error ;
}
void F_77 ( int V_16 )
{
if ( ! V_77 [ V_16 ] )
return;
F_37 ( V_77 [ V_16 ] ) ;
V_77 [ V_16 ] = NULL ;
}
static T_1 F_78 ( enum V_119 V_120 , char * V_4 )
{
int V_5 ;
V_5 = F_79 ( V_4 , V_10 - 1 , L_44 ,
F_80 ( & V_119 [ V_120 ] ) ) ;
V_4 [ V_5 ++ ] = '\n' ;
V_4 [ V_5 ] = '\0' ;
return V_5 ;
}
static T_1 F_81 ( struct V_1 * V_2 ,
struct V_14 * V_15 , char * V_4 )
{
struct V_121 * V_122 = F_68 ( V_15 , struct V_121 , V_15 ) ;
return F_78 ( V_122 -> V_120 , V_4 ) ;
}
static int T_5 F_82 ( void )
{
int V_75 ;
F_3 ( F_83 ( V_123 ) != V_124 ) ;
F_3 ( F_83 ( V_125 ) - 1 != V_124 ) ;
V_75 = F_84 ( & V_70 , V_126 ) ;
if ( ! V_75 ) {
static struct V_104 V_127 = {
. V_128 = F_71 ,
. V_129 = V_130 ,
} ;
F_85 ( & V_127 ) ;
}
return V_75 ;
}

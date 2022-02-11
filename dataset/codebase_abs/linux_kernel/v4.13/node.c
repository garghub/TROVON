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
V_15 , F_11 ( F_12 ( V_17 , V_41 ) +
F_12 ( V_17 , V_42 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_41 ) ) ,
#ifdef F_15
V_15 , F_11 ( F_12 ( V_17 , V_42 ) ) ,
V_15 , F_11 ( F_12 ( V_17 , V_43 ) *
V_44 ) ,
V_15 , F_11 ( F_12 ( V_17 , V_45 ) *
V_44 ) ,
V_15 , F_11 ( F_12 ( V_17 , V_46 ) *
V_44 ) ) ;
#else
V_15 , F_11 ( F_12 ( V_17 , V_42 ) ) ) ;
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
static int F_29 ( struct V_5 * V_5 , int V_66 )
{
int error ;
V_5 -> V_2 . V_9 = V_66 ;
V_5 -> V_2 . V_67 = & V_68 ;
V_5 -> V_2 . V_69 = F_25 ;
V_5 -> V_2 . V_70 = V_71 ;
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
int F_34 ( unsigned int V_72 , unsigned int V_15 )
{
int V_73 ;
struct V_1 * V_74 ;
if ( ! F_35 ( V_15 ) )
return 0 ;
V_74 = F_36 ( V_72 ) ;
if ( ! V_74 )
return 0 ;
V_73 = F_37 ( & V_75 [ V_15 ] -> V_2 . V_76 ,
& V_74 -> V_76 ,
F_38 ( & V_74 -> V_76 ) ) ;
if ( V_73 )
return V_73 ;
return F_37 ( & V_74 -> V_76 ,
& V_75 [ V_15 ] -> V_2 . V_76 ,
F_38 ( & V_75 [ V_15 ] -> V_2 . V_76 ) ) ;
}
int F_39 ( unsigned int V_72 , unsigned int V_15 )
{
struct V_1 * V_74 ;
if ( ! F_35 ( V_15 ) )
return 0 ;
V_74 = F_36 ( V_72 ) ;
if ( ! V_74 )
return 0 ;
F_40 ( & V_75 [ V_15 ] -> V_2 . V_76 ,
F_38 ( & V_74 -> V_76 ) ) ;
F_40 ( & V_74 -> V_76 ,
F_38 ( & V_75 [ V_15 ] -> V_2 . V_76 ) ) ;
return 0 ;
}
static int T_3 F_41 ( unsigned long V_77 )
{
if ( ! F_42 ( V_77 ) )
return - 1 ;
#ifdef F_43
if ( V_78 < V_79 )
return F_44 ( V_77 ) ;
#endif
return F_45 ( V_77 ) ;
}
int F_46 ( struct V_80 * V_81 , int V_15 )
{
int V_73 ;
unsigned long V_77 , V_82 , V_83 ;
if ( ! V_81 )
return - V_84 ;
if ( ! F_35 ( V_15 ) )
return 0 ;
V_82 = F_47 ( V_81 -> V_85 ) ;
V_83 = F_47 ( V_81 -> V_86 ) ;
V_83 += V_87 - 1 ;
for ( V_77 = V_82 ; V_77 <= V_83 ; V_77 ++ ) {
int V_88 ;
if ( ! F_48 ( V_77 ) ) {
V_77 = F_49 ( V_77 + V_87 ,
V_87 ) - 1 ;
continue;
}
V_88 = F_41 ( V_77 ) ;
if ( V_88 < 0 )
continue;
if ( V_88 != V_15 )
continue;
V_73 = F_50 ( & V_75 [ V_15 ] -> V_2 . V_76 ,
& V_81 -> V_2 . V_76 ,
F_38 ( & V_81 -> V_2 . V_76 ) ) ;
if ( V_73 )
return V_73 ;
return F_50 ( & V_81 -> V_2 . V_76 ,
& V_75 [ V_15 ] -> V_2 . V_76 ,
F_38 ( & V_75 [ V_15 ] -> V_2 . V_76 ) ) ;
}
return 0 ;
}
int F_51 ( struct V_80 * V_81 ,
unsigned long V_89 )
{
F_52 ( V_90 , V_91 , V_92 ) ;
unsigned long V_77 , V_82 , V_83 ;
if ( ! V_81 ) {
F_53 ( V_91 ) ;
return - V_84 ;
}
if ( ! V_91 )
return - V_93 ;
F_54 ( * V_91 ) ;
V_82 = F_47 ( V_89 ) ;
V_83 = V_82 + V_87 - 1 ;
for ( V_77 = V_82 ; V_77 <= V_83 ; V_77 ++ ) {
int V_15 ;
V_15 = F_41 ( V_77 ) ;
if ( V_15 < 0 )
continue;
if ( ! F_35 ( V_15 ) )
continue;
if ( F_55 ( V_15 , * V_91 ) )
continue;
F_40 ( & V_75 [ V_15 ] -> V_2 . V_76 ,
F_38 ( & V_81 -> V_2 . V_76 ) ) ;
F_40 ( & V_81 -> V_2 . V_76 ,
F_38 ( & V_75 [ V_15 ] -> V_2 . V_76 ) ) ;
}
F_53 ( V_91 ) ;
return 0 ;
}
int F_56 ( int V_15 , unsigned long V_94 , unsigned long V_95 )
{
unsigned long V_96 = V_94 + V_95 ;
unsigned long V_77 ;
struct V_80 * V_81 = NULL ;
int V_97 = 0 ;
for ( V_77 = V_94 ; V_77 < V_96 ; V_77 += V_87 ) {
unsigned long V_98 = F_57 ( V_77 ) ;
struct V_99 * V_100 ;
int V_73 ;
if ( ! F_58 ( V_98 ) )
continue;
V_100 = F_59 ( V_98 ) ;
if ( V_81 )
if ( ( V_98 >= V_81 -> V_85 ) &&
( V_98 <= V_81 -> V_86 ) )
continue;
V_81 = F_60 ( V_100 , V_81 ) ;
V_73 = F_46 ( V_81 , V_15 ) ;
if ( ! V_97 )
V_97 = V_73 ;
}
if ( V_81 )
F_61 ( & V_81 -> V_2 . V_76 ) ;
return V_97 ;
}
static void F_62 ( struct V_101 * V_102 )
{
struct V_5 * V_5 = F_63 ( V_102 , struct V_5 , V_65 ) ;
if ( ! F_21 ( V_5 ) )
F_23 ( V_5 ) ;
}
static void F_64 ( int V_15 )
{
F_65 ( & V_75 [ V_15 ] -> V_65 , F_62 ) ;
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
F_67 ( & V_75 [ V_15 ] -> V_65 ) ;
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
static inline int F_66 ( struct V_103 * V_104 ,
unsigned long V_105 , void * V_106 )
{
return V_117 ;
}
static void F_64 ( int V_15 ) { }
int F_68 ( int V_15 )
{
int error ;
int V_72 ;
V_75 [ V_15 ] = F_69 ( sizeof( struct V_5 ) , V_92 ) ;
if ( ! V_75 [ V_15 ] )
return - V_93 ;
error = F_29 ( V_75 [ V_15 ] , V_15 ) ;
F_70 (cpu) {
if ( F_71 ( V_72 ) == V_15 )
F_34 ( V_72 , V_15 ) ;
}
F_64 ( V_15 ) ;
return error ;
}
void F_72 ( int V_15 )
{
if ( ! V_75 [ V_15 ] )
return;
F_32 ( V_75 [ V_15 ] ) ;
V_75 [ V_15 ] = NULL ;
}
static T_1 F_73 ( enum V_118 V_119 , char * V_4 )
{
int V_14 ;
V_14 = F_74 ( V_4 , V_11 - 1 , L_44 ,
F_75 ( & V_118 [ V_119 ] ) ) ;
V_4 [ V_14 ++ ] = '\n' ;
V_4 [ V_14 ] = '\0' ;
return V_14 ;
}
static T_1 F_76 ( struct V_1 * V_2 ,
struct V_12 * V_13 , char * V_4 )
{
struct V_120 * V_121 = F_63 ( V_13 , struct V_120 , V_13 ) ;
return F_73 ( V_121 -> V_119 , V_4 ) ;
}
static int T_4 F_77 ( void )
{
int V_73 ;
F_4 ( F_78 ( V_122 ) != V_123 ) ;
F_4 ( F_78 ( V_124 ) - 1 != V_123 ) ;
V_73 = F_79 ( & V_68 , V_125 ) ;
if ( ! V_73 ) {
static struct V_103 V_126 = {
. V_127 = F_66 ,
. V_128 = V_129 ,
} ;
F_80 ( & V_126 ) ;
}
return V_73 ;
}

void
F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
V_6 -> F_1 ( V_2 , V_4 ) ;
V_8 -> F_1 ( V_2 , V_4 ) ;
}
static struct V_9 * F_2 ( struct V_1 * V_10 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_9 * V_14 ;
for ( V_12 -> V_15 = 0 ;
V_12 -> V_15 < V_12 -> V_16 ;
V_12 -> V_15 ++ ) {
V_14 = F_3 (
F_4 ( & V_12 -> V_17 [ V_12 -> V_15 ] ) ) ;
if ( ! F_5 ( V_14 ) )
return V_14 ;
}
return NULL ;
}
static struct V_9 * F_6 ( struct V_1 * V_10 ,
struct V_9 * V_18 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_18 = F_3 ( F_7 ( V_18 ) ) ;
while ( F_5 ( V_18 ) ) {
if ( F_8 ( F_9 ( V_18 ) == V_12 -> V_15 ) ) {
if ( ++ V_12 -> V_15 >= V_12 -> V_16 )
return NULL ;
}
V_18 = F_3 (
F_4 ( & V_12 -> V_17 [ V_12 -> V_15 ] ) ) ;
}
return V_18 ;
}
static struct V_9 * F_10 ( struct V_1 * V_10 , T_1 V_19 )
{
struct V_9 * V_18 = F_2 ( V_10 ) ;
if ( V_18 )
while ( V_19 && ( V_18 = F_6 ( V_10 , V_18 ) ) )
V_19 -- ;
return V_19 ? NULL : V_18 ;
}
static void * F_11 ( struct V_1 * V_10 , T_1 * V_19 )
__acquires( T_2 )
{
struct V_11 * V_12 = V_10 -> V_13 ;
V_12 -> V_20 = F_12 () ;
F_13 () ;
F_14 ( & V_12 -> V_17 , & V_12 -> V_16 ) ;
return F_10 ( V_10 , * V_19 ) ;
}
static void * F_15 ( struct V_1 * V_2 , void * V_21 , T_1 * V_19 )
{
( * V_19 ) ++ ;
return F_6 ( V_2 , V_21 ) ;
}
static void F_16 ( struct V_1 * V_2 , void * V_21 )
__releases( T_2 )
{
F_17 () ;
}
static void F_18 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
int V_24 ;
T_3 V_25 ;
char * V_26 ;
V_24 = F_19 ( V_23 -> V_27 , & V_26 , & V_25 ) ;
if ( V_24 )
return;
F_20 ( V_2 , L_1 , V_26 ) ;
F_21 ( V_26 , V_25 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
}
static void F_22 ( struct V_1 * V_2 , const struct V_22 * V_23 ,
int V_28 )
{
const struct V_29 * V_30 = F_23 ( V_23 ) ;
if ( V_30 -> V_28 != V_28 )
return;
switch ( V_30 -> V_28 ) {
case V_31 :
F_20 ( V_2 , L_2 , V_30 -> V_32 ) ;
break;
case V_33 :
F_20 ( V_2 , L_3 , V_30 -> V_32 ) ;
break;
case V_34 :
F_20 ( V_2 , L_4 , V_30 -> V_32 ) ;
break;
default:
break;
}
}
static inline void F_22 ( struct V_1 * V_2 , const struct V_22 * V_23 ,
int V_28 )
{
}
static void F_24 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_35 * V_36 ;
T_4 V_37 ;
V_36 = F_25 ( V_23 ) ;
if ( V_36 ) {
V_37 = V_12 -> V_20 - V_36 -> V_38 ;
if ( V_37 > 0 )
V_37 = F_26 ( V_37 , V_39 ) ;
else
V_37 = 0 ;
F_20 ( V_2 , L_5 ,
( unsigned long long ) V_37 ) ;
}
return;
}
static inline void
F_24 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
}
static int F_27 ( struct V_1 * V_2 , void * V_21 )
{
struct V_40 * V_17 = V_21 ;
struct V_22 * V_23 = F_28 ( V_17 ) ;
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
struct V_41 * V_41 = F_29 ( V_2 ) ;
int V_24 = 0 ;
F_30 ( V_23 ) ;
if ( F_31 ( ! F_32 ( & V_23 -> V_42 . V_43 ) ) )
return 0 ;
if ( F_33 ( V_23 ) ) {
F_34 ( V_23 ) ;
goto V_44;
}
if ( F_35 ( V_17 ) )
goto V_44;
if ( ! F_36 ( F_37 ( V_23 ) , V_41 ) )
goto V_44;
V_6 = F_38 ( F_39 ( V_23 ) ) ;
F_30 ( V_6 ) ;
V_8 = F_40 ( F_39 ( V_23 ) , F_41 ( V_23 ) ) ;
F_30 ( V_8 ) ;
V_24 = - V_45 ;
F_20 ( V_2 , L_6 ,
V_6 -> V_46 , F_39 ( V_23 ) ,
V_8 -> V_46 , F_41 ( V_23 ) ,
F_42 ( V_23 ) / V_47 ) ;
if ( V_8 -> V_48 )
V_8 -> V_48 ( V_2 , V_23 ) ;
F_1 ( V_2 , & V_23 -> V_49 [ V_50 ] . V_4 ,
V_6 , V_8 ) ;
F_22 ( V_2 , V_23 , V_33 ) ;
if ( F_43 ( V_2 ) )
goto V_44;
if ( F_44 ( V_2 , V_23 , V_50 ) )
goto V_44;
if ( ! ( F_45 ( V_51 , & V_23 -> V_52 ) ) )
F_20 ( V_2 , L_7 ) ;
F_1 ( V_2 , & V_23 -> V_49 [ V_53 ] . V_4 ,
V_6 , V_8 ) ;
F_22 ( V_2 , V_23 , V_34 ) ;
if ( F_44 ( V_2 , V_23 , V_53 ) )
goto V_44;
if ( F_45 ( V_54 , & V_23 -> V_52 ) )
F_20 ( V_2 , L_8 ) ;
if ( F_43 ( V_2 ) )
goto V_44;
#if F_46 ( V_55 )
F_20 ( V_2 , L_9 , V_23 -> V_56 ) ;
#endif
F_18 ( V_2 , V_23 ) ;
F_22 ( V_2 , V_23 , V_31 ) ;
F_24 ( V_2 , V_23 ) ;
F_20 ( V_2 , L_10 , F_47 ( & V_23 -> V_42 . V_43 ) ) ;
if ( F_43 ( V_2 ) )
goto V_44;
V_24 = 0 ;
V_44:
F_48 ( V_23 ) ;
return V_24 ;
}
static int F_49 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_50 ( V_57 , V_58 , & V_59 ,
sizeof( struct V_11 ) ) ;
}
static void * F_51 ( struct V_1 * V_10 , T_1 * V_19 )
{
struct V_41 * V_41 = F_29 ( V_10 ) ;
int V_60 ;
if ( * V_19 == 0 )
return V_61 ;
for ( V_60 = * V_19 - 1 ; V_60 < V_62 ; ++ V_60 ) {
if ( ! F_52 ( V_60 ) )
continue;
* V_19 = V_60 + 1 ;
return F_53 ( V_41 -> V_23 . V_63 , V_60 ) ;
}
return NULL ;
}
static void * F_54 ( struct V_1 * V_10 , void * V_21 , T_1 * V_19 )
{
struct V_41 * V_41 = F_29 ( V_10 ) ;
int V_60 ;
for ( V_60 = * V_19 ; V_60 < V_62 ; ++ V_60 ) {
if ( ! F_52 ( V_60 ) )
continue;
* V_19 = V_60 + 1 ;
return F_53 ( V_41 -> V_23 . V_63 , V_60 ) ;
}
return NULL ;
}
static void F_55 ( struct V_1 * V_10 , void * V_21 )
{
}
static int F_56 ( struct V_1 * V_10 , void * V_21 )
{
struct V_41 * V_41 = F_29 ( V_10 ) ;
unsigned int V_64 = F_47 ( & V_41 -> V_23 . V_65 ) ;
const struct V_66 * V_12 = V_21 ;
if ( V_21 == V_61 ) {
F_20 ( V_10 , L_11 ) ;
return 0 ;
}
F_20 ( V_10 , L_12
L_13 ,
V_64 ,
0 ,
V_12 -> V_67 ,
0 ,
V_12 -> V_68 ,
V_12 -> V_69 ,
0 ,
0 ,
V_12 -> V_70 ,
V_12 -> V_71 ,
V_12 -> V_72 ,
V_12 -> V_73 ,
V_12 -> error ,
V_12 -> V_74 ,
V_12 -> V_75 ,
V_12 -> V_76 ,
V_12 -> V_77
) ;
return 0 ;
}
static int F_57 ( struct V_57 * V_57 , struct V_58 * V_58 )
{
return F_50 ( V_57 , V_58 , & V_78 ,
sizeof( struct V_79 ) ) ;
}
static int F_58 ( struct V_41 * V_41 )
{
struct V_80 * V_81 ;
T_5 V_82 ;
T_6 V_83 ;
V_81 = F_59 ( L_14 , 0440 , V_41 -> V_84 , & V_85 ) ;
if ( ! V_81 )
goto V_86;
V_82 = F_60 ( V_41 -> V_87 , 0 ) ;
V_83 = F_61 ( V_41 -> V_87 , 0 ) ;
if ( F_62 ( V_82 ) && F_63 ( V_83 ) )
F_64 ( V_81 , V_82 , V_83 ) ;
V_81 = F_59 ( L_14 , V_88 , V_41 -> V_89 ,
& V_90 ) ;
if ( ! V_81 )
goto V_91;
return 0 ;
V_91:
F_65 ( L_14 , V_41 -> V_84 ) ;
V_86:
return - V_92 ;
}
static void F_66 ( struct V_41 * V_41 )
{
F_65 ( L_14 , V_41 -> V_89 ) ;
F_65 ( L_14 , V_41 -> V_84 ) ;
}
static int F_58 ( struct V_41 * V_41 )
{
return 0 ;
}
static void F_66 ( struct V_41 * V_41 )
{
}
static int
F_67 ( struct V_93 * V_94 , int V_95 ,
void T_7 * V_96 , T_8 * V_97 , T_1 * V_98 )
{
int V_24 ;
V_24 = F_68 ( V_94 , V_95 , V_96 , V_97 , V_98 ) ;
if ( V_24 < 0 || ! V_95 )
return V_24 ;
V_24 = F_69 ( V_99 ) ;
V_99 = V_100 ;
return V_24 ;
}
static int F_70 ( struct V_41 * V_41 )
{
struct V_93 * V_94 ;
V_94 = F_71 ( V_101 , sizeof( V_101 ) ,
V_102 ) ;
if ( ! V_94 )
goto V_103;
V_94 [ 1 ] . V_104 = & V_41 -> V_23 . V_65 ;
V_94 [ 3 ] . V_104 = & V_41 -> V_23 . V_105 ;
V_94 [ 4 ] . V_104 = & V_41 -> V_23 . V_106 ;
if ( V_41 -> V_87 != & V_107 )
V_94 [ 0 ] . V_108 = NULL ;
if ( ! F_36 ( & V_109 , V_41 ) )
V_94 [ 2 ] . V_110 = 0444 ;
V_41 -> V_23 . V_111 = F_72 ( V_41 , L_15 , V_94 ) ;
if ( ! V_41 -> V_23 . V_111 )
goto V_112;
return 0 ;
V_112:
F_73 ( V_94 ) ;
V_103:
return - V_92 ;
}
static void F_74 ( struct V_41 * V_41 )
{
struct V_93 * V_94 ;
V_94 = V_41 -> V_23 . V_111 -> V_113 ;
F_75 ( V_41 -> V_23 . V_111 ) ;
F_73 ( V_94 ) ;
}
static int F_70 ( struct V_41 * V_41 )
{
return 0 ;
}
static void F_74 ( struct V_41 * V_41 )
{
}
static int F_76 ( struct V_41 * V_41 )
{
int V_24 ;
V_24 = F_77 ( V_41 ) ;
if ( V_24 < 0 )
goto V_114;
V_24 = F_58 ( V_41 ) ;
if ( V_24 < 0 )
goto V_115;
V_41 -> V_23 . V_105 = 1 ;
V_41 -> V_23 . V_106 = 0 ;
V_24 = F_70 ( V_41 ) ;
if ( V_24 < 0 )
goto V_116;
return 0 ;
V_116:
F_66 ( V_41 ) ;
V_115:
F_78 ( V_41 ) ;
V_114:
return V_24 ;
}
static void F_79 ( struct V_117 * V_118 )
{
struct V_41 * V_41 ;
F_80 (net, net_exit_list, exit_list) {
F_74 ( V_41 ) ;
F_66 ( V_41 ) ;
}
F_81 ( V_118 ) ;
}
static int T_9 F_82 ( void )
{
int V_24 = F_83 () ;
if ( V_24 < 0 )
goto V_119;
#ifdef F_84
V_120 =
F_72 ( & V_109 , L_16 , V_121 ) ;
if ( ! V_120 ) {
F_85 ( L_17 ) ;
V_24 = - V_92 ;
goto V_116;
}
V_99 = V_100 ;
#endif
V_24 = F_86 ( & V_122 ) ;
if ( V_24 < 0 )
goto V_123;
F_87 () ;
return 0 ;
V_123:
#ifdef F_84
F_75 ( V_120 ) ;
V_116:
#endif
F_88 () ;
V_119:
return V_24 ;
}
static void T_10 F_89 ( void )
{
F_90 () ;
F_91 ( & V_122 ) ;
#ifdef F_84
F_75 ( V_120 ) ;
#endif
F_88 () ;
}
void F_92 ( void )
{
}

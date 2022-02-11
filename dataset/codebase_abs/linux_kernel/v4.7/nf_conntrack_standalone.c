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
V_12 -> V_15 < V_16 ;
V_12 -> V_15 ++ ) {
V_14 = F_3 ( F_4 ( & V_17 [ V_12 -> V_15 ] ) ) ;
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
if ( ++ V_12 -> V_15 >= V_16 )
return NULL ;
}
V_18 = F_3 (
F_4 (
& V_17 [ V_12 -> V_15 ] ) ) ;
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
return F_10 ( V_10 , * V_19 ) ;
}
static void * F_14 ( struct V_1 * V_2 , void * V_21 , T_1 * V_19 )
{
( * V_19 ) ++ ;
return F_6 ( V_2 , V_21 ) ;
}
static void F_15 ( struct V_1 * V_2 , void * V_21 )
__releases( T_2 )
{
F_16 () ;
}
static void F_17 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
int V_24 ;
T_3 V_25 ;
char * V_26 ;
V_24 = F_18 ( V_23 -> V_27 , & V_26 , & V_25 ) ;
if ( V_24 )
return;
F_19 ( V_2 , L_1 , V_26 ) ;
F_20 ( V_26 , V_25 ) ;
}
static inline void F_17 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
}
static void F_21 ( struct V_1 * V_2 , const struct V_22 * V_23 ,
int V_28 )
{
const struct V_29 * V_30 = F_22 ( V_23 ) ;
if ( V_30 -> V_28 != V_28 )
return;
switch ( V_30 -> V_28 ) {
case V_31 :
F_19 ( V_2 , L_2 , V_30 -> V_32 ) ;
break;
case V_33 :
F_19 ( V_2 , L_3 , V_30 -> V_32 ) ;
break;
case V_34 :
F_19 ( V_2 , L_4 , V_30 -> V_32 ) ;
break;
default:
break;
}
}
static inline void F_21 ( struct V_1 * V_2 , const struct V_22 * V_23 ,
int V_28 )
{
}
static void F_23 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
struct V_35 * V_36 ;
T_4 V_37 ;
V_36 = F_24 ( V_23 ) ;
if ( V_36 ) {
V_37 = V_12 -> V_20 - V_36 -> V_38 ;
if ( V_37 > 0 )
V_37 = F_25 ( V_37 , V_39 ) ;
else
V_37 = 0 ;
F_19 ( V_2 , L_5 ,
( unsigned long long ) V_37 ) ;
}
return;
}
static inline void
F_23 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
}
static int F_26 ( struct V_1 * V_2 , void * V_21 )
{
struct V_40 * V_41 = V_21 ;
struct V_22 * V_23 = F_27 ( V_41 ) ;
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
int V_24 = 0 ;
F_28 ( V_23 ) ;
if ( F_29 ( ! F_30 ( & V_23 -> V_42 . V_43 ) ) )
return 0 ;
if ( F_31 ( V_41 ) )
goto V_44;
V_6 = F_32 ( F_33 ( V_23 ) ) ;
F_28 ( V_6 ) ;
V_8 = F_34 ( F_33 ( V_23 ) , F_35 ( V_23 ) ) ;
F_28 ( V_8 ) ;
V_24 = - V_45 ;
F_19 ( V_2 , L_6 ,
V_6 -> V_46 , F_33 ( V_23 ) ,
V_8 -> V_46 , F_35 ( V_23 ) ,
F_36 ( & V_23 -> V_47 )
? ( long ) ( V_23 -> V_47 . V_48 - V_49 ) / V_50 : 0 ) ;
if ( V_8 -> V_51 )
V_8 -> V_51 ( V_2 , V_23 ) ;
F_1 ( V_2 , & V_23 -> V_52 [ V_53 ] . V_4 ,
V_6 , V_8 ) ;
F_21 ( V_2 , V_23 , V_33 ) ;
if ( F_37 ( V_2 ) )
goto V_44;
if ( F_38 ( V_2 , V_23 , V_53 ) )
goto V_44;
if ( ! ( F_39 ( V_54 , & V_23 -> V_55 ) ) )
F_19 ( V_2 , L_7 ) ;
F_1 ( V_2 , & V_23 -> V_52 [ V_56 ] . V_4 ,
V_6 , V_8 ) ;
F_21 ( V_2 , V_23 , V_34 ) ;
if ( F_38 ( V_2 , V_23 , V_56 ) )
goto V_44;
if ( F_39 ( V_57 , & V_23 -> V_55 ) )
F_19 ( V_2 , L_8 ) ;
if ( F_37 ( V_2 ) )
goto V_44;
#if F_40 ( V_58 )
F_19 ( V_2 , L_9 , V_23 -> V_59 ) ;
#endif
F_17 ( V_2 , V_23 ) ;
F_21 ( V_2 , V_23 , V_31 ) ;
F_23 ( V_2 , V_23 ) ;
F_19 ( V_2 , L_10 , F_41 ( & V_23 -> V_42 . V_43 ) ) ;
if ( F_37 ( V_2 ) )
goto V_44;
V_24 = 0 ;
V_44:
F_42 ( V_23 ) ;
return V_24 ;
}
static int F_43 ( struct V_60 * V_60 , struct V_61 * V_61 )
{
return F_44 ( V_60 , V_61 , & V_62 ,
sizeof( struct V_11 ) ) ;
}
static void * F_45 ( struct V_1 * V_10 , T_1 * V_19 )
{
struct V_63 * V_63 = F_46 ( V_10 ) ;
int V_64 ;
if ( * V_19 == 0 )
return V_65 ;
for ( V_64 = * V_19 - 1 ; V_64 < V_66 ; ++ V_64 ) {
if ( ! F_47 ( V_64 ) )
continue;
* V_19 = V_64 + 1 ;
return F_48 ( V_63 -> V_23 . V_67 , V_64 ) ;
}
return NULL ;
}
static void * F_49 ( struct V_1 * V_10 , void * V_21 , T_1 * V_19 )
{
struct V_63 * V_63 = F_46 ( V_10 ) ;
int V_64 ;
for ( V_64 = * V_19 ; V_64 < V_66 ; ++ V_64 ) {
if ( ! F_47 ( V_64 ) )
continue;
* V_19 = V_64 + 1 ;
return F_48 ( V_63 -> V_23 . V_67 , V_64 ) ;
}
return NULL ;
}
static void F_50 ( struct V_1 * V_10 , void * V_21 )
{
}
static int F_51 ( struct V_1 * V_10 , void * V_21 )
{
struct V_63 * V_63 = F_46 ( V_10 ) ;
unsigned int V_68 = F_41 ( & V_63 -> V_23 . V_69 ) ;
const struct V_70 * V_12 = V_21 ;
if ( V_21 == V_65 ) {
F_19 ( V_10 , L_11 ) ;
return 0 ;
}
F_19 ( V_10 , L_12
L_13 ,
V_68 ,
V_12 -> V_71 ,
V_12 -> V_72 ,
V_12 -> V_73 ,
V_12 -> V_74 ,
V_12 -> V_75 ,
V_12 -> V_76 ,
V_12 -> V_77 ,
V_12 -> V_78 ,
V_12 -> V_79 ,
V_12 -> V_80 ,
V_12 -> V_81 ,
V_12 -> error ,
V_12 -> V_82 ,
V_12 -> V_83 ,
V_12 -> V_84 ,
V_12 -> V_85
) ;
return 0 ;
}
static int F_52 ( struct V_60 * V_60 , struct V_61 * V_61 )
{
return F_44 ( V_60 , V_61 , & V_86 ,
sizeof( struct V_87 ) ) ;
}
static int F_53 ( struct V_63 * V_63 )
{
struct V_88 * V_89 ;
T_5 V_90 ;
T_6 V_91 ;
V_89 = F_54 ( L_14 , 0440 , V_63 -> V_92 , & V_93 ) ;
if ( ! V_89 )
goto V_94;
V_90 = F_55 ( V_63 -> V_95 , 0 ) ;
V_91 = F_56 ( V_63 -> V_95 , 0 ) ;
if ( F_57 ( V_90 ) && F_58 ( V_91 ) )
F_59 ( V_89 , V_90 , V_91 ) ;
V_89 = F_54 ( L_14 , V_96 , V_63 -> V_97 ,
& V_98 ) ;
if ( ! V_89 )
goto V_99;
return 0 ;
V_99:
F_60 ( L_14 , V_63 -> V_92 ) ;
V_94:
return - V_100 ;
}
static void F_61 ( struct V_63 * V_63 )
{
F_60 ( L_14 , V_63 -> V_97 ) ;
F_60 ( L_14 , V_63 -> V_92 ) ;
}
static int F_53 ( struct V_63 * V_63 )
{
return 0 ;
}
static void F_61 ( struct V_63 * V_63 )
{
}
static int F_62 ( struct V_63 * V_63 )
{
struct V_101 * V_102 ;
V_102 = F_63 ( V_103 , sizeof( V_103 ) ,
V_104 ) ;
if ( ! V_102 )
goto V_105;
V_102 [ 1 ] . V_106 = & V_63 -> V_23 . V_69 ;
V_102 [ 3 ] . V_106 = & V_63 -> V_23 . V_107 ;
V_102 [ 4 ] . V_106 = & V_63 -> V_23 . V_108 ;
if ( V_63 -> V_95 != & V_109 )
V_102 [ 0 ] . V_110 = NULL ;
V_63 -> V_23 . V_111 = F_64 ( V_63 , L_15 , V_102 ) ;
if ( ! V_63 -> V_23 . V_111 )
goto V_112;
return 0 ;
V_112:
F_65 ( V_102 ) ;
V_105:
return - V_100 ;
}
static void F_66 ( struct V_63 * V_63 )
{
struct V_101 * V_102 ;
V_102 = V_63 -> V_23 . V_111 -> V_113 ;
F_67 ( V_63 -> V_23 . V_111 ) ;
F_65 ( V_102 ) ;
}
static int F_62 ( struct V_63 * V_63 )
{
return 0 ;
}
static void F_66 ( struct V_63 * V_63 )
{
}
static int F_68 ( struct V_63 * V_63 )
{
int V_24 ;
V_24 = F_69 ( V_63 ) ;
if ( V_24 < 0 )
goto V_114;
V_24 = F_53 ( V_63 ) ;
if ( V_24 < 0 )
goto V_115;
V_63 -> V_23 . V_107 = 1 ;
V_63 -> V_23 . V_108 = 0 ;
V_24 = F_62 ( V_63 ) ;
if ( V_24 < 0 )
goto V_116;
return 0 ;
V_116:
F_61 ( V_63 ) ;
V_115:
F_70 ( V_63 ) ;
V_114:
return V_24 ;
}
static void F_71 ( struct V_117 * V_118 )
{
struct V_63 * V_63 ;
F_72 (net, net_exit_list, exit_list) {
F_66 ( V_63 ) ;
F_61 ( V_63 ) ;
}
F_73 ( V_118 ) ;
}
static int T_7 F_74 ( void )
{
int V_24 = F_75 () ;
if ( V_24 < 0 )
goto V_119;
#ifdef F_76
V_120 =
F_64 ( & V_121 , L_16 , V_122 ) ;
if ( ! V_120 ) {
F_77 ( L_17 ) ;
V_24 = - V_100 ;
goto V_116;
}
#endif
V_24 = F_78 ( & V_123 ) ;
if ( V_24 < 0 )
goto V_124;
F_79 () ;
return 0 ;
V_124:
#ifdef F_76
F_67 ( V_120 ) ;
V_116:
#endif
F_80 () ;
V_119:
return V_24 ;
}
static void T_8 F_81 ( void )
{
F_82 () ;
F_83 ( & V_123 ) ;
#ifdef F_76
F_67 ( V_120 ) ;
#endif
F_80 () ;
}
void F_84 ( void )
{
}

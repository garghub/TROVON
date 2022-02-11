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
struct V_11 * V_11 = F_3 ( V_10 ) ;
struct V_12 * V_13 = V_10 -> V_14 ;
struct V_9 * V_15 ;
for ( V_13 -> V_16 = 0 ;
V_13 -> V_16 < V_11 -> V_17 . V_18 ;
V_13 -> V_16 ++ ) {
V_15 = F_4 ( F_5 ( & V_11 -> V_17 . V_19 [ V_13 -> V_16 ] ) ) ;
if ( ! F_6 ( V_15 ) )
return V_15 ;
}
return NULL ;
}
static struct V_9 * F_7 ( struct V_1 * V_10 ,
struct V_9 * V_20 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
struct V_12 * V_13 = V_10 -> V_14 ;
V_20 = F_4 ( F_8 ( V_20 ) ) ;
while ( F_6 ( V_20 ) ) {
if ( F_9 ( F_10 ( V_20 ) == V_13 -> V_16 ) ) {
if ( ++ V_13 -> V_16 >= V_11 -> V_17 . V_18 )
return NULL ;
}
V_20 = F_4 (
F_5 (
& V_11 -> V_17 . V_19 [ V_13 -> V_16 ] ) ) ;
}
return V_20 ;
}
static struct V_9 * F_11 ( struct V_1 * V_10 , T_1 V_21 )
{
struct V_9 * V_20 = F_2 ( V_10 ) ;
if ( V_20 )
while ( V_21 && ( V_20 = F_7 ( V_10 , V_20 ) ) )
V_21 -- ;
return V_21 ? NULL : V_20 ;
}
static void * F_12 ( struct V_1 * V_10 , T_1 * V_21 )
__acquires( T_2 )
{
struct V_12 * V_13 = V_10 -> V_14 ;
V_13 -> V_22 = F_13 () ;
F_14 () ;
return F_11 ( V_10 , * V_21 ) ;
}
static void * F_15 ( struct V_1 * V_2 , void * V_23 , T_1 * V_21 )
{
( * V_21 ) ++ ;
return F_7 ( V_2 , V_23 ) ;
}
static void F_16 ( struct V_1 * V_2 , void * V_23 )
__releases( T_2 )
{
F_17 () ;
}
static void F_18 ( struct V_1 * V_2 , const struct V_24 * V_17 )
{
int V_25 ;
T_3 V_26 ;
char * V_27 ;
V_25 = F_19 ( V_17 -> V_28 , & V_27 , & V_26 ) ;
if ( V_25 )
return;
F_20 ( V_2 , L_1 , V_27 ) ;
F_21 ( V_27 , V_26 ) ;
}
static inline void F_18 ( struct V_1 * V_2 , const struct V_24 * V_17 )
{
}
static void F_22 ( struct V_1 * V_2 , const struct V_24 * V_17 ,
int V_29 )
{
const struct V_30 * V_31 = F_23 ( V_17 ) ;
if ( V_31 -> V_29 != V_29 )
return;
switch ( V_31 -> V_29 ) {
case V_32 :
F_20 ( V_2 , L_2 , V_31 -> V_33 ) ;
break;
case V_34 :
F_20 ( V_2 , L_3 , V_31 -> V_33 ) ;
break;
case V_35 :
F_20 ( V_2 , L_4 , V_31 -> V_33 ) ;
break;
default:
break;
}
}
static inline void F_22 ( struct V_1 * V_2 , const struct V_24 * V_17 ,
int V_29 )
{
}
static void F_24 ( struct V_1 * V_2 , const struct V_24 * V_17 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_36 * V_37 ;
T_4 V_38 ;
V_37 = F_25 ( V_17 ) ;
if ( V_37 ) {
V_38 = V_13 -> V_22 - V_37 -> V_39 ;
if ( V_38 > 0 )
V_38 = F_26 ( V_38 , V_40 ) ;
else
V_38 = 0 ;
F_20 ( V_2 , L_5 ,
( unsigned long long ) V_38 ) ;
}
return;
}
static inline void
F_24 ( struct V_1 * V_2 , const struct V_24 * V_17 )
{
}
static int F_27 ( struct V_1 * V_2 , void * V_23 )
{
struct V_41 * V_19 = V_23 ;
struct V_24 * V_17 = F_28 ( V_19 ) ;
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
int V_25 = 0 ;
F_29 ( V_17 ) ;
if ( F_30 ( ! F_31 ( & V_17 -> V_42 . V_43 ) ) )
return 0 ;
if ( F_32 ( V_19 ) )
goto V_44;
V_6 = F_33 ( F_34 ( V_17 ) ) ;
F_29 ( V_6 ) ;
V_8 = F_35 ( F_34 ( V_17 ) , F_36 ( V_17 ) ) ;
F_29 ( V_8 ) ;
V_25 = - V_45 ;
F_20 ( V_2 , L_6 ,
V_6 -> V_46 , F_34 ( V_17 ) ,
V_8 -> V_46 , F_36 ( V_17 ) ,
F_37 ( & V_17 -> V_47 )
? ( long ) ( V_17 -> V_47 . V_48 - V_49 ) / V_50 : 0 ) ;
if ( V_8 -> V_51 )
V_8 -> V_51 ( V_2 , V_17 ) ;
F_1 ( V_2 , & V_17 -> V_52 [ V_53 ] . V_4 ,
V_6 , V_8 ) ;
F_22 ( V_2 , V_17 , V_34 ) ;
if ( F_38 ( V_2 ) )
goto V_44;
if ( F_39 ( V_2 , V_17 , V_53 ) )
goto V_44;
if ( ! ( F_40 ( V_54 , & V_17 -> V_55 ) ) )
F_20 ( V_2 , L_7 ) ;
F_1 ( V_2 , & V_17 -> V_52 [ V_56 ] . V_4 ,
V_6 , V_8 ) ;
F_22 ( V_2 , V_17 , V_35 ) ;
if ( F_39 ( V_2 , V_17 , V_56 ) )
goto V_44;
if ( F_40 ( V_57 , & V_17 -> V_55 ) )
F_20 ( V_2 , L_8 ) ;
if ( F_38 ( V_2 ) )
goto V_44;
#if F_41 ( V_58 )
F_20 ( V_2 , L_9 , V_17 -> V_59 ) ;
#endif
F_18 ( V_2 , V_17 ) ;
F_22 ( V_2 , V_17 , V_32 ) ;
F_24 ( V_2 , V_17 ) ;
F_20 ( V_2 , L_10 , F_42 ( & V_17 -> V_42 . V_43 ) ) ;
if ( F_38 ( V_2 ) )
goto V_44;
V_25 = 0 ;
V_44:
F_43 ( V_17 ) ;
return V_25 ;
}
static int F_44 ( struct V_60 * V_60 , struct V_61 * V_61 )
{
return F_45 ( V_60 , V_61 , & V_62 ,
sizeof( struct V_12 ) ) ;
}
static void * F_46 ( struct V_1 * V_10 , T_1 * V_21 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
int V_63 ;
if ( * V_21 == 0 )
return V_64 ;
for ( V_63 = * V_21 - 1 ; V_63 < V_65 ; ++ V_63 ) {
if ( ! F_47 ( V_63 ) )
continue;
* V_21 = V_63 + 1 ;
return F_48 ( V_11 -> V_17 . V_66 , V_63 ) ;
}
return NULL ;
}
static void * F_49 ( struct V_1 * V_10 , void * V_23 , T_1 * V_21 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
int V_63 ;
for ( V_63 = * V_21 ; V_63 < V_65 ; ++ V_63 ) {
if ( ! F_47 ( V_63 ) )
continue;
* V_21 = V_63 + 1 ;
return F_48 ( V_11 -> V_17 . V_66 , V_63 ) ;
}
return NULL ;
}
static void F_50 ( struct V_1 * V_10 , void * V_23 )
{
}
static int F_51 ( struct V_1 * V_10 , void * V_23 )
{
struct V_11 * V_11 = F_3 ( V_10 ) ;
unsigned int V_67 = F_42 ( & V_11 -> V_17 . V_68 ) ;
const struct V_69 * V_13 = V_23 ;
if ( V_23 == V_64 ) {
F_20 ( V_10 , L_11 ) ;
return 0 ;
}
F_20 ( V_10 , L_12
L_13 ,
V_67 ,
V_13 -> V_70 ,
V_13 -> V_71 ,
V_13 -> V_72 ,
V_13 -> V_73 ,
V_13 -> V_74 ,
V_13 -> V_75 ,
V_13 -> V_76 ,
V_13 -> V_77 ,
V_13 -> V_78 ,
V_13 -> V_79 ,
V_13 -> V_80 ,
V_13 -> error ,
V_13 -> V_81 ,
V_13 -> V_82 ,
V_13 -> V_83 ,
V_13 -> V_84
) ;
return 0 ;
}
static int F_52 ( struct V_60 * V_60 , struct V_61 * V_61 )
{
return F_45 ( V_60 , V_61 , & V_85 ,
sizeof( struct V_86 ) ) ;
}
static int F_53 ( struct V_11 * V_11 )
{
struct V_87 * V_88 ;
T_5 V_89 ;
T_6 V_90 ;
V_88 = F_54 ( L_14 , 0440 , V_11 -> V_91 , & V_92 ) ;
if ( ! V_88 )
goto V_93;
V_89 = F_55 ( V_11 -> V_94 , 0 ) ;
V_90 = F_56 ( V_11 -> V_94 , 0 ) ;
if ( F_57 ( V_89 ) && F_58 ( V_90 ) )
F_59 ( V_88 , V_89 , V_90 ) ;
V_88 = F_54 ( L_14 , V_95 , V_11 -> V_96 ,
& V_97 ) ;
if ( ! V_88 )
goto V_98;
return 0 ;
V_98:
F_60 ( L_14 , V_11 -> V_91 ) ;
V_93:
return - V_99 ;
}
static void F_61 ( struct V_11 * V_11 )
{
F_60 ( L_14 , V_11 -> V_96 ) ;
F_60 ( L_14 , V_11 -> V_91 ) ;
}
static int F_53 ( struct V_11 * V_11 )
{
return 0 ;
}
static void F_61 ( struct V_11 * V_11 )
{
}
static int F_62 ( struct V_11 * V_11 )
{
struct V_100 * V_101 ;
V_101 = F_63 ( V_102 , sizeof( V_102 ) ,
V_103 ) ;
if ( ! V_101 )
goto V_104;
V_101 [ 1 ] . V_105 = & V_11 -> V_17 . V_68 ;
V_101 [ 2 ] . V_105 = & V_11 -> V_17 . V_18 ;
V_101 [ 3 ] . V_105 = & V_11 -> V_17 . V_106 ;
V_101 [ 4 ] . V_105 = & V_11 -> V_17 . V_107 ;
if ( V_11 -> V_94 != & V_108 )
V_101 [ 0 ] . V_109 = NULL ;
V_11 -> V_17 . V_110 = F_64 ( V_11 , L_15 , V_101 ) ;
if ( ! V_11 -> V_17 . V_110 )
goto V_111;
return 0 ;
V_111:
F_65 ( V_101 ) ;
V_104:
return - V_99 ;
}
static void F_66 ( struct V_11 * V_11 )
{
struct V_100 * V_101 ;
V_101 = V_11 -> V_17 . V_110 -> V_112 ;
F_67 ( V_11 -> V_17 . V_110 ) ;
F_65 ( V_101 ) ;
}
static int F_62 ( struct V_11 * V_11 )
{
return 0 ;
}
static void F_66 ( struct V_11 * V_11 )
{
}
static int F_68 ( struct V_11 * V_11 )
{
int V_25 ;
V_25 = F_69 ( V_11 ) ;
if ( V_25 < 0 )
goto V_113;
V_25 = F_53 ( V_11 ) ;
if ( V_25 < 0 )
goto V_114;
V_11 -> V_17 . V_106 = 1 ;
V_11 -> V_17 . V_107 = 0 ;
V_25 = F_62 ( V_11 ) ;
if ( V_25 < 0 )
goto V_115;
return 0 ;
V_115:
F_61 ( V_11 ) ;
V_114:
F_70 ( V_11 ) ;
V_113:
return V_25 ;
}
static void F_71 ( struct V_116 * V_117 )
{
struct V_11 * V_11 ;
F_72 (net, net_exit_list, exit_list) {
F_66 ( V_11 ) ;
F_61 ( V_11 ) ;
}
F_73 ( V_117 ) ;
}
static int T_7 F_74 ( void )
{
int V_25 = F_75 () ;
if ( V_25 < 0 )
goto V_118;
#ifdef F_76
V_119 =
F_64 ( & V_120 , L_16 , V_121 ) ;
if ( ! V_119 ) {
F_77 ( L_17 ) ;
V_25 = - V_99 ;
goto V_115;
}
#endif
V_25 = F_78 ( & V_122 ) ;
if ( V_25 < 0 )
goto V_123;
F_79 () ;
return 0 ;
V_123:
#ifdef F_76
F_67 ( V_119 ) ;
V_115:
#endif
F_80 () ;
V_118:
return V_25 ;
}
static void T_8 F_81 ( void )
{
F_82 () ;
F_83 ( & V_122 ) ;
#ifdef F_76
F_67 ( V_119 ) ;
#endif
F_80 () ;
}
void F_84 ( void )
{
}

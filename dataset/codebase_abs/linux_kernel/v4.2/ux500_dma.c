static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = V_3 -> V_1 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_8 * V_8 = V_7 -> V_8 ;
unsigned long V_9 ;
F_2 ( V_8 -> V_10 , L_1 ,
V_7 -> V_11 ) ;
F_3 ( & V_8 -> V_12 , V_9 ) ;
V_5 -> V_3 . V_13 = V_5 -> V_14 ;
V_5 -> V_3 . V_15 = V_16 ;
F_4 ( V_8 , V_7 -> V_11 , V_5 -> V_17 ) ;
F_5 ( & V_8 -> V_12 , V_9 ) ;
}
static bool F_6 ( struct V_2 * V_3 ,
T_1 V_18 , T_2 V_19 ,
T_3 V_20 , T_4 V_21 )
{
struct V_4 * V_5 = V_3 -> V_1 ;
struct V_6 * V_7 = V_5 -> V_7 ;
struct V_22 * V_22 = V_5 -> V_22 ;
struct V_23 * V_24 ;
enum V_25 V_26 ;
struct V_27 V_28 ;
struct V_29 V_30 ;
enum V_31 V_32 ;
struct V_8 * V_8 = V_5 -> V_10 -> V_1 ;
T_3 V_33 = ( V_8 -> V_34 . V_35 ( V_7 -> V_11 ) +
V_5 -> V_10 -> V_36 ) ;
F_2 ( V_8 -> V_10 ,
L_2 ,
V_18 , V_19 , ( unsigned long long ) V_20 ,
V_21 , V_5 -> V_17 ) ;
V_5 -> V_14 = V_21 ;
F_7 ( & V_28 , 1 ) ;
F_8 ( & V_28 , F_9 ( F_10 ( V_20 ) ) , V_21 ,
F_11 ( V_20 ) ) ;
F_12 ( & V_28 ) = V_20 ;
F_13 ( & V_28 ) = V_21 ;
V_26 = V_5 -> V_17 ? V_37 : V_38 ;
V_32 = ( V_21 & 0x3 ) ? V_39 :
V_40 ;
V_30 . V_26 = V_26 ;
V_30 . V_41 = V_33 ;
V_30 . V_42 = V_32 ;
V_30 . V_43 = 16 ;
V_30 . V_44 = V_33 ;
V_30 . V_45 = V_32 ;
V_30 . V_46 = 16 ;
V_30 . V_47 = false ;
F_14 ( V_22 , & V_30 ) ;
V_24 = F_15 ( V_22 , & V_28 , 1 , V_26 ,
V_48 | V_49 ) ;
if ( ! V_24 )
return false ;
V_24 -> V_50 = F_1 ;
V_24 -> V_51 = V_3 ;
V_5 -> V_52 = V_24 -> V_53 ( V_24 ) ;
F_16 ( V_22 ) ;
return true ;
}
static struct V_2 * F_17 ( struct V_54 * V_55 ,
struct V_6 * V_7 , T_2 V_17 )
{
struct V_56 * V_10 = F_18 ( V_55 ,
struct V_56 , V_10 ) ;
struct V_4 * V_5 = NULL ;
struct V_8 * V_8 = V_10 -> V_1 ;
T_2 V_57 = V_7 -> V_11 - 1 ;
if ( V_57 > 7 )
V_57 -= 8 ;
if ( V_57 >= V_58 )
return NULL ;
V_5 = V_17 ? & ( V_10 -> V_59 [ V_57 ] ) :
& ( V_10 -> V_60 [ V_57 ] ) ;
if ( V_5 -> V_61 )
return NULL ;
V_5 -> V_7 = V_7 ;
V_5 -> V_61 = 1 ;
F_2 ( V_8 -> V_10 , L_3 ,
V_7 -> V_11 , V_17 , V_57 ) ;
return & ( V_5 -> V_3 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_1 ;
struct V_8 * V_8 = V_5 -> V_10 -> V_1 ;
F_2 ( V_8 -> V_10 , L_4 , V_5 -> V_57 ) ;
if ( V_5 -> V_61 ) {
V_5 -> V_61 = 0 ;
V_3 -> V_15 = V_16 ;
V_3 -> V_13 = 0 ;
}
}
static int F_20 ( struct V_2 * V_3 ,
T_1 V_62 , void * V_63 , T_4 V_64 )
{
if ( ( V_62 & 0x3 ) ||
( ( unsigned long int ) V_63 & 0x3 ) ||
( V_64 < 512 ) ||
( V_64 & 0x3 ) )
return false ;
else
return true ;
}
static int F_21 ( struct V_2 * V_3 ,
T_1 V_18 , T_2 V_19 ,
T_3 V_20 , T_4 V_21 )
{
int V_65 ;
F_22 ( V_3 -> V_15 == V_66 ||
V_3 -> V_15 == V_67 ) ;
if ( ! F_20 ( V_3 , V_18 , ( void * ) V_20 , V_21 ) )
return false ;
V_3 -> V_15 = V_67 ;
V_3 -> V_13 = 0 ;
V_65 = F_6 ( V_3 , V_18 , V_19 , V_20 , V_21 ) ;
if ( ! V_65 )
V_3 -> V_15 = V_16 ;
return V_65 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_1 ;
struct V_56 * V_10 = V_5 -> V_10 ;
struct V_8 * V_8 = V_10 -> V_1 ;
void T_5 * V_68 = V_8 -> V_69 [ V_5 -> V_7 -> V_11 ] . V_70 ;
T_1 V_71 ;
F_2 ( V_8 -> V_10 , L_5 ,
V_5 -> V_57 , V_5 -> V_17 ) ;
if ( V_3 -> V_15 == V_67 ) {
if ( V_5 -> V_17 ) {
V_71 = F_24 ( V_68 , V_72 ) ;
V_71 &= ~ ( V_73 |
V_74 |
V_75 ) ;
F_25 ( V_68 , V_72 , V_71 ) ;
} else {
V_71 = F_24 ( V_68 , V_76 ) ;
V_71 &= ~ ( V_77 |
V_78 |
V_79 ) ;
F_25 ( V_68 , V_76 , V_71 ) ;
}
F_26 ( V_5 -> V_22 ) ;
V_3 -> V_15 = V_16 ;
}
return 0 ;
}
static void F_27 ( struct V_56 * V_10 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
T_2 V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_3 = & V_10 -> V_60 [ V_57 ] . V_3 ;
V_5 = V_3 -> V_1 ;
F_19 ( V_3 ) ;
if ( V_5 -> V_22 )
F_28 ( V_5 -> V_22 ) ;
}
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
V_3 = & V_10 -> V_59 [ V_57 ] . V_3 ;
V_5 = V_3 -> V_1 ;
F_19 ( V_3 ) ;
if ( V_5 -> V_22 )
F_28 ( V_5 -> V_22 ) ;
}
}
static int F_29 ( struct V_56 * V_10 )
{
struct V_4 * V_5 = NULL ;
struct V_8 * V_8 = V_10 -> V_1 ;
struct V_80 * V_81 = V_8 -> V_10 ;
struct V_82 * V_83 = F_30 ( V_81 ) ;
struct V_84 * V_85 ;
struct V_2 * V_2 = NULL ;
char * * V_86 ;
T_4 V_57 ;
T_2 V_87 ;
T_2 V_17 = 0 ;
void * * V_88 ;
struct V_4 * V_89 ;
T_6 V_90 ;
if ( ! V_83 ) {
F_31 ( V_8 -> V_10 , L_6 ) ;
return - V_91 ;
}
V_85 = V_83 -> V_92 ;
F_32 ( V_90 ) ;
F_33 ( V_93 , V_90 ) ;
V_89 = V_10 -> V_60 ;
V_88 = V_85 ? V_85 -> V_94 : NULL ;
V_86 = ( char * * ) V_95 ;
for ( V_87 = 0 ; V_87 < 2 ; V_87 ++ ) {
for ( V_57 = 0 ;
V_57 < V_58 ;
V_57 ++ ) {
V_5 = & V_89 [ V_57 ] ;
V_5 -> V_10 = V_10 ;
V_5 -> V_57 = V_57 ;
V_5 -> V_17 = V_17 ;
V_2 = & ( V_5 -> V_3 ) ;
V_2 -> V_1 = V_5 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_96 = V_97 ;
V_5 -> V_22 =
F_34 ( V_81 , V_86 [ V_57 ] ) ;
if ( ! V_5 -> V_22 )
V_5 -> V_22 =
F_35 ( V_90 ,
V_85 ?
V_85 -> V_98 :
NULL ,
V_88 ?
V_88 [ V_57 ] :
NULL ) ;
if ( ! V_5 -> V_22 ) {
F_36 ( L_7 ,
V_87 , V_57 ) ;
F_27 ( V_10 ) ;
return - V_99 ;
}
}
V_89 = V_10 -> V_59 ;
V_88 = V_85 ? V_85 -> V_100 : NULL ;
V_86 = ( char * * ) V_101 ;
V_17 = 1 ;
}
return 0 ;
}
void F_37 ( struct V_54 * V_55 )
{
struct V_56 * V_10 = F_18 ( V_55 ,
struct V_56 , V_10 ) ;
F_27 ( V_10 ) ;
F_38 ( V_10 ) ;
}
struct V_54 *
F_39 ( struct V_8 * V_8 , void T_5 * V_102 )
{
struct V_56 * V_10 ;
struct V_103 * V_104 = F_40 ( V_8 -> V_10 ) ;
struct V_105 * V_106 ;
int V_65 ;
V_10 = F_41 ( sizeof( * V_10 ) , V_107 ) ;
if ( ! V_10 )
goto V_108;
V_10 -> V_1 = V_8 ;
V_106 = F_42 ( V_104 , V_109 , 0 ) ;
if ( ! V_106 ) {
F_31 ( V_8 -> V_10 , L_8 ) ;
goto V_110;
}
V_10 -> V_36 = ( T_3 ) V_106 -> V_111 ;
V_10 -> V_10 . V_112 = F_17 ;
V_10 -> V_10 . V_113 = F_19 ;
V_10 -> V_10 . V_114 = F_21 ;
V_10 -> V_10 . V_115 = F_23 ;
V_10 -> V_10 . V_116 = F_20 ;
V_65 = F_29 ( V_10 ) ;
if ( V_65 )
goto V_110;
return & V_10 -> V_10 ;
V_110:
F_38 ( V_10 ) ;
V_108:
return NULL ;
}

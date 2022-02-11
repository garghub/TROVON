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
T_3 V_33 = ( F_7 ( V_7 -> V_11 ) +
V_5 -> V_10 -> V_34 ) ;
struct V_8 * V_8 = V_5 -> V_10 -> V_1 ;
F_2 ( V_8 -> V_10 ,
L_2 ,
V_18 , V_19 , ( unsigned long long ) V_20 ,
V_21 , V_5 -> V_17 ) ;
V_5 -> V_14 = V_21 ;
F_8 ( & V_28 , 1 ) ;
F_9 ( & V_28 , F_10 ( F_11 ( V_20 ) ) , V_21 ,
F_12 ( V_20 ) ) ;
F_13 ( & V_28 ) = V_20 ;
F_14 ( & V_28 ) = V_21 ;
V_26 = V_5 -> V_17 ? V_35 : V_36 ;
V_32 = ( V_21 & 0x3 ) ? V_37 :
V_38 ;
V_30 . V_26 = V_26 ;
V_30 . V_39 = V_33 ;
V_30 . V_40 = V_32 ;
V_30 . V_41 = 16 ;
V_30 . V_42 = V_33 ;
V_30 . V_43 = V_32 ;
V_30 . V_44 = 16 ;
V_30 . V_45 = false ;
V_22 -> V_46 -> V_47 ( V_22 , V_48 ,
( unsigned long ) & V_30 ) ;
V_24 = F_15 ( V_22 , & V_28 , 1 , V_26 ,
V_49 | V_50 ) ;
if ( ! V_24 )
return false ;
V_24 -> V_51 = F_1 ;
V_24 -> V_52 = V_3 ;
V_5 -> V_53 = V_24 -> V_54 ( V_24 ) ;
F_16 ( V_22 ) ;
return true ;
}
static struct V_2 * F_17 ( struct V_55 * V_56 ,
struct V_6 * V_7 , T_2 V_17 )
{
struct V_57 * V_10 = F_18 ( V_56 ,
struct V_57 , V_10 ) ;
struct V_4 * V_5 = NULL ;
struct V_8 * V_8 = V_10 -> V_1 ;
T_2 V_58 = V_7 -> V_11 - 1 ;
if ( V_58 > 7 )
V_58 -= 8 ;
if ( V_58 >= V_59 )
return NULL ;
V_5 = V_17 ? & ( V_10 -> V_60 [ V_58 ] ) :
& ( V_10 -> V_61 [ V_58 ] ) ;
if ( V_5 -> V_62 )
return NULL ;
V_5 -> V_7 = V_7 ;
V_5 -> V_62 = 1 ;
F_2 ( V_8 -> V_10 , L_3 ,
V_7 -> V_11 , V_17 , V_58 ) ;
return & ( V_5 -> V_3 ) ;
}
static void F_19 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_1 ;
struct V_8 * V_8 = V_5 -> V_10 -> V_1 ;
F_2 ( V_8 -> V_10 , L_4 , V_5 -> V_58 ) ;
if ( V_5 -> V_62 ) {
V_5 -> V_62 = 0 ;
V_3 -> V_15 = V_16 ;
V_3 -> V_13 = 0 ;
}
}
static int F_20 ( struct V_2 * V_3 ,
T_1 V_63 , void * V_64 , T_4 V_65 )
{
if ( ( V_63 & 0x3 ) ||
( ( unsigned long int ) V_64 & 0x3 ) ||
( V_65 < 512 ) ||
( V_65 & 0x3 ) )
return false ;
else
return true ;
}
static int F_21 ( struct V_2 * V_3 ,
T_1 V_18 , T_2 V_19 ,
T_3 V_20 , T_4 V_21 )
{
int V_66 ;
F_22 ( V_3 -> V_15 == V_67 ||
V_3 -> V_15 == V_68 ) ;
if ( ! F_20 ( V_3 , V_18 , ( void * ) V_20 , V_21 ) )
return false ;
V_3 -> V_15 = V_68 ;
V_3 -> V_13 = 0 ;
V_66 = F_6 ( V_3 , V_18 , V_19 , V_20 , V_21 ) ;
if ( ! V_66 )
V_3 -> V_15 = V_16 ;
return V_66 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_1 ;
struct V_57 * V_10 = V_5 -> V_10 ;
struct V_8 * V_8 = V_10 -> V_1 ;
void T_5 * V_69 = V_8 -> V_70 [ V_5 -> V_7 -> V_11 ] . V_71 ;
T_1 V_72 ;
F_2 ( V_8 -> V_10 , L_5 ,
V_5 -> V_58 , V_5 -> V_17 ) ;
if ( V_3 -> V_15 == V_68 ) {
if ( V_5 -> V_17 ) {
V_72 = F_24 ( V_69 , V_73 ) ;
V_72 &= ~ ( V_74 |
V_75 |
V_76 ) ;
F_25 ( V_69 , V_73 , V_72 ) ;
} else {
V_72 = F_24 ( V_69 , V_77 ) ;
V_72 &= ~ ( V_78 |
V_79 |
V_80 ) ;
F_25 ( V_69 , V_77 , V_72 ) ;
}
V_5 -> V_22 -> V_46 ->
V_47 ( V_5 -> V_22 ,
V_81 , 0 ) ;
V_3 -> V_15 = V_16 ;
}
return 0 ;
}
static void F_26 ( struct V_57 * V_10 )
{
struct V_4 * V_5 ;
struct V_2 * V_3 ;
T_2 V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_3 = & V_10 -> V_61 [ V_58 ] . V_3 ;
V_5 = V_3 -> V_1 ;
F_19 ( V_3 ) ;
if ( V_5 -> V_22 )
F_27 ( V_5 -> V_22 ) ;
}
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
V_3 = & V_10 -> V_60 [ V_58 ] . V_3 ;
V_5 = V_3 -> V_1 ;
F_19 ( V_3 ) ;
if ( V_5 -> V_22 )
F_27 ( V_5 -> V_22 ) ;
}
}
static int F_28 ( struct V_57 * V_10 )
{
struct V_4 * V_5 = NULL ;
struct V_8 * V_8 = V_10 -> V_1 ;
struct V_46 * V_82 = V_8 -> V_10 ;
struct V_83 * V_84 = F_29 ( V_82 ) ;
struct V_85 * V_86 ;
struct V_2 * V_2 = NULL ;
char * * V_87 ;
T_4 V_58 ;
T_2 V_88 ;
T_2 V_17 = 0 ;
void * * V_89 ;
struct V_4 * V_90 ;
T_6 V_91 ;
if ( ! V_84 ) {
F_30 ( V_8 -> V_10 , L_6 ) ;
return - V_92 ;
}
V_86 = V_84 -> V_93 ;
F_31 ( V_91 ) ;
F_32 ( V_94 , V_91 ) ;
V_90 = V_10 -> V_61 ;
V_89 = V_86 ? V_86 -> V_95 : NULL ;
V_87 = ( char * * ) V_96 ;
for ( V_88 = 0 ; V_88 < 2 ; V_88 ++ ) {
for ( V_58 = 0 ;
V_58 < V_59 ;
V_58 ++ ) {
V_5 = & V_90 [ V_58 ] ;
V_5 -> V_10 = V_10 ;
V_5 -> V_58 = V_58 ;
V_5 -> V_17 = V_17 ;
V_2 = & ( V_5 -> V_3 ) ;
V_2 -> V_1 = V_5 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_97 = V_98 ;
V_5 -> V_22 =
F_33 ( V_82 , V_87 [ V_58 ] ) ;
if ( ! V_5 -> V_22 )
V_5 -> V_22 =
F_34 ( V_91 ,
V_86 ?
V_86 -> V_99 :
NULL ,
V_89 [ V_58 ] ) ;
if ( ! V_5 -> V_22 ) {
F_35 ( L_7 ,
V_88 , V_58 ) ;
F_26 ( V_10 ) ;
return - V_100 ;
}
}
V_90 = V_10 -> V_60 ;
V_89 = V_86 ? V_86 -> V_101 : NULL ;
V_87 = ( char * * ) V_102 ;
V_17 = 1 ;
}
return 0 ;
}
void F_36 ( struct V_55 * V_56 )
{
struct V_57 * V_10 = F_18 ( V_56 ,
struct V_57 , V_10 ) ;
F_26 ( V_10 ) ;
F_37 ( V_10 ) ;
}
struct V_55 * F_38 ( struct V_8 * V_8 ,
void T_5 * V_103 )
{
struct V_57 * V_10 ;
struct V_104 * V_105 = F_39 ( V_8 -> V_10 ) ;
struct V_106 * V_107 ;
int V_66 ;
V_10 = F_40 ( sizeof( * V_10 ) , V_108 ) ;
if ( ! V_10 )
goto V_109;
V_10 -> V_1 = V_8 ;
V_107 = F_41 ( V_105 , V_110 , 0 ) ;
if ( ! V_107 ) {
F_30 ( V_8 -> V_10 , L_8 ) ;
goto V_111;
}
V_10 -> V_34 = ( T_3 ) V_107 -> V_112 ;
V_10 -> V_10 . V_113 = F_17 ;
V_10 -> V_10 . V_114 = F_19 ;
V_10 -> V_10 . V_115 = F_21 ;
V_10 -> V_10 . V_116 = F_23 ;
V_10 -> V_10 . V_117 = F_20 ;
V_66 = F_28 ( V_10 ) ;
if ( V_66 )
goto V_111;
return & V_10 -> V_10 ;
V_111:
F_37 ( V_10 ) ;
V_109:
return NULL ;
}

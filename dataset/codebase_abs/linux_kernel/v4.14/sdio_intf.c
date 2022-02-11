static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
if ( ! V_4 -> V_5 ) {
F_3 ( L_1 , V_6 ) ;
return;
}
F_4 ( V_4 , V_7 ) ;
F_5 ( V_4 -> V_5 ) ;
F_4 ( V_4 , NULL ) ;
}
static int F_6 ( struct V_3 * V_8 )
{
T_1 V_9 ;
struct V_1 * V_2 ;
int V_10 ;
V_9 = & V_8 -> V_11 ;
V_2 = V_9 -> V_2 ;
F_7 ( V_2 ) ;
V_10 = F_8 ( V_2 , & F_1 ) ;
if ( V_10 )
{
V_8 -> V_12 . V_13 ++ ;
F_9 ( V_14 L_2 , V_6 , V_10 ) ;
}
else
{
V_8 -> V_12 . V_15 ++ ;
V_8 -> V_16 = 1 ;
}
F_10 ( V_2 ) ;
return V_10 ? V_17 : V_18 ;
}
static void F_11 ( struct V_3 * V_8 )
{
T_1 V_9 ;
struct V_1 * V_2 ;
int V_10 ;
if ( V_8 -> V_16 ) {
V_9 = & V_8 -> V_11 ;
V_2 = V_9 -> V_2 ;
if ( V_2 ) {
F_7 ( V_2 ) ;
V_10 = F_12 ( V_2 ) ;
if ( V_10 )
{
V_8 -> V_12 . V_19 ++ ;
F_13 ( V_20 , L_3 , V_6 , V_10 ) ;
}
else
V_8 -> V_12 . V_21 ++ ;
F_10 ( V_2 ) ;
}
V_8 -> V_16 = 0 ;
}
}
static T_2 F_14 ( int V_22 , void * V_23 )
{
struct V_24 * V_25 = V_23 ;
F_13 ( V_26 , L_4 ) ;
F_15 ( V_27 / 2 ) ;
return V_28 ;
}
static T_3 F_16 ( struct V_24 * V_25 )
{
int V_10 ;
if ( V_29 == 0 ) {
F_3 ( L_5 ) ;
return V_17 ;
}
V_10 = F_17 ( V_29 , F_14 , NULL ,
V_30 ,
L_6 , V_25 ) ;
if ( V_10 < 0 ) {
F_3 ( L_7 , V_29 , V_10 ) ;
return false ;
} else {
F_3 ( L_8 , V_29 ) ;
}
F_18 ( V_29 ) ;
return V_18 ;
}
static void F_19 ( struct V_24 * V_25 )
{
if ( V_29 == 0 )
return;
F_20 ( V_29 ) ;
F_21 ( V_29 , V_25 ) ;
}
static T_4 F_22 ( struct V_3 * V_8 )
{
T_1 V_9 ;
struct V_1 * V_2 ;
int V_10 ;
V_9 = & V_8 -> V_11 ;
V_2 = V_9 -> V_2 ;
F_7 ( V_2 ) ;
V_10 = F_23 ( V_2 ) ;
if ( V_10 ) {
V_8 -> V_12 . V_31 ++ ;
F_24 ( V_14 L_9 , V_6 , V_10 ) ;
goto V_32;
}
V_10 = F_25 ( V_2 , 512 ) ;
if ( V_10 ) {
V_8 -> V_12 . V_31 ++ ;
F_24 ( V_14 L_10 , V_6 , V_10 ) ;
goto V_32;
}
V_9 -> V_33 = 512 ;
V_9 -> V_34 = 1 ;
V_9 -> V_35 = 1 ;
V_32:
F_10 ( V_2 ) ;
if ( V_10 )
return V_17 ;
return V_18 ;
}
static void F_26 ( struct V_3 * V_8 )
{
struct V_1 * V_2 ;
int V_10 ;
F_27 ( V_36 , V_37 , ( L_11 ) ) ;
V_2 = V_8 -> V_11 . V_2 ;
if ( V_2 ) {
F_7 ( V_2 ) ;
V_10 = F_28 ( V_2 ) ;
if ( V_10 )
{
V_8 -> V_12 . V_38 ++ ;
F_24 ( V_39 L_12 , V_6 , V_10 ) ;
}
if ( V_8 -> V_16 ) {
V_10 = F_12 ( V_2 ) ;
if ( V_10 )
{
V_8 -> V_12 . V_19 ++ ;
F_24 ( V_39 L_13 , V_6 , V_10 ) ;
}
else
V_8 -> V_12 . V_21 ++ ;
}
F_10 ( V_2 ) ;
}
}
static struct V_3 * F_29 ( struct V_1 * V_2 )
{
int V_40 = V_17 ;
struct V_3 * V_8 = NULL ;
T_1 V_41 ;
V_8 = F_30 () ;
if ( V_8 == NULL ) {
goto exit;
}
F_31 ( V_2 , V_8 ) ;
V_41 = & V_8 -> V_11 ;
V_41 -> V_2 = V_2 ;
if ( F_22 ( V_8 ) != V_18 ) {
F_27 ( V_36 , V_20 , ( L_14 , V_6 ) ) ;
goto V_42;
}
F_32 ( V_8 ) ;
V_40 = V_18 ;
V_42:
if ( V_40 != V_18 && V_8 ) {
F_31 ( V_2 , NULL ) ;
F_33 ( V_8 ) ;
V_8 = NULL ;
}
exit:
return V_8 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
F_31 ( V_2 , NULL ) ;
if ( V_8 ) {
F_26 ( V_8 ) ;
F_33 ( V_8 ) ;
}
return;
}
void F_35 ( struct V_24 * V_25 )
{
F_36 ( V_25 ) ;
F_37 ( V_25 ) ;
}
static void F_38 ( struct V_24 * V_25 )
{
if ( V_25 == NULL ) {
F_24 ( V_39 L_15 , V_6 ) ;
return;
}
F_39 ( V_25 ) ;
}
static void F_40 ( struct V_24 * V_25 )
{
if ( V_25 == NULL ) {
F_24 ( V_39 L_15 , V_6 ) ;
return;
}
F_41 ( V_25 ) ;
}
static struct V_24 * F_42 ( struct V_3 * V_8 , const struct V_43 * V_44 )
{
int V_40 = V_17 ;
struct V_45 * V_46 ;
struct V_24 * V_25 = NULL ;
T_1 V_41 = & V_8 -> V_11 ;
V_25 = (struct V_24 * ) F_43 ( sizeof( * V_25 ) ) ;
if ( V_25 == NULL ) {
goto exit;
}
V_25 -> V_8 = V_8 ;
V_8 -> V_5 = V_25 ;
V_25 -> V_47 = true ;
V_8 -> V_48 = V_25 ;
V_25 -> V_49 = 0 ;
V_46 = F_44 ( V_25 ) ;
if ( ! V_46 )
goto V_50;
F_45 ( V_46 , F_46 ( V_8 ) ) ;
V_25 = F_47 ( V_46 ) ;
F_48 ( V_25 , F_46 ( V_8 ) ) ;
F_35 ( V_25 ) ;
V_25 -> V_51 = & F_38 ;
V_25 -> V_52 = & F_40 ;
V_25 -> V_53 = & F_22 ;
V_25 -> V_54 = & F_26 ;
V_25 -> V_55 = & F_6 ;
V_25 -> V_56 = & F_11 ;
if ( F_49 ( V_25 , V_57 ) == V_17 )
{
F_27 ( V_36 , V_20 ,
( L_16 ) ) ;
goto V_58;
}
F_50 ( V_25 ) ;
F_51 ( V_25 ) ;
F_52 ( V_25 ) ;
F_53 ( V_25 ) ;
if ( F_54 ( V_25 ) == V_17 ) {
F_27 ( V_36 , V_20 ,
( L_17 ) ) ;
goto V_58;
}
F_55 ( & V_41 -> V_2 -> V_59 , V_25 -> V_60 . V_61 ) ;
F_41 ( V_25 ) ;
F_3 ( L_18
, V_25 -> V_47
, V_25 -> V_62
, V_25 -> V_63
, V_25 -> V_64
) ;
V_40 = V_18 ;
V_58:
if ( V_40 != V_18 && V_25 -> V_65 )
F_56 ( V_25 -> V_65 ) ;
if ( V_40 != V_18 ) {
F_57 ( V_25 -> V_66 ) ;
F_58 ( V_25 -> V_66 ) ;
}
V_50:
if ( V_40 != V_18 ) {
if ( V_46 )
F_59 ( V_46 ) ;
else
F_60 ( ( T_3 * ) V_25 ) ;
V_25 = NULL ;
}
exit:
return V_25 ;
}
static void F_61 ( struct V_24 * V_5 )
{
struct V_45 * V_46 = V_5 -> V_46 ;
struct V_67 * V_68 = & V_5 -> V_69 ;
if ( F_62 ( V_68 , V_70 ) )
F_63 ( V_5 , 0 , false ) ;
F_64 ( V_5 ) ;
#ifdef F_65
F_19 ( V_5 ) ;
#endif
F_66 ( V_5 ) ;
#ifdef F_67
F_68 ( V_5 ) -> V_71 = false ;
F_13 ( V_26 , L_19 , V_6 , F_68 ( V_5 ) -> V_71 ) ;
#endif
F_69 ( V_5 ) ;
F_3 ( L_20 , V_5 -> V_64 ) ;
if ( V_5 -> V_66 ) {
F_58 ( V_5 -> V_66 ) ;
}
F_70 ( V_5 ) ;
if ( V_46 )
F_59 ( V_46 ) ;
}
static int F_71 (
struct V_1 * V_2 ,
const struct V_43 * V_72 )
{
int V_40 = V_17 ;
struct V_24 * V_5 = NULL , * V_73 = NULL ;
struct V_3 * V_8 ;
V_8 = F_29 ( V_2 ) ;
if ( V_8 == NULL ) {
F_27 ( V_36 , V_20 , ( L_21 ) ) ;
goto exit;
}
V_5 = F_42 ( V_8 , V_72 ) ;
if ( V_5 == NULL ) {
F_3 ( L_22 ) ;
goto V_42;
}
V_40 = F_72 ( V_5 ) ;
if ( V_40 != V_18 ) {
goto V_74;
}
if ( F_6 ( V_8 ) != V_18 )
goto V_74;
#ifdef F_65
F_16 ( V_5 ) ;
#endif
F_27 ( V_36 , V_20 , ( L_23 ) ) ;
F_73 () ;
V_40 = V_18 ;
V_74:
if ( V_40 != V_18 && V_73 ) {
}
if ( V_40 != V_18 && V_5 ) {
F_61 ( V_5 ) ;
}
V_42:
if ( V_40 != V_18 )
F_34 ( V_2 ) ;
exit:
return V_40 == V_18 ? 0 : - V_75 ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_3 * V_8 = F_2 ( V_2 ) ;
struct V_24 * V_25 = V_8 -> V_5 ;
F_27 ( V_36 , V_37 , ( L_24 ) ) ;
V_8 -> V_76 = true ;
F_75 ( V_8 ) ;
if ( V_25 -> V_62 == false ) {
int V_10 ;
F_7 ( V_2 ) ;
F_76 ( V_2 , 0 , & V_10 ) ;
F_10 ( V_2 ) ;
if ( V_10 == - V_77 ) {
V_25 -> V_62 = true ;
F_3 ( V_78 L_25 , V_6 ) ;
}
}
F_77 ( V_25 , V_79 ) ;
F_78 ( V_25 , V_80 ) ;
F_79 ( V_25 , V_81 ) ;
F_80 ( V_25 ) ;
F_81 ( V_25 ) ;
F_61 ( V_25 ) ;
F_34 ( V_2 ) ;
F_27 ( V_36 , V_37 , ( L_26 ) ) ;
}
static int F_82 ( struct V_82 * V_59 )
{
struct V_1 * V_2 = F_83 ( V_59 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_83 * V_84 = F_84 ( V_4 ) ;
struct V_24 * V_25 = V_4 -> V_5 ;
struct V_85 * V_86 = & V_4 -> V_12 ;
if ( V_25 -> V_47 == true )
{
F_3 ( L_27 , V_6 , V_25 -> V_47 ) ;
return 0 ;
}
if ( V_84 -> V_87 == true )
{
F_3 ( L_28 , V_6 , V_84 -> V_87 ) ;
V_86 -> V_88 ++ ;
return 0 ;
}
return F_85 ( V_25 ) ;
}
static int F_86 ( struct V_24 * V_25 )
{
struct V_83 * V_84 = F_68 ( V_25 ) ;
struct V_3 * V_4 = V_25 -> V_8 ;
struct V_85 * V_86 = & V_4 -> V_12 ;
if ( V_84 -> V_87 == false )
{
V_86 -> V_89 ++ ;
F_3 ( L_28 , V_6 , V_84 -> V_87 ) ;
return - 1 ;
}
return F_87 ( V_25 ) ;
}
static int F_88 ( struct V_82 * V_59 )
{
struct V_1 * V_2 = F_83 ( V_59 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_83 * V_84 = F_84 ( V_4 ) ;
struct V_24 * V_25 = V_4 -> V_5 ;
struct V_90 * V_91 = & V_25 -> V_92 ;
int V_93 = 0 ;
struct V_85 * V_86 = & V_4 -> V_12 ;
F_3 ( L_29 , V_6 , V_7 -> V_94 , V_7 -> V_95 ) ;
V_86 -> V_96 ++ ;
if ( V_84 -> V_97 )
{
V_93 = F_86 ( V_25 ) ;
}
else
{
if ( V_84 -> V_71 || V_84 -> V_98 )
{
V_93 = F_86 ( V_25 ) ;
}
else
{
V_93 = F_86 ( V_25 ) ;
}
}
V_91 -> V_99 = V_100 ;
F_3 ( L_30 , V_6 , V_93 ) ;
return V_93 ;
}
static int T_5 F_89 ( void )
{
int V_93 = 0 ;
F_13 ( V_26 , L_31 ) ;
F_90 ( V_101 ) ;
#ifdef F_91
F_13 ( V_26 , L_32 , F_91 ) ;
#endif
V_102 . V_103 = true ;
F_92 () ;
V_93 = F_93 ( & V_102 . V_104 ) ;
if ( V_93 != 0 )
{
V_102 . V_103 = false ;
F_94 () ;
F_95 () ;
F_3 ( L_33 , V_6 , V_93 ) ;
goto exit;
}
goto exit;
exit:
F_13 ( V_26 , L_34 , V_93 ) ;
return V_93 ;
}
static void T_6 F_96 ( void )
{
F_13 ( V_26 , L_35 ) ;
V_102 . V_103 = false ;
F_97 ( & V_102 . V_104 ) ;
F_94 () ;
F_95 () ;
F_13 ( V_26 , L_36 ) ;
F_98 ( V_101 ) ;
}

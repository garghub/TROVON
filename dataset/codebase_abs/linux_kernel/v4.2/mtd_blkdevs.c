static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 =
F_2 ( V_1 , struct V_2 , V_4 ) ;
V_3 -> V_5 -> V_6 = NULL ;
F_3 ( V_3 -> V_7 ) ;
F_4 ( V_3 -> V_5 ) ;
F_5 ( & V_3 -> V_8 ) ;
F_6 ( V_3 ) ;
}
static struct V_2 * F_7 ( struct V_9 * V_5 )
{
struct V_2 * V_3 ;
F_8 ( & V_10 ) ;
V_3 = V_5 -> V_6 ;
if ( ! V_3 )
goto V_11;
F_9 ( & V_3 -> V_4 ) ;
V_11:
F_10 ( & V_10 ) ;
return V_3 ;
}
static void F_11 ( struct V_2 * V_3 )
{
F_8 ( & V_10 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_10 ( & V_10 ) ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
struct V_14 * V_15 )
{
unsigned long V_16 , V_17 ;
char * V_18 ;
V_16 = F_14 ( V_15 ) << 9 >> V_13 -> V_19 ;
V_17 = F_15 ( V_15 ) >> V_13 -> V_19 ;
V_18 = F_16 ( V_15 -> V_20 ) ;
if ( V_15 -> V_21 != V_22 )
return - V_23 ;
if ( V_15 -> V_24 & V_25 )
return V_13 -> V_26 ( V_3 ) ;
if ( F_14 ( V_15 ) + F_17 ( V_15 ) >
F_18 ( V_15 -> V_27 ) )
return - V_23 ;
if ( V_15 -> V_24 & V_28 )
return V_13 -> V_29 ( V_3 , V_16 , V_17 ) ;
switch( F_19 ( V_15 ) ) {
case V_30 :
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_31 )
if ( V_13 -> V_32 ( V_3 , V_16 , V_18 ) )
return - V_23 ;
F_20 ( V_15 ) ;
return 0 ;
case V_33 :
if ( ! V_13 -> V_34 )
return - V_23 ;
F_20 ( V_15 ) ;
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_31 )
if ( V_13 -> V_34 ( V_3 , V_16 , V_18 ) )
return - V_23 ;
return 0 ;
default:
F_21 ( V_35 L_1 , F_19 ( V_15 ) ) ;
return - V_23 ;
}
}
int F_22 ( struct V_2 * V_3 )
{
return V_3 -> V_36 ;
}
static void F_23 ( struct V_37 * V_38 )
{
struct V_2 * V_3 =
F_2 ( V_38 , struct V_2 , V_38 ) ;
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_39 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = NULL ;
int V_40 = 0 ;
F_24 ( V_7 -> V_41 ) ;
while ( 1 ) {
int V_42 ;
V_3 -> V_36 = false ;
if ( ! V_15 && ! ( V_15 = F_25 ( V_7 ) ) ) {
if ( V_13 -> V_43 && ! V_40 ) {
F_26 ( V_7 -> V_41 ) ;
F_8 ( & V_3 -> V_44 ) ;
V_13 -> V_43 ( V_3 ) ;
F_10 ( & V_3 -> V_44 ) ;
F_24 ( V_7 -> V_41 ) ;
V_40 = ! V_3 -> V_36 ;
continue;
}
break;
}
F_26 ( V_7 -> V_41 ) ;
F_8 ( & V_3 -> V_44 ) ;
V_42 = F_13 ( V_3 -> V_13 , V_3 , V_15 ) ;
F_10 ( & V_3 -> V_44 ) ;
F_24 ( V_7 -> V_41 ) ;
if ( ! F_27 ( V_15 , V_42 ) )
V_15 = NULL ;
V_40 = 0 ;
}
F_26 ( V_7 -> V_41 ) ;
}
static void F_28 ( struct V_39 * V_7 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 = NULL ;
V_3 = V_7 -> V_45 ;
if ( ! V_3 )
while ( ( V_15 = F_25 ( V_7 ) ) != NULL )
F_29 ( V_15 , - V_46 ) ;
else
F_30 ( V_3 -> V_47 , & V_3 -> V_38 ) ;
}
static int F_31 ( struct V_48 * V_49 , T_1 V_50 )
{
struct V_2 * V_3 = F_7 ( V_49 -> V_51 ) ;
int V_52 = 0 ;
if ( ! V_3 )
return - V_53 ;
F_8 ( & V_3 -> V_44 ) ;
F_8 ( & V_54 ) ;
if ( V_3 -> V_55 )
goto V_11;
F_9 ( & V_3 -> V_4 ) ;
F_32 ( V_3 -> V_13 -> V_56 ) ;
if ( ! V_3 -> V_57 )
goto V_11;
if ( V_3 -> V_13 -> V_55 ) {
V_52 = V_3 -> V_13 -> V_55 ( V_3 ) ;
if ( V_52 )
goto V_58;
}
V_52 = F_33 ( V_3 -> V_57 ) ;
if ( V_52 )
goto V_59;
V_3 -> V_60 = V_50 ;
V_11:
V_3 -> V_55 ++ ;
F_10 ( & V_54 ) ;
F_10 ( & V_3 -> V_44 ) ;
F_11 ( V_3 ) ;
return V_52 ;
V_59:
if ( V_3 -> V_13 -> V_61 )
V_3 -> V_13 -> V_61 ( V_3 ) ;
V_58:
F_34 ( V_3 -> V_13 -> V_56 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_10 ( & V_54 ) ;
F_10 ( & V_3 -> V_44 ) ;
F_11 ( V_3 ) ;
return V_52 ;
}
static void F_35 ( struct V_9 * V_5 , T_1 V_50 )
{
struct V_2 * V_3 = F_7 ( V_5 ) ;
if ( ! V_3 )
return;
F_8 ( & V_3 -> V_44 ) ;
F_8 ( & V_54 ) ;
if ( -- V_3 -> V_55 )
goto V_11;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_34 ( V_3 -> V_13 -> V_56 ) ;
if ( V_3 -> V_57 ) {
if ( V_3 -> V_13 -> V_61 )
V_3 -> V_13 -> V_61 ( V_3 ) ;
F_36 ( V_3 -> V_57 ) ;
}
V_11:
F_10 ( & V_54 ) ;
F_10 ( & V_3 -> V_44 ) ;
F_11 ( V_3 ) ;
}
static int F_37 ( struct V_48 * V_49 , struct V_62 * V_63 )
{
struct V_2 * V_3 = F_7 ( V_49 -> V_51 ) ;
int V_52 = - V_64 ;
if ( ! V_3 )
return V_52 ;
F_8 ( & V_3 -> V_44 ) ;
if ( ! V_3 -> V_57 )
goto V_11;
V_52 = V_3 -> V_13 -> V_65 ? V_3 -> V_13 -> V_65 ( V_3 , V_63 ) : - V_66 ;
V_11:
F_10 ( & V_3 -> V_44 ) ;
F_11 ( V_3 ) ;
return V_52 ;
}
static int F_38 ( struct V_48 * V_49 , T_1 V_50 ,
unsigned int V_67 , unsigned long V_68 )
{
struct V_2 * V_3 = F_7 ( V_49 -> V_51 ) ;
int V_52 = - V_64 ;
if ( ! V_3 )
return V_52 ;
F_8 ( & V_3 -> V_44 ) ;
if ( ! V_3 -> V_57 )
goto V_11;
switch ( V_67 ) {
case V_69 :
V_52 = V_3 -> V_13 -> V_26 ? V_3 -> V_13 -> V_26 ( V_3 ) : 0 ;
break;
default:
V_52 = - V_66 ;
}
V_11:
F_10 ( & V_3 -> V_44 ) ;
F_11 ( V_3 ) ;
return V_52 ;
}
int F_39 ( struct V_2 * V_70 )
{
struct V_12 * V_13 = V_70 -> V_13 ;
struct V_2 * V_71 ;
int V_72 = - 1 ;
struct V_9 * V_73 ;
int V_52 ;
if ( F_40 ( & V_54 ) ) {
F_10 ( & V_54 ) ;
F_41 () ;
}
F_8 ( & V_10 ) ;
F_42 (d, &tr->devs, list) {
if ( V_70 -> V_74 == - 1 ) {
if ( V_71 -> V_74 != V_72 + 1 ) {
V_70 -> V_74 = V_72 + 1 ;
F_43 ( & V_70 -> V_8 , & V_71 -> V_8 ) ;
goto V_75;
}
} else if ( V_71 -> V_74 == V_70 -> V_74 ) {
F_10 ( & V_10 ) ;
return - V_76 ;
} else if ( V_71 -> V_74 > V_70 -> V_74 ) {
F_43 ( & V_70 -> V_8 , & V_71 -> V_8 ) ;
goto V_75;
}
V_72 = V_71 -> V_74 ;
}
V_52 = - V_76 ;
if ( V_70 -> V_74 == - 1 )
V_70 -> V_74 = V_72 + 1 ;
if ( V_70 -> V_74 > ( V_77 >> V_13 -> V_78 ) ||
( V_13 -> V_78 && V_70 -> V_74 >= 27 * 26 ) ) {
F_10 ( & V_10 ) ;
goto V_79;
}
F_43 ( & V_70 -> V_8 , & V_13 -> V_80 ) ;
V_75:
F_10 ( & V_10 ) ;
F_44 ( & V_70 -> V_44 ) ;
F_45 ( & V_70 -> V_4 ) ;
if ( ! V_13 -> V_34 )
V_70 -> V_81 = 1 ;
V_52 = - V_82 ;
V_73 = F_46 ( 1 << V_13 -> V_78 ) ;
if ( ! V_73 )
goto V_83;
V_70 -> V_5 = V_73 ;
V_73 -> V_6 = V_70 ;
V_73 -> V_84 = V_13 -> V_84 ;
V_73 -> V_85 = ( V_70 -> V_74 ) << V_13 -> V_78 ;
V_73 -> V_86 = & V_87 ;
if ( V_13 -> V_78 )
if ( V_70 -> V_74 < 26 )
snprintf ( V_73 -> V_88 , sizeof( V_73 -> V_88 ) ,
L_2 , V_13 -> V_89 , 'a' + V_70 -> V_74 ) ;
else
snprintf ( V_73 -> V_88 , sizeof( V_73 -> V_88 ) ,
L_3 , V_13 -> V_89 ,
'a' - 1 + V_70 -> V_74 / 26 ,
'a' + V_70 -> V_74 % 26 ) ;
else
snprintf ( V_73 -> V_88 , sizeof( V_73 -> V_88 ) ,
L_4 , V_13 -> V_89 , V_70 -> V_74 ) ;
F_47 ( V_73 , ( V_70 -> V_90 * V_13 -> V_31 ) >> 9 ) ;
F_48 ( & V_70 -> V_41 ) ;
V_70 -> V_7 = F_49 ( F_28 , & V_70 -> V_41 ) ;
if ( ! V_70 -> V_7 )
goto V_91;
if ( V_13 -> V_26 )
F_50 ( V_70 -> V_7 , V_25 ) ;
V_70 -> V_7 -> V_45 = V_70 ;
F_51 ( V_70 -> V_7 , V_13 -> V_31 ) ;
F_52 ( V_92 , V_70 -> V_7 ) ;
F_53 ( V_93 , V_70 -> V_7 ) ;
if ( V_13 -> V_29 ) {
F_52 ( V_94 , V_70 -> V_7 ) ;
V_70 -> V_7 -> V_95 . V_96 = V_97 ;
}
V_73 -> V_98 = V_70 -> V_7 ;
V_70 -> V_47 = F_54 ( L_4 , 0 , 0 ,
V_13 -> V_89 , V_70 -> V_57 -> V_99 ) ;
if ( ! V_70 -> V_47 )
goto V_100;
F_55 ( & V_70 -> V_38 , F_23 ) ;
V_73 -> V_101 = & V_70 -> V_57 -> V_3 ;
if ( V_70 -> V_81 )
F_56 ( V_73 , 1 ) ;
F_57 ( V_73 ) ;
if ( V_70 -> V_102 ) {
V_52 = F_58 ( & F_59 ( V_73 ) -> V_103 ,
V_70 -> V_102 ) ;
F_60 ( V_52 ) ;
}
return 0 ;
V_100:
F_3 ( V_70 -> V_7 ) ;
V_91:
F_4 ( V_70 -> V_5 ) ;
V_83:
F_5 ( & V_70 -> V_8 ) ;
V_79:
return V_52 ;
}
int F_61 ( struct V_2 * V_104 )
{
unsigned long V_105 ;
if ( F_40 ( & V_54 ) ) {
F_10 ( & V_54 ) ;
F_41 () ;
}
if ( V_104 -> V_102 )
F_62 ( & F_59 ( V_104 -> V_5 ) -> V_103 ,
V_104 -> V_102 ) ;
F_63 ( V_104 -> V_5 ) ;
F_64 ( V_104 -> V_47 ) ;
F_65 ( & V_104 -> V_41 , V_105 ) ;
V_104 -> V_7 -> V_45 = NULL ;
F_66 ( V_104 -> V_7 ) ;
F_67 ( & V_104 -> V_41 , V_105 ) ;
F_8 ( & V_104 -> V_44 ) ;
if ( V_104 -> V_55 ) {
if ( V_104 -> V_13 -> V_61 )
V_104 -> V_13 -> V_61 ( V_104 ) ;
F_36 ( V_104 -> V_57 ) ;
}
V_104 -> V_57 = NULL ;
F_10 ( & V_104 -> V_44 ) ;
F_11 ( V_104 ) ;
return 0 ;
}
static void F_68 ( struct V_106 * V_57 )
{
struct V_12 * V_13 ;
struct V_2 * V_3 , * V_107 ;
F_42 (tr, &blktrans_majors, list)
F_69 (dev, next, &tr->devs, list)
if ( V_3 -> V_57 == V_57 )
V_13 -> V_108 ( V_3 ) ;
}
static void F_70 ( struct V_106 * V_57 )
{
struct V_12 * V_13 ;
if ( V_57 -> type == V_109 )
return;
F_42 (tr, &blktrans_majors, list)
V_13 -> V_110 ( V_13 , V_57 ) ;
}
int F_71 ( struct V_12 * V_13 )
{
struct V_106 * V_57 ;
int V_52 ;
if ( ! V_111 . V_8 . V_107 )
F_72 ( & V_111 ) ;
F_8 ( & V_54 ) ;
V_52 = F_73 ( V_13 -> V_84 , V_13 -> V_89 ) ;
if ( V_52 < 0 ) {
F_21 ( V_112 L_5 ,
V_13 -> V_89 , V_13 -> V_84 , V_52 ) ;
F_10 ( & V_54 ) ;
return V_52 ;
}
if ( V_52 )
V_13 -> V_84 = V_52 ;
V_13 -> V_19 = F_74 ( V_13 -> V_31 ) - 1 ;
F_75 ( & V_13 -> V_80 ) ;
F_76 ( & V_13 -> V_8 , & V_113 ) ;
F_77 (mtd)
if ( V_57 -> type != V_109 )
V_13 -> V_110 ( V_13 , V_57 ) ;
F_10 ( & V_54 ) ;
return 0 ;
}
int F_78 ( struct V_12 * V_13 )
{
struct V_2 * V_3 , * V_107 ;
F_8 ( & V_54 ) ;
F_5 ( & V_13 -> V_8 ) ;
F_69 (dev, next, &tr->devs, list)
V_13 -> V_108 ( V_3 ) ;
F_79 ( V_13 -> V_84 , V_13 -> V_89 ) ;
F_10 ( & V_54 ) ;
F_80 ( ! F_81 ( & V_13 -> V_80 ) ) ;
return 0 ;
}
static void T_2 F_82 ( void )
{
if ( V_111 . V_8 . V_107 )
F_83 ( & V_111 ) ;
}

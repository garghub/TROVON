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
if ( F_19 ( V_15 ) == V_30 ) {
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_31 )
if ( V_13 -> V_32 ( V_3 , V_16 , V_18 ) )
return - V_23 ;
F_20 ( V_15 ) ;
return 0 ;
} else {
if ( ! V_13 -> V_33 )
return - V_23 ;
F_20 ( V_15 ) ;
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_31 )
if ( V_13 -> V_33 ( V_3 , V_16 , V_18 ) )
return - V_23 ;
return 0 ;
}
}
int F_21 ( struct V_2 * V_3 )
{
return V_3 -> V_34 ;
}
static void F_22 ( struct V_35 * V_36 )
{
struct V_2 * V_3 =
F_2 ( V_36 , struct V_2 , V_36 ) ;
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_37 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = NULL ;
int V_38 = 0 ;
F_23 ( V_7 -> V_39 ) ;
while ( 1 ) {
int V_40 ;
V_3 -> V_34 = false ;
if ( ! V_15 && ! ( V_15 = F_24 ( V_7 ) ) ) {
if ( V_13 -> V_41 && ! V_38 ) {
F_25 ( V_7 -> V_39 ) ;
F_8 ( & V_3 -> V_42 ) ;
V_13 -> V_41 ( V_3 ) ;
F_10 ( & V_3 -> V_42 ) ;
F_23 ( V_7 -> V_39 ) ;
V_38 = ! V_3 -> V_34 ;
continue;
}
break;
}
F_25 ( V_7 -> V_39 ) ;
F_8 ( & V_3 -> V_42 ) ;
V_40 = F_13 ( V_3 -> V_13 , V_3 , V_15 ) ;
F_10 ( & V_3 -> V_42 ) ;
F_23 ( V_7 -> V_39 ) ;
if ( ! F_26 ( V_15 , V_40 ) )
V_15 = NULL ;
V_38 = 0 ;
}
F_25 ( V_7 -> V_39 ) ;
}
static void F_27 ( struct V_37 * V_7 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 = NULL ;
V_3 = V_7 -> V_43 ;
if ( ! V_3 )
while ( ( V_15 = F_24 ( V_7 ) ) != NULL )
F_28 ( V_15 , - V_44 ) ;
else
F_29 ( V_3 -> V_45 , & V_3 -> V_36 ) ;
}
static int F_30 ( struct V_46 * V_47 , T_1 V_48 )
{
struct V_2 * V_3 = F_7 ( V_47 -> V_49 ) ;
int V_50 = 0 ;
if ( ! V_3 )
return - V_51 ;
F_8 ( & V_52 ) ;
F_8 ( & V_3 -> V_42 ) ;
if ( V_3 -> V_53 )
goto V_11;
F_9 ( & V_3 -> V_4 ) ;
F_31 ( V_3 -> V_13 -> V_54 ) ;
if ( ! V_3 -> V_55 )
goto V_11;
if ( V_3 -> V_13 -> V_53 ) {
V_50 = V_3 -> V_13 -> V_53 ( V_3 ) ;
if ( V_50 )
goto V_56;
}
V_50 = F_32 ( V_3 -> V_55 ) ;
if ( V_50 )
goto V_57;
V_3 -> V_58 = V_48 ;
V_11:
V_3 -> V_53 ++ ;
F_10 ( & V_3 -> V_42 ) ;
F_10 ( & V_52 ) ;
F_11 ( V_3 ) ;
return V_50 ;
V_57:
if ( V_3 -> V_13 -> V_59 )
V_3 -> V_13 -> V_59 ( V_3 ) ;
V_56:
F_33 ( V_3 -> V_13 -> V_54 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_10 ( & V_3 -> V_42 ) ;
F_10 ( & V_52 ) ;
F_11 ( V_3 ) ;
return V_50 ;
}
static void F_34 ( struct V_9 * V_5 , T_1 V_48 )
{
struct V_2 * V_3 = F_7 ( V_5 ) ;
if ( ! V_3 )
return;
F_8 ( & V_52 ) ;
F_8 ( & V_3 -> V_42 ) ;
if ( -- V_3 -> V_53 )
goto V_11;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_33 ( V_3 -> V_13 -> V_54 ) ;
if ( V_3 -> V_55 ) {
if ( V_3 -> V_13 -> V_59 )
V_3 -> V_13 -> V_59 ( V_3 ) ;
F_35 ( V_3 -> V_55 ) ;
}
V_11:
F_10 ( & V_3 -> V_42 ) ;
F_10 ( & V_52 ) ;
F_11 ( V_3 ) ;
}
static int F_36 ( struct V_46 * V_47 , struct V_60 * V_61 )
{
struct V_2 * V_3 = F_7 ( V_47 -> V_49 ) ;
int V_50 = - V_62 ;
if ( ! V_3 )
return V_50 ;
F_8 ( & V_3 -> V_42 ) ;
if ( ! V_3 -> V_55 )
goto V_11;
V_50 = V_3 -> V_13 -> V_63 ? V_3 -> V_13 -> V_63 ( V_3 , V_61 ) : - V_64 ;
V_11:
F_10 ( & V_3 -> V_42 ) ;
F_11 ( V_3 ) ;
return V_50 ;
}
static int F_37 ( struct V_46 * V_47 , T_1 V_48 ,
unsigned int V_65 , unsigned long V_66 )
{
struct V_2 * V_3 = F_7 ( V_47 -> V_49 ) ;
int V_50 = - V_62 ;
if ( ! V_3 )
return V_50 ;
F_8 ( & V_3 -> V_42 ) ;
if ( ! V_3 -> V_55 )
goto V_11;
switch ( V_65 ) {
case V_67 :
V_50 = V_3 -> V_13 -> V_26 ? V_3 -> V_13 -> V_26 ( V_3 ) : 0 ;
break;
default:
V_50 = - V_64 ;
}
V_11:
F_10 ( & V_3 -> V_42 ) ;
F_11 ( V_3 ) ;
return V_50 ;
}
int F_38 ( struct V_2 * V_68 )
{
struct V_12 * V_13 = V_68 -> V_13 ;
struct V_2 * V_69 ;
int V_70 = - 1 ;
struct V_9 * V_71 ;
int V_50 ;
if ( F_39 ( & V_52 ) ) {
F_10 ( & V_52 ) ;
F_40 () ;
}
F_8 ( & V_10 ) ;
F_41 (d, &tr->devs, list) {
if ( V_68 -> V_72 == - 1 ) {
if ( V_69 -> V_72 != V_70 + 1 ) {
V_68 -> V_72 = V_70 + 1 ;
F_42 ( & V_68 -> V_8 , & V_69 -> V_8 ) ;
goto V_73;
}
} else if ( V_69 -> V_72 == V_68 -> V_72 ) {
F_10 ( & V_10 ) ;
return - V_74 ;
} else if ( V_69 -> V_72 > V_68 -> V_72 ) {
F_42 ( & V_68 -> V_8 , & V_69 -> V_8 ) ;
goto V_73;
}
V_70 = V_69 -> V_72 ;
}
V_50 = - V_74 ;
if ( V_68 -> V_72 == - 1 )
V_68 -> V_72 = V_70 + 1 ;
if ( V_68 -> V_72 > ( V_75 >> V_13 -> V_76 ) ||
( V_13 -> V_76 && V_68 -> V_72 >= 27 * 26 ) ) {
F_10 ( & V_10 ) ;
goto V_77;
}
F_42 ( & V_68 -> V_8 , & V_13 -> V_78 ) ;
V_73:
F_10 ( & V_10 ) ;
F_43 ( & V_68 -> V_42 ) ;
F_44 ( & V_68 -> V_4 ) ;
if ( ! V_13 -> V_33 )
V_68 -> V_79 = 1 ;
V_50 = - V_80 ;
V_71 = F_45 ( 1 << V_13 -> V_76 ) ;
if ( ! V_71 )
goto V_81;
V_68 -> V_5 = V_71 ;
V_71 -> V_6 = V_68 ;
V_71 -> V_82 = V_13 -> V_82 ;
V_71 -> V_83 = ( V_68 -> V_72 ) << V_13 -> V_76 ;
V_71 -> V_84 = & V_85 ;
if ( V_13 -> V_76 )
if ( V_68 -> V_72 < 26 )
snprintf ( V_71 -> V_86 , sizeof( V_71 -> V_86 ) ,
L_1 , V_13 -> V_87 , 'a' + V_68 -> V_72 ) ;
else
snprintf ( V_71 -> V_86 , sizeof( V_71 -> V_86 ) ,
L_2 , V_13 -> V_87 ,
'a' - 1 + V_68 -> V_72 / 26 ,
'a' + V_68 -> V_72 % 26 ) ;
else
snprintf ( V_71 -> V_86 , sizeof( V_71 -> V_86 ) ,
L_3 , V_13 -> V_87 , V_68 -> V_72 ) ;
F_46 ( V_71 , ( ( V_88 ) V_68 -> V_89 * V_13 -> V_31 ) >> 9 ) ;
F_47 ( & V_68 -> V_39 ) ;
V_68 -> V_7 = F_48 ( F_27 , & V_68 -> V_39 ) ;
if ( ! V_68 -> V_7 )
goto V_90;
if ( V_13 -> V_26 )
F_49 ( V_68 -> V_7 , V_25 ) ;
V_68 -> V_7 -> V_43 = V_68 ;
F_50 ( V_68 -> V_7 , V_13 -> V_31 ) ;
F_51 ( V_91 , V_68 -> V_7 ) ;
F_52 ( V_92 , V_68 -> V_7 ) ;
if ( V_13 -> V_29 ) {
F_51 ( V_93 , V_68 -> V_7 ) ;
F_53 ( V_68 -> V_7 , V_94 ) ;
}
V_71 -> V_95 = V_68 -> V_7 ;
V_68 -> V_45 = F_54 ( L_3 , 0 , 0 ,
V_13 -> V_87 , V_68 -> V_55 -> V_96 ) ;
if ( ! V_68 -> V_45 )
goto V_97;
F_55 ( & V_68 -> V_36 , F_22 ) ;
V_71 -> V_98 = & V_68 -> V_55 -> V_3 ;
if ( V_68 -> V_79 )
F_56 ( V_71 , 1 ) ;
F_57 ( V_71 ) ;
if ( V_68 -> V_99 ) {
V_50 = F_58 ( & F_59 ( V_71 ) -> V_100 ,
V_68 -> V_99 ) ;
F_60 ( V_50 ) ;
}
return 0 ;
V_97:
F_3 ( V_68 -> V_7 ) ;
V_90:
F_4 ( V_68 -> V_5 ) ;
V_81:
F_5 ( & V_68 -> V_8 ) ;
V_77:
return V_50 ;
}
int F_61 ( struct V_2 * V_101 )
{
unsigned long V_102 ;
if ( F_39 ( & V_52 ) ) {
F_10 ( & V_52 ) ;
F_40 () ;
}
if ( V_101 -> V_99 )
F_62 ( & F_59 ( V_101 -> V_5 ) -> V_100 ,
V_101 -> V_99 ) ;
F_63 ( V_101 -> V_5 ) ;
F_64 ( V_101 -> V_45 ) ;
F_65 ( & V_101 -> V_39 , V_102 ) ;
V_101 -> V_7 -> V_43 = NULL ;
F_66 ( V_101 -> V_7 ) ;
F_67 ( & V_101 -> V_39 , V_102 ) ;
F_8 ( & V_101 -> V_42 ) ;
if ( V_101 -> V_53 ) {
if ( V_101 -> V_13 -> V_59 )
V_101 -> V_13 -> V_59 ( V_101 ) ;
F_35 ( V_101 -> V_55 ) ;
}
V_101 -> V_55 = NULL ;
F_10 ( & V_101 -> V_42 ) ;
F_11 ( V_101 ) ;
return 0 ;
}
static void F_68 ( struct V_103 * V_55 )
{
struct V_12 * V_13 ;
struct V_2 * V_3 , * V_104 ;
F_41 (tr, &blktrans_majors, list)
F_69 (dev, next, &tr->devs, list)
if ( V_3 -> V_55 == V_55 )
V_13 -> V_105 ( V_3 ) ;
}
static void F_70 ( struct V_103 * V_55 )
{
struct V_12 * V_13 ;
if ( V_55 -> type == V_106 )
return;
F_41 (tr, &blktrans_majors, list)
V_13 -> V_107 ( V_13 , V_55 ) ;
}
int F_71 ( struct V_12 * V_13 )
{
struct V_103 * V_55 ;
int V_50 ;
if ( ! V_108 . V_8 . V_104 )
F_72 ( & V_108 ) ;
F_8 ( & V_52 ) ;
V_50 = F_73 ( V_13 -> V_82 , V_13 -> V_87 ) ;
if ( V_50 < 0 ) {
F_74 ( V_109 L_4 ,
V_13 -> V_87 , V_13 -> V_82 , V_50 ) ;
F_10 ( & V_52 ) ;
return V_50 ;
}
if ( V_50 )
V_13 -> V_82 = V_50 ;
V_13 -> V_19 = F_75 ( V_13 -> V_31 ) - 1 ;
F_76 ( & V_13 -> V_78 ) ;
F_77 ( & V_13 -> V_8 , & V_110 ) ;
F_78 (mtd)
if ( V_55 -> type != V_106 )
V_13 -> V_107 ( V_13 , V_55 ) ;
F_10 ( & V_52 ) ;
return 0 ;
}
int F_79 ( struct V_12 * V_13 )
{
struct V_2 * V_3 , * V_104 ;
F_8 ( & V_52 ) ;
F_5 ( & V_13 -> V_8 ) ;
F_69 (dev, next, &tr->devs, list)
V_13 -> V_105 ( V_3 ) ;
F_80 ( V_13 -> V_82 , V_13 -> V_87 ) ;
F_10 ( & V_52 ) ;
F_81 ( ! F_82 ( & V_13 -> V_78 ) ) ;
return 0 ;
}
static void T_2 F_83 ( void )
{
if ( V_108 . V_8 . V_104 )
F_84 ( & V_108 ) ;
}

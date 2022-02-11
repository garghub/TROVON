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
V_18 = V_15 -> V_20 ;
if ( V_15 -> V_21 != V_22 )
return - V_23 ;
if ( F_14 ( V_15 ) + F_16 ( V_15 ) >
F_17 ( V_15 -> V_24 ) )
return - V_23 ;
if ( V_15 -> V_25 & V_26 )
return V_13 -> V_27 ( V_3 , V_16 , V_17 ) ;
switch( F_18 ( V_15 ) ) {
case V_28 :
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_29 )
if ( V_13 -> V_30 ( V_3 , V_16 , V_18 ) )
return - V_23 ;
F_19 ( V_15 ) ;
return 0 ;
case V_31 :
if ( ! V_13 -> V_32 )
return - V_23 ;
F_19 ( V_15 ) ;
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_29 )
if ( V_13 -> V_32 ( V_3 , V_16 , V_18 ) )
return - V_23 ;
return 0 ;
default:
F_20 ( V_33 L_1 , F_18 ( V_15 ) ) ;
return - V_23 ;
}
}
int F_21 ( struct V_2 * V_3 )
{
if ( F_22 () )
return 1 ;
return V_3 -> V_34 ;
}
static int F_23 ( void * V_35 )
{
struct V_2 * V_3 = V_35 ;
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_36 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = NULL ;
int V_37 = 0 ;
F_24 ( V_7 -> V_38 ) ;
while ( ! F_22 () ) {
int V_39 ;
V_3 -> V_34 = false ;
if ( ! V_15 && ! ( V_15 = F_25 ( V_7 ) ) ) {
if ( V_13 -> V_40 && ! V_37 ) {
F_26 ( V_7 -> V_38 ) ;
F_8 ( & V_3 -> V_41 ) ;
V_13 -> V_40 ( V_3 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_24 ( V_7 -> V_38 ) ;
V_37 = ! V_3 -> V_34 ;
continue;
}
F_27 ( V_42 ) ;
if ( F_22 () )
F_27 ( V_43 ) ;
F_26 ( V_7 -> V_38 ) ;
F_28 () ;
F_24 ( V_7 -> V_38 ) ;
continue;
}
F_26 ( V_7 -> V_38 ) ;
F_8 ( & V_3 -> V_41 ) ;
V_39 = F_13 ( V_3 -> V_13 , V_3 , V_15 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_24 ( V_7 -> V_38 ) ;
if ( ! F_29 ( V_15 , V_39 ) )
V_15 = NULL ;
V_37 = 0 ;
}
if ( V_15 )
F_30 ( V_15 , - V_23 ) ;
F_26 ( V_7 -> V_38 ) ;
return 0 ;
}
static void F_31 ( struct V_36 * V_7 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 = NULL ;
V_3 = V_7 -> V_44 ;
if ( ! V_3 )
while ( ( V_15 = F_25 ( V_7 ) ) != NULL )
F_30 ( V_15 , - V_45 ) ;
else {
V_3 -> V_34 = true ;
F_32 ( V_3 -> V_46 ) ;
}
}
static int F_33 ( struct V_47 * V_48 , T_1 V_49 )
{
struct V_2 * V_3 = F_7 ( V_48 -> V_50 ) ;
int V_51 = 0 ;
if ( ! V_3 )
return - V_52 ;
F_8 ( & V_3 -> V_41 ) ;
if ( V_3 -> V_53 ++ )
goto V_11;
F_9 ( & V_3 -> V_4 ) ;
F_34 ( V_3 -> V_13 -> V_54 ) ;
if ( ! V_3 -> V_55 )
goto V_11;
if ( V_3 -> V_13 -> V_53 ) {
V_51 = V_3 -> V_13 -> V_53 ( V_3 ) ;
if ( V_51 )
goto V_56;
}
V_51 = F_35 ( V_3 -> V_55 ) ;
if ( V_51 )
goto V_57;
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
V_57:
if ( V_3 -> V_13 -> V_58 )
V_3 -> V_13 -> V_58 ( V_3 ) ;
V_56:
F_36 ( V_3 -> V_13 -> V_54 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
}
static int F_37 ( struct V_9 * V_5 , T_1 V_49 )
{
struct V_2 * V_3 = F_7 ( V_5 ) ;
int V_51 = 0 ;
if ( ! V_3 )
return V_51 ;
F_8 ( & V_3 -> V_41 ) ;
if ( -- V_3 -> V_53 )
goto V_11;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_36 ( V_3 -> V_13 -> V_54 ) ;
if ( V_3 -> V_55 ) {
V_51 = V_3 -> V_13 -> V_58 ? V_3 -> V_13 -> V_58 ( V_3 ) : 0 ;
F_38 ( V_3 -> V_55 ) ;
}
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
}
static int F_39 ( struct V_47 * V_48 , struct V_59 * V_60 )
{
struct V_2 * V_3 = F_7 ( V_48 -> V_50 ) ;
int V_51 = - V_61 ;
if ( ! V_3 )
return V_51 ;
F_8 ( & V_3 -> V_41 ) ;
if ( ! V_3 -> V_55 )
goto V_11;
V_51 = V_3 -> V_13 -> V_62 ? V_3 -> V_13 -> V_62 ( V_3 , V_60 ) : 0 ;
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
}
static int F_40 ( struct V_47 * V_48 , T_1 V_49 ,
unsigned int V_63 , unsigned long V_35 )
{
struct V_2 * V_3 = F_7 ( V_48 -> V_50 ) ;
int V_51 = - V_61 ;
if ( ! V_3 )
return V_51 ;
F_8 ( & V_3 -> V_41 ) ;
if ( ! V_3 -> V_55 )
goto V_11;
switch ( V_63 ) {
case V_64 :
V_51 = V_3 -> V_13 -> V_65 ? V_3 -> V_13 -> V_65 ( V_3 ) : 0 ;
break;
default:
V_51 = - V_66 ;
}
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
}
int F_41 ( struct V_2 * V_67 )
{
struct V_12 * V_13 = V_67 -> V_13 ;
struct V_2 * V_68 ;
int V_69 = - 1 ;
struct V_9 * V_70 ;
int V_51 ;
if ( F_42 ( & V_71 ) ) {
F_10 ( & V_71 ) ;
F_43 () ;
}
F_8 ( & V_10 ) ;
F_44 (d, &tr->devs, list) {
if ( V_67 -> V_72 == - 1 ) {
if ( V_68 -> V_72 != V_69 + 1 ) {
V_67 -> V_72 = V_69 + 1 ;
F_45 ( & V_67 -> V_8 , & V_68 -> V_8 ) ;
goto V_73;
}
} else if ( V_68 -> V_72 == V_67 -> V_72 ) {
F_10 ( & V_10 ) ;
return - V_74 ;
} else if ( V_68 -> V_72 > V_67 -> V_72 ) {
F_45 ( & V_67 -> V_8 , & V_68 -> V_8 ) ;
goto V_73;
}
V_69 = V_68 -> V_72 ;
}
V_51 = - V_74 ;
if ( V_67 -> V_72 == - 1 )
V_67 -> V_72 = V_69 + 1 ;
if ( V_67 -> V_72 > ( V_75 >> V_13 -> V_76 ) ||
( V_13 -> V_76 && V_67 -> V_72 >= 27 * 26 ) ) {
F_10 ( & V_10 ) ;
goto V_77;
}
F_45 ( & V_67 -> V_8 , & V_13 -> V_78 ) ;
V_73:
F_10 ( & V_10 ) ;
F_46 ( & V_67 -> V_41 ) ;
F_47 ( & V_67 -> V_4 ) ;
if ( ! V_13 -> V_32 )
V_67 -> V_79 = 1 ;
V_51 = - V_80 ;
V_70 = F_48 ( 1 << V_13 -> V_76 ) ;
if ( ! V_70 )
goto V_81;
V_67 -> V_5 = V_70 ;
V_70 -> V_6 = V_67 ;
V_70 -> V_82 = V_13 -> V_82 ;
V_70 -> V_83 = ( V_67 -> V_72 ) << V_13 -> V_76 ;
V_70 -> V_84 = & V_12 ;
if ( V_13 -> V_76 )
if ( V_67 -> V_72 < 26 )
snprintf ( V_70 -> V_85 , sizeof( V_70 -> V_85 ) ,
L_2 , V_13 -> V_86 , 'a' + V_67 -> V_72 ) ;
else
snprintf ( V_70 -> V_85 , sizeof( V_70 -> V_85 ) ,
L_3 , V_13 -> V_86 ,
'a' - 1 + V_67 -> V_72 / 26 ,
'a' + V_67 -> V_72 % 26 ) ;
else
snprintf ( V_70 -> V_85 , sizeof( V_70 -> V_85 ) ,
L_4 , V_13 -> V_86 , V_67 -> V_72 ) ;
F_49 ( V_70 , ( V_67 -> V_87 * V_13 -> V_29 ) >> 9 ) ;
F_50 ( & V_67 -> V_38 ) ;
V_67 -> V_7 = F_51 ( F_31 , & V_67 -> V_38 ) ;
if ( ! V_67 -> V_7 )
goto V_88;
V_67 -> V_7 -> V_44 = V_67 ;
F_52 ( V_67 -> V_7 , V_13 -> V_29 ) ;
F_53 ( V_89 , V_67 -> V_7 ) ;
if ( V_13 -> V_27 ) {
F_53 ( V_90 , V_67 -> V_7 ) ;
V_67 -> V_7 -> V_91 . V_92 = V_93 ;
}
V_70 -> V_94 = V_67 -> V_7 ;
V_67 -> V_46 = F_54 ( F_23 , V_67 ,
L_4 , V_13 -> V_86 , V_67 -> V_55 -> V_95 ) ;
if ( F_55 ( V_67 -> V_46 ) ) {
V_51 = F_56 ( V_67 -> V_46 ) ;
goto V_96;
}
V_70 -> V_97 = & V_67 -> V_55 -> V_3 ;
if ( V_67 -> V_79 )
F_57 ( V_70 , 1 ) ;
F_58 ( V_70 ) ;
if ( V_67 -> V_98 ) {
V_51 = F_59 ( & F_60 ( V_70 ) -> V_99 ,
V_67 -> V_98 ) ;
F_61 ( V_51 ) ;
}
return 0 ;
V_96:
F_3 ( V_67 -> V_7 ) ;
V_88:
F_4 ( V_67 -> V_5 ) ;
V_81:
F_5 ( & V_67 -> V_8 ) ;
V_77:
return V_51 ;
}
int F_62 ( struct V_2 * V_100 )
{
unsigned long V_101 ;
if ( F_42 ( & V_71 ) ) {
F_10 ( & V_71 ) ;
F_43 () ;
}
if ( V_100 -> V_98 )
F_63 ( & F_60 ( V_100 -> V_5 ) -> V_99 ,
V_100 -> V_98 ) ;
F_64 ( V_100 -> V_5 ) ;
F_65 ( V_100 -> V_46 ) ;
F_66 ( & V_100 -> V_38 , V_101 ) ;
V_100 -> V_7 -> V_44 = NULL ;
F_67 ( V_100 -> V_7 ) ;
F_68 ( & V_100 -> V_38 , V_101 ) ;
F_8 ( & V_100 -> V_41 ) ;
if ( V_100 -> V_53 ) {
if ( V_100 -> V_13 -> V_58 )
V_100 -> V_13 -> V_58 ( V_100 ) ;
F_38 ( V_100 -> V_55 ) ;
}
V_100 -> V_55 = NULL ;
F_10 ( & V_100 -> V_41 ) ;
F_11 ( V_100 ) ;
return 0 ;
}
static void F_69 ( struct V_102 * V_55 )
{
struct V_12 * V_13 ;
struct V_2 * V_3 , * V_103 ;
F_44 (tr, &blktrans_majors, list)
F_70 (dev, next, &tr->devs, list)
if ( V_3 -> V_55 == V_55 )
V_13 -> V_104 ( V_3 ) ;
}
static void F_71 ( struct V_102 * V_55 )
{
struct V_12 * V_13 ;
if ( V_55 -> type == V_105 )
return;
F_44 (tr, &blktrans_majors, list)
V_13 -> V_106 ( V_13 , V_55 ) ;
}
int F_72 ( struct V_12 * V_13 )
{
struct V_102 * V_55 ;
int V_51 ;
if ( ! V_107 . V_8 . V_103 )
F_73 ( & V_107 ) ;
F_8 ( & V_71 ) ;
V_51 = F_74 ( V_13 -> V_82 , V_13 -> V_86 ) ;
if ( V_51 < 0 ) {
F_20 ( V_108 L_5 ,
V_13 -> V_86 , V_13 -> V_82 , V_51 ) ;
F_10 ( & V_71 ) ;
return V_51 ;
}
if ( V_51 )
V_13 -> V_82 = V_51 ;
V_13 -> V_19 = F_75 ( V_13 -> V_29 ) - 1 ;
F_76 ( & V_13 -> V_78 ) ;
F_77 ( & V_13 -> V_8 , & V_109 ) ;
F_78 (mtd)
if ( V_55 -> type != V_105 )
V_13 -> V_106 ( V_13 , V_55 ) ;
F_10 ( & V_71 ) ;
return 0 ;
}
int F_79 ( struct V_12 * V_13 )
{
struct V_2 * V_3 , * V_103 ;
F_8 ( & V_71 ) ;
F_5 ( & V_13 -> V_8 ) ;
F_70 (dev, next, &tr->devs, list)
V_13 -> V_104 ( V_3 ) ;
F_80 ( V_13 -> V_82 , V_13 -> V_86 ) ;
F_10 ( & V_71 ) ;
F_81 ( ! F_82 ( & V_13 -> V_78 ) ) ;
return 0 ;
}
static void T_2 F_83 ( void )
{
if ( V_107 . V_8 . V_103 )
F_84 ( & V_107 ) ;
}

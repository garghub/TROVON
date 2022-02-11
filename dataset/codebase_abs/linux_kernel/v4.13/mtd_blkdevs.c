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
static T_1 F_13 ( struct V_12 * V_13 ,
struct V_2 * V_3 ,
struct V_14 * V_15 )
{
unsigned long V_16 , V_17 ;
char * V_18 ;
V_16 = F_14 ( V_15 ) << 9 >> V_13 -> V_19 ;
V_17 = F_15 ( V_15 ) >> V_13 -> V_19 ;
V_18 = F_16 ( V_15 -> V_20 ) ;
if ( F_17 ( V_15 ) == V_21 ) {
if ( V_13 -> V_22 ( V_3 ) )
return V_23 ;
return V_24 ;
}
if ( F_14 ( V_15 ) + F_18 ( V_15 ) >
F_19 ( V_15 -> V_25 ) )
return V_23 ;
switch ( F_17 ( V_15 ) ) {
case V_26 :
if ( V_13 -> V_27 ( V_3 , V_16 , V_17 ) )
return V_23 ;
return V_24 ;
case V_28 :
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_29 )
if ( V_13 -> V_30 ( V_3 , V_16 , V_18 ) )
return V_23 ;
F_20 ( V_15 ) ;
return V_24 ;
case V_31 :
if ( ! V_13 -> V_32 )
return V_23 ;
F_20 ( V_15 ) ;
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_29 )
if ( V_13 -> V_32 ( V_3 , V_16 , V_18 ) )
return V_23 ;
return V_24 ;
default:
return V_23 ;
}
}
int F_21 ( struct V_2 * V_3 )
{
return V_3 -> V_33 ;
}
static void F_22 ( struct V_34 * V_35 )
{
struct V_2 * V_3 =
F_2 ( V_35 , struct V_2 , V_35 ) ;
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_36 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = NULL ;
int V_37 = 0 ;
F_23 ( V_7 -> V_38 ) ;
while ( 1 ) {
T_1 V_39 ;
V_3 -> V_33 = false ;
if ( ! V_15 && ! ( V_15 = F_24 ( V_7 ) ) ) {
if ( V_13 -> V_40 && ! V_37 ) {
F_25 ( V_7 -> V_38 ) ;
F_8 ( & V_3 -> V_41 ) ;
V_13 -> V_40 ( V_3 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_23 ( V_7 -> V_38 ) ;
V_37 = ! V_3 -> V_33 ;
continue;
}
break;
}
F_25 ( V_7 -> V_38 ) ;
F_8 ( & V_3 -> V_41 ) ;
V_39 = F_13 ( V_3 -> V_13 , V_3 , V_15 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_23 ( V_7 -> V_38 ) ;
if ( ! F_26 ( V_15 , V_39 ) )
V_15 = NULL ;
V_37 = 0 ;
}
F_25 ( V_7 -> V_38 ) ;
}
static void F_27 ( struct V_36 * V_7 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 = NULL ;
V_3 = V_7 -> V_42 ;
if ( ! V_3 )
while ( ( V_15 = F_24 ( V_7 ) ) != NULL )
F_28 ( V_15 , V_23 ) ;
else
F_29 ( V_3 -> V_43 , & V_3 -> V_35 ) ;
}
static int F_30 ( struct V_44 * V_45 , T_2 V_46 )
{
struct V_2 * V_3 = F_7 ( V_45 -> V_47 ) ;
int V_48 = 0 ;
if ( ! V_3 )
return - V_49 ;
F_8 ( & V_50 ) ;
F_8 ( & V_3 -> V_41 ) ;
if ( V_3 -> V_51 )
goto V_11;
F_9 ( & V_3 -> V_4 ) ;
F_31 ( V_3 -> V_13 -> V_52 ) ;
if ( ! V_3 -> V_53 )
goto V_11;
if ( V_3 -> V_13 -> V_51 ) {
V_48 = V_3 -> V_13 -> V_51 ( V_3 ) ;
if ( V_48 )
goto V_54;
}
V_48 = F_32 ( V_3 -> V_53 ) ;
if ( V_48 )
goto V_55;
V_3 -> V_56 = V_46 ;
V_11:
V_3 -> V_51 ++ ;
F_10 ( & V_3 -> V_41 ) ;
F_10 ( & V_50 ) ;
F_11 ( V_3 ) ;
return V_48 ;
V_55:
if ( V_3 -> V_13 -> V_57 )
V_3 -> V_13 -> V_57 ( V_3 ) ;
V_54:
F_33 ( V_3 -> V_13 -> V_52 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_10 ( & V_50 ) ;
F_11 ( V_3 ) ;
return V_48 ;
}
static void F_34 ( struct V_9 * V_5 , T_2 V_46 )
{
struct V_2 * V_3 = F_7 ( V_5 ) ;
if ( ! V_3 )
return;
F_8 ( & V_50 ) ;
F_8 ( & V_3 -> V_41 ) ;
if ( -- V_3 -> V_51 )
goto V_11;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_33 ( V_3 -> V_13 -> V_52 ) ;
if ( V_3 -> V_53 ) {
if ( V_3 -> V_13 -> V_57 )
V_3 -> V_13 -> V_57 ( V_3 ) ;
F_35 ( V_3 -> V_53 ) ;
}
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_10 ( & V_50 ) ;
F_11 ( V_3 ) ;
}
static int F_36 ( struct V_44 * V_45 , struct V_58 * V_59 )
{
struct V_2 * V_3 = F_7 ( V_45 -> V_47 ) ;
int V_48 = - V_60 ;
if ( ! V_3 )
return V_48 ;
F_8 ( & V_3 -> V_41 ) ;
if ( ! V_3 -> V_53 )
goto V_11;
V_48 = V_3 -> V_13 -> V_61 ? V_3 -> V_13 -> V_61 ( V_3 , V_59 ) : - V_62 ;
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_48 ;
}
static int F_37 ( struct V_44 * V_45 , T_2 V_46 ,
unsigned int V_63 , unsigned long V_64 )
{
struct V_2 * V_3 = F_7 ( V_45 -> V_47 ) ;
int V_48 = - V_60 ;
if ( ! V_3 )
return V_48 ;
F_8 ( & V_3 -> V_41 ) ;
if ( ! V_3 -> V_53 )
goto V_11;
switch ( V_63 ) {
case V_65 :
V_48 = V_3 -> V_13 -> V_22 ? V_3 -> V_13 -> V_22 ( V_3 ) : 0 ;
break;
default:
V_48 = - V_62 ;
}
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_48 ;
}
int F_38 ( struct V_2 * V_66 )
{
struct V_12 * V_13 = V_66 -> V_13 ;
struct V_2 * V_67 ;
int V_68 = - 1 ;
struct V_9 * V_69 ;
int V_48 ;
if ( F_39 ( & V_50 ) ) {
F_10 ( & V_50 ) ;
F_40 () ;
}
F_8 ( & V_10 ) ;
F_41 (d, &tr->devs, list) {
if ( V_66 -> V_70 == - 1 ) {
if ( V_67 -> V_70 != V_68 + 1 ) {
V_66 -> V_70 = V_68 + 1 ;
F_42 ( & V_66 -> V_8 , & V_67 -> V_8 ) ;
goto V_71;
}
} else if ( V_67 -> V_70 == V_66 -> V_70 ) {
F_10 ( & V_10 ) ;
return - V_72 ;
} else if ( V_67 -> V_70 > V_66 -> V_70 ) {
F_42 ( & V_66 -> V_8 , & V_67 -> V_8 ) ;
goto V_71;
}
V_68 = V_67 -> V_70 ;
}
V_48 = - V_72 ;
if ( V_66 -> V_70 == - 1 )
V_66 -> V_70 = V_68 + 1 ;
if ( V_66 -> V_70 > ( V_73 >> V_13 -> V_74 ) ||
( V_13 -> V_74 && V_66 -> V_70 >= 27 * 26 ) ) {
F_10 ( & V_10 ) ;
goto V_75;
}
F_42 ( & V_66 -> V_8 , & V_13 -> V_76 ) ;
V_71:
F_10 ( & V_10 ) ;
F_43 ( & V_66 -> V_41 ) ;
F_44 ( & V_66 -> V_4 ) ;
if ( ! V_13 -> V_32 )
V_66 -> V_77 = 1 ;
V_48 = - V_78 ;
V_69 = F_45 ( 1 << V_13 -> V_74 ) ;
if ( ! V_69 )
goto V_79;
V_66 -> V_5 = V_69 ;
V_69 -> V_6 = V_66 ;
V_69 -> V_80 = V_13 -> V_80 ;
V_69 -> V_81 = ( V_66 -> V_70 ) << V_13 -> V_74 ;
V_69 -> V_82 = & V_83 ;
if ( V_13 -> V_74 )
if ( V_66 -> V_70 < 26 )
snprintf ( V_69 -> V_84 , sizeof( V_69 -> V_84 ) ,
L_1 , V_13 -> V_85 , 'a' + V_66 -> V_70 ) ;
else
snprintf ( V_69 -> V_84 , sizeof( V_69 -> V_84 ) ,
L_2 , V_13 -> V_85 ,
'a' - 1 + V_66 -> V_70 / 26 ,
'a' + V_66 -> V_70 % 26 ) ;
else
snprintf ( V_69 -> V_84 , sizeof( V_69 -> V_84 ) ,
L_3 , V_13 -> V_85 , V_66 -> V_70 ) ;
F_46 ( V_69 , ( ( V_86 ) V_66 -> V_87 * V_13 -> V_29 ) >> 9 ) ;
F_47 ( & V_66 -> V_38 ) ;
V_66 -> V_7 = F_48 ( F_27 , & V_66 -> V_38 ) ;
if ( ! V_66 -> V_7 )
goto V_88;
if ( V_13 -> V_22 )
F_49 ( V_66 -> V_7 , true , false ) ;
V_66 -> V_7 -> V_42 = V_66 ;
F_50 ( V_66 -> V_7 , V_13 -> V_29 ) ;
F_51 ( V_66 -> V_7 , V_89 ) ;
F_52 ( V_90 , V_66 -> V_7 ) ;
F_53 ( V_91 , V_66 -> V_7 ) ;
if ( V_13 -> V_27 ) {
F_52 ( V_92 , V_66 -> V_7 ) ;
F_54 ( V_66 -> V_7 , V_93 ) ;
}
V_69 -> V_94 = V_66 -> V_7 ;
V_66 -> V_43 = F_55 ( L_3 , 0 , 0 ,
V_13 -> V_85 , V_66 -> V_53 -> V_95 ) ;
if ( ! V_66 -> V_43 )
goto V_96;
F_56 ( & V_66 -> V_35 , F_22 ) ;
if ( V_66 -> V_77 )
F_57 ( V_69 , 1 ) ;
F_58 ( & V_66 -> V_53 -> V_3 , V_69 ) ;
if ( V_66 -> V_97 ) {
V_48 = F_59 ( & F_60 ( V_69 ) -> V_98 ,
V_66 -> V_97 ) ;
F_61 ( V_48 ) ;
}
return 0 ;
V_96:
F_3 ( V_66 -> V_7 ) ;
V_88:
F_4 ( V_66 -> V_5 ) ;
V_79:
F_5 ( & V_66 -> V_8 ) ;
V_75:
return V_48 ;
}
int F_62 ( struct V_2 * V_99 )
{
unsigned long V_100 ;
if ( F_39 ( & V_50 ) ) {
F_10 ( & V_50 ) ;
F_40 () ;
}
if ( V_99 -> V_97 )
F_63 ( & F_60 ( V_99 -> V_5 ) -> V_98 ,
V_99 -> V_97 ) ;
F_64 ( V_99 -> V_5 ) ;
F_65 ( V_99 -> V_43 ) ;
F_66 ( & V_99 -> V_38 , V_100 ) ;
V_99 -> V_7 -> V_42 = NULL ;
F_67 ( V_99 -> V_7 ) ;
F_68 ( & V_99 -> V_38 , V_100 ) ;
F_8 ( & V_99 -> V_41 ) ;
if ( V_99 -> V_51 ) {
if ( V_99 -> V_13 -> V_57 )
V_99 -> V_13 -> V_57 ( V_99 ) ;
F_35 ( V_99 -> V_53 ) ;
}
V_99 -> V_53 = NULL ;
F_10 ( & V_99 -> V_41 ) ;
F_11 ( V_99 ) ;
return 0 ;
}
static void F_69 ( struct V_101 * V_53 )
{
struct V_12 * V_13 ;
struct V_2 * V_3 , * V_102 ;
F_41 (tr, &blktrans_majors, list)
F_70 (dev, next, &tr->devs, list)
if ( V_3 -> V_53 == V_53 )
V_13 -> V_103 ( V_3 ) ;
}
static void F_71 ( struct V_101 * V_53 )
{
struct V_12 * V_13 ;
if ( V_53 -> type == V_104 )
return;
F_41 (tr, &blktrans_majors, list)
V_13 -> V_105 ( V_13 , V_53 ) ;
}
int F_72 ( struct V_12 * V_13 )
{
struct V_101 * V_53 ;
int V_48 ;
if ( ! V_106 . V_8 . V_102 )
F_73 ( & V_106 ) ;
F_8 ( & V_50 ) ;
V_48 = F_74 ( V_13 -> V_80 , V_13 -> V_85 ) ;
if ( V_48 < 0 ) {
F_75 ( V_107 L_4 ,
V_13 -> V_85 , V_13 -> V_80 , V_48 ) ;
F_10 ( & V_50 ) ;
return V_48 ;
}
if ( V_48 )
V_13 -> V_80 = V_48 ;
V_13 -> V_19 = F_76 ( V_13 -> V_29 ) - 1 ;
F_77 ( & V_13 -> V_76 ) ;
F_78 ( & V_13 -> V_8 , & V_108 ) ;
F_79 (mtd)
if ( V_53 -> type != V_104 )
V_13 -> V_105 ( V_13 , V_53 ) ;
F_10 ( & V_50 ) ;
return 0 ;
}
int F_80 ( struct V_12 * V_13 )
{
struct V_2 * V_3 , * V_102 ;
F_8 ( & V_50 ) ;
F_5 ( & V_13 -> V_8 ) ;
F_70 (dev, next, &tr->devs, list)
V_13 -> V_103 ( V_3 ) ;
F_81 ( V_13 -> V_80 , V_13 -> V_85 ) ;
F_10 ( & V_50 ) ;
F_82 ( ! F_83 ( & V_13 -> V_76 ) ) ;
return 0 ;
}
static void T_3 F_84 ( void )
{
if ( V_106 . V_8 . V_102 )
F_85 ( & V_106 ) ;
}

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
if ( F_17 ( V_15 ) == V_24 )
return V_13 -> V_25 ( V_3 ) ;
if ( F_14 ( V_15 ) + F_18 ( V_15 ) >
F_19 ( V_15 -> V_26 ) )
return - V_23 ;
if ( F_17 ( V_15 ) == V_27 )
return V_13 -> V_28 ( V_3 , V_16 , V_17 ) ;
if ( F_20 ( V_15 ) == V_29 ) {
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_30 )
if ( V_13 -> V_31 ( V_3 , V_16 , V_18 ) )
return - V_23 ;
F_21 ( V_15 ) ;
return 0 ;
} else {
if ( ! V_13 -> V_32 )
return - V_23 ;
F_21 ( V_15 ) ;
for (; V_17 > 0 ; V_17 -- , V_16 ++ , V_18 += V_13 -> V_30 )
if ( V_13 -> V_32 ( V_3 , V_16 , V_18 ) )
return - V_23 ;
return 0 ;
}
}
int F_22 ( struct V_2 * V_3 )
{
return V_3 -> V_33 ;
}
static void F_23 ( struct V_34 * V_35 )
{
struct V_2 * V_3 =
F_2 ( V_35 , struct V_2 , V_35 ) ;
struct V_12 * V_13 = V_3 -> V_13 ;
struct V_36 * V_7 = V_3 -> V_7 ;
struct V_14 * V_15 = NULL ;
int V_37 = 0 ;
F_24 ( V_7 -> V_38 ) ;
while ( 1 ) {
int V_39 ;
V_3 -> V_33 = false ;
if ( ! V_15 && ! ( V_15 = F_25 ( V_7 ) ) ) {
if ( V_13 -> V_40 && ! V_37 ) {
F_26 ( V_7 -> V_38 ) ;
F_8 ( & V_3 -> V_41 ) ;
V_13 -> V_40 ( V_3 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_24 ( V_7 -> V_38 ) ;
V_37 = ! V_3 -> V_33 ;
continue;
}
break;
}
F_26 ( V_7 -> V_38 ) ;
F_8 ( & V_3 -> V_41 ) ;
V_39 = F_13 ( V_3 -> V_13 , V_3 , V_15 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_24 ( V_7 -> V_38 ) ;
if ( ! F_27 ( V_15 , V_39 ) )
V_15 = NULL ;
V_37 = 0 ;
}
F_26 ( V_7 -> V_38 ) ;
}
static void F_28 ( struct V_36 * V_7 )
{
struct V_2 * V_3 ;
struct V_14 * V_15 = NULL ;
V_3 = V_7 -> V_42 ;
if ( ! V_3 )
while ( ( V_15 = F_25 ( V_7 ) ) != NULL )
F_29 ( V_15 , - V_43 ) ;
else
F_30 ( V_3 -> V_44 , & V_3 -> V_35 ) ;
}
static int F_31 ( struct V_45 * V_46 , T_1 V_47 )
{
struct V_2 * V_3 = F_7 ( V_46 -> V_48 ) ;
int V_49 = 0 ;
if ( ! V_3 )
return - V_50 ;
F_8 ( & V_51 ) ;
F_8 ( & V_3 -> V_41 ) ;
if ( V_3 -> V_52 )
goto V_11;
F_9 ( & V_3 -> V_4 ) ;
F_32 ( V_3 -> V_13 -> V_53 ) ;
if ( ! V_3 -> V_54 )
goto V_11;
if ( V_3 -> V_13 -> V_52 ) {
V_49 = V_3 -> V_13 -> V_52 ( V_3 ) ;
if ( V_49 )
goto V_55;
}
V_49 = F_33 ( V_3 -> V_54 ) ;
if ( V_49 )
goto V_56;
V_3 -> V_57 = V_47 ;
V_11:
V_3 -> V_52 ++ ;
F_10 ( & V_3 -> V_41 ) ;
F_10 ( & V_51 ) ;
F_11 ( V_3 ) ;
return V_49 ;
V_56:
if ( V_3 -> V_13 -> V_58 )
V_3 -> V_13 -> V_58 ( V_3 ) ;
V_55:
F_34 ( V_3 -> V_13 -> V_53 ) ;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_10 ( & V_3 -> V_41 ) ;
F_10 ( & V_51 ) ;
F_11 ( V_3 ) ;
return V_49 ;
}
static void F_35 ( struct V_9 * V_5 , T_1 V_47 )
{
struct V_2 * V_3 = F_7 ( V_5 ) ;
if ( ! V_3 )
return;
F_8 ( & V_51 ) ;
F_8 ( & V_3 -> V_41 ) ;
if ( -- V_3 -> V_52 )
goto V_11;
F_12 ( & V_3 -> V_4 , F_1 ) ;
F_34 ( V_3 -> V_13 -> V_53 ) ;
if ( V_3 -> V_54 ) {
if ( V_3 -> V_13 -> V_58 )
V_3 -> V_13 -> V_58 ( V_3 ) ;
F_36 ( V_3 -> V_54 ) ;
}
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_10 ( & V_51 ) ;
F_11 ( V_3 ) ;
}
static int F_37 ( struct V_45 * V_46 , struct V_59 * V_60 )
{
struct V_2 * V_3 = F_7 ( V_46 -> V_48 ) ;
int V_49 = - V_61 ;
if ( ! V_3 )
return V_49 ;
F_8 ( & V_3 -> V_41 ) ;
if ( ! V_3 -> V_54 )
goto V_11;
V_49 = V_3 -> V_13 -> V_62 ? V_3 -> V_13 -> V_62 ( V_3 , V_60 ) : - V_63 ;
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_49 ;
}
static int F_38 ( struct V_45 * V_46 , T_1 V_47 ,
unsigned int V_64 , unsigned long V_65 )
{
struct V_2 * V_3 = F_7 ( V_46 -> V_48 ) ;
int V_49 = - V_61 ;
if ( ! V_3 )
return V_49 ;
F_8 ( & V_3 -> V_41 ) ;
if ( ! V_3 -> V_54 )
goto V_11;
switch ( V_64 ) {
case V_66 :
V_49 = V_3 -> V_13 -> V_25 ? V_3 -> V_13 -> V_25 ( V_3 ) : 0 ;
break;
default:
V_49 = - V_63 ;
}
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_49 ;
}
int F_39 ( struct V_2 * V_67 )
{
struct V_12 * V_13 = V_67 -> V_13 ;
struct V_2 * V_68 ;
int V_69 = - 1 ;
struct V_9 * V_70 ;
int V_49 ;
if ( F_40 ( & V_51 ) ) {
F_10 ( & V_51 ) ;
F_41 () ;
}
F_8 ( & V_10 ) ;
F_42 (d, &tr->devs, list) {
if ( V_67 -> V_71 == - 1 ) {
if ( V_68 -> V_71 != V_69 + 1 ) {
V_67 -> V_71 = V_69 + 1 ;
F_43 ( & V_67 -> V_8 , & V_68 -> V_8 ) ;
goto V_72;
}
} else if ( V_68 -> V_71 == V_67 -> V_71 ) {
F_10 ( & V_10 ) ;
return - V_73 ;
} else if ( V_68 -> V_71 > V_67 -> V_71 ) {
F_43 ( & V_67 -> V_8 , & V_68 -> V_8 ) ;
goto V_72;
}
V_69 = V_68 -> V_71 ;
}
V_49 = - V_73 ;
if ( V_67 -> V_71 == - 1 )
V_67 -> V_71 = V_69 + 1 ;
if ( V_67 -> V_71 > ( V_74 >> V_13 -> V_75 ) ||
( V_13 -> V_75 && V_67 -> V_71 >= 27 * 26 ) ) {
F_10 ( & V_10 ) ;
goto V_76;
}
F_43 ( & V_67 -> V_8 , & V_13 -> V_77 ) ;
V_72:
F_10 ( & V_10 ) ;
F_44 ( & V_67 -> V_41 ) ;
F_45 ( & V_67 -> V_4 ) ;
if ( ! V_13 -> V_32 )
V_67 -> V_78 = 1 ;
V_49 = - V_79 ;
V_70 = F_46 ( 1 << V_13 -> V_75 ) ;
if ( ! V_70 )
goto V_80;
V_67 -> V_5 = V_70 ;
V_70 -> V_6 = V_67 ;
V_70 -> V_81 = V_13 -> V_81 ;
V_70 -> V_82 = ( V_67 -> V_71 ) << V_13 -> V_75 ;
V_70 -> V_83 = & V_84 ;
if ( V_13 -> V_75 )
if ( V_67 -> V_71 < 26 )
snprintf ( V_70 -> V_85 , sizeof( V_70 -> V_85 ) ,
L_1 , V_13 -> V_86 , 'a' + V_67 -> V_71 ) ;
else
snprintf ( V_70 -> V_85 , sizeof( V_70 -> V_85 ) ,
L_2 , V_13 -> V_86 ,
'a' - 1 + V_67 -> V_71 / 26 ,
'a' + V_67 -> V_71 % 26 ) ;
else
snprintf ( V_70 -> V_85 , sizeof( V_70 -> V_85 ) ,
L_3 , V_13 -> V_86 , V_67 -> V_71 ) ;
F_47 ( V_70 , ( ( V_87 ) V_67 -> V_88 * V_13 -> V_30 ) >> 9 ) ;
F_48 ( & V_67 -> V_38 ) ;
V_67 -> V_7 = F_49 ( F_28 , & V_67 -> V_38 ) ;
if ( ! V_67 -> V_7 )
goto V_89;
if ( V_13 -> V_25 )
F_50 ( V_67 -> V_7 , true , false ) ;
V_67 -> V_7 -> V_42 = V_67 ;
F_51 ( V_67 -> V_7 , V_13 -> V_30 ) ;
F_52 ( V_90 , V_67 -> V_7 ) ;
F_53 ( V_91 , V_67 -> V_7 ) ;
if ( V_13 -> V_28 ) {
F_52 ( V_92 , V_67 -> V_7 ) ;
F_54 ( V_67 -> V_7 , V_93 ) ;
}
V_70 -> V_94 = V_67 -> V_7 ;
V_67 -> V_44 = F_55 ( L_3 , 0 , 0 ,
V_13 -> V_86 , V_67 -> V_54 -> V_95 ) ;
if ( ! V_67 -> V_44 )
goto V_96;
F_56 ( & V_67 -> V_35 , F_23 ) ;
if ( V_67 -> V_78 )
F_57 ( V_70 , 1 ) ;
F_58 ( & V_67 -> V_54 -> V_3 , V_70 ) ;
if ( V_67 -> V_97 ) {
V_49 = F_59 ( & F_60 ( V_70 ) -> V_98 ,
V_67 -> V_97 ) ;
F_61 ( V_49 ) ;
}
return 0 ;
V_96:
F_3 ( V_67 -> V_7 ) ;
V_89:
F_4 ( V_67 -> V_5 ) ;
V_80:
F_5 ( & V_67 -> V_8 ) ;
V_76:
return V_49 ;
}
int F_62 ( struct V_2 * V_99 )
{
unsigned long V_100 ;
if ( F_40 ( & V_51 ) ) {
F_10 ( & V_51 ) ;
F_41 () ;
}
if ( V_99 -> V_97 )
F_63 ( & F_60 ( V_99 -> V_5 ) -> V_98 ,
V_99 -> V_97 ) ;
F_64 ( V_99 -> V_5 ) ;
F_65 ( V_99 -> V_44 ) ;
F_66 ( & V_99 -> V_38 , V_100 ) ;
V_99 -> V_7 -> V_42 = NULL ;
F_67 ( V_99 -> V_7 ) ;
F_68 ( & V_99 -> V_38 , V_100 ) ;
F_8 ( & V_99 -> V_41 ) ;
if ( V_99 -> V_52 ) {
if ( V_99 -> V_13 -> V_58 )
V_99 -> V_13 -> V_58 ( V_99 ) ;
F_36 ( V_99 -> V_54 ) ;
}
V_99 -> V_54 = NULL ;
F_10 ( & V_99 -> V_41 ) ;
F_11 ( V_99 ) ;
return 0 ;
}
static void F_69 ( struct V_101 * V_54 )
{
struct V_12 * V_13 ;
struct V_2 * V_3 , * V_102 ;
F_42 (tr, &blktrans_majors, list)
F_70 (dev, next, &tr->devs, list)
if ( V_3 -> V_54 == V_54 )
V_13 -> V_103 ( V_3 ) ;
}
static void F_71 ( struct V_101 * V_54 )
{
struct V_12 * V_13 ;
if ( V_54 -> type == V_104 )
return;
F_42 (tr, &blktrans_majors, list)
V_13 -> V_105 ( V_13 , V_54 ) ;
}
int F_72 ( struct V_12 * V_13 )
{
struct V_101 * V_54 ;
int V_49 ;
if ( ! V_106 . V_8 . V_102 )
F_73 ( & V_106 ) ;
F_8 ( & V_51 ) ;
V_49 = F_74 ( V_13 -> V_81 , V_13 -> V_86 ) ;
if ( V_49 < 0 ) {
F_75 ( V_107 L_4 ,
V_13 -> V_86 , V_13 -> V_81 , V_49 ) ;
F_10 ( & V_51 ) ;
return V_49 ;
}
if ( V_49 )
V_13 -> V_81 = V_49 ;
V_13 -> V_19 = F_76 ( V_13 -> V_30 ) - 1 ;
F_77 ( & V_13 -> V_77 ) ;
F_78 ( & V_13 -> V_8 , & V_108 ) ;
F_79 (mtd)
if ( V_54 -> type != V_104 )
V_13 -> V_105 ( V_13 , V_54 ) ;
F_10 ( & V_51 ) ;
return 0 ;
}
int F_80 ( struct V_12 * V_13 )
{
struct V_2 * V_3 , * V_102 ;
F_8 ( & V_51 ) ;
F_5 ( & V_13 -> V_8 ) ;
F_70 (dev, next, &tr->devs, list)
V_13 -> V_103 ( V_3 ) ;
F_81 ( V_13 -> V_81 , V_13 -> V_86 ) ;
F_10 ( & V_51 ) ;
F_82 ( ! F_83 ( & V_13 -> V_77 ) ) ;
return 0 ;
}
static void T_2 F_84 ( void )
{
if ( V_106 . V_8 . V_102 )
F_85 ( & V_106 ) ;
}

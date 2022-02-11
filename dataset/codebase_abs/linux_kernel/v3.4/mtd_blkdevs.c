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
if ( V_3 -> V_53 )
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
V_3 -> V_58 = V_49 ;
V_11:
V_3 -> V_53 ++ ;
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
V_57:
if ( V_3 -> V_13 -> V_59 )
V_3 -> V_13 -> V_59 ( V_3 ) ;
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
V_51 = V_3 -> V_13 -> V_59 ? V_3 -> V_13 -> V_59 ( V_3 ) : 0 ;
F_38 ( V_3 -> V_55 ) ;
}
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
}
static int F_39 ( struct V_47 * V_48 , struct V_60 * V_61 )
{
struct V_2 * V_3 = F_7 ( V_48 -> V_50 ) ;
int V_51 = - V_62 ;
if ( ! V_3 )
return V_51 ;
F_8 ( & V_3 -> V_41 ) ;
if ( ! V_3 -> V_55 )
goto V_11;
V_51 = V_3 -> V_13 -> V_63 ? V_3 -> V_13 -> V_63 ( V_3 , V_61 ) : 0 ;
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
}
static int F_40 ( struct V_47 * V_48 , T_1 V_49 ,
unsigned int V_64 , unsigned long V_35 )
{
struct V_2 * V_3 = F_7 ( V_48 -> V_50 ) ;
int V_51 = - V_62 ;
if ( ! V_3 )
return V_51 ;
F_8 ( & V_3 -> V_41 ) ;
if ( ! V_3 -> V_55 )
goto V_11;
switch ( V_64 ) {
case V_65 :
V_51 = V_3 -> V_13 -> V_66 ? V_3 -> V_13 -> V_66 ( V_3 ) : 0 ;
break;
default:
V_51 = - V_67 ;
}
V_11:
F_10 ( & V_3 -> V_41 ) ;
F_11 ( V_3 ) ;
return V_51 ;
}
int F_41 ( struct V_2 * V_68 )
{
struct V_12 * V_13 = V_68 -> V_13 ;
struct V_2 * V_69 ;
int V_70 = - 1 ;
struct V_9 * V_71 ;
int V_51 ;
if ( F_42 ( & V_72 ) ) {
F_10 ( & V_72 ) ;
F_43 () ;
}
F_8 ( & V_10 ) ;
F_44 (d, &tr->devs, list) {
if ( V_68 -> V_73 == - 1 ) {
if ( V_69 -> V_73 != V_70 + 1 ) {
V_68 -> V_73 = V_70 + 1 ;
F_45 ( & V_68 -> V_8 , & V_69 -> V_8 ) ;
goto V_74;
}
} else if ( V_69 -> V_73 == V_68 -> V_73 ) {
F_10 ( & V_10 ) ;
return - V_75 ;
} else if ( V_69 -> V_73 > V_68 -> V_73 ) {
F_45 ( & V_68 -> V_8 , & V_69 -> V_8 ) ;
goto V_74;
}
V_70 = V_69 -> V_73 ;
}
V_51 = - V_75 ;
if ( V_68 -> V_73 == - 1 )
V_68 -> V_73 = V_70 + 1 ;
if ( V_68 -> V_73 > ( V_76 >> V_13 -> V_77 ) ||
( V_13 -> V_77 && V_68 -> V_73 >= 27 * 26 ) ) {
F_10 ( & V_10 ) ;
goto V_78;
}
F_45 ( & V_68 -> V_8 , & V_13 -> V_79 ) ;
V_74:
F_10 ( & V_10 ) ;
F_46 ( & V_68 -> V_41 ) ;
F_47 ( & V_68 -> V_4 ) ;
if ( ! V_13 -> V_32 )
V_68 -> V_80 = 1 ;
V_51 = - V_81 ;
V_71 = F_48 ( 1 << V_13 -> V_77 ) ;
if ( ! V_71 )
goto V_82;
V_68 -> V_5 = V_71 ;
V_71 -> V_6 = V_68 ;
V_71 -> V_83 = V_13 -> V_83 ;
V_71 -> V_84 = ( V_68 -> V_73 ) << V_13 -> V_77 ;
V_71 -> V_85 = & V_12 ;
if ( V_13 -> V_77 )
if ( V_68 -> V_73 < 26 )
snprintf ( V_71 -> V_86 , sizeof( V_71 -> V_86 ) ,
L_2 , V_13 -> V_87 , 'a' + V_68 -> V_73 ) ;
else
snprintf ( V_71 -> V_86 , sizeof( V_71 -> V_86 ) ,
L_3 , V_13 -> V_87 ,
'a' - 1 + V_68 -> V_73 / 26 ,
'a' + V_68 -> V_73 % 26 ) ;
else
snprintf ( V_71 -> V_86 , sizeof( V_71 -> V_86 ) ,
L_4 , V_13 -> V_87 , V_68 -> V_73 ) ;
F_49 ( V_71 , ( V_68 -> V_88 * V_13 -> V_29 ) >> 9 ) ;
F_50 ( & V_68 -> V_38 ) ;
V_68 -> V_7 = F_51 ( F_31 , & V_68 -> V_38 ) ;
if ( ! V_68 -> V_7 )
goto V_89;
V_68 -> V_7 -> V_44 = V_68 ;
F_52 ( V_68 -> V_7 , V_13 -> V_29 ) ;
F_53 ( V_90 , V_68 -> V_7 ) ;
if ( V_13 -> V_27 ) {
F_53 ( V_91 , V_68 -> V_7 ) ;
V_68 -> V_7 -> V_92 . V_93 = V_94 ;
}
V_71 -> V_95 = V_68 -> V_7 ;
V_68 -> V_46 = F_54 ( F_23 , V_68 ,
L_4 , V_13 -> V_87 , V_68 -> V_55 -> V_96 ) ;
if ( F_55 ( V_68 -> V_46 ) ) {
V_51 = F_56 ( V_68 -> V_46 ) ;
goto V_97;
}
V_71 -> V_98 = & V_68 -> V_55 -> V_3 ;
if ( V_68 -> V_80 )
F_57 ( V_71 , 1 ) ;
F_58 ( V_71 ) ;
if ( V_68 -> V_99 ) {
V_51 = F_59 ( & F_60 ( V_71 ) -> V_100 ,
V_68 -> V_99 ) ;
F_61 ( V_51 ) ;
}
return 0 ;
V_97:
F_3 ( V_68 -> V_7 ) ;
V_89:
F_4 ( V_68 -> V_5 ) ;
V_82:
F_5 ( & V_68 -> V_8 ) ;
V_78:
return V_51 ;
}
int F_62 ( struct V_2 * V_101 )
{
unsigned long V_102 ;
if ( F_42 ( & V_72 ) ) {
F_10 ( & V_72 ) ;
F_43 () ;
}
if ( V_101 -> V_99 )
F_63 ( & F_60 ( V_101 -> V_5 ) -> V_100 ,
V_101 -> V_99 ) ;
F_64 ( V_101 -> V_5 ) ;
F_65 ( V_101 -> V_46 ) ;
F_66 ( & V_101 -> V_38 , V_102 ) ;
V_101 -> V_7 -> V_44 = NULL ;
F_67 ( V_101 -> V_7 ) ;
F_68 ( & V_101 -> V_38 , V_102 ) ;
F_8 ( & V_101 -> V_41 ) ;
if ( V_101 -> V_53 ) {
if ( V_101 -> V_13 -> V_59 )
V_101 -> V_13 -> V_59 ( V_101 ) ;
F_38 ( V_101 -> V_55 ) ;
}
V_101 -> V_55 = NULL ;
F_10 ( & V_101 -> V_41 ) ;
F_11 ( V_101 ) ;
return 0 ;
}
static void F_69 ( struct V_103 * V_55 )
{
struct V_12 * V_13 ;
struct V_2 * V_3 , * V_104 ;
F_44 (tr, &blktrans_majors, list)
F_70 (dev, next, &tr->devs, list)
if ( V_3 -> V_55 == V_55 )
V_13 -> V_105 ( V_3 ) ;
}
static void F_71 ( struct V_103 * V_55 )
{
struct V_12 * V_13 ;
if ( V_55 -> type == V_106 )
return;
F_44 (tr, &blktrans_majors, list)
V_13 -> V_107 ( V_13 , V_55 ) ;
}
int F_72 ( struct V_12 * V_13 )
{
struct V_103 * V_55 ;
int V_51 ;
if ( ! V_108 . V_8 . V_104 )
F_73 ( & V_108 ) ;
F_8 ( & V_72 ) ;
V_51 = F_74 ( V_13 -> V_83 , V_13 -> V_87 ) ;
if ( V_51 < 0 ) {
F_20 ( V_109 L_5 ,
V_13 -> V_87 , V_13 -> V_83 , V_51 ) ;
F_10 ( & V_72 ) ;
return V_51 ;
}
if ( V_51 )
V_13 -> V_83 = V_51 ;
V_13 -> V_19 = F_75 ( V_13 -> V_29 ) - 1 ;
F_76 ( & V_13 -> V_79 ) ;
F_77 ( & V_13 -> V_8 , & V_110 ) ;
F_78 (mtd)
if ( V_55 -> type != V_106 )
V_13 -> V_107 ( V_13 , V_55 ) ;
F_10 ( & V_72 ) ;
return 0 ;
}
int F_79 ( struct V_12 * V_13 )
{
struct V_2 * V_3 , * V_104 ;
F_8 ( & V_72 ) ;
F_5 ( & V_13 -> V_8 ) ;
F_70 (dev, next, &tr->devs, list)
V_13 -> V_105 ( V_3 ) ;
F_80 ( V_13 -> V_83 , V_13 -> V_87 ) ;
F_10 ( & V_72 ) ;
F_81 ( ! F_82 ( & V_13 -> V_79 ) ) ;
return 0 ;
}
static void T_2 F_83 ( void )
{
if ( V_108 . V_8 . V_104 )
F_84 ( & V_108 ) ;
}

static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_3 ( V_4 , L_1 , V_2 ,
F_4 ( V_6 -> V_7 ) ) ;
if ( V_2 ) {
if ( F_4 ( V_6 -> V_7 ) )
F_5 ( V_4 ) ;
} else {
F_6 ( V_4 ) ;
}
}
static void F_7 ( struct V_8 * V_7 , void * V_9 ,
void * V_1 , int V_10 )
{
struct V_3 * V_4 = V_9 ;
struct V_11 * V_12 ;
int V_13 ;
V_12 = V_1 ;
if ( ! V_12 )
return;
F_3 ( V_4 , L_2 , V_14 , V_10 ) ;
if ( V_10 < 0 ) {
V_4 -> V_15 . V_16 ++ ;
V_4 -> V_15 . V_17 ++ ;
goto V_18;
}
F_8 ( V_12 , V_10 ) ;
V_12 -> V_19 = F_9 ( V_12 , V_4 ) ;
V_12 -> V_20 = V_21 ;
if ( F_10 ( V_12 ) == V_22 ) {
V_4 -> V_15 . V_16 ++ ;
V_4 -> V_15 . V_23 ++ ;
} else {
V_4 -> V_15 . V_24 ++ ;
V_4 -> V_15 . V_25 += V_10 ;
}
V_12 = F_11 ( V_4 , V_4 -> V_26 + V_27 ) ;
if ( ! V_12 ) {
V_4 -> V_15 . V_16 ++ ;
V_4 -> V_15 . V_28 ++ ;
return;
}
V_18:
V_13 = F_12 ( V_7 , V_12 , V_12 -> V_1 , V_4 -> V_26 + V_27 ) ;
if ( V_13 ) {
F_13 ( V_12 ) ;
V_4 -> V_15 . V_16 ++ ;
V_4 -> V_15 . V_29 ++ ;
}
}
static int F_14 ( struct V_3 * V_30 ,
struct V_8 * V_7 , int V_31 )
{
struct V_5 * V_6 = F_2 ( V_30 ) ;
F_15 ( V_30 ) ;
F_16 () ;
if ( F_17 ( F_18 ( V_7 ) < V_31 ) ) {
F_19 ( & V_6 -> V_32 , V_33 + F_20 ( V_34 ) ) ;
return - V_35 ;
}
F_21 ( V_30 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_8 * V_7 , int V_31 )
{
if ( F_23 ( V_4 ) ||
( F_18 ( V_7 ) >= V_31 ) )
return 0 ;
return F_14 ( V_4 , V_7 , V_31 ) ;
}
static void F_24 ( struct V_8 * V_7 , void * V_9 ,
void * V_1 , int V_10 )
{
struct V_3 * V_4 = V_9 ;
struct V_11 * V_12 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_12 = V_1 ;
if ( ! V_12 || ! V_4 )
return;
if ( V_10 > 0 ) {
V_4 -> V_15 . V_36 ++ ;
V_4 -> V_15 . V_37 += V_12 -> V_10 ;
} else {
V_4 -> V_15 . V_38 ++ ;
V_4 -> V_15 . V_39 ++ ;
}
F_13 ( V_12 ) ;
if ( F_18 ( V_6 -> V_7 ) >= V_40 ) {
F_16 () ;
if ( F_23 ( V_4 ) )
F_25 ( V_4 ) ;
}
}
static T_1 F_26 ( struct V_11 * V_12 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_13 ;
F_22 ( V_4 , V_6 -> V_7 , V_41 ) ;
V_13 = F_27 ( V_6 -> V_7 , V_12 , V_12 -> V_1 , V_12 -> V_10 ) ;
if ( V_13 )
goto V_42;
F_22 ( V_4 , V_6 -> V_7 , V_41 ) ;
return V_43 ;
V_42:
V_4 -> V_15 . V_44 ++ ;
V_4 -> V_15 . V_38 ++ ;
return V_45 ;
}
static void F_28 ( unsigned long V_1 )
{
struct V_3 * V_4 = (struct V_3 * ) V_1 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( F_18 ( V_6 -> V_7 ) < V_41 ) {
F_19 ( & V_6 -> V_32 , V_33 + F_29 ( V_34 ) ) ;
} else {
F_16 () ;
if ( F_23 ( V_4 ) )
F_25 ( V_4 ) ;
}
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
int V_13 , V_46 , V_10 ;
for ( V_46 = 0 ; V_46 < V_47 ; V_46 ++ ) {
V_12 = F_11 ( V_4 , V_4 -> V_26 + V_27 ) ;
if ( ! V_12 ) {
V_13 = - V_48 ;
goto V_42;
}
V_13 = F_12 ( V_6 -> V_7 , V_12 , V_12 -> V_1 ,
V_4 -> V_26 + V_27 ) ;
if ( V_13 ) {
F_13 ( V_12 ) ;
goto V_42;
}
}
F_31 ( & V_6 -> V_32 , F_28 , ( unsigned long ) V_4 ) ;
F_6 ( V_4 ) ;
F_32 ( V_6 -> V_7 ) ;
F_21 ( V_4 ) ;
return 0 ;
V_42:
while ( ( V_12 = F_33 ( V_6 -> V_7 , & V_10 ) ) )
F_13 ( V_12 ) ;
return V_13 ;
}
static int F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
int V_10 ;
F_35 ( V_6 -> V_7 ) ;
while ( ( V_12 = F_33 ( V_6 -> V_7 , & V_10 ) ) )
F_13 ( V_12 ) ;
F_36 ( & V_6 -> V_32 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , int V_49 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_11 * V_12 ;
int V_10 , V_13 ;
if ( V_49 > F_38 ( V_6 -> V_7 ) - V_27 )
return - V_50 ;
if ( ! F_39 ( V_4 ) ) {
V_4 -> V_26 = V_49 ;
return 0 ;
}
F_35 ( V_6 -> V_7 ) ;
if ( V_4 -> V_26 < V_49 ) {
int V_46 ;
for ( V_46 = 0 ; ( V_12 = F_33 ( V_6 -> V_7 , & V_10 ) ) ; V_46 ++ )
F_13 ( V_12 ) ;
for (; V_46 ; V_46 -- ) {
V_12 = F_11 ( V_4 , V_49 + V_27 ) ;
if ( ! V_12 ) {
V_13 = - V_48 ;
goto V_42;
}
V_13 = F_12 ( V_6 -> V_7 , V_12 , V_12 -> V_1 ,
V_49 + V_27 ) ;
if ( V_13 ) {
F_13 ( V_12 ) ;
goto V_42;
}
}
}
V_4 -> V_26 = V_49 ;
F_32 ( V_6 -> V_7 ) ;
return 0 ;
V_42:
F_35 ( V_6 -> V_7 ) ;
while ( ( V_12 = F_33 ( V_6 -> V_7 , & V_10 ) ) )
F_13 ( V_12 ) ;
F_40 ( V_4 , L_3 ) ;
return V_13 ;
}
static void F_41 ( struct V_3 * V_4 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_42 ( V_52 -> V_53 , V_54 , sizeof( V_52 -> V_53 ) ) ;
F_42 ( V_52 -> V_55 , V_56 , sizeof( V_52 -> V_55 ) ) ;
F_42 ( V_52 -> V_57 , F_43 ( V_6 -> V_58 ) , sizeof( V_52 -> V_57 ) ) ;
}
static int F_44 ( struct V_3 * V_6 ,
struct V_59 * V_60 )
{
F_45 ( V_60 , V_61 ) ;
F_46 ( V_60 , V_61 , V_62 ) ;
F_45 ( V_60 , V_63 ) ;
F_46 ( V_60 , V_63 , V_62 ) ;
V_60 -> V_64 . V_65 = V_66 ;
V_60 -> V_64 . V_67 = V_68 ;
V_60 -> V_64 . V_69 = V_70 ;
V_60 -> V_64 . V_71 = 0 ;
V_60 -> V_64 . V_72 = V_73 ;
return 0 ;
}
static int F_47 ( struct V_74 * V_75 )
{
struct V_76 * V_77 ;
struct V_3 * V_4 ;
struct V_78 * V_58 ;
struct V_5 * V_6 ;
int V_13 ;
V_77 = F_48 ( V_75 -> V_79 ) ;
V_58 = V_77 -> V_58 ;
if ( ! V_58 )
return - V_80 ;
V_4 = F_49 ( sizeof( * V_6 ) ) ;
if ( ! V_4 )
return - V_48 ;
F_50 ( V_4 , V_75 ) ;
V_6 = F_2 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
V_6 -> V_58 = V_58 ;
V_4 -> V_81 = V_82 ;
V_4 -> V_83 |= V_84 ;
V_4 -> V_85 = V_4 -> V_81 ;
V_4 -> V_86 = F_29 ( V_87 ) ;
F_51 ( V_4 -> V_88 ) ;
memcpy ( V_4 -> V_89 , V_4 -> V_88 , V_4 -> V_90 ) ;
V_4 -> V_91 = & V_92 ;
V_4 -> V_93 = & V_94 ;
V_4 -> V_95 = 0 ;
V_4 -> V_96 = V_97 ;
V_6 -> V_7 = F_52 ( V_4 , V_75 ,
& V_98 ) ;
if ( ! V_6 -> V_7 ) {
V_13 = - V_99 ;
goto V_42;
}
V_4 -> V_26 = F_38 ( V_6 -> V_7 ) - V_27 ;
V_13 = F_53 ( V_4 ) ;
if ( V_13 )
goto V_100;
F_54 ( & V_6 -> V_101 , & V_102 ) ;
F_55 ( & V_58 -> V_6 , L_4 , V_4 -> V_103 ) ;
return 0 ;
V_100:
F_56 ( V_6 -> V_7 ) ;
V_42:
F_57 ( V_4 ) ;
return V_13 ;
}
static void F_58 ( struct V_74 * V_75 )
{
struct V_76 * V_77 ;
struct V_3 * V_4 ;
struct V_78 * V_58 ;
struct V_5 * V_6 ;
bool V_104 = false ;
V_77 = F_48 ( V_75 -> V_79 ) ;
V_58 = V_77 -> V_58 ;
F_59 (dev, &dev_list, list) {
if ( V_6 -> V_58 == V_58 ) {
V_104 = true ;
break;
}
}
if ( ! V_104 )
return;
F_60 ( & V_6 -> V_101 ) ;
V_4 = V_6 -> V_4 ;
F_61 ( V_4 ) ;
F_56 ( V_6 -> V_7 ) ;
F_57 ( V_4 ) ;
}
static int T_2 F_62 ( void )
{
int V_13 ;
V_13 = F_63 ( V_54 ) ;
if ( V_13 )
return V_13 ;
return F_64 ( & V_105 ) ;
}
static void T_3 F_65 ( void )
{
F_66 ( & V_105 ) ;
F_67 ( V_54 ) ;
}

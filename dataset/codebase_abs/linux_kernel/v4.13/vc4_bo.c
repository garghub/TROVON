static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ,
V_2 -> V_3 . V_4 ) ;
F_2 ( L_2 ,
V_2 -> V_3 . V_5 / 1024 ) ;
F_2 ( L_3 ,
V_2 -> V_3 . V_4 - V_2 -> V_3 . V_6 ) ;
F_2 ( L_4 ,
( V_2 -> V_3 . V_5 -
V_2 -> V_3 . V_7 ) / 1024 ) ;
F_2 ( L_5 ,
V_2 -> V_3 . V_6 ) ;
F_2 ( L_6 ,
V_2 -> V_3 . V_7 / 1024 ) ;
}
int F_3 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_9 -> V_13 ;
struct V_14 * V_15 = V_12 -> V_16 -> V_15 ;
struct V_1 * V_2 = F_4 ( V_15 ) ;
struct V_17 V_18 ;
F_5 ( & V_2 -> V_19 ) ;
V_18 = V_2 -> V_3 ;
F_6 ( & V_2 -> V_19 ) ;
F_7 ( V_9 , L_1 ,
V_18 . V_4 ) ;
F_7 ( V_9 , L_2 ,
V_18 . V_5 / 1024 ) ;
F_7 ( V_9 , L_3 ,
V_18 . V_4 - V_18 . V_6 ) ;
F_7 ( V_9 , L_4 ,
( V_18 . V_5 - V_18 . V_7 ) / 1024 ) ;
F_7 ( V_9 , L_5 ,
V_18 . V_6 ) ;
F_7 ( V_9 , L_6 ,
V_18 . V_7 / 1024 ) ;
return 0 ;
}
static T_1 F_8 ( T_2 V_20 )
{
return ( V_20 / V_21 ) - 1 ;
}
static void F_9 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_26 . V_26 ;
struct V_1 * V_2 = F_4 ( V_25 -> V_15 ) ;
if ( V_23 -> V_27 ) {
F_10 ( V_23 -> V_27 -> V_28 ) ;
F_10 ( V_23 -> V_27 ) ;
V_23 -> V_27 = NULL ;
}
V_2 -> V_3 . V_4 -- ;
V_2 -> V_3 . V_5 -= V_25 -> V_20 ;
F_11 ( & V_23 -> V_29 ) ;
F_12 ( V_25 ) ;
}
static void F_13 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_26 . V_26 ;
struct V_1 * V_2 = F_4 ( V_25 -> V_15 ) ;
V_2 -> V_3 . V_6 -- ;
V_2 -> V_3 . V_7 -= V_25 -> V_20 ;
F_14 ( & V_23 -> V_30 ) ;
F_14 ( & V_23 -> V_31 ) ;
}
static struct V_32 * F_15 ( struct V_14 * V_15 ,
T_2 V_20 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
T_1 V_33 = F_8 ( V_20 ) ;
if ( V_2 -> V_34 . V_35 <= V_33 ) {
T_1 V_36 = F_16 ( V_2 -> V_34 . V_35 * 2 ,
V_33 + 1 ) ;
struct V_32 * V_37 ;
T_1 V_38 ;
V_37 = F_17 ( V_36 , sizeof( struct V_32 ) ,
V_39 ) ;
if ( ! V_37 )
return NULL ;
for ( V_38 = 0 ; V_38 < V_2 -> V_34 . V_35 ; V_38 ++ ) {
struct V_32 * V_40 =
& V_2 -> V_34 . V_41 [ V_38 ] ;
if ( F_18 ( V_40 ) )
F_19 ( & V_37 [ V_38 ] ) ;
else
F_20 ( V_40 , & V_37 [ V_38 ] ) ;
}
for ( V_38 = V_2 -> V_34 . V_35 ; V_38 < V_36 ; V_38 ++ )
F_19 ( & V_37 [ V_38 ] ) ;
F_10 ( V_2 -> V_34 . V_41 ) ;
V_2 -> V_34 . V_41 = V_37 ;
V_2 -> V_34 . V_35 = V_36 ;
}
return & V_2 -> V_34 . V_41 [ V_33 ] ;
}
static void F_21 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
F_5 ( & V_2 -> V_19 ) ;
while ( ! F_18 ( & V_2 -> V_34 . V_42 ) ) {
struct V_22 * V_23 = F_22 ( & V_2 -> V_34 . V_42 ,
struct V_22 , V_30 ) ;
F_13 ( V_23 ) ;
F_9 ( V_23 ) ;
}
F_6 ( & V_2 -> V_19 ) ;
}
static struct V_22 * F_23 ( struct V_14 * V_15 ,
T_1 V_20 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
T_1 V_33 = F_8 ( V_20 ) ;
struct V_22 * V_23 = NULL ;
V_20 = F_24 ( V_20 , V_21 ) ;
F_5 ( & V_2 -> V_19 ) ;
if ( V_33 >= V_2 -> V_34 . V_35 )
goto V_43;
if ( F_18 ( & V_2 -> V_34 . V_41 [ V_33 ] ) )
goto V_43;
V_23 = F_25 ( & V_2 -> V_34 . V_41 [ V_33 ] ,
struct V_22 , V_31 ) ;
F_13 ( V_23 ) ;
F_26 ( & V_23 -> V_26 . V_26 . V_44 ) ;
V_43:
F_6 ( & V_2 -> V_19 ) ;
return V_23 ;
}
struct V_24 * F_27 ( struct V_14 * V_15 , T_2 V_20 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
struct V_22 * V_23 ;
V_23 = F_28 ( sizeof( * V_23 ) , V_39 ) ;
if ( ! V_23 )
return F_29 ( - V_45 ) ;
F_5 ( & V_2 -> V_19 ) ;
V_2 -> V_3 . V_4 ++ ;
V_2 -> V_3 . V_5 += V_20 ;
F_6 ( & V_2 -> V_19 ) ;
V_23 -> V_46 = & V_23 -> V_29 ;
F_30 ( V_23 -> V_46 ) ;
return & V_23 -> V_26 . V_26 ;
}
struct V_22 * F_31 ( struct V_14 * V_15 , T_2 V_47 ,
bool V_48 )
{
T_2 V_20 = F_24 ( V_47 , V_21 ) ;
struct V_1 * V_2 = F_4 ( V_15 ) ;
struct V_49 * V_50 ;
struct V_22 * V_23 ;
if ( V_20 == 0 )
return F_29 ( - V_51 ) ;
V_23 = F_23 ( V_15 , V_20 ) ;
if ( V_23 ) {
if ( ! V_48 )
memset ( V_23 -> V_26 . V_52 , 0 , V_23 -> V_26 . V_26 . V_20 ) ;
return V_23 ;
}
V_50 = F_32 ( V_15 , V_20 ) ;
if ( F_33 ( V_50 ) ) {
F_21 ( V_15 ) ;
V_50 = F_32 ( V_15 , V_20 ) ;
if ( F_33 ( V_50 ) ) {
F_34 ( L_7 ) ;
F_1 ( V_2 ) ;
return F_29 ( - V_45 ) ;
}
}
return F_35 ( & V_50 -> V_26 ) ;
}
int F_36 ( struct V_53 * V_54 ,
struct V_14 * V_15 ,
struct V_55 * args )
{
int V_56 = F_37 ( args -> V_57 * args -> V_58 , 8 ) ;
struct V_22 * V_23 = NULL ;
int V_59 ;
if ( args -> V_60 < V_56 )
args -> V_60 = V_56 ;
if ( args -> V_20 < args -> V_60 * args -> V_61 )
args -> V_20 = args -> V_60 * args -> V_61 ;
V_23 = F_31 ( V_15 , args -> V_20 , false ) ;
if ( F_33 ( V_23 ) )
return F_38 ( V_23 ) ;
V_59 = F_39 ( V_54 , & V_23 -> V_26 . V_26 , & args -> V_62 ) ;
F_40 ( & V_23 -> V_26 . V_26 ) ;
return V_59 ;
}
static void F_41 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
unsigned long V_63 = V_64 - F_42 ( 1000 ) ;
while ( ! F_18 ( & V_2 -> V_34 . V_42 ) ) {
struct V_22 * V_23 = F_22 ( & V_2 -> V_34 . V_42 ,
struct V_22 , V_30 ) ;
if ( F_43 ( V_63 , V_23 -> V_65 ) ) {
F_44 ( & V_2 -> V_34 . V_66 ,
F_45 ( V_64 +
F_42 ( 1000 ) ) ) ;
return;
}
F_13 ( V_23 ) ;
F_9 ( V_23 ) ;
}
}
void F_46 ( struct V_24 * V_67 )
{
struct V_14 * V_15 = V_67 -> V_15 ;
struct V_1 * V_2 = F_4 ( V_15 ) ;
struct V_22 * V_23 = F_35 ( V_67 ) ;
struct V_32 * V_68 ;
F_5 ( & V_2 -> V_19 ) ;
if ( V_67 -> V_69 ) {
F_9 ( V_23 ) ;
goto V_43;
}
if ( V_67 -> V_70 ) {
F_9 ( V_23 ) ;
goto V_43;
}
if ( ! V_23 -> V_26 . V_52 ) {
F_9 ( V_23 ) ;
goto V_43;
}
V_68 = F_15 ( V_15 , V_67 -> V_20 ) ;
if ( ! V_68 ) {
F_9 ( V_23 ) ;
goto V_43;
}
if ( V_23 -> V_27 ) {
F_10 ( V_23 -> V_27 -> V_28 ) ;
F_10 ( V_23 -> V_27 ) ;
V_23 -> V_27 = NULL ;
}
V_23 -> V_71 = false ;
V_23 -> V_65 = V_64 ;
F_47 ( & V_23 -> V_31 , V_68 ) ;
F_47 ( & V_23 -> V_30 , & V_2 -> V_34 . V_42 ) ;
V_2 -> V_3 . V_6 ++ ;
V_2 -> V_3 . V_7 += V_67 -> V_20 ;
F_41 ( V_15 ) ;
V_43:
F_6 ( & V_2 -> V_19 ) ;
}
static void F_48 ( struct V_72 * V_73 )
{
struct V_1 * V_2 =
F_49 ( V_73 , struct V_1 , V_34 . V_74 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_5 ( & V_2 -> V_19 ) ;
F_41 ( V_15 ) ;
F_6 ( & V_2 -> V_19 ) ;
}
static void F_50 ( unsigned long V_75 )
{
struct V_14 * V_15 = (struct V_14 * ) V_75 ;
struct V_1 * V_2 = F_4 ( V_15 ) ;
F_51 ( & V_2 -> V_34 . V_74 ) ;
}
struct V_76 * F_52 ( struct V_24 * V_25 )
{
struct V_22 * V_23 = F_35 ( V_25 ) ;
return V_23 -> V_46 ;
}
struct V_77 *
F_53 ( struct V_14 * V_15 , struct V_24 * V_25 , int V_78 )
{
struct V_22 * V_23 = F_35 ( V_25 ) ;
if ( V_23 -> V_27 ) {
F_34 ( L_8 ) ;
return F_29 ( - V_51 ) ;
}
return F_54 ( V_15 , V_25 , V_78 ) ;
}
int F_55 ( struct V_79 * V_80 , struct V_81 * V_82 )
{
struct V_24 * V_83 ;
struct V_22 * V_23 ;
int V_59 ;
V_59 = F_56 ( V_80 , V_82 ) ;
if ( V_59 )
return V_59 ;
V_83 = V_82 -> V_84 ;
V_23 = F_35 ( V_83 ) ;
if ( V_23 -> V_27 && ( V_82 -> V_85 & V_86 ) ) {
F_34 ( L_9 ) ;
return - V_51 ;
}
V_82 -> V_85 &= ~ V_87 ;
V_82 -> V_88 = 0 ;
V_59 = F_57 ( V_23 -> V_26 . V_26 . V_15 -> V_15 , V_82 , V_23 -> V_26 . V_52 ,
V_23 -> V_26 . V_89 , V_82 -> V_90 - V_82 -> V_91 ) ;
if ( V_59 )
F_58 ( V_82 ) ;
return V_59 ;
}
int F_59 ( struct V_24 * V_25 , struct V_81 * V_82 )
{
struct V_22 * V_23 = F_35 ( V_25 ) ;
if ( V_23 -> V_27 && ( V_82 -> V_85 & V_86 ) ) {
F_34 ( L_9 ) ;
return - V_51 ;
}
return F_60 ( V_25 , V_82 ) ;
}
void * F_61 ( struct V_24 * V_25 )
{
struct V_22 * V_23 = F_35 ( V_25 ) ;
if ( V_23 -> V_27 ) {
F_34 ( L_10 ) ;
return F_29 ( - V_51 ) ;
}
return F_62 ( V_25 ) ;
}
struct V_24 *
F_63 ( struct V_14 * V_15 ,
struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_24 * V_25 ;
struct V_22 * V_23 ;
V_25 = F_64 ( V_15 , V_93 , V_95 ) ;
if ( F_33 ( V_25 ) )
return V_25 ;
V_23 = F_35 ( V_25 ) ;
V_23 -> V_46 = V_93 -> V_96 -> V_46 ;
return V_25 ;
}
int F_65 ( struct V_14 * V_15 , void * V_75 ,
struct V_53 * V_54 )
{
struct V_97 * args = V_75 ;
struct V_22 * V_23 = NULL ;
int V_59 ;
V_23 = F_31 ( V_15 , args -> V_20 , false ) ;
if ( F_33 ( V_23 ) )
return F_38 ( V_23 ) ;
V_59 = F_39 ( V_54 , & V_23 -> V_26 . V_26 , & args -> V_62 ) ;
F_40 ( & V_23 -> V_26 . V_26 ) ;
return V_59 ;
}
int F_66 ( struct V_14 * V_15 , void * V_75 ,
struct V_53 * V_54 )
{
struct V_98 * args = V_75 ;
struct V_24 * V_83 ;
V_83 = F_67 ( V_54 , args -> V_62 ) ;
if ( ! V_83 ) {
F_34 ( L_11 , args -> V_62 ) ;
return - V_51 ;
}
args -> V_99 = F_68 ( & V_83 -> V_100 ) ;
F_40 ( V_83 ) ;
return 0 ;
}
int
F_69 ( struct V_14 * V_15 , void * V_75 ,
struct V_53 * V_54 )
{
struct V_101 * args = V_75 ;
struct V_22 * V_23 = NULL ;
int V_59 ;
if ( args -> V_20 == 0 )
return - V_51 ;
if ( args -> V_20 % sizeof( V_102 ) != 0 )
return - V_51 ;
if ( args -> V_78 != 0 ) {
F_2 ( L_12 , args -> V_78 ) ;
return - V_51 ;
}
if ( args -> V_103 != 0 ) {
F_2 ( L_13 , args -> V_103 ) ;
return - V_51 ;
}
V_23 = F_31 ( V_15 , args -> V_20 , true ) ;
if ( F_33 ( V_23 ) )
return F_38 ( V_23 ) ;
if ( F_70 ( V_23 -> V_26 . V_52 ,
( void V_104 * ) ( V_105 ) args -> V_75 ,
args -> V_20 ) ) {
V_59 = - V_106 ;
goto V_107;
}
memset ( V_23 -> V_26 . V_52 + args -> V_20 , 0 ,
V_23 -> V_26 . V_26 . V_20 - args -> V_20 ) ;
V_23 -> V_27 = F_71 ( & V_23 -> V_26 ) ;
if ( ! V_23 -> V_27 ) {
V_59 = - V_51 ;
goto V_107;
}
V_59 = F_39 ( V_54 , & V_23 -> V_26 . V_26 , & args -> V_62 ) ;
V_107:
F_40 ( & V_23 -> V_26 . V_26 ) ;
return V_59 ;
}
int F_72 ( struct V_14 * V_15 , void * V_75 ,
struct V_53 * V_54 )
{
struct V_108 * args = V_75 ;
struct V_24 * V_83 ;
struct V_22 * V_23 ;
bool V_71 ;
if ( args -> V_78 != 0 )
return - V_51 ;
switch ( args -> V_109 ) {
case V_110 :
V_71 = false ;
break;
case V_111 :
V_71 = true ;
break;
default:
return - V_51 ;
}
V_83 = F_67 ( V_54 , args -> V_62 ) ;
if ( ! V_83 ) {
F_34 ( L_11 , args -> V_62 ) ;
return - V_112 ;
}
V_23 = F_35 ( V_83 ) ;
V_23 -> V_71 = V_71 ;
F_40 ( V_83 ) ;
return 0 ;
}
int F_73 ( struct V_14 * V_15 , void * V_75 ,
struct V_53 * V_54 )
{
struct V_113 * args = V_75 ;
struct V_24 * V_83 ;
struct V_22 * V_23 ;
if ( args -> V_78 != 0 || args -> V_109 != 0 )
return - V_51 ;
V_83 = F_67 ( V_54 , args -> V_62 ) ;
if ( ! V_83 ) {
F_34 ( L_11 , args -> V_62 ) ;
return - V_112 ;
}
V_23 = F_35 ( V_83 ) ;
if ( V_23 -> V_71 )
args -> V_109 = V_111 ;
else
args -> V_109 = V_110 ;
F_40 ( V_83 ) ;
return 0 ;
}
void F_74 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
F_75 ( & V_2 -> V_19 ) ;
F_19 ( & V_2 -> V_34 . V_42 ) ;
F_76 ( & V_2 -> V_34 . V_74 , F_48 ) ;
F_77 ( & V_2 -> V_34 . V_66 ,
F_50 ,
( unsigned long ) V_15 ) ;
}
void F_78 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
F_79 ( & V_2 -> V_34 . V_66 ) ;
F_80 ( & V_2 -> V_34 . V_74 ) ;
F_21 ( V_15 ) ;
if ( V_2 -> V_3 . V_4 ) {
F_34 ( L_14 ) ;
F_1 ( V_2 ) ;
}
}

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
F_11 ( V_25 ) ;
}
static void F_12 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = & V_23 -> V_26 . V_26 ;
struct V_1 * V_2 = F_4 ( V_25 -> V_15 ) ;
V_2 -> V_3 . V_6 -- ;
V_2 -> V_3 . V_7 -= V_25 -> V_20 ;
F_13 ( & V_23 -> V_29 ) ;
F_13 ( & V_23 -> V_30 ) ;
}
static struct V_31 * F_14 ( struct V_14 * V_15 ,
T_2 V_20 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
T_1 V_32 = F_8 ( V_20 ) ;
if ( V_2 -> V_33 . V_34 <= V_32 ) {
T_1 V_35 = F_15 ( V_2 -> V_33 . V_34 * 2 ,
V_32 + 1 ) ;
struct V_31 * V_36 ;
T_1 V_37 ;
V_36 = F_16 ( V_35 , sizeof( struct V_31 ) ,
V_38 ) ;
if ( ! V_36 )
return NULL ;
for ( V_37 = 0 ; V_37 < V_2 -> V_33 . V_34 ; V_37 ++ ) {
struct V_31 * V_39 =
& V_2 -> V_33 . V_40 [ V_37 ] ;
if ( F_17 ( V_39 ) )
F_18 ( & V_36 [ V_37 ] ) ;
else
F_19 ( V_39 , & V_36 [ V_37 ] ) ;
}
for ( V_37 = V_2 -> V_33 . V_34 ; V_37 < V_35 ; V_37 ++ )
F_18 ( & V_36 [ V_37 ] ) ;
F_10 ( V_2 -> V_33 . V_40 ) ;
V_2 -> V_33 . V_40 = V_36 ;
V_2 -> V_33 . V_34 = V_35 ;
}
return & V_2 -> V_33 . V_40 [ V_32 ] ;
}
static void F_20 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
F_5 ( & V_2 -> V_19 ) ;
while ( ! F_17 ( & V_2 -> V_33 . V_41 ) ) {
struct V_22 * V_23 = F_21 ( & V_2 -> V_33 . V_41 ,
struct V_22 , V_29 ) ;
F_12 ( V_23 ) ;
F_9 ( V_23 ) ;
}
F_6 ( & V_2 -> V_19 ) ;
}
static struct V_22 * F_22 ( struct V_14 * V_15 ,
T_1 V_20 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
T_1 V_32 = F_8 ( V_20 ) ;
struct V_22 * V_23 = NULL ;
V_20 = F_23 ( V_20 , V_21 ) ;
F_5 ( & V_2 -> V_19 ) ;
if ( V_32 >= V_2 -> V_33 . V_34 )
goto V_42;
if ( F_17 ( & V_2 -> V_33 . V_40 [ V_32 ] ) )
goto V_42;
V_23 = F_24 ( & V_2 -> V_33 . V_40 [ V_32 ] ,
struct V_22 , V_30 ) ;
F_12 ( V_23 ) ;
F_25 ( & V_23 -> V_26 . V_26 . V_43 ) ;
V_42:
F_6 ( & V_2 -> V_19 ) ;
return V_23 ;
}
struct V_24 * F_26 ( struct V_14 * V_15 , T_2 V_20 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
struct V_22 * V_23 ;
V_23 = F_27 ( sizeof( * V_23 ) , V_38 ) ;
if ( ! V_23 )
return F_28 ( - V_44 ) ;
F_5 ( & V_2 -> V_19 ) ;
V_2 -> V_3 . V_4 ++ ;
V_2 -> V_3 . V_5 += V_20 ;
F_6 ( & V_2 -> V_19 ) ;
return & V_23 -> V_26 . V_26 ;
}
struct V_22 * F_29 ( struct V_14 * V_15 , T_2 V_45 ,
bool V_46 )
{
T_2 V_20 = F_23 ( V_45 , V_21 ) ;
struct V_1 * V_2 = F_4 ( V_15 ) ;
struct V_47 * V_48 ;
struct V_22 * V_23 ;
if ( V_20 == 0 )
return F_28 ( - V_49 ) ;
V_23 = F_22 ( V_15 , V_20 ) ;
if ( V_23 ) {
if ( ! V_46 )
memset ( V_23 -> V_26 . V_50 , 0 , V_23 -> V_26 . V_26 . V_20 ) ;
return V_23 ;
}
V_48 = F_30 ( V_15 , V_20 ) ;
if ( F_31 ( V_48 ) ) {
F_20 ( V_15 ) ;
V_48 = F_30 ( V_15 , V_20 ) ;
if ( F_31 ( V_48 ) ) {
F_32 ( L_7 ) ;
F_1 ( V_2 ) ;
return F_28 ( - V_44 ) ;
}
}
return F_33 ( & V_48 -> V_26 ) ;
}
int F_34 ( struct V_51 * V_52 ,
struct V_14 * V_15 ,
struct V_53 * args )
{
int V_54 = F_35 ( args -> V_55 * args -> V_56 , 8 ) ;
struct V_22 * V_23 = NULL ;
int V_57 ;
if ( args -> V_58 < V_54 )
args -> V_58 = V_54 ;
if ( args -> V_20 < args -> V_58 * args -> V_59 )
args -> V_20 = args -> V_58 * args -> V_59 ;
V_23 = F_29 ( V_15 , args -> V_20 , false ) ;
if ( F_31 ( V_23 ) )
return F_36 ( V_23 ) ;
V_57 = F_37 ( V_52 , & V_23 -> V_26 . V_26 , & args -> V_60 ) ;
F_38 ( & V_23 -> V_26 . V_26 ) ;
return V_57 ;
}
static void F_39 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
unsigned long V_61 = V_62 - F_40 ( 1000 ) ;
while ( ! F_17 ( & V_2 -> V_33 . V_41 ) ) {
struct V_22 * V_23 = F_21 ( & V_2 -> V_33 . V_41 ,
struct V_22 , V_29 ) ;
if ( F_41 ( V_61 , V_23 -> V_63 ) ) {
F_42 ( & V_2 -> V_33 . V_64 ,
F_43 ( V_62 +
F_40 ( 1000 ) ) ) ;
return;
}
F_12 ( V_23 ) ;
F_9 ( V_23 ) ;
}
}
void F_44 ( struct V_24 * V_65 )
{
struct V_14 * V_15 = V_65 -> V_15 ;
struct V_1 * V_2 = F_4 ( V_15 ) ;
struct V_22 * V_23 = F_33 ( V_65 ) ;
struct V_31 * V_66 ;
F_5 ( & V_2 -> V_19 ) ;
if ( V_65 -> V_67 ) {
F_9 ( V_23 ) ;
goto V_42;
}
if ( V_65 -> V_68 ) {
F_9 ( V_23 ) ;
goto V_42;
}
if ( ! V_23 -> V_26 . V_50 ) {
F_9 ( V_23 ) ;
goto V_42;
}
V_66 = F_14 ( V_15 , V_65 -> V_20 ) ;
if ( ! V_66 ) {
F_9 ( V_23 ) ;
goto V_42;
}
if ( V_23 -> V_27 ) {
F_10 ( V_23 -> V_27 -> V_28 ) ;
F_10 ( V_23 -> V_27 ) ;
V_23 -> V_27 = NULL ;
}
V_23 -> V_63 = V_62 ;
F_45 ( & V_23 -> V_30 , V_66 ) ;
F_45 ( & V_23 -> V_29 , & V_2 -> V_33 . V_41 ) ;
V_2 -> V_3 . V_6 ++ ;
V_2 -> V_3 . V_7 += V_65 -> V_20 ;
F_39 ( V_15 ) ;
V_42:
F_6 ( & V_2 -> V_19 ) ;
}
static void F_46 ( struct V_69 * V_70 )
{
struct V_1 * V_2 =
F_47 ( V_70 , struct V_1 , V_33 . V_71 ) ;
struct V_14 * V_15 = V_2 -> V_15 ;
F_5 ( & V_2 -> V_19 ) ;
F_39 ( V_15 ) ;
F_6 ( & V_2 -> V_19 ) ;
}
static void F_48 ( unsigned long V_72 )
{
struct V_14 * V_15 = (struct V_14 * ) V_72 ;
struct V_1 * V_2 = F_4 ( V_15 ) ;
F_49 ( & V_2 -> V_33 . V_71 ) ;
}
struct V_73 *
F_50 ( struct V_14 * V_15 , struct V_24 * V_25 , int V_74 )
{
struct V_22 * V_23 = F_33 ( V_25 ) ;
if ( V_23 -> V_27 ) {
F_32 ( L_8 ) ;
return F_28 ( - V_49 ) ;
}
return F_51 ( V_15 , V_25 , V_74 ) ;
}
int F_52 ( struct V_75 * V_76 , struct V_77 * V_78 )
{
struct V_24 * V_79 ;
struct V_22 * V_23 ;
int V_57 ;
V_57 = F_53 ( V_76 , V_78 ) ;
if ( V_57 )
return V_57 ;
V_79 = V_78 -> V_80 ;
V_23 = F_33 ( V_79 ) ;
if ( V_23 -> V_27 && ( V_78 -> V_81 & V_82 ) ) {
F_32 ( L_9 ) ;
return - V_49 ;
}
V_78 -> V_81 &= ~ V_83 ;
V_78 -> V_84 = 0 ;
V_57 = F_54 ( V_23 -> V_26 . V_26 . V_15 -> V_15 , V_78 , V_23 -> V_26 . V_50 ,
V_23 -> V_26 . V_85 , V_78 -> V_86 - V_78 -> V_87 ) ;
if ( V_57 )
F_55 ( V_78 ) ;
return V_57 ;
}
int F_56 ( struct V_24 * V_25 , struct V_77 * V_78 )
{
struct V_22 * V_23 = F_33 ( V_25 ) ;
if ( V_23 -> V_27 && ( V_78 -> V_81 & V_82 ) ) {
F_32 ( L_9 ) ;
return - V_49 ;
}
return F_57 ( V_25 , V_78 ) ;
}
void * F_58 ( struct V_24 * V_25 )
{
struct V_22 * V_23 = F_33 ( V_25 ) ;
if ( V_23 -> V_27 ) {
F_32 ( L_10 ) ;
return F_28 ( - V_49 ) ;
}
return F_59 ( V_25 ) ;
}
int F_60 ( struct V_14 * V_15 , void * V_72 ,
struct V_51 * V_52 )
{
struct V_88 * args = V_72 ;
struct V_22 * V_23 = NULL ;
int V_57 ;
V_23 = F_29 ( V_15 , args -> V_20 , false ) ;
if ( F_31 ( V_23 ) )
return F_36 ( V_23 ) ;
V_57 = F_37 ( V_52 , & V_23 -> V_26 . V_26 , & args -> V_60 ) ;
F_38 ( & V_23 -> V_26 . V_26 ) ;
return V_57 ;
}
int F_61 ( struct V_14 * V_15 , void * V_72 ,
struct V_51 * V_52 )
{
struct V_89 * args = V_72 ;
struct V_24 * V_79 ;
V_79 = F_62 ( V_52 , args -> V_60 ) ;
if ( ! V_79 ) {
F_32 ( L_11 , args -> V_60 ) ;
return - V_49 ;
}
args -> V_90 = F_63 ( & V_79 -> V_91 ) ;
F_38 ( V_79 ) ;
return 0 ;
}
int
F_64 ( struct V_14 * V_15 , void * V_72 ,
struct V_51 * V_52 )
{
struct V_92 * args = V_72 ;
struct V_22 * V_23 = NULL ;
int V_57 ;
if ( args -> V_20 == 0 )
return - V_49 ;
if ( args -> V_20 % sizeof( V_93 ) != 0 )
return - V_49 ;
if ( args -> V_74 != 0 ) {
F_2 ( L_12 , args -> V_74 ) ;
return - V_49 ;
}
if ( args -> V_94 != 0 ) {
F_2 ( L_13 , args -> V_94 ) ;
return - V_49 ;
}
V_23 = F_29 ( V_15 , args -> V_20 , true ) ;
if ( F_31 ( V_23 ) )
return F_36 ( V_23 ) ;
if ( F_65 ( V_23 -> V_26 . V_50 ,
( void V_95 * ) ( V_96 ) args -> V_72 ,
args -> V_20 ) ) {
V_57 = - V_97 ;
goto V_98;
}
memset ( V_23 -> V_26 . V_50 + args -> V_20 , 0 ,
V_23 -> V_26 . V_26 . V_20 - args -> V_20 ) ;
V_23 -> V_27 = F_66 ( & V_23 -> V_26 ) ;
if ( ! V_23 -> V_27 ) {
V_57 = - V_49 ;
goto V_98;
}
V_57 = F_37 ( V_52 , & V_23 -> V_26 . V_26 , & args -> V_60 ) ;
V_98:
F_38 ( & V_23 -> V_26 . V_26 ) ;
return V_57 ;
}
void F_67 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
F_68 ( & V_2 -> V_19 ) ;
F_18 ( & V_2 -> V_33 . V_41 ) ;
F_69 ( & V_2 -> V_33 . V_71 , F_46 ) ;
F_70 ( & V_2 -> V_33 . V_64 ,
F_48 ,
( unsigned long ) V_15 ) ;
}
void F_71 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_4 ( V_15 ) ;
F_72 ( & V_2 -> V_33 . V_64 ) ;
F_73 ( & V_2 -> V_33 . V_71 ) ;
F_20 ( V_15 ) ;
if ( V_2 -> V_3 . V_4 ) {
F_32 ( L_14 ) ;
F_1 ( V_2 ) ;
}
}

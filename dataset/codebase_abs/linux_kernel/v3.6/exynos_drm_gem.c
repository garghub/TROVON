static unsigned int F_1 ( int V_1 )
{
unsigned int V_2 ;
switch ( V_1 ) {
case 0 :
case - V_3 :
case - V_4 :
V_2 = V_5 ;
break;
case - V_6 :
V_2 = V_7 ;
break;
default:
V_2 = V_8 ;
break;
}
return V_2 ;
}
static int F_2 ( unsigned int V_9 )
{
if ( V_9 & ~ ( V_10 ) ) {
F_3 ( L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static void F_4 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
F_5 ( L_2 , V_13 -> V_9 ) ;
if ( V_13 -> V_9 & V_16 )
V_15 -> V_17 = F_6 ( V_15 -> V_18 ) ;
else if ( V_13 -> V_9 & V_19 )
V_15 -> V_17 =
F_7 ( F_6 ( V_15 -> V_18 ) ) ;
else
V_15 -> V_17 =
F_8 ( F_6 ( V_15 -> V_18 ) ) ;
}
static unsigned long F_9 ( unsigned long V_20 , unsigned int V_9 )
{
if ( ! F_10 ( V_9 ) ) {
if ( V_20 >= V_21 )
return F_11 ( V_20 , V_22 ) ;
else if ( V_20 >= V_23 )
return F_11 ( V_20 , V_23 ) ;
else
goto V_24;
}
V_24:
return F_11 ( V_20 , V_25 ) ;
}
struct V_26 * * F_12 ( struct V_27 * V_13 ,
T_1 V_28 )
{
struct V_26 * V_29 , * * V_30 ;
int V_31 , V_32 ;
V_32 = V_13 -> V_20 >> V_33 ;
V_30 = F_13 ( V_32 , sizeof( struct V_26 * ) ) ;
if ( V_30 == NULL )
return F_14 ( - V_6 ) ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_29 = F_15 ( V_28 ) ;
if ( F_16 ( V_29 ) )
goto V_34;
V_30 [ V_31 ] = V_29 ;
}
return V_30 ;
V_34:
while ( -- V_31 )
F_17 ( V_30 [ V_31 ] ) ;
F_18 ( V_30 ) ;
return F_19 ( V_29 ) ;
}
static void F_20 ( struct V_27 * V_13 ,
struct V_26 * * V_30 )
{
int V_32 ;
V_32 = V_13 -> V_20 >> V_33 ;
while ( -- V_32 >= 0 )
F_17 ( V_30 [ V_32 ] ) ;
F_18 ( V_30 ) ;
}
static int F_21 ( struct V_27 * V_13 ,
struct V_14 * V_15 ,
unsigned long V_35 ,
T_2 V_36 )
{
struct V_12 * V_37 = F_22 ( V_13 ) ;
struct V_38 * V_39 = V_37 -> V_40 ;
unsigned long V_41 ;
if ( V_37 -> V_9 & V_42 ) {
if ( ! V_39 -> V_30 )
return - V_4 ;
V_41 = F_23 ( V_39 -> V_30 [ V_36 ++ ] ) ;
} else
V_41 = ( V_39 -> V_43 >> V_33 ) + V_36 ;
return F_24 ( V_15 , V_35 , V_41 ) ;
}
static int F_25 ( struct V_27 * V_13 )
{
struct V_12 * V_37 = F_22 ( V_13 ) ;
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_44 * V_45 ;
struct V_26 * * V_30 ;
unsigned int V_32 , V_31 = 0 ;
int V_46 ;
if ( V_39 -> V_30 ) {
F_5 ( L_3 ) ;
return - V_11 ;
}
V_30 = F_12 ( V_13 , V_47 ) ;
if ( F_16 ( V_30 ) ) {
F_3 ( L_4 ) ;
return F_26 ( V_30 ) ;
}
V_32 = V_13 -> V_20 >> V_33 ;
V_39 -> V_48 = V_25 ;
V_39 -> V_49 = F_27 ( sizeof( struct V_50 ) , V_51 ) ;
if ( ! V_39 -> V_49 ) {
F_3 ( L_5 ) ;
V_46 = - V_6 ;
goto V_52;
}
V_46 = F_28 ( V_39 -> V_49 , V_32 , V_51 ) ;
if ( V_46 < 0 ) {
F_3 ( L_6 ) ;
V_46 = - V_53 ;
goto V_54;
}
V_45 = V_39 -> V_49 -> V_45 ;
while ( V_31 < V_32 ) {
F_29 ( V_45 , V_30 [ V_31 ] , V_25 , 0 ) ;
F_30 ( V_45 ) = F_31 ( V_30 [ V_31 ] ) ;
V_31 ++ ;
V_45 = F_32 ( V_45 ) ;
}
V_39 -> V_30 = V_30 ;
return V_46 ;
V_54:
F_33 ( V_39 -> V_49 ) ;
V_39 -> V_49 = NULL ;
V_52:
F_20 ( V_13 , V_30 ) ;
return V_46 ;
}
static void F_34 ( struct V_27 * V_13 )
{
struct V_12 * V_37 = F_22 ( V_13 ) ;
struct V_38 * V_39 = V_37 -> V_40 ;
F_35 ( V_39 -> V_49 ) ;
F_33 ( V_39 -> V_49 ) ;
V_39 -> V_49 = NULL ;
F_20 ( V_13 , V_39 -> V_30 ) ;
V_39 -> V_30 = NULL ;
}
static int F_36 ( struct V_27 * V_13 ,
struct V_55 * V_56 ,
unsigned int * V_57 )
{
int V_46 ;
V_46 = F_37 ( V_56 , V_13 , V_57 ) ;
if ( V_46 )
return V_46 ;
F_5 ( L_7 , * V_57 ) ;
F_38 ( V_13 ) ;
return 0 ;
}
void F_39 ( struct V_12 * V_37 )
{
struct V_27 * V_13 ;
struct V_38 * V_39 ;
F_5 ( L_8 , __FILE__ ) ;
V_13 = & V_37 -> V_58 ;
V_39 = V_37 -> V_40 ;
F_5 ( L_9 , F_40 ( & V_13 -> V_59 ) ) ;
if ( ! V_39 -> V_30 )
return;
if ( V_13 -> V_60 )
goto V_24;
if ( V_37 -> V_9 & V_42 )
F_34 ( V_13 ) ;
else
F_41 ( V_13 -> V_61 , V_37 -> V_9 , V_39 ) ;
V_24:
F_42 ( V_13 -> V_61 , V_39 ) ;
V_37 -> V_40 = NULL ;
if ( V_13 -> V_62 . V_63 )
F_43 ( V_13 ) ;
F_44 ( V_13 ) ;
F_33 ( V_37 ) ;
V_37 = NULL ;
}
struct V_12 * F_45 ( struct V_64 * V_61 ,
unsigned long V_20 )
{
struct V_12 * V_37 ;
struct V_27 * V_13 ;
int V_46 ;
V_37 = F_27 ( sizeof( * V_37 ) , V_51 ) ;
if ( ! V_37 ) {
F_3 ( L_10 ) ;
return NULL ;
}
V_37 -> V_20 = V_20 ;
V_13 = & V_37 -> V_58 ;
V_46 = F_46 ( V_61 , V_13 , V_20 ) ;
if ( V_46 < 0 ) {
F_3 ( L_11 ) ;
F_33 ( V_37 ) ;
return NULL ;
}
F_5 ( L_12 , ( unsigned int ) V_13 -> V_65 ) ;
return V_37 ;
}
struct V_12 * F_47 ( struct V_64 * V_61 ,
unsigned int V_9 ,
unsigned long V_20 )
{
struct V_12 * V_37 ;
struct V_38 * V_39 ;
int V_46 ;
if ( ! V_20 ) {
F_3 ( L_13 ) ;
return F_14 ( - V_11 ) ;
}
V_20 = F_9 ( V_20 , V_9 ) ;
F_5 ( L_8 , __FILE__ ) ;
V_46 = F_2 ( V_9 ) ;
if ( V_46 )
return F_14 ( V_46 ) ;
V_39 = F_48 ( V_61 , V_20 ) ;
if ( ! V_39 )
return F_14 ( - V_6 ) ;
V_37 = F_45 ( V_61 , V_20 ) ;
if ( ! V_37 ) {
V_46 = - V_6 ;
goto V_66;
}
V_37 -> V_40 = V_39 ;
V_37 -> V_9 = V_9 ;
if ( V_9 & V_42 ) {
V_46 = F_25 ( & V_37 -> V_58 ) ;
if ( V_46 < 0 ) {
F_44 ( & V_37 -> V_58 ) ;
goto V_66;
}
} else {
V_46 = F_49 ( V_61 , V_39 , V_9 ) ;
if ( V_46 < 0 ) {
F_44 ( & V_37 -> V_58 ) ;
goto V_66;
}
}
return V_37 ;
V_66:
F_42 ( V_61 , V_39 ) ;
return F_14 ( V_46 ) ;
}
int F_50 ( struct V_64 * V_61 , void * V_67 ,
struct V_55 * V_56 )
{
struct V_68 * args = V_67 ;
struct V_12 * V_37 ;
int V_46 ;
F_5 ( L_8 , __FILE__ ) ;
V_37 = F_47 ( V_61 , args -> V_9 , args -> V_20 ) ;
if ( F_16 ( V_37 ) )
return F_26 ( V_37 ) ;
V_46 = F_36 ( & V_37 -> V_58 , V_56 ,
& args -> V_57 ) ;
if ( V_46 ) {
F_39 ( V_37 ) ;
return V_46 ;
}
return 0 ;
}
void * F_51 ( struct V_64 * V_61 ,
unsigned int V_69 ,
struct V_55 * V_56 )
{
struct V_12 * V_37 ;
struct V_27 * V_13 ;
V_13 = F_52 ( V_61 , V_56 , V_69 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
return F_14 ( - V_11 ) ;
}
V_37 = F_22 ( V_13 ) ;
if ( V_37 -> V_9 & V_42 ) {
F_5 ( L_15 ) ;
F_38 ( V_13 ) ;
return F_14 ( - V_11 ) ;
}
return & V_37 -> V_40 -> V_43 ;
}
void F_53 ( struct V_64 * V_61 ,
unsigned int V_69 ,
struct V_55 * V_56 )
{
struct V_12 * V_37 ;
struct V_27 * V_13 ;
V_13 = F_52 ( V_61 , V_56 , V_69 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
return;
}
V_37 = F_22 ( V_13 ) ;
if ( V_37 -> V_9 & V_42 ) {
F_5 ( L_15 ) ;
F_38 ( V_13 ) ;
return;
}
F_38 ( V_13 ) ;
F_38 ( V_13 ) ;
}
int F_54 ( struct V_64 * V_61 , void * V_67 ,
struct V_55 * V_56 )
{
struct V_70 * args = V_67 ;
F_5 ( L_8 , __FILE__ ) ;
F_5 ( L_16 ,
args -> V_57 , ( unsigned long ) args -> V_71 ) ;
if ( ! ( V_61 -> V_72 -> V_73 & V_74 ) ) {
F_3 ( L_17 ) ;
return - V_75 ;
}
return F_55 ( V_56 , V_61 , args -> V_57 ,
& args -> V_71 ) ;
}
static int F_56 ( struct V_76 * V_65 ,
struct V_14 * V_15 )
{
struct V_27 * V_13 = V_65 -> V_77 ;
struct V_12 * V_37 = F_22 ( V_13 ) ;
struct V_38 * V_40 ;
unsigned long V_41 , V_78 , V_79 , V_80 = V_15 -> V_81 ;
int V_46 ;
F_5 ( L_8 , __FILE__ ) ;
V_15 -> V_18 |= ( V_82 | V_83 ) ;
F_4 ( V_37 , V_15 ) ;
V_78 = V_79 = V_15 -> V_84 - V_15 -> V_81 ;
V_40 = V_37 -> V_40 ;
if ( V_78 > V_40 -> V_20 )
return - V_11 ;
if ( V_37 -> V_9 & V_42 ) {
int V_31 = 0 ;
if ( ! V_40 -> V_30 )
return - V_11 ;
V_15 -> V_18 |= V_85 ;
do {
V_46 = F_57 ( V_15 , V_80 , V_40 -> V_30 [ V_31 ++ ] ) ;
if ( V_46 ) {
F_3 ( L_18 ) ;
return V_46 ;
}
V_80 += V_25 ;
V_79 -= V_25 ;
} while ( V_79 > 0 );
} else {
V_41 = ( ( unsigned long ) V_37 -> V_40 -> V_43 ) >>
V_33 ;
F_5 ( L_19 , V_41 ) ;
if ( F_58 ( V_15 , V_15 -> V_81 , V_41 , V_78 ,
V_15 -> V_17 ) ) {
F_3 ( L_20 ) ;
return - V_86 ;
}
}
return 0 ;
}
int F_59 ( struct V_64 * V_61 , void * V_67 ,
struct V_55 * V_56 )
{
struct V_87 * args = V_67 ;
struct V_27 * V_13 ;
unsigned int V_88 ;
F_5 ( L_8 , __FILE__ ) ;
if ( ! ( V_61 -> V_72 -> V_73 & V_74 ) ) {
F_3 ( L_17 ) ;
return - V_75 ;
}
V_13 = F_52 ( V_61 , V_56 , args -> V_57 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
return - V_11 ;
}
V_13 -> V_65 -> V_89 = & V_90 ;
V_13 -> V_65 -> V_77 = V_13 ;
V_88 = F_60 ( V_13 -> V_65 , 0 , args -> V_20 ,
V_91 | V_92 , V_93 , 0 ) ;
F_38 ( V_13 ) ;
if ( F_16 ( ( void * ) V_88 ) )
return F_26 ( ( void * ) V_88 ) ;
args -> V_94 = V_88 ;
F_5 ( L_21 , ( unsigned long ) args -> V_94 ) ;
return 0 ;
}
int F_61 ( struct V_64 * V_61 , void * V_67 ,
struct V_55 * V_56 )
{ struct V_12 * V_37 ;
struct V_95 * args = V_67 ;
struct V_27 * V_13 ;
F_62 ( & V_61 -> V_96 ) ;
V_13 = F_52 ( V_61 , V_56 , args -> V_57 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
F_63 ( & V_61 -> V_96 ) ;
return - V_11 ;
}
V_37 = F_22 ( V_13 ) ;
args -> V_9 = V_37 -> V_9 ;
args -> V_20 = V_37 -> V_20 ;
F_64 ( V_13 ) ;
F_63 ( & V_61 -> V_96 ) ;
return 0 ;
}
int F_65 ( struct V_27 * V_13 )
{
F_5 ( L_8 , __FILE__ ) ;
return 0 ;
}
void F_66 ( struct V_27 * V_13 )
{
struct V_12 * V_37 ;
struct V_38 * V_39 ;
F_5 ( L_8 , __FILE__ ) ;
V_37 = F_22 ( V_13 ) ;
V_39 = V_37 -> V_40 ;
if ( V_13 -> V_60 )
F_67 ( V_13 , V_39 -> V_49 ) ;
F_39 ( F_22 ( V_13 ) ) ;
}
int F_68 ( struct V_55 * V_56 ,
struct V_64 * V_61 ,
struct V_97 * args )
{
struct V_12 * V_37 ;
int V_46 ;
F_5 ( L_8 , __FILE__ ) ;
args -> V_98 = args -> V_99 * ( ( args -> V_100 + 7 ) / 8 ) ;
args -> V_20 = args -> V_98 * args -> V_101 ;
V_37 = F_47 ( V_61 , args -> V_9 , args -> V_20 ) ;
if ( F_16 ( V_37 ) )
return F_26 ( V_37 ) ;
V_46 = F_36 ( & V_37 -> V_58 , V_56 ,
& args -> V_57 ) ;
if ( V_46 ) {
F_39 ( V_37 ) ;
return V_46 ;
}
return 0 ;
}
int F_55 ( struct V_55 * V_56 ,
struct V_64 * V_61 , T_3 V_57 ,
T_4 * V_71 )
{
struct V_27 * V_13 ;
int V_46 = 0 ;
F_5 ( L_8 , __FILE__ ) ;
F_62 ( & V_61 -> V_96 ) ;
V_13 = F_52 ( V_61 , V_56 , V_57 ) ;
if ( ! V_13 ) {
F_3 ( L_14 ) ;
V_46 = - V_11 ;
goto V_102;
}
if ( ! V_13 -> V_62 . V_63 ) {
V_46 = F_69 ( V_13 ) ;
if ( V_46 )
goto V_24;
}
* V_71 = ( V_103 ) V_13 -> V_62 . V_104 . V_105 << V_33 ;
F_5 ( L_22 , ( unsigned long ) * V_71 ) ;
V_24:
F_64 ( V_13 ) ;
V_102:
F_63 ( & V_61 -> V_96 ) ;
return V_46 ;
}
int F_70 ( struct V_55 * V_56 ,
struct V_64 * V_61 ,
unsigned int V_57 )
{
int V_46 ;
F_5 ( L_8 , __FILE__ ) ;
V_46 = F_71 ( V_56 , V_57 ) ;
if ( V_46 < 0 ) {
F_3 ( L_23 ) ;
return V_46 ;
}
return 0 ;
}
int F_72 ( struct V_14 * V_15 , struct V_106 * V_107 )
{
struct V_27 * V_13 = V_15 -> V_108 ;
struct V_64 * V_61 = V_13 -> V_61 ;
unsigned long V_35 ;
T_2 V_36 ;
int V_46 ;
V_36 = ( ( unsigned long ) V_107 -> V_109 -
V_15 -> V_81 ) >> V_33 ;
V_35 = ( unsigned long ) V_107 -> V_109 ;
F_62 ( & V_61 -> V_96 ) ;
V_46 = F_21 ( V_13 , V_15 , V_35 , V_36 ) ;
if ( V_46 < 0 )
F_3 ( L_24 ) ;
F_63 ( & V_61 -> V_96 ) ;
return F_1 ( V_46 ) ;
}
int F_73 ( struct V_76 * V_65 , struct V_14 * V_15 )
{
struct V_12 * V_37 ;
struct V_27 * V_13 ;
int V_46 ;
F_5 ( L_8 , __FILE__ ) ;
V_46 = F_74 ( V_65 , V_15 ) ;
if ( V_46 < 0 ) {
F_3 ( L_25 ) ;
return V_46 ;
}
V_13 = V_15 -> V_108 ;
V_37 = F_22 ( V_13 ) ;
V_46 = F_2 ( V_37 -> V_9 ) ;
if ( V_46 ) {
F_75 ( V_15 ) ;
F_43 ( V_13 ) ;
return V_46 ;
}
V_15 -> V_18 &= ~ V_110 ;
V_15 -> V_18 |= V_85 ;
F_4 ( V_37 , V_15 ) ;
return V_46 ;
}

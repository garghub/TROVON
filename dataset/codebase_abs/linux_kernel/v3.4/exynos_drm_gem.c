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
static unsigned long F_4 ( unsigned long V_12 , unsigned int V_9 )
{
if ( ! F_5 ( V_9 ) ) {
if ( V_12 >= V_13 )
return F_6 ( V_12 , V_14 ) ;
else if ( V_12 >= V_15 )
return F_6 ( V_12 , V_15 ) ;
else
goto V_16;
}
V_16:
return F_6 ( V_12 , V_17 ) ;
}
static struct V_18 * * F_7 ( struct V_19 * V_20 ,
T_1 V_21 )
{
struct V_22 * V_22 ;
struct V_23 * V_24 ;
struct V_18 * V_25 , * * V_26 ;
int V_27 , V_28 ;
V_22 = V_20 -> V_29 -> V_30 . V_31 -> V_32 ;
V_24 = V_22 -> V_33 ;
V_28 = V_20 -> V_12 >> V_34 ;
V_26 = F_8 ( V_28 , sizeof( struct V_18 * ) ) ;
if ( V_26 == NULL )
return F_9 ( - V_6 ) ;
V_21 |= F_10 ( V_24 ) ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_25 = F_11 ( V_24 , V_27 , V_21 ) ;
if ( F_12 ( V_25 ) )
goto V_35;
V_26 [ V_27 ] = V_25 ;
}
return V_26 ;
V_35:
while ( V_27 -- )
F_13 ( V_26 [ V_27 ] ) ;
F_14 ( V_26 ) ;
return F_9 ( F_15 ( V_25 ) ) ;
}
static void F_16 ( struct V_19 * V_20 ,
struct V_18 * * V_26 ,
bool V_36 , bool V_37 )
{
int V_27 , V_28 ;
V_28 = V_20 -> V_12 >> V_34 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
if ( V_36 )
F_17 ( V_26 [ V_27 ] ) ;
if ( V_37 )
F_18 ( V_26 [ V_27 ] ) ;
F_13 ( V_26 [ V_27 ] ) ;
}
F_14 ( V_26 ) ;
}
static int F_19 ( struct V_19 * V_20 ,
struct V_38 * V_39 ,
unsigned long V_40 ,
T_2 V_41 )
{
struct V_42 * V_43 = F_20 ( V_20 ) ;
struct V_44 * V_45 = V_43 -> V_46 ;
unsigned long V_47 ;
if ( V_43 -> V_9 & V_48 ) {
if ( ! V_45 -> V_26 )
return - V_4 ;
V_47 = F_21 ( V_45 -> V_26 [ V_41 ++ ] ) ;
} else
V_47 = ( V_45 -> V_49 >> V_34 ) + V_41 ;
return F_22 ( V_39 , V_40 , V_47 ) ;
}
static int F_23 ( struct V_19 * V_20 )
{
struct V_42 * V_43 = F_20 ( V_20 ) ;
struct V_44 * V_45 = V_43 -> V_46 ;
struct V_50 * V_51 ;
struct V_18 * * V_26 ;
unsigned int V_28 , V_27 = 0 ;
int V_52 ;
if ( V_45 -> V_26 ) {
F_24 ( L_2 ) ;
return - V_11 ;
}
V_26 = F_7 ( V_20 , V_53 ) ;
if ( F_12 ( V_26 ) ) {
F_3 ( L_3 ) ;
return F_15 ( V_26 ) ;
}
V_28 = V_20 -> V_12 >> V_34 ;
V_45 -> V_54 = F_25 ( sizeof( struct V_55 ) , V_53 ) ;
if ( ! V_45 -> V_54 ) {
F_3 ( L_4 ) ;
V_52 = - V_6 ;
goto V_56;
}
V_52 = F_26 ( V_45 -> V_54 , V_28 , V_53 ) ;
if ( V_52 < 0 ) {
F_3 ( L_5 ) ;
V_52 = - V_57 ;
goto V_58;
}
V_51 = V_45 -> V_54 -> V_51 ;
while ( V_27 < V_28 ) {
F_27 ( V_51 , V_26 [ V_27 ] , V_17 , 0 ) ;
F_28 ( V_51 ) = F_29 ( V_26 [ V_27 ] ) ;
V_27 ++ ;
V_51 = F_30 ( V_51 ) ;
}
V_45 -> V_26 = V_26 ;
return V_52 ;
V_58:
F_31 ( V_45 -> V_54 ) ;
V_45 -> V_54 = NULL ;
V_56:
F_16 ( V_20 , V_26 , true , false ) ;
return V_52 ;
}
static void F_32 ( struct V_19 * V_20 )
{
struct V_42 * V_43 = F_20 ( V_20 ) ;
struct V_44 * V_45 = V_43 -> V_46 ;
F_33 ( V_45 -> V_54 ) ;
F_31 ( V_45 -> V_54 ) ;
V_45 -> V_54 = NULL ;
F_16 ( V_20 , V_45 -> V_26 , true , false ) ;
V_45 -> V_26 = NULL ;
}
static int F_34 ( struct V_19 * V_20 ,
struct V_59 * V_60 ,
unsigned int * V_61 )
{
int V_52 ;
V_52 = F_35 ( V_60 , V_20 , V_61 ) ;
if ( V_52 )
return V_52 ;
F_24 ( L_6 , * V_61 ) ;
F_36 ( V_20 ) ;
return 0 ;
}
void F_37 ( struct V_42 * V_43 )
{
struct V_19 * V_20 ;
F_24 ( L_7 , __FILE__ ) ;
if ( ! V_43 )
return;
V_20 = & V_43 -> V_62 ;
F_24 ( L_8 , F_38 ( & V_20 -> V_63 ) ) ;
if ( ( V_43 -> V_9 & V_48 ) &&
V_43 -> V_46 -> V_26 )
F_32 ( V_20 ) ;
else
F_39 ( V_20 -> V_64 , V_43 -> V_9 ,
V_43 -> V_46 ) ;
F_40 ( V_20 -> V_64 , V_43 -> V_46 ) ;
V_43 -> V_46 = NULL ;
if ( V_20 -> V_65 . V_66 )
F_41 ( V_20 ) ;
F_42 ( V_20 ) ;
F_31 ( V_43 ) ;
V_43 = NULL ;
}
static struct V_42 * F_43 ( struct V_67 * V_64 ,
unsigned long V_12 )
{
struct V_42 * V_43 ;
struct V_19 * V_20 ;
int V_52 ;
V_43 = F_25 ( sizeof( * V_43 ) , V_53 ) ;
if ( ! V_43 ) {
F_3 ( L_9 ) ;
return NULL ;
}
V_43 -> V_12 = V_12 ;
V_20 = & V_43 -> V_62 ;
V_52 = F_44 ( V_64 , V_20 , V_12 ) ;
if ( V_52 < 0 ) {
F_3 ( L_10 ) ;
F_31 ( V_43 ) ;
return NULL ;
}
F_24 ( L_11 , ( unsigned int ) V_20 -> V_29 ) ;
return V_43 ;
}
struct V_42 * F_45 ( struct V_67 * V_64 ,
unsigned int V_9 ,
unsigned long V_12 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_52 ;
if ( ! V_12 ) {
F_3 ( L_12 ) ;
return F_9 ( - V_11 ) ;
}
V_12 = F_4 ( V_12 , V_9 ) ;
F_24 ( L_7 , __FILE__ ) ;
V_52 = F_2 ( V_9 ) ;
if ( V_52 )
return F_9 ( V_52 ) ;
V_45 = F_46 ( V_64 , V_12 ) ;
if ( ! V_45 )
return F_9 ( - V_6 ) ;
V_43 = F_43 ( V_64 , V_12 ) ;
if ( ! V_43 ) {
V_52 = - V_6 ;
goto V_68;
}
V_43 -> V_46 = V_45 ;
V_43 -> V_9 = V_9 ;
if ( V_9 & V_48 ) {
V_52 = F_23 ( & V_43 -> V_62 ) ;
if ( V_52 < 0 ) {
F_42 ( & V_43 -> V_62 ) ;
goto V_68;
}
} else {
V_52 = F_47 ( V_64 , V_45 , V_9 ) ;
if ( V_52 < 0 ) {
F_42 ( & V_43 -> V_62 ) ;
goto V_68;
}
}
return V_43 ;
V_68:
F_40 ( V_64 , V_45 ) ;
return F_9 ( V_52 ) ;
}
int F_48 ( struct V_67 * V_64 , void * V_69 ,
struct V_59 * V_60 )
{
struct V_70 * args = V_69 ;
struct V_42 * V_43 ;
int V_52 ;
F_24 ( L_7 , __FILE__ ) ;
V_43 = F_45 ( V_64 , args -> V_9 , args -> V_12 ) ;
if ( F_12 ( V_43 ) )
return F_15 ( V_43 ) ;
V_52 = F_34 ( & V_43 -> V_62 , V_60 ,
& args -> V_61 ) ;
if ( V_52 ) {
F_37 ( V_43 ) ;
return V_52 ;
}
return 0 ;
}
void * F_49 ( struct V_67 * V_64 ,
unsigned int V_71 ,
struct V_59 * V_60 )
{
struct V_42 * V_43 ;
struct V_19 * V_20 ;
V_20 = F_50 ( V_64 , V_60 , V_71 ) ;
if ( ! V_20 ) {
F_3 ( L_13 ) ;
return F_9 ( - V_11 ) ;
}
V_43 = F_20 ( V_20 ) ;
if ( V_43 -> V_9 & V_48 ) {
F_24 ( L_14 ) ;
F_36 ( V_20 ) ;
return F_9 ( - V_11 ) ;
}
return & V_43 -> V_46 -> V_49 ;
}
void F_51 ( struct V_67 * V_64 ,
unsigned int V_71 ,
struct V_59 * V_60 )
{
struct V_42 * V_43 ;
struct V_19 * V_20 ;
V_20 = F_50 ( V_64 , V_60 , V_71 ) ;
if ( ! V_20 ) {
F_3 ( L_13 ) ;
return;
}
V_43 = F_20 ( V_20 ) ;
if ( V_43 -> V_9 & V_48 ) {
F_24 ( L_14 ) ;
F_36 ( V_20 ) ;
return;
}
F_36 ( V_20 ) ;
F_36 ( V_20 ) ;
}
int F_52 ( struct V_67 * V_64 , void * V_69 ,
struct V_59 * V_60 )
{
struct V_72 * args = V_69 ;
F_24 ( L_7 , __FILE__ ) ;
F_24 ( L_15 ,
args -> V_61 , ( unsigned long ) args -> V_73 ) ;
if ( ! ( V_64 -> V_74 -> V_75 & V_76 ) ) {
F_3 ( L_16 ) ;
return - V_77 ;
}
return F_53 ( V_60 , V_64 , args -> V_61 ,
& args -> V_73 ) ;
}
static int F_54 ( struct V_78 * V_29 ,
struct V_38 * V_39 )
{
struct V_19 * V_20 = V_29 -> V_79 ;
struct V_42 * V_43 = F_20 ( V_20 ) ;
struct V_44 * V_46 ;
unsigned long V_47 , V_80 , V_81 , V_82 = V_39 -> V_83 ;
int V_52 ;
F_24 ( L_7 , __FILE__ ) ;
V_39 -> V_84 |= ( V_85 | V_86 ) ;
V_39 -> V_87 = F_55 ( V_39 -> V_87 ) ;
V_80 = V_81 = V_39 -> V_88 - V_39 -> V_83 ;
V_46 = V_43 -> V_46 ;
if ( V_80 > V_46 -> V_12 )
return - V_11 ;
if ( V_43 -> V_9 & V_48 ) {
int V_27 = 0 ;
if ( ! V_46 -> V_26 )
return - V_11 ;
V_39 -> V_84 |= V_89 ;
do {
V_52 = F_56 ( V_39 , V_82 , V_46 -> V_26 [ V_27 ++ ] ) ;
if ( V_52 ) {
F_3 ( L_17 ) ;
return V_52 ;
}
V_82 += V_17 ;
V_81 -= V_17 ;
} while ( V_81 > 0 );
} else {
V_47 = ( ( unsigned long ) V_43 -> V_46 -> V_49 ) >>
V_34 ;
F_24 ( L_18 , V_47 ) ;
if ( F_57 ( V_39 , V_39 -> V_83 , V_47 , V_80 ,
V_39 -> V_87 ) ) {
F_3 ( L_19 ) ;
return - V_90 ;
}
}
return 0 ;
}
int F_58 ( struct V_67 * V_64 , void * V_69 ,
struct V_59 * V_60 )
{
struct V_91 * args = V_69 ;
struct V_19 * V_20 ;
unsigned int V_92 ;
F_24 ( L_7 , __FILE__ ) ;
if ( ! ( V_64 -> V_74 -> V_75 & V_76 ) ) {
F_3 ( L_16 ) ;
return - V_77 ;
}
V_20 = F_50 ( V_64 , V_60 , args -> V_61 ) ;
if ( ! V_20 ) {
F_3 ( L_13 ) ;
return - V_11 ;
}
V_20 -> V_29 -> V_93 = & V_94 ;
V_20 -> V_29 -> V_79 = V_20 ;
V_92 = F_59 ( V_20 -> V_29 , 0 , args -> V_12 ,
V_95 | V_96 , V_97 , 0 ) ;
F_36 ( V_20 ) ;
if ( F_12 ( ( void * ) V_92 ) )
return F_15 ( ( void * ) V_92 ) ;
args -> V_98 = V_92 ;
F_24 ( L_20 , ( unsigned long ) args -> V_98 ) ;
return 0 ;
}
int F_60 ( struct V_19 * V_20 )
{
F_24 ( L_7 , __FILE__ ) ;
return 0 ;
}
void F_61 ( struct V_19 * V_20 )
{
F_24 ( L_7 , __FILE__ ) ;
F_37 ( F_20 ( V_20 ) ) ;
}
int F_62 ( struct V_59 * V_60 ,
struct V_67 * V_64 ,
struct V_99 * args )
{
struct V_42 * V_43 ;
int V_52 ;
F_24 ( L_7 , __FILE__ ) ;
args -> V_100 = args -> V_101 * args -> V_102 >> 3 ;
args -> V_12 = F_63 ( args -> V_100 * args -> V_103 ) ;
V_43 = F_45 ( V_64 , args -> V_9 , args -> V_12 ) ;
if ( F_12 ( V_43 ) )
return F_15 ( V_43 ) ;
V_52 = F_34 ( & V_43 -> V_62 , V_60 ,
& args -> V_61 ) ;
if ( V_52 ) {
F_37 ( V_43 ) ;
return V_52 ;
}
return 0 ;
}
int F_53 ( struct V_59 * V_60 ,
struct V_67 * V_64 , T_3 V_61 ,
T_4 * V_73 )
{
struct V_42 * V_43 ;
struct V_19 * V_20 ;
int V_52 = 0 ;
F_24 ( L_7 , __FILE__ ) ;
F_64 ( & V_64 -> V_104 ) ;
V_20 = F_50 ( V_64 , V_60 , V_61 ) ;
if ( ! V_20 ) {
F_3 ( L_13 ) ;
V_52 = - V_11 ;
goto V_105;
}
V_43 = F_20 ( V_20 ) ;
if ( ! V_43 -> V_62 . V_65 . V_66 ) {
V_52 = F_65 ( & V_43 -> V_62 ) ;
if ( V_52 )
goto V_16;
}
* V_73 = ( V_106 ) V_43 -> V_62 . V_65 . V_107 . V_108 << V_34 ;
F_24 ( L_21 , ( unsigned long ) * V_73 ) ;
V_16:
F_66 ( V_20 ) ;
V_105:
F_67 ( & V_64 -> V_104 ) ;
return V_52 ;
}
int F_68 ( struct V_59 * V_60 ,
struct V_67 * V_64 ,
unsigned int V_61 )
{
int V_52 ;
F_24 ( L_7 , __FILE__ ) ;
V_52 = F_69 ( V_60 , V_61 ) ;
if ( V_52 < 0 ) {
F_3 ( L_22 ) ;
return V_52 ;
}
return 0 ;
}
int F_70 ( struct V_38 * V_39 , struct V_109 * V_110 )
{
struct V_19 * V_20 = V_39 -> V_111 ;
struct V_67 * V_64 = V_20 -> V_64 ;
unsigned long V_40 ;
T_2 V_41 ;
int V_52 ;
V_41 = ( ( unsigned long ) V_110 -> V_112 -
V_39 -> V_83 ) >> V_34 ;
V_40 = ( unsigned long ) V_110 -> V_112 ;
F_64 ( & V_64 -> V_104 ) ;
V_52 = F_19 ( V_20 , V_39 , V_40 , V_41 ) ;
if ( V_52 < 0 )
F_3 ( L_23 ) ;
F_67 ( & V_64 -> V_104 ) ;
return F_1 ( V_52 ) ;
}
int F_71 ( struct V_78 * V_29 , struct V_38 * V_39 )
{
int V_52 ;
F_24 ( L_7 , __FILE__ ) ;
V_52 = F_72 ( V_29 , V_39 ) ;
if ( V_52 < 0 ) {
F_3 ( L_24 ) ;
return V_52 ;
}
V_39 -> V_84 &= ~ V_113 ;
V_39 -> V_84 |= V_89 ;
return V_52 ;
}

static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
unsigned int V_4 = 0 ;
int V_5 = V_2 -> V_5 ;
while ( V_5 > 0 ) {
struct V_6 * V_7 ;
int V_8 ;
int V_9 ;
V_8 = F_2 ( V_5 ) ;
if ( ( V_10 << V_8 ) > V_5 )
V_8 -- ;
V_7 = NULL ;
while ( ! V_7 ) {
V_7 = F_3 ( V_11 | V_12 |
V_13 | V_3 , V_8 ) ;
if ( V_7 )
break;
if ( V_8 == 0 ) {
while ( V_4 -- )
F_4 ( V_2 -> V_7 [ V_4 ] ) ;
return - V_14 ;
}
V_8 -- ;
}
F_5 ( V_7 , V_8 ) ;
for ( V_9 = 0 ; V_9 < ( 1 << V_8 ) ; V_9 ++ )
V_2 -> V_7 [ V_4 ++ ] = & V_7 [ V_9 ] ;
V_5 -= V_10 << V_8 ;
}
return 0 ;
}
static void * F_6 ( struct V_15 * V_16 , unsigned long V_17 ,
unsigned long V_5 , enum V_18 V_19 ,
T_1 V_3 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_22 ;
int V_23 ;
if ( F_7 ( ! V_16 ) )
return F_8 ( - V_24 ) ;
V_2 = F_9 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return F_8 ( - V_14 ) ;
V_2 -> V_25 = NULL ;
V_2 -> V_19 = V_19 ;
V_2 -> V_26 = 0 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_23 = V_5 >> V_27 ;
V_2 -> V_28 = & V_2 -> V_20 ;
V_2 -> V_7 = F_9 ( V_2 -> V_23 * sizeof( struct V_6 * ) ,
V_11 ) ;
if ( ! V_2 -> V_7 )
goto V_29;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_22 )
goto V_30;
V_22 = F_10 ( V_2 -> V_28 , V_2 -> V_7 ,
V_2 -> V_23 , 0 , V_5 , V_11 ) ;
if ( V_22 )
goto V_31;
V_2 -> V_16 = F_11 ( V_16 ) ;
V_21 = & V_2 -> V_20 ;
V_21 -> V_32 = F_12 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_2 -> V_19 , V_35 ) ;
if ( ! V_21 -> V_32 )
goto V_36;
V_2 -> V_37 . V_38 = & V_2 -> V_38 ;
V_2 -> V_37 . V_39 = V_40 ;
V_2 -> V_37 . V_41 = V_2 ;
F_13 ( & V_2 -> V_38 ) ;
F_14 ( 1 , L_1 ,
V_42 , V_2 -> V_23 ) ;
return V_2 ;
V_36:
F_15 ( V_2 -> V_16 ) ;
F_16 ( V_2 -> V_28 ) ;
V_31:
V_23 = V_2 -> V_23 ;
while ( V_23 -- )
F_4 ( V_2 -> V_7 [ V_23 ] ) ;
V_30:
F_17 ( V_2 -> V_7 ) ;
V_29:
F_17 ( V_2 ) ;
return F_8 ( - V_14 ) ;
}
static void V_40 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
if ( F_18 ( & V_2 -> V_38 ) ) {
F_14 ( 1 , L_2 , V_42 ,
V_2 -> V_23 ) ;
F_19 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_2 -> V_19 , V_35 ) ;
if ( V_2 -> V_25 )
F_20 ( V_2 -> V_25 , V_2 -> V_23 ) ;
F_16 ( V_2 -> V_28 ) ;
while ( -- V_9 >= 0 )
F_4 ( V_2 -> V_7 [ V_9 ] ) ;
F_17 ( V_2 -> V_7 ) ;
F_15 ( V_2 -> V_16 ) ;
F_17 ( V_2 ) ;
}
}
static void F_21 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = V_2 -> V_28 ;
if ( V_2 -> V_44 )
return;
F_22 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_2 -> V_19 ) ;
}
static void F_23 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = V_2 -> V_28 ;
if ( V_2 -> V_44 )
return;
F_24 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 , V_2 -> V_19 ) ;
}
static void * F_25 ( struct V_15 * V_16 , unsigned long V_25 ,
unsigned long V_5 ,
enum V_18 V_19 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_45 * V_46 ;
if ( F_7 ( ! V_16 ) )
return F_8 ( - V_24 ) ;
V_2 = F_9 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return F_8 ( - V_14 ) ;
V_2 -> V_25 = NULL ;
V_2 -> V_16 = V_16 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_26 = V_25 & ~ V_47 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_28 = & V_2 -> V_20 ;
V_46 = F_26 ( V_25 , V_5 , V_2 -> V_19 == V_48 ) ;
if ( F_27 ( V_46 ) )
goto V_49;
V_2 -> V_46 = V_46 ;
V_2 -> V_7 = F_28 ( V_46 ) ;
if ( F_27 ( V_2 -> V_7 ) )
goto V_50;
V_2 -> V_23 = F_29 ( V_46 ) ;
if ( F_10 ( V_2 -> V_28 , V_2 -> V_7 ,
V_2 -> V_23 , V_2 -> V_26 , V_5 , 0 ) )
goto V_50;
V_21 = & V_2 -> V_20 ;
V_21 -> V_32 = F_12 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_2 -> V_19 , V_35 ) ;
if ( ! V_21 -> V_32 )
goto V_51;
return V_2 ;
V_51:
F_16 ( & V_2 -> V_20 ) ;
V_50:
F_30 ( V_46 ) ;
V_49:
F_17 ( V_2 ) ;
return F_8 ( - V_14 ) ;
}
static void F_31 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
F_14 ( 1 , L_3 ,
V_42 , V_2 -> V_23 ) ;
F_19 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 , V_2 -> V_19 ,
V_35 ) ;
if ( V_2 -> V_25 )
F_20 ( V_2 -> V_25 , V_2 -> V_23 ) ;
F_16 ( V_2 -> V_28 ) ;
while ( -- V_9 >= 0 ) {
if ( V_2 -> V_19 == V_48 )
F_32 ( V_2 -> V_7 [ V_9 ] ) ;
}
F_30 ( V_2 -> V_46 ) ;
F_17 ( V_2 ) ;
}
static void * F_33 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
F_34 ( ! V_2 ) ;
if ( ! V_2 -> V_25 ) {
if ( V_2 -> V_44 )
V_2 -> V_25 = F_35 ( V_2 -> V_44 -> V_52 ) ;
else
V_2 -> V_25 = F_36 ( V_2 -> V_7 ,
V_2 -> V_23 , - 1 , V_53 ) ;
}
return V_2 -> V_25 ? V_2 -> V_25 + V_2 -> V_26 : NULL ;
}
static unsigned int F_37 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
return F_38 ( & V_2 -> V_38 ) ;
}
static int F_39 ( void * V_43 , struct V_54 * V_55 )
{
struct V_1 * V_2 = V_43 ;
unsigned long V_56 = V_55 -> V_57 ;
unsigned long V_58 = V_55 -> V_59 - V_55 -> V_57 ;
int V_9 = 0 ;
if ( ! V_2 ) {
F_40 ( V_60 L_4 ) ;
return - V_24 ;
}
do {
int V_22 ;
V_22 = F_41 ( V_55 , V_56 , V_2 -> V_7 [ V_9 ++ ] ) ;
if ( V_22 ) {
F_40 ( V_60 L_5 , V_22 ) ;
return V_22 ;
}
V_56 += V_10 ;
V_58 -= V_10 ;
} while ( V_58 > 0 );
V_55 -> V_61 = & V_2 -> V_37 ;
V_55 -> V_62 = & V_63 ;
V_55 -> V_62 -> V_64 ( V_55 ) ;
return 0 ;
}
static int F_42 ( struct V_65 * V_66 , struct V_15 * V_16 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 ;
unsigned int V_9 ;
struct V_71 * V_72 , * V_73 ;
struct V_20 * V_21 ;
struct V_1 * V_2 = V_66 -> V_74 ;
int V_22 ;
V_70 = F_9 ( sizeof( * V_70 ) , V_11 ) ;
if ( ! V_70 )
return - V_14 ;
V_21 = & V_70 -> V_21 ;
V_22 = F_43 ( V_21 , V_2 -> V_28 -> V_34 , V_11 ) ;
if ( V_22 ) {
F_17 ( V_70 ) ;
return - V_14 ;
}
V_72 = V_2 -> V_28 -> V_33 ;
V_73 = V_21 -> V_33 ;
for ( V_9 = 0 ; V_9 < V_21 -> V_34 ; ++ V_9 ) {
F_44 ( V_73 , F_45 ( V_72 ) , V_72 -> V_75 , V_72 -> V_26 ) ;
V_72 = F_46 ( V_72 ) ;
V_73 = F_46 ( V_73 ) ;
}
V_70 -> V_19 = V_76 ;
V_68 -> V_74 = V_70 ;
return 0 ;
}
static void F_47 ( struct V_65 * V_66 ,
struct V_67 * V_44 )
{
struct V_69 * V_70 = V_44 -> V_74 ;
struct V_20 * V_21 ;
if ( ! V_70 )
return;
V_21 = & V_70 -> V_21 ;
if ( V_70 -> V_19 != V_76 )
F_48 ( V_44 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_70 -> V_19 ) ;
F_16 ( V_21 ) ;
F_17 ( V_70 ) ;
V_44 -> V_74 = NULL ;
}
static struct V_20 * F_49 (
struct V_67 * V_44 , enum V_18 V_19 )
{
struct V_69 * V_70 = V_44 -> V_74 ;
struct V_77 * V_78 = & V_44 -> V_52 -> V_78 ;
struct V_20 * V_21 ;
F_50 ( V_78 ) ;
V_21 = & V_70 -> V_21 ;
if ( V_70 -> V_19 == V_19 ) {
F_51 ( V_78 ) ;
return V_21 ;
}
if ( V_70 -> V_19 != V_76 ) {
F_48 ( V_44 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_70 -> V_19 ) ;
V_70 -> V_19 = V_76 ;
}
V_21 -> V_32 = F_52 ( V_44 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_19 ) ;
if ( ! V_21 -> V_32 ) {
F_53 ( L_6 ) ;
F_51 ( V_78 ) ;
return F_8 ( - V_79 ) ;
}
V_70 -> V_19 = V_19 ;
F_51 ( V_78 ) ;
return V_21 ;
}
static void F_54 ( struct V_67 * V_44 ,
struct V_20 * V_21 , enum V_18 V_19 )
{
}
static void F_55 ( struct V_65 * V_66 )
{
V_40 ( V_66 -> V_74 ) ;
}
static void * F_56 ( struct V_65 * V_66 , unsigned long V_80 )
{
struct V_1 * V_2 = V_66 -> V_74 ;
return V_2 -> V_25 ? V_2 -> V_25 + V_80 * V_10 : NULL ;
}
static void * F_57 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_74 ;
return F_33 ( V_2 ) ;
}
static int F_58 ( struct V_65 * V_66 ,
struct V_54 * V_55 )
{
return F_39 ( V_66 -> V_74 , V_55 ) ;
}
static struct V_65 * F_59 ( void * V_43 , unsigned long V_81 )
{
struct V_1 * V_2 = V_43 ;
struct V_65 * V_66 ;
F_60 ( V_82 ) ;
V_82 . V_83 = & V_84 ;
V_82 . V_5 = V_2 -> V_5 ;
V_82 . V_81 = V_81 ;
V_82 . V_74 = V_2 ;
if ( F_7 ( ! V_2 -> V_28 ) )
return NULL ;
V_66 = F_61 ( & V_82 ) ;
if ( F_27 ( V_66 ) )
return NULL ;
F_13 ( & V_2 -> V_38 ) ;
return V_66 ;
}
static int F_62 ( void * V_85 )
{
struct V_1 * V_2 = V_85 ;
struct V_20 * V_21 ;
if ( F_7 ( ! V_2 -> V_44 ) ) {
F_53 ( L_7 ) ;
return - V_24 ;
}
if ( F_7 ( V_2 -> V_28 ) ) {
F_53 ( L_8 ) ;
return 0 ;
}
V_21 = F_63 ( V_2 -> V_44 , V_2 -> V_19 ) ;
if ( F_27 ( V_21 ) ) {
F_53 ( L_9 ) ;
return - V_24 ;
}
V_2 -> V_28 = V_21 ;
V_2 -> V_25 = NULL ;
return 0 ;
}
static void F_64 ( void * V_85 )
{
struct V_1 * V_2 = V_85 ;
struct V_20 * V_21 = V_2 -> V_28 ;
if ( F_7 ( ! V_2 -> V_44 ) ) {
F_53 ( L_10 ) ;
return;
}
if ( F_7 ( ! V_21 ) ) {
F_53 ( L_11 ) ;
return;
}
if ( V_2 -> V_25 ) {
F_65 ( V_2 -> V_44 -> V_52 , V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
}
F_66 ( V_2 -> V_44 , V_21 , V_2 -> V_19 ) ;
V_2 -> V_28 = NULL ;
}
static void F_67 ( void * V_85 )
{
struct V_1 * V_2 = V_85 ;
if ( F_7 ( V_2 -> V_28 ) )
F_64 ( V_2 ) ;
F_68 ( V_2 -> V_44 -> V_52 , V_2 -> V_44 ) ;
F_17 ( V_2 ) ;
}
static void * F_69 ( struct V_15 * V_16 , struct V_65 * V_66 ,
unsigned long V_5 , enum V_18 V_19 )
{
struct V_1 * V_2 ;
struct V_67 * V_86 ;
if ( F_7 ( ! V_16 ) )
return F_8 ( - V_24 ) ;
if ( V_66 -> V_5 < V_5 )
return F_8 ( - V_87 ) ;
V_2 = F_9 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return F_8 ( - V_14 ) ;
V_2 -> V_16 = V_16 ;
V_86 = F_70 ( V_66 , V_2 -> V_16 ) ;
if ( F_27 ( V_86 ) ) {
F_53 ( L_12 ) ;
F_17 ( V_2 ) ;
return V_86 ;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_44 = V_86 ;
return V_2 ;
}
static void * F_71 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
return V_2 -> V_28 ;
}

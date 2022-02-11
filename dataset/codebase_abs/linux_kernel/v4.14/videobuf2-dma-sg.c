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
V_2 -> V_7 = F_10 ( V_2 -> V_23 , sizeof( struct V_6 * ) ,
V_11 | V_12 ) ;
if ( ! V_2 -> V_7 )
goto V_29;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_22 )
goto V_30;
V_22 = F_11 ( V_2 -> V_28 , V_2 -> V_7 ,
V_2 -> V_23 , 0 , V_5 , V_11 ) ;
if ( V_22 )
goto V_31;
V_2 -> V_16 = F_12 ( V_16 ) ;
V_21 = & V_2 -> V_20 ;
V_21 -> V_32 = F_13 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_2 -> V_19 , V_35 ) ;
if ( ! V_21 -> V_32 )
goto V_36;
V_2 -> V_37 . V_38 = & V_2 -> V_38 ;
V_2 -> V_37 . V_39 = V_40 ;
V_2 -> V_37 . V_41 = V_2 ;
F_14 ( & V_2 -> V_38 , 1 ) ;
F_15 ( 1 , L_1 ,
V_42 , V_2 -> V_23 ) ;
return V_2 ;
V_36:
F_16 ( V_2 -> V_16 ) ;
F_17 ( V_2 -> V_28 ) ;
V_31:
V_23 = V_2 -> V_23 ;
while ( V_23 -- )
F_4 ( V_2 -> V_7 [ V_23 ] ) ;
V_30:
F_18 ( V_2 -> V_7 ) ;
V_29:
F_19 ( V_2 ) ;
return F_8 ( - V_14 ) ;
}
static void V_40 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
if ( F_20 ( & V_2 -> V_38 ) ) {
F_15 ( 1 , L_2 , V_42 ,
V_2 -> V_23 ) ;
F_21 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_2 -> V_19 , V_35 ) ;
if ( V_2 -> V_25 )
F_22 ( V_2 -> V_25 , V_2 -> V_23 ) ;
F_17 ( V_2 -> V_28 ) ;
while ( -- V_9 >= 0 )
F_4 ( V_2 -> V_7 [ V_9 ] ) ;
F_18 ( V_2 -> V_7 ) ;
F_16 ( V_2 -> V_16 ) ;
F_19 ( V_2 ) ;
}
}
static void F_23 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = V_2 -> V_28 ;
if ( V_2 -> V_44 )
return;
F_24 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_2 -> V_19 ) ;
}
static void F_25 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = V_2 -> V_28 ;
if ( V_2 -> V_44 )
return;
F_26 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 , V_2 -> V_19 ) ;
}
static void * F_27 ( struct V_15 * V_16 , unsigned long V_25 ,
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
V_46 = F_28 ( V_25 , V_5 , V_19 == V_48 ||
V_19 == V_49 ) ;
if ( F_29 ( V_46 ) )
goto V_50;
V_2 -> V_46 = V_46 ;
V_2 -> V_7 = F_30 ( V_46 ) ;
if ( F_29 ( V_2 -> V_7 ) )
goto V_51;
V_2 -> V_23 = F_31 ( V_46 ) ;
if ( F_11 ( V_2 -> V_28 , V_2 -> V_7 ,
V_2 -> V_23 , V_2 -> V_26 , V_5 , 0 ) )
goto V_51;
V_21 = & V_2 -> V_20 ;
V_21 -> V_32 = F_13 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_2 -> V_19 , V_35 ) ;
if ( ! V_21 -> V_32 )
goto V_52;
return V_2 ;
V_52:
F_17 ( & V_2 -> V_20 ) ;
V_51:
F_32 ( V_46 ) ;
V_50:
F_19 ( V_2 ) ;
return F_8 ( - V_14 ) ;
}
static void F_33 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
F_15 ( 1 , L_3 ,
V_42 , V_2 -> V_23 ) ;
F_21 ( V_2 -> V_16 , V_21 -> V_33 , V_21 -> V_34 , V_2 -> V_19 ,
V_35 ) ;
if ( V_2 -> V_25 )
F_22 ( V_2 -> V_25 , V_2 -> V_23 ) ;
F_17 ( V_2 -> V_28 ) ;
while ( -- V_9 >= 0 ) {
if ( V_2 -> V_19 == V_48 ||
V_2 -> V_19 == V_49 )
F_34 ( V_2 -> V_7 [ V_9 ] ) ;
}
F_32 ( V_2 -> V_46 ) ;
F_19 ( V_2 ) ;
}
static void * F_35 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
F_36 ( ! V_2 ) ;
if ( ! V_2 -> V_25 ) {
if ( V_2 -> V_44 )
V_2 -> V_25 = F_37 ( V_2 -> V_44 -> V_53 ) ;
else
V_2 -> V_25 = F_38 ( V_2 -> V_7 ,
V_2 -> V_23 , - 1 , V_54 ) ;
}
return V_2 -> V_25 ? V_2 -> V_25 + V_2 -> V_26 : NULL ;
}
static unsigned int F_39 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
return F_40 ( & V_2 -> V_38 ) ;
}
static int F_41 ( void * V_43 , struct V_55 * V_56 )
{
struct V_1 * V_2 = V_43 ;
unsigned long V_57 = V_56 -> V_58 ;
unsigned long V_59 = V_56 -> V_60 - V_56 -> V_58 ;
int V_9 = 0 ;
if ( ! V_2 ) {
F_42 ( V_61 L_4 ) ;
return - V_24 ;
}
do {
int V_22 ;
V_22 = F_43 ( V_56 , V_57 , V_2 -> V_7 [ V_9 ++ ] ) ;
if ( V_22 ) {
F_42 ( V_61 L_5 , V_22 ) ;
return V_22 ;
}
V_57 += V_10 ;
V_59 -= V_10 ;
} while ( V_59 > 0 );
V_56 -> V_62 = & V_2 -> V_37 ;
V_56 -> V_63 = & V_64 ;
V_56 -> V_63 -> V_65 ( V_56 ) ;
return 0 ;
}
static int F_44 ( struct V_66 * V_67 , struct V_15 * V_16 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 ;
unsigned int V_9 ;
struct V_72 * V_73 , * V_74 ;
struct V_20 * V_21 ;
struct V_1 * V_2 = V_67 -> V_75 ;
int V_22 ;
V_71 = F_9 ( sizeof( * V_71 ) , V_11 ) ;
if ( ! V_71 )
return - V_14 ;
V_21 = & V_71 -> V_21 ;
V_22 = F_45 ( V_21 , V_2 -> V_28 -> V_34 , V_11 ) ;
if ( V_22 ) {
F_19 ( V_71 ) ;
return - V_14 ;
}
V_73 = V_2 -> V_28 -> V_33 ;
V_74 = V_21 -> V_33 ;
for ( V_9 = 0 ; V_9 < V_21 -> V_34 ; ++ V_9 ) {
F_46 ( V_74 , F_47 ( V_73 ) , V_73 -> V_76 , V_73 -> V_26 ) ;
V_73 = F_48 ( V_73 ) ;
V_74 = F_48 ( V_74 ) ;
}
V_71 -> V_19 = V_77 ;
V_69 -> V_75 = V_71 ;
return 0 ;
}
static void F_49 ( struct V_66 * V_67 ,
struct V_68 * V_44 )
{
struct V_70 * V_71 = V_44 -> V_75 ;
struct V_20 * V_21 ;
if ( ! V_71 )
return;
V_21 = & V_71 -> V_21 ;
if ( V_71 -> V_19 != V_77 )
F_50 ( V_44 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_71 -> V_19 ) ;
F_17 ( V_21 ) ;
F_19 ( V_71 ) ;
V_44 -> V_75 = NULL ;
}
static struct V_20 * F_51 (
struct V_68 * V_44 , enum V_18 V_19 )
{
struct V_70 * V_71 = V_44 -> V_75 ;
struct V_78 * V_79 = & V_44 -> V_53 -> V_79 ;
struct V_20 * V_21 ;
F_52 ( V_79 ) ;
V_21 = & V_71 -> V_21 ;
if ( V_71 -> V_19 == V_19 ) {
F_53 ( V_79 ) ;
return V_21 ;
}
if ( V_71 -> V_19 != V_77 ) {
F_50 ( V_44 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_71 -> V_19 ) ;
V_71 -> V_19 = V_77 ;
}
V_21 -> V_32 = F_54 ( V_44 -> V_16 , V_21 -> V_33 , V_21 -> V_34 ,
V_19 ) ;
if ( ! V_21 -> V_32 ) {
F_55 ( L_6 ) ;
F_53 ( V_79 ) ;
return F_8 ( - V_80 ) ;
}
V_71 -> V_19 = V_19 ;
F_53 ( V_79 ) ;
return V_21 ;
}
static void F_56 ( struct V_68 * V_44 ,
struct V_20 * V_21 , enum V_18 V_19 )
{
}
static void F_57 ( struct V_66 * V_67 )
{
V_40 ( V_67 -> V_75 ) ;
}
static void * F_58 ( struct V_66 * V_67 , unsigned long V_81 )
{
struct V_1 * V_2 = V_67 -> V_75 ;
return V_2 -> V_25 ? V_2 -> V_25 + V_81 * V_10 : NULL ;
}
static void * F_59 ( struct V_66 * V_67 )
{
struct V_1 * V_2 = V_67 -> V_75 ;
return F_35 ( V_2 ) ;
}
static int F_60 ( struct V_66 * V_67 ,
struct V_55 * V_56 )
{
return F_41 ( V_67 -> V_75 , V_56 ) ;
}
static struct V_66 * F_61 ( void * V_43 , unsigned long V_82 )
{
struct V_1 * V_2 = V_43 ;
struct V_66 * V_67 ;
F_62 ( V_83 ) ;
V_83 . V_84 = & V_85 ;
V_83 . V_5 = V_2 -> V_5 ;
V_83 . V_82 = V_82 ;
V_83 . V_75 = V_2 ;
if ( F_7 ( ! V_2 -> V_28 ) )
return NULL ;
V_67 = F_63 ( & V_83 ) ;
if ( F_29 ( V_67 ) )
return NULL ;
F_64 ( & V_2 -> V_38 ) ;
return V_67 ;
}
static int F_65 ( void * V_86 )
{
struct V_1 * V_2 = V_86 ;
struct V_20 * V_21 ;
if ( F_7 ( ! V_2 -> V_44 ) ) {
F_55 ( L_7 ) ;
return - V_24 ;
}
if ( F_7 ( V_2 -> V_28 ) ) {
F_55 ( L_8 ) ;
return 0 ;
}
V_21 = F_66 ( V_2 -> V_44 , V_2 -> V_19 ) ;
if ( F_29 ( V_21 ) ) {
F_55 ( L_9 ) ;
return - V_24 ;
}
V_2 -> V_28 = V_21 ;
V_2 -> V_25 = NULL ;
return 0 ;
}
static void F_67 ( void * V_86 )
{
struct V_1 * V_2 = V_86 ;
struct V_20 * V_21 = V_2 -> V_28 ;
if ( F_7 ( ! V_2 -> V_44 ) ) {
F_55 ( L_10 ) ;
return;
}
if ( F_7 ( ! V_21 ) ) {
F_55 ( L_11 ) ;
return;
}
if ( V_2 -> V_25 ) {
F_68 ( V_2 -> V_44 -> V_53 , V_2 -> V_25 ) ;
V_2 -> V_25 = NULL ;
}
F_69 ( V_2 -> V_44 , V_21 , V_2 -> V_19 ) ;
V_2 -> V_28 = NULL ;
}
static void F_70 ( void * V_86 )
{
struct V_1 * V_2 = V_86 ;
if ( F_7 ( V_2 -> V_28 ) )
F_67 ( V_2 ) ;
F_71 ( V_2 -> V_44 -> V_53 , V_2 -> V_44 ) ;
F_19 ( V_2 ) ;
}
static void * F_72 ( struct V_15 * V_16 , struct V_66 * V_67 ,
unsigned long V_5 , enum V_18 V_19 )
{
struct V_1 * V_2 ;
struct V_68 * V_87 ;
if ( F_7 ( ! V_16 ) )
return F_8 ( - V_24 ) ;
if ( V_67 -> V_5 < V_5 )
return F_8 ( - V_88 ) ;
V_2 = F_9 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return F_8 ( - V_14 ) ;
V_2 -> V_16 = V_16 ;
V_87 = F_73 ( V_67 , V_2 -> V_16 ) ;
if ( F_29 ( V_87 ) ) {
F_55 ( L_12 ) ;
F_19 ( V_2 ) ;
return V_87 ;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_44 = V_87 ;
return V_2 ;
}
static void * F_74 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
return V_2 -> V_28 ;
}

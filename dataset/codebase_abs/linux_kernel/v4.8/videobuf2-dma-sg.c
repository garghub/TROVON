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
if ( F_7 ( V_16 == NULL ) )
return NULL ;
V_2 = F_8 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_24 = NULL ;
V_2 -> V_19 = V_19 ;
V_2 -> V_25 = 0 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_23 = V_5 >> V_26 ;
V_2 -> V_27 = & V_2 -> V_20 ;
V_2 -> V_7 = F_8 ( V_2 -> V_23 * sizeof( struct V_6 * ) ,
V_11 ) ;
if ( ! V_2 -> V_7 )
goto V_28;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_22 )
goto V_29;
V_22 = F_9 ( V_2 -> V_27 , V_2 -> V_7 ,
V_2 -> V_23 , 0 , V_5 , V_11 ) ;
if ( V_22 )
goto V_30;
V_2 -> V_16 = F_10 ( V_16 ) ;
V_21 = & V_2 -> V_20 ;
V_21 -> V_31 = F_11 ( V_2 -> V_16 , V_21 -> V_32 , V_21 -> V_33 ,
V_2 -> V_19 , V_34 ) ;
if ( ! V_21 -> V_31 )
goto V_35;
V_2 -> V_36 . V_37 = & V_2 -> V_37 ;
V_2 -> V_36 . V_38 = V_39 ;
V_2 -> V_36 . V_40 = V_2 ;
F_12 ( & V_2 -> V_37 ) ;
F_13 ( 1 , L_1 ,
V_41 , V_2 -> V_23 ) ;
return V_2 ;
V_35:
F_14 ( V_2 -> V_16 ) ;
F_15 ( V_2 -> V_27 ) ;
V_30:
V_23 = V_2 -> V_23 ;
while ( V_23 -- )
F_4 ( V_2 -> V_7 [ V_23 ] ) ;
V_29:
F_16 ( V_2 -> V_7 ) ;
V_28:
F_16 ( V_2 ) ;
return NULL ;
}
static void V_39 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
if ( F_17 ( & V_2 -> V_37 ) ) {
F_13 ( 1 , L_2 , V_41 ,
V_2 -> V_23 ) ;
F_18 ( V_2 -> V_16 , V_21 -> V_32 , V_21 -> V_33 ,
V_2 -> V_19 , V_34 ) ;
if ( V_2 -> V_24 )
F_19 ( V_2 -> V_24 , V_2 -> V_23 ) ;
F_15 ( V_2 -> V_27 ) ;
while ( -- V_9 >= 0 )
F_4 ( V_2 -> V_7 [ V_9 ] ) ;
F_16 ( V_2 -> V_7 ) ;
F_14 ( V_2 -> V_16 ) ;
F_16 ( V_2 ) ;
}
}
static void F_20 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_20 * V_21 = V_2 -> V_27 ;
if ( V_2 -> V_43 )
return;
F_21 ( V_2 -> V_16 , V_21 -> V_32 , V_21 -> V_33 ,
V_2 -> V_19 ) ;
}
static void F_22 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_20 * V_21 = V_2 -> V_27 ;
if ( V_2 -> V_43 )
return;
F_23 ( V_2 -> V_16 , V_21 -> V_32 , V_21 -> V_33 , V_2 -> V_19 ) ;
}
static void * F_24 ( struct V_15 * V_16 , unsigned long V_24 ,
unsigned long V_5 ,
enum V_18 V_19 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
struct V_44 * V_45 ;
V_2 = F_8 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_24 = NULL ;
V_2 -> V_16 = V_16 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_25 = V_24 & ~ V_46 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_27 = & V_2 -> V_20 ;
V_45 = F_25 ( V_24 , V_5 , V_2 -> V_19 == V_47 ) ;
if ( F_26 ( V_45 ) )
goto V_48;
V_2 -> V_45 = V_45 ;
V_2 -> V_7 = F_27 ( V_45 ) ;
if ( F_26 ( V_2 -> V_7 ) )
goto V_49;
V_2 -> V_23 = F_28 ( V_45 ) ;
if ( F_9 ( V_2 -> V_27 , V_2 -> V_7 ,
V_2 -> V_23 , V_2 -> V_25 , V_5 , 0 ) )
goto V_49;
V_21 = & V_2 -> V_20 ;
V_21 -> V_31 = F_11 ( V_2 -> V_16 , V_21 -> V_32 , V_21 -> V_33 ,
V_2 -> V_19 , V_34 ) ;
if ( ! V_21 -> V_31 )
goto V_50;
return V_2 ;
V_50:
F_15 ( & V_2 -> V_20 ) ;
V_49:
F_29 ( V_45 ) ;
V_48:
F_16 ( V_2 ) ;
return NULL ;
}
static void F_30 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
F_13 ( 1 , L_3 ,
V_41 , V_2 -> V_23 ) ;
F_18 ( V_2 -> V_16 , V_21 -> V_32 , V_21 -> V_33 , V_2 -> V_19 ,
V_34 ) ;
if ( V_2 -> V_24 )
F_19 ( V_2 -> V_24 , V_2 -> V_23 ) ;
F_15 ( V_2 -> V_27 ) ;
while ( -- V_9 >= 0 ) {
if ( V_2 -> V_19 == V_47 )
F_31 ( V_2 -> V_7 [ V_9 ] ) ;
}
F_29 ( V_2 -> V_45 ) ;
F_16 ( V_2 ) ;
}
static void * F_32 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
F_33 ( ! V_2 ) ;
if ( ! V_2 -> V_24 ) {
if ( V_2 -> V_43 )
V_2 -> V_24 = F_34 ( V_2 -> V_43 -> V_51 ) ;
else
V_2 -> V_24 = F_35 ( V_2 -> V_7 ,
V_2 -> V_23 , - 1 , V_52 ) ;
}
return V_2 -> V_24 ? V_2 -> V_24 + V_2 -> V_25 : NULL ;
}
static unsigned int F_36 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
return F_37 ( & V_2 -> V_37 ) ;
}
static int F_38 ( void * V_42 , struct V_53 * V_54 )
{
struct V_1 * V_2 = V_42 ;
unsigned long V_55 = V_54 -> V_56 ;
unsigned long V_57 = V_54 -> V_58 - V_54 -> V_56 ;
int V_9 = 0 ;
if ( ! V_2 ) {
F_39 ( V_59 L_4 ) ;
return - V_60 ;
}
do {
int V_22 ;
V_22 = F_40 ( V_54 , V_55 , V_2 -> V_7 [ V_9 ++ ] ) ;
if ( V_22 ) {
F_39 ( V_59 L_5 , V_22 ) ;
return V_22 ;
}
V_55 += V_10 ;
V_57 -= V_10 ;
} while ( V_57 > 0 );
V_54 -> V_61 = & V_2 -> V_36 ;
V_54 -> V_62 = & V_63 ;
V_54 -> V_62 -> V_64 ( V_54 ) ;
return 0 ;
}
static int F_41 ( struct V_65 * V_66 , struct V_15 * V_16 ,
struct V_67 * V_68 )
{
struct V_69 * V_70 ;
unsigned int V_9 ;
struct V_71 * V_72 , * V_73 ;
struct V_20 * V_21 ;
struct V_1 * V_2 = V_66 -> V_74 ;
int V_22 ;
V_70 = F_8 ( sizeof( * V_70 ) , V_11 ) ;
if ( ! V_70 )
return - V_14 ;
V_21 = & V_70 -> V_21 ;
V_22 = F_42 ( V_21 , V_2 -> V_27 -> V_33 , V_11 ) ;
if ( V_22 ) {
F_16 ( V_70 ) ;
return - V_14 ;
}
V_72 = V_2 -> V_27 -> V_32 ;
V_73 = V_21 -> V_32 ;
for ( V_9 = 0 ; V_9 < V_21 -> V_33 ; ++ V_9 ) {
F_43 ( V_73 , F_44 ( V_72 ) , V_72 -> V_75 , V_72 -> V_25 ) ;
V_72 = F_45 ( V_72 ) ;
V_73 = F_45 ( V_73 ) ;
}
V_70 -> V_19 = V_76 ;
V_68 -> V_74 = V_70 ;
return 0 ;
}
static void F_46 ( struct V_65 * V_66 ,
struct V_67 * V_43 )
{
struct V_69 * V_70 = V_43 -> V_74 ;
struct V_20 * V_21 ;
if ( ! V_70 )
return;
V_21 = & V_70 -> V_21 ;
if ( V_70 -> V_19 != V_76 )
F_47 ( V_43 -> V_16 , V_21 -> V_32 , V_21 -> V_33 ,
V_70 -> V_19 ) ;
F_15 ( V_21 ) ;
F_16 ( V_70 ) ;
V_43 -> V_74 = NULL ;
}
static struct V_20 * F_48 (
struct V_67 * V_43 , enum V_18 V_19 )
{
struct V_69 * V_70 = V_43 -> V_74 ;
struct V_77 * V_78 = & V_43 -> V_51 -> V_78 ;
struct V_20 * V_21 ;
F_49 ( V_78 ) ;
V_21 = & V_70 -> V_21 ;
if ( V_70 -> V_19 == V_19 ) {
F_50 ( V_78 ) ;
return V_21 ;
}
if ( V_70 -> V_19 != V_76 ) {
F_47 ( V_43 -> V_16 , V_21 -> V_32 , V_21 -> V_33 ,
V_70 -> V_19 ) ;
V_70 -> V_19 = V_76 ;
}
V_21 -> V_31 = F_51 ( V_43 -> V_16 , V_21 -> V_32 , V_21 -> V_33 ,
V_19 ) ;
if ( ! V_21 -> V_31 ) {
F_52 ( L_6 ) ;
F_50 ( V_78 ) ;
return F_53 ( - V_79 ) ;
}
V_70 -> V_19 = V_19 ;
F_50 ( V_78 ) ;
return V_21 ;
}
static void F_54 ( struct V_67 * V_43 ,
struct V_20 * V_21 , enum V_18 V_19 )
{
}
static void F_55 ( struct V_65 * V_66 )
{
V_39 ( V_66 -> V_74 ) ;
}
static void * F_56 ( struct V_65 * V_66 , unsigned long V_80 )
{
struct V_1 * V_2 = V_66 -> V_74 ;
return V_2 -> V_24 ? V_2 -> V_24 + V_80 * V_10 : NULL ;
}
static void * F_57 ( struct V_65 * V_66 )
{
struct V_1 * V_2 = V_66 -> V_74 ;
return F_32 ( V_2 ) ;
}
static int F_58 ( struct V_65 * V_66 ,
struct V_53 * V_54 )
{
return F_38 ( V_66 -> V_74 , V_54 ) ;
}
static struct V_65 * F_59 ( void * V_42 , unsigned long V_81 )
{
struct V_1 * V_2 = V_42 ;
struct V_65 * V_66 ;
F_60 ( V_82 ) ;
V_82 . V_83 = & V_84 ;
V_82 . V_5 = V_2 -> V_5 ;
V_82 . V_81 = V_81 ;
V_82 . V_74 = V_2 ;
if ( F_7 ( ! V_2 -> V_27 ) )
return NULL ;
V_66 = F_61 ( & V_82 ) ;
if ( F_26 ( V_66 ) )
return NULL ;
F_12 ( & V_2 -> V_37 ) ;
return V_66 ;
}
static int F_62 ( void * V_85 )
{
struct V_1 * V_2 = V_85 ;
struct V_20 * V_21 ;
if ( F_7 ( ! V_2 -> V_43 ) ) {
F_52 ( L_7 ) ;
return - V_60 ;
}
if ( F_7 ( V_2 -> V_27 ) ) {
F_52 ( L_8 ) ;
return 0 ;
}
V_21 = F_63 ( V_2 -> V_43 , V_2 -> V_19 ) ;
if ( F_26 ( V_21 ) ) {
F_52 ( L_9 ) ;
return - V_60 ;
}
V_2 -> V_27 = V_21 ;
V_2 -> V_24 = NULL ;
return 0 ;
}
static void F_64 ( void * V_85 )
{
struct V_1 * V_2 = V_85 ;
struct V_20 * V_21 = V_2 -> V_27 ;
if ( F_7 ( ! V_2 -> V_43 ) ) {
F_52 ( L_10 ) ;
return;
}
if ( F_7 ( ! V_21 ) ) {
F_52 ( L_11 ) ;
return;
}
if ( V_2 -> V_24 ) {
F_65 ( V_2 -> V_43 -> V_51 , V_2 -> V_24 ) ;
V_2 -> V_24 = NULL ;
}
F_66 ( V_2 -> V_43 , V_21 , V_2 -> V_19 ) ;
V_2 -> V_27 = NULL ;
}
static void F_67 ( void * V_85 )
{
struct V_1 * V_2 = V_85 ;
if ( F_7 ( V_2 -> V_27 ) )
F_64 ( V_2 ) ;
F_68 ( V_2 -> V_43 -> V_51 , V_2 -> V_43 ) ;
F_16 ( V_2 ) ;
}
static void * F_69 ( struct V_15 * V_16 , struct V_65 * V_66 ,
unsigned long V_5 , enum V_18 V_19 )
{
struct V_1 * V_2 ;
struct V_67 * V_86 ;
if ( V_66 -> V_5 < V_5 )
return F_53 ( - V_87 ) ;
V_2 = F_8 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return F_53 ( - V_14 ) ;
V_2 -> V_16 = V_16 ;
V_86 = F_70 ( V_66 , V_2 -> V_16 ) ;
if ( F_26 ( V_86 ) ) {
F_52 ( L_12 ) ;
F_16 ( V_2 ) ;
return V_86 ;
}
V_2 -> V_19 = V_19 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_43 = V_86 ;
return V_2 ;
}
static void * F_71 ( void * V_42 )
{
struct V_1 * V_2 = V_42 ;
return V_2 -> V_27 ;
}

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
static void * F_6 ( void * V_15 , unsigned long V_5 ,
enum V_16 V_17 , T_1 V_3 )
{
struct V_18 * V_19 = V_15 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
int V_22 ;
int V_23 ;
F_7 ( V_24 ) ;
F_8 ( V_25 , & V_24 ) ;
if ( F_9 ( V_15 == NULL ) )
return NULL ;
V_2 = F_10 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_26 = NULL ;
V_2 -> V_17 = V_17 ;
V_2 -> V_27 = 0 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_23 = V_5 >> V_28 ;
V_2 -> V_29 = & V_2 -> V_20 ;
V_2 -> V_7 = F_10 ( V_2 -> V_23 * sizeof( struct V_6 * ) ,
V_11 ) ;
if ( ! V_2 -> V_7 )
goto V_30;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_22 )
goto V_31;
V_22 = F_11 ( V_2 -> V_29 , V_2 -> V_7 ,
V_2 -> V_23 , 0 , V_5 , V_11 ) ;
if ( V_22 )
goto V_32;
V_2 -> V_33 = F_12 ( V_19 -> V_33 ) ;
V_21 = & V_2 -> V_20 ;
V_21 -> V_34 = F_13 ( V_2 -> V_33 , V_21 -> V_35 , V_21 -> V_36 ,
V_2 -> V_17 , & V_24 ) ;
if ( ! V_21 -> V_34 )
goto V_37;
V_2 -> V_38 . V_39 = & V_2 -> V_39 ;
V_2 -> V_38 . V_40 = V_41 ;
V_2 -> V_38 . V_42 = V_2 ;
F_14 ( & V_2 -> V_39 ) ;
F_15 ( 1 , L_1 ,
V_43 , V_2 -> V_23 ) ;
return V_2 ;
V_37:
F_16 ( V_2 -> V_33 ) ;
F_17 ( V_2 -> V_29 ) ;
V_32:
V_23 = V_2 -> V_23 ;
while ( V_23 -- )
F_4 ( V_2 -> V_7 [ V_23 ] ) ;
V_31:
F_18 ( V_2 -> V_7 ) ;
V_30:
F_18 ( V_2 ) ;
return NULL ;
}
static void V_41 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
if ( F_19 ( & V_2 -> V_39 ) ) {
F_7 ( V_24 ) ;
F_8 ( V_25 , & V_24 ) ;
F_15 ( 1 , L_2 , V_43 ,
V_2 -> V_23 ) ;
F_20 ( V_2 -> V_33 , V_21 -> V_35 , V_21 -> V_36 ,
V_2 -> V_17 , & V_24 ) ;
if ( V_2 -> V_26 )
F_21 ( V_2 -> V_26 , V_2 -> V_23 ) ;
F_17 ( V_2 -> V_29 ) ;
while ( -- V_9 >= 0 )
F_4 ( V_2 -> V_7 [ V_9 ] ) ;
F_18 ( V_2 -> V_7 ) ;
F_16 ( V_2 -> V_33 ) ;
F_18 ( V_2 ) ;
}
}
static void F_22 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
struct V_20 * V_21 = V_2 -> V_29 ;
if ( V_2 -> V_45 )
return;
F_23 ( V_2 -> V_33 , V_21 -> V_35 , V_21 -> V_34 , V_2 -> V_17 ) ;
}
static void F_24 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
struct V_20 * V_21 = V_2 -> V_29 ;
if ( V_2 -> V_45 )
return;
F_25 ( V_2 -> V_33 , V_21 -> V_35 , V_21 -> V_34 , V_2 -> V_17 ) ;
}
static void * F_26 ( void * V_15 , unsigned long V_26 ,
unsigned long V_5 ,
enum V_16 V_17 )
{
struct V_18 * V_19 = V_15 ;
struct V_1 * V_2 ;
struct V_20 * V_21 ;
F_7 ( V_24 ) ;
struct V_46 * V_47 ;
F_8 ( V_25 , & V_24 ) ;
V_2 = F_10 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_26 = NULL ;
V_2 -> V_33 = V_19 -> V_33 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_27 = V_26 & ~ V_48 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_29 = & V_2 -> V_20 ;
V_47 = F_27 ( V_26 , V_5 , V_2 -> V_17 == V_49 ) ;
if ( F_28 ( V_47 ) )
goto V_50;
V_2 -> V_47 = V_47 ;
V_2 -> V_7 = F_29 ( V_47 ) ;
if ( F_28 ( V_2 -> V_7 ) )
goto V_51;
V_2 -> V_23 = F_30 ( V_47 ) ;
if ( F_11 ( V_2 -> V_29 , V_2 -> V_7 ,
V_2 -> V_23 , V_2 -> V_27 , V_5 , 0 ) )
goto V_51;
V_21 = & V_2 -> V_20 ;
V_21 -> V_34 = F_13 ( V_2 -> V_33 , V_21 -> V_35 , V_21 -> V_36 ,
V_2 -> V_17 , & V_24 ) ;
if ( ! V_21 -> V_34 )
goto V_52;
return V_2 ;
V_52:
F_17 ( & V_2 -> V_20 ) ;
V_51:
F_31 ( V_47 ) ;
V_50:
F_18 ( V_2 ) ;
return NULL ;
}
static void F_32 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
F_7 ( V_24 ) ;
F_8 ( V_25 , & V_24 ) ;
F_15 ( 1 , L_3 ,
V_43 , V_2 -> V_23 ) ;
F_20 ( V_2 -> V_33 , V_21 -> V_35 , V_21 -> V_36 , V_2 -> V_17 ,
& V_24 ) ;
if ( V_2 -> V_26 )
F_21 ( V_2 -> V_26 , V_2 -> V_23 ) ;
F_17 ( V_2 -> V_29 ) ;
while ( -- V_9 >= 0 ) {
if ( V_2 -> V_17 == V_49 )
F_33 ( V_2 -> V_7 [ V_9 ] ) ;
}
F_31 ( V_2 -> V_47 ) ;
F_18 ( V_2 ) ;
}
static void * F_34 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
F_35 ( ! V_2 ) ;
if ( ! V_2 -> V_26 ) {
if ( V_2 -> V_45 )
V_2 -> V_26 = F_36 ( V_2 -> V_45 -> V_53 ) ;
else
V_2 -> V_26 = F_37 ( V_2 -> V_7 ,
V_2 -> V_23 , - 1 , V_54 ) ;
}
return V_2 -> V_26 ? V_2 -> V_26 + V_2 -> V_27 : NULL ;
}
static unsigned int F_38 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
return F_39 ( & V_2 -> V_39 ) ;
}
static int F_40 ( void * V_44 , struct V_55 * V_56 )
{
struct V_1 * V_2 = V_44 ;
unsigned long V_57 = V_56 -> V_58 ;
unsigned long V_59 = V_56 -> V_60 - V_56 -> V_58 ;
int V_9 = 0 ;
if ( ! V_2 ) {
F_41 ( V_61 L_4 ) ;
return - V_62 ;
}
do {
int V_22 ;
V_22 = F_42 ( V_56 , V_57 , V_2 -> V_7 [ V_9 ++ ] ) ;
if ( V_22 ) {
F_41 ( V_61 L_5 , V_22 ) ;
return V_22 ;
}
V_57 += V_10 ;
V_59 -= V_10 ;
} while ( V_59 > 0 );
V_56 -> V_63 = & V_2 -> V_38 ;
V_56 -> V_64 = & V_65 ;
V_56 -> V_64 -> V_66 ( V_56 ) ;
return 0 ;
}
static int F_43 ( struct V_67 * V_68 , struct V_69 * V_33 ,
struct V_70 * V_71 )
{
struct V_72 * V_73 ;
unsigned int V_9 ;
struct V_74 * V_75 , * V_76 ;
struct V_20 * V_21 ;
struct V_1 * V_2 = V_68 -> V_77 ;
int V_22 ;
V_73 = F_10 ( sizeof( * V_73 ) , V_11 ) ;
if ( ! V_73 )
return - V_14 ;
V_21 = & V_73 -> V_21 ;
V_22 = F_44 ( V_21 , V_2 -> V_29 -> V_36 , V_11 ) ;
if ( V_22 ) {
F_18 ( V_73 ) ;
return - V_14 ;
}
V_75 = V_2 -> V_29 -> V_35 ;
V_76 = V_21 -> V_35 ;
for ( V_9 = 0 ; V_9 < V_21 -> V_36 ; ++ V_9 ) {
F_45 ( V_76 , F_46 ( V_75 ) , V_75 -> V_78 , V_75 -> V_27 ) ;
V_75 = F_47 ( V_75 ) ;
V_76 = F_47 ( V_76 ) ;
}
V_73 -> V_17 = V_79 ;
V_71 -> V_77 = V_73 ;
return 0 ;
}
static void F_48 ( struct V_67 * V_68 ,
struct V_70 * V_45 )
{
struct V_72 * V_73 = V_45 -> V_77 ;
struct V_20 * V_21 ;
if ( ! V_73 )
return;
V_21 = & V_73 -> V_21 ;
if ( V_73 -> V_17 != V_79 )
F_49 ( V_45 -> V_33 , V_21 -> V_35 , V_21 -> V_36 ,
V_73 -> V_17 ) ;
F_17 ( V_21 ) ;
F_18 ( V_73 ) ;
V_45 -> V_77 = NULL ;
}
static struct V_20 * F_50 (
struct V_70 * V_45 , enum V_16 V_17 )
{
struct V_72 * V_73 = V_45 -> V_77 ;
struct V_80 * V_81 = & V_45 -> V_53 -> V_81 ;
struct V_20 * V_21 ;
F_51 ( V_81 ) ;
V_21 = & V_73 -> V_21 ;
if ( V_73 -> V_17 == V_17 ) {
F_52 ( V_81 ) ;
return V_21 ;
}
if ( V_73 -> V_17 != V_79 ) {
F_49 ( V_45 -> V_33 , V_21 -> V_35 , V_21 -> V_36 ,
V_73 -> V_17 ) ;
V_73 -> V_17 = V_79 ;
}
V_21 -> V_34 = F_53 ( V_45 -> V_33 , V_21 -> V_35 , V_21 -> V_36 ,
V_17 ) ;
if ( ! V_21 -> V_34 ) {
F_54 ( L_6 ) ;
F_52 ( V_81 ) ;
return F_55 ( - V_82 ) ;
}
V_73 -> V_17 = V_17 ;
F_52 ( V_81 ) ;
return V_21 ;
}
static void F_56 ( struct V_70 * V_45 ,
struct V_20 * V_21 , enum V_16 V_17 )
{
}
static void F_57 ( struct V_67 * V_68 )
{
V_41 ( V_68 -> V_77 ) ;
}
static void * F_58 ( struct V_67 * V_68 , unsigned long V_83 )
{
struct V_1 * V_2 = V_68 -> V_77 ;
return V_2 -> V_26 ? V_2 -> V_26 + V_83 * V_10 : NULL ;
}
static void * F_59 ( struct V_67 * V_68 )
{
struct V_1 * V_2 = V_68 -> V_77 ;
return F_34 ( V_2 ) ;
}
static int F_60 ( struct V_67 * V_68 ,
struct V_55 * V_56 )
{
return F_40 ( V_68 -> V_77 , V_56 ) ;
}
static struct V_67 * F_61 ( void * V_44 , unsigned long V_84 )
{
struct V_1 * V_2 = V_44 ;
struct V_67 * V_68 ;
F_62 ( V_85 ) ;
V_85 . V_86 = & V_87 ;
V_85 . V_5 = V_2 -> V_5 ;
V_85 . V_84 = V_84 ;
V_85 . V_77 = V_2 ;
if ( F_9 ( ! V_2 -> V_29 ) )
return NULL ;
V_68 = F_63 ( & V_85 ) ;
if ( F_28 ( V_68 ) )
return NULL ;
F_14 ( & V_2 -> V_39 ) ;
return V_68 ;
}
static int F_64 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
struct V_20 * V_21 ;
if ( F_9 ( ! V_2 -> V_45 ) ) {
F_54 ( L_7 ) ;
return - V_62 ;
}
if ( F_9 ( V_2 -> V_29 ) ) {
F_54 ( L_8 ) ;
return 0 ;
}
V_21 = F_65 ( V_2 -> V_45 , V_2 -> V_17 ) ;
if ( F_28 ( V_21 ) ) {
F_54 ( L_9 ) ;
return - V_62 ;
}
V_2 -> V_29 = V_21 ;
V_2 -> V_26 = NULL ;
return 0 ;
}
static void F_66 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
struct V_20 * V_21 = V_2 -> V_29 ;
if ( F_9 ( ! V_2 -> V_45 ) ) {
F_54 ( L_10 ) ;
return;
}
if ( F_9 ( ! V_21 ) ) {
F_54 ( L_11 ) ;
return;
}
if ( V_2 -> V_26 ) {
F_67 ( V_2 -> V_45 -> V_53 , V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
F_68 ( V_2 -> V_45 , V_21 , V_2 -> V_17 ) ;
V_2 -> V_29 = NULL ;
}
static void F_69 ( void * V_88 )
{
struct V_1 * V_2 = V_88 ;
if ( F_9 ( V_2 -> V_29 ) )
F_66 ( V_2 ) ;
F_70 ( V_2 -> V_45 -> V_53 , V_2 -> V_45 ) ;
F_18 ( V_2 ) ;
}
static void * F_71 ( void * V_15 , struct V_67 * V_68 ,
unsigned long V_5 , enum V_16 V_17 )
{
struct V_18 * V_19 = V_15 ;
struct V_1 * V_2 ;
struct V_70 * V_89 ;
if ( V_68 -> V_5 < V_5 )
return F_55 ( - V_90 ) ;
V_2 = F_10 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return F_55 ( - V_14 ) ;
V_2 -> V_33 = V_19 -> V_33 ;
V_89 = F_72 ( V_68 , V_2 -> V_33 ) ;
if ( F_28 ( V_89 ) ) {
F_54 ( L_12 ) ;
F_18 ( V_2 ) ;
return V_89 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_45 = V_89 ;
return V_2 ;
}
static void * F_73 ( void * V_44 )
{
struct V_1 * V_2 = V_44 ;
return V_2 -> V_29 ;
}
void * F_74 ( struct V_69 * V_33 )
{
struct V_18 * V_19 ;
V_19 = F_10 ( sizeof( * V_19 ) , V_11 ) ;
if ( ! V_19 )
return F_55 ( - V_14 ) ;
V_19 -> V_33 = V_33 ;
return V_19 ;
}
void F_75 ( void * V_15 )
{
if ( ! F_76 ( V_15 ) )
F_18 ( V_15 ) ;
}

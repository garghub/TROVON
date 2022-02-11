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
if ( F_13 ( V_2 -> V_33 , V_21 -> V_34 , V_21 -> V_35 ,
V_2 -> V_17 , & V_24 ) == 0 )
goto V_36;
V_2 -> V_37 . V_38 = & V_2 -> V_38 ;
V_2 -> V_37 . V_39 = V_40 ;
V_2 -> V_37 . V_41 = V_2 ;
F_14 ( & V_2 -> V_38 ) ;
F_15 ( 1 , L_1 ,
V_42 , V_2 -> V_23 ) ;
return V_2 ;
V_36:
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
static void V_40 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
if ( F_19 ( & V_2 -> V_38 ) ) {
F_7 ( V_24 ) ;
F_8 ( V_25 , & V_24 ) ;
F_15 ( 1 , L_2 , V_42 ,
V_2 -> V_23 ) ;
F_20 ( V_2 -> V_33 , V_21 -> V_34 , V_21 -> V_35 ,
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
static void F_22 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = V_2 -> V_29 ;
if ( V_2 -> V_44 )
return;
F_23 ( V_2 -> V_33 , V_21 -> V_34 , V_21 -> V_35 , V_2 -> V_17 ) ;
}
static void F_24 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = V_2 -> V_29 ;
if ( V_2 -> V_44 )
return;
F_25 ( V_2 -> V_33 , V_21 -> V_34 , V_21 -> V_35 , V_2 -> V_17 ) ;
}
static inline int F_26 ( struct V_45 * V_46 )
{
return ! ! ( V_46 -> V_47 & ( V_48 | V_49 ) ) ;
}
static void * F_27 ( void * V_15 , unsigned long V_26 ,
unsigned long V_5 ,
enum V_16 V_17 )
{
struct V_18 * V_19 = V_15 ;
struct V_1 * V_2 ;
unsigned long V_50 , V_51 ;
int V_52 ;
struct V_45 * V_46 ;
struct V_20 * V_21 ;
F_7 ( V_24 ) ;
F_8 ( V_25 , & V_24 ) ;
V_2 = F_10 ( sizeof *V_2 , V_11 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_26 = NULL ;
V_2 -> V_33 = V_19 -> V_33 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_27 = V_26 & ~ V_53 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_29 = & V_2 -> V_20 ;
V_50 = ( V_26 & V_53 ) >> V_28 ;
V_51 = ( ( V_26 + V_5 - 1 ) & V_53 ) >> V_28 ;
V_2 -> V_23 = V_51 - V_50 + 1 ;
V_2 -> V_7 = F_10 ( V_2 -> V_23 * sizeof( struct V_6 * ) ,
V_11 ) ;
if ( ! V_2 -> V_7 )
goto V_54;
V_46 = F_28 ( V_55 -> V_56 , V_26 ) ;
if ( ! V_46 ) {
F_15 ( 1 , L_3 , V_26 ) ;
goto V_57;
}
if ( V_46 -> V_58 < V_26 + V_5 ) {
F_15 ( 1 , L_4 ,
V_26 , V_5 ) ;
goto V_57;
}
V_2 -> V_46 = F_29 ( V_46 ) ;
if ( ! V_2 -> V_46 ) {
F_15 ( 1 , L_5 ) ;
goto V_57;
}
if ( F_26 ( V_2 -> V_46 ) ) {
for ( V_52 = 0 ;
V_52 < V_2 -> V_23 ;
++ V_52 , V_26 += V_10 ) {
unsigned long V_59 ;
if ( F_30 ( V_46 , V_26 , & V_59 ) ) {
F_15 ( 1 , L_6 , V_26 ) ;
break;
}
V_2 -> V_7 [ V_52 ] = F_31 ( V_59 ) ;
}
} else
V_52 = F_32 ( V_55 , V_55 -> V_56 ,
V_26 & V_53 ,
V_2 -> V_23 ,
V_2 -> V_17 == V_60 ,
1 ,
V_2 -> V_7 ,
NULL ) ;
if ( V_52 != V_2 -> V_23 )
goto V_61;
if ( F_11 ( V_2 -> V_29 , V_2 -> V_7 ,
V_2 -> V_23 , V_2 -> V_27 , V_5 , 0 ) )
goto V_62;
V_21 = & V_2 -> V_20 ;
if ( F_13 ( V_2 -> V_33 , V_21 -> V_34 , V_21 -> V_35 ,
V_2 -> V_17 , & V_24 ) == 0 )
goto V_63;
return V_2 ;
V_63:
F_17 ( & V_2 -> V_20 ) ;
V_62:
V_61:
F_15 ( 1 , L_7 ,
V_2 -> V_23 , V_52 ) ;
if ( ! F_26 ( V_2 -> V_46 ) )
while ( -- V_52 >= 0 )
F_33 ( V_2 -> V_7 [ V_52 ] ) ;
F_34 ( V_2 -> V_46 ) ;
V_57:
F_18 ( V_2 -> V_7 ) ;
V_54:
F_18 ( V_2 ) ;
return NULL ;
}
static void F_35 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
struct V_20 * V_21 = & V_2 -> V_20 ;
int V_9 = V_2 -> V_23 ;
F_7 ( V_24 ) ;
F_8 ( V_25 , & V_24 ) ;
F_15 ( 1 , L_8 ,
V_42 , V_2 -> V_23 ) ;
F_20 ( V_2 -> V_33 , V_21 -> V_34 , V_21 -> V_35 , V_2 -> V_17 , & V_24 ) ;
if ( V_2 -> V_26 )
F_21 ( V_2 -> V_26 , V_2 -> V_23 ) ;
F_17 ( V_2 -> V_29 ) ;
while ( -- V_9 >= 0 ) {
if ( V_2 -> V_17 == V_60 )
F_36 ( V_2 -> V_7 [ V_9 ] ) ;
if ( ! F_26 ( V_2 -> V_46 ) )
F_33 ( V_2 -> V_7 [ V_9 ] ) ;
}
F_18 ( V_2 -> V_7 ) ;
F_34 ( V_2 -> V_46 ) ;
F_18 ( V_2 ) ;
}
static void * F_37 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
F_38 ( ! V_2 ) ;
if ( ! V_2 -> V_26 ) {
if ( V_2 -> V_44 )
V_2 -> V_26 = F_39 ( V_2 -> V_44 -> V_64 ) ;
else
V_2 -> V_26 = F_40 ( V_2 -> V_7 ,
V_2 -> V_23 , - 1 , V_65 ) ;
}
return V_2 -> V_26 ? V_2 -> V_26 + V_2 -> V_27 : NULL ;
}
static unsigned int F_41 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
return F_42 ( & V_2 -> V_38 ) ;
}
static int F_43 ( void * V_43 , struct V_45 * V_46 )
{
struct V_1 * V_2 = V_43 ;
unsigned long V_66 = V_46 -> V_67 ;
unsigned long V_68 = V_46 -> V_58 - V_46 -> V_67 ;
int V_9 = 0 ;
if ( ! V_2 ) {
F_44 ( V_69 L_9 ) ;
return - V_70 ;
}
do {
int V_22 ;
V_22 = F_45 ( V_46 , V_66 , V_2 -> V_7 [ V_9 ++ ] ) ;
if ( V_22 ) {
F_44 ( V_69 L_10 , V_22 ) ;
return V_22 ;
}
V_66 += V_10 ;
V_68 -= V_10 ;
} while ( V_68 > 0 );
V_46 -> V_71 = & V_2 -> V_37 ;
V_46 -> V_72 = & V_73 ;
V_46 -> V_72 -> V_74 ( V_46 ) ;
return 0 ;
}
static int F_46 ( struct V_75 * V_76 , struct V_77 * V_33 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 ;
unsigned int V_9 ;
struct V_82 * V_83 , * V_84 ;
struct V_20 * V_21 ;
struct V_1 * V_2 = V_76 -> V_85 ;
int V_22 ;
V_81 = F_10 ( sizeof( * V_81 ) , V_11 ) ;
if ( ! V_81 )
return - V_14 ;
V_21 = & V_81 -> V_21 ;
V_22 = F_47 ( V_21 , V_2 -> V_29 -> V_86 , V_11 ) ;
if ( V_22 ) {
F_18 ( V_81 ) ;
return - V_14 ;
}
V_83 = V_2 -> V_29 -> V_34 ;
V_84 = V_21 -> V_34 ;
for ( V_9 = 0 ; V_9 < V_21 -> V_86 ; ++ V_9 ) {
F_48 ( V_84 , F_49 ( V_83 ) , V_83 -> V_87 , V_83 -> V_27 ) ;
V_83 = F_50 ( V_83 ) ;
V_84 = F_50 ( V_84 ) ;
}
V_81 -> V_17 = V_88 ;
V_79 -> V_85 = V_81 ;
return 0 ;
}
static void F_51 ( struct V_75 * V_76 ,
struct V_78 * V_44 )
{
struct V_80 * V_81 = V_44 -> V_85 ;
struct V_20 * V_21 ;
if ( ! V_81 )
return;
V_21 = & V_81 -> V_21 ;
if ( V_81 -> V_17 != V_88 )
F_52 ( V_44 -> V_33 , V_21 -> V_34 , V_21 -> V_86 ,
V_81 -> V_17 ) ;
F_17 ( V_21 ) ;
F_18 ( V_81 ) ;
V_44 -> V_85 = NULL ;
}
static struct V_20 * F_53 (
struct V_78 * V_44 , enum V_16 V_17 )
{
struct V_80 * V_81 = V_44 -> V_85 ;
struct V_89 * V_90 = & V_44 -> V_64 -> V_90 ;
struct V_20 * V_21 ;
int V_22 ;
F_54 ( V_90 ) ;
V_21 = & V_81 -> V_21 ;
if ( V_81 -> V_17 == V_17 ) {
F_55 ( V_90 ) ;
return V_21 ;
}
if ( V_81 -> V_17 != V_88 ) {
F_52 ( V_44 -> V_33 , V_21 -> V_34 , V_21 -> V_86 ,
V_81 -> V_17 ) ;
V_81 -> V_17 = V_88 ;
}
V_22 = F_56 ( V_44 -> V_33 , V_21 -> V_34 , V_21 -> V_86 , V_17 ) ;
if ( V_22 <= 0 ) {
F_57 ( L_11 ) ;
F_55 ( V_90 ) ;
return F_58 ( - V_91 ) ;
}
V_81 -> V_17 = V_17 ;
F_55 ( V_90 ) ;
return V_21 ;
}
static void F_59 ( struct V_78 * V_44 ,
struct V_20 * V_21 , enum V_16 V_17 )
{
}
static void F_60 ( struct V_75 * V_76 )
{
V_40 ( V_76 -> V_85 ) ;
}
static void * F_61 ( struct V_75 * V_76 , unsigned long V_92 )
{
struct V_1 * V_2 = V_76 -> V_85 ;
return V_2 -> V_26 ? V_2 -> V_26 + V_92 * V_10 : NULL ;
}
static void * F_62 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = V_76 -> V_85 ;
return F_37 ( V_2 ) ;
}
static int F_63 ( struct V_75 * V_76 ,
struct V_45 * V_46 )
{
return F_43 ( V_76 -> V_85 , V_46 ) ;
}
static struct V_75 * F_64 ( void * V_43 , unsigned long V_93 )
{
struct V_1 * V_2 = V_43 ;
struct V_75 * V_76 ;
if ( F_9 ( ! V_2 -> V_29 ) )
return NULL ;
V_76 = F_65 ( V_2 , & V_94 , V_2 -> V_5 , V_93 , NULL ) ;
if ( F_66 ( V_76 ) )
return NULL ;
F_14 ( & V_2 -> V_38 ) ;
return V_76 ;
}
static int F_67 ( void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_20 * V_21 ;
if ( F_9 ( ! V_2 -> V_44 ) ) {
F_57 ( L_12 ) ;
return - V_70 ;
}
if ( F_9 ( V_2 -> V_29 ) ) {
F_57 ( L_13 ) ;
return 0 ;
}
V_21 = F_68 ( V_2 -> V_44 , V_2 -> V_17 ) ;
if ( F_66 ( V_21 ) ) {
F_57 ( L_14 ) ;
return - V_70 ;
}
V_2 -> V_29 = V_21 ;
V_2 -> V_26 = NULL ;
return 0 ;
}
static void F_69 ( void * V_95 )
{
struct V_1 * V_2 = V_95 ;
struct V_20 * V_21 = V_2 -> V_29 ;
if ( F_9 ( ! V_2 -> V_44 ) ) {
F_57 ( L_15 ) ;
return;
}
if ( F_9 ( ! V_21 ) ) {
F_57 ( L_16 ) ;
return;
}
if ( V_2 -> V_26 ) {
F_70 ( V_2 -> V_44 -> V_64 , V_2 -> V_26 ) ;
V_2 -> V_26 = NULL ;
}
F_71 ( V_2 -> V_44 , V_21 , V_2 -> V_17 ) ;
V_2 -> V_29 = NULL ;
}
static void F_72 ( void * V_95 )
{
struct V_1 * V_2 = V_95 ;
if ( F_9 ( V_2 -> V_29 ) )
F_69 ( V_2 ) ;
F_73 ( V_2 -> V_44 -> V_64 , V_2 -> V_44 ) ;
F_18 ( V_2 ) ;
}
static void * F_74 ( void * V_15 , struct V_75 * V_76 ,
unsigned long V_5 , enum V_16 V_17 )
{
struct V_18 * V_19 = V_15 ;
struct V_1 * V_2 ;
struct V_78 * V_96 ;
if ( V_76 -> V_5 < V_5 )
return F_58 ( - V_97 ) ;
V_2 = F_10 ( sizeof( * V_2 ) , V_11 ) ;
if ( ! V_2 )
return F_58 ( - V_14 ) ;
V_2 -> V_33 = V_19 -> V_33 ;
V_96 = F_75 ( V_76 , V_2 -> V_33 ) ;
if ( F_66 ( V_96 ) ) {
F_57 ( L_17 ) ;
F_18 ( V_2 ) ;
return V_96 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_44 = V_96 ;
return V_2 ;
}
static void * F_76 ( void * V_43 )
{
struct V_1 * V_2 = V_43 ;
return V_2 -> V_29 ;
}
void * F_77 ( struct V_77 * V_33 )
{
struct V_18 * V_19 ;
V_19 = F_10 ( sizeof( * V_19 ) , V_11 ) ;
if ( ! V_19 )
return F_58 ( - V_14 ) ;
V_19 -> V_33 = V_33 ;
return V_19 ;
}
void F_78 ( void * V_15 )
{
if ( ! F_79 ( V_15 ) )
F_18 ( V_15 ) ;
}

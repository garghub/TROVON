static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 ,
bool V_4 )
{
if ( ! V_4 || F_2 ( V_5 , V_2 ) )
return F_3 ( V_3 ) ;
return V_3 ;
}
static void * F_4 ( struct V_6 * V_7 , T_2 V_8 ,
T_3 * V_9 , T_4 V_10 ,
struct V_1 * V_2 )
{
if ( V_7 == NULL ) {
F_5 ( 1 , L_1 ) ;
return NULL ;
}
if ( F_6 ( V_11 ) &&
V_7 -> V_12 <= F_7 ( 32 ) )
V_10 |= V_13 ;
if ( F_6 ( V_14 ) ) {
struct V_15 * V_15 ;
V_8 = F_8 ( V_8 ) ;
V_15 = F_9 ( V_7 , V_8 >> V_16 ,
F_10 ( V_8 ) ) ;
if ( ! V_15 )
return NULL ;
* V_9 = F_11 ( V_7 , F_12 ( V_15 ) ) ;
return F_13 ( V_15 ) ;
} else {
return F_14 ( V_7 , V_8 , V_9 , V_10 ) ;
}
}
static void F_15 ( struct V_6 * V_7 , T_2 V_8 ,
void * V_17 , T_3 V_9 ,
struct V_1 * V_2 )
{
if ( V_7 == NULL ) {
F_5 ( 1 , L_1 ) ;
return;
}
if ( F_6 ( V_14 ) ) {
T_5 V_18 = F_16 ( V_7 , V_9 ) ;
F_17 ( V_7 ,
F_18 ( V_18 ) ,
V_8 >> V_16 ) ;
} else {
F_19 ( V_7 , V_8 , V_17 , V_9 ) ;
}
}
static void * F_20 ( struct V_6 * V_7 , T_2 V_8 ,
T_3 * V_9 , T_4 V_10 ,
struct V_1 * V_2 )
{
struct V_15 * V_15 , * * V_19 ;
void * V_20 , * V_21 ;
int V_22 , V_23 ;
V_8 = F_8 ( V_8 ) ;
V_22 = F_10 ( V_8 ) ;
V_20 = F_4 ( V_7 , V_8 , V_9 , V_10 , V_2 ) ;
if ( ! V_20 )
goto V_24;
V_19 = F_21 ( sizeof( struct V_15 * ) << V_22 , V_10 & ~ V_13 ) ;
if ( ! V_19 )
goto V_25;
F_22 ( V_20 , V_20 + V_8 ) ;
V_15 = F_23 ( V_20 ) ;
for ( V_23 = 0 ; V_23 < ( V_8 >> V_16 ) ; V_23 ++ )
V_19 [ V_23 ] = V_15 + V_23 ;
V_21 = F_24 ( V_19 , V_8 >> V_16 , V_26 ,
F_1 ( V_2 , V_27 , false ) ) ;
F_25 ( V_19 ) ;
if ( ! V_21 )
goto V_25;
return V_21 ;
V_25:
F_15 ( V_7 , V_8 , V_20 , * V_9 , V_2 ) ;
V_24:
* V_9 = ~ 0 ;
return NULL ;
}
static void F_26 ( struct V_6 * V_7 , T_2 V_8 ,
void * V_17 , T_3 V_9 ,
struct V_1 * V_2 )
{
void * V_28 = F_27 ( F_16 ( V_7 , V_9 ) ) ;
F_28 ( V_17 ) ;
F_15 ( V_7 , V_8 , V_28 , V_9 , V_2 ) ;
}
static T_3 F_29 ( struct V_6 * V_7 , struct V_15 * V_15 ,
unsigned long V_29 , T_2 V_8 ,
enum V_30 V_31 ,
struct V_1 * V_2 )
{
T_3 V_32 ;
V_32 = F_30 ( V_7 , V_15 , V_29 , V_8 , V_31 , V_2 ) ;
F_31 ( F_27 ( F_16 ( V_7 , V_32 ) ) , V_8 , V_31 ) ;
return V_32 ;
}
static void F_32 ( struct V_6 * V_7 , T_3 V_32 ,
T_2 V_8 , enum V_30 V_31 ,
struct V_1 * V_2 )
{
F_33 ( F_27 ( F_16 ( V_7 , V_32 ) ) , V_8 , V_31 ) ;
F_34 ( V_7 , V_32 , V_8 , V_31 , V_2 ) ;
}
static int F_35 ( struct V_6 * V_7 , struct V_33 * V_34 ,
int V_35 , enum V_30 V_31 ,
struct V_1 * V_2 )
{
struct V_33 * V_36 ;
int V_23 , V_37 ;
V_37 = F_36 ( V_7 , V_34 , V_35 , V_31 , V_2 ) ;
F_37 (sgl, sg, ret, i)
F_31 ( F_27 ( F_16 ( V_7 , V_36 -> V_38 ) ) ,
V_36 -> V_39 , V_31 ) ;
return V_37 ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_33 * V_34 , int V_35 ,
enum V_30 V_31 ,
struct V_1 * V_2 )
{
struct V_33 * V_36 ;
int V_23 ;
F_37 (sgl, sg, nelems, i)
F_33 ( F_27 ( F_16 ( V_7 , V_36 -> V_38 ) ) ,
V_36 -> V_39 , V_31 ) ;
F_39 ( V_7 , V_34 , V_35 , V_31 , V_2 ) ;
}
static void F_40 ( struct V_6 * V_7 ,
T_3 V_32 , T_2 V_8 ,
enum V_30 V_31 )
{
F_33 ( F_27 ( F_16 ( V_7 , V_32 ) ) , V_8 , V_31 ) ;
F_41 ( V_7 , V_32 , V_8 , V_31 ) ;
}
static void F_42 ( struct V_6 * V_7 ,
T_3 V_32 , T_2 V_8 ,
enum V_30 V_31 )
{
F_43 ( V_7 , V_32 , V_8 , V_31 ) ;
F_31 ( F_27 ( F_16 ( V_7 , V_32 ) ) , V_8 , V_31 ) ;
}
static void F_44 ( struct V_6 * V_7 ,
struct V_33 * V_34 , int V_35 ,
enum V_30 V_31 )
{
struct V_33 * V_36 ;
int V_23 ;
F_37 (sgl, sg, nelems, i)
F_33 ( F_27 ( F_16 ( V_7 , V_36 -> V_38 ) ) ,
V_36 -> V_39 , V_31 ) ;
F_45 ( V_7 , V_34 , V_35 , V_31 ) ;
}
static void F_46 ( struct V_6 * V_7 ,
struct V_33 * V_34 , int V_35 ,
enum V_30 V_31 )
{
struct V_33 * V_36 ;
int V_23 ;
F_47 ( V_7 , V_34 , V_35 , V_31 ) ;
F_37 (sgl, sg, nelems, i)
F_31 ( F_27 ( F_16 ( V_7 , V_36 -> V_38 ) ) ,
V_36 -> V_39 , V_31 ) ;
}
static int F_48 ( struct V_6 * V_7 , struct V_40 * V_41 ,
void * V_42 , T_3 V_43 , T_2 V_8 )
{
int V_37 = - V_44 ;
unsigned long V_45 = ( V_41 -> V_46 - V_41 -> V_47 ) >>
V_16 ;
unsigned long V_48 = F_8 ( V_8 ) >> V_16 ;
unsigned long V_49 = F_16 ( V_7 , V_43 ) >> V_16 ;
unsigned long V_50 = V_41 -> V_51 ;
if ( F_49 ( V_7 , V_41 , V_42 , V_8 , & V_37 ) )
return V_37 ;
if ( V_50 < V_48 && V_45 <= ( V_48 - V_50 ) ) {
V_37 = F_50 ( V_41 , V_41 -> V_47 ,
V_49 + V_50 ,
V_41 -> V_46 - V_41 -> V_47 ,
V_41 -> V_52 ) ;
}
return V_37 ;
}
static int F_51 ( struct V_6 * V_7 ,
struct V_40 * V_41 ,
void * V_42 , T_3 V_43 , T_2 V_8 ,
struct V_1 * V_2 )
{
V_41 -> V_52 = F_1 ( V_2 , V_41 -> V_52 , false ) ;
return F_48 ( V_7 , V_41 , V_42 , V_43 , V_8 ) ;
}
static int F_52 ( struct V_6 * V_7 ,
struct V_40 * V_41 ,
void * V_42 , T_3 V_43 , T_2 V_8 ,
struct V_1 * V_2 )
{
return F_48 ( V_7 , V_41 , V_42 , V_43 , V_8 ) ;
}
static int F_53 ( struct V_53 * V_54 ,
unsigned long V_55 , void * V_56 )
{
struct V_6 * V_7 = V_56 ;
if ( V_55 != V_57 )
return V_58 ;
if ( F_54 ( V_7 -> V_59 , L_2 ) )
F_55 ( V_7 , & V_60 ) ;
return V_61 ;
}
static int T_6 F_56 ( void )
{
T_2 V_62 = F_57 ( V_63 , V_64 << V_16 ) ;
F_58 ( & V_65 , & V_66 ) ;
F_58 ( & V_67 , & V_68 ) ;
V_69 = & V_70 ;
return F_59 ( V_62 ) ;
}
static int T_6 F_60 ( void )
{
F_61 ( V_71 ) ;
return 0 ;
}

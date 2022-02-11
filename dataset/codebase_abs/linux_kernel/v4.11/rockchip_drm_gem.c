static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 = V_4 -> V_9 ;
int V_10 = V_11 | V_12 ;
T_1 V_13 ;
F_2 ( & V_8 -> V_14 ) ;
V_13 = F_3 ( & V_8 -> V_15 , & V_2 -> V_15 ,
V_2 -> V_5 . V_16 , V_17 ,
0 , 0 ) ;
F_4 ( & V_8 -> V_14 ) ;
if ( V_13 < 0 ) {
F_5 ( L_1 , V_13 ) ;
return V_13 ;
}
V_2 -> V_18 = V_2 -> V_15 . V_19 ;
V_13 = F_6 ( V_8 -> V_20 , V_2 -> V_18 , V_2 -> V_21 -> V_22 ,
V_2 -> V_21 -> V_23 , V_10 ) ;
if ( V_13 < V_2 -> V_5 . V_16 ) {
F_5 ( L_2 ,
V_13 , V_2 -> V_5 . V_16 ) ;
V_13 = - V_24 ;
goto V_25;
}
V_2 -> V_16 = V_13 ;
return 0 ;
V_25:
F_7 ( & V_2 -> V_15 ) ;
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 = V_4 -> V_9 ;
F_9 ( V_8 -> V_20 , V_2 -> V_18 , V_2 -> V_16 ) ;
F_2 ( & V_8 -> V_14 ) ;
F_7 ( & V_2 -> V_15 ) ;
F_4 ( & V_8 -> V_14 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
int V_13 , V_26 ;
struct V_27 * V_28 ;
V_2 -> V_29 = F_11 ( & V_2 -> V_5 ) ;
if ( F_12 ( V_2 -> V_29 ) )
return F_13 ( V_2 -> V_29 ) ;
V_2 -> V_30 = V_2 -> V_5 . V_16 >> V_31 ;
V_2 -> V_21 = F_14 ( V_2 -> V_29 , V_2 -> V_30 ) ;
if ( F_12 ( V_2 -> V_21 ) ) {
V_13 = F_13 ( V_2 -> V_21 ) ;
goto V_32;
}
F_15 (rk_obj->sgt->sgl, s, rk_obj->sgt->nents, i)
F_16 ( V_28 ) = F_17 ( V_28 ) ;
F_18 ( V_4 -> V_6 , V_2 -> V_21 -> V_22 , V_2 -> V_21 -> V_23 ,
V_33 ) ;
return 0 ;
V_32:
F_19 ( & V_2 -> V_5 , V_2 -> V_29 , false , false ) ;
return V_13 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 -> V_21 ) ;
F_22 ( V_2 -> V_21 ) ;
F_19 ( & V_2 -> V_5 , V_2 -> V_29 , true , true ) ;
}
static int F_23 ( struct V_1 * V_2 ,
bool V_34 )
{
int V_13 ;
V_13 = F_10 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 < 0 )
goto V_35;
if ( V_34 ) {
V_2 -> V_36 = F_24 ( V_2 -> V_29 , V_2 -> V_30 , V_37 ,
F_25 ( V_38 ) ) ;
if ( ! V_2 -> V_36 ) {
F_5 ( L_3 ) ;
V_13 = - V_24 ;
goto V_39;
}
}
return 0 ;
V_39:
F_8 ( V_2 ) ;
V_35:
F_20 ( V_2 ) ;
return V_13 ;
}
static int F_26 ( struct V_1 * V_2 ,
bool V_34 )
{
struct V_40 * V_41 = & V_2 -> V_5 ;
struct V_3 * V_4 = V_41 -> V_6 ;
V_2 -> V_42 = V_43 ;
if ( ! V_34 )
V_2 -> V_42 |= V_44 ;
V_2 -> V_36 = F_27 ( V_4 -> V_6 , V_41 -> V_16 ,
& V_2 -> V_18 , V_45 ,
V_2 -> V_42 ) ;
if ( ! V_2 -> V_36 ) {
F_5 ( L_4 , V_41 -> V_16 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
bool V_34 )
{
struct V_40 * V_41 = & V_2 -> V_5 ;
struct V_3 * V_4 = V_41 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_9 ;
if ( V_8 -> V_20 )
return F_23 ( V_2 , V_34 ) ;
else
return F_26 ( V_2 , V_34 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 -> V_36 ) ;
F_8 ( V_2 ) ;
F_20 ( V_2 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = & V_2 -> V_5 ;
struct V_3 * V_4 = V_41 -> V_6 ;
F_32 ( V_4 -> V_6 , V_41 -> V_16 , V_2 -> V_36 , V_2 -> V_18 ,
V_2 -> V_42 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 )
F_29 ( V_2 ) ;
else
F_31 ( V_2 ) ;
}
static int F_34 ( struct V_40 * V_41 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
unsigned int V_26 , V_48 = V_41 -> V_16 >> V_31 ;
unsigned long V_49 = ( V_47 -> V_50 - V_47 -> V_51 ) >> V_31 ;
unsigned long V_52 = V_47 -> V_51 ;
unsigned long V_53 = V_47 -> V_54 ;
unsigned long V_55 = V_49 + V_53 ;
int V_13 ;
if ( V_49 == 0 )
return - V_56 ;
if ( V_55 > V_48 )
return - V_56 ;
for ( V_26 = V_53 ; V_26 < V_55 ; V_26 ++ ) {
V_13 = F_36 ( V_47 , V_52 , V_2 -> V_29 [ V_26 ] ) ;
if ( V_13 )
return V_13 ;
V_52 += V_17 ;
}
return 0 ;
}
static int F_37 ( struct V_40 * V_41 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
struct V_3 * V_4 = V_41 -> V_6 ;
return F_38 ( V_4 -> V_6 , V_47 , V_2 -> V_36 , V_2 -> V_18 ,
V_41 -> V_16 , V_2 -> V_42 ) ;
}
static int F_39 ( struct V_40 * V_41 ,
struct V_46 * V_47 )
{
int V_13 ;
struct V_1 * V_2 = F_35 ( V_41 ) ;
V_47 -> V_57 &= ~ V_58 ;
V_47 -> V_54 = 0 ;
if ( V_2 -> V_29 )
V_13 = F_34 ( V_41 , V_47 ) ;
else
V_13 = F_37 ( V_41 , V_47 ) ;
if ( V_13 )
F_40 ( V_47 ) ;
return V_13 ;
}
int F_41 ( struct V_40 * V_41 ,
struct V_46 * V_47 )
{
int V_13 ;
V_13 = F_42 ( V_41 , V_41 -> V_16 , V_47 ) ;
if ( V_13 )
return V_13 ;
return F_39 ( V_41 , V_47 ) ;
}
int F_43 ( struct V_59 * V_60 , struct V_46 * V_47 )
{
struct V_40 * V_41 ;
int V_13 ;
V_13 = F_44 ( V_60 , V_47 ) ;
if ( V_13 )
return V_13 ;
V_41 = V_47 -> V_61 ;
return F_39 ( V_41 , V_47 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( & V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
}
struct V_1 *
F_47 ( struct V_3 * V_4 , unsigned int V_16 ,
bool V_34 )
{
struct V_1 * V_2 ;
struct V_40 * V_41 ;
int V_13 ;
V_16 = F_48 ( V_16 , V_17 ) ;
V_2 = F_49 ( sizeof( * V_2 ) , V_45 ) ;
if ( ! V_2 )
return F_50 ( - V_24 ) ;
V_41 = & V_2 -> V_5 ;
F_51 ( V_4 , V_41 , V_16 ) ;
V_13 = F_28 ( V_2 , V_34 ) ;
if ( V_13 )
goto V_62;
return V_2 ;
V_62:
F_45 ( V_2 ) ;
return F_50 ( V_13 ) ;
}
void F_52 ( struct V_40 * V_41 )
{
struct V_1 * V_2 ;
V_2 = F_35 ( V_41 ) ;
F_33 ( V_2 ) ;
F_45 ( V_2 ) ;
}
static struct V_1 *
F_53 ( struct V_63 * V_64 ,
struct V_3 * V_4 , unsigned int V_16 ,
unsigned int * V_65 )
{
struct V_1 * V_2 ;
struct V_40 * V_41 ;
int V_13 ;
V_2 = F_47 ( V_4 , V_16 , false ) ;
if ( F_12 ( V_2 ) )
return F_54 ( V_2 ) ;
V_41 = & V_2 -> V_5 ;
V_13 = F_55 ( V_64 , V_41 , V_65 ) ;
if ( V_13 )
goto V_66;
F_56 ( V_41 ) ;
return V_2 ;
V_66:
F_52 ( V_41 ) ;
return F_50 ( V_13 ) ;
}
int F_57 ( struct V_63 * V_64 ,
struct V_3 * V_6 , T_2 V_65 ,
T_3 * V_53 )
{
struct V_40 * V_41 ;
int V_13 ;
V_41 = F_58 ( V_64 , V_65 ) ;
if ( ! V_41 ) {
F_5 ( L_5 ) ;
return - V_67 ;
}
V_13 = F_59 ( V_41 ) ;
if ( V_13 )
goto V_68;
* V_53 = F_60 ( & V_41 -> V_69 ) ;
F_61 ( L_6 , * V_53 ) ;
V_68:
F_56 ( V_41 ) ;
return 0 ;
}
int F_62 ( struct V_63 * V_64 ,
struct V_3 * V_6 ,
struct V_70 * args )
{
struct V_1 * V_2 ;
int V_71 = F_63 ( args -> V_72 * args -> V_73 , 8 ) ;
args -> V_74 = F_64 ( V_71 , 64 ) ;
args -> V_16 = args -> V_74 * args -> V_75 ;
V_2 = F_53 ( V_64 , V_6 , args -> V_16 ,
& args -> V_65 ) ;
return F_65 ( V_2 ) ;
}
struct V_76 * F_66 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
struct V_3 * V_4 = V_41 -> V_6 ;
struct V_76 * V_21 ;
int V_13 ;
if ( V_2 -> V_29 )
return F_14 ( V_2 -> V_29 , V_2 -> V_30 ) ;
V_21 = F_49 ( sizeof( * V_21 ) , V_45 ) ;
if ( ! V_21 )
return F_50 ( - V_24 ) ;
V_13 = F_67 ( V_4 -> V_6 , V_21 , V_2 -> V_36 ,
V_2 -> V_18 , V_41 -> V_16 ,
V_2 -> V_42 ) ;
if ( V_13 ) {
F_5 ( L_7 , V_13 ) ;
F_22 ( V_21 ) ;
return F_50 ( V_13 ) ;
}
return V_21 ;
}
void * F_68 ( struct V_40 * V_41 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
if ( V_2 -> V_29 )
return F_24 ( V_2 -> V_29 , V_2 -> V_30 , V_37 ,
F_25 ( V_38 ) ) ;
if ( V_2 -> V_42 & V_44 )
return NULL ;
return V_2 -> V_36 ;
}
void F_69 ( struct V_40 * V_41 , void * V_77 )
{
struct V_1 * V_2 = F_35 ( V_41 ) ;
if ( V_2 -> V_29 ) {
F_30 ( V_77 ) ;
return;
}
}

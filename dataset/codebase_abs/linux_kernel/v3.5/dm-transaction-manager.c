static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = 0 ;
unsigned V_5 = F_2 ( V_3 , V_6 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
F_3 ( & V_2 -> V_11 ) ;
F_4 (si, n, tm->buckets + bucket, hlist)
if ( V_8 -> V_12 == V_3 ) {
V_4 = 1 ;
break;
}
F_5 ( & V_2 -> V_11 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned V_5 ;
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_13 ) ;
if ( V_8 ) {
V_8 -> V_12 = V_3 ;
V_5 = F_2 ( V_3 , V_6 ) ;
F_3 ( & V_2 -> V_11 ) ;
F_8 ( & V_8 -> V_14 , V_2 -> V_15 + V_5 ) ;
F_5 ( & V_2 -> V_11 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 , * V_16 ;
struct V_17 * V_5 ;
int V_18 ;
F_3 ( & V_2 -> V_11 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_5 = V_2 -> V_15 + V_18 ;
F_10 (si, n, tmp, bucket, hlist)
F_11 ( V_8 ) ;
F_12 ( V_5 ) ;
}
F_5 ( & V_2 -> V_11 ) ;
}
static struct V_1 * F_13 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
int V_18 ;
struct V_1 * V_2 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return F_14 ( - V_25 ) ;
V_2 -> V_26 = 0 ;
V_2 -> V_27 = NULL ;
V_2 -> V_21 = V_21 ;
V_2 -> V_23 = V_23 ;
F_15 ( & V_2 -> V_11 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ )
F_12 ( V_2 -> V_15 + V_18 ) ;
return V_2 ;
}
struct V_1 * F_16 ( struct V_1 * V_27 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_24 ) ;
if ( V_2 ) {
V_2 -> V_26 = 1 ;
V_2 -> V_27 = V_27 ;
}
return V_2 ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_26 )
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_26 )
return - V_28 ;
V_4 = F_19 ( V_2 -> V_23 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , struct V_29 * V_30 )
{
if ( V_2 -> V_26 )
return - V_28 ;
F_9 ( V_2 ) ;
return F_21 ( V_2 -> V_21 , V_30 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_29 * * V_33 )
{
int V_4 ;
T_1 V_34 ;
if ( V_2 -> V_26 )
return - V_28 ;
V_4 = F_23 ( V_2 -> V_23 , & V_34 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_24 ( V_2 -> V_21 , V_34 , V_32 , V_33 ) ;
if ( V_4 < 0 ) {
F_25 ( V_2 -> V_23 , V_34 ) ;
return V_4 ;
}
F_6 ( V_2 , V_34 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_35 ,
struct V_31 * V_32 ,
struct V_29 * * V_33 )
{
int V_4 ;
T_1 V_36 ;
struct V_29 * V_37 ;
V_4 = F_23 ( V_2 -> V_23 , & V_36 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_25 ( V_2 -> V_23 , V_35 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_27 ( V_2 -> V_21 , V_35 , V_32 , & V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_28 ( V_37 , V_36 ) ;
if ( V_4 < 0 ) {
F_29 ( V_37 ) ;
return V_4 ;
}
return F_30 ( V_2 -> V_21 , V_36 , V_32 , V_33 ) ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_35 ,
struct V_31 * V_32 , struct V_29 * * V_33 ,
int * V_38 )
{
int V_4 ;
if ( V_2 -> V_26 )
return - V_28 ;
V_4 = F_32 ( V_2 -> V_23 , V_35 , V_38 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( F_1 ( V_2 , V_35 ) && ! * V_38 )
return F_30 ( V_2 -> V_21 , V_35 , V_32 , V_33 ) ;
V_4 = F_26 ( V_2 , V_35 , V_32 , V_33 ) ;
if ( V_4 < 0 )
return V_4 ;
F_6 ( V_2 , F_33 ( * V_33 ) ) ;
return V_4 ;
}
int F_34 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_31 * V_32 ,
struct V_29 * * V_39 )
{
if ( V_2 -> V_26 )
return F_35 ( V_2 -> V_27 -> V_21 , V_3 , V_32 , V_39 ) ;
return F_27 ( V_2 -> V_21 , V_3 , V_32 , V_39 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_29 * V_3 )
{
return F_29 ( V_3 ) ;
}
void F_37 ( struct V_1 * V_2 , T_1 V_3 )
{
F_38 ( V_2 -> V_26 ) ;
F_39 ( V_2 -> V_23 , V_3 ) ;
}
void F_40 ( struct V_1 * V_2 , T_1 V_3 )
{
F_38 ( V_2 -> V_26 ) ;
F_25 ( V_2 -> V_23 , V_3 ) ;
}
int F_41 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_33 )
{
if ( V_2 -> V_26 )
return - V_28 ;
return F_42 ( V_2 -> V_23 , V_3 , V_33 ) ;
}
struct V_20 * F_43 ( struct V_1 * V_2 )
{
return V_2 -> V_21 ;
}
static int F_44 ( struct V_20 * V_21 ,
T_1 V_40 ,
struct V_31 * V_41 ,
T_3 V_42 , T_3 V_43 ,
struct V_1 * * V_2 ,
struct V_22 * * V_23 ,
struct V_29 * * V_44 ,
int V_45 )
{
int V_4 ;
struct V_22 * V_46 ;
V_46 = F_45 () ;
if ( F_46 ( V_46 ) )
return F_47 ( V_46 ) ;
* V_2 = F_13 ( V_21 , V_46 ) ;
if ( F_46 ( * V_2 ) ) {
F_48 ( V_46 ) ;
return F_47 ( * V_2 ) ;
}
if ( V_45 ) {
V_4 = F_24 ( F_43 ( * V_2 ) , V_40 ,
V_41 , V_44 ) ;
if ( V_4 < 0 ) {
F_49 ( L_1 ) ;
goto V_47;
}
V_4 = F_50 ( V_46 , * V_2 , F_51 ( V_21 ) ,
V_40 ) ;
if ( V_4 ) {
F_49 ( L_2 ) ;
goto V_48;
}
* V_23 = F_52 ( V_46 ) ;
if ( F_46 ( * V_23 ) ) {
V_4 = F_47 ( * V_23 ) ;
goto V_48;
}
} else {
V_4 = F_30 ( F_43 ( * V_2 ) , V_40 ,
V_41 , V_44 ) ;
if ( V_4 < 0 ) {
F_49 ( L_1 ) ;
goto V_47;
}
V_4 = F_53 ( V_46 , * V_2 ,
F_54 ( * V_44 ) + V_42 ,
V_43 ) ;
if ( V_4 ) {
F_49 ( L_3 ) ;
goto V_48;
}
* V_23 = F_52 ( V_46 ) ;
if ( F_46 ( * V_23 ) ) {
V_4 = F_47 ( * V_23 ) ;
goto V_48;
}
}
return 0 ;
V_48:
F_36 ( * V_2 , * V_44 ) ;
V_47:
F_17 ( * V_2 ) ;
F_48 ( V_46 ) ;
return V_4 ;
}
int F_55 ( struct V_20 * V_21 , T_1 V_40 ,
struct V_31 * V_41 ,
struct V_1 * * V_2 ,
struct V_22 * * V_23 , struct V_29 * * V_44 )
{
return F_44 ( V_21 , V_40 , V_41 ,
0 , 0 , V_2 , V_23 , V_44 , 1 ) ;
}
int F_56 ( struct V_20 * V_21 , T_1 V_40 ,
struct V_31 * V_41 ,
T_3 V_42 , T_3 V_43 ,
struct V_1 * * V_2 ,
struct V_22 * * V_23 , struct V_29 * * V_44 )
{
return F_44 ( V_21 , V_40 , V_41 , V_42 ,
V_43 , V_2 , V_23 , V_44 , 0 ) ;
}

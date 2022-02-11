static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 = 0 ;
unsigned V_5 = F_2 ( V_3 , V_6 ) ;
struct V_7 * V_8 ;
F_3 ( & V_2 -> V_9 ) ;
F_4 (si, tm->buckets + bucket, hlist)
if ( V_8 -> V_10 == V_3 ) {
V_4 = 1 ;
break;
}
F_5 ( & V_2 -> V_9 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned V_5 ;
struct V_7 * V_8 ;
V_8 = F_7 ( sizeof( * V_8 ) , V_11 ) ;
if ( V_8 ) {
V_8 -> V_10 = V_3 ;
V_5 = F_2 ( V_3 , V_6 ) ;
F_3 ( & V_2 -> V_9 ) ;
F_8 ( & V_8 -> V_12 , V_2 -> V_13 + V_5 ) ;
F_5 ( & V_2 -> V_9 ) ;
}
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
struct V_14 * V_15 ;
struct V_16 * V_5 ;
int V_17 ;
F_3 ( & V_2 -> V_9 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_5 = V_2 -> V_13 + V_17 ;
F_10 (si, tmp, bucket, hlist)
F_11 ( V_8 ) ;
F_12 ( V_5 ) ;
}
F_5 ( & V_2 -> V_9 ) ;
}
static struct V_1 * F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
int V_17 ;
struct V_1 * V_2 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 )
return F_14 ( - V_24 ) ;
V_2 -> V_25 = 0 ;
V_2 -> V_26 = NULL ;
V_2 -> V_20 = V_20 ;
V_2 -> V_22 = V_22 ;
F_15 ( & V_2 -> V_9 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
F_12 ( V_2 -> V_13 + V_17 ) ;
return V_2 ;
}
struct V_1 * F_16 ( struct V_1 * V_26 )
{
struct V_1 * V_2 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_23 ) ;
if ( V_2 ) {
V_2 -> V_25 = 1 ;
V_2 -> V_26 = V_26 ;
}
return V_2 ;
}
void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_25 )
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_25 )
return - V_27 ;
V_4 = F_19 ( V_2 -> V_22 ) ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
if ( V_2 -> V_25 )
return - V_27 ;
F_9 ( V_2 ) ;
return F_21 ( V_2 -> V_20 , V_29 ) ;
}
int F_22 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_28 * * V_32 )
{
int V_4 ;
T_1 V_33 ;
if ( V_2 -> V_25 )
return - V_27 ;
V_4 = F_23 ( V_2 -> V_22 , & V_33 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_24 ( V_2 -> V_20 , V_33 , V_31 , V_32 ) ;
if ( V_4 < 0 ) {
F_25 ( V_2 -> V_22 , V_33 ) ;
return V_4 ;
}
F_6 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_34 ,
struct V_30 * V_31 ,
struct V_28 * * V_32 )
{
int V_4 ;
T_1 V_35 ;
struct V_28 * V_36 ;
V_4 = F_23 ( V_2 -> V_22 , & V_35 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_25 ( V_2 -> V_22 , V_34 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_27 ( V_2 -> V_20 , V_34 , V_31 , & V_36 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_24 ( V_2 -> V_20 , V_35 , V_31 , V_32 ) ;
if ( V_4 ) {
F_28 ( V_36 ) ;
return V_4 ;
}
memcpy ( F_29 ( * V_32 ) , F_29 ( V_36 ) ,
F_30 ( V_2 -> V_20 ) ) ;
F_28 ( V_36 ) ;
return V_4 ;
}
int F_31 ( struct V_1 * V_2 , T_1 V_34 ,
struct V_30 * V_31 , struct V_28 * * V_32 ,
int * V_37 )
{
int V_4 ;
if ( V_2 -> V_25 )
return - V_27 ;
V_4 = F_32 ( V_2 -> V_22 , V_34 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( F_1 ( V_2 , V_34 ) && ! * V_37 )
return F_33 ( V_2 -> V_20 , V_34 , V_31 , V_32 ) ;
V_4 = F_26 ( V_2 , V_34 , V_31 , V_32 ) ;
if ( V_4 < 0 )
return V_4 ;
F_6 ( V_2 , F_34 ( * V_32 ) ) ;
return V_4 ;
}
int F_35 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_30 * V_31 ,
struct V_28 * * V_38 )
{
if ( V_2 -> V_25 )
return F_36 ( V_2 -> V_26 -> V_20 , V_3 , V_31 , V_38 ) ;
return F_27 ( V_2 -> V_20 , V_3 , V_31 , V_38 ) ;
}
int F_37 ( struct V_1 * V_2 , struct V_28 * V_3 )
{
return F_28 ( V_3 ) ;
}
void F_38 ( struct V_1 * V_2 , T_1 V_3 )
{
F_39 ( V_2 -> V_25 ) ;
F_40 ( V_2 -> V_22 , V_3 ) ;
}
void F_41 ( struct V_1 * V_2 , T_1 V_3 )
{
F_39 ( V_2 -> V_25 ) ;
F_25 ( V_2 -> V_22 , V_3 ) ;
}
int F_42 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_32 )
{
if ( V_2 -> V_25 )
return - V_27 ;
return F_43 ( V_2 -> V_22 , V_3 , V_32 ) ;
}
struct V_19 * F_44 ( struct V_1 * V_2 )
{
return V_2 -> V_20 ;
}
static int F_45 ( struct V_19 * V_20 ,
T_1 V_39 ,
struct V_1 * * V_2 ,
struct V_21 * * V_22 ,
int V_40 ,
void * V_41 , T_3 V_42 )
{
int V_4 ;
* V_22 = F_46 () ;
if ( F_47 ( * V_22 ) )
return F_48 ( * V_22 ) ;
* V_2 = F_13 ( V_20 , * V_22 ) ;
if ( F_47 ( * V_2 ) ) {
F_49 ( * V_22 ) ;
return F_48 ( * V_2 ) ;
}
if ( V_40 ) {
V_4 = F_50 ( * V_22 , * V_2 , F_51 ( V_20 ) ,
V_39 ) ;
if ( V_4 ) {
F_52 ( L_1 ) ;
goto V_43;
}
} else {
V_4 = F_53 ( * V_22 , * V_2 , V_41 , V_42 ) ;
if ( V_4 ) {
F_52 ( L_2 ) ;
goto V_43;
}
}
return 0 ;
V_43:
F_17 ( * V_2 ) ;
F_49 ( * V_22 ) ;
return V_4 ;
}
int F_54 ( struct V_19 * V_20 , T_1 V_39 ,
struct V_1 * * V_2 ,
struct V_21 * * V_22 )
{
return F_45 ( V_20 , V_39 , V_2 , V_22 , 1 , NULL , 0 ) ;
}
int F_55 ( struct V_19 * V_20 , T_1 V_39 ,
void * V_41 , T_3 V_44 ,
struct V_1 * * V_2 ,
struct V_21 * * V_22 )
{
return F_45 ( V_20 , V_39 , V_2 , V_22 , 0 , V_41 , V_44 ) ;
}

static unsigned F_1 ( T_1 V_1 )
{
return F_2 ( V_1 , V_2 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
unsigned V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
V_4 -> V_7 [ V_5 ] = V_8 ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_9 ) ;
F_3 ( V_4 ) ;
}
static void F_6 ( struct V_3 * V_4 , T_1 V_1 )
{
unsigned V_10 = F_1 ( V_1 ) ;
F_7 ( & V_4 -> V_9 ) ;
if ( V_4 -> V_7 [ V_10 ] == V_8 )
V_4 -> V_7 [ V_10 ] = V_1 ;
F_8 ( & V_4 -> V_9 ) ;
}
static void F_9 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
unsigned V_5 ;
F_7 ( & V_4 -> V_9 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
if ( V_4 -> V_7 [ V_5 ] != V_8 ) {
F_10 ( V_12 , V_4 -> V_7 [ V_5 ] ) ;
V_4 -> V_7 [ V_5 ] = V_8 ;
}
F_8 ( & V_4 -> V_9 ) ;
}
static int F_11 ( struct V_13 * V_14 , T_1 V_1 )
{
int V_15 = 0 ;
unsigned V_16 = F_12 ( V_1 , V_17 ) ;
struct V_18 * V_19 ;
F_13 ( & V_14 -> V_9 ) ;
F_14 (si, tm->buckets + bucket, hlist)
if ( V_19 -> V_20 == V_1 ) {
V_15 = 1 ;
break;
}
F_15 ( & V_14 -> V_9 ) ;
return V_15 ;
}
static void F_16 ( struct V_13 * V_14 , T_1 V_1 )
{
unsigned V_16 ;
struct V_18 * V_19 ;
V_19 = F_17 ( sizeof( * V_19 ) , V_21 ) ;
if ( V_19 ) {
V_19 -> V_20 = V_1 ;
V_16 = F_12 ( V_1 , V_17 ) ;
F_13 ( & V_14 -> V_9 ) ;
F_18 ( & V_19 -> V_22 , V_14 -> V_23 + V_16 ) ;
F_15 ( & V_14 -> V_9 ) ;
}
}
static void F_19 ( struct V_13 * V_14 )
{
struct V_18 * V_19 ;
struct V_24 * V_25 ;
struct V_26 * V_16 ;
int V_5 ;
F_13 ( & V_14 -> V_9 ) ;
for ( V_5 = 0 ; V_5 < V_27 ; V_5 ++ ) {
V_16 = V_14 -> V_23 + V_5 ;
F_20 (si, tmp, bucket, hlist)
F_21 ( V_19 ) ;
F_22 ( V_16 ) ;
}
F_15 ( & V_14 -> V_9 ) ;
}
static struct V_13 * F_23 ( struct V_11 * V_12 ,
struct V_28 * V_29 )
{
int V_5 ;
struct V_13 * V_14 ;
V_14 = F_17 ( sizeof( * V_14 ) , V_30 ) ;
if ( ! V_14 )
return F_24 ( - V_31 ) ;
V_14 -> V_32 = 0 ;
V_14 -> V_33 = NULL ;
V_14 -> V_12 = V_12 ;
V_14 -> V_29 = V_29 ;
F_25 ( & V_14 -> V_9 ) ;
for ( V_5 = 0 ; V_5 < V_27 ; V_5 ++ )
F_22 ( V_14 -> V_23 + V_5 ) ;
F_4 ( & V_14 -> V_34 ) ;
return V_14 ;
}
struct V_13 * F_26 ( struct V_13 * V_33 )
{
struct V_13 * V_14 ;
V_14 = F_17 ( sizeof( * V_14 ) , V_30 ) ;
if ( V_14 ) {
V_14 -> V_32 = 1 ;
V_14 -> V_33 = V_33 ;
}
return V_14 ;
}
void F_27 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_32 )
F_19 ( V_14 ) ;
F_21 ( V_14 ) ;
}
int F_28 ( struct V_13 * V_14 )
{
int V_15 ;
if ( V_14 -> V_32 )
return - V_35 ;
V_15 = F_29 ( V_14 -> V_29 ) ;
if ( V_15 < 0 )
return V_15 ;
return F_30 ( V_14 -> V_12 ) ;
}
int F_31 ( struct V_13 * V_14 , struct V_36 * V_37 )
{
if ( V_14 -> V_32 )
return - V_35 ;
F_19 ( V_14 ) ;
F_32 ( V_37 ) ;
return F_30 ( V_14 -> V_12 ) ;
}
int F_33 ( struct V_13 * V_14 ,
struct V_38 * V_39 ,
struct V_36 * * V_40 )
{
int V_15 ;
T_1 V_41 ;
if ( V_14 -> V_32 )
return - V_35 ;
V_15 = F_34 ( V_14 -> V_29 , & V_41 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_35 ( V_14 -> V_12 , V_41 , V_39 , V_40 ) ;
if ( V_15 < 0 ) {
F_36 ( V_14 -> V_29 , V_41 ) ;
return V_15 ;
}
F_16 ( V_14 , V_41 ) ;
return 0 ;
}
static int F_37 ( struct V_13 * V_14 , T_1 V_42 ,
struct V_38 * V_39 ,
struct V_36 * * V_40 )
{
int V_15 ;
T_1 V_43 ;
struct V_36 * V_44 ;
V_15 = F_34 ( V_14 -> V_29 , & V_43 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_36 ( V_14 -> V_29 , V_42 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_38 ( V_14 -> V_12 , V_42 , V_39 , & V_44 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_35 ( V_14 -> V_12 , V_43 , V_39 , V_40 ) ;
if ( V_15 ) {
F_32 ( V_44 ) ;
return V_15 ;
}
memcpy ( F_39 ( * V_40 ) , F_39 ( V_44 ) ,
F_40 ( V_14 -> V_12 ) ) ;
F_32 ( V_44 ) ;
return V_15 ;
}
int F_41 ( struct V_13 * V_14 , T_1 V_42 ,
struct V_38 * V_39 , struct V_36 * * V_40 ,
int * V_45 )
{
int V_15 ;
if ( V_14 -> V_32 )
return - V_35 ;
V_15 = F_42 ( V_14 -> V_29 , V_42 , V_45 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_11 ( V_14 , V_42 ) && ! * V_45 )
return F_43 ( V_14 -> V_12 , V_42 , V_39 , V_40 ) ;
V_15 = F_37 ( V_14 , V_42 , V_39 , V_40 ) ;
if ( V_15 < 0 )
return V_15 ;
F_16 ( V_14 , F_44 ( * V_40 ) ) ;
return V_15 ;
}
int F_45 ( struct V_13 * V_14 , T_1 V_1 ,
struct V_38 * V_39 ,
struct V_36 * * V_46 )
{
if ( V_14 -> V_32 ) {
int V_15 = F_46 ( V_14 -> V_33 -> V_12 , V_1 , V_39 , V_46 ) ;
if ( V_15 == - V_35 )
F_6 ( & V_14 -> V_33 -> V_34 , V_1 ) ;
return V_15 ;
}
return F_38 ( V_14 -> V_12 , V_1 , V_39 , V_46 ) ;
}
int F_47 ( struct V_13 * V_14 , struct V_36 * V_1 )
{
return F_32 ( V_1 ) ;
}
void F_48 ( struct V_13 * V_14 , T_1 V_1 )
{
F_49 ( V_14 -> V_32 ) ;
F_50 ( V_14 -> V_29 , V_1 ) ;
}
void F_51 ( struct V_13 * V_14 , T_1 V_1 )
{
F_49 ( V_14 -> V_32 ) ;
F_36 ( V_14 -> V_29 , V_1 ) ;
}
int F_52 ( struct V_13 * V_14 , T_1 V_1 ,
T_2 * V_40 )
{
if ( V_14 -> V_32 )
return - V_35 ;
return F_53 ( V_14 -> V_29 , V_1 , V_40 ) ;
}
struct V_11 * F_54 ( struct V_13 * V_14 )
{
return V_14 -> V_12 ;
}
void F_55 ( struct V_13 * V_14 )
{
F_9 ( & V_14 -> V_34 , V_14 -> V_12 ) ;
}
static int F_56 ( struct V_11 * V_12 ,
T_1 V_47 ,
struct V_13 * * V_14 ,
struct V_28 * * V_29 ,
int V_48 ,
void * V_49 , T_3 V_50 )
{
int V_15 ;
* V_29 = F_57 () ;
if ( F_58 ( * V_29 ) )
return F_59 ( * V_29 ) ;
* V_14 = F_23 ( V_12 , * V_29 ) ;
if ( F_58 ( * V_14 ) ) {
F_60 ( * V_29 ) ;
return F_59 ( * V_14 ) ;
}
if ( V_48 ) {
V_15 = F_61 ( * V_29 , * V_14 , F_62 ( V_12 ) ,
V_47 ) ;
if ( V_15 ) {
F_63 ( L_1 ) ;
goto V_51;
}
} else {
V_15 = F_64 ( * V_29 , * V_14 , V_49 , V_50 ) ;
if ( V_15 ) {
F_63 ( L_2 ) ;
goto V_51;
}
}
return 0 ;
V_51:
F_27 ( * V_14 ) ;
F_60 ( * V_29 ) ;
return V_15 ;
}
int F_65 ( struct V_11 * V_12 , T_1 V_47 ,
struct V_13 * * V_14 ,
struct V_28 * * V_29 )
{
return F_56 ( V_12 , V_47 , V_14 , V_29 , 1 , NULL , 0 ) ;
}
int F_66 ( struct V_11 * V_12 , T_1 V_47 ,
void * V_49 , T_3 V_52 ,
struct V_13 * * V_14 ,
struct V_28 * * V_29 )
{
return F_56 ( V_12 , V_47 , V_14 , V_29 , 0 , V_49 , V_52 ) ;
}

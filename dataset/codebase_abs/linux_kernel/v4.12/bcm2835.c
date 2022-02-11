static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_1 * V_4 = * (struct V_1 * * ) V_3 ;
F_2 ( V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_1 * V_5 )
{
struct V_1 * * V_6 ;
int V_7 ;
V_6 = F_4 ( F_1 , sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return - V_9 ;
V_7 = F_5 ( V_5 ) ;
if ( V_7 ) {
F_6 ( V_6 ) ;
return V_7 ;
}
* V_6 = V_5 ;
F_7 ( V_2 , V_6 ) ;
return 0 ;
}
static struct V_1 *
F_8 ( struct V_1 * V_10 ,
struct V_11 * V_12 ,
const char * V_13 )
{
struct V_1 * V_1 ;
int V_7 ;
V_1 = F_9 ( V_10 , sizeof( * V_1 ) , V_8 ) ;
if ( ! V_1 )
return F_10 ( - V_9 ) ;
F_11 ( V_1 ) ;
V_1 -> V_10 = V_10 ;
V_1 -> V_12 = V_12 ;
F_12 ( V_1 , L_1 , V_13 ) ;
V_7 = F_3 ( V_10 , V_1 ) ;
if ( V_7 )
return F_10 ( V_7 ) ;
return V_1 ;
}
static int F_13 ( struct V_14 * V_15 )
{
F_14 ( V_15 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_1 )
{
return F_13 ( V_1 -> V_17 ) ;
}
static int F_16 ( struct V_18 * V_19 ,
struct V_14 * * V_20 )
{
struct V_14 * V_15 ;
int V_21 ;
static struct V_22 V_23 = {
. V_24 = F_15 ,
} ;
* V_20 = NULL ;
V_15 = F_17 ( sizeof( * V_15 ) , V_8 ) ;
if ( ! V_15 )
return - V_9 ;
V_15 -> V_19 = V_19 ;
V_21 = F_18 ( V_19 , V_25 , V_15 , & V_23 ) ;
if ( V_21 ) {
F_13 ( V_15 ) ;
return V_21 ;
}
* V_20 = V_15 ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 , void * V_3 )
{
struct V_18 * V_18 = * (struct V_18 * * ) V_3 ;
F_20 ( V_18 ) ;
}
static struct V_18 * F_21 ( struct V_1 * V_2 )
{
struct V_18 * * V_6 ;
struct V_18 * V_19 ;
int V_7 ;
V_6 = F_4 ( F_19 , sizeof( * V_6 ) , V_8 ) ;
if ( ! V_6 )
return F_10 ( - V_9 ) ;
V_7 = F_22 ( V_2 , - 1 , NULL , V_26 , 0 , & V_19 ) ;
if ( V_7 ) {
F_6 ( V_6 ) ;
return F_10 ( V_7 ) ;
}
* V_6 = V_19 ;
F_7 ( V_2 , V_6 ) ;
return V_19 ;
}
static int F_23 ( struct V_14 * V_15 ,
const char * V_13 ,
enum V_27 V_28 ,
T_1 V_29 )
{
int V_21 ;
V_21 = F_24 ( V_15 , V_29 - 1 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_25 ( V_15 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 ,
struct V_30 * V_31 ,
T_1 V_32 )
{
struct V_18 * V_19 ;
struct V_1 * V_5 ;
struct V_14 * V_15 ;
int V_21 , V_33 ;
V_5 = F_8 ( V_1 , & V_31 -> V_12 ,
V_31 -> V_12 . V_13 ) ;
if ( F_27 ( V_5 ) ) {
F_28 ( V_1 ,
L_2 ,
V_31 -> V_12 . V_13 ,
F_29 ( V_5 ) ) ;
return F_29 ( V_5 ) ;
}
V_19 = F_21 ( V_5 ) ;
if ( F_27 ( V_19 ) ) {
F_28 ( V_5 , L_3 ) ;
return F_29 ( V_19 ) ;
}
F_30 ( V_19 , V_5 ) ;
strcpy ( V_19 -> V_12 , V_31 -> V_12 . V_13 ) ;
strcpy ( V_19 -> V_34 , V_31 -> V_34 ) ;
strcpy ( V_19 -> V_35 , V_31 -> V_35 ) ;
V_21 = F_16 ( V_19 , & V_15 ) ;
if ( V_21 ) {
F_28 ( V_5 , L_4 , V_21 ) ;
return V_21 ;
}
V_15 -> V_2 = V_5 ;
V_21 = V_31 -> V_36 ( V_15 , V_31 -> V_34 ,
V_31 -> V_28 ,
V_32 ) ;
if ( V_21 ) {
F_28 ( V_5 , L_5 , V_21 ) ;
return V_21 ;
}
V_21 = V_31 -> V_37 ( V_15 ) ;
if ( V_21 ) {
F_28 ( V_5 , L_6 , V_21 ) ;
return V_21 ;
}
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
V_15 -> V_38 |= ( 1 << V_33 ) ;
V_21 = F_31 ( V_19 ) ;
if ( V_21 ) {
F_28 ( V_5 , L_7 , V_21 ) ;
return V_21 ;
}
F_32 ( V_5 , V_19 ) ;
F_33 ( V_5 , L_8 , V_32 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , T_1 V_32 )
{
int V_33 ;
int V_39 = 0 ;
int V_40 = 0 ;
int V_41 = 0 ;
int V_42 = 0 ;
int V_43 = 0 ;
for ( V_33 = 0 ; V_33 < F_35 ( V_44 ) ; V_33 ++ )
if ( * V_44 [ V_33 ] . V_45 )
V_39 ++ ;
if ( ! V_39 )
return 0 ;
for ( V_33 = 0 ; V_33 < F_35 ( V_44 ) ; V_33 ++ )
if ( * V_44 [ V_33 ] . V_45 )
V_40 +=
V_44 [ V_33 ] . V_31 -> V_40 ;
if ( V_40 < V_32 ) {
V_41 = V_32 - V_40 ;
V_42 = V_41 / V_39 ;
V_43 = V_41 % V_39 ;
}
F_36 ( V_1 , L_9 , V_40 ) ;
F_36 ( V_1 , L_10 , V_41 ) ;
F_36 ( V_1 , L_11 ,
V_42 ) ;
F_36 ( V_1 , L_12 ,
V_43 ) ;
for ( V_33 = 0 ; V_33 < F_35 ( V_44 ) ; V_33 ++ ) {
int V_21 ;
int V_46 ;
struct V_30 * V_31 ;
if ( ! * V_44 [ V_33 ] . V_45 )
continue;
V_31 = V_44 [ V_33 ] . V_31 ;
if ( V_31 -> V_40 > V_32 ) {
F_28 ( V_1 ,
L_13 ,
V_31 -> V_40 ,
V_32 ) ;
continue;
}
V_46 =
V_31 -> V_40 + V_42 +
V_43 ;
V_43 = 0 ;
V_32 -= V_46 ;
V_21 = F_26 ( V_1 , V_31 ,
V_46 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static int F_37 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = & V_48 -> V_2 ;
T_1 V_32 ;
int V_21 ;
V_21 = F_38 ( V_2 -> V_49 , L_14 ,
& V_32 ) ;
if ( V_21 ) {
F_28 ( V_2 , L_15 ) ;
return V_21 ;
}
if ( V_32 == 0 || V_32 > V_50 ) {
V_32 = V_50 ;
F_39 ( V_2 ,
L_16 ,
V_32 ) ;
}
V_21 = F_34 ( V_2 , V_32 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_40 ( struct V_47 * V_48 ,
T_2 V_51 )
{
return 0 ;
}
static int F_41 ( struct V_47 * V_48 )
{
return 0 ;
}
static int F_42 ( void )
{
int V_52 ;
V_52 = F_43 ( & V_53 ) ;
if ( V_52 )
F_44 ( L_17 , V_52 ) ;
return V_52 ;
}
static void F_45 ( void )
{
F_46 ( & V_53 ) ;
}

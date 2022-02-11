static struct V_1 * F_1 ( unsigned V_2 )
{
struct V_1 * V_3 = NULL ;
F_2 ( & V_4 ) ;
V_3 = F_3 ( & V_5 , V_2 ) ;
if ( ! F_4 ( & V_3 -> V_6 ) )
V_3 = NULL ;
F_5 ( & V_4 ) ;
return V_3 ;
}
static struct V_1 * F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_3 ;
int V_2 ;
V_3 = F_7 ( sizeof( * V_3 ) , V_9 ) ;
if ( ! V_3 )
return F_8 ( - V_10 ) ;
V_3 -> V_8 = V_8 ;
F_9 ( & V_3 -> V_11 , 1 ) ;
F_10 ( & V_3 -> V_6 ) ;
F_2 ( & V_4 ) ;
V_2 = F_11 ( & V_5 , V_3 , 0 , V_12 ,
V_9 ) ;
F_5 ( & V_4 ) ;
if ( V_2 < 0 ) {
F_12 ( V_3 ) ;
return F_8 ( V_2 ) ;
}
V_3 -> V_2 = V_2 ;
return V_3 ;
}
static void F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_3 =
F_14 ( V_14 , struct V_1 , V_6 ) ;
F_12 ( V_3 ) ;
}
static T_1 F_15 ( struct V_15 * V_16 ,
struct V_17 * V_18 , char * V_19 )
{
T_1 V_20 ;
struct V_1 * V_3 =
F_1 ( F_16 ( V_16 -> V_21 ) ) ;
if ( ! V_3 )
return - V_22 ;
V_20 = sprintf ( V_19 , L_1 , V_3 -> V_8 -> V_23 ) ;
F_17 ( & V_3 -> V_6 , F_13 ) ;
return V_20 ;
}
static int F_18 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
unsigned int V_26 = F_19 ( V_24 ) ;
struct V_1 * V_3 ;
V_3 = F_1 ( V_26 ) ;
if ( ! V_3 )
return - V_22 ;
V_25 -> V_27 = V_3 ;
return 0 ;
}
static T_2 F_20 ( struct V_25 * V_25 , T_2 V_28 , int V_29 )
{
return F_21 ( V_25 , V_28 , V_29 , V_30 ) ;
}
static T_1 F_22 ( struct V_25 * V_25 , char T_3 * V_19 , T_4 V_31 ,
T_2 * V_28 )
{
T_4 V_32 , V_33 = 0 ;
struct V_1 * V_3 = V_25 -> V_27 ;
T_1 V_20 = 0 ;
if ( ! F_23 ( & V_3 -> V_11 ) )
return - V_22 ;
V_32 = F_24 ( ( T_2 ) V_31 , V_30 - ( * V_28 ) ) ;
if ( ! F_25 ( V_34 , V_19 , V_32 ) ) {
V_20 = - V_35 ;
goto V_36;
}
while ( V_32 > 0 ) {
T_5 V_37 [ V_38 ] ;
T_1 V_39 = F_26 ( T_4 , V_32 , sizeof( V_37 ) ) ;
V_20 = F_27 ( V_3 -> V_8 , * V_28 , V_37 , V_39 ) ;
if ( V_20 <= 0 ) {
V_20 = V_33 ? V_33 : V_20 ;
goto V_36;
}
if ( F_28 ( V_19 + V_33 , V_37 , V_20 ) ) {
V_20 = V_33 ?
V_33 : - V_35 ;
goto V_36;
}
V_32 -= V_20 ;
* V_28 += V_20 ;
V_33 += V_20 ;
V_20 = V_33 ;
}
V_36:
F_29 ( & V_3 -> V_11 ) ;
F_30 ( & V_3 -> V_11 ) ;
return V_20 ;
}
static T_1 F_31 ( struct V_25 * V_25 , const char T_3 * V_19 ,
T_4 V_31 , T_2 * V_28 )
{
T_4 V_32 , V_33 = 0 ;
struct V_1 * V_3 = V_25 -> V_27 ;
T_1 V_20 = 0 ;
if ( ! F_23 ( & V_3 -> V_11 ) )
return - V_22 ;
V_32 = F_24 ( ( T_2 ) V_31 , V_30 - * V_28 ) ;
if ( ! F_25 ( V_40 , V_19 , V_32 ) ) {
V_20 = - V_35 ;
goto V_36;
}
while ( V_32 > 0 ) {
T_5 V_37 [ V_38 ] ;
T_1 V_39 = F_26 ( T_4 , V_32 , sizeof( V_37 ) ) ;
if ( F_32 ( V_37 ,
V_19 + V_33 , V_39 ) ) {
V_20 = V_33 ?
V_33 : - V_35 ;
goto V_36;
}
V_20 = F_33 ( V_3 -> V_8 , * V_28 , V_37 , V_39 ) ;
if ( V_20 <= 0 ) {
V_20 = V_33 ? V_33 : V_20 ;
goto V_36;
}
V_32 -= V_20 ;
* V_28 += V_20 ;
V_33 += V_20 ;
V_20 = V_33 ;
}
V_36:
F_29 ( & V_3 -> V_11 ) ;
F_30 ( & V_3 -> V_11 ) ;
return V_20 ;
}
static int F_34 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_1 * V_3 = V_25 -> V_27 ;
F_17 ( & V_3 -> V_6 , F_13 ) ;
return 0 ;
}
static struct V_1 * F_35 ( struct V_7 * V_8 )
{
struct V_1 * V_41 , * V_3 = NULL ;
int V_42 ;
F_2 ( & V_4 ) ;
F_36 (&aux_idr, iter, id) {
if ( V_41 -> V_8 == V_8 ) {
V_3 = V_41 ;
break;
}
}
F_5 ( & V_4 ) ;
return V_3 ;
}
static int F_37 ( T_6 * V_43 )
{
F_38 () ;
return 0 ;
}
void F_39 ( struct V_7 * V_8 )
{
struct V_1 * V_3 ;
unsigned int V_26 ;
V_3 = F_35 ( V_8 ) ;
if ( ! V_3 )
return;
F_2 ( & V_4 ) ;
F_40 ( & V_5 , V_3 -> V_2 ) ;
F_5 ( & V_4 ) ;
F_29 ( & V_3 -> V_11 ) ;
F_41 ( & V_3 -> V_11 , F_37 ,
V_44 ) ;
V_26 = V_3 -> V_2 ;
if ( V_3 -> V_16 )
F_42 ( V_45 ,
F_43 ( V_46 , V_26 ) ) ;
F_44 ( L_2 , V_8 -> V_23 ) ;
F_17 ( & V_3 -> V_6 , F_13 ) ;
}
int F_45 ( struct V_7 * V_8 )
{
struct V_1 * V_3 ;
int V_20 ;
V_3 = F_6 ( V_8 ) ;
if ( F_46 ( V_3 ) )
return F_47 ( V_3 ) ;
V_3 -> V_16 = F_48 ( V_45 , V_8 -> V_16 ,
F_43 ( V_46 , V_3 -> V_2 ) , NULL ,
L_3 , V_3 -> V_2 ) ;
if ( F_46 ( V_3 -> V_16 ) ) {
V_20 = F_47 ( V_3 -> V_16 ) ;
V_3 -> V_16 = NULL ;
goto error;
}
F_44 ( L_4 ,
V_8 -> V_23 , V_3 -> V_2 ) ;
return 0 ;
error:
F_39 ( V_8 ) ;
return V_20 ;
}
int F_49 ( void )
{
int V_20 ;
V_45 = F_50 ( V_47 , L_5 ) ;
if ( F_46 ( V_45 ) ) {
V_20 = F_47 ( V_45 ) ;
goto V_36;
}
V_45 -> V_48 = V_49 ;
V_20 = F_51 ( 0 , L_6 , & V_50 ) ;
if ( V_20 < 0 )
goto V_36;
V_46 = V_20 ;
return 0 ;
V_36:
F_52 ( V_45 ) ;
return V_20 ;
}
void F_53 ( void )
{
F_54 ( V_46 , L_6 ) ;
F_52 ( V_45 ) ;
}

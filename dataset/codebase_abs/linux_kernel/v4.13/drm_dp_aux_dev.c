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
static T_1 F_22 ( struct V_31 * V_32 , struct V_33 * V_34 )
{
struct V_1 * V_3 = V_32 -> V_35 -> V_27 ;
T_2 V_36 = V_32 -> V_37 ;
T_1 V_20 = 0 ;
if ( ! F_23 ( & V_3 -> V_11 ) )
return - V_22 ;
F_24 ( V_34 , V_30 - V_36 ) ;
while ( F_25 ( V_34 ) ) {
T_3 V_19 [ V_38 ] ;
T_1 V_39 = F_26 ( F_25 ( V_34 ) , sizeof( V_19 ) ) ;
if ( F_27 ( V_40 ) ) {
V_20 = - V_41 ;
break;
}
V_20 = F_28 ( V_3 -> V_8 , V_36 , V_19 , V_39 ) ;
if ( V_20 <= 0 )
break;
if ( F_29 ( V_19 , V_20 , V_34 ) != V_20 ) {
V_20 = - V_42 ;
break;
}
V_36 += V_20 ;
}
if ( V_36 != V_32 -> V_37 )
V_20 = V_36 - V_32 -> V_37 ;
V_32 -> V_37 = V_36 ;
F_30 ( & V_3 -> V_11 ) ;
F_31 ( & V_3 -> V_11 ) ;
return V_20 ;
}
static T_1 F_32 ( struct V_31 * V_32 , struct V_33 * V_43 )
{
struct V_1 * V_3 = V_32 -> V_35 -> V_27 ;
T_2 V_36 = V_32 -> V_37 ;
T_1 V_20 = 0 ;
if ( ! F_23 ( & V_3 -> V_11 ) )
return - V_22 ;
F_24 ( V_43 , V_30 - V_36 ) ;
while ( F_25 ( V_43 ) ) {
T_3 V_19 [ V_38 ] ;
T_1 V_39 = F_26 ( F_25 ( V_43 ) , sizeof( V_19 ) ) ;
if ( F_27 ( V_40 ) ) {
V_20 = - V_41 ;
break;
}
if ( ! F_33 ( V_19 , V_39 , V_43 ) ) {
V_20 = - V_42 ;
break;
}
V_20 = F_34 ( V_3 -> V_8 , V_36 , V_19 , V_39 ) ;
if ( V_20 <= 0 )
break;
V_36 += V_20 ;
}
if ( V_36 != V_32 -> V_37 )
V_20 = V_36 - V_32 -> V_37 ;
V_32 -> V_37 = V_36 ;
F_30 ( & V_3 -> V_11 ) ;
F_31 ( & V_3 -> V_11 ) ;
return V_20 ;
}
static int F_35 ( struct V_24 * V_24 , struct V_25 * V_25 )
{
struct V_1 * V_3 = V_25 -> V_27 ;
F_17 ( & V_3 -> V_6 , F_13 ) ;
return 0 ;
}
static struct V_1 * F_36 ( struct V_7 * V_8 )
{
struct V_1 * V_44 , * V_3 = NULL ;
int V_45 ;
F_2 ( & V_4 ) ;
F_37 (&aux_idr, iter, id) {
if ( V_44 -> V_8 == V_8 ) {
V_3 = V_44 ;
break;
}
}
F_5 ( & V_4 ) ;
return V_3 ;
}
static int F_38 ( T_4 * V_46 )
{
F_39 () ;
return 0 ;
}
void F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_3 ;
unsigned int V_26 ;
V_3 = F_36 ( V_8 ) ;
if ( ! V_3 )
return;
F_2 ( & V_4 ) ;
F_41 ( & V_5 , V_3 -> V_2 ) ;
F_5 ( & V_4 ) ;
F_30 ( & V_3 -> V_11 ) ;
F_42 ( & V_3 -> V_11 , F_38 ,
V_47 ) ;
V_26 = V_3 -> V_2 ;
if ( V_3 -> V_16 )
F_43 ( V_48 ,
F_44 ( V_49 , V_26 ) ) ;
F_45 ( L_2 , V_8 -> V_23 ) ;
F_17 ( & V_3 -> V_6 , F_13 ) ;
}
int F_46 ( struct V_7 * V_8 )
{
struct V_1 * V_3 ;
int V_20 ;
V_3 = F_6 ( V_8 ) ;
if ( F_47 ( V_3 ) )
return F_48 ( V_3 ) ;
V_3 -> V_16 = F_49 ( V_48 , V_8 -> V_16 ,
F_44 ( V_49 , V_3 -> V_2 ) , NULL ,
L_3 , V_3 -> V_2 ) ;
if ( F_47 ( V_3 -> V_16 ) ) {
V_20 = F_48 ( V_3 -> V_16 ) ;
V_3 -> V_16 = NULL ;
goto error;
}
F_45 ( L_4 ,
V_8 -> V_23 , V_3 -> V_2 ) ;
return 0 ;
error:
F_40 ( V_8 ) ;
return V_20 ;
}
int F_50 ( void )
{
int V_20 ;
V_48 = F_51 ( V_50 , L_5 ) ;
if ( F_47 ( V_48 ) ) {
return F_48 ( V_48 ) ;
}
V_48 -> V_51 = V_52 ;
V_20 = F_52 ( 0 , L_6 , & V_53 ) ;
if ( V_20 < 0 )
goto V_54;
V_49 = V_20 ;
return 0 ;
V_54:
F_53 ( V_48 ) ;
return V_20 ;
}
void F_54 ( void )
{
F_55 ( V_49 , L_6 ) ;
F_53 ( V_48 ) ;
}

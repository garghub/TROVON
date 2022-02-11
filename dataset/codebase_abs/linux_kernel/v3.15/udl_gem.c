struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_1 * V_5 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_6 ) ;
if ( V_5 == NULL )
return NULL ;
if ( F_3 ( V_3 , & V_5 -> V_7 , V_4 ) != 0 ) {
F_4 ( V_5 ) ;
return NULL ;
}
return V_5 ;
}
static int
F_5 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
T_2 V_4 ,
T_3 * V_10 )
{
struct V_1 * V_5 ;
int V_11 ;
T_4 V_12 ;
V_4 = F_6 ( V_4 , V_13 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 == NULL )
return - V_14 ;
V_11 = F_7 ( V_9 , & V_5 -> V_7 , & V_12 ) ;
if ( V_11 ) {
F_8 ( & V_5 -> V_7 ) ;
F_4 ( V_5 ) ;
return V_11 ;
}
F_9 ( & V_5 -> V_7 ) ;
* V_10 = V_12 ;
return 0 ;
}
int F_10 ( struct V_8 * V_9 ,
struct V_2 * V_3 ,
struct V_15 * args )
{
args -> V_16 = args -> V_17 * F_11 ( args -> V_18 , 8 ) ;
args -> V_4 = args -> V_16 * args -> V_19 ;
return F_5 ( V_9 , V_3 ,
args -> V_4 , & args -> V_12 ) ;
}
int F_12 ( struct V_9 * V_20 , struct V_21 * V_22 )
{
int V_11 ;
V_11 = F_13 ( V_20 , V_22 ) ;
if ( V_11 )
return V_11 ;
V_22 -> V_23 &= ~ V_24 ;
V_22 -> V_23 |= V_25 ;
return V_11 ;
}
int F_14 ( struct V_21 * V_22 , struct V_26 * V_27 )
{
struct V_1 * V_5 = F_15 ( V_22 -> V_28 ) ;
struct V_29 * V_29 ;
unsigned int V_30 ;
int V_11 = 0 ;
V_30 = ( ( unsigned long ) V_27 -> V_31 - V_22 -> V_32 ) >>
V_33 ;
if ( ! V_5 -> V_34 )
return V_35 ;
V_29 = V_5 -> V_34 [ V_30 ] ;
V_11 = F_16 ( V_22 , ( unsigned long ) V_27 -> V_31 , V_29 ) ;
switch ( V_11 ) {
case - V_36 :
case 0 :
case - V_37 :
return V_38 ;
case - V_14 :
return V_39 ;
default:
return V_35 ;
}
}
static int F_17 ( struct V_1 * V_5 , T_5 V_40 )
{
struct V_29 * * V_34 ;
if ( V_5 -> V_34 )
return 0 ;
V_34 = F_18 ( & V_5 -> V_7 , V_40 ) ;
if ( F_19 ( V_34 ) )
return F_20 ( V_34 ) ;
V_5 -> V_34 = V_34 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_5 )
{
if ( V_5 -> V_7 . V_41 ) {
F_22 ( V_5 -> V_34 ) ;
V_5 -> V_34 = NULL ;
return;
}
F_23 ( & V_5 -> V_7 , V_5 -> V_34 , false , false ) ;
V_5 -> V_34 = NULL ;
}
int F_24 ( struct V_1 * V_5 )
{
int V_42 = V_5 -> V_7 . V_4 / V_13 ;
int V_11 ;
if ( V_5 -> V_7 . V_41 ) {
V_5 -> V_43 = F_25 ( V_5 -> V_7 . V_41 -> V_44 ) ;
if ( ! V_5 -> V_43 )
return - V_14 ;
return 0 ;
}
V_11 = F_17 ( V_5 , V_6 ) ;
if ( V_11 )
return V_11 ;
V_5 -> V_43 = F_26 ( V_5 -> V_34 , V_42 , 0 , V_45 ) ;
if ( ! V_5 -> V_43 )
return - V_14 ;
return 0 ;
}
void F_27 ( struct V_1 * V_5 )
{
if ( V_5 -> V_7 . V_41 ) {
F_28 ( V_5 -> V_7 . V_41 -> V_44 , V_5 -> V_43 ) ;
return;
}
if ( V_5 -> V_43 )
F_29 ( V_5 -> V_43 ) ;
F_21 ( V_5 ) ;
}
void F_30 ( struct V_46 * V_47 )
{
struct V_1 * V_5 = F_15 ( V_47 ) ;
if ( V_5 -> V_43 )
F_27 ( V_5 ) ;
if ( V_47 -> V_41 ) {
F_31 ( V_47 , V_5 -> V_48 ) ;
F_32 ( V_47 -> V_3 -> V_3 ) ;
}
if ( V_5 -> V_34 )
F_21 ( V_5 ) ;
F_33 ( V_47 ) ;
}
int F_34 ( struct V_8 * V_9 , struct V_2 * V_3 ,
T_3 V_12 , T_2 * V_49 )
{
struct V_1 * V_50 ;
struct V_46 * V_5 ;
int V_11 = 0 ;
F_35 ( & V_3 -> V_51 ) ;
V_5 = F_36 ( V_3 , V_9 , V_12 ) ;
if ( V_5 == NULL ) {
V_11 = - V_52 ;
goto V_53;
}
V_50 = F_15 ( V_5 ) ;
V_11 = F_17 ( V_50 , V_6 ) ;
if ( V_11 )
goto V_54;
V_11 = F_37 ( V_5 ) ;
if ( V_11 )
goto V_54;
* V_49 = F_38 ( & V_50 -> V_7 . V_55 ) ;
V_54:
F_9 ( & V_50 -> V_7 ) ;
V_53:
F_39 ( & V_3 -> V_51 ) ;
return V_11 ;
}
static int F_40 ( struct V_2 * V_3 ,
T_1 V_4 ,
struct V_56 * V_48 ,
struct V_1 * * V_57 )
{
struct V_1 * V_5 ;
int V_58 ;
V_58 = V_4 / V_13 ;
* V_57 = NULL ;
V_5 = F_1 ( V_3 , V_58 * V_13 ) ;
if ( ! V_5 )
return - V_14 ;
V_5 -> V_48 = V_48 ;
V_5 -> V_34 = F_41 ( V_58 , sizeof( struct V_29 * ) ) ;
if ( V_5 -> V_34 == NULL ) {
F_42 ( L_1 , V_58 ) ;
return - V_14 ;
}
F_43 ( V_48 , V_5 -> V_34 , NULL , V_58 ) ;
* V_57 = V_5 ;
return 0 ;
}
struct V_46 * F_44 ( struct V_2 * V_3 ,
struct V_59 * V_59 )
{
struct V_60 * V_61 ;
struct V_56 * V_48 ;
struct V_1 * V_62 ;
int V_11 ;
F_45 ( V_3 -> V_3 ) ;
V_61 = F_46 ( V_59 , V_3 -> V_3 ) ;
if ( F_19 ( V_61 ) ) {
F_32 ( V_3 -> V_3 ) ;
return F_47 ( V_61 ) ;
}
F_48 ( V_59 ) ;
V_48 = F_49 ( V_61 , V_63 ) ;
if ( F_19 ( V_48 ) ) {
V_11 = F_20 ( V_48 ) ;
goto V_64;
}
V_11 = F_40 ( V_3 , V_59 -> V_4 , V_48 , & V_62 ) ;
if ( V_11 ) {
goto V_65;
}
V_62 -> V_7 . V_41 = V_61 ;
return & V_62 -> V_7 ;
V_65:
F_50 ( V_61 , V_48 , V_63 ) ;
V_64:
F_51 ( V_59 , V_61 ) ;
F_52 ( V_59 ) ;
F_32 ( V_3 -> V_3 ) ;
return F_53 ( V_11 ) ;
}

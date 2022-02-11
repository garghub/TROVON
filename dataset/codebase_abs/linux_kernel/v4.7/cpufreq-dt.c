static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
return F_2 ( V_5 -> V_7 ,
V_2 -> V_8 [ V_3 ] . V_9 * 1000 ) ;
}
static const char * F_3 ( struct V_10 * V_11 )
{
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 = V_11 -> V_17 ;
const char * V_18 = NULL ;
V_13 = F_4 ( V_11 -> V_19 ) ;
if ( F_5 ( ! V_13 ) )
return NULL ;
if ( ! V_16 ) {
V_15 = F_6 ( V_13 , L_1 , NULL ) ;
if ( V_15 ) {
V_18 = L_2 ;
goto V_20;
}
}
V_15 = F_6 ( V_13 , L_3 , NULL ) ;
if ( V_15 ) {
V_18 = L_4 ;
goto V_20;
}
F_7 ( V_11 , L_5 , V_16 ) ;
V_20:
F_8 ( V_13 ) ;
return V_18 ;
}
static int F_9 ( void )
{
struct V_10 * V_7 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_25 = 0 ;
const char * V_18 ;
V_7 = F_10 ( 0 ) ;
if ( ! V_7 ) {
F_11 ( L_6 ) ;
return - V_26 ;
}
V_24 = F_12 ( V_7 , NULL ) ;
V_25 = F_13 ( V_24 ) ;
if ( V_25 ) {
if ( V_25 == - V_27 )
F_7 ( V_7 , L_7 ) ;
else
F_14 ( V_7 , L_8 , V_25 ) ;
return V_25 ;
}
F_15 ( V_24 ) ;
V_18 = F_3 ( V_7 ) ;
if ( ! V_18 )
return 0 ;
V_22 = F_16 ( V_7 , V_18 ) ;
V_25 = F_13 ( V_22 ) ;
if ( V_25 ) {
if ( V_25 == - V_27 )
F_7 ( V_7 , L_9 ) ;
else
F_7 ( V_7 , L_10 , V_25 ) ;
return V_25 ;
}
F_17 ( V_22 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_28 * V_8 ;
struct V_4 * V_5 ;
struct V_10 * V_7 ;
struct V_23 * V_24 ;
struct V_29 * V_30 ;
unsigned int V_31 ;
bool V_32 = false ;
const char * V_18 ;
int V_25 ;
V_7 = F_10 ( V_2 -> V_16 ) ;
if ( ! V_7 ) {
F_11 ( L_11 , V_2 -> V_16 ) ;
return - V_26 ;
}
V_24 = F_12 ( V_7 , NULL ) ;
if ( F_19 ( V_24 ) ) {
V_25 = F_20 ( V_24 ) ;
F_14 ( V_7 , L_12 , V_33 , V_25 ) ;
return V_25 ;
}
V_25 = F_21 ( V_7 , V_2 -> V_34 ) ;
if ( V_25 ) {
if ( V_25 != - V_35 )
goto V_36;
if ( F_22 ( V_7 , V_2 -> V_34 ) )
V_32 = true ;
}
V_18 = F_3 ( V_7 ) ;
if ( V_18 ) {
V_25 = F_23 ( V_7 , V_18 ) ;
if ( V_25 ) {
F_14 ( V_7 , L_13 ,
V_2 -> V_16 , V_25 ) ;
goto V_36;
}
}
F_24 ( V_2 -> V_34 ) ;
V_25 = F_25 ( V_7 ) ;
if ( V_25 <= 0 ) {
F_7 ( V_7 , L_14 ) ;
V_25 = - V_27 ;
goto V_37;
}
if ( V_32 ) {
F_26 ( V_2 -> V_34 ) ;
V_25 = F_27 ( V_7 , V_2 -> V_34 ) ;
if ( V_25 )
F_14 ( V_7 , L_15 ,
V_33 , V_25 ) ;
}
V_5 = F_28 ( sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 ) {
V_25 = - V_39 ;
goto V_37;
}
V_5 -> V_40 = V_18 ;
V_25 = F_29 ( V_7 , & V_8 ) ;
if ( V_25 ) {
F_14 ( V_7 , L_16 , V_25 ) ;
goto V_41;
}
V_5 -> V_7 = V_7 ;
V_2 -> V_6 = V_5 ;
V_2 -> V_23 = V_24 ;
F_30 () ;
V_30 = F_31 ( V_7 ) ;
if ( V_30 )
V_2 -> V_42 = F_32 ( V_30 ) / 1000 ;
F_33 () ;
V_25 = F_34 ( V_2 , V_8 ) ;
if ( V_25 ) {
F_14 ( V_7 , L_17 , V_33 ,
V_25 ) ;
goto V_43;
}
if ( F_35 ( V_2 ) ) {
V_25 = F_36 () ;
if ( V_25 )
goto V_43;
V_44 [ 1 ] = & V_45 ;
}
V_31 = F_37 ( V_7 ) ;
if ( ! V_31 )
V_31 = V_46 ;
V_2 -> V_47 . V_31 = V_31 ;
return 0 ;
V_43:
F_38 ( V_7 , & V_8 ) ;
V_41:
F_39 ( V_5 ) ;
V_37:
F_40 ( V_2 -> V_34 ) ;
if ( V_18 )
F_41 ( V_7 ) ;
V_36:
F_15 ( V_24 ) ;
return V_25 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_43 ( V_5 -> V_48 ) ;
F_38 ( V_5 -> V_7 , & V_2 -> V_8 ) ;
F_40 ( V_2 -> V_49 ) ;
if ( V_5 -> V_40 )
F_41 ( V_5 -> V_7 ) ;
F_15 ( V_2 -> V_23 ) ;
F_39 ( V_5 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_12 * V_13 = F_4 ( V_5 -> V_7 -> V_19 ) ;
if ( F_5 ( ! V_13 ) )
return;
if ( F_6 ( V_13 , L_18 , NULL ) ) {
T_1 V_50 = 0 ;
F_45 ( V_13 , L_19 ,
& V_50 ) ;
V_5 -> V_48 = F_46 ( V_13 ,
V_2 -> V_49 , V_50 , NULL ) ;
if ( F_19 ( V_5 -> V_48 ) ) {
F_14 ( V_5 -> V_7 ,
L_20 ,
F_20 ( V_5 -> V_48 ) ) ;
V_5 -> V_48 = NULL ;
}
}
F_8 ( V_13 ) ;
}
static int F_47 ( struct V_51 * V_52 )
{
int V_25 ;
V_25 = F_9 () ;
if ( V_25 )
return V_25 ;
V_53 . V_6 = F_48 ( & V_52 -> V_11 ) ;
V_25 = F_49 ( & V_53 ) ;
if ( V_25 )
F_14 ( & V_52 -> V_11 , L_21 , V_25 ) ;
return V_25 ;
}
static int F_50 ( struct V_51 * V_52 )
{
F_51 ( & V_53 ) ;
return 0 ;
}

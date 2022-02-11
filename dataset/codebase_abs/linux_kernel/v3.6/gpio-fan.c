static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( & V_4 -> V_6 -> V_7 . V_8 , NULL , L_1 ) ;
F_4 ( & V_4 -> V_6 -> V_7 . V_8 , V_9 ) ;
}
static T_1 F_5 ( int V_10 , void * V_11 )
{
struct V_3 * V_4 = V_11 ;
F_6 ( & V_4 -> V_5 ) ;
return V_12 ;
}
static T_2 F_7 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_17 * V_18 = V_4 -> V_18 ;
int V_19 = F_9 ( V_18 -> V_20 ) ;
if ( V_18 -> V_21 )
V_19 = ! V_19 ;
return sprintf ( V_16 , L_2 , V_19 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
int V_22 ;
int V_23 ;
struct V_24 * V_6 = V_4 -> V_6 ;
V_4 -> V_18 = V_18 ;
V_22 = F_11 ( & V_6 -> V_7 , V_18 -> V_20 , L_3 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_12 ( V_18 -> V_20 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_13 ( & V_6 -> V_7 , & V_25 ) ;
if ( V_22 )
return V_22 ;
V_23 = F_14 ( V_18 -> V_20 ) ;
if ( V_23 < 0 )
return 0 ;
F_15 ( & V_4 -> V_5 , F_1 ) ;
F_16 ( V_23 , V_26 ) ;
V_22 = F_17 ( & V_6 -> V_7 , V_23 , F_5 ,
V_27 , L_3 , V_4 ) ;
if ( V_22 )
goto V_28;
return 0 ;
V_28:
F_18 ( & V_6 -> V_7 , & V_25 ) ;
return V_22 ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_24 * V_6 = V_4 -> V_6 ;
F_18 ( & V_6 -> V_7 , & V_25 ) ;
}
static void F_20 ( struct V_3 * V_4 , int V_29 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_31 ; V_30 ++ )
F_21 ( V_4 -> V_32 [ V_30 ] , ( V_29 >> V_30 ) & 1 ) ;
}
static int F_22 ( struct V_3 * V_4 )
{
int V_30 ;
int V_29 = 0 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_31 ; V_30 ++ ) {
int V_19 ;
V_19 = F_9 ( V_4 -> V_32 [ V_30 ] ) ;
V_29 |= ( V_19 << V_30 ) ;
}
return V_29 ;
}
static void F_23 ( struct V_3 * V_4 , int V_33 )
{
if ( V_4 -> V_33 == V_33 )
return;
F_20 ( V_4 , V_4 -> V_34 [ V_33 ] . V_29 ) ;
V_4 -> V_33 = V_33 ;
}
static int F_24 ( struct V_3 * V_4 )
{
int V_29 = F_22 ( V_4 ) ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_35 ; V_30 ++ )
if ( V_4 -> V_34 [ V_30 ] . V_29 == V_29 )
return V_30 ;
F_25 ( & V_4 -> V_6 -> V_7 ,
L_4 , V_29 ) ;
return - V_36 ;
}
static int F_26 ( struct V_3 * V_4 , int V_37 )
{
struct V_38 * V_34 = V_4 -> V_34 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_4 -> V_35 ; V_30 ++ )
if ( V_34 [ V_30 ] . V_37 >= V_37 )
return V_30 ;
return V_4 -> V_35 - 1 ;
}
static T_2 F_27 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
T_3 V_39 = V_4 -> V_33 * 255 / ( V_4 -> V_35 - 1 ) ;
return sprintf ( V_16 , L_2 , V_39 ) ;
}
static T_2 F_28 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_40 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_39 ;
int V_33 ;
int V_41 = V_40 ;
if ( F_29 ( V_16 , 10 , & V_39 ) || V_39 > 255 )
return - V_36 ;
F_30 ( & V_4 -> V_42 ) ;
if ( ! V_4 -> V_43 ) {
V_41 = - V_44 ;
goto V_45;
}
V_33 = F_31 ( V_39 * ( V_4 -> V_35 - 1 ) , 255 ) ;
F_23 ( V_4 , V_33 ) ;
V_45:
F_32 ( & V_4 -> V_42 ) ;
return V_41 ;
}
static T_2 F_33 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_43 ) ;
}
static T_2 F_34 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_40 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_46 ;
if ( F_29 ( V_16 , 10 , & V_46 ) || V_46 > 1 )
return - V_36 ;
if ( V_4 -> V_43 == V_46 )
return V_40 ;
F_30 ( & V_4 -> V_42 ) ;
V_4 -> V_43 = V_46 ;
if ( V_46 == 0 )
F_23 ( V_4 , V_4 -> V_35 - 1 ) ;
F_32 ( & V_4 -> V_42 ) ;
return V_40 ;
}
static T_2 F_35 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
return sprintf ( V_16 , L_5 ) ;
}
static T_2 F_36 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_34 [ 0 ] . V_37 ) ;
}
static T_2 F_37 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 ,
V_4 -> V_34 [ V_4 -> V_35 - 1 ] . V_37 ) ;
}
static T_2 F_38 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_34 [ V_4 -> V_33 ] . V_37 ) ;
}
static T_2 F_39 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_40 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_37 ;
int V_41 = V_40 ;
if ( F_29 ( V_16 , 10 , & V_37 ) )
return - V_36 ;
F_30 ( & V_4 -> V_42 ) ;
if ( ! V_4 -> V_43 ) {
V_41 = - V_44 ;
goto V_45;
}
F_23 ( V_4 , F_26 ( V_4 , V_37 ) ) ;
V_45:
F_32 ( & V_4 -> V_42 ) ;
return V_41 ;
}
static int F_40 ( struct V_3 * V_4 ,
struct V_47 * V_48 )
{
struct V_24 * V_6 = V_4 -> V_6 ;
int V_31 = V_48 -> V_31 ;
unsigned * V_32 = V_48 -> V_32 ;
int V_30 , V_22 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_22 = F_11 ( & V_6 -> V_7 , V_32 [ V_30 ] ,
L_6 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_41 ( V_32 [ V_30 ] , F_9 ( V_32 [ V_30 ] ) ) ;
if ( V_22 )
return V_22 ;
}
V_4 -> V_31 = V_31 ;
V_4 -> V_32 = V_32 ;
V_4 -> V_35 = V_48 -> V_35 ;
V_4 -> V_34 = V_48 -> V_34 ;
V_4 -> V_43 = true ;
V_4 -> V_33 = F_24 ( V_4 ) ;
if ( V_4 -> V_33 < 0 )
return - V_49 ;
V_22 = F_42 ( & V_6 -> V_7 . V_8 , & V_50 ) ;
return V_22 ;
}
static void F_43 ( struct V_3 * V_4 )
{
struct V_24 * V_6 = V_4 -> V_6 ;
F_44 ( & V_6 -> V_7 . V_8 , & V_50 ) ;
}
static T_2 F_45 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
return sprintf ( V_16 , L_7 ) ;
}
static int T_5 F_46 ( struct V_24 * V_6 )
{
int V_22 ;
struct V_3 * V_4 ;
struct V_47 * V_48 = V_6 -> V_7 . V_51 ;
if ( ! V_48 )
return - V_36 ;
V_4 = F_47 ( & V_6 -> V_7 , sizeof( struct V_3 ) ,
V_52 ) ;
if ( ! V_4 )
return - V_53 ;
V_4 -> V_6 = V_6 ;
F_48 ( V_6 , V_4 ) ;
F_49 ( & V_4 -> V_42 ) ;
if ( V_48 -> V_18 ) {
V_22 = F_10 ( V_4 , V_48 -> V_18 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_48 -> V_32 && V_48 -> V_31 > 0 ) {
if ( ! V_48 -> V_34 || V_48 -> V_35 <= 1 ) {
V_22 = - V_36 ;
goto V_54;
}
V_22 = F_40 ( V_4 , V_48 ) ;
if ( V_22 )
goto V_54;
}
V_22 = F_13 ( & V_6 -> V_7 , & V_55 ) ;
if ( V_22 )
goto V_56;
V_4 -> V_57 = F_50 ( & V_6 -> V_7 ) ;
if ( F_51 ( V_4 -> V_57 ) ) {
V_22 = F_52 ( V_4 -> V_57 ) ;
goto V_58;
}
F_53 ( & V_6 -> V_7 , L_8 ) ;
return 0 ;
V_58:
F_18 ( & V_6 -> V_7 , & V_55 ) ;
V_56:
if ( V_4 -> V_32 )
F_43 ( V_4 ) ;
V_54:
if ( V_4 -> V_18 )
F_19 ( V_4 ) ;
return V_22 ;
}
static int T_6 F_54 ( struct V_24 * V_6 )
{
struct V_3 * V_4 = F_55 ( V_6 ) ;
F_56 ( V_4 -> V_57 ) ;
F_18 ( & V_6 -> V_7 , & V_55 ) ;
if ( V_4 -> V_18 )
F_19 ( V_4 ) ;
if ( V_4 -> V_32 )
F_43 ( V_4 ) ;
return 0 ;
}
static int F_57 ( struct V_13 * V_7 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
if ( V_4 -> V_32 ) {
V_4 -> V_59 = V_4 -> V_33 ;
F_23 ( V_4 , 0 ) ;
}
return 0 ;
}
static int F_58 ( struct V_13 * V_7 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
if ( V_4 -> V_32 )
F_23 ( V_4 , V_4 -> V_59 ) ;
return 0 ;
}

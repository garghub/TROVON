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
V_22 = F_11 ( V_18 -> V_20 , L_3 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_12 ( V_18 -> V_20 ) ;
if ( V_22 )
goto V_25;
V_22 = F_13 ( & V_6 -> V_7 , & V_26 ) ;
if ( V_22 )
goto V_25;
V_23 = F_14 ( V_18 -> V_20 ) ;
if ( V_23 < 0 )
return 0 ;
F_15 ( & V_4 -> V_5 , F_1 ) ;
F_16 ( V_23 , V_27 ) ;
V_22 = F_17 ( V_23 , F_5 , V_28 ,
L_3 , V_4 ) ;
if ( V_22 )
goto V_29;
return 0 ;
V_29:
F_18 ( & V_6 -> V_7 , & V_26 ) ;
V_25:
F_19 ( V_18 -> V_20 ) ;
return V_22 ;
}
static void F_20 ( struct V_3 * V_4 )
{
struct V_24 * V_6 = V_4 -> V_6 ;
int V_23 = F_14 ( V_4 -> V_18 -> V_20 ) ;
if ( V_23 >= 0 )
F_21 ( V_23 , V_4 ) ;
F_18 ( & V_6 -> V_7 , & V_26 ) ;
F_19 ( V_4 -> V_18 -> V_20 ) ;
}
static void F_22 ( struct V_3 * V_4 , int V_30 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_4 -> V_32 ; V_31 ++ )
F_23 ( V_4 -> V_33 [ V_31 ] , ( V_30 >> V_31 ) & 1 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
int V_31 ;
int V_30 = 0 ;
for ( V_31 = 0 ; V_31 < V_4 -> V_32 ; V_31 ++ ) {
int V_19 ;
V_19 = F_9 ( V_4 -> V_33 [ V_31 ] ) ;
V_30 |= ( V_19 << V_31 ) ;
}
return V_30 ;
}
static void F_25 ( struct V_3 * V_4 , int V_34 )
{
if ( V_4 -> V_34 == V_34 )
return;
F_22 ( V_4 , V_4 -> V_35 [ V_34 ] . V_30 ) ;
V_4 -> V_34 = V_34 ;
}
static int F_26 ( struct V_3 * V_4 )
{
int V_30 = F_24 ( V_4 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_4 -> V_36 ; V_31 ++ )
if ( V_4 -> V_35 [ V_31 ] . V_30 == V_30 )
return V_31 ;
F_27 ( & V_4 -> V_6 -> V_7 ,
L_4 , V_30 ) ;
return - V_37 ;
}
static int F_28 ( struct V_3 * V_4 , int V_38 )
{
struct V_39 * V_35 = V_4 -> V_35 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_4 -> V_36 ; V_31 ++ )
if ( V_35 [ V_31 ] . V_38 >= V_38 )
return V_31 ;
return V_4 -> V_36 - 1 ;
}
static T_2 F_29 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
T_3 V_40 = V_4 -> V_34 * 255 / ( V_4 -> V_36 - 1 ) ;
return sprintf ( V_16 , L_2 , V_40 ) ;
}
static T_2 F_30 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_41 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_40 ;
int V_34 ;
int V_42 = V_41 ;
if ( F_31 ( V_16 , 10 , & V_40 ) || V_40 > 255 )
return - V_37 ;
F_32 ( & V_4 -> V_43 ) ;
if ( ! V_4 -> V_44 ) {
V_42 = - V_45 ;
goto V_46;
}
V_34 = F_33 ( V_40 * ( V_4 -> V_36 - 1 ) , 255 ) ;
F_25 ( V_4 , V_34 ) ;
V_46:
F_34 ( & V_4 -> V_43 ) ;
return V_42 ;
}
static T_2 F_35 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_44 ) ;
}
static T_2 F_36 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_41 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_47 ;
if ( F_31 ( V_16 , 10 , & V_47 ) || V_47 > 1 )
return - V_37 ;
if ( V_4 -> V_44 == V_47 )
return V_41 ;
F_32 ( & V_4 -> V_43 ) ;
V_4 -> V_44 = V_47 ;
if ( V_47 == 0 )
F_25 ( V_4 , V_4 -> V_36 - 1 ) ;
F_34 ( & V_4 -> V_43 ) ;
return V_41 ;
}
static T_2 F_37 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
return sprintf ( V_16 , L_5 ) ;
}
static T_2 F_38 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_35 [ 0 ] . V_38 ) ;
}
static T_2 F_39 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 ,
V_4 -> V_35 [ V_4 -> V_36 - 1 ] . V_38 ) ;
}
static T_2 F_40 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_35 [ V_4 -> V_34 ] . V_38 ) ;
}
static T_2 F_41 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_41 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_38 ;
int V_42 = V_41 ;
if ( F_31 ( V_16 , 10 , & V_38 ) )
return - V_37 ;
F_32 ( & V_4 -> V_43 ) ;
if ( ! V_4 -> V_44 ) {
V_42 = - V_45 ;
goto V_46;
}
F_25 ( V_4 , F_28 ( V_4 , V_38 ) ) ;
V_46:
F_34 ( & V_4 -> V_43 ) ;
return V_42 ;
}
static int F_42 ( struct V_3 * V_4 ,
struct V_48 * V_49 )
{
struct V_24 * V_6 = V_4 -> V_6 ;
int V_32 = V_49 -> V_32 ;
unsigned * V_33 = V_49 -> V_33 ;
int V_31 , V_22 ;
for ( V_31 = 0 ; V_31 < V_32 ; V_31 ++ ) {
V_22 = F_11 ( V_33 [ V_31 ] , L_6 ) ;
if ( V_22 )
goto V_25;
V_22 = F_43 ( V_33 [ V_31 ] , F_9 ( V_33 [ V_31 ] ) ) ;
if ( V_22 ) {
F_19 ( V_33 [ V_31 ] ) ;
goto V_25;
}
}
V_4 -> V_32 = V_32 ;
V_4 -> V_33 = V_33 ;
V_4 -> V_36 = V_49 -> V_36 ;
V_4 -> V_35 = V_49 -> V_35 ;
V_4 -> V_44 = true ;
V_4 -> V_34 = F_26 ( V_4 ) ;
if ( V_4 -> V_34 < 0 ) {
V_22 = - V_50 ;
goto V_25;
}
V_22 = F_44 ( & V_6 -> V_7 . V_8 , & V_51 ) ;
if ( V_22 )
goto V_25;
return 0 ;
V_25:
for ( V_31 = V_31 - 1 ; V_31 >= 0 ; V_31 -- )
F_19 ( V_33 [ V_31 ] ) ;
return V_22 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_24 * V_6 = V_4 -> V_6 ;
int V_31 ;
F_46 ( & V_6 -> V_7 . V_8 , & V_51 ) ;
for ( V_31 = 0 ; V_31 < V_4 -> V_32 ; V_31 ++ )
F_19 ( V_4 -> V_33 [ V_31 ] ) ;
}
static T_2 F_47 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
return sprintf ( V_16 , L_7 ) ;
}
static int T_5 F_48 ( struct V_24 * V_6 )
{
int V_22 ;
struct V_3 * V_4 ;
struct V_48 * V_49 = V_6 -> V_7 . V_52 ;
if ( ! V_49 )
return - V_37 ;
V_4 = F_49 ( sizeof( struct V_3 ) , V_53 ) ;
if ( ! V_4 )
return - V_54 ;
V_4 -> V_6 = V_6 ;
F_50 ( V_6 , V_4 ) ;
F_51 ( & V_4 -> V_43 ) ;
if ( V_49 -> V_18 ) {
V_22 = F_10 ( V_4 , V_49 -> V_18 ) ;
if ( V_22 )
goto V_55;
}
if ( V_49 -> V_33 && V_49 -> V_32 > 0 ) {
if ( ! V_49 -> V_35 || V_49 -> V_36 <= 1 ) {
V_22 = - V_37 ;
goto V_56;
}
V_22 = F_42 ( V_4 , V_49 ) ;
if ( V_22 )
goto V_56;
}
V_22 = F_13 ( & V_6 -> V_7 , & V_57 ) ;
if ( V_22 )
goto V_58;
V_4 -> V_59 = F_52 ( & V_6 -> V_7 ) ;
if ( F_53 ( V_4 -> V_59 ) ) {
V_22 = F_54 ( V_4 -> V_59 ) ;
goto V_60;
}
F_55 ( & V_6 -> V_7 , L_8 ) ;
return 0 ;
V_60:
F_18 ( & V_6 -> V_7 , & V_57 ) ;
V_58:
if ( V_4 -> V_33 )
F_45 ( V_4 ) ;
V_56:
if ( V_4 -> V_18 )
F_20 ( V_4 ) ;
V_55:
F_50 ( V_6 , NULL ) ;
F_56 ( V_4 ) ;
return V_22 ;
}
static int T_6 F_57 ( struct V_24 * V_6 )
{
struct V_3 * V_4 = F_58 ( V_6 ) ;
F_59 ( V_4 -> V_59 ) ;
F_18 ( & V_6 -> V_7 , & V_57 ) ;
if ( V_4 -> V_18 )
F_20 ( V_4 ) ;
if ( V_4 -> V_33 )
F_45 ( V_4 ) ;
F_56 ( V_4 ) ;
return 0 ;
}
static int F_60 ( struct V_24 * V_6 , T_7 V_61 )
{
struct V_3 * V_4 = F_58 ( V_6 ) ;
if ( V_4 -> V_33 ) {
V_4 -> V_62 = V_4 -> V_34 ;
F_25 ( V_4 , 0 ) ;
}
return 0 ;
}
static int F_61 ( struct V_24 * V_6 )
{
struct V_3 * V_4 = F_58 ( V_6 ) ;
if ( V_4 -> V_33 )
F_25 ( V_4 , V_4 -> V_62 ) ;
return 0 ;
}

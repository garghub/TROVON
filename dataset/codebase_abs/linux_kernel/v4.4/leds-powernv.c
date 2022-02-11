static int F_1 ( const char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( ! strcmp ( V_3 [ V_2 ] . V_4 , V_1 ) )
return V_3 [ V_2 ] . type ;
return - 1 ;
}
static void F_3 ( struct V_5 * V_6 ,
enum V_7 V_8 )
{
int V_9 , V_10 ;
T_1 V_11 , V_12 = 0 ;
T_2 V_13 ;
struct V_14 V_15 ;
struct V_16 * V_17 = V_6 -> V_18 . V_17 ;
struct V_19 * V_19 = V_6 -> V_20 ;
V_13 = V_19 -> V_21 ;
V_11 = V_22 << V_6 -> V_23 ;
if ( V_8 )
V_12 = V_11 ;
V_10 = F_4 () ;
if ( V_10 < 0 ) {
if ( V_10 != - V_24 )
F_5 ( V_17 , L_1 ,
V_25 ) ;
return;
}
V_9 = F_6 ( V_10 , V_6 -> V_26 ,
V_11 , V_12 , & V_13 ) ;
if ( V_9 != V_27 ) {
F_5 ( V_17 , L_2 ,
V_25 , V_6 -> V_26 , V_9 ) ;
goto V_28;
}
V_9 = F_7 ( V_10 , & V_15 ) ;
if ( V_9 ) {
F_5 ( V_17 ,
L_3 ,
V_25 , V_9 ) ;
goto V_28;
}
V_9 = F_8 ( V_15 . V_29 [ 1 ] ) ;
if ( V_9 != V_30 )
F_5 ( V_17 , L_4 ,
V_25 , V_9 ) ;
V_28:
F_9 ( V_10 ) ;
}
static enum V_7 F_10 ( struct V_5 * V_6 )
{
int V_9 ;
T_2 V_31 , V_8 , V_13 ;
T_1 V_11 , V_12 ;
struct V_16 * V_17 = V_6 -> V_18 . V_17 ;
struct V_19 * V_19 = V_6 -> V_20 ;
V_31 = F_11 ( 0 ) ;
V_8 = F_11 ( 0 ) ;
V_13 = V_19 -> V_21 ;
V_9 = F_12 ( V_6 -> V_26 ,
& V_31 , & V_8 , & V_13 ) ;
if ( V_9 != V_30 && V_9 != V_32 ) {
F_5 ( V_17 , L_5 ,
V_25 , V_9 ) ;
return V_33 ;
}
V_11 = F_8 ( V_31 ) ;
V_12 = F_8 ( V_8 ) ;
if ( ! ( ( V_11 >> V_6 -> V_23 ) & V_22 ) ) {
F_5 ( V_17 , L_6 ,
V_25 , V_6 -> V_18 . V_34 ) ;
return V_33 ;
}
if ( ( V_12 >> V_6 -> V_23 ) & V_22 )
return V_35 ;
return V_33 ;
}
static void F_13 ( struct V_36 * V_37 ,
enum V_7 V_8 )
{
struct V_5 * V_6 =
F_14 ( V_37 , struct V_5 , V_18 ) ;
struct V_19 * V_19 = V_6 -> V_20 ;
if ( V_19 -> V_38 )
return;
F_15 ( & V_19 -> V_39 ) ;
F_3 ( V_6 , V_8 ) ;
F_16 ( & V_19 -> V_39 ) ;
}
static enum V_7 F_17 ( struct V_36 * V_37 )
{
struct V_5 * V_6 =
F_14 ( V_37 , struct V_5 , V_18 ) ;
return F_10 ( V_6 ) ;
}
static int F_18 ( struct V_16 * V_17 ,
struct V_5 * V_6 ,
const char * V_1 )
{
int V_9 ;
V_6 -> V_23 = F_1 ( V_1 ) ;
if ( V_6 -> V_23 == - 1 ) {
F_19 ( V_17 , L_7 ,
V_25 , V_1 ) ;
return - V_40 ;
}
V_6 -> V_18 . V_34 = F_20 ( V_17 , V_41 , L_8 ,
V_6 -> V_26 ,
V_1 ) ;
if ( ! V_6 -> V_18 . V_34 ) {
F_5 ( V_17 ,
L_9 ,
V_25 ) ;
return - V_42 ;
}
V_6 -> V_18 . V_43 = F_13 ;
V_6 -> V_18 . V_44 = F_17 ;
V_6 -> V_18 . V_45 = V_33 ;
V_6 -> V_18 . V_46 = V_35 ;
V_9 = F_21 ( V_17 , & V_6 -> V_18 ) ;
if ( V_9 ) {
F_5 ( V_17 , L_10 ,
V_25 , V_6 -> V_18 . V_34 ) ;
}
return V_9 ;
}
static int F_22 ( struct V_47 * V_48 ,
struct V_49 * V_50 ,
struct V_19 * V_19 )
{
const char * V_51 = NULL ;
int V_9 = - 1 ;
struct V_52 * V_53 ;
struct V_49 * V_54 ;
struct V_5 * V_6 ;
struct V_16 * V_17 = & V_48 -> V_17 ;
F_23 (led_node, np) {
V_53 = F_24 ( V_54 , L_11 , NULL ) ;
if ( ! V_53 )
continue;
while ( ( V_51 = F_25 ( V_53 , V_51 ) ) != NULL ) {
V_6 = F_26 ( V_17 , sizeof( * V_6 ) ,
V_41 ) ;
if ( ! V_6 ) {
F_27 ( V_54 ) ;
return - V_42 ;
}
V_6 -> V_20 = V_19 ;
V_6 -> V_26 = ( char * ) V_54 -> V_34 ;
V_9 = F_18 ( V_17 , V_6 , V_51 ) ;
if ( V_9 ) {
F_27 ( V_54 ) ;
return V_9 ;
}
}
}
return V_9 ;
}
static int F_28 ( struct V_47 * V_48 )
{
struct V_49 * V_50 ;
struct V_19 * V_19 ;
struct V_16 * V_17 = & V_48 -> V_17 ;
V_50 = F_29 ( L_12 ) ;
if ( ! V_50 ) {
F_5 ( V_17 , L_13 ,
V_25 ) ;
return - V_40 ;
}
V_19 = F_26 ( V_17 , sizeof( * V_19 ) ,
V_41 ) ;
if ( ! V_19 )
return - V_42 ;
F_30 ( & V_19 -> V_39 ) ;
V_19 -> V_21 = F_11 ( V_55 ) ;
F_31 ( V_48 , V_19 ) ;
return F_22 ( V_48 , V_50 , V_19 ) ;
}
static int F_32 ( struct V_47 * V_48 )
{
struct V_19 * V_19 ;
V_19 = F_33 ( V_48 ) ;
V_19 -> V_38 = true ;
F_34 ( & V_19 -> V_39 ) ;
F_35 ( & V_48 -> V_17 , L_14 ) ;
return 0 ;
}

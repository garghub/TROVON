static int F_1 ( const char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( ! strcmp ( V_3 [ V_2 ] . V_4 , V_1 ) )
return V_3 [ V_2 ] . type ;
return - 1 ;
}
static int F_3 ( struct V_5 * V_6 ,
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
return V_10 ;
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
V_9 = F_8 ( V_15 ) ;
if ( V_9 != V_29 )
F_5 ( V_17 , L_4 ,
V_25 , V_9 ) ;
V_28:
F_9 ( V_10 ) ;
return V_9 ;
}
static enum V_7 F_10 ( struct V_5 * V_6 )
{
int V_9 ;
T_2 V_30 , V_8 , V_13 ;
T_1 V_11 , V_12 ;
struct V_16 * V_17 = V_6 -> V_18 . V_17 ;
struct V_19 * V_19 = V_6 -> V_20 ;
V_30 = F_11 ( 0 ) ;
V_8 = F_11 ( 0 ) ;
V_13 = V_19 -> V_21 ;
V_9 = F_12 ( V_6 -> V_26 ,
& V_30 , & V_8 , & V_13 ) ;
if ( V_9 != V_29 && V_9 != V_31 ) {
F_5 ( V_17 , L_5 ,
V_25 , V_9 ) ;
return V_32 ;
}
V_11 = F_13 ( V_30 ) ;
V_12 = F_13 ( V_8 ) ;
if ( ! ( ( V_11 >> V_6 -> V_23 ) & V_22 ) ) {
F_5 ( V_17 , L_6 ,
V_25 , V_6 -> V_18 . V_33 ) ;
return V_32 ;
}
if ( ( V_12 >> V_6 -> V_23 ) & V_22 )
return V_34 ;
return V_32 ;
}
static int F_14 ( struct V_35 * V_36 ,
enum V_7 V_8 )
{
struct V_5 * V_6 =
F_15 ( V_36 , struct V_5 , V_18 ) ;
struct V_19 * V_19 = V_6 -> V_20 ;
int V_9 ;
if ( V_19 -> V_37 )
return 0 ;
F_16 ( & V_19 -> V_38 ) ;
V_9 = F_3 ( V_6 , V_8 ) ;
F_17 ( & V_19 -> V_38 ) ;
return V_9 ;
}
static enum V_7 F_18 ( struct V_35 * V_36 )
{
struct V_5 * V_6 =
F_15 ( V_36 , struct V_5 , V_18 ) ;
return F_10 ( V_6 ) ;
}
static int F_19 ( struct V_16 * V_17 ,
struct V_5 * V_6 ,
const char * V_1 )
{
int V_9 ;
V_6 -> V_23 = F_1 ( V_1 ) ;
if ( V_6 -> V_23 == - 1 ) {
F_20 ( V_17 , L_7 ,
V_25 , V_1 ) ;
return - V_39 ;
}
V_6 -> V_18 . V_33 = F_21 ( V_17 , V_40 , L_8 ,
V_6 -> V_26 ,
V_1 ) ;
if ( ! V_6 -> V_18 . V_33 )
return - V_41 ;
V_6 -> V_18 . V_42 = F_14 ;
V_6 -> V_18 . V_43 = F_18 ;
V_6 -> V_18 . V_44 = V_32 ;
V_6 -> V_18 . V_45 = V_34 ;
V_9 = F_22 ( V_17 , & V_6 -> V_18 ) ;
if ( V_9 ) {
F_5 ( V_17 , L_9 ,
V_25 , V_6 -> V_18 . V_33 ) ;
}
return V_9 ;
}
static int F_23 ( struct V_46 * V_47 ,
struct V_48 * V_49 ,
struct V_19 * V_19 )
{
const char * V_50 = NULL ;
int V_9 = - 1 ;
struct V_51 * V_52 ;
struct V_48 * V_53 ;
struct V_5 * V_6 ;
struct V_16 * V_17 = & V_47 -> V_17 ;
F_24 (led_node, np) {
V_52 = F_25 ( V_53 , L_10 , NULL ) ;
while ( ( V_50 = F_26 ( V_52 , V_50 ) ) != NULL ) {
V_6 = F_27 ( V_17 , sizeof( * V_6 ) ,
V_40 ) ;
if ( ! V_6 ) {
F_28 ( V_53 ) ;
return - V_41 ;
}
V_6 -> V_20 = V_19 ;
V_6 -> V_26 = ( char * ) V_53 -> V_33 ;
V_9 = F_19 ( V_17 , V_6 , V_50 ) ;
if ( V_9 ) {
F_28 ( V_53 ) ;
return V_9 ;
}
}
}
return V_9 ;
}
static int F_29 ( struct V_46 * V_47 )
{
struct V_48 * V_49 ;
struct V_19 * V_19 ;
struct V_16 * V_17 = & V_47 -> V_17 ;
V_49 = F_30 ( L_11 ) ;
if ( ! V_49 ) {
F_5 ( V_17 , L_12 ,
V_25 ) ;
return - V_39 ;
}
V_19 = F_27 ( V_17 , sizeof( * V_19 ) ,
V_40 ) ;
if ( ! V_19 )
return - V_41 ;
F_31 ( & V_19 -> V_38 ) ;
V_19 -> V_21 = F_11 ( V_54 ) ;
F_32 ( V_47 , V_19 ) ;
return F_23 ( V_47 , V_49 , V_19 ) ;
}
static int F_33 ( struct V_46 * V_47 )
{
struct V_19 * V_19 ;
V_19 = F_34 ( V_47 ) ;
V_19 -> V_37 = true ;
F_35 ( & V_19 -> V_38 ) ;
F_36 ( & V_47 -> V_17 , L_13 ) ;
return 0 ;
}

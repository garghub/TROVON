static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
if ( V_10 -> V_11 ( V_6 , V_10 -> V_12 ) ) {
F_3 ( V_8 , L_1 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_9 * V_10 = F_2 ( V_8 ) ;
if ( V_10 -> V_14 ( V_6 , V_10 -> V_12 ) ) {
F_3 ( V_8 , L_2 ) ;
return - V_13 ;
}
return 0 ;
}
static void * F_5 ( struct V_1 * V_1 , T_1 V_15 , int V_16 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
void * V_17 = NULL ;
int V_18 ;
T_2 V_19 ;
if ( V_16 <= 0 )
return NULL ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ ) {
if ( V_15 >= V_3 -> V_21 [ V_18 ] . V_22 && V_15 + V_16 <=
V_3 -> V_21 [ V_18 ] . V_22 + V_3 -> V_21 [ V_18 ] . V_23 ) {
V_19 = V_15 - V_3 -> V_21 [ V_18 ] . V_22 ;
V_17 = ( V_24 void * ) ( V_3 -> V_21 [ V_18 ] . V_25 + V_19 ) ;
break;
}
}
return V_17 ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_9 * V_10 = V_8 -> V_26 ;
const char * V_27 [ V_20 ] = { L_3 , L_4 } ;
struct V_2 * V_3 ;
const char * V_28 ;
struct V_1 * V_1 ;
struct V_29 * V_30 ;
const T_3 * V_31 ;
T_2 V_32 = 0 ;
T_1 V_23 ;
int V_33 ;
int V_18 ;
if ( ! ( V_10 && V_10 -> V_11 && V_10 -> V_14 &&
V_10 -> V_12 ) ) {
F_3 ( V_8 , L_5 ) ;
return - V_13 ;
}
V_33 = F_7 ( V_8 -> V_34 , L_6 ,
& V_28 ) ;
if ( V_33 ) {
F_3 ( V_8 , L_7 ) ;
return - V_13 ;
}
F_8 ( & V_6 -> V_8 ) ;
V_33 = F_9 ( & V_6 -> V_8 ) ;
if ( V_33 < 0 ) {
F_3 ( & V_6 -> V_8 , L_8 ) ;
goto V_35;
}
V_1 = F_10 ( V_8 , L_9 , & V_36 ,
V_28 , sizeof( * V_3 ) ) ;
if ( ! V_1 ) {
V_33 = - V_37 ;
goto V_35;
}
V_1 -> V_38 = false ;
V_3 = V_1 -> V_4 ;
V_3 -> V_1 = V_1 ;
V_3 -> V_6 = V_6 ;
for ( V_18 = 0 ; V_18 < F_11 ( V_27 ) ; V_18 ++ ) {
V_30 = F_12 ( V_6 , V_39 ,
V_27 [ V_18 ] ) ;
V_3 -> V_21 [ V_18 ] . V_25 = F_13 ( V_8 , V_30 ) ;
if ( F_14 ( V_3 -> V_21 [ V_18 ] . V_25 ) ) {
F_3 ( & V_6 -> V_8 , L_10 ,
V_18 ) ;
V_33 = F_15 ( V_3 -> V_21 [ V_18 ] . V_25 ) ;
goto V_35;
}
V_3 -> V_21 [ V_18 ] . V_40 = V_30 -> V_41 ;
V_3 -> V_21 [ V_18 ] . V_23 = F_16 ( V_30 ) ;
V_31 = F_17 ( V_8 -> V_34 , V_18 , & V_23 , NULL ) ;
if ( ! strcmp ( V_27 [ V_18 ] , L_3 ) )
V_32 = F_18 ( * V_31 ) ;
V_3 -> V_21 [ V_18 ] . V_22 = F_18 ( * V_31 ) - V_32 ;
}
F_19 ( V_8 , V_1 ) ;
V_33 = F_20 ( V_1 ) ;
if ( V_33 ) {
F_3 ( V_8 , L_11 ) ;
goto V_42;
}
return 0 ;
V_42:
F_21 ( V_1 ) ;
V_35:
F_22 ( V_8 ) ;
F_23 ( V_8 ) ;
return V_33 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_1 = F_25 ( V_6 ) ;
F_26 ( V_1 ) ;
F_21 ( V_1 ) ;
F_27 ( & V_6 -> V_8 ) ;
F_23 ( & V_6 -> V_8 ) ;
return 0 ;
}
static int F_28 ( struct V_7 * V_8 )
{
return - V_43 ;
}
static int F_29 ( struct V_7 * V_8 )
{
return 0 ;
}

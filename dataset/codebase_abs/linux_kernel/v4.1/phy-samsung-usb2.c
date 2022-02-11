static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 ;
F_3 ( V_5 -> V_7 , L_1 ,
V_3 -> V_8 -> V_9 ) ;
V_6 = F_4 ( V_5 -> V_10 ) ;
if ( V_6 )
goto V_11;
V_6 = F_4 ( V_5 -> V_12 ) ;
if ( V_6 )
goto V_13;
if ( V_3 -> V_8 -> V_14 ) {
F_5 ( & V_5 -> V_15 ) ;
V_6 = V_3 -> V_8 -> V_14 ( V_3 ) ;
F_6 ( & V_5 -> V_15 ) ;
if ( V_6 )
goto V_16;
}
return 0 ;
V_16:
F_7 ( V_5 -> V_12 ) ;
V_13:
F_7 ( V_5 -> V_10 ) ;
V_11:
return V_6 ;
}
static int F_8 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
int V_6 ;
F_3 ( V_5 -> V_7 , L_2 ,
V_3 -> V_8 -> V_9 ) ;
if ( V_3 -> V_8 -> V_17 ) {
F_5 ( & V_5 -> V_15 ) ;
V_6 = V_3 -> V_8 -> V_17 ( V_3 ) ;
F_6 ( & V_5 -> V_15 ) ;
if ( V_6 )
return V_6 ;
}
F_7 ( V_5 -> V_12 ) ;
F_7 ( V_5 -> V_10 ) ;
return 0 ;
}
static struct V_1 * F_9 ( struct V_18 * V_7 ,
struct V_19 * args )
{
struct V_4 * V_5 ;
V_5 = F_10 ( V_7 ) ;
if ( ! V_5 )
return F_11 ( - V_20 ) ;
if ( F_12 ( args -> args [ 0 ] >= V_5 -> V_8 -> V_21 ) )
return F_11 ( - V_22 ) ;
return V_5 -> V_23 [ args -> args [ 0 ] ] . V_1 ;
}
static int F_13 ( struct V_24 * V_25 )
{
const struct V_26 * V_27 ;
const struct V_28 * V_8 ;
struct V_18 * V_7 = & V_25 -> V_7 ;
struct V_29 * V_29 ;
struct V_30 * V_31 ;
struct V_4 * V_5 ;
int V_32 , V_6 ;
if ( ! V_25 -> V_7 . V_33 ) {
F_14 ( V_7 , L_3 ) ;
return - V_20 ;
}
V_27 = F_15 ( V_34 , V_25 -> V_7 . V_33 ) ;
if ( ! V_27 ) {
F_14 ( V_7 , L_4 ) ;
return - V_20 ;
}
V_8 = V_27 -> V_35 ;
V_5 = F_16 ( V_7 , sizeof( struct V_4 ) +
V_8 -> V_21 * sizeof( struct V_2 ) ,
V_36 ) ;
if ( ! V_5 )
return - V_37 ;
F_17 ( V_7 , V_5 ) ;
F_18 ( & V_5 -> V_15 ) ;
V_5 -> V_8 = V_8 ;
V_5 -> V_7 = V_7 ;
V_31 = F_19 ( V_25 , V_38 , 0 ) ;
V_5 -> V_39 = F_20 ( V_7 , V_31 ) ;
if ( F_21 ( V_5 -> V_39 ) ) {
F_14 ( V_7 , L_5 ) ;
return F_22 ( V_5 -> V_39 ) ;
}
V_5 -> V_40 = F_23 ( V_25 -> V_7 . V_33 ,
L_6 ) ;
if ( F_21 ( V_5 -> V_40 ) ) {
F_14 ( V_7 , L_7 ) ;
return F_22 ( V_5 -> V_40 ) ;
}
if ( V_5 -> V_8 -> V_41 ) {
V_5 -> V_42 = F_23 (
V_25 -> V_7 . V_33 , L_8 ) ;
if ( F_21 ( V_5 -> V_42 ) ) {
F_14 ( V_7 , L_9 ) ;
return F_22 ( V_5 -> V_42 ) ;
}
}
V_5 -> V_10 = F_24 ( V_7 , L_10 ) ;
if ( F_21 ( V_5 -> V_10 ) ) {
F_14 ( V_7 , L_11 ) ;
return F_22 ( V_5 -> V_10 ) ;
}
V_5 -> V_12 = F_24 ( V_7 , L_12 ) ;
if ( F_21 ( V_5 -> V_12 ) ) {
F_14 ( V_7 , L_13 ) ;
return F_22 ( V_5 -> V_12 ) ;
}
V_5 -> V_43 = F_25 ( V_5 -> V_12 ) ;
if ( V_5 -> V_8 -> V_44 ) {
V_6 = V_5 -> V_8 -> V_44 ( V_5 -> V_43 , & V_5 -> V_45 ) ;
if ( V_6 )
return V_6 ;
}
for ( V_32 = 0 ; V_32 < V_5 -> V_8 -> V_21 ; V_32 ++ ) {
char * V_9 = V_5 -> V_8 -> V_46 [ V_32 ] . V_9 ;
struct V_2 * V_47 = & V_5 -> V_23 [ V_32 ] ;
F_3 ( V_7 , L_14 , V_9 ) ;
V_47 -> V_1 = F_26 ( V_7 , NULL , & V_48 ) ;
if ( F_21 ( V_47 -> V_1 ) ) {
F_14 ( V_5 -> V_7 , L_15 ,
V_9 ) ;
return F_22 ( V_47 -> V_1 ) ;
}
V_47 -> V_8 = & V_5 -> V_8 -> V_46 [ V_32 ] ;
V_47 -> V_5 = V_5 ;
F_27 ( V_47 -> V_1 , 8 ) ;
F_28 ( V_47 -> V_1 , V_47 ) ;
}
V_29 = F_29 ( V_7 ,
F_9 ) ;
if ( F_21 ( V_29 ) ) {
F_14 ( V_5 -> V_7 , L_16 ) ;
return F_22 ( V_29 ) ;
}
return 0 ;
}

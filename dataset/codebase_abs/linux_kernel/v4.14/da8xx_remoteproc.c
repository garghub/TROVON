static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 ;
F_2 ( V_3 , 0 ) ;
F_2 ( V_3 , 1 ) ;
return V_4 ;
}
static T_1 F_3 ( int V_1 , void * V_2 )
{
struct V_3 * V_3 = (struct V_3 * ) V_2 ;
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
T_2 V_8 ;
V_8 = F_4 ( V_6 -> V_8 ) ;
if ( V_8 & V_9 ) {
F_5 ( V_9 , V_6 -> V_8 + 4 ) ;
V_6 -> V_10 ( V_6 -> V_11 ) ;
return V_12 ;
}
return V_4 ;
}
static int F_6 ( struct V_3 * V_3 )
{
struct V_13 * V_14 = V_3 -> V_14 . V_15 ;
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_16 * V_17 = V_6 -> V_17 ;
if ( V_3 -> V_18 & 0x3ff ) {
F_7 ( V_14 , L_1 ) ;
return - V_19 ;
}
F_5 ( V_3 -> V_18 , V_6 -> V_20 ) ;
F_8 ( V_17 ) ;
F_9 ( V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_3 )
{
struct V_5 * V_6 = V_3 -> V_7 ;
F_11 ( V_6 -> V_17 ) ;
F_12 ( V_6 -> V_17 ) ;
return 0 ;
}
static void F_13 ( struct V_3 * V_3 , int V_21 )
{
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
F_5 ( V_22 , V_6 -> V_8 ) ;
}
static int F_14 ( struct V_23 * V_24 ,
struct V_5 * V_6 )
{
static const char * const V_25 [] = { L_2 , L_3 , L_4 } ;
int V_26 = F_15 ( V_25 ) ;
struct V_13 * V_14 = & V_24 -> V_14 ;
struct V_27 * V_28 ;
int V_29 ;
V_6 -> V_30 = F_16 ( V_14 , V_26 , sizeof( * V_6 -> V_30 ) ,
V_31 ) ;
if ( ! V_6 -> V_30 )
return - V_32 ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ ) {
V_28 = F_17 ( V_24 , V_33 ,
V_25 [ V_29 ] ) ;
V_6 -> V_30 [ V_29 ] . V_34 = F_18 ( V_14 , V_28 ) ;
if ( F_19 ( V_6 -> V_30 [ V_29 ] . V_34 ) ) {
F_7 ( V_14 , L_5 ,
V_25 [ V_29 ] ) ;
return F_20 ( V_6 -> V_30 [ V_29 ] . V_34 ) ;
}
V_6 -> V_30 [ V_29 ] . V_35 = V_28 -> V_36 ;
V_6 -> V_30 [ V_29 ] . V_37 =
V_28 -> V_36 & V_38 ;
V_6 -> V_30 [ V_29 ] . V_39 = F_21 ( V_28 ) ;
F_22 ( V_14 , L_6 ,
V_25 [ V_29 ] , & V_6 -> V_30 [ V_29 ] . V_35 ,
V_6 -> V_30 [ V_29 ] . V_39 , V_6 -> V_30 [ V_29 ] . V_34 ,
V_6 -> V_30 [ V_29 ] . V_37 ) ;
}
V_6 -> V_26 = V_26 ;
return 0 ;
}
static int F_23 ( struct V_23 * V_24 )
{
struct V_13 * V_14 = & V_24 -> V_14 ;
struct V_5 * V_6 ;
struct V_3 * V_3 ;
struct V_11 * V_11 ;
struct V_27 * V_40 ;
struct V_27 * V_41 ;
struct V_16 * V_17 ;
void T_3 * V_8 ;
void T_3 * V_20 ;
int V_1 ;
int V_42 ;
V_1 = F_24 ( V_24 , 0 ) ;
if ( V_1 < 0 ) {
F_7 ( V_14 , L_7 , V_1 ) ;
return V_1 ;
}
V_11 = F_25 ( V_1 ) ;
if ( ! V_11 ) {
F_7 ( V_14 , L_8 , V_1 ) ;
return - V_19 ;
}
V_40 = F_17 ( V_24 , V_33 ,
L_9 ) ;
V_20 = F_18 ( V_14 , V_40 ) ;
if ( F_19 ( V_20 ) )
return F_20 ( V_20 ) ;
V_41 = F_17 ( V_24 , V_33 ,
L_10 ) ;
V_8 = F_18 ( V_14 , V_41 ) ;
if ( F_19 ( V_8 ) )
return F_20 ( V_8 ) ;
V_17 = F_26 ( V_14 , NULL ) ;
if ( F_19 ( V_17 ) ) {
F_7 ( V_14 , L_11 , F_20 ( V_17 ) ) ;
return F_20 ( V_17 ) ;
}
if ( V_14 -> V_43 ) {
V_42 = F_27 ( V_14 ) ;
if ( V_42 ) {
F_7 ( V_14 , L_12 ,
V_42 ) ;
return V_42 ;
}
}
V_3 = F_28 ( V_14 , L_13 , & V_44 , V_45 ,
sizeof( * V_6 ) ) ;
if ( ! V_3 ) {
V_42 = - V_32 ;
goto V_46;
}
V_6 = V_3 -> V_7 ;
V_6 -> V_3 = V_3 ;
V_6 -> V_17 = V_17 ;
V_3 -> V_47 = false ;
V_42 = F_14 ( V_24 , V_6 ) ;
if ( V_42 )
goto V_48;
F_29 ( V_24 , V_3 ) ;
V_42 = F_30 ( V_14 , V_1 , F_3 ,
F_1 , 0 , L_14 ,
V_3 ) ;
if ( V_42 ) {
F_7 ( V_14 , L_15 , V_42 ) ;
goto V_48;
}
V_42 = F_11 ( V_6 -> V_17 ) ;
if ( V_42 )
goto V_48;
V_6 -> V_8 = V_8 ;
V_6 -> V_20 = V_20 ;
V_6 -> V_10 = V_11 -> V_49 -> V_50 ;
V_6 -> V_11 = V_11 ;
V_6 -> V_1 = V_1 ;
V_42 = F_31 ( V_3 ) ;
if ( V_42 ) {
F_7 ( V_14 , L_16 , V_42 ) ;
goto V_48;
}
return 0 ;
V_48:
F_32 ( V_3 ) ;
V_46:
if ( V_14 -> V_43 )
F_33 ( V_14 ) ;
return V_42 ;
}
static int F_34 ( struct V_23 * V_24 )
{
struct V_3 * V_3 = F_35 ( V_24 ) ;
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_13 * V_14 = & V_24 -> V_14 ;
F_36 ( V_6 -> V_1 ) ;
F_37 ( V_3 ) ;
F_32 ( V_3 ) ;
if ( V_14 -> V_43 )
F_33 ( V_14 ) ;
return 0 ;
}

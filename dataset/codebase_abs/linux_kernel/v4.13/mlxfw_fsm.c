static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
enum V_3 V_4 )
{
enum V_5 V_6 ;
enum V_3 V_7 ;
int V_8 ;
int V_9 ;
V_8 = V_10 ;
V_11:
V_9 = V_1 -> V_12 -> V_13 ( V_1 , V_2 ,
& V_7 , & V_6 ) ;
if ( V_9 )
return V_9 ;
if ( V_6 != V_14 ) {
F_2 ( L_1 ,
V_15 [ V_6 ] ) ;
return - V_16 ;
}
if ( V_7 != V_4 ) {
if ( -- V_8 == 0 ) {
F_2 ( L_2 ) ;
return - V_17 ;
}
F_3 ( V_18 ) ;
goto V_11;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 ,
T_1 V_2 ,
struct V_19 * V_20 )
{
T_2 V_21 ;
T_3 V_22 ;
T_1 V_23 ;
T_2 V_24 ;
T_3 * V_25 ;
T_1 V_26 ;
int V_9 ;
V_9 = V_1 -> V_12 -> V_27 ( V_1 , V_20 -> V_28 ,
& V_23 , & V_22 ,
& V_21 ) ;
if ( V_9 )
return V_9 ;
V_23 = F_5 ( T_1 , V_23 , V_29 ) ;
if ( V_20 -> V_30 > V_23 ) {
F_2 ( L_3 ,
V_20 -> V_28 , V_20 -> V_30 , V_23 ) ;
return - V_16 ;
}
V_21 = F_6 ( V_21 ,
V_22 ) ;
F_7 ( L_4 ) ;
V_9 = V_1 -> V_12 -> V_31 ( V_1 , V_2 ,
V_20 -> V_28 ,
V_20 -> V_30 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_1 ( V_1 , V_2 ,
V_32 ) ;
if ( V_9 )
goto V_33;
F_7 ( L_5 ) ;
for ( V_26 = 0 ;
V_26 < F_8 ( V_20 -> V_30 , V_22 ) ;
V_26 += V_21 ) {
V_25 = V_20 -> V_34 + V_26 ;
V_24 = ( T_2 ) F_5 ( T_1 , V_20 -> V_30 - V_26 ,
V_21 ) ;
V_9 = V_1 -> V_12 -> V_35 ( V_1 , V_2 ,
V_25 , V_24 ,
V_26 ) ;
if ( V_9 )
goto V_33;
}
F_7 ( L_6 ) ;
V_9 = V_1 -> V_12 -> V_36 ( V_1 , V_2 ,
V_20 -> V_28 ) ;
if ( V_9 )
goto V_33;
V_9 = F_1 ( V_1 , V_2 , V_37 ) ;
if ( V_9 )
goto V_33;
return 0 ;
V_33:
V_1 -> V_12 -> V_38 ( V_1 , V_2 ) ;
return V_9 ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_2 ,
struct V_39 * V_40 )
{
T_1 V_41 ;
int V_9 ;
int V_42 ;
V_9 = F_10 ( V_40 , V_1 -> V_43 ,
V_1 -> V_44 ,
& V_41 ) ;
if ( V_9 ) {
F_2 ( L_7 ) ;
return V_9 ;
}
for ( V_42 = 0 ; V_42 < V_41 ; V_42 ++ ) {
struct V_19 * V_20 ;
V_20 = F_11 ( V_40 , V_1 -> V_43 ,
V_1 -> V_44 , V_42 ) ;
if ( F_12 ( V_20 ) )
return F_13 ( V_20 ) ;
F_14 ( L_8 , V_20 -> V_28 ) ;
V_9 = F_4 ( V_1 , V_2 , V_20 ) ;
F_15 ( V_20 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_1 ,
const struct V_45 * V_45 )
{
struct V_39 * V_40 ;
T_1 V_2 ;
int V_9 ;
if ( ! F_17 ( V_45 ) ) {
F_2 ( L_9 ) ;
return - V_16 ;
}
V_40 = F_18 ( V_45 ) ;
if ( F_12 ( V_40 ) )
return F_13 ( V_40 ) ;
F_14 ( L_10 ) ;
V_9 = V_1 -> V_12 -> V_46 ( V_1 , & V_2 ) ;
if ( V_9 ) {
F_2 ( L_11 ) ;
goto V_47;
}
V_9 = F_1 ( V_1 , V_2 ,
V_37 ) ;
if ( V_9 )
goto V_48;
V_9 = F_9 ( V_1 , V_2 , V_40 ) ;
if ( V_9 )
goto V_49;
F_7 ( L_12 ) ;
V_9 = V_1 -> V_12 -> V_50 ( V_1 , V_2 ) ;
if ( V_9 ) {
F_2 ( L_13 ) ;
goto V_51;
}
V_9 = F_1 ( V_1 , V_2 , V_37 ) ;
if ( V_9 )
goto V_52;
F_7 ( L_14 ) ;
V_1 -> V_12 -> V_53 ( V_1 , V_2 ) ;
F_14 ( L_15 ) ;
F_19 ( V_40 ) ;
return 0 ;
V_52:
V_51:
V_49:
V_48:
V_1 -> V_12 -> V_53 ( V_1 , V_2 ) ;
V_47:
F_19 ( V_40 ) ;
return V_9 ;
}

static int F_1 ( const struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
T_1 V_5 ;
int V_6 ;
if ( F_2 ( V_3 , 0 ) < 0 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
if ( F_4 ( V_3 , V_2 -> V_8 . V_9 ) >= 0 ) {
F_3 ( L_2 ) ;
return - V_7 ;
}
V_5 = F_5 ( 0 ) ;
if ( ! V_5 )
return - V_10 ;
V_6 = F_6 ( V_5 , V_3 , V_2 -> V_8 . V_11 , V_2 -> V_8 . V_9 ) ;
if ( V_6 < 0 ) {
F_7 ( V_5 ) ;
return V_6 ;
}
* V_4 = V_5 ;
return 0 ;
}
static int F_8 ( T_1 V_12 , T_2 V_13 , T_3 * * V_14 )
{
unsigned V_15 , V_16 ;
int V_17 ;
T_3 * V_18 ;
V_16 = F_9 ( V_12 ) ;
F_10 ( L_3 , V_16 , V_13 * 8 ) ;
if ( V_16 != V_13 * 8 - 15 )
return - V_19 ;
V_18 = F_11 ( V_12 , & V_15 , & V_17 ) ;
if ( ! V_18 )
return - V_10 ;
if ( V_17 < 0 ) {
F_12 ( V_18 ) ;
return - V_7 ;
}
if ( V_15 != V_13 - 1 ) {
F_12 ( V_18 ) ;
return - V_7 ;
}
* V_14 = V_18 ;
return 0 ;
}
static int F_13 ( const T_3 * V_20 , const T_3 * V_21 , T_2 V_22 , T_2 V_23 ,
const T_3 * V_24 , T_2 V_25 )
{
unsigned V_26 , V_27 , V_28 ;
F_14 ( L_4 , V_22 , V_23 , V_25 ) ;
if ( V_22 < 2 + 1 + V_25 + V_23 )
return - V_7 ;
if ( V_21 [ 1 ] != 0x01 ) {
F_3 ( L_5 , V_21 [ 1 ] ) ;
return - V_7 ;
}
V_27 = V_22 - ( V_25 + V_23 ) ;
V_26 = V_27 - 1 ;
if ( V_21 [ V_26 ] != 0x00 ) {
F_3 ( L_6 , V_21 [ V_26 ] ) ;
return - V_7 ;
}
for ( V_28 = 2 ; V_28 < V_26 ; V_28 ++ ) {
if ( V_21 [ V_28 ] != 0xff ) {
F_3 ( L_7 , V_28 - 2 , V_21 [ V_28 ] ) ;
return - V_7 ;
}
}
if ( F_15 ( V_24 , V_21 + V_27 , V_25 ) != 0 ) {
F_3 ( L_8 ) ;
return - V_7 ;
}
if ( F_15 ( V_20 , V_21 + V_27 + V_25 , V_23 ) != 0 ) {
F_3 ( L_9 ) ;
return - V_29 ;
}
F_3 ( L_10 ) ;
return 0 ;
}
static int F_16 ( const struct V_1 * V_2 ,
const struct V_30 * V_31 )
{
T_2 V_32 ;
int V_6 ;
const T_3 * V_20 = V_31 -> V_33 ;
T_3 * V_21 = NULL ;
T_1 V_5 = NULL ;
T_2 V_22 ;
F_14 ( L_11 ) ;
if ( ! V_34 [ V_31 -> V_35 ] . V_36 )
return - V_37 ;
V_22 = F_9 ( V_2 -> V_8 . V_9 ) ;
V_32 = F_9 ( V_31 -> V_8 . V_3 ) ;
F_10 ( L_12 , V_22 , V_32 ) ;
if ( V_22 < V_32 ) {
V_6 = - V_7 ;
goto error;
}
V_22 = ( V_22 + 7 ) / 8 ;
V_6 = F_1 ( V_2 , V_31 -> V_8 . V_3 , & V_5 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_8 ( V_5 , V_22 , & V_21 ) ;
if ( V_6 < 0 )
goto error;
V_6 = F_13 ( V_20 , V_21 - 1 , V_22 , V_31 -> V_38 ,
V_34 [ V_31 -> V_35 ] . V_36 ,
V_34 [ V_31 -> V_35 ] . V_39 ) ;
error:
F_12 ( V_21 ) ;
F_7 ( V_5 ) ;
F_3 ( L_13 , V_6 ) ;
return V_6 ;
}

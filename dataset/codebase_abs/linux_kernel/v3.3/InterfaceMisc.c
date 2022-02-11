INT F_1 ( T_1 V_1 ,
T_2 V_2 ,
T_3 V_3 ,
INT V_4 )
{
int V_5 ;
T_4 V_6 = 0 ;
if ( V_1 == NULL ) {
F_2 ( V_1 -> V_7 , V_8 , 0 , 0 , L_1 ) ;
return - V_9 ;
}
if ( V_1 -> V_7 -> V_10 == TRUE ) {
F_2 ( V_1 -> V_7 , V_8 , 0 , 0 , L_2 ) ;
return - V_11 ;
}
if ( ( V_1 -> V_7 -> V_12 == TRUE ) && ( V_1 -> V_7 -> V_13 >= V_14 ) ) {
F_2 ( V_1 -> V_7 , V_15 , V_16 , V_17 , L_3 ) ;
return - V_18 ;
}
if ( V_1 -> V_19 == TRUE || V_1 -> V_20 == TRUE ) {
F_2 ( V_1 -> V_7 , V_15 , V_16 , V_17 , L_4 ) ;
return - V_18 ;
}
V_1 -> V_7 -> V_21 = TRUE ;
do {
V_5 = F_3 ( V_1 -> V_22 ,
F_4 ( V_1 -> V_22 , 0 ) ,
0x02 ,
0xC2 ,
( V_2 & 0xFFFF ) ,
( ( V_2 >> 16 ) & 0xFFFF ) ,
V_3 ,
V_4 ,
5000 ) ;
V_6 ++ ;
if ( - V_11 == V_5 ) {
V_1 -> V_7 -> V_10 = TRUE ;
break;
}
} while ( ( V_5 < 0 ) && ( V_6 < V_23 ) );
if ( V_5 < 0 )
F_2 ( V_1 -> V_7 , V_15 , V_16 , V_17 , L_5 , V_5 , V_6 ) ;
else
F_2 ( V_1 -> V_7 , V_15 , V_16 , V_17 , L_6 , V_5 ) ;
V_1 -> V_7 -> V_21 = FALSE ;
return V_5 ;
}
INT F_5 ( T_1 V_1 ,
T_2 V_2 ,
T_3 V_3 ,
INT V_4 )
{
int V_24 = 0 ;
T_4 V_6 = 0 ;
if ( V_1 == NULL ) {
F_2 ( V_1 -> V_7 , V_8 , 0 , 0 , L_7 ) ;
return - V_9 ;
}
if ( V_1 -> V_7 -> V_10 == TRUE ) {
F_2 ( V_1 -> V_7 , V_8 , 0 , 0 , L_2 ) ;
return - V_11 ;
}
if ( ( V_1 -> V_7 -> V_12 == TRUE ) && ( V_1 -> V_7 -> V_13 >= V_14 ) ) {
F_2 ( V_1 -> V_7 , V_15 , V_25 , V_17 , L_8 ) ;
return - V_18 ;
}
if ( V_1 -> V_19 == TRUE || V_1 -> V_20 == TRUE ) {
F_2 ( V_1 -> V_7 , V_15 , V_25 , V_17 , L_4 ) ;
return - V_18 ;
}
V_1 -> V_7 -> V_21 = TRUE ;
do {
V_24 = F_3 ( V_1 -> V_22 ,
F_6 ( V_1 -> V_22 , 0 ) ,
0x01 ,
0x42 ,
( V_2 & 0xFFFF ) ,
( ( V_2 >> 16 ) & 0xFFFF ) ,
V_3 ,
V_4 ,
5000 ) ;
V_6 ++ ;
if ( - V_11 == V_24 ) {
V_1 -> V_7 -> V_10 = TRUE ;
break;
}
} while ( ( V_24 < 0 ) && ( V_6 < V_23 ) );
if ( V_24 < 0 ) {
F_2 ( V_1 -> V_7 , V_15 , V_25 , V_17 , L_9 , V_24 , V_6 ) ;
V_1 -> V_7 -> V_21 = FALSE ;
return V_24 ;
} else {
V_1 -> V_7 -> V_21 = FALSE ;
F_2 ( V_1 -> V_7 , V_15 , V_25 , V_17 , L_10 , V_24 ) ;
return V_26 ;
}
}
INT F_7 ( T_3 V_27 ,
T_2 V_2 ,
T_3 V_3 ,
INT V_4 )
{
return F_1 ( ( T_1 ) V_27 , V_2 , V_3 , V_4 ) ;
}
INT F_8 ( T_3 V_27 ,
T_2 V_2 ,
T_3 V_3 ,
INT V_4 )
{
return F_5 ( ( T_1 ) V_27 , V_2 , V_3 , V_4 ) ;
}
INT F_9 ( T_5 V_28 )
{
T_1 V_1 = ( T_1 ) ( V_28 -> V_29 ) ;
INT V_30 = V_26 ;
F_10 ( V_1 ) ;
V_30 = F_11 ( V_1 -> V_22 , V_1 -> V_31 . V_32 ) ;
if ( V_30 != V_26 )
F_2 ( V_28 , V_15 , V_33 , V_17 , L_11 , V_30 ) ;
V_30 = F_11 ( V_1 -> V_22 , V_1 -> V_34 . V_35 ) ;
if ( V_30 != V_26 )
F_2 ( V_28 , V_15 , V_33 , V_17 , L_12 , V_30 ) ;
V_30 = F_11 ( V_1 -> V_22 , V_1 -> V_36 . V_37 ) ;
if ( V_30 != V_26 )
F_2 ( V_28 , V_15 , V_33 , V_17 , L_13 , V_30 ) ;
return V_30 ;
}
VOID F_10 ( T_1 V_1 )
{
struct V_38 * V_39 = NULL ;
T_2 V_40 ;
if ( V_1 -> V_41 != NULL ) {
if ( V_1 -> V_41 -> V_30 == - V_42 )
F_12 ( V_1 -> V_41 ) ;
}
for ( V_40 = 0 ; V_40 < V_43 ; V_40 ++ ) {
V_39 = V_1 -> V_44 [ V_40 ] . V_38 ;
if ( V_39 ) {
if ( V_39 -> V_30 == - V_42 )
F_12 ( V_39 ) ;
}
}
for ( V_40 = 0 ; V_40 < V_45 ; V_40 ++ ) {
V_39 = V_1 -> V_46 [ V_40 ] . V_38 ;
if ( V_39 ) {
if ( V_39 -> V_30 == - V_42 )
F_12 ( V_39 ) ;
}
}
F_13 ( & V_1 -> V_47 , 0 ) ;
F_13 ( & V_1 -> V_48 , 0 ) ;
F_13 ( & V_1 -> V_49 , 0 ) ;
F_13 ( & V_1 -> V_50 , 0 ) ;
}
VOID F_14 ( struct V_51 * V_52 )
{
T_1 V_1 = NULL ;
struct V_53 * V_54 = NULL ;
V_1 = F_15 ( V_52 , V_55 , V_56 ) ;
V_54 = V_1 -> V_57 ;
if ( V_1 -> V_19 == FALSE )
F_16 ( V_54 ) ;
}

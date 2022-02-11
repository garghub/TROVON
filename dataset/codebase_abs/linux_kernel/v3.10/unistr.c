bool F_1 ( const T_1 * V_1 , T_2 V_2 ,
const T_1 * V_3 , T_2 V_4 , const T_3 V_5 ,
const T_1 * V_6 , const T_4 V_7 )
{
if ( V_2 != V_4 )
return false ;
if ( V_5 == V_8 )
return ! F_2 ( V_1 , V_3 , V_2 ) ;
return ! F_3 ( V_1 , V_3 , V_2 , V_6 , V_7 ) ;
}
int F_4 ( const T_1 * V_9 , const T_4 V_10 ,
const T_1 * V_11 , const T_4 V_12 ,
const int V_13 , const T_3 V_5 ,
const T_1 * V_6 , const T_4 V_14 )
{
T_4 V_15 , V_16 ;
T_5 V_17 , V_18 ;
V_16 = V_10 ;
if ( V_10 > V_12 )
V_16 = V_12 ;
for ( V_15 = 0 ; V_15 < V_16 ; ++ V_15 ) {
V_17 = F_5 ( * V_9 ++ ) ;
V_18 = F_5 ( * V_11 ++ ) ;
if ( V_5 ) {
if ( V_17 < V_14 )
V_17 = F_5 ( V_6 [ V_17 ] ) ;
if ( V_18 < V_14 )
V_18 = F_5 ( V_6 [ V_18 ] ) ;
}
if ( V_17 < 64 && V_19 [ V_17 ] & 8 )
return V_13 ;
if ( V_17 < V_18 )
return - 1 ;
if ( V_17 > V_18 )
return 1 ;
}
if ( V_10 < V_12 )
return - 1 ;
if ( V_10 == V_12 )
return 0 ;
V_17 = F_5 ( * V_9 ) ;
if ( V_17 < 64 && V_19 [ V_17 ] & 8 )
return V_13 ;
return 1 ;
}
int F_2 ( const T_1 * V_1 , const T_1 * V_3 , T_2 V_20 )
{
T_5 V_17 , V_18 ;
T_2 V_21 ;
for ( V_21 = 0 ; V_21 < V_20 ; ++ V_21 ) {
V_17 = F_5 ( V_1 [ V_21 ] ) ;
V_18 = F_5 ( V_3 [ V_21 ] ) ;
if ( V_17 < V_18 )
return - 1 ;
if ( V_17 > V_18 )
return 1 ;
if ( ! V_17 )
break;
}
return 0 ;
}
int F_3 ( const T_1 * V_1 , const T_1 * V_3 , T_2 V_20 ,
const T_1 * V_6 , const T_4 V_7 )
{
T_2 V_21 ;
T_5 V_17 , V_18 ;
for ( V_21 = 0 ; V_21 < V_20 ; ++ V_21 ) {
if ( ( V_17 = F_5 ( V_1 [ V_21 ] ) ) < V_7 )
V_17 = F_5 ( V_6 [ V_17 ] ) ;
if ( ( V_18 = F_5 ( V_3 [ V_21 ] ) ) < V_7 )
V_18 = F_5 ( V_6 [ V_18 ] ) ;
if ( V_17 < V_18 )
return - 1 ;
if ( V_17 > V_18 )
return 1 ;
if ( ! V_17 )
break;
}
return 0 ;
}
void F_6 ( T_1 * V_22 , T_4 V_23 , const T_1 * V_6 ,
const T_4 V_14 )
{
T_4 V_21 ;
T_5 V_24 ;
for ( V_21 = 0 ; V_21 < V_23 ; V_21 ++ )
if ( ( V_24 = F_5 ( V_22 [ V_21 ] ) ) < V_14 )
V_22 [ V_21 ] = V_6 [ V_24 ] ;
}
void F_7 ( T_6 * V_25 ,
const T_1 * V_6 , const T_4 V_14 )
{
F_6 ( ( T_1 * ) & V_25 -> V_26 ,
V_25 -> V_27 , V_6 , V_14 ) ;
}
int F_8 ( T_6 * V_28 ,
T_6 * V_29 ,
const int V_13 , const T_3 V_5 ,
const T_1 * V_6 , const T_4 V_14 )
{
return F_4 ( ( T_1 * ) & V_28 -> V_26 ,
V_28 -> V_27 ,
( T_1 * ) & V_29 -> V_26 ,
V_29 -> V_27 ,
V_13 , V_5 , V_6 , V_14 ) ;
}
int F_9 ( const T_7 * V_30 , const char * V_31 ,
const int V_32 , T_1 * * V_33 )
{
struct V_34 * V_35 = V_30 -> V_36 ;
T_1 * V_37 ;
T_8 V_38 ;
int V_21 , V_39 , V_40 ;
if ( F_10 ( V_31 ) ) {
V_37 = F_11 ( V_41 , V_42 ) ;
if ( F_10 ( V_37 ) ) {
for ( V_21 = V_39 = 0 ; V_21 < V_32 ; V_21 += V_40 ) {
V_40 = V_35 -> V_43 ( V_31 + V_21 , V_32 - V_21 ,
& V_38 ) ;
if ( F_10 ( V_40 >= 0 &&
V_39 < V_44 ) ) {
if ( F_10 ( V_38 ) ) {
V_37 [ V_39 ++ ] = F_12 ( V_38 ) ;
continue;
}
break;
}
goto V_45;
}
V_37 [ V_39 ] = 0 ;
* V_33 = V_37 ;
return V_39 ;
}
F_13 ( V_30 -> V_46 , L_1
L_2 ) ;
return - V_47 ;
}
F_13 ( V_30 -> V_46 , L_3 ) ;
return - V_48 ;
V_45:
F_14 ( V_41 , V_37 ) ;
if ( V_40 < 0 ) {
F_13 ( V_30 -> V_46 , L_4
L_5
L_6 , V_35 -> V_49 ) ;
V_21 = - V_50 ;
} else {
F_13 ( V_30 -> V_46 , L_7
L_8 ,
V_44 ) ;
V_21 = - V_51 ;
}
return V_21 ;
}
int F_15 ( const T_7 * V_30 , const T_1 * V_31 ,
const int V_32 , unsigned char * * V_33 , int V_52 )
{
struct V_34 * V_35 = V_30 -> V_36 ;
unsigned char * V_53 ;
int V_21 , V_39 , V_54 , V_38 ;
if ( V_31 ) {
V_53 = * V_33 ;
V_54 = V_52 ;
if ( V_53 && ! V_54 ) {
V_38 = - V_51 ;
goto V_55;
}
if ( ! V_53 ) {
V_54 = V_32 * V_56 ;
V_53 = F_16 ( V_54 + 1 , V_42 ) ;
if ( ! V_53 )
goto V_57;
}
for ( V_21 = V_39 = 0 ; V_21 < V_32 ; V_21 ++ ) {
V_58: V_38 = V_35 -> V_59 ( F_5 ( V_31 [ V_21 ] ) , V_53 + V_39 ,
V_54 - V_39 ) ;
if ( V_38 > 0 ) {
V_39 += V_38 ;
continue;
} else if ( ! V_38 )
break;
else if ( V_38 == - V_51 && V_53 != * V_33 ) {
unsigned char * V_60 ;
V_60 = F_16 ( ( V_54 + 64 ) &
~ 63 , V_42 ) ;
if ( V_60 ) {
memcpy ( V_60 , V_53 , V_54 ) ;
V_54 = ( ( V_54 + 64 ) & ~ 63 ) - 1 ;
F_17 ( V_53 ) ;
V_53 = V_60 ;
goto V_58;
}
}
goto V_55;
}
V_53 [ V_39 ] = 0 ;
* V_33 = V_53 ;
return V_39 ;
}
F_13 ( V_30 -> V_46 , L_3 ) ;
return - V_48 ;
V_55:
F_13 ( V_30 -> V_46 , L_9
L_10
L_11 , V_35 -> V_49 ) ;
if ( V_53 != * V_33 )
F_17 ( V_53 ) ;
if ( V_38 != - V_51 )
V_38 = - V_50 ;
return V_38 ;
V_57:
F_13 ( V_30 -> V_46 , L_12 ) ;
return - V_47 ;
}

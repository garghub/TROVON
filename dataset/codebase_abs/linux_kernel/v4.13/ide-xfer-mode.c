const char * F_1 ( T_1 V_1 )
{
const char * V_2 ;
T_1 V_3 = V_1 & 0xf ;
if ( V_1 >= V_4 && V_1 <= V_5 )
V_2 = V_6 [ V_3 ] ;
else if ( V_1 >= V_7 && V_1 <= V_8 )
V_2 = V_9 [ V_3 ] ;
else if ( V_1 >= V_10 && V_1 <= V_11 )
V_2 = V_12 [ V_3 ] ;
else if ( V_1 >= V_13 && V_1 <= V_14 )
V_2 = V_15 [ V_3 & 0x7 ] ;
else if ( V_1 == V_16 )
V_2 = L_1 ;
else
V_2 = L_2 ;
return V_2 ;
}
static T_1 F_2 ( T_2 * V_17 , T_1 V_18 , T_1 V_19 )
{
T_3 * V_20 = V_17 -> V_20 ;
int V_21 = - 1 , V_22 = 0 ;
if ( V_18 != 255 )
return F_3 ( T_1 , V_18 , V_19 ) ;
if ( ( V_17 -> V_23 -> V_24 & V_25 ) == 0 )
V_21 = F_4 ( ( char * ) & V_20 [ V_26 ] ) ;
if ( V_21 != - 1 ) {
F_5 ( V_27 L_3 , V_17 -> V_28 ) ;
} else {
V_21 = V_20 [ V_29 ] >> 8 ;
if ( V_21 > 2 ) {
V_21 = 2 ;
V_22 = 1 ;
}
if ( V_20 [ V_30 ] & 2 ) {
if ( F_6 ( V_20 ) && ( V_20 [ V_31 ] & 7 ) )
V_21 = 4 + F_3 ( int , 2 ,
V_20 [ V_31 ] & 7 ) ;
else if ( F_7 ( V_20 ) ) {
if ( V_20 [ V_32 ] & 7 ) {
V_22 = 0 ;
if ( V_20 [ V_32 ] & 4 )
V_21 = 5 ;
else if ( V_20 [ V_32 ] & 2 )
V_21 = 4 ;
else
V_21 = 3 ;
}
}
}
if ( V_22 )
F_5 ( V_27 L_4 ,
V_17 -> V_28 ) ;
}
if ( V_21 > V_19 )
V_21 = V_19 ;
return V_21 ;
}
int F_8 ( T_2 * V_17 , const T_1 V_33 )
{
if ( V_33 == 0 && ( V_17 -> V_23 -> V_34 & V_35 ) )
return 0 ;
return F_9 ( V_17 -> V_20 , V_33 ) ;
}
int F_10 ( T_2 * V_17 , const T_1 V_1 )
{
T_4 * V_23 = V_17 -> V_23 ;
const struct V_36 * V_37 = V_23 -> V_37 ;
if ( V_23 -> V_24 & V_38 )
return 0 ;
if ( V_37 == NULL || V_37 -> V_39 == NULL )
return - 1 ;
if ( V_37 -> V_40 == NULL ) {
V_17 -> V_21 = V_1 ;
V_37 -> V_39 ( V_23 , V_17 ) ;
return 0 ;
}
if ( V_23 -> V_24 & V_41 ) {
if ( F_11 ( V_17 , V_1 ) )
return - 1 ;
V_17 -> V_21 = V_1 ;
V_37 -> V_39 ( V_23 , V_17 ) ;
return 0 ;
} else {
V_17 -> V_21 = V_1 ;
V_37 -> V_39 ( V_23 , V_17 ) ;
return F_11 ( V_17 , V_1 ) ;
}
}
int F_12 ( T_2 * V_17 , const T_1 V_1 )
{
T_4 * V_23 = V_17 -> V_23 ;
const struct V_36 * V_37 = V_23 -> V_37 ;
if ( V_23 -> V_24 & V_38 )
return 0 ;
if ( V_37 == NULL || V_37 -> V_40 == NULL )
return - 1 ;
if ( V_23 -> V_24 & V_41 ) {
if ( F_11 ( V_17 , V_1 ) )
return - 1 ;
V_17 -> V_42 = V_1 ;
V_37 -> V_40 ( V_23 , V_17 ) ;
return 0 ;
} else {
V_17 -> V_42 = V_1 ;
V_37 -> V_40 ( V_23 , V_17 ) ;
return F_11 ( V_17 , V_1 ) ;
}
}
void F_13 ( T_2 * V_17 , T_1 V_43 )
{
T_4 * V_23 = V_17 -> V_23 ;
const struct V_36 * V_37 = V_23 -> V_37 ;
T_1 V_44 , V_33 ;
if ( V_37 == NULL || V_37 -> V_39 == NULL ||
( V_23 -> V_24 & V_38 ) )
return;
F_14 ( V_23 -> V_45 == 0x00 ) ;
V_44 = F_15 ( V_23 -> V_45 ) - 1 ;
V_33 = F_2 ( V_17 , V_43 , V_44 ) ;
F_5 ( V_46 L_5 ,
V_17 -> V_28 , V_44 , V_43 ,
V_43 == 255 ? L_6 : L_7 , V_33 ) ;
( void ) F_10 ( V_17 , V_13 + V_33 ) ;
}
static T_1 F_16 ( T_2 * V_17 , T_1 V_47 )
{
T_4 * V_23 = V_17 -> V_23 ;
T_1 V_1 = F_17 ( V_17 , V_47 ) ;
if ( V_1 == 0 ) {
if ( V_23 -> V_45 )
V_1 = F_15 ( V_23 -> V_45 ) - 1 + V_13 ;
else
V_1 = V_48 ;
}
return F_18 ( V_47 , V_1 ) ;
}
int F_19 ( T_2 * V_17 , T_1 V_49 )
{
T_4 * V_23 = V_17 -> V_23 ;
const struct V_36 * V_37 = V_23 -> V_37 ;
if ( V_37 == NULL || V_37 -> V_40 == NULL ||
( V_23 -> V_24 & V_38 ) )
return - 1 ;
V_49 = F_16 ( V_17 , V_49 ) ;
F_14 ( V_49 < V_13 ) ;
if ( V_49 >= V_13 && V_49 <= V_14 )
return F_10 ( V_17 , V_49 ) ;
return F_12 ( V_17 , V_49 ) ;
}

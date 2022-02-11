static T_1
F_1 ( T_2 * V_1 , T_3 V_2 , struct V_3 * V_4 ,
T_4 * V_5 , int * V_6 , T_5 * * V_7 )
{
T_6 V_8 ;
int V_9 ;
if ( ( V_8 = F_2 ( V_1 , V_6 ) ) == - 1 )
return FALSE ;
if ( V_8 > V_10 ) {
* V_6 = V_11 ;
* V_7 = F_3 ( L_1 V_12 L_2 ,
V_8 , V_10 ) ;
return FALSE ;
}
V_9 = ( int ) V_8 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 = 0 ;
V_4 -> V_16 = V_9 ;
V_4 -> V_17 = V_9 ;
V_4 -> V_18 . V_19 = 0 ;
V_4 -> V_18 . V_20 = 0 ;
return F_4 ( V_2 , V_5 , V_9 , V_6 , V_7 ) ;
}
static T_1
F_5 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 , T_6 * V_21 )
{
T_6 V_22 ;
* V_6 = 0 ;
V_22 = F_6 ( V_1 -> V_2 ) ;
if ( V_22 != 0 )
return FALSE ;
* V_21 = V_22 ;
return F_1 ( V_1 , V_1 -> V_2 , & V_1 -> V_4 , V_1 -> V_23 , V_6 , V_7 ) ;
}
static T_1
F_7 ( T_2 * V_1 , T_6 V_24 , struct V_3 * V_4 , T_4 * V_5 , int * V_6 , T_5 * * V_7 )
{
if ( V_24 > 0 ) {
* V_6 = 0 ;
return FALSE ;
}
if ( F_8 ( V_1 -> V_25 , V_24 , V_26 , V_6 ) == - 1 )
return FALSE ;
return F_1 ( V_1 , V_1 -> V_25 , V_4 , V_5 , V_6 , V_7 ) ;
}
T_7
F_9 ( T_2 * V_1 , int * V_6 , T_5 * * V_7 )
{
char V_27 [ 128 ] ;
int V_28 ;
T_1 V_29 ;
T_8 V_30 ;
T_8 V_31 = 12 ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ )
V_31 = F_10 ( V_31 , V_33 [ V_30 ] . V_34 ) ;
V_31 = ( T_8 ) F_11 ( V_31 , sizeof( V_27 ) ) ;
V_28 = F_12 ( V_27 , V_31 , V_1 -> V_2 ) ;
if ( V_28 < 0 ) {
* V_6 = F_13 ( V_1 -> V_2 , V_7 ) ;
return V_35 ;
}
if ( V_28 == 0 )
return V_36 ;
V_29 = FALSE ;
for ( V_30 = 0 ; V_30 < V_32 ; V_30 ++ ) {
if ( ( T_8 ) V_28 >= V_33 [ V_30 ] . V_34 && ! memcmp ( V_27 , V_33 [ V_30 ] . V_37 , F_11 ( V_33 [ V_30 ] . V_34 , ( T_8 ) V_28 ) ) ) {
if ( ! V_29 ) {
if ( V_33 [ V_30 ] . V_37 == V_38 ) {
if ( memcmp ( V_27 + 8 , V_39 , sizeof( V_39 ) ) &&
memcmp ( V_27 + 8 , V_40 , sizeof( V_40 ) ) )
continue;
}
V_29 = TRUE ;
} else
return V_36 ;
}
}
if ( ! V_29 )
return V_36 ;
if ( F_8 ( V_1 -> V_2 , 0 , V_26 , V_6 ) == - 1 )
return V_35 ;
V_1 -> V_41 = V_42 ;
V_1 -> V_43 = V_44 ;
V_1 -> V_45 = V_46 ;
V_1 -> V_47 = F_5 ;
V_1 -> V_48 = F_7 ;
V_1 -> V_49 = 0 ;
return V_50 ;
}

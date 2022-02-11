int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 ;
char V_5 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_6 ; V_4 ++ )
if ( V_2 -> V_7 [ V_4 ] . V_8 > 0 )
V_3 ++ ;
if ( V_3 == 0 )
return - 1 ;
F_2 ( & V_5 , 1 ) ;
V_3 = V_5 % V_3 ;
V_4 = 0 ;
for ( V_4 = 0 ; V_3 > 0 ; V_4 ++ , V_3 -- )
while ( V_2 -> V_7 [ V_4 ] . V_8 <= 0 )
V_4 ++ ;
return V_4 ;
}
struct V_1 * F_3 ( void * * V_9 , void * V_10 )
{
struct V_1 * V_2 ;
const void * V_11 = * V_9 ;
int V_4 , V_12 , V_3 ;
int V_13 = - V_14 ;
T_1 V_15 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_16 ) ;
if ( V_2 == NULL )
return F_5 ( - V_17 ) ;
F_6 ( V_9 , V_10 , V_15 , V_18 ) ;
if ( V_15 > 3 ) {
F_7 ( L_1 , V_15 ) ;
goto V_18;
}
F_8 ( V_9 , V_10 , 8 * sizeof( V_19 ) + sizeof( V_20 ) , V_18 ) ;
V_2 -> V_21 = F_9 ( V_9 ) ;
V_2 -> V_22 = F_9 ( V_9 ) ;
V_2 -> V_23 = F_9 ( V_9 ) ;
V_2 -> V_24 = F_9 ( V_9 ) ;
V_2 -> V_25 = F_9 ( V_9 ) ;
V_2 -> V_26 = F_9 ( V_9 ) ;
V_2 -> V_27 = F_10 ( V_9 ) ;
V_2 -> V_6 = F_9 ( V_9 ) ;
V_2 -> V_7 = F_11 ( V_2 -> V_6 , sizeof( * V_2 -> V_7 ) , V_16 ) ;
if ( V_2 -> V_7 == NULL )
goto V_28;
V_3 = F_9 ( V_9 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_20 V_29 ;
V_19 V_30 ;
T_2 V_31 , V_32 , V_8 ;
V_20 V_33 ;
T_3 V_34 ;
struct V_35 V_36 ;
V_19 V_37 ;
void * V_38 = NULL ;
struct V_39 V_40 ;
F_8 ( V_9 , V_10 , sizeof( V_20 ) * 2 + 1 + sizeof( V_19 ) , V_18 ) ;
V_29 = F_10 ( V_9 ) ;
V_34 = F_12 ( V_9 ) ;
* V_9 += sizeof( V_20 ) ;
V_30 = F_9 ( V_9 ) ;
* V_9 += V_30 ;
F_8 ( V_9 , V_10 ,
4 * sizeof( V_19 ) + sizeof( V_20 ) +
sizeof( V_36 ) + sizeof( struct V_39 ) ,
V_18 ) ;
V_31 = F_9 ( V_9 ) ;
V_32 = F_9 ( V_9 ) ;
V_8 = F_9 ( V_9 ) ;
V_33 = F_10 ( V_9 ) ;
F_13 ( V_9 , & V_36 , sizeof( V_36 ) ) ;
F_14 ( & V_36 ) ;
F_13 ( V_9 , & V_40 , sizeof( V_40 ) ) ;
* V_9 += sizeof( V_19 ) ;
F_15 ( V_9 , V_10 , V_30 , V_18 ) ;
* V_9 += V_30 ;
if ( V_34 >= 2 ) {
F_15 ( V_9 , V_10 , V_37 , V_18 ) ;
V_38 = * V_9 ;
* V_9 += V_37 * sizeof( V_19 ) ;
} else {
V_37 = 0 ;
}
F_16 ( L_2 ,
V_4 + 1 , V_3 , V_29 , V_31 , V_32 ,
F_17 ( & V_36 . V_41 ) ,
F_18 ( V_8 ) ) ;
if ( V_31 >= 0 && V_31 < V_2 -> V_6 && V_8 > 0 ) {
V_2 -> V_7 [ V_31 ] . V_29 = V_29 ;
V_2 -> V_7 [ V_31 ] . V_8 = V_8 ;
V_2 -> V_7 [ V_31 ] . V_36 = V_36 ;
V_2 -> V_7 [ V_31 ] . V_42 =
( V_40 . V_43 != 0 ||
V_40 . V_44 != 0 ) ;
V_2 -> V_7 [ V_31 ] . V_37 = V_37 ;
if ( V_37 ) {
V_2 -> V_7 [ V_31 ] . V_45 =
F_11 ( V_37 , sizeof( V_19 ) ,
V_16 ) ;
for ( V_12 = 0 ; V_12 < V_37 ; V_12 ++ )
V_2 -> V_7 [ V_31 ] . V_45 [ V_12 ] =
F_9 ( & V_38 ) ;
} else {
V_2 -> V_7 [ V_31 ] . V_45 = NULL ;
}
}
}
F_15 ( V_9 , V_10 , V_3 , V_18 ) ;
V_2 -> V_46 = V_3 ;
V_2 -> V_47 = F_11 ( V_3 , sizeof( V_20 ) , V_16 ) ;
if ( ! V_2 -> V_47 )
goto V_28;
F_8 ( V_9 , V_10 , sizeof( V_20 ) * ( V_3 + 1 ) , V_18 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 -> V_47 [ V_4 ] = F_10 ( V_9 ) ;
V_2 -> V_48 = F_10 ( V_9 ) ;
F_16 ( L_3 , V_2 -> V_21 ) ;
return V_2 ;
V_28:
V_13 = - V_17 ;
V_18:
F_19 ( L_4 ) ;
F_20 ( V_49 , L_5 ,
V_50 , 16 , 1 ,
V_11 , V_10 - V_11 , true ) ;
F_21 ( V_2 ) ;
return F_5 ( - V_14 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_6 ; V_4 ++ )
F_22 ( V_2 -> V_7 [ V_4 ] . V_45 ) ;
F_22 ( V_2 -> V_7 ) ;
F_22 ( V_2 -> V_47 ) ;
F_22 ( V_2 ) ;
}

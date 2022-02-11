int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
int V_4 ;
if ( 1 == V_2 -> V_5 && V_2 -> V_6 [ 0 ] . V_7 > 0 )
return 0 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( V_2 -> V_6 [ V_4 ] . V_7 > 0 )
V_3 ++ ;
if ( V_3 == 0 )
return - 1 ;
V_3 = F_2 () % V_3 ;
V_4 = 0 ;
for ( V_4 = 0 ; V_3 > 0 ; V_4 ++ , V_3 -- )
while ( V_2 -> V_6 [ V_4 ] . V_7 <= 0 )
V_4 ++ ;
return V_4 ;
}
struct V_1 * F_3 ( void * * V_8 , void * V_9 )
{
struct V_1 * V_2 ;
const void * V_10 = * V_8 ;
int V_4 , V_11 , V_3 ;
int V_12 = - V_13 ;
T_1 V_14 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_15 ) ;
if ( V_2 == NULL )
return F_5 ( - V_16 ) ;
F_6 ( V_8 , V_9 , V_14 , V_17 ) ;
if ( V_14 > 3 ) {
F_7 ( L_1 , V_14 ) ;
goto V_17;
}
F_8 ( V_8 , V_9 , 8 * sizeof( V_18 ) + sizeof( V_19 ) , V_17 ) ;
V_2 -> V_20 = F_9 ( V_8 ) ;
V_2 -> V_21 = F_9 ( V_8 ) ;
V_2 -> V_22 = F_9 ( V_8 ) ;
V_2 -> V_23 = F_9 ( V_8 ) ;
V_2 -> V_24 = F_9 ( V_8 ) ;
V_2 -> V_25 = F_9 ( V_8 ) ;
V_2 -> V_26 = F_10 ( V_8 ) ;
V_2 -> V_5 = F_9 ( V_8 ) ;
V_2 -> V_6 = F_11 ( V_2 -> V_5 , sizeof( * V_2 -> V_6 ) , V_15 ) ;
if ( V_2 -> V_6 == NULL )
goto V_27;
V_3 = F_9 ( V_8 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_19 V_28 ;
V_18 V_29 ;
T_2 V_30 , V_31 , V_7 ;
V_19 V_32 ;
T_3 V_33 ;
struct V_34 V_35 ;
V_18 V_36 ;
void * V_37 = NULL ;
struct V_38 V_39 ;
struct V_40 * V_41 ;
F_8 ( V_8 , V_9 , sizeof( V_19 ) * 2 + 1 + sizeof( V_18 ) , V_17 ) ;
V_28 = F_10 ( V_8 ) ;
V_33 = F_12 ( V_8 ) ;
* V_8 += sizeof( V_19 ) ;
V_29 = F_9 ( V_8 ) ;
* V_8 += V_29 ;
F_8 ( V_8 , V_9 ,
4 * sizeof( V_18 ) + sizeof( V_19 ) +
sizeof( V_35 ) + sizeof( struct V_38 ) ,
V_17 ) ;
V_30 = F_9 ( V_8 ) ;
V_31 = F_9 ( V_8 ) ;
V_7 = F_9 ( V_8 ) ;
V_32 = F_10 ( V_8 ) ;
F_13 ( V_8 , & V_35 , sizeof( V_35 ) ) ;
F_14 ( & V_35 ) ;
F_13 ( V_8 , & V_39 , sizeof( V_39 ) ) ;
* V_8 += sizeof( V_18 ) ;
F_15 ( V_8 , V_9 , V_29 , V_17 ) ;
* V_8 += V_29 ;
if ( V_33 >= 2 ) {
F_15 ( V_8 , V_9 , V_36 , V_17 ) ;
V_37 = * V_8 ;
* V_8 += V_36 * sizeof( V_18 ) ;
} else {
V_36 = 0 ;
}
F_16 ( L_2 ,
V_4 + 1 , V_3 , V_28 , V_30 , V_31 ,
F_17 ( & V_35 . V_42 ) ,
F_18 ( V_7 ) ) ;
if ( V_30 < 0 || V_30 >= V_2 -> V_5 || V_7 <= 0 )
continue;
V_41 = & V_2 -> V_6 [ V_30 ] ;
V_41 -> V_28 = V_28 ;
V_41 -> V_7 = V_7 ;
V_41 -> V_35 = V_35 ;
V_41 -> V_43 = ( V_39 . V_44 != 0 ||
V_39 . V_45 != 0 ) ;
V_41 -> V_36 = V_36 ;
if ( V_36 ) {
V_41 -> V_46 = F_11 ( V_36 ,
sizeof( V_18 ) , V_15 ) ;
if ( V_41 -> V_46 == NULL )
goto V_27;
for ( V_11 = 0 ; V_11 < V_36 ; V_11 ++ )
V_41 -> V_46 [ V_11 ] =
F_9 ( & V_37 ) ;
} else {
V_41 -> V_46 = NULL ;
}
}
F_15 ( V_8 , V_9 , V_3 , V_17 ) ;
V_2 -> V_47 = V_3 ;
V_2 -> V_48 = F_11 ( V_3 , sizeof( V_19 ) , V_15 ) ;
if ( ! V_2 -> V_48 )
goto V_27;
F_8 ( V_8 , V_9 , sizeof( V_19 ) * ( V_3 + 1 ) , V_17 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 -> V_48 [ V_4 ] = F_10 ( V_8 ) ;
V_2 -> V_49 = F_10 ( V_8 ) ;
F_16 ( L_3 , V_2 -> V_20 ) ;
return V_2 ;
V_27:
V_12 = - V_16 ;
V_17:
F_19 ( L_4 ) ;
F_20 ( V_50 , L_5 ,
V_51 , 16 , 1 ,
V_10 , V_9 - V_10 , true ) ;
F_21 ( V_2 ) ;
return F_5 ( V_12 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
F_22 ( V_2 -> V_6 [ V_4 ] . V_46 ) ;
F_22 ( V_2 -> V_6 ) ;
F_22 ( V_2 -> V_48 ) ;
F_22 ( V_2 ) ;
}

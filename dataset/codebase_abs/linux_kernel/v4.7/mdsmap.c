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
T_1 V_14 , V_15 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_16 ) ;
if ( V_2 == NULL )
return F_5 ( - V_17 ) ;
F_6 ( V_8 , V_9 , 1 + 1 , V_18 ) ;
V_14 = F_7 ( V_8 ) ;
V_15 = F_7 ( V_8 ) ;
if ( V_14 >= 4 ) {
T_2 V_19 ;
F_8 ( V_8 , V_9 , V_19 , V_18 ) ;
if ( V_9 < * V_8 + V_19 )
goto V_18;
V_9 = * V_8 + V_19 ;
}
F_6 ( V_8 , V_9 , 8 * sizeof( T_2 ) + sizeof( V_20 ) , V_18 ) ;
V_2 -> V_21 = F_9 ( V_8 ) ;
V_2 -> V_22 = F_9 ( V_8 ) ;
V_2 -> V_23 = F_9 ( V_8 ) ;
V_2 -> V_24 = F_9 ( V_8 ) ;
V_2 -> V_25 = F_9 ( V_8 ) ;
V_2 -> V_26 = F_9 ( V_8 ) ;
V_2 -> V_27 = F_10 ( V_8 ) ;
V_2 -> V_5 = F_9 ( V_8 ) ;
V_2 -> V_6 = F_11 ( V_2 -> V_5 , sizeof( * V_2 -> V_6 ) , V_16 ) ;
if ( V_2 -> V_6 == NULL )
goto V_28;
V_3 = F_9 ( V_8 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_20 V_29 ;
T_2 V_30 ;
T_3 V_31 , V_32 , V_7 ;
V_20 V_33 ;
T_1 V_34 ;
void * V_35 = NULL ;
struct V_36 V_37 ;
T_2 V_38 ;
void * V_39 = NULL ;
struct V_40 V_41 ;
struct V_42 * V_43 ;
F_6 ( V_8 , V_9 , sizeof( V_20 ) + 1 , V_18 ) ;
V_29 = F_10 ( V_8 ) ;
V_34 = F_7 ( V_8 ) ;
if ( V_34 >= 4 ) {
T_2 V_44 ;
T_1 V_45 ;
F_6 ( V_8 , V_9 , 1 + sizeof( T_2 ) , V_18 ) ;
V_45 = F_7 ( V_8 ) ;
V_44 = F_9 ( V_8 ) ;
V_35 = * V_8 + V_44 ;
if ( V_35 > V_9 )
goto V_18;
}
F_6 ( V_8 , V_9 , sizeof( V_20 ) + sizeof( T_2 ) , V_18 ) ;
* V_8 += sizeof( V_20 ) ;
V_30 = F_9 ( V_8 ) ;
* V_8 += V_30 ;
F_6 ( V_8 , V_9 ,
4 * sizeof( T_2 ) + sizeof( V_20 ) +
sizeof( V_37 ) + sizeof( struct V_40 ) ,
V_18 ) ;
V_31 = F_9 ( V_8 ) ;
V_32 = F_9 ( V_8 ) ;
V_7 = F_9 ( V_8 ) ;
V_33 = F_10 ( V_8 ) ;
F_12 ( V_8 , & V_37 , sizeof( V_37 ) ) ;
F_13 ( & V_37 ) ;
F_12 ( V_8 , & V_41 , sizeof( V_41 ) ) ;
* V_8 += sizeof( T_2 ) ;
F_8 ( V_8 , V_9 , V_30 , V_18 ) ;
* V_8 += V_30 ;
if ( V_34 >= 2 ) {
F_8 ( V_8 , V_9 , V_38 , V_18 ) ;
V_39 = * V_8 ;
* V_8 += V_38 * sizeof( T_2 ) ;
} else {
V_38 = 0 ;
}
if ( V_35 && * V_8 != V_35 ) {
if ( * V_8 > V_35 )
goto V_18;
* V_8 = V_35 ;
}
F_14 ( L_1 ,
V_4 + 1 , V_3 , V_29 , V_31 , V_32 ,
F_15 ( & V_37 . V_46 ) ,
F_16 ( V_7 ) ) ;
if ( V_31 < 0 || V_31 >= V_2 -> V_5 || V_7 <= 0 )
continue;
V_43 = & V_2 -> V_6 [ V_31 ] ;
V_43 -> V_29 = V_29 ;
V_43 -> V_7 = V_7 ;
V_43 -> V_37 = V_37 ;
V_43 -> V_47 = ( V_41 . V_48 != 0 ||
V_41 . V_49 != 0 ) ;
V_43 -> V_38 = V_38 ;
if ( V_38 ) {
V_43 -> V_50 = F_11 ( V_38 ,
sizeof( T_2 ) , V_16 ) ;
if ( V_43 -> V_50 == NULL )
goto V_28;
for ( V_11 = 0 ; V_11 < V_38 ; V_11 ++ )
V_43 -> V_50 [ V_11 ] =
F_9 ( & V_39 ) ;
} else {
V_43 -> V_50 = NULL ;
}
}
F_8 ( V_8 , V_9 , V_3 , V_18 ) ;
V_2 -> V_51 = V_3 ;
V_2 -> V_52 = F_11 ( V_3 , sizeof( V_20 ) , V_16 ) ;
if ( ! V_2 -> V_52 )
goto V_28;
F_6 ( V_8 , V_9 , sizeof( V_20 ) * ( V_3 + 1 ) , V_18 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 -> V_52 [ V_4 ] = F_10 ( V_8 ) ;
V_2 -> V_53 = F_10 ( V_8 ) ;
* V_8 = V_9 ;
F_14 ( L_2 , V_2 -> V_21 ) ;
return V_2 ;
V_28:
V_12 = - V_17 ;
V_18:
F_17 ( L_3 ) ;
F_18 ( V_54 , L_4 ,
V_55 , 16 , 1 ,
V_10 , V_9 - V_10 , true ) ;
F_19 ( V_2 ) ;
return F_5 ( V_12 ) ;
}
void F_19 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
F_20 ( V_2 -> V_6 [ V_4 ] . V_50 ) ;
F_20 ( V_2 -> V_6 ) ;
F_20 ( V_2 -> V_52 ) ;
F_20 ( V_2 ) ;
}

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
static int F_3 ( void * * V_8 , void * V_9 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 3 ; V_4 ++ ) {
T_1 V_3 ;
F_4 ( V_8 , V_9 , sizeof( V_10 ) + sizeof( T_1 ) , V_11 ) ;
* V_8 += sizeof( V_10 ) ;
V_3 = F_5 ( V_8 ) ;
while ( V_3 -- > 0 ) {
T_1 V_12 ;
F_4 ( V_8 , V_9 , sizeof( V_10 ) + sizeof( T_1 ) ,
V_11 ) ;
* V_8 += sizeof( V_10 ) ;
V_12 = F_5 ( V_8 ) ;
F_4 ( V_8 , V_9 , V_12 , V_11 ) ;
* V_8 += V_12 ;
}
}
return 0 ;
V_11:
return - 1 ;
}
struct V_1 * F_6 ( void * * V_8 , void * V_9 )
{
struct V_1 * V_2 ;
const void * V_13 = * V_8 ;
int V_4 , V_14 , V_3 ;
int V_15 = - V_16 ;
T_2 V_17 , V_18 ;
T_3 V_19 ;
V_2 = F_7 ( sizeof( * V_2 ) , V_20 ) ;
if ( V_2 == NULL )
return F_8 ( - V_21 ) ;
F_4 ( V_8 , V_9 , 1 + 1 , V_11 ) ;
V_17 = F_9 ( V_8 ) ;
V_18 = F_9 ( V_8 ) ;
if ( V_17 >= 4 ) {
T_1 V_22 ;
F_10 ( V_8 , V_9 , V_22 , V_11 ) ;
if ( V_9 < * V_8 + V_22 )
goto V_11;
V_9 = * V_8 + V_22 ;
}
F_4 ( V_8 , V_9 , 8 * sizeof( T_1 ) + sizeof( V_10 ) , V_11 ) ;
V_2 -> V_23 = F_5 ( V_8 ) ;
V_2 -> V_24 = F_5 ( V_8 ) ;
V_2 -> V_25 = F_5 ( V_8 ) ;
V_2 -> V_26 = F_5 ( V_8 ) ;
V_2 -> V_27 = F_5 ( V_8 ) ;
V_2 -> V_28 = F_5 ( V_8 ) ;
V_2 -> V_29 = F_11 ( V_8 ) ;
V_2 -> V_5 = F_5 ( V_8 ) ;
V_2 -> V_6 = F_12 ( V_2 -> V_5 , sizeof( * V_2 -> V_6 ) , V_20 ) ;
if ( V_2 -> V_6 == NULL )
goto V_30;
V_3 = F_5 ( V_8 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_10 V_31 ;
T_1 V_32 ;
T_4 V_33 , V_34 , V_7 ;
V_10 V_35 ;
T_2 V_36 ;
void * V_37 = NULL ;
struct V_38 V_39 ;
T_1 V_40 ;
void * V_41 = NULL ;
struct V_42 V_43 ;
struct V_44 * V_45 ;
F_4 ( V_8 , V_9 , sizeof( V_10 ) + 1 , V_11 ) ;
V_31 = F_11 ( V_8 ) ;
V_36 = F_9 ( V_8 ) ;
if ( V_36 >= 4 ) {
T_1 V_46 ;
T_2 V_47 ;
F_4 ( V_8 , V_9 , 1 + sizeof( T_1 ) , V_11 ) ;
V_47 = F_9 ( V_8 ) ;
V_46 = F_5 ( V_8 ) ;
V_37 = * V_8 + V_46 ;
if ( V_37 > V_9 )
goto V_11;
}
F_4 ( V_8 , V_9 , sizeof( V_10 ) + sizeof( T_1 ) , V_11 ) ;
* V_8 += sizeof( V_10 ) ;
V_32 = F_5 ( V_8 ) ;
* V_8 += V_32 ;
F_4 ( V_8 , V_9 ,
4 * sizeof( T_1 ) + sizeof( V_10 ) +
sizeof( V_39 ) + sizeof( struct V_42 ) ,
V_11 ) ;
V_33 = F_5 ( V_8 ) ;
V_34 = F_5 ( V_8 ) ;
V_7 = F_5 ( V_8 ) ;
V_35 = F_11 ( V_8 ) ;
F_13 ( V_8 , & V_39 , sizeof( V_39 ) ) ;
F_14 ( & V_39 ) ;
F_13 ( V_8 , & V_43 , sizeof( V_43 ) ) ;
* V_8 += sizeof( T_1 ) ;
F_10 ( V_8 , V_9 , V_32 , V_11 ) ;
* V_8 += V_32 ;
if ( V_36 >= 2 ) {
F_10 ( V_8 , V_9 , V_40 , V_11 ) ;
V_41 = * V_8 ;
* V_8 += V_40 * sizeof( T_1 ) ;
} else {
V_40 = 0 ;
}
if ( V_37 && * V_8 != V_37 ) {
if ( * V_8 > V_37 )
goto V_11;
* V_8 = V_37 ;
}
F_15 ( L_1 ,
V_4 + 1 , V_3 , V_31 , V_33 , V_34 ,
F_16 ( & V_39 . V_48 ) ,
F_17 ( V_7 ) ) ;
if ( V_33 < 0 || V_33 >= V_2 -> V_5 || V_7 <= 0 )
continue;
V_45 = & V_2 -> V_6 [ V_33 ] ;
V_45 -> V_31 = V_31 ;
V_45 -> V_7 = V_7 ;
V_45 -> V_39 = V_39 ;
V_45 -> V_49 = ( V_43 . V_50 != 0 ||
V_43 . V_51 != 0 ) ;
V_45 -> V_40 = V_40 ;
if ( V_40 ) {
V_45 -> V_52 = F_12 ( V_40 ,
sizeof( T_1 ) , V_20 ) ;
if ( V_45 -> V_52 == NULL )
goto V_30;
for ( V_14 = 0 ; V_14 < V_40 ; V_14 ++ )
V_45 -> V_52 [ V_14 ] =
F_5 ( & V_41 ) ;
} else {
V_45 -> V_52 = NULL ;
}
}
F_10 ( V_8 , V_9 , V_3 , V_11 ) ;
V_2 -> V_53 = V_3 ;
V_2 -> V_54 = F_12 ( V_3 , sizeof( V_10 ) , V_20 ) ;
if ( ! V_2 -> V_54 )
goto V_30;
F_4 ( V_8 , V_9 , sizeof( V_10 ) * ( V_3 + 1 ) , V_11 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 -> V_54 [ V_4 ] = F_11 ( V_8 ) ;
V_2 -> V_55 = F_11 ( V_8 ) ;
V_2 -> V_56 = V_2 -> V_23 > 1 ;
V_19 = 1 ;
if ( V_17 >= 2 ) {
F_18 ( V_8 , V_9 , V_19 , V_57 ) ;
}
if ( V_19 >= 3 ) {
if ( F_3 ( V_8 , V_9 ) < 0 )
goto V_57;
}
if ( V_19 < 5 ) {
F_19 ( V_8 , V_9 , T_1 , V_57 ) ;
} else {
F_19 ( V_8 , V_9 , V_10 , V_57 ) ;
}
F_19 ( V_8 , V_9 , struct V_42 , V_57 ) ;
F_19 ( V_8 , V_9 , struct V_42 , V_57 ) ;
F_19 ( V_8 , V_9 , T_1 , V_57 ) ;
{
int V_58 = 0 ;
F_10 ( V_8 , V_9 , V_3 , V_57 ) ;
F_4 ( V_8 , V_9 , sizeof( T_1 ) * V_3 , V_57 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
T_4 V_33 = F_5 ( V_8 ) ;
if ( V_33 >= 0 && V_33 < V_2 -> V_5 ) {
if ( V_2 -> V_6 [ V_33 ] . V_49 )
V_58 ++ ;
}
}
V_2 -> V_59 = V_58 ;
}
F_20 ( V_8 , V_9 , T_1 , T_1 , V_57 ) ;
F_20 ( V_8 , V_9 , T_1 , V_10 , V_57 ) ;
F_21 ( V_8 , V_9 , T_1 , V_57 ) ;
F_21 ( V_8 , V_9 , T_1 , V_57 ) ;
if ( V_19 >= 4 ) {
F_19 ( V_8 , V_9 , T_1 , V_57 ) ;
}
if ( V_19 >= 6 ) {
F_19 ( V_8 , V_9 , T_2 , V_57 ) ;
F_19 ( V_8 , V_9 , T_2 , V_57 ) ;
}
if ( V_19 >= 7 ) {
F_19 ( V_8 , V_9 , T_2 , V_57 ) ;
}
if ( V_19 >= 8 ) {
T_1 V_60 ;
F_22 ( V_8 , V_9 , V_2 -> V_56 , V_57 ) ;
F_10 ( V_8 , V_9 , V_60 , V_57 ) ;
F_4 ( V_8 , V_9 , V_60 , V_57 ) ;
* V_8 += V_60 ;
}
if ( V_19 >= 9 ) {
T_5 V_61 ;
F_10 ( V_8 , V_9 , V_3 , V_57 ) ;
V_61 = sizeof( T_1 ) * V_3 ;
F_4 ( V_8 , V_9 , V_61 , V_57 ) ;
* V_8 += V_61 ;
V_2 -> V_62 = V_3 > 0 ;
} else {
V_2 -> V_62 = false ;
}
V_57:
* V_8 = V_9 ;
F_15 ( L_2 , V_2 -> V_23 ) ;
return V_2 ;
V_30:
V_15 = - V_21 ;
goto V_63;
V_11:
F_23 ( L_3 ) ;
F_24 ( V_64 , L_4 ,
V_65 , 16 , 1 ,
V_13 , V_9 - V_13 , true ) ;
V_63:
F_25 ( V_2 ) ;
return F_8 ( V_15 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
F_26 ( V_2 -> V_6 [ V_4 ] . V_52 ) ;
F_26 ( V_2 -> V_6 ) ;
F_26 ( V_2 -> V_54 ) ;
F_26 ( V_2 ) ;
}
bool F_27 ( struct V_1 * V_2 )
{
int V_4 , V_66 = 0 ;
if ( ! V_2 -> V_56 )
return false ;
if ( V_2 -> V_62 )
return false ;
if ( V_2 -> V_59 > 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_2 -> V_6 [ V_4 ] . V_7 == V_67 )
V_66 ++ ;
}
return V_66 > 0 ;
}

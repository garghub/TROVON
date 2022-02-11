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
V_2 -> V_30 = F_5 ( V_8 ) ;
V_2 -> V_5 = V_2 -> V_30 ;
V_2 -> V_6 = F_12 ( V_2 -> V_5 , sizeof( * V_2 -> V_6 ) , V_20 ) ;
if ( V_2 -> V_6 == NULL )
goto V_31;
V_3 = F_5 ( V_8 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_10 V_32 ;
T_1 V_33 ;
T_4 V_34 , V_35 , V_7 ;
V_10 V_36 ;
T_2 V_37 ;
void * V_38 = NULL ;
struct V_39 V_40 ;
T_1 V_41 ;
void * V_42 = NULL ;
struct V_43 V_44 ;
struct V_45 * V_46 ;
F_4 ( V_8 , V_9 , sizeof( V_10 ) + 1 , V_11 ) ;
V_32 = F_11 ( V_8 ) ;
V_37 = F_9 ( V_8 ) ;
if ( V_37 >= 4 ) {
T_1 V_47 ;
T_2 V_48 ;
F_4 ( V_8 , V_9 , 1 + sizeof( T_1 ) , V_11 ) ;
V_48 = F_9 ( V_8 ) ;
V_47 = F_5 ( V_8 ) ;
V_38 = * V_8 + V_47 ;
if ( V_38 > V_9 )
goto V_11;
}
F_4 ( V_8 , V_9 , sizeof( V_10 ) + sizeof( T_1 ) , V_11 ) ;
* V_8 += sizeof( V_10 ) ;
V_33 = F_5 ( V_8 ) ;
* V_8 += V_33 ;
F_4 ( V_8 , V_9 ,
4 * sizeof( T_1 ) + sizeof( V_10 ) +
sizeof( V_40 ) + sizeof( struct V_43 ) ,
V_11 ) ;
V_34 = F_5 ( V_8 ) ;
V_35 = F_5 ( V_8 ) ;
V_7 = F_5 ( V_8 ) ;
V_36 = F_11 ( V_8 ) ;
F_13 ( V_8 , & V_40 , sizeof( V_40 ) ) ;
F_14 ( & V_40 ) ;
F_13 ( V_8 , & V_44 , sizeof( V_44 ) ) ;
* V_8 += sizeof( T_1 ) ;
F_10 ( V_8 , V_9 , V_33 , V_11 ) ;
* V_8 += V_33 ;
if ( V_37 >= 2 ) {
F_10 ( V_8 , V_9 , V_41 , V_11 ) ;
V_42 = * V_8 ;
* V_8 += V_41 * sizeof( T_1 ) ;
} else {
V_41 = 0 ;
}
if ( V_38 && * V_8 != V_38 ) {
if ( * V_8 > V_38 )
goto V_11;
* V_8 = V_38 ;
}
F_15 ( L_1 ,
V_4 + 1 , V_3 , V_32 , V_34 , V_35 ,
F_16 ( & V_40 . V_49 ) ,
F_17 ( V_7 ) ) ;
if ( V_34 < 0 || V_7 <= 0 )
continue;
if ( V_34 >= V_2 -> V_5 ) {
int V_50 = F_18 ( V_34 + 1 , V_2 -> V_5 * 2 ) ;
void * V_51 = F_19 ( V_2 -> V_6 ,
V_50 * sizeof( * V_2 -> V_6 ) ,
V_20 | V_52 ) ;
if ( ! V_51 )
goto V_31;
V_2 -> V_6 = V_51 ;
V_2 -> V_5 = V_50 ;
}
V_46 = & V_2 -> V_6 [ V_34 ] ;
V_46 -> V_32 = V_32 ;
V_46 -> V_7 = V_7 ;
V_46 -> V_40 = V_40 ;
V_46 -> V_53 = ( V_44 . V_54 != 0 ||
V_44 . V_55 != 0 ) ;
V_46 -> V_41 = V_41 ;
if ( V_41 ) {
V_46 -> V_56 = F_12 ( V_41 ,
sizeof( T_1 ) , V_20 ) ;
if ( V_46 -> V_56 == NULL )
goto V_31;
for ( V_14 = 0 ; V_14 < V_41 ; V_14 ++ )
V_46 -> V_56 [ V_14 ] =
F_5 ( & V_42 ) ;
} else {
V_46 -> V_56 = NULL ;
}
}
if ( V_2 -> V_5 > V_2 -> V_30 ) {
for ( V_4 = V_2 -> V_5 ; V_4 >= V_2 -> V_30 ; V_4 -- ) {
if ( V_4 == 0 || V_2 -> V_6 [ V_4 - 1 ] . V_7 > 0 )
break;
}
V_2 -> V_5 = V_4 ;
}
F_10 ( V_8 , V_9 , V_3 , V_11 ) ;
V_2 -> V_57 = V_3 ;
V_2 -> V_58 = F_12 ( V_3 , sizeof( V_10 ) , V_20 ) ;
if ( ! V_2 -> V_58 )
goto V_31;
F_4 ( V_8 , V_9 , sizeof( V_10 ) * ( V_3 + 1 ) , V_11 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 -> V_58 [ V_4 ] = F_11 ( V_8 ) ;
V_2 -> V_59 = F_11 ( V_8 ) ;
V_2 -> V_60 = V_2 -> V_23 > 1 ;
V_19 = 1 ;
if ( V_17 >= 2 ) {
F_20 ( V_8 , V_9 , V_19 , V_61 ) ;
}
if ( V_19 >= 3 ) {
if ( F_3 ( V_8 , V_9 ) < 0 )
goto V_61;
}
if ( V_19 < 5 ) {
F_21 ( V_8 , V_9 , T_1 , V_61 ) ;
} else {
F_21 ( V_8 , V_9 , V_10 , V_61 ) ;
}
F_21 ( V_8 , V_9 , struct V_43 , V_61 ) ;
F_21 ( V_8 , V_9 , struct V_43 , V_61 ) ;
F_21 ( V_8 , V_9 , T_1 , V_61 ) ;
{
int V_62 = 0 ;
F_10 ( V_8 , V_9 , V_3 , V_61 ) ;
F_4 ( V_8 , V_9 , sizeof( T_1 ) * V_3 , V_61 ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
T_4 V_34 = F_5 ( V_8 ) ;
if ( V_34 >= 0 && V_34 < V_2 -> V_5 ) {
if ( V_2 -> V_6 [ V_34 ] . V_53 )
V_62 ++ ;
}
}
V_2 -> V_63 = V_62 ;
if ( V_3 > V_2 -> V_5 ) {
void * V_51 = F_19 ( V_2 -> V_6 ,
V_3 * sizeof( * V_2 -> V_6 ) ,
V_20 | V_52 ) ;
if ( ! V_51 )
goto V_31;
V_2 -> V_6 = V_51 ;
}
V_2 -> V_5 = V_3 ;
}
F_22 ( V_8 , V_9 , T_1 , T_1 , V_61 ) ;
F_22 ( V_8 , V_9 , T_1 , V_10 , V_61 ) ;
F_23 ( V_8 , V_9 , T_1 , V_61 ) ;
F_23 ( V_8 , V_9 , T_1 , V_61 ) ;
if ( V_19 >= 4 ) {
F_21 ( V_8 , V_9 , T_1 , V_61 ) ;
}
if ( V_19 >= 6 ) {
F_21 ( V_8 , V_9 , T_2 , V_61 ) ;
F_21 ( V_8 , V_9 , T_2 , V_61 ) ;
}
if ( V_19 >= 7 ) {
F_21 ( V_8 , V_9 , T_2 , V_61 ) ;
}
if ( V_19 >= 8 ) {
T_1 V_64 ;
F_24 ( V_8 , V_9 , V_2 -> V_60 , V_61 ) ;
F_10 ( V_8 , V_9 , V_64 , V_61 ) ;
F_4 ( V_8 , V_9 , V_64 , V_61 ) ;
* V_8 += V_64 ;
}
if ( V_19 >= 9 ) {
T_5 V_65 ;
F_10 ( V_8 , V_9 , V_3 , V_61 ) ;
V_65 = sizeof( T_1 ) * V_3 ;
F_4 ( V_8 , V_9 , V_65 , V_61 ) ;
* V_8 += V_65 ;
V_2 -> V_66 = V_3 > 0 ;
} else {
V_2 -> V_66 = false ;
}
V_61:
* V_8 = V_9 ;
F_15 ( L_2 , V_2 -> V_23 ) ;
return V_2 ;
V_31:
V_15 = - V_21 ;
goto V_67;
V_11:
F_25 ( L_3 ) ;
F_26 ( V_68 , L_4 ,
V_69 , 16 , 1 ,
V_13 , V_9 - V_13 , true ) ;
V_67:
F_27 ( V_2 ) ;
return F_8 ( V_15 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
F_28 ( V_2 -> V_6 [ V_4 ] . V_56 ) ;
F_28 ( V_2 -> V_6 ) ;
F_28 ( V_2 -> V_58 ) ;
F_28 ( V_2 ) ;
}
bool F_29 ( struct V_1 * V_2 )
{
int V_4 , V_70 = 0 ;
if ( ! V_2 -> V_60 )
return false ;
if ( V_2 -> V_66 )
return false ;
if ( V_2 -> V_63 > 0 )
return false ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_2 -> V_6 [ V_4 ] . V_7 == V_71 )
V_70 ++ ;
}
return V_70 > 0 ;
}

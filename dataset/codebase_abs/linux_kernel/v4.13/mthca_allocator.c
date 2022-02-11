T_1 F_1 ( struct F_1 * V_1 )
{
unsigned long V_2 ;
T_1 V_3 ;
F_2 ( & V_1 -> V_4 , V_2 ) ;
V_3 = F_3 ( V_1 -> V_5 , V_1 -> V_6 , V_1 -> V_7 ) ;
if ( V_3 >= V_1 -> V_6 ) {
V_1 -> V_8 = ( V_1 -> V_8 + V_1 -> V_6 ) & V_1 -> V_9 ;
V_3 = F_4 ( V_1 -> V_5 , V_1 -> V_6 ) ;
}
if ( V_3 < V_1 -> V_6 ) {
F_5 ( V_3 , V_1 -> V_5 ) ;
V_3 |= V_1 -> V_8 ;
} else
V_3 = - 1 ;
F_6 ( & V_1 -> V_4 , V_2 ) ;
return V_3 ;
}
void F_7 ( struct F_1 * V_1 , T_1 V_3 )
{
unsigned long V_2 ;
V_3 &= V_1 -> V_6 - 1 ;
F_2 ( & V_1 -> V_4 , V_2 ) ;
F_8 ( V_3 , V_1 -> V_5 ) ;
V_1 -> V_7 = F_9 ( V_1 -> V_7 , V_3 ) ;
V_1 -> V_8 = ( V_1 -> V_8 + V_1 -> V_6 ) & V_1 -> V_9 ;
F_6 ( & V_1 -> V_4 , V_2 ) ;
}
int F_10 ( struct F_1 * V_1 , T_1 V_10 , T_1 V_9 ,
T_1 V_11 )
{
int V_12 ;
if ( V_10 != 1 << ( F_11 ( V_10 ) - 1 ) )
return - V_13 ;
V_1 -> V_7 = 0 ;
V_1 -> V_8 = 0 ;
V_1 -> V_6 = V_10 ;
V_1 -> V_9 = V_9 ;
F_12 ( & V_1 -> V_4 ) ;
V_1 -> V_5 = F_13 ( F_14 ( V_10 ) * sizeof ( long ) ,
V_14 ) ;
if ( ! V_1 -> V_5 )
return - V_15 ;
F_15 ( V_1 -> V_5 , V_10 ) ;
for ( V_12 = 0 ; V_12 < V_11 ; ++ V_12 )
F_5 ( V_12 , V_1 -> V_5 ) ;
return 0 ;
}
void F_16 ( struct F_1 * V_1 )
{
F_17 ( V_1 -> V_5 ) ;
}
void * F_18 ( struct V_16 * V_17 , int V_18 )
{
int V_19 = ( V_18 * sizeof ( void * ) ) >> V_20 ;
if ( V_17 -> V_21 [ V_19 ] . V_22 )
return V_17 -> V_21 [ V_19 ] . V_22 [ V_18 & V_23 ] ;
else
return NULL ;
}
int F_19 ( struct V_16 * V_17 , int V_18 , void * V_24 )
{
int V_19 = ( V_18 * sizeof ( void * ) ) >> V_20 ;
if ( ! V_17 -> V_21 [ V_19 ] . V_22 )
V_17 -> V_21 [ V_19 ] . V_22 = ( void * * ) F_20 ( V_25 ) ;
if ( ! V_17 -> V_21 [ V_19 ] . V_22 )
return - V_15 ;
V_17 -> V_21 [ V_19 ] . V_22 [ V_18 & V_23 ] = V_24 ;
++ V_17 -> V_21 [ V_19 ] . V_26 ;
return 0 ;
}
void F_21 ( struct V_16 * V_17 , int V_18 )
{
int V_19 = ( V_18 * sizeof ( void * ) ) >> V_20 ;
if ( -- V_17 -> V_21 [ V_19 ] . V_26 == 0 ) {
F_22 ( ( unsigned long ) V_17 -> V_21 [ V_19 ] . V_22 ) ;
V_17 -> V_21 [ V_19 ] . V_22 = NULL ;
} else
V_17 -> V_21 [ V_19 ] . V_22 [ V_18 & V_23 ] = NULL ;
if ( V_17 -> V_21 [ V_19 ] . V_26 < 0 )
F_23 ( L_1 ,
V_17 , V_18 , V_19 , V_17 -> V_21 [ V_19 ] . V_26 ) ;
}
int F_24 ( struct V_16 * V_17 , int V_27 )
{
int V_28 = ( V_27 * sizeof ( void * ) + V_29 - 1 ) / V_29 ;
int V_12 ;
V_17 -> V_21 = F_13 ( V_28 * sizeof * V_17 -> V_21 , V_14 ) ;
if ( ! V_17 -> V_21 )
return - V_15 ;
for ( V_12 = 0 ; V_12 < V_28 ; ++ V_12 ) {
V_17 -> V_21 [ V_12 ] . V_22 = NULL ;
V_17 -> V_21 [ V_12 ] . V_26 = 0 ;
}
return 0 ;
}
void F_25 ( struct V_16 * V_17 , int V_27 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < ( V_27 * sizeof ( void * ) + V_29 - 1 ) / V_29 ; ++ V_12 )
F_22 ( ( unsigned long ) V_17 -> V_21 [ V_12 ] . V_22 ) ;
F_17 ( V_17 -> V_21 ) ;
}
int F_26 ( struct V_30 * V_31 , int V_32 , int V_33 ,
union V_34 * V_35 , int * V_36 , struct V_37 * V_38 ,
int V_39 , struct V_40 * V_41 )
{
int V_42 = - V_15 ;
int V_43 , V_44 ;
T_2 * V_45 = NULL ;
T_3 V_46 ;
int V_12 ;
if ( V_32 <= V_33 ) {
* V_36 = 1 ;
V_43 = 1 ;
V_44 = F_27 ( V_32 ) + V_20 ;
V_35 -> V_47 . V_35 = F_28 ( & V_31 -> V_48 -> V_31 ,
V_32 , & V_46 , V_14 ) ;
if ( ! V_35 -> V_47 . V_35 )
return - V_15 ;
F_29 ( & V_35 -> V_47 , V_49 , V_46 ) ;
memset ( V_35 -> V_47 . V_35 , 0 , V_32 ) ;
while ( V_46 & ( ( 1 << V_44 ) - 1 ) ) {
-- V_44 ;
V_43 *= 2 ;
}
V_45 = F_13 ( V_43 * sizeof *V_45 , V_14 ) ;
if ( ! V_45 )
goto V_50;
for ( V_12 = 0 ; V_12 < V_43 ; ++ V_12 )
V_45 [ V_12 ] = V_46 + V_12 * ( 1 << V_44 ) ;
} else {
* V_36 = 0 ;
V_43 = ( V_32 + V_29 - 1 ) / V_29 ;
V_44 = V_20 ;
V_45 = F_13 ( V_43 * sizeof *V_45 , V_14 ) ;
if ( ! V_45 )
return - V_15 ;
V_35 -> V_21 = F_13 ( V_43 * sizeof * V_35 -> V_21 ,
V_14 ) ;
if ( ! V_35 -> V_21 )
goto V_51;
for ( V_12 = 0 ; V_12 < V_43 ; ++ V_12 )
V_35 -> V_21 [ V_12 ] . V_35 = NULL ;
for ( V_12 = 0 ; V_12 < V_43 ; ++ V_12 ) {
V_35 -> V_21 [ V_12 ] . V_35 =
F_28 ( & V_31 -> V_48 -> V_31 , V_29 ,
& V_46 , V_14 ) ;
if ( ! V_35 -> V_21 [ V_12 ] . V_35 )
goto V_50;
V_45 [ V_12 ] = V_46 ;
F_29 ( & V_35 -> V_21 [ V_12 ] , V_49 , V_46 ) ;
F_30 ( V_35 -> V_21 [ V_12 ] . V_35 ) ;
}
}
V_42 = F_31 ( V_31 , V_38 -> V_52 ,
V_45 , V_44 , V_43 ,
0 , V_32 ,
V_53 |
( V_39 ? V_54 : 0 ) ,
V_41 ) ;
if ( V_42 )
goto V_50;
F_17 ( V_45 ) ;
return 0 ;
V_50:
F_32 ( V_31 , V_32 , V_35 , * V_36 , NULL ) ;
V_51:
F_17 ( V_45 ) ;
return V_42 ;
}
void F_32 ( struct V_30 * V_31 , int V_32 , union V_34 * V_35 ,
int V_36 , struct V_40 * V_41 )
{
int V_12 ;
if ( V_41 )
F_33 ( V_31 , V_41 ) ;
if ( V_36 )
F_34 ( & V_31 -> V_48 -> V_31 , V_32 , V_35 -> V_47 . V_35 ,
F_35 ( & V_35 -> V_47 , V_49 ) ) ;
else {
for ( V_12 = 0 ; V_12 < ( V_32 + V_29 - 1 ) / V_29 ; ++ V_12 )
F_34 ( & V_31 -> V_48 -> V_31 , V_29 ,
V_35 -> V_21 [ V_12 ] . V_35 ,
F_35 ( & V_35 -> V_21 [ V_12 ] ,
V_49 ) ) ;
F_17 ( V_35 -> V_21 ) ;
}
}

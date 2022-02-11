static void F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * V_5 , int V_6 )
{
int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_3 ; V_7 ++ ) {
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
if ( V_2 [ V_7 ] . V_9 == V_5 [ V_8 ] . V_10 )
break;
if ( V_8 == V_6 )
F_2 ( L_1 ) ;
V_2 [ V_7 ] . V_9 = V_5 [ V_8 ] . V_11 ;
V_2 [ V_7 ] . V_12 -= V_5 [ V_8 ] . V_13 ;
V_2 [ V_7 ] . V_12 += V_5 [ V_8 ] . V_14 ;
}
}
static void F_3 ( struct V_4 * V_15 , int V_16 ,
struct V_4 * V_17 , int V_18 )
{
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ ) {
for ( V_20 = 0 ; V_20 < V_18 ; V_20 ++ )
if ( V_15 [ V_19 ] . V_11 == V_17 [ V_20 ] . V_10 &&
V_15 [ V_19 ] . V_14 >= V_17 [ V_20 ] . V_13 &&
V_17 [ V_20 ] . V_13 + V_17 [ V_20 ] . V_21 - V_15 [ V_19 ] . V_14 > 0U )
break;
if ( V_20 == V_18 )
F_2 ( L_2 ) ;
else if ( V_15 [ V_19 ] . V_14 + V_15 [ V_19 ] . V_21 > V_17 [ V_20 ] . V_13 + V_17 [ V_20 ] . V_21 )
V_15 [ V_19 ] . V_21 = V_17 [ V_20 ] . V_13 + V_17 [ V_20 ] . V_21 - V_15 [ V_19 ] . V_14 ;
V_15 [ V_19 ] . V_11 = V_17 [ V_20 ] . V_11 ;
V_15 [ V_19 ] . V_14 += V_17 [ V_20 ] . V_14 ;
}
}
void F_4 ( struct V_1 * V_22 , int V_3 )
{
if ( V_23 )
F_1 ( V_22 , V_3 , V_24 , V_23 ) ;
}
void T_1 F_5 ( void )
{
T_2 V_25 , V_26 ;
int V_27 ;
V_23 = 0 ;
V_25 = F_6 ( V_28 ) ;
V_26 = F_7 ( V_25 , L_3 ) ;
if ( V_26 ) {
V_27 = F_8 ( V_26 , L_4 ,
( char * ) V_24 ,
sizeof( V_24 ) ) ;
if ( V_27 != - 1 )
V_23 = ( V_27 / sizeof( struct V_4 ) ) ;
}
if ( V_23 )
F_2 ( L_5 , V_23 ) ;
}
void F_9 ( T_2 V_25 , T_2 V_29 ,
struct V_1 * V_22 , int V_3 )
{
int V_27 ;
int V_30 ;
struct V_4 V_31 [ V_32 ] ;
V_27 = F_8 ( V_25 , L_4 ,
( char * ) V_31 ,
sizeof( V_31 ) ) ;
if ( V_27 != - 1 ) {
V_30 = ( V_27 / sizeof( struct V_4 ) ) ;
if ( V_29 ) {
struct V_4 V_33 [ V_32 ] ;
int V_34 ;
V_27 = F_8 ( V_29 , L_4 ,
( char * ) V_33 ,
sizeof( V_33 ) ) ;
if ( V_27 != - 1 ) {
V_34 = ( V_27 / sizeof( struct V_4 ) ) ;
F_3 ( V_31 , V_30 , V_33 , V_34 ) ;
}
}
F_1 ( V_22 , V_3 , V_31 , V_30 ) ;
}
}

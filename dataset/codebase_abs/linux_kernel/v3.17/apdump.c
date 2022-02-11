T_1 F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 ) ) {
if ( ! F_3 ( V_2 -> V_3 ) ) {
F_4 ( L_1 ,
* ( V_4 * ) V_2 -> V_3 ) ;
return ( FALSE ) ;
}
if ( V_2 -> V_5 < sizeof( struct V_1 ) ) {
F_4 ( L_2 ,
V_2 -> V_5 ) ;
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
T_2 V_6 ;
struct V_7 * V_8 ;
if ( F_2 ( V_2 -> V_3 ) ) {
V_8 = F_6 ( struct V_7 , V_2 ) ;
V_6 = F_7 ( V_8 ) ;
} else {
V_6 = F_8 ( V_2 , V_2 -> V_5 ) ;
}
if ( F_9 ( V_6 ) ) {
F_4 ( L_3 ,
V_2 -> V_3 ) ;
}
return ( V_9 ) ;
}
V_4 F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
if ( ! F_1 ( V_2 ) ) {
return ( 0 ) ;
}
if ( F_2 ( V_2 -> V_3 ) ) {
V_8 = F_6 ( struct V_7 , V_2 ) ;
return ( V_8 -> V_5 ) ;
}
return ( V_2 -> V_5 ) ;
}
static int
F_11 ( struct V_1 * V_2 ,
V_4 V_10 , T_3 V_11 )
{
V_4 V_12 ;
V_12 = F_10 ( V_2 ) ;
if ( V_13 ) {
F_12 ( V_11 , V_2 ) ;
return ( 0 ) ;
}
if ( V_14 ) {
return ( F_13 ( V_2 , V_10 ) ) ;
}
F_14 ( V_15 , L_4 ,
V_2 -> V_3 , F_15 ( V_11 ) ) ;
F_16 ( V_15 ,
F_6 ( T_1 , V_2 ) , V_12 ,
V_16 , 0 ) ;
F_14 ( V_15 , L_5 ) ;
return ( 0 ) ;
}
int F_17 ( void )
{
struct V_1 * V_2 ;
V_4 V_10 = 0 ;
T_3 V_11 ;
T_2 V_6 ;
int V_17 ;
V_4 V_18 ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_6 =
F_18 ( V_18 , & V_2 , & V_10 , & V_11 ) ;
if ( F_9 ( V_6 ) ) {
if ( V_6 == V_20 ) {
return ( 0 ) ;
} else if ( V_18 == 0 ) {
F_4
( L_6 ,
F_19 ( V_6 ) ) ;
return ( - 1 ) ;
} else {
F_4
( L_7 ,
V_18 , F_19 ( V_6 ) ) ;
continue;
}
}
V_17 = F_11 ( V_2 , V_10 , V_11 ) ;
F_20 ( V_2 ) ;
if ( V_17 ) {
break;
}
}
return ( - 1 ) ;
}
int F_21 ( char * V_21 )
{
T_3 V_11 ;
struct V_1 * V_2 ;
T_2 V_6 ;
int V_17 ;
T_4 V_22 ;
V_6 = F_22 ( V_21 , 0 , & V_22 ) ;
if ( F_9 ( V_6 ) ) {
F_4 ( L_8 ,
V_21 ) ;
return ( - 1 ) ;
}
V_11 = ( T_3 ) V_22 ;
V_6 = F_23 ( V_11 , & V_2 ) ;
if ( F_9 ( V_6 ) ) {
F_4 ( L_9 ,
F_15 ( V_11 ) ,
F_19 ( V_6 ) ) ;
return ( - 1 ) ;
}
V_17 = F_11 ( V_2 , 0 , V_11 ) ;
F_20 ( V_2 ) ;
return ( V_17 ) ;
}
int F_24 ( char * V_3 )
{
char V_23 [ V_24 + 1 ] ;
V_4 V_10 ;
struct V_1 * V_2 ;
T_3 V_11 ;
T_2 V_6 ;
int V_17 ;
if ( F_25 ( V_3 ) != V_24 ) {
F_4
( L_10 ,
V_3 ) ;
return ( - 1 ) ;
}
F_26 ( V_23 , V_3 ) ;
F_27 ( V_23 ) ;
if ( F_28 ( V_23 , L_11 ) ) {
F_26 ( V_23 , V_25 ) ;
} else if ( F_28 ( V_23 , L_12 ) ) {
F_26 ( V_23 , V_26 ) ;
}
for ( V_10 = 0 ; V_10 < V_19 ; V_10 ++ ) {
V_6 = F_29 ( V_23 , V_10 ,
& V_2 , & V_11 ) ;
if ( F_9 ( V_6 ) ) {
if ( V_6 == V_20 ) {
return ( 0 ) ;
}
F_4
( L_13 ,
V_23 , F_19 ( V_6 ) ) ;
return ( - 1 ) ;
}
V_17 = F_11 ( V_2 , V_10 , V_11 ) ;
F_20 ( V_2 ) ;
if ( V_17 ) {
break;
}
}
return ( - 1 ) ;
}
int F_30 ( char * V_27 )
{
struct V_1 * V_2 ;
V_4 V_28 = 0 ;
int V_17 = - 1 ;
V_2 = F_31 ( V_27 , & V_28 ) ;
if ( ! V_2 ) {
return ( - 1 ) ;
}
if ( V_2 -> V_5 > V_28 ) {
F_4
( L_14 ,
V_2 -> V_5 , V_28 , V_27 ) ;
goto exit;
}
if ( V_29 ) {
F_4
( L_15 ,
V_27 , V_2 -> V_3 , V_28 , V_28 ) ;
}
V_17 = F_11 ( V_2 , 0 , 0 ) ;
exit:
F_20 ( V_2 ) ;
return ( V_17 ) ;
}

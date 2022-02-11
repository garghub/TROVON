T_1 F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 -> V_3 ) ) {
if ( ! F_3 ( V_2 -> V_3 ) ) {
fprintf ( V_4 ,
L_1 ,
* ( V_5 * ) V_2 -> V_3 ) ;
return ( FALSE ) ;
}
if ( V_2 -> V_6 < sizeof( struct V_1 ) ) {
fprintf ( V_4 , L_2 ,
V_2 -> V_6 ) ;
return ( FALSE ) ;
}
}
return ( TRUE ) ;
}
T_1 F_4 ( struct V_1 * V_2 )
{
T_2 V_7 ;
struct V_8 * V_9 ;
if ( F_2 ( V_2 -> V_3 ) ) {
V_9 = F_5 ( struct V_8 , V_2 ) ;
V_7 = F_6 ( V_9 ) ;
} else {
V_7 = F_7 ( V_2 , V_2 -> V_6 ) ;
}
if ( F_8 ( V_7 ) ) {
fprintf ( V_4 , L_3 ,
V_2 -> V_3 ) ;
}
return ( V_10 ) ;
}
V_5 F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
if ( ! F_1 ( V_2 ) ) {
return ( 0 ) ;
}
if ( F_2 ( V_2 -> V_3 ) ) {
V_9 = F_5 ( struct V_8 , V_2 ) ;
return ( F_10 ( V_9 ) ) ;
}
return ( V_2 -> V_6 ) ;
}
static int
F_11 ( struct V_1 * V_2 ,
V_5 V_11 , T_3 V_12 )
{
V_5 V_13 ;
V_13 = F_9 ( V_2 ) ;
if ( V_14 ) {
F_12 ( V_12 , V_2 ) ;
return ( 0 ) ;
}
if ( V_15 ) {
return ( F_13 ( V_2 , V_11 ) ) ;
}
fprintf ( V_16 , L_4 ,
V_2 -> V_3 , F_14 ( V_12 ) ) ;
F_15 ( V_16 ,
F_5 ( T_1 , V_2 ) , V_13 ,
V_17 , 0 ) ;
fprintf ( V_16 , L_5 ) ;
return ( 0 ) ;
}
int F_16 ( void )
{
struct V_1 * V_2 ;
V_5 V_11 = 0 ;
T_3 V_12 ;
T_2 V_7 ;
int V_18 ;
V_5 V_19 ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ ) {
V_7 =
F_17 ( V_19 , & V_2 , & V_11 , & V_12 ) ;
if ( F_8 ( V_7 ) ) {
if ( V_7 == V_21 ) {
return ( 0 ) ;
} else if ( V_19 == 0 ) {
fprintf ( V_4 ,
L_6 ,
F_18 ( V_7 ) ) ;
return ( - 1 ) ;
} else {
fprintf ( V_4 ,
L_7 ,
V_19 , F_18 ( V_7 ) ) ;
continue;
}
}
V_18 = F_11 ( V_2 , V_11 , V_12 ) ;
F_19 ( V_2 ) ;
if ( V_18 ) {
break;
}
}
return ( - 1 ) ;
}
int F_20 ( char * V_22 )
{
T_3 V_12 ;
struct V_1 * V_2 ;
T_2 V_7 ;
int V_18 ;
T_4 V_23 ;
V_7 = F_21 ( V_22 , V_24 ,
& V_23 ) ;
if ( F_8 ( V_7 ) ) {
fprintf ( V_4 , L_8 ,
V_22 ) ;
return ( - 1 ) ;
}
V_12 = ( T_3 ) V_23 ;
V_7 = F_22 ( V_12 , & V_2 ) ;
if ( F_8 ( V_7 ) ) {
fprintf ( V_4 , L_9 ,
F_14 ( V_12 ) ,
F_18 ( V_7 ) ) ;
return ( - 1 ) ;
}
V_18 = F_11 ( V_2 , 0 , V_12 ) ;
F_19 ( V_2 ) ;
return ( V_18 ) ;
}
int F_23 ( char * V_3 )
{
char V_25 [ V_26 + 1 ] ;
V_5 V_11 ;
struct V_1 * V_2 ;
T_3 V_12 ;
T_2 V_7 ;
int V_18 ;
if ( strlen ( V_3 ) != V_26 ) {
fprintf ( V_4 ,
L_10 ,
V_3 ) ;
return ( - 1 ) ;
}
strcpy ( V_25 , V_3 ) ;
F_24 ( V_25 ) ;
if ( F_25 ( V_25 , L_11 ) ) {
strcpy ( V_25 , V_27 ) ;
} else if ( F_25 ( V_25 , L_12 ) ) {
strcpy ( V_25 , V_28 ) ;
}
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ ) {
V_7 = F_26 ( V_25 , V_11 ,
& V_2 , & V_12 ) ;
if ( F_8 ( V_7 ) ) {
if ( V_7 == V_21 ) {
return ( 0 ) ;
}
fprintf ( V_4 ,
L_13 ,
V_25 , F_18 ( V_7 ) ) ;
return ( - 1 ) ;
}
V_18 = F_11 ( V_2 , V_11 , V_12 ) ;
F_19 ( V_2 ) ;
if ( V_18 ) {
break;
}
}
return ( - 1 ) ;
}
int F_27 ( char * V_29 )
{
struct V_1 * V_2 ;
V_5 V_30 = 0 ;
int V_18 = - 1 ;
V_2 = F_28 ( V_29 , & V_30 ) ;
if ( ! V_2 ) {
return ( - 1 ) ;
}
if ( ! F_3 ( V_2 -> V_3 ) ) {
fprintf ( V_4 ,
L_14 ,
V_29 ) ;
}
if ( V_2 -> V_6 > V_30 ) {
fprintf ( V_4 ,
L_15 ,
V_2 -> V_6 , V_30 , V_29 ) ;
goto exit;
}
if ( V_31 ) {
fprintf ( V_4 ,
L_16 ,
V_29 , V_2 -> V_3 , V_30 , V_30 ) ;
}
V_18 = F_11 ( V_2 , 0 , 0 ) ;
exit:
F_19 ( V_2 ) ;
return ( V_18 ) ;
}

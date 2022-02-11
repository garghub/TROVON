static int F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
int V_5 ;
for( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
V_4 += sprintf ( V_3 + V_4 , L_1 ,
V_2 ? V_2 -> V_6 [ V_5 ] : 0xff ) ;
V_4 += sprintf ( V_3 + V_4 , L_2 , V_2 ? V_2 -> V_7 : L_3 ) ;
return V_4 ;
}
static int F_2 ( char * V_3 , char * * V_8 , T_1 V_9 ,
int V_10 , int * V_11 , void * V_12 )
{
int V_13 , V_4 = 0 ;
if( V_14 ) {
struct V_1 * V_2 ;
for( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
V_2 = F_3 ( V_13 ) ;
V_4 += sprintf ( V_3 + V_4 , L_4 , V_13 + 1 ) ;
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
}
V_2 = F_3 ( V_16 ) ;
V_4 += sprintf ( V_3 + V_4 , L_5 ) ;
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
V_2 = F_3 ( V_17 ) ;
V_4 += sprintf ( V_3 + V_4 , L_6 ) ;
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
V_2 = F_3 ( V_18 ) ;
V_4 += sprintf ( V_3 + V_4 , L_7 ) ;
V_4 = F_1 ( V_2 , V_3 , V_4 ) ;
} else {
}
if ( V_4 <= V_9 + V_10 ) * V_11 = 1 ;
* V_8 = V_3 + V_9 ;
V_4 -= V_9 ;
if ( V_4 > V_10 ) V_4 = V_10 ;
if ( V_4 < 0 ) V_4 = 0 ;
return V_4 ;
}
static int F_4 ( char * V_19 , struct V_1 * V_2 )
{
int V_4 = 0 , V_13 ;
int V_20 = V_2 -> V_20 ;
if( V_20 < V_15 ) {
V_4 += sprintf ( V_19 + V_4 , L_8 , V_20 + 1 ) ;
} else if( V_20 == V_17 ) {
V_4 += sprintf ( V_19 + V_4 , L_9 ) ;
} else if( V_20 == V_16 ) {
V_4 += sprintf ( V_19 + V_4 , L_10 ) ;
} else if( V_20 == V_18 ) {
V_4 += sprintf ( V_19 + V_4 , L_11 ) ;
}
if ( V_2 -> V_7 [ 0 ] ) {
V_4 += sprintf ( V_19 + V_4 , L_12 ,
V_2 -> V_7 ) ;
} else {
V_4 += sprintf ( V_19 + V_4 , L_13 ) ;
}
V_4 += sprintf ( V_19 + V_4 , L_14 ,
V_2 -> V_6 [ 1 ] , V_2 -> V_6 [ 0 ] ) ;
V_4 += sprintf ( V_19 + V_4 , L_15 ,
F_5 ( V_2 ) == V_21 ?
L_16 : L_17 ) ;
for( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_4 += sprintf ( V_19 + V_4 , L_1 , V_2 -> V_6 [ V_13 ] ) ;
}
V_4 += sprintf ( V_19 + V_4 , L_18 ,
F_6 ( V_2 ) ? L_16 : L_17 ) ;
V_19 [ V_4 ++ ] = '\n' ;
V_19 [ V_4 ] = 0 ;
return V_4 ;
}
static int F_7 ( char * V_3 , char * * V_8 , T_1 V_9 ,
int V_10 , int * V_11 , void * V_12 )
{
int V_4 = 0 ;
V_4 += sprintf ( V_3 + V_4 , L_19 , V_22 ) ;
V_4 += sprintf ( V_3 + V_4 , L_20 , V_23 ) ;
V_4 += sprintf ( V_3 + V_4 , L_21 , V_24 ) ;
if ( V_4 <= V_9 + V_10 ) * V_11 = 1 ;
* V_8 = V_3 + V_9 ;
V_4 -= V_9 ;
if ( V_4 > V_10 ) V_4 = V_10 ;
if ( V_4 < 0 ) V_4 = 0 ;
return V_4 ;
}
static int F_8 ( char * V_3 , char * * V_8 , T_1 V_9 ,
int V_10 , int * V_11 , void * V_12 )
{
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
int V_4 = 0 ;
V_4 = F_4 ( V_3 , V_2 ) ;
if( V_2 -> V_25 ) {
V_4 += V_2 -> V_25 ( V_3 + V_4 , V_2 -> V_20 ,
V_2 -> V_26 ) ;
}
if ( V_4 <= V_9 + V_10 ) * V_11 = 1 ;
* V_8 = V_3 + V_9 ;
V_4 -= V_9 ;
if ( V_4 > V_10 ) V_4 = V_10 ;
if ( V_4 < 0 ) V_4 = 0 ;
return V_4 ;
}
void T_2 F_9 ( void )
{
int V_13 ;
struct V_27 * V_28 ;
struct V_27 * V_29 = NULL ;
struct V_1 * V_2 ;
V_28 = F_10 ( L_22 , NULL ) ;
F_11 ( L_23 , 0 , V_28 , F_2 , NULL ) ;
F_11 ( L_24 , 0 , V_28 , F_7 , NULL ) ;
for( V_13 = 0 ; V_13 < V_30 ; V_13 ++ ) {
enum V_31 V_32 ;
V_2 = F_3 ( V_13 ) ;
if( ! V_2 )
continue;
V_2 -> V_25 = NULL ;
if( V_13 < V_15 ) sprintf ( V_2 -> V_33 , L_25 , V_13 + 1 ) ;
else if( V_13 == V_16 ) sprintf ( V_2 -> V_33 , L_26 ) ;
else if( V_13 == V_17 ) sprintf ( V_2 -> V_33 , L_27 ) ;
else if( V_13 == V_18 ) sprintf ( V_2 -> V_33 , L_28 ) ;
V_32 = F_5 ( V_2 ) ;
if ( V_32 != V_21 &&
V_32 != V_34 )
continue;
V_29 = F_11 ( V_2 -> V_33 , 0 , V_28 ,
F_8 , ( void * ) V_2 ) ;
if( V_29 == NULL ) {
F_12 ( L_29 ) ;
return;
}
}
}
void F_13 ( int V_20 , T_3 V_25 , void * V_26 )
{
struct V_1 * V_2 = F_3 ( V_20 ) ;
if( ! V_2 )
return;
V_2 -> V_25 = V_25 ;
V_2 -> V_26 = V_26 ;
}

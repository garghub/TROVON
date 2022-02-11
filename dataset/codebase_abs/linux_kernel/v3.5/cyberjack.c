static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_6 ) ;
if ( ! V_4 )
return - V_7 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
F_4 ( V_2 -> V_12 [ 0 ] , V_4 ) ;
F_5 ( & V_2 -> V_12 [ 0 ] -> V_13 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_14 ; ++ V_5 ) {
int V_15 ;
V_15 = F_6 ( V_2 -> V_12 [ V_5 ] -> V_16 ,
V_6 ) ;
if ( V_15 )
F_7 ( & V_2 -> V_17 -> V_17 ,
L_1 ) ;
F_8 ( L_2 , V_18 ) ;
}
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_14 ; ++ V_5 )
F_10 ( V_2 -> V_12 [ V_5 ] -> V_16 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_14 ; ++ V_5 ) {
F_12 ( F_13 ( V_2 -> V_12 [ V_5 ] ) ) ;
}
}
static int F_14 ( struct V_19 * V_20 ,
struct V_21 * V_12 )
{
struct V_3 * V_4 ;
unsigned long V_22 ;
int V_15 = 0 ;
F_8 ( L_3 , V_18 ) ;
F_15 ( V_12 -> V_2 -> V_17 , V_12 -> V_23 -> V_24 ) ;
V_4 = F_13 ( V_12 ) ;
F_16 ( & V_4 -> V_8 , V_22 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
F_17 ( & V_4 -> V_8 , V_22 ) ;
return V_15 ;
}
static void F_18 ( struct V_21 * V_12 )
{
if ( V_12 -> V_2 -> V_17 ) {
F_10 ( V_12 -> V_23 ) ;
F_10 ( V_12 -> V_25 ) ;
}
}
static int F_19 ( struct V_19 * V_20 ,
struct V_21 * V_12 , const unsigned char * V_26 , int V_27 )
{
struct V_3 * V_4 = F_13 ( V_12 ) ;
unsigned long V_22 ;
int V_15 ;
int V_28 ;
if ( V_27 == 0 ) {
F_8 ( L_4 , V_18 ) ;
return 0 ;
}
if ( ! F_20 ( 0 , & V_12 -> V_29 ) ) {
F_8 ( L_5 , V_18 ) ;
return 0 ;
}
F_16 ( & V_4 -> V_8 , V_22 ) ;
if ( V_27 + V_4 -> V_10 > sizeof( V_4 -> V_30 ) ) {
V_4 -> V_10 = 0 ;
F_17 ( & V_4 -> V_8 , V_22 ) ;
F_21 ( 0 , & V_12 -> V_29 ) ;
return 0 ;
}
memcpy ( V_4 -> V_30 + V_4 -> V_10 , V_26 , V_27 ) ;
F_22 ( V_31 , & V_12 -> V_17 , V_18 , V_27 ,
V_4 -> V_30 + V_4 -> V_10 ) ;
V_4 -> V_10 += V_27 ;
if ( V_4 -> V_10 >= 3 ) {
V_28 = ( ( int ) V_4 -> V_30 [ 2 ] << 8 ) + V_4 -> V_30 [ 1 ] + 3 ;
F_8 ( L_6 , V_18 , V_28 ) ;
} else
V_28 = sizeof( V_4 -> V_30 ) ;
if ( V_4 -> V_10 >= V_28 ) {
int V_32 ;
F_8 ( L_7 , V_18 ) ;
V_32 = ( V_28 > V_12 -> V_33 ) ?
V_12 -> V_33 : V_28 ;
memcpy ( V_12 -> V_23 -> V_34 , V_4 -> V_30 , V_32 ) ;
V_4 -> V_11 = V_32 ;
V_12 -> V_23 -> V_35 = V_32 ;
V_15 = F_6 ( V_12 -> V_23 , V_36 ) ;
if ( V_15 ) {
F_7 ( & V_12 -> V_17 ,
L_8 ,
V_18 , V_15 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
F_17 ( & V_4 -> V_8 , V_22 ) ;
F_21 ( 0 , & V_12 -> V_29 ) ;
return 0 ;
}
F_8 ( L_9 , V_18 , V_4 -> V_11 ) ;
F_8 ( L_10 , V_18 , V_4 -> V_10 ) ;
if ( V_4 -> V_11 >= V_4 -> V_10 ) {
F_8 ( L_11 , V_18 ) ;
memset ( V_4 -> V_30 , 0 , sizeof( V_4 -> V_30 ) ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
}
}
F_17 ( & V_4 -> V_8 , V_22 ) ;
return V_27 ;
}
static int F_23 ( struct V_19 * V_20 )
{
return V_37 ;
}
static void F_24 ( struct V_38 * V_38 )
{
struct V_21 * V_12 = V_38 -> V_39 ;
struct V_3 * V_4 = F_13 ( V_12 ) ;
unsigned char * V_40 = V_38 -> V_34 ;
int V_41 = V_38 -> V_41 ;
int V_15 ;
if ( V_41 )
return;
F_22 ( V_31 , & V_12 -> V_17 , V_18 ,
V_38 -> V_42 , V_40 ) ;
if ( V_38 -> V_42 == 4 && V_40 [ 0 ] == 0x01 ) {
short V_43 ;
unsigned short V_44 = ( ( unsigned short ) V_40 [ 3 ] << 8 ) + V_40 [ 2 ] + 3 ;
F_25 ( & V_4 -> V_8 ) ;
V_43 = V_4 -> V_9 ;
if ( V_43 + V_44 < V_43 ) {
F_8 ( L_12 ) ;
F_26 ( & V_4 -> V_8 ) ;
goto V_45;
}
V_4 -> V_9 += V_44 ;
F_8 ( L_13 , V_18 , V_4 -> V_9 ) ;
F_26 ( & V_4 -> V_8 ) ;
if ( ! V_43 ) {
V_15 = F_6 ( V_12 -> V_25 , V_36 ) ;
if ( V_15 )
F_7 ( & V_12 -> V_17 , L_14
L_15 ,
V_18 , V_15 ) ;
F_8 ( L_16 , V_18 ) ;
}
}
V_45:
V_15 = F_6 ( V_12 -> V_16 , V_36 ) ;
if ( V_15 )
F_7 ( & V_12 -> V_17 , L_1 ) ;
F_8 ( L_2 , V_18 ) ;
}
static void F_27 ( struct V_38 * V_38 )
{
struct V_21 * V_12 = V_38 -> V_39 ;
struct V_3 * V_4 = F_13 ( V_12 ) ;
struct V_19 * V_20 ;
unsigned char * V_40 = V_38 -> V_34 ;
short V_46 ;
int V_15 ;
int V_41 = V_38 -> V_41 ;
F_22 ( V_31 , & V_12 -> V_17 , V_18 ,
V_38 -> V_42 , V_40 ) ;
if ( V_41 ) {
F_8 ( L_17 ,
V_18 , V_41 ) ;
return;
}
V_20 = F_28 ( & V_12 -> V_12 ) ;
if ( ! V_20 ) {
F_8 ( L_18 , V_18 ) ;
return;
}
if ( V_38 -> V_42 ) {
F_29 ( V_20 , V_40 , V_38 -> V_42 ) ;
F_30 ( V_20 ) ;
}
F_31 ( V_20 ) ;
F_25 ( & V_4 -> V_8 ) ;
V_4 -> V_9 -= V_38 -> V_42 ;
if ( V_4 -> V_9 < 0 )
V_4 -> V_9 = 0 ;
V_46 = V_4 -> V_9 ;
F_26 ( & V_4 -> V_8 ) ;
F_8 ( L_13 , V_18 , V_46 ) ;
if ( V_46 ) {
V_15 = F_6 ( V_12 -> V_25 , V_36 ) ;
if ( V_15 )
F_7 ( & V_12 -> V_17 , L_19
L_20 , V_18 , V_15 ) ;
F_8 ( L_16 , V_18 ) ;
}
}
static void F_32 ( struct V_38 * V_38 )
{
struct V_21 * V_12 = V_38 -> V_39 ;
struct V_3 * V_4 = F_13 ( V_12 ) ;
int V_41 = V_38 -> V_41 ;
F_21 ( 0 , & V_12 -> V_29 ) ;
if ( V_41 ) {
F_8 ( L_21 ,
V_18 , V_41 ) ;
return;
}
F_25 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_10 ) {
int V_32 , V_47 , V_15 ;
F_8 ( L_22 , V_18 ) ;
V_32 = ( ( V_4 -> V_10 - V_4 -> V_11 ) > V_12 -> V_33 ) ?
V_12 -> V_33 : ( V_4 -> V_10 - V_4 -> V_11 ) ;
memcpy ( V_12 -> V_23 -> V_34 ,
V_4 -> V_30 + V_4 -> V_11 , V_32 ) ;
V_4 -> V_11 += V_32 ;
V_12 -> V_23 -> V_35 = V_32 ;
V_15 = F_6 ( V_12 -> V_23 , V_36 ) ;
if ( V_15 ) {
F_7 ( & V_12 -> V_17 ,
L_23 ,
V_18 , V_15 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
goto exit;
}
F_8 ( L_9 , V_18 , V_4 -> V_11 ) ;
F_8 ( L_10 , V_18 , V_4 -> V_10 ) ;
V_47 = ( ( int ) V_4 -> V_30 [ 2 ] << 8 ) + V_4 -> V_30 [ 1 ] + 3 ;
if ( V_4 -> V_11 >= V_4 -> V_10 ||
V_4 -> V_11 >= V_47 ) {
F_8 ( L_11 , V_18 ) ;
memset ( V_4 -> V_30 , 0 , sizeof( V_4 -> V_30 ) ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
}
}
exit:
F_26 ( & V_4 -> V_8 ) ;
F_33 ( V_12 ) ;
}

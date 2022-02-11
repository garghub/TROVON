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
F_4 ( V_2 , V_4 ) ;
V_5 = F_5 ( V_2 -> V_12 , V_6 ) ;
if ( V_5 )
F_6 ( & V_2 -> V_13 , L_1 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_8 ( V_2 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static void F_10 ( struct V_14 * V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_17 ; ++ V_16 )
F_11 ( V_15 -> V_2 [ V_16 ] -> V_12 ) ;
}
static int F_12 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_20 ;
int V_5 = 0 ;
F_13 ( & V_2 -> V_13 , L_2 , V_21 ) ;
F_14 ( V_2 -> V_15 -> V_13 , V_2 -> V_22 -> V_23 ) ;
V_4 = F_8 ( V_2 ) ;
F_15 ( & V_4 -> V_8 , V_20 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
F_16 ( & V_4 -> V_8 , V_20 ) ;
return V_5 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_15 -> V_13 ) {
F_11 ( V_2 -> V_22 ) ;
F_11 ( V_2 -> V_24 ) ;
}
}
static int F_18 ( struct V_18 * V_19 ,
struct V_1 * V_2 , const unsigned char * V_25 , int V_26 )
{
struct V_27 * V_13 = & V_2 -> V_13 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
unsigned long V_20 ;
int V_5 ;
int V_28 ;
if ( V_26 == 0 ) {
F_13 ( V_13 , L_3 , V_21 ) ;
return 0 ;
}
if ( ! F_19 ( 0 , & V_2 -> V_29 ) ) {
F_13 ( V_13 , L_4 , V_21 ) ;
return 0 ;
}
F_15 ( & V_4 -> V_8 , V_20 ) ;
if ( V_26 + V_4 -> V_10 > sizeof( V_4 -> V_30 ) ) {
V_4 -> V_10 = 0 ;
F_16 ( & V_4 -> V_8 , V_20 ) ;
F_20 ( 0 , & V_2 -> V_29 ) ;
return 0 ;
}
memcpy ( V_4 -> V_30 + V_4 -> V_10 , V_25 , V_26 ) ;
F_21 ( V_13 , V_21 , V_26 , V_4 -> V_30 + V_4 -> V_10 ) ;
V_4 -> V_10 += V_26 ;
if ( V_4 -> V_10 >= 3 ) {
V_28 = ( ( int ) V_4 -> V_30 [ 2 ] << 8 ) + V_4 -> V_30 [ 1 ] + 3 ;
F_13 ( V_13 , L_5 , V_21 , V_28 ) ;
} else
V_28 = sizeof( V_4 -> V_30 ) ;
if ( V_4 -> V_10 >= V_28 ) {
int V_31 ;
F_13 ( V_13 , L_6 , V_21 ) ;
V_31 = ( V_28 > V_2 -> V_32 ) ?
V_2 -> V_32 : V_28 ;
memcpy ( V_2 -> V_22 -> V_33 , V_4 -> V_30 , V_31 ) ;
V_4 -> V_11 = V_31 ;
V_2 -> V_22 -> V_34 = V_31 ;
V_5 = F_5 ( V_2 -> V_22 , V_35 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_13 ,
L_7 ,
V_21 , V_5 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
F_16 ( & V_4 -> V_8 , V_20 ) ;
F_20 ( 0 , & V_2 -> V_29 ) ;
return 0 ;
}
F_13 ( V_13 , L_8 , V_21 , V_4 -> V_11 ) ;
F_13 ( V_13 , L_9 , V_21 , V_4 -> V_10 ) ;
if ( V_4 -> V_11 >= V_4 -> V_10 ) {
F_13 ( V_13 , L_10 , V_21 ) ;
memset ( V_4 -> V_30 , 0 , sizeof( V_4 -> V_30 ) ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
}
}
F_16 ( & V_4 -> V_8 , V_20 ) ;
return V_26 ;
}
static int F_22 ( struct V_18 * V_19 )
{
return V_36 ;
}
static void F_23 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_38 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_27 * V_13 = & V_2 -> V_13 ;
unsigned char * V_39 = V_37 -> V_33 ;
int V_40 = V_37 -> V_40 ;
int V_5 ;
if ( V_40 )
return;
F_21 ( V_13 , V_21 , V_37 -> V_41 , V_39 ) ;
if ( V_37 -> V_41 == 4 && V_39 [ 0 ] == 0x01 ) {
short V_42 ;
unsigned short V_43 = ( ( unsigned short ) V_39 [ 3 ] << 8 ) + V_39 [ 2 ] + 3 ;
F_24 ( & V_4 -> V_8 ) ;
V_42 = V_4 -> V_9 ;
if ( V_42 + V_43 < V_42 ) {
F_13 ( V_13 , L_11 ) ;
F_25 ( & V_4 -> V_8 ) ;
goto V_44;
}
V_4 -> V_9 += V_43 ;
F_13 ( V_13 , L_12 , V_21 , V_4 -> V_9 ) ;
F_25 ( & V_4 -> V_8 ) ;
if ( ! V_42 ) {
V_5 = F_5 ( V_2 -> V_24 , V_35 ) ;
if ( V_5 )
F_6 ( V_13 , L_13 ,
V_21 , V_5 ) ;
F_13 ( V_13 , L_14 , V_21 ) ;
}
}
V_44:
V_5 = F_5 ( V_2 -> V_12 , V_35 ) ;
if ( V_5 )
F_6 ( & V_2 -> V_13 , L_1 ) ;
F_13 ( V_13 , L_15 , V_21 ) ;
}
static void F_26 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_38 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_27 * V_13 = & V_2 -> V_13 ;
struct V_18 * V_19 ;
unsigned char * V_39 = V_37 -> V_33 ;
short V_45 ;
int V_5 ;
int V_40 = V_37 -> V_40 ;
F_21 ( V_13 , V_21 , V_37 -> V_41 , V_39 ) ;
if ( V_40 ) {
F_13 ( V_13 , L_16 ,
V_21 , V_40 ) ;
return;
}
V_19 = F_27 ( & V_2 -> V_2 ) ;
if ( ! V_19 ) {
F_13 ( V_13 , L_17 , V_21 ) ;
return;
}
if ( V_37 -> V_41 ) {
F_28 ( V_19 , V_39 , V_37 -> V_41 ) ;
F_29 ( V_19 ) ;
}
F_30 ( V_19 ) ;
F_24 ( & V_4 -> V_8 ) ;
V_4 -> V_9 -= V_37 -> V_41 ;
if ( V_4 -> V_9 < 0 )
V_4 -> V_9 = 0 ;
V_45 = V_4 -> V_9 ;
F_25 ( & V_4 -> V_8 ) ;
F_13 ( V_13 , L_12 , V_21 , V_45 ) ;
if ( V_45 ) {
V_5 = F_5 ( V_2 -> V_24 , V_35 ) ;
if ( V_5 )
F_6 ( V_13 , L_13 ,
V_21 , V_5 ) ;
F_13 ( V_13 , L_14 , V_21 ) ;
}
}
static void F_31 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_38 ;
struct V_3 * V_4 = F_8 ( V_2 ) ;
struct V_27 * V_13 = & V_2 -> V_13 ;
int V_40 = V_37 -> V_40 ;
F_20 ( 0 , & V_2 -> V_29 ) ;
if ( V_40 ) {
F_13 ( V_13 , L_18 ,
V_21 , V_40 ) ;
return;
}
F_24 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_10 ) {
int V_31 , V_46 , V_5 ;
F_13 ( V_13 , L_19 , V_21 ) ;
V_31 = ( ( V_4 -> V_10 - V_4 -> V_11 ) > V_2 -> V_32 ) ?
V_2 -> V_32 : ( V_4 -> V_10 - V_4 -> V_11 ) ;
memcpy ( V_2 -> V_22 -> V_33 ,
V_4 -> V_30 + V_4 -> V_11 , V_31 ) ;
V_4 -> V_11 += V_31 ;
V_2 -> V_22 -> V_34 = V_31 ;
V_5 = F_5 ( V_2 -> V_22 , V_35 ) ;
if ( V_5 ) {
F_6 ( V_13 , L_20 ,
V_21 , V_5 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
goto exit;
}
F_13 ( V_13 , L_8 , V_21 , V_4 -> V_11 ) ;
F_13 ( V_13 , L_9 , V_21 , V_4 -> V_10 ) ;
V_46 = ( ( int ) V_4 -> V_30 [ 2 ] << 8 ) + V_4 -> V_30 [ 1 ] + 3 ;
if ( V_4 -> V_11 >= V_4 -> V_10 ||
V_4 -> V_11 >= V_46 ) {
F_13 ( V_13 , L_10 , V_21 ) ;
memset ( V_4 -> V_30 , 0 , sizeof( V_4 -> V_30 ) ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
}
}
exit:
F_25 ( & V_4 -> V_8 ) ;
F_32 ( V_2 ) ;
}

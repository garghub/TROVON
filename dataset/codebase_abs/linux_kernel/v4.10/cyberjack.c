static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 < V_2 -> V_4 )
return - V_5 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_3 ( sizeof( struct V_8 ) , V_11 ) ;
if ( ! V_9 )
return - V_12 ;
F_4 ( & V_9 -> V_13 ) ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
F_5 ( V_7 , V_9 ) ;
V_10 = F_6 ( V_7 -> V_17 , V_11 ) ;
if ( V_10 )
F_7 ( & V_7 -> V_18 , L_1 ) ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
F_9 ( V_7 -> V_17 ) ;
V_9 = F_10 ( V_7 ) ;
F_11 ( V_9 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 ;
unsigned long V_21 ;
F_13 ( & V_7 -> V_18 , L_2 , V_22 ) ;
F_14 ( V_7 -> V_2 -> V_18 , V_7 -> V_23 -> V_24 ) ;
V_9 = F_10 ( V_7 ) ;
F_15 ( & V_9 -> V_13 , V_21 ) ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
F_16 ( & V_9 -> V_13 , V_21 ) ;
return 0 ;
}
static void F_17 ( struct V_6 * V_7 )
{
F_9 ( V_7 -> V_23 ) ;
F_9 ( V_7 -> V_25 ) ;
}
static int F_18 ( struct V_19 * V_20 ,
struct V_6 * V_7 , const unsigned char * V_26 , int V_27 )
{
struct V_28 * V_18 = & V_7 -> V_18 ;
struct V_8 * V_9 = F_10 ( V_7 ) ;
unsigned long V_21 ;
int V_10 ;
int V_29 ;
if ( V_27 == 0 ) {
F_13 ( V_18 , L_3 , V_22 ) ;
return 0 ;
}
if ( ! F_19 ( 0 , & V_7 -> V_30 ) ) {
F_13 ( V_18 , L_4 , V_22 ) ;
return 0 ;
}
F_15 ( & V_9 -> V_13 , V_21 ) ;
if ( V_27 + V_9 -> V_15 > sizeof( V_9 -> V_31 ) ) {
V_9 -> V_15 = 0 ;
F_16 ( & V_9 -> V_13 , V_21 ) ;
F_20 ( 0 , & V_7 -> V_30 ) ;
return 0 ;
}
memcpy ( V_9 -> V_31 + V_9 -> V_15 , V_26 , V_27 ) ;
F_21 ( V_18 , V_22 , V_27 , V_9 -> V_31 + V_9 -> V_15 ) ;
V_9 -> V_15 += V_27 ;
if ( V_9 -> V_15 >= 3 ) {
V_29 = ( ( int ) V_9 -> V_31 [ 2 ] << 8 ) + V_9 -> V_31 [ 1 ] + 3 ;
F_13 ( V_18 , L_5 , V_22 , V_29 ) ;
} else
V_29 = sizeof( V_9 -> V_31 ) ;
if ( V_9 -> V_15 >= V_29 ) {
int V_32 ;
F_13 ( V_18 , L_6 , V_22 ) ;
V_32 = ( V_29 > V_7 -> V_33 ) ?
V_7 -> V_33 : V_29 ;
memcpy ( V_7 -> V_23 -> V_34 , V_9 -> V_31 , V_32 ) ;
V_9 -> V_16 = V_32 ;
V_7 -> V_23 -> V_35 = V_32 ;
V_10 = F_6 ( V_7 -> V_23 , V_36 ) ;
if ( V_10 ) {
F_7 ( & V_7 -> V_18 ,
L_7 ,
V_22 , V_10 ) ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
F_16 ( & V_9 -> V_13 , V_21 ) ;
F_20 ( 0 , & V_7 -> V_30 ) ;
return 0 ;
}
F_13 ( V_18 , L_8 , V_22 , V_9 -> V_16 ) ;
F_13 ( V_18 , L_9 , V_22 , V_9 -> V_15 ) ;
if ( V_9 -> V_16 >= V_9 -> V_15 ) {
F_13 ( V_18 , L_10 , V_22 ) ;
memset ( V_9 -> V_31 , 0 , sizeof( V_9 -> V_31 ) ) ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
}
}
F_16 ( & V_9 -> V_13 , V_21 ) ;
return V_27 ;
}
static int F_22 ( struct V_19 * V_20 )
{
return V_37 ;
}
static void F_23 ( struct V_38 * V_38 )
{
struct V_6 * V_7 = V_38 -> V_39 ;
struct V_8 * V_9 = F_10 ( V_7 ) ;
struct V_28 * V_18 = & V_7 -> V_18 ;
unsigned char * V_40 = V_38 -> V_34 ;
int V_41 = V_38 -> V_41 ;
int V_10 ;
if ( V_41 )
return;
F_21 ( V_18 , V_22 , V_38 -> V_42 , V_40 ) ;
if ( V_38 -> V_42 == 4 && V_40 [ 0 ] == 0x01 ) {
short V_43 ;
unsigned short V_44 = ( ( unsigned short ) V_40 [ 3 ] << 8 ) + V_40 [ 2 ] + 3 ;
F_24 ( & V_9 -> V_13 ) ;
V_43 = V_9 -> V_14 ;
if ( V_43 > V_45 - V_44 ) {
F_13 ( V_18 , L_11 ) ;
F_25 ( & V_9 -> V_13 ) ;
goto V_46;
}
V_9 -> V_14 += V_44 ;
F_13 ( V_18 , L_12 , V_22 , V_9 -> V_14 ) ;
F_25 ( & V_9 -> V_13 ) ;
if ( ! V_43 ) {
V_10 = F_6 ( V_7 -> V_25 , V_36 ) ;
if ( V_10 )
F_7 ( V_18 , L_13 ,
V_22 , V_10 ) ;
F_13 ( V_18 , L_14 , V_22 ) ;
}
}
V_46:
V_10 = F_6 ( V_7 -> V_17 , V_36 ) ;
if ( V_10 )
F_7 ( & V_7 -> V_18 , L_1 ) ;
F_13 ( V_18 , L_15 , V_22 ) ;
}
static void F_26 ( struct V_38 * V_38 )
{
struct V_6 * V_7 = V_38 -> V_39 ;
struct V_8 * V_9 = F_10 ( V_7 ) ;
struct V_28 * V_18 = & V_7 -> V_18 ;
unsigned char * V_40 = V_38 -> V_34 ;
short V_47 ;
int V_10 ;
int V_41 = V_38 -> V_41 ;
F_21 ( V_18 , V_22 , V_38 -> V_42 , V_40 ) ;
if ( V_41 ) {
F_13 ( V_18 , L_16 ,
V_22 , V_41 ) ;
return;
}
if ( V_38 -> V_42 ) {
F_27 ( & V_7 -> V_7 , V_40 , V_38 -> V_42 ) ;
F_28 ( & V_7 -> V_7 ) ;
}
F_24 ( & V_9 -> V_13 ) ;
V_9 -> V_14 -= V_38 -> V_42 ;
if ( V_9 -> V_14 < 0 )
V_9 -> V_14 = 0 ;
V_47 = V_9 -> V_14 ;
F_25 ( & V_9 -> V_13 ) ;
F_13 ( V_18 , L_12 , V_22 , V_47 ) ;
if ( V_47 ) {
V_10 = F_6 ( V_7 -> V_25 , V_36 ) ;
if ( V_10 )
F_7 ( V_18 , L_13 ,
V_22 , V_10 ) ;
F_13 ( V_18 , L_14 , V_22 ) ;
}
}
static void F_29 ( struct V_38 * V_38 )
{
struct V_6 * V_7 = V_38 -> V_39 ;
struct V_8 * V_9 = F_10 ( V_7 ) ;
struct V_28 * V_18 = & V_7 -> V_18 ;
int V_41 = V_38 -> V_41 ;
F_20 ( 0 , & V_7 -> V_30 ) ;
if ( V_41 ) {
F_13 ( V_18 , L_17 ,
V_22 , V_41 ) ;
return;
}
F_24 ( & V_9 -> V_13 ) ;
if ( V_9 -> V_15 ) {
int V_32 , V_48 , V_10 ;
F_13 ( V_18 , L_18 , V_22 ) ;
V_32 = ( ( V_9 -> V_15 - V_9 -> V_16 ) > V_7 -> V_33 ) ?
V_7 -> V_33 : ( V_9 -> V_15 - V_9 -> V_16 ) ;
memcpy ( V_7 -> V_23 -> V_34 ,
V_9 -> V_31 + V_9 -> V_16 , V_32 ) ;
V_9 -> V_16 += V_32 ;
V_7 -> V_23 -> V_35 = V_32 ;
V_10 = F_6 ( V_7 -> V_23 , V_36 ) ;
if ( V_10 ) {
F_7 ( V_18 , L_7 ,
V_22 , V_10 ) ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
goto exit;
}
F_13 ( V_18 , L_8 , V_22 , V_9 -> V_16 ) ;
F_13 ( V_18 , L_9 , V_22 , V_9 -> V_15 ) ;
V_48 = ( ( int ) V_9 -> V_31 [ 2 ] << 8 ) + V_9 -> V_31 [ 1 ] + 3 ;
if ( V_9 -> V_16 >= V_9 -> V_15 ||
V_9 -> V_16 >= V_48 ) {
F_13 ( V_18 , L_10 , V_22 ) ;
memset ( V_9 -> V_31 , 0 , sizeof( V_9 -> V_31 ) ) ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
}
}
exit:
F_25 ( & V_9 -> V_13 ) ;
F_30 ( V_7 ) ;
}

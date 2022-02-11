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
F_8 ( V_2 -> V_12 ) ;
V_4 = F_9 ( V_2 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 ,
struct V_1 * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_16 ;
int V_5 = 0 ;
F_12 ( & V_2 -> V_13 , L_2 , V_17 ) ;
F_13 ( V_2 -> V_18 -> V_13 , V_2 -> V_19 -> V_20 ) ;
V_4 = F_9 ( V_2 ) ;
F_14 ( & V_4 -> V_8 , V_16 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
F_15 ( & V_4 -> V_8 , V_16 ) ;
return V_5 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_19 ) ;
F_8 ( V_2 -> V_21 ) ;
}
static int F_17 ( struct V_14 * V_15 ,
struct V_1 * V_2 , const unsigned char * V_22 , int V_23 )
{
struct V_24 * V_13 = & V_2 -> V_13 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
unsigned long V_16 ;
int V_5 ;
int V_25 ;
if ( V_23 == 0 ) {
F_12 ( V_13 , L_3 , V_17 ) ;
return 0 ;
}
if ( ! F_18 ( 0 , & V_2 -> V_26 ) ) {
F_12 ( V_13 , L_4 , V_17 ) ;
return 0 ;
}
F_14 ( & V_4 -> V_8 , V_16 ) ;
if ( V_23 + V_4 -> V_10 > sizeof( V_4 -> V_27 ) ) {
V_4 -> V_10 = 0 ;
F_15 ( & V_4 -> V_8 , V_16 ) ;
F_19 ( 0 , & V_2 -> V_26 ) ;
return 0 ;
}
memcpy ( V_4 -> V_27 + V_4 -> V_10 , V_22 , V_23 ) ;
F_20 ( V_13 , V_17 , V_23 , V_4 -> V_27 + V_4 -> V_10 ) ;
V_4 -> V_10 += V_23 ;
if ( V_4 -> V_10 >= 3 ) {
V_25 = ( ( int ) V_4 -> V_27 [ 2 ] << 8 ) + V_4 -> V_27 [ 1 ] + 3 ;
F_12 ( V_13 , L_5 , V_17 , V_25 ) ;
} else
V_25 = sizeof( V_4 -> V_27 ) ;
if ( V_4 -> V_10 >= V_25 ) {
int V_28 ;
F_12 ( V_13 , L_6 , V_17 ) ;
V_28 = ( V_25 > V_2 -> V_29 ) ?
V_2 -> V_29 : V_25 ;
memcpy ( V_2 -> V_19 -> V_30 , V_4 -> V_27 , V_28 ) ;
V_4 -> V_11 = V_28 ;
V_2 -> V_19 -> V_31 = V_28 ;
V_5 = F_5 ( V_2 -> V_19 , V_32 ) ;
if ( V_5 ) {
F_6 ( & V_2 -> V_13 ,
L_7 ,
V_17 , V_5 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
F_15 ( & V_4 -> V_8 , V_16 ) ;
F_19 ( 0 , & V_2 -> V_26 ) ;
return 0 ;
}
F_12 ( V_13 , L_8 , V_17 , V_4 -> V_11 ) ;
F_12 ( V_13 , L_9 , V_17 , V_4 -> V_10 ) ;
if ( V_4 -> V_11 >= V_4 -> V_10 ) {
F_12 ( V_13 , L_10 , V_17 ) ;
memset ( V_4 -> V_27 , 0 , sizeof( V_4 -> V_27 ) ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
}
}
F_15 ( & V_4 -> V_8 , V_16 ) ;
return V_23 ;
}
static int F_21 ( struct V_14 * V_15 )
{
return V_33 ;
}
static void F_22 ( struct V_34 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
struct V_24 * V_13 = & V_2 -> V_13 ;
unsigned char * V_36 = V_34 -> V_30 ;
int V_37 = V_34 -> V_37 ;
int V_5 ;
if ( V_37 )
return;
F_20 ( V_13 , V_17 , V_34 -> V_38 , V_36 ) ;
if ( V_34 -> V_38 == 4 && V_36 [ 0 ] == 0x01 ) {
short V_39 ;
unsigned short V_40 = ( ( unsigned short ) V_36 [ 3 ] << 8 ) + V_36 [ 2 ] + 3 ;
F_23 ( & V_4 -> V_8 ) ;
V_39 = V_4 -> V_9 ;
if ( V_39 > V_41 - V_40 ) {
F_12 ( V_13 , L_11 ) ;
F_24 ( & V_4 -> V_8 ) ;
goto V_42;
}
V_4 -> V_9 += V_40 ;
F_12 ( V_13 , L_12 , V_17 , V_4 -> V_9 ) ;
F_24 ( & V_4 -> V_8 ) ;
if ( ! V_39 ) {
V_5 = F_5 ( V_2 -> V_21 , V_32 ) ;
if ( V_5 )
F_6 ( V_13 , L_13 ,
V_17 , V_5 ) ;
F_12 ( V_13 , L_14 , V_17 ) ;
}
}
V_42:
V_5 = F_5 ( V_2 -> V_12 , V_32 ) ;
if ( V_5 )
F_6 ( & V_2 -> V_13 , L_1 ) ;
F_12 ( V_13 , L_15 , V_17 ) ;
}
static void F_25 ( struct V_34 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
struct V_24 * V_13 = & V_2 -> V_13 ;
unsigned char * V_36 = V_34 -> V_30 ;
short V_43 ;
int V_5 ;
int V_37 = V_34 -> V_37 ;
F_20 ( V_13 , V_17 , V_34 -> V_38 , V_36 ) ;
if ( V_37 ) {
F_12 ( V_13 , L_16 ,
V_17 , V_37 ) ;
return;
}
if ( V_34 -> V_38 ) {
F_26 ( & V_2 -> V_2 , V_36 , V_34 -> V_38 ) ;
F_27 ( & V_2 -> V_2 ) ;
}
F_23 ( & V_4 -> V_8 ) ;
V_4 -> V_9 -= V_34 -> V_38 ;
if ( V_4 -> V_9 < 0 )
V_4 -> V_9 = 0 ;
V_43 = V_4 -> V_9 ;
F_24 ( & V_4 -> V_8 ) ;
F_12 ( V_13 , L_12 , V_17 , V_43 ) ;
if ( V_43 ) {
V_5 = F_5 ( V_2 -> V_21 , V_32 ) ;
if ( V_5 )
F_6 ( V_13 , L_13 ,
V_17 , V_5 ) ;
F_12 ( V_13 , L_14 , V_17 ) ;
}
}
static void F_28 ( struct V_34 * V_34 )
{
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_3 * V_4 = F_9 ( V_2 ) ;
struct V_24 * V_13 = & V_2 -> V_13 ;
int V_37 = V_34 -> V_37 ;
F_19 ( 0 , & V_2 -> V_26 ) ;
if ( V_37 ) {
F_12 ( V_13 , L_17 ,
V_17 , V_37 ) ;
return;
}
F_23 ( & V_4 -> V_8 ) ;
if ( V_4 -> V_10 ) {
int V_28 , V_44 , V_5 ;
F_12 ( V_13 , L_18 , V_17 ) ;
V_28 = ( ( V_4 -> V_10 - V_4 -> V_11 ) > V_2 -> V_29 ) ?
V_2 -> V_29 : ( V_4 -> V_10 - V_4 -> V_11 ) ;
memcpy ( V_2 -> V_19 -> V_30 ,
V_4 -> V_27 + V_4 -> V_11 , V_28 ) ;
V_4 -> V_11 += V_28 ;
V_2 -> V_19 -> V_31 = V_28 ;
V_5 = F_5 ( V_2 -> V_19 , V_32 ) ;
if ( V_5 ) {
F_6 ( V_13 , L_7 ,
V_17 , V_5 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
goto exit;
}
F_12 ( V_13 , L_8 , V_17 , V_4 -> V_11 ) ;
F_12 ( V_13 , L_9 , V_17 , V_4 -> V_10 ) ;
V_44 = ( ( int ) V_4 -> V_27 [ 2 ] << 8 ) + V_4 -> V_27 [ 1 ] + 3 ;
if ( V_4 -> V_11 >= V_4 -> V_10 ||
V_4 -> V_11 >= V_44 ) {
F_12 ( V_13 , L_10 , V_17 ) ;
memset ( V_4 -> V_27 , 0 , sizeof( V_4 -> V_27 ) ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_11 = 0 ;
}
}
exit:
F_24 ( & V_4 -> V_8 ) ;
F_29 ( V_2 ) ;
}

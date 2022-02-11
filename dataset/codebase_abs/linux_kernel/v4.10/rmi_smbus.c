static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_2 ( V_4 , V_6 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_4 -> V_7 , L_1 ) ;
return V_5 ;
}
return V_5 + 1 ;
}
static int F_4 ( struct V_8 * V_9 ,
T_1 V_10 , const void * V_11 , T_2 V_12 )
{
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_6 ( V_4 , V_10 , V_12 , V_11 ) ;
F_7 ( V_13 , & V_4 -> V_7 ,
L_2 ,
V_12 , V_10 , V_5 , ( int ) V_12 , V_11 ) ;
return V_5 ;
}
static int F_8 ( struct V_8 * V_9 ,
T_3 V_14 , int V_15 , bool V_16 , T_1 * V_10 )
{
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
int V_17 ;
int V_5 ;
struct V_18 V_19 [ 1 ] ;
F_9 ( & V_2 -> V_20 ) ;
for ( V_17 = 0 ; V_17 < V_21 ; V_17 ++ ) {
if ( V_2 -> V_22 [ V_17 ] . V_14 == V_14 ) {
if ( V_16 ) {
if ( V_2 -> V_22 [ V_17 ] . V_23
== V_15 ) {
* V_10 = V_17 ;
V_5 = 0 ;
goto exit;
}
} else {
if ( V_2 -> V_22 [ V_17 ] . V_24 &
V_25 ) {
* V_10 = V_17 ;
V_5 = 0 ;
goto exit;
}
}
}
}
V_17 = V_2 -> V_26 ;
V_2 -> V_26 = ( V_17 + 1 ) % V_21 ;
memset ( V_19 , 0 , sizeof( V_19 ) ) ;
V_19 [ 0 ] . V_14 = F_10 ( V_14 ) ;
V_19 [ 0 ] . V_23 = V_15 ;
V_19 [ 0 ] . V_24 = ! V_16 ? V_25 : 0 ;
V_5 = F_4 ( V_9 , V_17 + 0x80 , V_19 ,
sizeof( V_19 ) ) ;
if ( V_5 < 0 ) {
V_2 -> V_22 [ V_17 ] . V_14 = 0x0000 ;
V_2 -> V_22 [ V_17 ] . V_23 = 0 ;
V_2 -> V_22 [ V_17 ] . V_24 = 0 ;
goto exit;
}
V_2 -> V_22 [ V_17 ] . V_14 = V_14 ;
V_2 -> V_22 [ V_17 ] . V_23 = V_15 ;
V_2 -> V_22 [ V_17 ] . V_24 = ! V_16 ? V_25 : 0 ;
* V_10 = V_17 ;
exit:
F_11 ( & V_2 -> V_20 ) ;
return V_5 ;
}
static int F_12 ( struct V_8 * V_9 , T_3 V_14 ,
const void * V_27 , T_2 V_12 )
{
int V_5 = 0 ;
T_1 V_10 ;
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
int V_28 = ( int ) V_12 ;
F_9 ( & V_2 -> V_29 ) ;
while ( V_28 > 0 ) {
int V_30 = F_13 ( int , V_12 , V_31 ) ;
V_5 = F_8 ( V_9 , V_14 , V_30 ,
false , & V_10 ) ;
if ( V_5 < 0 )
goto exit;
V_5 = F_4 ( V_9 , V_10 ,
V_27 , V_30 ) ;
if ( V_5 < 0 )
goto exit;
V_28 -= V_31 ;
V_27 += V_31 ;
V_14 += V_31 ;
}
exit:
F_11 ( & V_2 -> V_29 ) ;
return V_5 ;
}
static int F_14 ( struct V_8 * V_9 ,
T_1 V_10 , void * V_11 , T_2 V_12 )
{
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_15 ( V_4 , V_10 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_5 ;
}
static int F_16 ( struct V_8 * V_9 , T_3 V_14 ,
void * V_27 , T_2 V_12 )
{
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
int V_5 ;
T_1 V_10 ;
int V_28 = ( int ) V_12 ;
F_9 ( & V_2 -> V_29 ) ;
memset ( V_27 , 0 , V_12 ) ;
while ( V_28 > 0 ) {
int V_30 = F_13 ( int , V_28 , V_31 ) ;
V_5 = F_8 ( V_9 , V_14 , V_30 ,
true , & V_10 ) ;
if ( V_5 < 0 )
goto exit;
V_5 = F_14 ( V_9 , V_10 ,
V_27 , V_30 ) ;
if ( V_5 < 0 )
goto exit;
V_28 -= V_31 ;
V_27 += V_31 ;
V_14 += V_31 ;
}
V_5 = 0 ;
exit:
F_11 ( & V_2 -> V_29 ) ;
return V_5 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_20 ) ;
memset ( V_2 -> V_22 , 0 , sizeof( V_2 -> V_22 ) ) ;
F_11 ( & V_2 -> V_20 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_19 ( struct V_8 * V_9 , T_3 V_32 )
{
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
F_17 ( V_2 ) ;
return F_18 ( V_2 ) ;
}
static int F_20 ( struct V_3 * V_4 ,
const struct V_33 * V_34 )
{
struct V_35 * V_36 = F_21 ( & V_4 -> V_7 ) ;
struct V_1 * V_2 ;
int V_5 ;
int V_37 ;
if ( ! F_22 ( V_4 -> V_38 ,
V_39 |
V_40 ) ) {
F_3 ( & V_4 -> V_7 ,
L_3 ) ;
return - V_41 ;
}
if ( V_4 -> V_42 <= 0 ) {
F_3 ( & V_4 -> V_7 , L_4 ) ;
return V_4 -> V_42 ? V_4 -> V_42 : - V_41 ;
}
V_2 = F_23 ( & V_4 -> V_7 , sizeof( struct V_1 ) ,
V_43 ) ;
if ( ! V_2 )
return - V_44 ;
if ( ! V_36 ) {
F_3 ( & V_4 -> V_7 , L_5 ) ;
return - V_44 ;
}
F_7 ( V_13 , & V_4 -> V_7 , L_6 ,
F_24 ( & V_4 -> V_7 ) ) ;
V_2 -> V_4 = V_4 ;
F_25 ( & V_2 -> V_29 ) ;
F_25 ( & V_2 -> V_20 ) ;
V_2 -> V_9 . V_7 = & V_4 -> V_7 ;
V_2 -> V_9 . V_36 = * V_36 ;
V_2 -> V_9 . V_36 . V_42 = V_4 -> V_42 ;
V_2 -> V_9 . V_45 = L_7 ;
V_2 -> V_9 . V_46 = & V_47 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
V_37 = V_5 ;
F_7 ( V_13 , & V_4 -> V_7 , L_8 ,
V_37 ) ;
if ( V_37 != 2 ) {
F_3 ( & V_4 -> V_7 , L_9 ,
V_37 ) ;
return - V_41 ;
}
F_26 ( V_4 , V_2 ) ;
V_5 = F_27 ( & V_2 -> V_9 ) ;
if ( V_5 ) {
F_3 ( & V_4 -> V_7 , L_10 ,
V_4 -> V_48 ) ;
F_26 ( V_4 , NULL ) ;
return V_5 ;
}
F_28 ( & V_4 -> V_7 , L_11 ,
V_4 -> V_48 ) ;
return 0 ;
}
static int F_29 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_30 ( V_4 ) ;
F_31 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int T_4 F_32 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_33 ( V_7 ) ;
struct V_1 * V_2 = F_30 ( V_4 ) ;
int V_50 ;
V_50 = F_34 ( V_2 -> V_9 . V_51 , true ) ;
if ( V_50 )
F_35 ( V_7 , L_12 , V_50 ) ;
return V_50 ;
}
static int T_4 F_36 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_33 ( V_7 ) ;
struct V_1 * V_2 = F_30 ( V_4 ) ;
int V_50 ;
V_50 = F_34 ( V_2 -> V_9 . V_51 , false ) ;
if ( V_50 )
F_35 ( V_7 , L_12 , V_50 ) ;
return V_50 ;
}
static int T_4 F_37 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_5 ( V_7 , struct V_3 , V_7 ) ;
struct V_1 * V_2 = F_30 ( V_4 ) ;
struct V_52 * V_51 = V_2 -> V_9 . V_51 ;
int V_50 ;
F_19 ( & V_2 -> V_9 , 0 ) ;
F_38 ( V_51 ) ;
V_50 = F_39 ( V_2 -> V_9 . V_51 , true ) ;
if ( V_50 )
F_35 ( V_7 , L_13 , V_50 ) ;
return 0 ;
}
static int T_4 F_40 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_33 ( V_7 ) ;
struct V_1 * V_2 = F_30 ( V_4 ) ;
int V_50 ;
V_50 = F_39 ( V_2 -> V_9 . V_51 , false ) ;
if ( V_50 )
F_35 ( V_7 , L_13 , V_50 ) ;
return 0 ;
}

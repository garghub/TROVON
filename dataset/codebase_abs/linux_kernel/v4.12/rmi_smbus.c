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
struct V_17 V_18 ;
int V_19 ;
int V_5 = 0 ;
F_9 ( & V_2 -> V_20 ) ;
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
struct V_17 * V_22 = & V_2 -> V_23 [ V_19 ] ;
if ( F_10 ( V_22 -> V_14 ) == V_14 ) {
if ( V_16 ) {
if ( V_22 -> V_24 == V_15 )
goto exit;
} else {
if ( V_22 -> V_25 & V_26 ) {
goto exit;
}
}
}
}
V_19 = V_2 -> V_27 ;
V_2 -> V_27 = ( V_19 + 1 ) % V_21 ;
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
V_18 . V_14 = F_11 ( V_14 ) ;
V_18 . V_24 = V_15 ;
V_18 . V_25 = ! V_16 ? V_26 : 0 ;
V_5 = F_4 ( V_9 , V_19 + 0x80 , & V_18 , sizeof( V_18 ) ) ;
if ( V_5 < 0 ) {
memset ( & V_18 , 0 , sizeof( V_18 ) ) ;
}
V_2 -> V_23 [ V_19 ] = V_18 ;
exit:
F_12 ( & V_2 -> V_20 ) ;
if ( V_5 < 0 )
return V_5 ;
* V_10 = V_19 ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 , T_3 V_14 ,
const void * V_28 , T_2 V_12 )
{
int V_5 = 0 ;
T_1 V_10 ;
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
int V_29 = ( int ) V_12 ;
F_9 ( & V_2 -> V_30 ) ;
while ( V_29 > 0 ) {
int V_31 = F_14 ( int , V_12 , V_32 ) ;
V_5 = F_8 ( V_9 , V_14 , V_31 ,
false , & V_10 ) ;
if ( V_5 < 0 )
goto exit;
V_5 = F_4 ( V_9 , V_10 ,
V_28 , V_31 ) ;
if ( V_5 < 0 )
goto exit;
V_29 -= V_32 ;
V_28 += V_32 ;
V_14 += V_32 ;
}
exit:
F_12 ( & V_2 -> V_30 ) ;
return V_5 ;
}
static int F_15 ( struct V_8 * V_9 ,
T_1 V_10 , void * V_11 , T_2 V_12 )
{
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
V_5 = F_16 ( V_4 , V_10 , V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_5 ;
}
static int F_17 ( struct V_8 * V_9 , T_3 V_14 ,
void * V_28 , T_2 V_12 )
{
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
int V_5 ;
T_1 V_10 ;
int V_29 = ( int ) V_12 ;
F_9 ( & V_2 -> V_30 ) ;
memset ( V_28 , 0 , V_12 ) ;
while ( V_29 > 0 ) {
int V_31 = F_14 ( int , V_29 , V_32 ) ;
V_5 = F_8 ( V_9 , V_14 , V_31 ,
true , & V_10 ) ;
if ( V_5 < 0 )
goto exit;
V_5 = F_15 ( V_9 , V_10 ,
V_28 , V_31 ) ;
if ( V_5 < 0 )
goto exit;
V_29 -= V_32 ;
V_28 += V_32 ;
V_14 += V_32 ;
}
V_5 = 0 ;
exit:
F_12 ( & V_2 -> V_30 ) ;
return V_5 ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_20 ) ;
memset ( V_2 -> V_23 , 0 , sizeof( V_2 -> V_23 ) ) ;
F_12 ( & V_2 -> V_20 ) ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_5 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 )
return V_5 ;
return 0 ;
}
static int F_20 ( struct V_8 * V_9 , T_3 V_33 )
{
struct V_1 * V_2 =
F_5 ( V_9 , struct V_1 , V_9 ) ;
F_18 ( V_2 ) ;
return F_19 ( V_2 ) ;
}
static int F_21 ( struct V_3 * V_4 ,
const struct V_34 * V_35 )
{
struct V_36 * V_37 = F_22 ( & V_4 -> V_7 ) ;
struct V_1 * V_2 ;
int V_38 ;
int error ;
if ( ! V_37 ) {
F_3 ( & V_4 -> V_7 , L_3 ) ;
return - V_39 ;
}
if ( ! F_23 ( V_4 -> V_40 ,
V_41 |
V_42 ) ) {
F_3 ( & V_4 -> V_7 ,
L_4 ) ;
return - V_43 ;
}
if ( V_4 -> V_44 <= 0 ) {
F_3 ( & V_4 -> V_7 , L_5 ) ;
return V_4 -> V_44 ? V_4 -> V_44 : - V_43 ;
}
V_2 = F_24 ( & V_4 -> V_7 , sizeof( struct V_1 ) ,
V_45 ) ;
if ( ! V_2 )
return - V_39 ;
F_7 ( V_13 , & V_4 -> V_7 , L_6 ,
F_25 ( & V_4 -> V_7 ) ) ;
V_2 -> V_4 = V_4 ;
F_26 ( & V_2 -> V_30 ) ;
F_26 ( & V_2 -> V_20 ) ;
V_2 -> V_9 . V_7 = & V_4 -> V_7 ;
V_2 -> V_9 . V_37 = * V_37 ;
V_2 -> V_9 . V_37 . V_44 = V_4 -> V_44 ;
V_2 -> V_9 . V_46 = L_7 ;
V_2 -> V_9 . V_47 = & V_48 ;
V_38 = F_1 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
F_7 ( V_13 , & V_4 -> V_7 , L_8 ,
V_38 ) ;
if ( V_38 != 2 ) {
F_3 ( & V_4 -> V_7 , L_9 ,
V_38 ) ;
return - V_43 ;
}
F_27 ( V_4 , V_2 ) ;
F_28 ( & V_4 -> V_7 , L_10 ) ;
error = F_29 ( & V_2 -> V_9 ) ;
if ( error ) {
F_3 ( & V_4 -> V_7 , L_11 , error ) ;
return error ;
}
return 0 ;
}
static int F_30 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_31 ( V_4 ) ;
F_32 ( & V_2 -> V_9 ) ;
return 0 ;
}
static int T_4 F_33 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_34 ( V_7 ) ;
struct V_1 * V_2 = F_31 ( V_4 ) ;
int V_50 ;
V_50 = F_35 ( V_2 -> V_9 . V_51 , true ) ;
if ( V_50 )
F_36 ( V_7 , L_12 , V_50 ) ;
return V_50 ;
}
static int T_4 F_37 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_34 ( V_7 ) ;
struct V_1 * V_2 = F_31 ( V_4 ) ;
int V_50 ;
V_50 = F_35 ( V_2 -> V_9 . V_51 , false ) ;
if ( V_50 )
F_36 ( V_7 , L_12 , V_50 ) ;
return V_50 ;
}
static int T_4 F_38 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_5 ( V_7 , struct V_3 , V_7 ) ;
struct V_1 * V_2 = F_31 ( V_4 ) ;
struct V_52 * V_51 = V_2 -> V_9 . V_51 ;
int V_50 ;
F_20 ( & V_2 -> V_9 , 0 ) ;
F_39 ( V_51 ) ;
V_50 = F_40 ( V_2 -> V_9 . V_51 , true ) ;
if ( V_50 )
F_36 ( V_7 , L_13 , V_50 ) ;
return 0 ;
}
static int T_4 F_41 ( struct V_49 * V_7 )
{
struct V_3 * V_4 = F_34 ( V_7 ) ;
struct V_1 * V_2 = F_31 ( V_4 ) ;
int V_50 ;
V_50 = F_40 ( V_2 -> V_9 . V_51 , false ) ;
if ( V_50 )
F_36 ( V_7 , L_13 , V_50 ) ;
return 0 ;
}

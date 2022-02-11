int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 ;
V_7 = ( T_1 * ) V_4 -> V_8 ;
if ( F_2 ( & V_2 -> V_9 ) ) {
F_3 ( V_2 -> V_10 , L_1 ) ;
return - V_11 ;
}
F_4 (module, &ctx->uuid_list, list) {
if ( F_5 ( * V_7 , V_6 -> V_12 ) == 0 ) {
V_4 -> V_13 . V_14 = V_6 -> V_13 ;
V_4 -> V_15 = V_6 -> V_15 ;
return 0 ;
}
}
return - V_11 ;
}
static int F_6 ( struct V_5 * V_6 , int V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_18 ; V_17 ++ ) {
if ( V_6 -> V_16 [ V_17 ] == V_16 )
return V_17 ;
}
return - V_11 ;
}
int F_7 ( struct V_1 * V_2 ,
int V_14 , int V_16 )
{
struct V_5 * V_6 ;
F_4 (module, &ctx->uuid_list, list) {
if ( V_6 -> V_13 == V_14 )
return F_6 ( V_6 , V_16 ) ;
}
return - V_11 ;
}
static inline int F_8 ( struct V_5 * V_6 , T_2 * V_19 ,
int V_20 , int V_21 )
{
int V_22 , V_23 , V_17 ;
T_3 V_24 ;
V_23 = V_6 -> V_18 ;
V_24 = ( T_3 ) ( * V_19 >> V_20 ) ;
if ( V_24 != 0xffffffff ) {
V_22 = F_9 ( V_24 ) ;
V_17 = V_22 + V_20 + V_21 ;
if ( V_17 <= ( V_23 - 1 ) ) {
* V_19 |= 1 << ( V_22 + V_20 ) ;
return V_17 ;
}
}
return - V_11 ;
}
static inline int F_10 ( struct V_5 * V_6 )
{
int V_25 , V_26 , V_20 , V_21 = 0 , V_17 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ ) {
V_20 = 0 ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
V_17 = F_8 ( V_6 , & V_6 -> V_17 [ V_25 ] ,
V_20 , V_21 ) ;
if ( V_17 >= 0 )
return V_17 ;
V_20 += 32 ;
if ( ( V_20 + V_21 ) >= V_6 -> V_18 )
return - V_11 ;
}
V_21 += 64 ;
if ( V_21 >= V_6 -> V_18 )
return - V_11 ;
}
return - V_11 ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
T_1 * V_7 ;
int V_17 ;
V_7 = ( T_1 * ) V_4 -> V_8 ;
F_4 (module, &ctx->uuid_list, list) {
if ( F_5 ( * V_7 , V_6 -> V_12 ) == 0 ) {
V_17 = F_10 ( V_6 ) ;
if ( V_17 >= 0 ) {
V_6 -> V_16 [ V_17 ] =
V_4 -> V_13 . V_16 ;
return V_17 ;
}
}
}
return - V_11 ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_26 ;
T_1 * V_7 ;
struct V_5 * V_6 ;
V_7 = ( T_1 * ) V_4 -> V_8 ;
F_4 (module, &ctx->uuid_list, list) {
if ( F_5 ( * V_7 , V_6 -> V_12 ) == 0 ) {
if ( V_4 -> V_13 . V_17 != 0 )
V_26 = ( V_4 -> V_13 . V_17 ) / 64 ;
else
V_26 = 0 ;
V_6 -> V_17 [ V_26 ] &= ~ ( 1 << ( V_4 -> V_13 . V_17 ) ) ;
V_4 -> V_13 . V_17 = - 1 ;
return 0 ;
}
}
return - V_11 ;
}
int F_13 ( struct V_28 * V_2 , const struct V_29 * V_30 ,
unsigned int V_31 , int V_22 )
{
struct V_32 * V_33 ;
struct V_34 * V_35 ;
int V_26 , V_36 , V_37 ;
T_1 * V_38 ;
const char * V_39 ;
struct V_1 * V_40 = V_2 -> V_41 ;
struct V_5 * V_6 ;
struct V_29 V_42 ;
unsigned int V_43 ;
V_42 . V_44 = V_30 -> V_44 ;
V_42 . V_37 = V_30 -> V_37 ;
F_14 ( & V_42 ) ;
V_39 = V_42 . V_44 ;
V_43 = sizeof( * V_33 ) + V_31 ;
if ( V_42 . V_37 <= V_43 ) {
F_3 ( V_2 -> V_10 , L_2 ) ;
return - V_11 ;
}
V_33 = (struct V_32 * ) ( V_39 + V_31 ) ;
V_43 += V_33 -> V_45 + sizeof( * V_35 ) ;
if ( V_42 . V_37 <= V_43 ) {
F_3 ( V_2 -> V_10 , L_3 ) ;
return - V_11 ;
}
V_35 = (struct V_34 * )
( V_39 + V_31 + V_33 -> V_45 ) ;
V_36 = V_33 -> V_46 ;
V_43 += V_36 * sizeof( * V_35 ) ;
if ( V_42 . V_37 <= V_43 ) {
F_3 ( V_2 -> V_10 , L_4 ) ;
return - V_11 ;
}
for ( V_26 = 0 ; V_26 < V_36 ; V_26 ++ , V_35 ++ ) {
V_6 = F_15 ( sizeof( * V_6 ) , V_47 ) ;
if ( ! V_6 )
return - V_48 ;
V_38 = ( T_1 * ) V_35 -> V_12 . V_13 ;
memcpy ( & V_6 -> V_12 , V_38 , sizeof( V_6 -> V_12 ) ) ;
V_6 -> V_13 = ( V_26 | ( V_22 << 12 ) ) ;
V_6 -> V_15 = V_35 -> type . V_49 ;
V_6 -> V_18 = V_35 -> V_50 ;
V_37 = sizeof( int ) * V_35 -> V_50 ;
V_6 -> V_16 = F_16 ( V_2 -> V_10 , V_37 , V_47 ) ;
if ( ! V_6 -> V_16 ) {
F_17 ( V_6 ) ;
return - V_48 ;
}
F_18 ( & V_6 -> V_51 , & V_40 -> V_9 ) ;
F_19 ( V_2 -> V_10 ,
L_5 ,
& V_6 -> V_12 , V_6 -> V_13 , V_6 -> V_15 ) ;
}
return 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_12 , * V_52 ;
F_21 (uuid, _uuid, &ctx->uuid_list, list) {
F_22 ( & V_12 -> V_51 ) ;
F_17 ( V_12 ) ;
}
}
int F_14 ( struct V_29 * V_30 )
{
struct V_53 * V_54 ;
if ( V_30 -> V_37 < sizeof( V_54 ) ) {
F_23 ( L_6 , V_55 ) ;
return - V_11 ;
}
V_54 = (struct V_53 * ) V_30 -> V_44 ;
if ( V_54 -> V_13 == V_56 ) {
V_30 -> V_37 -= V_54 -> V_45 ;
V_30 -> V_44 += V_54 -> V_45 ;
}
return 0 ;
}

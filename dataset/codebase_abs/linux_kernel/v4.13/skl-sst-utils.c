static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_2 -> V_3 [ V_4 ] == V_3 )
return V_4 ;
}
return - V_6 ;
}
int F_2 ( struct V_7 * V_8 ,
int V_9 , int V_3 )
{
struct V_1 * V_2 ;
F_3 (module, &ctx->uuid_list, list) {
if ( V_2 -> V_10 == V_9 )
return F_1 ( V_2 , V_3 ) ;
}
return - V_6 ;
}
static inline int F_4 ( struct V_1 * V_2 , T_1 * V_11 ,
int V_12 , int V_13 )
{
int V_14 , V_15 , V_4 ;
T_2 V_16 ;
V_15 = V_2 -> V_5 ;
V_16 = ( T_2 ) ( * V_11 >> V_12 ) ;
if ( V_16 != 0xffffffff ) {
V_14 = F_5 ( V_16 ) ;
V_4 = V_14 + V_12 + V_13 ;
if ( V_4 <= ( V_15 - 1 ) ) {
* V_11 |= 1ULL << ( V_14 + V_12 ) ;
return V_4 ;
}
}
return - V_6 ;
}
static inline int F_6 ( struct V_1 * V_2 )
{
int V_17 , V_18 , V_12 , V_13 = 0 , V_4 ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ ) {
V_12 = 0 ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
V_4 = F_4 ( V_2 , & V_2 -> V_4 [ V_17 ] ,
V_12 , V_13 ) ;
if ( V_4 >= 0 )
return V_4 ;
V_12 += 32 ;
if ( ( V_12 + V_13 ) >= V_2 -> V_5 )
return - V_6 ;
}
V_13 += 64 ;
if ( V_13 >= V_2 -> V_5 )
return - V_6 ;
}
return - V_6 ;
}
int F_7 ( struct V_7 * V_8 , T_3 * V_20 , int V_3 )
{
struct V_1 * V_2 ;
int V_4 ;
F_3 (module, &ctx->uuid_list, list) {
if ( F_8 ( * V_20 , V_2 -> V_21 ) == 0 ) {
V_4 = F_6 ( V_2 ) ;
if ( V_4 >= 0 ) {
V_2 -> V_3 [ V_4 ] = V_3 ;
return V_4 ;
}
}
}
return - V_6 ;
}
int F_9 ( struct V_7 * V_8 , T_3 * V_20 , int * V_4 )
{
int V_18 ;
struct V_1 * V_2 ;
F_3 (module, &ctx->uuid_list, list) {
if ( F_8 ( * V_20 , V_2 -> V_21 ) == 0 ) {
if ( * V_4 != 0 )
V_18 = ( * V_4 ) / 64 ;
else
V_18 = 0 ;
V_2 -> V_4 [ V_18 ] &= ~ ( 1 << ( * V_4 ) ) ;
* V_4 = - 1 ;
return 0 ;
}
}
return - V_6 ;
}
int F_10 ( struct V_22 * V_8 , const struct V_23 * V_24 ,
unsigned int V_25 , int V_14 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_18 , V_30 , V_31 ;
T_3 * V_32 ;
const char * V_33 ;
struct V_7 * V_34 = V_8 -> V_35 ;
struct V_1 * V_2 ;
struct V_23 V_36 ;
unsigned int V_37 ;
V_36 . V_38 = V_24 -> V_38 ;
V_36 . V_31 = V_24 -> V_31 ;
F_11 ( & V_36 ) ;
V_33 = V_36 . V_38 ;
V_37 = sizeof( * V_27 ) + V_25 ;
if ( V_36 . V_31 <= V_37 ) {
F_12 ( V_8 -> V_39 , L_1 ) ;
return - V_6 ;
}
V_27 = (struct V_26 * ) ( V_33 + V_25 ) ;
V_37 += V_27 -> V_40 + sizeof( * V_29 ) ;
if ( V_36 . V_31 <= V_37 ) {
F_12 ( V_8 -> V_39 , L_2 ) ;
return - V_6 ;
}
V_29 = (struct V_28 * )
( V_33 + V_25 + V_27 -> V_40 ) ;
V_30 = V_27 -> V_41 ;
V_37 += V_30 * sizeof( * V_29 ) ;
if ( V_36 . V_31 <= V_37 ) {
F_12 ( V_8 -> V_39 , L_3 ) ;
return - V_6 ;
}
for ( V_18 = 0 ; V_18 < V_30 ; V_18 ++ , V_29 ++ ) {
V_2 = F_13 ( sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_32 = ( T_3 * ) V_29 -> V_21 . V_10 ;
memcpy ( & V_2 -> V_21 , V_32 , sizeof( V_2 -> V_21 ) ) ;
V_2 -> V_10 = ( V_18 | ( V_14 << 12 ) ) ;
V_2 -> V_44 = V_29 -> type . V_45 ;
V_2 -> V_5 = V_29 -> V_46 ;
V_31 = sizeof( int ) * V_29 -> V_46 ;
V_2 -> V_3 = F_14 ( V_8 -> V_39 , V_31 , V_42 ) ;
if ( ! V_2 -> V_3 ) {
F_15 ( V_2 ) ;
return - V_43 ;
}
F_16 ( & V_2 -> V_47 , & V_34 -> V_48 ) ;
F_17 ( V_8 -> V_39 ,
L_4 ,
& V_2 -> V_21 , V_2 -> V_10 , V_2 -> V_44 ) ;
}
return 0 ;
}
void F_18 ( struct V_7 * V_8 )
{
struct V_1 * V_21 , * V_49 ;
F_19 (uuid, _uuid, &ctx->uuid_list, list) {
F_20 ( & V_21 -> V_47 ) ;
F_15 ( V_21 ) ;
}
}
int F_11 ( struct V_23 * V_24 )
{
struct V_50 * V_51 ;
if ( V_24 -> V_31 < sizeof( V_51 ) ) {
F_21 ( L_5 , V_52 ) ;
return - V_6 ;
}
V_51 = (struct V_50 * ) V_24 -> V_38 ;
if ( V_51 -> V_10 == V_53 ) {
V_24 -> V_31 -= V_51 -> V_40 ;
V_24 -> V_38 += V_51 -> V_40 ;
}
return 0 ;
}
int F_22 ( struct V_54 * V_39 , int V_55 , const char * V_56 ,
struct V_57 V_58 , struct V_7 * * V_59 ,
struct V_60 * V_61 )
{
struct V_7 * V_34 ;
struct V_22 * V_62 ;
int V_63 ;
V_34 = F_14 ( V_39 , sizeof( * V_34 ) , V_42 ) ;
if ( V_34 == NULL )
return - V_43 ;
V_34 -> V_39 = V_39 ;
V_61 -> V_35 = V_34 ;
F_23 ( & V_34 -> V_48 ) ;
V_34 -> V_59 = F_24 ( V_39 , V_61 , V_55 ) ;
if ( ! V_34 -> V_59 ) {
F_12 ( V_34 -> V_39 , L_6 , V_52 ) ;
return - V_64 ;
}
V_62 = V_34 -> V_59 ;
V_62 -> V_56 = V_56 ;
V_62 -> V_58 = V_58 ;
F_25 ( & V_34 -> V_65 ) ;
F_23 ( & V_62 -> V_66 ) ;
V_63 = F_26 ( V_39 , V_34 ) ;
if ( V_63 )
return V_63 ;
V_34 -> V_67 = true ;
if ( V_59 )
* V_59 = V_34 ;
return V_63 ;
}
int F_27 ( struct V_7 * V_34 , struct V_68 * V_69 ,
struct V_23 * V_36 ,
unsigned int V_70 , int V_14 )
{
int V_63 ;
struct V_22 * V_59 = V_34 -> V_59 ;
if ( V_69 -> V_24 == NULL ) {
V_63 = F_28 ( & V_69 -> V_24 , V_69 -> V_71 ,
V_34 -> V_39 ) ;
if ( V_63 < 0 ) {
F_12 ( V_34 -> V_39 , L_7 ,
V_69 -> V_71 , V_63 ) ;
return V_63 ;
}
}
if ( V_34 -> V_67 ) {
V_63 = F_10 ( V_59 , V_69 -> V_24 , V_70 , V_14 ) ;
if ( V_63 < 0 )
return V_63 ;
}
V_36 -> V_38 = V_69 -> V_24 -> V_38 ;
V_36 -> V_31 = V_69 -> V_24 -> V_31 ;
F_11 ( V_36 ) ;
return 0 ;
}
void F_29 ( struct V_68 * V_69 , int V_72 )
{
int V_18 ;
for ( V_18 = 1 ; V_18 < V_72 ; V_18 ++ ) {
if ( V_69 [ V_18 ] . V_24 ) {
F_30 ( V_69 [ V_18 ] . V_24 ) ;
V_69 [ V_18 ] . V_24 = NULL ;
}
}
}

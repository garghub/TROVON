static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
if ( V_6 -> V_8 )
V_7 = ! ! F_2 ( V_4 -> V_9 ) ;
else
V_7 = ! ! F_3 ( V_4 -> V_9 ) ;
if ( V_7 != V_6 -> V_10 ) {
unsigned int type = V_4 -> type ? : V_11 ;
F_4 ( V_2 , type , V_4 -> V_12 ,
! ! ( V_7 ^ V_4 -> V_13 ) ) ;
F_5 ( V_2 ) ;
V_6 -> V_14 = 0 ;
V_6 -> V_10 = V_7 ;
}
}
static void F_6 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
const struct V_20 * V_21 = V_18 -> V_21 ;
struct V_1 * V_2 = V_16 -> V_2 ;
int V_22 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
struct V_5 * V_6 = & V_18 -> V_24 [ V_22 ] ;
if ( V_6 -> V_14 < V_6 -> V_25 )
V_6 -> V_14 ++ ;
else
F_1 ( V_2 , & V_21 -> V_26 [ V_22 ] ,
V_6 ) ;
}
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
const struct V_20 * V_21 = V_18 -> V_21 ;
if ( V_21 -> V_27 )
V_21 -> V_27 ( V_18 -> V_16 ) ;
}
static void F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
const struct V_20 * V_21 = V_18 -> V_21 ;
if ( V_21 -> V_28 )
V_21 -> V_28 ( V_18 -> V_16 ) ;
}
static struct V_20 * F_9 ( struct V_29 * V_16 )
{
struct V_30 * V_31 , * V_32 ;
struct V_20 * V_21 ;
struct V_3 * V_4 ;
int error ;
int V_23 ;
int V_22 ;
V_31 = V_16 -> V_33 ;
if ( ! V_31 )
return NULL ;
V_23 = F_10 ( V_31 ) ;
if ( V_23 == 0 )
return NULL ;
V_21 = F_11 ( V_16 , sizeof( * V_21 ) + V_23 * sizeof( * V_4 ) ,
V_34 ) ;
if ( ! V_21 )
return F_12 ( - V_35 ) ;
V_21 -> V_26 = (struct V_3 * ) ( V_21 + 1 ) ;
V_21 -> V_23 = V_23 ;
V_21 -> V_36 = ! ! F_13 ( V_31 , L_1 , NULL ) ;
F_14 ( V_31 , L_2 , & V_21 -> V_37 ) ;
V_22 = 0 ;
F_15 (node, pp) {
int V_9 ;
enum V_38 V_39 ;
if ( ! F_16 ( V_32 , L_3 , NULL ) ) {
V_21 -> V_23 -- ;
F_17 ( V_16 , L_4 ) ;
continue;
}
V_9 = F_18 ( V_32 , 0 , & V_39 ) ;
if ( V_9 < 0 ) {
error = V_9 ;
if ( error != - V_40 )
F_19 ( V_16 ,
L_5 ,
error ) ;
return F_12 ( error ) ;
}
V_4 = & V_21 -> V_26 [ V_22 ++ ] ;
V_4 -> V_9 = V_9 ;
V_4 -> V_13 = V_39 & V_41 ;
if ( F_14 ( V_32 , L_6 , & V_4 -> V_12 ) ) {
F_19 ( V_16 , L_7 ,
V_4 -> V_9 ) ;
return F_12 ( - V_42 ) ;
}
V_4 -> V_43 = F_13 ( V_32 , L_8 , NULL ) ;
if ( F_14 ( V_32 , L_9 , & V_4 -> type ) )
V_4 -> type = V_11 ;
V_4 -> V_44 = ! ! F_13 ( V_32 , L_10 , NULL ) ;
if ( F_14 ( V_32 , L_11 ,
& V_4 -> V_45 ) )
V_4 -> V_45 = 5 ;
}
if ( V_21 -> V_23 == 0 )
return F_12 ( - V_42 ) ;
return V_21 ;
}
static inline struct V_20 *
F_9 ( struct V_29 * V_16 )
{
return NULL ;
}
static int F_20 ( struct V_46 * V_47 )
{
struct V_29 * V_16 = & V_47 -> V_16 ;
const struct V_20 * V_21 = F_21 ( V_16 ) ;
struct V_17 * V_18 ;
struct V_15 * V_48 ;
struct V_1 * V_2 ;
T_1 V_49 ;
int error ;
int V_22 ;
if ( ! V_21 ) {
V_21 = F_9 ( V_16 ) ;
if ( F_22 ( V_21 ) )
return F_23 ( V_21 ) ;
if ( ! V_21 ) {
F_19 ( V_16 , L_12 ) ;
return - V_42 ;
}
}
if ( ! V_21 -> V_37 ) {
F_19 ( V_16 , L_13 ) ;
return - V_42 ;
}
V_49 = sizeof( struct V_17 ) +
V_21 -> V_23 * sizeof( struct V_5 ) ;
V_18 = F_11 ( & V_47 -> V_16 , V_49 , V_34 ) ;
if ( ! V_18 ) {
F_19 ( V_16 , L_14 ) ;
return - V_35 ;
}
V_48 = F_24 ( & V_47 -> V_16 ) ;
if ( ! V_48 ) {
F_19 ( V_16 , L_15 ) ;
return - V_35 ;
}
V_48 -> V_19 = V_18 ;
V_48 -> V_50 = F_6 ;
V_48 -> V_37 = V_21 -> V_37 ;
V_48 -> V_51 = F_7 ;
V_48 -> V_52 = F_8 ;
V_2 = V_48 -> V_2 ;
V_2 -> V_53 = V_47 -> V_53 ;
V_2 -> V_54 = V_55 L_16 ;
V_2 -> V_56 . V_57 = V_58 ;
V_2 -> V_56 . V_59 = 0x0001 ;
V_2 -> V_56 . V_60 = 0x0001 ;
V_2 -> V_56 . V_61 = 0x0100 ;
F_25 ( V_11 , V_2 -> V_62 ) ;
if ( V_21 -> V_36 )
F_25 ( V_63 , V_2 -> V_62 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
struct V_3 * V_4 = & V_21 -> V_26 [ V_22 ] ;
struct V_5 * V_6 = & V_18 -> V_24 [ V_22 ] ;
unsigned int V_9 = V_4 -> V_9 ;
unsigned int type = V_4 -> type ? : V_11 ;
if ( V_4 -> V_44 ) {
F_19 ( V_16 , V_55 L_17 ) ;
return - V_42 ;
}
error = F_26 ( & V_47 -> V_16 , V_9 , V_64 ,
V_4 -> V_43 ? : V_55 ) ;
if ( error ) {
F_19 ( V_16 , L_18 ,
V_9 , error ) ;
return error ;
}
V_6 -> V_8 = F_27 ( V_9 ) ;
V_6 -> V_10 = - 1 ;
V_6 -> V_25 = F_28 ( V_4 -> V_45 ,
V_21 -> V_37 ) ;
F_29 ( V_2 , type , V_4 -> V_12 ) ;
}
V_18 -> V_48 = V_48 ;
V_18 -> V_16 = V_16 ;
V_18 -> V_21 = V_21 ;
F_30 ( V_47 , V_18 ) ;
error = F_31 ( V_48 ) ;
if ( error ) {
F_19 ( V_16 , L_19 ,
error ) ;
return error ;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ )
F_1 ( V_2 , & V_21 -> V_26 [ V_22 ] ,
& V_18 -> V_24 [ V_22 ] ) ;
return 0 ;
}

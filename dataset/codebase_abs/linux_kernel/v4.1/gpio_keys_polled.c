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
F_4 ( V_2 , type , V_4 -> V_12 , V_7 ) ;
F_5 ( V_2 ) ;
V_6 -> V_13 = 0 ;
V_6 -> V_10 = V_7 ;
}
}
static void F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
const struct V_19 * V_20 = V_17 -> V_20 ;
struct V_1 * V_2 = V_15 -> V_2 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_20 -> V_22 ; V_21 ++ ) {
struct V_5 * V_6 = & V_17 -> V_23 [ V_21 ] ;
if ( V_6 -> V_13 < V_6 -> V_24 )
V_6 -> V_13 ++ ;
else
F_1 ( V_2 , & V_20 -> V_25 [ V_21 ] ,
V_6 ) ;
}
}
static void F_7 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
const struct V_19 * V_20 = V_17 -> V_20 ;
if ( V_20 -> V_26 )
V_20 -> V_26 ( V_17 -> V_15 ) ;
}
static void F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_18 ;
const struct V_19 * V_20 = V_17 -> V_20 ;
if ( V_20 -> V_27 )
V_20 -> V_27 ( V_17 -> V_15 ) ;
}
static struct V_19 * F_9 ( struct V_28 * V_15 )
{
struct V_19 * V_20 ;
struct V_3 * V_4 ;
struct V_29 * V_30 ;
int error ;
int V_22 ;
V_22 = F_10 ( V_15 ) ;
if ( V_22 == 0 )
return NULL ;
V_20 = F_11 ( V_15 , sizeof( * V_20 ) + V_22 * sizeof( * V_4 ) ,
V_31 ) ;
if ( ! V_20 )
return F_12 ( - V_32 ) ;
V_20 -> V_25 = (struct V_3 * ) ( V_20 + 1 ) ;
V_20 -> V_33 = F_13 ( V_15 , L_1 ) ;
F_14 ( V_15 , L_2 , & V_20 -> V_34 ) ;
F_15 (dev, child) {
struct V_35 * V_36 ;
V_36 = F_16 ( V_15 , NULL , V_30 ) ;
if ( F_17 ( V_36 ) ) {
error = F_18 ( V_36 ) ;
if ( error != - V_37 )
F_19 ( V_15 ,
L_3 ,
error ) ;
F_20 ( V_30 ) ;
return F_12 ( error ) ;
}
V_4 = & V_20 -> V_25 [ V_20 -> V_22 ++ ] ;
V_4 -> V_9 = V_36 ;
if ( F_21 ( V_30 , L_4 , & V_4 -> V_12 ) ) {
F_19 ( V_15 , L_5 ,
V_20 -> V_22 - 1 ) ;
F_20 ( V_30 ) ;
return F_12 ( - V_38 ) ;
}
F_22 ( V_30 , L_6 , & V_4 -> V_36 ) ;
if ( F_21 ( V_30 , L_7 ,
& V_4 -> type ) )
V_4 -> type = V_11 ;
V_4 -> V_39 = F_23 ( V_30 , L_8 ) ;
if ( F_21 ( V_30 , L_9 ,
& V_4 -> V_40 ) )
V_4 -> V_40 = 5 ;
}
if ( V_20 -> V_22 == 0 )
return F_12 ( - V_38 ) ;
return V_20 ;
}
static int F_24 ( struct V_41 * V_42 )
{
struct V_28 * V_15 = & V_42 -> V_15 ;
const struct V_19 * V_20 = F_25 ( V_15 ) ;
struct V_16 * V_17 ;
struct V_14 * V_43 ;
struct V_1 * V_2 ;
T_1 V_44 ;
int error ;
int V_21 ;
if ( ! V_20 ) {
V_20 = F_9 ( V_15 ) ;
if ( F_17 ( V_20 ) )
return F_18 ( V_20 ) ;
if ( ! V_20 ) {
F_19 ( V_15 , L_10 ) ;
return - V_38 ;
}
}
if ( ! V_20 -> V_34 ) {
F_19 ( V_15 , L_11 ) ;
return - V_38 ;
}
V_44 = sizeof( struct V_16 ) +
V_20 -> V_22 * sizeof( struct V_5 ) ;
V_17 = F_11 ( & V_42 -> V_15 , V_44 , V_31 ) ;
if ( ! V_17 ) {
F_19 ( V_15 , L_12 ) ;
return - V_32 ;
}
V_43 = F_26 ( & V_42 -> V_15 ) ;
if ( ! V_43 ) {
F_19 ( V_15 , L_13 ) ;
return - V_32 ;
}
V_43 -> V_18 = V_17 ;
V_43 -> V_45 = F_6 ;
V_43 -> V_34 = V_20 -> V_34 ;
V_43 -> V_46 = F_7 ;
V_43 -> V_47 = F_8 ;
V_2 = V_43 -> V_2 ;
V_2 -> V_48 = V_42 -> V_48 ;
V_2 -> V_49 = V_50 L_14 ;
V_2 -> V_51 . V_52 = V_53 ;
V_2 -> V_51 . V_54 = 0x0001 ;
V_2 -> V_51 . V_55 = 0x0001 ;
V_2 -> V_51 . V_56 = 0x0100 ;
F_27 ( V_11 , V_2 -> V_57 ) ;
if ( V_20 -> V_33 )
F_27 ( V_58 , V_2 -> V_57 ) ;
for ( V_21 = 0 ; V_21 < V_20 -> V_22 ; V_21 ++ ) {
struct V_3 * V_4 = & V_20 -> V_25 [ V_21 ] ;
struct V_5 * V_6 = & V_17 -> V_23 [ V_21 ] ;
unsigned int type = V_4 -> type ? : V_11 ;
if ( V_4 -> V_39 ) {
F_19 ( V_15 , V_50 L_15 ) ;
return - V_38 ;
}
if ( ! V_4 -> V_9 && F_28 ( V_4 -> V_59 ) ) {
unsigned V_60 = 0 ;
if ( V_4 -> V_61 )
V_60 |= V_62 ;
error = F_29 ( & V_42 -> V_15 , V_4 -> V_59 ,
V_60 , V_4 -> V_36 ? : V_50 ) ;
if ( error ) {
F_19 ( V_15 , L_16 ,
V_4 -> V_59 , error ) ;
return error ;
}
V_4 -> V_9 = F_30 ( V_4 -> V_59 ) ;
}
if ( F_17 ( V_4 -> V_9 ) )
return F_18 ( V_4 -> V_9 ) ;
V_6 -> V_8 = F_31 ( V_4 -> V_9 ) ;
V_6 -> V_10 = - 1 ;
V_6 -> V_24 = F_32 ( V_4 -> V_40 ,
V_20 -> V_34 ) ;
F_33 ( V_2 , type , V_4 -> V_12 ) ;
}
V_17 -> V_43 = V_43 ;
V_17 -> V_15 = V_15 ;
V_17 -> V_20 = V_20 ;
F_34 ( V_42 , V_17 ) ;
error = F_35 ( V_43 ) ;
if ( error ) {
F_19 ( V_15 , L_17 ,
error ) ;
return error ;
}
for ( V_21 = 0 ; V_21 < V_20 -> V_22 ; V_21 ++ )
F_1 ( V_2 , & V_20 -> V_25 [ V_21 ] ,
& V_17 -> V_23 [ V_21 ] ) ;
return 0 ;
}

static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int type = V_4 -> type ? : V_11 ;
if ( type == V_12 ) {
if ( V_5 ) {
F_2 ( V_10 , type , V_4 -> V_13 , V_4 -> V_14 ) ;
F_3 ( V_4 -> V_13 , V_7 -> V_15 ) ;
}
} else if ( type == V_16 ) {
if ( V_5 ) {
F_2 ( V_10 , type , V_4 -> V_13 , V_4 -> V_14 ) ;
F_3 ( V_4 -> V_13 , V_7 -> V_17 ) ;
}
} else {
F_2 ( V_10 , type , V_4 -> V_13 , V_5 ) ;
F_4 ( V_10 ) ;
}
}
static void F_5 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_18 * V_19 )
{
int V_5 ;
V_5 = F_6 ( V_19 -> V_20 ) ;
if ( V_5 < 0 ) {
F_7 ( V_2 -> V_10 -> V_2 . V_21 ,
L_1 , V_5 ) ;
} else {
F_1 ( V_2 , V_4 , V_5 ) ;
if ( V_5 != V_19 -> V_22 ) {
V_19 -> V_23 = 0 ;
V_19 -> V_22 = V_5 ;
}
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
const struct V_24 * V_25 = V_7 -> V_25 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_26 ;
memset ( V_7 -> V_15 , 0 , sizeof( V_7 -> V_15 ) ) ;
memset ( V_7 -> V_17 , 0 , sizeof( V_7 -> V_17 ) ) ;
for ( V_26 = 0 ; V_26 < V_25 -> V_27 ; V_26 ++ ) {
struct V_18 * V_19 = & V_7 -> V_28 [ V_26 ] ;
if ( V_19 -> V_23 < V_19 -> V_29 ) {
V_19 -> V_23 ++ ;
F_1 ( V_2 , & V_25 -> V_30 [ V_26 ] ,
V_19 -> V_22 ) ;
} else {
F_5 ( V_2 , & V_25 -> V_30 [ V_26 ] ,
V_19 ) ;
}
}
F_9 (i, input->relbit, REL_CNT) {
if ( ! F_10 ( V_26 , V_7 -> V_15 ) )
F_2 ( V_10 , V_12 , V_26 , 0 ) ;
}
F_9 (i, input->absbit, ABS_CNT) {
if ( ! F_10 ( V_26 , V_7 -> V_17 ) )
F_2 ( V_10 , V_16 , V_26 , 0 ) ;
}
F_4 ( V_10 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
const struct V_24 * V_25 = V_7 -> V_25 ;
if ( V_25 -> V_31 )
V_25 -> V_31 ( V_7 -> V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
const struct V_24 * V_25 = V_7 -> V_25 ;
if ( V_25 -> V_32 )
V_25 -> V_32 ( V_7 -> V_2 ) ;
}
static struct V_24 *
F_13 ( struct V_33 * V_2 )
{
struct V_24 * V_25 ;
struct V_3 * V_4 ;
struct V_34 * V_35 ;
int V_27 ;
V_27 = F_14 ( V_2 ) ;
if ( V_27 == 0 )
return F_15 ( - V_36 ) ;
V_25 = F_16 ( V_2 , sizeof( * V_25 ) + V_27 * sizeof( * V_4 ) ,
V_37 ) ;
if ( ! V_25 )
return F_15 ( - V_38 ) ;
V_4 = (struct V_3 * ) ( V_25 + 1 ) ;
V_25 -> V_30 = V_4 ;
V_25 -> V_27 = V_27 ;
V_25 -> V_39 = F_17 ( V_2 , L_2 ) ;
F_18 ( V_2 , L_3 , & V_25 -> V_40 ) ;
F_19 (dev, child) {
if ( F_20 ( V_35 , L_4 ,
& V_4 -> V_13 ) ) {
F_7 ( V_2 , L_5 ) ;
F_21 ( V_35 ) ;
return F_15 ( - V_36 ) ;
}
F_22 ( V_35 , L_6 , & V_4 -> V_41 ) ;
if ( F_20 ( V_35 , L_7 ,
& V_4 -> type ) )
V_4 -> type = V_11 ;
if ( F_20 ( V_35 , L_8 ,
( V_42 * ) & V_4 -> V_14 ) )
V_4 -> V_14 = 1 ;
V_4 -> V_43 =
F_23 ( V_35 , L_9 ) ||
F_23 ( V_35 , L_10 ) ;
if ( F_20 ( V_35 , L_11 ,
& V_4 -> V_44 ) )
V_4 -> V_44 = 5 ;
V_4 ++ ;
}
return V_25 ;
}
static void F_24 ( struct V_9 * V_10 ,
const struct V_24 * V_25 , unsigned int V_13 )
{
int V_26 , V_45 = 0 , V_46 = 0 ;
for ( V_26 = 0 ; V_26 < V_25 -> V_27 ; V_26 ++ ) {
const struct V_3 * V_4 = & V_25 -> V_30 [ V_26 ] ;
if ( V_4 -> type != V_16 || V_4 -> V_13 != V_13 )
continue;
if ( V_4 -> V_14 < V_45 )
V_45 = V_4 -> V_14 ;
if ( V_4 -> V_14 > V_46 )
V_46 = V_4 -> V_14 ;
}
F_25 ( V_10 , V_13 , V_45 , V_46 , 0 , 0 ) ;
}
static int F_26 ( struct V_47 * V_48 )
{
struct V_33 * V_2 = & V_48 -> V_2 ;
struct V_34 * V_35 = NULL ;
const struct V_24 * V_25 = F_27 ( V_2 ) ;
struct V_6 * V_7 ;
struct V_1 * V_49 ;
struct V_9 * V_10 ;
T_1 V_50 ;
int error ;
int V_26 ;
if ( ! V_25 ) {
V_25 = F_13 ( V_2 ) ;
if ( F_28 ( V_25 ) )
return F_29 ( V_25 ) ;
}
if ( ! V_25 -> V_40 ) {
F_7 ( V_2 , L_12 ) ;
return - V_36 ;
}
V_50 = sizeof( struct V_6 ) +
V_25 -> V_27 * sizeof( struct V_18 ) ;
V_7 = F_16 ( V_2 , V_50 , V_37 ) ;
if ( ! V_7 ) {
F_7 ( V_2 , L_13 ) ;
return - V_38 ;
}
V_49 = F_30 ( V_2 ) ;
if ( ! V_49 ) {
F_7 ( V_2 , L_14 ) ;
return - V_38 ;
}
V_49 -> V_8 = V_7 ;
V_49 -> V_51 = F_8 ;
V_49 -> V_40 = V_25 -> V_40 ;
V_49 -> V_52 = F_11 ;
V_49 -> V_53 = F_12 ;
V_10 = V_49 -> V_10 ;
V_10 -> V_54 = V_48 -> V_54 ;
V_10 -> V_55 = V_56 L_15 ;
V_10 -> V_57 . V_58 = V_59 ;
V_10 -> V_57 . V_60 = 0x0001 ;
V_10 -> V_57 . V_61 = 0x0001 ;
V_10 -> V_57 . V_62 = 0x0100 ;
F_3 ( V_11 , V_10 -> V_63 ) ;
if ( V_25 -> V_39 )
F_3 ( V_64 , V_10 -> V_63 ) ;
for ( V_26 = 0 ; V_26 < V_25 -> V_27 ; V_26 ++ ) {
const struct V_3 * V_4 = & V_25 -> V_30 [ V_26 ] ;
struct V_18 * V_19 = & V_7 -> V_28 [ V_26 ] ;
unsigned int type = V_4 -> type ? : V_11 ;
if ( V_4 -> V_43 ) {
F_7 ( V_2 , V_56 L_16 ) ;
F_21 ( V_35 ) ;
return - V_36 ;
}
if ( ! F_27 ( V_2 ) ) {
V_35 = F_31 ( V_2 , V_35 ) ;
if ( ! V_35 ) {
F_7 ( V_2 , L_17 ) ;
return - V_36 ;
}
V_19 -> V_20 = F_32 ( V_2 ,
NULL , V_35 ,
V_65 ,
V_4 -> V_41 ) ;
if ( F_28 ( V_19 -> V_20 ) ) {
error = F_29 ( V_19 -> V_20 ) ;
if ( error != - V_66 )
F_7 ( V_2 ,
L_18 ,
error ) ;
F_21 ( V_35 ) ;
return error ;
}
} else if ( F_33 ( V_4 -> V_67 ) ) {
unsigned V_68 = V_69 ;
if ( V_4 -> V_70 )
V_68 |= V_71 ;
error = F_34 ( V_2 , V_4 -> V_67 ,
V_68 , V_4 -> V_41 ? : V_56 ) ;
if ( error ) {
F_7 ( V_2 ,
L_19 ,
V_4 -> V_67 , error ) ;
return error ;
}
V_19 -> V_20 = F_35 ( V_4 -> V_67 ) ;
if ( ! V_19 -> V_20 ) {
F_7 ( V_2 ,
L_20 ,
V_4 -> V_67 ) ;
return - V_36 ;
}
}
V_19 -> V_22 = - 1 ;
V_19 -> V_29 = F_36 ( V_4 -> V_44 ,
V_25 -> V_40 ) ;
F_37 ( V_10 , type , V_4 -> V_13 ) ;
if ( type == V_16 )
F_24 ( V_10 , V_25 ,
V_4 -> V_13 ) ;
}
F_21 ( V_35 ) ;
V_7 -> V_49 = V_49 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_25 = V_25 ;
error = F_38 ( V_49 ) ;
if ( error ) {
F_7 ( V_2 , L_21 ,
error ) ;
return error ;
}
for ( V_26 = 0 ; V_26 < V_25 -> V_27 ; V_26 ++ )
F_5 ( V_49 , & V_25 -> V_30 [ V_26 ] ,
& V_7 -> V_28 [ V_26 ] ) ;
F_4 ( V_10 ) ;
return 0 ;
}

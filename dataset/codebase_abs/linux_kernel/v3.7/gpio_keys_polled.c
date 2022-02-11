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
static struct V_20 * T_1
F_9 ( struct V_29 * V_16 )
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
V_21 = F_11 ( sizeof( * V_21 ) + V_23 * ( sizeof *V_4 ) ,
V_34 ) ;
if ( ! V_21 ) {
error = - V_35 ;
goto V_36;
}
V_21 -> V_26 = (struct V_3 * ) ( V_21 + 1 ) ;
V_21 -> V_23 = V_23 ;
V_21 -> V_37 = ! ! F_12 ( V_31 , L_1 , NULL ) ;
F_13 ( V_31 , L_2 , & V_21 -> V_38 ) ;
V_22 = 0 ;
F_14 (node, pp) {
enum V_39 V_40 ;
if ( ! F_15 ( V_32 , L_3 , NULL ) ) {
V_21 -> V_23 -- ;
F_16 ( V_16 , L_4 ) ;
continue;
}
V_4 = & V_21 -> V_26 [ V_22 ++ ] ;
V_4 -> V_9 = F_17 ( V_32 , 0 , & V_40 ) ;
V_4 -> V_13 = V_40 & V_41 ;
if ( F_13 ( V_32 , L_5 , & V_4 -> V_12 ) ) {
F_18 ( V_16 , L_6 ,
V_4 -> V_9 ) ;
error = - V_42 ;
goto V_43;
}
V_4 -> V_44 = F_12 ( V_32 , L_7 , NULL ) ;
if ( F_13 ( V_32 , L_8 , & V_4 -> type ) )
V_4 -> type = V_11 ;
V_4 -> V_45 = ! ! F_12 ( V_32 , L_9 , NULL ) ;
if ( F_13 ( V_32 , L_10 ,
& V_4 -> V_46 ) )
V_4 -> V_46 = 5 ;
}
if ( V_21 -> V_23 == 0 ) {
error = - V_42 ;
goto V_43;
}
return V_21 ;
V_43:
F_19 ( V_21 ) ;
V_36:
return F_20 ( error ) ;
}
static inline struct V_20 *
F_9 ( struct V_29 * V_16 )
{
return NULL ;
}
static int T_1 F_21 ( struct V_47 * V_48 )
{
struct V_29 * V_16 = & V_48 -> V_16 ;
const struct V_20 * V_21 = F_22 ( V_16 ) ;
struct V_17 * V_18 ;
struct V_15 * V_49 ;
struct V_1 * V_2 ;
int error ;
int V_22 ;
if ( ! V_21 ) {
V_21 = F_9 ( V_16 ) ;
if ( F_23 ( V_21 ) )
return F_24 ( V_21 ) ;
if ( ! V_21 ) {
F_18 ( V_16 , L_11 ) ;
return - V_42 ;
}
}
if ( ! V_21 -> V_38 ) {
F_18 ( V_16 , L_12 ) ;
error = - V_42 ;
goto V_43;
}
V_18 = F_11 ( sizeof( struct V_17 ) +
V_21 -> V_23 * sizeof( struct V_5 ) ,
V_34 ) ;
if ( ! V_18 ) {
F_18 ( V_16 , L_13 ) ;
error = - V_35 ;
goto V_43;
}
V_49 = F_25 () ;
if ( ! V_49 ) {
F_18 ( V_16 , L_14 ) ;
error = - V_35 ;
goto V_50;
}
V_49 -> V_19 = V_18 ;
V_49 -> V_51 = F_6 ;
V_49 -> V_38 = V_21 -> V_38 ;
V_49 -> V_52 = F_7 ;
V_49 -> V_53 = F_8 ;
V_2 = V_49 -> V_2 ;
V_2 -> V_54 [ 0 ] = F_26 ( V_11 ) ;
V_2 -> V_55 = V_48 -> V_55 ;
V_2 -> V_56 = V_57 L_15 ;
V_2 -> V_16 . V_58 = & V_48 -> V_16 ;
V_2 -> V_59 . V_60 = V_61 ;
V_2 -> V_59 . V_62 = 0x0001 ;
V_2 -> V_59 . V_63 = 0x0001 ;
V_2 -> V_59 . V_64 = 0x0100 ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ ) {
struct V_3 * V_4 = & V_21 -> V_26 [ V_22 ] ;
struct V_5 * V_6 = & V_18 -> V_24 [ V_22 ] ;
unsigned int V_9 = V_4 -> V_9 ;
unsigned int type = V_4 -> type ? : V_11 ;
if ( V_4 -> V_45 ) {
F_18 ( V_16 , V_57 L_16 ) ;
error = - V_42 ;
goto V_65;
}
error = F_27 ( V_9 ,
V_4 -> V_44 ? V_4 -> V_44 : V_57 ) ;
if ( error ) {
F_18 ( V_16 , L_17 ,
V_9 , error ) ;
goto V_65;
}
error = F_28 ( V_9 ) ;
if ( error ) {
F_18 ( V_16 ,
L_18 ,
V_9 , error ) ;
goto V_65;
}
V_6 -> V_8 = F_29 ( V_9 ) ;
V_6 -> V_10 = - 1 ;
V_6 -> V_25 = F_30 ( V_4 -> V_46 ,
V_21 -> V_38 ) ;
F_31 ( V_2 , type , V_4 -> V_12 ) ;
}
V_18 -> V_49 = V_49 ;
V_18 -> V_16 = V_16 ;
V_18 -> V_21 = V_21 ;
F_32 ( V_48 , V_18 ) ;
error = F_33 ( V_49 ) ;
if ( error ) {
F_18 ( V_16 , L_19 ,
error ) ;
goto V_65;
}
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ )
F_1 ( V_2 , & V_21 -> V_26 [ V_22 ] ,
& V_18 -> V_24 [ V_22 ] ) ;
return 0 ;
V_65:
while ( -- V_22 >= 0 )
F_34 ( V_21 -> V_26 [ V_22 ] . V_9 ) ;
F_35 ( V_49 ) ;
V_50:
F_19 ( V_18 ) ;
F_32 ( V_48 , NULL ) ;
V_43:
if ( ! F_22 ( & V_48 -> V_16 ) )
F_19 ( V_21 ) ;
return error ;
}
static int T_2 F_36 ( struct V_47 * V_48 )
{
struct V_17 * V_18 = F_37 ( V_48 ) ;
const struct V_20 * V_21 = V_18 -> V_21 ;
int V_22 ;
F_38 ( V_18 -> V_49 ) ;
for ( V_22 = 0 ; V_22 < V_21 -> V_23 ; V_22 ++ )
F_34 ( V_21 -> V_26 [ V_22 ] . V_9 ) ;
F_35 ( V_18 -> V_49 ) ;
if ( ! F_22 ( & V_48 -> V_16 ) )
F_19 ( V_21 ) ;
F_19 ( V_18 ) ;
F_32 ( V_48 , NULL ) ;
return 0 ;
}

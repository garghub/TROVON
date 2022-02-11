const struct V_1 * V_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
int F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * args )
{
struct V_10 * V_11 = V_8 -> V_12 ;
unsigned int V_13 = F_3 ( args -> V_14 * args -> V_15 , 8 ) ;
unsigned int V_16 ;
if ( F_4 ( V_11 , V_17 ) )
V_16 = 128 ;
else
V_16 = 16 * args -> V_15 / 8 ;
args -> V_18 = F_5 ( F_6 ( args -> V_18 , V_13 ) , V_16 ) ;
return F_7 ( V_6 , V_8 , args ) ;
}
static struct V_19 *
F_8 ( struct V_7 * V_8 , struct V_5 * V_20 ,
struct V_21 * V_22 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
const struct V_1 * V_23 ;
unsigned int V_16 ;
V_23 = V_1 ( V_22 -> V_24 ) ;
if ( V_23 == NULL ) {
F_9 ( V_8 -> V_8 , L_1 ,
V_22 -> V_24 ) ;
return F_10 ( - V_25 ) ;
}
if ( F_4 ( V_11 , V_17 ) )
V_16 = 128 ;
else
V_16 = 16 * V_23 -> V_15 / 8 ;
if ( V_22 -> V_26 [ 0 ] & ( V_16 - 1 ) ||
V_22 -> V_26 [ 0 ] >= 8192 ) {
F_9 ( V_8 -> V_8 , L_2 ,
V_22 -> V_26 [ 0 ] ) ;
return F_10 ( - V_25 ) ;
}
if ( V_23 -> V_27 == 2 ) {
if ( V_22 -> V_26 [ 1 ] != V_22 -> V_26 [ 0 ] ) {
F_9 ( V_8 -> V_8 ,
L_3 ) ;
return F_10 ( - V_25 ) ;
}
}
return F_11 ( V_8 , V_20 , V_22 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
F_13 ( V_11 -> V_28 ) ;
}
int F_14 ( struct V_10 * V_11 )
{
static const unsigned int V_29 [] = {
V_30 , V_31
} ;
struct V_7 * V_8 = V_11 -> V_32 ;
struct V_33 * V_34 ;
struct V_35 * V_28 ;
unsigned int V_36 ;
unsigned int V_3 ;
int V_37 ;
F_15 ( V_8 ) ;
V_8 -> V_38 . V_39 = 0 ;
V_8 -> V_38 . V_40 = 0 ;
V_8 -> V_38 . V_41 = 4095 ;
V_8 -> V_38 . V_42 = 2047 ;
V_8 -> V_38 . V_43 = & V_44 ;
V_11 -> V_45 = V_11 -> V_46 -> V_45 ;
V_36 = F_3 ( V_11 -> V_45 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_36 ; ++ V_3 ) {
struct V_47 * V_48 = & V_11 -> V_49 [ V_3 ] ;
V_48 -> V_8 = V_11 ;
V_48 -> V_50 = V_29 [ V_3 ] ;
V_48 -> V_51 = V_3 ;
V_37 = F_16 ( V_48 ) ;
if ( V_37 < 0 )
return V_37 ;
}
for ( V_3 = 0 ; V_3 < V_11 -> V_45 ; ++ V_3 ) {
struct V_47 * V_48 = & V_11 -> V_49 [ V_3 / 2 ] ;
V_37 = F_17 ( V_48 , V_3 ) ;
if ( V_37 < 0 )
return V_37 ;
}
V_37 = F_18 ( V_11 ) ;
if ( V_37 < 0 )
return V_37 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_52 -> V_53 ; ++ V_3 ) {
const struct V_54 * V_52 =
& V_11 -> V_52 -> V_55 [ V_3 ] ;
const struct V_56 * V_57 =
& V_11 -> V_46 -> V_58 [ V_52 -> V_59 ] ;
if ( V_52 -> type == V_60 )
continue;
if ( V_52 -> V_59 >= V_61 ||
V_57 -> V_62 == 0 ) {
F_19 ( V_11 -> V_8 ,
L_4 ,
V_3 , V_52 -> V_59 ) ;
continue;
}
F_20 ( V_11 , V_52 -> type , V_52 -> V_59 , V_52 ) ;
}
F_21 (encoder, &dev->mode_config.encoder_list, head) {
struct V_63 * V_64 = F_22 ( V_34 ) ;
const struct V_56 * V_57 =
& V_11 -> V_46 -> V_58 [ V_64 -> V_59 ] ;
V_34 -> V_62 = V_57 -> V_62 ;
V_34 -> V_65 = ( 1 << V_11 -> V_52 -> V_53 ) - 1 ;
}
for ( V_3 = 0 ; V_3 < V_36 ; ++ V_3 ) {
V_37 = F_23 ( & V_11 -> V_49 [ V_3 ] ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_24 ( V_8 ) ;
F_25 ( V_8 ) ;
V_28 = F_26 ( V_8 , 32 , V_8 -> V_38 . V_66 ,
V_8 -> V_38 . V_67 ) ;
if ( F_27 ( V_28 ) )
return F_28 ( V_28 ) ;
#ifndef F_29
F_30 ( V_28 ) ;
#endif
V_11 -> V_28 = V_28 ;
return 0 ;
}

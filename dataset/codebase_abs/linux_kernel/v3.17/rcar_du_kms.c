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
unsigned int V_24 ;
unsigned int V_16 ;
unsigned int V_15 ;
V_23 = V_1 ( V_22 -> V_25 ) ;
if ( V_23 == NULL ) {
F_9 ( V_8 -> V_8 , L_1 ,
V_22 -> V_25 ) ;
return F_10 ( - V_26 ) ;
}
V_15 = V_23 -> V_27 == 2 ? 1 : V_23 -> V_15 / 8 ;
V_24 = 4096 * V_15 ;
if ( F_4 ( V_11 , V_17 ) )
V_16 = 128 ;
else
V_16 = 16 * V_15 ;
if ( V_22 -> V_28 [ 0 ] & ( V_16 - 1 ) ||
V_22 -> V_28 [ 0 ] >= V_24 ) {
F_9 ( V_8 -> V_8 , L_2 ,
V_22 -> V_28 [ 0 ] ) ;
return F_10 ( - V_26 ) ;
}
if ( V_23 -> V_27 == 2 ) {
if ( V_22 -> V_28 [ 1 ] != V_22 -> V_28 [ 0 ] ) {
F_9 ( V_8 -> V_8 ,
L_3 ) ;
return F_10 ( - V_26 ) ;
}
}
return F_11 ( V_8 , V_20 , V_22 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = V_8 -> V_12 ;
F_13 ( V_11 -> V_29 ) ;
}
int F_14 ( struct V_10 * V_11 )
{
static const unsigned int V_30 [] = {
V_31 , V_32
} ;
struct V_7 * V_8 = V_11 -> V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_29 ;
unsigned int V_37 ;
unsigned int V_3 ;
int V_38 ;
F_15 ( V_8 ) ;
V_8 -> V_39 . V_40 = 0 ;
V_8 -> V_39 . V_41 = 0 ;
V_8 -> V_39 . V_42 = 4095 ;
V_8 -> V_39 . V_43 = 2047 ;
V_8 -> V_39 . V_44 = & V_45 ;
V_11 -> V_46 = V_11 -> V_47 -> V_46 ;
V_37 = F_3 ( V_11 -> V_46 , 2 ) ;
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
struct V_48 * V_49 = & V_11 -> V_50 [ V_3 ] ;
V_49 -> V_8 = V_11 ;
V_49 -> V_51 = V_30 [ V_3 ] ;
V_49 -> V_52 = V_3 ;
V_38 = F_16 ( V_49 ) ;
if ( V_38 < 0 )
return V_38 ;
}
for ( V_3 = 0 ; V_3 < V_11 -> V_46 ; ++ V_3 ) {
struct V_48 * V_49 = & V_11 -> V_50 [ V_3 / 2 ] ;
V_38 = F_17 ( V_49 , V_3 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_38 = F_18 ( V_11 ) ;
if ( V_38 < 0 )
return V_38 ;
for ( V_3 = 0 ; V_3 < V_11 -> V_53 -> V_54 ; ++ V_3 ) {
const struct V_55 * V_53 =
& V_11 -> V_53 -> V_56 [ V_3 ] ;
const struct V_57 * V_58 =
& V_11 -> V_47 -> V_59 [ V_53 -> V_60 ] ;
if ( V_53 -> type == V_61 )
continue;
if ( V_53 -> V_60 >= V_62 ||
V_58 -> V_63 == 0 ) {
F_19 ( V_11 -> V_8 ,
L_4 ,
V_3 , V_53 -> V_60 ) ;
continue;
}
V_38 = F_20 ( V_11 , V_53 -> type , V_53 -> V_60 ,
V_53 ) ;
if ( V_38 < 0 )
return V_38 ;
}
F_21 (encoder, &dev->mode_config.encoder_list, head) {
struct V_64 * V_65 = F_22 ( V_35 ) ;
const struct V_57 * V_58 =
& V_11 -> V_47 -> V_59 [ V_65 -> V_60 ] ;
V_35 -> V_63 = V_58 -> V_63 ;
V_35 -> V_66 = ( 1 << V_11 -> V_53 -> V_54 ) - 1 ;
}
for ( V_3 = 0 ; V_3 < V_37 ; ++ V_3 ) {
V_38 = F_23 ( & V_11 -> V_50 [ V_3 ] ) ;
if ( V_38 < 0 )
return V_38 ;
}
F_24 ( V_8 ) ;
F_25 ( V_8 ) ;
V_29 = F_26 ( V_8 , 32 , V_8 -> V_39 . V_67 ,
V_8 -> V_39 . V_68 ) ;
if ( F_27 ( V_29 ) )
return F_28 ( V_29 ) ;
#ifndef F_29
F_30 ( V_29 ) ;
#endif
V_11 -> V_29 = V_29 ;
return 0 ;
}

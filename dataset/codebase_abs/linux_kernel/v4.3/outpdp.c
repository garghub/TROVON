int
F_1 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
bool V_7 = true ;
T_2 V_8 [ 2 ] , V_9 [ 3 ] ;
T_1 V_10 ;
int V_11 , V_12 ;
V_11 = F_2 ( V_6 -> V_13 , V_14 , V_8 , 2 ) ;
if ( V_11 ) {
F_3 ( & V_6 -> V_2 ,
L_1 ) ;
goto V_15;
}
V_10 = V_8 [ 0 ] * 27000 * ( V_8 [ 1 ] & V_16 ) ;
V_10 = ( V_10 * 8 ) / 10 ;
V_3 = ( V_3 + 9 ) / 10 ;
if ( V_10 < V_3 ) {
F_3 ( & V_6 -> V_2 , L_2 ) ;
goto V_15;
}
V_11 = F_2 ( V_6 -> V_13 , V_17 , V_9 , 3 ) ;
if ( V_11 ) {
F_3 ( & V_6 -> V_2 ,
L_3 ) ;
goto V_15;
}
if ( V_9 [ 2 ] & V_18 ) {
for ( V_12 = 0 ; V_12 < ( V_8 [ 1 ] & V_16 ) ; V_12 ++ ) {
T_2 V_19 = ( V_9 [ V_12 >> 1 ] >> ( ( V_12 & 1 ) * 4 ) ) & 0x0f ;
if ( ! ( V_19 & V_20 ) ||
! ( V_19 & V_21 ) ||
! ( V_19 & V_22 ) ) {
F_3 ( & V_6 -> V_2 ,
L_4 , V_19 ) ;
goto V_15;
}
}
V_7 = false ;
} else {
F_3 ( & V_6 -> V_2 , L_5 ) ;
}
V_15:
if ( V_7 || ! F_4 ( & V_6 -> V_23 . V_15 ) ) {
if ( V_6 -> V_24 [ V_25 ] == 0x00 ) {
V_6 -> V_24 [ V_26 ] =
V_6 -> V_2 . V_27 . V_28 . V_29 ;
V_6 -> V_24 [ V_30 ] =
V_6 -> V_2 . V_27 . V_28 . V_31 ;
}
F_5 ( & V_6 -> V_23 . V_15 , 0 ) ;
F_6 ( & V_6 -> V_23 . V_32 ) ;
} else {
F_7 ( & V_6 -> V_33 ) ;
}
if ( V_4 ) {
if ( ! F_8 ( V_6 -> V_23 . V_4 ,
F_4 ( & V_6 -> V_23 . V_15 ) ,
F_9 ( 2000 ) ) )
V_11 = - V_34 ;
}
return V_11 ;
}
static void
F_10 ( struct V_5 * V_6 , bool V_35 )
{
struct V_36 * V_13 = V_6 -> V_13 ;
if ( V_35 ) {
if ( ! V_6 -> V_37 ) {
F_3 ( & V_6 -> V_2 , L_6 ) ;
F_11 ( V_13 , true ) ;
V_6 -> V_37 = true ;
}
if ( ! F_2 ( V_13 , V_25 , V_6 -> V_24 ,
sizeof( V_6 -> V_24 ) ) ) {
F_1 ( & V_6 -> V_2 , 0 , true ) ;
return;
}
}
if ( V_6 -> V_37 ) {
F_3 ( & V_6 -> V_2 , L_7 ) ;
F_11 ( V_13 , false ) ;
V_6 -> V_37 = false ;
}
F_5 ( & V_6 -> V_23 . V_15 , 0 ) ;
}
static int
F_12 ( struct V_38 * V_39 )
{
const struct V_40 * line = V_39 -> V_41 ;
struct V_5 * V_6 = F_13 ( V_39 , F_14 ( * V_6 ) , V_42 ) ;
struct V_43 * V_44 = V_6 -> V_2 . V_44 ;
struct V_45 * V_46 = V_6 -> V_2 . V_46 ;
struct V_47 V_48 = {} ;
F_3 ( & V_6 -> V_2 , L_8 , line -> V_49 ) ;
F_10 ( V_6 , true ) ;
if ( line -> V_49 & V_50 )
V_48 . V_49 |= V_51 ;
if ( line -> V_49 & V_52 )
V_48 . V_49 |= V_53 ;
F_15 ( & V_46 -> V_42 , V_48 . V_49 , V_44 -> V_54 , & V_48 , sizeof( V_48 ) ) ;
return V_55 ;
}
static int
F_16 ( struct V_38 * V_39 )
{
const struct V_40 * line = V_39 -> V_41 ;
struct V_5 * V_6 = F_13 ( V_39 , F_14 ( * V_6 ) , V_33 ) ;
struct V_43 * V_44 = V_6 -> V_2 . V_44 ;
struct V_45 * V_46 = V_6 -> V_2 . V_46 ;
struct V_47 V_48 = {
. V_49 = V_56 ,
} ;
F_3 ( & V_6 -> V_2 , L_9 , line -> V_49 ) ;
F_1 ( & V_6 -> V_2 , 0 , true ) ;
F_15 ( & V_46 -> V_42 , V_48 . V_49 , V_44 -> V_54 , & V_48 , sizeof( V_48 ) ) ;
return V_57 ;
}
static void
F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
F_18 ( & V_6 -> V_42 ) ;
F_18 ( & V_6 -> V_33 ) ;
F_19 ( & V_6 -> V_23 . V_32 ) ;
F_10 ( V_6 , false ) ;
}
static void
F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
F_18 ( & V_6 -> V_2 . V_44 -> V_42 ) ;
F_10 ( V_6 , true ) ;
F_7 ( & V_6 -> V_42 ) ;
}
static void *
F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
F_22 ( & V_6 -> V_42 ) ;
F_22 ( & V_6 -> V_33 ) ;
return V_6 ;
}
int
F_23 ( const struct V_58 * V_59 ,
struct V_45 * V_46 , int V_54 , struct V_60 * V_61 ,
struct V_36 * V_13 , struct V_5 * V_6 )
{
struct V_62 * V_63 = V_46 -> V_64 . V_65 . V_63 ;
struct V_66 * V_67 = V_63 -> V_67 ;
struct V_68 * V_69 = V_63 -> V_69 ;
T_2 V_70 , V_71 , V_72 ;
T_1 V_41 ;
int V_11 ;
F_24 ( & V_58 , V_46 , V_54 , V_61 , & V_6 -> V_2 ) ;
V_6 -> V_59 = V_59 ;
V_6 -> V_13 = V_13 ;
if ( ! V_6 -> V_13 ) {
F_25 ( & V_6 -> V_2 , L_10 ) ;
return - V_73 ;
}
V_41 = F_26 ( V_67 , V_6 -> V_2 . V_27 . V_74 ,
V_6 -> V_2 . V_27 . V_75 , & V_6 -> V_76 ,
& V_70 , & V_71 , & V_72 , & V_6 -> V_27 ) ;
if ( ! V_41 ) {
F_25 ( & V_6 -> V_2 , L_11 ) ;
return - V_73 ;
}
F_3 ( & V_6 -> V_2 , L_12 ,
V_6 -> V_76 , V_70 , V_71 , V_72 ) ;
F_27 ( & V_6 -> V_23 . V_32 , V_77 ) ;
F_28 ( & V_6 -> V_23 . V_4 ) ;
F_5 ( & V_6 -> V_23 . V_15 , 0 ) ;
V_11 = F_29 (NULL, &i2c->event, nvkm_output_dp_irq, true,
&(struct nvkm_i2c_ntfy_req) {
.mask = NVKM_I2C_IRQ,
.port = outp->aux->id,
},
sizeof(struct nvkm_i2c_ntfy_req),
sizeof(struct nvkm_i2c_ntfy_rep),
&outp->irq) ;
if ( V_11 ) {
F_25 ( & V_6 -> V_2 , L_13 , V_11 ) ;
return V_11 ;
}
V_11 = F_29 (NULL, &i2c->event, nvkm_output_dp_hpd, true,
&(struct nvkm_i2c_ntfy_req) {
.mask = NVKM_I2C_PLUG | NVKM_I2C_UNPLUG,
.port = outp->aux->id,
},
sizeof(struct nvkm_i2c_ntfy_req),
sizeof(struct nvkm_i2c_ntfy_rep),
&outp->hpd) ;
if ( V_11 ) {
F_25 ( & V_6 -> V_2 , L_14 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
int
F_30 ( const struct V_58 * V_59 ,
struct V_45 * V_46 , int V_54 , struct V_60 * V_61 ,
struct V_1 * * V_78 )
{
struct V_68 * V_69 = V_46 -> V_64 . V_65 . V_63 -> V_69 ;
struct V_36 * V_13 = F_31 ( V_69 , V_61 -> V_79 ) ;
struct V_5 * V_6 ;
if ( ! ( V_6 = F_32 ( sizeof( * V_6 ) , V_80 ) ) )
return - V_81 ;
* V_78 = & V_6 -> V_2 ;
return F_23 ( V_59 , V_46 , V_54 , V_61 , V_13 , V_6 ) ;
}

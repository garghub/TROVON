int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
bool V_6 = true ;
T_2 V_7 [ 2 ] , V_8 [ 3 ] ;
T_1 V_9 ;
int V_10 , V_11 ;
F_2 ( & V_5 -> V_12 ) ;
V_10 = F_3 ( V_5 -> V_13 , V_14 , V_7 , 2 ) ;
if ( V_10 ) {
F_4 ( & V_5 -> V_2 ,
L_1 ) ;
goto V_15;
}
V_9 = V_7 [ 0 ] * 27000 * ( V_7 [ 1 ] & V_16 ) ;
V_9 = ( V_9 * 8 ) / 10 ;
V_3 = ( V_3 + 9 ) / 10 ;
if ( V_9 < V_3 ) {
F_4 ( & V_5 -> V_2 , L_2 ) ;
goto V_15;
}
V_10 = F_3 ( V_5 -> V_13 , V_17 , V_8 , 3 ) ;
if ( V_10 ) {
F_4 ( & V_5 -> V_2 ,
L_3 ) ;
goto V_15;
}
if ( V_8 [ 2 ] & V_18 ) {
for ( V_11 = 0 ; V_11 < ( V_7 [ 1 ] & V_16 ) ; V_11 ++ ) {
T_2 V_19 = ( V_8 [ V_11 >> 1 ] >> ( ( V_11 & 1 ) * 4 ) ) & 0x0f ;
if ( ! ( V_19 & V_20 ) ||
! ( V_19 & V_21 ) ||
! ( V_19 & V_22 ) ) {
F_4 ( & V_5 -> V_2 ,
L_4 , V_19 ) ;
goto V_15;
}
}
V_6 = false ;
} else {
F_4 ( & V_5 -> V_2 , L_5 ) ;
}
V_15:
if ( V_6 || ! F_5 ( & V_5 -> V_23 . V_15 ) ) {
if ( V_5 -> V_24 [ V_25 ] == 0x00 ) {
V_5 -> V_24 [ V_26 ] =
V_5 -> V_2 . V_27 . V_28 . V_29 ;
V_5 -> V_24 [ V_30 ] =
V_5 -> V_2 . V_27 . V_28 . V_31 ;
}
F_6 ( V_5 ) ;
}
F_7 ( & V_5 -> V_12 ) ;
return V_10 ;
}
static void
F_8 ( struct V_4 * V_5 , bool V_32 )
{
struct V_33 * V_13 = V_5 -> V_13 ;
if ( V_32 ) {
if ( ! V_5 -> V_34 ) {
F_4 ( & V_5 -> V_2 , L_6 ) ;
F_9 ( V_13 , true ) ;
V_5 -> V_34 = true ;
}
if ( ! F_3 ( V_13 , V_25 , V_5 -> V_24 ,
sizeof( V_5 -> V_24 ) ) ) {
F_1 ( & V_5 -> V_2 , 0 ) ;
return;
}
}
if ( V_5 -> V_34 ) {
F_4 ( & V_5 -> V_2 , L_7 ) ;
F_9 ( V_13 , false ) ;
V_5 -> V_34 = false ;
}
F_10 ( & V_5 -> V_23 . V_15 , 0 ) ;
}
static int
F_11 ( struct V_35 * V_36 )
{
const struct V_37 * line = V_36 -> V_38 ;
struct V_4 * V_5 = F_12 ( V_36 , F_13 ( * V_5 ) , V_39 ) ;
struct V_40 * V_41 = V_5 -> V_2 . V_41 ;
struct V_42 * V_43 = V_5 -> V_2 . V_43 ;
struct V_44 V_45 = {} ;
F_4 ( & V_5 -> V_2 , L_8 , line -> V_46 ) ;
F_8 ( V_5 , true ) ;
if ( line -> V_46 & V_47 )
V_45 . V_46 |= V_48 ;
if ( line -> V_46 & V_49 )
V_45 . V_46 |= V_50 ;
F_14 ( & V_43 -> V_39 , V_45 . V_46 , V_41 -> V_51 , & V_45 , sizeof( V_45 ) ) ;
return V_52 ;
}
static int
F_15 ( struct V_35 * V_36 )
{
const struct V_37 * line = V_36 -> V_38 ;
struct V_4 * V_5 = F_12 ( V_36 , F_13 ( * V_5 ) , V_53 ) ;
struct V_40 * V_41 = V_5 -> V_2 . V_41 ;
struct V_42 * V_43 = V_5 -> V_2 . V_43 ;
struct V_44 V_45 = {
. V_46 = V_54 ,
} ;
F_4 ( & V_5 -> V_2 , L_9 , line -> V_46 ) ;
F_1 ( & V_5 -> V_2 , 0 ) ;
F_14 ( & V_43 -> V_39 , V_45 . V_46 , V_41 -> V_51 , & V_45 , sizeof( V_45 ) ) ;
return V_52 ;
}
static void
F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
F_17 ( & V_5 -> V_39 ) ;
F_17 ( & V_5 -> V_53 ) ;
F_8 ( V_5 , false ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
F_17 ( & V_5 -> V_2 . V_41 -> V_39 ) ;
F_8 ( V_5 , true ) ;
F_19 ( & V_5 -> V_53 ) ;
F_19 ( & V_5 -> V_39 ) ;
}
static void *
F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
F_21 ( & V_5 -> V_39 ) ;
F_21 ( & V_5 -> V_53 ) ;
return V_5 ;
}
int
F_22 ( const struct V_55 * V_56 ,
struct V_42 * V_43 , int V_51 , struct V_57 * V_58 ,
struct V_33 * V_13 , struct V_4 * V_5 )
{
struct V_59 * V_60 = V_43 -> V_61 . V_62 . V_60 ;
struct V_63 * V_64 = V_60 -> V_64 ;
struct V_65 * V_66 = V_60 -> V_66 ;
T_2 V_67 , V_68 , V_69 ;
T_1 V_38 ;
int V_10 ;
F_23 ( & V_55 , V_43 , V_51 , V_58 , & V_5 -> V_2 ) ;
V_5 -> V_56 = V_56 ;
V_5 -> V_13 = V_13 ;
if ( ! V_5 -> V_13 ) {
F_24 ( & V_5 -> V_2 , L_10 ) ;
return - V_70 ;
}
V_38 = F_25 ( V_64 , V_5 -> V_2 . V_27 . V_71 ,
V_5 -> V_2 . V_27 . V_72 , & V_5 -> V_73 ,
& V_67 , & V_68 , & V_69 , & V_5 -> V_27 ) ;
if ( ! V_38 ) {
F_24 ( & V_5 -> V_2 , L_11 ) ;
return - V_70 ;
}
F_4 ( & V_5 -> V_2 , L_12 ,
V_5 -> V_73 , V_67 , V_68 , V_69 ) ;
V_10 = F_26 (NULL, &i2c->event, nvkm_output_dp_irq, true,
&(struct nvkm_i2c_ntfy_req) {
.mask = NVKM_I2C_IRQ,
.port = outp->aux->id,
},
sizeof(struct nvkm_i2c_ntfy_req),
sizeof(struct nvkm_i2c_ntfy_rep),
&outp->irq) ;
if ( V_10 ) {
F_24 ( & V_5 -> V_2 , L_13 , V_10 ) ;
return V_10 ;
}
F_27 ( & V_5 -> V_12 ) ;
F_10 ( & V_5 -> V_23 . V_15 , 0 ) ;
V_10 = F_26 (NULL, &i2c->event, nvkm_output_dp_hpd, true,
&(struct nvkm_i2c_ntfy_req) {
.mask = NVKM_I2C_PLUG | NVKM_I2C_UNPLUG,
.port = outp->aux->id,
},
sizeof(struct nvkm_i2c_ntfy_req),
sizeof(struct nvkm_i2c_ntfy_rep),
&outp->hpd) ;
if ( V_10 ) {
F_24 ( & V_5 -> V_2 , L_14 , V_10 ) ;
return V_10 ;
}
return 0 ;
}
int
F_28 ( const struct V_55 * V_56 ,
struct V_42 * V_43 , int V_51 , struct V_57 * V_58 ,
struct V_1 * * V_74 )
{
struct V_65 * V_66 = V_43 -> V_61 . V_62 . V_60 -> V_66 ;
struct V_33 * V_13 = F_29 ( V_66 , V_58 -> V_75 ) ;
struct V_4 * V_5 ;
if ( ! ( V_5 = F_30 ( sizeof( * V_5 ) , V_76 ) ) )
return - V_77 ;
* V_74 = & V_5 -> V_2 ;
return F_22 ( V_56 , V_43 , V_51 , V_58 , V_13 , V_5 ) ;
}

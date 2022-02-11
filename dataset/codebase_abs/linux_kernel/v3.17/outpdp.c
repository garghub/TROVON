int
F_1 ( struct V_1 * V_2 , T_1 V_3 , bool V_4 )
{
struct V_5 * V_6 = ( void * ) V_2 ;
bool V_7 = true ;
T_2 V_8 [ 2 ] , V_9 [ 3 ] ;
T_1 V_10 ;
int V_11 , V_12 ;
V_11 = F_2 ( V_6 -> V_2 . V_13 , V_14 , V_8 , 2 ) ;
if ( V_11 ) {
F_3 ( L_1 ) ;
goto V_15;
}
V_10 = V_8 [ 0 ] * 27000 * ( V_8 [ 1 ] & V_16 ) ;
V_10 = ( V_10 * 8 ) / 10 ;
V_3 = ( V_3 + 9 ) / 10 ;
if ( V_10 < V_3 ) {
F_3 ( L_2 ) ;
goto V_15;
}
V_11 = F_2 ( V_6 -> V_2 . V_13 , V_17 , V_9 , 3 ) ;
if ( V_11 ) {
F_3 ( L_3 ) ;
goto V_15;
}
if ( V_9 [ 2 ] & V_18 ) {
for ( V_12 = 0 ; V_12 < ( V_8 [ 1 ] & V_16 ) ; V_12 ++ ) {
T_2 V_19 = ( V_9 [ V_12 >> 1 ] >> ( ( V_12 & 1 ) * 4 ) ) & 0x0f ;
if ( ! ( V_19 & V_20 ) ||
! ( V_19 & V_21 ) ||
! ( V_19 & V_22 ) ) {
F_3 ( L_4 , V_19 ) ;
goto V_15;
}
}
V_7 = false ;
} else {
F_3 ( L_5 ) ;
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
struct V_36 * V_37 = V_6 -> V_2 . V_13 ;
if ( V_35 ) {
if ( ! V_6 -> V_35 ) {
F_11 ( V_37 ) -> F_12 ( V_37 , 0 ) ;
F_3 ( L_6 ) ;
V_6 -> V_35 = true ;
}
F_1 ( & V_6 -> V_2 , 0 , true ) ;
} else {
if ( V_6 -> V_35 ) {
F_11 ( V_37 ) -> F_13 ( V_37 ) ;
F_3 ( L_7 ) ;
V_6 -> V_35 = false ;
}
F_5 ( & V_6 -> V_23 . V_15 , 0 ) ;
}
}
static void
F_14 ( struct V_5 * V_6 )
{
struct V_36 * V_37 = V_6 -> V_2 . V_13 ;
int V_11 = F_11 ( V_37 ) -> F_12 ( V_37 , 0 ) ;
if ( V_11 == 0 ) {
V_11 = F_2 ( V_6 -> V_2 . V_13 , V_25 ,
V_6 -> V_24 , sizeof( V_6 -> V_24 ) ) ;
F_10 ( V_6 , V_11 == 0 ) ;
F_11 ( V_37 ) -> F_13 ( V_37 ) ;
}
}
static int
F_15 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_16 ( V_39 , F_17 ( * V_41 ) , V_42 ) ;
struct V_5 * V_6 ;
struct V_43 * V_44 = V_43 ( V_41 ) ;
const struct V_45 * line = V_39 -> V_46 ;
struct V_47 V_48 = {} ;
F_18 (outp, &disp->outp, base.head) {
if ( V_6 -> V_2 . V_41 == V_41 &&
V_6 -> V_27 . type == V_49 ) {
F_3 ( L_8 , line -> V_50 ) ;
F_14 ( V_6 ) ;
if ( line -> V_50 & V_51 )
V_48 . V_50 |= V_52 ;
if ( line -> V_50 & V_53 )
V_48 . V_50 |= V_54 ;
F_19 ( & V_44 -> V_42 , V_48 . V_50 , V_41 -> V_55 ,
& V_48 , sizeof( V_48 ) ) ;
return V_56 ;
}
}
F_20 ( 1 ) ;
return V_57 ;
}
static int
F_21 ( struct V_38 * V_39 )
{
struct V_5 * V_6 = F_16 ( V_39 , F_17 ( * V_6 ) , V_33 ) ;
struct V_43 * V_44 = V_43 ( V_6 ) ;
const struct V_45 * line = V_39 -> V_46 ;
struct V_47 V_48 = {
. V_50 = V_58 ,
} ;
int V_55 = V_6 -> V_2 . V_27 . V_59 ;
F_3 ( L_9 , line -> V_50 ) ;
F_1 ( & V_6 -> V_2 , 0 , true ) ;
F_19 ( & V_44 -> V_42 , V_48 . V_50 , V_55 , & V_48 , sizeof( V_48 ) ) ;
return V_57 ;
}
int
F_22 ( struct V_60 * V_61 , bool V_62 )
{
struct V_5 * V_6 = ( void * ) V_61 ;
F_23 ( & V_6 -> V_33 ) ;
F_10 ( V_6 , false ) ;
return F_24 ( & V_6 -> V_2 , V_62 ) ;
}
int
F_25 ( struct V_60 * V_61 )
{
struct V_5 * V_6 = ( void * ) V_61 ;
F_14 ( V_6 ) ;
return F_26 ( & V_6 -> V_2 ) ;
}
void
F_27 ( struct V_60 * V_61 )
{
struct V_5 * V_6 = ( void * ) V_61 ;
F_28 ( & V_6 -> V_33 ) ;
F_29 ( & V_6 -> V_2 ) ;
}
int
F_30 ( struct V_60 * V_63 ,
struct V_60 * V_64 ,
struct V_65 * V_66 ,
struct V_67 * V_27 , int V_55 ,
int V_68 , void * * V_69 )
{
struct V_70 * V_71 = V_70 ( V_63 ) ;
struct F_11 * V_72 = F_11 ( V_63 ) ;
struct V_5 * V_6 ;
T_2 V_73 , V_74 , V_75 ;
T_1 V_46 ;
int V_11 ;
V_11 = F_31 ( V_63 , V_64 , V_66 , V_27 , V_55 ,
V_68 , V_69 ) ;
V_6 = * V_69 ;
if ( V_11 )
return V_11 ;
F_28 ( & V_6 -> V_2 . V_41 -> V_42 ) ;
if ( ! V_6 -> V_2 . V_13 ) {
F_32 ( L_10 ) ;
return - V_76 ;
}
V_46 = F_33 ( V_71 , V_6 -> V_2 . V_27 . V_77 ,
V_6 -> V_2 . V_27 . V_78 , & V_6 -> V_79 ,
& V_73 , & V_74 , & V_75 , & V_6 -> V_27 ) ;
if ( ! V_46 ) {
F_32 ( L_11 ) ;
return - V_76 ;
}
F_3 ( L_12 , V_6 -> V_79 , V_73 , V_74 , V_75 ) ;
F_34 ( & V_6 -> V_23 . V_32 , V_80 ) ;
F_35 ( & V_6 -> V_23 . V_4 ) ;
F_5 ( & V_6 -> V_23 . V_15 , 0 ) ;
V_11 = F_36 (&i2c->event, nvkm_output_dp_irq, true,
&(struct nvkm_i2c_ntfy_req) {
.mask = NVKM_I2C_IRQ,
.port = outp->base.edid->index,
},
sizeof(struct nvkm_i2c_ntfy_req),
sizeof(struct nvkm_i2c_ntfy_rep),
&outp->irq) ;
if ( V_11 ) {
F_32 ( L_13 , V_11 ) ;
return V_11 ;
}
V_11 = F_36 (&i2c->event, nvkm_output_dp_hpd, true,
&(struct nvkm_i2c_ntfy_req) {
.mask = NVKM_I2C_PLUG | NVKM_I2C_UNPLUG,
.port = outp->base.edid->index,
},
sizeof(struct nvkm_i2c_ntfy_req),
sizeof(struct nvkm_i2c_ntfy_rep),
&outp->base.conn->hpd) ;
if ( V_11 ) {
F_32 ( L_14 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
int
F_37 ( struct V_60 * V_63 ,
struct V_60 * V_64 ,
struct V_65 * V_66 , void * V_27 , T_1 V_55 ,
struct V_60 * * V_69 )
{
struct V_5 * V_6 ;
int V_11 ;
V_11 = F_38 ( V_63 , V_64 , V_66 , V_27 , V_55 , & V_6 ) ;
* V_69 = F_39 ( V_6 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}

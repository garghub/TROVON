static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
T_1 type ;
int V_10 ;
T_2 V_11 ;
T_3 V_12 = 6 ;
#ifdef F_2
if ( V_3 -> V_13 )
V_12 = 8 ;
#endif
F_3 (i2o_dev, &c->devices, list)
if ( V_6 -> V_14 . V_15 == V_16 ) {
if ( ! F_4 ( V_6 , 0x0000 , 0 , & type , 1 )
&& ( type == 0x01 ) )
V_9 ++ ;
}
if ( ! V_9 ) {
F_5 ( L_1 , V_3 -> V_17 ) ;
return F_6 ( - V_18 ) ;
}
V_11 = V_9 * sizeof( struct V_5 * )
+ sizeof( struct V_1 ) ;
V_8 = F_7 ( & V_19 , V_11 ) ;
if ( ! V_8 ) {
F_5 ( L_2 ) ;
return F_6 ( - V_20 ) ;
}
V_8 -> V_9 = V_9 - 1 ;
V_8 -> V_21 = V_22 ;
V_8 -> V_23 = V_24 ;
V_8 -> V_25 = V_3 -> V_26 ;
V_8 -> V_27 = F_8 ( V_3 , V_12 ) ;
V_4 = (struct V_1 * ) V_8 -> V_28 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_29 = V_3 ;
V_4 -> V_30 = 1 ;
V_10 = 0 ;
F_3 (i2o_dev, &c->devices, list)
if ( V_6 -> V_14 . V_15 == V_16 ) {
if ( ! F_4 ( V_6 , 0x0000 , 0 , & type , 1 )
&& ( type == 0x01 ) )
V_4 -> V_31 [ V_10 ++ ] = V_6 ;
if ( V_10 >= V_9 )
break;
}
return V_4 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 )
{
return V_3 -> V_32 [ V_33 . V_34 ] ;
}
static int F_10 ( struct V_35 * V_36 )
{
struct V_5 * V_6 = F_11 ( V_36 ) ;
struct V_2 * V_3 = V_6 -> V_29 ;
struct V_1 * V_4 ;
struct V_37 * V_38 ;
F_12 ( L_3 , V_6 -> V_14 . V_39 ) ;
V_4 = F_9 ( V_3 ) ;
F_13 (scsi_dev, i2o_shost->scsi_host)
if ( V_38 -> V_28 == V_6 ) {
F_14 ( & V_6 -> V_35 . V_40 , L_4 ) ;
F_15 ( V_38 ) ;
F_16 ( V_38 ) ;
break;
}
return 0 ;
}
static int F_17 ( struct V_35 * V_36 )
{
struct V_5 * V_6 = F_11 ( V_36 ) ;
struct V_2 * V_3 = V_6 -> V_29 ;
struct V_1 * V_4 ;
struct V_7 * V_8 ;
struct V_5 * V_41 ;
struct V_37 * V_38 ;
T_4 V_42 = - 1 ;
T_5 V_30 = - 1 ;
int V_31 = - 1 ;
int V_10 , V_43 ;
V_4 = F_9 ( V_3 ) ;
if ( ! V_4 )
return - V_18 ;
V_8 = V_4 -> V_8 ;
switch ( V_6 -> V_14 . V_15 ) {
case V_44 :
case V_45 :
#ifdef F_2
if ( V_3 -> V_13 ) {
T_1 type ;
struct V_5 * V_46 = V_4 -> V_31 [ 0 ] ;
if ( ! F_4 ( V_46 , 0x0000 , 0 , & type , 1 )
&& ( type == 0x01 ) )
if ( ! F_4 ( V_46 , 0x0200 , 4 , & V_42 , 4 ) ) {
V_31 = 0 ;
if ( V_6 -> V_14 . V_15 ==
V_44 )
V_30 =
F_18 ( V_4 ->
V_30 ++ ) ;
else
V_30 = 0 ;
}
}
#endif
break;
case V_47 :
if ( F_4 ( V_6 , 0x0000 , 3 , & V_42 , 4 ) )
return - V_18 ;
if ( F_4 ( V_6 , 0x0000 , 4 , & V_30 , 8 ) )
return - V_18 ;
V_41 = F_19 ( V_3 , V_6 -> V_14 . V_48 ) ;
if ( ! V_41 ) {
F_5 ( L_5 ,
V_6 -> V_14 . V_39 ) ;
return - V_18 ;
}
for ( V_10 = 0 ; V_10 <= V_4 -> V_8 -> V_9 ; V_10 ++ )
if ( V_4 -> V_31 [ V_10 ] == V_41 )
V_31 = V_10 ;
break;
default:
return - V_18 ;
}
if ( V_31 == - 1 ) {
F_5 ( L_6 ,
V_6 -> V_14 . V_39 ) ;
return - V_18 ;
}
if ( F_20 ( V_42 ) >= V_8 -> V_21 ) {
F_5 ( L_7 ,
F_20 ( V_42 ) , V_8 -> V_21 ) ;
return - V_18 ;
}
if ( F_21 ( V_30 ) >= V_8 -> V_23 ) {
F_5 ( L_8 ,
( long unsigned int ) F_21 ( V_30 ) ,
V_8 -> V_23 ) ;
return - V_18 ;
}
V_38 =
F_22 ( V_4 -> V_8 , V_31 , F_20 ( V_42 ) ,
F_21 ( V_30 ) , V_6 ) ;
if ( F_23 ( V_38 ) ) {
F_5 ( L_9 ,
V_6 -> V_14 . V_39 ) ;
return F_24 ( V_38 ) ;
}
V_43 = F_25 ( & V_6 -> V_35 . V_40 ,
& V_38 -> V_49 . V_40 , L_4 ) ;
if ( V_43 )
goto V_50;
F_12 ( L_10 ,
V_6 -> V_14 . V_39 , V_31 , F_20 ( V_42 ) ,
( long unsigned int ) F_21 ( V_30 ) ) ;
return 0 ;
V_50:
F_15 ( V_38 ) ;
return V_43 ;
}
static const char * F_26 ( struct V_7 * V_51 )
{
struct V_1 * V_28 ;
V_28 = (struct V_1 * ) V_51 -> V_28 ;
return V_28 -> V_29 -> V_17 ;
}
static int F_27 ( struct V_2 * V_3 , T_4 V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 ;
T_4 error ;
struct V_35 * V_36 ;
V_56 = F_28 ( V_3 , F_20 ( V_54 -> V_57 . V_58 . V_59 ) ) ;
if ( F_29 ( ! V_56 ) ) {
F_30 ( L_11 ) ;
return - 1 ;
}
error = F_20 ( V_54 -> V_60 [ 0 ] ) ;
F_31 ( L_12 , V_56 ) ;
V_56 -> V_61 = error & 0xff ;
if ( V_56 -> V_61 )
memcpy ( V_56 -> V_62 , & V_54 -> V_60 [ 3 ] ,
F_32 ( V_63 , 40 ) ) ;
if ( ( error >> 8 ) & 0xff )
F_30 ( L_13 , error ) ;
V_36 = & V_3 -> V_64 -> V_36 ;
F_33 ( V_56 ) ;
V_56 -> V_65 ( V_56 ) ;
return 1 ;
}
static void F_34 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_14 . V_15 ) {
case V_45 :
case V_44 :
F_17 ( & V_6 -> V_35 ) ;
break;
default:
break;
}
}
static void F_35 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_14 . V_15 ) {
case V_45 :
case V_44 :
F_10 ( & V_6 -> V_35 ) ;
break;
default:
break;
}
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_43 ;
V_4 = F_1 ( V_3 ) ;
if ( F_23 ( V_4 ) ) {
F_30 ( L_14 ) ;
return;
}
V_43 = F_37 ( V_4 -> V_8 , & V_3 -> V_35 ) ;
if ( V_43 ) {
F_30 ( L_15 ) ;
F_38 ( V_4 -> V_8 ) ;
return;
}
V_3 -> V_32 [ V_33 . V_34 ] = V_4 ;
F_31 ( L_16 ) ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = F_9 ( V_3 ) ;
if ( ! V_4 )
return;
V_3 -> V_32 [ V_33 . V_34 ] = NULL ;
F_40 ( V_4 -> V_8 ) ;
F_38 ( V_4 -> V_8 ) ;
F_31 ( L_17 ) ;
}
static int F_41 ( struct V_55 * V_66 ,
void (* F_42) ( struct V_55 * ) )
{
struct V_2 * V_3 ;
struct V_5 * V_6 ;
int V_39 ;
struct V_53 * V_54 ;
T_4 V_67 = 0x20a00000 ;
T_4 V_68 ;
T_4 * V_69 ;
T_4 V_56 = V_70 << 24 ;
int V_43 = 0 ;
V_6 = V_66 -> V_35 -> V_28 ;
V_66 -> V_65 = F_42 ;
if ( F_29 ( ! V_6 ) ) {
F_5 ( L_18 ) ;
V_66 -> V_61 = V_71 << 16 ;
F_42 ( V_66 ) ;
goto exit;
}
V_3 = V_6 -> V_29 ;
V_39 = V_6 -> V_14 . V_39 ;
F_31 ( L_19 , V_39 ) ;
F_31 ( L_20 ) ;
switch ( V_66 -> V_72 ) {
case V_73 :
V_68 = V_74 ;
break;
case V_75 :
V_67 |= 0x80000000 ;
V_68 = V_76 ;
break;
case V_77 :
V_67 |= 0x40000000 ;
V_68 = V_76 ;
break;
default:
V_66 -> V_61 = V_71 << 16 ;
F_42 ( V_66 ) ;
goto exit;
}
V_54 = F_43 ( V_3 ) ;
if ( F_23 ( V_54 ) ) {
V_43 = V_78 ;
goto exit;
}
V_69 = & V_54 -> V_60 [ 0 ] ;
#if 0
#ifdef F_2
if (c->adaptec) {
u32 adpt_flags = 0;
if (SCpnt->sc_request && SCpnt->sc_request->upper_private_data) {
i2o_sg_io_hdr_t __user *usr_ptr =
((Sg_request *) (SCpnt->sc_request->
upper_private_data))->header.
usr_ptr;
if (usr_ptr)
get_user(adpt_flags, &usr_ptr->flags);
}
switch (i2o_dev->lct_data.class_id) {
case I2O_CLASS_EXECUTIVE:
case I2O_CLASS_RANDOM_BLOCK_STORAGE:
adpt_flags ^= I2O_DPT_SG_FLAG_INTERPRET;
break;
default:
break;
}
if (sgl_offset == SGL_OFFSET_10)
sgl_offset = SGL_OFFSET_12;
cmd = I2O_CMD_PRIVATE << 24;
*mptr++ = cpu_to_le32(I2O_VENDOR_DPT << 16 | I2O_CMD_SCSI_EXEC);
*mptr++ = cpu_to_le32(adpt_flags | tid);
}
#endif
#endif
V_54 -> V_57 . V_79 [ 1 ] = F_44 ( V_56 | V_80 << 12 | V_39 ) ;
V_54 -> V_57 . V_58 . V_81 = F_44 ( V_33 . V_34 ) ;
V_54 -> V_57 . V_58 . V_59 = F_44 ( F_45 ( V_3 , V_66 ) ) ;
* V_69 ++ = F_44 ( V_67 | V_66 -> V_82 ) ;
memcpy ( V_69 , V_66 -> V_83 , 16 ) ;
V_69 += 4 ;
if ( V_68 != V_74 ) {
* V_69 ++ = F_44 ( F_46 ( V_66 ) ) ;
if ( F_47 ( V_66 ) ) {
if ( ! F_48 ( V_3 , F_49 ( V_66 ) ,
F_47 ( V_66 ) ,
V_66 -> V_72 , & V_69 ) )
goto V_84;
}
}
V_54 -> V_57 . V_79 [ 0 ] =
F_44 ( F_50 ( V_69 - & V_54 -> V_57 . V_79 [ 0 ] ) | V_68 ) ;
F_51 ( V_3 , V_54 ) ;
F_31 ( L_21 , V_66 ) ;
return 0 ;
V_84:
V_43 = - V_20 ;
F_52 ( V_3 , V_54 ) ;
exit:
return V_43 ;
}
int F_53 ( struct V_37 * V_85 ,
struct V_86 * V_36 , T_6 V_87 ,
int * V_88 )
{
int V_11 ;
V_11 = V_87 ;
V_88 [ 0 ] = 64 ;
V_88 [ 1 ] = 32 ;
if ( ( V_88 [ 2 ] = V_11 >> 11 ) > 1024 ) {
V_88 [ 0 ] = 255 ;
V_88 [ 1 ] = 63 ;
V_88 [ 2 ] = V_11 / ( 255 * 63 ) ;
}
return 0 ;
}
static int T_7 F_54 ( void )
{
int V_43 ;
F_55 (KERN_INFO OSM_DESCRIPTION L_22 OSM_VERSION L_23 ) ;
V_43 = F_56 ( & V_33 ) ;
if ( V_43 ) {
F_30 ( L_24 ) ;
return V_43 ;
}
return 0 ;
}
static void T_8 F_57 ( void )
{
F_58 ( & V_33 ) ;
}

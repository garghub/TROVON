static int F_1 ( struct V_1 * V_1 , T_1 V_2 ,
T_2 V_3 , T_2 V_4 , T_1 * V_5 , T_2 V_6 )
{
int V_7 ;
V_7 = F_2 ( V_1 -> V_8 ,
F_3 ( V_1 -> V_8 , 0 ) ,
V_2 ,
V_9 | V_10 | V_11 ,
V_3 , V_4 , V_5 , V_6 , 1000 ) ;
if ( V_7 < 0 )
F_4 ( L_1 , V_2 , V_7 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_1 , int V_12 )
{
int V_7 ;
V_7 = F_1 ( V_1 , 0x50 , V_12 , 0 , NULL , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_12 )
V_7 = F_1 ( V_1 , 0x55 , 1 , 0 , NULL , 0 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 * V_5 , int V_13 )
{
int V_7 , V_14 , V_15 = 0 ;
T_1 * V_16 = V_1 -> V_17 ;
T_3 V_18 = F_7 ( V_1 -> V_19 ) ;
T_3 V_20 = F_7 ( V_1 -> V_20 ) ;
memset ( V_16 , 0 , 16 ) ;
V_16 [ 0 ] = V_20 ;
if ( V_1 -> V_21 == 256 )
V_16 [ 1 ] |= 0x01 ;
if ( V_1 -> V_22 <= 122 ) {
V_16 [ 1 ] |= 0x10 ;
V_14 = V_1 -> V_22 * 2 ;
} else
V_14 = V_1 -> V_22 ;
V_16 [ 2 ] = 0x90 ;
if ( V_14 <= 200 )
V_16 [ 3 ] = 0x06 ;
else if ( V_14 <= 242 )
V_16 [ 3 ] = 0x07 ;
else
V_16 [ 3 ] = 0x08 ;
if ( V_18 < 256 ) {
V_16 [ 4 ] = 255 - V_18 ;
V_16 [ 5 ] = 0x00 ;
V_16 [ 6 ] = 0x00 ;
V_16 [ 7 ] = 0x01 ;
} else {
V_16 [ 4 ] = 0x00 ;
V_16 [ 5 ] = 0x00 ;
V_16 [ 6 ] = V_18 & 0xFF ;
V_16 [ 7 ] = V_18 >> 8 ;
}
V_16 [ 8 ] = ( ( 244 - V_14 ) / 2 ) & ~ 0x01 ;
F_8 ( & V_1 -> V_23 ) ;
V_7 = F_1 ( V_1 , 0x51 , 0x80 , 0 , V_16 , 16 ) ;
F_9 ( & V_1 -> V_23 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_10 ( V_1 -> V_8 ,
F_11 ( V_1 -> V_8 , 0x81 ) ,
V_5 , V_13 , & V_15 , 10000 ) ;
if ( V_7 < 0 || V_15 != V_13 ) {
F_4 ( L_2 ,
V_7 , V_15 , V_13 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_12 ( struct V_25 * V_26 )
{
struct V_27 * V_27 = F_13 ( V_26 , struct V_27 , V_25 ) ;
struct V_1 * V_1 = & V_27 -> V_1 ;
int V_7 , V_28 ;
T_1 * V_29 ;
V_28 = V_1 -> V_30 . V_31 [ V_1 -> V_32 ] . V_33 +
V_34 ;
V_29 = F_14 ( V_28 , V_35 | V_36 ) ;
if ( ! V_29 ) {
F_4 ( L_3 ) ;
goto exit;
}
while ( V_1 -> V_8 && V_1 -> V_37 ) {
#ifdef F_15
if ( V_1 -> V_38 )
break;
#endif
V_7 = F_6 ( V_1 , V_29 , V_28 ) ;
if ( V_7 < 0 )
break;
F_16 ( V_1 , V_39 ,
V_29 + V_34 ,
V_28 - V_34 ) ;
F_16 ( V_1 , V_40 , NULL , 0 ) ;
}
exit:
F_17 ( V_29 ) ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_41 * V_42 )
{
struct V_30 * V_30 = & V_1 -> V_30 ;
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
V_30 -> V_43 = 1 ;
V_30 -> V_44 = 64 ;
V_30 -> V_31 = V_45 ;
V_30 -> V_46 = F_19 ( V_45 ) ;
F_20 ( & V_27 -> V_25 , F_12 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_7 ;
const struct V_47 * V_48 ;
const struct V_49 * V_50 ( V_51 ) ;
T_1 * V_52 ;
V_7 = F_22 ( & V_51 , V_53 ,
& V_1 -> V_8 -> V_8 ) ;
if ( V_7 ) {
F_4 ( L_4 , V_7 ) ;
return V_7 ;
}
V_52 = F_14 ( V_54 , V_35 ) ;
if ( ! V_52 ) {
V_7 = - V_55 ;
goto exit;
}
for ( V_48 = ( void * ) V_51 -> V_5 ; V_48 ; V_48 = F_23 ( V_48 ) ) {
memcpy ( V_52 , V_48 -> V_5 , F_24 ( V_48 -> V_6 ) ) ;
V_7 = F_1 ( V_1 , 0xff , 0 , 0 , V_52 ,
F_24 ( V_48 -> V_6 ) ) ;
if ( V_7 < 0 )
break;
}
F_17 ( V_52 ) ;
exit:
F_25 ( V_51 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_27 * V_27 = (struct V_27 * ) V_1 ;
int V_7 ;
V_7 = F_5 ( V_1 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_27 -> V_56 = F_27 ( V_57 ) ;
F_28 ( V_27 -> V_56 , & V_27 -> V_25 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_27 * V_8 = (struct V_27 * ) V_1 ;
F_9 ( & V_1 -> V_23 ) ;
F_30 ( V_8 -> V_56 ) ;
V_8 -> V_56 = NULL ;
F_8 ( & V_1 -> V_23 ) ;
if ( V_1 -> V_8 )
F_5 ( V_1 , 0 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_58 * V_59 = & V_1 -> V_60 ;
V_1 -> V_61 . V_60 = V_59 ;
F_32 ( V_59 , 2 ) ;
V_1 -> V_19 = F_33 ( V_59 , NULL ,
V_62 , 0 , 2047 , 1 , 256 ) ;
V_1 -> V_20 = F_33 ( V_59 , NULL ,
V_63 , 0 , 255 , 1 , 200 ) ;
if ( V_59 -> error ) {
F_4 ( L_5 ) ;
return V_59 -> error ;
}
return 0 ;
}
static int F_34 ( struct V_64 * V_65 ,
const struct V_41 * V_42 )
{
return F_35 ( V_65 , V_42 ,
& V_66 ,
sizeof( struct V_27 ) ,
V_67 ) ;
}

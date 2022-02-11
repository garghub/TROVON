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
if ( V_1 -> V_21 . V_22 == 256 )
V_16 [ 1 ] |= 0x01 ;
if ( V_1 -> V_21 . V_23 <= 122 ) {
V_16 [ 1 ] |= 0x10 ;
V_14 = V_1 -> V_21 . V_23 * 2 ;
} else
V_14 = V_1 -> V_21 . V_23 ;
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
F_8 ( & V_1 -> V_24 ) ;
V_7 = F_1 ( V_1 , 0x51 , 0x80 , 0 , V_16 , 16 ) ;
F_9 ( & V_1 -> V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_10 ( V_1 -> V_8 ,
F_11 ( V_1 -> V_8 , 0x81 ) ,
V_5 , V_13 , & V_15 , 10000 ) ;
if ( V_7 < 0 || V_15 != V_13 ) {
F_4 ( L_2 ,
V_7 , V_15 , V_13 ) ;
return - V_25 ;
}
return 0 ;
}
static void F_12 ( struct V_26 * V_27 )
{
struct V_28 * V_28 = F_13 ( V_27 , struct V_28 , V_26 ) ;
struct V_1 * V_1 = & V_28 -> V_1 ;
int V_7 , V_29 ;
T_1 * V_30 ;
V_29 = V_1 -> V_31 . V_32 [ V_1 -> V_33 ] . V_34 +
V_35 ;
V_30 = F_14 ( V_29 , V_36 | V_37 ) ;
if ( ! V_30 ) {
F_4 ( L_3 ) ;
goto exit;
}
while ( V_1 -> V_38 && V_1 -> V_39 ) {
#ifdef F_15
if ( V_1 -> V_40 )
break;
#endif
V_7 = F_6 ( V_1 , V_30 , V_29 ) ;
if ( V_7 < 0 )
break;
F_16 ( V_1 , V_41 ,
V_30 + V_35 ,
V_29 - V_35 ) ;
F_16 ( V_1 , V_42 , NULL , 0 ) ;
}
exit:
F_17 ( V_30 ) ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_43 * V_44 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
struct V_28 * V_28 = (struct V_28 * ) V_1 ;
V_31 -> V_45 = 1 ;
V_31 -> V_46 = 64 ;
V_31 -> V_32 = V_47 ;
V_31 -> V_48 = F_19 ( V_47 ) ;
F_20 ( & V_28 -> V_26 , F_12 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
int V_7 ;
const struct V_49 * V_50 ;
const struct V_51 * V_52 ( V_53 ) ;
T_1 * V_54 ;
V_7 = F_22 ( & V_53 , V_55 ,
& V_1 -> V_8 -> V_8 ) ;
if ( V_7 ) {
F_4 ( L_4 , V_7 ) ;
return V_7 ;
}
V_54 = F_14 ( V_56 , V_36 ) ;
if ( ! V_54 ) {
V_7 = - V_57 ;
goto exit;
}
for ( V_50 = ( void * ) V_53 -> V_5 ; V_50 ; V_50 = F_23 ( V_50 ) ) {
memcpy ( V_54 , V_50 -> V_5 , F_24 ( V_50 -> V_6 ) ) ;
V_7 = F_1 ( V_1 , 0xff , 0 , 0 , V_54 ,
F_24 ( V_50 -> V_6 ) ) ;
if ( V_7 < 0 )
break;
}
F_17 ( V_54 ) ;
exit:
F_25 ( V_53 ) ;
return V_7 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_28 * V_28 = (struct V_28 * ) V_1 ;
int V_7 ;
V_7 = F_5 ( V_1 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_28 -> V_58 = F_27 ( V_59 ) ;
F_28 ( V_28 -> V_58 , & V_28 -> V_26 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_1 )
{
struct V_28 * V_8 = (struct V_28 * ) V_1 ;
F_9 ( & V_1 -> V_24 ) ;
F_30 ( V_8 -> V_58 ) ;
V_8 -> V_58 = NULL ;
F_8 ( & V_1 -> V_24 ) ;
if ( V_1 -> V_38 )
F_5 ( V_1 , 0 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_60 * V_61 = & V_1 -> V_62 ;
V_1 -> V_63 . V_62 = V_61 ;
F_32 ( V_61 , 2 ) ;
V_1 -> V_19 = F_33 ( V_61 , NULL ,
V_64 , 0 , 2047 , 1 , 256 ) ;
V_1 -> V_20 = F_33 ( V_61 , NULL ,
V_65 , 0 , 255 , 1 , 200 ) ;
if ( V_61 -> error ) {
F_4 ( L_5 ) ;
return V_61 -> error ;
}
return 0 ;
}
static int F_34 ( struct V_66 * V_67 ,
const struct V_43 * V_44 )
{
return F_35 ( V_67 , V_44 ,
& V_68 ,
sizeof( struct V_28 ) ,
V_69 ) ;
}

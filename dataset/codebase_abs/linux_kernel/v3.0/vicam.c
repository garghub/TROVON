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
struct V_14 * V_14 = (struct V_14 * ) V_1 ;
int V_7 , V_15 , V_16 = 0 ;
T_1 * V_17 = V_1 -> V_18 ;
memset ( V_17 , 0 , 16 ) ;
V_17 [ 0 ] = V_14 -> V_19 [ V_20 ] . V_21 ;
if ( V_1 -> V_22 == 256 )
V_17 [ 1 ] |= 0x01 ;
if ( V_1 -> V_23 <= 122 ) {
V_17 [ 1 ] |= 0x10 ;
V_15 = V_1 -> V_23 * 2 ;
} else
V_15 = V_1 -> V_23 ;
V_17 [ 2 ] = 0x90 ;
if ( V_15 <= 200 )
V_17 [ 3 ] = 0x06 ;
else if ( V_15 <= 242 )
V_17 [ 3 ] = 0x07 ;
else
V_17 [ 3 ] = 0x08 ;
if ( V_14 -> V_19 [ V_24 ] . V_21 < 256 ) {
V_17 [ 4 ] = 255 - V_14 -> V_19 [ V_24 ] . V_21 ;
V_17 [ 5 ] = 0x00 ;
V_17 [ 6 ] = 0x00 ;
V_17 [ 7 ] = 0x01 ;
} else {
V_17 [ 4 ] = 0x00 ;
V_17 [ 5 ] = 0x00 ;
V_17 [ 6 ] = V_14 -> V_19 [ V_24 ] . V_21 & 0xFF ;
V_17 [ 7 ] = V_14 -> V_19 [ V_24 ] . V_21 >> 8 ;
}
V_17 [ 8 ] = ( ( 244 - V_15 ) / 2 ) & ~ 0x01 ;
F_7 ( & V_1 -> V_25 ) ;
V_7 = F_1 ( V_1 , 0x51 , 0x80 , 0 , V_17 , 16 ) ;
F_8 ( & V_1 -> V_25 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_9 ( V_1 -> V_8 ,
F_10 ( V_1 -> V_8 , 0x81 ) ,
V_5 , V_13 , & V_16 , 10000 ) ;
if ( V_7 < 0 || V_16 != V_13 ) {
F_4 ( L_2 ,
V_7 , V_16 , V_13 ) ;
return - V_26 ;
}
return 0 ;
}
static void F_11 ( struct V_27 * V_28 )
{
struct V_14 * V_14 = F_12 ( V_28 , struct V_14 , V_27 ) ;
struct V_1 * V_1 = & V_14 -> V_1 ;
int V_7 , V_29 ;
T_1 * V_30 ;
V_29 = V_1 -> V_31 . V_32 [ V_1 -> V_33 ] . V_34 +
V_35 ;
V_30 = F_13 ( V_29 , V_36 | V_37 ) ;
if ( ! V_30 ) {
F_4 ( L_3 ) ;
goto exit;
}
while ( V_1 -> V_38 && V_1 -> V_39 ) {
V_7 = F_6 ( V_1 , V_30 , V_29 ) ;
if ( V_7 < 0 )
break;
F_14 ( V_1 , V_40 ,
V_30 + V_35 ,
V_29 - V_35 ) ;
F_14 ( V_1 , V_41 , NULL , 0 ) ;
}
exit:
F_15 ( V_30 ) ;
}
static int F_16 ( struct V_1 * V_1 ,
const struct V_42 * V_43 )
{
struct V_31 * V_31 = & V_1 -> V_31 ;
struct V_14 * V_14 = (struct V_14 * ) V_1 ;
V_31 -> V_44 = 1 ;
V_31 -> V_45 = 64 ;
V_31 -> V_32 = V_46 ;
V_31 -> V_47 = F_17 ( V_46 ) ;
V_31 -> V_19 = V_14 -> V_19 ;
F_18 ( & V_14 -> V_27 , F_11 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_1 )
{
int V_7 ;
const struct V_48 * V_49 ;
const struct V_50 * V_51 ( V_52 ) ;
T_1 * V_53 ;
V_7 = F_20 ( & V_52 , L_4 ,
& V_1 -> V_8 -> V_8 ) ;
if ( V_7 ) {
F_4 ( L_5 , V_7 ) ;
return V_7 ;
}
V_53 = F_13 ( V_54 , V_36 ) ;
if ( ! V_53 ) {
V_7 = - V_55 ;
goto exit;
}
for ( V_49 = ( void * ) V_52 -> V_5 ; V_49 ; V_49 = F_21 ( V_49 ) ) {
memcpy ( V_53 , V_49 -> V_5 , F_22 ( V_49 -> V_6 ) ) ;
V_7 = F_1 ( V_1 , 0xff , 0 , 0 , V_53 ,
F_22 ( V_49 -> V_6 ) ) ;
if ( V_7 < 0 )
break;
}
F_15 ( V_53 ) ;
exit:
F_23 ( V_52 ) ;
return V_7 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_14 * V_14 = (struct V_14 * ) V_1 ;
int V_7 ;
V_7 = F_5 ( V_1 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_14 -> V_56 = F_25 ( V_57 ) ;
F_26 ( V_14 -> V_56 , & V_14 -> V_27 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_14 * V_8 = (struct V_14 * ) V_1 ;
F_8 ( & V_1 -> V_25 ) ;
F_28 ( V_8 -> V_56 ) ;
V_8 -> V_56 = NULL ;
F_7 ( & V_1 -> V_25 ) ;
F_5 ( V_1 , 0 ) ;
}
static int F_29 ( struct V_58 * V_59 ,
const struct V_42 * V_43 )
{
return F_30 ( V_59 , V_43 ,
& V_60 ,
sizeof( struct V_14 ) ,
V_61 ) ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_62 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_62 ) ;
}

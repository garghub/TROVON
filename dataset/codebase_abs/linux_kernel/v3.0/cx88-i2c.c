static void F_1 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 )
V_4 -> V_5 |= 0x02 ;
else
V_4 -> V_5 &= ~ 0x02 ;
F_2 ( V_6 , V_4 -> V_5 ) ;
F_3 ( V_6 ) ;
}
static void F_4 ( void * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 ;
if ( V_2 )
V_4 -> V_5 |= 0x01 ;
else
V_4 -> V_5 &= ~ 0x01 ;
F_2 ( V_6 , V_4 -> V_5 ) ;
F_3 ( V_6 ) ;
}
static int F_5 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
T_1 V_2 ;
V_2 = F_3 ( V_6 ) ;
return V_2 & 0x02 ? 1 : 0 ;
}
static int F_6 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
T_1 V_2 ;
V_2 = F_3 ( V_6 ) ;
return V_2 & 0x01 ;
}
static void F_7 ( const char * V_7 , struct V_8 * V_9 )
{
unsigned char V_10 ;
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < F_8 ( V_13 ) ; V_11 ++ ) {
V_9 -> V_14 = V_11 ;
V_12 = F_9 ( V_9 , & V_10 , 0 ) ;
if ( V_12 < 0 )
continue;
F_10 ( L_1 ,
V_7 , V_11 << 1 , V_13 [ V_11 ] ? V_13 [ V_11 ] : L_2 ) ;
}
}
int F_11 ( struct V_3 * V_4 , struct V_15 * V_16 )
{
if ( V_17 < 5 )
V_17 = 5 ;
memcpy ( & V_4 -> V_18 , & V_19 ,
sizeof( V_4 -> V_18 ) ) ;
V_4 -> V_20 . V_21 . V_22 = & V_16 -> V_21 ;
F_12 ( V_4 -> V_20 . V_7 , V_4 -> V_7 , sizeof( V_4 -> V_20 . V_7 ) ) ;
V_4 -> V_20 . V_23 = V_24 ;
V_4 -> V_18 . V_25 = V_17 ;
V_4 -> V_18 . V_1 = V_4 ;
F_13 ( & V_4 -> V_20 , & V_4 -> V_26 ) ;
V_4 -> V_20 . V_27 = & V_4 -> V_18 ;
V_4 -> V_8 . V_28 = & V_4 -> V_20 ;
F_12 ( V_4 -> V_8 . V_7 , L_3 , V_29 ) ;
F_1 ( V_4 , 1 ) ;
F_4 ( V_4 , 1 ) ;
V_4 -> V_30 = F_14 ( & V_4 -> V_20 ) ;
if ( 0 == V_4 -> V_30 ) {
static T_2 V_31 [] =
{ 0x0b , 0xdc , 0x86 , 0x52 } ;
static struct V_32 V_33 =
{ . V_34 = 0 , . V_14 = 0xc2 >> 1 , . V_10 = V_31 , . V_35 = 4 } ;
F_15 ( 1 , L_4 ) ;
switch( V_4 -> V_36 ) {
case V_37 :
case V_38 :
case V_39 :
F_10 ( L_5 ,
V_4 -> V_7 ) ;
F_16 ( V_4 -> V_8 . V_28 , & V_33 , 1 ) ;
break;
default:
break;
}
if ( V_40 )
F_7 ( V_4 -> V_7 , & V_4 -> V_8 ) ;
} else
F_10 ( L_6 , V_4 -> V_7 ) ;
return V_4 -> V_30 ;
}

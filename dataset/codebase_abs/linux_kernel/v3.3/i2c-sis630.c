static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_1 , T_1 V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 , int V_6 , T_1 * V_7 )
{
int V_8 ;
if ( ( V_8 = F_1 ( V_9 ) & 0x03 ) != 0x00 ) {
F_6 ( & V_5 -> V_10 , L_1 , V_8 ) ;
F_3 ( V_11 , 0x20 ) ;
if ( ( V_8 = F_1 ( V_9 ) & 0x03 ) != 0x00 ) {
F_6 ( & V_5 -> V_10 , L_2 , V_8 ) ;
return - V_12 ;
} else {
F_6 ( & V_5 -> V_10 , L_3 ) ;
}
}
* V_7 = F_1 ( V_9 ) ;
F_6 ( & V_5 -> V_10 , L_4 , * V_7 ) ;
if ( V_13 )
F_3 ( V_9 , 0x20 ) ;
else
F_3 ( V_9 , ( * V_7 & ~ 0x40 ) ) ;
V_8 = F_1 ( V_14 ) ;
F_3 ( V_14 , V_8 & 0x1e ) ;
F_3 ( V_11 , 0x10 | ( V_6 & 0x07 ) ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , int V_6 )
{
int V_8 , V_15 = 0 , V_16 = 0 ;
do {
F_8 ( 1 ) ;
V_8 = F_1 ( V_14 ) ;
if ( V_6 == V_17 && ( V_8 & 0x10 ) )
break;
} while ( ! ( V_8 & 0x0e ) && ( V_16 ++ < V_18 ) );
if ( V_16 > V_18 ) {
F_6 ( & V_5 -> V_10 , L_5 ) ;
V_15 = - V_19 ;
}
if ( V_8 & 0x02 ) {
F_6 ( & V_5 -> V_10 , L_6 ) ;
V_15 = - V_20 ;
}
if ( V_8 & 0x04 ) {
F_9 ( & V_5 -> V_10 , L_7 ) ;
V_15 = - V_21 ;
}
return V_15 ;
}
static void F_10 ( struct V_4 * V_5 , T_1 V_7 )
{
int V_8 = 0 ;
F_3 ( V_14 , V_8 ) ;
F_6 ( & V_5 -> V_10 , L_8 , F_1 ( V_9 ) ) ;
if ( V_13 && ! ( V_7 & 0x20 ) )
F_3 ( V_9 , ( F_1 ( V_9 ) & ~ 0x20 ) ) ;
F_6 ( & V_5 -> V_10 , L_9 , F_1 ( V_9 ) ) ;
}
static int F_11 ( struct V_4 * V_5 , int V_6 )
{
int V_15 = 0 ;
T_1 V_7 = 0 ;
V_15 = F_5 ( V_5 , V_6 , & V_7 ) ;
if ( ! V_15 ) {
V_15 = F_7 ( V_5 , V_6 ) ;
F_10 ( V_5 , V_7 ) ;
}
return V_15 ;
}
static int F_12 ( struct V_4 * V_5 , union V_22 * V_3 , int V_23 )
{
int V_24 , V_25 = 0 , V_26 = 0 ;
T_1 V_7 = 0 ;
if ( V_23 == V_27 ) {
V_25 = V_3 -> V_28 [ 0 ] ;
if ( V_25 < 0 )
V_25 = 0 ;
else if ( V_25 > 32 )
V_25 = 32 ;
F_3 ( V_29 , V_25 ) ;
for ( V_24 = 1 ; V_24 <= V_25 ; V_24 ++ ) {
F_6 ( & V_5 -> V_10 , L_10 , V_3 -> V_28 [ V_24 ] ) ;
F_3 ( V_30 + ( V_24 - 1 ) % 8 , V_3 -> V_28 [ V_24 ] ) ;
if ( V_24 == 8 || ( V_25 < 8 && V_24 == V_25 ) ) {
F_6 ( & V_5 -> V_10 , L_11 , V_25 , V_24 ) ;
V_26 = F_5 ( V_5 ,
V_17 , & V_7 ) ;
if ( V_26 )
return V_26 ;
}
else if ( ( V_24 - 1 ) % 8 == 7 || V_24 == V_25 ) {
F_6 ( & V_5 -> V_10 , L_12 , V_25 , V_24 ) ;
if ( V_24 > 8 ) {
F_6 ( & V_5 -> V_10 , L_13 , V_25 , V_24 ) ;
F_3 ( V_14 , 0x10 ) ;
}
V_26 = F_7 ( V_5 ,
V_17 ) ;
if ( V_26 ) {
F_6 ( & V_5 -> V_10 , L_14 ) ;
break;
}
}
}
}
else {
V_3 -> V_28 [ 0 ] = V_25 = 0 ;
V_26 = F_5 ( V_5 ,
V_17 , & V_7 ) ;
if ( V_26 )
return V_26 ;
do {
V_26 = F_7 ( V_5 , V_17 ) ;
if ( V_26 ) {
F_6 ( & V_5 -> V_10 , L_14 ) ;
break;
}
if ( V_25 == 0 )
V_3 -> V_28 [ 0 ] = F_1 ( V_29 ) ;
if ( V_3 -> V_28 [ 0 ] > 32 )
V_3 -> V_28 [ 0 ] = 32 ;
F_6 ( & V_5 -> V_10 , L_15 , V_3 -> V_28 [ 0 ] ) ;
for ( V_24 = 0 ; V_24 < 8 && V_25 < V_3 -> V_28 [ 0 ] ; V_24 ++ , V_25 ++ ) {
F_6 ( & V_5 -> V_10 , L_16 , V_24 , V_25 ) ;
V_3 -> V_28 [ V_25 + 1 ] = F_1 ( V_30 + V_24 ) ;
}
F_6 ( & V_5 -> V_10 , L_13 , V_25 , V_24 ) ;
F_3 ( V_14 , 0x10 ) ;
} while( V_25 < V_3 -> V_28 [ 0 ] );
}
F_10 ( V_5 , V_7 ) ;
return V_26 ;
}
static T_2 F_13 ( struct V_4 * V_5 , T_3 V_31 ,
unsigned short V_32 , char V_23 ,
T_1 V_33 , int V_6 , union V_22 * V_3 )
{
int V_34 ;
switch ( V_6 ) {
case V_35 :
F_3 ( V_36 , ( ( V_31 & 0x7f ) << 1 ) | ( V_23 & 0x01 ) ) ;
V_6 = V_37 ;
break;
case V_38 :
F_3 ( V_36 , ( ( V_31 & 0x7f ) << 1 ) | ( V_23 & 0x01 ) ) ;
if ( V_23 == V_27 )
F_3 ( V_39 , V_33 ) ;
V_6 = V_40 ;
break;
case V_41 :
F_3 ( V_36 , ( ( V_31 & 0x7f ) << 1 ) | ( V_23 & 0x01 ) ) ;
F_3 ( V_39 , V_33 ) ;
if ( V_23 == V_27 )
F_3 ( V_30 , V_3 -> V_42 ) ;
V_6 = V_43 ;
break;
case V_44 :
case V_45 :
F_3 ( V_36 , ( ( V_31 & 0x7f ) << 1 ) | ( V_23 & 0x01 ) ) ;
F_3 ( V_39 , V_33 ) ;
if ( V_23 == V_27 ) {
F_3 ( V_30 , V_3 -> V_46 & 0xff ) ;
F_3 ( V_30 + 1 , ( V_3 -> V_46 & 0xff00 ) >> 8 ) ;
}
V_6 = ( V_6 == V_44 ? V_47 : V_48 ) ;
break;
case V_49 :
F_3 ( V_36 , ( ( V_31 & 0x7f ) << 1 ) | ( V_23 & 0x01 ) ) ;
F_3 ( V_39 , V_33 ) ;
V_6 = V_17 ;
return F_12 ( V_5 , V_3 , V_23 ) ;
default:
F_14 ( & V_5 -> V_10 , L_17 ,
V_6 ) ;
return - V_50 ;
}
V_34 = F_11 ( V_5 , V_6 ) ;
if ( V_34 )
return V_34 ;
if ( ( V_6 != V_47 ) &&
( ( V_23 == V_27 ) || ( V_6 == V_37 ) ) ) {
return 0 ;
}
switch( V_6 ) {
case V_40 :
case V_43 :
V_3 -> V_42 = F_1 ( V_30 ) ;
break;
case V_47 :
case V_48 :
V_3 -> V_46 = F_1 ( V_30 ) + ( F_1 ( V_30 + 1 ) << 8 ) ;
break;
}
return 0 ;
}
static T_4 F_15 ( struct V_4 * V_51 )
{
return V_52 | V_53 | V_54 |
V_55 | V_56 |
V_57 ;
}
static int T_5 F_16 ( struct V_58 * V_59 )
{
unsigned char V_60 ;
struct V_58 * V_61 = NULL ;
int V_62 , V_24 ;
for ( V_24 = 0 ; V_63 [ V_24 ] > 0 ; V_24 ++ ) {
if ( ( V_61 = F_17 ( V_64 , V_63 [ V_24 ] , V_61 ) ) )
break;
}
if ( V_61 ) {
F_18 ( V_61 ) ;
}
else if ( V_65 ) {
F_9 ( & V_59 -> V_10 , L_18
L_19 ) ;
}
else {
return - V_66 ;
}
if ( F_19 ( V_59 , V_67 , & V_60 ) ) {
F_9 ( & V_59 -> V_10 , L_20 ) ;
V_62 = - V_66 ;
goto exit;
}
if ( ! ( V_60 & 0x80 ) &&
F_20 ( V_59 , V_67 , V_60 | 0x80 ) ) {
F_9 ( & V_59 -> V_10 , L_21 ) ;
V_62 = - V_66 ;
goto exit;
}
if ( F_21 ( V_59 , V_68 , & V_2 ) ) {
F_9 ( & V_59 -> V_10 , L_22 ) ;
V_62 = - V_66 ;
goto exit;
}
F_6 ( & V_59 -> V_10 , L_23 , V_2 ) ;
V_62 = F_22 ( V_2 + V_14 , V_69 ,
V_70 . V_71 ) ;
if ( V_62 )
goto exit;
if ( ! F_23 ( V_2 + V_14 , V_69 ,
V_70 . V_71 ) ) {
F_9 ( & V_59 -> V_10 , L_24
L_25 , V_2 + V_14 , V_2 + V_72 ) ;
V_62 = - V_12 ;
goto exit;
}
V_62 = 0 ;
exit:
if ( V_62 )
V_2 = 0 ;
return V_62 ;
}
static int T_5 F_24 ( struct V_58 * V_10 , const struct V_73 * V_74 )
{
if ( F_16 ( V_10 ) ) {
F_9 ( & V_10 -> V_10 , L_26 ) ;
return - V_66 ;
}
V_75 . V_10 . V_76 = & V_10 -> V_10 ;
snprintf ( V_75 . V_71 , sizeof( V_75 . V_71 ) ,
L_27 , V_2 + V_14 ) ;
return F_25 ( & V_75 ) ;
}
static void T_6 F_26 ( struct V_58 * V_10 )
{
if ( V_2 ) {
F_27 ( & V_75 ) ;
F_28 ( V_2 + V_14 , V_69 ) ;
V_2 = 0 ;
}
}
static int T_7 F_29 ( void )
{
return F_30 ( & V_70 ) ;
}
static void T_8 F_31 ( void )
{
F_32 ( & V_70 ) ;
}

static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 V_6 [] = {
{
. V_7 = V_4 -> V_7 ,
. V_8 = V_9 ,
. V_10 = sizeof( V_2 -> V_11 ) ,
. V_11 = V_2 -> V_11
} ,
} ;
if ( V_2 -> V_12 ) {
int V_7 = F_2 ( V_13 ) ;
int V_14 = sizeof( V_2 -> V_11 ) - 1 ;
if ( F_3 ( V_4 , V_7 , V_14 ,
V_2 -> V_11 + 1 ) != V_14 ) {
F_4 ( & V_4 -> V_15 , L_1 ) ;
return - V_16 ;
}
} else {
if ( ( F_5 ( V_4 -> V_17 , V_6 , 1 ) ) != 1 ) {
F_4 ( & V_4 -> V_15 , L_1 ) ;
return - V_16 ;
}
}
F_6 ( & V_4 -> V_15 ,
L_2 ,
V_2 -> V_18 + 0 , V_2 -> V_18 [ 3 ] ,
V_2 -> V_18 + 4 , V_2 -> V_18 [ 7 ] ,
V_2 -> V_18 + 8 , V_2 -> V_18 + 11 ,
V_2 -> V_18 [ 14 ] , V_2 -> V_18 [ 15 ] ) ;
return 0 ;
}
static unsigned F_7 ( struct V_1 * V_2 , unsigned V_19 )
{
unsigned V_20 ;
if ( V_2 -> V_21 )
return F_8 ( V_19 & 0x3f ) ;
V_20 = F_8 ( V_19 & 0x1f ) ;
if ( V_20 == 12 )
V_20 = 0 ;
if ( V_19 & 0x20 )
V_20 += 12 ;
return V_20 ;
}
static unsigned F_9 ( struct V_1 * V_2 , unsigned V_20 )
{
if ( V_2 -> V_21 )
return F_10 ( V_20 ) ;
if ( V_20 > 12 )
return 0x20 | F_10 ( V_20 - 12 ) ;
if ( V_20 == 12 )
return 0x20 | F_10 ( 12 ) ;
if ( V_20 == 0 )
return F_10 ( 12 ) ;
return F_10 ( V_20 ) ;
}
static int F_11 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
int V_24 = F_1 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
V_23 -> V_25 = F_8 ( V_2 -> V_18 [ V_13 ] & 0x7f ) ;
V_23 -> V_26 = F_8 ( V_2 -> V_18 [ V_27 ] & 0x7f ) ;
V_23 -> V_28 = F_7 ( V_2 , V_2 -> V_18 [ V_29 ] ) ;
V_23 -> V_30 = F_8 ( V_2 -> V_18 [ V_31 ] & 0x07 ) ;
V_23 -> V_32 = F_8 ( V_2 -> V_18 [ V_33 ] & 0x3f ) ;
V_23 -> V_34 = F_8 ( V_2 -> V_18 [ V_35 ] & 0x1f ) - 1 ;
V_23 -> V_36 = F_8 ( V_2 -> V_18 [ V_37 ] ) + 100 ;
F_6 ( & V_4 -> V_15 , L_3
L_4 ,
V_38 ,
V_23 -> V_25 , V_23 -> V_26 , V_23 -> V_28 ,
V_23 -> V_32 , V_23 -> V_34 , V_23 -> V_36 , V_23 -> V_30 ) ;
return F_13 ( V_23 ) ;
}
static int F_14 ( struct V_3 * V_4 , struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_11 [ 7 ] ;
int V_7 ;
F_6 ( & V_4 -> V_15 , L_5
L_4 ,
V_38 ,
V_23 -> V_25 , V_23 -> V_26 , V_23 -> V_28 ,
V_23 -> V_32 , V_23 -> V_34 , V_23 -> V_36 , V_23 -> V_30 ) ;
V_7 = F_2 ( V_13 ) ;
V_11 [ 0 ] = F_10 ( V_23 -> V_25 ) ;
V_11 [ 1 ] = F_10 ( V_23 -> V_26 ) ;
V_11 [ 2 ] = F_9 ( V_2 , V_23 -> V_28 ) ;
V_11 [ 3 ] = F_10 ( V_23 -> V_30 ) ;
V_11 [ 4 ] = F_10 ( V_23 -> V_32 ) ;
V_11 [ 5 ] = F_10 ( V_23 -> V_34 + 1 ) ;
V_11 [ 6 ] = F_10 ( V_23 -> V_36 - 100 ) ;
if ( F_15 ( V_4 , V_7 , sizeof( V_11 ) , V_11 ) < 0 ) {
F_16 ( & V_4 -> V_15 , L_6 , V_38 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , int * V_39 , int * V_40 )
{
struct V_1 * V_1 = F_12 ( V_4 ) ;
T_1 V_41 = V_1 -> V_18 [ V_42 ] ;
if ( V_39 )
* V_39 = ( V_41 & V_43 ) ? 32000 : 32768 ;
if ( V_40 ) {
F_6 ( & V_4 -> V_15 , L_7 , V_38 , V_41 ) ;
V_41 &= V_44 ;
if ( V_41 & 0x3e ) {
int V_45 = V_41 & 0x3f ;
if ( V_41 & 0x40 )
V_45 = ( ~ V_45 | ( V_46 ) 0xc0 ) + 1 ;
else
V_45 = V_45 - 1 ;
V_41 = V_45 * 2 ;
} else
V_41 = 0 ;
* V_40 = V_41 ;
}
return 0 ;
}
static int F_18 ( struct V_47 * V_15 , struct V_22 * V_23 )
{
return F_11 ( F_19 ( V_15 ) , V_23 ) ;
}
static int F_20 ( struct V_47 * V_15 , struct V_22 * V_23 )
{
return F_14 ( F_19 ( V_15 ) , V_23 ) ;
}
static int F_21 ( struct V_47 * V_15 , unsigned int V_48 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_11 ;
int V_24 , V_7 ;
V_11 = V_2 -> V_18 [ V_49 ] ;
if ( ! V_2 -> V_50 )
return - V_51 ;
V_24 = F_1 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
V_7 = F_2 ( V_49 ) ;
if ( V_48 )
V_11 |= V_52 ;
else
V_11 &= ~ V_52 ;
if ( F_22 ( V_4 , V_7 , V_11 ) < 0 ) {
F_4 ( V_15 , L_8 ) ;
V_24 = - V_16 ;
} else
V_2 -> V_18 [ V_49 ] = V_11 ;
return V_24 ;
}
static int F_23 ( struct V_47 * V_15 , struct V_53 * V_45 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
struct V_1 * V_2 = F_12 ( V_4 ) ;
int V_24 ;
V_24 = F_1 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
V_45 -> time . V_25 = 0 ;
V_45 -> time . V_26 = F_8 ( V_2 -> V_18 [ V_54 ] & 0x7f ) ;
V_45 -> time . V_28 = F_7 ( V_2 , V_2 -> V_18 [ V_55 ] ) ;
V_45 -> V_48 = ! ! ( V_2 -> V_18 [ V_49 ] & V_52 ) ;
V_45 -> V_56 = ! ! ( V_2 -> V_18 [ V_57 ] & V_58 ) ;
return 0 ;
}
static int F_24 ( struct V_47 * V_15 , struct V_53 * V_45 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
struct V_1 * V_2 = F_12 ( V_4 ) ;
int V_24 , V_7 , V_59 ;
unsigned char V_11 [ 3 ] ;
if ( V_45 -> time . V_32 != - 1
|| V_45 -> time . V_34 != - 1
|| V_45 -> time . V_36 != - 1 )
return - V_51 ;
V_24 = F_1 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
if ( V_2 -> V_18 [ V_49 ] & V_52 ) {
V_7 = F_2 ( V_49 ) ;
V_11 [ 0 ] = V_2 -> V_18 [ V_49 ] & ~ V_52 ;
if ( F_22 ( V_4 , V_7 , V_11 [ 0 ] ) < 0 ) {
F_6 ( V_15 , L_9 ) ;
return - V_16 ;
}
V_2 -> V_18 [ V_49 ] = V_11 [ 0 ] ;
}
V_11 [ 0 ] = F_10 ( V_45 -> time . V_26 ) ;
V_11 [ 1 ] = F_9 ( V_2 , V_45 -> time . V_28 ) ;
V_11 [ 2 ] = 0x7f ;
for ( V_59 = 0 ; V_59 < sizeof( V_11 ) ; V_59 ++ ) {
V_7 = F_2 ( V_54 + V_59 ) ;
if ( F_22 ( V_4 , V_7 , V_11 [ V_59 ] ) < 0 ) {
F_6 ( V_15 , L_10 ) ;
return - V_16 ;
}
}
if ( V_45 -> V_48 ) {
V_7 = F_2 ( V_49 ) ;
V_11 [ 0 ] = V_2 -> V_18 [ V_49 ] | V_52 ;
if ( F_22 ( V_4 , V_7 , V_11 [ 0 ] ) < 0 )
F_4 ( V_15 , L_11 ) ;
V_2 -> V_18 [ V_49 ] = V_11 [ 0 ] ;
}
return 0 ;
}
static int F_25 ( struct V_47 * V_15 , struct V_60 * V_61 )
{
int V_62 , V_39 , V_40 ;
V_62 = F_17 ( F_19 ( V_15 ) , & V_39 , & V_40 ) ;
if ( V_62 == 0 ) {
F_26 ( V_61 , L_12 ,
V_39 / 1000 , V_39 % 1000 ) ;
F_26 ( V_61 , L_13 , V_40 ) ;
}
return 0 ;
}
static T_2 F_27 ( struct V_47 * V_15 ,
struct V_63 * V_64 , char * V_11 )
{
int V_62 , V_40 ;
V_62 = F_17 ( F_19 ( V_15 ) , NULL , & V_40 ) ;
if ( V_62 )
return V_62 ;
return sprintf ( V_11 , L_14 , V_40 ) ;
}
static T_2 F_28 ( struct V_47 * V_15 ,
struct V_63 * V_64 , char * V_11 )
{
int V_62 , V_39 ;
V_62 = F_17 ( F_19 ( V_15 ) , & V_39 , NULL ) ;
if ( V_62 )
return V_62 ;
return sprintf ( V_11 , L_15 , V_39 / 1000 , V_39 % 1000 ) ;
}
static int F_29 ( struct V_47 * V_15 )
{
int V_62 ;
V_62 = F_30 ( V_15 , & V_65 ) ;
if ( V_62 )
return V_62 ;
V_62 = F_30 ( V_15 , & V_66 ) ;
if ( V_62 )
F_31 ( V_15 , & V_65 ) ;
return V_62 ;
}
static void F_32 ( struct V_47 * V_15 )
{
F_31 ( V_15 , & V_65 ) ;
F_31 ( V_15 , & V_66 ) ;
}
static int F_29 ( struct V_47 * V_15 )
{
return 0 ;
}
static void F_32 ( struct V_47 * V_15 )
{
}
static int F_33 ( struct V_1 * V_1 )
{
unsigned char V_11 [ 2 ] ;
int V_7 , V_59 , V_67 = 0 ;
if ( V_1 -> type == V_68 ) {
if ( V_1 -> V_18 [ V_57 ] & V_69 )
return V_67 ;
V_1 -> V_18 [ V_57 ] |= V_69 ;
} else {
if ( ! ( V_1 -> V_18 [ V_57 ] & V_70 ) )
return V_67 ;
V_1 -> V_18 [ V_57 ] &= ~ V_70 ;
}
V_7 = F_2 ( V_49 ) ;
V_11 [ 0 ] = V_1 -> V_18 [ V_49 ] ;
V_11 [ 1 ] = V_1 -> V_18 [ V_57 ] ;
switch ( V_1 -> type ) {
case V_71 :
case V_72 :
V_11 [ 1 ] |= V_73 ;
V_1 -> V_21 = 1 ;
break;
case V_68 :
case V_74 :
case V_75 :
case V_76 :
V_11 [ 0 ] |= V_77 ;
V_1 -> V_21 = 1 ;
break;
default:
break;
}
for ( V_59 = 0 ; V_59 < sizeof( V_11 ) ; V_59 ++ ) {
V_7 = F_2 ( V_49 + V_59 ) ;
V_67 = F_22 ( V_1 -> V_4 , V_7 , V_11 [ V_59 ] ) ;
if ( F_34 ( V_67 < 0 ) )
return V_67 ;
}
V_1 -> V_18 [ V_49 ] = V_11 [ 0 ] ;
V_1 -> V_18 [ V_57 ] = V_11 [ 1 ] ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 ,
const struct V_78 * V_79 )
{
int V_62 = 0 ;
int V_80 = 0 ;
struct V_1 * V_1 ;
struct V_22 V_23 ;
F_6 ( & V_4 -> V_15 , L_16 , V_38 ) ;
if ( ! F_36 ( V_4 -> V_17 , V_81 |
V_82 | V_83 ) ) {
if ( F_36 ( V_4 -> V_17 ,
V_82 |
V_83 ) )
V_80 = 1 ;
else {
V_62 = - V_84 ;
goto exit;
}
}
V_1 = F_37 ( & V_4 -> V_15 , sizeof( struct V_1 ) ,
V_85 ) ;
if ( ! V_1 ) {
V_62 = - V_86 ;
goto exit;
}
V_1 -> V_4 = V_4 ;
F_38 ( V_4 , V_1 ) ;
V_1 -> type = V_79 -> V_87 ;
V_1 -> V_18 = & V_1 -> V_11 [ 1 ] ;
V_1 -> V_12 = V_80 ;
V_62 = F_1 ( V_1 ) ;
if ( V_62 < 0 )
goto exit;
switch ( V_1 -> type ) {
case V_71 :
case V_72 :
if ( V_1 -> V_18 [ V_57 ] & V_73 )
V_1 -> V_21 = 1 ;
break;
case V_68 :
case V_74 :
case V_75 :
case V_76 :
if ( V_1 -> V_18 [ V_49 ] & V_77 )
V_1 -> V_21 = 1 ;
break;
default:
F_16 ( & V_4 -> V_15 , L_17 ) ;
goto exit;
}
V_62 = F_33 ( V_1 ) ;
if ( F_34 ( V_62 < 0 ) ) {
F_16 ( & V_4 -> V_15 , L_18 ) ;
goto exit;
}
if ( F_11 ( V_4 , & V_23 ) < 0 )
F_4 ( & V_4 -> V_15 , L_19 ) ;
F_39 (&client->dev, L_20 ,
({ char *s; switch (rs5c372->type) {
case rtc_r2025sd: s = L_21; break;
case rtc_r2221tl: s = L_22; break;
case rtc_rs5c372a: s = L_23; break;
case rtc_rs5c372b: s = L_24; break;
case rtc_rv5c386: s = L_25; break;
case rtc_rv5c387a: s = L_26; break;
default: s = L_27; break;
}; s;}),
rs5c372->time24 ? L_28 : L_29
) ;
V_1 -> V_88 = F_40 ( & V_4 -> V_15 ,
V_89 . V_90 . V_91 ,
& V_92 , V_93 ) ;
if ( F_41 ( V_1 -> V_88 ) ) {
V_62 = F_42 ( V_1 -> V_88 ) ;
goto exit;
}
V_62 = F_29 ( & V_4 -> V_15 ) ;
if ( V_62 )
goto exit;
return 0 ;
exit:
return V_62 ;
}
static int F_43 ( struct V_3 * V_4 )
{
F_32 ( & V_4 -> V_15 ) ;
return 0 ;
}

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
L_2
L_3 ,
V_2 -> V_18 [ 0 ] , V_2 -> V_18 [ 1 ] , V_2 -> V_18 [ 2 ] , V_2 -> V_18 [ 3 ] ,
V_2 -> V_18 [ 4 ] , V_2 -> V_18 [ 5 ] , V_2 -> V_18 [ 6 ] , V_2 -> V_18 [ 7 ] ,
V_2 -> V_18 [ 8 ] , V_2 -> V_18 [ 9 ] , V_2 -> V_18 [ 10 ] , V_2 -> V_18 [ 11 ] ,
V_2 -> V_18 [ 12 ] , V_2 -> V_18 [ 13 ] , V_2 -> V_18 [ 14 ] , V_2 -> V_18 [ 15 ] ) ;
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
F_6 ( & V_4 -> V_15 , L_4
L_5 ,
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
F_6 ( & V_4 -> V_15 , L_6
L_5 ,
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
F_16 ( & V_4 -> V_15 , L_7 , V_38 ) ;
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
F_6 ( & V_4 -> V_15 , L_8 , V_38 , V_41 ) ;
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
F_23 ( V_53 L_9 ,
V_2 -> V_54 -> V_55 ) ;
V_24 = - V_16 ;
} else
V_2 -> V_18 [ V_49 ] = V_11 ;
return V_24 ;
}
static int F_24 ( struct V_47 * V_15 , struct V_56 * V_45 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
struct V_1 * V_2 = F_12 ( V_4 ) ;
int V_24 ;
V_24 = F_1 ( V_2 ) ;
if ( V_24 < 0 )
return V_24 ;
V_45 -> time . V_25 = 0 ;
V_45 -> time . V_26 = F_8 ( V_2 -> V_18 [ V_57 ] & 0x7f ) ;
V_45 -> time . V_28 = F_7 ( V_2 , V_2 -> V_18 [ V_58 ] ) ;
V_45 -> time . V_32 = - 1 ;
V_45 -> time . V_34 = - 1 ;
V_45 -> time . V_36 = - 1 ;
V_45 -> time . V_30 = - 1 ;
V_45 -> time . V_59 = - 1 ;
V_45 -> time . V_60 = - 1 ;
V_45 -> V_48 = ! ! ( V_2 -> V_18 [ V_49 ] & V_52 ) ;
V_45 -> V_61 = ! ! ( V_2 -> V_18 [ V_62 ] & V_63 ) ;
return 0 ;
}
static int F_25 ( struct V_47 * V_15 , struct V_56 * V_45 )
{
struct V_3 * V_4 = F_19 ( V_15 ) ;
struct V_1 * V_2 = F_12 ( V_4 ) ;
int V_24 , V_7 , V_64 ;
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
F_26 ( L_10 , V_2 -> V_54 -> V_55 ) ;
return - V_16 ;
}
V_2 -> V_18 [ V_49 ] = V_11 [ 0 ] ;
}
V_11 [ 0 ] = F_10 ( V_45 -> time . V_26 ) ;
V_11 [ 1 ] = F_9 ( V_2 , V_45 -> time . V_28 ) ;
V_11 [ 2 ] = 0x7f ;
for ( V_64 = 0 ; V_64 < sizeof( V_11 ) ; V_64 ++ ) {
V_7 = F_2 ( V_57 + V_64 ) ;
if ( F_22 ( V_4 , V_7 , V_11 [ V_64 ] ) < 0 ) {
F_26 ( L_11 , V_2 -> V_54 -> V_55 ) ;
return - V_16 ;
}
}
if ( V_45 -> V_48 ) {
V_7 = F_2 ( V_49 ) ;
V_11 [ 0 ] = V_2 -> V_18 [ V_49 ] | V_52 ;
if ( F_22 ( V_4 , V_7 , V_11 [ 0 ] ) < 0 )
F_23 ( V_53 L_12 ,
V_2 -> V_54 -> V_55 ) ;
V_2 -> V_18 [ V_49 ] = V_11 [ 0 ] ;
}
return 0 ;
}
static int F_27 ( struct V_47 * V_15 , struct V_65 * V_66 )
{
int V_67 , V_39 , V_40 ;
V_67 = F_17 ( F_19 ( V_15 ) , & V_39 , & V_40 ) ;
if ( V_67 == 0 ) {
F_28 ( V_66 , L_13 ,
V_39 / 1000 , V_39 % 1000 ) ;
F_28 ( V_66 , L_14 , V_40 ) ;
}
return 0 ;
}
static T_2 F_29 ( struct V_47 * V_15 ,
struct V_68 * V_69 , char * V_11 )
{
int V_67 , V_40 ;
V_67 = F_17 ( F_19 ( V_15 ) , NULL , & V_40 ) ;
if ( V_67 )
return V_67 ;
return sprintf ( V_11 , L_15 , V_40 ) ;
}
static T_2 F_30 ( struct V_47 * V_15 ,
struct V_68 * V_69 , char * V_11 )
{
int V_67 , V_39 ;
V_67 = F_17 ( F_19 ( V_15 ) , & V_39 , NULL ) ;
if ( V_67 )
return V_67 ;
return sprintf ( V_11 , L_16 , V_39 / 1000 , V_39 % 1000 ) ;
}
static int F_31 ( struct V_47 * V_15 )
{
int V_67 ;
V_67 = F_32 ( V_15 , & V_70 ) ;
if ( V_67 )
return V_67 ;
V_67 = F_32 ( V_15 , & V_71 ) ;
if ( V_67 )
F_33 ( V_15 , & V_70 ) ;
return V_67 ;
}
static void F_34 ( struct V_47 * V_15 )
{
F_33 ( V_15 , & V_70 ) ;
F_33 ( V_15 , & V_71 ) ;
}
static int F_31 ( struct V_47 * V_15 )
{
return 0 ;
}
static void F_34 ( struct V_47 * V_15 )
{
}
static int F_35 ( struct V_1 * V_1 )
{
unsigned char V_11 [ 2 ] ;
int V_7 , V_64 , V_72 = 0 ;
if ( V_1 -> type == V_73 ) {
if ( ! ( V_1 -> V_18 [ V_62 ] & V_74 ) )
return V_72 ;
V_1 -> V_18 [ V_62 ] &= ~ V_74 ;
} else {
if ( ! ( V_1 -> V_18 [ V_62 ] & V_75 ) )
return V_72 ;
V_1 -> V_18 [ V_62 ] &= ~ V_75 ;
}
V_7 = F_2 ( V_49 ) ;
V_11 [ 0 ] = V_1 -> V_18 [ V_49 ] ;
V_11 [ 1 ] = V_1 -> V_18 [ V_62 ] ;
switch ( V_1 -> type ) {
case V_76 :
case V_77 :
V_11 [ 1 ] |= V_78 ;
V_1 -> V_21 = 1 ;
break;
case V_73 :
case V_79 :
case V_80 :
V_11 [ 0 ] |= V_81 ;
V_1 -> V_21 = 1 ;
break;
default:
break;
}
for ( V_64 = 0 ; V_64 < sizeof( V_11 ) ; V_64 ++ ) {
V_7 = F_2 ( V_49 + V_64 ) ;
V_72 = F_22 ( V_1 -> V_4 , V_7 , V_11 [ V_64 ] ) ;
if ( F_36 ( V_72 < 0 ) )
return V_72 ;
}
V_1 -> V_18 [ V_49 ] = V_11 [ 0 ] ;
V_1 -> V_18 [ V_62 ] = V_11 [ 1 ] ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
const struct V_82 * V_83 )
{
int V_67 = 0 ;
int V_84 = 0 ;
struct V_1 * V_1 ;
struct V_22 V_23 ;
F_6 ( & V_4 -> V_15 , L_17 , V_38 ) ;
if ( ! F_38 ( V_4 -> V_17 , V_85 |
V_86 | V_87 ) ) {
if ( F_38 ( V_4 -> V_17 ,
V_86 |
V_87 ) )
V_84 = 1 ;
else {
V_67 = - V_88 ;
goto exit;
}
}
if ( ! ( V_1 = F_39 ( sizeof( struct V_1 ) , V_89 ) ) ) {
V_67 = - V_90 ;
goto exit;
}
V_1 -> V_4 = V_4 ;
F_40 ( V_4 , V_1 ) ;
V_1 -> type = V_83 -> V_91 ;
V_1 -> V_18 = & V_1 -> V_11 [ 1 ] ;
V_1 -> V_12 = V_84 ;
V_67 = F_1 ( V_1 ) ;
if ( V_67 < 0 )
goto V_92;
switch ( V_1 -> type ) {
case V_76 :
case V_77 :
if ( V_1 -> V_18 [ V_62 ] & V_78 )
V_1 -> V_21 = 1 ;
break;
case V_73 :
case V_79 :
case V_80 :
if ( V_1 -> V_18 [ V_49 ] & V_81 )
V_1 -> V_21 = 1 ;
break;
default:
F_16 ( & V_4 -> V_15 , L_18 ) ;
goto V_92;
}
V_67 = F_35 ( V_1 ) ;
if ( F_36 ( V_67 < 0 ) ) {
F_16 ( & V_4 -> V_15 , L_19 ) ;
goto V_92;
}
if ( F_11 ( V_4 , & V_23 ) < 0 )
F_4 ( & V_4 -> V_15 , L_20 ) ;
F_41 (&client->dev, L_21 DRV_VERSION L_22 ,
({ char *s; switch (rs5c372->type) {
case rtc_r2025sd: s = L_23; break;
case rtc_rs5c372a: s = L_24; break;
case rtc_rs5c372b: s = L_25; break;
case rtc_rv5c386: s = L_26; break;
case rtc_rv5c387a: s = L_27; break;
default: s = L_28; break;
}; s;}),
rs5c372->time24 ? L_29 : L_30
) ;
V_1 -> V_54 = F_42 ( V_93 . V_94 . V_55 ,
& V_4 -> V_15 , & V_95 , V_96 ) ;
if ( F_43 ( V_1 -> V_54 ) ) {
V_67 = F_44 ( V_1 -> V_54 ) ;
goto V_92;
}
V_67 = F_31 ( & V_4 -> V_15 ) ;
if ( V_67 )
goto V_97;
return 0 ;
V_97:
F_45 ( V_1 -> V_54 ) ;
V_92:
F_46 ( V_1 ) ;
exit:
return V_67 ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_12 ( V_4 ) ;
F_45 ( V_1 -> V_54 ) ;
F_34 ( & V_4 -> V_15 ) ;
F_46 ( V_1 ) ;
return 0 ;
}

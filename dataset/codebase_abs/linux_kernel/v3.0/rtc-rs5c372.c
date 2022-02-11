static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 V_6 [] = {
{ V_4 -> V_7 , V_8 , sizeof V_2 -> V_9 , V_2 -> V_9 } ,
} ;
if ( V_2 -> V_10 ) {
int V_7 = F_2 ( V_11 ) ;
int V_12 = sizeof( V_2 -> V_9 ) - 1 ;
if ( F_3 ( V_4 , V_7 , V_12 ,
V_2 -> V_9 + 1 ) != V_12 ) {
F_4 ( & V_4 -> V_13 , L_1 ) ;
return - V_14 ;
}
} else {
if ( ( F_5 ( V_4 -> V_15 , V_6 , 1 ) ) != 1 ) {
F_4 ( & V_4 -> V_13 , L_1 ) ;
return - V_14 ;
}
}
F_6 ( & V_4 -> V_13 ,
L_2
L_3 ,
V_2 -> V_16 [ 0 ] , V_2 -> V_16 [ 1 ] , V_2 -> V_16 [ 2 ] , V_2 -> V_16 [ 3 ] ,
V_2 -> V_16 [ 4 ] , V_2 -> V_16 [ 5 ] , V_2 -> V_16 [ 6 ] , V_2 -> V_16 [ 7 ] ,
V_2 -> V_16 [ 8 ] , V_2 -> V_16 [ 9 ] , V_2 -> V_16 [ 10 ] , V_2 -> V_16 [ 11 ] ,
V_2 -> V_16 [ 12 ] , V_2 -> V_16 [ 13 ] , V_2 -> V_16 [ 14 ] , V_2 -> V_16 [ 15 ] ) ;
return 0 ;
}
static unsigned F_7 ( struct V_1 * V_2 , unsigned V_17 )
{
unsigned V_18 ;
if ( V_2 -> V_19 )
return F_8 ( V_17 & 0x3f ) ;
V_18 = F_8 ( V_17 & 0x1f ) ;
if ( V_18 == 12 )
V_18 = 0 ;
if ( V_17 & 0x20 )
V_18 += 12 ;
return V_18 ;
}
static unsigned F_9 ( struct V_1 * V_2 , unsigned V_18 )
{
if ( V_2 -> V_19 )
return F_10 ( V_18 ) ;
if ( V_18 > 12 )
return 0x20 | F_10 ( V_18 - 12 ) ;
if ( V_18 == 12 )
return 0x20 | F_10 ( 12 ) ;
if ( V_18 == 0 )
return F_10 ( 12 ) ;
return F_10 ( V_18 ) ;
}
static int F_11 ( struct V_3 * V_4 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
int V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_21 -> V_23 = F_8 ( V_2 -> V_16 [ V_11 ] & 0x7f ) ;
V_21 -> V_24 = F_8 ( V_2 -> V_16 [ V_25 ] & 0x7f ) ;
V_21 -> V_26 = F_7 ( V_2 , V_2 -> V_16 [ V_27 ] ) ;
V_21 -> V_28 = F_8 ( V_2 -> V_16 [ V_29 ] & 0x07 ) ;
V_21 -> V_30 = F_8 ( V_2 -> V_16 [ V_31 ] & 0x3f ) ;
V_21 -> V_32 = F_8 ( V_2 -> V_16 [ V_33 ] & 0x1f ) - 1 ;
V_21 -> V_34 = F_8 ( V_2 -> V_16 [ V_35 ] ) + 100 ;
F_6 ( & V_4 -> V_13 , L_4
L_5 ,
V_36 ,
V_21 -> V_23 , V_21 -> V_24 , V_21 -> V_26 ,
V_21 -> V_30 , V_21 -> V_32 , V_21 -> V_34 , V_21 -> V_28 ) ;
return F_13 ( V_21 ) ;
}
static int F_14 ( struct V_3 * V_4 , struct V_20 * V_21 )
{
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_9 [ 7 ] ;
int V_7 ;
F_6 ( & V_4 -> V_13 , L_6
L_5 ,
V_36 ,
V_21 -> V_23 , V_21 -> V_24 , V_21 -> V_26 ,
V_21 -> V_30 , V_21 -> V_32 , V_21 -> V_34 , V_21 -> V_28 ) ;
V_7 = F_2 ( V_11 ) ;
V_9 [ 0 ] = F_10 ( V_21 -> V_23 ) ;
V_9 [ 1 ] = F_10 ( V_21 -> V_24 ) ;
V_9 [ 2 ] = F_9 ( V_2 , V_21 -> V_26 ) ;
V_9 [ 3 ] = F_10 ( V_21 -> V_28 ) ;
V_9 [ 4 ] = F_10 ( V_21 -> V_30 ) ;
V_9 [ 5 ] = F_10 ( V_21 -> V_32 + 1 ) ;
V_9 [ 6 ] = F_10 ( V_21 -> V_34 - 100 ) ;
if ( F_15 ( V_4 , V_7 , sizeof( V_9 ) , V_9 ) < 0 ) {
F_16 ( & V_4 -> V_13 , L_7 , V_36 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 , int * V_37 , int * V_38 )
{
struct V_1 * V_1 = F_12 ( V_4 ) ;
T_1 V_39 = V_1 -> V_16 [ V_40 ] ;
if ( V_37 )
* V_37 = ( V_39 & V_41 ) ? 32000 : 32768 ;
if ( V_38 ) {
F_6 ( & V_4 -> V_13 , L_8 , V_36 , V_39 ) ;
V_39 &= V_42 ;
if ( V_39 & 0x3e ) {
int V_43 = V_39 & 0x3f ;
if ( V_39 & 0x40 )
V_43 = ( ~ V_43 | ( V_44 ) 0xc0 ) + 1 ;
else
V_43 = V_43 - 1 ;
V_39 = V_43 * 2 ;
} else
V_39 = 0 ;
* V_38 = V_39 ;
}
return 0 ;
}
static int F_18 ( struct V_45 * V_13 , struct V_20 * V_21 )
{
return F_11 ( F_19 ( V_13 ) , V_21 ) ;
}
static int F_20 ( struct V_45 * V_13 , struct V_20 * V_21 )
{
return F_14 ( F_19 ( V_13 ) , V_21 ) ;
}
static int F_21 ( struct V_45 * V_13 , unsigned int V_46 )
{
struct V_3 * V_4 = F_19 ( V_13 ) ;
struct V_1 * V_2 = F_12 ( V_4 ) ;
unsigned char V_9 ;
int V_22 , V_7 ;
V_9 = V_2 -> V_16 [ V_47 ] ;
if ( ! V_2 -> V_48 )
return - V_49 ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_7 = F_2 ( V_47 ) ;
if ( V_46 )
V_9 |= V_50 ;
else
V_9 &= ~ V_50 ;
if ( F_22 ( V_4 , V_7 , V_9 ) < 0 ) {
F_23 ( V_51 L_9 ,
V_2 -> V_52 -> V_53 ) ;
V_22 = - V_14 ;
} else
V_2 -> V_16 [ V_47 ] = V_9 ;
return V_22 ;
}
static int F_24 ( struct V_45 * V_13 , struct V_54 * V_43 )
{
struct V_3 * V_4 = F_19 ( V_13 ) ;
struct V_1 * V_2 = F_12 ( V_4 ) ;
int V_22 ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
V_43 -> time . V_23 = 0 ;
V_43 -> time . V_24 = F_8 ( V_2 -> V_16 [ V_55 ] & 0x7f ) ;
V_43 -> time . V_26 = F_7 ( V_2 , V_2 -> V_16 [ V_56 ] ) ;
V_43 -> time . V_30 = - 1 ;
V_43 -> time . V_32 = - 1 ;
V_43 -> time . V_34 = - 1 ;
V_43 -> time . V_28 = - 1 ;
V_43 -> time . V_57 = - 1 ;
V_43 -> time . V_58 = - 1 ;
V_43 -> V_46 = ! ! ( V_2 -> V_16 [ V_47 ] & V_50 ) ;
V_43 -> V_59 = ! ! ( V_2 -> V_16 [ V_60 ] & V_61 ) ;
return 0 ;
}
static int F_25 ( struct V_45 * V_13 , struct V_54 * V_43 )
{
struct V_3 * V_4 = F_19 ( V_13 ) ;
struct V_1 * V_2 = F_12 ( V_4 ) ;
int V_22 , V_7 , V_62 ;
unsigned char V_9 [ 3 ] ;
if ( V_43 -> time . V_30 != - 1
|| V_43 -> time . V_32 != - 1
|| V_43 -> time . V_34 != - 1 )
return - V_49 ;
V_22 = F_1 ( V_2 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_2 -> V_16 [ V_47 ] & V_50 ) {
V_7 = F_2 ( V_47 ) ;
V_9 [ 0 ] = V_2 -> V_16 [ V_47 ] & ~ V_50 ;
if ( F_22 ( V_4 , V_7 , V_9 [ 0 ] ) < 0 ) {
F_26 ( L_10 , V_2 -> V_52 -> V_53 ) ;
return - V_14 ;
}
V_2 -> V_16 [ V_47 ] = V_9 [ 0 ] ;
}
V_9 [ 0 ] = F_10 ( V_43 -> time . V_24 ) ;
V_9 [ 1 ] = F_9 ( V_2 , V_43 -> time . V_26 ) ;
V_9 [ 2 ] = 0x7f ;
for ( V_62 = 0 ; V_62 < sizeof( V_9 ) ; V_62 ++ ) {
V_7 = F_2 ( V_55 + V_62 ) ;
if ( F_22 ( V_4 , V_7 , V_9 [ V_62 ] ) < 0 ) {
F_26 ( L_11 , V_2 -> V_52 -> V_53 ) ;
return - V_14 ;
}
}
if ( V_43 -> V_46 ) {
V_7 = F_2 ( V_47 ) ;
V_9 [ 0 ] = V_2 -> V_16 [ V_47 ] | V_50 ;
if ( F_22 ( V_4 , V_7 , V_9 [ 0 ] ) < 0 )
F_23 ( V_51 L_12 ,
V_2 -> V_52 -> V_53 ) ;
V_2 -> V_16 [ V_47 ] = V_9 [ 0 ] ;
}
return 0 ;
}
static int F_27 ( struct V_45 * V_13 , struct V_63 * V_64 )
{
int V_65 , V_37 , V_38 ;
V_65 = F_17 ( F_19 ( V_13 ) , & V_37 , & V_38 ) ;
if ( V_65 == 0 ) {
F_28 ( V_64 , L_13 ,
V_37 / 1000 , V_37 % 1000 ) ;
F_28 ( V_64 , L_14 , V_38 ) ;
}
return 0 ;
}
static T_2 F_29 ( struct V_45 * V_13 ,
struct V_66 * V_67 , char * V_9 )
{
int V_65 , V_38 ;
V_65 = F_17 ( F_19 ( V_13 ) , NULL , & V_38 ) ;
if ( V_65 )
return V_65 ;
return sprintf ( V_9 , L_15 , V_38 ) ;
}
static T_2 F_30 ( struct V_45 * V_13 ,
struct V_66 * V_67 , char * V_9 )
{
int V_65 , V_37 ;
V_65 = F_17 ( F_19 ( V_13 ) , & V_37 , NULL ) ;
if ( V_65 )
return V_65 ;
return sprintf ( V_9 , L_16 , V_37 / 1000 , V_37 % 1000 ) ;
}
static int F_31 ( struct V_45 * V_13 )
{
int V_65 ;
V_65 = F_32 ( V_13 , & V_68 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_32 ( V_13 , & V_69 ) ;
if ( V_65 )
F_33 ( V_13 , & V_68 ) ;
return V_65 ;
}
static void F_34 ( struct V_45 * V_13 )
{
F_33 ( V_13 , & V_68 ) ;
F_33 ( V_13 , & V_69 ) ;
}
static int F_31 ( struct V_45 * V_13 )
{
return 0 ;
}
static void F_34 ( struct V_45 * V_13 )
{
}
static int F_35 ( struct V_1 * V_1 )
{
unsigned char V_9 [ 2 ] ;
int V_7 , V_62 , V_70 = 0 ;
if ( V_1 -> type == V_71 ) {
if ( ! ( V_1 -> V_16 [ V_60 ] & V_72 ) )
return V_70 ;
V_1 -> V_16 [ V_60 ] &= ~ V_72 ;
} else {
if ( ! ( V_1 -> V_16 [ V_60 ] & V_73 ) )
return V_70 ;
V_1 -> V_16 [ V_60 ] &= ~ V_73 ;
}
V_7 = F_2 ( V_47 ) ;
V_9 [ 0 ] = V_1 -> V_16 [ V_47 ] ;
V_9 [ 1 ] = V_1 -> V_16 [ V_60 ] ;
switch ( V_1 -> type ) {
case V_74 :
case V_75 :
V_9 [ 1 ] |= V_76 ;
V_1 -> V_19 = 1 ;
break;
case V_71 :
case V_77 :
case V_78 :
V_9 [ 0 ] |= V_79 ;
V_1 -> V_19 = 1 ;
break;
default:
break;
}
for ( V_62 = 0 ; V_62 < sizeof( V_9 ) ; V_62 ++ ) {
V_7 = F_2 ( V_47 + V_62 ) ;
V_70 = F_22 ( V_1 -> V_4 , V_7 , V_9 [ V_62 ] ) ;
if ( F_36 ( V_70 < 0 ) )
return V_70 ;
}
V_1 -> V_16 [ V_47 ] = V_9 [ 0 ] ;
V_1 -> V_16 [ V_60 ] = V_9 [ 1 ] ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
const struct V_80 * V_81 )
{
int V_65 = 0 ;
int V_82 = 0 ;
struct V_1 * V_1 ;
struct V_20 V_21 ;
F_6 ( & V_4 -> V_13 , L_17 , V_36 ) ;
if ( ! F_38 ( V_4 -> V_15 , V_83 |
V_84 | V_85 ) ) {
if ( F_38 ( V_4 -> V_15 ,
V_84 |
V_85 ) )
V_82 = 1 ;
else {
V_65 = - V_86 ;
goto exit;
}
}
if ( ! ( V_1 = F_39 ( sizeof( struct V_1 ) , V_87 ) ) ) {
V_65 = - V_88 ;
goto exit;
}
V_1 -> V_4 = V_4 ;
F_40 ( V_4 , V_1 ) ;
V_1 -> type = V_81 -> V_89 ;
V_1 -> V_16 = & V_1 -> V_9 [ 1 ] ;
V_1 -> V_10 = V_82 ;
V_65 = F_1 ( V_1 ) ;
if ( V_65 < 0 )
goto V_90;
switch ( V_1 -> type ) {
case V_74 :
case V_75 :
if ( V_1 -> V_16 [ V_60 ] & V_76 )
V_1 -> V_19 = 1 ;
break;
case V_71 :
case V_77 :
case V_78 :
if ( V_1 -> V_16 [ V_47 ] & V_79 )
V_1 -> V_19 = 1 ;
break;
default:
F_16 ( & V_4 -> V_13 , L_18 ) ;
goto V_90;
}
V_65 = F_35 ( V_1 ) ;
if ( F_36 ( V_65 < 0 ) ) {
F_16 ( & V_4 -> V_13 , L_19 ) ;
goto V_90;
}
if ( F_11 ( V_4 , & V_21 ) < 0 )
F_4 ( & V_4 -> V_13 , L_20 ) ;
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
V_1 -> V_52 = F_42 ( V_91 . V_92 . V_53 ,
& V_4 -> V_13 , & V_93 , V_94 ) ;
if ( F_43 ( V_1 -> V_52 ) ) {
V_65 = F_44 ( V_1 -> V_52 ) ;
goto V_90;
}
V_65 = F_31 ( & V_4 -> V_13 ) ;
if ( V_65 )
goto V_95;
return 0 ;
V_95:
F_45 ( V_1 -> V_52 ) ;
V_90:
F_46 ( V_1 ) ;
exit:
return V_65 ;
}
static int F_47 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_12 ( V_4 ) ;
F_45 ( V_1 -> V_52 ) ;
F_34 ( & V_4 -> V_13 ) ;
F_46 ( V_1 ) ;
return 0 ;
}
static T_3 int F_48 ( void )
{
return F_49 ( & V_91 ) ;
}
static T_4 void F_50 ( void )
{
F_51 ( & V_91 ) ;
}

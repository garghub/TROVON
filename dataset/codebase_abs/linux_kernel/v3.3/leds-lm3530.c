static int F_1 ( const char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( F_3 ( V_1 , V_3 [ V_2 ] . V_4 ) )
return V_3 [ V_2 ] . V_5 ;
return - 1 ;
}
static int F_4 ( struct V_6 * V_7 )
{
int V_8 = 0 ;
int V_2 ;
T_1 V_9 ;
T_1 V_10 = 0 ;
T_1 V_11 ;
T_1 V_12 = 0 ;
T_1 V_13 ;
T_1 V_14 [ V_15 ] ;
T_1 V_16 [ V_17 ] ;
T_2 V_18 , V_19 , V_20 ;
struct V_21 * V_22 = V_7 -> V_23 ;
struct V_24 * V_25 = V_7 -> V_25 ;
V_9 = ( V_22 -> V_26 << V_27 ) |
( ( V_22 -> V_28 & 7 ) << V_29 ) ;
if ( V_7 -> V_4 == V_30 ||
V_7 -> V_4 == V_31 )
V_9 |= ( V_32 ) ;
if ( V_7 -> V_4 == V_31 ) {
if ( V_22 -> V_19 == 0 ) {
V_22 -> V_18 = 0 ;
V_22 -> V_19 = V_33 ;
}
V_18 = V_22 -> V_18 ;
V_19 = V_22 -> V_19 ;
if ( ( V_19 - V_18 ) > V_33 )
V_22 -> V_19 = V_19 =
V_18 + V_33 ;
V_20 = ( V_19 - V_18 ) / ( V_17 + 1 ) ;
for ( V_2 = 0 ; V_2 < V_17 ; V_2 ++ )
V_16 [ V_2 ] = ( ( ( V_18 + V_34 ) +
V_20 + ( V_2 * V_20 ) ) * V_35 )
/ 1000 ;
V_10 =
( V_22 -> V_36 << V_37 ) |
( V_38 ) |
( V_22 -> V_39 << V_40 ) ;
V_12 =
( V_22 -> V_41 << V_42 ) |
( V_22 -> V_43 << V_44 ) ;
}
if ( V_7 -> V_4 == V_45 )
V_9 |= ( V_46 ) |
( V_22 -> V_47 << V_48 ) |
( V_49 ) ;
V_11 = ( V_22 -> V_50 << V_51 ) |
( V_22 -> V_52 << V_53 ) ;
if ( V_7 -> V_13 )
V_13 = V_7 -> V_13 ;
else
V_13 = V_7 -> V_13 = V_22 -> V_54 ;
V_14 [ 0 ] = V_9 ;
V_14 [ 1 ] = V_10 ;
V_14 [ 2 ] = V_11 ;
V_14 [ 3 ] = 0x00 ;
V_14 [ 4 ] = V_12 ;
V_14 [ 5 ] = V_13 ;
V_14 [ 6 ] = V_16 [ 0 ] ;
V_14 [ 7 ] = V_16 [ 1 ] ;
V_14 [ 8 ] = V_16 [ 2 ] ;
V_14 [ 9 ] = V_16 [ 3 ] ;
V_14 [ 10 ] = V_55 ;
V_14 [ 11 ] = V_56 ;
V_14 [ 12 ] = V_57 ;
V_14 [ 13 ] = V_58 ;
V_14 [ 14 ] = V_59 ;
if ( ! V_7 -> V_60 ) {
V_8 = F_5 ( V_7 -> V_61 ) ;
if ( V_8 ) {
F_6 ( & V_7 -> V_25 -> V_62 ,
L_1 ) ;
return V_8 ;
}
V_7 -> V_60 = true ;
}
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ ) {
V_8 = F_7 ( V_25 ,
V_63 [ V_2 ] , V_14 [ V_2 ] ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static void F_8 ( struct V_64 * V_65 ,
enum V_66 V_54 )
{
int V_67 ;
struct V_6 * V_7 =
F_9 ( V_65 , struct V_6 , V_68 ) ;
switch ( V_7 -> V_4 ) {
case V_30 :
if ( ! V_7 -> V_60 ) {
V_67 = F_4 ( V_7 ) ;
if ( V_67 ) {
F_6 ( & V_7 -> V_25 -> V_62 ,
L_2 , V_67 ) ;
break;
}
}
V_67 = F_7 ( V_7 -> V_25 ,
V_69 , V_54 / 2 ) ;
if ( V_67 )
F_6 ( & V_7 -> V_25 -> V_62 ,
L_3 , V_67 ) ;
else
V_7 -> V_13 = V_54 / 2 ;
if ( V_54 == 0 ) {
V_67 = F_10 ( V_7 -> V_61 ) ;
if ( V_67 )
F_6 ( & V_7 -> V_25 -> V_62 ,
L_4 ) ;
V_7 -> V_60 = false ;
}
break;
case V_31 :
break;
case V_45 :
break;
default:
break;
}
}
static T_3 F_11 ( struct V_70 * V_62 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_24 * V_25 = F_9 (
V_62 -> V_74 , struct V_24 , V_62 ) ;
struct V_6 * V_7 = F_12 ( V_25 ) ;
int V_2 , V_75 = 0 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_7 -> V_4 == V_3 [ V_2 ] . V_5 )
V_75 += sprintf ( V_73 + V_75 , L_5 , V_3 [ V_2 ] . V_4 ) ;
else
V_75 += sprintf ( V_73 + V_75 , L_6 , V_3 [ V_2 ] . V_4 ) ;
V_75 += sprintf ( V_73 + V_75 , L_7 ) ;
return V_75 ;
}
static T_3 F_13 ( struct V_70 * V_62 , struct V_71
* V_72 , const char * V_73 , T_4 V_76 )
{
int V_67 ;
struct V_24 * V_25 = F_9 (
V_62 -> V_74 , struct V_24 , V_62 ) ;
struct V_6 * V_7 = F_12 ( V_25 ) ;
int V_4 ;
V_4 = F_1 ( V_73 ) ;
if ( V_4 < 0 ) {
F_6 ( V_62 , L_8 ) ;
return - V_77 ;
}
if ( V_4 == V_30 )
V_7 -> V_4 = V_30 ;
else if ( V_4 == V_31 )
V_7 -> V_4 = V_31 ;
else if ( V_4 == V_45 ) {
F_6 ( V_62 , L_9 ) ;
return - V_77 ;
}
V_67 = F_4 ( V_7 ) ;
if ( V_67 ) {
F_6 ( V_62 , L_10 , V_73 , V_67 ) ;
return V_67 ;
}
return sizeof( V_7 -> V_4 ) ;
}
static int T_5 F_14 ( struct V_24 * V_25 ,
const struct V_78 * V_79 )
{
struct V_21 * V_23 = V_25 -> V_62 . V_80 ;
struct V_6 * V_7 ;
int V_67 = 0 ;
if ( V_23 == NULL ) {
F_6 ( & V_25 -> V_62 , L_11 ) ;
V_67 = - V_81 ;
goto V_82;
}
if ( V_23 -> V_4 > V_45 ) {
F_6 ( & V_25 -> V_62 , L_12 ) ;
V_67 = - V_77 ;
goto V_82;
}
if ( ! F_15 ( V_25 -> V_83 , V_84 ) ) {
F_6 ( & V_25 -> V_62 , L_13 ) ;
V_67 = - V_85 ;
goto V_82;
}
V_7 = F_16 ( sizeof( struct V_6 ) , V_86 ) ;
if ( V_7 == NULL ) {
V_67 = - V_87 ;
goto V_82;
}
V_7 -> V_4 = V_23 -> V_4 ;
V_7 -> V_25 = V_25 ;
V_7 -> V_23 = V_23 ;
V_7 -> V_13 = V_88 ;
V_7 -> V_60 = false ;
V_7 -> V_68 . V_89 = V_90 ;
V_7 -> V_68 . V_91 = F_8 ;
F_17 ( V_25 , V_7 ) ;
V_7 -> V_61 = F_18 ( & V_25 -> V_62 , L_14 ) ;
if ( F_19 ( V_7 -> V_61 ) ) {
F_6 ( & V_25 -> V_62 , L_15 ) ;
V_67 = F_20 ( V_7 -> V_61 ) ;
V_7 -> V_61 = NULL ;
goto V_92;
}
if ( V_7 -> V_23 -> V_54 ) {
V_67 = F_4 ( V_7 ) ;
if ( V_67 < 0 ) {
F_6 ( & V_25 -> V_62 ,
L_2 , V_67 ) ;
V_67 = - V_81 ;
goto V_93;
}
}
V_67 = F_21 ( & V_25 -> V_62 , & V_7 -> V_68 ) ;
if ( V_67 < 0 ) {
F_6 ( & V_25 -> V_62 , L_16 , V_67 ) ;
V_67 = - V_81 ;
goto V_94;
}
V_67 = F_22 ( V_7 -> V_68 . V_62 , & V_95 ) ;
if ( V_67 < 0 ) {
F_6 ( & V_25 -> V_62 , L_17 , V_67 ) ;
V_67 = - V_81 ;
goto V_96;
}
return 0 ;
V_96:
F_23 ( & V_7 -> V_68 ) ;
V_94:
V_93:
F_24 ( V_7 -> V_61 ) ;
V_92:
F_25 ( V_7 ) ;
V_82:
return V_67 ;
}
static int T_6 F_26 ( struct V_24 * V_25 )
{
struct V_6 * V_7 = F_12 ( V_25 ) ;
F_27 ( V_7 -> V_68 . V_62 , & V_95 ) ;
if ( V_7 -> V_60 )
F_10 ( V_7 -> V_61 ) ;
F_24 ( V_7 -> V_61 ) ;
F_23 ( & V_7 -> V_68 ) ;
F_25 ( V_7 ) ;
return 0 ;
}

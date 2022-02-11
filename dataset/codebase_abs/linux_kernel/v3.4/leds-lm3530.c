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
struct V_21 * V_22 = V_7 -> V_22 ;
struct V_23 * V_24 = V_7 -> V_24 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
V_9 = ( V_22 -> V_28 << V_29 ) |
( ( V_22 -> V_30 & 7 ) << V_31 ) ;
switch ( V_7 -> V_4 ) {
case V_32 :
case V_33 :
V_9 |= V_34 ;
break;
case V_35 :
V_9 |= V_36 | V_37 |
( V_22 -> V_38 << V_39 ) ;
break;
}
if ( V_7 -> V_4 == V_33 ) {
if ( V_22 -> V_19 == 0 ) {
V_22 -> V_18 = 0 ;
V_22 -> V_19 = V_40 ;
}
V_18 = V_22 -> V_18 ;
V_19 = V_22 -> V_19 ;
if ( ( V_19 - V_18 ) > V_40 )
V_22 -> V_19 = V_19 =
V_18 + V_40 ;
V_20 = ( V_19 - V_18 ) / ( V_17 + 1 ) ;
for ( V_2 = 0 ; V_2 < V_17 ; V_2 ++ )
V_16 [ V_2 ] = ( ( ( V_18 + V_41 ) +
V_20 + ( V_2 * V_20 ) ) * V_42 )
/ 1000 ;
V_10 =
( V_22 -> V_43 << V_44 ) |
( V_45 ) |
( V_22 -> V_46 << V_47 ) ;
V_12 =
( V_22 -> V_48 << V_49 ) |
( V_22 -> V_50 << V_51 ) ;
}
V_11 = ( V_22 -> V_52 << V_53 ) |
( V_22 -> V_54 << V_55 ) ;
if ( V_7 -> V_13 )
V_13 = V_7 -> V_13 ;
else
V_13 = V_7 -> V_13 = V_22 -> V_56 ;
if ( V_13 > V_7 -> V_57 . V_58 )
V_13 = V_7 -> V_57 . V_58 ;
V_14 [ 0 ] = V_9 ;
V_14 [ 1 ] = V_10 ;
V_14 [ 2 ] = V_11 ;
V_14 [ 3 ] = V_12 ;
V_14 [ 4 ] = V_13 ;
V_14 [ 5 ] = V_16 [ 0 ] ;
V_14 [ 6 ] = V_16 [ 1 ] ;
V_14 [ 7 ] = V_16 [ 2 ] ;
V_14 [ 8 ] = V_16 [ 3 ] ;
V_14 [ 9 ] = V_59 ;
V_14 [ 10 ] = V_60 ;
V_14 [ 11 ] = V_61 ;
V_14 [ 12 ] = V_62 ;
V_14 [ 13 ] = V_63 ;
if ( ! V_7 -> V_64 ) {
V_8 = F_5 ( V_7 -> V_65 ) ;
if ( V_8 ) {
F_6 ( & V_7 -> V_24 -> V_66 ,
L_1 ) ;
return V_8 ;
}
V_7 -> V_64 = true ;
}
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ ) {
if ( V_67 [ V_2 ] == V_68 &&
V_7 -> V_4 == V_35 ) {
if ( V_26 -> V_69 )
V_26 -> V_69 ( V_14 [ V_2 ] ,
V_7 -> V_57 . V_58 ) ;
continue;
}
V_8 = F_7 ( V_24 ,
V_67 [ V_2 ] , V_14 [ V_2 ] ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static void F_8 ( struct V_70 * V_71 ,
enum V_72 V_56 )
{
int V_73 ;
struct V_6 * V_7 =
F_9 ( V_71 , struct V_6 , V_57 ) ;
struct V_21 * V_22 = V_7 -> V_22 ;
struct V_25 * V_26 = & V_22 -> V_27 ;
T_1 V_58 = V_71 -> V_58 ;
switch ( V_7 -> V_4 ) {
case V_32 :
if ( ! V_7 -> V_64 ) {
V_73 = F_4 ( V_7 ) ;
if ( V_73 ) {
F_6 ( & V_7 -> V_24 -> V_66 ,
L_2 , V_73 ) ;
break;
}
}
V_73 = F_7 ( V_7 -> V_24 ,
V_68 , V_56 ) ;
if ( V_73 )
F_6 ( & V_7 -> V_24 -> V_66 ,
L_3 , V_73 ) ;
else
V_7 -> V_13 = V_56 ;
if ( V_56 == 0 ) {
V_73 = F_10 ( V_7 -> V_65 ) ;
if ( V_73 )
F_6 ( & V_7 -> V_24 -> V_66 ,
L_4 ) ;
V_7 -> V_64 = false ;
}
break;
case V_33 :
break;
case V_35 :
if ( V_26 -> V_69 )
V_26 -> V_69 ( V_56 , V_58 ) ;
break;
default:
break;
}
}
static T_3 F_11 ( struct V_74 * V_66 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_70 * V_71 = F_12 ( V_66 ) ;
struct V_6 * V_7 ;
int V_2 , V_78 = 0 ;
V_7 = F_9 ( V_71 , struct V_6 , V_57 ) ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_7 -> V_4 == V_3 [ V_2 ] . V_5 )
V_78 += sprintf ( V_77 + V_78 , L_5 , V_3 [ V_2 ] . V_4 ) ;
else
V_78 += sprintf ( V_77 + V_78 , L_6 , V_3 [ V_2 ] . V_4 ) ;
V_78 += sprintf ( V_77 + V_78 , L_7 ) ;
return V_78 ;
}
static T_3 F_13 ( struct V_74 * V_66 , struct V_75
* V_76 , const char * V_77 , T_4 V_79 )
{
struct V_70 * V_71 = F_12 ( V_66 ) ;
struct V_6 * V_7 ;
struct V_25 * V_26 ;
T_1 V_58 ;
int V_4 , V_73 ;
V_7 = F_9 ( V_71 , struct V_6 , V_57 ) ;
V_26 = & V_7 -> V_22 -> V_27 ;
V_58 = V_71 -> V_58 ;
V_4 = F_1 ( V_77 ) ;
if ( V_4 < 0 ) {
F_6 ( V_66 , L_8 ) ;
return - V_80 ;
}
V_7 -> V_4 = V_4 ;
if ( V_4 != V_35 && V_26 -> V_69 )
V_26 -> V_69 ( 0 , V_58 ) ;
V_73 = F_4 ( V_7 ) ;
if ( V_73 ) {
F_6 ( V_66 , L_9 , V_77 , V_73 ) ;
return V_73 ;
}
return sizeof( V_7 -> V_4 ) ;
}
static int T_5 F_14 ( struct V_23 * V_24 ,
const struct V_81 * V_82 )
{
struct V_21 * V_22 = V_24 -> V_66 . V_83 ;
struct V_6 * V_7 ;
int V_73 = 0 ;
if ( V_22 == NULL ) {
F_6 ( & V_24 -> V_66 , L_10 ) ;
V_73 = - V_84 ;
goto V_85;
}
if ( V_22 -> V_4 > V_35 ) {
F_6 ( & V_24 -> V_66 , L_11 ) ;
V_73 = - V_80 ;
goto V_85;
}
if ( ! F_15 ( V_24 -> V_86 , V_87 ) ) {
F_6 ( & V_24 -> V_66 , L_12 ) ;
V_73 = - V_88 ;
goto V_85;
}
V_7 = F_16 ( sizeof( struct V_6 ) , V_89 ) ;
if ( V_7 == NULL ) {
V_73 = - V_90 ;
goto V_85;
}
V_7 -> V_4 = V_22 -> V_4 ;
V_7 -> V_24 = V_24 ;
V_7 -> V_22 = V_22 ;
V_7 -> V_13 = V_91 ;
V_7 -> V_64 = false ;
V_7 -> V_57 . V_92 = V_93 ;
V_7 -> V_57 . V_94 = F_8 ;
V_7 -> V_57 . V_58 = V_95 ;
F_17 ( V_24 , V_7 ) ;
V_7 -> V_65 = F_18 ( & V_24 -> V_66 , L_13 ) ;
if ( F_19 ( V_7 -> V_65 ) ) {
F_6 ( & V_24 -> V_66 , L_14 ) ;
V_73 = F_20 ( V_7 -> V_65 ) ;
V_7 -> V_65 = NULL ;
goto V_96;
}
if ( V_7 -> V_22 -> V_56 ) {
V_73 = F_4 ( V_7 ) ;
if ( V_73 < 0 ) {
F_6 ( & V_24 -> V_66 ,
L_2 , V_73 ) ;
V_73 = - V_84 ;
goto V_97;
}
}
V_73 = F_21 ( & V_24 -> V_66 , & V_7 -> V_57 ) ;
if ( V_73 < 0 ) {
F_6 ( & V_24 -> V_66 , L_15 , V_73 ) ;
V_73 = - V_84 ;
goto V_98;
}
V_73 = F_22 ( V_7 -> V_57 . V_66 , & V_99 ) ;
if ( V_73 < 0 ) {
F_6 ( & V_24 -> V_66 , L_16 , V_73 ) ;
V_73 = - V_84 ;
goto V_100;
}
return 0 ;
V_100:
F_23 ( & V_7 -> V_57 ) ;
V_98:
V_97:
F_24 ( V_7 -> V_65 ) ;
V_96:
F_25 ( V_7 ) ;
V_85:
return V_73 ;
}
static int T_6 F_26 ( struct V_23 * V_24 )
{
struct V_6 * V_7 = F_27 ( V_24 ) ;
F_28 ( V_7 -> V_57 . V_66 , & V_99 ) ;
if ( V_7 -> V_64 )
F_10 ( V_7 -> V_65 ) ;
F_24 ( V_7 -> V_65 ) ;
F_23 ( & V_7 -> V_57 ) ;
F_25 ( V_7 ) ;
return 0 ;
}

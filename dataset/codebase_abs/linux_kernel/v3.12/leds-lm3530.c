static int F_1 ( const char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( F_3 ( V_1 , V_3 [ V_2 ] . V_4 ) )
return V_3 [ V_2 ] . V_5 ;
return - V_6 ;
}
static void F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_2 ;
T_1 V_11 , V_12 , V_13 ;
if ( V_8 -> V_12 == 0 ) {
V_8 -> V_11 = 0 ;
V_8 -> V_12 = V_14 ;
}
V_11 = V_8 -> V_11 ;
V_12 = V_8 -> V_12 ;
if ( ( V_12 - V_11 ) > V_14 )
V_8 -> V_12 = V_12 = V_11 + V_14 ;
V_13 = ( V_12 - V_11 ) / ( V_15 + 1 ) ;
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ )
V_10 -> V_16 [ V_2 ] = ( ( ( V_11 + V_17 ) +
V_13 + ( V_2 * V_13 ) ) * V_18 ) / 1000 ;
V_10 -> V_19 =
( V_8 -> V_20 << V_21 ) |
( V_22 ) |
( V_8 -> V_23 << V_24 ) ;
V_10 -> V_25 =
( V_8 -> V_26 << V_27 ) |
( V_8 -> V_28 << V_29 ) ;
}
static int F_5 ( struct V_30 * V_31 )
{
int V_32 ;
if ( V_31 -> V_33 )
return 0 ;
V_32 = F_6 ( V_31 -> V_34 ) ;
if ( V_32 ) {
F_7 ( V_31 -> V_35 . V_36 , L_1 , V_32 ) ;
return V_32 ;
}
V_31 -> V_33 = true ;
return 0 ;
}
static void F_8 ( struct V_30 * V_31 )
{
int V_32 ;
if ( ! V_31 -> V_33 )
return;
V_32 = F_9 ( V_31 -> V_34 ) ;
if ( V_32 ) {
F_7 ( V_31 -> V_35 . V_36 , L_2 ,
V_32 ) ;
return;
}
V_31 -> V_33 = false ;
}
static int F_10 ( struct V_30 * V_31 )
{
int V_32 = 0 ;
int V_2 ;
T_2 V_37 ;
T_2 V_38 ;
T_2 V_39 ;
T_2 V_40 [ V_41 ] ;
struct V_7 * V_8 = V_31 -> V_8 ;
struct V_42 * V_43 = V_31 -> V_43 ;
struct V_44 * V_45 = & V_8 -> V_46 ;
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( struct V_9 ) ) ;
V_37 = ( V_8 -> V_47 << V_48 ) |
( ( V_8 -> V_49 & 7 ) << V_50 ) ;
switch ( V_31 -> V_4 ) {
case V_51 :
V_37 |= V_52 ;
break;
case V_53 :
V_37 |= V_52 ;
F_4 ( V_8 , & V_10 ) ;
break;
case V_54 :
V_37 |= V_55 | V_56 |
( V_8 -> V_57 << V_58 ) ;
break;
}
V_38 = ( V_8 -> V_59 << V_60 ) |
( V_8 -> V_61 << V_62 ) ;
if ( V_31 -> V_39 )
V_39 = V_31 -> V_39 ;
else
V_39 = V_31 -> V_39 = V_8 -> V_63 ;
if ( V_39 > V_31 -> V_35 . V_64 )
V_39 = V_31 -> V_35 . V_64 ;
V_40 [ 0 ] = V_37 ;
V_40 [ 1 ] = V_10 . V_19 ;
V_40 [ 2 ] = V_38 ;
V_40 [ 3 ] = V_10 . V_25 ;
V_40 [ 4 ] = V_39 ;
V_40 [ 5 ] = V_10 . V_16 [ 0 ] ;
V_40 [ 6 ] = V_10 . V_16 [ 1 ] ;
V_40 [ 7 ] = V_10 . V_16 [ 2 ] ;
V_40 [ 8 ] = V_10 . V_16 [ 3 ] ;
V_40 [ 9 ] = V_65 ;
V_40 [ 10 ] = V_66 ;
V_40 [ 11 ] = V_67 ;
V_40 [ 12 ] = V_68 ;
V_40 [ 13 ] = V_69 ;
V_32 = F_5 ( V_31 ) ;
if ( V_32 )
return V_32 ;
for ( V_2 = 0 ; V_2 < V_41 ; V_2 ++ ) {
if ( V_70 [ V_2 ] == V_71 &&
V_31 -> V_4 == V_54 ) {
if ( V_45 -> V_72 )
V_45 -> V_72 ( V_40 [ V_2 ] ,
V_31 -> V_35 . V_64 ) ;
continue;
}
V_32 = F_11 ( V_43 ,
V_70 [ V_2 ] , V_40 [ V_2 ] ) ;
if ( V_32 )
break;
}
return V_32 ;
}
static void F_12 ( struct V_73 * V_74 ,
enum V_75 V_63 )
{
int V_76 ;
struct V_30 * V_31 =
F_13 ( V_74 , struct V_30 , V_35 ) ;
struct V_7 * V_8 = V_31 -> V_8 ;
struct V_44 * V_45 = & V_8 -> V_46 ;
T_2 V_64 = V_74 -> V_64 ;
switch ( V_31 -> V_4 ) {
case V_51 :
if ( ! V_31 -> V_33 ) {
V_76 = F_10 ( V_31 ) ;
if ( V_76 ) {
F_7 ( & V_31 -> V_43 -> V_36 ,
L_3 , V_76 ) ;
break;
}
}
V_76 = F_11 ( V_31 -> V_43 ,
V_71 , V_63 ) ;
if ( V_76 )
F_7 ( & V_31 -> V_43 -> V_36 ,
L_4 , V_76 ) ;
else
V_31 -> V_39 = V_63 ;
if ( V_63 == 0 )
F_8 ( V_31 ) ;
break;
case V_53 :
break;
case V_54 :
if ( V_45 -> V_72 )
V_45 -> V_72 ( V_63 , V_64 ) ;
break;
default:
break;
}
}
static T_3 F_14 ( struct V_77 * V_36 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_73 * V_74 = F_15 ( V_36 ) ;
struct V_30 * V_31 ;
int V_2 , V_81 = 0 ;
V_31 = F_13 ( V_74 , struct V_30 , V_35 ) ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_31 -> V_4 == V_3 [ V_2 ] . V_5 )
V_81 += sprintf ( V_80 + V_81 , L_5 , V_3 [ V_2 ] . V_4 ) ;
else
V_81 += sprintf ( V_80 + V_81 , L_6 , V_3 [ V_2 ] . V_4 ) ;
V_81 += sprintf ( V_80 + V_81 , L_7 ) ;
return V_81 ;
}
static T_3 F_16 ( struct V_77 * V_36 , struct V_78
* V_79 , const char * V_80 , T_4 V_82 )
{
struct V_73 * V_74 = F_15 ( V_36 ) ;
struct V_30 * V_31 ;
struct V_44 * V_45 ;
T_2 V_64 ;
int V_4 , V_76 ;
V_31 = F_13 ( V_74 , struct V_30 , V_35 ) ;
V_45 = & V_31 -> V_8 -> V_46 ;
V_64 = V_74 -> V_64 ;
V_4 = F_1 ( V_80 ) ;
if ( V_4 < 0 ) {
F_7 ( V_36 , L_8 ) ;
return V_4 ;
}
V_31 -> V_4 = V_4 ;
if ( V_4 != V_54 && V_45 -> V_72 )
V_45 -> V_72 ( 0 , V_64 ) ;
V_76 = F_10 ( V_31 ) ;
if ( V_76 ) {
F_7 ( V_36 , L_9 , V_80 , V_76 ) ;
return V_76 ;
}
return sizeof( V_31 -> V_4 ) ;
}
static int F_17 ( struct V_42 * V_43 ,
const struct V_83 * V_84 )
{
struct V_7 * V_8 = F_18 ( & V_43 -> V_36 ) ;
struct V_30 * V_31 ;
int V_76 = 0 ;
if ( V_8 == NULL ) {
F_7 ( & V_43 -> V_36 , L_10 ) ;
return - V_85 ;
}
if ( V_8 -> V_4 > V_54 ) {
F_7 ( & V_43 -> V_36 , L_11 ) ;
return - V_6 ;
}
if ( ! F_19 ( V_43 -> V_86 , V_87 ) ) {
F_7 ( & V_43 -> V_36 , L_12 ) ;
return - V_88 ;
}
V_31 = F_20 ( & V_43 -> V_36 , sizeof( struct V_30 ) ,
V_89 ) ;
if ( V_31 == NULL )
return - V_90 ;
V_31 -> V_4 = V_8 -> V_4 ;
V_31 -> V_43 = V_43 ;
V_31 -> V_8 = V_8 ;
V_31 -> V_39 = V_91 ;
V_31 -> V_33 = false ;
V_31 -> V_35 . V_92 = V_93 ;
V_31 -> V_35 . V_94 = F_12 ;
V_31 -> V_35 . V_64 = V_95 ;
F_21 ( V_43 , V_31 ) ;
V_31 -> V_34 = F_22 ( & V_43 -> V_36 , L_13 ) ;
if ( F_23 ( V_31 -> V_34 ) ) {
F_7 ( & V_43 -> V_36 , L_14 ) ;
V_76 = F_24 ( V_31 -> V_34 ) ;
V_31 -> V_34 = NULL ;
return V_76 ;
}
if ( V_31 -> V_8 -> V_63 ) {
V_76 = F_10 ( V_31 ) ;
if ( V_76 < 0 ) {
F_7 ( & V_43 -> V_36 ,
L_3 , V_76 ) ;
return V_76 ;
}
}
V_76 = F_25 ( & V_43 -> V_36 , & V_31 -> V_35 ) ;
if ( V_76 < 0 ) {
F_7 ( & V_43 -> V_36 , L_15 , V_76 ) ;
return V_76 ;
}
V_76 = F_26 ( V_31 -> V_35 . V_36 , & V_96 ) ;
if ( V_76 < 0 ) {
F_7 ( & V_43 -> V_36 , L_16 , V_76 ) ;
V_76 = - V_85 ;
goto V_97;
}
return 0 ;
V_97:
F_27 ( & V_31 -> V_35 ) ;
return V_76 ;
}
static int F_28 ( struct V_42 * V_43 )
{
struct V_30 * V_31 = F_29 ( V_43 ) ;
F_30 ( V_31 -> V_35 . V_36 , & V_96 ) ;
F_8 ( V_31 ) ;
F_27 ( & V_31 -> V_35 ) ;
return 0 ;
}

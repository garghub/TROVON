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
int V_32 = 0 ;
int V_2 ;
T_2 V_33 ;
T_2 V_34 ;
T_2 V_35 ;
T_2 V_36 [ V_37 ] ;
struct V_7 * V_8 = V_31 -> V_8 ;
struct V_38 * V_39 = V_31 -> V_39 ;
struct V_40 * V_41 = & V_8 -> V_42 ;
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( struct V_9 ) ) ;
V_33 = ( V_8 -> V_43 << V_44 ) |
( ( V_8 -> V_45 & 7 ) << V_46 ) ;
switch ( V_31 -> V_4 ) {
case V_47 :
V_33 |= V_48 ;
break;
case V_49 :
V_33 |= V_48 ;
F_4 ( V_8 , & V_10 ) ;
break;
case V_50 :
V_33 |= V_51 | V_52 |
( V_8 -> V_53 << V_54 ) ;
break;
}
V_34 = ( V_8 -> V_55 << V_56 ) |
( V_8 -> V_57 << V_58 ) ;
if ( V_31 -> V_35 )
V_35 = V_31 -> V_35 ;
else
V_35 = V_31 -> V_35 = V_8 -> V_59 ;
if ( V_35 > V_31 -> V_60 . V_61 )
V_35 = V_31 -> V_60 . V_61 ;
V_36 [ 0 ] = V_33 ;
V_36 [ 1 ] = V_10 . V_19 ;
V_36 [ 2 ] = V_34 ;
V_36 [ 3 ] = V_10 . V_25 ;
V_36 [ 4 ] = V_35 ;
V_36 [ 5 ] = V_10 . V_16 [ 0 ] ;
V_36 [ 6 ] = V_10 . V_16 [ 1 ] ;
V_36 [ 7 ] = V_10 . V_16 [ 2 ] ;
V_36 [ 8 ] = V_10 . V_16 [ 3 ] ;
V_36 [ 9 ] = V_62 ;
V_36 [ 10 ] = V_63 ;
V_36 [ 11 ] = V_64 ;
V_36 [ 12 ] = V_65 ;
V_36 [ 13 ] = V_66 ;
if ( ! V_31 -> V_67 ) {
V_32 = F_6 ( V_31 -> V_68 ) ;
if ( V_32 ) {
F_7 ( & V_31 -> V_39 -> V_69 ,
L_1 ) ;
return V_32 ;
}
V_31 -> V_67 = true ;
}
for ( V_2 = 0 ; V_2 < V_37 ; V_2 ++ ) {
if ( V_70 [ V_2 ] == V_71 &&
V_31 -> V_4 == V_50 ) {
if ( V_41 -> V_72 )
V_41 -> V_72 ( V_36 [ V_2 ] ,
V_31 -> V_60 . V_61 ) ;
continue;
}
V_32 = F_8 ( V_39 ,
V_70 [ V_2 ] , V_36 [ V_2 ] ) ;
if ( V_32 )
break;
}
return V_32 ;
}
static void F_9 ( struct V_73 * V_74 ,
enum V_75 V_59 )
{
int V_76 ;
struct V_30 * V_31 =
F_10 ( V_74 , struct V_30 , V_60 ) ;
struct V_7 * V_8 = V_31 -> V_8 ;
struct V_40 * V_41 = & V_8 -> V_42 ;
T_2 V_61 = V_74 -> V_61 ;
switch ( V_31 -> V_4 ) {
case V_47 :
if ( ! V_31 -> V_67 ) {
V_76 = F_5 ( V_31 ) ;
if ( V_76 ) {
F_7 ( & V_31 -> V_39 -> V_69 ,
L_2 , V_76 ) ;
break;
}
}
V_76 = F_8 ( V_31 -> V_39 ,
V_71 , V_59 ) ;
if ( V_76 )
F_7 ( & V_31 -> V_39 -> V_69 ,
L_3 , V_76 ) ;
else
V_31 -> V_35 = V_59 ;
if ( V_59 == 0 ) {
V_76 = F_11 ( V_31 -> V_68 ) ;
if ( V_76 )
F_7 ( & V_31 -> V_39 -> V_69 ,
L_4 ) ;
V_31 -> V_67 = false ;
}
break;
case V_49 :
break;
case V_50 :
if ( V_41 -> V_72 )
V_41 -> V_72 ( V_59 , V_61 ) ;
break;
default:
break;
}
}
static T_3 F_12 ( struct V_77 * V_69 ,
struct V_78 * V_79 , char * V_80 )
{
struct V_73 * V_74 = F_13 ( V_69 ) ;
struct V_30 * V_31 ;
int V_2 , V_81 = 0 ;
V_31 = F_10 ( V_74 , struct V_30 , V_60 ) ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_31 -> V_4 == V_3 [ V_2 ] . V_5 )
V_81 += sprintf ( V_80 + V_81 , L_5 , V_3 [ V_2 ] . V_4 ) ;
else
V_81 += sprintf ( V_80 + V_81 , L_6 , V_3 [ V_2 ] . V_4 ) ;
V_81 += sprintf ( V_80 + V_81 , L_7 ) ;
return V_81 ;
}
static T_3 F_14 ( struct V_77 * V_69 , struct V_78
* V_79 , const char * V_80 , T_4 V_82 )
{
struct V_73 * V_74 = F_13 ( V_69 ) ;
struct V_30 * V_31 ;
struct V_40 * V_41 ;
T_2 V_61 ;
int V_4 , V_76 ;
V_31 = F_10 ( V_74 , struct V_30 , V_60 ) ;
V_41 = & V_31 -> V_8 -> V_42 ;
V_61 = V_74 -> V_61 ;
V_4 = F_1 ( V_80 ) ;
if ( V_4 < 0 ) {
F_7 ( V_69 , L_8 ) ;
return V_4 ;
}
V_31 -> V_4 = V_4 ;
if ( V_4 != V_50 && V_41 -> V_72 )
V_41 -> V_72 ( 0 , V_61 ) ;
V_76 = F_5 ( V_31 ) ;
if ( V_76 ) {
F_7 ( V_69 , L_9 , V_80 , V_76 ) ;
return V_76 ;
}
return sizeof( V_31 -> V_4 ) ;
}
static int T_5 F_15 ( struct V_38 * V_39 ,
const struct V_83 * V_84 )
{
struct V_7 * V_8 = V_39 -> V_69 . V_85 ;
struct V_30 * V_31 ;
int V_76 = 0 ;
if ( V_8 == NULL ) {
F_7 ( & V_39 -> V_69 , L_10 ) ;
return - V_86 ;
}
if ( V_8 -> V_4 > V_50 ) {
F_7 ( & V_39 -> V_69 , L_11 ) ;
return - V_6 ;
}
if ( ! F_16 ( V_39 -> V_87 , V_88 ) ) {
F_7 ( & V_39 -> V_69 , L_12 ) ;
return - V_89 ;
}
V_31 = F_17 ( & V_39 -> V_69 , sizeof( struct V_30 ) ,
V_90 ) ;
if ( V_31 == NULL )
return - V_91 ;
V_31 -> V_4 = V_8 -> V_4 ;
V_31 -> V_39 = V_39 ;
V_31 -> V_8 = V_8 ;
V_31 -> V_35 = V_92 ;
V_31 -> V_67 = false ;
V_31 -> V_60 . V_93 = V_94 ;
V_31 -> V_60 . V_95 = F_9 ;
V_31 -> V_60 . V_61 = V_96 ;
F_18 ( V_39 , V_31 ) ;
V_31 -> V_68 = F_19 ( & V_39 -> V_69 , L_13 ) ;
if ( F_20 ( V_31 -> V_68 ) ) {
F_7 ( & V_39 -> V_69 , L_14 ) ;
V_76 = F_21 ( V_31 -> V_68 ) ;
V_31 -> V_68 = NULL ;
return V_76 ;
}
if ( V_31 -> V_8 -> V_59 ) {
V_76 = F_5 ( V_31 ) ;
if ( V_76 < 0 ) {
F_7 ( & V_39 -> V_69 ,
L_2 , V_76 ) ;
return V_76 ;
}
}
V_76 = F_22 ( & V_39 -> V_69 , & V_31 -> V_60 ) ;
if ( V_76 < 0 ) {
F_7 ( & V_39 -> V_69 , L_15 , V_76 ) ;
return V_76 ;
}
V_76 = F_23 ( V_31 -> V_60 . V_69 , & V_97 ) ;
if ( V_76 < 0 ) {
F_7 ( & V_39 -> V_69 , L_16 , V_76 ) ;
V_76 = - V_86 ;
goto V_98;
}
return 0 ;
V_98:
F_24 ( & V_31 -> V_60 ) ;
return V_76 ;
}
static int T_6 F_25 ( struct V_38 * V_39 )
{
struct V_30 * V_31 = F_26 ( V_39 ) ;
F_27 ( V_31 -> V_60 . V_69 , & V_97 ) ;
if ( V_31 -> V_67 )
F_11 ( V_31 -> V_68 ) ;
F_24 ( & V_31 -> V_60 ) ;
return 0 ;
}

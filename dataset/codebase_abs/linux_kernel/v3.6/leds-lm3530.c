static int F_1 ( const char * V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( F_3 ( V_1 , V_3 [ V_2 ] . V_4 ) )
return V_3 [ V_2 ] . V_5 ;
return - 1 ;
}
static void F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
int V_2 ;
T_1 V_10 , V_11 , V_12 ;
if ( V_7 -> V_11 == 0 ) {
V_7 -> V_10 = 0 ;
V_7 -> V_11 = V_13 ;
}
V_10 = V_7 -> V_10 ;
V_11 = V_7 -> V_11 ;
if ( ( V_11 - V_10 ) > V_13 )
V_7 -> V_11 = V_11 = V_10 + V_13 ;
V_12 = ( V_11 - V_10 ) / ( V_14 + 1 ) ;
for ( V_2 = 0 ; V_2 < V_14 ; V_2 ++ )
V_9 -> V_15 [ V_2 ] = ( ( ( V_10 + V_16 ) +
V_12 + ( V_2 * V_12 ) ) * V_17 ) / 1000 ;
V_9 -> V_18 =
( V_7 -> V_19 << V_20 ) |
( V_21 ) |
( V_7 -> V_22 << V_23 ) ;
V_9 -> V_24 =
( V_7 -> V_25 << V_26 ) |
( V_7 -> V_27 << V_28 ) ;
}
static int F_5 ( struct V_29 * V_30 )
{
int V_31 = 0 ;
int V_2 ;
T_2 V_32 ;
T_2 V_33 ;
T_2 V_34 ;
T_2 V_35 [ V_36 ] ;
struct V_6 * V_7 = V_30 -> V_7 ;
struct V_37 * V_38 = V_30 -> V_38 ;
struct V_39 * V_40 = & V_7 -> V_41 ;
struct V_8 V_9 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
V_32 = ( V_7 -> V_42 << V_43 ) |
( ( V_7 -> V_44 & 7 ) << V_45 ) ;
switch ( V_30 -> V_4 ) {
case V_46 :
V_32 |= V_47 ;
break;
case V_48 :
V_32 |= V_47 ;
F_4 ( V_7 , & V_9 ) ;
break;
case V_49 :
V_32 |= V_50 | V_51 |
( V_7 -> V_52 << V_53 ) ;
break;
}
V_33 = ( V_7 -> V_54 << V_55 ) |
( V_7 -> V_56 << V_57 ) ;
if ( V_30 -> V_34 )
V_34 = V_30 -> V_34 ;
else
V_34 = V_30 -> V_34 = V_7 -> V_58 ;
if ( V_34 > V_30 -> V_59 . V_60 )
V_34 = V_30 -> V_59 . V_60 ;
V_35 [ 0 ] = V_32 ;
V_35 [ 1 ] = V_9 . V_18 ;
V_35 [ 2 ] = V_33 ;
V_35 [ 3 ] = V_9 . V_24 ;
V_35 [ 4 ] = V_34 ;
V_35 [ 5 ] = V_9 . V_15 [ 0 ] ;
V_35 [ 6 ] = V_9 . V_15 [ 1 ] ;
V_35 [ 7 ] = V_9 . V_15 [ 2 ] ;
V_35 [ 8 ] = V_9 . V_15 [ 3 ] ;
V_35 [ 9 ] = V_61 ;
V_35 [ 10 ] = V_62 ;
V_35 [ 11 ] = V_63 ;
V_35 [ 12 ] = V_64 ;
V_35 [ 13 ] = V_65 ;
if ( ! V_30 -> V_66 ) {
V_31 = F_6 ( V_30 -> V_67 ) ;
if ( V_31 ) {
F_7 ( & V_30 -> V_38 -> V_68 ,
L_1 ) ;
return V_31 ;
}
V_30 -> V_66 = true ;
}
for ( V_2 = 0 ; V_2 < V_36 ; V_2 ++ ) {
if ( V_69 [ V_2 ] == V_70 &&
V_30 -> V_4 == V_49 ) {
if ( V_40 -> V_71 )
V_40 -> V_71 ( V_35 [ V_2 ] ,
V_30 -> V_59 . V_60 ) ;
continue;
}
V_31 = F_8 ( V_38 ,
V_69 [ V_2 ] , V_35 [ V_2 ] ) ;
if ( V_31 )
break;
}
return V_31 ;
}
static void F_9 ( struct V_72 * V_73 ,
enum V_74 V_58 )
{
int V_75 ;
struct V_29 * V_30 =
F_10 ( V_73 , struct V_29 , V_59 ) ;
struct V_6 * V_7 = V_30 -> V_7 ;
struct V_39 * V_40 = & V_7 -> V_41 ;
T_2 V_60 = V_73 -> V_60 ;
switch ( V_30 -> V_4 ) {
case V_46 :
if ( ! V_30 -> V_66 ) {
V_75 = F_5 ( V_30 ) ;
if ( V_75 ) {
F_7 ( & V_30 -> V_38 -> V_68 ,
L_2 , V_75 ) ;
break;
}
}
V_75 = F_8 ( V_30 -> V_38 ,
V_70 , V_58 ) ;
if ( V_75 )
F_7 ( & V_30 -> V_38 -> V_68 ,
L_3 , V_75 ) ;
else
V_30 -> V_34 = V_58 ;
if ( V_58 == 0 ) {
V_75 = F_11 ( V_30 -> V_67 ) ;
if ( V_75 )
F_7 ( & V_30 -> V_38 -> V_68 ,
L_4 ) ;
V_30 -> V_66 = false ;
}
break;
case V_48 :
break;
case V_49 :
if ( V_40 -> V_71 )
V_40 -> V_71 ( V_58 , V_60 ) ;
break;
default:
break;
}
}
static T_3 F_12 ( struct V_76 * V_68 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_72 * V_73 = F_13 ( V_68 ) ;
struct V_29 * V_30 ;
int V_2 , V_80 = 0 ;
V_30 = F_10 ( V_73 , struct V_29 , V_59 ) ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_30 -> V_4 == V_3 [ V_2 ] . V_5 )
V_80 += sprintf ( V_79 + V_80 , L_5 , V_3 [ V_2 ] . V_4 ) ;
else
V_80 += sprintf ( V_79 + V_80 , L_6 , V_3 [ V_2 ] . V_4 ) ;
V_80 += sprintf ( V_79 + V_80 , L_7 ) ;
return V_80 ;
}
static T_3 F_14 ( struct V_76 * V_68 , struct V_77
* V_78 , const char * V_79 , T_4 V_81 )
{
struct V_72 * V_73 = F_13 ( V_68 ) ;
struct V_29 * V_30 ;
struct V_39 * V_40 ;
T_2 V_60 ;
int V_4 , V_75 ;
V_30 = F_10 ( V_73 , struct V_29 , V_59 ) ;
V_40 = & V_30 -> V_7 -> V_41 ;
V_60 = V_73 -> V_60 ;
V_4 = F_1 ( V_79 ) ;
if ( V_4 < 0 ) {
F_7 ( V_68 , L_8 ) ;
return - V_82 ;
}
V_30 -> V_4 = V_4 ;
if ( V_4 != V_49 && V_40 -> V_71 )
V_40 -> V_71 ( 0 , V_60 ) ;
V_75 = F_5 ( V_30 ) ;
if ( V_75 ) {
F_7 ( V_68 , L_9 , V_79 , V_75 ) ;
return V_75 ;
}
return sizeof( V_30 -> V_4 ) ;
}
static int T_5 F_15 ( struct V_37 * V_38 ,
const struct V_83 * V_84 )
{
struct V_6 * V_7 = V_38 -> V_68 . V_85 ;
struct V_29 * V_30 ;
int V_75 = 0 ;
if ( V_7 == NULL ) {
F_7 ( & V_38 -> V_68 , L_10 ) ;
return - V_86 ;
}
if ( V_7 -> V_4 > V_49 ) {
F_7 ( & V_38 -> V_68 , L_11 ) ;
return - V_82 ;
}
if ( ! F_16 ( V_38 -> V_87 , V_88 ) ) {
F_7 ( & V_38 -> V_68 , L_12 ) ;
return - V_89 ;
}
V_30 = F_17 ( & V_38 -> V_68 , sizeof( struct V_29 ) ,
V_90 ) ;
if ( V_30 == NULL )
return - V_91 ;
V_30 -> V_4 = V_7 -> V_4 ;
V_30 -> V_38 = V_38 ;
V_30 -> V_7 = V_7 ;
V_30 -> V_34 = V_92 ;
V_30 -> V_66 = false ;
V_30 -> V_59 . V_93 = V_94 ;
V_30 -> V_59 . V_95 = F_9 ;
V_30 -> V_59 . V_60 = V_96 ;
F_18 ( V_38 , V_30 ) ;
V_30 -> V_67 = F_19 ( & V_38 -> V_68 , L_13 ) ;
if ( F_20 ( V_30 -> V_67 ) ) {
F_7 ( & V_38 -> V_68 , L_14 ) ;
V_75 = F_21 ( V_30 -> V_67 ) ;
V_30 -> V_67 = NULL ;
return V_75 ;
}
if ( V_30 -> V_7 -> V_58 ) {
V_75 = F_5 ( V_30 ) ;
if ( V_75 < 0 ) {
F_7 ( & V_38 -> V_68 ,
L_2 , V_75 ) ;
V_75 = - V_86 ;
goto V_97;
}
}
V_75 = F_22 ( & V_38 -> V_68 , & V_30 -> V_59 ) ;
if ( V_75 < 0 ) {
F_7 ( & V_38 -> V_68 , L_15 , V_75 ) ;
V_75 = - V_86 ;
goto V_98;
}
V_75 = F_23 ( V_30 -> V_59 . V_68 , & V_99 ) ;
if ( V_75 < 0 ) {
F_7 ( & V_38 -> V_68 , L_16 , V_75 ) ;
V_75 = - V_86 ;
goto V_100;
}
return 0 ;
V_100:
F_24 ( & V_30 -> V_59 ) ;
V_98:
V_97:
F_25 ( V_30 -> V_67 ) ;
return V_75 ;
}
static int T_6 F_26 ( struct V_37 * V_38 )
{
struct V_29 * V_30 = F_27 ( V_38 ) ;
F_28 ( V_30 -> V_59 . V_68 , & V_99 ) ;
if ( V_30 -> V_66 )
F_11 ( V_30 -> V_67 ) ;
F_25 ( V_30 -> V_67 ) ;
F_24 ( & V_30 -> V_59 ) ;
return 0 ;
}

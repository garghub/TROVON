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
struct V_16 * V_17 = V_7 -> V_18 ;
struct V_19 * V_20 = V_7 -> V_20 ;
V_9 = ( V_17 -> V_21 << V_22 ) |
( ( V_17 -> V_23 & 7 ) << V_24 ) ;
if ( V_7 -> V_4 == V_25 ||
V_7 -> V_4 == V_26 )
V_9 |= ( V_27 ) ;
if ( V_7 -> V_4 == V_26 ) {
V_10 =
( V_17 -> V_28 << V_29 ) |
( V_30 ) |
( V_17 -> V_31 << V_32 ) ;
V_12 =
( V_17 -> V_33 << V_34 ) |
( V_17 -> V_35 << V_36 ) ;
}
if ( V_7 -> V_4 == V_37 )
V_9 |= ( V_38 ) |
( V_17 -> V_39 << V_40 ) |
( V_41 ) ;
V_11 = ( V_17 -> V_42 << V_43 ) |
( V_17 -> V_44 << V_45 ) ;
if ( V_7 -> V_13 )
V_13 = V_7 -> V_13 ;
else
V_13 = V_7 -> V_13 = V_17 -> V_46 ;
V_14 [ 0 ] = V_9 ;
V_14 [ 1 ] = V_10 ;
V_14 [ 2 ] = V_11 ;
V_14 [ 3 ] = 0x00 ;
V_14 [ 4 ] = V_12 ;
V_14 [ 5 ] = V_13 ;
V_14 [ 6 ] = V_47 ;
V_14 [ 7 ] = V_48 ;
V_14 [ 8 ] = V_49 ;
V_14 [ 9 ] = V_50 ;
V_14 [ 10 ] = V_51 ;
V_14 [ 11 ] = V_52 ;
V_14 [ 12 ] = V_53 ;
V_14 [ 13 ] = V_54 ;
V_14 [ 14 ] = V_55 ;
if ( ! V_7 -> V_56 ) {
V_8 = F_5 ( V_7 -> V_57 ) ;
if ( V_8 ) {
F_6 ( & V_7 -> V_20 -> V_58 ,
L_1 ) ;
return V_8 ;
}
V_7 -> V_56 = true ;
}
for ( V_2 = 0 ; V_2 < V_15 ; V_2 ++ ) {
V_8 = F_7 ( V_20 ,
V_59 [ V_2 ] , V_14 [ V_2 ] ) ;
if ( V_8 )
break;
}
return V_8 ;
}
static void F_8 ( struct V_60 * V_61 ,
enum V_62 V_46 )
{
int V_63 ;
struct V_6 * V_7 =
F_9 ( V_61 , struct V_6 , V_64 ) ;
switch ( V_7 -> V_4 ) {
case V_25 :
if ( ! V_7 -> V_56 ) {
V_63 = F_4 ( V_7 ) ;
if ( V_63 ) {
F_6 ( & V_7 -> V_20 -> V_58 ,
L_2 , V_63 ) ;
break;
}
}
V_63 = F_7 ( V_7 -> V_20 ,
V_65 , V_46 / 2 ) ;
if ( V_63 )
F_6 ( & V_7 -> V_20 -> V_58 ,
L_3 , V_63 ) ;
else
V_7 -> V_13 = V_46 / 2 ;
if ( V_46 == 0 ) {
V_63 = F_10 ( V_7 -> V_57 ) ;
if ( V_63 )
F_6 ( & V_7 -> V_20 -> V_58 ,
L_4 ) ;
V_7 -> V_56 = false ;
}
break;
case V_26 :
break;
case V_37 :
break;
default:
break;
}
}
static T_2 F_11 ( struct V_66 * V_58 , struct V_67
* V_68 , const char * V_69 , T_3 V_70 )
{
int V_63 ;
struct V_19 * V_20 = F_9 (
V_58 -> V_71 , struct V_19 , V_58 ) ;
struct V_6 * V_7 = F_12 ( V_20 ) ;
int V_4 ;
V_4 = F_1 ( V_69 ) ;
if ( V_4 < 0 ) {
F_6 ( V_58 , L_5 ) ;
return - V_72 ;
}
if ( V_4 == V_25 )
V_7 -> V_4 = V_25 ;
else if ( V_4 == V_26 )
V_7 -> V_4 = V_26 ;
else if ( V_4 == V_37 ) {
F_6 ( V_58 , L_6 ) ;
return - V_72 ;
}
V_63 = F_4 ( V_7 ) ;
if ( V_63 ) {
F_6 ( V_58 , L_7 , V_69 , V_63 ) ;
return V_63 ;
}
return sizeof( V_7 -> V_4 ) ;
}
static int T_4 F_13 ( struct V_19 * V_20 ,
const struct V_73 * V_74 )
{
struct V_16 * V_18 = V_20 -> V_58 . V_75 ;
struct V_6 * V_7 ;
int V_63 = 0 ;
if ( V_18 == NULL ) {
F_6 ( & V_20 -> V_58 , L_8 ) ;
V_63 = - V_76 ;
goto V_77;
}
if ( V_18 -> V_4 > V_37 ) {
F_6 ( & V_20 -> V_58 , L_9 ) ;
V_63 = - V_72 ;
goto V_77;
}
if ( ! F_14 ( V_20 -> V_78 , V_79 ) ) {
F_6 ( & V_20 -> V_58 , L_10 ) ;
V_63 = - V_80 ;
goto V_77;
}
V_7 = F_15 ( sizeof( struct V_6 ) , V_81 ) ;
if ( V_7 == NULL ) {
V_63 = - V_82 ;
goto V_77;
}
V_7 -> V_4 = V_18 -> V_4 ;
V_7 -> V_20 = V_20 ;
V_7 -> V_18 = V_18 ;
V_7 -> V_13 = V_83 ;
V_7 -> V_56 = false ;
V_7 -> V_64 . V_84 = V_85 ;
V_7 -> V_64 . V_86 = F_8 ;
F_16 ( V_20 , V_7 ) ;
V_7 -> V_57 = F_17 ( & V_20 -> V_58 , L_11 ) ;
if ( F_18 ( V_7 -> V_57 ) ) {
F_6 ( & V_20 -> V_58 , L_12 ) ;
V_63 = F_19 ( V_7 -> V_57 ) ;
V_7 -> V_57 = NULL ;
goto V_87;
}
if ( V_7 -> V_18 -> V_46 ) {
V_63 = F_4 ( V_7 ) ;
if ( V_63 < 0 ) {
F_6 ( & V_20 -> V_58 ,
L_2 , V_63 ) ;
V_63 = - V_76 ;
goto V_88;
}
}
V_63 = F_20 ( & V_20 -> V_58 , & V_7 -> V_64 ) ;
if ( V_63 < 0 ) {
F_6 ( & V_20 -> V_58 , L_13 , V_63 ) ;
V_63 = - V_76 ;
goto V_89;
}
V_63 = F_21 ( V_7 -> V_64 . V_58 , & V_90 ) ;
if ( V_63 < 0 ) {
F_6 ( & V_20 -> V_58 , L_14 , V_63 ) ;
V_63 = - V_76 ;
goto V_91;
}
return 0 ;
V_91:
F_22 ( & V_7 -> V_64 ) ;
V_89:
V_88:
F_23 ( V_7 -> V_57 ) ;
V_87:
F_16 ( V_20 , NULL ) ;
F_24 ( V_7 ) ;
V_77:
return V_63 ;
}
static int T_5 F_25 ( struct V_19 * V_20 )
{
struct V_6 * V_7 = F_12 ( V_20 ) ;
F_26 ( V_7 -> V_64 . V_58 , & V_90 ) ;
if ( V_7 -> V_56 )
F_10 ( V_7 -> V_57 ) ;
F_23 ( V_7 -> V_57 ) ;
F_22 ( & V_7 -> V_64 ) ;
F_24 ( V_7 ) ;
return 0 ;
}
static int T_6 F_27 ( void )
{
return F_28 ( & V_92 ) ;
}
static void T_7 F_29 ( void )
{
F_30 ( & V_92 ) ;
}

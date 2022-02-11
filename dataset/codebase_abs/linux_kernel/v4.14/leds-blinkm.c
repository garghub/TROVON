static T_1 F_1 ( struct V_1 * V_2 , char * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
V_9 = F_4 ( V_6 , V_10 ) ;
if ( V_9 < 0 )
return V_9 ;
switch ( V_4 ) {
case V_11 :
return F_5 ( V_3 , V_12 , L_1 , V_8 -> V_13 ) ;
case V_14 :
return F_5 ( V_3 , V_12 , L_1 , V_8 -> V_15 ) ;
case V_16 :
return F_5 ( V_3 , V_12 , L_1 , V_8 -> V_17 ) ;
default:
return - V_18 ;
}
return - V_18 ;
}
static int F_6 ( struct V_1 * V_2 , const char * V_3 , int V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 ;
T_2 V_19 ;
V_6 = F_2 ( V_2 ) ;
V_8 = F_3 ( V_6 ) ;
V_9 = F_7 ( V_3 , 10 , & V_19 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 , L_2 ) ;
return V_9 ;
}
switch ( V_4 ) {
case V_11 :
V_8 -> V_20 = V_19 ;
break;
case V_14 :
V_8 -> V_21 = V_19 ;
break;
case V_16 :
V_8 -> V_22 = V_19 ;
break;
default:
return - V_18 ;
}
F_9 ( V_2 , L_3 ,
V_8 -> V_20 , V_8 -> V_21 , V_8 -> V_22 ) ;
V_9 = F_4 ( V_6 , V_23 ) ;
if ( V_9 < 0 ) {
F_8 ( V_2 , L_4 ) ;
return V_9 ;
}
return 0 ;
}
static T_1 F_10 ( struct V_1 * V_2 , struct V_24 * V_25 ,
char * V_3 )
{
return F_1 ( V_2 , V_3 , V_11 ) ;
}
static T_1 F_11 ( struct V_1 * V_2 , struct V_24 * V_25 ,
const char * V_3 , T_3 V_26 )
{
int V_9 ;
V_9 = F_6 ( V_2 , V_3 , V_11 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_26 ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_24 * V_25 ,
char * V_3 )
{
return F_1 ( V_2 , V_3 , V_14 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_24 * V_25 ,
const char * V_3 , T_3 V_26 )
{
int V_9 ;
V_9 = F_6 ( V_2 , V_3 , V_14 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_26 ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_24 * V_25 ,
char * V_3 )
{
return F_1 ( V_2 , V_3 , V_16 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_24 * V_25 ,
const char * V_3 , T_3 V_26 )
{
int V_9 ;
V_9 = F_6 ( V_2 , V_3 , V_16 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_26 ;
}
static T_1 F_16 ( struct V_1 * V_2 , struct V_24 * V_25 ,
char * V_3 )
{
return F_5 ( V_3 , V_12 ,
L_5 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , struct V_24 * V_25 ,
const char * V_3 , T_3 V_26 )
{
struct V_5 * V_6 ;
int V_9 ;
V_6 = F_2 ( V_2 ) ;
V_9 = F_18 ( V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
return V_26 ;
}
static int F_19 ( struct V_5 * V_6 , int V_27 , T_2 * V_28 )
{
int V_29 ;
int V_30 ;
int V_31 = V_32 [ V_27 ] . V_33 ;
V_29 = F_20 ( V_6 , V_32 [ V_27 ] . V_34 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_31 == 0 )
return 0 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_29 = F_20 ( V_6 , V_28 [ V_30 ] ) ;
if ( V_29 < 0 )
return V_29 ;
}
return 0 ;
}
static int F_21 ( struct V_5 * V_6 , int V_27 , T_2 * V_28 )
{
int V_29 ;
int V_30 ;
int V_35 = V_32 [ V_27 ] . V_36 ;
for ( V_30 = 0 ; V_30 < V_35 ; V_30 ++ ) {
V_29 = F_22 ( V_6 ) ;
if ( V_29 < 0 )
return V_29 ;
V_28 [ V_30 ] = V_29 ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_6 , int V_27 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
if ( F_23 ( & V_8 -> V_37 ) < 0 )
return - V_38 ;
switch ( V_27 ) {
case V_39 :
case V_23 :
case V_40 :
V_8 -> args [ 0 ] = V_8 -> V_20 ;
V_8 -> args [ 1 ] = V_8 -> V_21 ;
V_8 -> args [ 2 ] = V_8 -> V_22 ;
F_19 ( V_6 , V_27 , V_8 -> args ) ;
V_8 -> V_13 = V_8 -> args [ 0 ] ;
V_8 -> V_15 = V_8 -> args [ 1 ] ;
V_8 -> V_17 = V_8 -> args [ 2 ] ;
break;
case V_41 :
case V_42 :
V_8 -> args [ 0 ] = V_8 -> V_43 ;
V_8 -> args [ 1 ] = V_8 -> V_44 ;
V_8 -> args [ 2 ] = V_8 -> V_45 ;
F_19 ( V_6 , V_27 , V_8 -> args ) ;
V_8 -> V_46 = V_8 -> V_43 ;
V_8 -> V_47 = V_8 -> V_44 ;
V_8 -> V_48 = V_8 -> V_45 ;
break;
case V_49 :
V_8 -> args [ 0 ] = V_8 -> V_50 ;
V_8 -> args [ 1 ] = V_8 -> V_51 ;
V_8 -> args [ 2 ] = V_8 -> V_52 ;
F_19 ( V_6 , V_27 , V_8 -> args ) ;
break;
case V_53 :
F_19 ( V_6 , V_27 , NULL ) ;
break;
case V_10 :
V_8 -> args [ 0 ] = V_8 -> V_13 ;
V_8 -> args [ 1 ] = V_8 -> V_15 ;
V_8 -> args [ 2 ] = V_8 -> V_17 ;
F_19 ( V_6 , V_27 , NULL ) ;
F_21 ( V_6 , V_27 , V_8 -> args ) ;
V_8 -> V_13 = V_8 -> args [ 0 ] ;
V_8 -> V_15 = V_8 -> args [ 1 ] ;
V_8 -> V_17 = V_8 -> args [ 2 ] ;
break;
case V_54 :
V_8 -> args [ 0 ] = V_8 -> V_55 ;
F_19 ( V_6 , V_27 , NULL ) ;
F_21 ( V_6 , V_27 , V_8 -> args ) ;
V_8 -> V_55 = V_8 -> args [ 0 ] ;
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
F_8 ( & V_6 -> V_2 ,
L_6 , V_27 ) ;
break;
default:
F_8 ( & V_6 -> V_2 , L_7 , V_27 ) ;
F_24 ( & V_8 -> V_37 ) ;
return - V_18 ;
}
F_24 ( & V_8 -> V_37 ) ;
return 0 ;
}
static int F_25 ( struct V_64 * V_65 ,
enum V_66 V_19 , int V_4 )
{
struct V_67 * V_68 = F_26 ( V_65 ) ;
struct V_7 * V_8 = F_3 ( V_68 -> V_5 ) ;
switch ( V_4 ) {
case V_11 :
if ( V_8 -> V_20 == ( T_2 ) V_19 )
return 0 ;
V_8 -> V_20 = ( T_2 ) V_19 ;
break;
case V_14 :
if ( V_8 -> V_21 == ( T_2 ) V_19 )
return 0 ;
V_8 -> V_21 = ( T_2 ) V_19 ;
break;
case V_16 :
if ( V_8 -> V_22 == ( T_2 ) V_19 )
return 0 ;
V_8 -> V_22 = ( T_2 ) V_19 ;
break;
default:
F_8 ( & V_68 -> V_5 -> V_2 , L_8 ) ;
return - V_18 ;
}
F_4 ( V_68 -> V_5 , V_23 ) ;
F_9 ( & V_68 -> V_5 -> V_2 ,
L_9
L_10 ,
V_8 -> V_20 , V_8 -> V_21 ,
V_8 -> V_22 ) ;
return 0 ;
}
static int F_27 ( struct V_64 * V_65 ,
enum V_66 V_19 )
{
return F_25 ( V_65 , V_19 , V_11 ) ;
}
static int F_28 ( struct V_64 * V_65 ,
enum V_66 V_19 )
{
return F_25 ( V_65 , V_19 , V_14 ) ;
}
static int F_29 ( struct V_64 * V_65 ,
enum V_66 V_19 )
{
return F_25 ( V_65 , V_19 , V_16 ) ;
}
static void F_30 ( struct V_5 * V_6 )
{
int V_9 ;
V_9 = F_4 ( V_6 , V_53 ) ;
V_9 = F_4 ( V_6 , V_23 ) ;
}
static int F_18 ( struct V_5 * V_6 )
{
int V_9 ;
struct V_7 * V_8 = F_3 ( V_6 ) ;
V_8 -> V_20 = 0x01 ;
V_8 -> V_21 = 0x05 ;
V_8 -> V_22 = 0x10 ;
V_9 = F_4 ( V_6 , V_23 ) ;
if ( V_9 < 0 )
return V_9 ;
F_31 ( 2000 ) ;
V_8 -> V_20 = 0x25 ;
V_8 -> V_21 = 0x10 ;
V_8 -> V_22 = 0x31 ;
V_9 = F_4 ( V_6 , V_40 ) ;
if ( V_9 < 0 )
return V_9 ;
F_31 ( 2000 ) ;
V_8 -> V_43 = 0x50 ;
V_8 -> V_44 = 0x10 ;
V_8 -> V_45 = 0x20 ;
V_9 = F_4 ( V_6 , V_41 ) ;
if ( V_9 < 0 )
return V_9 ;
F_31 ( 2000 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 , struct V_69 * V_70 )
{
struct V_71 * V_72 = V_6 -> V_72 ;
int V_9 ;
int V_26 = 99 ;
T_2 V_73 [ 7 ] ;
if ( ! F_33 ( V_72 , V_74
| V_75
| V_76 ) )
return - V_77 ;
while ( V_26 > 0 ) {
V_9 = F_19 ( V_6 , V_54 , NULL ) ;
F_34 ( 5000 , 10000 ) ;
V_9 = F_21 ( V_6 , V_54 , V_73 ) ;
F_34 ( 5000 , 10000 ) ;
if ( V_73 [ 0 ] == 0x09 )
V_26 = 0 ;
V_26 -- ;
}
V_9 = F_19 ( V_6 , V_54 , NULL ) ;
if ( V_9 < 0 )
return V_9 ;
F_34 ( 20000 , 30000 ) ;
V_9 = F_21 ( V_6 , V_54 , V_73 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_73 [ 0 ] != 0x09 ) {
F_8 ( & V_6 -> V_2 , L_11 , V_73 [ 0 ] ) ;
return - V_77 ;
}
F_35 ( V_70 -> type , L_12 , V_78 ) ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 ,
const struct V_79 * V_80 )
{
struct V_7 * V_8 ;
struct V_67 * V_68 [ 3 ] ;
int V_81 , V_30 ;
char V_82 [ 28 ] ;
V_8 = F_37 ( & V_6 -> V_2 ,
sizeof( struct V_7 ) , V_83 ) ;
if ( ! V_8 ) {
V_81 = - V_84 ;
goto exit;
}
V_8 -> V_55 = 0x09 ;
V_8 -> V_55 = 0x08 ;
V_8 -> V_85 = 0xfe ;
V_8 -> V_50 = 0x01 ;
V_8 -> V_5 = V_6 ;
F_38 ( V_6 , V_8 ) ;
F_39 ( & V_8 -> V_37 ) ;
V_81 = F_40 ( & V_6 -> V_2 . V_86 , & V_87 ) ;
if ( V_81 < 0 ) {
F_8 ( & V_6 -> V_2 , L_13 ) ;
goto exit;
}
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ ) {
V_68 [ V_30 ] = & V_8 -> V_88 [ V_30 ] ;
V_68 [ V_30 ] -> V_5 = V_6 ;
V_68 [ V_30 ] -> V_80 = V_30 ;
V_68 [ V_30 ] -> V_65 . V_89 = 255 ;
V_68 [ V_30 ] -> V_65 . V_90 = V_91 ;
switch ( V_30 ) {
case V_11 :
snprintf ( V_82 , sizeof( V_82 ) ,
L_14 ,
V_6 -> V_72 -> V_92 ,
V_6 -> V_93 ) ;
V_68 [ V_30 ] -> V_65 . V_94 = V_82 ;
V_68 [ V_30 ] -> V_65 . V_95 =
F_27 ;
V_81 = F_41 ( & V_6 -> V_2 ,
& V_68 [ V_30 ] -> V_65 ) ;
if ( V_81 < 0 ) {
F_8 ( & V_6 -> V_2 ,
L_15 ,
V_68 [ V_30 ] -> V_65 . V_94 ) ;
goto V_96;
}
break;
case V_14 :
snprintf ( V_82 , sizeof( V_82 ) ,
L_16 ,
V_6 -> V_72 -> V_92 ,
V_6 -> V_93 ) ;
V_68 [ V_30 ] -> V_65 . V_94 = V_82 ;
V_68 [ V_30 ] -> V_65 . V_95 =
F_28 ;
V_81 = F_41 ( & V_6 -> V_2 ,
& V_68 [ V_30 ] -> V_65 ) ;
if ( V_81 < 0 ) {
F_8 ( & V_6 -> V_2 ,
L_15 ,
V_68 [ V_30 ] -> V_65 . V_94 ) ;
goto V_97;
}
break;
case V_16 :
snprintf ( V_82 , sizeof( V_82 ) ,
L_17 ,
V_6 -> V_72 -> V_92 ,
V_6 -> V_93 ) ;
V_68 [ V_30 ] -> V_65 . V_94 = V_82 ;
V_68 [ V_30 ] -> V_65 . V_95 =
F_29 ;
V_81 = F_41 ( & V_6 -> V_2 ,
& V_68 [ V_30 ] -> V_65 ) ;
if ( V_81 < 0 ) {
F_8 ( & V_6 -> V_2 ,
L_15 ,
V_68 [ V_30 ] -> V_65 . V_94 ) ;
goto V_98;
}
break;
}
}
F_30 ( V_6 ) ;
return 0 ;
V_98:
F_42 ( & V_68 [ V_14 ] -> V_65 ) ;
V_97:
F_42 ( & V_68 [ V_11 ] -> V_65 ) ;
V_96:
F_43 ( & V_6 -> V_2 . V_86 , & V_87 ) ;
exit:
return V_81 ;
}
static int F_44 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_3 ( V_6 ) ;
int V_9 = 0 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < 3 ; V_30 ++ )
F_42 ( & V_8 -> V_88 [ V_30 ] . V_65 ) ;
V_8 -> V_20 = 0x00 ;
V_8 -> V_21 = 0x00 ;
V_8 -> V_22 = 0x00 ;
V_9 = F_4 ( V_6 , V_40 ) ;
if ( V_9 < 0 )
F_8 ( & V_6 -> V_2 , L_18 ) ;
V_8 -> V_43 = 0x00 ;
V_8 -> V_44 = 0x00 ;
V_8 -> V_45 = 0x00 ;
V_9 = F_4 ( V_6 , V_41 ) ;
if ( V_9 < 0 )
F_8 ( & V_6 -> V_2 , L_18 ) ;
V_8 -> V_20 = 0xff ;
V_9 = F_4 ( V_6 , V_23 ) ;
if ( V_9 < 0 )
F_8 ( & V_6 -> V_2 , L_18 ) ;
V_8 -> V_20 = 0x00 ;
V_9 = F_4 ( V_6 , V_40 ) ;
if ( V_9 < 0 )
F_8 ( & V_6 -> V_2 , L_18 ) ;
F_43 ( & V_6 -> V_2 . V_86 , & V_87 ) ;
return 0 ;
}

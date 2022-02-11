static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 ;
char V_6 [] = { ( V_3 >> 8 ) | 0x80 , V_3 & 0xff , V_4 } ;
struct V_7 V_8 = { . V_9 = V_2 -> V_10 , . V_11 = 0 ,
. V_6 = V_6 , . V_12 = sizeof( V_6 ) } ;
V_5 = F_2 ( V_2 -> V_13 -> V_14 . V_15 , & V_8 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_5 == 1 ) ? 0 : - V_16 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_17 ,
char * V_6 , int V_18 )
{
int V_5 ;
char V_19 [ 3 ] ;
struct V_7 V_8 [ 2 ] = { { . V_9 = V_2 -> V_10 , . V_11 = 0 ,
. V_6 = V_19 , . V_12 = 2 } ,
{ . V_9 = V_2 -> V_10 , . V_11 = V_20 ,
. V_6 = V_6 , . V_12 = V_18 } } ;
V_19 [ 0 ] = 0x40 | V_3 >> 8 ;
V_19 [ 1 ] = V_3 & 0xff ;
if ( V_17 >= 0 ) {
V_19 [ 2 ] = V_17 ;
V_8 [ 0 ] . V_12 ++ ;
}
V_5 = F_2 ( V_2 -> V_13 -> V_14 . V_15 , V_8 , 2 ) ;
if ( V_5 < 0 )
return V_5 ;
return ( V_5 == 2 ) ? 0 : - V_16 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_21 , T_2 V_22 )
{
int V_5 ;
char V_6 , V_23 ;
V_5 = F_3 ( V_2 , V_3 , - 1 , & V_6 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_23 = V_6 ;
V_6 = ( V_6 & ~ V_21 ) | ( V_22 & V_21 ) ;
if ( V_6 == V_23 )
return 0 ;
return F_1 ( V_2 , V_3 , V_6 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned char V_6 [ 40 ] ;
F_6 ( V_24 ) ;
int V_25 , V_26 , V_5 ;
int V_27 , V_28 , V_29 ;
bool V_30 = true ;
if ( V_2 -> V_13 -> V_31 == V_32 )
return 0 ;
V_5 = F_3 ( V_2 , 0xe1 , - 1 , V_6 , 1 ) ;
if ( V_5 < 0 || ! ( V_6 [ 0 ] & ( 1 << 4 ) ) ) {
F_7 ( V_2 , 0xe0 , 1 << 4 ) ;
return 0 ;
}
V_5 = F_3 ( V_2 , 0xe3 , 0x11 , V_6 , sizeof( V_6 ) ) ;
if ( V_5 < 0 )
return V_5 ;
F_8 ( V_2 , 0xe0 , 1 << 4 ) ;
F_7 ( V_2 , 0xe0 , 1 << 4 ) ;
F_9 ( 16 , L_1 , 40 , V_6 ) ;
V_27 = ( V_6 [ 0 ] >> 7 ) & 0x01 ;
V_29 = 0 ;
for ( V_25 = 0 ; V_25 < sizeof( V_6 ) ; V_25 ++ ) {
for ( V_26 = 7 ; V_26 >= 0 ; V_26 -- ) {
V_28 = ( V_6 [ V_25 ] >> V_26 ) & 0x01 ;
if ( V_28 == V_27 ) {
V_29 ++ ;
continue;
}
if ( V_30 ) {
V_30 = false ;
F_10 ( & V_24 ) ;
V_24 . V_33 = true ;
if ( V_29 > V_34 - 2 &&
V_29 < V_34 + 2 ) {
V_24 . V_35 = V_36 ;
F_9 ( 16 , L_2 ,
V_24 . V_33 ? L_3 : L_4 ,
V_24 . V_35 ) ;
} else {
V_24 . V_35 = V_37 ;
F_9 ( 16 , L_5 ,
V_24 . V_33 ? L_3 : L_4 ,
V_24 . V_35 ) ;
}
F_11 ( V_2 -> V_5 , & V_24 ) ;
}
F_10 ( & V_24 ) ;
V_24 . V_33 = V_27 ? false : true ;
V_24 . V_35 = V_38 * V_29 ;
F_9 ( 16 , L_6 ,
V_24 . V_33 ? L_3 : L_4 ,
V_24 . V_35 ) ;
F_11 ( V_2 -> V_5 , & V_24 ) ;
V_29 = 1 ;
V_27 = V_28 ;
}
}
F_10 ( & V_24 ) ;
V_24 . V_33 = V_27 ? false : true ;
V_24 . V_35 = V_38 * V_29 ;
F_9 ( 16 , L_7 ,
V_24 . V_33 ? L_3 : L_4 ,
V_24 . V_35 ) ;
F_11 ( V_2 -> V_5 , & V_24 ) ;
F_12 ( V_2 -> V_5 ) ;
return 1 ;
}
static void F_13 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_14 ( V_40 , struct V_1 , V_40 . V_40 ) ;
int V_5 ;
V_5 = V_2 -> V_41 ( V_2 ) ;
if ( V_5 < 0 )
F_15 ( L_8 ) ;
F_16 ( & V_2 -> V_40 , F_17 ( V_2 -> V_42 ) ) ;
}
static int F_18 ( struct V_43 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_44 ;
F_19 ( & V_2 -> V_40 , F_13 ) ;
F_7 ( V_2 , 0xe0 , 1 << 4 ) ;
F_16 ( & V_2 -> V_40 , F_17 ( V_2 -> V_42 ) ) ;
return 0 ;
}
static void F_20 ( struct V_43 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_44 ;
F_21 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_13 -> V_31 != V_32 ) {
F_8 ( V_2 , 0xe0 , 1 << 4 ) ;
}
}
static int F_22 ( struct V_45 * V_13 )
{
int V_25 = 0 ;
const unsigned short V_46 [] = {
0x47 , V_47
} ;
while ( V_46 [ V_25 ] != V_47 ) {
if ( F_23 ( V_13 -> V_14 . V_15 ,
V_46 [ V_25 ] ) == 1 )
return V_46 [ V_25 ] ;
V_25 ++ ;
}
return - V_48 ;
}
int F_24 ( struct V_45 * V_13 )
{
struct V_1 * V_2 ;
struct V_43 * V_5 ;
int V_49 = - V_50 ;
T_1 V_51 = 0 ;
if ( ! V_13 -> V_52 . V_53 || V_54 )
return 0 ;
V_51 = F_22 ( V_13 ) ;
if ( ! V_51 )
return - V_48 ;
V_2 = F_25 ( sizeof( * V_2 ) , V_55 ) ;
V_5 = F_26 () ;
if ( ! V_2 || ! V_5 )
goto error;
V_2 -> V_13 = V_13 ;
V_13 -> V_2 = V_2 ;
V_2 -> V_5 = V_5 ;
V_5 -> V_44 = V_2 ;
V_5 -> V_56 = F_18 ;
V_5 -> V_57 = F_20 ;
if ( V_13 -> V_52 . V_53 ) {
switch ( V_13 -> V_58 ) {
case V_59 :
V_5 -> V_60 = V_61 ;
V_2 -> V_41 = F_5 ;
break;
default:
V_49 = - V_48 ;
goto error;
}
V_2 -> V_10 = V_51 ;
}
V_2 -> V_42 = 100 ;
snprintf ( V_2 -> V_62 , sizeof( V_2 -> V_62 ) , L_9 ,
V_13 -> V_52 . V_62 ) ;
F_27 ( V_13 -> V_63 , V_2 -> V_64 , sizeof( V_2 -> V_64 ) ) ;
F_28 ( V_2 -> V_64 , L_10 , sizeof( V_2 -> V_64 ) ) ;
V_5 -> V_65 = V_2 -> V_62 ;
V_5 -> V_66 = V_2 -> V_64 ;
V_5 -> V_67 . V_68 = V_69 ;
V_5 -> V_67 . V_70 = 1 ;
V_5 -> V_67 . V_71 = F_29 ( V_13 -> V_63 -> V_72 . V_73 ) ;
V_5 -> V_67 . V_74 = F_29 ( V_13 -> V_63 -> V_72 . V_75 ) ;
V_5 -> V_13 . V_76 = & V_13 -> V_63 -> V_13 ;
V_5 -> V_77 = L_11 ;
V_5 -> V_78 = V_79 ;
V_5 -> V_80 = V_81 | V_82 ;
V_49 = F_30 ( V_5 ) ;
if ( V_49 )
goto error;
F_15 ( L_12 , V_2 -> V_62 ) ;
return 0 ;
error:
V_13 -> V_2 = NULL ;
F_31 ( V_5 ) ;
F_32 ( V_2 ) ;
return V_49 ;
}
void F_33 ( struct V_45 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
if ( ! V_2 )
return;
F_34 ( V_2 -> V_5 ) ;
F_32 ( V_2 ) ;
V_13 -> V_2 = NULL ;
}
int F_35 ( struct V_45 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
if ( ! V_2 )
return 0 ;
F_15 ( L_13 ) ;
F_21 ( & V_2 -> V_40 ) ;
F_8 ( V_2 , 0xe0 , 1 << 4 ) ;
return 0 ;
}
int F_36 ( struct V_45 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
if ( ! V_2 )
return 0 ;
F_15 ( L_14 ) ;
F_7 ( V_2 , 0xe0 , 1 << 4 ) ;
F_16 ( & V_2 -> V_40 , F_17 ( V_2 -> V_42 ) ) ;
return 0 ;
}

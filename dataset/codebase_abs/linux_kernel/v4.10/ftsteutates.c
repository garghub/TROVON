static int F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
int V_4 ;
unsigned char V_5 = V_3 >> 8 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
F_3 ( & V_7 -> V_9 ) ;
F_4 ( & V_2 -> V_8 , L_1 , V_5 ) ;
V_4 = F_5 ( V_2 , V_10 , V_5 ) ;
if ( V_4 < 0 )
goto error;
V_3 &= 0xFF ;
V_4 = F_6 ( V_2 , V_3 ) ;
F_4 ( & V_2 -> V_8 , L_2 , V_3 , V_4 ) ;
error:
F_7 ( & V_7 -> V_9 ) ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned short V_3 ,
unsigned char V_11 )
{
int V_4 ;
unsigned char V_5 = V_3 >> 8 ;
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
F_3 ( & V_7 -> V_9 ) ;
F_4 ( & V_2 -> V_8 , L_1 , V_5 ) ;
V_4 = F_5 ( V_2 , V_10 , V_5 ) ;
if ( V_4 < 0 )
goto error;
V_3 &= 0xFF ;
F_4 ( & V_2 -> V_8 ,
L_3 , V_3 , V_11 ) ;
V_4 = F_5 ( V_2 , V_3 , V_11 ) ;
error:
F_7 ( & V_7 -> V_9 ) ;
return V_4 ;
}
static int F_9 ( struct V_6 * V_7 )
{
int V_12 ;
int V_13 = 0 ;
F_3 ( & V_7 -> V_14 ) ;
if ( ! F_10 ( V_15 , V_7 -> V_16 + 2 * V_17 ) && V_7 -> V_18 )
goto exit;
V_13 = F_1 ( V_7 -> V_2 , V_19 ) ;
if ( V_13 < 0 )
goto exit;
V_7 -> V_18 = ! ! ( V_13 & 0x02 ) ;
if ( F_11 ( ! V_7 -> V_18 ) ) {
V_13 = - V_20 ;
goto exit;
}
V_13 = F_1 ( V_7 -> V_2 , V_21 ) ;
if ( V_13 < 0 )
goto exit;
V_7 -> V_22 = V_13 ;
V_13 = F_1 ( V_7 -> V_2 , V_23 ) ;
if ( V_13 < 0 )
goto exit;
V_7 -> V_24 = V_13 ;
for ( V_12 = 0 ; V_12 < V_25 ; V_12 ++ ) {
if ( V_7 -> V_22 & F_12 ( V_12 ) ) {
V_13 = F_1 ( V_7 -> V_2 , F_13 ( V_12 ) ) ;
if ( V_13 < 0 )
goto exit;
V_7 -> V_26 [ V_12 ] = V_13 ;
V_13 = F_1 ( V_7 -> V_2 ,
F_14 ( V_12 ) ) ;
if ( V_13 < 0 )
goto exit;
V_7 -> V_27 [ V_12 ] = V_13 ;
} else {
V_7 -> V_26 [ V_12 ] = 0 ;
V_7 -> V_27 [ V_12 ] = 0 ;
}
}
V_13 = F_1 ( V_7 -> V_2 , V_28 ) ;
if ( V_13 < 0 )
goto exit;
V_7 -> V_29 = V_13 ;
for ( V_12 = 0 ; V_12 < V_30 ; V_12 ++ ) {
V_13 = F_1 ( V_7 -> V_2 , F_15 ( V_12 ) ) ;
if ( V_13 < 0 )
goto exit;
V_7 -> V_31 [ V_12 ] = V_13 ;
}
for ( V_12 = 0 ; V_12 < V_32 ; V_12 ++ ) {
V_13 = F_1 ( V_7 -> V_2 , F_16 ( V_12 ) ) ;
if ( V_13 < 0 )
goto exit;
V_7 -> V_33 [ V_12 ] = V_13 ;
}
V_7 -> V_16 = V_15 ;
V_13 = 0 ;
exit:
F_7 ( & V_7 -> V_14 ) ;
return V_13 ;
}
static int F_17 ( struct V_6 * V_7 ,
enum V_34 V_35 )
{
int V_4 ;
if ( V_7 -> V_35 == V_35 )
return 0 ;
V_4 = F_1 ( V_7 -> V_2 , V_36 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( ( V_35 == V_37 && V_4 & F_12 ( 1 ) ) ||
( V_35 == V_38 && ( V_4 & F_12 ( 1 ) ) == 0 ) ) {
V_7 -> V_35 = V_35 ;
return 0 ;
}
if ( V_35 == V_37 )
V_4 |= F_12 ( 1 ) ;
else
V_4 &= ~ F_12 ( 1 ) ;
V_4 = F_8 ( V_7 -> V_2 , V_36 , V_4 ) ;
if ( V_4 < 0 )
return V_4 ;
V_7 -> V_35 = V_35 ;
return V_4 ;
}
static int F_18 ( struct V_39 * V_40 , unsigned int V_41 )
{
struct V_6 * V_7 ;
enum V_34 V_35 = V_37 ;
int V_4 ;
V_7 = F_19 ( V_40 ) ;
if ( V_41 > 0xFF ) {
V_41 = F_20 ( V_41 , 60 ) * 60 ;
V_35 = V_38 ;
}
V_4 = F_17 ( V_7 , V_35 ) ;
if ( V_4 < 0 )
return V_4 ;
V_40 -> V_41 = V_41 ;
return 0 ;
}
static int F_21 ( struct V_39 * V_40 )
{
struct V_6 * V_7 = F_19 ( V_40 ) ;
return F_8 ( V_7 -> V_2 , V_42 ,
V_40 -> V_41 / ( V_43 ) V_7 -> V_35 ) ;
}
static int F_22 ( struct V_39 * V_40 )
{
struct V_6 * V_7 ;
V_7 = F_19 ( V_40 ) ;
return F_8 ( V_7 -> V_2 , V_42 , 0 ) ;
}
static int F_23 ( struct V_6 * V_7 )
{
int V_41 , V_4 ;
F_24 ( & V_7 -> V_40 , V_7 ) ;
V_41 = F_1 ( V_7 -> V_2 , V_42 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_41 == 0 ) {
V_4 = F_17 ( V_7 , V_37 ) ;
if ( V_4 < 0 )
return V_4 ;
V_7 -> V_40 . V_41 = 60 ;
} else {
V_4 = F_1 ( V_7 -> V_2 , V_36 ) ;
if ( V_4 < 0 )
return V_4 ;
V_7 -> V_35 = V_4 & F_12 ( 1 ) ? V_37 : V_38 ;
V_7 -> V_40 . V_41 = V_41 * ( V_43 ) V_7 -> V_35 ;
F_25 ( V_44 , & V_7 -> V_40 . V_45 ) ;
}
V_7 -> V_40 . V_46 = & V_47 ;
V_7 -> V_40 . V_48 = & V_49 ;
V_7 -> V_40 . V_50 = & V_7 -> V_2 -> V_8 ;
V_7 -> V_40 . V_51 = 1 ;
V_7 -> V_40 . V_52 = 0xFF * 60 * V_53 ;
return F_26 ( & V_7 -> V_40 ) ;
}
static T_1 F_27 ( struct V_54 * V_8 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
int V_13 ;
V_13 = F_9 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_57 , L_4 , V_7 -> V_33 [ V_58 ] ) ;
}
static T_1 F_29 ( struct V_54 * V_8 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
int V_13 ;
V_13 = F_9 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_57 , L_4 , V_7 -> V_31 [ V_58 ] ) ;
}
static T_1 F_30 ( struct V_54 * V_8 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
int V_13 ;
V_13 = F_9 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_57 , L_5 , V_7 -> V_31 [ V_58 ] == 0 ) ;
}
static T_1 F_31 ( struct V_54 * V_8 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
int V_13 ;
V_13 = F_9 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_57 , L_4 , ! ! ( V_7 -> V_29 & F_12 ( V_58 ) ) ) ;
}
static T_1
F_32 ( struct V_54 * V_8 , struct V_55 * V_56 ,
const char * V_57 , T_2 V_59 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
long V_4 ;
V_4 = F_9 ( V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( F_33 ( V_57 , 10 , & V_4 ) || V_4 != 0 )
return - V_60 ;
F_3 ( & V_7 -> V_14 ) ;
V_4 = F_1 ( V_7 -> V_2 , F_34 ( V_58 ) ) ;
if ( V_4 < 0 )
goto error;
V_4 = F_8 ( V_7 -> V_2 , F_34 ( V_58 ) ,
V_4 | 0x1 ) ;
if ( V_4 < 0 )
goto error;
V_7 -> V_18 = false ;
error:
F_7 ( & V_7 -> V_14 ) ;
return V_4 ;
}
static T_1 F_35 ( struct V_54 * V_8 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
int V_13 ;
V_13 = F_9 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_57 , L_4 , V_7 -> V_26 [ V_58 ] ) ;
}
static T_1 F_36 ( struct V_54 * V_8 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
int V_13 ;
V_13 = F_9 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_57 , L_4 , V_7 -> V_27 [ V_58 ] ) ;
}
static T_1 F_37 ( struct V_54 * V_8 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
int V_13 ;
V_13 = F_9 ( V_7 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_57 , L_5 , ! ! ( V_7 -> V_24 & F_12 ( V_58 ) ) ) ;
}
static T_1
F_38 ( struct V_54 * V_8 , struct V_55 * V_56 ,
const char * V_57 , T_2 V_59 )
{
struct V_6 * V_7 = F_2 ( V_8 ) ;
int V_58 = F_28 ( V_56 ) -> V_58 ;
long V_4 ;
V_4 = F_9 ( V_7 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( F_33 ( V_57 , 10 , & V_4 ) || V_4 != 0 )
return - V_60 ;
F_3 ( & V_7 -> V_14 ) ;
V_4 = F_1 ( V_7 -> V_2 , F_39 ( V_58 ) ) ;
if ( V_4 < 0 )
goto error;
V_4 = F_8 ( V_7 -> V_2 , F_39 ( V_58 ) ,
V_4 | 0x1 ) ;
if ( V_4 < 0 )
goto error;
V_7 -> V_18 = false ;
error:
F_7 ( & V_7 -> V_14 ) ;
return V_4 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_61 * V_46 )
{
int V_62 ;
V_62 = F_6 ( V_2 , V_63 ) ;
if ( V_62 < 0x2b )
return - V_64 ;
V_62 = F_6 ( V_2 , V_65 ) ;
if ( V_62 != 0x17 )
return - V_64 ;
V_62 = F_6 ( V_2 , V_66 ) ;
if ( V_62 != 0x34 )
return - V_64 ;
V_62 = F_6 ( V_2 , V_67 ) ;
if ( V_62 != 0x54 )
return - V_64 ;
V_62 = F_6 ( V_2 , V_68 ) ;
if ( V_62 != 0x11 )
return - V_64 ;
F_41 ( V_46 -> type , V_69 [ 0 ] . V_70 , V_71 ) ;
V_46 -> V_72 = 0 ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( & V_2 -> V_8 ) ;
F_43 ( & V_7 -> V_40 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , const struct V_73 * V_74 )
{
V_43 V_75 ;
struct V_6 * V_7 ;
int V_13 ;
T_3 V_76 ;
struct V_54 * V_77 ;
if ( V_2 -> V_78 != 0x73 )
return - V_64 ;
V_76 = F_6 ( V_2 , V_68 ) ;
if ( V_76 > 0 && ( V_76 & 0xF0 ) == 0x10 ) {
switch ( V_76 & 0x0F ) {
case 0x01 :
break;
default:
F_4 ( & V_2 -> V_8 ,
L_6 ) ;
return - V_64 ;
}
} else {
F_4 ( & V_2 -> V_8 , L_7 ) ;
return - V_64 ;
}
V_7 = F_45 ( & V_2 -> V_8 , sizeof( struct V_6 ) ,
V_79 ) ;
if ( ! V_7 )
return - V_80 ;
F_46 ( & V_7 -> V_14 ) ;
F_46 ( & V_7 -> V_9 ) ;
V_7 -> V_2 = V_2 ;
F_47 ( & V_2 -> V_8 , V_7 ) ;
V_13 = F_6 ( V_2 , V_63 ) ;
if ( V_13 < 0 )
return V_13 ;
V_75 = V_13 ;
V_77 = F_48 ( & V_2 -> V_8 ,
L_8 ,
V_7 ,
V_81 ) ;
if ( F_49 ( V_77 ) )
return F_50 ( V_77 ) ;
V_13 = F_23 ( V_7 ) ;
if ( V_13 )
return V_13 ;
F_51 ( & V_2 -> V_8 , L_9 ,
( V_75 & 0xF0 ) >> 4 , V_75 & 0x0F ) ;
return 0 ;
}

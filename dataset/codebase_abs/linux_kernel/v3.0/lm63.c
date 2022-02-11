static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_4 ( V_9 -> V_10 [ V_7 -> V_11 ] ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , struct V_3 * V_12 ,
const char * V_5 , T_2 V_13 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_15 ) ;
unsigned long V_16 = F_8 ( V_5 , NULL , 10 ) ;
F_9 ( & V_9 -> V_17 ) ;
V_9 -> V_10 [ 1 ] = F_10 ( V_16 ) ;
F_11 ( V_15 , V_18 ,
V_9 -> V_10 [ 1 ] & 0xFF ) ;
F_11 ( V_15 , V_19 ,
V_9 -> V_10 [ 1 ] >> 8 ) ;
F_12 ( & V_9 -> V_17 ) ;
return V_13 ;
}
static T_1 F_13 ( struct V_1 * V_2 , struct V_3 * V_12 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_9 -> V_20 >= 2 * V_9 -> V_21 ?
255 : ( V_9 -> V_20 * 255 + V_9 -> V_21 ) /
( 2 * V_9 -> V_21 ) ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_12 ,
const char * V_5 , T_2 V_13 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_15 ) ;
unsigned long V_16 ;
if ( ! ( V_9 -> V_22 & 0x20 ) )
return - V_23 ;
V_16 = F_8 ( V_5 , NULL , 10 ) ;
F_9 ( & V_9 -> V_17 ) ;
V_9 -> V_20 = V_16 <= 0 ? 0 :
V_16 >= 255 ? 2 * V_9 -> V_21 :
( V_16 * V_9 -> V_21 * 2 + 127 ) / 255 ;
F_11 ( V_15 , V_24 , V_9 -> V_20 ) ;
F_12 ( & V_9 -> V_17 ) ;
return V_13 ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_12 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_9 -> V_22 & 0x20 ? 1 : 2 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_17 ( V_9 -> V_25 [ V_7 -> V_11 ] ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_17 ( V_9 -> V_25 [ V_7 -> V_11 ] )
+ V_9 -> V_26 ) ;
}
static T_1 F_19 ( struct V_1 * V_2 ,
struct V_3 * V_12 ,
const char * V_5 , T_2 V_13 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_15 ) ;
long V_16 = F_20 ( V_5 , NULL , 10 ) ;
F_9 ( & V_9 -> V_17 ) ;
V_9 -> V_25 [ 1 ] = F_21 ( V_16 ) ;
F_11 ( V_15 , V_27 , V_9 -> V_25 [ 1 ] ) ;
F_12 ( & V_9 -> V_17 ) ;
return V_13 ;
}
static T_1 F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_23 ( V_9 -> V_28 [ V_7 -> V_11 ] )
+ V_9 -> V_26 ) ;
}
static T_1 F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_13 )
{
static const T_3 V_29 [ 4 ] = {
V_30 ,
V_31 ,
V_32 ,
V_33 ,
} ;
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_15 ) ;
long V_16 = F_20 ( V_5 , NULL , 10 ) ;
int V_34 = V_7 -> V_11 ;
F_9 ( & V_9 -> V_17 ) ;
V_9 -> V_28 [ V_34 ] = F_25 ( V_16 - V_9 -> V_26 ) ;
F_11 ( V_15 , V_29 [ ( V_34 - 1 ) * 2 ] ,
V_9 -> V_28 [ V_34 ] >> 8 ) ;
F_11 ( V_15 , V_29 [ ( V_34 - 1 ) * 2 + 1 ] ,
V_9 -> V_28 [ V_34 ] & 0xff ) ;
F_12 ( & V_9 -> V_17 ) ;
return V_13 ;
}
static T_1 F_26 ( struct V_1 * V_2 , struct V_3 * V_12 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_1 , F_17 ( V_9 -> V_25 [ 2 ] )
+ V_9 -> V_26
- F_17 ( V_9 -> V_35 ) ) ;
}
static T_1 F_27 ( struct V_1 * V_2 , struct V_3 * V_12 ,
const char * V_5 , T_2 V_13 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_15 ) ;
long V_16 = F_20 ( V_5 , NULL , 10 ) ;
long V_36 ;
F_9 ( & V_9 -> V_17 ) ;
V_36 = F_17 ( V_9 -> V_25 [ 2 ] ) + V_9 -> V_26 - V_16 ;
F_11 ( V_15 , V_37 ,
F_28 ( V_36 ) ) ;
F_12 ( & V_9 -> V_17 ) ;
return V_13 ;
}
static T_1 F_29 ( struct V_1 * V_2 , struct V_3 * V_12 ,
char * V_5 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_9 -> V_38 ) ;
}
static T_1 F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_2 ) ;
int V_39 = V_7 -> V_11 ;
return sprintf ( V_5 , L_2 , ( V_9 -> V_38 >> V_39 ) & 1 ) ;
}
static int F_31 ( struct V_14 * V_40 ,
struct V_41 * V_42 )
{
struct V_43 * V_44 = V_40 -> V_44 ;
T_3 V_45 , V_46 , V_47 , V_48 ;
T_3 V_49 , V_50 ;
int V_51 = V_40 -> V_52 ;
if ( ! F_32 ( V_44 , V_53 ) )
return - V_54 ;
V_45 = F_33 ( V_40 , V_55 ) ;
V_46 = F_33 ( V_40 , V_56 ) ;
V_47 = F_33 ( V_40 ,
V_57 ) ;
V_48 = F_33 ( V_40 ,
V_58 ) ;
V_49 = F_33 ( V_40 ,
V_59 ) ;
V_50 = F_33 ( V_40 ,
V_60 ) ;
if ( V_45 != 0x01
|| ( V_47 & 0x18 ) != 0x00
|| ( V_48 & 0xF8 ) != 0x00
|| ( V_49 & 0x20 ) != 0x00
|| ( V_50 & 0xA4 ) != 0xA4 ) {
F_34 ( & V_44 -> V_2 ,
L_3 ,
V_45 , V_46 ) ;
return - V_54 ;
}
if ( V_46 == 0x41 && V_51 == 0x4c )
F_35 ( V_42 -> type , L_4 , V_61 ) ;
else if ( V_46 == 0x51 && ( V_51 == 0x18 || V_51 == 0x4e ) )
F_35 ( V_42 -> type , L_5 , V_61 ) ;
else
return - V_54 ;
return 0 ;
}
static int F_36 ( struct V_14 * V_40 ,
const struct V_62 * V_63 )
{
struct V_8 * V_9 ;
int V_64 ;
V_9 = F_37 ( sizeof( struct V_8 ) , V_65 ) ;
if ( ! V_9 ) {
V_64 = - V_66 ;
goto exit;
}
F_38 ( V_40 , V_9 ) ;
V_9 -> V_67 = 0 ;
F_39 ( & V_9 -> V_17 ) ;
V_9 -> V_68 = V_63 -> V_69 ;
if ( V_9 -> V_68 == V_70 )
V_9 -> V_26 = 16000 ;
F_40 ( V_40 ) ;
if ( ( V_64 = F_41 ( & V_40 -> V_2 . V_71 ,
& V_72 ) ) )
goto V_73;
if ( V_9 -> V_74 & 0x04 ) {
if ( ( V_64 = F_41 ( & V_40 -> V_2 . V_71 ,
& V_75 ) ) )
goto V_76;
}
V_9 -> V_77 = F_42 ( & V_40 -> V_2 ) ;
if ( F_43 ( V_9 -> V_77 ) ) {
V_64 = F_44 ( V_9 -> V_77 ) ;
goto V_76;
}
return 0 ;
V_76:
F_45 ( & V_40 -> V_2 . V_71 , & V_72 ) ;
F_45 ( & V_40 -> V_2 . V_71 , & V_75 ) ;
V_73:
F_46 ( V_9 ) ;
exit:
return V_64 ;
}
static void F_40 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_7 ( V_15 ) ;
V_9 -> V_74 = F_33 ( V_15 , V_57 ) ;
V_9 -> V_22 = F_33 ( V_15 ,
V_78 ) ;
if ( V_9 -> V_74 & 0x40 ) {
F_34 ( & V_15 -> V_2 , L_6 ) ;
V_9 -> V_74 &= 0xA7 ;
F_11 ( V_15 , V_57 ,
V_9 -> V_74 ) ;
}
V_9 -> V_21 = F_33 ( V_15 , V_79 ) ;
if ( V_9 -> V_21 == 0 )
V_9 -> V_21 = 1 ;
F_34 ( & V_15 -> V_2 , L_7 ,
( V_9 -> V_74 & 0x04 ) ? L_8 :
L_9 ) ;
F_34 ( & V_15 -> V_2 , L_10 ,
( V_9 -> V_22 & 0x08 ) ? L_11 : L_12 ,
( ( V_9 -> V_22 & 0x08 ) ? 700 : 180000 ) / V_9 -> V_21 ) ;
F_34 ( & V_15 -> V_2 , L_13 ,
( V_9 -> V_22 & 0x10 ) ? L_14 : L_15 ,
( V_9 -> V_22 & 0x20 ) ? L_16 : L_17 ) ;
}
static int F_47 ( struct V_14 * V_15 )
{
struct V_8 * V_9 = F_7 ( V_15 ) ;
F_48 ( V_9 -> V_77 ) ;
F_45 ( & V_15 -> V_2 . V_71 , & V_72 ) ;
F_45 ( & V_15 -> V_2 . V_71 , & V_75 ) ;
F_46 ( V_9 ) ;
return 0 ;
}
static struct V_8 * F_3 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_7 ( V_15 ) ;
F_9 ( & V_9 -> V_17 ) ;
if ( F_49 ( V_80 , V_9 -> V_81 + V_82 ) || ! V_9 -> V_67 ) {
if ( V_9 -> V_74 & 0x04 ) {
V_9 -> V_10 [ 0 ] = F_33 ( V_15 ,
V_83 ) & 0xFC ;
V_9 -> V_10 [ 0 ] |= F_33 ( V_15 ,
V_84 ) << 8 ;
V_9 -> V_10 [ 1 ] = ( F_33 ( V_15 ,
V_18 ) & 0xFC )
| ( F_33 ( V_15 ,
V_19 ) << 8 ) ;
}
V_9 -> V_21 = F_33 ( V_15 ,
V_79 ) ;
if ( V_9 -> V_21 == 0 )
V_9 -> V_21 = 1 ;
V_9 -> V_20 = F_33 ( V_15 ,
V_24 ) ;
V_9 -> V_25 [ 0 ] = F_33 ( V_15 ,
V_85 ) ;
V_9 -> V_25 [ 1 ] = F_33 ( V_15 ,
V_27 ) ;
V_9 -> V_28 [ 0 ] = F_33 ( V_15 ,
V_86 ) << 8 ;
V_9 -> V_28 [ 0 ] |= F_33 ( V_15 ,
V_87 ) ;
V_9 -> V_28 [ 1 ] = ( F_33 ( V_15 ,
V_30 ) << 8 )
| F_33 ( V_15 ,
V_31 ) ;
V_9 -> V_28 [ 2 ] = ( F_33 ( V_15 ,
V_32 ) << 8 )
| F_33 ( V_15 ,
V_33 ) ;
V_9 -> V_25 [ 2 ] = F_33 ( V_15 ,
V_88 ) ;
V_9 -> V_35 = F_33 ( V_15 ,
V_37 ) ;
V_9 -> V_38 = F_33 ( V_15 ,
V_59 ) & 0x7F ;
V_9 -> V_81 = V_80 ;
V_9 -> V_67 = 1 ;
}
F_12 ( & V_9 -> V_17 ) ;
return V_9 ;
}
static int T_4 F_50 ( void )
{
return F_51 ( & V_89 ) ;
}
static void T_5 F_52 ( void )
{
F_53 ( & V_89 ) ;
}

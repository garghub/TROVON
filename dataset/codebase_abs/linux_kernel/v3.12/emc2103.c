static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 = F_2 ( V_2 , V_3 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_6 , L_1 ,
V_3 , V_5 ) ;
} else {
* V_4 = V_5 ;
}
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_7 * V_8 )
{
T_1 V_9 , V_10 ;
if ( F_1 ( V_2 , V_3 , & V_9 ) < 0 )
return;
if ( F_1 ( V_2 , V_3 + 1 , & V_10 ) < 0 )
return;
V_8 -> V_9 = V_9 ;
V_8 -> V_11 = ( V_10 & 0xe0 ) >> 5 ;
}
static void F_5 ( struct V_1 * V_2 , T_2 * V_4 ,
T_1 V_12 , T_1 V_13 )
{
T_1 V_14 , V_15 ;
if ( F_1 ( V_2 , V_12 , & V_14 ) < 0 )
return;
if ( F_1 ( V_2 , V_13 , & V_15 ) < 0 )
return;
* V_4 = ( ( T_2 ) V_14 << 5 ) | ( V_15 >> 3 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_14 = ( V_16 & 0x1fe0 ) >> 5 ;
T_1 V_17 = ( V_16 & 0x001f ) << 3 ;
F_7 ( V_2 , V_18 , V_17 ) ;
F_7 ( V_2 , V_19 , V_14 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_9 ( V_2 ) ;
T_1 V_22 ;
if ( F_1 ( V_2 , V_23 , & V_22 ) < 0 )
return;
V_21 -> V_24 = 1 << ( ( V_22 & 0x60 ) >> 5 ) ;
V_21 -> V_25 = ( V_22 & 0x80 ) != 0 ;
}
static struct V_20 * F_10 ( struct V_26 * V_6 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
F_12 ( & V_21 -> V_27 ) ;
if ( F_13 ( V_28 , V_21 -> V_29 + V_30 + V_30 / 2 )
|| ! V_21 -> V_31 ) {
int V_32 ;
for ( V_32 = 0 ; V_32 < V_21 -> V_33 ; V_32 ++ ) {
F_4 ( V_2 , V_34 [ V_32 ] , & V_21 -> V_8 [ V_32 ] ) ;
F_1 ( V_2 , V_35 [ V_32 ] ,
& V_21 -> V_36 [ V_32 ] ) ;
F_1 ( V_2 , V_37 [ V_32 ] ,
& V_21 -> V_38 [ V_32 ] ) ;
}
F_1 ( V_2 , V_39 ,
& V_21 -> V_40 ) ;
F_1 ( V_2 , V_41 ,
& V_21 -> V_42 ) ;
F_5 ( V_2 , & V_21 -> V_43 ,
V_44 , V_45 ) ;
F_5 ( V_2 , & V_21 -> V_46 ,
V_19 , V_18 ) ;
F_8 ( V_2 ) ;
V_21 -> V_29 = V_28 ;
V_21 -> V_31 = true ;
}
F_14 ( & V_21 -> V_27 ) ;
return V_21 ;
}
static T_3
F_15 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
int V_50 = F_16 ( V_48 ) -> V_51 ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
int V_52 = V_21 -> V_8 [ V_50 ] . V_9 * 1000
+ V_21 -> V_8 [ V_50 ] . V_11 * 125 ;
return sprintf ( V_49 , L_2 , V_52 ) ;
}
static T_3
F_17 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
int V_50 = F_16 ( V_48 ) -> V_51 ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
int V_52 = V_21 -> V_36 [ V_50 ] * 1000 ;
return sprintf ( V_49 , L_2 , V_52 ) ;
}
static T_3
F_18 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
int V_50 = F_16 ( V_48 ) -> V_51 ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
int V_52 = V_21 -> V_38 [ V_50 ] * 1000 ;
return sprintf ( V_49 , L_2 , V_52 ) ;
}
static T_3
F_19 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
int V_50 = F_16 ( V_48 ) -> V_51 ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
bool V_53 = ( V_21 -> V_8 [ V_50 ] . V_9 == - 128 ) ;
return sprintf ( V_49 , L_2 , V_53 ? 1 : 0 ) ;
}
static T_3
F_20 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
int V_50 = F_16 ( V_48 ) -> V_51 ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
bool V_54 = V_21 -> V_40 & ( 1 << V_50 ) ;
return sprintf ( V_49 , L_2 , V_54 ? 1 : 0 ) ;
}
static T_3
F_21 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
int V_50 = F_16 ( V_48 ) -> V_51 ;
struct V_20 * V_21 = F_10 ( V_6 ) ;
bool V_54 = V_21 -> V_42 & ( 1 << V_50 ) ;
return sprintf ( V_49 , L_2 , V_54 ? 1 : 0 ) ;
}
static T_3 F_22 ( struct V_26 * V_6 , struct V_47 * V_48 ,
const char * V_49 , T_4 V_55 )
{
int V_50 = F_16 ( V_48 ) -> V_51 ;
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
long V_56 ;
int V_57 = F_23 ( V_49 , 10 , & V_56 ) ;
if ( V_57 < 0 )
return V_57 ;
V_56 = F_24 ( V_56 , 1000 ) ;
if ( ( V_56 < - 63 ) || ( V_56 > 127 ) )
return - V_58 ;
F_12 ( & V_21 -> V_27 ) ;
V_21 -> V_36 [ V_50 ] = V_56 ;
F_7 ( V_2 , V_35 [ V_50 ] , V_56 ) ;
F_14 ( & V_21 -> V_27 ) ;
return V_55 ;
}
static T_3 F_25 ( struct V_26 * V_6 , struct V_47 * V_48 ,
const char * V_49 , T_4 V_55 )
{
int V_50 = F_16 ( V_48 ) -> V_51 ;
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
long V_56 ;
int V_57 = F_23 ( V_49 , 10 , & V_56 ) ;
if ( V_57 < 0 )
return V_57 ;
V_56 = F_24 ( V_56 , 1000 ) ;
if ( ( V_56 < - 63 ) || ( V_56 > 127 ) )
return - V_58 ;
F_12 ( & V_21 -> V_27 ) ;
V_21 -> V_38 [ V_50 ] = V_56 ;
F_7 ( V_2 , V_37 [ V_50 ] , V_56 ) ;
F_14 ( & V_21 -> V_27 ) ;
return V_55 ;
}
static T_3
F_26 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
int V_59 = 0 ;
if ( V_21 -> V_43 != 0 )
V_59 = ( V_60 * V_21 -> V_24 ) / V_21 -> V_43 ;
return sprintf ( V_49 , L_2 , V_59 ) ;
}
static T_3
F_27 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
int V_61 = 8 / V_21 -> V_24 ;
return sprintf ( V_49 , L_2 , V_61 ) ;
}
static T_3 F_28 ( struct V_26 * V_6 , struct V_47 * V_48 ,
const char * V_49 , T_4 V_55 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
struct V_1 * V_2 = F_11 ( V_6 ) ;
int V_62 , V_63 = 8 / V_21 -> V_24 ;
long V_64 ;
int V_5 = F_23 ( V_49 , 10 , & V_64 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_64 == V_63 )
return V_55 ;
switch ( V_64 ) {
case 1 :
V_62 = 3 ;
break;
case 2 :
V_62 = 2 ;
break;
case 4 :
V_62 = 1 ;
break;
case 8 :
V_62 = 0 ;
break;
default:
return - V_58 ;
}
F_12 ( & V_21 -> V_27 ) ;
V_5 = F_2 ( V_2 , V_23 ) ;
if ( V_5 < 0 ) {
F_29 ( & V_2 -> V_6 , L_1 ,
V_23 , V_5 ) ;
F_14 ( & V_21 -> V_27 ) ;
return - V_65 ;
}
V_5 &= 0x9F ;
V_5 |= ( V_62 << 5 ) ;
F_7 ( V_2 , V_23 , V_5 ) ;
V_21 -> V_24 = 8 / V_64 ;
if ( ( V_21 -> V_46 & 0x1fe0 ) != 0x1fe0 ) {
T_2 V_16 = ( V_21 -> V_46 * V_63 ) / V_64 ;
V_21 -> V_46 = F_30 ( V_16 , ( T_2 ) 0x1fff ) ;
F_6 ( V_2 , V_21 -> V_46 ) ;
}
V_21 -> V_31 = false ;
F_14 ( & V_21 -> V_27 ) ;
return V_55 ;
}
static T_3
F_31 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
int V_59 = 0 ;
if ( ( V_21 -> V_46 != 0 ) && ( ( V_21 -> V_46 & 0x1fe0 ) != 0x1fe0 ) )
V_59 = ( V_60 * V_21 -> V_24 )
/ V_21 -> V_46 ;
return sprintf ( V_49 , L_2 , V_59 ) ;
}
static T_3 F_32 ( struct V_26 * V_6 , struct V_47 * V_48 ,
const char * V_49 , T_4 V_55 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
struct V_1 * V_2 = F_11 ( V_6 ) ;
long V_66 ;
int V_57 = F_23 ( V_49 , 10 , & V_66 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ( V_66 < 0 ) || ( V_66 > 16384 ) )
return - V_58 ;
F_12 ( & V_21 -> V_27 ) ;
if ( V_66 == 0 )
V_21 -> V_46 = 0x1fff ;
else
V_21 -> V_46 = F_33 (
( V_60 * V_21 -> V_24 ) / V_66 ,
0 , 0x1fff ) ;
F_6 ( V_2 , V_21 -> V_46 ) ;
F_14 ( & V_21 -> V_27 ) ;
return V_55 ;
}
static T_3
F_34 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
bool V_53 = ( ( V_21 -> V_43 & 0x1fe0 ) == 0x1fe0 ) ;
return sprintf ( V_49 , L_2 , V_53 ? 1 : 0 ) ;
}
static T_3
F_35 ( struct V_26 * V_6 , struct V_47 * V_48 , char * V_49 )
{
struct V_20 * V_21 = F_10 ( V_6 ) ;
return sprintf ( V_49 , L_2 , V_21 -> V_25 ? 3 : 0 ) ;
}
static T_3 F_36 ( struct V_26 * V_6 , struct V_47 * V_48 ,
const char * V_49 , T_4 V_55 )
{
struct V_1 * V_2 = F_11 ( V_6 ) ;
struct V_20 * V_21 = F_9 ( V_2 ) ;
long V_67 ;
T_1 V_68 ;
int V_57 = F_23 ( V_49 , 10 , & V_67 ) ;
if ( V_57 < 0 )
return V_57 ;
F_12 ( & V_21 -> V_27 ) ;
switch ( V_67 ) {
case 0 :
V_21 -> V_25 = false ;
break;
case 3 :
V_21 -> V_25 = true ;
break;
default:
V_55 = - V_58 ;
goto V_69;
}
V_57 = F_1 ( V_2 , V_23 , & V_68 ) ;
if ( V_57 ) {
V_55 = V_57 ;
goto V_69;
}
if ( V_21 -> V_25 )
V_68 |= 0x80 ;
else
V_68 &= ~ 0x80 ;
F_7 ( V_2 , V_23 , V_68 ) ;
V_69:
F_14 ( & V_21 -> V_27 ) ;
return V_55 ;
}
static int
F_37 ( struct V_1 * V_2 , const struct V_70 * V_71 )
{
struct V_20 * V_21 ;
int V_5 ;
if ( ! F_38 ( V_2 -> V_72 , V_73 ) )
return - V_65 ;
V_21 = F_39 ( & V_2 -> V_6 , sizeof( struct V_20 ) ,
V_74 ) ;
if ( ! V_21 )
return - V_75 ;
F_40 ( V_2 , V_21 ) ;
F_41 ( & V_21 -> V_27 ) ;
V_5 = F_2 ( V_2 , V_76 ) ;
if ( V_5 == 0x24 ) {
V_21 -> V_33 = 2 ;
} else {
V_5 = F_2 ( V_2 , V_77 ) ;
if ( V_5 < 0 ) {
F_29 ( & V_2 -> V_6 , L_1 , V_77 ,
V_5 ) ;
return V_5 ;
}
V_21 -> V_33 = ( V_5 & 0x01 ) ? 4 : 3 ;
if ( V_78 == 0 ) {
V_21 -> V_33 = 3 ;
V_5 &= ~ ( 0x01 ) ;
F_7 ( V_2 , V_77 , V_5 ) ;
} else if ( V_78 == 1 ) {
V_21 -> V_33 = 4 ;
V_5 |= 0x01 ;
F_7 ( V_2 , V_77 , V_5 ) ;
}
}
V_5 = F_42 ( & V_2 -> V_6 . V_79 , & V_80 ) ;
if ( V_5 )
return V_5 ;
if ( V_21 -> V_33 >= 3 ) {
V_5 = F_42 ( & V_2 -> V_6 . V_79 ,
& V_81 ) ;
if ( V_5 )
goto V_82;
}
if ( V_21 -> V_33 == 4 ) {
V_5 = F_42 ( & V_2 -> V_6 . V_79 ,
& V_83 ) ;
if ( V_5 )
goto V_84;
}
V_21 -> V_85 = F_43 ( & V_2 -> V_6 ) ;
if ( F_44 ( V_21 -> V_85 ) ) {
V_5 = F_45 ( V_21 -> V_85 ) ;
goto V_86;
}
F_46 ( & V_2 -> V_6 , L_3 ,
F_47 ( V_21 -> V_85 ) , V_2 -> V_87 ) ;
return 0 ;
V_86:
if ( V_21 -> V_33 == 4 )
F_48 ( & V_2 -> V_6 . V_79 , & V_83 ) ;
V_84:
if ( V_21 -> V_33 >= 3 )
F_48 ( & V_2 -> V_6 . V_79 , & V_81 ) ;
V_82:
F_48 ( & V_2 -> V_6 . V_79 , & V_80 ) ;
return V_5 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_9 ( V_2 ) ;
F_50 ( V_21 -> V_85 ) ;
if ( V_21 -> V_33 == 4 )
F_48 ( & V_2 -> V_6 . V_79 , & V_83 ) ;
if ( V_21 -> V_33 >= 3 )
F_48 ( & V_2 -> V_6 . V_79 , & V_81 ) ;
F_48 ( & V_2 -> V_6 . V_79 , & V_80 ) ;
return 0 ;
}
static int
F_51 ( struct V_1 * V_88 , struct V_89 * V_90 )
{
struct V_91 * V_72 = V_88 -> V_72 ;
int V_92 , V_93 ;
if ( ! F_38 ( V_72 , V_73 ) )
return - V_94 ;
V_92 = F_2 ( V_88 , V_95 ) ;
if ( V_92 != 0x5D )
return - V_94 ;
V_93 = F_2 ( V_88 , V_76 ) ;
if ( ( V_93 != 0x24 ) && ( V_93 != 0x26 ) )
return - V_94 ;
F_52 ( V_90 -> type , L_4 , V_96 ) ;
return 0 ;
}

static T_1 F_1 ( T_1 V_1 , T_2 V_2 )
{
T_2 V_3 ;
T_1 V_4 ;
if ( V_2 == 900 )
return V_1 ;
else if ( V_2 == 200 )
return V_1 ;
else if ( V_2 < 200 )
V_3 = 200 ;
else
V_3 = 900 ;
V_4 = 8192 + F_2 ( V_1 - 8192 , V_3 , V_2 ) ;
if ( V_4 < 0 )
return 0 ;
else if ( V_4 > 16383 )
return 16383 ;
else
return V_4 ;
}
int F_3 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_9 * V_10 , T_1 V_1 , struct V_11 * V_12 )
{
struct V_13 * V_14 = V_12 -> V_15 ;
T_1 V_4 = 0 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_1 ) ;
return 0 ;
}
switch ( V_14 -> V_16 . V_17 ) {
case V_18 :
switch ( V_10 -> V_19 ) {
case V_20 :
V_4 = F_1 ( V_1 , V_14 -> V_16 . V_2 ) ;
F_5 ( V_8 -> V_21 -> V_22 , V_10 -> type , V_10 -> V_19 , V_4 ) ;
return 1 ;
default:
return 0 ;
}
default:
return 0 ;
}
}
int F_6 ( struct V_5 * V_23 , struct V_24 * V_25 ,
T_3 * V_26 , int V_27 , struct V_11 * V_12 )
{
int V_28 ;
struct V_13 * V_14 = V_12 -> V_15 ;
if ( ! V_14 )
return 0 ;
if ( V_14 -> V_16 . V_29 ) {
switch ( V_14 -> V_16 . V_17 ) {
case V_30 :
V_26 [ 5 ] = V_26 [ 3 ] ;
V_26 [ 6 ] = 0x7F ;
return 1 ;
case V_31 :
case V_32 :
case V_33 :
V_26 [ 4 ] = V_26 [ 3 ] ;
V_26 [ 5 ] = 0x7F ;
return 1 ;
case V_18 :
V_26 [ 5 ] = V_26 [ 4 ] ;
V_26 [ 6 ] = 0x7F ;
return 1 ;
case V_34 :
case V_35 :
V_28 = 5 ;
break;
case V_36 :
case V_37 :
V_28 = 6 ;
break;
case V_38 :
V_28 = 3 ;
break;
default:
return 0 ;
}
V_26 [ V_28 ] = ( 0xFF + V_26 [ V_28 ] - V_26 [ V_28 + 1 ] ) >> 1 ;
V_26 [ V_28 + 1 ] = 0x7F ;
return 1 ;
}
return 0 ;
}
static void F_7 ( struct V_39 * const V_16 , const struct V_40 * V_41 ,
const struct V_42 * V_43 ,
const T_2 V_44 )
{
T_4 V_45 = 0 ;
const char * V_46 = NULL ;
const char * V_47 = NULL ;
if ( V_43 ) {
V_45 = V_43 -> V_45 ;
V_46 = V_43 -> V_46 ;
V_47 = V_43 -> V_47 ;
}
{
struct V_39 V_48 = { . V_17 = V_41 -> V_17 ,
. V_44 = V_44 ,
. V_29 = 0 ,
. V_49 = V_41 -> V_49 ,
. V_3 = V_41 -> V_3 ,
. V_50 = V_41 -> V_50 ,
. V_45 = V_45 ,
. V_46 = V_46 ,
. V_47 = V_47 } ;
memcpy ( V_16 , & V_48 , sizeof( V_48 ) ) ;
}
}
static int F_8 ( struct V_51 * V_52 , void * V_53 , struct V_54 * V_55 )
{
struct V_5 * V_6 = F_9 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_56 ;
T_1 * V_1 ;
int V_57 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_58 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_58 ;
}
V_1 = V_14 -> V_25 -> V_8 [ 0 ] -> V_1 ;
#define F_11 ( V_57 ) do { if (x < 0) x = 0; else if (x > 0xff) x = 0xff; } while (0)
switch ( V_55 -> type ) {
case V_59 :
V_57 = V_55 -> V_60 . V_61 . V_62 + 0x80 ;
F_11 ( V_57 ) ;
F_12 ( & V_14 -> V_63 , V_56 ) ;
if ( V_57 == 0x80 ) {
V_1 [ 0 ] = 0x13 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
return 0 ;
}
V_1 [ 0 ] = 0x11 ;
V_1 [ 1 ] = 0x08 ;
V_1 [ 2 ] = V_57 ;
V_1 [ 3 ] = 0x80 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
break;
}
return 0 ;
}
static void F_15 ( struct V_51 * V_52 , T_2 V_65 )
{
struct V_5 * V_6 = F_9 ( V_52 ) ;
struct V_66 * V_67 = & V_6 -> V_68 [ V_69 ] . V_67 ;
struct V_24 * V_25 = F_16 ( V_67 -> V_70 , struct V_24 , V_71 ) ;
T_1 * V_1 = V_25 -> V_8 [ 0 ] -> V_1 ;
T_4 V_72 , V_73 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_56 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_25 -> V_8 [ 0 ] -> V_1 ;
F_12 ( & V_14 -> V_63 , V_56 ) ;
if ( V_65 == 0 ) {
V_1 [ 0 ] = 0xf5 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
return;
}
if ( V_65 <= 0xaaaa ) {
V_72 = 0x0c * V_65 ;
V_73 = 0x80 * V_65 ;
} else {
V_72 = ( 0x0c * 0xaaaa ) + 0x06 * ( V_65 - 0xaaaa ) ;
V_73 = ( 0x80 * 0xaaaa ) + 0xff * ( V_65 - 0xaaaa ) ;
}
switch ( V_14 -> V_16 . V_17 ) {
case V_32 :
case V_33 :
break;
default:
V_72 = V_72 >> 1 ;
break;
}
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x0d ;
V_1 [ 2 ] = V_72 / 0xaaaa ;
V_1 [ 3 ] = V_72 / 0xaaaa ;
V_1 [ 4 ] = V_73 / 0xaaaa ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
V_1 [ 0 ] = 0x14 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
}
static void F_17 ( struct V_51 * V_52 , T_2 V_65 )
{
struct V_5 * V_6 = F_9 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_56 ;
T_1 * V_1 ;
V_65 = V_65 * 90 / 65535 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_25 -> V_8 [ 0 ] -> V_1 ;
F_12 ( & V_14 -> V_63 , V_56 ) ;
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_65 >> 14 ;
V_1 [ 3 ] = V_65 >> 14 ;
V_1 [ 4 ] = V_65 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
}
static void F_18 ( struct V_5 * V_6 , T_2 V_2 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_56 ;
T_1 * V_1 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_25 -> V_8 [ 0 ] -> V_1 ;
F_19 ( L_4 , V_2 ) ;
F_12 ( & V_14 -> V_63 , V_56 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x81 ;
V_1 [ 2 ] = V_2 & 0x00ff ;
V_1 [ 3 ] = ( V_2 & 0xff00 ) >> 8 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
}
static void F_20 ( struct V_5 * V_6 , T_2 V_2 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_56 ;
int V_74 , V_75 , V_76 ;
T_1 * V_1 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_25 -> V_8 [ 0 ] -> V_1 ;
F_19 ( L_5 , V_2 ) ;
F_12 ( & V_14 -> V_63 , V_56 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 > 200 ) {
V_1 [ 1 ] = 0x03 ;
V_76 = 900 ;
} else {
V_1 [ 1 ] = 0x02 ;
V_76 = 200 ;
}
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
V_1 [ 0 ] = 0x81 ;
V_1 [ 1 ] = 0x0b ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 == 200 || V_2 == 900 ) {
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
return;
}
V_74 = ( ( ( V_76 - V_2 + 1 ) * 2047 ) / V_76 ) ;
V_75 = 0xfff - V_74 ;
V_1 [ 2 ] = V_74 >> 4 ;
V_1 [ 3 ] = V_75 >> 4 ;
V_1 [ 4 ] = 0xff ;
V_1 [ 5 ] = ( V_75 & 0xe ) << 4 | ( V_74 & 0xe ) ;
V_1 [ 6 ] = 0xff ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
}
static const struct V_77 * F_21 ( const T_2 V_44 , const T_2 V_78 )
{
switch ( V_44 ) {
case V_18 :
switch ( V_78 ) {
case V_18 :
return & V_79 ;
default:
return NULL ;
}
break;
case V_34 :
switch ( V_78 ) {
case V_18 :
return & V_79 ;
case V_34 :
return & V_80 ;
default:
return NULL ;
}
break;
case V_35 :
switch ( V_78 ) {
case V_30 :
return & V_81 ;
case V_18 :
return & V_82 ;
case V_34 :
return & V_83 ;
case V_35 :
return & V_84 ;
default:
return NULL ;
}
break;
case V_37 :
switch ( V_78 ) {
case V_18 :
return & V_82 ;
case V_36 :
return & V_85 ;
case V_34 :
return & V_83 ;
case V_35 :
return & V_84 ;
case V_37 :
return & V_86 ;
default:
return NULL ;
}
break;
case V_36 :
switch ( V_78 ) {
case V_30 :
return & V_81 ;
case V_18 :
return & V_82 ;
case V_36 :
return & V_85 ;
default:
return NULL ;
}
break;
default:
return NULL ;
}
}
static int F_22 ( struct V_5 * V_6 , const struct V_77 * V_87 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_56 ;
T_1 * V_1 ;
T_3 V_88 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_58 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_58 ;
}
V_1 = V_14 -> V_25 -> V_8 [ 0 ] -> V_1 ;
F_12 ( & V_14 -> V_63 , V_56 ) ;
for ( V_88 = 0 ; V_88 < V_87 -> V_89 ; V_88 ++ ) {
T_3 V_90 ;
for ( V_90 = 0 ; V_90 < 7 ; V_90 ++ )
V_1 [ V_90 ] = V_87 -> V_91 [ V_90 + ( 7 * V_88 ) ] ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
}
F_14 ( & V_14 -> V_63 , V_56 ) ;
F_23 ( V_6 ) ;
return 0 ;
}
static T_5 F_24 ( struct V_92 * V_52 , struct V_93 * V_94 , char * V_95 )
{
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_5 V_96 = 0 ;
int V_88 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
if ( ! V_14 -> V_16 . V_47 ) {
F_4 ( V_6 , L_6 ) ;
return 0 ;
}
for ( V_88 = 0 ; V_88 < V_97 ; V_88 ++ ) {
if ( V_14 -> V_16 . V_45 & F_26 ( V_88 ) ) {
V_96 += F_27 ( V_95 + V_96 , V_98 - V_96 , L_7 ,
V_99 [ V_88 ] . V_100 ,
! V_99 [ V_88 ] . V_17 ? V_14 -> V_16 . V_47 : V_99 [ V_88 ] . V_101 ) ;
if ( V_96 >= V_98 - 1 )
return V_96 ;
if ( V_99 [ V_88 ] . V_17 == V_14 -> V_16 . V_17 ||
( V_99 [ V_88 ] . V_17 == 0 && V_14 -> V_16 . V_17 == V_14 -> V_16 . V_44 ) )
V_96 += F_27 ( V_95 + V_96 , V_98 - V_96 , L_8 ) ;
else
V_96 += F_27 ( V_95 + V_96 , V_98 - V_96 , L_9 ) ;
if ( V_96 >= V_98 - 1 )
return V_96 ;
}
}
return V_96 ;
}
static T_5 F_28 ( struct V_92 * V_52 , struct V_93 * V_94 , const char * V_95 , T_6 V_96 )
{
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
const struct V_77 * V_87 ;
T_2 V_78 = 0 ;
int V_88 , V_102 ;
char * V_103 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_58 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_58 ;
}
V_103 = F_29 ( V_104 , L_10 , V_95 ) ;
if ( ! V_103 )
return - V_105 ;
V_88 = strlen ( V_103 ) ;
if ( V_103 [ V_88 - 1 ] == '\n' ) {
if ( V_88 == 1 ) {
F_30 ( V_103 ) ;
return - V_58 ;
}
V_103 [ V_88 - 1 ] = '\0' ;
}
for ( V_88 = 0 ; V_88 < V_97 ; V_88 ++ ) {
const T_2 V_106 = V_99 [ V_88 ] . V_17 ;
const char * V_100 = V_99 [ V_88 ] . V_100 ;
if ( V_14 -> V_16 . V_45 & F_26 ( V_88 ) ) {
if ( ! strcmp ( V_100 , V_103 ) ) {
if ( ! V_106 )
V_78 = V_14 -> V_16 . V_44 ;
else
V_78 = V_106 ;
break;
}
}
}
if ( V_88 == V_97 ) {
F_31 ( V_6 , L_11 , V_103 ) ;
F_30 ( V_103 ) ;
return - V_58 ;
}
F_30 ( V_103 ) ;
if ( V_78 == V_14 -> V_16 . V_17 )
return V_96 ;
if ( V_78 == V_30 && ! V_107 ) {
F_31 ( V_6 , L_12 ,
V_14 -> V_16 . V_47 ) ;
return - V_58 ;
}
if ( ( V_14 -> V_16 . V_44 == V_18 || V_14 -> V_16 . V_44 == V_34 ) &&
V_14 -> V_16 . V_17 > V_78 ) {
F_31 ( V_6 , L_13 , V_14 -> V_16 . V_47 , V_99 [ V_88 ] . V_101 ) ;
return - V_58 ;
}
V_87 = F_21 ( V_14 -> V_16 . V_44 , V_78 ) ;
if ( ! V_87 ) {
F_4 ( V_6 , L_14 , V_78 ) ;
return - V_58 ;
}
V_102 = F_22 ( V_6 , V_87 ) ;
return ( V_102 == 0 ? V_96 : V_102 ) ;
}
static T_5 F_32 ( struct V_92 * V_52 , struct V_93 * V_94 ,
char * V_95 )
{
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_96 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
V_96 = F_27 ( V_95 , V_98 , L_15 , V_14 -> V_16 . V_29 ) ;
return V_96 ;
}
static T_5 F_33 ( struct V_92 * V_52 , struct V_93 * V_94 ,
const char * V_95 , T_6 V_96 )
{
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_2 V_29 = F_34 ( V_95 , NULL , 10 ) ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_58 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_58 ;
}
if ( V_29 > 1 )
V_29 = 1 ;
V_14 -> V_16 . V_29 = V_29 ;
return V_96 ;
}
static T_5 F_35 ( struct V_92 * V_52 , struct V_93 * V_94 ,
char * V_95 )
{
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_96 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
V_96 = F_27 ( V_95 , V_98 , L_15 , V_14 -> V_16 . V_2 ) ;
return V_96 ;
}
static T_5 F_36 ( struct V_92 * V_52 , struct V_93 * V_94 ,
const char * V_95 , T_6 V_96 )
{
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_2 V_2 = F_34 ( V_95 , NULL , 10 ) ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_58 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_58 ;
}
if ( V_2 == 0 )
V_2 = V_14 -> V_16 . V_3 ;
if ( V_14 -> V_16 . V_50 && V_2 >= V_14 -> V_16 . V_49 && V_2 <= V_14 -> V_16 . V_3 ) {
V_14 -> V_16 . V_50 ( V_6 , V_2 ) ;
V_14 -> V_16 . V_2 = V_2 ;
}
return V_96 ;
}
static T_5 F_37 ( struct V_92 * V_52 , struct V_93 * V_94 , char * V_95 )
{
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_96 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
if ( ! V_14 -> V_16 . V_46 || ! V_14 -> V_16 . V_47 ) {
F_4 ( V_6 , L_6 ) ;
return 0 ;
}
V_96 = F_27 ( V_95 , V_98 , L_16 , V_14 -> V_16 . V_46 , V_14 -> V_16 . V_47 ) ;
return V_96 ;
}
static T_5 F_38 ( struct V_92 * V_52 , struct V_93 * V_94 , const char * V_95 , T_6 V_96 )
{
return - V_108 ;
}
static void F_39 ( struct V_5 * V_6 , T_3 V_109 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned long V_56 ;
T_1 * V_1 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_25 -> V_8 [ 0 ] -> V_1 ;
F_12 ( & V_14 -> V_63 , V_56 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x12 ;
V_1 [ 2 ] = V_109 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_13 ( V_6 , V_14 -> V_25 , V_64 ) ;
F_14 ( & V_14 -> V_63 , V_56 ) ;
}
static void F_40 ( struct V_110 * V_111 ,
enum V_112 V_1 )
{
struct V_92 * V_52 = V_111 -> V_52 -> V_113 ;
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_11 * V_12 = F_10 ( V_6 ) ;
struct V_13 * V_14 ;
int V_88 , V_114 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_17 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_18 ) ;
return;
}
for ( V_88 = 0 ; V_88 < 5 ; V_88 ++ ) {
if ( V_111 != V_14 -> V_16 . V_115 [ V_88 ] )
continue;
V_114 = ( V_14 -> V_16 . V_116 >> V_88 ) & 1 ;
if ( V_1 == V_117 && V_114 ) {
V_14 -> V_16 . V_116 &= ~ ( 1 << V_88 ) ;
F_39 ( V_6 , V_14 -> V_16 . V_116 ) ;
} else if ( V_1 != V_117 && ! V_114 ) {
V_14 -> V_16 . V_116 |= 1 << V_88 ;
F_39 ( V_6 , V_14 -> V_16 . V_116 ) ;
}
break;
}
}
static enum V_112 F_41 ( struct V_110 * V_111 )
{
struct V_92 * V_52 = V_111 -> V_52 -> V_113 ;
struct V_5 * V_6 = F_25 ( V_52 ) ;
struct V_11 * V_12 = F_10 ( V_6 ) ;
struct V_13 * V_14 ;
int V_88 , V_1 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_17 ) ;
return V_117 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_18 ) ;
return V_117 ;
}
for ( V_88 = 0 ; V_88 < 5 ; V_88 ++ )
if ( V_111 == V_14 -> V_16 . V_115 [ V_88 ] ) {
V_1 = ( V_14 -> V_16 . V_116 >> V_88 ) & 1 ;
break;
}
return V_1 ? V_118 : V_117 ;
}
static T_2 F_42 ( struct V_5 * V_6 , const T_2 V_119 , const T_2 V_120 )
{
T_4 V_121 ;
int V_88 ;
for ( V_88 = 1 ; V_88 < F_43 ( V_99 ) ; V_88 ++ ) {
F_19 ( L_19 , V_99 [ V_88 ] . V_17 ) ;
if ( V_119 == V_99 [ V_88 ] . V_17 )
break;
}
if ( V_88 == F_43 ( V_99 ) )
return 0 ;
V_121 = F_26 ( V_88 ) ;
for ( V_88 = 0 ; V_88 < F_43 ( V_122 ) ; V_88 ++ ) {
const T_2 V_123 = V_122 [ V_88 ] -> V_123 ;
const T_2 V_124 = V_122 [ V_88 ] -> V_124 ;
const T_2 V_44 = V_122 [ V_88 ] -> V_44 ;
if ( ( V_121 & V_122 [ V_88 ] -> V_125 ) && \
( V_120 & V_123 ) == V_124 ) {
F_19 ( L_20 , V_44 , V_119 ) ;
return V_44 ;
}
}
F_19 ( L_21 , V_120 ) ;
return 0 ;
}
static int F_44 ( struct V_5 * V_6 , T_2 * V_44 , const T_2 V_120 )
{
const T_2 V_119 = V_6 -> V_126 ;
int V_102 ;
* V_44 = F_42 ( V_6 , V_119 , V_120 ) ;
if ( ! * V_44 ) {
* V_44 = V_119 ;
F_19 ( L_22 ) ;
return V_127 ;
}
if ( V_119 == V_30 &&
V_119 != * V_44 &&
! V_107 ) {
const struct V_77 * V_87 = F_21 ( * V_44 , * V_44 ) ;
if ( ! V_87 ) {
F_4 ( V_6 , L_23 , * V_44 ) ;
return V_127 ;
}
V_102 = F_22 ( V_6 , V_87 ) ;
if ( V_102 ) {
F_4 ( V_6 , L_24 , V_102 ) ;
return V_128 ;
}
return V_129 ;
}
return V_128 ;
}
int F_45 ( struct V_5 * V_6 )
{
struct V_130 * V_21 = F_16 ( V_6 -> V_131 . V_70 , struct V_130 , V_71 ) ;
struct V_51 * V_52 = V_21 -> V_22 ;
struct V_66 * V_67 = & V_6 -> V_68 [ V_69 ] . V_67 ;
struct V_24 * V_25 = F_16 ( V_67 -> V_70 , struct V_24 , V_71 ) ;
const struct V_132 * V_133 = & ( F_46 ( V_6 ) -> V_134 ) ;
const T_2 V_120 = F_47 ( V_133 -> V_120 ) ;
const struct V_42 * V_43 = NULL ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
int error , V_88 , V_90 ;
int V_135 , V_136 = - 1 ;
T_2 V_44 ;
if ( ! F_48 ( V_6 , V_69 , 0 , 0 , 7 ) )
return - 1 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_25 ) ;
return - 1 ;
}
V_14 = F_49 ( sizeof( * V_14 ) , V_104 ) ;
if ( ! V_14 )
return - V_105 ;
F_50 ( & V_14 -> V_63 ) ;
V_14 -> V_25 = V_25 ;
V_12 -> V_15 = V_14 ;
V_135 = F_44 ( V_6 , & V_44 , V_120 ) ;
if ( V_135 == V_129 )
return 0 ;
else if ( V_135 < 0 ) {
F_4 ( V_6 , L_26 , V_135 ) ;
error = V_135 ;
goto V_137;
}
for ( V_88 = 0 ; V_88 < F_43 ( V_138 ) ; V_88 ++ ) {
if ( V_6 -> V_126 == V_138 [ V_88 ] . V_17 ) {
F_19 ( L_27 , V_138 [ V_88 ] . V_17 ) ;
break;
}
}
if ( V_88 == F_43 ( V_138 ) ) {
F_4 ( V_6 , L_28
L_29
L_30 ) ;
error = - 1 ;
goto V_137;
}
if ( V_135 == V_128 ) {
for ( V_136 = 0 ; V_136 < F_43 ( V_139 ) ; V_136 ++ ) {
if ( V_44 == V_139 [ V_136 ] . V_17 )
break;
}
if ( V_136 == F_43 ( V_139 ) ) {
F_4 ( V_6 , L_31 , V_44 ) ;
error = - 1 ;
goto V_137;
}
}
for ( V_90 = 0 ; V_138 [ V_88 ] . V_140 [ V_90 ] >= 0 ; V_90 ++ )
F_51 ( V_138 [ V_88 ] . V_140 [ V_90 ] , V_52 -> V_141 ) ;
error = F_52 ( V_52 , NULL , F_8 ) ;
if ( error )
goto V_137;
if ( V_135 == V_128 ) {
F_53 ( V_136 == - 1 ) ;
V_43 = & V_139 [ V_136 ] ;
}
F_7 ( & V_14 -> V_16 , & V_138 [ V_88 ] , V_43 , V_44 ) ;
if ( F_54 ( V_142 , V_52 -> V_141 ) ) {
if ( ( V_120 >> 8 ) == V_143 &&
( V_120 & 0xff ) == V_144 )
V_52 -> V_145 -> V_146 = F_17 ;
else
V_52 -> V_145 -> V_146 = F_15 ;
V_52 -> V_145 -> V_146 ( V_52 , 0 ) ;
}
error = F_55 ( & V_6 -> V_52 , & V_147 ) ;
if ( error )
F_56 ( V_6 , L_32 , error ) ;
error = F_55 ( & V_6 -> V_52 , & V_148 ) ;
if ( error )
F_56 ( V_6 , L_33 , error ) ;
if ( V_135 == V_128 ) {
error = F_55 ( & V_6 -> V_52 , & V_149 ) ;
if ( error )
F_56 ( V_6 , L_34 , error ) ;
error = F_55 ( & V_6 -> V_52 , & V_150 ) ;
if ( error )
F_56 ( V_6 , L_35 , error ) ;
}
F_19 ( L_36 ) ;
V_14 -> V_16 . V_2 = V_14 -> V_16 . V_3 ;
if ( V_14 -> V_16 . V_50 )
V_14 -> V_16 . V_50 ( V_6 , V_14 -> V_16 . V_2 ) ;
#ifdef F_57
V_14 -> V_16 . V_116 = 0 ;
for ( V_90 = 0 ; V_90 < 5 ; V_90 ++ )
V_14 -> V_16 . V_115 [ V_90 ] = NULL ;
if ( V_138 [ V_88 ] . V_17 == V_35 ||
V_138 [ V_88 ] . V_17 == V_37 ) {
struct V_110 * V_115 ;
T_6 V_151 ;
char * V_101 ;
F_39 ( V_6 , 0 ) ;
V_151 = strlen ( F_58 ( & V_6 -> V_52 ) ) + 8 ;
for ( V_90 = 0 ; V_90 < 5 ; V_90 ++ ) {
V_115 = F_49 ( sizeof( struct V_110 ) + V_151 , V_104 ) ;
if ( ! V_115 ) {
F_4 ( V_6 , L_37 , V_90 ) ;
goto V_152;
}
V_101 = ( void * ) ( & V_115 [ 1 ] ) ;
snprintf ( V_101 , V_151 , L_38 , F_58 ( & V_6 -> V_52 ) , V_90 + 1 ) ;
V_115 -> V_101 = V_101 ;
V_115 -> V_153 = 0 ;
V_115 -> V_154 = 1 ;
V_115 -> V_155 = F_41 ;
V_115 -> V_156 = F_40 ;
V_14 -> V_16 . V_115 [ V_90 ] = V_115 ;
error = F_59 ( & V_6 -> V_52 , V_115 ) ;
if ( error ) {
F_4 ( V_6 , L_39 , V_90 ) ;
V_152:
for ( V_90 = 0 ; V_90 < 5 ; V_90 ++ ) {
V_115 = V_14 -> V_16 . V_115 [ V_90 ] ;
V_14 -> V_16 . V_115 [ V_90 ] = NULL ;
if ( ! V_115 )
continue;
F_60 ( V_115 ) ;
F_30 ( V_115 ) ;
}
goto V_157;
}
}
}
V_157:
#endif
F_31 ( V_6 , L_40 ) ;
return 0 ;
V_137:
V_12 -> V_15 = NULL ;
F_30 ( V_14 ) ;
return error ;
}
int F_61 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_12 = F_10 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_41 ) ;
return - 1 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 )
goto V_157;
if ( V_14 -> V_16 . V_45 ) {
F_62 ( & V_6 -> V_52 , & V_149 ) ;
F_62 ( & V_6 -> V_52 , & V_150 ) ;
}
F_62 ( & V_6 -> V_52 , & V_147 ) ;
F_62 ( & V_6 -> V_52 , & V_148 ) ;
#ifdef F_57
{
int V_90 ;
struct V_110 * V_115 ;
for ( V_90 = 0 ; V_90 < 5 ; V_90 ++ ) {
V_115 = V_14 -> V_16 . V_115 [ V_90 ] ;
V_14 -> V_16 . V_115 [ V_90 ] = NULL ;
if ( ! V_115 )
continue;
F_60 ( V_115 ) ;
F_30 ( V_115 ) ;
}
}
#endif
F_63 ( V_6 ) ;
V_12 -> V_15 = NULL ;
F_30 ( V_14 ) ;
V_157:
F_19 ( L_42 ) ;
return 0 ;
}

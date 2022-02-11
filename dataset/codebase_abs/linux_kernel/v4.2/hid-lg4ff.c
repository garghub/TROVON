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
static void F_6 ( struct V_23 * const V_16 , const struct V_24 * V_25 ,
const struct V_26 * V_27 ,
const T_2 V_28 )
{
T_3 V_29 = 0 ;
const char * V_30 = NULL ;
const char * V_31 = NULL ;
if ( V_27 ) {
V_29 = V_27 -> V_29 ;
V_30 = V_27 -> V_30 ;
V_31 = V_27 -> V_31 ;
}
{
struct V_23 V_32 = { . V_17 = V_25 -> V_17 ,
. V_28 = V_28 ,
. V_33 = V_25 -> V_33 ,
. V_3 = V_25 -> V_3 ,
. V_34 = V_25 -> V_34 ,
. V_29 = V_29 ,
. V_30 = V_30 ,
. V_31 = V_31 } ;
memcpy ( V_16 , & V_32 , sizeof( V_32 ) ) ;
}
}
static int F_7 ( struct V_35 * V_36 , void * V_37 , struct V_38 * V_39 )
{
struct V_5 * V_6 = F_8 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_40 ;
T_1 * V_1 ;
int V_41 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_42 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_42 ;
}
V_1 = V_14 -> V_43 -> V_8 [ 0 ] -> V_1 ;
#define F_10 ( V_41 ) do { if (x < 0) x = 0; else if (x > 0xff) x = 0xff; } while (0)
switch ( V_39 -> type ) {
case V_44 :
V_41 = V_39 -> V_45 . V_46 . V_47 + 0x80 ;
F_10 ( V_41 ) ;
F_11 ( & V_14 -> V_48 , V_40 ) ;
if ( V_41 == 0x80 ) {
V_1 [ 0 ] = 0x13 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
return 0 ;
}
V_1 [ 0 ] = 0x11 ;
V_1 [ 1 ] = 0x08 ;
V_1 [ 2 ] = V_41 ;
V_1 [ 3 ] = 0x80 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
break;
}
return 0 ;
}
static void F_14 ( struct V_35 * V_36 , T_2 V_50 )
{
struct V_5 * V_6 = F_8 ( V_36 ) ;
struct V_51 * V_52 = & V_6 -> V_53 [ V_54 ] . V_52 ;
struct V_55 * V_43 = F_15 ( V_52 -> V_56 , struct V_55 , V_57 ) ;
T_1 * V_1 = V_43 -> V_8 [ 0 ] -> V_1 ;
T_3 V_58 , V_59 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_40 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_43 -> V_8 [ 0 ] -> V_1 ;
F_11 ( & V_14 -> V_48 , V_40 ) ;
if ( V_50 == 0 ) {
V_1 [ 0 ] = 0xf5 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
return;
}
if ( V_50 <= 0xaaaa ) {
V_58 = 0x0c * V_50 ;
V_59 = 0x80 * V_50 ;
} else {
V_58 = ( 0x0c * 0xaaaa ) + 0x06 * ( V_50 - 0xaaaa ) ;
V_59 = ( 0x80 * 0xaaaa ) + 0xff * ( V_50 - 0xaaaa ) ;
}
switch ( V_14 -> V_16 . V_17 ) {
case V_60 :
case V_61 :
break;
default:
V_58 = V_58 >> 1 ;
break;
}
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x0d ;
V_1 [ 2 ] = V_58 / 0xaaaa ;
V_1 [ 3 ] = V_58 / 0xaaaa ;
V_1 [ 4 ] = V_59 / 0xaaaa ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
V_1 [ 0 ] = 0x14 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
}
static void F_16 ( struct V_35 * V_36 , T_2 V_50 )
{
struct V_5 * V_6 = F_8 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_40 ;
T_1 * V_1 ;
V_50 = V_50 * 90 / 65535 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_43 -> V_8 [ 0 ] -> V_1 ;
F_11 ( & V_14 -> V_48 , V_40 ) ;
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_50 >> 14 ;
V_1 [ 3 ] = V_50 >> 14 ;
V_1 [ 4 ] = V_50 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
}
static void F_17 ( struct V_5 * V_6 , T_2 V_2 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_40 ;
T_1 * V_1 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_43 -> V_8 [ 0 ] -> V_1 ;
F_18 ( L_4 , V_2 ) ;
F_11 ( & V_14 -> V_48 , V_40 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x81 ;
V_1 [ 2 ] = V_2 & 0x00ff ;
V_1 [ 3 ] = ( V_2 & 0xff00 ) >> 8 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
}
static void F_19 ( struct V_5 * V_6 , T_2 V_2 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_40 ;
int V_62 , V_63 , V_64 ;
T_1 * V_1 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_43 -> V_8 [ 0 ] -> V_1 ;
F_18 ( L_5 , V_2 ) ;
F_11 ( & V_14 -> V_48 , V_40 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 > 200 ) {
V_1 [ 1 ] = 0x03 ;
V_64 = 900 ;
} else {
V_1 [ 1 ] = 0x02 ;
V_64 = 200 ;
}
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
V_1 [ 0 ] = 0x81 ;
V_1 [ 1 ] = 0x0b ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 == 200 || V_2 == 900 ) {
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
return;
}
V_62 = ( ( ( V_64 - V_2 + 1 ) * 2047 ) / V_64 ) ;
V_63 = 0xfff - V_62 ;
V_1 [ 2 ] = V_62 >> 4 ;
V_1 [ 3 ] = V_63 >> 4 ;
V_1 [ 4 ] = 0xff ;
V_1 [ 5 ] = ( V_63 & 0xe ) << 4 | ( V_62 & 0xe ) ;
V_1 [ 6 ] = 0xff ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
}
static const struct V_65 * F_20 ( const T_2 V_28 , const T_2 V_66 )
{
switch ( V_28 ) {
case V_18 :
switch ( V_66 ) {
case V_18 :
return & V_67 ;
default:
return NULL ;
}
break;
case V_68 :
switch ( V_66 ) {
case V_18 :
return & V_67 ;
case V_68 :
return & V_69 ;
default:
return NULL ;
}
break;
case V_70 :
switch ( V_66 ) {
case V_71 :
return & V_72 ;
case V_18 :
return & V_73 ;
case V_68 :
return & V_74 ;
case V_70 :
return & V_75 ;
default:
return NULL ;
}
break;
case V_76 :
switch ( V_66 ) {
case V_71 :
return & V_72 ;
case V_18 :
return & V_73 ;
case V_76 :
return & V_77 ;
default:
return NULL ;
}
break;
default:
return NULL ;
}
}
static int F_21 ( struct V_5 * V_6 , const struct V_65 * V_78 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_40 ;
T_1 * V_1 ;
T_4 V_79 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_42 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_42 ;
}
V_1 = V_14 -> V_43 -> V_8 [ 0 ] -> V_1 ;
F_11 ( & V_14 -> V_48 , V_40 ) ;
for ( V_79 = 0 ; V_79 < V_78 -> V_80 ; V_79 ++ ) {
T_4 V_81 ;
for ( V_81 = 0 ; V_81 < 7 ; V_81 ++ )
V_1 [ V_81 ] = V_78 -> V_82 [ V_81 + ( 7 * V_79 ) ] ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
}
F_13 ( & V_14 -> V_48 , V_40 ) ;
F_22 ( V_6 ) ;
return 0 ;
}
static T_5 F_23 ( struct V_83 * V_36 , struct V_84 * V_85 , char * V_86 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_5 V_87 = 0 ;
int V_79 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
if ( ! V_14 -> V_16 . V_31 ) {
F_4 ( V_6 , L_6 ) ;
return 0 ;
}
for ( V_79 = 0 ; V_79 < V_88 ; V_79 ++ ) {
if ( V_14 -> V_16 . V_29 & F_25 ( V_79 ) ) {
V_87 += F_26 ( V_86 + V_87 , V_89 - V_87 , L_7 ,
V_90 [ V_79 ] . V_91 ,
! V_90 [ V_79 ] . V_17 ? V_14 -> V_16 . V_31 : V_90 [ V_79 ] . V_92 ) ;
if ( V_87 >= V_89 - 1 )
return V_87 ;
if ( V_90 [ V_79 ] . V_17 == V_14 -> V_16 . V_17 ||
( V_90 [ V_79 ] . V_17 == 0 && V_14 -> V_16 . V_17 == V_14 -> V_16 . V_28 ) )
V_87 += F_26 ( V_86 + V_87 , V_89 - V_87 , L_8 ) ;
else
V_87 += F_26 ( V_86 + V_87 , V_89 - V_87 , L_9 ) ;
if ( V_87 >= V_89 - 1 )
return V_87 ;
}
}
return V_87 ;
}
static T_5 F_27 ( struct V_83 * V_36 , struct V_84 * V_85 , const char * V_86 , T_6 V_87 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
const struct V_65 * V_78 ;
T_2 V_66 = 0 ;
int V_79 , V_93 ;
char * V_94 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_42 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_42 ;
}
V_94 = F_28 ( V_95 , L_10 , V_86 ) ;
if ( ! V_94 )
return - V_96 ;
V_79 = strlen ( V_94 ) ;
if ( V_94 [ V_79 - 1 ] == '\n' ) {
if ( V_79 == 1 ) {
F_29 ( V_94 ) ;
return - V_42 ;
}
V_94 [ V_79 - 1 ] = '\0' ;
}
for ( V_79 = 0 ; V_79 < V_88 ; V_79 ++ ) {
const T_2 V_97 = V_90 [ V_79 ] . V_17 ;
const char * V_91 = V_90 [ V_79 ] . V_91 ;
if ( V_14 -> V_16 . V_29 & F_25 ( V_79 ) ) {
if ( ! strcmp ( V_91 , V_94 ) ) {
if ( ! V_97 )
V_66 = V_14 -> V_16 . V_28 ;
else
V_66 = V_97 ;
break;
}
}
}
if ( V_79 == V_88 ) {
F_30 ( V_6 , L_11 , V_94 ) ;
F_29 ( V_94 ) ;
return - V_42 ;
}
F_29 ( V_94 ) ;
if ( V_66 == V_14 -> V_16 . V_17 )
return V_87 ;
if ( V_66 == V_71 && ! V_98 ) {
F_30 ( V_6 , L_12 ,
V_14 -> V_16 . V_31 ) ;
return - V_42 ;
}
if ( ( V_14 -> V_16 . V_28 == V_18 || V_14 -> V_16 . V_28 == V_68 ) &&
V_14 -> V_16 . V_17 > V_66 ) {
F_30 ( V_6 , L_13 , V_14 -> V_16 . V_31 , V_90 [ V_79 ] . V_92 ) ;
return - V_42 ;
}
V_78 = F_20 ( V_14 -> V_16 . V_28 , V_66 ) ;
if ( ! V_78 ) {
F_4 ( V_6 , L_14 , V_66 ) ;
return - V_42 ;
}
V_93 = F_21 ( V_6 , V_78 ) ;
return ( V_93 == 0 ? V_87 : V_93 ) ;
}
static T_5 F_31 ( struct V_83 * V_36 , struct V_84 * V_85 ,
char * V_86 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_87 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
V_87 = F_26 ( V_86 , V_89 , L_15 , V_14 -> V_16 . V_2 ) ;
return V_87 ;
}
static T_5 F_32 ( struct V_83 * V_36 , struct V_84 * V_85 ,
const char * V_86 , T_6 V_87 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_2 V_2 = F_33 ( V_86 , NULL , 10 ) ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_42 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_42 ;
}
if ( V_2 == 0 )
V_2 = V_14 -> V_16 . V_3 ;
if ( V_14 -> V_16 . V_34 && V_2 >= V_14 -> V_16 . V_33 && V_2 <= V_14 -> V_16 . V_3 ) {
V_14 -> V_16 . V_34 ( V_6 , V_2 ) ;
V_14 -> V_16 . V_2 = V_2 ;
}
return V_87 ;
}
static T_5 F_34 ( struct V_83 * V_36 , struct V_84 * V_85 , char * V_86 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_87 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
if ( ! V_14 -> V_16 . V_30 || ! V_14 -> V_16 . V_31 ) {
F_4 ( V_6 , L_6 ) ;
return 0 ;
}
V_87 = F_26 ( V_86 , V_89 , L_16 , V_14 -> V_16 . V_30 , V_14 -> V_16 . V_31 ) ;
return V_87 ;
}
static T_5 F_35 ( struct V_83 * V_36 , struct V_84 * V_85 , const char * V_86 , T_6 V_87 )
{
return - V_99 ;
}
static void F_36 ( struct V_5 * V_6 , T_4 V_100 )
{
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned long V_40 ;
T_1 * V_1 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
V_1 = V_14 -> V_43 -> V_8 [ 0 ] -> V_1 ;
F_11 ( & V_14 -> V_48 , V_40 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x12 ;
V_1 [ 2 ] = V_100 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
}
static void F_37 ( struct V_101 * V_102 ,
enum V_103 V_1 )
{
struct V_83 * V_36 = V_102 -> V_36 -> V_104 ;
struct V_5 * V_6 = F_38 ( V_36 , struct V_5 , V_36 ) ;
struct V_11 * V_12 = F_9 ( V_6 ) ;
struct V_13 * V_14 ;
int V_79 , V_105 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_17 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_18 ) ;
return;
}
for ( V_79 = 0 ; V_79 < 5 ; V_79 ++ ) {
if ( V_102 != V_14 -> V_16 . V_106 [ V_79 ] )
continue;
V_105 = ( V_14 -> V_16 . V_107 >> V_79 ) & 1 ;
if ( V_1 == V_108 && V_105 ) {
V_14 -> V_16 . V_107 &= ~ ( 1 << V_79 ) ;
F_36 ( V_6 , V_14 -> V_16 . V_107 ) ;
} else if ( V_1 != V_108 && ! V_105 ) {
V_14 -> V_16 . V_107 |= 1 << V_79 ;
F_36 ( V_6 , V_14 -> V_16 . V_107 ) ;
}
break;
}
}
static enum V_103 F_39 ( struct V_101 * V_102 )
{
struct V_83 * V_36 = V_102 -> V_36 -> V_104 ;
struct V_5 * V_6 = F_38 ( V_36 , struct V_5 , V_36 ) ;
struct V_11 * V_12 = F_9 ( V_6 ) ;
struct V_13 * V_14 ;
int V_79 , V_1 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_17 ) ;
return V_108 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_18 ) ;
return V_108 ;
}
for ( V_79 = 0 ; V_79 < 5 ; V_79 ++ )
if ( V_102 == V_14 -> V_16 . V_106 [ V_79 ] ) {
V_1 = ( V_14 -> V_16 . V_107 >> V_79 ) & 1 ;
break;
}
return V_1 ? V_109 : V_108 ;
}
static T_2 F_40 ( struct V_5 * V_6 , const T_2 V_110 , const T_2 V_111 )
{
const struct V_112 * V_113 ;
int V_79 , V_114 , V_115 ;
switch ( V_110 ) {
case V_71 :
case V_18 :
V_113 = & V_116 ;
V_114 = 0 ;
V_115 = V_113 -> V_87 - 1 ;
break;
case V_68 :
V_113 = & V_116 ;
V_114 = 0 ;
V_115 = V_113 -> V_87 - 2 ;
break;
case V_70 :
V_113 = & V_116 ;
V_114 = 1 ;
V_115 = V_113 -> V_87 - 3 ;
break;
case V_76 :
V_113 = & V_116 ;
V_114 = 0 ;
V_115 = V_113 -> V_87 - 4 ;
break;
default:
return 0 ;
}
for ( V_79 = V_114 ; V_79 <= V_115 ; V_79 ++ ) {
const T_2 V_117 = V_113 -> V_118 [ V_79 ] -> V_117 ;
const T_2 V_119 = V_113 -> V_118 [ V_79 ] -> V_119 ;
const T_2 V_28 = V_113 -> V_118 [ V_79 ] -> V_28 ;
if ( ( V_111 & V_117 ) == V_119 ) {
F_18 ( L_19 , V_28 , V_110 ) ;
return V_28 ;
}
}
F_18 ( L_20 , V_111 ) ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 , T_2 * V_28 , const T_2 V_111 )
{
const T_2 V_110 = V_6 -> V_120 ;
int V_93 ;
* V_28 = F_40 ( V_6 , V_110 , V_111 ) ;
if ( ! * V_28 ) {
* V_28 = V_110 ;
F_18 ( L_21 ) ;
return V_121 ;
}
if ( V_110 == V_71 &&
V_110 != * V_28 &&
! V_98 ) {
const struct V_65 * V_78 = F_20 ( * V_28 , * V_28 ) ;
if ( ! V_78 ) {
F_4 ( V_6 , L_22 , * V_28 ) ;
return V_121 ;
}
V_93 = F_21 ( V_6 , V_78 ) ;
if ( V_93 ) {
F_4 ( V_6 , L_23 , V_93 ) ;
return V_122 ;
}
return V_123 ;
}
return V_122 ;
}
int F_42 ( struct V_5 * V_6 )
{
struct V_124 * V_21 = F_15 ( V_6 -> V_125 . V_56 , struct V_124 , V_57 ) ;
struct V_35 * V_36 = V_21 -> V_22 ;
struct V_51 * V_52 = & V_6 -> V_53 [ V_54 ] . V_52 ;
struct V_55 * V_43 = F_15 ( V_52 -> V_56 , struct V_55 , V_57 ) ;
const struct V_126 * V_127 = & ( F_43 ( V_6 ) -> V_128 ) ;
const T_2 V_111 = F_44 ( V_127 -> V_111 ) ;
const struct V_26 * V_27 = NULL ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
int error , V_79 , V_81 ;
int V_129 , V_130 = - 1 ;
T_2 V_28 ;
if ( ! F_45 ( V_6 , V_54 , 0 , 0 , 7 ) )
return - 1 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_24 ) ;
return - 1 ;
}
V_14 = F_46 ( sizeof( * V_14 ) , V_95 ) ;
if ( ! V_14 )
return - V_96 ;
F_47 ( & V_14 -> V_48 ) ;
V_14 -> V_43 = V_43 ;
V_12 -> V_15 = V_14 ;
V_129 = F_41 ( V_6 , & V_28 , V_111 ) ;
if ( V_129 == V_123 )
return 0 ;
else if ( V_129 < 0 ) {
F_4 ( V_6 , L_25 , V_129 ) ;
error = V_129 ;
goto V_131;
}
for ( V_79 = 0 ; V_79 < F_48 ( V_132 ) ; V_79 ++ ) {
if ( V_6 -> V_120 == V_132 [ V_79 ] . V_17 ) {
F_18 ( L_26 , V_132 [ V_79 ] . V_17 ) ;
break;
}
}
if ( V_79 == F_48 ( V_132 ) ) {
F_4 ( V_6 , L_27
L_28
L_29 ) ;
error = - 1 ;
goto V_131;
}
if ( V_129 == V_122 ) {
for ( V_130 = 0 ; V_130 < F_48 ( V_133 ) ; V_130 ++ ) {
if ( V_28 == V_133 [ V_130 ] . V_17 )
break;
}
if ( V_130 == F_48 ( V_133 ) ) {
F_4 ( V_6 , L_30 , V_28 ) ;
error = - 1 ;
goto V_131;
}
}
for ( V_81 = 0 ; V_132 [ V_79 ] . V_134 [ V_81 ] >= 0 ; V_81 ++ )
F_49 ( V_132 [ V_79 ] . V_134 [ V_81 ] , V_36 -> V_135 ) ;
error = F_50 ( V_36 , NULL , F_7 ) ;
if ( error )
goto V_131;
if ( V_129 == V_122 ) {
F_51 ( V_130 == - 1 ) ;
V_27 = & V_133 [ V_130 ] ;
}
F_6 ( & V_14 -> V_16 , & V_132 [ V_79 ] , V_27 , V_28 ) ;
if ( F_52 ( V_136 , V_36 -> V_135 ) ) {
if ( ( V_111 >> 8 ) == V_137 &&
( V_111 & 0xff ) == V_138 )
V_36 -> V_139 -> V_140 = F_16 ;
else
V_36 -> V_139 -> V_140 = F_14 ;
V_36 -> V_139 -> V_140 ( V_36 , 0 ) ;
}
error = F_53 ( & V_6 -> V_36 , & V_141 ) ;
if ( error )
F_54 ( V_6 , L_31 , error ) ;
if ( V_129 == V_122 ) {
error = F_53 ( & V_6 -> V_36 , & V_142 ) ;
if ( error )
F_54 ( V_6 , L_32 , error ) ;
error = F_53 ( & V_6 -> V_36 , & V_143 ) ;
if ( error )
F_54 ( V_6 , L_33 , error ) ;
}
F_18 ( L_34 ) ;
V_14 -> V_16 . V_2 = V_14 -> V_16 . V_3 ;
if ( V_14 -> V_16 . V_34 )
V_14 -> V_16 . V_34 ( V_6 , V_14 -> V_16 . V_2 ) ;
#ifdef F_55
V_14 -> V_16 . V_107 = 0 ;
for ( V_81 = 0 ; V_81 < 5 ; V_81 ++ )
V_14 -> V_16 . V_106 [ V_81 ] = NULL ;
if ( V_132 [ V_79 ] . V_17 == V_70 ) {
struct V_101 * V_106 ;
T_6 V_144 ;
char * V_92 ;
F_36 ( V_6 , 0 ) ;
V_144 = strlen ( F_56 ( & V_6 -> V_36 ) ) + 8 ;
for ( V_81 = 0 ; V_81 < 5 ; V_81 ++ ) {
V_106 = F_46 ( sizeof( struct V_101 ) + V_144 , V_95 ) ;
if ( ! V_106 ) {
F_4 ( V_6 , L_35 , V_81 ) ;
goto V_145;
}
V_92 = ( void * ) ( & V_106 [ 1 ] ) ;
snprintf ( V_92 , V_144 , L_36 , F_56 ( & V_6 -> V_36 ) , V_81 + 1 ) ;
V_106 -> V_92 = V_92 ;
V_106 -> V_146 = 0 ;
V_106 -> V_147 = 1 ;
V_106 -> V_148 = F_39 ;
V_106 -> V_149 = F_37 ;
V_14 -> V_16 . V_106 [ V_81 ] = V_106 ;
error = F_57 ( & V_6 -> V_36 , V_106 ) ;
if ( error ) {
F_4 ( V_6 , L_37 , V_81 ) ;
V_145:
for ( V_81 = 0 ; V_81 < 5 ; V_81 ++ ) {
V_106 = V_14 -> V_16 . V_106 [ V_81 ] ;
V_14 -> V_16 . V_106 [ V_81 ] = NULL ;
if ( ! V_106 )
continue;
F_58 ( V_106 ) ;
F_29 ( V_106 ) ;
}
goto V_150;
}
}
}
V_150:
#endif
F_30 ( V_6 , L_38 ) ;
return 0 ;
V_131:
V_12 -> V_15 = NULL ;
F_29 ( V_14 ) ;
return error ;
}
int F_59 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_39 ) ;
return - 1 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 )
goto V_150;
if ( V_14 -> V_16 . V_29 ) {
F_60 ( & V_6 -> V_36 , & V_142 ) ;
F_60 ( & V_6 -> V_36 , & V_143 ) ;
}
F_60 ( & V_6 -> V_36 , & V_141 ) ;
#ifdef F_55
{
int V_81 ;
struct V_101 * V_106 ;
for ( V_81 = 0 ; V_81 < 5 ; V_81 ++ ) {
V_106 = V_14 -> V_16 . V_106 [ V_81 ] ;
V_14 -> V_16 . V_106 [ V_81 ] = NULL ;
if ( ! V_106 )
continue;
F_58 ( V_106 ) ;
F_29 ( V_106 ) ;
}
}
#endif
F_61 ( V_6 ) ;
V_12 -> V_15 = NULL ;
F_29 ( V_14 ) ;
V_150:
F_18 ( L_40 ) ;
return 0 ;
}

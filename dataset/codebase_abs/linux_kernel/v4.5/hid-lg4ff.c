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
case V_18 :
return & V_73 ;
case V_77 :
return & V_78 ;
case V_68 :
return & V_74 ;
case V_70 :
return & V_75 ;
case V_76 :
return & V_79 ;
default:
return NULL ;
}
break;
case V_77 :
switch ( V_66 ) {
case V_71 :
return & V_72 ;
case V_18 :
return & V_73 ;
case V_77 :
return & V_78 ;
default:
return NULL ;
}
break;
default:
return NULL ;
}
}
static int F_21 ( struct V_5 * V_6 , const struct V_65 * V_80 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
unsigned long V_40 ;
T_1 * V_1 ;
T_4 V_81 ;
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
for ( V_81 = 0 ; V_81 < V_80 -> V_82 ; V_81 ++ ) {
T_4 V_83 ;
for ( V_83 = 0 ; V_83 < 7 ; V_83 ++ )
V_1 [ V_83 ] = V_80 -> V_84 [ V_83 + ( 7 * V_81 ) ] ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
}
F_13 ( & V_14 -> V_48 , V_40 ) ;
F_22 ( V_6 ) ;
return 0 ;
}
static T_5 F_23 ( struct V_85 * V_36 , struct V_86 * V_87 , char * V_88 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_5 V_89 = 0 ;
int V_81 ;
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
for ( V_81 = 0 ; V_81 < V_90 ; V_81 ++ ) {
if ( V_14 -> V_16 . V_29 & F_25 ( V_81 ) ) {
V_89 += F_26 ( V_88 + V_89 , V_91 - V_89 , L_7 ,
V_92 [ V_81 ] . V_93 ,
! V_92 [ V_81 ] . V_17 ? V_14 -> V_16 . V_31 : V_92 [ V_81 ] . V_94 ) ;
if ( V_89 >= V_91 - 1 )
return V_89 ;
if ( V_92 [ V_81 ] . V_17 == V_14 -> V_16 . V_17 ||
( V_92 [ V_81 ] . V_17 == 0 && V_14 -> V_16 . V_17 == V_14 -> V_16 . V_28 ) )
V_89 += F_26 ( V_88 + V_89 , V_91 - V_89 , L_8 ) ;
else
V_89 += F_26 ( V_88 + V_89 , V_91 - V_89 , L_9 ) ;
if ( V_89 >= V_91 - 1 )
return V_89 ;
}
}
return V_89 ;
}
static T_5 F_27 ( struct V_85 * V_36 , struct V_86 * V_87 , const char * V_88 , T_6 V_89 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
const struct V_65 * V_80 ;
T_2 V_66 = 0 ;
int V_81 , V_95 ;
char * V_96 ;
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
V_96 = F_28 ( V_97 , L_10 , V_88 ) ;
if ( ! V_96 )
return - V_98 ;
V_81 = strlen ( V_96 ) ;
if ( V_96 [ V_81 - 1 ] == '\n' ) {
if ( V_81 == 1 ) {
F_29 ( V_96 ) ;
return - V_42 ;
}
V_96 [ V_81 - 1 ] = '\0' ;
}
for ( V_81 = 0 ; V_81 < V_90 ; V_81 ++ ) {
const T_2 V_99 = V_92 [ V_81 ] . V_17 ;
const char * V_93 = V_92 [ V_81 ] . V_93 ;
if ( V_14 -> V_16 . V_29 & F_25 ( V_81 ) ) {
if ( ! strcmp ( V_93 , V_96 ) ) {
if ( ! V_99 )
V_66 = V_14 -> V_16 . V_28 ;
else
V_66 = V_99 ;
break;
}
}
}
if ( V_81 == V_90 ) {
F_30 ( V_6 , L_11 , V_96 ) ;
F_29 ( V_96 ) ;
return - V_42 ;
}
F_29 ( V_96 ) ;
if ( V_66 == V_14 -> V_16 . V_17 )
return V_89 ;
if ( V_66 == V_71 && ! V_100 ) {
F_30 ( V_6 , L_12 ,
V_14 -> V_16 . V_31 ) ;
return - V_42 ;
}
if ( ( V_14 -> V_16 . V_28 == V_18 || V_14 -> V_16 . V_28 == V_68 ) &&
V_14 -> V_16 . V_17 > V_66 ) {
F_30 ( V_6 , L_13 , V_14 -> V_16 . V_31 , V_92 [ V_81 ] . V_94 ) ;
return - V_42 ;
}
V_80 = F_20 ( V_14 -> V_16 . V_28 , V_66 ) ;
if ( ! V_80 ) {
F_4 ( V_6 , L_14 , V_66 ) ;
return - V_42 ;
}
V_95 = F_21 ( V_6 , V_80 ) ;
return ( V_95 == 0 ? V_89 : V_95 ) ;
}
static T_5 F_31 ( struct V_85 * V_36 , struct V_86 * V_87 ,
char * V_88 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_89 ;
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
V_89 = F_26 ( V_88 , V_91 , L_15 , V_14 -> V_16 . V_2 ) ;
return V_89 ;
}
static T_5 F_32 ( struct V_85 * V_36 , struct V_86 * V_87 ,
const char * V_88 , T_6 V_89 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_2 V_2 = F_33 ( V_88 , NULL , 10 ) ;
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
return V_89 ;
}
static T_5 F_34 ( struct V_85 * V_36 , struct V_86 * V_87 , char * V_88 )
{
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_89 ;
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
V_89 = F_26 ( V_88 , V_91 , L_16 , V_14 -> V_16 . V_30 , V_14 -> V_16 . V_31 ) ;
return V_89 ;
}
static T_5 F_35 ( struct V_85 * V_36 , struct V_86 * V_87 , const char * V_88 , T_6 V_89 )
{
return - V_101 ;
}
static void F_36 ( struct V_5 * V_6 , T_4 V_102 )
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
V_1 [ 2 ] = V_102 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_12 ( V_6 , V_14 -> V_43 , V_49 ) ;
F_13 ( & V_14 -> V_48 , V_40 ) ;
}
static void F_37 ( struct V_103 * V_104 ,
enum V_105 V_1 )
{
struct V_85 * V_36 = V_104 -> V_36 -> V_106 ;
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_11 * V_12 = F_9 ( V_6 ) ;
struct V_13 * V_14 ;
int V_81 , V_107 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_17 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_18 ) ;
return;
}
for ( V_81 = 0 ; V_81 < 5 ; V_81 ++ ) {
if ( V_104 != V_14 -> V_16 . V_108 [ V_81 ] )
continue;
V_107 = ( V_14 -> V_16 . V_109 >> V_81 ) & 1 ;
if ( V_1 == V_110 && V_107 ) {
V_14 -> V_16 . V_109 &= ~ ( 1 << V_81 ) ;
F_36 ( V_6 , V_14 -> V_16 . V_109 ) ;
} else if ( V_1 != V_110 && ! V_107 ) {
V_14 -> V_16 . V_109 |= 1 << V_81 ;
F_36 ( V_6 , V_14 -> V_16 . V_109 ) ;
}
break;
}
}
static enum V_105 F_38 ( struct V_103 * V_104 )
{
struct V_85 * V_36 = V_104 -> V_36 -> V_106 ;
struct V_5 * V_6 = F_24 ( V_36 ) ;
struct V_11 * V_12 = F_9 ( V_6 ) ;
struct V_13 * V_14 ;
int V_81 , V_1 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_17 ) ;
return V_110 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_18 ) ;
return V_110 ;
}
for ( V_81 = 0 ; V_81 < 5 ; V_81 ++ )
if ( V_104 == V_14 -> V_16 . V_108 [ V_81 ] ) {
V_1 = ( V_14 -> V_16 . V_109 >> V_81 ) & 1 ;
break;
}
return V_1 ? V_111 : V_110 ;
}
static T_2 F_39 ( struct V_5 * V_6 , const T_2 V_112 , const T_2 V_113 )
{
T_3 V_114 ;
int V_81 ;
for ( V_81 = 1 ; V_81 < F_40 ( V_92 ) ; V_81 ++ ) {
F_18 ( L_19 , V_92 [ V_81 ] . V_17 ) ;
if ( V_112 == V_92 [ V_81 ] . V_17 )
break;
}
if ( V_81 == F_40 ( V_92 ) )
return 0 ;
V_114 = F_25 ( V_81 ) ;
for ( V_81 = 0 ; V_81 < F_40 ( V_115 ) ; V_81 ++ ) {
const T_2 V_116 = V_115 [ V_81 ] -> V_116 ;
const T_2 V_117 = V_115 [ V_81 ] -> V_117 ;
const T_2 V_28 = V_115 [ V_81 ] -> V_28 ;
if ( ( V_114 & V_115 [ V_81 ] -> V_118 ) && \
( V_113 & V_116 ) == V_117 ) {
F_18 ( L_20 , V_28 , V_112 ) ;
return V_28 ;
}
}
F_18 ( L_21 , V_113 ) ;
return 0 ;
}
static int F_41 ( struct V_5 * V_6 , T_2 * V_28 , const T_2 V_113 )
{
const T_2 V_112 = V_6 -> V_119 ;
int V_95 ;
* V_28 = F_39 ( V_6 , V_112 , V_113 ) ;
if ( ! * V_28 ) {
* V_28 = V_112 ;
F_18 ( L_22 ) ;
return V_120 ;
}
if ( V_112 == V_71 &&
V_112 != * V_28 &&
! V_100 ) {
const struct V_65 * V_80 = F_20 ( * V_28 , * V_28 ) ;
if ( ! V_80 ) {
F_4 ( V_6 , L_23 , * V_28 ) ;
return V_120 ;
}
V_95 = F_21 ( V_6 , V_80 ) ;
if ( V_95 ) {
F_4 ( V_6 , L_24 , V_95 ) ;
return V_121 ;
}
return V_122 ;
}
return V_121 ;
}
int F_42 ( struct V_5 * V_6 )
{
struct V_123 * V_21 = F_15 ( V_6 -> V_124 . V_56 , struct V_123 , V_57 ) ;
struct V_35 * V_36 = V_21 -> V_22 ;
struct V_51 * V_52 = & V_6 -> V_53 [ V_54 ] . V_52 ;
struct V_55 * V_43 = F_15 ( V_52 -> V_56 , struct V_55 , V_57 ) ;
const struct V_125 * V_126 = & ( F_43 ( V_6 ) -> V_127 ) ;
const T_2 V_113 = F_44 ( V_126 -> V_113 ) ;
const struct V_26 * V_27 = NULL ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
int error , V_81 , V_83 ;
int V_128 , V_129 = - 1 ;
T_2 V_28 ;
if ( ! F_45 ( V_6 , V_54 , 0 , 0 , 7 ) )
return - 1 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_25 ) ;
return - 1 ;
}
V_14 = F_46 ( sizeof( * V_14 ) , V_97 ) ;
if ( ! V_14 )
return - V_98 ;
F_47 ( & V_14 -> V_48 ) ;
V_14 -> V_43 = V_43 ;
V_12 -> V_15 = V_14 ;
V_128 = F_41 ( V_6 , & V_28 , V_113 ) ;
if ( V_128 == V_122 )
return 0 ;
else if ( V_128 < 0 ) {
F_4 ( V_6 , L_26 , V_128 ) ;
error = V_128 ;
goto V_130;
}
for ( V_81 = 0 ; V_81 < F_40 ( V_131 ) ; V_81 ++ ) {
if ( V_6 -> V_119 == V_131 [ V_81 ] . V_17 ) {
F_18 ( L_27 , V_131 [ V_81 ] . V_17 ) ;
break;
}
}
if ( V_81 == F_40 ( V_131 ) ) {
F_4 ( V_6 , L_28
L_29
L_30 ) ;
error = - 1 ;
goto V_130;
}
if ( V_128 == V_121 ) {
for ( V_129 = 0 ; V_129 < F_40 ( V_132 ) ; V_129 ++ ) {
if ( V_28 == V_132 [ V_129 ] . V_17 )
break;
}
if ( V_129 == F_40 ( V_132 ) ) {
F_4 ( V_6 , L_31 , V_28 ) ;
error = - 1 ;
goto V_130;
}
}
for ( V_83 = 0 ; V_131 [ V_81 ] . V_133 [ V_83 ] >= 0 ; V_83 ++ )
F_48 ( V_131 [ V_81 ] . V_133 [ V_83 ] , V_36 -> V_134 ) ;
error = F_49 ( V_36 , NULL , F_7 ) ;
if ( error )
goto V_130;
if ( V_128 == V_121 ) {
F_50 ( V_129 == - 1 ) ;
V_27 = & V_132 [ V_129 ] ;
}
F_6 ( & V_14 -> V_16 , & V_131 [ V_81 ] , V_27 , V_28 ) ;
if ( F_51 ( V_135 , V_36 -> V_134 ) ) {
if ( ( V_113 >> 8 ) == V_136 &&
( V_113 & 0xff ) == V_137 )
V_36 -> V_138 -> V_139 = F_16 ;
else
V_36 -> V_138 -> V_139 = F_14 ;
V_36 -> V_138 -> V_139 ( V_36 , 0 ) ;
}
error = F_52 ( & V_6 -> V_36 , & V_140 ) ;
if ( error )
F_53 ( V_6 , L_32 , error ) ;
if ( V_128 == V_121 ) {
error = F_52 ( & V_6 -> V_36 , & V_141 ) ;
if ( error )
F_53 ( V_6 , L_33 , error ) ;
error = F_52 ( & V_6 -> V_36 , & V_142 ) ;
if ( error )
F_53 ( V_6 , L_34 , error ) ;
}
F_18 ( L_35 ) ;
V_14 -> V_16 . V_2 = V_14 -> V_16 . V_3 ;
if ( V_14 -> V_16 . V_34 )
V_14 -> V_16 . V_34 ( V_6 , V_14 -> V_16 . V_2 ) ;
#ifdef F_54
V_14 -> V_16 . V_109 = 0 ;
for ( V_83 = 0 ; V_83 < 5 ; V_83 ++ )
V_14 -> V_16 . V_108 [ V_83 ] = NULL ;
if ( V_131 [ V_81 ] . V_17 == V_70 ||
V_131 [ V_81 ] . V_17 == V_76 ) {
struct V_103 * V_108 ;
T_6 V_143 ;
char * V_94 ;
F_36 ( V_6 , 0 ) ;
V_143 = strlen ( F_55 ( & V_6 -> V_36 ) ) + 8 ;
for ( V_83 = 0 ; V_83 < 5 ; V_83 ++ ) {
V_108 = F_46 ( sizeof( struct V_103 ) + V_143 , V_97 ) ;
if ( ! V_108 ) {
F_4 ( V_6 , L_36 , V_83 ) ;
goto V_144;
}
V_94 = ( void * ) ( & V_108 [ 1 ] ) ;
snprintf ( V_94 , V_143 , L_37 , F_55 ( & V_6 -> V_36 ) , V_83 + 1 ) ;
V_108 -> V_94 = V_94 ;
V_108 -> V_145 = 0 ;
V_108 -> V_146 = 1 ;
V_108 -> V_147 = F_38 ;
V_108 -> V_148 = F_37 ;
V_14 -> V_16 . V_108 [ V_83 ] = V_108 ;
error = F_56 ( & V_6 -> V_36 , V_108 ) ;
if ( error ) {
F_4 ( V_6 , L_38 , V_83 ) ;
V_144:
for ( V_83 = 0 ; V_83 < 5 ; V_83 ++ ) {
V_108 = V_14 -> V_16 . V_108 [ V_83 ] ;
V_14 -> V_16 . V_108 [ V_83 ] = NULL ;
if ( ! V_108 )
continue;
F_57 ( V_108 ) ;
F_29 ( V_108 ) ;
}
goto V_149;
}
}
}
V_149:
#endif
F_30 ( V_6 , L_39 ) ;
return 0 ;
V_130:
V_12 -> V_15 = NULL ;
F_29 ( V_14 ) ;
return error ;
}
int F_58 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_12 = F_9 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_40 ) ;
return - 1 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 )
goto V_149;
if ( V_14 -> V_16 . V_29 ) {
F_59 ( & V_6 -> V_36 , & V_141 ) ;
F_59 ( & V_6 -> V_36 , & V_142 ) ;
}
F_59 ( & V_6 -> V_36 , & V_140 ) ;
#ifdef F_54
{
int V_83 ;
struct V_103 * V_108 ;
for ( V_83 = 0 ; V_83 < 5 ; V_83 ++ ) {
V_108 = V_14 -> V_16 . V_108 [ V_83 ] ;
V_14 -> V_16 . V_108 [ V_83 ] = NULL ;
if ( ! V_108 )
continue;
F_57 ( V_108 ) ;
F_29 ( V_108 ) ;
}
}
#endif
F_60 ( V_6 ) ;
V_12 -> V_15 = NULL ;
F_29 ( V_14 ) ;
V_149:
F_18 ( L_41 ) ;
return 0 ;
}

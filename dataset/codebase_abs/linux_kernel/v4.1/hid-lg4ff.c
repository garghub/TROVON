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
switch ( V_14 -> V_16 ) {
case V_17 :
switch ( V_10 -> V_18 ) {
case V_19 :
V_4 = F_1 ( V_1 , V_14 -> V_2 ) ;
F_5 ( V_8 -> V_20 -> V_21 , V_10 -> type , V_10 -> V_18 , V_4 ) ;
return 1 ;
default:
return 0 ;
}
default:
return 0 ;
}
}
static int F_6 ( struct V_22 * V_23 , void * V_24 , struct V_25 * V_26 )
{
struct V_5 * V_6 = F_7 ( V_23 ) ;
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
int V_35 ;
#define F_9 ( V_35 ) do { if (x < 0) x = 0; else if (x > 0xff) x = 0xff; } while (0)
switch ( V_26 -> type ) {
case V_36 :
V_35 = V_26 -> V_37 . V_38 . V_39 + 0x80 ;
F_9 ( V_35 ) ;
if ( V_35 == 0x80 ) {
V_1 [ 0 ] = 0x13 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
return 0 ;
}
V_1 [ 0 ] = 0x11 ;
V_1 [ 1 ] = 0x08 ;
V_1 [ 2 ] = V_35 ;
V_1 [ 3 ] = 0x80 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
break;
}
return 0 ;
}
static void F_11 ( struct V_22 * V_23 , T_3 V_41 )
{
struct V_5 * V_6 = F_7 ( V_23 ) ;
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
T_4 V_42 , V_43 ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return;
}
if ( V_41 == 0 ) {
V_1 [ 0 ] = 0xf5 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
return;
}
if ( V_41 <= 0xaaaa ) {
V_42 = 0x0c * V_41 ;
V_43 = 0x80 * V_41 ;
} else {
V_42 = ( 0x0c * 0xaaaa ) + 0x06 * ( V_41 - 0xaaaa ) ;
V_43 = ( 0x80 * 0xaaaa ) + 0xff * ( V_41 - 0xaaaa ) ;
}
switch ( V_14 -> V_16 ) {
case V_44 :
case V_45 :
break;
default:
V_42 = V_42 >> 1 ;
break;
}
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x0d ;
V_1 [ 2 ] = V_42 / 0xaaaa ;
V_1 [ 3 ] = V_42 / 0xaaaa ;
V_1 [ 4 ] = V_43 / 0xaaaa ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
V_1 [ 0 ] = 0x14 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_13 ( struct V_22 * V_23 , T_3 V_41 )
{
struct V_5 * V_6 = F_7 ( V_23 ) ;
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
V_41 = V_41 * 90 / 65535 ;
V_1 [ 0 ] = 0xfe ;
V_1 [ 1 ] = 0x03 ;
V_1 [ 2 ] = V_41 >> 14 ;
V_1 [ 3 ] = V_41 >> 14 ;
V_1 [ 4 ] = V_41 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_14 ( struct V_5 * V_6 , T_3 V_2 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
F_15 ( L_4 , V_2 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x81 ;
V_1 [ 2 ] = V_2 & 0x00ff ;
V_1 [ 3 ] = ( V_2 & 0xff00 ) >> 8 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_16 ( struct V_5 * V_6 , T_2 V_2 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
int V_46 , V_47 , V_48 ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
F_15 ( L_5 , V_2 ) ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x00 ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 > 200 ) {
V_32 -> V_8 [ 0 ] -> V_1 [ 1 ] = 0x03 ;
V_48 = 900 ;
} else {
V_32 -> V_8 [ 0 ] -> V_1 [ 1 ] = 0x02 ;
V_48 = 200 ;
}
F_10 ( V_6 , V_32 , V_40 ) ;
V_1 [ 0 ] = 0x81 ;
V_1 [ 1 ] = 0x0b ;
V_1 [ 2 ] = 0x00 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
if ( V_2 == 200 || V_2 == 900 ) {
F_10 ( V_6 , V_32 , V_40 ) ;
return;
}
V_46 = ( ( ( V_48 - V_2 + 1 ) * 2047 ) / V_48 ) ;
V_47 = 0xfff - V_46 ;
V_1 [ 2 ] = V_46 >> 4 ;
V_1 [ 3 ] = V_47 >> 4 ;
V_1 [ 4 ] = 0xff ;
V_1 [ 5 ] = ( V_47 & 0xe ) << 4 | ( V_46 & 0xe ) ;
V_1 [ 6 ] = 0xff ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static const struct V_49 * F_17 ( const T_3 V_50 , const T_3 V_51 )
{
switch ( V_50 ) {
case V_17 :
switch ( V_51 ) {
case V_17 :
return & V_52 ;
default:
return NULL ;
}
break;
case V_53 :
switch ( V_51 ) {
case V_17 :
return & V_52 ;
case V_53 :
return & V_54 ;
default:
return NULL ;
}
break;
case V_55 :
switch ( V_51 ) {
case V_56 :
return & V_57 ;
case V_17 :
return & V_58 ;
case V_53 :
return & V_59 ;
case V_55 :
return & V_60 ;
default:
return NULL ;
}
break;
case V_61 :
switch ( V_51 ) {
case V_56 :
return & V_57 ;
case V_17 :
return & V_58 ;
case V_61 :
return & V_62 ;
default:
return NULL ;
}
break;
default:
return NULL ;
}
}
static int F_18 ( struct V_5 * V_6 , const struct V_49 * V_63 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
T_5 V_64 ;
for ( V_64 = 0 ; V_64 < V_63 -> V_65 ; V_64 ++ ) {
T_5 V_66 ;
for ( V_66 = 0 ; V_66 < 7 ; V_66 ++ )
V_1 [ V_66 ] = V_63 -> V_67 [ V_66 + ( 7 * V_64 ) ] ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
F_19 ( V_6 ) ;
return 0 ;
}
static T_6 F_20 ( struct V_68 * V_23 , struct V_69 * V_70 , char * V_71 )
{
struct V_5 * V_6 = F_21 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_6 V_72 = 0 ;
int V_64 ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
if ( ! V_14 -> V_73 ) {
F_4 ( V_6 , L_6 ) ;
return 0 ;
}
for ( V_64 = 0 ; V_64 < V_74 ; V_64 ++ ) {
if ( V_14 -> V_75 & F_22 ( V_64 ) ) {
V_72 += F_23 ( V_71 + V_72 , V_76 - V_72 , L_7 ,
V_77 [ V_64 ] . V_78 ,
! V_77 [ V_64 ] . V_16 ? V_14 -> V_73 : V_77 [ V_64 ] . V_79 ) ;
if ( V_72 >= V_76 - 1 )
return V_72 ;
if ( V_77 [ V_64 ] . V_16 == V_14 -> V_16 ||
( V_77 [ V_64 ] . V_16 == 0 && V_14 -> V_16 == V_14 -> V_50 ) )
V_72 += F_23 ( V_71 + V_72 , V_76 - V_72 , L_8 ) ;
else
V_72 += F_23 ( V_71 + V_72 , V_76 - V_72 , L_9 ) ;
if ( V_72 >= V_76 - 1 )
return V_72 ;
}
}
return V_72 ;
}
static T_6 F_24 ( struct V_68 * V_23 , struct V_69 * V_70 , const char * V_71 , T_7 V_72 )
{
struct V_5 * V_6 = F_21 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
const struct V_49 * V_63 ;
T_3 V_51 = 0 ;
int V_64 , V_80 ;
char * V_81 ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_82 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_82 ;
}
V_81 = F_25 ( V_83 , L_10 , V_71 ) ;
if ( ! V_81 )
return - V_84 ;
V_64 = strlen ( V_81 ) ;
if ( V_81 [ V_64 - 1 ] == '\n' ) {
if ( V_64 == 1 ) {
F_26 ( V_81 ) ;
return - V_82 ;
}
V_81 [ V_64 - 1 ] = '\0' ;
}
for ( V_64 = 0 ; V_64 < V_74 ; V_64 ++ ) {
const T_3 V_85 = V_77 [ V_64 ] . V_16 ;
const char * V_78 = V_77 [ V_64 ] . V_78 ;
if ( V_14 -> V_75 & F_22 ( V_64 ) ) {
if ( ! strcmp ( V_78 , V_81 ) ) {
if ( ! V_85 )
V_51 = V_14 -> V_50 ;
else
V_51 = V_85 ;
break;
}
}
}
if ( V_64 == V_74 ) {
F_27 ( V_6 , L_11 , V_81 ) ;
F_26 ( V_81 ) ;
return - V_82 ;
}
F_26 ( V_81 ) ;
if ( V_51 == V_14 -> V_16 )
return V_72 ;
if ( V_51 == V_56 && ! V_86 ) {
F_27 ( V_6 , L_12 ,
V_14 -> V_73 ) ;
return - V_82 ;
}
if ( ( V_14 -> V_50 == V_17 || V_14 -> V_50 == V_53 ) &&
V_14 -> V_16 > V_51 ) {
F_27 ( V_6 , L_13 , V_14 -> V_73 , V_77 [ V_64 ] . V_79 ) ;
return - V_82 ;
}
V_63 = F_17 ( V_14 -> V_50 , V_51 ) ;
if ( ! V_63 ) {
F_4 ( V_6 , L_14 , V_51 ) ;
return - V_82 ;
}
V_80 = F_18 ( V_6 , V_63 ) ;
return ( V_80 == 0 ? V_72 : V_80 ) ;
}
static T_6 F_28 ( struct V_68 * V_23 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_5 * V_6 = F_21 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_7 V_72 ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
V_72 = F_23 ( V_71 , V_76 , L_15 , V_14 -> V_2 ) ;
return V_72 ;
}
static T_6 F_29 ( struct V_68 * V_23 , struct V_69 * V_70 ,
const char * V_71 , T_7 V_72 )
{
struct V_5 * V_6 = F_21 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_2 V_2 = F_30 ( V_71 , NULL , 10 ) ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return - V_82 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return - V_82 ;
}
if ( V_2 == 0 )
V_2 = V_14 -> V_3 ;
if ( V_14 -> V_87 != NULL && V_2 >= V_14 -> V_88 && V_2 <= V_14 -> V_3 ) {
V_14 -> V_87 ( V_6 , V_2 ) ;
V_14 -> V_2 = V_2 ;
}
return V_72 ;
}
static T_6 F_31 ( struct V_68 * V_23 , struct V_69 * V_70 , char * V_71 )
{
struct V_5 * V_6 = F_21 ( V_23 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
T_7 V_72 ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_2 ) ;
return 0 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_3 ) ;
return 0 ;
}
if ( ! V_14 -> V_89 || ! V_14 -> V_73 ) {
F_4 ( V_6 , L_6 ) ;
return 0 ;
}
V_72 = F_23 ( V_71 , V_76 , L_16 , V_14 -> V_89 , V_14 -> V_73 ) ;
return V_72 ;
}
static T_6 F_32 ( struct V_68 * V_23 , struct V_69 * V_70 , const char * V_71 , T_7 V_72 )
{
return - V_90 ;
}
static void F_33 ( struct V_5 * V_6 , T_8 V_91 )
{
struct V_27 * V_28 = & V_6 -> V_29 [ V_30 ] . V_28 ;
struct V_31 * V_32 = F_8 ( V_28 -> V_33 , struct V_31 , V_34 ) ;
T_1 * V_1 = V_32 -> V_8 [ 0 ] -> V_1 ;
V_1 [ 0 ] = 0xf8 ;
V_1 [ 1 ] = 0x12 ;
V_1 [ 2 ] = V_91 ;
V_1 [ 3 ] = 0x00 ;
V_1 [ 4 ] = 0x00 ;
V_1 [ 5 ] = 0x00 ;
V_1 [ 6 ] = 0x00 ;
F_10 ( V_6 , V_32 , V_40 ) ;
}
static void F_34 ( struct V_92 * V_93 ,
enum V_94 V_1 )
{
struct V_68 * V_23 = V_93 -> V_23 -> V_95 ;
struct V_5 * V_6 = F_35 ( V_23 , struct V_5 , V_23 ) ;
struct V_11 * V_12 = F_12 ( V_6 ) ;
struct V_13 * V_14 ;
int V_64 , V_96 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_17 ) ;
return;
}
V_14 = (struct V_13 * ) V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_18 ) ;
return;
}
for ( V_64 = 0 ; V_64 < 5 ; V_64 ++ ) {
if ( V_93 != V_14 -> V_97 [ V_64 ] )
continue;
V_96 = ( V_14 -> V_98 >> V_64 ) & 1 ;
if ( V_1 == V_99 && V_96 ) {
V_14 -> V_98 &= ~ ( 1 << V_64 ) ;
F_33 ( V_6 , V_14 -> V_98 ) ;
} else if ( V_1 != V_99 && ! V_96 ) {
V_14 -> V_98 |= 1 << V_64 ;
F_33 ( V_6 , V_14 -> V_98 ) ;
}
break;
}
}
static enum V_94 F_36 ( struct V_92 * V_93 )
{
struct V_68 * V_23 = V_93 -> V_23 -> V_95 ;
struct V_5 * V_6 = F_35 ( V_23 , struct V_5 , V_23 ) ;
struct V_11 * V_12 = F_12 ( V_6 ) ;
struct V_13 * V_14 ;
int V_64 , V_1 = 0 ;
if ( ! V_12 ) {
F_4 ( V_6 , L_17 ) ;
return V_99 ;
}
V_14 = (struct V_13 * ) V_12 -> V_15 ;
if ( ! V_14 ) {
F_4 ( V_6 , L_18 ) ;
return V_99 ;
}
for ( V_64 = 0 ; V_64 < 5 ; V_64 ++ )
if ( V_93 == V_14 -> V_97 [ V_64 ] ) {
V_1 = ( V_14 -> V_98 >> V_64 ) & 1 ;
break;
}
return V_1 ? V_100 : V_99 ;
}
static T_3 F_37 ( struct V_5 * V_6 , const T_3 V_101 , const T_3 V_102 )
{
const struct V_103 * V_104 ;
int V_64 , V_105 , V_106 ;
switch ( V_101 ) {
case V_56 :
case V_17 :
V_104 = & V_107 ;
V_105 = 0 ;
V_106 = V_104 -> V_72 - 1 ;
break;
case V_53 :
V_104 = & V_107 ;
V_105 = 0 ;
V_106 = V_104 -> V_72 - 2 ;
break;
case V_55 :
V_104 = & V_107 ;
V_105 = 1 ;
V_106 = V_104 -> V_72 - 3 ;
break;
case V_61 :
V_104 = & V_107 ;
V_105 = 0 ;
V_106 = V_104 -> V_72 - 4 ;
break;
default:
return 0 ;
}
for ( V_64 = V_105 ; V_64 <= V_106 ; V_64 ++ ) {
const T_3 V_108 = V_104 -> V_109 [ V_64 ] -> V_108 ;
const T_3 V_110 = V_104 -> V_109 [ V_64 ] -> V_110 ;
const T_3 V_50 = V_104 -> V_109 [ V_64 ] -> V_50 ;
if ( ( V_102 & V_108 ) == V_110 ) {
F_15 ( L_19 , V_50 , V_101 ) ;
return V_50 ;
}
}
F_15 ( L_20 , V_102 ) ;
return 0 ;
}
static int F_38 ( struct V_5 * V_6 , T_3 * V_50 , const T_3 V_102 )
{
const T_3 V_101 = V_6 -> V_111 ;
int V_80 ;
* V_50 = F_37 ( V_6 , V_101 , V_102 ) ;
if ( ! * V_50 ) {
* V_50 = V_101 ;
F_15 ( L_21 ) ;
return V_112 ;
}
if ( V_101 == V_56 &&
V_101 != * V_50 &&
! V_86 ) {
const struct V_49 * V_63 = F_17 ( * V_50 , * V_50 ) ;
if ( ! V_63 ) {
F_4 ( V_6 , L_22 , * V_50 ) ;
return V_112 ;
}
V_80 = F_18 ( V_6 , V_63 ) ;
if ( V_80 ) {
F_4 ( V_6 , L_23 , V_80 ) ;
return V_113 ;
}
return V_114 ;
}
return V_113 ;
}
int F_39 ( struct V_5 * V_6 )
{
struct V_115 * V_20 = F_8 ( V_6 -> V_116 . V_33 , struct V_115 , V_34 ) ;
struct V_22 * V_23 = V_20 -> V_21 ;
const struct V_117 * V_118 = & ( F_40 ( V_6 ) -> V_119 ) ;
const T_3 V_102 = F_41 ( V_118 -> V_102 ) ;
struct V_13 * V_14 ;
struct V_11 * V_12 ;
int error , V_64 , V_66 ;
int V_120 , V_121 = - 1 ;
T_3 V_50 ;
if ( ! F_42 ( V_6 , V_30 , 0 , 0 , 7 ) )
return - 1 ;
V_120 = F_38 ( V_6 , & V_50 , V_102 ) ;
if ( V_120 == V_114 )
return 0 ;
for ( V_64 = 0 ; V_64 < F_43 ( V_122 ) ; V_64 ++ ) {
if ( V_6 -> V_111 == V_122 [ V_64 ] . V_16 ) {
F_15 ( L_24 , V_122 [ V_64 ] . V_16 ) ;
break;
}
}
if ( V_64 == F_43 ( V_122 ) ) {
F_4 ( V_6 , L_25
L_26 ) ;
return - 1 ;
}
if ( V_120 == V_113 ) {
for ( V_121 = 0 ; V_121 < F_43 ( V_123 ) ; V_121 ++ ) {
if ( V_50 == V_123 [ V_121 ] . V_16 )
break;
}
if ( V_121 == F_43 ( V_123 ) ) {
F_4 ( V_6 , L_27 , V_50 ) ;
return - 1 ;
}
}
for ( V_66 = 0 ; V_122 [ V_64 ] . V_124 [ V_66 ] >= 0 ; V_66 ++ )
F_44 ( V_122 [ V_64 ] . V_124 [ V_66 ] , V_23 -> V_125 ) ;
error = F_45 ( V_23 , NULL , F_6 ) ;
if ( error )
return error ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_28 ) ;
return - 1 ;
}
V_14 = F_46 ( sizeof( struct V_13 ) , V_83 ) ;
if ( ! V_14 ) {
F_4 ( V_6 , L_29 ) ;
return - V_84 ;
}
V_12 -> V_15 = V_14 ;
V_14 -> V_16 = V_122 [ V_64 ] . V_16 ;
V_14 -> V_50 = V_50 ;
V_14 -> V_88 = V_122 [ V_64 ] . V_88 ;
V_14 -> V_3 = V_122 [ V_64 ] . V_3 ;
V_14 -> V_87 = V_122 [ V_64 ] . V_87 ;
if ( V_120 == V_113 ) {
F_47 ( V_121 == - 1 ) ;
V_14 -> V_75 = V_123 [ V_121 ] . V_75 ;
V_14 -> V_89 = V_123 [ V_121 ] . V_89 ;
V_14 -> V_73 = V_123 [ V_121 ] . V_73 ;
}
if ( F_48 ( V_126 , V_23 -> V_125 ) ) {
if ( ( V_102 >> 8 ) == V_127 &&
( V_102 & 0xff ) == V_128 )
V_23 -> V_129 -> V_130 = F_13 ;
else
V_23 -> V_129 -> V_130 = F_11 ;
V_23 -> V_129 -> V_130 ( V_23 , 0 ) ;
}
error = F_49 ( & V_6 -> V_23 , & V_131 ) ;
if ( error )
return error ;
if ( V_120 == V_113 ) {
error = F_49 ( & V_6 -> V_23 , & V_132 ) ;
if ( error )
return error ;
error = F_49 ( & V_6 -> V_23 , & V_133 ) ;
if ( error )
return error ;
}
F_15 ( L_30 ) ;
V_14 -> V_2 = V_14 -> V_3 ;
if ( V_14 -> V_87 != NULL )
V_14 -> V_87 ( V_6 , V_14 -> V_2 ) ;
#ifdef F_50
V_14 -> V_98 = 0 ;
for ( V_66 = 0 ; V_66 < 5 ; V_66 ++ )
V_14 -> V_97 [ V_66 ] = NULL ;
if ( V_122 [ V_64 ] . V_16 == V_55 ) {
struct V_92 * V_97 ;
T_7 V_134 ;
char * V_79 ;
F_33 ( V_6 , 0 ) ;
V_134 = strlen ( F_51 ( & V_6 -> V_23 ) ) + 8 ;
for ( V_66 = 0 ; V_66 < 5 ; V_66 ++ ) {
V_97 = F_46 ( sizeof( struct V_92 ) + V_134 , V_83 ) ;
if ( ! V_97 ) {
F_4 ( V_6 , L_31 , V_66 ) ;
goto V_135;
}
V_79 = ( void * ) ( & V_97 [ 1 ] ) ;
snprintf ( V_79 , V_134 , L_32 , F_51 ( & V_6 -> V_23 ) , V_66 + 1 ) ;
V_97 -> V_79 = V_79 ;
V_97 -> V_136 = 0 ;
V_97 -> V_137 = 1 ;
V_97 -> V_138 = F_36 ;
V_97 -> V_139 = F_34 ;
V_14 -> V_97 [ V_66 ] = V_97 ;
error = F_52 ( & V_6 -> V_23 , V_97 ) ;
if ( error ) {
F_4 ( V_6 , L_33 , V_66 ) ;
V_135:
for ( V_66 = 0 ; V_66 < 5 ; V_66 ++ ) {
V_97 = V_14 -> V_97 [ V_66 ] ;
V_14 -> V_97 [ V_66 ] = NULL ;
if ( ! V_97 )
continue;
F_53 ( V_97 ) ;
F_26 ( V_97 ) ;
}
goto V_140;
}
}
}
V_140:
#endif
F_27 ( V_6 , L_34 ) ;
return 0 ;
}
int F_54 ( struct V_5 * V_6 )
{
struct V_13 * V_14 ;
struct V_11 * V_12 ;
V_12 = F_12 ( V_6 ) ;
if ( ! V_12 ) {
F_4 ( V_6 , L_35 ) ;
return - 1 ;
}
V_14 = V_12 -> V_15 ;
if ( ! V_14 )
goto V_140;
F_55 ( & V_6 -> V_23 , & V_131 ) ;
if ( V_14 -> V_75 ) {
F_55 ( & V_6 -> V_23 , & V_132 ) ;
F_55 ( & V_6 -> V_23 , & V_133 ) ;
}
#ifdef F_50
{
int V_66 ;
struct V_92 * V_97 ;
for ( V_66 = 0 ; V_66 < 5 ; V_66 ++ ) {
V_97 = V_14 -> V_97 [ V_66 ] ;
V_14 -> V_97 [ V_66 ] = NULL ;
if ( ! V_97 )
continue;
F_53 ( V_97 ) ;
F_26 ( V_97 ) ;
}
}
#endif
F_26 ( V_14 ) ;
V_140:
F_15 ( L_36 ) ;
return 0 ;
}

static unsigned char F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 ;
int V_4 ;
V_4 = 32 ;
V_3 = V_2 -> V_5 . V_6 . V_7 + 1 ;
while ( ( V_4 ) && ( V_2 -> V_5 . V_6 . V_8 [ V_3 >> 3 ] == 0xFF ) ) {
V_2 -> V_5 . V_6 . V_7 = ( V_3 & 0xF8 ) + 8 ;
V_4 -- ;
}
if ( V_4 ) {
while ( V_2 -> V_5 . V_6 . V_8 [ V_3 >> 3 ] & ( 1 << ( V_3 & 7 ) ) )
V_3 ++ ;
} else
V_3 = 0 ;
V_2 -> V_5 . V_6 . V_7 = V_3 ;
V_2 -> V_5 . V_6 . V_8 [ V_3 >> 3 ] |= ( 1 << ( V_3 & 7 ) ) ;
return ( V_3 ) ;
}
static void F_2 ( struct V_1 * V_2 , unsigned char V_9 )
{
if ( ! V_9 ) return;
V_2 -> V_5 . V_6 . V_8 [ V_9 >> 3 ] &= ~ ( 1 << ( V_9 & 7 ) ) ;
}
static struct V_10
* F_3 ( struct V_1 * V_11 , int V_12 )
{ struct V_10 * V_13 ;
if ( ! ( V_13 = F_4 ( V_11 , V_12 ) ) )
return ( NULL ) ;
V_13 -> V_5 . V_6 . V_14 = 0 ;
V_13 -> V_5 . V_6 . V_15 = 0 ;
V_13 -> V_5 . V_6 . V_16 [ 0 ] = '\0' ;
return ( V_13 ) ;
}
static void
F_5 ( struct V_10 * V_2 )
{
F_2 ( V_2 -> V_11 , V_2 -> V_5 . V_6 . V_14 ) ;
F_6 ( V_2 ) ;
}
static struct V_10 *
F_7 ( struct V_1 * V_11 , int V_9 )
{ struct V_10 * V_17 = V_11 -> V_18 . V_13 ;
if ( ! V_9 ) return ( NULL ) ;
while ( V_17 )
{ if ( ( V_17 -> V_19 == - 1 ) && ( V_17 -> V_5 . V_6 . V_14 == V_9 ) )
return ( V_17 ) ;
V_17 = V_17 -> V_20 ;
}
return ( NULL ) ;
}
static void
F_8 ( struct V_1 * V_11 , int V_9 , T_1 * V_2 , T_1 V_21 )
{ T_2 V_22 ;
struct V_23 * V_24 ;
struct V_10 * V_17 = NULL ;
if ( ( V_17 = F_7 ( V_11 , V_9 ) ) )
{ F_9 ( & V_17 -> V_25 ) ;
V_24 = V_17 -> V_11 -> V_26 . V_27 ;
V_22 . V_28 = V_24 -> V_29 ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_33 ;
V_22 . V_34 . V_35 . V_36 = V_17 -> V_5 . V_6 . V_14 ;
V_22 . V_34 . V_35 . V_37 = V_17 -> V_5 . V_6 . V_37 ;
V_22 . V_34 . V_35 . V_13 = V_17 -> V_5 . V_6 . V_13 ;
V_22 . V_34 . V_35 . V_38 = 0 ;
V_22 . V_34 . V_35 . V_39 = V_21 ;
V_22 . V_34 . V_35 . V_40 = V_2 ;
F_2 ( V_17 -> V_11 , V_17 -> V_5 . V_6 . V_14 ) ;
V_17 -> V_5 . V_6 . V_14 = 0 ;
V_24 -> V_41 . V_42 ( & V_22 ) ;
F_5 ( V_17 ) ;
}
else
F_10 ( V_11 , L_1 , V_9 , V_21 ) ;
}
static void
F_11 ( struct V_1 * V_11 , int V_9 , T_3 error )
{ T_2 V_22 ;
struct V_23 * V_24 ;
struct V_10 * V_17 = NULL ;
if ( ( V_17 = F_7 ( V_11 , V_9 ) ) )
{ F_9 ( & V_17 -> V_25 ) ;
V_24 = V_17 -> V_11 -> V_26 . V_27 ;
V_22 . V_28 = V_24 -> V_29 ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_43 ;
V_22 . V_34 . V_35 . V_36 = V_17 -> V_5 . V_6 . V_14 ;
V_22 . V_34 . V_35 . V_37 = V_17 -> V_5 . V_6 . V_37 ;
V_22 . V_34 . V_35 . V_13 = V_17 -> V_5 . V_6 . V_13 ;
V_22 . V_34 . V_35 . V_38 = error ;
V_22 . V_34 . V_35 . V_39 = 0 ;
V_22 . V_34 . V_35 . V_40 = NULL ;
F_2 ( V_17 -> V_11 , V_17 -> V_5 . V_6 . V_14 ) ;
V_17 -> V_5 . V_6 . V_14 = 0 ;
V_24 -> V_41 . V_42 ( & V_22 ) ;
F_5 ( V_17 ) ;
}
else
F_10 ( V_11 , L_2 , V_9 , error ) ;
}
static void
F_12 ( struct V_1 * V_11 , int V_12 , int V_9 ,
int V_44 , T_1 * V_2 , T_1 V_21 )
{ T_2 V_22 ;
struct V_23 * V_24 ;
F_10 ( V_11 , L_3 ,
( V_12 == - 1 ) ? L_4 : L_5 , V_9 , V_44 , V_21 ) ;
if ( V_12 >= - 1 ) return;
V_24 = V_11 -> V_26 . V_27 ;
V_22 . V_28 = V_24 -> V_29 ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_45 ;
V_22 . V_34 . V_35 . V_36 = V_9 ;
V_22 . V_34 . V_35 . V_37 = 0 ;
V_22 . V_34 . V_35 . V_13 = V_44 ;
V_22 . V_34 . V_35 . V_38 = 0 ;
V_22 . V_34 . V_35 . V_39 = V_21 ;
V_22 . V_34 . V_35 . V_40 = V_2 ;
V_24 -> V_41 . V_42 ( & V_22 ) ;
}
static void
F_13 ( struct V_1 * V_11 , struct V_10 * V_17 ,
int V_12 , T_1 * V_2 )
{
int V_46 = 0 ;
unsigned char V_21 = 0 , V_47 , V_48 ;
int V_44 , V_9 ;
T_3 V_49 ;
if ( V_17 )
V_11 = V_17 -> V_11 ;
else
if ( ( ! V_11 ) || ( V_12 >= 0 ) ) return;
V_2 ++ ;
V_46 = * V_2 ++ ;
if ( V_46 == 0 ) {
F_10 ( V_11 , L_6 ) ;
return;
}
if ( ( * V_2 & 0x1F ) != 0x11 ) {
F_10 ( V_11 , L_7 ) ;
return;
}
while ( V_46 > 0 && ! ( * V_2 & 0x80 ) ) {
V_2 ++ ;
V_46 -- ;
}
if ( V_46 < 2 ) {
F_10 ( V_11 , L_8 ) ;
return;
}
V_2 ++ ;
V_46 -- ;
if ( ( * V_2 & 0xE0 ) != 0xA0 ) {
F_10 ( V_11 , L_9 ) ;
return;
}
V_48 = * V_2 & 0x1F ;
V_2 ++ ;
V_46 -- ;
if ( V_46 < 1 )
{ F_10 ( V_11 , L_10 ) ;
return;
}
if ( * V_2 & 0x80 )
{
V_21 = * V_2 ++ & 0x7F ;
if ( ( V_46 -- < ( ( ! V_21 ) ? 3 : ( 1 + V_21 ) ) ) ||
( V_21 > 1 ) )
{ F_10 ( V_11 , L_11 ) ;
return;
}
if ( V_21 == 1 )
{ V_21 = * V_2 ++ ;
V_46 -- ;
}
else
{ V_46 -= 2 ;
if ( ( * ( V_2 + V_46 ) ) || ( * ( V_2 + V_46 + 1 ) ) )
{ F_10 ( V_11 , L_12 ) ;
return;
}
V_21 = V_46 ;
}
}
else
{ V_21 = * V_2 ++ ;
V_46 -- ;
}
if ( V_46 < V_21 )
{ F_10 ( V_11 , L_13 ) ;
return;
}
V_46 -= V_21 ;
if ( V_21 < 2 )
{ F_10 ( V_11 , L_14 ) ;
return;
}
if ( * V_2 != 0x02 )
{
F_10 ( V_11 , L_15 ) ;
return;
}
V_2 ++ ;
V_21 -- ;
if ( * V_2 & 0x80 )
{
F_10 ( V_11 , L_16 ) ;
return;
}
V_47 = * V_2 ++ ;
V_21 -- ;
if ( V_47 > V_21 || V_47 == 0 )
{ F_10 ( V_11 , L_17 ) ;
return;
}
V_21 -= V_47 ;
V_9 = 0 ;
while ( V_47 > 0 )
{ V_9 = ( V_9 << 8 ) | ( * V_2 ++ & 0xFF ) ;
V_47 -- ;
}
switch ( V_48 ) {
case 1 :
if ( V_21 < 2 ) {
F_10 ( V_11 , L_18 ) ;
return;
}
if ( * V_2 != 0x02 ) {
F_10 ( V_11 , L_19 ) ;
return;
}
V_2 ++ ;
V_21 -- ;
V_47 = * V_2 ++ ;
V_21 -- ;
if ( V_47 > V_21 || V_47 == 0 ) {
F_10 ( V_11 , L_20 ) ;
return;
}
V_21 -= V_47 ;
V_44 = 0 ;
while ( V_47 > 0 ) {
V_44 = ( V_44 << 8 ) | ( * V_2 ++ & 0xFF ) ;
V_47 -- ;
}
if ( ! V_17 )
{ F_12 ( V_11 , V_12 , V_9 , V_44 , V_2 , V_21 ) ;
return;
}
#ifdef F_14
{
#define F_15 ( T_4 , T_5 , T_6 ) \
while (nlen > 1) { \
int ilen = p[1]; \
if (nlen < ilen + 2) { \
l3_debug(st, "FOO1 nlen < ilen+2"); \
return; \
} \
nlen -= ilen + 2; \
if ((*p & 0xFF) == (a)) { \
int nlen = ilen; \
p += 2; \
b; \
} else { \
p += ilen + 2; \
} \
}
switch ( V_44 ) {
case 0x22 :
F_15 ( L_21 , 0x30 , FOO1(L_22, 0xA1, FOO1(L_23, 0x30, FOO1(L_24, 0x02, ( {
ident = 0;
nlen = (nlen) ? nlen : 0;
while (ilen > 0) {
ident = (ident << 8) | *p++;
ilen--;
}
if (ident > pc->para.chargeinfo) {
pc->para.chargeinfo = ident;
st->l3.l3l4(st, CC_CHARGE | INDICATION, pc);
}
if (st->l3.debug & L3_DEB_CHARGE) {
if (*(p + 2) == 0) {
l3_debug(st, L_25, pc->para.chargeinfo);
}
else {
l3_debug(st, L_26, pc->para.chargeinfo);
}
}
}
)))))
break;
case 0x24 :
F_15 ( L_27 , 0x30 , FOO1(L_28, 0x30, FOO1(L_29, 0xA1, FOO1(L_30, 0x30, FOO1(L_31, 0x02, ( {
ident = 0;
nlen = (nlen) ? nlen : 0;
while (ilen > 0) {
ident = (ident << 8) | *p++;
ilen--;
}
if (ident > pc->para.chargeinfo) {
pc->para.chargeinfo = ident;
st->l3.l3l4(st, CC_CHARGE | INDICATION, pc);
}
if (st->l3.debug & L3_DEB_CHARGE) {
l3_debug(st, L_26, pc->para.chargeinfo);
}
}
))))))
break;
default:
F_10 ( V_11 , L_32 , V_44 ) ;
break;
}
#undef F_15
}
#else
F_10 ( V_11 , L_33 ) ;
#endif
break;
case 2 :
if ( ! V_17 )
{ if ( V_12 == - 1 )
F_8 ( V_11 , V_9 , V_2 , V_21 ) ;
return;
}
if ( ( V_17 -> V_5 . V_6 . V_14 ) && ( V_17 -> V_5 . V_6 . V_14 == V_9 ) )
{
F_2 ( V_11 , V_17 -> V_5 . V_6 . V_14 ) ;
V_17 -> V_5 . V_6 . V_50 = 0 ;
V_17 -> V_5 . V_6 . V_14 = 0 ;
V_17 -> V_51 = V_17 -> V_5 . V_6 . V_50 ;
V_11 -> V_18 . V_52 ( V_11 , V_53 | V_54 , V_17 ) ; }
else
F_10 ( V_11 , L_34 ) ;
break;
case 3 :
V_49 = 0 ;
if ( V_21 < 2 )
{ F_10 ( V_11 , L_35 ) ;
return;
}
if ( * V_2 != 0x02 )
{
F_10 ( V_11 , L_36 ) ;
return;
}
V_2 ++ ;
V_21 -- ;
if ( * V_2 > 4 )
{
F_10 ( V_11 , L_37 ) ;
return;
}
V_47 = * V_2 ++ ;
V_21 -- ;
if ( V_47 > V_21 || V_47 == 0 )
{ F_10 ( V_11 , L_38 ) ;
return;
}
V_21 -= V_47 ;
while ( V_47 > 0 )
{ V_49 = ( V_49 << 8 ) | ( * V_2 ++ & 0xFF ) ;
V_47 -- ;
}
if ( ! V_17 )
{ if ( V_12 == - 1 )
F_11 ( V_11 , V_9 , V_49 ) ;
return;
}
if ( ( V_17 -> V_5 . V_6 . V_14 ) && ( V_17 -> V_5 . V_6 . V_14 == V_9 ) )
{
F_2 ( V_11 , V_17 -> V_5 . V_6 . V_14 ) ;
V_17 -> V_5 . V_6 . V_50 = V_49 ;
V_17 -> V_5 . V_6 . V_14 = 0 ;
V_17 -> V_51 = V_17 -> V_5 . V_6 . V_50 ;
V_11 -> V_18 . V_52 ( V_11 , V_53 | V_54 , V_17 ) ;
}
else
F_10 ( V_11 , L_39 ) ;
break;
default:
F_10 ( V_11 , L_40 , V_48 ) ;
break;
}
}
static void
F_16 ( struct V_10 * V_17 , T_1 V_55 )
{
struct V_56 * V_57 ;
T_1 * V_2 ;
if ( ! ( V_57 = F_17 ( 4 ) ) )
return;
V_2 = F_18 ( V_57 , 4 ) ;
F_19 ( V_2 , V_17 -> V_19 , V_55 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
}
static void
F_21 ( struct V_10 * V_17 , T_1 V_55 , T_1 V_60 )
{
struct V_56 * V_57 ;
T_1 V_61 [ 16 ] ;
T_1 * V_2 = V_61 ;
int V_62 ;
F_19 ( V_2 , V_17 -> V_19 , V_55 ) ;
* V_2 ++ = V_63 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = V_60 | 0x80 ;
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
}
static void
F_22 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
T_1 V_61 [ 16 ] ;
T_1 * V_2 = V_61 ;
int V_62 ;
struct V_56 * V_57 ;
F_19 ( V_2 , V_17 -> V_19 , V_65 ) ;
* V_2 ++ = V_63 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = V_17 -> V_66 . V_60 | 0x80 ;
* V_2 ++ = V_67 ;
* V_2 ++ = 0x1 ;
* V_2 ++ = V_17 -> V_68 & 0x3f ;
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
}
static void
F_23 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
T_1 V_61 [ 16 ] ;
T_1 * V_2 = V_61 ;
int V_62 ;
struct V_56 * V_57 ;
switch ( V_17 -> V_66 . V_60 ) {
case 81 :
case 88 :
case 96 :
case 100 :
case 101 :
F_19 ( V_2 , V_17 -> V_19 , V_69 ) ;
* V_2 ++ = V_63 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = V_17 -> V_66 . V_60 | 0x80 ;
break;
default:
F_24 ( V_70 L_41 ,
V_17 -> V_66 . V_60 ) ;
return;
}
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
F_5 ( V_17 ) ;
}
static int
F_25 ( T_1 V_71 ) {
int V_4 = 0 ;
while ( V_72 [ V_4 ] . V_71 != - 1 ) {
if ( V_72 [ V_4 ] . V_71 == V_71 )
return ( V_72 [ V_4 ] . V_73 ) ;
V_4 ++ ;
}
return ( 255 ) ;
}
static int
F_26 ( struct V_10 * V_17 , T_1 V_71 , int * V_74 ) {
int V_75 = 1 ;
while ( * V_74 != - 1 ) {
if ( ( * V_74 & 0xff ) == V_71 ) {
if ( V_71 & 0x80 )
return ( - V_75 ) ;
else
return ( V_75 ) ;
}
V_75 ++ ;
V_74 ++ ;
}
return ( 0 ) ;
}
static int
F_27 ( struct V_10 * V_17 , struct V_56 * V_57 , int * V_74 )
{
int * V_76 = V_74 ;
T_1 V_55 ;
T_1 * V_2 , V_71 ;
int V_62 , V_77 , V_78 ;
int V_79 = 0 , V_80 = 0 , V_81 = 0 , V_82 = 0 ;
T_1 V_83 = 0 ;
T_1 V_84 = 0 ;
T_1 V_85 = 1 ;
V_2 = V_57 -> V_40 ;
V_2 ++ ;
V_62 = ( * V_2 ++ ) & 0xf ;
V_2 += V_62 ;
V_55 = * V_2 ++ ;
V_78 = 0 ;
while ( ( V_2 - V_57 -> V_40 ) < V_57 -> V_73 ) {
if ( ( * V_2 & 0xf0 ) == 0x90 ) {
V_84 = V_83 ;
V_83 = * V_2 & 7 ;
if ( * V_2 & 0x08 )
V_85 = 0 ;
else
V_85 = 1 ;
if ( V_17 -> V_86 & V_87 )
F_10 ( V_17 -> V_11 , L_42 ,
V_85 ? L_43 : L_44 , V_84 , V_83 ) ;
V_2 ++ ;
continue;
}
if ( ! V_83 ) {
if ( ( V_77 = F_26 ( V_17 , * V_2 , V_76 ) ) ) {
if ( V_77 > 0 ) {
if ( V_77 < V_78 )
V_79 ++ ;
else
V_78 = V_77 ;
}
} else {
if ( F_26 ( V_17 , * V_2 , V_88 ) )
V_81 ++ ;
else
V_82 ++ ;
}
}
V_71 = * V_2 ++ ;
if ( V_71 & 0x80 ) {
V_62 = 1 ;
} else {
V_62 = * V_2 ++ ;
V_2 += V_62 ;
V_62 += 2 ;
}
if ( ! V_83 && ( V_62 > F_25 ( V_71 ) ) )
V_80 ++ ;
if ( ! V_85 ) {
if ( V_17 -> V_86 & V_87 )
F_10 ( V_17 -> V_11 , L_45 ,
V_83 , V_84 ) ;
V_83 = V_84 ;
V_85 = 1 ;
}
}
if ( V_81 | V_82 | V_80 | V_79 ) {
if ( V_17 -> V_86 & V_87 )
F_10 ( V_17 -> V_11 , L_46 ,
V_55 , V_81 , V_82 , V_80 , V_79 ) ;
if ( V_81 )
return ( V_89 ) ;
if ( V_82 )
return ( V_90 ) ;
if ( V_80 )
return ( V_91 ) ;
if ( V_79 )
return ( V_92 ) ;
}
return ( 0 ) ;
}
static int
F_28 ( struct V_10 * V_17 , int V_55 , void * V_32 )
{
switch ( V_55 ) {
case V_93 :
case V_94 :
case V_95 :
case V_96 :
case V_97 :
case V_98 :
case V_99 :
case V_100 :
case V_101 :
case V_102 :
case V_69 :
case V_103 :
case V_104 :
case V_105 :
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_65 :
case V_113 :
if ( V_17 -> V_86 & V_87 )
F_10 ( V_17 -> V_11 , L_47 , V_55 ) ;
break;
case V_114 :
case V_115 :
default:
if ( V_17 -> V_86 & ( V_87 | V_116 ) )
F_10 ( V_17 -> V_11 , L_48 , V_55 ) ;
V_17 -> V_66 . V_60 = 97 ;
F_22 ( V_17 , 0 , NULL ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
static void
F_29 ( struct V_10 * V_17 , int V_75 ) {
if ( V_17 -> V_86 & V_87 )
F_10 ( V_17 -> V_11 , L_49 , V_75 ) ;
switch ( V_75 ) {
case 0 :
break;
case V_89 :
V_17 -> V_66 . V_60 = 96 ;
F_22 ( V_17 , 0 , NULL ) ;
break;
case V_90 :
V_17 -> V_66 . V_60 = 99 ;
F_22 ( V_17 , 0 , NULL ) ;
break;
case V_91 :
V_17 -> V_66 . V_60 = 100 ;
F_22 ( V_17 , 0 , NULL ) ;
break;
case V_92 :
default:
break;
}
}
static int
F_30 ( struct V_10 * V_17 , struct V_56 * V_57 ) {
T_1 * V_2 ;
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , V_117 , 0 ) ) ) {
V_2 ++ ;
if ( * V_2 != 1 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_50 , * V_2 ) ;
return ( - 2 ) ;
}
V_2 ++ ;
if ( * V_2 & 0x60 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_51 , * V_2 ) ;
return ( - 3 ) ;
}
return ( * V_2 & 0x3 ) ;
} else
return ( - 1 ) ;
}
static int
F_32 ( struct V_10 * V_17 , struct V_56 * V_57 ) {
T_1 V_62 , V_4 = 0 ;
T_1 * V_2 ;
V_2 = V_57 -> V_40 ;
V_17 -> V_66 . V_60 = 31 ;
V_17 -> V_66 . V_118 = 0 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , V_63 , 0 ) ) ) {
V_2 ++ ;
V_62 = * V_2 ++ ;
if ( V_62 > 30 )
return ( 1 ) ;
if ( V_62 ) {
V_17 -> V_66 . V_118 = * V_2 ++ ;
V_62 -- ;
} else {
return ( 2 ) ;
}
if ( V_62 && ! ( V_17 -> V_66 . V_118 & 0x80 ) ) {
V_62 -- ;
V_2 ++ ;
}
if ( V_62 ) {
V_17 -> V_66 . V_60 = * V_2 ++ ;
V_62 -- ;
if ( ! ( V_17 -> V_66 . V_60 & 0x80 ) )
return ( 3 ) ;
} else
return ( 4 ) ;
while ( V_62 && ( V_4 < 6 ) ) {
V_17 -> V_66 . V_119 [ V_4 ++ ] = * V_2 ++ ;
V_62 -- ;
}
} else
return ( - 1 ) ;
return ( 0 ) ;
}
static void
F_33 ( struct V_10 * V_17 , T_1 V_120 )
{
struct V_56 * V_57 ;
T_1 V_61 [ 16 + 40 ] ;
T_1 * V_2 = V_61 ;
int V_62 ;
F_19 ( V_2 , V_17 -> V_19 , V_120 ) ;
if ( V_17 -> V_5 . V_6 . V_16 [ 0 ] )
{ * V_2 ++ = V_121 ;
* V_2 ++ = strlen ( V_17 -> V_5 . V_6 . V_16 ) + 1 ;
* V_2 ++ = 0x04 ;
strcpy ( V_2 , V_17 -> V_5 . V_6 . V_16 ) ;
V_2 += strlen ( V_17 -> V_5 . V_6 . V_16 ) ;
V_17 -> V_5 . V_6 . V_16 [ 0 ] = '\0' ;
}
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
}
static void
F_34 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_35 ( V_17 ) ;
F_36 ( V_17 , 19 ) ;
if ( ! V_17 -> V_5 . V_6 . V_16 [ 0 ] )
F_16 ( V_17 , V_102 ) ;
else
F_33 ( V_17 , V_102 ) ;
F_37 ( & V_17 -> V_25 , V_122 , V_123 ) ;
}
static void
F_38 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_75 ;
if ( ( V_75 = F_32 ( V_17 , V_57 ) ) > 0 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_52 , V_75 ) ;
} else if ( V_75 < 0 )
V_17 -> V_66 . V_60 = V_124 ;
F_35 ( V_17 ) ;
F_36 ( V_17 , 0 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_125 | V_126 , V_17 ) ;
F_5 ( V_17 ) ;
}
static T_1 *
F_39 ( T_1 * V_2 , T_1 V_127 )
{
V_2 [ 0 ] = 0 ;
V_2 [ 1 ] = 0x40 ;
V_2 [ 2 ] = 0x80 ;
if ( V_127 & 32 )
V_2 [ 2 ] += 16 ;
else
V_2 [ 2 ] += 24 ;
if ( V_127 & 16 )
V_2 [ 2 ] += 96 ;
else
V_2 [ 2 ] += 32 ;
if ( V_127 & 8 )
V_2 [ 2 ] += 2 ;
else
V_2 [ 2 ] += 3 ;
switch ( V_127 & 0x07 ) {
case 0 :
V_2 [ 0 ] = 66 ;
break;
case 1 :
V_2 [ 0 ] = 88 ;
break;
case 2 :
V_2 [ 0 ] = 87 ;
break;
case 3 :
V_2 [ 0 ] = 67 ;
break;
case 4 :
V_2 [ 0 ] = 69 ;
break;
case 5 :
V_2 [ 0 ] = 72 ;
break;
case 6 :
V_2 [ 0 ] = 73 ;
break;
case 7 :
V_2 [ 0 ] = 75 ;
break;
}
return V_2 + 3 ;
}
static T_1
F_40 ( T_1 V_127 , T_1 V_128 )
{
switch ( V_127 ) {
case 0 :
return V_128 + 2 ;
case 1 :
return V_128 + 24 ;
case 2 :
return V_128 + 23 ;
case 3 :
return V_128 + 3 ;
case 4 :
return V_128 + 5 ;
case 5 :
return V_128 + 8 ;
case 6 :
return V_128 + 9 ;
case 7 :
return V_128 + 11 ;
case 8 :
return V_128 + 14 ;
case 9 :
return V_128 + 15 ;
case 15 :
return V_128 + 40 ;
default:
break;
}
return V_128 ;
}
static T_1
F_41 ( T_1 V_127 , T_1 * V_2 )
{
T_1 V_129 ;
switch ( V_2 [ 5 ] ) {
case 66 :
break;
case 88 :
V_127 += 1 ;
break;
case 87 :
V_127 += 2 ;
break;
case 67 :
V_127 += 3 ;
break;
case 69 :
V_127 += 4 ;
break;
case 72 :
V_127 += 5 ;
break;
case 73 :
V_127 += 6 ;
break;
case 75 :
V_127 += 7 ;
break;
}
V_129 = V_2 [ 7 ] & 0x7f ;
if ( ( V_129 & 16 ) && ( ! ( V_129 & 8 ) ) )
V_127 += 32 ;
if ( ( V_129 & 96 ) == 96 )
V_127 += 16 ;
if ( ( V_129 & 2 ) && ( ! ( V_129 & 1 ) ) )
V_127 += 8 ;
return V_127 ;
}
static T_1
F_42 ( T_1 V_127 , T_1 V_129 )
{
V_129 &= 0x7f ;
switch ( V_129 ) {
case 40 :
return V_127 + 15 ;
case 15 :
return V_127 + 9 ;
case 14 :
return V_127 + 8 ;
case 11 :
return V_127 + 7 ;
case 9 :
return V_127 + 6 ;
case 8 :
return V_127 + 5 ;
case 5 :
return V_127 + 4 ;
case 3 :
return V_127 + 3 ;
case 23 :
return V_127 + 2 ;
case 24 :
return V_127 + 1 ;
default:
return V_127 ;
}
}
static T_1
F_43 ( struct V_56 * V_57 )
{
T_1 * V_2 ;
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , 0x7c , 0 ) ) ) {
switch ( V_2 [ 4 ] & 0x0f ) {
case 0x01 :
if ( V_2 [ 1 ] == 0x04 )
return F_42 ( 160 , V_2 [ 5 ] ) ;
else if ( V_2 [ 1 ] == 0x06 )
return F_41 ( 192 , V_2 ) ;
break;
case 0x08 :
if ( V_2 [ 1 ] > 3 )
return F_42 ( 176 , V_2 [ 5 ] ) ;
break;
}
}
return 0 ;
}
static void
F_44 ( struct V_10 * V_17 , T_1 V_64 ,
void * V_32 )
{
struct V_56 * V_57 ;
T_1 V_61 [ 128 ] ;
T_1 * V_2 = V_61 ;
T_1 V_130 = 0 ;
T_1 V_131 ;
T_1 V_132 = 0x80 ;
T_1 * V_133 ;
T_1 * V_134 ;
T_1 * V_135 ;
T_1 * V_136 ;
int V_62 ;
F_19 ( V_2 , V_17 -> V_19 , V_103 ) ;
V_133 = V_17 -> V_66 . V_137 . V_138 ;
#ifndef F_45
V_131 = ( strchr ( V_133 , '*' ) || strchr ( V_133 , '#' ) ) ? 1 : 0 ;
#else
V_131 = 0 ;
#endif
#ifndef F_46
if ( ! V_131 )
* V_2 ++ = 0xa1 ;
#endif
switch ( V_17 -> V_66 . V_137 . V_139 ) {
case 1 :
* V_2 ++ = V_140 ;
* V_2 ++ = 0x3 ;
* V_2 ++ = 0x90 ;
* V_2 ++ = 0x90 ;
* V_2 ++ = 0xa3 ;
break;
case 5 :
case 7 :
default:
* V_2 ++ = V_140 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x88 ;
* V_2 ++ = 0x90 ;
break;
}
if ( V_131 ) {
* V_2 ++ = V_141 ;
* V_2 ++ = strlen ( V_133 ) ;
while ( * V_133 )
* V_2 ++ = ( * V_133 ++ ) & 0x7F ;
}
if ( ( * V_133 ) && ( ! V_131 ) ) {
if ( ! isdigit ( * V_133 ) ) {
switch ( 0x5f & * V_133 ) {
case 'C' :
V_130 = 0x08 ;
case 'P' :
V_130 |= 0x80 ;
V_133 ++ ;
if ( * V_133 == '1' )
V_130 |= 0x01 ;
else
V_130 |= 0x02 ;
break;
case 'R' :
V_132 = 0xA0 ;
break;
case 'D' :
V_132 = 0x80 ;
break;
default:
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_53 ) ;
break;
}
V_133 ++ ;
}
}
if ( V_130 ) {
* V_2 ++ = V_117 ;
* V_2 ++ = 1 ;
* V_2 ++ = V_130 ;
}
V_134 = V_17 -> V_66 . V_137 . V_142 ;
V_135 = NULL ;
V_136 = V_134 ;
while ( * V_136 ) {
if ( '.' == * V_136 ) {
V_135 = V_136 ;
* V_136 = 0 ;
} else
V_136 ++ ;
}
if ( * V_134 ) {
* V_2 ++ = V_143 ;
* V_2 ++ = strlen ( V_134 ) + ( V_132 ? 2 : 1 ) ;
if ( V_132 ) {
* V_2 ++ = 0x01 ;
* V_2 ++ = V_132 ;
} else
* V_2 ++ = 0x81 ;
while ( * V_134 )
* V_2 ++ = * V_134 ++ & 0x7f ;
}
if ( V_135 ) {
* V_135 ++ = '.' ;
* V_2 ++ = V_144 ;
* V_2 ++ = strlen ( V_135 ) + 2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = 0x50 ;
while ( * V_135 )
* V_2 ++ = * V_135 ++ & 0x7f ;
}
V_135 = NULL ;
V_136 = V_133 ;
while ( * V_136 ) {
if ( '.' == * V_136 ) {
V_135 = V_136 ;
* V_136 = 0 ;
} else
V_136 ++ ;
}
if ( ! V_131 ) {
* V_2 ++ = V_145 ;
* V_2 ++ = strlen ( V_133 ) + 1 ;
* V_2 ++ = 0x81 ;
while ( * V_133 )
* V_2 ++ = * V_133 ++ & 0x7f ;
if ( V_135 ) {
* V_135 ++ = '.' ;
* V_2 ++ = V_146 ;
* V_2 ++ = strlen ( V_135 ) + 2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = 0x50 ;
while ( * V_135 )
* V_2 ++ = * V_135 ++ & 0x7f ;
}
}
#ifdef F_47
if ( ( V_17 -> V_66 . V_137 . V_127 >= 160 ) && ( V_17 -> V_66 . V_137 . V_127 <= 175 ) ) {
* V_2 ++ = V_147 ;
* V_2 ++ = 0x04 ;
* V_2 ++ = 0x88 ;
* V_2 ++ = 0x90 ;
* V_2 ++ = 0x21 ;
* V_2 ++ = F_40 ( V_17 -> V_66 . V_137 . V_127 - 160 , 0x80 ) ;
} else if ( ( V_17 -> V_66 . V_137 . V_127 >= 176 ) && ( V_17 -> V_66 . V_137 . V_127 <= 191 ) ) {
* V_2 ++ = V_147 ;
* V_2 ++ = 0x05 ;
* V_2 ++ = 0x88 ;
* V_2 ++ = 0x90 ;
* V_2 ++ = 0x28 ;
* V_2 ++ = F_40 ( V_17 -> V_66 . V_137 . V_127 - 176 , 0 ) ;
* V_2 ++ = 0x82 ;
} else if ( V_17 -> V_66 . V_137 . V_127 >= 192 ) {
* V_2 ++ = V_147 ;
* V_2 ++ = 0x06 ;
* V_2 ++ = 0x88 ;
* V_2 ++ = 0x90 ;
* V_2 ++ = 0x21 ;
V_2 = F_39 ( V_2 , V_17 -> V_66 . V_137 . V_127 - 192 ) ;
#ifndef F_48
} else {
switch ( V_17 -> V_66 . V_137 . V_139 ) {
case 1 :
* V_2 ++ = V_147 ;
* V_2 ++ = 0x3 ;
* V_2 ++ = 0x90 ;
* V_2 ++ = 0x90 ;
* V_2 ++ = 0xa3 ;
break;
case 5 :
case 7 :
default:
* V_2 ++ = V_147 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x88 ;
* V_2 ++ = 0x90 ;
break;
}
#endif
}
#endif
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_9 ( & V_17 -> V_25 ) ;
F_37 ( & V_17 -> V_25 , V_148 , V_149 ) ;
F_36 ( V_17 , 1 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
}
static void
F_49 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_9 , V_75 ;
if ( ( V_9 = F_30 ( V_17 , V_57 ) ) >= 0 ) {
if ( ( 0 == V_9 ) || ( ( 3 == V_9 ) && ( 0x10 == V_17 -> V_66 . V_150 ) ) ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_54 , V_9 ) ;
V_17 -> V_66 . V_60 = 100 ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_17 -> V_66 . V_151 = V_9 ;
} else if ( 1 == V_17 -> V_68 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_55 , V_9 ) ;
if ( V_9 == - 1 )
V_17 -> V_66 . V_60 = 96 ;
else
V_17 -> V_66 . V_60 = 100 ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_75 = F_27 ( V_17 , V_57 , V_152 ) ;
if ( V_89 == V_75 ) {
F_29 ( V_17 , V_75 ) ;
return;
}
F_9 ( & V_17 -> V_25 ) ;
F_36 ( V_17 , 3 ) ;
F_37 ( & V_17 -> V_25 , V_153 , V_154 ) ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_155 | V_54 , V_17 ) ;
}
static void
F_50 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_9 , V_75 ;
if ( ( V_9 = F_30 ( V_17 , V_57 ) ) >= 0 ) {
if ( ( 0 == V_9 ) || ( ( 3 == V_9 ) && ( 0x10 == V_17 -> V_66 . V_150 ) ) ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_54 , V_9 ) ;
V_17 -> V_66 . V_60 = 100 ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_17 -> V_66 . V_151 = V_9 ;
} else {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_55 , V_9 ) ;
if ( V_9 == - 1 )
V_17 -> V_66 . V_60 = 96 ;
else
V_17 -> V_66 . V_60 = 100 ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_75 = F_27 ( V_17 , V_57 , V_156 ) ;
if ( V_89 == V_75 ) {
F_29 ( V_17 , V_75 ) ;
return;
}
F_9 ( & V_17 -> V_25 ) ;
F_36 ( V_17 , 2 ) ;
F_37 ( & V_17 -> V_25 , V_157 , V_158 ) ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_159 | V_54 , V_17 ) ;
}
static void
F_51 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
T_1 * V_2 ;
int V_75 ;
T_1 V_60 = 0 ;
F_35 ( V_17 ) ;
if ( ( V_75 = F_32 ( V_17 , V_57 ) ) ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_56 , V_75 ) ;
if ( V_75 < 0 )
V_60 = 96 ;
else if ( V_75 > 0 )
V_60 = 100 ;
}
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_160 , 0 ) ) )
F_13 ( V_17 -> V_11 , V_17 , V_17 -> V_19 , V_2 ) ;
V_75 = F_27 ( V_17 , V_57 , V_161 ) ;
if ( V_89 == V_75 )
V_60 = 96 ;
else if ( ( ! V_60 ) && ( V_90 == V_75 ) )
V_60 = 99 ;
V_75 = V_17 -> V_68 ;
F_36 ( V_17 , 12 ) ;
if ( V_60 )
F_36 ( V_17 , 19 ) ;
if ( 11 != V_75 )
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_162 | V_54 , V_17 ) ;
else if ( ! V_60 )
F_34 ( V_17 , V_64 , NULL ) ;
if ( V_60 ) {
F_21 ( V_17 , V_102 , V_60 ) ;
F_37 ( & V_17 -> V_25 , V_122 , V_123 ) ;
}
}
static void
F_52 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_75 ;
V_75 = F_27 ( V_17 , V_57 , V_163 ) ;
if ( V_89 == V_75 ) {
F_29 ( V_17 , V_75 ) ;
return;
}
F_9 ( & V_17 -> V_25 ) ;
F_36 ( V_17 , 10 ) ;
V_17 -> V_66 . V_164 = 0 ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_165 | V_126 , V_17 ) ;
}
static void
F_53 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_75 ;
V_75 = F_27 ( V_17 , V_57 , V_166 ) ;
if ( V_89 == V_75 ) {
F_29 ( V_17 , V_75 ) ;
return;
}
F_9 ( & V_17 -> V_25 ) ;
F_36 ( V_17 , 4 ) ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_167 | V_54 , V_17 ) ;
}
static void
F_54 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
T_1 * V_2 ;
int V_168 = 0 ;
char V_61 [ 80 ] ;
struct V_56 * V_57 = V_32 ;
int V_9 ;
int V_169 = 0 ;
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , 0x04 , 0 ) ) ) {
if ( ( V_2 [ 1 ] < 2 ) || ( V_2 [ 1 ] > 11 ) )
V_169 = 1 ;
else {
V_17 -> V_66 . V_137 . V_127 = 0 ;
switch ( V_2 [ 2 ] & 0x7f ) {
case 0x00 :
case 0x10 :
V_17 -> V_66 . V_137 . V_139 = 1 ;
break;
case 0x08 :
V_17 -> V_66 . V_137 . V_139 = 7 ;
#ifdef F_47
V_17 -> V_66 . V_137 . V_127 = F_43 ( V_57 ) ;
#endif
break;
case 0x09 :
V_17 -> V_66 . V_137 . V_139 = 2 ;
break;
case 0x11 :
V_17 -> V_66 . V_137 . V_139 = 3 ;
break;
case 0x18 :
V_17 -> V_66 . V_137 . V_139 = 4 ;
break;
default:
V_169 = 2 ;
break;
}
switch ( V_2 [ 3 ] & 0x7f ) {
case 0x40 :
V_17 -> V_66 . V_137 . V_139 = 8 ;
break;
case 0x10 :
case 0x11 :
case 0x13 :
case 0x15 :
case 0x17 :
V_17 -> V_66 . V_150 = V_2 [ 3 ] & 0x7f ;
break;
default:
V_169 = 3 ;
break;
}
}
if ( V_17 -> V_86 & V_170 )
F_10 ( V_17 -> V_11 , L_57 ,
V_17 -> V_66 . V_137 . V_139 , V_17 -> V_66 . V_137 . V_127 ) ;
if ( V_169 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_58 ,
V_2 [ 1 ] , V_2 [ 2 ] , V_2 [ 3 ] ) ;
V_17 -> V_66 . V_60 = 100 ;
F_23 ( V_17 , V_64 , NULL ) ;
return;
}
} else {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_59 ) ;
V_17 -> V_66 . V_60 = 96 ;
F_23 ( V_17 , V_64 , NULL ) ;
return;
}
if ( ( V_9 = F_30 ( V_17 , V_57 ) ) >= 0 ) {
if ( ( V_17 -> V_66 . V_151 = V_9 ) ) {
if ( ( 3 == V_9 ) && ( 0x10 == V_17 -> V_66 . V_150 ) ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_60 ,
V_9 ) ;
V_17 -> V_66 . V_60 = 100 ;
F_23 ( V_17 , V_64 , NULL ) ;
return;
}
V_168 ++ ;
} else
{ if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_61 ) ;
V_168 ++ ;
}
} else {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_62 , V_9 ) ;
if ( V_9 == - 1 )
V_17 -> V_66 . V_60 = 96 ;
else
V_17 -> V_66 . V_60 = 100 ;
F_23 ( V_17 , V_64 , NULL ) ;
return;
}
V_169 = F_27 ( V_17 , V_57 , V_171 ) ;
if ( V_89 == V_169 ) {
V_17 -> V_66 . V_60 = 96 ;
F_23 ( V_17 , V_64 , NULL ) ;
return;
}
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , 0x70 , 0 ) ) )
F_55 ( V_17 -> V_66 . V_137 . V_142 , V_2 , 1 ) ;
else
V_17 -> V_66 . V_137 . V_142 [ 0 ] = 0 ;
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , 0x71 , 0 ) ) ) {
if ( ( V_2 [ 1 ] >= 2 ) && ( V_2 [ 2 ] == 0x80 ) && ( V_2 [ 3 ] == 0x50 ) ) {
V_61 [ 0 ] = '.' ;
F_55 ( & V_61 [ 1 ] , V_2 , 2 ) ;
strcat ( V_17 -> V_66 . V_137 . V_142 , V_61 ) ;
} else if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_63 ) ;
}
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , 0x6c , 0 ) ) ) {
V_17 -> V_66 . V_137 . V_172 = V_2 [ 2 ] ;
if ( V_2 [ 2 ] & 0x80 ) {
F_55 ( V_17 -> V_66 . V_137 . V_138 , V_2 , 1 ) ;
V_17 -> V_66 . V_137 . V_132 = 0 ;
} else {
F_55 ( V_17 -> V_66 . V_137 . V_138 , V_2 , 2 ) ;
V_17 -> V_66 . V_137 . V_132 = V_2 [ 3 ] ;
}
} else {
V_17 -> V_66 . V_137 . V_138 [ 0 ] = 0 ;
V_17 -> V_66 . V_137 . V_172 = 0 ;
V_17 -> V_66 . V_137 . V_132 = 0 ;
}
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , 0x6d , 0 ) ) ) {
if ( ( V_2 [ 1 ] >= 2 ) && ( V_2 [ 2 ] == 0x80 ) && ( V_2 [ 3 ] == 0x50 ) ) {
V_61 [ 0 ] = '.' ;
F_55 ( & V_61 [ 1 ] , V_2 , 2 ) ;
strcat ( V_17 -> V_66 . V_137 . V_138 , V_61 ) ;
} else if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_64 ) ;
}
F_36 ( V_17 , 6 ) ;
if ( V_169 )
F_29 ( V_17 , V_169 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_165 | V_54 , V_17 ) ;
}
static void
F_56 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_5 ( V_17 ) ;
}
static void
F_57 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 ;
T_1 V_61 [ 16 + 40 ] ;
T_1 * V_2 = V_61 ;
int V_62 ;
T_1 V_60 = 16 ;
if ( V_17 -> V_66 . V_60 != V_124 )
V_60 = V_17 -> V_66 . V_60 ;
F_35 ( V_17 ) ;
F_19 ( V_2 , V_17 -> V_19 , V_97 ) ;
* V_2 ++ = V_63 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = V_60 | 0x80 ;
if ( V_17 -> V_5 . V_6 . V_16 [ 0 ] )
{ * V_2 ++ = V_121 ;
* V_2 ++ = strlen ( V_17 -> V_5 . V_6 . V_16 ) + 1 ;
* V_2 ++ = 0x04 ;
strcpy ( V_2 , V_17 -> V_5 . V_6 . V_16 ) ;
V_2 += strlen ( V_17 -> V_5 . V_6 . V_16 ) ;
V_17 -> V_5 . V_6 . V_16 [ 0 ] = '\0' ;
}
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_36 ( V_17 , 11 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
F_37 ( & V_17 -> V_25 , V_173 , V_174 ) ;
}
static void
F_58 ( struct V_10 * V_17 , T_1 V_64 ,
void * V_32 )
{
if ( ! V_17 -> V_66 . V_151 )
{ if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_65 ) ;
F_57 ( V_17 , V_64 , V_32 ) ;
return;
}
F_36 ( V_17 , 8 ) ;
F_16 ( V_17 , V_95 ) ;
F_9 ( & V_17 -> V_25 ) ;
F_37 ( & V_17 -> V_25 , V_175 , V_176 ) ;
}
static void
F_59 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_75 ;
V_75 = F_27 ( V_17 , V_57 , V_177 ) ;
if ( V_89 == V_75 ) {
F_29 ( V_17 , V_75 ) ;
return;
}
F_36 ( V_17 , 10 ) ;
F_9 ( & V_17 -> V_25 ) ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_178 | V_54 , V_17 ) ;
}
static void
F_60 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 ;
T_1 V_61 [ 16 ] ;
T_1 * V_2 = V_61 ;
int V_62 ;
T_1 V_60 = 21 ;
if ( V_17 -> V_66 . V_60 != V_124 )
V_60 = V_17 -> V_66 . V_60 ;
F_19 ( V_2 , V_17 -> V_19 , V_69 ) ;
* V_2 ++ = V_63 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = V_60 | 0x80 ;
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_125 | V_54 , V_17 ) ;
F_36 ( V_17 , 0 ) ;
F_5 ( V_17 ) ;
}
static void
F_61 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
T_1 * V_2 ;
int V_75 , V_60 = 0 ;
F_35 ( V_17 ) ;
if ( ( V_75 = F_32 ( V_17 , V_57 ) ) > 0 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_66 , V_75 ) ;
} else if ( V_75 < 0 )
V_17 -> V_66 . V_60 = V_124 ;
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_160 , 0 ) ) ) {
F_13 ( V_17 -> V_11 , V_17 , V_17 -> V_19 , V_2 ) ;
}
if ( ( V_75 < 0 ) && ( V_17 -> V_68 != 11 ) )
V_60 = 96 ;
else if ( V_75 > 0 )
V_60 = 100 ;
V_75 = F_27 ( V_17 , V_57 , V_179 ) ;
if ( V_89 == V_75 )
V_60 = 96 ;
else if ( ( V_90 == V_75 ) && ( ! V_60 ) )
V_60 = 99 ;
if ( V_60 )
F_21 ( V_17 , V_69 , V_60 ) ;
else
F_16 ( V_17 , V_69 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_125 | V_54 , V_17 ) ;
F_36 ( V_17 , 0 ) ;
F_5 ( V_17 ) ;
}
static void
F_62 ( struct V_10 * V_17 , T_1 V_64 ,
void * V_32 )
{
F_36 ( V_17 , 7 ) ;
if ( ! V_17 -> V_5 . V_6 . V_16 [ 0 ] )
F_16 ( V_17 , V_93 ) ;
else
F_33 ( V_17 , V_93 ) ;
}
static void
F_63 ( struct V_10 * V_17 , T_1 V_64 ,
void * V_32 )
{
F_36 ( V_17 , 9 ) ;
F_16 ( V_17 , V_94 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_180 | V_54 , V_17 ) ;
}
static void
F_64 ( struct V_10 * V_17 , T_1 V_64 ,
void * V_32 )
{
F_36 ( V_17 , 25 ) ;
F_9 ( & V_17 -> V_25 ) ;
F_37 ( & V_17 -> V_25 , V_181 , V_182 ) ;
F_16 ( V_17 , V_104 ) ;
}
static void
F_65 ( struct V_10 * V_17 , int V_64 , T_1 * V_183 )
{ T_1 V_73 ;
T_2 V_22 ;
struct V_23 * V_24 ;
char * V_2 ;
if ( * V_183 ++ != V_184 ) return;
if ( ( V_73 = * V_183 ++ ) > 80 ) return;
if ( ! V_17 -> V_185 ) return;
V_2 = V_22 . V_34 . V_186 ;
while ( V_73 -- )
* V_2 ++ = * V_183 ++ ;
* V_2 = '\0' ;
V_22 . V_30 = V_187 ;
V_24 = V_17 -> V_11 -> V_26 . V_27 ;
V_22 . V_28 = V_24 -> V_29 ;
V_22 . V_32 = V_17 -> V_185 -> V_185 ;
V_24 -> V_41 . V_42 ( & V_22 ) ;
}
static void
F_66 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_169 = 0 ;
T_1 * V_2 ;
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_188 , 0 ) ) ) {
if ( V_2 [ 1 ] != 2 ) {
V_169 = 1 ;
V_17 -> V_66 . V_60 = 100 ;
} else if ( ! ( V_2 [ 2 ] & 0x70 ) ) {
switch ( V_2 [ 2 ] ) {
case 0x80 :
case 0x81 :
case 0x82 :
case 0x84 :
case 0x85 :
case 0x87 :
case 0x8a :
switch ( V_2 [ 3 ] ) {
case 0x81 :
case 0x82 :
case 0x83 :
case 0x84 :
case 0x88 :
break;
default:
V_169 = 2 ;
V_17 -> V_66 . V_60 = 100 ;
break;
}
break;
default:
V_169 = 3 ;
V_17 -> V_66 . V_60 = 100 ;
break;
}
}
} else {
V_17 -> V_66 . V_60 = 96 ;
V_169 = 4 ;
}
if ( V_169 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_67 , V_169 ) ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_169 = F_27 ( V_17 , V_57 , V_189 ) ;
if ( V_169 )
F_29 ( V_17 , V_169 ) ;
if ( V_89 != V_169 )
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_190 | V_54 , V_17 ) ;
}
static void
F_67 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_169 = 0 ;
T_1 * V_2 ;
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_191 , 0 ) ) ) {
if ( V_2 [ 1 ] != 1 ) {
V_169 = 1 ;
V_17 -> V_66 . V_60 = 100 ;
} else {
switch ( V_2 [ 2 ] ) {
case 0x80 :
case 0x81 :
case 0x82 :
break;
default:
V_17 -> V_66 . V_60 = 100 ;
V_169 = 2 ;
break;
}
}
} else {
V_17 -> V_66 . V_60 = 96 ;
V_169 = 3 ;
}
if ( V_169 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_68 , V_169 ) ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_169 = F_27 ( V_17 , V_57 , V_192 ) ;
if ( V_169 )
F_29 ( V_17 , V_169 ) ;
if ( V_89 != V_169 )
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_193 | V_54 , V_17 ) ;
}
static void
F_68 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
int V_75 ;
struct V_56 * V_57 = V_32 ;
V_75 = F_27 ( V_17 , V_57 , V_194 ) ;
F_29 ( V_17 , V_75 ) ;
V_17 -> V_66 . V_60 = 30 ;
F_22 ( V_17 , V_64 , NULL ) ;
}
static void
F_69 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
int V_75 ;
struct V_56 * V_57 = V_32 ;
T_1 * V_2 ;
char V_61 [ 32 ] ;
V_75 = F_27 ( V_17 , V_57 , V_195 ) ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
if ( V_17 -> V_68 == 25 ) {
F_9 ( & V_17 -> V_25 ) ;
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , 0x70 , 0 ) ) ) {
F_55 ( V_61 , V_2 , 1 ) ;
strcat ( V_17 -> V_66 . V_137 . V_142 , V_61 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_159 | V_54 , V_17 ) ;
}
F_37 ( & V_17 -> V_25 , V_181 , V_182 ) ;
}
}
static void F_70 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 ;
T_1 V_61 [ 128 ] ;
T_1 * V_2 = V_61 ;
T_1 * V_196 ;
T_1 V_197 = 0 ;
T_1 V_198 = 0 ;
int V_62 ;
strcpy ( V_17 -> V_5 . V_6 . V_16 , V_17 -> V_185 -> V_137 . V_142 ) ;
if ( ! V_17 -> V_185 -> V_137 . V_138 [ 0 ] )
{ V_17 -> V_66 . V_60 = - 1 ;
F_57 ( V_17 , V_64 , V_32 ) ;
return;
}
if ( V_17 -> V_5 . V_6 . V_14 )
F_2 ( V_17 -> V_11 , V_17 -> V_5 . V_6 . V_14 ) ;
if ( ! ( V_17 -> V_5 . V_6 . V_14 = F_1 ( V_17 -> V_11 ) ) )
return;
F_19 ( V_2 , V_17 -> V_19 , V_99 ) ;
for ( V_196 = V_17 -> V_185 -> V_137 . V_138 ; ( * V_196 ) && ( * V_196 != '.' ) ; V_196 ++ ) V_197 ++ ;
if ( * V_196 ++ == '.' ) V_198 = strlen ( V_196 ) + 2 ;
* V_2 ++ = 0x1c ;
* V_2 ++ = V_197 + V_198 + 2 + 2 + 8 + 3 + 3 ;
* V_2 ++ = 0x91 ;
* V_2 ++ = 0xa1 ;
* V_2 ++ = V_197 + V_198 + 2 + 2 + 8 + 3 ;
* V_2 ++ = 0x02 ;
* V_2 ++ = 0x01 ;
* V_2 ++ = V_17 -> V_5 . V_6 . V_14 ;
* V_2 ++ = 0x02 ;
* V_2 ++ = 0x01 ;
* V_2 ++ = 0x0D ;
* V_2 ++ = 0x30 ;
* V_2 ++ = V_197 + 2 + 2 + 3 + V_198 ;
* V_2 ++ = 0x30 ;
* V_2 ++ = V_197 + 2 + V_198 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = V_197 ;
for ( V_62 = 0 ; V_62 < V_197 ; V_62 ++ )
* V_2 ++ = V_17 -> V_185 -> V_137 . V_138 [ V_62 ] ;
if ( V_198 )
{ * V_2 ++ = 0x04 ;
* V_2 ++ = V_198 - 2 ;
while ( * V_196 ) * V_2 ++ = * V_196 ++ ;
}
* V_2 ++ = 0x01 ;
* V_2 ++ = 0x01 ;
* V_2 ++ = V_17 -> V_185 -> V_137 . V_132 ;
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) ) return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
}
static void F_71 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_63 ( V_17 , V_64 , V_32 ) ;
F_70 ( V_17 , V_64 , V_32 ) ;
}
static int F_72 ( struct V_1 * V_11 , T_2 * V_22 )
{ T_1 V_9 ;
T_1 V_199 [ 265 ] ;
T_1 * V_2 = V_199 ;
int V_4 , V_62 , V_200 ;
struct V_56 * V_57 ;
struct V_10 * V_17 = NULL ;
switch ( V_22 -> V_32 )
{ case V_201 :
if ( V_22 -> V_34 . V_35 . V_39 < 0 ) return ( - 2 ) ;
for ( V_200 = 1 , V_4 = V_22 -> V_34 . V_35 . V_13 >> 8 ; V_4 ; V_4 ++ )
V_4 = V_4 >> 8 ;
V_62 = V_22 -> V_34 . V_35 . V_39 + V_200 + 8 ;
if ( V_62 > 255 )
return ( - 2 ) ;
if ( ! ( V_9 = F_1 ( V_11 ) ) )
return ( 0 ) ;
V_4 = - 1 ;
F_19 ( V_2 , V_4 , V_99 ) ;
* V_2 ++ = 0x1C ;
* V_2 ++ = V_62 ;
* V_2 ++ = 0x91 ;
* V_2 ++ = 0xA1 ;
* V_2 ++ = V_62 - 3 ;
* V_2 ++ = 0x02 ;
* V_2 ++ = 0x01 ;
* V_2 ++ = V_9 ;
* V_2 ++ = 0x02 ;
* V_2 ++ = V_200 ;
for ( V_4 = V_200 ; V_4 ; V_4 -- )
* V_2 ++ = ( V_22 -> V_34 . V_35 . V_13 >> ( V_4 - 1 ) ) & 0xFF ;
memcpy ( V_2 , V_22 -> V_34 . V_35 . V_40 , V_22 -> V_34 . V_35 . V_39 ) ;
V_62 = ( V_2 - V_199 ) + V_22 -> V_34 . V_35 . V_39 ;
if ( V_22 -> V_34 . V_35 . V_38 > 0 )
if ( ! ( V_17 = F_3 ( V_11 , - 1 ) ) )
{ F_2 ( V_11 , V_9 ) ;
return ( - 2 ) ;
}
V_17 -> V_5 . V_6 . V_37 = V_22 -> V_34 . V_35 . V_37 ;
V_17 -> V_5 . V_6 . V_13 = V_22 -> V_34 . V_35 . V_13 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
{ F_2 ( V_11 , V_9 ) ;
if ( V_17 ) F_5 ( V_17 ) ;
return ( - 2 ) ;
}
memcpy ( F_18 ( V_57 , V_62 ) , V_199 , V_62 ) ;
if ( V_17 )
{ V_17 -> V_5 . V_6 . V_14 = V_9 ;
F_37 ( & V_17 -> V_25 , V_22 -> V_34 . V_35 . V_38 , V_202 | V_59 ) ;
}
F_20 ( V_11 , V_58 | V_59 , V_57 ) ;
V_22 -> V_34 . V_35 . V_36 = V_9 ;
return ( 0 ) ;
case V_203 :
if ( ( V_17 = F_7 ( V_11 , V_22 -> V_34 . V_35 . V_36 ) ) )
{ F_9 ( & V_17 -> V_25 ) ;
F_5 ( V_17 ) ;
return ( 0 ) ;
}
else
{ F_10 ( V_11 , L_69 ) ;
return ( - 2 ) ;
}
break;
default:
F_10 ( V_11 , L_70 , V_22 -> V_32 ) ;
return ( - 1 ) ;
}
return ( - 1 ) ;
}
static void
F_73 ( struct V_10 * V_17 )
{ T_2 V_22 ;
struct V_23 * V_24 = V_17 -> V_11 -> V_26 . V_27 ;
F_9 ( & V_17 -> V_25 ) ;
V_22 . V_28 = V_24 -> V_29 ;
V_22 . V_30 = V_31 ;
V_22 . V_32 = V_43 ;
V_22 . V_34 . V_35 . V_36 = V_17 -> V_5 . V_6 . V_14 ;
V_22 . V_34 . V_35 . V_37 = V_17 -> V_5 . V_6 . V_37 ;
V_22 . V_34 . V_35 . V_13 = V_17 -> V_5 . V_6 . V_13 ;
V_22 . V_34 . V_35 . V_38 = - 1 ;
V_22 . V_34 . V_35 . V_39 = 0 ;
V_22 . V_34 . V_35 . V_40 = NULL ;
F_2 ( V_17 -> V_11 , V_17 -> V_5 . V_6 . V_14 ) ;
V_17 -> V_5 . V_6 . V_14 = 0 ;
V_24 -> V_41 . V_42 ( & V_22 ) ;
F_5 ( V_17 ) ;
}
static void
F_74 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
T_1 * V_2 ;
struct V_56 * V_57 = V_32 ;
int V_204 = 0 ;
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , V_67 , 0 ) ) ) {
V_2 ++ ;
if ( 1 == * V_2 ++ )
V_204 = * V_2 ;
}
if ( V_204 == 0 ) {
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_125 | V_54 , V_17 ) ;
F_36 ( V_17 , 0 ) ;
F_5 ( V_17 ) ;
} else {
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_205 | V_54 , V_17 ) ;
}
}
static void
F_75 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
}
static void
F_76 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_66 . V_118 = 0 ;
V_17 -> V_66 . V_60 = 28 ;
F_57 ( V_17 , V_64 , NULL ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_206 , V_17 ) ;
}
static void
F_77 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
if ( V_17 -> V_207 > 0 ) {
V_17 -> V_207 -- ;
F_9 ( & V_17 -> V_25 ) ;
F_44 ( V_17 , V_64 , V_32 ) ;
} else {
F_9 ( & V_17 -> V_25 ) ;
F_21 ( V_17 , V_69 , 102 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_208 , V_17 ) ;
F_5 ( V_17 ) ;
}
}
static void
F_78 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_66 . V_118 = 0 ;
V_17 -> V_66 . V_60 = 102 ;
F_57 ( V_17 , V_64 , NULL ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_206 , V_17 ) ;
}
static void
F_79 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
T_1 V_61 [ 16 ] ;
T_1 * V_2 = V_61 ;
int V_62 ;
struct V_56 * V_57 ;
T_1 V_60 = 16 ;
F_9 ( & V_17 -> V_25 ) ;
if ( V_17 -> V_66 . V_60 != V_124 )
V_60 = V_17 -> V_66 . V_60 ;
F_19 ( V_2 , V_17 -> V_19 , V_102 ) ;
* V_2 ++ = V_63 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = V_60 | 0x80 ;
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_36 ( V_17 , 19 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
F_37 ( & V_17 -> V_25 , V_122 , V_123 ) ;
}
static void
F_80 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_66 . V_118 = 0 ;
V_17 -> V_66 . V_60 = 102 ;
F_57 ( V_17 , V_64 , NULL ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_206 , V_17 ) ;
}
static void
F_81 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_66 . V_118 = 0 ;
V_17 -> V_66 . V_60 = 102 ;
F_57 ( V_17 , V_64 , NULL ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_209 , V_17 ) ;
}
static void
F_82 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_36 ( V_17 , 19 ) ;
F_9 ( & V_17 -> V_25 ) ;
F_16 ( V_17 , V_102 ) ;
F_37 ( & V_17 -> V_25 , V_122 , V_210 ) ;
}
static void
F_83 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_211 , V_17 ) ;
F_5 ( V_17 ) ;
}
static void
F_84 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_66 . V_60 = 102 ;
V_17 -> V_66 . V_118 = 0 ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_212 , V_17 ) ;
F_36 ( V_17 , 19 ) ;
F_16 ( V_17 , V_102 ) ;
F_37 ( & V_17 -> V_25 , V_122 , V_123 ) ;
}
static void
F_85 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_66 . V_60 = 102 ;
V_17 -> V_66 . V_118 = 0 ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_213 , V_17 ) ;
F_36 ( V_17 , 10 ) ;
}
static void
F_86 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_125 | V_54 , V_17 ) ;
F_5 ( V_17 ) ;
}
static void
F_87 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
T_1 * V_2 ;
struct V_56 * V_57 = V_32 ;
int V_75 ;
T_1 V_60 = 0 , V_204 = 0 ;
if ( ( V_75 = F_32 ( V_17 , V_57 ) ) ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_71 , V_75 ) ;
if ( V_75 < 0 )
V_60 = 96 ;
else if ( V_75 > 0 )
V_60 = 100 ;
}
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_67 , 0 ) ) ) {
V_2 ++ ;
if ( 1 == * V_2 ++ ) {
V_204 = * V_2 ;
if ( ! F_26 ( V_17 , * V_2 , V_214 ) )
V_60 = 100 ;
} else
V_60 = 100 ;
} else
V_60 = 96 ;
if ( ! V_60 ) {
V_75 = F_27 ( V_17 , V_57 , V_215 ) ;
if ( V_89 == V_75 )
V_60 = 96 ;
else if ( V_90 == V_75 )
V_60 = 99 ;
}
if ( V_60 ) {
T_1 V_61 ;
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_72 , V_75 , V_60 ) ;
V_61 = V_17 -> V_66 . V_60 ;
V_17 -> V_66 . V_60 = V_60 ;
F_22 ( V_17 , 0 , NULL ) ;
if ( V_60 == 99 )
V_17 -> V_66 . V_60 = V_61 ;
else
return;
}
V_60 = V_17 -> V_66 . V_60 ;
if ( ( ( V_60 & 0x7f ) == 111 ) && ( V_204 == 0 ) ) {
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_125 | V_54 , V_17 ) ;
F_36 ( V_17 , 0 ) ;
F_5 ( V_17 ) ;
}
}
static void
F_88 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_75 ;
V_75 = F_27 ( V_17 , V_57 , V_216 ) ;
F_29 ( V_17 , V_75 ) ;
{
T_1 * V_2 ;
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_160 , 0 ) ) )
F_13 ( V_17 -> V_11 , V_17 , V_17 -> V_19 , V_2 ) ;
}
}
static void
F_89 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 ;
T_1 V_61 [ 32 ] ;
T_1 * V_2 = V_61 ;
T_1 V_4 , V_62 ;
T_1 * V_217 = V_17 -> V_185 -> V_137 . V_138 ;
F_19 ( V_2 , V_17 -> V_19 , V_115 ) ;
V_62 = * V_217 ++ ;
if ( V_62 && ( V_62 <= 10 ) ) {
* V_2 ++ = V_218 ;
* V_2 ++ = V_62 ;
for ( V_4 = 0 ; V_4 < V_62 ; V_4 ++ )
* V_2 ++ = * V_217 ++ ;
} else if ( V_62 ) {
F_10 ( V_17 -> V_11 , L_73 , V_62 ) ;
return;
}
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
F_36 ( V_17 , 15 ) ;
F_37 ( & V_17 -> V_25 , V_219 , V_220 ) ;
}
static void
F_90 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_75 ;
F_9 ( & V_17 -> V_25 ) ;
F_36 ( V_17 , 0 ) ;
V_17 -> V_66 . V_60 = V_124 ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_221 | V_126 , V_17 ) ;
if ( ( V_75 = F_27 ( V_17 , V_57 , V_222 ) ) )
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_74 , V_75 ) ;
F_5 ( V_17 ) ;
}
static void
F_91 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_75 ;
if ( ( V_75 = F_32 ( V_17 , V_57 ) ) ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_75 , V_75 ) ;
if ( V_75 < 0 )
V_17 -> V_66 . V_60 = 96 ;
else
V_17 -> V_66 . V_60 = 100 ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_75 = F_27 ( V_17 , V_57 , V_223 ) ;
if ( V_89 == V_75 ) {
F_29 ( V_17 , V_75 ) ;
return;
}
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_213 , V_17 ) ;
F_36 ( V_17 , 10 ) ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
}
static void
F_92 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 ;
T_1 V_61 [ 32 ] ;
T_1 * V_2 = V_61 ;
T_1 V_4 , V_62 ;
T_1 * V_217 = V_17 -> V_66 . V_137 . V_138 ;
F_19 ( V_2 , V_17 -> V_19 , V_114 ) ;
V_62 = * V_217 ++ ;
if ( V_62 && ( V_62 <= 10 ) ) {
* V_2 ++ = V_218 ;
* V_2 ++ = V_62 ;
for ( V_4 = 0 ; V_4 < V_62 ; V_4 ++ )
* V_2 ++ = * V_217 ++ ;
} else if ( V_62 ) {
F_10 ( V_17 -> V_11 , L_76 , V_62 ) ;
return;
}
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
F_36 ( V_17 , 17 ) ;
F_37 ( & V_17 -> V_25 , V_224 , V_225 ) ;
}
static void
F_93 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_9 , V_75 ;
if ( ( V_9 = F_30 ( V_17 , V_57 ) ) > 0 ) {
if ( ( 0 == V_9 ) || ( ( 3 == V_9 ) && ( 0x10 == V_17 -> V_66 . V_150 ) ) ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_77 , V_9 ) ;
V_17 -> V_66 . V_60 = 100 ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_17 -> V_66 . V_151 = V_9 ;
} else if ( 1 == V_17 -> V_68 ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_78 , V_9 ) ;
V_17 -> V_66 . V_60 = 96 ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_75 = F_27 ( V_17 , V_57 , V_226 ) ;
if ( V_89 == V_75 ) {
F_29 ( V_17 , V_75 ) ;
return;
}
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_227 | V_126 , V_17 ) ;
F_36 ( V_17 , 10 ) ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
}
static void
F_94 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
struct V_56 * V_57 = V_32 ;
int V_75 ;
if ( ( V_75 = F_32 ( V_17 , V_57 ) ) ) {
if ( V_17 -> V_86 & V_116 )
F_10 ( V_17 -> V_11 , L_79 , V_75 ) ;
if ( V_75 < 0 )
V_17 -> V_66 . V_60 = 96 ;
else
V_17 -> V_66 . V_60 = 100 ;
F_22 ( V_17 , V_64 , NULL ) ;
return;
}
V_75 = F_27 ( V_17 , V_57 , V_228 ) ;
if ( V_89 == V_75 ) {
F_29 ( V_17 , V_75 ) ;
return;
}
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_212 , V_17 ) ;
F_36 ( V_17 , 0 ) ;
if ( V_75 )
F_29 ( V_17 , V_75 ) ;
F_5 ( V_17 ) ;
}
static void
F_95 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
T_1 V_61 [ 32 ] ;
T_1 * V_2 ;
T_1 V_229 , V_230 = 0 , V_185 = 0 ;
int V_62 ;
struct V_56 * V_57 = V_32 ;
struct V_10 * V_231 ;
F_36 ( V_17 , 2 ) ;
F_9 ( & V_17 -> V_25 ) ;
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , V_232 , 0 ) ) ) {
V_229 = V_2 [ 2 ] ;
F_10 ( V_17 -> V_11 , L_80 , V_229 ) ;
} else {
F_10 ( V_17 -> V_11 , L_81 ) ;
V_229 = 0x86 ;
}
V_2 = V_57 -> V_40 ;
if ( ( V_2 = F_31 ( V_2 , V_57 -> V_73 , V_117 , 0 ) ) ) {
V_185 = V_2 [ 2 ] & 3 ;
V_230 = V_2 [ 2 ] ;
if ( V_17 -> V_11 -> V_18 . V_86 )
F_10 ( V_17 -> V_11 , L_82 , V_185 ) ;
}
F_36 ( V_17 , 2 ) ;
V_231 = V_17 -> V_11 -> V_18 . V_13 ;
while ( V_231 ) {
if ( ( V_229 & 7 ) == 7 )
V_231 -> V_11 -> V_233 . V_234 ( V_231 -> V_11 , V_235 | V_59 , V_231 ) ;
else if ( V_231 -> V_66 . V_151 == V_185 )
V_231 -> V_11 -> V_233 . V_234 ( V_231 -> V_11 , V_235 | V_59 , V_231 ) ;
V_231 = V_231 -> V_20 ;
}
V_2 = V_61 ;
F_19 ( V_2 , V_17 -> V_19 , V_111 ) ;
if ( V_185 ) {
* V_2 ++ = V_117 ;
* V_2 ++ = 1 ;
* V_2 ++ = V_230 | 0x80 ;
}
* V_2 ++ = 0x79 ;
* V_2 ++ = 1 ;
* V_2 ++ = V_229 ;
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_36 ( V_17 , 0 ) ;
F_20 ( V_17 -> V_11 , V_58 | V_59 , V_57 ) ;
}
static void
F_96 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
V_17 -> V_66 . V_60 = 0x29 ;
V_17 -> V_66 . V_118 = 0 ;
F_57 ( V_17 , V_64 , NULL ) ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_206 , V_17 ) ;
}
static void
F_97 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_36 ( V_17 , 0 ) ;
V_17 -> V_66 . V_60 = 0x1b ;
V_17 -> V_66 . V_118 = 0 ;
V_17 -> V_11 -> V_18 . V_52 ( V_17 -> V_11 , V_125 | V_54 , V_17 ) ;
F_6 ( V_17 ) ;
}
static void
F_98 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
F_37 ( & V_17 -> V_25 , V_236 , V_237 ) ;
F_20 ( V_17 -> V_11 , V_238 | V_59 , NULL ) ;
}
static void
F_99 ( struct V_10 * V_17 , T_1 V_64 , void * V_32 )
{
F_9 ( & V_17 -> V_25 ) ;
V_17 -> V_66 . V_60 = 0x1F ;
F_22 ( V_17 , 0 , NULL ) ;
}
static void
F_100 ( struct V_1 * V_11 , int V_55 , struct V_56 * V_57 )
{
T_1 V_61 [ 16 ] ;
T_1 * V_2 = V_61 ;
int V_62 ;
int V_4 ;
struct V_10 * V_13 = V_11 -> V_18 . V_239 ;
V_13 -> V_19 = V_57 -> V_40 [ 2 ] ;
for ( V_4 = 0 ; V_4 < F_101 ( V_240 ) ; V_4 ++ )
if ( ( V_55 == V_240 [ V_4 ] . V_241 ) &&
( ( 1 << V_13 -> V_68 ) & V_240 [ V_4 ] . V_68 ) )
break;
if ( V_4 == F_101 ( V_240 ) ) {
if ( V_11 -> V_18 . V_86 & V_242 ) {
F_10 ( V_11 , L_83 ,
V_13 -> V_68 , V_55 ) ;
}
F_19 ( V_2 , V_13 -> V_19 , V_65 ) ;
* V_2 ++ = V_63 ;
* V_2 ++ = 0x2 ;
* V_2 ++ = 0x80 ;
* V_2 ++ = 81 | 0x80 ;
* V_2 ++ = 0x14 ;
* V_2 ++ = 0x1 ;
* V_2 ++ = V_13 -> V_68 & 0x3f ;
V_62 = V_2 - V_61 ;
if ( ! ( V_57 = F_17 ( V_62 ) ) )
return;
memcpy ( F_18 ( V_57 , V_62 ) , V_61 , V_62 ) ;
F_20 ( V_13 -> V_11 , V_58 | V_59 , V_57 ) ;
} else {
if ( V_11 -> V_18 . V_86 & V_242 ) {
F_10 ( V_11 , L_84 ,
V_13 -> V_68 , V_55 ) ;
}
V_240 [ V_4 ] . F_102 ( V_13 , V_55 , V_57 ) ;
}
}
static void
F_103 ( struct V_1 * V_11 , int V_64 , void * V_32 )
{
int V_4 , V_55 , V_12 , V_204 ;
char * V_243 ;
T_1 * V_2 ;
struct V_56 * V_57 = V_32 ;
struct V_10 * V_13 ;
switch ( V_64 ) {
case ( V_58 | V_54 ) :
case ( V_244 | V_54 ) :
break;
case ( V_238 | V_126 ) :
case ( V_238 | V_54 ) :
case ( V_245 | V_54 ) :
case ( V_245 | V_126 ) :
F_20 ( V_11 , V_64 , V_32 ) ;
return;
break;
default:
F_24 ( V_70 L_85 , V_64 ) ;
return;
}
if ( V_57 -> V_73 < 3 ) {
F_10 ( V_11 , L_86 , V_57 -> V_73 ) ;
F_104 ( V_57 ) ;
return;
}
if ( V_57 -> V_40 [ 0 ] != V_246 ) {
if ( V_11 -> V_18 . V_86 & V_247 ) {
F_10 ( V_11 , L_87 ,
( V_64 == ( V_58 | V_54 ) ) ? L_44 : L_88 ,
V_57 -> V_40 [ 0 ] , V_57 -> V_73 ) ;
}
F_104 ( V_57 ) ;
return;
}
V_12 = F_105 ( V_57 -> V_40 ) ;
if ( V_57 -> V_73 < ( ( V_57 -> V_40 [ 1 ] & 0x0f ) + 3 ) ) {
F_10 ( V_11 , L_86 , V_57 -> V_73 ) ;
F_104 ( V_57 ) ;
return;
}
V_55 = V_57 -> V_40 [ V_57 -> V_40 [ 1 ] + 2 ] ;
if ( V_11 -> V_18 . V_86 & V_242 )
F_10 ( V_11 , L_89 , V_12 ) ;
if ( V_12 == - 2 ) {
if ( V_11 -> V_18 . V_86 & V_116 )
F_10 ( V_11 , L_90 ) ;
F_104 ( V_57 ) ;
return;
} else if ( V_12 == - 1 ) {
if ( V_55 == V_99 )
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_160 , 0 ) ) ) {
F_13 ( V_11 , NULL ,
( V_64 == ( V_58 | V_54 ) ) ? - 1 : - 2 , V_2 ) ;
F_104 ( V_57 ) ;
return;
}
if ( V_11 -> V_18 . V_86 & V_116 )
F_10 ( V_11 , L_91 ) ;
F_104 ( V_57 ) ;
return;
} else if ( ( ( ( V_57 -> V_40 [ 1 ] & 0x0f ) == 1 ) && ( 0 == ( V_12 & 0x7f ) ) ) ||
( ( ( V_57 -> V_40 [ 1 ] & 0x0f ) == 2 ) && ( 0 == ( V_12 & 0x7fff ) ) ) ) {
if ( V_11 -> V_18 . V_86 & V_242 )
F_10 ( V_11 , L_92 ) ;
F_100 ( V_11 , V_55 , V_57 ) ;
F_104 ( V_57 ) ;
return;
} else if ( ! ( V_13 = F_106 ( V_11 , V_12 ) ) ) {
if ( V_55 == V_103 ) {
if ( V_57 -> V_40 [ 2 ] & 0x80 ) {
if ( V_11 -> V_18 . V_86 & V_242 )
F_10 ( V_11 , L_93 ) ;
F_104 ( V_57 ) ;
return;
}
if ( ! ( V_13 = F_3 ( V_11 , V_12 ) ) ) {
F_104 ( V_57 ) ;
return;
}
} else if ( V_55 == V_65 ) {
if ( ( V_243 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_63 , 0 ) ) != NULL ) {
V_243 ++ ;
if ( * V_243 ++ == 2 )
V_243 ++ ;
}
V_204 = 0 ;
if ( ( V_243 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_67 , 0 ) ) != NULL ) {
V_243 ++ ;
if ( * V_243 ++ == 2 )
V_243 ++ ;
V_204 = * V_243 ;
}
if ( V_204 != 0 ) {
if ( ( V_13 = F_3 ( V_11 , V_12 ) ) ) {
V_13 -> V_66 . V_60 = 101 ;
F_23 ( V_13 , 0 , NULL ) ;
}
}
F_104 ( V_57 ) ;
return;
} else if ( V_55 == V_69 ) {
F_104 ( V_57 ) ;
return;
} else {
F_104 ( V_57 ) ;
if ( ( V_13 = F_3 ( V_11 , V_12 ) ) ) {
V_13 -> V_66 . V_60 = 81 ;
F_23 ( V_13 , 0 , NULL ) ;
}
return;
}
}
if ( F_28 ( V_13 , V_55 , V_57 ) ) {
F_104 ( V_57 ) ;
return;
}
if ( ( V_2 = F_31 ( V_57 -> V_40 , V_57 -> V_73 , V_184 , 0 ) ) != NULL )
F_65 ( V_13 , V_64 , V_2 ) ;
for ( V_4 = 0 ; V_4 < F_101 ( V_248 ) ; V_4 ++ )
if ( ( V_55 == V_248 [ V_4 ] . V_241 ) &&
( ( 1 << V_13 -> V_68 ) & V_248 [ V_4 ] . V_68 ) )
break;
if ( V_4 == F_101 ( V_248 ) ) {
if ( V_11 -> V_18 . V_86 & V_242 ) {
F_10 ( V_11 , L_94 ,
( V_64 == ( V_58 | V_54 ) ) ? L_44 : L_88 ,
V_13 -> V_68 , V_55 ) ;
}
if ( ( V_69 != V_55 ) && ( V_102 != V_55 ) ) {
V_13 -> V_66 . V_60 = 101 ;
F_22 ( V_13 , V_64 , V_57 ) ;
}
} else {
if ( V_11 -> V_18 . V_86 & V_242 ) {
F_10 ( V_11 , L_95 ,
( V_64 == ( V_58 | V_54 ) ) ? L_44 : L_88 ,
V_13 -> V_68 , V_55 ) ;
}
V_248 [ V_4 ] . F_102 ( V_13 , V_64 , V_57 ) ;
}
F_104 ( V_57 ) ;
return;
}
static void
F_107 ( struct V_1 * V_11 , int V_64 , void * V_32 )
{
int V_4 , V_12 ;
struct V_10 * V_13 ;
struct V_249 * V_185 ;
if ( ( V_238 | V_59 ) == V_64 ) {
F_20 ( V_11 , V_64 , NULL ) ;
return;
} else if ( ( ( V_165 | V_59 ) == V_64 ) || ( ( V_227 | V_59 ) == V_64 ) ) {
V_185 = V_32 ;
V_12 = F_108 () ;
V_12 |= 0x80 ;
if ( ( V_13 = F_3 ( V_11 , V_12 ) ) ) {
V_13 -> V_185 = V_185 ;
V_185 -> V_13 = V_13 ;
memcpy ( & V_13 -> V_66 . V_137 , & V_185 -> V_137 , sizeof( V_250 ) ) ;
V_13 -> V_19 = V_12 ;
}
} else {
V_13 = V_32 ;
}
if ( ! V_13 ) {
F_24 ( V_70 L_96 , V_64 ) ;
return;
}
if ( V_64 == ( V_202 | V_59 ) ) {
F_73 ( V_13 ) ;
return;
}
for ( V_4 = 0 ; V_4 < F_101 ( V_251 ) ; V_4 ++ )
if ( ( V_64 == V_251 [ V_4 ] . V_241 ) &&
( ( 1 << V_13 -> V_68 ) & V_251 [ V_4 ] . V_68 ) )
break;
if ( V_4 == F_101 ( V_251 ) ) {
if ( V_11 -> V_18 . V_86 & V_242 ) {
F_10 ( V_11 , L_97 ,
V_13 -> V_68 , V_64 ) ;
}
} else {
if ( V_11 -> V_18 . V_86 & V_242 ) {
F_10 ( V_11 , L_98 ,
V_13 -> V_68 , V_64 ) ;
}
V_251 [ V_4 ] . F_102 ( V_13 , V_64 , V_32 ) ;
}
}
static void
F_109 ( struct V_1 * V_11 , int V_64 , void * V_32 )
{
int V_4 ;
struct V_10 * V_13 = V_32 ;
if ( ! V_13 ) {
F_24 ( V_70 L_99 , V_64 ) ;
return;
}
for ( V_4 = 0 ; V_4 < F_101 ( V_252 ) ; V_4 ++ )
if ( ( V_64 == V_252 [ V_4 ] . V_241 ) &&
( ( 1 << V_13 -> V_68 ) & V_252 [ V_4 ] . V_68 ) )
break;
if ( V_4 == F_101 ( V_252 ) ) {
if ( V_11 -> V_18 . V_86 & V_242 ) {
F_10 ( V_11 , L_100 ,
V_13 -> V_19 & 0x7f , V_13 -> V_68 , V_64 ) ;
}
} else {
if ( V_11 -> V_18 . V_86 & V_242 ) {
F_10 ( V_11 , L_101 ,
V_13 -> V_19 & 0x7f , V_13 -> V_68 , V_64 ) ;
}
V_252 [ V_4 ] . F_102 ( V_13 , V_64 , V_32 ) ;
}
}
void
F_110 ( struct V_1 * V_11 )
{
char V_61 [ 64 ] ;
int V_4 ;
V_11 -> V_233 . V_234 = F_107 ;
V_11 -> V_233 . V_253 = F_72 ;
V_11 -> V_254 . V_255 = F_103 ;
V_11 -> V_18 . V_256 = F_109 ;
V_11 -> V_18 . V_207 = 1 ;
V_11 -> V_5 . V_6 . V_7 = 0 ;
V_11 -> V_5 . V_6 . V_8 [ 0 ] = 1 ;
V_4 = 1 ;
while ( V_4 < 32 )
V_11 -> V_5 . V_6 . V_8 [ V_4 ++ ] = 0 ;
if ( ! ( V_11 -> V_18 . V_239 = F_111 ( sizeof( struct V_10 ) , V_257 ) ) ) {
F_24 ( V_70 L_102 ) ;
} else {
V_11 -> V_18 . V_239 -> V_68 = 0 ;
V_11 -> V_18 . V_239 -> V_19 = 0 ;
V_11 -> V_18 . V_239 -> V_20 = NULL ;
V_11 -> V_18 . V_239 -> V_86 = V_116 ;
V_11 -> V_18 . V_239 -> V_11 = V_11 ;
V_11 -> V_18 . V_239 -> V_207 = 1 ;
V_11 -> V_18 . V_239 -> V_5 . V_6 . V_14 = 0 ;
F_112 ( V_11 -> V_18 . V_239 , & V_11 -> V_18 . V_239 -> V_25 ) ;
}
strcpy ( V_61 , V_258 ) ;
F_24 ( V_259 L_103 , F_113 ( V_61 ) ) ;
}

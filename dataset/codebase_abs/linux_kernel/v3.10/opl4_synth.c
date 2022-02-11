void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
F_3 ( V_2 , V_7 + V_4 , V_8 ) ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
F_5 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
memset ( V_2 -> V_11 , 0 , sizeof( V_2 -> V_11 ) ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
V_2 -> V_11 [ V_4 ] . V_12 = V_4 ;
F_6 ( & V_2 -> V_11 [ V_4 ] . V_13 , & V_2 -> V_9 ) ;
}
F_7 ( V_2 -> V_14 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
int V_4 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ )
F_3 ( V_2 , V_7 + V_4 ,
V_2 -> V_11 [ V_4 ] . V_15 & ~ V_16 ) ;
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_17 , struct V_18 * V_19 ,
void (* F_10)( struct V_1 * V_2 , struct V_20 * V_21 ) )
{
int V_4 ;
unsigned long V_3 ;
struct V_20 * V_21 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
V_21 = & V_2 -> V_11 [ V_4 ] ;
if ( V_21 -> V_19 == V_19 && V_21 -> V_17 == V_17 ) {
F_10 ( V_2 , V_21 ) ;
}
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_18 * V_19 ,
void (* F_10)( struct V_1 * V_2 , struct V_20 * V_21 ) )
{
int V_4 ;
unsigned long V_3 ;
struct V_20 * V_21 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
V_21 = & V_2 -> V_11 [ V_4 ] ;
if ( V_21 -> V_19 == V_19 ) {
F_10 ( V_2 , V_21 ) ;
}
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
void (* F_10)( struct V_1 * V_2 , struct V_20 * V_21 ) )
{
int V_4 ;
unsigned long V_3 ;
struct V_20 * V_21 ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
V_21 = & V_2 -> V_11 [ V_4 ] ;
if ( V_21 -> V_19 )
F_10 ( V_2 , V_21 ) ;
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_22 ;
V_22 = V_21 -> V_23 -> V_24 ;
V_22 += V_25 [ V_2 -> V_14 -> V_26 & 0x7f ] ;
V_22 += V_25 [ V_21 -> V_19 -> V_27 & 0x7f ] ;
V_22 += V_25 [ V_21 -> V_19 -> V_28 & 0x7f ] ;
V_22 += V_25 [ V_21 -> V_29 ] ;
V_22 = 0x7f - ( 0x7f - V_22 ) * ( V_21 -> V_23 -> V_30 ) / 0xfe - V_31 ;
if ( V_22 < 0 )
V_22 = 0 ;
else if ( V_22 > 0x7e )
V_22 = 0x7e ;
F_3 ( V_2 , V_32 + V_21 -> V_12 ,
( V_22 << 1 ) | V_21 -> V_33 ) ;
V_21 -> V_33 = 0 ;
}
static void F_14 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_34 = V_21 -> V_23 -> V_35 ;
if ( ! V_21 -> V_19 -> V_36 )
V_34 += ( V_21 -> V_19 -> V_37 [ V_38 ] - 0x40 ) >> 3 ;
if ( V_34 < - 7 )
V_34 = - 7 ;
else if ( V_34 > 7 )
V_34 = 7 ;
V_21 -> V_15 = ( V_21 -> V_15 & ~ V_39 )
| ( V_34 & V_39 ) ;
F_3 ( V_2 , V_7 + V_21 -> V_12 , V_21 -> V_15 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
int V_40 ;
if ( V_21 -> V_19 -> V_36 )
return;
V_40 = ( 7 - V_21 -> V_23 -> V_41 )
* ( V_21 -> V_19 -> V_37 [ V_42 ] & 0x7f ) ;
V_40 = ( V_40 >> 7 ) + V_21 -> V_23 -> V_41 ;
V_21 -> V_43 &= ~ V_44 ;
V_21 -> V_43 |= V_40 & V_44 ;
F_3 ( V_2 , V_45 + V_21 -> V_12 ,
V_21 -> V_43 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_18 * V_19 = V_21 -> V_19 ;
int V_17 , V_46 , V_47 ;
V_17 = V_19 -> V_36 ? 60 : V_21 -> V_17 ;
V_46 = ( ( V_17 - 60 ) << 7 ) * V_21 -> V_23 -> V_48 / 100 + ( 60 << 7 ) ;
V_46 += V_21 -> V_23 -> V_49 ;
if ( ! V_19 -> V_36 )
V_46 += V_19 -> V_50 ;
V_46 += V_19 -> V_51 >> 7 ;
V_46 += V_19 -> V_52 * V_19 -> V_53 / 0x2000 ;
if ( V_46 < 0 )
V_46 = 0 ;
else if ( V_46 >= 0x6000 )
V_46 = 0x5fff ;
V_47 = V_46 / 0x600 - 8 ;
V_46 = V_54 [ V_46 % 0x600 ] ;
F_3 ( V_2 , V_55 + V_21 -> V_12 ,
( V_47 << 4 ) | ( ( V_46 >> 7 ) & V_56 ) ) ;
V_21 -> V_57 = ( V_21 -> V_57 & V_58 )
| ( ( V_46 << 1 ) & V_59 ) ;
F_3 ( V_2 , V_60 + V_21 -> V_12 , V_21 -> V_57 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
F_3 ( V_2 , V_61 + V_21 -> V_12 ,
V_21 -> V_23 -> V_62 ) ;
F_3 ( V_2 , V_63 + V_21 -> V_12 ,
V_21 -> V_23 -> V_64 ) ;
F_3 ( V_2 , V_65 + V_21 -> V_12 ,
V_21 -> V_23 -> V_66 ) ;
F_3 ( V_2 , V_67 + V_21 -> V_12 ,
V_21 -> V_23 -> V_68 ) ;
}
static struct V_20 * F_18 ( struct V_1 * V_2 )
{
if ( ! F_19 ( & V_2 -> V_9 ) )
return F_20 ( V_2 -> V_9 . V_69 , struct V_20 , V_13 ) ;
F_21 ( F_19 ( & V_2 -> V_10 ) ) ;
return F_20 ( V_2 -> V_10 . V_69 , struct V_20 , V_13 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
int V_70 = 200 ;
while ( ( F_23 ( V_2 -> V_71 ) & V_72 ) && -- V_70 > 0 )
F_24 ( 10 ) ;
}
void F_25 ( void * V_73 , int V_17 , int V_74 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_73 ;
const struct V_75 * V_76 ;
struct V_20 * V_21 [ 2 ] ;
const struct V_77 * V_23 [ 2 ] ;
int V_11 = 0 , V_4 ;
unsigned long V_3 ;
V_4 = V_19 -> V_36 ? 0x80 : ( V_19 -> V_78 & 0x7f ) ;
V_76 = & V_79 [ V_4 ] ;
for ( V_4 = 0 ; V_4 < V_76 -> V_80 ; V_4 ++ ) {
if ( V_17 >= V_76 -> V_76 [ V_4 ] . V_81 &&
V_17 <= V_76 -> V_76 [ V_4 ] . V_82 ) {
V_23 [ V_11 ] = & V_76 -> V_76 [ V_4 ] . V_23 ;
if ( ++ V_11 >= 2 )
break;
}
}
F_2 ( & V_2 -> V_5 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
V_21 [ V_4 ] = F_18 ( V_2 ) ;
F_26 ( & V_21 [ V_4 ] -> V_13 , & V_2 -> V_10 ) ;
V_21 [ V_4 ] -> V_19 = V_19 ;
V_21 [ V_4 ] -> V_17 = V_17 ;
V_21 [ V_4 ] -> V_29 = V_74 & 0x7f ;
V_21 [ V_4 ] -> V_23 = V_23 [ V_4 ] ;
}
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
V_21 [ V_4 ] -> V_57 =
( V_23 [ V_4 ] -> V_83 >> 8 ) & V_58 ;
F_3 ( V_2 , V_60 + V_21 [ V_4 ] -> V_12 ,
V_21 [ V_4 ] -> V_57 ) ;
F_3 ( V_2 , V_84 + V_21 [ V_4 ] -> V_12 ,
V_23 [ V_4 ] -> V_83 & 0xff ) ;
}
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
V_21 [ V_4 ] -> V_15 = V_85 ;
F_14 ( V_2 , V_21 [ V_4 ] ) ;
F_16 ( V_2 , V_21 [ V_4 ] ) ;
V_21 [ V_4 ] -> V_33 = V_86 ;
F_13 ( V_2 , V_21 [ V_4 ] ) ;
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
F_22 ( V_2 ) ;
F_2 ( & V_2 -> V_5 , V_3 ) ;
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
F_17 ( V_2 , V_21 [ V_4 ] ) ;
V_21 [ V_4 ] -> V_43 = V_21 [ V_4 ] -> V_23 -> V_43 ;
F_15 ( V_2 , V_21 [ V_4 ] ) ;
}
for ( V_4 = 0 ; V_4 < V_11 ; V_4 ++ ) {
V_21 [ V_4 ] -> V_15 =
( V_21 [ V_4 ] -> V_15 & 0x1f ) | V_16 ;
F_3 ( V_2 , V_7 + V_21 [ V_4 ] -> V_12 ,
V_21 [ V_4 ] -> V_15 ) ;
}
F_4 ( & V_2 -> V_5 , V_3 ) ;
}
static void F_27 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
F_26 ( & V_21 -> V_13 , & V_2 -> V_9 ) ;
V_21 -> V_15 &= ~ V_16 ;
F_3 ( V_2 , V_7 + V_21 -> V_12 , V_21 -> V_15 ) ;
}
void F_28 ( void * V_73 , int V_17 , int V_74 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_73 ;
F_9 ( V_2 , V_17 , V_19 , F_27 ) ;
}
static void F_29 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
F_26 ( & V_21 -> V_13 , & V_2 -> V_9 ) ;
V_21 -> V_15 = ( V_21 -> V_15 & ~ V_16 ) | V_8 ;
F_3 ( V_2 , V_7 + V_21 -> V_12 , V_21 -> V_15 ) ;
}
void F_30 ( void * V_73 , int V_17 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_73 ;
F_9 ( V_2 , V_17 , V_19 , F_29 ) ;
}
void F_31 ( void * V_73 , int type , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_73 ;
switch ( type ) {
case V_87 :
V_19 -> V_37 [ V_42 ] = V_19 -> V_37 [ V_87 ] ;
F_11 ( V_2 , V_19 , F_15 ) ;
break;
case V_88 :
F_11 ( V_2 , V_19 , F_13 ) ;
break;
case V_38 :
F_11 ( V_2 , V_19 , F_14 ) ;
break;
case V_89 :
F_11 ( V_2 , V_19 , F_13 ) ;
break;
case V_90 :
break;
case V_42 :
F_11 ( V_2 , V_19 , F_15 ) ;
break;
case V_91 :
break;
case V_92 :
break;
case V_93 :
F_11 ( V_2 , V_19 , F_16 ) ;
break;
}
}
void F_32 ( void * V_73 , unsigned char * V_94 , int V_95 ,
int V_96 , struct V_97 * V_14 )
{
struct V_1 * V_2 = V_73 ;
if ( V_96 == V_98 )
F_12 ( V_2 , F_13 ) ;
}

static T_1 F_1 ( T_1 V_1 )
{
int V_2 ;
switch ( V_1 ) {
case 0x18003 : return 1 ;
case 0x10003 : return 2 ;
default:
for ( V_2 = V_3 + 1 ; V_1 != 0x4000 && V_2 > 0 ; V_2 -- )
V_1 = ( ( V_1 ^ V_1 >> 14 ) & 1 ) | ( V_1 << 1 & 0x7fff ) ;
return V_2 ;
}
}
static T_1 F_2 ( T_1 V_4 )
{
T_1 V_2 , V_1 = 0x4000 ;
switch ( V_4 ) {
case 0 : return 0 ;
case 1 : return 0x18003 ;
case 2 : return 0x10003 ;
default:
for ( V_2 = V_4 ; V_2 <= V_3 ; V_2 ++ )
V_1 = ( ( V_1 ^ V_1 >> 1 ) & 1 ) << 14 | ( V_1 >> 1 & 0xffff ) ;
return V_1 ;
}
}
static T_1 F_3 ( T_1 V_4 )
{
T_1 V_5 ;
if ( V_4 > 16384 ) return 1 ;
if ( V_4 > 8192 ) return 2 ;
if ( V_4 > 2048 ) return 4 ;
if ( V_4 >= 501 ) return 8 ;
if ( V_4 >= 60 ) {
V_5 = 1024 / ( V_4 + 9 ) ;
return ( ( 1024 == ( V_5 * ( V_4 + 9 ) ) ) == 0 ) ? V_5 * 4 : ( V_5 + 1 ) * 4 ;
}
return ( V_4 & 0x3c ) + 4 ;
}
static T_1 F_4 ( T_1 V_4 )
{
if ( V_4 < 60 )
return ( V_4 >> 1 ) + 1 ;
return 31 ;
}
static unsigned long F_5 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
struct V_9 * V_10 = F_6 ( V_7 ) ;
T_1 V_11 , V_12 , V_4 , V_13 ;
V_11 = F_7 ( V_10 -> V_14 + V_15 ) ;
V_12 = F_7 ( V_10 -> V_14 + V_16 ) ;
V_13 = F_7 ( V_10 -> V_14 + V_17 ) ;
if ( V_11 & V_18 )
return V_8 ;
if ( V_13 != V_19 ) {
F_8 ( L_1 , V_20 ) ;
return 0 ;
}
V_4 = F_1 ( V_12 & V_21 ) ;
if ( V_4 )
return 2 * V_4 * V_8 ;
F_8 ( L_2 , V_20 ) ;
return 0 ;
}
static long F_9 ( struct V_6 * V_7 , unsigned long V_22 ,
unsigned long * V_23 )
{
unsigned long V_24 ;
if ( * V_23 < V_22 ) {
F_8 ( L_3 , V_20 ) ;
return - V_25 ;
}
V_24 = F_10 ( * V_23 , V_22 * 2 ) ;
if ( V_24 <= 0 && V_24 > V_3 ) {
F_8 ( L_4 , V_20 , V_22 ) ;
return - V_25 ;
}
return 2 * * V_23 * V_24 ;
}
static int F_11 ( struct V_6 * V_7 , unsigned long V_22 ,
unsigned long V_8 )
{
struct V_9 * V_10 = F_6 ( V_7 ) ;
T_1 V_11 , V_26 , V_24 ;
int V_27 = 3 ;
if ( V_8 < V_22 ) {
F_8 ( L_3 , V_20 ) ;
return - V_25 ;
}
V_24 = F_10 ( V_8 , V_22 * 2 ) ;
if ( V_24 <= 0 && V_24 > V_3 ) {
F_8 ( L_4 , V_20 , V_22 ) ;
return - V_25 ;
}
V_24 = F_2 ( V_24 ) ;
V_24 |= F_4 ( V_24 ) << V_28 ;
V_24 |= F_3 ( V_24 ) << V_29 ;
V_11 = F_7 ( V_10 -> V_14 + V_15 ) ;
V_11 |= V_30 ;
V_11 &= ~ ( V_18 | V_31 |
V_32 | V_33 ) ;
F_12 ( V_11 , V_10 -> V_14 + V_15 ) ;
F_12 ( V_24 , V_10 -> V_14 + V_16 ) ;
F_12 ( V_19 , V_10 -> V_14 + V_17 ) ;
V_11 &= ~ V_30 ;
F_12 ( V_11 , V_10 -> V_14 + V_15 ) ;
do {
F_13 ( 10 ) ;
V_26 = F_7 ( V_10 -> V_14 + V_34 ) ;
if ( V_26 & V_35 ) {
V_11 |= V_33 ;
F_12 ( V_11 , V_10 -> V_14 + V_15 ) ;
return 0 ;
}
} while ( V_27 -- );
F_8 ( L_5 , V_20 ) ;
return - V_25 ;
}
static unsigned long F_14 ( struct V_6 * V_7 ,
unsigned long V_8 )
{
struct V_9 * V_10 = F_6 ( V_7 ) ;
T_2 V_4 , V_36 , V_37 ;
bool V_38 , V_39 ;
T_1 V_26 , V_11 ;
V_26 = F_7 ( V_10 -> V_14 + V_40 ) ;
V_11 = F_7 ( V_10 -> V_14 + V_41 ) ;
V_38 = ( V_11 & V_42 ) ? true : false ;
V_39 = ( V_11 & V_43 ) ? true : false ;
V_4 = ( ( V_11 >> 16 ) & 0xff ) + 1 ;
V_36 = ( ( V_11 >> 12 ) & 0x3 ) + 1 ;
if ( V_38 || V_39 )
return V_4 * ( V_8 / V_36 ) ;
V_37 = ( V_11 >> 8 ) & 0x3 ;
V_37 = 1 << V_37 ;
return ( V_4 / ( 2 * V_37 ) ) * ( V_8 / V_36 ) ;
}
static void F_15 ( const char * * V_44 , T_1 * V_45 , int V_46 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_46 ; V_2 ++ )
V_44 [ V_2 ] = V_47 [ V_45 [ V_2 ] ] ;
}
static struct V_48 * F_16 ( struct V_49 * V_48 ,
void T_3 * V_50 , int V_51 )
{
void T_3 * V_14 = V_50 + F_17 ( V_51 ) ;
const char * V_52 = V_47 [ V_48 -> V_53 ] ;
const char * V_54 [ V_55 ] ;
V_48 -> div . V_14 = V_14 ;
V_48 -> V_56 . V_14 = V_14 ;
V_48 -> V_57 . V_14 = V_14 ;
F_15 ( V_54 , V_48 -> V_56 . V_58 , V_48 -> V_59 ) ;
return F_18 ( NULL , V_52 , V_54 , V_48 -> V_59 ,
& V_48 -> V_56 . V_7 , & V_60 ,
& V_48 -> div . V_7 , & V_61 ,
& V_48 -> V_57 . V_7 , & V_62 , 0 ) ;
}
static struct V_48 * F_19 ( struct V_63 * V_48 ,
void T_3 * V_64 , int V_51 )
{
void T_3 * V_14 = V_64 + F_20 ( V_51 ) ;
const char * V_52 = V_65 [ V_48 -> V_53 ] ;
const char * V_54 [ V_55 ] ;
if ( V_48 -> V_59 == 0 )
return F_21 ( - V_66 ) ;
V_48 -> V_56 . V_14 = V_14 ;
V_48 -> V_57 . V_14 = V_14 ;
F_15 ( V_54 , V_48 -> V_56 . V_58 , V_48 -> V_59 ) ;
if ( V_51 == V_67 )
return F_18 ( NULL , V_52 , V_54 , V_48 -> V_59 ,
& V_48 -> V_56 . V_7 , & V_60 ,
NULL , NULL , NULL , NULL , 0 ) ;
return F_18 ( NULL , V_52 , V_54 , V_48 -> V_59 ,
& V_48 -> V_56 . V_7 , & V_60 ,
NULL , NULL ,
& V_48 -> V_57 . V_7 , & V_62 , 0 ) ;
}
static struct V_48 * F_22 ( struct V_68 * V_48 ,
void T_3 * V_50 )
{
const char * V_52 = V_47 [ V_48 -> V_53 ] ;
const char * V_54 [ V_55 ] ;
V_48 -> V_10 . V_14 = V_50 ;
V_48 -> V_56 . V_14 = V_50 + V_48 -> V_69 + V_70 ;
V_48 -> V_57 . V_14 = V_50 + V_48 -> V_69 + V_70 ;
F_15 ( V_54 , V_48 -> V_56 . V_58 , V_48 -> V_59 ) ;
return F_18 ( NULL , V_52 , V_54 , V_48 -> V_59 ,
& V_48 -> V_56 . V_7 , & V_60 ,
& V_48 -> V_10 . V_7 , V_48 -> V_71 ,
& V_48 -> V_57 . V_7 , & V_62 , 0 ) ;
}
static void T_4 F_23 ( struct V_72 * V_73 ,
void T_3 * V_50 )
{
const char * V_54 [ V_55 ] ;
struct V_48 * V_48 ;
int V_2 ;
V_48 = F_24 ( NULL , V_47 [ V_74 ] ,
NULL , V_75 , 12000000 ) ;
if ( F_25 ( V_48 ) )
F_8 ( L_6 , V_20 ) ;
V_54 [ 0 ] = F_26 ( V_73 , 0 ) ;
V_48 = F_27 ( NULL , V_47 [ V_76 ] , V_54 [ 0 ] ,
0 , V_50 + V_77 ,
0 , V_78 , NULL ) ;
if ( F_25 ( V_48 ) )
F_8 ( L_7 , V_20 ) ;
for ( V_2 = 0 ; V_2 < F_28 ( V_79 ) ; V_2 ++ ) {
V_48 = F_22 ( & V_79 [ V_2 ] ,
V_50 ) ;
if ( F_25 ( V_48 ) )
F_8 ( L_8 , V_20 , V_2 ) ;
}
for ( V_2 = 0 ; V_2 < F_28 ( V_80 ) ; V_2 ++ ) {
V_48 = F_16 ( & V_80 [ V_2 ] ,
V_50 , V_2 ) ;
if ( F_25 ( V_48 ) )
F_8 ( L_9 , V_20 , V_2 ) ;
}
}
static void T_4 F_29 ( void T_3 * V_64 )
{
int V_2 ;
for ( V_2 = V_67 ; V_2 < V_81 ; V_2 ++ ) {
V_82 [ V_2 ] = F_19 ( & V_83 [ V_2 ] ,
V_64 , V_2 ) ;
if ( F_25 ( V_82 [ V_2 ] ) && F_30 ( V_82 [ V_2 ] ) != - V_66 )
F_8 ( L_10 , V_20 , V_2 ) ;
}
}
static void T_4 F_31 ( struct V_72 * V_73 )
{
void T_3 * V_64 ;
V_64 = F_32 ( V_73 , 0 ) ;
if ( ! V_64 ) {
F_8 ( L_11 , V_20 ) ;
return;
}
F_23 ( V_73 , V_64 ) ;
F_29 ( V_64 ) ;
F_33 ( V_73 , V_84 , & V_85 ) ;
}

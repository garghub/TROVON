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
static int F_15 ( struct V_6 * V_7 )
{
return V_44 . V_45 ( V_7 ) ;
}
static void F_16 ( struct V_6 * V_7 )
{
V_44 . V_46 ( V_7 ) ;
}
static int F_17 ( struct V_6 * V_7 )
{
const struct V_6 * V_47 ;
V_47 = F_18 ( V_7 ) ;
if ( ! V_47 )
return 0 ;
if ( ! F_19 ( V_47 ) )
return 0 ;
return V_44 . V_48 ( V_7 ) ;
}
static void F_20 ( const char * * V_47 , T_1 * V_49 , int V_50 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_50 ; V_2 ++ )
V_47 [ V_2 ] = V_51 [ V_49 [ V_2 ] ] ;
}
static struct V_52 * F_21 ( struct V_53 * V_52 ,
void T_3 * V_54 , int V_55 )
{
void T_3 * V_14 = V_54 + F_22 ( V_55 ) ;
const char * V_56 = V_51 [ V_52 -> V_57 ] ;
const char * V_58 [ V_59 ] ;
V_52 -> div . V_14 = V_14 ;
V_52 -> V_60 . V_14 = V_14 ;
V_52 -> V_61 . V_14 = V_14 ;
F_20 ( V_58 , V_52 -> V_60 . V_62 , V_52 -> V_63 ) ;
return F_23 ( NULL , V_56 , V_58 , V_52 -> V_63 ,
& V_52 -> V_60 . V_7 , & V_64 ,
& V_52 -> div . V_7 , & V_65 ,
& V_52 -> V_61 . V_7 , & V_66 , 0 ) ;
}
static struct V_52 * F_24 ( struct V_67 * V_52 ,
void T_3 * V_68 , int V_55 )
{
void T_3 * V_14 = V_68 + F_25 ( V_55 ) ;
const char * V_56 = V_69 [ V_52 -> V_57 ] ;
const char * V_58 [ V_59 ] ;
if ( V_52 -> V_63 == 0 )
return F_26 ( - V_70 ) ;
V_52 -> V_60 . V_14 = V_14 ;
V_52 -> V_61 . V_14 = V_14 ;
F_20 ( V_58 , V_52 -> V_60 . V_62 , V_52 -> V_63 ) ;
if ( V_55 == V_71 )
return F_23 ( NULL , V_56 , V_58 , V_52 -> V_63 ,
& V_52 -> V_60 . V_7 , & V_64 ,
NULL , NULL , NULL , NULL , 0 ) ;
return F_23 ( NULL , V_56 , V_58 , V_52 -> V_63 ,
& V_52 -> V_60 . V_7 , & V_64 ,
NULL , NULL ,
& V_52 -> V_61 . V_7 , & V_66 , 0 ) ;
}
static struct V_52 * F_27 ( struct V_72 * V_52 ,
void T_3 * V_54 )
{
const char * V_56 = V_51 [ V_52 -> V_57 ] ;
const char * V_58 [ V_59 ] ;
V_52 -> V_10 . V_14 = V_54 ;
V_52 -> V_60 . V_14 = V_54 + V_52 -> V_73 + V_74 ;
V_52 -> V_61 . V_14 = V_54 + V_52 -> V_73 + V_74 ;
F_20 ( V_58 , V_52 -> V_60 . V_62 , V_52 -> V_63 ) ;
return F_23 ( NULL , V_56 , V_58 , V_52 -> V_63 ,
& V_52 -> V_60 . V_7 , & V_64 ,
& V_52 -> V_10 . V_7 , V_52 -> V_75 ,
& V_52 -> V_61 . V_7 , & V_66 , 0 ) ;
}
static void T_4 F_28 ( struct V_76 * V_77 ,
void T_3 * V_54 )
{
const char * V_58 [ V_59 ] ;
struct V_52 * V_52 ;
int V_2 ;
V_52 = F_29 ( NULL , V_51 [ V_78 ] ,
NULL , 0 , 12000000 ) ;
if ( F_30 ( V_52 ) )
F_8 ( L_6 , V_20 ) ;
V_58 [ 0 ] = F_31 ( V_77 , 0 ) ;
V_52 = F_32 ( NULL , V_51 [ V_79 ] , V_58 [ 0 ] ,
0 , V_54 + V_80 ,
0 , V_81 , NULL ) ;
if ( F_30 ( V_52 ) )
F_8 ( L_7 , V_20 ) ;
for ( V_2 = 0 ; V_2 < F_33 ( V_82 ) ; V_2 ++ ) {
V_52 = F_27 ( & V_82 [ V_2 ] ,
V_54 ) ;
if ( F_30 ( V_52 ) )
F_8 ( L_8 , V_20 , V_2 ) ;
}
for ( V_2 = 0 ; V_2 < F_33 ( V_83 ) ; V_2 ++ ) {
V_52 = F_21 ( & V_83 [ V_2 ] ,
V_54 , V_2 ) ;
if ( F_30 ( V_52 ) )
F_8 ( L_9 , V_20 , V_2 ) ;
}
}
static void T_4 F_34 ( void T_3 * V_68 )
{
int V_2 ;
for ( V_2 = V_71 ; V_2 < V_84 ; V_2 ++ ) {
V_85 [ V_2 ] = F_24 ( & V_86 [ V_2 ] ,
V_68 , V_2 ) ;
if ( F_30 ( V_85 [ V_2 ] ) && F_35 ( V_85 [ V_2 ] ) != - V_70 )
F_8 ( L_10 , V_20 , V_2 ) ;
}
}
static void T_4 F_36 ( struct V_76 * V_77 )
{
void T_3 * V_68 ;
V_68 = F_37 ( V_77 , 0 ) ;
if ( ! V_68 ) {
F_8 ( L_11 , V_20 ) ;
return;
}
F_28 ( V_77 , V_68 ) ;
F_34 ( V_68 ) ;
F_38 ( V_77 , V_87 , & V_88 ) ;
}

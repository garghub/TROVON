static int F_1 ( struct V_1 * V_1 , unsigned char V_2 ,
unsigned char * V_3 )
{
if ( F_2 ( V_1 , V_2 ) ||
F_3 ( & V_1 -> V_4 , V_3 , V_5 ) ) {
F_4 ( L_1 , V_2 ) ;
return - 1 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_1 ,
unsigned char * V_3 , int V_6 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
struct V_7 * V_8 = V_1 -> V_9 ;
int V_10 ;
int V_11 = V_12 ;
do {
V_10 = F_3 ( V_4 , V_3 , V_6 ) ;
if ( V_10 == 0 )
break;
V_11 -- ;
F_6 ( L_2 ,
V_6 , V_11 ) ;
F_7 ( V_13 ) ;
} while ( V_11 > 0 );
if ( V_10 )
F_4 ( L_3 , V_6 ) ;
return V_10 ;
}
static int F_8 ( struct V_1 * V_1 , unsigned char V_14 ,
unsigned char * V_15 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
unsigned char V_3 [ 3 ] ;
int V_10 = 0 ;
if ( V_14 < 0x10 || V_14 > 0x26 )
return - 1 ;
if ( V_14 > 0x11 && V_14 < 0x20 )
return - 1 ;
switch ( V_8 -> V_16 ) {
case 1 :
if ( F_2 ( V_1 , V_17 ) ||
F_2 ( V_1 , V_14 ) ||
F_3 ( & V_1 -> V_4 , V_3 , V_5 ) ) {
V_10 = - 1 ;
}
break;
case 2 :
if ( F_5 ( V_1 , NULL , V_18 ) ||
F_5 ( V_1 , NULL , V_17 ) ||
F_5 ( V_1 , NULL , V_18 ) ||
F_5 ( V_1 , NULL , V_14 ) ||
F_5 ( V_1 , V_3 , V_5 ) ) {
V_10 = - 1 ;
}
break;
}
if ( V_10 )
F_4 ( L_4 , V_14 ) ;
else
* V_15 = V_3 [ 0 ] ;
return V_10 ;
}
static int F_9 ( struct V_1 * V_1 , unsigned char V_14 ,
unsigned char V_15 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
int V_10 = 0 ;
if ( V_14 < 0x10 || V_14 > 0x26 )
return - 1 ;
if ( V_14 > 0x11 && V_14 < 0x20 )
return - 1 ;
switch ( V_8 -> V_16 ) {
case 1 :
if ( F_2 ( V_1 , V_19 ) ||
F_2 ( V_1 , V_14 ) ||
F_2 ( V_1 , V_15 ) ||
F_3 ( & V_1 -> V_4 , NULL , V_20 ) ) {
V_10 = - 1 ;
}
break;
case 2 :
if ( F_5 ( V_1 , NULL , V_18 ) ||
F_5 ( V_1 , NULL , V_19 ) ||
F_5 ( V_1 , NULL , V_18 ) ||
F_5 ( V_1 , NULL , V_14 ) ||
F_5 ( V_1 , NULL , V_18 ) ||
F_5 ( V_1 , NULL , V_15 ) ||
F_5 ( V_1 , NULL , V_20 ) ) {
V_10 = - 1 ;
}
break;
}
if ( V_10 )
F_4 ( L_5 ,
V_14 , V_15 ) ;
return V_10 ;
}
static void F_10 ( unsigned char * V_21 , int V_22 )
{
int V_23 ;
F_11 (KERN_DEBUG pr_fmt(L_6)) ;
for ( V_23 = 0 ; V_23 < V_22 ; V_23 ++ )
F_11 ( L_7 , ( V_23 ) ? L_8 : L_9 , V_21 [ V_23 ] ) ;
F_11 ( L_10 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_24 * V_25 = V_1 -> V_25 ;
struct V_7 * V_8 = V_1 -> V_9 ;
unsigned char * V_21 = V_1 -> V_21 ;
int V_26 ;
if ( V_8 -> V_27 < 0x020000 ) {
V_26 = ( ( V_21 [ 1 ] & 0x80 ) >> 7 ) +
( ( V_21 [ 1 ] & 0x30 ) >> 4 ) ;
} else {
V_26 = ( V_21 [ 0 ] & 0xc0 ) >> 6 ;
}
if ( V_8 -> V_28 ) {
if ( V_26 != 1 ) {
V_8 -> V_29 = 0 ;
} else if ( V_8 -> V_29 < 2 ) {
V_8 -> V_29 ++ ;
F_6 ( L_11 ) ;
return;
}
}
F_13 ( V_25 , V_30 , V_26 != 0 ) ;
if ( V_26 ) {
F_14 ( V_25 , V_31 ,
( ( V_21 [ 1 ] & 0x0c ) << 6 ) | V_21 [ 2 ] ) ;
F_14 ( V_25 , V_32 ,
V_33 - ( ( ( V_21 [ 1 ] & 0x03 ) << 8 ) | V_21 [ 3 ] ) ) ;
}
F_13 ( V_25 , V_34 , V_26 == 1 ) ;
F_13 ( V_25 , V_35 , V_26 == 2 ) ;
F_13 ( V_25 , V_36 , V_26 == 3 ) ;
F_13 ( V_25 , V_37 , V_21 [ 0 ] & 0x01 ) ;
F_13 ( V_25 , V_38 , V_21 [ 0 ] & 0x02 ) ;
if ( V_8 -> V_27 < 0x020000 &&
( V_8 -> V_39 & V_40 ) ) {
F_13 ( V_25 , V_41 , V_21 [ 0 ] & 0x40 ) ;
F_13 ( V_25 , V_42 , V_21 [ 0 ] & 0x80 ) ;
}
F_15 ( V_25 ) ;
}
static void F_16 ( struct V_24 * V_25 , int V_43 , bool V_44 ,
unsigned int V_45 , unsigned int V_46 )
{
F_17 ( V_25 , V_43 ) ;
F_18 ( V_25 , V_47 , V_44 ) ;
if ( V_44 ) {
F_14 ( V_25 , V_48 , V_45 ) ;
F_14 ( V_25 , V_49 , V_46 ) ;
}
}
static void F_19 ( struct V_24 * V_25 ,
unsigned int V_50 ,
unsigned int V_51 , unsigned int y1 ,
unsigned int V_52 , unsigned int V_53 )
{
F_16 ( V_25 , 0 , V_50 != 0 , V_51 , y1 ) ;
F_16 ( V_25 , 1 , V_50 == 2 , V_52 , V_53 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
struct V_24 * V_25 = V_1 -> V_25 ;
unsigned char * V_21 = V_1 -> V_21 ;
unsigned int V_26 , V_51 = 0 , y1 = 0 , V_52 = 0 , V_53 = 0 , V_54 = 0 , V_55 = 0 ;
V_26 = ( V_21 [ 0 ] & 0xc0 ) >> 6 ;
F_13 ( V_25 , V_30 , V_26 != 0 ) ;
switch ( V_26 ) {
case 3 :
if ( V_21 [ 3 ] & 0x80 )
V_26 = 4 ;
case 1 :
V_51 = ( ( V_21 [ 1 ] & 0x07 ) << 8 ) | V_21 [ 2 ] ;
y1 = V_56 - ( ( ( V_21 [ 4 ] & 0x03 ) << 8 ) | V_21 [ 5 ] ) ;
F_14 ( V_25 , V_31 , V_51 ) ;
F_14 ( V_25 , V_32 , y1 ) ;
V_55 = ( V_21 [ 1 ] & 0xf0 ) | ( ( V_21 [ 4 ] & 0xf0 ) >> 4 ) ;
V_54 = ( ( V_21 [ 0 ] & 0x30 ) >> 2 ) | ( ( V_21 [ 3 ] & 0x30 ) >> 4 ) ;
break;
case 2 :
V_51 = ( ( V_21 [ 0 ] & 0x10 ) << 4 ) | V_21 [ 1 ] ;
y1 = V_57 - ( ( ( V_21 [ 0 ] & 0x20 ) << 3 ) | V_21 [ 2 ] ) ;
V_52 = ( ( V_21 [ 3 ] & 0x10 ) << 4 ) | V_21 [ 4 ] ;
V_53 = V_57 - ( ( ( V_21 [ 3 ] & 0x20 ) << 3 ) | V_21 [ 5 ] ) ;
F_14 ( V_25 , V_31 , V_51 << 2 ) ;
F_14 ( V_25 , V_32 , y1 << 2 ) ;
V_55 = 127 ;
V_54 = 7 ;
break;
}
F_19 ( V_25 , V_26 , V_51 , y1 , V_52 , V_53 ) ;
F_13 ( V_25 , V_34 , V_26 == 1 ) ;
F_13 ( V_25 , V_35 , V_26 == 2 ) ;
F_13 ( V_25 , V_36 , V_26 == 3 ) ;
F_13 ( V_25 , V_58 , V_26 == 4 ) ;
F_13 ( V_25 , V_37 , V_21 [ 0 ] & 0x01 ) ;
F_13 ( V_25 , V_38 , V_21 [ 0 ] & 0x02 ) ;
if ( V_8 -> V_59 ) {
F_14 ( V_25 , V_60 , V_55 ) ;
F_14 ( V_25 , V_61 , V_54 ) ;
}
F_15 ( V_25 ) ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
unsigned char * V_21 = V_1 -> V_21 ;
unsigned char V_62 , V_63 , V_64 ;
if ( V_8 -> V_27 < 0x020000 ) {
V_62 = ( V_21 [ 0 ] & 0x20 ) >> 5 ;
V_63 = ( V_21 [ 0 ] & 0x10 ) >> 4 ;
} else {
V_62 = ( V_21 [ 0 ] & 0x10 ) >> 4 ;
V_63 = ( V_21 [ 0 ] & 0x20 ) >> 5 ;
}
V_64 = ( V_21 [ 0 ] & 0x04 ) >> 2 ;
return V_8 -> V_65 [ V_21 [ 1 ] ] == V_62 &&
V_8 -> V_65 [ V_21 [ 2 ] ] == V_63 &&
V_8 -> V_65 [ V_21 [ 3 ] ] == V_64 ;
}
static T_1 F_22 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
if ( V_1 -> V_66 < V_1 -> V_67 )
return V_68 ;
if ( V_8 -> V_69 > 1 )
F_10 ( V_1 -> V_21 , V_1 -> V_67 ) ;
switch ( V_8 -> V_16 ) {
case 1 :
if ( V_8 -> V_70 && ! F_21 ( V_1 ) )
return V_71 ;
F_12 ( V_1 ) ;
break;
case 2 :
F_20 ( V_1 ) ;
break;
}
return V_72 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
unsigned char V_15 ;
int V_11 = V_73 ;
int V_10 = 0 ;
switch ( V_8 -> V_16 ) {
case 1 :
V_8 -> V_74 = 0x16 ;
V_8 -> V_75 = 0x8f ;
if ( F_9 ( V_1 , 0x10 , V_8 -> V_74 ) ||
F_9 ( V_1 , 0x11 , V_8 -> V_75 ) ) {
V_10 = - 1 ;
}
break;
case 2 :
V_8 -> V_74 = 0x54 ;
V_8 -> V_75 = 0x88 ;
V_8 -> V_76 = 0x60 ;
if ( F_9 ( V_1 , 0x10 , V_8 -> V_74 ) ||
F_9 ( V_1 , 0x11 , V_8 -> V_75 ) ||
F_9 ( V_1 , 0x21 , V_8 -> V_76 ) ) {
V_10 = - 1 ;
break;
}
}
if ( V_10 == 0 ) {
do {
V_10 = F_8 ( V_1 , 0x10 , & V_15 ) ;
if ( V_10 == 0 )
break;
V_11 -- ;
F_6 ( L_12 , V_11 ) ;
F_7 ( V_77 ) ;
} while ( V_11 > 0 );
if ( V_10 ) {
F_4 ( L_13 ) ;
} else if ( V_8 -> V_16 == 1 &&
! ( V_15 & V_78 ) ) {
F_4 ( L_14 ) ;
V_10 = - 1 ;
}
}
if ( V_10 )
F_4 ( L_15 ) ;
return V_10 ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_24 * V_25 = V_1 -> V_25 ;
struct V_7 * V_8 = V_1 -> V_9 ;
F_25 ( V_79 , V_25 -> V_80 ) ;
F_25 ( V_81 , V_25 -> V_80 ) ;
F_26 ( V_82 , V_25 -> V_80 ) ;
F_25 ( V_37 , V_25 -> V_83 ) ;
F_25 ( V_38 , V_25 -> V_83 ) ;
F_25 ( V_30 , V_25 -> V_83 ) ;
F_25 ( V_34 , V_25 -> V_83 ) ;
F_25 ( V_35 , V_25 -> V_83 ) ;
F_25 ( V_36 , V_25 -> V_83 ) ;
switch ( V_8 -> V_16 ) {
case 1 :
if ( V_8 -> V_27 < 0x020000 &&
( V_8 -> V_39 & V_40 ) ) {
F_25 ( V_41 , V_25 -> V_83 ) ;
F_25 ( V_42 , V_25 -> V_83 ) ;
}
F_27 ( V_25 , V_31 , V_84 , V_85 , 0 , 0 ) ;
F_27 ( V_25 , V_32 , V_86 , V_33 , 0 , 0 ) ;
break;
case 2 :
F_25 ( V_58 , V_25 -> V_83 ) ;
F_27 ( V_25 , V_31 , V_87 , V_88 , 0 , 0 ) ;
F_27 ( V_25 , V_32 , V_89 , V_56 , 0 , 0 ) ;
if ( V_8 -> V_59 ) {
F_27 ( V_25 , V_60 , V_90 ,
V_91 , 0 , 0 ) ;
F_27 ( V_25 , V_61 , V_92 ,
V_93 , 0 , 0 ) ;
}
F_25 ( V_94 , V_25 -> V_95 ) ;
F_28 ( V_25 , 2 ) ;
F_27 ( V_25 , V_48 , V_87 , V_88 , 0 , 0 ) ;
F_27 ( V_25 , V_49 , V_89 , V_56 , 0 , 0 ) ;
break;
}
}
static T_2 F_29 ( struct V_1 * V_1 , void * V_96 ,
char * V_97 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
struct V_98 * V_99 = V_96 ;
unsigned char * V_14 = ( unsigned char * ) V_8 + V_99 -> V_100 ;
int V_10 = 0 ;
if ( V_99 -> V_14 )
V_10 = F_8 ( V_1 , V_99 -> V_14 , V_14 ) ;
return sprintf ( V_97 , L_16 , ( V_99 -> V_14 && V_10 ) ? - 1 : * V_14 ) ;
}
static T_2 F_30 ( struct V_1 * V_1 ,
void * V_96 , const char * V_97 , T_3 V_101 )
{
struct V_7 * V_8 = V_1 -> V_9 ;
struct V_98 * V_99 = V_96 ;
unsigned char * V_14 = ( unsigned char * ) V_8 + V_99 -> V_100 ;
unsigned long V_102 ;
int V_103 ;
V_103 = F_31 ( V_97 , 16 , & V_102 ) ;
if ( V_103 )
return V_103 ;
if ( V_102 > 0xff )
return - V_104 ;
if ( V_8 -> V_16 == 1 ) {
if ( V_99 -> V_14 == 0x10 )
V_102 |= V_78 ;
else if ( V_99 -> V_14 == 0x11 )
V_102 |= V_105 ;
}
if ( ! V_99 -> V_14 || F_9 ( V_1 , V_99 -> V_14 , V_102 ) == 0 )
* V_14 = V_102 ;
return V_101 ;
}
static bool F_32 ( const unsigned char * V_3 )
{
static const unsigned char V_106 [] = { 200 , 100 , 80 , 60 , 40 , 20 , 10 } ;
int V_23 ;
if ( V_3 [ 0 ] == 0 )
return false ;
if ( V_3 [ 1 ] == 0 )
return true ;
for ( V_23 = 0 ; V_23 < F_33 ( V_106 ) ; V_23 ++ )
if ( V_3 [ 2 ] == V_106 [ V_23 ] )
return false ;
return true ;
}
int F_34 ( struct V_1 * V_1 , bool V_107 )
{
struct V_4 * V_4 = & V_1 -> V_4 ;
unsigned char V_3 [ 3 ] ;
F_3 ( & V_1 -> V_4 , NULL , V_108 ) ;
if ( F_3 ( V_4 , NULL , V_109 ) ||
F_3 ( V_4 , NULL , V_20 ) ||
F_3 ( V_4 , NULL , V_20 ) ||
F_3 ( V_4 , NULL , V_20 ) ||
F_3 ( V_4 , V_3 , V_5 ) ) {
F_35 ( L_17 ) ;
return - 1 ;
}
if ( V_3 [ 0 ] != 0x3c || V_3 [ 1 ] != 0x03 || V_3 [ 2 ] != 0xc8 ) {
F_35 ( L_18 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
return - 1 ;
}
if ( F_1 ( V_1 , V_110 , V_3 ) ) {
F_35 ( L_19 ) ;
return - 1 ;
}
F_35 ( L_20 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( ! F_32 ( V_3 ) ) {
if ( ! V_111 ) {
F_35 ( L_21 ) ;
return - 1 ;
}
F_35 ( L_22 ) ;
}
if ( V_107 ) {
V_1 -> V_112 = L_23 ;
V_1 -> V_113 = L_24 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_1 )
{
F_37 ( & V_1 -> V_4 . V_114 -> V_25 . V_115 ,
& V_116 ) ;
F_38 ( V_1 -> V_9 ) ;
V_1 -> V_9 = NULL ;
}
static int F_39 ( struct V_1 * V_1 )
{
if ( F_34 ( V_1 , 0 ) )
return - 1 ;
if ( F_23 ( V_1 ) ) {
F_4 ( L_25 ) ;
return - 1 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_1 )
{
struct V_7 * V_8 ;
int V_23 , error ;
unsigned char V_3 [ 3 ] ;
V_1 -> V_9 = V_8 = F_41 ( sizeof( struct V_7 ) , V_117 ) ;
if ( ! V_8 )
return - V_118 ;
V_8 -> V_65 [ 0 ] = 1 ;
for ( V_23 = 1 ; V_23 < 256 ; V_23 ++ )
V_8 -> V_65 [ V_23 ] = V_8 -> V_65 [ V_23 & ( V_23 - 1 ) ] ^ 1 ;
if ( F_1 ( V_1 , V_110 , V_3 ) ) {
F_4 ( L_19 ) ;
goto V_119;
}
V_8 -> V_27 = ( V_3 [ 0 ] << 16 ) | ( V_3 [ 1 ] << 8 ) | V_3 [ 2 ] ;
if ( V_8 -> V_27 >= 0x020030 ) {
V_8 -> V_16 = 2 ;
V_8 -> V_69 = 1 ;
V_8 -> V_70 = 0 ;
if ( V_8 -> V_27 >= 0x020800 )
V_8 -> V_59 = true ;
} else {
V_8 -> V_16 = 1 ;
V_8 -> V_70 = 1 ;
}
F_42 ( L_26 ,
V_8 -> V_16 , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( F_1 ( V_1 , V_120 , V_3 ) ) {
F_4 ( L_27 ) ;
goto V_119;
}
F_42 ( L_28 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] ) ;
V_8 -> V_39 = V_3 [ 0 ] ;
if ( V_8 -> V_27 == 0x020022 || V_8 -> V_27 == 0x020600 ) {
F_42 ( L_29 ) ;
V_8 -> V_28 = true ;
}
if ( F_23 ( V_1 ) ) {
F_4 ( L_30 ) ;
goto V_119;
}
F_24 ( V_1 ) ;
error = F_43 ( & V_1 -> V_4 . V_114 -> V_25 . V_115 ,
& V_116 ) ;
if ( error ) {
F_4 ( L_31 , error ) ;
goto V_119;
}
V_1 -> V_121 = F_22 ;
V_1 -> V_122 = F_36 ;
V_1 -> V_123 = F_39 ;
V_1 -> V_67 = V_8 -> V_16 == 2 ? 6 : 4 ;
return 0 ;
V_119:
F_38 ( V_8 ) ;
return - 1 ;
}

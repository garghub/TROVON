static bool F_1 ( const struct V_1 * V_2 ,
unsigned char V_3 )
{
return ( V_3 & V_2 -> V_4 ) == V_2 -> V_5 ;
}
static void F_2 ( struct V_6 * V_6 ,
struct V_7 * V_8 , struct V_7 * V_9 ,
int V_10 , int V_11 , int V_12 )
{
struct V_7 * V_13 ;
V_13 = F_3 ( V_14 , V_9 -> V_15 ) ? V_9 : V_8 ;
F_4 ( V_13 , V_14 , V_10 ) ;
V_13 = F_3 ( V_16 , V_9 -> V_15 ) ? V_9 : V_8 ;
F_4 ( V_13 , V_16 , V_11 ) ;
V_13 = F_3 ( V_17 , V_9 -> V_15 ) ? V_9 : V_8 ;
F_4 ( V_13 , V_17 , V_12 ) ;
F_5 ( V_9 ) ;
}
static void F_6 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
const struct V_1 * V_2 = V_19 -> V_21 ;
unsigned char * V_22 = V_6 -> V_22 ;
struct V_7 * V_13 = V_6 -> V_13 ;
struct V_7 * V_9 = V_19 -> V_9 ;
int V_23 , V_24 , V_25 , V_26 , V_27 , V_10 , V_11 , V_12 ;
int V_28 = 0 , V_29 = 0 ;
if ( V_2 -> V_30 & V_31 ) {
V_10 = V_22 [ 2 ] & 0x10 ;
V_11 = V_22 [ 2 ] & 0x08 ;
V_12 = 0 ;
V_23 = V_22 [ 1 ] | ( ( V_22 [ 0 ] & 0x07 ) << 7 ) ;
V_24 = V_22 [ 4 ] | ( ( V_22 [ 3 ] & 0x07 ) << 7 ) ;
V_25 = V_22 [ 5 ] ;
} else {
V_10 = V_22 [ 3 ] & 1 ;
V_11 = V_22 [ 3 ] & 2 ;
V_12 = V_22 [ 3 ] & 4 ;
V_23 = V_22 [ 1 ] | ( ( V_22 [ 2 ] & 0x78 ) << ( 7 - 3 ) ) ;
V_24 = V_22 [ 4 ] | ( ( V_22 [ 3 ] & 0x70 ) << ( 7 - 4 ) ) ;
V_25 = V_22 [ 5 ] ;
}
if ( V_2 -> V_30 & V_32 ) {
V_28 = V_22 [ 0 ] & 0x10 ;
V_29 = V_22 [ 2 ] & 4 ;
}
if ( V_2 -> V_30 & V_33 ) {
V_28 = V_22 [ 3 ] & 4 ;
V_29 = V_22 [ 2 ] & 4 ;
if ( ( V_12 = V_29 && V_28 ) )
V_29 = V_28 = 0 ;
}
V_26 = V_22 [ 2 ] & 1 ;
V_27 = V_22 [ 2 ] & 2 ;
if ( ( V_2 -> V_30 & V_34 ) && V_25 == 127 ) {
F_7 ( V_9 , V_35 , ( V_23 > 383 ? ( V_23 - 768 ) : V_23 ) ) ;
F_7 ( V_9 , V_36 , - ( V_24 > 255 ? ( V_24 - 512 ) : V_24 ) ) ;
F_2 ( V_6 , V_9 , V_13 , V_10 , V_11 , V_12 ) ;
F_5 ( V_9 ) ;
return;
}
F_2 ( V_6 , V_13 , V_9 , V_10 , V_11 , V_12 ) ;
if ( V_26 && ! V_27 )
V_25 = 40 ;
if ( V_26 && V_27 && ! V_19 -> V_37 ) {
F_8 ( V_13 , V_38 , V_23 ) ;
F_8 ( V_13 , V_39 , V_24 ) ;
F_8 ( V_13 , V_40 , 0 ) ;
F_4 ( V_13 , V_41 , 0 ) ;
F_5 ( V_13 ) ;
}
V_19 -> V_37 = V_27 ;
if ( V_25 > 30 )
F_4 ( V_13 , V_42 , 1 ) ;
if ( V_25 < 25 )
F_4 ( V_13 , V_42 , 0 ) ;
if ( V_25 > 0 ) {
F_8 ( V_13 , V_38 , V_23 ) ;
F_8 ( V_13 , V_39 , V_24 ) ;
}
F_8 ( V_13 , V_40 , V_25 ) ;
F_4 ( V_13 , V_41 , V_25 > 0 ) ;
if ( V_2 -> V_30 & V_43 )
F_7 ( V_13 , V_44 , ( ( V_22 [ 2 ] << 1 ) & 0x08 ) - ( ( V_22 [ 0 ] >> 4 ) & 0x07 ) ) ;
if ( V_2 -> V_30 & ( V_32 | V_33 ) ) {
F_4 ( V_13 , V_45 , V_29 ) ;
F_4 ( V_13 , V_46 , V_28 ) ;
}
if ( V_2 -> V_30 & V_47 ) {
F_4 ( V_13 , V_48 , V_22 [ 2 ] & 4 ) ;
F_4 ( V_13 , V_49 , V_22 [ 0 ] & 0x10 ) ;
F_4 ( V_13 , V_50 , V_22 [ 3 ] & 4 ) ;
F_4 ( V_13 , V_51 , V_22 [ 0 ] & 0x20 ) ;
}
F_5 ( V_13 ) ;
}
static void F_9 ( struct V_6 * V_6 ,
unsigned char V_22 [] ,
bool V_52 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
struct V_7 * V_9 = V_19 -> V_9 ;
if ( V_52 )
F_2 ( V_6 , V_9 , V_6 -> V_13 ,
V_22 [ 0 ] & 1 , V_22 [ 0 ] & 2 , V_22 [ 0 ] & 4 ) ;
F_7 ( V_9 , V_35 ,
V_22 [ 1 ] ? V_22 [ 1 ] - ( ( V_22 [ 0 ] << 4 ) & 0x100 ) : 0 ) ;
F_7 ( V_9 , V_36 ,
V_22 [ 2 ] ? ( ( V_22 [ 0 ] << 3 ) & 0x100 ) - V_22 [ 2 ] : 0 ) ;
F_5 ( V_9 ) ;
}
static T_1 F_10 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
if ( V_6 -> V_53 < 6 )
return V_54 ;
if ( V_6 -> V_53 == 6 ) {
F_11 ( & V_19 -> V_55 , V_56 + F_12 ( 20 ) ) ;
return V_54 ;
}
F_13 ( & V_19 -> V_55 ) ;
if ( V_6 -> V_22 [ 6 ] & 0x80 ) {
if ( ( ( V_6 -> V_22 [ 3 ] |
V_6 -> V_22 [ 4 ] |
V_6 -> V_22 [ 5 ] ) & 0x80 ) ||
( ! F_1 ( V_19 -> V_21 , V_6 -> V_22 [ 6 ] ) ) ) {
F_14 ( L_1
L_2 ,
V_6 -> V_22 [ 3 ] , V_6 -> V_22 [ 4 ] ,
V_6 -> V_22 [ 5 ] , V_6 -> V_22 [ 6 ] ) ;
return V_57 ;
}
F_6 ( V_6 ) ;
V_6 -> V_22 [ 0 ] = V_6 -> V_22 [ 6 ] ;
V_6 -> V_53 = 1 ;
} else {
F_9 ( V_6 , & V_6 -> V_22 [ 3 ] ,
false ) ;
V_6 -> V_22 [ 3 ] = V_6 -> V_22 [ 6 ] & 0xf7 ;
V_6 -> V_53 = 4 ;
}
return V_54 ;
}
static void F_15 ( unsigned long V_3 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
F_16 ( V_6 -> V_58 . V_59 ) ;
if ( V_6 -> V_53 == 6 ) {
if ( ( V_6 -> V_22 [ 3 ] |
V_6 -> V_22 [ 4 ] |
V_6 -> V_22 [ 5 ] ) & 0x80 ) {
F_14 ( L_3
L_2 ,
V_6 -> V_22 [ 3 ] , V_6 -> V_22 [ 4 ] ,
V_6 -> V_22 [ 5 ] ) ;
} else {
F_6 ( V_6 ) ;
}
V_6 -> V_53 = 0 ;
}
F_17 ( V_6 -> V_58 . V_59 ) ;
}
static T_1 F_18 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
const struct V_1 * V_2 = V_19 -> V_21 ;
if ( ( V_6 -> V_22 [ 0 ] & 0xc8 ) == 0x08 ) {
if ( V_6 -> V_53 == 3 ) {
F_9 ( V_6 , V_6 -> V_22 ,
true ) ;
return V_60 ;
}
return V_54 ;
}
if ( ( V_2 -> V_30 & V_61 ) &&
V_6 -> V_53 >= 4 && ( V_6 -> V_22 [ 3 ] & 0x0f ) == 0x0f ) {
return F_10 ( V_6 ) ;
}
if ( ! F_1 ( V_2 , V_6 -> V_22 [ 0 ] ) ) {
F_14 ( L_4 ,
V_6 -> V_22 [ 0 ] , V_2 -> V_4 , V_2 -> V_5 ) ;
return V_57 ;
}
if ( V_6 -> V_53 >= 2 && V_6 -> V_53 <= 6 &&
( V_6 -> V_22 [ V_6 -> V_53 - 1 ] & 0x80 ) ) {
F_14 ( L_5 ,
V_6 -> V_53 - 1 , V_6 -> V_22 [ V_6 -> V_53 - 1 ] ) ;
return V_57 ;
}
if ( V_6 -> V_53 == 6 ) {
F_6 ( V_6 ) ;
return V_60 ;
}
return V_54 ;
}
static const struct V_1 * F_19 ( struct V_6 * V_6 , int * V_62 )
{
struct V_58 * V_58 = & V_6 -> V_58 ;
static const unsigned char V_63 [] = { 0 , 10 , 20 , 40 , 60 , 80 , 100 , 200 } ;
unsigned char V_64 [ 4 ] ;
int V_21 ;
V_64 [ 0 ] = 0 ;
if ( F_20 ( V_58 , V_64 , V_65 ) ||
F_20 ( V_58 , NULL , V_66 ) ||
F_20 ( V_58 , NULL , V_66 ) ||
F_20 ( V_58 , NULL , V_66 ) )
return NULL ;
V_64 [ 0 ] = V_64 [ 1 ] = V_64 [ 2 ] = 0xff ;
if ( F_20 ( V_58 , V_64 , V_67 ) )
return NULL ;
F_14 ( L_6 , V_64 [ 0 ] , V_64 [ 1 ] , V_64 [ 2 ] ) ;
if ( V_64 [ 0 ] != 0 || V_64 [ 1 ] != 0 || ( V_64 [ 2 ] != 10 && V_64 [ 2 ] != 100 ) )
return NULL ;
V_64 [ 0 ] = 0 ;
if ( F_20 ( V_58 , V_64 , V_65 ) ||
F_20 ( V_58 , NULL , V_68 ) ||
F_20 ( V_58 , NULL , V_68 ) ||
F_20 ( V_58 , NULL , V_68 ) )
return NULL ;
V_64 [ 0 ] = V_64 [ 1 ] = V_64 [ 2 ] = 0xff ;
if ( F_20 ( V_58 , V_64 , V_67 ) )
return NULL ;
F_14 ( L_7 , V_64 [ 0 ] , V_64 [ 1 ] , V_64 [ 2 ] ) ;
if ( V_62 ) {
for ( V_21 = 0 ; V_21 < F_21 ( V_63 ) && V_64 [ 2 ] != V_63 [ V_21 ] ; V_21 ++ )
;
* V_62 = ( V_64 [ 0 ] << 8 ) | ( V_64 [ 1 ] << 4 ) | V_21 ;
}
for ( V_21 = 0 ; V_21 < F_21 ( V_69 ) ; V_21 ++ )
if ( ! memcmp ( V_64 , V_69 [ V_21 ] . V_70 ,
sizeof( V_69 [ V_21 ] . V_70 ) ) )
return V_69 + V_21 ;
return NULL ;
}
static int F_22 ( struct V_6 * V_6 , bool V_71 )
{
struct V_58 * V_58 = & V_6 -> V_58 ;
int V_72 = V_71 ? V_68 : V_66 ;
if ( F_20 ( V_58 , NULL , V_72 ) ||
F_20 ( V_58 , NULL , V_72 ) ||
F_20 ( V_58 , NULL , V_72 ) ||
F_20 ( V_58 , NULL , V_73 ) )
return - 1 ;
F_23 ( V_58 , 3 , 100 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_6 )
{
struct V_58 * V_58 = & V_6 -> V_58 ;
if ( F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , NULL , V_74 ) )
return - 1 ;
return F_20 ( & V_6 -> V_58 , NULL , V_75 ) ;
}
static int F_25 ( struct V_6 * V_6 , char * V_64 )
{
struct V_58 * V_58 = & V_6 -> V_58 ;
if ( F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , V_64 , V_67 ) )
return - 1 ;
F_14 ( L_8 , V_64 [ 0 ] , V_64 [ 1 ] , V_64 [ 2 ] ) ;
return 0 ;
}
static int F_26 ( struct V_6 * V_6 , int V_71 )
{
struct V_58 * V_58 = & V_6 -> V_58 ;
int V_72 = V_71 ? V_76 : V_65 ;
unsigned char V_77 = V_71 ? 0x0A : 0x00 ;
unsigned char V_64 [ 4 ] ;
if ( F_20 ( V_58 , V_64 , V_67 ) ||
F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , NULL , V_73 ) ||
F_20 ( V_58 , & V_77 , V_72 ) )
return - 1 ;
if ( F_25 ( V_6 , V_64 ) )
return - 1 ;
return 0 ;
}
static int F_27 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
unsigned char V_78 [ 6 ] ;
bool V_79 ;
if ( V_19 -> V_21 -> V_30 & V_80 )
F_22 ( V_6 , true ) ;
V_79 = F_20 ( & V_6 -> V_58 , V_78 ,
V_81 | ( V_6 -> V_82 << 8 ) ) < 0 ;
if ( V_19 -> V_21 -> V_30 & V_80 )
F_22 ( V_6 , false ) ;
if ( V_79 || ( V_78 [ 0 ] & V_19 -> V_21 -> V_4 ) != V_19 -> V_21 -> V_5 )
return - 1 ;
if ( ( V_6 -> V_83 & 0xc8 ) == 0x08 ) {
if ( F_20 ( & V_6 -> V_58 , V_78 , V_81 | ( 3 << 8 ) ) )
return - 1 ;
}
memcpy ( V_6 -> V_22 , V_78 , sizeof( V_78 ) ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
const struct V_1 * V_2 = V_19 -> V_21 ;
if ( ( V_2 -> V_30 & V_80 ) &&
F_22 ( V_6 , true ) ) {
return - 1 ;
}
if ( F_26 ( V_6 , true ) ) {
F_29 ( V_84 L_9 ) ;
return - 1 ;
}
if ( F_24 ( V_6 ) ) {
F_29 ( V_85 L_10 ) ;
return - 1 ;
}
if ( ( V_2 -> V_30 & V_80 ) &&
F_22 ( V_6 , false ) ) {
return - 1 ;
}
if ( F_20 ( & V_6 -> V_58 , NULL , V_86 ) ) {
F_29 ( V_85 L_11 ) ;
return - 1 ;
}
return 0 ;
}
static int F_30 ( struct V_6 * V_6 )
{
const struct V_1 * V_2 ;
F_31 ( V_6 ) ;
V_2 = F_19 ( V_6 , NULL ) ;
if ( ! V_2 )
return - 1 ;
return F_28 ( V_6 ) ;
}
static void F_32 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = V_6 -> V_20 ;
F_31 ( V_6 ) ;
F_33 ( & V_19 -> V_55 ) ;
F_34 ( V_19 -> V_9 ) ;
F_35 ( V_19 ) ;
}
int F_36 ( struct V_6 * V_6 )
{
struct V_18 * V_19 ;
const struct V_1 * V_2 ;
struct V_7 * V_8 = V_6 -> V_13 , * V_9 ;
int V_62 ;
V_19 = F_37 ( sizeof( struct V_18 ) , V_87 ) ;
V_9 = F_38 () ;
if ( ! V_19 || ! V_9 )
goto V_88;
V_19 -> V_9 = V_9 ;
F_39 ( & V_19 -> V_55 , F_15 , ( unsigned long ) V_6 ) ;
V_6 -> V_20 = V_19 ;
V_2 = F_19 ( V_6 , & V_62 ) ;
if ( ! V_2 )
goto V_88;
V_19 -> V_21 = V_2 ;
if ( F_28 ( V_6 ) )
goto V_88;
F_40 ( V_89 , V_8 -> V_90 ) ;
F_40 ( V_35 , V_8 -> V_91 ) ;
F_40 ( V_36 , V_8 -> V_91 ) ;
V_8 -> V_90 [ F_41 ( V_92 ) ] |= F_42 ( V_92 ) ;
V_8 -> V_93 [ F_41 ( V_42 ) ] |= F_42 ( V_42 ) ;
V_8 -> V_93 [ F_41 ( V_41 ) ] |= F_42 ( V_41 ) ;
V_8 -> V_93 [ F_41 ( V_14 ) ] |=
F_42 ( V_14 ) | F_42 ( V_16 ) ;
V_8 -> V_90 [ F_41 ( V_94 ) ] |= F_42 ( V_94 ) ;
F_43 ( V_8 , V_38 , 0 , 1023 , 0 , 0 ) ;
F_43 ( V_8 , V_39 , 0 , 767 , 0 , 0 ) ;
F_43 ( V_8 , V_40 , 0 , 127 , 0 , 0 ) ;
if ( V_2 -> V_30 & V_43 ) {
V_8 -> V_90 [ F_41 ( V_89 ) ] |= F_42 ( V_89 ) ;
V_8 -> V_91 [ F_41 ( V_44 ) ] |= F_42 ( V_44 ) ;
}
if ( V_2 -> V_30 & ( V_32 | V_33 ) ) {
V_8 -> V_93 [ F_41 ( V_45 ) ] |= F_42 ( V_45 ) ;
V_8 -> V_93 [ F_41 ( V_46 ) ] |= F_42 ( V_46 ) ;
}
if ( V_2 -> V_30 & V_47 ) {
V_8 -> V_93 [ F_41 ( V_48 ) ] |= F_42 ( V_48 ) ;
V_8 -> V_93 [ F_41 ( V_49 ) ] |= F_42 ( V_49 ) ;
V_8 -> V_93 [ F_41 ( V_50 ) ] |= F_42 ( V_50 ) ;
V_8 -> V_93 [ F_41 ( V_51 ) ] |= F_42 ( V_51 ) ;
} else {
V_8 -> V_93 [ F_41 ( V_17 ) ] |= F_42 ( V_17 ) ;
}
snprintf ( V_19 -> V_95 , sizeof( V_19 -> V_95 ) , L_12 , V_6 -> V_58 . V_59 -> V_95 ) ;
V_9 -> V_95 = V_19 -> V_95 ;
V_9 -> V_96 = ( V_2 -> V_30 & V_34 ) ? L_13 : L_14 ;
V_9 -> V_97 . V_98 = V_99 ;
V_9 -> V_97 . V_100 = 0x0002 ;
V_9 -> V_97 . V_101 = V_102 ;
V_9 -> V_97 . V_62 = 0x0000 ;
V_9 -> V_13 . V_103 = & V_6 -> V_58 . V_59 -> V_13 ;
V_9 -> V_90 [ 0 ] = F_42 ( V_92 ) | F_42 ( V_89 ) ;
V_9 -> V_91 [ F_41 ( V_35 ) ] = F_42 ( V_35 ) | F_42 ( V_36 ) ;
V_9 -> V_93 [ F_41 ( V_14 ) ] =
F_42 ( V_14 ) | F_42 ( V_17 ) | F_42 ( V_16 ) ;
if ( F_44 ( V_19 -> V_9 ) )
goto V_88;
V_6 -> V_104 = F_18 ;
V_6 -> V_105 = F_27 ;
V_6 -> V_106 = F_32 ;
V_6 -> V_107 = F_30 ;
V_6 -> V_82 = 6 ;
V_6 -> V_108 = 0 ;
return 0 ;
V_88:
F_31 ( V_6 ) ;
F_45 ( V_9 ) ;
F_35 ( V_19 ) ;
V_6 -> V_20 = NULL ;
return - 1 ;
}
int F_46 ( struct V_6 * V_6 , bool V_109 )
{
int V_62 ;
const struct V_1 * V_2 ;
V_2 = F_19 ( V_6 , & V_62 ) ;
if ( ! V_2 )
return - 1 ;
if ( V_109 ) {
V_6 -> V_100 = L_15 ;
V_6 -> V_96 = V_2 -> V_30 & V_34 ?
L_16 : L_17 ;
V_6 -> V_2 = V_62 ;
}
return 0 ;
}

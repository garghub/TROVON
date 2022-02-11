static const char * F_1 ( const struct V_1 * V_2 ,
int V_3 , int V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 ; ++ V_5 , ++ V_2 ) {
if ( V_4 == V_2 -> V_6 )
break;
}
return ( V_5 < V_3 ) ? V_2 -> V_7 : NULL ;
}
static void F_2 ( unsigned char * V_8 , int V_9 )
{
int V_10 , V_11 , V_12 ;
int V_13 = 0 ;
const char * V_7 ;
V_12 = V_8 [ 0 ] ;
switch( V_12 ) {
case V_14 :
V_11 = F_3 ( V_8 ) ;
if ( V_11 < 10 ) {
F_4 ( L_1
L_2 , V_11 , V_9 ) ;
break;
}
V_10 = ( V_8 [ 8 ] << 8 ) + V_8 [ 9 ] ;
V_7 = F_1 ( V_15 , V_16 ,
V_10 ) ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
if ( ( V_9 > 0 ) && ( V_11 != V_9 ) )
F_4 ( L_5 , V_11 , V_9 ) ;
break;
case V_17 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_18 , V_19 , V_10 ) ;
V_13 = 1 ;
break;
case V_20 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_21 , V_22 , V_10 ) ;
V_13 = 1 ;
break;
case V_23 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_24 , V_25 , V_10 ) ;
V_13 = 1 ;
break;
case V_26 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_27 , V_28 , V_10 ) ;
V_13 = 1 ;
break;
case V_29 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_30 , V_31 , V_10 ) ;
V_13 = 1 ;
break;
case V_32 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_33 , V_34 , V_10 ) ;
V_13 = 1 ;
break;
case V_35 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_36 , V_37 , V_10 ) ;
V_13 = 1 ;
break;
case V_38 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_39 , V_40 , V_10 ) ;
V_13 = 1 ;
break;
case V_41 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_42 , V_43 , V_10 ) ;
V_13 = 1 ;
break;
case V_44 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_45 , V_46 , V_10 ) ;
V_13 = 1 ;
break;
case V_47 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_48 , V_49 , V_10 ) ;
V_13 = 1 ;
break;
default:
if ( V_12 < 0xc0 ) {
V_7 = V_50 [ V_12 ] ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_6 , V_12 ) ;
} else
F_4 ( L_7 , V_12 ) ;
break;
}
if ( V_13 ) {
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
}
}
static void F_2 ( unsigned char * V_8 , int V_9 )
{
int V_10 , V_11 , V_12 ;
V_12 = V_8 [ 0 ] ;
switch( V_12 ) {
case V_14 :
V_11 = F_3 ( V_8 ) ;
if ( V_11 < 10 ) {
F_4 ( L_8
L_9 , V_12 , V_11 , V_9 ) ;
break;
}
V_10 = ( V_8 [ 8 ] << 8 ) + V_8 [ 9 ] ;
F_4 ( L_4 , V_12 , V_10 ) ;
if ( V_11 != V_9 )
F_4 ( L_5 , V_11 , V_9 ) ;
break;
case V_17 :
case V_20 :
case V_23 :
case V_26 :
case V_29 :
case V_32 :
case V_35 :
case V_38 :
case V_41 :
case V_44 :
case V_47 :
V_10 = V_8 [ 1 ] & 0x1f ;
F_4 ( L_4 , V_12 , V_10 ) ;
break;
default:
if ( V_12 < 0xc0 )
F_4 ( L_10 , V_12 ) ;
else
F_4 ( L_7 , V_12 ) ;
break;
}
}
void F_5 ( unsigned char * V_51 )
{
int V_5 , V_11 ;
F_2 ( V_51 , 0 ) ;
V_11 = F_6 ( V_51 ) ;
for ( V_5 = 0 ; V_5 < V_11 ; ++ V_5 )
F_4 ( L_11 , V_51 [ V_5 ] ) ;
F_4 ( L_12 ) ;
}
void F_7 ( struct V_52 * V_53 )
{
int V_5 ;
if ( V_53 -> V_54 == NULL )
return;
F_8 ( V_55 , V_53 , L_13 ) ;
F_2 ( V_53 -> V_54 , V_53 -> V_56 ) ;
F_4 ( L_14 ) ;
for ( V_5 = 0 ; V_5 < V_53 -> V_56 ; ++ V_5 )
F_4 ( L_11 , V_53 -> V_54 [ V_5 ] ) ;
F_4 ( L_12 ) ;
}
void
F_9 ( unsigned char V_57 ) {
#ifdef F_10
const char * V_58 ;
switch ( V_57 ) {
case 0 : V_58 = L_15 ; break;
case 0x2 : V_58 = L_16 ; break;
case 0x4 : V_58 = L_17 ; break;
case 0x8 : V_58 = L_18 ; break;
case 0x10 : V_58 = L_19 ; break;
case 0x14 : V_58 = L_20 ; break;
case 0x18 : V_58 = L_21 ; break;
case 0x22 : V_58 = L_22 ; break;
case 0x28 : V_58 = L_23 ; break;
case 0x30 : V_58 = L_24 ; break;
case 0x40 : V_58 = L_25 ; break;
default: V_58 = L_26 ;
}
F_4 ( V_55 L_3 , V_58 ) ;
#else
F_4 ( V_55 L_27 , V_57 ) ;
#endif
}
const char *
F_11 ( unsigned char V_59 ) {
#ifdef F_10
if ( V_59 <= 0xE )
return V_60 [ V_59 ] ;
#endif
return NULL ;
}
const char *
F_12 ( unsigned char V_61 , unsigned char V_62 ) {
#ifdef F_10
int V_63 ;
unsigned short V_64 = ( ( V_61 << 8 ) | V_62 ) ;
for ( V_63 = 0 ; V_65 [ V_63 ] . V_66 ; V_63 ++ )
if ( V_65 [ V_63 ] . V_67 == V_64 )
return V_65 [ V_63 ] . V_66 ;
for ( V_63 = 0 ; V_68 [ V_63 ] . V_69 ; V_63 ++ ) {
if ( V_68 [ V_63 ] . V_70 == V_61 &&
V_62 >= V_68 [ V_63 ] . V_71 &&
V_62 <= V_68 [ V_63 ] . V_72 )
return V_68 [ V_63 ] . V_69 ;
}
#endif
return NULL ;
}
void
F_13 ( unsigned char V_61 , unsigned char V_62 )
{
const char * V_73 = F_12 ( V_61 , V_62 ) ;
if ( V_73 ) {
if ( strstr ( V_73 , L_28 ) ) {
F_4 ( L_29 ) ;
F_4 ( V_73 , V_62 ) ;
} else
F_4 ( L_30 , V_73 ) ;
} else {
if ( V_61 >= 0x80 )
F_4 ( L_31 , V_61 ,
V_62 ) ;
if ( V_62 >= 0x80 )
F_4 ( L_32 , V_61 ,
V_62 ) ;
else
F_4 ( L_33 , V_61 , V_62 ) ;
}
F_4 ( L_12 ) ;
}
void
F_14 ( struct V_74 * V_75 )
{
const char * V_76 ;
V_76 = F_11 ( V_75 -> V_77 ) ;
if ( V_76 )
F_4 ( L_34 , V_76 ) ;
else
F_4 ( L_35 , V_75 -> V_77 ) ;
F_4 ( L_3 , F_15 ( V_75 ) ? L_36 :
L_37 ) ;
if ( V_75 -> V_78 >= 0x72 )
F_4 ( L_38 ) ;
F_4 ( L_12 ) ;
}
void
F_16 ( const char * V_7 , struct V_74 * V_75 )
{
F_4 ( V_55 L_39 , V_7 ) ;
F_14 ( V_75 ) ;
F_4 ( V_55 L_39 , V_7 ) ;
F_13 ( V_75 -> V_61 , V_75 -> V_62 ) ;
}
void
F_17 ( struct V_52 * V_79 , const char * V_80 ,
struct V_74 * V_75 )
{
F_8 ( V_55 , V_79 , L_39 , V_80 ) ;
F_14 ( V_75 ) ;
F_8 ( V_55 , V_79 , L_39 , V_80 ) ;
F_13 ( V_75 -> V_61 , V_75 -> V_62 ) ;
}
static void
F_18 ( const unsigned char * V_81 , int V_82 ,
struct V_74 * V_75 )
{
int V_5 , V_83 , V_84 ;
V_84 = F_19 ( V_81 , V_82 , V_75 ) ;
if ( 0 == V_84 ) {
V_83 = ( V_82 < 32 ) ? V_82 : 32 ;
F_4 ( L_40 ) ;
for ( V_5 = 0 ; V_5 < V_83 ; ++ V_5 ) {
if ( 0 == ( V_5 % 16 ) ) {
F_4 ( L_12 ) ;
F_4 ( V_55 L_41 ) ;
}
F_4 ( L_42 , V_81 [ V_5 ] ) ;
}
F_4 ( L_12 ) ;
return;
}
}
static void
F_20 ( const unsigned char * V_81 , int V_82 ,
struct V_74 * V_75 )
{
int V_5 , V_83 , V_84 ;
if ( V_75 -> V_78 < 0x72 )
{
char V_85 [ 80 ] ;
int V_86 , V_87 ;
unsigned int V_88 ;
V_87 = V_81 [ 0 ] & 0x80 ;
V_88 = ( ( V_81 [ 3 ] << 24 ) | ( V_81 [ 4 ] << 16 ) |
( V_81 [ 5 ] << 8 ) | V_81 [ 6 ] ) ;
V_84 = 0 ;
memset ( V_85 , 0 , sizeof( V_85 ) ) ;
V_86 = sizeof( V_85 ) - 1 ;
if ( V_87 )
V_84 += snprintf ( V_85 + V_84 , V_86 - V_84 ,
L_43 , V_88 ) ;
if ( V_81 [ 2 ] & 0x80 ) {
if ( V_84 > 0 )
V_84 += snprintf ( V_85 + V_84 , V_86 - V_84 , L_44 ) ;
V_84 += snprintf ( V_85 + V_84 , V_86 - V_84 , L_45 ) ;
}
if ( V_81 [ 2 ] & 0x40 ) {
if ( V_84 > 0 )
V_84 += snprintf ( V_85 + V_84 , V_86 - V_84 , L_44 ) ;
V_84 += snprintf ( V_85 + V_84 , V_86 - V_84 , L_46 ) ;
}
if ( V_81 [ 2 ] & 0x20 ) {
if ( V_84 > 0 )
V_84 += snprintf ( V_85 + V_84 , V_86 - V_84 , L_44 ) ;
V_84 += snprintf ( V_85 + V_84 , V_86 - V_84 , L_47 ) ;
}
if ( V_84 > 0 )
F_4 ( L_48 , V_85 ) ;
} else if ( V_75 -> V_89 > 0 ) {
V_83 = 8 + V_75 -> V_89 ;
V_83 = ( V_82 < V_83 ) ? V_82 : V_83 ;
F_4 ( L_49
L_50 ) ;
for ( V_5 = 0 ; V_5 < V_83 ; ++ V_5 ) {
if ( 0 == ( V_5 % 16 ) ) {
F_4 ( L_12 ) ;
F_4 ( V_55 L_41 ) ;
}
F_4 ( L_42 , V_81 [ V_5 ] ) ;
}
F_4 ( L_12 ) ;
}
}
void F_21 ( const char * V_7 , const unsigned char * V_81 ,
int V_82 )
{
struct V_74 V_75 ;
F_4 ( V_55 L_39 , V_7 ) ;
F_18 ( V_81 , V_82 , & V_75 ) ;
F_14 ( & V_75 ) ;
F_20 ( V_81 , V_82 , & V_75 ) ;
F_4 ( V_55 L_39 , V_7 ) ;
F_13 ( V_75 . V_61 , V_75 . V_62 ) ;
}
void F_22 ( char * V_7 , struct V_52 * V_53 )
{
struct V_74 V_75 ;
F_8 ( V_55 , V_53 , L_51 ) ;
F_18 ( V_53 -> V_81 , V_90 ,
& V_75 ) ;
F_14 ( & V_75 ) ;
F_20 ( V_53 -> V_81 , V_90 ,
& V_75 ) ;
F_8 ( V_55 , V_53 , L_51 ) ;
F_13 ( V_75 . V_61 , V_75 . V_62 ) ;
}
void F_23 ( int V_91 )
{
int V_92 = F_24 ( V_91 ) ;
int V_93 = F_25 ( V_91 ) ;
F_4 ( L_52 ,
( V_92 < V_94 ? V_95 [ V_92 ] : L_53 ) ,
( V_93 < V_96 ? V_97 [ V_93 ] : L_53 ) ) ;
}
void F_23 ( int V_91 )
{
F_4 ( L_54 ,
F_24 ( V_91 ) , F_25 ( V_91 ) ) ;
}
void F_26 ( struct V_52 * V_53 )
{
F_8 ( V_55 , V_53 , L_51 ) ;
F_23 ( V_53 -> V_91 ) ;
}

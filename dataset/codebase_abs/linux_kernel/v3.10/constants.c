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
const char * V_7 ;
V_12 = V_8 [ 0 ] ;
switch( V_12 ) {
case V_13 :
V_11 = F_3 ( V_8 ) ;
if ( V_11 < 10 ) {
F_4 ( L_1
L_2 , V_11 , V_9 ) ;
break;
}
V_10 = ( V_8 [ 8 ] << 8 ) + V_8 [ 9 ] ;
V_7 = F_1 ( V_14 , V_15 , V_10 ) ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
if ( ( V_9 > 0 ) && ( V_11 != V_9 ) )
F_4 ( L_5 , V_11 , V_9 ) ;
break;
case V_16 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_17 , V_18 , V_10 ) ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
break;
case V_19 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_20 , V_21 , V_10 ) ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
break;
case V_22 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_23 , V_24 , V_10 ) ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
break;
case V_25 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_26 , V_27 , V_10 ) ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
break;
case V_28 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_29 , V_30 , V_10 ) ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
break;
case V_31 :
V_10 = V_8 [ 1 ] & 0x1f ;
V_7 = F_1 ( V_32 , V_33 , V_10 ) ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_4 , V_12 , V_10 ) ;
break;
default:
if ( V_12 < 0xc0 ) {
V_7 = V_34 [ V_12 ] ;
if ( V_7 )
F_4 ( L_3 , V_7 ) ;
else
F_4 ( L_6 , V_12 ) ;
} else
F_4 ( L_7 , V_12 ) ;
break;
}
}
static void F_2 ( unsigned char * V_8 , int V_9 )
{
int V_10 , V_11 , V_12 ;
V_12 = V_8 [ 0 ] ;
switch( V_12 ) {
case V_13 :
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
case V_16 :
case V_19 :
case V_22 :
case V_25 :
case V_28 :
case V_31 :
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
void F_5 ( unsigned char * V_35 )
{
int V_5 , V_11 ;
F_2 ( V_35 , 0 ) ;
V_11 = F_6 ( V_35 ) ;
for ( V_5 = 0 ; V_5 < V_11 ; ++ V_5 )
F_4 ( L_11 , V_35 [ V_5 ] ) ;
F_4 ( L_12 ) ;
}
void F_7 ( struct V_36 * V_37 )
{
int V_5 ;
if ( V_37 -> V_38 == NULL )
return;
F_8 ( V_39 , V_37 , L_13 ) ;
F_2 ( V_37 -> V_38 , V_37 -> V_40 ) ;
F_4 ( L_14 ) ;
for ( V_5 = 0 ; V_5 < V_37 -> V_40 ; ++ V_5 )
F_4 ( L_11 , V_37 -> V_38 [ V_5 ] ) ;
F_4 ( L_12 ) ;
}
void
F_9 ( unsigned char V_41 ) {
#ifdef F_10
const char * V_42 ;
switch ( V_41 ) {
case 0 : V_42 = L_15 ; break;
case 0x2 : V_42 = L_16 ; break;
case 0x4 : V_42 = L_17 ; break;
case 0x8 : V_42 = L_18 ; break;
case 0x10 : V_42 = L_19 ; break;
case 0x14 : V_42 = L_20 ; break;
case 0x18 : V_42 = L_21 ; break;
case 0x22 : V_42 = L_22 ; break;
case 0x28 : V_42 = L_23 ; break;
case 0x30 : V_42 = L_24 ; break;
case 0x40 : V_42 = L_25 ; break;
default: V_42 = L_26 ;
}
F_4 ( V_39 L_3 , V_42 ) ;
#else
F_4 ( V_39 L_27 , V_41 ) ;
#endif
}
const char *
F_11 ( unsigned char V_43 ) {
#ifdef F_10
if ( V_43 <= 0xE )
return V_44 [ V_43 ] ;
#endif
return NULL ;
}
const char *
F_12 ( unsigned char V_45 , unsigned char V_46 ) {
#ifdef F_10
int V_47 ;
unsigned short V_48 = ( ( V_45 << 8 ) | V_46 ) ;
for ( V_47 = 0 ; V_49 [ V_47 ] . V_50 ; V_47 ++ )
if ( V_49 [ V_47 ] . V_51 == V_48 )
return V_49 [ V_47 ] . V_50 ;
for ( V_47 = 0 ; V_52 [ V_47 ] . V_53 ; V_47 ++ ) {
if ( V_52 [ V_47 ] . V_54 == V_45 &&
V_46 >= V_52 [ V_47 ] . V_55 &&
V_46 <= V_52 [ V_47 ] . V_56 )
return V_52 [ V_47 ] . V_53 ;
}
#endif
return NULL ;
}
void
F_13 ( unsigned char V_45 , unsigned char V_46 )
{
const char * V_57 = F_12 ( V_45 , V_46 ) ;
if ( V_57 ) {
if ( strstr ( V_57 , L_28 ) ) {
F_4 ( L_29 ) ;
F_4 ( V_57 , V_46 ) ;
} else
F_4 ( L_30 , V_57 ) ;
} else {
if ( V_45 >= 0x80 )
F_4 ( L_31 , V_45 ,
V_46 ) ;
if ( V_46 >= 0x80 )
F_4 ( L_32 , V_45 ,
V_46 ) ;
else
F_4 ( L_33 , V_45 , V_46 ) ;
}
F_4 ( L_12 ) ;
}
void
F_14 ( struct V_58 * V_59 )
{
const char * V_60 ;
V_60 = F_11 ( V_59 -> V_61 ) ;
if ( V_60 )
F_4 ( L_34 , V_60 ) ;
else
F_4 ( L_35 , V_59 -> V_61 ) ;
F_4 ( L_3 , F_15 ( V_59 ) ? L_36 :
L_37 ) ;
if ( V_59 -> V_62 >= 0x72 )
F_4 ( L_38 ) ;
F_4 ( L_12 ) ;
}
void
F_16 ( const char * V_7 , struct V_58 * V_59 )
{
F_4 ( V_39 L_39 , V_7 ) ;
F_14 ( V_59 ) ;
F_4 ( V_39 L_39 , V_7 ) ;
F_13 ( V_59 -> V_45 , V_59 -> V_46 ) ;
}
void
F_17 ( struct V_36 * V_63 , const char * V_64 ,
struct V_58 * V_59 )
{
F_8 ( V_39 , V_63 , L_39 , V_64 ) ;
F_14 ( V_59 ) ;
F_8 ( V_39 , V_63 , L_39 , V_64 ) ;
F_13 ( V_59 -> V_45 , V_59 -> V_46 ) ;
}
static void
F_18 ( const unsigned char * V_65 , int V_66 ,
struct V_58 * V_59 )
{
int V_5 , V_67 , V_68 ;
V_68 = F_19 ( V_65 , V_66 , V_59 ) ;
if ( 0 == V_68 ) {
V_67 = ( V_66 < 32 ) ? V_66 : 32 ;
F_4 ( L_40 ) ;
for ( V_5 = 0 ; V_5 < V_67 ; ++ V_5 ) {
if ( 0 == ( V_5 % 16 ) ) {
F_4 ( L_12 ) ;
F_4 ( V_39 L_41 ) ;
}
F_4 ( L_42 , V_65 [ V_5 ] ) ;
}
F_4 ( L_12 ) ;
return;
}
}
static void
F_20 ( const unsigned char * V_65 , int V_66 ,
struct V_58 * V_59 )
{
int V_5 , V_67 , V_68 ;
if ( V_59 -> V_62 < 0x72 )
{
char V_69 [ 80 ] ;
int V_70 , V_71 ;
unsigned int V_72 ;
V_71 = V_65 [ 0 ] & 0x80 ;
V_72 = ( ( V_65 [ 3 ] << 24 ) | ( V_65 [ 4 ] << 16 ) |
( V_65 [ 5 ] << 8 ) | V_65 [ 6 ] ) ;
V_68 = 0 ;
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
V_70 = sizeof( V_69 ) - 1 ;
if ( V_71 )
V_68 += snprintf ( V_69 + V_68 , V_70 - V_68 ,
L_43 , V_72 ) ;
if ( V_65 [ 2 ] & 0x80 ) {
if ( V_68 > 0 )
V_68 += snprintf ( V_69 + V_68 , V_70 - V_68 , L_44 ) ;
V_68 += snprintf ( V_69 + V_68 , V_70 - V_68 , L_45 ) ;
}
if ( V_65 [ 2 ] & 0x40 ) {
if ( V_68 > 0 )
V_68 += snprintf ( V_69 + V_68 , V_70 - V_68 , L_44 ) ;
V_68 += snprintf ( V_69 + V_68 , V_70 - V_68 , L_46 ) ;
}
if ( V_65 [ 2 ] & 0x20 ) {
if ( V_68 > 0 )
V_68 += snprintf ( V_69 + V_68 , V_70 - V_68 , L_44 ) ;
V_68 += snprintf ( V_69 + V_68 , V_70 - V_68 , L_47 ) ;
}
if ( V_68 > 0 )
F_4 ( L_48 , V_69 ) ;
} else if ( V_59 -> V_73 > 0 ) {
V_67 = 8 + V_59 -> V_73 ;
V_67 = ( V_66 < V_67 ) ? V_66 : V_67 ;
F_4 ( L_49
L_50 ) ;
for ( V_5 = 0 ; V_5 < V_67 ; ++ V_5 ) {
if ( 0 == ( V_5 % 16 ) ) {
F_4 ( L_12 ) ;
F_4 ( V_39 L_41 ) ;
}
F_4 ( L_42 , V_65 [ V_5 ] ) ;
}
F_4 ( L_12 ) ;
}
}
void F_21 ( const char * V_7 , const unsigned char * V_65 ,
int V_66 )
{
struct V_58 V_59 ;
F_4 ( V_39 L_39 , V_7 ) ;
F_18 ( V_65 , V_66 , & V_59 ) ;
F_14 ( & V_59 ) ;
F_20 ( V_65 , V_66 , & V_59 ) ;
F_4 ( V_39 L_39 , V_7 ) ;
F_13 ( V_59 . V_45 , V_59 . V_46 ) ;
}
void F_22 ( char * V_7 , struct V_36 * V_37 )
{
struct V_58 V_59 ;
F_8 ( V_39 , V_37 , L_51 ) ;
F_18 ( V_37 -> V_65 , V_74 ,
& V_59 ) ;
F_14 ( & V_59 ) ;
F_20 ( V_37 -> V_65 , V_74 ,
& V_59 ) ;
F_8 ( V_39 , V_37 , L_51 ) ;
F_13 ( V_59 . V_45 , V_59 . V_46 ) ;
}
void F_23 ( int V_75 )
{
int V_76 = F_24 ( V_75 ) ;
int V_77 = F_25 ( V_75 ) ;
F_4 ( L_52 ,
( V_76 < V_78 ? V_79 [ V_76 ] : L_53 ) ,
( V_77 < V_80 ? V_81 [ V_77 ] : L_53 ) ) ;
}
void F_23 ( int V_75 )
{
F_4 ( L_54 ,
F_24 ( V_75 ) , F_25 ( V_75 ) ) ;
}
void F_26 ( struct V_36 * V_37 )
{
F_8 ( V_39 , V_37 , L_51 ) ;
F_23 ( V_37 -> V_75 ) ;
}

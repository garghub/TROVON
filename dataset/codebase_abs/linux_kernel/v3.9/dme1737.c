static inline int F_1 ( int V_1 , int V_2 , int V_3 )
{
return ( V_1 * V_2 + ( 3 << ( V_3 - 3 ) ) ) / ( 3 << ( V_3 - 2 ) ) ;
}
static inline int F_2 ( int V_4 , int V_2 )
{
return F_3 ( ( V_4 * 192 + V_2 / 2 ) / V_2 , 0 , 255 ) ;
}
static inline int F_4 ( int V_1 , int V_3 )
{
return ( V_1 * 1000 ) >> ( V_3 - 8 ) ;
}
static inline int F_5 ( int V_4 )
{
return F_3 ( ( V_4 < 0 ? V_4 - 500 : V_4 + 500 ) / 1000 , - 128 , 127 ) ;
}
static inline int F_6 ( int V_1 )
{
return V_5 [ ( V_1 >> 4 ) & 0x0f ] ;
}
static int F_7 ( int V_4 , int V_1 )
{
int V_6 ;
for ( V_6 = 15 ; V_6 > 0 ; V_6 -- ) {
if ( V_4 > ( V_5 [ V_6 ] + V_5 [ V_6 - 1 ] + 1 ) / 2 )
break;
}
return ( V_1 & 0x0f ) | ( V_6 << 4 ) ;
}
static inline int F_8 ( int V_1 , int V_7 )
{
return ( ( ( V_7 == 1 ) ? V_1 : V_1 >> 4 ) & 0x0f ) * 1000 ;
}
static inline int F_9 ( int V_4 , int V_7 , int V_1 )
{
int V_8 = F_3 ( ( V_4 + 500 ) / 1000 , 0 , 15 ) ;
return ( V_7 == 1 ) ? ( V_1 & 0xf0 ) | V_8 : ( V_1 & 0x0f ) | ( V_8 << 4 ) ;
}
static inline int F_10 ( int V_1 , int V_9 )
{
if ( V_9 )
return V_9 * V_1 ;
else
return ( V_1 == 0 || V_1 == 0xffff ) ? 0 : 90000 * 60 / V_1 ;
}
static inline int F_11 ( int V_4 , int V_9 )
{
if ( V_9 ) {
return F_3 ( V_4 / V_9 , 0 , 0xffff ) ;
} else {
return ( V_4 <= 0 ) ? 0xffff :
F_3 ( 90000 * 60 / V_4 , 0 , 0xfffe ) ;
}
}
static inline int F_12 ( int V_1 )
{
return ( V_1 & 0x20 ) ? 0 : 60 >> ( V_1 & 0x03 ) ;
}
static inline int F_13 ( int V_1 )
{
int V_10 = ( V_1 >> 1 ) & 0x03 ;
return ( V_10 > 0 ) ? 1 << ( V_10 - 1 ) : 0 ;
}
static inline int F_14 ( int V_4 , int V_1 )
{
int V_10 = ( V_4 == 4 ) ? 3 : V_4 ;
return ( V_1 & 0xf9 ) | ( V_10 << 1 ) ;
}
static int F_15 ( int V_1 )
{
int V_6 ;
for ( V_6 = 10 ; V_6 > 0 ; V_6 -- ) {
if ( V_1 == V_11 [ V_6 ] )
break;
}
return 1000 + V_6 * 500 ;
}
static int F_16 ( int V_4 )
{
int V_6 ;
for ( V_6 = 10 ; V_6 > 0 ; V_6 -- ) {
if ( V_4 > ( 1000 + ( V_6 - 1 ) * 500 ) )
break;
}
return V_11 [ V_6 ] ;
}
static inline int F_17 ( int V_1 )
{
static const int V_12 [] = { 2 , 2 , 2 , 0 , - 1 , 2 , 2 , 1 } ;
return V_12 [ ( V_1 >> 5 ) & 0x07 ] ;
}
static inline int F_18 ( int V_4 , int V_1 )
{
int V_12 = ( V_4 == 1 ) ? 7 : 3 ;
return ( V_1 & 0x1f ) | ( ( V_12 & 0x07 ) << 5 ) ;
}
static inline int F_19 ( int V_1 )
{
static const int V_13 [] = { 1 , 2 , 4 , 0 , 0 , 6 , 7 , 0 } ;
return V_13 [ ( V_1 >> 5 ) & 0x07 ] ;
}
static inline int F_20 ( int V_4 , int V_1 )
{
int V_13 = ( V_4 == 4 ) ? 2 : V_4 - 1 ;
return ( V_1 & 0x1f ) | ( ( V_13 & 0x07 ) << 5 ) ;
}
static inline int F_21 ( int V_1 )
{
return V_14 [ V_1 & 0x0f ] ;
}
static int F_22 ( int V_4 , int V_1 )
{
int V_6 ;
if ( V_4 > 27500 ) {
V_6 = 10 ;
} else if ( V_4 > 22500 ) {
V_6 = 11 ;
} else {
for ( V_6 = 9 ; V_6 > 0 ; V_6 -- ) {
if ( V_4 > ( V_14 [ V_6 ] + V_14 [ V_6 - 1 ] + 1 ) / 2 )
break;
}
}
return ( V_1 & 0xf0 ) | V_6 ;
}
static inline int F_23 ( int V_1 , int V_7 )
{
int V_15 = ( V_7 == 1 ) ? V_1 >> 4 : V_1 ;
return ( V_15 & 0x08 ) ? V_16 [ V_15 & 0x07 ] : 0 ;
}
static int F_24 ( int V_4 , int V_7 , int V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 7 ; V_6 ++ ) {
if ( V_4 > ( V_16 [ V_6 ] + V_16 [ V_6 + 1 ] + 1 ) / 2 )
break;
}
return ( V_7 == 1 ) ? ( V_1 & 0x8f ) | ( V_6 << 4 ) : ( V_1 & 0xf8 ) | V_6 ;
}
static inline int F_25 ( int V_1 , int V_7 )
{
return F_23 ( V_1 , V_7 ) ? 1 : 0 ;
}
static inline int F_26 ( int V_4 , int V_7 , int V_1 )
{
int V_12 = ( V_7 == 1 ) ? 0x80 : 0x08 ;
return V_4 ? V_1 | V_12 : V_1 & ~ V_12 ;
}
static inline int F_27 ( int V_1 , int V_7 )
{
return ( V_1 >> ( V_7 + 5 ) ) & 0x01 ;
}
static inline int F_28 ( int V_4 , int V_7 , int V_1 )
{
return ( V_1 & ~ ( 1 << ( V_7 + 5 ) ) ) | ( ( V_4 & 0x01 ) << ( V_7 + 5 ) ) ;
}
static T_1 F_29 ( const struct V_17 * V_18 , T_1 V_1 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
T_2 V_4 ;
if ( V_20 ) {
V_4 = F_30 ( V_20 , V_1 ) ;
if ( V_4 < 0 ) {
F_31 ( & V_20 -> V_21 , L_1
L_2
L_3 , V_1 ) ;
}
} else {
F_32 ( V_1 , V_18 -> V_22 ) ;
V_4 = F_33 ( V_18 -> V_22 + 1 ) ;
}
return V_4 ;
}
static T_2 F_34 ( const struct V_17 * V_18 , T_1 V_1 , T_1 V_4 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
T_2 V_3 = 0 ;
if ( V_20 ) {
V_3 = F_35 ( V_20 , V_1 , V_4 ) ;
if ( V_3 < 0 ) {
F_31 ( & V_20 -> V_21 , L_4
L_2
L_3 , V_1 ) ;
}
} else {
F_32 ( V_1 , V_18 -> V_22 ) ;
F_32 ( V_4 , V_18 -> V_22 + 1 ) ;
}
return V_3 ;
}
static struct V_17 * F_36 ( struct V_23 * V_21 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
int V_7 ;
T_1 V_24 [ 6 ] ;
F_38 ( & V_18 -> V_25 ) ;
if ( F_39 ( V_26 , V_18 -> V_27 + 600 * V_28 ) || ! V_18 -> V_29 ) {
F_34 ( V_18 , V_30 , F_29 ( V_18 ,
V_30 ) | 0x10 ) ;
V_18 -> V_27 = V_26 ;
}
if ( F_39 ( V_26 , V_18 -> V_31 + V_28 ) || ! V_18 -> V_29 ) {
if ( V_18 -> V_32 & V_33 ) {
V_18 -> V_34 = F_29 ( V_18 , V_35 ) &
0x3f ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_36 ) ; V_7 ++ ) {
if ( V_7 == 7 && ! ( V_18 -> V_32 & V_37 ) )
continue;
V_18 -> V_36 [ V_7 ] = F_29 ( V_18 ,
F_41 ( V_7 ) ) << 8 ;
V_18 -> V_38 [ V_7 ] = F_29 ( V_18 ,
F_42 ( V_7 ) ) ;
V_18 -> V_39 [ V_7 ] = F_29 ( V_18 ,
F_43 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_40 ) ; V_7 ++ ) {
V_18 -> V_40 [ V_7 ] = F_29 ( V_18 ,
F_44 ( V_7 ) ) << 8 ;
V_18 -> V_41 [ V_7 ] = F_29 ( V_18 ,
F_45 ( V_7 ) ) ;
V_18 -> V_42 [ V_7 ] = F_29 ( V_18 ,
F_46 ( V_7 ) ) ;
if ( V_18 -> V_32 & V_43 ) {
V_18 -> V_44 [ V_7 ] = F_29 ( V_18 ,
F_47 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_24 ) ; V_7 ++ ) {
if ( V_7 == 5 && ! ( V_18 -> V_32 & V_37 ) )
continue;
V_24 [ V_7 ] = F_29 ( V_18 ,
F_48 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_36 ) ; V_7 ++ ) {
if ( V_7 == 7 && ! ( V_18 -> V_32 & V_37 ) )
continue;
V_18 -> V_36 [ V_7 ] |= ( V_24 [ V_45 [ V_7 ] ] <<
V_46 [ V_7 ] ) & 0xf0 ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_40 ) ; V_7 ++ ) {
V_18 -> V_40 [ V_7 ] |= ( V_24 [ V_47 [ V_7 ] ] <<
V_48 [ V_7 ] ) & 0xf0 ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_49 ) ; V_7 ++ ) {
if ( ! ( V_18 -> V_32 & F_49 ( V_7 ) ) )
continue;
V_18 -> V_49 [ V_7 ] = F_29 ( V_18 ,
F_50 ( V_7 ) ) ;
V_18 -> V_49 [ V_7 ] |= F_29 ( V_18 ,
F_50 ( V_7 ) + 1 ) << 8 ;
V_18 -> V_50 [ V_7 ] = F_29 ( V_18 ,
F_51 ( V_7 ) ) ;
V_18 -> V_50 [ V_7 ] |= F_29 ( V_18 ,
F_51 ( V_7 ) + 1 ) << 8 ;
V_18 -> V_51 [ V_7 ] = F_29 ( V_18 ,
F_52 ( V_7 ) ) ;
if ( V_7 > 3 ) {
V_18 -> V_52 [ V_7 - 4 ] = F_29 ( V_18 ,
F_53 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_53 ) ; V_7 ++ ) {
if ( ! ( V_18 -> V_32 & F_54 ( V_7 ) ) )
continue;
V_18 -> V_53 [ V_7 ] = F_29 ( V_18 ,
F_55 ( V_7 ) ) ;
V_18 -> V_54 [ V_7 ] = F_29 ( V_18 ,
F_56 ( V_7 ) ) ;
if ( V_7 < 3 ) {
V_18 -> V_55 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
V_18 -> V_56 [ V_7 ] = F_29 ( V_18 ,
F_58 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_57 ) ; V_7 ++ ) {
V_18 -> V_57 [ V_7 ] = F_29 ( V_18 ,
F_59 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_58 ) ; V_7 ++ ) {
if ( ( V_7 == 2 ) && ! ( V_18 -> V_32 & V_59 ) )
continue;
if ( ( V_7 == 1 ) && ( V_18 -> type == V_60 ) ) {
V_18 -> V_58 [ 1 ] = F_29 ( V_18 ,
F_60 ( 2 ) ) ;
V_18 -> V_61 [ 1 ] = F_29 ( V_18 ,
F_61 ( 2 ) ) ;
} else {
V_18 -> V_58 [ V_7 ] = F_29 ( V_18 ,
F_60 ( V_7 ) ) ;
V_18 -> V_61 [ V_7 ] = F_29 ( V_18 ,
F_61 ( V_7 ) ) ;
}
}
if ( V_18 -> V_32 & V_62 ) {
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_63 ) ; V_7 ++ ) {
V_18 -> V_63 [ V_7 ] = F_29 ( V_18 ,
F_62 ( V_7 ) ) ;
}
}
V_18 -> V_64 = F_29 ( V_18 ,
V_65 ) ;
if ( V_18 -> V_64 & 0x80 ) {
V_18 -> V_64 |= F_29 ( V_18 ,
V_66 ) << 8 ;
V_18 -> V_64 |= F_29 ( V_18 ,
V_67 ) << 16 ;
}
if ( ! V_18 -> V_20 ) {
if ( V_18 -> V_64 & 0xff0000 )
F_34 ( V_18 , V_67 , 0xff ) ;
if ( V_18 -> V_64 & 0xff00 )
F_34 ( V_18 , V_66 , 0xff ) ;
if ( V_18 -> V_64 & 0xff )
F_34 ( V_18 , V_65 , 0xff ) ;
}
V_18 -> V_31 = V_26 ;
V_18 -> V_29 = 1 ;
}
F_63 ( & V_18 -> V_25 ) ;
return V_18 ;
}
static T_3 F_64 ( struct V_23 * V_21 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
int V_3 ;
switch ( V_74 ) {
case V_76 :
V_3 = F_1 ( V_18 -> V_36 [ V_7 ] , V_18 -> V_77 [ V_7 ] , 16 ) ;
break;
case V_78 :
V_3 = F_1 ( V_18 -> V_38 [ V_7 ] , V_18 -> V_77 [ V_7 ] , 8 ) ;
break;
case V_79 :
V_3 = F_1 ( V_18 -> V_39 [ V_7 ] , V_18 -> V_77 [ V_7 ] , 8 ) ;
break;
case V_80 :
V_3 = ( V_18 -> V_64 >> V_81 [ V_7 ] ) & 0x01 ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_5 , V_74 ) ;
}
return sprintf ( V_70 , L_6 , V_3 ) ;
}
static T_3 F_67 ( struct V_23 * V_21 , struct V_68 * V_69 ,
const char * V_70 , T_4 V_82 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
long V_4 ;
int V_83 ;
V_83 = F_68 ( V_70 , 10 , & V_4 ) ;
if ( V_83 )
return V_83 ;
F_38 ( & V_18 -> V_25 ) ;
switch ( V_74 ) {
case V_78 :
V_18 -> V_38 [ V_7 ] = F_2 ( V_4 , V_18 -> V_77 [ V_7 ] ) ;
F_34 ( V_18 , F_42 ( V_7 ) ,
V_18 -> V_38 [ V_7 ] ) ;
break;
case V_79 :
V_18 -> V_39 [ V_7 ] = F_2 ( V_4 , V_18 -> V_77 [ V_7 ] ) ;
F_34 ( V_18 , F_43 ( V_7 ) ,
V_18 -> V_39 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_5 , V_74 ) ;
}
F_63 ( & V_18 -> V_25 ) ;
return V_82 ;
}
static T_3 F_69 ( struct V_23 * V_21 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
int V_3 ;
switch ( V_74 ) {
case V_84 :
V_3 = F_4 ( V_18 -> V_40 [ V_7 ] , 16 ) ;
break;
case V_85 :
V_3 = F_4 ( V_18 -> V_41 [ V_7 ] , 8 ) ;
break;
case V_86 :
V_3 = F_4 ( V_18 -> V_42 [ V_7 ] , 8 ) ;
break;
case V_87 :
V_3 = F_4 ( V_18 -> V_44 [ V_7 ] , 8 ) ;
break;
case V_88 :
V_3 = ( V_18 -> V_64 >> V_89 [ V_7 ] ) & 0x01 ;
break;
case V_90 :
V_3 = ( ( ( V_91 ) V_18 -> V_40 [ V_7 ] & 0xff00 ) == 0x8000 ) ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_5 , V_74 ) ;
}
return sprintf ( V_70 , L_6 , V_3 ) ;
}
static T_3 F_70 ( struct V_23 * V_21 , struct V_68 * V_69 ,
const char * V_70 , T_4 V_82 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
long V_4 ;
int V_83 ;
V_83 = F_68 ( V_70 , 10 , & V_4 ) ;
if ( V_83 )
return V_83 ;
F_38 ( & V_18 -> V_25 ) ;
switch ( V_74 ) {
case V_85 :
V_18 -> V_41 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_45 ( V_7 ) ,
V_18 -> V_41 [ V_7 ] ) ;
break;
case V_86 :
V_18 -> V_42 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_46 ( V_7 ) ,
V_18 -> V_42 [ V_7 ] ) ;
break;
case V_87 :
V_18 -> V_44 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_47 ( V_7 ) ,
V_18 -> V_44 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_5 , V_74 ) ;
}
F_63 ( & V_18 -> V_25 ) ;
return V_82 ;
}
static T_3 F_71 ( struct V_23 * V_21 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
int V_3 ;
switch ( V_74 ) {
case V_92 :
if ( ( V_7 == 1 ) && ( V_18 -> V_93 & 0x02 ) )
V_3 = 4 ;
else
V_3 = 1 << V_7 ;
break;
case V_94 :
V_3 = F_4 ( V_18 -> V_58 [ V_7 ] , 8 ) -
F_8 ( V_18 -> V_63 [ V_7 == 2 ] , V_7 ) ;
break;
case V_95 :
V_3 = F_4 ( V_18 -> V_58 [ V_7 ] , 8 ) ;
break;
case V_96 :
V_3 = F_4 ( V_18 -> V_58 [ V_7 ] , 8 ) +
F_6 ( V_18 -> V_54 [ V_7 ] ) ;
break;
case V_97 :
V_3 = F_4 ( V_18 -> V_61 [ V_7 ] , 8 ) ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_5 , V_74 ) ;
}
return sprintf ( V_70 , L_6 , V_3 ) ;
}
static T_3 F_72 ( struct V_23 * V_21 , struct V_68 * V_69 ,
const char * V_70 , T_4 V_82 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
long V_4 ;
int V_83 ;
V_83 = F_68 ( V_70 , 10 , & V_4 ) ;
if ( V_83 )
return V_83 ;
F_38 ( & V_18 -> V_25 ) ;
switch ( V_74 ) {
case V_94 :
V_18 -> V_58 [ V_7 ] = F_29 ( V_18 ,
F_60 ( V_7 ) ) ;
V_18 -> V_63 [ V_7 == 2 ] = F_9 (
F_4 ( V_18 -> V_58 [ V_7 ] , 8 ) -
V_4 , V_7 , F_29 ( V_18 ,
F_62 ( V_7 == 2 ) ) ) ;
F_34 ( V_18 , F_62 ( V_7 == 2 ) ,
V_18 -> V_63 [ V_7 == 2 ] ) ;
break;
case V_95 :
V_18 -> V_58 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_60 ( V_7 ) ,
V_18 -> V_58 [ V_7 ] ) ;
break;
case V_96 :
V_18 -> V_58 [ V_7 ] = F_29 ( V_18 ,
F_60 ( V_7 ) ) ;
V_18 -> V_54 [ V_7 ] = F_7 ( V_4 -
F_4 ( V_18 -> V_58 [ V_7 ] , 8 ) ,
F_29 ( V_18 ,
F_56 ( V_7 ) ) ) ;
F_34 ( V_18 , F_56 ( V_7 ) ,
V_18 -> V_54 [ V_7 ] ) ;
break;
case V_97 :
V_18 -> V_61 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_61 ( V_7 ) ,
V_18 -> V_61 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_5 , V_74 ) ;
}
F_63 ( & V_18 -> V_25 ) ;
return V_82 ;
}
static T_3 F_73 ( struct V_23 * V_21 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
int V_3 ;
switch ( V_74 ) {
case V_98 :
V_3 = F_10 ( V_18 -> V_49 [ V_7 ] ,
V_7 < 4 ? 0 :
F_12 ( V_18 -> V_51 [ V_7 ] ) ) ;
break;
case V_99 :
V_3 = F_10 ( V_18 -> V_50 [ V_7 ] ,
V_7 < 4 ? 0 :
F_12 ( V_18 -> V_51 [ V_7 ] ) ) ;
break;
case V_100 :
V_3 = F_15 ( V_18 -> V_52 [ V_7 - 4 ] ) ;
break;
case V_101 :
V_3 = ( V_18 -> V_64 >> V_102 [ V_7 ] ) & 0x01 ;
break;
case V_103 :
V_3 = F_13 ( V_18 -> V_51 [ V_7 ] ) ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_5 , V_74 ) ;
}
return sprintf ( V_70 , L_6 , V_3 ) ;
}
static T_3 F_74 ( struct V_23 * V_21 , struct V_68 * V_69 ,
const char * V_70 , T_4 V_82 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
long V_4 ;
int V_83 ;
V_83 = F_68 ( V_70 , 10 , & V_4 ) ;
if ( V_83 )
return V_83 ;
F_38 ( & V_18 -> V_25 ) ;
switch ( V_74 ) {
case V_99 :
if ( V_7 < 4 ) {
V_18 -> V_50 [ V_7 ] = F_11 ( V_4 , 0 ) ;
} else {
V_18 -> V_51 [ V_7 ] = F_29 ( V_18 ,
F_52 ( V_7 ) ) ;
V_18 -> V_50 [ V_7 ] = F_11 ( V_4 ,
F_12 ( V_18 -> V_51 [ V_7 ] ) ) ;
}
F_34 ( V_18 , F_51 ( V_7 ) ,
V_18 -> V_50 [ V_7 ] & 0xff ) ;
F_34 ( V_18 , F_51 ( V_7 ) + 1 ,
V_18 -> V_50 [ V_7 ] >> 8 ) ;
break;
case V_100 :
V_18 -> V_52 [ V_7 - 4 ] = F_16 ( V_4 ) ;
F_34 ( V_18 , F_53 ( V_7 ) ,
V_18 -> V_52 [ V_7 - 4 ] ) ;
break;
case V_103 :
if ( ! ( V_4 == 1 || V_4 == 2 || V_4 == 4 ) ) {
V_82 = - V_104 ;
F_31 ( V_21 , L_7
L_8 ,
V_4 ) ;
goto exit;
}
V_18 -> V_51 [ V_7 ] = F_14 ( V_4 , F_29 ( V_18 ,
F_52 ( V_7 ) ) ) ;
F_34 ( V_18 , F_52 ( V_7 ) ,
V_18 -> V_51 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_5 , V_74 ) ;
}
exit:
F_63 ( & V_18 -> V_25 ) ;
return V_82 ;
}
static T_3 F_75 ( struct V_23 * V_21 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
int V_3 ;
switch ( V_74 ) {
case V_105 :
if ( F_17 ( V_18 -> V_55 [ V_7 ] ) == 0 )
V_3 = 255 ;
else
V_3 = V_18 -> V_53 [ V_7 ] ;
break;
case V_106 :
V_3 = F_21 ( V_18 -> V_54 [ V_7 ] ) ;
break;
case V_107 :
if ( V_7 >= 3 )
V_3 = 1 ;
else
V_3 = F_17 ( V_18 -> V_55 [ V_7 ] ) ;
break;
case V_108 :
V_3 = F_23 ( V_18 -> V_57 [ V_7 > 0 ] , V_7 ) ;
break;
case V_109 :
if ( F_17 ( V_18 -> V_55 [ V_7 ] ) == 2 )
V_3 = F_19 ( V_18 -> V_55 [ V_7 ] ) ;
else
V_3 = V_18 -> V_110 [ V_7 ] ;
break;
case V_111 :
if ( F_27 ( V_18 -> V_57 [ 0 ] , V_7 ) )
V_3 = V_18 -> V_56 [ V_7 ] ;
else
V_3 = 0 ;
break;
case V_112 :
V_3 = V_18 -> V_56 [ V_7 ] ;
break;
case V_113 :
V_3 = 255 ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_5 , V_74 ) ;
}
return sprintf ( V_70 , L_6 , V_3 ) ;
}
static T_3 F_76 ( struct V_23 * V_21 , struct V_68 * V_69 ,
const char * V_70 , T_4 V_82 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_71
* V_72 = F_65 ( V_69 ) ;
int V_7 = V_72 -> V_73 ;
int V_74 = V_72 -> V_75 ;
long V_4 ;
int V_83 ;
V_83 = F_68 ( V_70 , 10 , & V_4 ) ;
if ( V_83 )
return V_83 ;
F_38 ( & V_18 -> V_25 ) ;
switch ( V_74 ) {
case V_105 :
V_18 -> V_53 [ V_7 ] = F_3 ( V_4 , 0 , 255 ) ;
F_34 ( V_18 , F_55 ( V_7 ) , V_18 -> V_53 [ V_7 ] ) ;
break;
case V_106 :
V_18 -> V_54 [ V_7 ] = F_22 ( V_4 , F_29 ( V_18 ,
F_56 ( V_7 ) ) ) ;
F_34 ( V_18 , F_56 ( V_7 ) ,
V_18 -> V_54 [ V_7 ] ) ;
break;
case V_107 :
if ( V_4 < 0 || V_4 > 2 ) {
V_82 = - V_104 ;
F_31 ( V_21 , L_9
L_10 ,
V_4 ) ;
goto exit;
}
V_18 -> V_55 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
if ( V_4 == F_17 ( V_18 -> V_55 [ V_7 ] ) ) {
goto exit;
}
if ( F_17 ( V_18 -> V_55 [ V_7 ] ) == 2 ) {
V_18 -> V_110 [ V_7 ] = F_19 (
V_18 -> V_55 [ V_7 ] ) ;
V_18 -> V_57 [ V_7 > 0 ] = F_29 ( V_18 ,
F_59 ( V_7 > 0 ) ) ;
V_18 -> V_114 &= ~ ( 1 << V_7 ) ;
if ( F_25 ( V_18 -> V_57 [ V_7 > 0 ] , V_7 ) ) {
V_18 -> V_114 |= ( 1 << V_7 ) ;
V_18 -> V_57 [ V_7 > 0 ] = F_26 ( 0 , V_7 ,
V_18 -> V_57 [ V_7 > 0 ] ) ;
F_34 ( V_18 ,
F_59 ( V_7 > 0 ) ,
V_18 -> V_57 [ V_7 > 0 ] ) ;
}
}
switch ( V_4 ) {
case 0 :
F_77 ( V_21 , V_115 [ V_7 ] ,
V_116 ) ;
V_18 -> V_55 [ V_7 ] = F_18 ( 0 ,
V_18 -> V_55 [ V_7 ] ) ;
F_34 ( V_18 , F_57 ( V_7 ) ,
V_18 -> V_55 [ V_7 ] ) ;
break;
case 1 :
V_18 -> V_55 [ V_7 ] = F_18 ( 1 ,
V_18 -> V_55 [ V_7 ] ) ;
F_34 ( V_18 , F_57 ( V_7 ) ,
V_18 -> V_55 [ V_7 ] ) ;
F_77 ( V_21 , V_115 [ V_7 ] ,
V_116 | V_117 ) ;
break;
case 2 :
F_77 ( V_21 , V_115 [ V_7 ] ,
V_116 ) ;
V_18 -> V_55 [ V_7 ] = F_20 (
V_18 -> V_110 [ V_7 ] ,
V_18 -> V_55 [ V_7 ] ) ;
F_34 ( V_18 , F_57 ( V_7 ) ,
V_18 -> V_55 [ V_7 ] ) ;
if ( V_18 -> V_114 & ( 1 << V_7 ) ) {
V_18 -> V_57 [ V_7 > 0 ] = F_26 ( 1 , V_7 ,
F_29 ( V_18 ,
F_59 ( V_7 > 0 ) ) ) ;
F_34 ( V_18 ,
F_59 ( V_7 > 0 ) ,
V_18 -> V_57 [ V_7 > 0 ] ) ;
}
break;
}
break;
case V_108 :
V_18 -> V_55 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
V_18 -> V_57 [ V_7 > 0 ] = F_29 ( V_18 ,
F_59 ( V_7 > 0 ) ) ;
if ( V_4 > 0 ) {
V_18 -> V_57 [ V_7 > 0 ] = F_24 ( V_4 , V_7 ,
V_18 -> V_57 [ V_7 > 0 ] ) ;
}
if ( F_17 ( V_18 -> V_55 [ V_7 ] ) == 2 ) {
V_18 -> V_57 [ V_7 > 0 ] = F_26 ( V_4 > 0 , V_7 ,
V_18 -> V_57 [ V_7 > 0 ] ) ;
}
F_34 ( V_18 , F_59 ( V_7 > 0 ) ,
V_18 -> V_57 [ V_7 > 0 ] ) ;
break;
case V_109 :
if ( ! ( V_4 == 1 || V_4 == 2 || V_4 == 4 ||
V_4 == 6 || V_4 == 7 ) ) {
V_82 = - V_104 ;
F_31 ( V_21 , L_11
L_12
L_13 , V_4 ) ;
goto exit;
}
V_18 -> V_55 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
if ( F_17 ( V_18 -> V_55 [ V_7 ] ) == 2 ) {
V_18 -> V_55 [ V_7 ] = F_20 ( V_4 ,
V_18 -> V_55 [ V_7 ] ) ;
F_34 ( V_18 , F_57 ( V_7 ) ,
V_18 -> V_55 [ V_7 ] ) ;
} else {
V_18 -> V_110 [ V_7 ] = V_4 ;
}
break;
case V_111 :
V_18 -> V_56 [ V_7 ] = F_29 ( V_18 ,
F_58 ( V_7 ) ) ;
if ( V_4 > ( ( V_18 -> V_56 [ V_7 ] + 1 ) / 2 ) ) {
V_18 -> V_57 [ 0 ] = F_28 ( 1 , V_7 ,
F_29 ( V_18 ,
F_59 ( 0 ) ) ) ;
} else {
V_18 -> V_57 [ 0 ] = F_28 ( 0 , V_7 ,
F_29 ( V_18 ,
F_59 ( 0 ) ) ) ;
}
F_34 ( V_18 , F_59 ( 0 ) ,
V_18 -> V_57 [ 0 ] ) ;
break;
case V_112 :
V_18 -> V_56 [ V_7 ] = F_3 ( V_4 , 0 , 255 ) ;
F_34 ( V_18 , F_58 ( V_7 ) ,
V_18 -> V_56 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_5 , V_74 ) ;
}
exit:
F_63 ( & V_18 -> V_25 ) ;
return V_82 ;
}
static T_3 F_78 ( struct V_23 * V_21 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_19 * V_20 = F_79 ( V_21 ) ;
struct V_17 * V_18 = F_80 ( V_20 ) ;
return sprintf ( V_70 , L_6 , V_18 -> V_118 ) ;
}
static T_3 F_81 ( struct V_23 * V_21 , struct V_68 * V_69 ,
const char * V_70 , T_4 V_82 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
long V_4 ;
int V_83 ;
V_83 = F_68 ( V_70 , 10 , & V_4 ) ;
if ( V_83 )
return V_83 ;
V_18 -> V_118 = V_4 ;
return V_82 ;
}
static T_3 F_82 ( struct V_23 * V_21 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
return sprintf ( V_70 , L_6 , F_83 ( V_18 -> V_34 , V_18 -> V_118 ) ) ;
}
static T_3 F_84 ( struct V_23 * V_21 , struct V_68 * V_69 ,
char * V_70 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
return sprintf ( V_70 , L_14 , V_18 -> V_119 ) ;
}
static inline void F_85 ( int V_120 )
{
F_32 ( 0x55 , V_120 ) ;
}
static inline void F_86 ( int V_120 )
{
F_32 ( 0xaa , V_120 ) ;
}
static inline int F_87 ( int V_120 , int V_1 )
{
F_32 ( V_1 , V_120 ) ;
return F_33 ( V_120 + 1 ) ;
}
static inline void F_88 ( int V_120 , int V_1 , int V_4 )
{
F_32 ( V_1 , V_120 ) ;
F_32 ( V_4 , V_120 + 1 ) ;
}
static void F_77 ( struct V_23 * V_21 ,
struct V_121 * V_69 , T_5 V_122 )
{
if ( F_89 ( & V_21 -> V_123 , V_69 , V_122 ) ) {
F_31 ( V_21 , L_15 ,
V_69 -> V_119 ) ;
}
}
static void F_90 ( struct V_23 * V_21 ,
const struct V_124 * V_125 ,
T_5 V_122 )
{
struct V_121 * * V_69 ;
for ( V_69 = V_125 -> V_126 ; * V_69 ; V_69 ++ )
F_77 ( V_21 , * V_69 , V_122 ) ;
}
static void F_91 ( struct V_23 * V_21 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_40 ( V_127 ) ; V_7 ++ ) {
if ( V_18 -> V_32 & F_49 ( V_7 ) ) {
F_92 ( & V_21 -> V_123 ,
& V_127 [ V_7 ] ) ;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_128 ) ; V_7 ++ ) {
if ( V_18 -> V_32 & F_54 ( V_7 ) ) {
F_92 ( & V_21 -> V_123 ,
& V_128 [ V_7 ] ) ;
if ( ( V_18 -> V_32 & V_129 ) && V_7 < 3 ) {
F_93 ( & V_21 -> V_123 ,
V_130 [ V_7 ] ) ;
}
}
}
if ( V_18 -> V_32 & V_43 )
F_92 ( & V_21 -> V_123 , & V_131 ) ;
if ( V_18 -> V_32 & V_33 )
F_92 ( & V_21 -> V_123 , & V_132 ) ;
if ( V_18 -> V_32 & V_59 )
F_92 ( & V_21 -> V_123 , & V_133 ) ;
if ( V_18 -> V_32 & V_62 )
F_92 ( & V_21 -> V_123 , & V_134 ) ;
if ( V_18 -> V_32 & V_37 )
F_92 ( & V_21 -> V_123 , & V_135 ) ;
F_92 ( & V_21 -> V_123 , & V_136 ) ;
if ( ! V_18 -> V_20 )
F_93 ( & V_21 -> V_123 , & V_137 . V_69 ) ;
}
static int F_94 ( struct V_23 * V_21 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
int V_83 , V_7 ;
if ( ! V_18 -> V_20 ) {
V_83 = F_95 ( & V_21 -> V_123 , & V_137 . V_69 ) ;
if ( V_83 )
goto exit;
}
V_83 = F_96 ( & V_21 -> V_123 , & V_136 ) ;
if ( V_83 )
goto V_138;
if ( V_18 -> V_32 & V_43 ) {
V_83 = F_96 ( & V_21 -> V_123 ,
& V_131 ) ;
if ( V_83 )
goto V_138;
}
if ( V_18 -> V_32 & V_33 ) {
V_83 = F_96 ( & V_21 -> V_123 , & V_132 ) ;
if ( V_83 )
goto V_138;
}
if ( V_18 -> V_32 & V_59 ) {
V_83 = F_96 ( & V_21 -> V_123 , & V_133 ) ;
if ( V_83 )
goto V_138;
}
if ( V_18 -> V_32 & V_62 ) {
V_83 = F_96 ( & V_21 -> V_123 , & V_134 ) ;
if ( V_83 )
goto V_138;
}
if ( V_18 -> V_32 & V_37 ) {
V_83 = F_96 ( & V_21 -> V_123 , & V_135 ) ;
if ( V_83 )
goto V_138;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_127 ) ; V_7 ++ ) {
if ( V_18 -> V_32 & F_49 ( V_7 ) ) {
V_83 = F_96 ( & V_21 -> V_123 ,
& V_127 [ V_7 ] ) ;
if ( V_83 )
goto V_138;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_128 ) ; V_7 ++ ) {
if ( V_18 -> V_32 & F_54 ( V_7 ) ) {
V_83 = F_96 ( & V_21 -> V_123 ,
& V_128 [ V_7 ] ) ;
if ( V_83 )
goto V_138;
if ( ( V_18 -> V_32 & V_129 ) && ( V_7 < 3 ) ) {
V_83 = F_95 ( & V_21 -> V_123 ,
V_130 [ V_7 ] ) ;
if ( V_83 )
goto V_138;
}
}
}
if ( V_18 -> V_139 & 0x02 ) {
F_97 ( V_21 , L_16
L_17 ) ;
} else {
F_90 ( V_21 , & V_140 ,
V_116 | V_117 ) ;
if ( V_18 -> V_32 & V_43 ) {
F_90 ( V_21 , & V_131 ,
V_116 | V_117 ) ;
}
if ( V_18 -> V_32 & V_59 ) {
F_90 ( V_21 , & V_141 ,
V_116 | V_117 ) ;
}
if ( V_18 -> V_32 & V_62 ) {
F_90 ( V_21 , & V_134 ,
V_116 | V_117 ) ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_142 ) ; V_7 ++ ) {
if ( V_18 -> V_32 & F_54 ( V_7 ) ) {
F_90 ( V_21 ,
& V_142 [ V_7 ] ,
V_116 | V_117 ) ;
if ( ( V_18 -> V_32 & V_129 ) &&
V_7 < 3 ) {
F_77 ( V_21 ,
V_130 [ V_7 ] ,
V_116 | V_117 ) ;
}
}
}
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
if ( ( V_18 -> V_32 & F_54 ( V_7 ) ) &&
( F_17 ( V_18 -> V_55 [ V_7 ] ) == 1 ) ) {
F_77 ( V_21 ,
V_115 [ V_7 ] ,
V_116 | V_117 ) ;
}
}
}
return 0 ;
V_138:
F_91 ( V_21 ) ;
exit:
return V_83 ;
}
static int F_98 ( struct V_23 * V_21 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
int V_7 ;
T_1 V_1 ;
V_18 -> V_77 = F_99 ( V_18 -> type ) ;
V_18 -> V_139 = F_29 ( V_18 , V_30 ) ;
if ( ! ( V_18 -> V_139 & 0x01 ) ) {
if ( ! V_143 ) {
F_100 ( V_21 , L_18
L_19
L_20 ) ;
return - V_144 ;
}
V_18 -> V_139 |= 0x01 ;
F_34 ( V_18 , V_30 , V_18 -> V_139 ) ;
}
if ( ! ( V_18 -> V_139 & 0x04 ) ) {
F_100 ( V_21 , L_21 ) ;
return - V_144 ;
}
if ( V_20 ) {
V_18 -> V_93 = F_29 ( V_18 , V_145 ) ;
if ( V_18 -> V_93 & 0x04 )
V_18 -> V_32 |= F_49 ( 2 ) ;
if ( V_20 -> V_22 == 0x2e )
V_18 -> V_32 |= F_49 ( 3 ) | F_54 ( 2 ) ;
if ( F_101 ( 0x2e , V_18 ) &&
F_101 ( 0x4e , V_18 ) ) {
F_31 ( V_21 , L_22
L_23 ) ;
}
}
V_18 -> V_32 |= F_49 ( 0 ) | F_49 ( 1 ) | F_54 ( 0 ) | F_54 ( 1 ) ;
switch ( V_18 -> type ) {
case V_146 :
V_18 -> V_32 |= V_43 | V_33 | V_59 |
V_62 | V_129 ;
break;
case V_147 :
V_18 -> V_32 |= V_43 | V_59 |
V_62 | V_129 | F_49 ( 2 ) | F_54 ( 2 ) ;
break;
case V_148 :
V_18 -> V_32 |= V_59 ;
break;
case V_60 :
V_18 -> V_32 |= F_49 ( 2 ) | F_54 ( 2 ) | V_37 ;
break;
default:
break;
}
F_97 ( V_21 , L_24
L_25 ,
( V_18 -> V_32 & F_54 ( 2 ) ) ? L_26 : L_27 ,
( V_18 -> V_32 & F_54 ( 4 ) ) ? L_26 : L_27 ,
( V_18 -> V_32 & F_54 ( 5 ) ) ? L_26 : L_27 ,
( V_18 -> V_32 & F_49 ( 2 ) ) ? L_26 : L_27 ,
( V_18 -> V_32 & F_49 ( 3 ) ) ? L_26 : L_27 ,
( V_18 -> V_32 & F_49 ( 4 ) ) ? L_26 : L_27 ,
( V_18 -> V_32 & F_49 ( 5 ) ) ? L_26 : L_27 ) ;
V_1 = F_29 ( V_18 , V_149 ) ;
if ( V_20 && V_1 != 0xa4 ) {
F_31 ( V_21 , L_28
L_29
L_30
L_3 ,
( V_1 & 0x03 ) + 1 , ( ( V_1 >> 2 ) & 0x03 ) + 1 ,
( ( V_1 >> 4 ) & 0x03 ) + 1 , ( ( V_1 >> 6 ) & 0x03 ) + 1 ) ;
} else if ( ! V_20 && V_1 != 0x24 ) {
F_31 ( V_21 , L_28
L_31
L_32 ,
( V_1 & 0x03 ) + 1 , ( ( V_1 >> 2 ) & 0x03 ) + 1 ,
( ( V_1 >> 4 ) & 0x03 ) + 1 ) ;
}
if ( ! ( V_18 -> V_139 & 0x02 ) ) {
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_18 -> V_55 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
if ( ( V_18 -> V_32 & F_54 ( V_7 ) ) &&
( F_17 ( V_18 -> V_55 [ V_7 ] ) == - 1 ) ) {
F_97 ( V_21 , L_33
L_34 , V_7 + 1 ) ;
V_18 -> V_55 [ V_7 ] = F_18 ( 1 ,
V_18 -> V_55 [ V_7 ] ) ;
F_34 ( V_18 , F_55 ( V_7 ) , 0 ) ;
F_34 ( V_18 ,
F_57 ( V_7 ) ,
V_18 -> V_55 [ V_7 ] ) ;
}
}
}
V_18 -> V_110 [ 0 ] = 1 ;
V_18 -> V_110 [ 1 ] = 2 ;
V_18 -> V_110 [ 2 ] = 4 ;
if ( V_18 -> V_32 & V_33 )
V_18 -> V_118 = F_102 () ;
return 0 ;
}
static int F_101 ( int V_120 , struct V_17 * V_18 )
{
int V_83 = 0 , V_1 ;
V_91 V_22 ;
F_85 ( V_120 ) ;
V_1 = V_150 ? V_150 : F_87 ( V_120 , 0x20 ) ;
if ( ! ( V_1 == V_151 || V_1 == V_152 ||
V_1 == V_153 ) ) {
V_83 = - V_154 ;
goto exit;
}
F_88 ( V_120 , 0x07 , 0x0a ) ;
V_22 = ( F_87 ( V_120 , 0x60 ) << 8 ) |
F_87 ( V_120 , 0x61 ) ;
if ( ! V_22 ) {
V_83 = - V_154 ;
goto exit;
}
if ( ( F_33 ( V_22 + 0x43 ) & 0x0c ) == 0x08 )
V_18 -> V_32 |= F_49 ( 5 ) ;
if ( ( F_33 ( V_22 + 0x44 ) & 0x0c ) == 0x08 )
V_18 -> V_32 |= F_54 ( 5 ) ;
if ( ( F_33 ( V_22 + 0x45 ) & 0x0c ) == 0x08 )
V_18 -> V_32 |= F_49 ( 4 ) ;
if ( ( F_33 ( V_22 + 0x46 ) & 0x0c ) == 0x08 )
V_18 -> V_32 |= F_54 ( 4 ) ;
exit:
F_86 ( V_120 ) ;
return V_83 ;
}
static int F_103 ( struct V_19 * V_20 ,
struct V_155 * V_156 )
{
struct V_157 * V_158 = V_20 -> V_158 ;
struct V_23 * V_21 = & V_158 -> V_21 ;
T_1 V_159 , V_160 = 0 ;
const char * V_119 ;
if ( ! F_104 ( V_158 , V_161 ) )
return - V_154 ;
V_159 = F_30 ( V_20 , V_162 ) ;
V_160 = F_30 ( V_20 , V_163 ) ;
if ( V_159 == V_164 &&
V_160 == V_165 ) {
V_119 = L_35 ;
} else if ( V_159 == V_164 &&
( V_160 & V_166 ) == V_167 ) {
V_119 = L_36 ;
} else {
return - V_154 ;
}
F_97 ( V_21 , L_37 ,
V_160 == V_165 ? L_38 : L_39 ,
V_20 -> V_22 , V_160 ) ;
F_105 ( V_156 -> type , V_119 , V_168 ) ;
return 0 ;
}
static int F_106 ( struct V_19 * V_20 ,
const struct V_169 * V_170 )
{
struct V_17 * V_18 ;
struct V_23 * V_21 = & V_20 -> V_21 ;
int V_83 ;
V_18 = F_107 ( V_21 , sizeof( struct V_17 ) , V_171 ) ;
if ( ! V_18 )
return - V_172 ;
F_108 ( V_20 , V_18 ) ;
V_18 -> type = V_170 -> V_173 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_119 = V_20 -> V_119 ;
F_109 ( & V_18 -> V_25 ) ;
V_83 = F_98 ( V_21 ) ;
if ( V_83 ) {
F_100 ( V_21 , L_40 ) ;
return V_83 ;
}
V_83 = F_94 ( V_21 ) ;
if ( V_83 ) {
F_100 ( V_21 , L_41 ) ;
return V_83 ;
}
V_18 -> V_174 = F_110 ( V_21 ) ;
if ( F_111 ( V_18 -> V_174 ) ) {
F_100 ( V_21 , L_42 ) ;
V_83 = F_112 ( V_18 -> V_174 ) ;
goto V_138;
}
return 0 ;
V_138:
F_91 ( V_21 ) ;
return V_83 ;
}
static int F_113 ( struct V_19 * V_20 )
{
struct V_17 * V_18 = F_80 ( V_20 ) ;
F_114 ( V_18 -> V_174 ) ;
F_91 ( & V_20 -> V_21 ) ;
return 0 ;
}
static int T_6 F_115 ( int V_120 , unsigned short * V_22 )
{
int V_83 = 0 , V_1 ;
unsigned short V_175 ;
F_85 ( V_120 ) ;
V_1 = V_150 ? V_150 : F_87 ( V_120 , 0x20 ) ;
if ( ! ( V_1 == V_176 || V_1 == V_177 || V_1 == V_178 ||
V_1 == V_179 ) ) {
V_83 = - V_154 ;
goto exit;
}
F_88 ( V_120 , 0x07 , 0x0a ) ;
V_175 = ( F_87 ( V_120 , 0x60 ) << 8 ) |
F_87 ( V_120 , 0x61 ) ;
if ( ! V_175 ) {
F_116 ( L_43 ) ;
V_83 = - V_154 ;
goto exit;
}
* V_22 = V_175 + 0x70 ;
exit:
F_86 ( V_120 ) ;
return V_83 ;
}
static int T_6 F_117 ( unsigned short V_22 )
{
struct V_180 V_3 = {
. V_181 = V_22 ,
. V_182 = V_22 + V_183 - 1 ,
. V_119 = L_36 ,
. V_184 = V_185 ,
} ;
int V_83 ;
V_83 = F_118 ( & V_3 ) ;
if ( V_83 )
goto exit;
V_186 = F_119 ( L_36 , V_22 ) ;
if ( ! V_186 ) {
F_116 ( L_44 ) ;
V_83 = - V_172 ;
goto exit;
}
V_83 = F_120 ( V_186 , & V_3 , 1 ) ;
if ( V_83 ) {
F_116 ( L_45 , V_83 ) ;
goto V_187;
}
V_83 = F_121 ( V_186 ) ;
if ( V_83 ) {
F_116 ( L_46 , V_83 ) ;
goto V_187;
}
return 0 ;
V_187:
F_122 ( V_186 ) ;
V_186 = NULL ;
exit:
return V_83 ;
}
static int F_123 ( struct V_188 * V_186 )
{
T_1 V_159 , V_23 ;
struct V_180 * V_3 ;
struct V_17 * V_18 ;
struct V_23 * V_21 = & V_186 -> V_21 ;
int V_83 ;
V_3 = F_124 ( V_186 , V_185 , 0 ) ;
if ( ! F_125 ( V_21 , V_3 -> V_181 , V_183 , L_36 ) ) {
F_100 ( V_21 , L_47 ,
( unsigned short ) V_3 -> V_181 ,
( unsigned short ) V_3 -> V_181 + V_183 - 1 ) ;
return - V_189 ;
}
V_18 = F_107 ( V_21 , sizeof( struct V_17 ) , V_171 ) ;
if ( ! V_18 )
return - V_172 ;
V_18 -> V_22 = V_3 -> V_181 ;
F_126 ( V_186 , V_18 ) ;
switch ( V_150 ) {
case V_176 :
case V_177 :
case V_178 :
V_18 -> type = V_147 ;
break;
case V_179 :
V_18 -> type = V_60 ;
break;
default:
V_159 = F_29 ( V_18 , V_162 ) ;
V_23 = F_29 ( V_18 , V_190 ) ;
if ( ( V_159 == V_164 ) &&
( V_23 == V_191 ) ) {
V_18 -> type = V_147 ;
} else if ( ( V_159 == V_164 ) &&
( V_23 == V_192 ) ) {
V_18 -> type = V_60 ;
} else {
return - V_154 ;
}
}
if ( V_18 -> type == V_60 )
V_18 -> V_119 = L_48 ;
else
V_18 -> V_119 = L_49 ;
F_109 ( & V_18 -> V_25 ) ;
F_97 ( V_21 , L_50 ,
V_18 -> type == V_60 ? L_51 : L_52 , V_18 -> V_22 ) ;
V_83 = F_98 ( V_21 ) ;
if ( V_83 ) {
F_100 ( V_21 , L_40 ) ;
return V_83 ;
}
V_83 = F_94 ( V_21 ) ;
if ( V_83 ) {
F_100 ( V_21 , L_41 ) ;
return V_83 ;
}
V_18 -> V_174 = F_110 ( V_21 ) ;
if ( F_111 ( V_18 -> V_174 ) ) {
F_100 ( V_21 , L_42 ) ;
V_83 = F_112 ( V_18 -> V_174 ) ;
goto V_193;
}
return 0 ;
V_193:
F_91 ( V_21 ) ;
return V_83 ;
}
static int F_127 ( struct V_188 * V_186 )
{
struct V_17 * V_18 = F_128 ( V_186 ) ;
F_114 ( V_18 -> V_174 ) ;
F_91 ( & V_186 -> V_21 ) ;
return 0 ;
}
static int T_6 F_129 ( void )
{
int V_83 ;
unsigned short V_22 ;
V_83 = F_130 ( & V_194 ) ;
if ( V_83 )
goto exit;
if ( F_115 ( 0x2e , & V_22 ) &&
F_115 ( 0x4e , & V_22 ) &&
( ! V_195 ||
( F_115 ( 0x162e , & V_22 ) &&
F_115 ( 0x164e , & V_22 ) ) ) ) {
return 0 ;
}
V_83 = F_131 ( & V_196 ) ;
if ( V_83 )
goto V_197;
V_83 = F_117 ( V_22 ) ;
if ( V_83 )
goto V_198;
return 0 ;
V_198:
F_132 ( & V_196 ) ;
V_197:
F_133 ( & V_194 ) ;
exit:
return V_83 ;
}
static void T_7 F_134 ( void )
{
if ( V_186 ) {
F_135 ( V_186 ) ;
F_132 ( & V_196 ) ;
}
F_133 ( & V_194 ) ;
}

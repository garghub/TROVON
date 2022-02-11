static inline int F_1 ( int V_1 , int V_2 , int V_3 )
{
return ( V_1 * V_2 + ( 3 << ( V_3 - 3 ) ) ) / ( 3 << ( V_3 - 2 ) ) ;
}
static inline int F_2 ( long V_4 , int V_2 )
{
return F_3 ( ( V_4 * 192 + V_2 / 2 ) / V_2 , 0 , 255 ) ;
}
static inline int F_4 ( int V_1 , int V_3 )
{
return ( V_1 * 1000 ) >> ( V_3 - 8 ) ;
}
static inline int F_5 ( long V_4 )
{
return F_3 ( ( V_4 < 0 ? V_4 - 500 : V_4 + 500 ) / 1000 , - 128 , 127 ) ;
}
static inline int F_6 ( int V_1 )
{
return V_5 [ ( V_1 >> 4 ) & 0x0f ] ;
}
static int F_7 ( long V_4 , int V_1 )
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
static inline int F_9 ( long V_4 , int V_7 , int V_1 )
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
static inline int F_11 ( long V_4 , int V_9 )
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
static inline int F_14 ( long V_4 , int V_1 )
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
static int F_16 ( long V_4 )
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
static inline int F_20 ( long V_4 , int V_1 )
{
int V_13 = ( V_4 == 4 ) ? 2 : V_4 - 1 ;
return ( V_1 & 0x1f ) | ( ( V_13 & 0x07 ) << 5 ) ;
}
static inline int F_21 ( int V_1 )
{
return V_14 [ V_1 & 0x0f ] ;
}
static int F_22 ( long V_4 , int V_1 )
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
static int F_24 ( long V_4 , int V_7 , int V_1 )
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
static inline int F_26 ( long V_4 , int V_7 , int V_1 )
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
F_31 ( & V_20 -> V_21 ,
L_1 ,
V_1 , V_22 ) ;
}
} else {
F_32 ( V_1 , V_18 -> V_23 ) ;
V_4 = F_33 ( V_18 -> V_23 + 1 ) ;
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
F_31 ( & V_20 -> V_21 ,
L_2 ,
V_1 , V_22 ) ;
}
} else {
F_32 ( V_1 , V_18 -> V_23 ) ;
F_32 ( V_4 , V_18 -> V_23 + 1 ) ;
}
return V_3 ;
}
static struct V_17 * F_36 ( struct V_24 * V_21 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
int V_7 ;
T_1 V_25 [ 6 ] ;
F_38 ( & V_18 -> V_26 ) ;
if ( F_39 ( V_27 , V_18 -> V_28 + 600 * V_29 ) || ! V_18 -> V_30 ) {
F_34 ( V_18 , V_31 , F_29 ( V_18 ,
V_31 ) | 0x10 ) ;
V_18 -> V_28 = V_27 ;
}
if ( F_39 ( V_27 , V_18 -> V_32 + V_29 ) || ! V_18 -> V_30 ) {
if ( V_18 -> V_33 & V_34 ) {
V_18 -> V_35 = F_29 ( V_18 , V_36 ) &
0x3f ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_37 ) ; V_7 ++ ) {
if ( V_7 == 7 && ! ( V_18 -> V_33 & V_38 ) )
continue;
V_18 -> V_37 [ V_7 ] = F_29 ( V_18 ,
F_41 ( V_7 ) ) << 8 ;
V_18 -> V_39 [ V_7 ] = F_29 ( V_18 ,
F_42 ( V_7 ) ) ;
V_18 -> V_40 [ V_7 ] = F_29 ( V_18 ,
F_43 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_41 ) ; V_7 ++ ) {
V_18 -> V_41 [ V_7 ] = F_29 ( V_18 ,
F_44 ( V_7 ) ) << 8 ;
V_18 -> V_42 [ V_7 ] = F_29 ( V_18 ,
F_45 ( V_7 ) ) ;
V_18 -> V_43 [ V_7 ] = F_29 ( V_18 ,
F_46 ( V_7 ) ) ;
if ( V_18 -> V_33 & V_44 ) {
V_18 -> V_45 [ V_7 ] = F_29 ( V_18 ,
F_47 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_25 ) ; V_7 ++ ) {
if ( V_7 == 5 && ! ( V_18 -> V_33 & V_38 ) )
continue;
V_25 [ V_7 ] = F_29 ( V_18 ,
F_48 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_37 ) ; V_7 ++ ) {
if ( V_7 == 7 && ! ( V_18 -> V_33 & V_38 ) )
continue;
V_18 -> V_37 [ V_7 ] |= ( V_25 [ V_46 [ V_7 ] ] <<
V_47 [ V_7 ] ) & 0xf0 ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_41 ) ; V_7 ++ ) {
V_18 -> V_41 [ V_7 ] |= ( V_25 [ V_48 [ V_7 ] ] <<
V_49 [ V_7 ] ) & 0xf0 ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_50 ) ; V_7 ++ ) {
if ( ! ( V_18 -> V_33 & F_49 ( V_7 ) ) )
continue;
V_18 -> V_50 [ V_7 ] = F_29 ( V_18 ,
F_50 ( V_7 ) ) ;
V_18 -> V_50 [ V_7 ] |= F_29 ( V_18 ,
F_50 ( V_7 ) + 1 ) << 8 ;
V_18 -> V_51 [ V_7 ] = F_29 ( V_18 ,
F_51 ( V_7 ) ) ;
V_18 -> V_51 [ V_7 ] |= F_29 ( V_18 ,
F_51 ( V_7 ) + 1 ) << 8 ;
V_18 -> V_52 [ V_7 ] = F_29 ( V_18 ,
F_52 ( V_7 ) ) ;
if ( V_7 > 3 ) {
V_18 -> V_53 [ V_7 - 4 ] = F_29 ( V_18 ,
F_53 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_54 ) ; V_7 ++ ) {
if ( ! ( V_18 -> V_33 & F_54 ( V_7 ) ) )
continue;
V_18 -> V_54 [ V_7 ] = F_29 ( V_18 ,
F_55 ( V_7 ) ) ;
V_18 -> V_55 [ V_7 ] = F_29 ( V_18 ,
F_56 ( V_7 ) ) ;
if ( V_7 < 3 ) {
V_18 -> V_56 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
V_18 -> V_57 [ V_7 ] = F_29 ( V_18 ,
F_58 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_58 ) ; V_7 ++ ) {
V_18 -> V_58 [ V_7 ] = F_29 ( V_18 ,
F_59 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_59 ) ; V_7 ++ ) {
if ( ( V_7 == 2 ) && ! ( V_18 -> V_33 & V_60 ) )
continue;
if ( ( V_7 == 1 ) && ( V_18 -> type == V_61 ) ) {
V_18 -> V_59 [ 1 ] = F_29 ( V_18 ,
F_60 ( 2 ) ) ;
V_18 -> V_62 [ 1 ] = F_29 ( V_18 ,
F_61 ( 2 ) ) ;
} else {
V_18 -> V_59 [ V_7 ] = F_29 ( V_18 ,
F_60 ( V_7 ) ) ;
V_18 -> V_62 [ V_7 ] = F_29 ( V_18 ,
F_61 ( V_7 ) ) ;
}
}
if ( V_18 -> V_33 & V_63 ) {
for ( V_7 = 0 ; V_7 < F_40 ( V_18 -> V_64 ) ; V_7 ++ ) {
V_18 -> V_64 [ V_7 ] = F_29 ( V_18 ,
F_62 ( V_7 ) ) ;
}
}
V_18 -> V_65 = F_29 ( V_18 ,
V_66 ) ;
if ( V_18 -> V_65 & 0x80 ) {
V_18 -> V_65 |= F_29 ( V_18 ,
V_67 ) << 8 ;
V_18 -> V_65 |= F_29 ( V_18 ,
V_68 ) << 16 ;
}
if ( ! V_18 -> V_20 ) {
if ( V_18 -> V_65 & 0xff0000 )
F_34 ( V_18 , V_68 , 0xff ) ;
if ( V_18 -> V_65 & 0xff00 )
F_34 ( V_18 , V_67 , 0xff ) ;
if ( V_18 -> V_65 & 0xff )
F_34 ( V_18 , V_66 , 0xff ) ;
}
V_18 -> V_32 = V_27 ;
V_18 -> V_30 = 1 ;
}
F_63 ( & V_18 -> V_26 ) ;
return V_18 ;
}
static T_3 F_64 ( struct V_24 * V_21 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_77 :
V_3 = F_1 ( V_18 -> V_37 [ V_7 ] , V_18 -> V_78 [ V_7 ] , 16 ) ;
break;
case V_79 :
V_3 = F_1 ( V_18 -> V_39 [ V_7 ] , V_18 -> V_78 [ V_7 ] , 8 ) ;
break;
case V_80 :
V_3 = F_1 ( V_18 -> V_40 [ V_7 ] , V_18 -> V_78 [ V_7 ] , 8 ) ;
break;
case V_81 :
V_3 = ( V_18 -> V_65 >> V_82 [ V_7 ] ) & 0x01 ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_67 ( struct V_24 * V_21 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_68 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_38 ( & V_18 -> V_26 ) ;
switch ( V_75 ) {
case V_79 :
V_18 -> V_39 [ V_7 ] = F_2 ( V_4 , V_18 -> V_78 [ V_7 ] ) ;
F_34 ( V_18 , F_42 ( V_7 ) ,
V_18 -> V_39 [ V_7 ] ) ;
break;
case V_80 :
V_18 -> V_40 [ V_7 ] = F_2 ( V_4 , V_18 -> V_78 [ V_7 ] ) ;
F_34 ( V_18 , F_43 ( V_7 ) ,
V_18 -> V_40 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_3 , V_75 ) ;
}
F_63 ( & V_18 -> V_26 ) ;
return V_83 ;
}
static T_3 F_69 ( struct V_24 * V_21 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_85 :
V_3 = F_4 ( V_18 -> V_41 [ V_7 ] , 16 ) ;
break;
case V_86 :
V_3 = F_4 ( V_18 -> V_42 [ V_7 ] , 8 ) ;
break;
case V_87 :
V_3 = F_4 ( V_18 -> V_43 [ V_7 ] , 8 ) ;
break;
case V_88 :
V_3 = F_4 ( V_18 -> V_45 [ V_7 ] , 8 ) ;
break;
case V_89 :
V_3 = ( V_18 -> V_65 >> V_90 [ V_7 ] ) & 0x01 ;
break;
case V_91 :
V_3 = ( ( ( V_92 ) V_18 -> V_41 [ V_7 ] & 0xff00 ) == 0x8000 ) ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_70 ( struct V_24 * V_21 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_68 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_38 ( & V_18 -> V_26 ) ;
switch ( V_75 ) {
case V_86 :
V_18 -> V_42 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_45 ( V_7 ) ,
V_18 -> V_42 [ V_7 ] ) ;
break;
case V_87 :
V_18 -> V_43 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_46 ( V_7 ) ,
V_18 -> V_43 [ V_7 ] ) ;
break;
case V_88 :
V_18 -> V_45 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_47 ( V_7 ) ,
V_18 -> V_45 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_3 , V_75 ) ;
}
F_63 ( & V_18 -> V_26 ) ;
return V_83 ;
}
static T_3 F_71 ( struct V_24 * V_21 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_93 :
if ( ( V_7 == 1 ) && ( V_18 -> V_94 & 0x02 ) )
V_3 = 4 ;
else
V_3 = 1 << V_7 ;
break;
case V_95 :
V_3 = F_4 ( V_18 -> V_59 [ V_7 ] , 8 ) -
F_8 ( V_18 -> V_64 [ V_7 == 2 ] , V_7 ) ;
break;
case V_96 :
V_3 = F_4 ( V_18 -> V_59 [ V_7 ] , 8 ) ;
break;
case V_97 :
V_3 = F_4 ( V_18 -> V_59 [ V_7 ] , 8 ) +
F_6 ( V_18 -> V_55 [ V_7 ] ) ;
break;
case V_98 :
V_3 = F_4 ( V_18 -> V_62 [ V_7 ] , 8 ) ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_72 ( struct V_24 * V_21 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_68 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_38 ( & V_18 -> V_26 ) ;
switch ( V_75 ) {
case V_95 :
V_18 -> V_59 [ V_7 ] = F_29 ( V_18 ,
F_60 ( V_7 ) ) ;
V_18 -> V_64 [ V_7 == 2 ] = F_9 (
F_4 ( V_18 -> V_59 [ V_7 ] , 8 ) -
V_4 , V_7 , F_29 ( V_18 ,
F_62 ( V_7 == 2 ) ) ) ;
F_34 ( V_18 , F_62 ( V_7 == 2 ) ,
V_18 -> V_64 [ V_7 == 2 ] ) ;
break;
case V_96 :
V_18 -> V_59 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_60 ( V_7 ) ,
V_18 -> V_59 [ V_7 ] ) ;
break;
case V_97 :
V_18 -> V_59 [ V_7 ] = F_29 ( V_18 ,
F_60 ( V_7 ) ) ;
V_18 -> V_55 [ V_7 ] = F_7 ( V_4 -
F_4 ( V_18 -> V_59 [ V_7 ] , 8 ) ,
F_29 ( V_18 ,
F_56 ( V_7 ) ) ) ;
F_34 ( V_18 , F_56 ( V_7 ) ,
V_18 -> V_55 [ V_7 ] ) ;
break;
case V_98 :
V_18 -> V_62 [ V_7 ] = F_5 ( V_4 ) ;
F_34 ( V_18 , F_61 ( V_7 ) ,
V_18 -> V_62 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_3 , V_75 ) ;
}
F_63 ( & V_18 -> V_26 ) ;
return V_83 ;
}
static T_3 F_73 ( struct V_24 * V_21 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_99 :
V_3 = F_10 ( V_18 -> V_50 [ V_7 ] ,
V_7 < 4 ? 0 :
F_12 ( V_18 -> V_52 [ V_7 ] ) ) ;
break;
case V_100 :
V_3 = F_10 ( V_18 -> V_51 [ V_7 ] ,
V_7 < 4 ? 0 :
F_12 ( V_18 -> V_52 [ V_7 ] ) ) ;
break;
case V_101 :
V_3 = F_15 ( V_18 -> V_53 [ V_7 - 4 ] ) ;
break;
case V_102 :
V_3 = ( V_18 -> V_65 >> V_103 [ V_7 ] ) & 0x01 ;
break;
case V_104 :
V_3 = F_13 ( V_18 -> V_52 [ V_7 ] ) ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_74 ( struct V_24 * V_21 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_68 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_38 ( & V_18 -> V_26 ) ;
switch ( V_75 ) {
case V_100 :
if ( V_7 < 4 ) {
V_18 -> V_51 [ V_7 ] = F_11 ( V_4 , 0 ) ;
} else {
V_18 -> V_52 [ V_7 ] = F_29 ( V_18 ,
F_52 ( V_7 ) ) ;
V_18 -> V_51 [ V_7 ] = F_11 ( V_4 ,
F_12 ( V_18 -> V_52 [ V_7 ] ) ) ;
}
F_34 ( V_18 , F_51 ( V_7 ) ,
V_18 -> V_51 [ V_7 ] & 0xff ) ;
F_34 ( V_18 , F_51 ( V_7 ) + 1 ,
V_18 -> V_51 [ V_7 ] >> 8 ) ;
break;
case V_101 :
V_18 -> V_53 [ V_7 - 4 ] = F_16 ( V_4 ) ;
F_34 ( V_18 , F_53 ( V_7 ) ,
V_18 -> V_53 [ V_7 - 4 ] ) ;
break;
case V_104 :
if ( ! ( V_4 == 1 || V_4 == 2 || V_4 == 4 ) ) {
V_83 = - V_105 ;
F_31 ( V_21 ,
L_5 ,
V_4 ) ;
goto exit;
}
V_18 -> V_52 [ V_7 ] = F_14 ( V_4 , F_29 ( V_18 ,
F_52 ( V_7 ) ) ) ;
F_34 ( V_18 , F_52 ( V_7 ) ,
V_18 -> V_52 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_3 , V_75 ) ;
}
exit:
F_63 ( & V_18 -> V_26 ) ;
return V_83 ;
}
static T_3 F_75 ( struct V_24 * V_21 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_106 :
if ( F_17 ( V_18 -> V_56 [ V_7 ] ) == 0 )
V_3 = 255 ;
else
V_3 = V_18 -> V_54 [ V_7 ] ;
break;
case V_107 :
V_3 = F_21 ( V_18 -> V_55 [ V_7 ] ) ;
break;
case V_108 :
if ( V_7 >= 3 )
V_3 = 1 ;
else
V_3 = F_17 ( V_18 -> V_56 [ V_7 ] ) ;
break;
case V_109 :
V_3 = F_23 ( V_18 -> V_58 [ V_7 > 0 ] , V_7 ) ;
break;
case V_110 :
if ( F_17 ( V_18 -> V_56 [ V_7 ] ) == 2 )
V_3 = F_19 ( V_18 -> V_56 [ V_7 ] ) ;
else
V_3 = V_18 -> V_111 [ V_7 ] ;
break;
case V_112 :
if ( F_27 ( V_18 -> V_58 [ 0 ] , V_7 ) )
V_3 = V_18 -> V_57 [ V_7 ] ;
else
V_3 = 0 ;
break;
case V_113 :
V_3 = V_18 -> V_57 [ V_7 ] ;
break;
case V_114 :
V_3 = 255 ;
break;
default:
V_3 = 0 ;
F_66 ( V_21 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_76 ( struct V_24 * V_21 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_72
* V_73 = F_65 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_68 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_38 ( & V_18 -> V_26 ) ;
switch ( V_75 ) {
case V_106 :
V_18 -> V_54 [ V_7 ] = F_3 ( V_4 , 0 , 255 ) ;
F_34 ( V_18 , F_55 ( V_7 ) , V_18 -> V_54 [ V_7 ] ) ;
break;
case V_107 :
V_18 -> V_55 [ V_7 ] = F_22 ( V_4 , F_29 ( V_18 ,
F_56 ( V_7 ) ) ) ;
F_34 ( V_18 , F_56 ( V_7 ) ,
V_18 -> V_55 [ V_7 ] ) ;
break;
case V_108 :
if ( V_4 < 0 || V_4 > 2 ) {
V_83 = - V_105 ;
F_31 ( V_21 ,
L_6 ,
V_4 ) ;
goto exit;
}
V_18 -> V_56 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
if ( V_4 == F_17 ( V_18 -> V_56 [ V_7 ] ) ) {
goto exit;
}
if ( F_17 ( V_18 -> V_56 [ V_7 ] ) == 2 ) {
V_18 -> V_111 [ V_7 ] = F_19 (
V_18 -> V_56 [ V_7 ] ) ;
V_18 -> V_58 [ V_7 > 0 ] = F_29 ( V_18 ,
F_59 ( V_7 > 0 ) ) ;
V_18 -> V_115 &= ~ ( 1 << V_7 ) ;
if ( F_25 ( V_18 -> V_58 [ V_7 > 0 ] , V_7 ) ) {
V_18 -> V_115 |= ( 1 << V_7 ) ;
V_18 -> V_58 [ V_7 > 0 ] = F_26 ( 0 , V_7 ,
V_18 -> V_58 [ V_7 > 0 ] ) ;
F_34 ( V_18 ,
F_59 ( V_7 > 0 ) ,
V_18 -> V_58 [ V_7 > 0 ] ) ;
}
}
switch ( V_4 ) {
case 0 :
F_77 ( V_21 , V_116 [ V_7 ] ,
V_117 ) ;
V_18 -> V_56 [ V_7 ] = F_18 ( 0 ,
V_18 -> V_56 [ V_7 ] ) ;
F_34 ( V_18 , F_57 ( V_7 ) ,
V_18 -> V_56 [ V_7 ] ) ;
break;
case 1 :
V_18 -> V_56 [ V_7 ] = F_18 ( 1 ,
V_18 -> V_56 [ V_7 ] ) ;
F_34 ( V_18 , F_57 ( V_7 ) ,
V_18 -> V_56 [ V_7 ] ) ;
F_77 ( V_21 , V_116 [ V_7 ] ,
V_117 | V_118 ) ;
break;
case 2 :
F_77 ( V_21 , V_116 [ V_7 ] ,
V_117 ) ;
V_18 -> V_56 [ V_7 ] = F_20 (
V_18 -> V_111 [ V_7 ] ,
V_18 -> V_56 [ V_7 ] ) ;
F_34 ( V_18 , F_57 ( V_7 ) ,
V_18 -> V_56 [ V_7 ] ) ;
if ( V_18 -> V_115 & ( 1 << V_7 ) ) {
V_18 -> V_58 [ V_7 > 0 ] = F_26 ( 1 , V_7 ,
F_29 ( V_18 ,
F_59 ( V_7 > 0 ) ) ) ;
F_34 ( V_18 ,
F_59 ( V_7 > 0 ) ,
V_18 -> V_58 [ V_7 > 0 ] ) ;
}
break;
}
break;
case V_109 :
V_18 -> V_56 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
V_18 -> V_58 [ V_7 > 0 ] = F_29 ( V_18 ,
F_59 ( V_7 > 0 ) ) ;
if ( V_4 > 0 ) {
V_18 -> V_58 [ V_7 > 0 ] = F_24 ( V_4 , V_7 ,
V_18 -> V_58 [ V_7 > 0 ] ) ;
}
if ( F_17 ( V_18 -> V_56 [ V_7 ] ) == 2 ) {
V_18 -> V_58 [ V_7 > 0 ] = F_26 ( V_4 > 0 , V_7 ,
V_18 -> V_58 [ V_7 > 0 ] ) ;
}
F_34 ( V_18 , F_59 ( V_7 > 0 ) ,
V_18 -> V_58 [ V_7 > 0 ] ) ;
break;
case V_110 :
if ( ! ( V_4 == 1 || V_4 == 2 || V_4 == 4 ||
V_4 == 6 || V_4 == 7 ) ) {
V_83 = - V_105 ;
F_31 ( V_21 ,
L_7
L_8 , V_4 ) ;
goto exit;
}
V_18 -> V_56 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
if ( F_17 ( V_18 -> V_56 [ V_7 ] ) == 2 ) {
V_18 -> V_56 [ V_7 ] = F_20 ( V_4 ,
V_18 -> V_56 [ V_7 ] ) ;
F_34 ( V_18 , F_57 ( V_7 ) ,
V_18 -> V_56 [ V_7 ] ) ;
} else {
V_18 -> V_111 [ V_7 ] = V_4 ;
}
break;
case V_112 :
V_18 -> V_57 [ V_7 ] = F_29 ( V_18 ,
F_58 ( V_7 ) ) ;
if ( V_4 > ( ( V_18 -> V_57 [ V_7 ] + 1 ) / 2 ) ) {
V_18 -> V_58 [ 0 ] = F_28 ( 1 , V_7 ,
F_29 ( V_18 ,
F_59 ( 0 ) ) ) ;
} else {
V_18 -> V_58 [ 0 ] = F_28 ( 0 , V_7 ,
F_29 ( V_18 ,
F_59 ( 0 ) ) ) ;
}
F_34 ( V_18 , F_59 ( 0 ) ,
V_18 -> V_58 [ 0 ] ) ;
break;
case V_113 :
V_18 -> V_57 [ V_7 ] = F_3 ( V_4 , 0 , 255 ) ;
F_34 ( V_18 , F_58 ( V_7 ) ,
V_18 -> V_57 [ V_7 ] ) ;
break;
default:
F_66 ( V_21 , L_3 , V_75 ) ;
}
exit:
F_63 ( & V_18 -> V_26 ) ;
return V_83 ;
}
static T_3 F_78 ( struct V_24 * V_21 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_19 * V_20 = F_79 ( V_21 ) ;
struct V_17 * V_18 = F_80 ( V_20 ) ;
return sprintf ( V_71 , L_4 , V_18 -> V_119 ) ;
}
static T_3 F_81 ( struct V_24 * V_21 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
unsigned long V_4 ;
int V_84 ;
V_84 = F_82 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
if ( V_4 > 255 )
return - V_105 ;
V_18 -> V_119 = V_4 ;
return V_83 ;
}
static T_3 F_83 ( struct V_24 * V_21 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_17 * V_18 = F_36 ( V_21 ) ;
return sprintf ( V_71 , L_4 , F_84 ( V_18 -> V_35 , V_18 -> V_119 ) ) ;
}
static T_3 F_85 ( struct V_24 * V_21 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
return sprintf ( V_71 , L_9 , V_18 -> V_120 ) ;
}
static inline void F_86 ( int V_121 )
{
F_32 ( 0x55 , V_121 ) ;
}
static inline void F_87 ( int V_121 )
{
F_32 ( 0xaa , V_121 ) ;
}
static inline int F_88 ( int V_121 , int V_1 )
{
F_32 ( V_1 , V_121 ) ;
return F_33 ( V_121 + 1 ) ;
}
static inline void F_89 ( int V_121 , int V_1 , int V_4 )
{
F_32 ( V_1 , V_121 ) ;
F_32 ( V_4 , V_121 + 1 ) ;
}
static void F_77 ( struct V_24 * V_21 ,
struct V_122 * V_70 , T_5 V_123 )
{
if ( F_90 ( & V_21 -> V_124 , V_70 , V_123 ) ) {
F_31 ( V_21 , L_10 ,
V_70 -> V_120 ) ;
}
}
static void F_91 ( struct V_24 * V_21 ,
const struct V_125 * V_126 ,
T_5 V_123 )
{
struct V_122 * * V_70 ;
for ( V_70 = V_126 -> V_127 ; * V_70 ; V_70 ++ )
F_77 ( V_21 , * V_70 , V_123 ) ;
}
static void F_92 ( struct V_24 * V_21 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_40 ( V_128 ) ; V_7 ++ ) {
if ( V_18 -> V_33 & F_49 ( V_7 ) ) {
F_93 ( & V_21 -> V_124 ,
& V_128 [ V_7 ] ) ;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_129 ) ; V_7 ++ ) {
if ( V_18 -> V_33 & F_54 ( V_7 ) ) {
F_93 ( & V_21 -> V_124 ,
& V_129 [ V_7 ] ) ;
if ( ( V_18 -> V_33 & V_130 ) && V_7 < 3 ) {
F_94 ( & V_21 -> V_124 ,
V_131 [ V_7 ] ) ;
}
}
}
if ( V_18 -> V_33 & V_44 )
F_93 ( & V_21 -> V_124 , & V_132 ) ;
if ( V_18 -> V_33 & V_34 )
F_93 ( & V_21 -> V_124 , & V_133 ) ;
if ( V_18 -> V_33 & V_60 )
F_93 ( & V_21 -> V_124 , & V_134 ) ;
if ( V_18 -> V_33 & V_63 )
F_93 ( & V_21 -> V_124 , & V_135 ) ;
if ( V_18 -> V_33 & V_38 )
F_93 ( & V_21 -> V_124 , & V_136 ) ;
F_93 ( & V_21 -> V_124 , & V_137 ) ;
if ( ! V_18 -> V_20 )
F_94 ( & V_21 -> V_124 , & V_138 . V_70 ) ;
}
static int F_95 ( struct V_24 * V_21 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
int V_84 , V_7 ;
if ( ! V_18 -> V_20 ) {
V_84 = F_96 ( & V_21 -> V_124 , & V_138 . V_70 ) ;
if ( V_84 )
goto exit;
}
V_84 = F_97 ( & V_21 -> V_124 , & V_137 ) ;
if ( V_84 )
goto V_139;
if ( V_18 -> V_33 & V_44 ) {
V_84 = F_97 ( & V_21 -> V_124 ,
& V_132 ) ;
if ( V_84 )
goto V_139;
}
if ( V_18 -> V_33 & V_34 ) {
V_84 = F_97 ( & V_21 -> V_124 , & V_133 ) ;
if ( V_84 )
goto V_139;
}
if ( V_18 -> V_33 & V_60 ) {
V_84 = F_97 ( & V_21 -> V_124 , & V_134 ) ;
if ( V_84 )
goto V_139;
}
if ( V_18 -> V_33 & V_63 ) {
V_84 = F_97 ( & V_21 -> V_124 , & V_135 ) ;
if ( V_84 )
goto V_139;
}
if ( V_18 -> V_33 & V_38 ) {
V_84 = F_97 ( & V_21 -> V_124 , & V_136 ) ;
if ( V_84 )
goto V_139;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_128 ) ; V_7 ++ ) {
if ( V_18 -> V_33 & F_49 ( V_7 ) ) {
V_84 = F_97 ( & V_21 -> V_124 ,
& V_128 [ V_7 ] ) ;
if ( V_84 )
goto V_139;
}
}
for ( V_7 = 0 ; V_7 < F_40 ( V_129 ) ; V_7 ++ ) {
if ( V_18 -> V_33 & F_54 ( V_7 ) ) {
V_84 = F_97 ( & V_21 -> V_124 ,
& V_129 [ V_7 ] ) ;
if ( V_84 )
goto V_139;
if ( ( V_18 -> V_33 & V_130 ) && ( V_7 < 3 ) ) {
V_84 = F_96 ( & V_21 -> V_124 ,
V_131 [ V_7 ] ) ;
if ( V_84 )
goto V_139;
}
}
}
if ( V_18 -> V_140 & 0x02 ) {
F_98 ( V_21 ,
L_11 ) ;
} else {
F_91 ( V_21 , & V_141 ,
V_117 | V_118 ) ;
if ( V_18 -> V_33 & V_44 ) {
F_91 ( V_21 , & V_132 ,
V_117 | V_118 ) ;
}
if ( V_18 -> V_33 & V_60 ) {
F_91 ( V_21 , & V_142 ,
V_117 | V_118 ) ;
}
if ( V_18 -> V_33 & V_63 ) {
F_91 ( V_21 , & V_135 ,
V_117 | V_118 ) ;
}
for ( V_7 = 0 ; V_7 < F_40 ( V_143 ) ; V_7 ++ ) {
if ( V_18 -> V_33 & F_54 ( V_7 ) ) {
F_91 ( V_21 ,
& V_143 [ V_7 ] ,
V_117 | V_118 ) ;
if ( ( V_18 -> V_33 & V_130 ) &&
V_7 < 3 ) {
F_77 ( V_21 ,
V_131 [ V_7 ] ,
V_117 | V_118 ) ;
}
}
}
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
if ( ( V_18 -> V_33 & F_54 ( V_7 ) ) &&
( F_17 ( V_18 -> V_56 [ V_7 ] ) == 1 ) ) {
F_77 ( V_21 ,
V_116 [ V_7 ] ,
V_117 | V_118 ) ;
}
}
}
return 0 ;
V_139:
F_92 ( V_21 ) ;
exit:
return V_84 ;
}
static int F_99 ( struct V_24 * V_21 )
{
struct V_17 * V_18 = F_37 ( V_21 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
int V_7 ;
T_1 V_1 ;
V_18 -> V_78 = F_100 ( V_18 -> type ) ;
V_18 -> V_140 = F_29 ( V_18 , V_31 ) ;
if ( ! ( V_18 -> V_140 & 0x01 ) ) {
if ( ! V_144 ) {
F_101 ( V_21 ,
L_12 ) ;
return - V_145 ;
}
V_18 -> V_140 |= 0x01 ;
F_34 ( V_18 , V_31 , V_18 -> V_140 ) ;
}
if ( ! ( V_18 -> V_140 & 0x04 ) ) {
F_101 ( V_21 , L_13 ) ;
return - V_145 ;
}
if ( V_20 ) {
V_18 -> V_94 = F_29 ( V_18 , V_146 ) ;
if ( V_18 -> V_94 & 0x04 )
V_18 -> V_33 |= F_49 ( 2 ) ;
if ( V_20 -> V_23 == 0x2e )
V_18 -> V_33 |= F_49 ( 3 ) | F_54 ( 2 ) ;
if ( F_102 ( 0x2e , V_18 ) &&
F_102 ( 0x4e , V_18 ) ) {
F_31 ( V_21 ,
L_14 ) ;
}
}
V_18 -> V_33 |= F_49 ( 0 ) | F_49 ( 1 ) | F_54 ( 0 ) | F_54 ( 1 ) ;
switch ( V_18 -> type ) {
case V_147 :
V_18 -> V_33 |= V_44 | V_34 | V_60 |
V_63 | V_130 ;
break;
case V_148 :
V_18 -> V_33 |= V_44 | V_60 |
V_63 | V_130 | F_49 ( 2 ) | F_54 ( 2 ) ;
break;
case V_149 :
V_18 -> V_33 |= V_60 ;
break;
case V_61 :
V_18 -> V_33 |= F_49 ( 2 ) | F_54 ( 2 ) | V_38 ;
break;
default:
break;
}
F_98 ( V_21 ,
L_15 ,
( V_18 -> V_33 & F_54 ( 2 ) ) ? L_16 : L_17 ,
( V_18 -> V_33 & F_54 ( 4 ) ) ? L_16 : L_17 ,
( V_18 -> V_33 & F_54 ( 5 ) ) ? L_16 : L_17 ,
( V_18 -> V_33 & F_49 ( 2 ) ) ? L_16 : L_17 ,
( V_18 -> V_33 & F_49 ( 3 ) ) ? L_16 : L_17 ,
( V_18 -> V_33 & F_49 ( 4 ) ) ? L_16 : L_17 ,
( V_18 -> V_33 & F_49 ( 5 ) ) ? L_16 : L_17 ) ;
V_1 = F_29 ( V_18 , V_150 ) ;
if ( V_20 && V_1 != 0xa4 ) {
F_31 ( V_21 ,
L_18 ,
( V_1 & 0x03 ) + 1 , ( ( V_1 >> 2 ) & 0x03 ) + 1 ,
( ( V_1 >> 4 ) & 0x03 ) + 1 , ( ( V_1 >> 6 ) & 0x03 ) + 1 ,
V_22 ) ;
} else if ( ! V_20 && V_1 != 0x24 ) {
F_31 ( V_21 ,
L_19 ,
( V_1 & 0x03 ) + 1 , ( ( V_1 >> 2 ) & 0x03 ) + 1 ,
( ( V_1 >> 4 ) & 0x03 ) + 1 , V_22 ) ;
}
if ( ! ( V_18 -> V_140 & 0x02 ) ) {
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_18 -> V_56 [ V_7 ] = F_29 ( V_18 ,
F_57 ( V_7 ) ) ;
if ( ( V_18 -> V_33 & F_54 ( V_7 ) ) &&
( F_17 ( V_18 -> V_56 [ V_7 ] ) == - 1 ) ) {
F_98 ( V_21 ,
L_20 ,
V_7 + 1 ) ;
V_18 -> V_56 [ V_7 ] = F_18 ( 1 ,
V_18 -> V_56 [ V_7 ] ) ;
F_34 ( V_18 , F_55 ( V_7 ) , 0 ) ;
F_34 ( V_18 ,
F_57 ( V_7 ) ,
V_18 -> V_56 [ V_7 ] ) ;
}
}
}
V_18 -> V_111 [ 0 ] = 1 ;
V_18 -> V_111 [ 1 ] = 2 ;
V_18 -> V_111 [ 2 ] = 4 ;
if ( V_18 -> V_33 & V_34 )
V_18 -> V_119 = F_103 () ;
return 0 ;
}
static int F_102 ( int V_121 , struct V_17 * V_18 )
{
int V_84 = 0 , V_1 ;
V_92 V_23 ;
F_86 ( V_121 ) ;
V_1 = V_151 ? V_151 : F_88 ( V_121 , 0x20 ) ;
if ( ! ( V_1 == V_152 || V_1 == V_153 ||
V_1 == V_154 ) ) {
V_84 = - V_155 ;
goto exit;
}
F_89 ( V_121 , 0x07 , 0x0a ) ;
V_23 = ( F_88 ( V_121 , 0x60 ) << 8 ) |
F_88 ( V_121 , 0x61 ) ;
if ( ! V_23 ) {
V_84 = - V_155 ;
goto exit;
}
if ( ( F_33 ( V_23 + 0x43 ) & 0x0c ) == 0x08 )
V_18 -> V_33 |= F_49 ( 5 ) ;
if ( ( F_33 ( V_23 + 0x44 ) & 0x0c ) == 0x08 )
V_18 -> V_33 |= F_54 ( 5 ) ;
if ( ( F_33 ( V_23 + 0x45 ) & 0x0c ) == 0x08 )
V_18 -> V_33 |= F_49 ( 4 ) ;
if ( ( F_33 ( V_23 + 0x46 ) & 0x0c ) == 0x08 )
V_18 -> V_33 |= F_54 ( 4 ) ;
exit:
F_87 ( V_121 ) ;
return V_84 ;
}
static int F_104 ( struct V_19 * V_20 ,
struct V_156 * V_157 )
{
struct V_158 * V_159 = V_20 -> V_159 ;
struct V_24 * V_21 = & V_159 -> V_21 ;
T_1 V_160 , V_161 = 0 ;
const char * V_120 ;
if ( ! F_105 ( V_159 , V_162 ) )
return - V_155 ;
V_160 = F_30 ( V_20 , V_163 ) ;
V_161 = F_30 ( V_20 , V_164 ) ;
if ( V_160 == V_165 &&
V_161 == V_166 ) {
V_120 = L_21 ;
} else if ( V_160 == V_165 &&
( V_161 & V_167 ) == V_168 ) {
V_120 = L_22 ;
} else {
return - V_155 ;
}
F_98 ( V_21 , L_23 ,
V_161 == V_166 ? L_24 : L_25 ,
V_20 -> V_23 , V_161 ) ;
F_106 ( V_157 -> type , V_120 , V_169 ) ;
return 0 ;
}
static int F_107 ( struct V_19 * V_20 ,
const struct V_170 * V_171 )
{
struct V_17 * V_18 ;
struct V_24 * V_21 = & V_20 -> V_21 ;
int V_84 ;
V_18 = F_108 ( V_21 , sizeof( struct V_17 ) , V_172 ) ;
if ( ! V_18 )
return - V_173 ;
F_109 ( V_20 , V_18 ) ;
V_18 -> type = V_171 -> V_174 ;
V_18 -> V_20 = V_20 ;
V_18 -> V_120 = V_20 -> V_120 ;
F_110 ( & V_18 -> V_26 ) ;
V_84 = F_99 ( V_21 ) ;
if ( V_84 ) {
F_101 ( V_21 , L_26 ) ;
return V_84 ;
}
V_84 = F_95 ( V_21 ) ;
if ( V_84 ) {
F_101 ( V_21 , L_27 ) ;
return V_84 ;
}
V_18 -> V_175 = F_111 ( V_21 ) ;
if ( F_112 ( V_18 -> V_175 ) ) {
F_101 ( V_21 , L_28 ) ;
V_84 = F_113 ( V_18 -> V_175 ) ;
goto V_139;
}
return 0 ;
V_139:
F_92 ( V_21 ) ;
return V_84 ;
}
static int F_114 ( struct V_19 * V_20 )
{
struct V_17 * V_18 = F_80 ( V_20 ) ;
F_115 ( V_18 -> V_175 ) ;
F_92 ( & V_20 -> V_21 ) ;
return 0 ;
}
static int T_6 F_116 ( int V_121 , unsigned short * V_23 )
{
int V_84 = 0 , V_1 ;
unsigned short V_176 ;
F_86 ( V_121 ) ;
V_1 = V_151 ? V_151 : F_88 ( V_121 , 0x20 ) ;
if ( ! ( V_1 == V_177 || V_1 == V_178 || V_1 == V_179 ||
V_1 == V_180 ) ) {
V_84 = - V_155 ;
goto exit;
}
F_89 ( V_121 , 0x07 , 0x0a ) ;
V_176 = ( F_88 ( V_121 , 0x60 ) << 8 ) |
F_88 ( V_121 , 0x61 ) ;
if ( ! V_176 ) {
F_117 ( L_29 ) ;
V_84 = - V_155 ;
goto exit;
}
* V_23 = V_176 + 0x70 ;
exit:
F_87 ( V_121 ) ;
return V_84 ;
}
static int T_6 F_118 ( unsigned short V_23 )
{
struct V_181 V_3 = {
. V_182 = V_23 ,
. V_183 = V_23 + V_184 - 1 ,
. V_120 = L_22 ,
. V_185 = V_186 ,
} ;
int V_84 ;
V_84 = F_119 ( & V_3 ) ;
if ( V_84 )
goto exit;
V_187 = F_120 ( L_22 , V_23 ) ;
if ( ! V_187 ) {
F_117 ( L_30 ) ;
V_84 = - V_173 ;
goto exit;
}
V_84 = F_121 ( V_187 , & V_3 , 1 ) ;
if ( V_84 ) {
F_117 ( L_31 , V_84 ) ;
goto V_188;
}
V_84 = F_122 ( V_187 ) ;
if ( V_84 ) {
F_117 ( L_32 , V_84 ) ;
goto V_188;
}
return 0 ;
V_188:
F_123 ( V_187 ) ;
V_187 = NULL ;
exit:
return V_84 ;
}
static int F_124 ( struct V_189 * V_187 )
{
T_1 V_160 , V_24 ;
struct V_181 * V_3 ;
struct V_17 * V_18 ;
struct V_24 * V_21 = & V_187 -> V_21 ;
int V_84 ;
V_3 = F_125 ( V_187 , V_186 , 0 ) ;
if ( ! F_126 ( V_21 , V_3 -> V_182 , V_184 , L_22 ) ) {
F_101 ( V_21 , L_33 ,
( unsigned short ) V_3 -> V_182 ,
( unsigned short ) V_3 -> V_182 + V_184 - 1 ) ;
return - V_190 ;
}
V_18 = F_108 ( V_21 , sizeof( struct V_17 ) , V_172 ) ;
if ( ! V_18 )
return - V_173 ;
V_18 -> V_23 = V_3 -> V_182 ;
F_127 ( V_187 , V_18 ) ;
switch ( V_151 ) {
case V_177 :
case V_178 :
case V_179 :
V_18 -> type = V_148 ;
break;
case V_180 :
V_18 -> type = V_61 ;
break;
default:
V_160 = F_29 ( V_18 , V_163 ) ;
V_24 = F_29 ( V_18 , V_191 ) ;
if ( ( V_160 == V_165 ) &&
( V_24 == V_192 ) ) {
V_18 -> type = V_148 ;
} else if ( ( V_160 == V_165 ) &&
( V_24 == V_193 ) ) {
V_18 -> type = V_61 ;
} else {
return - V_155 ;
}
}
if ( V_18 -> type == V_61 )
V_18 -> V_120 = L_34 ;
else
V_18 -> V_120 = L_35 ;
F_110 ( & V_18 -> V_26 ) ;
F_98 ( V_21 , L_36 ,
V_18 -> type == V_61 ? L_37 : L_38 , V_18 -> V_23 ) ;
V_84 = F_99 ( V_21 ) ;
if ( V_84 ) {
F_101 ( V_21 , L_26 ) ;
return V_84 ;
}
V_84 = F_95 ( V_21 ) ;
if ( V_84 ) {
F_101 ( V_21 , L_27 ) ;
return V_84 ;
}
V_18 -> V_175 = F_111 ( V_21 ) ;
if ( F_112 ( V_18 -> V_175 ) ) {
F_101 ( V_21 , L_28 ) ;
V_84 = F_113 ( V_18 -> V_175 ) ;
goto V_194;
}
return 0 ;
V_194:
F_92 ( V_21 ) ;
return V_84 ;
}
static int F_128 ( struct V_189 * V_187 )
{
struct V_17 * V_18 = F_129 ( V_187 ) ;
F_115 ( V_18 -> V_175 ) ;
F_92 ( & V_187 -> V_21 ) ;
return 0 ;
}
static int T_6 F_130 ( void )
{
int V_84 ;
unsigned short V_23 ;
V_84 = F_131 ( & V_195 ) ;
if ( V_84 )
goto exit;
if ( F_116 ( 0x2e , & V_23 ) &&
F_116 ( 0x4e , & V_23 ) &&
( ! V_196 ||
( F_116 ( 0x162e , & V_23 ) &&
F_116 ( 0x164e , & V_23 ) ) ) ) {
return 0 ;
}
V_84 = F_132 ( & V_197 ) ;
if ( V_84 )
goto V_198;
V_84 = F_118 ( V_23 ) ;
if ( V_84 )
goto V_199;
return 0 ;
V_199:
F_133 ( & V_197 ) ;
V_198:
F_134 ( & V_195 ) ;
exit:
return V_84 ;
}
static void T_7 F_135 ( void )
{
if ( V_187 ) {
F_136 ( V_187 ) ;
F_133 ( & V_197 ) ;
}
F_134 ( & V_195 ) ;
}

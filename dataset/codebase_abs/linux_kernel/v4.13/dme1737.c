static inline int F_1 ( int V_1 , int V_2 , int V_3 )
{
return ( V_1 * V_2 + ( 3 << ( V_3 - 3 ) ) ) / ( 3 << ( V_3 - 2 ) ) ;
}
static inline int F_2 ( long V_4 , int V_2 )
{
V_4 = F_3 ( V_4 , 0 , 255 * V_2 / 192 ) ;
return F_4 ( V_4 * 192 , V_2 ) ;
}
static inline int F_5 ( int V_1 , int V_3 )
{
return ( V_1 * 1000 ) >> ( V_3 - 8 ) ;
}
static inline int F_6 ( long V_4 )
{
V_4 = F_3 ( V_4 , - 128000 , 127000 ) ;
return F_4 ( V_4 , 1000 ) ;
}
static inline int F_7 ( int V_1 )
{
return V_5 [ ( V_1 >> 4 ) & 0x0f ] ;
}
static int F_8 ( long V_4 , int V_1 )
{
int V_6 ;
for ( V_6 = 15 ; V_6 > 0 ; V_6 -- ) {
if ( V_4 > ( V_5 [ V_6 ] + V_5 [ V_6 - 1 ] + 1 ) / 2 )
break;
}
return ( V_1 & 0x0f ) | ( V_6 << 4 ) ;
}
static inline int F_9 ( int V_1 , int V_7 )
{
return ( ( ( V_7 == 1 ) ? V_1 : V_1 >> 4 ) & 0x0f ) * 1000 ;
}
static inline int F_10 ( int V_8 , long V_9 , int V_7 , int V_1 )
{
V_9 = F_3 ( V_9 , V_8 - 15000 , V_8 ) ;
V_9 = F_4 ( V_8 - V_9 , 1000 ) ;
return ( V_7 == 1 ) ? ( V_1 & 0xf0 ) | V_9 : ( V_1 & 0x0f ) | ( V_9 << 4 ) ;
}
static inline int F_11 ( int V_1 , int V_10 )
{
if ( V_10 )
return V_10 * V_1 ;
else
return ( V_1 == 0 || V_1 == 0xffff ) ? 0 : 90000 * 60 / V_1 ;
}
static inline int F_12 ( long V_4 , int V_10 )
{
if ( V_10 ) {
return F_3 ( V_4 / V_10 , 0 , 0xffff ) ;
} else {
return ( V_4 <= 0 ) ? 0xffff :
F_3 ( 90000 * 60 / V_4 , 0 , 0xfffe ) ;
}
}
static inline int F_13 ( int V_1 )
{
return ( V_1 & 0x20 ) ? 0 : 60 >> ( V_1 & 0x03 ) ;
}
static inline int F_14 ( int V_1 )
{
int V_11 = ( V_1 >> 1 ) & 0x03 ;
return ( V_11 > 0 ) ? 1 << ( V_11 - 1 ) : 0 ;
}
static inline int F_15 ( long V_4 , int V_1 )
{
int V_11 = ( V_4 == 4 ) ? 3 : V_4 ;
return ( V_1 & 0xf9 ) | ( V_11 << 1 ) ;
}
static int F_16 ( int V_1 )
{
int V_6 ;
for ( V_6 = 10 ; V_6 > 0 ; V_6 -- ) {
if ( V_1 == V_12 [ V_6 ] )
break;
}
return 1000 + V_6 * 500 ;
}
static int F_17 ( long V_4 )
{
int V_6 ;
for ( V_6 = 10 ; V_6 > 0 ; V_6 -- ) {
if ( V_4 > ( 1000 + ( V_6 - 1 ) * 500 ) )
break;
}
return V_12 [ V_6 ] ;
}
static inline int F_18 ( int V_1 )
{
static const int V_13 [] = { 2 , 2 , 2 , 0 , - 1 , 2 , 2 , 1 } ;
return V_13 [ ( V_1 >> 5 ) & 0x07 ] ;
}
static inline int F_19 ( int V_4 , int V_1 )
{
int V_13 = ( V_4 == 1 ) ? 7 : 3 ;
return ( V_1 & 0x1f ) | ( ( V_13 & 0x07 ) << 5 ) ;
}
static inline int F_20 ( int V_1 )
{
static const int V_14 [] = { 1 , 2 , 4 , 0 , 0 , 6 , 7 , 0 } ;
return V_14 [ ( V_1 >> 5 ) & 0x07 ] ;
}
static inline int F_21 ( long V_4 , int V_1 )
{
int V_14 = ( V_4 == 4 ) ? 2 : V_4 - 1 ;
return ( V_1 & 0x1f ) | ( ( V_14 & 0x07 ) << 5 ) ;
}
static inline int F_22 ( int V_1 )
{
return V_15 [ V_1 & 0x0f ] ;
}
static int F_23 ( long V_4 , int V_1 )
{
int V_6 ;
if ( V_4 > 27500 ) {
V_6 = 10 ;
} else if ( V_4 > 22500 ) {
V_6 = 11 ;
} else {
for ( V_6 = 9 ; V_6 > 0 ; V_6 -- ) {
if ( V_4 > ( V_15 [ V_6 ] + V_15 [ V_6 - 1 ] + 1 ) / 2 )
break;
}
}
return ( V_1 & 0xf0 ) | V_6 ;
}
static inline int F_24 ( int V_1 , int V_7 )
{
int V_16 = ( V_7 == 1 ) ? V_1 >> 4 : V_1 ;
return ( V_16 & 0x08 ) ? V_17 [ V_16 & 0x07 ] : 0 ;
}
static int F_25 ( long V_4 , int V_7 , int V_1 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < 7 ; V_6 ++ ) {
if ( V_4 > ( V_17 [ V_6 ] + V_17 [ V_6 + 1 ] + 1 ) / 2 )
break;
}
return ( V_7 == 1 ) ? ( V_1 & 0x8f ) | ( V_6 << 4 ) : ( V_1 & 0xf8 ) | V_6 ;
}
static inline int F_26 ( int V_1 , int V_7 )
{
return F_24 ( V_1 , V_7 ) ? 1 : 0 ;
}
static inline int F_27 ( long V_4 , int V_7 , int V_1 )
{
int V_13 = ( V_7 == 1 ) ? 0x80 : 0x08 ;
return V_4 ? V_1 | V_13 : V_1 & ~ V_13 ;
}
static inline int F_28 ( int V_1 , int V_7 )
{
return ( V_1 >> ( V_7 + 5 ) ) & 0x01 ;
}
static inline int F_29 ( int V_4 , int V_7 , int V_1 )
{
return ( V_1 & ~ ( 1 << ( V_7 + 5 ) ) ) | ( ( V_4 & 0x01 ) << ( V_7 + 5 ) ) ;
}
static T_1 F_30 ( const struct V_18 * V_19 , T_1 V_1 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
T_2 V_4 ;
if ( V_21 ) {
V_4 = F_31 ( V_21 , V_1 ) ;
if ( V_4 < 0 ) {
F_32 ( & V_21 -> V_22 ,
L_1 ,
V_1 , V_23 ) ;
}
} else {
F_33 ( V_1 , V_19 -> V_24 ) ;
V_4 = F_34 ( V_19 -> V_24 + 1 ) ;
}
return V_4 ;
}
static T_2 F_35 ( const struct V_18 * V_19 , T_1 V_1 , T_1 V_4 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
T_2 V_3 = 0 ;
if ( V_21 ) {
V_3 = F_36 ( V_21 , V_1 , V_4 ) ;
if ( V_3 < 0 ) {
F_32 ( & V_21 -> V_22 ,
L_2 ,
V_1 , V_23 ) ;
}
} else {
F_33 ( V_1 , V_19 -> V_24 ) ;
F_33 ( V_4 , V_19 -> V_24 + 1 ) ;
}
return V_3 ;
}
static struct V_18 * F_37 ( struct V_25 * V_22 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
int V_7 ;
T_1 V_26 [ 6 ] ;
F_39 ( & V_19 -> V_27 ) ;
if ( F_40 ( V_28 , V_19 -> V_29 + 600 * V_30 ) || ! V_19 -> V_31 ) {
F_35 ( V_19 , V_32 , F_30 ( V_19 ,
V_32 ) | 0x10 ) ;
V_19 -> V_29 = V_28 ;
}
if ( F_40 ( V_28 , V_19 -> V_33 + V_30 ) || ! V_19 -> V_31 ) {
if ( V_19 -> V_34 & V_35 ) {
V_19 -> V_36 = F_30 ( V_19 , V_37 ) &
0x3f ;
}
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_38 ) ; V_7 ++ ) {
if ( V_7 == 7 && ! ( V_19 -> V_34 & V_39 ) )
continue;
V_19 -> V_38 [ V_7 ] = F_30 ( V_19 ,
F_42 ( V_7 ) ) << 8 ;
V_19 -> V_40 [ V_7 ] = F_30 ( V_19 ,
F_43 ( V_7 ) ) ;
V_19 -> V_41 [ V_7 ] = F_30 ( V_19 ,
F_44 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_8 ) ; V_7 ++ ) {
V_19 -> V_8 [ V_7 ] = F_30 ( V_19 ,
F_45 ( V_7 ) ) << 8 ;
V_19 -> V_42 [ V_7 ] = F_30 ( V_19 ,
F_46 ( V_7 ) ) ;
V_19 -> V_43 [ V_7 ] = F_30 ( V_19 ,
F_47 ( V_7 ) ) ;
if ( V_19 -> V_34 & V_44 ) {
V_19 -> V_45 [ V_7 ] = F_30 ( V_19 ,
F_48 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_41 ( V_26 ) ; V_7 ++ ) {
if ( V_7 == 5 && ! ( V_19 -> V_34 & V_39 ) )
continue;
V_26 [ V_7 ] = F_30 ( V_19 ,
F_49 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_38 ) ; V_7 ++ ) {
if ( V_7 == 7 && ! ( V_19 -> V_34 & V_39 ) )
continue;
V_19 -> V_38 [ V_7 ] |= ( V_26 [ V_46 [ V_7 ] ] <<
V_47 [ V_7 ] ) & 0xf0 ;
}
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_8 ) ; V_7 ++ ) {
V_19 -> V_8 [ V_7 ] |= ( V_26 [ V_48 [ V_7 ] ] <<
V_49 [ V_7 ] ) & 0xf0 ;
}
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_50 ) ; V_7 ++ ) {
if ( ! ( V_19 -> V_34 & F_50 ( V_7 ) ) )
continue;
V_19 -> V_50 [ V_7 ] = F_30 ( V_19 ,
F_51 ( V_7 ) ) ;
V_19 -> V_50 [ V_7 ] |= F_30 ( V_19 ,
F_51 ( V_7 ) + 1 ) << 8 ;
V_19 -> V_51 [ V_7 ] = F_30 ( V_19 ,
F_52 ( V_7 ) ) ;
V_19 -> V_51 [ V_7 ] |= F_30 ( V_19 ,
F_52 ( V_7 ) + 1 ) << 8 ;
V_19 -> V_52 [ V_7 ] = F_30 ( V_19 ,
F_53 ( V_7 ) ) ;
if ( V_7 > 3 ) {
V_19 -> V_53 [ V_7 - 4 ] = F_30 ( V_19 ,
F_54 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_54 ) ; V_7 ++ ) {
if ( ! ( V_19 -> V_34 & F_55 ( V_7 ) ) )
continue;
V_19 -> V_54 [ V_7 ] = F_30 ( V_19 ,
F_56 ( V_7 ) ) ;
V_19 -> V_55 [ V_7 ] = F_30 ( V_19 ,
F_57 ( V_7 ) ) ;
if ( V_7 < 3 ) {
V_19 -> V_56 [ V_7 ] = F_30 ( V_19 ,
F_58 ( V_7 ) ) ;
V_19 -> V_57 [ V_7 ] = F_30 ( V_19 ,
F_59 ( V_7 ) ) ;
}
}
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_58 ) ; V_7 ++ ) {
V_19 -> V_58 [ V_7 ] = F_30 ( V_19 ,
F_60 ( V_7 ) ) ;
}
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_59 ) ; V_7 ++ ) {
if ( ( V_7 == 2 ) && ! ( V_19 -> V_34 & V_60 ) )
continue;
if ( ( V_7 == 1 ) && ( V_19 -> type == V_61 ) ) {
V_19 -> V_59 [ 1 ] = F_30 ( V_19 ,
F_61 ( 2 ) ) ;
V_19 -> V_62 [ 1 ] = F_30 ( V_19 ,
F_62 ( 2 ) ) ;
} else {
V_19 -> V_59 [ V_7 ] = F_30 ( V_19 ,
F_61 ( V_7 ) ) ;
V_19 -> V_62 [ V_7 ] = F_30 ( V_19 ,
F_62 ( V_7 ) ) ;
}
}
if ( V_19 -> V_34 & V_63 ) {
for ( V_7 = 0 ; V_7 < F_41 ( V_19 -> V_64 ) ; V_7 ++ ) {
V_19 -> V_64 [ V_7 ] = F_30 ( V_19 ,
F_63 ( V_7 ) ) ;
}
}
V_19 -> V_65 = F_30 ( V_19 ,
V_66 ) ;
if ( V_19 -> V_65 & 0x80 ) {
V_19 -> V_65 |= F_30 ( V_19 ,
V_67 ) << 8 ;
V_19 -> V_65 |= F_30 ( V_19 ,
V_68 ) << 16 ;
}
if ( ! V_19 -> V_21 ) {
if ( V_19 -> V_65 & 0xff0000 )
F_35 ( V_19 , V_68 , 0xff ) ;
if ( V_19 -> V_65 & 0xff00 )
F_35 ( V_19 , V_67 , 0xff ) ;
if ( V_19 -> V_65 & 0xff )
F_35 ( V_19 , V_66 , 0xff ) ;
}
V_19 -> V_33 = V_28 ;
V_19 -> V_31 = 1 ;
}
F_64 ( & V_19 -> V_27 ) ;
return V_19 ;
}
static T_3 F_65 ( struct V_25 * V_22 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_18 * V_19 = F_37 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_77 :
V_3 = F_1 ( V_19 -> V_38 [ V_7 ] , V_19 -> V_78 [ V_7 ] , 16 ) ;
break;
case V_79 :
V_3 = F_1 ( V_19 -> V_40 [ V_7 ] , V_19 -> V_78 [ V_7 ] , 8 ) ;
break;
case V_80 :
V_3 = F_1 ( V_19 -> V_41 [ V_7 ] , V_19 -> V_78 [ V_7 ] , 8 ) ;
break;
case V_81 :
V_3 = ( V_19 -> V_65 >> V_82 [ V_7 ] ) & 0x01 ;
break;
default:
V_3 = 0 ;
F_67 ( V_22 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_68 ( struct V_25 * V_22 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_69 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_39 ( & V_19 -> V_27 ) ;
switch ( V_75 ) {
case V_79 :
V_19 -> V_40 [ V_7 ] = F_2 ( V_4 , V_19 -> V_78 [ V_7 ] ) ;
F_35 ( V_19 , F_43 ( V_7 ) ,
V_19 -> V_40 [ V_7 ] ) ;
break;
case V_80 :
V_19 -> V_41 [ V_7 ] = F_2 ( V_4 , V_19 -> V_78 [ V_7 ] ) ;
F_35 ( V_19 , F_44 ( V_7 ) ,
V_19 -> V_41 [ V_7 ] ) ;
break;
default:
F_67 ( V_22 , L_3 , V_75 ) ;
}
F_64 ( & V_19 -> V_27 ) ;
return V_83 ;
}
static T_3 F_70 ( struct V_25 * V_22 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_18 * V_19 = F_37 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_85 :
V_3 = F_5 ( V_19 -> V_8 [ V_7 ] , 16 ) ;
break;
case V_86 :
V_3 = F_5 ( V_19 -> V_42 [ V_7 ] , 8 ) ;
break;
case V_87 :
V_3 = F_5 ( V_19 -> V_43 [ V_7 ] , 8 ) ;
break;
case V_88 :
V_3 = F_5 ( V_19 -> V_45 [ V_7 ] , 8 ) ;
break;
case V_89 :
V_3 = ( V_19 -> V_65 >> V_90 [ V_7 ] ) & 0x01 ;
break;
case V_91 :
V_3 = ( ( ( V_92 ) V_19 -> V_8 [ V_7 ] & 0xff00 ) == 0x8000 ) ;
break;
default:
V_3 = 0 ;
F_67 ( V_22 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_71 ( struct V_25 * V_22 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_69 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_39 ( & V_19 -> V_27 ) ;
switch ( V_75 ) {
case V_86 :
V_19 -> V_42 [ V_7 ] = F_6 ( V_4 ) ;
F_35 ( V_19 , F_46 ( V_7 ) ,
V_19 -> V_42 [ V_7 ] ) ;
break;
case V_87 :
V_19 -> V_43 [ V_7 ] = F_6 ( V_4 ) ;
F_35 ( V_19 , F_47 ( V_7 ) ,
V_19 -> V_43 [ V_7 ] ) ;
break;
case V_88 :
V_19 -> V_45 [ V_7 ] = F_6 ( V_4 ) ;
F_35 ( V_19 , F_48 ( V_7 ) ,
V_19 -> V_45 [ V_7 ] ) ;
break;
default:
F_67 ( V_22 , L_3 , V_75 ) ;
}
F_64 ( & V_19 -> V_27 ) ;
return V_83 ;
}
static T_3 F_72 ( struct V_25 * V_22 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_18 * V_19 = F_37 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_93 :
if ( ( V_7 == 1 ) && ( V_19 -> V_94 & 0x02 ) )
V_3 = 4 ;
else
V_3 = 1 << V_7 ;
break;
case V_95 :
V_3 = F_5 ( V_19 -> V_59 [ V_7 ] , 8 ) -
F_9 ( V_19 -> V_64 [ V_7 == 2 ] , V_7 ) ;
break;
case V_96 :
V_3 = F_5 ( V_19 -> V_59 [ V_7 ] , 8 ) ;
break;
case V_97 :
V_3 = F_5 ( V_19 -> V_59 [ V_7 ] , 8 ) +
F_7 ( V_19 -> V_55 [ V_7 ] ) ;
break;
case V_98 :
V_3 = F_5 ( V_19 -> V_62 [ V_7 ] , 8 ) ;
break;
default:
V_3 = 0 ;
F_67 ( V_22 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_73 ( struct V_25 * V_22 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_8 ;
int V_84 ;
T_1 V_1 ;
V_84 = F_69 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_39 ( & V_19 -> V_27 ) ;
switch ( V_75 ) {
case V_95 :
V_19 -> V_59 [ V_7 ] = F_30 ( V_19 ,
F_61 ( V_7 ) ) ;
V_8 = F_5 ( V_19 -> V_59 [ V_7 ] , 8 ) ;
V_1 = F_30 ( V_19 , F_63 ( V_7 == 2 ) ) ;
V_19 -> V_64 [ V_7 == 2 ] = F_10 ( V_8 , V_4 , V_7 , V_1 ) ;
F_35 ( V_19 , F_63 ( V_7 == 2 ) ,
V_19 -> V_64 [ V_7 == 2 ] ) ;
break;
case V_96 :
V_19 -> V_59 [ V_7 ] = F_6 ( V_4 ) ;
F_35 ( V_19 , F_61 ( V_7 ) ,
V_19 -> V_59 [ V_7 ] ) ;
break;
case V_97 :
V_19 -> V_59 [ V_7 ] = F_30 ( V_19 ,
F_61 ( V_7 ) ) ;
V_8 = F_5 ( V_19 -> V_59 [ V_7 ] , 8 ) ;
V_4 = F_3 ( V_4 , V_8 , V_8 + 80000 ) ;
V_1 = F_30 ( V_19 , F_57 ( V_7 ) ) ;
V_19 -> V_55 [ V_7 ] = F_8 ( V_4 - V_8 , V_1 ) ;
F_35 ( V_19 , F_57 ( V_7 ) ,
V_19 -> V_55 [ V_7 ] ) ;
break;
case V_98 :
V_19 -> V_62 [ V_7 ] = F_6 ( V_4 ) ;
F_35 ( V_19 , F_62 ( V_7 ) ,
V_19 -> V_62 [ V_7 ] ) ;
break;
default:
F_67 ( V_22 , L_3 , V_75 ) ;
}
F_64 ( & V_19 -> V_27 ) ;
return V_83 ;
}
static T_3 F_74 ( struct V_25 * V_22 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_18 * V_19 = F_37 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_99 :
V_3 = F_11 ( V_19 -> V_50 [ V_7 ] ,
V_7 < 4 ? 0 :
F_13 ( V_19 -> V_52 [ V_7 ] ) ) ;
break;
case V_100 :
V_3 = F_11 ( V_19 -> V_51 [ V_7 ] ,
V_7 < 4 ? 0 :
F_13 ( V_19 -> V_52 [ V_7 ] ) ) ;
break;
case V_101 :
V_3 = F_16 ( V_19 -> V_53 [ V_7 - 4 ] ) ;
break;
case V_102 :
V_3 = ( V_19 -> V_65 >> V_103 [ V_7 ] ) & 0x01 ;
break;
case V_104 :
V_3 = F_14 ( V_19 -> V_52 [ V_7 ] ) ;
break;
default:
V_3 = 0 ;
F_67 ( V_22 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_75 ( struct V_25 * V_22 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_69 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_39 ( & V_19 -> V_27 ) ;
switch ( V_75 ) {
case V_100 :
if ( V_7 < 4 ) {
V_19 -> V_51 [ V_7 ] = F_12 ( V_4 , 0 ) ;
} else {
V_19 -> V_52 [ V_7 ] = F_30 ( V_19 ,
F_53 ( V_7 ) ) ;
V_19 -> V_51 [ V_7 ] = F_12 ( V_4 ,
F_13 ( V_19 -> V_52 [ V_7 ] ) ) ;
}
F_35 ( V_19 , F_52 ( V_7 ) ,
V_19 -> V_51 [ V_7 ] & 0xff ) ;
F_35 ( V_19 , F_52 ( V_7 ) + 1 ,
V_19 -> V_51 [ V_7 ] >> 8 ) ;
break;
case V_101 :
V_19 -> V_53 [ V_7 - 4 ] = F_17 ( V_4 ) ;
F_35 ( V_19 , F_54 ( V_7 ) ,
V_19 -> V_53 [ V_7 - 4 ] ) ;
break;
case V_104 :
if ( ! ( V_4 == 1 || V_4 == 2 || V_4 == 4 ) ) {
V_83 = - V_105 ;
F_32 ( V_22 ,
L_5 ,
V_4 ) ;
goto exit;
}
V_19 -> V_52 [ V_7 ] = F_15 ( V_4 , F_30 ( V_19 ,
F_53 ( V_7 ) ) ) ;
F_35 ( V_19 , F_53 ( V_7 ) ,
V_19 -> V_52 [ V_7 ] ) ;
break;
default:
F_67 ( V_22 , L_3 , V_75 ) ;
}
exit:
F_64 ( & V_19 -> V_27 ) ;
return V_83 ;
}
static T_3 F_76 ( struct V_25 * V_22 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_18 * V_19 = F_37 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
int V_3 ;
switch ( V_75 ) {
case V_106 :
if ( F_18 ( V_19 -> V_56 [ V_7 ] ) == 0 )
V_3 = 255 ;
else
V_3 = V_19 -> V_54 [ V_7 ] ;
break;
case V_107 :
V_3 = F_22 ( V_19 -> V_55 [ V_7 ] ) ;
break;
case V_108 :
if ( V_7 >= 3 )
V_3 = 1 ;
else
V_3 = F_18 ( V_19 -> V_56 [ V_7 ] ) ;
break;
case V_109 :
V_3 = F_24 ( V_19 -> V_58 [ V_7 > 0 ] , V_7 ) ;
break;
case V_110 :
if ( F_18 ( V_19 -> V_56 [ V_7 ] ) == 2 )
V_3 = F_20 ( V_19 -> V_56 [ V_7 ] ) ;
else
V_3 = V_19 -> V_111 [ V_7 ] ;
break;
case V_112 :
if ( F_28 ( V_19 -> V_58 [ 0 ] , V_7 ) )
V_3 = V_19 -> V_57 [ V_7 ] ;
else
V_3 = 0 ;
break;
case V_113 :
V_3 = V_19 -> V_57 [ V_7 ] ;
break;
case V_114 :
V_3 = 255 ;
break;
default:
V_3 = 0 ;
F_67 ( V_22 , L_3 , V_75 ) ;
}
return sprintf ( V_71 , L_4 , V_3 ) ;
}
static T_3 F_77 ( struct V_25 * V_22 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
struct V_72
* V_73 = F_66 ( V_70 ) ;
int V_7 = V_73 -> V_74 ;
int V_75 = V_73 -> V_76 ;
long V_4 ;
int V_84 ;
V_84 = F_69 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
F_39 ( & V_19 -> V_27 ) ;
switch ( V_75 ) {
case V_106 :
V_19 -> V_54 [ V_7 ] = F_3 ( V_4 , 0 , 255 ) ;
F_35 ( V_19 , F_56 ( V_7 ) , V_19 -> V_54 [ V_7 ] ) ;
break;
case V_107 :
V_19 -> V_55 [ V_7 ] = F_23 ( V_4 , F_30 ( V_19 ,
F_57 ( V_7 ) ) ) ;
F_35 ( V_19 , F_57 ( V_7 ) ,
V_19 -> V_55 [ V_7 ] ) ;
break;
case V_108 :
if ( V_4 < 0 || V_4 > 2 ) {
V_83 = - V_105 ;
F_32 ( V_22 ,
L_6 ,
V_4 ) ;
goto exit;
}
V_19 -> V_56 [ V_7 ] = F_30 ( V_19 ,
F_58 ( V_7 ) ) ;
if ( V_4 == F_18 ( V_19 -> V_56 [ V_7 ] ) ) {
goto exit;
}
if ( F_18 ( V_19 -> V_56 [ V_7 ] ) == 2 ) {
V_19 -> V_111 [ V_7 ] = F_20 (
V_19 -> V_56 [ V_7 ] ) ;
V_19 -> V_58 [ V_7 > 0 ] = F_30 ( V_19 ,
F_60 ( V_7 > 0 ) ) ;
V_19 -> V_115 &= ~ ( 1 << V_7 ) ;
if ( F_26 ( V_19 -> V_58 [ V_7 > 0 ] , V_7 ) ) {
V_19 -> V_115 |= ( 1 << V_7 ) ;
V_19 -> V_58 [ V_7 > 0 ] = F_27 ( 0 , V_7 ,
V_19 -> V_58 [ V_7 > 0 ] ) ;
F_35 ( V_19 ,
F_60 ( V_7 > 0 ) ,
V_19 -> V_58 [ V_7 > 0 ] ) ;
}
}
switch ( V_4 ) {
case 0 :
F_78 ( V_22 , V_116 [ V_7 ] ,
V_117 ) ;
V_19 -> V_56 [ V_7 ] = F_19 ( 0 ,
V_19 -> V_56 [ V_7 ] ) ;
F_35 ( V_19 , F_58 ( V_7 ) ,
V_19 -> V_56 [ V_7 ] ) ;
break;
case 1 :
V_19 -> V_56 [ V_7 ] = F_19 ( 1 ,
V_19 -> V_56 [ V_7 ] ) ;
F_35 ( V_19 , F_58 ( V_7 ) ,
V_19 -> V_56 [ V_7 ] ) ;
F_78 ( V_22 , V_116 [ V_7 ] ,
V_117 | V_118 ) ;
break;
case 2 :
F_78 ( V_22 , V_116 [ V_7 ] ,
V_117 ) ;
V_19 -> V_56 [ V_7 ] = F_21 (
V_19 -> V_111 [ V_7 ] ,
V_19 -> V_56 [ V_7 ] ) ;
F_35 ( V_19 , F_58 ( V_7 ) ,
V_19 -> V_56 [ V_7 ] ) ;
if ( V_19 -> V_115 & ( 1 << V_7 ) ) {
V_19 -> V_58 [ V_7 > 0 ] = F_27 ( 1 , V_7 ,
F_30 ( V_19 ,
F_60 ( V_7 > 0 ) ) ) ;
F_35 ( V_19 ,
F_60 ( V_7 > 0 ) ,
V_19 -> V_58 [ V_7 > 0 ] ) ;
}
break;
}
break;
case V_109 :
V_19 -> V_56 [ V_7 ] = F_30 ( V_19 ,
F_58 ( V_7 ) ) ;
V_19 -> V_58 [ V_7 > 0 ] = F_30 ( V_19 ,
F_60 ( V_7 > 0 ) ) ;
if ( V_4 > 0 ) {
V_19 -> V_58 [ V_7 > 0 ] = F_25 ( V_4 , V_7 ,
V_19 -> V_58 [ V_7 > 0 ] ) ;
}
if ( F_18 ( V_19 -> V_56 [ V_7 ] ) == 2 ) {
V_19 -> V_58 [ V_7 > 0 ] = F_27 ( V_4 > 0 , V_7 ,
V_19 -> V_58 [ V_7 > 0 ] ) ;
}
F_35 ( V_19 , F_60 ( V_7 > 0 ) ,
V_19 -> V_58 [ V_7 > 0 ] ) ;
break;
case V_110 :
if ( ! ( V_4 == 1 || V_4 == 2 || V_4 == 4 ||
V_4 == 6 || V_4 == 7 ) ) {
V_83 = - V_105 ;
F_32 ( V_22 ,
L_7
L_8 , V_4 ) ;
goto exit;
}
V_19 -> V_56 [ V_7 ] = F_30 ( V_19 ,
F_58 ( V_7 ) ) ;
if ( F_18 ( V_19 -> V_56 [ V_7 ] ) == 2 ) {
V_19 -> V_56 [ V_7 ] = F_21 ( V_4 ,
V_19 -> V_56 [ V_7 ] ) ;
F_35 ( V_19 , F_58 ( V_7 ) ,
V_19 -> V_56 [ V_7 ] ) ;
} else {
V_19 -> V_111 [ V_7 ] = V_4 ;
}
break;
case V_112 :
V_19 -> V_57 [ V_7 ] = F_30 ( V_19 ,
F_59 ( V_7 ) ) ;
if ( V_4 > ( ( V_19 -> V_57 [ V_7 ] + 1 ) / 2 ) ) {
V_19 -> V_58 [ 0 ] = F_29 ( 1 , V_7 ,
F_30 ( V_19 ,
F_60 ( 0 ) ) ) ;
} else {
V_19 -> V_58 [ 0 ] = F_29 ( 0 , V_7 ,
F_30 ( V_19 ,
F_60 ( 0 ) ) ) ;
}
F_35 ( V_19 , F_60 ( 0 ) ,
V_19 -> V_58 [ 0 ] ) ;
break;
case V_113 :
V_19 -> V_57 [ V_7 ] = F_3 ( V_4 , 0 , 255 ) ;
F_35 ( V_19 , F_59 ( V_7 ) ,
V_19 -> V_57 [ V_7 ] ) ;
break;
default:
F_67 ( V_22 , L_3 , V_75 ) ;
}
exit:
F_64 ( & V_19 -> V_27 ) ;
return V_83 ;
}
static T_3 F_79 ( struct V_25 * V_22 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_20 * V_21 = F_80 ( V_22 ) ;
struct V_18 * V_19 = F_81 ( V_21 ) ;
return sprintf ( V_71 , L_4 , V_19 -> V_119 ) ;
}
static T_3 F_82 ( struct V_25 * V_22 , struct V_69 * V_70 ,
const char * V_71 , T_4 V_83 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
unsigned long V_4 ;
int V_84 ;
V_84 = F_83 ( V_71 , 10 , & V_4 ) ;
if ( V_84 )
return V_84 ;
if ( V_4 > 255 )
return - V_105 ;
V_19 -> V_119 = V_4 ;
return V_83 ;
}
static T_3 F_84 ( struct V_25 * V_22 ,
struct V_69 * V_70 , char * V_71 )
{
struct V_18 * V_19 = F_37 ( V_22 ) ;
return sprintf ( V_71 , L_4 , F_85 ( V_19 -> V_36 , V_19 -> V_119 ) ) ;
}
static T_3 F_86 ( struct V_25 * V_22 , struct V_69 * V_70 ,
char * V_71 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
return sprintf ( V_71 , L_9 , V_19 -> V_120 ) ;
}
static inline void F_87 ( int V_121 )
{
F_33 ( 0x55 , V_121 ) ;
}
static inline void F_88 ( int V_121 )
{
F_33 ( 0xaa , V_121 ) ;
}
static inline int F_89 ( int V_121 , int V_1 )
{
F_33 ( V_1 , V_121 ) ;
return F_34 ( V_121 + 1 ) ;
}
static inline void F_90 ( int V_121 , int V_1 , int V_4 )
{
F_33 ( V_1 , V_121 ) ;
F_33 ( V_4 , V_121 + 1 ) ;
}
static void F_78 ( struct V_25 * V_22 ,
struct V_122 * V_70 , T_5 V_123 )
{
if ( F_91 ( & V_22 -> V_124 , V_70 , V_123 ) ) {
F_32 ( V_22 , L_10 ,
V_70 -> V_120 ) ;
}
}
static void F_92 ( struct V_25 * V_22 ,
const struct V_125 * V_126 ,
T_5 V_123 )
{
struct V_122 * * V_70 ;
for ( V_70 = V_126 -> V_127 ; * V_70 ; V_70 ++ )
F_78 ( V_22 , * V_70 , V_123 ) ;
}
static void F_93 ( struct V_25 * V_22 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < F_41 ( V_128 ) ; V_7 ++ ) {
if ( V_19 -> V_34 & F_50 ( V_7 ) ) {
F_94 ( & V_22 -> V_124 ,
& V_128 [ V_7 ] ) ;
}
}
for ( V_7 = 0 ; V_7 < F_41 ( V_129 ) ; V_7 ++ ) {
if ( V_19 -> V_34 & F_55 ( V_7 ) ) {
F_94 ( & V_22 -> V_124 ,
& V_129 [ V_7 ] ) ;
if ( ( V_19 -> V_34 & V_130 ) && V_7 < 3 ) {
F_95 ( & V_22 -> V_124 ,
V_131 [ V_7 ] ) ;
}
}
}
if ( V_19 -> V_34 & V_44 )
F_94 ( & V_22 -> V_124 , & V_132 ) ;
if ( V_19 -> V_34 & V_35 )
F_94 ( & V_22 -> V_124 , & V_133 ) ;
if ( V_19 -> V_34 & V_60 )
F_94 ( & V_22 -> V_124 , & V_134 ) ;
if ( V_19 -> V_34 & V_63 )
F_94 ( & V_22 -> V_124 , & V_135 ) ;
if ( V_19 -> V_34 & V_39 )
F_94 ( & V_22 -> V_124 , & V_136 ) ;
F_94 ( & V_22 -> V_124 , & V_137 ) ;
if ( ! V_19 -> V_21 )
F_95 ( & V_22 -> V_124 , & V_138 . V_70 ) ;
}
static int F_96 ( struct V_25 * V_22 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
int V_84 , V_7 ;
if ( ! V_19 -> V_21 ) {
V_84 = F_97 ( & V_22 -> V_124 , & V_138 . V_70 ) ;
if ( V_84 )
goto exit;
}
V_84 = F_98 ( & V_22 -> V_124 , & V_137 ) ;
if ( V_84 )
goto V_139;
if ( V_19 -> V_34 & V_44 ) {
V_84 = F_98 ( & V_22 -> V_124 ,
& V_132 ) ;
if ( V_84 )
goto V_139;
}
if ( V_19 -> V_34 & V_35 ) {
V_84 = F_98 ( & V_22 -> V_124 , & V_133 ) ;
if ( V_84 )
goto V_139;
}
if ( V_19 -> V_34 & V_60 ) {
V_84 = F_98 ( & V_22 -> V_124 , & V_134 ) ;
if ( V_84 )
goto V_139;
}
if ( V_19 -> V_34 & V_63 ) {
V_84 = F_98 ( & V_22 -> V_124 , & V_135 ) ;
if ( V_84 )
goto V_139;
}
if ( V_19 -> V_34 & V_39 ) {
V_84 = F_98 ( & V_22 -> V_124 , & V_136 ) ;
if ( V_84 )
goto V_139;
}
for ( V_7 = 0 ; V_7 < F_41 ( V_128 ) ; V_7 ++ ) {
if ( V_19 -> V_34 & F_50 ( V_7 ) ) {
V_84 = F_98 ( & V_22 -> V_124 ,
& V_128 [ V_7 ] ) ;
if ( V_84 )
goto V_139;
}
}
for ( V_7 = 0 ; V_7 < F_41 ( V_129 ) ; V_7 ++ ) {
if ( V_19 -> V_34 & F_55 ( V_7 ) ) {
V_84 = F_98 ( & V_22 -> V_124 ,
& V_129 [ V_7 ] ) ;
if ( V_84 )
goto V_139;
if ( ( V_19 -> V_34 & V_130 ) && ( V_7 < 3 ) ) {
V_84 = F_97 ( & V_22 -> V_124 ,
V_131 [ V_7 ] ) ;
if ( V_84 )
goto V_139;
}
}
}
if ( V_19 -> V_140 & 0x02 ) {
F_99 ( V_22 ,
L_11 ) ;
} else {
F_92 ( V_22 , & V_141 ,
V_117 | V_118 ) ;
if ( V_19 -> V_34 & V_44 ) {
F_92 ( V_22 , & V_132 ,
V_117 | V_118 ) ;
}
if ( V_19 -> V_34 & V_60 ) {
F_92 ( V_22 , & V_142 ,
V_117 | V_118 ) ;
}
if ( V_19 -> V_34 & V_63 ) {
F_92 ( V_22 , & V_135 ,
V_117 | V_118 ) ;
}
for ( V_7 = 0 ; V_7 < F_41 ( V_143 ) ; V_7 ++ ) {
if ( V_19 -> V_34 & F_55 ( V_7 ) ) {
F_92 ( V_22 ,
& V_143 [ V_7 ] ,
V_117 | V_118 ) ;
if ( ( V_19 -> V_34 & V_130 ) &&
V_7 < 3 ) {
F_78 ( V_22 ,
V_131 [ V_7 ] ,
V_117 | V_118 ) ;
}
}
}
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
if ( ( V_19 -> V_34 & F_55 ( V_7 ) ) &&
( F_18 ( V_19 -> V_56 [ V_7 ] ) == 1 ) ) {
F_78 ( V_22 ,
V_116 [ V_7 ] ,
V_117 | V_118 ) ;
}
}
}
return 0 ;
V_139:
F_93 ( V_22 ) ;
exit:
return V_84 ;
}
static int F_100 ( struct V_25 * V_22 )
{
struct V_18 * V_19 = F_38 ( V_22 ) ;
struct V_20 * V_21 = V_19 -> V_21 ;
int V_7 ;
T_1 V_1 ;
V_19 -> V_78 = F_101 ( V_19 -> type ) ;
V_19 -> V_140 = F_30 ( V_19 , V_32 ) ;
if ( ! ( V_19 -> V_140 & 0x01 ) ) {
if ( ! V_144 ) {
F_102 ( V_22 ,
L_12 ) ;
return - V_145 ;
}
V_19 -> V_140 |= 0x01 ;
F_35 ( V_19 , V_32 , V_19 -> V_140 ) ;
}
if ( ! ( V_19 -> V_140 & 0x04 ) ) {
F_102 ( V_22 , L_13 ) ;
return - V_145 ;
}
if ( V_21 ) {
V_19 -> V_94 = F_30 ( V_19 , V_146 ) ;
if ( V_19 -> V_94 & 0x04 )
V_19 -> V_34 |= F_50 ( 2 ) ;
if ( V_21 -> V_24 == 0x2e )
V_19 -> V_34 |= F_50 ( 3 ) | F_55 ( 2 ) ;
if ( F_103 ( 0x2e , V_19 ) &&
F_103 ( 0x4e , V_19 ) ) {
F_32 ( V_22 ,
L_14 ) ;
}
}
V_19 -> V_34 |= F_50 ( 0 ) | F_50 ( 1 ) | F_55 ( 0 ) | F_55 ( 1 ) ;
switch ( V_19 -> type ) {
case V_147 :
V_19 -> V_34 |= V_44 | V_35 | V_60 |
V_63 | V_130 ;
break;
case V_148 :
V_19 -> V_34 |= V_44 | V_60 |
V_63 | V_130 | F_50 ( 2 ) | F_55 ( 2 ) ;
break;
case V_149 :
V_19 -> V_34 |= V_60 ;
break;
case V_61 :
V_19 -> V_34 |= F_50 ( 2 ) | F_55 ( 2 ) | V_39 ;
break;
default:
break;
}
F_99 ( V_22 ,
L_15 ,
( V_19 -> V_34 & F_55 ( 2 ) ) ? L_16 : L_17 ,
( V_19 -> V_34 & F_55 ( 4 ) ) ? L_16 : L_17 ,
( V_19 -> V_34 & F_55 ( 5 ) ) ? L_16 : L_17 ,
( V_19 -> V_34 & F_50 ( 2 ) ) ? L_16 : L_17 ,
( V_19 -> V_34 & F_50 ( 3 ) ) ? L_16 : L_17 ,
( V_19 -> V_34 & F_50 ( 4 ) ) ? L_16 : L_17 ,
( V_19 -> V_34 & F_50 ( 5 ) ) ? L_16 : L_17 ) ;
V_1 = F_30 ( V_19 , V_150 ) ;
if ( V_21 && V_1 != 0xa4 ) {
F_32 ( V_22 ,
L_18 ,
( V_1 & 0x03 ) + 1 , ( ( V_1 >> 2 ) & 0x03 ) + 1 ,
( ( V_1 >> 4 ) & 0x03 ) + 1 , ( ( V_1 >> 6 ) & 0x03 ) + 1 ,
V_23 ) ;
} else if ( ! V_21 && V_1 != 0x24 ) {
F_32 ( V_22 ,
L_19 ,
( V_1 & 0x03 ) + 1 , ( ( V_1 >> 2 ) & 0x03 ) + 1 ,
( ( V_1 >> 4 ) & 0x03 ) + 1 , V_23 ) ;
}
if ( ! ( V_19 -> V_140 & 0x02 ) ) {
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_19 -> V_56 [ V_7 ] = F_30 ( V_19 ,
F_58 ( V_7 ) ) ;
if ( ( V_19 -> V_34 & F_55 ( V_7 ) ) &&
( F_18 ( V_19 -> V_56 [ V_7 ] ) == - 1 ) ) {
F_99 ( V_22 ,
L_20 ,
V_7 + 1 ) ;
V_19 -> V_56 [ V_7 ] = F_19 ( 1 ,
V_19 -> V_56 [ V_7 ] ) ;
F_35 ( V_19 , F_56 ( V_7 ) , 0 ) ;
F_35 ( V_19 ,
F_58 ( V_7 ) ,
V_19 -> V_56 [ V_7 ] ) ;
}
}
}
V_19 -> V_111 [ 0 ] = 1 ;
V_19 -> V_111 [ 1 ] = 2 ;
V_19 -> V_111 [ 2 ] = 4 ;
if ( V_19 -> V_34 & V_35 )
V_19 -> V_119 = F_104 () ;
return 0 ;
}
static int F_103 ( int V_121 , struct V_18 * V_19 )
{
int V_84 = 0 , V_1 ;
V_92 V_24 ;
F_87 ( V_121 ) ;
V_1 = V_151 ? V_151 : F_89 ( V_121 , 0x20 ) ;
if ( ! ( V_1 == V_152 || V_1 == V_153 ||
V_1 == V_154 ) ) {
V_84 = - V_155 ;
goto exit;
}
F_90 ( V_121 , 0x07 , 0x0a ) ;
V_24 = ( F_89 ( V_121 , 0x60 ) << 8 ) |
F_89 ( V_121 , 0x61 ) ;
if ( ! V_24 ) {
V_84 = - V_155 ;
goto exit;
}
if ( ( F_34 ( V_24 + 0x43 ) & 0x0c ) == 0x08 )
V_19 -> V_34 |= F_50 ( 5 ) ;
if ( ( F_34 ( V_24 + 0x44 ) & 0x0c ) == 0x08 )
V_19 -> V_34 |= F_55 ( 5 ) ;
if ( ( F_34 ( V_24 + 0x45 ) & 0x0c ) == 0x08 )
V_19 -> V_34 |= F_50 ( 4 ) ;
if ( ( F_34 ( V_24 + 0x46 ) & 0x0c ) == 0x08 )
V_19 -> V_34 |= F_55 ( 4 ) ;
exit:
F_88 ( V_121 ) ;
return V_84 ;
}
static int F_105 ( struct V_20 * V_21 ,
struct V_156 * V_157 )
{
struct V_158 * V_159 = V_21 -> V_159 ;
struct V_25 * V_22 = & V_159 -> V_22 ;
T_1 V_160 , V_161 = 0 ;
const char * V_120 ;
if ( ! F_106 ( V_159 , V_162 ) )
return - V_155 ;
V_160 = F_31 ( V_21 , V_163 ) ;
V_161 = F_31 ( V_21 , V_164 ) ;
if ( V_160 == V_165 &&
V_161 == V_166 ) {
V_120 = L_21 ;
} else if ( V_160 == V_165 &&
( V_161 & V_167 ) == V_168 ) {
V_120 = L_22 ;
} else {
return - V_155 ;
}
F_99 ( V_22 , L_23 ,
V_161 == V_166 ? L_24 : L_25 ,
V_21 -> V_24 , V_161 ) ;
F_107 ( V_157 -> type , V_120 , V_169 ) ;
return 0 ;
}
static int F_108 ( struct V_20 * V_21 ,
const struct V_170 * V_171 )
{
struct V_18 * V_19 ;
struct V_25 * V_22 = & V_21 -> V_22 ;
int V_84 ;
V_19 = F_109 ( V_22 , sizeof( struct V_18 ) , V_172 ) ;
if ( ! V_19 )
return - V_173 ;
F_110 ( V_21 , V_19 ) ;
V_19 -> type = V_171 -> V_174 ;
V_19 -> V_21 = V_21 ;
V_19 -> V_120 = V_21 -> V_120 ;
F_111 ( & V_19 -> V_27 ) ;
V_84 = F_100 ( V_22 ) ;
if ( V_84 ) {
F_102 ( V_22 , L_26 ) ;
return V_84 ;
}
V_84 = F_96 ( V_22 ) ;
if ( V_84 ) {
F_102 ( V_22 , L_27 ) ;
return V_84 ;
}
V_19 -> V_175 = F_112 ( V_22 ) ;
if ( F_113 ( V_19 -> V_175 ) ) {
F_102 ( V_22 , L_28 ) ;
V_84 = F_114 ( V_19 -> V_175 ) ;
goto V_139;
}
return 0 ;
V_139:
F_93 ( V_22 ) ;
return V_84 ;
}
static int F_115 ( struct V_20 * V_21 )
{
struct V_18 * V_19 = F_81 ( V_21 ) ;
F_116 ( V_19 -> V_175 ) ;
F_93 ( & V_21 -> V_22 ) ;
return 0 ;
}
static int T_6 F_117 ( int V_121 , unsigned short * V_24 )
{
int V_84 = 0 , V_1 ;
unsigned short V_176 ;
F_87 ( V_121 ) ;
V_1 = V_151 ? V_151 : F_89 ( V_121 , 0x20 ) ;
if ( ! ( V_1 == V_177 || V_1 == V_178 || V_1 == V_179 ||
V_1 == V_180 ) ) {
V_84 = - V_155 ;
goto exit;
}
F_90 ( V_121 , 0x07 , 0x0a ) ;
V_176 = ( F_89 ( V_121 , 0x60 ) << 8 ) |
F_89 ( V_121 , 0x61 ) ;
if ( ! V_176 ) {
F_118 ( L_29 ) ;
V_84 = - V_155 ;
goto exit;
}
* V_24 = V_176 + 0x70 ;
exit:
F_88 ( V_121 ) ;
return V_84 ;
}
static int T_6 F_119 ( unsigned short V_24 )
{
struct V_181 V_3 = {
. V_182 = V_24 ,
. V_183 = V_24 + V_184 - 1 ,
. V_120 = L_22 ,
. V_185 = V_186 ,
} ;
int V_84 ;
V_84 = F_120 ( & V_3 ) ;
if ( V_84 )
goto exit;
V_187 = F_121 ( L_22 , V_24 ) ;
if ( ! V_187 ) {
F_118 ( L_30 ) ;
V_84 = - V_173 ;
goto exit;
}
V_84 = F_122 ( V_187 , & V_3 , 1 ) ;
if ( V_84 ) {
F_118 ( L_31 , V_84 ) ;
goto V_188;
}
V_84 = F_123 ( V_187 ) ;
if ( V_84 ) {
F_118 ( L_32 , V_84 ) ;
goto V_188;
}
return 0 ;
V_188:
F_124 ( V_187 ) ;
V_187 = NULL ;
exit:
return V_84 ;
}
static int F_125 ( struct V_189 * V_187 )
{
T_1 V_160 , V_25 ;
struct V_181 * V_3 ;
struct V_18 * V_19 ;
struct V_25 * V_22 = & V_187 -> V_22 ;
int V_84 ;
V_3 = F_126 ( V_187 , V_186 , 0 ) ;
if ( ! F_127 ( V_22 , V_3 -> V_182 , V_184 , L_22 ) ) {
F_102 ( V_22 , L_33 ,
( unsigned short ) V_3 -> V_182 ,
( unsigned short ) V_3 -> V_182 + V_184 - 1 ) ;
return - V_190 ;
}
V_19 = F_109 ( V_22 , sizeof( struct V_18 ) , V_172 ) ;
if ( ! V_19 )
return - V_173 ;
V_19 -> V_24 = V_3 -> V_182 ;
F_128 ( V_187 , V_19 ) ;
switch ( V_151 ) {
case V_177 :
case V_178 :
case V_179 :
V_19 -> type = V_148 ;
break;
case V_180 :
V_19 -> type = V_61 ;
break;
default:
V_160 = F_30 ( V_19 , V_163 ) ;
V_25 = F_30 ( V_19 , V_191 ) ;
if ( ( V_160 == V_165 ) &&
( V_25 == V_192 ) ) {
V_19 -> type = V_148 ;
} else if ( ( V_160 == V_165 ) &&
( V_25 == V_193 ) ) {
V_19 -> type = V_61 ;
} else {
return - V_155 ;
}
}
if ( V_19 -> type == V_61 )
V_19 -> V_120 = L_34 ;
else
V_19 -> V_120 = L_35 ;
F_111 ( & V_19 -> V_27 ) ;
F_99 ( V_22 , L_36 ,
V_19 -> type == V_61 ? L_37 : L_38 , V_19 -> V_24 ) ;
V_84 = F_100 ( V_22 ) ;
if ( V_84 ) {
F_102 ( V_22 , L_26 ) ;
return V_84 ;
}
V_84 = F_96 ( V_22 ) ;
if ( V_84 ) {
F_102 ( V_22 , L_27 ) ;
return V_84 ;
}
V_19 -> V_175 = F_112 ( V_22 ) ;
if ( F_113 ( V_19 -> V_175 ) ) {
F_102 ( V_22 , L_28 ) ;
V_84 = F_114 ( V_19 -> V_175 ) ;
goto V_194;
}
return 0 ;
V_194:
F_93 ( V_22 ) ;
return V_84 ;
}
static int F_129 ( struct V_189 * V_187 )
{
struct V_18 * V_19 = F_130 ( V_187 ) ;
F_116 ( V_19 -> V_175 ) ;
F_93 ( & V_187 -> V_22 ) ;
return 0 ;
}
static int T_6 F_131 ( void )
{
int V_84 ;
unsigned short V_24 ;
V_84 = F_132 ( & V_195 ) ;
if ( V_84 )
goto exit;
if ( F_117 ( 0x2e , & V_24 ) &&
F_117 ( 0x4e , & V_24 ) &&
( ! V_196 ||
( F_117 ( 0x162e , & V_24 ) &&
F_117 ( 0x164e , & V_24 ) ) ) ) {
return 0 ;
}
V_84 = F_133 ( & V_197 ) ;
if ( V_84 )
goto V_198;
V_84 = F_119 ( V_24 ) ;
if ( V_84 )
goto V_199;
return 0 ;
V_199:
F_134 ( & V_197 ) ;
V_198:
F_135 ( & V_195 ) ;
exit:
return V_84 ;
}
static void T_7 F_136 ( void )
{
if ( V_187 ) {
F_137 ( V_187 ) ;
F_134 ( & V_197 ) ;
}
F_135 ( & V_195 ) ;
}

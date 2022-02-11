static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
T_1 V_5 [ 4 ] ;
V_5 [ 0 ] = V_3 & 0xff ;
V_5 [ 1 ] = ( V_3 >> 8 ) & 0xff ;
V_5 [ 2 ] = ( V_3 >> 16 ) & 0xff ;
V_5 [ 3 ] = ( V_3 >> 24 ) & 0xff ;
if ( ! ( V_5 [ 0 ] & V_6 ) ) {
F_2 ( V_2 , L_1 ) ;
F_2 ( V_2 , L_2 ) ;
if ( ! ( V_5 [ 0 ] & V_7 ) ) {
F_2 ( V_2 , L_3 ) ;
} else {
F_2 ( V_2 , L_4 ) ;
}
F_2 ( V_2 , L_5 ) ;
switch ( V_5 [ 3 ] & V_8 ) {
case V_9 :
F_2 ( V_2 , L_6 ) ;
break;
case V_10 :
F_2 ( V_2 , L_7 ) ;
break;
case V_11 :
F_2 ( V_2 , L_8 ) ;
break;
default:
F_2 ( V_2 , L_9 ) ;
break;
}
F_2 ( V_2 , L_10 ) ;
if ( V_5 [ 0 ] & V_12 ) {
F_2 ( V_2 , L_11 ) ;
} else {
F_2 ( V_2 , L_12 ) ;
}
F_2 ( V_2 , L_13 ) ;
if ( ( V_5 [ 0 ] & V_13 ) != V_14 ) {
F_2 ( V_2 , L_14 ) ;
} else {
F_2 ( V_2 , L_15 ) ;
}
F_2 ( V_2 , L_16 ) ;
for ( V_4 = 0 ; V_4 < F_3 ( V_15 ) ; V_4 ++ ) {
if ( ( V_5 [ 1 ] & V_16 ) == V_15 [ V_4 ] . V_17 ) {
F_2 ( V_2 , L_17 , V_15 [ V_4 ] . V_18 ) ;
break;
}
}
if ( V_4 >= F_3 ( V_15 ) ) {
F_2 ( V_2 , L_18 , V_5 [ 1 ] & V_16 ) ;
}
F_2 ( V_2 , L_19 ) ;
if ( V_5 [ 1 ] & V_19 ) {
F_2 ( V_2 , L_20 ) ;
} else {
F_2 ( V_2 , L_21 ) ;
}
F_2 ( V_2 , L_22 ) ;
switch ( V_5 [ 3 ] & V_20 ) {
case V_21 :
F_2 ( V_2 , L_23 ) ;
break;
case V_22 :
F_2 ( V_2 , L_24 ) ;
break;
case V_23 :
F_2 ( V_2 , L_25 ) ;
break;
default:
F_2 ( V_2 , L_9 ) ;
break;
}
} else {
F_2 ( V_2 , L_26 ) ;
F_2 ( V_2 , L_2 ) ;
if ( ! ( V_5 [ 0 ] & V_7 ) ) {
F_2 ( V_2 , L_3 ) ;
} else {
F_2 ( V_2 , L_4 ) ;
}
F_2 ( V_2 , L_5 ) ;
switch ( V_5 [ 0 ] & V_24 ) {
case V_25 :
F_2 ( V_2 , L_6 ) ;
break;
case V_26 :
F_2 ( V_2 , L_7 ) ;
break;
case V_27 :
F_2 ( V_2 , L_8 ) ;
break;
default:
F_2 ( V_2 , L_9 ) ;
break;
}
F_2 ( V_2 , L_27 ) ;
if ( V_5 [ 0 ] & V_28 )
F_2 ( V_2 , L_28 ) ;
else
F_2 ( V_2 , L_29 ) ;
F_2 ( V_2 , L_13 ) ;
switch ( V_5 [ 0 ] & V_29 ) {
case V_30 :
F_2 ( V_2 , L_30 ) ;
break;
case V_31 :
F_2 ( V_2 , L_14 ) ;
break;
case V_32 :
F_2 ( V_2 , L_15 ) ;
break;
case V_33 :
default:
F_2 ( V_2 , L_9 ) ;
break;
}
F_2 ( V_2 , L_31 ) ;
if ( ( V_5 [ 1 ] & V_34 ) == V_35 ) {
F_2 ( V_2 , L_32 ) ;
} else {
F_2 ( V_2 , L_33 ) ;
}
F_2 ( V_2 , L_34 ) ;
switch ( V_5 [ 1 ] & V_36 ) {
case V_37 :
F_2 ( V_2 , L_35 ) ;
break;
case V_38 :
F_2 ( V_2 , L_36 ) ;
break;
default:
F_2 ( V_2 , L_9 ) ;
break;
}
F_2 ( V_2 , L_37 ) ;
switch ( V_5 [ 2 ] & V_39 ) {
case V_40 :
F_2 ( V_2 , L_38 ) ;
break;
case V_41 :
F_2 ( V_2 , L_39 ) ;
break;
case V_42 :
F_2 ( V_2 , L_40 ) ;
break;
default:
F_2 ( V_2 , L_9 ) ;
break;
}
F_2 ( V_2 , L_41 ) ;
switch ( V_5 [ 2 ] & V_43 ) {
case V_44 :
F_2 ( V_2 , L_42 ) ;
break;
case V_45 :
F_2 ( V_2 , L_43 ) ;
break;
case V_46 :
F_2 ( V_2 , L_44 ) ;
break;
case V_47 :
F_2 ( V_2 , L_45 ) ;
break;
default:
F_2 ( V_2 , L_9 ) ;
break;
}
}
}
static void F_4 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
T_1 V_3 ;
V_3 = F_5 ( V_51 , V_53 , 0 ) ;
F_2 ( V_2 , L_46 ,
( V_3 & 0x100000 ) ? L_47 : L_48 ,
( V_3 & 0x200000 ) ? L_49 : L_50 ,
( V_3 & 0x400000 ) ? L_51 : L_52 ) ;
F_2 ( V_2 , L_53 ,
( ( V_3 & 0xfffff ) * 48000 ) / 0x8000 ) ;
if ( V_3 & 0x200000 ) {
F_2 ( V_2 , L_54 ) ;
V_3 = F_5 ( V_51 , V_54 , 0 ) ;
F_1 ( V_2 , V_3 ) ;
}
F_2 ( V_2 , L_55 ) ;
}
static void F_6 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
unsigned long V_55 ;
char line [ 64 ] ;
T_1 V_56 , V_17 ;
while ( ! F_7 ( V_2 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_56 , & V_56 , & V_17 ) != 2 )
continue;
if ( V_56 < 0x40 && V_17 <= 0xffffffff ) {
F_8 ( & V_51 -> V_57 , V_55 ) ;
F_9 ( V_17 , V_51 -> V_58 + ( V_56 & 0xfffffffc ) ) ;
F_10 ( & V_51 -> V_57 , V_55 ) ;
}
}
}
static void F_11 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
unsigned long V_3 ;
unsigned long V_55 ;
int V_4 ;
F_2 ( V_2 , L_57 ) ;
for( V_4 = 0 ; V_4 < 0x20 ; V_4 += 4 ) {
F_8 ( & V_51 -> V_57 , V_55 ) ;
V_3 = F_12 ( V_51 -> V_58 + V_4 ) ;
F_10 ( & V_51 -> V_57 , V_55 ) ;
F_2 ( V_2 , L_58 , V_4 , V_3 ) ;
}
}
static void F_13 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
unsigned int V_3 ;
unsigned long V_55 ;
int V_4 ;
F_2 ( V_2 , L_57 ) ;
for( V_4 = 0 ; V_4 < 0x20 ; V_4 += 2 ) {
F_8 ( & V_51 -> V_57 , V_55 ) ;
V_3 = F_14 ( V_51 -> V_58 + V_4 ) ;
F_10 ( & V_51 -> V_57 , V_55 ) ;
F_2 ( V_2 , L_59 , V_4 , V_3 ) ;
}
}
static void F_15 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
unsigned int V_3 ;
unsigned long V_55 ;
int V_4 ;
F_2 ( V_2 , L_57 ) ;
for( V_4 = 0 ; V_4 < 0x20 ; V_4 += 1 ) {
F_8 ( & V_51 -> V_57 , V_55 ) ;
V_3 = F_16 ( V_51 -> V_58 + V_4 ) ;
F_10 ( & V_51 -> V_57 , V_55 ) ;
F_2 ( V_2 , L_60 , V_4 , V_3 ) ;
}
}
static void F_17 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
unsigned long V_3 ;
int V_4 , V_59 ;
F_2 ( V_2 , L_61 ) ;
for( V_4 = 0 ; V_4 < 0x40 ; V_4 ++ ) {
F_2 ( V_2 , L_62 , V_4 ) ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
V_3 = F_5 ( V_51 , V_4 , V_59 ) ;
F_2 ( V_2 , L_63 , V_3 ) ;
}
F_2 ( V_2 , L_55 ) ;
}
}
static void F_18 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
unsigned long V_3 ;
int V_4 , V_59 ;
F_2 ( V_2 , L_61 ) ;
for( V_4 = 0x40 ; V_4 < 0x80 ; V_4 ++ ) {
F_2 ( V_2 , L_62 , V_4 ) ;
for ( V_59 = 0 ; V_59 < 4 ; V_59 ++ ) {
V_3 = F_5 ( V_51 , V_4 , V_59 ) ;
F_2 ( V_2 , L_63 , V_3 ) ;
}
F_2 ( V_2 , L_55 ) ;
}
}
static void F_19 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
char line [ 64 ] ;
unsigned int V_56 , V_60 , V_17 ;
while ( ! F_7 ( V_2 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_64 , & V_56 , & V_60 , & V_17 ) != 3 )
continue;
if ( V_56 < 0x80 && V_17 <= 0xffffffff && V_60 <= 3 )
F_20 ( V_51 , V_56 , V_60 , V_17 ) ;
}
}
static void F_21 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 = V_49 -> V_52 ;
char line [ 64 ] ;
unsigned int V_56 , V_17 ;
while ( ! F_7 ( V_2 , line , sizeof( line ) ) ) {
if ( sscanf ( line , L_56 , & V_56 , & V_17 ) != 2 )
continue;
if ( ( V_56 <= 0x7f ) || ( V_17 <= 0x1ff ) ) {
F_22 ( V_51 , V_56 , V_17 ) ;
}
}
}
int F_23 ( struct V_50 * V_51 )
{
struct V_48 * V_49 ;
if( ! F_24 ( V_51 -> V_61 , L_65 , & V_49 ) )
F_25 ( V_49 , V_51 , F_4 ) ;
if( ! F_24 ( V_51 -> V_61 , L_66 , & V_49 ) ) {
F_25 ( V_49 , V_51 , F_11 ) ;
V_49 -> V_62 . V_63 . V_64 = F_6 ;
V_49 -> V_65 |= V_66 ;
}
if( ! F_24 ( V_51 -> V_61 , L_67 , & V_49 ) )
F_25 ( V_49 , V_51 , F_13 ) ;
if( ! F_24 ( V_51 -> V_61 , L_68 , & V_49 ) )
F_25 ( V_49 , V_51 , F_15 ) ;
if( ! F_24 ( V_51 -> V_61 , L_69 , & V_49 ) ) {
F_25 ( V_49 , V_51 , F_17 ) ;
V_49 -> V_62 . V_63 . V_64 = F_19 ;
V_49 -> V_65 |= V_66 ;
}
if( ! F_24 ( V_51 -> V_61 , L_70 , & V_49 ) ) {
V_49 -> V_62 . V_63 . V_64 = F_21 ;
V_49 -> V_52 = V_51 ;
V_49 -> V_65 |= V_66 ;
}
if( ! F_24 ( V_51 -> V_61 , L_71 , & V_49 ) )
F_25 ( V_49 , V_51 , F_18 ) ;
return 0 ;
}

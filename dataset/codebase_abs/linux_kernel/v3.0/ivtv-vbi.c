static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 V_5 ;
if ( ! ( V_2 -> V_6 & V_7 ) )
return;
V_5 . V_8 = V_9 ;
V_5 . V_10 = 0 ;
V_5 . line = V_3 ? 16 : 0 ;
V_5 . V_5 [ 2 ] = V_2 -> V_11 . V_12 . V_5 [ 0 ] ;
V_5 . V_5 [ 8 ] = V_2 -> V_11 . V_12 . V_5 [ 1 ] ;
V_5 . V_5 [ 9 ] = V_2 -> V_11 . V_12 . V_5 [ 2 ] ;
V_5 . V_5 [ 10 ] = V_2 -> V_11 . V_12 . V_5 [ 3 ] ;
V_5 . V_5 [ 11 ] = V_2 -> V_11 . V_12 . V_5 [ 4 ] ;
F_2 ( V_2 , V_13 , V_11 , V_14 , & V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_15 , const struct V_16 * V_17 )
{
struct V_4 V_5 ;
if ( ! ( V_2 -> V_6 & V_7 ) )
return;
V_5 . V_8 = V_18 ;
V_5 . V_10 = 0 ;
V_5 . line = ( V_15 & 1 ) ? 21 : 0 ;
V_5 . V_5 [ 0 ] = V_17 -> V_19 [ 0 ] ;
V_5 . V_5 [ 1 ] = V_17 -> V_19 [ 1 ] ;
F_2 ( V_2 , V_13 , V_11 , V_14 , & V_5 ) ;
V_5 . V_10 = 1 ;
V_5 . line = ( V_15 & 2 ) ? 21 : 0 ;
V_5 . V_5 [ 0 ] = V_17 -> V_20 [ 0 ] ;
V_5 . V_5 [ 1 ] = V_17 -> V_20 [ 1 ] ;
F_2 ( V_2 , V_13 , V_11 , V_14 , & V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 , int V_3 , int V_15 )
{
struct V_4 V_5 ;
if ( ! ( V_2 -> V_6 & V_7 ) )
return;
if ( ( V_2 -> V_21 & V_22 ) && ! V_3 ) {
V_3 = 1 ;
V_15 = 0x08 ;
}
V_5 . V_8 = V_23 ;
V_5 . V_10 = 0 ;
V_5 . line = V_3 ? 23 : 0 ;
V_5 . V_5 [ 0 ] = V_15 & 0xff ;
V_5 . V_5 [ 1 ] = ( V_15 >> 8 ) & 0xff ;
F_2 ( V_2 , V_13 , V_11 , V_14 , & V_5 ) ;
}
static int F_5 ( T_1 V_24 )
{
V_24 ^= ( V_24 >> 4 ) ;
V_24 ^= ( V_24 >> 2 ) ;
V_24 ^= ( V_24 >> 1 ) ;
return V_24 & 1 ;
}
static void F_6 ( struct V_1 * V_2 ,
const struct V_4 * V_25 ,
struct V_16 * V_17 , int * V_26 )
{
struct V_27 * V_28 = & V_2 -> V_11 ;
if ( V_25 -> V_8 == V_18 && V_25 -> line == 21 ) {
if ( V_25 -> V_10 ) {
V_17 -> V_20 [ 0 ] = V_25 -> V_5 [ 0 ] ;
V_17 -> V_20 [ 1 ] = V_25 -> V_5 [ 1 ] ;
} else {
V_17 -> V_19 [ 0 ] = V_25 -> V_5 [ 0 ] ;
V_17 -> V_19 [ 1 ] = V_25 -> V_5 [ 1 ] ;
}
* V_26 = 1 ;
} else if ( V_25 -> V_8 == V_9 && V_25 -> line == 16 && V_25 -> V_10 == 0 ) {
struct V_29 V_30 ;
V_30 . V_5 [ 0 ] = V_25 -> V_5 [ 2 ] ;
V_30 . V_5 [ 1 ] = V_25 -> V_5 [ 8 ] ;
V_30 . V_5 [ 2 ] = V_25 -> V_5 [ 9 ] ;
V_30 . V_5 [ 3 ] = V_25 -> V_5 [ 10 ] ;
V_30 . V_5 [ 4 ] = V_25 -> V_5 [ 11 ] ;
if ( memcmp ( & V_30 , & V_28 -> V_12 , sizeof( V_30 ) ) ) {
V_28 -> V_12 = V_30 ;
F_7 ( V_31 , & V_2 -> V_32 ) ;
}
} else if ( V_25 -> V_8 == V_23 &&
V_25 -> line == 23 && V_25 -> V_10 == 0 ) {
int V_33 = V_25 -> V_5 [ 0 ] | V_25 -> V_5 [ 1 ] << 8 ;
if ( V_28 -> V_34 != V_33 ) {
V_28 -> V_34 = V_33 ;
F_7 ( V_35 , & V_2 -> V_32 ) ;
}
}
}
static void F_8 ( struct V_1 * V_2 , const struct V_16 * V_17 )
{
struct V_27 * V_28 = & V_2 -> V_11 ;
if ( V_28 -> V_36 < F_9 ( V_28 -> V_37 ) ) {
memcpy ( & V_28 -> V_37 [ V_28 -> V_36 ] , V_17 ,
sizeof( struct V_16 ) ) ;
V_28 -> V_36 ++ ;
F_7 ( V_38 , & V_2 -> V_32 ) ;
}
}
static void F_10 ( struct V_1 * V_2 ,
const struct V_4 * V_39 ,
T_2 V_40 )
{
struct V_16 V_17 = { . V_19 = { 0x80 , 0x80 } , . V_20 = { 0x80 , 0x80 } } ;
int V_26 = 0 ;
T_2 V_41 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ )
F_6 ( V_2 , V_39 + V_41 , & V_17 , & V_26 ) ;
if ( V_26 )
F_8 ( V_2 , & V_17 ) ;
}
T_3
F_11 ( struct V_1 * V_2 ,
const struct V_4 T_4 * V_39 ,
T_2 V_40 )
{
struct V_16 V_17 = { . V_19 = { 0x80 , 0x80 } , . V_20 = { 0x80 , 0x80 } } ;
int V_26 = 0 ;
T_2 V_41 ;
struct V_4 V_25 ;
T_3 V_42 = V_40 * sizeof( struct V_4 ) ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
if ( F_12 ( & V_25 , V_39 + V_41 ,
sizeof( struct V_4 ) ) ) {
V_42 = - V_43 ;
break;
}
F_6 ( V_2 , & V_25 , & V_17 , & V_26 ) ;
}
if ( V_26 )
F_8 ( V_2 , & V_17 ) ;
return V_42 ;
}
static void F_13 ( struct V_1 * V_2 , int V_44 , T_5 V_45 )
{
int line = 0 ;
int V_41 ;
T_5 V_46 [ 2 ] = { 0 , 0 } ;
unsigned short V_47 ;
static const T_1 V_48 [] = {
0x00 , 0x00 , 0x01 , 0xba , 0x44 , 0x00 , 0x0c , 0x66 ,
0x24 , 0x01 , 0x01 , 0xd1 , 0xd3 , 0xfa , 0xff , 0xff ,
0x00 , 0x00 , 0x01 , 0xbd , 0x00 , 0x1a , 0x84 , 0x80 ,
0x07 , 0x21 , 0x00 , 0x5d , 0x63 , 0xa7 , 0xff , 0xff
} ;
const int V_49 = sizeof( V_48 ) ;
int V_50 = V_2 -> V_11 . V_51 % V_52 ;
T_1 * V_53 = & V_2 -> V_11 . V_54 [ V_50 ] [ 0 ] ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
int V_55 , V_56 ;
if ( V_2 -> V_11 . V_57 [ V_41 ] . V_8 == 0 )
continue;
V_56 = V_2 -> V_11 . V_57 [ V_41 ] . line - 6 ;
V_55 = V_2 -> V_11 . V_57 [ V_41 ] . V_10 ;
if ( V_55 )
V_56 += 18 ;
if ( V_56 < 32 )
V_46 [ 0 ] |= ( 1 << V_56 ) ;
else
V_46 [ 1 ] |= ( 1 << ( V_56 - 32 ) ) ;
V_53 [ V_49 + 12 + line * 43 ] =
F_14 ( V_2 -> V_11 . V_57 [ V_41 ] . V_8 ) ;
memcpy ( V_53 + V_49 + 12 + line * 43 + 1 , V_2 -> V_11 . V_57 [ V_41 ] . V_5 , 42 ) ;
line ++ ;
}
memcpy ( V_53 , V_48 , sizeof( V_48 ) ) ;
if ( line == 36 ) {
memcpy ( V_53 + V_49 , L_1 , 4 ) ;
memcpy ( V_53 + V_49 + 4 , V_53 + V_49 + 12 , line * 43 ) ;
V_47 = 4 + ( ( 43 * line + 3 ) & ~ 3 ) ;
} else {
memcpy ( V_53 + V_49 , L_2 , 4 ) ;
F_15 ( & V_46 [ 0 ] ) ;
F_15 ( & V_46 [ 1 ] ) ;
memcpy ( V_53 + V_49 + 4 , & V_46 [ 0 ] , 8 ) ;
V_47 = 12 + ( ( 43 * line + 3 ) & ~ 3 ) ;
}
V_53 [ 4 + 16 ] = ( V_47 + 10 ) >> 8 ;
V_53 [ 5 + 16 ] = ( V_47 + 10 ) & 0xff ;
V_53 [ 9 + 16 ] = 0x21 | ( ( V_45 >> 29 ) & 0x6 ) ;
V_53 [ 10 + 16 ] = ( V_45 >> 22 ) & 0xff ;
V_53 [ 11 + 16 ] = 1 | ( ( V_45 >> 14 ) & 0xff ) ;
V_53 [ 12 + 16 ] = ( V_45 >> 7 ) & 0xff ;
V_53 [ 13 + 16 ] = 1 | ( ( V_45 & 0x7f ) << 1 ) ;
V_2 -> V_11 . V_58 [ V_50 ] = V_49 + V_47 ;
}
static int F_16 ( struct V_1 * V_2 , T_1 * V_59 )
{
T_5 V_46 [ 2 ] ;
int V_41 , V_56 , V_60 ;
int line = 0 ;
if ( ! memcmp ( V_59 , L_2 , 4 ) ) {
memcpy ( V_46 , V_59 + 4 , 8 ) ;
V_59 += 12 ;
} else if ( ! memcmp ( V_59 , L_1 , 4 ) ) {
V_46 [ 0 ] = 0xffffffff ;
V_46 [ 1 ] = 0xf ;
V_59 += 4 ;
} else {
V_46 [ 0 ] = V_46 [ 1 ] = 0 ;
}
for ( V_41 = 0 ; V_41 < 36 ; V_41 ++ ) {
int V_61 = 0 ;
if ( V_41 < 32 && ! ( V_46 [ 0 ] & ( 1 << V_41 ) ) )
continue;
if ( V_41 >= 32 && ! ( V_46 [ 1 ] & ( 1 << ( V_41 - 32 ) ) ) )
continue;
V_60 = * V_59 & 0xf ;
switch ( V_60 ) {
case V_62 :
V_60 = V_63 ;
break;
case V_64 :
V_60 = V_18 ;
V_61 = ! F_5 ( V_59 [ 1 ] ) || ! F_5 ( V_59 [ 2 ] ) ;
break;
case V_65 :
V_60 = V_9 ;
break;
case V_66 :
V_60 = V_23 ;
break;
default:
V_60 = 0 ;
break;
}
if ( V_61 == 0 ) {
V_56 = ( V_41 < 18 ) ? V_41 + 6 : V_41 - 18 + 6 ;
V_2 -> V_11 . V_67 [ line ] . line = V_56 ;
V_2 -> V_11 . V_67 [ line ] . V_10 = V_41 >= 18 ;
V_2 -> V_11 . V_67 [ line ] . V_8 = V_60 ;
memcpy ( V_2 -> V_11 . V_67 [ line ] . V_5 , V_59 + 1 , 42 ) ;
line ++ ;
}
V_59 += 43 ;
}
while ( line < 36 ) {
V_2 -> V_11 . V_67 [ line ] . V_8 = 0 ;
V_2 -> V_11 . V_67 [ line ] . line = 0 ;
V_2 -> V_11 . V_67 [ line ] . V_10 = 0 ;
line ++ ;
}
return line * sizeof( V_2 -> V_11 . V_67 [ 0 ] ) ;
}
static T_5 F_17 ( struct V_1 * V_2 , T_1 * V_68 , T_5 V_47 )
{
T_5 V_69 = V_2 -> V_11 . V_70 ;
T_5 V_44 = V_2 -> V_11 . V_71 ;
T_1 V_72 = V_2 -> V_11 . V_73 ;
T_1 V_74 = V_2 -> V_11 . V_75 ;
T_1 * V_76 = V_68 ;
T_1 * V_59 ;
int V_41 ;
for ( V_41 = 0 ; V_41 < V_44 ; V_41 ++ ) {
V_59 = V_68 + V_41 * V_69 ;
if ( V_59 [ 0 ] != 0xff || V_59 [ 1 ] || V_59 [ 2 ] || ( V_59 [ 3 ] != V_72 && V_59 [ 3 ] != V_74 ) ) {
break;
}
memcpy ( V_76 , V_59 + 4 , V_69 - 4 ) ;
V_76 += V_69 - 4 ;
}
return V_44 * ( V_69 - 4 ) ;
}
static T_5 F_18 ( struct V_1 * V_2 , T_5 line , T_1 * V_68 , T_5 V_47 , T_1 V_77 )
{
T_5 V_69 = V_2 -> V_11 . V_78 ;
struct V_79 V_11 ;
int V_41 ;
unsigned V_44 = 0 ;
for ( V_41 = 0 ; V_41 < V_47 ; V_41 ++ , V_68 ++ ) {
if ( V_68 [ 0 ] == 0xff && ! V_68 [ 1 ] && ! V_68 [ 2 ] && V_68 [ 3 ] == V_77 )
break;
}
V_47 -= V_41 ;
if ( V_47 < V_69 ) {
return line ;
}
for ( V_41 = 0 ; V_41 < V_47 / V_69 ; V_41 ++ ) {
T_1 * V_59 = V_68 + V_41 * V_69 ;
if ( V_59 [ 0 ] != 0xff || V_59 [ 1 ] || V_59 [ 2 ] || V_59 [ 3 ] != V_77 ) {
continue;
}
V_11 . V_59 = V_59 + 4 ;
F_19 ( V_2 -> V_80 , V_11 , V_81 , & V_11 ) ;
if ( V_11 . type && ! ( V_44 & ( 1 << V_11 . line ) ) ) {
V_44 |= 1 << V_11 . line ;
V_2 -> V_11 . V_57 [ line ] . V_8 = V_11 . type ;
V_2 -> V_11 . V_57 [ line ] . V_10 = V_11 . V_82 ;
V_2 -> V_11 . V_57 [ line ] . line = V_11 . line ;
memcpy ( V_2 -> V_11 . V_57 [ line ] . V_5 , V_11 . V_59 , 42 ) ;
line ++ ;
}
}
return line ;
}
void F_20 ( struct V_1 * V_2 , struct V_83 * V_68 ,
T_6 V_45 , int V_84 )
{
T_1 * V_59 = ( T_1 * ) V_68 -> V_68 ;
T_5 V_47 = V_68 -> V_85 ;
int V_86 ;
if ( V_84 == V_87 && F_21 ( V_2 ) ) {
T_1 type ;
F_22 ( V_68 ) ;
type = V_59 [ 3 ] ;
V_47 = V_68 -> V_85 = F_17 ( V_2 , V_59 , V_47 ) ;
if ( type == V_2 -> V_11 . V_75 ) {
V_59 += V_47 - 4 ;
memcpy ( V_59 , & V_2 -> V_11 . V_51 , 4 ) ;
V_2 -> V_11 . V_51 ++ ;
}
return;
}
if ( V_84 == V_87 ) {
int V_44 ;
F_22 ( V_68 ) ;
V_44 = F_18 ( V_2 , 0 , V_59 , V_47 / 2 ,
V_2 -> V_11 . V_88 ) ;
V_44 = F_18 ( V_2 , V_44 , V_59 + V_47 / 2 - 32 , V_47 / 2 + 32 ,
V_2 -> V_11 . V_89 ) ;
if ( V_44 == 0 ) {
V_2 -> V_11 . V_57 [ 0 ] . V_8 = 0 ;
V_2 -> V_11 . V_57 [ 0 ] . line = 0 ;
V_2 -> V_11 . V_57 [ 0 ] . V_10 = 0 ;
V_44 = 1 ;
}
V_68 -> V_85 = V_47 = V_44 * sizeof( V_2 -> V_11 . V_57 [ 0 ] ) ;
memcpy ( V_59 , & V_2 -> V_11 . V_57 [ 0 ] , V_47 ) ;
if ( V_2 -> V_11 . V_90 ) {
F_13 ( V_2 , V_44 , V_45 ) ;
}
V_2 -> V_11 . V_51 ++ ;
return;
}
if ( V_84 == V_91 ) {
int V_92 = V_47 & 3 ;
int V_40 ;
if ( V_92 ) {
V_59 += 4 - V_92 ;
}
for ( V_86 = 0 ; V_86 < V_47 ; V_86 += 4 ) {
F_23 ( ( T_5 * ) ( V_59 + V_86 ) ) ;
}
V_40 = F_16 ( V_2 , V_59 + V_92 ) ;
memcpy ( V_68 -> V_68 , V_2 -> V_11 . V_67 , V_40 ) ;
V_68 -> V_85 = V_40 ;
F_10 ( V_2 , V_2 -> V_11 . V_67 ,
V_40 / sizeof( V_2 -> V_11 . V_67 [ 0 ] ) ) ;
return;
}
}
void F_24 ( struct V_1 * V_2 )
{
struct V_16 V_17 = { . V_19 = { 0x80 , 0x80 } , . V_20 = { 0x80 , 0x80 } } ;
F_25 ( V_38 , & V_2 -> V_32 ) ;
F_3 ( V_2 , 0 , & V_17 ) ;
V_2 -> V_11 . V_36 = 0 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = & V_2 -> V_11 ;
struct V_4 V_5 ;
struct V_16 V_17 = { . V_19 = { 0x80 , 0x80 } , . V_20 = { 0x80 , 0x80 } } ;
if ( V_2 -> V_93 == V_94 ) {
if ( V_2 -> V_95 ) {
V_5 . V_8 = V_23 ;
V_5 . V_10 = 0 ;
if ( F_19 ( V_2 -> V_80 , V_11 , V_96 , & V_5 ) == 0 ) {
F_4 ( V_2 , 1 , V_5 . V_5 [ 0 ] & 0xf ) ;
V_28 -> V_97 = 0 ;
} else if ( V_28 -> V_97 == 4 ) {
F_4 ( V_2 , 1 , 0x8 ) ;
} else {
V_28 -> V_97 ++ ;
}
}
else {
int V_15 = 0 ;
V_5 . V_8 = V_18 ;
V_5 . V_10 = 0 ;
if ( F_19 ( V_2 -> V_80 , V_11 , V_96 , & V_5 ) == 0 ) {
V_15 |= 1 ;
V_17 . V_19 [ 0 ] = V_5 . V_5 [ 0 ] ;
V_17 . V_19 [ 1 ] = V_5 . V_5 [ 1 ] ;
}
V_5 . V_10 = 1 ;
if ( F_19 ( V_2 -> V_80 , V_11 , V_96 , & V_5 ) == 0 ) {
V_15 |= 2 ;
V_17 . V_20 [ 0 ] = V_5 . V_5 [ 0 ] ;
V_17 . V_20 [ 1 ] = V_5 . V_5 [ 1 ] ;
}
if ( V_15 ) {
V_28 -> V_98 = 0 ;
F_3 ( V_2 , V_15 , & V_17 ) ;
} else if ( V_28 -> V_98 == 4 ) {
F_3 ( V_2 , 0 , & V_17 ) ;
} else {
V_28 -> V_98 ++ ;
}
}
return;
}
if ( F_27 ( V_35 , & V_2 -> V_32 ) ) {
F_4 ( V_2 , 1 , V_28 -> V_34 & 0xf ) ;
}
if ( F_28 ( V_38 , & V_2 -> V_32 ) ) {
if ( V_28 -> V_36 == 0 ) {
F_25 ( V_38 , & V_2 -> V_32 ) ;
F_3 ( V_2 , 3 , & V_17 ) ;
}
while ( V_28 -> V_36 ) {
V_17 = V_28 -> V_37 [ 0 ] ;
memcpy ( V_28 -> V_37 , V_28 -> V_37 + 1 ,
sizeof( V_28 -> V_37 ) - sizeof( V_28 -> V_37 [ 0 ] ) ) ;
V_28 -> V_36 -- ;
if ( V_28 -> V_36 && V_17 . V_19 [ 0 ] == 0x80 && V_17 . V_19 [ 1 ] == 0x80 )
continue;
F_3 ( V_2 , 3 , & V_17 ) ;
break;
}
}
if ( F_27 ( V_31 , & V_2 -> V_32 ) ) {
F_1 ( V_2 , 1 ) ;
}
}

void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_7 :
V_6 -> V_8 [ 0 ] = ( ( V_6 -> V_8 [ 0 ] & 0xfffff3ff ) | F_3 ( 10 ) | F_3 ( 11 ) ) ;
F_4 ( V_2 , V_9 , V_10 , V_11 , V_6 -> V_8 [ 0 ] ) ;
break;
case V_12 :
V_6 -> V_8 [ 0 ] = ( ( V_6 -> V_8 [ 0 ] & 0xfffff3ff ) | F_3 ( 10 ) ) ;
F_4 ( V_2 , V_9 , V_10 , V_11 , V_6 -> V_8 [ 0 ] ) ;
break;
default:
break;
}
}
void
F_5 (
struct V_1 * V_2 ,
T_1 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 = & V_6 -> V_16 ;
struct V_17 * V_18 = & V_2 -> V_19 ;
T_2 V_20 [ 2 ] = { 0 , 0 } , V_21 = 0 , V_22 ;
bool V_23 = false ;
T_1 V_24 , V_25 ;
T_1 * V_26 ;
T_1 V_27 ;
V_23 = true ;
if ( V_18 -> V_28 . V_29 == V_30 ) {
V_20 [ V_9 ] = 0x3f3f3f3f ;
V_20 [ V_31 ] = 0x3f3f3f3f ;
V_23 = true ;
if ( V_23 ) {
for ( V_24 = V_9 ; V_24 <= V_31 ; V_24 ++ ) {
V_20 [ V_24 ] =
V_13 [ V_24 ] | ( V_13 [ V_24 ] << 8 ) |
( V_13 [ V_24 ] << 16 ) | ( V_13 [ V_24 ] << 24 ) ;
if ( V_20 [ V_24 ] > 0x20 && V_6 -> V_32 )
V_20 [ V_24 ] = 0x20 ;
}
}
} else {
if ( V_15 -> V_33 == V_34 ) {
V_20 [ V_9 ] = 0x10101010 ;
V_20 [ V_31 ] = 0x10101010 ;
} else if ( V_15 -> V_33 == V_35 ) {
V_20 [ V_9 ] = 0x00000000 ;
V_20 [ V_31 ] = 0x00000000 ;
} else {
for ( V_24 = V_9 ; V_24 <= V_31 ; V_24 ++ ) {
V_20 [ V_24 ] =
V_13 [ V_24 ] | ( V_13 [ V_24 ] << 8 ) |
( V_13 [ V_24 ] << 16 ) | ( V_13 [ V_24 ] << 24 ) ;
}
if ( V_6 -> V_36 == 0 ) {
V_21 = ( V_6 -> V_37 [ 0 ] [ 6 ] ) +
( V_6 -> V_37 [ 0 ] [ 7 ] << 8 ) ;
V_20 [ V_9 ] += V_21 ;
V_21 = ( V_6 -> V_37 [ 0 ] [ 14 ] ) +
( V_6 -> V_37 [ 0 ] [ 15 ] << 24 ) ;
V_20 [ V_31 ] += V_21 ;
}
}
}
for ( V_24 = V_9 ; V_24 <= V_31 ; V_24 ++ ) {
V_26 = ( T_1 * ) ( & ( V_20 [ V_24 ] ) ) ;
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
if ( * V_26 > V_38 )
* V_26 = V_38 ;
V_26 ++ ;
}
}
F_6 ( & V_6 -> V_39 , 1 , & V_27 , & V_22 ) ;
if ( V_27 == 1 ) {
V_20 [ 0 ] += V_22 ;
V_20 [ 1 ] += V_22 ;
} else if ( V_27 == 2 ) {
V_20 [ 0 ] -= V_22 ;
V_20 [ 1 ] -= V_22 ;
}
V_21 = V_20 [ V_9 ] & 0xff ;
F_7 ( V_2 , V_40 , V_41 , V_21 ) ;
V_21 = V_20 [ V_9 ] >> 8 ;
F_7 ( V_2 , V_42 , 0xffffff00 , V_21 ) ;
V_21 = V_20 [ V_31 ] >> 24 ;
F_7 ( V_2 , V_42 , V_43 , V_21 ) ;
V_21 = V_20 [ V_31 ] & 0x00ffffff ;
F_7 ( V_2 , V_44 , 0xffffff00 , V_21 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 * V_45 ,
T_1 * V_46 , T_1 * V_47 , T_1 V_48 , T_2 * V_49 , T_2 * V_50 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_51 , V_52 ;
T_1 V_53 , V_54 [ 2 ] ;
for ( V_53 = 0 ; V_53 < 2 ; V_53 ++ ) {
V_51 = V_45 [ V_53 ] ;
V_51 = ( V_51 << 24 ) | ( V_51 << 16 ) | ( V_51 << 8 ) | V_51 ;
* ( V_49 + V_53 ) = V_51 ;
}
for ( V_53 = 0 ; V_53 < V_6 -> V_55 ; V_53 ++ ) {
if ( V_6 -> V_56 == V_7 )
V_54 [ V_53 ] = V_46 [ V_53 ] ;
else
V_54 [ V_53 ] = V_47 [ V_53 ] ;
V_52 = V_54 [ V_53 ] ;
V_52 = ( V_52 << 24 ) | ( V_52 << 16 ) | ( V_52 << 8 ) | V_52 ;
* ( V_50 + V_53 ) = V_52 ;
}
}
static void F_9 ( struct V_1 * V_2 , T_1 V_48 ,
T_1 V_57 , T_2 * V_51 , T_2 * V_52 ,
T_2 * V_58 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_14 * V_15 = & V_6 -> V_16 ;
T_1 V_53 , V_59 = 0 , V_60 [ 4 ] , V_61 ;
T_3 V_62 = 0 ;
T_2 V_63 , V_64 , V_65 ;
T_1 V_66 = V_6 -> V_36 ;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
switch ( V_66 ) {
case 0 :
V_59 = 0 ;
V_63 = V_6 -> V_37 [ V_59 ] [ V_57 + ( V_65 ? 8 : 0 ) ] +
( ( V_57 < 2 ) ? V_51 [ V_65 ] : V_52 [ V_65 ] ) ;
break;
case 1 :
if ( V_6 -> V_67 == 1 )
V_59 = 0 ;
if ( V_6 -> V_67 >= V_6 -> V_68 ) {
if ( V_48 < 3 )
V_59 = 0 ;
else if ( V_48 < 6 )
V_59 = 1 ;
else if ( V_48 < 9 )
V_59 = 2 ;
else if ( V_48 < 12 )
V_59 = 3 ;
else if ( V_48 < 14 )
V_59 = 4 ;
else if ( V_48 == 14 )
V_59 = 5 ;
}
V_63 = V_6 -> V_37 [ V_59 ] [ V_57 + ( V_65 ? 8 : 0 ) ] +
( ( V_57 < 2 ) ? V_51 [ V_65 ] : V_52 [ V_65 ] ) ;
break;
case 2 :
V_63 = ( ( V_57 < 2 ) ? V_51 [ V_65 ] : V_52 [ V_65 ] ) ;
break;
case 3 :
V_59 = 0 ;
if ( V_57 < 2 )
V_62 = V_6 -> V_69 [ V_65 ] [ V_48 - 1 ] ;
else if ( V_6 -> V_56 == V_7 )
V_62 = V_6 -> V_70 [ V_65 ] [ V_48 - 1 ] ;
if ( V_6 -> V_56 == V_12 )
V_61 = V_6 -> V_71 [ V_65 ] [ V_48 - 1 ] ;
else
V_61 = V_6 -> V_72 [ V_65 ] [ V_48 - 1 ] ;
if ( V_62 >= V_61 )
V_62 = 0 ;
else
V_62 = V_61 - V_62 ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
V_60 [ V_53 ] = ( T_1 ) ( ( V_6 -> V_37 [ V_59 ] [ V_57 + ( V_65 ? 8 : 0 ) ] & ( 0x7f << ( V_53 * 8 ) ) ) >> ( V_53 * 8 ) ) ;
if ( V_60 [ V_53 ] > V_62 )
V_60 [ V_53 ] = V_62 ;
}
V_64 = ( V_60 [ 3 ] << 24 ) | ( V_60 [ 2 ] << 16 ) |
( V_60 [ 1 ] << 8 ) | ( V_60 [ 0 ] ) ;
V_63 = V_64 + ( ( V_57 < 2 ) ? V_51 [ V_65 ] : V_52 [ V_65 ] ) ;
break;
default:
V_59 = 0 ;
V_63 = V_6 -> V_37 [ V_59 ] [ V_57 + ( V_65 ? 8 : 0 ) ] +
( ( V_57 < 2 ) ? V_51 [ V_65 ] : V_52 [ V_65 ] ) ;
break;
}
if ( V_15 -> V_33 == V_34 )
V_63 = 0x14141414 ;
else if ( V_15 -> V_33 == V_35 )
V_63 = 0x00000000 ;
if ( V_15 -> V_33 == V_73 )
V_63 = V_63 - 0x06060606 ;
else if ( V_15 -> V_33 == V_74 )
V_63 = V_63 ;
* ( V_58 + V_65 ) = V_63 ;
}
}
static void F_10 ( struct V_1 * V_2 , T_1 V_57 , T_2 * V_75 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_76 [ 6 ] = {
V_77 , V_78 ,
V_79 , V_80 ,
V_81 , V_82 } ;
T_4 V_83 [ 6 ] = {
V_84 , V_85 ,
V_86 , V_87 ,
V_88 , V_89 } ;
T_1 V_53 , V_65 , V_90 [ 4 ] ;
T_2 V_63 ;
T_4 V_91 ;
for ( V_65 = 0 ; V_65 < 2 ; V_65 ++ ) {
V_63 = V_75 [ V_65 ] ;
for ( V_53 = 0 ; V_53 < 4 ; V_53 ++ ) {
V_90 [ V_53 ] = ( T_1 ) ( ( V_63 & ( 0x7f << ( V_53 * 8 ) ) ) >> ( V_53 * 8 ) ) ;
if ( V_90 [ V_53 ] > V_38 )
V_90 [ V_53 ] = V_38 ;
}
V_63 = ( V_90 [ 3 ] << 24 ) | ( V_90 [ 2 ] << 16 ) | ( V_90 [ 1 ] << 8 ) | V_90 [ 0 ] ;
if ( V_65 == 0 )
V_91 = V_76 [ V_57 ] ;
else
V_91 = V_83 [ V_57 ] ;
F_7 ( V_2 , V_91 , V_92 , V_63 ) ;
if ( ( ( V_6 -> V_93 == V_94 ) &&
( V_91 == V_82 || V_91 == V_89 ) ) ||
( ( V_6 -> V_93 != V_94 ) &&
( V_91 == V_80 || V_91 == V_87 ) ) ) {
V_63 = V_90 [ 3 ] ;
if ( V_91 == V_82 || V_91 == V_80 )
V_91 = 0xc90 ;
if ( V_91 == V_89 || V_91 == V_87 )
V_91 = 0xc98 ;
for ( V_53 = 0 ; V_53 < 3 ; V_53 ++ ) {
if ( V_53 != 2 )
V_63 = ( V_63 > 8 ) ? ( V_63 - 8 ) : 0 ;
else
V_63 = ( V_63 > 6 ) ? ( V_63 - 6 ) : 0 ;
F_11 ( V_2 , ( T_2 ) ( V_91 + V_53 ) , ( T_1 ) V_63 ) ;
}
}
}
}
void
F_12 (
struct V_1 * V_2 ,
T_1 * V_45 ,
T_1 * V_46 ,
T_1 * V_47 ,
T_1 V_48 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_63 [ 2 ] , V_51 [ 2 ] , V_52 [ 2 ] , V_22 ;
T_1 V_27 ;
T_1 V_57 = 0 ;
F_8 ( V_2 , V_45 , V_46 , V_47 , V_48 , & V_51 [ 0 ] , & V_52 [ 0 ] ) ;
F_6 ( & V_6 -> V_39 , 0 , & V_27 , & V_22 ) ;
for ( V_57 = 0 ; V_57 < 6 ; V_57 ++ ) {
F_9 ( V_2 , V_48 , V_57 ,
& V_51 [ 0 ] , & V_52 [ 0 ] ,
& V_63 [ 0 ] ) ;
if ( V_27 == 1 ) {
V_63 [ 0 ] += V_22 ;
V_63 [ 1 ] += V_22 ;
} else if ( V_27 == 2 ) {
V_63 [ 0 ] -= V_22 ;
V_63 [ 1 ] -= V_22 ;
}
F_10 ( V_2 , V_57 , & V_63 [ 0 ] ) ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_95 * V_96 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_2 V_97 = 0 ;
T_1 V_98 ;
int V_99 = V_100 ;
for ( V_98 = 0 ; V_98 < V_6 -> V_55 ; V_98 ++ ) {
V_96 = & V_6 -> V_101 [ V_98 ] ;
switch ( V_98 ) {
case V_9 :
case V_102 :
V_97 = F_14 ( V_2 , V_96 -> V_103 , V_104 ) ;
break;
case V_31 :
case V_105 :
V_97 = F_14 ( V_2 , V_96 -> V_103 , V_104 << 16 ) ;
break;
}
F_7 ( V_2 , V_96 -> V_106 , V_104 << 16 , 0x1 ) ;
F_15 ( 1 ) ;
F_7 ( V_2 , V_96 -> V_107 , V_104 , 0x1 ) ;
F_15 ( 1 ) ;
F_7 ( V_2 , V_96 -> V_108 , V_109 , 0x0 ) ;
F_15 ( 1 ) ;
F_7 ( V_2 , V_96 -> V_108 , V_110 , 0x0 ) ;
F_15 ( 1 ) ;
switch ( V_98 ) {
case V_9 :
if ( V_111 == F_16 ( & V_6 -> V_39 , (enum V_112 ) V_98 , (enum V_112 ) V_98 ) )
V_99 = V_113 ;
break;
case V_31 :
if ( V_111 == F_16 ( & V_6 -> V_39 , (enum V_112 ) V_98 , (enum V_112 ) V_98 ) )
V_99 = V_113 ;
break;
case V_102 :
break;
case V_105 :
break;
}
;
switch ( V_98 ) {
case V_9 :
case V_102 :
F_7 ( V_2 , V_96 -> V_103 , V_104 , V_97 ) ;
break;
case V_31 :
case V_105 :
F_7 ( V_2 , V_96 -> V_103 , V_104 << 16 , V_97 ) ;
break;
}
if ( V_99 != V_100 )
goto V_114;
}
return V_99 ;
V_114:
return V_99 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_99 = V_100 ;
if ( V_6 -> V_93 == V_115 )
V_6 -> V_55 = 1 ;
else
V_6 -> V_55 = 2 ;
V_99 = F_13 ( V_2 ) ;
return V_99 ;
}

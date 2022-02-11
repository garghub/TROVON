static int F_1 ( struct V_1 * V_1 ,
const T_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
int V_6 ;
int V_7 ;
if ( V_8 >= 3 ) {
F_2 ( V_9 L_1 ) ;
for ( V_7 = 0 ; V_7 < V_3 ; ++ V_7 )
F_2 ( V_10 L_2 , V_2 [ V_7 ] ) ;
F_2 ( V_10 L_3 ) ;
}
if ( F_3 ( & V_1 -> V_11 ) < 0 )
return - V_12 ;
V_6 = F_4 ( V_1 -> V_13 , V_1 -> V_14 ,
( T_1 * ) V_2 , V_3 , & V_5 , 1000 ) ;
if ( V_6 != 0 ) {
F_5 ( L_4 ,
V_15 , V_6 ) ;
F_6 ( & V_1 -> V_11 ) ;
return V_6 ;
}
if ( V_5 != V_3 ) {
F_5 ( L_5 , V_15 ,
V_5 , V_3 ) ;
F_6 ( & V_1 -> V_11 ) ;
return - 1 ;
}
V_6 = F_4 ( V_1 -> V_13 , V_1 -> V_16 ,
V_1 -> V_17 , 32 , & V_5 , 1000 ) ;
if ( V_6 != 0 ) {
F_2 ( L_6 , V_15 ,
V_6 ) ;
F_6 ( & V_1 -> V_11 ) ;
return V_6 ;
}
if ( V_8 >= 3 ) {
V_5 = V_1 -> V_17 [ 3 ] + 4 ;
F_2 ( V_9 L_7 ) ;
for ( V_7 = 0 ; V_7 < V_5 ; ++ V_7 )
F_2 ( V_10 L_2 , V_1 -> V_17 [ V_7 ] ) ;
F_2 ( V_10 L_3 ) ;
}
if ( ! V_4 )
F_6 ( & V_1 -> V_11 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 * V_2 , int V_3 )
{
memcpy ( V_2 , V_1 -> V_17 , V_3 ) ;
F_6 ( & V_1 -> V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_1 ,
T_1 V_18 , T_1 * V_19 , T_1 V_20 , T_1 * V_21 ,
T_1 V_22 )
{
T_1 V_23 [ 0x28 ] ;
T_1 V_24 = ++ V_1 -> V_25 ;
int V_7 , V_6 ;
if ( V_20 > 0x28 - 7 || V_22 > 0x20 - 7 )
return - V_26 ;
V_23 [ 0 ] = 0xaa ;
V_23 [ 1 ] = V_24 ;
V_23 [ 2 ] = 0x31 ;
V_23 [ 3 ] = V_20 + 3 ;
V_23 [ 4 ] = V_18 << 1 ;
V_23 [ 5 ] = V_20 ;
V_23 [ 6 ] = V_22 ;
for ( V_7 = 0 ; V_7 < V_20 ; V_7 ++ )
V_23 [ 7 + V_7 ] = V_19 [ V_7 ] ;
V_6 = F_1 ( V_1 , V_23 , V_20 + 7 , 1 ) ;
if ( V_6 )
return - V_27 ;
V_6 = F_7 ( V_1 , V_23 , 0x20 ) ;
if ( ( V_20 != V_23 [ 5 ] ) || ( V_22 != V_23 [ 6 ] ) ) return - V_27 ;
if ( V_22 > 0 ) {
if ( V_6 || V_23 [ 0 ] != 0x55 || V_23 [ 1 ] != V_24 ) {
F_5
( L_8 ,
V_15 , V_6 , V_24 ) ;
return - V_27 ;
}
for ( V_7 = 0 ; V_7 < V_22 ; V_7 ++ )
V_21 [ V_7 ] = V_23 [ 7 + V_7 ] ;
}
return V_22 ;
}
static int F_9 ( struct V_28 * V_29 , struct V_30 * V_31 , int V_32 )
{
struct V_1 * V_1 = F_10 ( V_29 ) ;
int V_7 = 0 ;
int V_33 ;
if ( F_3 ( & V_1 -> V_34 ) < 0 )
return - V_12 ;
while ( V_7 < V_32 ) {
T_1 V_18 , V_20 , V_22 , * V_19 , * V_21 ;
int V_6 ;
if ( V_32 > V_7 + 1 && ( V_31 [ V_7 + 1 ] . V_35 & V_36 ) ) {
V_18 = V_31 [ V_7 ] . V_18 ;
V_19 = V_31 [ V_7 ] . V_37 ;
V_20 = V_31 [ V_7 ] . V_3 ;
V_21 = V_31 [ V_7 + 1 ] . V_37 ;
V_22 = V_31 [ V_7 + 1 ] . V_3 ;
V_33 = 2 ;
} else {
V_18 = V_31 [ V_7 ] . V_18 ;
V_19 = V_31 [ V_7 ] . V_37 ;
V_20 = V_31 [ V_7 ] . V_3 ;
V_21 = NULL ;
V_22 = 0 ;
V_33 = 1 ;
}
V_6 = F_8 ( V_1 , V_18 ,
V_19 , V_20 , V_21 , V_22 ) ;
if ( V_6 < V_22 ) {
F_5 ( L_9 , V_15 , V_7 ) ;
break;
}
V_7 += V_33 ;
}
F_6 ( & V_1 -> V_34 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_1 )
{
const struct V_38 * V_39 ;
int V_7 , V_6 ;
T_1 V_23 [ 40 ] ;
V_6 = F_12 ( & V_39 , L_10 ,
& V_1 -> V_13 -> V_13 ) ;
if ( V_6 ) {
F_2 ( V_40 L_11 ) ;
return V_6 ;
}
V_23 [ 0 ] = 0xaa ;
V_23 [ 2 ] = 0x13 ;
V_23 [ 3 ] = 28 ;
for ( V_7 = 0 ; V_7 < V_39 -> V_41 ; V_7 += 28 ) {
memcpy ( & V_23 [ 4 ] , & V_39 -> V_2 [ V_7 ] , 28 ) ;
V_23 [ 1 ] = ++ V_1 -> V_25 ;
V_6 = F_1 ( V_1 , V_23 , 32 , 0 ) ;
if ( V_6 )
goto V_42;
}
V_23 [ 1 ] = ++ V_1 -> V_25 ;
V_23 [ 2 ] = 0x13 ;
V_23 [ 3 ] = 0 ;
V_6 = F_1 ( V_1 , V_23 , 4 , 0 ) ;
if ( V_6 )
goto V_42;
V_23 [ 1 ] = ++ V_1 -> V_25 ;
V_23 [ 2 ] = 0x14 ;
V_23 [ 3 ] = 0 ;
V_6 = F_1 ( V_1 , V_23 , 4 , 0 ) ;
V_42:
F_13 ( V_39 ) ;
if ( V_6 ) {
F_5 ( L_12 ,
V_15 , V_6 ) ;
}
return V_6 ;
}
static int F_14 ( struct V_1 * V_1 , int V_43 , int V_44 ,
int V_45 )
{
int V_6 ;
T_1 V_23 [] = { 0xaa , ++ V_1 -> V_25 , 0x22 , 4 , V_43 , V_44 ,
( V_45 >> 8 ) & 0xff , V_45 & 0xff
} ;
V_6 = F_1 ( V_1 , V_23 , sizeof( V_23 ) , 0 ) ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_1 , int V_46 )
{
int V_6 ;
T_1 V_23 [] = { 0xaa , ++ V_1 -> V_25 , 0x23 , 1 , V_46 } ;
V_6 = F_1 ( V_1 , V_23 , sizeof( V_23 ) , 0 ) ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_1 , int V_47 ,
int V_48 , T_1 V_49 [ 8 ] , T_1 V_50 [ 8 ] )
{
int V_6 ;
T_1 V_23 [] = { 0xaa , 0 , 0x24 , 0x1a , V_47 , V_48 ,
V_49 [ 0 ] , V_49 [ 1 ] , V_49 [ 2 ] , V_49 [ 3 ] ,
V_49 [ 4 ] , V_49 [ 5 ] , V_49 [ 6 ] , V_49 [ 7 ] ,
V_49 [ 8 ] , V_49 [ 9 ] , V_49 [ 10 ] , V_49 [ 11 ] ,
V_50 [ 0 ] , V_50 [ 1 ] , V_50 [ 2 ] , V_50 [ 3 ] ,
V_50 [ 4 ] , V_50 [ 5 ] , V_50 [ 6 ] , V_50 [ 7 ] ,
V_50 [ 8 ] , V_50 [ 9 ] , V_50 [ 10 ] , V_50 [ 11 ]
} ;
V_6 = F_1 ( V_1 , V_23 , sizeof( V_23 ) , 0 ) ;
return V_6 ;
}
static int F_17 ( struct V_1 * V_1 , int V_47 )
{
int V_6 ;
T_1 V_23 [] = { 0xaa , ++ V_1 -> V_25 , 0x25 , 1 , V_47 } ;
V_6 = F_1 ( V_1 , V_23 , sizeof( V_23 ) , 0 ) ;
return V_6 ;
}
static int F_18 ( struct V_1 * V_1 )
{
T_1 V_51 [] = { 0xaa , ++ V_1 -> V_25 , 0x15 , 1 , 0 } ;
T_1 V_52 [] = { 0xaa , ++ V_1 -> V_25 , 0x15 , 1 , 1 } ;
T_1 V_53 [] = { 0xaa , ++ V_1 -> V_25 , 0x32 , 1 , 0 } ;
T_1 V_54 [] =
{ 0xaa , ++ V_1 -> V_25 , 0x31 , 5 , 0x10 , 0x02 , 0x01 , 0x00 , 0x1e } ;
T_1 V_55 [] =
{ 0x55 , V_1 -> V_25 , 0x31 , 4 , 0x10 , 0x02 , 0x01 , 0x00 , 0x1e } ;
T_1 V_56 [] = { 0xaa , ++ V_1 -> V_25 , 0x17 , 5 , 0 , 0 , 0 , 0 , 0 } ;
T_1 V_57 [ 0x20 ] =
{ 0xaa , ++ V_1 -> V_25 , 0x26 , 28 , 0 , 0 , 0 , 0 , 0 } ;
int V_6 ;
if ( ( V_6 = F_1 ( V_1 , V_51 , sizeof( V_51 ) , 0 ) ) )
return V_6 ;
if ( ( V_6 = F_1 ( V_1 , V_52 , sizeof( V_52 ) , 0 ) ) )
return V_6 ;
F_11 ( V_1 ) ;
if ( ( V_6 = F_1 ( V_1 , V_53 , sizeof( V_53 ) , 0 ) ) )
return V_6 ;
if ( ( V_6 = F_1 ( V_1 , V_54 , sizeof( V_54 ) , 1 ) ) )
return V_6 ;
V_6 = F_7 ( V_1 , V_55 , sizeof( V_55 ) ) ;
if ( ( V_6 = F_1 ( V_1 , V_56 , sizeof( V_56 ) , 1 ) ) )
return V_6 ;
if ( ( V_6 = F_7 ( V_1 , V_56 , sizeof( V_56 ) ) ) )
return V_6 ;
F_5 ( L_13 , V_15 ,
V_56 [ 4 ] , V_56 [ 5 ] , V_56 [ 6 ] ,
V_56 [ 7 ] , V_56 [ 8 ] ) ;
if ( memcmp ( V_56 + 4 , L_14 , 5 ) &&
memcmp ( V_56 + 4 , L_15 , 5 ) &&
memcmp ( V_56 + 4 , L_16 , 5 ) &&
memcmp ( V_56 + 4 , L_17 , 5 ) ) {
F_2
( L_18 ,
V_15 , V_56 [ 4 ] , V_56 [ 5 ] ,
V_56 [ 6 ] , V_56 [ 7 ] , V_56 [ 8 ] ) ;
}
V_1 -> V_58 = ( ( V_56 [ 6 ] - '0' ) << 4 ) |
( V_56 [ 8 ] - '0' ) ;
V_6 =
F_1 ( V_1 , V_57 , sizeof( V_57 ) , 1 ) ;
if ( V_6 )
return V_6 ;
V_6 =
F_7 ( V_1 , V_57 , sizeof( V_57 ) ) ;
if ( V_6 )
return V_6 ;
F_2 ( L_19 , V_15 ,
V_57 [ 4 ] , V_57 [ 5 ] , V_57 [ 6 ] ) ;
return 0 ;
}
static int F_19 ( struct V_59 * V_60 ,
const struct V_61 * V_62 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_23 [ 12 ] = { 0xaa , ++ V_1 -> V_25 , 0x18 } ;
int V_6 ;
V_23 [ 3 ] = 4 + 2 + V_62 -> V_65 ;
V_23 [ 4 ] = 0xFF ;
V_23 [ 5 ] = V_62 -> V_65 ;
memcpy ( V_23 + 5 , V_62 -> V_31 , V_62 -> V_65 ) ;
if ( ( V_6 = F_1 ( V_1 , V_23 , 4 + V_23 [ 3 ] , 0 ) ) ) {
F_5 ( L_12 ,
V_15 , V_6 ) ;
}
return V_6 ;
}
static int F_20 ( struct V_1 * V_1 )
{
T_1 V_23 [] = { 0xaa , ++ V_1 -> V_25 , 0x16 , 5 , 1 ,
V_1 -> V_66 == V_67 ? 0 : 1 ,
V_1 -> V_68 == V_69 ? 1 : 0 , 1 , 1
} ;
int V_6 ;
if ( ( V_6 = F_1 ( V_1 , V_23 , sizeof( V_23 ) , 0 ) ) ) {
F_5 ( L_12 ,
V_15 , V_6 ) ;
}
return V_6 ;
}
static int F_21 ( struct V_59 * V_60 ,
enum V_70 V_66 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
V_1 -> V_66 = V_66 ;
return F_20 ( V_1 ) ;
}
static int F_22 ( struct V_59 * V_60 , enum V_71 V_68 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
V_1 -> V_68 = V_68 ;
return F_20 ( V_1 ) ;
}
static void F_23 ( struct V_1 * V_1 , const T_1 * V_72 ,
int V_3 )
{
T_2 V_73 = 0 , V_74 ;
int V_7 ;
if ( V_3 < 4 || V_3 & 0x1 ) {
F_24 ( L_20 , V_15 , V_3 ) ;
V_75 ++ ;
return;
}
for ( V_7 = 0 ; V_7 < V_3 ; V_7 += 2 )
V_73 ^= F_25 ( ( V_76 * ) ( V_72 + V_7 ) ) ;
if ( V_73 ) {
F_2 ( L_21 ,
V_15 ) ;
V_75 ++ ;
return;
}
V_74 = ( V_72 [ V_3 - 4 ] << 8 ) | V_72 [ V_3 - 3 ] ;
V_74 &= 0x7FFF ;
if ( ( V_74 != V_1 -> V_74 ) && ( V_1 -> V_74 != - 1 ) )
F_2 ( L_22 ,
V_15 , ( V_74 - V_1 -> V_74 ) & 0x7FFF ) ;
V_1 -> V_74 = ( V_74 + 1 ) & 0x7FFF ;
if ( V_72 [ 0 ] & 0x80 ) {
#ifdef F_26
int V_77 = V_72 [ 0 ] & 0x40 ;
int V_78 = V_72 [ 0 ] & 0x1F ;
int V_79 = V_72 [ 1 ] ;
const T_1 * V_2 = V_72 + 2 ;
if ( V_72 [ 0 ] & 0x20 )
V_2 ++ ;
F_27 ( V_1 -> V_78 + V_78 , V_2 ,
V_79 ) ;
V_2 += V_79 ;
if ( ( ! ! ( V_1 -> V_72 [ 0 ] & 0x20 ) ) ^
! ! ( V_1 -> V_72 [ 1 ] & 1 ) )
V_2 ++ ;
#warning TODO: pusi
F_2 ( L_23 , ( V_2 [ 0 ] << 8 ) | V_2 [ 1 ] ) ;
#endif
V_80 ++ ;
} else if ( V_72 [ 0 ] == 0x47 ) {
#ifdef F_26
int V_45 = ( ( V_72 [ 1 ] & 0x0F ) << 8 ) | V_72 [ 2 ] ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_81 ; ++ V_78 )
if ( V_1 -> V_78 [ V_78 ] . V_82
&& ( V_45 == V_1 -> V_78 [ V_78 ] . V_45 ) )
F_28 ( V_1 -> V_78 +
V_78 , V_72 ,
188 ) ;
#endif
V_83 ++ ;
F_29 ( & V_1 -> V_84 , V_72 , 1 ) ;
} else if ( V_72 [ 0 ] != 0 ) {
V_75 ++ ;
F_2 ( L_24 , V_72 [ 0 ] ) ;
} else
V_85 ++ ;
}
static void F_30 ( struct V_1 * V_1 , T_1 * V_2 , int V_3 )
{
int V_86 = 1024 ;
while ( V_3 ) {
if ( ! ( V_86 -- ) ) {
F_2 ( L_25 , V_15 ) ;
break;
}
switch ( V_1 -> V_87 ) {
case 0 :
case 1 :
case 2 :
V_3 -- ;
if ( * V_2 ++ == 0xAA )
++ V_1 -> V_87 ;
else {
V_1 -> V_87 = 0 ;
if ( V_1 -> V_88 ) {
F_5 ( L_26 ,
V_15 , V_2 [ - 1 ] ) ;
F_2 ( V_89 L_27 ,
V_15 ) ;
V_1 -> V_88 = 0 ;
}
}
break;
case 3 :
V_1 -> V_88 = 1 ;
V_3 -- ;
V_1 -> V_90 = * V_2 ++ ;
++ V_1 -> V_87 ;
V_1 -> V_91 = 0 ;
V_1 -> V_92 = 2 ;
break;
case 4 :
{
int V_93 ;
V_93 = V_3 ;
if ( V_93 >
( V_1 -> V_92 -
V_1 -> V_91 ) )
V_93 =
V_1 -> V_92 -
V_1 -> V_91 ;
memcpy ( V_1 -> V_72 + V_1 -> V_91 ,
V_2 , V_93 ) ;
V_1 -> V_91 += V_93 ;
F_31 ( V_1 -> V_91 > 264 ) ;
V_2 += V_93 ;
V_3 -= V_93 ;
if ( V_1 -> V_91 == 2 ) {
if ( V_1 -> V_72 [ 0 ] & 0x80 ) {
V_1 -> V_92 =
V_1 -> V_72 [ 1 ] + 2 ;
if ( V_1 ->
V_72 [ 0 ] & 0x20 )
V_1 ->
V_92 ++ ;
if ( ( ! !
( V_1 ->
V_72 [ 0 ] & 0x20 ) ) ^
! ! ( V_1 ->
V_72 [ 1 ] & 1 ) )
V_1 ->
V_92 ++ ;
V_1 -> V_92 += 4 ;
} else if ( V_1 -> V_72 [ 0 ] ==
0x47 )
V_1 -> V_92 =
188 + 4 ;
else if ( V_1 -> V_72 [ 0 ] == 0x00 )
V_1 -> V_92 =
V_1 -> V_72 [ 1 ] + 2 +
4 ;
else {
F_5
( L_28 ,
V_15 ,
V_1 -> V_72 [ 0 ] ) ;
V_1 -> V_87 = 0 ;
}
}
if ( ( V_1 -> V_91 >= 2 ) &&
( V_1 -> V_91 ==
V_1 -> V_92 ) ) {
F_23 ( V_1 ,
V_1 ->
V_72 ,
V_1 ->
V_91 ) ;
V_1 -> V_91 = 0 ;
V_1 -> V_92 = 2 ;
if ( ! V_1 -> V_90 -- ) {
V_1 -> V_87 = 0 ;
break;
}
}
break;
}
default:
F_32 () ;
break;
}
}
}
static void F_33 ( struct V_94 * V_94 )
{
struct V_1 * V_1 = V_94 -> V_95 ;
struct V_96 * V_97 ;
T_1 * V_2 ;
int V_3 , V_7 ;
if ( ! V_1 -> V_98 )
return;
#if 0
printk("%s: status %d, errcount == %d, length == %i\n",
__func__,
urb->status, urb->error_count, urb->actual_length);
#endif
if ( ! V_94 -> V_99 ) {
for ( V_7 = 0 ; V_7 < V_94 -> V_100 ; ++ V_7 ) {
V_101 ++ ;
if ( F_34 ( V_102 , V_103 + V_104 ) ) {
F_5 ( L_29
L_30 ,
V_101 * V_104 / ( V_102 - V_103 ) ,
V_83 , V_85 , V_80 , V_75 ,
V_83 + V_85 + V_80 + V_75 ) ;
V_83 = V_85 = V_80 = V_75 = 0 ;
V_103 = V_102 ;
V_101 = 0 ;
}
V_97 = & V_94 -> V_105 [ V_7 ] ;
V_2 = V_94 -> V_106 + V_97 -> V_107 ;
V_3 = V_97 -> V_108 ;
V_97 -> V_108 = 0 ;
V_97 -> V_99 = 0 ;
F_30 ( V_1 , V_2 , V_3 ) ;
}
}
F_35 ( V_94 , V_109 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_110 ; V_7 ++ )
F_37 ( V_1 -> V_111 [ V_7 ] ) ;
F_38 ( NULL ,
V_112 * V_113 *
V_110 , V_1 -> V_114 ,
V_1 -> V_115 ) ;
}
static int F_39 ( struct V_1 * V_1 )
{
int V_7 ;
V_1 -> V_114 = F_40 ( NULL ,
V_112 * V_113 * V_110 ,
& V_1 -> V_115 ) ;
if ( ! V_1 -> V_114 ) {
F_5 ( L_31 ,
V_15 ) ;
return - V_116 ;
}
for ( V_7 = 0 ; V_7 < V_110 ; V_7 ++ ) {
struct V_94 * V_94 ;
if ( !
( V_94 =
F_41 ( V_113 , V_109 ) ) ) {
F_36 ( V_1 ) ;
return - V_116 ;
}
V_1 -> V_111 [ V_7 ] = V_94 ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_110 ; V_7 ++ )
F_43 ( V_1 -> V_111 [ V_7 ] ) ;
V_1 -> V_98 = 0 ;
}
static int F_44 ( struct V_1 * V_1 )
{
int V_7 , V_117 , V_6 , V_118 = 0 ;
if ( V_1 -> V_98 ) {
F_2 ( L_32 , V_15 ) ;
return 0 ;
}
V_1 -> V_74 = - 1 ;
V_1 -> V_88 = 0 ;
V_1 -> V_87 = 0 ;
for ( V_7 = 0 ; V_7 < V_110 ; V_7 ++ ) {
int V_119 = 0 ;
struct V_94 * V_94 = V_1 -> V_111 [ V_7 ] ;
V_94 -> V_13 = V_1 -> V_13 ;
V_94 -> V_95 = V_1 ;
V_94 -> V_120 = F_33 ;
V_94 -> V_121 = V_1 -> V_122 ;
V_94 -> V_123 = V_124 ;
V_94 -> V_125 = 1 ;
V_94 -> V_100 = V_113 ;
V_94 -> V_126 =
V_112 * V_113 ;
V_94 -> V_106 = V_1 -> V_114 + V_118 ;
V_118 += V_112 * V_113 ;
for ( V_117 = 0 ; V_117 < V_113 ; V_117 ++ ) {
V_94 -> V_105 [ V_117 ] . V_107 = V_119 ;
V_94 -> V_105 [ V_117 ] . V_127 = V_112 ;
V_119 += V_112 ;
}
}
for ( V_7 = 0 ; V_7 < V_110 ; V_7 ++ ) {
if ( ( V_6 = F_35 ( V_1 -> V_111 [ V_7 ] , V_109 ) ) ) {
F_42 ( V_1 ) ;
F_2
( L_33 ,
V_15 , V_7 , V_6 ) ;
return V_6 ;
}
}
V_1 -> V_98 = 1 ;
return 0 ;
}
static void F_28 ( struct V_128 * V_129 , const T_1 * V_2 ,
int V_3 )
{
V_129 -> V_130 . V_131 ( V_2 , V_3 , 0 , 0 , & V_129 -> V_132 . V_131 , 0 ) ;
}
static void F_27 ( struct V_128 * V_129 , const T_1 * V_2 ,
int V_3 )
{
#error TODO: handle ugly stuff
}
static int F_45 ( struct V_128 * V_129 )
{
struct V_1 * V_1 = (struct V_1 * ) V_129 -> V_133 ;
int V_134 = 1 ;
F_5 ( L_34 ) ;
switch ( V_129 -> type ) {
case V_135 :
break;
case V_136 :
break;
default:
return - V_26 ;
}
if ( V_129 -> type == V_135 ) {
switch ( V_129 -> V_137 ) {
case V_138 :
case V_139 :
case V_140 :
case V_141 :
case V_142 :
break;
default:
return - V_26 ;
}
}
#ifdef F_26
#error TODO: allocate filters
if ( V_129 -> type == V_135 ) {
V_134 = 1 ;
} else if ( V_129 -> type == V_136 ) {
V_134 = 2 ;
}
#endif
F_14 ( V_1 , V_129 -> V_143 , V_134 , V_129 -> V_45 ) ;
if ( 0 == V_1 -> V_144 ++ )
F_44 ( V_1 ) ;
return 0 ;
}
static int F_46 ( struct V_128 * V_129 )
{
struct V_1 * V_1 = (struct V_1 * ) V_129 -> V_133 ;
F_15 ( V_1 , V_129 -> V_143 ) ;
if ( -- V_1 -> V_144 == 0 )
F_42 ( V_1 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_1 )
{
F_48 ( V_1 -> V_13 , 1 , 1 ) ;
V_1 -> V_14 = F_49 ( V_1 -> V_13 , 1 ) ;
V_1 -> V_16 = F_50 ( V_1 -> V_13 , 1 ) ;
V_1 -> V_122 = F_51 ( V_1 -> V_13 , 2 ) ;
return 0 ;
}
static T_3 F_52 ( struct V_28 * V_29 )
{
return V_145 ;
}
static int F_53 ( struct V_59 * V_60 )
{
struct V_146 * V_147 = & V_60 -> V_148 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_2 [ 4 ] ;
struct V_30 V_31 = { . V_18 = 0x61 , . V_35 = 0 , . V_37 = V_2 , . V_3 =sizeof( V_2 ) } ;
T_3 div ;
div = ( V_147 -> V_149 + 36166667 ) / 166667 ;
V_2 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_2 [ 1 ] = div & 0xff ;
V_2 [ 2 ] = ( ( div >> 10 ) & 0x60 ) | 0x85 ;
V_2 [ 3 ] = V_147 -> V_149 < 592000000 ? 0x40 : 0x80 ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_31 , 1 ) != 1 ) return - V_153 ;
return 0 ;
}
static int F_55 ( struct V_59 * V_60 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
static T_1 V_154 [] = { 0x0b , 0xf5 , 0x85 , 0xab } ;
static T_1 V_155 [] = { 0x1d , 0x74 , 0xa0 , 0x68 } ;
struct V_30 V_156 = { . V_18 = 0x60 , . V_35 = 0 , . V_37 = V_154 , . V_3 =sizeof( V_154 ) } ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_156 , 1 ) != 1 ) return - V_153 ;
F_56 ( 1 ) ;
V_156 . V_18 = 0x65 ;
V_156 . V_37 = V_155 ;
V_156 . V_3 = sizeof( V_155 ) ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_156 , 1 ) != 1 ) {
F_54 ( & V_1 -> V_152 , & V_156 , 1 ) ;
}
return 0 ;
}
static int F_57 ( struct V_59 * V_60 )
{
struct V_146 * V_147 = & V_60 -> V_148 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_157 [ 4 ] ;
struct V_30 V_156 = { . V_18 = 0x60 , . V_35 = 0 , . V_37 = V_157 , . V_3 =sizeof( V_157 ) } ;
int V_158 = 0 ;
T_1 V_159 , V_160 , V_49 ;
V_158 = V_147 -> V_149 + 36130000 ;
if ( V_158 < 87000000 ) return - V_26 ;
else if ( V_158 < 130000000 ) V_160 = 3 ;
else if ( V_158 < 160000000 ) V_160 = 5 ;
else if ( V_158 < 200000000 ) V_160 = 6 ;
else if ( V_158 < 290000000 ) V_160 = 3 ;
else if ( V_158 < 420000000 ) V_160 = 5 ;
else if ( V_158 < 480000000 ) V_160 = 6 ;
else if ( V_158 < 620000000 ) V_160 = 3 ;
else if ( V_158 < 830000000 ) V_160 = 5 ;
else if ( V_158 < 895000000 ) V_160 = 7 ;
else return - V_26 ;
if ( V_147 -> V_149 < 49000000 )
return - V_26 ;
else if ( V_147 -> V_149 < 159000000 )
V_159 = 1 ;
else if ( V_147 -> V_149 < 444000000 )
V_159 = 2 ;
else if ( V_147 -> V_149 < 861000000 )
V_159 = 4 ;
else return - V_26 ;
switch ( V_147 -> V_161 ) {
case 6000000 :
F_58 ( V_60 , 0x0C , 0 ) ;
V_49 = 0 ;
break;
case 7000000 :
F_58 ( V_60 , 0x0C , 0 ) ;
V_49 = 0 ;
break;
case 8000000 :
F_58 ( V_60 , 0x0C , 0xFF ) ;
V_49 = 1 ;
break;
default:
return - V_26 ;
}
V_158 = ( ( ( V_147 -> V_149 / 1000 ) * 6 ) + 217280 ) / 1000 ;
V_157 [ 0 ] = V_158 >> 8 ;
V_157 [ 1 ] = V_158 & 0xff ;
V_157 [ 2 ] = 0xca ;
V_157 [ 3 ] = ( V_160 << 5 ) | ( V_49 << 3 ) | V_159 ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_156 , 1 ) != 1 )
return - V_153 ;
F_56 ( 1 ) ;
return 0 ;
}
static int F_59 ( struct V_59 * V_60 , const struct V_38 * * V_39 , char * V_162 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
return F_12 ( V_39 , V_162 , & V_1 -> V_13 -> V_13 ) ;
}
static int F_60 ( struct V_59 * V_60 , T_3 V_163 , T_3 V_164 )
{
T_1 V_165 = 0 ;
T_1 V_166 = 0 ;
if ( V_163 < 1500000 ) {
V_165 = 0xb7 ;
V_166 = 0x47 ;
} else if ( V_163 < 3000000 ) {
V_165 = 0xb7 ;
V_166 = 0x4b ;
} else if ( V_163 < 7000000 ) {
V_165 = 0xb7 ;
V_166 = 0x4f ;
} else if ( V_163 < 14000000 ) {
V_165 = 0xb7 ;
V_166 = 0x53 ;
} else if ( V_163 < 30000000 ) {
V_165 = 0xb6 ;
V_166 = 0x53 ;
} else if ( V_163 < 45000000 ) {
V_165 = 0xb4 ;
V_166 = 0x51 ;
}
F_61 ( V_60 , 0x13 , V_165 ) ;
F_61 ( V_60 , 0x14 , V_166 ) ;
F_61 ( V_60 , 0x1f , ( V_164 >> 16 ) & 0xff ) ;
F_61 ( V_60 , 0x20 , ( V_164 >> 8 ) & 0xff ) ;
F_61 ( V_60 , 0x21 , ( V_164 ) & 0xf0 ) ;
return 0 ;
}
static int F_62 ( struct V_59 * V_60 )
{
struct V_146 * V_147 = & V_60 -> V_148 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_37 [ 4 ] ;
T_3 div ;
struct V_30 V_31 = { . V_18 = 0x61 , . V_35 = 0 , . V_37 = V_37 , . V_3 = sizeof( V_37 ) } ;
if ( ( V_147 -> V_149 < 950000 ) || ( V_147 -> V_149 > 2150000 ) )
return - V_26 ;
div = ( V_147 -> V_149 + ( 125 - 1 ) ) / 125 ;
V_37 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_37 [ 1 ] = div & 0xff ;
V_37 [ 2 ] = 0x80 | ( ( div & 0x18000 ) >> 10 ) | 4 ;
V_37 [ 3 ] = 0xC4 ;
if ( V_147 -> V_149 > 1530000 )
V_37 [ 3 ] = 0xC0 ;
if ( V_1 -> V_58 == V_167 )
V_37 [ 3 ] |= 0x20 ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_31 , 1 ) != 1 )
return - V_153 ;
return 0 ;
}
static int F_63 ( struct V_59 * V_60 )
{
struct V_146 * V_147 = & V_60 -> V_148 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_37 [ 4 ] ;
T_3 div ;
struct V_30 V_31 = { . V_18 = 0x61 , . V_35 = 0 , . V_37 = V_37 , . V_3 = sizeof( V_37 ) } ;
div = V_147 -> V_149 / 125 ;
V_37 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_37 [ 1 ] = div & 0xff ;
V_37 [ 2 ] = 0x8e ;
V_37 [ 3 ] = 0x00 ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_31 , 1 ) != 1 )
return - V_153 ;
return 0 ;
}
static int F_64 ( struct V_59 * V_60 )
{
struct V_146 * V_147 = & V_60 -> V_148 ;
struct V_1 * V_1 = V_60 -> V_63 -> V_64 ;
T_3 div ;
T_1 V_2 [ 4 ] ;
struct V_30 V_31 = { . V_18 = 0x62 , . V_35 = 0 , . V_37 = V_2 , . V_3 = sizeof( V_2 ) } ;
div = ( V_147 -> V_149 + 35937500 + 31250 ) / 62500 ;
V_2 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_2 [ 1 ] = div & 0xff ;
V_2 [ 2 ] = 0x85 | ( ( div >> 10 ) & 0x60 ) ;
V_2 [ 3 ] = ( V_147 -> V_149 < 174000000 ? 0x88 : V_147 -> V_149 < 470000000 ? 0x84 : 0x81 ) ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_31 , 1 ) != 1 )
return - V_153 ;
return 0 ;
}
static T_1 F_65 ( struct V_1 * V_1 )
{
T_1 V_23 = 0xff ;
T_1 V_168 ;
struct V_30 V_31 [] = { { . V_18 = 0x50 , . V_35 = 0 , . V_37 = & V_23 , . V_3 = 1 } ,
{ . V_18 = 0x50 , . V_35 = V_36 , . V_37 = & V_168 , . V_3 = 1 } } ;
if ( ( F_54 ( & V_1 -> V_152 , V_31 , 2 ) != 2 ) || ( V_168 == 0xff ) )
V_168 = 0x48 ;
return V_168 ;
}
static int F_66 ( struct V_59 * V_60 )
{
struct V_146 * V_147 = & V_60 -> V_148 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_157 [ 5 ] ;
struct V_30 V_156 = { . V_18 = 0x60 ,
. V_35 = 0 ,
. V_37 = V_157 ,
. V_3 = sizeof( V_157 ) } ;
int V_158 = 0 ;
T_1 V_159 , V_160 , V_49 ;
V_158 = V_147 -> V_149 ;
if ( V_158 < 87000000 ) { return - V_26 ; }
else if ( V_158 < 130000000 ) { V_160 = 3 ; V_159 = 1 ; }
else if ( V_158 < 160000000 ) { V_160 = 5 ; V_159 = 1 ; }
else if ( V_158 < 200000000 ) { V_160 = 6 ; V_159 = 1 ; }
else if ( V_158 < 290000000 ) { V_160 = 3 ; V_159 = 2 ; }
else if ( V_158 < 420000000 ) { V_160 = 5 ; V_159 = 2 ; }
else if ( V_158 < 480000000 ) { V_160 = 6 ; V_159 = 2 ; }
else if ( V_158 < 620000000 ) { V_160 = 3 ; V_159 = 4 ; }
else if ( V_158 < 830000000 ) { V_160 = 5 ; V_159 = 4 ; }
else if ( V_158 < 895000000 ) { V_160 = 7 ; V_159 = 4 ; }
else { return - V_26 ; }
V_49 = 1 ;
V_158 = ( ( V_147 -> V_149 + 36125000 ) / 62500 ) ;
V_157 [ 0 ] = V_158 >> 8 ;
V_157 [ 1 ] = V_158 & 0xff ;
V_157 [ 2 ] = 0xc8 ;
V_157 [ 3 ] = ( V_160 << 5 ) | ( V_49 << 3 ) | V_159 ;
V_157 [ 4 ] = 0x80 ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_156 , 1 ) != 1 ) {
F_2 ( L_35 ) ;
return - V_153 ;
}
F_56 ( 50 ) ;
if ( V_60 -> V_150 . V_151 )
V_60 -> V_150 . V_151 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_152 , & V_156 , 1 ) != 1 ) {
F_2 ( L_36 ) ;
return - V_153 ;
}
F_56 ( 1 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_1 )
{
switch( F_68 ( V_1 -> V_13 -> V_169 . V_170 ) ) {
case 0x1003 :
V_1 -> V_60 = F_69 ( V_171 , & V_172 , & V_1 -> V_152 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_150 . V_173 . V_174 = F_62 ;
if( V_1 -> V_58 == V_167 ) {
V_172 . V_175 = V_176 ;
F_69 ( V_177 , V_1 -> V_60 , & V_1 -> V_152 , 0 , 0 ) ;
} else {
V_1 -> V_60 -> V_150 . V_178 = F_21 ;
}
break;
}
V_1 -> V_60 = F_69 ( V_179 , & V_180 , & V_1 -> V_152 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_150 . V_173 . V_174 = F_63 ;
V_1 -> V_60 -> V_150 . V_178 = F_21 ;
break;
}
break;
case 0x1004 :
V_1 -> V_60 = F_69 ( V_181 , & V_182 , & V_1 -> V_152 , F_65 ( V_1 ) ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_150 . V_173 . V_174 = F_64 ;
break;
}
V_1 -> V_60 = F_69 ( V_183 , & V_184 , & V_1 -> V_152 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_150 . V_173 . V_174 = F_66 ;
break;
}
break;
case 0x1005 :
V_1 -> V_60 = F_69 ( V_185 , & V_186 , & V_1 -> V_152 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_150 . V_173 . V_174 = F_53 ;
break;
}
V_1 -> V_60 = F_69 ( V_187 , & V_188 , & V_1 -> V_152 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_150 . V_173 . V_189 = F_55 ;
V_1 -> V_60 -> V_150 . V_173 . V_174 = F_57 ;
break;
}
break;
}
if ( V_1 -> V_60 == NULL ) {
F_2 ( L_37 ,
F_68 ( V_1 -> V_13 -> V_169 . V_190 ) ,
F_68 ( V_1 -> V_13 -> V_169 . V_170 ) ) ;
} else {
if ( F_70 ( & V_1 -> V_29 , V_1 -> V_60 ) ) {
F_2 ( L_38 ) ;
F_71 ( V_1 -> V_60 ) ;
V_1 -> V_60 = NULL ;
}
}
}
static int F_72 ( struct V_191 * V_192 , const struct V_193 * V_24 )
{
struct V_194 * V_195 ;
struct V_1 * V_1 ;
int V_196 ;
F_5 ( L_39 , V_15 ) ;
V_195 = F_73 ( V_192 ) ;
if ( V_192 -> V_197 -> V_198 . V_199 != 1 ) return - V_200 ;
if ( ! ( V_1 = F_74 ( sizeof( struct V_1 ) , V_201 ) ) )
return - V_116 ;
V_1 -> V_13 = V_195 ;
V_1 -> V_25 = 0 ;
V_1 -> V_87 = 0 ;
F_75 ( & V_1 -> V_34 ) ;
F_76 ( & V_1 -> V_34 ) ;
F_75 ( & V_1 -> V_11 ) ;
F_47 ( V_1 ) ;
V_196 = F_39 ( V_1 ) ;
if ( V_196 < 0 ) {
F_5 ( L_40 , V_15 ) ;
F_6 ( & V_1 -> V_34 ) ;
F_77 ( V_1 ) ;
return V_196 ;
}
if ( F_18 ( V_1 ) )
F_2 ( L_41 ) ;
F_6 ( & V_1 -> V_34 ) ;
V_196 = F_78 ( & V_1 -> V_29 ,
L_42 ,
V_202 , & V_195 -> V_13 , V_203 ) ;
if ( V_196 < 0 ) {
F_36 ( V_1 ) ;
F_77 ( V_1 ) ;
return V_196 ;
}
V_1 -> V_29 . V_64 = V_1 ;
memset ( & V_1 -> V_152 , 0 , sizeof( struct V_28 ) ) ;
strcpy ( V_1 -> V_152 . V_162 , L_43 ) ;
F_79 ( & V_1 -> V_152 , V_1 ) ;
V_1 -> V_152 . V_204 = & V_205 ;
V_1 -> V_152 . V_206 = NULL ;
V_1 -> V_152 . V_13 . V_207 = & V_195 -> V_13 ;
V_196 = F_80 ( & V_1 -> V_152 ) ;
if ( V_196 )
goto V_208;
memset ( & V_1 -> V_84 , 0 , sizeof( V_1 -> V_84 ) ) ;
V_1 -> V_84 . V_209 . V_210 =
V_211 | V_212 ;
V_1 -> V_84 . V_64 = NULL ;
#ifdef F_26
V_1 -> V_84 . V_213 = V_214 ;
#else
V_1 -> V_84 . V_213 = 32 ;
#endif
V_1 -> V_84 . V_215 = V_81 ;
V_1 -> V_84 . V_216 = F_45 ;
V_1 -> V_84 . V_217 = F_46 ;
V_1 -> V_84 . V_218 = NULL ;
V_196 = F_81 ( & V_1 -> V_84 ) ;
if ( V_196 < 0 ) {
F_2 ( L_44 , V_196 ) ;
V_196 = - V_200 ;
goto V_219;
}
V_1 -> V_220 . V_213 = V_1 -> V_84 . V_213 ;
V_1 -> V_220 . V_133 = & V_1 -> V_84 . V_209 ;
V_1 -> V_220 . V_210 = 0 ;
V_196 = F_82 ( & V_1 -> V_220 , & V_1 -> V_29 ) ;
if ( V_196 < 0 ) {
F_2 ( L_45 ,
V_196 ) ;
V_196 = - V_200 ;
goto V_221;
}
if ( F_83 ( & V_1 -> V_29 , & V_1 -> V_222 , & V_1 -> V_84 . V_209 ) ) {
F_2 ( L_46 ) ;
V_196 = - V_200 ;
goto V_223;
}
F_84 ( V_192 , ( void * ) V_1 ) ;
F_67 ( V_1 ) ;
return 0 ;
V_223:
F_85 ( & V_1 -> V_220 ) ;
V_221:
F_86 ( & V_1 -> V_84 ) ;
V_219:
F_87 ( & V_1 -> V_152 ) ;
V_208:
F_88 ( & V_1 -> V_29 ) ;
F_36 ( V_1 ) ;
F_77 ( V_1 ) ;
return V_196 ;
}
static void F_89 ( struct V_191 * V_192 )
{
struct V_1 * V_1 = F_90 ( V_192 ) ;
F_84 ( V_192 , NULL ) ;
V_1 -> V_224 = 1 ;
F_42 ( V_1 ) ;
V_1 -> V_84 . V_209 . V_225 ( & V_1 -> V_84 . V_209 ) ;
F_91 ( & V_1 -> V_222 ) ;
F_85 ( & V_1 -> V_220 ) ;
F_86 ( & V_1 -> V_84 ) ;
if ( V_1 -> V_60 != NULL ) {
F_92 ( V_1 -> V_60 ) ;
F_71 ( V_1 -> V_60 ) ;
}
F_87 ( & V_1 -> V_152 ) ;
F_88 ( & V_1 -> V_29 ) ;
F_36 ( V_1 ) ;
F_77 ( V_1 ) ;
F_5 ( L_47 , V_15 ) ;
}

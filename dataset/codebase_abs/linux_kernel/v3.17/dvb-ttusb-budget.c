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
static int F_21 ( struct V_59 * V_60 , T_2 V_66 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
V_1 -> V_66 = V_66 ;
return F_20 ( V_1 ) ;
}
static int F_22 ( struct V_59 * V_60 , T_3 V_68 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
V_1 -> V_68 = V_68 ;
return F_20 ( V_1 ) ;
}
static void F_23 ( struct V_1 * V_1 , const T_1 * V_70 ,
int V_3 )
{
T_4 V_71 = 0 , V_72 ;
int V_7 ;
if ( V_3 < 4 || V_3 & 0x1 ) {
F_24 ( L_20 , V_15 , V_3 ) ;
V_73 ++ ;
return;
}
for ( V_7 = 0 ; V_7 < V_3 ; V_7 += 2 )
V_71 ^= F_25 ( ( V_74 * ) ( V_70 + V_7 ) ) ;
if ( V_71 ) {
F_2 ( L_21 ,
V_15 ) ;
V_73 ++ ;
return;
}
V_72 = ( V_70 [ V_3 - 4 ] << 8 ) | V_70 [ V_3 - 3 ] ;
V_72 &= 0x7FFF ;
if ( ( V_72 != V_1 -> V_72 ) && ( V_1 -> V_72 != - 1 ) )
F_2 ( L_22 ,
V_15 , ( V_72 - V_1 -> V_72 ) & 0x7FFF ) ;
V_1 -> V_72 = ( V_72 + 1 ) & 0x7FFF ;
if ( V_70 [ 0 ] & 0x80 ) {
#ifdef F_26
int V_75 = V_70 [ 0 ] & 0x40 ;
int V_76 = V_70 [ 0 ] & 0x1F ;
int V_77 = V_70 [ 1 ] ;
const T_1 * V_2 = V_70 + 2 ;
if ( V_70 [ 0 ] & 0x20 )
V_2 ++ ;
F_27 ( V_1 -> V_76 + V_76 , V_2 ,
V_77 ) ;
V_2 += V_77 ;
if ( ( ! ! ( V_1 -> V_70 [ 0 ] & 0x20 ) ) ^
! ! ( V_1 -> V_70 [ 1 ] & 1 ) )
V_2 ++ ;
#warning TODO: pusi
F_2 ( L_23 , ( V_2 [ 0 ] << 8 ) | V_2 [ 1 ] ) ;
#endif
V_78 ++ ;
} else if ( V_70 [ 0 ] == 0x47 ) {
#ifdef F_26
int V_45 = ( ( V_70 [ 1 ] & 0x0F ) << 8 ) | V_70 [ 2 ] ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_79 ; ++ V_76 )
if ( V_1 -> V_76 [ V_76 ] . V_80
&& ( V_45 == V_1 -> V_76 [ V_76 ] . V_45 ) )
F_28 ( V_1 -> V_76 +
V_76 , V_70 ,
188 ) ;
#endif
V_81 ++ ;
F_29 ( & V_1 -> V_82 , V_70 , 1 ) ;
} else if ( V_70 [ 0 ] != 0 ) {
V_73 ++ ;
F_2 ( L_24 , V_70 [ 0 ] ) ;
} else
V_83 ++ ;
}
static void F_30 ( struct V_1 * V_1 , T_1 * V_2 , int V_3 )
{
int V_84 = 1024 ;
while ( V_3 ) {
if ( ! ( V_84 -- ) ) {
F_2 ( L_25 , V_15 ) ;
break;
}
switch ( V_1 -> V_85 ) {
case 0 :
case 1 :
case 2 :
V_3 -- ;
if ( * V_2 ++ == 0xAA )
++ V_1 -> V_85 ;
else {
V_1 -> V_85 = 0 ;
if ( V_1 -> V_86 ) {
F_5 ( L_26 ,
V_15 , V_2 [ - 1 ] ) ;
F_2 ( V_87 L_27 ,
V_15 ) ;
V_1 -> V_86 = 0 ;
}
}
break;
case 3 :
V_1 -> V_86 = 1 ;
V_3 -- ;
V_1 -> V_88 = * V_2 ++ ;
++ V_1 -> V_85 ;
V_1 -> V_89 = 0 ;
V_1 -> V_90 = 2 ;
break;
case 4 :
{
int V_91 ;
V_91 = V_3 ;
if ( V_91 >
( V_1 -> V_90 -
V_1 -> V_89 ) )
V_91 =
V_1 -> V_90 -
V_1 -> V_89 ;
memcpy ( V_1 -> V_70 + V_1 -> V_89 ,
V_2 , V_91 ) ;
V_1 -> V_89 += V_91 ;
F_31 ( V_1 -> V_89 > 264 ) ;
V_2 += V_91 ;
V_3 -= V_91 ;
if ( V_1 -> V_89 == 2 ) {
if ( V_1 -> V_70 [ 0 ] & 0x80 ) {
V_1 -> V_90 =
V_1 -> V_70 [ 1 ] + 2 ;
if ( V_1 ->
V_70 [ 0 ] & 0x20 )
V_1 ->
V_90 ++ ;
if ( ( ! !
( V_1 ->
V_70 [ 0 ] & 0x20 ) ) ^
! ! ( V_1 ->
V_70 [ 1 ] & 1 ) )
V_1 ->
V_90 ++ ;
V_1 -> V_90 += 4 ;
} else if ( V_1 -> V_70 [ 0 ] ==
0x47 )
V_1 -> V_90 =
188 + 4 ;
else if ( V_1 -> V_70 [ 0 ] == 0x00 )
V_1 -> V_90 =
V_1 -> V_70 [ 1 ] + 2 +
4 ;
else {
F_5
( L_28 ,
V_15 ,
V_1 -> V_70 [ 0 ] ) ;
V_1 -> V_85 = 0 ;
}
}
if ( ( V_1 -> V_89 >= 2 ) &&
( V_1 -> V_89 ==
V_1 -> V_90 ) ) {
F_23 ( V_1 ,
V_1 ->
V_70 ,
V_1 ->
V_89 ) ;
V_1 -> V_89 = 0 ;
V_1 -> V_90 = 2 ;
if ( ! V_1 -> V_88 -- ) {
V_1 -> V_85 = 0 ;
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
static void F_33 ( struct V_92 * V_92 )
{
struct V_1 * V_1 = V_92 -> V_93 ;
struct V_94 * V_95 ;
T_1 * V_2 ;
int V_3 , V_7 ;
if ( ! V_1 -> V_96 )
return;
#if 0
printk("%s: status %d, errcount == %d, length == %i\n",
__func__,
urb->status, urb->error_count, urb->actual_length);
#endif
if ( ! V_92 -> V_97 ) {
for ( V_7 = 0 ; V_7 < V_92 -> V_98 ; ++ V_7 ) {
V_99 ++ ;
if ( F_34 ( V_100 , V_101 + V_102 ) ) {
F_5 ( L_29
L_30 ,
V_99 * V_102 / ( V_100 - V_101 ) ,
V_81 , V_83 , V_78 , V_73 ,
V_81 + V_83 + V_78 + V_73 ) ;
V_81 = V_83 = V_78 = V_73 = 0 ;
V_101 = V_100 ;
V_99 = 0 ;
}
V_95 = & V_92 -> V_103 [ V_7 ] ;
V_2 = V_92 -> V_104 + V_95 -> V_105 ;
V_3 = V_95 -> V_106 ;
V_95 -> V_106 = 0 ;
V_95 -> V_97 = 0 ;
F_30 ( V_1 , V_2 , V_3 ) ;
}
}
F_35 ( V_92 , V_107 ) ;
}
static void F_36 ( struct V_1 * V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_108 ; V_7 ++ )
F_37 ( V_1 -> V_109 [ V_7 ] ) ;
F_38 ( NULL ,
V_110 * V_111 *
V_108 , V_1 -> V_112 ,
V_1 -> V_113 ) ;
}
static int F_39 ( struct V_1 * V_1 )
{
int V_7 ;
V_1 -> V_112 = F_40 ( NULL ,
V_110 * V_111 * V_108 ,
& V_1 -> V_113 ) ;
if ( ! V_1 -> V_112 ) {
F_5 ( L_31 ,
V_15 ) ;
return - V_114 ;
}
for ( V_7 = 0 ; V_7 < V_108 ; V_7 ++ ) {
struct V_92 * V_92 ;
if ( !
( V_92 =
F_41 ( V_111 , V_107 ) ) ) {
F_36 ( V_1 ) ;
return - V_114 ;
}
V_1 -> V_109 [ V_7 ] = V_92 ;
}
return 0 ;
}
static void F_42 ( struct V_1 * V_1 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_108 ; V_7 ++ )
F_43 ( V_1 -> V_109 [ V_7 ] ) ;
V_1 -> V_96 = 0 ;
}
static int F_44 ( struct V_1 * V_1 )
{
int V_7 , V_115 , V_6 , V_116 = 0 ;
if ( V_1 -> V_96 ) {
F_2 ( L_32 , V_15 ) ;
return 0 ;
}
V_1 -> V_72 = - 1 ;
V_1 -> V_86 = 0 ;
V_1 -> V_85 = 0 ;
for ( V_7 = 0 ; V_7 < V_108 ; V_7 ++ ) {
int V_117 = 0 ;
struct V_92 * V_92 = V_1 -> V_109 [ V_7 ] ;
V_92 -> V_13 = V_1 -> V_13 ;
V_92 -> V_93 = V_1 ;
V_92 -> V_118 = F_33 ;
V_92 -> V_119 = V_1 -> V_120 ;
V_92 -> V_121 = V_122 ;
V_92 -> V_123 = 1 ;
V_92 -> V_98 = V_111 ;
V_92 -> V_124 =
V_110 * V_111 ;
V_92 -> V_104 = V_1 -> V_112 + V_116 ;
V_116 += V_110 * V_111 ;
for ( V_115 = 0 ; V_115 < V_111 ; V_115 ++ ) {
V_92 -> V_103 [ V_115 ] . V_105 = V_117 ;
V_92 -> V_103 [ V_115 ] . V_125 = V_110 ;
V_117 += V_110 ;
}
}
for ( V_7 = 0 ; V_7 < V_108 ; V_7 ++ ) {
if ( ( V_6 = F_35 ( V_1 -> V_109 [ V_7 ] , V_107 ) ) ) {
F_42 ( V_1 ) ;
F_2
( L_33 ,
V_15 , V_7 , V_6 ) ;
return V_6 ;
}
}
V_1 -> V_96 = 1 ;
return 0 ;
}
static void F_28 ( struct V_126 * V_127 , const T_1 * V_2 ,
int V_3 )
{
V_127 -> V_128 . V_129 ( V_2 , V_3 , 0 , 0 , & V_127 -> V_130 . V_129 , 0 ) ;
}
static void F_27 ( struct V_126 * V_127 , const T_1 * V_2 ,
int V_3 )
{
#error TODO: handle ugly stuff
}
static int F_45 ( struct V_126 * V_127 )
{
struct V_1 * V_1 = (struct V_1 * ) V_127 -> V_131 ;
int V_132 = 1 ;
F_5 ( L_34 ) ;
switch ( V_127 -> type ) {
case V_133 :
break;
case V_134 :
break;
default:
return - V_26 ;
}
if ( V_127 -> type == V_133 ) {
switch ( V_127 -> V_135 ) {
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
break;
default:
return - V_26 ;
}
}
#ifdef F_26
#error TODO: allocate filters
if ( V_127 -> type == V_133 ) {
V_132 = 1 ;
} else if ( V_127 -> type == V_134 ) {
V_132 = 2 ;
}
#endif
F_14 ( V_1 , V_127 -> V_141 , V_132 , V_127 -> V_45 ) ;
if ( 0 == V_1 -> V_142 ++ )
F_44 ( V_1 ) ;
return 0 ;
}
static int F_46 ( struct V_126 * V_127 )
{
struct V_1 * V_1 = (struct V_1 * ) V_127 -> V_131 ;
F_15 ( V_1 , V_127 -> V_141 ) ;
if ( -- V_1 -> V_142 == 0 )
F_42 ( V_1 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_1 )
{
F_48 ( V_1 -> V_13 , 1 , 1 ) ;
V_1 -> V_14 = F_49 ( V_1 -> V_13 , 1 ) ;
V_1 -> V_16 = F_50 ( V_1 -> V_13 , 1 ) ;
V_1 -> V_120 = F_51 ( V_1 -> V_13 , 2 ) ;
return 0 ;
}
static T_5 F_52 ( struct V_28 * V_29 )
{
return V_143 ;
}
static int F_53 ( struct V_59 * V_60 )
{
struct V_144 * V_145 = & V_60 -> V_146 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_2 [ 4 ] ;
struct V_30 V_31 = { . V_18 = 0x61 , . V_35 = 0 , . V_37 = V_2 , . V_3 =sizeof( V_2 ) } ;
T_5 div ;
div = ( V_145 -> V_147 + 36166667 ) / 166667 ;
V_2 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_2 [ 1 ] = div & 0xff ;
V_2 [ 2 ] = ( ( div >> 10 ) & 0x60 ) | 0x85 ;
V_2 [ 3 ] = V_145 -> V_147 < 592000000 ? 0x40 : 0x80 ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_31 , 1 ) != 1 ) return - V_151 ;
return 0 ;
}
static int F_55 ( struct V_59 * V_60 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
static T_1 V_152 [] = { 0x0b , 0xf5 , 0x85 , 0xab } ;
static T_1 V_153 [] = { 0x1d , 0x74 , 0xa0 , 0x68 } ;
struct V_30 V_154 = { . V_18 = 0x60 , . V_35 = 0 , . V_37 = V_152 , . V_3 =sizeof( V_152 ) } ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_154 , 1 ) != 1 ) return - V_151 ;
F_56 ( 1 ) ;
V_154 . V_18 = 0x65 ;
V_154 . V_37 = V_153 ;
V_154 . V_3 = sizeof( V_153 ) ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_154 , 1 ) != 1 ) {
F_54 ( & V_1 -> V_150 , & V_154 , 1 ) ;
}
return 0 ;
}
static int F_57 ( struct V_59 * V_60 )
{
struct V_144 * V_145 = & V_60 -> V_146 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_155 [ 4 ] ;
struct V_30 V_154 = { . V_18 = 0x60 , . V_35 = 0 , . V_37 = V_155 , . V_3 =sizeof( V_155 ) } ;
int V_156 = 0 ;
T_1 V_157 , V_158 , V_49 ;
V_156 = V_145 -> V_147 + 36130000 ;
if ( V_156 < 87000000 ) return - V_26 ;
else if ( V_156 < 130000000 ) V_158 = 3 ;
else if ( V_156 < 160000000 ) V_158 = 5 ;
else if ( V_156 < 200000000 ) V_158 = 6 ;
else if ( V_156 < 290000000 ) V_158 = 3 ;
else if ( V_156 < 420000000 ) V_158 = 5 ;
else if ( V_156 < 480000000 ) V_158 = 6 ;
else if ( V_156 < 620000000 ) V_158 = 3 ;
else if ( V_156 < 830000000 ) V_158 = 5 ;
else if ( V_156 < 895000000 ) V_158 = 7 ;
else return - V_26 ;
if ( V_145 -> V_147 < 49000000 )
return - V_26 ;
else if ( V_145 -> V_147 < 159000000 )
V_157 = 1 ;
else if ( V_145 -> V_147 < 444000000 )
V_157 = 2 ;
else if ( V_145 -> V_147 < 861000000 )
V_157 = 4 ;
else return - V_26 ;
switch ( V_145 -> V_159 ) {
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
V_156 = ( ( ( V_145 -> V_147 / 1000 ) * 6 ) + 217280 ) / 1000 ;
V_155 [ 0 ] = V_156 >> 8 ;
V_155 [ 1 ] = V_156 & 0xff ;
V_155 [ 2 ] = 0xca ;
V_155 [ 3 ] = ( V_158 << 5 ) | ( V_49 << 3 ) | V_157 ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_154 , 1 ) != 1 )
return - V_151 ;
F_56 ( 1 ) ;
return 0 ;
}
static int F_59 ( struct V_59 * V_60 , const struct V_38 * * V_39 , char * V_160 )
{
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
return F_12 ( V_39 , V_160 , & V_1 -> V_13 -> V_13 ) ;
}
static int F_60 ( struct V_59 * V_60 , T_5 V_161 , T_5 V_162 )
{
T_1 V_163 = 0 ;
T_1 V_164 = 0 ;
if ( V_161 < 1500000 ) {
V_163 = 0xb7 ;
V_164 = 0x47 ;
} else if ( V_161 < 3000000 ) {
V_163 = 0xb7 ;
V_164 = 0x4b ;
} else if ( V_161 < 7000000 ) {
V_163 = 0xb7 ;
V_164 = 0x4f ;
} else if ( V_161 < 14000000 ) {
V_163 = 0xb7 ;
V_164 = 0x53 ;
} else if ( V_161 < 30000000 ) {
V_163 = 0xb6 ;
V_164 = 0x53 ;
} else if ( V_161 < 45000000 ) {
V_163 = 0xb4 ;
V_164 = 0x51 ;
}
F_61 ( V_60 , 0x13 , V_163 ) ;
F_61 ( V_60 , 0x14 , V_164 ) ;
F_61 ( V_60 , 0x1f , ( V_162 >> 16 ) & 0xff ) ;
F_61 ( V_60 , 0x20 , ( V_162 >> 8 ) & 0xff ) ;
F_61 ( V_60 , 0x21 , ( V_162 ) & 0xf0 ) ;
return 0 ;
}
static int F_62 ( struct V_59 * V_60 )
{
struct V_144 * V_145 = & V_60 -> V_146 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_37 [ 4 ] ;
T_5 div ;
struct V_30 V_31 = { . V_18 = 0x61 , . V_35 = 0 , . V_37 = V_37 , . V_3 = sizeof( V_37 ) } ;
if ( ( V_145 -> V_147 < 950000 ) || ( V_145 -> V_147 > 2150000 ) )
return - V_26 ;
div = ( V_145 -> V_147 + ( 125 - 1 ) ) / 125 ;
V_37 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_37 [ 1 ] = div & 0xff ;
V_37 [ 2 ] = 0x80 | ( ( div & 0x18000 ) >> 10 ) | 4 ;
V_37 [ 3 ] = 0xC4 ;
if ( V_145 -> V_147 > 1530000 )
V_37 [ 3 ] = 0xC0 ;
if ( V_1 -> V_58 == V_165 )
V_37 [ 3 ] |= 0x20 ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_31 , 1 ) != 1 )
return - V_151 ;
return 0 ;
}
static int F_63 ( struct V_59 * V_60 )
{
struct V_144 * V_145 = & V_60 -> V_146 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_37 [ 4 ] ;
T_5 div ;
struct V_30 V_31 = { . V_18 = 0x61 , . V_35 = 0 , . V_37 = V_37 , . V_3 = sizeof( V_37 ) } ;
div = V_145 -> V_147 / 125 ;
V_37 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_37 [ 1 ] = div & 0xff ;
V_37 [ 2 ] = 0x8e ;
V_37 [ 3 ] = 0x00 ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_31 , 1 ) != 1 )
return - V_151 ;
return 0 ;
}
static int F_64 ( struct V_59 * V_60 )
{
struct V_144 * V_145 = & V_60 -> V_146 ;
struct V_1 * V_1 = V_60 -> V_63 -> V_64 ;
T_5 div ;
T_1 V_2 [ 4 ] ;
struct V_30 V_31 = { . V_18 = 0x62 , . V_35 = 0 , . V_37 = V_2 , . V_3 = sizeof( V_2 ) } ;
div = ( V_145 -> V_147 + 35937500 + 31250 ) / 62500 ;
V_2 [ 0 ] = ( div >> 8 ) & 0x7f ;
V_2 [ 1 ] = div & 0xff ;
V_2 [ 2 ] = 0x85 | ( ( div >> 10 ) & 0x60 ) ;
V_2 [ 3 ] = ( V_145 -> V_147 < 174000000 ? 0x88 : V_145 -> V_147 < 470000000 ? 0x84 : 0x81 ) ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_31 , 1 ) != 1 )
return - V_151 ;
return 0 ;
}
static T_1 F_65 ( struct V_1 * V_1 )
{
T_1 V_23 = 0xff ;
T_1 V_166 ;
struct V_30 V_31 [] = { { . V_18 = 0x50 , . V_35 = 0 , . V_37 = & V_23 , . V_3 = 1 } ,
{ . V_18 = 0x50 , . V_35 = V_36 , . V_37 = & V_166 , . V_3 = 1 } } ;
if ( ( F_54 ( & V_1 -> V_150 , V_31 , 2 ) != 2 ) || ( V_166 == 0xff ) )
V_166 = 0x48 ;
return V_166 ;
}
static int F_66 ( struct V_59 * V_60 )
{
struct V_144 * V_145 = & V_60 -> V_146 ;
struct V_1 * V_1 = (struct V_1 * ) V_60 -> V_63 -> V_64 ;
T_1 V_155 [ 5 ] ;
struct V_30 V_154 = { . V_18 = 0x60 ,
. V_35 = 0 ,
. V_37 = V_155 ,
. V_3 = sizeof( V_155 ) } ;
int V_156 = 0 ;
T_1 V_157 , V_158 , V_49 ;
V_156 = V_145 -> V_147 ;
if ( V_156 < 87000000 ) { return - V_26 ; }
else if ( V_156 < 130000000 ) { V_158 = 3 ; V_157 = 1 ; }
else if ( V_156 < 160000000 ) { V_158 = 5 ; V_157 = 1 ; }
else if ( V_156 < 200000000 ) { V_158 = 6 ; V_157 = 1 ; }
else if ( V_156 < 290000000 ) { V_158 = 3 ; V_157 = 2 ; }
else if ( V_156 < 420000000 ) { V_158 = 5 ; V_157 = 2 ; }
else if ( V_156 < 480000000 ) { V_158 = 6 ; V_157 = 2 ; }
else if ( V_156 < 620000000 ) { V_158 = 3 ; V_157 = 4 ; }
else if ( V_156 < 830000000 ) { V_158 = 5 ; V_157 = 4 ; }
else if ( V_156 < 895000000 ) { V_158 = 7 ; V_157 = 4 ; }
else { return - V_26 ; }
V_49 = 1 ;
V_156 = ( ( V_145 -> V_147 + 36125000 ) / 62500 ) ;
V_155 [ 0 ] = V_156 >> 8 ;
V_155 [ 1 ] = V_156 & 0xff ;
V_155 [ 2 ] = 0xc8 ;
V_155 [ 3 ] = ( V_158 << 5 ) | ( V_49 << 3 ) | V_157 ;
V_155 [ 4 ] = 0x80 ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_154 , 1 ) != 1 ) {
F_2 ( L_35 ) ;
return - V_151 ;
}
F_56 ( 50 ) ;
if ( V_60 -> V_148 . V_149 )
V_60 -> V_148 . V_149 ( V_60 , 1 ) ;
if ( F_54 ( & V_1 -> V_150 , & V_154 , 1 ) != 1 ) {
F_2 ( L_36 ) ;
return - V_151 ;
}
F_56 ( 1 ) ;
return 0 ;
}
static void F_67 ( struct V_1 * V_1 )
{
switch( F_68 ( V_1 -> V_13 -> V_167 . V_168 ) ) {
case 0x1003 :
V_1 -> V_60 = F_69 ( V_169 , & V_170 , & V_1 -> V_150 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_148 . V_171 . V_172 = F_62 ;
if( V_1 -> V_58 == V_165 ) {
V_170 . V_173 = V_174 ;
F_69 ( V_175 , V_1 -> V_60 , & V_1 -> V_150 , 0 , 0 ) ;
} else {
V_1 -> V_60 -> V_148 . V_176 = F_21 ;
}
break;
}
V_1 -> V_60 = F_69 ( V_177 , & V_178 , & V_1 -> V_150 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_148 . V_171 . V_172 = F_63 ;
V_1 -> V_60 -> V_148 . V_176 = F_21 ;
break;
}
break;
case 0x1004 :
V_1 -> V_60 = F_69 ( V_179 , & V_180 , & V_1 -> V_150 , F_65 ( V_1 ) ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_148 . V_171 . V_172 = F_64 ;
break;
}
V_1 -> V_60 = F_69 ( V_181 , & V_182 , & V_1 -> V_150 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_148 . V_171 . V_172 = F_66 ;
break;
}
break;
case 0x1005 :
V_1 -> V_60 = F_69 ( V_183 , & V_184 , & V_1 -> V_150 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_148 . V_171 . V_172 = F_53 ;
break;
}
V_1 -> V_60 = F_69 ( V_185 , & V_186 , & V_1 -> V_150 ) ;
if ( V_1 -> V_60 != NULL ) {
V_1 -> V_60 -> V_148 . V_171 . V_187 = F_55 ;
V_1 -> V_60 -> V_148 . V_171 . V_172 = F_57 ;
break;
}
break;
}
if ( V_1 -> V_60 == NULL ) {
F_2 ( L_37 ,
F_68 ( V_1 -> V_13 -> V_167 . V_188 ) ,
F_68 ( V_1 -> V_13 -> V_167 . V_168 ) ) ;
} else {
if ( F_70 ( & V_1 -> V_29 , V_1 -> V_60 ) ) {
F_2 ( L_38 ) ;
F_71 ( V_1 -> V_60 ) ;
V_1 -> V_60 = NULL ;
}
}
}
static int F_72 ( struct V_189 * V_190 , const struct V_191 * V_24 )
{
struct V_192 * V_193 ;
struct V_1 * V_1 ;
int V_194 ;
F_5 ( L_39 , V_15 ) ;
V_193 = F_73 ( V_190 ) ;
if ( V_190 -> V_195 -> V_196 . V_197 != 1 ) return - V_198 ;
if ( ! ( V_1 = F_74 ( sizeof( struct V_1 ) , V_199 ) ) )
return - V_114 ;
V_1 -> V_13 = V_193 ;
V_1 -> V_25 = 0 ;
V_1 -> V_85 = 0 ;
F_75 ( & V_1 -> V_34 ) ;
F_76 ( & V_1 -> V_34 ) ;
F_75 ( & V_1 -> V_11 ) ;
F_47 ( V_1 ) ;
V_194 = F_39 ( V_1 ) ;
if ( V_194 < 0 ) {
F_5 ( L_40 , V_15 ) ;
F_6 ( & V_1 -> V_34 ) ;
F_77 ( V_1 ) ;
return V_194 ;
}
if ( F_18 ( V_1 ) )
F_2 ( L_41 ) ;
F_6 ( & V_1 -> V_34 ) ;
V_194 = F_78 ( & V_1 -> V_29 ,
L_42 ,
V_200 , & V_193 -> V_13 , V_201 ) ;
if ( V_194 < 0 ) {
F_36 ( V_1 ) ;
F_77 ( V_1 ) ;
return V_194 ;
}
V_1 -> V_29 . V_64 = V_1 ;
memset ( & V_1 -> V_150 , 0 , sizeof( struct V_28 ) ) ;
strcpy ( V_1 -> V_150 . V_160 , L_43 ) ;
F_79 ( & V_1 -> V_150 , V_1 ) ;
V_1 -> V_150 . V_202 = & V_203 ;
V_1 -> V_150 . V_204 = NULL ;
V_1 -> V_150 . V_13 . V_205 = & V_193 -> V_13 ;
V_194 = F_80 ( & V_1 -> V_150 ) ;
if ( V_194 )
goto V_206;
memset ( & V_1 -> V_82 , 0 , sizeof( V_1 -> V_82 ) ) ;
V_1 -> V_82 . V_207 . V_208 =
V_209 | V_210 ;
V_1 -> V_82 . V_64 = NULL ;
#ifdef F_26
V_1 -> V_82 . V_211 = V_212 ;
#else
V_1 -> V_82 . V_211 = 32 ;
#endif
V_1 -> V_82 . V_213 = V_79 ;
V_1 -> V_82 . V_214 = F_45 ;
V_1 -> V_82 . V_215 = F_46 ;
V_1 -> V_82 . V_216 = NULL ;
V_194 = F_81 ( & V_1 -> V_82 ) ;
if ( V_194 < 0 ) {
F_2 ( L_44 , V_194 ) ;
V_194 = - V_198 ;
goto V_217;
}
V_1 -> V_218 . V_211 = V_1 -> V_82 . V_211 ;
V_1 -> V_218 . V_131 = & V_1 -> V_82 . V_207 ;
V_1 -> V_218 . V_208 = 0 ;
V_194 = F_82 ( & V_1 -> V_218 , & V_1 -> V_29 ) ;
if ( V_194 < 0 ) {
F_2 ( L_45 ,
V_194 ) ;
V_194 = - V_198 ;
goto V_219;
}
if ( F_83 ( & V_1 -> V_29 , & V_1 -> V_220 , & V_1 -> V_82 . V_207 ) ) {
F_2 ( L_46 ) ;
V_194 = - V_198 ;
goto V_221;
}
F_84 ( V_190 , ( void * ) V_1 ) ;
F_67 ( V_1 ) ;
return 0 ;
V_221:
F_85 ( & V_1 -> V_218 ) ;
V_219:
F_86 ( & V_1 -> V_82 ) ;
V_217:
F_87 ( & V_1 -> V_150 ) ;
V_206:
F_88 ( & V_1 -> V_29 ) ;
F_36 ( V_1 ) ;
F_77 ( V_1 ) ;
return V_194 ;
}
static void F_89 ( struct V_189 * V_190 )
{
struct V_1 * V_1 = F_90 ( V_190 ) ;
F_84 ( V_190 , NULL ) ;
V_1 -> V_222 = 1 ;
F_42 ( V_1 ) ;
V_1 -> V_82 . V_207 . V_223 ( & V_1 -> V_82 . V_207 ) ;
F_91 ( & V_1 -> V_220 ) ;
F_85 ( & V_1 -> V_218 ) ;
F_86 ( & V_1 -> V_82 ) ;
if ( V_1 -> V_60 != NULL ) {
F_92 ( V_1 -> V_60 ) ;
F_71 ( V_1 -> V_60 ) ;
}
F_87 ( & V_1 -> V_150 ) ;
F_88 ( & V_1 -> V_29 ) ;
F_36 ( V_1 ) ;
F_77 ( V_1 ) ;
F_5 ( L_47 , V_15 ) ;
}

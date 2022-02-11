static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
unsigned int V_7 ;
int V_8 ;
V_4 -> V_6 = V_6 ;
V_8 = F_2 ( V_2 , V_6 , V_9 , & V_7 ) ;
if ( V_8 < 0 ) {
F_3 ( V_2 -> V_10 -> V_11 , L_1 , V_6 ) ;
return V_8 ;
}
V_7 &= 0x00f00fff ;
if ( V_7 == 0x00400200 )
V_4 -> V_12 = false ;
else if ( V_7 == 0x0040000a && V_5 == V_13 )
V_4 -> V_12 = true ;
else if ( V_7 == 0x0040000c && V_5 == V_14 )
V_4 -> V_12 = true ;
else {
F_3 ( V_2 -> V_10 -> V_11 , L_2 , V_7 , V_6 ) ;
return - V_15 ;
}
if ( ! V_4 -> V_12 )
return 0 ;
if ( V_5 == V_14 )
V_8 = F_2 ( V_2 , V_6 , V_16 , & V_7 ) ;
else
V_8 = F_2 ( V_2 , V_6 , V_17 , & V_7 ) ;
if ( V_8 < 0 ) {
F_3 ( V_2 -> V_10 -> V_11 , L_3 , V_6 ) ;
return V_8 ;
}
V_4 -> V_18 = F_4 ( V_7 ) ;
V_4 -> V_19 = F_5 ( V_7 ) ;
V_4 -> V_20 = F_6 ( V_7 ) ;
if ( V_4 -> V_20 ) {
V_4 -> V_20 ++ ;
V_4 -> V_19 ++ ;
}
V_4 -> V_21 = F_7 ( V_7 ) ;
V_8 = F_8 ( V_2 , V_6 , V_22 , 0 , 0 , & V_7 ,
NULL ) ;
if ( V_8 < 0 ) {
F_3 ( V_2 -> V_10 -> V_11 , L_4 , V_6 ) ;
return V_8 ;
}
V_4 -> V_23 = V_7 & 0x3ff ;
V_4 -> V_24 = 0 ;
V_4 -> V_25 = 0 ;
V_4 -> V_26 = 0 ;
return 0 ;
}
int F_9 ( struct V_1 * V_2 , int V_5 , int * V_27 )
{
int V_28 , V_8 , V_6 ;
V_6 = * V_27 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 [ V_5 ] . V_29 ; V_28 ++ , V_6 ++ ) {
V_8 = F_1 ( V_2 , & V_2 -> V_4 [ V_5 ] . V_30 [ V_28 ] , V_5 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_4 [ V_5 ] . V_30 [ V_28 ] . V_12 )
V_2 -> V_4 [ V_5 ] . V_31 ++ ;
}
* V_27 = V_6 ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_32 . V_33 ) ;
}
int F_12 ( struct V_1 * V_2 , int V_6 )
{
unsigned int V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 , V_6 , V_9 , & V_7 ) ;
if ( V_8 < 0 ) {
F_3 ( V_2 -> V_10 -> V_11 , L_1 , V_6 ) ;
return V_8 ;
}
if ( ( V_7 & 0xfff00000 ) != 0x02f00000 ) {
F_13 ( V_2 -> V_10 -> V_11 , L_5 ) ;
return 0 ;
}
V_2 -> V_32 . V_6 = V_6 ;
V_2 -> V_32 . V_34 = V_7 ;
V_2 -> V_32 . V_35 = (struct V_36 V_37 * )
( V_2 -> V_38 [ V_39 ] . V_40 + V_41 ) ;
V_2 -> V_32 . V_33 = F_14 ( sizeof( struct V_36 ) ) ;
V_2 -> V_32 . V_42 = V_2 -> V_43 [ V_14 ] . V_44 ;
V_2 -> V_32 . V_45 = V_2 -> V_4 [ V_13 ] . V_29 ;
V_2 -> V_32 . V_46 = V_2 -> V_43 [ V_13 ] . V_44 ;
V_2 -> V_32 . V_47 = V_2 -> V_4 [ V_14 ] . V_29 ;
V_2 -> V_32 . V_48 = V_2 -> V_32 . V_45 +
F_15 ( V_7 ) ;
V_2 -> V_32 . V_49 = V_2 -> V_32 . V_46 +
F_16 ( V_7 ) ;
if ( V_2 -> V_32 . V_48 > V_50 ||
V_2 -> V_32 . V_49 > V_51 ) {
F_3 ( V_2 -> V_10 -> V_11 , L_6 ) ;
return - V_15 ;
}
V_2 -> V_32 . V_52 = ( ( 1U << V_2 -> V_32 . V_45 ) - 1 ) |
( ( ( 1U << V_2 -> V_32 . V_42 ) - 1 )
<< V_2 -> V_32 . V_48 ) ;
V_2 -> V_32 . V_53 = ( ( 1U << V_2 -> V_32 . V_46 ) - 1 ) |
( ( ( 1U << V_2 -> V_32 . V_47 ) - 1 )
<< V_2 -> V_32 . V_49 ) ;
F_13 ( V_2 -> V_10 -> V_11 , L_7 ,
V_2 -> V_32 . V_52 , V_2 -> V_32 . V_53 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_54 ,
unsigned short V_55 , bool V_56 )
{
unsigned int V_57 , V_7 ;
if ( ! ( V_2 -> V_32 . V_52 & ( 1 << V_54 ) ) )
return - V_15 ;
V_57 = V_7 = F_18 ( & V_2 -> V_32 . V_35 -> V_58 ) ;
if ( V_56 )
V_7 |= ( 1 << V_54 ) ;
else
V_7 &= ~ ( 1 << V_54 ) ;
if ( ( V_7 == V_57 ) &&
( V_55 == F_19 ( & V_2 -> V_32 . V_35 -> V_59 [ V_54 ] ) ) )
return 0 ;
F_13 ( V_2 -> V_10 -> V_11 ,
L_8 ,
V_54 , V_55 , V_7 ) ;
F_20 ( V_55 , & V_2 -> V_32 . V_35 -> V_59 [ V_54 ] ) ;
F_21 ( V_7 , & V_2 -> V_32 . V_35 -> V_58 ) ;
F_22 ( V_2 ) ;
return F_23 ( V_2 , V_2 -> V_32 . V_6 ,
V_60 , V_54 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned int V_61 , unsigned int V_62 ,
unsigned short V_55 , bool V_56 )
{
unsigned int V_7 ;
if ( ! ( V_2 -> V_32 . V_52 & ( 1 << V_61 ) ) ||
! ( V_2 -> V_32 . V_53 & ( 1 << V_62 ) ) )
return - V_15 ;
if ( V_56 )
F_20 ( V_55 , & V_2 -> V_32 . V_35 -> V_63 [ V_62 ] [ V_61 ] ) ;
V_7 = F_18 ( & V_2 -> V_32 . V_35 -> V_64 [ V_62 ] ) ;
if ( V_56 )
V_7 |= ( 1 << V_61 ) ;
else
V_7 &= ~ ( 1 << V_61 ) ;
F_21 ( V_7 , & V_2 -> V_32 . V_35 -> V_64 [ V_62 ] ) ;
F_22 ( V_2 ) ;
return F_23 ( V_2 , V_2 -> V_32 . V_6 , V_65 ,
V_61 , V_62 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_5 , bool V_66 )
{
struct V_3 * V_4 ;
int V_67 , V_68 ;
V_4 = V_2 -> V_4 [ V_5 ] . V_30 ;
V_68 = V_2 -> V_4 [ V_5 ] . V_29 ;
for ( V_67 = 0 ; V_67 < V_68 ; V_67 ++ ) {
if ( V_4 [ V_67 ] . V_12 ) {
unsigned int V_7 = V_66 ? 0 : V_4 [ V_67 ] . V_26 ;
F_26 ( V_2 , V_5 , V_67 , V_7 , false ) ;
}
}
return F_22 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 . V_33 ) {
F_28 ( V_2 -> V_32 . V_33 , V_2 -> V_32 . V_35 ,
sizeof( * V_2 -> V_32 . V_35 ) ) ;
}
F_25 ( V_2 , V_14 , true ) ;
}
void F_29 ( struct V_1 * V_2 )
{
int V_28 ;
if ( V_2 -> V_32 . V_33 ) {
F_30 ( V_2 -> V_32 . V_35 , V_2 -> V_32 . V_33 ,
sizeof( * V_2 -> V_32 . V_35 ) ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_45 ; V_28 ++ )
F_23 ( V_2 , V_2 -> V_32 . V_6 ,
V_60 ,
V_28 , 0 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_42 ; V_28 ++ )
F_23 ( V_2 , V_2 -> V_32 . V_6 ,
V_60 ,
V_2 -> V_32 . V_48 + V_28 , 0 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_46 ; V_28 ++ )
F_23 ( V_2 , V_2 -> V_32 . V_6 ,
V_69 ,
V_28 , 0 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_47 ; V_28 ++ )
F_23 ( V_2 , V_2 -> V_32 . V_6 ,
V_69 ,
V_2 -> V_32 . V_49 + V_28 , 0 ) ;
F_22 ( V_2 ) ;
}
}
static int F_26 ( struct V_1 * V_2 , int V_5 ,
unsigned int V_67 , unsigned int V_7 ,
bool V_70 )
{
struct V_3 * V_4 ;
int V_8 ;
if ( V_67 >= V_2 -> V_4 [ V_5 ] . V_29 )
return - V_15 ;
V_4 = & V_2 -> V_4 [ V_5 ] . V_30 [ V_67 ] ;
if ( ! V_4 -> V_12 || V_4 -> V_20 <= V_7 )
return - V_15 ;
if ( V_70 && V_4 -> V_26 == V_7 )
return 0 ;
if ( V_70 )
F_22 ( V_2 ) ;
F_13 ( V_2 -> V_10 -> V_11 ,
L_9 ,
V_5 , V_67 , V_7 ) ;
V_8 = F_23 ( V_2 , V_4 -> V_6 ,
V_71 , V_7 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_70 )
V_4 -> V_26 = V_7 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_52 , bool V_72 )
{
int V_73 = 0 ;
int V_74 = 0 ;
int V_75 , V_8 ;
if ( ( V_2 -> V_76 & V_52 ) != V_52 )
return - V_15 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_4 [ V_13 ] . V_29 ; V_75 += 2 ) {
unsigned int V_77 = 3U << V_75 ;
unsigned int V_78 , V_79 ;
if ( ! ( V_2 -> V_76 & V_77 ) )
continue;
V_78 = ( V_52 & V_77 ) != 0 ;
if ( V_72 ) {
V_79 = ( V_2 -> V_80 & V_77 ) != 0 ;
if ( V_79 == V_78 )
continue;
}
V_8 = F_23 ( V_2 , V_2 -> V_43 [ V_13 ] . V_81 [ V_75 ] . V_6 ,
V_82 , V_78 , 0 ) ;
if ( ! V_8 )
V_74 ++ ;
else
V_73 = V_8 ;
}
if ( V_74 )
V_73 = F_22 ( V_2 ) ;
if ( ! V_73 )
V_2 -> V_80 = V_52 ;
return V_73 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_28 ;
F_31 ( V_2 , ( 1 << V_2 -> V_4 [ V_13 ] . V_29 ) - 1 , false ) ;
F_33 ( V_2 -> V_32 . V_35 , 0 , sizeof( * V_2 -> V_32 . V_35 ) ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_46 ; V_28 ++ )
F_23 ( V_2 , V_2 -> V_32 . V_6 ,
V_69 ,
V_28 , 0 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_47 ; V_28 ++ )
F_23 ( V_2 , V_2 -> V_32 . V_6 ,
V_69 ,
V_2 -> V_32 . V_49 + V_28 , 0 ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_45 ; V_28 ++ )
F_17 ( V_2 , V_28 , 336 , true ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_42 ; V_28 ++ )
F_17 ( V_2 ,
V_28 + V_2 -> V_32 . V_48 ,
336 , true ) ;
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_46 ; V_28 ++ ) {
int V_61 = V_28 % V_2 -> V_32 . V_45 ;
F_24 ( V_2 , V_61 , V_28 , 336 , true ) ;
}
for ( V_28 = 0 ; V_28 < V_2 -> V_32 . V_42 ; V_28 ++ ) {
int V_61 = V_2 -> V_32 . V_48 + V_28 ;
int V_83 = V_2 -> V_32 . V_49 +
V_28 % V_2 -> V_32 . V_47 ;
F_24 ( V_2 , V_61 , V_83 , 336 , true ) ;
}
return 0 ;
}
static int F_34 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
int V_5 = V_85 -> V_88 ;
V_87 -> type = V_89 ;
V_87 -> V_90 = V_2 -> V_4 [ V_5 ] . V_29 ;
V_87 -> V_91 . integer . V_92 = 0 ;
V_87 -> V_91 . integer . V_93 = V_2 -> V_4 [ V_5 ] . V_30 [ 0 ] . V_20 ;
return 0 ;
}
static int F_36 ( struct V_84 * V_85 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
int V_5 = V_85 -> V_88 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 [ V_5 ] . V_29 ; V_28 ++ )
V_95 -> V_91 . integer . V_91 [ V_28 ] =
V_2 -> V_4 [ V_5 ] . V_30 [ V_28 ] . V_26 ;
return 0 ;
}
static int F_37 ( struct V_84 * V_85 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
int V_5 = V_85 -> V_88 ;
int V_28 , V_8 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 [ V_5 ] . V_29 ; V_28 ++ ) {
V_8 = F_26 ( V_2 , V_5 , V_28 ,
V_95 -> V_91 . integer . V_91 [ V_28 ] ,
true ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_38 ( struct V_84 * V_85 , int V_96 ,
unsigned int V_97 , unsigned int T_1 * V_98 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
int V_5 = V_85 -> V_88 ;
unsigned int V_99 , V_100 ;
struct V_3 * V_4 ;
if ( V_97 < 4 * sizeof( unsigned int ) )
return - V_101 ;
V_4 = & V_2 -> V_4 [ V_5 ] . V_30 [ 0 ] ;
V_100 = V_4 -> V_19 * 25 ;
V_99 = - 1 * ( int ) V_4 -> V_21 * ( int ) V_100 ;
#ifdef F_39
V_100 |= F_39 ;
#endif
if ( F_40 ( V_102 , V_98 ) )
return - V_103 ;
if ( F_40 ( 2 * sizeof( unsigned int ) , V_98 + 1 ) )
return - V_103 ;
if ( F_40 ( V_99 , V_98 + 2 ) )
return - V_103 ;
if ( F_40 ( V_100 , V_98 + 3 ) )
return - V_103 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , int V_5 , char * V_104 )
{
if ( ! V_2 -> V_4 [ V_5 ] . V_29 )
return 0 ;
if ( V_2 -> V_4 [ V_5 ] . V_29 != V_2 -> V_4 [ V_5 ] . V_31 )
return 0 ;
V_105 . V_104 = V_104 ;
V_105 . V_88 = V_5 ;
return F_42 ( V_2 -> V_10 ,
F_43 ( & V_105 , V_2 ) ) ;
}
static int F_44 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
V_87 -> type = V_106 ;
V_87 -> V_90 = V_2 -> V_4 [ V_13 ] . V_29 ;
V_87 -> V_91 . integer . V_92 = 0 ;
V_87 -> V_91 . integer . V_93 = 1 ;
return 0 ;
}
static int F_45 ( struct V_84 * V_85 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 [ V_13 ] . V_29 ; V_28 ++ )
V_95 -> V_91 . integer . V_91 [ V_28 ] =
! ! ( V_2 -> V_80 & ( 1 << V_28 ) ) ;
return 0 ;
}
static int F_46 ( struct V_84 * V_85 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
int V_28 ;
unsigned int V_77 ;
V_77 = 0 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_4 [ V_13 ] . V_29 ; V_28 ++ )
if ( V_95 -> V_91 . integer . V_91 [ V_28 ] )
V_77 |= 1 << V_28 ;
return F_31 ( V_2 , V_77 , true ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_76 )
return 0 ;
return F_42 ( V_2 -> V_10 ,
F_43 ( & V_107 , V_2 ) ) ;
}
static int F_48 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
unsigned int V_90 = ( V_85 -> V_88 >> 8 ) & 0xff ;
V_87 -> type = V_89 ;
V_87 -> V_90 = V_90 ;
V_87 -> V_91 . integer . V_92 = 0 ;
V_87 -> V_91 . integer . V_93 = 409 ;
return 0 ;
}
static int F_49 ( struct V_84 * V_85 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
unsigned int V_108 = V_85 -> V_88 & 0xff ;
unsigned int V_90 = ( V_85 -> V_88 >> 8 ) & 0xff ;
unsigned int V_77 , V_28 ;
V_77 = F_18 ( & V_2 -> V_32 . V_35 -> V_58 ) ;
for ( V_28 = 0 ; V_28 < V_90 ; V_28 ++ ) {
unsigned int V_67 = V_108 + V_28 ;
unsigned short V_7 ;
if ( ! ( V_2 -> V_32 . V_52 & ( 1 << V_67 ) ) )
return - V_15 ;
if ( V_77 & ( 1 << V_67 ) )
V_7 = F_19 ( & V_2 -> V_32 . V_35 -> V_59 [ V_67 ] ) + 1 ;
else
V_7 = 0 ;
V_95 -> V_91 . integer . V_91 [ V_28 ] = V_7 ;
}
return 0 ;
}
static int F_50 ( struct V_84 * V_85 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_35 ( V_85 ) ;
unsigned int V_108 = V_85 -> V_88 & 0xff ;
unsigned int V_90 = ( V_85 -> V_88 >> 8 ) & 0xff ;
int V_28 , V_8 ;
for ( V_28 = 0 ; V_28 < V_90 ; V_28 ++ ) {
unsigned int V_67 = V_108 + V_28 ;
unsigned short V_7 = V_95 -> V_91 . integer . V_91 [ V_28 ] ;
if ( V_7 )
V_7 -- ;
V_8 = F_17 ( V_2 , V_67 , V_7 , ! ! V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
int V_109 , int V_108 , char * V_104 )
{
V_110 . V_104 = V_104 ;
V_110 . V_88 = V_108 + ( V_109 << 8 ) ;
return F_42 ( V_2 -> V_10 ,
F_43 ( & V_110 , V_2 ) ) ;
}
int F_52 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_41 ( V_2 , V_14 , L_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_41 ( V_2 , V_13 , L_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_51 ( V_2 , V_2 -> V_32 . V_45 , 0 ,
L_12 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_51 ( V_2 , V_2 -> V_32 . V_42 ,
V_2 -> V_32 . V_48 ,
L_13 ) ;
if ( V_8 < 0 )
return V_8 ;
#if 0
err = create_dest_gain_mixer(chip,
chip->mixer.src_phys_ins, 0,
chip->mixer.dest_stream_ins, 0,
"Line Capture Volume");
if (err < 0)
return err;
err = create_dest_gain_mixer(chip,
chip->mixer.src_stream_outs,
chip->mixer.src_stream_out_ofs,
chip->mixer.dest_stream_ins, 0,
"Stream-Loopback Capture Volume");
if (err < 0)
return err;
err = create_dest_gain_mixer(chip,
chip->mixer.src_phys_ins, 0,
chip->mixer.dest_phys_outs,
chip->mixer.dest_phys_out_ofs,
"Line-Loopback Playback Volume");
if (err < 0)
return err;
err = create_dest_gain_mixer(chip,
chip->mixer.src_stream_outs,
chip->mixer.src_stream_out_ofs,
chip->mixer.dest_phys_outs,
chip->mixer.dest_phys_out_ofs,
"Stream Playback Volume");
if (err < 0)
return err;
#endif
return F_32 ( V_2 ) ;
}

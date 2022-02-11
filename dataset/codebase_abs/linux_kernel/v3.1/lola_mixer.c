static int T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , int V_6 )
{
unsigned int V_7 ;
int V_8 ;
V_4 -> V_6 = V_6 ;
V_8 = F_2 ( V_2 , V_6 , V_9 , & V_7 ) ;
if ( V_8 < 0 ) {
F_3 (KERN_ERR SFX L_1 , nid) ;
return V_8 ;
}
V_7 &= 0x00f00fff ;
if ( V_7 == 0x00400200 )
V_4 -> V_10 = false ;
else if ( V_7 == 0x0040000a && V_5 == V_11 )
V_4 -> V_10 = true ;
else if ( V_7 == 0x0040000c && V_5 == V_12 )
V_4 -> V_10 = true ;
else {
F_3 (KERN_ERR SFX L_2 , val, nid) ;
return - V_13 ;
}
if ( ! V_4 -> V_10 )
return 0 ;
if ( V_5 == V_12 )
V_8 = F_2 ( V_2 , V_6 , V_14 , & V_7 ) ;
else
V_8 = F_2 ( V_2 , V_6 , V_15 , & V_7 ) ;
if ( V_8 < 0 ) {
F_3 (KERN_ERR SFX L_3 , nid) ;
return V_8 ;
}
V_4 -> V_16 = F_4 ( V_7 ) ;
V_4 -> V_17 = F_5 ( V_7 ) ;
V_4 -> V_18 = F_6 ( V_7 ) ;
if ( V_4 -> V_18 ) {
V_4 -> V_18 ++ ;
V_4 -> V_17 ++ ;
}
V_4 -> V_19 = F_7 ( V_7 ) ;
V_8 = F_8 ( V_2 , V_6 , V_20 , 0 , 0 , & V_7 ,
NULL ) ;
if ( V_8 < 0 ) {
F_3 (KERN_ERR SFX L_4 , nid) ;
return V_8 ;
}
V_4 -> V_21 = V_7 & 0x3ff ;
V_4 -> V_22 = 0 ;
V_4 -> V_23 = 0 ;
V_4 -> V_24 = 0 ;
return 0 ;
}
int T_1 F_9 ( struct V_1 * V_2 , int V_5 , int * V_25 )
{
int V_26 , V_8 , V_6 ;
V_6 = * V_25 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_4 [ V_5 ] . V_27 ; V_26 ++ , V_6 ++ ) {
V_8 = F_1 ( V_2 , & V_2 -> V_4 [ V_5 ] . V_28 [ V_26 ] , V_5 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_2 -> V_4 [ V_5 ] . V_28 [ V_26 ] . V_10 )
V_2 -> V_4 [ V_5 ] . V_29 ++ ;
}
* V_25 = V_6 ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 . V_31 )
F_11 ( V_2 -> V_30 . V_31 ) ;
}
int T_1 F_12 ( struct V_1 * V_2 , int V_6 )
{
unsigned int V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 , V_6 , V_9 , & V_7 ) ;
if ( V_8 < 0 ) {
F_3 (KERN_ERR SFX L_1 , nid) ;
return V_8 ;
}
if ( ( V_7 & 0xfff00000 ) != 0x02f00000 ) {
F_13 ( L_5 ) ;
return 0 ;
}
V_2 -> V_30 . V_6 = V_6 ;
V_2 -> V_30 . V_32 = V_7 ;
V_2 -> V_30 . V_33 = (struct V_34 V_35 * )
( V_2 -> V_36 [ V_37 ] . V_38 + V_39 ) ;
V_2 -> V_30 . V_31 = F_14 ( sizeof( struct V_34 ) ) ;
V_2 -> V_30 . V_40 = V_2 -> V_41 [ V_12 ] . V_42 ;
V_2 -> V_30 . V_43 = V_2 -> V_4 [ V_11 ] . V_27 ;
V_2 -> V_30 . V_44 = V_2 -> V_41 [ V_11 ] . V_42 ;
V_2 -> V_30 . V_45 = V_2 -> V_4 [ V_12 ] . V_27 ;
V_2 -> V_30 . V_46 = V_2 -> V_30 . V_43 +
F_15 ( V_7 ) ;
V_2 -> V_30 . V_47 = V_2 -> V_30 . V_44 +
F_16 ( V_7 ) ;
if ( V_2 -> V_30 . V_46 > V_48 ||
V_2 -> V_30 . V_47 > V_49 ) {
F_3 (KERN_ERR SFX L_6 ) ;
return - V_13 ;
}
V_2 -> V_30 . V_50 = ( ( 1U << V_2 -> V_30 . V_43 ) - 1 ) |
( ( ( 1U << V_2 -> V_30 . V_40 ) - 1 )
<< V_2 -> V_30 . V_46 ) ;
V_2 -> V_30 . V_51 = ( ( 1U << V_2 -> V_30 . V_44 ) - 1 ) |
( ( ( 1U << V_2 -> V_30 . V_45 ) - 1 )
<< V_2 -> V_30 . V_47 ) ;
F_13 ( L_7 ,
V_2 -> V_30 . V_50 , V_2 -> V_30 . V_51 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_52 ,
unsigned short V_53 , bool V_54 )
{
unsigned int V_55 , V_7 ;
if ( ! ( V_2 -> V_30 . V_50 & ( 1 << V_52 ) ) )
return - V_13 ;
V_55 = V_7 = F_18 ( & V_2 -> V_30 . V_33 -> V_56 ) ;
if ( V_54 )
V_7 |= ( 1 << V_52 ) ;
else
V_7 &= ~ ( 1 << V_52 ) ;
if ( ( V_7 == V_55 ) &&
( V_53 == F_19 ( & V_2 -> V_30 . V_33 -> V_57 [ V_52 ] ) ) )
return 0 ;
F_13 ( L_8 ,
V_52 , V_53 , V_7 ) ;
F_20 ( V_53 , & V_2 -> V_30 . V_33 -> V_57 [ V_52 ] ) ;
F_21 ( V_7 , & V_2 -> V_30 . V_33 -> V_56 ) ;
F_22 ( V_2 ) ;
return F_23 ( V_2 , V_2 -> V_30 . V_6 ,
V_58 , V_52 , 0 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
unsigned int V_59 , unsigned int V_60 ,
unsigned short V_53 , bool V_54 )
{
unsigned int V_7 ;
if ( ! ( V_2 -> V_30 . V_50 & ( 1 << V_59 ) ) ||
! ( V_2 -> V_30 . V_51 & ( 1 << V_60 ) ) )
return - V_13 ;
if ( V_54 )
F_20 ( V_53 , & V_2 -> V_30 . V_33 -> V_61 [ V_60 ] [ V_59 ] ) ;
V_7 = F_18 ( & V_2 -> V_30 . V_33 -> V_62 [ V_60 ] ) ;
if ( V_54 )
V_7 |= ( 1 << V_59 ) ;
else
V_7 &= ~ ( 1 << V_59 ) ;
F_21 ( V_7 , & V_2 -> V_30 . V_33 -> V_62 [ V_60 ] ) ;
F_22 ( V_2 ) ;
return F_23 ( V_2 , V_2 -> V_30 . V_6 , V_63 ,
V_59 , V_60 ) ;
}
int F_25 ( struct V_1 * V_2 , int V_5 , bool V_64 )
{
struct V_3 * V_4 ;
int V_65 , V_66 ;
V_4 = V_2 -> V_4 [ V_5 ] . V_28 ;
V_66 = V_2 -> V_4 [ V_5 ] . V_27 ;
for ( V_65 = 0 ; V_65 < V_66 ; V_65 ++ ) {
if ( V_4 [ V_65 ] . V_10 ) {
unsigned int V_7 = V_64 ? 0 : V_4 [ V_65 ] . V_24 ;
F_26 ( V_2 , V_5 , V_65 , V_7 , false ) ;
}
}
return F_22 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_30 . V_31 ) {
F_28 ( V_2 -> V_30 . V_31 , V_2 -> V_30 . V_33 ,
sizeof( * V_2 -> V_30 . V_33 ) ) ;
}
F_25 ( V_2 , V_12 , true ) ;
}
void F_29 ( struct V_1 * V_2 )
{
int V_26 ;
if ( V_2 -> V_30 . V_31 ) {
F_30 ( V_2 -> V_30 . V_33 , V_2 -> V_30 . V_31 ,
sizeof( * V_2 -> V_30 . V_33 ) ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_43 ; V_26 ++ )
F_23 ( V_2 , V_2 -> V_30 . V_6 ,
V_58 ,
V_26 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_40 ; V_26 ++ )
F_23 ( V_2 , V_2 -> V_30 . V_6 ,
V_58 ,
V_2 -> V_30 . V_46 + V_26 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_44 ; V_26 ++ )
F_23 ( V_2 , V_2 -> V_30 . V_6 ,
V_67 ,
V_26 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_45 ; V_26 ++ )
F_23 ( V_2 , V_2 -> V_30 . V_6 ,
V_67 ,
V_2 -> V_30 . V_47 + V_26 , 0 ) ;
F_22 ( V_2 ) ;
}
}
static int F_26 ( struct V_1 * V_2 , int V_5 ,
unsigned int V_65 , unsigned int V_7 ,
bool V_68 )
{
struct V_3 * V_4 ;
int V_8 ;
if ( V_65 >= V_2 -> V_4 [ V_5 ] . V_27 )
return - V_13 ;
V_4 = & V_2 -> V_4 [ V_5 ] . V_28 [ V_65 ] ;
if ( ! V_4 -> V_10 || V_4 -> V_18 <= V_7 )
return - V_13 ;
if ( V_68 && V_4 -> V_24 == V_7 )
return 0 ;
if ( V_68 )
F_22 ( V_2 ) ;
F_13 ( L_9 ,
V_5 , V_65 , V_7 ) ;
V_8 = F_23 ( V_2 , V_4 -> V_6 ,
V_69 , V_7 , 0 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_68 )
V_4 -> V_24 = V_7 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_50 , bool V_70 )
{
int V_71 = 0 ;
int V_72 = 0 ;
int V_73 , V_8 ;
if ( ( V_2 -> V_74 & V_50 ) != V_50 )
return - V_13 ;
for ( V_73 = 0 ; V_73 < V_2 -> V_4 [ V_11 ] . V_27 ; V_73 += 2 ) {
unsigned int V_75 = 3U << V_73 ;
unsigned int V_76 , V_77 ;
if ( ! ( V_2 -> V_74 & V_75 ) )
continue;
V_76 = ( V_50 & V_75 ) != 0 ;
if ( V_70 ) {
V_77 = ( V_2 -> V_78 & V_75 ) != 0 ;
if ( V_77 == V_76 )
continue;
}
V_8 = F_23 ( V_2 , V_2 -> V_41 [ V_11 ] . V_79 [ V_73 ] . V_6 ,
V_80 , V_76 , 0 ) ;
if ( ! V_8 )
V_72 ++ ;
else
V_71 = V_8 ;
}
if ( V_72 )
V_71 = F_22 ( V_2 ) ;
if ( ! V_71 )
V_2 -> V_78 = V_50 ;
return V_71 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_26 ;
F_31 ( V_2 , ( 1 << V_2 -> V_4 [ V_11 ] . V_27 ) - 1 , false ) ;
F_33 ( V_2 -> V_30 . V_33 , 0 , sizeof( * V_2 -> V_30 . V_33 ) ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_44 ; V_26 ++ )
F_23 ( V_2 , V_2 -> V_30 . V_6 ,
V_67 ,
V_26 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_45 ; V_26 ++ )
F_23 ( V_2 , V_2 -> V_30 . V_6 ,
V_67 ,
V_2 -> V_30 . V_47 + V_26 , 0 ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_43 ; V_26 ++ )
F_17 ( V_2 , V_26 , 336 , true ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_40 ; V_26 ++ )
F_17 ( V_2 ,
V_26 + V_2 -> V_30 . V_46 ,
336 , true ) ;
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_44 ; V_26 ++ ) {
int V_59 = V_26 % V_2 -> V_30 . V_43 ;
F_24 ( V_2 , V_59 , V_26 , 336 , true ) ;
}
for ( V_26 = 0 ; V_26 < V_2 -> V_30 . V_40 ; V_26 ++ ) {
int V_59 = V_2 -> V_30 . V_46 + V_26 ;
int V_81 = V_2 -> V_30 . V_47 +
V_26 % V_2 -> V_30 . V_45 ;
F_24 ( V_2 , V_59 , V_81 , 336 , true ) ;
}
return 0 ;
}
static int F_34 ( struct V_82 * V_83 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
int V_5 = V_83 -> V_86 ;
V_85 -> type = V_87 ;
V_85 -> V_88 = V_2 -> V_4 [ V_5 ] . V_27 ;
V_85 -> V_89 . integer . V_90 = 0 ;
V_85 -> V_89 . integer . V_91 = V_2 -> V_4 [ V_5 ] . V_28 [ 0 ] . V_18 ;
return 0 ;
}
static int F_36 ( struct V_82 * V_83 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
int V_5 = V_83 -> V_86 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_4 [ V_5 ] . V_27 ; V_26 ++ )
V_93 -> V_89 . integer . V_89 [ V_26 ] =
V_2 -> V_4 [ V_5 ] . V_28 [ V_26 ] . V_24 ;
return 0 ;
}
static int F_37 ( struct V_82 * V_83 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
int V_5 = V_83 -> V_86 ;
int V_26 , V_8 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_4 [ V_5 ] . V_27 ; V_26 ++ ) {
V_8 = F_26 ( V_2 , V_5 , V_26 ,
V_93 -> V_89 . integer . V_89 [ V_26 ] ,
true ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int F_38 ( struct V_82 * V_83 , int V_94 ,
unsigned int V_95 , unsigned int T_2 * V_96 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
int V_5 = V_83 -> V_86 ;
unsigned int V_97 , V_98 ;
struct V_3 * V_4 ;
if ( V_95 < 4 * sizeof( unsigned int ) )
return - V_99 ;
V_4 = & V_2 -> V_4 [ V_5 ] . V_28 [ 0 ] ;
V_98 = V_4 -> V_17 * 25 ;
V_97 = - 1 * ( int ) V_4 -> V_19 * ( int ) V_98 ;
#ifdef F_39
V_98 |= F_39 ;
#endif
if ( F_40 ( V_100 , V_96 ) )
return - V_101 ;
if ( F_40 ( 2 * sizeof( unsigned int ) , V_96 + 1 ) )
return - V_101 ;
if ( F_40 ( V_97 , V_96 + 2 ) )
return - V_101 ;
if ( F_40 ( V_98 , V_96 + 3 ) )
return - V_101 ;
return 0 ;
}
static int T_1 F_41 ( struct V_1 * V_2 , int V_5 , char * V_102 )
{
if ( ! V_2 -> V_4 [ V_5 ] . V_27 )
return 0 ;
if ( V_2 -> V_4 [ V_5 ] . V_27 != V_2 -> V_4 [ V_5 ] . V_29 )
return 0 ;
V_103 . V_102 = V_102 ;
V_103 . V_86 = V_5 ;
return F_42 ( V_2 -> V_104 ,
F_43 ( & V_103 , V_2 ) ) ;
}
static int F_44 ( struct V_82 * V_83 ,
struct V_84 * V_85 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
V_85 -> type = V_105 ;
V_85 -> V_88 = V_2 -> V_4 [ V_11 ] . V_27 ;
V_85 -> V_89 . integer . V_90 = 0 ;
V_85 -> V_89 . integer . V_91 = 1 ;
return 0 ;
}
static int F_45 ( struct V_82 * V_83 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_4 [ V_11 ] . V_27 ; V_26 ++ )
V_93 -> V_89 . integer . V_89 [ V_26 ] =
! ! ( V_2 -> V_78 & ( 1 << V_26 ) ) ;
return 0 ;
}
static int F_46 ( struct V_82 * V_83 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
int V_26 ;
unsigned int V_75 ;
V_75 = 0 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_4 [ V_11 ] . V_27 ; V_26 ++ )
if ( V_93 -> V_89 . integer . V_89 [ V_26 ] )
V_75 |= 1 << V_26 ;
return F_31 ( V_2 , V_75 , true ) ;
}
static int T_1 F_47 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_74 )
return 0 ;
return F_42 ( V_2 -> V_104 ,
F_43 ( & V_106 , V_2 ) ) ;
}
static int F_48 ( struct V_82 * V_83 ,
struct V_84 * V_85 )
{
unsigned int V_88 = ( V_83 -> V_86 >> 8 ) & 0xff ;
V_85 -> type = V_87 ;
V_85 -> V_88 = V_88 ;
V_85 -> V_89 . integer . V_90 = 0 ;
V_85 -> V_89 . integer . V_91 = 409 ;
return 0 ;
}
static int F_49 ( struct V_82 * V_83 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
unsigned int V_107 = V_83 -> V_86 & 0xff ;
unsigned int V_88 = ( V_83 -> V_86 >> 8 ) & 0xff ;
unsigned int V_75 , V_26 ;
V_75 = F_18 ( & V_2 -> V_30 . V_33 -> V_56 ) ;
for ( V_26 = 0 ; V_26 < V_88 ; V_26 ++ ) {
unsigned int V_65 = V_107 + V_26 ;
unsigned short V_7 ;
if ( ! ( V_2 -> V_30 . V_50 & ( 1 << V_65 ) ) )
return - V_13 ;
if ( V_75 & ( 1 << V_65 ) )
V_7 = F_19 ( & V_2 -> V_30 . V_33 -> V_57 [ V_65 ] ) + 1 ;
else
V_7 = 0 ;
V_93 -> V_89 . integer . V_89 [ V_26 ] = V_7 ;
}
return 0 ;
}
static int F_50 ( struct V_82 * V_83 ,
struct V_92 * V_93 )
{
struct V_1 * V_2 = F_35 ( V_83 ) ;
unsigned int V_107 = V_83 -> V_86 & 0xff ;
unsigned int V_88 = ( V_83 -> V_86 >> 8 ) & 0xff ;
int V_26 , V_8 ;
for ( V_26 = 0 ; V_26 < V_88 ; V_26 ++ ) {
unsigned int V_65 = V_107 + V_26 ;
unsigned short V_7 = V_93 -> V_89 . integer . V_89 [ V_26 ] ;
if ( V_7 )
V_7 -- ;
V_8 = F_17 ( V_2 , V_65 , V_7 , ! ! V_7 ) ;
if ( V_8 < 0 )
return V_8 ;
}
return 0 ;
}
static int T_1 F_51 ( struct V_1 * V_2 ,
int V_108 , int V_107 , char * V_102 )
{
V_109 . V_102 = V_102 ;
V_109 . V_86 = V_107 + ( V_108 << 8 ) ;
return F_42 ( V_2 -> V_104 ,
F_43 ( & V_109 , V_2 ) ) ;
}
int T_1 F_52 ( struct V_1 * V_2 )
{
int V_8 ;
V_8 = F_41 ( V_2 , V_12 , L_10 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_41 ( V_2 , V_11 , L_11 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_47 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_51 ( V_2 , V_2 -> V_30 . V_43 , 0 ,
L_12 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_51 ( V_2 , V_2 -> V_30 . V_40 ,
V_2 -> V_30 . V_46 ,
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

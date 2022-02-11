static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
do {
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
} while ( ! ( V_3 & V_6 ) );
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
unsigned int V_12 = F_4 ( V_10 -> V_13 ) ;
unsigned int V_14 = F_5 ( V_10 -> V_13 ) ;
unsigned int V_15 = 0 ;
int V_16 ;
int V_17 ;
if ( V_14 ) {
F_6 ( 0 , V_2 -> V_4 + V_5 ) ;
} else {
V_15 |= V_18 ;
F_6 ( V_19 ,
V_2 -> V_4 + V_5 ) ;
}
V_15 |= F_7 ( V_12 ) ;
for ( V_16 = 0 ; V_16 < V_10 -> V_20 ; V_16 ++ ) {
if ( V_14 == 1 ) {
if ( V_11 [ V_16 ] > 0x1fff ) {
F_8 ( V_2 -> V_21 ,
L_1 ) ;
return - V_22 ;
}
}
V_17 = F_1 ( V_2 ) ;
if ( V_17 )
return V_17 ;
F_6 ( V_15 | F_9 ( V_11 [ V_16 ] ) ,
V_2 -> V_4 + V_23 ) ;
}
return V_10 -> V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
V_11 [ 1 ] = F_2 ( V_2 -> V_4 + V_24 ) & 0x3 ;
return V_10 -> V_20 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
unsigned int V_25 = V_11 [ 0 ] ;
unsigned int V_26 = V_11 [ 1 ] ;
V_8 -> V_27 = F_2 ( V_2 -> V_4 + V_28 ) ;
if ( V_25 ) {
V_8 -> V_27 &= ~ V_25 ;
V_8 -> V_27 |= ( V_26 & V_25 ) ;
F_6 ( V_8 -> V_27 , V_2 -> V_4 + V_28 ) ;
}
V_11 [ 1 ] = V_8 -> V_27 ;
return V_10 -> V_20 ;
}
static void F_12 ( unsigned long V_4 )
{
unsigned char V_15 ;
do {
V_15 = F_13 ( V_4 + V_29 ) ;
} while ( V_15 & 0x80 );
}
static unsigned short F_14 ( unsigned long V_4 ,
unsigned short V_30 )
{
unsigned short V_15 = 0 ;
unsigned char V_31 ;
unsigned char V_16 ;
V_30 += V_32 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
F_15 ( V_33 , V_4 + V_29 ) ;
F_12 ( V_4 ) ;
F_15 ( ( V_30 + V_16 ) & 0xff , V_4 + V_34 ) ;
F_12 ( V_4 ) ;
F_15 ( V_35 , V_4 + V_29 ) ;
F_12 ( V_4 ) ;
F_15 ( ( ( V_30 + V_16 ) >> 8 ) & 0xff ,
V_4 + V_34 ) ;
F_12 ( V_4 ) ;
F_15 ( V_36 , V_4 + V_29 ) ;
F_12 ( V_4 ) ;
V_31 = F_13 ( V_4 + V_34 ) ;
F_12 ( V_4 ) ;
if ( V_16 == 0 )
V_15 |= V_31 ;
else
V_15 |= ( V_31 << 8 ) ;
}
return V_15 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned long V_4 = V_38 -> V_40 ;
unsigned char V_41 ;
int V_16 ;
V_41 = F_14 ( V_4 , 10 ) & 0xff ;
for ( V_16 = 0 ; V_16 < V_41 ; V_16 ++ ) {
unsigned short V_42 = V_16 * 4 ;
unsigned short V_30 ;
unsigned char V_43 ;
unsigned short V_15 ;
V_43 = F_14 ( V_4 , 12 + V_42 ) & 0x3f ;
V_30 = F_14 ( V_4 , 14 + V_42 ) ;
if ( V_43 == V_44 ) {
V_15 = F_14 ( V_4 , V_30 + 10 ) ;
return ( V_15 >> 4 ) & 0x3ff ;
}
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned short V_30 = F_4 ( V_10 -> V_13 ) ;
V_11 [ 0 ] = F_14 ( V_38 -> V_40 , 2 * V_30 ) ;
return V_10 -> V_20 ;
}
static T_1 F_18 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned int V_47 ;
unsigned long V_48 ;
int V_49 ;
V_48 = F_2 ( V_2 -> V_4 + V_50 ) ;
V_48 = ( V_48 & 0xFFFFF9FDul ) ;
F_6 ( V_48 , V_2 -> V_4 + V_50 ) ;
V_47 = F_2 ( V_2 -> V_4 + V_51 ) & 0x1 ;
if ( ( ! V_47 ) ) {
F_19 ( V_2 , L_2 ) ;
return V_52 ;
}
F_20 ( V_53 , V_38 -> V_54 , 0 ) ;
V_48 = F_2 ( V_2 -> V_4 + V_50 ) ;
V_48 = ( ( V_48 & 0xFFFFF9FDul ) | 1 << 1 ) ;
F_6 ( V_48 , V_2 -> V_4 + V_50 ) ;
V_49 = F_2 ( V_2 -> V_4 + V_55 ) & 0x1 ;
return V_56 ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
int V_12 ;
int V_17 ;
F_6 ( 0x0 , V_2 -> V_4 + V_28 ) ;
F_6 ( V_19 ,
V_2 -> V_4 + V_5 ) ;
V_15 = V_18 | F_9 ( 0 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_17 = F_1 ( V_2 ) ;
if ( V_17 ) {
F_22 ( V_2 -> V_21 ,
L_3 ,
V_57 , V_12 ) ;
} else {
F_6 ( V_15 | F_7 ( V_12 ) ,
V_2 -> V_4 + V_23 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned long V_58 )
{
struct V_59 * V_60 = F_24 ( V_2 ) ;
struct V_37 * V_38 ;
struct V_7 * V_8 ;
int V_61 ;
int V_17 ;
V_38 = F_25 ( sizeof( * V_38 ) , V_62 ) ;
if ( ! V_38 )
return - V_63 ;
V_2 -> V_39 = V_38 ;
V_17 = F_26 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_4 = F_27 ( V_60 , 1 ) ;
V_38 -> V_40 = F_27 ( V_60 , 0 ) ;
V_61 = F_16 ( V_2 ) ;
if ( V_60 -> V_45 > 0 ) {
V_17 = F_28 ( V_60 -> V_45 , F_18 , V_64 ,
V_2 -> V_65 , V_2 ) ;
if ( V_17 == 0 )
V_2 -> V_45 = V_60 -> V_45 ;
}
V_17 = F_29 ( V_2 , 5 ) ;
if ( V_17 )
return V_17 ;
V_8 = & V_2 -> V_66 [ 0 ] ;
if ( V_61 ) {
V_8 -> type = V_67 ;
V_8 -> V_68 = V_69 | V_70 | V_71 ;
V_8 -> V_72 = V_61 ;
V_8 -> V_73 = 0x3fff ;
V_8 -> V_74 = & V_75 ;
V_8 -> V_76 = F_3 ;
} else {
V_8 -> type = V_77 ;
}
V_8 = & V_2 -> V_66 [ 1 ] ;
V_8 -> type = V_78 ;
V_8 -> V_68 = V_79 ;
V_8 -> V_72 = 2 ;
V_8 -> V_73 = 1 ;
V_8 -> V_74 = & V_80 ;
V_8 -> V_81 = F_10 ;
V_8 = & V_2 -> V_66 [ 2 ] ;
V_8 -> type = V_82 ;
V_8 -> V_68 = V_69 ;
V_8 -> V_72 = 2 ;
V_8 -> V_73 = 1 ;
V_8 -> V_74 = & V_80 ;
V_8 -> V_81 = F_11 ;
V_8 = & V_2 -> V_66 [ 3 ] ;
V_8 -> type = V_83 ;
V_8 -> V_68 = V_69 | V_70 | V_71 ;
V_8 -> V_72 = 1 ;
V_8 -> V_73 = 0 ;
V_8 -> V_84 = 1 ;
V_8 -> V_74 = & V_80 ;
V_8 -> V_76 = V_85 ;
V_8 -> V_86 = V_87 ;
V_8 -> V_88 = V_89 ;
V_8 = & V_2 -> V_66 [ 4 ] ;
V_8 -> type = V_90 ;
V_8 -> V_68 = V_79 | V_91 ;
V_8 -> V_72 = 256 ;
V_8 -> V_73 = 0xffff ;
V_8 -> V_86 = F_17 ;
F_21 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_21 ( V_2 ) ;
if ( V_2 -> V_45 )
F_31 ( V_2 -> V_45 , V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_59 * V_2 ,
const struct V_92 * V_93 )
{
return F_34 ( V_2 , & V_94 , V_93 -> V_95 ) ;
}

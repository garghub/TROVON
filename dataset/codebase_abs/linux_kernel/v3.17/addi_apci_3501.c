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
V_8 -> V_25 = F_2 ( V_2 -> V_4 + V_26 ) ;
if ( F_12 ( V_8 , V_11 ) )
F_6 ( V_8 -> V_25 , V_2 -> V_4 + V_26 ) ;
V_11 [ 1 ] = V_8 -> V_25 ;
return V_10 -> V_20 ;
}
static void F_13 ( unsigned long V_4 )
{
unsigned char V_15 ;
do {
V_15 = F_14 ( V_4 + V_27 ) ;
} while ( V_15 & 0x80 );
}
static unsigned short F_15 ( unsigned long V_4 ,
unsigned short V_28 )
{
unsigned short V_15 = 0 ;
unsigned char V_29 ;
unsigned char V_16 ;
V_28 += V_30 ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
F_16 ( V_31 , V_4 + V_27 ) ;
F_13 ( V_4 ) ;
F_16 ( ( V_28 + V_16 ) & 0xff , V_4 + V_32 ) ;
F_13 ( V_4 ) ;
F_16 ( V_33 , V_4 + V_27 ) ;
F_13 ( V_4 ) ;
F_16 ( ( ( V_28 + V_16 ) >> 8 ) & 0xff ,
V_4 + V_32 ) ;
F_13 ( V_4 ) ;
F_16 ( V_34 , V_4 + V_27 ) ;
F_13 ( V_4 ) ;
V_29 = F_14 ( V_4 + V_32 ) ;
F_13 ( V_4 ) ;
if ( V_16 == 0 )
V_15 |= V_29 ;
else
V_15 |= ( V_29 << 8 ) ;
}
return V_15 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
unsigned long V_4 = V_36 -> V_38 ;
unsigned char V_39 ;
int V_16 ;
V_39 = F_15 ( V_4 , 10 ) & 0xff ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
unsigned short V_40 = V_16 * 4 ;
unsigned short V_28 ;
unsigned char V_41 ;
unsigned short V_15 ;
V_41 = F_15 ( V_4 , 12 + V_40 ) & 0x3f ;
V_28 = F_15 ( V_4 , 14 + V_40 ) ;
if ( V_41 == V_42 ) {
V_15 = F_15 ( V_4 , V_28 + 10 ) ;
return ( V_15 >> 4 ) & 0x3ff ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_35 * V_36 = V_2 -> V_37 ;
unsigned short V_28 = F_4 ( V_10 -> V_13 ) ;
V_11 [ 0 ] = F_15 ( V_36 -> V_38 , 2 * V_28 ) ;
return V_10 -> V_20 ;
}
static T_1 F_19 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
struct V_35 * V_36 = V_2 -> V_37 ;
unsigned int V_45 ;
unsigned long V_46 ;
int V_47 ;
V_46 = F_2 ( V_2 -> V_4 + V_48 ) ;
V_46 = ( V_46 & 0xFFFFF9FDul ) ;
F_6 ( V_46 , V_2 -> V_4 + V_48 ) ;
V_45 = F_2 ( V_2 -> V_4 + V_49 ) & 0x1 ;
if ( ( ! V_45 ) ) {
F_8 ( V_2 -> V_21 , L_2 ) ;
return V_50 ;
}
F_20 ( V_51 , V_36 -> V_52 , 0 ) ;
V_46 = F_2 ( V_2 -> V_4 + V_48 ) ;
V_46 = ( ( V_46 & 0xFFFFF9FDul ) | 1 << 1 ) ;
F_6 ( V_46 , V_2 -> V_4 + V_48 ) ;
V_47 = F_2 ( V_2 -> V_4 + V_53 ) & 0x1 ;
return V_54 ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned int V_15 ;
int V_12 ;
int V_17 ;
F_6 ( 0x0 , V_2 -> V_4 + V_26 ) ;
F_6 ( V_19 ,
V_2 -> V_4 + V_5 ) ;
V_15 = V_18 | F_9 ( 0 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_17 = F_1 ( V_2 ) ;
if ( V_17 ) {
F_22 ( V_2 -> V_21 ,
L_3 ,
V_55 , V_12 ) ;
} else {
F_6 ( V_15 | F_7 ( V_12 ) ,
V_2 -> V_4 + V_23 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned long V_56 )
{
struct V_57 * V_58 = F_24 ( V_2 ) ;
struct V_35 * V_36 ;
struct V_7 * V_8 ;
int V_59 ;
int V_17 ;
V_36 = F_25 ( V_2 , sizeof( * V_36 ) ) ;
if ( ! V_36 )
return - V_60 ;
V_17 = F_26 ( V_2 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_4 = F_27 ( V_58 , 1 ) ;
V_36 -> V_38 = F_27 ( V_58 , 0 ) ;
V_59 = F_17 ( V_2 ) ;
if ( V_58 -> V_43 > 0 ) {
V_17 = F_28 ( V_58 -> V_43 , F_19 , V_61 ,
V_2 -> V_62 , V_2 ) ;
if ( V_17 == 0 )
V_2 -> V_43 = V_58 -> V_43 ;
}
V_17 = F_29 ( V_2 , 5 ) ;
if ( V_17 )
return V_17 ;
V_8 = & V_2 -> V_63 [ 0 ] ;
if ( V_59 ) {
V_8 -> type = V_64 ;
V_8 -> V_65 = V_66 | V_67 | V_68 ;
V_8 -> V_69 = V_59 ;
V_8 -> V_70 = 0x3fff ;
V_8 -> V_71 = & V_72 ;
V_8 -> V_73 = F_3 ;
} else {
V_8 -> type = V_74 ;
}
V_8 = & V_2 -> V_63 [ 1 ] ;
V_8 -> type = V_75 ;
V_8 -> V_65 = V_76 ;
V_8 -> V_69 = 2 ;
V_8 -> V_70 = 1 ;
V_8 -> V_71 = & V_77 ;
V_8 -> V_78 = F_10 ;
V_8 = & V_2 -> V_63 [ 2 ] ;
V_8 -> type = V_79 ;
V_8 -> V_65 = V_66 ;
V_8 -> V_69 = 2 ;
V_8 -> V_70 = 1 ;
V_8 -> V_71 = & V_77 ;
V_8 -> V_78 = F_11 ;
V_8 = & V_2 -> V_63 [ 3 ] ;
V_8 -> type = V_80 ;
V_8 -> V_65 = V_66 | V_67 | V_68 ;
V_8 -> V_69 = 1 ;
V_8 -> V_70 = 0 ;
V_8 -> V_81 = 1 ;
V_8 -> V_71 = & V_77 ;
V_8 -> V_73 = V_82 ;
V_8 -> V_83 = V_84 ;
V_8 -> V_85 = V_86 ;
V_8 = & V_2 -> V_63 [ 4 ] ;
V_8 -> type = V_87 ;
V_8 -> V_65 = V_76 | V_88 ;
V_8 -> V_69 = 256 ;
V_8 -> V_70 = 0xffff ;
V_8 -> V_83 = F_18 ;
F_21 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_21 ( V_2 ) ;
if ( V_2 -> V_43 )
F_31 ( V_2 -> V_43 , V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_57 * V_2 ,
const struct V_89 * V_90 )
{
return F_34 ( V_2 , & V_91 , V_90 -> V_92 ) ;
}

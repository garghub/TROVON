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
unsigned int V_15 = F_6 ( V_12 ) ;
int V_16 ;
int V_17 ;
if ( V_14 ) {
F_7 ( 0 , V_2 -> V_4 + V_5 ) ;
} else {
V_15 |= V_18 ;
F_7 ( V_19 ,
V_2 -> V_4 + V_5 ) ;
}
for ( V_17 = 0 ; V_17 < V_10 -> V_20 ; V_17 ++ ) {
unsigned int V_21 = V_11 [ V_17 ] ;
if ( V_14 == 1 ) {
if ( V_11 [ V_17 ] > 0x1fff ) {
F_8 ( V_2 -> V_22 ,
L_1 ) ;
return - V_23 ;
}
}
V_16 = F_1 ( V_2 ) ;
if ( V_16 )
return V_16 ;
F_7 ( V_15 | F_9 ( V_21 ) ,
V_2 -> V_4 + V_24 ) ;
V_8 -> V_25 [ V_12 ] = V_21 ;
}
return V_10 -> V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
V_11 [ 1 ] = F_2 ( V_2 -> V_4 + V_26 ) & 0x3 ;
return V_10 -> V_20 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
V_8 -> V_27 = F_2 ( V_2 -> V_4 + V_28 ) ;
if ( F_12 ( V_8 , V_11 ) )
F_7 ( V_8 -> V_27 , V_2 -> V_4 + V_28 ) ;
V_11 [ 1 ] = V_8 -> V_27 ;
return V_10 -> V_20 ;
}
static void F_13 ( unsigned long V_4 )
{
unsigned char V_21 ;
do {
V_21 = F_14 ( V_4 + V_29 ) ;
} while ( V_21 & 0x80 );
}
static unsigned short F_15 ( unsigned long V_4 ,
unsigned short V_30 )
{
unsigned short V_21 = 0 ;
unsigned char V_31 ;
unsigned char V_17 ;
V_30 += V_32 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
F_16 ( V_33 , V_4 + V_29 ) ;
F_13 ( V_4 ) ;
F_16 ( ( V_30 + V_17 ) & 0xff , V_4 + V_34 ) ;
F_13 ( V_4 ) ;
F_16 ( V_35 , V_4 + V_29 ) ;
F_13 ( V_4 ) ;
F_16 ( ( ( V_30 + V_17 ) >> 8 ) & 0xff ,
V_4 + V_34 ) ;
F_13 ( V_4 ) ;
F_16 ( V_36 , V_4 + V_29 ) ;
F_13 ( V_4 ) ;
V_31 = F_14 ( V_4 + V_34 ) ;
F_13 ( V_4 ) ;
if ( V_17 == 0 )
V_21 |= V_31 ;
else
V_21 |= ( V_31 << 8 ) ;
}
return V_21 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned long V_4 = V_38 -> V_40 ;
unsigned char V_41 ;
int V_17 ;
V_41 = F_15 ( V_4 , 10 ) & 0xff ;
for ( V_17 = 0 ; V_17 < V_41 ; V_17 ++ ) {
unsigned short V_42 = V_17 * 4 ;
unsigned short V_30 ;
unsigned char V_43 ;
unsigned short V_21 ;
V_43 = F_15 ( V_4 , 12 + V_42 ) & 0x3f ;
V_30 = F_15 ( V_4 , 14 + V_42 ) ;
if ( V_43 == V_44 ) {
V_21 = F_15 ( V_4 , V_30 + 10 ) ;
return ( V_21 >> 4 ) & 0x3ff ;
}
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned short V_30 = F_4 ( V_10 -> V_13 ) ;
V_11 [ 0 ] = F_15 ( V_38 -> V_40 , 2 * V_30 ) ;
return V_10 -> V_20 ;
}
static T_1 F_19 ( int V_45 , void * V_46 )
{
struct V_1 * V_2 = V_46 ;
struct V_37 * V_38 = V_2 -> V_39 ;
unsigned int V_47 ;
unsigned long V_48 ;
V_48 = F_2 ( V_2 -> V_4 + V_49 ) ;
V_48 = V_48 & 0xFFFFF9FDul ;
F_7 ( V_48 , V_2 -> V_4 + V_49 ) ;
V_47 = F_2 ( V_2 -> V_4 + V_50 ) & 0x1 ;
if ( ( ! V_47 ) ) {
F_8 ( V_2 -> V_22 , L_2 ) ;
return V_51 ;
}
F_20 ( V_52 , V_38 -> V_53 , 0 ) ;
V_48 = F_2 ( V_2 -> V_4 + V_49 ) ;
V_48 = ( V_48 & 0xFFFFF9FDul ) | 1 << 1 ;
F_7 ( V_48 , V_2 -> V_4 + V_49 ) ;
F_2 ( V_2 -> V_4 + V_54 ) ;
return V_55 ;
}
static int F_21 ( struct V_1 * V_2 )
{
unsigned int V_21 ;
int V_12 ;
int V_16 ;
F_7 ( 0x0 , V_2 -> V_4 + V_28 ) ;
F_7 ( V_19 ,
V_2 -> V_4 + V_5 ) ;
V_21 = V_18 | F_9 ( 0 ) ;
for ( V_12 = 0 ; V_12 < 8 ; V_12 ++ ) {
V_16 = F_1 ( V_2 ) ;
if ( V_16 ) {
F_22 ( V_2 -> V_22 ,
L_3 ,
V_56 , V_12 ) ;
} else {
F_7 ( V_21 | F_6 ( V_12 ) ,
V_2 -> V_4 + V_24 ) ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned long V_57 )
{
struct V_58 * V_59 = F_24 ( V_2 ) ;
struct V_37 * V_38 ;
struct V_7 * V_8 ;
int V_60 ;
int V_16 ;
V_38 = F_25 ( V_2 , sizeof( * V_38 ) ) ;
if ( ! V_38 )
return - V_61 ;
V_16 = F_26 ( V_2 ) ;
if ( V_16 )
return V_16 ;
V_2 -> V_4 = F_27 ( V_59 , 1 ) ;
V_38 -> V_40 = F_27 ( V_59 , 0 ) ;
V_60 = F_17 ( V_2 ) ;
if ( V_59 -> V_45 > 0 ) {
V_16 = F_28 ( V_59 -> V_45 , F_19 , V_62 ,
V_2 -> V_63 , V_2 ) ;
if ( V_16 == 0 )
V_2 -> V_45 = V_59 -> V_45 ;
}
V_16 = F_29 ( V_2 , 5 ) ;
if ( V_16 )
return V_16 ;
V_8 = & V_2 -> V_64 [ 0 ] ;
if ( V_60 ) {
V_8 -> type = V_65 ;
V_8 -> V_66 = V_67 | V_68 | V_69 ;
V_8 -> V_70 = V_60 ;
V_8 -> V_71 = 0x3fff ;
V_8 -> V_72 = & V_73 ;
V_8 -> V_74 = F_3 ;
V_16 = F_30 ( V_8 ) ;
if ( V_16 )
return V_16 ;
} else {
V_8 -> type = V_75 ;
}
V_8 = & V_2 -> V_64 [ 1 ] ;
V_8 -> type = V_76 ;
V_8 -> V_66 = V_77 ;
V_8 -> V_70 = 2 ;
V_8 -> V_71 = 1 ;
V_8 -> V_72 = & V_78 ;
V_8 -> V_79 = F_10 ;
V_8 = & V_2 -> V_64 [ 2 ] ;
V_8 -> type = V_80 ;
V_8 -> V_66 = V_67 ;
V_8 -> V_70 = 2 ;
V_8 -> V_71 = 1 ;
V_8 -> V_72 = & V_78 ;
V_8 -> V_79 = F_11 ;
V_8 = & V_2 -> V_64 [ 3 ] ;
V_8 -> type = V_81 ;
V_8 -> V_66 = V_67 ;
V_8 -> V_70 = 1 ;
V_8 -> V_71 = 0 ;
V_8 -> V_82 = 1 ;
V_8 -> V_72 = & V_78 ;
V_8 -> V_74 = V_83 ;
V_8 -> V_84 = V_85 ;
V_8 -> V_86 = V_87 ;
V_8 = & V_2 -> V_64 [ 4 ] ;
V_8 -> type = V_88 ;
V_8 -> V_66 = V_77 | V_89 ;
V_8 -> V_70 = 256 ;
V_8 -> V_71 = 0xffff ;
V_8 -> V_84 = F_18 ;
F_21 ( V_2 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 )
F_21 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_58 * V_2 ,
const struct V_90 * V_91 )
{
return F_34 ( V_2 , & V_92 , V_91 -> V_93 ) ;
}

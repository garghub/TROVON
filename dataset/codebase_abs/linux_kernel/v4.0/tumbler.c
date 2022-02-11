static int F_1 ( struct V_1 * V_2 , unsigned int * V_3 )
{
while ( * V_3 > 0 ) {
int V_4 , V_5 = 10 ;
do {
V_4 = F_2 ( V_2 -> V_6 ,
V_3 [ 0 ] , V_3 [ 1 ] ) ;
if ( V_4 >= 0 )
break;
F_3 ( L_1 , V_4 ) ;
F_4 ( 10 ) ;
} while ( V_5 -- );
if ( V_4 < 0 )
return - V_7 ;
V_3 += 2 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
static unsigned int V_3 [] = {
V_8 , ( 1 << 6 ) | ( 2 << 4 ) | ( 2 << 2 ) | 0 ,
0 ,
} ;
F_3 ( L_2 ) ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
static unsigned int V_3 [] = {
V_8 , ( 1 << 6 ) | ( 2 << 4 ) | 0 ,
V_9 , ( 1 << 1 ) ,
V_10 , 0 ,
0 ,
} ;
F_3 ( L_3 ) ;
return F_1 ( V_2 , V_3 ) ;
}
static void F_7 ( struct V_11 * V_12 , int V_13 )
{
if ( ! V_12 -> V_14 )
return;
V_13 = V_13 ? V_12 -> V_15 : V_12 -> V_16 ;
F_8 ( V_12 , V_13 ) ;
F_3 ( L_4 , V_12 -> V_14 , V_13 ) ;
}
static int F_9 ( struct V_11 * V_12 )
{
int V_17 ;
if ( ! V_12 -> V_14 )
return 0 ;
V_17 = F_10 ( V_12 ) ;
return ( V_17 & 0x1 ) == ( V_12 -> V_15 & 0x1 ) ;
}
static int F_11 ( struct V_11 * V_12 )
{
int V_17 ;
if ( ! V_12 -> V_14 )
return 0 ;
V_17 = F_10 ( V_12 ) ;
V_17 = ( V_17 & 0x02 ) != 0 ;
return V_17 == V_12 -> V_18 ;
}
static int F_12 ( struct V_19 * V_20 )
{
unsigned char V_21 [ 6 ] ;
unsigned int V_22 , V_23 ;
if ( ! V_20 -> V_2 . V_6 )
return - V_24 ;
if ( ! V_20 -> V_25 [ 0 ] )
V_22 = 0 ;
else {
V_22 = V_20 -> V_26 [ 0 ] ;
if ( V_22 >= F_13 ( V_27 ) )
V_22 = F_13 ( V_27 ) - 1 ;
V_22 = V_27 [ V_22 ] ;
}
if ( ! V_20 -> V_25 [ 1 ] )
V_23 = 0 ;
else {
V_23 = V_20 -> V_26 [ 1 ] ;
if ( V_23 >= F_13 ( V_27 ) )
V_23 = F_13 ( V_27 ) - 1 ;
V_23 = V_27 [ V_23 ] ;
}
V_21 [ 0 ] = ( V_22 >> 16 ) & 0xff ;
V_21 [ 1 ] = ( V_22 >> 8 ) & 0xff ;
V_21 [ 2 ] = ( V_22 >> 0 ) & 0xff ;
V_21 [ 3 ] = ( V_23 >> 16 ) & 0xff ;
V_21 [ 4 ] = ( V_23 >> 8 ) & 0xff ;
V_21 [ 5 ] = ( V_23 >> 0 ) & 0xff ;
if ( F_14 ( V_20 -> V_2 . V_6 , V_28 , 6 ,
V_21 ) < 0 ) {
F_15 ( V_29 L_5 ) ;
return - V_30 ;
}
F_3 ( L_6 , V_22 , V_23 ) ;
return 0 ;
}
static int F_16 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
V_34 -> type = V_35 ;
V_34 -> V_5 = 2 ;
V_34 -> V_36 . integer . V_37 = 0 ;
V_34 -> V_36 . integer . V_38 = F_13 ( V_27 ) - 1 ;
return 0 ;
}
static int F_17 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 = V_42 -> V_43 ;
V_40 -> V_36 . integer . V_36 [ 0 ] = V_20 -> V_26 [ 0 ] ;
V_40 -> V_36 . integer . V_36 [ 1 ] = V_20 -> V_26 [ 1 ] ;
return 0 ;
}
static int F_19 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 = V_42 -> V_43 ;
unsigned int V_44 [ 2 ] ;
int V_45 ;
V_44 [ 0 ] = V_40 -> V_36 . integer . V_36 [ 0 ] ;
V_44 [ 1 ] = V_40 -> V_36 . integer . V_36 [ 1 ] ;
if ( V_44 [ 0 ] >= F_13 ( V_27 ) ||
V_44 [ 1 ] >= F_13 ( V_27 ) )
return - V_30 ;
V_45 = V_20 -> V_26 [ 0 ] != V_44 [ 0 ] ||
V_20 -> V_26 [ 1 ] != V_44 [ 1 ] ;
if ( V_45 ) {
V_20 -> V_26 [ 0 ] = V_44 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_44 [ 1 ] ;
F_12 ( V_20 ) ;
}
return V_45 ;
}
static int F_20 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 = V_42 -> V_43 ;
V_40 -> V_36 . integer . V_36 [ 0 ] = V_20 -> V_25 [ 0 ] ;
V_40 -> V_36 . integer . V_36 [ 1 ] = V_20 -> V_25 [ 1 ] ;
return 0 ;
}
static int F_21 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 = V_42 -> V_43 ;
int V_45 ;
V_45 = V_20 -> V_25 [ 0 ] != V_40 -> V_36 . integer . V_36 [ 0 ] ||
V_20 -> V_25 [ 1 ] != V_40 -> V_36 . integer . V_36 [ 1 ] ;
if ( V_45 ) {
V_20 -> V_25 [ 0 ] = ! ! V_40 -> V_36 . integer . V_36 [ 0 ] ;
V_20 -> V_25 [ 1 ] = ! ! V_40 -> V_36 . integer . V_36 [ 1 ] ;
F_12 ( V_20 ) ;
}
return V_45 ;
}
static int F_22 ( struct V_19 * V_20 )
{
unsigned char V_46 [ 2 ] ;
if ( ! V_20 -> V_2 . V_6 )
return - V_24 ;
if ( V_20 -> V_47 ) {
V_46 [ 0 ] = 0xc1 ;
if ( V_20 -> V_48 > V_49 )
V_46 [ 1 ] = 0xf0 ;
else if ( V_20 -> V_48 < 0 )
V_46 [ 1 ] = 0x91 ;
else
V_46 [ 1 ] = V_20 -> V_48 + 0x91 ;
} else {
V_46 [ 0 ] = 0 ;
V_46 [ 1 ] = 0 ;
}
if ( F_14 ( V_20 -> V_2 . V_6 , V_50 ,
2 , V_46 ) < 0 ) {
F_15 ( V_29 L_7 ) ;
return - V_30 ;
}
F_3 ( L_8 , V_46 [ 0 ] , V_46 [ 1 ] ) ;
return 0 ;
}
static int F_23 ( struct V_19 * V_20 )
{
unsigned char V_46 [ 6 ] ;
if ( ! V_20 -> V_2 . V_6 )
return - V_24 ;
if ( V_20 -> V_47 )
V_46 [ 0 ] = 0x50 ;
else
V_46 [ 0 ] = 0x51 ;
V_46 [ 1 ] = 0x02 ;
if ( V_20 -> V_48 > 0xef )
V_46 [ 2 ] = 0xef ;
else if ( V_20 -> V_48 < 0 )
V_46 [ 2 ] = 0x00 ;
else
V_46 [ 2 ] = V_20 -> V_48 ;
V_46 [ 3 ] = 0xb0 ;
V_46 [ 4 ] = 0x60 ;
V_46 [ 5 ] = 0xa0 ;
if ( F_14 ( V_20 -> V_2 . V_6 , V_50 ,
6 , V_46 ) < 0 ) {
F_15 ( V_29 L_7 ) ;
return - V_30 ;
}
F_3 ( L_8 , V_46 [ 0 ] , V_46 [ 1 ] ) ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
V_34 -> type = V_35 ;
V_34 -> V_5 = 1 ;
V_34 -> V_36 . integer . V_37 = 0 ;
V_34 -> V_36 . integer . V_38 =
V_42 -> V_51 == V_52 ? V_49 : V_53 ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
V_40 -> V_36 . integer . V_36 [ 0 ] = V_20 -> V_48 ;
return 0 ;
}
static int F_26 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
unsigned int V_46 ;
int V_45 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
V_46 = V_40 -> V_36 . integer . V_36 [ 0 ] ;
if ( V_42 -> V_51 == V_52 ) {
if ( V_46 > V_49 )
return - V_30 ;
} else {
if ( V_46 > V_53 )
return - V_30 ;
}
V_45 = V_20 -> V_48 != V_46 ;
if ( V_45 ) {
V_20 -> V_48 = V_46 ;
if ( V_42 -> V_51 == V_52 )
F_22 ( V_20 ) ;
else
F_23 ( V_20 ) ;
}
return V_45 ;
}
static int F_27 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
V_40 -> V_36 . integer . V_36 [ 0 ] = V_20 -> V_47 ;
return 0 ;
}
static int F_28 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
int V_45 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
V_45 = V_20 -> V_47 != V_40 -> V_36 . integer . V_36 [ 0 ] ;
if ( V_45 ) {
V_20 -> V_47 = ! ! V_40 -> V_36 . integer . V_36 [ 0 ] ;
if ( V_42 -> V_51 == V_52 )
F_22 ( V_20 ) ;
else
F_23 ( V_20 ) ;
}
return V_45 ;
}
static int F_29 ( struct V_19 * V_20 ,
struct V_54 * V_55 )
{
unsigned char V_21 [ 4 ] ;
unsigned int V_44 ;
int V_56 ;
if ( ! V_20 -> V_2 . V_6 )
return - V_24 ;
V_44 = V_20 -> V_57 [ V_55 -> V_58 ] ;
if ( V_44 >= V_55 -> V_38 )
V_44 = V_55 -> V_38 - 1 ;
V_44 = V_55 -> V_59 [ V_44 ] ;
for ( V_56 = 0 ; V_56 < V_55 -> V_60 ; V_56 ++ )
V_21 [ V_56 ] = ( V_44 >> ( ( V_55 -> V_60 - V_56 - 1 ) * 8 ) ) & 0xff ;
if ( F_14 ( V_20 -> V_2 . V_6 , V_55 -> V_61 ,
V_55 -> V_60 , V_21 ) < 0 ) {
F_15 ( V_29 L_9 ,
V_55 -> V_58 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_30 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
struct V_54 * V_55 = (struct V_54 * ) V_32 -> V_62 ;
V_34 -> type = V_35 ;
V_34 -> V_5 = 1 ;
V_34 -> V_36 . integer . V_37 = 0 ;
V_34 -> V_36 . integer . V_38 = V_55 -> V_38 - 1 ;
return 0 ;
}
static int F_31 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_54 * V_55 = (struct V_54 * ) V_32 -> V_62 ;
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
V_40 -> V_36 . integer . V_36 [ 0 ] = V_20 -> V_57 [ V_55 -> V_58 ] ;
return 0 ;
}
static int F_32 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_54 * V_55 = (struct V_54 * ) V_32 -> V_62 ;
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
unsigned int V_44 ;
int V_45 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
V_44 = V_40 -> V_36 . integer . V_36 [ 0 ] ;
if ( V_44 >= V_55 -> V_38 )
return - V_30 ;
V_45 = V_20 -> V_57 [ V_55 -> V_58 ] != V_44 ;
if ( V_45 ) {
V_20 -> V_57 [ V_55 -> V_58 ] = V_44 ;
F_29 ( V_20 , V_55 ) ;
}
return V_45 ;
}
static int F_33 ( struct V_19 * V_20 , int V_63 , int V_64 , int V_61 )
{
int V_56 , V_65 , V_44 ;
unsigned char V_21 [ 9 ] ;
V_44 = V_20 -> V_66 [ V_63 ] [ V_64 ] ;
if ( V_44 >= F_13 ( V_67 ) ) {
V_44 = F_13 ( V_67 ) - 1 ;
V_20 -> V_66 [ V_63 ] [ V_64 ] = V_44 ;
}
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
V_44 = V_20 -> V_66 [ V_56 ] [ V_64 ] ;
V_44 = V_67 [ V_44 ] ;
for ( V_65 = 0 ; V_65 < 3 ; V_65 ++ )
V_21 [ V_56 * 3 + V_65 ] = ( V_44 >> ( ( 2 - V_65 ) * 8 ) ) & 0xff ;
}
if ( F_14 ( V_20 -> V_2 . V_6 , V_61 ,
9 , V_21 ) < 0 ) {
F_15 ( V_29 L_9 , V_61 ) ;
return - V_30 ;
}
return 0 ;
}
static int F_34 ( struct V_19 * V_20 , int V_63 )
{
if ( ! V_20 -> V_2 . V_6 )
return - V_24 ;
if ( F_33 ( V_20 , V_63 , 0 , V_68 ) < 0 ||
F_33 ( V_20 , V_63 , 1 , V_69 ) < 0 )
return - V_30 ;
return 0 ;
}
static int F_35 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
V_34 -> type = V_35 ;
V_34 -> V_5 = 2 ;
V_34 -> V_36 . integer . V_37 = 0 ;
V_34 -> V_36 . integer . V_38 = F_13 ( V_67 ) - 1 ;
return 0 ;
}
static int F_36 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
int V_63 = ( int ) V_32 -> V_62 ;
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
V_40 -> V_36 . integer . V_36 [ 0 ] = V_20 -> V_66 [ V_63 ] [ 0 ] ;
V_40 -> V_36 . integer . V_36 [ 1 ] = V_20 -> V_66 [ V_63 ] [ 1 ] ;
return 0 ;
}
static int F_37 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
int V_63 = ( int ) V_32 -> V_62 ;
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
unsigned int V_44 [ 2 ] ;
int V_45 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
V_44 [ 0 ] = V_40 -> V_36 . integer . V_36 [ 0 ] ;
V_44 [ 1 ] = V_40 -> V_36 . integer . V_36 [ 1 ] ;
if ( V_44 [ 0 ] >= F_13 ( V_67 ) ||
V_44 [ 1 ] >= F_13 ( V_67 ) )
return - V_30 ;
V_45 = V_20 -> V_66 [ V_63 ] [ 0 ] != V_44 [ 0 ] ||
V_20 -> V_66 [ V_63 ] [ 1 ] != V_44 [ 1 ] ;
if ( V_45 ) {
V_20 -> V_66 [ V_63 ] [ 0 ] = V_44 [ 0 ] ;
V_20 -> V_66 [ V_63 ] [ 1 ] = V_44 [ 1 ] ;
F_34 ( V_20 , V_63 ) ;
}
return V_45 ;
}
static int F_38 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
struct V_11 * V_12 ;
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
switch( V_32 -> V_62 ) {
case V_70 :
V_12 = & V_20 -> V_71 ; break;
case V_72 :
V_12 = & V_20 -> V_73 ; break;
case V_74 :
V_12 = & V_20 -> V_75 ; break;
default:
V_12 = NULL ;
}
if ( V_12 == NULL )
return - V_30 ;
V_40 -> V_36 . integer . V_36 [ 0 ] = ! F_9 ( V_12 ) ;
return 0 ;
}
static int F_39 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 ;
struct V_11 * V_12 ;
int V_46 ;
#ifdef F_40
if ( V_42 -> V_76 && V_42 -> V_77 )
return 0 ;
#endif
if ( ! ( V_20 = V_42 -> V_43 ) )
return - V_24 ;
switch( V_32 -> V_62 ) {
case V_70 :
V_12 = & V_20 -> V_71 ; break;
case V_72 :
V_12 = & V_20 -> V_73 ; break;
case V_74 :
V_12 = & V_20 -> V_75 ; break;
default:
V_12 = NULL ;
}
if ( V_12 == NULL )
return - V_30 ;
V_46 = ! F_9 ( V_12 ) ;
if ( V_46 != V_40 -> V_36 . integer . V_36 [ 0 ] ) {
F_7 ( V_12 , ! V_40 -> V_36 . integer . V_36 [ 0 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_41 ( struct V_19 * V_20 )
{
if ( ! V_20 -> V_2 . V_6 )
return - V_24 ;
if ( V_20 -> V_78 )
V_20 -> V_79 |= 2 ;
else
V_20 -> V_79 &= ~ 2 ;
return F_2 ( V_20 -> V_2 . V_6 , V_10 , V_20 -> V_79 ) ;
}
static int F_42 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
static const char * const V_80 [ 2 ] = {
L_10 , L_11
} ;
return F_43 ( V_34 , 1 , 2 , V_80 ) ;
}
static int F_44 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 = V_42 -> V_43 ;
V_40 -> V_36 . V_81 . V_82 [ 0 ] = V_20 -> V_78 ;
return 0 ;
}
static int F_45 ( struct V_31 * V_32 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_18 ( V_32 ) ;
struct V_19 * V_20 = V_42 -> V_43 ;
int V_45 ;
V_45 = V_40 -> V_36 . V_81 . V_82 [ 0 ] != V_20 -> V_78 ;
if ( V_45 ) {
V_20 -> V_78 = ! ! V_40 -> V_36 . V_81 . V_82 [ 0 ] ;
F_41 ( V_20 ) ;
}
return V_45 ;
}
static int F_46 ( struct V_41 * V_42 )
{
struct V_19 * V_20 = V_42 -> V_43 ;
int V_83 = 0 ;
if ( V_20 -> V_84 . V_14 )
V_83 |= F_11 ( & V_20 -> V_84 ) ;
return V_83 ;
}
static int F_47 ( struct V_41 * V_42 )
{
struct V_19 * V_20 = V_42 -> V_43 ;
int V_83 = 0 ;
if ( V_20 -> V_85 . V_14 )
V_83 |= F_11 ( & V_20 -> V_85 ) ;
return V_83 ;
}
static void F_48 ( struct V_41 * V_42 , struct V_11 * V_12 , int V_46 , int V_86 ,
struct V_31 * V_87 )
{
if ( F_9 ( V_12 ) != V_46 ) {
F_7 ( V_12 , V_46 ) ;
if ( V_86 )
F_49 ( V_42 -> V_88 , V_89 ,
& V_87 -> V_90 ) ;
}
}
static void F_50 ( struct V_91 * V_92 )
{
struct V_41 * V_42 = V_93 ;
struct V_19 * V_20 ;
int V_94 , V_95 ;
if ( ! V_42 )
return;
V_20 = V_42 -> V_43 ;
if ( F_51 ( ! V_20 ) )
return;
V_94 = F_46 ( V_42 ) ;
V_95 = F_47 ( V_42 ) ;
F_3 ( L_12 , V_94 , V_95 ) ;
if ( V_94 || V_95 ) {
if ( V_94 )
F_48 ( V_42 , & V_20 -> V_71 , 0 , V_20 -> V_96 ,
V_42 -> V_97 ) ;
if ( V_95 && V_20 -> V_75 . V_14 != 0 )
F_48 ( V_42 , & V_20 -> V_75 , 0 , V_20 -> V_96 ,
V_42 -> V_98 ) ;
if ( V_20 -> V_99 )
F_52 ( 10 ) ;
F_48 ( V_42 , & V_20 -> V_73 , ! V_100 , V_20 -> V_96 ,
V_42 -> V_101 ) ;
} else {
F_48 ( V_42 , & V_20 -> V_73 , 0 , V_20 -> V_96 ,
V_42 -> V_101 ) ;
if ( V_20 -> V_99 )
F_52 ( 10 ) ;
F_48 ( V_42 , & V_20 -> V_71 , 1 , V_20 -> V_96 ,
V_42 -> V_97 ) ;
if ( V_20 -> V_75 . V_14 != 0 )
F_48 ( V_42 , & V_20 -> V_75 , 1 , V_20 -> V_96 ,
V_42 -> V_98 ) ;
}
if ( V_20 -> V_96 )
F_49 ( V_42 -> V_88 , V_89 ,
& V_42 -> V_102 -> V_90 ) ;
#ifdef F_53
V_20 -> V_47 = ! ( V_94 || V_95 ) ;
if ( V_20 -> V_96 )
F_49 ( V_42 -> V_88 , V_89 ,
& V_42 -> V_103 -> V_90 ) ;
if ( V_42 -> V_51 == V_52 )
F_22 ( V_20 ) ;
else
F_23 ( V_20 ) ;
#endif
F_12 ( V_20 ) ;
}
static void F_54 ( struct V_41 * V_42 , int V_86 )
{
if ( V_42 -> V_77 ) {
struct V_19 * V_20 ;
V_20 = V_42 -> V_43 ;
if ( F_51 ( ! V_20 ) )
return;
V_20 -> V_96 = V_86 ;
F_55 ( & V_104 ) ;
}
}
static T_1 F_56 ( int V_105 , void * V_106 )
{
struct V_41 * V_42 = V_106 ;
if ( V_42 -> V_76 && V_42 -> V_107 ) {
V_42 -> V_76 ( V_42 , 1 ) ;
return V_108 ;
}
return V_109 ;
}
static struct V_110 * F_57 ( const char * V_111 )
{
struct V_110 * V_112 ;
struct V_110 * V_113 ;
V_112 = F_58 ( NULL , L_13 ) ;
if ( ! V_112 )
return NULL ;
for ( V_113 = F_59 ( V_112 , NULL ) ; V_113 ;
V_113 = F_59 ( V_112 , V_113 ) ) {
const char * V_114 = F_60 ( V_113 , L_14 , NULL ) ;
if ( V_114 && strcmp ( V_114 , V_111 ) == 0 )
break;
}
F_61 ( V_112 ) ;
return V_113 ;
}
static struct V_110 * F_62 ( const char * V_111 )
{
struct V_110 * V_112 ;
struct V_110 * V_113 ;
V_112 = F_58 ( NULL , L_13 ) ;
if ( ! V_112 )
return NULL ;
for ( V_113 = F_59 ( V_112 , NULL ) ; V_113 ;
V_113 = F_59 ( V_112 , V_113 ) ) {
if ( F_63 ( V_113 , V_111 ) )
break;
}
F_61 ( V_112 ) ;
return V_113 ;
}
static long F_64 ( const char * V_115 , const char * V_116 ,
struct V_11 * V_12 , int V_117 )
{
struct V_110 * V_118 ;
const T_2 * V_119 ;
T_2 V_14 ;
long V_17 ;
if ( V_117 )
V_118 = F_62 ( V_115 ) ;
else
V_118 = F_57 ( V_115 ) ;
if ( ! V_118 ) {
F_3 ( L_15 , V_115 ) ;
F_65 ( L_16 , V_115 ) ;
return - V_24 ;
}
V_119 = F_60 ( V_118 , L_17 , NULL ) ;
if ( ! V_119 ) {
V_119 = F_60 ( V_118 , L_18 , NULL ) ;
if ( ! V_119 ) {
F_3 ( L_19 , V_115 ) ;
F_66 ( L_20 , V_115 ) ;
F_61 ( V_118 ) ;
return - V_24 ;
}
V_14 = * V_119 ;
if ( V_14 < 0x50 )
V_14 += 0x50 ;
} else
V_14 = * V_119 ;
V_12 -> V_14 = V_14 & 0x0000ffff ;
V_119 = F_60 ( V_118 , L_21 , NULL ) ;
if ( V_119 ) {
V_12 -> V_18 = * V_119 ;
V_12 -> V_15 = ( * V_119 ) ? 0x5 : 0x4 ;
V_12 -> V_16 = ( * V_119 ) ? 0x4 : 0x5 ;
} else {
const T_2 * V_120 = NULL ;
V_12 -> V_18 = V_100
&& ! strncmp ( V_115 , L_22 , 13 ) ;
V_12 -> V_15 = 0x4 ;
V_12 -> V_16 = 0x5 ;
if ( V_116 )
V_120 = F_60 ( V_118 , V_116 , NULL ) ;
if ( V_120 ) {
if ( V_120 [ 3 ] == 0x9 && V_120 [ 4 ] == 0x9 ) {
V_12 -> V_15 = 0xd ;
V_12 -> V_16 = 0xc ;
}
if ( V_120 [ 3 ] == 0x1 && V_120 [ 4 ] == 0x1 ) {
V_12 -> V_15 = 0x5 ;
V_12 -> V_16 = 0x4 ;
}
}
}
F_3 ( L_23 ,
V_115 , V_12 -> V_14 , V_12 -> V_18 ) ;
V_17 = F_67 ( V_118 , 0 ) ;
F_61 ( V_118 ) ;
return V_17 ;
}
static void F_68 ( struct V_41 * V_42 )
{
struct V_19 * V_20 = V_42 -> V_43 ;
if ( V_20 -> V_99 ) {
F_3 ( L_24 ) ;
F_7 ( & V_20 -> V_71 , 0 ) ;
F_7 ( & V_20 -> V_73 , 0 ) ;
F_52 ( 200 ) ;
F_7 ( & V_20 -> V_71 , 1 ) ;
F_7 ( & V_20 -> V_73 , 1 ) ;
F_52 ( 100 ) ;
F_7 ( & V_20 -> V_71 , 0 ) ;
F_7 ( & V_20 -> V_73 , 0 ) ;
F_52 ( 100 ) ;
} else {
F_3 ( L_25 ) ;
F_7 ( & V_20 -> V_121 , 0 ) ;
F_52 ( 200 ) ;
F_7 ( & V_20 -> V_121 , 1 ) ;
F_52 ( 100 ) ;
F_7 ( & V_20 -> V_121 , 0 ) ;
F_52 ( 100 ) ;
}
}
static void F_69 ( struct V_41 * V_42 )
{
struct V_19 * V_20 = V_42 -> V_43 ;
if ( V_20 -> V_122 >= 0 )
F_70 ( V_20 -> V_122 ) ;
if ( V_20 -> V_123 >= 0 )
F_70 ( V_20 -> V_123 ) ;
V_20 -> V_124 [ 0 ] = V_20 -> V_25 [ 0 ] ;
V_20 -> V_124 [ 1 ] = V_20 -> V_25 [ 1 ] ;
V_20 -> V_125 [ 0 ] = V_20 -> V_26 [ 0 ] ;
V_20 -> V_125 [ 1 ] = V_20 -> V_26 [ 1 ] ;
V_20 -> V_25 [ 0 ] = V_20 -> V_25 [ 1 ] = 0 ;
F_12 ( V_20 ) ;
if ( ! V_20 -> V_99 ) {
F_7 ( & V_20 -> V_73 , 1 ) ;
F_7 ( & V_20 -> V_71 , 1 ) ;
}
if ( V_42 -> V_51 == V_126 ) {
V_20 -> V_79 |= 1 ;
F_2 ( V_20 -> V_2 . V_6 , V_10 , V_20 -> V_79 ) ;
}
if ( V_20 -> V_99 ) {
F_7 ( & V_20 -> V_73 , 1 ) ;
F_7 ( & V_20 -> V_71 , 1 ) ;
} else
F_7 ( & V_20 -> V_121 , 1 ) ;
}
static void F_71 ( struct V_41 * V_42 )
{
struct V_19 * V_20 = V_42 -> V_43 ;
V_20 -> V_79 &= ~ 1 ;
V_20 -> V_25 [ 0 ] = V_20 -> V_124 [ 0 ] ;
V_20 -> V_25 [ 1 ] = V_20 -> V_124 [ 1 ] ;
V_20 -> V_26 [ 0 ] = V_20 -> V_125 [ 0 ] ;
V_20 -> V_26 [ 1 ] = V_20 -> V_125 [ 1 ] ;
F_68 ( V_42 ) ;
if ( V_20 -> V_2 . V_6 && V_20 -> V_2 . V_127 ) {
if ( V_20 -> V_2 . V_127 ( & V_20 -> V_2 ) < 0 )
F_72 ( V_29 L_26 ) ;
} else
F_72 ( V_29 L_27 ) ;
if ( V_42 -> V_51 == V_52 ) {
F_29 ( V_20 , & V_128 ) ;
F_29 ( V_20 , & V_129 ) ;
F_29 ( V_20 , & V_130 ) ;
F_22 ( V_20 ) ;
} else {
F_34 ( V_20 , V_131 ) ;
F_34 ( V_20 , V_132 ) ;
F_34 ( V_20 , V_133 ) ;
F_29 ( V_20 , & V_134 ) ;
F_29 ( V_20 , & V_135 ) ;
F_23 ( V_20 ) ;
F_41 ( V_20 ) ;
}
F_12 ( V_20 ) ;
if ( V_42 -> V_76 )
V_42 -> V_76 ( V_42 , 0 ) ;
if ( V_20 -> V_122 >= 0 ) {
unsigned char V_46 ;
F_73 ( V_20 -> V_122 ) ;
V_46 = F_10 ( & V_20 -> V_84 ) ;
F_8 ( & V_20 -> V_84 , V_46 | 0x80 ) ;
}
if ( V_20 -> V_123 >= 0 )
F_73 ( V_20 -> V_123 ) ;
}
static int F_74 ( struct V_41 * V_42 )
{
int V_105 ;
struct V_19 * V_20 = V_42 -> V_43 ;
if ( F_64 ( L_28 ,
L_29 ,
& V_20 -> V_121 , 0 ) < 0 )
F_64 ( L_30 ,
L_29 ,
& V_20 -> V_121 , 1 ) ;
if ( F_64 ( L_31 ,
L_32 ,
& V_20 -> V_73 , 0 ) < 0 )
F_64 ( L_31 ,
L_32 ,
& V_20 -> V_73 , 1 ) ;
if ( F_64 ( L_33 ,
L_34 ,
& V_20 -> V_71 , 0 ) < 0 )
F_64 ( L_33 ,
L_34 ,
& V_20 -> V_71 , 1 ) ;
if ( F_64 ( L_35 ,
L_36 ,
& V_20 -> V_75 , 0 ) < 0 )
F_64 ( L_35 ,
L_36 ,
& V_20 -> V_75 , 1 ) ;
V_105 = F_64 ( L_37 ,
NULL , & V_20 -> V_84 , 0 ) ;
if ( V_105 <= V_136 )
V_105 = F_64 ( L_37 ,
NULL , & V_20 -> V_84 , 1 ) ;
if ( V_105 <= V_136 )
V_105 = F_64 ( L_38 ,
NULL , & V_20 -> V_84 , 1 ) ;
V_20 -> V_122 = V_105 ;
V_105 = F_64 ( L_39 ,
NULL , & V_20 -> V_85 , 0 ) ;
if ( V_105 <= V_136 )
V_105 = F_64 ( L_39 ,
NULL , & V_20 -> V_85 , 1 ) ;
if ( V_100 && V_105 <= V_136 )
V_105 = F_64 ( L_40 ,
NULL , & V_20 -> V_85 , 1 ) ;
V_20 -> V_123 = V_105 ;
F_68 ( V_42 ) ;
return 0 ;
}
static void F_75 ( struct V_41 * V_42 )
{
struct V_19 * V_20 = V_42 -> V_43 ;
if ( ! V_20 )
return;
if ( V_20 -> V_122 >= 0 )
F_76 ( V_20 -> V_122 , V_42 ) ;
if ( V_20 -> V_123 >= 0 )
F_76 ( V_20 -> V_123 , V_42 ) ;
F_77 ( & V_20 -> V_121 ) ;
F_77 ( & V_20 -> V_73 ) ;
F_77 ( & V_20 -> V_71 ) ;
F_77 ( & V_20 -> V_84 ) ;
F_78 ( & V_20 -> V_2 ) ;
F_79 ( V_20 ) ;
V_42 -> V_43 = NULL ;
}
int F_80 ( struct V_41 * V_42 )
{
int V_56 , V_4 ;
struct V_19 * V_20 ;
const T_2 * V_137 ;
struct V_110 * V_138 , * V_113 ;
char * V_139 ;
F_81 ( L_41 ) ;
V_20 = F_82 ( sizeof( * V_20 ) , V_140 ) ;
if ( ! V_20 )
return - V_141 ;
V_20 -> V_122 = - 1 ;
V_42 -> V_43 = V_20 ;
V_42 -> V_142 = F_75 ;
V_20 -> V_99 = 0 ;
V_20 -> V_143 = 1 ;
for ( V_113 = V_42 -> V_118 -> V_144 ; V_113 ; V_113 = V_113 -> V_145 ) {
if ( ! strcmp ( V_113 -> V_111 , L_42 ) ) {
if ( F_60 ( V_113 , L_43 , NULL ) )
V_20 -> V_99 = 1 ;
if ( F_60 ( V_113 , L_44 , NULL ) )
V_20 -> V_143 = 0 ;
break;
}
}
if ( ( V_4 = F_74 ( V_42 ) ) < 0 )
return V_4 ;
V_138 = F_58 ( NULL , L_45 ) ;
if ( V_138 == NULL )
V_138 = F_58 ( NULL , L_46 ) ;
if ( V_138 == NULL )
return - V_24 ;
V_137 = F_60 ( V_138 , L_47 , NULL ) ;
if ( V_137 == NULL )
V_137 = F_60 ( V_138 , L_18 , NULL ) ;
if ( V_137 )
V_20 -> V_2 . V_14 = ( * V_137 ) >> 1 ;
else
V_20 -> V_2 . V_14 = V_146 ;
F_61 ( V_138 ) ;
F_3 ( L_48 , V_20 -> V_2 . V_14 ) ;
if ( V_42 -> V_51 == V_52 ) {
V_20 -> V_2 . V_127 = F_5 ;
V_20 -> V_2 . V_111 = L_49 ;
V_139 = L_50 ;
} else {
V_20 -> V_2 . V_127 = F_6 ;
V_20 -> V_2 . V_111 = L_51 ;
V_139 = L_52 ;
}
if ( ( V_4 = F_83 ( & V_20 -> V_2 ) ) < 0 )
return V_4 ;
sprintf ( V_42 -> V_88 -> V_147 , L_53 , V_139 ) ;
if ( V_42 -> V_51 == V_52 ) {
for ( V_56 = 0 ; V_56 < F_13 ( V_148 ) ; V_56 ++ ) {
if ( ( V_4 = F_84 ( V_42 -> V_88 , F_85 ( & V_148 [ V_56 ] , V_42 ) ) ) < 0 )
return V_4 ;
}
} else {
for ( V_56 = 0 ; V_56 < F_13 ( V_149 ) ; V_56 ++ ) {
if ( ( V_4 = F_84 ( V_42 -> V_88 , F_85 ( & V_149 [ V_56 ] , V_42 ) ) ) < 0 )
return V_4 ;
}
}
V_42 -> V_97 = F_85 ( & V_150 , V_42 ) ;
if ( ( V_4 = F_84 ( V_42 -> V_88 , V_42 -> V_97 ) ) < 0 )
return V_4 ;
V_42 -> V_101 = F_85 ( & V_151 , V_42 ) ;
if ( ( V_4 = F_84 ( V_42 -> V_88 , V_42 -> V_101 ) ) < 0 )
return V_4 ;
if ( V_20 -> V_75 . V_14 != 0 ) {
V_42 -> V_98 = F_85 ( & V_152 , V_42 ) ;
if ( ( V_4 = F_84 ( V_42 -> V_88 , V_42 -> V_98 ) ) < 0 )
return V_4 ;
}
V_42 -> V_103 = F_85 ( & V_153 , V_42 ) ;
if ( ( V_4 = F_84 ( V_42 -> V_88 , V_42 -> V_103 ) ) < 0 )
return V_4 ;
if ( V_42 -> V_51 == V_52 )
V_20 -> V_48 = ( V_49 * 6 ) / 10 ;
else
V_20 -> V_48 = ( V_53 * 6 ) / 10 ;
V_20 -> V_47 = 1 ;
if ( V_42 -> V_51 == V_52 )
F_22 ( V_20 ) ;
else
F_23 ( V_20 ) ;
#ifdef F_86
V_42 -> V_154 = F_69 ;
V_42 -> V_155 = F_71 ;
#endif
F_87 ( & V_104 , F_50 ) ;
V_93 = V_42 ;
#ifdef F_40
if ( ( V_20 -> V_122 >= 0 || V_20 -> V_123 >= 0 )
&& ( V_4 = F_88 ( V_42 ) ) < 0 )
return V_4 ;
V_42 -> V_156 = F_46 ;
V_42 -> V_76 = F_54 ;
F_54 ( V_42 , 0 ) ;
if ( V_20 -> V_122 >= 0 ) {
unsigned char V_46 ;
if ( ( V_4 = F_89 ( V_20 -> V_122 , F_56 , 0 ,
L_54 , V_42 ) ) < 0 )
return 0 ;
V_46 = F_10 ( & V_20 -> V_84 ) ;
F_8 ( & V_20 -> V_84 , V_46 | 0x80 ) ;
}
if ( V_20 -> V_123 >= 0 ) {
unsigned char V_46 ;
if ( ( V_4 = F_89 ( V_20 -> V_123 , F_56 , 0 ,
L_55 , V_42 ) ) < 0 )
return 0 ;
V_46 = F_10 ( & V_20 -> V_85 ) ;
F_8 ( & V_20 -> V_85 , V_46 | 0x80 ) ;
}
#endif
return 0 ;
}

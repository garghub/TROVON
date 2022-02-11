static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_4 = V_2 -> V_4 ;
if ( V_3 -> V_5 & ( 1 << V_4 ) )
return 1 ;
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_4 = V_2 -> V_4 ;
F_3 ( & V_2 -> V_7 ) ;
if ( V_6 )
V_3 -> V_5 |= ( 1 << V_4 ) ;
else
V_3 -> V_5 &= ~ ( 1 << V_4 ) ;
F_4 ( V_2 -> V_3 , V_8 ,
1 << V_2 -> V_4 ) ;
V_2 -> V_9 = 0 ;
F_4 ( V_3 , V_10 ,
F_5 ( V_3 -> V_5 ) |
( F_6 ( V_3 ) >> 16 ) ) ;
if ( V_3 -> V_5 )
F_7 ( V_3 , V_11 ) ;
else
F_8 ( V_3 , V_11 ) ;
F_9 ( & V_2 -> V_7 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
F_11 ( & V_2 -> V_7 ) ;
V_2 -> V_12 = ( V_2 -> V_13 & 0x08 ) ? 1 : 0 ;
V_2 -> V_14 = F_12 ( V_3 -> V_15 / V_2 -> V_16 , 1 ) ;
switch ( V_2 -> V_13 ) {
case V_17 :
V_2 -> V_18 = V_3 -> V_19 >> 1 ;
V_2 -> V_20 = V_3 -> V_21 ;
break;
case V_22 :
V_2 -> V_18 = V_3 -> V_19 ;
V_2 -> V_20 = V_3 -> V_21 << 1 ;
V_2 -> V_14 <<= 2 ;
break;
default:
F_13 ( 1 , L_1 ) ;
}
}
static int F_14 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
T_1 V_4 = V_2 -> V_4 ;
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_16 ;
F_11 ( & V_2 -> V_7 ) ;
if ( V_24 -> V_26 )
return 0 ;
F_10 ( V_2 ) ;
if ( ! F_15 ( & V_2 -> V_27 ) ) {
if ( V_2 -> V_14 > V_3 -> V_28 )
return - V_29 ;
else
V_3 -> V_28 -= V_2 -> V_14 ;
}
V_24 -> V_26 = 1 ;
V_24 -> V_30 = V_2 -> V_3 -> V_31 ;
if ( V_24 -> type == V_32 )
F_4 ( V_3 , F_16 ( V_4 ) , 1 ) ;
if ( F_17 ( & V_2 -> V_27 ) > 1 )
return 0 ;
F_4 ( V_3 , F_18 ( V_4 ) , 0 ) ;
F_4 ( V_3 , F_19 ( V_4 ) ,
V_2 -> V_12 ? 1 : 0 ) ;
if ( V_2 -> V_12 )
V_16 = V_2 -> V_16 - 1 ;
else
V_16 = V_2 -> V_16 ;
F_4 ( V_3 , F_20 ( V_4 ) , V_2 -> V_33 ) ;
F_4 ( V_3 , F_21 ( V_4 ) , V_2 -> V_34 ) ;
F_4 ( V_3 , F_22 ( V_4 ) , V_16 ) ;
F_4 ( V_3 , F_23 ( V_4 ) , V_2 -> V_33 ) ;
F_4 ( V_3 , F_24 ( V_4 ) , V_2 -> V_34 ) ;
F_4 ( V_3 , F_25 ( V_4 ) , V_16 ) ;
F_4 ( V_3 , F_18 ( V_4 ) , V_2 -> V_13 ) ;
F_26 ( 10 ) ;
return 0 ;
}
static void F_27 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( ! V_24 -> V_26 )
return;
if ( V_24 -> V_35 ) {
F_28 ( V_24 -> V_35 ) ;
V_24 -> V_35 = NULL ;
}
V_3 -> V_28 += V_2 -> V_14 ;
V_24 -> V_26 = 0 ;
if ( F_29 ( & V_2 -> V_27 ) > 0 )
return;
F_4 ( V_3 , F_18 ( V_2 -> V_4 ) , 0 ) ;
F_4 ( V_3 , F_16 ( V_2 -> V_4 ) , 0 ) ;
}
static int F_30 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
V_24 -> V_35 = F_31 ( V_36 , V_24 , V_37 L_2 ) ;
if ( F_32 ( V_24 -> V_35 ) ) {
F_3 ( & V_2 -> V_7 ) ;
F_27 ( V_24 ) ;
F_9 ( & V_2 -> V_7 ) ;
return F_33 ( V_24 -> V_35 ) ;
}
return 0 ;
}
static void F_34 ( struct V_3 * V_3 , T_1 V_4 )
{
F_35 ( V_4 >= V_3 -> V_38 ) ;
F_4 ( V_3 , F_20 ( V_4 ) , 1 ) ;
V_3 -> V_39 [ V_4 ] -> V_40 = 1 ;
}
static int F_36 ( struct V_3 * V_3 , T_1 V_4 , T_1 V_41 )
{
F_35 ( V_4 >= V_3 -> V_38 ) ;
if ( ! V_3 -> V_39 [ V_4 ] -> V_40 )
return 0 ;
if ( V_41 )
return 1 ;
V_3 -> V_39 [ V_4 ] -> V_40 = 0 ;
F_4 ( V_3 , F_20 ( V_4 ) ,
V_3 -> V_39 [ V_4 ] -> V_33 ) ;
return 0 ;
}
static void F_37 ( struct V_42 * V_43 , void * V_44 , int V_45 )
{
struct V_42 * V_46 ;
T_1 * V_47 = V_44 ;
for ( V_46 = V_43 ; V_46 && V_45 > 0 ; V_46 = F_38 ( V_46 ) ) {
T_1 * V_48 = F_39 ( V_46 ) ;
T_2 V_49 = F_40 ( V_46 ) ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_49 && V_45 ; V_50 ++ )
V_48 [ V_50 ] = * ( V_47 ++ ) ;
}
}
static int F_41 ( struct V_3 * V_3 ,
struct V_51 * V_52 ,
struct V_42 * V_43 , int V_53 ,
unsigned int V_54 , unsigned int V_45 )
{
int V_55 ;
if ( V_54 > F_42 ( V_3 ) )
return - V_56 ;
if ( V_54 + V_45 <= F_42 ( V_3 ) ) {
return F_43 ( V_3 , V_57 ,
V_52 , 0 , V_43 , V_53 ,
F_44 ( V_3 ) + V_54 , V_45 ) ;
}
V_55 = F_43 ( V_3 , V_57 , V_52 , 0 ,
V_43 , V_53 , F_44 ( V_3 ) + V_54 ,
F_42 ( V_3 ) - V_54 ) ;
V_55 |= F_43 ( V_3 , V_57 , V_52 , 0 ,
V_43 , V_53 + F_42 ( V_3 ) - V_54 ,
F_44 ( V_3 ) ,
V_45 + V_54 - F_42 ( V_3 ) ) ;
return V_55 ;
}
static int F_45 ( struct V_3 * V_3 ,
T_3 V_44 , unsigned int V_54 ,
unsigned int V_45 )
{
int V_55 ;
if ( V_54 > F_42 ( V_3 ) )
return - V_56 ;
if ( V_54 + V_45 <= F_42 ( V_3 ) ) {
return F_46 ( V_3 , V_57 , 0 , V_44 ,
F_44 ( V_3 ) + V_54 , V_45 ) ;
}
V_55 = F_46 ( V_3 , V_57 , 0 , V_44 ,
F_44 ( V_3 ) + V_54 ,
F_42 ( V_3 ) - V_54 ) ;
V_55 |= F_46 ( V_3 , V_57 , 0 ,
V_44 + F_42 ( V_3 ) - V_54 ,
F_44 ( V_3 ) ,
V_45 + V_54 - F_42 ( V_3 ) ) ;
return V_55 ;
}
static int F_47 ( struct V_3 * V_3 , void * V_44 ,
unsigned int V_54 , unsigned int V_45 )
{
int V_55 ;
T_3 V_58 = F_48 ( V_3 -> V_59 , V_44 , V_45 ,
V_60 ) ;
V_55 = F_45 ( V_3 , V_58 , V_54 , V_45 ) ;
F_49 ( V_3 -> V_59 , V_58 , V_45 , V_60 ) ;
return V_55 ;
}
static int F_50 ( struct V_3 * V_3 ,
struct V_51 * V_52 ,
struct V_42 * V_43 , int V_53 ,
unsigned int V_54 , unsigned int V_45 )
{
int V_55 ;
if ( V_54 > F_51 ( V_3 ) )
return - V_56 ;
if ( V_54 + V_45 <= F_51 ( V_3 ) ) {
return F_43 ( V_3 , V_61 ,
V_52 , 0 , V_43 , V_53 ,
F_52 ( V_3 ) + V_54 , V_45 ) ;
}
V_55 = F_43 ( V_3 , V_61 , V_52 , 0 ,
V_43 , V_53 , F_52 ( V_3 ) + V_54 ,
F_51 ( V_3 ) - V_54 ) ;
V_55 |= F_43 ( V_3 , V_61 , V_52 , 0 ,
V_43 , V_53 + F_51 ( V_3 ) - V_54 ,
F_52 ( V_3 ) ,
V_45 + V_54 - F_51 ( V_3 ) ) ;
return V_55 ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_62 * V_63 )
{
struct V_42 * V_46 ;
void * V_47 = V_64 ;
T_2 V_65 = 0 ;
T_2 V_66 = sizeof( V_64 ) ;
for ( V_46 = V_63 -> V_43 ; V_46 && V_65 < V_66 ; V_46 = F_38 ( V_46 ) ) {
T_2 V_67 = F_54 ( F_40 ( V_46 ) ,
( unsigned int ) ( V_66 - V_65 ) ) ;
T_1 * V_48 = F_39 ( V_46 ) ;
memcpy ( V_48 , V_47 + V_65 , V_67 ) ;
if ( F_55 ( V_65 , V_67 , V_68 + 5 ) )
V_48 [ ( V_68 + 5 ) - V_65 ] =
0xff & ( V_2 -> V_20 >> 8 ) ;
if ( F_55 ( V_65 , V_67 , V_68 + 6 ) )
V_48 [ ( V_68 + 6 ) - V_65 ] = 0xff & V_2 -> V_20 ;
if ( F_55 ( V_65 , V_67 , V_68 + 7 ) )
V_48 [ ( V_68 + 7 ) - V_65 ] =
0xff & ( V_2 -> V_18 >> 8 ) ;
if ( F_55 ( V_65 , V_67 , V_68 + 8 ) )
V_48 [ ( V_68 + 8 ) - V_65 ] = 0xff & V_2 -> V_18 ;
V_65 += V_67 ;
}
}
static int F_56 ( struct V_23 * V_24 , struct V_69 * V_70 ,
struct V_71 * V_72 ,
struct V_62 * V_63 )
{
struct V_3 * V_3 = V_24 -> V_25 -> V_3 ;
int V_45 = V_70 -> V_73 ;
F_53 ( V_24 -> V_25 , V_63 ) ;
V_72 -> V_45 = V_45 + sizeof( V_64 ) ;
return F_50 ( V_3 , V_24 -> V_52 , V_63 -> V_43 ,
sizeof( V_64 ) ,
V_70 -> V_74 , V_45 ) ;
}
static inline int F_57 ( T_4 * V_75 )
{
return ( F_58 ( V_75 [ 0 ] ) >> 30 ) & 1 ;
}
static inline T_5 F_59 ( T_4 * V_75 )
{
return F_58 ( V_75 [ 0 ] ) & 0xFFFFF ;
}
static inline T_1 F_60 ( T_4 * V_75 )
{
return ( F_58 ( V_75 [ 1 ] ) >> 8 ) & 0xFF ;
}
static inline T_1 F_61 ( T_4 * V_75 )
{
return F_58 ( V_75 [ 1 ] ) & 0xFF ;
}
static void F_62 ( T_1 * * V_76 , unsigned * V_77 , const T_1 * V_47 , unsigned V_78 )
{
memcpy ( * V_76 , V_47 , V_78 ) ;
* V_76 += V_78 ;
* V_77 += V_78 * 8 ;
}
static void F_63 ( T_1 * * V_76 , unsigned * V_77 , T_5 V_79 , unsigned V_78 )
{
V_79 <<= 32 - V_78 ;
while ( V_78 -- ) {
* * V_76 <<= 1 ;
* * V_76 |= ! ! ( V_79 & ( 1 << 31 ) ) ;
V_79 <<= 1 ;
if ( ++ ( * V_77 ) % 8 == 0 )
( * V_76 ) ++ ;
}
}
static void F_64 ( T_1 * * V_76 , unsigned * V_77 , unsigned V_79 )
{
T_6 F_12 = 0 , V_80 = 0 ;
while ( V_79 > F_12 ) {
F_12 = ( F_12 + 2 ) * 2 - 2 ;
V_80 ++ ;
}
F_63 ( V_76 , V_77 , 1 , V_80 + 1 ) ;
F_63 ( V_76 , V_77 , ~ ( F_12 - V_79 ) , V_80 ) ;
}
static void F_65 ( T_1 * * V_76 , unsigned * V_77 , int V_79 )
{
if ( V_79 <= 0 )
F_64 ( V_76 , V_77 , - V_79 * 2 ) ;
else
F_64 ( V_76 , V_77 , V_79 * 2 - 1 ) ;
}
static void F_66 ( T_1 * * V_76 , unsigned * V_77 )
{
F_63 ( V_76 , V_77 , 0 , 1 ) ;
if ( * V_77 % 32 )
F_63 ( V_76 , V_77 , 0xFFFFFFFF , 32 - * V_77 % 32 ) ;
}
static void F_67 ( T_1 * * V_76 , unsigned * V_77 , int V_81 )
{
F_63 ( V_76 , V_77 , 1 , 1 ) ;
while ( ( * V_77 ) % 8 )
F_63 ( V_76 , V_77 , 0 , 1 ) ;
if ( V_81 )
while ( ( * V_77 ) % 32 )
F_63 ( V_76 , V_77 , 0 , 1 ) ;
}
static void F_68 ( T_1 * * V_76 , struct V_3 * V_3 ,
T_4 * V_75 , unsigned V_15 , unsigned V_16 )
{
static const T_1 V_82 [] = {
0 , 0 , 1 , 0x00 ,
0 , 0 , 1 , 0x20
} ;
unsigned V_77 = 0 ;
unsigned V_18 = F_60 ( V_75 ) << 4 ;
unsigned V_20 = F_61 ( V_75 ) << 4 ;
unsigned V_12 = F_57 ( V_75 ) ;
F_62 ( V_76 , & V_77 , V_82 , sizeof( V_82 ) ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0x04 , 8 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 2 , 4 ) ;
F_63 ( V_76 , & V_77 , 0 , 3 ) ;
if ( V_3 -> V_83 == V_84 )
F_63 ( V_76 , & V_77 , 3 , 4 ) ;
else
F_63 ( V_76 , & V_77 , 2 , 4 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 2 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 2 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , V_15 , 16 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , V_16 , 15 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , V_18 , 13 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , V_20 , 13 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , V_12 , 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 2 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 0 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_66 ( V_76 , & V_77 ) ;
}
static void F_69 ( T_1 * * V_76 , struct V_3 * V_3 , T_4 * V_75 )
{
static const T_1 V_85 [] = {
0 , 0 , 0 , 1 , 0x67 , 66 ,
0 , 30
} ;
static const T_1 V_86 [] = {
0 , 0 , 0 , 1 , 0x68
} ;
unsigned V_77 = 0 ;
unsigned V_87 = F_60 ( V_75 ) ;
unsigned V_88 = F_61 ( V_75 ) ;
F_62 ( V_76 , & V_77 , V_85 , sizeof( V_85 ) ) ;
F_64 ( V_76 , & V_77 , 0 ) ;
F_64 ( V_76 , & V_77 , 5 ) ;
F_64 ( V_76 , & V_77 , 0 ) ;
F_64 ( V_76 , & V_77 , 6 ) ;
F_64 ( V_76 , & V_77 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_64 ( V_76 , & V_77 , V_87 - 1 ) ;
F_64 ( V_76 , & V_77 , V_88 - 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_67 ( V_76 , & V_77 , 0 ) ;
F_62 ( V_76 , & V_77 , V_86 , sizeof( V_86 ) ) ;
F_64 ( V_76 , & V_77 , 0 ) ;
F_64 ( V_76 , & V_77 , 0 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_64 ( V_76 , & V_77 , 0 ) ;
F_64 ( V_76 , & V_77 , 0 ) ;
F_64 ( V_76 , & V_77 , 0 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 2 ) ;
F_65 ( V_76 , & V_77 , 0 ) ;
F_65 ( V_76 , & V_77 , 0 ) ;
F_65 ( V_76 , & V_77 , 2 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_63 ( V_76 , & V_77 , 1 , 1 ) ;
F_63 ( V_76 , & V_77 , 0 , 1 ) ;
F_67 ( V_76 , & V_77 , 1 ) ;
}
static int F_70 ( struct V_23 * V_24 , struct V_69 * V_70 ,
struct V_71 * V_72 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
#define F_71 16
#define F_72 64
T_4 V_75 [ F_71 ] ;
int V_55 ;
int V_89 , V_90 ;
int V_53 = 0 ;
if ( F_73 ( V_70 -> V_45 <= sizeof( V_75 ) ) )
return - V_56 ;
V_55 = F_47 ( V_3 , V_75 , V_70 -> V_54 , sizeof( V_75 ) ) ;
if ( F_73 ( V_55 ) )
return V_55 ;
if ( F_73 ( F_59 ( V_75 ) > V_70 -> V_45 ) )
return - V_56 ;
V_72 -> V_18 = F_60 ( V_75 ) << 4 ;
V_72 -> V_20 = F_61 ( V_75 ) << 4 ;
V_72 -> V_45 = F_59 ( V_75 ) ;
if ( ! V_70 -> V_41 ) {
T_1 V_91 [ F_72 ] , * V_76 = V_91 ;
if ( V_3 -> V_92 & V_93 )
F_69 ( & V_76 , V_3 , V_75 ) ;
else
F_68 ( & V_76 , V_3 , V_75 ,
V_3 -> V_15 * 1000 ,
V_2 -> V_16 * 1000 ) ;
V_53 = V_76 - V_91 ;
F_37 ( V_63 -> V_43 , V_91 , V_53 ) ;
V_72 -> V_45 += V_53 ;
}
V_90 = ( V_70 -> V_54 + sizeof( V_75 ) ) % F_42 ( V_3 ) ;
V_89 = V_70 -> V_45 - sizeof( V_75 ) ;
V_55 = F_41 ( V_3 , V_24 -> V_52 , V_63 -> V_43 ,
V_53 , V_90 , V_89 ) ;
F_73 ( V_55 ) ;
return V_55 ;
}
static void F_74 ( struct V_23 * V_24 ,
struct V_71 * V_72 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_69 * V_70 = NULL ;
struct V_62 * V_63 ;
int V_55 ;
int error = 1 ;
T_7 V_94 = V_24 -> V_30 ;
while ( V_94 != V_3 -> V_31 ) {
struct V_69 * V_95 = & V_3 -> V_70 [ V_94 ] ;
V_94 = ( V_94 + 1 ) % V_96 ;
if ( V_95 -> V_4 != V_2 -> V_4 )
continue;
if ( V_24 -> V_97 == V_98 ) {
if ( V_24 -> type == V_95 -> type ) {
V_70 = V_95 ;
break;
}
} else {
V_70 = V_95 ;
}
}
V_24 -> V_30 = V_94 ;
if ( F_73 ( ! V_70 ) )
goto V_99;
if ( ( V_24 -> V_97 == V_98 &&
V_72 -> V_100 < V_70 -> V_45 ) ||
( V_24 -> V_97 == V_101 &&
V_72 -> V_100 < ( V_70 -> V_73 + sizeof( V_64 ) ) ) ) {
F_73 ( 1 ) ;
goto V_99;
}
V_63 = F_75 ( V_72 ) ;
if ( F_73 ( ! V_63 ) )
goto V_99;
if ( V_24 -> V_97 == V_98 )
V_55 = F_70 ( V_24 , V_70 , V_72 , V_63 ) ;
else
V_55 = F_56 ( V_24 , V_70 , V_72 , V_63 ) ;
if ( ! V_55 )
error = 0 ;
V_99:
if ( error ) {
V_72 -> V_102 = V_103 ;
} else {
V_72 -> V_104 ++ ;
V_72 -> V_105 = V_70 -> V_105 ;
V_72 -> V_102 = V_106 ;
}
F_76 ( & V_72 -> V_107 ) ;
return;
}
static void F_77 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_71 * V_72 ;
for (; ; ) {
F_3 ( & V_2 -> V_7 ) ;
if ( V_24 -> V_30 == V_3 -> V_31 )
break;
if ( F_78 ( & V_24 -> V_108 ) )
break;
V_72 = F_79 ( & V_24 -> V_108 ,
struct V_71 , V_109 ) ;
if ( ! F_80 ( & V_72 -> V_107 ) )
break;
F_81 ( & V_72 -> V_109 ) ;
F_9 ( & V_2 -> V_7 ) ;
F_74 ( V_24 , V_72 ) ;
}
F_11 ( & V_2 -> V_7 ) ;
F_9 ( & V_2 -> V_7 ) ;
}
static int V_36 ( void * V_110 )
{
struct V_23 * V_24 = V_110 ;
struct V_1 * V_2 = V_24 -> V_25 ;
F_82 ( V_111 , V_112 ) ;
F_83 () ;
F_84 ( & V_2 -> V_113 , & V_111 ) ;
for (; ; ) {
long V_114 = F_85 ( V_115 ) ;
if ( V_114 == - V_116 || F_86 () )
break;
F_77 ( V_24 ) ;
F_87 () ;
}
F_88 ( & V_2 -> V_113 , & V_111 ) ;
return 0 ;
}
void F_89 ( struct V_3 * V_3 )
{
T_5 V_117 ;
int V_50 ;
F_4 ( V_3 , V_118 , V_11 ) ;
V_117 = F_90 ( V_3 , V_119 ) ;
for ( V_50 = 0 ; V_50 < V_3 -> V_38 ; V_50 ++ ) {
struct V_1 * V_2 = V_3 -> V_39 [ V_50 ] ;
F_35 ( V_2 == NULL ) ;
if ( V_2 -> V_9 )
continue;
if ( ! ( V_117 & ( 1 << V_50 ) ) )
continue;
V_2 -> V_9 = 1 ;
}
}
void F_91 ( struct V_3 * V_3 )
{
struct V_69 * V_70 ;
T_5 V_120 , V_121 , V_122 ;
T_5 V_123 , V_124 , V_73 ;
T_5 V_125 ;
T_1 V_126 , V_127 ;
T_1 V_4 ;
enum V_128 V_129 ;
F_4 ( V_3 , V_118 , V_130 ) ;
V_126 = ( ( F_90 ( V_3 , F_92 ( 11 ) ) & 0xF ) + 1 ) % V_131 ;
V_125 = ( ( F_90 ( V_3 , F_92 ( 0 ) ) & 0xFFFFF ) + 64 + 8 ) & ~ 7 ;
while ( V_3 -> V_132 != V_126 ) {
V_120 = F_90 ( V_3 ,
F_93 ( V_3 -> V_132 ) ) ;
V_123 = F_90 ( V_3 ,
F_94 ( V_3 -> V_132 ) ) ;
V_3 -> V_132 = ( V_3 -> V_132 + 1 ) % V_131 ;
V_121 = F_90 ( V_3 ,
F_93 ( V_3 -> V_132 ) ) ;
V_124 = F_90 ( V_3 ,
F_94 ( V_3 -> V_132 ) ) ;
V_4 = ( V_120 >> 24 ) & 0x1f ;
if ( V_4 >= V_133 ) {
V_4 -= V_133 ;
V_129 = V_32 ;
} else
V_129 = V_134 ;
V_127 = ( V_120 >> 29 ) & 3 ;
V_120 &= 0x00ffffff ;
V_121 &= 0x00ffffff ;
V_123 &= 0x00ffffff ;
V_124 &= 0x00ffffff ;
V_122 = ( F_42 ( V_3 ) +
V_121 - V_120 ) %
F_42 ( V_3 ) ;
V_73 = ( F_51 ( V_3 ) +
V_124 - V_123 ) %
F_51 ( V_3 ) ;
if ( V_120 > V_121 && V_122 != V_125 ) {
F_34 ( V_3 , V_4 ) ;
continue;
}
if ( F_36 ( V_3 , V_4 , V_127 ) )
continue;
V_70 = & V_3 -> V_70 [ V_3 -> V_31 ] ;
V_70 -> V_41 = V_127 ;
V_70 -> V_4 = V_4 ;
V_70 -> V_54 = V_120 ;
V_70 -> V_45 = V_122 ;
V_70 -> V_74 = V_123 ;
V_70 -> V_73 = V_73 ;
V_70 -> type = V_129 ;
F_95 ( & V_70 -> V_105 ) ;
V_3 -> V_31 = ( V_3 -> V_31 + 1 ) %
V_96 ;
F_96 ( & V_3 -> V_39 [ V_4 ] -> V_113 ) ;
}
return;
}
static int F_97 ( struct V_135 * V_136 , unsigned int * V_78 ,
unsigned int * V_45 )
{
* V_45 = V_137 ;
if ( * V_78 < V_138 )
* V_78 = V_138 ;
return 0 ;
}
static int F_98 ( struct V_135 * V_136 ,
struct V_71 * V_72 ,
enum V_139 V_140 )
{
struct V_23 * V_24 = V_136 -> V_141 ;
struct V_1 * V_2 = V_24 -> V_25 ;
V_72 -> V_45 = V_137 ;
if ( V_72 -> V_142 != 0 && V_72 -> V_100 < V_72 -> V_45 )
return - V_56 ;
V_72 -> V_18 = V_2 -> V_18 ;
V_72 -> V_20 = V_2 -> V_20 ;
V_72 -> V_140 = V_140 ;
if ( V_72 -> V_102 == V_143 ) {
int V_144 = F_99 ( V_136 , V_72 , NULL ) ;
if ( V_144 < 0 ) {
struct V_62 * V_145 = F_75 ( V_72 ) ;
F_100 ( V_136 -> V_146 , V_145 ) ;
F_101 ( V_145 ) ;
V_72 -> V_102 = V_143 ;
return V_144 ;
}
}
V_72 -> V_102 = V_147 ;
return 0 ;
}
static void F_102 ( struct V_135 * V_136 ,
struct V_71 * V_72 )
{
struct V_23 * V_24 = V_136 -> V_141 ;
V_72 -> V_102 = V_148 ;
F_103 ( & V_72 -> V_109 , & V_24 -> V_108 ) ;
F_96 ( & V_24 -> V_25 -> V_113 ) ;
}
static void F_104 ( struct V_135 * V_136 ,
struct V_71 * V_72 )
{
struct V_62 * V_145 = F_75 ( V_72 ) ;
F_100 ( V_136 -> V_146 , V_145 ) ;
F_101 ( V_145 ) ;
V_72 -> V_102 = V_143 ;
}
static unsigned int F_105 ( struct V_149 * V_149 ,
struct V_150 * V_111 )
{
struct V_23 * V_24 = V_149 -> V_151 ;
return F_106 ( V_149 , & V_24 -> V_152 , V_111 ) ;
}
static int F_107 ( struct V_149 * V_149 , struct V_153 * V_154 )
{
struct V_23 * V_24 = V_149 -> V_151 ;
return F_108 ( & V_24 -> V_152 , V_154 ) ;
}
static int F_109 ( struct V_149 * V_149 )
{
struct V_1 * V_2 = F_110 ( V_149 ) ;
struct V_23 * V_24 ;
V_24 = F_111 ( sizeof( * V_24 ) , V_155 ) ;
if ( V_24 == NULL )
return - V_156 ;
V_24 -> V_25 = V_2 ;
V_149 -> V_151 = V_24 ;
F_112 ( & V_24 -> V_108 ) ;
V_24 -> V_97 = V_98 ;
V_24 -> type = V_134 ;
F_113 ( & V_24 -> V_152 , & V_157 ,
& V_2 -> V_3 -> V_59 -> V_146 ,
& V_2 -> V_7 ,
V_158 ,
V_159 ,
sizeof( struct V_71 ) , V_24 , NULL ) ;
return 0 ;
}
static T_8 F_114 ( struct V_149 * V_149 , char T_9 * V_110 ,
T_2 V_78 , T_10 * V_160 )
{
struct V_23 * V_24 = V_149 -> V_151 ;
struct V_1 * V_2 = V_24 -> V_25 ;
if ( ! V_24 -> V_26 ) {
int V_55 ;
F_3 ( & V_2 -> V_7 ) ;
V_55 = F_14 ( V_24 ) ;
F_9 ( & V_2 -> V_7 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_30 ( V_24 ) ;
if ( V_55 )
return V_55 ;
}
return F_115 ( & V_24 -> V_152 , V_110 , V_78 , V_160 , 0 ,
V_149 -> V_161 & V_162 ) ;
}
static int F_116 ( struct V_149 * V_149 )
{
struct V_23 * V_24 = V_149 -> V_151 ;
struct V_1 * V_2 = V_24 -> V_25 ;
F_117 ( & V_24 -> V_152 ) ;
F_118 ( & V_24 -> V_152 ) ;
F_3 ( & V_2 -> V_7 ) ;
F_27 ( V_24 ) ;
F_9 ( & V_2 -> V_7 ) ;
F_119 ( V_24 ) ;
return 0 ;
}
static int F_120 ( struct V_149 * V_149 , void * V_163 ,
struct V_164 * V_165 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
strcpy ( V_165 -> V_166 , V_37 ) ;
snprintf ( V_165 -> V_167 , sizeof( V_165 -> V_167 ) , L_3 ,
V_2 -> V_4 ) ;
snprintf ( V_165 -> V_168 , sizeof( V_165 -> V_168 ) , L_4 ,
F_121 ( V_3 -> V_59 ) ) ;
V_165 -> V_169 = V_170 ;
V_165 -> V_171 = V_172 |
V_173 |
V_174 ;
return 0 ;
}
static int F_122 ( struct V_149 * V_149 , void * V_163 ,
struct V_175 * V_176 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
if ( V_176 -> V_177 )
return - V_56 ;
snprintf ( V_176 -> V_178 , sizeof( V_176 -> V_178 ) , L_5 ,
V_2 -> V_4 + 1 ) ;
V_176 -> type = V_179 ;
if ( V_3 -> V_83 == V_84 )
V_176 -> V_180 = V_181 ;
else
V_176 -> V_180 = V_182 ;
if ( ! F_123 ( V_3 , V_2 -> V_4 ) )
V_176 -> V_117 = V_183 ;
return 0 ;
}
static int F_124 ( struct V_149 * V_149 , void * V_163 , unsigned int V_177 )
{
if ( V_177 )
return - V_56 ;
return 0 ;
}
static int F_125 ( struct V_149 * V_149 , void * V_163 ,
unsigned int * V_177 )
{
* V_177 = 0 ;
return 0 ;
}
static int F_126 ( struct V_149 * V_149 , void * V_163 ,
struct V_184 * V_185 )
{
switch ( V_185 -> V_177 ) {
case 0 :
V_185 -> V_186 = V_98 ;
strcpy ( V_185 -> V_187 , L_6 ) ;
break;
case 1 :
V_185 -> V_186 = V_101 ;
strcpy ( V_185 -> V_187 , L_7 ) ;
break;
default:
return - V_56 ;
}
V_185 -> V_92 = V_188 ;
return 0 ;
}
static int F_127 ( struct V_149 * V_149 , void * V_163 ,
struct V_189 * V_185 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_190 * V_191 = & V_185 -> V_97 . V_191 ;
if ( V_191 -> V_186 != V_98 &&
V_191 -> V_186 != V_101 )
return - V_56 ;
if ( F_15 ( & V_2 -> V_27 ) > 0 ) {
if ( V_191 -> V_18 != V_2 -> V_18 ||
V_191 -> V_20 != V_2 -> V_20 )
return - V_29 ;
}
if ( V_191 -> V_18 < V_3 -> V_19 ||
V_191 -> V_20 < V_3 -> V_21 << 1 ) {
V_191 -> V_18 = V_3 -> V_19 >> 1 ;
V_191 -> V_20 = V_3 -> V_21 ;
} else {
V_191 -> V_18 = V_3 -> V_19 ;
V_191 -> V_20 = V_3 -> V_21 << 1 ;
}
if ( V_191 -> V_140 == V_192 )
V_191 -> V_140 = V_159 ;
else if ( V_191 -> V_140 != V_159 )
V_191 -> V_140 = V_159 ;
V_191 -> V_193 = V_194 ;
V_191 -> V_195 = V_137 ;
return 0 ;
}
static int F_128 ( struct V_149 * V_149 , void * V_163 ,
struct V_189 * V_185 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_190 * V_191 = & V_185 -> V_97 . V_191 ;
int V_55 ;
F_3 ( & V_2 -> V_7 ) ;
V_55 = F_127 ( V_149 , V_163 , V_185 ) ;
if ( V_55 ) {
F_9 ( & V_2 -> V_7 ) ;
return V_55 ;
}
if ( V_191 -> V_18 == V_3 -> V_19 )
V_2 -> V_13 = V_22 ;
else
V_2 -> V_13 = V_17 ;
V_24 -> V_97 = V_191 -> V_186 ;
if ( V_191 -> V_163 )
V_24 -> type = V_32 ;
V_55 = F_14 ( V_24 ) ;
F_9 ( & V_2 -> V_7 ) ;
if ( V_55 )
return V_55 ;
return F_30 ( V_24 ) ;
}
static int F_129 ( struct V_149 * V_149 , void * V_163 ,
struct V_189 * V_185 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_190 * V_191 = & V_185 -> V_97 . V_191 ;
V_191 -> V_18 = V_2 -> V_18 ;
V_191 -> V_20 = V_2 -> V_20 ;
V_191 -> V_186 = V_24 -> V_97 ;
V_191 -> V_140 = V_2 -> V_12 ? V_159 :
V_196 ;
V_191 -> V_195 = V_137 ;
V_191 -> V_193 = V_194 ;
return 0 ;
}
static int F_130 ( struct V_149 * V_149 , void * V_163 ,
struct V_197 * V_198 )
{
struct V_23 * V_24 = V_163 ;
return F_131 ( & V_24 -> V_152 , V_198 ) ;
}
static int F_132 ( struct V_149 * V_149 , void * V_163 ,
struct V_199 * V_44 )
{
struct V_23 * V_24 = V_163 ;
return F_133 ( & V_24 -> V_152 , V_44 ) ;
}
static int F_134 ( struct V_149 * V_149 , void * V_163 , struct V_199 * V_44 )
{
struct V_23 * V_24 = V_163 ;
return F_135 ( & V_24 -> V_152 , V_44 ) ;
}
static int F_136 ( struct V_149 * V_149 , void * V_163 ,
struct V_199 * V_44 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
int V_55 ;
if ( ! V_24 -> V_26 ) {
F_3 ( & V_2 -> V_7 ) ;
V_55 = F_14 ( V_24 ) ;
F_9 ( & V_2 -> V_7 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_30 ( V_24 ) ;
if ( V_55 )
return V_55 ;
}
V_55 = F_137 ( & V_24 -> V_152 , V_44 , V_149 -> V_161 & V_162 ) ;
if ( V_55 )
return V_55 ;
if ( F_1 ( V_2 ) ) {
V_44 -> V_92 |= V_200 ;
if ( V_2 -> V_9 ) {
V_44 -> V_92 |= V_201 ;
F_4 ( V_2 -> V_3 , V_8 ,
1 << V_2 -> V_4 ) ;
V_2 -> V_9 = 0 ;
}
}
if ( V_24 -> V_97 == V_98 ) {
struct V_62 * V_63 =
F_75 ( V_24 -> V_152 . V_202 [ V_44 -> V_177 ] ) ;
if ( V_63 ) {
T_1 * V_48 = F_39 ( V_63 -> V_43 ) ;
if ( V_48 [ 3 ] == 0x00 )
V_44 -> V_92 |= V_203 ;
else
V_44 -> V_92 |= V_204 ;
}
}
return 0 ;
}
static int F_138 ( struct V_149 * V_149 , void * V_163 ,
enum V_205 V_50 )
{
struct V_23 * V_24 = V_163 ;
if ( V_50 != V_158 )
return - V_56 ;
return F_139 ( & V_24 -> V_152 ) ;
}
static int F_140 ( struct V_149 * V_149 , void * V_163 ,
enum V_205 V_50 )
{
struct V_23 * V_24 = V_163 ;
if ( V_50 != V_158 )
return - V_56 ;
return F_141 ( & V_24 -> V_152 ) ;
}
static int F_142 ( struct V_149 * V_149 , void * V_163 , T_11 * V_50 )
{
return 0 ;
}
static int F_143 ( struct V_149 * V_149 , void * V_163 ,
struct V_206 * V_207 )
{
struct V_23 * V_24 = V_163 ;
struct V_3 * V_3 = V_24 -> V_25 -> V_3 ;
if ( V_207 -> V_208 != V_98 )
return - V_56 ;
switch ( V_207 -> V_177 ) {
case 0 :
V_207 -> V_209 . V_18 = V_3 -> V_19 >> 1 ;
V_207 -> V_209 . V_20 = V_3 -> V_21 ;
break;
case 1 :
V_207 -> V_209 . V_18 = V_3 -> V_19 ;
V_207 -> V_209 . V_20 = V_3 -> V_21 << 1 ;
break;
default:
return - V_56 ;
}
V_207 -> type = V_210 ;
return 0 ;
}
static int F_144 ( struct V_149 * V_149 , void * V_163 ,
struct V_211 * V_212 )
{
struct V_23 * V_24 = V_163 ;
struct V_3 * V_3 = V_24 -> V_25 -> V_3 ;
if ( V_212 -> V_208 != V_98 || V_212 -> V_177 )
return - V_56 ;
V_212 -> type = V_213 ;
V_212 -> V_214 . F_54 . V_215 = V_3 -> V_15 ;
V_212 -> V_214 . F_54 . V_216 = 1 ;
V_212 -> V_214 . F_12 . V_215 = V_3 -> V_15 ;
V_212 -> V_214 . F_12 . V_216 = 15 ;
V_212 -> V_214 . V_217 . V_215 = 1 ;
V_212 -> V_214 . V_217 . V_216 = 1 ;
return 0 ;
}
static int F_145 ( struct V_149 * V_149 , void * V_163 ,
struct V_218 * V_219 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_220 * V_221 = & V_219 -> V_222 . V_223 ;
V_221 -> V_224 = V_225 ;
V_221 -> V_226 . V_215 = V_2 -> V_16 ;
V_221 -> V_226 . V_216 = V_3 -> V_15 ;
V_221 -> V_227 = 0 ;
V_221 -> V_228 = 2 ;
return 0 ;
}
static int F_146 ( struct V_149 * V_149 , void * V_163 ,
struct V_218 * V_219 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
struct V_220 * V_221 = & V_219 -> V_222 . V_223 ;
F_3 ( & V_2 -> V_7 ) ;
if ( F_15 ( & V_2 -> V_27 ) > 0 ) {
F_9 ( & V_2 -> V_7 ) ;
return - V_29 ;
}
if ( ( V_221 -> V_226 . V_215 == 0 ) ||
( V_221 -> V_226 . V_216 == 0 ) ) {
V_221 -> V_226 . V_215 = 1 ;
V_221 -> V_226 . V_216 = V_3 -> V_15 ;
}
if ( V_221 -> V_226 . V_216 != V_3 -> V_15 )
V_221 -> V_226 . V_216 = V_3 -> V_15 ;
if ( V_221 -> V_226 . V_215 > 15 )
V_221 -> V_226 . V_215 = 15 ;
V_2 -> V_16 = V_221 -> V_226 . V_215 ;
V_221 -> V_224 = V_225 ;
V_2 -> V_33 = F_12 ( V_3 -> V_15 / V_2 -> V_16 , 1 ) ;
F_10 ( V_2 ) ;
F_9 ( & V_2 -> V_7 ) ;
return 0 ;
}
static int F_147 ( struct V_149 * V_149 , void * V_163 ,
struct V_229 * V_230 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
V_230 -> V_231 = F_148 ( V_232 , V_230 -> V_231 ) ;
if ( ! V_230 -> V_231 )
return - V_56 ;
switch ( V_230 -> V_231 ) {
case V_233 :
case V_234 :
case V_235 :
case V_236 :
return F_149 ( V_230 , 0x00 , 0xff , 1 , 0x80 ) ;
case V_237 :
return F_149 ( V_230 , 0x00 , 0x0f , 1 , 0x00 ) ;
case V_238 :
return F_149 (
V_230 , V_239 ,
V_240 , 1 ,
V_240 ) ;
case V_241 :
return F_149 ( V_230 , 1 , 255 , 1 , V_3 -> V_15 ) ;
#ifdef F_150
case V_242 :
V_230 -> V_92 |= V_243 ;
V_230 -> type = V_244 ;
V_230 -> V_245 = 0 ;
V_230 -> V_246 = 0xffff ;
V_230 -> V_217 = 1 ;
V_230 -> V_247 = V_248 ;
F_151 ( V_230 -> V_178 , L_8 ,
sizeof( V_230 -> V_178 ) ) ;
return 0 ;
case V_249 :
V_230 -> type = V_250 ;
V_230 -> V_245 = 0 ;
V_230 -> V_246 = V_230 -> V_217 = 1 ;
V_230 -> V_247 = 0 ;
F_151 ( V_230 -> V_178 , L_9 , sizeof( V_230 -> V_178 ) ) ;
return 0 ;
#else
case V_242 :
return F_149 ( V_230 , 0 , 0xffff , 1 ,
V_248 ) ;
case V_249 :
return F_149 ( V_230 , 0 , 1 , 1 , 0 ) ;
#endif
case V_251 :
V_230 -> type = V_252 ;
V_230 -> V_245 = 0 ;
V_230 -> V_246 = V_253 ;
V_230 -> V_217 = 1 ;
V_230 -> V_247 = 0 ;
F_151 ( V_230 -> V_178 , L_10 , sizeof( V_230 -> V_178 ) ) ;
return 0 ;
}
return - V_56 ;
}
static int F_152 ( struct V_149 * V_149 , void * V_163 ,
struct V_254 * V_255 )
{
struct V_229 V_256 ;
int V_257 ;
V_256 . V_231 = V_255 -> V_231 ;
V_257 = F_147 ( V_149 , V_163 , & V_256 ) ;
if ( V_257 )
return V_257 ;
return F_153 ( V_255 , & V_256 , NULL ) ;
}
static int F_154 ( struct V_149 * V_149 , void * V_163 ,
struct V_258 * V_259 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
switch ( V_259 -> V_231 ) {
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
return F_155 ( V_3 , V_259 -> V_231 , V_2 -> V_4 ,
& V_259 -> V_79 ) ;
case V_238 :
V_259 -> V_79 = V_240 ;
break;
case V_241 :
V_259 -> V_79 = V_2 -> V_33 ;
break;
case V_242 :
V_259 -> V_79 = V_2 -> V_260 ;
break;
case V_249 :
V_259 -> V_79 = F_1 ( V_2 ) ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_156 ( struct V_149 * V_149 , void * V_163 ,
struct V_258 * V_259 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
struct V_3 * V_3 = V_2 -> V_3 ;
switch ( V_259 -> V_231 ) {
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
return F_157 ( V_3 , V_259 -> V_231 , V_2 -> V_4 ,
V_259 -> V_79 ) ;
case V_238 :
if ( V_259 -> V_79 != V_240 )
return - V_261 ;
break;
case V_241 :
if ( V_259 -> V_79 < 1 || V_259 -> V_79 > 255 )
return - V_261 ;
V_2 -> V_33 = V_259 -> V_79 ;
F_4 ( V_3 , F_20 ( V_2 -> V_4 ) ,
V_2 -> V_33 ) ;
F_4 ( V_3 , F_23 ( V_2 -> V_4 ) ,
V_2 -> V_33 ) ;
break;
case V_242 :
if ( V_259 -> V_79 < 0 || V_259 -> V_79 > 0xffff )
return - V_261 ;
V_2 -> V_260 = V_259 -> V_79 ;
F_158 ( V_3 , V_2 -> V_4 , V_259 -> V_79 ) ;
break;
case V_249 :
F_2 ( V_2 , V_259 -> V_79 ) ;
break;
default:
return - V_56 ;
}
return 0 ;
}
static int F_159 ( struct V_149 * V_149 , void * V_163 ,
struct V_262 * V_263 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_263 -> V_78 ; V_50 ++ ) {
struct V_264 * V_259 = ( V_263 -> V_265 + V_50 ) ;
int V_257 ;
switch ( V_259 -> V_231 ) {
case V_251 :
if ( V_259 -> V_45 - 1 > V_253 )
V_257 = - V_261 ;
else {
V_257 = F_160 ( V_2 -> V_266 ,
V_259 -> string ,
V_253 ) ;
V_2 -> V_266 [ V_253 ] = '\0' ;
if ( ! V_257 )
V_257 = F_161 ( V_2 ) ;
else
V_257 = - V_267 ;
}
break;
default:
V_257 = - V_56 ;
}
if ( V_257 < 0 ) {
V_263 -> V_268 = V_50 ;
return V_257 ;
}
}
return 0 ;
}
static int F_162 ( struct V_149 * V_149 , void * V_163 ,
struct V_262 * V_263 )
{
struct V_23 * V_24 = V_163 ;
struct V_1 * V_2 = V_24 -> V_25 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_263 -> V_78 ; V_50 ++ ) {
struct V_264 * V_259 = ( V_263 -> V_265 + V_50 ) ;
int V_257 ;
switch ( V_259 -> V_231 ) {
case V_251 :
if ( V_259 -> V_45 < V_253 ) {
V_259 -> V_45 = V_253 ;
V_257 = - V_269 ;
} else {
V_257 = F_163 ( V_259 -> string ,
V_2 -> V_266 ,
V_253 ) ;
if ( V_257 )
V_257 = - V_267 ;
}
break;
default:
V_257 = - V_56 ;
}
if ( V_257 < 0 ) {
V_263 -> V_268 = V_50 ;
return V_257 ;
}
}
return 0 ;
}
static struct V_1 * F_164 ( struct V_3 * V_3 , T_1 V_4 )
{
struct V_1 * V_2 ;
int V_55 ;
V_2 = F_111 ( sizeof( * V_2 ) , V_155 ) ;
if ( ! V_2 )
return F_165 ( - V_156 ) ;
V_2 -> V_270 = F_166 () ;
if ( ! V_2 -> V_270 ) {
F_119 ( V_2 ) ;
return F_165 ( - V_156 ) ;
}
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
* V_2 -> V_270 = V_271 ;
V_2 -> V_270 -> V_272 = & V_3 -> V_59 -> V_146 ;
V_55 = F_167 ( V_2 -> V_270 , V_273 ,
V_274 ) ;
if ( V_55 < 0 ) {
F_168 ( V_2 -> V_270 ) ;
F_119 ( V_2 ) ;
return F_165 ( V_55 ) ;
}
F_169 ( V_2 -> V_270 , V_2 ) ;
snprintf ( V_2 -> V_270 -> V_178 , sizeof( V_2 -> V_270 -> V_178 ) ,
L_11 , V_37 , V_3 -> V_270 -> V_275 ,
V_2 -> V_270 -> V_275 ) ;
if ( V_274 != - 1 )
V_274 ++ ;
F_170 ( & V_2 -> V_7 ) ;
F_171 ( & V_2 -> V_113 ) ;
F_172 ( & V_2 -> V_27 , 0 ) ;
V_2 -> V_34 = V_276 ;
V_2 -> V_33 = V_3 -> V_15 ;
V_2 -> V_16 = 1 ;
V_2 -> V_13 = V_17 ;
V_2 -> V_260 = V_248 ;
F_3 ( & V_2 -> V_7 ) ;
F_10 ( V_2 ) ;
F_9 ( & V_2 -> V_7 ) ;
return V_2 ;
}
static void F_173 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_174 ( V_2 -> V_270 ) ;
F_119 ( V_2 ) ;
}
int F_175 ( struct V_3 * V_3 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_3 -> V_38 ; V_50 ++ ) {
V_3 -> V_39 [ V_50 ] = F_164 ( V_3 , V_50 ) ;
if ( F_32 ( V_3 -> V_39 [ V_50 ] ) )
break;
}
if ( V_50 != V_3 -> V_38 ) {
int V_55 = F_33 ( V_3 -> V_39 [ V_50 ] ) ;
while ( V_50 -- )
F_173 ( V_3 -> V_39 [ V_50 ] ) ;
return V_55 ;
}
V_3 -> V_28 = V_3 -> V_15 * 4 * 4 ;
F_176 ( & V_3 -> V_59 -> V_146 , L_12 ,
V_3 -> V_39 [ 0 ] -> V_270 -> V_275 ,
V_3 -> V_39 [ V_3 -> V_38 - 1 ] -> V_270 -> V_275 ) ;
return 0 ;
}
void F_177 ( struct V_3 * V_3 )
{
int V_50 ;
F_8 ( V_3 , V_11 ) ;
for ( V_50 = 0 ; V_50 < V_3 -> V_38 ; V_50 ++ )
F_173 ( V_3 -> V_39 [ V_50 ] ) ;
}

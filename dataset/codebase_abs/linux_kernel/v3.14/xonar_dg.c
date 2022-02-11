int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_7 ;
V_7 = V_3 << 8 ;
V_7 |= ( V_8 | V_9 ) << 16 ;
V_7 |= V_5 -> V_10 [ V_3 ] ;
return F_2 ( V_2 , V_11 |
V_12 |
V_13 |
( 0 << V_14 ) |
V_15 ,
V_7 ) ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_17 ;
V_17 = F_2 ( V_2 , V_11 |
V_18 |
V_15 |
V_13 | ( 0 << V_14 ) ,
( ( V_8 | V_9 ) << 8 ) | V_16 ) ;
if ( V_17 < 0 )
return V_17 ;
V_17 = F_2 ( V_2 , V_11 |
V_18 |
V_15 |
V_13 | ( 0 << V_14 ) ,
( V_8 | V_19 ) << 8 ) ;
if ( V_17 < 0 )
return V_17 ;
V_5 -> V_10 [ V_16 ] = F_4 ( V_2 , V_20 ) ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , enum V_21 V_22 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_16 ;
int V_17 ;
for ( V_16 = 1 ; V_16 < F_6 ( V_5 -> V_10 ) ; V_16 ++ ) {
V_17 = ( V_22 == V_23 ?
F_3 ( V_2 , V_16 ) :
F_1 ( V_2 , V_16 ) ) ;
if ( V_17 < 0 )
return V_17 ;
}
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
F_5 ( V_2 , V_23 ) ;
V_5 -> V_10 [ V_24 ] = 0 ;
V_5 -> V_10 [ V_25 ] =
V_26 | V_27 ;
V_5 -> V_10 [ V_28 ] =
V_29 | V_30 ;
V_5 -> V_10 [ V_31 ] =
V_32 | V_33 | V_34 ;
V_5 -> V_10 [ V_35 ] =
V_36 | V_37 ;
V_5 -> V_10 [ V_38 ] =
V_39 | V_40 ;
V_5 -> V_10 [ V_41 ] = 0 ;
V_5 -> V_10 [ V_42 ] = 0 ;
V_5 -> V_10 [ V_43 ] = 8 ;
V_5 -> V_10 [ V_44 ] = 8 ;
F_5 ( V_2 , V_45 ) ;
F_8 ( V_2 -> V_46 , L_1 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_5 -> V_47 = V_48 ;
V_5 -> V_49 = V_50 ;
F_7 ( V_2 ) ;
F_10 ( V_2 , V_51 ,
V_52 | V_53 | V_54 ) ;
F_11 ( 2500 ) ;
F_10 ( V_2 , V_55 ,
V_52 | V_54 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 , V_55 , V_52 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_45 ) ;
F_11 ( 2500 ) ;
F_16 ( V_2 , V_55 , V_52 ) ;
}
void F_17 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_58 ;
unsigned char V_59 ;
V_58 = V_5 -> V_10 [ V_28 ] & ~ V_60 ;
V_59 = V_5 -> V_10 [ V_61 ] & ~ V_62 ;
if ( F_18 ( V_57 ) <= 50000 ) {
V_58 |= V_29 ;
V_59 |= V_63 << V_64 ;
} else if ( F_18 ( V_57 ) <= 100000 ) {
V_58 |= V_65 ;
V_59 |= V_63 << V_64 ;
} else {
V_58 |= V_66 ;
V_59 |= V_67 << V_64 ;
}
V_5 -> V_10 [ V_28 ] = V_58 ;
V_5 -> V_10 [ V_61 ] = V_59 ;
F_1 ( V_2 , V_28 ) ;
F_1 ( V_2 , V_61 ) ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_56 * V_57 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned char V_68 ;
unsigned char V_59 ;
V_68 = V_5 -> V_10 [ V_35 ] & ~ V_69 ;
V_59 = V_5 -> V_10 [ V_61 ] & ~ V_70 ;
if ( F_18 ( V_57 ) <= 50000 ) {
V_68 |= V_36 ;
V_59 |= V_63 << V_71 ;
} else if ( F_18 ( V_57 ) <= 100000 ) {
V_68 |= V_72 ;
V_59 |= V_63 << V_71 ;
} else {
V_68 |= V_73 ;
V_59 |= V_67 << V_71 ;
}
V_5 -> V_10 [ V_35 ] = V_68 ;
V_5 -> V_10 [ V_61 ] = V_59 ;
F_1 ( V_2 , V_35 ) ;
F_1 ( V_2 , V_61 ) ;
}
static inline unsigned int F_20 ( unsigned int V_74 ,
unsigned int V_75 ,
unsigned int V_76 ,
unsigned int V_77 )
{
if ( V_75 < V_76 )
return ( V_74 << ( V_76 - V_75 ) ) & V_77 ;
else
return ( V_74 >> ( V_75 - V_76 ) ) & V_77 ;
}
unsigned int F_21 ( struct V_1 * V_2 ,
unsigned int V_78 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
switch ( V_5 -> V_47 ) {
case V_79 :
case V_48 :
F_22 ( V_2 , V_80 ,
V_81 | V_82 |
V_83 , V_84 ) ;
break;
case V_85 :
F_22 ( V_2 , V_80 ,
V_86 , V_84 ) ;
break;
}
return ( V_78 & V_87 ) |
F_20 ( V_78 ,
V_88 ,
V_89 ,
V_90 ) |
F_20 ( V_78 ,
V_89 ,
V_88 ,
V_91 ) |
F_20 ( V_78 ,
V_92 ,
V_93 ,
V_94 ) ;
}
void F_23 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_16 ;
F_24 ( V_96 , L_2 ) ;
F_3 ( V_2 , V_97 ) ;
for ( V_16 = 1 ; V_16 < F_6 ( V_5 -> V_10 ) ; V_16 ++ )
F_24 ( V_96 , L_3 , V_5 -> V_10 [ V_16 ] ) ;
F_24 ( V_96 , L_4 ) ;
}

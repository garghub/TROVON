static unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
int V_4 ;
const int V_5 = 16 ;
for ( V_4 = 1 ; V_4 <= V_5 ; V_4 ++ ) {
if ( F_2 ( V_2 -> V_6 + V_7 ) & V_8 )
V_3 |= 1 << ( V_5 - V_4 ) ;
}
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_4 ;
for ( V_4 = 1 ; V_4 <= V_9 ; V_4 ++ ) {
if ( V_3 & ( 1 << ( V_9 - V_4 ) ) )
V_11 -> V_13 |= V_14 ;
else
V_11 -> V_13 &= ~ V_14 ;
F_4 ( V_11 -> V_13 , V_2 -> V_6 + V_7 ) ;
}
}
static unsigned int F_5 ( struct V_1 * V_2 ,
unsigned int V_15 )
{
unsigned int V_4 ;
unsigned int V_16 ;
unsigned int V_3 ;
const int V_17 = 4 ;
const int V_18 = 0x6 ;
const int V_19 = 3 ;
const int V_20 = 8 ;
V_16 = V_21 | V_22 | V_23 ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ )
V_16 |= F_6 ( V_4 ) ;
F_4 ( V_16 , V_2 -> V_6 + V_24 ) ;
F_3 ( V_2 , V_18 , V_19 ) ;
F_3 ( V_2 , V_15 , V_20 ) ;
V_3 = F_1 ( V_2 ) ;
V_16 &= ~ V_21 ;
F_4 ( V_16 , V_2 -> V_6 + V_24 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_25 , unsigned int V_26 ,
unsigned int V_3 )
{
unsigned int V_16 ;
unsigned int V_4 ;
const int V_27 = 3 ;
const int V_28 = 8 ;
const int V_17 = 4 ;
F_3 ( V_2 , V_26 , V_27 ) ;
F_3 ( V_2 , V_3 , V_28 ) ;
V_16 = V_22 | V_23 ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ )
V_16 |= F_6 ( V_4 ) ;
V_16 &= ~ F_6 ( V_25 ) ;
F_4 ( V_16 , V_2 -> V_6 + V_24 ) ;
V_16 |= F_6 ( V_25 ) ;
F_4 ( V_16 , V_2 -> V_6 + V_24 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_26 ,
unsigned int V_29 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_25 = V_26 / 2 ;
unsigned int V_30 = 4 * ( V_26 % 2 ) ;
unsigned int V_31 = 2 * V_29 + 12 * V_26 ;
unsigned int V_32 ;
unsigned int V_33 ;
V_11 -> V_34 [ V_26 ] = V_29 ;
V_32 = V_11 -> V_35 [ 0x7 + V_31 ] ;
V_33 = V_11 -> V_35 [ 0x8 + V_31 ] ;
F_7 ( V_2 , V_25 , V_30 + V_36 ,
( V_32 >> 8 ) & 0xff ) ;
F_7 ( V_2 , V_25 , V_30 + V_37 ,
V_32 & 0xff ) ;
F_7 ( V_2 , V_25 , V_30 + V_38 ,
( V_33 >> 8 ) & 0xff ) ;
F_7 ( V_2 , V_25 , V_30 + V_39 ,
V_33 & 0xff ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
struct V_42 * V_43 ,
unsigned int * V_44 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned int V_26 = F_10 ( V_43 -> V_45 ) ;
unsigned int V_29 = F_11 ( V_43 -> V_45 ) ;
unsigned int V_46 ;
if ( V_29 != V_11 -> V_34 [ V_26 ] )
F_8 ( V_2 , V_26 , V_29 ) ;
V_46 = V_47 | F_12 ( V_26 ) ;
switch ( V_29 ) {
case 0 :
case 3 :
V_46 |= V_48 ;
break;
case 1 :
case 4 :
V_46 |= V_49 ;
break;
case 2 :
case 5 :
V_46 |= V_50 ;
break;
}
if ( V_29 > 2 )
V_46 |= V_51 ;
F_13 ( V_46 , V_2 -> V_6 + V_52 ) ;
F_13 ( V_44 [ 0 ] , V_2 -> V_6 + F_14 ( V_26 ) ) ;
return V_43 -> V_53 ;
}
static const void * F_15 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
const struct V_56 * V_57 ;
int V_4 ;
for ( V_4 = 0 ; V_4 < F_16 ( V_58 ) ; V_4 ++ ) {
V_57 = & V_58 [ V_4 ] ;
if ( V_57 -> V_59 != V_55 -> V_60 )
return V_57 ;
}
return NULL ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned long V_61 )
{
struct V_54 * V_55 = F_18 ( V_2 ) ;
const struct V_56 * V_57 ;
struct V_10 * V_11 ;
struct V_40 * V_41 ;
unsigned long V_62 ;
int V_4 ;
int V_63 ;
V_57 = F_15 ( V_2 , V_55 ) ;
if ( ! V_57 )
return - V_64 ;
V_2 -> V_65 = V_57 ;
V_2 -> V_66 = V_57 -> V_67 ;
V_11 = F_19 ( sizeof( * V_11 ) , V_68 ) ;
if ( ! V_11 )
return - V_69 ;
V_2 -> V_12 = V_11 ;
V_63 = F_20 ( V_55 , V_2 -> V_66 ) ;
if ( V_63 )
return V_63 ;
V_2 -> V_6 = F_21 ( V_55 , 3 ) ;
V_62 = F_21 ( V_55 , 2 ) ;
V_63 = F_22 ( V_2 , 3 ) ;
if ( V_63 )
return V_63 ;
V_41 = & V_2 -> V_70 [ 0 ] ;
V_41 -> type = V_71 ;
V_41 -> V_72 = V_73 ;
V_41 -> V_74 = V_57 -> V_75 ;
V_41 -> V_76 = ( 1 << V_57 -> V_77 ) - 1 ;
V_41 -> V_78 = & V_79 ;
V_41 -> V_80 = F_9 ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_41 = & V_2 -> V_70 [ 1 + V_4 ] ;
V_63 = F_23 ( V_2 , V_41 , NULL , V_62 + ( V_4 * 4 ) ) ;
if ( V_63 )
return V_63 ;
}
for ( V_4 = 0 ; V_4 < V_81 ; V_4 ++ )
V_11 -> V_35 [ V_4 ] = F_5 ( V_2 , V_4 ) ;
for ( V_4 = 0 ; V_4 < V_57 -> V_75 ; V_4 ++ )
F_8 ( V_2 , V_4 , V_11 -> V_34 [ V_4 ] ) ;
F_24 ( V_2 -> V_82 , L_1 , V_2 -> V_66 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_18 ( V_2 ) ;
if ( V_2 -> V_70 ) {
F_26 ( V_2 , & V_2 -> V_70 [ 1 ] ) ;
F_26 ( V_2 , & V_2 -> V_70 [ 2 ] ) ;
}
if ( V_55 ) {
if ( V_2 -> V_6 )
F_27 ( V_55 ) ;
}
}
static int F_28 ( struct V_54 * V_2 ,
const struct V_83 * V_84 )
{
return F_29 ( V_2 , & V_85 ) ;
}

static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
F_2 ( V_4 | V_5 | V_3 ,
V_2 -> V_6 + V_7 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned long V_12 )
{
unsigned int V_13 ;
V_13 = F_4 ( V_2 -> V_6 + V_14 ) ;
if ( V_13 & V_12 )
return 0 ;
return - V_15 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_16 )
{
unsigned int V_17 = F_6 ( V_11 -> V_18 ) ;
unsigned int V_19 ;
int V_20 ;
int V_21 ;
F_1 ( V_2 , V_22 | F_7 ( V_17 ) ) ;
V_20 = F_8 ( V_2 , V_9 , V_11 , F_3 ,
V_23 ) ;
if ( V_20 )
return V_20 ;
for ( V_21 = 0 ; V_21 < V_11 -> V_24 ; V_21 ++ ) {
F_2 ( 0 , V_2 -> V_6 + V_25 ) ;
V_20 = F_8 ( V_2 , V_9 , V_11 , F_3 ,
V_26 ) ;
if ( V_20 )
return V_20 ;
V_19 = F_9 ( V_2 -> V_6 + V_27 ) << 8 ;
V_19 |= F_9 ( V_2 -> V_6 + V_27 ) ;
V_19 &= V_9 -> V_28 ;
V_16 [ V_21 ] = F_10 ( V_9 , V_19 ) ;
}
return V_11 -> V_24 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_16 )
{
unsigned int V_17 = F_6 ( V_11 -> V_18 ) ;
unsigned int V_19 = V_9 -> V_29 [ V_17 ] ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_11 -> V_24 ; V_21 ++ ) {
V_19 = V_16 [ V_21 ] ;
F_1 ( V_2 , V_30 |
F_12 ( V_17 ) ) ;
F_2 ( V_19 , V_2 -> V_6 + V_31 ) ;
F_1 ( V_2 , 0 ) ;
}
V_9 -> V_29 [ V_17 ] = V_19 ;
return V_11 -> V_24 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 , unsigned int * V_16 )
{
V_16 [ 1 ] = F_4 ( V_2 -> V_6 + V_32 ) ;
return V_11 -> V_24 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_16 )
{
if ( F_15 ( V_9 , V_16 ) )
F_2 ( V_9 -> V_33 , V_2 -> V_6 + V_34 ) ;
V_16 [ 1 ] = V_9 -> V_33 ;
return V_11 -> V_24 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_16 )
{
unsigned int V_17 = F_6 ( V_11 -> V_18 ) ;
unsigned int V_19 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_11 -> V_24 ; V_21 ++ ) {
F_1 ( V_2 , V_22 |
F_17 ( V_17 ) ) ;
F_18 ( V_35 , V_2 -> V_6 + V_36 ) ;
F_18 ( V_37 , V_2 -> V_6 + V_36 ) ;
V_19 = F_9 ( V_2 -> V_6 + V_38 ) ;
V_19 |= ( F_9 ( V_2 -> V_6 + V_38 ) << 8 ) ;
V_19 |= ( F_9 ( V_2 -> V_6 + V_38 ) << 16 ) ;
V_16 [ V_21 ] = ( V_19 + ( ( V_9 -> V_28 + 1 ) >> 1 ) ) & V_9 -> V_28 ;
}
return V_11 -> V_24 ;
}
static void F_19 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
F_1 ( V_2 , V_22 | F_17 ( V_17 ) ) ;
F_18 ( V_39 , V_2 -> V_6 + V_36 ) ;
F_18 ( V_35 , V_2 -> V_6 + V_36 ) ;
F_18 ( V_40 , V_2 -> V_6 + V_38 ) ;
F_18 ( V_41 , V_2 -> V_6 + V_36 ) ;
F_18 ( V_42 , V_2 -> V_6 + V_36 ) ;
F_18 ( V_43 , V_2 -> V_6 + V_36 ) ;
F_18 ( V_44 , V_2 -> V_6 + V_36 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_16 )
{
unsigned int V_17 = F_6 ( V_11 -> V_18 ) ;
switch ( V_16 [ 0 ] ) {
case V_45 :
F_19 ( V_2 , V_17 ) ;
break;
default:
return - V_46 ;
}
return V_11 -> V_24 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_8 * V_9 ;
int V_20 ;
int V_21 ;
V_20 = F_22 ( V_2 , V_48 -> V_49 [ 0 ] , 0x10 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_23 ( V_2 , 5 ) ;
if ( V_20 )
return V_20 ;
V_9 = & V_2 -> V_50 [ 0 ] ;
V_9 -> type = V_51 ;
V_9 -> V_52 = V_53 | V_54 ;
V_9 -> V_55 = 8 ;
V_9 -> V_28 = 0x1fff ;
V_9 -> V_56 = & V_57 ;
V_9 -> V_58 = F_5 ;
V_9 = & V_2 -> V_50 [ 1 ] ;
V_9 -> type = V_59 ;
V_9 -> V_52 = V_60 ;
V_9 -> V_55 = 8 ;
V_9 -> V_28 = 0x0fff ;
V_9 -> V_56 = & V_57 ;
V_9 -> V_61 = F_11 ;
V_20 = F_24 ( V_9 ) ;
if ( V_20 )
return V_20 ;
V_9 = & V_2 -> V_50 [ 2 ] ;
V_9 -> type = V_62 ;
V_9 -> V_52 = V_53 ;
V_9 -> V_55 = 16 ;
V_9 -> V_28 = 1 ;
V_9 -> V_56 = & V_63 ;
V_9 -> V_64 = F_13 ;
V_9 = & V_2 -> V_50 [ 3 ] ;
V_9 -> type = V_65 ;
V_9 -> V_52 = V_60 ;
V_9 -> V_55 = 16 ;
V_9 -> V_28 = 1 ;
V_9 -> V_56 = & V_63 ;
V_9 -> V_64 = F_14 ;
V_9 = & V_2 -> V_50 [ 4 ] ;
V_9 -> type = V_66 ;
V_9 -> V_52 = V_53 | V_67 ;
V_9 -> V_55 = V_48 -> V_49 [ 2 ] * 2 ;
V_9 -> V_28 = 0x00ffffff ;
V_9 -> V_56 = & V_68 ;
V_9 -> V_58 = F_16 ;
V_9 -> V_69 = F_20 ;
for ( V_21 = 0 ; V_21 < V_9 -> V_55 ; V_21 ++ )
F_19 ( V_2 , V_21 ) ;
return 0 ;
}

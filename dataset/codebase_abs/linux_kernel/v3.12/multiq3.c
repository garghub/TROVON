static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 , V_9 ;
int V_10 ;
unsigned int V_11 , V_12 ;
V_10 = F_2 ( V_6 -> V_13 ) ;
F_3 ( V_14 | V_15 | ( V_10 << 3 ) ,
V_2 -> V_16 + V_17 ) ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
if ( F_4 ( V_2 -> V_16 + V_19 ) & V_20 )
break;
}
if ( V_8 == V_18 )
return - V_21 ;
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
F_3 ( 0 , V_2 -> V_16 + V_22 ) ;
for ( V_8 = 0 ; V_8 < V_18 ; V_8 ++ ) {
if ( F_4 ( V_2 -> V_16 +
V_19 ) & V_23 )
break;
}
if ( V_8 == V_18 )
return - V_21 ;
V_11 = F_5 ( V_2 -> V_16 + V_22 ) ;
V_12 = F_5 ( V_2 -> V_16 + V_22 ) ;
V_7 [ V_9 ] = ( ( ( V_11 << 8 ) | V_12 ) + 0x1000 ) & 0x1fff ;
}
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
int V_8 ;
int V_10 = F_2 ( V_6 -> V_13 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_9 ; V_8 ++ )
V_7 [ V_8 ] = V_25 -> V_27 [ V_10 ] ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
int V_8 ;
int V_10 = F_2 ( V_6 -> V_13 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_9 ; V_8 ++ ) {
F_3 ( V_14 | V_28 | V_10 ,
V_2 -> V_16 + V_17 ) ;
F_3 ( V_7 [ V_8 ] , V_2 -> V_16 + V_29 ) ;
F_3 ( V_14 , V_2 -> V_16 + V_17 ) ;
V_25 -> V_27 [ V_10 ] = V_7 [ V_8 ] ;
}
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_16 + V_30 ) ;
return V_6 -> V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_4 -> V_31 &= ~ V_7 [ 0 ] ;
V_4 -> V_31 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_3 ( V_4 -> V_31 , V_2 -> V_16 + V_32 ) ;
V_7 [ 1 ] = V_4 -> V_31 ;
return V_6 -> V_9 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_9 ;
int V_10 = F_2 ( V_6 -> V_13 ) ;
int V_33 = V_14 | V_15 | ( V_10 << 3 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
int V_34 ;
F_3 ( V_33 , V_2 -> V_16 + V_17 ) ;
F_11 ( V_35 , V_2 -> V_16 + V_36 ) ;
F_11 ( V_37 , V_2 -> V_16 + V_36 ) ;
V_34 = F_5 ( V_2 -> V_16 + V_38 ) ;
V_34 |= ( F_5 ( V_2 -> V_16 + V_38 ) << 8 ) ;
V_34 |= ( F_5 ( V_2 -> V_16 + V_38 ) << 16 ) ;
V_7 [ V_9 ] = ( V_34 + 0x800000 ) & 0xffffff ;
}
return V_9 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_39 [ 4 ] ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_4 -> V_40 ; V_10 ++ ) {
int V_33 =
V_14 | V_15 | ( V_10 << 3 ) ;
F_3 ( V_33 , V_2 -> V_16 + V_17 ) ;
F_11 ( V_41 , V_2 -> V_16 + V_36 ) ;
F_11 ( V_35 , V_2 -> V_16 + V_36 ) ;
F_11 ( V_42 , V_2 -> V_16 + V_38 ) ;
F_11 ( V_43 , V_2 -> V_16 + V_36 ) ;
F_11 ( V_44 , V_2 -> V_16 + V_36 ) ;
F_11 ( V_45 , V_2 -> V_16 + V_36 ) ;
F_11 ( V_46 , V_2 -> V_16 + V_36 ) ;
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_24 * V_25 ;
struct V_3 * V_4 ;
int V_49 ;
V_49 = F_14 ( V_2 , V_48 -> V_50 [ 0 ] , V_51 ) ;
if ( V_49 )
return V_49 ;
V_49 = F_15 ( V_2 , 5 ) ;
if ( V_49 )
return V_49 ;
V_25 = F_16 ( V_2 , sizeof( * V_25 ) ) ;
if ( ! V_25 )
return - V_52 ;
V_4 = & V_2 -> V_39 [ 0 ] ;
V_4 -> type = V_53 ;
V_4 -> V_54 = V_55 | V_56 ;
V_4 -> V_40 = 8 ;
V_4 -> V_57 = F_1 ;
V_4 -> V_58 = 0x1fff ;
V_4 -> V_59 = & V_60 ;
V_4 = & V_2 -> V_39 [ 1 ] ;
V_4 -> type = V_61 ;
V_4 -> V_54 = V_62 ;
V_4 -> V_40 = 8 ;
V_4 -> V_57 = F_6 ;
V_4 -> V_63 = F_7 ;
V_4 -> V_58 = 0xfff ;
V_4 -> V_59 = & V_60 ;
V_4 = & V_2 -> V_39 [ 2 ] ;
V_4 -> type = V_64 ;
V_4 -> V_54 = V_55 ;
V_4 -> V_40 = 16 ;
V_4 -> V_65 = F_8 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = & V_66 ;
V_4 = & V_2 -> V_39 [ 3 ] ;
V_4 -> type = V_67 ;
V_4 -> V_54 = V_62 ;
V_4 -> V_40 = 16 ;
V_4 -> V_65 = F_9 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = & V_66 ;
V_4 -> V_31 = 0 ;
V_4 = & V_2 -> V_39 [ 4 ] ;
V_4 -> type = V_68 ;
V_4 -> V_54 = V_55 | V_69 ;
V_4 -> V_40 = V_48 -> V_50 [ 2 ] * 2 ;
V_4 -> V_57 = F_10 ;
V_4 -> V_58 = 0xffffff ;
V_4 -> V_59 = & V_70 ;
F_12 ( V_2 ) ;
return 0 ;
}

static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( V_8 & V_7 )
return 0 ;
return - V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
int V_13 ;
int V_14 ;
unsigned int V_15 , V_16 ;
int V_17 ;
V_14 = F_4 ( V_6 -> V_18 ) ;
F_5 ( V_19 | V_20 | ( V_14 << 3 ) ,
V_2 -> V_9 + V_21 ) ;
V_17 = F_6 ( V_2 , V_4 , V_6 , F_1 ,
V_22 ) ;
if ( V_17 )
return V_17 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
F_5 ( 0 , V_2 -> V_9 + V_23 ) ;
V_17 = F_6 ( V_2 , V_4 , V_6 , F_1 ,
V_24 ) ;
if ( V_17 )
return V_17 ;
V_15 = F_7 ( V_2 -> V_9 + V_23 ) ;
V_16 = F_7 ( V_2 -> V_9 + V_23 ) ;
V_12 [ V_13 ] = ( ( ( V_15 << 8 ) | V_16 ) + 0x1000 ) & 0x1fff ;
}
return V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
int V_28 ;
int V_14 = F_4 ( V_6 -> V_18 ) ;
for ( V_28 = 0 ; V_28 < V_6 -> V_13 ; V_28 ++ )
V_12 [ V_28 ] = V_26 -> V_29 [ V_14 ] ;
return V_28 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
int V_28 ;
int V_14 = F_4 ( V_6 -> V_18 ) ;
for ( V_28 = 0 ; V_28 < V_6 -> V_13 ; V_28 ++ ) {
F_5 ( V_19 | V_30 | V_14 ,
V_2 -> V_9 + V_21 ) ;
F_5 ( V_12 [ V_28 ] , V_2 -> V_9 + V_31 ) ;
F_5 ( V_19 , V_2 -> V_9 + V_21 ) ;
V_26 -> V_29 [ V_14 ] = V_12 [ V_28 ] ;
}
return V_28 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
V_12 [ 1 ] = F_2 ( V_2 -> V_9 + V_32 ) ;
return V_6 -> V_13 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
if ( F_12 ( V_4 , V_12 ) )
F_5 ( V_4 -> V_33 , V_2 -> V_9 + V_34 ) ;
V_12 [ 1 ] = V_4 -> V_33 ;
return V_6 -> V_13 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
int V_14 = F_4 ( V_6 -> V_18 ) ;
int V_35 = V_19 | V_20 | ( V_14 << 3 ) ;
int V_36 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
F_5 ( V_35 , V_2 -> V_9 + V_21 ) ;
F_14 ( V_37 , V_2 -> V_9 + V_38 ) ;
F_14 ( V_39 , V_2 -> V_9 + V_38 ) ;
V_36 = F_7 ( V_2 -> V_9 + V_40 ) ;
V_36 |= ( F_7 ( V_2 -> V_9 + V_40 ) << 8 ) ;
V_36 |= ( F_7 ( V_2 -> V_9 + V_40 ) << 16 ) ;
V_12 [ V_13 ] = ( V_36 + 0x800000 ) & 0xffffff ;
}
return V_13 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_41 [ 4 ] ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_4 -> V_42 ; V_14 ++ ) {
int V_35 =
V_19 | V_20 | ( V_14 << 3 ) ;
F_5 ( V_35 , V_2 -> V_9 + V_21 ) ;
F_14 ( V_43 , V_2 -> V_9 + V_38 ) ;
F_14 ( V_37 , V_2 -> V_9 + V_38 ) ;
F_14 ( V_44 , V_2 -> V_9 + V_40 ) ;
F_14 ( V_45 , V_2 -> V_9 + V_38 ) ;
F_14 ( V_46 , V_2 -> V_9 + V_38 ) ;
F_14 ( V_47 , V_2 -> V_9 + V_38 ) ;
F_14 ( V_48 , V_2 -> V_9 + V_38 ) ;
}
}
static int F_16 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
struct V_25 * V_26 ;
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_17 ( V_2 , V_50 -> V_51 [ 0 ] , 0x10 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_18 ( V_2 , 5 ) ;
if ( V_17 )
return V_17 ;
V_26 = F_19 ( V_2 , sizeof( * V_26 ) ) ;
if ( ! V_26 )
return - V_52 ;
V_4 = & V_2 -> V_41 [ 0 ] ;
V_4 -> type = V_53 ;
V_4 -> V_54 = V_55 | V_56 ;
V_4 -> V_42 = 8 ;
V_4 -> V_57 = F_3 ;
V_4 -> V_58 = 0x1fff ;
V_4 -> V_59 = & V_60 ;
V_4 = & V_2 -> V_41 [ 1 ] ;
V_4 -> type = V_61 ;
V_4 -> V_54 = V_62 ;
V_4 -> V_42 = 8 ;
V_4 -> V_57 = F_8 ;
V_4 -> V_63 = F_9 ;
V_4 -> V_58 = 0xfff ;
V_4 -> V_59 = & V_60 ;
V_4 = & V_2 -> V_41 [ 2 ] ;
V_4 -> type = V_64 ;
V_4 -> V_54 = V_55 ;
V_4 -> V_42 = 16 ;
V_4 -> V_65 = F_10 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = & V_66 ;
V_4 = & V_2 -> V_41 [ 3 ] ;
V_4 -> type = V_67 ;
V_4 -> V_54 = V_62 ;
V_4 -> V_42 = 16 ;
V_4 -> V_65 = F_11 ;
V_4 -> V_58 = 1 ;
V_4 -> V_59 = & V_66 ;
V_4 -> V_33 = 0 ;
V_4 = & V_2 -> V_41 [ 4 ] ;
V_4 -> type = V_68 ;
V_4 -> V_54 = V_55 | V_69 ;
V_4 -> V_42 = V_50 -> V_51 [ 2 ] * 2 ;
V_4 -> V_57 = F_13 ;
V_4 -> V_58 = 0xffffff ;
V_4 -> V_59 = & V_70 ;
F_15 ( V_2 ) ;
return 0 ;
}

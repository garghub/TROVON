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
struct V_5 * V_6 ,
unsigned int * V_12 )
{
unsigned int V_14 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_25 = V_4 -> V_26 [ V_14 ] ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_6 -> V_13 ; V_27 ++ ) {
V_25 = V_12 [ V_27 ] ;
F_5 ( V_19 | V_28 | V_14 ,
V_2 -> V_9 + V_21 ) ;
F_5 ( V_25 , V_2 -> V_9 + V_29 ) ;
F_5 ( V_19 , V_2 -> V_9 + V_21 ) ;
}
V_4 -> V_26 [ V_14 ] = V_25 ;
return V_6 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_12 )
{
V_12 [ 1 ] = F_2 ( V_2 -> V_9 + V_30 ) ;
return V_6 -> V_13 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
if ( F_11 ( V_4 , V_12 ) )
F_5 ( V_4 -> V_31 , V_2 -> V_9 + V_32 ) ;
V_12 [ 1 ] = V_4 -> V_31 ;
return V_6 -> V_13 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_12 )
{
int V_14 = F_4 ( V_6 -> V_18 ) ;
int V_33 = V_19 | V_20 | ( V_14 << 3 ) ;
int V_34 ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
F_5 ( V_33 , V_2 -> V_9 + V_21 ) ;
F_13 ( V_35 , V_2 -> V_9 + V_36 ) ;
F_13 ( V_37 , V_2 -> V_9 + V_36 ) ;
V_34 = F_7 ( V_2 -> V_9 + V_38 ) ;
V_34 |= ( F_7 ( V_2 -> V_9 + V_38 ) << 8 ) ;
V_34 |= ( F_7 ( V_2 -> V_9 + V_38 ) << 16 ) ;
V_12 [ V_13 ] = ( V_34 + 0x800000 ) & 0xffffff ;
}
return V_13 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_39 [ 4 ] ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_4 -> V_40 ; V_14 ++ ) {
int V_33 =
V_19 | V_20 | ( V_14 << 3 ) ;
F_5 ( V_33 , V_2 -> V_9 + V_21 ) ;
F_13 ( V_41 , V_2 -> V_9 + V_36 ) ;
F_13 ( V_35 , V_2 -> V_9 + V_36 ) ;
F_13 ( V_42 , V_2 -> V_9 + V_38 ) ;
F_13 ( V_43 , V_2 -> V_9 + V_36 ) ;
F_13 ( V_44 , V_2 -> V_9 + V_36 ) ;
F_13 ( V_45 , V_2 -> V_9 + V_36 ) ;
F_13 ( V_46 , V_2 -> V_9 + V_36 ) ;
}
}
static int F_15 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_3 * V_4 ;
int V_17 ;
V_17 = F_16 ( V_2 , V_48 -> V_49 [ 0 ] , 0x10 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_17 ( V_2 , 5 ) ;
if ( V_17 )
return V_17 ;
V_4 = & V_2 -> V_39 [ 0 ] ;
V_4 -> type = V_50 ;
V_4 -> V_51 = V_52 | V_53 ;
V_4 -> V_40 = 8 ;
V_4 -> V_54 = F_3 ;
V_4 -> V_55 = 0x1fff ;
V_4 -> V_56 = & V_57 ;
V_4 = & V_2 -> V_39 [ 1 ] ;
V_4 -> type = V_58 ;
V_4 -> V_51 = V_59 ;
V_4 -> V_40 = 8 ;
V_4 -> V_55 = 0xfff ;
V_4 -> V_56 = & V_57 ;
V_4 -> V_60 = F_8 ;
V_17 = F_18 ( V_4 ) ;
if ( V_17 )
return V_17 ;
V_4 = & V_2 -> V_39 [ 2 ] ;
V_4 -> type = V_61 ;
V_4 -> V_51 = V_52 ;
V_4 -> V_40 = 16 ;
V_4 -> V_62 = F_9 ;
V_4 -> V_55 = 1 ;
V_4 -> V_56 = & V_63 ;
V_4 = & V_2 -> V_39 [ 3 ] ;
V_4 -> type = V_64 ;
V_4 -> V_51 = V_59 ;
V_4 -> V_40 = 16 ;
V_4 -> V_62 = F_10 ;
V_4 -> V_55 = 1 ;
V_4 -> V_56 = & V_63 ;
V_4 -> V_31 = 0 ;
V_4 = & V_2 -> V_39 [ 4 ] ;
V_4 -> type = V_65 ;
V_4 -> V_51 = V_52 | V_66 ;
V_4 -> V_40 = V_48 -> V_49 [ 2 ] * 2 ;
V_4 -> V_54 = F_12 ;
V_4 -> V_55 = 0xffffff ;
V_4 -> V_56 = & V_67 ;
F_14 ( V_2 ) ;
return 0 ;
}

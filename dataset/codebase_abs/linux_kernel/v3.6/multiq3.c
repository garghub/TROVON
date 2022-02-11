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
int V_8 ;
int V_10 = F_2 ( V_6 -> V_13 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_9 ; V_8 ++ )
V_7 [ V_8 ] = V_24 -> V_25 [ V_10 ] ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 ;
int V_10 = F_2 ( V_6 -> V_13 ) ;
for ( V_8 = 0 ; V_8 < V_6 -> V_9 ; V_8 ++ ) {
F_3 ( V_14 | V_26 | V_10 ,
V_2 -> V_16 + V_17 ) ;
F_3 ( V_7 [ V_8 ] , V_2 -> V_16 + V_27 ) ;
F_3 ( V_14 , V_2 -> V_16 + V_17 ) ;
V_24 -> V_25 [ V_10 ] = V_7 [ V_8 ] ;
}
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_16 + V_28 ) ;
return V_6 -> V_9 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_4 -> V_29 &= ~ V_7 [ 0 ] ;
V_4 -> V_29 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_3 ( V_4 -> V_29 , V_2 -> V_16 + V_30 ) ;
V_7 [ 1 ] = V_4 -> V_29 ;
return V_6 -> V_9 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_9 ;
int V_10 = F_2 ( V_6 -> V_13 ) ;
int V_31 = V_14 | V_15 | ( V_10 << 3 ) ;
for ( V_9 = 0 ; V_9 < V_6 -> V_9 ; V_9 ++ ) {
int V_32 ;
F_3 ( V_31 , V_2 -> V_16 + V_17 ) ;
F_11 ( V_33 , V_2 -> V_16 + V_34 ) ;
F_11 ( V_35 , V_2 -> V_16 + V_34 ) ;
V_32 = F_5 ( V_2 -> V_16 + V_36 ) ;
V_32 |= ( F_5 ( V_2 -> V_16 + V_36 ) << 8 ) ;
V_32 |= ( F_5 ( V_2 -> V_16 + V_36 ) << 16 ) ;
V_7 [ V_9 ] = ( V_32 + 0x800000 ) & 0xffffff ;
}
return V_9 ;
}
static void F_12 ( struct V_1 * V_2 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_2 -> V_37 [ 4 ] . V_38 ; V_10 ++ ) {
int V_31 =
V_14 | V_15 | ( V_10 << 3 ) ;
F_3 ( V_31 , V_2 -> V_16 + V_17 ) ;
F_11 ( V_39 , V_2 -> V_16 + V_34 ) ;
F_11 ( V_33 , V_2 -> V_16 + V_34 ) ;
F_11 ( V_40 , V_2 -> V_16 + V_36 ) ;
F_11 ( V_41 , V_2 -> V_16 + V_34 ) ;
F_11 ( V_42 , V_2 -> V_16 + V_34 ) ;
F_11 ( V_43 , V_2 -> V_16 + V_34 ) ;
F_11 ( V_44 , V_2 -> V_16 + V_34 ) ;
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_45 * V_46 )
{
int V_47 = 0 ;
unsigned long V_16 ;
unsigned int V_48 ;
struct V_3 * V_4 ;
V_16 = V_46 -> V_49 [ 0 ] ;
F_14 ( V_50 L_1 , V_2 -> V_51 , V_16 ) ;
if ( ! F_15 ( V_16 , V_52 , L_2 ) ) {
F_14 ( V_53 L_3 , V_2 -> V_51 ) ;
return - V_54 ;
}
V_2 -> V_16 = V_16 ;
V_48 = V_46 -> V_49 [ 1 ] ;
if ( V_48 )
F_14 ( V_55 L_4 ,
V_2 -> V_51 , V_48 ) ;
else
F_14 ( V_55 L_5 , V_2 -> V_51 ) ;
V_2 -> V_56 = L_2 ;
V_47 = F_16 ( V_2 , 5 ) ;
if ( V_47 )
return V_47 ;
V_47 = F_17 ( V_2 , sizeof( struct V_57 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_4 = V_2 -> V_37 + 0 ;
V_4 -> type = V_58 ;
V_4 -> V_59 = V_60 | V_61 ;
V_4 -> V_38 = 8 ;
V_4 -> V_62 = F_1 ;
V_4 -> V_63 = 0x1fff ;
V_4 -> V_64 = & V_65 ;
V_4 = V_2 -> V_37 + 1 ;
V_4 -> type = V_66 ;
V_4 -> V_59 = V_67 ;
V_4 -> V_38 = 8 ;
V_4 -> V_62 = F_6 ;
V_4 -> V_68 = F_7 ;
V_4 -> V_63 = 0xfff ;
V_4 -> V_64 = & V_65 ;
V_4 = V_2 -> V_37 + 2 ;
V_4 -> type = V_69 ;
V_4 -> V_59 = V_60 ;
V_4 -> V_38 = 16 ;
V_4 -> V_70 = F_8 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = & V_71 ;
V_4 = V_2 -> V_37 + 3 ;
V_4 -> type = V_72 ;
V_4 -> V_59 = V_67 ;
V_4 -> V_38 = 16 ;
V_4 -> V_70 = F_9 ;
V_4 -> V_63 = 1 ;
V_4 -> V_64 = & V_71 ;
V_4 -> V_29 = 0 ;
V_4 = V_2 -> V_37 + 4 ;
V_4 -> type = V_73 ;
V_4 -> V_59 = V_60 | V_74 ;
V_4 -> V_38 = V_46 -> V_49 [ 2 ] * 2 ;
V_4 -> V_62 = F_10 ;
V_4 -> V_63 = 0xffffff ;
V_4 -> V_64 = & V_75 ;
F_12 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_16 )
F_19 ( V_2 -> V_16 , V_52 ) ;
if ( V_2 -> V_48 )
F_20 ( V_2 -> V_48 , V_2 ) ;
}

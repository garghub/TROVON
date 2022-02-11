static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 , V_12 ;
int V_13 ;
int V_14 = F_2 ( V_6 -> V_15 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ ) {
V_12 = V_7 [ V_13 ] & 0xff ;
V_11 = ( V_7 [ V_13 ] >> 8 ) & 0xf ;
if ( V_9 -> V_16 [ V_14 ] )
V_11 ^= 0x8 ;
F_3 ( V_11 , V_2 -> V_17 + V_18 + 2 * V_14 ) ;
F_3 ( V_12 , V_2 -> V_17 + V_19 + 2 * V_14 ) ;
V_9 -> V_20 [ V_14 ] = V_7 [ V_13 ] ;
}
return V_13 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_14 = F_2 ( V_6 -> V_15 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_13 ; V_13 ++ )
V_7 [ V_13 ] = V_9 -> V_20 [ V_14 ] ;
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_21 * V_22 = F_6 ( V_2 ) ;
V_7 [ 1 ] = F_7 ( V_2 -> V_17 + V_22 -> V_23 ) |
( F_7 ( V_2 -> V_17 + V_22 -> V_24 ) << 8 ) ;
return V_6 -> V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_21 * V_22 = F_6 ( V_2 ) ;
if ( V_7 [ 0 ] ) {
V_4 -> V_25 &= ~ V_7 [ 0 ] ;
V_4 -> V_25 |= V_7 [ 0 ] & V_7 [ 1 ] ;
}
if ( V_7 [ 1 ] & 0x00ff )
F_3 ( V_4 -> V_25 & 0xff , V_2 -> V_17 + V_22 -> V_26 ) ;
if ( V_7 [ 1 ] & 0xff00 )
F_3 ( ( V_4 -> V_25 >> 8 ) , V_2 -> V_17 + V_22 -> V_27 ) ;
V_7 [ 1 ] = V_4 -> V_25 ;
return V_6 -> V_13 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
const struct V_21 * V_22 = F_6 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned long V_17 ;
unsigned int V_30 ;
int V_31 , V_32 ;
#ifdef F_10
unsigned int V_33 ;
#endif
V_17 = V_29 -> V_34 [ 0 ] ;
V_30 = V_22 -> V_35 ;
F_11 ( V_36 L_1 , V_2 -> V_37 ,
V_22 -> V_38 , V_17 ) ;
if ( ! F_12 ( V_17 , V_30 , L_2 ) ) {
F_11 ( V_36 L_3 ) ;
return - V_39 ;
}
V_2 -> V_17 = V_17 ;
V_2 -> V_40 = V_22 -> V_38 ;
V_9 = F_13 ( sizeof( * V_9 ) , V_41 ) ;
if ( ! V_9 )
return - V_42 ;
V_2 -> V_10 = V_9 ;
for ( V_32 = 0 ; V_32 < 12 ; V_32 ++ ) {
V_9 -> V_16 [ V_32 ] = 0 ;
V_9 -> V_43 [ V_32 ] = & V_44 ;
}
#ifdef F_10
V_33 = 0 ;
if ( V_45 [ V_22 ] . V_46 != 0 ) {
V_33 = V_29 -> V_34 [ 1 ] ;
V_9 -> V_47 = 2 ;
if ( V_33 ) {
if ( ( ( 1 << V_33 ) & V_45 [ V_22 ] . V_46 ) == 0 ) {
F_11 ( V_36
L_4
L_5 , V_33 ) ;
V_33 = 0 ;
} else {
if ( F_14 ( V_33 , V_48 , 0 ,
L_2 , V_2 ) ) {
F_11 ( V_36
L_6
L_5 , V_33 ) ;
V_33 = 0 ;
} else {
F_11 ( L_7 , V_33 ) ;
}
}
}
}
V_2 -> V_33 = V_33 ;
#endif
F_11 ( L_8 ) ;
V_31 = F_15 ( V_2 , 3 ) ;
if ( V_31 )
return V_31 ;
V_4 = & V_2 -> V_49 [ 0 ] ;
V_4 -> type = V_50 ;
V_4 -> V_51 = V_52 | V_53 ;
V_4 -> V_54 = V_22 -> V_55 ;
V_4 -> V_56 = 0xfff ;
V_4 -> V_57 = 1 ;
V_4 -> V_58 = F_1 ;
V_4 -> V_59 = F_4 ;
V_4 -> V_60 = V_9 -> V_43 ;
for ( V_32 = 0 ; V_32 < V_22 -> V_55 ; V_32 ++ ) {
int V_61 ;
V_61 = V_29 -> V_34 [ 2 + 1 ] ;
if ( ( V_61 < 0 ) || ( V_61 >= V_22 -> V_62 ) ) {
F_11
( L_9 ,
V_32 , V_61 , V_22 -> V_62 - 1 ) ;
V_61 = 0 ;
}
V_9 -> V_43 [ V_32 ] = V_22 -> V_63 [ V_61 ] ;
if ( V_9 -> V_43 [ V_32 ] -> V_64 [ 0 ] . V_65 ==
- V_9 -> V_43 [ V_32 ] -> V_64 [ 0 ] . V_66 )
V_9 -> V_16 [ V_32 ] = 1 ;
}
V_4 = & V_2 -> V_49 [ 1 ] ;
if ( ! V_22 -> V_67 ) {
V_4 -> type = V_68 ;
} else {
V_4 -> type = V_69 ;
V_4 -> V_51 = V_70 | V_53 ;
V_4 -> V_54 = 16 ;
V_4 -> V_56 = 1 ;
V_4 -> V_57 = 1 ;
V_4 -> V_71 = F_5 ;
V_4 -> V_72 = & V_73 ;
}
V_4 = & V_2 -> V_49 [ 2 ] ;
if ( ! V_22 -> V_67 ) {
V_4 -> type = V_68 ;
} else {
V_4 -> type = V_74 ;
V_4 -> V_51 = V_52 | V_53 ;
V_4 -> V_54 = 16 ;
V_4 -> V_56 = 1 ;
V_4 -> V_57 = 1 ;
V_4 -> V_71 = F_8 ;
V_4 -> V_72 = & V_73 ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
const struct V_21 * V_22 = F_6 ( V_2 ) ;
#ifdef F_10
if ( V_2 -> V_33 )
F_17 ( V_2 -> V_33 , V_2 ) ;
#endif
if ( V_2 -> V_17 )
F_18 ( V_2 -> V_17 , V_22 -> V_35 ) ;
}

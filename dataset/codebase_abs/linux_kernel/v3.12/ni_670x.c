static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
int V_12 = F_2 ( V_6 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_14 ; V_11 ++ ) {
F_3 ( ( ( V_12 & 15 ) << 1 ) | ( ( V_12 & 16 ) >> 4 ) ,
V_9 -> V_15 -> V_16 + V_17 ) ;
F_3 ( V_7 [ V_11 ] , V_9 -> V_15 -> V_16 + V_18 ) ;
V_9 -> V_19 [ V_12 ] = V_7 [ V_11 ] ;
}
return V_11 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
int V_12 = F_2 ( V_6 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_14 ; V_11 ++ )
V_7 [ V_11 ] = V_9 -> V_19 [ V_12 ] ;
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
void T_1 * V_20 = V_9 -> V_15 -> V_16 +
V_21 ;
unsigned int V_22 = V_7 [ 0 ] ;
unsigned int V_23 = V_7 [ 1 ] ;
if ( V_22 ) {
V_4 -> V_24 &= ~ V_22 ;
V_4 -> V_24 |= ( V_23 & V_22 ) ;
F_3 ( V_4 -> V_24 , V_20 ) ;
}
V_7 [ 1 ] = F_6 ( V_20 ) ;
return V_6 -> V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_25 ;
V_25 = F_8 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_25 )
return V_25 ;
F_3 ( V_4 -> V_26 , V_9 -> V_15 -> V_16 + V_27 ) ;
return V_6 -> V_14 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned long V_28 )
{
struct V_29 * V_30 = F_10 ( V_2 ) ;
const struct V_31 * V_32 = NULL ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_25 ;
int V_11 ;
if ( V_28 < F_11 ( V_33 ) )
V_32 = & V_33 [ V_28 ] ;
if ( ! V_32 )
return - V_34 ;
V_2 -> V_35 = V_32 ;
V_2 -> V_36 = V_32 -> V_37 ;
V_25 = F_12 ( V_2 ) ;
if ( V_25 )
return V_25 ;
V_9 = F_13 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_38 ;
V_9 -> V_15 = F_14 ( V_30 ) ;
if ( ! V_9 -> V_15 )
return - V_38 ;
V_25 = F_15 ( V_9 -> V_15 ) ;
if ( V_25 < 0 ) {
F_16 ( V_2 -> V_39 , L_1 ) ;
return V_25 ;
}
V_25 = F_17 ( V_2 , 2 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_40 [ 0 ] ;
V_4 -> type = V_41 ;
V_4 -> V_42 = V_43 ;
V_4 -> V_44 = V_32 -> V_45 ;
V_4 -> V_46 = 0xffff ;
if ( V_4 -> V_44 == 32 ) {
const struct V_47 * * V_48 ;
V_48 = F_18 ( sizeof( struct V_47 * ) * 32 ,
V_49 ) ;
if ( ! V_48 )
return - V_38 ;
V_4 -> V_48 = V_48 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_48 [ V_11 ] = & V_50 ;
V_48 [ 16 + V_11 ] = & V_51 ;
}
} else {
V_4 -> V_52 = & V_50 ;
}
V_4 -> V_53 = & F_1 ;
V_4 -> V_54 = & F_4 ;
V_4 = & V_2 -> V_40 [ 1 ] ;
V_4 -> type = V_55 ;
V_4 -> V_42 = V_56 | V_43 ;
V_4 -> V_44 = 8 ;
V_4 -> V_46 = 1 ;
V_4 -> V_52 = & V_57 ;
V_4 -> V_58 = F_5 ;
V_4 -> V_59 = F_7 ;
F_3 ( 0x10 , V_9 -> V_15 -> V_16 + V_60 ) ;
F_3 ( 0x00 , V_9 -> V_15 -> V_16 + V_61 ) ;
F_19 ( V_2 -> V_39 , L_2 ,
V_2 -> V_62 -> V_63 , V_2 -> V_36 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 ;
if ( V_2 -> V_64 ) {
V_4 = & V_2 -> V_40 [ 0 ] ;
if ( V_4 )
F_21 ( V_4 -> V_48 ) ;
}
if ( V_9 && V_9 -> V_15 ) {
F_22 ( V_9 -> V_15 ) ;
F_23 ( V_9 -> V_15 ) ;
}
F_24 ( V_2 ) ;
}
static int F_25 ( struct V_29 * V_2 ,
const struct V_65 * V_66 )
{
return F_26 ( V_2 , & V_67 , V_66 -> V_68 ) ;
}

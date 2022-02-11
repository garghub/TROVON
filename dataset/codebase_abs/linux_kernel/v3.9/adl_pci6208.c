static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned long V_13 = 1 << ( 16 - 1 ) ;
unsigned long V_14 = 0 ;
unsigned short V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ ) {
V_14 = V_7 [ V_16 ] ^ V_13 ;
do {
V_15 = F_3 ( V_2 -> V_18 + V_19 ) ;
} while ( V_15 & V_20 );
F_4 ( V_14 , V_2 -> V_18 + F_5 ( V_11 ) ) ;
}
V_9 -> V_21 [ V_11 ] = V_14 ;
return V_6 -> V_17 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = F_2 ( V_6 -> V_12 ) ;
int V_16 ;
for ( V_16 = 0 ; V_16 < V_6 -> V_17 ; V_16 ++ )
V_7 [ V_16 ] = V_9 -> V_21 [ V_11 ] ;
return V_6 -> V_17 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_22 ;
V_22 = F_3 ( V_2 -> V_18 + V_23 ) ;
V_22 = ( V_22 & V_24 ) >> V_25 ;
V_7 [ 1 ] = V_22 ;
return V_6 -> V_17 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_26 = V_7 [ 0 ] ;
unsigned int V_27 = V_7 [ 1 ] ;
if ( V_26 ) {
V_4 -> V_28 &= ~ V_26 ;
V_4 -> V_28 |= ( V_27 & V_26 ) ;
F_4 ( V_4 -> V_28 , V_2 -> V_18 + V_23 ) ;
}
V_7 [ 1 ] = V_4 -> V_28 ;
return V_6 -> V_17 ;
}
static const void * F_9 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
const struct V_31 * V_32 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_10 ( V_33 ) ; V_16 ++ ) {
V_32 = & V_33 [ V_16 ] ;
if ( V_32 -> V_34 == V_30 -> V_35 )
return V_32 ;
}
return NULL ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_36 )
{
struct V_29 * V_30 = F_12 ( V_2 ) ;
const struct V_31 * V_32 ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
unsigned int V_22 ;
int V_37 ;
V_32 = F_9 ( V_2 , V_30 ) ;
if ( ! V_32 )
return - V_38 ;
V_2 -> V_39 = V_32 ;
V_2 -> V_40 = V_32 -> V_41 ;
V_9 = F_13 ( sizeof( * V_9 ) , V_42 ) ;
if ( ! V_9 )
return - V_43 ;
V_2 -> V_10 = V_9 ;
V_37 = F_14 ( V_30 , V_2 -> V_40 ) ;
if ( V_37 )
return V_37 ;
V_2 -> V_18 = F_15 ( V_30 , 2 ) ;
V_37 = F_16 ( V_2 , 3 ) ;
if ( V_37 )
return V_37 ;
V_4 = & V_2 -> V_44 [ 0 ] ;
V_4 -> type = V_45 ;
V_4 -> V_46 = V_47 ;
V_4 -> V_48 = V_32 -> V_49 ;
V_4 -> V_50 = 0xffff ;
V_4 -> V_51 = & V_52 ;
V_4 -> V_53 = F_1 ;
V_4 -> V_54 = F_6 ;
V_4 = & V_2 -> V_44 [ 1 ] ;
V_4 -> type = V_55 ;
V_4 -> V_46 = V_56 ;
V_4 -> V_48 = 4 ;
V_4 -> V_50 = 1 ;
V_4 -> V_51 = & V_57 ;
V_4 -> V_58 = F_7 ;
V_4 = & V_2 -> V_44 [ 2 ] ;
V_4 -> type = V_59 ;
V_4 -> V_46 = V_47 ;
V_4 -> V_48 = 4 ;
V_4 -> V_50 = 1 ;
V_4 -> V_51 = & V_57 ;
V_4 -> V_58 = F_8 ;
V_22 = F_3 ( V_2 -> V_18 + V_23 ) ;
V_22 = ( V_22 & V_60 ) >> V_61 ;
V_4 -> V_28 = V_22 ;
V_4 -> V_62 = 0x0f ;
F_17 ( V_2 -> V_63 , L_1 ,
V_2 -> V_64 -> V_65 , V_2 -> V_40 , V_2 -> V_18 ) ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = F_12 ( V_2 ) ;
if ( V_30 ) {
if ( V_2 -> V_18 )
F_19 ( V_30 ) ;
}
}
static int F_20 ( struct V_29 * V_2 ,
const struct V_66 * V_67 )
{
return F_21 ( V_2 , & V_68 ) ;
}

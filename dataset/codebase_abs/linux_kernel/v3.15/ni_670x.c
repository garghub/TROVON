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
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
void T_1 * V_20 = V_9 -> V_15 -> V_16 +
V_21 ;
if ( F_6 ( V_4 , V_7 ) )
F_3 ( V_4 -> V_22 , V_20 ) ;
V_7 [ 1 ] = F_7 ( V_20 ) ;
return V_6 -> V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_23 ;
V_23 = F_9 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_23 )
return V_23 ;
F_3 ( V_4 -> V_24 , V_9 -> V_15 -> V_16 + V_25 ) ;
return V_6 -> V_14 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_27 * V_28 = F_11 ( V_2 ) ;
const struct V_29 * V_30 = NULL ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_23 ;
int V_11 ;
if ( V_26 < F_12 ( V_31 ) )
V_30 = & V_31 [ V_26 ] ;
if ( ! V_30 )
return - V_32 ;
V_2 -> V_33 = V_30 ;
V_2 -> V_34 = V_30 -> V_35 ;
V_23 = F_13 ( V_2 ) ;
if ( V_23 )
return V_23 ;
V_9 = F_14 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_36 ;
V_9 -> V_15 = F_15 ( V_28 ) ;
if ( ! V_9 -> V_15 )
return - V_36 ;
V_23 = F_16 ( V_9 -> V_15 ) ;
if ( V_23 < 0 ) {
F_17 ( V_2 -> V_37 , L_1 ) ;
return V_23 ;
}
V_23 = F_18 ( V_2 , 2 ) ;
if ( V_23 )
return V_23 ;
V_4 = & V_2 -> V_38 [ 0 ] ;
V_4 -> type = V_39 ;
V_4 -> V_40 = V_41 ;
V_4 -> V_42 = V_30 -> V_43 ;
V_4 -> V_44 = 0xffff ;
if ( V_4 -> V_42 == 32 ) {
const struct V_45 * * V_46 ;
V_46 = F_19 ( sizeof( struct V_45 * ) * 32 ,
V_47 ) ;
if ( ! V_46 )
return - V_36 ;
V_4 -> V_46 = V_46 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_46 [ V_11 ] = & V_48 ;
V_46 [ 16 + V_11 ] = & V_49 ;
}
} else {
V_4 -> V_50 = & V_48 ;
}
V_4 -> V_51 = & F_1 ;
V_4 -> V_52 = & F_4 ;
V_4 = & V_2 -> V_38 [ 1 ] ;
V_4 -> type = V_53 ;
V_4 -> V_40 = V_54 | V_41 ;
V_4 -> V_42 = 8 ;
V_4 -> V_44 = 1 ;
V_4 -> V_50 = & V_55 ;
V_4 -> V_56 = F_5 ;
V_4 -> V_57 = F_8 ;
F_3 ( 0x10 , V_9 -> V_15 -> V_16 + V_58 ) ;
F_3 ( 0x00 , V_9 -> V_15 -> V_16 + V_59 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_3 * V_4 ;
if ( V_2 -> V_60 ) {
V_4 = & V_2 -> V_38 [ 0 ] ;
if ( V_4 )
F_21 ( V_4 -> V_46 ) ;
}
if ( V_9 && V_9 -> V_15 ) {
F_22 ( V_9 -> V_15 ) ;
F_23 ( V_9 -> V_15 ) ;
}
F_24 ( V_2 ) ;
}
static int F_25 ( struct V_27 * V_2 ,
const struct V_61 * V_62 )
{
return F_26 ( V_2 , & V_63 , V_62 -> V_64 ) ;
}

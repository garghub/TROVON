static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 ;
int V_12 = F_2 ( V_6 -> V_13 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_14 ; V_11 ++ ) {
F_3 ( ( ( V_12 & 15 ) << 1 ) | ( ( V_12 & 16 ) >> 4 ) ,
V_2 -> V_15 + V_16 ) ;
F_3 ( V_7 [ V_11 ] , V_2 -> V_15 + V_17 ) ;
V_9 -> V_18 [ V_12 ] = V_7 [ V_11 ] ;
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
V_7 [ V_11 ] = V_9 -> V_18 [ V_12 ] ;
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_6 ( V_4 , V_7 ) )
F_3 ( V_4 -> V_19 , V_2 -> V_15 + V_20 ) ;
V_7 [ 1 ] = F_7 ( V_2 -> V_15 + V_20 ) ;
return V_6 -> V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_21 ;
V_21 = F_9 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_21 )
return V_21 ;
F_3 ( V_4 -> V_22 , V_2 -> V_15 + V_23 ) ;
return V_6 -> V_14 ;
}
static int F_10 ( struct V_24 * V_25 )
{
void T_1 * V_26 ;
T_2 V_27 ;
V_26 = F_11 ( V_25 , 0 ) ;
if ( ! V_26 )
return - V_28 ;
V_27 = F_12 ( V_25 , 1 ) ;
F_3 ( V_27 | V_29 , V_26 + V_30 ) ;
F_13 ( V_26 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned long V_31 )
{
struct V_24 * V_25 = F_15 ( V_2 ) ;
const struct V_32 * V_33 = NULL ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_21 ;
int V_11 ;
if ( V_31 < F_16 ( V_34 ) )
V_33 = & V_34 [ V_31 ] ;
if ( ! V_33 )
return - V_35 ;
V_2 -> V_36 = V_33 ;
V_2 -> V_37 = V_33 -> V_38 ;
V_21 = F_17 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_9 = F_18 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_28 ;
V_21 = F_10 ( V_25 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_15 = F_11 ( V_25 , 1 ) ;
if ( ! V_2 -> V_15 )
return - V_28 ;
V_21 = F_19 ( V_2 , 2 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_39 [ 0 ] ;
V_4 -> type = V_40 ;
V_4 -> V_41 = V_42 ;
V_4 -> V_43 = V_33 -> V_44 ;
V_4 -> V_45 = 0xffff ;
if ( V_4 -> V_43 == 32 ) {
const struct V_46 * * V_47 ;
V_47 = F_20 ( sizeof( struct V_46 * ) * 32 ,
V_48 ) ;
if ( ! V_47 )
return - V_28 ;
V_4 -> V_47 = V_47 ;
for ( V_11 = 0 ; V_11 < 16 ; V_11 ++ ) {
V_47 [ V_11 ] = & V_49 ;
V_47 [ 16 + V_11 ] = & V_50 ;
}
} else {
V_4 -> V_51 = & V_49 ;
}
V_4 -> V_52 = & F_1 ;
V_4 -> V_53 = & F_4 ;
V_4 = & V_2 -> V_39 [ 1 ] ;
V_4 -> type = V_54 ;
V_4 -> V_41 = V_55 | V_42 ;
V_4 -> V_43 = 8 ;
V_4 -> V_45 = 1 ;
V_4 -> V_51 = & V_56 ;
V_4 -> V_57 = F_5 ;
V_4 -> V_58 = F_8 ;
F_3 ( 0x10 , V_2 -> V_15 + V_59 ) ;
F_3 ( 0x00 , V_2 -> V_15 + V_60 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
if ( V_2 -> V_61 ) {
V_4 = & V_2 -> V_39 [ 0 ] ;
if ( V_4 )
F_22 ( V_4 -> V_47 ) ;
}
if ( V_2 -> V_15 )
F_13 ( V_2 -> V_15 ) ;
F_23 ( V_2 ) ;
}
static int F_24 ( struct V_24 * V_2 ,
const struct V_62 * V_63 )
{
return F_25 ( V_2 , & V_64 , V_63 -> V_65 ) ;
}

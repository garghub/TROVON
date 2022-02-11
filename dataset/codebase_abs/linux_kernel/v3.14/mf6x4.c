static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 1 ] = F_2 ( V_9 -> V_11 + V_12 ) & V_13 ;
return V_6 -> V_14 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( F_4 ( V_4 , V_7 ) )
F_5 ( V_4 -> V_15 & V_16 ,
V_9 -> V_11 + V_17 ) ;
V_7 [ 1 ] = V_4 -> V_15 ;
return V_6 -> V_14 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_19 ;
while ( V_18 -- ) {
V_19 = F_7 ( V_9 -> V_20 ) & V_21 ;
if ( V_19 )
return 0 ;
F_8 ( 1 ) ;
}
return - V_22 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_23 = F_10 ( V_6 -> V_24 ) ;
int V_25 ;
int V_26 ;
int V_27 ;
F_5 ( ( 1 << V_23 ) & V_28 ,
V_9 -> V_11 + V_29 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_14 ; V_26 ++ ) {
F_2 ( V_9 -> V_11 + V_30 ) ;
V_25 = F_6 ( V_2 , 100 ) ;
if ( V_25 )
return V_25 ;
V_27 = F_2 ( V_9 -> V_11 + V_31 ) ;
V_27 &= V_4 -> V_32 ;
V_7 [ V_26 ] = V_27 ;
}
F_5 ( 0x0 , V_9 -> V_11 + V_29 ) ;
return V_6 -> V_14 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_23 = F_10 ( V_6 -> V_24 ) ;
T_1 V_33 ;
int V_26 ;
V_33 = F_7 ( V_9 -> V_20 ) ;
F_12 ( ( V_33 & ~ V_34 ) | V_35 ,
V_9 -> V_20 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_14 ; V_26 ++ ) {
F_5 ( V_7 [ V_26 ] & V_36 ,
V_9 -> V_11 + F_13 ( V_23 ) ) ;
V_9 -> V_37 [ V_23 ] = V_7 [ V_26 ] ;
}
return V_6 -> V_14 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_23 = F_10 ( V_6 -> V_24 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_6 -> V_14 ; V_26 ++ )
V_7 [ V_26 ] = V_9 -> V_37 [ V_23 ] ;
return V_6 -> V_14 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_38 )
{
struct V_39 * V_40 = F_16 ( V_2 ) ;
const struct V_41 * V_42 = NULL ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_25 ;
if ( V_38 < F_17 ( V_43 ) )
V_42 = & V_43 [ V_38 ] ;
else
return - V_44 ;
V_2 -> V_45 = V_42 ;
V_2 -> V_46 = V_42 -> V_47 ;
V_25 = F_18 ( V_2 ) ;
if ( V_25 )
return V_25 ;
V_9 = F_19 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_48 ;
V_9 -> V_49 = F_20 ( V_40 , V_42 -> V_50 [ 0 ] ) ;
if ( ! V_9 -> V_49 )
return - V_44 ;
V_9 -> V_11 = F_20 ( V_40 , V_42 -> V_50 [ 1 ] ) ;
if ( ! V_9 -> V_11 )
return - V_44 ;
V_9 -> V_51 = F_20 ( V_40 , V_42 -> V_50 [ 2 ] ) ;
if ( ! V_9 -> V_51 )
return - V_44 ;
if ( V_42 == & V_43 [ V_52 ] )
V_9 -> V_20 = V_9 -> V_51 + V_53 ;
else
V_9 -> V_20 = V_9 -> V_49 + V_54 ;
V_25 = F_21 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_55 [ 0 ] ;
V_4 -> type = V_56 ;
V_4 -> V_57 = V_58 | V_59 ;
V_4 -> V_60 = 8 ;
V_4 -> V_32 = 0x3fff ;
V_4 -> V_61 = & V_62 ;
V_4 -> V_63 = F_9 ;
V_4 = & V_2 -> V_55 [ 1 ] ;
V_4 -> type = V_64 ;
V_4 -> V_57 = V_65 ;
V_4 -> V_60 = 8 ;
V_4 -> V_32 = 0x3fff ;
V_4 -> V_61 = & V_62 ;
V_4 -> V_66 = F_11 ;
V_4 -> V_63 = F_14 ;
V_4 = & V_2 -> V_55 [ 2 ] ;
V_4 -> type = V_67 ;
V_4 -> V_57 = V_58 ;
V_4 -> V_60 = 8 ;
V_4 -> V_32 = 1 ;
V_4 -> V_61 = & V_68 ;
V_4 -> V_69 = F_1 ;
V_4 = & V_2 -> V_55 [ 3 ] ;
V_4 -> type = V_70 ;
V_4 -> V_57 = V_65 ;
V_4 -> V_60 = 8 ;
V_4 -> V_32 = 1 ;
V_4 -> V_61 = & V_68 ;
V_4 -> V_69 = F_3 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
if ( V_9 -> V_49 )
F_23 ( V_9 -> V_49 ) ;
if ( V_9 -> V_11 )
F_23 ( V_9 -> V_11 ) ;
if ( V_9 -> V_51 )
F_23 ( V_9 -> V_51 ) ;
F_24 ( V_2 ) ;
}
static int F_25 ( struct V_39 * V_2 , const struct V_71 * V_72 )
{
return F_26 ( V_2 , & V_73 , V_72 -> V_74 ) ;
}

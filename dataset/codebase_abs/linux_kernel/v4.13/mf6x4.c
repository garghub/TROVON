static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
V_7 [ 1 ] = F_2 ( V_2 -> V_8 + V_9 ) & V_10 ;
return V_6 -> V_11 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_4 ( V_4 , V_7 ) )
F_5 ( V_4 -> V_12 , V_2 -> V_8 + V_13 ) ;
V_7 [ 1 ] = V_4 -> V_12 ;
return V_6 -> V_11 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_14 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_18 ;
V_18 = F_7 ( V_16 -> V_19 ) ;
if ( V_18 & V_20 )
return 0 ;
return - V_21 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_22 = F_9 ( V_6 -> V_23 ) ;
unsigned int V_24 ;
int V_25 ;
int V_26 ;
F_5 ( F_10 ( V_22 ) , V_2 -> V_8 + V_27 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_11 ; V_26 ++ ) {
F_2 ( V_2 -> V_8 + V_28 ) ;
V_25 = F_11 ( V_2 , V_4 , V_6 , F_6 , 0 ) ;
if ( V_25 )
return V_25 ;
V_24 = F_2 ( V_2 -> V_8 + V_29 ) ;
V_24 &= V_4 -> V_30 ;
V_7 [ V_26 ] = F_12 ( V_4 , V_24 ) ;
}
F_5 ( 0x0 , V_2 -> V_8 + V_27 ) ;
return V_6 -> V_11 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
unsigned int V_22 = F_9 ( V_6 -> V_23 ) ;
unsigned int V_31 = V_4 -> V_32 [ V_22 ] ;
unsigned int V_33 ;
int V_26 ;
V_33 = F_7 ( V_16 -> V_19 ) ;
F_14 ( ( V_33 & ~ V_34 ) | V_35 ,
V_16 -> V_19 ) ;
for ( V_26 = 0 ; V_26 < V_6 -> V_11 ; V_26 ++ ) {
V_31 = V_7 [ V_26 ] ;
F_5 ( V_31 , V_2 -> V_8 + F_15 ( V_22 ) ) ;
}
V_4 -> V_32 [ V_22 ] = V_31 ;
return V_6 -> V_11 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned long V_14 )
{
struct V_36 * V_37 = F_17 ( V_2 ) ;
const struct V_38 * V_39 = NULL ;
struct V_15 * V_16 ;
struct V_3 * V_4 ;
int V_25 ;
if ( V_14 < F_18 ( V_40 ) )
V_39 = & V_40 [ V_14 ] ;
else
return - V_41 ;
V_2 -> V_42 = V_39 ;
V_2 -> V_43 = V_39 -> V_44 ;
V_25 = F_19 ( V_2 ) ;
if ( V_25 )
return V_25 ;
V_16 = F_20 ( V_2 , sizeof( * V_16 ) ) ;
if ( ! V_16 )
return - V_45 ;
V_16 -> V_46 = F_21 ( V_37 , V_39 -> V_47 [ 0 ] ) ;
if ( ! V_16 -> V_46 )
return - V_41 ;
V_2 -> V_8 = F_21 ( V_37 , V_39 -> V_47 [ 1 ] ) ;
if ( ! V_2 -> V_8 )
return - V_41 ;
V_16 -> V_48 = F_21 ( V_37 , V_39 -> V_47 [ 2 ] ) ;
if ( ! V_16 -> V_48 )
return - V_41 ;
if ( V_39 == & V_40 [ V_49 ] )
V_16 -> V_19 = V_16 -> V_48 + V_50 ;
else
V_16 -> V_19 = V_16 -> V_46 + V_51 ;
V_25 = F_22 ( V_2 , 4 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_52 [ 0 ] ;
V_4 -> type = V_53 ;
V_4 -> V_54 = V_55 | V_56 ;
V_4 -> V_57 = 8 ;
V_4 -> V_30 = 0x3fff ;
V_4 -> V_58 = & V_59 ;
V_4 -> V_60 = F_8 ;
V_4 = & V_2 -> V_52 [ 1 ] ;
V_4 -> type = V_61 ;
V_4 -> V_54 = V_62 ;
V_4 -> V_57 = 8 ;
V_4 -> V_30 = 0x3fff ;
V_4 -> V_58 = & V_59 ;
V_4 -> V_63 = F_13 ;
V_25 = F_23 ( V_4 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_52 [ 2 ] ;
V_4 -> type = V_64 ;
V_4 -> V_54 = V_55 ;
V_4 -> V_57 = 8 ;
V_4 -> V_30 = 1 ;
V_4 -> V_58 = & V_65 ;
V_4 -> V_66 = F_1 ;
V_4 = & V_2 -> V_52 [ 3 ] ;
V_4 -> type = V_67 ;
V_4 -> V_54 = V_62 ;
V_4 -> V_57 = 8 ;
V_4 -> V_30 = 1 ;
V_4 -> V_58 = & V_65 ;
V_4 -> V_66 = F_3 ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = V_2 -> V_17 ;
if ( V_16 ) {
if ( V_16 -> V_46 )
F_25 ( V_16 -> V_46 ) ;
if ( V_16 -> V_48 )
F_25 ( V_16 -> V_48 ) ;
}
F_26 ( V_2 ) ;
}
static int F_27 ( struct V_36 * V_2 , const struct V_68 * V_69 )
{
return F_28 ( V_2 , & V_70 , V_69 -> V_71 ) ;
}

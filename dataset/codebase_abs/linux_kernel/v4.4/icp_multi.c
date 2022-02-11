static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
if ( ( V_8 & V_11 ) == 0 )
return 0 ;
return - V_12 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
unsigned int V_16 = F_5 ( V_6 -> V_15 ) ;
unsigned int V_17 = F_6 ( V_6 -> V_15 ) ;
unsigned int V_18 ;
int V_19 = 0 ;
int V_20 ;
if ( V_17 == V_21 ) {
V_18 = F_7 ( V_14 ) |
V_22 ;
} else {
V_18 = F_8 ( V_14 ) ;
}
V_18 |= V_23 [ V_16 ] ;
F_9 ( V_18 , V_2 -> V_9 + V_10 ) ;
for ( V_20 = 0 ; V_20 < V_6 -> V_20 ; V_20 ++ ) {
F_9 ( V_18 | V_24 ,
V_2 -> V_9 + V_10 ) ;
F_10 ( 1 ) ;
V_19 = F_11 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_19 )
break;
V_13 [ V_20 ] = ( F_2 ( V_2 -> V_9 + V_25 ) >> 4 ) & 0x0fff ;
}
return V_19 ? V_19 : V_20 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
unsigned int V_8 ;
V_8 = F_2 ( V_2 -> V_9 + V_26 ) ;
if ( ( V_8 & V_27 ) == 0 )
return 0 ;
return - V_12 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
unsigned int V_14 = F_4 ( V_6 -> V_15 ) ;
unsigned int V_16 = F_5 ( V_6 -> V_15 ) ;
unsigned int V_28 ;
int V_29 ;
V_28 = F_14 ( V_14 ) ;
V_28 |= V_23 [ V_16 ] ;
F_9 ( V_28 , V_2 -> V_9 + V_26 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_20 ; V_29 ++ ) {
unsigned int V_30 = V_13 [ V_29 ] ;
int V_19 ;
V_19 = F_11 ( V_2 , V_4 , V_6 , F_12 , 0 ) ;
if ( V_19 )
return V_19 ;
F_9 ( V_30 , V_2 -> V_9 + V_31 ) ;
F_9 ( V_28 | V_32 ,
V_2 -> V_9 + V_26 ) ;
V_4 -> V_33 [ V_14 ] = V_30 ;
}
return V_6 -> V_20 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
V_13 [ 1 ] = F_2 ( V_2 -> V_9 + V_34 ) ;
return V_6 -> V_20 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_13 )
{
if ( F_17 ( V_4 , V_13 ) )
F_9 ( V_4 -> V_35 , V_2 -> V_9 + V_36 ) ;
V_13 [ 1 ] = V_4 -> V_35 ;
return V_6 -> V_20 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_29 ;
F_9 ( 0 , V_2 -> V_9 + V_37 ) ;
F_9 ( V_38 , V_2 -> V_9 + V_39 ) ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
unsigned int V_28 = F_14 ( V_29 ) ;
F_9 ( V_28 , V_2 -> V_9 + V_26 ) ;
F_9 ( 0 , V_2 -> V_9 + V_31 ) ;
F_9 ( V_28 | V_32 ,
V_2 -> V_9 + V_26 ) ;
F_10 ( 1 ) ;
}
F_9 ( 0 , V_2 -> V_9 + V_36 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned long V_40 )
{
struct V_41 * V_42 = F_20 ( V_2 ) ;
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_21 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_9 = F_22 ( V_42 , 2 ) ;
if ( ! V_2 -> V_9 )
return - V_43 ;
V_19 = F_23 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_18 ( V_2 ) ;
V_4 = & V_2 -> V_44 [ 0 ] ;
V_4 -> type = V_45 ;
V_4 -> V_46 = V_47 | V_48 | V_49 | V_50 ;
V_4 -> V_51 = 16 ;
V_4 -> V_52 = 0x0fff ;
V_4 -> V_53 = & V_54 ;
V_4 -> V_55 = F_3 ;
V_4 = & V_2 -> V_44 [ 1 ] ;
V_4 -> type = V_56 ;
V_4 -> V_46 = V_57 | V_49 | V_48 ;
V_4 -> V_51 = 4 ;
V_4 -> V_52 = 0x0fff ;
V_4 -> V_53 = & V_54 ;
V_4 -> V_58 = F_13 ;
V_19 = F_24 ( V_4 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_44 [ 2 ] ;
V_4 -> type = V_59 ;
V_4 -> V_46 = V_47 ;
V_4 -> V_51 = 16 ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = & V_60 ;
V_4 -> V_61 = F_15 ;
V_4 = & V_2 -> V_44 [ 3 ] ;
V_4 -> type = V_62 ;
V_4 -> V_46 = V_57 ;
V_4 -> V_51 = 8 ;
V_4 -> V_52 = 1 ;
V_4 -> V_53 = & V_60 ;
V_4 -> V_61 = F_16 ;
return 0 ;
}
static int F_25 ( struct V_41 * V_2 ,
const struct V_63 * V_64 )
{
return F_26 ( V_2 , & V_65 , V_64 -> V_66 ) ;
}

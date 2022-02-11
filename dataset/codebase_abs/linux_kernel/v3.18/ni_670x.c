static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 = V_4 -> V_11 [ V_8 ] ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ ) {
V_10 = V_7 [ V_12 ] ;
F_3 ( ( ( V_8 & 15 ) << 1 ) | ( ( V_8 & 16 ) >> 4 ) ,
V_2 -> V_14 + V_15 ) ;
F_3 ( V_10 , V_2 -> V_14 + V_16 ) ;
}
V_4 -> V_11 [ V_8 ] = V_10 ;
return V_6 -> V_13 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_5 ( V_4 , V_7 ) )
F_3 ( V_4 -> V_17 , V_2 -> V_14 + V_18 ) ;
V_7 [ 1 ] = F_6 ( V_2 -> V_14 + V_18 ) ;
return V_6 -> V_13 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
int V_19 ;
V_19 = F_8 ( V_2 , V_4 , V_6 , V_7 , 0 ) ;
if ( V_19 )
return V_19 ;
F_3 ( V_4 -> V_20 , V_2 -> V_14 + V_21 ) ;
return V_6 -> V_13 ;
}
static int F_9 ( struct V_22 * V_23 )
{
void T_1 * V_24 ;
T_2 V_25 ;
V_24 = F_10 ( V_23 , 0 ) ;
if ( ! V_24 )
return - V_26 ;
V_25 = F_11 ( V_23 , 1 ) ;
F_3 ( V_25 | V_27 , V_24 + V_28 ) ;
F_12 ( V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned long V_29 )
{
struct V_22 * V_23 = F_14 ( V_2 ) ;
const struct V_30 * V_31 = NULL ;
struct V_32 * V_33 ;
struct V_3 * V_4 ;
int V_19 ;
int V_12 ;
if ( V_29 < F_15 ( V_34 ) )
V_31 = & V_34 [ V_29 ] ;
if ( ! V_31 )
return - V_35 ;
V_2 -> V_36 = V_31 ;
V_2 -> V_37 = V_31 -> V_38 ;
V_19 = F_16 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_33 = F_17 ( V_2 , sizeof( * V_33 ) ) ;
if ( ! V_33 )
return - V_26 ;
V_19 = F_9 ( V_23 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_14 = F_10 ( V_23 , 1 ) ;
if ( ! V_2 -> V_14 )
return - V_26 ;
V_19 = F_18 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_39 [ 0 ] ;
V_4 -> type = V_40 ;
V_4 -> V_41 = V_42 ;
V_4 -> V_43 = V_31 -> V_44 ;
V_4 -> V_45 = 0xffff ;
if ( V_4 -> V_43 == 32 ) {
const struct V_46 * * V_47 ;
V_47 = F_19 ( sizeof( struct V_46 * ) * 32 ,
V_48 ) ;
if ( ! V_47 )
return - V_26 ;
V_4 -> V_47 = V_47 ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_47 [ V_12 ] = & V_49 ;
V_47 [ 16 + V_12 ] = & V_50 ;
}
} else {
V_4 -> V_51 = & V_49 ;
}
V_4 -> V_52 = F_1 ;
V_4 -> V_53 = V_54 ;
V_19 = F_20 ( V_4 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_39 [ 1 ] ;
V_4 -> type = V_55 ;
V_4 -> V_41 = V_56 | V_42 ;
V_4 -> V_43 = 8 ;
V_4 -> V_45 = 1 ;
V_4 -> V_51 = & V_57 ;
V_4 -> V_58 = F_4 ;
V_4 -> V_59 = F_7 ;
F_3 ( 0x10 , V_2 -> V_14 + V_60 ) ;
F_3 ( 0x00 , V_2 -> V_14 + V_61 ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_22 ( V_2 ) ;
if ( V_2 -> V_62 ) {
V_4 = & V_2 -> V_39 [ 0 ] ;
if ( V_4 )
F_23 ( V_4 -> V_47 ) ;
}
}
static int F_24 ( struct V_22 * V_2 ,
const struct V_63 * V_64 )
{
return F_25 ( V_2 , & V_65 , V_64 -> V_66 ) ;
}

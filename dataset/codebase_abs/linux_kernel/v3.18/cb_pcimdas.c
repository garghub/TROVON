static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned long V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 ;
V_11 = F_2 ( V_9 -> V_12 + 2 ) ;
if ( ( V_11 & 0x80 ) == 0 )
return 0 ;
return - V_13 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_14 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_15 ;
unsigned int V_16 ;
int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned short V_19 ;
int V_20 ;
int V_21 ;
if ( ( F_2 ( V_9 -> V_12 + 2 ) & 0x20 ) == 0 )
V_20 = V_4 -> V_22 / 2 ;
else
V_20 = V_4 -> V_22 ;
if ( V_17 > ( V_20 - 1 ) )
return - V_23 ;
V_16 = F_2 ( V_9 -> V_12 + 5 ) ;
if ( ( V_16 & 0x03 ) > 0 ) {
V_16 = V_16 & 0xfd ;
F_5 ( V_16 , V_9 -> V_12 + 5 ) ;
}
F_5 ( 0x01 , V_9 -> V_12 + 6 ) ;
F_5 ( 0x00 , V_9 -> V_12 + 7 ) ;
V_19 = V_17 | ( V_17 << 4 ) ;
F_5 ( V_19 , V_9 -> V_12 + 0 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
F_6 ( 0 , V_9 -> V_24 + 0 ) ;
V_21 = F_7 ( V_2 , V_4 , V_6 , F_1 , 0 ) ;
if ( V_21 )
return V_21 ;
V_14 [ V_15 ] = F_8 ( V_9 -> V_24 + 0 ) ;
}
return V_15 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_14 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_17 = F_4 ( V_6 -> V_18 ) ;
unsigned int V_25 = V_4 -> V_26 [ V_17 ] ;
unsigned int V_27 = ( V_17 ) ? V_28 : V_29 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_6 -> V_15 ; V_30 ++ ) {
V_25 = V_14 [ V_30 ] ;
F_6 ( V_25 , V_9 -> V_24 + V_27 ) ;
}
V_4 -> V_26 [ V_17 ] = V_25 ;
return V_6 -> V_15 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned long V_31 )
{
struct V_32 * V_33 = F_11 ( V_2 ) ;
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_21 ;
V_9 = F_12 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_34 ;
V_21 = F_13 ( V_2 ) ;
if ( V_21 )
return V_21 ;
V_9 -> V_24 = F_14 ( V_33 , 2 ) ;
V_9 -> V_12 = F_14 ( V_33 , 3 ) ;
V_2 -> V_35 = F_14 ( V_33 , 4 ) ;
V_21 = F_15 ( V_2 , 3 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_36 [ 0 ] ;
V_4 -> type = V_37 ;
V_4 -> V_38 = V_39 | V_40 ;
V_4 -> V_22 = 16 ;
V_4 -> V_41 = 0xffff ;
V_4 -> V_42 = & V_43 ;
V_4 -> V_44 = 1 ;
V_4 -> V_45 = F_3 ;
V_4 = & V_2 -> V_36 [ 1 ] ;
V_4 -> type = V_46 ;
V_4 -> V_38 = V_47 ;
V_4 -> V_22 = 2 ;
V_4 -> V_41 = 0xfff ;
V_4 -> V_42 = & V_43 ;
V_4 -> V_48 = F_9 ;
V_4 -> V_45 = V_49 ;
V_21 = F_16 ( V_4 ) ;
if ( V_21 )
return V_21 ;
V_4 = & V_2 -> V_36 [ 2 ] ;
V_21 = F_17 ( V_2 , V_4 , NULL , 0x00 ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_18 ( struct V_32 * V_2 ,
const struct V_50 * V_51 )
{
return F_19 ( V_2 , & V_52 ,
V_51 -> V_53 ) ;
}

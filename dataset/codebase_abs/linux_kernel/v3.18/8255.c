static int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , unsigned long V_6 )
{
if ( V_3 ) {
F_2 ( V_5 , V_2 -> V_7 + V_6 + V_4 ) ;
return 0 ;
}
return F_3 ( V_2 -> V_7 + V_6 + V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_3 , int V_4 , int V_5 , unsigned long V_6 )
{
if ( V_3 ) {
F_5 ( V_5 , V_2 -> V_8 + V_6 + V_4 ) ;
return 0 ;
}
return F_6 ( V_2 -> V_8 + V_6 + V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
unsigned int * V_5 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
unsigned long V_6 = V_14 -> V_6 ;
unsigned int V_16 ;
unsigned int V_17 ;
V_16 = F_8 ( V_10 , V_5 ) ;
if ( V_16 ) {
if ( V_16 & 0xff )
V_14 -> V_18 ( V_2 , 1 , V_19 ,
V_10 -> V_20 & 0xff , V_6 ) ;
if ( V_16 & 0xff00 )
V_14 -> V_18 ( V_2 , 1 , V_21 ,
( V_10 -> V_20 >> 8 ) & 0xff , V_6 ) ;
if ( V_16 & 0xff0000 )
V_14 -> V_18 ( V_2 , 1 , V_22 ,
( V_10 -> V_20 >> 16 ) & 0xff , V_6 ) ;
}
V_17 = V_14 -> V_18 ( V_2 , 0 , V_19 , 0 , V_6 ) ;
V_17 |= ( V_14 -> V_18 ( V_2 , 0 , V_21 , 0 , V_6 ) << 8 ) ;
V_17 |= ( V_14 -> V_18 ( V_2 , 0 , V_22 , 0 , V_6 ) << 16 ) ;
V_5 [ 1 ] = V_17 ;
return V_12 -> V_23 ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_13 * V_14 = V_10 -> V_15 ;
unsigned long V_6 = V_14 -> V_6 ;
int V_24 ;
V_24 = V_25 ;
if ( ! ( V_10 -> V_26 & 0x0000ff ) )
V_24 |= V_27 ;
if ( ! ( V_10 -> V_26 & 0x00ff00 ) )
V_24 |= V_28 ;
if ( ! ( V_10 -> V_26 & 0x0f0000 ) )
V_24 |= V_29 ;
if ( ! ( V_10 -> V_26 & 0xf00000 ) )
V_24 |= V_30 ;
V_14 -> V_18 ( V_2 , 1 , V_31 , V_24 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_11 * V_12 ,
unsigned int * V_5 )
{
unsigned int V_32 = F_11 ( V_12 -> V_33 ) ;
unsigned int V_16 ;
int V_34 ;
if ( V_32 < 8 )
V_16 = 0x0000ff ;
else if ( V_32 < 16 )
V_16 = 0x00ff00 ;
else if ( V_32 < 20 )
V_16 = 0x0f0000 ;
else
V_16 = 0xf00000 ;
V_34 = F_12 ( V_2 , V_10 , V_12 , V_5 , V_16 ) ;
if ( V_34 )
return V_34 ;
F_9 ( V_2 , V_10 ) ;
return V_12 -> V_23 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
int (* V_18)( struct V_1 * ,
int , int , int , unsigned long ) ,
unsigned long V_6 ,
bool V_35 )
{
struct V_13 * V_14 ;
V_14 = F_14 ( V_10 , sizeof( * V_14 ) ) ;
if ( ! V_14 )
return - V_36 ;
if ( V_18 )
V_14 -> V_18 = V_18 ;
else if ( V_35 )
V_14 -> V_18 = F_4 ;
else
V_14 -> V_18 = F_1 ;
V_14 -> V_6 = V_6 ;
V_10 -> type = V_37 ;
V_10 -> V_38 = V_39 | V_40 ;
V_10 -> V_41 = 24 ;
V_10 -> V_42 = & V_43 ;
V_10 -> V_44 = 1 ;
V_10 -> V_45 = F_7 ;
V_10 -> V_46 = F_10 ;
F_9 ( V_2 , V_10 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int (* V_18)( struct V_1 * ,
int , int , int , unsigned long ) ,
unsigned long V_6 )
{
return F_13 ( V_2 , V_10 , V_18 , V_6 , false ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int (* V_18)( struct V_1 * ,
int , int , int , unsigned long ) ,
unsigned long V_6 )
{
return F_13 ( V_2 , V_10 , V_18 , V_6 , true ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_9 * V_10 ;
unsigned long V_7 ;
int V_34 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
V_7 = V_48 -> V_51 [ V_49 ] ;
if ( ! V_7 )
break;
}
if ( V_49 == 0 ) {
F_18 ( V_2 -> V_52 , L_1 ) ;
return - V_53 ;
}
V_34 = F_19 ( V_2 , V_49 ) ;
if ( V_34 )
return V_34 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_54 ; V_49 ++ ) {
V_10 = & V_2 -> V_55 [ V_49 ] ;
V_7 = V_48 -> V_51 [ V_49 ] ;
V_34 = F_20 ( V_2 , V_7 , V_56 ) ;
if ( V_34 ) {
V_10 -> type = V_57 ;
} else {
V_34 = F_15 ( V_2 , V_10 , NULL , V_7 ) ;
if ( V_34 )
return V_34 ;
}
}
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
struct V_13 * V_14 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_2 -> V_54 ; V_49 ++ ) {
V_10 = & V_2 -> V_55 [ V_49 ] ;
if ( V_10 -> type != V_57 ) {
V_14 = V_10 -> V_15 ;
F_22 ( V_14 -> V_6 , V_56 ) ;
}
}
}

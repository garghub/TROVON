static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_4 -> V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_4 -> V_6 , V_7 , V_4 -> V_8 [ 0 ] ) ;
F_5 ( V_4 -> V_6 , V_9 , V_4 -> V_8 [ 1 ] ) ;
F_6 ( & V_4 -> V_5 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 = V_2 -> V_11 & 0xf ;
int V_12 = V_2 -> V_11 >> 4 ;
V_4 -> V_8 [ V_12 ] &= ~ F_8 ( V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_10 = V_2 -> V_11 & 0xf ;
int V_12 = V_2 -> V_11 >> 4 ;
V_4 -> V_8 [ V_12 ] |= F_8 ( V_10 ) ;
}
static int F_10 ( struct V_1 * V_1 , unsigned int V_13 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
int V_10 = V_1 -> V_11 & 0xf ;
int V_12 = V_1 -> V_11 >> 4 ;
if ( V_13 )
V_4 -> V_14 [ V_12 ] |= F_8 ( V_10 ) ;
else
V_4 -> V_14 [ V_12 ] &= ~ F_8 ( V_10 ) ;
return 0 ;
}
static void F_11 ( struct V_3 * V_4 , int V_12 ,
int V_15 )
{
unsigned int V_16 ;
int V_17 , V_18 , V_19 ;
V_19 = F_12 ( V_4 -> V_6 , V_12 , & V_16 ) ;
if ( V_19 ) {
F_13 ( V_4 -> V_20 , L_1 , V_19 ) ;
return;
}
for ( V_17 = 0 ; V_17 < 16 ; V_17 ++ ) {
if ( V_16 & F_8 ( V_17 ) ) {
V_18 = F_14 ( V_4 -> V_21 , V_15 + V_17 ) ;
if ( V_18 )
F_15 ( V_18 ) ;
}
}
F_5 ( V_4 -> V_6 , V_12 , V_16 ) ;
}
static T_1 F_16 ( int V_18 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_11 ( V_4 , V_22 , 0 ) ;
F_11 ( V_4 , V_23 , 16 ) ;
return V_24 ;
}
static int F_17 ( struct V_21 * V_25 , unsigned int V_18 ,
T_2 V_26 )
{
struct V_3 * V_4 = V_25 -> V_27 ;
F_18 ( V_18 , V_4 ) ;
F_19 ( V_18 , & V_28 , V_29 ) ;
F_20 ( V_18 , 1 ) ;
F_21 ( V_18 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 )
{
int V_19 ;
F_23 ( & V_4 -> V_5 ) ;
F_5 ( V_4 -> V_6 , V_7 , 0x0 ) ;
F_5 ( V_4 -> V_6 , V_9 , 0x0 ) ;
V_4 -> V_21 = F_24 ( V_4 -> V_20 -> V_30 ,
V_31 , & V_32 , V_4 ) ;
if ( ! V_4 -> V_21 ) {
F_13 ( V_4 -> V_20 , L_2 ) ;
return - V_33 ;
}
V_19 = F_25 ( V_4 -> V_20 , V_4 -> V_18 , NULL ,
F_16 , V_34 , L_3 , V_4 ) ;
if ( V_19 ) {
F_13 ( V_4 -> V_20 , L_4 ,
V_4 -> V_18 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int F_26 ( struct V_35 * V_20 )
{
struct V_3 * V_36 = F_27 ( V_20 ) ;
F_5 ( V_36 -> V_6 , V_7 , V_36 -> V_14 [ 0 ] ) ;
F_5 ( V_36 -> V_6 , V_9 , V_36 -> V_14 [ 1 ] ) ;
F_28 ( V_36 -> V_18 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_20 )
{
struct V_3 * V_36 = F_27 ( V_20 ) ;
F_5 ( V_36 -> V_6 , V_7 , V_36 -> V_8 [ 0 ] ) ;
F_5 ( V_36 -> V_6 , V_9 , V_36 -> V_8 [ 1 ] ) ;
F_30 ( V_36 -> V_18 ) ;
return 0 ;
}
static int F_31 ( struct V_37 * V_38 )
{
int V_19 ;
struct V_3 * V_4 ;
V_4 = F_32 ( & V_38 -> V_20 , sizeof( * V_4 ) , V_39 ) ;
if ( ! V_4 )
return - V_33 ;
V_4 -> V_20 = & V_38 -> V_20 ;
V_4 -> V_6 = F_33 ( V_38 -> V_20 . V_40 , NULL ) ;
if ( ! V_4 -> V_6 )
return - V_41 ;
F_34 ( V_38 , V_4 ) ;
V_4 -> V_18 = F_35 ( V_38 , 0 ) ;
if ( V_4 -> V_18 > 0 ) {
V_19 = F_22 ( V_4 ) ;
if ( V_19 )
return V_19 ;
}
V_19 = F_36 ( & V_38 -> V_20 , - 1 , V_42 ,
F_37 ( V_42 ) , NULL , 0 , NULL ) ;
if ( V_19 )
F_13 ( & V_38 -> V_20 , L_5 , V_19 ) ;
return V_19 ;
}
static int F_38 ( struct V_37 * V_38 )
{
F_39 ( & V_38 -> V_20 ) ;
return 0 ;
}

static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
F_5 ( V_4 -> V_7 , V_8 , V_4 -> V_9 [ 0 ] ) ;
F_5 ( V_4 -> V_7 , V_10 , V_4 -> V_9 [ 1 ] ) ;
F_6 ( & V_4 -> V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_11 = V_2 -> V_12 & 0xf ;
int V_13 = V_2 -> V_12 >> 4 ;
V_4 -> V_9 [ V_13 ] &= ~ F_8 ( V_11 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
int V_11 = V_2 -> V_12 & 0xf ;
int V_13 = V_2 -> V_12 >> 4 ;
V_4 -> V_9 [ V_13 ] |= F_8 ( V_11 ) ;
}
static void F_10 ( struct V_3 * V_4 , int V_13 ,
int V_14 )
{
unsigned int V_15 ;
int V_16 , V_5 , V_17 ;
V_17 = F_11 ( V_4 -> V_7 , V_13 , & V_15 ) ;
if ( V_17 ) {
F_12 ( V_4 -> V_18 , L_1 , V_17 ) ;
return;
}
for ( V_16 = 0 ; V_16 < 16 ; V_16 ++ ) {
if ( V_15 & F_8 ( V_16 ) ) {
V_5 = F_13 ( V_4 -> V_19 , V_14 + V_16 ) ;
if ( V_5 )
F_14 ( V_5 ) ;
}
}
F_5 ( V_4 -> V_7 , V_13 , V_15 ) ;
}
static T_1 F_15 ( int V_5 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_10 ( V_4 , V_20 , 0 ) ;
F_10 ( V_4 , V_21 , 16 ) ;
return V_22 ;
}
static int F_16 ( struct V_19 * V_23 , unsigned int V_5 ,
T_2 V_24 )
{
struct V_3 * V_4 = V_23 -> V_25 ;
F_17 ( V_5 , V_4 ) ;
F_18 ( V_5 , & V_26 , V_27 ) ;
F_19 ( V_5 , 1 ) ;
#ifdef F_20
F_21 ( V_5 , V_28 ) ;
#else
F_22 ( V_5 ) ;
#endif
return 0 ;
}
static int F_23 ( struct V_3 * V_4 )
{
int V_17 ;
F_24 ( & V_4 -> V_6 ) ;
F_5 ( V_4 -> V_7 , V_8 , 0x0 ) ;
F_5 ( V_4 -> V_7 , V_10 , 0x0 ) ;
V_4 -> V_19 = F_25 ( V_4 -> V_18 -> V_29 ,
V_30 , & V_31 , V_4 ) ;
if ( ! V_4 -> V_19 ) {
F_12 ( V_4 -> V_18 , L_2 ) ;
return - V_32 ;
}
V_17 = F_26 ( V_4 -> V_18 , V_4 -> V_5 , NULL ,
F_15 , V_33 , L_3 , V_4 ) ;
if ( V_17 ) {
F_12 ( V_4 -> V_18 , L_4 ,
V_4 -> V_5 , V_17 ) ;
return V_17 ;
}
return 0 ;
}
static int F_27 ( struct V_34 * V_35 )
{
int V_17 ;
struct V_3 * V_4 ;
V_4 = F_28 ( & V_35 -> V_18 , sizeof( * V_4 ) , V_36 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_18 = & V_35 -> V_18 ;
V_4 -> V_7 = F_29 ( V_35 -> V_18 . V_37 , NULL ) ;
if ( ! V_4 -> V_7 )
return - V_38 ;
F_30 ( V_35 , V_4 ) ;
V_4 -> V_5 = F_31 ( V_35 , 0 ) ;
if ( V_4 -> V_5 > 0 ) {
V_17 = F_23 ( V_4 ) ;
if ( V_17 )
return V_17 ;
}
V_17 = F_32 ( & V_35 -> V_18 , - 1 , V_39 ,
F_33 ( V_39 ) , NULL , 0 , NULL ) ;
if ( V_17 )
F_12 ( & V_35 -> V_18 , L_5 , V_17 ) ;
return V_17 ;
}
static int F_34 ( struct V_34 * V_35 )
{
F_35 ( & V_35 -> V_18 ) ;
return 0 ;
}

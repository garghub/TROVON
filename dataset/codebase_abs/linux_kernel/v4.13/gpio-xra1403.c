static unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return V_1 + ( V_2 > 7 ) ;
}
static int F_2 ( struct V_3 * V_4 , unsigned int V_2 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return F_4 ( V_6 -> V_7 , F_1 ( V_8 , V_2 ) ,
F_5 ( V_2 % 8 ) , F_5 ( V_2 % 8 ) ) ;
}
static int F_6 ( struct V_3 * V_4 , unsigned int V_2 ,
int V_9 )
{
int V_10 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_10 = F_4 ( V_6 -> V_7 , F_1 ( V_8 , V_2 ) ,
F_5 ( V_2 % 8 ) , 0 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_4 ( V_6 -> V_7 , F_1 ( V_11 , V_2 ) ,
F_5 ( V_2 % 8 ) , V_9 ? F_5 ( V_2 % 8 ) : 0 ) ;
return V_10 ;
}
static int F_7 ( struct V_3 * V_4 , unsigned int V_2 )
{
int V_10 ;
unsigned int V_12 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_10 = F_8 ( V_6 -> V_7 , F_1 ( V_8 , V_2 ) , & V_12 ) ;
if ( V_10 )
return V_10 ;
return ! ! ( V_12 & F_5 ( V_2 % 8 ) ) ;
}
static int F_9 ( struct V_3 * V_4 , unsigned int V_2 )
{
int V_10 ;
unsigned int V_12 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_10 = F_8 ( V_6 -> V_7 , F_1 ( V_13 , V_2 ) , & V_12 ) ;
if ( V_10 )
return V_10 ;
return ! ! ( V_12 & F_5 ( V_2 % 8 ) ) ;
}
static void F_10 ( struct V_3 * V_4 , unsigned int V_2 , int V_9 )
{
int V_10 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_10 = F_4 ( V_6 -> V_7 , F_1 ( V_11 , V_2 ) ,
F_5 ( V_2 % 8 ) , V_9 ? F_5 ( V_2 % 8 ) : 0 ) ;
if ( V_10 )
F_11 ( V_4 -> V_14 , L_1 ,
V_2 , V_10 ) ;
}
static void F_12 ( struct V_15 * V_16 , struct V_3 * V_4 )
{
int V_1 ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_9 [ V_17 . V_18 ] ;
int V_19 ;
unsigned int V_20 ;
unsigned int V_21 ;
F_13 ( V_16 , L_2 ) ;
for ( V_1 = 0 ; V_1 <= V_17 . V_18 ; V_1 ++ )
F_14 ( V_16 , L_3 , V_1 ) ;
F_13 ( V_16 , L_4 ) ;
for ( V_1 = 0 ; V_1 < V_17 . V_18 ; V_1 ++ ) {
F_8 ( V_6 -> V_7 , V_1 , & V_9 [ V_1 ] ) ;
F_14 ( V_16 , L_3 , V_9 [ V_1 ] ) ;
}
F_13 ( V_16 , L_5 ) ;
V_20 = V_9 [ V_8 + 1 ] << 8 | V_9 [ V_8 ] ;
V_21 = V_9 [ V_13 + 1 ] << 8 | V_9 [ V_13 ] ;
for ( V_19 = 0 ; V_19 < V_4 -> V_22 ; V_19 ++ ) {
const char * V_23 = F_15 ( V_4 , V_19 ) ;
if ( ! V_23 )
continue;
F_14 ( V_16 , L_6 ,
V_4 -> V_24 + V_19 , V_23 ,
( V_20 & F_5 ( V_19 ) ) ? L_7 : L_8 ,
( V_21 & F_5 ( V_19 ) ) ? L_9 : L_10 ) ;
}
}
static int F_16 ( struct V_25 * V_26 )
{
struct V_5 * V_6 ;
struct V_27 * V_28 ;
int V_10 ;
V_6 = F_17 ( & V_26 -> V_29 , sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 )
return - V_31 ;
V_28 = F_18 ( & V_26 -> V_29 , L_11 , V_32 ) ;
if ( F_19 ( V_28 ) )
F_20 ( & V_26 -> V_29 , L_12 ) ;
V_6 -> V_4 . V_33 = F_2 ;
V_6 -> V_4 . V_34 = F_6 ;
V_6 -> V_4 . V_35 = F_7 ;
V_6 -> V_4 . V_36 = F_9 ;
V_6 -> V_4 . V_37 = F_10 ;
V_6 -> V_4 . V_38 = F_12 ;
V_6 -> V_4 . V_22 = 16 ;
V_6 -> V_4 . V_23 = L_13 ;
V_6 -> V_4 . V_24 = - 1 ;
V_6 -> V_4 . V_39 = true ;
V_6 -> V_4 . V_14 = & V_26 -> V_29 ;
V_6 -> V_4 . V_40 = V_41 ;
V_6 -> V_7 = F_21 ( V_26 , & V_17 ) ;
if ( F_19 ( V_6 -> V_7 ) ) {
V_10 = F_22 ( V_6 -> V_7 ) ;
F_11 ( & V_26 -> V_29 , L_14 , V_10 ) ;
return V_10 ;
}
V_10 = F_23 ( & V_26 -> V_29 , & V_6 -> V_4 , V_6 ) ;
if ( V_10 < 0 ) {
F_11 ( & V_26 -> V_29 , L_15 ) ;
return V_10 ;
}
F_24 ( V_26 , V_6 ) ;
return 0 ;
}

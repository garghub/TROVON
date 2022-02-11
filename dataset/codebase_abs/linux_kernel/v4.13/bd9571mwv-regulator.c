static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , V_6 , & V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
return V_3 & V_7 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
int V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_4 ( V_2 -> V_5 , F_5 ( V_4 ) ,
V_2 -> V_9 -> V_10 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
int V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_4 = F_2 ( V_2 -> V_5 , F_5 ( V_4 ) , & V_3 ) ;
if ( V_4 != 0 )
return V_4 ;
V_3 &= V_2 -> V_9 -> V_10 ;
V_3 >>= F_7 ( V_2 -> V_9 -> V_10 ) - 1 ;
return V_3 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_8 )
{
return F_4 ( V_2 -> V_5 , V_11 ,
V_2 -> V_9 -> V_10 , V_8 ) ;
}
static int F_9 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_10 ( V_13 -> V_16 . V_17 ) ;
struct V_18 V_19 = { } ;
struct V_1 * V_2 ;
int V_20 ;
F_11 ( V_13 , V_15 ) ;
V_19 . V_16 = & V_13 -> V_16 ;
V_19 . V_16 -> V_21 = V_15 -> V_16 -> V_21 ;
V_19 . V_22 = V_15 ;
V_19 . V_5 = V_15 -> V_5 ;
for ( V_20 = 0 ; V_20 < F_12 ( V_23 ) ; V_20 ++ ) {
V_2 = F_13 ( & V_13 -> V_16 , & V_23 [ V_20 ] ,
& V_19 ) ;
if ( F_14 ( V_2 ) ) {
F_15 ( V_15 -> V_16 , L_1 ,
V_13 -> V_24 ) ;
return F_16 ( V_2 ) ;
}
}
return 0 ;
}

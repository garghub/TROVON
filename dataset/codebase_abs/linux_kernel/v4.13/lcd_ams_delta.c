static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == V_4 ) {
if ( ! ( V_5 & V_6 ) ) {
F_2 ( V_5 & V_7 ,
V_8 ) ;
F_2 ( 1 , V_9 ) ;
V_5 |= V_6 ;
}
} else {
if ( V_5 & V_6 ) {
F_2 ( 0 , V_8 ) ;
F_2 ( 0 , V_9 ) ;
V_5 &= ~ V_6 ;
}
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_10 )
{
if ( ( V_10 >= 0 ) && ( V_10 <= V_7 ) ) {
F_2 ( V_10 , V_8 ) ;
V_5 &= ~ V_7 ;
V_5 |= V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
if ( V_5 & V_6 )
return V_4 ;
else
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( ! ( V_5 & V_6 ) )
return 0 ;
return V_5 & V_7 ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
return F_7 ( V_16 , F_8 ( V_16 ) ) ;
}
static void F_9 ( struct V_12 * V_13 )
{
F_10 ( V_16 , F_8 ( V_16 ) ) ;
}
static int F_11 ( struct V_12 * V_13 )
{
F_12 ( V_17 , 1 ) ;
F_12 ( V_18 , 1 ) ;
return 0 ;
}
static void F_13 ( struct V_12 * V_13 )
{
F_12 ( V_18 , 0 ) ;
F_12 ( V_17 , 0 ) ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = NULL ;
#ifdef F_15
int V_21 ;
V_1 = F_16 ( L_1 , & V_20 -> V_2 , NULL ,
& V_22 ) ;
if ( F_17 ( V_1 ) ) {
V_21 = F_18 ( V_1 ) ;
F_19 ( & V_20 -> V_2 , L_2 ) ;
return V_21 ;
}
F_20 ( V_20 , V_1 ) ;
V_1 -> V_23 . V_24 = V_7 ;
#endif
F_3 ( V_1 , V_25 ) ;
F_1 ( V_1 , V_4 ) ;
F_21 ( & V_26 ) ;
return 0 ;
}

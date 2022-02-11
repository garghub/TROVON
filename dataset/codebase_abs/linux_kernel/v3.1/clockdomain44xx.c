static int F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
F_2 ( ( 1 << V_3 -> V_4 ) ,
V_2 -> V_5 ,
V_2 -> V_6 , V_2 -> V_7 +
V_8 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
F_4 ( ( 1 << V_3 -> V_4 ) ,
V_2 -> V_5 ,
V_2 -> V_6 , V_2 -> V_7 +
V_8 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_1 * V_3 )
{
return F_6 ( V_2 -> V_5 ,
V_2 -> V_6 , V_2 -> V_7 +
V_8 ,
( 1 << V_3 -> V_4 ) ) ;
}
static int F_7 ( struct V_1 * V_9 )
{
struct V_10 * V_11 ;
T_1 V_12 = 0 ;
for ( V_11 = V_9 -> V_13 ; V_11 && V_11 -> V_14 ; V_11 ++ ) {
if ( ! F_8 ( V_11 -> V_15 ) )
continue;
if ( ! V_11 -> V_9 )
continue;
V_12 |= 1 << V_11 -> V_9 -> V_4 ;
F_9 ( & V_11 -> V_16 , 0 ) ;
}
F_4 ( V_12 , V_9 -> V_5 ,
V_9 -> V_6 , V_9 -> V_7 +
V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_9 )
{
F_11 ( V_9 -> V_5 ,
V_9 -> V_6 , V_9 -> V_7 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_9 )
{
F_13 ( V_9 -> V_5 ,
V_9 -> V_6 , V_9 -> V_7 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_9 )
{
F_15 ( V_9 -> V_5 ,
V_9 -> V_6 , V_9 -> V_7 ) ;
}
static void F_16 ( struct V_1 * V_9 )
{
F_17 ( V_9 -> V_5 ,
V_9 -> V_6 , V_9 -> V_7 ) ;
}
static int F_18 ( struct V_1 * V_9 )
{
if ( V_9 -> V_17 & V_18 )
return F_12 ( V_9 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_9 )
{
bool V_19 = false ;
V_19 = F_20 ( V_9 -> V_5 ,
V_9 -> V_6 , V_9 -> V_7 ) ;
if ( ! V_19 && ( V_9 -> V_17 & V_20 ) )
F_10 ( V_9 ) ;
return 0 ;
}

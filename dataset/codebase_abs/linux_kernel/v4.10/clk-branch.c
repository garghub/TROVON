static bool F_1 ( const struct V_1 * V_2 )
{
T_1 V_3 ;
if ( ! V_2 -> V_4 )
return 0 ;
F_2 ( V_2 -> V_5 . V_6 , V_2 -> V_4 , & V_3 ) ;
return ! ! ( V_3 & F_3 ( V_2 -> V_7 ) ) ;
}
static bool F_4 ( const struct V_1 * V_2 , bool V_8 )
{
bool V_9 = ( V_2 -> V_10 == V_11 ) ;
T_1 V_3 ;
F_2 ( V_2 -> V_5 . V_6 , V_2 -> V_12 , & V_3 ) ;
V_3 &= F_3 ( V_2 -> V_13 ) ;
if ( V_9 )
V_3 = ! V_3 ;
return ! ! V_3 == ! V_8 ;
}
static bool F_5 ( const struct V_1 * V_2 , bool V_8 )
{
T_1 V_3 ;
T_1 V_14 ;
V_14 = V_15 << V_16 ;
V_14 |= V_17 ;
F_2 ( V_2 -> V_5 . V_6 , V_2 -> V_12 , & V_3 ) ;
if ( V_8 ) {
V_3 &= V_14 ;
return ( V_3 & V_17 ) == 0 ||
V_3 == V_18 ;
} else {
return V_3 & V_17 ;
}
}
static int F_6 ( const struct V_1 * V_2 , bool V_8 ,
bool (F_7)( const struct V_1 * , bool ) )
{
bool V_19 = V_2 -> V_10 & V_20 ;
const char * V_21 = F_8 ( & V_2 -> V_5 . V_22 ) ;
if ( F_1 ( V_2 ) )
return 0 ;
if ( V_2 -> V_10 == V_23 || ( ! V_8 && V_19 ) ) {
F_9 ( 10 ) ;
} else if ( V_2 -> V_10 == V_11 ||
V_2 -> V_10 == V_24 ||
( V_8 && V_19 ) ) {
int V_25 = 200 ;
while ( V_25 -- > 0 ) {
if ( F_7 ( V_2 , V_8 ) )
return 0 ;
F_9 ( 1 ) ;
}
F_10 ( 1 , L_1 , V_21 ,
V_8 ? L_2 : L_3 ) ;
return - V_26 ;
}
return 0 ;
}
static int F_11 ( struct V_27 * V_22 , bool V_28 ,
bool (F_7)( const struct V_1 * , bool ) )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
int V_29 ;
if ( V_28 ) {
V_29 = F_13 ( V_22 ) ;
if ( V_29 )
return V_29 ;
} else {
F_14 ( V_22 ) ;
}
return F_6 ( V_2 , V_28 , F_7 ) ;
}
static int F_15 ( struct V_27 * V_22 )
{
return F_11 ( V_22 , true , F_4 ) ;
}
static void F_16 ( struct V_27 * V_22 )
{
F_11 ( V_22 , false , F_4 ) ;
}
static int F_17 ( struct V_27 * V_22 )
{
return F_11 ( V_22 , true , F_5 ) ;
}
static void F_18 ( struct V_27 * V_22 )
{
F_11 ( V_22 , false , F_5 ) ;
}

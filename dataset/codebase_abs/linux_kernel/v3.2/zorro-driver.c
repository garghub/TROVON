const struct V_1 *
F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
while ( V_2 -> V_5 ) {
if ( V_2 -> V_5 == V_6 || V_2 -> V_5 == V_4 -> V_5 )
return V_2 ;
V_2 ++ ;
}
return NULL ;
}
static int F_2 ( struct V_7 * V_8 )
{
int error = 0 ;
struct V_9 * V_10 = F_3 ( V_8 -> V_11 ) ;
struct V_3 * V_4 = F_4 ( V_8 ) ;
if ( ! V_4 -> V_11 && V_10 -> V_12 ) {
const struct V_1 * V_5 ;
V_5 = F_1 ( V_10 -> V_13 , V_4 ) ;
if ( V_5 )
error = V_10 -> V_12 ( V_4 , V_5 ) ;
if ( error >= 0 ) {
V_4 -> V_11 = V_10 ;
error = 0 ;
}
}
return error ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
struct V_9 * V_10 = F_3 ( V_8 -> V_11 ) ;
if ( V_10 ) {
if ( V_10 -> remove )
V_10 -> remove ( V_4 ) ;
V_4 -> V_11 = NULL ;
}
return 0 ;
}
int F_6 ( struct V_9 * V_10 )
{
V_10 -> V_11 . V_14 = V_10 -> V_14 ;
V_10 -> V_11 . V_15 = & V_16 ;
return F_7 ( & V_10 -> V_11 ) ;
}
void F_8 ( struct V_9 * V_10 )
{
F_9 ( & V_10 -> V_11 ) ;
}
static int F_10 ( struct V_7 * V_8 , struct V_17 * V_10 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
struct V_9 * V_18 = F_3 ( V_10 ) ;
const struct V_1 * V_2 = V_18 -> V_13 ;
if ( ! V_2 )
return 0 ;
while ( V_2 -> V_5 ) {
if ( V_2 -> V_5 == V_6 || V_2 -> V_5 == V_4 -> V_5 )
return 1 ;
V_2 ++ ;
}
return 0 ;
}
static int F_11 ( struct V_7 * V_8 , struct V_19 * V_20 )
{
#ifdef F_12
struct V_3 * V_4 ;
if ( ! V_8 )
return - V_21 ;
V_4 = F_4 ( V_8 ) ;
if ( ! V_4 )
return - V_21 ;
if ( F_13 ( V_20 , L_1 , V_4 -> V_5 ) ||
F_13 ( V_20 , L_2 , F_14 ( V_8 ) ) ||
F_13 ( V_20 , L_3 , V_4 -> V_22 ) ||
F_13 ( V_20 , L_4 V_23 , V_4 -> V_5 ) )
return - V_24 ;
return 0 ;
#else
return - V_21 ;
#endif
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_16 ) ;
}

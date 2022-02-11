const struct V_1 *
F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
while ( V_2 -> V_5 ) {
if ( V_2 -> V_5 == V_6 )
return V_2 ;
if ( F_2 ( V_2 -> V_5 & 0xff ) ) {
if ( V_2 -> V_5 == V_4 -> V_5 )
return V_2 ;
} else {
if ( ( V_2 -> V_5 & 0xff ) == ( V_4 -> V_5 & 0xff ) )
return V_2 ;
}
V_2 ++ ;
}
return NULL ;
}
static int F_3 ( struct V_7 * V_8 )
{
int error = 0 ;
struct V_9 * V_10 = F_4 ( V_8 -> V_11 ) ;
struct V_3 * V_4 = F_5 ( V_8 ) ;
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
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_18 = F_4 ( V_10 ) ;
const struct V_1 * V_2 = V_18 -> V_13 ;
if ( ! V_2 )
return 0 ;
return F_1 ( V_2 , V_4 ) ? 1 : 0 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_16 ) ;
}

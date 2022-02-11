int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 ) ;
}
const struct V_4 * F_5 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
const struct V_4 * V_7 = V_2 -> V_8 ;
if ( V_7 ) {
while ( V_7 -> V_9 [ 0 ] || V_7 -> V_10 [ 0 ] ) {
if ( strcmp ( V_6 -> V_9 , V_7 -> V_9 ) == 0 &&
strcmp ( V_6 -> V_10 , V_7 -> V_10 ) == 0 )
return V_7 ;
V_7 ++ ;
}
}
return NULL ;
}
static int F_6 ( struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_5 * V_6 = F_7 ( V_12 ) ;
struct V_1 * V_2 = F_8 ( V_14 ) ;
const struct V_4 * V_7 ;
V_7 = F_5 ( V_2 , V_6 ) ;
if ( V_7 )
return 1 ;
return 0 ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_15 ) ;
}

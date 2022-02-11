struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ? F_2 ( V_3 -> V_4 ) : NULL ;
}
int F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_6 ;
if ( ! V_5 )
return - V_7 ;
V_6 = F_4 ( V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_5 ( V_5 , V_3 -> V_8 ) ;
if ( V_6 < 0 )
F_6 ( V_5 ) ;
else
V_3 -> V_9 = true ;
return V_6 ;
}
void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_5 && V_3 -> V_9 ) {
F_8 ( V_5 ) ;
F_6 ( V_5 ) ;
}
V_3 -> V_9 = false ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( ! V_5 || ! V_3 -> V_9 )
return;
if ( V_3 -> V_10 ) {
F_10 ( V_3 -> V_10 , V_3 ) ;
V_3 -> V_10 = 0 ;
}
if ( V_3 -> V_11 ) {
F_11 ( V_3 -> V_11 ) ;
V_3 -> V_11 = NULL ;
}
F_7 ( V_3 ) ;
}
int F_12 ( struct V_1 * V_5 ,
struct V_12 * V_13 ,
unsigned long V_14 )
{
return F_13 ( & V_5 -> V_3 , V_13 , V_14 ) ;
}
void F_14 ( struct V_1 * V_5 )
{
F_15 ( & V_5 -> V_3 ) ;
}
int F_16 ( struct V_12 * V_12 ,
struct V_15 * V_15 )
{
int V_16 ;
V_16 = F_17 ( V_12 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_18 ( V_15 ) ;
if ( V_16 < 0 ) {
F_19 ( V_12 ) ;
return V_16 ;
}
return 0 ;
}
void F_20 ( struct V_12 * V_12 ,
struct V_15 * V_15 )
{
F_21 ( V_15 ) ;
F_19 ( V_12 ) ;
}
static int T_1 F_22 ( void )
{
return 0 ;
}
static void T_2 F_23 ( void )
{
}

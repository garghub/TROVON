static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( V_4 , V_5 [ V_3 ] . V_6 * 1000 ) ;
}
static unsigned int F_3 ( unsigned int V_7 )
{
int V_8 = 0 ;
unsigned long V_9 = F_4 ( V_4 ) / 1000 ;
while ( V_5 [ V_8 + 1 ] . V_6 != V_10 ) {
if ( V_9 < V_5 [ V_8 ] . V_6 +
( V_5 [ V_8 + 1 ] . V_6 - V_5 [ V_8 ] . V_6 ) / 2 )
return V_5 [ V_8 ] . V_6 ;
V_8 ++ ;
}
return V_5 [ V_8 ] . V_6 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 , V_5 , 20 * 1000 ) ;
}
static int F_7 ( struct V_11 * V_12 )
{
int V_8 = 0 ;
V_5 = F_8 ( & V_12 -> V_13 ) ;
if ( ! V_5 ) {
F_9 ( L_1 ) ;
return - V_14 ;
}
V_4 = F_10 ( & V_12 -> V_13 , L_2 ) ;
if ( F_11 ( V_4 ) ) {
F_9 ( L_3 ) ;
return F_12 ( V_4 ) ;
}
F_13 ( L_4 ) ;
while ( V_5 [ V_8 ] . V_6 != V_10 ) {
F_13 ( L_5 , V_5 [ V_8 ] . V_6 / 1000 ) ;
V_8 ++ ;
}
return F_14 ( & V_15 ) ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_16 ) ;
}

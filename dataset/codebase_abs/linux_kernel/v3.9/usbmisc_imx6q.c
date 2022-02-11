static struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 , V_5 ;
for ( V_4 = 0 ; V_4 < V_6 ; V_4 ++ ) {
if ( V_7 -> V_8 [ V_4 ] . V_3 == V_3 )
return & V_7 -> V_8 [ V_4 ] ;
else if ( ! V_7 -> V_8 [ V_4 ] . V_3 )
break;
}
if ( V_4 >= V_6 )
return F_2 ( - V_9 ) ;
V_5 = F_3 ( V_3 , & V_7 -> V_8 [ V_4 ] ) ;
if ( V_5 )
return F_2 ( V_5 ) ;
return & V_7 -> V_8 [ V_4 ] ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_8 ;
unsigned long V_10 ;
T_1 V_11 ;
V_8 = F_1 ( V_3 ) ;
if ( F_5 ( V_8 ) )
return F_6 ( V_8 ) ;
if ( V_8 -> V_12 ) {
F_7 ( & V_7 -> V_13 , V_10 ) ;
V_11 = F_8 ( V_7 -> V_14 + V_8 -> V_15 * 4 ) ;
F_9 ( V_11 | V_16 ,
V_7 -> V_14 + V_8 -> V_15 * 4 ) ;
F_10 ( & V_7 -> V_13 , V_10 ) ;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 ;
int V_5 ;
if ( V_7 )
return - V_9 ;
V_22 = F_12 ( & V_18 -> V_3 , sizeof( * V_22 ) , V_23 ) ;
if ( ! V_22 )
return - V_24 ;
F_13 ( & V_22 -> V_13 ) ;
V_20 = F_14 ( V_18 , V_25 , 0 ) ;
V_22 -> V_14 = F_15 ( & V_18 -> V_3 , V_20 ) ;
if ( F_5 ( V_22 -> V_14 ) )
return F_6 ( V_22 -> V_14 ) ;
V_22 -> V_26 = F_16 ( & V_18 -> V_3 , NULL ) ;
if ( F_5 ( V_22 -> V_26 ) ) {
F_17 ( & V_18 -> V_3 ,
L_1 , F_6 ( V_22 -> V_26 ) ) ;
return F_6 ( V_22 -> V_26 ) ;
}
V_5 = F_18 ( V_22 -> V_26 ) ;
if ( V_5 ) {
F_17 ( & V_18 -> V_3 ,
L_2 , V_5 ) ;
return V_5 ;
}
V_5 = F_19 ( & V_27 ) ;
if ( V_5 ) {
F_20 ( V_22 -> V_26 ) ;
return V_5 ;
}
V_7 = V_22 ;
return 0 ;
}
static int F_21 ( struct V_17 * V_18 )
{
F_22 ( & V_27 ) ;
F_20 ( V_7 -> V_26 ) ;
return 0 ;
}
int T_2 F_23 ( void )
{
return F_24 ( & V_28 ) ;
}
void T_3 F_25 ( void )
{
F_26 ( & V_28 ) ;
}

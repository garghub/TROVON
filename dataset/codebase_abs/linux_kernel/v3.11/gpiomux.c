static void F_1 ( unsigned V_1 , T_1 V_2 )
{
unsigned V_3 = ( V_2 & ~ V_4 ) |
( ( V_1 & 0x3ff ) << 4 ) ;
unsigned V_5 = 0 ;
int V_6 ;
V_6 = F_2 ( V_7 ,
& V_3 , & V_5 ) ;
if ( V_6 )
F_3 ( L_1 ,
V_8 , V_6 , V_3 , V_5 ) ;
}
int F_4 ( unsigned V_1 ,
T_1 V_9 ,
T_1 V_10 )
{
struct V_11 * V_12 = V_13 + V_1 ;
unsigned long V_14 ;
T_1 V_15 ;
if ( V_1 >= V_16 )
return - V_17 ;
F_5 ( & V_18 , V_14 ) ;
if ( V_9 & V_19 )
V_12 -> V_9 = V_9 ;
if ( V_10 & V_19 )
V_12 -> V_10 = V_10 ;
V_15 = V_12 -> V_20 ? V_9 : V_10 ;
if ( V_15 & V_19 )
F_1 ( V_1 , V_15 ) ;
F_6 ( & V_18 , V_14 ) ;
return 0 ;
}
int F_7 ( unsigned V_1 )
{
struct V_11 * V_12 = V_13 + V_1 ;
unsigned long V_14 ;
if ( V_1 >= V_16 )
return - V_17 ;
F_5 ( & V_18 , V_14 ) ;
if ( V_12 -> V_20 ++ == 0 && V_12 -> V_9 & V_19 )
F_1 ( V_1 , V_12 -> V_9 ) ;
F_6 ( & V_18 , V_14 ) ;
return 0 ;
}
int F_8 ( unsigned V_1 )
{
struct V_11 * V_12 = V_13 + V_1 ;
unsigned long V_14 ;
if ( V_1 >= V_16 )
return - V_17 ;
F_5 ( & V_18 , V_14 ) ;
F_9 ( V_12 -> V_20 == 0 ) ;
if ( -- V_12 -> V_20 == 0 && V_12 -> V_10 & V_19 )
F_1 ( V_1 , V_12 -> V_10 ) ;
F_6 ( & V_18 , V_14 ) ;
return 0 ;
}
static int T_2 F_10 ( void )
{
unsigned V_21 ;
for ( V_21 = 0 ; V_21 < V_16 ; ++ V_21 ) {
V_13 [ V_21 ] . V_20 = 0 ;
if ( ! ( V_13 [ V_21 ] . V_10 & V_19 ) )
continue;
F_1 ( V_21 , V_13 [ V_21 ] . V_10 ) ;
}
return 0 ;
}

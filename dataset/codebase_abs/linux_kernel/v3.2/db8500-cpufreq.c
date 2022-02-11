static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_4 ,
unsigned int V_5 )
{
struct V_6 V_7 ;
unsigned int V_8 ;
if ( V_4 < V_2 -> V_9 . V_10 )
V_4 = V_2 -> V_9 . V_10 ;
if ( V_4 > V_2 -> V_9 . V_11 )
V_4 = V_2 -> V_9 . V_11 ;
if ( F_4
( V_2 , V_3 , V_4 , V_5 , & V_8 ) ) {
return - V_12 ;
}
V_7 . V_13 = V_2 -> V_14 ;
V_7 . V_15 = V_3 [ V_8 ] . V_16 ;
if ( V_7 . V_13 == V_7 . V_15 )
return 0 ;
F_5 (freqs.cpu, policy->cpus)
F_6 ( & V_7 , V_17 ) ;
if ( F_7 ( V_18 [ V_8 ] ) ) {
F_8 ( L_1 ) ;
return - V_12 ;
}
F_5 (freqs.cpu, policy->cpus)
F_6 ( & V_7 , V_19 ) ;
return 0 ;
}
static unsigned int F_9 ( unsigned int V_20 )
{
int V_21 ;
for ( V_21 = 0 ; F_10 () != V_18 [ V_21 ] ; V_21 ++ )
;
return V_3 [ V_21 ] . V_16 ;
}
static int T_1 F_11 ( struct V_1 * V_2 )
{
int V_21 , V_22 ;
F_12 ( F_13 ( V_18 ) + 1 != F_13 ( V_3 ) ) ;
if ( ! F_14 () ) {
V_3 [ 1 ] . V_16 = 400000 ;
V_3 [ 2 ] . V_16 = 800000 ;
if ( F_15 () )
V_3 [ 3 ] . V_16 = 1000000 ;
}
F_16 ( L_2 ) ;
for ( V_21 = 0 ; V_3 [ V_21 ] . V_16 != V_23 ; V_21 ++ )
F_16 ( L_3 , V_3 [ V_21 ] . V_16 / 1000 ) ;
V_22 = F_17 ( V_2 , V_3 ) ;
if ( ! V_22 )
F_18 ( V_3 , V_2 -> V_20 ) ;
else {
F_8 ( L_4 ) ;
return V_22 ;
}
V_2 -> V_24 = V_2 -> V_9 . V_10 ;
V_2 -> V_25 = V_2 -> V_9 . V_11 ;
V_2 -> V_14 = F_9 ( V_2 -> V_20 ) ;
V_2 -> V_26 = V_27 ;
V_2 -> V_9 . V_28 = 20 * 1000 ;
F_19 ( V_2 -> V_29 , & V_30 ) ;
V_2 -> V_31 = V_32 ;
return 0 ;
}
static int T_2 F_20 ( void )
{
if ( ! F_21 () )
return - V_33 ;
F_16 ( L_5 ) ;
return F_22 ( & V_34 ) ;
}

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
int V_9 ;
if ( V_4 < V_2 -> V_10 . V_11 )
V_4 = V_2 -> V_10 . V_11 ;
if ( V_4 > V_2 -> V_10 . V_12 )
V_4 = V_2 -> V_10 . V_12 ;
if ( F_4 ( V_2 , V_3 , V_4 ,
V_5 , & V_8 ) )
return - V_13 ;
V_7 . V_14 = V_2 -> V_15 ;
V_7 . V_16 = V_3 [ V_8 ] . V_17 ;
if ( V_7 . V_14 == V_7 . V_16 )
return 0 ;
F_5 (freqs.cpu, policy->cpus)
F_6 ( & V_7 , V_18 ) ;
V_9 = F_7 ( V_19 , V_7 . V_16 * 1000 ) ;
if ( V_9 ) {
F_8 ( L_1 ,
V_7 . V_16 * 1000 , V_9 ) ;
return V_9 ;
}
F_5 (freqs.cpu, policy->cpus)
F_6 ( & V_7 , V_20 ) ;
return 0 ;
}
static unsigned int F_9 ( unsigned int V_21 )
{
int V_22 = 0 ;
unsigned long V_23 = F_10 ( V_19 ) / 1000 ;
while ( V_3 [ V_22 ] . V_17 != V_24 ) {
if ( V_23 <= V_3 [ V_22 ] . V_17 )
return V_3 [ V_22 ] . V_17 ;
V_22 ++ ;
}
F_8 ( L_2 ) ;
return 0 ;
}
static int T_1 F_11 ( struct V_1 * V_2 )
{
int V_25 ;
V_25 = F_12 ( V_2 , V_3 ) ;
if ( ! V_25 )
F_13 ( V_3 , V_2 -> V_21 ) ;
else {
F_8 ( L_3 ) ;
return V_25 ;
}
V_2 -> V_26 = V_2 -> V_10 . V_11 ;
V_2 -> V_27 = V_2 -> V_10 . V_12 ;
V_2 -> V_15 = F_9 ( V_2 -> V_21 ) ;
V_2 -> V_28 = V_29 ;
V_2 -> V_10 . V_30 = 20 * 1000 ;
F_14 ( V_2 -> V_31 ) ;
return 0 ;
}
static int F_15 ( struct V_32 * V_33 )
{
int V_22 = 0 ;
V_3 = F_16 ( & V_33 -> V_34 ) ;
if ( ! V_3 ) {
F_8 ( L_4 ) ;
return - V_35 ;
}
V_19 = F_17 ( & V_33 -> V_34 , L_5 ) ;
if ( F_18 ( V_19 ) ) {
F_8 ( L_6 ) ;
return F_19 ( V_19 ) ;
}
F_20 ( L_7 ) ;
while ( V_3 [ V_22 ] . V_17 != V_24 ) {
F_20 ( L_8 , V_3 [ V_22 ] . V_17 / 1000 ) ;
V_22 ++ ;
}
return F_21 ( & V_36 ) ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_37 ) ;
}

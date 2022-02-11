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
if ( F_7 ( V_18 , V_3 [ V_8 ] . V_16 * 1000 ) ) {
F_8 ( L_1 ) ;
return - V_12 ;
}
F_5 (freqs.cpu, policy->cpus)
F_6 ( & V_7 , V_19 ) ;
return 0 ;
}
static unsigned int F_9 ( unsigned int V_20 )
{
int V_21 = 0 ;
unsigned long V_22 = F_10 ( V_18 ) / 1000 ;
while ( V_3 [ V_21 ] . V_16 != V_23 ) {
if ( V_22 <= V_3 [ V_21 ] . V_16 )
return V_3 [ V_21 ] . V_16 ;
V_21 ++ ;
}
F_8 ( L_2 ) ;
return 0 ;
}
static int T_1 F_11 ( struct V_1 * V_2 )
{
int V_21 = 0 ;
int V_24 ;
V_18 = F_12 ( NULL , L_3 ) ;
if ( F_13 ( V_18 ) ) {
F_8 ( L_4 ) ;
return F_14 ( V_18 ) ;
}
F_15 ( L_5 ) ;
while ( V_3 [ V_21 ] . V_16 != V_23 ) {
F_15 ( L_6 , V_3 [ V_21 ] . V_16 / 1000 ) ;
V_21 ++ ;
}
V_24 = F_16 ( V_2 , V_3 ) ;
if ( ! V_24 )
F_17 ( V_3 , V_2 -> V_20 ) ;
else {
F_8 ( L_7 ) ;
F_18 ( V_18 ) ;
return V_24 ;
}
V_2 -> V_25 = V_2 -> V_9 . V_10 ;
V_2 -> V_26 = V_2 -> V_9 . V_11 ;
V_2 -> V_14 = F_9 ( V_2 -> V_20 ) ;
V_2 -> V_27 = V_28 ;
V_2 -> V_9 . V_29 = 20 * 1000 ;
F_19 ( V_2 -> V_30 , V_31 ) ;
V_2 -> V_32 = V_33 ;
return 0 ;
}
static int F_20 ( struct V_34 * V_35 )
{
V_3 = F_21 ( & V_35 -> V_36 ) ;
if ( ! V_3 ) {
F_8 ( L_8 ) ;
return - V_37 ;
}
return F_22 ( & V_38 ) ;
}
static int T_2 F_23 ( void )
{
if ( ! F_24 () )
return - V_37 ;
F_15 ( L_9 ) ;
return F_25 ( & V_39 ) ;
}

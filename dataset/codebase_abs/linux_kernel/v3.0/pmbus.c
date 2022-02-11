static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
if ( F_2 ( V_2 , 0 , V_6 ) )
V_4 -> V_7 [ 0 ] |= V_8 ;
if ( F_2 ( V_2 , 0 , V_9 ) )
V_4 -> V_7 [ 0 ] |= V_10 ;
if ( F_2 ( V_2 , 0 , V_11 ) )
V_4 -> V_7 [ 0 ] |= V_12 ;
if ( F_2 ( V_2 , 0 , V_13 ) )
V_4 -> V_7 [ 0 ] |= V_14 ;
if ( V_4 -> V_7 [ 0 ]
&& F_3 ( V_2 , 0 , V_15 ) )
V_4 -> V_7 [ 0 ] |= V_16 ;
if ( F_3 ( V_2 , 0 , V_17 ) &&
F_2 ( V_2 , 0 , V_18 ) ) {
V_4 -> V_7 [ 0 ] |= V_19 ;
if ( F_3 ( V_2 , 0 , V_20 ) )
V_4 -> V_7 [ 0 ] |= V_21 ;
}
if ( F_3 ( V_2 , 0 , V_22 ) &&
F_2 ( V_2 , 0 , V_23 ) ) {
V_4 -> V_7 [ 0 ] |= V_24 ;
if ( F_3 ( V_2 , 0 , V_25 ) )
V_4 -> V_7 [ 0 ] |= V_26 ;
}
if ( F_2 ( V_2 , 0 , V_27 ) )
V_4 -> V_7 [ 0 ] |= V_28 ;
if ( F_2 ( V_2 , 0 , V_29 ) )
V_4 -> V_7 [ 0 ] |= V_30 ;
if ( F_2 ( V_2 , 0 , V_31 ) )
V_4 -> V_7 [ 0 ] |= V_32 ;
if ( V_4 -> V_7 [ 0 ] & ( V_28 | V_30
| V_32 )
&& F_3 ( V_2 , 0 ,
V_33 ) )
V_4 -> V_7 [ 0 ] |= V_34 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_35 ; V_5 ++ ) {
if ( F_2 ( V_2 , V_5 , V_36 ) ) {
V_4 -> V_7 [ V_5 ] |= V_37 ;
if ( F_3 ( V_2 , V_5 ,
V_38 ) )
V_4 -> V_7 [ V_5 ] |= V_39 ;
}
if ( F_2 ( V_2 , V_5 , V_40 ) ) {
V_4 -> V_7 [ V_5 ] |= V_41 ;
if ( F_3 ( V_2 , 0 ,
V_42 ) )
V_4 -> V_7 [ V_5 ] |= V_43 ;
}
if ( F_2 ( V_2 , V_5 , V_44 ) )
V_4 -> V_7 [ V_5 ] |= V_45 ;
}
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ! V_4 -> V_35 ) {
if ( F_3 ( V_2 , 0 , V_46 ) ) {
int V_5 ;
for ( V_5 = 1 ; V_5 < V_47 ; V_5 ++ ) {
if ( F_5 ( V_2 , V_5 ) < 0 )
break;
}
F_5 ( V_2 , 0 ) ;
V_4 -> V_35 = V_5 ;
} else {
V_4 -> V_35 = 1 ;
}
}
F_1 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_48 * V_49 )
{
struct V_3 * V_4 ;
int V_50 ;
V_4 = F_7 ( sizeof( struct V_3 ) , V_51 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_35 = V_49 -> V_53 ;
V_4 -> V_54 = F_4 ;
V_50 = F_8 ( V_2 , V_49 , V_4 ) ;
if ( V_50 < 0 )
goto V_55;
return 0 ;
V_55:
F_9 ( V_4 ) ;
return V_50 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_50 ;
const struct V_3 * V_4 ;
V_4 = F_11 ( V_2 ) ;
V_50 = F_12 ( V_2 ) ;
F_9 ( V_4 ) ;
return V_50 ;
}
static int T_1 F_13 ( void )
{
return F_14 ( & V_56 ) ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_56 ) ;
}

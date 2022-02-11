static int T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
if ( V_2 -> V_7 == V_8 &&
V_2 -> V_9 == V_10 &&
V_2 -> V_11 == 0x0299 )
return - V_12 ;
V_4 -> V_13 = ( V_2 -> V_11 & 0xf0 ) >> 4 ;
if ( V_4 -> V_13 > F_2 ( V_4 -> V_14 ) )
V_4 -> V_13 = F_2 ( V_4 -> V_14 ) ;
if ( V_4 -> V_14 [ 0 ] . V_15 != 0 )
V_4 -> V_14 [ 0 ] . V_15 = V_2 -> V_11 & 0xf ;
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_18 * V_19 = F_4 ( V_2 ) ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_21 = & V_24 [ V_17 -> V_25 ] ;
V_23 = F_5 ( V_2 , V_21 ) ;
if ( F_6 ( V_23 ) )
return F_7 ( V_23 ) ;
V_19 -> V_23 = V_23 ;
return 0 ;
}
static int T_1 F_8 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_3 * V_26 ;
struct V_18 * V_19 = F_4 ( V_2 ) ;
int V_27 , V_28 = 0 ;
V_19 -> V_4 = V_29 [ V_17 -> V_25 ] ;
V_26 = & V_19 -> V_4 ;
if ( V_26 -> V_30 &&
V_26 -> V_30 ( V_2 , V_26 , V_31 , V_32 ) )
return - V_12 ;
for ( V_27 = 0 ; V_27 < V_26 -> V_13 ; V_27 ++ ) {
struct V_33 * V_34 ;
int V_15 = V_26 -> V_14 [ V_27 ] . V_15 ;
int V_35 = V_26 -> V_14 [ V_27 ] . V_35 ;
unsigned long V_36 , V_37 ;
int V_38 ;
if ( V_19 -> V_39 == F_2 ( V_19 -> V_34 ) ) {
F_9 ( V_40
L_1
L_2 , F_10 ( V_2 ) ,
F_2 ( V_19 -> V_34 ) , V_26 -> V_13 ) ;
break;
}
V_36 = F_11 ( V_2 , V_15 ) ;
V_37 = 0 ;
if ( ( V_35 >= 0 ) && ( V_35 <= 6 ) )
V_37 = F_11 ( V_2 , V_35 ) ;
else if ( V_35 > 6 )
V_36 += V_35 ;
V_38 = V_2 -> V_38 ;
if ( V_38 == V_41 ) {
F_12 ( & V_2 -> V_2 ,
L_3 ,
V_36 , V_37 ) ;
V_38 = V_31 ;
} else {
F_12 ( & V_2 -> V_2 ,
L_4 ,
V_36 , V_37 , V_38 ) ;
}
V_34 = F_13 ( V_36 , V_37 , V_38 ,
V_32 , & V_2 -> V_2 , V_42 ) ;
if ( V_34 ) {
V_19 -> V_34 [ V_19 -> V_39 ++ ] = V_34 ;
V_28 = 1 ;
}
}
if ( V_26 -> V_43 )
V_26 -> V_43 ( V_2 , V_26 , ! V_28 ) ;
return 0 ;
}
static int T_1 F_14 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_44 ;
V_19 = F_15 ( sizeof *V_19 , V_45 ) ;
if ( ! V_19 )
return - V_46 ;
F_16 ( V_2 , V_19 ) ;
V_44 = F_17 ( V_2 ) ;
if ( V_44 ) {
F_16 ( V_2 , NULL ) ;
F_18 ( V_19 ) ;
return V_44 ;
}
if ( F_8 ( V_2 , V_17 ) ) {
F_16 ( V_2 , NULL ) ;
F_18 ( V_19 ) ;
return - V_12 ;
}
if ( F_3 ( V_2 , V_17 ) ) {
int V_47 ;
for ( V_47 = 0 ; V_47 < V_19 -> V_39 ; V_47 ++ )
F_19 ( V_19 -> V_34 [ V_47 ] ) ;
F_16 ( V_2 , NULL ) ;
F_18 ( V_19 ) ;
return - V_12 ;
}
return 0 ;
}
static void T_2 F_20 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_4 ( V_2 ) ;
int V_47 ;
F_16 ( V_2 , NULL ) ;
if ( V_19 -> V_23 )
F_21 ( V_19 -> V_23 ) ;
for ( V_47 = 0 ; V_47 < V_19 -> V_39 ; V_47 ++ )
F_19 ( V_19 -> V_34 [ V_47 ] ) ;
F_18 ( V_19 ) ;
return;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_48 )
{
struct V_18 * V_19 = F_4 ( V_2 ) ;
if ( V_19 -> V_23 )
F_23 ( V_19 -> V_23 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 , F_26 ( V_2 , V_48 ) ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_4 ( V_2 ) ;
int V_44 ;
F_25 ( V_2 , V_49 ) ;
F_28 ( V_2 ) ;
V_44 = F_17 ( V_2 ) ;
if ( V_44 ) {
F_9 ( V_50 L_5
L_6 , F_10 ( V_2 ) , V_44 ) ;
return V_44 ;
}
if ( V_19 -> V_23 )
F_29 ( V_19 -> V_23 ) ;
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_51 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_51 ) ;
return;
}

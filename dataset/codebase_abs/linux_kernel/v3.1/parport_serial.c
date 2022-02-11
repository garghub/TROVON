static int T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 , int V_6 )
{
if ( V_2 -> V_7 == V_8 &&
V_2 -> V_9 == V_10 &&
V_2 -> V_11 == 0x0299 )
return - V_12 ;
if ( V_2 -> V_7 == V_13 ) {
V_4 -> V_14 = 1 ;
} else {
V_4 -> V_14 = ( V_2 -> V_11 & 0xf0 ) >> 4 ;
if ( V_4 -> V_14 > F_2 ( V_4 -> V_15 ) )
V_4 -> V_14 = F_2 ( V_4 -> V_15 ) ;
}
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_18 * V_19 = F_4 ( V_2 ) ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
V_21 = & V_24 [ V_17 -> V_25 ] ;
if ( V_21 -> V_26 == 0 )
return 0 ;
V_23 = F_5 ( V_2 , V_21 ) ;
if ( F_6 ( V_23 ) )
return F_7 ( V_23 ) ;
V_19 -> V_23 = V_23 ;
return 0 ;
}
static int T_1 F_8 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_3 * V_27 ;
struct V_18 * V_19 = F_4 ( V_2 ) ;
int V_28 , V_29 = 0 ;
V_19 -> V_4 = V_30 [ V_17 -> V_25 ] ;
V_27 = & V_19 -> V_4 ;
if ( V_27 -> V_31 &&
V_27 -> V_31 ( V_2 , V_27 , V_32 , V_33 ) )
return - V_12 ;
for ( V_28 = 0 ; V_28 < V_27 -> V_14 ; V_28 ++ ) {
struct V_34 * V_35 ;
int V_36 = V_27 -> V_15 [ V_28 ] . V_36 ;
int V_37 = V_27 -> V_15 [ V_28 ] . V_37 ;
unsigned long V_38 , V_39 ;
int V_40 ;
if ( V_19 -> V_41 == F_2 ( V_19 -> V_35 ) ) {
F_9 ( V_42
L_1
L_2 , F_10 ( V_2 ) ,
F_2 ( V_19 -> V_35 ) , V_27 -> V_14 ) ;
break;
}
V_38 = F_11 ( V_2 , V_36 ) ;
V_39 = 0 ;
if ( ( V_37 >= 0 ) && ( V_37 <= 6 ) )
V_39 = F_11 ( V_2 , V_37 ) ;
else if ( V_37 > 6 )
V_38 += V_37 ;
V_40 = V_2 -> V_40 ;
if ( V_40 == V_43 ) {
F_12 ( & V_2 -> V_2 ,
L_3 ,
V_38 , V_39 ) ;
V_40 = V_32 ;
} else {
F_12 ( & V_2 -> V_2 ,
L_4 ,
V_38 , V_39 , V_40 ) ;
}
V_35 = F_13 ( V_38 , V_39 , V_40 ,
V_33 , & V_2 -> V_2 , V_44 ) ;
if ( V_35 ) {
V_19 -> V_35 [ V_19 -> V_41 ++ ] = V_35 ;
V_29 = 1 ;
}
}
if ( V_27 -> V_45 )
V_27 -> V_45 ( V_2 , V_27 , ! V_29 ) ;
return 0 ;
}
static int T_1 F_14 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_46 ;
V_19 = F_15 ( sizeof *V_19 , V_47 ) ;
if ( ! V_19 )
return - V_48 ;
F_16 ( V_2 , V_19 ) ;
V_46 = F_17 ( V_2 ) ;
if ( V_46 ) {
F_16 ( V_2 , NULL ) ;
F_18 ( V_19 ) ;
return V_46 ;
}
if ( F_8 ( V_2 , V_17 ) ) {
F_16 ( V_2 , NULL ) ;
F_18 ( V_19 ) ;
return - V_12 ;
}
if ( F_3 ( V_2 , V_17 ) ) {
int V_49 ;
for ( V_49 = 0 ; V_49 < V_19 -> V_41 ; V_49 ++ )
F_19 ( V_19 -> V_35 [ V_49 ] ) ;
F_16 ( V_2 , NULL ) ;
F_18 ( V_19 ) ;
return - V_12 ;
}
return 0 ;
}
static void T_2 F_20 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_4 ( V_2 ) ;
int V_49 ;
F_16 ( V_2 , NULL ) ;
if ( V_19 -> V_23 )
F_21 ( V_19 -> V_23 ) ;
for ( V_49 = 0 ; V_49 < V_19 -> V_41 ; V_49 ++ )
F_19 ( V_19 -> V_35 [ V_49 ] ) ;
F_18 ( V_19 ) ;
return;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_50 )
{
struct V_18 * V_19 = F_4 ( V_2 ) ;
if ( V_19 -> V_23 )
F_23 ( V_19 -> V_23 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 , F_26 ( V_2 , V_50 ) ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = F_4 ( V_2 ) ;
int V_46 ;
F_25 ( V_2 , V_51 ) ;
F_28 ( V_2 ) ;
V_46 = F_17 ( V_2 ) ;
if ( V_46 ) {
F_9 ( V_52 L_5
L_6 , F_10 ( V_2 ) , V_46 ) ;
return V_46 ;
}
if ( V_19 -> V_23 )
F_29 ( V_19 -> V_23 ) ;
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_53 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_53 ) ;
return;
}

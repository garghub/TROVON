static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_6 ,
const unsigned * * V_9 ,
unsigned * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_11 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_12 ;
}
static const char * F_6 ( struct V_1 * V_2 ,
unsigned V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_14 [ V_13 ] . V_8 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_13 ,
const char * const * * V_15 ,
unsigned * const V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_15 = V_4 -> V_14 [ V_13 ] . V_15 ;
* V_16 = V_4 -> V_14 [ V_13 ] . V_16 ;
return 0 ;
}
static int F_8 ( struct V_17 * V_18 , unsigned V_19 )
{
int V_20 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( V_18 -> V_13 [ V_20 ] == V_19 )
break;
}
if ( V_20 >= V_21 )
return - V_22 ;
return V_20 ;
}
static int F_9 ( struct V_23 * V_24 ,
struct V_3 * V_4 ,
unsigned V_19 )
{
int V_20 , V_25 , V_26 = 0 ;
for ( V_20 = 0 ; V_20 < V_24 -> V_11 ; V_20 ++ ) {
V_25 = V_24 -> V_9 [ V_20 ] ;
V_26 = F_8 ( & V_4 -> V_18 [ V_25 ] , V_19 ) ;
if ( V_26 < 0 ) {
F_10 ( V_4 -> V_27 , L_1 ,
V_19 , V_25 ) ;
break;
}
}
return V_26 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_13 ,
unsigned V_28 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_23 * V_29 = & V_4 -> V_7 [ V_28 ] ;
unsigned int V_30 ;
int V_20 , V_31 , V_25 , V_32 ;
if ( ! V_29 -> V_11 ||
( F_9 ( V_29 , V_4 , V_29 -> V_19 ) < 0 ) ) {
F_10 ( V_4 -> V_27 , L_2 , V_28 ) ;
return - V_22 ;
}
for ( V_20 = 0 ; V_20 < V_29 -> V_11 ; V_20 ++ ) {
V_25 = V_29 -> V_9 [ V_20 ] ;
V_32 = F_8 ( & V_4 -> V_18 [ V_25 ] , V_29 -> V_19 ) ;
V_31 = V_4 -> V_18 [ V_25 ] . V_31 ;
V_30 = F_12 ( V_4 -> V_33 + V_31 ) ;
V_30 &= ~ V_34 ;
V_30 |= V_32 ;
F_13 ( V_30 , V_4 -> V_33 + V_31 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
unsigned V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_30 ;
int V_32 , V_31 ;
V_32 = F_8 ( & V_4 -> V_18 [ V_25 ] , V_37 ) ;
if ( V_32 < 0 ) {
F_10 ( V_4 -> V_27 , L_3 ,
V_25 , V_4 -> V_38 [ V_25 ] . V_8 ) ;
return - V_22 ;
}
V_31 = V_4 -> V_18 [ V_25 ] . V_31 ;
V_30 = F_12 ( V_4 -> V_33 + V_31 ) & ~ V_34 ;
V_30 |= V_32 ;
F_13 ( V_30 , V_4 -> V_33 + V_31 ) ;
return 0 ;
}
int F_15 ( struct V_39 * V_40 ,
struct V_3 * V_4 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
if ( ! V_4 || ! V_4 -> V_45 )
return - V_22 ;
V_42 = V_4 -> V_42 ;
V_42 -> V_9 = V_4 -> V_38 ;
V_42 -> V_11 = V_4 -> V_46 ;
V_42 -> V_47 = & V_48 ;
V_42 -> V_49 = & V_50 ;
V_4 -> V_27 = & V_40 -> V_27 ;
V_51 . V_11 = V_4 -> V_52 ;
V_44 = F_16 ( V_40 , V_53 , 0 ) ;
if ( ! V_44 )
return - V_54 ;
V_4 -> V_33 = F_17 ( & V_40 -> V_27 , V_44 ) ;
if ( ! V_4 -> V_33 )
return - V_55 ;
V_4 -> V_56 = F_18 ( V_42 , & V_40 -> V_27 , V_4 ) ;
if ( ! V_4 -> V_56 ) {
F_10 ( & V_40 -> V_27 , L_4 ) ;
return - V_22 ;
}
F_19 ( V_4 -> V_56 , & V_51 ) ;
F_20 ( V_40 , V_4 ) ;
return 0 ;
}
int F_21 ( struct V_39 * V_40 )
{
struct V_3 * V_4 = F_22 ( V_40 ) ;
F_23 ( V_4 -> V_56 ) ;
F_20 ( V_40 , NULL ) ;
return 0 ;
}
static int T_1 F_24 ( void )
{
F_25 ( L_5 ) ;
return 0 ;
}
static void T_2 F_26 ( void )
{
}

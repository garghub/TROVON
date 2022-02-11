static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 >= V_5 -> V_6 )
return - V_7 ;
return 0 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 >= V_5 -> V_6 )
return NULL ;
return V_5 -> V_8 [ V_3 ] . V_9 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_3 ,
const unsigned * * V_10 ,
unsigned * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_3 >= V_5 -> V_6 )
return - V_7 ;
* V_10 = V_5 -> V_8 [ V_3 ] . V_10 ;
* V_11 = V_5 -> V_8 [ V_3 ] . V_12 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_13 >= V_5 -> V_14 )
return - V_7 ;
return 0 ;
}
static const char * F_6 ( struct V_1 * V_2 ,
unsigned V_13 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_15 [ V_13 ] . V_9 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_13 ,
const char * const * * V_16 ,
unsigned * const V_17 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
* V_16 = V_5 -> V_15 [ V_13 ] . V_16 ;
* V_17 = V_5 -> V_15 [ V_13 ] . V_17 ;
return 0 ;
}
static int F_8 ( struct V_18 * V_19 , unsigned V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ ) {
if ( V_19 -> V_13 [ V_21 ] == V_20 )
break;
}
if ( V_21 >= V_22 )
return - V_7 ;
return V_21 ;
}
static int F_9 ( struct V_23 * V_24 ,
struct V_4 * V_5 ,
unsigned V_20 )
{
int V_21 , V_25 , V_26 = 0 ;
for ( V_21 = 0 ; V_21 < V_24 -> V_12 ; V_21 ++ ) {
V_25 = V_24 -> V_10 [ V_21 ] ;
V_26 = F_8 ( & V_5 -> V_19 [ V_25 ] , V_20 ) ;
if ( V_26 < 0 ) {
F_10 ( V_5 -> V_27 , L_1 ,
V_20 , V_25 ) ;
break;
}
}
return V_26 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_13 ,
unsigned V_28 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_23 * V_29 = & V_5 -> V_8 [ V_28 ] ;
unsigned int V_30 ;
int V_21 , V_31 , V_25 , V_32 ;
if ( ! V_29 -> V_12 ||
( F_9 ( V_29 , V_5 , V_29 -> V_20 ) < 0 ) ) {
F_10 ( V_5 -> V_27 , L_2 , V_28 ) ;
return - V_7 ;
}
for ( V_21 = 0 ; V_21 < V_29 -> V_12 ; V_21 ++ ) {
V_25 = V_29 -> V_10 [ V_21 ] ;
V_32 = F_8 ( & V_5 -> V_19 [ V_25 ] , V_29 -> V_20 ) ;
V_31 = V_5 -> V_19 [ V_25 ] . V_31 ;
V_30 = F_12 ( V_5 -> V_33 + V_31 ) ;
V_30 &= ~ V_34 ;
V_30 |= V_32 ;
F_13 ( V_30 , V_5 -> V_33 + V_31 ) ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_13 ,
unsigned V_28 )
{
}
static int F_15 ( struct V_1 * V_2 ,
struct V_35 * V_36 ,
unsigned V_25 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_30 ;
int V_32 , V_31 ;
V_32 = F_8 ( & V_5 -> V_19 [ V_25 ] , V_37 ) ;
if ( V_32 < 0 ) {
F_10 ( V_5 -> V_27 , L_3 ,
V_25 , V_5 -> V_38 [ V_25 ] . V_9 ) ;
return - V_7 ;
}
V_31 = V_5 -> V_19 [ V_25 ] . V_31 ;
V_30 = F_12 ( V_5 -> V_33 + V_31 ) & ~ V_34 ;
V_30 |= V_32 ;
F_13 ( V_30 , V_5 -> V_33 + V_31 ) ;
return 0 ;
}
int F_16 ( struct V_39 * V_40 ,
struct V_4 * V_5 )
{
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_26 = 0 ;
if ( ! V_5 || ! V_5 -> V_45 )
return - V_7 ;
V_42 = V_5 -> V_42 ;
V_42 -> V_10 = V_5 -> V_38 ;
V_42 -> V_12 = V_5 -> V_46 ;
V_42 -> V_47 = & V_48 ;
V_42 -> V_49 = & V_50 ;
V_5 -> V_27 = & V_40 -> V_27 ;
V_51 . V_12 = V_5 -> V_52 ;
V_44 = F_17 ( V_40 , V_53 , 0 ) ;
if ( ! V_44 )
return - V_54 ;
V_5 -> V_55 = V_44 -> V_56 ;
V_5 -> V_57 = F_18 ( V_44 ) ;
V_5 -> V_33 = F_19 ( V_5 -> V_55 , V_5 -> V_57 ) ;
if ( ! V_5 -> V_33 )
return - V_58 ;
V_5 -> V_59 = F_20 ( V_42 , & V_40 -> V_27 , V_5 ) ;
if ( ! V_5 -> V_59 ) {
F_10 ( & V_40 -> V_27 , L_4 ) ;
V_26 = - V_7 ;
goto V_60;
}
F_21 ( V_5 -> V_59 , & V_51 ) ;
F_22 ( V_40 , V_5 ) ;
return 0 ;
V_60:
F_23 ( V_5 -> V_33 ) ;
return V_26 ;
}
int F_24 ( struct V_39 * V_40 )
{
struct V_4 * V_5 = F_25 ( V_40 ) ;
F_26 ( V_5 -> V_59 ) ;
F_23 ( V_5 -> V_33 ) ;
F_22 ( V_40 , NULL ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
F_28 ( L_5 ) ;
return 0 ;
}
static void T_2 F_29 ( void )
{
}

static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
do {
F_2 ( 10 ) ;
V_6 = F_3 ( V_7 , V_8 ) ;
if ( V_6 & ( V_9 | V_10 ) )
break;
} while ( 1 );
return ( V_6 & V_10 ) ? 0 : 1 ;
}
static int F_4 ( struct V_1 * V_2 , int V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_7 , V_12 , V_11 ) ;
F_5 ( V_7 , V_13 , V_14 ) ;
F_5 ( V_7 , V_8 , V_4 -> V_15 ? V_16 : V_17 ) ;
if ( ! F_1 ( V_2 ) )
return - V_18 ;
V_4 -> V_15 = ! ( F_3 ( V_7 , V_19 ) & V_20 ) ;
return V_4 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 , T_2 V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_7 , V_12 , V_21 ) ;
F_5 ( V_7 , V_8 , V_17 ) ;
if ( ! F_1 ( V_2 ) )
return - V_18 ;
return ! ( F_3 ( V_7 , V_19 ) & V_20 ) ;
}
static int F_7 ( struct V_1 * V_2 , T_2 * V_21 , int V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_7 , V_8 , V_17 | ( V_22 ? 0 : V_23 ) ) ;
if ( ! F_1 ( V_2 ) )
return 0 ;
* V_21 = F_3 ( V_7 , V_12 ) ;
return 1 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_5 ( V_7 , V_8 , V_24 ) ;
F_5 ( V_7 , V_13 , V_25 ) ;
V_4 -> V_15 = 0 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_28 , V_29 = 0 ;
int V_22 = V_27 -> V_30 - 1 ;
for ( V_28 = 0 ; V_28 < V_27 -> V_30 ; V_28 ++ ) {
if ( ! F_7 ( V_2 , & V_27 -> V_31 [ V_28 ] , V_28 == V_22 ) ) {
V_29 = - V_18 ;
break;
}
}
return V_29 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_26 * V_27 )
{
int V_28 , V_29 = 0 ;
for ( V_28 = 0 ; V_28 < V_27 -> V_30 ; V_28 ++ ) {
if ( ! F_6 ( V_2 , V_27 -> V_31 [ V_28 ] ) ) {
V_29 = - V_18 ;
break;
}
}
return V_29 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_26 * V_32 ,
int V_33 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 * V_27 ;
int V_11 ;
int V_28 = 0 , V_34 = 0 ;
F_12 ( V_4 -> V_35 , L_1 , V_36 , V_33 ) ;
for ( V_28 = 0 ; V_28 < V_33 ; V_28 ++ ) {
V_27 = & V_32 [ V_28 ] ;
if ( ! V_27 -> V_30 ) {
F_12 ( V_4 -> V_35 , L_2 , V_36 ) ;
continue;
}
V_11 = V_27 -> V_11 ;
if ( V_27 -> V_37 & V_38 )
V_11 |= 1 ;
V_34 = F_4 ( V_2 , V_11 ) ;
if ( V_34 < 0 )
break;
if ( V_27 -> V_37 & V_38 )
V_34 = F_9 ( V_2 , V_27 ) ;
else
V_34 = F_10 ( V_2 , V_27 ) ;
}
if ( V_28 )
F_8 ( V_2 ) ;
return ( V_34 < 0 ) ? V_34 : V_28 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
return V_39 ;
}
int F_14 ( struct V_3 * V_4 )
{
int V_29 ;
V_40 . V_5 = V_4 ;
V_4 -> V_2 = & V_40 ;
V_29 = F_15 ( V_4 -> V_2 ) ;
if ( V_29 < 0 ) {
F_16 ( V_4 -> V_35 , L_3 ,
V_40 . V_41 ) ;
}
return V_29 ;
}
void F_17 ( struct V_3 * V_4 )
{
if ( V_4 -> V_2 ) {
F_18 ( V_4 -> V_2 ) ;
V_4 -> V_2 = NULL ;
}
}

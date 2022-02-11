static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
T_1 (* F_4)( int , void * ) , void * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_5 ( V_7 -> V_8 , NULL , F_4 ,
V_9 , F_6 ( V_3 ) , V_6 ) ;
}
static void F_7 ( struct V_2 * V_3 , void * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_8 ( V_7 -> V_8 , V_6 ) ;
}
struct V_10 * F_9 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = & V_12 -> V_3 ;
struct V_13 * V_14 = V_3 -> V_15 ;
struct V_1 * V_7 ;
const T_2 * V_16 ;
int V_17 ;
int V_18 ;
int V_19 = - V_20 ;
if ( V_3 -> V_4 || ! V_14 )
return V_3 -> V_4 ;
V_7 = F_10 ( sizeof( * V_7 ) , V_21 ) ;
if ( ! V_7 )
return NULL ;
V_16 = F_11 ( V_14 , L_1 , & V_17 ) ;
V_17 = V_17 / sizeof( * V_16 ) / 2 ;
if ( ! V_16 || ! V_17 ) {
F_12 ( V_3 , L_2 ) ;
goto V_22;
}
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
const int V_23 = V_18 * 2 ;
T_2 V_24 ;
V_24 = F_13 ( F_14 ( V_16 [ V_23 ] ) ,
F_14 ( V_16 [ V_23 + 1 ] ) ) ;
if ( ! V_24 ) {
V_19 = - V_20 ;
F_12 ( V_3 , L_3 , V_18 ) ;
goto V_22;
}
V_7 -> V_5 . V_25 |= V_24 ;
}
for ( V_18 = 0 ; V_18 < F_15 ( V_7 -> V_26 ) ; V_18 ++ ) {
enum V_27 V_28 ;
V_7 -> V_26 [ V_18 ] = F_16 ( V_14 , V_18 , & V_28 ) ;
if ( ! F_17 ( V_7 -> V_26 [ V_18 ] ) )
continue;
if ( V_28 & V_29 )
V_7 -> V_30 [ V_18 ] = true ;
}
if ( F_17 ( V_7 -> V_26 [ V_31 ] ) ) {
V_7 -> V_5 . V_32 = V_7 -> V_26 [ V_31 ] ;
V_7 -> V_5 . V_33 |= V_34 ;
if ( ! V_7 -> V_30 [ V_31 ] )
V_7 -> V_5 . V_35 |= V_36 ;
}
if ( F_17 ( V_7 -> V_26 [ V_37 ] ) ) {
V_7 -> V_5 . V_38 = V_7 -> V_26 [ V_37 ] ;
V_7 -> V_5 . V_33 |= V_39 ;
if ( ! V_7 -> V_30 [ V_37 ] )
V_7 -> V_5 . V_35 |= V_40 ;
}
V_7 -> V_8 = F_18 ( V_14 , 0 ) ;
if ( V_7 -> V_8 != 0 ) {
V_7 -> V_5 . V_41 = F_3 ;
V_7 -> V_5 . exit = F_7 ;
} else {
V_7 -> V_5 . V_42 |= V_43 ;
}
V_3 -> V_4 = & V_7 -> V_5 ;
return V_3 -> V_4 ;
V_22:
F_19 ( V_7 ) ;
return NULL ;
}
void F_20 ( struct V_11 * V_12 )
{
struct V_2 * V_3 = & V_12 -> V_3 ;
struct V_13 * V_14 = V_3 -> V_15 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_4 || ! V_14 )
return;
F_19 ( V_7 ) ;
V_3 -> V_4 = NULL ;
}

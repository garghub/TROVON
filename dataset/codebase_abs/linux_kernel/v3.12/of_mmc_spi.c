static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 ,
T_1 (* F_4)( int , void * ) , void * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_5 ( V_7 -> V_8 , NULL , F_4 , 0 ,
F_6 ( V_3 ) , V_6 ) ;
}
static void F_7 ( struct V_2 * V_3 , void * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_8 ( V_7 -> V_8 , V_6 ) ;
}
struct V_9 * F_9 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = & V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_7 ;
const T_2 * V_15 ;
int V_16 ;
int V_17 ;
int V_18 = - V_19 ;
if ( V_3 -> V_4 || ! V_13 )
return V_3 -> V_4 ;
V_7 = F_10 ( sizeof( * V_7 ) , V_20 ) ;
if ( ! V_7 )
return NULL ;
V_15 = F_11 ( V_13 , L_1 , & V_16 ) ;
V_16 = V_16 / sizeof( * V_15 ) / 2 ;
if ( ! V_15 || ! V_16 ) {
F_12 ( V_3 , L_2 ) ;
goto V_21;
}
for ( V_17 = 0 ; V_17 < V_16 ; V_17 ++ ) {
const int V_22 = V_17 * 2 ;
T_2 V_23 ;
V_23 = F_13 ( F_14 ( V_15 [ V_22 ] ) ,
F_14 ( V_15 [ V_22 + 1 ] ) ) ;
if ( ! V_23 ) {
V_18 = - V_19 ;
F_12 ( V_3 , L_3 , V_17 ) ;
goto V_21;
}
V_7 -> V_5 . V_24 |= V_23 ;
}
for ( V_17 = 0 ; V_17 < F_15 ( V_7 -> V_25 ) ; V_17 ++ ) {
enum V_26 V_27 ;
V_7 -> V_25 [ V_17 ] = F_16 ( V_13 , V_17 , & V_27 ) ;
if ( ! F_17 ( V_7 -> V_25 [ V_17 ] ) )
continue;
if ( V_27 & V_28 )
V_7 -> V_29 [ V_17 ] = true ;
}
if ( F_17 ( V_7 -> V_25 [ V_30 ] ) ) {
V_7 -> V_5 . V_31 = V_7 -> V_25 [ V_30 ] ;
V_7 -> V_5 . V_32 |= V_33 ;
if ( ! V_7 -> V_29 [ V_30 ] )
V_7 -> V_5 . V_34 |= V_35 ;
}
if ( F_17 ( V_7 -> V_25 [ V_36 ] ) ) {
V_7 -> V_5 . V_37 = V_7 -> V_25 [ V_36 ] ;
V_7 -> V_5 . V_32 |= V_38 ;
if ( ! V_7 -> V_29 [ V_36 ] )
V_7 -> V_5 . V_34 |= V_39 ;
}
V_7 -> V_8 = F_18 ( V_13 , 0 ) ;
if ( V_7 -> V_8 != 0 ) {
V_7 -> V_5 . V_40 = F_3 ;
V_7 -> V_5 . exit = F_7 ;
} else {
V_7 -> V_5 . V_41 |= V_42 ;
}
V_3 -> V_4 = & V_7 -> V_5 ;
return V_3 -> V_4 ;
V_21:
F_19 ( V_7 ) ;
return NULL ;
}
void F_20 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = & V_11 -> V_3 ;
struct V_12 * V_13 = V_3 -> V_14 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
if ( ! V_3 -> V_4 || ! V_13 )
return;
F_19 ( V_7 ) ;
V_3 -> V_4 = NULL ;
}

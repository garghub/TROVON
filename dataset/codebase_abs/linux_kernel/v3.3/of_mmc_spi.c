static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 , struct V_1 , V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , int V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
bool V_8 = V_7 -> V_9 [ V_6 ] ;
bool V_10 = F_4 ( V_7 -> V_11 [ V_6 ] ) ;
return V_8 ^ V_10 ;
}
static int F_5 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_12 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
return F_3 ( V_3 , V_13 ) ;
}
static int F_7 ( struct V_2 * V_3 ,
T_1 (* F_8)( int , void * ) , void * V_14 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return F_9 ( V_7 -> V_15 , NULL , F_8 , 0 ,
F_10 ( V_3 ) , V_14 ) ;
}
static void F_11 ( struct V_2 * V_3 , void * V_14 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_12 ( V_7 -> V_15 , V_14 ) ;
}
struct V_16 * F_13 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_19 * V_20 = V_3 -> V_21 ;
struct V_1 * V_7 ;
const T_2 * V_22 ;
int V_23 ;
int V_24 ;
int V_25 = - V_26 ;
if ( V_3 -> V_4 || ! V_20 )
return V_3 -> V_4 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 )
return NULL ;
V_22 = F_15 ( V_20 , L_1 , & V_23 ) ;
V_23 = V_23 / sizeof( * V_22 ) / 2 ;
if ( ! V_22 || ! V_23 ) {
F_16 ( V_3 , L_2 ) ;
goto V_28;
}
for ( V_24 = 0 ; V_24 < V_23 ; V_24 ++ ) {
const int V_29 = V_24 * 2 ;
T_2 V_30 ;
V_30 = F_17 ( F_18 ( V_22 [ V_29 ] ) ,
F_18 ( V_22 [ V_29 + 1 ] ) ) ;
if ( ! V_30 ) {
V_25 = - V_26 ;
F_16 ( V_3 , L_3 , V_24 ) ;
goto V_28;
}
V_7 -> V_5 . V_31 |= V_30 ;
}
for ( V_24 = 0 ; V_24 < F_19 ( V_7 -> V_11 ) ; V_24 ++ ) {
enum V_32 V_33 ;
V_7 -> V_11 [ V_24 ] = F_20 ( V_20 , V_24 , & V_33 ) ;
if ( ! F_21 ( V_7 -> V_11 [ V_24 ] ) )
continue;
V_25 = F_22 ( V_7 -> V_11 [ V_24 ] , F_10 ( V_3 ) ) ;
if ( V_25 < 0 ) {
V_7 -> V_11 [ V_24 ] = - V_26 ;
continue;
}
if ( V_33 & V_34 )
V_7 -> V_9 [ V_24 ] = true ;
}
if ( F_21 ( V_7 -> V_11 [ V_12 ] ) )
V_7 -> V_5 . V_35 = F_5 ;
if ( F_21 ( V_7 -> V_11 [ V_13 ] ) )
V_7 -> V_5 . V_36 = F_6 ;
V_7 -> V_15 = F_23 ( V_20 , 0 ) ;
if ( V_7 -> V_15 != V_37 ) {
V_7 -> V_5 . V_38 = F_7 ;
V_7 -> V_5 . exit = F_11 ;
} else {
V_7 -> V_5 . V_39 |= V_40 ;
}
V_3 -> V_4 = & V_7 -> V_5 ;
return V_3 -> V_4 ;
V_28:
F_24 ( V_7 ) ;
return NULL ;
}
void F_25 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = & V_18 -> V_3 ;
struct V_19 * V_20 = V_3 -> V_21 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_24 ;
if ( ! V_3 -> V_4 || ! V_20 )
return;
for ( V_24 = 0 ; V_24 < F_19 ( V_7 -> V_11 ) ; V_24 ++ ) {
if ( F_21 ( V_7 -> V_11 [ V_24 ] ) )
F_26 ( V_7 -> V_11 [ V_24 ] ) ;
}
F_24 ( V_7 ) ;
V_3 -> V_4 = NULL ;
}

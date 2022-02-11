static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char V_6 [ V_7 ] ;
bool V_8 = false ;
if ( V_4 ) {
F_2 ( V_4 -> V_9 ) ;
} else {
V_4 = F_3 ( sizeof( * V_4 ) , V_10 ) ;
if ( ! V_4 )
return;
}
V_4 -> V_11 = V_4 -> V_12 = 0 ;
if ( F_4 ( V_2 , 0x00 , V_6 , V_7 ) ) {
F_5 ( V_6 , V_4 ) ;
V_8 = V_4 -> V_11 || V_4 -> V_12 ;
}
if ( ! V_8 ) {
F_6 ( V_4 ) ;
V_4 = NULL ;
} else
F_7 ( V_13 L_1 , V_4 -> V_14 , V_4 -> V_15 ) ;
V_2 -> V_5 = V_4 ;
}
static const struct V_16 * F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_17 ;
if ( ! V_4 || ! V_4 -> V_9 || ! ( V_4 -> V_18 & V_19 ) )
return NULL ;
for ( V_17 = 0 ; V_17 < V_4 -> V_20 ; V_17 ++ ) {
if ( V_4 -> V_9 [ V_17 ] . V_21 & V_22 &&
V_4 -> V_9 [ V_17 ] . V_21 & V_23 )
return & V_4 -> V_9 [ V_17 ] ;
}
return NULL ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 )
F_2 ( V_4 -> V_9 ) ;
}
void F_10 ( struct V_24 * V_25 )
{
struct V_1 V_2 = {
. V_25 = V_25 ,
. V_26 = 0x50 ,
. V_27 = V_27 ,
. F_9 = F_9 ,
. F_8 = F_8 } ;
F_1 ( & V_2 ) ;
F_11 ( & V_2 ) ;
}

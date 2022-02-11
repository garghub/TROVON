static unsigned int F_1 ( T_1 V_1 )
{
return ( V_1 & ( V_2 - 1 ) ) ;
}
static struct V_3 * F_2 ( T_2 V_4 , T_1 V_5 )
{
unsigned int V_6 ;
struct V_3 * V_1 ;
V_6 = F_1 ( V_5 ) ;
F_3 (pkey, &sel_ib_pkey_hash[idx].list, list) {
if ( V_1 -> V_7 . V_1 == V_5 &&
V_1 -> V_7 . V_4 == V_4 )
return V_1 ;
}
return NULL ;
}
static void F_4 ( struct V_3 * V_1 )
{
unsigned int V_6 ;
V_6 = F_1 ( V_1 -> V_7 . V_1 ) ;
F_5 ( & V_1 -> V_8 , & V_9 [ V_6 ] . V_8 ) ;
if ( V_9 [ V_6 ] . V_10 == V_11 ) {
struct V_3 * V_12 ;
V_12 = F_6 (
F_7 (
V_9 [ V_6 ] . V_8 . V_13 ,
F_8 ( & V_14 ) ) ,
struct V_3 , V_8 ) ;
F_9 ( & V_12 -> V_8 ) ;
F_10 ( V_12 , V_15 ) ;
} else {
V_9 [ V_6 ] . V_10 ++ ;
}
}
static int F_11 ( T_2 V_4 , T_1 V_5 , T_3 * V_16 )
{
int V_17 ;
struct V_3 * V_1 ;
struct V_3 * V_18 = NULL ;
unsigned long V_19 ;
F_12 ( & V_14 , V_19 ) ;
V_1 = F_2 ( V_4 , V_5 ) ;
if ( V_1 ) {
* V_16 = V_1 -> V_7 . V_16 ;
F_13 ( & V_14 , V_19 ) ;
return 0 ;
}
V_17 = F_14 ( V_4 , V_5 , V_16 ) ;
if ( V_17 )
goto V_20;
V_18 = F_15 ( sizeof( * V_18 ) , V_21 ) ;
if ( ! V_18 )
goto V_20;
V_18 -> V_7 . V_4 = V_4 ;
V_18 -> V_7 . V_1 = V_5 ;
V_18 -> V_7 . V_16 = * V_16 ;
F_4 ( V_18 ) ;
V_20:
F_13 ( & V_14 , V_19 ) ;
return V_17 ;
}
int F_16 ( T_2 V_4 , T_1 V_5 , T_3 * V_16 )
{
struct V_3 * V_1 ;
F_17 () ;
V_1 = F_2 ( V_4 , V_5 ) ;
if ( V_1 ) {
* V_16 = V_1 -> V_7 . V_16 ;
F_18 () ;
return 0 ;
}
F_18 () ;
return F_11 ( V_4 , V_5 , V_16 ) ;
}
void F_19 ( void )
{
unsigned int V_6 ;
struct V_3 * V_1 , * V_22 ;
unsigned long V_19 ;
F_12 ( & V_14 , V_19 ) ;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
F_20 (pkey, pkey_tmp,
&sel_ib_pkey_hash[idx].list, list) {
F_9 ( & V_1 -> V_8 ) ;
F_10 ( V_1 , V_15 ) ;
}
V_9 [ V_6 ] . V_10 = 0 ;
}
F_13 ( & V_14 , V_19 ) ;
}
static T_4 int F_21 ( void )
{
int V_23 ;
if ( ! V_24 )
return 0 ;
for ( V_23 = 0 ; V_23 < V_2 ; V_23 ++ ) {
F_22 ( & V_9 [ V_23 ] . V_8 ) ;
V_9 [ V_23 ] . V_10 = 0 ;
}
return 0 ;
}

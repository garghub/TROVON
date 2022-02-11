void T_1 F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 = & V_4 ;
V_3 = F_2 ( V_3 ) ;
* V_3 = * V_2 ;
* F_2 ( & V_5 ) = & V_4 ;
}
static struct V_1 * T_1 F_3 ( unsigned long V_6 ,
struct V_1 * V_2 )
{
struct V_1 * V_3 = & V_4 ;
struct V_1 V_7 ;
V_3 = F_2 ( V_3 ) ;
V_7 = * V_3 ;
* V_3 = * V_2 ;
if ( V_7 . V_8 && ! V_2 -> V_8 ) {
V_3 -> V_8 = V_7 . V_8 ;
V_3 -> V_9 = V_7 . V_9 ;
V_3 -> V_10 = V_7 . V_10 ;
V_3 -> V_11 = V_7 . V_11 ;
V_3 -> V_12 = V_7 . V_12 ;
V_3 -> V_13 = V_7 . V_13 ;
if ( V_7 . V_14 != NULL ) {
V_3 -> V_14 = V_7 . V_14 ;
V_3 -> V_10 = V_7 . V_10 ;
}
}
* F_2 ( & V_5 ) = & V_4 ;
if ( * F_2 ( & V_15 ) == NULL )
* F_2 ( & V_15 ) = V_3 -> V_16 ;
#if F_4 ( V_17 ) || F_4 ( V_18 )
if ( V_3 -> V_19 ) {
V_3 -> V_19 ( V_6 , V_3 ) ;
}
#endif
return V_3 ;
}
struct V_1 * T_1 F_5 ( unsigned long V_6 , unsigned int V_20 )
{
struct V_1 * V_2 = V_21 ;
int V_22 ;
V_2 = F_2 ( V_2 ) ;
for ( V_22 = 0 ; V_22 < F_6 ( V_21 ) ; V_22 ++ , V_2 ++ ) {
if ( ( V_20 & V_2 -> V_23 ) == V_2 -> V_24 )
return F_3 ( V_6 , V_2 ) ;
}
F_7 () ;
return NULL ;
}
void T_1 F_8 ( unsigned int V_20 )
{
struct V_1 * V_2 = V_21 ;
struct V_1 * V_3 = & V_4 ;
int V_22 ;
V_2 = F_2 ( V_2 ) ;
V_3 = F_2 ( V_3 ) ;
for ( V_22 = 0 ; V_22 < F_6 ( V_21 ) ; V_22 ++ , V_2 ++ ) {
if ( ( V_20 & V_2 -> V_23 ) == V_2 -> V_24 ) {
V_3 -> V_25 = V_2 -> V_25 ;
return;
}
}
}
void T_1 F_9 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_26 ; V_22 ++ ) {
unsigned long V_27 = 1ul << V_22 ;
if ( ! ( V_5 -> V_28 & V_27 ) )
F_10 ( & V_29 [ V_22 ] ) ;
}
}
void T_1 F_11 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_30 ; V_22 ++ ) {
unsigned long V_27 = 1ul << V_22 ;
if ( ! ( V_5 -> V_31 & V_27 ) )
F_10 ( & V_32 [ V_22 ] ) ;
}
}

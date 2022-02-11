static void F_1 ( unsigned long * V_1 , unsigned long V_2 )
{
int V_3 ;
unsigned long V_4 ;
struct V_5 * V_6 = (struct V_5 * ) V_2 ;
F_2 ( V_7 L_1 ) ;
while ( ( ( long ) V_1 & ( V_8 - 1 ) ) != 0 ) {
V_4 = * V_1 ;
if ( F_3 ( V_4 ) ) {
V_3 = 0 ;
if ( ( unsigned long ) V_1 == V_2 + sizeof( long ) ) {
V_6 = V_6 ? V_6 -> V_9 : NULL ;
V_2 = ( unsigned long ) V_6 ;
V_3 = 1 ;
}
F_2 ( V_7 L_2 , V_4 ) ;
F_2 ( V_10 L_3 , V_3 ? L_4 : L_5 ) ;
F_4 ( V_10 L_6 , V_4 ) ;
F_2 ( V_10 L_7 ) ;
}
V_1 ++ ;
}
F_2 ( V_7 L_7 ) ;
}
static unsigned long F_5 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
if ( ! V_12 || V_12 == V_15 )
return V_14 ? F_6 ( V_14 ) : F_7 () ;
else
return F_8 ( V_12 ) ;
}
static unsigned long * F_9 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
if ( ! V_12 || V_12 == V_15 )
return V_14 ? ( unsigned long * ) F_10 ( V_14 ) : F_11 () ;
else
return ( unsigned long * ) F_12 ( V_12 ) ;
}
void F_13 ( struct V_11 * V_12 , unsigned long * V_16 )
{
unsigned long * V_1 = V_16 , V_2 = 0 ;
struct V_13 * V_14 = V_15 -> V_17 . V_14 ;
int V_18 ;
if ( ! V_14 && F_14 () ) {
F_2 ( V_19 L_8
L_9 ) ;
return;
}
#ifdef F_15
V_2 = F_5 ( V_12 , V_14 ) ;
#endif
if ( ! V_16 )
V_1 = F_9 ( V_12 , V_14 ) ;
F_2 ( V_7 L_10 ) ;
V_16 = V_1 ;
for ( V_18 = 0 ; V_18 < 3 * V_20 ; V_18 ++ ) {
if ( F_16 ( V_16 ) )
break;
if ( V_18 && ( ( V_18 % V_20 ) == 0 ) )
F_2 ( V_10 L_7 ) ;
F_2 ( V_10 L_11 , * V_16 ++ ) ;
}
F_2 ( V_10 L_7 ) ;
F_1 ( V_1 , V_2 ) ;
}

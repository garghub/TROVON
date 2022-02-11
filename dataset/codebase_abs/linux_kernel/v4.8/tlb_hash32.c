void F_1 ( struct V_1 * V_2 , T_1 * V_3 , unsigned long V_4 )
{
unsigned long V_5 ;
if ( V_6 != 0 ) {
V_5 = F_2 ( V_3 ) & V_7 ;
F_3 ( V_2 -> V_8 . V_9 , V_4 , V_5 , 1 ) ;
}
}
void F_4 ( struct V_10 * V_11 )
{
if ( V_6 == 0 ) {
F_5 () ;
}
}
static void F_6 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_13 )
{
T_2 * V_14 ;
unsigned long V_15 ;
int V_16 ;
unsigned int V_17 = V_2 -> V_8 . V_9 ;
if ( V_6 == 0 ) {
F_5 () ;
return;
}
V_12 &= V_7 ;
if ( V_12 >= V_13 )
return;
V_13 = ( V_13 - 1 ) | ~ V_7 ;
V_14 = F_7 ( F_8 ( F_9 ( V_2 , V_12 ) , V_12 ) , V_12 ) ;
for (; ; ) {
V_15 = ( ( V_12 + V_18 ) & V_19 ) - 1 ;
if ( V_15 > V_13 )
V_15 = V_13 ;
if ( ! F_10 ( * V_14 ) ) {
V_16 = ( ( V_15 - V_12 ) >> V_20 ) + 1 ;
F_3 ( V_17 , V_12 , F_11 ( * V_14 ) , V_16 ) ;
}
if ( V_15 == V_13 )
break;
V_12 = V_15 + 1 ;
++ V_14 ;
}
}
void F_12 ( unsigned long V_12 , unsigned long V_13 )
{
F_6 ( & V_21 , V_12 , V_13 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
if ( V_6 == 0 ) {
F_5 () ;
return;
}
for ( V_23 = V_2 -> V_24 ; V_23 != NULL ; V_23 = V_23 -> V_25 )
F_6 ( V_23 -> V_26 , V_23 -> V_27 , V_23 -> V_28 ) ;
}
void F_14 ( struct V_22 * V_29 , unsigned long V_30 )
{
struct V_1 * V_2 ;
T_2 * V_14 ;
if ( V_6 == 0 ) {
F_15 ( V_30 ) ;
return;
}
V_2 = ( V_30 < V_31 ) ? V_29 -> V_26 : & V_21 ;
V_14 = F_7 ( F_8 ( F_9 ( V_2 , V_30 ) , V_30 ) , V_30 ) ;
if ( ! F_10 ( * V_14 ) )
F_3 ( V_2 -> V_8 . V_9 , V_30 , F_11 ( * V_14 ) , 1 ) ;
}
void F_16 ( struct V_22 * V_29 , unsigned long V_12 ,
unsigned long V_13 )
{
F_6 ( V_29 -> V_26 , V_12 , V_13 ) ;
}
void T_3 F_17 ( void )
{
}

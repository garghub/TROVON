void F_1 ( struct V_1 * V_2 , T_1 * V_3 , unsigned long V_4 )
{
unsigned long V_5 ;
if ( V_6 != 0 ) {
V_5 = F_2 ( V_3 ) & V_7 ;
F_3 ( V_2 -> V_8 . V_9 , V_4 , V_5 , 1 ) ;
}
}
void F_4 ( struct V_10 * V_11 , unsigned long V_4 )
{
if ( V_6 != 0 )
return;
F_5 ( V_4 ) ;
}
void F_6 ( struct V_12 * V_13 )
{
if ( V_6 == 0 ) {
F_7 () ;
}
}
static void F_8 ( struct V_1 * V_2 , unsigned long V_14 ,
unsigned long V_15 )
{
T_2 * V_16 ;
unsigned long V_17 ;
int V_18 ;
unsigned int V_19 = V_2 -> V_8 . V_9 ;
if ( V_6 == 0 ) {
F_7 () ;
return;
}
V_14 &= V_7 ;
if ( V_14 >= V_15 )
return;
V_15 = ( V_15 - 1 ) | ~ V_7 ;
V_16 = F_9 ( F_10 ( F_11 ( V_2 , V_14 ) , V_14 ) , V_14 ) ;
for (; ; ) {
V_17 = ( ( V_14 + V_20 ) & V_21 ) - 1 ;
if ( V_17 > V_15 )
V_17 = V_15 ;
if ( ! F_12 ( * V_16 ) ) {
V_18 = ( ( V_17 - V_14 ) >> V_22 ) + 1 ;
F_3 ( V_19 , V_14 , F_13 ( * V_16 ) , V_18 ) ;
}
if ( V_17 == V_15 )
break;
V_14 = V_17 + 1 ;
++ V_16 ;
}
}
void F_14 ( unsigned long V_14 , unsigned long V_15 )
{
F_8 ( & V_23 , V_14 , V_15 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct V_10 * V_24 ;
if ( V_6 == 0 ) {
F_7 () ;
return;
}
for ( V_24 = V_2 -> V_25 ; V_24 != NULL ; V_24 = V_24 -> V_26 )
F_8 ( V_24 -> V_27 , V_24 -> V_28 , V_24 -> V_29 ) ;
}
void F_16 ( struct V_10 * V_11 , unsigned long V_30 )
{
struct V_1 * V_2 ;
T_2 * V_16 ;
if ( V_6 == 0 ) {
F_5 ( V_30 ) ;
return;
}
V_2 = ( V_30 < V_31 ) ? V_11 -> V_27 : & V_23 ;
V_16 = F_9 ( F_10 ( F_11 ( V_2 , V_30 ) , V_30 ) , V_30 ) ;
if ( ! F_12 ( * V_16 ) )
F_3 ( V_2 -> V_8 . V_9 , V_30 , F_13 ( * V_16 ) , 1 ) ;
}
void F_17 ( struct V_10 * V_11 , unsigned long V_14 ,
unsigned long V_15 )
{
F_8 ( V_11 -> V_27 , V_14 , V_15 ) ;
}
void T_3 F_18 ( void )
{
}

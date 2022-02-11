int F_1 ( int V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) F_2 ( V_4 ) ;
if ( V_1 < 0 || V_1 >= V_5 ) {
F_3 ( L_1 , V_1 ) ;
return 0 ;
}
V_3 += V_1 ;
if ( ! ( V_3 -> V_6 & V_7 ) ) {
F_3 ( L_2 , V_1 ) ;
return 0 ;
}
if ( V_3 -> V_6 & ( V_8 | V_9 ) ) {
F_3 ( L_3 , V_1 ) ;
return 0 ;
}
return 1 ;
}
void F_4 ( int V_1 ,
unsigned long V_10 , unsigned long V_11 ,
unsigned long V_12 , unsigned long V_13 )
{
volatile struct V_2 * V_3 =
(struct V_2 * ) F_2 ( V_4 ) ;
if ( ! F_1 ( V_1 ) )
return;
if ( V_1 == F_5 () ) {
F_3 ( L_4 , V_1 ) ;
return;
}
V_3 += V_1 ;
F_3 ( L_5 , V_1 ) ;
V_3 -> V_10 = V_10 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_11 = V_11 ;
V_3 -> V_13 = V_13 ;
F_6 () ;
V_3 -> V_6 |= V_8 ;
F_6 () ;
while ( ( V_3 -> V_6 & V_9 ) == 0 )
;
F_7 () ;
F_3 ( L_6 , V_1 ) ;
}

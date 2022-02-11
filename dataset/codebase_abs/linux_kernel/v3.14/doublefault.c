static void F_1 ( void )
{
struct V_1 V_2 = { 0 , 0 } ;
unsigned long V_3 , V_4 ;
F_2 ( & V_2 ) ;
V_3 = V_2 . V_5 ;
F_3 ( V_6 L_1 , V_3 , V_2 . V_7 ) ;
if ( F_4 ( V_3 ) ) {
V_3 += V_8 << 3 ;
V_4 = F_5 ( (struct V_9 * ) V_3 ) ;
F_3 ( V_6 L_2 , V_4 ) ;
if ( F_4 ( V_4 ) ) {
struct V_10 * V_11 = (struct V_10 * ) V_4 ;
F_3 ( V_6 L_3 ,
V_11 -> V_12 , V_11 -> V_13 ) ;
F_3 ( V_6 L_4 ,
V_11 -> V_14 , V_11 -> V_15 , V_11 -> V_16 , V_11 -> V_17 ) ;
F_3 ( V_6 L_5 ,
V_11 -> V_18 , V_11 -> V_19 ) ;
}
}
for (; ; )
F_6 () ;
}
void F_7 ( struct V_20 * V_21 , long V_22 ) {}
void F_7 ( struct V_20 * V_21 , long V_22 )
{
F_8 ( L_6 , V_22 ) ;
F_9 ( V_21 ) ;
F_10 ( L_7 ) ;
}

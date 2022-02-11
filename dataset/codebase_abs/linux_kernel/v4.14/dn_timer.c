void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , V_4 , ( unsigned long ) V_2 ) ;
F_3 ( V_2 , & V_2 -> V_3 , V_5 + V_6 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , & V_2 -> V_3 ) ;
}
static void V_4 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_8 * V_9 = F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
F_3 ( V_2 , & V_2 -> V_3 , V_5 + V_10 / 10 ) ;
goto V_11;
}
if ( V_9 -> V_12 && V_9 -> V_13 ) {
if ( V_9 -> V_12 <= V_6 ) {
V_9 -> V_12 = 0 ;
if ( V_9 -> V_13 ( V_2 ) )
goto V_11;
} else {
V_9 -> V_12 -= V_6 ;
}
}
if ( V_9 -> V_14 && V_9 -> V_15 && ( V_9 -> V_16 == V_17 ) ) {
if ( F_9 ( V_5 , V_9 -> V_18 + V_9 -> V_14 ) )
V_9 -> V_15 ( V_2 ) ;
}
F_3 ( V_2 , & V_2 -> V_3 , V_5 + V_6 ) ;
V_11:
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}

void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 + V_6 ;
V_2 -> V_3 . V_7 = V_8 ;
V_2 -> V_3 . V_9 = ( unsigned long ) V_2 ;
F_2 ( & V_2 -> V_3 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 ) ;
}
static void V_8 ( unsigned long V_10 )
{
struct V_1 * V_2 = (struct V_1 * ) V_10 ;
struct V_11 * V_12 = F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
if ( F_8 ( V_2 ) ) {
V_2 -> V_3 . V_4 = V_5 + V_13 / 10 ;
F_2 ( & V_2 -> V_3 ) ;
goto V_14;
}
if ( V_12 -> V_15 && V_12 -> V_16 ) {
if ( V_12 -> V_15 <= V_6 ) {
V_12 -> V_15 = 0 ;
if ( V_12 -> V_16 ( V_2 ) )
goto V_14;
} else {
V_12 -> V_15 -= V_6 ;
}
}
if ( V_12 -> V_17 && V_12 -> V_18 && ( V_12 -> V_19 == V_20 ) ) {
if ( ( V_5 - V_12 -> V_21 ) >= V_12 -> V_17 )
V_12 -> V_18 ( V_2 ) ;
}
V_2 -> V_3 . V_4 = V_5 + V_6 ;
F_2 ( & V_2 -> V_3 ) ;
V_14:
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}

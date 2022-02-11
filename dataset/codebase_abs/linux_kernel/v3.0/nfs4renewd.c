void
F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 . V_2 ) ;
struct V_8 * V_9 ;
long V_10 ;
unsigned long V_11 , V_12 ;
V_4 = V_6 -> V_13 -> V_14 ;
F_3 ( L_1 , V_15 ) ;
if ( F_4 ( V_16 , & V_6 -> V_17 ) )
goto V_18;
F_5 ( & V_6 -> V_19 ) ;
V_10 = V_6 -> V_20 ;
V_11 = V_6 -> V_21 ;
V_12 = V_22 ;
if ( F_6 ( V_12 , V_11 + V_10 / 3 ) ) {
V_9 = V_4 -> V_23 ( V_6 ) ;
F_7 ( & V_6 -> V_19 ) ;
if ( V_9 == NULL ) {
if ( ! F_8 ( V_6 ) ) {
F_9 ( V_24 , & V_6 -> V_25 ) ;
goto V_18;
}
F_10 ( V_6 ) ;
} else {
V_4 -> V_26 ( V_6 , V_9 ) ;
F_11 ( V_9 ) ;
goto V_27;
}
} else {
F_3 ( L_2 ,
V_15 ) ;
F_7 ( & V_6 -> V_19 ) ;
}
F_12 ( V_6 ) ;
V_27:
F_13 ( V_6 ) ;
V_18:
F_3 ( L_3 , V_15 ) ;
}
void
F_12 ( struct V_5 * V_6 )
{
long V_28 ;
F_5 ( & V_6 -> V_19 ) ;
V_28 = ( 2 * V_6 -> V_20 ) / 3 + ( long ) V_6 -> V_21
- ( long ) V_22 ;
if ( V_28 < 5 * V_29 )
V_28 = 5 * V_29 ;
F_3 ( L_4 ,
V_15 , ( V_28 + V_29 - 1 ) / V_29 ) ;
F_14 ( & V_6 -> V_7 ) ;
F_15 ( & V_6 -> V_7 , V_28 ) ;
F_9 ( V_30 , & V_6 -> V_17 ) ;
F_7 ( & V_6 -> V_19 ) ;
}
void
F_16 ( struct V_5 * V_6 )
{
F_17 ( & V_6 -> V_7 ) ;
}

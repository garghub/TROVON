static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
struct V_4 * V_5 = (struct V_4 * ) V_3 -> V_5 ;
struct V_6 * V_7 = & V_3 -> V_7 ;
unsigned long V_8 ;
T_1 * V_9 = V_3 -> V_9 ;
T_1 V_10 ;
if ( * V_9 == V_3 -> V_11 )
goto V_12;
if ( ( * V_9 ) & 0x01 ) {
F_2 ( V_13 , F_3 ( V_13 ) | V_14 ) ;
do {
V_10 = F_3 ( V_15 ) ;
} while ( ( V_10 & V_16 ) == 0 );
F_4 ( V_5 , 100 ) ;
} else {
F_4 ( V_5 , 0 ) ;
F_2 ( V_13 , F_3 ( V_13 ) & ~ V_14 ) ;
do {
V_10 = F_3 ( V_15 ) ;
} while ( ( V_10 & V_16 ) == 0 );
}
V_3 -> V_11 = * V_9 ;
V_12:
F_5 ( & V_3 -> V_17 , V_8 ) ;
if ( ! F_6 ( V_7 ) ) {
V_7 -> V_18 = V_19 + V_20 ;
F_7 ( V_7 ) ;
}
F_8 ( & V_3 -> V_17 , V_8 ) ;
}
void F_9 ( struct V_2 * V_3 )
{
struct V_6 * V_7 = & V_3 -> V_7 ;
unsigned long V_8 ;
F_10 ( & V_3 -> V_17 ) ;
F_5 ( & V_3 -> V_17 , V_8 ) ;
F_11 ( V_7 ) ;
V_7 -> V_1 = ( unsigned long ) V_3 ;
V_7 -> V_21 = F_1 ;
V_7 -> V_18 = V_19 + V_20 ;
F_7 ( V_7 ) ;
F_8 ( & V_3 -> V_17 , V_8 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
F_13 ( & V_3 -> V_7 ) ;
}

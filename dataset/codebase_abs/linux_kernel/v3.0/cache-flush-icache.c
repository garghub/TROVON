void F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
unsigned long V_4 = F_2 ( V_3 ) ;
unsigned long V_5 ;
V_5 = F_3 () ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
F_6 ( V_6 , V_4 , V_4 + V_7 ) ;
F_7 ( V_5 ) ;
}
static void F_8 ( unsigned long V_4 , unsigned long V_8 )
{
unsigned long V_9 , V_10 , V_11 ;
struct V_3 * V_3 ;
T_1 * V_12 ;
T_2 * V_13 ;
T_3 * V_14 ;
T_4 * V_15 , V_16 ;
V_11 = V_4 & ~ V_17 ;
V_10 = V_8 - V_4 ;
V_12 = F_9 ( V_18 -> V_19 , V_4 ) ;
if ( ! V_12 || ! F_10 ( * V_12 ) )
return;
V_13 = F_11 ( V_12 , V_4 ) ;
if ( ! V_13 || ! F_12 ( * V_13 ) )
return;
V_14 = F_13 ( V_13 , V_4 ) ;
if ( ! V_14 || ! F_14 ( * V_14 ) )
return;
V_15 = F_15 ( V_14 , V_4 ) ;
if ( ! V_15 )
return;
V_16 = * V_15 ;
F_16 ( V_15 ) ;
if ( F_17 ( V_16 ) )
return;
V_3 = F_18 ( V_16 ) ;
if ( ! V_3 )
return;
V_9 = F_2 ( V_3 ) ;
F_19 ( V_9 + V_11 , V_10 ) ;
F_20 ( V_9 + V_11 , V_10 ) ;
F_6 ( V_6 , V_4 , V_8 ) ;
}
void F_21 ( unsigned long V_4 , unsigned long V_8 )
{
unsigned long V_20 , V_21 ;
unsigned long V_5 ;
V_5 = F_3 () ;
if ( V_8 > 0x80000000UL ) {
if ( V_8 > 0xa0000000UL ) {
V_8 = 0xa0000000UL ;
if ( V_4 >= V_8 )
goto V_22;
}
V_20 = ( V_4 >= 0x80000000UL ) ? V_4 : 0x80000000UL ;
F_22 ( V_20 , V_8 ) ;
F_23 ( V_20 , V_8 ) ;
F_6 ( V_6 , V_20 , V_8 ) ;
if ( V_20 == V_4 )
goto V_22;
V_8 = V_20 ;
}
V_20 = V_4 & V_17 ;
V_21 = ( V_8 - 1 ) & V_17 ;
if ( V_20 == V_21 ) {
F_8 ( V_4 , V_8 ) ;
} else if ( V_20 + 1 == V_21 ) {
F_8 ( V_4 , V_21 ) ;
F_8 ( V_21 , V_8 ) ;
} else {
F_24 () ;
F_25 () ;
F_6 ( V_23 , 0 , 0 ) ;
}
V_22:
F_7 ( V_5 ) ;
}

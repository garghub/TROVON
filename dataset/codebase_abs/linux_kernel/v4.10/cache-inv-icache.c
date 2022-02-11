static void F_1 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_3 , V_4 , V_5 ;
struct V_6 * V_6 ;
T_1 * V_7 ;
T_2 * V_8 ;
T_3 * V_9 ;
T_4 * V_10 , V_11 ;
V_5 = V_1 & ~ V_12 ;
V_4 = V_2 - V_1 ;
V_7 = F_2 ( V_13 -> V_14 , V_1 ) ;
if ( ! V_7 || ! F_3 ( * V_7 ) )
return;
V_8 = F_4 ( V_7 , V_1 ) ;
if ( ! V_8 || ! F_5 ( * V_8 ) )
return;
V_9 = F_6 ( V_8 , V_1 ) ;
if ( ! V_9 || ! F_7 ( * V_9 ) )
return;
V_10 = F_8 ( V_9 , V_1 ) ;
if ( ! V_10 )
return;
V_11 = * V_10 ;
F_9 ( V_10 ) ;
if ( F_10 ( V_11 ) )
return;
V_6 = F_11 ( V_11 ) ;
if ( ! V_6 )
return;
V_3 = F_12 ( V_6 ) ;
F_13 ( V_3 + V_5 , V_4 ) ;
F_14 ( V_15 , V_1 , V_2 ) ;
}
void F_15 ( unsigned long V_1 , unsigned long V_2 )
{
unsigned long V_16 , V_17 ;
unsigned long V_18 ;
V_18 = F_16 () ;
if ( V_2 > 0x80000000UL ) {
if ( V_2 > 0xa0000000UL ) {
V_2 = 0xa0000000UL ;
if ( V_1 >= V_2 )
goto V_19;
}
V_16 = ( V_1 >= 0x80000000UL ) ? V_1 : 0x80000000UL ;
F_17 ( V_16 , V_2 ) ;
F_14 ( V_15 , V_1 , V_2 ) ;
if ( V_16 == V_1 )
goto V_19;
V_2 = V_16 ;
}
V_16 = V_1 & V_12 ;
V_17 = ( V_2 - 1 ) & V_12 ;
if ( V_16 == V_17 ) {
F_1 ( V_1 , V_2 ) ;
} else if ( V_16 + 1 == V_17 ) {
F_1 ( V_1 , V_17 ) ;
F_1 ( V_17 , V_2 ) ;
} else {
F_18 () ;
F_14 ( V_20 , 0 , 0 ) ;
}
V_19:
F_19 ( V_18 ) ;
}

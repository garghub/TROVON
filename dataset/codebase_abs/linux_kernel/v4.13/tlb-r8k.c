void F_1 ( void )
{
unsigned long V_1 ;
unsigned long V_2 ;
int V_3 ;
F_2 ( V_1 ) ;
V_2 = F_3 () ;
F_4 ( 0 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
F_5 ( V_3 >> V_5 ) ;
F_6 ( V_3 << V_6 ) ;
F_7 ( V_7 + ( V_3 << ( V_6 + 1 ) ) ) ;
F_8 () ;
F_9 () ;
}
F_10 () ;
F_7 ( V_2 ) ;
F_11 ( V_1 ) ;
}
void F_12 ( struct V_8 * V_9 )
{
int V_10 = F_13 () ;
if ( F_14 ( V_10 , V_9 ) != 0 )
F_15 ( V_9 , V_10 ) ;
}
void F_16 ( struct V_11 * V_12 , unsigned long V_13 ,
unsigned long V_14 )
{
struct V_8 * V_9 = V_12 -> V_15 ;
int V_10 = F_13 () ;
unsigned long V_1 ;
int V_16 , V_17 , V_18 ;
if ( ! F_14 ( V_10 , V_9 ) )
return;
V_18 = ( V_14 - V_13 + ( V_19 - 1 ) ) >> V_6 ;
V_18 = ( V_18 + 1 ) >> 1 ;
F_2 ( V_1 ) ;
if ( V_18 > V_4 / 2 ) {
F_15 ( V_9 , V_10 ) ;
goto V_20;
}
V_16 = F_3 () ;
V_17 = F_17 ( V_10 , V_9 ) ;
F_4 ( 0 ) ;
V_13 &= V_21 ;
V_14 += ( V_19 - 1 ) ;
V_14 &= V_21 ;
while ( V_13 < V_14 ) {
signed long V_22 ;
F_6 ( V_13 ) ;
F_7 ( V_13 ) ;
V_13 += V_19 ;
F_18 () ;
V_22 = F_19 () ;
if ( V_22 < 0 )
continue;
F_7 ( V_7 + ( V_22 << ( V_6 + 1 ) ) ) ;
F_9 () ;
}
F_7 ( V_16 ) ;
V_20:
F_11 ( V_1 ) ;
}
void F_20 ( unsigned long V_13 , unsigned long V_14 )
{
unsigned long V_18 , V_1 ;
V_18 = ( V_14 - V_13 + ( V_19 - 1 ) ) >> V_6 ;
V_18 = ( V_18 + 1 ) >> 1 ;
if ( V_18 > V_4 / 2 ) {
F_1 () ;
return;
}
F_2 ( V_1 ) ;
F_4 ( 0 ) ;
V_13 &= V_21 ;
V_14 += ( V_19 - 1 ) ;
V_14 &= V_21 ;
while ( V_13 < V_14 ) {
signed long V_22 ;
F_6 ( V_13 ) ;
F_7 ( V_13 ) ;
V_13 += V_19 ;
F_18 () ;
V_22 = F_19 () ;
if ( V_22 < 0 )
continue;
F_7 ( V_7 + ( V_22 << ( V_6 + 1 ) ) ) ;
F_9 () ;
}
F_11 ( V_1 ) ;
}
void F_21 ( struct V_11 * V_12 , unsigned long V_23 )
{
int V_10 = F_13 () ;
unsigned long V_1 ;
int V_16 , V_17 ;
signed long V_22 ;
if ( ! F_14 ( V_10 , V_12 -> V_15 ) )
return;
V_17 = F_17 ( V_10 , V_12 -> V_15 ) ;
V_23 &= V_21 ;
F_2 ( V_1 ) ;
V_16 = F_3 () ;
F_6 ( V_23 ) ;
F_7 ( V_17 ) ;
F_18 () ;
V_22 = F_19 () ;
if ( V_22 < 0 )
goto V_24;
F_4 ( 0 ) ;
F_7 ( V_7 + ( V_22 << ( V_6 + 1 ) ) ) ;
F_9 () ;
V_24:
F_7 ( V_16 ) ;
F_11 ( V_1 ) ;
}
void F_22 ( struct V_11 * V_12 , unsigned long V_25 , T_1 V_26 )
{
unsigned long V_1 ;
T_2 * V_27 ;
T_3 * V_28 ;
T_1 * V_29 ;
int V_30 ;
if ( V_31 -> V_32 != V_12 -> V_15 )
return;
V_30 = F_3 () & F_23 ( & V_33 ) ;
F_2 ( V_1 ) ;
V_25 &= V_21 ;
F_6 ( V_25 ) ;
F_7 ( V_30 ) ;
V_27 = F_24 ( V_12 -> V_15 , V_25 ) ;
V_28 = F_25 ( V_27 , V_25 ) ;
V_29 = F_26 ( V_28 , V_25 ) ;
F_18 () ;
F_4 ( F_27 ( * V_29 ++ ) >> 6 ) ;
F_9 () ;
F_7 ( V_30 ) ;
F_11 ( V_1 ) ;
}
static void F_28 ( unsigned long V_34 )
{
struct V_35 * V_36 = & V_33 ;
V_36 -> V_37 = 3 * 128 ;
}
void F_29 ( void )
{
unsigned int V_34 = F_30 () ;
unsigned long V_38 ;
F_28 ( V_34 ) ;
V_38 = F_31 () ;
V_38 &= ~ ( V_39 | V_40 ) ;
#ifdef F_32
V_38 |= ( V_41 << 32 ) | ( V_41 << 36 ) ;
#elif F_33 ( V_42 )
V_38 |= ( V_43 << 32 ) | ( V_43 << 36 ) ;
#elif F_33 ( V_44 )
V_38 |= ( V_45 << 32 ) | ( V_45 << 36 ) ;
#elif F_33 ( V_46 )
V_38 |= ( V_47 << 32 ) | ( V_47 << 36 ) ;
#endif
F_34 ( V_38 ) ;
F_35 ( 0 ) ;
F_1 () ;
F_36 () ;
}

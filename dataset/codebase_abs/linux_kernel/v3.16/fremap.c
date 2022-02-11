static int F_1 ( struct V_1 * V_1 )
{
return F_2 ( V_1 ) ? V_2 : V_3 ;
}
static void F_3 ( struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned long V_8 , T_1 * V_9 )
{
T_1 V_10 = * V_9 ;
struct V_1 * V_1 ;
T_2 V_11 ;
if ( F_4 ( V_10 ) ) {
F_5 ( V_7 , V_8 , F_6 ( V_10 ) ) ;
V_10 = F_7 ( V_7 , V_8 , V_9 ) ;
V_1 = F_8 ( V_7 , V_8 , V_10 ) ;
if ( V_1 ) {
if ( F_9 ( V_10 ) )
F_10 ( V_1 ) ;
F_11 ( V_5 ) ;
F_12 ( V_5 , F_1 ( V_1 ) ) ;
F_13 ( V_1 ) ;
F_14 ( V_1 ) ;
}
} else {
if ( ! F_15 ( V_10 ) ) {
F_11 ( V_5 ) ;
V_11 = F_16 ( V_10 ) ;
if ( F_17 ( V_11 ) ) {
if ( F_18 ( V_11 ) ) {
V_1 = F_19 ( V_11 ) ;
F_12 ( V_5 , F_1 ( V_1 ) ) ;
}
} else {
F_20 ( V_11 ) ;
F_12 ( V_5 , V_12 ) ;
}
}
F_21 ( V_5 , V_8 , V_9 , 0 ) ;
}
}
static int F_22 ( struct V_4 * V_5 , struct V_6 * V_7 ,
unsigned long V_8 , unsigned long V_13 , T_3 V_14 )
{
int V_15 = - V_16 ;
T_1 * V_10 , V_17 ;
T_4 * V_18 ;
V_10 = F_23 ( V_5 , V_8 , & V_18 ) ;
if ( ! V_10 )
goto V_19;
V_17 = F_24 ( V_13 ) ;
if ( ! F_25 ( * V_10 ) )
F_3 ( V_5 , V_7 , V_8 , V_10 ) ;
F_26 ( V_5 , V_8 , V_10 , F_27 ( V_17 ) ) ;
F_28 ( V_10 , V_18 ) ;
V_15 = 0 ;
V_19:
return V_15 ;
}
int F_29 ( struct V_6 * V_7 , unsigned long V_8 ,
unsigned long V_20 , T_5 V_13 )
{
struct V_4 * V_5 = V_7 -> V_21 ;
int V_15 ;
do {
V_15 = F_22 ( V_5 , V_7 , V_8 , V_13 , V_7 -> V_22 ) ;
if ( V_15 )
return V_15 ;
V_20 -= V_23 ;
V_8 += V_23 ;
V_13 ++ ;
} while ( V_20 );
return 0 ;
}

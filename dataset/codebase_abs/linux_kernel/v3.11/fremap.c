static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , T_1 * V_6 )
{
T_1 V_7 = * V_6 ;
if ( F_2 ( V_7 ) ) {
struct V_8 * V_8 ;
F_3 ( V_4 , V_5 , F_4 ( V_7 ) ) ;
V_7 = F_5 ( V_4 , V_5 , V_6 ) ;
V_8 = F_6 ( V_4 , V_5 , V_7 ) ;
if ( V_8 ) {
if ( F_7 ( V_7 ) )
F_8 ( V_8 ) ;
F_9 ( V_8 ) ;
F_10 ( V_8 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 , V_9 ) ;
}
} else {
if ( ! F_13 ( V_7 ) )
F_14 ( F_15 ( V_7 ) ) ;
F_16 ( V_2 , V_5 , V_6 , 0 ) ;
}
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long V_5 , unsigned long V_10 , T_2 V_11 )
{
int V_12 = - V_13 ;
T_1 * V_7 , V_14 ;
T_3 * V_15 ;
V_7 = F_18 ( V_2 , V_5 , & V_15 ) ;
if ( ! V_7 )
goto V_16;
V_14 = F_19 ( V_10 ) ;
if ( ! F_20 ( * V_7 ) ) {
if ( F_2 ( * V_7 ) && F_21 ( * V_7 ) )
F_22 ( V_14 ) ;
F_1 ( V_2 , V_4 , V_5 , V_7 ) ;
}
F_23 ( V_2 , V_5 , V_7 , V_14 ) ;
F_24 ( V_7 , V_15 ) ;
V_12 = 0 ;
V_16:
return V_12 ;
}
int F_25 ( struct V_3 * V_4 , unsigned long V_5 ,
unsigned long V_17 , T_4 V_10 )
{
struct V_1 * V_2 = V_4 -> V_18 ;
int V_12 ;
do {
V_12 = F_17 ( V_2 , V_4 , V_5 , V_10 , V_4 -> V_19 ) ;
if ( V_12 )
return V_12 ;
V_17 -= V_20 ;
V_5 += V_20 ;
V_10 ++ ;
} while ( V_17 );
return 0 ;
}

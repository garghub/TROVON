int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 , unsigned long V_3 )
{
struct V_4 V_5 ;
T_1 V_6 = F_2 ( V_2 ) ;
unsigned int V_7 , V_8 ;
int V_9 = F_3 ( V_2 ) ;
int V_10 , V_11 ;
V_12:
V_11 = F_4 ( & V_1 -> V_13 , V_2 , V_9 , & V_7 ) ;
if ( V_11 == V_14 ) {
F_5 () ;
goto V_12;
}
if ( F_6 ( ! F_7 ( V_2 ) ) )
goto V_15;
V_5 . V_3 = V_3 ;
F_8 ( & V_5 . V_16 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
void * V_17 = F_9 ( V_2 ) ;
V_5 . V_6 = V_6 + V_10 ;
V_8 = F_10 ( & V_1 -> V_13 , V_7 + V_10 ) ;
F_11 ( & V_1 -> V_13 , V_17 , V_5 , V_8 ) ;
F_12 ( V_2 , V_18 ) ;
}
#ifdef F_13
F_14 ( V_9 , & V_1 -> V_19 ) ;
F_14 ( V_9 , & V_1 -> V_20 ) ;
#endif
V_15:
F_15 ( V_1 ) ;
return V_11 ;
}
int F_16 ( struct V_1 * V_1 , void * V_17 , T_2 * V_21 ,
unsigned int V_9 , unsigned int V_22 ,
struct V_23 * V_24 , unsigned long V_3 )
{
struct V_4 V_5 ;
unsigned int V_7 , V_8 ;
int V_10 , V_25 ;
V_12:
if ( ! F_17 ( & V_1 -> V_13 , V_22 , & V_7 ) ) {
F_5 () ;
goto V_12;
}
V_5 . V_3 = V_3 ;
F_8 ( & V_5 . V_16 ) ;
for ( V_10 = 0 , V_25 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if ( V_21 [ V_10 ] == V_26 )
continue;
V_5 . V_6 = V_21 [ V_10 ] ;
V_8 = F_10 ( & V_1 -> V_13 , V_7 + V_25 ) ;
F_18 ( & V_1 -> V_13 , V_17 , V_5 , V_24 , V_8 ) ;
V_17 += V_18 ;
V_25 ++ ;
}
F_19 ( V_22 != V_25 ,
L_1 ) ;
#ifdef F_13
F_14 ( V_25 , & V_1 -> V_19 ) ;
F_14 ( V_25 , & V_1 -> V_27 ) ;
#endif
F_15 ( V_1 ) ;
return V_28 ;
}

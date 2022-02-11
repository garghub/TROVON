int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 , unsigned long V_3 )
{
struct V_4 V_5 ;
T_1 V_6 = F_2 ( V_2 ) ;
unsigned int V_7 , V_8 ;
int V_9 = F_3 ( V_2 ) ;
int V_10 , V_11 ;
V_12:
V_11 = F_4 ( & V_1 -> V_13 , V_2 , V_9 , & V_7 ) ;
switch ( V_11 ) {
case V_14 :
F_5 () ;
goto V_12;
case V_15 :
F_6 ( V_1 ) ;
goto V_16;
}
if ( F_7 ( ! F_8 ( V_2 ) ) )
goto V_16;
V_5 . V_3 = V_3 ;
F_9 ( & V_5 . V_17 ) ;
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
void * V_18 = F_10 ( V_2 ) ;
V_5 . V_6 = V_6 + V_10 ;
V_8 = F_11 ( & V_1 -> V_13 , V_7 + V_10 ) ;
F_12 ( & V_1 -> V_13 , V_18 , V_5 , V_8 ) ;
F_13 ( V_2 , V_19 ) ;
}
#ifdef F_14
F_15 ( V_9 , & V_1 -> V_20 ) ;
F_15 ( V_9 , & V_1 -> V_21 ) ;
#endif
F_16 ( & V_1 -> V_22 , V_9 ) ;
V_16:
F_17 ( V_1 ) ;
return V_11 ;
}
int F_18 ( struct V_1 * V_1 , void * V_18 , T_2 * V_23 ,
unsigned int V_9 , unsigned int V_24 ,
struct V_25 * V_26 , unsigned long V_3 )
{
struct V_4 V_5 ;
unsigned int V_7 , V_8 ;
int V_10 , V_27 ;
V_12:
if ( ! F_19 ( & V_1 -> V_13 , V_24 , & V_7 ) ) {
F_5 () ;
goto V_12;
}
V_5 . V_3 = V_3 ;
F_9 ( & V_5 . V_17 ) ;
for ( V_10 = 0 , V_27 = 0 ; V_10 < V_9 ; V_10 ++ ) {
if ( V_23 [ V_10 ] == V_28 )
continue;
V_5 . V_6 = V_23 [ V_10 ] ;
V_8 = F_11 ( & V_1 -> V_13 , V_7 + V_27 ) ;
F_20 ( & V_1 -> V_13 , V_18 , V_5 , V_26 , V_8 ) ;
V_18 += V_19 ;
V_27 ++ ;
}
F_21 ( V_24 != V_27 ,
L_1 ) ;
#ifdef F_14
F_15 ( V_27 , & V_1 -> V_20 ) ;
F_15 ( V_27 , & V_1 -> V_29 ) ;
#endif
F_17 ( V_1 ) ;
return V_30 ;
}

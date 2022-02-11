int F_1 ( struct V_1 * V_2 , void * V_3 , int V_4 )
{
struct V_5 V_5 ;
struct V_6 * V_7 ;
char * V_8 ;
int V_9 = 0 , strlen , V_10 = 0 ;
V_7 = F_2 ( & V_2 -> V_11 ) ;
if ( ! V_7 ) {
F_3 ( L_1 , V_12 , F_4 ( & V_2 -> V_11 . V_13 ) ) ;
return - V_14 ;
}
F_5 ( & V_15 -> V_16 -> V_17 ) ;
V_5 . V_18 = F_6 ( V_15 -> V_16 -> V_19 . V_18 ) ;
F_7 ( & V_15 -> V_16 -> V_17 ) ;
V_5 . V_6 = V_7 ;
if ( ! F_8 ( V_7 ) && F_9 ( V_7 ) )
V_10 = 1 ;
V_8 = F_10 ( & V_5 , V_3 , V_4 ) ;
if ( F_11 ( V_8 ) ) {
V_9 = F_12 ( V_8 ) ;
goto V_20;
}
if ( V_10 && V_4 >= V_21 ) {
char * V_22 = V_3 + V_4 - V_21 ;
* V_22 = '\0' ;
}
strlen = V_4 - ( V_8 - ( char * ) V_3 ) ;
memmove ( V_3 , V_8 , strlen ) ;
V_8 = V_3 ;
V_9 = strlen ;
F_13 ( L_2 ,
V_12 , V_7 -> V_23 . V_24 , V_7 -> V_23 . V_4 , V_4 , V_8 , strlen ) ;
V_20:
F_14 ( V_7 ) ;
F_15 ( V_5 . V_18 ) ;
return V_9 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 , * V_19 , * V_25 ;
int V_4 ;
unsigned V_26 ;
V_25 = F_2 ( & V_2 -> V_11 ) ;
if ( ! V_25 ) {
F_13 ( L_3 , V_12 , V_2 -> V_27 , V_2 -> V_11 . V_28 ) ;
return - V_14 ;
}
F_5 ( & V_15 -> V_16 -> V_17 ) ;
V_19 = F_17 ( V_15 -> V_16 -> V_19 . V_6 ) ;
F_7 ( & V_15 -> V_16 -> V_17 ) ;
V_29:
V_4 = 1 ;
V_7 = V_25 ;
V_26 = F_18 ( & V_30 ) ;
F_19 () ;
if ( ! F_8 ( V_7 ) && F_9 ( V_7 ) )
V_4 += V_21 ;
while ( V_7 && V_7 != V_19 && ! F_8 ( V_7 ) ) {
V_4 += V_7 -> V_23 . V_4 + 1 ;
V_7 = V_7 -> V_31 ;
}
F_20 () ;
if ( F_21 ( & V_30 , V_26 ) )
goto V_29;
F_14 ( V_19 ) ;
F_14 ( V_25 ) ;
return V_4 + 1 ;
}

int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 * V_4 ,
T_1 V_5 , int V_6 )
{
int V_7 = ! F_2 ( * V_4 , V_5 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_8 , V_3 , V_4 , V_5 ) ;
F_4 ( V_2 , V_3 ) ;
}
return V_7 ;
}
int F_5 ( struct V_1 * V_2 ,
unsigned long V_3 , T_2 * V_9 ,
T_2 V_5 , int V_6 )
{
#ifdef F_6
int V_7 = ! F_7 ( * V_9 , V_5 ) ;
F_8 ( V_3 & ~ V_10 ) ;
if ( V_7 ) {
F_9 ( V_2 -> V_8 , V_3 , V_9 , V_5 ) ;
F_10 ( V_2 , V_3 , V_3 + V_11 ) ;
}
return V_7 ;
#else
F_11 () ;
return 0 ;
#endif
}
int F_12 ( struct V_1 * V_2 ,
unsigned long V_3 , T_1 * V_4 )
{
int V_12 ;
V_12 = F_13 ( V_2 , V_3 , V_4 ) ;
if ( V_12 )
F_4 ( V_2 , V_3 ) ;
return V_12 ;
}
int F_14 ( struct V_1 * V_2 ,
unsigned long V_3 , T_2 * V_9 )
{
int V_12 ;
#ifdef F_6
F_8 ( V_3 & ~ V_10 ) ;
#else
F_11 () ;
#endif
V_12 = F_15 ( V_2 , V_3 , V_9 ) ;
if ( V_12 )
F_10 ( V_2 , V_3 , V_3 + V_11 ) ;
return V_12 ;
}
T_1 F_16 ( struct V_1 * V_2 , unsigned long V_3 ,
T_1 * V_4 )
{
T_1 V_13 ;
V_13 = F_17 ( ( V_2 ) -> V_8 , V_3 , V_4 ) ;
F_4 ( V_2 , V_3 ) ;
return V_13 ;
}
T_2 F_18 ( struct V_1 * V_2 , unsigned long V_3 ,
T_2 * V_9 )
{
T_2 V_14 ;
F_8 ( V_3 & ~ V_10 ) ;
V_14 = F_19 ( V_2 -> V_8 , V_3 , V_9 ) ;
F_10 ( V_2 , V_3 , V_3 + V_11 ) ;
return V_14 ;
}
void F_20 ( struct V_1 * V_2 , unsigned long V_3 ,
T_2 * V_9 )
{
T_2 V_14 = F_21 ( * V_9 ) ;
F_8 ( V_3 & ~ V_10 ) ;
F_9 ( V_2 -> V_8 , V_3 , V_9 , V_14 ) ;
F_10 ( V_2 , V_3 , V_3 + V_11 ) ;
}
void F_22 ( struct V_15 * V_16 , T_3 V_17 )
{
F_23 ( & V_16 -> V_18 ) ;
if ( ! V_16 -> V_19 )
F_24 ( & V_17 -> V_20 ) ;
else
F_25 ( & V_17 -> V_20 , & V_16 -> V_19 -> V_20 ) ;
V_16 -> V_19 = V_17 ;
}
T_3 F_26 ( struct V_15 * V_16 )
{
T_3 V_17 ;
F_23 ( & V_16 -> V_18 ) ;
V_17 = V_16 -> V_19 ;
if ( F_27 ( & V_17 -> V_20 ) )
V_16 -> V_19 = NULL ;
else {
V_16 -> V_19 = F_28 ( V_17 -> V_20 . V_21 ,
struct V_22 , V_20 ) ;
F_29 ( & V_17 -> V_20 ) ;
}
return V_17 ;
}
void F_30 ( struct V_1 * V_2 , unsigned long V_3 ,
T_2 * V_9 )
{
F_9 ( V_2 -> V_8 , V_3 , V_9 , F_31 ( * V_9 ) ) ;
F_10 ( V_2 , V_3 , V_3 + V_11 ) ;
}

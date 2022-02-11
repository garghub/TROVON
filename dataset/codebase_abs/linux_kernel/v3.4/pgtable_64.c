static void * F_1 ( unsigned long V_1 )
{
void * V_2 ;
if ( V_3 )
V_2 = F_2 ( V_1 , V_1 , F_3 ( V_4 ) ) ;
else
V_2 = F_4 ( F_5 ( V_1 , V_1 ,
F_3 ( V_4 ) ) ) ;
memset ( V_2 , 0 , V_1 ) ;
return V_2 ;
}
int F_6 ( unsigned long V_5 , unsigned long V_6 , int V_7 )
{
T_1 * V_8 ;
T_2 * V_9 ;
T_3 * V_10 ;
T_4 * V_11 ;
if ( F_7 () ) {
V_8 = F_8 ( V_5 ) ;
V_9 = F_9 ( & V_12 , V_8 , V_5 ) ;
if ( ! V_9 )
return - V_13 ;
V_10 = F_10 ( & V_12 , V_9 , V_5 ) ;
if ( ! V_10 )
return - V_13 ;
V_11 = F_11 ( V_10 , V_5 ) ;
if ( ! V_11 )
return - V_13 ;
F_12 ( & V_12 , V_5 , V_11 , F_13 ( V_6 >> V_14 ,
F_14 ( V_7 ) ) ) ;
} else {
#ifdef F_15
V_8 = F_8 ( V_5 ) ;
#ifdef F_16
if ( F_17 ( * V_8 ) ) {
V_9 = F_1 ( F_16 ) ;
F_18 ( V_9 == NULL ) ;
F_19 ( & V_12 , V_8 , V_9 ) ;
}
#endif
V_9 = F_20 ( V_8 , V_5 ) ;
if ( F_21 ( * V_9 ) ) {
V_10 = F_1 ( V_15 ) ;
F_18 ( V_10 == NULL ) ;
F_22 ( & V_12 , V_9 , V_10 ) ;
}
V_10 = F_23 ( V_9 , V_5 ) ;
if ( ! F_24 ( * V_10 ) ) {
V_11 = F_1 ( V_16 ) ;
F_18 ( V_11 == NULL ) ;
F_25 ( & V_12 , V_10 , V_11 ) ;
}
V_11 = F_26 ( V_10 , V_5 ) ;
F_12 ( & V_12 , V_5 , V_11 , F_13 ( V_6 >> V_14 ,
F_14 ( V_7 ) ) ) ;
#else
if ( F_27 ( V_5 , V_5 + V_16 , V_6 , V_7 ,
V_17 , V_18 ) ) {
F_28 ( V_19 L_1
L_2 , V_6 ) ;
return - V_13 ;
}
#endif
}
return 0 ;
}
void T_5 * F_29 ( T_6 V_6 , void * V_5 , unsigned long V_1 ,
unsigned long V_7 )
{
unsigned long V_20 ;
if ( ( V_7 & V_21 ) == 0 )
V_7 |= F_30 ( V_22 ) ;
if ( V_7 & V_23 )
V_7 &= ~ V_24 ;
if ( V_7 & V_25 )
return NULL ;
F_31 ( V_6 & ~ V_26 ) ;
F_31 ( ( ( unsigned long ) V_5 ) & ~ V_26 ) ;
F_31 ( V_1 & ~ V_26 ) ;
for ( V_20 = 0 ; V_20 < V_1 ; V_20 += V_16 )
if ( F_6 ( ( unsigned long ) V_5 + V_20 , V_6 + V_20 , V_7 ) )
return NULL ;
return ( void T_5 * ) V_5 ;
}
void F_32 ( void * V_5 , unsigned long V_1 )
{
F_31 ( ( ( unsigned long ) V_5 ) & ~ V_26 ) ;
F_31 ( V_1 & ~ V_26 ) ;
F_33 ( ( unsigned long ) V_5 , V_1 ) ;
}
void T_5 * F_34 ( T_6 V_27 , unsigned long V_1 ,
unsigned long V_7 , void * V_28 )
{
T_6 V_29 ;
void T_5 * V_30 ;
V_29 = V_27 & V_26 ;
V_1 = F_35 ( V_27 + V_1 ) - V_29 ;
if ( ( V_1 == 0 ) || ( V_29 == 0 ) )
return NULL ;
if ( V_31 ) {
struct V_32 * V_33 ;
V_33 = F_36 ( V_1 , V_34 ,
V_35 , V_36 ,
V_28 ) ;
if ( V_33 == NULL )
return NULL ;
V_33 -> V_37 = V_29 ;
V_30 = F_29 ( V_29 , V_33 -> V_27 , V_1 , V_7 ) ;
if ( ! V_30 )
F_37 ( V_33 -> V_27 ) ;
} else {
V_30 = F_29 ( V_29 , ( void * ) V_35 , V_1 , V_7 ) ;
if ( V_30 )
V_35 += V_1 ;
}
if ( V_30 )
V_30 += V_27 & ~ V_26 ;
return V_30 ;
}
void T_5 * F_38 ( T_6 V_27 , unsigned long V_1 ,
unsigned long V_7 )
{
return F_34 ( V_27 , V_1 , V_7 , F_39 ( 0 ) ) ;
}
void T_5 * F_40 ( T_6 V_27 , unsigned long V_1 )
{
unsigned long V_7 = V_23 | V_38 ;
void * V_28 = F_39 ( 0 ) ;
if ( V_39 . F_40 )
return V_39 . F_40 ( V_27 , V_1 , V_7 , V_28 ) ;
return F_34 ( V_27 , V_1 , V_7 , V_28 ) ;
}
void T_5 * F_41 ( T_6 V_27 , unsigned long V_1 )
{
unsigned long V_7 = V_23 ;
void * V_28 = F_39 ( 0 ) ;
if ( V_39 . F_40 )
return V_39 . F_40 ( V_27 , V_1 , V_7 , V_28 ) ;
return F_34 ( V_27 , V_1 , V_7 , V_28 ) ;
}
void T_5 * F_42 ( T_6 V_27 , unsigned long V_1 ,
unsigned long V_7 )
{
void * V_28 = F_39 ( 0 ) ;
if ( V_7 & V_40 )
V_7 |= V_41 ;
V_7 &= ~ ( V_42 | V_43 ) ;
#ifdef F_43
V_7 |= F_43 ;
#endif
if ( V_39 . F_40 )
return V_39 . F_40 ( V_27 , V_1 , V_7 , V_28 ) ;
return F_34 ( V_27 , V_1 , V_7 , V_28 ) ;
}
void F_44 ( volatile void T_5 * V_44 )
{
void * V_27 ;
if ( ! V_31 )
return;
V_27 = ( void * ) ( ( unsigned long V_45 )
F_45 ( V_44 ) & V_26 ) ;
if ( ( unsigned long ) V_27 < V_35 ) {
F_28 ( V_46 L_3
L_4 , V_27 ) ;
return;
}
F_37 ( V_27 ) ;
}
void F_46 ( volatile void T_5 * V_44 )
{
if ( V_39 . F_46 )
V_39 . F_46 ( V_44 ) ;
else
F_44 ( V_44 ) ;
}

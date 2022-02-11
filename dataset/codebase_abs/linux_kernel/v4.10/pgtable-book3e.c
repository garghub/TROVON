int T_1 F_1 ( unsigned long V_1 ,
unsigned long V_2 ,
unsigned long V_3 )
{
unsigned long V_4 , V_5 = V_6 | V_7 |
V_8 ;
F_2 ( V_9 [ V_10 ] . V_11 > 0xf ) ;
V_5 |= V_9 [ V_10 ] . V_11 << 8 ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 += V_12 )
F_2 ( F_3 ( V_1 + V_4 , V_3 , V_5 ) ) ;
return 0 ;
}
void F_4 ( unsigned long V_1 ,
unsigned long V_2 )
{
}
static T_2 void * F_5 ( unsigned long V_13 )
{
void * V_14 ;
V_14 = F_6 ( F_7 ( V_13 , V_13 , F_8 ( V_15 ) ) ) ;
memset ( V_14 , 0 , V_13 ) ;
return V_14 ;
}
int F_3 ( unsigned long V_16 , unsigned long V_17 , unsigned long V_5 )
{
T_3 * V_18 ;
T_4 * V_19 ;
T_5 * V_20 ;
T_6 * V_21 ;
F_9 ( V_22 > V_23 ) ;
if ( F_10 () ) {
V_18 = F_11 ( V_16 ) ;
V_19 = F_12 ( & V_24 , V_18 , V_16 ) ;
if ( ! V_19 )
return - V_25 ;
V_20 = F_13 ( & V_24 , V_19 , V_16 ) ;
if ( ! V_20 )
return - V_25 ;
V_21 = F_14 ( V_20 , V_16 ) ;
if ( ! V_21 )
return - V_25 ;
F_15 ( & V_24 , V_16 , V_21 , F_16 ( V_17 >> V_26 ,
F_17 ( V_5 ) ) ) ;
} else {
V_18 = F_11 ( V_16 ) ;
#ifndef F_18
if ( F_19 ( * V_18 ) ) {
V_19 = F_5 ( V_27 ) ;
F_2 ( V_19 == NULL ) ;
F_20 ( & V_24 , V_18 , V_19 ) ;
}
#endif
V_19 = F_21 ( V_18 , V_16 ) ;
if ( F_22 ( * V_19 ) ) {
V_20 = F_5 ( V_28 ) ;
F_2 ( V_20 == NULL ) ;
F_23 ( & V_24 , V_19 , V_20 ) ;
}
V_20 = F_24 ( V_19 , V_16 ) ;
if ( ! F_25 ( * V_20 ) ) {
V_21 = F_5 ( V_12 ) ;
F_2 ( V_21 == NULL ) ;
F_26 ( & V_24 , V_20 , V_21 ) ;
}
V_21 = F_27 ( V_20 , V_16 ) ;
F_15 ( & V_24 , V_16 , V_21 , F_16 ( V_17 >> V_26 ,
F_17 ( V_5 ) ) ) ;
}
F_28 () ;
return 0 ;
}

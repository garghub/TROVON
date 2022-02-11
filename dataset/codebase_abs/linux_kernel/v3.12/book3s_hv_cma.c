long T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
long V_3 ;
T_2 V_4 ;
struct V_5 * V_6 = & V_7 ;
F_2 ( L_1 , V_8 , ( unsigned long ) V_1 ) ;
if ( ! V_1 )
return - V_9 ;
V_2 = F_3 ( V_2 , ( T_2 ) ( V_10 << V_11 ) ) ;
V_1 = F_4 ( V_1 , V_2 ) ;
V_4 = F_5 ( V_1 , V_2 , 0 ) ;
if ( ! V_4 ) {
V_3 = - V_12 ;
goto V_13;
} else
V_3 = F_6 ( V_4 ) ;
V_6 -> V_3 = V_3 ;
V_6 -> V_14 = V_1 >> V_15 ;
F_7 ( L_2 , ( unsigned long ) V_1 / V_16 ) ;
return 0 ;
V_13:
F_8 ( L_3 , ( unsigned long ) V_1 / V_16 ) ;
return V_3 ;
}
struct V_17 * F_9 ( unsigned long V_18 , unsigned long V_19 )
{
int V_20 ;
struct V_17 * V_17 = NULL ;
struct V_5 * V_6 = & V_7 ;
unsigned long V_21 , V_22 ;
unsigned long V_23 , V_24 , V_25 , V_26 = 0 ;
if ( ! V_6 || ! V_6 -> V_14 )
return NULL ;
F_2 ( L_4 , V_8 ,
( void * ) V_6 , V_18 , V_19 ) ;
if ( ! V_18 )
return NULL ;
F_10 ( ! F_11 ( V_19 ) ) ;
V_23 = ( V_19 >> ( V_27 - V_15 ) ) - 1 ;
F_12 ( V_15 > V_27 ) ;
V_21 = V_6 -> V_14 >> ( V_27 - V_15 ) ;
V_22 = V_18 >> ( V_27 - V_15 ) ;
F_13 ( & V_28 ) ;
for (; ; ) {
V_25 = F_14 ( V_6 -> V_29 , V_21 ,
V_26 , V_22 , V_23 ) ;
if ( V_25 >= V_21 )
break;
V_24 = V_6 -> V_3 + ( V_25 << ( V_27 - V_15 ) ) ;
V_20 = F_15 ( V_24 , V_24 + V_18 , V_30 ) ;
if ( V_20 == 0 ) {
F_16 ( V_6 -> V_29 , V_25 , V_22 ) ;
V_17 = F_17 ( V_24 ) ;
memset ( F_18 ( V_24 ) , 0 , V_18 << V_15 ) ;
break;
} else if ( V_20 != - V_31 ) {
break;
}
F_2 ( L_5 ,
V_8 , F_17 ( V_24 ) ) ;
V_26 = V_25 + V_23 + 1 ;
}
F_19 ( & V_28 ) ;
F_2 ( L_6 , V_8 , V_17 ) ;
return V_17 ;
}
bool F_20 ( struct V_17 * V_32 , unsigned long V_18 )
{
unsigned long V_24 ;
unsigned long V_22 ;
struct V_5 * V_6 = & V_7 ;
if ( ! V_6 || ! V_32 )
return false ;
F_2 ( L_7 , V_8 , ( void * ) V_32 , V_18 ) ;
V_24 = F_21 ( V_32 ) ;
if ( V_24 < V_6 -> V_3 || V_24 >= V_6 -> V_3 + V_6 -> V_14 )
return false ;
F_10 ( V_24 + V_18 > V_6 -> V_3 + V_6 -> V_14 ) ;
V_22 = V_18 >> ( V_27 - V_15 ) ;
F_13 ( & V_28 ) ;
F_22 ( V_6 -> V_29 ,
( V_24 - V_6 -> V_3 ) >> ( V_27 - V_15 ) ,
V_22 ) ;
F_23 ( V_24 , V_18 ) ;
F_19 ( & V_28 ) ;
return true ;
}
static int T_1 F_24 ( unsigned long V_3 ,
unsigned long V_14 )
{
unsigned long V_24 = V_3 ;
unsigned V_33 = V_14 >> V_11 ;
struct V_34 * V_34 ;
F_25 ( ! F_26 ( V_24 ) ) ;
V_34 = F_27 ( F_17 ( V_24 ) ) ;
do {
unsigned V_35 ;
V_3 = V_24 ;
for ( V_35 = V_36 ; V_35 ; -- V_35 , V_24 ++ ) {
F_25 ( ! F_26 ( V_24 ) ) ;
if ( F_27 ( F_17 ( V_24 ) ) != V_34 )
return - V_9 ;
}
F_28 ( F_17 ( V_3 ) ) ;
} while ( -- V_33 );
return 0 ;
}
static int T_1 F_29 ( void )
{
int V_37 , V_20 ;
unsigned long V_21 ;
struct V_5 * V_6 = & V_7 ;
F_2 ( L_8 , V_8 ) ;
if ( ! V_6 -> V_14 )
return 0 ;
V_21 = V_6 -> V_14 >> ( V_27 - V_15 ) ;
V_37 = F_30 ( V_21 ) * sizeof( long ) ;
V_6 -> V_29 = F_31 ( V_37 , V_38 ) ;
if ( ! V_6 -> V_29 )
return - V_12 ;
V_20 = F_24 ( V_6 -> V_3 , V_6 -> V_14 ) ;
if ( V_20 )
goto error;
return 0 ;
error:
F_32 ( V_6 -> V_29 ) ;
return V_20 ;
}

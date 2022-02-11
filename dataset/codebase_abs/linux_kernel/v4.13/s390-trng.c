static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
static T_1 F_3 ( struct V_2 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
T_5 V_6 [ 32 ] ;
T_5 * V_7 = V_6 ;
unsigned int V_8 ;
T_1 V_9 = 0 ;
if ( V_4 > sizeof( V_6 ) ) {
V_7 = ( T_5 * ) F_4 ( V_10 ) ;
if ( ! V_7 )
return - V_11 ;
}
while ( V_4 ) {
if ( F_5 () ) {
if ( F_6 ( V_12 ) ) {
if ( V_9 == 0 )
V_9 = - V_13 ;
break;
}
F_7 () ;
}
V_8 = V_4 > V_14 ? V_14 : V_4 ;
F_8 ( NULL , 0 , V_7 , V_8 ) ;
F_9 ( V_8 , & V_15 ) ;
if ( F_10 ( V_3 , V_7 , V_8 ) ) {
V_9 = - V_16 ;
break;
}
V_4 -= V_8 ;
V_3 += V_8 ;
V_9 += V_8 ;
}
if ( V_7 != V_6 )
F_11 ( ( unsigned long ) V_7 ) ;
F_12 ( L_1 , V_9 ) ;
return V_9 ;
}
static T_1 F_13 ( struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_6 )
{
T_6 V_21 = F_14 ( & V_15 ) ;
T_6 V_22 = F_14 ( & V_23 ) ;
#if F_15 ( V_24 )
T_6 V_25 = F_14 ( & V_26 ) ;
return snprintf ( V_6 , V_14 ,
L_2
L_3
L_4
L_5 ,
V_21 , V_22 , V_25 ,
V_21 + V_22 + V_25 ) ;
#else
return snprintf ( V_6 , V_14 ,
L_2
L_3
L_5 ,
V_21 , V_22 ,
V_21 + V_22 ) ;
#endif
}
static inline void F_16 ( T_5 * V_6 , T_3 V_27 )
{
F_8 ( NULL , 0 , V_6 , V_27 ) ;
F_9 ( V_27 , & V_23 ) ;
}
static int F_17 ( struct V_28 * V_29 , T_7 * V_30 )
{
T_3 V_27 = sizeof( * V_30 ) ;
F_16 ( ( T_5 * ) V_30 , V_27 ) ;
F_12 ( L_6 , V_27 ) ;
return V_27 ;
}
static int F_18 ( struct V_28 * V_29 , void * V_30 , T_3 V_31 , bool V_32 )
{
T_3 V_27 = V_31 <= V_14 ? V_31 : V_14 ;
F_16 ( ( T_5 * ) V_30 , V_27 ) ;
F_12 ( L_7 , V_27 ) ;
return V_27 ;
}
static void T_8 F_19 ( void )
{
V_33 = F_20 ( L_8 , 1 , 1 , 4 * sizeof( long ) ) ;
F_21 ( V_33 , & V_34 ) ;
F_22 ( V_33 , 3 ) ;
}
static void F_23 ( void )
{
F_24 ( V_33 ) ;
}
static int T_8 F_25 ( void )
{
int V_9 ;
F_19 () ;
if ( ! F_26 ( V_35 , V_36 ) ) {
F_27 ( L_9 ) ;
V_9 = - V_37 ;
goto V_38;
}
V_9 = F_28 ( & V_39 ) ;
if ( V_9 ) {
F_29 ( L_10 , V_9 ) ;
goto V_38;
}
V_9 = F_30 ( & V_40 ) ;
if ( V_9 ) {
F_29 ( L_11 , V_9 ) ;
goto V_41;
}
F_12 ( L_12 ) ;
return 0 ;
V_41:
F_31 ( & V_39 ) ;
V_38:
F_23 () ;
return V_9 ;
}
static void T_9 F_32 ( void )
{
F_33 ( & V_40 ) ;
F_31 ( & V_39 ) ;
F_23 () ;
}

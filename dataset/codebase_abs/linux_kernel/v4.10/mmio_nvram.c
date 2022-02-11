static T_1 F_1 ( char * V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned long V_4 ;
if ( * V_3 >= V_5 )
return 0 ;
if ( * V_3 + V_2 > V_5 )
V_2 = V_5 - * V_3 ;
F_2 ( & V_6 , V_4 ) ;
F_3 ( V_1 , V_7 + * V_3 , V_2 ) ;
F_4 ( & V_6 , V_4 ) ;
* V_3 += V_2 ;
return V_2 ;
}
static unsigned char F_5 ( int V_8 )
{
unsigned long V_4 ;
unsigned char V_9 ;
if ( V_8 >= V_5 )
return 0xff ;
F_2 ( & V_6 , V_4 ) ;
V_9 = F_6 ( V_7 + V_8 ) ;
F_4 ( & V_6 , V_4 ) ;
return V_9 ;
}
static T_1 F_7 ( char * V_1 , T_2 V_2 , T_3 * V_3 )
{
unsigned long V_4 ;
if ( * V_3 >= V_5 )
return 0 ;
if ( * V_3 + V_2 > V_5 )
V_2 = V_5 - * V_3 ;
F_2 ( & V_6 , V_4 ) ;
F_8 ( V_7 + * V_3 , V_1 , V_2 ) ;
F_4 ( & V_6 , V_4 ) ;
* V_3 += V_2 ;
return V_2 ;
}
static void F_9 ( int V_8 , unsigned char V_9 )
{
unsigned long V_4 ;
if ( V_8 < V_5 ) {
F_2 ( & V_6 , V_4 ) ;
F_10 ( V_9 , V_7 + V_8 ) ;
F_4 ( & V_6 , V_4 ) ;
}
}
static T_1 F_11 ( void )
{
return V_5 ;
}
int T_4 F_12 ( void )
{
struct V_10 * V_11 ;
unsigned long V_12 ;
struct V_13 V_14 ;
int V_15 ;
V_11 = F_13 ( NULL , L_1 ) ;
if ( ! V_11 )
V_11 = F_14 ( NULL , NULL , L_1 ) ;
if ( ! V_11 ) {
F_15 ( V_16 L_2 ) ;
return - V_17 ;
}
V_15 = F_16 ( V_11 , 0 , & V_14 ) ;
if ( V_15 ) {
F_15 ( V_16 L_3 ,
V_15 ) ;
goto V_18;
}
V_12 = V_14 . V_19 ;
V_5 = F_17 ( & V_14 ) ;
if ( ( ! V_5 ) || ( ! V_12 ) ) {
F_15 ( V_16 L_4 ) ;
V_15 = - V_20 ;
goto V_18;
}
V_7 = F_18 ( V_12 , V_5 ) ;
if ( ! V_7 ) {
F_15 ( V_16 L_5 ) ;
V_15 = - V_21 ;
goto V_18;
}
F_15 ( V_22 L_6 ,
V_5 >> 10 , V_12 , V_7 ) ;
V_23 . V_24 = F_5 ;
V_23 . V_25 = F_9 ;
V_23 . V_26 = F_1 ;
V_23 . V_27 = F_7 ;
V_23 . V_28 = F_11 ;
V_18:
F_19 ( V_11 ) ;
return V_15 ;
}

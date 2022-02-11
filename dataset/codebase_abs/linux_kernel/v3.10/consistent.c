static int T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
return 0 ;
}
void * F_3 ( struct V_2 * V_3 , T_2 V_4 ,
T_3 * V_5 , T_4 V_6 ,
struct V_7 * V_8 )
{
void * V_9 , * V_10 ;
int V_11 = F_4 ( V_4 ) ;
V_6 |= V_12 ;
V_9 = ( void * ) F_5 ( V_6 , V_11 ) ;
if ( ! V_9 )
return NULL ;
F_6 ( V_3 , V_9 , V_4 , V_13 ) ;
V_10 = ( void V_14 * ) F_7 ( F_8 ( V_9 ) , V_4 ) ;
if ( ! V_10 ) {
F_9 ( ( unsigned long ) V_9 , V_11 ) ;
return NULL ;
}
F_10 ( F_11 ( F_8 ( V_9 ) >> V_15 ) , V_11 ) ;
* V_5 = F_8 ( V_9 ) ;
return V_10 ;
}
void F_12 ( struct V_2 * V_3 , T_2 V_4 ,
void * V_16 , T_3 V_5 ,
struct V_7 * V_8 )
{
int V_11 = F_4 ( V_4 ) ;
unsigned long V_17 = V_5 >> V_15 ;
int V_18 ;
for ( V_18 = 0 ; V_18 < ( 1 << V_11 ) ; V_18 ++ )
F_13 ( F_11 ( V_17 + V_18 ) , 0 ) ;
F_14 ( V_16 ) ;
}
void F_6 ( struct V_2 * V_3 , void * V_16 , T_2 V_4 ,
enum V_19 V_20 )
{
void * V_21 ;
V_21 = F_15 () ?
( void * ) F_16 ( ( unsigned long ) V_16 ) : V_16 ;
switch ( V_20 ) {
case V_22 :
F_17 ( V_21 , V_4 ) ;
break;
case V_23 :
F_18 ( V_21 , V_4 ) ;
break;
case V_13 :
F_19 ( V_21 , V_4 ) ;
break;
default:
F_20 () ;
}
}
static int T_1 F_21 ( char * V_24 )
{
return 1 ;
}
static void T_1 F_22 ( char * V_25 , unsigned long * V_26 )
{
char * V_27 = V_28 ;
int V_18 = strlen ( V_25 ) ;
while ( ( V_27 = strstr ( V_27 , L_1 ) ) ) {
V_27 += 9 ;
if ( ! strncmp ( V_25 , V_27 , V_18 ) && V_27 [ V_18 ] == '=' ) {
V_27 += V_18 + 1 ;
* V_26 = F_23 ( V_27 , NULL ) ;
F_24 ( L_2 ,
V_25 , * V_26 ) ;
break;
}
}
}
int T_1 F_25 ( struct V_29 * V_30 ,
char * V_25 , unsigned long V_31 )
{
struct V_32 * V_33 ;
T_3 V_5 ;
void * V_34 ;
V_33 = V_30 -> V_32 + V_30 -> V_35 - 1 ;
if ( V_33 -> V_36 ) {
F_26 ( L_3 ,
V_25 ) ;
return - V_37 ;
}
F_22 ( V_25 , & V_31 ) ;
if ( ! V_31 )
return 0 ;
V_34 = F_27 ( NULL , V_31 , & V_5 , V_38 ) ;
if ( ! V_34 ) {
F_26 ( L_4 , V_25 ) ;
return - V_39 ;
}
memset ( V_34 , 0 , V_31 ) ;
V_33 -> V_36 = V_40 ;
V_33 -> V_41 = V_5 ;
V_33 -> V_42 = V_33 -> V_41 + V_31 - 1 ;
V_33 -> V_25 = V_25 ;
return 0 ;
}

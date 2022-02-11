static int T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
return 0 ;
}
void * F_3 ( struct V_2 * V_3 , T_2 V_4 ,
T_3 * V_5 , T_4 V_6 )
{
void * V_7 , * V_8 ;
int V_9 = F_4 ( V_4 ) ;
V_6 |= V_10 ;
V_7 = ( void * ) F_5 ( V_6 , V_9 ) ;
if ( ! V_7 )
return NULL ;
F_6 ( V_3 , V_7 , V_4 , V_11 ) ;
V_8 = ( void V_12 * ) F_7 ( F_8 ( V_7 ) , V_4 ) ;
if ( ! V_8 ) {
F_9 ( ( unsigned long ) V_7 , V_9 ) ;
return NULL ;
}
F_10 ( F_11 ( F_8 ( V_7 ) >> V_13 ) , V_9 ) ;
* V_5 = F_8 ( V_7 ) ;
return V_8 ;
}
void F_12 ( struct V_2 * V_3 , T_2 V_4 ,
void * V_14 , T_3 V_5 )
{
int V_9 = F_4 ( V_4 ) ;
unsigned long V_15 = V_5 >> V_13 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < ( 1 << V_9 ) ; V_16 ++ )
F_13 ( F_11 ( V_15 + V_16 ) , 0 ) ;
F_14 ( V_14 ) ;
}
void F_6 ( struct V_2 * V_3 , void * V_14 , T_2 V_4 ,
enum V_17 V_18 )
{
void * V_19 ;
V_19 = F_15 () ?
( void * ) F_16 ( ( unsigned long ) V_14 ) : V_14 ;
switch ( V_18 ) {
case V_20 :
F_17 ( V_19 , V_4 ) ;
break;
case V_21 :
F_18 ( V_19 , V_4 ) ;
break;
case V_11 :
F_19 ( V_19 , V_4 ) ;
break;
default:
F_20 () ;
}
}
static int T_1 F_21 ( char * V_22 )
{
return 1 ;
}
static void T_1 F_22 ( char * V_23 , unsigned long * V_24 )
{
char * V_25 = V_26 ;
int V_16 = strlen ( V_23 ) ;
while ( ( V_25 = strstr ( V_25 , L_1 ) ) ) {
V_25 += 9 ;
if ( ! strncmp ( V_23 , V_25 , V_16 ) && V_25 [ V_16 ] == '=' ) {
V_25 += V_16 + 1 ;
* V_24 = F_23 ( V_25 , NULL ) ;
F_24 ( L_2 ,
V_23 , * V_24 ) ;
break;
}
}
}
int T_1 F_25 ( struct V_27 * V_28 ,
char * V_23 , unsigned long V_29 )
{
struct V_30 * V_31 ;
T_3 V_5 ;
void * V_32 ;
V_31 = V_28 -> V_30 + V_28 -> V_33 - 1 ;
if ( V_31 -> V_34 ) {
F_26 ( L_3 ,
V_23 ) ;
return - V_35 ;
}
F_22 ( V_23 , & V_29 ) ;
if ( ! V_29 )
return 0 ;
V_32 = F_27 ( NULL , V_29 , & V_5 , V_36 ) ;
if ( ! V_32 ) {
F_26 ( L_4 , V_23 ) ;
return - V_37 ;
}
memset ( V_32 , 0 , V_29 ) ;
V_31 -> V_34 = V_38 ;
V_31 -> V_39 = V_5 ;
V_31 -> V_40 = V_31 -> V_39 + V_29 - 1 ;
V_31 -> V_23 = V_23 ;
return 0 ;
}

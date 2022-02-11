static int T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
return 0 ;
}
void * F_3 ( struct V_2 * V_3 , T_2 V_4 ,
T_3 * V_5 , T_4 V_6 ,
unsigned long V_7 )
{
void * V_8 , * V_9 ;
int V_10 = F_4 ( V_4 ) ;
V_6 |= V_11 ;
V_8 = ( void * ) F_5 ( V_6 , V_10 ) ;
if ( ! V_8 )
return NULL ;
F_6 ( V_3 , V_8 , V_4 , V_12 ) ;
V_9 = ( void V_13 * ) F_7 ( F_8 ( V_8 ) , V_4 ) ;
if ( ! V_9 ) {
F_9 ( ( unsigned long ) V_8 , V_10 ) ;
return NULL ;
}
F_10 ( F_11 ( F_8 ( V_8 ) >> V_14 ) , V_10 ) ;
* V_5 = F_8 ( V_8 ) ;
return V_9 ;
}
void F_12 ( struct V_2 * V_3 , T_2 V_4 ,
void * V_15 , T_3 V_5 ,
unsigned long V_7 )
{
int V_10 = F_4 ( V_4 ) ;
unsigned long V_16 = V_5 >> V_14 ;
int V_17 ;
for ( V_17 = 0 ; V_17 < ( 1 << V_10 ) ; V_17 ++ )
F_13 ( F_11 ( V_16 + V_17 ) , 0 ) ;
F_14 ( V_15 ) ;
}
void F_6 ( struct V_2 * V_3 , void * V_15 , T_2 V_4 ,
enum V_18 V_19 )
{
void * V_20 ;
V_20 = F_15 () ?
( void * ) F_16 ( ( unsigned long ) V_15 ) : V_15 ;
switch ( V_19 ) {
case V_21 :
F_17 ( V_20 , V_4 ) ;
break;
case V_22 :
F_18 ( V_20 , V_4 ) ;
break;
case V_12 :
F_19 ( V_20 , V_4 ) ;
break;
default:
F_20 () ;
}
}
static int T_1 F_21 ( char * V_23 )
{
return 1 ;
}
static void T_1 F_22 ( char * V_24 , unsigned long * V_25 )
{
char * V_26 = V_27 ;
int V_17 = strlen ( V_24 ) ;
while ( ( V_26 = strstr ( V_26 , L_1 ) ) ) {
V_26 += 9 ;
if ( ! strncmp ( V_24 , V_26 , V_17 ) && V_26 [ V_17 ] == '=' ) {
V_26 += V_17 + 1 ;
* V_25 = F_23 ( V_26 , NULL ) ;
F_24 ( L_2 ,
V_24 , * V_25 ) ;
break;
}
}
}
int T_1 F_25 ( struct V_28 * V_29 ,
char * V_24 , unsigned long V_30 )
{
struct V_31 * V_32 ;
T_3 V_5 ;
void * V_33 ;
V_32 = V_29 -> V_31 + V_29 -> V_34 - 1 ;
if ( V_32 -> V_35 ) {
F_26 ( L_3 ,
V_24 ) ;
return - V_36 ;
}
F_22 ( V_24 , & V_30 ) ;
if ( ! V_30 )
return 0 ;
V_33 = F_27 ( NULL , V_30 , & V_5 , V_37 ) ;
if ( ! V_33 ) {
F_26 ( L_4 , V_24 ) ;
return - V_38 ;
}
memset ( V_33 , 0 , V_30 ) ;
V_32 -> V_35 = V_39 ;
V_32 -> V_40 = V_5 ;
V_32 -> V_41 = V_32 -> V_40 + V_30 - 1 ;
V_32 -> V_24 = V_24 ;
return 0 ;
}

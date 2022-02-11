void F_1 ( enum V_1 type , const char * * V_2 , const char * * V_3 )
{
switch ( type ) {
case V_4 :
case V_5 :
* V_2 = L_1 ;
* V_3 = L_2 ;
break;
default:
* V_2 = NULL ;
* V_3 = NULL ;
}
}
static bool F_2 ( unsigned long * V_6 , struct V_7 * V_8 )
{
unsigned long * V_2 = ( unsigned long * ) F_3 ( V_9 ) ;
unsigned long * V_3 = V_2 + ( V_10 / sizeof( long ) ) ;
if ( V_6 < V_2 || V_6 > V_3 )
return false ;
V_8 -> type = V_4 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_11 = ( unsigned long * ) * V_2 ;
return true ;
}
static bool F_4 ( unsigned long * V_6 , struct V_7 * V_8 )
{
unsigned long * V_2 = ( unsigned long * ) F_3 ( V_12 ) ;
unsigned long * V_3 = V_2 + ( V_10 / sizeof( long ) ) ;
if ( V_6 < V_2 || V_6 > V_3 )
return false ;
V_8 -> type = V_5 ;
V_8 -> V_2 = V_2 ;
V_8 -> V_3 = V_3 ;
V_8 -> V_11 = ( unsigned long * ) * V_2 ;
return true ;
}
int F_5 ( unsigned long * V_6 , struct V_13 * V_14 ,
struct V_7 * V_8 , unsigned long * V_15 )
{
if ( ! V_6 )
goto V_16;
V_14 = V_14 ? : V_17 ;
if ( F_6 ( V_6 , V_14 , V_8 ) )
goto V_18;
if ( V_14 != V_17 )
goto V_16;
if ( F_2 ( V_6 , V_8 ) )
goto V_18;
if ( F_4 ( V_6 , V_8 ) )
goto V_18;
goto V_16;
V_18:
if ( V_15 ) {
if ( * V_15 & ( 1UL << V_8 -> type ) )
goto V_16;
* V_15 |= 1UL << V_8 -> type ;
}
return 0 ;
V_16:
V_8 -> type = V_19 ;
return - V_20 ;
}
void F_7 ( struct V_13 * V_14 , struct V_21 * V_22 ,
unsigned long * V_23 , char * V_24 )
{
unsigned long * V_6 ;
int V_25 ;
if ( ! F_8 ( V_14 ) )
return;
V_23 = V_23 ? : F_9 ( V_14 , V_22 ) ;
V_6 = V_23 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
if ( F_10 ( V_6 ) )
break;
if ( ( V_25 % V_27 ) == 0 ) {
if ( V_25 != 0 )
F_11 ( L_3 ) ;
F_12 ( L_4 , V_24 , * V_6 ++ ) ;
} else
F_11 ( L_5 , * V_6 ++ ) ;
F_13 () ;
}
F_11 ( L_3 ) ;
F_14 ( V_14 , V_22 , V_23 , V_24 ) ;
F_15 ( V_14 ) ;
}
void F_16 ( struct V_21 * V_22 )
{
int V_25 ;
F_17 ( V_28 ) ;
F_18 ( V_22 , ! F_19 ( V_22 ) ) ;
if ( ! F_19 ( V_22 ) ) {
unsigned int V_29 = V_30 * 43 / 64 ;
unsigned int V_31 = V_30 ;
unsigned char V_32 ;
T_1 * V_33 ;
F_20 ( L_6 ) ;
F_7 ( V_17 , V_22 , NULL , V_28 ) ;
F_20 ( L_7 ) ;
V_33 = ( T_1 * ) V_22 -> V_33 - V_29 ;
if ( V_33 < ( T_1 * ) V_34 || F_21 ( V_33 , V_32 ) ) {
V_33 = ( T_1 * ) V_22 -> V_33 ;
V_31 = V_31 - V_29 + 1 ;
}
for ( V_25 = 0 ; V_25 < V_31 ; V_25 ++ , V_33 ++ ) {
if ( V_33 < ( T_1 * ) V_34 ||
F_21 ( V_33 , V_32 ) ) {
F_11 ( L_8 ) ;
break;
}
if ( V_33 == ( T_1 * ) V_22 -> V_33 )
F_11 ( L_9 , V_32 ) ;
else
F_11 ( L_10 , V_32 ) ;
}
}
F_11 ( L_3 ) ;
}
int F_22 ( unsigned long V_33 )
{
unsigned short V_35 ;
if ( V_33 < V_34 )
return 0 ;
if ( F_21 ( ( unsigned short * ) V_33 , V_35 ) )
return 0 ;
return V_35 == 0x0b0f ;
}

const char * F_1 ( enum V_1 type )
{
if ( type == V_2 )
return L_1 ;
if ( type == V_3 )
return L_2 ;
return NULL ;
}
static bool F_2 ( unsigned long * V_4 , struct V_5 * V_6 )
{
unsigned long * V_7 = ( unsigned long * ) F_3 ( V_8 ) ;
unsigned long * V_9 = V_7 + ( V_10 / sizeof( long ) ) ;
if ( V_4 <= V_7 || V_4 > V_9 )
return false ;
V_6 -> type = V_2 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_11 = ( unsigned long * ) * V_7 ;
return true ;
}
static bool F_4 ( unsigned long * V_4 , struct V_5 * V_6 )
{
unsigned long * V_7 = ( unsigned long * ) F_3 ( V_12 ) ;
unsigned long * V_9 = V_7 + ( V_10 / sizeof( long ) ) ;
if ( V_4 <= V_7 || V_4 > V_9 )
return false ;
V_6 -> type = V_3 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_11 = ( unsigned long * ) * V_7 ;
return true ;
}
int F_5 ( unsigned long * V_4 , struct V_13 * V_14 ,
struct V_5 * V_6 , unsigned long * V_15 )
{
if ( ! V_4 )
goto V_16;
V_14 = V_14 ? : V_17 ;
if ( F_6 ( V_4 , V_14 , V_6 ) )
goto V_18;
if ( V_14 != V_17 )
goto V_16;
if ( F_2 ( V_4 , V_6 ) )
goto V_18;
if ( F_4 ( V_4 , V_6 ) )
goto V_18;
goto V_16;
V_18:
if ( V_15 ) {
if ( * V_15 & ( 1UL << V_6 -> type ) ) {
F_7 ( V_19 L_3 , V_6 -> type ) ;
goto V_16;
}
* V_15 |= 1UL << V_6 -> type ;
}
return 0 ;
V_16:
V_6 -> type = V_20 ;
return - V_21 ;
}
void F_8 ( struct V_22 * V_23 )
{
int V_24 ;
F_9 ( V_25 ) ;
F_10 ( V_23 , ! F_11 ( V_23 ) ) ;
if ( ! F_11 ( V_23 ) ) {
unsigned int V_26 = V_27 * 43 / 64 ;
unsigned int V_28 = V_27 ;
unsigned char V_29 ;
T_1 * V_30 ;
F_12 ( V_17 , V_23 , NULL , V_25 ) ;
F_13 ( L_4 ) ;
V_30 = ( T_1 * ) V_23 -> V_30 - V_26 ;
if ( V_30 < ( T_1 * ) V_31 || F_14 ( V_30 , V_29 ) ) {
V_30 = ( T_1 * ) V_23 -> V_30 ;
V_28 = V_28 - V_26 + 1 ;
}
for ( V_24 = 0 ; V_24 < V_28 ; V_24 ++ , V_30 ++ ) {
if ( V_30 < ( T_1 * ) V_31 ||
F_14 ( V_30 , V_29 ) ) {
F_15 ( L_5 ) ;
break;
}
if ( V_30 == ( T_1 * ) V_23 -> V_30 )
F_15 ( L_6 , V_29 ) ;
else
F_15 ( L_7 , V_29 ) ;
}
}
F_15 ( L_8 ) ;
}

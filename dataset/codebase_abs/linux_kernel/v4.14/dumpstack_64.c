const char * F_1 ( enum V_1 type )
{
F_2 ( V_2 != 4 ) ;
if ( type == V_3 )
return L_1 ;
if ( type >= V_4 && type <= V_5 )
return V_6 [ type - V_4 ] ;
return NULL ;
}
static bool F_3 ( unsigned long * V_7 , struct V_8 * V_9 )
{
unsigned long * V_10 , * V_11 ;
struct V_12 * V_13 ;
unsigned V_14 ;
F_2 ( V_2 != 4 ) ;
for ( V_14 = 0 ; V_14 < V_2 ; V_14 ++ ) {
V_11 = ( unsigned long * ) F_4 ( & V_15 ) -> V_16 [ V_14 ] ;
V_10 = V_11 - ( V_17 [ V_14 ] / sizeof( long ) ) ;
V_13 = (struct V_12 * ) V_11 - 1 ;
if ( V_7 <= V_10 || V_7 >= V_11 )
continue;
V_9 -> type = V_4 + V_14 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_18 = ( unsigned long * ) V_13 -> V_19 ;
return true ;
}
return false ;
}
static bool F_5 ( unsigned long * V_7 , struct V_8 * V_9 )
{
unsigned long * V_11 = ( unsigned long * ) F_6 ( V_20 ) ;
unsigned long * V_10 = V_11 - ( V_21 / sizeof( long ) ) ;
if ( V_7 <= V_10 || V_7 > V_11 )
return false ;
V_9 -> type = V_3 ;
V_9 -> V_10 = V_10 ;
V_9 -> V_11 = V_11 ;
V_9 -> V_18 = ( unsigned long * ) * ( V_11 - 1 ) ;
return true ;
}
int F_7 ( unsigned long * V_7 , struct V_22 * V_23 ,
struct V_8 * V_9 , unsigned long * V_24 )
{
if ( ! V_7 )
goto V_25;
V_23 = V_23 ? : V_26 ;
if ( F_8 ( V_7 , V_23 , V_9 ) )
goto V_27;
if ( V_23 != V_26 )
goto V_25;
if ( F_3 ( V_7 , V_9 ) )
goto V_27;
if ( F_5 ( V_7 , V_9 ) )
goto V_27;
goto V_25;
V_27:
if ( V_24 ) {
if ( * V_24 & ( 1UL << V_9 -> type ) ) {
F_9 ( V_28 L_2 , V_9 -> type ) ;
goto V_25;
}
* V_24 |= 1UL << V_9 -> type ;
}
return 0 ;
V_25:
V_9 -> type = V_29 ;
return - V_30 ;
}
void F_10 ( struct V_12 * V_13 )
{
int V_31 ;
F_11 ( V_32 ) ;
F_12 ( V_13 , 1 ) ;
if ( ! F_13 ( V_13 ) ) {
unsigned int V_33 = V_34 * 43 / 64 ;
unsigned int V_35 = V_34 ;
unsigned char V_36 ;
T_1 * V_37 ;
F_14 ( V_26 , V_13 , NULL , V_32 ) ;
F_15 ( V_32 L_3 ) ;
V_37 = ( T_1 * ) V_13 -> V_37 - V_33 ;
if ( V_37 < ( T_1 * ) V_38 || F_16 ( V_37 , V_36 ) ) {
V_37 = ( T_1 * ) V_13 -> V_37 ;
V_35 = V_35 - V_33 + 1 ;
}
for ( V_31 = 0 ; V_31 < V_35 ; V_31 ++ , V_37 ++ ) {
if ( V_37 < ( T_1 * ) V_38 ||
F_16 ( V_37 , V_36 ) ) {
F_17 ( L_4 ) ;
break;
}
if ( V_37 == ( T_1 * ) V_13 -> V_37 )
F_17 ( L_5 , V_36 ) ;
else
F_17 ( L_6 , V_36 ) ;
}
}
F_17 ( L_7 ) ;
}

void F_1 ( enum V_1 type , const char * * V_2 , const char * * V_3 )
{
F_2 ( V_4 != 4 ) ;
switch ( type ) {
case V_5 :
* V_2 = L_1 ;
* V_3 = L_2 ;
break;
case V_6 ... V_7 :
* V_2 = V_8 [ type - V_6 ] ;
* V_3 = L_3 ;
break;
default:
* V_2 = NULL ;
* V_3 = NULL ;
}
}
static bool F_3 ( unsigned long * V_9 , struct V_10 * V_11 )
{
unsigned long * V_2 , * V_3 ;
struct V_12 * V_13 ;
unsigned V_14 ;
F_2 ( V_4 != 4 ) ;
for ( V_14 = 0 ; V_14 < V_4 ; V_14 ++ ) {
V_3 = ( unsigned long * ) F_4 ( & V_15 ) -> V_16 [ V_14 ] ;
V_2 = V_3 - ( V_17 [ V_14 ] / sizeof( long ) ) ;
V_13 = (struct V_12 * ) V_3 - 1 ;
if ( V_9 < V_2 || V_9 >= V_3 )
continue;
V_11 -> type = V_6 + V_14 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_18 = ( unsigned long * ) V_13 -> V_19 ;
return true ;
}
return false ;
}
static bool F_5 ( unsigned long * V_9 , struct V_10 * V_11 )
{
unsigned long * V_3 = ( unsigned long * ) F_6 ( V_20 ) ;
unsigned long * V_2 = V_3 - ( V_21 / sizeof( long ) ) ;
if ( V_9 < V_2 || V_9 > V_3 )
return false ;
V_11 -> type = V_5 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_18 = ( unsigned long * ) * ( V_3 - 1 ) ;
return true ;
}
int F_7 ( unsigned long * V_9 , struct V_22 * V_23 ,
struct V_10 * V_11 , unsigned long * V_24 )
{
if ( ! V_9 )
goto V_25;
V_23 = V_23 ? : V_26 ;
if ( F_8 ( V_9 , V_23 , V_11 ) )
goto V_27;
if ( V_23 != V_26 )
goto V_25;
if ( F_3 ( V_9 , V_11 ) )
goto V_27;
if ( F_5 ( V_9 , V_11 ) )
goto V_27;
goto V_25;
V_27:
if ( V_24 ) {
if ( * V_24 & ( 1UL << V_11 -> type ) )
goto V_25;
* V_24 |= 1UL << V_11 -> type ;
}
return 0 ;
V_25:
V_11 -> type = V_28 ;
return - V_29 ;
}
void F_9 ( struct V_22 * V_23 , struct V_12 * V_13 ,
unsigned long * V_19 , char * V_30 )
{
unsigned long * V_31 ;
unsigned long * V_32 ;
unsigned long * V_9 ;
int V_33 ;
if ( ! F_10 ( V_23 ) )
return;
V_31 = ( unsigned long * ) F_6 ( V_20 ) ;
V_32 = V_31 - ( V_21 / sizeof( long ) ) ;
V_19 = V_19 ? : F_11 ( V_23 , V_13 ) ;
V_9 = V_19 ;
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
unsigned long V_35 ;
if ( V_9 >= V_32 && V_9 <= V_31 ) {
if ( V_9 == V_31 ) {
V_9 = ( unsigned long * ) ( V_31 [ - 1 ] ) ;
F_12 ( L_4 ) ;
}
} else {
if ( F_13 ( V_9 ) )
break;
}
if ( F_14 ( V_9 , V_35 ) )
break;
if ( ( V_33 % V_36 ) == 0 ) {
if ( V_33 != 0 )
F_12 ( L_5 ) ;
F_15 ( L_6 , V_30 , V_35 ) ;
} else
F_12 ( L_7 , V_35 ) ;
V_9 ++ ;
F_16 () ;
}
F_12 ( L_5 ) ;
F_17 ( V_23 , V_13 , V_19 , V_30 ) ;
F_18 ( V_23 ) ;
}
void F_19 ( struct V_12 * V_13 )
{
int V_33 ;
F_20 ( V_37 ) ;
F_21 ( V_13 , 1 ) ;
if ( ! F_22 ( V_13 ) ) {
unsigned int V_38 = V_39 * 43 / 64 ;
unsigned int V_40 = V_39 ;
unsigned char V_41 ;
T_1 * V_42 ;
F_15 ( V_37 L_8 ) ;
F_9 ( V_26 , V_13 , NULL , V_37 ) ;
F_15 ( V_37 L_9 ) ;
V_42 = ( T_1 * ) V_13 -> V_42 - V_38 ;
if ( V_42 < ( T_1 * ) V_43 || F_14 ( V_42 , V_41 ) ) {
V_42 = ( T_1 * ) V_13 -> V_42 ;
V_40 = V_40 - V_38 + 1 ;
}
for ( V_33 = 0 ; V_33 < V_40 ; V_33 ++ , V_42 ++ ) {
if ( V_42 < ( T_1 * ) V_43 ||
F_14 ( V_42 , V_41 ) ) {
F_12 ( L_10 ) ;
break;
}
if ( V_42 == ( T_1 * ) V_13 -> V_42 )
F_12 ( L_11 , V_41 ) ;
else
F_12 ( L_12 , V_41 ) ;
}
}
F_12 ( L_5 ) ;
}
int F_23 ( unsigned long V_42 )
{
unsigned short V_44 ;
if ( F_24 ( & V_44 , ( const void V_45 * ) V_42 , sizeof( V_44 ) ) )
return 0 ;
return V_44 == 0x0b0f ;
}

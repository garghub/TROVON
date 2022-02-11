static T_1 F_1 ( int V_1 , struct V_2 * V_3 , void * V_4 ,
T_2 V_5 , T_3 * V_6 )
{
T_4 V_7 ;
int V_8 ;
if ( V_9 [ V_1 ] . V_10 )
return V_9 [ V_1 ] . V_10 ( V_3 , V_4 , V_5 , V_6 ) ;
V_7 = V_9 [ V_1 ] . F_2 ( V_3 ) ;
V_8 = snprintf ( V_4 , V_5 , L_1 , V_7 ) ;
if ( V_8 >= V_5 )
return V_5 ;
return ++ V_8 ;
}
static int F_3 ( struct V_11 * V_11 , const void * V_12 , int V_13 , T_3 * V_14 )
{
unsigned long V_15 = F_4 ( V_16 ) ;
T_1 V_17 ;
if ( * V_14 + V_13 > V_15 )
return - V_18 ;
V_17 = V_11 -> V_19 -> V_20 ( V_11 , V_12 , V_13 , & V_11 -> V_21 ) ;
* V_14 += V_17 ;
if ( V_17 != V_13 )
return - V_18 ;
return 0 ;
}
static int F_5 ( struct V_11 * V_11 , char * V_22 , T_3 V_23 ,
T_3 * V_14 )
{
int V_24 , V_5 ;
V_5 = F_6 ( ( T_3 ) V_25 , V_23 - * V_14 ) ;
memset ( V_22 , 0 , V_5 ) ;
V_24 = 0 ;
while ( V_24 == 0 && V_23 > * V_14 ) {
V_5 = F_6 ( ( T_3 ) V_25 , V_23 - * V_14 ) ;
V_24 = F_3 ( V_11 , V_22 , V_5 , V_14 ) ;
}
return V_24 ;
}
static int F_7 ( struct V_2 * V_3 , int V_26 )
{
int V_27 , V_28 , V_29 = 0 ;
char * V_30 ;
char V_31 [ 80 ] ;
for ( V_27 = 0 ; V_9 [ V_27 ] . V_30 != NULL ; V_27 ++ ) {
V_30 = V_9 [ V_27 ] . V_30 ;
V_28 = V_9 [ V_27 ] . V_5 ;
sprintf ( V_31 , L_2 , V_26 , V_30 ) ;
V_29 += sizeof( struct V_32 ) ;
V_29 += F_8 ( strlen ( V_31 ) + 1 , 4 ) ;
V_29 += F_8 ( V_28 , 4 ) ;
}
return V_29 ;
}
static struct V_2 * F_9 ( int * V_33 )
{
struct V_34 * V_35 = F_10 ( V_36 -> V_37 ) ;
struct V_11 * V_11 ;
struct V_2 * V_3 = NULL ;
for (; * V_33 < V_35 -> V_38 ; ( * V_33 ) ++ ) {
if ( ! F_11 ( * V_33 , V_35 -> V_39 ) )
continue;
V_11 = F_12 ( * V_33 ) ;
if ( ! V_11 || V_11 -> V_19 != & V_40 )
continue;
V_3 = F_13 ( V_11 -> V_41 -> V_42 ) -> V_43 ;
if ( V_3 -> V_44 & V_45 )
continue;
break;
}
return V_3 ;
}
int F_14 ( void )
{
struct V_2 * V_3 ;
int V_5 = 0 , V_24 , V_33 ;
V_33 = 0 ;
while ( ( V_3 = F_9 ( & V_33 ) ) != NULL ) {
V_24 = F_15 ( V_3 ) ;
if ( V_24 )
break;
V_24 = F_7 ( V_3 , V_33 ) ;
F_16 ( V_3 ) ;
if ( V_24 < 0 )
break;
V_5 += V_24 ;
V_33 ++ ;
}
return V_5 ;
}
static int F_17 ( struct V_2 * V_3 , int V_27 ,
struct V_11 * V_11 , int V_26 , T_3 * V_14 )
{
T_3 V_46 = 0 ;
int V_28 , V_24 , V_47 , V_29 = 0 ;
const int V_48 = V_25 ;
char * V_30 ;
char V_31 [ 80 ] , * V_22 ;
struct V_32 V_49 ;
V_22 = ( void * ) F_18 ( V_50 ) ;
if ( ! V_22 )
return - V_51 ;
V_30 = V_9 [ V_27 ] . V_30 ;
V_28 = V_9 [ V_27 ] . V_5 ;
sprintf ( V_31 , L_2 , V_26 , V_30 ) ;
V_49 . V_52 = strlen ( V_31 ) + 1 ;
V_49 . V_53 = V_28 ;
V_49 . V_54 = V_55 ;
V_24 = F_3 ( V_11 , & V_49 , sizeof( V_49 ) , V_14 ) ;
if ( V_24 )
goto V_56;
V_24 = F_3 ( V_11 , V_31 , V_49 . V_52 , V_14 ) ;
if ( V_24 )
goto V_56;
V_24 = F_5 ( V_11 , V_22 , F_8 ( * V_14 , 4 ) , V_14 ) ;
if ( V_24 )
goto V_56;
do {
V_47 = F_1 ( V_27 , V_3 , V_22 , V_48 , & V_46 ) ;
if ( V_47 > 0 ) {
V_24 = F_3 ( V_11 , V_22 , V_47 , V_14 ) ;
if ( V_24 )
goto V_56;
V_29 += V_47 ;
}
} while ( V_47 == V_48 && V_29 < V_28 );
if ( V_47 < 0 ) {
V_24 = V_47 ;
goto V_56;
}
V_24 = F_5 ( V_11 , V_22 , F_8 ( * V_14 - V_29 + V_28 , 4 ) ,
V_14 ) ;
V_56:
F_19 ( ( unsigned long ) V_22 ) ;
return V_24 ;
}
int F_20 ( struct V_11 * V_11 , T_3 * V_14 )
{
struct V_2 * V_3 ;
int V_33 , V_57 , V_24 ;
V_33 = 0 ;
while ( ( V_3 = F_9 ( & V_33 ) ) != NULL ) {
V_24 = F_15 ( V_3 ) ;
if ( V_24 )
return V_24 ;
for ( V_57 = 0 ; V_9 [ V_57 ] . V_30 != NULL ; V_57 ++ ) {
V_24 = F_17 ( V_3 , V_57 , V_11 , V_33 , V_14 ) ;
if ( V_24 ) {
F_16 ( V_3 ) ;
return V_24 ;
}
}
F_16 ( V_3 ) ;
V_33 ++ ;
}
return 0 ;
}

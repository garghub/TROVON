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
static int F_3 ( struct V_2 * V_3 , int V_11 )
{
int V_12 , V_13 , V_14 = 0 ;
char * V_15 ;
char V_16 [ 80 ] ;
for ( V_12 = 0 ; V_9 [ V_12 ] . V_15 != NULL ; V_12 ++ ) {
V_15 = V_9 [ V_12 ] . V_15 ;
V_13 = V_9 [ V_12 ] . V_5 ;
sprintf ( V_16 , L_2 , V_11 , V_15 ) ;
V_14 += sizeof( struct V_17 ) ;
V_14 += F_4 ( strlen ( V_16 ) + 1 , 4 ) ;
V_14 += F_4 ( V_13 , 4 ) ;
}
return V_14 ;
}
static int F_5 ( const void * V_18 , struct V_19 * V_19 , unsigned V_20 )
{
struct V_2 * V_3 ;
if ( V_19 -> V_21 != & V_22 )
return 0 ;
V_3 = F_6 ( F_7 ( V_19 ) ) -> V_23 ;
if ( V_3 -> V_24 & V_25 )
return 0 ;
return V_20 + 1 ;
}
static struct V_2 * F_8 ( int * V_20 )
{
struct V_19 * V_19 ;
int V_26 = F_9 ( V_27 -> V_28 , * V_20 , F_5 , NULL ) ;
if ( ! V_26 )
return NULL ;
* V_20 = V_26 - 1 ;
V_19 = F_10 ( * V_20 ) ;
return F_6 ( F_7 ( V_19 ) ) -> V_23 ;
}
int F_11 ( void )
{
struct V_2 * V_3 ;
int V_5 = 0 , V_29 , V_20 ;
V_20 = 0 ;
while ( ( V_3 = F_8 ( & V_20 ) ) != NULL ) {
V_29 = F_12 ( V_3 ) ;
if ( V_29 )
break;
V_29 = F_3 ( V_3 , V_20 ) ;
F_13 ( V_3 ) ;
if ( V_29 < 0 )
break;
V_5 += V_29 ;
V_20 ++ ;
}
return V_5 ;
}
static int F_14 ( struct V_2 * V_3 , int V_12 ,
struct V_30 * V_31 , int V_11 )
{
T_3 V_32 = 0 ;
int V_13 , V_29 , V_14 = 0 ;
const int V_33 = V_34 ;
char * V_15 ;
char V_16 [ 80 ] , * V_35 ;
struct V_17 V_36 ;
T_2 V_37 ;
V_35 = ( void * ) F_15 ( V_38 ) ;
if ( ! V_35 )
return - V_39 ;
V_15 = V_9 [ V_12 ] . V_15 ;
V_13 = V_9 [ V_12 ] . V_5 ;
sprintf ( V_16 , L_2 , V_11 , V_15 ) ;
V_36 . V_40 = strlen ( V_16 ) + 1 ;
V_36 . V_41 = V_13 ;
V_36 . V_42 = V_43 ;
if ( ! F_16 ( V_31 , & V_36 , sizeof( V_36 ) ) )
goto V_44;
if ( ! F_16 ( V_31 , V_16 , V_36 . V_40 ) )
goto V_44;
if ( ! F_17 ( V_31 , 4 ) )
goto V_44;
do {
V_29 = F_1 ( V_12 , V_3 , V_35 , V_33 , & V_32 ) ;
if ( V_29 > 0 ) {
if ( ! F_16 ( V_31 , V_35 , V_29 ) )
goto V_44;
V_14 += V_29 ;
}
} while ( V_29 == V_33 && V_14 < V_13 );
if ( V_29 < 0 )
goto V_45;
V_37 = F_4 ( V_31 -> V_32 - V_14 + V_13 , 4 ) - V_31 -> V_32 ;
if ( ! F_18 ( V_31 , V_37 ) )
goto V_44;
V_45:
F_19 ( ( unsigned long ) V_35 ) ;
return V_29 ;
V_44:
F_19 ( ( unsigned long ) V_35 ) ;
return - V_46 ;
}
int F_20 ( struct V_30 * V_31 )
{
struct V_2 * V_3 ;
int V_20 , V_47 , V_29 ;
V_20 = 0 ;
while ( ( V_3 = F_8 ( & V_20 ) ) != NULL ) {
V_29 = F_12 ( V_3 ) ;
if ( V_29 )
return V_29 ;
for ( V_47 = 0 ; V_9 [ V_47 ] . V_15 != NULL ; V_47 ++ ) {
V_29 = F_14 ( V_3 , V_47 , V_31 , V_20 ) ;
if ( V_29 ) {
F_13 ( V_3 ) ;
return V_29 ;
}
}
F_13 ( V_3 ) ;
V_20 ++ ;
}
return 0 ;
}

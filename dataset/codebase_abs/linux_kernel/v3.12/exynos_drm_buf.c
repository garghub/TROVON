static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , struct V_4 * V_5 )
{
int V_6 = 0 ;
enum V_7 V_8 ;
unsigned int V_9 ;
if ( V_5 -> V_10 ) {
F_2 ( L_1 ) ;
return 0 ;
}
F_3 ( & V_5 -> V_11 ) ;
if ( ! ( V_3 & V_12 ) )
F_4 ( V_13 , & V_5 -> V_11 ) ;
if ( V_3 & V_14 || ! ( V_3 & V_15 ) )
V_8 = V_16 ;
else
V_8 = V_17 ;
F_4 ( V_8 , & V_5 -> V_11 ) ;
F_4 ( V_18 , & V_5 -> V_11 ) ;
V_9 = V_5 -> V_19 >> V_20 ;
if ( ! F_5 ( V_2 ) ) {
T_1 V_21 ;
unsigned int V_22 = 0 ;
V_5 -> V_23 = F_6 ( V_9 , sizeof( struct V_24 * ) ) ;
if ( ! V_5 -> V_23 ) {
F_7 ( L_2 ) ;
return - V_25 ;
}
V_5 -> V_26 = ( void V_27 * ) F_8 ( V_2 -> V_2 ,
V_5 -> V_19 ,
& V_5 -> V_10 , V_28 ,
& V_5 -> V_11 ) ;
if ( ! V_5 -> V_26 ) {
F_7 ( L_3 ) ;
V_6 = - V_25 ;
goto V_29;
}
V_21 = V_5 -> V_10 ;
while ( V_22 < V_9 ) {
V_5 -> V_23 [ V_22 ] = F_9 ( V_21 ) ;
V_21 += V_30 ;
V_22 ++ ;
}
} else {
V_5 -> V_23 = F_8 ( V_2 -> V_2 , V_5 -> V_19 ,
& V_5 -> V_10 , V_28 ,
& V_5 -> V_11 ) ;
if ( ! V_5 -> V_23 ) {
F_7 ( L_3 ) ;
return - V_25 ;
}
}
V_5 -> V_31 = F_10 ( V_5 -> V_23 , V_9 ) ;
if ( F_11 ( V_5 -> V_31 ) ) {
F_7 ( L_4 ) ;
V_6 = F_12 ( V_5 -> V_31 ) ;
goto V_32;
}
F_2 ( L_5 ,
( unsigned long ) V_5 -> V_10 ,
V_5 -> V_19 ) ;
return V_6 ;
V_32:
F_13 ( V_2 -> V_2 , V_5 -> V_19 , V_5 -> V_23 ,
( T_1 ) V_5 -> V_10 , & V_5 -> V_11 ) ;
V_5 -> V_10 = ( T_1 ) NULL ;
V_29:
if ( ! F_5 ( V_2 ) )
F_14 ( V_5 -> V_23 ) ;
return V_6 ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned int V_3 , struct V_4 * V_5 )
{
if ( ! V_5 -> V_10 ) {
F_2 ( L_6 ) ;
return;
}
F_2 ( L_5 ,
( unsigned long ) V_5 -> V_10 ,
V_5 -> V_19 ) ;
F_16 ( V_5 -> V_31 ) ;
F_17 ( V_5 -> V_31 ) ;
V_5 -> V_31 = NULL ;
if ( ! F_5 ( V_2 ) ) {
F_13 ( V_2 -> V_2 , V_5 -> V_19 , V_5 -> V_26 ,
( T_1 ) V_5 -> V_10 , & V_5 -> V_11 ) ;
F_14 ( V_5 -> V_23 ) ;
} else
F_13 ( V_2 -> V_2 , V_5 -> V_19 , V_5 -> V_23 ,
( T_1 ) V_5 -> V_10 , & V_5 -> V_11 ) ;
V_5 -> V_10 = ( T_1 ) NULL ;
}
struct V_4 * F_18 ( struct V_1 * V_2 ,
unsigned int V_19 )
{
struct V_4 * V_33 ;
F_2 ( L_7 , V_19 ) ;
V_33 = F_19 ( sizeof( * V_33 ) , V_28 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_19 = V_19 ;
return V_33 ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_4 * V_33 )
{
F_17 ( V_33 ) ;
V_33 = NULL ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_4 * V_5 , unsigned int V_3 )
{
if ( F_1 ( V_2 , V_3 , V_5 ) < 0 )
return - V_25 ;
return 0 ;
}
void F_22 ( struct V_1 * V_2 ,
unsigned int V_3 , struct V_4 * V_33 )
{
F_15 ( V_2 , V_3 , V_33 ) ;
}

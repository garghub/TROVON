void * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( struct V_1 ) ) ;
if ( V_2 == NULL ) {
F_3 ( L_1 ) ;
exit ( V_3 ) ;
}
V_2 -> V_4 = - 1 ;
V_2 -> V_5 = - 1 ;
V_2 -> V_6 = - 1 ;
V_2 -> V_7 = - 1 ;
V_2 -> V_8 = - 1 ;
V_2 -> V_9 = V_10 ;
return V_2 ;
}
void * F_4 ( int V_11 , const char * V_12 , const char * V_13 ,
bool V_14 , unsigned long V_9 ,
struct V_1 * V_2 )
{
int V_15 [ 2 ] ;
V_2 -> V_4 = V_11 ;
V_2 -> V_5 = F_5 ( V_12 , V_16 ) ;
if ( V_2 -> V_5 == - 1 ) {
F_3 ( L_2 , V_11 ) ;
goto error;
}
if ( ! V_14 ) {
V_2 -> V_6 = F_5 ( V_13 , V_17 ) ;
if ( V_2 -> V_6 == - 1 ) {
F_3 ( L_3 , V_11 ) ;
goto error;
}
} else
V_2 -> V_6 = V_18 ;
if ( F_6 ( V_15 , V_19 ) < 0 ) {
F_3 ( L_4 , V_11 ) ;
goto error;
}
if ( F_7 ( * V_15 , V_20 , V_9 ) < 0 ) {
F_3 ( L_5 , V_11 ) ;
goto error;
}
V_2 -> V_7 = V_15 [ 1 ] ;
V_2 -> V_8 = V_15 [ 0 ] ;
V_2 -> V_9 = V_9 ;
return NULL ;
error:
exit ( V_3 ) ;
}
static void F_8 ( int V_4 )
{
T_1 V_21 ;
F_9 ( & V_21 ) ;
F_10 ( V_4 , & V_21 ) ;
if ( F_11 ( 0 , sizeof( V_21 ) , & V_21 ) == - 1 )
F_3 ( L_6 , ( int ) V_4 ) ;
}
static void * F_12 ( void * V_22 )
{
T_2 V_23 , V_24 ;
T_2 V_25 ;
struct V_1 * V_26 = (struct V_1 * ) V_22 ;
F_8 ( V_26 -> V_4 ) ;
while ( 1 ) {
if ( ! V_27 ) {
F_13 ( & V_28 ) ;
F_14 ( & V_29 , & V_28 ) ;
F_15 ( & V_28 ) ;
}
if ( V_30 )
break;
V_23 = F_16 ( V_26 -> V_5 , NULL , V_26 -> V_7 , NULL ,
V_26 -> V_9 , V_31 | V_32 ) ;
if ( V_23 < 0 ) {
F_3 ( L_7 , V_26 -> V_4 ) ;
goto error;
} else if ( V_23 == 0 ) {
F_17 ( V_33 ) ;
F_18 ( L_8 , V_26 -> V_4 ) ;
continue;
}
V_24 = 0 ;
do {
V_25 = F_16 ( V_26 -> V_8 , NULL , V_26 -> V_6 , NULL ,
V_23 - V_24 ,
V_31 | V_32 ) ;
if ( V_25 < 0 ) {
F_3 ( L_9 ,
V_26 -> V_4 ) ;
goto error;
} else if ( V_25 == 0 )
F_19 ( 1 ) ;
V_24 += V_25 ;
} while ( V_24 < V_23 );
}
return NULL ;
error:
exit ( V_3 ) ;
}
T_3 F_20 ( struct V_1 * V_2 )
{
int V_25 ;
T_3 V_34 ;
V_25 = F_21 ( & V_34 , NULL , F_12 , V_2 ) ;
if ( V_25 != 0 ) {
F_3 ( L_10 , V_2 -> V_4 ) ;
exit ( V_3 ) ;
}
return V_34 ;
}

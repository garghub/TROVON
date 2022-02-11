void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct F_1 * V_8 = V_3 ;
int V_9 ;
V_5 = F_2 ( V_2 ) ;
V_7 = (struct V_6 * ) V_5 -> V_10 ;
V_7 -> V_11 = V_8 -> V_11 ;
V_7 -> V_12 = - 1 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_2 = V_2 ;
F_3 ( & V_7 -> V_14 ) ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = NULL ;
V_2 -> V_17 = 0 ;
V_2 -> type = V_18 ;
V_2 -> V_19 = 256 ;
V_2 -> V_20 = V_21 ;
F_4 ( L_1 ) ;
for ( V_9 = 0 ; V_7 -> V_11 . V_22 [ V_9 ] != NULL ; V_9 ++ )
F_4 ( L_2 , V_7 -> V_11 . V_22 [ V_9 ] ) ;
F_4 ( L_3 ) ;
}
static unsigned short F_5 ( struct V_23 * V_24 )
{
return F_6 ( V_25 ) ;
}
static int F_7 ( int V_26 , struct V_23 * V_27 , struct V_4 * V_28 )
{
return F_8 ( V_26 , F_9 ( V_27 ) , V_27 -> V_2 -> V_29 ,
(struct V_6 * ) & V_28 -> V_10 ) ;
}
static int F_10 ( int V_26 , struct V_23 * V_27 , struct V_4 * V_28 )
{
return F_11 ( V_26 , V_27 -> V_3 , V_27 -> V_30 ,
(struct V_6 * ) & V_28 -> V_10 ) ;
}
static int F_12 ( char * V_31 , char * * V_32 , void * V_3 )
{
struct F_1 * V_8 = V_3 ;
int V_9 = 0 ;
* V_8 = ( (struct F_1 ) { . V_11 = { { L_4 , NULL } } } ) ;
V_31 = F_13 ( V_31 , V_32 , NULL ) ;
if ( V_31 == NULL )
return 1 ;
do {
if ( V_9 >= V_33 - 1 ) {
F_4 ( V_34 L_5
L_6 ) ;
break;
}
V_8 -> V_11 . V_22 [ V_9 ++ ] = V_31 ;
while( * V_31 && * V_31 != ',' ) {
if ( * V_31 == '_' )
* V_31 = ' ' ;
V_31 ++ ;
}
if ( * V_31 != ',' )
break;
* V_31 ++ = '\0' ;
} while ( 1 );
V_8 -> V_11 . V_22 [ V_9 ] = NULL ;
return 1 ;
}
static int F_14 ( void )
{
F_15 ( & V_35 ) ;
return 0 ;
}

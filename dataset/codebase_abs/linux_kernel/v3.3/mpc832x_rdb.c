static int T_1 F_1 ( char * type , char * V_1 , T_2 V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 ,
void (* F_2)( struct V_6 * V_7 ,
bool V_8 ) )
{
struct V_9 * V_10 ;
unsigned int V_11 = 0 ;
F_3 (np, type, compatible) {
int V_12 ;
unsigned int V_13 ;
const void * V_14 ;
struct V_15 V_16 [ 2 ] ;
struct V_17 * V_18 ;
struct V_19 V_20 = {
. F_2 = F_2 ,
} ;
memset ( V_16 , 0 , sizeof( V_16 ) ) ;
V_20 . V_2 = V_2 ;
V_14 = F_4 ( V_10 , L_1 , NULL ) ;
if ( ! V_14 )
goto V_21;
V_20 . V_22 = * ( T_2 * ) V_14 ;
V_14 = F_4 ( V_10 , L_2 , NULL ) ;
if ( V_14 )
V_11 = * ( T_2 * ) V_14 ;
V_14 = F_4 ( V_10 , L_3 , NULL ) ;
if ( V_14 && ! strcmp ( V_14 , L_4 ) )
V_20 . V_23 = V_24 ;
for ( V_13 = 0 ; V_13 < V_5 ; V_13 ++ ) {
if ( V_4 [ V_13 ] . V_22 == V_20 . V_22 )
V_20 . V_25 ++ ;
}
if ( ! V_20 . V_25 )
continue;
V_12 = F_5 ( V_10 , 0 , & V_16 [ 0 ] ) ;
if ( V_12 )
goto V_21;
V_12 = F_6 ( V_10 , 0 , & V_16 [ 1 ] ) ;
if ( V_12 == V_26 )
goto V_21;
V_18 = F_7 ( L_5 , V_11 ) ;
if ( ! V_18 )
goto V_21;
V_12 = F_8 ( V_18 , & V_20 , sizeof( V_20 ) ) ;
if ( V_12 )
goto V_27;
V_12 = F_9 ( V_18 , V_16 ,
F_10 ( V_16 ) ) ;
if ( V_12 )
goto V_27;
V_12 = F_11 ( V_18 ) ;
if ( V_12 )
goto V_27;
goto V_28;
V_27:
F_12 ( V_18 ) ;
V_21:
F_13 ( L_6 , V_10 -> V_29 ) ;
V_28:
V_11 ++ ;
}
return V_11 ;
}
static int T_1 F_14 ( struct V_3 * V_4 ,
unsigned int V_5 ,
void (* F_2)( struct V_6 * V_30 ,
bool V_8 ) )
{
T_2 V_2 = - 1 ;
int V_12 ;
V_2 = F_15 () ;
if ( V_2 == - 1 ) {
V_2 = F_16 () ;
if ( V_2 == - 1 )
return - V_31 ;
}
V_12 = F_1 ( NULL , L_7 , V_2 , V_4 ,
V_5 , F_2 ) ;
if ( ! V_12 )
F_1 ( L_8 , L_9 , V_2 , V_4 ,
V_5 , F_2 ) ;
return F_17 ( V_4 , V_5 ) ;
}
static void F_18 ( struct V_6 * V_30 , bool V_8 )
{
F_19 ( L_10 , V_32 , V_30 -> V_33 , V_8 ) ;
F_20 ( 3 , 13 , V_8 ) ;
}
static int T_1 F_21 ( void )
{
F_22 ( 3 , 0 , 3 , 0 , 1 , 0 ) ;
F_22 ( 3 , 1 , 3 , 0 , 1 , 0 ) ;
F_22 ( 3 , 2 , 3 , 0 , 1 , 0 ) ;
F_22 ( 3 , 3 , 2 , 0 , 1 , 0 ) ;
F_22 ( 3 , 13 , 1 , 0 , 0 , 0 ) ;
F_22 ( 3 , 14 , 2 , 0 , 0 , 0 ) ;
F_22 ( 3 , 15 , 2 , 0 , 0 , 0 ) ;
if ( F_23 ( NULL , NULL , L_11 ) )
return 0 ;
return F_14 ( & V_34 , 1 , F_18 ) ;
}
static void T_1 F_24 ( void )
{
#if F_25 ( V_35 )
struct V_9 * V_10 ;
#endif
if ( V_36 . V_37 )
V_36 . V_37 ( L_12 , 0 ) ;
F_26 () ;
#ifdef V_35
F_27 () ;
if ( ( V_10 = F_28 ( NULL , L_13 ) ) != NULL ) {
F_29 ( V_10 ) ;
F_30 ( V_10 ) ;
for ( V_10 = NULL ; ( V_10 = F_28 ( V_10 , L_14 ) ) != NULL ; )
F_31 ( V_10 ) ;
}
#endif
}
static int T_1 F_32 ( void )
{
unsigned long V_38 = F_33 () ;
return F_34 ( V_38 , L_15 ) ;
}

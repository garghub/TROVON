static void F_1 ( int V_1 , T_1 * V_2 , void * V_3 )
{
T_2 * V_4 = ( T_2 * ) ( V_3 ) ;
int V_5 ;
char * V_6 ;
T_3 V_7 ;
T_4 V_8 ;
if ( V_2 -> V_9 != V_10 )
return;
if ( ! V_4 )
return;
V_5 = V_4 -> V_11 . V_12 [ V_13 ] ;
V_6 = ( char * ) V_4 -> V_11 . V_12 [ V_14 ] ;
V_8 = ( T_4 ) V_4 -> V_11 . V_12 [ V_15 ] ;
if ( V_5 != V_16 )
return;
if ( V_4 -> V_11 . V_12 [ V_17 ] != V_18 )
return;
V_4 -> V_11 . V_12 [ V_19 ] = - 1 ;
if ( F_2 ( V_20 , L_1 , 6 ) > 0 ) {
V_7 = F_2 ( V_20 , V_6 , V_8 ) ;
V_4 -> V_11 . V_12 [ V_19 ] = V_7 ;
}
return;
}
static int F_3 ( void )
{
struct V_21 V_22 ;
T_5 V_23 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_4 ( & V_23 ) ;
F_5 ( & V_23 , V_24 ) ;
V_22 . V_25 = & F_1 ;
V_22 . V_26 = V_27 ;
if ( V_21 ( V_24 , & V_22 , NULL ) < 0 ) {
perror ( L_2 ) ;
return - 1 ;
}
if ( F_6 ( V_28 , & V_23 , NULL ) ) {
perror ( L_3 ) ;
return - 1 ;
}
return 0 ;
}
static int F_7 ( void )
{
struct V_29 V_30 [] = {
F_8 ( V_31 + V_32 + V_33 , V_34 ) ,
F_9 ( V_35 + V_36 + V_37 , V_38 , 0 , 1 ) ,
F_8 ( V_39 + V_37 , V_40 ) ,
#ifdef F_10
F_9 ( V_35 + V_36 + V_37 , F_10 , 0 , 1 ) ,
F_8 ( V_39 + V_37 , V_40 ) ,
#endif
F_9 ( V_35 + V_36 + V_37 , V_41 , 0 , 1 ) ,
F_8 ( V_39 + V_37 , V_40 ) ,
F_9 ( V_35 + V_36 + V_37 , V_42 , 0 , 1 ) ,
F_8 ( V_39 + V_37 , V_40 ) ,
F_9 ( V_35 + V_36 + V_37 , V_43 , 1 , 0 ) ,
F_9 ( V_35 + V_36 + V_37 , V_16 , 3 , 2 ) ,
F_8 ( V_31 + V_32 + V_33 , F_11 ( 0 ) ) ,
F_9 ( V_35 + V_36 + V_37 , V_44 , 4 , 0 ) ,
F_8 ( V_39 + V_37 , V_45 ) ,
F_8 ( V_31 + V_32 + V_33 , F_11 ( 0 ) ) ,
F_9 ( V_35 + V_36 + V_37 , V_20 , 1 , 0 ) ,
F_9 ( V_35 + V_36 + V_37 , V_18 , 1 , 2 ) ,
F_8 ( V_39 + V_37 , V_40 ) ,
F_8 ( V_39 + V_37 , V_46 ) ,
F_8 ( V_39 + V_37 , V_45 ) ,
} ;
struct V_47 V_48 = {
. V_8 = ( unsigned short ) ( sizeof( V_30 ) / sizeof( V_30 [ 0 ] ) ) ,
. V_30 = V_30 ,
} ;
if ( F_12 ( V_49 , 1 , 0 , 0 , 0 ) ) {
perror ( L_4 ) ;
return 1 ;
}
if ( F_12 ( V_50 , V_51 , & V_48 ) ) {
perror ( L_5 ) ;
return 1 ;
}
return 0 ;
}
int main ( int V_52 , char * * V_53 )
{
char V_6 [ 4096 ] ;
T_3 V_7 = 0 ;
if ( F_3 () )
return 1 ;
if ( F_7 () )
return 1 ;
V_5 ( V_16 , V_20 ,
F_13 ( L_6 ) ) ;
V_7 = V_5 ( V_43 , V_44 , V_6 , sizeof( V_6 ) ) ;
V_5 ( V_16 , V_20 , F_13 ( L_7 ) ) ;
V_5 ( V_16 , V_20 , V_6 , V_7 ) ;
V_5 ( V_16 , V_18 ,
F_13 ( L_8 ) ) ;
return 0 ;
}
int main ( void )
{
return 1 ;
}

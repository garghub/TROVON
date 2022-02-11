static void F_1 ( int V_1 )
{
longjmp ( V_2 , 1 ) ;
}
static int F_2 ( unsigned long V_3 )
{
unsigned long * V_4 = ( unsigned long * ) ( V_3 << V_5 ) ;
unsigned long V_6 = ~ 0UL ;
void * V_7 = NULL ;
int V_8 = 0 ;
if ( setjmp ( V_2 ) == 0 )
V_6 = * V_4 ;
else {
V_7 = F_3 ( V_4 , V_9 ,
V_10 | V_11 ,
V_12 | V_13 | V_14 , - 1 , 0 ) ;
if ( V_7 == V_15 )
return 0 ;
if ( V_7 != V_4 )
goto V_16;
}
if ( setjmp ( V_2 ) == 0 ) {
* V_4 = V_6 ;
V_8 = 1 ;
goto V_16;
} else if ( F_4 ( V_4 , V_9 ,
V_10 | V_11 ) != 0 )
goto V_16;
if ( setjmp ( V_2 ) == 0 ) {
* V_4 = V_6 ;
V_8 = 1 ;
}
V_16:
if ( V_7 != NULL )
F_5 ( V_7 , V_9 ) ;
return V_8 ;
}
unsigned long F_6 ( void )
{
struct V_17 V_18 , V_19 ;
unsigned long V_20 = 0 ;
unsigned long V_21 = 0xffffd000 >> V_5 ;
unsigned long V_22 , V_23 ;
printf ( L_1 ) ;
fflush ( stdout ) ;
V_18 . V_24 = F_1 ;
F_7 ( & V_18 . V_25 ) ;
V_18 . V_26 = V_27 ;
if ( V_17 ( V_28 , & V_18 , & V_19 ) ) {
perror ( L_2 ) ;
exit ( 1 ) ;
}
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( F_2 ( V_20 ) )
break;
}
if ( V_20 == V_21 ) {
fprintf ( V_29 , L_3
L_4 ) ;
exit ( 1 ) ;
}
printf ( L_5 , V_20 << V_5 ) ;
printf ( L_6 ) ;
fflush ( stdout ) ;
V_23 = V_20 ;
if ( F_2 ( V_21 ) )
goto V_16;
do {
V_22 = V_20 + ( V_21 - V_20 ) / 2 ;
if ( F_2 ( V_22 ) )
V_20 = V_22 ;
else
V_21 = V_22 ;
} while ( V_21 - V_20 > 1 );
V_16:
if ( V_17 ( V_28 , & V_19 , NULL ) ) {
perror ( L_2 ) ;
exit ( 1 ) ;
}
V_21 <<= V_5 ;
printf ( L_5 , V_21 ) ;
return V_21 ;
}
unsigned long F_6 ( void )
{
return 0x7fc0000000 ;
}

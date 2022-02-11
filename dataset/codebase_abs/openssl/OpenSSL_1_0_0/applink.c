static void * F_1 ( void ) { return V_1 ; }
static void * F_2 ( void ) { return stdout ; }
static void * F_3 ( void ) { return V_2 ; }
static int F_4 ( T_1 * V_3 ) { return feof ( V_3 ) ; }
static int F_5 ( T_1 * V_3 ) { return ferror ( V_3 ) ; }
static void F_6 ( T_1 * V_3 ) { clearerr ( V_3 ) ; }
static int F_7 ( T_1 * V_3 ) { return F_8 ( V_3 ) ; }
static int F_9 ( T_1 * V_3 , char V_4 )
{ return F_10 ( F_8 ( V_3 ) , V_4 == 'b' ? V_5 : V_6 ) ; }
void * *
#if F_11 ( V_7 )
T_2
#else
T_3
#endif
F_12 ( void )
{ static int V_8 = 1 ;
static void * V_9 [ V_10 + 1 ] = { ( void * ) V_10 } ;
if ( V_8 )
{ V_9 [ V_11 ] = F_1 ;
V_9 [ V_12 ] = F_2 ;
V_9 [ V_13 ] = F_3 ;
V_9 [ V_14 ] = fprintf ;
V_9 [ V_15 ] = fgets ;
V_9 [ V_16 ] = fread ;
V_9 [ V_17 ] = fwrite ;
V_9 [ V_18 ] = F_9 ;
V_9 [ V_19 ] = F_4 ;
V_9 [ V_20 ] = fclose ;
V_9 [ V_21 ] = fopen ;
V_9 [ V_22 ] = fseek ;
V_9 [ V_23 ] = ftell ;
V_9 [ V_24 ] = fflush ;
V_9 [ V_25 ] = F_5 ;
V_9 [ V_26 ] = F_6 ;
V_9 [ V_27 ] = F_7 ;
V_9 [ V_28 ] = V_29 ;
V_9 [ V_30 ] = V_31 ;
V_9 [ V_32 ] = V_33 ;
V_9 [ V_34 ] = V_35 ;
V_9 [ V_36 ] = V_37 ;
V_8 = 0 ;
}
return V_9 ;
}

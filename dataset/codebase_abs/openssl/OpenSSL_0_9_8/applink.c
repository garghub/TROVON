static void * F_1 ( void ) { return V_1 ; }
static void * F_2 ( void ) { return stdout ; }
static void * F_3 ( void ) { return V_2 ; }
static int F_4 ( T_1 * V_3 ) { return feof ( V_3 ) ; }
static int F_5 ( T_1 * V_3 ) { return ferror ( V_3 ) ; }
static void F_6 ( T_1 * V_3 ) { clearerr ( V_3 ) ; }
static int F_7 ( T_1 * V_3 ) { return F_8 ( V_3 ) ; }
static int F_9 ( T_1 * V_3 , char V_4 )
{ return F_10 ( F_8 ( V_3 ) , V_4 == 'b' ? V_5 : V_6 ) ; }
void * * F_11 ( void )
{ static int V_7 = 1 ;
static void * V_8 [ V_9 + 1 ] = { ( void * ) V_9 } ;
if ( V_7 )
{ V_8 [ V_10 ] = F_1 ;
V_8 [ V_11 ] = F_2 ;
V_8 [ V_12 ] = F_3 ;
V_8 [ V_13 ] = fprintf ;
V_8 [ V_14 ] = fgets ;
V_8 [ V_15 ] = fread ;
V_8 [ V_16 ] = fwrite ;
V_8 [ V_17 ] = F_9 ;
V_8 [ V_18 ] = F_4 ;
V_8 [ V_19 ] = fclose ;
V_8 [ V_20 ] = fopen ;
V_8 [ V_21 ] = fseek ;
V_8 [ V_22 ] = ftell ;
V_8 [ V_23 ] = fflush ;
V_8 [ V_24 ] = F_5 ;
V_8 [ V_25 ] = F_6 ;
V_8 [ V_26 ] = F_7 ;
V_8 [ V_27 ] = V_28 ;
V_8 [ V_29 ] = V_30 ;
V_8 [ V_31 ] = V_32 ;
V_8 [ V_33 ] = V_34 ;
V_8 [ V_35 ] = V_36 ;
V_7 = 0 ;
}
return V_8 ;
}

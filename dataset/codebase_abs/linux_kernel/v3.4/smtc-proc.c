static int F_1 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
int V_7 = 0 ;
int V_8 ;
int V_9 ;
extern unsigned long V_10 ;
V_8 = sprintf ( V_1 , L_1 , V_11 ) ;
V_7 += V_8 ;
V_1 += V_8 ;
V_8 = sprintf ( V_1 , L_2 , F_2 () ) ;
V_7 += V_8 ;
V_1 += V_8 ;
V_8 = sprintf ( V_1 , L_3 , V_10 ) ;
V_7 += V_8 ;
V_1 += V_8 ;
V_8 = sprintf ( V_1 , L_4 ) ;
V_7 += V_8 ;
V_1 += V_8 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
V_8 = sprintf ( V_1 , L_5 , V_9 , V_13 [ V_9 ] . V_14 ) ;
V_7 += V_8 ;
V_1 += V_8 ;
}
V_8 = sprintf ( V_1 , L_6 ) ;
V_7 += V_8 ;
V_1 += V_8 ;
for( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
V_8 = sprintf ( V_1 , L_5 , V_9 , V_13 [ V_9 ] . V_15 ) ;
V_7 += V_8 ;
V_1 += V_8 ;
}
V_8 = sprintf ( V_1 , L_7 ,
F_3 ( & V_16 ) ) ;
V_7 += V_8 ;
V_1 += V_8 ;
return V_7 ;
}
void F_4 ( void )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < V_12 ; V_9 ++ ) {
V_13 [ V_9 ] . V_14 = 0 ;
V_13 [ V_9 ] . V_15 = 0 ;
}
F_5 ( & V_16 , 0 ) ;
V_17 = F_6 ( L_8 , 0444 , NULL ,
F_1 , NULL ) ;
}

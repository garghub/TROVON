void F_1 ( unsigned char * V_1 , T_1 V_2 ,
T_1 V_3 , T_2 V_4 ,
void * V_5 )
{
T_1 V_6 , V_7 , V_8 ;
if ( ! V_4 )
return;
V_3 = F_2 ( V_3 ) ;
V_8 = V_3 - 1 ;
V_4 ( V_9 , 0 , V_5 ) ;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
if ( ( V_6 & V_8 ) == 0 ) {
V_4 ( V_10 , - 1 , V_5 ) ;
V_4 ( V_11 , V_6 , V_5 ) ;
}
V_4 ( V_12 , V_1 [ V_6 ] , V_5 ) ;
if ( ( ( V_6 & V_8 ) == V_8 ) || V_6 == V_2 - 1 ) {
for ( V_7 = 0 ; V_7 < V_8 - ( V_6 & V_8 ) ; V_7 ++ )
V_4 ( V_13 , - 1 , V_5 ) ;
V_4 ( V_14 , V_6 , V_5 ) ;
for ( V_7 = V_6 & ~ V_8 ; V_7 <= V_6 ; V_7 ++ )
V_4 ( V_15 , V_1 [ V_7 ] , V_5 ) ;
for ( V_7 = 0 ; V_7 < V_8 - ( V_6 & V_8 ) ; V_7 ++ )
V_4 ( V_16 , V_6 , V_5 ) ;
V_4 ( V_17 , - 1 , V_5 ) ;
}
}
V_4 ( V_18 , - 1 , V_5 ) ;
}
int F_3 ( char * V_19 , unsigned int V_2 )
{
unsigned int V_6 ;
if ( ! V_19 || ! V_2 || V_19 [ V_2 - 1 ] != 0 )
return 0 ;
V_2 -- ;
for ( V_6 = 0 ; V_6 < V_2 ; V_6 ++ ) {
if ( ! isprint ( V_19 [ V_6 ] ) && ! isspace ( V_19 [ V_6 ] ) )
return 0 ;
}
return 1 ;
}

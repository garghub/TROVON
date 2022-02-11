static int F_1 ( int V_1 , char * V_2 , int V_3 )
{
unsigned int V_4 ;
V_4 = V_2 [ V_3 - 1 ] ;
if ( V_4 == 0 )
F_2 ( L_1 ) ;
V_4 = V_4 % V_1 ;
return V_4 ;
}
static int F_3 ( int V_1 , char * V_2 , int V_3 )
{
unsigned int V_4 = 0 ;
while ( -- V_3 >= 0 )
V_4 += V_2 [ V_3 ] ;
V_4 = V_4 % V_1 ;
return V_4 ;
}
int F_4 ( int V_5 , int V_1 , const char * V_2 , int V_3 )
{
unsigned int V_4 = 0 ;
int V_6 ;
F_5 ( V_3 > 0 ) ;
if ( F_6 ( V_2 , V_3 , & V_6 ) ) {
if ( ( V_6 >= 0 ) && ( V_6 < V_1 ) )
return V_6 ;
goto V_7;
}
if ( V_1 <= 1 )
return 0 ;
V_7:
switch ( V_5 ) {
case V_8 :
V_4 = F_1 ( V_1 , ( char * ) V_2 , V_3 ) ;
break;
case V_9 :
V_4 = F_3 ( V_1 , ( char * ) V_2 , V_3 ) ;
break;
case V_10 :
F_7 ( L_2 ) ;
break;
default:
F_7 ( L_3 , V_5 ) ;
}
F_5 ( V_4 < V_1 ) ;
return V_4 ;
}
int F_8 ( struct V_11 * V_12 , const char * V_2 , int V_3 )
{
unsigned int V_4 ;
F_5 ( V_12 && V_12 -> V_13 ) ;
V_4 = F_4 ( V_12 -> V_14 , V_12 -> V_13 , V_2 , V_3 ) ;
F_5 ( V_4 < V_12 -> V_13 ) ;
return V_4 ;
}

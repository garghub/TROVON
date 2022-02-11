static int F_1 ( const char * V_1 , char * * V_2 )
{
struct V_3 * V_4 ;
long V_5 ;
char * V_6 ;
T_1 V_7 ;
V_4 = F_2 ( V_1 , 0 , 0 ) ;
if ( F_3 ( V_4 ) )
{
F_4 ( V_8 L_1 , V_1 ) ;
return 0 ;
}
V_5 = F_5 ( V_4 -> V_9 . V_10 -> V_11 ) ;
if ( V_5 <= 0 || V_5 > 131072 )
{
F_4 ( V_8 L_2 , V_1 ) ;
F_6 ( V_4 , V_12 -> V_13 ) ;
return 0 ;
}
V_6 = F_7 ( V_5 ) ;
if ( V_6 == NULL )
{
F_4 ( V_8 L_3 , V_1 ) ;
F_6 ( V_4 , V_12 -> V_13 ) ;
return 0 ;
}
V_7 = 0 ;
if ( F_8 ( V_4 , V_6 , V_5 , & V_7 ) != V_5 )
{
F_4 ( V_8 L_4 , V_1 ) ;
F_9 ( V_6 ) ;
F_6 ( V_4 , V_12 -> V_13 ) ;
return 0 ;
}
F_6 ( V_4 , V_12 -> V_13 ) ;
* V_2 = V_6 ;
return ( int ) V_5 ;
}
int F_10 ( const char * V_1 , char * * V_2 )
{
int V_14 ;
T_2 V_15 = F_11 () ;
F_12 ( F_13 () ) ;
V_14 = F_1 ( V_1 , V_2 ) ;
F_12 ( V_15 ) ;
return V_14 ;
}

int F_1 ( const T_1 * V_1 , const T_1 * V_2 , T_2 * V_3 )
{
int V_4 ;
int V_5 = - 2 ;
int V_6 = 0 ;
T_1 * V_7 , * V_8 , * V_9 ;
static const int V_10 [ 8 ] = { 0 , 1 , 0 , - 1 , 0 , - 1 , 0 , 1 } ;
F_2 ( V_1 ) ;
F_2 ( V_2 ) ;
F_3 ( V_3 ) ;
V_7 = F_4 ( V_3 ) ;
V_8 = F_4 ( V_3 ) ;
if ( V_8 == NULL )
goto V_11;
V_6 = ! F_5 ( V_7 , V_1 ) ;
if ( V_6 )
goto V_11;
V_6 = ! F_5 ( V_8 , V_2 ) ;
if ( V_6 )
goto V_11;
if ( F_6 ( V_8 ) ) {
V_5 = F_7 ( V_7 , 1 ) ;
goto V_11;
}
if ( ! F_8 ( V_7 ) && ! F_8 ( V_8 ) ) {
V_5 = 0 ;
goto V_11;
}
V_4 = 0 ;
while ( ! F_9 ( V_8 , V_4 ) )
V_4 ++ ;
V_6 = ! F_10 ( V_8 , V_8 , V_4 ) ;
if ( V_6 )
goto V_11;
if ( V_4 & 1 ) {
V_5 = V_10 [ F_11 ( V_7 ) & 7 ] ;
} else {
V_5 = 1 ;
}
if ( V_8 -> V_12 ) {
V_8 -> V_12 = 0 ;
if ( V_7 -> V_12 )
V_5 = - V_5 ;
}
while ( 1 ) {
if ( F_6 ( V_7 ) ) {
V_5 = F_12 ( V_8 ) ? V_5 : 0 ;
goto V_11;
}
V_4 = 0 ;
while ( ! F_9 ( V_7 , V_4 ) )
V_4 ++ ;
V_6 = ! F_10 ( V_7 , V_7 , V_4 ) ;
if ( V_6 )
goto V_11;
if ( V_4 & 1 ) {
V_5 = V_5 * V_10 [ F_11 ( V_8 ) & 7 ] ;
}
if ( ( V_7 -> V_12 ? ~ F_11 ( V_7 ) : F_11 ( V_7 ) ) & F_11 ( V_8 ) & 2 )
V_5 = - V_5 ;
V_6 = ! F_13 ( V_8 , V_8 , V_7 , V_3 ) ;
if ( V_6 )
goto V_11;
V_9 = V_7 ;
V_7 = V_8 ;
V_8 = V_9 ;
V_9 -> V_12 = 0 ;
}
V_11:
F_14 ( V_3 ) ;
if ( V_6 )
return - 2 ;
else
return V_5 ;
}

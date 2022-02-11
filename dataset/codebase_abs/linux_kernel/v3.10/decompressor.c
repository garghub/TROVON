const struct V_1 * F_1 ( int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] -> V_2 ; V_3 ++ )
if ( V_2 == V_4 [ V_3 ] -> V_2 )
break;
return V_4 [ V_3 ] ;
}
void * F_2 ( struct V_5 * V_6 , unsigned short V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
void * V_11 , * V_12 = NULL ;
int V_13 = 0 ;
if ( F_3 ( V_7 ) ) {
V_12 = F_4 ( V_14 , V_15 ) ;
if ( V_12 == NULL )
return F_5 ( - V_16 ) ;
V_13 = F_6 ( V_6 , & V_12 ,
sizeof( struct V_17 ) , 0 , NULL ,
V_14 , 1 ) ;
if ( V_13 < 0 ) {
V_11 = F_5 ( V_13 ) ;
goto V_18;
}
}
V_11 = V_9 -> V_4 -> V_19 ( V_9 , V_12 , V_13 ) ;
V_18:
F_7 ( V_12 ) ;
return V_11 ;
}

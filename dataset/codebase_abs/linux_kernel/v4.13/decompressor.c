const struct V_1 * F_1 ( int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_4 [ V_3 ] -> V_2 ; V_3 ++ )
if ( V_2 == V_4 [ V_3 ] -> V_2 )
break;
return V_4 [ V_3 ] ;
}
static void * F_2 ( struct V_5 * V_6 , unsigned short V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
void * V_11 = NULL , * V_12 ;
struct V_13 * V_14 = NULL ;
int V_15 = 0 ;
if ( F_3 ( V_7 ) ) {
V_11 = F_4 ( V_16 , V_17 ) ;
if ( V_11 == NULL ) {
V_12 = F_5 ( - V_18 ) ;
goto V_19;
}
V_14 = F_6 ( & V_11 , 1 , 0 ) ;
if ( V_14 == NULL ) {
V_12 = F_5 ( - V_18 ) ;
goto V_19;
}
V_15 = F_7 ( V_6 ,
sizeof( struct V_20 ) , 0 , NULL , V_14 ) ;
if ( V_15 < 0 ) {
V_12 = F_5 ( V_15 ) ;
goto V_19;
}
}
V_12 = F_8 ( V_9 , V_11 , V_15 ) ;
V_19:
F_9 ( V_14 ) ;
F_9 ( V_11 ) ;
return V_12 ;
}
void * F_10 ( struct V_5 * V_6 , unsigned short V_7 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
void * V_21 , * V_12 = F_2 ( V_6 , V_7 ) ;
if ( F_11 ( V_12 ) )
return V_12 ;
V_21 = F_12 ( V_9 , V_12 ) ;
if ( F_11 ( V_21 ) )
F_9 ( V_12 ) ;
return V_21 ;
}

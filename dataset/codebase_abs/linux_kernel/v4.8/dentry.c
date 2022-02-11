static int F_1 ( const struct V_1 * V_1 , struct V_2 * V_2 )
{
unsigned long V_3 ;
int V_4 ;
unsigned V_5 = V_2 -> V_6 ;
if ( V_5 == 1 ) if ( V_2 -> V_7 [ 0 ] == '.' ) goto V_8;
if ( V_5 == 2 ) if ( V_2 -> V_7 [ 0 ] == '.' || V_2 -> V_7 [ 1 ] == '.' ) goto V_8;
F_2 ( V_2 -> V_7 , & V_5 ) ;
V_8:
V_3 = F_3 ( V_1 ) ;
for ( V_4 = 0 ; V_4 < V_5 ; V_4 ++ )
V_3 = F_4 ( F_5 ( F_6 ( V_1 -> V_9 ) -> V_10 , V_2 -> V_7 [ V_4 ] ) , V_3 ) ;
V_2 -> V_3 = F_7 ( V_3 ) ;
return 0 ;
}
static int F_8 ( const struct V_1 * V_1 ,
unsigned int V_6 , const char * V_11 , const struct V_2 * V_7 )
{
unsigned V_12 = V_6 ;
unsigned V_13 = V_7 -> V_6 ;
F_2 ( V_11 , & V_12 ) ;
if ( F_9 ( V_7 -> V_7 , & V_13 ) )
return 1 ;
if ( F_10 ( V_1 -> V_9 , V_11 , V_12 , V_7 -> V_7 , V_13 , 0 ) )
return 1 ;
return 0 ;
}

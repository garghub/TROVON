static int F_1 ( const struct V_1 * V_1 , const struct V_2 * V_2 ,
struct V_3 * V_3 )
{
unsigned long V_4 ;
int V_5 ;
unsigned V_6 = V_3 -> V_7 ;
if ( V_6 == 1 ) if ( V_3 -> V_8 [ 0 ] == '.' ) goto V_9;
if ( V_6 == 2 ) if ( V_3 -> V_8 [ 0 ] == '.' || V_3 -> V_8 [ 1 ] == '.' ) goto V_9;
F_2 ( V_3 -> V_8 , & V_6 ) ;
V_9:
V_4 = F_3 () ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ )
V_4 = F_4 ( F_5 ( F_6 ( V_1 -> V_10 ) -> V_11 , V_3 -> V_8 [ V_5 ] ) , V_4 ) ;
V_3 -> V_4 = F_7 ( V_4 ) ;
return 0 ;
}
static int F_8 ( const struct V_1 * V_12 ,
const struct V_2 * V_13 ,
const struct V_1 * V_1 , const struct V_2 * V_2 ,
unsigned int V_7 , const char * V_14 , const struct V_3 * V_8 )
{
unsigned V_15 = V_7 ;
unsigned V_16 = V_8 -> V_7 ;
F_2 ( V_14 , & V_15 ) ;
if ( F_9 ( V_8 -> V_8 , & V_16 ) )
return 1 ;
if ( F_10 ( V_12 -> V_10 , V_14 , V_15 , V_8 -> V_8 , V_16 , 0 ) )
return 1 ;
return 0 ;
}

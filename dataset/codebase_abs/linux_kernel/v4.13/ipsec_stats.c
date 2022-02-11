int F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 )
return 0 ;
return V_4 ;
}
int F_2 ( struct V_1 * V_2 , T_1 * V_5 )
{
unsigned int V_6 , V_7 = 0 ;
if ( ! V_2 -> V_3 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
strcpy ( V_5 + ( V_7 ++ ) * V_9 ,
V_10 [ V_6 ] . V_11 ) ;
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ )
strcpy ( V_5 + ( V_7 ++ ) * V_9 ,
V_13 [ V_6 ] . V_11 ) ;
return V_4 ;
}
void F_3 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 -> V_3 )
return;
V_14 = F_4 ( V_2 -> V_15 , ( V_16 * ) & V_2 -> V_3 -> V_17 ,
V_8 ) ;
if ( V_14 )
memset ( & V_2 -> V_3 -> V_17 , 0 , sizeof( V_2 -> V_3 -> V_17 ) ) ;
}
int F_5 ( struct V_1 * V_2 , V_16 * V_5 )
{
int V_6 , V_7 = 0 ;
if ( ! V_2 -> V_3 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ )
V_5 [ V_7 ++ ] = F_6 ( & V_2 -> V_3 -> V_17 ,
V_10 , V_6 ) ;
for ( V_6 = 0 ; V_6 < V_12 ; V_6 ++ )
V_5 [ V_7 ++ ] = F_7 ( & V_2 -> V_3 -> V_18 ,
V_13 , V_6 ) ;
return V_4 ;
}

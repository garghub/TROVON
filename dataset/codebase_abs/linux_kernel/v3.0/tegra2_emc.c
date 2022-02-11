static inline void F_1 ( T_1 V_1 , unsigned long V_2 )
{
F_2 ( V_1 , V_3 + V_2 ) ;
}
static inline T_1 F_3 ( unsigned long V_2 )
{
return F_4 ( V_3 + V_2 ) ;
}
long F_5 ( unsigned long V_4 )
{
int V_5 ;
int V_6 = - 1 ;
unsigned long V_7 = V_8 ;
if ( ! V_9 )
return - V_10 ;
if ( ! V_11 )
return - V_10 ;
F_6 ( L_1 , V_12 , V_4 ) ;
V_4 = V_4 / 2 / 1000 ;
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ ) {
if ( V_9 [ V_5 ] . V_4 >= V_4 &&
( V_9 [ V_5 ] . V_4 - V_4 ) < V_7 ) {
V_7 = V_9 [ V_5 ] . V_4 - V_4 ;
V_6 = V_5 ;
}
}
if ( V_6 < 0 )
return - V_10 ;
F_6 ( L_2 , V_12 , V_9 [ V_6 ] . V_4 ) ;
return V_9 [ V_6 ] . V_4 * 2 * 1000 ;
}
int F_7 ( unsigned long V_4 )
{
int V_5 ;
int V_14 ;
if ( ! V_9 )
return - V_10 ;
V_4 = V_4 / 2 / 1000 ;
for ( V_5 = 0 ; V_5 < V_13 ; V_5 ++ )
if ( V_9 [ V_5 ] . V_4 == V_4 )
break;
if ( V_5 >= V_13 )
return - V_10 ;
F_6 ( L_3 , V_12 , V_4 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
F_1 ( V_9 [ V_5 ] . V_16 [ V_14 ] , V_17 [ V_14 ] ) ;
F_3 ( V_9 [ V_5 ] . V_16 [ V_15 - 1 ] ) ;
return 0 ;
}
void F_8 ( const struct V_9 * V_18 , int V_19 )
{
V_9 = V_18 ;
V_13 = V_19 ;
}

void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = V_3 ;
}
void F_2 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_5 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_4 = V_6 ;
F_4 ( & V_2 -> V_7 ) ;
}
int F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 , int V_10 , int V_3 )
{
int V_11 ;
F_1 ( V_2 , V_3 ) ;
V_11 = F_6 ( V_9 , V_2 -> V_12 [ V_10 ] . V_13 ,
V_2 -> V_12 [ V_10 ] . V_14 ) ;
if ( V_11 < 0 )
F_3 ( V_2 ) ;
return V_11 ;
}
int F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_2 -> V_7 ,
V_2 -> V_4 == V_6 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_7 , V_2 -> V_4 == V_6 ) ;
}
int F_11 ( struct V_1 * V_2 , long V_15 )
{
return F_12 ( V_2 -> V_7 ,
V_2 -> V_4 == V_6 ,
V_15 ) ;
}
int F_13 ( struct V_1 * V_2 , const void * V_16 ,
T_1 V_17 , int V_10 )
{
V_2 -> V_12 [ V_10 ] . V_13 = F_14 ( V_16 , V_17 , V_18 ) ;
if ( V_2 -> V_12 [ V_10 ] . V_13 == NULL )
return - V_19 ;
V_2 -> V_12 [ V_10 ] . V_14 = V_17 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , const void * V_16 ,
T_1 V_17 )
{
int V_11 ;
V_11 = F_13 ( V_2 , V_16 , V_17 , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
F_16 ( & V_2 -> V_7 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 , int V_10 )
{
if ( V_2 == NULL )
return;
if ( V_2 -> V_12 [ V_10 ] . V_13 == NULL )
return;
F_18 ( V_2 -> V_12 [ V_10 ] . V_13 ) ;
V_2 -> V_12 [ V_10 ] . V_13 = NULL ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 [ 0 ] . V_13 == NULL )
return;
F_17 ( V_2 , 0 ) ;
}

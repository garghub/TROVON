unsigned char F_1 ( struct V_1 * V_2 , int V_3 )
{
if( V_3 < 0 || V_3 >= 8 )
return 0 ;
return V_2 -> V_4 [ V_3 ] ;
}
unsigned char F_2 ( struct V_1 * V_2 , int V_3 )
{
struct V_5 * V_5 = F_3 ( V_2 -> V_6 . V_7 ) ;
return V_5 -> V_8 . V_9 ( V_2 , V_3 ) ;
return V_2 -> V_4 [ V_3 ] ;
}
void F_4 ( struct V_1 * V_2 , int V_3 ,
unsigned char V_10 )
{
struct V_5 * V_5 = F_3 ( V_2 -> V_6 . V_7 ) ;
V_5 -> V_8 . V_11 ( V_2 , V_3 , V_10 ) ;
}
int F_5 ( struct V_1 * V_2 , int V_12 )
{
struct V_5 * V_5 = F_3 ( V_2 -> V_6 . V_7 ) ;
return V_5 -> V_8 . V_13 ( V_2 , V_12 ) ;
}
int F_6 ( struct V_1 * V_2 , int V_14 )
{
struct V_5 * V_5 = F_3 ( V_2 -> V_6 . V_7 ) ;
return V_5 -> V_8 . V_15 ( V_2 , V_14 ) ;
}
void * F_7 ( struct V_1 * V_2 , void * V_16 )
{
struct V_5 * V_5 = F_3 ( V_2 -> V_6 . V_7 ) ;
return V_5 -> V_8 . V_17 ( V_2 , V_16 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
return V_2 -> V_18 ;
}
void F_9 ( struct V_1 * V_2 , int V_19 )
{
V_2 -> V_18 = V_19 ;
}
enum V_20 F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_21 ;
}
void F_11 ( struct V_1 * V_2 , const char * V_22 )
{
if( ! V_2 )
return;
F_12 ( V_2 -> V_22 , V_22 , sizeof( V_2 -> V_22 ) ) ;
}

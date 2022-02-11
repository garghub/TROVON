void F_1 ( struct V_1 * V_2 )
{
}
static inline long F_2 ( struct V_1 * V_3 , int V_4 )
{
long * V_5 = ( long * ) F_3 ( V_3 ) ;
if ( V_4 == V_6 || V_4 == V_7 )
return 0 ;
return V_5 [ V_4 ] ;
}
static inline int F_4 ( struct V_1 * V_3 ,
int V_4 ,
unsigned long V_8 )
{
unsigned long * V_5 = ( unsigned long * ) F_3 ( V_3 ) ;
if ( V_4 != V_6 && V_4 != V_7 )
V_5 [ V_4 ] = V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_9 ,
const struct V_10 * V_11 ,
unsigned int V_12 , unsigned int V_13 ,
void * V_14 , void T_1 * V_15 )
{
struct V_16 * V_17 = F_3 ( V_9 ) ;
return F_6 ( & V_12 , & V_13 , & V_14 , & V_15 ,
V_17 ,
0 , sizeof( * V_17 ) ) ;
}
const struct V_18 * F_7 ( struct V_1 * V_3 )
{
return & V_19 ;
}
long F_8 ( struct V_1 * V_2 , long V_20 ,
unsigned long V_5 , unsigned long V_8 )
{
int V_21 = 0 ;
switch ( V_20 ) {
case V_22 :
V_21 = F_9 ( V_2 , V_5 , V_8 ) ;
if ( V_21 == 0 && V_20 == V_22 )
F_10 ( V_5 , V_5 + 4 ) ;
break;
default:
V_21 = F_11 ( V_2 , V_20 , V_5 , V_8 ) ;
break;
}
return V_21 ;
}
T_2 unsigned long F_12 ( struct V_16 * V_17 )
{
if ( F_13 ( V_17 ) )
return V_23 ;
return V_17 -> V_24 ;
}
T_2 void F_14 ( struct V_16 * V_17 )
{
F_15 ( V_17 , 0 ) ;
}

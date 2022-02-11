static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if( V_7 -> V_8 != V_5 -> V_9 )
return 0 ;
if( V_7 -> V_10 < V_5 -> V_10 )
return 0 ;
if( ! V_5 -> V_7 || V_5 -> V_7 -> V_10 >= V_7 -> V_10 )
V_5 -> V_7 = V_7 ;
return 0 ;
}
int F_3 ( int V_9 , int V_11 )
{
struct V_4 V_5 ;
if( V_9 == 0xffff )
return V_12 ;
V_5 . V_10 = V_11 ;
V_5 . V_9 = V_9 ;
V_5 . V_7 = NULL ;
for(; ; ) {
F_4 ( & V_13 , NULL , & V_5 , F_1 ) ;
if( V_5 . V_7 == NULL )
return V_12 ;
if( V_5 . V_7 -> V_14 != V_15 )
break;
V_5 . V_10 = V_5 . V_7 -> V_10 + 1 ;
V_5 . V_7 = NULL ;
}
return V_5 . V_7 -> V_10 ;
}
int F_5 ( int V_9 , int V_11 )
{
struct V_4 V_5 = { 0 } ;
if ( ! V_16 || V_9 == 0xffff )
return V_12 ;
V_5 . V_10 = V_11 ;
V_5 . V_9 = V_9 ;
V_5 . V_7 = NULL ;
for(; ; ) {
F_4 ( & V_13 , NULL , & V_5 , F_1 ) ;
if( V_5 . V_7 == NULL )
return V_12 ;
if( V_5 . V_7 -> V_14 != V_15
&& ! V_5 . V_7 -> V_17 )
break;
V_5 . V_10 = V_5 . V_7 -> V_10 + 1 ;
V_5 . V_7 = NULL ;
}
return V_5 . V_7 -> V_10 ;
}
static int F_6 ( struct V_1 * V_2 , void * V_3 )
{
struct V_18 * V_5 = V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if( V_7 -> V_10 == V_5 -> V_10 )
V_5 -> V_7 = V_7 ;
return 0 ;
}
struct V_6 * F_7 ( int V_10 )
{
struct V_18 V_5 ;
V_5 . V_10 = V_10 ;
V_5 . V_7 = NULL ;
F_4 ( & V_13 , NULL , & V_5 , F_6 ) ;
return V_5 . V_7 ;
}
unsigned char F_8 ( int V_10 , int V_19 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
if( ! V_7 )
return 0 ;
return F_9 ( V_7 , V_19 ) ;
}
unsigned char F_10 ( int V_10 , int V_19 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
if( ! V_7 )
return 0 ;
return F_11 ( V_7 , V_19 ) ;
}
void F_12 ( int V_10 , int V_19 , unsigned char V_20 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
if( ! V_7 )
return;
F_13 ( V_7 , V_19 , V_20 ) ;
}
void F_14 ( int V_10 , char * V_21 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
if( ! V_7 )
return;
F_15 ( V_7 , V_21 ) ;
}
int F_16 ( int V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
if( ! V_7 )
return 1 ;
if( F_17 ( V_7 ) )
return 1 ;
F_18 ( V_7 , 1 ) ;
return 0 ;
}
void F_19 ( int V_10 )
{
struct V_6 * V_7 = F_7 ( V_10 ) ;
if( ! V_7 )
return;
F_18 ( V_7 , 0 ) ;
}

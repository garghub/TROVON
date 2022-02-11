struct V_1 * F_1 ( T_1 V_2 )
{
int V_3 = sizeof( struct V_1 ) + V_2 + 1 ;
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 , V_5 | V_6 ) ;
if ( V_4 == NULL )
return NULL ;
V_4 -> V_3 = V_3 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_7 = 0 ;
V_4 -> V_8 = 0 ;
F_3 ( & V_4 -> V_9 ) ;
return V_4 ;
}
void F_4 ( struct V_1 * V_1 , unsigned char V_10 )
{
int V_11 = V_1 -> V_2 + 1 ;
F_5 ( & V_1 -> V_9 ) ;
V_1 -> V_7 = ( V_1 -> V_7 + 1 ) % V_11 ;
if ( V_1 -> V_7 == V_1 -> V_8 )
V_1 -> V_8 = ( V_1 -> V_8 + 1 ) % V_11 ;
V_1 -> V_12 [ V_1 -> V_7 ] = V_10 ;
F_6 ( & V_1 -> V_9 ) ;
}
BOOL F_7 ( struct V_1 * V_1 )
{
BOOL V_13 ;
F_5 ( & V_1 -> V_9 ) ;
V_13 = F_8 ( V_1 ) ;
F_6 ( & V_1 -> V_9 ) ;
return V_13 ;
}
static int F_9 ( struct V_1 * V_1 )
{
int V_11 = V_1 -> V_2 + 1 ;
if ( F_8 ( V_1 ) )
return - 1 ;
V_1 -> V_8 = ( V_1 -> V_8 + 1 ) % V_11 ;
return V_1 -> V_12 [ V_1 -> V_8 ] ;
}
int F_10 ( struct V_1 * V_1 )
{
int V_14 ;
F_5 ( & V_1 -> V_9 ) ;
V_14 = F_9 ( V_1 ) ;
F_6 ( & V_1 -> V_9 ) ;
return V_14 ;
}
int F_11 ( struct V_1 * V_1 , unsigned char * V_12 ,
int V_15 )
{
int V_14 , V_16 = 0 , V_10 ;
F_5 ( & V_1 -> V_9 ) ;
for (; ; ) {
if ( V_15 <= 0 )
break;
V_10 = F_9 ( V_1 ) ;
if ( V_10 < 0 )
break;
* V_12 = ( unsigned char ) ( V_10 ) ;
V_12 ++ ;
V_15 -- ;
V_16 ++ ;
}
V_14 = V_16 ;
F_6 ( & V_1 -> V_9 ) ;
return V_14 ;
}
void F_12 ( struct V_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_13 ( V_1 ) ;
}

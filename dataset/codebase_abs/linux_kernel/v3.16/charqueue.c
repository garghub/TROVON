T_1 * F_1 ( T_2 V_1 )
{
int V_2 = sizeof( T_1 ) + V_1 + 1 ;
T_1 * V_3 = F_2 ( V_2 , V_4 | V_5 ) ;
if ( V_3 == NULL ) {
F_3 ( L_1 ,
V_2 ) ;
return NULL ;
}
V_3 -> V_2 = V_2 ;
V_3 -> V_1 = V_1 ;
V_3 -> V_6 = V_3 -> V_7 = 0 ;
F_4 ( & V_3 -> V_8 ) ;
return V_3 ;
}
void F_5 ( T_1 * V_9 , unsigned char V_10 )
{
int V_11 = V_9 -> V_1 + 1 ;
F_6 ( & V_9 -> V_8 ) ;
V_9 -> V_6 = ( V_9 -> V_6 + 1 ) % V_11 ;
if ( V_9 -> V_6 == V_9 -> V_7 )
V_9 -> V_7 = ( V_9 -> V_7 + 1 ) % V_11 ;
V_9 -> V_12 [ V_9 -> V_6 ] = V_10 ;
F_7 ( & V_9 -> V_8 ) ;
}
BOOL F_8 ( T_1 * V_9 )
{
BOOL V_13 ;
F_6 ( & V_9 -> V_8 ) ;
V_13 = F_9 ( V_9 ) ;
F_7 ( & V_9 -> V_8 ) ;
return V_13 ;
}
static int F_10 ( T_1 * V_9 )
{
int V_11 = V_9 -> V_1 + 1 ;
if ( F_9 ( V_9 ) )
return - 1 ;
V_9 -> V_7 = ( V_9 -> V_7 + 1 ) % V_11 ;
return V_9 -> V_12 [ V_9 -> V_7 ] ;
}
int F_11 ( T_1 * V_9 )
{
int V_14 ;
F_6 ( & V_9 -> V_8 ) ;
V_14 = F_10 ( V_9 ) ;
F_7 ( & V_9 -> V_8 ) ;
return V_14 ;
}
int F_12 ( T_1 * V_9 , unsigned char * V_12 , int V_15 )
{
int V_14 , V_16 = 0 , V_10 ;
F_6 ( & V_9 -> V_8 ) ;
for (; ; ) {
if ( V_15 <= 0 )
break;
V_10 = F_10 ( V_9 ) ;
if ( V_10 < 0 )
break;
* V_12 = ( unsigned char ) ( V_10 ) ;
V_12 ++ ;
V_15 -- ;
V_16 ++ ;
}
V_14 = V_16 ;
F_7 ( & V_9 -> V_8 ) ;
return V_14 ;
}
void F_13 ( T_1 * V_9 )
{
if ( V_9 == NULL )
return;
F_14 ( V_9 ) ;
}

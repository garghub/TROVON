static void * F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
struct V_3 * V_4 = V_5 ;
if ( V_1 == 0 )
goto V_6;
V_1 = F_2 ( V_1 , V_7 ) ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ , V_4 ++ )
if ( ! ( V_4 -> V_9 & V_10 ) ) {
if ( V_1 <= V_11 ) {
V_4 -> V_12 = V_13 ;
V_4 -> V_1 = V_1 ;
V_4 -> V_9 = V_10 | V_14 ;
V_13 += V_1 ;
V_11 -= V_1 ;
return ( void * ) V_4 -> V_12 ;
}
goto V_6;
}
else if ( ! ( V_4 -> V_9 & V_14 ) && ( V_1 <= V_4 -> V_1 ) ) {
V_4 -> V_9 |= V_14 ;
return ( void * ) V_4 -> V_12 ;
}
V_6:
return NULL ;
}
static struct V_3 * F_3 ( void * V_15 )
{
unsigned long V_2 ;
struct V_3 * V_4 = V_5 ;
for ( V_2 = 0 ; V_2 < V_8 ; V_2 ++ , V_4 ++ ) {
if ( ! ( V_4 -> V_9 & V_10 ) )
break;
if ( ( V_4 -> V_9 & V_14 ) &&
( V_4 -> V_12 == ( unsigned long ) V_15 ) )
return V_4 ;
}
return NULL ;
}
static void F_4 ( void * V_15 )
{
struct V_3 * V_4 = F_3 ( V_15 ) ;
if ( V_4 != NULL )
V_4 -> V_9 &= ~ V_14 ;
}
static void * F_5 ( void * V_15 , unsigned long V_1 )
{
struct V_3 * V_4 ;
void * V_16 ;
if ( V_1 == 0 ) {
F_4 ( V_15 ) ;
return NULL ;
}
if ( V_15 == NULL )
return F_1 ( V_1 ) ;
V_4 = F_3 ( V_15 ) ;
if ( V_4 == NULL )
return NULL ;
if ( V_1 <= V_4 -> V_1 )
return V_15 ;
V_16 = F_1 ( V_1 ) ;
memcpy ( V_16 , V_15 , V_4 -> V_1 ) ;
F_4 ( V_15 ) ;
return V_16 ;
}
void * F_6 ( char * V_12 , unsigned long V_17 ,
unsigned long V_18 , unsigned long V_19 )
{
unsigned long V_20 , V_21 ;
V_17 = F_2 ( V_17 , V_18 ) ;
V_7 = V_18 ;
V_8 = V_19 ;
V_21 = V_8 * sizeof( struct V_3 ) ;
V_5 = (struct V_3 * ) F_2 ( ( unsigned long ) V_12 , 8 ) ;
memset ( V_5 , 0 , V_21 ) ;
V_20 = F_2 ( ( unsigned long ) V_5 + V_21 , V_7 ) ;
V_13 = V_20 ;
V_11 = V_17 ;
V_22 . malloc = F_1 ;
V_22 . free = F_4 ;
V_22 . realloc = F_5 ;
return ( void * ) ( V_20 + V_17 ) ;
}

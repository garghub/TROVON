T_1 *
F_1 ( T_2 V_1 , void * V_2 )
{
T_1 * V_3 = ( T_1 * ) F_2 ( sizeof( T_1 ) ) ;
if ( V_3 == NULL ) return NULL ;
F_3 ( & ( V_3 -> V_1 ) ) ;
F_4 ( & V_3 -> V_1 , & V_1 ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_4 = NULL ;
return V_3 ;
}
void
F_5 ( T_1 * V_3 )
{
if ( V_3 == NULL ) return;
F_6 ( & ( V_3 -> V_1 ) ) ;
F_7 ( V_3 ) ;
}
T_3 *
F_8 ()
{
T_3 * V_5 = ( T_3 * ) F_2 ( sizeof( T_3 ) ) ;
if ( V_5 == NULL ) return NULL ;
memset ( V_5 , 0x00 , sizeof( T_3 ) ) ;
return V_5 ;
}
void
F_9 ( T_3 * V_5 )
{
if ( V_5 == NULL ) return;
F_7 ( V_5 ) ;
}
T_1 *
F_10 ( T_3 * V_5 , T_1 * V_3 )
{
T_1 * V_6 , * V_4 ;
if ( V_5 -> V_7 == NULL )
{
V_5 -> V_7 = V_3 ;
return V_3 ;
}
for( V_6 = NULL , V_4 = V_5 -> V_7 ;
V_4 != NULL ;
V_6 = V_4 , V_4 = V_4 -> V_4 )
{
if ( F_11 ( & ( V_4 -> V_1 ) , & ( V_3 -> V_1 ) ) )
{
V_3 -> V_4 = V_4 ;
if ( V_6 == NULL )
V_5 -> V_7 = V_3 ;
else
V_6 -> V_4 = V_3 ;
return V_3 ;
}
if ( F_12 ( & ( V_3 -> V_1 ) , & ( V_4 -> V_1 ) ) )
return NULL ;
}
V_3 -> V_4 = NULL ;
V_6 -> V_4 = V_3 ;
return V_3 ;
}
T_1 *
F_13 ( T_3 * V_5 )
{
return V_5 -> V_7 ;
}
T_1 *
F_14 ( T_3 * V_5 )
{
T_1 * V_3 = V_5 -> V_7 ;
if ( V_5 -> V_7 != NULL )
V_5 -> V_7 = V_5 -> V_7 -> V_4 ;
return V_3 ;
}
T_1 *
F_15 ( T_3 * V_5 , T_2 V_1 )
{
T_1 * V_4 , * V_8 = NULL ;
T_1 * V_9 = NULL ;
if ( V_5 -> V_7 == NULL )
return NULL ;
for ( V_4 = V_5 -> V_7 ; V_4 -> V_4 != NULL ;
V_8 = V_4 , V_4 = V_4 -> V_4 )
{
if ( F_12 ( & ( V_4 -> V_1 ) , & V_1 ) )
{
V_9 = V_4 ;
break;
}
}
if ( F_12 ( & ( V_4 -> V_1 ) , & V_1 ) )
V_9 = V_4 ;
if ( ! V_9 )
return NULL ;
#if 0
if ( prev == NULL)
pq->items = next->next;
else
prev->next = next->next;
#endif
return V_9 ;
}
void
F_16 ( T_3 * V_5 )
{
T_1 * V_3 = V_5 -> V_7 ;
while( V_3 != NULL )
{
printf ( L_1 V_10 L_2 , V_3 -> V_1 ) ;
V_3 = V_3 -> V_4 ;
}
}
T_1 *
F_17 ( T_3 * V_5 )
{
return F_13 ( V_5 ) ;
}
T_1 *
F_18 ( T_1 * * V_3 )
{
T_1 * V_11 ;
if ( V_3 == NULL || * V_3 == NULL )
return NULL ;
V_11 = * V_3 ;
* V_3 = ( * V_3 ) -> V_4 ;
return V_11 ;
}

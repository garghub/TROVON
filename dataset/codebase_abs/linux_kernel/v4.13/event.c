static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (reader, &sp->event_buffer->readers, node)
F_3 ( & V_4 -> V_5 ) ;
}
void F_4 ( struct V_1 * V_2 , void * V_6 , unsigned int V_7 )
{
struct V_8 * V_9 = V_2 -> V_8 ;
struct V_10 * V_11 ;
unsigned long V_12 ;
V_7 = F_5 ( V_7 , V_13 ) ;
F_6 ( & V_2 -> V_14 , V_12 ) ;
V_11 = & V_9 -> V_15 [ V_9 -> V_16 ] ;
F_7 ( V_11 -> V_6 , V_6 , V_7 ) ;
V_11 -> V_7 = V_7 ;
V_11 -> V_17 = V_9 -> V_18 ;
V_9 -> V_16 = ( V_9 -> V_16 + 1 ) % V_19 ;
V_9 -> V_18 ++ ;
F_8 ( & V_2 -> V_14 , V_12 ) ;
F_1 ( V_2 ) ;
}
static inline int F_9 ( struct V_8 * V_20 , struct V_3 * V_21 )
{
return ( V_21 -> V_18 < V_20 -> V_18 ) ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = V_2 -> V_8 ;
struct V_10 * V_11 ;
unsigned int V_22 ;
unsigned long V_12 ;
V_4 -> V_23 = 0 ;
if ( F_11 ( V_4 -> V_5 ,
F_9 ( V_9 , V_4 ) || V_4 -> V_23 ) )
return - V_24 ;
if ( ! F_9 ( V_9 , V_4 ) )
return 0 ;
F_6 ( & V_2 -> V_14 , V_12 ) ;
V_22 = V_9 -> V_16 ;
V_11 = & V_9 -> V_15 [ V_22 ] ;
while ( V_11 -> V_17 < V_4 -> V_18 ) {
V_22 = ( V_22 + 1 ) % V_19 ;
V_11 = & V_9 -> V_15 [ V_22 ] ;
}
memcpy ( V_4 -> V_6 , V_11 -> V_6 , V_11 -> V_7 ) ;
V_4 -> V_7 = V_11 -> V_7 ;
V_4 -> V_18 = V_11 -> V_17 + 1 ;
F_8 ( & V_2 -> V_14 , V_12 ) ;
return V_11 -> V_7 ;
}
void F_12 ( struct V_3 * V_4 )
{
V_4 -> V_23 = 1 ;
F_3 ( & V_4 -> V_5 ) ;
}
void F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_12 ;
V_4 -> V_18 = V_2 -> V_8 -> V_18 ;
F_14 ( & V_4 -> V_5 ) ;
F_6 ( & V_2 -> V_14 , V_12 ) ;
F_15 ( & V_4 -> V_25 , & V_2 -> V_8 -> V_26 ) ;
F_8 ( & V_2 -> V_14 , V_12 ) ;
}
void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_12 ;
F_6 ( & V_2 -> V_14 , V_12 ) ;
F_17 ( & V_4 -> V_25 ) ;
F_8 ( & V_2 -> V_14 , V_12 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_27 ;
V_9 = F_19 ( sizeof( struct V_8 ) , V_28 ) ;
if ( ! V_9 )
return 1 ;
V_9 -> V_16 = 0 ;
V_9 -> V_18 = 1 ;
V_11 = V_9 -> V_15 ;
for ( V_27 = 0 ; V_27 < V_19 ; V_27 ++ , V_11 ++ )
V_11 -> V_17 = 0 ;
F_20 ( & V_9 -> V_26 ) ;
V_2 -> V_8 = V_9 ;
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 -> V_8 ) ;
}

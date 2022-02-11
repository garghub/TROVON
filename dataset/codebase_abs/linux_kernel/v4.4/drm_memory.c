static void * F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 , V_6 =
F_2 ( V_2 ) / V_7 ;
struct V_8 * V_9 ;
struct V_10 * * V_11 ;
struct V_10 * * V_12 ;
void * V_13 ;
V_2 = F_2 ( V_2 ) ;
#ifdef F_3
V_1 -= V_4 -> V_14 -> V_15 -> V_16 ;
#endif
F_4 (agpmem, &dev->agp->memory, head)
if ( V_9 -> V_17 <= V_1
&& ( V_9 -> V_17 + ( V_9 -> V_18 << V_19 ) ) >=
( V_1 + V_2 ) )
break;
if ( & V_9 -> V_20 == & V_4 -> V_21 -> V_22 )
return NULL ;
V_11 = F_5 ( V_6 * sizeof( struct V_10 * ) ) ;
if ( ! V_11 )
return NULL ;
V_12 = ( V_9 -> V_22 -> V_18 + ( V_1 - V_9 -> V_17 ) / V_7 ) ;
for ( V_5 = 0 ; V_5 < V_6 ; ++ V_5 )
V_11 [ V_5 ] = V_12 [ V_5 ] ;
V_13 = F_6 ( V_11 , V_6 , V_23 , V_24 ) ;
F_7 ( V_11 ) ;
return V_13 ;
}
void F_8 ( struct V_25 * V_26 , int V_18 )
{
F_9 ( V_26 ) ;
}
int F_10 ( struct V_25 * V_26 , unsigned int V_16 )
{
return F_11 ( V_26 , V_16 ) ;
}
int F_12 ( struct V_25 * V_26 )
{
return F_13 ( V_26 ) ;
}
static inline void * F_1 ( unsigned long V_1 , unsigned long V_2 ,
struct V_3 * V_4 )
{
return NULL ;
}
void F_14 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
if ( V_4 -> V_21 && V_4 -> V_21 -> V_29 && V_28 -> type == V_30 )
V_28 -> V_26 = F_1 ( V_28 -> V_1 , V_28 -> V_2 , V_4 ) ;
else
V_28 -> V_26 = F_15 ( V_28 -> V_1 , V_28 -> V_2 ) ;
}
void F_16 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
if ( V_4 -> V_21 && V_4 -> V_21 -> V_29 && V_28 -> type == V_30 )
V_28 -> V_26 = F_1 ( V_28 -> V_1 , V_28 -> V_2 , V_4 ) ;
else
V_28 -> V_26 = F_17 ( V_28 -> V_1 , V_28 -> V_2 ) ;
}
void F_18 ( struct V_27 * V_28 , struct V_3 * V_4 )
{
if ( ! V_28 -> V_26 || ! V_28 -> V_2 )
return;
if ( V_4 -> V_21 && V_4 -> V_21 -> V_29 && V_28 -> type == V_30 )
F_19 ( V_28 -> V_26 ) ;
else
F_20 ( V_28 -> V_26 ) ;
}

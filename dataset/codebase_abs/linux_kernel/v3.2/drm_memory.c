int F_1 ( char * V_1 , char * * V_2 , T_1 V_3 ,
int V_4 , int * V_5 , void * V_6 )
{
return 0 ;
}
static void * F_2 ( unsigned long V_3 , unsigned long V_7 ,
struct V_8 * V_9 )
{
unsigned long V_10 , V_11 =
F_3 ( V_7 ) / V_12 ;
struct V_13 * V_14 ;
struct V_15 * * V_16 ;
struct V_15 * * V_17 ;
void * V_18 ;
V_7 = F_3 ( V_7 ) ;
#ifdef F_4
V_3 -= V_9 -> V_19 -> V_20 -> V_2 ;
#endif
F_5 (agpmem, &dev->agp->memory, head)
if ( V_14 -> V_21 <= V_3
&& ( V_14 -> V_21 + ( V_14 -> V_22 << V_23 ) ) >=
( V_3 + V_7 ) )
break;
if ( & V_14 -> V_24 == & V_9 -> V_25 -> V_26 )
return NULL ;
V_16 = F_6 ( V_11 * sizeof( struct V_15 * ) ) ;
if ( ! V_16 )
return NULL ;
V_17 = ( V_14 -> V_26 -> V_22 + ( V_3 - V_14 -> V_21 ) / V_12 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; ++ V_10 )
V_16 [ V_10 ] = V_17 [ V_10 ] ;
V_18 = F_7 ( V_16 , V_11 , V_27 , V_28 ) ;
F_8 ( V_16 ) ;
return V_18 ;
}
void F_9 ( T_2 * V_29 , int V_22 )
{
F_10 ( V_29 ) ;
}
int F_11 ( T_2 * V_29 , unsigned int V_2 )
{
return F_12 ( V_29 , V_2 ) ;
}
int F_13 ( T_2 * V_29 )
{
return F_14 ( V_29 ) ;
}
static inline void * F_2 ( unsigned long V_3 , unsigned long V_7 ,
struct V_8 * V_9 )
{
return NULL ;
}
void F_15 ( struct V_30 * V_31 , struct V_8 * V_9 )
{
if ( F_16 ( V_9 ) &&
V_9 -> V_25 && V_9 -> V_25 -> V_32 && V_31 -> type == V_33 )
V_31 -> V_29 = F_2 ( V_31 -> V_3 , V_31 -> V_7 , V_9 ) ;
else
V_31 -> V_29 = F_17 ( V_31 -> V_3 , V_31 -> V_7 ) ;
}
void F_18 ( struct V_30 * V_31 , struct V_8 * V_9 )
{
if ( F_16 ( V_9 ) &&
V_9 -> V_25 && V_9 -> V_25 -> V_32 && V_31 -> type == V_33 )
V_31 -> V_29 = F_2 ( V_31 -> V_3 , V_31 -> V_7 , V_9 ) ;
else
V_31 -> V_29 = F_19 ( V_31 -> V_3 , V_31 -> V_7 ) ;
}
void F_20 ( struct V_30 * V_31 , struct V_8 * V_9 )
{
if ( ! V_31 -> V_29 || ! V_31 -> V_7 )
return;
if ( F_16 ( V_9 ) &&
V_9 -> V_25 && V_9 -> V_25 -> V_32 && V_31 -> type == V_33 )
F_21 ( V_31 -> V_29 ) ;
else
F_22 ( V_31 -> V_29 ) ;
}

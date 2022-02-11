struct V_1 * F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
F_3 ( V_2 -> V_3 != V_4 ) ;
#endif
if ( F_4 ( V_2 ) )
return NULL ;
V_2 ++ ;
if ( F_5 ( F_6 ( V_2 ) ) )
V_2 = F_7 ( V_2 ) ;
return V_2 ;
}
struct V_1 * F_8 ( struct V_1 * V_5 , unsigned int V_6 )
{
#ifndef F_9
struct V_1 * V_7 = & V_5 [ V_6 - 1 ] ;
#else
struct V_1 * V_2 , * V_7 = NULL ;
unsigned int V_8 ;
F_10 (sgl, sg, nents, i)
V_7 = V_2 ;
#endif
#ifdef F_2
F_3 ( V_5 [ 0 ] . V_3 != V_4 ) ;
F_3 ( ! F_4 ( V_7 ) ) ;
#endif
return V_7 ;
}
void F_11 ( struct V_1 * V_5 , unsigned int V_6 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) * V_6 ) ;
#ifdef F_2
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ )
V_5 [ V_8 ] . V_3 = V_4 ;
}
#endif
F_12 ( & V_5 [ V_6 - 1 ] ) ;
}
void F_13 ( struct V_1 * V_2 , const void * V_9 , unsigned int V_10 )
{
F_11 ( V_2 , 1 ) ;
F_14 ( V_2 , V_9 , V_10 ) ;
}
static struct V_1 * F_15 ( unsigned int V_6 , T_1 V_11 )
{
if ( V_6 == V_12 ) {
void * V_13 = ( void * ) F_16 ( V_11 ) ;
F_17 ( V_13 , V_14 , 1 , V_11 ) ;
return V_13 ;
} else
return F_18 ( V_6 * sizeof( struct V_1 ) , V_11 ) ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_6 == V_12 ) {
F_20 ( V_2 ) ;
F_21 ( ( unsigned long ) V_2 ) ;
} else
F_22 ( V_2 ) ;
}
void F_23 ( struct V_15 * V_16 , unsigned int V_17 ,
T_2 * V_18 )
{
struct V_1 * V_5 , * V_19 ;
if ( F_5 ( ! V_16 -> V_5 ) )
return;
V_5 = V_16 -> V_5 ;
while ( V_16 -> V_20 ) {
unsigned int V_21 = V_16 -> V_20 ;
unsigned int V_22 ;
if ( V_21 > V_17 ) {
V_19 = F_7 ( & V_5 [ V_17 - 1 ] ) ;
V_21 = V_17 ;
V_22 = V_21 - 1 ;
} else {
V_22 = V_21 ;
V_19 = NULL ;
}
V_16 -> V_20 -= V_22 ;
V_18 ( V_5 , V_21 ) ;
V_5 = V_19 ;
}
V_16 -> V_5 = NULL ;
}
void F_24 ( struct V_15 * V_16 )
{
F_23 ( V_16 , V_12 , F_19 ) ;
}
int F_25 ( struct V_15 * V_16 , unsigned int V_6 ,
unsigned int V_17 , T_1 V_11 ,
T_3 * V_23 )
{
struct V_1 * V_2 , * V_24 ;
unsigned int V_25 ;
#ifndef F_9
F_3 ( V_6 > V_17 ) ;
#endif
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_25 = V_6 ;
V_24 = NULL ;
do {
unsigned int V_22 , V_21 = V_25 ;
if ( V_21 > V_17 ) {
V_21 = V_17 ;
V_22 = V_21 - 1 ;
} else
V_22 = V_21 ;
V_25 -= V_22 ;
V_2 = V_23 ( V_21 , V_11 ) ;
if ( F_5 ( ! V_2 ) ) {
if ( V_24 )
V_16 -> V_6 = ++ V_16 -> V_20 ;
return - V_26 ;
}
F_11 ( V_2 , V_21 ) ;
V_16 -> V_6 = V_16 -> V_20 += V_22 ;
if ( V_24 )
F_26 ( V_24 , V_17 , V_2 ) ;
else
V_16 -> V_5 = V_2 ;
if ( ! V_25 )
F_12 ( & V_2 [ V_22 - 1 ] ) ;
V_11 &= ~ V_27 ;
V_11 |= V_28 ;
V_24 = V_2 ;
} while ( V_25 );
return 0 ;
}
int F_27 ( struct V_15 * V_16 , unsigned int V_6 , T_1 V_11 )
{
int V_7 ;
V_7 = F_25 ( V_16 , V_6 , V_12 ,
V_11 , F_15 ) ;
if ( F_5 ( V_7 ) )
F_23 ( V_16 , V_12 , F_19 ) ;
return V_7 ;
}
void F_28 ( struct V_29 * V_30 , struct V_1 * V_5 ,
unsigned int V_6 , unsigned int V_31 )
{
memset ( V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 -> V_32 = V_5 ;
V_30 -> V_33 = V_6 ;
V_30 -> V_34 = 0 ;
F_29 ( ! ( V_31 & ( V_35 | V_36 ) ) ) ;
V_30 -> V_37 = V_31 ;
}
bool F_30 ( struct V_29 * V_30 )
{
unsigned int V_38 , V_39 ;
if ( ! V_30 -> V_33 )
return false ;
F_31 ( V_30 ) ;
while ( V_30 -> V_34 == V_30 -> V_32 -> V_40 ) {
if ( -- V_30 -> V_33 ) {
V_30 -> V_32 = F_1 ( V_30 -> V_32 ) ;
V_30 -> V_34 = 0 ;
} else
return false ;
}
V_38 = V_30 -> V_32 -> V_41 + V_30 -> V_34 ;
V_39 = V_30 -> V_32 -> V_40 - V_30 -> V_34 ;
V_30 -> V_42 = F_32 ( F_33 ( V_30 -> V_32 ) , V_38 >> V_43 ) ;
V_38 &= ~ V_44 ;
V_30 -> V_40 = F_34 (unsigned int, len, PAGE_SIZE - off) ;
V_30 -> V_45 = V_30 -> V_40 ;
if ( V_30 -> V_37 & V_46 )
V_30 -> V_47 = F_35 ( V_30 -> V_42 ) + V_38 ;
else
V_30 -> V_47 = F_36 ( V_30 -> V_42 ) + V_38 ;
return true ;
}
void F_31 ( struct V_29 * V_30 )
{
F_29 ( V_30 -> V_45 > V_30 -> V_40 ) ;
if ( V_30 -> V_47 ) {
V_30 -> V_34 += V_30 -> V_45 ;
if ( V_30 -> V_37 & V_35 )
F_37 ( V_30 -> V_42 ) ;
if ( V_30 -> V_37 & V_46 ) {
F_29 ( ! F_38 () ) ;
F_39 ( V_30 -> V_47 ) ;
} else
F_40 ( V_30 -> V_42 ) ;
V_30 -> V_42 = NULL ;
V_30 -> V_47 = NULL ;
V_30 -> V_40 = 0 ;
V_30 -> V_45 = 0 ;
}
}
static T_4 F_41 ( struct V_1 * V_5 , unsigned int V_6 ,
void * V_9 , T_4 V_10 , int V_48 )
{
unsigned int V_41 = 0 ;
struct V_29 V_30 ;
unsigned long V_31 ;
unsigned int V_49 = V_46 ;
if ( V_48 )
V_49 |= V_36 ;
else
V_49 |= V_35 ;
F_28 ( & V_30 , V_5 , V_6 , V_49 ) ;
F_42 ( V_31 ) ;
while ( F_30 ( & V_30 ) && V_41 < V_10 ) {
unsigned int V_39 ;
V_39 = F_43 ( V_30 . V_40 , V_10 - V_41 ) ;
if ( V_48 )
memcpy ( V_9 + V_41 , V_30 . V_47 , V_39 ) ;
else
memcpy ( V_30 . V_47 , V_9 + V_41 , V_39 ) ;
V_41 += V_39 ;
}
F_31 ( & V_30 ) ;
F_44 ( V_31 ) ;
return V_41 ;
}
T_4 F_45 ( struct V_1 * V_5 , unsigned int V_6 ,
void * V_9 , T_4 V_10 )
{
return F_41 ( V_5 , V_6 , V_9 , V_10 , 0 ) ;
}
T_4 F_46 ( struct V_1 * V_5 , unsigned int V_6 ,
void * V_9 , T_4 V_10 )
{
return F_41 ( V_5 , V_6 , V_9 , V_10 , 1 ) ;
}

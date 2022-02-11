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
int F_28 ( struct V_15 * V_27 ,
struct V_28 * * V_29 , unsigned int V_30 ,
unsigned long V_31 , unsigned long V_32 ,
T_1 V_11 )
{
unsigned int V_33 ;
unsigned int V_8 ;
unsigned int V_34 ;
int V_7 ;
struct V_1 * V_35 ;
V_33 = 1 ;
for ( V_8 = 1 ; V_8 < V_30 ; ++ V_8 )
if ( F_29 ( V_29 [ V_8 ] ) != F_29 ( V_29 [ V_8 - 1 ] ) + 1 )
++ V_33 ;
V_7 = F_27 ( V_27 , V_33 , V_11 ) ;
if ( F_5 ( V_7 ) )
return V_7 ;
V_34 = 0 ;
F_10 (sgt->sgl, s, sgt->orig_nents, i) {
unsigned long V_36 ;
unsigned int V_37 ;
for ( V_37 = V_34 + 1 ; V_37 < V_30 ; ++ V_37 )
if ( F_29 ( V_29 [ V_37 ] ) !=
F_29 ( V_29 [ V_37 - 1 ] ) + 1 )
break;
V_36 = ( ( V_37 - V_34 ) << V_38 ) - V_31 ;
F_30 ( V_35 , V_29 [ V_34 ] , F_31 ( V_32 , V_36 ) , V_31 ) ;
V_32 -= V_36 ;
V_31 = 0 ;
V_34 = V_37 ;
}
return 0 ;
}
void F_32 ( struct V_39 * V_40 , struct V_1 * V_5 ,
unsigned int V_6 , unsigned int V_41 )
{
memset ( V_40 , 0 , sizeof( struct V_39 ) ) ;
V_40 -> V_42 = V_5 ;
V_40 -> V_43 = V_6 ;
V_40 -> V_44 = 0 ;
F_33 ( ! ( V_41 & ( V_45 | V_46 ) ) ) ;
V_40 -> V_47 = V_41 ;
}
bool F_34 ( struct V_39 * V_40 )
{
unsigned int V_48 , V_49 ;
if ( ! V_40 -> V_43 )
return false ;
F_35 ( V_40 ) ;
while ( V_40 -> V_44 == V_40 -> V_42 -> V_50 ) {
if ( -- V_40 -> V_43 ) {
V_40 -> V_42 = F_1 ( V_40 -> V_42 ) ;
V_40 -> V_44 = 0 ;
} else
return false ;
}
V_48 = V_40 -> V_42 -> V_31 + V_40 -> V_44 ;
V_49 = V_40 -> V_42 -> V_50 - V_40 -> V_44 ;
V_40 -> V_28 = F_36 ( F_37 ( V_40 -> V_42 ) , V_48 >> V_38 ) ;
V_48 &= ~ V_51 ;
V_40 -> V_50 = F_38 (unsigned int, len, PAGE_SIZE - off) ;
V_40 -> V_52 = V_40 -> V_50 ;
if ( V_40 -> V_47 & V_53 )
V_40 -> V_54 = F_39 ( V_40 -> V_28 ) + V_48 ;
else
V_40 -> V_54 = F_40 ( V_40 -> V_28 ) + V_48 ;
return true ;
}
void F_35 ( struct V_39 * V_40 )
{
F_33 ( V_40 -> V_52 > V_40 -> V_50 ) ;
if ( V_40 -> V_54 ) {
V_40 -> V_44 += V_40 -> V_52 ;
if ( V_40 -> V_47 & V_45 )
F_41 ( V_40 -> V_28 ) ;
if ( V_40 -> V_47 & V_53 ) {
F_33 ( ! F_42 () ) ;
F_43 ( V_40 -> V_54 ) ;
} else
F_44 ( V_40 -> V_28 ) ;
V_40 -> V_28 = NULL ;
V_40 -> V_54 = NULL ;
V_40 -> V_50 = 0 ;
V_40 -> V_52 = 0 ;
}
}
static T_4 F_45 ( struct V_1 * V_5 , unsigned int V_6 ,
void * V_9 , T_4 V_10 , int V_55 )
{
unsigned int V_31 = 0 ;
struct V_39 V_40 ;
unsigned long V_41 ;
unsigned int V_56 = V_53 ;
if ( V_55 )
V_56 |= V_46 ;
else
V_56 |= V_45 ;
F_32 ( & V_40 , V_5 , V_6 , V_56 ) ;
F_46 ( V_41 ) ;
while ( F_34 ( & V_40 ) && V_31 < V_10 ) {
unsigned int V_49 ;
V_49 = F_31 ( V_40 . V_50 , V_10 - V_31 ) ;
if ( V_55 )
memcpy ( V_9 + V_31 , V_40 . V_54 , V_49 ) ;
else
memcpy ( V_40 . V_54 , V_9 + V_31 , V_49 ) ;
V_31 += V_49 ;
}
F_35 ( & V_40 ) ;
F_47 ( V_41 ) ;
return V_31 ;
}
T_4 F_48 ( struct V_1 * V_5 , unsigned int V_6 ,
void * V_9 , T_4 V_10 )
{
return F_45 ( V_5 , V_6 , V_9 , V_10 , 0 ) ;
}
T_4 F_49 ( struct V_1 * V_5 , unsigned int V_6 ,
void * V_9 , T_4 V_10 )
{
return F_45 ( V_5 , V_6 , V_9 , V_10 , 1 ) ;
}

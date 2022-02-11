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
int F_8 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_2 ; V_2 = F_1 ( V_2 ) )
V_5 ++ ;
return V_5 ;
}
struct V_1 * F_9 ( struct V_1 * V_6 , unsigned int V_5 )
{
#ifndef F_10
struct V_1 * V_7 = & V_6 [ V_5 - 1 ] ;
#else
struct V_1 * V_2 , * V_7 = NULL ;
unsigned int V_8 ;
F_11 (sgl, sg, nents, i)
V_7 = V_2 ;
#endif
#ifdef F_2
F_3 ( V_6 [ 0 ] . V_3 != V_4 ) ;
F_3 ( ! F_4 ( V_7 ) ) ;
#endif
return V_7 ;
}
void F_12 ( struct V_1 * V_6 , unsigned int V_5 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) * V_5 ) ;
#ifdef F_2
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < V_5 ; V_8 ++ )
V_6 [ V_8 ] . V_3 = V_4 ;
}
#endif
F_13 ( & V_6 [ V_5 - 1 ] ) ;
}
void F_14 ( struct V_1 * V_2 , const void * V_9 , unsigned int V_10 )
{
F_12 ( V_2 , 1 ) ;
F_15 ( V_2 , V_9 , V_10 ) ;
}
static struct V_1 * F_16 ( unsigned int V_5 , T_1 V_11 )
{
if ( V_5 == V_12 ) {
void * V_13 = ( void * ) F_17 ( V_11 ) ;
F_18 ( V_13 , V_14 , 1 , V_11 ) ;
return V_13 ;
} else
return F_19 ( V_5 * sizeof( struct V_1 ) , V_11 ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int V_5 )
{
if ( V_5 == V_12 ) {
F_21 ( V_2 ) ;
F_22 ( ( unsigned long ) V_2 ) ;
} else
F_23 ( V_2 ) ;
}
void F_24 ( struct V_15 * V_16 , unsigned int V_17 ,
T_2 * V_18 )
{
struct V_1 * V_6 , * V_19 ;
if ( F_5 ( ! V_16 -> V_6 ) )
return;
V_6 = V_16 -> V_6 ;
while ( V_16 -> V_20 ) {
unsigned int V_21 = V_16 -> V_20 ;
unsigned int V_22 ;
if ( V_21 > V_17 ) {
V_19 = F_7 ( & V_6 [ V_17 - 1 ] ) ;
V_21 = V_17 ;
V_22 = V_21 - 1 ;
} else {
V_22 = V_21 ;
V_19 = NULL ;
}
V_16 -> V_20 -= V_22 ;
V_18 ( V_6 , V_21 ) ;
V_6 = V_19 ;
}
V_16 -> V_6 = NULL ;
}
void F_25 ( struct V_15 * V_16 )
{
F_24 ( V_16 , V_12 , F_20 ) ;
}
int F_26 ( struct V_15 * V_16 , unsigned int V_5 ,
unsigned int V_17 , T_1 V_11 ,
T_3 * V_23 )
{
struct V_1 * V_2 , * V_24 ;
unsigned int V_25 ;
#ifndef F_10
if ( F_27 ( V_5 > V_17 ) )
return - V_26 ;
#endif
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
V_25 = V_5 ;
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
V_16 -> V_5 = ++ V_16 -> V_20 ;
return - V_27 ;
}
F_12 ( V_2 , V_21 ) ;
V_16 -> V_5 = V_16 -> V_20 += V_22 ;
if ( V_24 )
F_28 ( V_24 , V_17 , V_2 ) ;
else
V_16 -> V_6 = V_2 ;
if ( ! V_25 )
F_13 ( & V_2 [ V_22 - 1 ] ) ;
V_24 = V_2 ;
} while ( V_25 );
return 0 ;
}
int F_29 ( struct V_15 * V_16 , unsigned int V_5 , T_1 V_11 )
{
int V_7 ;
V_7 = F_26 ( V_16 , V_5 , V_12 ,
V_11 , F_16 ) ;
if ( F_5 ( V_7 ) )
F_24 ( V_16 , V_12 , F_20 ) ;
return V_7 ;
}
int F_30 ( struct V_15 * V_28 ,
struct V_29 * * V_30 , unsigned int V_31 ,
unsigned long V_32 , unsigned long V_33 ,
T_1 V_11 )
{
unsigned int V_34 ;
unsigned int V_8 ;
unsigned int V_35 ;
int V_7 ;
struct V_1 * V_36 ;
V_34 = 1 ;
for ( V_8 = 1 ; V_8 < V_31 ; ++ V_8 )
if ( F_31 ( V_30 [ V_8 ] ) != F_31 ( V_30 [ V_8 - 1 ] ) + 1 )
++ V_34 ;
V_7 = F_29 ( V_28 , V_34 , V_11 ) ;
if ( F_5 ( V_7 ) )
return V_7 ;
V_35 = 0 ;
F_11 (sgt->sgl, s, sgt->orig_nents, i) {
unsigned long V_37 ;
unsigned int V_38 ;
for ( V_38 = V_35 + 1 ; V_38 < V_31 ; ++ V_38 )
if ( F_31 ( V_30 [ V_38 ] ) !=
F_31 ( V_30 [ V_38 - 1 ] ) + 1 )
break;
V_37 = ( ( V_38 - V_35 ) << V_39 ) - V_32 ;
F_32 ( V_36 , V_30 [ V_35 ] , F_33 ( V_33 , V_37 ) , V_32 ) ;
V_33 -= V_37 ;
V_32 = 0 ;
V_35 = V_38 ;
}
return 0 ;
}
void F_34 ( struct V_40 * V_41 ,
struct V_1 * V_42 , unsigned int V_5 ,
unsigned long V_43 )
{
V_41 -> V_44 = 0 ;
V_41 -> V_45 = V_5 ;
V_41 -> V_29 = NULL ;
V_41 -> V_2 = V_42 ;
V_41 -> V_46 = V_43 ;
}
static int F_35 ( struct V_1 * V_2 )
{
return F_36 ( V_2 -> V_32 + V_2 -> V_47 ) >> V_39 ;
}
bool F_37 ( struct V_40 * V_41 )
{
if ( ! V_41 -> V_45 || ! V_41 -> V_2 )
return false ;
V_41 -> V_46 += V_41 -> V_44 ;
V_41 -> V_44 = 1 ;
while ( V_41 -> V_46 >= F_35 ( V_41 -> V_2 ) ) {
V_41 -> V_46 -= F_35 ( V_41 -> V_2 ) ;
V_41 -> V_2 = F_1 ( V_41 -> V_2 ) ;
if ( ! -- V_41 -> V_45 || ! V_41 -> V_2 )
return false ;
}
V_41 -> V_29 = F_38 ( F_39 ( V_41 -> V_2 ) , V_41 -> V_46 ) ;
return true ;
}
void F_40 ( struct V_48 * V_49 , struct V_1 * V_6 ,
unsigned int V_5 , unsigned int V_50 )
{
memset ( V_49 , 0 , sizeof( struct V_48 ) ) ;
F_34 ( & V_49 -> V_41 , V_6 , V_5 , 0 ) ;
F_41 ( ! ( V_50 & ( V_51 | V_52 ) ) ) ;
V_49 -> V_53 = V_50 ;
}
bool F_42 ( struct V_48 * V_49 )
{
F_43 ( V_49 ) ;
if ( ! V_49 -> V_54 ) {
struct V_1 * V_2 ;
unsigned long V_43 ;
if ( ! F_37 ( & V_49 -> V_41 ) )
return false ;
V_2 = V_49 -> V_41 . V_2 ;
V_43 = V_49 -> V_41 . V_46 ;
V_49 -> V_55 = V_43 ? 0 : V_2 -> V_32 ;
V_49 -> V_54 = V_2 -> V_32 + V_2 -> V_47 -
( V_43 << V_39 ) - V_49 -> V_55 ;
V_49 -> V_54 = F_44 (unsigned long, miter->__remaining,
PAGE_SIZE - miter->__offset) ;
}
V_49 -> V_29 = V_49 -> V_41 . V_29 ;
V_49 -> V_56 = V_49 -> V_47 = V_49 -> V_54 ;
if ( V_49 -> V_53 & V_57 )
V_49 -> V_58 = F_45 ( V_49 -> V_29 ) + V_49 -> V_55 ;
else
V_49 -> V_58 = F_46 ( V_49 -> V_29 ) + V_49 -> V_55 ;
return true ;
}
void F_43 ( struct V_48 * V_49 )
{
F_41 ( V_49 -> V_56 > V_49 -> V_47 ) ;
if ( V_49 -> V_58 ) {
V_49 -> V_55 += V_49 -> V_56 ;
V_49 -> V_54 -= V_49 -> V_56 ;
if ( V_49 -> V_53 & V_51 )
F_47 ( V_49 -> V_29 ) ;
if ( V_49 -> V_53 & V_57 ) {
F_27 ( F_48 () ) ;
F_49 ( V_49 -> V_58 ) ;
} else
F_50 ( V_49 -> V_29 ) ;
V_49 -> V_29 = NULL ;
V_49 -> V_58 = NULL ;
V_49 -> V_47 = 0 ;
V_49 -> V_56 = 0 ;
}
}
static T_4 F_51 ( struct V_1 * V_6 , unsigned int V_5 ,
void * V_9 , T_4 V_10 , int V_59 )
{
unsigned int V_32 = 0 ;
struct V_48 V_49 ;
unsigned long V_50 ;
unsigned int V_60 = V_57 ;
if ( V_59 )
V_60 |= V_52 ;
else
V_60 |= V_51 ;
F_40 ( & V_49 , V_6 , V_5 , V_60 ) ;
F_52 ( V_50 ) ;
while ( F_42 ( & V_49 ) && V_32 < V_10 ) {
unsigned int V_61 ;
V_61 = F_33 ( V_49 . V_47 , V_10 - V_32 ) ;
if ( V_59 )
memcpy ( V_9 + V_32 , V_49 . V_58 , V_61 ) ;
else
memcpy ( V_49 . V_58 , V_9 + V_32 , V_61 ) ;
V_32 += V_61 ;
}
F_43 ( & V_49 ) ;
F_53 ( V_50 ) ;
return V_32 ;
}
T_4 F_54 ( struct V_1 * V_6 , unsigned int V_5 ,
void * V_9 , T_4 V_10 )
{
return F_51 ( V_6 , V_5 , V_9 , V_10 , 0 ) ;
}
T_4 F_55 ( struct V_1 * V_6 , unsigned int V_5 ,
void * V_9 , T_4 V_10 )
{
return F_51 ( V_6 , V_5 , V_9 , V_10 , 1 ) ;
}

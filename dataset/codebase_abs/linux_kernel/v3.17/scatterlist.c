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
bool V_18 , T_2 * V_19 )
{
struct V_1 * V_6 , * V_20 ;
if ( F_5 ( ! V_16 -> V_6 ) )
return;
V_6 = V_16 -> V_6 ;
while ( V_16 -> V_21 ) {
unsigned int V_22 = V_16 -> V_21 ;
unsigned int V_23 ;
if ( V_22 > V_17 ) {
V_20 = F_7 ( & V_6 [ V_17 - 1 ] ) ;
V_22 = V_17 ;
V_23 = V_22 - 1 ;
} else {
V_23 = V_22 ;
V_20 = NULL ;
}
V_16 -> V_21 -= V_23 ;
if ( ! V_18 ) {
V_19 ( V_6 , V_22 ) ;
V_18 = false ;
}
V_6 = V_20 ;
}
V_16 -> V_6 = NULL ;
}
void F_25 ( struct V_15 * V_16 )
{
F_24 ( V_16 , V_12 , false , F_20 ) ;
}
int F_26 ( struct V_15 * V_16 , unsigned int V_5 ,
unsigned int V_17 , struct V_1 * V_24 ,
T_1 V_11 , T_3 * V_25 )
{
struct V_1 * V_2 , * V_26 ;
unsigned int V_27 ;
memset ( V_16 , 0 , sizeof( * V_16 ) ) ;
if ( V_5 == 0 )
return - V_28 ;
#ifndef F_10
if ( F_27 ( V_5 > V_17 ) )
return - V_28 ;
#endif
V_27 = V_5 ;
V_26 = NULL ;
do {
unsigned int V_23 , V_22 = V_27 ;
if ( V_22 > V_17 ) {
V_22 = V_17 ;
V_23 = V_22 - 1 ;
} else
V_23 = V_22 ;
V_27 -= V_23 ;
if ( V_24 ) {
V_2 = V_24 ;
V_24 = NULL ;
} else {
V_2 = V_25 ( V_22 , V_11 ) ;
}
if ( F_5 ( ! V_2 ) ) {
if ( V_26 )
V_16 -> V_5 = ++ V_16 -> V_21 ;
return - V_29 ;
}
F_12 ( V_2 , V_22 ) ;
V_16 -> V_5 = V_16 -> V_21 += V_23 ;
if ( V_26 )
F_28 ( V_26 , V_17 , V_2 ) ;
else
V_16 -> V_6 = V_2 ;
if ( ! V_27 )
F_13 ( & V_2 [ V_23 - 1 ] ) ;
V_26 = V_2 ;
} while ( V_27 );
return 0 ;
}
int F_29 ( struct V_15 * V_16 , unsigned int V_5 , T_1 V_11 )
{
int V_7 ;
V_7 = F_26 ( V_16 , V_5 , V_12 ,
NULL , V_11 , F_16 ) ;
if ( F_5 ( V_7 ) )
F_24 ( V_16 , V_12 , false , F_20 ) ;
return V_7 ;
}
int F_30 ( struct V_15 * V_30 ,
struct V_31 * * V_32 , unsigned int V_33 ,
unsigned long V_34 , unsigned long V_35 ,
T_1 V_11 )
{
unsigned int V_36 ;
unsigned int V_8 ;
unsigned int V_37 ;
int V_7 ;
struct V_1 * V_38 ;
V_36 = 1 ;
for ( V_8 = 1 ; V_8 < V_33 ; ++ V_8 )
if ( F_31 ( V_32 [ V_8 ] ) != F_31 ( V_32 [ V_8 - 1 ] ) + 1 )
++ V_36 ;
V_7 = F_29 ( V_30 , V_36 , V_11 ) ;
if ( F_5 ( V_7 ) )
return V_7 ;
V_37 = 0 ;
F_11 (sgt->sgl, s, sgt->orig_nents, i) {
unsigned long V_39 ;
unsigned int V_40 ;
for ( V_40 = V_37 + 1 ; V_40 < V_33 ; ++ V_40 )
if ( F_31 ( V_32 [ V_40 ] ) !=
F_31 ( V_32 [ V_40 - 1 ] ) + 1 )
break;
V_39 = ( ( V_40 - V_37 ) << V_41 ) - V_34 ;
F_32 ( V_38 , V_32 [ V_37 ] , F_33 ( V_35 , V_39 ) , V_34 ) ;
V_35 -= V_39 ;
V_34 = 0 ;
V_37 = V_40 ;
}
return 0 ;
}
void F_34 ( struct V_42 * V_43 ,
struct V_1 * V_44 , unsigned int V_5 ,
unsigned long V_45 )
{
V_43 -> V_46 = 0 ;
V_43 -> V_47 = V_5 ;
V_43 -> V_2 = V_44 ;
V_43 -> V_48 = V_45 ;
}
static int F_35 ( struct V_1 * V_2 )
{
return F_36 ( V_2 -> V_34 + V_2 -> V_49 ) >> V_41 ;
}
bool F_37 ( struct V_42 * V_43 )
{
if ( ! V_43 -> V_47 || ! V_43 -> V_2 )
return false ;
V_43 -> V_48 += V_43 -> V_46 ;
V_43 -> V_46 = 1 ;
while ( V_43 -> V_48 >= F_35 ( V_43 -> V_2 ) ) {
V_43 -> V_48 -= F_35 ( V_43 -> V_2 ) ;
V_43 -> V_2 = F_1 ( V_43 -> V_2 ) ;
if ( ! -- V_43 -> V_47 || ! V_43 -> V_2 )
return false ;
}
return true ;
}
void F_38 ( struct V_50 * V_51 , struct V_1 * V_6 ,
unsigned int V_5 , unsigned int V_52 )
{
memset ( V_51 , 0 , sizeof( struct V_50 ) ) ;
F_34 ( & V_51 -> V_43 , V_6 , V_5 , 0 ) ;
F_39 ( ! ( V_52 & ( V_53 | V_54 ) ) ) ;
V_51 -> V_55 = V_52 ;
}
static bool F_40 ( struct V_50 * V_51 )
{
if ( ! V_51 -> V_56 ) {
struct V_1 * V_2 ;
unsigned long V_45 ;
if ( ! F_37 ( & V_51 -> V_43 ) )
return false ;
V_2 = V_51 -> V_43 . V_2 ;
V_45 = V_51 -> V_43 . V_48 ;
V_51 -> V_57 = V_45 ? 0 : V_2 -> V_34 ;
V_51 -> V_56 = V_2 -> V_34 + V_2 -> V_49 -
( V_45 << V_41 ) - V_51 -> V_57 ;
V_51 -> V_56 = F_41 (unsigned long, miter->__remaining,
PAGE_SIZE - miter->__offset) ;
}
return true ;
}
bool F_42 ( struct V_50 * V_51 , T_4 V_34 )
{
F_43 ( V_51 ) ;
while ( V_34 ) {
T_4 V_58 ;
if ( ! F_40 ( V_51 ) )
return false ;
V_58 = F_41 ( T_4 , V_34 , V_51 -> V_56 ) ;
V_51 -> V_57 += V_58 ;
V_51 -> V_56 -= V_58 ;
V_34 -= V_58 ;
}
return true ;
}
bool F_44 ( struct V_50 * V_51 )
{
F_43 ( V_51 ) ;
if ( ! F_40 ( V_51 ) )
return false ;
V_51 -> V_31 = F_45 ( & V_51 -> V_43 ) ;
V_51 -> V_58 = V_51 -> V_49 = V_51 -> V_56 ;
if ( V_51 -> V_55 & V_59 )
V_51 -> V_60 = F_46 ( V_51 -> V_31 ) + V_51 -> V_57 ;
else
V_51 -> V_60 = F_47 ( V_51 -> V_31 ) + V_51 -> V_57 ;
return true ;
}
void F_43 ( struct V_50 * V_51 )
{
F_39 ( V_51 -> V_58 > V_51 -> V_49 ) ;
if ( V_51 -> V_60 ) {
V_51 -> V_57 += V_51 -> V_58 ;
V_51 -> V_56 -= V_51 -> V_58 ;
if ( ( V_51 -> V_55 & V_53 ) &&
! F_48 ( V_51 -> V_31 ) )
F_49 ( V_51 -> V_31 ) ;
if ( V_51 -> V_55 & V_59 ) {
F_27 ( F_50 () ) ;
F_51 ( V_51 -> V_60 ) ;
} else
F_52 ( V_51 -> V_31 ) ;
V_51 -> V_31 = NULL ;
V_51 -> V_60 = NULL ;
V_51 -> V_49 = 0 ;
V_51 -> V_58 = 0 ;
}
}
static T_5 F_53 ( struct V_1 * V_6 , unsigned int V_5 ,
void * V_9 , T_5 V_10 , T_4 V_61 ,
bool V_62 )
{
unsigned int V_34 = 0 ;
struct V_50 V_51 ;
unsigned long V_52 ;
unsigned int V_63 = V_59 ;
if ( V_62 )
V_63 |= V_54 ;
else
V_63 |= V_53 ;
F_38 ( & V_51 , V_6 , V_5 , V_63 ) ;
if ( ! F_42 ( & V_51 , V_61 ) )
return false ;
F_54 ( V_52 ) ;
while ( F_44 ( & V_51 ) && V_34 < V_10 ) {
unsigned int V_64 ;
V_64 = F_33 ( V_51 . V_49 , V_10 - V_34 ) ;
if ( V_62 )
memcpy ( V_9 + V_34 , V_51 . V_60 , V_64 ) ;
else
memcpy ( V_51 . V_60 , V_9 + V_34 , V_64 ) ;
V_34 += V_64 ;
}
F_43 ( & V_51 ) ;
F_55 ( V_52 ) ;
return V_34 ;
}
T_5 F_56 ( struct V_1 * V_6 , unsigned int V_5 ,
void * V_9 , T_5 V_10 )
{
return F_53 ( V_6 , V_5 , V_9 , V_10 , 0 , false ) ;
}
T_5 F_57 ( struct V_1 * V_6 , unsigned int V_5 ,
void * V_9 , T_5 V_10 )
{
return F_53 ( V_6 , V_5 , V_9 , V_10 , 0 , true ) ;
}
T_5 F_58 ( struct V_1 * V_6 , unsigned int V_5 ,
void * V_9 , T_5 V_10 , T_4 V_61 )
{
return F_53 ( V_6 , V_5 , V_9 , V_10 , V_61 , false ) ;
}
T_5 F_59 ( struct V_1 * V_6 , unsigned int V_5 ,
void * V_9 , T_5 V_10 , T_4 V_61 )
{
return F_53 ( V_6 , V_5 , V_9 , V_10 , V_61 , true ) ;
}

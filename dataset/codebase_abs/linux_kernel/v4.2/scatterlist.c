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
int F_9 ( struct V_1 * V_2 , T_1 V_6 )
{
int V_5 ;
T_1 V_7 ;
if ( ! V_6 )
return 0 ;
for ( V_5 = 0 , V_7 = 0 ; V_2 ; V_2 = F_1 ( V_2 ) ) {
V_5 ++ ;
V_7 += V_2 -> V_8 ;
if ( V_7 >= V_6 )
return V_5 ;
}
return - V_9 ;
}
struct V_1 * F_10 ( struct V_1 * V_10 , unsigned int V_5 )
{
#ifndef F_11
struct V_1 * V_11 = & V_10 [ V_5 - 1 ] ;
#else
struct V_1 * V_2 , * V_11 = NULL ;
unsigned int V_12 ;
F_12 (sgl, sg, nents, i)
V_11 = V_2 ;
#endif
#ifdef F_2
F_3 ( V_10 [ 0 ] . V_3 != V_4 ) ;
F_3 ( ! F_4 ( V_11 ) ) ;
#endif
return V_11 ;
}
void F_13 ( struct V_1 * V_10 , unsigned int V_5 )
{
memset ( V_10 , 0 , sizeof( * V_10 ) * V_5 ) ;
#ifdef F_2
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_5 ; V_12 ++ )
V_10 [ V_12 ] . V_3 = V_4 ;
}
#endif
F_14 ( & V_10 [ V_5 - 1 ] ) ;
}
void F_15 ( struct V_1 * V_2 , const void * V_13 , unsigned int V_14 )
{
F_13 ( V_2 , 1 ) ;
F_16 ( V_2 , V_13 , V_14 ) ;
}
static struct V_1 * F_17 ( unsigned int V_5 , T_2 V_15 )
{
if ( V_5 == V_16 ) {
void * V_17 = ( void * ) F_18 ( V_15 ) ;
F_19 ( V_17 , V_18 , 1 , V_15 ) ;
return V_17 ;
} else
return F_20 ( V_5 * sizeof( struct V_1 ) , V_15 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_5 )
{
if ( V_5 == V_16 ) {
F_22 ( V_2 ) ;
F_23 ( ( unsigned long ) V_2 ) ;
} else
F_24 ( V_2 ) ;
}
void F_25 ( struct V_19 * V_20 , unsigned int V_21 ,
bool V_22 , T_3 * V_23 )
{
struct V_1 * V_10 , * V_24 ;
if ( F_5 ( ! V_20 -> V_10 ) )
return;
V_10 = V_20 -> V_10 ;
while ( V_20 -> V_25 ) {
unsigned int V_26 = V_20 -> V_25 ;
unsigned int V_27 ;
if ( V_26 > V_21 ) {
V_24 = F_7 ( & V_10 [ V_21 - 1 ] ) ;
V_26 = V_21 ;
V_27 = V_26 - 1 ;
} else {
V_27 = V_26 ;
V_24 = NULL ;
}
V_20 -> V_25 -= V_27 ;
if ( V_22 )
V_22 = false ;
else
V_23 ( V_10 , V_26 ) ;
V_10 = V_24 ;
}
V_20 -> V_10 = NULL ;
}
void F_26 ( struct V_19 * V_20 )
{
F_25 ( V_20 , V_16 , false , F_21 ) ;
}
int F_27 ( struct V_19 * V_20 , unsigned int V_5 ,
unsigned int V_21 , struct V_1 * V_28 ,
T_2 V_15 , T_4 * V_29 )
{
struct V_1 * V_2 , * V_30 ;
unsigned int V_31 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
if ( V_5 == 0 )
return - V_9 ;
#ifndef F_11
if ( F_28 ( V_5 > V_21 ) )
return - V_9 ;
#endif
V_31 = V_5 ;
V_30 = NULL ;
do {
unsigned int V_27 , V_26 = V_31 ;
if ( V_26 > V_21 ) {
V_26 = V_21 ;
V_27 = V_26 - 1 ;
} else
V_27 = V_26 ;
V_31 -= V_27 ;
if ( V_28 ) {
V_2 = V_28 ;
V_28 = NULL ;
} else {
V_2 = V_29 ( V_26 , V_15 ) ;
}
if ( F_5 ( ! V_2 ) ) {
if ( V_30 )
V_20 -> V_5 = ++ V_20 -> V_25 ;
return - V_32 ;
}
F_13 ( V_2 , V_26 ) ;
V_20 -> V_5 = V_20 -> V_25 += V_27 ;
if ( V_30 )
F_29 ( V_30 , V_21 , V_2 ) ;
else
V_20 -> V_10 = V_2 ;
if ( ! V_31 )
F_14 ( & V_2 [ V_27 - 1 ] ) ;
V_30 = V_2 ;
} while ( V_31 );
return 0 ;
}
int F_30 ( struct V_19 * V_20 , unsigned int V_5 , T_2 V_15 )
{
int V_11 ;
V_11 = F_27 ( V_20 , V_5 , V_16 ,
NULL , V_15 , F_17 ) ;
if ( F_5 ( V_11 ) )
F_25 ( V_20 , V_16 , false , F_21 ) ;
return V_11 ;
}
int F_31 ( struct V_19 * V_33 ,
struct V_34 * * V_35 , unsigned int V_36 ,
unsigned long V_37 , unsigned long V_38 ,
T_2 V_15 )
{
unsigned int V_39 ;
unsigned int V_12 ;
unsigned int V_40 ;
int V_11 ;
struct V_1 * V_41 ;
V_39 = 1 ;
for ( V_12 = 1 ; V_12 < V_36 ; ++ V_12 )
if ( F_32 ( V_35 [ V_12 ] ) != F_32 ( V_35 [ V_12 - 1 ] ) + 1 )
++ V_39 ;
V_11 = F_30 ( V_33 , V_39 , V_15 ) ;
if ( F_5 ( V_11 ) )
return V_11 ;
V_40 = 0 ;
F_12 (sgt->sgl, s, sgt->orig_nents, i) {
unsigned long V_42 ;
unsigned int V_43 ;
for ( V_43 = V_40 + 1 ; V_43 < V_36 ; ++ V_43 )
if ( F_32 ( V_35 [ V_43 ] ) !=
F_32 ( V_35 [ V_43 - 1 ] ) + 1 )
break;
V_42 = ( ( V_43 - V_40 ) << V_44 ) - V_37 ;
F_33 ( V_41 , V_35 [ V_40 ] , F_34 ( V_38 , V_42 ) , V_37 ) ;
V_38 -= V_42 ;
V_37 = 0 ;
V_40 = V_43 ;
}
return 0 ;
}
void F_35 ( struct V_45 * V_46 ,
struct V_1 * V_47 , unsigned int V_5 ,
unsigned long V_48 )
{
V_46 -> V_49 = 0 ;
V_46 -> V_50 = V_5 ;
V_46 -> V_2 = V_47 ;
V_46 -> V_51 = V_48 ;
}
static int F_36 ( struct V_1 * V_2 )
{
return F_37 ( V_2 -> V_37 + V_2 -> V_8 ) >> V_44 ;
}
bool F_38 ( struct V_45 * V_46 )
{
if ( ! V_46 -> V_50 || ! V_46 -> V_2 )
return false ;
V_46 -> V_51 += V_46 -> V_49 ;
V_46 -> V_49 = 1 ;
while ( V_46 -> V_51 >= F_36 ( V_46 -> V_2 ) ) {
V_46 -> V_51 -= F_36 ( V_46 -> V_2 ) ;
V_46 -> V_2 = F_1 ( V_46 -> V_2 ) ;
if ( ! -- V_46 -> V_50 || ! V_46 -> V_2 )
return false ;
}
return true ;
}
void F_39 ( struct V_52 * V_53 , struct V_1 * V_10 ,
unsigned int V_5 , unsigned int V_54 )
{
memset ( V_53 , 0 , sizeof( struct V_52 ) ) ;
F_35 ( & V_53 -> V_46 , V_10 , V_5 , 0 ) ;
F_40 ( ! ( V_54 & ( V_55 | V_56 ) ) ) ;
V_53 -> V_57 = V_54 ;
}
static bool F_41 ( struct V_52 * V_53 )
{
if ( ! V_53 -> V_58 ) {
struct V_1 * V_2 ;
unsigned long V_48 ;
if ( ! F_38 ( & V_53 -> V_46 ) )
return false ;
V_2 = V_53 -> V_46 . V_2 ;
V_48 = V_53 -> V_46 . V_51 ;
V_53 -> V_59 = V_48 ? 0 : V_2 -> V_37 ;
V_53 -> V_58 = V_2 -> V_37 + V_2 -> V_8 -
( V_48 << V_44 ) - V_53 -> V_59 ;
V_53 -> V_58 = F_42 (unsigned long, miter->__remaining,
PAGE_SIZE - miter->__offset) ;
}
return true ;
}
bool F_43 ( struct V_52 * V_53 , T_5 V_37 )
{
F_44 ( V_53 ) ;
while ( V_37 ) {
T_5 V_60 ;
if ( ! F_41 ( V_53 ) )
return false ;
V_60 = F_42 ( T_5 , V_37 , V_53 -> V_58 ) ;
V_53 -> V_59 += V_60 ;
V_53 -> V_58 -= V_60 ;
V_37 -= V_60 ;
}
return true ;
}
bool F_45 ( struct V_52 * V_53 )
{
F_44 ( V_53 ) ;
if ( ! F_41 ( V_53 ) )
return false ;
V_53 -> V_34 = F_46 ( & V_53 -> V_46 ) ;
V_53 -> V_60 = V_53 -> V_8 = V_53 -> V_58 ;
if ( V_53 -> V_57 & V_61 )
V_53 -> V_62 = F_47 ( V_53 -> V_34 ) + V_53 -> V_59 ;
else
V_53 -> V_62 = F_48 ( V_53 -> V_34 ) + V_53 -> V_59 ;
return true ;
}
void F_44 ( struct V_52 * V_53 )
{
F_40 ( V_53 -> V_60 > V_53 -> V_8 ) ;
if ( V_53 -> V_62 ) {
V_53 -> V_59 += V_53 -> V_60 ;
V_53 -> V_58 -= V_53 -> V_60 ;
if ( ( V_53 -> V_57 & V_55 ) &&
! F_49 ( V_53 -> V_34 ) )
F_50 ( V_53 -> V_34 ) ;
if ( V_53 -> V_57 & V_61 ) {
F_28 ( F_51 () ) ;
F_52 ( V_53 -> V_62 ) ;
} else
F_53 ( V_53 -> V_34 ) ;
V_53 -> V_34 = NULL ;
V_53 -> V_62 = NULL ;
V_53 -> V_8 = 0 ;
V_53 -> V_60 = 0 ;
}
}
T_6 F_54 ( struct V_1 * V_10 , unsigned int V_5 , void * V_13 ,
T_6 V_14 , T_5 V_63 , bool V_64 )
{
unsigned int V_37 = 0 ;
struct V_52 V_53 ;
unsigned long V_54 ;
unsigned int V_65 = V_61 ;
if ( V_64 )
V_65 |= V_56 ;
else
V_65 |= V_55 ;
F_39 ( & V_53 , V_10 , V_5 , V_65 ) ;
if ( ! F_43 ( & V_53 , V_63 ) )
return false ;
F_55 ( V_54 ) ;
while ( F_45 ( & V_53 ) && V_37 < V_14 ) {
unsigned int V_6 ;
V_6 = F_34 ( V_53 . V_8 , V_14 - V_37 ) ;
if ( V_64 )
memcpy ( V_13 + V_37 , V_53 . V_62 , V_6 ) ;
else
memcpy ( V_53 . V_62 , V_13 + V_37 , V_6 ) ;
V_37 += V_6 ;
}
F_44 ( & V_53 ) ;
F_56 ( V_54 ) ;
return V_37 ;
}
T_6 F_57 ( struct V_1 * V_10 , unsigned int V_5 ,
const void * V_13 , T_6 V_14 )
{
return F_54 ( V_10 , V_5 , ( void * ) V_13 , V_14 , 0 , false ) ;
}
T_6 F_58 ( struct V_1 * V_10 , unsigned int V_5 ,
void * V_13 , T_6 V_14 )
{
return F_54 ( V_10 , V_5 , V_13 , V_14 , 0 , true ) ;
}
T_6 F_59 ( struct V_1 * V_10 , unsigned int V_5 ,
const void * V_13 , T_6 V_14 , T_5 V_63 )
{
return F_54 ( V_10 , V_5 , ( void * ) V_13 , V_14 , V_63 , false ) ;
}
T_6 F_60 ( struct V_1 * V_10 , unsigned int V_5 ,
void * V_13 , T_6 V_14 , T_5 V_63 )
{
return F_54 ( V_10 , V_5 , V_13 , V_14 , V_63 , true ) ;
}

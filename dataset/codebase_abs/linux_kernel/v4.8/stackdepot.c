static bool F_1 ( void * * V_1 )
{
if ( ! * V_1 )
return false ;
if ( F_2 ( & V_2 ) )
return true ;
if ( V_3 [ V_4 ] == NULL ) {
V_3 [ V_4 ] = * V_1 ;
} else {
V_3 [ V_4 + 1 ] = * V_1 ;
F_3 ( & V_2 , 1 ) ;
}
* V_1 = NULL ;
return true ;
}
static struct V_5 * F_4 ( unsigned long * V_6 , int V_7 ,
T_1 V_8 , void * * V_1 , T_2 V_9 )
{
int V_10 = F_5 ( struct V_5 , V_6 ) +
sizeof( unsigned long ) * V_7 ;
struct V_5 * V_11 ;
V_10 = F_6 ( V_10 , 1 << V_12 ) ;
if ( F_7 ( V_13 + V_10 > V_14 ) ) {
if ( F_7 ( V_4 + 1 >= V_15 ) ) {
F_8 ( 1 , L_1 ) ;
return NULL ;
}
V_4 ++ ;
V_13 = 0 ;
if ( V_4 + 1 < V_15 )
F_3 ( & V_2 , 0 ) ;
}
F_1 ( V_1 ) ;
if ( V_3 [ V_4 ] == NULL )
return NULL ;
V_11 = V_3 [ V_4 ] + V_13 ;
V_11 -> V_8 = V_8 ;
V_11 -> V_7 = V_7 ;
V_11 -> V_16 . V_17 = V_4 ;
V_11 -> V_16 . V_18 = V_13 >> V_12 ;
V_11 -> V_16 . V_19 = 1 ;
memcpy ( V_11 -> V_6 , V_6 , V_7 * sizeof( unsigned long ) ) ;
V_13 += V_10 ;
return V_11 ;
}
static inline T_1 F_9 ( unsigned long * V_6 , unsigned int V_7 )
{
return F_10 ( ( T_1 * ) V_6 ,
V_7 * sizeof( unsigned long ) / sizeof( T_1 ) ,
V_20 ) ;
}
static inline struct V_5 * F_11 ( struct V_5 * V_21 ,
unsigned long * V_6 , int V_7 ,
T_1 V_8 )
{
struct V_5 * V_22 ;
for ( V_22 = V_21 ; V_22 ; V_22 = V_22 -> V_23 ) {
if ( V_22 -> V_8 == V_8 &&
V_22 -> V_7 == V_7 &&
! memcmp ( V_6 , V_22 -> V_6 ,
V_7 * sizeof( unsigned long ) ) ) {
return V_22 ;
}
}
return NULL ;
}
void F_12 ( T_3 V_16 , struct V_24 * V_25 )
{
union V_26 V_27 = { . V_16 = V_16 } ;
void * V_28 = V_3 [ V_27 . V_17 ] ;
T_4 V_18 = V_27 . V_18 << V_12 ;
struct V_5 * V_11 = V_28 + V_18 ;
V_25 -> V_29 = V_25 -> V_30 = V_11 -> V_7 ;
V_25 -> V_6 = V_11 -> V_6 ;
V_25 -> V_31 = 0 ;
}
T_3 F_13 ( struct V_24 * V_25 ,
T_2 V_9 )
{
T_1 V_8 ;
T_3 V_32 = 0 ;
struct V_5 * V_22 = NULL , * * V_21 ;
unsigned long V_33 ;
struct V_34 * V_34 = NULL ;
void * V_1 = NULL ;
if ( F_7 ( V_25 -> V_29 == 0 ) )
goto V_35;
V_8 = F_9 ( V_25 -> V_6 , V_25 -> V_29 ) ;
V_21 = & V_36 [ V_8 & V_37 ] ;
V_22 = F_11 ( F_2 ( V_21 ) , V_25 -> V_6 ,
V_25 -> V_29 , V_8 ) ;
if ( V_22 )
goto exit;
if ( F_7 ( ! F_2 ( & V_2 ) ) ) {
V_9 &= ~ V_38 ;
V_9 &= ( V_39 | V_40 ) ;
V_9 |= V_41 ;
V_34 = F_14 ( V_9 , V_42 ) ;
if ( V_34 )
V_1 = F_15 ( V_34 ) ;
}
F_16 ( & V_43 , V_33 ) ;
V_22 = F_11 ( * V_21 , V_25 -> V_6 , V_25 -> V_29 , V_8 ) ;
if ( ! V_22 ) {
struct V_5 * V_44 =
F_4 ( V_25 -> V_6 , V_25 -> V_29 ,
V_8 , & V_1 , V_9 ) ;
if ( V_44 ) {
V_44 -> V_23 = * V_21 ;
F_3 ( V_21 , V_44 ) ;
V_22 = V_44 ;
}
} else if ( V_1 ) {
F_17 ( ! F_1 ( & V_1 ) ) ;
}
F_18 ( & V_43 , V_33 ) ;
exit:
if ( V_1 ) {
F_19 ( ( unsigned long ) V_1 , V_42 ) ;
}
if ( V_22 )
V_32 = V_22 -> V_16 . V_16 ;
V_35:
return V_32 ;
}

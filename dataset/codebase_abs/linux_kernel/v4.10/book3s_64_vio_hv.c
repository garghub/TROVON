struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
struct V_5 * V_5 = V_3 -> V_5 ;
struct V_1 * V_6 ;
F_2 (stt, &kvm->arch.spapr_tce_tables, list)
if ( V_6 -> V_4 == V_4 )
return V_6 ;
return NULL ;
}
long F_3 ( struct V_1 * V_6 ,
unsigned long V_7 , unsigned long V_8 )
{
unsigned long V_9 = ( 1ULL << V_6 -> V_10 ) - 1 ;
unsigned long V_11 = V_7 >> V_6 -> V_10 ;
if ( ( V_7 & V_9 ) || ( V_11 < V_6 -> V_12 ) ||
( V_11 - V_6 -> V_12 + V_8 > V_6 -> V_13 ) ||
( V_11 + V_8 < V_11 ) )
return V_14 ;
return V_15 ;
}
long F_4 ( struct V_1 * V_6 , unsigned long V_16 )
{
unsigned long V_17 = ~ ( ( 1ULL << V_6 -> V_10 ) - 1 ) ;
unsigned long V_9 = ~ ( V_17 | V_18 | V_19 ) ;
if ( V_16 & V_9 )
return V_14 ;
return V_15 ;
}
static T_1 * F_5 ( struct V_20 * V_20 )
{
#if F_6 ( V_21 ) || F_6 ( V_22 )
#error TODO: fix to avoid page_address() here
#endif
return ( T_1 * ) F_7 ( V_20 ) ;
}
void F_8 ( struct V_1 * V_6 ,
unsigned long V_11 , unsigned long V_16 )
{
struct V_20 * V_20 ;
T_1 * V_23 ;
V_11 -= V_6 -> V_12 ;
V_20 = V_6 -> V_24 [ V_11 / V_25 ] ;
V_23 = F_5 ( V_20 ) ;
V_23 [ V_11 % V_25 ] = V_16 ;
}
long F_9 ( struct V_5 * V_5 , unsigned long V_26 ,
unsigned long * V_27 , unsigned long * * V_28 )
{
unsigned long V_29 = V_26 >> V_30 ;
struct V_31 * V_32 ;
V_32 = F_10 ( F_11 ( V_5 ) , V_29 ) ;
if ( ! V_32 )
return - V_33 ;
* V_27 = F_12 ( V_32 , V_29 ) |
( V_26 & ~ ( V_34 | V_19 | V_18 ) ) ;
#ifdef F_13
if ( V_28 )
* V_28 = & V_32 -> V_35 . V_36 [ V_29 - V_32 -> V_37 ] ;
#endif
return 0 ;
}
long F_14 ( struct V_2 * V_3 , unsigned long V_4 ,
unsigned long V_7 , unsigned long V_16 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_4 ) ;
long V_38 ;
if ( ! V_6 )
return V_39 ;
V_38 = F_3 ( V_6 , V_7 , 1 ) ;
if ( V_38 != V_15 )
return V_38 ;
V_38 = F_4 ( V_6 , V_16 ) ;
if ( V_38 != V_15 )
return V_38 ;
F_8 ( V_6 , V_7 >> V_6 -> V_10 , V_16 ) ;
return V_15 ;
}
static long F_15 ( struct V_2 * V_3 ,
unsigned long V_27 , unsigned long * V_40 )
{
T_2 * V_41 , V_42 ;
unsigned V_43 = 0 ;
V_41 = F_16 ( V_3 -> V_35 . V_44 , V_27 , NULL , & V_43 ) ;
if ( ! V_41 || ! F_17 ( * V_41 ) )
return - V_45 ;
V_42 = * V_41 ;
if ( ! V_43 )
V_43 = V_30 ;
if ( V_43 > V_30 )
return - V_46 ;
if ( ! F_18 ( V_42 ) )
return - V_46 ;
* V_40 = ( F_19 ( V_42 ) << V_30 ) | ( V_27 & ( ( 1ULL << V_43 ) - 1 ) ) |
( V_27 & ~ V_34 ) ;
return 0 ;
}
long F_20 ( struct V_2 * V_3 ,
unsigned long V_4 , unsigned long V_7 ,
unsigned long V_47 , unsigned long V_8 )
{
struct V_1 * V_6 ;
long V_48 , V_38 = V_15 ;
unsigned long V_49 , V_50 , V_27 = 0 ;
unsigned long * V_36 = NULL ;
V_6 = F_1 ( V_3 , V_4 ) ;
if ( ! V_6 )
return V_39 ;
V_50 = V_7 >> V_6 -> V_10 ;
if ( V_8 > 512 )
return V_14 ;
if ( V_47 & ( V_51 - 1 ) )
return V_14 ;
V_38 = F_3 ( V_6 , V_7 , V_8 ) ;
if ( V_38 != V_15 )
return V_38 ;
if ( F_9 ( V_3 -> V_5 , V_47 , & V_27 , & V_36 ) )
return V_39 ;
V_36 = ( void * ) F_21 ( V_36 ) ;
F_22 ( V_36 ) ;
if ( F_15 ( V_3 , V_27 , & V_49 ) ) {
V_38 = V_39 ;
goto V_52;
}
for ( V_48 = 0 ; V_48 < V_8 ; ++ V_48 ) {
unsigned long V_16 = F_23 ( ( ( T_1 * ) V_49 ) [ V_48 ] ) ;
V_38 = F_4 ( V_6 , V_16 ) ;
if ( V_38 != V_15 )
goto V_52;
F_8 ( V_6 , V_50 + V_48 , V_16 ) ;
}
V_52:
F_24 ( V_36 ) ;
return V_38 ;
}
long F_25 ( struct V_2 * V_3 ,
unsigned long V_4 , unsigned long V_7 ,
unsigned long V_53 , unsigned long V_8 )
{
struct V_1 * V_6 ;
long V_48 , V_38 ;
V_6 = F_1 ( V_3 , V_4 ) ;
if ( ! V_6 )
return V_39 ;
V_38 = F_3 ( V_6 , V_7 , V_8 ) ;
if ( V_38 != V_15 )
return V_38 ;
if ( V_53 & ( V_18 | V_19 ) )
return V_14 ;
for ( V_48 = 0 ; V_48 < V_8 ; ++ V_48 , V_7 += ( 1ULL << V_6 -> V_10 ) )
F_8 ( V_6 , V_7 >> V_6 -> V_10 , V_53 ) ;
return V_15 ;
}
long F_26 ( struct V_2 * V_3 , unsigned long V_4 ,
unsigned long V_7 )
{
struct V_1 * V_6 = F_1 ( V_3 , V_4 ) ;
long V_38 ;
unsigned long V_11 ;
struct V_20 * V_20 ;
T_1 * V_23 ;
if ( ! V_6 )
return V_39 ;
V_38 = F_3 ( V_6 , V_7 , 1 ) ;
if ( V_38 != V_15 )
return V_38 ;
V_11 = ( V_7 >> V_6 -> V_10 ) - V_6 -> V_12 ;
V_20 = V_6 -> V_24 [ V_11 / V_25 ] ;
V_23 = ( T_1 * ) F_7 ( V_20 ) ;
V_3 -> V_35 . V_54 [ 4 ] = V_23 [ V_11 % V_25 ] ;
return V_15 ;
}

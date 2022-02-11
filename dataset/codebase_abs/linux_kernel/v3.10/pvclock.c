void F_1 ( T_1 V_1 )
{
V_2 = V_1 ;
}
unsigned long F_2 ( struct V_3 * V_4 )
{
T_2 V_5 = 1000000ULL << 32 ;
F_3 ( V_5 , V_4 -> V_6 ) ;
if ( V_4 -> V_7 < 0 )
V_5 <<= - V_4 -> V_7 ;
else
V_5 >>= V_4 -> V_7 ;
return V_5 ;
}
void F_4 ( void )
{
F_5 ( & V_8 , 0 ) ;
}
T_1 F_6 ( struct V_3 * V_4 )
{
unsigned V_9 ;
T_3 V_10 ;
T_1 V_1 ;
do {
V_9 = F_7 ( V_4 , & V_10 , & V_1 ) ;
} while ( ( V_4 -> V_9 & 1 ) || V_9 != V_4 -> V_9 );
return V_1 & V_2 ;
}
T_3 F_8 ( struct V_3 * V_4 )
{
unsigned V_9 ;
T_3 V_10 ;
T_2 V_11 ;
T_1 V_1 ;
do {
V_9 = F_7 ( V_4 , & V_10 , & V_1 ) ;
} while ( ( V_4 -> V_9 & 1 ) || V_9 != V_4 -> V_9 );
if ( ( V_2 & V_12 ) &&
( V_1 & V_12 ) )
return V_10 ;
V_11 = F_9 ( & V_8 ) ;
do {
if ( V_10 < V_11 )
return V_11 ;
V_11 = F_10 ( & V_8 , V_11 , V_10 ) ;
} while ( F_11 ( V_11 != V_10 ) );
return V_10 ;
}
void F_12 ( struct V_13 * V_14 ,
struct V_3 * V_15 ,
struct V_16 * V_17 )
{
T_4 V_9 ;
T_2 V_18 ;
struct V_16 V_19 ;
do {
V_9 = V_14 -> V_9 ;
F_13 () ;
V_19 . V_20 = V_14 -> V_21 ;
V_19 . V_22 = V_14 -> V_23 ;
F_13 () ;
} while ( ( V_14 -> V_9 & 1 ) || ( V_9 != V_14 -> V_9 ) );
V_18 = F_8 ( V_15 ) ;
V_18 += V_19 . V_20 * ( T_2 ) V_24 + V_19 . V_22 ;
V_19 . V_22 = F_3 ( V_18 , V_24 ) ;
V_19 . V_20 = V_18 ;
F_14 ( V_17 , V_19 . V_20 , V_19 . V_22 ) ;
}
static struct V_25 *
F_15 ( int V_26 )
{
if ( ! V_27 ) {
F_16 () ;
return NULL ;
}
return & V_27 [ V_26 ] ;
}
struct V_3 * F_17 ( int V_26 )
{
return & F_15 ( V_26 ) -> V_28 ;
}
static int F_18 ( struct V_29 * V_30 , unsigned long V_31 ,
void * V_32 )
{
struct V_33 * V_34 = V_32 ;
struct V_25 * V_28 ;
V_28 = F_15 ( V_34 -> V_35 ) ;
if ( F_11 ( V_28 == NULL ) )
return V_36 ;
V_28 -> V_37 ++ ;
return V_36 ;
}
int T_5 F_19 ( struct V_25 * V_38 ,
int V_39 )
{
int V_40 ;
F_20 ( V_39 != V_41 * V_42 ) ;
V_27 = V_38 ;
for ( V_40 = 0 ; V_40 <= ( V_43 - V_44 ) ; V_40 ++ ) {
F_21 ( V_44 + V_40 ,
F_22 ( V_38 ) + ( V_40 * V_42 ) ,
V_45 ) ;
}
F_23 ( & V_46 ) ;
return 0 ;
}

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
int T_5 F_15 ( struct V_25 * V_26 ,
int V_27 )
{
int V_28 ;
F_16 ( V_27 != V_29 * V_30 ) ;
for ( V_28 = 0 ; V_28 <= ( V_31 - V_32 ) ; V_28 ++ ) {
F_17 ( V_32 + V_28 ,
F_18 ( V_26 ) + ( V_28 * V_30 ) ,
V_33 ) ;
}
return 0 ;
}

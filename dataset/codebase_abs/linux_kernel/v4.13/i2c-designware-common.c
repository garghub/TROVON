T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
if ( V_2 -> V_5 & V_6 )
V_4 = F_2 ( V_2 -> V_7 + V_3 ) |
( F_2 ( V_2 -> V_7 + V_3 + 2 ) << 16 ) ;
else
V_4 = F_3 ( V_2 -> V_7 + V_3 ) ;
if ( V_2 -> V_5 & V_8 )
return F_4 ( V_4 ) ;
else
return V_4 ;
}
void F_5 ( struct V_1 * V_2 , T_1 V_9 , int V_3 )
{
if ( V_2 -> V_5 & V_8 )
V_9 = F_4 ( V_9 ) ;
if ( V_2 -> V_5 & V_6 ) {
F_6 ( ( V_10 ) V_9 , V_2 -> V_7 + V_3 ) ;
F_6 ( ( V_10 ) ( V_9 >> 16 ) , V_2 -> V_7 + V_3 + 2 ) ;
} else {
F_7 ( V_9 , V_2 -> V_7 + V_3 ) ;
}
}
T_1 F_8 ( T_1 V_11 , T_1 V_12 , T_1 V_13 , int V_14 , int V_3 )
{
if ( V_14 )
return ( V_11 * V_12 + 500000 ) / 1000000 - 8 + V_3 ;
else
return ( V_11 * ( V_12 + V_13 ) + 500000 ) / 1000000
- 3 + V_3 ;
}
T_1 F_9 ( T_1 V_11 , T_1 V_15 , T_1 V_13 , int V_3 )
{
return ( ( V_11 * ( V_15 + V_13 ) + 500000 ) / 1000000 ) - 1 + V_3 ;
}
void F_10 ( struct V_1 * V_2 , bool V_16 )
{
F_5 ( V_2 , V_16 , V_17 ) ;
}
void F_11 ( struct V_1 * V_2 , bool V_16 )
{
int V_18 = 100 ;
do {
F_10 ( V_2 , V_16 ) ;
if ( ( F_1 ( V_2 , V_19 ) & 1 ) == V_16 )
return;
F_12 ( 25 , 250 ) ;
} while ( V_18 -- );
F_13 ( V_2 -> V_2 , L_1 ,
V_16 ? L_2 : L_3 ) ;
}
unsigned long F_14 ( struct V_1 * V_2 )
{
if ( F_15 ( ! V_2 -> V_20 ) )
return 0 ;
return V_2 -> V_20 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
int V_21 ;
if ( ! V_2 -> V_22 )
return 0 ;
V_21 = V_2 -> V_22 ( V_2 ) ;
if ( ! V_21 )
return 0 ;
F_17 ( V_2 -> V_2 , L_4 ) ;
return V_21 ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 )
V_2 -> V_23 ( V_2 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
int V_18 = V_24 ;
while ( F_1 ( V_2 , V_25 ) & V_26 ) {
if ( V_18 <= 0 ) {
F_13 ( V_2 -> V_2 , L_5 ) ;
return - V_27 ;
}
V_18 -- ;
F_12 ( 1000 , 1100 ) ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 )
{
unsigned long V_28 = V_2 -> V_28 ;
int V_29 ;
if ( V_28 & V_30 ) {
F_21 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_22 ( V_2 -> V_2 ,
L_6 , V_31 , V_32 [ V_29 ] ) ;
return - V_33 ;
}
F_21 (i, &abort_source, ARRAY_SIZE(abort_sources))
F_17 ( V_2 -> V_2 , L_6 , V_31 , V_32 [ V_29 ] ) ;
if ( V_28 & V_34 )
return - V_35 ;
else if ( V_28 & V_36 )
return - V_37 ;
else
return - V_38 ;
}
T_1 F_23 ( struct V_39 * V_40 )
{
struct V_1 * V_2 = F_24 ( V_40 ) ;
return V_2 -> V_41 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_11 ( V_2 , false ) ;
F_5 ( V_2 , 0 , V_42 ) ;
F_1 ( V_2 , V_43 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_5 ( V_2 , 0 , V_42 ) ;
}
T_1 F_27 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_44 ) ;
}

void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
unsigned long V_6 , V_7 , V_8 ;
T_1 * * V_9 ;
for ( V_6 = 0 ; V_6 < 4 ; ++ V_6 ) {
if ( V_4 -> V_10 [ V_6 ] ) {
F_2 ( ( unsigned long ) V_4 -> V_10 [ V_6 ] ) ;
V_4 -> V_10 [ V_6 ] = NULL ;
}
}
V_8 = 0 ;
for ( V_6 = 0 ; V_6 < ( V_11 >> 43 ) ; ++ V_6 ) {
V_9 = V_4 -> V_12 [ V_6 ] ;
if ( ! V_9 )
continue;
V_4 -> V_12 [ V_6 ] = NULL ;
for ( V_7 = 0 ; V_7 < V_13 && V_8 < V_4 -> V_14 ;
++ V_7 , V_8 += V_15 )
if ( V_9 [ V_7 ] )
F_2 ( ( unsigned long ) V_9 [ V_7 ] ) ;
F_2 ( ( unsigned long ) V_9 ) ;
}
V_4 -> V_14 = 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned long V_8 ,
int V_16 )
{
T_2 * V_17 ;
T_3 * V_18 ;
T_4 * V_19 ;
T_5 * V_20 ;
T_6 * V_21 ;
V_17 = F_5 ( V_2 , V_8 ) ;
if ( F_6 ( * V_17 ) )
return;
V_18 = F_7 ( V_17 , V_8 ) ;
if ( F_8 ( * V_18 ) )
return;
V_19 = F_9 ( V_18 , V_8 ) ;
if ( F_10 ( * V_19 ) )
return;
V_20 = F_11 ( V_2 , V_19 , V_8 , & V_21 ) ;
F_12 () ;
for (; V_16 > 0 ; -- V_16 ) {
F_13 ( V_2 , V_8 , V_20 , 0 , 0 , 0 ) ;
V_8 += V_15 ;
++ V_20 ;
}
F_14 () ;
F_15 ( V_20 - 1 , V_21 ) ;
}
static void F_16 ( unsigned long V_8 , unsigned long V_22 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
T_1 * * V_24 , * V_25 ;
unsigned long V_6 ;
T_7 V_26 ;
unsigned long V_27 , V_28 ;
F_17 ( & V_2 -> V_29 ) ;
V_28 = V_8 + V_22 ;
if ( V_28 > V_4 -> V_14 )
V_28 = V_4 -> V_14 ;
for (; V_8 < V_28 ; V_8 = V_27 ) {
V_27 = F_18 ( V_8 , V_28 ) ;
if ( V_8 < 0x100000000UL ) {
V_24 = V_4 -> V_10 ;
} else {
V_24 = V_4 -> V_12 [ V_8 >> V_30 ] ;
if ( ! V_24 )
continue;
}
V_25 = V_24 [ ( V_8 >> V_31 ) & ( V_13 - 1 ) ] ;
if ( ! V_25 )
continue;
V_25 += ( V_8 >> V_32 ) & ( V_33 - 1 ) ;
V_6 = ( V_8 >> V_32 ) & ( V_34 - 1 ) ;
V_26 = V_34 - V_6 ;
if ( V_8 + ( V_26 << V_32 ) > V_27 )
V_26 = ( V_27 - V_8 ) >> V_32 ;
memset ( V_25 , 0 , V_26 * sizeof( T_1 ) ) ;
F_4 ( V_2 , V_8 , V_26 ) ;
}
F_19 ( & V_2 -> V_29 ) ;
}
static int F_20 ( T_4 * V_19 , unsigned long V_8 ,
unsigned long V_35 , struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_39 ;
F_21 ( V_39 , V_19 , V_8 ) ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 , unsigned long V_8 ,
unsigned long V_22 )
{
struct V_38 * V_39 ;
struct V_36 V_40 = {
. V_2 = V_2 ,
. V_41 = F_20 ,
} ;
V_39 = F_23 ( V_2 , V_8 ) ;
if ( V_39 && ( ( V_8 + V_22 ) <= V_39 -> V_42 ) )
return;
while ( V_39 ) {
if ( V_39 -> V_42 >= ( V_8 + V_22 ) )
break;
V_39 -> V_43 |= V_44 ;
F_24 ( V_39 , & V_40 ) ;
V_39 = V_39 -> V_45 ;
}
}
static void F_22 ( struct V_1 * V_2 , unsigned long V_8 ,
unsigned long V_22 )
{
return;
}
long F_25 ( unsigned long V_8 , unsigned long V_22 , T_1 T_8 * V_46 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_3 * V_4 = & V_2 -> V_5 . V_4 ;
T_1 * * V_24 , * V_25 ;
unsigned long V_6 ;
T_7 V_26 ;
unsigned long V_27 , V_28 ;
int V_47 ;
if ( ( V_8 & ~ V_48 ) || ( V_22 & ~ V_48 ) ||
V_8 >= V_2 -> V_49 || V_22 >= V_2 -> V_49 ||
V_8 + V_22 > V_2 -> V_49 )
return - V_50 ;
if ( F_26 ( V_2 , V_8 , V_22 ) )
return - V_50 ;
if ( ! V_46 ) {
F_16 ( V_8 , V_22 ) ;
return 0 ;
}
if ( ! F_27 ( V_51 , V_46 , ( V_22 >> V_32 ) * sizeof( T_1 ) ) )
return - V_52 ;
F_17 ( & V_2 -> V_29 ) ;
F_22 ( V_2 , V_8 , V_22 ) ;
for ( V_28 = V_8 + V_22 ; V_8 < V_28 ; V_8 = V_27 ) {
V_27 = F_18 ( V_8 , V_28 ) ;
V_47 = - V_53 ;
if ( V_8 < 0x100000000UL ) {
V_24 = V_4 -> V_10 ;
} else {
V_24 = V_4 -> V_12 [ V_8 >> V_30 ] ;
if ( ! V_24 ) {
V_24 = ( T_1 * * ) F_28 ( V_54 ) ;
if ( ! V_24 )
goto V_55;
V_4 -> V_12 [ V_8 >> V_30 ] = V_24 ;
}
}
V_24 += ( V_8 >> V_31 ) & ( V_13 - 1 ) ;
V_25 = * V_24 ;
if ( ! V_25 ) {
V_25 = ( T_1 * ) F_28 ( V_54 ) ;
if ( ! V_25 )
goto V_55;
* V_24 = V_25 ;
}
V_25 += ( V_8 >> V_32 ) & ( V_33 - 1 ) ;
F_29 () ;
F_30 ( V_2 , V_8 ) ;
F_31 () ;
V_6 = ( V_8 >> V_32 ) & ( V_34 - 1 ) ;
V_26 = V_34 - V_6 ;
if ( V_8 + ( V_26 << V_32 ) > V_27 )
V_26 = ( V_27 - V_8 ) >> V_32 ;
F_19 ( & V_2 -> V_29 ) ;
if ( F_32 ( V_25 , V_46 , V_26 * sizeof( T_1 ) ) )
return - V_52 ;
V_46 += V_26 ;
F_17 ( & V_2 -> V_29 ) ;
F_4 ( V_2 , V_8 , V_26 ) ;
}
if ( V_28 > V_4 -> V_14 )
V_4 -> V_14 = V_28 ;
V_47 = 0 ;
V_55:
F_19 ( & V_2 -> V_29 ) ;
return V_47 ;
}

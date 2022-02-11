void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 = V_2 -> V_9 ;
if ( V_4 -> V_10 >= V_11 ) {
const int V_12 = V_8 -> V_13 . V_14 . V_15 / 2 ;
V_2 -> V_16 . V_17 = ( V_8 -> V_13 . V_14 . V_15 - V_12 ) >> 2 ;
V_2 -> V_16 . V_18 = ( V_12 / 8 ) - 1 ;
V_2 -> V_16 . V_19 = 0 ;
V_2 -> V_16 . V_20 = V_2 -> V_16 . V_18 - V_2 -> V_16 . V_19 ;
V_2 -> V_16 . V_21 = ( V_8 -> V_13 . V_14 . V_15 - V_12 ) >> 2 ;
} else {
V_2 -> V_16 . V_21 = ( V_8 -> V_13 . V_14 . V_15 >> 2 ) - 2 ;
}
V_2 -> V_16 . V_22 = 0 ;
V_2 -> V_16 . V_23 = V_2 -> V_16 . V_22 ;
V_2 -> V_16 . free = V_2 -> V_16 . V_21 - V_2 -> V_16 . V_23 ;
}
void
F_2 ( struct V_1 * V_2 , const void * V_24 , unsigned V_25 )
{
bool V_26 ;
T_1 * V_14 = F_3 ( & V_2 -> V_9 -> V_27 , & V_26 ) ;
V_14 = & V_14 [ V_2 -> V_16 . V_23 ] ;
if ( V_26 )
F_4 ( ( void V_28 V_29 * ) V_14 , V_24 , V_25 * 4 ) ;
else
memcpy ( V_14 , V_24 , V_25 * 4 ) ;
V_2 -> V_16 . V_23 += V_25 ;
}
static inline int
F_5 ( struct V_1 * V_2 , T_2 * V_30 , int * V_31 )
{
T_2 V_32 ;
V_32 = F_6 ( V_2 , V_2 -> V_33 ) ;
if ( V_2 -> V_34 )
V_32 |= ( T_2 ) F_6 ( V_2 , V_2 -> V_34 ) << 32 ;
if ( V_32 != * V_30 ) {
* V_30 = V_32 ;
* V_31 = 0 ;
}
if ( ( ++ * V_31 & 0xff ) == 0 ) {
F_7 ( 1 ) ;
if ( * V_31 > 100000 )
return - V_35 ;
}
if ( V_32 < V_2 -> V_36 ||
V_32 > V_2 -> V_36 + ( V_2 -> V_16 . V_21 << 2 ) )
return - V_37 ;
return ( V_32 - V_2 -> V_36 ) >> 2 ;
}
void
F_8 ( struct V_1 * V_2 , struct V_7 * V_13 ,
int V_38 , int V_39 )
{
struct V_7 * V_40 = V_2 -> V_9 ;
struct V_41 * V_42 ;
int V_43 = ( V_2 -> V_16 . V_19 * 2 ) + V_2 -> V_16 . V_17 ;
T_3 V_44 ;
V_42 = F_9 ( V_13 , V_2 -> V_45 ) ;
F_10 ( ! V_42 ) ;
V_44 = V_42 -> V_44 + V_38 ;
F_10 ( V_2 -> V_16 . V_20 < 1 ) ;
F_11 ( V_40 , V_43 ++ , F_12 ( V_44 ) ) ;
F_11 ( V_40 , V_43 ++ , F_13 ( V_44 ) | V_39 << 8 ) ;
V_2 -> V_16 . V_19 = ( V_2 -> V_16 . V_19 + 1 ) & V_2 -> V_16 . V_18 ;
F_14 () ;
F_15 ( V_40 , 0 ) ;
F_16 ( V_2 , 0x8c , V_2 -> V_16 . V_19 ) ;
V_2 -> V_16 . V_20 -- ;
}
static int
F_17 ( struct V_1 * V_2 , int V_46 )
{
T_4 V_47 = 0 , V_30 = 0 ;
while ( V_2 -> V_16 . V_20 < V_46 ) {
T_4 V_48 = F_6 ( V_2 , 0x88 ) ;
if ( V_48 != V_30 ) {
V_30 = V_48 ;
V_47 = 0 ;
}
if ( ( ++ V_47 & 0xff ) == 0 ) {
F_7 ( 1 ) ;
if ( V_47 > 100000 )
return - V_35 ;
}
V_2 -> V_16 . V_20 = V_48 - V_2 -> V_16 . V_19 ;
if ( V_2 -> V_16 . V_20 <= 0 )
V_2 -> V_16 . V_20 += V_2 -> V_16 . V_18 ;
}
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 , int V_49 , int V_46 )
{
T_2 V_30 = 0 ;
int V_50 , V_47 = 0 ;
V_50 = F_17 ( V_2 , V_49 + 1 ) ;
if ( F_19 ( V_50 ) )
return V_50 ;
while ( V_2 -> V_16 . free < V_46 ) {
int V_48 = F_5 ( V_2 , & V_30 , & V_47 ) ;
if ( F_19 ( V_48 < 0 ) ) {
if ( V_48 == - V_37 )
continue;
return V_48 ;
}
if ( V_48 <= V_2 -> V_16 . V_23 ) {
V_2 -> V_16 . free = V_2 -> V_16 . V_21 - V_2 -> V_16 . V_23 ;
if ( V_2 -> V_16 . free >= V_46 )
break;
F_20 ( V_2 ) ;
do {
V_48 = F_5 ( V_2 , & V_30 , & V_47 ) ;
if ( F_19 ( V_48 < 0 ) ) {
if ( V_48 == - V_37 )
continue;
return V_48 ;
}
} while ( V_48 == 0 );
V_2 -> V_16 . V_23 = 0 ;
V_2 -> V_16 . V_22 = 0 ;
}
V_2 -> V_16 . free = V_48 - V_2 -> V_16 . V_23 - 1 ;
}
return 0 ;
}
int
F_21 ( struct V_1 * V_2 , int V_49 , int V_15 )
{
T_2 V_30 = 0 ;
int V_47 = 0 , V_48 ;
if ( V_2 -> V_16 . V_18 )
return F_18 ( V_2 , V_49 , V_15 ) ;
while ( V_2 -> V_16 . free < V_15 ) {
V_48 = F_5 ( V_2 , & V_30 , & V_47 ) ;
if ( F_19 ( V_48 == - V_35 ) )
return - V_35 ;
if ( F_19 ( V_48 == - V_37 ) || V_48 < V_51 )
continue;
if ( V_48 <= V_2 -> V_16 . V_23 ) {
V_2 -> V_16 . free = V_2 -> V_16 . V_21 - V_2 -> V_16 . V_23 ;
if ( V_2 -> V_16 . free >= V_15 )
break;
F_22 ( V_2 , V_2 -> V_36 | 0x20000000 ) ;
do {
V_48 = F_5 ( V_2 , & V_30 , & V_47 ) ;
if ( F_19 ( V_48 == - V_35 ) )
return - V_35 ;
if ( F_19 ( V_48 == - V_37 ) )
continue;
} while ( V_48 <= V_51 );
F_23 ( V_51 ) ;
V_2 -> V_16 . V_23 =
V_2 -> V_16 . V_22 = V_51 ;
}
V_2 -> V_16 . free = V_48 - V_2 -> V_16 . V_23 - 1 ;
}
return 0 ;
}

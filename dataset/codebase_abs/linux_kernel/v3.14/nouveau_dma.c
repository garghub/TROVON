void
F_1 ( struct V_1 * V_2 , const void * V_3 , unsigned V_4 )
{
bool V_5 ;
T_1 * V_6 = F_2 ( & V_2 -> V_7 . V_8 -> V_9 , & V_5 ) ;
V_6 = & V_6 [ V_2 -> V_10 . V_11 ] ;
if ( V_5 )
F_3 ( ( void V_12 V_13 * ) V_6 , V_3 , V_4 * 4 ) ;
else
memcpy ( V_6 , V_3 , V_4 * 4 ) ;
V_2 -> V_10 . V_11 += V_4 ;
}
static inline int
F_4 ( struct V_1 * V_2 , T_2 * V_14 , int * V_15 )
{
T_2 V_16 ;
V_16 = F_5 ( V_2 -> V_17 , V_2 -> V_18 ) ;
if ( V_2 -> V_19 )
V_16 |= ( T_2 ) F_5 ( V_2 -> V_17 , V_2 -> V_19 ) << 32 ;
if ( V_16 != * V_14 ) {
* V_14 = V_16 ;
* V_15 = 0 ;
}
if ( ( ++ * V_15 & 0xff ) == 0 ) {
F_6 ( 1 ) ;
if ( * V_15 > 100000 )
return - V_20 ;
}
if ( V_16 < V_2 -> V_7 . V_21 . V_22 ||
V_16 > V_2 -> V_7 . V_21 . V_22 + ( V_2 -> V_10 . V_23 << 2 ) )
return - V_24 ;
return ( V_16 - V_2 -> V_7 . V_21 . V_22 ) >> 2 ;
}
void
F_7 ( struct V_1 * V_2 , struct V_25 * V_26 ,
int V_27 , int V_28 )
{
struct V_25 * V_29 = V_2 -> V_7 . V_8 ;
struct V_30 * V_21 ;
int V_31 = ( V_2 -> V_10 . V_32 * 2 ) + V_2 -> V_10 . V_33 ;
T_3 V_22 ;
V_21 = F_8 ( V_26 , F_9 ( V_2 -> V_34 ) -> V_35 ) ;
F_10 ( ! V_21 ) ;
V_22 = V_21 -> V_22 + V_27 ;
F_10 ( V_2 -> V_10 . V_36 < 1 ) ;
F_11 ( V_29 , V_31 ++ , F_12 ( V_22 ) ) ;
F_11 ( V_29 , V_31 ++ , F_13 ( V_22 ) | V_28 << 8 ) ;
V_2 -> V_10 . V_32 = ( V_2 -> V_10 . V_32 + 1 ) & V_2 -> V_10 . V_37 ;
F_14 () ;
F_15 ( V_29 , 0 ) ;
F_16 ( V_2 -> V_17 , 0x8c , V_2 -> V_10 . V_32 ) ;
V_2 -> V_10 . V_36 -- ;
}
static int
F_17 ( struct V_1 * V_2 , int V_38 )
{
T_4 V_39 = 0 , V_14 = 0 ;
while ( V_2 -> V_10 . V_36 < V_38 ) {
T_4 V_40 = F_5 ( V_2 -> V_17 , 0x88 ) ;
if ( V_40 != V_14 ) {
V_14 = V_40 ;
V_39 = 0 ;
}
if ( ( ++ V_39 & 0xff ) == 0 ) {
F_18 ( 1 ) ;
if ( V_39 > 100000 )
return - V_20 ;
}
V_2 -> V_10 . V_36 = V_40 - V_2 -> V_10 . V_32 ;
if ( V_2 -> V_10 . V_36 <= 0 )
V_2 -> V_10 . V_36 += V_2 -> V_10 . V_37 ;
}
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 , int V_41 , int V_38 )
{
T_2 V_14 = 0 ;
int V_42 , V_39 = 0 ;
V_42 = F_17 ( V_2 , V_41 + 1 ) ;
if ( F_20 ( V_42 ) )
return V_42 ;
while ( V_2 -> V_10 . free < V_38 ) {
int V_40 = F_4 ( V_2 , & V_14 , & V_39 ) ;
if ( F_20 ( V_40 < 0 ) ) {
if ( V_40 == - V_24 )
continue;
return V_40 ;
}
if ( V_40 <= V_2 -> V_10 . V_11 ) {
V_2 -> V_10 . free = V_2 -> V_10 . V_23 - V_2 -> V_10 . V_11 ;
if ( V_2 -> V_10 . free >= V_38 )
break;
F_21 ( V_2 ) ;
do {
V_40 = F_4 ( V_2 , & V_14 , & V_39 ) ;
if ( F_20 ( V_40 < 0 ) ) {
if ( V_40 == - V_24 )
continue;
return V_40 ;
}
} while ( V_40 == 0 );
V_2 -> V_10 . V_11 = 0 ;
V_2 -> V_10 . V_43 = 0 ;
}
V_2 -> V_10 . free = V_40 - V_2 -> V_10 . V_11 - 1 ;
}
return 0 ;
}
int
F_22 ( struct V_1 * V_2 , int V_41 , int V_44 )
{
T_2 V_14 = 0 ;
int V_39 = 0 , V_40 ;
if ( V_2 -> V_10 . V_37 )
return F_19 ( V_2 , V_41 , V_44 ) ;
while ( V_2 -> V_10 . free < V_44 ) {
V_40 = F_4 ( V_2 , & V_14 , & V_39 ) ;
if ( F_20 ( V_40 == - V_20 ) )
return - V_20 ;
if ( F_20 ( V_40 == - V_24 ) || V_40 < V_45 )
continue;
if ( V_40 <= V_2 -> V_10 . V_11 ) {
V_2 -> V_10 . free = V_2 -> V_10 . V_23 - V_2 -> V_10 . V_11 ;
if ( V_2 -> V_10 . free >= V_44 )
break;
F_23 ( V_2 , V_2 -> V_7 . V_21 . V_22 | 0x20000000 ) ;
do {
V_40 = F_4 ( V_2 , & V_14 , & V_39 ) ;
if ( F_20 ( V_40 == - V_20 ) )
return - V_20 ;
if ( F_20 ( V_40 == - V_24 ) )
continue;
} while ( V_40 <= V_45 );
F_24 ( V_45 ) ;
V_2 -> V_10 . V_11 =
V_2 -> V_10 . V_43 = V_45 ;
}
V_2 -> V_10 . free = V_40 - V_2 -> V_10 . V_11 - 1 ;
}
return 0 ;
}

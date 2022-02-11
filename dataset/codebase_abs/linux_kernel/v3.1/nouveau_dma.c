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
int
F_2 ( struct V_1 * V_2 )
{
struct V_24 * V_5 = V_2 -> V_5 ;
struct V_3 * V_4 = V_5 -> V_6 ;
int V_25 , V_26 ;
if ( V_4 -> V_10 >= V_27 ) {
V_25 = F_3 ( V_2 , 0x9039 , 0x9039 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_4 ( V_2 , 2 ) ;
if ( V_25 )
return V_25 ;
F_5 ( V_2 , 2 , V_28 , 0x0000 , 1 ) ;
F_6 ( V_2 , 0x00009039 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
V_25 = F_3 ( V_2 , V_29 , V_4 -> V_10 < V_11 ?
0x0039 : 0x5039 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_8 ( V_2 , V_30 , 32 , 0xfe0 , 0x1000 ,
& V_2 -> V_31 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_4 ( V_2 , V_32 ) ;
if ( V_25 )
return V_25 ;
for ( V_26 = 0 ; V_26 < V_32 ; V_26 ++ )
F_6 ( V_2 , 0 ) ;
V_25 = F_4 ( V_2 , 6 ) ;
if ( V_25 )
return V_25 ;
F_9 ( V_2 , V_28 , V_33 , 1 ) ;
F_6 ( V_2 , V_29 ) ;
F_9 ( V_2 , V_28 , V_34 , 3 ) ;
F_6 ( V_2 , V_30 ) ;
F_6 ( V_2 , V_2 -> V_35 ) ;
F_6 ( V_2 , V_2 -> V_36 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
void
F_10 ( struct V_1 * V_2 , const void * V_37 , unsigned V_38 )
{
bool V_39 ;
T_1 * V_14 = F_11 ( & V_2 -> V_9 -> V_40 , & V_39 ) ;
V_14 = & V_14 [ V_2 -> V_16 . V_23 ] ;
if ( V_39 )
F_12 ( ( void V_41 V_42 * ) V_14 , V_37 , V_38 * 4 ) ;
else
memcpy ( V_14 , V_37 , V_38 * 4 ) ;
V_2 -> V_16 . V_23 += V_38 ;
}
static inline int
F_13 ( struct V_1 * V_2 , T_2 * V_43 , T_2 * V_44 )
{
T_2 V_45 ;
V_45 = F_14 ( V_2 , V_2 -> V_46 ) ;
if ( V_45 != * V_43 ) {
* V_43 = V_45 ;
* V_44 = 0 ;
}
if ( ( ++ * V_44 & 0xff ) == 0 ) {
F_15 ( 1 ) ;
if ( * V_44 > 100000 )
return - V_47 ;
}
if ( V_45 < V_2 -> V_48 ||
V_45 > V_2 -> V_48 + ( V_2 -> V_16 . V_21 << 2 ) )
return - V_49 ;
return ( V_45 - V_2 -> V_48 ) >> 2 ;
}
void
F_16 ( struct V_1 * V_2 , struct V_7 * V_13 ,
int V_50 , int V_51 )
{
struct V_7 * V_52 = V_2 -> V_9 ;
struct V_53 * V_54 ;
int V_55 = ( V_2 -> V_16 . V_19 * 2 ) + V_2 -> V_16 . V_17 ;
T_3 V_56 ;
V_54 = F_17 ( V_13 , V_2 -> V_57 ) ;
F_18 ( ! V_54 ) ;
V_56 = V_54 -> V_56 + V_50 ;
F_18 ( V_2 -> V_16 . V_20 < 1 ) ;
F_19 ( V_52 , V_55 ++ , F_20 ( V_56 ) ) ;
F_19 ( V_52 , V_55 ++ , F_21 ( V_56 ) | V_51 << 8 ) ;
V_2 -> V_16 . V_19 = ( V_2 -> V_16 . V_19 + 1 ) & V_2 -> V_16 . V_18 ;
F_22 () ;
F_23 ( V_52 , 0 ) ;
F_24 ( V_2 , 0x8c , V_2 -> V_16 . V_19 ) ;
V_2 -> V_16 . V_20 -- ;
}
static int
F_25 ( struct V_1 * V_2 , int V_58 )
{
T_2 V_59 = 0 , V_43 = 0 ;
while ( V_2 -> V_16 . V_20 < V_58 ) {
T_2 V_60 = F_14 ( V_2 , 0x88 ) ;
if ( V_60 != V_43 ) {
V_43 = V_60 ;
V_59 = 0 ;
}
if ( ( ++ V_59 & 0xff ) == 0 ) {
F_15 ( 1 ) ;
if ( V_59 > 100000 )
return - V_47 ;
}
V_2 -> V_16 . V_20 = V_60 - V_2 -> V_16 . V_19 ;
if ( V_2 -> V_16 . V_20 <= 0 )
V_2 -> V_16 . V_20 += V_2 -> V_16 . V_18 ;
}
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 , int V_61 , int V_58 )
{
T_2 V_59 = 0 , V_43 = 0 ;
int V_25 ;
V_25 = F_25 ( V_2 , V_61 + 1 ) ;
if ( F_27 ( V_25 ) )
return V_25 ;
while ( V_2 -> V_16 . free < V_58 ) {
int V_60 = F_13 ( V_2 , & V_43 , & V_59 ) ;
if ( F_27 ( V_60 < 0 ) ) {
if ( V_60 == - V_49 )
continue;
return V_60 ;
}
if ( V_60 <= V_2 -> V_16 . V_23 ) {
V_2 -> V_16 . free = V_2 -> V_16 . V_21 - V_2 -> V_16 . V_23 ;
if ( V_2 -> V_16 . free >= V_58 )
break;
F_7 ( V_2 ) ;
do {
V_60 = F_13 ( V_2 , & V_43 , & V_59 ) ;
if ( F_27 ( V_60 < 0 ) ) {
if ( V_60 == - V_49 )
continue;
return V_60 ;
}
} while ( V_60 == 0 );
V_2 -> V_16 . V_23 = 0 ;
V_2 -> V_16 . V_22 = 0 ;
}
V_2 -> V_16 . free = V_60 - V_2 -> V_16 . V_23 - 1 ;
}
return 0 ;
}
int
F_28 ( struct V_1 * V_2 , int V_61 , int V_15 )
{
T_2 V_43 = 0 , V_59 = 0 ;
int V_60 ;
if ( V_2 -> V_16 . V_18 )
return F_26 ( V_2 , V_61 , V_15 ) ;
while ( V_2 -> V_16 . free < V_15 ) {
V_60 = F_13 ( V_2 , & V_43 , & V_59 ) ;
if ( F_27 ( V_60 == - V_47 ) )
return - V_47 ;
if ( F_27 ( V_60 == - V_49 ) || V_60 < V_32 )
continue;
if ( V_60 <= V_2 -> V_16 . V_23 ) {
V_2 -> V_16 . free = V_2 -> V_16 . V_21 - V_2 -> V_16 . V_23 ;
if ( V_2 -> V_16 . free >= V_15 )
break;
F_6 ( V_2 , V_2 -> V_48 | 0x20000000 ) ;
do {
V_60 = F_13 ( V_2 , & V_43 , & V_59 ) ;
if ( F_27 ( V_60 == - V_47 ) )
return - V_47 ;
if ( F_27 ( V_60 == - V_49 ) )
continue;
} while ( V_60 <= V_32 );
F_29 ( V_32 ) ;
V_2 -> V_16 . V_23 =
V_2 -> V_16 . V_22 = V_32 ;
}
V_2 -> V_16 . free = V_60 - V_2 -> V_16 . V_23 - 1 ;
}
return 0 ;
}

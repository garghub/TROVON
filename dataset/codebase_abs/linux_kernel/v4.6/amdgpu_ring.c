int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_3 = ( V_3 + V_2 -> V_4 ) & ~ V_2 -> V_4 ;
if ( F_2 ( V_3 > V_2 -> V_5 ) )
return - V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 = V_2 -> V_9 ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
F_4 ( V_2 , V_2 -> V_12 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
while ( V_14 -> V_15 & V_2 -> V_4 )
V_14 -> V_16 [ V_14 -> V_15 ++ ] = V_2 -> V_12 ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_10 ;
V_10 = V_2 -> V_4 + 1 - ( V_2 -> V_9 & V_2 -> V_4 ) ;
V_10 %= V_2 -> V_4 + 1 ;
V_2 -> V_17 -> V_18 ( V_2 , V_10 ) ;
F_7 () ;
F_8 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_9 = V_2 -> V_8 ;
}
unsigned F_10 ( struct V_1 * V_2 ,
T_1 * * V_19 )
{
unsigned V_20 , V_16 , V_11 ;
* V_19 = NULL ;
if ( V_2 -> V_21 == NULL )
return 0 ;
if ( ! F_11 ( V_2 ) )
return 0 ;
V_16 = F_12 ( * V_2 -> V_22 ) ;
V_20 = V_2 -> V_9 + ( V_2 -> V_23 / 4 ) ;
V_20 -= V_16 ;
V_20 &= V_2 -> V_24 ;
if ( V_20 == 0 )
return 0 ;
* V_19 = F_13 ( V_20 , sizeof( T_1 ) , V_25 ) ;
if ( ! * V_19 )
return 0 ;
for ( V_11 = 0 ; V_11 < V_20 ; ++ V_11 ) {
( * V_19 ) [ V_11 ] = V_2 -> V_2 [ V_16 ++ ] ;
V_16 &= V_2 -> V_24 ;
}
return V_20 ;
}
int F_14 ( struct V_1 * V_2 ,
unsigned V_20 , T_1 * V_19 )
{
int V_11 , V_26 ;
if ( ! V_20 || ! V_19 )
return 0 ;
V_26 = F_1 ( V_2 , V_20 ) ;
if ( V_26 )
return V_26 ;
for ( V_11 = 0 ; V_11 < V_20 ; ++ V_11 ) {
F_4 ( V_2 , V_19 [ V_11 ] ) ;
}
F_6 ( V_2 ) ;
F_15 ( V_19 ) ;
return 0 ;
}
int F_16 ( struct V_27 * V_28 , struct V_1 * V_2 ,
unsigned V_23 , T_2 V_12 , T_2 V_4 ,
struct V_29 * V_30 , unsigned V_31 ,
enum V_32 V_33 )
{
T_2 V_34 ;
int V_26 ;
if ( V_2 -> V_28 == NULL ) {
if ( V_28 -> V_35 >= V_36 )
return - V_37 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_38 = V_28 -> V_35 ++ ;
V_28 -> V_39 [ V_2 -> V_38 ] = V_2 ;
V_26 = F_17 ( V_2 ,
V_40 ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_18 ( V_28 , & V_2 -> V_41 ) ;
if ( V_26 ) {
F_19 ( V_28 -> V_42 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_18 ( V_28 , & V_2 -> V_43 ) ;
if ( V_26 ) {
F_19 ( V_28 -> V_42 , L_2 , V_26 ) ;
return V_26 ;
}
V_26 = F_18 ( V_28 , & V_2 -> V_44 ) ;
if ( V_26 ) {
F_19 ( V_28 -> V_42 , L_3 , V_26 ) ;
return V_26 ;
}
V_26 = F_18 ( V_28 , & V_2 -> V_45 ) ;
if ( V_26 ) {
F_19 ( V_28 -> V_42 , L_4 , V_26 ) ;
return V_26 ;
}
V_2 -> V_46 = V_28 -> V_47 . V_48 + ( V_2 -> V_45 * 4 ) ;
V_2 -> V_22 = & V_28 -> V_47 . V_47 [ V_2 -> V_45 ] ;
F_20 ( & V_2 -> V_49 ) ;
V_26 = F_21 ( V_2 , V_30 , V_31 ) ;
if ( V_26 ) {
F_19 ( V_28 -> V_42 , L_5 , V_26 ) ;
return V_26 ;
}
V_34 = F_22 ( V_23 / 8 ) ;
V_23 = ( 1 << ( V_34 + 1 ) ) * 4 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> type = V_33 ;
if ( V_2 -> V_21 == NULL ) {
V_26 = F_23 ( V_28 , V_2 -> V_23 , V_50 , true ,
V_51 , 0 ,
NULL , NULL , & V_2 -> V_21 ) ;
if ( V_26 ) {
F_19 ( V_28 -> V_42 , L_6 , V_26 ) ;
return V_26 ;
}
V_26 = F_24 ( V_2 -> V_21 , false ) ;
if ( F_25 ( V_26 != 0 ) )
return V_26 ;
V_26 = F_26 ( V_2 -> V_21 , V_51 ,
& V_2 -> V_48 ) ;
if ( V_26 ) {
F_27 ( V_2 -> V_21 ) ;
F_19 ( V_28 -> V_42 , L_7 , V_26 ) ;
return V_26 ;
}
V_26 = F_28 ( V_2 -> V_21 ,
( void * * ) & V_2 -> V_2 ) ;
F_27 ( V_2 -> V_21 ) ;
if ( V_26 ) {
F_19 ( V_28 -> V_42 , L_8 , V_26 ) ;
return V_26 ;
}
}
V_2 -> V_24 = ( V_2 -> V_23 / 4 ) - 1 ;
V_2 -> V_5 = F_29 ( V_2 -> V_23 / 4 ,
V_40 ) ;
if ( F_30 ( V_28 , V_2 ) ) {
F_31 ( L_9 ) ;
}
return 0 ;
}
void F_32 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_52 * V_21 ;
V_21 = V_2 -> V_21 ;
V_2 -> V_53 = false ;
V_2 -> V_2 = NULL ;
V_2 -> V_21 = NULL ;
F_33 ( V_2 -> V_28 , V_2 -> V_44 ) ;
F_33 ( V_2 -> V_28 , V_2 -> V_41 ) ;
F_33 ( V_2 -> V_28 , V_2 -> V_43 ) ;
F_33 ( V_2 -> V_28 , V_2 -> V_45 ) ;
if ( V_21 ) {
V_26 = F_24 ( V_21 , false ) ;
if ( F_34 ( V_26 == 0 ) ) {
F_35 ( V_21 ) ;
F_36 ( V_21 ) ;
F_27 ( V_21 ) ;
}
F_37 ( & V_21 ) ;
}
}
static int F_38 ( struct V_54 * V_55 , void * V_19 )
{
struct V_56 * V_57 = (struct V_56 * ) V_55 -> V_58 ;
struct V_59 * V_42 = V_57 -> V_60 -> V_42 ;
struct V_27 * V_28 = V_42 -> V_61 ;
int V_62 = * ( int * ) V_57 -> V_63 -> V_19 ;
struct V_1 * V_2 = ( void * ) ( ( ( V_64 * ) V_28 ) + V_62 ) ;
T_1 V_65 , V_9 , V_66 ;
unsigned V_11 ;
V_9 = F_39 ( V_2 ) ;
F_40 ( V_55 , L_10 , V_9 , V_9 ) ;
V_65 = F_41 ( V_2 ) ;
V_66 = F_12 ( * V_2 -> V_22 ) ;
F_40 ( V_55 , L_11 , V_65 , V_65 ) ;
F_40 ( V_55 , L_12 ,
V_2 -> V_9 , V_2 -> V_9 ) ;
if ( ! V_2 -> V_53 )
return 0 ;
V_11 = ( V_65 + V_2 -> V_24 + 1 - 32 ) & V_2 -> V_24 ;
while ( V_11 != V_65 ) {
F_40 ( V_55 , L_13 , V_11 , V_2 -> V_2 [ V_11 ] ) ;
if ( V_11 == V_65 )
F_42 ( V_55 , L_14 ) ;
if ( V_11 == V_66 )
F_42 ( V_55 , L_15 ) ;
F_42 ( V_55 , L_16 ) ;
V_11 = ( V_11 + 1 ) & V_2 -> V_24 ;
}
while ( V_11 != V_9 ) {
F_40 ( V_55 , L_13 , V_11 , V_2 -> V_2 [ V_11 ] ) ;
if ( V_11 == V_65 )
F_42 ( V_55 , L_14 ) ;
if ( V_11 == V_66 )
F_42 ( V_55 , L_15 ) ;
F_42 ( V_55 , L_16 ) ;
V_11 = ( V_11 + 1 ) & V_2 -> V_24 ;
}
return 0 ;
}
static int F_30 ( struct V_27 * V_28 , struct V_1 * V_2 )
{
#if F_43 ( V_67 )
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < F_44 ( V_68 ) ; ++ V_11 ) {
struct V_69 * V_70 = & V_68 [ V_11 ] ;
int V_62 = * ( int * ) V_68 [ V_11 ] . V_19 ;
struct V_1 * V_71 = ( void * ) ( ( ( V_64 * ) V_28 ) + V_62 ) ;
unsigned V_26 ;
if ( V_71 != V_2 )
continue;
V_26 = F_45 ( V_28 , V_70 , 1 ) ;
if ( V_26 )
return V_26 ;
}
#endif
return 0 ;
}

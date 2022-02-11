void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
V_2 -> V_4 = V_3 + ( V_2 -> V_5 / 4 ) ;
V_2 -> V_4 -= V_2 -> V_6 ;
V_2 -> V_4 &= V_2 -> V_7 ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_4 = V_2 -> V_5 / 4 ;
F_3 ( V_2 ) ;
}
}
int F_4 ( struct V_1 * V_2 , unsigned V_8 )
{
int V_9 ;
if ( V_8 > ( V_2 -> V_5 / 4 ) )
return - V_10 ;
F_1 ( V_2 ) ;
V_8 = ( V_8 + V_2 -> V_11 ) & ~ V_2 -> V_11 ;
while ( V_8 > ( V_2 -> V_4 - 1 ) ) {
F_1 ( V_2 ) ;
if ( V_8 < V_2 -> V_4 ) {
break;
}
V_9 = F_5 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
V_2 -> V_12 = V_8 ;
V_2 -> V_13 = V_2 -> V_6 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , unsigned V_8 )
{
int V_9 ;
F_7 ( V_2 -> V_14 ) ;
V_9 = F_4 ( V_2 , V_8 ) ;
if ( V_9 ) {
F_8 ( V_2 -> V_14 ) ;
return V_9 ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
while ( V_2 -> V_6 & V_2 -> V_11 ) {
F_10 ( V_2 , V_2 -> V_15 ) ;
}
F_11 () ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
F_8 ( V_2 -> V_14 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_13 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_8 ( V_2 -> V_14 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_16 ( & V_2 -> V_16 , F_2 ( V_2 ) ) ;
F_17 ( & V_2 -> V_17 , V_18 ) ;
}
bool F_18 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
T_2 V_19 = F_19 ( & V_2 -> V_17 ) ;
T_2 V_20 ;
if ( V_3 != F_20 ( & V_2 -> V_16 ) ) {
F_3 ( V_2 ) ;
return false ;
}
V_20 = F_21 ( V_18 - V_19 ) ;
if ( V_21 && V_20 >= V_21 ) {
F_22 ( V_2 -> V_22 -> V_23 , L_1 ,
V_2 -> V_24 , V_20 ) ;
return true ;
}
return false ;
}
unsigned F_23 ( struct V_1 * V_2 ,
T_1 * * V_25 )
{
unsigned V_26 , V_27 , V_28 ;
F_7 ( V_2 -> V_14 ) ;
* V_25 = NULL ;
if ( V_2 -> V_29 == NULL ) {
F_8 ( V_2 -> V_14 ) ;
return 0 ;
}
if ( ! F_24 ( V_2 ) ) {
F_8 ( V_2 -> V_14 ) ;
return 0 ;
}
V_27 = F_25 ( * V_2 -> V_30 ) ;
V_26 = V_2 -> V_6 + ( V_2 -> V_5 / 4 ) ;
V_26 -= V_27 ;
V_26 &= V_2 -> V_7 ;
if ( V_26 == 0 ) {
F_8 ( V_2 -> V_14 ) ;
return 0 ;
}
* V_25 = F_26 ( V_26 , sizeof( T_1 ) , V_31 ) ;
if ( ! * V_25 ) {
F_8 ( V_2 -> V_14 ) ;
return 0 ;
}
for ( V_28 = 0 ; V_28 < V_26 ; ++ V_28 ) {
( * V_25 ) [ V_28 ] = V_2 -> V_2 [ V_27 ++ ] ;
V_27 &= V_2 -> V_7 ;
}
F_8 ( V_2 -> V_14 ) ;
return V_26 ;
}
int F_27 ( struct V_1 * V_2 ,
unsigned V_26 , T_1 * V_25 )
{
int V_28 , V_9 ;
if ( ! V_26 || ! V_25 )
return 0 ;
V_9 = F_6 ( V_2 , V_26 ) ;
if ( V_9 )
return V_9 ;
for ( V_28 = 0 ; V_28 < V_26 ; ++ V_28 ) {
F_10 ( V_2 , V_25 [ V_28 ] ) ;
}
F_13 ( V_2 ) ;
F_28 ( V_25 ) ;
return 0 ;
}
int F_29 ( struct V_32 * V_22 , struct V_1 * V_2 ,
unsigned V_5 , T_3 V_15 , T_3 V_11 ,
struct V_33 * V_34 , unsigned V_35 ,
enum V_36 V_37 )
{
T_3 V_38 ;
int V_9 ;
if ( V_2 -> V_22 == NULL ) {
if ( V_22 -> V_39 >= V_40 )
return - V_41 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_24 = V_22 -> V_39 ++ ;
V_22 -> V_42 [ V_2 -> V_24 ] = V_2 ;
F_30 ( V_2 ) ;
}
V_9 = F_31 ( V_22 , & V_2 -> V_43 ) ;
if ( V_9 ) {
F_22 ( V_22 -> V_23 , L_2 , V_9 ) ;
return V_9 ;
}
V_9 = F_31 ( V_22 , & V_2 -> V_44 ) ;
if ( V_9 ) {
F_22 ( V_22 -> V_23 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_31 ( V_22 , & V_2 -> V_45 ) ;
if ( V_9 ) {
F_22 ( V_22 -> V_23 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_31 ( V_22 , & V_2 -> V_46 ) ;
if ( V_9 ) {
F_22 ( V_22 -> V_23 , L_5 , V_9 ) ;
return V_9 ;
}
V_2 -> V_47 = V_22 -> V_48 . V_49 + ( V_2 -> V_46 * 4 ) ;
V_2 -> V_30 = & V_22 -> V_48 . V_48 [ V_2 -> V_46 ] ;
V_9 = F_32 ( V_2 , V_34 , V_35 ) ;
if ( V_9 ) {
F_22 ( V_22 -> V_23 , L_6 , V_9 ) ;
return V_9 ;
}
V_2 -> V_14 = & V_22 -> V_14 ;
V_38 = F_33 ( V_5 / 8 ) ;
V_5 = ( 1 << ( V_38 + 1 ) ) * 4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_15 = V_15 ;
V_2 -> type = V_37 ;
if ( V_2 -> V_29 == NULL ) {
V_9 = F_34 ( V_22 , V_2 -> V_5 , V_50 , true ,
V_51 , 0 ,
NULL , & V_2 -> V_29 ) ;
if ( V_9 ) {
F_22 ( V_22 -> V_23 , L_7 , V_9 ) ;
return V_9 ;
}
V_9 = F_35 ( V_2 -> V_29 , false ) ;
if ( F_36 ( V_9 != 0 ) )
return V_9 ;
V_9 = F_37 ( V_2 -> V_29 , V_51 ,
& V_2 -> V_49 ) ;
if ( V_9 ) {
F_38 ( V_2 -> V_29 ) ;
F_22 ( V_22 -> V_23 , L_8 , V_9 ) ;
return V_9 ;
}
V_9 = F_39 ( V_2 -> V_29 ,
( void * * ) & V_2 -> V_2 ) ;
F_38 ( V_2 -> V_29 ) ;
if ( V_9 ) {
F_22 ( V_22 -> V_23 , L_9 , V_9 ) ;
return V_9 ;
}
}
V_2 -> V_7 = ( V_2 -> V_5 / 4 ) - 1 ;
V_2 -> V_4 = V_2 -> V_5 / 4 ;
if ( F_40 ( V_22 , V_2 ) ) {
F_41 ( L_10 ) ;
}
F_3 ( V_2 ) ;
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_52 * V_29 ;
if ( V_2 -> V_14 == NULL )
return;
F_7 ( V_2 -> V_14 ) ;
V_29 = V_2 -> V_29 ;
V_2 -> V_53 = false ;
V_2 -> V_2 = NULL ;
V_2 -> V_29 = NULL ;
F_8 ( V_2 -> V_14 ) ;
F_43 ( V_2 -> V_22 , V_2 -> V_45 ) ;
F_43 ( V_2 -> V_22 , V_2 -> V_43 ) ;
F_43 ( V_2 -> V_22 , V_2 -> V_44 ) ;
F_43 ( V_2 -> V_22 , V_2 -> V_46 ) ;
if ( V_29 ) {
V_9 = F_35 ( V_29 , false ) ;
if ( F_44 ( V_9 == 0 ) ) {
F_45 ( V_29 ) ;
F_46 ( V_29 ) ;
F_38 ( V_29 ) ;
}
F_47 ( & V_29 ) ;
}
}
static int F_48 ( struct V_54 * V_55 , void * V_25 )
{
struct V_56 * V_57 = (struct V_56 * ) V_55 -> V_58 ;
struct V_59 * V_23 = V_57 -> V_60 -> V_23 ;
struct V_32 * V_22 = V_23 -> V_61 ;
int V_62 = * ( int * ) V_57 -> V_63 -> V_25 ;
struct V_1 * V_2 = ( void * ) ( ( ( V_64 * ) V_22 ) + V_62 ) ;
T_1 V_3 , V_6 , V_65 ;
unsigned V_66 , V_28 , V_67 ;
F_1 ( V_2 ) ;
V_66 = ( V_2 -> V_5 / 4 ) - V_2 -> V_4 ;
V_6 = F_49 ( V_2 ) ;
F_50 ( V_55 , L_11 ,
V_6 , V_6 ) ;
V_3 = F_2 ( V_2 ) ;
F_50 ( V_55 , L_12 ,
V_3 , V_3 ) ;
V_65 = ~ 0 ;
F_50 ( V_55 , L_13 ,
V_2 -> V_6 , V_2 -> V_6 ) ;
F_50 ( V_55 , L_14 ,
V_2 -> V_68 ) ;
F_50 ( V_55 , L_15 ,
V_2 -> V_69 ) ;
F_50 ( V_55 , L_16 , V_2 -> V_4 ) ;
F_50 ( V_55 , L_17 , V_66 ) ;
if ( ! V_2 -> V_53 )
return 0 ;
V_28 = ( V_3 + V_2 -> V_7 + 1 - 32 ) & V_2 -> V_7 ;
for ( V_67 = 0 ; V_67 <= ( V_66 + 32 ) ; V_67 ++ ) {
F_50 ( V_55 , L_18 , V_28 , V_2 -> V_2 [ V_28 ] ) ;
if ( V_3 == V_28 )
F_51 ( V_55 , L_19 ) ;
if ( V_65 == V_28 )
F_51 ( V_55 , L_20 ) ;
F_51 ( V_55 , L_21 ) ;
V_28 = ( V_28 + 1 ) & V_2 -> V_7 ;
}
return 0 ;
}
static int F_40 ( struct V_32 * V_22 , struct V_1 * V_2 )
{
#if F_52 ( V_70 )
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < F_53 ( V_71 ) ; ++ V_28 ) {
struct V_72 * V_73 = & V_71 [ V_28 ] ;
int V_62 = * ( int * ) V_71 [ V_28 ] . V_25 ;
struct V_1 * V_74 = ( void * ) ( ( ( V_64 * ) V_22 ) + V_62 ) ;
unsigned V_9 ;
if ( V_74 != V_2 )
continue;
V_9 = F_54 ( V_22 , V_73 , 1 ) ;
if ( V_9 )
return V_9 ;
}
#endif
return 0 ;
}

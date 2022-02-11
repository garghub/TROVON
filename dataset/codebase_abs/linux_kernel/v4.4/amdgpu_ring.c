void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
V_2 -> V_4 = V_3 + ( V_2 -> V_5 / 4 ) ;
V_2 -> V_4 -= V_2 -> V_6 ;
V_2 -> V_4 &= V_2 -> V_7 ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_4 = V_2 -> V_5 / 4 ;
}
}
int F_3 ( struct V_1 * V_2 , unsigned V_8 )
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
V_9 = F_4 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
V_2 -> V_12 = V_8 ;
V_2 -> V_13 = V_2 -> V_6 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , unsigned V_8 )
{
int V_9 ;
F_6 ( V_2 -> V_14 ) ;
V_9 = F_3 ( V_2 , V_8 ) ;
if ( V_9 ) {
F_7 ( V_2 -> V_14 ) ;
return V_9 ;
}
return 0 ;
}
void F_8 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
F_9 ( V_2 , V_2 -> V_17 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
T_1 V_15 ;
V_15 = V_2 -> V_11 + 1 - ( V_2 -> V_6 & V_2 -> V_11 ) ;
V_15 %= V_2 -> V_11 + 1 ;
V_2 -> V_18 -> V_19 ( V_2 , V_15 ) ;
F_11 () ;
F_12 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_7 ( V_2 -> V_14 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_13 ;
}
void F_15 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_7 ( V_2 -> V_14 ) ;
}
unsigned F_16 ( struct V_1 * V_2 ,
T_1 * * V_20 )
{
unsigned V_21 , V_22 , V_16 ;
F_6 ( V_2 -> V_14 ) ;
* V_20 = NULL ;
if ( V_2 -> V_23 == NULL ) {
F_7 ( V_2 -> V_14 ) ;
return 0 ;
}
if ( ! F_17 ( V_2 ) ) {
F_7 ( V_2 -> V_14 ) ;
return 0 ;
}
V_22 = F_18 ( * V_2 -> V_24 ) ;
V_21 = V_2 -> V_6 + ( V_2 -> V_5 / 4 ) ;
V_21 -= V_22 ;
V_21 &= V_2 -> V_7 ;
if ( V_21 == 0 ) {
F_7 ( V_2 -> V_14 ) ;
return 0 ;
}
* V_20 = F_19 ( V_21 , sizeof( T_1 ) , V_25 ) ;
if ( ! * V_20 ) {
F_7 ( V_2 -> V_14 ) ;
return 0 ;
}
for ( V_16 = 0 ; V_16 < V_21 ; ++ V_16 ) {
( * V_20 ) [ V_16 ] = V_2 -> V_2 [ V_22 ++ ] ;
V_22 &= V_2 -> V_7 ;
}
F_7 ( V_2 -> V_14 ) ;
return V_21 ;
}
int F_20 ( struct V_1 * V_2 ,
unsigned V_21 , T_1 * V_20 )
{
int V_16 , V_9 ;
if ( ! V_21 || ! V_20 )
return 0 ;
V_9 = F_5 ( V_2 , V_21 ) ;
if ( V_9 )
return V_9 ;
for ( V_16 = 0 ; V_16 < V_21 ; ++ V_16 ) {
F_9 ( V_2 , V_20 [ V_16 ] ) ;
}
F_13 ( V_2 ) ;
F_21 ( V_20 ) ;
return 0 ;
}
int F_22 ( struct V_26 * V_27 , struct V_1 * V_2 ,
unsigned V_5 , T_2 V_17 , T_2 V_11 ,
struct V_28 * V_29 , unsigned V_30 ,
enum V_31 V_32 )
{
T_2 V_33 ;
int V_9 ;
if ( V_2 -> V_27 == NULL ) {
if ( V_27 -> V_34 >= V_35 )
return - V_36 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_37 = V_27 -> V_34 ++ ;
V_27 -> V_38 [ V_2 -> V_37 ] = V_2 ;
V_9 = F_23 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_24 ( V_27 , & V_2 -> V_39 ) ;
if ( V_9 ) {
F_25 ( V_27 -> V_40 , L_1 , V_9 ) ;
return V_9 ;
}
V_9 = F_24 ( V_27 , & V_2 -> V_41 ) ;
if ( V_9 ) {
F_25 ( V_27 -> V_40 , L_2 , V_9 ) ;
return V_9 ;
}
V_9 = F_24 ( V_27 , & V_2 -> V_42 ) ;
if ( V_9 ) {
F_25 ( V_27 -> V_40 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_24 ( V_27 , & V_2 -> V_43 ) ;
if ( V_9 ) {
F_25 ( V_27 -> V_40 , L_4 , V_9 ) ;
return V_9 ;
}
V_2 -> V_44 = V_27 -> V_45 . V_46 + ( V_2 -> V_43 * 4 ) ;
V_2 -> V_24 = & V_27 -> V_45 . V_45 [ V_2 -> V_43 ] ;
F_26 ( & V_2 -> V_47 ) ;
V_9 = F_27 ( V_2 , V_29 , V_30 ) ;
if ( V_9 ) {
F_25 ( V_27 -> V_40 , L_5 , V_9 ) ;
return V_9 ;
}
V_2 -> V_14 = & V_27 -> V_14 ;
V_33 = F_28 ( V_5 / 8 ) ;
V_5 = ( 1 << ( V_33 + 1 ) ) * 4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_17 = V_17 ;
V_2 -> type = V_32 ;
if ( V_2 -> V_23 == NULL ) {
V_9 = F_29 ( V_27 , V_2 -> V_5 , V_48 , true ,
V_49 , 0 ,
NULL , NULL , & V_2 -> V_23 ) ;
if ( V_9 ) {
F_25 ( V_27 -> V_40 , L_6 , V_9 ) ;
return V_9 ;
}
V_9 = F_30 ( V_2 -> V_23 , false ) ;
if ( F_31 ( V_9 != 0 ) )
return V_9 ;
V_9 = F_32 ( V_2 -> V_23 , V_49 ,
& V_2 -> V_46 ) ;
if ( V_9 ) {
F_33 ( V_2 -> V_23 ) ;
F_25 ( V_27 -> V_40 , L_7 , V_9 ) ;
return V_9 ;
}
V_9 = F_34 ( V_2 -> V_23 ,
( void * * ) & V_2 -> V_2 ) ;
F_33 ( V_2 -> V_23 ) ;
if ( V_9 ) {
F_25 ( V_27 -> V_40 , L_8 , V_9 ) ;
return V_9 ;
}
}
V_2 -> V_7 = ( V_2 -> V_5 / 4 ) - 1 ;
V_2 -> V_4 = V_2 -> V_5 / 4 ;
if ( F_35 ( V_27 , V_2 ) ) {
F_36 ( L_9 ) ;
}
return 0 ;
}
void F_37 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_50 * V_23 ;
if ( V_2 -> V_14 == NULL )
return;
F_6 ( V_2 -> V_14 ) ;
V_23 = V_2 -> V_23 ;
V_2 -> V_51 = false ;
V_2 -> V_2 = NULL ;
V_2 -> V_23 = NULL ;
F_7 ( V_2 -> V_14 ) ;
F_38 ( V_2 -> V_27 , V_2 -> V_42 ) ;
F_38 ( V_2 -> V_27 , V_2 -> V_39 ) ;
F_38 ( V_2 -> V_27 , V_2 -> V_41 ) ;
F_38 ( V_2 -> V_27 , V_2 -> V_43 ) ;
if ( V_23 ) {
V_9 = F_30 ( V_23 , false ) ;
if ( F_39 ( V_9 == 0 ) ) {
F_40 ( V_23 ) ;
F_41 ( V_23 ) ;
F_33 ( V_23 ) ;
}
F_42 ( & V_23 ) ;
}
}
struct V_1 * F_43 ( struct V_52 * V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
V_57 = F_44 ( V_53 ) ;
if ( V_57 )
return F_45 ( V_57 -> V_58 , struct V_1 , V_58 ) ;
V_55 = F_46 ( V_53 ) ;
if ( V_55 )
return V_55 -> V_2 ;
return NULL ;
}
static int F_47 ( struct V_59 * V_60 , void * V_20 )
{
struct V_61 * V_62 = (struct V_61 * ) V_60 -> V_63 ;
struct V_64 * V_40 = V_62 -> V_65 -> V_40 ;
struct V_26 * V_27 = V_40 -> V_66 ;
int V_67 = * ( int * ) V_62 -> V_68 -> V_20 ;
struct V_1 * V_2 = ( void * ) ( ( ( V_69 * ) V_27 ) + V_67 ) ;
T_1 V_3 , V_6 , V_70 ;
unsigned V_15 , V_16 , V_71 ;
F_1 ( V_2 ) ;
V_15 = ( V_2 -> V_5 / 4 ) - V_2 -> V_4 ;
V_6 = F_48 ( V_2 ) ;
F_49 ( V_60 , L_10 ,
V_6 , V_6 ) ;
V_3 = F_2 ( V_2 ) ;
F_49 ( V_60 , L_11 ,
V_3 , V_3 ) ;
V_70 = ~ 0 ;
F_49 ( V_60 , L_12 ,
V_2 -> V_6 , V_2 -> V_6 ) ;
F_49 ( V_60 , L_13 ,
V_2 -> V_72 ) ;
F_49 ( V_60 , L_14 ,
V_2 -> V_73 ) ;
F_49 ( V_60 , L_15 , V_2 -> V_4 ) ;
F_49 ( V_60 , L_16 , V_15 ) ;
if ( ! V_2 -> V_51 )
return 0 ;
V_16 = ( V_3 + V_2 -> V_7 + 1 - 32 ) & V_2 -> V_7 ;
for ( V_71 = 0 ; V_71 <= ( V_15 + 32 ) ; V_71 ++ ) {
F_49 ( V_60 , L_17 , V_16 , V_2 -> V_2 [ V_16 ] ) ;
if ( V_3 == V_16 )
F_50 ( V_60 , L_18 ) ;
if ( V_70 == V_16 )
F_50 ( V_60 , L_19 ) ;
F_50 ( V_60 , L_20 ) ;
V_16 = ( V_16 + 1 ) & V_2 -> V_7 ;
}
return 0 ;
}
static int F_35 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
#if F_51 ( V_74 )
unsigned V_16 ;
for ( V_16 = 0 ; V_16 < F_52 ( V_75 ) ; ++ V_16 ) {
struct V_76 * V_77 = & V_75 [ V_16 ] ;
int V_67 = * ( int * ) V_75 [ V_16 ] . V_20 ;
struct V_1 * V_78 = ( void * ) ( ( ( V_69 * ) V_27 ) + V_67 ) ;
unsigned V_9 ;
if ( V_78 != V_2 )
continue;
V_9 = F_53 ( V_27 , V_77 , 1 ) ;
if ( V_9 )
return V_9 ;
}
#endif
return 0 ;
}

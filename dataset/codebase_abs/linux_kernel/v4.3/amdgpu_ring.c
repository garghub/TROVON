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
void F_9 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 ; V_16 ++ )
F_10 ( V_2 , V_2 -> V_17 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
T_1 V_15 ;
V_15 = V_2 -> V_11 + 1 - ( V_2 -> V_6 & V_2 -> V_11 ) ;
V_15 %= V_2 -> V_11 + 1 ;
V_2 -> V_18 -> V_19 ( V_2 , V_15 ) ;
F_12 () ;
F_13 ( V_2 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_8 ( V_2 -> V_14 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_13 ;
}
void F_16 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
F_8 ( V_2 -> V_14 ) ;
}
void F_3 ( struct V_1 * V_2 )
{
F_17 ( & V_2 -> V_20 , F_2 ( V_2 ) ) ;
F_18 ( & V_2 -> V_21 , V_22 ) ;
}
bool F_19 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 ) ;
T_2 V_23 = F_20 ( & V_2 -> V_21 ) ;
T_2 V_24 ;
if ( V_3 != F_21 ( & V_2 -> V_20 ) ) {
F_3 ( V_2 ) ;
return false ;
}
V_24 = F_22 ( V_22 - V_23 ) ;
if ( V_25 && V_24 >= V_25 ) {
F_23 ( V_2 -> V_26 -> V_27 , L_1 ,
V_2 -> V_28 , V_24 ) ;
return true ;
}
return false ;
}
unsigned F_24 ( struct V_1 * V_2 ,
T_1 * * V_29 )
{
unsigned V_30 , V_31 , V_16 ;
F_7 ( V_2 -> V_14 ) ;
* V_29 = NULL ;
if ( V_2 -> V_32 == NULL ) {
F_8 ( V_2 -> V_14 ) ;
return 0 ;
}
if ( ! F_25 ( V_2 ) ) {
F_8 ( V_2 -> V_14 ) ;
return 0 ;
}
V_31 = F_26 ( * V_2 -> V_33 ) ;
V_30 = V_2 -> V_6 + ( V_2 -> V_5 / 4 ) ;
V_30 -= V_31 ;
V_30 &= V_2 -> V_7 ;
if ( V_30 == 0 ) {
F_8 ( V_2 -> V_14 ) ;
return 0 ;
}
* V_29 = F_27 ( V_30 , sizeof( T_1 ) , V_34 ) ;
if ( ! * V_29 ) {
F_8 ( V_2 -> V_14 ) ;
return 0 ;
}
for ( V_16 = 0 ; V_16 < V_30 ; ++ V_16 ) {
( * V_29 ) [ V_16 ] = V_2 -> V_2 [ V_31 ++ ] ;
V_31 &= V_2 -> V_7 ;
}
F_8 ( V_2 -> V_14 ) ;
return V_30 ;
}
int F_28 ( struct V_1 * V_2 ,
unsigned V_30 , T_1 * V_29 )
{
int V_16 , V_9 ;
if ( ! V_30 || ! V_29 )
return 0 ;
V_9 = F_6 ( V_2 , V_30 ) ;
if ( V_9 )
return V_9 ;
for ( V_16 = 0 ; V_16 < V_30 ; ++ V_16 ) {
F_10 ( V_2 , V_29 [ V_16 ] ) ;
}
F_14 ( V_2 ) ;
F_29 ( V_29 ) ;
return 0 ;
}
int F_30 ( struct V_35 * V_26 , struct V_1 * V_2 ,
unsigned V_5 , T_3 V_17 , T_3 V_11 ,
struct V_36 * V_37 , unsigned V_38 ,
enum V_39 V_40 )
{
T_3 V_41 ;
int V_9 ;
if ( V_2 -> V_26 == NULL ) {
if ( V_26 -> V_42 >= V_43 )
return - V_44 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_28 = V_26 -> V_42 ++ ;
V_26 -> V_45 [ V_2 -> V_28 ] = V_2 ;
V_9 = F_31 ( V_2 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_32 ( V_26 , & V_2 -> V_46 ) ;
if ( V_9 ) {
F_23 ( V_26 -> V_27 , L_2 , V_9 ) ;
return V_9 ;
}
V_9 = F_32 ( V_26 , & V_2 -> V_47 ) ;
if ( V_9 ) {
F_23 ( V_26 -> V_27 , L_3 , V_9 ) ;
return V_9 ;
}
V_9 = F_32 ( V_26 , & V_2 -> V_48 ) ;
if ( V_9 ) {
F_23 ( V_26 -> V_27 , L_4 , V_9 ) ;
return V_9 ;
}
V_9 = F_32 ( V_26 , & V_2 -> V_49 ) ;
if ( V_9 ) {
F_23 ( V_26 -> V_27 , L_5 , V_9 ) ;
return V_9 ;
}
V_2 -> V_50 = V_26 -> V_51 . V_52 + ( V_2 -> V_49 * 4 ) ;
V_2 -> V_33 = & V_26 -> V_51 . V_51 [ V_2 -> V_49 ] ;
F_33 ( & V_2 -> V_53 ) ;
V_9 = F_34 ( V_2 , V_37 , V_38 ) ;
if ( V_9 ) {
F_23 ( V_26 -> V_27 , L_6 , V_9 ) ;
return V_9 ;
}
V_2 -> V_14 = & V_26 -> V_14 ;
V_41 = F_35 ( V_5 / 8 ) ;
V_5 = ( 1 << ( V_41 + 1 ) ) * 4 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_17 = V_17 ;
V_2 -> type = V_40 ;
if ( V_2 -> V_32 == NULL ) {
V_9 = F_36 ( V_26 , V_2 -> V_5 , V_54 , true ,
V_55 , 0 ,
NULL , NULL , & V_2 -> V_32 ) ;
if ( V_9 ) {
F_23 ( V_26 -> V_27 , L_7 , V_9 ) ;
return V_9 ;
}
V_9 = F_37 ( V_2 -> V_32 , false ) ;
if ( F_38 ( V_9 != 0 ) )
return V_9 ;
V_9 = F_39 ( V_2 -> V_32 , V_55 ,
& V_2 -> V_52 ) ;
if ( V_9 ) {
F_40 ( V_2 -> V_32 ) ;
F_23 ( V_26 -> V_27 , L_8 , V_9 ) ;
return V_9 ;
}
V_9 = F_41 ( V_2 -> V_32 ,
( void * * ) & V_2 -> V_2 ) ;
F_40 ( V_2 -> V_32 ) ;
if ( V_9 ) {
F_23 ( V_26 -> V_27 , L_9 , V_9 ) ;
return V_9 ;
}
}
V_2 -> V_7 = ( V_2 -> V_5 / 4 ) - 1 ;
V_2 -> V_4 = V_2 -> V_5 / 4 ;
if ( F_42 ( V_26 , V_2 ) ) {
F_43 ( L_10 ) ;
}
F_3 ( V_2 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_56 * V_32 ;
if ( V_2 -> V_14 == NULL )
return;
F_7 ( V_2 -> V_14 ) ;
V_32 = V_2 -> V_32 ;
V_2 -> V_57 = false ;
V_2 -> V_2 = NULL ;
V_2 -> V_32 = NULL ;
F_8 ( V_2 -> V_14 ) ;
F_45 ( V_2 -> V_26 , V_2 -> V_48 ) ;
F_45 ( V_2 -> V_26 , V_2 -> V_46 ) ;
F_45 ( V_2 -> V_26 , V_2 -> V_47 ) ;
F_45 ( V_2 -> V_26 , V_2 -> V_49 ) ;
if ( V_32 ) {
V_9 = F_37 ( V_32 , false ) ;
if ( F_46 ( V_9 == 0 ) ) {
F_47 ( V_32 ) ;
F_48 ( V_32 ) ;
F_40 ( V_32 ) ;
}
F_49 ( & V_32 ) ;
}
}
static int F_50 ( struct V_58 * V_59 , void * V_29 )
{
struct V_60 * V_61 = (struct V_60 * ) V_59 -> V_62 ;
struct V_63 * V_27 = V_61 -> V_64 -> V_27 ;
struct V_35 * V_26 = V_27 -> V_65 ;
int V_66 = * ( int * ) V_61 -> V_67 -> V_29 ;
struct V_1 * V_2 = ( void * ) ( ( ( V_68 * ) V_26 ) + V_66 ) ;
T_1 V_3 , V_6 , V_69 ;
unsigned V_15 , V_16 , V_70 ;
F_1 ( V_2 ) ;
V_15 = ( V_2 -> V_5 / 4 ) - V_2 -> V_4 ;
V_6 = F_51 ( V_2 ) ;
F_52 ( V_59 , L_11 ,
V_6 , V_6 ) ;
V_3 = F_2 ( V_2 ) ;
F_52 ( V_59 , L_12 ,
V_3 , V_3 ) ;
V_69 = ~ 0 ;
F_52 ( V_59 , L_13 ,
V_2 -> V_6 , V_2 -> V_6 ) ;
F_52 ( V_59 , L_14 ,
V_2 -> V_71 ) ;
F_52 ( V_59 , L_15 ,
V_2 -> V_72 ) ;
F_52 ( V_59 , L_16 , V_2 -> V_4 ) ;
F_52 ( V_59 , L_17 , V_15 ) ;
if ( ! V_2 -> V_57 )
return 0 ;
V_16 = ( V_3 + V_2 -> V_7 + 1 - 32 ) & V_2 -> V_7 ;
for ( V_70 = 0 ; V_70 <= ( V_15 + 32 ) ; V_70 ++ ) {
F_52 ( V_59 , L_18 , V_16 , V_2 -> V_2 [ V_16 ] ) ;
if ( V_3 == V_16 )
F_53 ( V_59 , L_19 ) ;
if ( V_69 == V_16 )
F_53 ( V_59 , L_20 ) ;
F_53 ( V_59 , L_21 ) ;
V_16 = ( V_16 + 1 ) & V_2 -> V_7 ;
}
return 0 ;
}
static int F_42 ( struct V_35 * V_26 , struct V_1 * V_2 )
{
#if F_54 ( V_73 )
unsigned V_16 ;
for ( V_16 = 0 ; V_16 < F_55 ( V_74 ) ; ++ V_16 ) {
struct V_75 * V_76 = & V_74 [ V_16 ] ;
int V_66 = * ( int * ) V_74 [ V_16 ] . V_29 ;
struct V_1 * V_77 = ( void * ) ( ( ( V_68 * ) V_26 ) + V_66 ) ;
unsigned V_9 ;
if ( V_77 != V_2 )
continue;
V_9 = F_56 ( V_26 , V_76 , 1 ) ;
if ( V_9 )
return V_9 ;
}
#endif
return 0 ;
}

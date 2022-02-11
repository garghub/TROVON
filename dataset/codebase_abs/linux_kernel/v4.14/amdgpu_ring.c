int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_3 = ( V_3 + V_2 -> V_4 -> V_5 ) & ~ V_2 -> V_4 -> V_5 ;
if ( F_2 ( V_3 > V_2 -> V_6 ) )
return - V_7 ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 = V_2 -> V_10 ;
if ( V_2 -> V_4 -> V_11 )
V_2 -> V_4 -> V_11 ( V_2 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
F_4 ( V_2 , V_2 -> V_4 -> V_14 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
while ( V_16 -> V_17 & V_2 -> V_4 -> V_5 )
V_16 -> V_18 [ V_16 -> V_17 ++ ] = V_2 -> V_4 -> V_14 ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_12 ;
V_12 = V_2 -> V_4 -> V_5 + 1 -
( V_2 -> V_10 & V_2 -> V_4 -> V_5 ) ;
V_12 %= V_2 -> V_4 -> V_5 + 1 ;
V_2 -> V_4 -> V_19 ( V_2 , V_12 ) ;
F_7 () ;
F_8 ( V_2 ) ;
if ( V_2 -> V_4 -> V_20 )
V_2 -> V_4 -> V_20 ( V_2 ) ;
F_9 ( V_2 -> V_21 , V_2 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_10 = V_2 -> V_9 ;
if ( V_2 -> V_4 -> V_20 )
V_2 -> V_4 -> V_20 ( V_2 ) ;
}
int F_11 ( struct V_22 * V_21 , struct V_1 * V_2 ,
unsigned V_6 , struct V_23 * V_24 ,
unsigned V_25 )
{
int V_26 ;
int V_27 = V_28 ;
if ( V_2 -> V_4 -> type == V_29 )
V_27 = F_12 ( V_27 , 256 ) ;
if ( V_2 -> V_21 == NULL ) {
if ( V_21 -> V_30 >= V_31 )
return - V_32 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_33 = V_21 -> V_30 ++ ;
V_21 -> V_34 [ V_2 -> V_33 ] = V_2 ;
V_26 = F_13 ( V_2 , V_27 ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_14 ( V_21 , & V_2 -> V_35 ) ;
if ( V_26 ) {
F_15 ( V_21 -> V_36 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_14 ( V_21 , & V_2 -> V_37 ) ;
if ( V_26 ) {
F_15 ( V_21 -> V_36 , L_2 , V_26 ) ;
return V_26 ;
}
V_26 = F_14 ( V_21 , & V_2 -> V_38 ) ;
if ( V_26 ) {
F_15 ( V_21 -> V_36 , L_3 , V_26 ) ;
return V_26 ;
}
V_26 = F_14 ( V_21 , & V_2 -> V_39 ) ;
if ( V_26 ) {
F_15 ( V_21 -> V_36 , L_4 , V_26 ) ;
return V_26 ;
}
V_2 -> V_40 = V_21 -> V_41 . V_42 + ( V_2 -> V_39 * 4 ) ;
V_2 -> V_43 = & V_21 -> V_41 . V_41 [ V_2 -> V_39 ] ;
* V_2 -> V_43 = 1 ;
V_26 = F_16 ( V_2 , V_24 , V_25 ) ;
if ( V_26 ) {
F_15 ( V_21 -> V_36 , L_5 , V_26 ) ;
return V_26 ;
}
V_2 -> V_44 = F_17 ( V_6 * 4 * V_27 ) ;
V_2 -> V_45 = ( V_2 -> V_44 / 4 ) - 1 ;
V_2 -> V_46 = V_2 -> V_4 -> V_47 ?
0xffffffffffffffff : V_2 -> V_45 ;
if ( V_2 -> V_48 == NULL ) {
V_26 = F_18 ( V_21 , V_2 -> V_44 , V_49 ,
V_50 ,
& V_2 -> V_48 ,
& V_2 -> V_42 ,
( void * * ) & V_2 -> V_2 ) ;
if ( V_26 ) {
F_15 ( V_21 -> V_36 , L_6 , V_26 ) ;
return V_26 ;
}
F_19 ( V_2 ) ;
}
V_2 -> V_6 = V_6 ;
F_20 ( & V_2 -> V_51 ) ;
F_9 ( V_21 , V_2 ) ;
if ( F_21 ( V_21 , V_2 ) ) {
F_22 ( L_7 ) ;
}
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_52 = false ;
if ( ! ( V_2 -> V_21 ) || ! ( V_2 -> V_21 -> V_34 [ V_2 -> V_33 ] ) )
return;
F_24 ( V_2 -> V_21 , V_2 -> V_35 ) ;
F_24 ( V_2 -> V_21 , V_2 -> V_37 ) ;
F_24 ( V_2 -> V_21 , V_2 -> V_39 ) ;
F_24 ( V_2 -> V_21 , V_2 -> V_38 ) ;
F_25 ( & V_2 -> V_48 ,
& V_2 -> V_42 ,
( void * * ) & V_2 -> V_2 ) ;
F_26 ( V_2 ) ;
V_2 -> V_21 -> V_34 [ V_2 -> V_33 ] = NULL ;
}
static void F_27 ( struct V_22 * V_21 ,
struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_51 , & V_21 -> V_53 ) ;
}
static bool F_29 ( struct V_1 * V_2 ,
int * V_54 , int V_55 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_55 ; V_13 ++ ) {
if ( V_2 -> V_33 == V_54 [ V_13 ] )
return true ;
}
return false ;
}
int F_30 ( struct V_22 * V_21 , int type , int * V_54 ,
int V_55 , struct V_1 * * V_2 )
{
struct V_1 * V_56 ;
* V_2 = NULL ;
F_31 ( & V_21 -> V_57 ) ;
F_32 (entry, &adev->ring_lru_list, lru_list) {
if ( V_56 -> V_4 -> type != type )
continue;
if ( F_29 ( V_56 , V_54 , V_55 ) )
continue;
* V_2 = V_56 ;
F_27 ( V_21 , * V_2 ) ;
break;
}
F_33 ( & V_21 -> V_57 ) ;
if ( ! * V_2 ) {
F_22 ( L_8 , type ) ;
return - V_32 ;
}
return 0 ;
}
void F_9 ( struct V_22 * V_21 , struct V_1 * V_2 )
{
F_31 ( & V_21 -> V_57 ) ;
F_27 ( V_21 , V_2 ) ;
F_33 ( & V_21 -> V_57 ) ;
}
static T_2 F_34 ( struct V_58 * V_59 , char T_3 * V_60 ,
T_4 V_61 , T_5 * V_62 )
{
struct V_1 * V_2 = F_35 ( V_59 ) -> V_63 ;
int V_26 , V_13 ;
T_1 V_64 , V_65 , V_66 [ 3 ] ;
if ( * V_62 & 3 || V_61 & 3 )
return - V_32 ;
V_65 = 0 ;
if ( * V_62 < 12 ) {
V_66 [ 0 ] = F_36 ( V_2 ) ;
V_66 [ 1 ] = F_37 ( V_2 ) & V_2 -> V_45 ;
V_66 [ 2 ] = V_2 -> V_10 & V_2 -> V_45 ;
for ( V_13 = * V_62 / 4 ; V_13 < 3 && V_61 ; V_13 ++ ) {
V_26 = F_38 ( V_66 [ V_13 ] , ( T_1 * ) V_60 ) ;
if ( V_26 )
return V_26 ;
V_60 += 4 ;
V_65 += 4 ;
V_61 -= 4 ;
* V_62 += 4 ;
}
}
while ( V_61 ) {
if ( * V_62 >= ( V_2 -> V_44 + 12 ) )
return V_65 ;
V_64 = V_2 -> V_2 [ ( * V_62 - 12 ) / 4 ] ;
V_26 = F_38 ( V_64 , ( T_1 * ) V_60 ) ;
if ( V_26 )
return V_26 ;
V_60 += 4 ;
V_65 += 4 ;
V_61 -= 4 ;
* V_62 += 4 ;
}
return V_65 ;
}
static int F_21 ( struct V_22 * V_21 ,
struct V_1 * V_2 )
{
#if F_39 ( V_67 )
struct V_68 * V_69 = V_21 -> V_70 -> V_71 ;
struct V_72 * V_73 , * V_74 = V_69 -> V_75 ;
char V_76 [ 32 ] ;
sprintf ( V_76 , L_9 , V_2 -> V_76 ) ;
V_73 = F_40 ( V_76 ,
V_77 | V_78 , V_74 ,
V_2 , & V_79 ) ;
if ( ! V_73 )
return - V_7 ;
F_41 ( V_73 -> V_80 , V_2 -> V_44 + 12 ) ;
V_2 -> V_73 = V_73 ;
#endif
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
#if F_39 ( V_67 )
F_42 ( V_2 -> V_73 ) ;
#endif
}

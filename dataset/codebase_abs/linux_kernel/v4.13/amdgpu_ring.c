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
if ( V_2 -> V_21 == NULL ) {
if ( V_21 -> V_27 >= V_28 )
return - V_29 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_30 = V_21 -> V_27 ++ ;
V_21 -> V_31 [ V_2 -> V_30 ] = V_2 ;
V_26 = F_12 ( V_2 ,
V_32 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_2 -> V_4 -> V_33 ) {
V_26 = F_13 ( V_21 , & V_2 -> V_34 ) ;
if ( V_26 ) {
F_14 ( V_21 -> V_35 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_13 ( V_21 , & V_2 -> V_36 ) ;
if ( V_26 ) {
F_14 ( V_21 -> V_35 , L_2 , V_26 ) ;
return V_26 ;
}
} else {
V_26 = F_15 ( V_21 , & V_2 -> V_34 ) ;
if ( V_26 ) {
F_14 ( V_21 -> V_35 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_15 ( V_21 , & V_2 -> V_36 ) ;
if ( V_26 ) {
F_14 ( V_21 -> V_35 , L_2 , V_26 ) ;
return V_26 ;
}
}
V_26 = F_15 ( V_21 , & V_2 -> V_37 ) ;
if ( V_26 ) {
F_14 ( V_21 -> V_35 , L_3 , V_26 ) ;
return V_26 ;
}
V_26 = F_15 ( V_21 , & V_2 -> V_38 ) ;
if ( V_26 ) {
F_14 ( V_21 -> V_35 , L_4 , V_26 ) ;
return V_26 ;
}
V_2 -> V_39 = V_21 -> V_40 . V_41 + ( V_2 -> V_38 * 4 ) ;
V_2 -> V_42 = & V_21 -> V_40 . V_40 [ V_2 -> V_38 ] ;
* V_2 -> V_42 = 1 ;
V_26 = F_16 ( V_2 , V_24 , V_25 ) ;
if ( V_26 ) {
F_14 ( V_21 -> V_35 , L_5 , V_26 ) ;
return V_26 ;
}
V_2 -> V_43 = F_17 ( V_6 * 4 *
V_32 ) ;
V_2 -> V_44 = ( V_2 -> V_43 / 4 ) - 1 ;
V_2 -> V_45 = V_2 -> V_4 -> V_33 ?
0xffffffffffffffff : V_2 -> V_44 ;
if ( V_2 -> V_46 == NULL ) {
V_26 = F_18 ( V_21 , V_2 -> V_43 , V_47 ,
V_48 ,
& V_2 -> V_46 ,
& V_2 -> V_41 ,
( void * * ) & V_2 -> V_2 ) ;
if ( V_26 ) {
F_14 ( V_21 -> V_35 , L_6 , V_26 ) ;
return V_26 ;
}
F_19 ( V_2 ) ;
}
V_2 -> V_6 = V_6 ;
F_20 ( & V_2 -> V_49 ) ;
F_9 ( V_21 , V_2 ) ;
if ( F_21 ( V_21 , V_2 ) ) {
F_22 ( L_7 ) ;
}
return 0 ;
}
void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_50 = false ;
if ( V_2 -> V_4 -> V_33 ) {
F_24 ( V_2 -> V_21 , V_2 -> V_38 ) ;
F_24 ( V_2 -> V_21 , V_2 -> V_37 ) ;
F_24 ( V_2 -> V_21 , V_2 -> V_34 ) ;
F_24 ( V_2 -> V_21 , V_2 -> V_36 ) ;
} else {
F_25 ( V_2 -> V_21 , V_2 -> V_38 ) ;
F_25 ( V_2 -> V_21 , V_2 -> V_37 ) ;
F_25 ( V_2 -> V_21 , V_2 -> V_34 ) ;
F_25 ( V_2 -> V_21 , V_2 -> V_36 ) ;
}
F_26 ( & V_2 -> V_46 ,
& V_2 -> V_41 ,
( void * * ) & V_2 -> V_2 ) ;
F_27 ( V_2 ) ;
V_2 -> V_21 -> V_31 [ V_2 -> V_30 ] = NULL ;
}
static void F_28 ( struct V_22 * V_21 ,
struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_49 , & V_21 -> V_51 ) ;
}
static bool F_30 ( struct V_1 * V_2 ,
int * V_52 , int V_53 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_53 ; V_13 ++ ) {
if ( V_2 -> V_30 == V_52 [ V_13 ] )
return true ;
}
return false ;
}
int F_31 ( struct V_22 * V_21 , int type , int * V_52 ,
int V_53 , struct V_1 * * V_2 )
{
struct V_1 * V_54 ;
* V_2 = NULL ;
F_32 ( & V_21 -> V_55 ) ;
F_33 (entry, &adev->ring_lru_list, lru_list) {
if ( V_54 -> V_4 -> type != type )
continue;
if ( F_30 ( V_54 , V_52 , V_53 ) )
continue;
* V_2 = V_54 ;
F_28 ( V_21 , * V_2 ) ;
break;
}
F_34 ( & V_21 -> V_55 ) ;
if ( ! * V_2 ) {
F_22 ( L_8 , type ) ;
return - V_29 ;
}
return 0 ;
}
void F_9 ( struct V_22 * V_21 , struct V_1 * V_2 )
{
F_32 ( & V_21 -> V_55 ) ;
F_28 ( V_21 , V_2 ) ;
F_34 ( & V_21 -> V_55 ) ;
}
static T_2 F_35 ( struct V_56 * V_57 , char T_3 * V_58 ,
T_4 V_59 , T_5 * V_60 )
{
struct V_1 * V_2 = F_36 ( V_57 ) -> V_61 ;
int V_26 , V_13 ;
T_1 V_62 , V_63 , V_64 [ 3 ] ;
if ( * V_60 & 3 || V_59 & 3 )
return - V_29 ;
V_63 = 0 ;
if ( * V_60 < 12 ) {
V_64 [ 0 ] = F_37 ( V_2 ) ;
V_64 [ 1 ] = F_38 ( V_2 ) & V_2 -> V_44 ;
V_64 [ 2 ] = V_2 -> V_10 & V_2 -> V_44 ;
for ( V_13 = * V_60 / 4 ; V_13 < 3 && V_59 ; V_13 ++ ) {
V_26 = F_39 ( V_64 [ V_13 ] , ( T_1 * ) V_58 ) ;
if ( V_26 )
return V_26 ;
V_58 += 4 ;
V_63 += 4 ;
V_59 -= 4 ;
* V_60 += 4 ;
}
}
while ( V_59 ) {
if ( * V_60 >= ( V_2 -> V_43 + 12 ) )
return V_63 ;
V_62 = V_2 -> V_2 [ ( * V_60 - 12 ) / 4 ] ;
V_26 = F_39 ( V_62 , ( T_1 * ) V_58 ) ;
if ( V_26 )
return V_26 ;
V_58 += 4 ;
V_63 += 4 ;
V_59 -= 4 ;
* V_60 += 4 ;
}
return V_63 ;
}
static int F_21 ( struct V_22 * V_21 ,
struct V_1 * V_2 )
{
#if F_40 ( V_65 )
struct V_66 * V_67 = V_21 -> V_68 -> V_69 ;
struct V_70 * V_71 , * V_72 = V_67 -> V_73 ;
char V_74 [ 32 ] ;
sprintf ( V_74 , L_9 , V_2 -> V_74 ) ;
V_71 = F_41 ( V_74 ,
V_75 | V_76 , V_72 ,
V_2 , & V_77 ) ;
if ( ! V_71 )
return - V_7 ;
F_42 ( V_71 -> V_78 , V_2 -> V_43 + 12 ) ;
V_2 -> V_71 = V_71 ;
#endif
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
#if F_40 ( V_65 )
F_43 ( V_2 -> V_71 ) ;
#endif
}

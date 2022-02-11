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
}
void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_10 = V_2 -> V_9 ;
if ( V_2 -> V_4 -> V_20 )
V_2 -> V_4 -> V_20 ( V_2 ) ;
}
int F_10 ( struct V_21 * V_22 , struct V_1 * V_2 ,
unsigned V_6 , struct V_23 * V_24 ,
unsigned V_25 )
{
int V_26 ;
if ( V_2 -> V_22 == NULL ) {
if ( V_22 -> V_27 >= V_28 )
return - V_29 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_30 = V_22 -> V_27 ++ ;
V_22 -> V_31 [ V_2 -> V_30 ] = V_2 ;
V_26 = F_11 ( V_2 ,
V_32 ) ;
if ( V_26 )
return V_26 ;
}
if ( V_2 -> V_4 -> V_33 ) {
V_26 = F_12 ( V_22 , & V_2 -> V_34 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_35 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_12 ( V_22 , & V_2 -> V_36 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_35 , L_2 , V_26 ) ;
return V_26 ;
}
} else {
V_26 = F_14 ( V_22 , & V_2 -> V_34 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_35 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_14 ( V_22 , & V_2 -> V_36 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_35 , L_2 , V_26 ) ;
return V_26 ;
}
}
V_26 = F_14 ( V_22 , & V_2 -> V_37 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_35 , L_3 , V_26 ) ;
return V_26 ;
}
V_26 = F_14 ( V_22 , & V_2 -> V_38 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_35 , L_4 , V_26 ) ;
return V_26 ;
}
V_2 -> V_39 = V_22 -> V_40 . V_41 + ( V_2 -> V_38 * 4 ) ;
V_2 -> V_42 = & V_22 -> V_40 . V_40 [ V_2 -> V_38 ] ;
* V_2 -> V_42 = 1 ;
V_26 = F_15 ( V_2 , V_24 , V_25 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_35 , L_5 , V_26 ) ;
return V_26 ;
}
V_2 -> V_43 = F_16 ( V_6 * 4 *
V_32 ) ;
V_2 -> V_44 = ( V_2 -> V_43 / 4 ) - 1 ;
V_2 -> V_45 = V_2 -> V_4 -> V_33 ?
0xffffffffffffffff : V_2 -> V_44 ;
if ( V_2 -> V_46 == NULL ) {
V_26 = F_17 ( V_22 , V_2 -> V_43 , V_47 ,
V_48 ,
& V_2 -> V_46 ,
& V_2 -> V_41 ,
( void * * ) & V_2 -> V_2 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_35 , L_6 , V_26 ) ;
return V_26 ;
}
F_18 ( V_2 ) ;
}
V_2 -> V_6 = V_6 ;
if ( F_19 ( V_22 , V_2 ) ) {
F_20 ( L_7 ) ;
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_49 = false ;
if ( V_2 -> V_4 -> V_33 ) {
F_22 ( V_2 -> V_22 , V_2 -> V_38 ) ;
F_22 ( V_2 -> V_22 , V_2 -> V_37 ) ;
F_22 ( V_2 -> V_22 , V_2 -> V_34 ) ;
F_22 ( V_2 -> V_22 , V_2 -> V_36 ) ;
} else {
F_23 ( V_2 -> V_22 , V_2 -> V_38 ) ;
F_23 ( V_2 -> V_22 , V_2 -> V_37 ) ;
F_23 ( V_2 -> V_22 , V_2 -> V_34 ) ;
F_23 ( V_2 -> V_22 , V_2 -> V_36 ) ;
}
F_24 ( & V_2 -> V_46 ,
& V_2 -> V_41 ,
( void * * ) & V_2 -> V_2 ) ;
F_25 ( V_2 ) ;
V_2 -> V_22 -> V_31 [ V_2 -> V_30 ] = NULL ;
}
static T_2 F_26 ( struct V_50 * V_51 , char T_3 * V_52 ,
T_4 V_53 , T_5 * V_54 )
{
struct V_1 * V_2 = F_27 ( V_51 ) -> V_55 ;
int V_26 , V_13 ;
T_1 V_56 , V_57 , V_58 [ 3 ] ;
if ( * V_54 & 3 || V_53 & 3 )
return - V_29 ;
V_57 = 0 ;
if ( * V_54 < 12 ) {
V_58 [ 0 ] = F_28 ( V_2 ) ;
V_58 [ 1 ] = F_29 ( V_2 ) & V_2 -> V_44 ;
V_58 [ 2 ] = V_2 -> V_10 & V_2 -> V_44 ;
for ( V_13 = * V_54 / 4 ; V_13 < 3 && V_53 ; V_13 ++ ) {
V_26 = F_30 ( V_58 [ V_13 ] , ( T_1 * ) V_52 ) ;
if ( V_26 )
return V_26 ;
V_52 += 4 ;
V_57 += 4 ;
V_53 -= 4 ;
* V_54 += 4 ;
}
}
while ( V_53 ) {
if ( * V_54 >= ( V_2 -> V_43 + 12 ) )
return V_57 ;
V_56 = V_2 -> V_2 [ ( * V_54 - 12 ) / 4 ] ;
V_26 = F_30 ( V_56 , ( T_1 * ) V_52 ) ;
if ( V_26 )
return V_26 ;
V_52 += 4 ;
V_57 += 4 ;
V_53 -= 4 ;
* V_54 += 4 ;
}
return V_57 ;
}
static int F_19 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
#if F_31 ( V_59 )
struct V_60 * V_61 = V_22 -> V_62 -> V_63 ;
struct V_64 * V_65 , * V_66 = V_61 -> V_67 ;
char V_68 [ 32 ] ;
sprintf ( V_68 , L_8 , V_2 -> V_68 ) ;
V_65 = F_32 ( V_68 ,
V_69 | V_70 , V_66 ,
V_2 , & V_71 ) ;
if ( ! V_65 )
return - V_7 ;
F_33 ( V_65 -> V_72 , V_2 -> V_43 + 12 ) ;
V_2 -> V_65 = V_65 ;
#endif
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
#if F_31 ( V_59 )
F_34 ( V_2 -> V_65 ) ;
#endif
}

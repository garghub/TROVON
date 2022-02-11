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
V_26 = F_12 ( V_22 , & V_2 -> V_33 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_34 , L_1 , V_26 ) ;
return V_26 ;
}
V_26 = F_12 ( V_22 , & V_2 -> V_35 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_34 , L_2 , V_26 ) ;
return V_26 ;
}
V_26 = F_12 ( V_22 , & V_2 -> V_36 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_34 , L_3 , V_26 ) ;
return V_26 ;
}
V_26 = F_12 ( V_22 , & V_2 -> V_37 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_34 , L_4 , V_26 ) ;
return V_26 ;
}
V_2 -> V_38 = V_22 -> V_39 . V_40 + ( V_2 -> V_37 * 4 ) ;
V_2 -> V_41 = & V_22 -> V_39 . V_39 [ V_2 -> V_37 ] ;
* V_2 -> V_41 = 1 ;
V_26 = F_14 ( V_2 , V_24 , V_25 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_34 , L_5 , V_26 ) ;
return V_26 ;
}
V_2 -> V_42 = F_15 ( V_6 * 4 *
V_32 ) ;
if ( V_2 -> V_43 == NULL ) {
V_26 = F_16 ( V_22 , V_2 -> V_42 , V_44 ,
V_45 ,
& V_2 -> V_43 ,
& V_2 -> V_40 ,
( void * * ) & V_2 -> V_2 ) ;
if ( V_26 ) {
F_13 ( V_22 -> V_34 , L_6 , V_26 ) ;
return V_26 ;
}
memset ( ( void * ) V_2 -> V_2 , 0 , V_2 -> V_42 ) ;
}
V_2 -> V_46 = ( V_2 -> V_42 / 4 ) - 1 ;
V_2 -> V_6 = V_6 ;
if ( F_17 ( V_22 , V_2 ) ) {
F_18 ( L_7 ) ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_47 = false ;
F_20 ( V_2 -> V_22 , V_2 -> V_37 ) ;
F_20 ( V_2 -> V_22 , V_2 -> V_36 ) ;
F_20 ( V_2 -> V_22 , V_2 -> V_33 ) ;
F_20 ( V_2 -> V_22 , V_2 -> V_35 ) ;
F_21 ( & V_2 -> V_43 ,
& V_2 -> V_40 ,
( void * * ) & V_2 -> V_2 ) ;
F_22 ( V_2 ) ;
V_2 -> V_22 -> V_31 [ V_2 -> V_30 ] = NULL ;
}
static T_2 F_23 ( struct V_48 * V_49 , char T_3 * V_50 ,
T_4 V_51 , T_5 * V_52 )
{
struct V_1 * V_2 = F_24 ( V_49 ) -> V_53 ;
int V_26 , V_13 ;
T_1 V_54 , V_55 , V_56 [ 3 ] ;
if ( * V_52 & 3 || V_51 & 3 )
return - V_29 ;
V_55 = 0 ;
if ( * V_52 < 12 ) {
V_56 [ 0 ] = F_25 ( V_2 ) ;
V_56 [ 1 ] = F_26 ( V_2 ) ;
V_56 [ 2 ] = V_2 -> V_10 ;
for ( V_13 = * V_52 / 4 ; V_13 < 3 && V_51 ; V_13 ++ ) {
V_26 = F_27 ( V_56 [ V_13 ] , ( T_1 * ) V_50 ) ;
if ( V_26 )
return V_26 ;
V_50 += 4 ;
V_55 += 4 ;
V_51 -= 4 ;
* V_52 += 4 ;
}
}
while ( V_51 ) {
if ( * V_52 >= ( V_2 -> V_42 + 12 ) )
return V_55 ;
V_54 = V_2 -> V_2 [ ( * V_52 - 12 ) / 4 ] ;
V_26 = F_27 ( V_54 , ( T_1 * ) V_50 ) ;
if ( V_26 )
return V_26 ;
V_50 += 4 ;
V_55 += 4 ;
V_51 -= 4 ;
* V_52 += 4 ;
}
return V_55 ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
#if F_28 ( V_57 )
struct V_58 * V_59 = V_22 -> V_60 -> V_61 ;
struct V_62 * V_63 , * V_64 = V_59 -> V_65 ;
char V_66 [ 32 ] ;
sprintf ( V_66 , L_8 , V_2 -> V_66 ) ;
V_63 = F_29 ( V_66 ,
V_67 | V_68 , V_64 ,
V_2 , & V_69 ) ;
if ( ! V_63 )
return - V_7 ;
F_30 ( V_63 -> V_70 , V_2 -> V_42 + 12 ) ;
V_2 -> V_63 = V_63 ;
#endif
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
#if F_28 ( V_57 )
F_31 ( V_2 -> V_63 ) ;
#endif
}

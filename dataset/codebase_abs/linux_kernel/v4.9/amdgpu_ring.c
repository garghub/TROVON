int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
V_3 = ( V_3 + V_2 -> V_4 ) & ~ V_2 -> V_4 ;
if ( F_2 ( V_3 > V_2 -> V_5 ) )
return - V_6 ;
V_2 -> V_7 = V_3 ;
V_2 -> V_8 = V_2 -> V_9 ;
if ( V_2 -> V_10 -> V_11 )
V_2 -> V_10 -> V_11 ( V_2 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
F_4 ( V_2 , V_2 -> V_14 ) ;
}
void F_5 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
while ( V_16 -> V_17 & V_2 -> V_4 )
V_16 -> V_18 [ V_16 -> V_17 ++ ] = V_2 -> V_14 ;
}
void F_6 ( struct V_1 * V_2 )
{
T_1 V_12 ;
V_12 = V_2 -> V_4 + 1 - ( V_2 -> V_9 & V_2 -> V_4 ) ;
V_12 %= V_2 -> V_4 + 1 ;
V_2 -> V_10 -> V_19 ( V_2 , V_12 ) ;
F_7 () ;
F_8 ( V_2 ) ;
if ( V_2 -> V_10 -> V_20 )
V_2 -> V_10 -> V_20 ( V_2 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_9 = V_2 -> V_8 ;
if ( V_2 -> V_10 -> V_20 )
V_2 -> V_10 -> V_20 ( V_2 ) ;
}
int F_10 ( struct V_21 * V_22 , struct V_1 * V_2 ,
unsigned V_5 , T_2 V_14 , T_2 V_4 ,
struct V_23 * V_24 , unsigned V_25 ,
enum V_26 V_27 )
{
int V_28 ;
if ( V_2 -> V_22 == NULL ) {
if ( V_22 -> V_29 >= V_30 )
return - V_31 ;
V_2 -> V_22 = V_22 ;
V_2 -> V_32 = V_22 -> V_29 ++ ;
V_22 -> V_33 [ V_2 -> V_32 ] = V_2 ;
V_28 = F_11 ( V_2 ,
V_34 ) ;
if ( V_28 )
return V_28 ;
}
V_28 = F_12 ( V_22 , & V_2 -> V_35 ) ;
if ( V_28 ) {
F_13 ( V_22 -> V_36 , L_1 , V_28 ) ;
return V_28 ;
}
V_28 = F_12 ( V_22 , & V_2 -> V_37 ) ;
if ( V_28 ) {
F_13 ( V_22 -> V_36 , L_2 , V_28 ) ;
return V_28 ;
}
V_28 = F_12 ( V_22 , & V_2 -> V_38 ) ;
if ( V_28 ) {
F_13 ( V_22 -> V_36 , L_3 , V_28 ) ;
return V_28 ;
}
V_28 = F_12 ( V_22 , & V_2 -> V_39 ) ;
if ( V_28 ) {
F_13 ( V_22 -> V_36 , L_4 , V_28 ) ;
return V_28 ;
}
V_2 -> V_40 = V_22 -> V_41 . V_42 + ( V_2 -> V_39 * 4 ) ;
V_2 -> V_43 = & V_22 -> V_41 . V_41 [ V_2 -> V_39 ] ;
V_28 = F_14 ( V_2 , V_24 , V_25 ) ;
if ( V_28 ) {
F_13 ( V_22 -> V_36 , L_5 , V_28 ) ;
return V_28 ;
}
V_2 -> V_44 = F_15 ( V_5 * 4 *
V_34 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_14 = V_14 ;
V_2 -> type = V_27 ;
if ( V_2 -> V_45 == NULL ) {
V_28 = F_16 ( V_22 , V_2 -> V_44 , V_46 ,
V_47 ,
& V_2 -> V_45 ,
& V_2 -> V_42 ,
( void * * ) & V_2 -> V_2 ) ;
if ( V_28 ) {
F_13 ( V_22 -> V_36 , L_6 , V_28 ) ;
return V_28 ;
}
memset ( ( void * ) V_2 -> V_2 , 0 , V_2 -> V_44 ) ;
}
V_2 -> V_48 = ( V_2 -> V_44 / 4 ) - 1 ;
V_2 -> V_5 = V_5 ;
if ( F_17 ( V_22 , V_2 ) ) {
F_18 ( L_7 ) ;
}
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
V_2 -> V_49 = false ;
F_20 ( V_2 -> V_22 , V_2 -> V_39 ) ;
F_20 ( V_2 -> V_22 , V_2 -> V_38 ) ;
F_20 ( V_2 -> V_22 , V_2 -> V_35 ) ;
F_20 ( V_2 -> V_22 , V_2 -> V_37 ) ;
F_21 ( & V_2 -> V_45 ,
& V_2 -> V_42 ,
( void * * ) & V_2 -> V_2 ) ;
F_22 ( V_2 ) ;
V_2 -> V_22 -> V_33 [ V_2 -> V_32 ] = NULL ;
}
static T_3 F_23 ( struct V_50 * V_51 , char T_4 * V_52 ,
T_5 V_53 , T_6 * V_54 )
{
struct V_1 * V_2 = (struct V_1 * ) V_51 -> V_55 -> V_56 ;
int V_28 , V_13 ;
T_1 V_57 , V_58 , V_59 [ 3 ] ;
if ( * V_54 & 3 || V_53 & 3 )
return - V_31 ;
V_58 = 0 ;
if ( * V_54 < 12 ) {
V_59 [ 0 ] = F_24 ( V_2 ) ;
V_59 [ 1 ] = F_25 ( V_2 ) ;
V_59 [ 2 ] = V_2 -> V_9 ;
for ( V_13 = * V_54 / 4 ; V_13 < 3 && V_53 ; V_13 ++ ) {
V_28 = F_26 ( V_59 [ V_13 ] , ( T_1 * ) V_52 ) ;
if ( V_28 )
return V_28 ;
V_52 += 4 ;
V_58 += 4 ;
V_53 -= 4 ;
* V_54 += 4 ;
}
}
while ( V_53 ) {
if ( * V_54 >= ( V_2 -> V_44 + 12 ) )
return V_58 ;
V_57 = V_2 -> V_2 [ ( * V_54 - 12 ) / 4 ] ;
V_28 = F_26 ( V_57 , ( T_1 * ) V_52 ) ;
if ( V_28 )
return V_28 ;
V_52 += 4 ;
V_58 += 4 ;
V_53 -= 4 ;
* V_54 += 4 ;
}
return V_58 ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
#if F_27 ( V_60 )
struct V_61 * V_62 = V_22 -> V_63 -> V_64 ;
struct V_65 * V_66 , * V_67 = V_62 -> V_68 ;
char V_69 [ 32 ] ;
sprintf ( V_69 , L_8 , V_2 -> V_69 ) ;
V_66 = F_28 ( V_69 ,
V_70 | V_71 , V_67 ,
V_2 , & V_72 ) ;
if ( ! V_66 )
return - V_6 ;
F_29 ( V_66 -> V_73 , V_2 -> V_44 + 12 ) ;
V_2 -> V_66 = V_66 ;
#endif
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
#if F_27 ( V_60 )
F_30 ( V_2 -> V_66 ) ;
#endif
}

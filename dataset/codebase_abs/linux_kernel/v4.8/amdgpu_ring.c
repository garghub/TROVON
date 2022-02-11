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
V_28 = F_16 ( V_22 , V_2 -> V_44 , V_46 , true ,
V_47 , 0 ,
NULL , NULL , & V_2 -> V_45 ) ;
if ( V_28 ) {
F_13 ( V_22 -> V_36 , L_6 , V_28 ) ;
return V_28 ;
}
V_28 = F_17 ( V_2 -> V_45 , false ) ;
if ( F_18 ( V_28 != 0 ) )
return V_28 ;
V_28 = F_19 ( V_2 -> V_45 , V_47 ,
& V_2 -> V_42 ) ;
if ( V_28 ) {
F_20 ( V_2 -> V_45 ) ;
F_13 ( V_22 -> V_36 , L_7 , V_28 ) ;
return V_28 ;
}
V_28 = F_21 ( V_2 -> V_45 ,
( void * * ) & V_2 -> V_2 ) ;
memset ( ( void * ) V_2 -> V_2 , 0 , V_2 -> V_44 ) ;
F_20 ( V_2 -> V_45 ) ;
if ( V_28 ) {
F_13 ( V_22 -> V_36 , L_8 , V_28 ) ;
return V_28 ;
}
}
V_2 -> V_48 = ( V_2 -> V_44 / 4 ) - 1 ;
V_2 -> V_5 = V_5 ;
if ( F_22 ( V_22 , V_2 ) ) {
F_23 ( L_9 ) ;
}
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_49 * V_45 ;
V_45 = V_2 -> V_45 ;
V_2 -> V_50 = false ;
V_2 -> V_2 = NULL ;
V_2 -> V_45 = NULL ;
F_25 ( V_2 -> V_22 , V_2 -> V_39 ) ;
F_25 ( V_2 -> V_22 , V_2 -> V_38 ) ;
F_25 ( V_2 -> V_22 , V_2 -> V_35 ) ;
F_25 ( V_2 -> V_22 , V_2 -> V_37 ) ;
if ( V_45 ) {
V_28 = F_17 ( V_45 , false ) ;
if ( F_26 ( V_28 == 0 ) ) {
F_27 ( V_45 ) ;
F_28 ( V_45 ) ;
F_20 ( V_45 ) ;
}
F_29 ( & V_45 ) ;
}
F_30 ( V_2 ) ;
}
static T_3 F_31 ( struct V_51 * V_52 , char T_4 * V_53 ,
T_5 V_54 , T_6 * V_55 )
{
struct V_1 * V_2 = (struct V_1 * ) V_52 -> V_56 -> V_57 ;
int V_28 , V_13 ;
T_1 V_58 , V_59 , V_60 [ 3 ] ;
if ( * V_55 & 3 || V_54 & 3 )
return - V_31 ;
V_59 = 0 ;
if ( * V_55 < 12 ) {
V_60 [ 0 ] = F_32 ( V_2 ) ;
V_60 [ 1 ] = F_33 ( V_2 ) ;
V_60 [ 2 ] = V_2 -> V_9 ;
for ( V_13 = * V_55 / 4 ; V_13 < 3 && V_54 ; V_13 ++ ) {
V_28 = F_34 ( V_60 [ V_13 ] , ( T_1 * ) V_53 ) ;
if ( V_28 )
return V_28 ;
V_53 += 4 ;
V_59 += 4 ;
V_54 -= 4 ;
* V_55 += 4 ;
}
}
while ( V_54 ) {
if ( * V_55 >= ( V_2 -> V_44 + 12 ) )
return V_59 ;
V_58 = V_2 -> V_2 [ ( * V_55 - 12 ) / 4 ] ;
V_28 = F_34 ( V_58 , ( T_1 * ) V_53 ) ;
if ( V_28 )
return V_28 ;
V_53 += 4 ;
V_59 += 4 ;
V_54 -= 4 ;
* V_55 += 4 ;
}
return V_59 ;
}
static int F_22 ( struct V_21 * V_22 ,
struct V_1 * V_2 )
{
#if F_35 ( V_61 )
struct V_62 * V_63 = V_22 -> V_64 -> V_65 ;
struct V_66 * V_67 , * V_68 = V_63 -> V_69 ;
char V_70 [ 32 ] ;
sprintf ( V_70 , L_10 , V_2 -> V_70 ) ;
V_67 = F_36 ( V_70 ,
V_71 | V_72 , V_68 ,
V_2 , & V_73 ) ;
if ( F_37 ( V_67 ) )
return F_38 ( V_67 ) ;
F_39 ( V_67 -> V_74 , V_2 -> V_44 + 12 ) ;
V_2 -> V_67 = V_67 ;
#endif
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
#if F_35 ( V_61 )
F_40 ( V_2 -> V_67 ) ;
#endif
}

static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 , struct V_5 * V_6 )
{
struct V_7 * V_8 ;
struct V_9 * V_10 ;
unsigned long V_11 ;
unsigned int V_12 , V_13 ;
int V_14 , V_15 = - V_16 ;
V_6 -> V_17 = 0 ;
V_6 -> V_18 = & V_6 -> V_19 [ 0 ] ;
V_11 = F_2 ( V_2 , V_3 , 0 ) ;
if ( ! V_11 ) {
F_3 ( V_2 , L_1 , V_3 ) ;
goto V_20;
}
V_6 -> V_18 [ 0 ] = F_4 ( V_2 , V_11 ) ;
if ( ! V_6 -> V_18 [ 0 ] )
goto V_20;
V_6 -> V_17 += 1 ;
V_8 = (struct V_7 * ) V_6 -> V_18 [ 0 ] -> V_21 ;
V_13 = F_5 ( V_8 -> V_22 ) ;
if ( V_13 != V_4 ) {
F_6 ( V_23 L_2
L_3
L_4 ,
V_13 , V_4 ) ;
}
if ( V_8 -> V_24 [ 0 ] != 0 || V_8 -> V_24 [ 1 ] != 0 ||
V_8 -> V_24 [ 2 ] != 0 || V_13 & 2047 ||
V_8 -> V_25 != F_7 ( V_26 ) ) {
F_6 ( V_23 L_5
L_6 , V_3 ) ;
goto V_20;
}
V_13 >>= V_2 -> V_27 ;
if ( V_13 > F_8 ( V_6 -> V_19 ) ) {
struct V_28 * * V_18 =
F_9 ( V_13 , sizeof( struct V_28 * ) ,
V_29 ) ;
if ( ! V_18 ) {
V_15 = - V_30 ;
F_3 ( V_2 , L_7
L_8 , V_3 , V_13 ) ;
goto V_20;
}
V_6 -> V_18 = V_18 ;
V_6 -> V_18 [ 0 ] = V_6 -> V_19 [ 0 ] ;
}
for ( V_12 = 1 ; V_12 < V_13 ; V_12 ++ ) {
V_11 = F_2 ( V_2 , V_3 , V_12 ) ;
if ( ! V_11 ) {
F_3 ( V_2 , L_9 , V_3 , V_12 ) ;
goto V_20;
}
V_6 -> V_18 [ V_12 ] = F_4 ( V_2 , V_11 ) ;
if ( ! V_6 -> V_18 [ V_12 ] ) {
F_3 ( V_2 , L_10 ,
V_3 , V_12 , V_11 ) ;
goto V_20;
}
V_6 -> V_17 += 1 ;
}
V_10 = (struct V_9 * )
( V_6 -> V_18 [ V_13 - 1 ] -> V_21 + ( V_2 -> V_31 - 8 ) ) ;
if ( V_10 -> V_32 != F_7 ( V_33 ) ||
V_10 -> V_34 != V_8 -> V_35 ||
V_10 -> V_36 [ 0 ] != 0 || V_10 -> V_36 [ 1 ] != 0 ) {
F_6 ( V_23 L_11
L_12 , V_3 ) ;
goto V_20;
}
V_6 -> V_37 = F_5 ( V_8 -> V_38 ) ;
V_6 -> V_2 = V_2 ;
return 0 ;
V_20:
if ( V_6 -> V_18 ) {
for ( V_14 = 0 ; V_14 < V_6 -> V_17 ; V_14 ++ )
F_10 ( V_6 -> V_18 [ V_14 ] ) ;
if ( & V_6 -> V_19 [ 0 ] != V_6 -> V_18 )
F_11 ( V_6 -> V_18 ) ;
V_6 -> V_18 = NULL ;
}
V_6 -> V_17 = 0 ;
V_6 -> V_2 = NULL ;
return V_15 ;
}
static int
F_12 ( struct V_5 * V_6 , unsigned int V_39 )
{
struct V_7 * V_8 =
(struct V_7 * ) V_6 -> V_18 [ 0 ] -> V_21 ;
int V_15 = - V_40 ;
if ( V_39 <= F_5 ( V_8 -> V_41 ) ) {
V_6 -> V_42 = V_39 ;
V_15 = 0 ;
}
return V_15 ;
}
static void
F_13 ( struct V_5 * V_6 , unsigned int V_43 , void * V_44 , int V_45 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned int V_46 , V_47 , V_48 ;
V_46 = V_43 >> V_2 -> V_27 ;
V_43 &= V_2 -> V_31 - 1 ;
V_47 = V_2 -> V_31 - V_43 ;
if ( V_47 >= V_45 )
memcpy ( V_44 , V_6 -> V_18 [ V_46 ] -> V_21 + V_43 , V_45 ) ;
else {
char * V_49 = ( char * ) V_44 ;
V_48 = V_45 - V_47 ;
memcpy ( V_49 ,
V_6 -> V_18 [ V_46 ] -> V_21 + V_43 ,
V_47 ) ;
memcpy ( V_49 + V_47 ,
V_6 -> V_18 [ V_46 + 1 ] -> V_21 ,
V_48 ) ;
}
}
static int
F_14 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
struct V_7 * V_8 =
(struct V_7 * ) V_6 -> V_18 [ 0 ] -> V_21 ;
struct V_52 V_53 ;
unsigned int V_43 ;
int V_14 , V_15 = - V_40 ;
if ( V_6 -> V_42 >= F_5 ( V_8 -> V_41 ) )
goto V_20;
V_43 = F_15 ( struct V_7 , V_54 ) ;
V_43 += ( ( F_5 ( V_8 -> V_55 ) + 4 ) & ~ 3 ) ;
V_43 += V_6 -> V_42 * sizeof( struct V_52 ) ;
F_13 ( V_6 , V_43 , & V_53 , sizeof( struct V_52 ) ) ;
V_51 -> V_56 = F_5 ( V_53 . V_57 ) ;
V_51 -> V_58 = F_5 ( V_53 . V_59 ) ;
V_51 -> V_13 = F_5 ( V_53 . V_60 ) ;
V_51 -> V_61 = F_5 ( V_53 . V_62 ) ;
V_51 -> V_63 = F_5 ( V_53 . V_64 ) ;
V_51 -> V_65 = F_5 ( V_53 . V_66 ) ;
V_43 = F_15 ( struct V_7 , V_54 ) ;
V_43 += ( ( F_5 ( V_8 -> V_55 ) + 4 ) & ~ 3 ) ;
V_43 += F_5 ( V_8 -> V_41 ) * sizeof( struct V_52 ) ;
V_43 += F_5 ( V_53 . V_67 ) ;
F_13 ( V_6 , V_43 , V_51 -> V_68 , V_51 -> V_65 ) ;
for ( V_14 = 0 ; V_14 < V_51 -> V_65 ; V_14 ++ )
if ( V_51 -> V_68 [ V_14 ] == '/' )
V_51 -> V_68 [ V_14 ] = '.' ;
V_51 -> V_69 = - 1 ;
if ( ( 0 == ( V_51 -> V_63 & V_70 ) ) &&
( 0xfff00000 == ( 0xfff00000 & V_51 -> V_56 ) ) ) {
V_51 -> V_69 = ( V_71 ) ( ( 0x000fff00 & V_51 -> V_56 ) >> 8 ) ;
if ( F_16 ( V_6 -> V_2 ) -> V_72 )
V_51 -> V_65 +=
F_17 (
& V_51 -> V_68 [ V_51 -> V_65 ] ,
V_51 -> V_69 ) ;
}
V_6 -> V_42 += 1 ;
V_15 = 0 ;
V_20:
return V_15 ;
}
static int
F_18 ( struct V_5 * V_6 )
{
int V_73 = 0 ;
int V_14 ;
for ( V_14 = V_6 -> V_17 - 1 ; V_14 >= 0 ; V_14 -- ) {
struct V_28 * V_19 = V_6 -> V_18 [ V_14 ] ;
F_19 ( V_19 ) ;
if ( F_20 ( V_19 ) && ! F_21 ( V_19 ) )
V_73 = - V_16 ;
}
return V_73 ;
}
static void
F_22 ( struct V_5 * V_6 )
{
int V_14 ;
if ( V_6 -> V_18 ) {
for ( V_14 = 0 ; V_14 < V_6 -> V_17 ; V_14 ++ )
F_10 ( V_6 -> V_18 [ V_14 ] ) ;
if ( & V_6 -> V_19 [ 0 ] != V_6 -> V_18 )
F_11 ( V_6 -> V_18 ) ;
V_6 -> V_18 = NULL ;
}
V_6 -> V_17 = 0 ;
V_6 -> V_2 = NULL ;
}

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
if ( V_13 > sizeof( V_6 -> V_19 ) / sizeof( V_6 -> V_19 [ 0 ] ) ) {
struct V_28 * * V_18 =
F_8 ( V_13 * sizeof( struct V_28 * ) ,
V_29 ) ;
if ( ! V_18 ) {
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
F_3 ( V_2 , L_10
L_11 ,
V_3 , V_12 , V_11 ) ;
goto V_20;
}
V_6 -> V_17 += 1 ;
}
V_10 = (struct V_9 * )
( V_6 -> V_18 [ V_13 - 1 ] -> V_21 + ( V_2 -> V_30 - 8 ) ) ;
if ( V_10 -> V_31 != F_7 ( V_32 ) ||
V_10 -> V_33 != V_8 -> V_34 ||
V_10 -> V_35 [ 0 ] != 0 || V_10 -> V_35 [ 1 ] != 0 ) {
F_6 ( V_23 L_12
L_13 , V_3 ) ;
goto V_20;
}
V_6 -> V_36 = F_5 ( V_8 -> V_37 ) ;
V_6 -> V_2 = V_2 ;
return 0 ;
V_20:
if ( V_6 -> V_18 ) {
for ( V_14 = 0 ; V_14 < V_6 -> V_17 ; V_14 ++ )
F_9 ( V_6 -> V_18 [ V_14 ] ) ;
if ( & V_6 -> V_19 [ 0 ] != V_6 -> V_18 )
F_10 ( V_6 -> V_18 ) ;
V_6 -> V_18 = NULL ;
}
V_6 -> V_17 = 0 ;
V_6 -> V_2 = NULL ;
return V_15 ;
}
static int
F_11 ( struct V_5 * V_6 , unsigned int V_38 )
{
struct V_7 * V_8 =
(struct V_7 * ) V_6 -> V_18 [ 0 ] -> V_21 ;
int V_15 = - V_39 ;
if ( V_38 <= F_5 ( V_8 -> V_40 ) ) {
V_6 -> V_41 = V_38 ;
V_15 = 0 ;
}
return V_15 ;
}
static void
F_12 ( struct V_5 * V_6 , unsigned int V_42 , void * V_43 , int V_44 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned int V_45 , V_46 , V_47 ;
V_45 = V_42 >> V_2 -> V_27 ;
V_42 &= V_2 -> V_30 - 1 ;
V_46 = V_2 -> V_30 - V_42 ;
if ( V_46 >= V_44 )
memcpy ( V_43 , V_6 -> V_18 [ V_45 ] -> V_21 + V_42 , V_44 ) ;
else {
char * V_48 = ( char * ) V_43 ;
V_47 = V_44 - V_46 ;
memcpy ( V_48 ,
V_6 -> V_18 [ V_45 ] -> V_21 + V_42 ,
V_46 ) ;
memcpy ( V_48 + V_46 ,
V_6 -> V_18 [ V_45 + 1 ] -> V_21 ,
V_47 ) ;
}
}
static int
F_13 ( struct V_5 * V_6 , struct V_49 * V_50 )
{
struct V_7 * V_8 =
(struct V_7 * ) V_6 -> V_18 [ 0 ] -> V_21 ;
struct V_51 V_52 ;
unsigned int V_42 ;
int V_14 , V_15 = - V_39 ;
if ( V_6 -> V_41 >= F_5 ( V_8 -> V_40 ) )
goto V_20;
V_42 = F_14 ( struct V_7 , V_53 ) ;
V_42 += ( ( F_5 ( V_8 -> V_54 ) + 4 ) & ~ 3 ) ;
V_42 += V_6 -> V_41 * sizeof( struct V_51 ) ;
F_12 ( V_6 , V_42 , & V_52 , sizeof( struct V_51 ) ) ;
V_50 -> V_55 = F_5 ( V_52 . V_56 ) ;
V_50 -> V_57 = F_5 ( V_52 . V_58 ) ;
V_50 -> V_13 = F_5 ( V_52 . V_59 ) ;
V_50 -> V_60 = F_5 ( V_52 . V_61 ) ;
V_50 -> V_62 = F_5 ( V_52 . V_63 ) ;
V_50 -> V_64 = F_5 ( V_52 . V_65 ) ;
V_42 = F_14 ( struct V_7 , V_53 ) ;
V_42 += ( ( F_5 ( V_8 -> V_54 ) + 4 ) & ~ 3 ) ;
V_42 += F_5 ( V_8 -> V_40 ) * sizeof( struct V_51 ) ;
V_42 += F_5 ( V_52 . V_66 ) ;
F_12 ( V_6 , V_42 , V_50 -> V_67 , V_50 -> V_64 ) ;
for ( V_14 = 0 ; V_14 < V_50 -> V_64 ; V_14 ++ )
if ( V_50 -> V_67 [ V_14 ] == '/' )
V_50 -> V_67 [ V_14 ] = '.' ;
V_50 -> V_68 = - 1 ;
if ( ( 0 == ( V_50 -> V_62 & V_69 ) ) &&
( 0xfff00000 == ( 0xfff00000 & V_50 -> V_55 ) ) ) {
V_50 -> V_68 = ( V_70 ) ( ( 0x000fff00 & V_50 -> V_55 ) >> 8 ) ;
if ( F_15 ( V_6 -> V_2 ) -> V_71 )
V_50 -> V_64 +=
F_16 (
& V_50 -> V_67 [ V_50 -> V_64 ] ,
V_50 -> V_68 ) ;
}
V_6 -> V_41 += 1 ;
V_15 = 0 ;
V_20:
return V_15 ;
}
static int
F_17 ( struct V_5 * V_6 )
{
int V_72 = 0 ;
int V_14 ;
for ( V_14 = V_6 -> V_17 - 1 ; V_14 >= 0 ; V_14 -- ) {
struct V_28 * V_19 = V_6 -> V_18 [ V_14 ] ;
F_18 ( V_19 ) ;
if ( F_19 ( V_19 ) && ! F_20 ( V_19 ) )
V_72 = - V_16 ;
}
return V_72 ;
}
static void
F_21 ( struct V_5 * V_6 )
{
int V_14 ;
if ( V_6 -> V_18 ) {
for ( V_14 = 0 ; V_14 < V_6 -> V_17 ; V_14 ++ )
F_9 ( V_6 -> V_18 [ V_14 ] ) ;
if ( & V_6 -> V_19 [ 0 ] != V_6 -> V_18 )
F_10 ( V_6 -> V_18 ) ;
V_6 -> V_18 = NULL ;
}
V_6 -> V_17 = 0 ;
V_6 -> V_2 = NULL ;
}

static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
char * V_8 = NULL ;
struct V_9 * V_10 = & V_2 -> V_10 [ V_4 ] ;
unsigned long V_11 = V_10 -> V_12 ;
if ( V_11 > V_13 )
V_8 = ( void * ) F_2 ( V_14 ,
F_3 ( F_4 ( V_11 ) ) - V_15 ) ;
else
V_8 = F_5 ( V_11 , V_14 ) ;
if ( V_8 == NULL ) {
F_6 ( L_1 ,
V_10 -> V_16 , ( int ) V_11 ) ;
return - V_17 ;
}
if ( V_4 == V_18 ) {
struct V_19 * V_20 = (struct V_19 * ) V_10 -> V_21 ;
struct V_19 * V_22 ;
int V_23 ;
char * V_24 , * V_25 ;
V_24 = V_8 ;
F_7 (sgl, sg, data->size, i) {
V_25 = F_8 ( F_9 ( V_22 ) ) ;
memcpy ( V_24 ,
V_25 + V_22 -> V_26 ,
V_22 -> V_27 ) ;
F_10 ( V_25 ) ;
V_24 += V_22 -> V_27 ;
}
}
F_11 ( & V_2 -> V_28 [ V_4 ] . V_29 , V_8 , V_11 ) ;
V_2 -> V_28 [ V_4 ] . V_21 =
& V_2 -> V_28 [ V_4 ] . V_29 ;
V_2 -> V_28 [ V_4 ] . V_16 = 1 ;
V_2 -> V_28 [ V_4 ] . V_30 = V_8 ;
V_7 = V_2 -> V_31 -> V_32 -> V_33 -> V_6 ;
V_5 = F_12 ( V_7 ,
& V_2 -> V_28 [ V_4 ] . V_29 ,
1 ,
( V_4 == V_18 ) ?
V_34 : V_35 ) ;
F_13 ( V_5 == 0 ) ;
V_2 -> V_28 [ V_4 ] . V_5 = V_5 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_6 * V_7 ;
struct V_9 * V_36 ;
unsigned long V_11 ;
V_7 = V_2 -> V_31 -> V_32 -> V_33 -> V_6 ;
V_36 = & V_2 -> V_28 [ V_4 ] ;
F_15 ( V_7 , & V_36 -> V_29 , 1 ,
( V_4 == V_18 ) ?
V_34 : V_35 ) ;
if ( V_4 == V_37 ) {
char * V_8 ;
struct V_19 * V_20 , * V_22 ;
unsigned char * V_24 , * V_38 ;
unsigned int V_39 ;
int V_23 ;
V_8 = V_36 -> V_30 ;
V_20 = (struct V_19 * ) V_2 -> V_10 [ V_37 ] . V_21 ;
V_39 = V_2 -> V_10 [ V_37 ] . V_16 ;
V_24 = V_8 ;
F_7 (sgl, sg, sg_size, i) {
V_38 = F_8 ( F_9 ( V_22 ) ) ;
memcpy ( V_38 + V_22 -> V_26 ,
V_24 ,
V_22 -> V_27 ) ;
F_10 ( V_38 ) ;
V_24 += V_22 -> V_27 ;
}
}
V_11 = V_2 -> V_10 [ V_4 ] . V_12 ;
if ( V_11 > V_13 )
F_16 ( ( unsigned long ) V_36 -> V_30 ,
F_3 ( F_4 ( V_11 ) ) - V_15 ) ;
else
F_17 ( V_36 -> V_30 ) ;
V_36 -> V_30 = NULL ;
}
static int F_18 ( struct V_9 * V_10 ,
struct V_40 * V_41 ,
struct V_6 * V_42 )
{
struct V_19 * V_22 , * V_20 = (struct V_19 * ) V_10 -> V_21 ;
T_1 V_43 , V_44 , V_45 , V_46 = 0 ;
unsigned long V_47 = 0 ;
unsigned int V_48 ;
int V_23 , V_49 , V_50 , V_51 = V_10 -> V_5 - 1 ;
V_41 -> V_26 = ( T_1 ) V_20 [ 0 ] . V_26 & ~ V_52 ;
V_49 = 1 ;
V_50 = 0 ;
F_7 (sgl, sg, data->dma_nents, i) {
V_43 = F_19 ( V_42 , V_22 ) ;
if ( V_49 )
V_46 = V_43 ;
V_48 = F_20 ( V_42 , V_22 ) ;
V_44 = V_43 + V_48 ;
V_47 += V_48 ;
if ( ! F_21 ( V_44 ) && V_23 < V_51 ) {
V_49 = 0 ;
continue;
}
V_49 = 1 ;
V_45 = V_46 & V_52 ;
do {
V_41 -> V_53 [ V_50 ++ ] = V_45 ;
V_45 += V_54 ;
} while ( V_45 < V_44 );
}
V_41 -> V_55 = V_47 ;
F_22 ( L_2 , V_41 -> V_55 , V_50 ) ;
return V_50 ;
}
static int F_23 ( struct V_9 * V_10 ,
struct V_6 * V_42 )
{
struct V_19 * V_20 , * V_22 , * V_56 = NULL ;
T_1 V_43 , V_44 ;
int V_23 , V_57 , V_58 = 0 ;
if ( V_10 -> V_5 == 1 )
return 1 ;
V_20 = (struct V_19 * ) V_10 -> V_21 ;
V_43 = F_19 ( V_42 , V_20 ) ;
F_7 (sgl, sg, data->dma_nents, i) {
if ( V_58 && ! F_21 ( V_43 ) )
break;
V_56 = F_24 ( V_22 ) ;
if ( ! V_56 )
break;
V_44 = V_43 + F_20 ( V_42 , V_22 ) ;
V_43 = F_19 ( V_42 , V_56 ) ;
if ( V_44 == V_43 ) {
V_58 = 0 ;
continue;
} else
V_58 = 1 ;
if ( ! F_21 ( V_44 ) )
break;
}
V_57 = ( V_56 ) ? V_23 : V_23 + 1 ;
F_22 ( L_3 ,
V_57 , V_10 -> V_5 , V_10 ) ;
return V_57 ;
}
static void F_25 ( struct V_9 * V_10 ,
struct V_6 * V_42 )
{
struct V_19 * V_20 = (struct V_19 * ) V_10 -> V_21 ;
struct V_19 * V_22 ;
int V_23 ;
if ( V_59 == 0 )
return;
F_7 (sgl, sg, data->dma_nents, i)
F_26 ( L_4
L_5 ,
V_23 , ( unsigned long ) F_19 ( V_42 , V_22 ) ,
F_9 ( V_22 ) , V_22 -> V_26 ,
V_22 -> V_27 , F_20 ( V_42 , V_22 ) ) ;
}
static void F_27 ( struct V_40 * V_41 )
{
int V_23 ;
F_6 ( L_6 ,
V_41 -> V_27 , V_41 -> V_55 ) ;
for ( V_23 = 0 ; V_23 < V_41 -> V_27 ; V_23 ++ )
F_6 ( L_7 , V_23 , ( unsigned long ) V_41 -> V_53 [ V_23 ] ) ;
}
static void F_28 ( struct V_9 * V_10 ,
struct V_40 * V_41 ,
struct V_6 * V_42 )
{
int V_60 = 0 ;
V_41 -> V_27 = 0 ;
V_41 -> V_26 = 0 ;
F_22 ( L_8 , V_10 -> V_5 ) ;
V_60 = F_18 ( V_10 , V_41 , V_42 ) ;
F_22 ( L_9 , V_10 -> V_5 , V_60 ) ;
V_41 -> V_27 = V_60 ;
if ( V_60 * V_54 < V_41 -> V_55 ) {
F_6 ( L_10 ) ;
F_25 ( V_10 , V_42 ) ;
F_27 ( V_41 ) ;
F_29 () ;
}
}
int F_30 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
enum V_3 V_61 ,
enum V_62 V_63 )
{
struct V_6 * V_7 ;
V_2 -> V_64 [ V_61 ] = 1 ;
V_7 = V_2 -> V_31 -> V_32 -> V_33 -> V_6 ;
V_10 -> V_5 = F_12 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_63 ) ;
if ( V_10 -> V_5 == 0 ) {
F_6 ( L_11 ) ;
return - V_65 ;
}
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
V_7 = V_2 -> V_31 -> V_32 -> V_33 -> V_6 ;
if ( V_2 -> V_64 [ V_37 ] ) {
V_10 = & V_2 -> V_10 [ V_37 ] ;
F_15 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_35 ) ;
}
if ( V_2 -> V_64 [ V_18 ] ) {
V_10 = & V_2 -> V_10 [ V_18 ] ;
F_15 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_34 ) ;
}
}
int F_32 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_66 * V_66 = V_2 -> V_31 -> V_66 ;
struct V_31 * V_32 = V_2 -> V_31 -> V_32 ;
struct V_67 * V_33 = V_32 -> V_33 ;
struct V_6 * V_42 = V_33 -> V_6 ;
struct V_9 * V_8 = & V_2 -> V_10 [ V_4 ] ;
struct V_68 * V_69 ;
int V_70 ;
int V_71 ;
int V_23 ;
struct V_19 * V_22 ;
V_69 = & V_2 -> V_72 [ V_4 ] ;
V_70 = F_23 ( V_8 , V_42 ) ;
if ( V_70 != V_8 -> V_5 ||
( ! V_32 -> V_73 && V_8 -> V_5 > 1 ) ) {
V_66 -> V_74 ++ ;
F_26 ( L_12 ,
V_70 , V_8 -> V_16 ) ;
F_25 ( V_8 , V_42 ) ;
F_31 ( V_2 ) ;
if ( F_1 ( V_2 , V_4 ) != 0 )
return - V_17 ;
V_8 = & V_2 -> V_28 [ V_4 ] ;
}
if ( V_8 -> V_5 == 1 ) {
V_22 = (struct V_19 * ) V_8 -> V_21 ;
V_69 -> V_75 . V_76 = V_33 -> V_77 -> V_76 ;
V_69 -> V_75 . V_78 = V_33 -> V_77 -> V_78 ;
V_69 -> V_75 . V_79 = F_20 ( V_42 , & V_22 [ 0 ] ) ;
V_69 -> V_75 . V_80 = F_19 ( V_42 , & V_22 [ 0 ] ) ;
V_69 -> V_75 . V_81 = 0 ;
F_22 ( L_13
L_14 ,
( unsigned int ) V_69 -> V_75 . V_76 ,
( unsigned int ) V_69 -> V_75 . V_78 ,
( unsigned long ) V_69 -> V_75 . V_80 ,
( unsigned long ) V_69 -> V_75 . V_79 ) ;
} else {
F_28 ( V_8 , V_32 -> V_41 , V_42 ) ;
V_71 = F_33 ( V_32 , V_32 -> V_41 , & V_69 -> V_75 ) ;
if ( V_71 && V_71 != - V_82 ) {
F_25 ( V_8 , V_42 ) ;
F_6 ( L_15 ,
V_8 -> V_5 ,
F_34 ( V_2 -> V_83 . V_84 . V_85 ) ) ;
F_6 ( L_16 ,
V_32 -> V_41 -> V_55 , V_32 -> V_41 -> V_27 ,
V_32 -> V_41 -> V_26 ) ;
for ( V_23 = 0 ; V_23 < V_32 -> V_41 -> V_27 ; V_23 ++ )
F_6 ( L_17 , V_23 ,
( unsigned long long ) V_32 -> V_41 -> V_53 [ V_23 ] ) ;
return V_71 ;
}
}
return 0 ;
}

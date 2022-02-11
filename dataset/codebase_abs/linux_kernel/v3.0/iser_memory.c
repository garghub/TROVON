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
V_25 = F_8 ( F_9 ( V_22 ) , V_26 ) ;
memcpy ( V_24 ,
V_25 + V_22 -> V_27 ,
V_22 -> V_28 ) ;
F_10 ( V_25 , V_26 ) ;
V_24 += V_22 -> V_28 ;
}
}
F_11 ( & V_2 -> V_29 [ V_4 ] . V_30 , V_8 , V_11 ) ;
V_2 -> V_29 [ V_4 ] . V_21 =
& V_2 -> V_29 [ V_4 ] . V_30 ;
V_2 -> V_29 [ V_4 ] . V_16 = 1 ;
V_2 -> V_29 [ V_4 ] . V_31 = V_8 ;
V_7 = V_2 -> V_32 -> V_33 -> V_34 -> V_6 ;
V_5 = F_12 ( V_7 ,
& V_2 -> V_29 [ V_4 ] . V_30 ,
1 ,
( V_4 == V_18 ) ?
V_35 : V_36 ) ;
F_13 ( V_5 == 0 ) ;
V_2 -> V_29 [ V_4 ] . V_5 = V_5 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_6 * V_7 ;
struct V_9 * V_37 ;
unsigned long V_11 ;
V_7 = V_2 -> V_32 -> V_33 -> V_34 -> V_6 ;
V_37 = & V_2 -> V_29 [ V_4 ] ;
F_15 ( V_7 , & V_37 -> V_30 , 1 ,
( V_4 == V_18 ) ?
V_35 : V_36 ) ;
if ( V_4 == V_38 ) {
char * V_8 ;
struct V_19 * V_20 , * V_22 ;
unsigned char * V_24 , * V_39 ;
unsigned int V_40 ;
int V_23 ;
V_8 = V_37 -> V_31 ;
V_20 = (struct V_19 * ) V_2 -> V_10 [ V_38 ] . V_21 ;
V_40 = V_2 -> V_10 [ V_38 ] . V_16 ;
V_24 = V_8 ;
F_7 (sgl, sg, sg_size, i) {
V_39 = F_8 ( F_9 ( V_22 ) , V_41 ) ;
memcpy ( V_39 + V_22 -> V_27 ,
V_24 ,
V_22 -> V_28 ) ;
F_10 ( V_39 , V_41 ) ;
V_24 += V_22 -> V_28 ;
}
}
V_11 = V_2 -> V_10 [ V_4 ] . V_12 ;
if ( V_11 > V_13 )
F_16 ( ( unsigned long ) V_37 -> V_31 ,
F_3 ( F_4 ( V_11 ) ) - V_15 ) ;
else
F_17 ( V_37 -> V_31 ) ;
V_37 -> V_31 = NULL ;
}
static int F_18 ( struct V_9 * V_10 ,
struct V_42 * V_43 ,
struct V_6 * V_44 )
{
struct V_19 * V_22 , * V_20 = (struct V_19 * ) V_10 -> V_21 ;
T_1 V_45 , V_46 , V_47 , V_48 = 0 ;
unsigned long V_49 = 0 ;
unsigned int V_50 ;
int V_23 , V_51 , V_52 , V_53 = V_10 -> V_5 - 1 ;
V_43 -> V_27 = ( T_1 ) V_20 [ 0 ] . V_27 & ~ V_54 ;
V_51 = 1 ;
V_52 = 0 ;
F_7 (sgl, sg, data->dma_nents, i) {
V_45 = F_19 ( V_44 , V_22 ) ;
if ( V_51 )
V_48 = V_45 ;
V_50 = F_20 ( V_44 , V_22 ) ;
V_46 = V_45 + V_50 ;
V_49 += V_50 ;
if ( ! F_21 ( V_46 ) && V_23 < V_53 ) {
V_51 = 0 ;
continue;
}
V_51 = 1 ;
V_47 = V_48 & V_54 ;
do {
V_43 -> V_55 [ V_52 ++ ] = V_47 ;
V_47 += V_56 ;
} while ( V_47 < V_46 );
}
V_43 -> V_57 = V_49 ;
F_22 ( L_2 , V_43 -> V_57 , V_52 ) ;
return V_52 ;
}
static int F_23 ( struct V_9 * V_10 ,
struct V_6 * V_44 )
{
struct V_19 * V_20 , * V_22 , * V_58 = NULL ;
T_1 V_45 , V_46 ;
int V_23 , V_59 , V_60 = 0 ;
if ( V_10 -> V_5 == 1 )
return 1 ;
V_20 = (struct V_19 * ) V_10 -> V_21 ;
V_45 = F_19 ( V_44 , V_20 ) ;
F_7 (sgl, sg, data->dma_nents, i) {
if ( V_60 && ! F_21 ( V_45 ) )
break;
V_58 = F_24 ( V_22 ) ;
if ( ! V_58 )
break;
V_46 = V_45 + F_20 ( V_44 , V_22 ) ;
V_45 = F_19 ( V_44 , V_58 ) ;
if ( V_46 == V_45 ) {
V_60 = 0 ;
continue;
} else
V_60 = 1 ;
if ( ! F_21 ( V_46 ) )
break;
}
V_59 = ( V_58 ) ? V_23 : V_23 + 1 ;
F_22 ( L_3 ,
V_59 , V_10 -> V_5 , V_10 ) ;
return V_59 ;
}
static void F_25 ( struct V_9 * V_10 ,
struct V_6 * V_44 )
{
struct V_19 * V_20 = (struct V_19 * ) V_10 -> V_21 ;
struct V_19 * V_22 ;
int V_23 ;
if ( V_61 == 0 )
return;
F_7 (sgl, sg, data->dma_nents, i)
F_26 ( L_4
L_5 ,
V_23 , ( unsigned long ) F_19 ( V_44 , V_22 ) ,
F_9 ( V_22 ) , V_22 -> V_27 ,
V_22 -> V_28 , F_20 ( V_44 , V_22 ) ) ;
}
static void F_27 ( struct V_42 * V_43 )
{
int V_23 ;
F_6 ( L_6 ,
V_43 -> V_28 , V_43 -> V_57 ) ;
for ( V_23 = 0 ; V_23 < V_43 -> V_28 ; V_23 ++ )
F_6 ( L_7 , V_23 , ( unsigned long ) V_43 -> V_55 [ V_23 ] ) ;
}
static void F_28 ( struct V_9 * V_10 ,
struct V_42 * V_43 ,
struct V_6 * V_44 )
{
int V_62 = 0 ;
V_43 -> V_28 = 0 ;
V_43 -> V_27 = 0 ;
F_22 ( L_8 , V_10 -> V_5 ) ;
V_62 = F_18 ( V_10 , V_43 , V_44 ) ;
F_22 ( L_9 , V_10 -> V_5 , V_62 ) ;
V_43 -> V_28 = V_62 ;
if ( V_62 * V_56 < V_43 -> V_57 ) {
F_6 ( L_10 ) ;
F_25 ( V_10 , V_44 ) ;
F_27 ( V_43 ) ;
F_29 () ;
}
}
int F_30 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
enum V_3 V_63 ,
enum V_64 V_65 )
{
struct V_6 * V_7 ;
V_2 -> V_66 [ V_63 ] = 1 ;
V_7 = V_2 -> V_32 -> V_33 -> V_34 -> V_6 ;
V_10 -> V_5 = F_12 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_65 ) ;
if ( V_10 -> V_5 == 0 ) {
F_6 ( L_11 ) ;
return - V_67 ;
}
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_9 * V_10 ;
V_7 = V_2 -> V_32 -> V_33 -> V_34 -> V_6 ;
if ( V_2 -> V_66 [ V_38 ] ) {
V_10 = & V_2 -> V_10 [ V_38 ] ;
F_15 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_36 ) ;
}
if ( V_2 -> V_66 [ V_18 ] ) {
V_10 = & V_2 -> V_10 [ V_18 ] ;
F_15 ( V_7 , V_10 -> V_21 , V_10 -> V_16 , V_35 ) ;
}
}
int F_32 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_68 * V_68 = V_2 -> V_32 -> V_68 ;
struct V_32 * V_33 = V_2 -> V_32 -> V_33 ;
struct V_69 * V_34 = V_33 -> V_34 ;
struct V_6 * V_44 = V_34 -> V_6 ;
struct V_9 * V_8 = & V_2 -> V_10 [ V_4 ] ;
struct V_70 * V_71 ;
int V_72 ;
int V_73 ;
int V_23 ;
struct V_19 * V_22 ;
V_71 = & V_2 -> V_74 [ V_4 ] ;
V_72 = F_23 ( V_8 , V_44 ) ;
if ( V_72 != V_8 -> V_5 ) {
V_68 -> V_75 ++ ;
F_26 ( L_12 ,
V_72 , V_8 -> V_16 ) ;
F_25 ( V_8 , V_44 ) ;
F_31 ( V_2 ) ;
if ( F_1 ( V_2 , V_4 ) != 0 )
return - V_17 ;
V_8 = & V_2 -> V_29 [ V_4 ] ;
}
if ( V_8 -> V_5 == 1 ) {
V_22 = (struct V_19 * ) V_8 -> V_21 ;
V_71 -> V_76 . V_77 = V_34 -> V_78 -> V_77 ;
V_71 -> V_76 . V_79 = V_34 -> V_78 -> V_79 ;
V_71 -> V_76 . V_80 = F_20 ( V_44 , & V_22 [ 0 ] ) ;
V_71 -> V_76 . V_81 = F_19 ( V_44 , & V_22 [ 0 ] ) ;
V_71 -> V_76 . V_82 = 0 ;
F_22 ( L_13
L_14 ,
( unsigned int ) V_71 -> V_76 . V_77 ,
( unsigned int ) V_71 -> V_76 . V_79 ,
( unsigned long ) V_71 -> V_76 . V_81 ,
( unsigned long ) V_71 -> V_76 . V_80 ) ;
} else {
F_28 ( V_8 , V_33 -> V_43 , V_44 ) ;
V_73 = F_33 ( V_33 , V_33 -> V_43 , & V_71 -> V_76 ) ;
if ( V_73 ) {
F_25 ( V_8 , V_44 ) ;
F_6 ( L_15 ,
V_8 -> V_5 ,
F_34 ( V_2 -> V_83 . V_84 . V_85 ) ) ;
F_6 ( L_16 ,
V_33 -> V_43 -> V_57 , V_33 -> V_43 -> V_28 ,
V_33 -> V_43 -> V_27 ) ;
for ( V_23 = 0 ; V_23 < V_33 -> V_43 -> V_28 ; V_23 ++ )
F_6 ( L_17 , V_23 ,
( unsigned long long ) V_33 -> V_43 -> V_55 [ V_23 ] ) ;
return V_73 ;
}
}
return 0 ;
}

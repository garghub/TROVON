static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned int V_7 ;
if ( ! V_4 )
return;
if ( V_4 -> V_6 ) {
for ( V_7 = 0 ; V_7 < V_4 -> V_8 ; V_7 ++ ) {
V_6 = F_2 ( V_4 , V_7 ) ;
F_3 ( V_2 , V_6 ) ;
}
F_4 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
if ( V_4 -> V_9 ) {
F_5 ( V_2 -> V_10 ,
( sizeof( struct V_11 ) *
V_4 -> V_8 ) ,
V_4 -> V_9 , V_4 -> V_12 ) ;
V_4 -> V_9 = NULL ;
}
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
unsigned int V_7 ;
F_7 ( L_1 ) ;
V_14 = V_2 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ , V_14 ++ ) {
F_1 ( V_2 , V_14 -> V_16 ) ;
F_1 ( V_2 , V_14 -> V_17 ) ;
}
F_7 ( L_2 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_8 )
{
F_7 ( L_3 ) ;
if ( ! V_4 )
return 0 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_9 = F_9 ( V_2 -> V_10 ,
( sizeof( struct V_11 ) *
V_8 ) , & V_4 -> V_12 ,
V_18 ) ;
if ( ! V_4 -> V_9 )
return - V_19 ;
V_4 -> V_6 = F_10 ( V_8 , sizeof( struct V_5 ) ,
V_18 ) ;
if ( ! V_4 -> V_6 )
return - V_19 ;
F_7 ( L_4 ,
V_4 -> V_9 , V_4 -> V_12 , V_4 -> V_6 ) ;
F_7 ( L_5 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
unsigned int V_7 ;
int V_20 ;
F_7 ( L_6 ) ;
V_14 = V_2 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ , V_14 ++ ) {
F_7 ( L_7 , V_14 -> V_21 ) ;
V_20 = F_8 ( V_2 , V_14 -> V_16 ,
V_2 -> V_22 ) ;
if ( V_20 ) {
F_12 ( V_2 -> V_23 ,
L_8 ) ;
goto V_24;
}
F_7 ( L_9 , V_14 -> V_21 ) ;
V_20 = F_8 ( V_2 , V_14 -> V_17 ,
V_2 -> V_25 ) ;
if ( V_20 ) {
F_12 ( V_2 -> V_23 ,
L_8 ) ;
goto V_24;
}
}
F_7 ( L_10 ) ;
return 0 ;
V_24:
F_6 ( V_2 ) ;
return V_20 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_11 * V_9 ;
T_1 V_12 ;
unsigned int V_7 , V_28 ;
F_7 ( L_11 ) ;
V_14 = V_2 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ , V_14 ++ ) {
V_4 = V_14 -> V_16 ;
if ( ! V_4 )
break;
V_9 = V_4 -> V_9 ;
V_12 = V_4 -> V_12 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_8 ; V_28 ++ ) {
V_6 = F_2 ( V_4 , V_28 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_12 = V_12 ;
V_9 ++ ;
V_12 += sizeof( struct V_11 ) ;
}
V_4 -> V_29 = 0 ;
V_4 -> V_30 = 0 ;
V_4 -> V_31 . V_32 = 0 ;
V_27 -> V_33 ( V_14 ) ;
}
F_7 ( L_12 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_13 * V_14 ;
struct V_3 * V_4 ;
struct V_11 * V_9 ;
struct V_5 * V_6 ;
T_1 V_12 , V_34 ;
struct V_35 * V_36 = NULL ;
unsigned int V_7 , V_28 ;
F_7 ( L_13 ) ;
V_14 = V_2 -> V_14 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_15 ; V_7 ++ , V_14 ++ ) {
V_4 = V_14 -> V_17 ;
if ( ! V_4 )
break;
V_9 = V_4 -> V_9 ;
V_12 = V_4 -> V_12 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_8 ; V_28 ++ ) {
V_6 = F_2 ( V_4 , V_28 ) ;
V_6 -> V_9 = V_9 ;
V_6 -> V_12 = V_12 ;
V_36 = F_15 ( V_2 -> V_37 ) ;
if ( V_36 == NULL )
break;
V_34 = F_16 ( V_2 -> V_10 , V_36 -> V_38 ,
V_2 -> V_37 ,
V_39 ) ;
if ( F_17 ( V_2 -> V_10 , V_34 ) ) {
F_12 ( V_2 -> V_23 ,
L_14 ) ;
F_18 ( V_36 ) ;
break;
}
V_6 -> V_36 = V_36 ;
V_6 -> V_34 = V_34 ;
V_6 -> V_40 = V_2 -> V_37 ;
V_9 ++ ;
V_12 += sizeof( struct V_11 ) ;
}
V_4 -> V_29 = 0 ;
V_4 -> V_30 = 0 ;
V_4 -> V_41 . V_42 = 0 ;
V_4 -> V_41 . V_43 = 0 ;
V_27 -> V_44 ( V_14 ) ;
}
F_7 ( L_15 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_34 ) {
if ( V_6 -> V_45 ) {
F_19 ( V_2 -> V_10 , V_6 -> V_34 ,
V_6 -> V_40 , V_46 ) ;
} else {
F_20 ( V_2 -> V_10 , V_6 -> V_34 ,
V_6 -> V_40 , V_46 ) ;
}
V_6 -> V_34 = 0 ;
V_6 -> V_40 = 0 ;
}
if ( V_6 -> V_36 ) {
F_18 ( V_6 -> V_36 ) ;
V_6 -> V_36 = NULL ;
}
V_6 -> V_47 = 0 ;
V_6 -> V_48 = 0 ;
V_6 -> V_49 = 0 ;
V_6 -> V_45 = 0 ;
if ( V_6 -> V_50 ) {
V_6 -> V_50 = 0 ;
V_6 -> V_51 . V_52 = 0 ;
V_6 -> V_51 . V_53 = 0 ;
V_6 -> V_51 . V_36 = NULL ;
V_6 -> V_51 . V_48 = 0 ;
V_6 -> V_51 . error = 0 ;
}
}
static int F_21 ( struct V_13 * V_14 , struct V_35 * V_36 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_3 * V_4 = V_14 -> V_16 ;
struct V_5 * V_6 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_1 V_34 ;
unsigned int V_58 , V_59 ;
unsigned int V_60 , V_61 , V_62 , V_63 , V_48 ;
unsigned int V_7 ;
F_7 ( L_16 , V_4 -> V_29 ) ;
V_60 = 0 ;
V_58 = V_4 -> V_29 ;
V_59 = V_4 -> V_29 ;
V_55 = & V_4 -> V_64 ;
V_55 -> V_8 = 0 ;
V_55 -> V_65 = 0 ;
V_61 = F_22 ( V_55 -> V_66 , V_67 ,
V_68 ) ;
V_62 = F_22 ( V_55 -> V_66 , V_67 ,
V_69 ) ;
if ( ( V_61 && ( V_55 -> V_70 != V_4 -> V_31 . V_71 ) ) ||
( V_62 && ( V_55 -> V_72 != V_4 -> V_31 . V_73 ) ) )
V_59 ++ ;
V_6 = F_2 ( V_4 , V_59 ) ;
if ( V_61 ) {
F_7 ( L_17 ) ;
V_34 = F_16 ( V_2 -> V_10 , V_36 -> V_38 ,
V_55 -> V_74 , V_46 ) ;
if ( F_17 ( V_2 -> V_10 , V_34 ) ) {
F_12 ( V_2 -> V_23 , L_18 ) ;
goto V_75;
}
V_6 -> V_34 = V_34 ;
V_6 -> V_40 = V_55 -> V_74 ;
V_6 -> V_47 = 1 ;
V_60 = V_55 -> V_74 ;
V_55 -> V_65 += V_55 -> V_74 ;
V_59 ++ ;
V_6 = F_2 ( V_4 , V_59 ) ;
}
for ( V_63 = F_23 ( V_36 ) - V_60 ; V_63 ; ) {
V_48 = F_24 (unsigned int, datalen, XGBE_TX_MAX_BUF_SIZE) ;
V_34 = F_16 ( V_2 -> V_10 , V_36 -> V_38 + V_60 , V_48 ,
V_46 ) ;
if ( F_17 ( V_2 -> V_10 , V_34 ) ) {
F_12 ( V_2 -> V_23 , L_18 ) ;
goto V_75;
}
V_6 -> V_34 = V_34 ;
V_6 -> V_40 = V_48 ;
F_7 ( L_19 ,
V_59 , V_34 , V_48 ) ;
V_63 -= V_48 ;
V_60 += V_48 ;
V_55 -> V_65 += V_48 ;
V_59 ++ ;
V_6 = F_2 ( V_4 , V_59 ) ;
}
for ( V_7 = 0 ; V_7 < F_25 ( V_36 ) -> V_76 ; V_7 ++ ) {
F_7 ( L_20 , V_7 ) ;
V_57 = & F_25 ( V_36 ) -> V_77 [ V_7 ] ;
V_60 = 0 ;
for ( V_63 = F_26 ( V_57 ) ; V_63 ; ) {
V_48 = F_24 (unsigned int, datalen,
XGBE_TX_MAX_BUF_SIZE) ;
V_34 = F_27 ( V_2 -> V_10 , V_57 , V_60 ,
V_48 , V_46 ) ;
if ( F_17 ( V_2 -> V_10 , V_34 ) ) {
F_12 ( V_2 -> V_23 ,
L_21 ) ;
goto V_75;
}
V_6 -> V_34 = V_34 ;
V_6 -> V_40 = V_48 ;
V_6 -> V_45 = 1 ;
F_7 ( L_19 ,
V_59 , V_34 , V_48 ) ;
V_63 -= V_48 ;
V_60 += V_48 ;
V_55 -> V_65 += V_48 ;
V_59 ++ ;
V_6 = F_2 ( V_4 , V_59 ) ;
}
}
V_6 -> V_36 = V_36 ;
V_55 -> V_8 = V_59 - V_58 ;
F_7 ( L_22 , V_55 -> V_8 ) ;
return V_55 -> V_8 ;
V_75:
while ( V_58 < V_59 ) {
V_6 = F_2 ( V_4 , V_58 ++ ) ;
F_3 ( V_2 , V_6 ) ;
}
F_7 ( L_23 ) ;
return 0 ;
}
static void F_28 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
struct V_26 * V_27 = & V_2 -> V_27 ;
struct V_3 * V_4 = V_14 -> V_17 ;
struct V_5 * V_6 ;
struct V_35 * V_36 = NULL ;
T_1 V_34 ;
int V_7 ;
F_7 ( L_24 ,
V_4 -> V_41 . V_42 ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_30 ; V_7 ++ ) {
V_6 = F_2 ( V_4 , V_4 -> V_41 . V_42 ) ;
F_3 ( V_2 , V_6 ) ;
V_36 = F_15 ( V_2 -> V_37 ) ;
if ( V_36 == NULL )
break;
V_34 = F_16 ( V_2 -> V_10 , V_36 -> V_38 ,
V_2 -> V_37 , V_39 ) ;
if ( F_17 ( V_2 -> V_10 , V_34 ) ) {
F_12 ( V_2 -> V_23 ,
L_14 ) ;
F_18 ( V_36 ) ;
break;
}
V_6 -> V_36 = V_36 ;
V_6 -> V_34 = V_34 ;
V_6 -> V_40 = V_2 -> V_37 ;
V_27 -> V_78 ( V_6 ) ;
V_4 -> V_41 . V_42 ++ ;
}
V_4 -> V_30 = 0 ;
F_7 ( L_25 ) ;
}
void F_29 ( struct V_79 * V_80 )
{
F_7 ( L_26 ) ;
V_80 -> V_81 = F_11 ;
V_80 -> V_82 = F_6 ;
V_80 -> V_83 = F_21 ;
V_80 -> V_84 = F_28 ;
V_80 -> V_85 = F_3 ;
V_80 -> V_86 = F_13 ;
V_80 -> V_87 = F_14 ;
F_7 ( L_27 ) ;
}

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
if ( V_4 -> V_9 . V_10 ) {
F_5 ( V_2 -> V_11 , V_4 -> V_9 . V_12 ,
V_4 -> V_9 . V_13 , V_14 ) ;
F_6 ( V_4 -> V_9 . V_10 ) ;
V_4 -> V_9 . V_10 = NULL ;
V_4 -> V_9 . V_13 = 0 ;
V_4 -> V_9 . V_15 = 0 ;
V_4 -> V_9 . V_12 = 0 ;
}
if ( V_4 -> V_16 . V_10 ) {
F_5 ( V_2 -> V_11 , V_4 -> V_16 . V_12 ,
V_4 -> V_16 . V_13 , V_14 ) ;
F_6 ( V_4 -> V_16 . V_10 ) ;
V_4 -> V_16 . V_10 = NULL ;
V_4 -> V_16 . V_13 = 0 ;
V_4 -> V_16 . V_15 = 0 ;
V_4 -> V_16 . V_12 = 0 ;
}
if ( V_4 -> V_17 ) {
F_7 ( V_2 -> V_11 ,
( sizeof( struct V_18 ) *
V_4 -> V_8 ) ,
V_4 -> V_17 , V_4 -> V_19 ) ;
V_4 -> V_17 = NULL ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned int V_7 ;
F_9 ( L_1 ) ;
V_21 = V_2 -> V_21 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ , V_21 ++ ) {
F_1 ( V_2 , V_21 -> V_23 ) ;
F_1 ( V_2 , V_21 -> V_24 ) ;
}
F_9 ( L_2 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_8 )
{
F_9 ( L_3 ) ;
if ( ! V_4 )
return 0 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_17 = F_11 ( V_2 -> V_11 ,
( sizeof( struct V_18 ) *
V_8 ) , & V_4 -> V_19 ,
V_25 ) ;
if ( ! V_4 -> V_17 )
return - V_26 ;
V_4 -> V_6 = F_12 ( V_8 , sizeof( struct V_5 ) ,
V_25 ) ;
if ( ! V_4 -> V_6 )
return - V_26 ;
F_9 ( L_4 ,
V_4 -> V_17 , V_4 -> V_19 , V_4 -> V_6 ) ;
F_9 ( L_5 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned int V_7 ;
int V_27 ;
F_9 ( L_6 ) ;
V_21 = V_2 -> V_21 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ , V_21 ++ ) {
F_9 ( L_7 , V_21 -> V_28 ) ;
V_27 = F_10 ( V_2 , V_21 -> V_23 ,
V_2 -> V_29 ) ;
if ( V_27 ) {
F_14 ( V_2 -> V_30 ,
L_8 ) ;
goto V_31;
}
F_9 ( L_9 , V_21 -> V_28 ) ;
V_27 = F_10 ( V_2 , V_21 -> V_24 ,
V_2 -> V_32 ) ;
if ( V_27 ) {
F_14 ( V_2 -> V_30 ,
L_8 ) ;
goto V_31;
}
}
F_9 ( L_10 ) ;
return 0 ;
V_31:
F_8 ( V_2 ) ;
return V_27 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_33 * V_34 , T_1 V_35 , int V_36 )
{
struct V_37 * V_10 = NULL ;
T_2 V_12 ;
int V_27 ;
V_35 |= V_38 | V_39 ;
while ( V_36 >= 0 ) {
V_10 = F_16 ( V_35 , V_36 ) ;
if ( V_10 )
break;
V_36 -- ;
}
if ( ! V_10 )
return - V_26 ;
V_12 = F_17 ( V_2 -> V_11 , V_10 , 0 ,
V_40 << V_36 , V_14 ) ;
V_27 = F_18 ( V_2 -> V_11 , V_12 ) ;
if ( V_27 ) {
F_6 ( V_10 ) ;
return V_27 ;
}
V_34 -> V_10 = V_10 ;
V_34 -> V_13 = V_40 << V_36 ;
V_34 -> V_15 = 0 ;
V_34 -> V_12 = V_12 ;
return 0 ;
}
static void F_19 ( struct V_41 * V_42 ,
struct V_33 * V_34 ,
unsigned int V_43 )
{
F_20 ( V_34 -> V_10 ) ;
V_42 -> V_34 = * V_34 ;
V_42 -> V_44 = V_34 -> V_12 + V_34 -> V_15 ;
V_42 -> V_45 = V_43 ;
V_34 -> V_15 += V_43 ;
if ( ( V_34 -> V_15 + V_43 ) > V_34 -> V_13 ) {
V_42 -> V_46 = * V_34 ;
V_34 -> V_10 = NULL ;
V_34 -> V_13 = 0 ;
V_34 -> V_15 = 0 ;
V_34 -> V_12 = 0 ;
}
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_36 , V_27 ;
if ( ! V_4 -> V_9 . V_10 ) {
V_27 = F_15 ( V_2 , & V_4 -> V_9 , V_47 , 0 ) ;
if ( V_27 )
return V_27 ;
}
if ( ! V_4 -> V_16 . V_10 ) {
V_36 = F_22 ( int , V_48 - 1 , 0 ) ;
V_27 = F_15 ( V_2 , & V_4 -> V_16 , V_47 ,
V_36 ) ;
if ( V_27 )
return V_27 ;
}
F_19 ( & V_6 -> V_49 . V_50 , & V_4 -> V_9 ,
V_51 ) ;
F_19 ( & V_6 -> V_49 . V_52 , & V_4 -> V_16 ,
V_2 -> V_53 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = & V_2 -> V_55 ;
struct V_20 * V_21 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_18 * V_17 ;
T_2 V_19 ;
unsigned int V_7 , V_56 ;
F_9 ( L_11 ) ;
V_21 = V_2 -> V_21 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ , V_21 ++ ) {
V_4 = V_21 -> V_23 ;
if ( ! V_4 )
break;
V_17 = V_4 -> V_17 ;
V_19 = V_4 -> V_19 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_8 ; V_56 ++ ) {
V_6 = F_2 ( V_4 , V_56 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_19 = V_19 ;
V_17 ++ ;
V_19 += sizeof( struct V_18 ) ;
}
V_4 -> V_57 = 0 ;
V_4 -> V_58 = 0 ;
memset ( & V_4 -> V_59 , 0 , sizeof( V_4 -> V_59 ) ) ;
V_55 -> V_60 ( V_21 ) ;
}
F_9 ( L_12 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = & V_2 -> V_55 ;
struct V_20 * V_21 ;
struct V_3 * V_4 ;
struct V_18 * V_17 ;
struct V_5 * V_6 ;
T_2 V_19 ;
unsigned int V_7 , V_56 ;
F_9 ( L_13 ) ;
V_21 = V_2 -> V_21 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ , V_21 ++ ) {
V_4 = V_21 -> V_24 ;
if ( ! V_4 )
break;
V_17 = V_4 -> V_17 ;
V_19 = V_4 -> V_19 ;
for ( V_56 = 0 ; V_56 < V_4 -> V_8 ; V_56 ++ ) {
V_6 = F_2 ( V_4 , V_56 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_19 = V_19 ;
if ( F_21 ( V_2 , V_4 , V_6 ) )
break;
V_17 ++ ;
V_19 += sizeof( struct V_18 ) ;
}
V_4 -> V_57 = 0 ;
V_4 -> V_58 = 0 ;
V_55 -> V_61 ( V_21 ) ;
}
F_9 ( L_14 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_62 ) {
if ( V_6 -> V_63 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_62 ,
V_6 -> V_64 , V_65 ) ;
} else {
F_25 ( V_2 -> V_11 , V_6 -> V_62 ,
V_6 -> V_64 , V_65 ) ;
}
V_6 -> V_62 = 0 ;
V_6 -> V_64 = 0 ;
}
if ( V_6 -> V_66 ) {
F_26 ( V_6 -> V_66 ) ;
V_6 -> V_66 = NULL ;
}
if ( V_6 -> V_49 . V_50 . V_34 . V_10 )
F_6 ( V_6 -> V_49 . V_50 . V_34 . V_10 ) ;
if ( V_6 -> V_49 . V_50 . V_46 . V_10 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_49 . V_50 . V_46 . V_12 ,
V_6 -> V_49 . V_50 . V_46 . V_13 ,
V_14 ) ;
F_6 ( V_6 -> V_49 . V_50 . V_46 . V_10 ) ;
}
if ( V_6 -> V_49 . V_52 . V_34 . V_10 )
F_6 ( V_6 -> V_49 . V_52 . V_34 . V_10 ) ;
if ( V_6 -> V_49 . V_52 . V_46 . V_10 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_49 . V_52 . V_46 . V_12 ,
V_6 -> V_49 . V_52 . V_46 . V_13 ,
V_14 ) ;
F_6 ( V_6 -> V_49 . V_52 . V_46 . V_10 ) ;
}
memset ( & V_6 -> V_59 , 0 , sizeof( V_6 -> V_59 ) ) ;
memset ( & V_6 -> V_49 , 0 , sizeof( V_6 -> V_49 ) ) ;
V_6 -> V_63 = 0 ;
if ( V_6 -> V_67 ) {
V_6 -> V_67 = 0 ;
V_6 -> V_68 . V_69 = 0 ;
V_6 -> V_68 . V_70 = 0 ;
V_6 -> V_68 . V_66 = NULL ;
V_6 -> V_68 . V_43 = 0 ;
V_6 -> V_68 . error = 0 ;
}
}
static int F_27 ( struct V_20 * V_21 , struct V_71 * V_66 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_21 -> V_23 ;
struct V_5 * V_6 ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
T_2 V_62 ;
unsigned int V_76 , V_77 ;
unsigned int V_78 , V_79 , V_80 , V_81 , V_43 ;
unsigned int V_7 ;
F_9 ( L_15 , V_4 -> V_57 ) ;
V_78 = 0 ;
V_76 = V_4 -> V_57 ;
V_77 = V_4 -> V_57 ;
V_73 = & V_4 -> V_82 ;
V_73 -> V_8 = 0 ;
V_73 -> V_83 = 0 ;
V_79 = F_28 ( V_73 -> V_84 , V_85 ,
V_86 ) ;
V_80 = F_28 ( V_73 -> V_84 , V_85 ,
V_87 ) ;
if ( ( V_79 && ( V_73 -> V_88 != V_4 -> V_59 . V_89 ) ) ||
( V_80 && ( V_73 -> V_90 != V_4 -> V_59 . V_91 ) ) )
V_77 ++ ;
V_6 = F_2 ( V_4 , V_77 ) ;
if ( V_79 ) {
F_9 ( L_16 ) ;
V_62 = F_29 ( V_2 -> V_11 , V_66 -> V_92 ,
V_73 -> V_93 , V_65 ) ;
if ( F_18 ( V_2 -> V_11 , V_62 ) ) {
F_14 ( V_2 -> V_30 , L_17 ) ;
goto V_94;
}
V_6 -> V_62 = V_62 ;
V_6 -> V_64 = V_73 -> V_93 ;
V_78 = V_73 -> V_93 ;
V_73 -> V_83 += V_73 -> V_93 ;
V_77 ++ ;
V_6 = F_2 ( V_4 , V_77 ) ;
}
for ( V_81 = F_30 ( V_66 ) - V_78 ; V_81 ; ) {
V_43 = F_31 (unsigned int, datalen, XGBE_TX_MAX_BUF_SIZE) ;
V_62 = F_29 ( V_2 -> V_11 , V_66 -> V_92 + V_78 , V_43 ,
V_65 ) ;
if ( F_18 ( V_2 -> V_11 , V_62 ) ) {
F_14 ( V_2 -> V_30 , L_17 ) ;
goto V_94;
}
V_6 -> V_62 = V_62 ;
V_6 -> V_64 = V_43 ;
F_9 ( L_18 ,
V_77 , V_62 , V_43 ) ;
V_81 -= V_43 ;
V_78 += V_43 ;
V_73 -> V_83 += V_43 ;
V_77 ++ ;
V_6 = F_2 ( V_4 , V_77 ) ;
}
for ( V_7 = 0 ; V_7 < F_32 ( V_66 ) -> V_95 ; V_7 ++ ) {
F_9 ( L_19 , V_7 ) ;
V_75 = & F_32 ( V_66 ) -> V_96 [ V_7 ] ;
V_78 = 0 ;
for ( V_81 = F_33 ( V_75 ) ; V_81 ; ) {
V_43 = F_31 (unsigned int, datalen,
XGBE_TX_MAX_BUF_SIZE) ;
V_62 = F_34 ( V_2 -> V_11 , V_75 , V_78 ,
V_43 , V_65 ) ;
if ( F_18 ( V_2 -> V_11 , V_62 ) ) {
F_14 ( V_2 -> V_30 ,
L_20 ) ;
goto V_94;
}
V_6 -> V_62 = V_62 ;
V_6 -> V_64 = V_43 ;
V_6 -> V_63 = 1 ;
F_9 ( L_18 ,
V_77 , V_62 , V_43 ) ;
V_81 -= V_43 ;
V_78 += V_43 ;
V_73 -> V_83 += V_43 ;
V_77 ++ ;
V_6 = F_2 ( V_4 , V_77 ) ;
}
}
V_6 = F_2 ( V_4 , V_77 - 1 ) ;
V_6 -> V_66 = V_66 ;
V_73 -> V_8 = V_77 - V_76 ;
F_9 ( L_21 , V_73 -> V_8 ) ;
return V_73 -> V_8 ;
V_94:
while ( V_76 < V_77 ) {
V_6 = F_2 ( V_4 , V_76 ++ ) ;
F_3 ( V_2 , V_6 ) ;
}
F_9 ( L_22 ) ;
return 0 ;
}
void F_35 ( struct V_97 * V_98 )
{
F_9 ( L_23 ) ;
V_98 -> V_99 = F_13 ;
V_98 -> V_100 = F_8 ;
V_98 -> V_101 = F_27 ;
V_98 -> V_102 = F_21 ;
V_98 -> V_103 = F_3 ;
V_98 -> V_104 = F_23 ;
V_98 -> V_105 = F_24 ;
F_9 ( L_24 ) ;
}

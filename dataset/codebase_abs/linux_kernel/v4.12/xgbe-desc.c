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
F_13 ( V_2 , V_27 , V_2 -> V_28 ,
L_4 ,
V_4 -> V_17 , & V_4 -> V_19 , V_4 -> V_6 ) ;
F_9 ( L_5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned int V_7 ;
int V_29 ;
F_9 ( L_6 ) ;
V_21 = V_2 -> V_21 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ , V_21 ++ ) {
F_13 ( V_2 , V_27 , V_2 -> V_28 , L_7 ,
V_21 -> V_30 ) ;
V_29 = F_10 ( V_2 , V_21 -> V_23 ,
V_2 -> V_31 ) ;
if ( V_29 ) {
F_15 ( V_2 -> V_28 ,
L_8 ) ;
goto V_32;
}
F_13 ( V_2 , V_27 , V_2 -> V_28 , L_9 ,
V_21 -> V_30 ) ;
V_29 = F_10 ( V_2 , V_21 -> V_24 ,
V_2 -> V_33 ) ;
if ( V_29 ) {
F_15 ( V_2 -> V_28 ,
L_10 ) ;
goto V_32;
}
}
F_9 ( L_11 ) ;
return 0 ;
V_32:
F_8 ( V_2 ) ;
return V_29 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_34 * V_35 , T_1 V_36 , int V_37 )
{
struct V_38 * V_10 = NULL ;
T_2 V_12 ;
int V_29 ;
V_36 |= V_39 | V_40 | V_41 ;
while ( V_37 >= 0 ) {
V_10 = F_17 ( V_36 , V_37 ) ;
if ( V_10 )
break;
V_37 -- ;
}
if ( ! V_10 )
return - V_26 ;
V_12 = F_18 ( V_2 -> V_11 , V_10 , 0 ,
V_42 << V_37 , V_14 ) ;
V_29 = F_19 ( V_2 -> V_11 , V_12 ) ;
if ( V_29 ) {
F_6 ( V_10 ) ;
return V_29 ;
}
V_35 -> V_10 = V_10 ;
V_35 -> V_13 = V_42 << V_37 ;
V_35 -> V_15 = 0 ;
V_35 -> V_12 = V_12 ;
return 0 ;
}
static void F_20 ( struct V_43 * V_44 ,
struct V_34 * V_35 ,
unsigned int V_45 )
{
F_21 ( V_35 -> V_10 ) ;
V_44 -> V_35 = * V_35 ;
V_44 -> V_46 = V_35 -> V_12 ;
V_44 -> V_47 = V_35 -> V_15 ;
V_44 -> V_48 = V_45 ;
V_35 -> V_15 += V_45 ;
if ( ( V_35 -> V_15 + V_45 ) > V_35 -> V_13 ) {
V_44 -> V_49 = * V_35 ;
V_35 -> V_10 = NULL ;
V_35 -> V_13 = 0 ;
V_35 -> V_15 = 0 ;
V_35 -> V_12 = 0 ;
}
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_29 ;
if ( ! V_4 -> V_9 . V_10 ) {
V_29 = F_16 ( V_2 , & V_4 -> V_9 , V_50 , 0 ) ;
if ( V_29 )
return V_29 ;
}
if ( ! V_4 -> V_16 . V_10 ) {
V_29 = F_16 ( V_2 , & V_4 -> V_16 , V_50 ,
V_51 ) ;
if ( V_29 )
return V_29 ;
}
F_20 ( & V_6 -> V_52 . V_53 , & V_4 -> V_9 ,
V_54 ) ;
F_20 ( & V_6 -> V_52 . V_55 , & V_4 -> V_16 ,
V_2 -> V_56 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = & V_2 -> V_58 ;
struct V_20 * V_21 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_18 * V_17 ;
T_2 V_19 ;
unsigned int V_7 , V_59 ;
F_9 ( L_12 ) ;
V_21 = V_2 -> V_21 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ , V_21 ++ ) {
V_4 = V_21 -> V_23 ;
if ( ! V_4 )
break;
V_17 = V_4 -> V_17 ;
V_19 = V_4 -> V_19 ;
for ( V_59 = 0 ; V_59 < V_4 -> V_8 ; V_59 ++ ) {
V_6 = F_2 ( V_4 , V_59 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_19 = V_19 ;
V_17 ++ ;
V_19 += sizeof( struct V_18 ) ;
}
V_4 -> V_60 = 0 ;
V_4 -> V_61 = 0 ;
memset ( & V_4 -> V_62 , 0 , sizeof( V_4 -> V_62 ) ) ;
V_58 -> V_63 ( V_21 ) ;
}
F_9 ( L_13 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_57 * V_58 = & V_2 -> V_58 ;
struct V_20 * V_21 ;
struct V_3 * V_4 ;
struct V_18 * V_17 ;
struct V_5 * V_6 ;
T_2 V_19 ;
unsigned int V_7 , V_59 ;
F_9 ( L_14 ) ;
V_21 = V_2 -> V_21 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ , V_21 ++ ) {
V_4 = V_21 -> V_24 ;
if ( ! V_4 )
break;
V_17 = V_4 -> V_17 ;
V_19 = V_4 -> V_19 ;
for ( V_59 = 0 ; V_59 < V_4 -> V_8 ; V_59 ++ ) {
V_6 = F_2 ( V_4 , V_59 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_19 = V_19 ;
if ( F_22 ( V_2 , V_4 , V_6 ) )
break;
V_17 ++ ;
V_19 += sizeof( struct V_18 ) ;
}
V_4 -> V_60 = 0 ;
V_4 -> V_61 = 0 ;
V_58 -> V_64 ( V_21 ) ;
}
F_9 ( L_15 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_65 ) {
if ( V_6 -> V_66 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_65 ,
V_6 -> V_67 , V_68 ) ;
} else {
F_25 ( V_2 -> V_11 , V_6 -> V_65 ,
V_6 -> V_67 , V_68 ) ;
}
V_6 -> V_65 = 0 ;
V_6 -> V_67 = 0 ;
}
if ( V_6 -> V_69 ) {
F_26 ( V_6 -> V_69 ) ;
V_6 -> V_69 = NULL ;
}
if ( V_6 -> V_52 . V_53 . V_35 . V_10 )
F_6 ( V_6 -> V_52 . V_53 . V_35 . V_10 ) ;
if ( V_6 -> V_52 . V_53 . V_49 . V_10 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_52 . V_53 . V_49 . V_12 ,
V_6 -> V_52 . V_53 . V_49 . V_13 ,
V_14 ) ;
F_6 ( V_6 -> V_52 . V_53 . V_49 . V_10 ) ;
}
if ( V_6 -> V_52 . V_55 . V_35 . V_10 )
F_6 ( V_6 -> V_52 . V_55 . V_35 . V_10 ) ;
if ( V_6 -> V_52 . V_55 . V_49 . V_10 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_52 . V_55 . V_49 . V_12 ,
V_6 -> V_52 . V_55 . V_49 . V_13 ,
V_14 ) ;
F_6 ( V_6 -> V_52 . V_55 . V_49 . V_10 ) ;
}
memset ( & V_6 -> V_62 , 0 , sizeof( V_6 -> V_62 ) ) ;
memset ( & V_6 -> V_52 , 0 , sizeof( V_6 -> V_52 ) ) ;
V_6 -> V_66 = 0 ;
if ( V_6 -> V_70 ) {
V_6 -> V_70 = 0 ;
V_6 -> V_71 . V_69 = NULL ;
V_6 -> V_71 . V_45 = 0 ;
V_6 -> V_71 . error = 0 ;
}
}
static int F_27 ( struct V_20 * V_21 , struct V_72 * V_69 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_21 -> V_23 ;
struct V_5 * V_6 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
T_2 V_65 ;
unsigned int V_77 , V_78 ;
unsigned int V_79 , V_80 , V_81 , V_82 , V_45 ;
unsigned int V_7 ;
F_9 ( L_16 , V_4 -> V_60 ) ;
V_79 = 0 ;
V_77 = V_4 -> V_60 ;
V_78 = V_4 -> V_60 ;
V_74 = & V_4 -> V_83 ;
V_74 -> V_8 = 0 ;
V_74 -> V_84 = 0 ;
V_80 = F_28 ( V_74 -> V_85 , V_86 ,
V_87 ) ;
V_81 = F_28 ( V_74 -> V_85 , V_86 ,
V_88 ) ;
if ( ( V_80 && ( V_74 -> V_89 != V_4 -> V_62 . V_90 ) ) ||
( V_81 && ( V_74 -> V_91 != V_4 -> V_62 . V_92 ) ) )
V_78 ++ ;
V_6 = F_2 ( V_4 , V_78 ) ;
if ( V_80 ) {
V_65 = F_29 ( V_2 -> V_11 , V_69 -> V_93 ,
V_74 -> V_94 , V_68 ) ;
if ( F_19 ( V_2 -> V_11 , V_65 ) ) {
F_15 ( V_2 -> V_28 , L_17 ) ;
goto V_95;
}
V_6 -> V_65 = V_65 ;
V_6 -> V_67 = V_74 -> V_94 ;
F_13 ( V_2 , V_96 , V_2 -> V_28 ,
L_18 ,
V_78 , & V_65 , V_74 -> V_94 ) ;
V_79 = V_74 -> V_94 ;
V_74 -> V_84 += V_74 -> V_94 ;
V_78 ++ ;
V_6 = F_2 ( V_4 , V_78 ) ;
}
for ( V_82 = F_30 ( V_69 ) - V_79 ; V_82 ; ) {
V_45 = F_31 (unsigned int, datalen, XGBE_TX_MAX_BUF_SIZE) ;
V_65 = F_29 ( V_2 -> V_11 , V_69 -> V_93 + V_79 , V_45 ,
V_68 ) ;
if ( F_19 ( V_2 -> V_11 , V_65 ) ) {
F_15 ( V_2 -> V_28 , L_17 ) ;
goto V_95;
}
V_6 -> V_65 = V_65 ;
V_6 -> V_67 = V_45 ;
F_13 ( V_2 , V_96 , V_2 -> V_28 ,
L_19 ,
V_78 , & V_65 , V_45 ) ;
V_82 -= V_45 ;
V_79 += V_45 ;
V_74 -> V_84 += V_45 ;
V_78 ++ ;
V_6 = F_2 ( V_4 , V_78 ) ;
}
for ( V_7 = 0 ; V_7 < F_32 ( V_69 ) -> V_97 ; V_7 ++ ) {
F_13 ( V_2 , V_96 , V_2 -> V_28 ,
L_20 , V_7 ) ;
V_76 = & F_32 ( V_69 ) -> V_98 [ V_7 ] ;
V_79 = 0 ;
for ( V_82 = F_33 ( V_76 ) ; V_82 ; ) {
V_45 = F_31 (unsigned int, datalen,
XGBE_TX_MAX_BUF_SIZE) ;
V_65 = F_34 ( V_2 -> V_11 , V_76 , V_79 ,
V_45 , V_68 ) ;
if ( F_19 ( V_2 -> V_11 , V_65 ) ) {
F_15 ( V_2 -> V_28 ,
L_21 ) ;
goto V_95;
}
V_6 -> V_65 = V_65 ;
V_6 -> V_67 = V_45 ;
V_6 -> V_66 = 1 ;
F_13 ( V_2 , V_96 , V_2 -> V_28 ,
L_22 ,
V_78 , & V_65 , V_45 ) ;
V_82 -= V_45 ;
V_79 += V_45 ;
V_74 -> V_84 += V_45 ;
V_78 ++ ;
V_6 = F_2 ( V_4 , V_78 ) ;
}
}
V_6 = F_2 ( V_4 , V_78 - 1 ) ;
V_6 -> V_69 = V_69 ;
V_74 -> V_8 = V_78 - V_77 ;
F_9 ( L_23 , V_74 -> V_8 ) ;
return V_74 -> V_8 ;
V_95:
while ( V_77 < V_78 ) {
V_6 = F_2 ( V_4 , V_77 ++ ) ;
F_3 ( V_2 , V_6 ) ;
}
F_9 ( L_24 ) ;
return 0 ;
}
void F_35 ( struct V_99 * V_100 )
{
F_9 ( L_25 ) ;
V_100 -> V_101 = F_14 ;
V_100 -> V_102 = F_8 ;
V_100 -> V_103 = F_27 ;
V_100 -> V_104 = F_22 ;
V_100 -> V_105 = F_3 ;
V_100 -> V_106 = F_23 ;
V_100 -> V_107 = F_24 ;
F_9 ( L_26 ) ;
}

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
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ ) {
V_21 = V_2 -> V_21 [ V_7 ] ;
F_1 ( V_2 , V_21 -> V_23 ) ;
F_1 ( V_2 , V_21 -> V_24 ) ;
}
F_9 ( L_2 ) ;
}
static void * F_10 ( T_1 V_25 , int V_26 )
{
void * V_27 ;
V_27 = F_11 ( V_25 , V_28 , V_26 ) ;
if ( ! V_27 )
V_27 = F_12 ( V_25 , V_28 ) ;
return V_27 ;
}
static void * F_13 ( struct V_29 * V_11 , T_1 V_25 ,
T_2 * V_30 , int V_26 )
{
void * V_27 ;
int V_31 = F_14 ( V_11 ) ;
F_15 ( V_11 , V_26 ) ;
V_27 = F_16 ( V_11 , V_25 , V_30 , V_28 ) ;
F_15 ( V_11 , V_31 ) ;
if ( ! V_27 )
V_27 = F_16 ( V_11 , V_25 , V_30 , V_28 ) ;
return V_27 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned int V_8 )
{
T_1 V_25 ;
if ( ! V_4 )
return 0 ;
V_25 = V_8 * sizeof( struct V_18 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_17 = F_13 ( V_2 -> V_11 , V_25 , & V_4 -> V_19 ,
V_4 -> V_26 ) ;
if ( ! V_4 -> V_17 )
return - V_32 ;
V_25 = V_8 * sizeof( struct V_5 ) ;
V_4 -> V_6 = F_10 ( V_25 , V_4 -> V_26 ) ;
if ( ! V_4 -> V_6 )
return - V_32 ;
F_18 ( V_2 , V_33 , V_2 -> V_34 ,
L_3 ,
V_4 -> V_17 , & V_4 -> V_19 , V_4 -> V_6 , V_4 -> V_26 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
unsigned int V_7 ;
int V_35 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ ) {
V_21 = V_2 -> V_21 [ V_7 ] ;
F_18 ( V_2 , V_33 , V_2 -> V_34 , L_4 ,
V_21 -> V_36 ) ;
V_35 = F_17 ( V_2 , V_21 -> V_23 ,
V_2 -> V_37 ) ;
if ( V_35 ) {
F_20 ( V_2 -> V_34 ,
L_5 ) ;
goto V_38;
}
F_18 ( V_2 , V_33 , V_2 -> V_34 , L_6 ,
V_21 -> V_36 ) ;
V_35 = F_17 ( V_2 , V_21 -> V_24 ,
V_2 -> V_39 ) ;
if ( V_35 ) {
F_20 ( V_2 -> V_34 ,
L_7 ) ;
goto V_38;
}
}
return 0 ;
V_38:
F_8 ( V_2 ) ;
return V_35 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_40 * V_41 , int V_42 ,
int V_26 )
{
struct V_43 * V_10 = NULL ;
T_2 V_12 ;
T_3 V_44 ;
int V_45 , V_35 ;
V_46:
V_45 = V_42 ;
V_44 = V_47 | V_48 | V_49 | V_50 ;
while ( V_45 >= 0 ) {
V_10 = F_22 ( V_26 , V_44 , V_45 ) ;
if ( V_10 )
break;
V_45 -- ;
}
if ( ! V_10 && ( V_26 != V_51 ) ) {
V_26 = V_51 ;
goto V_46;
}
if ( ! V_10 )
return - V_32 ;
V_12 = F_23 ( V_2 -> V_11 , V_10 , 0 ,
V_52 << V_45 , V_14 ) ;
V_35 = F_24 ( V_2 -> V_11 , V_12 ) ;
if ( V_35 ) {
F_6 ( V_10 ) ;
return V_35 ;
}
V_41 -> V_10 = V_10 ;
V_41 -> V_13 = V_52 << V_45 ;
V_41 -> V_15 = 0 ;
V_41 -> V_12 = V_12 ;
return 0 ;
}
static void F_25 ( struct V_53 * V_54 ,
struct V_40 * V_41 ,
unsigned int V_55 )
{
F_26 ( V_41 -> V_10 ) ;
V_54 -> V_41 = * V_41 ;
V_54 -> V_56 = V_41 -> V_12 ;
V_54 -> V_57 = V_41 -> V_15 ;
V_54 -> V_58 = V_55 ;
V_41 -> V_15 += V_55 ;
if ( ( V_41 -> V_15 + V_55 ) > V_41 -> V_13 ) {
V_54 -> V_59 = * V_41 ;
V_41 -> V_10 = NULL ;
V_41 -> V_13 = 0 ;
V_41 -> V_15 = 0 ;
V_41 -> V_12 = 0 ;
}
}
static int F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_35 ;
if ( ! V_4 -> V_9 . V_10 ) {
V_35 = F_21 ( V_2 , & V_4 -> V_9 , 0 , V_4 -> V_26 ) ;
if ( V_35 )
return V_35 ;
}
if ( ! V_4 -> V_16 . V_10 ) {
V_35 = F_21 ( V_2 , & V_4 -> V_16 ,
V_60 , V_4 -> V_26 ) ;
if ( V_35 )
return V_35 ;
}
F_25 ( & V_6 -> V_61 . V_62 , & V_4 -> V_9 ,
V_63 ) ;
F_25 ( & V_6 -> V_61 . V_64 , & V_4 -> V_16 ,
V_2 -> V_65 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = & V_2 -> V_67 ;
struct V_20 * V_21 ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_18 * V_17 ;
T_2 V_19 ;
unsigned int V_7 , V_68 ;
F_9 ( L_8 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ ) {
V_21 = V_2 -> V_21 [ V_7 ] ;
V_4 = V_21 -> V_23 ;
if ( ! V_4 )
break;
V_17 = V_4 -> V_17 ;
V_19 = V_4 -> V_19 ;
for ( V_68 = 0 ; V_68 < V_4 -> V_8 ; V_68 ++ ) {
V_6 = F_2 ( V_4 , V_68 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_19 = V_19 ;
V_17 ++ ;
V_19 += sizeof( struct V_18 ) ;
}
V_4 -> V_69 = 0 ;
V_4 -> V_70 = 0 ;
memset ( & V_4 -> V_71 , 0 , sizeof( V_4 -> V_71 ) ) ;
V_67 -> V_72 ( V_21 ) ;
}
F_9 ( L_9 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = & V_2 -> V_67 ;
struct V_20 * V_21 ;
struct V_3 * V_4 ;
struct V_18 * V_17 ;
struct V_5 * V_6 ;
T_2 V_19 ;
unsigned int V_7 , V_68 ;
F_9 ( L_10 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_22 ; V_7 ++ ) {
V_21 = V_2 -> V_21 [ V_7 ] ;
V_4 = V_21 -> V_24 ;
if ( ! V_4 )
break;
V_17 = V_4 -> V_17 ;
V_19 = V_4 -> V_19 ;
for ( V_68 = 0 ; V_68 < V_4 -> V_8 ; V_68 ++ ) {
V_6 = F_2 ( V_4 , V_68 ) ;
V_6 -> V_17 = V_17 ;
V_6 -> V_19 = V_19 ;
if ( F_27 ( V_2 , V_4 , V_6 ) )
break;
V_17 ++ ;
V_19 += sizeof( struct V_18 ) ;
}
V_4 -> V_69 = 0 ;
V_4 -> V_70 = 0 ;
V_67 -> V_73 ( V_21 ) ;
}
F_9 ( L_11 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
if ( V_6 -> V_74 ) {
if ( V_6 -> V_75 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_74 ,
V_6 -> V_76 , V_77 ) ;
} else {
F_30 ( V_2 -> V_11 , V_6 -> V_74 ,
V_6 -> V_76 , V_77 ) ;
}
V_6 -> V_74 = 0 ;
V_6 -> V_76 = 0 ;
}
if ( V_6 -> V_78 ) {
F_31 ( V_6 -> V_78 ) ;
V_6 -> V_78 = NULL ;
}
if ( V_6 -> V_61 . V_62 . V_41 . V_10 )
F_6 ( V_6 -> V_61 . V_62 . V_41 . V_10 ) ;
if ( V_6 -> V_61 . V_62 . V_59 . V_10 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_61 . V_62 . V_59 . V_12 ,
V_6 -> V_61 . V_62 . V_59 . V_13 ,
V_14 ) ;
F_6 ( V_6 -> V_61 . V_62 . V_59 . V_10 ) ;
}
if ( V_6 -> V_61 . V_64 . V_41 . V_10 )
F_6 ( V_6 -> V_61 . V_64 . V_41 . V_10 ) ;
if ( V_6 -> V_61 . V_64 . V_59 . V_10 ) {
F_5 ( V_2 -> V_11 , V_6 -> V_61 . V_64 . V_59 . V_12 ,
V_6 -> V_61 . V_64 . V_59 . V_13 ,
V_14 ) ;
F_6 ( V_6 -> V_61 . V_64 . V_59 . V_10 ) ;
}
memset ( & V_6 -> V_71 , 0 , sizeof( V_6 -> V_71 ) ) ;
memset ( & V_6 -> V_61 , 0 , sizeof( V_6 -> V_61 ) ) ;
V_6 -> V_75 = 0 ;
if ( V_6 -> V_79 ) {
V_6 -> V_79 = 0 ;
V_6 -> V_80 . V_78 = NULL ;
V_6 -> V_80 . V_55 = 0 ;
V_6 -> V_80 . error = 0 ;
}
}
static int F_32 ( struct V_20 * V_21 , struct V_81 * V_78 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_21 -> V_23 ;
struct V_5 * V_6 ;
struct V_82 * V_83 ;
struct V_84 * V_85 ;
T_2 V_74 ;
unsigned int V_86 , V_87 ;
unsigned int V_88 , V_89 , V_90 , V_91 , V_55 ;
unsigned int V_7 ;
F_9 ( L_12 , V_4 -> V_69 ) ;
V_88 = 0 ;
V_86 = V_4 -> V_69 ;
V_87 = V_4 -> V_69 ;
V_83 = & V_4 -> V_92 ;
V_83 -> V_8 = 0 ;
V_83 -> V_93 = 0 ;
V_89 = F_33 ( V_83 -> V_94 , V_95 ,
V_96 ) ;
V_90 = F_33 ( V_83 -> V_94 , V_95 ,
V_97 ) ;
if ( ( V_89 && ( V_83 -> V_98 != V_4 -> V_71 . V_99 ) ) ||
( V_90 && ( V_83 -> V_100 != V_4 -> V_71 . V_101 ) ) )
V_87 ++ ;
V_6 = F_2 ( V_4 , V_87 ) ;
if ( V_89 ) {
V_74 = F_34 ( V_2 -> V_11 , V_78 -> V_102 ,
V_83 -> V_103 , V_77 ) ;
if ( F_24 ( V_2 -> V_11 , V_74 ) ) {
F_20 ( V_2 -> V_34 , L_13 ) ;
goto V_104;
}
V_6 -> V_74 = V_74 ;
V_6 -> V_76 = V_83 -> V_103 ;
F_18 ( V_2 , V_105 , V_2 -> V_34 ,
L_14 ,
V_87 , & V_74 , V_83 -> V_103 ) ;
V_88 = V_83 -> V_103 ;
V_83 -> V_93 += V_83 -> V_103 ;
V_87 ++ ;
V_6 = F_2 ( V_4 , V_87 ) ;
}
for ( V_91 = F_35 ( V_78 ) - V_88 ; V_91 ; ) {
V_55 = F_36 (unsigned int, datalen, XGBE_TX_MAX_BUF_SIZE) ;
V_74 = F_34 ( V_2 -> V_11 , V_78 -> V_102 + V_88 , V_55 ,
V_77 ) ;
if ( F_24 ( V_2 -> V_11 , V_74 ) ) {
F_20 ( V_2 -> V_34 , L_13 ) ;
goto V_104;
}
V_6 -> V_74 = V_74 ;
V_6 -> V_76 = V_55 ;
F_18 ( V_2 , V_105 , V_2 -> V_34 ,
L_15 ,
V_87 , & V_74 , V_55 ) ;
V_91 -= V_55 ;
V_88 += V_55 ;
V_83 -> V_93 += V_55 ;
V_87 ++ ;
V_6 = F_2 ( V_4 , V_87 ) ;
}
for ( V_7 = 0 ; V_7 < F_37 ( V_78 ) -> V_106 ; V_7 ++ ) {
F_18 ( V_2 , V_105 , V_2 -> V_34 ,
L_16 , V_7 ) ;
V_85 = & F_37 ( V_78 ) -> V_107 [ V_7 ] ;
V_88 = 0 ;
for ( V_91 = F_38 ( V_85 ) ; V_91 ; ) {
V_55 = F_36 (unsigned int, datalen,
XGBE_TX_MAX_BUF_SIZE) ;
V_74 = F_39 ( V_2 -> V_11 , V_85 , V_88 ,
V_55 , V_77 ) ;
if ( F_24 ( V_2 -> V_11 , V_74 ) ) {
F_20 ( V_2 -> V_34 ,
L_17 ) ;
goto V_104;
}
V_6 -> V_74 = V_74 ;
V_6 -> V_76 = V_55 ;
V_6 -> V_75 = 1 ;
F_18 ( V_2 , V_105 , V_2 -> V_34 ,
L_18 ,
V_87 , & V_74 , V_55 ) ;
V_91 -= V_55 ;
V_88 += V_55 ;
V_83 -> V_93 += V_55 ;
V_87 ++ ;
V_6 = F_2 ( V_4 , V_87 ) ;
}
}
V_6 = F_2 ( V_4 , V_87 - 1 ) ;
V_6 -> V_78 = V_78 ;
V_83 -> V_8 = V_87 - V_86 ;
F_9 ( L_19 , V_83 -> V_8 ) ;
return V_83 -> V_8 ;
V_104:
while ( V_86 < V_87 ) {
V_6 = F_2 ( V_4 , V_86 ++ ) ;
F_3 ( V_2 , V_6 ) ;
}
F_9 ( L_20 ) ;
return 0 ;
}
void F_40 ( struct V_108 * V_109 )
{
F_9 ( L_21 ) ;
V_109 -> V_110 = F_19 ;
V_109 -> V_111 = F_8 ;
V_109 -> V_112 = F_32 ;
V_109 -> V_113 = F_27 ;
V_109 -> V_114 = F_3 ;
V_109 -> V_115 = F_28 ;
V_109 -> V_116 = F_29 ;
F_9 ( L_22 ) ;
}

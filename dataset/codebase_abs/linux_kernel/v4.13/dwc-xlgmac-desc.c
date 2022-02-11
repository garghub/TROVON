static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_5 ) {
if ( V_4 -> V_6 ) {
F_2 ( V_2 -> V_7 , V_4 -> V_5 ,
V_4 -> V_8 , V_9 ) ;
} else {
F_3 ( V_2 -> V_7 , V_4 -> V_5 ,
V_4 -> V_8 , V_9 ) ;
}
V_4 -> V_5 = 0 ;
V_4 -> V_8 = 0 ;
}
if ( V_4 -> V_10 ) {
F_4 ( V_4 -> V_10 ) ;
V_4 -> V_10 = NULL ;
}
if ( V_4 -> V_11 . V_12 . V_13 . V_14 )
F_5 ( V_4 -> V_11 . V_12 . V_13 . V_14 ) ;
if ( V_4 -> V_11 . V_12 . V_15 . V_14 ) {
F_2 ( V_2 -> V_7 , V_4 -> V_11 . V_12 . V_15 . V_16 ,
V_4 -> V_11 . V_12 . V_15 . V_17 ,
V_18 ) ;
F_5 ( V_4 -> V_11 . V_12 . V_15 . V_14 ) ;
}
if ( V_4 -> V_11 . V_19 . V_13 . V_14 )
F_5 ( V_4 -> V_11 . V_19 . V_13 . V_14 ) ;
if ( V_4 -> V_11 . V_19 . V_15 . V_14 ) {
F_2 ( V_2 -> V_7 , V_4 -> V_11 . V_19 . V_15 . V_16 ,
V_4 -> V_11 . V_19 . V_15 . V_17 ,
V_18 ) ;
F_5 ( V_4 -> V_11 . V_19 . V_15 . V_14 ) ;
}
memset ( & V_4 -> V_20 , 0 , sizeof( V_4 -> V_20 ) ) ;
memset ( & V_4 -> V_11 , 0 , sizeof( V_4 -> V_11 ) ) ;
V_4 -> V_6 = 0 ;
if ( V_4 -> V_21 ) {
V_4 -> V_21 = 0 ;
V_4 -> V_22 . V_10 = NULL ;
V_4 -> V_22 . V_23 = 0 ;
V_4 -> V_22 . error = 0 ;
}
}
static void F_6 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 ;
unsigned int V_26 ;
if ( ! V_25 )
return;
if ( V_25 -> V_27 ) {
for ( V_26 = 0 ; V_26 < V_25 -> V_28 ; V_26 ++ ) {
V_4 = F_7 ( V_25 , V_26 ) ;
F_1 ( V_2 , V_4 ) ;
}
F_8 ( V_25 -> V_27 ) ;
V_25 -> V_27 = NULL ;
}
if ( V_25 -> V_29 . V_14 ) {
F_2 ( V_2 -> V_7 , V_25 -> V_29 . V_16 ,
V_25 -> V_29 . V_17 , V_18 ) ;
F_5 ( V_25 -> V_29 . V_14 ) ;
V_25 -> V_29 . V_14 = NULL ;
V_25 -> V_29 . V_17 = 0 ;
V_25 -> V_29 . V_30 = 0 ;
V_25 -> V_29 . V_16 = 0 ;
}
if ( V_25 -> V_31 . V_14 ) {
F_2 ( V_2 -> V_7 , V_25 -> V_31 . V_16 ,
V_25 -> V_31 . V_17 , V_18 ) ;
F_5 ( V_25 -> V_31 . V_14 ) ;
V_25 -> V_31 . V_14 = NULL ;
V_25 -> V_31 . V_17 = 0 ;
V_25 -> V_31 . V_30 = 0 ;
V_25 -> V_31 . V_16 = 0 ;
}
if ( V_25 -> V_32 ) {
F_9 ( V_2 -> V_7 ,
( sizeof( struct V_33 ) *
V_25 -> V_28 ) ,
V_25 -> V_32 ,
V_25 -> V_34 ) ;
V_25 -> V_32 = NULL ;
}
}
static int F_10 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
unsigned int V_28 )
{
if ( ! V_25 )
return 0 ;
V_25 -> V_28 = V_28 ;
V_25 -> V_32 = F_11 ( V_2 -> V_7 ,
( sizeof( struct V_33 ) *
V_28 ) ,
& V_25 -> V_34 ,
V_35 ) ;
if ( ! V_25 -> V_32 )
return - V_36 ;
V_25 -> V_27 = F_12 ( V_28 ,
sizeof( struct V_3 ) ,
V_35 ) ;
if ( ! V_25 -> V_27 )
return - V_36 ;
F_13 ( V_2 , V_37 , V_2 -> V_38 ,
L_1 ,
V_25 -> V_32 ,
& V_25 -> V_34 ,
V_25 -> V_27 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
unsigned int V_26 ;
if ( ! V_2 -> V_41 )
return;
V_40 = V_2 -> V_41 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_42 ; V_26 ++ , V_40 ++ ) {
F_6 ( V_2 , V_40 -> V_43 ) ;
F_6 ( V_2 , V_40 -> V_44 ) ;
}
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
unsigned int V_26 ;
int V_45 ;
V_40 = V_2 -> V_41 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_42 ; V_26 ++ , V_40 ++ ) {
F_13 ( V_2 , V_37 , V_2 -> V_38 , L_2 ,
V_40 -> V_46 ) ;
V_45 = F_10 ( V_2 , V_40 -> V_43 ,
V_2 -> V_47 ) ;
if ( V_45 ) {
F_16 ( V_2 -> V_38 ,
L_3 ) ;
goto V_48;
}
F_13 ( V_2 , V_37 , V_2 -> V_38 , L_4 ,
V_40 -> V_46 ) ;
V_45 = F_10 ( V_2 , V_40 -> V_44 ,
V_2 -> V_49 ) ;
if ( V_45 ) {
F_16 ( V_2 -> V_38 ,
L_5 ) ;
goto V_48;
}
}
return 0 ;
V_48:
F_14 ( V_2 ) ;
return V_45 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_41 )
return;
F_8 ( V_2 -> V_41 -> V_43 ) ;
V_2 -> V_41 -> V_43 = NULL ;
F_8 ( V_2 -> V_41 -> V_44 ) ;
V_2 -> V_41 -> V_44 = NULL ;
F_8 ( V_2 -> V_41 ) ;
V_2 -> V_41 = NULL ;
V_2 -> V_42 = 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_39 * V_41 , * V_40 ;
struct V_24 * V_43 , * V_44 ;
int V_45 = - V_36 ;
unsigned int V_26 ;
V_41 = F_12 ( V_2 -> V_42 ,
sizeof( struct V_39 ) , V_35 ) ;
if ( ! V_41 )
return V_45 ;
F_13 ( V_2 , V_37 , V_2 -> V_38 ,
L_6 , V_41 ) ;
V_43 = F_12 ( V_2 -> V_50 , sizeof( struct V_24 ) ,
V_35 ) ;
if ( ! V_43 )
goto V_51;
V_44 = F_12 ( V_2 -> V_52 , sizeof( struct V_24 ) ,
V_35 ) ;
if ( ! V_44 )
goto V_53;
for ( V_26 = 0 , V_40 = V_41 ; V_26 < V_2 -> V_42 ;
V_26 ++ , V_40 ++ ) {
snprintf ( V_40 -> V_46 , sizeof( V_40 -> V_46 ) , L_7 , V_26 ) ;
V_40 -> V_2 = V_2 ;
V_40 -> V_54 = V_26 ;
V_40 -> V_55 = V_2 -> V_56 + V_57 +
( V_58 * V_26 ) ;
if ( V_2 -> V_59 ) {
V_45 = V_2 -> V_60 [ V_26 ] ;
if ( V_45 < 0 ) {
F_19 ( V_2 -> V_38 ,
L_8 ,
V_26 + 1 ) ;
goto V_61;
}
V_40 -> V_62 = V_45 ;
}
if ( V_26 < V_2 -> V_50 )
V_40 -> V_43 = V_43 ++ ;
if ( V_26 < V_2 -> V_52 )
V_40 -> V_44 = V_44 ++ ;
F_13 ( V_2 , V_37 , V_2 -> V_38 ,
L_9 ,
V_40 -> V_46 , V_40 -> V_55 ,
V_40 -> V_43 , V_40 -> V_44 ) ;
}
V_2 -> V_41 = V_41 ;
return 0 ;
V_61:
F_8 ( V_44 ) ;
V_53:
F_8 ( V_43 ) ;
V_51:
F_8 ( V_41 ) ;
return V_45 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_45 ;
V_45 = F_18 ( V_2 ) ;
if ( V_45 )
goto V_63;
V_45 = F_15 ( V_2 ) ;
if ( V_45 )
goto V_63;
return 0 ;
V_63:
F_20 ( V_2 ) ;
return V_45 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_64 * V_13 ,
T_1 V_65 , int V_66 )
{
struct V_67 * V_14 = NULL ;
T_2 V_16 ;
V_65 |= V_68 | V_69 | V_70 ;
while ( V_66 >= 0 ) {
V_14 = F_23 ( V_65 , V_66 ) ;
if ( V_14 )
break;
V_66 -- ;
}
if ( ! V_14 )
return - V_36 ;
V_16 = F_24 ( V_2 -> V_7 , V_14 , 0 ,
V_71 << V_66 , V_18 ) ;
if ( F_25 ( V_2 -> V_7 , V_16 ) ) {
F_5 ( V_14 ) ;
return - V_36 ;
}
V_13 -> V_14 = V_14 ;
V_13 -> V_17 = V_71 << V_66 ;
V_13 -> V_30 = 0 ;
V_13 -> V_16 = V_16 ;
return 0 ;
}
static void F_26 ( struct V_72 * V_73 ,
struct V_64 * V_13 ,
unsigned int V_23 )
{
F_27 ( V_13 -> V_14 ) ;
V_73 -> V_13 = * V_13 ;
V_73 -> V_74 = V_13 -> V_16 ;
V_73 -> V_75 = V_13 -> V_30 ;
V_73 -> V_76 = V_23 ;
V_13 -> V_30 += V_23 ;
if ( ( V_13 -> V_30 + V_23 ) > V_13 -> V_17 ) {
V_73 -> V_15 = * V_13 ;
V_13 -> V_14 = NULL ;
V_13 -> V_17 = 0 ;
V_13 -> V_30 = 0 ;
V_13 -> V_16 = 0 ;
}
}
static int F_28 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_3 * V_4 )
{
int V_66 , V_45 ;
if ( ! V_25 -> V_29 . V_14 ) {
V_45 = F_22 ( V_2 , & V_25 -> V_29 ,
V_77 , 0 ) ;
if ( V_45 )
return V_45 ;
}
if ( ! V_25 -> V_31 . V_14 ) {
V_66 = F_29 ( int , V_78 - 1 , 0 ) ;
V_45 = F_22 ( V_2 , & V_25 -> V_31 ,
V_77 , V_66 ) ;
if ( V_45 )
return V_45 ;
}
F_26 ( & V_4 -> V_11 . V_12 , & V_25 -> V_29 ,
V_79 ) ;
F_26 ( & V_4 -> V_11 . V_19 , & V_25 -> V_31 ,
V_2 -> V_80 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 ;
struct V_3 * V_4 ;
struct V_33 * V_83 ;
struct V_39 * V_40 ;
struct V_24 * V_25 ;
T_2 V_84 ;
unsigned int V_26 , V_85 ;
V_40 = V_2 -> V_41 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_42 ; V_26 ++ , V_40 ++ ) {
V_25 = V_40 -> V_43 ;
if ( ! V_25 )
break;
V_83 = V_25 -> V_32 ;
V_84 = V_25 -> V_34 ;
for ( V_85 = 0 ; V_85 < V_25 -> V_28 ; V_85 ++ ) {
V_4 = F_7 ( V_25 , V_85 ) ;
V_4 -> V_83 = V_83 ;
V_4 -> V_84 = V_84 ;
V_83 ++ ;
V_84 += sizeof( struct V_33 ) ;
}
V_25 -> V_86 = 0 ;
V_25 -> V_87 = 0 ;
memset ( & V_25 -> V_20 , 0 , sizeof( V_25 -> V_20 ) ) ;
V_82 -> V_88 ( V_40 ) ;
}
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 ;
struct V_3 * V_4 ;
struct V_33 * V_83 ;
struct V_39 * V_40 ;
struct V_24 * V_25 ;
T_2 V_84 ;
unsigned int V_26 , V_85 ;
V_40 = V_2 -> V_41 ;
for ( V_26 = 0 ; V_26 < V_2 -> V_42 ; V_26 ++ , V_40 ++ ) {
V_25 = V_40 -> V_44 ;
if ( ! V_25 )
break;
V_83 = V_25 -> V_32 ;
V_84 = V_25 -> V_34 ;
for ( V_85 = 0 ; V_85 < V_25 -> V_28 ; V_85 ++ ) {
V_4 = F_7 ( V_25 , V_85 ) ;
V_4 -> V_83 = V_83 ;
V_4 -> V_84 = V_84 ;
if ( F_28 ( V_2 , V_25 , V_4 ) )
break;
V_83 ++ ;
V_84 += sizeof( struct V_33 ) ;
}
V_25 -> V_86 = 0 ;
V_25 -> V_87 = 0 ;
V_82 -> V_89 ( V_40 ) ;
}
}
static int F_32 ( struct V_39 * V_40 ,
struct V_90 * V_10 )
{
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_24 * V_25 = V_40 -> V_43 ;
unsigned int V_91 , V_92 ;
struct V_3 * V_4 ;
unsigned int V_93 , V_94 , V_23 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
unsigned int V_99 , V_100 ;
T_2 V_5 ;
unsigned int V_26 ;
V_93 = 0 ;
V_91 = V_25 -> V_86 ;
V_92 = V_25 -> V_86 ;
V_96 = & V_25 -> V_96 ;
V_96 -> V_101 = 0 ;
V_96 -> V_102 = 0 ;
V_99 = F_33 ( V_96 -> V_103 ,
V_104 ,
V_105 ) ;
V_100 = F_33 ( V_96 -> V_103 ,
V_106 ,
V_107 ) ;
if ( ( V_99 && ( V_96 -> V_108 != V_25 -> V_20 . V_109 ) ) ||
( V_100 && ( V_96 -> V_110 != V_25 -> V_20 . V_111 ) ) )
V_92 ++ ;
V_4 = F_7 ( V_25 , V_92 ) ;
if ( V_99 ) {
V_5 = F_34 ( V_2 -> V_7 , V_10 -> V_112 ,
V_96 -> V_113 , V_9 ) ;
if ( F_25 ( V_2 -> V_7 , V_5 ) ) {
F_16 ( V_2 -> V_38 , L_10 ) ;
goto V_114;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_8 = V_96 -> V_113 ;
F_13 ( V_2 , V_115 , V_2 -> V_38 ,
L_11 ,
V_92 , & V_5 , V_96 -> V_113 ) ;
V_93 = V_96 -> V_113 ;
V_96 -> V_102 += V_96 -> V_113 ;
V_92 ++ ;
V_4 = F_7 ( V_25 , V_92 ) ;
}
for ( V_94 = F_35 ( V_10 ) - V_93 ; V_94 ; ) {
V_23 = F_36 (unsigned int, datalen, XLGMAC_TX_MAX_BUF_SIZE) ;
V_5 = F_34 ( V_2 -> V_7 , V_10 -> V_112 + V_93 , V_23 ,
V_9 ) ;
if ( F_25 ( V_2 -> V_7 , V_5 ) ) {
F_16 ( V_2 -> V_38 , L_10 ) ;
goto V_114;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_8 = V_23 ;
F_13 ( V_2 , V_115 , V_2 -> V_38 ,
L_12 ,
V_92 , & V_5 , V_23 ) ;
V_94 -= V_23 ;
V_93 += V_23 ;
V_96 -> V_102 += V_23 ;
V_92 ++ ;
V_4 = F_7 ( V_25 , V_92 ) ;
}
for ( V_26 = 0 ; V_26 < F_37 ( V_10 ) -> V_116 ; V_26 ++ ) {
F_13 ( V_2 , V_115 , V_2 -> V_38 ,
L_13 , V_26 ) ;
V_98 = & F_37 ( V_10 ) -> V_117 [ V_26 ] ;
V_93 = 0 ;
for ( V_94 = F_38 ( V_98 ) ; V_94 ; ) {
V_23 = F_36 (unsigned int, datalen,
XLGMAC_TX_MAX_BUF_SIZE) ;
V_5 = F_39 ( V_2 -> V_7 , V_98 , V_93 ,
V_23 , V_9 ) ;
if ( F_25 ( V_2 -> V_7 , V_5 ) ) {
F_16 ( V_2 -> V_38 ,
L_14 ) ;
goto V_114;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_8 = V_23 ;
V_4 -> V_6 = 1 ;
F_13 ( V_2 , V_115 , V_2 -> V_38 ,
L_15 ,
V_92 , & V_5 , V_23 ) ;
V_94 -= V_23 ;
V_93 += V_23 ;
V_96 -> V_102 += V_23 ;
V_92 ++ ;
V_4 = F_7 ( V_25 , V_92 ) ;
}
}
V_4 = F_7 ( V_25 , V_92 - 1 ) ;
V_4 -> V_10 = V_10 ;
V_96 -> V_101 = V_92 - V_91 ;
return V_96 -> V_101 ;
V_114:
while ( V_91 < V_92 ) {
V_4 = F_7 ( V_25 , V_91 ++ ) ;
F_1 ( V_2 , V_4 ) ;
}
return 0 ;
}
void F_40 ( struct V_118 * V_119 )
{
V_119 -> V_120 = F_21 ;
V_119 -> V_121 = F_20 ;
V_119 -> V_122 = F_32 ;
V_119 -> V_123 = F_28 ;
V_119 -> V_124 = F_1 ;
V_119 -> V_88 = F_30 ;
V_119 -> V_89 = F_31 ;
}

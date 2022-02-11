static inline T_1 F_1 ( T_1 T_2 * V_1 , unsigned int V_2 )
{
return F_2 ( V_1 + ( V_2 >> 2 ) ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
}
static void F_4 ( struct V_3 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_5 -> V_10 -> V_11 ;
T_3 V_12 = F_5 ( V_5 ) ;
int V_13 , V_14 ;
V_14 = ( V_12 >> V_9 -> V_15 ) & V_16 ;
V_13 = V_9 -> V_17 [ V_14 ] -> V_18 ;
F_6 ( V_7 , L_1 , V_13 ) ;
}
static int F_7 ( struct V_19 * V_20 , unsigned int V_18 ,
T_3 V_21 )
{
struct V_8 * V_9 = V_20 -> V_11 ;
struct V_22 * V_23 = & V_24 ;
F_8 ( V_18 , V_25 ) ;
F_9 ( V_18 , V_9 ) ;
F_10 ( V_18 , V_23 , V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 )
{
int V_27 , V_12 ;
V_27 = F_12 ( & V_9 -> V_28 , V_29 ,
V_9 -> V_30 -> V_31 ) ;
if ( V_27 )
return V_27 ;
for ( V_12 = 0 ; V_12 < V_29 ; V_12 ++ )
F_13 ( & V_9 -> V_28 , V_12 ) ;
return 0 ;
}
static void F_14 ( struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_8 * V_9 ;
F_15 (entry, &pdev->msi_list, list) {
if ( V_35 -> V_36 == V_37 )
continue;
V_9 = F_16 ( V_35 -> V_36 ) ;
F_17 ( V_35 -> V_36 , NULL ) ;
F_18 ( & V_9 -> V_28 ,
F_19 ( V_35 -> V_36 ) , 1 ) ;
F_20 ( V_35 -> V_36 ) ;
}
return;
}
static void F_21 ( struct V_32 * V_33 , int V_12 ,
struct V_38 * V_39 ,
struct V_8 * V_40 )
{
struct V_8 * V_9 = V_40 ;
struct V_41 * V_42 = F_22 ( V_33 -> V_43 ) ;
T_4 V_44 ;
int V_45 ;
const T_5 * V_2 ;
V_2 = F_23 ( V_42 -> V_46 , L_2 , & V_45 ) ;
if ( V_2 && ( V_45 == sizeof( T_4 ) ) )
V_44 = F_24 ( V_2 ) ;
else
V_44 = F_25 ( V_42 ) + V_9 -> V_47 ;
V_39 -> V_48 = F_26 ( V_44 ) ;
V_39 -> V_49 = F_27 ( V_44 ) ;
if ( V_9 -> V_50 & V_51 )
V_39 -> V_52 = F_28 ( V_12 ) ;
else
V_39 -> V_52 = V_12 ;
F_29 ( L_3 , V_53 ,
( V_12 >> V_9 -> V_15 ) & V_16 ,
( V_12 >> V_9 -> V_54 ) & V_55 ) ;
}
static int F_30 ( struct V_32 * V_33 , int V_56 , int type )
{
struct V_41 * V_42 = F_22 ( V_33 -> V_43 ) ;
struct V_57 * V_58 ;
T_6 T_6 = 0 ;
int V_27 , V_12 = - V_59 ;
unsigned int V_18 ;
struct V_34 * V_35 ;
struct V_38 V_39 ;
struct V_8 * V_9 ;
if ( type == V_60 ) {
F_15 (msi_data, &msi_head, list)
if ( V_9 -> V_50 & V_51 )
return - V_61 ;
}
V_58 = F_31 ( V_42 -> V_46 , L_4 , 0 ) ;
if ( V_58 ) {
if ( F_32 ( V_58 , L_5 ) ||
F_32 ( V_58 , L_6 ) ||
F_32 ( V_58 , L_7 ) )
T_6 = V_58 -> T_6 ;
else {
F_33 ( & V_33 -> V_62 ,
L_8 ,
V_42 -> V_46 -> V_63 , V_58 -> T_6 ) ;
return - V_61 ;
}
}
F_15 (entry, &pdev->msi_list, list) {
F_15 (msi_data, &msi_head, list) {
if ( T_6 && ( T_6 != V_9 -> T_6 ) )
continue;
V_12 = F_34 ( & V_9 -> V_28 , 1 ) ;
if ( V_12 >= 0 )
break;
}
if ( V_12 < 0 ) {
V_27 = V_12 ;
F_33 ( & V_33 -> V_62 , L_9 ) ;
goto V_64;
}
V_18 = F_35 ( V_9 -> V_30 , V_12 ) ;
if ( V_18 == V_37 ) {
F_33 ( & V_33 -> V_62 , L_10 , V_12 ) ;
F_18 ( & V_9 -> V_28 , V_12 , 1 ) ;
V_27 = - V_65 ;
goto V_64;
}
F_17 ( V_18 , V_35 ) ;
F_21 ( V_33 , V_12 , & V_39 , V_9 ) ;
F_36 ( V_18 , & V_39 ) ;
}
return 0 ;
V_64:
return V_27 ;
}
static T_7 F_37 ( int V_36 , void * V_52 )
{
unsigned int V_66 ;
struct V_8 * V_9 ;
int V_67 = - 1 ;
T_1 V_68 = 0 ;
T_1 V_69 ;
T_1 V_70 = 0 ;
struct V_71 * V_72 = V_52 ;
T_7 V_73 = V_74 ;
V_9 = V_72 -> V_9 ;
V_67 = V_72 -> V_75 ;
if ( V_67 >= V_76 )
V_66 = V_37 ;
switch ( V_9 -> V_50 & V_77 ) {
case V_78 :
V_68 = F_1 ( V_9 -> V_79 ,
V_67 * 0x10 ) ;
break;
case V_80 :
V_68 = F_1 ( V_9 -> V_79 , V_67 * 0x4 ) ;
break;
#ifdef F_38
case V_81 : {
unsigned int V_73 ;
V_73 = F_39 ( F_19 ( V_36 ) , & V_68 ) ;
if ( V_73 ) {
F_40 ( L_11
L_12 , V_36 , V_73 ) ;
V_68 = 0 ;
}
break;
}
#endif
}
while ( V_68 ) {
V_69 = F_41 ( V_68 ) - 1 ;
V_66 = F_42 ( V_9 -> V_30 ,
F_43 ( V_9 , V_67 ,
V_69 + V_70 ) ) ;
if ( V_66 != V_37 ) {
F_44 ( V_66 ) ;
V_73 = V_82 ;
}
V_70 += V_69 + 1 ;
V_68 = V_68 >> ( V_69 + 1 ) ;
}
return V_73 ;
}
static int F_45 ( struct V_83 * V_84 )
{
struct V_8 * V_85 = F_46 ( V_84 ) ;
int V_18 , V_86 ;
if ( V_85 -> V_87 . V_88 != NULL )
F_47 ( & V_85 -> V_87 ) ;
for ( V_86 = 0 ; V_86 < V_76 ; V_86 ++ ) {
if ( V_85 -> V_17 [ V_86 ] ) {
V_18 = V_85 -> V_17 [ V_86 ] -> V_18 ;
F_48 ( V_18 == V_37 ) ;
F_49 ( V_18 , V_85 -> V_17 [ V_86 ] ) ;
F_50 ( V_85 -> V_17 [ V_86 ] ) ;
F_20 ( V_18 ) ;
}
}
if ( V_85 -> V_28 . V_28 )
F_51 ( & V_85 -> V_28 ) ;
if ( ( V_85 -> V_50 & V_77 ) != V_81 )
F_52 ( V_85 -> V_79 ) ;
F_50 ( V_85 ) ;
return 0 ;
}
static int F_53 ( struct V_8 * V_85 , struct V_83 * V_62 ,
int V_89 , int V_90 )
{
struct V_71 * V_72 = NULL ;
int V_91 , V_86 , V_73 ;
V_91 = F_54 ( V_62 -> V_62 . V_31 , V_90 ) ;
if ( V_91 == V_37 ) {
F_33 ( & V_62 -> V_62 , L_13 ,
V_53 , V_90 ) ;
return 0 ;
}
V_72 = F_55 ( sizeof( struct V_71 ) , V_92 ) ;
if ( ! V_72 ) {
F_33 ( & V_62 -> V_62 , L_14 ) ;
return - V_59 ;
}
F_56 ( V_91 , & V_93 ) ;
V_72 -> V_75 = V_89 ;
V_72 -> V_9 = V_85 ;
V_72 -> V_18 = V_91 ;
V_85 -> V_17 [ V_90 ] = V_72 ;
V_73 = F_57 ( V_91 , F_37 , V_94 ,
L_15 , V_72 ) ;
if ( V_73 ) {
F_33 ( & V_62 -> V_62 , L_16 ,
V_91 , V_73 ) ;
return V_73 ;
}
for ( V_86 = 0 ; V_86 < V_95 ; V_86 ++ )
F_18 ( & V_85 -> V_28 ,
F_43 ( V_85 , V_89 , V_86 ) , 1 ) ;
return 0 ;
}
static int F_58 ( struct V_83 * V_62 )
{
const struct V_96 * V_97 ;
struct V_8 * V_85 ;
struct V_98 V_99 , V_100 ;
int V_101 , V_86 , V_102 , V_90 , V_103 ;
const T_1 * V_7 ;
const struct V_104 * V_105 ;
int V_45 ;
T_1 V_89 ;
struct V_41 * V_106 ;
V_97 = F_59 ( V_107 , & V_62 -> V_62 ) ;
if ( ! V_97 )
return - V_61 ;
V_105 = V_97 -> V_52 ;
F_60 ( V_108 L_17 ) ;
V_85 = F_55 ( sizeof( struct V_8 ) , V_92 ) ;
if ( ! V_85 ) {
F_33 ( & V_62 -> V_62 , L_18 ) ;
return - V_59 ;
}
F_61 ( V_62 , V_85 ) ;
V_85 -> V_30 = F_62 ( V_62 -> V_62 . V_31 ,
V_29 , & V_109 , V_85 ) ;
if ( V_85 -> V_30 == NULL ) {
F_33 ( & V_62 -> V_62 , L_19 ) ;
V_101 = - V_59 ;
goto V_110;
}
if ( ( V_105 -> V_111 & V_77 ) != V_81 ) {
V_101 = F_63 ( V_62 -> V_62 . V_31 , 0 , & V_99 ) ;
if ( V_101 ) {
F_33 ( & V_62 -> V_62 , L_20 ,
V_62 -> V_62 . V_31 -> V_63 ) ;
goto V_110;
}
V_85 -> V_79 = F_64 ( V_99 . V_112 , F_65 ( & V_99 ) ) ;
if ( ! V_85 -> V_79 ) {
V_101 = - V_59 ;
F_33 ( & V_62 -> V_62 , L_21 ,
V_62 -> V_62 . V_31 -> V_63 ) ;
goto V_110;
}
V_85 -> V_47 =
V_105 -> V_47 + ( V_99 . V_112 & 0xfffff ) ;
if ( F_63 ( V_62 -> V_62 . V_31 , 1 , & V_100 ) )
V_85 -> V_47 = V_105 -> V_47 +
( V_99 . V_112 & V_113 ) ;
else
V_85 -> V_47 = V_100 . V_112 & V_113 ;
}
V_85 -> V_50 = V_105 -> V_111 ;
if ( ( V_105 -> V_111 & V_77 ) == V_78
&& ( F_66 () == 0x0200 ) )
V_85 -> V_50 |= V_51 ;
V_85 -> T_6 = V_62 -> V_62 . V_31 -> T_6 ;
V_101 = F_11 ( V_85 ) ;
if ( V_101 ) {
F_33 ( & V_62 -> V_62 , L_22 ) ;
goto V_110;
}
V_7 = F_23 ( V_62 -> V_62 . V_31 , L_23 , & V_45 ) ;
if ( F_32 ( V_62 -> V_62 . V_31 , L_24 ) ||
F_32 ( V_62 -> V_62 . V_31 , L_7 ) ) {
V_85 -> V_15 = V_114 ;
V_85 -> V_54 = V_115 ;
if ( V_7 )
F_67 ( & V_62 -> V_62 , L_25 ,
V_53 ) ;
for ( V_90 = 0 ; V_90 < V_116 ;
V_90 ++ ) {
V_101 = F_53 ( V_85 , V_62 ,
V_90 , V_90 ) ;
if ( V_101 )
goto V_110;
}
} else {
static const T_1 V_117 [] =
{ 0 , V_118 * V_95 } ;
V_85 -> V_15 = V_119 ;
V_85 -> V_54 = V_120 ;
if ( V_7 && V_45 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_33 ( & V_62 -> V_62 , L_26 ,
V_53 ) ;
V_101 = - V_61 ;
goto V_110;
}
if ( ! V_7 ) {
V_7 = V_117 ;
V_45 = sizeof( V_117 ) ;
}
for ( V_90 = 0 , V_86 = 0 ; V_86 < V_45 / ( 2 * sizeof( T_1 ) ) ; V_86 ++ ) {
if ( V_7 [ V_86 * 2 ] % V_95 ||
V_7 [ V_86 * 2 + 1 ] % V_95 ) {
F_68 ( L_27 ,
V_53 , V_62 -> V_62 . V_31 -> V_63 ,
V_7 [ V_86 * 2 + 1 ] , V_7 [ V_86 * 2 ] ) ;
V_101 = - V_61 ;
goto V_110;
}
V_89 = V_7 [ V_86 * 2 ] / V_95 ;
V_103 = V_7 [ V_86 * 2 + 1 ] / V_95 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ , V_90 ++ ) {
V_101 = F_53 ( V_85 , V_62 , V_89 + V_102 ,
V_90 ) ;
if ( V_101 )
goto V_110;
}
}
}
F_69 ( & V_85 -> V_87 , & V_121 ) ;
F_15 (phb, &hose_list, list_node) {
if ( ! V_106 -> V_122 . V_123 ) {
V_106 -> V_122 . V_123 = F_30 ;
V_106 -> V_122 . V_124 = F_14 ;
} else if ( V_106 -> V_122 . V_123 != F_30 ) {
F_33 ( & V_62 -> V_62 , L_28 ) ;
V_101 = - V_125 ;
goto V_110;
}
}
return 0 ;
V_110:
F_45 ( V_62 ) ;
return V_101 ;
}
static T_8 int F_70 ( void )
{
return F_71 ( & V_126 ) ;
}

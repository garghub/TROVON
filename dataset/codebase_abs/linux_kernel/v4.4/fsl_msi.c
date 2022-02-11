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
F_13 ( V_9 -> V_30 ) ) ;
if ( V_27 )
return V_27 ;
for ( V_12 = 0 ; V_12 < V_29 ; V_12 ++ )
F_14 ( & V_9 -> V_28 , V_12 ) ;
return 0 ;
}
static void F_15 ( struct V_31 * V_32 )
{
struct V_33 * V_34 ;
struct V_8 * V_9 ;
T_3 V_12 ;
F_16 (entry, pdev) {
if ( V_34 -> V_35 == V_36 )
continue;
V_12 = F_17 ( V_34 -> V_35 ) ;
V_9 = F_18 ( V_34 -> V_35 ) ;
F_19 ( V_34 -> V_35 , NULL ) ;
F_20 ( V_34 -> V_35 ) ;
F_21 ( & V_9 -> V_28 , V_12 , 1 ) ;
}
return;
}
static void F_22 ( struct V_31 * V_32 , int V_12 ,
struct V_37 * V_38 ,
struct V_8 * V_39 )
{
struct V_8 * V_9 = V_39 ;
struct V_40 * V_41 = F_23 ( V_32 -> V_42 ) ;
T_4 V_43 ;
int V_44 ;
const T_5 * V_2 ;
V_2 = F_24 ( V_41 -> V_45 , L_2 , & V_44 ) ;
if ( V_2 && ( V_44 == sizeof( T_4 ) ) )
V_43 = F_25 ( V_2 ) ;
else
V_43 = F_26 ( V_41 ) + V_9 -> V_46 ;
V_38 -> V_47 = F_27 ( V_43 ) ;
V_38 -> V_48 = F_28 ( V_43 ) ;
if ( V_9 -> V_49 & V_50 )
V_38 -> V_51 = F_29 ( V_12 ) ;
else
V_38 -> V_51 = V_12 ;
F_30 ( L_3 , V_52 ,
( V_12 >> V_9 -> V_15 ) & V_16 ,
( V_12 >> V_9 -> V_53 ) & V_54 ) ;
}
static int F_31 ( struct V_31 * V_32 , int V_55 , int type )
{
struct V_40 * V_41 = F_23 ( V_32 -> V_42 ) ;
struct V_56 * V_57 ;
T_6 T_6 = 0 ;
int V_27 , V_12 = - V_58 ;
unsigned int V_18 ;
struct V_33 * V_34 ;
struct V_37 V_38 ;
struct V_8 * V_9 ;
if ( type == V_59 ) {
F_32 (msi_data, &msi_head, list)
if ( V_9 -> V_49 & V_50 )
return - V_60 ;
}
V_57 = F_33 ( V_41 -> V_45 , L_4 , 0 ) ;
if ( V_57 ) {
if ( F_34 ( V_57 , L_5 ) ||
F_34 ( V_57 , L_6 ) ||
F_34 ( V_57 , L_7 ) )
T_6 = V_57 -> T_6 ;
else {
F_35 ( & V_32 -> V_61 ,
L_8 ,
V_41 -> V_45 -> V_62 , V_57 -> T_6 ) ;
return - V_60 ;
}
}
F_16 (entry, pdev) {
F_32 (msi_data, &msi_head, list) {
if ( T_6 && ( T_6 != V_9 -> T_6 ) )
continue;
V_12 = F_36 ( & V_9 -> V_28 , 1 ) ;
if ( V_12 >= 0 )
break;
}
if ( V_12 < 0 ) {
V_27 = V_12 ;
F_35 ( & V_32 -> V_61 , L_9 ) ;
goto V_63;
}
V_18 = F_37 ( V_9 -> V_30 , V_12 ) ;
if ( V_18 == V_36 ) {
F_35 ( & V_32 -> V_61 , L_10 , V_12 ) ;
F_21 ( & V_9 -> V_28 , V_12 , 1 ) ;
V_27 = - V_64 ;
goto V_63;
}
F_19 ( V_18 , V_34 ) ;
F_22 ( V_32 , V_12 , & V_38 , V_9 ) ;
F_38 ( V_18 , & V_38 ) ;
}
return 0 ;
V_63:
return V_27 ;
}
static T_7 F_39 ( int V_35 , void * V_51 )
{
unsigned int V_65 ;
struct V_8 * V_9 ;
int V_66 = - 1 ;
T_1 V_67 = 0 ;
T_1 V_68 ;
T_1 V_69 = 0 ;
struct V_70 * V_71 = V_51 ;
T_7 V_72 = V_73 ;
V_9 = V_71 -> V_9 ;
V_66 = V_71 -> V_74 ;
if ( V_66 >= V_75 )
V_65 = V_36 ;
switch ( V_9 -> V_49 & V_76 ) {
case V_77 :
V_67 = F_1 ( V_9 -> V_78 ,
V_66 * 0x10 ) ;
break;
case V_79 :
V_67 = F_1 ( V_9 -> V_78 , V_66 * 0x4 ) ;
break;
#ifdef F_40
case V_80 : {
unsigned int V_72 ;
V_72 = F_41 ( F_17 ( V_35 ) , & V_67 ) ;
if ( V_72 ) {
F_42 ( L_11
L_12 , V_35 , V_72 ) ;
V_67 = 0 ;
}
break;
}
#endif
}
while ( V_67 ) {
V_68 = F_43 ( V_67 ) - 1 ;
V_65 = F_44 ( V_9 -> V_30 ,
F_45 ( V_9 , V_66 ,
V_68 + V_69 ) ) ;
if ( V_65 != V_36 ) {
F_46 ( V_65 ) ;
V_72 = V_81 ;
}
V_69 += V_68 + 1 ;
V_67 = V_67 >> ( V_68 + 1 ) ;
}
return V_72 ;
}
static int F_47 ( struct V_82 * V_83 )
{
struct V_8 * V_84 = F_48 ( V_83 ) ;
int V_18 , V_85 ;
if ( V_84 -> V_86 . V_87 != NULL )
F_49 ( & V_84 -> V_86 ) ;
for ( V_85 = 0 ; V_85 < V_75 ; V_85 ++ ) {
if ( V_84 -> V_17 [ V_85 ] ) {
V_18 = V_84 -> V_17 [ V_85 ] -> V_18 ;
F_50 ( V_18 == V_36 ) ;
F_51 ( V_18 , V_84 -> V_17 [ V_85 ] ) ;
F_52 ( V_84 -> V_17 [ V_85 ] ) ;
F_20 ( V_18 ) ;
}
}
if ( V_84 -> V_28 . V_28 )
F_53 ( & V_84 -> V_28 ) ;
if ( ( V_84 -> V_49 & V_76 ) != V_80 )
F_54 ( V_84 -> V_78 ) ;
F_52 ( V_84 ) ;
return 0 ;
}
static int F_55 ( struct V_8 * V_84 , struct V_82 * V_61 ,
int V_88 , int V_89 )
{
struct V_70 * V_71 = NULL ;
int V_90 , V_85 , V_72 ;
V_90 = F_56 ( V_61 -> V_61 . V_91 , V_89 ) ;
if ( V_90 == V_36 ) {
F_35 ( & V_61 -> V_61 , L_13 ,
V_52 , V_89 ) ;
return 0 ;
}
V_71 = F_57 ( sizeof( struct V_70 ) , V_92 ) ;
if ( ! V_71 ) {
F_35 ( & V_61 -> V_61 , L_14 ) ;
return - V_58 ;
}
F_58 ( V_90 , & V_93 ) ;
V_71 -> V_74 = V_88 ;
V_71 -> V_9 = V_84 ;
V_71 -> V_18 = V_90 ;
V_84 -> V_17 [ V_89 ] = V_71 ;
V_72 = F_59 ( V_90 , F_39 , V_94 ,
L_15 , V_71 ) ;
if ( V_72 ) {
F_35 ( & V_61 -> V_61 , L_16 ,
V_90 , V_72 ) ;
return V_72 ;
}
for ( V_85 = 0 ; V_85 < V_95 ; V_85 ++ )
F_21 ( & V_84 -> V_28 ,
F_45 ( V_84 , V_88 , V_85 ) , 1 ) ;
return 0 ;
}
static int F_60 ( struct V_82 * V_61 )
{
const struct V_96 * V_97 ;
struct V_8 * V_84 ;
struct V_98 V_99 , V_100 ;
int V_101 , V_85 , V_102 , V_89 , V_103 ;
const T_1 * V_7 ;
const struct V_104 * V_105 ;
int V_44 ;
T_1 V_88 ;
struct V_40 * V_106 ;
V_97 = F_61 ( V_107 , & V_61 -> V_61 ) ;
if ( ! V_97 )
return - V_60 ;
V_105 = V_97 -> V_51 ;
F_62 ( V_108 L_17 ) ;
V_84 = F_57 ( sizeof( struct V_8 ) , V_92 ) ;
if ( ! V_84 ) {
F_35 ( & V_61 -> V_61 , L_18 ) ;
return - V_58 ;
}
F_63 ( V_61 , V_84 ) ;
V_84 -> V_30 = F_64 ( V_61 -> V_61 . V_91 ,
V_29 , & V_109 , V_84 ) ;
if ( V_84 -> V_30 == NULL ) {
F_35 ( & V_61 -> V_61 , L_19 ) ;
V_101 = - V_58 ;
goto V_110;
}
if ( ( V_105 -> V_111 & V_76 ) != V_80 ) {
V_101 = F_65 ( V_61 -> V_61 . V_91 , 0 , & V_99 ) ;
if ( V_101 ) {
F_35 ( & V_61 -> V_61 , L_20 ,
V_61 -> V_61 . V_91 -> V_62 ) ;
goto V_110;
}
V_84 -> V_78 = F_66 ( V_99 . V_112 , F_67 ( & V_99 ) ) ;
if ( ! V_84 -> V_78 ) {
V_101 = - V_58 ;
F_35 ( & V_61 -> V_61 , L_21 ,
V_61 -> V_61 . V_91 -> V_62 ) ;
goto V_110;
}
V_84 -> V_46 =
V_105 -> V_46 + ( V_99 . V_112 & 0xfffff ) ;
if ( F_65 ( V_61 -> V_61 . V_91 , 1 , & V_100 ) )
V_84 -> V_46 = V_105 -> V_46 +
( V_99 . V_112 & V_113 ) ;
else
V_84 -> V_46 = V_100 . V_112 & V_113 ;
}
V_84 -> V_49 = V_105 -> V_111 ;
if ( ( V_105 -> V_111 & V_76 ) == V_77
&& ( F_68 () == 0x0200 ) )
V_84 -> V_49 |= V_50 ;
V_84 -> T_6 = V_61 -> V_61 . V_91 -> T_6 ;
V_101 = F_11 ( V_84 ) ;
if ( V_101 ) {
F_35 ( & V_61 -> V_61 , L_22 ) ;
goto V_110;
}
V_7 = F_24 ( V_61 -> V_61 . V_91 , L_23 , & V_44 ) ;
if ( F_34 ( V_61 -> V_61 . V_91 , L_24 ) ||
F_34 ( V_61 -> V_61 . V_91 , L_7 ) ) {
V_84 -> V_15 = V_114 ;
V_84 -> V_53 = V_115 ;
if ( V_7 )
F_69 ( & V_61 -> V_61 , L_25 ,
V_52 ) ;
for ( V_89 = 0 ; V_89 < V_116 ;
V_89 ++ ) {
V_101 = F_55 ( V_84 , V_61 ,
V_89 , V_89 ) ;
if ( V_101 )
goto V_110;
}
} else {
static const T_1 V_117 [] =
{ 0 , V_118 * V_95 } ;
V_84 -> V_15 = V_119 ;
V_84 -> V_53 = V_120 ;
if ( V_7 && V_44 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_35 ( & V_61 -> V_61 , L_26 ,
V_52 ) ;
V_101 = - V_60 ;
goto V_110;
}
if ( ! V_7 ) {
V_7 = V_117 ;
V_44 = sizeof( V_117 ) ;
}
for ( V_89 = 0 , V_85 = 0 ; V_85 < V_44 / ( 2 * sizeof( T_1 ) ) ; V_85 ++ ) {
if ( V_7 [ V_85 * 2 ] % V_95 ||
V_7 [ V_85 * 2 + 1 ] % V_95 ) {
F_70 ( L_27 ,
V_52 , V_61 -> V_61 . V_91 -> V_62 ,
V_7 [ V_85 * 2 + 1 ] , V_7 [ V_85 * 2 ] ) ;
V_101 = - V_60 ;
goto V_110;
}
V_88 = V_7 [ V_85 * 2 ] / V_95 ;
V_103 = V_7 [ V_85 * 2 + 1 ] / V_95 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ , V_89 ++ ) {
V_101 = F_55 ( V_84 , V_61 , V_88 + V_102 ,
V_89 ) ;
if ( V_101 )
goto V_110;
}
}
}
F_71 ( & V_84 -> V_86 , & V_121 ) ;
F_32 (phb, &hose_list, list_node) {
if ( ! V_106 -> V_122 . V_123 ) {
V_106 -> V_122 . V_123 = F_31 ;
V_106 -> V_122 . V_124 = F_15 ;
} else if ( V_106 -> V_122 . V_123 != F_31 ) {
F_35 ( & V_61 -> V_61 , L_28 ) ;
V_101 = - V_125 ;
goto V_110;
}
}
return 0 ;
V_110:
F_47 ( V_61 ) ;
return V_101 ;
}
static T_8 int F_72 ( void )
{
return F_73 ( & V_126 ) ;
}

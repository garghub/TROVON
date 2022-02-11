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
if ( ! V_34 -> V_35 )
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
struct V_36 * V_37 ,
struct V_8 * V_38 )
{
struct V_8 * V_9 = V_38 ;
struct V_39 * V_40 = F_23 ( V_32 -> V_41 ) ;
T_4 V_42 ;
int V_43 ;
const T_5 * V_2 ;
V_2 = F_24 ( V_40 -> V_44 , L_2 , & V_43 ) ;
if ( V_2 && ( V_43 == sizeof( T_4 ) ) )
V_42 = F_25 ( V_2 ) ;
else
V_42 = F_26 ( V_40 ) + V_9 -> V_45 ;
V_37 -> V_46 = F_27 ( V_42 ) ;
V_37 -> V_47 = F_28 ( V_42 ) ;
if ( V_9 -> V_48 & V_49 )
V_37 -> V_50 = F_29 ( V_12 ) ;
else
V_37 -> V_50 = V_12 ;
F_30 ( L_3 , V_51 ,
( V_12 >> V_9 -> V_15 ) & V_16 ,
( V_12 >> V_9 -> V_52 ) & V_53 ) ;
}
static int F_31 ( struct V_31 * V_32 , int V_54 , int type )
{
struct V_39 * V_40 = F_23 ( V_32 -> V_41 ) ;
struct V_55 * V_56 ;
T_6 T_6 = 0 ;
int V_27 , V_12 = - V_57 ;
unsigned int V_18 ;
struct V_33 * V_34 ;
struct V_36 V_37 ;
struct V_8 * V_9 ;
if ( type == V_58 ) {
F_32 (msi_data, &msi_head, list)
if ( V_9 -> V_48 & V_49 )
return - V_59 ;
}
V_56 = F_33 ( V_40 -> V_44 , L_4 , 0 ) ;
if ( V_56 ) {
if ( F_34 ( V_56 , L_5 ) ||
F_34 ( V_56 , L_6 ) ||
F_34 ( V_56 , L_7 ) )
T_6 = V_56 -> T_6 ;
else {
F_35 ( & V_32 -> V_60 ,
L_8 ,
V_40 -> V_44 , V_56 -> T_6 ) ;
return - V_59 ;
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
F_35 ( & V_32 -> V_60 , L_9 ) ;
goto V_61;
}
V_18 = F_37 ( V_9 -> V_30 , V_12 ) ;
if ( ! V_18 ) {
F_35 ( & V_32 -> V_60 , L_10 , V_12 ) ;
F_21 ( & V_9 -> V_28 , V_12 , 1 ) ;
V_27 = - V_62 ;
goto V_61;
}
F_19 ( V_18 , V_34 ) ;
F_22 ( V_32 , V_12 , & V_37 , V_9 ) ;
F_38 ( V_18 , & V_37 ) ;
}
return 0 ;
V_61:
return V_27 ;
}
static T_7 F_39 ( int V_35 , void * V_50 )
{
unsigned int V_63 ;
struct V_8 * V_9 ;
int V_64 = - 1 ;
T_1 V_65 = 0 ;
T_1 V_66 ;
T_1 V_67 = 0 ;
struct V_68 * V_69 = V_50 ;
T_7 V_70 = V_71 ;
V_9 = V_69 -> V_9 ;
V_64 = V_69 -> V_72 ;
if ( V_64 >= V_73 )
V_63 = 0 ;
switch ( V_9 -> V_48 & V_74 ) {
case V_75 :
V_65 = F_1 ( V_9 -> V_76 ,
V_64 * 0x10 ) ;
break;
case V_77 :
V_65 = F_1 ( V_9 -> V_76 , V_64 * 0x4 ) ;
break;
#ifdef F_40
case V_78 : {
unsigned int V_70 ;
V_70 = F_41 ( F_17 ( V_35 ) , & V_65 ) ;
if ( V_70 ) {
F_42 ( L_11
L_12 , V_35 , V_70 ) ;
V_65 = 0 ;
}
break;
}
#endif
}
while ( V_65 ) {
V_66 = F_43 ( V_65 ) - 1 ;
V_63 = F_44 ( V_9 -> V_30 ,
F_45 ( V_9 , V_64 ,
V_66 + V_67 ) ) ;
if ( V_63 ) {
F_46 ( V_63 ) ;
V_70 = V_79 ;
}
V_67 += V_66 + 1 ;
V_65 = V_65 >> ( V_66 + 1 ) ;
}
return V_70 ;
}
static int F_47 ( struct V_80 * V_81 )
{
struct V_8 * V_82 = F_48 ( V_81 ) ;
int V_18 , V_83 ;
if ( V_82 -> V_84 . V_85 != NULL )
F_49 ( & V_82 -> V_84 ) ;
for ( V_83 = 0 ; V_83 < V_73 ; V_83 ++ ) {
if ( V_82 -> V_17 [ V_83 ] ) {
V_18 = V_82 -> V_17 [ V_83 ] -> V_18 ;
F_50 ( ! V_18 ) ;
F_51 ( V_18 , V_82 -> V_17 [ V_83 ] ) ;
F_52 ( V_82 -> V_17 [ V_83 ] ) ;
F_20 ( V_18 ) ;
}
}
if ( V_82 -> V_28 . V_28 )
F_53 ( & V_82 -> V_28 ) ;
if ( ( V_82 -> V_48 & V_74 ) != V_78 )
F_54 ( V_82 -> V_76 ) ;
F_52 ( V_82 ) ;
return 0 ;
}
static int F_55 ( struct V_8 * V_82 , struct V_80 * V_60 ,
int V_86 , int V_87 )
{
struct V_68 * V_69 = NULL ;
int V_88 , V_83 , V_70 ;
V_88 = F_56 ( V_60 -> V_60 . V_89 , V_87 ) ;
if ( ! V_88 ) {
F_35 ( & V_60 -> V_60 , L_13 ,
V_51 , V_87 ) ;
return 0 ;
}
V_69 = F_57 ( sizeof( struct V_68 ) , V_90 ) ;
if ( ! V_69 ) {
F_35 ( & V_60 -> V_60 , L_14 ) ;
return - V_57 ;
}
F_58 ( V_88 , & V_91 ) ;
V_69 -> V_72 = V_86 ;
V_69 -> V_9 = V_82 ;
V_69 -> V_18 = V_88 ;
V_82 -> V_17 [ V_87 ] = V_69 ;
V_70 = F_59 ( V_88 , F_39 , V_92 ,
L_15 , V_69 ) ;
if ( V_70 ) {
F_35 ( & V_60 -> V_60 , L_16 ,
V_88 , V_70 ) ;
return V_70 ;
}
for ( V_83 = 0 ; V_83 < V_93 ; V_83 ++ )
F_21 ( & V_82 -> V_28 ,
F_45 ( V_82 , V_86 , V_83 ) , 1 ) ;
return 0 ;
}
static int F_60 ( struct V_80 * V_60 )
{
const struct V_94 * V_95 ;
struct V_8 * V_82 ;
struct V_96 V_97 , V_98 ;
int V_99 , V_83 , V_100 , V_87 , V_101 ;
const T_1 * V_7 ;
const struct V_102 * V_103 ;
int V_43 ;
T_1 V_86 ;
struct V_39 * V_104 ;
V_95 = F_61 ( V_105 , & V_60 -> V_60 ) ;
if ( ! V_95 )
return - V_59 ;
V_103 = V_95 -> V_50 ;
F_62 ( V_106 L_17 ) ;
V_82 = F_57 ( sizeof( struct V_8 ) , V_90 ) ;
if ( ! V_82 ) {
F_35 ( & V_60 -> V_60 , L_18 ) ;
return - V_57 ;
}
F_63 ( V_60 , V_82 ) ;
V_82 -> V_30 = F_64 ( V_60 -> V_60 . V_89 ,
V_29 , & V_107 , V_82 ) ;
if ( V_82 -> V_30 == NULL ) {
F_35 ( & V_60 -> V_60 , L_19 ) ;
V_99 = - V_57 ;
goto V_108;
}
if ( ( V_103 -> V_109 & V_74 ) != V_78 ) {
V_99 = F_65 ( V_60 -> V_60 . V_89 , 0 , & V_97 ) ;
if ( V_99 ) {
F_35 ( & V_60 -> V_60 , L_20 ,
V_60 -> V_60 . V_89 ) ;
goto V_108;
}
V_82 -> V_76 = F_66 ( V_97 . V_110 , F_67 ( & V_97 ) ) ;
if ( ! V_82 -> V_76 ) {
V_99 = - V_57 ;
F_35 ( & V_60 -> V_60 , L_21 ,
V_60 -> V_60 . V_89 ) ;
goto V_108;
}
V_82 -> V_45 =
V_103 -> V_45 + ( V_97 . V_110 & 0xfffff ) ;
if ( F_65 ( V_60 -> V_60 . V_89 , 1 , & V_98 ) )
V_82 -> V_45 = V_103 -> V_45 +
( V_97 . V_110 & V_111 ) ;
else
V_82 -> V_45 = V_98 . V_110 & V_111 ;
}
V_82 -> V_48 = V_103 -> V_109 ;
if ( ( V_103 -> V_109 & V_74 ) == V_75
&& ( F_68 () == 0x0200 ) )
V_82 -> V_48 |= V_49 ;
V_82 -> T_6 = V_60 -> V_60 . V_89 -> T_6 ;
V_99 = F_11 ( V_82 ) ;
if ( V_99 ) {
F_35 ( & V_60 -> V_60 , L_22 ) ;
goto V_108;
}
V_7 = F_24 ( V_60 -> V_60 . V_89 , L_23 , & V_43 ) ;
if ( F_34 ( V_60 -> V_60 . V_89 , L_24 ) ||
F_34 ( V_60 -> V_60 . V_89 , L_7 ) ) {
V_82 -> V_15 = V_112 ;
V_82 -> V_52 = V_113 ;
if ( V_7 )
F_69 ( & V_60 -> V_60 , L_25 ,
V_51 ) ;
for ( V_87 = 0 ; V_87 < V_114 ;
V_87 ++ ) {
V_99 = F_55 ( V_82 , V_60 ,
V_87 , V_87 ) ;
if ( V_99 )
goto V_108;
}
} else {
static const T_1 V_115 [] =
{ 0 , V_116 * V_93 } ;
V_82 -> V_15 = V_117 ;
V_82 -> V_52 = V_118 ;
if ( V_7 && V_43 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_35 ( & V_60 -> V_60 , L_26 ,
V_51 ) ;
V_99 = - V_59 ;
goto V_108;
}
if ( ! V_7 ) {
V_7 = V_115 ;
V_43 = sizeof( V_115 ) ;
}
for ( V_87 = 0 , V_83 = 0 ; V_83 < V_43 / ( 2 * sizeof( T_1 ) ) ; V_83 ++ ) {
if ( V_7 [ V_83 * 2 ] % V_93 ||
V_7 [ V_83 * 2 + 1 ] % V_93 ) {
F_70 ( L_27 ,
V_51 , V_60 -> V_60 . V_89 ,
V_7 [ V_83 * 2 + 1 ] , V_7 [ V_83 * 2 ] ) ;
V_99 = - V_59 ;
goto V_108;
}
V_86 = V_7 [ V_83 * 2 ] / V_93 ;
V_101 = V_7 [ V_83 * 2 + 1 ] / V_93 ;
for ( V_100 = 0 ; V_100 < V_101 ; V_100 ++ , V_87 ++ ) {
V_99 = F_55 ( V_82 , V_60 , V_86 + V_100 ,
V_87 ) ;
if ( V_99 )
goto V_108;
}
}
}
F_71 ( & V_82 -> V_84 , & V_119 ) ;
F_32 (phb, &hose_list, list_node) {
if ( ! V_104 -> V_120 . V_121 ) {
V_104 -> V_120 . V_121 = F_31 ;
V_104 -> V_120 . V_122 = F_15 ;
} else if ( V_104 -> V_120 . V_121 != F_31 ) {
F_35 ( & V_60 -> V_60 , L_28 ) ;
V_99 = - V_123 ;
goto V_108;
}
}
return 0 ;
V_108:
F_47 ( V_60 ) ;
return V_99 ;
}
static T_8 int F_72 ( void )
{
return F_73 ( & V_124 ) ;
}

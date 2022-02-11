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
V_40 -> V_44 -> V_61 , V_56 -> T_6 ) ;
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
goto V_62;
}
V_18 = F_37 ( V_9 -> V_30 , V_12 ) ;
if ( ! V_18 ) {
F_35 ( & V_32 -> V_60 , L_10 , V_12 ) ;
F_21 ( & V_9 -> V_28 , V_12 , 1 ) ;
V_27 = - V_63 ;
goto V_62;
}
F_19 ( V_18 , V_34 ) ;
F_22 ( V_32 , V_12 , & V_37 , V_9 ) ;
F_38 ( V_18 , & V_37 ) ;
}
return 0 ;
V_62:
return V_27 ;
}
static T_7 F_39 ( int V_35 , void * V_50 )
{
unsigned int V_64 ;
struct V_8 * V_9 ;
int V_65 = - 1 ;
T_1 V_66 = 0 ;
T_1 V_67 ;
T_1 V_68 = 0 ;
struct V_69 * V_70 = V_50 ;
T_7 V_71 = V_72 ;
V_9 = V_70 -> V_9 ;
V_65 = V_70 -> V_73 ;
if ( V_65 >= V_74 )
V_64 = 0 ;
switch ( V_9 -> V_48 & V_75 ) {
case V_76 :
V_66 = F_1 ( V_9 -> V_77 ,
V_65 * 0x10 ) ;
break;
case V_78 :
V_66 = F_1 ( V_9 -> V_77 , V_65 * 0x4 ) ;
break;
#ifdef F_40
case V_79 : {
unsigned int V_71 ;
V_71 = F_41 ( F_17 ( V_35 ) , & V_66 ) ;
if ( V_71 ) {
F_42 ( L_11
L_12 , V_35 , V_71 ) ;
V_66 = 0 ;
}
break;
}
#endif
}
while ( V_66 ) {
V_67 = F_43 ( V_66 ) - 1 ;
V_64 = F_44 ( V_9 -> V_30 ,
F_45 ( V_9 , V_65 ,
V_67 + V_68 ) ) ;
if ( V_64 ) {
F_46 ( V_64 ) ;
V_71 = V_80 ;
}
V_68 += V_67 + 1 ;
V_66 = V_66 >> ( V_67 + 1 ) ;
}
return V_71 ;
}
static int F_47 ( struct V_81 * V_82 )
{
struct V_8 * V_83 = F_48 ( V_82 ) ;
int V_18 , V_84 ;
if ( V_83 -> V_85 . V_86 != NULL )
F_49 ( & V_83 -> V_85 ) ;
for ( V_84 = 0 ; V_84 < V_74 ; V_84 ++ ) {
if ( V_83 -> V_17 [ V_84 ] ) {
V_18 = V_83 -> V_17 [ V_84 ] -> V_18 ;
F_50 ( ! V_18 ) ;
F_51 ( V_18 , V_83 -> V_17 [ V_84 ] ) ;
F_52 ( V_83 -> V_17 [ V_84 ] ) ;
F_20 ( V_18 ) ;
}
}
if ( V_83 -> V_28 . V_28 )
F_53 ( & V_83 -> V_28 ) ;
if ( ( V_83 -> V_48 & V_75 ) != V_79 )
F_54 ( V_83 -> V_77 ) ;
F_52 ( V_83 ) ;
return 0 ;
}
static int F_55 ( struct V_8 * V_83 , struct V_81 * V_60 ,
int V_87 , int V_88 )
{
struct V_69 * V_70 = NULL ;
int V_89 , V_84 , V_71 ;
V_89 = F_56 ( V_60 -> V_60 . V_90 , V_88 ) ;
if ( ! V_89 ) {
F_35 ( & V_60 -> V_60 , L_13 ,
V_51 , V_88 ) ;
return 0 ;
}
V_70 = F_57 ( sizeof( struct V_69 ) , V_91 ) ;
if ( ! V_70 ) {
F_35 ( & V_60 -> V_60 , L_14 ) ;
return - V_57 ;
}
F_58 ( V_89 , & V_92 ) ;
V_70 -> V_73 = V_87 ;
V_70 -> V_9 = V_83 ;
V_70 -> V_18 = V_89 ;
V_83 -> V_17 [ V_88 ] = V_70 ;
V_71 = F_59 ( V_89 , F_39 , V_93 ,
L_15 , V_70 ) ;
if ( V_71 ) {
F_35 ( & V_60 -> V_60 , L_16 ,
V_89 , V_71 ) ;
return V_71 ;
}
for ( V_84 = 0 ; V_84 < V_94 ; V_84 ++ )
F_21 ( & V_83 -> V_28 ,
F_45 ( V_83 , V_87 , V_84 ) , 1 ) ;
return 0 ;
}
static int F_60 ( struct V_81 * V_60 )
{
const struct V_95 * V_96 ;
struct V_8 * V_83 ;
struct V_97 V_98 , V_99 ;
int V_100 , V_84 , V_101 , V_88 , V_102 ;
const T_1 * V_7 ;
const struct V_103 * V_104 ;
int V_43 ;
T_1 V_87 ;
struct V_39 * V_105 ;
V_96 = F_61 ( V_106 , & V_60 -> V_60 ) ;
if ( ! V_96 )
return - V_59 ;
V_104 = V_96 -> V_50 ;
F_62 ( V_107 L_17 ) ;
V_83 = F_57 ( sizeof( struct V_8 ) , V_91 ) ;
if ( ! V_83 ) {
F_35 ( & V_60 -> V_60 , L_18 ) ;
return - V_57 ;
}
F_63 ( V_60 , V_83 ) ;
V_83 -> V_30 = F_64 ( V_60 -> V_60 . V_90 ,
V_29 , & V_108 , V_83 ) ;
if ( V_83 -> V_30 == NULL ) {
F_35 ( & V_60 -> V_60 , L_19 ) ;
V_100 = - V_57 ;
goto V_109;
}
if ( ( V_104 -> V_110 & V_75 ) != V_79 ) {
V_100 = F_65 ( V_60 -> V_60 . V_90 , 0 , & V_98 ) ;
if ( V_100 ) {
F_35 ( & V_60 -> V_60 , L_20 ,
V_60 -> V_60 . V_90 -> V_61 ) ;
goto V_109;
}
V_83 -> V_77 = F_66 ( V_98 . V_111 , F_67 ( & V_98 ) ) ;
if ( ! V_83 -> V_77 ) {
V_100 = - V_57 ;
F_35 ( & V_60 -> V_60 , L_21 ,
V_60 -> V_60 . V_90 -> V_61 ) ;
goto V_109;
}
V_83 -> V_45 =
V_104 -> V_45 + ( V_98 . V_111 & 0xfffff ) ;
if ( F_65 ( V_60 -> V_60 . V_90 , 1 , & V_99 ) )
V_83 -> V_45 = V_104 -> V_45 +
( V_98 . V_111 & V_112 ) ;
else
V_83 -> V_45 = V_99 . V_111 & V_112 ;
}
V_83 -> V_48 = V_104 -> V_110 ;
if ( ( V_104 -> V_110 & V_75 ) == V_76
&& ( F_68 () == 0x0200 ) )
V_83 -> V_48 |= V_49 ;
V_83 -> T_6 = V_60 -> V_60 . V_90 -> T_6 ;
V_100 = F_11 ( V_83 ) ;
if ( V_100 ) {
F_35 ( & V_60 -> V_60 , L_22 ) ;
goto V_109;
}
V_7 = F_24 ( V_60 -> V_60 . V_90 , L_23 , & V_43 ) ;
if ( F_34 ( V_60 -> V_60 . V_90 , L_24 ) ||
F_34 ( V_60 -> V_60 . V_90 , L_7 ) ) {
V_83 -> V_15 = V_113 ;
V_83 -> V_52 = V_114 ;
if ( V_7 )
F_69 ( & V_60 -> V_60 , L_25 ,
V_51 ) ;
for ( V_88 = 0 ; V_88 < V_115 ;
V_88 ++ ) {
V_100 = F_55 ( V_83 , V_60 ,
V_88 , V_88 ) ;
if ( V_100 )
goto V_109;
}
} else {
static const T_1 V_116 [] =
{ 0 , V_117 * V_94 } ;
V_83 -> V_15 = V_118 ;
V_83 -> V_52 = V_119 ;
if ( V_7 && V_43 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_35 ( & V_60 -> V_60 , L_26 ,
V_51 ) ;
V_100 = - V_59 ;
goto V_109;
}
if ( ! V_7 ) {
V_7 = V_116 ;
V_43 = sizeof( V_116 ) ;
}
for ( V_88 = 0 , V_84 = 0 ; V_84 < V_43 / ( 2 * sizeof( T_1 ) ) ; V_84 ++ ) {
if ( V_7 [ V_84 * 2 ] % V_94 ||
V_7 [ V_84 * 2 + 1 ] % V_94 ) {
F_70 ( L_27 ,
V_51 , V_60 -> V_60 . V_90 -> V_61 ,
V_7 [ V_84 * 2 + 1 ] , V_7 [ V_84 * 2 ] ) ;
V_100 = - V_59 ;
goto V_109;
}
V_87 = V_7 [ V_84 * 2 ] / V_94 ;
V_102 = V_7 [ V_84 * 2 + 1 ] / V_94 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ , V_88 ++ ) {
V_100 = F_55 ( V_83 , V_60 , V_87 + V_101 ,
V_88 ) ;
if ( V_100 )
goto V_109;
}
}
}
F_71 ( & V_83 -> V_85 , & V_120 ) ;
F_32 (phb, &hose_list, list_node) {
if ( ! V_105 -> V_121 . V_122 ) {
V_105 -> V_121 . V_122 = F_31 ;
V_105 -> V_121 . V_123 = F_15 ;
} else if ( V_105 -> V_121 . V_122 != F_31 ) {
F_35 ( & V_60 -> V_60 , L_28 ) ;
V_100 = - V_124 ;
goto V_109;
}
}
return 0 ;
V_109:
F_47 ( V_60 ) ;
return V_100 ;
}
static T_8 int F_72 ( void )
{
return F_73 ( & V_125 ) ;
}

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
V_39 -> V_50 = V_12 ;
F_28 ( L_3 , V_51 ,
( V_12 >> V_9 -> V_15 ) & V_16 ,
( V_12 >> V_9 -> V_52 ) & V_53 ) ;
}
static int F_29 ( struct V_32 * V_33 , int V_54 , int type )
{
struct V_41 * V_42 = F_22 ( V_33 -> V_43 ) ;
struct V_55 * V_56 ;
T_6 T_6 = 0 ;
int V_27 , V_12 = - V_57 ;
unsigned int V_18 ;
struct V_34 * V_35 ;
struct V_38 V_39 ;
struct V_8 * V_9 ;
if ( type == V_58 )
F_28 ( L_4 ) ;
V_56 = F_30 ( V_42 -> V_46 , L_5 , 0 ) ;
if ( V_56 ) {
if ( F_31 ( V_56 , L_6 ) ||
F_31 ( V_56 , L_7 ) ||
F_31 ( V_56 , L_8 ) )
T_6 = V_56 -> T_6 ;
else {
F_32 ( & V_33 -> V_59 ,
L_9 ,
V_42 -> V_46 -> V_60 , V_56 -> T_6 ) ;
return - V_61 ;
}
}
F_15 (entry, &pdev->msi_list, list) {
F_15 (msi_data, &msi_head, list) {
if ( T_6 && ( T_6 != V_9 -> T_6 ) )
continue;
V_12 = F_33 ( & V_9 -> V_28 , 1 ) ;
if ( V_12 >= 0 )
break;
}
if ( V_12 < 0 ) {
V_27 = V_12 ;
F_32 ( & V_33 -> V_59 , L_10 ) ;
goto V_62;
}
V_18 = F_34 ( V_9 -> V_30 , V_12 ) ;
if ( V_18 == V_37 ) {
F_32 ( & V_33 -> V_59 , L_11 , V_12 ) ;
F_18 ( & V_9 -> V_28 , V_12 , 1 ) ;
V_27 = - V_63 ;
goto V_62;
}
F_17 ( V_18 , V_35 ) ;
F_21 ( V_33 , V_12 , & V_39 , V_9 ) ;
F_35 ( V_18 , & V_39 ) ;
}
return 0 ;
V_62:
return V_27 ;
}
static T_7 F_36 ( int V_36 , void * V_50 )
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
V_64 = V_37 ;
switch ( V_9 -> V_75 & V_76 ) {
case V_77 :
V_66 = F_1 ( V_9 -> V_78 ,
V_65 * 0x10 ) ;
break;
case V_79 :
V_66 = F_1 ( V_9 -> V_78 , V_65 * 0x4 ) ;
break;
#ifdef F_37
case V_80 : {
unsigned int V_71 ;
V_71 = F_38 ( F_19 ( V_36 ) , & V_66 ) ;
if ( V_71 ) {
F_39 ( L_12
L_13 , V_36 , V_71 ) ;
V_66 = 0 ;
}
break;
}
#endif
}
while ( V_66 ) {
V_67 = F_40 ( V_66 ) - 1 ;
V_64 = F_41 ( V_9 -> V_30 ,
F_42 ( V_9 , V_65 ,
V_67 + V_68 ) ) ;
if ( V_64 != V_37 ) {
F_43 ( V_64 ) ;
V_71 = V_81 ;
}
V_68 += V_67 + 1 ;
V_66 = V_66 >> ( V_67 + 1 ) ;
}
return V_71 ;
}
static int F_44 ( struct V_82 * V_83 )
{
struct V_8 * V_84 = F_45 ( V_83 ) ;
int V_18 , V_85 ;
if ( V_84 -> V_86 . V_87 != NULL )
F_46 ( & V_84 -> V_86 ) ;
for ( V_85 = 0 ; V_85 < V_74 ; V_85 ++ ) {
if ( V_84 -> V_17 [ V_85 ] ) {
V_18 = V_84 -> V_17 [ V_85 ] -> V_18 ;
F_47 ( V_18 == V_37 ) ;
F_48 ( V_18 , V_84 -> V_17 [ V_85 ] ) ;
F_49 ( V_84 -> V_17 [ V_85 ] ) ;
F_20 ( V_18 ) ;
}
}
if ( V_84 -> V_28 . V_28 )
F_50 ( & V_84 -> V_28 ) ;
if ( ( V_84 -> V_75 & V_76 ) != V_80 )
F_51 ( V_84 -> V_78 ) ;
F_49 ( V_84 ) ;
return 0 ;
}
static int F_52 ( struct V_8 * V_84 , struct V_82 * V_59 ,
int V_88 , int V_89 )
{
struct V_69 * V_70 = NULL ;
int V_90 , V_85 , V_71 ;
V_90 = F_53 ( V_59 -> V_59 . V_31 , V_89 ) ;
if ( V_90 == V_37 ) {
F_32 ( & V_59 -> V_59 , L_14 ,
V_51 , V_89 ) ;
return 0 ;
}
V_70 = F_54 ( sizeof( struct V_69 ) , V_91 ) ;
if ( ! V_70 ) {
F_32 ( & V_59 -> V_59 , L_15 ) ;
return - V_57 ;
}
F_55 ( V_90 , & V_92 ) ;
V_70 -> V_73 = V_88 ;
V_70 -> V_9 = V_84 ;
V_70 -> V_18 = V_90 ;
V_84 -> V_17 [ V_89 ] = V_70 ;
V_71 = F_56 ( V_90 , F_36 , V_93 ,
L_16 , V_70 ) ;
if ( V_71 ) {
F_32 ( & V_59 -> V_59 , L_17 ,
V_90 , V_71 ) ;
return V_71 ;
}
for ( V_85 = 0 ; V_85 < V_94 ; V_85 ++ )
F_18 ( & V_84 -> V_28 ,
F_42 ( V_84 , V_88 , V_85 ) , 1 ) ;
return 0 ;
}
static int F_57 ( struct V_82 * V_59 )
{
const struct V_95 * V_96 ;
struct V_8 * V_84 ;
struct V_97 V_98 , V_99 ;
int V_100 , V_85 , V_101 , V_89 , V_102 ;
const T_1 * V_7 ;
const struct V_103 * V_104 ;
int V_45 ;
T_1 V_88 ;
V_96 = F_58 ( V_105 , & V_59 -> V_59 ) ;
if ( ! V_96 )
return - V_61 ;
V_104 = V_96 -> V_50 ;
F_59 ( V_106 L_18 ) ;
V_84 = F_54 ( sizeof( struct V_8 ) , V_91 ) ;
if ( ! V_84 ) {
F_32 ( & V_59 -> V_59 , L_19 ) ;
return - V_57 ;
}
F_60 ( V_59 , V_84 ) ;
V_84 -> V_30 = F_61 ( V_59 -> V_59 . V_31 ,
V_29 , & V_107 , V_84 ) ;
if ( V_84 -> V_30 == NULL ) {
F_32 ( & V_59 -> V_59 , L_20 ) ;
V_100 = - V_57 ;
goto V_108;
}
if ( ( V_104 -> V_109 & V_76 ) != V_80 ) {
V_100 = F_62 ( V_59 -> V_59 . V_31 , 0 , & V_98 ) ;
if ( V_100 ) {
F_32 ( & V_59 -> V_59 , L_21 ,
V_59 -> V_59 . V_31 -> V_60 ) ;
goto V_108;
}
V_84 -> V_78 = F_63 ( V_98 . V_110 , F_64 ( & V_98 ) ) ;
if ( ! V_84 -> V_78 ) {
V_100 = - V_57 ;
F_32 ( & V_59 -> V_59 , L_22 ,
V_59 -> V_59 . V_31 -> V_60 ) ;
goto V_108;
}
V_84 -> V_47 =
V_104 -> V_47 + ( V_98 . V_110 & 0xfffff ) ;
if ( F_62 ( V_59 -> V_59 . V_31 , 1 , & V_99 ) )
V_84 -> V_47 = V_104 -> V_47 +
( V_98 . V_110 & V_111 ) ;
else
V_84 -> V_47 = V_99 . V_110 & V_111 ;
}
V_84 -> V_75 = V_104 -> V_109 ;
V_84 -> T_6 = V_59 -> V_59 . V_31 -> T_6 ;
V_100 = F_11 ( V_84 ) ;
if ( V_100 ) {
F_32 ( & V_59 -> V_59 , L_23 ) ;
goto V_108;
}
V_7 = F_23 ( V_59 -> V_59 . V_31 , L_24 , & V_45 ) ;
if ( F_31 ( V_59 -> V_59 . V_31 , L_25 ) ||
F_31 ( V_59 -> V_59 . V_31 , L_8 ) ) {
V_84 -> V_15 = V_112 ;
V_84 -> V_52 = V_113 ;
if ( V_7 )
F_65 ( & V_59 -> V_59 , L_26 ,
V_51 ) ;
for ( V_89 = 0 ; V_89 < V_114 ;
V_89 ++ ) {
V_100 = F_52 ( V_84 , V_59 ,
V_89 , V_89 ) ;
if ( V_100 )
goto V_108;
}
} else {
static const T_1 V_115 [] =
{ 0 , V_116 * V_94 } ;
V_84 -> V_15 = V_117 ;
V_84 -> V_52 = V_118 ;
if ( V_7 && V_45 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_32 ( & V_59 -> V_59 , L_27 ,
V_51 ) ;
V_100 = - V_61 ;
goto V_108;
}
if ( ! V_7 ) {
V_7 = V_115 ;
V_45 = sizeof( V_115 ) ;
}
for ( V_89 = 0 , V_85 = 0 ; V_85 < V_45 / ( 2 * sizeof( T_1 ) ) ; V_85 ++ ) {
if ( V_7 [ V_85 * 2 ] % V_94 ||
V_7 [ V_85 * 2 + 1 ] % V_94 ) {
F_66 ( L_28 ,
V_51 , V_59 -> V_59 . V_31 -> V_60 ,
V_7 [ V_85 * 2 + 1 ] , V_7 [ V_85 * 2 ] ) ;
V_100 = - V_61 ;
goto V_108;
}
V_88 = V_7 [ V_85 * 2 ] / V_94 ;
V_102 = V_7 [ V_85 * 2 + 1 ] / V_94 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ , V_89 ++ ) {
V_100 = F_52 ( V_84 , V_59 , V_88 + V_101 ,
V_89 ) ;
if ( V_100 )
goto V_108;
}
}
}
F_67 ( & V_84 -> V_86 , & V_119 ) ;
if ( ! V_120 . V_121 ) {
V_120 . V_121 = F_29 ;
V_120 . V_122 = F_14 ;
} else if ( V_120 . V_121 != F_29 ) {
F_32 ( & V_59 -> V_59 , L_29 ) ;
V_100 = - V_123 ;
goto V_108;
}
return 0 ;
V_108:
F_44 ( V_59 ) ;
return V_100 ;
}
static T_8 int F_68 ( void )
{
return F_69 ( & V_124 ) ;
}

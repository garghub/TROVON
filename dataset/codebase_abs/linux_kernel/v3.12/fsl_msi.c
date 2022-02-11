static inline T_1 F_1 ( T_1 T_2 * V_1 , unsigned int V_2 )
{
return F_2 ( V_1 + ( V_2 >> 2 ) ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
}
static int F_4 ( struct V_5 * V_6 , unsigned int V_7 ,
T_3 V_8 )
{
struct V_9 * V_10 = V_6 -> V_11 ;
struct V_12 * V_13 = & V_14 ;
F_5 ( V_7 , V_15 ) ;
F_6 ( V_7 , V_10 ) ;
F_7 ( V_7 , V_13 , V_16 ) ;
return 0 ;
}
static int F_8 ( struct V_9 * V_10 )
{
int V_17 , V_18 ;
V_17 = F_9 ( & V_10 -> V_19 , V_20 ,
V_10 -> V_21 -> V_22 ) ;
if ( V_17 )
return V_17 ;
for ( V_18 = 0 ; V_18 < V_20 ; V_18 ++ )
F_10 ( & V_10 -> V_19 , V_18 ) ;
return 0 ;
}
static int F_11 ( struct V_23 * V_24 , int V_25 , int type )
{
if ( type == V_26 )
F_12 ( L_1 ) ;
return 0 ;
}
static void F_13 ( struct V_23 * V_24 )
{
struct V_27 * V_28 ;
struct V_9 * V_10 ;
F_14 (entry, &pdev->msi_list, list) {
if ( V_28 -> V_29 == V_30 )
continue;
V_10 = F_15 ( V_28 -> V_29 ) ;
F_16 ( V_28 -> V_29 , NULL ) ;
F_17 ( & V_10 -> V_19 ,
F_18 ( V_28 -> V_29 ) , 1 ) ;
F_19 ( V_28 -> V_29 ) ;
}
return;
}
static void F_20 ( struct V_23 * V_24 , int V_18 ,
struct V_31 * V_32 ,
struct V_9 * V_33 )
{
struct V_9 * V_10 = V_33 ;
struct V_34 * V_35 = F_21 ( V_24 -> V_36 ) ;
T_4 V_37 ;
int V_38 ;
const T_5 * V_2 ;
V_2 = F_22 ( V_35 -> V_39 , L_2 , & V_38 ) ;
if ( V_2 && ( V_38 == sizeof( T_4 ) ) )
V_37 = F_23 ( V_2 ) ;
else
V_37 = F_24 ( V_35 ) + V_10 -> V_40 ;
V_32 -> V_41 = F_25 ( V_37 ) ;
V_32 -> V_42 = F_26 ( V_37 ) ;
V_32 -> V_43 = V_18 ;
F_12 ( L_3 , V_44 ,
( V_18 >> V_10 -> V_45 ) & V_46 ,
( V_18 >> V_10 -> V_47 ) & V_48 ) ;
}
static int F_27 ( struct V_23 * V_24 , int V_25 , int type )
{
struct V_34 * V_35 = F_21 ( V_24 -> V_36 ) ;
struct V_49 * V_50 ;
T_6 T_6 = 0 ;
int V_17 , V_18 = - V_51 ;
unsigned int V_7 ;
struct V_27 * V_28 ;
struct V_31 V_32 ;
struct V_9 * V_10 ;
V_50 = F_28 ( V_35 -> V_39 , L_4 , 0 ) ;
if ( V_50 ) {
if ( F_29 ( V_50 , L_5 ) ||
F_29 ( V_50 , L_6 ) )
T_6 = V_50 -> T_6 ;
else {
F_30 ( & V_24 -> V_52 ,
L_7 ,
V_35 -> V_39 -> V_53 , V_50 -> T_6 ) ;
return - V_54 ;
}
}
F_14 (entry, &pdev->msi_list, list) {
F_14 (msi_data, &msi_head, list) {
if ( T_6 && ( T_6 != V_10 -> T_6 ) )
continue;
V_18 = F_31 ( & V_10 -> V_19 , 1 ) ;
if ( V_18 >= 0 )
break;
}
if ( V_18 < 0 ) {
V_17 = V_18 ;
F_30 ( & V_24 -> V_52 , L_8 ) ;
goto V_55;
}
V_7 = F_32 ( V_10 -> V_21 , V_18 ) ;
if ( V_7 == V_30 ) {
F_30 ( & V_24 -> V_52 , L_9 , V_18 ) ;
F_17 ( & V_10 -> V_19 , V_18 , 1 ) ;
V_17 = - V_56 ;
goto V_55;
}
F_16 ( V_7 , V_28 ) ;
F_20 ( V_24 , V_18 , & V_32 , V_10 ) ;
F_33 ( V_7 , & V_32 ) ;
}
return 0 ;
V_55:
return V_17 ;
}
static void F_34 ( unsigned int V_29 , struct V_57 * V_58 )
{
struct V_12 * V_13 = F_35 ( V_58 ) ;
struct V_3 * V_59 = F_36 ( V_58 ) ;
unsigned int V_60 ;
struct V_9 * V_10 ;
int V_61 = - 1 ;
T_1 V_62 = 0 ;
T_1 V_63 ;
T_1 V_64 = 0 ;
struct V_65 * V_66 ;
V_66 = F_37 ( V_29 ) ;
V_10 = V_66 -> V_10 ;
F_38 ( & V_58 -> V_67 ) ;
if ( ( V_10 -> V_68 & V_69 ) == V_70 ) {
if ( V_13 -> V_71 )
V_13 -> V_71 ( V_59 ) ;
else {
V_13 -> V_72 ( V_59 ) ;
V_13 -> V_73 ( V_59 ) ;
}
}
if ( F_39 ( F_40 ( V_59 ) ) )
goto V_74;
V_61 = V_66 -> V_75 ;
if ( V_61 >= V_76 )
V_60 = V_30 ;
F_41 ( V_59 ) ;
switch ( V_10 -> V_68 & V_69 ) {
case V_77 :
V_62 = F_1 ( V_10 -> V_78 ,
V_61 * 0x10 ) ;
break;
case V_70 :
V_62 = F_1 ( V_10 -> V_78 , V_61 * 0x4 ) ;
break;
#ifdef F_42
case V_79 : {
unsigned int V_80 ;
V_80 = F_43 ( F_18 ( V_29 ) , & V_62 ) ;
if ( V_80 ) {
F_44 ( L_10
L_11 , V_29 , V_80 ) ;
V_62 = 0 ;
}
break;
}
#endif
}
while ( V_62 ) {
V_63 = F_45 ( V_62 ) - 1 ;
V_60 = F_46 ( V_10 -> V_21 ,
F_47 ( V_10 , V_61 ,
V_63 + V_64 ) ) ;
if ( V_60 != V_30 )
F_48 ( V_60 ) ;
V_64 += V_63 + 1 ;
V_62 = V_62 >> ( V_63 + 1 ) ;
}
F_49 ( V_59 ) ;
switch ( V_10 -> V_68 & V_69 ) {
case V_77 :
case V_79 :
V_13 -> V_81 ( V_59 ) ;
break;
case V_70 :
if ( ! F_50 ( V_59 ) && V_13 -> V_82 )
V_13 -> V_82 ( V_59 ) ;
break;
}
V_74:
F_51 ( & V_58 -> V_67 ) ;
}
static int F_52 ( struct V_83 * V_84 )
{
struct V_9 * V_85 = F_53 ( V_84 ) ;
int V_7 , V_86 ;
struct V_65 * V_66 ;
if ( V_85 -> V_87 . V_88 != NULL )
F_54 ( & V_85 -> V_87 ) ;
for ( V_86 = 0 ; V_86 < V_76 ; V_86 ++ ) {
V_7 = V_85 -> V_89 [ V_86 ] ;
if ( V_7 != V_30 ) {
V_66 = F_37 ( V_7 ) ;
F_55 ( V_66 ) ;
F_19 ( V_7 ) ;
}
}
if ( V_85 -> V_19 . V_19 )
F_56 ( & V_85 -> V_19 ) ;
if ( ( V_85 -> V_68 & V_69 ) != V_79 )
F_57 ( V_85 -> V_78 ) ;
F_55 ( V_85 ) ;
return 0 ;
}
static int F_58 ( struct V_9 * V_85 , struct V_83 * V_52 ,
int V_90 , int V_91 )
{
struct V_65 * V_66 = NULL ;
int V_92 , V_86 ;
V_92 = F_59 ( V_52 -> V_52 . V_22 , V_91 ) ;
if ( V_92 == V_30 ) {
F_30 ( & V_52 -> V_52 , L_12 ,
V_44 , V_91 ) ;
return 0 ;
}
V_66 = F_60 ( sizeof( struct V_65 ) , V_93 ) ;
if ( ! V_66 ) {
F_30 ( & V_52 -> V_52 , L_13 ) ;
return - V_51 ;
}
F_61 ( V_92 , & V_94 ) ;
V_85 -> V_89 [ V_91 ] = V_92 ;
V_66 -> V_75 = V_90 ;
V_66 -> V_10 = V_85 ;
F_62 ( V_92 , V_66 ) ;
F_63 ( V_92 , F_34 ) ;
for ( V_86 = 0 ; V_86 < V_95 ; V_86 ++ )
F_17 ( & V_85 -> V_19 ,
F_47 ( V_85 , V_90 , V_86 ) , 1 ) ;
return 0 ;
}
static int F_64 ( struct V_83 * V_52 )
{
const struct V_96 * V_97 ;
struct V_9 * V_85 ;
struct V_98 V_99 , V_100 ;
int V_101 , V_86 , V_102 , V_91 , V_103 ;
const T_1 * V_104 ;
const struct V_105 * V_106 ;
int V_38 ;
T_1 V_90 ;
V_97 = F_65 ( V_107 , & V_52 -> V_52 ) ;
if ( ! V_97 )
return - V_54 ;
V_106 = V_97 -> V_43 ;
F_66 ( V_108 L_14 ) ;
V_85 = F_60 ( sizeof( struct V_9 ) , V_93 ) ;
if ( ! V_85 ) {
F_30 ( & V_52 -> V_52 , L_15 ) ;
return - V_51 ;
}
F_67 ( V_52 , V_85 ) ;
V_85 -> V_21 = F_68 ( V_52 -> V_52 . V_22 ,
V_20 , & V_109 , V_85 ) ;
if ( V_85 -> V_21 == NULL ) {
F_30 ( & V_52 -> V_52 , L_16 ) ;
V_101 = - V_51 ;
goto V_110;
}
if ( ( V_106 -> V_111 & V_69 ) != V_79 ) {
V_101 = F_69 ( V_52 -> V_52 . V_22 , 0 , & V_99 ) ;
if ( V_101 ) {
F_30 ( & V_52 -> V_52 , L_17 ,
V_52 -> V_52 . V_22 -> V_53 ) ;
goto V_110;
}
V_85 -> V_78 = F_70 ( V_99 . V_112 , F_71 ( & V_99 ) ) ;
if ( ! V_85 -> V_78 ) {
V_101 = - V_51 ;
F_30 ( & V_52 -> V_52 , L_18 ,
V_52 -> V_52 . V_22 -> V_53 ) ;
goto V_110;
}
V_85 -> V_40 =
V_106 -> V_40 + ( V_99 . V_112 & 0xfffff ) ;
if ( F_69 ( V_52 -> V_52 . V_22 , 1 , & V_100 ) )
V_85 -> V_40 = V_106 -> V_40 +
( V_99 . V_112 & V_113 ) ;
else
V_85 -> V_40 = V_100 . V_112 & V_113 ;
}
V_85 -> V_68 = V_106 -> V_111 ;
V_85 -> T_6 = V_52 -> V_52 . V_22 -> T_6 ;
V_101 = F_8 ( V_85 ) ;
if ( V_101 ) {
F_30 ( & V_52 -> V_52 , L_19 ) ;
goto V_110;
}
V_104 = F_22 ( V_52 -> V_52 . V_22 , L_20 , & V_38 ) ;
if ( F_29 ( V_52 -> V_52 . V_22 , L_21 ) ) {
V_85 -> V_45 = V_114 ;
V_85 -> V_47 = V_115 ;
if ( V_104 )
F_72 ( & V_52 -> V_52 , L_22 ,
V_44 ) ;
for ( V_91 = 0 ; V_91 < V_116 ;
V_91 ++ ) {
V_101 = F_58 ( V_85 , V_52 ,
V_91 , V_91 ) ;
if ( V_101 )
goto V_110;
}
} else {
static const T_1 V_117 [] =
{ 0 , V_118 * V_95 } ;
V_85 -> V_45 = V_119 ;
V_85 -> V_47 = V_120 ;
if ( V_104 && V_38 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_30 ( & V_52 -> V_52 , L_23 ,
V_44 ) ;
V_101 = - V_54 ;
goto V_110;
}
if ( ! V_104 ) {
V_104 = V_117 ;
V_38 = sizeof( V_117 ) ;
}
for ( V_91 = 0 , V_86 = 0 ; V_86 < V_38 / ( 2 * sizeof( T_1 ) ) ; V_86 ++ ) {
if ( V_104 [ V_86 * 2 ] % V_95 ||
V_104 [ V_86 * 2 + 1 ] % V_95 ) {
F_73 ( L_24 ,
V_44 , V_52 -> V_52 . V_22 -> V_53 ,
V_104 [ V_86 * 2 + 1 ] , V_104 [ V_86 * 2 ] ) ;
V_101 = - V_54 ;
goto V_110;
}
V_90 = V_104 [ V_86 * 2 ] / V_95 ;
V_103 = V_104 [ V_86 * 2 + 1 ] / V_95 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ , V_91 ++ ) {
V_101 = F_58 ( V_85 , V_52 , V_90 + V_102 ,
V_91 ) ;
if ( V_101 )
goto V_110;
}
}
}
F_74 ( & V_85 -> V_87 , & V_121 ) ;
if ( ! V_122 . V_123 ) {
V_122 . V_123 = F_27 ;
V_122 . V_124 = F_13 ;
V_122 . V_125 = F_11 ;
} else if ( V_122 . V_123 != F_27 ) {
F_30 ( & V_52 -> V_52 , L_25 ) ;
V_101 = - V_126 ;
goto V_110;
}
return 0 ;
V_110:
F_52 ( V_52 ) ;
return V_101 ;
}
static T_7 int F_75 ( void )
{
return F_76 ( & V_127 ) ;
}

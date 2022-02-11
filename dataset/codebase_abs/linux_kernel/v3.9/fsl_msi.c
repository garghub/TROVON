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
int V_17 ;
V_17 = F_9 ( & V_10 -> V_18 , V_19 ,
V_10 -> V_20 -> V_21 ) ;
if ( V_17 )
return V_17 ;
V_17 = F_10 ( & V_10 -> V_18 ) ;
if ( V_17 < 0 ) {
F_11 ( & V_10 -> V_18 ) ;
return V_17 ;
}
return 0 ;
}
static int F_12 ( struct V_22 * V_23 , int V_24 , int type )
{
if ( type == V_25 )
F_13 ( L_1 ) ;
return 0 ;
}
static void F_14 ( struct V_22 * V_23 )
{
struct V_26 * V_27 ;
struct V_9 * V_10 ;
F_15 (entry, &pdev->msi_list, list) {
if ( V_27 -> V_28 == V_29 )
continue;
V_10 = F_16 ( V_27 -> V_28 ) ;
F_17 ( V_27 -> V_28 , NULL ) ;
F_18 ( & V_10 -> V_18 ,
F_19 ( V_27 -> V_28 ) , 1 ) ;
F_20 ( V_27 -> V_28 ) ;
}
return;
}
static void F_21 ( struct V_22 * V_23 , int V_30 ,
struct V_31 * V_32 ,
struct V_9 * V_33 )
{
struct V_9 * V_10 = V_33 ;
struct V_34 * V_35 = F_22 ( V_23 -> V_36 ) ;
T_4 V_37 ;
int V_38 ;
const T_5 * V_2 ;
V_2 = F_23 ( V_35 -> V_39 , L_2 , & V_38 ) ;
if ( V_2 && ( V_38 == sizeof( T_4 ) ) )
V_37 = F_24 ( V_2 ) ;
else
V_37 = F_25 ( V_35 ) + V_10 -> V_40 ;
V_32 -> V_41 = F_26 ( V_37 ) ;
V_32 -> V_42 = F_27 ( V_37 ) ;
V_32 -> V_43 = V_30 ;
F_13 ( L_3 ,
V_44 , V_30 / V_45 , V_30 % V_45 ) ;
}
static int F_28 ( struct V_22 * V_23 , int V_24 , int type )
{
struct V_34 * V_35 = F_22 ( V_23 -> V_36 ) ;
struct V_46 * V_47 ;
T_6 T_6 = 0 ;
int V_17 , V_30 = - V_48 ;
unsigned int V_7 ;
struct V_26 * V_27 ;
struct V_31 V_32 ;
struct V_9 * V_10 ;
V_47 = F_29 ( V_35 -> V_39 , L_4 , 0 ) ;
if ( V_47 ) {
if ( F_30 ( V_47 , L_5 ) ||
F_30 ( V_47 , L_6 ) )
T_6 = V_47 -> T_6 ;
else {
F_31 ( & V_23 -> V_49 ,
L_7 ,
V_35 -> V_39 -> V_50 , V_47 -> T_6 ) ;
return - V_51 ;
}
}
F_15 (entry, &pdev->msi_list, list) {
F_15 (msi_data, &msi_head, list) {
if ( T_6 && ( T_6 != V_10 -> T_6 ) )
continue;
V_30 = F_32 ( & V_10 -> V_18 , 1 ) ;
if ( V_30 >= 0 )
break;
}
if ( V_30 < 0 ) {
V_17 = V_30 ;
F_31 ( & V_23 -> V_49 , L_8 ) ;
goto V_52;
}
V_7 = F_33 ( V_10 -> V_20 , V_30 ) ;
if ( V_7 == V_29 ) {
F_31 ( & V_23 -> V_49 , L_9 , V_30 ) ;
F_18 ( & V_10 -> V_18 , V_30 , 1 ) ;
V_17 = - V_53 ;
goto V_52;
}
F_17 ( V_7 , V_27 ) ;
F_21 ( V_23 , V_30 , & V_32 , V_10 ) ;
F_34 ( V_7 , & V_32 ) ;
}
return 0 ;
V_52:
return V_17 ;
}
static void F_35 ( unsigned int V_28 , struct V_54 * V_55 )
{
struct V_12 * V_13 = F_36 ( V_55 ) ;
struct V_3 * V_56 = F_37 ( V_55 ) ;
unsigned int V_57 ;
struct V_9 * V_10 ;
int V_58 = - 1 ;
T_1 V_59 = 0 ;
T_1 V_60 ;
T_1 V_61 = 0 ;
struct V_62 * V_63 ;
V_63 = F_38 ( V_28 ) ;
V_10 = V_63 -> V_10 ;
F_39 ( & V_55 -> V_64 ) ;
if ( ( V_10 -> V_65 & V_66 ) == V_67 ) {
if ( V_13 -> V_68 )
V_13 -> V_68 ( V_56 ) ;
else {
V_13 -> V_69 ( V_56 ) ;
V_13 -> V_70 ( V_56 ) ;
}
}
if ( F_40 ( F_41 ( V_56 ) ) )
goto V_71;
V_58 = V_63 -> V_72 ;
if ( V_58 >= V_73 )
V_57 = V_29 ;
F_42 ( V_56 ) ;
switch ( V_10 -> V_65 & V_66 ) {
case V_74 :
V_59 = F_1 ( V_10 -> V_75 ,
V_58 * 0x10 ) ;
break;
case V_67 :
V_59 = F_1 ( V_10 -> V_75 , V_58 * 0x4 ) ;
break;
#ifdef F_43
case V_76 : {
unsigned int V_77 ;
V_77 = F_44 ( F_19 ( V_28 ) , & V_59 ) ;
if ( V_77 ) {
F_45 ( L_10
L_11 , V_28 , V_77 ) ;
V_59 = 0 ;
}
break;
}
#endif
}
while ( V_59 ) {
V_60 = F_46 ( V_59 ) - 1 ;
V_57 = F_47 ( V_10 -> V_20 ,
V_58 * V_45 +
V_60 + V_61 ) ;
if ( V_57 != V_29 )
F_48 ( V_57 ) ;
V_61 += V_60 + 1 ;
V_59 = V_59 >> ( V_60 + 1 ) ;
}
F_49 ( V_56 ) ;
switch ( V_10 -> V_65 & V_66 ) {
case V_74 :
case V_76 :
V_13 -> V_78 ( V_56 ) ;
break;
case V_67 :
if ( ! F_50 ( V_56 ) && V_13 -> V_79 )
V_13 -> V_79 ( V_56 ) ;
break;
}
V_71:
F_51 ( & V_55 -> V_64 ) ;
}
static int F_52 ( struct V_80 * V_81 )
{
struct V_9 * V_82 = F_53 ( V_81 ) ;
int V_7 , V_83 ;
struct V_62 * V_63 ;
if ( V_82 -> V_84 . V_85 != NULL )
F_54 ( & V_82 -> V_84 ) ;
for ( V_83 = 0 ; V_83 < V_73 ; V_83 ++ ) {
V_7 = V_82 -> V_86 [ V_83 ] ;
if ( V_7 != V_29 ) {
V_63 = F_38 ( V_7 ) ;
F_55 ( V_63 ) ;
F_20 ( V_7 ) ;
}
}
if ( V_82 -> V_18 . V_18 )
F_11 ( & V_82 -> V_18 ) ;
if ( ( V_82 -> V_65 & V_66 ) != V_76 )
F_56 ( V_82 -> V_75 ) ;
F_55 ( V_82 ) ;
return 0 ;
}
static int F_57 ( struct V_9 * V_82 , struct V_80 * V_49 ,
int V_87 , int V_88 )
{
struct V_62 * V_63 = NULL ;
int V_89 ;
V_89 = F_58 ( V_49 -> V_49 . V_21 , V_88 ) ;
if ( V_89 == V_29 ) {
F_31 ( & V_49 -> V_49 , L_12 ,
V_44 , V_88 ) ;
return 0 ;
}
V_63 = F_59 ( sizeof( struct V_62 ) , V_90 ) ;
if ( ! V_63 ) {
F_31 ( & V_49 -> V_49 , L_13 ) ;
return - V_48 ;
}
V_82 -> V_86 [ V_88 ] = V_89 ;
V_63 -> V_72 = V_87 ;
V_63 -> V_10 = V_82 ;
F_60 ( V_89 , V_63 ) ;
F_61 ( V_89 , F_35 ) ;
return 0 ;
}
static int F_62 ( struct V_80 * V_49 )
{
const struct V_91 * V_92 ;
struct V_9 * V_82 ;
struct V_93 V_94 ;
int V_95 , V_83 , V_96 , V_88 , V_97 ;
int V_17 ;
const T_1 * V_98 ;
const struct V_99 * V_100 ;
int V_38 ;
T_1 V_87 ;
static const T_1 V_101 [] = { 0 , V_19 } ;
V_92 = F_63 ( V_102 , & V_49 -> V_49 ) ;
if ( ! V_92 )
return - V_51 ;
V_100 = V_92 -> V_43 ;
F_64 ( V_103 L_14 ) ;
V_82 = F_59 ( sizeof( struct V_9 ) , V_90 ) ;
if ( ! V_82 ) {
F_31 ( & V_49 -> V_49 , L_15 ) ;
return - V_48 ;
}
F_65 ( V_49 , V_82 ) ;
V_82 -> V_20 = F_66 ( V_49 -> V_49 . V_21 ,
V_19 , & V_104 , V_82 ) ;
if ( V_82 -> V_20 == NULL ) {
F_31 ( & V_49 -> V_49 , L_16 ) ;
V_95 = - V_48 ;
goto V_105;
}
if ( ( V_100 -> V_106 & V_66 ) != V_76 ) {
V_95 = F_67 ( V_49 -> V_49 . V_21 , 0 , & V_94 ) ;
if ( V_95 ) {
F_31 ( & V_49 -> V_49 , L_17 ,
V_49 -> V_49 . V_21 -> V_50 ) ;
goto V_105;
}
V_82 -> V_75 = F_68 ( V_94 . V_107 , F_69 ( & V_94 ) ) ;
if ( ! V_82 -> V_75 ) {
V_95 = - V_48 ;
F_31 ( & V_49 -> V_49 , L_18 ,
V_49 -> V_49 . V_21 -> V_50 ) ;
goto V_105;
}
V_82 -> V_40 =
V_100 -> V_40 + ( V_94 . V_107 & 0xfffff ) ;
}
V_82 -> V_65 = V_100 -> V_106 ;
V_82 -> T_6 = V_49 -> V_49 . V_21 -> T_6 ;
V_17 = F_8 ( V_82 ) ;
if ( V_17 ) {
F_31 ( & V_49 -> V_49 , L_19 ) ;
goto V_105;
}
V_98 = F_23 ( V_49 -> V_49 . V_21 , L_20 , & V_38 ) ;
if ( V_98 && V_38 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_31 ( & V_49 -> V_49 , L_21 ,
V_44 ) ;
V_95 = - V_51 ;
goto V_105;
}
if ( ! V_98 ) {
V_98 = V_101 ;
V_38 = sizeof( V_101 ) ;
}
for ( V_88 = 0 , V_83 = 0 ; V_83 < V_38 / ( 2 * sizeof( T_1 ) ) ; V_83 ++ ) {
if ( V_98 [ V_83 * 2 ] % V_45 ||
V_98 [ V_83 * 2 + 1 ] % V_45 ) {
F_64 ( V_108 L_22 ,
V_44 , V_49 -> V_49 . V_21 -> V_50 ,
V_98 [ V_83 * 2 + 1 ] , V_98 [ V_83 * 2 ] ) ;
V_95 = - V_51 ;
goto V_105;
}
V_87 = V_98 [ V_83 * 2 ] / V_45 ;
V_97 = V_98 [ V_83 * 2 + 1 ] / V_45 ;
for ( V_96 = 0 ; V_96 < V_97 ; V_96 ++ , V_88 ++ ) {
V_95 = F_57 ( V_82 , V_49 , V_87 + V_96 , V_88 ) ;
if ( V_95 )
goto V_105;
}
}
F_70 ( & V_82 -> V_84 , & V_109 ) ;
if ( ! V_110 . V_111 ) {
V_110 . V_111 = F_28 ;
V_110 . V_112 = F_14 ;
V_110 . V_113 = F_12 ;
} else if ( V_110 . V_111 != F_28 ) {
F_31 ( & V_49 -> V_49 , L_23 ) ;
V_95 = - V_114 ;
goto V_105;
}
return 0 ;
V_105:
F_52 ( V_49 ) ;
return V_95 ;
}
static T_7 int F_71 ( void )
{
return F_72 ( & V_115 ) ;
}

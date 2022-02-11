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
T_4 V_1 = F_23 ( V_35 ) ;
V_32 -> V_37 = V_10 -> V_38 + F_24 ( V_1 ) ;
V_32 -> V_39 = V_10 -> V_40 + F_25 ( V_1 ) ;
V_32 -> V_41 = V_30 ;
F_13 ( L_2 ,
V_42 , V_30 / V_43 , V_30 % V_43 ) ;
}
static int F_26 ( struct V_22 * V_23 , int V_24 , int type )
{
int V_17 , V_30 = - V_44 ;
unsigned int V_7 ;
struct V_26 * V_27 ;
struct V_31 V_32 ;
struct V_9 * V_10 ;
F_15 (entry, &pdev->msi_list, list) {
F_15 (msi_data, &msi_head, list) {
V_30 = F_27 ( & V_10 -> V_18 , 1 ) ;
if ( V_30 >= 0 )
break;
}
if ( V_30 < 0 ) {
V_17 = V_30 ;
F_13 ( L_3 ,
V_42 ) ;
goto V_45;
}
V_7 = F_28 ( V_10 -> V_20 , V_30 ) ;
if ( V_7 == V_29 ) {
F_13 ( L_4 ,
V_42 , V_30 ) ;
F_18 ( & V_10 -> V_18 , V_30 , 1 ) ;
V_17 = - V_46 ;
goto V_45;
}
F_17 ( V_7 , V_27 ) ;
F_21 ( V_23 , V_30 , & V_32 , V_10 ) ;
F_29 ( V_7 , & V_32 ) ;
}
return 0 ;
V_45:
return V_17 ;
}
static void F_30 ( unsigned int V_28 , struct V_47 * V_48 )
{
struct V_12 * V_13 = F_31 ( V_48 ) ;
struct V_3 * V_49 = F_32 ( V_48 ) ;
unsigned int V_50 ;
struct V_9 * V_10 ;
int V_51 = - 1 ;
T_1 V_52 = 0 ;
T_1 V_53 ;
T_1 V_54 = 0 ;
struct V_55 * V_56 ;
V_56 = F_33 ( V_28 ) ;
V_10 = V_56 -> V_10 ;
F_34 ( & V_48 -> V_57 ) ;
if ( ( V_10 -> V_58 & V_59 ) == V_60 ) {
if ( V_13 -> V_61 )
V_13 -> V_61 ( V_49 ) ;
else {
V_13 -> V_62 ( V_49 ) ;
V_13 -> V_63 ( V_49 ) ;
}
}
if ( F_35 ( F_36 ( V_49 ) ) )
goto V_64;
V_51 = V_56 -> V_65 ;
if ( V_51 >= V_66 )
V_50 = V_29 ;
F_37 ( V_49 ) ;
switch ( V_10 -> V_58 & V_59 ) {
case V_67 :
V_52 = F_1 ( V_10 -> V_68 ,
V_51 * 0x10 ) ;
break;
case V_60 :
V_52 = F_1 ( V_10 -> V_68 , V_51 * 0x4 ) ;
break;
}
while ( V_52 ) {
V_53 = F_38 ( V_52 ) - 1 ;
V_50 = F_39 ( V_10 -> V_20 ,
V_51 * V_43 +
V_53 + V_54 ) ;
if ( V_50 != V_29 )
F_40 ( V_50 ) ;
V_54 += V_53 + 1 ;
V_52 = V_52 >> ( V_53 + 1 ) ;
}
F_41 ( V_49 ) ;
switch ( V_10 -> V_58 & V_59 ) {
case V_67 :
V_13 -> V_69 ( V_49 ) ;
break;
case V_60 :
if ( ! F_42 ( V_49 ) && V_13 -> V_70 )
V_13 -> V_70 ( V_49 ) ;
break;
}
V_64:
F_43 ( & V_48 -> V_57 ) ;
}
static int F_44 ( struct V_71 * V_72 )
{
struct V_9 * V_73 = F_45 ( V_72 ) ;
int V_7 , V_74 ;
struct V_55 * V_56 ;
if ( V_73 -> V_75 . V_76 != NULL )
F_46 ( & V_73 -> V_75 ) ;
for ( V_74 = 0 ; V_74 < V_66 ; V_74 ++ ) {
V_7 = V_73 -> V_77 [ V_74 ] ;
if ( V_7 != V_29 ) {
V_56 = F_33 ( V_7 ) ;
F_47 ( V_56 ) ;
F_20 ( V_7 ) ;
}
}
if ( V_73 -> V_18 . V_18 )
F_11 ( & V_73 -> V_18 ) ;
F_48 ( V_73 -> V_68 ) ;
F_47 ( V_73 ) ;
return 0 ;
}
static int T_5 F_49 ( struct V_9 * V_73 ,
struct V_71 * V_78 ,
int V_79 , int V_80 )
{
struct V_55 * V_56 = NULL ;
int V_81 ;
V_81 = F_50 ( V_78 -> V_78 . V_21 , V_80 ) ;
if ( V_81 == V_29 ) {
F_51 ( & V_78 -> V_78 , L_5 ,
V_42 , V_80 ) ;
return 0 ;
}
V_56 = F_52 ( sizeof( struct V_55 ) , V_82 ) ;
if ( ! V_56 ) {
F_51 ( & V_78 -> V_78 , L_6 ) ;
return - V_44 ;
}
V_73 -> V_77 [ V_80 ] = V_81 ;
V_56 -> V_65 = V_79 + V_80 ;
V_56 -> V_10 = V_73 ;
F_53 ( V_81 , V_56 ) ;
F_54 ( V_81 , F_30 ) ;
return 0 ;
}
static int T_5 F_55 ( struct V_71 * V_78 )
{
const struct V_83 * V_84 ;
struct V_9 * V_73 ;
struct V_85 V_86 ;
int V_87 , V_74 , V_88 , V_80 , V_89 ;
int V_17 ;
const T_1 * V_90 ;
struct V_91 * V_92 ;
int V_93 ;
T_1 V_79 ;
static const T_1 V_94 [] = { 0 , V_19 } ;
V_84 = F_56 ( V_95 , & V_78 -> V_78 ) ;
if ( ! V_84 )
return - V_96 ;
V_92 = V_84 -> V_41 ;
F_57 ( V_97 L_7 ) ;
V_73 = F_52 ( sizeof( struct V_9 ) , V_82 ) ;
if ( ! V_73 ) {
F_51 ( & V_78 -> V_78 , L_8 ) ;
return - V_44 ;
}
F_58 ( V_78 , V_73 ) ;
V_73 -> V_20 = F_59 ( V_78 -> V_78 . V_21 , V_98 ,
V_19 , & V_99 , 0 ) ;
if ( V_73 -> V_20 == NULL ) {
F_51 ( & V_78 -> V_78 , L_9 ) ;
V_87 = - V_44 ;
goto V_100;
}
V_87 = F_60 ( V_78 -> V_78 . V_21 , 0 , & V_86 ) ;
if ( V_87 ) {
F_51 ( & V_78 -> V_78 , L_10 ,
V_78 -> V_78 . V_21 -> V_101 ) ;
goto V_100;
}
V_73 -> V_68 = F_61 ( V_86 . V_102 , F_62 ( & V_86 ) ) ;
if ( ! V_73 -> V_68 ) {
F_51 ( & V_78 -> V_78 , L_11 ) ;
goto V_100;
}
V_73 -> V_58 = V_92 -> V_103 ;
V_73 -> V_20 -> V_11 = V_73 ;
V_73 -> V_40 = 0x0 ;
V_73 -> V_38 = V_92 -> V_104 + ( V_86 . V_102 & 0xfffff ) ;
V_17 = F_8 ( V_73 ) ;
if ( V_17 ) {
F_51 ( & V_78 -> V_78 , L_12 ) ;
goto V_100;
}
V_90 = F_63 ( V_78 -> V_78 . V_21 , L_13 , & V_93 ) ;
if ( V_90 && V_93 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_51 ( & V_78 -> V_78 , L_14 ,
V_42 ) ;
V_87 = - V_96 ;
goto V_100;
}
if ( ! V_90 )
V_90 = V_94 ;
for ( V_80 = 0 , V_74 = 0 ; V_74 < V_93 / ( 2 * sizeof( T_1 ) ) ; V_74 ++ ) {
if ( V_90 [ V_74 * 2 ] % V_43 ||
V_90 [ V_74 * 2 + 1 ] % V_43 ) {
F_57 ( V_105 L_15 ,
V_42 , V_78 -> V_78 . V_21 -> V_101 ,
V_90 [ V_74 * 2 + 1 ] , V_90 [ V_74 * 2 ] ) ;
V_87 = - V_96 ;
goto V_100;
}
V_79 = V_90 [ V_74 * 2 ] / V_43 ;
V_89 = V_90 [ V_74 * 2 + 1 ] / V_43 ;
for ( V_88 = 0 ; V_88 < V_89 ; V_88 ++ , V_80 ++ ) {
V_87 = F_49 ( V_73 , V_78 , V_79 , V_80 ) ;
if ( V_87 )
goto V_100;
}
}
F_64 ( & V_73 -> V_75 , & V_106 ) ;
if ( ! V_107 . V_108 ) {
V_107 . V_108 = F_26 ;
V_107 . V_109 = F_14 ;
V_107 . V_110 = F_12 ;
} else if ( V_107 . V_108 != F_26 ) {
F_51 ( & V_78 -> V_78 , L_16 ) ;
V_87 = - V_111 ;
goto V_100;
}
return 0 ;
V_100:
F_44 ( V_78 ) ;
return V_87 ;
}
static T_6 int F_65 ( void )
{
return F_66 ( & V_112 ) ;
}

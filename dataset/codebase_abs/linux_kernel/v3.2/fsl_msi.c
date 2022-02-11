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
const T_4 * V_2 ;
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
int V_17 , V_30 = - V_46 ;
unsigned int V_7 ;
struct V_26 * V_27 ;
struct V_31 V_32 ;
struct V_9 * V_10 ;
F_15 (entry, &pdev->msi_list, list) {
F_15 (msi_data, &msi_head, list) {
V_30 = F_29 ( & V_10 -> V_18 , 1 ) ;
if ( V_30 >= 0 )
break;
}
if ( V_30 < 0 ) {
V_17 = V_30 ;
F_13 ( L_4 ,
V_44 ) ;
goto V_47;
}
V_7 = F_30 ( V_10 -> V_20 , V_30 ) ;
if ( V_7 == V_29 ) {
F_13 ( L_5 ,
V_44 , V_30 ) ;
F_18 ( & V_10 -> V_18 , V_30 , 1 ) ;
V_17 = - V_48 ;
goto V_47;
}
F_17 ( V_7 , V_27 ) ;
F_21 ( V_23 , V_30 , & V_32 , V_10 ) ;
F_31 ( V_7 , & V_32 ) ;
}
return 0 ;
V_47:
return V_17 ;
}
static void F_32 ( unsigned int V_28 , struct V_49 * V_50 )
{
struct V_12 * V_13 = F_33 ( V_50 ) ;
struct V_3 * V_51 = F_34 ( V_50 ) ;
unsigned int V_52 ;
struct V_9 * V_10 ;
int V_53 = - 1 ;
T_1 V_54 = 0 ;
T_1 V_55 ;
T_1 V_56 = 0 ;
struct V_57 * V_58 ;
V_58 = F_35 ( V_28 ) ;
V_10 = V_58 -> V_10 ;
F_36 ( & V_50 -> V_59 ) ;
if ( ( V_10 -> V_60 & V_61 ) == V_62 ) {
if ( V_13 -> V_63 )
V_13 -> V_63 ( V_51 ) ;
else {
V_13 -> V_64 ( V_51 ) ;
V_13 -> V_65 ( V_51 ) ;
}
}
if ( F_37 ( F_38 ( V_51 ) ) )
goto V_66;
V_53 = V_58 -> V_67 ;
if ( V_53 >= V_68 )
V_52 = V_29 ;
F_39 ( V_51 ) ;
switch ( V_10 -> V_60 & V_61 ) {
case V_69 :
V_54 = F_1 ( V_10 -> V_70 ,
V_53 * 0x10 ) ;
break;
case V_62 :
V_54 = F_1 ( V_10 -> V_70 , V_53 * 0x4 ) ;
break;
}
while ( V_54 ) {
V_55 = F_40 ( V_54 ) - 1 ;
V_52 = F_41 ( V_10 -> V_20 ,
V_53 * V_45 +
V_55 + V_56 ) ;
if ( V_52 != V_29 )
F_42 ( V_52 ) ;
V_56 += V_55 + 1 ;
V_54 = V_54 >> ( V_55 + 1 ) ;
}
F_43 ( V_51 ) ;
switch ( V_10 -> V_60 & V_61 ) {
case V_69 :
V_13 -> V_71 ( V_51 ) ;
break;
case V_62 :
if ( ! F_44 ( V_51 ) && V_13 -> V_72 )
V_13 -> V_72 ( V_51 ) ;
break;
}
V_66:
F_45 ( & V_50 -> V_59 ) ;
}
static int F_46 ( struct V_73 * V_74 )
{
struct V_9 * V_75 = F_47 ( V_74 ) ;
int V_7 , V_76 ;
struct V_57 * V_58 ;
if ( V_75 -> V_77 . V_78 != NULL )
F_48 ( & V_75 -> V_77 ) ;
for ( V_76 = 0 ; V_76 < V_68 ; V_76 ++ ) {
V_7 = V_75 -> V_79 [ V_76 ] ;
if ( V_7 != V_29 ) {
V_58 = F_35 ( V_7 ) ;
F_49 ( V_58 ) ;
F_20 ( V_7 ) ;
}
}
if ( V_75 -> V_18 . V_18 )
F_11 ( & V_75 -> V_18 ) ;
F_50 ( V_75 -> V_70 ) ;
F_49 ( V_75 ) ;
return 0 ;
}
static int T_5 F_51 ( struct V_9 * V_75 ,
struct V_73 * V_80 ,
int V_81 , int V_82 )
{
struct V_57 * V_58 = NULL ;
int V_83 ;
V_83 = F_52 ( V_80 -> V_80 . V_21 , V_82 ) ;
if ( V_83 == V_29 ) {
F_53 ( & V_80 -> V_80 , L_6 ,
V_44 , V_82 ) ;
return 0 ;
}
V_58 = F_54 ( sizeof( struct V_57 ) , V_84 ) ;
if ( ! V_58 ) {
F_53 ( & V_80 -> V_80 , L_7 ) ;
return - V_46 ;
}
V_75 -> V_79 [ V_82 ] = V_83 ;
V_58 -> V_67 = V_81 ;
V_58 -> V_10 = V_75 ;
F_55 ( V_83 , V_58 ) ;
F_56 ( V_83 , F_32 ) ;
return 0 ;
}
static int T_5 F_57 ( struct V_73 * V_80 )
{
const struct V_85 * V_86 ;
struct V_9 * V_75 ;
struct V_87 V_88 ;
int V_89 , V_76 , V_90 , V_82 , V_91 ;
int V_17 ;
const T_1 * V_92 ;
struct V_93 * V_94 ;
int V_38 ;
T_1 V_81 ;
static const T_1 V_95 [] = { 0 , V_19 } ;
V_86 = F_58 ( V_96 , & V_80 -> V_80 ) ;
if ( ! V_86 )
return - V_97 ;
V_94 = V_86 -> V_43 ;
F_59 ( V_98 L_8 ) ;
V_75 = F_54 ( sizeof( struct V_9 ) , V_84 ) ;
if ( ! V_75 ) {
F_53 ( & V_80 -> V_80 , L_9 ) ;
return - V_46 ;
}
F_60 ( V_80 , V_75 ) ;
V_75 -> V_20 = F_61 ( V_80 -> V_80 . V_21 , V_99 ,
V_19 , & V_100 , 0 ) ;
if ( V_75 -> V_20 == NULL ) {
F_53 ( & V_80 -> V_80 , L_10 ) ;
V_89 = - V_46 ;
goto V_101;
}
V_89 = F_62 ( V_80 -> V_80 . V_21 , 0 , & V_88 ) ;
if ( V_89 ) {
F_53 ( & V_80 -> V_80 , L_11 ,
V_80 -> V_80 . V_21 -> V_102 ) ;
goto V_101;
}
V_75 -> V_70 = F_63 ( V_88 . V_103 , F_64 ( & V_88 ) ) ;
if ( ! V_75 -> V_70 ) {
F_53 ( & V_80 -> V_80 , L_12 ) ;
goto V_101;
}
V_75 -> V_60 = V_94 -> V_104 ;
V_75 -> V_20 -> V_11 = V_75 ;
V_75 -> V_40 = V_94 -> V_40 + ( V_88 . V_103 & 0xfffff ) ;
V_17 = F_8 ( V_75 ) ;
if ( V_17 ) {
F_53 ( & V_80 -> V_80 , L_13 ) ;
goto V_101;
}
V_92 = F_23 ( V_80 -> V_80 . V_21 , L_14 , & V_38 ) ;
if ( V_92 && V_38 % ( 2 * sizeof( T_1 ) ) != 0 ) {
F_53 ( & V_80 -> V_80 , L_15 ,
V_44 ) ;
V_89 = - V_97 ;
goto V_101;
}
if ( ! V_92 ) {
V_92 = V_95 ;
V_38 = sizeof( V_95 ) ;
}
for ( V_82 = 0 , V_76 = 0 ; V_76 < V_38 / ( 2 * sizeof( T_1 ) ) ; V_76 ++ ) {
if ( V_92 [ V_76 * 2 ] % V_45 ||
V_92 [ V_76 * 2 + 1 ] % V_45 ) {
F_59 ( V_105 L_16 ,
V_44 , V_80 -> V_80 . V_21 -> V_102 ,
V_92 [ V_76 * 2 + 1 ] , V_92 [ V_76 * 2 ] ) ;
V_89 = - V_97 ;
goto V_101;
}
V_81 = V_92 [ V_76 * 2 ] / V_45 ;
V_91 = V_92 [ V_76 * 2 + 1 ] / V_45 ;
for ( V_90 = 0 ; V_90 < V_91 ; V_90 ++ , V_82 ++ ) {
V_89 = F_51 ( V_75 , V_80 , V_81 + V_90 , V_82 ) ;
if ( V_89 )
goto V_101;
}
}
F_65 ( & V_75 -> V_77 , & V_106 ) ;
if ( ! V_107 . V_108 ) {
V_107 . V_108 = F_28 ;
V_107 . V_109 = F_14 ;
V_107 . V_110 = F_12 ;
} else if ( V_107 . V_108 != F_28 ) {
F_53 ( & V_80 -> V_80 , L_17 ) ;
V_89 = - V_111 ;
goto V_101;
}
return 0 ;
V_101:
F_46 ( V_80 ) ;
return V_89 ;
}
static T_6 int F_66 ( void )
{
return F_67 ( & V_112 ) ;
}

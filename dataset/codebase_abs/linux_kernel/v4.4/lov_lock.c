static struct V_1 * F_1 ( const struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_1 * V_8 ;
struct V_9 * V_10 = F_2 ( V_3 ) ;
struct V_11 * V_12 = V_10 -> V_13 . V_14 ;
struct V_15 * V_16 ;
V_8 = & F_3 ( V_3 ) -> V_17 ;
if ( ! V_12 || ! F_4 ( V_12 -> V_18 , V_5 -> V_19 . V_20 ) ) {
V_8 -> V_21 = V_3 ;
V_8 -> V_22 = V_12 ;
V_8 -> V_23 = NULL ;
} else {
V_16 = F_5 ( V_3 , V_10 , V_7 -> V_24 ) ;
if ( ! F_6 ( V_16 ) ) {
V_8 -> V_21 = V_16 -> V_25 ;
V_8 -> V_22 = V_16 -> V_26 ;
V_8 -> V_23 = V_16 ;
} else {
V_8 = ( void * ) V_16 ;
}
}
return V_8 ;
}
static void F_7 ( struct V_1 * V_8 )
{
if ( V_8 && V_8 -> V_23 )
F_8 ( V_8 -> V_23 ) ;
}
static void F_9 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
struct V_4 * V_29 , int V_30 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 ;
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
int V_37 ;
F_10 ( F_11 ( V_5 ) ) ;
F_10 ( F_11 ( V_29 ) ) ;
V_34 = F_12 ( V_29 ) ;
F_10 ( F_13 ( V_3 , V_28 , V_34 ) == NULL ) ;
F_10 ( V_30 < V_28 -> V_38 ) ;
V_28 -> V_39 [ V_30 ] . V_40 = V_34 ;
V_28 -> V_41 ++ ;
F_10 ( V_28 -> V_41 <= V_28 -> V_38 ) ;
F_14 ( & V_32 -> V_42 , & V_34 -> V_43 ) ;
V_32 -> V_44 = V_30 ;
V_32 -> V_45 = V_28 ;
F_15 ( V_5 ) ;
F_16 ( & V_5 -> V_46 , L_1 , V_29 ) ;
V_28 -> V_39 [ V_30 ] . V_47 |= V_48 ;
F_17 ( V_3 , V_29 ) ;
V_37 = F_18 ( V_3 , V_28 , V_34 , & V_29 -> V_19 , V_30 ) ;
F_10 ( V_37 == 0 ) ;
}
static struct V_4 * F_19 ( const struct V_2 * V_3 ,
const struct V_11 * V_12 ,
struct V_27 * V_28 ,
int V_30 , struct V_31 * * V_49 )
{
struct V_4 * V_29 ;
struct V_4 * V_5 ;
struct V_31 * V_32 ;
F_10 ( V_30 < V_28 -> V_38 ) ;
V_32 = F_20 ( V_50 , V_51 | V_52 ) ;
if ( V_32 != NULL ) {
struct V_1 * V_8 ;
struct V_6 * V_7 ;
struct V_53 * V_54 ;
V_5 = V_28 -> V_35 . V_36 ;
V_7 = & V_28 -> V_39 [ V_30 ] ;
V_54 = & V_7 -> V_55 ;
V_8 = F_1 ( V_3 , V_5 , V_7 ) ;
if ( ! F_6 ( V_8 ) ) {
V_29 = F_21 ( V_8 -> V_21 , V_8 -> V_22 ,
V_54 , L_2 , V_5 ) ;
F_7 ( V_8 ) ;
} else {
V_29 = ( void * ) V_8 ;
}
if ( ! F_6 ( V_29 ) )
* V_49 = V_32 ;
else
F_22 ( V_50 , V_32 ) ;
} else
V_29 = F_23 ( - V_56 ) ;
return V_29 ;
}
static void F_24 ( const struct V_2 * V_3 ,
struct V_33 * V_34 ,
struct V_57 * V_58 ,
struct V_1 * V_8 )
{
F_7 ( V_8 ) ;
V_34 -> V_59 = NULL ;
F_25 ( V_3 , V_58 ) ;
}
static int F_26 ( const struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_6 * V_7 ,
struct V_57 * V_58 ,
struct V_1 * * V_60 )
{
struct V_33 * V_29 ;
struct V_4 * V_61 ;
int V_62 = 0 ;
F_10 ( F_27 ( & V_58 -> V_63 ) ) ;
V_29 = V_7 -> V_40 ;
V_61 = V_29 -> V_64 . V_36 ;
V_62 = F_28 ( V_3 , V_61 , V_58 ) ;
if ( V_62 == 0 ) {
struct V_4 * V_5 = V_58 -> V_65 ;
F_10 ( F_11 ( V_61 ) ) ;
V_29 -> V_59 = V_5 ;
if ( F_29 ( ( V_61 -> V_66 == V_67 ) ||
( V_61 -> V_68 & V_69 ) ) ) {
struct V_31 * V_32 ;
F_10 ( ! ( V_7 -> V_47 & V_48 ) ) ;
V_32 = F_13 ( V_3 , V_28 , V_29 ) ;
F_10 ( V_32 != NULL ) ;
F_30 ( V_3 , V_32 , V_29 ) ;
F_24 ( V_3 , V_29 , V_58 , NULL ) ;
V_28 -> V_70 = 1 ;
V_62 = V_71 ;
} else if ( V_60 ) {
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 , V_5 , V_7 ) ;
if ( F_6 ( V_8 ) ) {
F_24 ( V_3 , V_29 ,
V_58 , NULL ) ;
V_62 = F_31 ( V_8 ) ;
} else {
* V_60 = V_8 ;
}
}
}
return V_62 ;
}
static int F_32 ( int V_62 , int V_37 )
{
int V_72 ;
int V_73 ;
F_33 ( V_62 <= 0 || V_62 == V_71 || V_62 == V_74 ,
L_3 , V_62 ) ;
F_33 ( V_37 <= 0 || V_37 == V_71 || V_37 == V_74 ,
L_4 , V_37 ) ;
F_34 ( V_74 < V_71 ) ;
V_72 = V_62 < 0 ? 1 + V_71 : V_62 ;
V_73 = V_37 < 0 ? 1 + V_71 : V_37 ;
if ( V_72 < V_73 )
V_62 = V_37 ;
return V_62 ;
}
static int F_35 ( const struct V_2 * V_3 ,
struct V_27 * V_28 , const struct V_11 * V_12 )
{
int V_62 = 0 ;
int V_75 ;
int V_76 ;
T_1 V_77 ;
T_1 V_78 ;
T_1 V_79 ;
T_1 V_80 ;
struct V_81 * V_82 = F_36 ( V_28 -> V_35 . V_83 ) ;
struct V_84 * V_85 = F_37 ( V_82 ) ;
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
V_28 -> V_86 = V_5 -> V_19 ;
V_79 = F_38 ( F_39 ( V_82 ) , V_5 -> V_19 . V_87 ) ;
V_80 = F_38 ( F_39 ( V_82 ) , V_5 -> V_19 . V_88 + 1 ) - 1 ;
for ( V_75 = 0 , V_76 = 0 ; V_75 < V_85 -> V_89 ; V_75 ++ ) {
if ( F_40 ( V_85 -> V_90 [ V_75 ] != NULL ) &&
F_41 ( V_82 -> V_91 , V_75 ,
V_79 , V_80 , & V_77 , & V_78 ) )
V_76 ++ ;
}
F_10 ( V_76 > 0 ) ;
V_28 -> V_39 = F_42 ( V_76 * sizeof( V_28 -> V_39 [ 0 ] ) , V_51 ) ;
if ( V_28 -> V_39 == NULL )
return - V_56 ;
V_28 -> V_38 = V_76 ;
for ( V_75 = 0 , V_76 = 0 ; V_75 < V_85 -> V_89 ; ++ V_75 ) {
if ( F_40 ( V_85 -> V_90 [ V_75 ] != NULL ) &&
F_41 ( V_82 -> V_91 , V_75 ,
V_79 , V_80 , & V_77 , & V_78 ) ) {
struct V_53 * V_54 ;
V_54 = & V_28 -> V_39 [ V_76 ] . V_92 ;
F_10 ( V_54 -> V_20 == NULL ) ;
V_54 -> V_20 = F_43 ( V_85 -> V_90 [ V_75 ] ) ;
V_54 -> V_87 = F_44 ( V_54 -> V_20 , V_77 ) ;
V_54 -> V_88 = F_44 ( V_54 -> V_20 , V_78 ) ;
V_54 -> V_93 = V_5 -> V_19 . V_93 ;
V_54 -> V_94 = V_5 -> V_19 . V_94 ;
V_54 -> V_95 = V_5 -> V_19 . V_95 ;
V_28 -> V_39 [ V_76 ] . V_55 = * V_54 ;
V_28 -> V_39 [ V_76 ] . V_24 = V_75 ;
V_76 ++ ;
}
}
F_10 ( V_76 == V_28 -> V_38 ) ;
return V_62 ;
}
static int F_45 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
int V_75 , int V_96 , int V_37 )
{
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
F_10 ( F_11 ( V_5 ) ) ;
if ( V_28 -> V_39 [ V_75 ] . V_47 & V_48 ) {
struct V_4 * V_29 ;
int V_97 ;
F_10 ( V_28 -> V_39 [ V_75 ] . V_40 != NULL ) ;
V_29 = V_28 -> V_39 [ V_75 ] . V_40 -> V_64 . V_36 ;
F_10 ( F_11 ( V_29 ) ) ;
V_28 -> V_39 [ V_75 ] . V_47 &= ~ V_48 ;
if ( V_96 )
F_46 ( V_3 , V_29 ) ;
V_97 = ( V_29 -> V_19 . V_93 == V_98 ||
V_29 -> V_19 . V_93 == V_99 ||
( V_29 -> V_68 & ( V_100 | V_101 ) ) ) &&
V_29 -> V_102 == 1 ;
if ( V_97 )
F_47 ( V_3 , V_5 ) ;
F_48 ( V_3 , V_29 , L_2 , V_5 ) ;
if ( V_97 ) {
F_49 ( V_3 , V_5 ) ;
V_37 = F_32 ( V_37 , V_71 ) ;
}
}
return V_37 ;
}
static void F_50 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
int V_75 )
{
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
F_10 ( F_11 ( V_5 ) ) ;
if ( ! ( V_28 -> V_39 [ V_75 ] . V_47 & V_48 ) ) {
struct V_4 * V_29 ;
F_10 ( V_28 -> V_39 [ V_75 ] . V_40 != NULL ) ;
V_29 = V_28 -> V_39 [ V_75 ] . V_40 -> V_64 . V_36 ;
F_10 ( F_11 ( V_29 ) ) ;
F_10 ( V_29 -> V_66 != V_67 ) ;
V_28 -> V_39 [ V_75 ] . V_47 |= V_48 ;
F_51 ( V_29 ) ;
F_52 ( V_3 , V_29 , L_2 , V_5 ) ;
F_17 ( V_3 , V_29 ) ;
F_53 ( V_3 , V_29 ) ;
}
}
static void F_54 ( const struct V_2 * V_3 ,
struct V_103 * V_104 )
{
struct V_27 * V_28 ;
int V_75 ;
V_28 = F_55 ( V_104 ) ;
F_10 ( V_28 -> V_41 == 0 ) ;
if ( V_28 -> V_39 != NULL ) {
for ( V_75 = 0 ; V_75 < V_28 -> V_38 ; ++ V_75 )
F_10 ( V_28 -> V_39 [ V_75 ] . V_40 == NULL ) ;
F_56 ( V_28 -> V_39 ) ;
}
F_22 ( V_105 , V_28 ) ;
}
static int F_57 ( const struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_4 * V_29 )
{
struct V_4 * V_106 = V_28 -> V_35 . V_36 ;
int V_62 ;
F_10 ( F_11 ( V_106 ) ) ;
F_47 ( V_3 , V_106 ) ;
V_62 = F_58 ( V_3 , V_29 , 0 ) ;
F_49 ( V_3 , V_106 ) ;
return V_62 ? : V_71 ;
}
static int F_59 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
struct V_4 * V_29 ,
struct V_11 * V_12 , T_2 V_107 , int V_108 )
{
int V_62 ;
V_62 = F_60 ( V_3 , V_29 , V_12 , V_107 ) ;
if ( ( V_29 -> V_66 == V_109 ) && ! ( V_107 & V_110 ) ) {
V_62 = F_61 ( V_3 , V_29 ) ;
if ( V_62 == V_111 )
V_62 = V_74 ;
}
if ( ( V_62 == V_74 ) && ( V_29 -> V_66 <= V_112 ) &&
( V_107 & V_113 ) && ( ! V_108 || ( V_107 & V_110 ) ) )
V_62 = 0 ;
return V_62 ;
}
static int F_62 ( const struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_11 * V_12 , struct V_27 * V_28 , int V_30 )
{
struct V_31 * V_32 = NULL ;
struct V_4 * V_29 ;
int V_62 ;
F_10 ( V_5 -> V_114 == 1 ) ;
F_47 ( V_3 , V_5 ) ;
V_29 = F_19 ( V_3 , V_12 , V_28 , V_30 , & V_32 ) ;
if ( ! F_6 ( V_29 ) )
F_49 ( V_3 , V_29 ) ;
F_49 ( V_3 , V_5 ) ;
if ( ! F_6 ( V_29 ) ) {
F_51 ( V_29 ) ;
if ( V_5 -> V_66 == V_115 &&
V_28 -> V_39 [ V_30 ] . V_40 == NULL ) {
F_9 ( V_3 , V_28 , V_29 , V_30 , V_32 ) ;
} else {
F_22 ( V_50 , V_32 ) ;
F_47 ( V_3 , V_5 ) ;
F_48 ( V_3 , V_29 , L_2 , V_5 ) ;
F_49 ( V_3 , V_5 ) ;
}
F_47 ( V_3 , V_29 ) ;
F_53 ( V_3 , V_29 ) ;
V_62 = V_71 ;
} else
V_62 = F_31 ( V_29 ) ;
return V_62 ;
}
static int F_63 ( const struct V_2 * V_3 ,
const struct V_103 * V_104 ,
struct V_11 * V_12 , T_2 V_107 )
{
struct V_4 * V_106 = V_104 -> V_36 ;
struct V_27 * V_28 = F_55 ( V_104 ) ;
struct V_57 * V_58 = F_64 ( V_3 , V_106 ) ;
int V_75 ;
int V_62 ;
enum V_116 V_117 ;
for ( V_62 = 0 , V_117 = V_67 , V_75 = 0 ; V_75 < V_28 -> V_38 ; ++ V_75 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_6 * V_7 ;
struct V_4 * V_29 ;
struct V_1 * V_8 ;
if ( V_106 -> V_66 != V_115 ) {
F_10 ( V_75 > 0 && V_62 != 0 ) ;
break;
}
V_7 = & V_28 -> V_39 [ V_75 ] ;
V_16 = V_7 -> V_40 ;
if ( V_16 == NULL ) {
V_62 = F_62 ( V_3 , V_106 , V_12 , V_28 , V_75 ) ;
break;
}
V_29 = V_16 -> V_64 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_58 , & V_8 ) ;
if ( V_37 == 0 ) {
F_50 ( V_3 , V_28 , V_75 ) ;
V_37 = F_59 ( V_8 -> V_21 , V_28 , V_29 ,
V_8 -> V_22 , V_107 ,
V_75 == V_28 -> V_38 - 1 ) ;
V_117 = F_65 ( V_117 , V_29 -> V_66 ) ;
if ( V_37 == V_74 ) {
switch ( V_29 -> V_66 ) {
case V_115 :
F_49 ( V_3 , V_29 ) ;
F_24 ( V_3 , V_16 , V_58 ,
V_8 ) ;
V_37 = F_57 ( V_3 , V_28 ,
V_29 ) ;
break;
case V_118 :
F_15 ( V_29 ) ;
F_49 ( V_3 , V_29 ) ;
F_24 ( V_3 , V_16 , V_58 ,
V_8 ) ;
V_37 = F_45 ( V_3 , V_28 , V_75 ,
1 , V_37 ) ;
F_47 ( V_3 , V_29 ) ;
F_53 ( V_3 , V_29 ) ;
break;
default:
F_24 ( V_3 , V_16 , V_58 ,
V_8 ) ;
break;
}
} else {
F_10 ( V_29 -> V_119 == NULL ) ;
F_24 ( V_3 , V_16 , V_58 , V_8 ) ;
}
}
V_62 = F_32 ( V_62 , V_37 ) ;
if ( V_62 != 0 )
break;
}
F_66 ( V_58 ) ;
return V_62 ? : V_117 >= V_109 ? 0 : V_74 ;
}
static int F_67 ( const struct V_2 * V_3 ,
const struct V_103 * V_104 )
{
struct V_27 * V_28 = F_55 ( V_104 ) ;
struct V_57 * V_58 = F_64 ( V_3 , V_104 -> V_36 ) ;
int V_75 ;
int V_62 ;
for ( V_62 = 0 , V_75 = 0 ; V_75 < V_28 -> V_38 ; ++ V_75 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_4 * V_29 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
F_10 ( V_104 -> V_36 -> V_66 == V_120 ) ;
V_7 = & V_28 -> V_39 [ V_75 ] ;
V_16 = V_7 -> V_40 ;
if ( V_16 == NULL )
continue;
V_29 = V_16 -> V_64 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_58 , & V_8 ) ;
if ( V_37 == 0 ) {
if ( V_7 -> V_47 & V_48 ) {
F_10 ( V_29 -> V_66 == V_112 ||
V_29 -> V_66 == V_109 ) ;
V_37 = F_68 ( V_8 -> V_21 , V_29 ) ;
V_37 = F_45 ( V_3 , V_28 , V_75 , 0 , V_37 ) ;
}
F_24 ( V_3 , V_16 , V_58 , V_8 ) ;
}
V_62 = F_32 ( V_62 , V_37 ) ;
}
if ( V_62 == 0 && V_28 -> V_70 ) {
V_28 -> V_70 = 0 ;
V_62 = - V_121 ;
}
F_66 ( V_58 ) ;
return V_62 ;
}
static void F_69 ( const struct V_2 * V_3 ,
const struct V_103 * V_104 )
{
struct V_27 * V_28 = F_55 ( V_104 ) ;
struct V_57 * V_58 = F_64 ( V_3 , V_104 -> V_36 ) ;
int V_75 ;
int V_62 ;
for ( V_62 = 0 , V_75 = 0 ; V_75 < V_28 -> V_38 ; ++ V_75 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_4 * V_29 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
V_7 = & V_28 -> V_39 [ V_75 ] ;
V_16 = V_7 -> V_40 ;
if ( V_16 == NULL )
continue;
V_29 = V_16 -> V_64 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_58 , & V_8 ) ;
if ( V_37 == 0 ) {
if ( ! ( V_7 -> V_47 & V_48 ) ) {
F_24 ( V_3 , V_16 , V_58 , V_8 ) ;
continue;
}
switch ( V_29 -> V_66 ) {
case V_112 :
V_37 = F_68 ( V_8 -> V_21 , V_29 ) ;
F_45 ( V_3 , V_28 , V_75 , 0 , 0 ) ;
break;
default:
F_45 ( V_3 , V_28 , V_75 , 1 , 0 ) ;
break;
}
F_24 ( V_3 , V_16 , V_58 , V_8 ) ;
}
if ( V_37 == V_71 ) {
-- V_75 ;
continue;
}
V_62 = F_32 ( V_62 , V_37 ) ;
}
if ( V_62 )
F_70 ( V_122 , V_3 , V_104 -> V_36 ,
L_5 , V_62 ) ;
F_66 ( V_58 ) ;
}
static int F_71 ( const struct V_2 * V_3 ,
const struct V_103 * V_104 )
{
struct V_27 * V_28 = F_55 ( V_104 ) ;
struct V_57 * V_58 = F_64 ( V_3 , V_104 -> V_36 ) ;
enum V_116 V_117 ;
int V_123 ;
int V_62 ;
int V_75 ;
V_124:
for ( V_62 = 0 , V_117 = V_67 , V_75 = 0 , V_123 = 0 ;
V_75 < V_28 -> V_38 ; ++ V_75 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_4 * V_29 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
V_7 = & V_28 -> V_39 [ V_75 ] ;
V_16 = V_7 -> V_40 ;
F_10 ( V_16 != NULL ) ;
V_29 = V_16 -> V_64 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_58 , & V_8 ) ;
if ( V_37 == 0 ) {
F_10 ( V_29 -> V_66 >= V_109 ) ;
if ( V_29 -> V_66 < V_112 )
V_37 = F_61 ( V_3 , V_29 ) ;
V_117 = F_65 ( V_117 , V_29 -> V_66 ) ;
F_24 ( V_3 , V_16 , V_58 , V_8 ) ;
}
if ( V_37 == V_111 ) {
V_123 ++ ;
V_37 = 0 ;
}
V_62 = F_32 ( V_62 , V_37 ) ;
if ( V_62 != 0 )
break;
}
if ( V_62 == 0 && V_123 != 0 )
goto V_124;
F_66 ( V_58 ) ;
return V_62 ? : V_117 >= V_112 ? 0 : V_74 ;
}
static int F_72 ( const struct V_2 * V_3 ,
const struct V_103 * V_104 )
{
struct V_27 * V_28 = F_55 ( V_104 ) ;
struct V_57 * V_58 = F_64 ( V_3 , V_104 -> V_36 ) ;
int V_62 ;
int V_75 ;
F_10 ( V_104 -> V_36 -> V_66 == V_120 ) ;
for ( V_62 = 0 , V_75 = 0 ; V_75 < V_28 -> V_38 ; ++ V_75 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_4 * V_29 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
F_10 ( V_104 -> V_36 -> V_66 == V_120 ) ;
V_7 = & V_28 -> V_39 [ V_75 ] ;
V_16 = V_7 -> V_40 ;
if ( V_16 == NULL ) {
V_62 = - V_121 ;
break;
}
V_29 = V_16 -> V_64 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_58 , & V_8 ) ;
if ( V_37 == 0 ) {
F_10 ( V_29 -> V_66 != V_67 ) ;
F_50 ( V_3 , V_28 , V_75 ) ;
if ( V_29 -> V_66 == V_118 ) {
V_37 = F_73 ( V_8 -> V_21 , V_29 , 0 ) ;
if ( V_37 != 0 )
V_37 = F_45 ( V_3 , V_28 ,
V_75 , 1 , V_37 ) ;
} else if ( V_29 -> V_66 == V_125 ) {
V_62 = - V_121 ;
F_45 ( V_3 , V_28 , V_75 , 1 , V_62 ) ;
}
F_24 ( V_3 , V_16 , V_58 , V_8 ) ;
}
V_62 = F_32 ( V_62 , V_37 ) ;
if ( V_62 != 0 )
break;
}
if ( V_28 -> V_70 ) {
V_28 -> V_70 = 0 ;
F_10 ( V_62 != 0 ) ;
V_62 = - V_121 ;
}
F_66 ( V_58 ) ;
return V_62 ;
}
static int F_74 ( const struct V_2 * V_3 ,
struct V_81 * V_126 , int V_127 ,
const struct V_53 * V_61 ,
const struct V_53 * V_54 )
{
struct V_128 * V_129 = V_126 -> V_91 ;
T_1 V_77 ;
T_1 V_78 ;
int V_62 ;
if ( F_37 ( V_126 ) -> V_89 == 1 )
return F_75 ( V_61 , V_54 ) ;
V_77 = F_38 ( & V_126 -> V_130 , V_54 -> V_87 ) ;
V_78 = F_38 ( & V_126 -> V_130 , V_54 -> V_88 + 1 ) - 1 ;
V_62 = 0 ;
if ( V_78 - V_77 <= V_129 -> V_131 ) {
int V_30 ;
V_30 = F_76 ( V_129 , V_77 ) ;
if ( V_30 == V_127 ||
F_29 ( F_37 ( V_126 ) -> V_90 [ V_30 ] == NULL ) ) {
V_30 = F_76 ( V_129 , V_78 ) ;
if ( V_30 == V_127 ||
F_29 ( F_37 ( V_126 ) -> V_90 [ V_30 ] == NULL ) )
V_62 = 1 ;
}
}
if ( V_62 != 0 ) {
struct V_53 * V_132 = & F_77 ( V_3 ) -> V_133 ;
T_1 V_134 ;
T_1 V_135 ;
V_132 -> V_20 = NULL ;
V_132 -> V_93 = V_54 -> V_93 ;
V_132 -> V_94 = V_54 -> V_94 ;
V_62 = F_41 ( V_129 , V_127 , V_77 , V_78 ,
& V_134 , & V_135 ) ;
F_10 ( V_62 ) ;
V_132 -> V_87 = F_44 ( V_61 -> V_20 , V_134 ) ;
V_132 -> V_88 = F_44 ( V_61 -> V_20 , V_135 ) ;
V_62 = F_75 ( V_61 , V_132 ) ;
}
return V_62 ;
}
static int F_78 ( const struct V_2 * V_3 ,
const struct V_103 * V_104 ,
const struct V_53 * V_136 ,
const struct V_11 * V_12 )
{
struct V_27 * V_126 = F_55 ( V_104 ) ;
struct V_81 * V_137 = F_36 ( V_104 -> V_83 ) ;
int V_62 ;
F_10 ( F_4 ( V_136 -> V_20 , V_104 -> V_83 ) ) ;
F_10 ( V_126 -> V_38 > 0 ) ;
if ( V_136 -> V_95 != V_126 -> V_86 . V_95 )
return 0 ;
if ( V_136 -> V_93 == V_99 )
V_62 = F_75 ( & V_126 -> V_86 , V_136 ) ;
else if ( V_126 -> V_38 == 1 ) {
struct V_53 * V_138 = & V_126 -> V_39 [ 0 ] . V_55 ;
V_62 = F_74 ( V_3 ,
F_36 ( V_104 -> V_83 ) ,
V_126 -> V_39 [ 0 ] . V_24 ,
V_138 , V_136 ) ;
} else if ( V_12 -> V_139 != V_140 && V_12 -> V_139 != V_141 &&
! F_79 ( V_12 ) && V_136 -> V_93 != V_98 )
V_62 = 0 ;
else
V_62 = F_75 ( & V_126 -> V_86 , V_136 ) ;
F_80 ( V_142 , V_143 L_6 V_143 L_7 ,
F_81 ( & V_126 -> V_86 ) , F_81 ( & V_126 -> V_39 [ 0 ] . V_55 ) ,
V_126 -> V_39 [ 0 ] . V_24 , V_126 -> V_38 , F_37 ( V_137 ) -> V_89 ,
V_62 ) ;
return V_62 ;
}
void F_30 ( const struct V_2 * V_3 ,
struct V_31 * V_32 , struct V_33 * V_16 )
{
struct V_27 * V_28 = V_32 -> V_45 ;
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
F_10 ( F_11 ( V_5 ) ) ;
F_10 ( F_11 ( V_16 -> V_64 . V_36 ) ) ;
F_82 ( & V_32 -> V_42 ) ;
F_10 ( V_28 -> V_39 [ V_32 -> V_44 ] . V_40 == V_16 ) ;
V_28 -> V_39 [ V_32 -> V_44 ] . V_40 = NULL ;
F_10 ( V_28 -> V_41 > 0 ) ;
V_28 -> V_41 -- ;
F_83 ( & V_5 -> V_46 , L_1 , V_16 -> V_64 . V_36 ) ;
F_53 ( V_3 , V_5 ) ;
F_22 ( V_50 , V_32 ) ;
}
struct V_31 * F_13 ( const struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_33 * V_16 )
{
struct V_31 * V_144 ;
F_10 ( F_11 ( V_16 -> V_64 . V_36 ) ) ;
F_84 (scan, &sub->lss_parents, lll_list) {
if ( V_144 -> V_45 == V_28 )
return V_144 ;
}
return NULL ;
}
static void F_85 ( const struct V_2 * V_3 ,
const struct V_103 * V_104 )
{
struct V_27 * V_28 = F_55 ( V_104 ) ;
struct V_57 * V_58 = F_64 ( V_3 , V_104 -> V_36 ) ;
struct V_31 * V_32 ;
int V_37 ;
int V_75 ;
F_10 ( V_104 -> V_36 -> V_66 == V_67 ) ;
for ( V_75 = 0 ; V_75 < V_28 -> V_38 ; ++ V_75 ) {
struct V_6 * V_7 = & V_28 -> V_39 [ V_75 ] ;
struct V_33 * V_34 = V_7 -> V_40 ;
if ( V_34 == NULL )
continue;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_58 , NULL ) ;
if ( V_37 == V_71 ) {
-- V_75 ;
continue;
}
F_10 ( V_37 == 0 ) ;
F_10 ( V_34 -> V_64 . V_36 -> V_66 < V_67 ) ;
if ( V_7 -> V_47 & V_48 )
F_45 ( V_3 , V_28 , V_75 , 1 , 0 ) ;
V_32 = F_13 ( V_3 , V_28 , V_34 ) ;
F_10 ( V_32 != NULL ) ;
F_30 ( V_3 , V_32 , V_34 ) ;
F_10 ( V_28 -> V_39 [ V_75 ] . V_40 == NULL ) ;
F_24 ( V_3 , V_34 , V_58 , NULL ) ;
}
F_66 ( V_58 ) ;
}
static int F_86 ( const struct V_2 * V_3 , void * V_145 ,
T_3 V_146 , const struct V_103 * V_104 )
{
struct V_27 * V_28 = F_55 ( V_104 ) ;
int V_75 ;
(* V_146)( V_3 , V_145 , L_8 , V_28 -> V_38 ) ;
for ( V_75 = 0 ; V_75 < V_28 -> V_38 ; ++ V_75 ) {
struct V_6 * V_16 ;
V_16 = & V_28 -> V_39 [ V_75 ] ;
(* V_146)( V_3 , V_145 , L_9 , V_75 , V_16 -> V_47 ) ;
if ( V_16 -> V_40 != NULL )
F_87 ( V_3 , V_145 , V_146 ,
V_16 -> V_40 -> V_64 . V_36 ) ;
else
(* V_146)( V_3 , V_145 , L_10 ) ;
}
return 0 ;
}
int F_88 ( const struct V_2 * V_3 , struct V_147 * V_137 ,
struct V_4 * V_106 , const struct V_11 * V_12 )
{
struct V_27 * V_28 ;
int V_62 ;
V_28 = F_20 ( V_105 , V_51 | V_52 ) ;
if ( V_28 != NULL ) {
F_89 ( V_106 , & V_28 -> V_35 , V_137 , & V_148 ) ;
V_62 = F_35 ( V_3 , V_28 , V_12 ) ;
} else
V_62 = - V_56 ;
return V_62 ;
}
static void F_90 ( const struct V_2 * V_3 ,
struct V_103 * V_104 )
{
struct V_27 * V_28 = F_55 ( V_104 ) ;
F_22 ( V_105 , V_28 ) ;
}
static int F_91 ( const struct V_2 * V_3 , void * V_145 ,
T_3 V_146 , const struct V_103 * V_104 )
{
(* V_146)( V_3 , V_145 , L_11 ) ;
return 0 ;
}
int F_92 ( const struct V_2 * V_3 , struct V_147 * V_137 ,
struct V_4 * V_106 , const struct V_11 * V_12 )
{
struct V_27 * V_28 ;
int V_62 = - V_56 ;
V_28 = F_20 ( V_105 , V_51 | V_52 ) ;
if ( V_28 != NULL ) {
F_89 ( V_106 , & V_28 -> V_35 , V_137 , & V_149 ) ;
V_28 -> V_86 = V_106 -> V_19 ;
V_62 = 0 ;
}
return V_62 ;
}
static struct V_57 * F_64 ( const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_57 * V_58 ;
V_58 = & F_77 ( V_3 ) -> V_150 ;
F_10 ( F_27 ( & V_58 -> V_63 ) ) ;
F_93 ( V_3 , V_58 , V_5 , 1 ) ;
return V_58 ;
}

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
F_20 ( V_32 , V_50 , V_51 ) ;
if ( V_32 != NULL ) {
struct V_1 * V_8 ;
struct V_6 * V_7 ;
struct V_52 * V_53 ;
V_5 = V_28 -> V_35 . V_36 ;
V_7 = & V_28 -> V_39 [ V_30 ] ;
V_53 = & V_7 -> V_54 ;
V_8 = F_1 ( V_3 , V_5 , V_7 ) ;
if ( ! F_6 ( V_8 ) ) {
V_29 = F_21 ( V_8 -> V_21 , V_8 -> V_22 ,
V_53 , L_2 , V_5 ) ;
F_7 ( V_8 ) ;
} else {
V_29 = ( void * ) V_8 ;
}
if ( ! F_6 ( V_29 ) )
* V_49 = V_32 ;
else
F_22 ( V_32 , V_50 ) ;
} else
V_29 = F_23 ( - V_55 ) ;
return V_29 ;
}
static void F_24 ( const struct V_2 * V_3 ,
struct V_33 * V_34 ,
struct V_56 * V_57 ,
struct V_1 * V_8 )
{
F_7 ( V_8 ) ;
V_34 -> V_58 = NULL ;
F_25 ( V_3 , V_57 ) ;
}
static int F_26 ( const struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_6 * V_7 ,
struct V_56 * V_57 ,
struct V_1 * * V_59 )
{
struct V_33 * V_29 ;
struct V_4 * V_60 ;
int V_61 = 0 ;
F_10 ( F_27 ( & V_57 -> V_62 ) ) ;
V_29 = V_7 -> V_40 ;
V_60 = V_29 -> V_63 . V_36 ;
V_61 = F_28 ( V_3 , V_60 , V_57 ) ;
if ( V_61 == 0 ) {
struct V_4 * V_5 = V_57 -> V_64 ;
F_10 ( F_11 ( V_60 ) ) ;
V_29 -> V_58 = V_5 ;
if ( F_29 ( ( V_60 -> V_65 == V_66 ) ||
( V_60 -> V_67 & V_68 ) ) ) {
struct V_31 * V_32 ;
F_10 ( ! ( V_7 -> V_47 & V_48 ) ) ;
V_32 = F_13 ( V_3 , V_28 , V_29 ) ;
F_10 ( V_32 != NULL ) ;
F_30 ( V_3 , V_32 , V_29 ) ;
F_24 ( V_3 , V_29 , V_57 , NULL ) ;
V_28 -> V_69 = 1 ;
V_61 = V_70 ;
} else if ( V_59 ) {
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 , V_5 , V_7 ) ;
if ( F_6 ( V_8 ) ) {
F_24 ( V_3 , V_29 ,
V_57 , NULL ) ;
V_61 = F_31 ( V_8 ) ;
} else {
* V_59 = V_8 ;
}
}
}
return V_61 ;
}
static int F_32 ( int V_61 , int V_37 )
{
int V_71 ;
int V_72 ;
F_33 ( V_61 <= 0 || V_61 == V_70 || V_61 == V_73 ,
L_3 , V_61 ) ;
F_33 ( V_37 <= 0 || V_37 == V_70 || V_37 == V_73 ,
L_4 , V_37 ) ;
F_34 ( V_73 < V_70 ) ;
V_71 = V_61 < 0 ? 1 + V_70 : V_61 ;
V_72 = V_37 < 0 ? 1 + V_70 : V_37 ;
if ( V_71 < V_72 )
V_61 = V_37 ;
return V_61 ;
}
static int F_35 ( const struct V_2 * V_3 ,
struct V_27 * V_28 , const struct V_11 * V_12 )
{
int V_61 = 0 ;
int V_74 ;
int V_75 ;
T_1 V_76 ;
T_1 V_77 ;
T_1 V_78 ;
T_1 V_79 ;
struct V_80 * V_81 = F_36 ( V_28 -> V_35 . V_82 ) ;
struct V_83 * V_84 = F_37 ( V_81 ) ;
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
V_28 -> V_85 = V_5 -> V_19 ;
V_78 = F_38 ( F_39 ( V_81 ) , V_5 -> V_19 . V_86 ) ;
V_79 = F_38 ( F_39 ( V_81 ) , V_5 -> V_19 . V_87 + 1 ) - 1 ;
for ( V_74 = 0 , V_75 = 0 ; V_74 < V_84 -> V_88 ; V_74 ++ ) {
if ( F_40 ( V_84 -> V_89 [ V_74 ] != NULL ) &&
F_41 ( V_81 -> V_90 , V_74 ,
V_78 , V_79 , & V_76 , & V_77 ) )
V_75 ++ ;
}
F_10 ( V_75 > 0 ) ;
F_42 ( V_28 -> V_39 , V_75 * sizeof( V_28 -> V_39 [ 0 ] ) ) ;
if ( V_28 -> V_39 == NULL )
return - V_55 ;
V_28 -> V_38 = V_75 ;
for ( V_74 = 0 , V_75 = 0 ; V_74 < V_84 -> V_88 ; ++ V_74 ) {
if ( F_40 ( V_84 -> V_89 [ V_74 ] != NULL ) &&
F_41 ( V_81 -> V_90 , V_74 ,
V_78 , V_79 , & V_76 , & V_77 ) ) {
struct V_52 * V_53 ;
V_53 = & V_28 -> V_39 [ V_75 ] . V_91 ;
F_10 ( V_53 -> V_20 == NULL ) ;
V_53 -> V_20 = F_43 ( V_84 -> V_89 [ V_74 ] ) ;
V_53 -> V_86 = F_44 ( V_53 -> V_20 , V_76 ) ;
V_53 -> V_87 = F_44 ( V_53 -> V_20 , V_77 ) ;
V_53 -> V_92 = V_5 -> V_19 . V_92 ;
V_53 -> V_93 = V_5 -> V_19 . V_93 ;
V_53 -> V_94 = V_5 -> V_19 . V_94 ;
V_28 -> V_39 [ V_75 ] . V_54 = * V_53 ;
V_28 -> V_39 [ V_75 ] . V_24 = V_74 ;
V_75 ++ ;
}
}
F_10 ( V_75 == V_28 -> V_38 ) ;
return V_61 ;
}
static int F_45 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
int V_74 , int V_95 , int V_37 )
{
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
F_10 ( F_11 ( V_5 ) ) ;
if ( V_28 -> V_39 [ V_74 ] . V_47 & V_48 ) {
struct V_4 * V_29 ;
int V_96 ;
F_10 ( V_28 -> V_39 [ V_74 ] . V_40 != NULL ) ;
V_29 = V_28 -> V_39 [ V_74 ] . V_40 -> V_63 . V_36 ;
F_10 ( F_11 ( V_29 ) ) ;
V_28 -> V_39 [ V_74 ] . V_47 &= ~ V_48 ;
if ( V_95 )
F_46 ( V_3 , V_29 ) ;
V_96 = ( V_29 -> V_19 . V_92 == V_97 ||
V_29 -> V_19 . V_92 == V_98 ||
( V_29 -> V_67 & ( V_99 | V_100 ) ) ) &&
V_29 -> V_101 == 1 ;
if ( V_96 )
F_47 ( V_3 , V_5 ) ;
F_48 ( V_3 , V_29 , L_2 , V_5 ) ;
if ( V_96 ) {
F_49 ( V_3 , V_5 ) ;
V_37 = F_32 ( V_37 , V_70 ) ;
}
}
return V_37 ;
}
static void F_50 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
int V_74 )
{
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
F_10 ( F_11 ( V_5 ) ) ;
if ( ! ( V_28 -> V_39 [ V_74 ] . V_47 & V_48 ) ) {
struct V_4 * V_29 ;
F_10 ( V_28 -> V_39 [ V_74 ] . V_40 != NULL ) ;
V_29 = V_28 -> V_39 [ V_74 ] . V_40 -> V_63 . V_36 ;
F_10 ( F_11 ( V_29 ) ) ;
F_10 ( V_29 -> V_65 != V_66 ) ;
V_28 -> V_39 [ V_74 ] . V_47 |= V_48 ;
F_51 ( V_29 ) ;
F_52 ( V_3 , V_29 , L_2 , V_5 ) ;
F_17 ( V_3 , V_29 ) ;
F_53 ( V_3 , V_29 ) ;
}
}
static void F_54 ( const struct V_2 * V_3 ,
struct V_102 * V_103 )
{
struct V_27 * V_28 ;
int V_74 ;
V_28 = F_55 ( V_103 ) ;
F_10 ( V_28 -> V_41 == 0 ) ;
if ( V_28 -> V_39 != NULL ) {
for ( V_74 = 0 ; V_74 < V_28 -> V_38 ; ++ V_74 )
F_10 ( V_28 -> V_39 [ V_74 ] . V_40 == NULL ) ;
F_56 ( V_28 -> V_39 ,
V_28 -> V_38 * sizeof( V_28 -> V_39 [ 0 ] ) ) ;
}
F_22 ( V_28 , V_104 ) ;
}
static int F_57 ( const struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_4 * V_29 )
{
struct V_4 * V_105 = V_28 -> V_35 . V_36 ;
int V_61 ;
F_10 ( F_11 ( V_105 ) ) ;
F_47 ( V_3 , V_105 ) ;
V_61 = F_58 ( V_3 , V_29 , 0 ) ;
F_49 ( V_3 , V_105 ) ;
return V_61 ? : V_70 ;
}
static int F_59 ( const struct V_2 * V_3 , struct V_27 * V_28 ,
struct V_4 * V_29 ,
struct V_11 * V_12 , T_2 V_106 , int V_107 )
{
int V_61 ;
V_61 = F_60 ( V_3 , V_29 , V_12 , V_106 ) ;
if ( ( V_29 -> V_65 == V_108 ) && ! ( V_106 & V_109 ) ) {
V_61 = F_61 ( V_3 , V_29 ) ;
if ( V_61 == V_110 )
V_61 = V_73 ;
}
if ( ( V_61 == V_73 ) && ( V_29 -> V_65 <= V_111 ) &&
( V_106 & V_112 ) && ( ! V_107 || ( V_106 & V_109 ) ) )
V_61 = 0 ;
return V_61 ;
}
static int F_62 ( const struct V_2 * V_3 , struct V_4 * V_5 ,
struct V_11 * V_12 , struct V_27 * V_28 , int V_30 )
{
struct V_31 * V_32 = NULL ;
struct V_4 * V_29 ;
int V_61 ;
F_10 ( V_5 -> V_113 == 1 ) ;
F_47 ( V_3 , V_5 ) ;
V_29 = F_19 ( V_3 , V_12 , V_28 , V_30 , & V_32 ) ;
if ( ! F_6 ( V_29 ) )
F_49 ( V_3 , V_29 ) ;
F_49 ( V_3 , V_5 ) ;
if ( ! F_6 ( V_29 ) ) {
F_51 ( V_29 ) ;
if ( V_5 -> V_65 == V_114 &&
V_28 -> V_39 [ V_30 ] . V_40 == NULL ) {
F_9 ( V_3 , V_28 , V_29 , V_30 , V_32 ) ;
} else {
F_22 ( V_32 , V_50 ) ;
F_47 ( V_3 , V_5 ) ;
F_48 ( V_3 , V_29 , L_2 , V_5 ) ;
F_49 ( V_3 , V_5 ) ;
}
F_47 ( V_3 , V_29 ) ;
F_53 ( V_3 , V_29 ) ;
V_61 = V_70 ;
} else
V_61 = F_31 ( V_29 ) ;
return V_61 ;
}
static int F_63 ( const struct V_2 * V_3 ,
const struct V_102 * V_103 ,
struct V_11 * V_12 , T_2 V_106 )
{
struct V_4 * V_105 = V_103 -> V_36 ;
struct V_27 * V_28 = F_55 ( V_103 ) ;
struct V_56 * V_57 = F_64 ( V_3 , V_105 ) ;
int V_74 ;
int V_61 ;
enum V_115 V_116 ;
for ( V_61 = 0 , V_116 = V_66 , V_74 = 0 ; V_74 < V_28 -> V_38 ; ++ V_74 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_6 * V_7 ;
struct V_4 * V_29 ;
struct V_1 * V_8 ;
if ( V_105 -> V_65 != V_114 ) {
F_10 ( V_74 > 0 && V_61 != 0 ) ;
break;
}
V_7 = & V_28 -> V_39 [ V_74 ] ;
V_16 = V_7 -> V_40 ;
if ( V_16 == NULL ) {
V_61 = F_62 ( V_3 , V_105 , V_12 , V_28 , V_74 ) ;
break;
}
V_29 = V_16 -> V_63 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_57 , & V_8 ) ;
if ( V_37 == 0 ) {
F_50 ( V_3 , V_28 , V_74 ) ;
V_37 = F_59 ( V_8 -> V_21 , V_28 , V_29 ,
V_8 -> V_22 , V_106 ,
V_74 == V_28 -> V_38 - 1 ) ;
V_116 = F_65 ( V_116 , V_29 -> V_65 ) ;
if ( V_37 == V_73 ) {
switch ( V_29 -> V_65 ) {
case V_114 :
F_49 ( V_3 , V_29 ) ;
F_24 ( V_3 , V_16 , V_57 ,
V_8 ) ;
V_37 = F_57 ( V_3 , V_28 ,
V_29 ) ;
break;
case V_117 :
F_15 ( V_29 ) ;
F_49 ( V_3 , V_29 ) ;
F_24 ( V_3 , V_16 , V_57 ,
V_8 ) ;
V_37 = F_45 ( V_3 , V_28 , V_74 ,
1 , V_37 ) ;
F_47 ( V_3 , V_29 ) ;
F_53 ( V_3 , V_29 ) ;
break;
default:
F_24 ( V_3 , V_16 , V_57 ,
V_8 ) ;
break;
}
} else {
F_10 ( V_29 -> V_118 == NULL ) ;
F_24 ( V_3 , V_16 , V_57 , V_8 ) ;
}
}
V_61 = F_32 ( V_61 , V_37 ) ;
if ( V_61 != 0 )
break;
}
F_66 ( V_57 ) ;
return V_61 ? : V_116 >= V_108 ? 0 : V_73 ;
}
static int F_67 ( const struct V_2 * V_3 ,
const struct V_102 * V_103 )
{
struct V_27 * V_28 = F_55 ( V_103 ) ;
struct V_56 * V_57 = F_64 ( V_3 , V_103 -> V_36 ) ;
int V_74 ;
int V_61 ;
for ( V_61 = 0 , V_74 = 0 ; V_74 < V_28 -> V_38 ; ++ V_74 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_4 * V_29 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
F_10 ( V_103 -> V_36 -> V_65 == V_119 ) ;
V_7 = & V_28 -> V_39 [ V_74 ] ;
V_16 = V_7 -> V_40 ;
if ( V_16 == NULL )
continue;
V_29 = V_16 -> V_63 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_57 , & V_8 ) ;
if ( V_37 == 0 ) {
if ( V_7 -> V_47 & V_48 ) {
F_10 ( V_29 -> V_65 == V_111 ||
V_29 -> V_65 == V_108 ) ;
V_37 = F_68 ( V_8 -> V_21 , V_29 ) ;
V_37 = F_45 ( V_3 , V_28 , V_74 , 0 , V_37 ) ;
}
F_24 ( V_3 , V_16 , V_57 , V_8 ) ;
}
V_61 = F_32 ( V_61 , V_37 ) ;
}
if ( V_61 == 0 && V_28 -> V_69 ) {
V_28 -> V_69 = 0 ;
V_61 = - V_120 ;
}
F_66 ( V_57 ) ;
return V_61 ;
}
static void F_69 ( const struct V_2 * V_3 ,
const struct V_102 * V_103 )
{
struct V_27 * V_28 = F_55 ( V_103 ) ;
struct V_56 * V_57 = F_64 ( V_3 , V_103 -> V_36 ) ;
int V_74 ;
int V_61 ;
for ( V_61 = 0 , V_74 = 0 ; V_74 < V_28 -> V_38 ; ++ V_74 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_4 * V_29 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
V_7 = & V_28 -> V_39 [ V_74 ] ;
V_16 = V_7 -> V_40 ;
if ( V_16 == NULL )
continue;
V_29 = V_16 -> V_63 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_57 , & V_8 ) ;
if ( V_37 == 0 ) {
if ( ! ( V_7 -> V_47 & V_48 ) ) {
F_24 ( V_3 , V_16 , V_57 , V_8 ) ;
continue;
}
switch ( V_29 -> V_65 ) {
case V_111 :
V_37 = F_68 ( V_8 -> V_21 , V_29 ) ;
F_45 ( V_3 , V_28 , V_74 , 0 , 0 ) ;
break;
default:
F_45 ( V_3 , V_28 , V_74 , 1 , 0 ) ;
break;
}
F_24 ( V_3 , V_16 , V_57 , V_8 ) ;
}
if ( V_37 == V_70 ) {
-- V_74 ;
continue;
}
V_61 = F_32 ( V_61 , V_37 ) ;
}
if ( V_61 )
F_70 ( V_121 , V_3 , V_103 -> V_36 ,
L_5 , V_61 ) ;
F_66 ( V_57 ) ;
}
static int F_71 ( const struct V_2 * V_3 ,
const struct V_102 * V_103 )
{
struct V_27 * V_28 = F_55 ( V_103 ) ;
struct V_56 * V_57 = F_64 ( V_3 , V_103 -> V_36 ) ;
enum V_115 V_116 ;
int V_122 ;
int V_61 ;
int V_74 ;
V_123:
for ( V_61 = 0 , V_116 = V_66 , V_74 = 0 , V_122 = 0 ;
V_74 < V_28 -> V_38 ; ++ V_74 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_4 * V_29 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
V_7 = & V_28 -> V_39 [ V_74 ] ;
V_16 = V_7 -> V_40 ;
F_10 ( V_16 != NULL ) ;
V_29 = V_16 -> V_63 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_57 , & V_8 ) ;
if ( V_37 == 0 ) {
F_10 ( V_29 -> V_65 >= V_108 ) ;
if ( V_29 -> V_65 < V_111 )
V_37 = F_61 ( V_3 , V_29 ) ;
V_116 = F_65 ( V_116 , V_29 -> V_65 ) ;
F_24 ( V_3 , V_16 , V_57 , V_8 ) ;
}
if ( V_37 == V_110 ) {
V_122 ++ ;
V_37 = 0 ;
}
V_61 = F_32 ( V_61 , V_37 ) ;
if ( V_61 != 0 )
break;
}
if ( V_61 == 0 && V_122 != 0 )
goto V_123;
F_66 ( V_57 ) ;
return V_61 ? : V_116 >= V_111 ? 0 : V_73 ;
}
static int F_72 ( const struct V_2 * V_3 ,
const struct V_102 * V_103 )
{
struct V_27 * V_28 = F_55 ( V_103 ) ;
struct V_56 * V_57 = F_64 ( V_3 , V_103 -> V_36 ) ;
int V_61 ;
int V_74 ;
F_10 ( V_103 -> V_36 -> V_65 == V_119 ) ;
for ( V_61 = 0 , V_74 = 0 ; V_74 < V_28 -> V_38 ; ++ V_74 ) {
int V_37 ;
struct V_33 * V_16 ;
struct V_4 * V_29 ;
struct V_6 * V_7 ;
struct V_1 * V_8 ;
F_10 ( V_103 -> V_36 -> V_65 == V_119 ) ;
V_7 = & V_28 -> V_39 [ V_74 ] ;
V_16 = V_7 -> V_40 ;
if ( V_16 == NULL ) {
V_61 = - V_120 ;
break;
}
V_29 = V_16 -> V_63 . V_36 ;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_57 , & V_8 ) ;
if ( V_37 == 0 ) {
F_10 ( V_29 -> V_65 != V_66 ) ;
F_50 ( V_3 , V_28 , V_74 ) ;
if ( V_29 -> V_65 == V_117 ) {
V_37 = F_73 ( V_8 -> V_21 , V_29 , 0 ) ;
if ( V_37 != 0 )
V_37 = F_45 ( V_3 , V_28 ,
V_74 , 1 , V_37 ) ;
} else if ( V_29 -> V_65 == V_124 ) {
V_61 = - V_120 ;
F_45 ( V_3 , V_28 , V_74 , 1 , V_61 ) ;
}
F_24 ( V_3 , V_16 , V_57 , V_8 ) ;
}
V_61 = F_32 ( V_61 , V_37 ) ;
if ( V_61 != 0 )
break;
}
if ( V_28 -> V_69 ) {
V_28 -> V_69 = 0 ;
F_10 ( V_61 != 0 ) ;
V_61 = - V_120 ;
}
F_66 ( V_57 ) ;
return V_61 ;
}
static int F_74 ( const struct V_2 * V_3 ,
struct V_80 * V_125 , int V_126 ,
const struct V_52 * V_60 ,
const struct V_52 * V_53 )
{
struct V_127 * V_128 = V_125 -> V_90 ;
T_1 V_76 ;
T_1 V_77 ;
int V_61 ;
if ( F_37 ( V_125 ) -> V_88 == 1 )
return F_75 ( V_60 , V_53 ) ;
V_76 = F_38 ( & V_125 -> V_129 , V_53 -> V_86 ) ;
V_77 = F_38 ( & V_125 -> V_129 , V_53 -> V_87 + 1 ) - 1 ;
V_61 = 0 ;
if ( V_77 - V_76 <= V_128 -> V_130 ) {
int V_30 ;
V_30 = F_76 ( V_128 , V_76 ) ;
if ( V_30 == V_126 ||
F_29 ( F_37 ( V_125 ) -> V_89 [ V_30 ] == NULL ) ) {
V_30 = F_76 ( V_128 , V_77 ) ;
if ( V_30 == V_126 ||
F_29 ( F_37 ( V_125 ) -> V_89 [ V_30 ] == NULL ) )
V_61 = 1 ;
}
}
if ( V_61 != 0 ) {
struct V_52 * V_131 = & F_77 ( V_3 ) -> V_132 ;
T_1 V_133 ;
T_1 V_134 ;
V_131 -> V_20 = NULL ;
V_131 -> V_92 = V_53 -> V_92 ;
V_131 -> V_93 = V_53 -> V_93 ;
V_61 = F_41 ( V_128 , V_126 , V_76 , V_77 ,
& V_133 , & V_134 ) ;
F_10 ( V_61 ) ;
V_131 -> V_86 = F_44 ( V_60 -> V_20 , V_133 ) ;
V_131 -> V_87 = F_44 ( V_60 -> V_20 , V_134 ) ;
V_61 = F_75 ( V_60 , V_131 ) ;
}
return V_61 ;
}
static int F_78 ( const struct V_2 * V_3 ,
const struct V_102 * V_103 ,
const struct V_52 * V_135 ,
const struct V_11 * V_12 )
{
struct V_27 * V_125 = F_55 ( V_103 ) ;
struct V_80 * V_136 = F_36 ( V_103 -> V_82 ) ;
int V_61 ;
F_10 ( F_4 ( V_135 -> V_20 , V_103 -> V_82 ) ) ;
F_10 ( V_125 -> V_38 > 0 ) ;
if ( V_135 -> V_94 != V_125 -> V_85 . V_94 )
return 0 ;
if ( V_135 -> V_92 == V_98 )
V_61 = F_75 ( & V_125 -> V_85 , V_135 ) ;
else if ( V_125 -> V_38 == 1 ) {
struct V_52 * V_137 = & V_125 -> V_39 [ 0 ] . V_54 ;
V_61 = F_74 ( V_3 ,
F_36 ( V_103 -> V_82 ) ,
V_125 -> V_39 [ 0 ] . V_24 ,
V_137 , V_135 ) ;
} else if ( V_12 -> V_138 != V_139 && V_12 -> V_138 != V_140 &&
! F_79 ( V_12 ) && V_135 -> V_92 != V_97 )
V_61 = 0 ;
else
V_61 = F_75 ( & V_125 -> V_85 , V_135 ) ;
F_80 ( V_141 , V_142 L_6 V_142 L_7 ,
F_81 ( & V_125 -> V_85 ) , F_81 ( & V_125 -> V_39 [ 0 ] . V_54 ) ,
V_125 -> V_39 [ 0 ] . V_24 , V_125 -> V_38 , F_37 ( V_136 ) -> V_88 ,
V_61 ) ;
return V_61 ;
}
void F_30 ( const struct V_2 * V_3 ,
struct V_31 * V_32 , struct V_33 * V_16 )
{
struct V_27 * V_28 = V_32 -> V_45 ;
struct V_4 * V_5 = V_28 -> V_35 . V_36 ;
F_10 ( F_11 ( V_5 ) ) ;
F_10 ( F_11 ( V_16 -> V_63 . V_36 ) ) ;
F_82 ( & V_32 -> V_42 ) ;
F_10 ( V_28 -> V_39 [ V_32 -> V_44 ] . V_40 == V_16 ) ;
V_28 -> V_39 [ V_32 -> V_44 ] . V_40 = NULL ;
F_10 ( V_28 -> V_41 > 0 ) ;
V_28 -> V_41 -- ;
F_83 ( & V_5 -> V_46 , L_1 , V_16 -> V_63 . V_36 ) ;
F_53 ( V_3 , V_5 ) ;
F_22 ( V_32 , V_50 ) ;
}
struct V_31 * F_13 ( const struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_33 * V_16 )
{
struct V_31 * V_143 ;
F_10 ( F_11 ( V_16 -> V_63 . V_36 ) ) ;
F_84 (scan, &sub->lss_parents, lll_list) {
if ( V_143 -> V_45 == V_28 )
return V_143 ;
}
return NULL ;
}
static void F_85 ( const struct V_2 * V_3 ,
const struct V_102 * V_103 )
{
struct V_27 * V_28 = F_55 ( V_103 ) ;
struct V_56 * V_57 = F_64 ( V_3 , V_103 -> V_36 ) ;
struct V_31 * V_32 ;
int V_37 ;
int V_74 ;
F_10 ( V_103 -> V_36 -> V_65 == V_66 ) ;
for ( V_74 = 0 ; V_74 < V_28 -> V_38 ; ++ V_74 ) {
struct V_6 * V_7 = & V_28 -> V_39 [ V_74 ] ;
struct V_33 * V_34 = V_7 -> V_40 ;
if ( V_34 == NULL )
continue;
V_37 = F_26 ( V_3 , V_28 , V_7 , V_57 , NULL ) ;
if ( V_37 == V_70 ) {
-- V_74 ;
continue;
}
F_10 ( V_37 == 0 ) ;
F_10 ( V_34 -> V_63 . V_36 -> V_65 < V_66 ) ;
if ( V_7 -> V_47 & V_48 )
F_45 ( V_3 , V_28 , V_74 , 1 , 0 ) ;
V_32 = F_13 ( V_3 , V_28 , V_34 ) ;
F_10 ( V_32 != NULL ) ;
F_30 ( V_3 , V_32 , V_34 ) ;
F_10 ( V_28 -> V_39 [ V_74 ] . V_40 == NULL ) ;
F_24 ( V_3 , V_34 , V_57 , NULL ) ;
}
F_66 ( V_57 ) ;
}
static int F_86 ( const struct V_2 * V_3 , void * V_144 ,
T_3 V_145 , const struct V_102 * V_103 )
{
struct V_27 * V_28 = F_55 ( V_103 ) ;
int V_74 ;
(* V_145)( V_3 , V_144 , L_8 , V_28 -> V_38 ) ;
for ( V_74 = 0 ; V_74 < V_28 -> V_38 ; ++ V_74 ) {
struct V_6 * V_16 ;
V_16 = & V_28 -> V_39 [ V_74 ] ;
(* V_145)( V_3 , V_144 , L_9 , V_74 , V_16 -> V_47 ) ;
if ( V_16 -> V_40 != NULL )
F_87 ( V_3 , V_144 , V_145 ,
V_16 -> V_40 -> V_63 . V_36 ) ;
else
(* V_145)( V_3 , V_144 , L_10 ) ;
}
return 0 ;
}
int F_88 ( const struct V_2 * V_3 , struct V_146 * V_136 ,
struct V_4 * V_105 , const struct V_11 * V_12 )
{
struct V_27 * V_28 ;
int V_61 ;
F_20 ( V_28 , V_104 , V_51 ) ;
if ( V_28 != NULL ) {
F_89 ( V_105 , & V_28 -> V_35 , V_136 , & V_147 ) ;
V_61 = F_35 ( V_3 , V_28 , V_12 ) ;
} else
V_61 = - V_55 ;
return V_61 ;
}
static void F_90 ( const struct V_2 * V_3 ,
struct V_102 * V_103 )
{
struct V_27 * V_28 = F_55 ( V_103 ) ;
F_22 ( V_28 , V_104 ) ;
}
static int F_91 ( const struct V_2 * V_3 , void * V_144 ,
T_3 V_145 , const struct V_102 * V_103 )
{
(* V_145)( V_3 , V_144 , L_11 ) ;
return 0 ;
}
int F_92 ( const struct V_2 * V_3 , struct V_146 * V_136 ,
struct V_4 * V_105 , const struct V_11 * V_12 )
{
struct V_27 * V_28 ;
int V_61 = - V_55 ;
F_20 ( V_28 , V_104 , V_51 ) ;
if ( V_28 != NULL ) {
F_89 ( V_105 , & V_28 -> V_35 , V_136 , & V_148 ) ;
V_28 -> V_85 = V_105 -> V_19 ;
V_61 = 0 ;
}
return V_61 ;
}
static struct V_56 * F_64 ( const struct V_2 * V_3 ,
struct V_4 * V_5 )
{
struct V_56 * V_57 ;
V_57 = & F_77 ( V_3 ) -> V_149 ;
F_10 ( F_27 ( & V_57 -> V_62 ) ) ;
F_93 ( V_3 , V_57 , V_5 , 1 ) ;
return V_57 ;
}

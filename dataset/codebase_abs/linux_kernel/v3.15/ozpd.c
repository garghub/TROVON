static int F_1 ( void )
{
return 0 ;
}
static void F_2 ( void )
{
}
static int F_3 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static void F_4 ( struct V_1 * V_2 , int V_4 )
{
}
static void F_5 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
}
void F_6 ( struct V_1 * V_2 , unsigned V_7 )
{
V_2 -> V_7 = V_7 ;
switch ( V_7 ) {
case V_8 :
F_7 ( V_2 , V_9 , L_1 ) ;
break;
case V_10 :
F_7 ( V_2 , V_9 , L_2 ) ;
break;
case V_11 :
F_7 ( V_2 , V_9 , L_3 ) ;
break;
case V_12 :
F_7 ( V_2 , V_9 , L_4 ) ;
break;
}
}
void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_13 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( F_11 ( & V_2 -> V_13 ) )
F_12 ( V_2 ) ;
}
struct V_1 * F_13 ( const T_1 * V_14 )
{
struct V_1 * V_2 = F_14 ( sizeof( struct V_1 ) , V_15 ) ;
if ( V_2 ) {
int V_16 ;
F_15 ( & V_2 -> V_13 , 2 ) ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
F_16 ( & V_2 -> V_18 [ V_16 ] ) ;
V_2 -> V_19 = 0xffffffff ;
F_6 ( V_2 , V_8 ) ;
V_2 -> V_20 = V_21 ;
F_17 ( V_2 -> V_14 , V_14 ) ;
if ( 0 != F_18 ( & V_2 -> V_22 ) ) {
F_19 ( V_2 ) ;
V_2 = NULL ;
}
F_16 ( & V_2 -> V_23 ) ;
F_20 ( & V_2 -> V_24 ) ;
F_20 ( & V_2 -> V_25 ) ;
V_2 -> V_26 = & V_2 -> V_24 ;
F_16 ( & V_2 -> V_27 ) ;
F_20 ( & V_2 -> V_28 ) ;
F_21 ( & V_2 -> V_29 , V_30 ,
( unsigned long ) V_2 ) ;
F_21 ( & V_2 -> V_31 , V_32 ,
( unsigned long ) V_2 ) ;
F_22 ( & V_2 -> V_33 , V_34 , V_35 ) ;
F_22 ( & V_2 -> V_36 , V_34 , V_35 ) ;
V_2 -> V_33 . V_37 = V_38 ;
V_2 -> V_36 . V_37 = V_39 ;
}
return V_2 ;
}
static void F_23 ( struct V_40 * V_41 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_1 * V_2 ;
F_7 ( V_2 , V_9 , L_5 ) ;
V_2 = F_24 ( V_41 , struct V_1 , V_50 ) ;
F_25 ( & V_2 -> V_29 ) ;
F_25 ( & V_2 -> V_31 ) ;
V_43 = V_2 -> V_28 . V_51 ;
while ( V_43 != & V_2 -> V_28 ) {
V_47 = F_24 ( V_43 , struct V_46 , V_52 ) ;
V_43 = V_43 -> V_51 ;
F_26 ( V_47 ) ;
}
V_43 = V_2 -> V_24 . V_51 ;
while ( V_43 != & V_2 -> V_24 ) {
V_45 = F_24 ( V_43 , struct V_44 , V_52 ) ;
V_43 = V_43 -> V_51 ;
if ( V_45 -> V_53 != NULL )
F_27 ( V_45 -> V_53 ) ;
F_28 ( V_2 , V_45 ) ;
}
F_29 ( & V_2 -> V_22 ) ;
V_43 = V_2 -> V_25 . V_51 ;
while ( V_43 != & V_2 -> V_25 ) {
V_49 = F_24 ( V_43 , struct V_48 , V_52 ) ;
V_43 = V_43 -> V_51 ;
F_19 ( V_49 ) ;
}
while ( V_2 -> V_54 ) {
V_43 = V_2 -> V_54 ;
V_2 -> V_54 = V_43 -> V_51 ;
F_19 ( F_24 ( V_43 , struct V_44 , V_52 ) ) ;
}
if ( V_2 -> V_55 )
F_30 ( V_2 -> V_55 ) ;
F_19 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( F_31 ( & V_2 -> V_36 ) )
F_32 ( & V_2 -> V_36 ) ;
if ( F_31 ( & V_2 -> V_33 ) )
F_32 ( & V_2 -> V_33 ) ;
F_33 ( & V_2 -> V_50 , F_23 ) ;
if ( ! F_34 ( & V_2 -> V_50 ) )
F_7 ( V_2 , V_9 , L_6 ) ;
}
int F_35 ( struct V_1 * V_2 , T_2 V_56 , int V_3 )
{
const struct V_57 * V_58 ;
int V_59 = 0 ;
F_7 ( V_2 , V_9 , L_7 , V_60 , V_56 , V_3 ) ;
for ( V_58 = V_61 ; V_58 < & V_61 [ V_17 ] ; V_58 ++ ) {
if ( V_56 & ( 1 << V_58 -> V_62 ) ) {
if ( V_58 -> V_63 ( V_2 , V_3 ) ) {
V_59 = - 1 ;
F_7 ( V_2 , V_9 ,
L_8 ,
V_58 -> V_62 ) ;
break;
}
F_36 ( & V_64 ) ;
V_2 -> V_65 |= ( 1 << V_58 -> V_62 ) ;
if ( V_3 )
V_2 -> V_66 &= ~ ( 1 << V_58 -> V_62 ) ;
F_37 ( & V_64 ) ;
}
}
return V_59 ;
}
void F_38 ( struct V_1 * V_2 , T_2 V_56 , int V_4 )
{
const struct V_57 * V_58 ;
F_7 ( V_2 , V_9 , L_9 , V_60 , V_56 , V_4 ) ;
for ( V_58 = V_61 ; V_58 < & V_61 [ V_17 ] ; V_58 ++ ) {
if ( V_56 & ( 1 << V_58 -> V_62 ) ) {
F_36 ( & V_64 ) ;
if ( V_4 ) {
V_2 -> V_66 |= ( 1 << V_58 -> V_62 ) ;
} else {
V_2 -> V_65 &= ~ ( 1 << V_58 -> V_62 ) ;
V_2 -> V_66 &= ~ ( 1 << V_58 -> V_62 ) ;
}
F_37 ( & V_64 ) ;
V_58 -> V_67 ( V_2 , V_4 ) ;
}
}
}
void F_39 ( struct V_1 * V_2 , T_2 V_56 )
{
const struct V_57 * V_58 ;
int V_68 = 0 ;
for ( V_58 = V_61 ; V_58 < & V_61 [ V_17 ] ; V_58 ++ ) {
if ( V_58 -> V_33 && ( V_56 & ( 1 << V_58 -> V_62 ) ) ) {
if ( V_58 -> V_33 ( V_2 ) )
V_68 = 1 ;
}
}
if ( ( ! V_68 ) && ( F_31 ( & V_2 -> V_33 ) ) )
F_32 ( & V_2 -> V_33 ) ;
if ( V_2 -> V_69 & V_70 ) {
int V_71 = 8 ;
while ( V_71 -- && ( F_40 ( V_2 ) >= 0 ) )
;
}
}
void F_41 ( struct V_1 * V_2 )
{
T_2 V_72 ;
F_42 ( V_9 , L_10 , V_2 -> V_7 ) ;
F_43 ( V_2 ) ;
F_36 ( & V_64 ) ;
V_72 = V_2 -> V_65 ;
V_2 -> V_65 = 0 ;
V_2 -> V_66 = 0 ;
F_37 ( & V_64 ) ;
F_38 ( V_2 , V_72 , 0 ) ;
F_36 ( & V_64 ) ;
F_6 ( V_2 , V_11 ) ;
F_44 ( & V_2 -> V_52 ) ;
F_37 ( & V_64 ) ;
F_42 ( V_9 , L_11 , F_45 ( & V_2 -> V_13 ) ) ;
F_10 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_73 = 0 ;
T_2 V_72 ;
F_36 ( & V_64 ) ;
if ( V_2 -> V_7 & ( V_12 | V_11 ) ) {
F_37 ( & V_64 ) ;
return 0 ;
}
if ( V_2 -> V_74 && V_2 -> V_75 )
F_6 ( V_2 , V_12 ) ;
else
V_73 = 1 ;
V_72 = V_2 -> V_65 ;
F_37 ( & V_64 ) ;
if ( V_73 ) {
F_41 ( V_2 ) ;
} else {
F_38 ( V_2 , V_72 , 1 ) ;
F_47 ( V_2 , V_76 , V_2 -> V_74 ) ;
}
return V_73 ;
}
static struct V_44 * F_48 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = NULL ;
F_36 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_54 ) {
V_45 = F_24 ( V_2 -> V_54 , struct V_44 , V_52 ) ;
V_2 -> V_54 = V_2 -> V_54 -> V_51 ;
V_2 -> V_77 -- ;
}
F_37 ( & V_2 -> V_23 ) ;
if ( V_45 == NULL )
V_45 = F_49 ( sizeof( struct V_44 ) , V_15 ) ;
if ( V_45 ) {
V_45 -> V_78 = sizeof( struct V_79 ) ;
F_20 ( & V_45 -> V_52 ) ;
F_20 ( & V_45 -> V_80 ) ;
}
return V_45 ;
}
static void F_50 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
V_2 -> V_81 -- ;
F_51 ( & V_45 -> V_52 ) ;
if ( V_2 -> V_77 < V_82 ) {
V_45 -> V_52 . V_51 = V_2 -> V_54 ;
V_2 -> V_54 = & V_45 -> V_52 ;
V_2 -> V_77 ++ ;
} else {
F_19 ( V_45 ) ;
}
F_42 ( V_83 , L_12 ,
V_2 -> V_81 ) ;
}
static void F_52 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
F_36 ( & V_2 -> V_23 ) ;
if ( V_2 -> V_77 < V_82 ) {
V_45 -> V_52 . V_51 = V_2 -> V_54 ;
V_2 -> V_54 = & V_45 -> V_52 ;
V_2 -> V_77 ++ ;
V_45 = NULL ;
}
F_37 ( & V_2 -> V_23 ) ;
F_19 ( V_45 ) ;
}
static void F_53 ( struct V_84 * V_53 )
{
struct V_79 * V_79 = (struct V_79 * ) F_54 ( V_53 ) ;
V_79 -> V_85 |= V_86 ;
}
static void F_55 ( struct V_1 * V_2 , struct V_84 * V_53 )
{
struct V_79 * V_79 = (struct V_79 * ) F_54 ( V_53 ) ;
V_79 -> V_87 = V_2 -> V_88 & V_89 ;
}
int F_56 ( struct V_1 * V_2 , int V_90 )
{
struct V_44 * V_45 ;
if ( ( V_2 -> V_69 & V_91 ) != V_92 )
return - 1 ;
if ( V_2 -> V_93 >= V_94 )
return - 1 ;
if ( ! V_90 && ! F_57 ( & V_2 -> V_22 ) )
return - 1 ;
V_45 = F_48 ( V_2 ) ;
if ( V_45 == NULL )
return - 1 ;
V_45 -> V_53 = NULL ;
V_45 -> V_95 . V_85 =
( V_96 << V_97 ) | V_98 ;
++ V_2 -> V_99 ;
F_58 ( F_59 ( V_2 -> V_99 ) , & V_45 -> V_95 . V_100 ) ;
if ( V_90 == 0 ) {
F_60 ( & V_2 -> V_22 , 0 , & V_45 -> V_78 ,
V_2 -> V_20 , & V_45 -> V_80 ) ;
}
F_61 ( & V_2 -> V_23 ) ;
F_62 ( & V_45 -> V_52 , & V_2 -> V_24 ) ;
V_2 -> V_93 ++ ;
F_63 ( & V_2 -> V_23 ) ;
return 0 ;
}
static struct V_84 * F_64 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_84 * V_53 ;
struct V_101 * V_102 = V_2 -> V_55 ;
struct V_79 * V_79 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
V_53 = F_65 ( V_45 -> V_78 + F_66 ( V_102 ) , V_15 ) ;
if ( V_53 == NULL )
return NULL ;
F_67 ( V_53 , F_68 ( V_102 ) ) ;
F_69 ( V_53 ) ;
V_53 -> V_102 = V_102 ;
V_53 -> V_103 = F_70 ( V_104 ) ;
if ( F_71 ( V_53 , V_102 , V_104 , V_2 -> V_14 ,
V_102 -> V_105 , V_53 -> V_106 ) < 0 )
goto V_107;
V_79 = (struct V_79 * ) F_72 ( V_53 , V_45 -> V_78 ) ;
V_45 -> V_95 . V_87 = V_2 -> V_88 & V_89 ;
memcpy ( V_79 , & V_45 -> V_95 , sizeof( struct V_79 ) ) ;
V_6 = (struct V_5 * ) ( V_79 + 1 ) ;
for ( V_43 = V_45 -> V_80 . V_51 ; V_43 != & V_45 -> V_80 ; V_43 = V_43 -> V_51 ) {
struct V_108 * V_109 ;
V_109 = F_24 ( V_43 , struct V_108 , V_52 ) ;
memcpy ( V_6 , V_109 -> V_110 , V_109 -> V_111 ) ;
V_6 = F_73 ( V_6 ) ;
}
return V_53 ;
V_107:
F_27 ( V_53 ) ;
return NULL ;
}
static void F_28 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_42 * V_43 ;
struct V_108 * V_109 ;
V_43 = V_45 -> V_80 . V_51 ;
while ( V_43 != & V_45 -> V_80 ) {
V_109 = F_24 ( V_43 , struct V_108 , V_52 ) ;
V_43 = V_43 -> V_51 ;
F_51 ( & V_109 -> V_52 ) ;
if ( V_109 -> V_112 )
V_109 -> V_112 ( V_2 , V_109 -> V_113 ) ;
F_36 ( & V_2 -> V_22 . V_114 ) ;
F_74 ( & V_2 -> V_22 , V_109 ) ;
F_37 ( & V_2 -> V_22 . V_114 ) ;
}
F_52 ( V_2 , V_45 ) ;
if ( V_2 -> V_22 . V_115 > V_2 -> V_22 . V_116 )
F_75 ( & V_2 -> V_22 ) ;
}
static int F_76 ( struct V_1 * V_2 , int V_117 )
{
struct V_84 * V_53 ;
struct V_44 * V_45 ;
struct V_42 * V_43 ;
F_61 ( & V_2 -> V_23 ) ;
V_43 = V_2 -> V_26 -> V_51 ;
if ( V_43 == & V_2 -> V_24 ) {
F_63 ( & V_2 -> V_23 ) ;
return - 1 ;
}
V_45 = F_24 ( V_43 , struct V_44 , V_52 ) ;
if ( V_45 -> V_53 != NULL ) {
V_53 = V_45 -> V_53 ;
F_50 ( V_2 , V_45 ) ;
F_63 ( & V_2 -> V_23 ) ;
if ( V_117 )
F_53 ( V_53 ) ;
F_55 ( V_2 , V_53 ) ;
if ( ( int ) F_45 ( & V_118 ) <
V_119 ) {
if ( F_77 ( V_53 ) < 0 ) {
F_42 ( V_83 , L_13 ) ;
return - 1 ;
}
F_9 ( & V_118 ) ;
F_42 ( V_83 , L_14 ,
V_2 -> V_81 ) ;
return 0 ;
} else {
F_27 ( V_53 ) ;
F_42 ( V_83 , L_15 ) ;
return - 1 ;
}
}
V_2 -> V_26 = V_43 ;
V_53 = F_64 ( V_2 , V_45 ) ;
F_63 ( & V_2 -> V_23 ) ;
if ( ! V_53 )
return - 1 ;
if ( V_117 )
F_53 ( V_53 ) ;
F_42 ( V_83 , L_16 , V_45 -> V_95 . V_100 ) ;
if ( F_77 ( V_53 ) < 0 )
return - 1 ;
return 0 ;
}
void F_78 ( struct V_1 * V_2 , int V_120 )
{
while ( F_56 ( V_2 , 0 ) >= 0 )
V_120 ++ ;
switch ( V_2 -> V_69 & ( V_121 | V_70 ) ) {
case V_121 : {
V_120 += V_2 -> V_81 ;
if ( V_120 <= 0 )
goto V_122;
if ( V_120 > V_119 )
V_120 = V_119 ;
break;
}
case V_123 : {
if ( ( V_120 <= 0 ) && ( V_2 -> V_124 == 0 ) )
goto V_122;
break;
}
default: {
if ( V_120 <= 0 )
goto V_122;
break;
}
}
while ( V_120 -- ) {
if ( F_76 ( V_2 , V_120 ) < 0 )
break;
}
return;
V_122: F_56 ( V_2 , 1 ) ;
F_76 ( V_2 , 0 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_84 * V_53 ;
struct V_101 * V_102 = V_2 -> V_55 ;
struct V_79 * V_79 ;
struct V_5 * V_6 ;
struct V_42 * V_43 ;
struct V_42 V_125 ;
int V_78 = sizeof( struct V_79 ) ;
F_20 ( & V_125 ) ;
F_60 ( & V_2 -> V_22 , 1 , & V_78 ,
V_2 -> V_20 , & V_125 ) ;
if ( V_125 . V_51 == & V_125 )
return 0 ;
V_53 = F_65 ( V_78 + F_66 ( V_102 ) , V_15 ) ;
if ( V_53 == NULL ) {
F_42 ( V_9 , L_17 ) ;
F_79 ( & V_2 -> V_22 , & V_125 ) ;
return - 1 ;
}
F_67 ( V_53 , F_68 ( V_102 ) ) ;
F_69 ( V_53 ) ;
V_53 -> V_102 = V_102 ;
V_53 -> V_103 = F_70 ( V_104 ) ;
if ( F_71 ( V_53 , V_102 , V_104 , V_2 -> V_14 ,
V_102 -> V_105 , V_53 -> V_106 ) < 0 ) {
F_27 ( V_53 ) ;
return - 1 ;
}
V_79 = (struct V_79 * ) F_72 ( V_53 , V_78 ) ;
V_79 -> V_85 = ( V_96 << V_97 ) | V_126 ;
V_79 -> V_87 = V_2 -> V_88 & V_89 ;
V_6 = (struct V_5 * ) ( V_79 + 1 ) ;
for ( V_43 = V_125 . V_51 ; V_43 != & V_125 ; V_43 = V_43 -> V_51 ) {
struct V_108 * V_109 ;
V_109 = F_24 ( V_43 , struct V_108 , V_52 ) ;
memcpy ( V_6 , V_109 -> V_110 , V_109 -> V_111 ) ;
V_6 = F_73 ( V_6 ) ;
}
F_77 ( V_53 ) ;
F_79 ( & V_2 -> V_22 , & V_125 ) ;
return 0 ;
}
void F_80 ( struct V_1 * V_2 , T_1 V_127 )
{
struct V_42 * V_43 ;
struct V_44 * V_45 ;
struct V_42 * V_128 = NULL ;
struct V_42 * V_129 = NULL ;
T_1 V_130 ;
T_3 V_100 ;
F_61 ( & V_2 -> V_23 ) ;
V_43 = V_2 -> V_24 . V_51 ;
while ( V_43 != & V_2 -> V_24 ) {
V_45 = F_24 ( V_43 , struct V_44 , V_52 ) ;
V_100 = F_81 ( F_82 ( & V_45 -> V_95 . V_100 ) ) ;
V_130 = ( V_127 - ( V_100 & V_89 ) ) & V_89 ;
if ( ( V_130 > V_131 ) || ( V_100 == 0 ) )
break;
F_42 ( V_83 , L_18 ,
V_100 , V_2 -> V_93 ) ;
if ( V_128 == NULL )
V_128 = V_43 ;
V_129 = V_43 ;
V_43 = V_43 -> V_51 ;
V_2 -> V_93 -- ;
}
if ( V_128 ) {
V_129 -> V_51 -> V_132 = & V_2 -> V_24 ;
V_2 -> V_24 . V_51 = V_129 -> V_51 ;
V_129 -> V_51 = NULL ;
}
V_2 -> V_26 = & V_2 -> V_24 ;
F_63 ( & V_2 -> V_23 ) ;
while ( V_128 ) {
V_45 = F_24 ( V_128 , struct V_44 , V_52 ) ;
V_128 = V_128 -> V_51 ;
F_28 ( V_2 , V_45 ) ;
}
}
static struct V_46 * F_83 ( struct V_1 * V_2 , T_1 V_133 )
{
struct V_42 * V_43 ;
struct V_46 * V_47 ;
F_84 (e, &pd->stream_list) {
V_47 = F_24 ( V_43 , struct V_46 , V_52 ) ;
if ( V_47 -> V_133 == V_133 )
return V_47 ;
}
return NULL ;
}
int F_85 ( struct V_1 * V_2 , T_1 V_133 )
{
struct V_46 * V_47 =
F_14 ( sizeof( struct V_46 ) , V_15 ) ;
if ( ! V_47 )
return - V_134 ;
V_47 -> V_133 = V_133 ;
F_36 ( & V_2 -> V_27 ) ;
if ( ! F_83 ( V_2 , V_133 ) ) {
F_86 ( & V_47 -> V_52 , & V_2 -> V_28 ) ;
V_47 = NULL ;
}
F_37 ( & V_2 -> V_27 ) ;
F_19 ( V_47 ) ;
return 0 ;
}
static void F_26 ( struct V_46 * V_47 )
{
F_27 ( V_47 -> V_53 ) ;
F_19 ( V_47 ) ;
}
int F_87 ( struct V_1 * V_2 , T_1 V_133 )
{
struct V_46 * V_47 ;
F_36 ( & V_2 -> V_27 ) ;
V_47 = F_83 ( V_2 , V_133 ) ;
if ( V_47 )
F_44 ( & V_47 -> V_52 ) ;
F_37 ( & V_2 -> V_27 ) ;
if ( V_47 )
F_26 ( V_47 ) ;
return 0 ;
}
static void F_88 ( struct V_84 * V_53 )
{
F_89 ( & V_118 ) ;
}
int F_90 ( struct V_1 * V_2 , T_1 V_133 , const T_1 * V_110 , int V_106 )
{
struct V_101 * V_102 = V_2 -> V_55 ;
struct V_46 * V_47 ;
T_1 V_135 = 0 ;
struct V_84 * V_53 = NULL ;
struct V_79 * V_79 = NULL ;
int V_136 = 0 ;
F_36 ( & V_2 -> V_27 ) ;
V_47 = F_83 ( V_2 , V_133 ) ;
if ( V_47 ) {
V_53 = V_47 -> V_53 ;
V_47 -> V_53 = NULL ;
V_135 = V_47 -> V_135 ;
V_47 -> V_135 = 0 ;
V_79 = V_47 -> V_79 ;
V_136 = V_47 -> V_136 ;
}
F_37 ( & V_2 -> V_27 ) ;
if ( ! V_47 )
return 0 ;
if ( ! V_53 ) {
V_53 = F_65 ( V_2 -> V_20 + F_66 ( V_102 ) ,
V_15 ) ;
if ( V_53 == NULL )
return 0 ;
F_67 ( V_53 , F_68 ( V_102 ) ) ;
F_69 ( V_53 ) ;
V_53 -> V_102 = V_102 ;
V_53 -> V_103 = F_70 ( V_104 ) ;
V_53 -> V_137 = 0x7 ;
V_136 = sizeof( struct V_79 ) + sizeof( struct V_138 ) ;
V_79 = (struct V_79 * ) F_72 ( V_53 , V_136 ) ;
}
memcpy ( F_72 ( V_53 , V_106 ) , V_110 , V_106 ) ;
V_136 += V_106 ;
if ( ++ V_135 < V_2 -> V_139 ) {
F_36 ( & V_2 -> V_27 ) ;
V_47 -> V_53 = V_53 ;
V_47 -> V_135 = V_135 ;
V_47 -> V_79 = V_79 ;
V_47 -> V_136 = V_136 ;
F_37 ( & V_2 -> V_27 ) ;
} else {
struct V_79 V_140 ;
struct V_138 V_141 ;
F_36 ( & V_2 -> V_27 ) ;
V_141 . V_142 = V_47 -> V_143 ;
V_47 -> V_143 += V_135 ;
F_37 ( & V_2 -> V_27 ) ;
V_140 . V_85 =
( V_96 << V_97 ) | V_126 ;
V_140 . V_87 = V_2 -> V_88 & V_89 ;
V_140 . V_100 = 0 ;
V_141 . V_144 = V_133 ;
V_141 . V_145 = V_146 ;
V_141 . V_147 = V_135 ;
memcpy ( V_79 , & V_140 , sizeof( V_140 ) ) ;
memcpy ( V_79 + 1 , & V_141 , sizeof( V_141 ) ) ;
if ( F_71 ( V_53 , V_102 , V_104 , V_2 -> V_14 ,
V_102 -> V_105 , V_53 -> V_106 ) < 0 )
goto V_122;
V_53 -> V_148 = F_88 ;
if ( ! ( V_2 -> V_69 & V_70 ) ) {
struct V_44 * V_149 = NULL ;
int V_150 = V_2 -> V_81 ;
if ( V_150 >= V_2 -> V_151 ) {
struct V_42 * V_43 ;
struct V_44 * V_45 ;
F_42 ( V_83 , L_19 ,
V_150 ) ;
F_61 ( & V_2 -> V_23 ) ;
F_84 (e, &pd->tx_queue) {
V_45 = F_24 ( V_43 , struct V_44 ,
V_52 ) ;
if ( V_45 -> V_53 != NULL ) {
F_50 ( V_2 , V_45 ) ;
break;
}
}
F_63 ( & V_2 -> V_23 ) ;
}
V_149 = F_48 ( V_2 ) ;
if ( V_149 == NULL )
goto V_122;
V_149 -> V_95 = V_140 ;
V_149 -> V_53 = V_53 ;
F_36 ( & V_2 -> V_23 ) ;
F_62 ( & V_149 -> V_52 , & V_2 -> V_24 ) ;
V_2 -> V_81 ++ ;
F_37 ( & V_2 -> V_23 ) ;
F_42 ( V_83 ,
L_20 ,
V_2 -> V_81 , V_2 -> V_93 ) ;
return 0 ;
}
if ( F_45 ( & V_118 ) < V_119 ) {
F_9 ( & V_118 ) ;
if ( F_77 ( V_53 ) < 0 )
return - 1 ;
else
return 0 ;
}
V_122: F_27 ( V_53 ) ;
return - 1 ;
}
return 0 ;
}
void F_91 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( V_61 [ V_16 ] . V_152 )
V_61 [ V_16 ] . V_152 () ;
}
void F_92 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( V_61 [ V_16 ] . V_153 )
V_61 [ V_16 ] . V_153 () ;
}
void F_93 ( struct V_1 * V_2 , T_1 V_62 , struct V_5 * V_6 )
{
const struct V_57 * V_58 ;
if ( V_62 == 0 || V_62 > V_17 )
return;
V_58 = & V_61 [ V_62 - 1 ] ;
V_58 -> V_154 ( V_2 , V_6 ) ;
}
void F_43 ( struct V_1 * V_2 )
{
struct V_48 * V_45 ;
const struct V_57 * V_58 = & V_61 [ V_155 - 1 ] ;
while ( 1 ) {
F_36 ( & V_64 ) ;
if ( F_94 ( & V_2 -> V_25 ) ) {
F_37 ( & V_64 ) ;
break;
}
V_45 = F_95 ( & V_2 -> V_25 ,
struct V_48 , V_52 ) ;
F_44 ( & V_45 -> V_52 ) ;
F_37 ( & V_64 ) ;
if ( V_58 -> V_156 )
V_58 -> V_156 ( V_2 , V_45 -> V_133 , V_45 -> V_157 , V_45 -> V_106 ) ;
F_19 ( V_45 ) ;
}
}

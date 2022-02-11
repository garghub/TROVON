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
memcpy ( V_2 -> V_14 , V_14 , V_22 ) ;
if ( 0 != F_17 ( & V_2 -> V_23 ) ) {
F_18 ( V_2 ) ;
V_2 = NULL ;
}
F_16 ( & V_2 -> V_24 ) ;
F_19 ( & V_2 -> V_25 ) ;
F_19 ( & V_2 -> V_26 ) ;
V_2 -> V_27 = & V_2 -> V_25 ;
F_16 ( & V_2 -> V_28 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_20 ( & V_2 -> V_30 , V_31 ,
( unsigned long ) V_2 ) ;
F_20 ( & V_2 -> V_32 , V_33 ,
( unsigned long ) V_2 ) ;
F_21 ( & V_2 -> V_34 , V_35 , V_36 ) ;
F_21 ( & V_2 -> V_37 , V_35 , V_36 ) ;
V_2 -> V_34 . V_38 = V_39 ;
V_2 -> V_37 . V_38 = V_40 ;
}
return V_2 ;
}
static void F_22 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
struct V_49 * V_50 ;
struct V_1 * V_2 ;
F_7 ( V_2 , V_9 , L_5 ) ;
V_2 = F_23 ( V_42 , struct V_1 , V_51 ) ;
F_24 ( & V_2 -> V_30 ) ;
F_24 ( & V_2 -> V_32 ) ;
V_44 = V_2 -> V_29 . V_52 ;
while ( V_44 != & V_2 -> V_29 ) {
V_48 = F_23 ( V_44 , struct V_47 , V_53 ) ;
V_44 = V_44 -> V_52 ;
F_25 ( V_48 ) ;
}
V_44 = V_2 -> V_25 . V_52 ;
while ( V_44 != & V_2 -> V_25 ) {
V_46 = F_23 ( V_44 , struct V_45 , V_53 ) ;
V_44 = V_44 -> V_52 ;
if ( V_46 -> V_54 != NULL )
F_26 ( V_46 -> V_54 ) ;
F_27 ( V_2 , V_46 ) ;
}
F_28 ( & V_2 -> V_23 ) ;
V_44 = V_2 -> V_26 . V_52 ;
while ( V_44 != & V_2 -> V_26 ) {
V_50 = F_23 ( V_44 , struct V_49 , V_53 ) ;
V_44 = V_44 -> V_52 ;
F_18 ( V_50 ) ;
}
while ( V_2 -> V_55 ) {
V_44 = V_2 -> V_55 ;
V_2 -> V_55 = V_44 -> V_52 ;
F_18 ( F_23 ( V_44 , struct V_45 , V_53 ) ) ;
}
if ( V_2 -> V_56 )
F_29 ( V_2 -> V_56 ) ;
F_18 ( V_2 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( F_30 ( & V_2 -> V_37 ) )
F_31 ( & V_2 -> V_37 ) ;
if ( F_30 ( & V_2 -> V_34 ) )
F_31 ( & V_2 -> V_34 ) ;
F_32 ( & V_2 -> V_51 , F_22 ) ;
if ( ! F_33 ( & V_2 -> V_51 ) )
F_7 ( V_2 , V_9 , L_6 ) ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_57 , int V_3 )
{
const struct V_58 * V_59 ;
int V_60 = 0 ;
F_7 ( V_2 , V_9 , L_7 , V_61 , V_57 , V_3 ) ;
for ( V_59 = V_62 ; V_59 < & V_62 [ V_17 ] ; V_59 ++ ) {
if ( V_57 & ( 1 << V_59 -> V_63 ) ) {
if ( V_59 -> V_64 ( V_2 , V_3 ) ) {
V_60 = - 1 ;
F_7 ( V_2 , V_9 ,
L_8 ,
V_59 -> V_63 ) ;
break;
}
F_35 () ;
V_2 -> V_65 |= ( 1 << V_59 -> V_63 ) ;
if ( V_3 )
V_2 -> V_66 &= ~ ( 1 << V_59 -> V_63 ) ;
F_36 () ;
}
}
return V_60 ;
}
void F_37 ( struct V_1 * V_2 , T_2 V_57 , int V_4 )
{
const struct V_58 * V_59 ;
F_7 ( V_2 , V_9 , L_9 , V_61 , V_57 , V_4 ) ;
for ( V_59 = V_62 ; V_59 < & V_62 [ V_17 ] ; V_59 ++ ) {
if ( V_57 & ( 1 << V_59 -> V_63 ) ) {
F_35 () ;
if ( V_4 ) {
V_2 -> V_66 |= ( 1 << V_59 -> V_63 ) ;
} else {
V_2 -> V_65 &= ~ ( 1 << V_59 -> V_63 ) ;
V_2 -> V_66 &= ~ ( 1 << V_59 -> V_63 ) ;
}
F_36 () ;
V_59 -> V_67 ( V_2 , V_4 ) ;
}
}
}
void F_38 ( struct V_1 * V_2 , T_2 V_57 )
{
const struct V_58 * V_59 ;
int V_68 = 0 ;
for ( V_59 = V_62 ; V_59 < & V_62 [ V_17 ] ; V_59 ++ ) {
if ( V_59 -> V_34 && ( V_57 & ( 1 << V_59 -> V_63 ) ) ) {
if ( V_59 -> V_34 ( V_2 ) )
V_68 = 1 ;
}
}
if ( ( ! V_68 ) && ( F_30 ( & V_2 -> V_34 ) ) )
F_31 ( & V_2 -> V_34 ) ;
if ( V_2 -> V_69 & V_70 ) {
int V_71 = 8 ;
while ( V_71 -- && ( F_39 ( V_2 ) >= 0 ) )
;
}
}
void F_40 ( struct V_1 * V_2 )
{
T_2 V_72 ;
F_41 ( V_9 , L_10 , V_2 -> V_7 ) ;
F_42 ( V_2 ) ;
F_35 () ;
V_72 = V_2 -> V_65 ;
V_2 -> V_65 = 0 ;
V_2 -> V_66 = 0 ;
F_36 () ;
F_37 ( V_2 , V_72 , 0 ) ;
F_35 () ;
F_6 ( V_2 , V_11 ) ;
F_43 ( & V_2 -> V_53 ) ;
F_36 () ;
F_41 ( V_9 , L_11 , F_44 ( & V_2 -> V_13 ) ) ;
F_10 ( V_2 ) ;
}
int F_45 ( struct V_1 * V_2 )
{
int V_73 = 0 ;
T_2 V_72 ;
F_35 () ;
if ( V_2 -> V_7 & ( V_12 | V_11 ) ) {
F_36 () ;
return 0 ;
}
if ( V_2 -> V_74 && V_2 -> V_75 )
F_6 ( V_2 , V_12 ) ;
else
V_73 = 1 ;
V_72 = V_2 -> V_65 ;
F_36 () ;
if ( V_73 ) {
F_40 ( V_2 ) ;
} else {
F_37 ( V_2 , V_72 , 1 ) ;
F_46 ( V_2 , V_76 , V_2 -> V_74 ) ;
}
return V_73 ;
}
static struct V_45 * F_47 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = NULL ;
F_48 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_55 ) {
V_46 = F_23 ( V_2 -> V_55 , struct V_45 , V_53 ) ;
V_2 -> V_55 = V_2 -> V_55 -> V_52 ;
V_2 -> V_77 -- ;
}
F_49 ( & V_2 -> V_24 ) ;
if ( V_46 == NULL )
V_46 = F_50 ( sizeof( struct V_45 ) , V_15 ) ;
if ( V_46 ) {
V_46 -> V_78 = sizeof( struct V_79 ) ;
F_19 ( & V_46 -> V_53 ) ;
F_19 ( & V_46 -> V_80 ) ;
}
return V_46 ;
}
static void F_51 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
V_2 -> V_81 -- ;
F_52 ( & V_46 -> V_53 ) ;
if ( V_2 -> V_77 < V_82 ) {
V_46 -> V_53 . V_52 = V_2 -> V_55 ;
V_2 -> V_55 = & V_46 -> V_53 ;
V_2 -> V_77 ++ ;
} else {
F_18 ( V_46 ) ;
}
F_41 ( V_83 , L_12 ,
V_2 -> V_81 ) ;
}
static void F_53 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
F_48 ( & V_2 -> V_24 ) ;
if ( V_2 -> V_77 < V_82 ) {
V_46 -> V_53 . V_52 = V_2 -> V_55 ;
V_2 -> V_55 = & V_46 -> V_53 ;
V_2 -> V_77 ++ ;
V_46 = NULL ;
}
F_49 ( & V_2 -> V_24 ) ;
F_18 ( V_46 ) ;
}
static void F_54 ( struct V_84 * V_54 )
{
struct V_79 * V_79 = (struct V_79 * ) F_55 ( V_54 ) ;
V_79 -> V_85 |= V_86 ;
}
static void F_56 ( struct V_1 * V_2 , struct V_84 * V_54 )
{
struct V_79 * V_79 = (struct V_79 * ) F_55 ( V_54 ) ;
V_79 -> V_87 = V_2 -> V_88 & V_89 ;
}
int F_57 ( struct V_1 * V_2 , int V_90 )
{
struct V_45 * V_46 ;
if ( ( V_2 -> V_69 & V_91 ) != V_92 )
return - 1 ;
if ( V_2 -> V_93 >= V_94 )
return - 1 ;
if ( ! V_90 && ! F_58 ( & V_2 -> V_23 ) )
return - 1 ;
V_46 = F_47 ( V_2 ) ;
if ( V_46 == NULL )
return - 1 ;
V_46 -> V_54 = NULL ;
V_46 -> V_95 . V_85 =
( V_96 << V_97 ) | V_98 ;
++ V_2 -> V_99 ;
F_59 ( F_60 ( V_2 -> V_99 ) , & V_46 -> V_95 . V_100 ) ;
if ( V_90 == 0 ) {
F_61 ( & V_2 -> V_23 , 0 , & V_46 -> V_78 ,
V_2 -> V_20 , & V_46 -> V_80 ) ;
}
F_62 ( & V_2 -> V_24 ) ;
F_63 ( & V_46 -> V_53 , & V_2 -> V_25 ) ;
V_2 -> V_93 ++ ;
F_64 ( & V_2 -> V_24 ) ;
return 0 ;
}
static struct V_84 * F_65 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_84 * V_54 ;
struct V_101 * V_102 = V_2 -> V_56 ;
struct V_79 * V_79 ;
struct V_5 * V_6 ;
struct V_43 * V_44 ;
V_54 = F_66 ( V_46 -> V_78 + F_67 ( V_102 ) , V_15 ) ;
if ( V_54 == NULL )
return NULL ;
F_68 ( V_54 , F_69 ( V_102 ) ) ;
F_70 ( V_54 ) ;
V_54 -> V_102 = V_102 ;
V_54 -> V_103 = F_71 ( V_104 ) ;
if ( F_72 ( V_54 , V_102 , V_104 , V_2 -> V_14 ,
V_102 -> V_105 , V_54 -> V_106 ) < 0 )
goto V_107;
V_79 = (struct V_79 * ) F_73 ( V_54 , V_46 -> V_78 ) ;
V_46 -> V_95 . V_87 = V_2 -> V_88 & V_89 ;
memcpy ( V_79 , & V_46 -> V_95 , sizeof( struct V_79 ) ) ;
V_6 = (struct V_5 * ) ( V_79 + 1 ) ;
for ( V_44 = V_46 -> V_80 . V_52 ; V_44 != & V_46 -> V_80 ; V_44 = V_44 -> V_52 ) {
struct V_108 * V_109 ;
V_109 = F_23 ( V_44 , struct V_108 , V_53 ) ;
memcpy ( V_6 , V_109 -> V_110 , V_109 -> V_111 ) ;
V_6 = F_74 ( V_6 ) ;
}
return V_54 ;
V_107:
F_26 ( V_54 ) ;
return NULL ;
}
static void F_27 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
struct V_43 * V_44 ;
struct V_108 * V_109 ;
V_44 = V_46 -> V_80 . V_52 ;
while ( V_44 != & V_46 -> V_80 ) {
V_109 = F_23 ( V_44 , struct V_108 , V_53 ) ;
V_44 = V_44 -> V_52 ;
F_52 ( & V_109 -> V_53 ) ;
if ( V_109 -> V_112 )
V_109 -> V_112 ( V_2 , V_109 -> V_113 ) ;
F_48 ( & V_2 -> V_23 . V_114 ) ;
F_75 ( & V_2 -> V_23 , V_109 ) ;
F_49 ( & V_2 -> V_23 . V_114 ) ;
}
F_53 ( V_2 , V_46 ) ;
if ( V_2 -> V_23 . V_115 > V_2 -> V_23 . V_116 )
F_76 ( & V_2 -> V_23 ) ;
}
static int F_77 ( struct V_1 * V_2 , int V_117 )
{
struct V_84 * V_54 ;
struct V_45 * V_46 ;
struct V_43 * V_44 ;
F_62 ( & V_2 -> V_24 ) ;
V_44 = V_2 -> V_27 -> V_52 ;
if ( V_44 == & V_2 -> V_25 ) {
F_64 ( & V_2 -> V_24 ) ;
return - 1 ;
}
V_46 = F_23 ( V_44 , struct V_45 , V_53 ) ;
if ( V_46 -> V_54 != NULL ) {
V_54 = V_46 -> V_54 ;
F_51 ( V_2 , V_46 ) ;
F_64 ( & V_2 -> V_24 ) ;
if ( V_117 )
F_54 ( V_54 ) ;
F_56 ( V_2 , V_54 ) ;
if ( ( int ) F_44 ( & V_118 ) <
V_119 ) {
if ( F_78 ( V_54 ) < 0 ) {
F_41 ( V_83 , L_13 ) ;
return - 1 ;
}
F_9 ( & V_118 ) ;
F_41 ( V_83 , L_14 ,
V_2 -> V_81 ) ;
return 0 ;
} else {
F_26 ( V_54 ) ;
F_41 ( V_83 , L_15 ) ;
return - 1 ;
}
}
V_2 -> V_27 = V_44 ;
V_54 = F_65 ( V_2 , V_46 ) ;
F_64 ( & V_2 -> V_24 ) ;
if ( ! V_54 )
return - 1 ;
if ( V_117 )
F_54 ( V_54 ) ;
F_41 ( V_83 , L_16 , V_46 -> V_95 . V_100 ) ;
if ( F_78 ( V_54 ) < 0 )
return - 1 ;
return 0 ;
}
void F_79 ( struct V_1 * V_2 , int V_120 )
{
while ( F_57 ( V_2 , 0 ) >= 0 )
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
if ( F_77 ( V_2 , V_120 ) < 0 )
break;
}
return;
V_122: F_57 ( V_2 , 1 ) ;
F_77 ( V_2 , 0 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_84 * V_54 ;
struct V_101 * V_102 = V_2 -> V_56 ;
struct V_79 * V_79 ;
struct V_5 * V_6 ;
struct V_43 * V_44 ;
struct V_43 V_125 ;
int V_78 = sizeof( struct V_79 ) ;
F_19 ( & V_125 ) ;
F_61 ( & V_2 -> V_23 , 1 , & V_78 ,
V_2 -> V_20 , & V_125 ) ;
if ( V_125 . V_52 == & V_125 )
return 0 ;
V_54 = F_66 ( V_78 + F_67 ( V_102 ) , V_15 ) ;
if ( V_54 == NULL ) {
F_41 ( V_9 , L_17 ) ;
F_80 ( & V_2 -> V_23 , & V_125 ) ;
return - 1 ;
}
F_68 ( V_54 , F_69 ( V_102 ) ) ;
F_70 ( V_54 ) ;
V_54 -> V_102 = V_102 ;
V_54 -> V_103 = F_71 ( V_104 ) ;
if ( F_72 ( V_54 , V_102 , V_104 , V_2 -> V_14 ,
V_102 -> V_105 , V_54 -> V_106 ) < 0 ) {
F_26 ( V_54 ) ;
return - 1 ;
}
V_79 = (struct V_79 * ) F_73 ( V_54 , V_78 ) ;
V_79 -> V_85 = ( V_96 << V_97 ) | V_126 ;
V_79 -> V_87 = V_2 -> V_88 & V_89 ;
V_6 = (struct V_5 * ) ( V_79 + 1 ) ;
for ( V_44 = V_125 . V_52 ; V_44 != & V_125 ; V_44 = V_44 -> V_52 ) {
struct V_108 * V_109 ;
V_109 = F_23 ( V_44 , struct V_108 , V_53 ) ;
memcpy ( V_6 , V_109 -> V_110 , V_109 -> V_111 ) ;
V_6 = F_74 ( V_6 ) ;
}
F_78 ( V_54 ) ;
F_80 ( & V_2 -> V_23 , & V_125 ) ;
return 0 ;
}
void F_81 ( struct V_1 * V_2 , T_1 V_127 )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
struct V_43 * V_128 = NULL ;
struct V_43 * V_129 = NULL ;
T_1 V_130 ;
T_3 V_100 ;
F_62 ( & V_2 -> V_24 ) ;
V_44 = V_2 -> V_25 . V_52 ;
while ( V_44 != & V_2 -> V_25 ) {
V_46 = F_23 ( V_44 , struct V_45 , V_53 ) ;
V_100 = F_82 ( F_83 ( & V_46 -> V_95 . V_100 ) ) ;
V_130 = ( V_127 - ( V_100 & V_89 ) ) & V_89 ;
if ( ( V_130 > V_131 ) || ( V_100 == 0 ) )
break;
F_41 ( V_83 , L_18 ,
V_100 , V_2 -> V_93 ) ;
if ( V_128 == NULL )
V_128 = V_44 ;
V_129 = V_44 ;
V_44 = V_44 -> V_52 ;
V_2 -> V_93 -- ;
}
if ( V_128 ) {
V_129 -> V_52 -> V_132 = & V_2 -> V_25 ;
V_2 -> V_25 . V_52 = V_129 -> V_52 ;
V_129 -> V_52 = NULL ;
}
V_2 -> V_27 = & V_2 -> V_25 ;
F_64 ( & V_2 -> V_24 ) ;
while ( V_128 ) {
V_46 = F_23 ( V_128 , struct V_45 , V_53 ) ;
V_128 = V_128 -> V_52 ;
F_27 ( V_2 , V_46 ) ;
}
}
static struct V_47 * F_84 ( struct V_1 * V_2 , T_1 V_133 )
{
struct V_43 * V_44 ;
struct V_47 * V_48 ;
F_85 (e, &pd->stream_list) {
V_48 = F_23 ( V_44 , struct V_47 , V_53 ) ;
if ( V_48 -> V_133 == V_133 )
return V_48 ;
}
return NULL ;
}
int F_86 ( struct V_1 * V_2 , T_1 V_133 )
{
struct V_47 * V_48 =
F_14 ( sizeof( struct V_47 ) , V_15 ) ;
if ( ! V_48 )
return - V_134 ;
V_48 -> V_133 = V_133 ;
F_48 ( & V_2 -> V_28 ) ;
if ( ! F_84 ( V_2 , V_133 ) ) {
F_87 ( & V_48 -> V_53 , & V_2 -> V_29 ) ;
V_48 = NULL ;
}
F_49 ( & V_2 -> V_28 ) ;
F_18 ( V_48 ) ;
return 0 ;
}
static void F_25 ( struct V_47 * V_48 )
{
F_26 ( V_48 -> V_54 ) ;
F_18 ( V_48 ) ;
}
int F_88 ( struct V_1 * V_2 , T_1 V_133 )
{
struct V_47 * V_48 ;
F_48 ( & V_2 -> V_28 ) ;
V_48 = F_84 ( V_2 , V_133 ) ;
if ( V_48 )
F_43 ( & V_48 -> V_53 ) ;
F_49 ( & V_2 -> V_28 ) ;
if ( V_48 )
F_25 ( V_48 ) ;
return 0 ;
}
static void F_89 ( struct V_84 * V_54 )
{
F_90 ( & V_118 ) ;
}
int F_91 ( struct V_1 * V_2 , T_1 V_133 , const T_1 * V_110 , int V_106 )
{
struct V_101 * V_102 = V_2 -> V_56 ;
struct V_47 * V_48 ;
T_1 V_135 = 0 ;
struct V_84 * V_54 = NULL ;
struct V_79 * V_79 = NULL ;
int V_136 = 0 ;
F_48 ( & V_2 -> V_28 ) ;
V_48 = F_84 ( V_2 , V_133 ) ;
if ( V_48 ) {
V_54 = V_48 -> V_54 ;
V_48 -> V_54 = NULL ;
V_135 = V_48 -> V_135 ;
V_48 -> V_135 = 0 ;
V_79 = V_48 -> V_79 ;
V_136 = V_48 -> V_136 ;
}
F_49 ( & V_2 -> V_28 ) ;
if ( ! V_48 )
return 0 ;
if ( ! V_54 ) {
V_54 = F_66 ( V_2 -> V_20 + F_67 ( V_102 ) ,
V_15 ) ;
if ( V_54 == NULL )
return 0 ;
F_68 ( V_54 , F_69 ( V_102 ) ) ;
F_70 ( V_54 ) ;
V_54 -> V_102 = V_102 ;
V_54 -> V_103 = F_71 ( V_104 ) ;
V_54 -> V_137 = 0x7 ;
V_136 = sizeof( struct V_79 ) + sizeof( struct V_138 ) ;
V_79 = (struct V_79 * ) F_73 ( V_54 , V_136 ) ;
}
memcpy ( F_73 ( V_54 , V_106 ) , V_110 , V_106 ) ;
V_136 += V_106 ;
if ( ++ V_135 < V_2 -> V_139 ) {
F_48 ( & V_2 -> V_28 ) ;
V_48 -> V_54 = V_54 ;
V_48 -> V_135 = V_135 ;
V_48 -> V_79 = V_79 ;
V_48 -> V_136 = V_136 ;
F_49 ( & V_2 -> V_28 ) ;
} else {
struct V_79 V_140 ;
struct V_138 V_141 ;
F_48 ( & V_2 -> V_28 ) ;
V_141 . V_142 = V_48 -> V_143 ;
V_48 -> V_143 += V_135 ;
F_49 ( & V_2 -> V_28 ) ;
V_140 . V_85 =
( V_96 << V_97 ) | V_126 ;
V_140 . V_87 = V_2 -> V_88 & V_89 ;
V_140 . V_100 = 0 ;
V_141 . V_144 = V_133 ;
V_141 . V_145 = V_146 ;
V_141 . V_147 = V_135 ;
memcpy ( V_79 , & V_140 , sizeof( V_140 ) ) ;
memcpy ( V_79 + 1 , & V_141 , sizeof( V_141 ) ) ;
if ( F_72 ( V_54 , V_102 , V_104 , V_2 -> V_14 ,
V_102 -> V_105 , V_54 -> V_106 ) < 0 )
goto V_122;
V_54 -> V_148 = F_89 ;
if ( ! ( V_2 -> V_69 & V_70 ) ) {
struct V_45 * V_149 = NULL ;
int V_150 = V_2 -> V_81 ;
if ( V_150 >= V_2 -> V_151 ) {
struct V_43 * V_44 ;
struct V_45 * V_46 ;
F_41 ( V_83 , L_19 ,
V_150 ) ;
F_62 ( & V_2 -> V_24 ) ;
F_85 (e, &pd->tx_queue) {
V_46 = F_23 ( V_44 , struct V_45 ,
V_53 ) ;
if ( V_46 -> V_54 != NULL ) {
F_51 ( V_2 , V_46 ) ;
break;
}
}
F_64 ( & V_2 -> V_24 ) ;
}
V_149 = F_47 ( V_2 ) ;
if ( V_149 == NULL )
goto V_122;
V_149 -> V_95 = V_140 ;
V_149 -> V_54 = V_54 ;
F_48 ( & V_2 -> V_24 ) ;
F_63 ( & V_149 -> V_53 , & V_2 -> V_25 ) ;
V_2 -> V_81 ++ ;
F_49 ( & V_2 -> V_24 ) ;
F_41 ( V_83 ,
L_20 ,
V_2 -> V_81 , V_2 -> V_93 ) ;
return 0 ;
}
if ( F_44 ( & V_118 ) < V_119 ) {
F_9 ( & V_118 ) ;
if ( F_78 ( V_54 ) < 0 )
return - 1 ;
else
return 0 ;
}
V_122: F_26 ( V_54 ) ;
return - 1 ;
}
return 0 ;
}
void F_92 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( V_62 [ V_16 ] . V_152 )
V_62 [ V_16 ] . V_152 () ;
}
void F_93 ( void )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ )
if ( V_62 [ V_16 ] . V_153 )
V_62 [ V_16 ] . V_153 () ;
}
void F_94 ( struct V_1 * V_2 , T_1 V_63 , struct V_5 * V_6 )
{
const struct V_58 * V_59 ;
if ( V_63 == 0 || V_63 > V_17 )
return;
V_59 = & V_62 [ V_63 - 1 ] ;
V_59 -> V_154 ( V_2 , V_6 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_49 * V_46 ;
const struct V_58 * V_59 = & V_62 [ V_155 - 1 ] ;
while ( 1 ) {
F_35 () ;
if ( F_95 ( & V_2 -> V_26 ) ) {
F_36 () ;
break;
}
V_46 = F_96 ( & V_2 -> V_26 ,
struct V_49 , V_53 ) ;
F_43 ( & V_46 -> V_53 ) ;
F_36 () ;
if ( V_59 -> V_156 )
V_59 -> V_156 ( V_2 , V_46 -> V_133 , V_46 -> V_157 , V_46 -> V_106 ) ;
F_18 ( V_46 ) ;
}
}

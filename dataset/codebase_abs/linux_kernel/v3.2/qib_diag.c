static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = V_5 ;
if ( V_4 )
V_5 = V_4 -> V_6 ;
else
V_4 = F_2 ( sizeof *V_4 , V_7 ) ;
if ( V_4 ) {
V_4 -> V_6 = NULL ;
V_4 -> V_3 = V_3 ;
V_4 -> V_8 = V_9 -> V_8 ;
V_4 -> V_10 = V_11 ;
}
return V_4 ;
}
static void F_3 ( struct V_1 * V_4 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
struct V_1 * V_12 , * V_13 ;
V_13 = NULL ;
if ( V_4 == V_3 -> V_14 ) {
V_3 -> V_14 = V_4 -> V_6 ;
V_13 = V_4 ;
} else {
V_12 = V_4 -> V_3 -> V_14 ;
while ( V_12 ) {
if ( V_4 == V_12 -> V_6 ) {
V_12 -> V_6 = V_4 -> V_6 ;
V_13 = V_4 ;
break;
}
V_12 = V_12 -> V_6 ;
}
}
if ( V_13 ) {
V_13 -> V_10 = V_15 ;
V_13 -> V_3 = NULL ;
V_13 -> V_8 = 0 ;
V_13 -> V_6 = V_5 ;
V_5 = V_13 ;
}
}
int F_4 ( struct V_2 * V_3 )
{
char V_16 [ 16 ] ;
int V_17 = 0 ;
if ( F_5 ( & V_18 ) == 1 ) {
V_17 = F_6 ( V_19 , L_1 ,
& V_20 , & V_21 ,
& V_22 ) ;
if ( V_17 )
goto V_23;
}
snprintf ( V_16 , sizeof( V_16 ) , L_2 , V_3 -> V_24 ) ;
V_17 = F_6 ( V_25 + V_3 -> V_24 , V_16 ,
& V_26 , & V_3 -> V_27 ,
& V_3 -> V_28 ) ;
V_23:
return V_17 ;
}
void F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( F_8 ( & V_18 ) )
F_9 ( & V_21 , & V_22 ) ;
F_9 ( & V_3 -> V_27 , & V_3 -> V_28 ) ;
while ( V_3 -> V_14 )
F_3 ( V_3 -> V_14 ) ;
while ( V_5 ) {
V_4 = V_5 ;
V_5 = V_4 -> V_6 ;
F_10 ( V_4 ) ;
}
F_11 ( V_3 ) ;
}
static T_1 T_2 * F_12 ( struct V_2 * V_3 , T_1 V_29 ,
T_1 * V_30 )
{
T_1 V_31 ;
T_1 V_32 , V_33 = 0 ;
T_1 T_2 * V_34 = ( T_1 T_2 * ) V_3 -> V_35 ;
T_1 T_2 * V_36 = NULL ;
T_1 V_37 = 0 ;
T_1 V_38 , V_39 ;
V_31 = ( V_3 -> V_40 - V_3 -> V_35 ) * sizeof( V_41 ) ;
if ( V_29 < V_31 ) {
V_36 = V_34 + ( V_29 / sizeof( T_1 ) ) ;
V_37 = V_31 - V_29 ;
goto V_42;
}
if ( V_3 -> V_43 ) {
T_1 V_44 = ( V_3 -> V_45 * V_3 -> V_46 ) + V_3 -> V_47 ;
if ( ! V_3 -> V_48 )
V_33 = V_3 -> V_47 ;
V_34 = ( T_1 T_2 * ) V_3 -> V_43 ;
if ( V_29 >= V_3 -> V_47 && V_29 < V_44 ) {
V_36 = V_34 + ( V_29 - V_3 -> V_47 ) / sizeof( T_1 ) ;
V_37 = V_44 - V_29 ;
goto V_42;
}
}
V_32 = V_3 -> V_49 ;
if ( V_33 == 0 ) {
T_1 V_50 = V_3 -> V_51 * F_13 ( V_3 -> V_52 , V_3 -> V_53 ) ;
V_33 = V_32 + V_50 ;
}
V_38 = V_3 -> V_54 * V_3 -> V_55 ;
V_39 = V_3 -> V_56 >> 32 ;
if ( V_3 -> V_54 ) {
if ( V_32 > V_39 )
V_32 = V_39 ;
else {
if ( ! V_3 -> V_43 || V_3 -> V_48 )
V_33 = V_39 + V_38 ;
}
}
if ( V_29 >= V_32 && V_29 < V_33 ) {
V_29 -= V_32 ;
V_36 = ( T_1 T_2 * ) V_3 -> V_57 + ( V_29 / sizeof( T_1 ) ) ;
V_37 = V_33 - V_29 ;
}
if ( ! V_36 && V_39 && V_3 -> V_48 ) {
V_33 = V_39 + V_38 + 2 * V_3 -> V_55 ;
if ( V_29 >= ( V_39 + V_38 ) && V_29 < V_33 ) {
V_36 = ( T_1 T_2 * ) V_3 -> V_48 +
( ( V_29 - ( V_39 + V_38 ) ) / sizeof( T_1 ) ) ;
V_37 = V_33 - V_29 ;
}
}
V_42:
if ( V_30 )
* V_30 = V_37 ;
return V_36 ;
}
static int F_14 ( struct V_2 * V_3 , void T_3 * V_58 ,
T_1 V_59 , T_4 V_60 )
{
const V_41 T_2 * V_61 ;
const V_41 T_2 * V_62 ;
T_1 V_63 ;
int V_17 ;
V_61 = ( const V_41 T_2 * ) F_12 ( V_3 , V_59 , & V_63 ) ;
if ( V_61 == NULL || V_63 == 0 || ! ( V_3 -> V_64 & V_65 ) ) {
V_17 = - V_66 ;
goto V_67;
}
if ( V_60 >= V_63 )
V_60 = V_63 ;
V_62 = V_61 + ( V_60 / sizeof( V_41 ) ) ;
while ( V_61 < V_62 ) {
V_41 V_68 = F_15 ( V_61 ) ;
if ( F_16 ( V_58 , & V_68 , sizeof( V_41 ) ) ) {
V_17 = - V_69 ;
goto V_67;
}
V_61 ++ ;
V_58 += sizeof( V_41 ) ;
}
V_17 = 0 ;
V_67:
return V_17 ;
}
static int F_17 ( struct V_2 * V_3 , T_1 V_59 ,
const void T_3 * V_58 , T_4 V_60 )
{
V_41 T_2 * V_61 ;
const V_41 T_2 * V_62 ;
T_1 V_63 ;
int V_17 ;
V_61 = ( V_41 T_2 * ) F_12 ( V_3 , V_59 , & V_63 ) ;
if ( V_61 == NULL || V_63 == 0 || ! ( V_3 -> V_64 & V_65 ) ) {
V_17 = - V_66 ;
goto V_67;
}
if ( V_60 >= V_63 )
V_60 = V_63 ;
V_62 = V_61 + ( V_60 / sizeof( V_41 ) ) ;
while ( V_61 < V_62 ) {
V_41 V_68 ;
if ( F_18 ( & V_68 , V_58 , sizeof( V_68 ) ) ) {
V_17 = - V_69 ;
goto V_67;
}
F_19 ( V_68 , V_61 ) ;
V_61 ++ ;
V_58 += sizeof( V_41 ) ;
}
V_17 = 0 ;
V_67:
return V_17 ;
}
static int F_20 ( struct V_2 * V_3 , void T_3 * V_58 ,
T_1 V_59 , T_4 V_60 )
{
const T_1 T_2 * V_61 ;
const T_1 T_2 * V_62 ;
T_1 V_63 ;
int V_17 ;
V_61 = F_12 ( V_3 , V_59 , & V_63 ) ;
if ( V_61 == NULL || V_63 == 0 || ! ( V_3 -> V_64 & V_65 ) ) {
V_17 = - V_66 ;
goto V_67;
}
if ( V_60 >= V_63 )
V_60 = V_63 ;
V_62 = V_61 + ( V_60 / sizeof( T_1 ) ) ;
while ( V_61 < V_62 ) {
T_1 V_68 = F_21 ( V_61 ) ;
if ( F_16 ( V_58 , & V_68 , sizeof( V_68 ) ) ) {
V_17 = - V_69 ;
goto V_67;
}
V_61 ++ ;
V_58 += sizeof( T_1 ) ;
}
V_17 = 0 ;
V_67:
return V_17 ;
}
static int F_22 ( struct V_2 * V_3 , T_1 V_59 ,
const void T_3 * V_58 , T_4 V_60 )
{
T_1 T_2 * V_61 ;
const T_1 T_2 * V_62 ;
T_1 V_63 ;
int V_17 ;
V_61 = F_12 ( V_3 , V_59 , & V_63 ) ;
if ( V_61 == NULL || V_63 == 0 || ! ( V_3 -> V_64 & V_65 ) ) {
V_17 = - V_66 ;
goto V_67;
}
if ( V_60 >= V_63 )
V_60 = V_63 ;
V_62 = V_61 + ( V_60 / sizeof( T_1 ) ) ;
while ( V_61 < V_62 ) {
T_1 V_68 ;
if ( F_18 ( & V_68 , V_58 , sizeof( V_68 ) ) ) {
V_17 = - V_69 ;
goto V_67;
}
F_23 ( V_68 , V_61 ) ;
V_61 ++ ;
V_58 += sizeof( T_1 ) ;
}
V_17 = 0 ;
V_67:
return V_17 ;
}
static int F_24 ( struct V_70 * V_71 , struct V_72 * V_73 )
{
int V_24 = F_25 ( V_71 ) - V_25 ;
struct V_2 * V_3 ;
struct V_1 * V_4 ;
int V_17 ;
F_26 ( & V_74 ) ;
V_3 = F_27 ( V_24 ) ;
if ( V_3 == NULL || ! ( V_3 -> V_64 & V_65 ) ||
! V_3 -> V_35 ) {
V_17 = - V_75 ;
goto V_67;
}
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
V_17 = - V_76 ;
goto V_67;
}
V_4 -> V_6 = V_3 -> V_14 ;
V_3 -> V_14 = V_4 ;
V_73 -> V_77 = V_4 ;
V_17 = 0 ;
V_67:
F_28 ( & V_74 ) ;
return V_17 ;
}
static T_5 F_29 ( struct V_72 * V_73 ,
const char T_3 * V_68 ,
T_4 V_60 , T_6 * V_78 )
{
T_1 T_2 * V_79 ;
T_1 V_80 , V_81 , V_82 ;
struct V_83 V_84 ;
T_1 * V_85 = NULL ;
struct V_2 * V_3 ;
struct V_86 * V_87 ;
T_5 V_17 = 0 ;
if ( V_60 != sizeof( V_84 ) ) {
V_17 = - V_66 ;
goto V_67;
}
if ( F_18 ( & V_84 , V_68 , sizeof( V_84 ) ) ) {
V_17 = - V_69 ;
goto V_67;
}
V_3 = F_27 ( V_84 . V_24 ) ;
if ( ! V_3 || ! ( V_3 -> V_64 & V_65 ) || ! V_3 -> V_35 ) {
V_17 = - V_75 ;
goto V_67;
}
if ( ! ( V_3 -> V_64 & V_88 ) ) {
V_17 = - V_75 ;
goto V_67;
}
if ( V_84 . V_89 != V_90 ) {
F_30 ( V_3 , L_3 ,
V_84 . V_89 ) ;
V_17 = - V_66 ;
goto V_67;
}
if ( V_84 . V_91 & 3 ) {
V_17 = - V_66 ;
goto V_67;
}
if ( ! V_84 . V_92 || V_84 . V_92 > V_3 -> V_93 ) {
V_17 = - V_66 ;
goto V_67;
}
V_87 = & V_3 -> V_94 [ V_84 . V_92 - 1 ] ;
V_80 = sizeof( T_1 ) + V_84 . V_91 ;
V_81 = V_84 . V_91 >> 2 ;
if ( ( V_80 + 4 ) > V_87 -> V_95 ) {
V_17 = - V_66 ;
goto V_67;
}
V_85 = F_31 ( V_80 ) ;
if ( ! V_85 ) {
F_32 ( V_3 -> V_96 , L_4
L_5 ) ;
V_17 = - V_76 ;
goto V_67;
}
if ( F_18 ( V_85 ,
( const void T_3 * ) ( unsigned long ) V_84 . V_68 ,
V_84 . V_91 ) ) {
V_17 = - V_69 ;
goto V_67;
}
V_80 >>= 2 ;
if ( V_84 . V_97 == 0 )
V_84 . V_97 = V_80 ;
V_79 = V_3 -> V_98 ( V_87 , V_84 . V_97 , & V_82 ) ;
if ( ! V_79 ) {
V_17 = - V_99 ;
goto V_67;
}
V_3 -> V_100 ( V_3 -> V_94 , F_33 ( V_82 ) ) ;
V_3 -> V_101 ( V_3 , V_82 , 1 , V_102 , NULL ) ;
F_19 ( V_84 . V_97 , V_79 ) ;
if ( V_3 -> V_64 & V_103 ) {
F_34 () ;
F_35 ( V_79 + 2 , V_85 , V_81 - 1 ) ;
F_34 () ;
F_36 ( V_85 [ V_81 - 1 ] , V_79 + V_81 + 1 ) ;
} else
F_35 ( V_79 + 2 , V_85 , V_81 ) ;
if ( V_3 -> V_64 & V_104 ) {
T_1 V_105 = ( V_82 >= V_3 -> V_51 ) ? 2047 : 1023 ;
F_34 () ;
F_36 ( 0xaebecede , V_79 + V_105 ) ;
}
F_34 () ;
F_37 ( V_3 , V_82 ) ;
V_3 -> V_101 ( V_3 , V_82 , 1 , V_106 , NULL ) ;
V_17 = sizeof( V_84 ) ;
V_67:
F_38 ( V_85 ) ;
return V_17 ;
}
static int F_39 ( struct V_70 * V_71 , struct V_72 * V_73 )
{
F_26 ( & V_74 ) ;
F_3 ( V_73 -> V_77 ) ;
V_73 -> V_77 = NULL ;
F_28 ( & V_74 ) ;
return 0 ;
}
int F_40 ( struct V_2 * V_3 ,
const struct V_107 * V_108 )
{
struct V_109 * V_110 ;
int V_17 = - V_66 ;
if ( ! V_3 || ! V_108 )
goto V_67;
V_17 = - V_76 ;
V_110 = F_31 ( sizeof *V_110 ) ;
if ( ! V_110 ) {
F_41 (KERN_ERR QIB_DRV_NAME L_6 ) ;
goto V_67;
}
if ( V_110 ) {
unsigned long V_64 ;
F_42 ( & V_3 -> V_111 , V_64 ) ;
V_110 -> V_108 = V_108 ;
V_110 -> V_6 = V_3 -> V_112 ;
V_3 -> V_112 = V_110 ;
F_43 ( & V_3 -> V_111 , V_64 ) ;
V_17 = 0 ;
}
V_67:
return V_17 ;
}
static void F_11 ( struct V_2 * V_3 )
{
struct V_109 * V_110 ;
unsigned long V_64 ;
F_42 ( & V_3 -> V_111 , V_64 ) ;
V_110 = V_3 -> V_112 ;
while ( V_110 ) {
V_3 -> V_112 = V_110 -> V_6 ;
F_43 ( & V_3 -> V_111 , V_64 ) ;
F_38 ( V_110 ) ;
F_42 ( & V_3 -> V_111 , V_64 ) ;
V_110 = V_3 -> V_112 ;
}
F_43 ( & V_3 -> V_111 , V_64 ) ;
}
static const struct V_107 * F_44 ( struct V_2 * V_3 ,
T_1 V_113 )
{
struct V_109 * V_110 ;
const struct V_107 * V_108 = NULL ;
V_110 = V_3 -> V_112 ;
while ( V_110 ) {
V_108 = V_110 -> V_108 ;
if ( V_113 >= V_108 -> V_114 && V_113 <= V_108 -> V_115 )
break;
V_110 = V_110 -> V_6 ;
}
if ( ! V_110 )
V_108 = NULL ;
return V_108 ;
}
static T_5 F_45 ( struct V_72 * V_73 , char T_3 * V_68 ,
T_4 V_60 , T_6 * V_78 )
{
struct V_1 * V_4 = V_73 -> V_77 ;
struct V_2 * V_3 = V_4 -> V_3 ;
void T_2 * V_116 ;
T_5 V_17 ;
if ( V_4 -> V_8 != V_9 -> V_8 ) {
V_17 = - V_117 ;
goto V_67;
}
V_116 = V_3 -> V_35 ;
if ( V_60 == 0 )
V_17 = 0 ;
else if ( ( V_60 % 4 ) || ( * V_78 % 4 ) )
V_17 = - V_66 ;
else if ( V_4 -> V_10 < V_118 && ( * V_78 || V_60 != 8 ) )
V_17 = - V_66 ;
else {
unsigned long V_64 ;
V_41 V_119 = 0 ;
int V_120 ;
const struct V_107 * V_108 ;
V_120 = ( V_60 % 8 ) || ( * V_78 % 8 ) ;
V_17 = - 1 ;
F_42 ( & V_3 -> V_111 , V_64 ) ;
V_108 = F_44 ( V_3 , * V_78 ) ;
if ( V_108 ) {
T_1 V_29 = * V_78 ;
V_17 = V_108 -> V_121 ( V_3 , V_108 , V_29 , & V_119 , 0 , V_120 ) ;
}
F_43 ( & V_3 -> V_111 , V_64 ) ;
if ( ! V_108 ) {
if ( V_120 )
V_17 = F_20 ( V_3 , V_68 , ( T_1 ) * V_78 ,
V_60 ) ;
else
V_17 = F_14 ( V_3 , V_68 , ( T_1 ) * V_78 ,
V_60 ) ;
} else if ( V_17 == V_60 ) {
V_17 = F_16 ( V_68 , & V_119 , V_120 ?
sizeof( T_1 ) : sizeof( V_41 ) ) ;
if ( V_17 )
V_17 = - V_69 ;
}
}
if ( V_17 >= 0 ) {
* V_78 += V_60 ;
V_17 = V_60 ;
if ( V_4 -> V_10 == V_11 )
V_4 -> V_10 = V_122 ;
}
V_67:
return V_17 ;
}
static T_5 F_46 ( struct V_72 * V_73 , const char T_3 * V_68 ,
T_4 V_60 , T_6 * V_78 )
{
struct V_1 * V_4 = V_73 -> V_77 ;
struct V_2 * V_3 = V_4 -> V_3 ;
void T_2 * V_116 ;
T_5 V_17 ;
if ( V_4 -> V_8 != V_9 -> V_8 ) {
V_17 = - V_117 ;
goto V_67;
}
V_116 = V_3 -> V_35 ;
if ( V_60 == 0 )
V_17 = 0 ;
else if ( ( V_60 % 4 ) || ( * V_78 % 4 ) )
V_17 = - V_66 ;
else if ( V_4 -> V_10 < V_118 &&
( ( * V_78 || V_60 != 8 ) || V_4 -> V_10 != V_122 ) )
V_17 = - V_66 ;
else {
unsigned long V_64 ;
const struct V_107 * V_108 = NULL ;
int V_120 = ( V_60 % 8 ) || ( * V_78 % 8 ) ;
if ( V_60 == 4 || V_60 == 8 ) {
V_41 V_119 ;
T_1 V_29 = * V_78 ;
V_17 = F_18 ( & V_119 , V_68 , V_60 ) ;
if ( V_17 ) {
V_17 = - V_69 ;
goto V_67;
}
F_42 ( & V_3 -> V_111 , V_64 ) ;
V_108 = F_44 ( V_3 , * V_78 ) ;
if ( V_108 )
V_17 = V_108 -> V_121 ( V_3 , V_108 , V_29 , & V_119 , ~ 0Ull ,
V_120 ) ;
F_43 ( & V_3 -> V_111 , V_64 ) ;
}
if ( ! V_108 ) {
if ( V_120 )
V_17 = F_22 ( V_3 , ( T_1 ) * V_78 , V_68 ,
V_60 ) ;
else
V_17 = F_17 ( V_3 , ( T_1 ) * V_78 , V_68 ,
V_60 ) ;
}
}
if ( V_17 >= 0 ) {
* V_78 += V_60 ;
V_17 = V_60 ;
if ( V_4 -> V_10 == V_122 )
V_4 -> V_10 = V_118 ;
}
V_67:
return V_17 ;
}

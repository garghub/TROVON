static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
int V_10 , V_11 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_4 -> V_13 )
goto V_14;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 ; V_10 ++ ) {
if ( ! V_4 -> V_8 [ V_10 ] )
continue;
V_8 = V_4 -> V_8 [ V_10 ] ;
V_6 = ( void * ) & V_8 -> V_16 ;
if ( ! ( V_6 -> V_17 & V_18 ) )
continue;
V_11 = F_4 ( V_8 , V_8 -> V_19 -> V_20 ) ;
if ( ! V_11 )
V_6 -> V_17 &= ~ V_18 ;
else
F_5 ( & V_4 -> V_2 ) ;
}
V_14:
F_6 ( & V_4 -> V_12 , V_9 ) ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_21 * V_22 = ( void * ) V_6 ;
struct V_7 * V_8 = F_2 ( V_22 , struct V_7 , V_16 ) ;
struct V_3 * V_4 = V_8 -> V_19 -> V_20 ;
F_8 ( & V_4 -> V_12 ) ;
V_6 -> V_17 |= V_18 ;
F_5 ( & V_4 -> V_2 ) ;
}
static void F_9 ( struct V_3 * V_4 , int V_23 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned long V_9 ;
int V_10 , V_11 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 ; V_10 ++ ) {
if ( ! V_4 -> V_8 [ V_10 ] )
continue;
V_8 = V_4 -> V_8 [ V_10 ] ;
V_6 = ( void * ) & V_8 -> V_16 ;
F_10 ( V_8 , V_24 , 0 ) ;
V_6 -> V_17 &= ~ V_25 ;
V_8 -> V_23 = V_23 << 16 ;
V_11 = F_11 ( V_8 , V_24 ) ;
F_12 ( V_11 != 0 ) ;
}
F_6 ( & V_4 -> V_12 , V_9 ) ;
}
static void F_13 ( struct V_26 * V_26 , struct V_7 * V_8 )
{
struct V_27 * V_27 = V_26 -> V_28 ;
struct V_29 * V_30 = V_8 -> V_19 ;
if ( V_26 -> V_31 > 16 ) {
unsigned V_32 = F_14 ( & V_27 -> V_32 ) ;
if ( V_32 + 16 != V_26 -> V_31 ) {
int V_33 = F_15 ( V_32 + 16 , V_26 -> V_31 ) - 16 ;
if ( V_33 < 0 )
V_33 = 0 ;
F_16 ( V_34 , V_30 , L_1
L_2
L_3 , V_24 ,
V_26 -> V_31 , V_32 , V_33 ) ;
V_32 = V_33 ;
}
memcpy ( V_8 -> V_35 , V_27 -> V_36 , V_32 ) ;
}
V_8 -> V_23 = V_27 -> V_37 ;
}
static void F_10 ( struct V_7 * V_8 , const char * V_38 ,
int V_37 )
{
struct V_5 * V_39 = ( void * ) & V_8 -> V_16 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
F_17 ( V_34 , V_8 ,
L_4 ,
V_38 , V_37 , V_6 -> V_40 ,
( V_39 -> V_17 & V_41 ) ? L_5 : L_6 ,
( V_39 -> V_17 & V_42 ) ? L_7 : L_6 ,
( V_39 -> V_17 & V_43 ) ? L_8 : L_6 ,
( V_39 -> V_17 & V_44 ) ? L_9 : L_6 ,
( V_39 -> V_17 & V_45 ) ? L_10 : L_6 ,
( V_39 -> V_17 & V_46 ) ? L_11 : L_6 ,
( V_39 -> V_17 & V_47 ) ? L_12 : L_6 ,
( V_39 -> V_17 & V_25 ) ? L_13 : L_6 ,
( V_39 -> V_17 & V_48 ) ? L_14 : L_6 ,
( V_39 -> V_17 & V_49 ) ? L_15 : L_6 ,
( V_39 -> V_17 & V_50 ) ? L_16 : L_6 ,
( V_39 -> V_17 & V_18 ) ? L_17 : L_6 ) ;
F_18 ( V_8 ) ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
if ( ! V_8 )
return;
V_6 = ( void * ) & V_8 -> V_16 ;
if ( V_6 -> V_17 & V_47 )
F_20 ( V_6 -> V_51 ) ;
if ( ! ( V_6 -> V_17 & V_48 ) )
F_20 ( V_6 -> V_52 ) ;
if ( ! ( V_6 -> V_17 & V_49 ) )
F_20 ( V_6 -> V_53 ) ;
}
static int F_11 ( struct V_7 * V_8 , const char * V_54 )
{
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_3 * V_4 = ( void * ) V_8 -> V_19 -> V_20 ;
F_8 ( & V_4 -> V_12 ) ;
if ( V_6 -> V_17 & ( V_25 |
V_48 |
V_49 |
V_50 ) )
return - V_55 ;
V_4 -> V_8 [ V_6 -> V_40 - 1 ] = NULL ;
F_19 ( V_8 ) ;
V_8 -> V_56 ( V_8 ) ;
return 0 ;
}
static void F_21 ( struct V_26 * V_26 , struct V_7 * V_8 ,
unsigned V_57 )
{
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
int V_11 ;
V_6 -> V_17 |= V_57 | V_41 ;
V_11 = F_4 ( V_8 , V_8 -> V_19 -> V_20 ) ;
if ( V_11 ) {
F_7 ( V_6 ) ;
}
}
static bool F_22 ( struct V_58 * V_59 , struct V_7 * V_8 )
{
T_1 V_60 = V_59 -> V_60 ;
switch ( V_60 ) {
case V_61 :
V_8 -> V_23 = V_62 << 16 ;
break;
case V_63 :
V_8 -> V_23 = V_64 << 16 ;
break;
case V_65 :
V_8 -> V_23 = V_66 << 16 ;
break;
default:
F_10 ( V_8 , L_18 , V_60 ) ;
V_8 -> V_23 = V_67 << 16 ;
break;
}
return V_60 == V_63 ;
}
static void F_23 ( struct V_26 * V_26 )
{
struct V_68 * V_68 = V_26 -> V_28 ;
struct V_69 * V_70 = V_26 -> V_71 ;
struct V_3 * V_4 = (struct V_3 * ) V_70 -> V_20 ;
struct V_26 * V_52 = NULL ;
struct V_26 * V_53 = NULL ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
unsigned long V_9 ;
unsigned int V_72 ;
int V_37 = V_26 -> V_37 ;
bool V_73 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_4 -> V_13 )
goto V_14;
if ( V_37 ) {
if ( V_37 != - V_74 && V_37 != - V_75 && V_37 != - V_76 )
F_24 ( & V_26 -> V_77 -> V_77 , L_19 , V_37 ) ;
goto V_14;
}
V_72 = F_14 ( & V_68 -> V_78 ) - 1 ;
if ( V_72 >= V_79 || ! V_4 -> V_8 [ V_72 ] ) {
F_24 ( & V_26 -> V_77 -> V_77 ,
L_20 , V_72 + 1 ) ;
goto V_14;
}
V_8 = V_4 -> V_8 [ V_72 ] ;
V_6 = ( void * ) & V_8 -> V_16 ;
if ( ! ( V_6 -> V_17 & V_25 ) ) {
F_10 ( V_8 , L_21 , 0 ) ;
goto V_14;
}
switch ( V_68 -> V_80 ) {
case V_81 :
F_13 ( V_26 , V_8 ) ;
if ( V_8 -> V_23 != 0 ) {
V_52 = F_25 ( V_6 -> V_52 ) ;
V_53 = F_25 ( V_6 -> V_53 ) ;
}
V_6 -> V_17 &= ~ V_25 ;
F_11 ( V_8 , V_24 ) ;
break;
case V_82 :
if ( ! V_6 -> V_52 ||
( V_6 -> V_17 & V_48 ) ) {
F_10 ( V_8 , L_22 , 0 ) ;
break;
}
F_21 ( V_26 , V_8 , V_43 ) ;
break;
case V_83 :
if ( ! V_6 -> V_53 ||
( V_6 -> V_17 & V_49 ) ) {
F_10 ( V_8 , L_23 , 0 ) ;
break;
}
F_21 ( V_26 , V_8 , V_45 ) ;
break;
case V_84 :
V_6 -> V_17 &= ~ V_25 ;
V_73 = F_22 ( (struct V_58 * ) V_68 , V_8 ) ;
if ( ! V_73 ) {
V_52 = F_25 ( V_6 -> V_52 ) ;
V_53 = F_25 ( V_6 -> V_53 ) ;
}
F_11 ( V_8 , V_24 ) ;
break;
default:
F_10 ( V_8 , L_24 , V_68 -> V_80 ) ;
}
V_14:
F_20 ( V_26 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
if ( V_52 ) {
F_26 ( V_52 ) ;
F_27 ( V_52 ) ;
}
if ( V_53 ) {
F_26 ( V_53 ) ;
F_27 ( V_53 ) ;
}
}
static void F_28 ( struct V_26 * V_26 )
{
struct V_7 * V_8 = V_26 -> V_71 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_3 * V_4 = ( void * ) V_8 -> V_19 -> V_20 ;
struct V_85 * V_86 = NULL ;
unsigned long V_9 ;
int V_37 = V_26 -> V_37 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_6 -> V_52 == V_26 ) {
V_86 = F_29 ( V_8 ) ;
V_6 -> V_17 &= ~ V_48 ;
V_6 -> V_52 = NULL ;
} else if ( V_6 -> V_53 == V_26 ) {
V_86 = F_30 ( V_8 ) ;
V_6 -> V_17 &= ~ V_49 ;
V_6 -> V_53 = NULL ;
}
if ( V_86 == NULL ) {
F_31 ( 1 ) ;
goto V_14;
}
if ( V_4 -> V_13 )
goto V_14;
if ( V_6 -> V_17 & V_47 ) {
F_10 ( V_8 , L_25 , 0 ) ;
goto V_14;
}
if ( V_37 ) {
if ( V_37 != - V_74 && V_37 != - V_75 && V_37 != - V_76 )
F_10 ( V_8 , L_26 , V_37 ) ;
V_86 -> V_87 = V_86 -> V_88 ;
} else {
V_86 -> V_87 = V_86 -> V_88 - V_26 -> V_31 ;
}
F_11 ( V_8 , V_24 ) ;
V_14:
F_20 ( V_26 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
}
static void F_32 ( struct V_26 * V_26 )
{
if ( V_26 -> V_37 )
F_24 ( & V_26 -> V_77 -> V_77 , L_27 , V_26 -> V_37 ) ;
F_20 ( V_26 ) ;
}
static struct V_26 * F_33 ( struct V_3 * V_4 , T_2 V_89 ,
struct V_7 * V_8 ,
enum V_90 V_91 )
{
struct V_92 * V_93 = V_4 -> V_93 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_26 * V_26 = F_34 ( 0 , V_89 ) ;
struct V_85 * V_86 = ( V_91 == V_94 )
? F_29 ( V_8 ) : F_30 ( V_8 ) ;
unsigned int V_95 = ( V_91 == V_94 )
? V_4 -> V_96 : V_4 -> V_97 ;
if ( ! V_26 )
goto V_14;
F_35 ( V_26 , V_93 , V_95 , NULL , V_86 -> V_88 ,
F_28 , V_8 ) ;
if ( V_4 -> V_98 )
V_26 -> V_99 = V_6 -> V_40 ;
V_26 -> V_100 = V_93 -> V_101 -> V_102 ? V_86 -> V_103 . V_104 : 0 ;
V_26 -> V_105 = V_86 -> V_103 . V_106 ;
V_14:
return V_26 ;
}
static struct V_26 * F_36 ( struct V_3 * V_4 , T_2 V_89 ,
struct V_7 * V_8 )
{
struct V_92 * V_93 = V_4 -> V_93 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_26 * V_26 = F_34 ( 0 , V_89 ) ;
struct V_27 * V_68 ;
if ( ! V_26 )
goto V_14;
V_68 = F_37 ( sizeof( * V_68 ) , V_89 ) ;
if ( ! V_68 )
goto free;
F_35 ( V_26 , V_93 , V_4 -> V_107 , V_68 , sizeof( * V_68 ) ,
F_23 , V_8 -> V_19 -> V_108 ) ;
if ( V_4 -> V_98 )
V_26 -> V_99 = V_6 -> V_40 ;
V_26 -> V_109 |= V_110 ;
V_14:
return V_26 ;
free:
F_20 ( V_26 ) ;
return NULL ;
}
static struct V_26 * F_38 ( struct V_3 * V_4 , T_2 V_89 ,
struct V_7 * V_8 )
{
struct V_92 * V_93 = V_4 -> V_93 ;
struct V_29 * V_30 = V_8 -> V_19 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_26 * V_26 = F_34 ( 0 , V_89 ) ;
struct V_111 * V_68 ;
int V_32 ;
if ( ! V_26 )
goto V_14;
V_32 = V_8 -> V_112 - 16 ;
if ( V_32 < 0 )
V_32 = 0 ;
V_32 = F_39 ( V_32 , 4 ) ;
V_68 = F_37 ( sizeof( * V_68 ) + V_32 , V_89 ) ;
if ( ! V_68 )
goto free;
V_68 -> V_80 = V_113 ;
V_68 -> V_78 = F_40 ( V_6 -> V_40 ) ;
V_68 -> V_114 = V_115 ;
V_68 -> V_32 = V_32 ;
F_41 ( V_30 -> V_116 , & V_68 -> V_116 ) ;
memcpy ( V_68 -> V_117 , V_8 -> V_8 , V_8 -> V_112 ) ;
F_35 ( V_26 , V_93 , V_4 -> V_118 , V_68 , sizeof( * V_68 ) + V_32 ,
F_32 , NULL ) ;
V_26 -> V_109 |= V_110 ;
V_14:
return V_26 ;
free:
F_20 ( V_26 ) ;
return NULL ;
}
static struct V_26 * F_42 ( struct V_7 * V_8 , T_2 V_89 )
{
struct V_3 * V_4 = V_8 -> V_19 -> V_20 ;
struct V_26 * V_26 ;
int V_11 ;
V_26 = F_36 ( V_4 , V_89 , V_8 ) ;
if ( ! V_26 )
return NULL ;
F_43 ( V_26 , & V_4 -> V_119 ) ;
V_11 = F_44 ( V_26 , V_89 ) ;
if ( V_11 ) {
F_45 ( V_26 ) ;
F_10 ( V_8 , L_28 , V_11 ) ;
F_20 ( V_26 ) ;
return NULL ;
}
return V_26 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_26 * V_26 ;
int V_11 ;
F_8 ( & V_4 -> V_12 ) ;
if ( V_6 -> V_17 & V_41 ) {
V_26 = F_42 ( V_8 , V_120 ) ;
if ( ! V_26 )
return V_121 ;
V_6 -> V_17 &= ~ V_41 ;
}
if ( V_6 -> V_17 & V_42 ) {
V_6 -> V_52 = F_33 ( V_4 , V_120 ,
V_8 , V_94 ) ;
if ( ! V_6 -> V_52 )
return V_121 ;
V_6 -> V_17 &= ~ V_42 ;
}
if ( V_6 -> V_17 & V_43 ) {
F_43 ( V_6 -> V_52 , & V_4 -> V_122 ) ;
V_11 = F_44 ( V_6 -> V_52 , V_120 ) ;
if ( V_11 ) {
F_45 ( V_6 -> V_52 ) ;
F_10 ( V_8 , L_29 , V_11 ) ;
return V_121 ;
}
V_6 -> V_17 &= ~ V_43 ;
V_6 -> V_17 |= V_48 ;
}
if ( V_6 -> V_17 & V_44 ) {
V_6 -> V_53 = F_33 ( V_4 , V_120 ,
V_8 , V_123 ) ;
if ( ! V_6 -> V_53 )
return V_121 ;
V_6 -> V_17 &= ~ V_44 ;
}
if ( V_6 -> V_17 & V_45 ) {
F_43 ( V_6 -> V_53 , & V_4 -> V_122 ) ;
V_11 = F_44 ( V_6 -> V_53 , V_120 ) ;
if ( V_11 ) {
F_45 ( V_6 -> V_53 ) ;
F_10 ( V_8 , L_30 , V_11 ) ;
return V_121 ;
}
V_6 -> V_17 &= ~ V_45 ;
V_6 -> V_17 |= V_49 ;
}
if ( V_6 -> V_17 & V_46 ) {
V_6 -> V_51 = F_38 ( V_4 , V_120 , V_8 ) ;
if ( ! V_6 -> V_51 )
return V_121 ;
V_6 -> V_17 &= ~ V_46 ;
}
if ( V_6 -> V_17 & V_47 ) {
F_43 ( V_6 -> V_51 , & V_4 -> V_124 ) ;
V_11 = F_44 ( V_6 -> V_51 , V_120 ) ;
if ( V_11 ) {
F_45 ( V_6 -> V_51 ) ;
F_10 ( V_8 , L_31 , V_11 ) ;
return V_121 ;
}
V_6 -> V_51 = NULL ;
V_6 -> V_17 &= ~ V_47 ;
V_6 -> V_17 |= V_25 ;
}
return 0 ;
}
static int F_46 ( struct V_7 * V_8 ,
void (* F_47)( struct V_7 * ) )
{
struct V_29 * V_30 = V_8 -> V_19 ;
struct V_3 * V_4 = V_30 -> V_20 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
unsigned long V_9 ;
int V_72 , V_11 ;
F_48 ( sizeof( struct V_5 ) > sizeof( struct V_21 ) ) ;
if ( V_8 -> V_19 -> V_108 -> V_125 )
return V_121 ;
if ( ( V_4 -> V_9 & V_126 ) &&
( V_8 -> V_8 [ 0 ] == V_127 || V_8 -> V_8 [ 0 ] == V_128 ) ) {
memcpy ( V_8 -> V_35 , V_129 ,
sizeof( V_129 ) ) ;
V_8 -> V_23 = V_130 ;
V_8 -> V_56 ( V_8 ) ;
return 0 ;
}
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_4 -> V_13 ) {
V_8 -> V_23 = V_67 << 16 ;
V_8 -> V_56 ( V_8 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
return 0 ;
}
for ( V_72 = 0 ; V_72 < V_4 -> V_15 ; V_72 ++ ) {
if ( ! V_4 -> V_8 [ V_72 ] )
break;
}
if ( V_72 == V_4 -> V_15 ) {
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_121 ;
}
V_8 -> V_56 = F_47 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_40 = V_72 + 1 ;
V_6 -> V_17 = V_41 | V_46 | V_47 ;
switch ( V_8 -> V_131 ) {
case V_94 :
V_6 -> V_17 |= V_42 | V_43 ;
break;
case V_132 :
V_6 -> V_17 |= V_42 | V_43 ;
case V_123 :
V_6 -> V_17 |= V_44 | V_45 ;
case V_133 :
break;
}
if ( ! V_4 -> V_98 )
V_6 -> V_17 &= ~ ( V_43 | V_45 ) ;
V_11 = F_4 ( V_8 , V_4 ) ;
if ( V_11 ) {
if ( V_6 -> V_17 & V_41 ) {
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_121 ;
}
F_7 ( V_6 ) ;
}
V_4 -> V_8 [ V_72 ] = V_8 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
return 0 ;
}
int F_49 ( struct V_7 * V_8 )
{
struct V_29 * V_30 = V_8 -> V_19 ;
struct V_3 * V_4 = V_30 -> V_20 ;
struct V_92 * V_93 = V_4 -> V_93 ;
unsigned long V_9 ;
int V_11 ;
V_11 = F_50 ( V_93 , V_4 -> V_134 ) ;
if ( V_11 ) {
F_51 ( V_135 , V_30 -> V_108 ,
L_32 , V_24 , V_11 ) ;
return V_136 ;
}
F_51 ( V_34 , V_30 -> V_108 , L_33 , V_24 ) ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 1 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_52 ( & V_4 -> V_124 ) ;
F_52 ( & V_4 -> V_119 ) ;
F_52 ( & V_4 -> V_122 ) ;
F_9 ( V_4 , V_137 ) ;
V_11 = F_53 ( V_93 ) ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 0 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_54 ( V_93 ) ;
if ( V_11 ) {
F_51 ( V_34 , V_30 -> V_108 , L_34 ,
V_24 , V_11 ) ;
return V_136 ;
}
F_51 ( V_34 , V_30 -> V_108 , L_35 , V_24 ) ;
return V_138 ;
}
static int F_55 ( struct V_139 * V_140 )
{
struct V_3 * V_4 = (struct V_3 * )
F_56 ( V_140 -> V_77 . V_141 ) -> V_20 ;
if ( V_4 -> V_9 & V_142 )
V_140 -> V_143 = 1 ;
return 0 ;
}
static int F_57 ( struct V_29 * V_30 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_30 -> V_108 -> V_20 ;
V_30 -> V_20 = V_4 ;
F_58 ( V_30 -> V_144 , ( 512 - 1 ) ) ;
if ( V_4 -> V_9 & V_145 )
F_59 ( V_30 -> V_144 , 64 ) ;
else if ( V_4 -> V_9 & V_146 )
F_59 ( V_30 -> V_144 , 240 ) ;
return 0 ;
}
static int F_60 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_20 ;
if ( V_4 -> V_9 & V_147 )
V_30 -> V_148 = 1 ;
if ( V_4 -> V_9 & V_149 )
V_30 -> V_150 = 1 ;
F_61 ( V_30 , V_4 -> V_15 - 2 ) ;
return 0 ;
}
static int F_62 ( struct V_92 * V_93 ,
struct V_151 * V_134 )
{
struct V_152 * V_153 ;
V_153 = F_63 ( V_134 ) ;
if ( ! V_153 )
return - V_154 ;
return F_64 ( V_93 , V_153 -> V_155 . V_156 ,
V_153 -> V_155 . V_157 ) ;
}
static int F_65 ( struct V_3 * V_4 )
{
struct V_158 * V_159 [ 4 ] = { } ;
struct V_92 * V_93 = V_4 -> V_93 ;
int V_160 ;
V_160 = F_66 ( V_4 -> V_134 -> V_161 , V_159 ) ;
if ( V_160 )
return V_160 ;
V_4 -> V_118 = F_67 ( V_93 ,
F_68 ( & V_159 [ 0 ] -> V_155 ) ) ;
V_4 -> V_107 = F_69 ( V_93 ,
F_68 ( & V_159 [ 1 ] -> V_155 ) ) ;
V_4 -> V_96 = F_69 ( V_93 ,
F_68 ( & V_159 [ 2 ] -> V_155 ) ) ;
V_4 -> V_97 = F_67 ( V_93 ,
F_68 ( & V_159 [ 3 ] -> V_155 ) ) ;
if ( V_93 -> V_162 < V_163 ) {
V_4 -> V_15 = 32 ;
V_4 -> V_98 = 0 ;
} else {
V_4 -> V_15 = F_70 ( V_4 -> V_134 , V_159 + 1 ,
3 , V_79 , V_164 ) ;
if ( V_4 -> V_15 < 0 )
return V_4 -> V_15 ;
V_4 -> V_98 = 1 ;
}
return 0 ;
}
static void F_71 ( struct V_3 * V_4 )
{
struct V_92 * V_93 = V_4 -> V_93 ;
struct V_158 * V_159 [ 3 ] ;
V_159 [ 0 ] = F_72 ( V_93 , V_4 -> V_107 ) ;
V_159 [ 1 ] = F_72 ( V_93 , V_4 -> V_96 ) ;
V_159 [ 2 ] = F_72 ( V_93 , V_4 -> V_97 ) ;
F_73 ( V_4 -> V_134 , V_159 , 3 , V_164 ) ;
}
static int F_74 ( struct V_151 * V_134 , const struct V_165 * V_166 )
{
int V_23 = - V_167 ;
struct V_69 * V_70 = NULL ;
struct V_3 * V_4 ;
struct V_92 * V_93 = F_75 ( V_134 ) ;
unsigned long V_168 ;
if ( ! F_76 ( V_134 , V_166 , & V_168 ) )
return - V_154 ;
if ( F_62 ( V_93 , V_134 ) )
return - V_154 ;
V_70 = F_77 ( & V_169 ,
sizeof( struct V_3 ) ) ;
if ( ! V_70 )
goto V_170;
V_70 -> V_171 = 16 + 252 ;
V_70 -> V_172 = 1 ;
V_70 -> V_173 = 256 ;
V_70 -> V_174 = 0 ;
V_70 -> V_102 = V_93 -> V_101 -> V_102 ;
V_4 = (struct V_3 * ) V_70 -> V_20 ;
V_4 -> V_134 = V_134 ;
V_4 -> V_93 = V_93 ;
V_4 -> V_13 = 0 ;
V_4 -> V_175 = 0 ;
V_4 -> V_9 = V_168 ;
F_78 ( & V_4 -> V_124 ) ;
F_78 ( & V_4 -> V_119 ) ;
F_78 ( & V_4 -> V_122 ) ;
F_79 ( & V_4 -> V_12 ) ;
F_80 ( & V_4 -> V_2 , F_1 ) ;
V_23 = F_65 ( V_4 ) ;
if ( V_23 )
goto V_170;
V_70 -> V_176 = V_4 -> V_15 - 2 ;
F_81 ( V_134 , V_70 ) ;
V_23 = F_82 ( V_70 , & V_134 -> V_77 ) ;
if ( V_23 )
goto V_177;
F_83 ( V_70 ) ;
return V_23 ;
V_177:
F_71 ( V_4 ) ;
F_81 ( V_134 , NULL ) ;
V_170:
F_64 ( V_93 , V_134 -> V_178 [ 0 ] . V_155 . V_156 , 0 ) ;
if ( V_70 )
F_84 ( V_70 ) ;
return V_23 ;
}
static int F_85 ( struct V_3 * V_4 )
{
unsigned long V_9 ;
int V_10 , V_160 = 1 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 ; V_10 ++ ) {
if ( V_4 -> V_8 [ V_10 ] ) {
V_160 = 0 ;
break;
}
}
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_160 ;
}
static int F_86 ( struct V_3 * V_4 )
{
unsigned long V_179 ;
int V_160 ;
V_179 = V_180 ;
do {
F_87 ( & V_4 -> V_2 ) ;
V_160 = F_88 ( & V_4 -> V_119 , 5000 ) ;
if ( V_160 == 0 )
return - V_181 ;
V_160 = F_88 ( & V_4 -> V_122 , 500 ) ;
if ( V_160 == 0 )
return - V_181 ;
if ( F_89 ( V_180 , V_179 + 5 * V_182 ) )
return - V_181 ;
} while ( ! F_85 ( V_4 ) );
return 0 ;
}
static int F_90 ( struct V_151 * V_134 )
{
struct V_69 * V_70 = F_91 ( V_134 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_70 -> V_20 ;
unsigned long V_9 ;
if ( V_4 -> V_175 )
return 0 ;
F_3 ( V_70 -> V_183 , V_9 ) ;
F_92 ( V_70 ) ;
F_6 ( V_70 -> V_183 , V_9 ) ;
if ( F_86 ( V_4 ) != 0 ) {
F_51 ( V_135 , V_70 , L_36 , V_24 ) ;
F_93 ( V_70 ) ;
return 1 ;
}
F_71 ( V_4 ) ;
return 0 ;
}
static int F_94 ( struct V_151 * V_134 )
{
struct V_69 * V_70 = F_91 ( V_134 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_70 -> V_20 ;
unsigned long V_9 ;
int V_11 ;
if ( V_4 -> V_175 )
return 0 ;
V_11 = F_65 ( V_4 ) ;
if ( V_11 ) {
F_51 ( V_135 , V_70 ,
L_37 ,
V_24 , V_11 ) ;
return 1 ;
}
F_3 ( V_70 -> V_183 , V_9 ) ;
F_95 ( V_70 , 0 ) ;
F_6 ( V_70 -> V_183 , V_9 ) ;
F_93 ( V_70 ) ;
return 0 ;
}
static int F_96 ( struct V_151 * V_134 , T_3 V_184 )
{
struct V_69 * V_70 = F_91 ( V_134 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_70 -> V_20 ;
if ( F_86 ( V_4 ) != 0 ) {
F_51 ( V_135 , V_70 , L_36 , V_24 ) ;
return - V_181 ;
}
return 0 ;
}
static int F_97 ( struct V_151 * V_134 )
{
return 0 ;
}
static int F_98 ( struct V_151 * V_134 )
{
struct V_69 * V_70 = F_91 ( V_134 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_70 -> V_20 ;
unsigned long V_9 ;
int V_11 ;
V_11 = F_65 ( V_4 ) ;
if ( V_11 ) {
F_51 ( V_135 , V_70 ,
L_37 ,
V_24 , V_11 ) ;
return - V_185 ;
}
F_3 ( V_70 -> V_183 , V_9 ) ;
F_95 ( V_70 , 0 ) ;
F_6 ( V_70 -> V_183 , V_9 ) ;
return 0 ;
}
static void F_99 ( struct V_151 * V_134 )
{
struct V_69 * V_70 = F_91 ( V_134 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_70 -> V_20 ;
unsigned long V_9 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 1 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_100 ( & V_4 -> V_2 ) ;
F_52 ( & V_4 -> V_124 ) ;
F_52 ( & V_4 -> V_119 ) ;
F_52 ( & V_4 -> V_122 ) ;
F_9 ( V_4 , V_186 ) ;
F_101 ( V_70 ) ;
F_71 ( V_4 ) ;
F_84 ( V_70 ) ;
}
static void F_102 ( struct V_19 * V_77 )
{
struct V_151 * V_134 = F_103 ( V_77 ) ;
struct V_92 * V_93 = F_75 ( V_134 ) ;
struct V_69 * V_70 = F_91 ( V_134 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_70 -> V_20 ;
if ( V_187 != V_188 )
return;
V_4 -> V_175 = 1 ;
F_71 ( V_4 ) ;
F_64 ( V_93 , V_134 -> V_178 [ 0 ] . V_155 . V_156 , 0 ) ;
F_53 ( V_93 ) ;
}

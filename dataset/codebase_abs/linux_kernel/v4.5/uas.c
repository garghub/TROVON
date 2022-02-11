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
static void F_22 ( struct V_26 * V_26 )
{
struct V_58 * V_58 = V_26 -> V_28 ;
struct V_59 * V_60 = V_26 -> V_61 ;
struct V_3 * V_4 = (struct V_3 * ) V_60 -> V_20 ;
struct V_26 * V_52 = NULL ;
struct V_26 * V_53 = NULL ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
unsigned long V_9 ;
unsigned int V_62 ;
int V_37 = V_26 -> V_37 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_4 -> V_13 )
goto V_14;
if ( V_37 ) {
if ( V_37 != - V_63 && V_37 != - V_64 && V_37 != - V_65 )
F_23 ( & V_26 -> V_66 -> V_66 , L_18 , V_37 ) ;
goto V_14;
}
V_62 = F_14 ( & V_58 -> V_67 ) - 1 ;
if ( V_62 >= V_68 || ! V_4 -> V_8 [ V_62 ] ) {
F_23 ( & V_26 -> V_66 -> V_66 ,
L_19 , V_62 + 1 ) ;
goto V_14;
}
V_8 = V_4 -> V_8 [ V_62 ] ;
V_6 = ( void * ) & V_8 -> V_16 ;
if ( ! ( V_6 -> V_17 & V_25 ) ) {
F_10 ( V_8 , L_20 , 0 ) ;
goto V_14;
}
switch ( V_58 -> V_69 ) {
case V_70 :
F_13 ( V_26 , V_8 ) ;
if ( V_8 -> V_23 != 0 ) {
V_52 = F_24 ( V_6 -> V_52 ) ;
V_53 = F_24 ( V_6 -> V_53 ) ;
}
V_6 -> V_17 &= ~ V_25 ;
F_11 ( V_8 , V_24 ) ;
break;
case V_71 :
if ( ! V_6 -> V_52 ||
( V_6 -> V_17 & V_48 ) ) {
F_10 ( V_8 , L_21 , 0 ) ;
break;
}
F_21 ( V_26 , V_8 , V_43 ) ;
break;
case V_72 :
if ( ! V_6 -> V_53 ||
( V_6 -> V_17 & V_49 ) ) {
F_10 ( V_8 , L_22 , 0 ) ;
break;
}
F_21 ( V_26 , V_8 , V_45 ) ;
break;
case V_73 :
F_10 ( V_8 , L_23 ,
( (struct V_74 * ) V_58 ) -> V_75 ) ;
V_52 = F_24 ( V_6 -> V_52 ) ;
V_53 = F_24 ( V_6 -> V_53 ) ;
V_6 -> V_17 &= ~ V_25 ;
V_8 -> V_23 = V_76 << 16 ;
F_11 ( V_8 , V_24 ) ;
break;
default:
F_10 ( V_8 , L_24 , V_58 -> V_69 ) ;
}
V_14:
F_20 ( V_26 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
if ( V_52 ) {
F_25 ( V_52 ) ;
F_26 ( V_52 ) ;
}
if ( V_53 ) {
F_25 ( V_53 ) ;
F_26 ( V_53 ) ;
}
}
static void F_27 ( struct V_26 * V_26 )
{
struct V_7 * V_8 = V_26 -> V_61 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_3 * V_4 = ( void * ) V_8 -> V_19 -> V_20 ;
struct V_77 * V_78 = NULL ;
unsigned long V_9 ;
int V_37 = V_26 -> V_37 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_6 -> V_52 == V_26 ) {
V_78 = F_28 ( V_8 ) ;
V_6 -> V_17 &= ~ V_48 ;
V_6 -> V_52 = NULL ;
} else if ( V_6 -> V_53 == V_26 ) {
V_78 = F_29 ( V_8 ) ;
V_6 -> V_17 &= ~ V_49 ;
V_6 -> V_53 = NULL ;
}
if ( V_78 == NULL ) {
F_30 ( 1 ) ;
goto V_14;
}
if ( V_4 -> V_13 )
goto V_14;
if ( V_6 -> V_17 & V_47 ) {
F_10 ( V_8 , L_25 , 0 ) ;
goto V_14;
}
if ( V_37 ) {
if ( V_37 != - V_63 && V_37 != - V_64 && V_37 != - V_65 )
F_10 ( V_8 , L_26 , V_37 ) ;
V_78 -> V_79 = V_78 -> V_80 ;
} else {
V_78 -> V_79 = V_78 -> V_80 - V_26 -> V_31 ;
}
F_11 ( V_8 , V_24 ) ;
V_14:
F_20 ( V_26 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
}
static void F_31 ( struct V_26 * V_26 )
{
if ( V_26 -> V_37 )
F_23 ( & V_26 -> V_66 -> V_66 , L_27 , V_26 -> V_37 ) ;
F_20 ( V_26 ) ;
}
static struct V_26 * F_32 ( struct V_3 * V_4 , T_1 V_81 ,
struct V_7 * V_8 ,
enum V_82 V_83 )
{
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_26 * V_26 = F_33 ( 0 , V_81 ) ;
struct V_77 * V_78 = ( V_83 == V_86 )
? F_28 ( V_8 ) : F_29 ( V_8 ) ;
unsigned int V_87 = ( V_83 == V_86 )
? V_4 -> V_88 : V_4 -> V_89 ;
if ( ! V_26 )
goto V_14;
F_34 ( V_26 , V_85 , V_87 , NULL , V_78 -> V_80 ,
F_27 , V_8 ) ;
if ( V_4 -> V_90 )
V_26 -> V_91 = V_6 -> V_40 ;
V_26 -> V_92 = V_85 -> V_93 -> V_94 ? V_78 -> V_95 . V_96 : 0 ;
V_26 -> V_97 = V_78 -> V_95 . V_98 ;
V_14:
return V_26 ;
}
static struct V_26 * F_35 ( struct V_3 * V_4 , T_1 V_81 ,
struct V_7 * V_8 )
{
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_26 * V_26 = F_33 ( 0 , V_81 ) ;
struct V_27 * V_58 ;
if ( ! V_26 )
goto V_14;
V_58 = F_36 ( sizeof( * V_58 ) , V_81 ) ;
if ( ! V_58 )
goto free;
F_34 ( V_26 , V_85 , V_4 -> V_99 , V_58 , sizeof( * V_58 ) ,
F_22 , V_8 -> V_19 -> V_100 ) ;
if ( V_4 -> V_90 )
V_26 -> V_91 = V_6 -> V_40 ;
V_26 -> V_101 |= V_102 ;
V_14:
return V_26 ;
free:
F_20 ( V_26 ) ;
return NULL ;
}
static struct V_26 * F_37 ( struct V_3 * V_4 , T_1 V_81 ,
struct V_7 * V_8 )
{
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_29 * V_30 = V_8 -> V_19 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_26 * V_26 = F_33 ( 0 , V_81 ) ;
struct V_103 * V_58 ;
int V_32 ;
if ( ! V_26 )
goto V_14;
V_32 = V_8 -> V_104 - 16 ;
if ( V_32 < 0 )
V_32 = 0 ;
V_32 = F_38 ( V_32 , 4 ) ;
V_58 = F_36 ( sizeof( * V_58 ) + V_32 , V_81 ) ;
if ( ! V_58 )
goto free;
V_58 -> V_69 = V_105 ;
V_58 -> V_67 = F_39 ( V_6 -> V_40 ) ;
V_58 -> V_106 = V_107 ;
V_58 -> V_32 = V_32 ;
F_40 ( V_30 -> V_108 , & V_58 -> V_108 ) ;
memcpy ( V_58 -> V_109 , V_8 -> V_8 , V_8 -> V_104 ) ;
F_34 ( V_26 , V_85 , V_4 -> V_110 , V_58 , sizeof( * V_58 ) + V_32 ,
F_31 , NULL ) ;
V_26 -> V_101 |= V_102 ;
V_14:
return V_26 ;
free:
F_20 ( V_26 ) ;
return NULL ;
}
static struct V_26 * F_41 ( struct V_7 * V_8 , T_1 V_81 )
{
struct V_3 * V_4 = V_8 -> V_19 -> V_20 ;
struct V_26 * V_26 ;
int V_11 ;
V_26 = F_35 ( V_4 , V_81 , V_8 ) ;
if ( ! V_26 )
return NULL ;
F_42 ( V_26 , & V_4 -> V_111 ) ;
V_11 = F_43 ( V_26 , V_81 ) ;
if ( V_11 ) {
F_44 ( V_26 ) ;
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
V_26 = F_41 ( V_8 , V_112 ) ;
if ( ! V_26 )
return V_113 ;
V_6 -> V_17 &= ~ V_41 ;
}
if ( V_6 -> V_17 & V_42 ) {
V_6 -> V_52 = F_32 ( V_4 , V_112 ,
V_8 , V_86 ) ;
if ( ! V_6 -> V_52 )
return V_113 ;
V_6 -> V_17 &= ~ V_42 ;
}
if ( V_6 -> V_17 & V_43 ) {
F_42 ( V_6 -> V_52 , & V_4 -> V_114 ) ;
V_11 = F_43 ( V_6 -> V_52 , V_112 ) ;
if ( V_11 ) {
F_44 ( V_6 -> V_52 ) ;
F_10 ( V_8 , L_29 , V_11 ) ;
return V_113 ;
}
V_6 -> V_17 &= ~ V_43 ;
V_6 -> V_17 |= V_48 ;
}
if ( V_6 -> V_17 & V_44 ) {
V_6 -> V_53 = F_32 ( V_4 , V_112 ,
V_8 , V_115 ) ;
if ( ! V_6 -> V_53 )
return V_113 ;
V_6 -> V_17 &= ~ V_44 ;
}
if ( V_6 -> V_17 & V_45 ) {
F_42 ( V_6 -> V_53 , & V_4 -> V_114 ) ;
V_11 = F_43 ( V_6 -> V_53 , V_112 ) ;
if ( V_11 ) {
F_44 ( V_6 -> V_53 ) ;
F_10 ( V_8 , L_30 , V_11 ) ;
return V_113 ;
}
V_6 -> V_17 &= ~ V_45 ;
V_6 -> V_17 |= V_49 ;
}
if ( V_6 -> V_17 & V_46 ) {
V_6 -> V_51 = F_37 ( V_4 , V_112 , V_8 ) ;
if ( ! V_6 -> V_51 )
return V_113 ;
V_6 -> V_17 &= ~ V_46 ;
}
if ( V_6 -> V_17 & V_47 ) {
F_42 ( V_6 -> V_51 , & V_4 -> V_116 ) ;
V_11 = F_43 ( V_6 -> V_51 , V_112 ) ;
if ( V_11 ) {
F_44 ( V_6 -> V_51 ) ;
F_10 ( V_8 , L_31 , V_11 ) ;
return V_113 ;
}
V_6 -> V_51 = NULL ;
V_6 -> V_17 &= ~ V_47 ;
V_6 -> V_17 |= V_25 ;
}
return 0 ;
}
static int F_45 ( struct V_7 * V_8 ,
void (* F_46)( struct V_7 * ) )
{
struct V_29 * V_30 = V_8 -> V_19 ;
struct V_3 * V_4 = V_30 -> V_20 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
unsigned long V_9 ;
int V_62 , V_11 ;
F_47 ( sizeof( struct V_5 ) > sizeof( struct V_21 ) ) ;
if ( V_8 -> V_19 -> V_100 -> V_117 )
return V_113 ;
if ( ( V_4 -> V_9 & V_118 ) &&
( V_8 -> V_8 [ 0 ] == V_119 || V_8 -> V_8 [ 0 ] == V_120 ) ) {
memcpy ( V_8 -> V_35 , V_121 ,
sizeof( V_121 ) ) ;
V_8 -> V_23 = V_122 ;
V_8 -> V_56 ( V_8 ) ;
return 0 ;
}
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_4 -> V_13 ) {
V_8 -> V_23 = V_76 << 16 ;
V_8 -> V_56 ( V_8 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
return 0 ;
}
for ( V_62 = 0 ; V_62 < V_4 -> V_15 ; V_62 ++ ) {
if ( ! V_4 -> V_8 [ V_62 ] )
break;
}
if ( V_62 == V_4 -> V_15 ) {
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_113 ;
}
V_8 -> V_56 = F_46 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_40 = V_62 + 1 ;
V_6 -> V_17 = V_41 | V_46 | V_47 ;
switch ( V_8 -> V_123 ) {
case V_86 :
V_6 -> V_17 |= V_42 | V_43 ;
break;
case V_124 :
V_6 -> V_17 |= V_42 | V_43 ;
case V_115 :
V_6 -> V_17 |= V_44 | V_45 ;
case V_125 :
break;
}
if ( ! V_4 -> V_90 )
V_6 -> V_17 &= ~ ( V_43 | V_45 ) ;
V_11 = F_4 ( V_8 , V_4 ) ;
if ( V_11 ) {
if ( V_6 -> V_17 & V_41 ) {
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_113 ;
}
F_7 ( V_6 ) ;
}
V_4 -> V_8 [ V_62 ] = V_8 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
return 0 ;
}
int F_48 ( struct V_7 * V_8 )
{
struct V_29 * V_30 = V_8 -> V_19 ;
struct V_3 * V_4 = V_30 -> V_20 ;
struct V_84 * V_85 = V_4 -> V_85 ;
unsigned long V_9 ;
int V_11 ;
V_11 = F_49 ( V_85 , V_4 -> V_126 ) ;
if ( V_11 ) {
F_50 ( V_127 , V_30 -> V_100 ,
L_32 , V_24 , V_11 ) ;
return V_128 ;
}
F_50 ( V_34 , V_30 -> V_100 , L_33 , V_24 ) ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 1 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_51 ( & V_4 -> V_116 ) ;
F_51 ( & V_4 -> V_111 ) ;
F_51 ( & V_4 -> V_114 ) ;
F_9 ( V_4 , V_129 ) ;
V_11 = F_52 ( V_85 ) ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 0 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_53 ( V_85 ) ;
if ( V_11 ) {
F_50 ( V_34 , V_30 -> V_100 , L_34 ,
V_24 , V_11 ) ;
return V_128 ;
}
F_50 ( V_34 , V_30 -> V_100 , L_35 , V_24 ) ;
return V_130 ;
}
static int F_54 ( struct V_29 * V_30 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_30 -> V_100 -> V_20 ;
V_30 -> V_20 = V_4 ;
F_55 ( V_30 -> V_131 , ( 512 - 1 ) ) ;
if ( V_4 -> V_9 & V_132 )
F_56 ( V_30 -> V_131 , 64 ) ;
else if ( V_4 -> V_9 & V_133 )
F_56 ( V_30 -> V_131 , 240 ) ;
return 0 ;
}
static int F_57 ( struct V_29 * V_30 )
{
struct V_3 * V_4 = V_30 -> V_20 ;
if ( V_4 -> V_9 & V_134 )
V_30 -> V_135 = 1 ;
if ( V_4 -> V_9 & V_136 )
V_30 -> V_137 = 1 ;
F_58 ( V_30 , V_4 -> V_15 - 2 ) ;
return 0 ;
}
static int F_59 ( struct V_84 * V_85 ,
struct V_138 * V_126 )
{
int V_139 ;
V_139 = F_60 ( V_126 ) ;
if ( V_139 < 0 )
return V_139 ;
return F_61 ( V_85 ,
V_126 -> V_140 [ 0 ] . V_141 . V_142 , V_139 ) ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_143 * V_144 [ 4 ] = { } ;
struct V_84 * V_85 = V_4 -> V_85 ;
int V_145 ;
V_145 = F_63 ( V_4 -> V_126 -> V_146 , V_144 ) ;
if ( V_145 )
return V_145 ;
V_4 -> V_110 = F_64 ( V_85 ,
F_65 ( & V_144 [ 0 ] -> V_141 ) ) ;
V_4 -> V_99 = F_66 ( V_85 ,
F_65 ( & V_144 [ 1 ] -> V_141 ) ) ;
V_4 -> V_88 = F_66 ( V_85 ,
F_65 ( & V_144 [ 2 ] -> V_141 ) ) ;
V_4 -> V_89 = F_64 ( V_85 ,
F_65 ( & V_144 [ 3 ] -> V_141 ) ) ;
if ( V_85 -> V_147 < V_148 ) {
V_4 -> V_15 = 32 ;
V_4 -> V_90 = 0 ;
} else {
V_4 -> V_15 = F_67 ( V_4 -> V_126 , V_144 + 1 ,
3 , V_68 , V_149 ) ;
if ( V_4 -> V_15 < 0 )
return V_4 -> V_15 ;
V_4 -> V_90 = 1 ;
}
return 0 ;
}
static void F_68 ( struct V_3 * V_4 )
{
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_143 * V_144 [ 3 ] ;
V_144 [ 0 ] = F_69 ( V_85 , V_4 -> V_99 ) ;
V_144 [ 1 ] = F_69 ( V_85 , V_4 -> V_88 ) ;
V_144 [ 2 ] = F_69 ( V_85 , V_4 -> V_89 ) ;
F_70 ( V_4 -> V_126 , V_144 , 3 , V_149 ) ;
}
static int F_71 ( struct V_138 * V_126 , const struct V_150 * V_151 )
{
int V_23 = - V_152 ;
struct V_59 * V_60 = NULL ;
struct V_3 * V_4 ;
struct V_84 * V_85 = F_72 ( V_126 ) ;
unsigned long V_153 ;
if ( ! F_73 ( V_126 , V_151 , & V_153 ) )
return - V_154 ;
if ( F_59 ( V_85 , V_126 ) )
return - V_154 ;
V_60 = F_74 ( & V_155 ,
sizeof( struct V_3 ) ) ;
if ( ! V_60 )
goto V_156;
V_60 -> V_157 = 16 + 252 ;
V_60 -> V_158 = 1 ;
V_60 -> V_159 = 256 ;
V_60 -> V_160 = 0 ;
V_60 -> V_94 = V_85 -> V_93 -> V_94 ;
V_4 = (struct V_3 * ) V_60 -> V_20 ;
V_4 -> V_126 = V_126 ;
V_4 -> V_85 = V_85 ;
V_4 -> V_13 = 0 ;
V_4 -> V_161 = 0 ;
V_4 -> V_9 = V_153 ;
F_75 ( & V_4 -> V_116 ) ;
F_75 ( & V_4 -> V_111 ) ;
F_75 ( & V_4 -> V_114 ) ;
F_76 ( & V_4 -> V_12 ) ;
F_77 ( & V_4 -> V_2 , F_1 ) ;
V_23 = F_62 ( V_4 ) ;
if ( V_23 )
goto V_156;
F_78 ( V_126 , V_60 ) ;
V_23 = F_79 ( V_60 , & V_126 -> V_66 ) ;
if ( V_23 )
goto V_162;
F_80 ( V_60 ) ;
return V_23 ;
V_162:
F_68 ( V_4 ) ;
F_78 ( V_126 , NULL ) ;
V_156:
F_61 ( V_85 , V_126 -> V_140 [ 0 ] . V_141 . V_142 , 0 ) ;
if ( V_60 )
F_81 ( V_60 ) ;
return V_23 ;
}
static int F_82 ( struct V_3 * V_4 )
{
unsigned long V_9 ;
int V_10 , V_145 = 1 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 ; V_10 ++ ) {
if ( V_4 -> V_8 [ V_10 ] ) {
V_145 = 0 ;
break;
}
}
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_145 ;
}
static int F_83 ( struct V_3 * V_4 )
{
unsigned long V_163 ;
int V_145 ;
V_163 = V_164 ;
do {
F_84 ( & V_4 -> V_2 ) ;
V_145 = F_85 ( & V_4 -> V_111 , 5000 ) ;
if ( V_145 == 0 )
return - V_165 ;
V_145 = F_85 ( & V_4 -> V_114 , 500 ) ;
if ( V_145 == 0 )
return - V_165 ;
if ( F_86 ( V_164 , V_163 + 5 * V_166 ) )
return - V_165 ;
} while ( ! F_82 ( V_4 ) );
return 0 ;
}
static int F_87 ( struct V_138 * V_126 )
{
struct V_59 * V_60 = F_88 ( V_126 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_60 -> V_20 ;
unsigned long V_9 ;
if ( V_4 -> V_161 )
return 0 ;
F_3 ( V_60 -> V_167 , V_9 ) ;
F_89 ( V_60 ) ;
F_6 ( V_60 -> V_167 , V_9 ) ;
if ( F_83 ( V_4 ) != 0 ) {
F_50 ( V_127 , V_60 , L_36 , V_24 ) ;
F_90 ( V_60 ) ;
return 1 ;
}
F_68 ( V_4 ) ;
return 0 ;
}
static int F_91 ( struct V_138 * V_126 )
{
struct V_59 * V_60 = F_88 ( V_126 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_60 -> V_20 ;
unsigned long V_9 ;
int V_11 ;
if ( V_4 -> V_161 )
return 0 ;
V_11 = F_62 ( V_4 ) ;
if ( V_11 ) {
F_50 ( V_127 , V_60 ,
L_37 ,
V_24 , V_11 ) ;
return 1 ;
}
F_3 ( V_60 -> V_167 , V_9 ) ;
F_92 ( V_60 , 0 ) ;
F_6 ( V_60 -> V_167 , V_9 ) ;
F_90 ( V_60 ) ;
return 0 ;
}
static int F_93 ( struct V_138 * V_126 , T_2 V_168 )
{
struct V_59 * V_60 = F_88 ( V_126 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_60 -> V_20 ;
if ( F_83 ( V_4 ) != 0 ) {
F_50 ( V_127 , V_60 , L_36 , V_24 ) ;
return - V_165 ;
}
return 0 ;
}
static int F_94 ( struct V_138 * V_126 )
{
return 0 ;
}
static int F_95 ( struct V_138 * V_126 )
{
struct V_59 * V_60 = F_88 ( V_126 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_60 -> V_20 ;
unsigned long V_9 ;
int V_11 ;
V_11 = F_62 ( V_4 ) ;
if ( V_11 ) {
F_50 ( V_127 , V_60 ,
L_37 ,
V_24 , V_11 ) ;
return - V_169 ;
}
F_3 ( V_60 -> V_167 , V_9 ) ;
F_92 ( V_60 , 0 ) ;
F_6 ( V_60 -> V_167 , V_9 ) ;
return 0 ;
}
static void F_96 ( struct V_138 * V_126 )
{
struct V_59 * V_60 = F_88 ( V_126 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_60 -> V_20 ;
unsigned long V_9 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 1 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_97 ( & V_4 -> V_2 ) ;
F_51 ( & V_4 -> V_116 ) ;
F_51 ( & V_4 -> V_111 ) ;
F_51 ( & V_4 -> V_114 ) ;
F_9 ( V_4 , V_170 ) ;
F_98 ( V_60 ) ;
F_68 ( V_4 ) ;
F_81 ( V_60 ) ;
}
static void F_99 ( struct V_19 * V_66 )
{
struct V_138 * V_126 = F_100 ( V_66 ) ;
struct V_84 * V_85 = F_72 ( V_126 ) ;
struct V_59 * V_60 = F_88 ( V_126 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_60 -> V_20 ;
if ( V_171 != V_172 )
return;
V_4 -> V_161 = 1 ;
F_68 ( V_4 ) ;
F_61 ( V_85 , V_126 -> V_140 [ 0 ] . V_141 . V_142 , 0 ) ;
F_52 ( V_85 ) ;
}

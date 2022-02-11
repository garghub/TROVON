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
V_11 = F_4 ( V_8 , V_8 -> V_19 -> V_20 , V_21 ) ;
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
struct V_22 * V_23 = ( void * ) V_6 ;
struct V_7 * V_8 = F_2 ( V_23 , struct V_7 , V_16 ) ;
struct V_3 * V_4 = V_8 -> V_19 -> V_20 ;
F_8 ( & V_4 -> V_12 ) ;
V_6 -> V_17 |= V_18 ;
F_5 ( & V_4 -> V_2 ) ;
}
static void F_9 ( struct V_3 * V_4 , int V_24 )
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
F_10 ( V_8 , V_25 , 0 ) ;
V_6 -> V_17 &= ~ V_26 ;
V_8 -> V_24 = V_24 << 16 ;
V_11 = F_11 ( V_8 , V_25 ) ;
F_12 ( V_11 != 0 ) ;
}
F_6 ( & V_4 -> V_12 , V_9 ) ;
}
static void F_13 ( struct V_27 * V_27 , struct V_7 * V_8 )
{
struct V_28 * V_28 = V_27 -> V_29 ;
struct V_30 * V_31 = V_8 -> V_19 ;
if ( V_27 -> V_32 > 16 ) {
unsigned V_33 = F_14 ( & V_28 -> V_33 ) ;
if ( V_33 + 16 != V_27 -> V_32 ) {
int V_34 = F_15 ( V_33 + 16 , V_27 -> V_32 ) - 16 ;
if ( V_34 < 0 )
V_34 = 0 ;
F_16 ( V_35 , V_31 , L_1
L_2
L_3 , V_25 ,
V_27 -> V_32 , V_33 , V_34 ) ;
V_33 = V_34 ;
}
memcpy ( V_8 -> V_36 , V_28 -> V_37 , V_33 ) ;
}
V_8 -> V_24 = V_28 -> V_38 ;
}
static void F_10 ( struct V_7 * V_8 , const char * V_39 ,
int V_38 )
{
struct V_5 * V_40 = ( void * ) & V_8 -> V_16 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
F_17 ( V_35 , V_8 ,
L_4 ,
V_39 , V_38 , V_6 -> V_41 ,
( V_40 -> V_17 & V_42 ) ? L_5 : L_6 ,
( V_40 -> V_17 & V_43 ) ? L_7 : L_6 ,
( V_40 -> V_17 & V_44 ) ? L_8 : L_6 ,
( V_40 -> V_17 & V_45 ) ? L_9 : L_6 ,
( V_40 -> V_17 & V_46 ) ? L_10 : L_6 ,
( V_40 -> V_17 & V_47 ) ? L_11 : L_6 ,
( V_40 -> V_17 & V_48 ) ? L_12 : L_6 ,
( V_40 -> V_17 & V_26 ) ? L_13 : L_6 ,
( V_40 -> V_17 & V_49 ) ? L_14 : L_6 ,
( V_40 -> V_17 & V_50 ) ? L_15 : L_6 ,
( V_40 -> V_17 & V_51 ) ? L_16 : L_6 ,
( V_40 -> V_17 & V_18 ) ? L_17 : L_6 ) ;
F_18 ( V_8 ) ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_5 * V_6 ;
if ( ! V_8 )
return;
V_6 = ( void * ) & V_8 -> V_16 ;
if ( V_6 -> V_17 & V_48 )
F_20 ( V_6 -> V_52 ) ;
if ( ! ( V_6 -> V_17 & V_49 ) )
F_20 ( V_6 -> V_53 ) ;
if ( ! ( V_6 -> V_17 & V_50 ) )
F_20 ( V_6 -> V_54 ) ;
}
static int F_11 ( struct V_7 * V_8 , const char * V_55 )
{
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_3 * V_4 = ( void * ) V_8 -> V_19 -> V_20 ;
F_8 ( & V_4 -> V_12 ) ;
if ( V_6 -> V_17 & ( V_26 |
V_49 |
V_50 |
V_51 ) )
return - V_56 ;
V_4 -> V_8 [ V_6 -> V_41 - 1 ] = NULL ;
F_19 ( V_8 ) ;
V_8 -> V_57 ( V_8 ) ;
return 0 ;
}
static void F_21 ( struct V_27 * V_27 , struct V_7 * V_8 ,
unsigned V_58 )
{
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
int V_11 ;
V_6 -> V_17 |= V_58 | V_42 ;
V_11 = F_4 ( V_8 , V_8 -> V_19 -> V_20 , V_21 ) ;
if ( V_11 ) {
F_7 ( V_6 ) ;
}
}
static void F_22 ( struct V_27 * V_27 )
{
struct V_59 * V_59 = V_27 -> V_29 ;
struct V_60 * V_61 = V_27 -> V_62 ;
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_20 ;
struct V_27 * V_53 = NULL ;
struct V_27 * V_54 = NULL ;
struct V_7 * V_8 ;
struct V_5 * V_6 ;
unsigned long V_9 ;
unsigned int V_63 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_4 -> V_13 )
goto V_14;
if ( V_27 -> V_38 ) {
if ( V_27 -> V_38 != - V_64 && V_27 -> V_38 != - V_65 ) {
F_23 ( & V_27 -> V_66 -> V_66 , L_18 ,
V_27 -> V_38 ) ;
}
goto V_14;
}
V_63 = F_14 ( & V_59 -> V_67 ) - 1 ;
if ( V_63 >= V_68 || ! V_4 -> V_8 [ V_63 ] ) {
F_23 ( & V_27 -> V_66 -> V_66 ,
L_19 , V_63 + 1 ) ;
goto V_14;
}
V_8 = V_4 -> V_8 [ V_63 ] ;
V_6 = ( void * ) & V_8 -> V_16 ;
if ( ! ( V_6 -> V_17 & V_26 ) ) {
F_10 ( V_8 , L_20 , 0 ) ;
goto V_14;
}
switch ( V_59 -> V_69 ) {
case V_70 :
F_13 ( V_27 , V_8 ) ;
if ( V_8 -> V_24 != 0 ) {
V_53 = F_24 ( V_6 -> V_53 ) ;
V_54 = F_24 ( V_6 -> V_54 ) ;
}
V_6 -> V_17 &= ~ V_26 ;
F_11 ( V_8 , V_25 ) ;
break;
case V_71 :
if ( ! V_6 -> V_53 ||
( V_6 -> V_17 & V_49 ) ) {
F_10 ( V_8 , L_21 , 0 ) ;
break;
}
F_21 ( V_27 , V_8 , V_44 ) ;
break;
case V_72 :
if ( ! V_6 -> V_54 ||
( V_6 -> V_17 & V_50 ) ) {
F_10 ( V_8 , L_22 , 0 ) ;
break;
}
F_21 ( V_27 , V_8 , V_46 ) ;
break;
case V_73 :
F_10 ( V_8 , L_23 ,
( (struct V_74 * ) V_59 ) -> V_75 ) ;
V_53 = F_24 ( V_6 -> V_53 ) ;
V_54 = F_24 ( V_6 -> V_54 ) ;
V_6 -> V_17 &= ~ V_26 ;
V_8 -> V_24 = V_76 << 16 ;
F_11 ( V_8 , V_25 ) ;
break;
default:
F_10 ( V_8 , L_24 , V_59 -> V_69 ) ;
}
V_14:
F_20 ( V_27 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
if ( V_53 ) {
F_25 ( V_53 ) ;
F_26 ( V_53 ) ;
}
if ( V_54 ) {
F_25 ( V_54 ) ;
F_26 ( V_54 ) ;
}
}
static void F_27 ( struct V_27 * V_27 )
{
struct V_7 * V_8 = V_27 -> V_62 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_3 * V_4 = ( void * ) V_8 -> V_19 -> V_20 ;
struct V_77 * V_78 = NULL ;
unsigned long V_9 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_6 -> V_53 == V_27 ) {
V_78 = F_28 ( V_8 ) ;
V_6 -> V_17 &= ~ V_49 ;
V_6 -> V_53 = NULL ;
} else if ( V_6 -> V_54 == V_27 ) {
V_78 = F_29 ( V_8 ) ;
V_6 -> V_17 &= ~ V_50 ;
V_6 -> V_54 = NULL ;
}
if ( V_78 == NULL ) {
F_30 ( 1 ) ;
goto V_14;
}
if ( V_4 -> V_13 )
goto V_14;
if ( V_6 -> V_17 & V_48 ) {
F_10 ( V_8 , L_25 , 0 ) ;
goto V_14;
}
if ( V_27 -> V_38 ) {
if ( V_27 -> V_38 != - V_64 && V_27 -> V_38 != - V_65 )
F_10 ( V_8 , L_26 , V_27 -> V_38 ) ;
V_78 -> V_79 = V_78 -> V_80 ;
} else {
V_78 -> V_79 = V_78 -> V_80 - V_27 -> V_32 ;
}
F_11 ( V_8 , V_25 ) ;
V_14:
F_20 ( V_27 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
}
static void F_31 ( struct V_27 * V_27 )
{
if ( V_27 -> V_38 )
F_23 ( & V_27 -> V_66 -> V_66 , L_27 , V_27 -> V_38 ) ;
F_20 ( V_27 ) ;
}
static struct V_27 * F_32 ( struct V_3 * V_4 , T_1 V_81 ,
struct V_7 * V_8 ,
enum V_82 V_83 )
{
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_27 * V_27 = F_33 ( 0 , V_81 ) ;
struct V_77 * V_78 = ( V_83 == V_86 )
? F_28 ( V_8 ) : F_29 ( V_8 ) ;
unsigned int V_87 = ( V_83 == V_86 )
? V_4 -> V_88 : V_4 -> V_89 ;
if ( ! V_27 )
goto V_14;
F_34 ( V_27 , V_85 , V_87 , NULL , V_78 -> V_80 ,
F_27 , V_8 ) ;
if ( V_4 -> V_90 )
V_27 -> V_91 = V_6 -> V_41 ;
V_27 -> V_92 = V_85 -> V_93 -> V_94 ? V_78 -> V_95 . V_96 : 0 ;
V_27 -> V_97 = V_78 -> V_95 . V_98 ;
V_14:
return V_27 ;
}
static struct V_27 * F_35 ( struct V_3 * V_4 , T_1 V_81 ,
struct V_7 * V_8 )
{
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_27 * V_27 = F_33 ( 0 , V_81 ) ;
struct V_28 * V_59 ;
if ( ! V_27 )
goto V_14;
V_59 = F_36 ( sizeof( * V_59 ) , V_81 ) ;
if ( ! V_59 )
goto free;
F_34 ( V_27 , V_85 , V_4 -> V_99 , V_59 , sizeof( * V_59 ) ,
F_22 , V_8 -> V_19 -> V_100 ) ;
if ( V_4 -> V_90 )
V_27 -> V_91 = V_6 -> V_41 ;
V_27 -> V_101 |= V_102 ;
V_14:
return V_27 ;
free:
F_20 ( V_27 ) ;
return NULL ;
}
static struct V_27 * F_37 ( struct V_3 * V_4 , T_1 V_81 ,
struct V_7 * V_8 )
{
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_30 * V_31 = V_8 -> V_19 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_27 * V_27 = F_33 ( 0 , V_81 ) ;
struct V_103 * V_59 ;
int V_33 ;
if ( ! V_27 )
goto V_14;
V_33 = V_8 -> V_104 - 16 ;
if ( V_33 < 0 )
V_33 = 0 ;
V_33 = F_38 ( V_33 , 4 ) ;
V_59 = F_36 ( sizeof( * V_59 ) + V_33 , V_81 ) ;
if ( ! V_59 )
goto free;
V_59 -> V_69 = V_105 ;
V_59 -> V_67 = F_39 ( V_6 -> V_41 ) ;
V_59 -> V_106 = V_107 ;
V_59 -> V_33 = V_33 ;
F_40 ( V_31 -> V_108 , & V_59 -> V_108 ) ;
memcpy ( V_59 -> V_109 , V_8 -> V_8 , V_8 -> V_104 ) ;
F_34 ( V_27 , V_85 , V_4 -> V_110 , V_59 , sizeof( * V_59 ) + V_33 ,
F_31 , NULL ) ;
V_27 -> V_101 |= V_102 ;
V_14:
return V_27 ;
free:
F_20 ( V_27 ) ;
return NULL ;
}
static struct V_27 * F_41 ( struct V_7 * V_8 , T_1 V_81 )
{
struct V_3 * V_4 = V_8 -> V_19 -> V_20 ;
struct V_27 * V_27 ;
int V_11 ;
V_27 = F_35 ( V_4 , V_81 , V_8 ) ;
if ( ! V_27 )
return NULL ;
F_42 ( V_27 , & V_4 -> V_111 ) ;
V_11 = F_43 ( V_27 , V_81 ) ;
if ( V_11 ) {
F_44 ( V_27 ) ;
F_10 ( V_8 , L_28 , V_11 ) ;
F_20 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_3 * V_4 , T_1 V_81 )
{
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
struct V_27 * V_27 ;
int V_11 ;
F_8 ( & V_4 -> V_12 ) ;
if ( V_6 -> V_17 & V_42 ) {
V_27 = F_41 ( V_8 , V_81 ) ;
if ( ! V_27 )
return V_112 ;
V_6 -> V_17 &= ~ V_42 ;
}
if ( V_6 -> V_17 & V_43 ) {
V_6 -> V_53 = F_32 ( V_4 , V_81 ,
V_8 , V_86 ) ;
if ( ! V_6 -> V_53 )
return V_112 ;
V_6 -> V_17 &= ~ V_43 ;
}
if ( V_6 -> V_17 & V_44 ) {
F_42 ( V_6 -> V_53 , & V_4 -> V_113 ) ;
V_11 = F_43 ( V_6 -> V_53 , V_81 ) ;
if ( V_11 ) {
F_44 ( V_6 -> V_53 ) ;
F_10 ( V_8 , L_29 , V_11 ) ;
return V_112 ;
}
V_6 -> V_17 &= ~ V_44 ;
V_6 -> V_17 |= V_49 ;
}
if ( V_6 -> V_17 & V_45 ) {
V_6 -> V_54 = F_32 ( V_4 , V_81 ,
V_8 , V_114 ) ;
if ( ! V_6 -> V_54 )
return V_112 ;
V_6 -> V_17 &= ~ V_45 ;
}
if ( V_6 -> V_17 & V_46 ) {
F_42 ( V_6 -> V_54 , & V_4 -> V_113 ) ;
V_11 = F_43 ( V_6 -> V_54 , V_81 ) ;
if ( V_11 ) {
F_44 ( V_6 -> V_54 ) ;
F_10 ( V_8 , L_30 , V_11 ) ;
return V_112 ;
}
V_6 -> V_17 &= ~ V_46 ;
V_6 -> V_17 |= V_50 ;
}
if ( V_6 -> V_17 & V_47 ) {
V_6 -> V_52 = F_37 ( V_4 , V_81 , V_8 ) ;
if ( ! V_6 -> V_52 )
return V_112 ;
V_6 -> V_17 &= ~ V_47 ;
}
if ( V_6 -> V_17 & V_48 ) {
F_42 ( V_6 -> V_52 , & V_4 -> V_115 ) ;
V_11 = F_43 ( V_6 -> V_52 , V_81 ) ;
if ( V_11 ) {
F_44 ( V_6 -> V_52 ) ;
F_10 ( V_8 , L_31 , V_11 ) ;
return V_112 ;
}
V_6 -> V_52 = NULL ;
V_6 -> V_17 &= ~ V_48 ;
V_6 -> V_17 |= V_26 ;
}
return 0 ;
}
static int F_45 ( struct V_7 * V_8 ,
void (* F_46)( struct V_7 * ) )
{
struct V_30 * V_31 = V_8 -> V_19 ;
struct V_3 * V_4 = V_31 -> V_20 ;
struct V_5 * V_6 = ( void * ) & V_8 -> V_16 ;
unsigned long V_9 ;
int V_63 , V_11 ;
F_47 ( sizeof( struct V_5 ) > sizeof( struct V_22 ) ) ;
if ( V_8 -> V_19 -> V_100 -> V_116 )
return V_112 ;
if ( ( V_4 -> V_9 & V_117 ) &&
( V_8 -> V_8 [ 0 ] == V_118 || V_8 -> V_8 [ 0 ] == V_119 ) ) {
memcpy ( V_8 -> V_36 , V_120 ,
sizeof( V_120 ) ) ;
V_8 -> V_24 = V_121 ;
V_8 -> V_57 ( V_8 ) ;
return 0 ;
}
F_3 ( & V_4 -> V_12 , V_9 ) ;
if ( V_4 -> V_13 ) {
V_8 -> V_24 = V_76 << 16 ;
V_8 -> V_57 ( V_8 ) ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
return 0 ;
}
for ( V_63 = 0 ; V_63 < V_4 -> V_15 ; V_63 ++ ) {
if ( ! V_4 -> V_8 [ V_63 ] )
break;
}
if ( V_63 == V_4 -> V_15 ) {
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_112 ;
}
V_8 -> V_57 = F_46 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_6 -> V_41 = V_63 + 1 ;
V_6 -> V_17 = V_42 | V_47 | V_48 ;
switch ( V_8 -> V_122 ) {
case V_86 :
V_6 -> V_17 |= V_43 | V_44 ;
break;
case V_123 :
V_6 -> V_17 |= V_43 | V_44 ;
case V_114 :
V_6 -> V_17 |= V_45 | V_46 ;
case V_124 :
break;
}
if ( ! V_4 -> V_90 )
V_6 -> V_17 &= ~ ( V_44 | V_46 ) ;
V_11 = F_4 ( V_8 , V_4 , V_21 ) ;
if ( V_11 ) {
if ( V_6 -> V_17 & V_42 ) {
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_112 ;
}
F_7 ( V_6 ) ;
}
V_4 -> V_8 [ V_63 ] = V_8 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
return 0 ;
}
int F_48 ( struct V_7 * V_8 )
{
struct V_30 * V_31 = V_8 -> V_19 ;
struct V_3 * V_4 = V_31 -> V_20 ;
struct V_84 * V_85 = V_4 -> V_85 ;
unsigned long V_9 ;
int V_11 ;
V_11 = F_49 ( V_85 , V_4 -> V_125 ) ;
if ( V_11 ) {
F_50 ( V_126 , V_31 -> V_100 ,
L_32 , V_25 , V_11 ) ;
return V_127 ;
}
F_50 ( V_35 , V_31 -> V_100 , L_33 , V_25 ) ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 1 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_51 ( & V_4 -> V_115 ) ;
F_51 ( & V_4 -> V_111 ) ;
F_51 ( & V_4 -> V_113 ) ;
F_9 ( V_4 , V_128 ) ;
V_11 = F_52 ( V_85 ) ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 0 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_53 ( V_85 ) ;
if ( V_11 ) {
F_50 ( V_35 , V_31 -> V_100 , L_34 ,
V_25 , V_11 ) ;
return V_127 ;
}
F_50 ( V_35 , V_31 -> V_100 , L_35 , V_25 ) ;
return V_129 ;
}
static int F_54 ( struct V_30 * V_31 )
{
struct V_3 * V_4 =
(struct V_3 * ) V_31 -> V_100 -> V_20 ;
V_31 -> V_20 = V_4 ;
F_55 ( V_31 -> V_130 , ( 512 - 1 ) ) ;
if ( V_4 -> V_9 & V_131 )
F_56 ( V_31 -> V_130 , 64 ) ;
else if ( V_4 -> V_9 & V_132 )
F_56 ( V_31 -> V_130 , 240 ) ;
return 0 ;
}
static int F_57 ( struct V_30 * V_31 )
{
struct V_3 * V_4 = V_31 -> V_20 ;
if ( V_4 -> V_9 & V_133 )
V_31 -> V_134 = 1 ;
F_58 ( V_31 , V_4 -> V_15 - 2 ) ;
return 0 ;
}
static int F_59 ( struct V_84 * V_85 ,
struct V_135 * V_125 )
{
int V_136 ;
V_136 = F_60 ( V_125 ) ;
if ( V_136 < 0 )
return V_136 ;
return F_61 ( V_85 ,
V_125 -> V_137 [ 0 ] . V_138 . V_139 , V_136 ) ;
}
static int F_62 ( struct V_3 * V_4 )
{
struct V_140 * V_141 [ 4 ] = { } ;
struct V_84 * V_85 = V_4 -> V_85 ;
int V_142 ;
V_142 = F_63 ( V_4 -> V_125 -> V_143 , V_141 ) ;
if ( V_142 )
return V_142 ;
V_4 -> V_110 = F_64 ( V_85 ,
F_65 ( & V_141 [ 0 ] -> V_138 ) ) ;
V_4 -> V_99 = F_66 ( V_85 ,
F_65 ( & V_141 [ 1 ] -> V_138 ) ) ;
V_4 -> V_88 = F_66 ( V_85 ,
F_65 ( & V_141 [ 2 ] -> V_138 ) ) ;
V_4 -> V_89 = F_64 ( V_85 ,
F_65 ( & V_141 [ 3 ] -> V_138 ) ) ;
if ( V_85 -> V_144 < V_145 ) {
V_4 -> V_15 = 32 ;
V_4 -> V_90 = 0 ;
} else {
V_4 -> V_15 = F_67 ( V_4 -> V_125 , V_141 + 1 ,
3 , V_68 , V_146 ) ;
if ( V_4 -> V_15 < 0 )
return V_4 -> V_15 ;
V_4 -> V_90 = 1 ;
}
return 0 ;
}
static void F_68 ( struct V_3 * V_4 )
{
struct V_84 * V_85 = V_4 -> V_85 ;
struct V_140 * V_141 [ 3 ] ;
V_141 [ 0 ] = F_69 ( V_85 , V_4 -> V_99 ) ;
V_141 [ 1 ] = F_69 ( V_85 , V_4 -> V_88 ) ;
V_141 [ 2 ] = F_69 ( V_85 , V_4 -> V_89 ) ;
F_70 ( V_4 -> V_125 , V_141 , 3 , V_146 ) ;
}
static int F_71 ( struct V_135 * V_125 , const struct V_147 * V_148 )
{
int V_24 = - V_149 ;
struct V_60 * V_61 = NULL ;
struct V_3 * V_4 ;
struct V_84 * V_85 = F_72 ( V_125 ) ;
unsigned long V_150 ;
if ( ! F_73 ( V_125 , V_148 , & V_150 ) )
return - V_151 ;
if ( F_59 ( V_85 , V_125 ) )
return - V_151 ;
V_61 = F_74 ( & V_152 ,
sizeof( struct V_3 ) ) ;
if ( ! V_61 )
goto V_153;
V_61 -> V_154 = 16 + 252 ;
V_61 -> V_155 = 1 ;
V_61 -> V_156 = 256 ;
V_61 -> V_157 = 0 ;
V_61 -> V_94 = V_85 -> V_93 -> V_94 ;
V_4 = (struct V_3 * ) V_61 -> V_20 ;
V_4 -> V_125 = V_125 ;
V_4 -> V_85 = V_85 ;
V_4 -> V_13 = 0 ;
V_4 -> V_158 = 0 ;
V_4 -> V_9 = V_150 ;
F_75 ( & V_4 -> V_115 ) ;
F_75 ( & V_4 -> V_111 ) ;
F_75 ( & V_4 -> V_113 ) ;
F_76 ( & V_4 -> V_12 ) ;
F_77 ( & V_4 -> V_2 , F_1 ) ;
V_24 = F_62 ( V_4 ) ;
if ( V_24 )
goto V_153;
V_24 = F_78 ( V_61 , V_4 -> V_15 - 2 ) ;
if ( V_24 )
goto V_159;
F_79 ( V_125 , V_61 ) ;
V_24 = F_80 ( V_61 , & V_125 -> V_66 ) ;
if ( V_24 )
goto V_159;
F_81 ( V_61 ) ;
return V_24 ;
V_159:
F_68 ( V_4 ) ;
F_79 ( V_125 , NULL ) ;
V_153:
F_61 ( V_85 , V_125 -> V_137 [ 0 ] . V_138 . V_139 , 0 ) ;
if ( V_61 )
F_82 ( V_61 ) ;
return V_24 ;
}
static int F_83 ( struct V_3 * V_4 )
{
unsigned long V_9 ;
int V_10 , V_142 = 1 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
for ( V_10 = 0 ; V_10 < V_4 -> V_15 ; V_10 ++ ) {
if ( V_4 -> V_8 [ V_10 ] ) {
V_142 = 0 ;
break;
}
}
F_6 ( & V_4 -> V_12 , V_9 ) ;
return V_142 ;
}
static int F_84 ( struct V_3 * V_4 )
{
unsigned long V_160 ;
int V_142 ;
V_160 = V_161 ;
do {
F_85 ( & V_4 -> V_2 ) ;
V_142 = F_86 ( & V_4 -> V_111 , 5000 ) ;
if ( V_142 == 0 )
return - V_162 ;
V_142 = F_86 ( & V_4 -> V_113 , 500 ) ;
if ( V_142 == 0 )
return - V_162 ;
if ( F_87 ( V_161 , V_160 + 5 * V_163 ) )
return - V_162 ;
} while ( ! F_83 ( V_4 ) );
return 0 ;
}
static int F_88 ( struct V_135 * V_125 )
{
struct V_60 * V_61 = F_89 ( V_125 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_20 ;
unsigned long V_9 ;
if ( V_4 -> V_158 )
return 0 ;
F_3 ( V_61 -> V_164 , V_9 ) ;
F_90 ( V_61 ) ;
F_6 ( V_61 -> V_164 , V_9 ) ;
if ( F_84 ( V_4 ) != 0 ) {
F_50 ( V_126 , V_61 , L_36 , V_25 ) ;
F_91 ( V_61 ) ;
return 1 ;
}
F_68 ( V_4 ) ;
return 0 ;
}
static int F_92 ( struct V_135 * V_125 )
{
struct V_60 * V_61 = F_89 ( V_125 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_20 ;
unsigned long V_9 ;
int V_11 ;
if ( V_4 -> V_158 )
return 0 ;
V_11 = F_62 ( V_4 ) ;
if ( V_11 ) {
F_50 ( V_126 , V_61 ,
L_37 ,
V_25 , V_11 ) ;
return 1 ;
}
F_3 ( V_61 -> V_164 , V_9 ) ;
F_93 ( V_61 , 0 ) ;
F_6 ( V_61 -> V_164 , V_9 ) ;
F_91 ( V_61 ) ;
return 0 ;
}
static int F_94 ( struct V_135 * V_125 , T_2 V_165 )
{
struct V_60 * V_61 = F_89 ( V_125 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_20 ;
if ( F_84 ( V_4 ) != 0 ) {
F_50 ( V_126 , V_61 , L_36 , V_25 ) ;
return - V_162 ;
}
return 0 ;
}
static int F_95 ( struct V_135 * V_125 )
{
return 0 ;
}
static int F_96 ( struct V_135 * V_125 )
{
struct V_60 * V_61 = F_89 ( V_125 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_20 ;
unsigned long V_9 ;
int V_11 ;
V_11 = F_62 ( V_4 ) ;
if ( V_11 ) {
F_50 ( V_126 , V_61 ,
L_37 ,
V_25 , V_11 ) ;
return - V_166 ;
}
F_3 ( V_61 -> V_164 , V_9 ) ;
F_93 ( V_61 , 0 ) ;
F_6 ( V_61 -> V_164 , V_9 ) ;
return 0 ;
}
static void F_97 ( struct V_135 * V_125 )
{
struct V_60 * V_61 = F_89 ( V_125 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_20 ;
unsigned long V_9 ;
F_3 ( & V_4 -> V_12 , V_9 ) ;
V_4 -> V_13 = 1 ;
F_6 ( & V_4 -> V_12 , V_9 ) ;
F_98 ( & V_4 -> V_2 ) ;
F_51 ( & V_4 -> V_115 ) ;
F_51 ( & V_4 -> V_111 ) ;
F_51 ( & V_4 -> V_113 ) ;
F_9 ( V_4 , V_167 ) ;
F_99 ( V_61 ) ;
F_68 ( V_4 ) ;
F_82 ( V_61 ) ;
}
static void F_100 ( struct V_19 * V_66 )
{
struct V_135 * V_125 = F_101 ( V_66 ) ;
struct V_84 * V_85 = F_72 ( V_125 ) ;
struct V_60 * V_61 = F_89 ( V_125 ) ;
struct V_3 * V_4 = (struct V_3 * ) V_61 -> V_20 ;
if ( V_168 != V_169 )
return;
V_4 -> V_158 = 1 ;
F_68 ( V_4 ) ;
F_61 ( V_85 , V_125 -> V_137 [ 0 ] . V_138 . V_139 , 0 ) ;
F_52 ( V_85 ) ;
}

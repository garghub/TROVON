static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = 0 , V_4 = 0 ;
F_2 ( V_5 ) ;
F_3 ( V_6 / 4 ) ;
V_3 = F_4 ( V_2 -> V_7 , 0 , V_8 ) ;
if ( V_3 != 0 )
return V_3 ;
V_3 = F_5 ( V_2 , V_9 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_6 ( V_2 , V_10 , V_11 , & V_4 ) ;
if ( V_3 | V_4 )
return V_3 ;
return 0 ;
}
static int F_7 ( struct V_12 * V_13 , int V_14 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_16 * V_17 ;
int V_3 = 0 ;
if ( ! V_2 )
return - V_18 ;
V_17 = F_8 ( V_13 , struct V_16 , V_19 ) ;
if ( V_14 ) {
F_9 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_21 & V_22 ) {
V_3 = - V_18 ;
goto V_23;
}
if ( V_2 -> V_21 && ! ( V_2 -> V_21 & V_24 ) ) {
V_3 = - V_25 ;
goto V_23;
}
F_10 ( V_2 -> V_26 ) ;
if ( 0 == V_2 -> V_21 ) {
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 ) {
F_11 ( V_2 -> V_26 ) ;
goto V_23;
}
V_2 -> V_21 |= V_24 ;
V_17 -> V_27 = 0 ;
V_17 -> V_28 = 0 ;
}
F_12 ( & V_17 -> V_29 ) ;
F_13 ( & V_2 -> V_30 ) ;
V_23:
F_14 ( & V_2 -> V_20 ) ;
} else {
F_15 ( V_17 ) ;
if ( F_16 ( & V_17 -> V_29 ) ) {
F_9 ( & V_2 -> V_20 ) ;
V_2 -> V_21 &= ~ V_24 ;
F_14 ( & V_2 -> V_20 ) ;
}
F_17 ( & V_2 -> V_30 , V_31 ) ;
F_11 ( V_2 -> V_26 ) ;
}
return V_3 ;
}
static void F_18 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
V_2 -> V_32 = NULL ;
V_2 -> V_33 = NULL ;
}
static T_1 F_19 ( struct V_12 * V_13 )
{
return 0 ;
}
static bool F_20 ( T_2 V_34 , int V_27 ,
struct V_16 * V_35 )
{
if ( V_27 < 0 )
return false ;
if ( V_35 -> V_28 == V_34
&& V_35 -> V_27 == V_27 ) {
long V_36 = V_37 - V_35 -> V_38 ;
unsigned int V_39 ;
V_39 = F_21 ( abs ( V_36 ) ) ;
return V_39 > 15000 ? true : false ;
}
return true ;
}
static int F_22 ( struct V_16 * V_35 )
{
long V_36 = V_37 - V_35 -> V_38 ;
unsigned int V_39 ;
V_39 = F_21 ( abs ( V_36 ) ) ;
return V_39 > 800 ? true : false ;
}
static int F_23 ( struct V_12 * V_13 )
{
struct V_40 * V_41 = & V_13 -> V_42 ;
T_1 V_3 = 0 , V_4 = 0 ;
T_1 V_43 , V_27 = - 1 ;
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_2 -> V_44 ;
if ( F_24 ( V_2 ) )
return - V_25 ;
F_9 ( & V_2 -> V_20 ) ;
for ( V_43 = 0 ; V_43 < V_45 ; V_43 ++ )
if ( V_41 -> V_46 == V_47 [ V_43 ] [ 1 ] )
V_27 = V_47 [ V_43 ] [ 0 ] ;
if ( F_20 ( V_41 -> V_48 , V_27 , V_17 ) ) {
V_3 = F_6 ( V_2 , V_49 ,
V_41 -> V_48 / 1000 , & V_4 ) ;
if ( V_3 | V_4 ) {
log ( L_1 ) ;
goto V_50;
}
V_3 = F_6 ( V_2 , V_51 ,
V_27 , & V_4 ) ;
if ( V_3 | V_4 ) {
log ( L_1 ) ;
goto V_50;
}
V_3 = F_6 ( V_2 , V_52 , 0 , & V_4 ) ;
if ( V_3 | V_4 ) {
log ( L_1 ) ;
goto V_50;
}
memcpy ( & V_17 -> V_53 , V_41 , sizeof( * V_41 ) ) ;
V_17 -> V_27 = V_27 ;
V_17 -> V_28 = V_41 -> V_48 ;
V_17 -> V_38 = V_37 ;
}
V_50:
F_14 ( & V_2 -> V_20 ) ;
return V_3 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_44 ;
F_15 ( V_17 ) ;
F_26 ( V_17 ) ;
F_27 ( 500 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_44 ;
F_1 ( V_2 ) ;
F_27 ( 300 ) ;
F_23 ( & V_17 -> V_19 ) ;
F_29 ( V_17 ) ;
return 0 ;
}
static T_1 F_30 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_2 -> V_44 ;
#ifdef F_31
V_2 -> V_32 = F_25 ;
V_2 -> V_33 = F_28 ;
#endif
memset ( & V_17 -> V_53 , 0 ,
sizeof( struct V_40 ) ) ;
return 0 ;
}
static int F_32 ( struct V_12 * V_13 )
{
struct V_40 * V_41 = & V_13 -> V_42 ;
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_16 * V_17 = & V_2 -> V_44 ;
memcpy ( V_41 , & V_17 -> V_53 , sizeof( * V_41 ) ) ;
return 0 ;
}
static int F_33 ( struct V_12 * V_13 ,
struct V_54 * V_55 )
{
V_55 -> V_56 = 1000 ;
return 0 ;
}
static int F_34 ( struct V_12 * V_13 , T_3 * V_57 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
T_1 V_3 = - 1 , V_4 ;
struct V_58 V_59 = {} ;
if ( F_24 ( V_2 ) )
return - V_25 ;
F_9 ( & V_2 -> V_20 ) ;
V_3 = F_35 ( V_2 , V_60 , V_61 ,
& V_59 , & V_4 , sizeof( V_59 ) ) ;
if ( V_3 | V_4 ) {
log ( L_2 ) ;
goto V_62;
}
if ( V_63 )
log ( L_3 , V_59 . V_64 ,
V_59 . V_65 , V_59 . V_66 ) ;
if ( V_59 . V_66 ) {
goto V_62;
} else if ( V_59 . V_64 || V_59 . V_65 ) {
* V_57 |= V_67 | V_68 | V_69
| V_70 | V_71 ;
} else {
if ( F_22 ( & V_2 -> V_44 ) )
* V_57 |= V_72 ;
}
V_62:
F_14 ( & V_2 -> V_20 ) ;
return V_3 ;
}
static int F_36 ( struct V_12 * V_13 , T_4 * V_73 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_74 V_75 = {} ;
T_1 V_3 = - 1 , V_4 ;
F_9 ( & V_2 -> V_20 ) ;
V_3 = F_35 ( V_2 , V_76 , 0 ,
& V_75 , & V_4 , sizeof( V_75 ) ) ;
if ( V_3 | V_4 )
goto V_62;
* V_73 = V_75 . V_77 ;
V_62:
F_14 ( & V_2 -> V_20 ) ;
return V_3 ;
}
static T_1 F_37 ( struct V_12 * V_13 , T_5 * V_78 )
{
struct V_1 * V_2 = V_13 -> V_15 ;
struct V_58 V_59 = {} ;
T_1 V_3 = 0 , V_4 ;
F_9 ( & V_2 -> V_20 ) ;
V_3 = F_35 ( V_2 , V_60 , V_61 ,
& V_59 , & V_4 , sizeof( V_59 ) ) ;
if ( V_3 | V_4 )
goto V_62;
if ( ( V_59 . V_64 || V_59 . V_65 ) && ! V_59 . V_79 )
* V_78 = 0xFFFF ;
else
* V_78 = V_59 . V_79 ;
V_62:
F_14 ( & V_2 -> V_20 ) ;
return V_3 ;
}
static int F_38 ( struct V_12 * V_13 , T_5 * V_80 )
{
return 0 ;
}
static int F_39 ( struct V_12 * V_13 , T_4 * V_81 )
{
* V_81 = 0 ;
return 0 ;
}
static void F_40 ( struct V_82 * V_82 )
{
struct V_16 * V_17 = V_82 -> V_83 ;
int V_84 = V_82 -> V_85 ;
struct V_86 * V_87 = & V_17 -> V_87 ;
T_1 V_3 ;
if ( ! V_17 -> V_88 || V_82 -> V_59 ) {
if ( V_82 -> V_59 == - V_89 )
goto V_90;
return;
}
if ( V_82 -> V_91 == V_84 )
F_41 ( V_87 , V_82 -> V_92 , V_84 ) ;
else if ( V_82 -> V_91 == V_84 - 4 ) {
int V_93 ;
T_6 * V_94 = V_82 -> V_92 ;
for ( V_93 = 456 ; V_93 < V_84 ; V_93 += 512 ) {
if ( ! strncmp ( V_94 + V_93 , L_4 , 4 ) ) {
F_41 ( V_87 , V_94 , V_93 ) ;
if ( V_84 > V_93 + 52 + 4 ) {
V_94 += V_93 + 52 ;
V_84 -= V_93 + 52 + 4 ;
F_41 ( V_87 , V_94 , V_84 ) ;
}
break;
}
}
}
V_90:
V_3 = F_42 ( V_82 , V_95 ) ;
if ( V_3 )
log ( L_5 , V_3 ) ;
}
static int F_43 ( struct V_16 * V_17 )
{
if ( V_17 -> V_96 [ 0 ] )
return 0 ;
F_44 ( V_17 -> V_96 , V_97 ,
V_17 -> V_98 -> V_7 , V_17 -> V_99 ,
V_100 , V_101 ,
F_40 , V_17 ) ;
return 0 ;
}
static void F_26 ( struct V_16 * V_17 )
{
F_45 ( V_17 -> V_96 , V_97 ) ;
}
static T_1 F_29 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_98 ;
int V_3 = 0 ;
if ( V_2 -> V_21 & V_22 )
return - V_18 ;
F_9 ( & V_2 -> V_20 ) ;
if ( ! V_17 -> V_88 ) {
T_1 V_43 , V_4 = 0 ;
V_3 = F_6 ( V_2 , V_102 , 1 , & V_4 ) ;
if ( V_3 | V_4 )
goto V_62;
V_3 = F_43 ( V_17 ) ;
if ( V_3 < 0 )
goto V_62;
V_17 -> V_88 = 1 ;
for ( V_43 = 0 ; V_43 < V_97 ; V_43 ++ ) {
V_3 = F_42 ( V_17 -> V_96 [ V_43 ] ,
V_101 ) ;
if ( V_3 ) {
log ( L_6 , V_3 ) ;
goto V_62;
}
}
}
V_62:
F_14 ( & V_2 -> V_20 ) ;
return V_3 ;
}
void F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_98 ;
F_9 ( & V_2 -> V_20 ) ;
if ( V_17 -> V_88 ) {
T_1 V_43 , V_3 , V_4 = 0 ;
V_17 -> V_88 = 0 ;
for ( V_43 = 0 ; V_43 < V_97 ; V_43 ++ )
if ( V_17 -> V_96 [ V_43 ] )
F_46 ( V_17 -> V_96 [ V_43 ] ) ;
V_3 = F_6 ( V_2 , V_102 , V_103 ,
& V_4 ) ;
if ( V_3 | V_4 )
log ( L_7 ) ;
}
F_14 ( & V_2 -> V_20 ) ;
}
static int F_47 ( struct V_104 * V_105 )
{
struct V_16 * V_17 = V_105 -> V_87 -> V_106 ;
int V_3 = 0 ;
if ( ! V_17 )
return - 1 ;
if ( F_48 ( & V_17 -> V_107 ) == 1 )
V_3 = F_29 ( V_17 ) ;
return V_3 ;
}
static int F_49 ( struct V_104 * V_105 )
{
struct V_16 * V_17 = V_105 -> V_87 -> V_106 ;
if ( ! V_17 )
return - 1 ;
if ( F_16 ( & V_17 -> V_107 ) )
F_15 ( V_17 ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_44 ;
struct V_86 * V_108 ;
int V_3 = 0 ;
V_17 -> V_99 = 0x82 ;
F_51 ( & V_17 -> V_29 , 0 ) ;
F_51 ( & V_17 -> V_107 , 0 ) ;
V_17 -> V_98 = V_2 ;
V_3 = F_52 ( & V_17 -> V_109 ,
L_8 ,
V_110 ,
NULL ,
V_111 ) ;
if ( V_3 < 0 )
goto V_112;
V_17 -> V_19 . V_15 = V_2 ;
memcpy ( & V_17 -> V_19 . V_113 , & V_114 ,
sizeof( struct V_115 ) ) ;
V_3 = F_53 ( & V_17 -> V_109 , & V_17 -> V_19 ) ;
if ( V_3 < 0 )
goto V_116;
V_108 = & V_17 -> V_87 ;
V_108 -> V_117 . V_118 = V_119 | V_120 ;
V_108 -> V_106 = V_17 ;
V_108 -> V_121 = V_108 -> V_122 = 64 ;
V_108 -> V_123 = F_47 ;
V_108 -> V_124 = F_49 ;
V_108 -> V_125 = NULL ;
V_3 = F_54 ( V_108 ) ;
if ( V_3 < 0 )
goto V_126;
V_17 -> V_127 . V_122 = V_17 -> V_87 . V_122 ;
V_17 -> V_127 . V_87 = & V_17 -> V_87 . V_117 ;
V_17 -> V_127 . V_118 = 0 ;
V_3 = F_55 ( & V_17 -> V_127 , & V_17 -> V_109 ) ;
if ( V_3 < 0 )
goto V_126;
return 0 ;
V_126:
F_56 ( & V_17 -> V_19 ) ;
V_116:
F_57 ( & V_17 -> V_109 ) ;
V_112:
return V_3 ;
}
void F_58 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_44 ;
while ( F_59 ( & V_17 -> V_29 ) != 0
|| F_59 ( & V_17 -> V_107 ) != 0 ) {
F_2 ( V_5 ) ;
F_3 ( V_6 ) ;
}
F_60 ( & V_17 -> V_127 ) ;
F_56 ( & V_17 -> V_19 ) ;
F_57 ( & V_17 -> V_109 ) ;
F_61 ( V_2 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = & V_2 -> V_44 ;
F_26 ( V_17 ) ;
}
int F_62 ( struct V_16 * V_17 )
{
return V_17 -> V_109 . V_128 ;
}

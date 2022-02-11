int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
V_1 -> V_4 ++ ;
if ( V_1 -> V_4 == 1 ) {
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
V_2 = F_3 ( V_1 -> V_8 ) ;
if ( V_2 != 0 )
goto V_9;
break;
}
V_2 = F_4 ( V_1 -> V_10 , V_11 ,
V_12 ,
V_12 ) ;
}
V_9:
if ( V_2 != 0 )
V_1 -> V_4 -- ;
F_5 ( & V_1 -> V_3 ) ;
return V_2 ;
}
int F_6 ( struct V_1 * V_1 )
{
F_2 ( & V_1 -> V_3 ) ;
F_7 ( V_1 -> V_4 <= 0 ) ;
V_1 -> V_4 -- ;
if ( V_1 -> V_4 == 0 ) {
F_4 ( V_1 -> V_10 , V_11 ,
V_12 , 0 ) ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
F_8 ( V_1 -> V_8 ) ;
break;
}
}
F_5 ( & V_1 -> V_3 ) ;
return 0 ;
}
static T_1 F_9 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
F_10 ( V_1 -> V_8 , L_1 ) ;
return V_15 ;
}
static T_1 F_11 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 ;
int V_2 ;
V_2 = F_12 ( V_1 -> V_10 , V_17 ,
& V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_2 ,
V_2 ) ;
return V_18 ;
}
if ( V_16 & V_19 )
F_10 ( V_1 -> V_8 , L_3 ) ;
if ( V_16 & V_20 )
F_10 ( V_1 -> V_8 , L_4 ) ;
if ( V_16 & V_21 )
F_10 ( V_1 -> V_8 , L_5 ) ;
if ( V_16 & V_22 )
F_10 ( V_1 -> V_8 , L_6 ) ;
if ( V_16 & V_23 )
F_10 ( V_1 -> V_8 , L_7 ) ;
if ( V_16 & V_24 )
F_10 ( V_1 -> V_8 , L_8 ) ;
if ( V_16 & V_25 )
F_10 ( V_1 -> V_8 , L_9 ) ;
if ( V_16 & V_26 )
F_10 ( V_1 -> V_8 , L_10 ) ;
if ( V_16 & V_27 )
F_10 ( V_1 -> V_8 , L_11 ) ;
if ( V_16 & V_28 )
F_10 ( V_1 -> V_8 , L_12 ) ;
if ( V_16 & V_29 )
F_10 ( V_1 -> V_8 , L_13 ) ;
return V_15 ;
}
static T_1 F_13 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 [ 3 ] ;
int V_2 ;
V_2 = F_14 ( V_1 -> V_10 , V_30 ,
& V_16 [ 0 ] , 3 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_14 ,
V_2 ) ;
return V_18 ;
}
switch ( V_1 -> type ) {
case V_31 :
case V_32 :
V_16 [ 0 ] = ( ( V_16 [ 0 ] & 0x60e0 ) >> 1 ) |
( ( V_16 [ 0 ] & 0x1e00 ) >> 2 ) |
( V_16 [ 0 ] & 0x000f ) ;
break;
default:
break;
}
if ( V_16 [ 0 ] & V_33 )
F_10 ( V_1 -> V_8 , L_15 ) ;
if ( V_16 [ 0 ] & V_34 )
F_10 ( V_1 -> V_8 , L_16 ) ;
if ( V_16 [ 0 ] & V_35 )
F_10 ( V_1 -> V_8 , L_17 ) ;
if ( V_16 [ 0 ] & V_36 )
F_10 ( V_1 -> V_8 , L_18 ) ;
if ( V_16 [ 0 ] & V_37 )
F_10 ( V_1 -> V_8 , L_19 ) ;
if ( V_16 [ 0 ] & V_38 )
F_10 ( V_1 -> V_8 , L_20 ) ;
if ( V_16 [ 0 ] & V_39 )
F_10 ( V_1 -> V_8 , L_21 ) ;
if ( V_16 [ 0 ] & V_40 )
F_10 ( V_1 -> V_8 , L_22 ) ;
if ( V_16 [ 0 ] & V_41 )
F_10 ( V_1 -> V_8 , L_23 ) ;
if ( V_16 [ 0 ] & V_42 )
F_10 ( V_1 -> V_8 , L_24 ) ;
if ( V_16 [ 1 ] & V_43 )
F_10 ( V_1 -> V_8 , L_25 ) ;
if ( V_16 [ 1 ] & V_44 )
F_10 ( V_1 -> V_8 , L_26 ) ;
if ( V_16 [ 1 ] & V_45 )
F_10 ( V_1 -> V_8 , L_27 ) ;
if ( V_16 [ 1 ] & V_46 )
F_10 ( V_1 -> V_8 , L_28 ) ;
if ( V_16 [ 1 ] & V_47 )
F_10 ( V_1 -> V_8 , L_29 ) ;
if ( V_16 [ 1 ] & V_48 )
F_10 ( V_1 -> V_8 , L_30 ) ;
if ( V_16 [ 1 ] & V_49 )
F_10 ( V_1 -> V_8 , L_31 ) ;
if ( V_16 [ 1 ] & V_50 )
F_10 ( V_1 -> V_8 , L_32 ) ;
if ( V_16 [ 1 ] & V_51 )
F_10 ( V_1 -> V_8 , L_33 ) ;
if ( V_16 [ 1 ] & V_52 )
F_10 ( V_1 -> V_8 , L_34 ) ;
if ( V_16 [ 1 ] & V_53 )
F_10 ( V_1 -> V_8 , L_35 ) ;
if ( V_16 [ 2 ] & V_54 )
F_10 ( V_1 -> V_8 , L_36 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_1 ,
int V_55 , unsigned int V_56 ,
unsigned int V_57 , unsigned int V_58 )
{
unsigned int V_16 = 0 ;
int V_2 , V_59 ;
for ( V_59 = 0 ; V_59 < V_55 ; V_59 ++ ) {
V_2 = F_12 ( V_1 -> V_10 , V_56 , & V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_37 ,
V_56 , V_2 ) ;
continue;
}
if ( ( V_16 & V_57 ) == V_58 )
return 0 ;
F_16 ( 1000 , 5000 ) ;
}
F_10 ( V_1 -> V_8 , L_38 , V_56 , V_16 ) ;
return - V_60 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_15 ( V_1 , 5 , V_61 ,
V_62 , V_62 ) ;
if ( ! V_2 )
F_18 ( V_1 -> V_10 , V_63 ,
V_62 ) ;
F_19 ( V_1 -> V_8 ) ;
return V_2 ;
}
static inline void F_20 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 . V_64 )
F_21 ( V_1 -> V_5 . V_64 , 0 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 . V_64 ) {
switch ( V_1 -> type ) {
case V_65 :
case V_66 :
F_16 ( 5000 , 10000 ) ;
break;
default:
break;
}
F_21 ( V_1 -> V_5 . V_64 , 1 ) ;
F_16 ( 1000 , 5000 ) ;
}
}
static int F_23 ( struct V_1 * V_1 ,
struct V_67 * V_68 )
{
int V_2 , V_69 ;
V_2 = F_12 ( V_1 -> V_10 , V_70 , & V_68 -> V_71 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_39 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_12 ( V_1 -> V_10 , V_72 ,
& V_68 -> V_73 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_40 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_18 ( V_1 -> V_10 , V_70 ,
V_74 | V_75 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_41 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_15 ( V_1 , 25 , V_61 ,
V_76 ,
V_76 ) ;
if ( V_2 ) {
V_2 = - V_60 ;
goto V_77;
}
V_2 = F_18 ( V_1 -> V_10 , V_72 , 0x0144 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_42 , V_2 ) ;
goto V_77;
}
return 0 ;
V_77:
V_69 = F_18 ( V_1 -> V_10 , V_70 , V_68 -> V_71 ) ;
if ( V_69 )
F_10 ( V_1 -> V_8 ,
L_43 , V_69 ) ;
return V_2 ;
}
static int F_24 ( struct V_1 * V_1 ,
struct V_67 * V_68 )
{
int V_2 ;
V_2 = F_18 ( V_1 -> V_10 , V_72 ,
V_68 -> V_73 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_44 , V_2 ) ;
return V_2 ;
}
V_2 = F_18 ( V_1 -> V_10 , V_70 , V_68 -> V_71 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_43 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_67 V_68 ;
int V_69 , V_2 ;
V_2 = F_23 ( V_1 , & V_68 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_18 ( V_1 -> V_10 , V_78 ,
V_79 | V_80 | 160 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_45 ,
V_2 ) ;
goto V_69;
}
V_2 = F_15 ( V_1 , 5 , V_81 ,
V_82 , 0 ) ;
if ( V_2 ) {
F_18 ( V_1 -> V_10 , V_78 ,
V_83 ) ;
V_2 = - V_60 ;
}
V_69:
V_69 = F_24 ( V_1 , & V_68 ) ;
return V_2 ? : V_69 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_67 V_68 ;
int V_69 , V_2 ;
V_2 = F_23 ( V_1 , & V_68 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_27 ( V_1 -> V_10 ,
V_84 ,
F_28 ( V_84 ) ) ;
V_69 = F_24 ( V_1 , & V_68 ) ;
return V_2 ? : V_69 ;
}
static int F_29 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_18 ( V_1 -> V_10 , V_85 ,
0x0 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_46 , V_2 ) ;
return V_2 ;
}
F_20 ( V_1 ) ;
F_30 ( V_1 -> V_86 ) ;
F_31 ( 20 ) ;
V_2 = F_32 ( V_1 -> V_86 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_47 , V_2 ) ;
return V_2 ;
}
F_22 ( V_1 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_4 ( V_1 -> V_10 ,
V_87 ,
V_88 ,
V_88 ) ;
if ( V_2 != 0 )
F_10 ( V_1 -> V_8 , L_48 , V_2 ) ;
return V_2 ;
}
static int F_34 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_4 ( V_1 -> V_10 ,
V_87 ,
V_88 , 0 ) ;
if ( V_2 != 0 )
F_10 ( V_1 -> V_8 , L_49 , V_2 ) ;
return V_2 ;
}
static int F_35 ( struct V_1 * V_1 )
{
unsigned int V_16 ;
int V_2 ;
V_2 = F_12 ( V_1 -> V_10 , V_89 , & V_16 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_50 , V_2 ) ;
return V_2 ;
} else if ( V_16 & V_90 ) {
return 1 ;
} else {
return 0 ;
}
}
static int F_36 ( struct V_91 * V_8 )
{
struct V_1 * V_1 = F_37 ( V_8 ) ;
int V_2 ;
F_38 ( V_1 -> V_8 , L_51 ) ;
if ( V_1 -> V_92 ) {
F_38 ( V_1 -> V_8 , L_52 ) ;
V_2 = F_39 ( V_1 -> V_93 ,
V_1 -> V_94 ) ;
if ( V_2 ) {
F_10 ( V_8 , L_53 ,
V_2 ) ;
return V_2 ;
}
}
V_2 = F_32 ( V_1 -> V_86 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_54 , V_2 ) ;
if ( V_1 -> V_92 )
F_40 ( V_1 -> V_93 ,
V_1 -> V_94 ) ;
return V_2 ;
}
if ( V_1 -> V_92 ) {
F_22 ( V_1 ) ;
F_41 ( V_1 -> V_13 ) ;
V_1 -> V_92 = false ;
}
F_42 ( V_1 -> V_10 , false ) ;
switch ( V_1 -> type ) {
case V_95 :
if ( V_1 -> V_96 ) {
V_2 = F_34 ( V_1 ) ;
if ( V_2 != 0 )
goto V_69;
}
V_2 = F_43 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_55 ,
V_2 ) ;
goto V_69;
}
V_2 = F_25 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_56 ,
V_2 ) ;
goto V_69;
}
break;
case V_65 :
case V_66 :
V_2 = F_17 ( V_1 ) ;
if ( V_2 )
goto V_69;
if ( V_1 -> V_96 ) {
V_2 = F_34 ( V_1 ) ;
if ( V_2 != 0 )
goto V_69;
} else {
V_2 = F_44 ( V_1 -> V_86 ,
1200000 , 1200000 ) ;
if ( V_2 < 0 ) {
F_10 ( V_1 -> V_8 ,
L_57 ,
V_2 ) ;
goto V_69;
}
}
V_2 = F_26 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_58 ,
V_2 ) ;
goto V_69;
}
break;
case V_97 :
case V_98 :
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 )
goto V_69;
break;
default:
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 )
goto V_69;
if ( V_1 -> V_96 ) {
V_2 = F_34 ( V_1 ) ;
if ( V_2 != 0 )
goto V_69;
}
break;
}
V_2 = F_45 ( V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_59 ) ;
goto V_69;
}
return 0 ;
V_69:
F_42 ( V_1 -> V_10 , true ) ;
F_30 ( V_1 -> V_86 ) ;
return V_2 ;
}
static int F_46 ( struct V_91 * V_8 )
{
struct V_1 * V_1 = F_37 ( V_8 ) ;
int V_99 = 0 ;
int V_2 ;
F_38 ( V_1 -> V_8 , L_60 ) ;
switch ( V_1 -> type ) {
case V_65 :
case V_66 :
V_99 = F_35 ( V_1 ) ;
if ( V_99 < 0 )
return V_99 ;
if ( V_1 -> V_96 ) {
V_2 = F_33 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
} else {
V_2 = F_44 ( V_1 -> V_86 ,
1175000 , 1175000 ) ;
if ( V_2 < 0 ) {
F_10 ( V_1 -> V_8 ,
L_61 ,
V_2 ) ;
return V_2 ;
}
}
break;
case V_95 :
V_99 = F_35 ( V_1 ) ;
if ( V_99 < 0 )
return V_99 ;
if ( V_1 -> V_96 ) {
V_2 = F_33 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
}
if ( ! V_99 ) {
V_2 = F_18 ( V_1 -> V_10 ,
V_85 , 0x0 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_62 ,
V_2 ) ;
return V_2 ;
}
}
break;
case V_97 :
case V_98 :
break;
default:
V_99 = F_35 ( V_1 ) ;
if ( V_99 < 0 )
return V_99 ;
if ( V_1 -> V_96 ) {
V_2 = F_33 ( V_1 ) ;
if ( V_2 != 0 )
return V_2 ;
}
break;
}
F_42 ( V_1 -> V_10 , true ) ;
F_47 ( V_1 -> V_10 ) ;
F_30 ( V_1 -> V_86 ) ;
if ( ! V_99 ) {
F_38 ( V_1 -> V_8 , L_63 ) ;
V_1 -> V_92 = true ;
F_48 ( V_1 -> V_13 ) ;
F_20 ( V_1 ) ;
F_40 ( V_1 -> V_93 ,
V_1 -> V_94 ) ;
}
return 0 ;
}
static int F_49 ( struct V_91 * V_8 )
{
struct V_1 * V_1 = F_37 ( V_8 ) ;
F_38 ( V_1 -> V_8 , L_64 ) ;
F_50 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_51 ( struct V_91 * V_8 )
{
struct V_1 * V_1 = F_37 ( V_8 ) ;
F_38 ( V_1 -> V_8 , L_65 ) ;
F_41 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_52 ( struct V_91 * V_8 )
{
struct V_1 * V_1 = F_37 ( V_8 ) ;
F_38 ( V_1 -> V_8 , L_66 ) ;
F_50 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_53 ( struct V_91 * V_8 )
{
struct V_1 * V_1 = F_37 ( V_8 ) ;
F_38 ( V_1 -> V_8 , L_67 ) ;
F_41 ( V_1 -> V_13 ) ;
return 0 ;
}
unsigned long F_54 ( struct V_91 * V_8 )
{
const struct V_100 * V_101 = F_55 ( V_102 , V_8 ) ;
if ( V_101 )
return ( unsigned long ) V_101 -> V_14 ;
else
return 0 ;
}
int F_56 ( struct V_1 * V_1 , const char * V_103 ,
bool V_104 )
{
int V_105 ;
V_105 = F_57 ( V_1 -> V_8 -> V_106 , V_103 , 0 ) ;
if ( V_105 < 0 ) {
if ( V_104 )
F_10 ( V_1 -> V_8 ,
L_68 ,
V_103 , V_105 ) ;
V_105 = 0 ;
}
return V_105 ;
}
static int F_58 ( struct V_1 * V_1 )
{
struct V_107 * V_5 = & V_1 -> V_5 ;
struct V_108 * V_103 ;
const T_2 * V_109 ;
T_3 V_16 ;
int V_2 , V_59 ;
int V_110 = 0 ;
V_5 -> V_64 = F_56 ( V_1 , L_69 , true ) ;
V_2 = F_59 ( V_1 -> V_8 -> V_106 ,
L_70 ,
V_5 -> V_111 ,
F_28 ( V_5 -> V_111 ) ) ;
if ( V_2 >= 0 ) {
for ( V_59 = 0 ; V_59 < F_28 ( V_5 -> V_111 ) ; V_59 ++ ) {
if ( V_5 -> V_111 [ V_59 ] > 0xffff )
V_5 -> V_111 [ V_59 ] = 0 ;
else if ( V_5 -> V_111 [ V_59 ] == 0 )
V_5 -> V_111 [ V_59 ] = 0x10000 ;
}
} else {
F_10 ( V_1 -> V_8 , L_71 ,
V_2 ) ;
}
F_60 (arizona->dev->of_node, L_72 , prop,
cur, val) {
if ( V_110 == F_28 ( V_5 -> V_112 ) )
break;
V_5 -> V_112 [ V_110 ] = V_16 ;
V_110 ++ ;
}
V_110 = 0 ;
F_60 (arizona->dev->of_node, L_73 , prop,
cur, val) {
if ( V_110 == F_28 ( V_5 -> V_113 ) )
break;
V_5 -> V_113 [ V_110 ] = V_16 ;
V_110 ++ ;
}
V_110 = 0 ;
F_60 (arizona->dev->of_node, L_74 , prop,
cur, val) {
if ( V_110 == F_28 ( V_5 -> V_114 ) )
break;
V_5 -> V_114 [ V_110 ] = ! ! V_16 ;
V_110 ++ ;
}
return 0 ;
}
static inline int F_58 ( struct V_1 * V_1 )
{
return 0 ;
}
int F_61 ( struct V_1 * V_1 )
{
struct V_91 * V_8 = V_1 -> V_8 ;
const char * V_115 = NULL ;
unsigned int V_56 , V_16 , V_57 ;
int (* F_62)( struct V_1 * ) = NULL ;
const struct V_116 * V_117 = NULL ;
int V_118 , V_2 , V_59 ;
F_63 ( V_1 -> V_8 , V_1 ) ;
F_64 ( & V_1 -> V_3 ) ;
if ( F_65 ( V_1 -> V_8 ) )
memcpy ( & V_1 -> V_5 , F_65 ( V_1 -> V_8 ) ,
sizeof( V_1 -> V_5 ) ) ;
else
F_58 ( V_1 ) ;
F_42 ( V_1 -> V_10 , true ) ;
switch ( V_1 -> type ) {
case V_95 :
case V_65 :
case V_66 :
case V_119 :
case V_31 :
case V_32 :
case V_97 :
case V_98 :
for ( V_59 = 0 ; V_59 < F_28 ( V_120 ) ; V_59 ++ )
V_1 -> V_94 [ V_59 ] . V_121
= V_120 [ V_59 ] ;
V_1 -> V_93 = F_28 ( V_120 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_75 ,
V_1 -> type ) ;
return - V_122 ;
}
V_1 -> V_96 = true ;
switch ( V_1 -> type ) {
case V_97 :
case V_98 :
break;
default:
V_2 = F_66 ( V_1 -> V_8 , - 1 , V_123 ,
F_28 ( V_123 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_76 , V_2 ) ;
return V_2 ;
}
break;
}
V_2 = F_67 ( V_8 , V_1 -> V_93 ,
V_1 -> V_94 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_77 ,
V_2 ) ;
goto V_124;
}
V_1 -> V_86 = F_68 ( V_1 -> V_8 , L_78 ) ;
if ( F_69 ( V_1 -> V_86 ) ) {
V_2 = F_70 ( V_1 -> V_86 ) ;
F_10 ( V_8 , L_79 , V_2 ) ;
goto V_124;
}
if ( V_1 -> V_5 . V_64 ) {
V_2 = F_71 ( V_1 -> V_8 , V_1 -> V_5 . V_64 ,
V_125 | V_126 ,
L_80 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_81 , V_2 ) ;
goto V_127;
}
}
V_2 = F_39 ( V_1 -> V_93 ,
V_1 -> V_94 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_53 ,
V_2 ) ;
goto V_127;
}
V_2 = F_32 ( V_1 -> V_86 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_54 , V_2 ) ;
goto V_128;
}
F_22 ( V_1 ) ;
F_42 ( V_1 -> V_10 , false ) ;
V_2 = F_12 ( V_1 -> V_10 , V_129 , & V_56 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_82 , V_2 ) ;
goto V_130;
}
switch ( V_56 ) {
case 0x5102 :
case 0x5110 :
case 0x6349 :
case 0x6363 :
case 0x8997 :
break;
default:
F_10 ( V_1 -> V_8 , L_83 , V_56 ) ;
goto V_130;
}
if ( ! V_1 -> V_5 . V_64 ) {
V_2 = F_18 ( V_1 -> V_10 , V_129 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_84 , V_2 ) ;
goto V_130;
}
F_16 ( 1000 , 5000 ) ;
}
switch ( V_1 -> type ) {
case V_95 :
V_2 = F_12 ( V_1 -> V_10 ,
V_85 , & V_16 ) ;
if ( V_2 ) {
F_10 ( V_8 ,
L_85 ,
V_2 ) ;
} else if ( V_16 & 0x01 ) {
V_2 = F_29 ( V_1 ) ;
if ( V_2 )
return V_2 ;
}
break;
default:
break;
}
V_2 = F_17 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_86 , V_2 ) ;
goto V_130;
}
V_2 = F_12 ( V_1 -> V_10 , V_129 , & V_56 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_82 , V_2 ) ;
goto V_130;
}
V_2 = F_12 ( V_1 -> V_10 , V_131 ,
& V_1 -> V_132 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_87 , V_2 ) ;
goto V_130;
}
V_1 -> V_132 &= V_133 ;
switch ( V_56 ) {
case 0x5102 :
if ( F_72 ( V_134 ) ) {
V_115 = L_88 ;
if ( V_1 -> type != V_95 ) {
F_73 ( V_1 -> V_8 ,
L_89 ,
V_1 -> type ) ;
V_1 -> type = V_95 ;
}
F_62 = F_43 ;
V_1 -> V_132 &= 0x7 ;
V_117 = V_135 ;
V_118 = F_28 ( V_135 ) ;
}
break;
case 0x5110 :
if ( F_72 ( V_136 ) ) {
switch ( V_1 -> type ) {
case V_65 :
V_115 = L_90 ;
break;
case V_66 :
V_115 = L_91 ;
break;
default:
V_115 = L_90 ;
F_73 ( V_1 -> V_8 ,
L_92 ,
V_1 -> type ) ;
V_1 -> type = V_65 ;
break;
}
F_62 = V_137 ;
V_117 = V_138 ;
V_118 = F_28 ( V_138 ) ;
}
break;
case 0x6363 :
if ( F_72 ( V_139 ) ) {
switch ( V_1 -> type ) {
case V_98 :
V_115 = L_93 ;
break;
case V_97 :
V_115 = L_94 ;
break;
default:
F_73 ( V_1 -> V_8 ,
L_95 ,
V_1 -> type ) ;
V_1 -> type = V_98 ;
break;
}
F_62 = V_140 ;
V_117 = V_141 ;
V_118 = F_28 ( V_141 ) ;
}
break;
case 0x8997 :
if ( F_72 ( V_142 ) ) {
V_115 = L_96 ;
if ( V_1 -> type != V_119 ) {
F_73 ( V_1 -> V_8 ,
L_97 ,
V_1 -> type ) ;
V_1 -> type = V_119 ;
}
F_62 = V_143 ;
V_117 = V_144 ;
V_118 = F_28 ( V_144 ) ;
}
break;
case 0x6349 :
if ( F_72 ( V_145 ) ) {
switch ( V_1 -> type ) {
case V_31 :
V_115 = L_98 ;
break;
case V_32 :
V_115 = L_99 ;
break;
default:
V_115 = L_98 ;
F_73 ( V_1 -> V_8 ,
L_100 ,
V_1 -> type ) ;
V_1 -> type = V_31 ;
}
F_62 = V_146 ;
V_117 = V_147 ;
V_118 = F_28 ( V_147 ) ;
}
break;
default:
F_10 ( V_1 -> V_8 , L_101 , V_56 ) ;
goto V_130;
}
if ( ! V_117 ) {
F_10 ( V_1 -> V_8 ,
L_102 , V_56 ) ;
goto V_130;
}
F_74 ( V_8 , L_103 , V_115 , V_1 -> V_132 + 'A' ) ;
if ( F_62 ) {
V_2 = F_62 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_55 ,
V_2 ) ;
goto V_130;
}
switch ( V_1 -> type ) {
case V_95 :
V_2 = F_25 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_56 ,
V_2 ) ;
goto V_130;
}
break;
case V_65 :
case V_66 :
V_2 = F_26 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_104 ,
V_2 ) ;
goto V_130;
}
break;
default:
break;
}
}
for ( V_59 = 0 ; V_59 < F_28 ( V_1 -> V_5 . V_111 ) ; V_59 ++ ) {
if ( ! V_1 -> V_5 . V_111 [ V_59 ] )
continue;
F_18 ( V_1 -> V_10 , V_148 + V_59 ,
V_1 -> V_5 . V_111 [ V_59 ] ) ;
}
if ( ! V_1 -> V_5 . V_6 )
V_1 -> V_5 . V_6 = V_149 ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
case V_149 :
F_4 ( V_1 -> V_10 , V_11 ,
V_150 ,
V_1 -> V_5 . V_6 - 1 ) ;
F_1 ( V_1 ) ;
break;
case V_151 :
F_4 ( V_1 -> V_10 , V_11 ,
V_150 , 2 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_105 ,
V_1 -> V_5 . V_6 ) ;
V_2 = - V_122 ;
goto V_130;
}
for ( V_59 = 0 ; V_59 < V_152 ; V_59 ++ ) {
if ( ! V_1 -> V_5 . V_153 [ V_59 ] . V_154 &&
! V_1 -> V_5 . V_153 [ V_59 ] . V_155 )
continue;
if ( ! V_1 -> V_5 . V_153 [ V_59 ] . V_154 )
V_1 -> V_5 . V_153 [ V_59 ] . V_154 = 2800 ;
V_16 = ( V_1 -> V_5 . V_153 [ V_59 ] . V_154 - 1500 ) / 100 ;
V_16 <<= V_156 ;
if ( V_1 -> V_5 . V_153 [ V_59 ] . V_157 )
V_16 |= V_158 ;
if ( V_1 -> V_5 . V_153 [ V_59 ] . V_159 )
V_16 |= V_160 ;
if ( V_1 -> V_5 . V_153 [ V_59 ] . V_161 )
V_16 |= V_162 ;
if ( V_1 -> V_5 . V_153 [ V_59 ] . V_155 )
V_16 |= V_163 ;
F_4 ( V_1 -> V_10 ,
V_164 + V_59 ,
V_165 |
V_158 |
V_160 |
V_163 |
V_162 , V_16 ) ;
}
for ( V_59 = 0 ; V_59 < V_166 ; V_59 ++ ) {
V_16 = V_1 -> V_5 . V_113 [ V_59 ]
<< V_167 ;
if ( V_1 -> V_5 . V_112 [ V_59 ] & V_168 )
V_16 |= 1 << V_169 ;
switch ( V_1 -> type ) {
case V_31 :
case V_32 :
F_4 ( V_1 -> V_10 ,
V_170 + ( V_59 * 8 ) ,
V_171 ,
( V_1 -> V_5 . V_112 [ V_59 ] & V_172 )
<< V_173 ) ;
F_4 ( V_1 -> V_10 ,
V_174 + ( V_59 * 8 ) ,
V_175 ,
( V_1 -> V_5 . V_112 [ V_59 ] & V_172 )
<< V_176 ) ;
V_57 = V_177 |
V_178 ;
break;
default:
if ( V_1 -> V_5 . V_112 [ V_59 ] & V_172 )
V_16 |= 1 << V_179 ;
V_57 = V_177 |
V_178 |
V_180 ;
break;
}
F_4 ( V_1 -> V_10 ,
V_181 + ( V_59 * 8 ) ,
V_57 , V_16 ) ;
}
for ( V_59 = 0 ; V_59 < V_182 ; V_59 ++ ) {
if ( V_1 -> V_5 . V_114 [ V_59 ] )
V_16 = V_183 ;
else
V_16 = 0 ;
F_4 ( V_1 -> V_10 ,
V_184 + ( V_59 * 8 ) ,
V_183 , V_16 ) ;
}
for ( V_59 = 0 ; V_59 < V_185 ; V_59 ++ ) {
if ( V_1 -> V_5 . V_186 [ V_59 ] )
F_4 ( V_1 -> V_10 ,
V_187 + ( V_59 * 2 ) ,
V_188 |
V_189 ,
V_1 -> V_5 . V_186 [ V_59 ] ) ;
if ( V_1 -> V_5 . V_190 [ V_59 ] )
F_4 ( V_1 -> V_10 ,
V_191 + ( V_59 * 2 ) ,
V_192 ,
V_1 -> V_5 . V_190 [ V_59 ] ) ;
}
F_75 ( V_1 -> V_8 ) ;
F_76 ( V_1 -> V_8 ) ;
V_2 = F_77 ( V_1 ) ;
if ( V_2 != 0 )
goto V_193;
F_78 ( V_1 -> V_8 , 100 ) ;
F_79 ( V_1 -> V_8 ) ;
F_80 ( V_1 , V_194 , L_106 ,
F_9 , V_1 ) ;
F_80 ( V_1 , V_195 , L_107 ,
F_13 , V_1 ) ;
F_80 ( V_1 , V_196 , L_108 ,
F_11 , V_1 ) ;
V_2 = F_66 ( V_1 -> V_8 , V_197 ,
V_117 , V_118 , NULL , 0 , NULL ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_109 , V_2 ) ;
goto V_198;
}
return 0 ;
V_198:
F_81 ( V_1 ) ;
V_193:
F_82 ( V_1 -> V_8 ) ;
V_130:
F_20 ( V_1 ) ;
F_30 ( V_1 -> V_86 ) ;
V_128:
F_40 ( V_1 -> V_93 ,
V_1 -> V_94 ) ;
V_127:
F_83 ( V_1 -> V_86 ) ;
V_124:
F_84 ( V_8 ) ;
return V_2 ;
}
int F_85 ( struct V_1 * V_1 )
{
F_82 ( V_1 -> V_8 ) ;
F_30 ( V_1 -> V_86 ) ;
F_83 ( V_1 -> V_86 ) ;
F_84 ( V_1 -> V_8 ) ;
F_86 ( V_1 , V_196 , V_1 ) ;
F_86 ( V_1 , V_195 , V_1 ) ;
F_86 ( V_1 , V_194 , V_1 ) ;
F_81 ( V_1 ) ;
F_20 ( V_1 ) ;
F_40 ( V_1 -> V_93 ,
V_1 -> V_94 ) ;
return 0 ;
}

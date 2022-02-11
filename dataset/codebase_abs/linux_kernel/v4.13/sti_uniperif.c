int F_1 ( struct V_1 * V_2 )
{
int V_3 = 10 ;
F_2 ( V_2 ) ;
if ( V_2 -> V_4 < V_5 ) {
while ( F_3 ( V_2 ) && V_3 ) {
F_4 ( 5 ) ;
V_3 -- ;
}
}
if ( ! V_3 ) {
F_5 ( V_2 -> V_6 , L_1 ) ;
return - V_7 ;
}
return 0 ;
}
int F_6 ( struct V_8 * V_9 , unsigned int V_10 ,
unsigned int V_11 , int V_12 ,
int V_13 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_1 * V_2 = V_15 -> V_16 . V_2 ;
int V_17 , V_18 , V_19 ;
if ( ! F_8 ( V_2 ) ) {
F_5 ( V_2 -> V_6 , L_2 ) ;
return - V_20 ;
}
V_2 -> V_21 . V_12 = V_12 ;
V_2 -> V_21 . V_13 = V_13 ;
V_2 -> V_21 . V_22 = ( V_10 != 0 ) ? V_10 : V_11 ;
for ( V_17 = 0 , V_19 = 0 ; V_17 < V_2 -> V_21 . V_12 ; V_17 ++ ) {
if ( ( V_2 -> V_21 . V_22 >> V_17 ) & 0x01 )
V_19 ++ ;
}
V_2 -> V_21 . V_19 = V_19 ;
V_18 = V_2 -> V_21 . V_19 * V_2 -> V_21 . V_13 / 8 ;
if ( ( V_18 > V_23 ) ||
( V_18 & ~ ( int ) V_24 ) ) {
F_5 ( V_2 -> V_6 , L_3 ,
V_18 ) ;
return - V_20 ;
}
return 0 ;
}
int F_9 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_30 V_31 ;
V_31 . V_32 = V_2 -> V_21 . V_19 ;
V_31 . V_33 = V_2 -> V_21 . V_19 ;
V_31 . V_34 = 0 ;
V_31 . V_35 = 0 ;
V_31 . integer = 0 ;
return F_10 ( F_11 ( V_26 , V_28 -> V_36 ) , & V_31 ) ;
}
int F_12 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
struct V_1 * V_2 = V_28 -> V_29 ;
struct V_37 * V_38 = F_13 ( V_26 , V_28 -> V_36 ) ;
T_1 V_39 ;
switch ( V_2 -> V_21 . V_13 ) {
case 16 :
V_39 = V_40 ;
break;
case 32 :
V_39 = V_41 ;
break;
default:
F_5 ( V_2 -> V_6 , L_4 ,
V_2 -> V_21 . V_13 ) ;
return - V_20 ;
}
V_38 -> V_42 [ 0 ] &= ( V_43 ) V_39 ;
V_38 -> V_42 [ 1 ] &= ( V_43 ) ( V_39 >> 32 ) ;
memset ( V_38 -> V_42 + 2 , 0 , ( V_44 - 64 ) / 8 ) ;
if ( ! V_38 -> V_42 [ 0 ] && ! V_38 -> V_42 [ 1 ] )
return - V_20 ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
unsigned int * V_45 )
{
int V_13 = V_2 -> V_21 . V_13 / 8 ;
int V_46 = V_2 -> V_21 . V_12 ;
unsigned int V_47 = V_2 -> V_21 . V_22 ;
int V_17 , V_48 , V_49 ;
unsigned int V_50 [ 4 ] ;
for ( V_17 = 0 , V_48 = 0 , V_49 = 0 ; ( V_17 < V_46 ) && ( V_49 < V_51 ) ; V_17 ++ ) {
if ( ( V_47 >> V_17 ) & 0x01 ) {
V_50 [ V_48 ] = V_17 * V_13 ;
if ( V_13 == 4 ) {
V_50 [ V_48 + 1 ] = V_50 [ V_48 ] + 2 ;
V_48 ++ ;
}
V_48 ++ ;
if ( V_48 > 3 ) {
V_45 [ V_49 ] = V_50 [ 1 ] |
( V_50 [ 0 ] << 8 ) |
( V_50 [ 3 ] << 16 ) |
( V_50 [ 2 ] << 24 ) ;
V_48 = 0 ;
V_49 ++ ;
}
}
}
return 0 ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_1 * V_2 = V_15 -> V_16 . V_2 ;
struct V_52 * V_53 ;
int V_17 ;
if ( ! V_2 -> V_54 )
return 0 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_54 ; V_17 ++ ) {
V_53 = & V_2 -> V_55 [ V_17 ] ;
V_53 -> V_56 = V_2 -> V_57 ;
V_53 -> V_58 = V_2 -> V_57 ;
}
return F_16 ( V_9 , V_2 -> V_55 , V_2 -> V_54 ) ;
}
int F_17 ( struct V_59 * V_60 ,
struct V_25 * V_26 ,
struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_1 * V_2 = V_15 -> V_16 . V_2 ;
struct V_61 * V_62 ;
int V_63 ;
if ( V_2 -> type == V_64 )
V_63 = F_18 ( V_26 ) / 32 ;
else
V_63 = F_19 ( V_26 ) * V_65 ;
V_62 = F_20 ( V_9 , V_60 ) ;
V_62 -> V_66 = V_63 ;
return 0 ;
}
int F_21 ( struct V_8 * V_9 , unsigned int V_67 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
V_15 -> V_16 . V_2 -> V_68 = V_67 ;
return 0 ;
}
static int F_22 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_1 * V_2 = V_15 -> V_16 . V_2 ;
int V_69 ;
if ( V_2 -> V_70 != V_71 ) {
F_5 ( V_2 -> V_6 , L_5 ,
V_72 , ( int ) V_2 -> V_70 ) ;
return - V_73 ;
}
V_69 = F_23 ( V_2 -> V_6 ) ;
if ( V_69 )
F_5 ( V_2 -> V_6 , L_6 ,
V_72 ) ;
return V_69 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_1 * V_2 = V_15 -> V_16 . V_2 ;
int V_69 ;
if ( V_15 -> V_16 . V_74 == V_75 ) {
V_69 = F_25 ( V_2 ) ;
if ( V_69 )
return V_69 ;
}
V_69 = F_26 ( V_2 -> V_6 ) ;
if ( V_69 )
F_5 ( V_2 -> V_6 , L_6 ,
V_72 ) ;
return V_69 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_14 * V_15 = F_7 ( V_9 ) ;
struct V_76 * V_16 = & V_15 -> V_16 ;
if ( V_15 -> V_16 . V_74 == V_75 )
F_28 ( V_9 , & V_16 -> V_62 , NULL ) ;
else
F_28 ( V_9 , NULL , & V_16 -> V_62 ) ;
V_16 -> V_62 . V_77 = V_16 -> V_2 -> V_78 ;
V_16 -> V_62 . V_79 = V_80 ;
return F_15 ( V_9 ) ;
}
static int F_29 ( struct V_81 * V_82 ,
struct V_14 * V_15 )
{
struct V_58 * V_6 = & V_15 -> V_83 -> V_6 ;
struct V_76 * V_16 = & V_15 -> V_16 ;
struct V_84 * V_9 = V_15 -> V_9 ;
struct V_85 * V_74 ;
struct V_1 * V_2 ;
const struct V_86 * V_87 ;
const struct V_88 * V_89 ;
const char * V_90 ;
int V_69 ;
V_87 = F_30 ( V_91 , V_82 ) ;
if ( ! V_87 -> V_92 ) {
F_5 ( V_6 , L_7 ) ;
return - V_20 ;
}
V_89 = (struct V_88 * ) V_87 -> V_92 ;
V_2 = F_31 ( V_6 , sizeof( * V_2 ) , V_93 ) ;
if ( ! V_2 )
return - V_94 ;
V_2 -> V_57 = V_89 -> V_57 ;
V_2 -> V_4 = V_89 -> V_95 ;
* V_9 = V_96 ;
V_9 -> V_97 = V_89 -> V_98 ;
V_2 -> V_99 = F_32 ( V_15 -> V_83 , V_100 , 0 ) ;
if ( ! V_2 -> V_99 ) {
F_5 ( V_6 , L_8 ) ;
return - V_101 ;
}
V_2 -> V_102 = F_33 ( V_6 , V_2 -> V_99 ) ;
if ( F_34 ( V_2 -> V_102 ) )
return F_35 ( V_2 -> V_102 ) ;
V_2 -> V_78 = V_2 -> V_99 -> V_103 +
F_36 ( V_2 ) ;
V_2 -> V_104 = F_37 ( V_15 -> V_83 , 0 ) ;
if ( V_2 -> V_104 < 0 ) {
F_5 ( V_6 , L_9 ) ;
return - V_105 ;
}
V_2 -> type = V_89 -> type ;
if ( V_89 -> type & V_64 ) {
if ( ! F_38 ( V_82 , L_10 , & V_90 ) )
V_2 -> type = V_64 ;
else
V_2 -> type = V_106 ;
}
V_16 -> V_2 = V_2 ;
V_16 -> V_74 = V_89 -> V_74 ;
if ( V_15 -> V_16 . V_74 == V_75 ) {
V_69 = F_39 ( V_15 -> V_83 , V_2 ) ;
V_74 = & V_9 -> V_107 ;
} else {
V_69 = F_40 ( V_15 -> V_83 , V_2 ) ;
V_74 = & V_9 -> V_108 ;
}
if ( V_69 < 0 )
return V_69 ;
V_9 -> V_109 = V_2 -> V_110 ;
V_74 -> V_111 = V_9 -> V_97 ;
V_74 -> V_112 = V_2 -> V_113 -> V_112 ;
V_74 -> V_114 = V_2 -> V_113 -> V_114 ;
V_74 -> V_115 = V_2 -> V_113 -> V_115 ;
V_74 -> V_116 = V_2 -> V_113 -> V_116 ;
return 0 ;
}
static int F_41 ( struct V_117 * V_83 )
{
struct V_14 * V_15 ;
struct V_81 * V_82 = V_83 -> V_6 . V_118 ;
int V_69 ;
V_15 = F_31 ( & V_83 -> V_6 , sizeof( * V_15 ) , V_93 ) ;
if ( ! V_15 )
return - V_94 ;
V_15 -> V_9 = F_31 ( & V_83 -> V_6 , sizeof( * V_15 -> V_9 ) , V_93 ) ;
if ( ! V_15 -> V_9 )
return - V_94 ;
V_15 -> V_83 = V_83 ;
V_69 = F_29 ( V_82 , V_15 ) ;
F_42 ( & V_83 -> V_6 , V_15 ) ;
V_69 = F_43 ( & V_83 -> V_6 ,
& V_119 ,
V_15 -> V_9 , 1 ) ;
if ( V_69 < 0 )
return V_69 ;
return F_44 ( & V_83 -> V_6 ,
& V_120 , 0 ) ;
}

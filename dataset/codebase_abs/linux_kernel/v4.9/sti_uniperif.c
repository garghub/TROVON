int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , int V_5 ,
int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
int V_12 , V_13 , V_14 ;
if ( ! F_3 ( V_10 ) ) {
F_4 ( V_10 -> V_15 , L_1 ) ;
return - V_16 ;
}
V_10 -> V_17 . V_5 = V_5 ;
V_10 -> V_17 . V_6 = V_6 ;
V_10 -> V_17 . V_18 = ( V_3 != 0 ) ? V_3 : V_4 ;
for ( V_12 = 0 , V_14 = 0 ; V_12 < V_10 -> V_17 . V_5 ; V_12 ++ ) {
if ( ( V_10 -> V_17 . V_18 >> V_12 ) & 0x01 )
V_14 ++ ;
}
V_10 -> V_17 . V_14 = V_14 ;
V_13 = V_10 -> V_17 . V_14 * V_10 -> V_17 . V_6 / 8 ;
if ( ( V_13 > V_19 ) ||
( V_13 & ~ ( int ) V_20 ) ) {
F_4 ( V_10 -> V_15 , L_2 ,
V_13 ) ;
return - V_16 ;
}
return 0 ;
}
int F_5 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
struct V_26 V_27 ;
V_27 . V_28 = V_10 -> V_17 . V_14 ;
V_27 . V_29 = V_10 -> V_17 . V_14 ;
V_27 . V_30 = 0 ;
V_27 . V_31 = 0 ;
V_27 . integer = 0 ;
return F_6 ( F_7 ( V_22 , V_24 -> V_32 ) , & V_27 ) ;
}
int F_8 ( struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_9 * V_10 = V_24 -> V_25 ;
struct V_33 * V_34 = F_9 ( V_22 , V_24 -> V_32 ) ;
T_1 V_35 ;
switch ( V_10 -> V_17 . V_6 ) {
case 16 :
V_35 = V_36 ;
break;
case 32 :
V_35 = V_37 ;
break;
default:
F_4 ( V_10 -> V_15 , L_3 ,
V_10 -> V_17 . V_6 ) ;
return - V_16 ;
}
V_34 -> V_38 [ 0 ] &= ( V_39 ) V_35 ;
V_34 -> V_38 [ 1 ] &= ( V_39 ) ( V_35 >> 32 ) ;
memset ( V_34 -> V_38 + 2 , 0 , ( V_40 - 64 ) / 8 ) ;
if ( ! V_34 -> V_38 [ 0 ] && ! V_34 -> V_38 [ 1 ] )
return - V_16 ;
return 0 ;
}
int F_10 ( struct V_9 * V_10 ,
unsigned int * V_41 )
{
int V_6 = V_10 -> V_17 . V_6 / 8 ;
int V_42 = V_10 -> V_17 . V_5 ;
unsigned int V_43 = V_10 -> V_17 . V_18 ;
int V_12 , V_44 , V_45 ;
unsigned int V_46 [ 4 ] ;
for ( V_12 = 0 , V_44 = 0 , V_45 = 0 ; ( V_12 < V_42 ) && ( V_45 < V_47 ) ; V_12 ++ ) {
if ( ( V_43 >> V_12 ) & 0x01 ) {
V_46 [ V_44 ] = V_12 * V_6 ;
if ( V_6 == 4 ) {
V_46 [ V_44 + 1 ] = V_46 [ V_44 ] + 2 ;
V_44 ++ ;
}
V_44 ++ ;
if ( V_44 > 3 ) {
V_41 [ V_45 ] = V_46 [ 1 ] |
( V_46 [ 0 ] << 8 ) |
( V_46 [ 3 ] << 16 ) |
( V_46 [ 2 ] << 24 ) ;
V_44 = 0 ;
V_45 ++ ;
}
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_48 * V_49 ;
int V_12 ;
if ( ! V_10 -> V_50 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_10 -> V_50 ; V_12 ++ ) {
V_49 = & V_10 -> V_51 [ V_12 ] ;
V_49 -> V_52 = V_10 -> V_53 ;
V_49 -> V_54 = V_10 -> V_53 ;
}
return F_12 ( V_2 , V_10 -> V_51 , V_10 -> V_50 ) ;
}
int F_13 ( struct V_55 * V_56 ,
struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_57 * V_58 ;
int V_59 ;
if ( V_10 -> type == V_60 )
V_59 = F_14 ( V_22 ) / 32 ;
else
V_59 = F_15 ( V_22 ) * V_61 ;
V_58 = F_16 ( V_2 , V_56 ) ;
V_58 -> V_62 = V_59 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , unsigned int V_63 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_11 . V_10 -> V_64 = V_63 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
int V_65 ;
if ( V_10 -> V_66 != V_67 ) {
F_4 ( V_10 -> V_15 , L_4 ,
V_68 , ( int ) V_10 -> V_66 ) ;
return - V_69 ;
}
V_65 = F_19 ( V_10 -> V_15 ) ;
if ( V_65 )
F_4 ( V_10 -> V_15 , L_5 ,
V_68 ) ;
return V_65 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
int V_65 ;
if ( V_8 -> V_11 . V_70 == V_71 ) {
V_65 = F_21 ( V_10 ) ;
if ( V_65 )
return V_65 ;
}
V_65 = F_22 ( V_10 -> V_15 ) ;
if ( V_65 )
F_4 ( V_10 -> V_15 , L_5 ,
V_68 ) ;
return V_65 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_72 * V_11 = & V_8 -> V_11 ;
if ( V_8 -> V_11 . V_70 == V_71 )
F_24 ( V_2 , & V_11 -> V_58 , NULL ) ;
else
F_24 ( V_2 , NULL , & V_11 -> V_58 ) ;
V_11 -> V_58 . V_73 = V_11 -> V_10 -> V_74 ;
V_11 -> V_58 . V_75 = V_76 ;
return F_11 ( V_2 ) ;
}
static int F_25 ( struct V_77 * V_78 ,
struct V_7 * V_8 )
{
struct V_54 * V_15 = & V_8 -> V_79 -> V_15 ;
struct V_72 * V_11 = & V_8 -> V_11 ;
struct V_80 * V_2 = V_8 -> V_2 ;
struct V_81 * V_70 ;
struct V_9 * V_10 ;
const struct V_82 * V_83 ;
const struct V_84 * V_85 ;
const char * V_86 ;
V_83 = F_26 ( V_87 , V_78 ) ;
if ( ! V_83 -> V_88 ) {
F_4 ( V_15 , L_6 ) ;
return - V_16 ;
}
V_85 = (struct V_84 * ) V_83 -> V_88 ;
V_10 = F_27 ( V_15 , sizeof( * V_10 ) , V_89 ) ;
if ( ! V_10 )
return - V_90 ;
V_10 -> V_53 = V_85 -> V_53 ;
V_10 -> V_91 = V_85 -> V_92 ;
* V_2 = V_93 ;
V_2 -> V_94 = V_85 -> V_95 ;
V_10 -> V_96 = F_28 ( V_8 -> V_79 , V_97 , 0 ) ;
if ( ! V_10 -> V_96 ) {
F_4 ( V_15 , L_7 ) ;
return - V_98 ;
}
V_10 -> V_99 = F_29 ( V_15 , V_10 -> V_96 ) ;
if ( F_30 ( V_10 -> V_99 ) )
return F_31 ( V_10 -> V_99 ) ;
V_10 -> V_74 = V_10 -> V_96 -> V_100 +
F_32 ( V_10 ) ;
V_10 -> V_101 = F_33 ( V_8 -> V_79 , 0 ) ;
if ( V_10 -> V_101 < 0 ) {
F_4 ( V_15 , L_8 ) ;
return - V_102 ;
}
V_10 -> type = V_85 -> type ;
if ( V_85 -> type & V_60 ) {
if ( ! F_34 ( V_78 , L_9 , & V_86 ) )
V_10 -> type = V_60 ;
else
V_10 -> type = V_103 ;
}
V_11 -> V_10 = V_10 ;
V_11 -> V_70 = V_85 -> V_70 ;
if ( V_8 -> V_11 . V_70 == V_71 ) {
F_35 ( V_8 -> V_79 , V_10 ) ;
V_70 = & V_2 -> V_104 ;
} else {
F_36 ( V_8 -> V_79 , V_10 ) ;
V_70 = & V_2 -> V_105 ;
}
V_2 -> V_106 = V_10 -> V_107 ;
V_70 -> V_108 = V_2 -> V_94 ;
V_70 -> V_109 = V_10 -> V_110 -> V_109 ;
V_70 -> V_111 = V_10 -> V_110 -> V_111 ;
V_70 -> V_112 = V_10 -> V_110 -> V_112 ;
V_70 -> V_113 = V_10 -> V_110 -> V_113 ;
return 0 ;
}
static int F_37 ( struct V_114 * V_79 )
{
struct V_7 * V_8 ;
struct V_77 * V_78 = V_79 -> V_15 . V_115 ;
int V_65 ;
V_8 = F_27 ( & V_79 -> V_15 , sizeof( * V_8 ) , V_89 ) ;
if ( ! V_8 )
return - V_90 ;
V_8 -> V_2 = F_27 ( & V_79 -> V_15 , sizeof( * V_8 -> V_2 ) , V_89 ) ;
if ( ! V_8 -> V_2 )
return - V_90 ;
V_8 -> V_79 = V_79 ;
V_65 = F_25 ( V_78 , V_8 ) ;
F_38 ( & V_79 -> V_15 , V_8 ) ;
V_65 = F_39 ( & V_79 -> V_15 ,
& V_116 ,
V_8 -> V_2 , 1 ) ;
if ( V_65 < 0 )
return V_65 ;
return F_40 ( & V_79 -> V_15 ,
& V_117 , 0 ) ;
}

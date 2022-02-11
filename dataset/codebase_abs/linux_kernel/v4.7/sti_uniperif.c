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
V_49 -> V_52 = V_10 -> V_53 -> V_54 ;
V_49 -> V_55 = V_10 -> V_53 -> V_54 ;
}
return F_12 ( V_2 , V_10 -> V_51 , V_10 -> V_50 ) ;
}
int F_13 ( struct V_56 * V_57 ,
struct V_21 * V_22 ,
struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
struct V_58 * V_59 ;
int V_60 ;
if ( V_10 -> V_53 -> type == V_61 )
V_60 = F_14 ( V_22 ) / 32 ;
else
V_60 = F_15 ( V_22 ) * V_62 ;
V_59 = F_16 ( V_2 , V_57 ) ;
V_59 -> V_63 = V_60 ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , unsigned int V_64 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_8 -> V_11 . V_10 -> V_65 = V_64 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
int V_66 ;
if ( V_10 -> V_67 != V_68 ) {
F_4 ( V_10 -> V_15 , L_4 ,
V_69 , ( int ) V_10 -> V_67 ) ;
return - V_70 ;
}
V_66 = F_19 ( V_10 -> V_15 ) ;
if ( V_66 )
F_4 ( V_10 -> V_15 , L_5 ,
V_69 ) ;
return V_66 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_8 -> V_11 . V_10 ;
int V_66 ;
if ( F_21 ( V_2 -> V_15 -> V_71 , L_6 ) ) {
V_66 = F_22 ( V_10 ) ;
if ( V_66 )
return V_66 ;
}
V_66 = F_23 ( V_10 -> V_15 ) ;
if ( V_66 )
F_4 ( V_10 -> V_15 , L_5 ,
V_69 ) ;
return V_66 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_72 * V_11 = & V_8 -> V_11 ;
if ( F_21 ( V_2 -> V_15 -> V_71 , L_6 ) )
F_25 ( V_2 , & V_11 -> V_59 , NULL ) ;
else
F_25 ( V_2 , NULL , & V_11 -> V_59 ) ;
V_11 -> V_59 . V_73 = V_11 -> V_10 -> V_74 ;
V_11 -> V_59 . V_75 = V_76 ;
return F_11 ( V_2 ) ;
}
static int F_26 ( struct V_77 * V_78 ,
struct V_7 * V_8 )
{
const char * V_79 ;
int V_66 ;
struct V_55 * V_15 = & V_8 -> V_80 -> V_15 ;
struct V_72 * V_11 = & V_8 -> V_11 ;
struct V_81 * V_2 = V_8 -> V_2 ;
struct V_82 * V_83 ;
struct V_9 * V_10 ;
V_10 = F_27 ( V_15 , sizeof( * V_10 ) , V_84 ) ;
if ( ! V_10 )
return - V_85 ;
* V_2 = V_86 ;
V_66 = F_28 ( V_78 , L_7 , & V_79 ) ;
if ( V_66 < 0 ) {
F_4 ( V_15 , L_8 , V_69 ) ;
return - V_16 ;
}
V_2 -> V_87 = V_79 ;
V_10 -> V_88 = F_29 ( V_8 -> V_80 , V_89 , 0 ) ;
if ( ! V_10 -> V_88 ) {
F_4 ( V_15 , L_9 ) ;
return - V_90 ;
}
V_10 -> V_91 = F_30 ( V_15 , V_10 -> V_88 ) ;
if ( F_31 ( V_10 -> V_91 ) )
return F_32 ( V_10 -> V_91 ) ;
V_10 -> V_74 = V_10 -> V_88 -> V_92 +
F_33 ( V_10 ) ;
V_10 -> V_93 = F_34 ( V_8 -> V_80 , 0 ) ;
if ( V_10 -> V_93 < 0 ) {
F_4 ( V_15 , L_10 ) ;
return - V_94 ;
}
V_11 -> V_10 = V_10 ;
if ( F_21 ( V_78 , L_6 ) ) {
F_35 ( V_8 -> V_80 , V_10 ) ;
V_83 = & V_2 -> V_95 ;
} else {
F_36 ( V_8 -> V_80 , V_10 ) ;
V_83 = & V_2 -> V_96 ;
}
V_2 -> V_97 = V_10 -> V_98 ;
V_83 -> V_99 = V_2 -> V_87 ;
V_83 -> V_100 = V_10 -> V_101 -> V_100 ;
V_83 -> V_102 = V_10 -> V_101 -> V_102 ;
V_83 -> V_103 = V_10 -> V_101 -> V_103 ;
V_83 -> V_104 = V_10 -> V_101 -> V_104 ;
return 0 ;
}
static int F_37 ( struct V_105 * V_80 )
{
struct V_7 * V_8 ;
struct V_77 * V_78 = V_80 -> V_15 . V_71 ;
int V_66 ;
V_8 = F_27 ( & V_80 -> V_15 , sizeof( * V_8 ) , V_84 ) ;
if ( ! V_8 )
return - V_85 ;
V_8 -> V_2 = F_27 ( & V_80 -> V_15 , sizeof( * V_8 -> V_2 ) , V_84 ) ;
if ( ! V_8 -> V_2 )
return - V_85 ;
V_8 -> V_80 = V_80 ;
V_66 = F_26 ( V_78 , V_8 ) ;
F_38 ( & V_80 -> V_15 , V_8 ) ;
V_66 = F_39 ( & V_80 -> V_15 ,
& V_106 ,
V_8 -> V_2 , 1 ) ;
if ( V_66 < 0 )
return V_66 ;
return F_40 ( & V_80 -> V_15 ,
& V_107 , 0 ) ;
}

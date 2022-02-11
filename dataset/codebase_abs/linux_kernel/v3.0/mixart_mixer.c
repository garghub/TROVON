static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 , V_5 ;
struct V_6 V_7 ;
struct V_8 V_9 ;
struct V_10 V_11 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_12 = - 1 ;
for( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if( V_3 ) {
V_9 . V_13 [ V_4 ] . V_14 = V_15 [ V_2 -> V_16 [ V_4 ] ] ;
} else {
if( V_2 -> V_17 [ V_4 ] )
V_9 . V_13 [ V_4 ] . V_14 = V_15 [ V_2 -> V_18 [ V_4 ] ] ;
else
V_9 . V_13 [ V_4 ] . V_14 = V_15 [ V_19 ] ;
}
}
if( V_3 ) V_7 . V_20 = V_2 -> V_21 ;
else V_7 . V_20 = V_2 -> V_22 ;
V_7 . V_23 = V_24 ;
V_7 . V_25 = & V_9 ;
V_7 . V_26 = sizeof( V_9 ) ;
V_5 = F_2 ( V_2 -> V_27 , & V_7 , sizeof( V_11 ) , & V_11 ) ;
if( ( V_5 < 0 ) || ( V_11 . V_28 ) ) {
F_3 ( V_29 L_1 , V_2 -> V_30 , V_3 , V_11 . V_28 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_4 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
V_35 -> type = V_36 ;
V_35 -> V_37 = 2 ;
if( V_33 -> V_38 == 0 ) {
V_35 -> V_39 . integer . V_40 = V_19 ;
V_35 -> V_39 . integer . V_41 = V_42 ;
} else {
V_35 -> V_39 . integer . V_40 = V_43 ;
V_35 -> V_39 . integer . V_41 = V_44 ;
}
return 0 ;
}
static int F_5 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
if( V_33 -> V_38 == 0 ) {
V_46 -> V_39 . integer . V_39 [ 0 ] = V_2 -> V_18 [ 0 ] ;
V_46 -> V_39 . integer . V_39 [ 1 ] = V_2 -> V_18 [ 1 ] ;
} else {
V_46 -> V_39 . integer . V_39 [ 0 ] = V_2 -> V_16 [ 0 ] ;
V_46 -> V_39 . integer . V_39 [ 1 ] = V_2 -> V_16 [ 1 ] ;
}
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return 0 ;
}
static int F_9 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
int V_48 = 0 ;
int V_3 , V_4 ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
V_3 = ( V_33 -> V_38 != 0 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
int V_49 = V_46 -> V_39 . integer . V_39 [ V_4 ] ;
int * V_50 = V_3 ?
& V_2 -> V_16 [ V_4 ] :
& V_2 -> V_18 [ V_4 ] ;
if ( V_3 ) {
if ( V_49 < V_43 ||
V_49 > V_44 )
continue;
} else {
if ( V_49 < V_19 ||
V_49 > V_42 )
continue;
}
if ( * V_50 != V_49 ) {
* V_50 = V_49 ;
V_48 = 1 ;
}
}
if ( V_48 )
F_1 ( V_2 , V_3 ) ;
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return V_48 ;
}
static int F_10 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
V_46 -> V_39 . integer . V_39 [ 0 ] = V_2 -> V_17 [ 0 ] ;
V_46 -> V_39 . integer . V_39 [ 1 ] = V_2 -> V_17 [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return 0 ;
}
static int F_11 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
int V_4 , V_48 = 0 ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if ( V_2 -> V_17 [ V_4 ] !=
V_46 -> V_39 . integer . V_39 [ V_4 ] ) {
V_2 -> V_17 [ V_4 ] =
! ! V_46 -> V_39 . integer . V_39 [ V_4 ] ;
V_48 = 1 ;
}
}
if ( V_48 )
F_1 ( V_2 , 0 ) ;
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return V_48 ;
}
int F_12 ( struct V_1 * V_2 , int V_51 , int V_52 )
{
int V_5 , V_4 ;
int V_53 [ 2 ] ;
struct V_6 V_7 ;
struct V_54 V_55 ;
T_1 V_56 ;
struct V_57 * V_58 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_59 = 1 ;
V_55 . V_60 . V_61 . V_62 = V_52 ;
if( V_51 ) {
V_58 = & V_2 -> V_63 ;
V_52 += V_64 ;
} else {
V_58 = & V_2 -> V_65 ;
}
if( V_58 -> V_56 == V_66 )
return 0 ;
V_55 . V_60 . V_61 . V_67 = V_58 -> V_68 ;
for( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if( V_2 -> V_69 [ V_52 ] [ V_4 ] )
V_53 [ V_4 ] = V_2 -> V_70 [ V_52 ] [ V_4 ] ;
else
V_53 [ V_4 ] = V_71 ;
}
V_55 . V_60 . V_72 . V_73 = V_74 | V_75 ;
V_55 . V_60 . V_72 . V_76 = V_77 [ V_53 [ 0 ] ] ;
V_55 . V_60 . V_72 . V_78 = V_77 [ V_53 [ 1 ] ] ;
V_7 . V_23 = V_79 ;
V_7 . V_20 = (struct V_80 ) { 0 , 0 } ;
V_7 . V_25 = & V_55 ;
V_7 . V_26 = sizeof( V_55 ) ;
V_5 = F_2 ( V_2 -> V_27 , & V_7 , sizeof( V_56 ) , & V_56 ) ;
if( ( V_5 < 0 ) || V_56 ) {
F_3 ( V_29 L_2 , V_2 -> V_30 , V_56 ) ;
return - V_31 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , int V_51 )
{
int V_5 , V_4 , V_52 ;
struct V_57 * V_58 ;
struct V_6 V_7 ;
struct V_81 V_55 ;
T_1 V_56 ;
if( V_51 ) {
V_52 = 1 ;
V_58 = & V_2 -> V_82 ;
} else {
V_52 = 0 ;
V_58 = & V_2 -> V_83 ;
}
if( V_58 -> V_56 == V_66 )
return 0 ;
memset ( & V_55 , 0 , sizeof( V_55 ) ) ;
V_55 . V_84 = 2 ;
V_55 . V_13 [ 0 ] . V_85 = V_58 -> V_86 ;
V_55 . V_13 [ 1 ] . V_85 = V_58 -> V_87 ;
for( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_55 . V_13 [ V_4 ] . V_73 = V_88 ;
V_55 . V_13 [ V_4 ] . V_89 = V_77 [ V_2 -> V_90 [ V_52 ] [ V_4 ] ] ;
}
V_7 . V_23 = V_91 ;
V_7 . V_20 = (struct V_80 ) { 0 , 0 } ;
V_7 . V_25 = & V_55 ;
V_7 . V_26 = sizeof( V_55 ) ;
V_5 = F_2 ( V_2 -> V_27 , & V_7 , sizeof( V_56 ) , & V_56 ) ;
if( ( V_5 < 0 ) || V_56 ) {
F_3 ( V_29 L_3 , V_2 -> V_30 , V_56 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_14 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
V_35 -> type = V_36 ;
V_35 -> V_37 = 2 ;
V_35 -> V_39 . integer . V_40 = V_71 ;
V_35 -> V_39 . integer . V_41 = V_92 ;
return 0 ;
}
static int F_15 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
int V_52 = F_16 ( V_33 , & V_46 -> V_93 ) ;
int * V_50 ;
int V_3 = V_33 -> V_38 & V_94 ;
int V_51 = V_33 -> V_38 & V_95 ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
if( V_3 ) {
if( V_51 ) V_50 = V_2 -> V_90 [ 1 ] ;
else V_50 = V_2 -> V_90 [ 0 ] ;
} else {
F_17 ( V_52 >= V_64 ) ;
if( V_51 ) V_50 = V_2 -> V_70 [ V_64 + V_52 ] ;
else V_50 = V_2 -> V_70 [ V_52 ] ;
}
V_46 -> V_39 . integer . V_39 [ 0 ] = V_50 [ 0 ] ;
V_46 -> V_39 . integer . V_39 [ 1 ] = V_50 [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
int V_52 = F_16 ( V_33 , & V_46 -> V_93 ) ;
int V_48 = 0 ;
int V_3 = V_33 -> V_38 & V_94 ;
int V_51 = V_33 -> V_38 & V_95 ;
int * V_50 ;
int V_4 ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
if ( V_3 ) {
if ( V_51 )
V_50 = V_2 -> V_90 [ 1 ] ;
else
V_50 = V_2 -> V_90 [ 0 ] ;
} else {
F_17 ( V_52 >= V_64 ) ;
if ( V_51 )
V_50 = V_2 -> V_70 [ V_64 + V_52 ] ;
else
V_50 = V_2 -> V_70 [ V_52 ] ;
}
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
int V_96 = V_46 -> V_39 . integer . V_39 [ V_4 ] ;
if ( V_96 < V_71 ||
V_96 > V_92 )
continue;
if ( V_50 [ V_4 ] != V_96 ) {
V_50 [ V_4 ] = V_96 ;
V_48 = 1 ;
}
}
if ( V_48 ) {
if ( V_3 )
F_13 ( V_2 , V_51 ) ;
else
F_12 ( V_2 , V_51 , V_52 ) ;
}
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return V_48 ;
}
static int F_19 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
int V_52 = F_16 ( V_33 , & V_46 -> V_93 ) ;
F_17 ( V_52 >= V_64 ) ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
if( V_33 -> V_38 & V_95 )
V_52 += V_64 ;
V_46 -> V_39 . integer . V_39 [ 0 ] = V_2 -> V_69 [ V_52 ] [ 0 ] ;
V_46 -> V_39 . integer . V_39 [ 1 ] = V_2 -> V_69 [ V_52 ] [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return 0 ;
}
static int F_20 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
int V_48 = 0 ;
int V_51 = V_33 -> V_38 & V_95 ;
int V_52 = F_16 ( V_33 , & V_46 -> V_93 ) ;
int V_4 , V_97 ;
F_17 ( V_52 >= V_64 ) ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
V_97 = V_52 ;
if ( V_51 )
V_97 += V_64 ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if ( V_2 -> V_69 [ V_97 ] [ V_4 ] !=
V_46 -> V_39 . integer . V_39 [ V_4 ] ) {
V_2 -> V_69 [ V_97 ] [ V_4 ] =
! ! V_46 -> V_39 . integer . V_39 [ V_4 ] ;
V_48 = 1 ;
}
}
if ( V_48 )
F_12 ( V_2 , V_51 , V_52 ) ;
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return V_48 ;
}
static int F_21 ( struct V_1 * V_2 , int V_12 )
{
int V_5 ;
struct V_6 V_7 ;
struct V_98 V_99 ;
T_1 V_11 ;
if( V_2 -> V_65 . V_56 == V_66 )
return - V_31 ;
if( ! V_12 ) V_7 . V_20 = V_2 -> V_65 . V_86 ;
else V_7 . V_20 = V_2 -> V_65 . V_87 ;
V_7 . V_23 = V_100 ;
V_7 . V_25 = & V_99 ;
V_7 . V_26 = sizeof( V_99 ) ;
memset ( & V_99 , 0 , sizeof( V_99 ) ) ;
V_99 . V_73 = V_101 | V_102 ;
V_99 . V_103 = V_77 [ V_2 -> V_104 [ V_12 != 0 ] ] ;
V_99 . V_105 = ! V_2 -> V_106 [ V_12 != 0 ] ;
V_5 = F_2 ( V_2 -> V_27 , & V_7 , sizeof( V_11 ) , & V_11 ) ;
if( ( V_5 < 0 ) || V_11 ) {
F_3 ( V_29 L_4 , V_2 -> V_30 , V_11 ) ;
return - V_31 ;
}
return 0 ;
}
static int F_22 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
V_46 -> V_39 . integer . V_39 [ 0 ] = V_2 -> V_104 [ 0 ] ;
V_46 -> V_39 . integer . V_39 [ 1 ] = V_2 -> V_104 [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return 0 ;
}
static int F_23 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
int V_48 = 0 ;
int V_4 ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if ( V_2 -> V_104 [ V_4 ] !=
V_46 -> V_39 . integer . V_39 [ V_4 ] ) {
V_2 -> V_104 [ V_4 ] =
! ! V_46 -> V_39 . integer . V_39 [ V_4 ] ;
F_21 ( V_2 , V_4 ) ;
V_48 = 1 ;
}
}
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return V_48 ;
}
static int F_24 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
V_46 -> V_39 . integer . V_39 [ 0 ] = V_2 -> V_106 [ 0 ] ;
V_46 -> V_39 . integer . V_39 [ 1 ] = V_2 -> V_106 [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return 0 ;
}
static int F_25 ( struct V_32 * V_33 , struct V_45 * V_46 )
{
struct V_1 * V_2 = F_6 ( V_33 ) ;
int V_48 = 0 ;
int V_4 ;
F_7 ( & V_2 -> V_27 -> V_47 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if ( V_2 -> V_106 [ V_4 ] !=
V_46 -> V_39 . integer . V_39 [ V_4 ] ) {
V_2 -> V_106 [ V_4 ] =
! ! V_46 -> V_39 . integer . V_39 [ V_4 ] ;
V_48 |= ( 1 << V_4 ) ;
}
}
if ( V_48 ) {
int V_107 = V_2 -> V_106 [ 0 ] ||
V_2 -> V_106 [ 1 ] ;
if ( V_107 ) {
F_26 ( V_2 , V_108 , 0 , 1 ) ;
F_26 ( V_2 , V_108 , 1 , 1 ) ;
}
if ( V_48 & 0x01 )
F_21 ( V_2 , 0 ) ;
if ( V_48 & 0x02 )
F_21 ( V_2 , 1 ) ;
if ( ! V_107 ) {
F_27 ( V_2 -> V_27 ,
& V_2 -> V_83 , 1 ) ;
F_27 ( V_2 -> V_27 ,
& V_2 -> V_65 , 1 ) ;
}
}
F_8 ( & V_2 -> V_27 -> V_47 ) ;
return ( V_48 != 0 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
if( V_2 -> V_30 < 2 ) {
F_1 ( V_2 , 1 ) ;
}
return;
}
int F_29 ( struct V_109 * V_27 )
{
struct V_1 * V_2 ;
int V_5 , V_4 ;
F_30 ( & V_27 -> V_47 ) ;
for( V_4 = 0 ; V_4 < V_27 -> V_110 ; V_4 ++ ) {
struct V_111 V_112 ;
V_2 = V_27 -> V_2 [ V_4 ] ;
V_112 = V_113 ;
V_112 . V_114 = L_5 ;
V_112 . V_38 = 0 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_112 , V_2 ) ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_116 , V_2 ) ) ) < 0 )
return V_5 ;
if( V_4 < 2 ) {
V_112 = V_113 ;
V_112 . V_114 = L_6 ;
V_112 . V_38 = 1 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_112 , V_2 ) ) ) < 0 )
return V_5 ;
}
V_112 = V_117 ;
V_112 . V_114 = L_7 ;
V_112 . V_37 = V_64 ;
V_112 . V_38 = 0 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_112 , V_2 ) ) ) < 0 )
return V_5 ;
V_112 . V_114 = L_8 ;
V_112 . V_37 = 1 ;
V_112 . V_38 = V_94 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_112 , V_2 ) ) ) < 0 )
return V_5 ;
if( V_27 -> V_118 == V_119 ) {
V_112 . V_114 = L_9 ;
V_112 . V_37 = V_64 ;
V_112 . V_38 = V_95 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_112 , V_2 ) ) ) < 0 )
return V_5 ;
V_112 . V_114 = L_10 ;
V_112 . V_37 = 0 ;
V_112 . V_38 = V_94 | V_95 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_112 , V_2 ) ) ) < 0 )
return V_5 ;
}
V_112 = V_120 ;
V_112 . V_114 = L_11 ;
V_112 . V_38 = 0 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_112 , V_2 ) ) ) < 0 )
return V_5 ;
if( V_27 -> V_118 == V_119 ) {
V_112 . V_114 = L_12 ;
V_112 . V_38 = V_95 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_112 , V_2 ) ) ) < 0 )
return V_5 ;
}
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_121 , V_2 ) ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_31 ( V_2 -> V_115 , F_32 ( & V_122 , V_2 ) ) ) < 0 )
return V_5 ;
F_28 ( V_2 ) ;
}
return 0 ;
}

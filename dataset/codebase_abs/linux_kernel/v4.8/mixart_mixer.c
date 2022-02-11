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
F_3 ( V_2 -> V_29 -> V_30 ,
L_1 ,
V_2 -> V_31 , V_3 , V_11 . V_28 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_4 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 2 ;
if( V_34 -> V_39 == 0 ) {
V_36 -> V_40 . integer . V_41 = V_19 ;
V_36 -> V_40 . integer . V_42 = V_43 ;
} else {
V_36 -> V_40 . integer . V_41 = V_44 ;
V_36 -> V_40 . integer . V_42 = V_45 ;
}
return 0 ;
}
static int F_5 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
if( V_34 -> V_39 == 0 ) {
V_47 -> V_40 . integer . V_40 [ 0 ] = V_2 -> V_18 [ 0 ] ;
V_47 -> V_40 . integer . V_40 [ 1 ] = V_2 -> V_18 [ 1 ] ;
} else {
V_47 -> V_40 . integer . V_40 [ 0 ] = V_2 -> V_16 [ 0 ] ;
V_47 -> V_40 . integer . V_40 [ 1 ] = V_2 -> V_16 [ 1 ] ;
}
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return 0 ;
}
static int F_9 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
int V_49 = 0 ;
int V_3 , V_4 ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
V_3 = ( V_34 -> V_39 != 0 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
int V_50 = V_47 -> V_40 . integer . V_40 [ V_4 ] ;
int * V_51 = V_3 ?
& V_2 -> V_16 [ V_4 ] :
& V_2 -> V_18 [ V_4 ] ;
if ( V_3 ) {
if ( V_50 < V_44 ||
V_50 > V_45 )
continue;
} else {
if ( V_50 < V_19 ||
V_50 > V_43 )
continue;
}
if ( * V_51 != V_50 ) {
* V_51 = V_50 ;
V_49 = 1 ;
}
}
if ( V_49 )
F_1 ( V_2 , V_3 ) ;
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return V_49 ;
}
static int F_10 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
V_47 -> V_40 . integer . V_40 [ 0 ] = V_2 -> V_17 [ 0 ] ;
V_47 -> V_40 . integer . V_40 [ 1 ] = V_2 -> V_17 [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return 0 ;
}
static int F_11 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
int V_4 , V_49 = 0 ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if ( V_2 -> V_17 [ V_4 ] !=
V_47 -> V_40 . integer . V_40 [ V_4 ] ) {
V_2 -> V_17 [ V_4 ] =
! ! V_47 -> V_40 . integer . V_40 [ V_4 ] ;
V_49 = 1 ;
}
}
if ( V_49 )
F_1 ( V_2 , 0 ) ;
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return V_49 ;
}
int F_12 ( struct V_1 * V_2 , int V_52 , int V_53 )
{
int V_5 , V_4 ;
int V_54 [ 2 ] ;
struct V_6 V_7 ;
struct V_55 V_56 ;
T_1 V_57 = 0 ;
struct V_58 * V_59 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_60 = 1 ;
V_56 . V_61 . V_62 . V_63 = V_53 ;
if( V_52 ) {
V_59 = & V_2 -> V_64 ;
V_53 += V_65 ;
} else {
V_59 = & V_2 -> V_66 ;
}
if( V_59 -> V_57 == V_67 )
return 0 ;
V_56 . V_61 . V_62 . V_68 = V_59 -> V_69 ;
for( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if( V_2 -> V_70 [ V_53 ] [ V_4 ] )
V_54 [ V_4 ] = V_2 -> V_71 [ V_53 ] [ V_4 ] ;
else
V_54 [ V_4 ] = V_72 ;
}
V_56 . V_61 . V_73 . V_74 = V_75 | V_76 ;
V_56 . V_61 . V_73 . V_77 = V_78 [ V_54 [ 0 ] ] ;
V_56 . V_61 . V_73 . V_79 = V_78 [ V_54 [ 1 ] ] ;
V_7 . V_23 = V_80 ;
V_7 . V_20 = (struct V_81 ) { 0 , 0 } ;
V_7 . V_25 = & V_56 ;
V_7 . V_26 = sizeof( V_56 ) ;
V_5 = F_2 ( V_2 -> V_27 , & V_7 , sizeof( V_57 ) , & V_57 ) ;
if( ( V_5 < 0 ) || V_57 ) {
F_3 ( V_2 -> V_29 -> V_30 ,
L_2 ,
V_2 -> V_31 , V_57 ) ;
return - V_32 ;
}
return 0 ;
}
int F_13 ( struct V_1 * V_2 , int V_52 )
{
int V_5 , V_4 , V_53 ;
struct V_58 * V_59 ;
struct V_6 V_7 ;
struct V_82 V_56 ;
T_1 V_57 = 0 ;
if( V_52 ) {
V_53 = 1 ;
V_59 = & V_2 -> V_83 ;
} else {
V_53 = 0 ;
V_59 = & V_2 -> V_84 ;
}
if( V_59 -> V_57 == V_67 )
return 0 ;
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 . V_85 = 2 ;
V_56 . V_13 [ 0 ] . V_86 = V_59 -> V_87 ;
V_56 . V_13 [ 1 ] . V_86 = V_59 -> V_88 ;
for( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
V_56 . V_13 [ V_4 ] . V_74 = V_89 ;
V_56 . V_13 [ V_4 ] . V_90 = V_78 [ V_2 -> V_91 [ V_53 ] [ V_4 ] ] ;
}
V_7 . V_23 = V_92 ;
V_7 . V_20 = (struct V_81 ) { 0 , 0 } ;
V_7 . V_25 = & V_56 ;
V_7 . V_26 = sizeof( V_56 ) ;
V_5 = F_2 ( V_2 -> V_27 , & V_7 , sizeof( V_57 ) , & V_57 ) ;
if( ( V_5 < 0 ) || V_57 ) {
F_3 ( V_2 -> V_29 -> V_30 ,
L_3 ,
V_2 -> V_31 , V_57 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_14 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
V_36 -> type = V_37 ;
V_36 -> V_38 = 2 ;
V_36 -> V_40 . integer . V_41 = V_72 ;
V_36 -> V_40 . integer . V_42 = V_93 ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
int V_53 = F_16 ( V_34 , & V_47 -> V_94 ) ;
int * V_51 ;
int V_3 = V_34 -> V_39 & V_95 ;
int V_52 = V_34 -> V_39 & V_96 ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
if( V_3 ) {
if( V_52 ) V_51 = V_2 -> V_91 [ 1 ] ;
else V_51 = V_2 -> V_91 [ 0 ] ;
} else {
F_17 ( V_53 >= V_65 ) ;
if( V_52 ) V_51 = V_2 -> V_71 [ V_65 + V_53 ] ;
else V_51 = V_2 -> V_71 [ V_53 ] ;
}
V_47 -> V_40 . integer . V_40 [ 0 ] = V_51 [ 0 ] ;
V_47 -> V_40 . integer . V_40 [ 1 ] = V_51 [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return 0 ;
}
static int F_18 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
int V_53 = F_16 ( V_34 , & V_47 -> V_94 ) ;
int V_49 = 0 ;
int V_3 = V_34 -> V_39 & V_95 ;
int V_52 = V_34 -> V_39 & V_96 ;
int * V_51 ;
int V_4 ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
if ( V_3 ) {
if ( V_52 )
V_51 = V_2 -> V_91 [ 1 ] ;
else
V_51 = V_2 -> V_91 [ 0 ] ;
} else {
F_17 ( V_53 >= V_65 ) ;
if ( V_52 )
V_51 = V_2 -> V_71 [ V_65 + V_53 ] ;
else
V_51 = V_2 -> V_71 [ V_53 ] ;
}
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
int V_97 = V_47 -> V_40 . integer . V_40 [ V_4 ] ;
if ( V_97 < V_72 ||
V_97 > V_93 )
continue;
if ( V_51 [ V_4 ] != V_97 ) {
V_51 [ V_4 ] = V_97 ;
V_49 = 1 ;
}
}
if ( V_49 ) {
if ( V_3 )
F_13 ( V_2 , V_52 ) ;
else
F_12 ( V_2 , V_52 , V_53 ) ;
}
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return V_49 ;
}
static int F_19 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
int V_53 = F_16 ( V_34 , & V_47 -> V_94 ) ;
F_17 ( V_53 >= V_65 ) ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
if( V_34 -> V_39 & V_96 )
V_53 += V_65 ;
V_47 -> V_40 . integer . V_40 [ 0 ] = V_2 -> V_70 [ V_53 ] [ 0 ] ;
V_47 -> V_40 . integer . V_40 [ 1 ] = V_2 -> V_70 [ V_53 ] [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return 0 ;
}
static int F_20 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
int V_49 = 0 ;
int V_52 = V_34 -> V_39 & V_96 ;
int V_53 = F_16 ( V_34 , & V_47 -> V_94 ) ;
int V_4 , V_98 ;
F_17 ( V_53 >= V_65 ) ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
V_98 = V_53 ;
if ( V_52 )
V_98 += V_65 ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if ( V_2 -> V_70 [ V_98 ] [ V_4 ] !=
V_47 -> V_40 . integer . V_40 [ V_4 ] ) {
V_2 -> V_70 [ V_98 ] [ V_4 ] =
! ! V_47 -> V_40 . integer . V_40 [ V_4 ] ;
V_49 = 1 ;
}
}
if ( V_49 )
F_12 ( V_2 , V_52 , V_53 ) ;
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return V_49 ;
}
static int F_21 ( struct V_1 * V_2 , int V_12 )
{
int V_5 ;
struct V_6 V_7 ;
struct V_99 V_100 ;
T_1 V_11 = 0 ;
if( V_2 -> V_66 . V_57 == V_67 )
return - V_32 ;
if( ! V_12 ) V_7 . V_20 = V_2 -> V_66 . V_87 ;
else V_7 . V_20 = V_2 -> V_66 . V_88 ;
V_7 . V_23 = V_101 ;
V_7 . V_25 = & V_100 ;
V_7 . V_26 = sizeof( V_100 ) ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_74 = V_102 | V_103 ;
V_100 . V_104 = V_78 [ V_2 -> V_105 [ V_12 != 0 ] ] ;
V_100 . V_106 = ! V_2 -> V_107 [ V_12 != 0 ] ;
V_5 = F_2 ( V_2 -> V_27 , & V_7 , sizeof( V_11 ) , & V_11 ) ;
if( ( V_5 < 0 ) || V_11 ) {
F_3 ( V_2 -> V_29 -> V_30 ,
L_4 ,
V_2 -> V_31 , V_11 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_22 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
V_47 -> V_40 . integer . V_40 [ 0 ] = V_2 -> V_105 [ 0 ] ;
V_47 -> V_40 . integer . V_40 [ 1 ] = V_2 -> V_105 [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return 0 ;
}
static int F_23 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
int V_49 = 0 ;
int V_4 ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if ( V_2 -> V_105 [ V_4 ] !=
V_47 -> V_40 . integer . V_40 [ V_4 ] ) {
V_2 -> V_105 [ V_4 ] =
! ! V_47 -> V_40 . integer . V_40 [ V_4 ] ;
F_21 ( V_2 , V_4 ) ;
V_49 = 1 ;
}
}
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return V_49 ;
}
static int F_24 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
V_47 -> V_40 . integer . V_40 [ 0 ] = V_2 -> V_107 [ 0 ] ;
V_47 -> V_40 . integer . V_40 [ 1 ] = V_2 -> V_107 [ 1 ] ;
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return 0 ;
}
static int F_25 ( struct V_33 * V_34 , struct V_46 * V_47 )
{
struct V_1 * V_2 = F_6 ( V_34 ) ;
int V_49 = 0 ;
int V_4 ;
F_7 ( & V_2 -> V_27 -> V_48 ) ;
for ( V_4 = 0 ; V_4 < 2 ; V_4 ++ ) {
if ( V_2 -> V_107 [ V_4 ] !=
V_47 -> V_40 . integer . V_40 [ V_4 ] ) {
V_2 -> V_107 [ V_4 ] =
! ! V_47 -> V_40 . integer . V_40 [ V_4 ] ;
V_49 |= ( 1 << V_4 ) ;
}
}
if ( V_49 ) {
int V_108 = V_2 -> V_107 [ 0 ] ||
V_2 -> V_107 [ 1 ] ;
if ( V_108 ) {
F_26 ( V_2 , V_109 , 0 , 1 ) ;
F_26 ( V_2 , V_109 , 1 , 1 ) ;
}
if ( V_49 & 0x01 )
F_21 ( V_2 , 0 ) ;
if ( V_49 & 0x02 )
F_21 ( V_2 , 1 ) ;
if ( ! V_108 ) {
F_27 ( V_2 -> V_27 ,
& V_2 -> V_84 , 1 ) ;
F_27 ( V_2 -> V_27 ,
& V_2 -> V_66 , 1 ) ;
}
}
F_8 ( & V_2 -> V_27 -> V_48 ) ;
return ( V_49 != 0 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_1 ( V_2 , 0 ) ;
if( V_2 -> V_31 < 2 ) {
F_1 ( V_2 , 1 ) ;
}
return;
}
int F_29 ( struct V_110 * V_27 )
{
struct V_1 * V_2 ;
int V_5 , V_4 ;
F_30 ( & V_27 -> V_48 ) ;
for( V_4 = 0 ; V_4 < V_27 -> V_111 ; V_4 ++ ) {
struct V_112 V_113 ;
V_2 = V_27 -> V_2 [ V_4 ] ;
V_113 = V_114 ;
V_113 . V_115 = L_5 ;
V_113 . V_39 = 0 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_113 , V_2 ) ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_116 , V_2 ) ) ) < 0 )
return V_5 ;
if( V_4 < 2 ) {
V_113 = V_114 ;
V_113 . V_115 = L_6 ;
V_113 . V_39 = 1 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_113 , V_2 ) ) ) < 0 )
return V_5 ;
}
V_113 = V_117 ;
V_113 . V_115 = L_7 ;
V_113 . V_38 = V_65 ;
V_113 . V_39 = 0 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_113 , V_2 ) ) ) < 0 )
return V_5 ;
V_113 . V_115 = L_8 ;
V_113 . V_38 = 1 ;
V_113 . V_39 = V_95 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_113 , V_2 ) ) ) < 0 )
return V_5 ;
if( V_27 -> V_118 == V_119 ) {
V_113 . V_115 = L_9 ;
V_113 . V_38 = V_65 ;
V_113 . V_39 = V_96 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_113 , V_2 ) ) ) < 0 )
return V_5 ;
V_113 . V_115 = L_10 ;
V_113 . V_38 = 0 ;
V_113 . V_39 = V_95 | V_96 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_113 , V_2 ) ) ) < 0 )
return V_5 ;
}
V_113 = V_120 ;
V_113 . V_115 = L_11 ;
V_113 . V_39 = 0 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_113 , V_2 ) ) ) < 0 )
return V_5 ;
if( V_27 -> V_118 == V_119 ) {
V_113 . V_115 = L_12 ;
V_113 . V_39 = V_96 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_113 , V_2 ) ) ) < 0 )
return V_5 ;
}
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_121 , V_2 ) ) ) < 0 )
return V_5 ;
if ( ( V_5 = F_31 ( V_2 -> V_29 , F_32 ( & V_122 , V_2 ) ) ) < 0 )
return V_5 ;
F_28 ( V_2 ) ;
}
return 0 ;
}

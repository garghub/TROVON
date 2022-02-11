static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , void * V_5 )
{
return F_2 ( V_2 , V_6 , V_7 ,
0x0000 , V_3 , V_5 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , const void * V_5 )
{
return F_4 ( V_2 , V_8 , V_9 ,
0x0000 , V_3 , V_5 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , void * V_5 )
{
F_6 ( V_2 , V_8 , V_9 ,
0x0000 , V_3 , V_5 , V_4 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned char * V_10 )
{
int V_11 = F_1 ( V_2 , V_12 , V_13 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned char * V_10 )
{
int V_11 = F_3 ( V_2 , V_12 , V_13 , V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 , void * V_16 )
{
int V_11 ;
struct V_1 * V_2 = F_10 ( V_15 ) ;
struct V_17 * V_10 = V_16 ;
if ( F_11 ( V_15 ) )
return - V_18 ;
if ( ! F_12 ( V_10 -> V_19 ) )
return - V_20 ;
V_11 = F_8 ( V_2 , V_10 -> V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
memcpy ( V_15 -> V_21 , V_10 -> V_19 , V_15 -> V_22 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_2 V_3 )
{
int V_11 ;
int V_23 ;
T_3 V_24 ;
T_2 V_25 [ 2 ] = {
V_26 | V_27 ,
V_28 | V_3 ,
} ;
F_14 ( & V_2 -> V_29 ) ;
V_11 = F_3 ( V_2 , V_30 , 2 , V_25 ) ;
if ( V_11 < 0 )
goto V_31;
for ( V_23 = 0 ; V_23 < 10 ; V_23 ++ ) {
V_11 = F_1 ( V_2 , V_30 , 2 , V_25 ) ;
if ( ( V_11 < 0 ) || ( V_25 [ 1 ] & V_32 ) )
break;
V_11 = - V_33 ;
F_15 ( 1 ) ;
}
if ( V_11 < 0 )
goto V_31;
V_11 = F_1 ( V_2 , V_34 , 2 , & V_24 ) ;
if ( V_11 < 0 )
goto V_31;
V_11 = F_16 ( V_24 ) ;
F_17 ( & V_2 -> V_35 -> V_2 , L_1 ,
V_3 , V_24 , V_23 ) ;
V_31:
F_18 ( & V_2 -> V_29 ) ;
return V_11 ;
}
static int F_19 ( struct V_1 * V_2 , T_2 V_3 , T_1 V_24 )
{
int V_11 ;
int V_23 ;
T_3 V_36 ;
T_2 V_25 [ 2 ] = {
V_37 | V_27 ,
V_28 | ( V_3 & 0x1F ) ,
} ;
F_14 ( & V_2 -> V_29 ) ;
V_36 = F_20 ( V_24 ) ;
V_11 = F_3 ( V_2 , V_34 , 2 , & V_36 ) ;
if ( V_11 < 0 )
goto V_31;
V_11 = F_3 ( V_2 , V_30 , 2 , V_25 ) ;
if ( V_11 < 0 )
goto V_31;
for ( V_23 = 0 ; V_23 < 10 ; V_23 ++ ) {
V_11 = F_1 ( V_2 , V_30 , 2 , V_25 ) ;
if ( ( V_11 < 0 ) || ( V_25 [ 1 ] & V_32 ) )
break;
V_11 = - V_33 ;
F_15 ( 1 ) ;
}
if ( V_11 < 0 )
goto V_31;
V_11 = 0 ;
F_17 ( & V_2 -> V_35 -> V_2 , L_2 ,
V_3 , V_24 , V_23 ) ;
V_31:
F_18 ( & V_2 -> V_29 ) ;
return V_11 ;
}
static int F_21 ( struct V_1 * V_2 , int V_38 )
{
int V_11 ;
V_11 = F_19 ( V_2 , V_39 , V_40 ) ;
if ( ! V_11 )
V_11 = F_19 ( V_2 , V_41 , 0x0000 ) ;
if ( ! V_11 )
V_11 = F_19 ( V_2 , V_41 , V_42 ) ;
if ( ! V_11 )
V_11 = F_19 ( V_2 , V_41 ,
V_42 | V_43 ) ;
return V_11 ;
}
static int F_22 ( struct V_1 * V_2 )
{
T_2 V_44 [ 2 ] ;
int V_11 ;
V_11 = F_1 ( V_2 , V_45 , 2 , V_44 ) ;
if ( V_11 > 0 )
return 2 ;
return 1 ;
}
static void F_23 ( struct V_1 * V_2 )
{
T_2 V_46 = V_47 ;
int V_48 ;
for ( V_48 = 0 ; V_48 < 2 ; V_48 ++ ) {
if ( F_22 ( V_2 ) == 2 ) {
F_24 ( & V_2 -> V_35 -> V_2 , L_3 ) ;
F_3 ( V_2 , V_49 ,
1 , & V_46 ) ;
}
F_15 ( 1 ) ;
}
}
static int F_25 ( struct V_14 * V_15 , int V_50 ,
int V_51 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
return F_13 ( V_2 , V_51 ) ;
}
static void F_26 ( struct V_14 * V_15 , int V_50 ,
int V_51 , int V_24 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
F_19 ( V_2 , V_51 , V_24 ) ;
}
static int F_27 ( struct V_14 * V_52 , struct V_53 * V_54 , int V_25 )
{
struct V_1 * V_2 = F_10 ( V_52 ) ;
return F_28 ( & V_2 -> V_55 , F_29 ( V_54 ) , V_25 , NULL ) ;
}
static inline struct V_56 * F_30 ( struct V_1 * V_2 )
{
return (struct V_56 * ) & V_2 -> V_5 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_56 * V_5 = F_30 ( V_2 ) ;
F_5 ( V_2 , V_57 ,
sizeof V_5 -> V_58 ,
V_5 -> V_58 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_56 * V_5 = F_30 ( V_2 ) ;
F_5 ( V_2 , V_59 , 1 , & V_5 -> V_60 ) ;
}
static void F_33 ( struct V_14 * V_52 )
{
struct V_1 * V_2 = F_10 ( V_52 ) ;
struct V_56 * V_5 = F_30 ( V_2 ) ;
memset ( V_5 -> V_58 , 0 , sizeof V_5 -> V_58 ) ;
V_5 -> V_60 = V_61 ;
V_5 -> V_60 |= V_62 ;
if ( V_52 -> V_63 & V_64 ) {
V_5 -> V_60 |= V_65 ;
} else if ( V_52 -> V_63 & V_66 ||
F_34 ( V_52 ) > V_67 ) {
V_5 -> V_60 |= V_62 ;
} else if ( F_35 ( V_52 ) ) {
} else {
struct V_68 * V_69 ;
T_4 V_70 ;
F_36 (ha, net) {
V_70 = F_37 ( V_13 , V_69 -> V_10 ) >> 26 ;
V_5 -> V_58 [ V_70 >> 3 ] |= 1 << ( V_70 & 7 ) ;
}
}
}
static int F_38 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_8 ( V_2 , V_2 -> V_52 -> V_21 ) ;
if ( V_11 ) {
F_24 ( & V_2 -> V_35 -> V_2 , L_4 ) ;
goto V_31;
}
V_11 = F_21 ( V_2 , 0 ) ;
if ( V_11 ) {
F_24 ( & V_2 -> V_35 -> V_2 , L_5 ) ;
goto V_31;
}
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
F_23 ( V_2 ) ;
V_11 = 0 ;
V_31:
return V_11 ;
}
static void F_39 ( struct V_14 * V_52 )
{
struct V_1 * V_2 = F_10 ( V_52 ) ;
F_33 ( V_52 ) ;
F_31 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_40 ( struct V_14 * V_52 )
{
struct V_1 * V_2 = F_10 ( V_52 ) ;
switch ( F_22 ( V_2 ) ) {
case 1 :
return 21 ;
case 2 :
return 32 ;
}
return 0 ;
}
static void F_41 ( struct V_14 * V_52 , struct V_71 * V_72 )
{
F_42 ( V_52 , V_72 ) ;
V_72 -> V_73 = F_40 ( V_52 ) ;
}
static void F_43 ( struct V_14 * V_52 , struct V_74 * V_75 , void * V_5 )
{
struct V_1 * V_2 = F_10 ( V_52 ) ;
V_75 -> V_76 = F_22 ( V_2 ) ;
F_1 ( V_2 , 0 , V_75 -> V_77 , V_5 ) ;
}
static int F_44 ( struct V_1 * V_2 , struct V_78 * V_35 )
{
struct V_14 * V_52 = V_2 -> V_52 ;
int V_11 ;
int V_48 ;
V_11 = - V_79 ;
for ( V_48 = 0 ; V_48 < 5 && V_11 ; V_48 ++ )
V_11 = F_7 ( V_2 , V_52 -> V_21 ) ;
if ( V_11 ) {
F_45 ( & V_2 -> V_35 -> V_2 , L_6 ) ;
goto V_31;
}
F_33 ( V_52 ) ;
V_11 = F_38 ( V_2 ) ;
if ( V_11 )
goto V_31;
V_52 -> V_80 = & V_81 ;
V_52 -> V_82 = & V_83 ;
V_2 -> V_84 = V_85 + 1 ;
V_2 -> V_55 . V_86 = F_25 ;
V_2 -> V_55 . V_87 = F_26 ;
V_2 -> V_55 . V_2 = V_52 ;
V_2 -> V_55 . V_88 = 0x3f ;
V_2 -> V_55 . V_89 = 0x1f ;
V_2 -> V_55 . V_50 = * ( ( T_2 * ) V_52 -> V_21 + 1 ) ;
V_11 = F_46 ( V_2 , V_35 ) ;
V_31:
return V_11 ;
}
static int F_47 ( struct V_1 * V_2 , struct V_90 * V_91 )
{
T_2 V_92 ;
if ( V_91 -> V_77 < V_2 -> V_52 -> V_93 ) {
F_48 ( & V_2 -> V_35 -> V_2 , L_7 ) ;
return 0 ;
}
F_49 ( V_91 , V_91 -> V_77 - 1 ) ;
V_92 = V_91 -> V_5 [ V_91 -> V_77 ] ;
if ( V_92 != V_94 ) {
F_17 ( & V_2 -> V_35 -> V_2 , L_8 , V_92 ) ;
V_2 -> V_52 -> V_95 . V_96 ++ ;
if ( V_92 & ( V_97
| V_98
| V_99 ) )
V_2 -> V_52 -> V_95 . V_100 ++ ;
if ( V_92 & V_101 )
V_2 -> V_52 -> V_95 . V_102 ++ ;
if ( V_92 & V_103 )
V_2 -> V_52 -> V_95 . V_104 ++ ;
}
return V_91 -> V_77 > 0 ;
}
static void F_50 ( struct V_1 * V_2 , struct V_105 * V_105 )
{
T_2 * V_106 = V_105 -> V_107 ;
bool V_108 , V_109 ;
if ( V_105 -> V_110 < 16 )
return;
V_108 = ! ( V_106 [ 1 ] == 0x20 ) ;
V_109 = F_51 ( V_2 -> V_52 ) != V_108 ;
if ( V_109 ) {
F_52 ( V_2 , V_108 , 0 ) ;
F_53 ( V_2 -> V_52 , L_9 , V_108 ) ;
}
}
static int F_54 ( struct V_78 * V_111 )
{
struct V_1 * V_2 = F_55 ( V_111 ) ;
F_38 ( V_2 ) ;
F_56 ( V_111 ) ;
return 0 ;
}

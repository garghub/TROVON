static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_3 ( V_4 -> V_10 ) ;
if ( V_7 == NULL || V_7 -> V_11 == NULL )
return;
V_9 = V_7 -> V_12 ;
if ( V_9 == NULL )
return;
if ( V_7 -> V_11 -> V_13 & V_14 )
F_4 ( V_9 ,
V_15 ) ;
else
F_4 ( V_9 ,
V_16 |
V_17 |
V_18 ) ;
}
static void F_5 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
F_7 ( & V_21 -> V_5 ) ;
}
static int F_8 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_23 = V_21 -> V_10 ;
int V_24 = 0 ;
V_24 = F_9 ( V_23 ) ;
if ( V_24 != 0 ) {
F_10 ( V_20 , L_1 , V_24 ) ;
return V_24 ;
}
F_11 ( V_20 ) ;
return V_24 ;
}
static int F_12 ( struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_22 * V_23 = V_21 -> V_10 ;
int V_24 ;
F_13 ( V_20 ) ;
F_14 ( & V_21 -> V_5 ) ;
V_24 = F_15 ( V_23 ) ;
if ( V_24 != 0 )
F_10 ( V_20 , L_2 , V_24 ) ;
return V_24 ;
}
static void F_16 ( void * V_25 )
{
struct V_26 * V_27 = (struct V_26 * ) V_25 ;
struct V_28 * V_29 = (struct V_28 * )
( unsigned long ) V_27 -> V_30 . V_31 . V_32 ;
F_17 ( V_27 ) ;
if ( V_29 )
F_18 ( V_29 ) ;
}
static int F_19 ( struct V_28 * V_29 , struct V_19 * V_20 )
{
struct V_3 * V_21 = F_6 ( V_20 ) ;
struct V_26 * V_27 ;
int V_24 ;
unsigned int V_33 , V_34 , V_35 ;
V_35 = ( ( ( unsigned long ) V_29 -> V_36 + F_20 ( V_29 ) - 1 )
>> V_37 ) - ( ( unsigned long ) V_29 -> V_36 >> V_37 ) + 1 ;
V_34 = F_21 ( V_29 ) -> V_38 + V_35 + 2 ;
V_27 = F_22 ( sizeof( struct V_26 ) +
( V_34 * sizeof( struct V_39 ) ) +
sizeof( struct V_40 ) +
V_41 , V_42 ) ;
if ( ! V_27 ) {
F_10 ( V_20 , L_3 ) ;
F_23 ( V_29 ) ;
V_20 -> V_43 . V_44 ++ ;
return V_45 ;
}
V_27 -> V_46 = V_29 -> V_46 ;
V_27 -> V_12 = ( void * ) ( unsigned long ) V_27 +
sizeof( struct V_26 ) +
( V_34 * sizeof( struct V_39 ) ) ;
V_27 -> V_47 = V_34 - 1 ;
V_27 -> V_48 = V_29 -> V_49 ;
V_27 -> V_50 [ 1 ] . V_51 = F_24 ( V_29 -> V_36 ) >> V_37 ;
V_27 -> V_50 [ 1 ] . V_52
= ( unsigned long ) V_29 -> V_36 & ( V_53 - 1 ) ;
if ( V_35 == 1 )
V_27 -> V_50 [ 1 ] . V_49 = F_20 ( V_29 ) ;
else
V_27 -> V_50 [ 1 ] . V_49 = V_53
- V_27 -> V_50 [ 1 ] . V_52 ;
for ( V_33 = 2 ; V_33 <= V_35 ; V_33 ++ ) {
V_27 -> V_50 [ V_33 ] . V_51 = F_24 ( V_29 -> V_36
+ V_53 * ( V_33 - 1 ) ) >> V_37 ;
V_27 -> V_50 [ V_33 ] . V_52 = 0 ;
V_27 -> V_50 [ V_33 ] . V_49 = V_53 ;
}
if ( V_35 > 1 )
V_27 -> V_50 [ V_35 ] . V_49 = ( ( ( unsigned long ) V_29 -> V_36
+ F_20 ( V_29 ) - 1 ) & ( V_53 - 1 ) ) + 1 ;
for ( V_33 = 0 ; V_33 < F_21 ( V_29 ) -> V_38 ; V_33 ++ ) {
const T_1 * V_54 = & F_21 ( V_29 ) -> V_55 [ V_33 ] ;
V_27 -> V_50 [ V_33 + V_35 + 1 ] . V_51 =
F_25 ( F_26 ( V_54 ) ) ;
V_27 -> V_50 [ V_33 + V_35 + 1 ] . V_52 = V_54 -> V_56 ;
V_27 -> V_50 [ V_33 + V_35 + 1 ] . V_49 = F_27 ( V_54 ) ;
}
V_27 -> V_30 . V_31 . V_57 = F_16 ;
V_27 -> V_30 . V_31 . V_58 = V_27 ;
V_27 -> V_30 . V_31 . V_32 = ( unsigned long ) V_29 ;
V_24 = F_28 ( V_21 -> V_10 ,
V_27 ) ;
if ( V_24 == 0 ) {
V_20 -> V_43 . V_59 += V_29 -> V_49 ;
V_20 -> V_43 . V_60 ++ ;
} else {
F_17 ( V_27 ) ;
if ( V_24 != - V_61 ) {
F_18 ( V_29 ) ;
V_20 -> V_43 . V_44 ++ ;
}
}
return ( V_24 == - V_61 ) ? V_62 : V_45 ;
}
void F_29 ( struct V_22 * V_23 ,
unsigned int V_63 )
{
struct V_19 * V_20 ;
struct V_3 * V_64 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_23 ) ;
V_20 = V_19 -> V_11 ;
if ( ! V_20 ) {
F_10 ( V_20 , L_4
L_5 ) ;
return;
}
if ( V_63 == 1 ) {
F_30 ( V_20 ) ;
V_64 = F_6 ( V_20 ) ;
F_31 ( & V_64 -> V_65 , 0 ) ;
F_31 ( & V_64 -> V_65 , F_32 ( 20 ) ) ;
} else {
F_33 ( V_20 ) ;
}
}
int F_34 ( struct V_22 * V_23 ,
struct V_26 * V_27 )
{
struct V_19 * V_20 ;
struct V_28 * V_29 ;
V_20 = ( (struct V_6 * ) F_3 ( V_23 ) ) -> V_11 ;
if ( ! V_20 || V_20 -> V_66 != V_67 ) {
V_27 -> V_63 = V_68 ;
return 0 ;
}
V_29 = F_35 ( V_20 , V_27 -> V_48 ) ;
if ( F_36 ( ! V_29 ) ) {
++ V_20 -> V_43 . V_69 ;
V_27 -> V_63 = V_68 ;
return 0 ;
}
memcpy ( F_37 ( V_29 , V_27 -> V_48 ) , V_27 -> V_36 ,
V_27 -> V_48 ) ;
V_29 -> V_70 = F_38 ( V_29 , V_20 ) ;
V_29 -> V_71 = V_72 ;
if ( V_27 -> V_46 & V_73 )
F_39 ( V_29 , F_40 ( V_74 ) ,
V_27 -> V_46 ) ;
V_20 -> V_43 . V_75 ++ ;
V_20 -> V_43 . V_76 += V_27 -> V_48 ;
F_41 ( V_29 ) ;
return 0 ;
}
static void F_42 ( struct V_19 * V_20 ,
struct V_77 * V_78 )
{
F_43 ( V_78 -> V_79 , V_80 , sizeof( V_78 -> V_79 ) ) ;
F_43 ( V_78 -> V_81 , L_6 , sizeof( V_78 -> V_81 ) ) ;
}
static int F_44 ( struct V_19 * V_11 , int V_82 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_83 = V_4 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_83 ) ;
struct V_84 V_85 ;
int V_86 = V_87 ;
if ( V_7 == NULL || V_7 -> V_88 )
return - V_89 ;
if ( V_7 -> V_90 == V_91 )
V_86 = V_92 ;
if ( V_82 < 68 || V_82 > V_86 )
return - V_93 ;
V_7 -> V_94 = true ;
F_14 ( & V_4 -> V_5 ) ;
F_13 ( V_11 ) ;
F_45 ( V_83 ) ;
V_11 -> V_82 = V_82 ;
V_4 -> V_10 = V_83 ;
F_46 ( V_83 , V_11 ) ;
V_85 . V_95 = V_95 ;
F_47 ( V_83 , & V_85 ) ;
F_48 ( V_11 ) ;
return 0 ;
}
static int F_49 ( struct V_19 * V_11 , void * V_96 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_83 = V_4 -> V_10 ;
struct V_97 * V_98 = V_96 ;
char V_99 [ V_100 ] ;
unsigned char V_101 ;
int V_102 ;
memcpy ( V_99 , V_11 -> V_103 , V_100 ) ;
V_101 = V_11 -> V_104 ;
V_102 = F_50 ( V_11 , V_96 ) ;
if ( V_102 != 0 )
return V_102 ;
V_102 = F_51 ( V_83 , V_98 -> V_105 ) ;
if ( V_102 != 0 ) {
memcpy ( V_11 -> V_103 , V_99 , V_100 ) ;
V_11 -> V_104 = V_101 ;
}
return V_102 ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_64 ;
struct V_19 * V_20 ;
struct V_6 * V_19 ;
V_64 = F_2 ( V_2 , struct V_3 , V_65 . V_5 ) ;
V_19 = F_3 ( V_64 -> V_10 ) ;
V_20 = V_19 -> V_11 ;
F_53 ( V_20 ) ;
}
static int F_54 ( struct V_22 * V_106 ,
const struct V_107 * V_108 )
{
struct V_19 * V_20 = NULL ;
struct V_3 * V_21 ;
struct V_84 V_85 ;
int V_24 ;
V_20 = F_55 ( sizeof( struct V_3 ) ) ;
if ( ! V_20 )
return - V_109 ;
F_33 ( V_20 ) ;
V_21 = F_6 ( V_20 ) ;
V_21 -> V_10 = V_106 ;
F_46 ( V_106 , V_20 ) ;
F_56 ( & V_21 -> V_65 , F_52 ) ;
F_57 ( & V_21 -> V_5 , F_1 ) ;
V_20 -> V_110 = & V_111 ;
V_20 -> V_112 = 0 ;
V_20 -> V_113 = V_114 ;
F_58 ( V_20 , & V_115 ) ;
F_59 ( V_20 , & V_106 -> V_116 ) ;
V_85 . V_95 = V_95 ;
V_24 = F_47 ( V_106 , & V_85 ) ;
if ( V_24 != 0 ) {
F_10 ( V_20 , L_7 , V_24 ) ;
F_60 ( V_20 ) ;
F_46 ( V_106 , NULL ) ;
return V_24 ;
}
memcpy ( V_20 -> V_103 , V_85 . V_117 , V_100 ) ;
F_30 ( V_20 ) ;
V_24 = F_61 ( V_20 ) ;
if ( V_24 != 0 ) {
F_62 ( L_8 ) ;
F_45 ( V_106 ) ;
F_60 ( V_20 ) ;
}
return V_24 ;
}
static int F_63 ( struct V_22 * V_106 )
{
struct V_19 * V_20 ;
struct V_3 * V_64 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_106 ) ;
V_20 = V_19 -> V_11 ;
if ( V_20 == NULL ) {
F_64 ( & V_106 -> V_116 , L_9 ) ;
return 0 ;
}
V_19 -> V_94 = true ;
V_64 = F_6 ( V_20 ) ;
F_65 ( & V_64 -> V_65 ) ;
F_14 ( & V_64 -> V_5 ) ;
F_13 ( V_20 ) ;
F_66 ( V_20 ) ;
F_45 ( V_106 ) ;
F_60 ( V_20 ) ;
return 0 ;
}
static void T_2 F_67 ( void )
{
F_68 ( & V_118 ) ;
}
static int T_3 F_69 ( void )
{
if ( V_95 < V_119 ) {
V_95 = V_119 ;
F_70 ( L_10 ,
V_95 ) ;
}
return F_71 ( & V_118 ) ;
}

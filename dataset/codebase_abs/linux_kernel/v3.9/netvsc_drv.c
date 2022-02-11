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
if ( ! V_20 ) {
F_10 ( V_20 , L_6
L_7 ) ;
V_27 -> V_63 = V_66 ;
return 0 ;
}
V_29 = F_35 ( V_20 , V_27 -> V_48 ) ;
if ( F_36 ( ! V_29 ) ) {
++ V_20 -> V_43 . V_67 ;
V_27 -> V_63 = V_66 ;
return 0 ;
}
memcpy ( F_37 ( V_29 , V_27 -> V_48 ) , V_27 -> V_36 ,
V_27 -> V_48 ) ;
V_29 -> V_68 = F_38 ( V_29 , V_20 ) ;
V_29 -> V_69 = V_70 ;
V_29 -> V_46 = V_27 -> V_46 ;
V_20 -> V_43 . V_71 ++ ;
V_20 -> V_43 . V_72 += V_27 -> V_48 ;
F_39 ( V_29 ) ;
return 0 ;
}
static void F_40 ( struct V_19 * V_20 ,
struct V_73 * V_74 )
{
F_41 ( V_74 -> V_75 , V_76 , sizeof( V_74 -> V_75 ) ) ;
F_41 ( V_74 -> V_77 , V_78 , sizeof( V_74 -> V_77 ) ) ;
F_41 ( V_74 -> V_79 , L_8 , sizeof( V_74 -> V_79 ) ) ;
}
static int F_42 ( struct V_19 * V_11 , int V_80 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_81 = V_4 -> V_10 ;
struct V_6 * V_7 = F_3 ( V_81 ) ;
struct V_82 V_83 ;
int V_84 = V_85 ;
if ( V_7 == NULL || V_7 -> V_86 )
return - V_87 ;
if ( V_7 -> V_88 == V_89 )
V_84 = V_90 ;
if ( V_80 < 68 || V_80 > V_84 )
return - V_91 ;
V_7 -> V_92 = true ;
F_43 ( & V_4 -> V_65 ) ;
F_14 ( & V_4 -> V_5 ) ;
F_13 ( V_11 ) ;
F_44 ( V_81 ) ;
V_11 -> V_80 = V_80 ;
V_4 -> V_10 = V_81 ;
F_45 ( V_81 , V_11 ) ;
V_83 . V_93 = V_93 ;
F_46 ( V_81 , & V_83 ) ;
F_47 ( V_11 ) ;
return 0 ;
}
static int F_48 ( struct V_19 * V_11 , void * V_94 )
{
struct V_3 * V_4 = F_6 ( V_11 ) ;
struct V_22 * V_81 = V_4 -> V_10 ;
struct V_95 * V_96 = V_94 ;
char V_97 [ V_98 ] ;
unsigned char V_99 ;
int V_100 ;
memcpy ( V_97 , V_11 -> V_101 , V_98 ) ;
V_99 = V_11 -> V_102 ;
V_100 = F_49 ( V_11 , V_94 ) ;
if ( V_100 != 0 )
return V_100 ;
V_100 = F_50 ( V_81 , V_96 -> V_103 ) ;
if ( V_100 != 0 ) {
memcpy ( V_11 -> V_101 , V_97 , V_98 ) ;
V_11 -> V_102 = V_99 ;
}
return V_100 ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_64 ;
struct V_19 * V_20 ;
struct V_6 * V_19 ;
V_64 = F_2 ( V_2 , struct V_3 , V_65 . V_5 ) ;
V_19 = F_3 ( V_64 -> V_10 ) ;
V_20 = V_19 -> V_11 ;
F_52 ( V_20 ) ;
}
static int F_53 ( struct V_22 * V_104 ,
const struct V_105 * V_106 )
{
struct V_19 * V_20 = NULL ;
struct V_3 * V_21 ;
struct V_82 V_83 ;
int V_24 ;
V_20 = F_54 ( sizeof( struct V_3 ) ) ;
if ( ! V_20 )
return - V_107 ;
F_33 ( V_20 ) ;
V_21 = F_6 ( V_20 ) ;
V_21 -> V_10 = V_104 ;
F_45 ( V_104 , V_20 ) ;
F_55 ( & V_21 -> V_65 , F_51 ) ;
F_56 ( & V_21 -> V_5 , F_1 ) ;
V_20 -> V_108 = & V_109 ;
V_20 -> V_110 = V_111 ;
V_20 -> V_112 = V_111 | V_113 ;
F_57 ( V_20 , & V_114 ) ;
F_58 ( V_20 , & V_104 -> V_115 ) ;
V_24 = F_59 ( V_20 ) ;
if ( V_24 != 0 ) {
F_60 ( L_9 ) ;
F_61 ( V_20 ) ;
goto V_116;
}
V_83 . V_93 = V_93 ;
V_24 = F_46 ( V_104 , & V_83 ) ;
if ( V_24 != 0 ) {
F_10 ( V_20 , L_10 , V_24 ) ;
F_62 ( V_20 ) ;
F_61 ( V_20 ) ;
F_45 ( V_104 , NULL ) ;
return V_24 ;
}
memcpy ( V_20 -> V_101 , V_83 . V_117 , V_98 ) ;
F_30 ( V_20 ) ;
V_116:
return V_24 ;
}
static int F_63 ( struct V_22 * V_104 )
{
struct V_19 * V_20 ;
struct V_3 * V_64 ;
struct V_6 * V_19 ;
V_19 = F_3 ( V_104 ) ;
V_20 = V_19 -> V_11 ;
if ( V_20 == NULL ) {
F_64 ( & V_104 -> V_115 , L_11 ) ;
return 0 ;
}
V_19 -> V_92 = true ;
V_64 = F_6 ( V_20 ) ;
F_43 ( & V_64 -> V_65 ) ;
F_14 ( & V_64 -> V_5 ) ;
F_13 ( V_20 ) ;
F_62 ( V_20 ) ;
F_44 ( V_104 ) ;
F_61 ( V_20 ) ;
return 0 ;
}
static void T_2 F_65 ( void )
{
F_66 ( & V_118 ) ;
}
static int T_3 F_67 ( void )
{
if ( V_93 < V_119 ) {
V_93 = V_119 ;
F_68 ( L_12 ,
V_93 ) ;
}
return F_69 ( & V_118 ) ;
}

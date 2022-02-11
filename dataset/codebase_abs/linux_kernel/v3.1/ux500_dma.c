static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_8 = V_7 -> V_8 ;
unsigned long V_9 ;
F_3 ( V_8 -> V_10 , L_1 ,
V_7 -> V_11 ) ;
F_4 ( & V_8 -> V_12 , V_9 ) ;
V_4 -> V_13 . V_14 = V_4 -> V_15 ;
V_4 -> V_13 . V_16 = V_17 ;
F_5 ( V_8 , V_7 -> V_11 ,
V_4 -> V_18 ) ;
F_6 ( & V_8 -> V_12 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_8 = V_7 -> V_8 ;
unsigned long V_9 ;
F_3 ( V_8 -> V_10 , L_2 ,
V_7 -> V_11 ) ;
F_4 ( & V_8 -> V_12 , V_9 ) ;
V_4 -> V_13 . V_14 = V_4 -> V_15 ;
V_4 -> V_13 . V_16 = V_17 ;
F_5 ( V_8 , V_7 -> V_11 ,
V_4 -> V_18 ) ;
F_6 ( & V_8 -> V_12 , V_9 ) ;
}
void F_8 ( void * V_19 )
{
struct V_20 * V_13 = (struct V_20 * ) V_19 ;
struct V_3 * V_4 = V_13 -> V_19 ;
F_9 ( & V_4 -> V_5 ) ;
}
static bool F_10 ( struct V_20 * V_13 ,
T_1 V_21 , T_2 V_22 ,
T_3 V_23 , T_4 V_24 )
{
struct V_3 * V_4 = V_13 -> V_19 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_25 * V_25 = V_4 -> V_25 ;
struct V_26 * V_27 ;
enum V_28 V_29 ;
struct V_30 V_31 ;
struct V_32 V_33 ;
enum V_34 V_35 ;
T_3 V_36 = ( F_11 ( V_7 -> V_11 ) +
V_4 -> V_10 -> V_37 ) ;
struct V_8 * V_8 = V_4 -> V_10 -> V_19 ;
F_3 ( V_8 -> V_10 ,
L_3 ,
V_21 , V_22 , V_23 , V_24 , V_4 -> V_18 ) ;
V_4 -> V_15 = V_24 ;
F_12 ( & V_31 , 1 ) ;
F_13 ( & V_31 , F_14 ( F_15 ( V_23 ) ) , V_24 ,
F_16 ( V_23 ) ) ;
F_17 ( & V_31 ) = V_23 ;
F_18 ( & V_31 ) = V_24 ;
V_29 = V_4 -> V_18 ? V_38 : V_39 ;
V_35 = ( V_24 & 0x3 ) ? V_40 :
V_41 ;
V_33 . V_29 = V_29 ;
V_33 . V_42 = V_36 ;
V_33 . V_43 = V_35 ;
V_33 . V_44 = 16 ;
V_33 . V_45 = V_36 ;
V_33 . V_46 = V_35 ;
V_33 . V_47 = 16 ;
V_25 -> V_48 -> V_49 ( V_25 , V_50 ,
( unsigned long ) & V_33 ) ;
V_27 = V_25 -> V_48 ->
V_51 ( V_25 , & V_31 , 1 , V_29 ,
V_52 | V_53 ) ;
if ( ! V_27 )
return false ;
V_27 -> V_54 = F_8 ;
V_27 -> V_55 = V_13 ;
V_4 -> V_56 = V_27 -> V_57 ( V_27 ) ;
F_19 ( V_25 ) ;
return true ;
}
static struct V_20 * F_20 ( struct V_58 * V_59 ,
struct V_6 * V_7 , T_2 V_18 )
{
struct V_60 * V_10 = F_2 ( V_59 ,
struct V_60 , V_10 ) ;
struct V_3 * V_4 = NULL ;
struct V_8 * V_8 = V_10 -> V_19 ;
T_2 V_61 = V_7 -> V_11 - 1 ;
T_4 V_62 ;
if ( V_61 > 7 )
V_61 -= 8 ;
V_62 = V_18 ? V_10 -> V_63 :
V_10 -> V_64 ;
if ( V_61 >= V_62 )
return NULL ;
V_4 = V_18 ? & ( V_10 -> V_65 [ V_61 ] ) :
& ( V_10 -> V_66 [ V_61 ] ) ;
if ( V_4 -> V_67 )
return NULL ;
V_4 -> V_7 = V_7 ;
V_4 -> V_67 = 1 ;
F_3 ( V_8 -> V_10 , L_4 ,
V_7 -> V_11 , V_18 , V_61 ) ;
return & ( V_4 -> V_13 ) ;
}
static void F_21 ( struct V_20 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_19 ;
struct V_8 * V_8 = V_4 -> V_10 -> V_19 ;
F_3 ( V_8 -> V_10 , L_5 , V_4 -> V_61 ) ;
if ( V_4 -> V_67 ) {
V_4 -> V_67 = 0 ;
V_13 -> V_16 = V_17 ;
V_13 -> V_14 = 0 ;
}
}
static int F_22 ( struct V_20 * V_13 ,
T_1 V_68 , void * V_69 , T_4 V_70 )
{
if ( ( V_68 & 0x3 ) ||
( ( int ) V_69 & 0x3 ) ||
( V_70 < 512 ) ||
( V_70 & 0x3 ) )
return false ;
else
return true ;
}
static int F_23 ( struct V_20 * V_13 ,
T_1 V_21 , T_2 V_22 ,
T_3 V_23 , T_4 V_24 )
{
int V_71 ;
F_24 ( V_13 -> V_16 == V_72 ||
V_13 -> V_16 == V_73 ) ;
if ( ! F_22 ( V_13 , V_21 , ( void * ) V_23 , V_24 ) )
return false ;
V_13 -> V_16 = V_73 ;
V_13 -> V_14 = 0 ;
V_71 = F_10 ( V_13 , V_21 , V_22 , V_23 , V_24 ) ;
if ( ! V_71 )
V_13 -> V_16 = V_17 ;
return V_71 ;
}
static int F_25 ( struct V_20 * V_13 )
{
struct V_3 * V_4 = V_13 -> V_19 ;
struct V_60 * V_10 = V_4 -> V_10 ;
struct V_8 * V_8 = V_10 -> V_19 ;
void T_5 * V_74 = V_8 -> V_75 [ V_4 -> V_7 -> V_11 ] . V_76 ;
T_1 V_77 ;
F_3 ( V_8 -> V_10 , L_6 ,
V_4 -> V_61 , V_4 -> V_18 ) ;
if ( V_13 -> V_16 == V_73 ) {
if ( V_4 -> V_18 ) {
V_77 = F_26 ( V_74 , V_78 ) ;
V_77 &= ~ ( V_79 |
V_80 |
V_81 ) ;
F_27 ( V_74 , V_78 , V_77 ) ;
} else {
V_77 = F_26 ( V_74 , V_82 ) ;
V_77 &= ~ ( V_83 |
V_84 |
V_85 ) ;
F_27 ( V_74 , V_82 , V_77 ) ;
}
V_4 -> V_25 -> V_48 ->
V_49 ( V_4 -> V_25 ,
V_86 , 0 ) ;
V_13 -> V_16 = V_17 ;
}
return 0 ;
}
static int F_28 ( struct V_58 * V_59 )
{
struct V_60 * V_10 = F_2 ( V_59 ,
struct V_60 , V_10 ) ;
struct V_3 * V_4 ;
struct V_20 * V_13 ;
T_2 V_61 ;
for ( V_61 = 0 ; V_61 < V_10 -> V_64 ; V_61 ++ ) {
V_13 = & V_10 -> V_66 [ V_61 ] . V_13 ;
V_4 = V_13 -> V_19 ;
F_21 ( V_13 ) ;
if ( V_4 -> V_25 )
F_29 ( V_4 -> V_25 ) ;
}
for ( V_61 = 0 ; V_61 < V_10 -> V_63 ; V_61 ++ ) {
V_13 = & V_10 -> V_65 [ V_61 ] . V_13 ;
V_4 = V_13 -> V_19 ;
F_21 ( V_13 ) ;
if ( V_4 -> V_25 )
F_29 ( V_4 -> V_25 ) ;
}
return 0 ;
}
static int F_30 ( struct V_58 * V_59 )
{
struct V_60 * V_10 = F_2 ( V_59 ,
struct V_60 , V_10 ) ;
struct V_3 * V_4 = NULL ;
struct V_8 * V_8 = V_10 -> V_19 ;
struct V_48 * V_87 = V_8 -> V_10 ;
struct V_88 * V_89 = V_87 -> V_90 ;
struct V_91 * V_2 = V_89 -> V_92 ;
struct V_20 * V_20 = NULL ;
T_4 V_61 ;
T_2 V_93 ;
T_2 V_18 = 0 ;
void * * V_94 ;
struct V_3 * V_95 ;
T_4 V_96 ;
void (* F_31)( struct V_1 * );
T_6 V_97 ;
if ( ( V_2 -> V_64 > V_98 ) ||
( V_2 -> V_63 > V_99 ) )
return - V_100 ;
V_10 -> V_64 = V_2 -> V_64 ;
V_10 -> V_63 = V_2 -> V_63 ;
F_32 ( V_97 ) ;
F_33 ( V_101 , V_97 ) ;
V_95 = V_10 -> V_66 ;
V_96 = V_2 -> V_64 ;
V_94 = V_2 -> V_102 ;
F_31 = F_7 ;
for ( V_93 = 0 ; V_93 < 2 ; V_93 ++ ) {
for ( V_61 = 0 ; V_61 < V_96 ; V_61 ++ ) {
V_4 = & V_95 [ V_61 ] ;
V_4 -> V_10 = V_10 ;
V_4 -> V_61 = V_61 ;
V_4 -> V_18 = V_18 ;
V_20 = & ( V_4 -> V_13 ) ;
V_20 -> V_19 = V_4 ;
V_20 -> V_16 = V_17 ;
V_20 -> V_103 = V_104 ;
V_4 -> V_25 = F_34 ( V_97 ,
V_2 -> V_105 ,
V_94 [ V_61 ] ) ;
if ( ! V_4 -> V_25 ) {
F_35 ( L_7 ,
V_93 , V_61 ) ;
F_28 ( V_59 ) ;
return - V_106 ;
}
F_36 ( & V_4 -> V_5 ,
F_31 ) ;
}
V_95 = V_10 -> V_65 ;
V_96 = V_2 -> V_63 ;
V_94 = V_2 -> V_107 ;
F_31 = F_1 ;
V_18 = 1 ;
}
return 0 ;
}
void F_37 ( struct V_58 * V_59 )
{
struct V_60 * V_10 = F_2 ( V_59 ,
struct V_60 , V_10 ) ;
F_38 ( V_10 ) ;
}
struct V_58 * T_7
F_39 ( struct V_8 * V_8 , void T_5 * V_108 )
{
struct V_60 * V_10 ;
struct V_109 * V_110 = F_40 ( V_8 -> V_10 ) ;
struct V_111 * V_112 ;
V_10 = F_41 ( sizeof( * V_10 ) , V_113 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_19 = V_8 ;
V_112 = F_42 ( V_110 , V_114 , 0 ) ;
V_10 -> V_37 = ( T_3 ) V_112 -> V_115 ;
V_10 -> V_10 . V_115 = F_30 ;
V_10 -> V_10 . V_116 = F_28 ;
V_10 -> V_10 . V_117 = F_20 ;
V_10 -> V_10 . V_118 = F_21 ;
V_10 -> V_10 . V_119 = F_23 ;
V_10 -> V_10 . V_120 = F_25 ;
V_10 -> V_10 . V_121 = F_22 ;
return & V_10 -> V_10 ;
}

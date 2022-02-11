static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_8 = V_7 -> V_8 ;
unsigned long V_9 ;
F_3 ( 4 , L_1 , V_7 -> V_10 ) ;
F_4 ( & V_8 -> V_11 , V_9 ) ;
V_4 -> V_12 . V_13 = V_4 -> V_14 ;
V_4 -> V_12 . V_15 = V_16 ;
F_5 ( V_8 , V_7 -> V_10 ,
V_4 -> V_17 ) ;
F_6 ( & V_8 -> V_11 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_8 = V_7 -> V_8 ;
unsigned long V_9 ;
F_3 ( 4 , L_2 , V_7 -> V_10 ) ;
F_4 ( & V_8 -> V_11 , V_9 ) ;
V_4 -> V_12 . V_13 = V_4 -> V_14 ;
V_4 -> V_12 . V_15 = V_16 ;
F_5 ( V_8 , V_7 -> V_10 ,
V_4 -> V_17 ) ;
F_6 ( & V_8 -> V_11 , V_9 ) ;
}
void F_8 ( void * V_18 )
{
struct V_19 * V_12 = (struct V_19 * ) V_18 ;
struct V_3 * V_4 = V_12 -> V_18 ;
F_9 ( & V_4 -> V_5 ) ;
}
static bool F_10 ( struct V_19 * V_12 ,
T_1 V_20 , T_2 V_21 ,
T_3 V_22 , T_4 V_23 )
{
struct V_3 * V_4 = V_12 -> V_18 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_24 * V_24 = V_4 -> V_24 ;
struct V_25 * V_26 ;
enum V_27 V_28 ;
struct V_29 V_30 ;
struct V_31 V_32 ;
enum V_33 V_34 ;
T_3 V_35 = ( F_11 ( V_7 -> V_10 ) +
V_4 -> V_36 -> V_37 ) ;
F_3 ( 4 , L_3 ,
V_20 , V_21 , V_22 , V_23 , V_4 -> V_17 ) ;
V_4 -> V_14 = V_23 ;
F_12 ( & V_30 , 1 ) ;
F_13 ( & V_30 , F_14 ( F_15 ( V_22 ) ) , V_23 ,
F_16 ( V_22 ) ) ;
F_17 ( & V_30 ) = V_22 ;
F_18 ( & V_30 ) = V_23 ;
V_28 = V_4 -> V_17 ? V_38 : V_39 ;
V_34 = ( V_23 & 0x3 ) ? V_40 :
V_41 ;
V_32 . V_28 = V_28 ;
if ( V_28 == V_39 ) {
V_32 . V_42 = V_35 ;
V_32 . V_43 = V_34 ;
V_32 . V_44 = 16 ;
} else {
V_32 . V_45 = V_35 ;
V_32 . V_46 = V_34 ;
V_32 . V_47 = 16 ;
}
V_24 -> V_48 -> V_49 ( V_24 , V_50 ,
( unsigned long ) & V_32 ) ;
V_26 = V_24 -> V_48 ->
V_51 ( V_24 , & V_30 , 1 , V_28 ,
V_52 | V_53 ) ;
if ( ! V_26 )
return false ;
V_26 -> V_54 = F_8 ;
V_26 -> V_55 = V_12 ;
V_4 -> V_56 = V_26 -> V_57 ( V_26 ) ;
F_19 ( V_24 ) ;
return true ;
}
static struct V_19 * F_20 ( struct V_58 * V_59 ,
struct V_6 * V_7 , T_2 V_17 )
{
struct V_60 * V_36 = F_2 ( V_59 ,
struct V_60 , V_36 ) ;
struct V_3 * V_4 = NULL ;
T_2 V_61 = V_7 -> V_10 - 1 ;
T_4 V_62 ;
if ( V_61 > 7 )
V_61 -= 8 ;
V_62 = V_17 ? V_36 -> V_63 :
V_36 -> V_64 ;
if ( V_61 >= V_62 )
return NULL ;
V_4 = V_17 ? & ( V_36 -> V_65 [ V_61 ] ) :
& ( V_36 -> V_66 [ V_61 ] ) ;
if ( V_4 -> V_67 )
return NULL ;
V_4 -> V_7 = V_7 ;
V_4 -> V_67 = 1 ;
F_3 ( 7 , L_4 ,
V_7 -> V_10 , V_17 , V_61 ) ;
return & ( V_4 -> V_12 ) ;
}
static void F_21 ( struct V_19 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_18 ;
F_3 ( 7 , L_5 , V_4 -> V_61 ) ;
if ( V_4 -> V_67 ) {
V_4 -> V_67 = 0 ;
V_12 -> V_15 = V_16 ;
V_12 -> V_13 = 0 ;
}
}
static int F_22 ( struct V_19 * V_12 ,
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
static int F_23 ( struct V_19 * V_12 ,
T_1 V_20 , T_2 V_21 ,
T_3 V_22 , T_4 V_23 )
{
int V_71 ;
F_24 ( V_12 -> V_15 == V_72 ||
V_12 -> V_15 == V_73 ) ;
if ( ! F_22 ( V_12 , V_20 , ( void * ) V_22 , V_23 ) )
return false ;
V_12 -> V_15 = V_73 ;
V_12 -> V_13 = 0 ;
V_71 = F_10 ( V_12 , V_20 , V_21 , V_22 , V_23 ) ;
if ( ! V_71 )
V_12 -> V_15 = V_16 ;
return V_71 ;
}
static int F_25 ( struct V_19 * V_12 )
{
struct V_3 * V_4 = V_12 -> V_18 ;
struct V_60 * V_36 = V_4 -> V_36 ;
struct V_8 * V_8 = V_36 -> V_18 ;
void T_5 * V_74 = V_8 -> V_75 [ V_4 -> V_7 -> V_10 ] . V_76 ;
T_1 V_77 ;
F_3 ( 4 , L_6 , V_4 -> V_61 ,
V_4 -> V_17 ) ;
if ( V_12 -> V_15 == V_73 ) {
if ( V_4 -> V_17 ) {
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
V_4 -> V_24 -> V_48 ->
V_49 ( V_4 -> V_24 ,
V_86 , 0 ) ;
V_12 -> V_15 = V_16 ;
}
return 0 ;
}
static int F_28 ( struct V_58 * V_59 )
{
struct V_60 * V_36 = F_2 ( V_59 ,
struct V_60 , V_36 ) ;
struct V_3 * V_4 ;
struct V_19 * V_12 ;
T_2 V_61 ;
for ( V_61 = 0 ; V_61 < V_36 -> V_64 ; V_61 ++ ) {
V_12 = & V_36 -> V_66 [ V_61 ] . V_12 ;
V_4 = V_12 -> V_18 ;
F_21 ( V_12 ) ;
if ( V_4 -> V_24 )
F_29 ( V_4 -> V_24 ) ;
}
for ( V_61 = 0 ; V_61 < V_36 -> V_63 ; V_61 ++ ) {
V_12 = & V_36 -> V_65 [ V_61 ] . V_12 ;
V_4 = V_12 -> V_18 ;
F_21 ( V_12 ) ;
if ( V_4 -> V_24 )
F_29 ( V_4 -> V_24 ) ;
}
return 0 ;
}
static int F_30 ( struct V_58 * V_59 )
{
struct V_60 * V_36 = F_2 ( V_59 ,
struct V_60 , V_36 ) ;
struct V_3 * V_4 = NULL ;
struct V_8 * V_8 = V_36 -> V_18 ;
struct V_48 * V_87 = V_8 -> V_36 ;
struct V_88 * V_89 = V_87 -> V_90 ;
struct V_91 * V_2 = V_89 -> V_92 ;
struct V_19 * V_19 = NULL ;
T_4 V_61 ;
T_2 V_93 ;
T_2 V_17 = 0 ;
void * * V_94 ;
struct V_3 * V_95 ;
T_4 V_96 ;
void (* F_31)( struct V_1 * );
T_6 V_97 ;
if ( ( V_2 -> V_64 > V_98 ) ||
( V_2 -> V_63 > V_99 ) )
return - V_100 ;
V_36 -> V_64 = V_2 -> V_64 ;
V_36 -> V_63 = V_2 -> V_63 ;
F_32 ( V_97 ) ;
F_33 ( V_101 , V_97 ) ;
V_95 = V_36 -> V_66 ;
V_96 = V_2 -> V_64 ;
V_94 = V_2 -> V_102 ;
F_31 = F_7 ;
for ( V_93 = 0 ; V_93 < 2 ; V_93 ++ ) {
for ( V_61 = 0 ; V_61 < V_96 ; V_61 ++ ) {
V_4 = & V_95 [ V_61 ] ;
V_4 -> V_36 = V_36 ;
V_4 -> V_61 = V_61 ;
V_4 -> V_17 = V_17 ;
V_19 = & ( V_4 -> V_12 ) ;
V_19 -> V_18 = V_4 ;
V_19 -> V_15 = V_16 ;
V_19 -> V_103 = V_104 ;
V_4 -> V_24 = F_34 ( V_97 ,
V_2 -> V_105 ,
V_94 [ V_61 ] ) ;
if ( ! V_4 -> V_24 ) {
F_35 ( L_7 ,
V_93 , V_61 ) ;
F_28 ( V_59 ) ;
return - V_106 ;
}
F_36 ( & V_4 -> V_5 ,
F_31 ) ;
}
V_95 = V_36 -> V_65 ;
V_96 = V_2 -> V_63 ;
V_94 = V_2 -> V_107 ;
F_31 = F_1 ;
V_17 = 1 ;
}
return 0 ;
}
void F_37 ( struct V_58 * V_59 )
{
struct V_60 * V_36 = F_2 ( V_59 ,
struct V_60 , V_36 ) ;
F_38 ( V_36 ) ;
}
struct V_58 * T_7
F_39 ( struct V_8 * V_8 , void T_5 * V_108 )
{
struct V_60 * V_36 ;
struct V_109 * V_110 = F_40 ( V_8 -> V_36 ) ;
struct V_111 * V_112 ;
V_36 = F_41 ( sizeof( * V_36 ) , V_113 ) ;
if ( ! V_36 )
return NULL ;
V_36 -> V_18 = V_8 ;
V_112 = F_42 ( V_110 , V_114 , 0 ) ;
V_36 -> V_37 = ( T_3 ) V_112 -> V_115 ;
V_36 -> V_36 . V_115 = F_30 ;
V_36 -> V_36 . V_116 = F_28 ;
V_36 -> V_36 . V_117 = F_20 ;
V_36 -> V_36 . V_118 = F_21 ;
V_36 -> V_36 . V_119 = F_23 ;
V_36 -> V_36 . V_120 = F_25 ;
V_36 -> V_36 . V_121 = F_22 ;
return & V_36 -> V_36 ;
}

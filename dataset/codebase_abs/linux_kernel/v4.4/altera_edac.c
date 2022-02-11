static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_11 , V_12 = 1 , V_13 ;
F_2 ( V_6 -> V_14 , V_9 -> V_15 , & V_11 ) ;
if ( V_11 & V_9 -> V_16 ) {
F_2 ( V_6 -> V_14 , V_9 -> V_17 ,
& V_13 ) ;
if ( V_9 -> V_18 )
F_2 ( V_6 -> V_14 , V_9 -> V_18 ,
& V_12 ) ;
F_3 ( L_1 ,
V_12 , V_13 ) ;
}
if ( V_11 & V_9 -> V_19 ) {
F_2 ( V_6 -> V_14 , V_9 -> V_20 ,
& V_13 ) ;
if ( V_9 -> V_18 )
F_2 ( V_6 -> V_14 , V_9 -> V_21 ,
& V_12 ) ;
F_4 ( V_22 , V_4 , V_12 ,
V_13 >> V_23 ,
V_13 & ~ V_24 , 0 ,
0 , 0 , - 1 , V_4 -> V_25 , L_2 ) ;
F_5 ( V_6 -> V_14 , V_9 -> V_26 ,
V_9 -> V_27 ) ;
return V_28 ;
}
return V_29 ;
}
static T_3 F_6 ( struct V_30 * V_30 ,
const char T_4 * V_10 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_3 * V_4 = V_30 -> V_33 ;
struct V_5 * V_6 = V_4 -> V_7 ;
const struct V_8 * V_9 = V_6 -> V_10 ;
T_2 * V_34 ;
T_7 V_35 ;
T_2 V_36 , V_37 ;
V_34 = F_7 ( V_4 -> V_38 , 16 , & V_35 , V_39 ) ;
if ( ! V_34 ) {
F_8 ( V_4 -> V_38 , 16 , V_34 , V_35 ) ;
F_9 ( V_40 , V_41 ,
L_3 ) ;
return - V_42 ;
}
F_2 ( V_6 -> V_14 , V_9 -> V_43 ,
& V_37 ) ;
V_37 &= ~ ( V_9 -> V_44 | V_9 -> V_45 ) ;
if ( V_31 == 3 ) {
F_9 ( V_46 , V_41 ,
L_4 ) ;
F_5 ( V_6 -> V_14 , V_9 -> V_43 ,
( V_37 | V_9 -> V_45 ) ) ;
} else {
F_9 ( V_46 , V_41 ,
L_5 ) ;
F_5 ( V_6 -> V_14 , V_9 -> V_43 ,
( V_37 | V_9 -> V_44 ) ) ;
}
V_34 [ 0 ] = 0x5A5A5A5A ;
V_34 [ 1 ] = 0xA5A5A5A5 ;
F_5 ( V_6 -> V_14 , V_9 -> V_43 , V_37 ) ;
F_10 () ;
V_36 = F_11 ( V_34 [ 0 ] ) ;
V_37 = F_11 ( V_34 [ 1 ] ) ;
F_12 () ;
F_9 ( V_46 , V_41 , L_6 ,
V_36 , V_37 ) ;
F_8 ( V_4 -> V_38 , 16 , V_34 , V_35 ) ;
return V_31 ;
}
static void F_13 ( struct V_3 * V_4 )
{
if ( ! F_14 ( V_47 ) )
return;
if ( ! V_4 -> V_48 )
return;
F_15 ( L_7 , V_49 , V_4 -> V_48 , V_4 ,
& V_50 ) ;
}
static unsigned long F_16 ( void )
{
struct V_51 * V_52 = NULL ;
const unsigned int * V_36 , * V_53 ;
int V_54 , V_55 , V_56 ;
unsigned long V_57 , V_58 , V_59 = 0 ;
F_17 (np, L_8 ) {
V_56 = F_18 ( V_52 ) ;
V_55 = F_19 ( V_52 ) ;
V_36 = ( const unsigned int * ) F_20 ( V_52 , L_9 , & V_54 ) ;
V_53 = V_36 + ( V_54 / sizeof( T_2 ) ) ;
V_59 = 0 ;
do {
V_57 = F_21 ( V_36 , V_56 ) ;
V_36 += V_56 ;
V_58 = F_21 ( V_36 , V_55 ) ;
V_36 += V_55 ;
V_59 += V_58 ;
} while ( V_36 < V_53 );
}
F_22 ( 0 , L_10 , V_59 ) ;
return V_59 ;
}
static int F_23 ( struct V_60 * V_14 )
{
if ( F_24 ( V_14 , V_61 ,
V_62 , V_62 ) ) {
F_9 ( V_40 , V_41 ,
L_11 ) ;
return - V_63 ;
}
if ( F_5 ( V_14 , V_64 , 1 ) ) {
F_9 ( V_40 , V_41 ,
L_12 ) ;
return - V_63 ;
}
return 0 ;
}
static int F_25 ( struct V_65 * V_38 , T_2 V_66 )
{
void T_8 * V_67 ;
int V_68 = 0 ;
if ( ! F_26 ( V_69 , sizeof( T_2 ) ,
F_27 ( & V_38 -> V_70 ) ) ) {
F_9 ( V_40 , V_41 ,
L_13 ) ;
return - V_71 ;
}
V_67 = F_28 ( V_69 , sizeof( T_2 ) ) ;
if ( ! V_67 ) {
F_9 ( V_40 , V_41 ,
L_14 ) ;
V_68 = - V_42 ;
goto V_72;
}
F_29 ( V_66 , V_67 ) ;
F_30 ( V_67 ) ;
V_72:
F_31 ( V_69 , sizeof( T_2 ) ) ;
return V_68 ;
}
static int F_32 ( struct V_65 * V_38 )
{
const struct V_73 * V_74 ;
struct V_75 V_76 [ 2 ] ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const struct V_8 * V_9 ;
struct V_60 * V_14 ;
struct V_77 * V_78 ;
T_2 V_37 ;
int V_1 , V_79 , V_80 = 0 ;
unsigned long V_81 , V_82 = 0 ;
V_74 = F_33 ( V_83 , & V_38 -> V_70 ) ;
if ( ! V_74 )
return - V_63 ;
V_14 = F_34 ( V_38 -> V_70 . V_84 ,
L_15 ) ;
if ( F_35 ( V_14 ) ) {
F_9 ( V_40 , V_41 ,
L_16 ) ;
return - V_63 ;
}
V_9 = F_36 ( V_83 ,
V_38 -> V_70 . V_84 ) -> V_10 ;
if ( F_2 ( V_14 , V_9 -> V_85 , & V_37 ) ||
( ( V_37 & V_9 -> V_86 ) != V_9 -> V_86 ) ) {
F_9 ( V_40 , V_41 ,
L_17 , V_37 ) ;
return - V_63 ;
}
V_81 = F_16 () ;
if ( ! V_81 ) {
F_9 ( V_40 , V_41 , L_18 ) ;
return - V_63 ;
}
if ( F_24 ( V_14 , V_9 -> V_87 ,
V_9 -> V_88 , 0 ) ) {
F_9 ( V_40 , V_41 ,
L_19 ) ;
return - V_63 ;
}
if ( F_24 ( V_14 , V_9 -> V_89 ,
V_9 -> V_90 ,
V_9 -> V_90 ) ) {
F_9 ( V_40 , V_41 ,
L_20 ) ;
return - V_63 ;
}
if ( F_24 ( V_14 , V_9 -> V_89 ,
V_9 -> V_90 , 0 ) ) {
F_9 ( V_40 , V_41 ,
L_20 ) ;
return - V_63 ;
}
V_1 = F_37 ( V_38 , 0 ) ;
if ( V_1 < 0 ) {
F_9 ( V_40 , V_41 ,
L_21 , V_1 ) ;
return - V_63 ;
}
V_79 = F_37 ( V_38 , 1 ) ;
V_76 [ 0 ] . type = V_91 ;
V_76 [ 0 ] . V_58 = 1 ;
V_76 [ 0 ] . V_92 = true ;
V_76 [ 1 ] . type = V_93 ;
V_76 [ 1 ] . V_58 = 1 ;
V_76 [ 1 ] . V_92 = false ;
V_4 = F_38 ( 0 , F_39 ( V_76 ) , V_76 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_42 ;
V_4 -> V_38 = & V_38 -> V_70 ;
V_6 = V_4 -> V_7 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_10 = V_9 ;
F_40 ( V_38 , V_4 ) ;
if ( ! F_41 ( & V_38 -> V_70 , NULL , V_39 ) ) {
F_9 ( V_40 , V_41 ,
L_22 ) ;
V_80 = - V_42 ;
goto free;
}
V_4 -> V_94 = V_95 ;
V_4 -> V_96 = V_97 | V_98 ;
V_4 -> V_99 = V_98 ;
V_4 -> V_100 = V_101 ;
V_4 -> V_102 = V_103 ;
V_4 -> V_25 = F_27 ( & V_38 -> V_70 ) ;
V_4 -> V_104 = V_105 ;
V_4 -> F_27 = F_27 ( & V_38 -> V_70 ) ;
V_78 = * V_4 -> V_106 ;
V_78 -> V_107 = ( ( V_81 - 1 ) >> V_23 ) + 1 ;
V_78 -> V_108 = 8 ;
V_78 -> V_109 = V_110 ;
V_78 -> V_111 = V_112 ;
V_78 -> V_113 = V_114 ;
V_80 = F_42 ( V_4 ) ;
if ( V_80 < 0 )
goto V_115;
if ( V_79 > 0 ) {
V_80 = F_23 ( V_14 ) ;
if ( V_80 < 0 )
goto V_116;
V_80 = F_43 ( & V_38 -> V_70 , V_79 ,
F_1 ,
V_117 , F_27 ( & V_38 -> V_70 ) , V_4 ) ;
if ( V_80 < 0 ) {
F_44 ( V_4 , V_40 ,
L_23 , V_79 ) ;
V_80 = - V_63 ;
goto V_116;
}
V_80 = F_25 ( V_38 , V_118 ) ;
if ( V_80 < 0 )
goto V_116;
V_82 = V_117 ;
}
V_80 = F_43 ( & V_38 -> V_70 , V_1 , F_1 ,
V_82 , F_27 ( & V_38 -> V_70 ) , V_4 ) ;
if ( V_80 < 0 ) {
F_44 ( V_4 , V_40 ,
L_23 , V_1 ) ;
V_80 = - V_63 ;
goto V_116;
}
if ( F_24 ( V_6 -> V_14 , V_9 -> V_87 ,
V_9 -> V_88 , V_9 -> V_88 ) ) {
F_44 ( V_4 , V_40 ,
L_24 ) ;
V_80 = - V_63 ;
goto V_116;
}
F_13 ( V_4 ) ;
F_45 ( & V_38 -> V_70 , NULL ) ;
return 0 ;
V_116:
F_46 ( & V_38 -> V_70 ) ;
V_115:
F_47 ( & V_38 -> V_70 , NULL ) ;
free:
F_48 ( V_4 ) ;
F_9 ( V_40 , V_41 ,
L_25 , V_80 ) ;
return V_80 ;
}
static int F_49 ( struct V_65 * V_38 )
{
struct V_3 * V_4 = F_50 ( V_38 ) ;
F_46 ( & V_38 -> V_70 ) ;
F_48 ( V_4 ) ;
F_40 ( V_38 , NULL ) ;
return 0 ;
}
static int F_51 ( struct V_119 * V_70 )
{
F_52 ( L_26 ) ;
return - V_120 ;
}

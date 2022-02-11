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
if ( V_4 -> V_47 )
F_14 ( L_7 , V_48 , V_4 -> V_47 , V_4 ,
& V_49 ) ;
}
static void F_13 ( struct V_3 * V_4 )
{}
static unsigned long F_15 ( void )
{
struct V_50 * V_51 = NULL ;
const unsigned int * V_36 , * V_52 ;
int V_53 , V_54 , V_55 ;
unsigned long V_56 , V_57 , V_58 = 0 ;
F_16 (np, L_8 ) {
V_55 = F_17 ( V_51 ) ;
V_54 = F_18 ( V_51 ) ;
V_36 = ( const unsigned int * ) F_19 ( V_51 , L_9 , & V_53 ) ;
V_52 = V_36 + ( V_53 / sizeof( T_2 ) ) ;
V_58 = 0 ;
do {
V_56 = F_20 ( V_36 , V_55 ) ;
V_36 += V_55 ;
V_57 = F_20 ( V_36 , V_54 ) ;
V_36 += V_54 ;
V_58 += V_57 ;
} while ( V_36 < V_52 );
}
F_21 ( 0 , L_10 , V_58 ) ;
return V_58 ;
}
static int F_22 ( struct V_59 * V_14 )
{
if ( F_23 ( V_14 , V_60 ,
V_61 , V_61 ) ) {
F_9 ( V_40 , V_41 ,
L_11 ) ;
return - V_62 ;
}
if ( F_5 ( V_14 , V_63 , 1 ) ) {
F_9 ( V_40 , V_41 ,
L_12 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_24 ( struct V_64 * V_38 , T_2 V_65 )
{
void T_8 * V_66 ;
int V_67 = 0 ;
if ( ! F_25 ( V_68 , sizeof( T_2 ) ,
F_26 ( & V_38 -> V_69 ) ) ) {
F_9 ( V_40 , V_41 ,
L_13 ) ;
return - V_70 ;
}
V_66 = F_27 ( V_68 , sizeof( T_2 ) ) ;
if ( ! V_66 ) {
F_9 ( V_40 , V_41 ,
L_14 ) ;
V_67 = - V_42 ;
goto V_71;
}
F_28 ( V_65 , V_66 ) ;
F_29 ( V_66 ) ;
V_71:
F_30 ( V_68 , sizeof( T_2 ) ) ;
return V_67 ;
}
static int F_31 ( struct V_64 * V_38 )
{
const struct V_72 * V_73 ;
struct V_74 V_75 [ 2 ] ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
const struct V_8 * V_9 ;
struct V_59 * V_14 ;
struct V_76 * V_77 ;
T_2 V_37 ;
int V_1 , V_78 , V_79 = 0 ;
unsigned long V_80 , V_81 = 0 ;
V_73 = F_32 ( V_82 , & V_38 -> V_69 ) ;
if ( ! V_73 )
return - V_62 ;
V_14 = F_33 ( V_38 -> V_69 . V_83 ,
L_15 ) ;
if ( F_34 ( V_14 ) ) {
F_9 ( V_40 , V_41 ,
L_16 ) ;
return - V_62 ;
}
V_9 = F_35 ( V_82 ,
V_38 -> V_69 . V_83 ) -> V_10 ;
if ( F_2 ( V_14 , V_9 -> V_84 , & V_37 ) ||
( ( V_37 & V_9 -> V_85 ) != V_9 -> V_85 ) ) {
F_9 ( V_40 , V_41 ,
L_17 , V_37 ) ;
return - V_62 ;
}
V_80 = F_15 () ;
if ( ! V_80 ) {
F_9 ( V_40 , V_41 , L_18 ) ;
return - V_62 ;
}
if ( F_23 ( V_14 , V_9 -> V_86 ,
V_9 -> V_87 , 0 ) ) {
F_9 ( V_40 , V_41 ,
L_19 ) ;
return - V_62 ;
}
if ( F_23 ( V_14 , V_9 -> V_88 ,
V_9 -> V_89 ,
V_9 -> V_89 ) ) {
F_9 ( V_40 , V_41 ,
L_20 ) ;
return - V_62 ;
}
if ( F_23 ( V_14 , V_9 -> V_88 ,
V_9 -> V_89 , 0 ) ) {
F_9 ( V_40 , V_41 ,
L_20 ) ;
return - V_62 ;
}
V_1 = F_36 ( V_38 , 0 ) ;
if ( V_1 < 0 ) {
F_9 ( V_40 , V_41 ,
L_21 , V_1 ) ;
return - V_62 ;
}
V_78 = F_36 ( V_38 , 1 ) ;
V_75 [ 0 ] . type = V_90 ;
V_75 [ 0 ] . V_57 = 1 ;
V_75 [ 0 ] . V_91 = true ;
V_75 [ 1 ] . type = V_92 ;
V_75 [ 1 ] . V_57 = 1 ;
V_75 [ 1 ] . V_91 = false ;
V_4 = F_37 ( 0 , F_38 ( V_75 ) , V_75 ,
sizeof( struct V_5 ) ) ;
if ( ! V_4 )
return - V_42 ;
V_4 -> V_38 = & V_38 -> V_69 ;
V_6 = V_4 -> V_7 ;
V_6 -> V_14 = V_14 ;
V_6 -> V_10 = V_9 ;
F_39 ( V_38 , V_4 ) ;
if ( ! F_40 ( & V_38 -> V_69 , NULL , V_39 ) ) {
F_9 ( V_40 , V_41 ,
L_22 ) ;
V_79 = - V_42 ;
goto free;
}
V_4 -> V_93 = V_94 ;
V_4 -> V_95 = V_96 | V_97 ;
V_4 -> V_98 = V_97 ;
V_4 -> V_99 = V_100 ;
V_4 -> V_101 = V_102 ;
V_4 -> V_25 = F_26 ( & V_38 -> V_69 ) ;
V_4 -> V_103 = V_104 ;
V_4 -> F_26 = F_26 ( & V_38 -> V_69 ) ;
V_77 = * V_4 -> V_105 ;
V_77 -> V_106 = ( ( V_80 - 1 ) >> V_23 ) + 1 ;
V_77 -> V_107 = 8 ;
V_77 -> V_108 = V_109 ;
V_77 -> V_110 = V_111 ;
V_77 -> V_112 = V_113 ;
V_79 = F_41 ( V_4 ) ;
if ( V_79 < 0 )
goto V_114;
if ( V_78 > 0 ) {
V_79 = F_22 ( V_14 ) ;
if ( V_79 < 0 )
goto V_115;
V_79 = F_42 ( & V_38 -> V_69 , V_78 ,
F_1 ,
V_116 , F_26 ( & V_38 -> V_69 ) , V_4 ) ;
if ( V_79 < 0 ) {
F_43 ( V_4 , V_40 ,
L_23 , V_78 ) ;
V_79 = - V_62 ;
goto V_115;
}
V_79 = F_24 ( V_38 , V_117 ) ;
if ( V_79 < 0 )
goto V_115;
V_81 = V_116 ;
}
V_79 = F_42 ( & V_38 -> V_69 , V_1 , F_1 ,
V_81 , F_26 ( & V_38 -> V_69 ) , V_4 ) ;
if ( V_79 < 0 ) {
F_43 ( V_4 , V_40 ,
L_23 , V_1 ) ;
V_79 = - V_62 ;
goto V_115;
}
if ( F_23 ( V_6 -> V_14 , V_9 -> V_86 ,
V_9 -> V_87 , V_9 -> V_87 ) ) {
F_43 ( V_4 , V_40 ,
L_24 ) ;
V_79 = - V_62 ;
goto V_115;
}
F_13 ( V_4 ) ;
F_44 ( & V_38 -> V_69 , NULL ) ;
return 0 ;
V_115:
F_45 ( & V_38 -> V_69 ) ;
V_114:
F_46 ( & V_38 -> V_69 , NULL ) ;
free:
F_47 ( V_4 ) ;
F_9 ( V_40 , V_41 ,
L_25 , V_79 ) ;
return V_79 ;
}
static int F_48 ( struct V_64 * V_38 )
{
struct V_3 * V_4 = F_49 ( V_38 ) ;
F_45 ( & V_38 -> V_69 ) ;
F_47 ( V_4 ) ;
F_39 ( V_38 , NULL ) ;
return 0 ;
}
static int F_50 ( struct V_118 * V_69 )
{
F_51 ( L_26 ) ;
return - V_119 ;
}

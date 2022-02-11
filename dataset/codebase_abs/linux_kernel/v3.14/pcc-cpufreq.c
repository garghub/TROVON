static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
static inline void F_3 ( void )
{
T_1 V_3 ;
int V_4 ;
F_4 ( & V_3 , & V_5 ) ;
F_5 ( ( V_3 & V_6 ) | V_7 ,
& V_5 ) ;
for ( V_4 = 0 ; V_4 < V_8 ; V_4 ++ ) {
if ( F_6 ( & V_9 -> V_10 ) & V_11 )
break;
}
}
static inline void F_7 ( void )
{
if ( V_12 )
F_8 ( V_12 ) ;
V_12 = NULL ;
}
static unsigned int F_9 ( unsigned int V_13 )
{
struct V_14 * V_15 ;
unsigned int V_16 ;
unsigned int V_17 ;
T_2 V_10 ;
T_3 V_18 ;
T_3 V_19 ;
F_10 ( & V_20 ) ;
F_11 ( L_1 , V_13 ) ;
V_15 = F_12 ( V_21 , V_13 ) ;
V_18 = 0x1 ;
F_13 ( V_18 ,
( V_12 + V_15 -> V_22 ) ) ;
F_14 ( V_23 , & V_9 -> V_24 ) ;
F_3 () ;
V_19 =
F_15 ( V_12 + V_15 -> V_25 ) ;
F_16 ( ( V_12 + V_15 -> V_22 ) , 0 , V_26 ) ;
V_10 = F_6 ( & V_9 -> V_10 ) ;
if ( V_10 != V_11 ) {
F_11 ( L_2 ,
V_13 , V_10 ) ;
goto V_27;
}
F_14 ( 0 , & V_9 -> V_10 ) ;
V_16 = ( ( ( F_15 ( & V_9 -> V_28 ) * ( V_19 & 0xff ) )
/ 100 ) * 1000 ) ;
F_11 ( L_3
L_4 ,
V_13 , ( V_12 + V_15 -> V_25 ) ,
V_19 , V_16 ) ;
V_17 = ( V_19 >> 8 ) & 0xff ;
if ( V_17 != 0xff ) {
F_11 ( L_5
L_6 , V_13 , V_16 ) ;
}
F_17 ( & V_20 ) ;
return V_16 ;
V_27:
F_14 ( 0 , & V_9 -> V_10 ) ;
F_17 ( & V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_29 ,
unsigned int V_30 )
{
struct V_14 * V_15 ;
struct V_31 V_32 ;
T_2 V_10 ;
T_3 V_18 ;
int V_13 ;
F_10 ( & V_20 ) ;
V_13 = V_2 -> V_13 ;
V_15 = F_12 ( V_21 , V_13 ) ;
F_11 ( L_7
L_8 ,
V_13 , V_29 ,
( V_12 + V_15 -> V_22 ) ) ;
V_32 . V_33 = V_2 -> V_34 ;
V_32 . V_35 = V_29 ;
F_19 ( V_2 , & V_32 , V_36 ) ;
V_18 = 0x1 | ( ( ( V_29 * 100 )
/ ( F_15 ( & V_9 -> V_28 ) * 1000 ) ) << 8 ) ;
F_13 ( V_18 ,
( V_12 + V_15 -> V_22 ) ) ;
F_14 ( V_37 , & V_9 -> V_24 ) ;
F_3 () ;
F_16 ( ( V_12 + V_15 -> V_22 ) , 0 , V_26 ) ;
V_10 = F_6 ( & V_9 -> V_10 ) ;
F_14 ( 0 , & V_9 -> V_10 ) ;
F_20 ( V_2 , & V_32 , V_10 != V_11 ) ;
F_17 ( & V_20 ) ;
if ( V_10 != V_11 ) {
F_11 ( L_9 ,
V_13 , V_10 ) ;
return - V_38 ;
}
F_11 ( L_10 , V_13 ) ;
return 0 ;
}
static int F_21 ( int V_13 )
{
T_4 V_10 ;
struct V_39 V_40 = { V_41 , NULL } ;
union V_42 * V_43 , * V_44 ;
struct V_14 * V_15 ;
struct V_45 * V_46 ;
int V_47 = 0 ;
V_46 = F_22 ( V_48 , V_13 ) ;
V_15 = F_12 ( V_21 , V_13 ) ;
if ( ! V_46 )
return - V_49 ;
V_10 = F_23 ( V_46 -> V_50 , L_11 , NULL , & V_40 ) ;
if ( F_24 ( V_10 ) )
return - V_49 ;
V_43 = V_40 . V_51 ;
if ( ! V_43 || V_43 -> type != V_52 ) {
V_47 = - V_49 ;
goto V_53;
} ;
V_44 = & ( V_43 -> V_54 . V_55 [ 0 ] ) ;
if ( ! V_44 || V_44 -> type != V_56 ) {
V_47 = - V_49 ;
goto V_53;
}
V_15 -> V_22 = V_44 -> integer . V_57 ;
V_44 = & ( V_43 -> V_54 . V_55 [ 1 ] ) ;
if ( ! V_44 || V_44 -> type != V_56 ) {
V_47 = - V_49 ;
goto V_53;
}
V_15 -> V_25 = V_44 -> integer . V_57 ;
F_16 ( ( V_12 + V_15 -> V_22 ) , 0 , V_26 ) ;
F_16 ( ( V_12 + V_15 -> V_25 ) , 0 , V_26 ) ;
F_11 ( L_12
L_13 ,
V_13 , V_15 -> V_22 , V_15 -> V_25 ) ;
V_53:
F_25 ( V_40 . V_51 ) ;
return V_47 ;
}
static int T_5 F_26 ( T_6 * V_50 )
{
T_4 V_10 ;
struct V_58 V_59 ;
struct V_39 V_60 = { V_41 , NULL } ;
union V_42 V_61 [ 4 ] ;
union V_42 * V_62 ;
T_3 V_63 [ 2 ] ;
T_3 V_64 ;
T_3 V_65 ;
int V_47 = 0 ;
V_59 . V_66 = 4 ;
V_59 . V_51 = V_61 ;
V_61 [ 0 ] . type = V_67 ;
V_61 [ 0 ] . V_40 . V_68 = 16 ;
V_61 [ 0 ] . V_40 . V_51 = V_69 ;
V_61 [ 1 ] . type = V_56 ;
V_61 [ 1 ] . integer . V_57 = 1 ;
V_61 [ 2 ] . type = V_56 ;
V_61 [ 2 ] . integer . V_57 = 2 ;
V_61 [ 3 ] . type = V_67 ;
V_61 [ 3 ] . V_40 . V_68 = 8 ;
V_61 [ 3 ] . V_40 . V_51 = ( V_70 * ) & V_63 ;
V_63 [ 0 ] = V_71 ;
V_63 [ 1 ] = 0x1 ;
V_10 = F_23 ( * V_50 , L_14 , & V_59 , & V_60 ) ;
if ( F_24 ( V_10 ) )
return - V_49 ;
if ( ! V_60 . V_68 )
return - V_49 ;
V_62 = V_60 . V_51 ;
if ( V_62 -> type != V_67 ) {
V_47 = - V_49 ;
goto V_53;
}
V_64 = * ( ( T_3 * ) V_62 -> V_40 . V_51 ) & ~ ( 1 << 0 ) ;
if ( V_64 ) {
V_47 = - V_49 ;
goto V_53;
}
V_65 = * ( ( T_3 * ) ( V_62 -> V_40 . V_51 + 4 ) ) ;
if ( ! ( V_65 & 0x1 ) ) {
V_47 = - V_49 ;
goto V_53;
}
F_25 ( V_60 . V_51 ) ;
V_63 [ 0 ] = 0x0 ;
V_63 [ 1 ] = 0x1 ;
V_10 = F_23 ( * V_50 , L_14 , & V_59 , & V_60 ) ;
if ( F_24 ( V_10 ) )
return - V_49 ;
if ( ! V_60 . V_68 )
return - V_49 ;
V_62 = V_60 . V_51 ;
if ( V_62 -> type != V_67 ) {
V_47 = - V_49 ;
goto V_53;
}
V_64 = * ( ( T_3 * ) V_62 -> V_40 . V_51 ) & ~ ( 1 << 0 ) ;
if ( V_64 ) {
V_47 = - V_49 ;
goto V_53;
}
V_65 = * ( ( T_3 * ) ( V_62 -> V_40 . V_51 + 4 ) ) ;
if ( ! ( V_65 & 0x1 ) ) {
V_47 = - V_49 ;
goto V_53;
}
V_53:
F_25 ( V_60 . V_51 ) ;
return V_47 ;
}
static int T_5 F_27 ( void )
{
T_4 V_10 ;
struct V_39 V_60 = { V_41 , NULL } ;
struct V_72 * V_73 ;
struct V_74 * V_75 ;
union V_42 * V_62 , * V_76 ;
T_6 V_50 , V_77 ;
int V_47 = 0 ;
V_10 = F_28 ( NULL , L_15 , & V_50 ) ;
if ( F_24 ( V_10 ) )
return - V_49 ;
if ( ! F_29 ( V_50 , L_16 ) )
return - V_49 ;
V_10 = F_28 ( V_50 , L_14 , & V_77 ) ;
if ( F_30 ( V_10 ) ) {
V_47 = F_26 ( & V_77 ) ;
if ( V_47 )
F_11 ( L_17 ) ;
V_47 = 0 ;
}
V_10 = F_23 ( V_50 , L_16 , NULL , & V_60 ) ;
if ( F_24 ( V_10 ) )
return - V_49 ;
V_62 = V_60 . V_51 ;
if ( V_62 -> type != V_52 ) {
V_47 = - V_49 ;
goto V_53;
}
V_76 = & V_62 -> V_54 . V_55 [ 0 ] ;
if ( V_76 -> type != V_67 ) {
V_47 = - V_49 ;
goto V_53;
}
V_73 = (struct V_72 * ) V_76 -> V_40 . V_51 ;
F_11 ( L_18
L_19
L_20
L_21
L_22 ,
V_73 -> V_78 , V_73 -> V_68 ,
V_73 -> V_79 , V_73 -> V_80 ,
V_73 -> V_81 , V_73 -> V_82 ,
V_73 -> V_83 , V_73 -> V_84 ,
V_73 -> V_85 ,
V_73 -> V_86 ) ;
if ( V_73 -> V_79 != V_87 ) {
V_47 = - V_49 ;
goto V_53;
}
V_12 = F_31 ( V_73 -> V_83 ,
V_73 -> V_86 ) ;
if ( V_12 == NULL ) {
F_11 ( L_23 ) ;
V_47 = - V_88 ;
goto V_53;
}
V_9 = V_12 ;
F_11 ( L_24 , V_9 ) ;
F_11 ( L_25
L_26
L_27
L_28 ,
V_73 -> V_83 , F_15 ( & V_9 -> V_89 ) ,
F_6 ( & V_9 -> V_68 ) , F_32 ( & V_9 -> V_90 ) ,
F_32 ( & V_9 -> V_91 ) , F_15 ( & V_9 -> V_92 ) ,
F_6 ( & V_9 -> V_24 ) , F_6 ( & V_9 -> V_10 ) ,
F_15 ( & V_9 -> V_93 ) ) ;
F_11 ( L_29
L_30
L_31
L_32
L_33 ,
F_15 ( & V_9 -> V_94 ) ,
F_15 ( & V_9 -> V_95 ) ,
F_15 ( & V_9 -> V_28 ) ,
F_15 ( & V_9 -> V_96 ) ,
F_15 ( & V_9 -> V_97 ) ) ;
V_76 = & V_62 -> V_54 . V_55 [ 1 ] ;
if ( V_76 -> type != V_67 ) {
V_47 = - V_49 ;
goto V_98;
}
V_75 = (struct V_74 * ) V_76 -> V_40 . V_51 ;
V_5 . V_79 = V_75 -> V_79 ;
V_5 . V_99 = V_75 -> V_99 ;
V_5 . V_100 = V_75 -> V_100 ;
V_5 . V_101 = 64 ;
V_5 . V_102 = V_75 -> V_102 ;
F_11 ( L_34
L_35 ,
V_5 . V_79 , V_5 . V_99 , V_5 . V_100 ,
V_5 . V_101 , V_75 -> V_102 ) ;
V_76 = & V_62 -> V_54 . V_55 [ 2 ] ;
if ( V_76 -> type != V_56 ) {
V_47 = - V_49 ;
goto V_98;
}
V_6 = V_76 -> integer . V_57 ;
V_76 = & V_62 -> V_54 . V_55 [ 3 ] ;
if ( V_76 -> type != V_56 ) {
V_47 = - V_49 ;
goto V_98;
}
V_7 = V_76 -> integer . V_57 ;
F_11 ( L_36
L_37 ,
V_6 , V_7 ) ;
V_21 = F_33 ( struct V_14 ) ;
if ( ! V_21 ) {
V_47 = - V_88 ;
goto V_98;
}
F_34 ( V_103 L_38
L_39 , V_104 ,
F_15 ( & V_9 -> V_97 ) ,
F_15 ( & V_9 -> V_28 ) ) ;
F_25 ( V_60 . V_51 ) ;
return V_47 ;
V_98:
F_7 () ;
V_53:
F_25 ( V_60 . V_51 ) ;
return V_47 ;
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned int V_13 = V_2 -> V_13 ;
unsigned int V_105 = 0 ;
if ( ! V_12 ) {
V_105 = - 1 ;
goto V_106;
}
V_105 = F_21 ( V_13 ) ;
if ( V_105 ) {
F_11 ( L_40 ) ;
goto V_106;
}
V_2 -> V_107 = V_2 -> V_108 . V_109 =
F_15 ( & V_9 -> V_28 ) * 1000 ;
V_2 -> V_110 = V_2 -> V_108 . V_111 =
F_15 ( & V_9 -> V_97 ) * 1000 ;
F_11 ( L_41 ,
V_2 -> V_107 , V_2 -> V_110 ) ;
V_106:
return V_105 ;
}
static int F_36 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_5 F_37 ( void )
{
int V_47 ;
if ( V_112 )
return 0 ;
V_47 = F_27 () ;
if ( V_47 ) {
F_11 ( L_42 ) ;
return V_47 ;
}
V_47 = F_38 ( & V_113 ) ;
return V_47 ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_113 ) ;
F_7 () ;
F_41 ( V_21 ) ;
}

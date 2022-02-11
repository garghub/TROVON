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
V_13 = V_2 -> V_13 ;
V_15 = F_12 ( V_21 , V_13 ) ;
F_11 ( L_7
L_8 ,
V_13 , V_29 ,
( V_12 + V_15 -> V_22 ) ) ;
V_32 . V_33 = V_2 -> V_34 ;
V_32 . V_35 = V_29 ;
F_19 ( V_2 , & V_32 ) ;
F_10 ( & V_20 ) ;
V_18 = 0x1 | ( ( ( V_29 * 100 )
/ ( F_15 ( & V_9 -> V_28 ) * 1000 ) ) << 8 ) ;
F_13 ( V_18 ,
( V_12 + V_15 -> V_22 ) ) ;
F_14 ( V_36 , & V_9 -> V_24 ) ;
F_3 () ;
F_16 ( ( V_12 + V_15 -> V_22 ) , 0 , V_26 ) ;
V_10 = F_6 ( & V_9 -> V_10 ) ;
F_14 ( 0 , & V_9 -> V_10 ) ;
F_20 ( V_2 , & V_32 , V_10 != V_11 ) ;
F_17 ( & V_20 ) ;
if ( V_10 != V_11 ) {
F_11 ( L_9 ,
V_13 , V_10 ) ;
return - V_37 ;
}
F_11 ( L_10 , V_13 ) ;
return 0 ;
}
static int F_21 ( int V_13 )
{
T_4 V_10 ;
struct V_38 V_39 = { V_40 , NULL } ;
union V_41 * V_42 , * V_43 ;
struct V_14 * V_15 ;
struct V_44 * V_45 ;
int V_46 = 0 ;
V_45 = F_22 ( V_47 , V_13 ) ;
V_15 = F_12 ( V_21 , V_13 ) ;
if ( ! V_45 )
return - V_48 ;
V_10 = F_23 ( V_45 -> V_49 , L_11 , NULL , & V_39 ) ;
if ( F_24 ( V_10 ) )
return - V_48 ;
V_42 = V_39 . V_50 ;
if ( ! V_42 || V_42 -> type != V_51 ) {
V_46 = - V_48 ;
goto V_52;
} ;
V_43 = & ( V_42 -> V_53 . V_54 [ 0 ] ) ;
if ( ! V_43 || V_43 -> type != V_55 ) {
V_46 = - V_48 ;
goto V_52;
}
V_15 -> V_22 = V_43 -> integer . V_56 ;
V_43 = & ( V_42 -> V_53 . V_54 [ 1 ] ) ;
if ( ! V_43 || V_43 -> type != V_55 ) {
V_46 = - V_48 ;
goto V_52;
}
V_15 -> V_25 = V_43 -> integer . V_56 ;
F_16 ( ( V_12 + V_15 -> V_22 ) , 0 , V_26 ) ;
F_16 ( ( V_12 + V_15 -> V_25 ) , 0 , V_26 ) ;
F_11 ( L_12
L_13 ,
V_13 , V_15 -> V_22 , V_15 -> V_25 ) ;
V_52:
F_25 ( V_39 . V_50 ) ;
return V_46 ;
}
static int T_5 F_26 ( T_6 * V_49 )
{
T_4 V_10 ;
struct V_57 V_58 ;
struct V_38 V_59 = { V_40 , NULL } ;
union V_41 V_60 [ 4 ] ;
union V_41 * V_61 ;
T_3 V_62 [ 2 ] ;
T_3 V_63 ;
T_3 V_64 ;
int V_46 = 0 ;
V_58 . V_65 = 4 ;
V_58 . V_50 = V_60 ;
V_60 [ 0 ] . type = V_66 ;
V_60 [ 0 ] . V_39 . V_67 = 16 ;
V_60 [ 0 ] . V_39 . V_50 = V_68 ;
V_60 [ 1 ] . type = V_55 ;
V_60 [ 1 ] . integer . V_56 = 1 ;
V_60 [ 2 ] . type = V_55 ;
V_60 [ 2 ] . integer . V_56 = 2 ;
V_60 [ 3 ] . type = V_66 ;
V_60 [ 3 ] . V_39 . V_67 = 8 ;
V_60 [ 3 ] . V_39 . V_50 = ( V_69 * ) & V_62 ;
V_62 [ 0 ] = V_70 ;
V_62 [ 1 ] = 0x1 ;
V_10 = F_23 ( * V_49 , L_14 , & V_58 , & V_59 ) ;
if ( F_24 ( V_10 ) )
return - V_48 ;
if ( ! V_59 . V_67 )
return - V_48 ;
V_61 = V_59 . V_50 ;
if ( V_61 -> type != V_66 ) {
V_46 = - V_48 ;
goto V_52;
}
V_63 = * ( ( T_3 * ) V_61 -> V_39 . V_50 ) & ~ ( 1 << 0 ) ;
if ( V_63 ) {
V_46 = - V_48 ;
goto V_52;
}
V_64 = * ( ( T_3 * ) ( V_61 -> V_39 . V_50 + 4 ) ) ;
if ( ! ( V_64 & 0x1 ) ) {
V_46 = - V_48 ;
goto V_52;
}
F_25 ( V_59 . V_50 ) ;
V_62 [ 0 ] = 0x0 ;
V_62 [ 1 ] = 0x1 ;
V_10 = F_23 ( * V_49 , L_14 , & V_58 , & V_59 ) ;
if ( F_24 ( V_10 ) )
return - V_48 ;
if ( ! V_59 . V_67 )
return - V_48 ;
V_61 = V_59 . V_50 ;
if ( V_61 -> type != V_66 ) {
V_46 = - V_48 ;
goto V_52;
}
V_63 = * ( ( T_3 * ) V_61 -> V_39 . V_50 ) & ~ ( 1 << 0 ) ;
if ( V_63 ) {
V_46 = - V_48 ;
goto V_52;
}
V_64 = * ( ( T_3 * ) ( V_61 -> V_39 . V_50 + 4 ) ) ;
if ( ! ( V_64 & 0x1 ) ) {
V_46 = - V_48 ;
goto V_52;
}
V_52:
F_25 ( V_59 . V_50 ) ;
return V_46 ;
}
static int T_5 F_27 ( void )
{
T_4 V_10 ;
struct V_38 V_59 = { V_40 , NULL } ;
struct V_71 * V_72 ;
struct V_73 * V_74 ;
union V_41 * V_61 , * V_75 ;
T_6 V_49 , V_76 ;
int V_46 = 0 ;
V_10 = F_28 ( NULL , L_15 , & V_49 ) ;
if ( F_24 ( V_10 ) )
return - V_48 ;
if ( ! F_29 ( V_49 , L_16 ) )
return - V_48 ;
V_10 = F_28 ( V_49 , L_14 , & V_76 ) ;
if ( F_30 ( V_10 ) ) {
V_46 = F_26 ( & V_76 ) ;
if ( V_46 )
F_11 ( L_17 ) ;
V_46 = 0 ;
}
V_10 = F_23 ( V_49 , L_16 , NULL , & V_59 ) ;
if ( F_24 ( V_10 ) )
return - V_48 ;
V_61 = V_59 . V_50 ;
if ( V_61 -> type != V_51 ) {
V_46 = - V_48 ;
goto V_52;
}
V_75 = & V_61 -> V_53 . V_54 [ 0 ] ;
if ( V_75 -> type != V_66 ) {
V_46 = - V_48 ;
goto V_52;
}
V_72 = (struct V_71 * ) V_75 -> V_39 . V_50 ;
F_11 ( L_18
L_19
L_20
L_21
L_22 ,
V_72 -> V_77 , V_72 -> V_67 ,
V_72 -> V_78 , V_72 -> V_79 ,
V_72 -> V_80 , V_72 -> V_81 ,
V_72 -> V_82 , V_72 -> V_83 ,
V_72 -> V_84 ,
V_72 -> V_85 ) ;
if ( V_72 -> V_78 != V_86 ) {
V_46 = - V_48 ;
goto V_52;
}
V_12 = F_31 ( V_72 -> V_82 ,
V_72 -> V_85 ) ;
if ( V_12 == NULL ) {
F_11 ( L_23 ) ;
V_46 = - V_87 ;
goto V_52;
}
V_9 = V_12 ;
F_11 ( L_24 , V_9 ) ;
F_11 ( L_25
L_26
L_27
L_28 ,
V_72 -> V_82 , F_15 ( & V_9 -> V_88 ) ,
F_6 ( & V_9 -> V_67 ) , F_32 ( & V_9 -> V_89 ) ,
F_32 ( & V_9 -> V_90 ) , F_15 ( & V_9 -> V_91 ) ,
F_6 ( & V_9 -> V_24 ) , F_6 ( & V_9 -> V_10 ) ,
F_15 ( & V_9 -> V_92 ) ) ;
F_11 ( L_29
L_30
L_31
L_32
L_33 ,
F_15 ( & V_9 -> V_93 ) ,
F_15 ( & V_9 -> V_94 ) ,
F_15 ( & V_9 -> V_28 ) ,
F_15 ( & V_9 -> V_95 ) ,
F_15 ( & V_9 -> V_96 ) ) ;
V_75 = & V_61 -> V_53 . V_54 [ 1 ] ;
if ( V_75 -> type != V_66 ) {
V_46 = - V_48 ;
goto V_97;
}
V_74 = (struct V_73 * ) V_75 -> V_39 . V_50 ;
V_5 . V_78 = V_74 -> V_78 ;
V_5 . V_98 = V_74 -> V_98 ;
V_5 . V_99 = V_74 -> V_99 ;
V_5 . V_100 = 4 ;
V_5 . V_101 = V_74 -> V_101 ;
F_11 ( L_34
L_35 ,
V_5 . V_78 , V_5 . V_98 , V_5 . V_99 ,
V_5 . V_100 , V_74 -> V_101 ) ;
V_75 = & V_61 -> V_53 . V_54 [ 2 ] ;
if ( V_75 -> type != V_55 ) {
V_46 = - V_48 ;
goto V_97;
}
V_6 = V_75 -> integer . V_56 ;
V_75 = & V_61 -> V_53 . V_54 [ 3 ] ;
if ( V_75 -> type != V_55 ) {
V_46 = - V_48 ;
goto V_97;
}
V_7 = V_75 -> integer . V_56 ;
F_11 ( L_36
L_37 ,
V_6 , V_7 ) ;
V_21 = F_33 ( struct V_14 ) ;
if ( ! V_21 ) {
V_46 = - V_87 ;
goto V_97;
}
F_34 ( V_102 L_38
L_39 , V_103 ,
F_15 ( & V_9 -> V_96 ) ,
F_15 ( & V_9 -> V_28 ) ) ;
F_25 ( V_59 . V_50 ) ;
return V_46 ;
V_97:
F_7 () ;
V_52:
F_25 ( V_59 . V_50 ) ;
return V_46 ;
}
static int F_35 ( struct V_1 * V_2 )
{
unsigned int V_13 = V_2 -> V_13 ;
unsigned int V_104 = 0 ;
if ( ! V_12 ) {
V_104 = - 1 ;
goto V_105;
}
V_104 = F_21 ( V_13 ) ;
if ( V_104 ) {
F_11 ( L_40 ) ;
goto V_105;
}
V_2 -> V_106 = V_2 -> V_107 . V_108 =
F_15 ( & V_9 -> V_28 ) * 1000 ;
V_2 -> V_109 = V_2 -> V_107 . V_110 =
F_15 ( & V_9 -> V_96 ) * 1000 ;
F_11 ( L_41 ,
V_2 -> V_106 , V_2 -> V_109 ) ;
V_105:
return V_104 ;
}
static int F_36 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_5 F_37 ( void )
{
int V_46 ;
if ( V_111 )
return 0 ;
V_46 = F_27 () ;
if ( V_46 ) {
F_11 ( L_42 ) ;
return V_46 ;
}
V_46 = F_38 ( & V_112 ) ;
return V_46 ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_112 ) ;
F_7 () ;
F_41 ( V_21 ) ;
}

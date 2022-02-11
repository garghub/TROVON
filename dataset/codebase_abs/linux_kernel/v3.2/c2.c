static void F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 , V_2 -> V_3 , V_2 -> V_4 , V_2 -> V_5 ) ;
}
static void F_3 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_2 ;
if ( V_2 -> V_7 > V_8 )
V_6 -> V_9 =
V_2 -> V_7 + V_10 + sizeof( struct V_11 ) +
V_12 ;
else
V_6 -> V_9 = sizeof( struct V_11 ) + V_8 ;
}
static int F_4 ( struct V_13 * V_14 , void * V_15 ,
T_1 V_16 , void T_2 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 T_2 * V_21 ;
struct V_22 * V_23 ;
int V_24 ;
V_14 -> V_25 = F_5 ( sizeof( * V_23 ) * V_14 -> V_26 , V_27 ) ;
if ( ! V_14 -> V_25 )
return - V_28 ;
V_23 = V_14 -> V_25 ;
V_19 = V_15 ;
V_21 = V_17 ;
for ( V_24 = 0 ; V_24 < V_14 -> V_26 ; V_24 ++ , V_23 ++ , V_19 ++ , V_21 ++ ) {
V_19 -> V_29 = 0 ;
V_19 -> V_30 = 0 ;
F_6 ( ( V_31 V_32 ) F_7 ( 0x1122334455667788ULL ) ,
( void T_2 * ) V_21 + V_33 ) ;
F_8 ( 0 , ( void T_2 * ) V_21 + V_34 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_36 ) ,
( void T_2 * ) V_21 + V_37 ) ;
V_23 -> V_38 = NULL ;
V_23 -> V_39 = V_19 ;
V_23 -> V_40 = V_21 ;
if ( V_24 == V_14 -> V_26 - 1 ) {
V_23 -> V_41 = V_14 -> V_25 ;
V_19 -> V_42 = V_16 ;
} else {
V_23 -> V_41 = V_23 + 1 ;
V_19 -> V_42 =
V_16 + ( V_24 + 1 ) * sizeof( * V_19 ) ;
}
}
V_14 -> V_43 = V_14 -> V_44 = V_14 -> V_25 ;
return 0 ;
}
static int F_10 ( struct V_13 * V_45 , void * V_15 ,
T_1 V_16 , void T_2 * V_46 )
{
struct V_47 * V_48 ;
struct V_49 T_2 * V_50 ;
struct V_22 * V_23 ;
int V_24 ;
V_45 -> V_25 = F_5 ( sizeof( * V_23 ) * V_45 -> V_26 , V_27 ) ;
if ( ! V_45 -> V_25 )
return - V_28 ;
V_23 = V_45 -> V_25 ;
V_48 = V_15 ;
V_50 = V_46 ;
for ( V_24 = 0 ; V_24 < V_45 -> V_26 ; V_24 ++ , V_23 ++ , V_48 ++ , V_50 ++ ) {
V_48 -> V_29 = 0 ;
V_48 -> V_30 = 0 ;
F_8 ( ( V_31 V_35 ) F_9 ( V_51 ) ,
( void T_2 * ) V_50 + V_52 ) ;
F_8 ( 0 , ( void T_2 * ) V_50 + V_53 ) ;
F_8 ( 0 , ( void T_2 * ) V_50 + V_54 ) ;
F_6 ( ( V_31 V_32 ) F_7 ( 0x99aabbccddeeffULL ) ,
( void T_2 * ) V_50 + V_55 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_56 ) ,
( void T_2 * ) V_50 + V_57 ) ;
V_23 -> V_38 = NULL ;
V_23 -> V_39 = V_48 ;
V_23 -> V_40 = V_50 ;
if ( V_24 == V_45 -> V_26 - 1 ) {
V_23 -> V_41 = V_45 -> V_25 ;
V_48 -> V_42 = V_16 ;
} else {
V_23 -> V_41 = V_23 + 1 ;
V_48 -> V_42 =
V_16 + ( V_24 + 1 ) * sizeof( * V_48 ) ;
}
}
V_45 -> V_43 = V_45 -> V_44 = V_45 -> V_25 ;
return 0 ;
}
static inline int F_11 ( struct V_6 * V_6 , struct V_22 * V_23 )
{
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_47 * V_48 = V_23 -> V_39 ;
struct V_60 * V_38 ;
T_1 V_61 ;
T_3 V_62 ;
struct V_11 * V_63 ;
V_38 = F_12 ( V_6 -> V_9 ) ;
if ( F_13 ( ! V_38 ) ) {
F_2 ( L_2 ,
V_6 -> V_2 -> V_3 ) ;
return - V_28 ;
}
memset ( V_38 -> V_64 , 0 , sizeof( * V_63 ) ) ;
V_38 -> V_65 = V_6 -> V_2 ;
V_62 = V_6 -> V_9 ;
V_61 =
F_14 ( V_59 -> V_66 , V_38 -> V_64 , V_62 ,
V_67 ) ;
V_63 = (struct V_11 * ) V_38 -> V_64 ;
V_63 -> V_68 = V_69 ;
F_8 ( 0 , V_23 -> V_40 + V_52 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( ( V_35 ) V_62 - sizeof( * V_63 ) ) ,
V_23 -> V_40 + V_54 ) ;
F_6 ( ( V_31 V_32 ) F_7 ( V_61 ) , V_23 -> V_40 + V_55 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_69 ) ,
V_23 -> V_40 + V_57 ) ;
V_23 -> V_38 = V_38 ;
V_23 -> V_61 = V_61 ;
V_23 -> V_62 = V_62 ;
V_48 -> V_29 = V_62 ;
return 0 ;
}
static int F_15 ( struct V_6 * V_6 )
{
struct V_13 * V_45 = & V_6 -> V_45 ;
struct V_22 * V_23 ;
int V_70 = 0 ;
V_23 = V_45 -> V_25 ;
do {
if ( F_11 ( V_6 , V_23 ) ) {
V_70 = 1 ;
break;
}
} while ( ( V_23 = V_23 -> V_41 ) != V_45 -> V_25 );
V_45 -> V_44 = V_45 -> V_25 ;
return V_70 ;
}
static void F_16 ( struct V_6 * V_6 )
{
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_13 * V_45 = & V_6 -> V_45 ;
struct V_22 * V_23 ;
struct V_47 * V_48 ;
V_23 = V_45 -> V_25 ;
do {
V_48 = V_23 -> V_39 ;
V_48 -> V_29 = 0 ;
F_8 ( 0 , V_23 -> V_40 + V_52 ) ;
F_8 ( 0 , V_23 -> V_40 + V_53 ) ;
F_8 ( 0 , V_23 -> V_40 + V_54 ) ;
F_6 ( ( V_31 V_32 ) F_7 ( 0x99aabbccddeeffULL ) ,
V_23 -> V_40 + V_55 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_56 ) ,
V_23 -> V_40 + V_57 ) ;
if ( V_23 -> V_38 ) {
F_17 ( V_59 -> V_66 , V_23 -> V_61 ,
V_23 -> V_62 , V_67 ) ;
F_18 ( V_23 -> V_38 ) ;
V_23 -> V_38 = NULL ;
}
} while ( ( V_23 = V_23 -> V_41 ) != V_45 -> V_25 );
}
static inline int F_19 ( struct V_58 * V_59 , struct V_22 * V_23 )
{
struct V_18 * V_19 = V_23 -> V_39 ;
V_19 -> V_29 = 0 ;
F_17 ( V_59 -> V_66 , V_23 -> V_61 , V_23 -> V_62 ,
V_71 ) ;
if ( V_23 -> V_38 ) {
F_20 ( V_23 -> V_38 ) ;
V_23 -> V_38 = NULL ;
}
return 0 ;
}
static void F_21 ( struct V_6 * V_6 )
{
struct V_13 * V_14 = & V_6 -> V_14 ;
struct V_22 * V_23 ;
struct V_20 V_72 ;
int V_73 ;
unsigned long V_68 ;
F_22 ( & V_6 -> V_74 , V_68 ) ;
V_23 = V_14 -> V_25 ;
do {
V_73 = 0 ;
do {
V_72 . V_68 =
F_23 ( V_23 -> V_40 + V_37 ) ;
if ( V_72 . V_68 == V_75 ) {
V_73 = 1 ;
F_8 ( 0 ,
V_23 -> V_40 + V_34 ) ;
F_6 ( 0 ,
V_23 -> V_40 + V_33 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_76 ) ,
V_23 -> V_40 + V_37 ) ;
V_6 -> V_2 -> V_77 . V_78 ++ ;
break;
} else {
F_8 ( 0 ,
V_23 -> V_40 + V_34 ) ;
F_6 ( ( V_31 V_32 ) F_7 ( 0x1122334455667788ULL ) ,
V_23 -> V_40 + V_33 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_36 ) ,
V_23 -> V_40 + V_37 ) ;
}
F_19 ( V_6 -> V_59 , V_23 ) ;
} while ( ( V_23 = V_23 -> V_41 ) != V_14 -> V_25 );
} while ( V_73 );
V_6 -> V_79 = V_6 -> V_14 . V_26 - 1 ;
V_6 -> V_59 -> V_80 = V_14 -> V_43 - V_14 -> V_25 ;
if ( V_6 -> V_79 > V_81 + 1 )
F_24 ( V_6 -> V_2 ) ;
F_25 ( & V_6 -> V_74 , V_68 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_27 ( V_2 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_13 * V_14 = & V_6 -> V_14 ;
struct V_22 * V_23 ;
struct V_20 V_72 ;
F_28 ( & V_6 -> V_74 ) ;
for ( V_23 = V_14 -> V_44 ; V_23 != V_14 -> V_43 ;
V_23 = V_23 -> V_41 ) {
V_72 . V_68 =
F_29 ( ( V_31 V_82 ) F_23 ( V_23 -> V_40 + V_37 ) ) ;
if ( V_72 . V_68 != V_76 )
break;
if ( F_30 ( V_6 ) ) {
V_72 . V_29 =
F_29 ( ( V_31 V_82 ) F_23 ( V_23 -> V_40 + V_34 ) ) ;
F_2 ( L_3
L_4 ,
V_2 -> V_3 , V_23 - V_14 -> V_25 ,
V_72 . V_68 , V_72 . V_29 ) ;
}
F_19 ( V_59 , V_23 ) ;
++ ( V_6 -> V_79 ) ;
}
V_14 -> V_44 = V_23 ;
if ( F_31 ( V_2 )
&& V_6 -> V_79 > V_81 + 1 )
F_24 ( V_2 ) ;
F_32 ( & V_6 -> V_74 ) ;
}
static void F_33 ( struct V_6 * V_6 , struct V_22 * V_23 )
{
struct V_47 * V_48 = V_23 -> V_39 ;
struct V_11 * V_63 = (struct V_11 * ) V_23 -> V_38 -> V_64 ;
if ( V_63 -> V_30 != V_51 ||
V_63 -> V_29 > ( V_48 -> V_29 - sizeof( * V_63 ) ) ) {
F_2 ( L_5 ) ;
F_2 ( L_6 , V_48 ) ;
F_2 ( L_7 ,
V_23 - V_6 -> V_45 . V_25 ) ;
F_2 ( L_8 , V_48 -> V_29 ) ;
F_2 ( L_9 , V_63 ,
( void * ) F_34 ( ( unsigned long ) V_63 ) ) ;
F_2 ( L_10 , V_63 -> V_68 ) ;
F_2 ( L_11 , V_63 -> V_30 ) ;
F_2 ( L_8 , V_63 -> V_29 ) ;
F_2 ( L_12 , V_63 -> V_83 ) ;
}
V_23 -> V_38 -> V_64 = V_23 -> V_38 -> V_84 ;
F_35 ( V_23 -> V_38 ) ;
memset ( V_23 -> V_38 -> V_64 , 0 , sizeof( * V_63 ) ) ;
F_8 ( 0 , V_23 -> V_40 + V_52 ) ;
F_8 ( 0 , V_23 -> V_40 + V_53 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( ( V_35 ) V_23 -> V_62 - sizeof( * V_63 ) ) ,
V_23 -> V_40 + V_54 ) ;
F_6 ( ( V_31 V_32 ) F_7 ( V_23 -> V_61 ) ,
V_23 -> V_40 + V_55 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_69 ) ,
V_23 -> V_40 + V_57 ) ;
F_2 ( L_13 ) ;
V_6 -> V_2 -> V_77 . V_85 ++ ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_27 ( V_2 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_13 * V_45 = & V_6 -> V_45 ;
struct V_22 * V_23 ;
struct V_47 * V_48 ;
struct V_11 * V_63 ;
struct V_60 * V_38 ;
T_1 V_61 ;
T_3 V_62 , V_86 ;
unsigned long V_68 ;
F_22 ( & V_59 -> V_87 , V_68 ) ;
V_45 -> V_44 = V_45 -> V_25 + V_59 -> V_88 ;
for ( V_23 = V_45 -> V_44 ; V_23 -> V_41 != V_45 -> V_44 ;
V_23 = V_23 -> V_41 ) {
V_48 = V_23 -> V_39 ;
V_61 = V_23 -> V_61 ;
V_62 = V_23 -> V_62 ;
V_38 = V_23 -> V_38 ;
V_63 = (struct V_11 * ) V_38 -> V_64 ;
if ( V_63 -> V_68 != V_89 )
break;
V_86 = V_63 -> V_29 ;
if ( V_63 -> V_30 != V_51 ||
V_86 > ( V_48 -> V_29 - sizeof( * V_63 ) ) ) {
F_33 ( V_6 , V_23 ) ;
continue;
}
if ( F_11 ( V_6 , V_23 ) ) {
F_33 ( V_6 , V_23 ) ;
continue;
}
F_17 ( V_59 -> V_66 , V_61 , V_62 ,
V_67 ) ;
F_37 ( V_38 -> V_64 ) ;
V_38 -> V_64 += sizeof( * V_63 ) ;
F_38 ( V_38 , V_86 ) ;
V_38 -> V_29 = V_86 ;
V_38 -> V_90 = F_39 ( V_38 , V_2 ) ;
F_40 ( V_38 ) ;
V_2 -> V_77 . V_91 ++ ;
V_2 -> V_77 . V_92 += V_86 ;
}
V_45 -> V_44 = V_23 ;
V_59 -> V_88 = V_23 - V_45 -> V_25 ;
F_41 ( V_59 , V_59 -> V_88 ) ;
F_25 ( & V_59 -> V_87 , V_68 ) ;
}
static T_4 F_42 ( int V_5 , void * V_93 )
{
unsigned int V_94 , V_95 ;
int V_96 = 0 ;
struct V_58 * V_59 = (struct V_58 * ) V_93 ;
V_94 = F_43 ( V_59 -> V_97 + V_98 ) ;
if ( V_94 ) {
F_36 ( V_59 -> V_2 ) ;
F_26 ( V_59 -> V_2 ) ;
F_44 ( V_94 , V_59 -> V_97 + V_98 ) ;
V_96 ++ ;
}
V_95 = F_43 ( V_59 -> V_97 + V_99 ) ;
if ( V_95 ) {
F_44 ( V_95 , V_59 -> V_97 + V_99 ) ;
F_45 ( V_59 ) ;
V_96 ++ ;
}
if ( V_96 ) {
return V_100 ;
} else {
return V_101 ;
}
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_27 ( V_2 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_22 * V_23 ;
struct V_11 * V_63 ;
struct V_102 * V_103 ;
T_5 V_104 , V_105 ;
int V_70 , V_24 ;
unsigned int V_106 ;
if ( F_47 ( V_6 ) )
F_2 ( L_14 , V_2 -> V_3 ) ;
F_3 ( V_6 ) ;
V_104 = V_6 -> V_45 . V_26 * sizeof( struct V_47 ) ;
V_105 = V_6 -> V_14 . V_26 * sizeof( struct V_18 ) ;
V_6 -> V_107 = V_105 + V_104 ;
V_6 -> V_108 = F_48 ( V_59 -> V_66 , V_6 -> V_107 ,
& V_6 -> V_109 ) ;
if ( V_6 -> V_108 == NULL ) {
F_2 ( L_15
L_16 ) ;
return - V_28 ;
}
memset ( V_6 -> V_108 , 0 , V_6 -> V_107 ) ;
if ( ( V_70 =
F_10 ( & V_6 -> V_45 , V_6 -> V_108 , V_6 -> V_109 ,
V_59 -> V_46 ) ) ) {
F_2 ( L_17 ) ;
goto V_110;
}
if ( F_15 ( V_6 ) ) {
F_2 ( L_18 ) ;
goto V_111;
}
if ( ( V_70 = F_4 ( & V_6 -> V_14 , V_6 -> V_108 + V_104 ,
V_6 -> V_109 + V_104 ,
V_59 -> V_17 ) ) ) {
F_2 ( L_19 ) ;
goto V_111;
}
V_6 -> V_79 = V_6 -> V_14 . V_26 - 1 ;
V_6 -> V_14 . V_43 = V_6 -> V_14 . V_44 =
V_6 -> V_14 . V_25 + V_59 -> V_80 ;
F_49 ( V_6 -> V_14 . V_43 != V_6 -> V_14 . V_44 ) ;
F_50 ( V_6 ) ;
for ( V_24 = 0 , V_23 = V_6 -> V_45 . V_25 ; V_24 < V_6 -> V_45 . V_26 ;
V_24 ++ , V_23 ++ ) {
V_63 = (struct V_11 * ) V_23 -> V_38 -> V_64 ;
V_63 -> V_68 = 0 ;
F_8 ( ( V_31 V_35 ) F_9 ( V_69 ) ,
V_23 -> V_40 + V_57 ) ;
}
F_51 ( V_2 ) ;
F_44 ( 0 , V_59 -> V_97 + V_112 ) ;
V_106 = F_43 ( V_59 -> V_97 + V_113 ) ;
V_106 &= ~ ( V_114 | V_115 ) ;
F_44 ( V_106 , V_59 -> V_97 + V_113 ) ;
V_103 = F_52 ( V_2 ) ;
F_53 ( V_103 , V_116 , 1 ) ;
F_54 ( V_103 ) ;
return 0 ;
V_111:
F_16 ( V_6 ) ;
F_55 ( V_6 -> V_45 . V_25 ) ;
V_110:
F_56 ( V_59 -> V_66 , V_6 -> V_107 , V_6 -> V_108 ,
V_6 -> V_109 ) ;
return V_70 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_27 ( V_2 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
if ( F_58 ( V_6 ) )
F_2 ( L_20 ,
V_2 -> V_3 ) ;
F_26 ( V_2 ) ;
F_59 ( V_2 ) ;
F_44 ( 1 , V_59 -> V_97 + V_112 ) ;
F_44 ( 0 , V_59 -> V_97 + V_113 ) ;
F_50 ( V_6 ) ;
F_21 ( V_6 ) ;
F_16 ( V_6 ) ;
F_55 ( V_6 -> V_45 . V_25 ) ;
F_55 ( V_6 -> V_14 . V_25 ) ;
F_56 ( V_59 -> V_66 , V_6 -> V_107 , V_6 -> V_108 ,
V_6 -> V_109 ) ;
return 0 ;
}
static void F_50 ( struct V_6 * V_6 )
{
struct V_58 * V_59 = V_6 -> V_59 ;
unsigned int V_88 = V_59 -> V_88 ;
F_41 ( V_59 , V_88 | V_117 ) ;
F_60 ( 2 ) ;
V_88 = F_61 ( V_59 ) ;
if ( V_88 & V_117 )
F_2 ( L_21 ) ;
V_88 &= ~ V_117 ;
V_59 -> V_88 = V_88 ;
F_2 ( L_22 , V_59 -> V_88 ) ;
}
static int F_62 ( struct V_60 * V_38 , struct V_1 * V_2 )
{
struct V_6 * V_6 = F_27 ( V_2 ) ;
struct V_58 * V_59 = V_6 -> V_59 ;
struct V_13 * V_14 = & V_6 -> V_14 ;
struct V_22 * V_23 ;
T_1 V_61 ;
T_3 V_62 ;
unsigned long V_68 ;
unsigned int V_24 ;
F_22 ( & V_6 -> V_74 , V_68 ) ;
if ( F_13 ( V_6 -> V_79 < ( F_63 ( V_38 ) -> V_118 + 1 ) ) ) {
F_59 ( V_2 ) ;
F_25 ( & V_6 -> V_74 , V_68 ) ;
F_2 ( L_23 ,
V_2 -> V_3 ) ;
return V_119 ;
}
V_62 = F_64 ( V_38 ) ;
V_61 =
F_14 ( V_59 -> V_66 , V_38 -> V_64 , V_62 , V_71 ) ;
V_23 = V_14 -> V_43 ;
V_23 -> V_38 = V_38 ;
V_23 -> V_61 = V_61 ;
V_23 -> V_62 = V_62 ;
F_6 ( ( V_31 V_32 ) F_7 ( V_61 ) ,
V_23 -> V_40 + V_33 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_62 ) ,
V_23 -> V_40 + V_34 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_75 ) ,
V_23 -> V_40 + V_37 ) ;
V_2 -> V_77 . V_120 ++ ;
V_2 -> V_77 . V_121 += V_62 ;
if ( F_63 ( V_38 ) -> V_118 ) {
for ( V_24 = 0 ; V_24 < F_63 ( V_38 ) -> V_118 ; V_24 ++ ) {
const T_6 * V_122 = & F_63 ( V_38 ) -> V_123 [ V_24 ] ;
V_62 = F_65 ( V_122 ) ;
V_61 = F_66 ( & V_59 -> V_66 -> V_65 , V_122 ,
0 , V_62 , V_124 ) ;
V_23 = V_23 -> V_41 ;
V_23 -> V_38 = NULL ;
V_23 -> V_61 = V_61 ;
V_23 -> V_62 = V_62 ;
F_6 ( ( V_31 V_32 ) F_7 ( V_61 ) ,
V_23 -> V_40 + V_33 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_62 ) ,
V_23 -> V_40 + V_34 ) ;
F_8 ( ( V_31 V_35 ) F_9 ( V_75 ) ,
V_23 -> V_40 + V_37 ) ;
V_2 -> V_77 . V_120 ++ ;
V_2 -> V_77 . V_121 += V_62 ;
}
}
V_14 -> V_43 = V_23 -> V_41 ;
V_6 -> V_79 -= ( F_63 ( V_38 ) -> V_118 + 1 ) ;
if ( V_6 -> V_79 <= V_81 + 1 ) {
F_59 ( V_2 ) ;
if ( F_67 ( V_6 ) )
F_2 ( L_24 ,
V_2 -> V_3 ) ;
}
F_25 ( & V_6 -> V_74 , V_68 ) ;
V_2 -> V_125 = V_126 ;
return V_127 ;
}
static void F_68 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_27 ( V_2 ) ;
if ( F_69 ( V_6 ) )
F_2 ( L_25 , V_2 -> V_3 ) ;
F_21 ( V_6 ) ;
}
static int F_70 ( struct V_1 * V_2 , int V_128 )
{
int V_70 = 0 ;
if ( V_128 < V_129 || V_128 > V_130 )
return - V_131 ;
V_2 -> V_7 = V_128 ;
if ( F_71 ( V_2 ) ) {
F_57 ( V_2 ) ;
F_46 ( V_2 ) ;
}
return V_70 ;
}
static struct V_1 * F_72 ( struct V_58 * V_59 ,
void T_2 * V_132 )
{
struct V_6 * V_6 = NULL ;
struct V_1 * V_2 = F_73 ( sizeof( * V_6 ) ) ;
if ( ! V_2 ) {
F_2 ( L_26 ) ;
return NULL ;
}
F_74 ( V_2 , & V_59 -> V_66 -> V_65 ) ;
V_2 -> V_133 = & V_134 ;
V_2 -> V_135 = V_136 ;
V_2 -> V_5 = V_59 -> V_66 -> V_5 ;
V_6 = F_27 ( V_2 ) ;
V_6 -> V_2 = V_2 ;
V_6 -> V_59 = V_59 ;
V_6 -> V_137 = F_75 ( V_138 , V_139 ) ;
V_6 -> V_14 . V_26 = V_140 ;
V_6 -> V_45 . V_26 = V_141 ;
F_76 ( & V_6 -> V_74 ) ;
F_77 ( V_2 -> V_4 , V_132 + V_142 , 6 ) ;
if ( ! F_78 ( V_2 -> V_4 ) ) {
F_2 ( L_27 ) ;
F_1 ( V_2 ) ;
F_79 ( V_2 ) ;
return NULL ;
}
V_59 -> V_2 = V_2 ;
return V_2 ;
}
static int T_7 F_80 ( struct V_143 * V_66 ,
const struct V_144 * V_145 )
{
int V_70 = 0 , V_24 ;
unsigned long V_146 , V_147 , V_148 ;
unsigned long V_149 , V_150 , V_151 ;
unsigned long V_152 , V_153 , V_154 ;
unsigned V_155 ;
struct V_1 * V_2 = NULL ;
struct V_58 * V_59 = NULL ;
void T_2 * V_156 = NULL ;
F_81 (KERN_INFO PFX L_28 ,
DRV_VERSION) ;
V_70 = F_82 ( V_66 ) ;
if ( V_70 ) {
F_81 (KERN_ERR PFX L_29 ,
pci_name(pcidev)) ;
goto V_110;
}
V_146 = F_83 ( V_66 , V_157 ) ;
V_148 = F_84 ( V_66 , V_157 ) ;
V_147 = F_85 ( V_66 , V_157 ) ;
V_149 = F_83 ( V_66 , V_158 ) ;
V_151 = F_84 ( V_66 , V_158 ) ;
V_150 = F_85 ( V_66 , V_158 ) ;
V_152 = F_83 ( V_66 , V_159 ) ;
V_154 = F_84 ( V_66 , V_159 ) ;
V_153 = F_85 ( V_66 , V_159 ) ;
F_2 ( L_30 , V_148 ) ;
F_2 ( L_31 , V_151 ) ;
F_2 ( L_32 , V_154 ) ;
if ( ! ( V_147 & V_160 ) ||
! ( V_150 & V_160 ) || ! ( V_153 & V_160 ) ) {
F_81 (KERN_ERR PFX L_33 ) ;
V_70 = - V_161 ;
goto V_111;
}
if ( ( V_148 < V_162 ) ||
( V_151 < V_163 ) || ( V_154 < V_164 ) ) {
F_81 (KERN_ERR PFX L_34 ) ;
V_70 = - V_161 ;
goto V_111;
}
V_70 = F_86 ( V_66 , V_165 ) ;
if ( V_70 ) {
F_81 (KERN_ERR PFX L_35 ,
pci_name(pcidev)) ;
goto V_111;
}
if ( ( sizeof( T_1 ) > 4 ) ) {
V_70 = F_87 ( V_66 , F_88 ( 64 ) ) ;
if ( V_70 < 0 ) {
F_81 (KERN_ERR PFX L_36 ) ;
goto V_166;
}
} else {
V_70 = F_87 ( V_66 , F_88 ( 32 ) ) ;
if ( V_70 < 0 ) {
F_81 (KERN_ERR PFX L_37 ) ;
goto V_166;
}
}
F_89 ( V_66 ) ;
V_156 = F_90 ( V_152 + V_167 ,
sizeof( struct V_168 ) ) ;
if ( ! V_156 ) {
F_81 (KERN_ERR PFX
L_38 ) ;
V_70 = - V_169 ;
goto V_166;
}
for ( V_24 = 0 ; V_24 < sizeof( V_170 ) ; V_24 ++ ) {
if ( V_170 [ V_24 ] != F_91 ( V_156 + V_171 + V_24 ) ) {
F_81 (KERN_ERR PFX L_39
L_40
L_41 ,
i + 1 , sizeof(c2_magic),
readb(mmio_regs + C2_REGS_MAGIC + i),
c2_magic[i]) ;
F_81 (KERN_ERR PFX L_42 ) ;
F_92 ( V_156 ) ;
V_70 = - V_169 ;
goto V_166;
}
}
if ( F_93 ( ( V_31 V_172 ) F_43 ( V_156 + V_173 ) ) != V_174 ) {
F_81 (KERN_ERR PFX L_43
L_44 ,
be32_to_cpu((__force __be32) readl(mmio_regs + C2_REGS_VERS)),
C2_VERSION) ;
V_70 = - V_131 ;
F_92 ( V_156 ) ;
goto V_166;
}
if ( F_93 ( ( V_31 V_172 ) F_43 ( V_156 + V_175 ) ) != V_176 ) {
F_81 (KERN_ERR PFX L_45
L_46
L_47 ,
be32_to_cpu((__force __be32) readl(mmio_regs + C2_REGS_IVN)),
C2_IVN) ;
V_70 = - V_131 ;
F_92 ( V_156 ) ;
goto V_166;
}
V_59 = (struct V_58 * ) F_94 ( sizeof( * V_59 ) ) ;
if ( ! V_59 ) {
F_81 (KERN_ERR PFX L_48 ,
pci_name(pcidev)) ;
V_70 = - V_28 ;
F_92 ( V_156 ) ;
goto V_166;
}
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
F_76 ( & V_59 -> V_87 ) ;
V_59 -> V_66 = V_66 ;
V_59 -> V_80 = 0 ;
V_59 -> V_88 =
( F_93 ( ( V_31 V_172 ) F_43 ( V_156 + V_177 ) ) -
0xffffc000 ) / sizeof( struct V_49 ) ;
V_70 = F_95 ( V_66 -> V_5 , F_42 , V_178 , V_165 , V_59 ) ;
if ( V_70 ) {
F_81 (KERN_ERR PFX L_49 ,
pci_name(pcidev), pcidev->irq) ;
F_92 ( V_156 ) ;
goto V_179;
}
F_96 ( V_66 , V_59 ) ;
if ( ( V_2 = F_72 ( V_59 , V_156 ) ) == NULL ) {
F_92 ( V_156 ) ;
goto V_180;
}
V_155 = F_93 ( ( V_31 V_172 ) F_43 ( V_156 + V_181 ) ) ;
F_92 ( V_156 ) ;
V_70 = F_97 ( V_2 ) ;
if ( V_70 ) {
F_81 (KERN_ERR PFX L_50 ,
ret) ;
goto V_182;
}
F_59 ( V_2 ) ;
V_59 -> V_46 = F_90 ( V_152 + V_183 ,
V_184 ) ;
if ( ! V_59 -> V_46 ) {
F_81 (KERN_ERR PFX L_51 ) ;
V_70 = - V_169 ;
goto V_185;
}
V_59 -> V_17 = F_90 ( V_152 + V_186 ,
V_187 ) ;
if ( ! V_59 -> V_17 ) {
F_81 (KERN_ERR PFX L_52 ) ;
V_70 = - V_169 ;
goto V_188;
}
F_41 ( V_59 , V_59 -> V_88 ) ;
V_59 -> V_97 = F_90 ( V_146 , V_148 ) ;
if ( ! V_59 -> V_97 ) {
F_81 (KERN_ERR PFX L_53 ) ;
V_70 = - V_169 ;
goto V_189;
}
V_59 -> V_190 = V_152 + V_167 ;
V_59 -> V_191 = F_90 ( V_152 + V_167 ,
V_155 ) ;
if ( ! V_59 -> V_191 ) {
F_81 (KERN_ERR PFX L_54 ) ;
V_70 = - V_169 ;
goto V_192;
}
F_1 ( V_2 ) ;
V_70 = F_98 ( V_59 ) ;
if ( V_70 ) {
F_81 (KERN_ERR PFX L_55 , ret) ;
goto V_193;
}
if ( F_99 ( V_59 ) )
goto V_193;
return 0 ;
V_193:
F_92 ( V_59 -> V_191 ) ;
V_192:
F_92 ( V_59 -> V_97 ) ;
V_189:
F_92 ( V_59 -> V_17 ) ;
V_188:
F_92 ( V_59 -> V_46 ) ;
V_185:
F_100 ( V_2 ) ;
V_182:
F_79 ( V_2 ) ;
V_180:
F_101 ( V_66 -> V_5 , V_59 ) ;
V_179:
F_102 ( & V_59 -> V_194 ) ;
V_166:
F_103 ( V_66 ) ;
V_111:
F_104 ( V_66 ) ;
V_110:
return V_70 ;
}
static void T_8 F_105 ( struct V_143 * V_66 )
{
struct V_58 * V_59 = F_106 ( V_66 ) ;
struct V_1 * V_2 = V_59 -> V_2 ;
F_107 ( V_59 ) ;
F_108 ( V_59 ) ;
F_100 ( V_2 ) ;
F_79 ( V_2 ) ;
F_101 ( V_66 -> V_5 , V_59 ) ;
F_92 ( V_59 -> V_191 ) ;
F_92 ( V_59 -> V_97 ) ;
F_92 ( V_59 -> V_17 ) ;
F_92 ( V_59 -> V_46 ) ;
F_102 ( & V_59 -> V_194 ) ;
F_103 ( V_66 ) ;
F_104 ( V_66 ) ;
F_96 ( V_66 , NULL ) ;
}
static int T_9 F_109 ( void )
{
return F_110 ( & V_195 ) ;
}
static void T_10 F_111 ( void )
{
F_112 ( & V_195 ) ;
}

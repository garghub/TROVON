static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) ( V_5 long ) V_2 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_8 . V_9 ;
struct V_10 * V_11 = & F_2 ( V_4 -> V_12 . V_9 -> V_13 -> V_14 ) ;
int V_15 = F_3 (
V_2 -> V_16 . V_17 ) ;
V_15 = ( V_15 == V_18 ) ? 0 : - V_19 ;
if ( V_8 -> V_20 ) {
if ( V_4 -> V_21 )
F_4 ( V_11 , V_4 -> V_12 . V_9 -> V_22 ,
V_4 -> V_21 , V_4 -> V_23 . V_9 . V_23 . V_24 ) ;
else
F_5 ( V_11 , V_4 -> V_23 . V_9 . V_23 . V_24 ,
V_4 -> V_12 . V_9 -> V_22 , V_25 ) ;
}
V_8 -> V_26 = V_4 -> V_12 . V_9 -> V_22 ;
if ( V_4 -> V_27 ) {
F_6 ( V_4 -> V_27 , V_8 -> V_28 , 0 ,
V_8 -> V_26 , 1 ) ;
F_4 ( V_11 , V_4 -> V_12 . V_9 -> V_22 , V_4 -> V_27 ,
V_4 -> V_29 . V_9 . V_30 ) ;
} else {
F_5 ( V_11 , V_4 -> V_29 . V_9 . V_30 , V_4 -> V_12 . V_9 -> V_22 ,
V_31 ) ;
}
F_5 ( V_11 , V_4 -> V_32 , sizeof( struct V_33 ) ,
V_25 ) ;
F_5 ( V_11 , V_4 -> V_34 ,
sizeof( struct V_35 ) ,
V_25 ) ;
F_7 ( V_8 , V_15 ) ;
}
static unsigned long F_8 ( unsigned int V_36 , bool V_37 )
{
unsigned int V_38 = V_36 << 3 ;
switch ( V_38 ) {
case 1536 :
return V_37 ? V_39 : V_40 ;
case 2048 :
return V_37 ? V_41 : V_42 ;
case 3072 :
return V_37 ? V_43 : V_44 ;
case 4096 :
return V_37 ? V_45 : V_46 ;
default:
return 0 ;
} ;
}
static inline struct V_47 * F_9 ( struct V_48 * V_49 )
{
return F_10 ( V_49 ) ;
}
static int F_11 ( struct V_7 * V_4 )
{
struct V_48 * V_49 = F_12 ( V_4 ) ;
struct V_47 * V_12 = F_10 ( V_49 ) ;
struct V_50 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = & F_2 ( V_13 -> V_14 ) ;
struct V_3 * V_51 =
F_13 ( F_14 ( V_4 ) , 64 ) ;
struct V_52 * V_53 = & V_51 -> V_4 ;
int V_54 , V_55 = 0 ;
int V_56 = 0 ;
if ( F_15 ( ! V_12 -> V_57 ) )
return - V_19 ;
if ( V_4 -> V_26 < V_12 -> V_22 ) {
V_4 -> V_26 = V_12 -> V_22 ;
return - V_58 ;
}
memset ( V_53 , '\0' , sizeof( * V_53 ) ) ;
F_16 ( V_53 -> V_59 ,
V_60 ) ;
V_53 -> V_59 . V_61 . V_62 = F_8 ( V_12 -> V_22 ,
! V_4 -> V_20 && V_12 -> V_37 ) ;
if ( F_15 ( ! V_53 -> V_59 . V_61 . V_62 ) )
return - V_19 ;
V_51 -> V_63 = F_1 ;
V_51 -> V_12 . V_9 = V_12 ;
V_51 -> V_8 . V_9 = V_4 ;
V_53 -> V_59 . V_64 = V_65 ;
V_53 -> V_59 . V_66 =
F_17 ( V_67 ,
V_68 ) ;
if ( V_4 -> V_20 ) {
V_51 -> V_23 . V_9 . V_23 . V_57 = V_12 -> V_69 ;
V_51 -> V_23 . V_9 . V_23 . V_70 = V_12 -> V_71 ;
V_56 = 3 ;
} else {
if ( V_12 -> V_37 ) {
V_51 -> V_23 . V_9 . V_72 . V_57 = V_12 -> V_69 ;
V_51 -> V_23 . V_9 . V_72 . V_70 = V_12 -> V_71 ;
V_56 = 2 ;
} else {
V_51 -> V_23 . V_9 . V_23 . V_24 = V_12 -> V_73 ;
V_51 -> V_23 . V_9 . V_23 . V_57 = V_12 -> V_69 ;
V_51 -> V_23 . V_9 . V_23 . V_70 = V_12 -> V_71 ;
V_56 = 3 ;
}
}
V_54 = - V_74 ;
if ( V_4 -> V_20 ) {
if ( F_18 ( V_4 -> V_20 ) && V_4 -> V_75 == V_12 -> V_22 ) {
V_51 -> V_21 = NULL ;
V_51 -> V_23 . V_9 . V_23 . V_24 = F_19 ( V_11 ,
F_20 ( V_4 -> V_20 ) ,
V_4 -> V_75 ,
V_25 ) ;
if ( F_15 ( F_21 ( V_11 ,
V_51 -> V_23 . V_9 . V_23 . V_24 ) ) )
return V_54 ;
} else {
int V_76 = V_12 -> V_22 - V_4 -> V_75 ;
V_51 -> V_21 = F_22 ( V_11 ,
V_12 -> V_22 ,
& V_51 -> V_23 . V_9 . V_23 . V_24 ,
V_77 ) ;
if ( F_15 ( ! V_51 -> V_21 ) )
return V_54 ;
F_6 ( V_51 -> V_21 + V_76 ,
V_4 -> V_20 , 0 , V_4 -> V_75 , 0 ) ;
}
}
if ( F_18 ( V_4 -> V_28 ) && V_4 -> V_26 == V_12 -> V_22 ) {
V_51 -> V_27 = NULL ;
V_51 -> V_29 . V_9 . V_30 = F_19 ( V_11 , F_20 ( V_4 -> V_28 ) ,
V_4 -> V_26 ,
V_31 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_29 . V_9 . V_30 ) ) )
goto V_78;
} else {
V_51 -> V_27 = F_22 ( V_11 , V_12 -> V_22 ,
& V_51 -> V_29 . V_9 . V_30 ,
V_77 ) ;
if ( F_15 ( ! V_51 -> V_27 ) )
goto V_78;
}
V_51 -> V_23 . V_9 . V_79 [ V_56 ] = 0 ;
V_51 -> V_29 . V_9 . V_80 [ 1 ] = 0 ;
V_51 -> V_32 = F_19 ( V_11 , & V_51 -> V_23 . V_9 . V_23 . V_24 ,
sizeof( struct V_33 ) ,
V_25 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_32 ) ) )
goto V_81;
V_51 -> V_34 = F_19 ( V_11 , & V_51 -> V_29 . V_9 . V_30 ,
sizeof( struct V_35 ) ,
V_25 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_34 ) ) )
goto V_82;
V_53 -> V_83 . V_84 = V_51 -> V_32 ;
V_53 -> V_83 . V_85 = V_51 -> V_34 ;
V_53 -> V_83 . V_6 = ( V_86 ) ( V_5 long ) V_51 ;
V_53 -> V_87 = V_56 ;
V_53 -> V_88 = 1 ;
do {
V_54 = F_23 ( V_12 -> V_13 -> V_89 , ( V_90 * ) V_53 ) ;
} while ( V_54 == - V_91 && V_55 ++ < 100 );
if ( ! V_54 )
return - V_92 ;
if ( ! F_21 ( V_11 , V_51 -> V_34 ) )
F_5 ( V_11 , V_51 -> V_34 ,
sizeof( struct V_35 ) ,
V_25 ) ;
V_82:
if ( ! F_21 ( V_11 , V_51 -> V_32 ) )
F_5 ( V_11 , V_51 -> V_32 ,
sizeof( struct V_33 ) ,
V_25 ) ;
V_81:
if ( V_51 -> V_27 )
F_4 ( V_11 , V_12 -> V_22 , V_51 -> V_27 ,
V_51 -> V_29 . V_9 . V_30 ) ;
else
if ( ! F_21 ( V_11 , V_51 -> V_29 . V_9 . V_30 ) )
F_5 ( V_11 , V_51 -> V_29 . V_9 . V_30 , V_12 -> V_22 ,
V_31 ) ;
V_78:
if ( V_4 -> V_20 ) {
if ( V_51 -> V_21 )
F_4 ( V_11 , V_12 -> V_22 , V_51 -> V_21 ,
V_51 -> V_23 . V_9 . V_23 . V_24 ) ;
else
if ( ! F_21 ( V_11 , V_51 -> V_23 . V_9 . V_23 . V_24 ) )
F_5 ( V_11 , V_51 -> V_23 . V_9 . V_23 . V_24 ,
V_12 -> V_22 ,
V_25 ) ;
}
return V_54 ;
}
static int F_24 ( unsigned int V_93 )
{
switch ( V_93 ) {
case 1536 :
case 2048 :
case 3072 :
case 4096 :
return 0 ;
}
return - V_19 ;
}
static int F_25 ( struct V_47 * V_12 , struct V_9 * V_94 )
{
struct V_50 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = & F_2 ( V_13 -> V_14 ) ;
if ( F_15 ( ! V_94 -> V_70 || ! V_94 -> V_95 ) )
return - V_19 ;
if ( F_24 ( V_94 -> V_22 << 3 ) )
return - V_19 ;
V_12 -> V_22 = V_94 -> V_22 ;
V_12 -> V_70 = F_22 ( V_11 , V_12 -> V_22 , & V_12 -> V_71 , V_77 ) ;
if ( ! V_12 -> V_70 )
return - V_74 ;
memcpy ( V_12 -> V_70 , V_94 -> V_70 , V_12 -> V_22 ) ;
if ( V_94 -> V_96 == 1 && * ( char * ) V_94 -> V_95 == 0x02 ) {
V_12 -> V_37 = true ;
return 0 ;
}
V_12 -> V_95 = F_22 ( V_11 , V_12 -> V_22 , & V_12 -> V_73 , V_77 ) ;
if ( ! V_12 -> V_95 ) {
F_4 ( V_11 , V_12 -> V_22 , V_12 -> V_70 , V_12 -> V_71 ) ;
V_12 -> V_70 = NULL ;
return - V_74 ;
}
memcpy ( V_12 -> V_95 + ( V_12 -> V_22 - V_94 -> V_96 ) , V_94 -> V_95 ,
V_94 -> V_96 ) ;
return 0 ;
}
static void F_26 ( struct V_10 * V_11 , struct V_47 * V_12 )
{
if ( V_12 -> V_95 ) {
F_4 ( V_11 , V_12 -> V_22 , V_12 -> V_95 , V_12 -> V_73 ) ;
V_12 -> V_95 = NULL ;
}
if ( V_12 -> V_57 ) {
F_4 ( V_11 , V_12 -> V_22 , V_12 -> V_57 , V_12 -> V_69 ) ;
V_12 -> V_57 = NULL ;
}
if ( V_12 -> V_70 ) {
F_4 ( V_11 , V_12 -> V_22 , V_12 -> V_70 , V_12 -> V_71 ) ;
V_12 -> V_70 = NULL ;
}
V_12 -> V_22 = 0 ;
V_12 -> V_37 = false ;
}
static int F_27 ( struct V_48 * V_49 , const void * V_97 ,
unsigned int V_36 )
{
struct V_47 * V_12 = F_10 ( V_49 ) ;
struct V_10 * V_11 = & F_2 ( V_12 -> V_13 -> V_14 ) ;
struct V_9 V_94 ;
int V_54 ;
if ( F_28 ( V_97 , V_36 , & V_94 ) < 0 )
return - V_19 ;
F_26 ( V_11 , V_12 ) ;
V_54 = F_25 ( V_12 , & V_94 ) ;
if ( V_54 < 0 )
return V_54 ;
V_12 -> V_57 = F_22 ( V_11 , V_12 -> V_22 , & V_12 -> V_69 ,
V_77 ) ;
if ( ! V_12 -> V_57 ) {
F_26 ( V_11 , V_12 ) ;
return - V_74 ;
}
memcpy ( V_12 -> V_57 + ( V_12 -> V_22 - V_94 . V_98 ) , V_94 . V_99 ,
V_94 . V_98 ) ;
return 0 ;
}
static int F_29 ( struct V_48 * V_49 )
{
struct V_47 * V_12 = F_10 ( V_49 ) ;
return V_12 -> V_70 ? V_12 -> V_22 : - V_19 ;
}
static int F_30 ( struct V_48 * V_49 )
{
struct V_47 * V_12 = F_10 ( V_49 ) ;
struct V_50 * V_13 =
F_31 ( F_32 () ) ;
if ( ! V_13 )
return - V_19 ;
V_12 -> V_22 = 0 ;
V_12 -> V_37 = false ;
V_12 -> V_13 = V_13 ;
return 0 ;
}
static void F_33 ( struct V_48 * V_49 )
{
struct V_47 * V_12 = F_10 ( V_49 ) ;
struct V_10 * V_11 = & F_2 ( V_12 -> V_13 -> V_14 ) ;
F_26 ( V_11 , V_12 ) ;
F_34 ( V_12 -> V_13 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = ( void * ) ( V_5 long ) V_2 -> V_6 ;
struct V_100 * V_8 = V_4 -> V_8 . V_101 ;
struct V_10 * V_11 = & F_2 ( V_4 -> V_12 . V_101 -> V_13 -> V_14 ) ;
int V_15 = F_3 (
V_2 -> V_16 . V_17 ) ;
V_15 = ( V_15 == V_18 ) ? 0 : - V_19 ;
if ( V_4 -> V_21 )
F_4 ( V_11 , V_4 -> V_12 . V_101 -> V_102 , V_4 -> V_21 ,
V_4 -> V_23 . V_101 . V_103 . V_104 ) ;
else
F_5 ( V_11 , V_4 -> V_23 . V_101 . V_103 . V_104 , V_4 -> V_12 . V_101 -> V_102 ,
V_25 ) ;
V_8 -> V_26 = V_4 -> V_12 . V_101 -> V_102 ;
if ( V_4 -> V_27 ) {
F_6 ( V_4 -> V_27 , V_8 -> V_28 , 0 ,
V_8 -> V_26 , 1 ) ;
F_4 ( V_11 , V_4 -> V_12 . V_101 -> V_102 , V_4 -> V_27 ,
V_4 -> V_29 . V_101 . V_103 . V_105 ) ;
} else {
F_5 ( V_11 , V_4 -> V_29 . V_101 . V_103 . V_105 , V_4 -> V_12 . V_101 -> V_102 ,
V_31 ) ;
}
F_5 ( V_11 , V_4 -> V_32 , sizeof( struct V_106 ) ,
V_25 ) ;
F_5 ( V_11 , V_4 -> V_34 ,
sizeof( struct V_107 ) ,
V_25 ) ;
F_36 ( V_8 , V_15 ) ;
}
void F_37 ( void * V_108 )
{
struct V_1 * V_2 = V_108 ;
struct V_3 * V_8 = ( void * ) ( V_5 long ) V_2 -> V_6 ;
V_8 -> V_63 ( V_2 ) ;
}
static unsigned long F_38 ( unsigned int V_36 )
{
unsigned int V_38 = V_36 << 3 ;
switch ( V_38 ) {
case 512 :
return V_109 ;
case 1024 :
return V_110 ;
case 1536 :
return V_111 ;
case 2048 :
return V_112 ;
case 3072 :
return V_113 ;
case 4096 :
return V_114 ;
default:
return 0 ;
} ;
}
static unsigned long F_39 ( unsigned int V_36 )
{
unsigned int V_38 = V_36 << 3 ;
switch ( V_38 ) {
case 512 :
return V_115 ;
case 1024 :
return V_116 ;
case 1536 :
return V_117 ;
case 2048 :
return V_118 ;
case 3072 :
return V_119 ;
case 4096 :
return V_120 ;
default:
return 0 ;
} ;
}
static unsigned long F_40 ( unsigned int V_36 )
{
unsigned int V_38 = V_36 << 3 ;
switch ( V_38 ) {
case 512 :
return V_121 ;
case 1024 :
return V_122 ;
case 1536 :
return V_123 ;
case 2048 :
return V_124 ;
case 3072 :
return V_125 ;
case 4096 :
return V_126 ;
default:
return 0 ;
} ;
}
static int F_41 ( struct V_100 * V_4 )
{
struct V_127 * V_49 = F_42 ( V_4 ) ;
struct V_128 * V_12 = F_43 ( V_49 ) ;
struct V_50 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = & F_2 ( V_13 -> V_14 ) ;
struct V_3 * V_51 =
F_13 ( F_44 ( V_4 ) , 64 ) ;
struct V_52 * V_53 = & V_51 -> V_4 ;
int V_54 , V_55 = 0 ;
if ( F_15 ( ! V_12 -> V_129 || ! V_12 -> V_130 ) )
return - V_19 ;
if ( V_4 -> V_26 < V_12 -> V_102 ) {
V_4 -> V_26 = V_12 -> V_102 ;
return - V_58 ;
}
memset ( V_53 , '\0' , sizeof( * V_53 ) ) ;
F_16 ( V_53 -> V_59 ,
V_60 ) ;
V_53 -> V_59 . V_61 . V_62 = F_38 ( V_12 -> V_102 ) ;
if ( F_15 ( ! V_53 -> V_59 . V_61 . V_62 ) )
return - V_19 ;
V_51 -> V_63 = F_35 ;
V_51 -> V_12 . V_101 = V_12 ;
V_51 -> V_8 . V_101 = V_4 ;
V_53 -> V_59 . V_64 = V_65 ;
V_53 -> V_59 . V_66 =
F_17 ( V_67 ,
V_68 ) ;
V_51 -> V_23 . V_101 . V_103 . V_130 = V_12 -> V_131 ;
V_51 -> V_23 . V_101 . V_103 . V_129 = V_12 -> V_132 ;
V_54 = - V_74 ;
if ( F_18 ( V_4 -> V_20 ) && V_4 -> V_75 == V_12 -> V_102 ) {
V_51 -> V_21 = NULL ;
V_51 -> V_23 . V_101 . V_103 . V_104 = F_19 ( V_11 , F_20 ( V_4 -> V_20 ) ,
V_4 -> V_75 , V_25 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_23 . V_101 . V_103 . V_104 ) ) )
return V_54 ;
} else {
int V_76 = V_12 -> V_102 - V_4 -> V_75 ;
V_51 -> V_21 = F_22 ( V_11 , V_12 -> V_102 ,
& V_51 -> V_23 . V_101 . V_103 . V_104 ,
V_77 ) ;
if ( F_15 ( ! V_51 -> V_21 ) )
return V_54 ;
F_6 ( V_51 -> V_21 + V_76 , V_4 -> V_20 ,
0 , V_4 -> V_75 , 0 ) ;
}
if ( F_18 ( V_4 -> V_28 ) && V_4 -> V_26 == V_12 -> V_102 ) {
V_51 -> V_27 = NULL ;
V_51 -> V_29 . V_101 . V_103 . V_105 = F_19 ( V_11 , F_20 ( V_4 -> V_28 ) ,
V_4 -> V_26 ,
V_31 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_29 . V_101 . V_103 . V_105 ) ) )
goto V_78;
} else {
V_51 -> V_27 = F_22 ( V_11 , V_12 -> V_102 ,
& V_51 -> V_29 . V_101 . V_103 . V_105 ,
V_77 ) ;
if ( F_15 ( ! V_51 -> V_27 ) )
goto V_78;
}
V_51 -> V_23 . V_101 . V_79 [ 3 ] = 0 ;
V_51 -> V_29 . V_101 . V_80 [ 1 ] = 0 ;
V_51 -> V_32 = F_19 ( V_11 , & V_51 -> V_23 . V_101 . V_103 . V_104 ,
sizeof( struct V_106 ) ,
V_25 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_32 ) ) )
goto V_81;
V_51 -> V_34 = F_19 ( V_11 , & V_51 -> V_29 . V_101 . V_103 . V_105 ,
sizeof( struct V_107 ) ,
V_25 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_34 ) ) )
goto V_82;
V_53 -> V_83 . V_84 = V_51 -> V_32 ;
V_53 -> V_83 . V_85 = V_51 -> V_34 ;
V_53 -> V_83 . V_6 = ( V_86 ) ( V_5 long ) V_51 ;
V_53 -> V_87 = 3 ;
V_53 -> V_88 = 1 ;
do {
V_54 = F_23 ( V_12 -> V_13 -> V_89 , ( V_90 * ) V_53 ) ;
} while ( V_54 == - V_91 && V_55 ++ < 100 );
if ( ! V_54 )
return - V_92 ;
if ( ! F_21 ( V_11 , V_51 -> V_34 ) )
F_5 ( V_11 , V_51 -> V_34 ,
sizeof( struct V_107 ) ,
V_25 ) ;
V_82:
if ( ! F_21 ( V_11 , V_51 -> V_32 ) )
F_5 ( V_11 , V_51 -> V_32 ,
sizeof( struct V_106 ) ,
V_25 ) ;
V_81:
if ( V_51 -> V_27 )
F_4 ( V_11 , V_12 -> V_102 , V_51 -> V_27 ,
V_51 -> V_29 . V_101 . V_103 . V_105 ) ;
else
if ( ! F_21 ( V_11 , V_51 -> V_29 . V_101 . V_103 . V_105 ) )
F_5 ( V_11 , V_51 -> V_29 . V_101 . V_103 . V_105 ,
V_12 -> V_102 , V_31 ) ;
V_78:
if ( V_51 -> V_21 )
F_4 ( V_11 , V_12 -> V_102 , V_51 -> V_21 ,
V_51 -> V_23 . V_101 . V_103 . V_104 ) ;
else
if ( ! F_21 ( V_11 , V_51 -> V_23 . V_101 . V_103 . V_104 ) )
F_5 ( V_11 , V_51 -> V_23 . V_101 . V_103 . V_104 ,
V_12 -> V_102 , V_25 ) ;
return V_54 ;
}
static int F_45 ( struct V_100 * V_4 )
{
struct V_127 * V_49 = F_42 ( V_4 ) ;
struct V_128 * V_12 = F_43 ( V_49 ) ;
struct V_50 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = & F_2 ( V_13 -> V_14 ) ;
struct V_3 * V_51 =
F_13 ( F_44 ( V_4 ) , 64 ) ;
struct V_52 * V_53 = & V_51 -> V_4 ;
int V_54 , V_55 = 0 ;
if ( F_15 ( ! V_12 -> V_129 || ! V_12 -> V_133 ) )
return - V_19 ;
if ( V_4 -> V_26 < V_12 -> V_102 ) {
V_4 -> V_26 = V_12 -> V_102 ;
return - V_58 ;
}
memset ( V_53 , '\0' , sizeof( * V_53 ) ) ;
F_16 ( V_53 -> V_59 ,
V_60 ) ;
V_53 -> V_59 . V_61 . V_62 = V_12 -> V_134 ?
F_40 ( V_12 -> V_102 ) :
F_39 ( V_12 -> V_102 ) ;
if ( F_15 ( ! V_53 -> V_59 . V_61 . V_62 ) )
return - V_19 ;
V_51 -> V_63 = F_35 ;
V_51 -> V_12 . V_101 = V_12 ;
V_51 -> V_8 . V_101 = V_4 ;
V_53 -> V_59 . V_64 = V_65 ;
V_53 -> V_59 . V_66 =
F_17 ( V_67 ,
V_68 ) ;
if ( V_12 -> V_134 ) {
V_51 -> V_23 . V_101 . V_135 . V_70 = V_12 -> V_71 ;
V_51 -> V_23 . V_101 . V_135 . V_136 = V_12 -> V_137 ;
V_51 -> V_23 . V_101 . V_135 . V_138 = V_12 -> V_139 ;
V_51 -> V_23 . V_101 . V_135 . V_140 = V_12 -> V_141 ;
V_51 -> V_23 . V_101 . V_135 . V_142 = V_12 -> V_143 ;
} else {
V_51 -> V_23 . V_101 . V_144 . V_133 = V_12 -> V_145 ;
V_51 -> V_23 . V_101 . V_144 . V_129 = V_12 -> V_132 ;
}
V_54 = - V_74 ;
if ( F_18 ( V_4 -> V_20 ) && V_4 -> V_75 == V_12 -> V_102 ) {
V_51 -> V_21 = NULL ;
V_51 -> V_23 . V_101 . V_144 . V_105 = F_19 ( V_11 , F_20 ( V_4 -> V_20 ) ,
V_4 -> V_26 , V_25 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_23 . V_101 . V_144 . V_105 ) ) )
return V_54 ;
} else {
int V_76 = V_12 -> V_102 - V_4 -> V_75 ;
V_51 -> V_21 = F_22 ( V_11 , V_12 -> V_102 ,
& V_51 -> V_23 . V_101 . V_144 . V_105 ,
V_77 ) ;
if ( F_15 ( ! V_51 -> V_21 ) )
return V_54 ;
F_6 ( V_51 -> V_21 + V_76 , V_4 -> V_20 ,
0 , V_4 -> V_75 , 0 ) ;
}
if ( F_18 ( V_4 -> V_28 ) && V_4 -> V_26 == V_12 -> V_102 ) {
V_51 -> V_27 = NULL ;
V_51 -> V_29 . V_101 . V_144 . V_104 = F_19 ( V_11 , F_20 ( V_4 -> V_28 ) ,
V_4 -> V_26 ,
V_31 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_29 . V_101 . V_144 . V_104 ) ) )
goto V_78;
} else {
V_51 -> V_27 = F_22 ( V_11 , V_12 -> V_102 ,
& V_51 -> V_29 . V_101 . V_144 . V_104 ,
V_77 ) ;
if ( F_15 ( ! V_51 -> V_27 ) )
goto V_78;
}
if ( V_12 -> V_134 )
V_51 -> V_23 . V_101 . V_79 [ 6 ] = 0 ;
else
V_51 -> V_23 . V_101 . V_79 [ 3 ] = 0 ;
V_51 -> V_29 . V_101 . V_80 [ 1 ] = 0 ;
V_51 -> V_32 = F_19 ( V_11 , & V_51 -> V_23 . V_101 . V_144 . V_105 ,
sizeof( struct V_106 ) ,
V_25 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_32 ) ) )
goto V_81;
V_51 -> V_34 = F_19 ( V_11 , & V_51 -> V_29 . V_101 . V_144 . V_104 ,
sizeof( struct V_107 ) ,
V_25 ) ;
if ( F_15 ( F_21 ( V_11 , V_51 -> V_34 ) ) )
goto V_82;
V_53 -> V_83 . V_84 = V_51 -> V_32 ;
V_53 -> V_83 . V_85 = V_51 -> V_34 ;
V_53 -> V_83 . V_6 = ( V_86 ) ( V_5 long ) V_51 ;
if ( V_12 -> V_134 )
V_53 -> V_87 = 6 ;
else
V_53 -> V_87 = 3 ;
V_53 -> V_88 = 1 ;
do {
V_54 = F_23 ( V_12 -> V_13 -> V_89 , ( V_90 * ) V_53 ) ;
} while ( V_54 == - V_91 && V_55 ++ < 100 );
if ( ! V_54 )
return - V_92 ;
if ( ! F_21 ( V_11 , V_51 -> V_34 ) )
F_5 ( V_11 , V_51 -> V_34 ,
sizeof( struct V_107 ) ,
V_25 ) ;
V_82:
if ( ! F_21 ( V_11 , V_51 -> V_32 ) )
F_5 ( V_11 , V_51 -> V_32 ,
sizeof( struct V_106 ) ,
V_25 ) ;
V_81:
if ( V_51 -> V_27 )
F_4 ( V_11 , V_12 -> V_102 , V_51 -> V_27 ,
V_51 -> V_29 . V_101 . V_144 . V_104 ) ;
else
if ( ! F_21 ( V_11 , V_51 -> V_29 . V_101 . V_144 . V_104 ) )
F_5 ( V_11 , V_51 -> V_29 . V_101 . V_144 . V_104 ,
V_12 -> V_102 , V_31 ) ;
V_78:
if ( V_51 -> V_21 )
F_4 ( V_11 , V_12 -> V_102 , V_51 -> V_21 ,
V_51 -> V_23 . V_101 . V_144 . V_105 ) ;
else
if ( ! F_21 ( V_11 , V_51 -> V_23 . V_101 . V_144 . V_105 ) )
F_5 ( V_11 , V_51 -> V_23 . V_101 . V_144 . V_105 ,
V_12 -> V_102 , V_25 ) ;
return V_54 ;
}
int F_46 ( struct V_128 * V_12 , const char * V_146 , T_1 V_147 )
{
struct V_50 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = & F_2 ( V_13 -> V_14 ) ;
const char * V_148 = V_146 ;
int V_54 ;
while ( ! * V_148 && V_147 ) {
V_148 ++ ;
V_147 -- ;
}
V_12 -> V_102 = V_147 ;
V_54 = - V_19 ;
if ( ! F_38 ( V_12 -> V_102 ) )
goto V_15;
V_54 = - V_74 ;
V_12 -> V_129 = F_22 ( V_11 , V_12 -> V_102 , & V_12 -> V_132 , V_77 ) ;
if ( ! V_12 -> V_129 )
goto V_15;
memcpy ( V_12 -> V_129 , V_148 , V_12 -> V_102 ) ;
return 0 ;
V_15:
V_12 -> V_102 = 0 ;
V_12 -> V_129 = NULL ;
return V_54 ;
}
int F_47 ( struct V_128 * V_12 , const char * V_146 , T_1 V_147 )
{
struct V_50 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = & F_2 ( V_13 -> V_14 ) ;
const char * V_148 = V_146 ;
while ( ! * V_148 && V_147 ) {
V_148 ++ ;
V_147 -- ;
}
if ( ! V_12 -> V_102 || ! V_147 || V_147 > V_12 -> V_102 ) {
V_12 -> V_130 = NULL ;
return - V_19 ;
}
V_12 -> V_130 = F_22 ( V_11 , V_12 -> V_102 , & V_12 -> V_131 , V_77 ) ;
if ( ! V_12 -> V_130 )
return - V_74 ;
memcpy ( V_12 -> V_130 + ( V_12 -> V_102 - V_147 ) , V_148 , V_147 ) ;
return 0 ;
}
int F_48 ( struct V_128 * V_12 , const char * V_146 , T_1 V_147 )
{
struct V_50 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = & F_2 ( V_13 -> V_14 ) ;
const char * V_148 = V_146 ;
int V_54 ;
while ( ! * V_148 && V_147 ) {
V_148 ++ ;
V_147 -- ;
}
V_54 = - V_19 ;
if ( ! V_12 -> V_102 || ! V_147 || V_147 > V_12 -> V_102 )
goto V_15;
V_54 = - V_74 ;
V_12 -> V_133 = F_22 ( V_11 , V_12 -> V_102 , & V_12 -> V_145 , V_77 ) ;
if ( ! V_12 -> V_133 )
goto V_15;
memcpy ( V_12 -> V_133 + ( V_12 -> V_102 - V_147 ) , V_148 , V_147 ) ;
return 0 ;
V_15:
V_12 -> V_133 = NULL ;
return V_54 ;
}
static void F_49 ( const char * * V_148 , unsigned int * V_36 )
{
while ( ! * * V_148 && * V_36 ) {
( * V_148 ) ++ ;
( * V_36 ) -- ;
}
}
static void F_50 ( struct V_128 * V_12 , struct V_149 * V_149 )
{
struct V_50 * V_13 = V_12 -> V_13 ;
struct V_10 * V_11 = & F_2 ( V_13 -> V_14 ) ;
const char * V_148 ;
unsigned int V_36 ;
unsigned int V_150 = V_12 -> V_102 / 2 ;
V_148 = V_149 -> V_70 ;
V_36 = V_149 -> V_151 ;
F_49 ( & V_148 , & V_36 ) ;
if ( ! V_36 )
goto V_15;
V_12 -> V_70 = F_22 ( V_11 , V_150 , & V_12 -> V_71 , V_77 ) ;
if ( ! V_12 -> V_70 )
goto V_15;
memcpy ( V_12 -> V_70 + ( V_150 - V_36 ) , V_148 , V_36 ) ;
V_148 = V_149 -> V_136 ;
V_36 = V_149 -> V_152 ;
F_49 ( & V_148 , & V_36 ) ;
if ( ! V_36 )
goto V_153;
V_12 -> V_136 = F_22 ( V_11 , V_150 , & V_12 -> V_137 , V_77 ) ;
if ( ! V_12 -> V_136 )
goto V_153;
memcpy ( V_12 -> V_136 + ( V_150 - V_36 ) , V_148 , V_36 ) ;
V_148 = V_149 -> V_138 ;
V_36 = V_149 -> V_154 ;
F_49 ( & V_148 , & V_36 ) ;
if ( ! V_36 )
goto V_155;
V_12 -> V_138 = F_22 ( V_11 , V_150 , & V_12 -> V_139 ,
V_77 ) ;
if ( ! V_12 -> V_138 )
goto V_155;
memcpy ( V_12 -> V_138 + ( V_150 - V_36 ) , V_148 , V_36 ) ;
V_148 = V_149 -> V_140 ;
V_36 = V_149 -> V_156 ;
F_49 ( & V_148 , & V_36 ) ;
if ( ! V_36 )
goto V_157;
V_12 -> V_140 = F_22 ( V_11 , V_150 , & V_12 -> V_141 ,
V_77 ) ;
if ( ! V_12 -> V_140 )
goto V_157;
memcpy ( V_12 -> V_140 + ( V_150 - V_36 ) , V_148 , V_36 ) ;
V_148 = V_149 -> V_142 ;
V_36 = V_149 -> V_158 ;
F_49 ( & V_148 , & V_36 ) ;
if ( ! V_36 )
goto V_159;
V_12 -> V_142 = F_22 ( V_11 , V_150 , & V_12 -> V_143 ,
V_77 ) ;
if ( ! V_12 -> V_142 )
goto V_159;
memcpy ( V_12 -> V_142 + ( V_150 - V_36 ) , V_148 , V_36 ) ;
V_12 -> V_134 = true ;
return;
V_159:
memset ( V_12 -> V_140 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_140 , V_12 -> V_141 ) ;
V_12 -> V_140 = NULL ;
V_157:
memset ( V_12 -> V_138 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_138 , V_12 -> V_139 ) ;
V_12 -> V_138 = NULL ;
V_155:
memset ( V_12 -> V_136 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_136 , V_12 -> V_137 ) ;
V_12 -> V_136 = NULL ;
V_153:
memset ( V_12 -> V_70 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_70 , V_12 -> V_71 ) ;
V_12 -> V_70 = NULL ;
V_15:
V_12 -> V_134 = false ;
}
static void F_51 ( struct V_10 * V_11 , struct V_128 * V_12 )
{
unsigned int V_150 = V_12 -> V_102 / 2 ;
if ( V_12 -> V_129 )
F_4 ( V_11 , V_12 -> V_102 , V_12 -> V_129 , V_12 -> V_132 ) ;
if ( V_12 -> V_130 )
F_4 ( V_11 , V_12 -> V_102 , V_12 -> V_130 , V_12 -> V_131 ) ;
if ( V_12 -> V_133 ) {
memset ( V_12 -> V_133 , '\0' , V_12 -> V_102 ) ;
F_4 ( V_11 , V_12 -> V_102 , V_12 -> V_133 , V_12 -> V_145 ) ;
}
if ( V_12 -> V_70 ) {
memset ( V_12 -> V_70 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_70 , V_12 -> V_71 ) ;
}
if ( V_12 -> V_136 ) {
memset ( V_12 -> V_136 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_136 , V_12 -> V_137 ) ;
}
if ( V_12 -> V_138 ) {
memset ( V_12 -> V_138 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_138 , V_12 -> V_139 ) ;
}
if ( V_12 -> V_140 ) {
memset ( V_12 -> V_140 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_140 , V_12 -> V_141 ) ;
}
if ( V_12 -> V_142 ) {
memset ( V_12 -> V_142 , '\0' , V_150 ) ;
F_4 ( V_11 , V_150 , V_12 -> V_142 , V_12 -> V_143 ) ;
}
V_12 -> V_129 = NULL ;
V_12 -> V_130 = NULL ;
V_12 -> V_133 = NULL ;
V_12 -> V_70 = NULL ;
V_12 -> V_136 = NULL ;
V_12 -> V_138 = NULL ;
V_12 -> V_140 = NULL ;
V_12 -> V_142 = NULL ;
V_12 -> V_134 = false ;
V_12 -> V_102 = 0 ;
}
static int F_52 ( struct V_127 * V_49 , const void * V_99 ,
unsigned int V_160 , bool V_161 )
{
struct V_128 * V_12 = F_43 ( V_49 ) ;
struct V_10 * V_11 = & F_2 ( V_12 -> V_13 -> V_14 ) ;
struct V_149 V_149 ;
int V_54 ;
F_51 ( V_11 , V_12 ) ;
if ( V_161 )
V_54 = F_53 ( & V_149 , V_99 , V_160 ) ;
else
V_54 = F_54 ( & V_149 , V_99 , V_160 ) ;
if ( V_54 < 0 )
goto free;
V_54 = F_46 ( V_12 , V_149 . V_129 , V_149 . V_162 ) ;
if ( V_54 < 0 )
goto free;
V_54 = F_47 ( V_12 , V_149 . V_130 , V_149 . V_163 ) ;
if ( V_54 < 0 )
goto free;
if ( V_161 ) {
V_54 = F_48 ( V_12 , V_149 . V_133 , V_149 . V_164 ) ;
if ( V_54 < 0 )
goto free;
F_50 ( V_12 , & V_149 ) ;
}
if ( ! V_12 -> V_129 || ! V_12 -> V_130 ) {
V_54 = - V_19 ;
goto free;
}
if ( V_161 && ! V_12 -> V_133 ) {
V_54 = - V_19 ;
goto free;
}
return 0 ;
free:
F_51 ( V_11 , V_12 ) ;
return V_54 ;
}
static int F_55 ( struct V_127 * V_49 , const void * V_99 ,
unsigned int V_160 )
{
return F_52 ( V_49 , V_99 , V_160 , false ) ;
}
static int F_56 ( struct V_127 * V_49 , const void * V_99 ,
unsigned int V_160 )
{
return F_52 ( V_49 , V_99 , V_160 , true ) ;
}
static int F_57 ( struct V_127 * V_49 )
{
struct V_128 * V_12 = F_43 ( V_49 ) ;
return ( V_12 -> V_129 ) ? V_12 -> V_102 : - V_19 ;
}
static int F_58 ( struct V_127 * V_49 )
{
struct V_128 * V_12 = F_43 ( V_49 ) ;
struct V_50 * V_13 =
F_31 ( F_32 () ) ;
if ( ! V_13 )
return - V_19 ;
V_12 -> V_102 = 0 ;
V_12 -> V_13 = V_13 ;
return 0 ;
}
static void F_59 ( struct V_127 * V_49 )
{
struct V_128 * V_12 = F_43 ( V_49 ) ;
struct V_10 * V_11 = & F_2 ( V_12 -> V_13 -> V_14 ) ;
if ( V_12 -> V_129 )
F_4 ( V_11 , V_12 -> V_102 , V_12 -> V_129 , V_12 -> V_132 ) ;
if ( V_12 -> V_130 )
F_4 ( V_11 , V_12 -> V_102 , V_12 -> V_130 , V_12 -> V_131 ) ;
if ( V_12 -> V_133 ) {
memset ( V_12 -> V_133 , '\0' , V_12 -> V_102 ) ;
F_4 ( V_11 , V_12 -> V_102 , V_12 -> V_133 , V_12 -> V_145 ) ;
}
F_34 ( V_12 -> V_13 ) ;
V_12 -> V_129 = NULL ;
V_12 -> V_130 = NULL ;
V_12 -> V_133 = NULL ;
}
int F_60 ( void )
{
int V_54 = 0 ;
F_61 ( & V_165 ) ;
if ( ++ V_166 == 1 ) {
V_101 . V_167 . V_168 = 0 ;
V_54 = F_62 ( & V_101 ) ;
if ( V_54 )
goto V_169;
V_54 = F_63 ( & V_9 ) ;
}
V_169:
F_64 ( & V_165 ) ;
return V_54 ;
}
void F_65 ( void )
{
F_61 ( & V_165 ) ;
if ( -- V_166 == 0 ) {
F_66 ( & V_101 ) ;
F_67 ( & V_9 ) ;
}
F_64 ( & V_165 ) ;
}

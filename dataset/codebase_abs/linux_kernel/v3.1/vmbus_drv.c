static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 V_6 ;
if ( ! V_2 -> V_7 )
return;
F_2 ( V_2 -> V_7 , & V_6 ) ;
V_4 -> V_8 = V_6 . V_9 ;
V_4 -> V_10 = V_6 . V_11 ;
memcpy ( & V_4 -> V_12 , & V_6 . V_13 ,
sizeof( struct V_14 ) ) ;
memcpy ( & V_4 -> V_15 , & V_6 . V_16 ,
sizeof( struct V_14 ) ) ;
V_4 -> V_17 = V_6 . V_18 ;
V_4 -> V_19 = V_6 . V_20 ;
V_4 -> V_21 = V_6 . V_22 ;
V_4 -> V_23 = V_6 . V_24 ;
V_4 -> V_25 = V_6 . V_26 ;
V_4 -> V_27 = V_6 . V_28 ;
V_4 -> V_29 = V_6 . V_30 ;
V_4 -> V_31 . V_32 = V_6 . V_31 . V_33 ;
V_4 -> V_31 . V_34 = V_6 . V_31 . V_35 ;
V_4 -> V_31 . V_36 = V_6 . V_31 . V_37 ;
V_4 -> V_31 . V_38 =
V_6 . V_31 . V_38 ;
V_4 -> V_31 . V_39 =
V_6 . V_31 . V_39 ;
V_4 -> V_40 . V_32 =
V_6 . V_40 . V_33 ;
V_4 -> V_40 . V_34 = V_6 . V_40 . V_35 ;
V_4 -> V_40 . V_36 = V_6 . V_40 . V_37 ;
V_4 -> V_40 . V_38 =
V_6 . V_40 . V_38 ;
V_4 -> V_40 . V_39 =
V_6 . V_40 . V_39 ;
}
static T_1 F_3 ( struct V_2 * V_41 ,
struct V_42 * V_43 ,
char * V_44 )
{
struct V_1 * V_45 = F_4 ( V_41 ) ;
struct V_3 V_46 ;
memset ( & V_46 , 0 , sizeof( struct V_3 ) ) ;
F_1 ( V_45 , & V_46 ) ;
if ( ! strcmp ( V_43 -> V_47 . V_48 , L_1 ) ) {
return sprintf ( V_44 , L_2
L_3 ,
V_46 . V_12 . V_49 [ 3 ] ,
V_46 . V_12 . V_49 [ 2 ] ,
V_46 . V_12 . V_49 [ 1 ] ,
V_46 . V_12 . V_49 [ 0 ] ,
V_46 . V_12 . V_49 [ 5 ] ,
V_46 . V_12 . V_49 [ 4 ] ,
V_46 . V_12 . V_49 [ 7 ] ,
V_46 . V_12 . V_49 [ 6 ] ,
V_46 . V_12 . V_49 [ 8 ] ,
V_46 . V_12 . V_49 [ 9 ] ,
V_46 . V_12 . V_49 [ 10 ] ,
V_46 . V_12 . V_49 [ 11 ] ,
V_46 . V_12 . V_49 [ 12 ] ,
V_46 . V_12 . V_49 [ 13 ] ,
V_46 . V_12 . V_49 [ 14 ] ,
V_46 . V_12 . V_49 [ 15 ] ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_4 ) ) {
return sprintf ( V_44 , L_2
L_3 ,
V_46 . V_15 . V_49 [ 3 ] ,
V_46 . V_15 . V_49 [ 2 ] ,
V_46 . V_15 . V_49 [ 1 ] ,
V_46 . V_15 . V_49 [ 0 ] ,
V_46 . V_15 . V_49 [ 5 ] ,
V_46 . V_15 . V_49 [ 4 ] ,
V_46 . V_15 . V_49 [ 7 ] ,
V_46 . V_15 . V_49 [ 6 ] ,
V_46 . V_15 . V_49 [ 8 ] ,
V_46 . V_15 . V_49 [ 9 ] ,
V_46 . V_15 . V_49 [ 10 ] ,
V_46 . V_15 . V_49 [ 11 ] ,
V_46 . V_15 . V_49 [ 12 ] ,
V_46 . V_15 . V_49 [ 13 ] ,
V_46 . V_15 . V_49 [ 14 ] ,
V_46 . V_15 . V_49 [ 15 ] ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_5 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_10 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_7 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_8 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_8 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_40 . V_32 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_9 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_40 . V_34 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_10 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_40 . V_36 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_11 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_40 . V_38 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_12 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_40 . V_39 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_13 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_31 . V_32 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_14 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_31 . V_34 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_15 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_31 . V_36 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_16 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_31 . V_38 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_17 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_31 . V_39 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_18 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_17 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_19 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_19 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_20 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_21 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_21 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_23 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_22 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_25 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_23 ) ) {
return sprintf ( V_44 , L_6 , V_46 . V_27 ) ;
} else if ( ! strcmp ( V_43 -> V_47 . V_48 , L_24 ) ) {
return sprintf ( V_44 , L_6 ,
V_46 . V_29 ) ;
} else {
return 0 ;
}
}
static int F_5 ( struct V_2 * V_2 , struct V_50 * V_51 )
{
struct V_1 * V_41 = F_4 ( V_2 ) ;
int V_52 ;
V_52 = F_6 ( V_51 , L_25
L_26
L_27 ,
V_41 -> V_53 . V_49 [ 3 ] ,
V_41 -> V_53 . V_49 [ 2 ] ,
V_41 -> V_53 . V_49 [ 1 ] ,
V_41 -> V_53 . V_49 [ 0 ] ,
V_41 -> V_53 . V_49 [ 5 ] ,
V_41 -> V_53 . V_49 [ 4 ] ,
V_41 -> V_53 . V_49 [ 7 ] ,
V_41 -> V_53 . V_49 [ 6 ] ,
V_41 -> V_53 . V_49 [ 8 ] ,
V_41 -> V_53 . V_49 [ 9 ] ,
V_41 -> V_53 . V_49 [ 10 ] ,
V_41 -> V_53 . V_49 [ 11 ] ,
V_41 -> V_53 . V_49 [ 12 ] ,
V_41 -> V_53 . V_49 [ 13 ] ,
V_41 -> V_53 . V_49 [ 14 ] ,
V_41 -> V_53 . V_49 [ 15 ] ) ;
if ( V_52 )
return V_52 ;
V_52 = F_6 ( V_51 , L_28
L_26
L_27 ,
V_41 -> V_54 . V_49 [ 3 ] ,
V_41 -> V_54 . V_49 [ 2 ] ,
V_41 -> V_54 . V_49 [ 1 ] ,
V_41 -> V_54 . V_49 [ 0 ] ,
V_41 -> V_54 . V_49 [ 5 ] ,
V_41 -> V_54 . V_49 [ 4 ] ,
V_41 -> V_54 . V_49 [ 7 ] ,
V_41 -> V_54 . V_49 [ 6 ] ,
V_41 -> V_54 . V_49 [ 8 ] ,
V_41 -> V_54 . V_49 [ 9 ] ,
V_41 -> V_54 . V_49 [ 10 ] ,
V_41 -> V_54 . V_49 [ 11 ] ,
V_41 -> V_54 . V_49 [ 12 ] ,
V_41 -> V_54 . V_49 [ 13 ] ,
V_41 -> V_54 . V_49 [ 14 ] ,
V_41 -> V_54 . V_49 [ 15 ] ) ;
if ( V_52 )
return V_52 ;
return 0 ;
}
static int F_7 ( struct V_2 * V_2 , struct V_55 * V_56 )
{
int V_57 = 0 ;
struct V_58 * V_59 = F_8 ( V_56 ) ;
struct V_1 * V_45 = F_4 ( V_2 ) ;
if ( memcmp ( & V_45 -> V_53 , & V_59 -> V_53 ,
sizeof( struct V_14 ) ) == 0 )
V_57 = 1 ;
return V_57 ;
}
static int F_9 ( struct V_2 * V_60 )
{
int V_52 = 0 ;
struct V_58 * V_59 =
F_8 ( V_60 -> V_56 ) ;
struct V_1 * V_41 = F_4 ( V_60 ) ;
if ( V_59 -> V_61 ) {
V_52 = V_59 -> V_61 ( V_41 ) ;
if ( V_52 != 0 )
F_10 ( L_29 ,
F_11 ( V_60 ) , V_52 ) ;
} else {
F_10 ( L_30 ,
F_11 ( V_60 ) ) ;
V_52 = - V_62 ;
}
return V_52 ;
}
static int F_12 ( struct V_2 * V_60 )
{
int V_52 ;
struct V_58 * V_59 ;
struct V_1 * V_41 = F_4 ( V_60 ) ;
if ( V_60 -> V_56 ) {
V_59 = F_8 ( V_60 -> V_56 ) ;
if ( V_59 -> remove ) {
V_52 = V_59 -> remove ( V_41 ) ;
} else {
F_10 ( L_31 ,
F_11 ( V_60 ) ) ;
V_52 = - V_62 ;
}
}
return 0 ;
}
static void F_13 ( struct V_2 * V_60 )
{
struct V_58 * V_59 ;
struct V_1 * V_41 = F_4 ( V_60 ) ;
if ( ! V_60 -> V_56 )
return;
V_59 = F_8 ( V_60 -> V_56 ) ;
if ( V_59 -> V_63 )
V_59 -> V_63 ( V_41 ) ;
return;
}
static void F_14 ( struct V_2 * V_2 )
{
struct V_1 * V_45 = F_4 ( V_2 ) ;
F_15 ( V_45 ) ;
}
static void F_16 ( struct V_64 * V_65 )
{
struct V_66 * V_67 ;
V_67 = F_17 ( V_65 , struct V_66 ,
V_65 ) ;
F_18 ( & V_67 -> V_68 ) ;
F_15 ( V_67 ) ;
}
static void F_19 ( unsigned long V_49 )
{
int V_69 = F_20 () ;
void * V_70 = V_71 . V_72 [ V_69 ] ;
struct V_73 * V_68 = (struct V_73 * ) V_70 +
V_74 ;
struct V_66 * V_67 ;
while ( 1 ) {
if ( V_68 -> V_75 . V_76 == V_77 ) {
break;
} else {
V_67 = F_21 ( sizeof( * V_67 ) , V_78 ) ;
if ( V_67 == NULL )
continue;
F_22 ( & V_67 -> V_65 , F_16 ) ;
memcpy ( & V_67 -> V_68 , V_68 , sizeof( * V_68 ) ) ;
F_23 ( V_79 . V_80 , & V_67 -> V_65 ) ;
}
V_68 -> V_75 . V_76 = V_77 ;
F_24 () ;
if ( V_68 -> V_75 . V_81 . V_82 ) {
F_25 ( V_83 , 0 ) ;
}
}
}
static int F_26 ( void )
{
int V_52 = 0 ;
int V_69 = F_20 () ;
void * V_70 ;
struct V_73 * V_68 ;
union V_84 * V_85 ;
V_70 = V_71 . V_72 [ V_69 ] ;
V_68 = (struct V_73 * ) V_70 + V_74 ;
if ( V_68 -> V_75 . V_76 != V_77 )
V_52 |= 0x1 ;
V_70 = V_71 . V_86 [ V_69 ] ;
V_85 = (union V_84 * ) V_70 + V_74 ;
if ( F_27 ( 0 , ( unsigned long * ) & V_85 -> V_87 [ 0 ] ) )
V_52 |= 0x2 ;
return V_52 ;
}
static T_2 F_28 ( int V_88 , void * V_89 )
{
int V_52 ;
V_52 = F_26 () ;
if ( V_52 > 0 ) {
if ( F_29 ( 0 , ( unsigned long * ) & V_52 ) )
F_30 ( & V_90 ) ;
if ( F_29 ( 1 , ( unsigned long * ) & V_52 ) )
F_30 ( & V_91 ) ;
return V_92 ;
} else {
return V_93 ;
}
}
static int F_31 ( int V_88 )
{
int V_52 ;
unsigned int V_94 ;
V_52 = F_32 () ;
if ( V_52 != 0 ) {
F_10 ( L_32 , V_52 ) ;
return V_52 ;
}
F_33 ( & V_90 , F_19 , 0 ) ;
F_33 ( & V_91 , V_95 , 0 ) ;
V_52 = F_34 ( & V_96 ) ;
if ( V_52 )
return V_52 ;
V_52 = F_35 ( V_88 , F_28 , V_97 ,
V_98 , V_99 ) ;
if ( V_52 != 0 ) {
F_10 ( L_33 ,
V_88 ) ;
F_36 ( & V_96 ) ;
return V_52 ;
}
V_94 = V_100 + V_88 ;
F_37 ( V_101 , ( void * ) & V_94 , 1 ) ;
V_52 = F_38 () ;
if ( V_52 ) {
F_39 ( V_88 , V_99 ) ;
F_36 ( & V_96 ) ;
return V_52 ;
}
F_40 () ;
return 0 ;
}
int F_41 ( struct V_55 * V_59 )
{
int V_52 ;
F_42 ( L_34 , V_59 -> V_48 ) ;
V_59 -> V_102 = & V_96 ;
V_52 = F_43 ( V_59 ) ;
F_40 () ;
return V_52 ;
}
void F_44 ( struct V_55 * V_59 )
{
F_42 ( L_35 , V_59 -> V_48 ) ;
F_45 ( V_59 ) ;
}
struct V_1 * F_46 ( struct V_14 * type ,
struct V_14 * V_103 ,
struct V_104 * V_7 )
{
struct V_1 * V_105 ;
V_105 = F_47 ( sizeof( struct V_1 ) , V_106 ) ;
if ( ! V_105 ) {
F_10 ( L_36 ) ;
return NULL ;
}
V_105 -> V_7 = V_7 ;
memcpy ( & V_105 -> V_53 , type , sizeof( struct V_14 ) ) ;
memcpy ( & V_105 -> V_54 , V_103 ,
sizeof( struct V_14 ) ) ;
return V_105 ;
}
int F_48 ( struct V_1 * V_105 )
{
int V_52 = 0 ;
static T_3 V_107 = F_49 ( 0 ) ;
F_50 ( & V_105 -> V_2 , L_37 ,
F_51 ( & V_107 ) ) ;
V_105 -> V_2 . V_102 = & V_96 ;
V_105 -> V_2 . V_108 = & V_99 -> V_41 ;
V_105 -> V_2 . V_109 = F_14 ;
V_52 = F_52 ( & V_105 -> V_2 ) ;
if ( V_52 )
F_10 ( L_38 ) ;
else
F_42 ( L_39 ,
F_11 ( & V_105 -> V_2 ) ) ;
return V_52 ;
}
void F_53 ( struct V_1 * V_110 )
{
F_54 ( & V_110 -> V_2 ) ;
F_42 ( L_40 ,
F_11 ( & V_110 -> V_2 ) ) ;
}
static T_4 F_55 ( struct V_111 * V_112 , void * V_88 )
{
if ( V_112 -> type == V_113 ) {
struct V_114 * V_115 ;
V_115 = & V_112 -> V_49 . V_88 ;
* ( ( unsigned int * ) V_88 ) = V_115 -> V_116 [ 0 ] ;
}
return V_117 ;
}
static int F_56 ( struct V_118 * V_2 )
{
T_4 V_119 ;
V_99 = V_2 ;
V_119 =
F_57 ( V_2 -> V_120 , V_121 ,
F_55 , & V_88 ) ;
if ( F_58 ( V_119 ) ) {
F_59 ( & V_122 ) ;
return - V_62 ;
}
F_59 ( & V_122 ) ;
return 0 ;
}
static int T_5 F_60 ( void )
{
int V_52 ;
F_61 ( & V_122 ) ;
V_52 = F_62 ( & V_123 ) ;
if ( V_52 )
return V_52 ;
F_63 ( & V_122 ) ;
if ( V_88 <= 0 ) {
F_64 ( & V_123 ) ;
return - V_62 ;
}
V_52 = F_31 ( V_88 ) ;
if ( V_52 )
F_64 ( & V_123 ) ;
return V_52 ;
}

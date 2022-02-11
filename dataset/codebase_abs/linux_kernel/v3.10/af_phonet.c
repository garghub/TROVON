static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_3 ;
if ( V_2 >= V_4 )
return NULL ;
F_2 () ;
V_3 = F_3 ( V_5 [ V_2 ] ) ;
if ( V_3 && ! F_4 ( V_3 -> V_6 -> V_7 ) )
V_3 = NULL ;
F_5 () ;
return V_3 ;
}
static inline void F_6 ( struct V_1 * V_3 )
{
F_7 ( V_3 -> V_6 -> V_7 ) ;
}
static int F_8 ( struct V_8 * V_8 , struct V_9 * V_10 , int V_2 ,
int V_11 )
{
struct V_10 * V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_15 ;
int V_16 ;
if ( ! F_9 ( V_17 ) )
return - V_18 ;
if ( V_2 == 0 ) {
switch ( V_10 -> type ) {
case V_19 :
V_2 = V_20 ;
break;
case V_21 :
V_2 = V_22 ;
break;
default:
return - V_23 ;
}
}
V_15 = F_1 ( V_2 ) ;
if ( V_15 == NULL &&
F_10 ( L_1 , V_24 , V_2 ) == 0 )
V_15 = F_1 ( V_2 ) ;
if ( V_15 == NULL )
return - V_23 ;
if ( V_10 -> type != V_15 -> V_25 ) {
V_16 = - V_23 ;
goto V_26;
}
V_12 = F_11 ( V_8 , V_24 , V_27 , V_15 -> V_6 ) ;
if ( V_12 == NULL ) {
V_16 = - V_28 ;
goto V_26;
}
F_12 ( V_10 , V_12 ) ;
V_10 -> V_29 = V_30 ;
V_10 -> V_31 = V_15 -> V_31 ;
V_12 -> V_32 = V_12 -> V_33 -> V_34 ;
V_12 -> V_35 = V_2 ;
V_14 = F_13 ( V_12 ) ;
V_14 -> V_36 = 0 ;
V_14 -> V_37 = 0 ;
V_14 -> V_38 = 0 ;
V_12 -> V_33 -> V_39 ( V_12 ) ;
V_16 = 0 ;
V_26:
F_6 ( V_15 ) ;
return V_16 ;
}
static int F_14 ( struct V_40 * V_41 , struct V_42 * V_43 ,
unsigned short type , const void * V_44 ,
const void * V_45 , unsigned int V_46 )
{
T_1 * V_47 = F_15 ( V_41 , 1 ) ;
if ( type != V_48 )
return - 1 ;
if ( ! V_45 )
V_45 = V_43 -> V_49 ;
* V_47 = * ( const T_1 * ) V_45 ;
return 1 ;
}
static int F_16 ( const struct V_40 * V_41 , unsigned char * V_50 )
{
const T_1 * V_47 = F_17 ( V_41 ) ;
* V_50 = * V_47 ;
return 1 ;
}
static int F_18 ( struct V_40 * V_41 , struct V_42 * V_43 ,
T_2 V_51 , T_2 V_52 , T_1 V_53 , T_1 V_54 )
{
struct V_55 * V_56 ;
int V_16 ;
if ( V_41 -> V_46 + 2 > 0xffff ||
V_41 -> V_46 + sizeof( struct V_55 ) > V_43 -> V_57 ) {
V_16 = - V_58 ;
goto V_59;
}
if ( F_19 ( V_51 ) == V_60 ) {
V_16 = - V_61 ;
goto V_59;
}
F_20 ( V_41 ) ;
F_21 ( F_22 ( V_41 ) & 1 ) ;
F_15 ( V_41 , sizeof( struct V_55 ) ) ;
F_23 ( V_41 ) ;
V_56 = F_24 ( V_41 ) ;
V_56 -> V_62 = F_25 ( V_51 ) ;
V_56 -> V_63 = F_25 ( V_52 ) ;
V_56 -> V_64 = V_53 ;
V_56 -> V_65 = F_26 ( V_41 -> V_46 + 2 - sizeof( * V_56 ) ) ;
V_56 -> V_66 = F_27 ( V_51 ) ;
V_56 -> V_67 = F_27 ( V_52 ) ;
V_41 -> V_2 = F_28 ( V_48 ) ;
V_41 -> V_68 = 0 ;
V_41 -> V_43 = V_43 ;
if ( V_41 -> V_69 == V_70 ) {
F_29 ( V_41 ) ;
F_30 ( V_41 ) ;
V_16 = ( V_54 ? F_31 ( V_41 ) : F_32 ( V_41 ) ) ? - V_71 : 0 ;
} else {
V_16 = F_33 ( V_41 , V_43 , F_34 ( V_41 -> V_2 ) ,
NULL , NULL , V_41 -> V_46 ) ;
if ( V_16 < 0 ) {
V_16 = - V_72 ;
goto V_59;
}
V_16 = F_35 ( V_41 ) ;
if ( F_36 ( V_16 > 0 ) )
V_16 = F_37 ( V_16 ) ;
}
return V_16 ;
V_59:
F_38 ( V_41 ) ;
return V_16 ;
}
static int F_39 ( const void * V_73 , int V_46 , struct V_42 * V_43 ,
T_2 V_51 , T_2 V_52 , T_1 V_53 )
{
struct V_40 * V_41 = F_40 ( V_74 + V_46 , V_75 ) ;
if ( V_41 == NULL )
return - V_28 ;
if ( F_41 ( F_42 ( V_43 ) , F_19 ( V_51 ) ) == 0 )
V_41 -> V_69 = V_70 ;
F_43 ( V_41 , V_74 ) ;
F_44 ( V_41 , V_46 ) ;
F_45 ( V_41 , V_73 , V_46 ) ;
return F_18 ( V_41 , V_43 , V_51 , V_52 , V_53 , 1 ) ;
}
int F_46 ( struct V_10 * V_12 , struct V_40 * V_41 ,
const struct V_76 * V_77 )
{
struct V_8 * V_8 = F_47 ( V_12 ) ;
struct V_42 * V_43 ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
int V_16 ;
T_2 V_52 , V_51 ;
T_1 V_44 , V_45 , V_53 ;
V_52 = V_14 -> V_36 ;
if ( V_77 != NULL ) {
V_51 = F_48 ( V_77 ) ;
V_53 = F_49 ( V_77 ) ;
} else {
V_51 = V_14 -> V_37 ;
V_53 = V_14 -> V_38 ;
}
V_44 = F_19 ( V_51 ) ;
V_16 = - V_72 ;
if ( V_12 -> V_78 )
V_43 = F_50 ( V_8 , V_12 -> V_78 ) ;
else if ( F_41 ( V_8 , V_44 ) == 0 ) {
V_43 = F_51 ( V_8 ) ;
V_41 -> V_69 = V_70 ;
} else if ( V_51 == 0 ) {
struct V_10 * V_12 = F_52 ( V_8 , V_53 ) ;
if ( V_12 ) {
F_53 ( V_12 ) ;
V_43 = F_51 ( V_8 ) ;
V_41 -> V_69 = V_70 ;
} else
V_43 = F_54 ( V_8 , V_44 ) ;
} else
V_43 = F_54 ( V_8 , V_44 ) ;
if ( ! V_43 || ! ( V_43 -> V_79 & V_80 ) )
goto V_59;
V_45 = F_55 ( V_43 , V_44 ) ;
if ( V_45 == V_81 )
goto V_59;
if ( ! F_19 ( V_52 ) )
V_52 = F_56 ( V_45 , F_27 ( V_52 ) ) ;
V_16 = F_18 ( V_41 , V_43 , V_51 , V_52 , V_53 , 0 ) ;
F_57 ( V_43 ) ;
return V_16 ;
V_59:
F_38 ( V_41 ) ;
if ( V_43 )
F_57 ( V_43 ) ;
return V_16 ;
}
static inline int F_58 ( struct V_40 * V_41 )
{
const struct V_55 * V_56 ;
const struct V_82 * V_83 ;
T_1 V_84 ;
if ( ! F_59 ( V_41 , 3 ) )
return 0 ;
V_56 = F_24 ( V_41 ) ;
if ( V_56 -> V_64 == V_85 && ! F_59 ( V_41 , 5 ) )
return 0 ;
if ( V_56 -> V_64 == V_86 )
return 0 ;
V_56 = F_24 ( V_41 ) ;
V_83 = F_60 ( V_41 ) ;
if ( V_83 -> V_87 != V_88 )
return 1 ;
V_84 = ( V_56 -> V_64 == V_85 )
? V_83 -> V_89 : V_83 -> V_90 ;
if ( V_84 != V_91 &&
V_83 -> V_89 != V_92 )
return 1 ;
return 0 ;
}
static int F_61 ( struct V_40 * V_93 )
{
const struct V_55 * V_94 = F_24 ( V_93 ) ;
const struct V_82 * V_95 = F_60 ( V_93 ) ;
struct V_82 V_96 ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_97 = V_95 -> V_97 ;
V_96 . V_87 = V_88 ;
if ( V_94 -> V_64 == V_85 ) {
V_96 . V_98 = V_95 -> V_98 ;
V_96 . V_89 = V_91 ;
V_96 . V_99 = V_95 -> V_87 ;
V_96 . V_100 = 0 ;
} else {
V_96 . V_90 = V_91 ;
V_96 . V_101 = V_95 -> V_87 ;
V_96 . V_102 = 0 ;
}
return F_39 ( & V_96 , sizeof( V_96 ) , V_93 -> V_43 ,
F_56 ( V_94 -> V_63 , V_94 -> V_67 ) ,
F_56 ( V_94 -> V_62 , V_94 -> V_66 ) ,
V_94 -> V_64 ) ;
}
static int F_62 ( struct V_40 * V_93 )
{
struct V_55 * V_94 = F_24 ( V_93 ) ;
static const T_1 V_73 [ 4 ] = {
0x00 , 0x10 ,
0x00 , 0x00
} ;
return F_39 ( V_73 , sizeof( V_73 ) , V_93 -> V_43 ,
F_56 ( V_94 -> V_63 , 0x00 ) ,
F_56 ( V_94 -> V_62 , V_94 -> V_66 ) ,
V_86 ) ;
}
static int F_63 ( struct V_40 * V_41 , struct V_42 * V_43 ,
struct V_103 * V_104 ,
struct V_42 * V_105 )
{
struct V_8 * V_8 = F_42 ( V_43 ) ;
struct V_55 * V_56 ;
struct V_76 V_106 ;
T_2 V_46 ;
if ( ! F_64 ( V_41 , sizeof( struct V_55 ) ) )
goto V_26;
V_56 = F_24 ( V_41 ) ;
V_46 = F_65 ( & V_56 -> V_65 ) ;
if ( V_46 < 2 )
goto V_26;
V_46 -= 2 ;
if ( ( V_46 > V_41 -> V_46 ) || F_66 ( V_41 , V_46 ) )
goto V_26;
F_20 ( V_41 ) ;
F_67 ( V_41 , & V_106 ) ;
if ( F_68 ( & V_106 ) == V_60 ) {
F_69 ( V_8 , V_41 ) ;
goto V_26;
}
if ( F_48 ( & V_106 ) == 0 ) {
struct V_10 * V_12 = F_52 ( V_8 , V_106 . V_107 ) ;
if ( V_12 )
return F_70 ( V_12 , V_41 , 0 ) ;
}
if ( F_41 ( V_8 , F_68 ( & V_106 ) ) == 0 ) {
struct V_10 * V_12 = F_71 ( V_8 , & V_106 ) ;
if ( V_12 )
return F_70 ( V_12 , V_41 , 0 ) ;
if ( F_58 ( V_41 ) ) {
F_61 ( V_41 ) ;
F_62 ( V_41 ) ;
}
} else if ( F_36 ( V_41 -> V_69 == V_70 ) )
goto V_26;
else {
struct V_42 * V_108 ;
V_108 = F_54 ( V_8 , F_68 ( & V_106 ) ) ;
if ( ! V_108 ) {
F_72 ( V_109 L_2 ,
F_68 ( & V_106 ) ) ;
goto V_26;
}
F_73 ( V_41 , sizeof( struct V_55 ) ) ;
V_41 -> V_43 = V_108 ;
if ( V_108 == V_43 ) {
F_72 ( V_110 L_3 ,
F_68 ( & V_106 ) , V_43 -> V_111 ) ;
goto V_108;
}
if ( F_74 ( V_41 , V_108 -> V_112 ) )
goto V_108;
if ( F_33 ( V_41 , V_108 , V_48 , NULL , NULL ,
V_41 -> V_46 ) < 0 )
goto V_108;
F_35 ( V_41 ) ;
F_57 ( V_108 ) ;
return V_113 ;
V_108:
F_57 ( V_108 ) ;
}
V_26:
F_38 ( V_41 ) ;
return V_114 ;
}
int T_3 F_75 ( unsigned int V_2 ,
struct V_1 * V_3 )
{
int V_16 = 0 ;
if ( V_2 >= V_4 )
return - V_115 ;
V_16 = F_76 ( V_3 -> V_6 , 1 ) ;
if ( V_16 )
return V_16 ;
F_77 ( & V_116 ) ;
if ( V_5 [ V_2 ] )
V_16 = - V_117 ;
else
F_78 ( V_5 [ V_2 ] , V_3 ) ;
F_79 ( & V_116 ) ;
return V_16 ;
}
void F_80 ( unsigned int V_2 , struct V_1 * V_3 )
{
F_77 ( & V_116 ) ;
F_81 ( V_5 [ V_2 ] != V_3 ) ;
F_82 ( V_5 [ V_2 ] , NULL ) ;
F_79 ( & V_116 ) ;
F_83 () ;
F_84 ( V_3 -> V_6 ) ;
}
static int T_4 F_85 ( void )
{
int V_16 ;
V_16 = F_86 () ;
if ( V_16 )
return V_16 ;
F_87 () ;
V_16 = F_88 ( & V_118 ) ;
if ( V_16 ) {
F_89 ( V_119
L_4 ) ;
goto V_120;
}
F_90 ( & V_121 ) ;
F_91 () ;
V_16 = F_92 () ;
if ( V_16 )
goto V_16;
return 0 ;
V_16:
F_93 () ;
F_94 ( V_24 ) ;
F_95 ( & V_121 ) ;
V_120:
F_96 () ;
return V_16 ;
}
static void T_5 F_97 ( void )
{
F_98 () ;
F_93 () ;
F_94 ( V_24 ) ;
F_95 ( & V_121 ) ;
F_96 () ;
}

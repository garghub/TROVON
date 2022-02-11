static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
V_5 = ( V_2 -> V_6 + 1 ) % V_7 ;
if ( V_5 != V_2 -> V_8 ) {
V_2 -> V_9 [ V_2 -> V_6 ] = V_4 ;
V_2 -> V_6 = V_5 ;
F_2 ( & V_2 -> V_10 ) ;
} else {
F_3 ( V_2 -> V_11 , L_1 ) ;
F_4 ( V_4 ) ;
}
}
static int F_5 ( struct V_1 * V_2 , T_2 V_12 )
{
unsigned long V_13 ;
struct V_3 * V_4 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_12 ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
return 0 ;
}
static int F_9 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
return F_5 ( V_2 , V_19 ) ;
}
static void F_10 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
V_11 -> V_20 = 0 ;
F_5 ( V_2 , V_21 ) ;
}
static int F_11 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
return F_5 ( V_2 , V_22 ) ;
}
static void F_12 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
F_5 ( V_2 , V_23 ) ;
}
static int F_13 ( struct V_24 * V_25 , unsigned int type ,
unsigned int V_26 , int V_27 )
{
struct V_17 * V_11 = F_14 ( V_25 ) ;
struct V_1 * V_2 = V_11 -> V_18 ;
unsigned long V_13 ;
struct V_3 * V_4 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_28 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_29 ;
V_4 -> V_30 . V_31 . type = type ;
V_4 -> V_30 . V_31 . V_26 = V_26 ;
V_4 -> V_30 . V_31 . V_27 = V_27 ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
return F_16 ( V_11 , V_2 -> V_32 , V_2 -> V_33 ) ;
}
static int F_17 ( struct V_17 * V_11 , unsigned char V_34 ,
T_1 * V_35 , T_3 V_36 , unsigned char V_37 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
T_1 V_38 ;
struct V_3 * V_4 ;
unsigned long V_13 ;
int V_39 ;
T_3 V_40 ( V_41 ) ;
struct V_42 * V_43 ;
if ( ! V_2 -> V_44 )
return - V_45 ;
switch ( V_37 ) {
case V_46 :
V_38 = V_47 ;
break;
case V_48 :
V_38 = V_49 ;
break;
case V_50 :
V_38 = V_51 ;
break;
default:
return - V_52 ;
}
V_39 = F_18 ( & V_2 -> V_53 ) ;
if ( V_39 )
return V_39 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 ) {
V_39 = - V_15 ;
goto V_54;
}
F_7 ( & V_2 -> V_16 , V_13 ) ;
V_4 -> type = V_55 ;
V_4 -> V_30 . V_56 . V_57 = F_19 ( & V_2 -> V_58 ) ;
V_4 -> V_30 . V_56 . V_34 = V_34 ;
V_4 -> V_30 . V_56 . V_37 = V_38 ;
F_20 ( & V_2 -> V_59 , 0 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
V_39 = F_21 ( V_2 -> V_60 ,
F_22 ( & V_2 -> V_59 ) , 5 * V_61 ) ;
F_23 () ;
if ( ! V_39 || ! V_2 -> V_44 ) {
V_39 = - V_45 ;
} else if ( V_39 < 0 ) {
V_39 = - V_62 ;
} else {
F_7 ( & V_2 -> V_16 , V_13 ) ;
V_43 = & V_2 -> V_63 . V_30 . V_64 ;
if ( V_43 -> V_65 ) {
V_39 = - V_45 ;
} else {
V_39 = 0 ;
V_41 = F_24 ( V_36 ,
F_25 ( T_3 , V_43 -> V_66 , V_67 ) ) ;
memcpy ( V_35 , V_43 -> V_68 , V_41 ) ;
}
F_8 ( & V_2 -> V_16 , V_13 ) ;
}
F_20 ( & V_2 -> V_59 , 1 ) ;
V_54:
F_26 ( & V_2 -> V_53 ) ;
return V_39 ? V_39 : V_41 ;
}
static int F_27 ( struct V_17 * V_11 , T_1 * V_35 , T_3 V_36 ,
unsigned char V_38 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
T_1 V_37 ;
unsigned long V_13 ;
struct V_3 * V_4 ;
switch ( V_38 ) {
case V_46 :
V_37 = V_47 ;
break;
case V_48 :
V_37 = V_49 ;
break;
default:
return - V_52 ;
}
if ( V_36 < 1 || V_36 > V_67 )
return - V_52 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_69 ;
V_4 -> V_30 . V_70 . V_66 = V_36 ;
V_4 -> V_30 . V_70 . V_37 = V_37 ;
memcpy ( V_4 -> V_30 . V_70 . V_68 , V_35 , V_36 ) ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
return V_36 ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_17 * V_11 ;
int V_39 ;
if ( V_2 -> V_44 )
return - V_71 ;
V_2 -> V_33 = V_4 -> V_30 . V_72 . V_33 ;
if ( V_2 -> V_33 <= 0 || V_2 -> V_33 > V_73 )
return - V_52 ;
V_2 -> V_32 = F_29 ( V_2 -> V_33 , V_14 ) ;
if ( ! V_2 -> V_32 )
return - V_15 ;
if ( F_30 ( V_2 -> V_32 , V_4 -> V_30 . V_72 . V_32 ,
V_2 -> V_33 ) ) {
V_39 = - V_74 ;
goto V_75;
}
V_11 = F_31 () ;
if ( F_32 ( V_11 ) ) {
V_39 = F_33 ( V_11 ) ;
goto V_75;
}
strncpy ( V_11 -> V_76 , V_4 -> V_30 . V_72 . V_76 , 127 ) ;
V_11 -> V_76 [ 127 ] = 0 ;
strncpy ( V_11 -> V_77 , V_4 -> V_30 . V_72 . V_77 , 63 ) ;
V_11 -> V_77 [ 63 ] = 0 ;
strncpy ( V_11 -> V_78 , V_4 -> V_30 . V_72 . V_78 , 63 ) ;
V_11 -> V_78 [ 63 ] = 0 ;
V_11 -> V_79 = & V_80 ;
V_11 -> V_81 = F_17 ;
V_11 -> V_82 = F_27 ;
V_11 -> V_83 = V_4 -> V_30 . V_72 . V_83 ;
V_11 -> V_84 = V_4 -> V_30 . V_72 . V_84 ;
V_11 -> V_85 = V_4 -> V_30 . V_72 . V_85 ;
V_11 -> V_86 = V_4 -> V_30 . V_72 . V_86 ;
V_11 -> V_87 = V_4 -> V_30 . V_72 . V_87 ;
V_11 -> V_18 = V_2 ;
V_11 -> V_88 . V_89 = V_90 . V_91 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_44 = true ;
V_39 = F_34 ( V_11 ) ;
if ( V_39 ) {
F_35 ( V_11 , L_2 ) ;
goto V_92;
}
return 0 ;
V_92:
F_36 ( V_11 ) ;
V_2 -> V_11 = NULL ;
V_2 -> V_44 = false ;
V_75:
F_4 ( V_2 -> V_32 ) ;
return V_39 ;
}
static int F_37 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_44 )
return - V_52 ;
V_2 -> V_44 = false ;
F_38 () ;
F_20 ( & V_2 -> V_59 , 1 ) ;
F_2 ( & V_2 -> V_60 ) ;
F_36 ( V_2 -> V_11 ) ;
F_4 ( V_2 -> V_32 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_2 -> V_44 )
return - V_52 ;
F_40 ( V_2 -> V_11 , V_50 , V_4 -> V_30 . V_25 . V_68 ,
F_25 ( T_3 , V_4 -> V_30 . V_25 . V_66 , V_67 ) , 0 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_13 ;
if ( ! V_2 -> V_44 )
return - V_52 ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
if ( F_22 ( & V_2 -> V_58 ) != V_4 -> V_30 . V_64 . V_57 )
goto V_54;
if ( F_22 ( & V_2 -> V_59 ) )
goto V_54;
memcpy ( & V_2 -> V_63 , V_4 , sizeof( * V_4 ) ) ;
F_20 ( & V_2 -> V_59 , 1 ) ;
F_2 ( & V_2 -> V_60 ) ;
V_54:
F_8 ( & V_2 -> V_16 , V_13 ) ;
return 0 ;
}
static int F_42 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
F_43 ( & V_2 -> V_95 ) ;
F_43 ( & V_2 -> V_53 ) ;
F_44 ( & V_2 -> V_16 ) ;
F_45 ( & V_2 -> V_10 ) ;
F_45 ( & V_2 -> V_60 ) ;
V_2 -> V_44 = false ;
F_20 ( & V_2 -> V_59 , 1 ) ;
V_94 -> V_96 = V_2 ;
F_46 ( V_93 , V_94 ) ;
return 0 ;
}
static int F_47 ( struct V_93 * V_93 , struct V_94 * V_94 )
{
struct V_1 * V_2 = V_94 -> V_96 ;
unsigned int V_97 ;
F_37 ( V_2 ) ;
for ( V_97 = 0 ; V_97 < V_7 ; ++ V_97 )
F_4 ( V_2 -> V_9 [ V_97 ] ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static T_4 F_48 ( struct V_94 * V_94 , char T_5 * V_98 ,
T_3 V_36 , T_6 * V_99 )
{
struct V_1 * V_2 = V_94 -> V_96 ;
int V_39 ;
unsigned long V_13 ;
T_3 V_41 ;
if ( V_36 < sizeof( T_2 ) )
return - V_52 ;
V_100:
if ( V_94 -> V_101 & V_102 ) {
if ( V_2 -> V_6 == V_2 -> V_8 )
return - V_103 ;
} else {
V_39 = F_49 ( V_2 -> V_10 ,
V_2 -> V_6 != V_2 -> V_8 ) ;
if ( V_39 )
return V_39 ;
}
V_39 = F_18 ( & V_2 -> V_95 ) ;
if ( V_39 )
return V_39 ;
if ( V_2 -> V_6 == V_2 -> V_8 ) {
F_26 ( & V_2 -> V_95 ) ;
goto V_100;
} else {
V_41 = F_24 ( V_36 , sizeof( * * V_2 -> V_9 ) ) ;
if ( F_50 ( V_98 , V_2 -> V_9 [ V_2 -> V_8 ] , V_41 ) ) {
V_39 = - V_74 ;
} else {
F_4 ( V_2 -> V_9 [ V_2 -> V_8 ] ) ;
V_2 -> V_9 [ V_2 -> V_8 ] = NULL ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
V_2 -> V_8 = ( V_2 -> V_8 + 1 ) % V_7 ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
}
}
F_26 ( & V_2 -> V_95 ) ;
return V_39 ? V_39 : V_41 ;
}
static T_4 F_51 ( struct V_94 * V_94 , const char T_5 * V_98 ,
T_3 V_36 , T_6 * V_99 )
{
struct V_1 * V_2 = V_94 -> V_96 ;
int V_39 ;
T_3 V_41 ;
if ( V_36 < sizeof( T_2 ) )
return - V_52 ;
V_39 = F_18 ( & V_2 -> V_95 ) ;
if ( V_39 )
return V_39 ;
memset ( & V_2 -> V_104 , 0 , sizeof( V_2 -> V_104 ) ) ;
V_41 = F_24 ( V_36 , sizeof( V_2 -> V_104 ) ) ;
if ( F_30 ( & V_2 -> V_104 , V_98 , V_41 ) ) {
V_39 = - V_74 ;
goto V_54;
}
switch ( V_2 -> V_104 . type ) {
case V_105 :
V_39 = F_28 ( V_2 , & V_2 -> V_104 ) ;
break;
case V_106 :
V_39 = F_37 ( V_2 ) ;
break;
case V_107 :
V_39 = F_39 ( V_2 , & V_2 -> V_104 ) ;
break;
case V_108 :
V_39 = F_41 ( V_2 , & V_2 -> V_104 ) ;
break;
default:
V_39 = - V_109 ;
}
V_54:
F_26 ( & V_2 -> V_95 ) ;
return V_39 ? V_39 : V_36 ;
}
static unsigned int F_52 ( struct V_94 * V_94 , T_7 * V_110 )
{
struct V_1 * V_2 = V_94 -> V_96 ;
F_53 ( V_94 , & V_2 -> V_10 , V_110 ) ;
if ( V_2 -> V_6 != V_2 -> V_8 )
return V_111 | V_112 ;
return 0 ;
}
static int T_8 F_54 ( void )
{
return F_55 ( & V_90 ) ;
}
static void T_9 F_56 ( void )
{
F_57 ( & V_90 ) ;
}

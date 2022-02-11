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
static int F_13 ( struct V_17 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
return F_14 ( V_11 , V_2 -> V_24 , V_2 -> V_25 ) ;
}
static int F_15 ( struct V_17 * V_11 , unsigned char V_26 ,
T_1 * V_27 , T_3 V_28 , unsigned char V_29 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
T_1 V_30 ;
struct V_3 * V_4 ;
unsigned long V_13 ;
int V_31 ;
T_3 V_32 ( V_33 ) ;
struct V_34 * V_35 ;
if ( ! V_2 -> V_36 )
return - V_37 ;
switch ( V_29 ) {
case V_38 :
V_30 = V_39 ;
break;
case V_40 :
V_30 = V_41 ;
break;
case V_42 :
V_30 = V_43 ;
break;
default:
return - V_44 ;
}
V_31 = F_16 ( & V_2 -> V_45 ) ;
if ( V_31 )
return V_31 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 ) {
V_31 = - V_15 ;
goto V_46;
}
F_7 ( & V_2 -> V_16 , V_13 ) ;
V_4 -> type = V_47 ;
V_4 -> V_48 . V_49 . V_50 = F_17 ( & V_2 -> V_51 ) ;
V_4 -> V_48 . V_49 . V_26 = V_26 ;
V_4 -> V_48 . V_49 . V_29 = V_30 ;
F_18 ( & V_2 -> V_52 , 0 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
V_31 = F_19 ( V_2 -> V_53 ,
F_20 ( & V_2 -> V_52 ) , 5 * V_54 ) ;
F_21 () ;
if ( ! V_31 || ! V_2 -> V_36 ) {
V_31 = - V_37 ;
} else if ( V_31 < 0 ) {
V_31 = - V_55 ;
} else {
F_7 ( & V_2 -> V_16 , V_13 ) ;
V_35 = & V_2 -> V_56 . V_48 . V_57 ;
if ( V_35 -> V_58 ) {
V_31 = - V_37 ;
} else {
V_31 = 0 ;
V_33 = F_22 ( V_28 ,
F_23 ( T_3 , V_35 -> V_59 , V_60 ) ) ;
memcpy ( V_27 , V_35 -> V_61 , V_33 ) ;
}
F_8 ( & V_2 -> V_16 , V_13 ) ;
}
F_18 ( & V_2 -> V_52 , 1 ) ;
V_46:
F_24 ( & V_2 -> V_45 ) ;
return V_31 ? V_31 : V_33 ;
}
static int F_25 ( struct V_17 * V_11 , T_1 * V_27 , T_3 V_28 ,
unsigned char V_30 )
{
struct V_1 * V_2 = V_11 -> V_18 ;
T_1 V_29 ;
unsigned long V_13 ;
struct V_3 * V_4 ;
switch ( V_30 ) {
case V_38 :
V_29 = V_39 ;
break;
case V_40 :
V_29 = V_41 ;
break;
default:
return - V_44 ;
}
if ( V_28 < 1 || V_28 > V_60 )
return - V_44 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return - V_15 ;
V_4 -> type = V_62 ;
V_4 -> V_48 . V_63 . V_59 = V_28 ;
V_4 -> V_48 . V_63 . V_29 = V_29 ;
memcpy ( V_4 -> V_48 . V_63 . V_61 , V_27 , V_28 ) ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
F_1 ( V_2 , V_4 ) ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
return V_28 ;
}
static int F_26 ( struct V_17 * V_11 , T_1 * V_27 ,
T_3 V_28 )
{
return F_25 ( V_11 , V_27 , V_28 , V_40 ) ;
}
static int F_27 ( struct V_17 * V_11 , unsigned char V_64 ,
T_1 * V_27 , T_3 V_33 , unsigned char V_29 ,
int V_65 )
{
switch ( V_65 ) {
case V_66 :
return F_15 ( V_11 , V_64 , V_27 , V_33 , V_29 ) ;
case V_67 :
return - V_68 ;
default:
return - V_37 ;
}
}
static int F_28 ( const char T_4 * V_69 , T_3 V_33 ,
struct V_3 * V_12 )
{
if ( F_29 () ) {
T_5 type ;
if ( F_30 ( type , V_69 ) )
return - V_70 ;
if ( type == V_71 ) {
struct V_72 * V_73 ;
V_73 = F_6 ( sizeof( * V_73 ) , V_14 ) ;
if ( ! V_73 )
return - V_15 ;
V_69 += sizeof( type ) ;
V_33 -= sizeof( type ) ;
if ( F_31 ( V_73 , V_69 ,
F_22 ( V_33 , sizeof( * V_73 ) ) ) ) {
F_4 ( V_73 ) ;
return - V_70 ;
}
V_12 -> type = type ;
memcpy ( V_12 -> V_48 . V_74 . V_75 , V_73 -> V_75 ,
sizeof( V_73 -> V_75 ) ) ;
memcpy ( V_12 -> V_48 . V_74 . V_76 , V_73 -> V_76 ,
sizeof( V_73 -> V_76 ) ) ;
memcpy ( V_12 -> V_48 . V_74 . V_77 , V_73 -> V_77 ,
sizeof( V_73 -> V_77 ) ) ;
V_12 -> V_48 . V_74 . V_24 = F_32 ( V_73 -> V_24 ) ;
V_12 -> V_48 . V_74 . V_25 = V_73 -> V_25 ;
V_12 -> V_48 . V_74 . V_78 = V_73 -> V_78 ;
V_12 -> V_48 . V_74 . V_79 = V_73 -> V_79 ;
V_12 -> V_48 . V_74 . V_80 = V_73 -> V_80 ;
V_12 -> V_48 . V_74 . V_81 = V_73 -> V_81 ;
V_12 -> V_48 . V_74 . V_82 = V_73 -> V_82 ;
F_4 ( V_73 ) ;
return 0 ;
}
}
if ( F_31 ( V_12 , V_69 , F_22 ( V_33 , sizeof( * V_12 ) ) ) )
return - V_70 ;
return 0 ;
}
static int F_28 ( const char T_4 * V_69 , T_3 V_33 ,
struct V_3 * V_12 )
{
if ( F_31 ( V_12 , V_69 , F_22 ( V_33 , sizeof( * V_12 ) ) ) )
return - V_70 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_17 * V_11 ;
int V_31 ;
if ( V_2 -> V_36 )
return - V_83 ;
V_2 -> V_25 = V_4 -> V_48 . V_74 . V_25 ;
if ( V_2 -> V_25 <= 0 || V_2 -> V_25 > V_84 )
return - V_44 ;
V_2 -> V_24 = F_34 ( V_2 -> V_25 , V_14 ) ;
if ( ! V_2 -> V_24 )
return - V_15 ;
if ( F_31 ( V_2 -> V_24 , V_4 -> V_48 . V_74 . V_24 ,
V_2 -> V_25 ) ) {
V_31 = - V_70 ;
goto V_85;
}
V_11 = F_35 () ;
if ( F_36 ( V_11 ) ) {
V_31 = F_37 ( V_11 ) ;
goto V_85;
}
strncpy ( V_11 -> V_75 , V_4 -> V_48 . V_74 . V_75 , 127 ) ;
V_11 -> V_75 [ 127 ] = 0 ;
strncpy ( V_11 -> V_76 , V_4 -> V_48 . V_74 . V_76 , 63 ) ;
V_11 -> V_76 [ 63 ] = 0 ;
strncpy ( V_11 -> V_77 , V_4 -> V_48 . V_74 . V_77 , 63 ) ;
V_11 -> V_77 [ 63 ] = 0 ;
V_11 -> V_86 = & V_87 ;
V_11 -> V_78 = V_4 -> V_48 . V_74 . V_78 ;
V_11 -> V_79 = V_4 -> V_48 . V_74 . V_79 ;
V_11 -> V_80 = V_4 -> V_48 . V_74 . V_80 ;
V_11 -> V_81 = V_4 -> V_48 . V_74 . V_81 ;
V_11 -> V_82 = V_4 -> V_48 . V_74 . V_82 ;
V_11 -> V_18 = V_2 ;
V_11 -> V_88 . V_89 = V_90 . V_91 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_36 = true ;
V_31 = F_38 ( V_11 ) ;
if ( V_31 ) {
F_39 ( V_11 , L_2 ) ;
goto V_92;
}
return 0 ;
V_92:
F_40 ( V_11 ) ;
V_2 -> V_11 = NULL ;
V_2 -> V_36 = false ;
V_85:
F_4 ( V_2 -> V_24 ) ;
return V_31 ;
}
static int F_41 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_17 * V_11 ;
int V_31 ;
if ( V_2 -> V_36 )
return - V_83 ;
V_2 -> V_25 = V_4 -> V_48 . V_93 . V_25 ;
if ( V_2 -> V_25 <= 0 || V_2 -> V_25 > V_84 )
return - V_44 ;
V_2 -> V_24 = F_34 ( V_2 -> V_25 , V_14 ) ;
if ( ! V_2 -> V_24 )
return - V_15 ;
memcpy ( V_2 -> V_24 , V_4 -> V_48 . V_93 . V_24 , V_2 -> V_25 ) ;
V_11 = F_35 () ;
if ( F_36 ( V_11 ) ) {
V_31 = F_37 ( V_11 ) ;
goto V_85;
}
strncpy ( V_11 -> V_75 , V_4 -> V_48 . V_93 . V_75 , 127 ) ;
V_11 -> V_75 [ 127 ] = 0 ;
strncpy ( V_11 -> V_76 , V_4 -> V_48 . V_93 . V_76 , 63 ) ;
V_11 -> V_76 [ 63 ] = 0 ;
strncpy ( V_11 -> V_77 , V_4 -> V_48 . V_93 . V_77 , 63 ) ;
V_11 -> V_77 [ 63 ] = 0 ;
V_11 -> V_86 = & V_87 ;
V_11 -> V_78 = V_4 -> V_48 . V_93 . V_78 ;
V_11 -> V_79 = V_4 -> V_48 . V_93 . V_79 ;
V_11 -> V_80 = V_4 -> V_48 . V_93 . V_80 ;
V_11 -> V_81 = V_4 -> V_48 . V_93 . V_81 ;
V_11 -> V_82 = V_4 -> V_48 . V_93 . V_82 ;
V_11 -> V_18 = V_2 ;
V_11 -> V_88 . V_89 = V_90 . V_91 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_36 = true ;
V_31 = F_38 ( V_11 ) ;
if ( V_31 ) {
F_39 ( V_11 , L_2 ) ;
goto V_92;
}
return 0 ;
V_92:
F_40 ( V_11 ) ;
V_2 -> V_11 = NULL ;
V_2 -> V_36 = false ;
V_85:
F_4 ( V_2 -> V_24 ) ;
return V_31 ;
}
static int F_42 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return - V_44 ;
V_2 -> V_36 = false ;
F_43 () ;
F_18 ( & V_2 -> V_52 , 1 ) ;
F_2 ( & V_2 -> V_53 ) ;
F_40 ( V_2 -> V_11 ) ;
F_4 ( V_2 -> V_24 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_2 -> V_36 )
return - V_44 ;
F_45 ( V_2 -> V_11 , V_42 , V_4 -> V_48 . V_94 . V_61 ,
F_23 ( T_3 , V_4 -> V_48 . V_94 . V_59 , V_60 ) , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_2 -> V_36 )
return - V_44 ;
F_45 ( V_2 -> V_11 , V_42 , V_4 -> V_48 . V_95 . V_61 ,
F_23 ( T_3 , V_4 -> V_48 . V_95 . V_59 , V_60 ) , 0 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_13 ;
if ( ! V_2 -> V_36 )
return - V_44 ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
if ( F_20 ( & V_2 -> V_51 ) != V_4 -> V_48 . V_57 . V_50 )
goto V_46;
if ( F_20 ( & V_2 -> V_52 ) )
goto V_46;
memcpy ( & V_2 -> V_56 , V_4 , sizeof( * V_4 ) ) ;
F_18 ( & V_2 -> V_52 , 1 ) ;
F_2 ( & V_2 -> V_53 ) ;
V_46:
F_8 ( & V_2 -> V_16 , V_13 ) ;
return 0 ;
}
static int F_48 ( struct V_96 * V_96 , struct V_97 * V_97 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
F_49 ( & V_2 -> V_98 ) ;
F_49 ( & V_2 -> V_45 ) ;
F_50 ( & V_2 -> V_16 ) ;
F_51 ( & V_2 -> V_10 ) ;
F_51 ( & V_2 -> V_53 ) ;
V_2 -> V_36 = false ;
F_18 ( & V_2 -> V_52 , 1 ) ;
V_97 -> V_99 = V_2 ;
F_52 ( V_96 , V_97 ) ;
return 0 ;
}
static int F_53 ( struct V_96 * V_96 , struct V_97 * V_97 )
{
struct V_1 * V_2 = V_97 -> V_99 ;
unsigned int V_100 ;
F_42 ( V_2 ) ;
for ( V_100 = 0 ; V_100 < V_7 ; ++ V_100 )
F_4 ( V_2 -> V_9 [ V_100 ] ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static T_6 F_54 ( struct V_97 * V_97 , char T_4 * V_69 ,
T_3 V_28 , T_7 * V_101 )
{
struct V_1 * V_2 = V_97 -> V_99 ;
int V_31 ;
unsigned long V_13 ;
T_3 V_33 ;
if ( V_28 < sizeof( T_2 ) )
return - V_44 ;
V_102:
if ( V_97 -> V_103 & V_104 ) {
if ( V_2 -> V_6 == V_2 -> V_8 )
return - V_105 ;
} else {
V_31 = F_55 ( V_2 -> V_10 ,
V_2 -> V_6 != V_2 -> V_8 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_16 ( & V_2 -> V_98 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_6 == V_2 -> V_8 ) {
F_24 ( & V_2 -> V_98 ) ;
goto V_102;
} else {
V_33 = F_22 ( V_28 , sizeof( * * V_2 -> V_9 ) ) ;
if ( F_56 ( V_69 , V_2 -> V_9 [ V_2 -> V_8 ] , V_33 ) ) {
V_31 = - V_70 ;
} else {
F_4 ( V_2 -> V_9 [ V_2 -> V_8 ] ) ;
V_2 -> V_9 [ V_2 -> V_8 ] = NULL ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
V_2 -> V_8 = ( V_2 -> V_8 + 1 ) % V_7 ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
}
}
F_24 ( & V_2 -> V_98 ) ;
return V_31 ? V_31 : V_33 ;
}
static T_6 F_57 ( struct V_97 * V_97 , const char T_4 * V_69 ,
T_3 V_28 , T_7 * V_101 )
{
struct V_1 * V_2 = V_97 -> V_99 ;
int V_31 ;
T_3 V_33 ;
if ( V_28 < sizeof( T_2 ) )
return - V_44 ;
V_31 = F_16 ( & V_2 -> V_98 ) ;
if ( V_31 )
return V_31 ;
memset ( & V_2 -> V_106 , 0 , sizeof( V_2 -> V_106 ) ) ;
V_33 = F_22 ( V_28 , sizeof( V_2 -> V_106 ) ) ;
V_31 = F_28 ( V_69 , V_33 , & V_2 -> V_106 ) ;
if ( V_31 )
goto V_46;
switch ( V_2 -> V_106 . type ) {
case V_71 :
V_31 = F_33 ( V_2 , & V_2 -> V_106 ) ;
break;
case V_107 :
V_31 = F_41 ( V_2 , & V_2 -> V_106 ) ;
break;
case V_108 :
V_31 = F_42 ( V_2 ) ;
break;
case V_109 :
V_31 = F_44 ( V_2 , & V_2 -> V_106 ) ;
break;
case V_110 :
V_31 = F_46 ( V_2 , & V_2 -> V_106 ) ;
break;
case V_111 :
V_31 = F_47 ( V_2 , & V_2 -> V_106 ) ;
break;
default:
V_31 = - V_112 ;
}
V_46:
F_24 ( & V_2 -> V_98 ) ;
return V_31 ? V_31 : V_28 ;
}
static unsigned int F_58 ( struct V_97 * V_97 , T_8 * V_113 )
{
struct V_1 * V_2 = V_97 -> V_99 ;
F_59 ( V_97 , & V_2 -> V_10 , V_113 ) ;
if ( V_2 -> V_6 != V_2 -> V_8 )
return V_114 | V_115 ;
return 0 ;
}
static int T_9 F_60 ( void )
{
return F_61 ( & V_90 ) ;
}
static void T_10 F_62 ( void )
{
F_63 ( & V_90 ) ;
}

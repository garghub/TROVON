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
static int F_26 ( const char T_4 * V_64 , T_3 V_33 ,
struct V_3 * V_12 )
{
if ( F_27 () ) {
T_5 type ;
if ( F_28 ( type , V_64 ) )
return - V_65 ;
if ( type == V_66 ) {
struct V_67 * V_68 ;
V_68 = F_6 ( sizeof( * V_68 ) , V_14 ) ;
if ( ! V_68 )
return - V_15 ;
V_64 += sizeof( type ) ;
V_33 -= sizeof( type ) ;
if ( F_29 ( V_68 , V_64 ,
F_22 ( V_33 , sizeof( * V_68 ) ) ) ) {
F_4 ( V_68 ) ;
return - V_65 ;
}
V_12 -> type = type ;
memcpy ( V_12 -> V_48 . V_69 . V_70 , V_68 -> V_70 ,
sizeof( V_68 -> V_70 ) ) ;
memcpy ( V_12 -> V_48 . V_69 . V_71 , V_68 -> V_71 ,
sizeof( V_68 -> V_71 ) ) ;
memcpy ( V_12 -> V_48 . V_69 . V_72 , V_68 -> V_72 ,
sizeof( V_68 -> V_72 ) ) ;
V_12 -> V_48 . V_69 . V_24 = F_30 ( V_68 -> V_24 ) ;
V_12 -> V_48 . V_69 . V_25 = V_68 -> V_25 ;
V_12 -> V_48 . V_69 . V_73 = V_68 -> V_73 ;
V_12 -> V_48 . V_69 . V_74 = V_68 -> V_74 ;
V_12 -> V_48 . V_69 . V_75 = V_68 -> V_75 ;
V_12 -> V_48 . V_69 . V_76 = V_68 -> V_76 ;
V_12 -> V_48 . V_69 . V_77 = V_68 -> V_77 ;
F_4 ( V_68 ) ;
return 0 ;
}
}
if ( F_29 ( V_12 , V_64 , F_22 ( V_33 , sizeof( * V_12 ) ) ) )
return - V_65 ;
return 0 ;
}
static int F_26 ( const char T_4 * V_64 , T_3 V_33 ,
struct V_3 * V_12 )
{
if ( F_29 ( V_12 , V_64 , F_22 ( V_33 , sizeof( * V_12 ) ) ) )
return - V_65 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_17 * V_11 ;
int V_31 ;
if ( V_2 -> V_36 )
return - V_78 ;
V_2 -> V_25 = V_4 -> V_48 . V_69 . V_25 ;
if ( V_2 -> V_25 <= 0 || V_2 -> V_25 > V_79 )
return - V_44 ;
V_2 -> V_24 = F_32 ( V_2 -> V_25 , V_14 ) ;
if ( ! V_2 -> V_24 )
return - V_15 ;
if ( F_29 ( V_2 -> V_24 , V_4 -> V_48 . V_69 . V_24 ,
V_2 -> V_25 ) ) {
V_31 = - V_65 ;
goto V_80;
}
V_11 = F_33 () ;
if ( F_34 ( V_11 ) ) {
V_31 = F_35 ( V_11 ) ;
goto V_80;
}
strncpy ( V_11 -> V_70 , V_4 -> V_48 . V_69 . V_70 , 127 ) ;
V_11 -> V_70 [ 127 ] = 0 ;
strncpy ( V_11 -> V_71 , V_4 -> V_48 . V_69 . V_71 , 63 ) ;
V_11 -> V_71 [ 63 ] = 0 ;
strncpy ( V_11 -> V_72 , V_4 -> V_48 . V_69 . V_72 , 63 ) ;
V_11 -> V_72 [ 63 ] = 0 ;
V_11 -> V_81 = & V_82 ;
V_11 -> V_83 = F_15 ;
V_11 -> V_84 = F_25 ;
V_11 -> V_73 = V_4 -> V_48 . V_69 . V_73 ;
V_11 -> V_74 = V_4 -> V_48 . V_69 . V_74 ;
V_11 -> V_75 = V_4 -> V_48 . V_69 . V_75 ;
V_11 -> V_76 = V_4 -> V_48 . V_69 . V_76 ;
V_11 -> V_77 = V_4 -> V_48 . V_69 . V_77 ;
V_11 -> V_18 = V_2 ;
V_11 -> V_85 . V_86 = V_87 . V_88 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_36 = true ;
V_31 = F_36 ( V_11 ) ;
if ( V_31 ) {
F_37 ( V_11 , L_2 ) ;
goto V_89;
}
return 0 ;
V_89:
F_38 ( V_11 ) ;
V_2 -> V_11 = NULL ;
V_2 -> V_36 = false ;
V_80:
F_4 ( V_2 -> V_24 ) ;
return V_31 ;
}
static int F_39 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_36 )
return - V_44 ;
V_2 -> V_36 = false ;
F_40 () ;
F_18 ( & V_2 -> V_52 , 1 ) ;
F_2 ( & V_2 -> V_53 ) ;
F_38 ( V_2 -> V_11 ) ;
F_4 ( V_2 -> V_24 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ! V_2 -> V_36 )
return - V_44 ;
F_42 ( V_2 -> V_11 , V_42 , V_4 -> V_48 . V_90 . V_61 ,
F_23 ( T_3 , V_4 -> V_48 . V_90 . V_59 , V_60 ) , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
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
static int F_44 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
struct V_1 * V_2 ;
V_2 = F_6 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 )
return - V_15 ;
F_45 ( & V_2 -> V_93 ) ;
F_45 ( & V_2 -> V_45 ) ;
F_46 ( & V_2 -> V_16 ) ;
F_47 ( & V_2 -> V_10 ) ;
F_47 ( & V_2 -> V_53 ) ;
V_2 -> V_36 = false ;
F_18 ( & V_2 -> V_52 , 1 ) ;
V_92 -> V_94 = V_2 ;
F_48 ( V_91 , V_92 ) ;
return 0 ;
}
static int F_49 ( struct V_91 * V_91 , struct V_92 * V_92 )
{
struct V_1 * V_2 = V_92 -> V_94 ;
unsigned int V_95 ;
F_39 ( V_2 ) ;
for ( V_95 = 0 ; V_95 < V_7 ; ++ V_95 )
F_4 ( V_2 -> V_9 [ V_95 ] ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static T_6 F_50 ( struct V_92 * V_92 , char T_4 * V_64 ,
T_3 V_28 , T_7 * V_96 )
{
struct V_1 * V_2 = V_92 -> V_94 ;
int V_31 ;
unsigned long V_13 ;
T_3 V_33 ;
if ( V_28 < sizeof( T_2 ) )
return - V_44 ;
V_97:
if ( V_92 -> V_98 & V_99 ) {
if ( V_2 -> V_6 == V_2 -> V_8 )
return - V_100 ;
} else {
V_31 = F_51 ( V_2 -> V_10 ,
V_2 -> V_6 != V_2 -> V_8 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_16 ( & V_2 -> V_93 ) ;
if ( V_31 )
return V_31 ;
if ( V_2 -> V_6 == V_2 -> V_8 ) {
F_24 ( & V_2 -> V_93 ) ;
goto V_97;
} else {
V_33 = F_22 ( V_28 , sizeof( * * V_2 -> V_9 ) ) ;
if ( F_52 ( V_64 , V_2 -> V_9 [ V_2 -> V_8 ] , V_33 ) ) {
V_31 = - V_65 ;
} else {
F_4 ( V_2 -> V_9 [ V_2 -> V_8 ] ) ;
V_2 -> V_9 [ V_2 -> V_8 ] = NULL ;
F_7 ( & V_2 -> V_16 , V_13 ) ;
V_2 -> V_8 = ( V_2 -> V_8 + 1 ) % V_7 ;
F_8 ( & V_2 -> V_16 , V_13 ) ;
}
}
F_24 ( & V_2 -> V_93 ) ;
return V_31 ? V_31 : V_33 ;
}
static T_6 F_53 ( struct V_92 * V_92 , const char T_4 * V_64 ,
T_3 V_28 , T_7 * V_96 )
{
struct V_1 * V_2 = V_92 -> V_94 ;
int V_31 ;
T_3 V_33 ;
if ( V_28 < sizeof( T_2 ) )
return - V_44 ;
V_31 = F_16 ( & V_2 -> V_93 ) ;
if ( V_31 )
return V_31 ;
memset ( & V_2 -> V_101 , 0 , sizeof( V_2 -> V_101 ) ) ;
V_33 = F_22 ( V_28 , sizeof( V_2 -> V_101 ) ) ;
V_31 = F_26 ( V_64 , V_33 , & V_2 -> V_101 ) ;
if ( V_31 )
goto V_46;
switch ( V_2 -> V_101 . type ) {
case V_66 :
V_31 = F_31 ( V_2 , & V_2 -> V_101 ) ;
break;
case V_102 :
V_31 = F_39 ( V_2 ) ;
break;
case V_103 :
V_31 = F_41 ( V_2 , & V_2 -> V_101 ) ;
break;
case V_104 :
V_31 = F_43 ( V_2 , & V_2 -> V_101 ) ;
break;
default:
V_31 = - V_105 ;
}
V_46:
F_24 ( & V_2 -> V_93 ) ;
return V_31 ? V_31 : V_28 ;
}
static unsigned int F_54 ( struct V_92 * V_92 , T_8 * V_106 )
{
struct V_1 * V_2 = V_92 -> V_94 ;
F_55 ( V_92 , & V_2 -> V_10 , V_106 ) ;
if ( V_2 -> V_6 != V_2 -> V_8 )
return V_107 | V_108 ;
return 0 ;
}
static int T_9 F_56 ( void )
{
return F_57 ( & V_87 ) ;
}
static void T_10 F_58 ( void )
{
F_59 ( & V_87 ) ;
}

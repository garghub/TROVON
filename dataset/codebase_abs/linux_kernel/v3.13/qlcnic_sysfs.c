int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return - V_4 ;
}
int F_2 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_6 )
{
return - V_4 ;
}
static T_2 F_3 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned long V_13 ;
int V_14 = - V_15 ;
if ( ! ( V_2 -> V_16 -> V_17 & V_18 ) )
goto V_19;
if ( ! F_5 ( V_20 , & V_2 -> V_5 ) )
goto V_19;
if ( F_6 ( V_11 , 2 , & V_13 ) )
goto V_19;
if ( ! F_7 ( V_2 , ! ! V_13 ) )
V_14 = V_12 ;
V_19:
return V_14 ;
}
static T_2 F_8 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_21 = 0 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
V_21 = ! ! ( V_2 -> V_22 & V_23 ) ;
return sprintf ( V_11 , L_1 , V_21 ) ;
}
static T_2 F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned long V_13 ;
if ( F_6 ( V_11 , 2 , & V_13 ) )
return - V_15 ;
if ( ! ! V_13 != ! ! ( V_2 -> V_22 & V_24 ) )
V_2 -> V_22 ^= V_24 ;
return V_12 ;
}
static T_2 F_10 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
return sprintf ( V_11 , L_1 , ! ! ( V_2 -> V_22 & V_24 ) ) ;
}
static int F_11 ( struct V_1 * V_2 , T_4 V_25 ,
T_5 * V_5 , T_5 * V_6 )
{
* V_6 = F_12 ( V_25 ) ;
* V_5 = F_13 ( V_25 ) ;
F_14 ( V_2 , V_26 , L_2 , * V_6 , * V_5 ) ;
if ( ! * V_5 ) {
* V_6 = V_27 ;
return 0 ;
} else if ( * V_5 > V_28 ) {
return - V_15 ;
}
if ( ( ! * V_6 ) || ( * V_6 > V_27 ) )
return - V_15 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
const char * V_11 , T_3 V_12 )
{
struct V_29 * V_16 = V_2 -> V_16 ;
unsigned long V_30 ;
int V_31 ;
if ( F_5 ( V_32 , & V_2 -> V_5 ) )
return - V_33 ;
if ( F_6 ( V_11 , 2 , & V_30 ) )
return - V_15 ;
if ( V_16 -> V_34 == V_30 )
return V_12 ;
F_16 () ;
if ( ! V_16 -> V_34 ) {
if ( F_17 ( V_35 , & V_2 -> V_5 ) ) {
F_18 () ;
return - V_36 ;
}
}
if ( V_30 )
V_31 = F_19 ( V_2 , 1 , V_30 ) ;
else
V_31 = F_19 ( V_2 , 0 , ! V_30 ) ;
if ( ! V_31 )
V_16 -> V_34 = V_30 ;
if ( ! V_16 -> V_34 )
F_20 ( V_35 , & V_2 -> V_5 ) ;
F_18 () ;
return V_12 ;
}
static int F_21 ( struct V_1 * V_2 ,
const char * V_11 , T_3 V_12 )
{
struct V_29 * V_16 = V_2 -> V_16 ;
int V_31 , V_37 = V_2 -> V_37 ;
T_4 V_25 ;
T_5 V_38 , V_39 , V_40 ;
if ( V_12 != sizeof( T_4 ) )
return V_41 ;
memcpy ( & V_25 , V_11 , sizeof( T_4 ) ) ;
V_31 = F_11 ( V_2 , V_25 , & V_39 , & V_40 ) ;
if ( V_31 )
return V_31 ;
if ( V_16 -> V_42 [ 0 ] & V_43 ) {
V_31 = F_22 ( V_2 , & V_38 ) ;
if ( V_31 ) {
F_23 ( V_2 -> V_44 ,
L_3 ) ;
} else {
if ( V_38 == V_45 )
V_16 -> V_34 = 0 ;
else if ( V_38 == V_46 )
V_16 -> V_34 = 2 ;
}
}
if ( V_16 -> V_34 == V_39 )
return V_12 ;
F_16 () ;
if ( ! V_16 -> V_34 ) {
if ( F_17 ( V_35 , & V_2 -> V_5 ) ) {
F_18 () ;
return - V_36 ;
}
}
if ( F_5 ( V_32 , & V_2 -> V_5 ) ) {
V_31 = - V_33 ;
goto V_47;
}
if ( ! F_5 ( V_20 , & V_2 -> V_5 ) ) {
V_31 = F_24 ( V_2 -> V_44 , V_48 ) ;
if ( V_31 )
goto V_47;
F_25 ( V_49 , & V_2 -> V_5 ) ;
}
V_31 = F_26 ( V_2 , V_39 , V_40 ) ;
if ( ! V_31 ) {
V_31 = V_12 ;
V_16 -> V_34 = V_39 ;
}
if ( F_27 ( V_49 , & V_2 -> V_5 ) )
F_28 ( V_2 -> V_44 , V_37 ) ;
V_47:
if ( ! V_16 -> V_34 )
F_20 ( V_35 , & V_2 -> V_5 ) ;
F_18 () ;
return V_31 ;
}
static T_2 F_29 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_31 = 0 ;
if ( V_2 -> V_16 -> V_50 == V_51 ) {
F_30 ( V_8 ,
L_4 ) ;
return - V_4 ;
}
if ( F_31 ( V_2 ) )
V_31 = F_21 ( V_2 , V_11 , V_12 ) ;
else if ( F_32 ( V_2 ) )
V_31 = F_15 ( V_2 , V_11 , V_12 ) ;
else
return - V_33 ;
return V_31 ;
}
static T_2 F_33 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
return sprintf ( V_11 , L_1 , V_2 -> V_16 -> V_34 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
T_6 V_52 , T_3 V_53 )
{
T_3 V_54 = 4 ;
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_33 ;
if ( V_52 < V_55 ) {
if ( F_35 ( V_52 , V_56 ,
V_57 ) )
V_54 = 8 ;
else
return - V_15 ;
}
if ( ( V_53 != V_54 ) || ( V_52 & ( V_54 - 1 ) ) )
return - V_15 ;
return 0 ;
}
static T_2 F_36 ( struct V_58 * V_59 , struct V_60 * V_61 ,
struct V_62 * V_10 , char * V_11 ,
T_6 V_52 , T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_34 ( V_2 , V_52 , V_53 ) ;
if ( V_14 != 0 )
return V_14 ;
F_38 ( V_2 , V_11 , V_52 , V_53 ) ;
return V_53 ;
}
static T_2 F_39 ( struct V_58 * V_59 , struct V_60 * V_61 ,
struct V_62 * V_10 , char * V_11 ,
T_6 V_52 , T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_34 ( V_2 , V_52 , V_53 ) ;
if ( V_14 != 0 )
return V_14 ;
F_40 ( V_2 , V_11 , V_52 , V_53 ) ;
return V_53 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_6 V_52 , T_3 V_53 )
{
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_33 ;
if ( ( V_53 != 8 ) || ( V_52 & 0x7 ) )
return - V_33 ;
return 0 ;
}
static T_2 F_42 ( struct V_58 * V_59 , struct V_60 * V_61 ,
struct V_62 * V_10 , char * V_11 ,
T_6 V_52 , T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_63 ;
int V_14 ;
V_14 = F_41 ( V_2 , V_52 , V_53 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_43 ( V_2 , V_52 , & V_63 ) )
return - V_33 ;
memcpy ( V_11 , & V_63 , V_53 ) ;
return V_53 ;
}
static T_2 F_44 ( struct V_58 * V_59 , struct V_60 * V_61 ,
struct V_62 * V_10 , char * V_11 ,
T_6 V_52 , T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_63 ;
int V_14 ;
V_14 = F_41 ( V_2 , V_52 , V_53 ) ;
if ( V_14 != 0 )
return V_14 ;
memcpy ( & V_63 , V_11 , V_53 ) ;
if ( F_45 ( V_2 , V_52 , V_63 ) )
return - V_33 ;
return V_53 ;
}
static int F_46 ( struct V_1 * V_2 , T_5 V_64 )
{
int V_65 ;
for ( V_65 = 0 ; V_65 < V_2 -> V_16 -> V_66 ; V_65 ++ ) {
if ( V_2 -> V_67 [ V_65 ] . V_64 == V_64 )
return V_65 ;
}
return - 1 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_68 * V_69 , int V_70 )
{
T_5 V_71 , V_72 , V_73 ;
T_5 V_74 ;
int V_65 , V_75 , V_76 ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_71 = V_69 [ V_65 ] . V_64 ;
V_74 = V_69 [ V_65 ] . V_77 ;
V_75 = F_46 ( V_2 , V_71 ) ;
if ( V_75 < 0 )
return V_41 ;
V_76 = F_46 ( V_2 , V_74 ) ;
if ( V_76 < 0 )
return V_41 ;
V_72 = V_2 -> V_67 [ V_75 ] . V_78 ;
V_73 = V_2 -> V_67 [ V_76 ] . V_78 ;
if ( V_72 != V_73 )
return V_41 ;
}
return 0 ;
}
static T_2 F_48 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_68 * V_69 ;
T_1 V_79 , V_80 , V_64 ;
int V_70 , V_81 , V_65 , V_14 , V_82 ;
V_70 = V_53 / sizeof( struct V_68 ) ;
V_81 = V_53 % sizeof( struct V_68 ) ;
if ( V_81 )
return V_41 ;
V_69 = (struct V_68 * ) V_11 ;
V_14 = F_47 ( V_2 , V_69 , V_70 ) ;
if ( V_14 )
return V_14 ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_69 [ V_65 ] . V_64 ;
V_80 = ! ! V_69 [ V_65 ] . V_80 ;
V_82 = F_46 ( V_2 , V_64 ) ;
if ( V_82 < 0 )
return V_41 ;
V_79 = V_2 -> V_67 [ V_82 ] . V_78 ;
V_14 = F_49 ( V_2 , V_79 ,
V_80 , V_64 ) ;
if ( V_14 )
return V_14 ;
}
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_69 [ V_65 ] . V_64 ;
V_82 = F_46 ( V_2 , V_64 ) ;
V_79 = V_2 -> V_67 [ V_82 ] . V_78 ;
V_2 -> V_67 [ V_82 ] . V_83 = ! ! V_69 [ V_65 ] . V_80 ;
V_2 -> V_67 [ V_82 ] . V_77 = V_79 ;
}
return V_53 ;
}
static T_2 F_50 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_68 V_69 [ V_84 ] ;
int V_65 ;
T_5 V_64 ;
if ( V_53 != sizeof( V_69 ) )
return V_41 ;
memset ( & V_69 , 0 ,
sizeof( struct V_68 ) * V_84 ) ;
for ( V_65 = 0 ; V_65 < V_84 ; V_65 ++ ) {
V_64 = V_2 -> V_67 [ V_65 ] . V_64 ;
if ( ! V_2 -> V_67 [ V_65 ] . V_85 )
continue;
if ( ! V_2 -> V_67 [ V_65 ] . V_86 )
continue;
V_69 [ V_64 ] . V_80 = V_2 -> V_67 [ V_65 ] . V_83 ;
V_69 [ V_64 ] . V_77 = 0 ;
V_69 [ V_64 ] . V_64 = V_65 ;
}
memcpy ( V_11 , & V_69 , V_53 ) ;
return V_53 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_87 * V_88 , int V_70 )
{
T_1 V_50 ;
T_5 V_64 ;
int V_65 , V_14 ;
if ( F_31 ( V_2 ) )
V_50 = F_52 ( V_2 -> V_16 -> V_89 + V_90 ) ;
else
V_50 = F_53 ( V_2 -> V_16 , V_91 ) ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_88 [ V_65 ] . V_64 ;
if ( V_64 >= V_84 )
return V_41 ;
if ( V_2 -> V_16 -> V_50 == V_92 )
if ( F_46 ( V_2 , V_64 ) < 0 )
return V_41 ;
switch ( V_88 [ V_65 ] . V_50 ) {
case V_93 :
if ( F_31 ( V_2 ) ) {
V_14 = F_54 ( V_50 , V_64 ) ;
} else {
V_14 = F_55 ( V_50 ,
V_64 ) ;
V_88 [ V_65 ] . V_94 = 0 ;
}
if ( V_14 != V_51 ) {
if ( V_88 [ V_65 ] . V_95 != 0 )
return V_41 ;
if ( V_88 [ V_65 ] . V_96 != 1 )
return V_41 ;
if ( V_88 [ V_65 ] . V_97 != 1 )
return V_41 ;
}
break;
case V_98 :
if ( ! F_56 ( V_88 [ V_65 ] . V_99 ) )
return V_41 ;
if ( ! V_88 [ V_65 ] . V_100 )
return V_41 ;
break;
case V_101 :
if ( ! V_88 [ V_65 ] . V_100 )
return V_41 ;
break;
default:
return V_41 ;
}
}
return 0 ;
}
static T_2 F_57 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_87 * V_88 ;
struct V_102 * V_103 ;
int V_70 , V_81 , V_65 , V_14 ;
int V_82 ;
T_5 V_50 = 0 , V_64 ;
V_70 = V_53 / sizeof( struct V_87 ) ;
V_81 = V_53 % sizeof( struct V_87 ) ;
if ( V_81 )
return V_41 ;
V_88 = (struct V_87 * ) V_11 ;
V_14 = F_51 ( V_2 , V_88 , V_70 ) ;
if ( V_14 )
return V_14 ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
if ( V_2 -> V_16 -> V_50 == V_92 )
if ( F_58 ( V_2 , & V_88 [ V_65 ] ) )
return V_41 ;
if ( V_2 -> V_16 -> V_64 != V_88 [ V_65 ] . V_64 )
continue;
V_50 = V_88 [ V_65 ] . V_50 ;
F_59 ( V_2 , & V_88 [ V_65 ] ) ;
V_88 [ V_65 ] . V_50 = V_50 ;
V_88 [ V_65 ] . V_64 = V_2 -> V_16 -> V_64 ;
switch ( V_88 [ V_65 ] . V_50 ) {
case V_93 :
F_60 ( V_2 , & V_88 [ V_65 ] ) ;
F_16 () ;
F_61 ( V_2 , & V_88 [ V_65 ] ) ;
F_18 () ;
break;
case V_98 :
F_62 ( V_2 , & V_88 [ V_65 ] ) ;
break;
case V_101 :
V_88 [ V_65 ] . V_99 = 0 ;
F_62 ( V_2 , & V_88 [ V_65 ] ) ;
break;
}
}
if ( V_2 -> V_16 -> V_50 != V_92 )
goto V_47;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_88 [ V_65 ] . V_64 ;
V_82 = F_46 ( V_2 , V_64 ) ;
V_103 = & V_2 -> V_67 [ V_82 ] ;
switch ( V_88 [ V_65 ] . V_50 ) {
case V_93 :
V_103 -> V_97 = V_88 [ V_65 ] . V_97 ;
V_103 -> V_96 = V_88 [ V_65 ] . V_96 ;
V_103 -> V_94 = V_88 [ V_65 ] . V_94 ;
V_103 -> V_95 = V_88 [ V_65 ] . V_95 ;
V_103 -> V_104 = V_88 [ V_65 ] . V_104 ;
break;
case V_98 :
V_103 -> V_105 = V_88 [ V_65 ] . V_99 ;
break;
case V_101 :
V_103 -> V_105 = 0 ;
break;
}
}
V_47:
return V_53 ;
}
static T_2 F_63 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_87 V_88 [ V_84 ] ;
T_5 V_65 , V_64 ;
if ( V_53 != sizeof( V_88 ) )
return V_41 ;
memset ( & V_88 , 0 ,
sizeof( struct V_87 ) * V_84 ) ;
for ( V_65 = 0 ; V_65 < V_84 ; V_65 ++ ) {
V_64 = V_2 -> V_67 [ V_65 ] . V_64 ;
if ( ! V_2 -> V_67 [ V_65 ] . V_85 )
continue;
if ( ! V_2 -> V_67 [ V_65 ] . V_86 )
continue;
V_88 [ V_64 ] . V_64 = V_64 ;
if ( F_59 ( V_2 , & V_88 [ V_64 ] ) )
return V_41 ;
}
memcpy ( V_11 , & V_88 , V_53 ) ;
return V_53 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_106 * V_107 ,
int V_70 )
{
T_5 V_64 , V_65 ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_107 [ V_65 ] . V_64 ;
if ( F_46 ( V_2 , V_64 ) < 0 )
return V_41 ;
if ( ! F_65 ( V_107 [ V_65 ] . V_108 ) ||
! F_65 ( V_107 [ V_65 ] . V_109 ) )
return V_41 ;
}
return 0 ;
}
static T_2 F_66 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_110 V_111 ;
struct V_106 * V_107 ;
int V_65 , V_70 , V_81 , V_14 , V_82 ;
T_5 V_64 ;
V_70 = V_53 / sizeof( struct V_106 ) ;
V_81 = V_53 % sizeof( struct V_106 ) ;
if ( V_81 )
return V_41 ;
V_107 = (struct V_106 * ) V_11 ;
V_14 = F_64 ( V_2 , V_107 , V_70 ) ;
if ( V_14 )
return V_14 ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_107 [ V_65 ] . V_64 ;
memset ( & V_111 , 0 , sizeof( struct V_110 ) ) ;
V_14 = F_67 ( V_2 , & V_111 , V_64 ) ;
if ( V_14 )
return V_14 ;
V_111 . V_64 = V_64 ;
V_111 . V_112 = V_107 [ V_65 ] . V_108 ;
V_111 . V_113 = V_107 [ V_65 ] . V_109 ;
V_14 = F_68 ( V_2 , & V_111 ) ;
if ( V_14 )
return V_14 ;
V_82 = F_46 ( V_2 , V_64 ) ;
V_2 -> V_67 [ V_82 ] . V_108 = V_111 . V_112 ;
V_2 -> V_67 [ V_82 ] . V_109 = V_111 . V_113 ;
}
return V_53 ;
}
static T_2 F_69 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_110 V_111 ;
struct V_106 V_107 [ V_84 ] ;
int V_65 , V_14 ;
if ( V_53 != sizeof( V_107 ) )
return V_41 ;
memset ( & V_111 , 0 , sizeof( struct V_110 ) ) ;
memset ( & V_107 , 0 ,
sizeof( struct V_106 ) * V_84 ) ;
for ( V_65 = 0 ; V_65 < V_84 ; V_65 ++ ) {
if ( F_46 ( V_2 , V_65 ) < 0 )
continue;
V_14 = F_67 ( V_2 , & V_111 , V_65 ) ;
if ( V_14 )
return V_14 ;
if ( ! V_2 -> V_67 [ V_65 ] . V_86 )
continue;
V_107 [ V_65 ] . V_64 = V_65 ;
V_107 [ V_65 ] . V_50 = ( T_5 ) V_111 . V_50 ;
V_107 [ V_65 ] . V_114 = V_111 . V_115 ;
V_107 [ V_65 ] . V_116 = V_111 . V_17 ;
V_107 [ V_65 ] . V_108 = V_111 . V_112 ;
V_107 [ V_65 ] . V_109 = V_111 . V_113 ;
V_107 [ V_65 ] . V_117 = V_111 . V_118 ;
V_107 [ V_65 ] . V_119 = V_111 . V_120 ;
}
memcpy ( V_11 , & V_107 , V_53 ) ;
return V_53 ;
}
static T_2 F_70 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_121 V_122 ;
int V_14 ;
if ( F_32 ( V_2 ) )
return V_123 ;
if ( V_53 != sizeof( struct V_121 ) )
return V_41 ;
if ( V_52 >= V_84 )
return V_41 ;
memset ( & V_122 , 0 , V_53 ) ;
V_14 = F_71 ( V_2 , V_52 , V_124 ,
& V_122 . V_125 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_71 ( V_2 , V_52 , V_126 ,
& V_122 . V_127 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_122 , V_53 ) ;
return V_53 ;
}
static T_2 F_72 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_121 V_128 ;
int V_14 ;
if ( F_32 ( V_2 ) )
return V_123 ;
if ( V_53 != sizeof( struct V_121 ) )
return V_41 ;
if ( V_52 >= V_129 )
return V_41 ;
memset ( & V_128 , 0 , V_53 ) ;
V_14 = F_73 ( V_2 , V_52 , V_124 ,
& V_128 . V_125 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_73 ( V_2 , V_52 , V_126 ,
& V_128 . V_127 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_128 , V_53 ) ;
return V_53 ;
}
static T_2 F_74 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_32 ( V_2 ) )
return V_123 ;
if ( V_52 >= V_129 )
return V_41 ;
V_14 = F_75 ( V_2 , V_130 , V_52 ,
V_124 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_75 ( V_2 , V_130 , V_52 ,
V_126 ) ;
if ( V_14 )
return V_14 ;
return V_53 ;
}
static T_2 F_76 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_32 ( V_2 ) )
return V_123 ;
if ( V_52 >= V_84 )
return V_41 ;
V_14 = F_75 ( V_2 , V_131 , V_52 ,
V_124 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_75 ( V_2 , V_131 , V_52 ,
V_126 ) ;
if ( V_14 )
return V_14 ;
return V_53 ;
}
static T_2 F_77 ( struct V_58 * V_58 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_132 V_133 [ V_84 ] ;
struct V_134 * V_135 ;
int V_65 , V_14 ;
if ( V_53 != sizeof( V_133 ) )
return V_41 ;
V_135 = F_78 ( V_84 , sizeof( * V_135 ) , V_136 ) ;
if ( ! V_135 )
return - V_137 ;
V_14 = F_79 ( V_2 , V_135 ) ;
if ( V_14 ) {
F_80 ( V_135 ) ;
return V_14 ;
}
memset ( & V_133 , 0 ,
sizeof( struct V_132 ) * V_84 ) ;
for ( V_65 = 0 ; V_65 < V_84 ; V_65 ++ ) {
V_133 [ V_65 ] . V_64 = V_135 [ V_65 ] . V_79 ;
V_133 [ V_65 ] . V_138 = V_135 [ V_65 ] . type ;
V_133 [ V_65 ] . V_114 = V_135 [ V_65 ] . V_139 ;
V_133 [ V_65 ] . V_108 = V_135 [ V_65 ] . V_140 ;
V_133 [ V_65 ] . V_109 = V_135 [ V_65 ] . V_141 ;
memcpy ( & V_133 [ V_65 ] . V_142 , & V_135 [ V_65 ] . V_143 , V_144 ) ;
}
memcpy ( V_11 , & V_133 , V_53 ) ;
F_80 ( V_135 ) ;
return V_53 ;
}
static T_2 F_81 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
unsigned char * V_145 ;
int V_14 , V_70 ;
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_53 )
return V_41 ;
if ( ! V_11 )
return V_41 ;
V_70 = V_53 / sizeof( T_1 ) ;
if ( V_53 % sizeof( T_1 ) )
V_70 ++ ;
V_145 = F_78 ( V_53 , sizeof( unsigned char ) , V_136 ) ;
if ( ! V_145 )
return - V_137 ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_145 ) ;
return - V_33 ;
}
V_14 = F_83 ( V_2 , V_52 , V_145 ,
V_70 ) ;
if ( V_14 ) {
F_84 ( V_2 ) ;
F_80 ( V_145 ) ;
return V_14 ;
}
F_84 ( V_2 ) ;
memcpy ( V_11 , V_145 , V_53 ) ;
F_80 ( V_145 ) ;
return V_53 ;
}
static int F_85 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
int V_65 , V_14 , V_70 ;
unsigned char * V_146 , * V_147 ;
V_146 = F_78 ( V_53 , sizeof( unsigned char ) , V_136 ) ;
if ( ! V_146 )
return - V_137 ;
memcpy ( V_146 , V_11 , V_53 ) ;
V_147 = V_146 ;
V_70 = V_53 / sizeof( T_1 ) ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_146 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_148 . V_149 == V_2 -> V_150 ) {
V_14 = F_86 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_65 = 0 ; V_65 < V_70 / V_151 ; V_65 ++ ) {
V_14 = F_87 ( V_2 , V_52 ,
( T_1 * ) V_147 ,
V_151 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_148 . V_149 == V_2 -> V_150 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
V_147 = V_147 + sizeof( T_1 ) * V_151 ;
V_52 = V_52 + sizeof( T_1 ) * V_151 ;
}
if ( V_2 -> V_16 -> V_148 . V_149 == V_2 -> V_150 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_52 , T_3 V_53 )
{
int V_65 , V_14 , V_70 ;
unsigned char * V_146 , * V_147 ;
V_146 = F_78 ( V_53 , sizeof( unsigned char ) , V_136 ) ;
if ( ! V_146 )
return - V_137 ;
memcpy ( V_146 , V_11 , V_53 ) ;
V_147 = V_146 ;
V_70 = V_53 / sizeof( T_1 ) ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_146 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_148 . V_149 == V_2 -> V_150 ) {
V_14 = F_86 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_14 = F_90 ( V_2 , V_52 , ( T_1 * ) V_147 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_148 . V_149 == V_2 -> V_150 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
V_147 = V_147 + sizeof( T_1 ) ;
V_52 = V_52 + sizeof( T_1 ) ;
}
if ( V_2 -> V_16 -> V_148 . V_149 == V_2 -> V_150 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_146 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static T_2 F_91 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
int V_14 ;
static int V_152 ;
unsigned long V_63 ;
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_11 )
return V_41 ;
V_14 = F_6 ( V_11 , 16 , & V_63 ) ;
switch ( V_63 ) {
case V_153 :
V_152 = V_154 ;
V_14 = F_92 ( V_2 , V_52 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_155 -> V_8 ,
L_5 , V_156 , __LINE__ ) ;
return - V_33 ;
}
break;
case V_157 :
V_152 = V_158 ;
break;
case V_159 :
V_152 = V_160 ;
break;
default:
if ( V_152 == V_158 ) {
V_14 = F_85 ( V_2 , V_11 ,
V_52 , V_53 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_155 -> V_8 ,
L_5 ,
V_156 , __LINE__ ) ;
return - V_33 ;
}
}
if ( V_152 == V_160 ) {
V_14 = F_89 ( V_2 , V_11 ,
V_52 , V_53 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_155 -> V_8 ,
L_5 , V_156 ,
__LINE__ ) ;
return - V_33 ;
}
}
}
return V_53 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_155 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
if ( F_95 ( V_8 , & V_161 ) )
F_30 ( V_8 ,
L_6 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_155 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
F_97 ( V_8 , & V_161 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_155 -> V_8 ;
if ( F_99 ( V_8 , & V_162 ) )
F_100 ( V_8 , L_7 ) ;
if ( V_2 -> V_16 -> V_50 == V_51 )
return;
if ( F_95 ( V_8 , & V_163 ) )
F_100 ( V_8 , L_8 ) ;
if ( F_99 ( V_8 , & V_164 ) )
F_100 ( V_8 , L_9 ) ;
if ( F_99 ( V_8 , & V_165 ) )
F_100 ( V_8 , L_10 ) ;
if ( F_5 ( V_166 , & V_2 -> V_5 ) )
return;
if ( F_99 ( V_8 , & V_167 ) )
F_100 ( V_8 , L_11 ) ;
if ( F_95 ( V_8 , & V_168 ) )
F_100 ( V_8 , L_12 ) ;
if ( ! ( V_2 -> V_22 & V_169 ) )
return;
if ( F_99 ( V_8 , & V_170 ) )
F_100 ( V_8 , L_13 ) ;
if ( V_2 -> V_16 -> V_50 != V_92 )
return;
if ( F_99 ( V_8 , & V_171 ) )
F_100 ( V_8 , L_14 ) ;
if ( F_99 ( V_8 , & V_172 ) )
F_100 ( V_8 , L_15 ) ;
if ( F_99 ( V_8 , & V_173 ) )
F_100 ( V_8 , L_16 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_155 -> V_8 ;
F_102 ( V_8 , & V_162 ) ;
if ( V_2 -> V_16 -> V_50 == V_51 )
return;
F_97 ( V_8 , & V_163 ) ;
F_102 ( V_8 , & V_164 ) ;
F_102 ( V_8 , & V_165 ) ;
if ( F_5 ( V_166 , & V_2 -> V_5 ) )
return;
F_102 ( V_8 , & V_167 ) ;
F_97 ( V_8 , & V_168 ) ;
if ( ! ( V_2 -> V_22 & V_169 ) )
return;
F_102 ( V_8 , & V_170 ) ;
if ( V_2 -> V_16 -> V_50 != V_92 )
return;
F_102 ( V_8 , & V_171 ) ;
F_102 ( V_8 , & V_172 ) ;
F_102 ( V_8 , & V_173 ) ;
}
void F_103 ( struct V_1 * V_2 )
{
F_98 ( V_2 ) ;
}
void F_104 ( struct V_1 * V_2 )
{
F_101 ( V_2 ) ;
}
void F_105 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_155 -> V_8 ;
F_98 ( V_2 ) ;
if ( F_106 ( & V_8 -> V_61 , & V_174 ) )
F_100 ( V_8 , L_17 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_155 -> V_8 ;
F_101 ( V_2 ) ;
F_108 ( & V_8 -> V_61 , & V_174 ) ;
}

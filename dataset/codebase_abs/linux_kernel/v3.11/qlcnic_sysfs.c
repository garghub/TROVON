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
for ( V_65 = 0 ; V_65 < V_2 -> V_16 -> V_66 ; V_65 ++ ) {
V_64 = V_2 -> V_67 [ V_65 ] . V_64 ;
V_69 [ V_64 ] . V_80 = V_2 -> V_67 [ V_65 ] . V_83 ;
V_69 [ V_64 ] . V_77 = 0 ;
V_69 [ V_64 ] . V_64 = V_65 ;
}
memcpy ( V_11 , & V_69 , V_53 ) ;
return V_53 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_85 * V_86 , int V_70 )
{
T_1 V_50 ;
T_5 V_64 ;
int V_65 , V_14 ;
if ( F_31 ( V_2 ) )
V_50 = F_52 ( V_2 -> V_16 -> V_87 + V_88 ) ;
else
V_50 = F_53 ( V_2 -> V_16 , V_89 ) ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_86 [ V_65 ] . V_64 ;
if ( V_64 >= V_84 )
return V_41 ;
if ( V_2 -> V_16 -> V_50 == V_90 )
if ( F_46 ( V_2 , V_64 ) < 0 )
return V_41 ;
switch ( V_86 [ V_65 ] . V_50 ) {
case V_91 :
if ( F_31 ( V_2 ) ) {
V_14 = F_54 ( V_50 , V_64 ) ;
} else {
V_14 = F_55 ( V_50 ,
V_64 ) ;
V_86 [ V_65 ] . V_92 = 0 ;
}
if ( V_14 != V_51 ) {
if ( V_86 [ V_65 ] . V_93 != 0 )
return V_41 ;
if ( V_86 [ V_65 ] . V_94 != 1 )
return V_41 ;
if ( V_86 [ V_65 ] . V_95 != 1 )
return V_41 ;
}
break;
case V_96 :
if ( ! F_56 ( V_86 [ V_65 ] . V_97 ) )
return V_41 ;
if ( ! V_86 [ V_65 ] . V_98 )
return V_41 ;
break;
case V_99 :
if ( ! V_86 [ V_65 ] . V_98 )
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
struct V_85 * V_86 ;
struct V_100 * V_101 ;
int V_70 , V_81 , V_65 , V_14 ;
int V_82 ;
T_5 V_50 = 0 , V_64 ;
V_70 = V_53 / sizeof( struct V_85 ) ;
V_81 = V_53 % sizeof( struct V_85 ) ;
if ( V_81 )
return V_41 ;
V_86 = (struct V_85 * ) V_11 ;
V_14 = F_51 ( V_2 , V_86 , V_70 ) ;
if ( V_14 )
return V_14 ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
if ( V_2 -> V_16 -> V_50 == V_90 )
if ( F_58 ( V_2 , & V_86 [ V_65 ] ) )
return V_41 ;
if ( V_2 -> V_16 -> V_64 != V_86 [ V_65 ] . V_64 )
continue;
V_50 = V_86 [ V_65 ] . V_50 ;
F_59 ( V_2 , & V_86 [ V_65 ] ) ;
V_86 [ V_65 ] . V_50 = V_50 ;
V_86 [ V_65 ] . V_64 = V_2 -> V_16 -> V_64 ;
switch ( V_86 [ V_65 ] . V_50 ) {
case V_91 :
F_60 ( V_2 , & V_86 [ V_65 ] ) ;
F_16 () ;
F_61 ( V_2 , & V_86 [ V_65 ] ) ;
F_18 () ;
break;
case V_96 :
F_62 ( V_2 , & V_86 [ V_65 ] ) ;
break;
case V_99 :
V_86 [ V_65 ] . V_97 = 0 ;
F_62 ( V_2 , & V_86 [ V_65 ] ) ;
break;
}
}
if ( V_2 -> V_16 -> V_50 != V_90 )
goto V_47;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_86 [ V_65 ] . V_64 ;
V_82 = F_46 ( V_2 , V_64 ) ;
V_101 = & V_2 -> V_67 [ V_82 ] ;
switch ( V_86 [ V_65 ] . V_50 ) {
case V_91 :
V_101 -> V_95 = V_86 [ V_65 ] . V_95 ;
V_101 -> V_94 = V_86 [ V_65 ] . V_94 ;
V_101 -> V_92 = V_86 [ V_65 ] . V_92 ;
V_101 -> V_93 = V_86 [ V_65 ] . V_93 ;
V_101 -> V_102 = V_86 [ V_65 ] . V_102 ;
break;
case V_96 :
V_101 -> V_103 = V_86 [ V_65 ] . V_97 ;
break;
case V_99 :
V_101 -> V_103 = 0 ;
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
struct V_85 V_86 [ V_84 ] ;
T_5 V_65 , V_64 ;
if ( V_53 != sizeof( V_86 ) )
return V_41 ;
memset ( & V_86 , 0 ,
sizeof( struct V_85 ) * V_84 ) ;
for ( V_65 = 0 ; V_65 < V_2 -> V_16 -> V_66 ; V_65 ++ ) {
V_64 = V_2 -> V_67 [ V_65 ] . V_64 ;
V_86 [ V_64 ] . V_64 = V_64 ;
if ( F_59 ( V_2 , & V_86 [ V_64 ] ) )
return V_41 ;
}
memcpy ( V_11 , & V_86 , V_53 ) ;
return V_53 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_104 * V_105 ,
int V_70 )
{
T_5 V_64 , V_65 ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_105 [ V_65 ] . V_64 ;
if ( F_46 ( V_2 , V_64 ) < 0 )
return V_41 ;
if ( ! F_65 ( V_105 [ V_65 ] . V_106 ) ||
! F_65 ( V_105 [ V_65 ] . V_107 ) )
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
struct V_108 V_109 ;
struct V_104 * V_105 ;
int V_65 , V_70 , V_81 , V_14 , V_82 ;
T_5 V_64 ;
V_70 = V_53 / sizeof( struct V_104 ) ;
V_81 = V_53 % sizeof( struct V_104 ) ;
if ( V_81 )
return V_41 ;
V_105 = (struct V_104 * ) V_11 ;
V_14 = F_64 ( V_2 , V_105 , V_70 ) ;
if ( V_14 )
return V_14 ;
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_64 = V_105 [ V_65 ] . V_64 ;
memset ( & V_109 , 0 , sizeof( struct V_108 ) ) ;
V_14 = F_67 ( V_2 , & V_109 , V_64 ) ;
if ( V_14 )
return V_14 ;
V_109 . V_64 = V_64 ;
V_109 . V_110 = V_105 [ V_65 ] . V_106 ;
V_109 . V_111 = V_105 [ V_65 ] . V_107 ;
V_14 = F_68 ( V_2 , & V_109 ) ;
if ( V_14 )
return V_14 ;
V_82 = F_46 ( V_2 , V_64 ) ;
V_2 -> V_67 [ V_82 ] . V_106 = V_109 . V_110 ;
V_2 -> V_67 [ V_82 ] . V_107 = V_109 . V_111 ;
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
struct V_108 V_109 ;
struct V_104 V_105 [ V_84 ] ;
int V_65 , V_14 ;
if ( V_53 != sizeof( V_105 ) )
return V_41 ;
memset ( & V_109 , 0 , sizeof( struct V_108 ) ) ;
memset ( & V_105 , 0 ,
sizeof( struct V_104 ) * V_84 ) ;
for ( V_65 = 0 ; V_65 < V_84 ; V_65 ++ ) {
if ( F_46 ( V_2 , V_65 ) < 0 )
continue;
V_14 = F_67 ( V_2 , & V_109 , V_65 ) ;
if ( V_14 )
return V_14 ;
V_105 [ V_65 ] . V_64 = V_65 ;
V_105 [ V_65 ] . V_50 = ( T_5 ) V_109 . V_50 ;
V_105 [ V_65 ] . V_112 = V_109 . V_113 ;
V_105 [ V_65 ] . V_114 = V_109 . V_17 ;
V_105 [ V_65 ] . V_106 = V_109 . V_110 ;
V_105 [ V_65 ] . V_107 = V_109 . V_111 ;
V_105 [ V_65 ] . V_115 = V_109 . V_116 ;
V_105 [ V_65 ] . V_117 = V_109 . V_118 ;
}
memcpy ( V_11 , & V_105 , V_53 ) ;
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
struct V_119 V_120 ;
int V_14 ;
if ( F_32 ( V_2 ) )
return V_121 ;
if ( V_53 != sizeof( struct V_119 ) )
return V_41 ;
if ( V_52 >= V_84 )
return V_41 ;
memset ( & V_120 , 0 , V_53 ) ;
V_14 = F_71 ( V_2 , V_52 , V_122 ,
& V_120 . V_123 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_71 ( V_2 , V_52 , V_124 ,
& V_120 . V_125 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_120 , V_53 ) ;
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
struct V_119 V_126 ;
int V_14 ;
if ( F_32 ( V_2 ) )
return V_121 ;
if ( V_53 != sizeof( struct V_119 ) )
return V_41 ;
if ( V_52 >= V_127 )
return V_41 ;
memset ( & V_126 , 0 , V_53 ) ;
V_14 = F_73 ( V_2 , V_52 , V_122 ,
& V_126 . V_123 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_73 ( V_2 , V_52 , V_124 ,
& V_126 . V_125 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_126 , V_53 ) ;
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
return V_121 ;
if ( V_52 >= V_127 )
return V_41 ;
V_14 = F_75 ( V_2 , V_128 , V_52 ,
V_122 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_75 ( V_2 , V_128 , V_52 ,
V_124 ) ;
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
return V_121 ;
if ( V_52 >= V_84 )
return V_41 ;
V_14 = F_75 ( V_2 , V_129 , V_52 ,
V_122 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_75 ( V_2 , V_129 , V_52 ,
V_124 ) ;
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
struct V_130 V_131 [ V_84 ] ;
struct V_132 * V_133 ;
int V_65 , V_14 ;
if ( V_53 != sizeof( V_131 ) )
return V_41 ;
V_133 = F_78 ( V_84 , sizeof( * V_133 ) , V_134 ) ;
if ( ! V_133 )
return - V_135 ;
V_14 = F_79 ( V_2 , V_133 ) ;
if ( V_14 ) {
F_80 ( V_133 ) ;
return V_14 ;
}
memset ( & V_131 , 0 ,
sizeof( struct V_130 ) * V_84 ) ;
for ( V_65 = 0 ; V_65 < V_84 ; V_65 ++ ) {
V_131 [ V_65 ] . V_64 = V_133 [ V_65 ] . V_79 ;
V_131 [ V_65 ] . V_136 = V_133 [ V_65 ] . type ;
V_131 [ V_65 ] . V_112 = V_133 [ V_65 ] . V_137 ;
V_131 [ V_65 ] . V_106 = V_133 [ V_65 ] . V_138 ;
V_131 [ V_65 ] . V_107 = V_133 [ V_65 ] . V_139 ;
memcpy ( & V_131 [ V_65 ] . V_140 , & V_133 [ V_65 ] . V_141 , V_142 ) ;
}
memcpy ( V_11 , & V_131 , V_53 ) ;
F_80 ( V_133 ) ;
return V_53 ;
}
static T_2 F_81 ( struct V_58 * V_59 ,
struct V_60 * V_61 ,
struct V_62 * V_10 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
unsigned char * V_143 ;
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
V_143 = F_78 ( V_53 , sizeof( unsigned char ) , V_134 ) ;
if ( ! V_143 )
return - V_135 ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_143 ) ;
return - V_33 ;
}
V_14 = F_83 ( V_2 , V_52 , V_143 ,
V_70 ) ;
if ( V_14 ) {
F_84 ( V_2 ) ;
F_80 ( V_143 ) ;
return V_14 ;
}
F_84 ( V_2 ) ;
memcpy ( V_11 , V_143 , V_53 ) ;
F_80 ( V_143 ) ;
return V_53 ;
}
static int F_85 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_52 ,
T_3 V_53 )
{
int V_65 , V_14 , V_70 ;
unsigned char * V_144 , * V_145 ;
V_144 = F_78 ( V_53 , sizeof( unsigned char ) , V_134 ) ;
if ( ! V_144 )
return - V_135 ;
memcpy ( V_144 , V_11 , V_53 ) ;
V_145 = V_144 ;
V_70 = V_53 / sizeof( T_1 ) ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_144 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_146 . V_147 == V_2 -> V_148 ) {
V_14 = F_86 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_65 = 0 ; V_65 < V_70 / V_149 ; V_65 ++ ) {
V_14 = F_87 ( V_2 , V_52 ,
( T_1 * ) V_145 ,
V_149 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_146 . V_147 == V_2 -> V_148 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
V_145 = V_145 + sizeof( T_1 ) * V_149 ;
V_52 = V_52 + sizeof( T_1 ) * V_149 ;
}
if ( V_2 -> V_16 -> V_146 . V_147 == V_2 -> V_148 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_52 , T_3 V_53 )
{
int V_65 , V_14 , V_70 ;
unsigned char * V_144 , * V_145 ;
V_144 = F_78 ( V_53 , sizeof( unsigned char ) , V_134 ) ;
if ( ! V_144 )
return - V_135 ;
memcpy ( V_144 , V_11 , V_53 ) ;
V_145 = V_144 ;
V_70 = V_53 / sizeof( T_1 ) ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_144 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_146 . V_147 == V_2 -> V_148 ) {
V_14 = F_86 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_65 = 0 ; V_65 < V_70 ; V_65 ++ ) {
V_14 = F_90 ( V_2 , V_52 , ( T_1 * ) V_145 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_146 . V_147 == V_2 -> V_148 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
V_145 = V_145 + sizeof( T_1 ) ;
V_52 = V_52 + sizeof( T_1 ) ;
}
if ( V_2 -> V_16 -> V_146 . V_147 == V_2 -> V_148 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_144 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_144 ) ;
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
static int V_150 ;
unsigned long V_63 ;
struct V_7 * V_8 = F_37 ( V_61 , struct V_7 , V_61 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_11 )
return V_41 ;
V_14 = F_6 ( V_11 , 16 , & V_63 ) ;
switch ( V_63 ) {
case V_151 :
V_150 = V_152 ;
V_14 = F_92 ( V_2 , V_52 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_153 -> V_8 ,
L_5 , V_154 , __LINE__ ) ;
return - V_33 ;
}
break;
case V_155 :
V_150 = V_156 ;
break;
case V_157 :
V_150 = V_158 ;
break;
default:
if ( V_150 == V_156 ) {
V_14 = F_85 ( V_2 , V_11 ,
V_52 , V_53 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_153 -> V_8 ,
L_5 ,
V_154 , __LINE__ ) ;
return - V_33 ;
}
}
if ( V_150 == V_158 ) {
V_14 = F_89 ( V_2 , V_11 ,
V_52 , V_53 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_153 -> V_8 ,
L_5 , V_154 ,
__LINE__ ) ;
return - V_33 ;
}
}
}
return V_53 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_153 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
if ( F_95 ( V_8 , & V_159 ) )
F_30 ( V_8 ,
L_6 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_153 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
F_97 ( V_8 , & V_159 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_153 -> V_8 ;
if ( F_99 ( V_8 , & V_160 ) )
F_100 ( V_8 , L_7 ) ;
if ( V_2 -> V_16 -> V_50 == V_51 )
return;
if ( F_95 ( V_8 , & V_161 ) )
F_100 ( V_8 , L_8 ) ;
if ( F_99 ( V_8 , & V_162 ) )
F_100 ( V_8 , L_9 ) ;
if ( F_99 ( V_8 , & V_163 ) )
F_100 ( V_8 , L_10 ) ;
if ( F_99 ( V_8 , & V_164 ) )
F_100 ( V_8 , L_11 ) ;
if ( F_95 ( V_8 , & V_165 ) )
F_100 ( V_8 , L_12 ) ;
if ( ! ( V_2 -> V_22 & V_166 ) )
return;
if ( F_99 ( V_8 , & V_167 ) )
F_100 ( V_8 , L_13 ) ;
if ( V_2 -> V_16 -> V_50 != V_90 )
return;
if ( F_99 ( V_8 , & V_168 ) )
F_100 ( V_8 , L_14 ) ;
if ( F_99 ( V_8 , & V_169 ) )
F_100 ( V_8 , L_15 ) ;
if ( F_99 ( V_8 , & V_170 ) )
F_100 ( V_8 , L_16 ) ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_153 -> V_8 ;
F_102 ( V_8 , & V_160 ) ;
if ( V_2 -> V_16 -> V_50 == V_51 )
return;
F_97 ( V_8 , & V_161 ) ;
F_102 ( V_8 , & V_162 ) ;
F_102 ( V_8 , & V_163 ) ;
F_102 ( V_8 , & V_164 ) ;
F_97 ( V_8 , & V_165 ) ;
if ( ! ( V_2 -> V_22 & V_166 ) )
return;
F_102 ( V_8 , & V_167 ) ;
if ( V_2 -> V_16 -> V_50 != V_90 )
return;
F_102 ( V_8 , & V_168 ) ;
F_102 ( V_8 , & V_169 ) ;
F_102 ( V_8 , & V_170 ) ;
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
struct V_7 * V_8 = & V_2 -> V_153 -> V_8 ;
F_98 ( V_2 ) ;
if ( F_106 ( & V_8 -> V_61 , & V_171 ) )
F_100 ( V_8 , L_17 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_153 -> V_8 ;
F_101 ( V_2 ) ;
F_108 ( & V_8 -> V_61 , & V_171 ) ;
}

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
if ( ! V_2 -> V_21 -> V_22 ( V_2 , ! ! V_13 ) )
V_14 = V_12 ;
V_19:
return V_14 ;
}
static T_2 F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_23 = 0 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
V_23 = ! ! ( V_2 -> V_24 & V_25 ) ;
return sprintf ( V_11 , L_1 , V_23 ) ;
}
static T_2 F_8 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned long V_13 ;
if ( F_6 ( V_11 , 2 , & V_13 ) )
return - V_15 ;
if ( ! ! V_13 != ! ! ( V_2 -> V_24 & V_26 ) )
V_2 -> V_24 ^= V_26 ;
return V_12 ;
}
static T_2 F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
return sprintf ( V_11 , L_1 ,
! ! ( V_2 -> V_24 & V_26 ) ) ;
}
static int F_10 ( struct V_1 * V_2 , T_4 V_27 ,
T_5 * V_5 , T_5 * V_6 )
{
* V_6 = F_11 ( V_27 ) ;
* V_5 = F_12 ( V_27 ) ;
F_13 ( V_2 , V_28 , L_2 , * V_6 , * V_5 ) ;
if ( ! * V_5 ) {
* V_6 = V_29 ;
return 0 ;
} else if ( * V_5 > V_30 ) {
return - V_15 ;
}
if ( ( ! * V_6 ) || ( * V_6 > V_29 ) )
return - V_15 ;
return 0 ;
}
static T_2 F_14 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_31 = V_2 -> V_31 ;
T_4 V_27 ;
T_5 V_32 , V_33 ;
int V_34 ;
if ( V_2 -> V_16 -> V_35 == V_36 ) {
F_15 ( V_8 ,
L_3 ) ;
return - V_4 ;
}
if ( V_12 != sizeof( T_4 ) )
return V_37 ;
memcpy ( & V_27 , V_11 , sizeof( T_4 ) ) ;
V_34 = F_10 ( V_2 , V_27 , & V_32 , & V_33 ) ;
if ( V_34 )
return V_34 ;
if ( V_2 -> V_16 -> V_38 == V_32 )
return V_12 ;
F_16 () ;
if ( ! V_2 -> V_16 -> V_38 )
if ( F_17 ( V_39 , & V_2 -> V_5 ) ) {
F_18 () ;
return - V_40 ;
}
if ( F_5 ( V_41 , & V_2 -> V_5 ) ) {
V_34 = - V_42 ;
goto V_43;
}
if ( ! F_5 ( V_20 , & V_2 -> V_5 ) ) {
V_34 = F_19 ( V_2 -> V_44 , V_45 ) ;
if ( V_34 )
goto V_43;
F_20 ( V_46 , & V_2 -> V_5 ) ;
}
V_34 = F_21 ( V_2 , V_32 , V_33 ) ;
if ( ! V_34 ) {
V_34 = V_12 ;
V_2 -> V_16 -> V_38 = V_32 ;
}
if ( F_22 ( V_46 , & V_2 -> V_5 ) )
F_23 ( V_2 -> V_44 , V_31 ) ;
V_43:
if ( ! V_2 -> V_16 -> V_38 )
F_24 ( V_39 , & V_2 -> V_5 ) ;
F_18 () ;
return V_34 ;
}
static T_2 F_25 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
return sprintf ( V_11 , L_1 , V_2 -> V_16 -> V_38 ) ;
}
static int F_26 ( struct V_1 * V_2 ,
T_6 V_47 , T_3 V_48 )
{
T_3 V_49 = 4 ;
if ( ! ( V_2 -> V_24 & V_26 ) )
return - V_42 ;
if ( V_47 < V_50 ) {
if ( F_27 ( V_47 , V_51 ,
V_52 ) )
V_49 = 8 ;
else
return - V_15 ;
}
if ( ( V_48 != V_49 ) || ( V_47 & ( V_49 - 1 ) ) )
return - V_15 ;
return 0 ;
}
static T_2 F_28 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_58 ;
T_7 V_59 ;
int V_14 ;
V_14 = F_26 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_27 ( V_47 , V_51 , V_52 ) ) {
F_30 ( V_2 , V_47 , & V_59 ) ;
memcpy ( V_11 , & V_59 , V_48 ) ;
} else {
V_58 = F_31 ( V_2 , V_47 ) ;
memcpy ( V_11 , & V_58 , V_48 ) ;
}
return V_48 ;
}
static T_2 F_32 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_1 V_58 ;
T_7 V_59 ;
int V_14 ;
V_14 = F_26 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_27 ( V_47 , V_51 , V_52 ) ) {
memcpy ( & V_59 , V_11 , V_48 ) ;
F_33 ( V_2 , V_47 , V_59 ) ;
} else {
memcpy ( & V_58 , V_11 , V_48 ) ;
F_34 ( V_2 , V_47 , V_58 ) ;
}
return V_48 ;
}
static int F_35 ( struct V_1 * V_2 ,
T_6 V_47 , T_3 V_48 )
{
if ( ! ( V_2 -> V_24 & V_26 ) )
return - V_42 ;
if ( ( V_48 != 8 ) || ( V_47 & 0x7 ) )
return - V_42 ;
return 0 ;
}
static T_2 F_36 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_58 ;
int V_14 ;
V_14 = F_35 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_37 ( V_2 , V_47 , & V_58 ) )
return - V_42 ;
memcpy ( V_11 , & V_58 , V_48 ) ;
return V_48 ;
}
static T_2 F_38 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_58 ;
int V_14 ;
V_14 = F_35 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
memcpy ( & V_58 , V_11 , V_48 ) ;
if ( F_39 ( V_2 , V_47 , V_58 ) )
return - V_42 ;
return V_48 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_60 * V_61 , int V_62 )
{
T_5 V_63 , V_64 , V_65 , V_66 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ ) {
V_63 = V_61 [ V_67 ] . V_68 ;
V_66 = V_61 [ V_67 ] . V_69 ;
if ( V_63 >= V_70 ||
V_66 >= V_70 )
return V_37 ;
if ( V_2 -> V_71 [ V_63 ] . type != V_72 )
return V_37 ;
if ( V_2 -> V_71 [ V_66 ] . type != V_72 )
return V_37 ;
V_64 = V_2 -> V_71 [ V_63 ] . V_73 ;
V_65 = V_2 -> V_71 [ V_66 ] . V_73 ;
if ( V_64 != V_65 )
return V_37 ;
}
return 0 ;
}
static T_2 F_41 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_60 * V_61 ;
T_1 V_74 , V_75 , V_68 ;
int V_62 , V_76 , V_67 , V_14 ;
V_62 = V_48 / sizeof( struct V_60 ) ;
V_76 = V_48 % sizeof( struct V_60 ) ;
if ( V_76 )
return V_37 ;
V_61 = (struct V_60 * ) V_11 ;
V_14 = F_40 ( V_2 , V_61 , V_62 ) ;
if ( V_14 )
return V_14 ;
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ ) {
V_68 = V_61 [ V_67 ] . V_68 ;
V_75 = ! ! V_61 [ V_67 ] . V_75 ;
V_74 = V_2 -> V_71 [ V_68 ] . V_73 ;
V_14 = F_42 ( V_2 , V_74 , V_75 ,
V_68 ) ;
if ( V_14 )
return V_14 ;
}
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ ) {
V_68 = V_61 [ V_67 ] . V_68 ;
V_74 = V_2 -> V_71 [ V_68 ] . V_73 ;
V_2 -> V_71 [ V_68 ] . V_77 = ! ! V_61 [ V_67 ] . V_75 ;
V_2 -> V_71 [ V_68 ] . V_69 = V_74 ;
}
return V_48 ;
}
static T_2 F_43 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_60 V_61 [ V_70 ] ;
int V_67 ;
if ( V_48 != sizeof( V_61 ) )
return V_37 ;
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ ) {
if ( V_2 -> V_71 [ V_67 ] . type != V_72 )
continue;
V_61 [ V_67 ] . V_75 = V_2 -> V_71 [ V_67 ] . V_77 ;
V_61 [ V_67 ] . V_69 = 0 ;
V_61 [ V_67 ] . V_68 = V_67 ;
}
memcpy ( V_11 , & V_61 , V_48 ) ;
return V_48 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_78 * V_79 , int V_62 )
{
T_1 V_35 ;
T_5 V_68 ;
int V_67 ;
V_35 = F_45 ( V_2 -> V_16 -> V_80 + V_81 ) ;
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ ) {
V_68 = V_79 [ V_67 ] . V_68 ;
if ( V_68 >= V_70 )
return V_37 ;
if ( V_2 -> V_16 -> V_35 == V_82 ) {
if ( V_2 -> V_71 [ V_68 ] . type != V_72 )
return V_37 ;
}
switch ( V_79 [ V_67 ] . V_35 ) {
case V_83 :
if ( F_46 ( V_35 , V_68 ) !=
V_36 ) {
if ( V_79 [ V_67 ] . V_84 != 0 )
return V_37 ;
if ( V_79 [ V_67 ] . V_85 != 1 )
return V_37 ;
if ( V_79 [ V_67 ] . V_86 != 1 )
return V_37 ;
}
break;
case V_87 :
if ( ! F_47 ( V_79 [ V_67 ] . V_88 ) )
return V_37 ;
if ( ! V_79 [ V_67 ] . V_89 )
return V_37 ;
break;
case V_90 :
if ( ! V_79 [ V_67 ] . V_89 )
return V_37 ;
break;
default:
return V_37 ;
}
}
return 0 ;
}
static T_2 F_48 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_78 * V_79 ;
struct V_91 * V_92 ;
int V_62 , V_76 , V_67 , V_14 ;
T_5 V_68 , V_35 = 0 ;
V_62 = V_48 / sizeof( struct V_78 ) ;
V_76 = V_48 % sizeof( struct V_78 ) ;
if ( V_76 )
return V_37 ;
V_79 = (struct V_78 * ) V_11 ;
V_14 = F_44 ( V_2 , V_79 , V_62 ) ;
if ( V_14 )
return V_14 ;
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ ) {
if ( V_2 -> V_16 -> V_35 == V_82 ) {
if ( F_49 ( V_2 , & V_79 [ V_67 ] ) )
return V_37 ;
}
if ( V_2 -> V_16 -> V_68 != V_79 [ V_67 ] . V_68 )
continue;
V_35 = V_79 [ V_67 ] . V_35 ;
F_50 ( V_2 , & V_79 [ V_67 ] ) ;
V_79 [ V_67 ] . V_35 = V_35 ;
V_79 [ V_67 ] . V_68 = V_2 -> V_16 -> V_68 ;
switch ( V_79 [ V_67 ] . V_35 ) {
case V_83 :
F_51 ( V_2 , & V_79 [ V_67 ] ) ;
break;
case V_87 :
F_52 ( V_2 , & V_79 [ V_67 ] ) ;
break;
case V_90 :
V_79 [ V_67 ] . V_88 = 0 ;
F_52 ( V_2 , & V_79 [ V_67 ] ) ;
break;
}
}
if ( V_2 -> V_16 -> V_35 != V_82 )
goto V_43;
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ ) {
V_68 = V_79 [ V_67 ] . V_68 ;
V_92 = & V_2 -> V_71 [ V_68 ] ;
switch ( V_79 [ V_67 ] . V_35 ) {
case V_83 :
V_92 -> V_86 = V_79 [ V_67 ] . V_86 ;
V_92 -> V_85 = V_79 [ V_67 ] . V_85 ;
V_92 -> V_93 = V_79 [ V_67 ] . V_93 ;
V_92 -> V_84 = V_79 [ V_67 ] . V_84 ;
V_92 -> V_94 = V_79 [ V_67 ] . V_94 ;
break;
case V_87 :
V_92 -> V_95 = V_79 [ V_67 ] . V_88 ;
break;
case V_90 :
V_92 -> V_95 = 0 ;
break;
}
}
V_43:
return V_48 ;
}
static T_2 F_53 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_78 V_79 [ V_70 ] ;
T_5 V_67 ;
if ( V_48 != sizeof( V_79 ) )
return V_37 ;
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ ) {
if ( V_2 -> V_71 [ V_67 ] . type != V_72 )
continue;
V_79 [ V_67 ] . V_68 = V_67 ;
if ( F_50 ( V_2 , & V_79 [ V_67 ] ) )
return V_37 ;
}
memcpy ( V_11 , & V_79 , V_48 ) ;
return V_48 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_96 * V_97 ,
int V_62 )
{
T_5 V_68 , V_67 ;
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ ) {
V_68 = V_97 [ V_67 ] . V_68 ;
if ( V_68 >= V_70 )
return V_37 ;
if ( V_2 -> V_71 [ V_68 ] . type != V_72 )
return V_37 ;
if ( ! F_55 ( V_97 [ V_67 ] . V_98 ) ||
! F_55 ( V_97 [ V_67 ] . V_99 ) )
return V_37 ;
}
return 0 ;
}
static T_2 F_56 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_100 V_101 ;
struct V_96 * V_97 ;
int V_67 , V_62 , V_76 , V_14 ;
T_5 V_68 ;
V_62 = V_48 / sizeof( struct V_96 ) ;
V_76 = V_48 % sizeof( struct V_96 ) ;
if ( V_76 )
return V_37 ;
V_97 = (struct V_96 * ) V_11 ;
V_14 = F_54 ( V_2 , V_97 , V_62 ) ;
if ( V_14 )
return V_14 ;
for ( V_67 = 0 ; V_67 < V_62 ; V_67 ++ ) {
V_68 = V_97 [ V_67 ] . V_68 ;
V_14 = F_57 ( V_2 , & V_101 , V_68 ) ;
if ( V_14 )
return V_14 ;
V_101 . V_68 = V_68 ;
V_101 . V_102 = V_97 [ V_67 ] . V_98 ;
V_101 . V_103 = V_97 [ V_67 ] . V_99 ;
V_14 = F_58 ( V_2 , & V_101 ) ;
if ( V_14 )
return V_14 ;
V_2 -> V_71 [ V_67 ] . V_98 = V_101 . V_102 ;
V_2 -> V_71 [ V_67 ] . V_99 = V_101 . V_103 ;
}
return V_48 ;
}
static T_2 F_59 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_100 V_101 ;
struct V_96 V_97 [ V_70 ] ;
int V_67 , V_14 ;
if ( V_48 != sizeof( V_97 ) )
return V_37 ;
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ ) {
if ( V_2 -> V_71 [ V_67 ] . type != V_72 )
continue;
V_14 = F_57 ( V_2 , & V_101 , V_67 ) ;
if ( V_14 )
return V_14 ;
V_97 [ V_67 ] . V_68 = V_67 ;
V_97 [ V_67 ] . V_35 = ( T_5 ) V_101 . V_35 ;
V_97 [ V_67 ] . V_104 = V_101 . V_105 ;
V_97 [ V_67 ] . V_106 = V_101 . V_17 ;
V_97 [ V_67 ] . V_98 = V_101 . V_102 ;
V_97 [ V_67 ] . V_99 = V_101 . V_103 ;
V_97 [ V_67 ] . V_107 = V_101 . V_108 ;
V_97 [ V_67 ] . V_109 = V_101 . V_110 ;
}
memcpy ( V_11 , & V_97 , V_48 ) ;
return V_48 ;
}
static T_2 F_60 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_111 V_112 ;
int V_14 ;
if ( V_48 != sizeof( struct V_111 ) )
return V_37 ;
if ( V_47 >= V_70 )
return V_37 ;
memset ( & V_112 , 0 , V_48 ) ;
V_14 = F_61 ( V_2 , V_47 , V_113 ,
& V_112 . V_114 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_61 ( V_2 , V_47 , V_115 ,
& V_112 . V_116 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_112 , V_48 ) ;
return V_48 ;
}
static T_2 F_62 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_111 V_117 ;
int V_14 ;
if ( V_48 != sizeof( struct V_111 ) )
return V_37 ;
if ( V_47 >= V_118 )
return V_37 ;
memset ( & V_117 , 0 , V_48 ) ;
V_14 = F_63 ( V_2 , V_47 , V_113 ,
& V_117 . V_114 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_63 ( V_2 , V_47 , V_115 ,
& V_117 . V_116 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_117 , V_48 ) ;
return V_48 ;
}
static T_2 F_64 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( V_47 >= V_118 )
return V_37 ;
V_14 = F_65 ( V_2 , V_119 , V_47 ,
V_113 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_65 ( V_2 , V_119 , V_47 ,
V_115 ) ;
if ( V_14 )
return V_14 ;
return V_48 ;
}
static T_2 F_66 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( V_47 >= V_70 )
return V_37 ;
V_14 = F_65 ( V_2 , V_120 , V_47 ,
V_113 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_65 ( V_2 , V_120 , V_47 ,
V_115 ) ;
if ( V_14 )
return V_14 ;
return V_48 ;
}
static T_2 F_67 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_29 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_121 V_122 [ V_70 ] ;
struct V_123 * V_124 ;
int V_67 , V_14 ;
if ( V_48 != sizeof( V_122 ) )
return V_37 ;
V_124 = F_68 ( V_70 , sizeof( * V_124 ) , V_125 ) ;
if ( ! V_124 )
return - V_126 ;
V_14 = F_69 ( V_2 , V_124 ) ;
if ( V_14 ) {
F_70 ( V_124 ) ;
return V_14 ;
}
for ( V_67 = 0 ; V_67 < V_70 ; V_67 ++ ) {
V_122 [ V_67 ] . V_68 = V_124 [ V_67 ] . V_74 ;
V_122 [ V_67 ] . V_127 = V_124 [ V_67 ] . type ;
V_122 [ V_67 ] . V_104 = V_124 [ V_67 ] . V_128 ;
V_122 [ V_67 ] . V_98 = V_124 [ V_67 ] . V_129 ;
V_122 [ V_67 ] . V_99 = V_124 [ V_67 ] . V_130 ;
memcpy ( & V_122 [ V_67 ] . V_131 , & V_124 [ V_67 ] . V_132 , V_133 ) ;
}
memcpy ( V_11 , & V_122 , V_48 ) ;
F_70 ( V_124 ) ;
return V_48 ;
}
void F_71 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_134 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
if ( F_72 ( V_8 , & V_135 ) )
F_15 ( V_8 ,
L_4 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_134 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
F_74 ( V_8 , & V_135 ) ;
}
void F_75 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_134 -> V_8 ;
T_1 V_5 = F_31 ( V_2 , V_136 ) ;
if ( F_76 ( V_8 , & V_137 ) )
F_77 ( V_8 , L_5 ) ;
if ( V_2 -> V_16 -> V_35 == V_36 )
return;
if ( F_72 ( V_8 , & V_138 ) )
F_77 ( V_8 , L_6 ) ;
if ( F_76 ( V_8 , & V_139 ) )
F_77 ( V_8 , L_7 ) ;
if ( F_76 ( V_8 , & V_140 ) )
F_77 ( V_8 , L_8 ) ;
if ( V_5 == V_141 || ( V_5 == V_142 ) )
return;
if ( F_76 ( V_8 , & V_143 ) )
F_77 ( V_8 , L_9 ) ;
if ( F_72 ( V_8 , & V_144 ) )
F_77 ( V_8 , L_10 ) ;
if ( ! ( V_2 -> V_24 & V_145 ) )
return;
if ( F_76 ( V_8 , & V_146 ) )
F_77 ( V_8 , L_11 ) ;
if ( V_2 -> V_16 -> V_35 != V_82 )
return;
if ( F_76 ( V_8 , & V_147 ) )
F_77 ( V_8 , L_12 ) ;
if ( F_76 ( V_8 , & V_148 ) )
F_77 ( V_8 , L_13 ) ;
if ( F_76 ( V_8 , & V_149 ) )
F_77 ( V_8 , L_14 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_134 -> V_8 ;
T_1 V_5 = F_31 ( V_2 , V_136 ) ;
F_79 ( V_8 , & V_137 ) ;
if ( V_2 -> V_16 -> V_35 == V_36 )
return;
F_74 ( V_8 , & V_138 ) ;
F_79 ( V_8 , & V_139 ) ;
F_79 ( V_8 , & V_140 ) ;
if ( V_5 == V_141 || ( V_5 == V_142 ) )
return;
F_79 ( V_8 , & V_143 ) ;
F_74 ( V_8 , & V_144 ) ;
if ( ! ( V_2 -> V_24 & V_145 ) )
return;
F_79 ( V_8 , & V_146 ) ;
if ( V_2 -> V_16 -> V_35 != V_82 )
return;
F_79 ( V_8 , & V_147 ) ;
F_79 ( V_8 , & V_148 ) ;
F_79 ( V_8 , & V_149 ) ;
}

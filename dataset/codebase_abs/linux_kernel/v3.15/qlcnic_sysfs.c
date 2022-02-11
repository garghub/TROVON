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
F_16 ( V_2 ) ;
if ( V_16 -> V_34 == V_30 )
return V_12 ;
F_17 () ;
if ( ! V_16 -> V_34 ) {
if ( F_18 ( V_35 , & V_2 -> V_5 ) ) {
F_19 () ;
return - V_36 ;
}
}
if ( V_30 )
V_31 = F_20 ( V_2 , 1 , V_30 ) ;
else
V_31 = F_20 ( V_2 , 0 , ! V_30 ) ;
if ( ! V_31 )
V_16 -> V_34 = V_30 ;
if ( ! V_16 -> V_34 )
F_21 ( V_35 , & V_2 -> V_5 ) ;
F_19 () ;
return V_12 ;
}
static int F_22 ( struct V_1 * V_2 ,
const char * V_11 , T_3 V_12 )
{
struct V_29 * V_16 = V_2 -> V_16 ;
int V_31 , V_37 = V_2 -> V_37 ;
T_4 V_25 ;
T_5 V_38 , V_39 ;
if ( V_12 != sizeof( T_4 ) )
return V_40 ;
memcpy ( & V_25 , V_11 , sizeof( T_4 ) ) ;
V_31 = F_11 ( V_2 , V_25 , & V_38 , & V_39 ) ;
if ( V_31 )
return V_31 ;
F_16 ( V_2 ) ;
if ( V_16 -> V_34 == V_38 )
return V_12 ;
F_17 () ;
if ( ! V_16 -> V_34 ) {
if ( F_18 ( V_35 , & V_2 -> V_5 ) ) {
F_19 () ;
return - V_36 ;
}
}
if ( F_5 ( V_32 , & V_2 -> V_5 ) ) {
V_31 = - V_33 ;
goto V_41;
}
if ( ! F_5 ( V_20 , & V_2 -> V_5 ) ) {
V_31 = F_23 ( V_2 -> V_42 , V_43 ) ;
if ( V_31 )
goto V_41;
F_24 ( V_44 , & V_2 -> V_5 ) ;
}
V_31 = F_25 ( V_2 , V_38 , V_39 ) ;
if ( ! V_31 ) {
V_31 = V_12 ;
V_16 -> V_34 = V_38 ;
}
if ( F_26 ( V_44 , & V_2 -> V_5 ) )
F_27 ( V_2 -> V_42 , V_37 ) ;
V_41:
if ( ! V_16 -> V_34 )
F_21 ( V_35 , & V_2 -> V_5 ) ;
F_19 () ;
return V_31 ;
}
static T_2 F_28 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_31 = 0 ;
if ( V_2 -> V_16 -> V_45 == V_46 ) {
F_29 ( V_8 ,
L_3 ) ;
return - V_4 ;
}
if ( F_30 ( V_2 ) )
V_31 = F_22 ( V_2 , V_11 , V_12 ) ;
else if ( F_31 ( V_2 ) )
V_31 = F_15 ( V_2 , V_11 , V_12 ) ;
else
return - V_33 ;
return V_31 ;
}
static T_2 F_32 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
return sprintf ( V_11 , L_1 , V_2 -> V_16 -> V_34 ) ;
}
static int F_33 ( struct V_1 * V_2 ,
T_6 V_47 , T_3 V_48 )
{
T_3 V_49 = 4 ;
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_33 ;
if ( V_47 < V_50 ) {
if ( F_34 ( V_47 , V_51 ,
V_52 ) )
V_49 = 8 ;
else
return - V_15 ;
}
if ( ( V_48 != V_49 ) || ( V_47 & ( V_49 - 1 ) ) )
return - V_15 ;
return 0 ;
}
static T_2 F_35 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_33 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
F_37 ( V_2 , V_11 , V_47 , V_48 ) ;
return V_48 ;
}
static T_2 F_38 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_33 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
F_39 ( V_2 , V_11 , V_47 , V_48 ) ;
return V_48 ;
}
static int F_40 ( struct V_1 * V_2 ,
T_6 V_47 , T_3 V_48 )
{
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_33 ;
if ( ( V_48 != 8 ) || ( V_47 & 0x7 ) )
return - V_33 ;
return 0 ;
}
static T_2 F_41 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_58 ;
int V_14 ;
V_14 = F_40 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_42 ( V_2 , V_47 , & V_58 ) )
return - V_33 ;
memcpy ( V_11 , & V_58 , V_48 ) ;
return V_48 ;
}
static T_2 F_43 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_58 ;
int V_14 ;
V_14 = F_40 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
memcpy ( & V_58 , V_11 , V_48 ) ;
if ( F_44 ( V_2 , V_47 , V_58 ) )
return - V_33 ;
return V_48 ;
}
int F_45 ( struct V_1 * V_2 , T_5 V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 -> V_61 ; V_60 ++ ) {
if ( V_2 -> V_62 [ V_60 ] . V_59 == V_59 )
return V_60 ;
}
return - V_15 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_63 * V_64 , int V_65 )
{
T_5 V_66 , V_67 , V_68 ;
T_5 V_69 ;
int V_60 , V_70 , V_71 ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_66 = V_64 [ V_60 ] . V_59 ;
V_69 = V_64 [ V_60 ] . V_72 ;
V_70 = F_45 ( V_2 , V_66 ) ;
if ( V_70 < 0 )
return V_40 ;
V_71 = F_45 ( V_2 , V_69 ) ;
if ( V_71 < 0 )
return V_40 ;
V_67 = V_2 -> V_62 [ V_70 ] . V_73 ;
V_68 = V_2 -> V_62 [ V_71 ] . V_73 ;
if ( V_67 != V_68 )
return V_40 ;
}
return 0 ;
}
static T_2 F_47 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_63 * V_64 ;
T_1 V_74 , V_75 , V_59 ;
int V_65 , V_76 , V_60 , V_14 , V_77 ;
V_65 = V_48 / sizeof( struct V_63 ) ;
V_76 = V_48 % sizeof( struct V_63 ) ;
if ( V_76 )
return V_40 ;
V_64 = (struct V_63 * ) V_11 ;
V_14 = F_46 ( V_2 , V_64 , V_65 ) ;
if ( V_14 )
return V_14 ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_59 = V_64 [ V_60 ] . V_59 ;
V_75 = ! ! V_64 [ V_60 ] . V_75 ;
V_77 = F_45 ( V_2 , V_59 ) ;
if ( V_77 < 0 )
return V_40 ;
V_74 = V_2 -> V_62 [ V_77 ] . V_73 ;
V_14 = F_48 ( V_2 , V_74 ,
V_75 , V_59 ) ;
if ( V_14 )
return V_14 ;
}
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_59 = V_64 [ V_60 ] . V_59 ;
V_77 = F_45 ( V_2 , V_59 ) ;
if ( V_77 < 0 )
return V_40 ;
V_74 = V_2 -> V_62 [ V_77 ] . V_73 ;
V_2 -> V_62 [ V_77 ] . V_78 = ! ! V_64 [ V_60 ] . V_75 ;
V_2 -> V_62 [ V_77 ] . V_72 = V_74 ;
}
return V_48 ;
}
static T_2 F_49 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_63 * V_64 ;
T_5 V_59 ;
T_1 V_65 ;
int V_60 ;
memset ( V_11 , 0 , V_48 ) ;
V_64 = (struct V_63 * ) V_11 ;
V_65 = V_48 / sizeof( struct V_63 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 -> V_61 ; V_60 ++ ) {
V_59 = V_2 -> V_62 [ V_60 ] . V_59 ;
if ( V_59 >= V_65 ) {
F_50 ( V_8 , L_4 ,
V_79 , V_2 -> V_16 -> V_61 , V_65 ) ;
continue;
}
if ( ! V_2 -> V_62 [ V_60 ] . V_80 )
continue;
V_64 [ V_59 ] . V_75 = V_2 -> V_62 [ V_60 ] . V_78 ;
V_64 [ V_59 ] . V_72 = 0 ;
V_64 [ V_59 ] . V_59 = V_60 ;
}
return V_48 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_81 * V_82 , int V_65 )
{
struct V_29 * V_16 = V_2 -> V_16 ;
int V_60 , V_14 ;
T_1 V_45 ;
T_5 V_59 ;
if ( F_30 ( V_2 ) )
V_45 = F_52 ( V_16 -> V_83 + V_84 ) ;
else
V_45 = F_53 ( V_16 , V_85 ) ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_59 = V_82 [ V_60 ] . V_59 ;
if ( V_59 >= V_16 -> V_86 )
return V_40 ;
if ( V_2 -> V_16 -> V_45 == V_87 )
if ( F_45 ( V_2 , V_59 ) < 0 )
return V_40 ;
switch ( V_82 [ V_60 ] . V_45 ) {
case V_88 :
if ( F_30 ( V_2 ) ) {
V_14 = F_54 ( V_45 , V_59 ) ;
} else {
V_14 = F_55 ( V_45 ,
V_59 ) ;
V_82 [ V_60 ] . V_89 = 0 ;
}
if ( V_14 != V_46 ) {
if ( V_82 [ V_60 ] . V_90 != 0 )
return V_40 ;
if ( V_82 [ V_60 ] . V_91 != 1 )
return V_40 ;
if ( V_82 [ V_60 ] . V_92 != 1 )
return V_40 ;
}
break;
case V_93 :
if ( ! F_56 ( V_82 [ V_60 ] . V_94 ) )
return V_40 ;
if ( ! V_82 [ V_60 ] . V_95 )
return V_40 ;
break;
case V_96 :
if ( ! V_82 [ V_60 ] . V_95 )
return V_40 ;
break;
default:
return V_40 ;
}
}
return 0 ;
}
static T_2 F_57 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_81 * V_82 ;
struct V_97 * V_98 ;
int V_65 , V_76 , V_60 , V_14 ;
int V_77 ;
T_5 V_45 = 0 , V_59 ;
V_65 = V_48 / sizeof( struct V_81 ) ;
V_76 = V_48 % sizeof( struct V_81 ) ;
if ( V_76 )
return V_40 ;
V_82 = (struct V_81 * ) V_11 ;
V_14 = F_51 ( V_2 , V_82 , V_65 ) ;
if ( V_14 )
return V_14 ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
if ( V_2 -> V_16 -> V_45 == V_87 )
if ( F_58 ( V_2 , & V_82 [ V_60 ] ) )
return V_40 ;
if ( V_2 -> V_16 -> V_59 != V_82 [ V_60 ] . V_59 )
continue;
V_45 = V_82 [ V_60 ] . V_45 ;
F_59 ( V_2 , & V_82 [ V_60 ] ) ;
V_82 [ V_60 ] . V_45 = V_45 ;
V_82 [ V_60 ] . V_59 = V_2 -> V_16 -> V_59 ;
switch ( V_82 [ V_60 ] . V_45 ) {
case V_88 :
F_60 ( V_2 , & V_82 [ V_60 ] ) ;
F_17 () ;
F_61 ( V_2 , & V_82 [ V_60 ] ) ;
F_19 () ;
break;
case V_93 :
F_62 ( V_2 , & V_82 [ V_60 ] ) ;
break;
case V_96 :
V_82 [ V_60 ] . V_94 = 0 ;
F_62 ( V_2 , & V_82 [ V_60 ] ) ;
break;
}
}
if ( V_2 -> V_16 -> V_45 != V_87 )
goto V_41;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_59 = V_82 [ V_60 ] . V_59 ;
V_77 = F_45 ( V_2 , V_59 ) ;
if ( V_77 < 0 )
return V_40 ;
V_98 = & V_2 -> V_62 [ V_77 ] ;
switch ( V_82 [ V_60 ] . V_45 ) {
case V_88 :
V_98 -> V_92 = V_82 [ V_60 ] . V_92 ;
V_98 -> V_91 = V_82 [ V_60 ] . V_91 ;
V_98 -> V_89 = V_82 [ V_60 ] . V_89 ;
V_98 -> V_90 = V_82 [ V_60 ] . V_90 ;
V_98 -> V_99 = V_82 [ V_60 ] . V_99 ;
break;
case V_93 :
V_98 -> V_100 = V_82 [ V_60 ] . V_94 ;
break;
case V_96 :
V_98 -> V_100 = 0 ;
break;
}
}
V_41:
return V_48 ;
}
static T_2 F_63 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_81 * V_82 ;
T_5 V_59 ;
T_1 V_65 ;
int V_60 ;
memset ( V_11 , 0 , V_48 ) ;
V_82 = (struct V_81 * ) V_11 ;
V_65 = V_48 / sizeof( struct V_81 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 -> V_61 ; V_60 ++ ) {
V_59 = V_2 -> V_62 [ V_60 ] . V_59 ;
if ( V_59 >= V_65 ) {
F_50 ( V_8 , L_4 ,
V_79 , V_2 -> V_16 -> V_61 , V_65 ) ;
continue;
}
if ( ! V_2 -> V_62 [ V_60 ] . V_80 )
continue;
V_82 [ V_59 ] . V_59 = V_59 ;
if ( F_59 ( V_2 , & V_82 [ V_59 ] ) )
return V_40 ;
}
return V_48 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_101 * V_102 ,
int V_65 )
{
T_5 V_59 , V_60 ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_59 = V_102 [ V_60 ] . V_59 ;
if ( F_45 ( V_2 , V_59 ) < 0 )
return V_40 ;
if ( ! F_65 ( V_102 [ V_60 ] . V_103 ) ||
! F_65 ( V_102 [ V_60 ] . V_104 ) )
return V_40 ;
}
return 0 ;
}
static T_2 F_66 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_105 V_106 ;
struct V_101 * V_102 ;
int V_60 , V_65 , V_76 , V_14 , V_77 ;
T_5 V_59 ;
V_65 = V_48 / sizeof( struct V_101 ) ;
V_76 = V_48 % sizeof( struct V_101 ) ;
if ( V_76 )
return V_40 ;
V_102 = (struct V_101 * ) V_11 ;
V_14 = F_64 ( V_2 , V_102 , V_65 ) ;
if ( V_14 )
return V_14 ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_59 = V_102 [ V_60 ] . V_59 ;
memset ( & V_106 , 0 , sizeof( struct V_105 ) ) ;
V_14 = F_67 ( V_2 , & V_106 , V_59 ) ;
if ( V_14 )
return V_14 ;
V_106 . V_59 = V_59 ;
V_106 . V_107 = V_102 [ V_60 ] . V_103 ;
V_106 . V_108 = V_102 [ V_60 ] . V_104 ;
V_14 = F_68 ( V_2 , & V_106 ) ;
if ( V_14 )
return V_14 ;
V_77 = F_45 ( V_2 , V_59 ) ;
if ( V_77 < 0 )
return V_40 ;
V_2 -> V_62 [ V_77 ] . V_103 = V_106 . V_107 ;
V_2 -> V_62 [ V_77 ] . V_104 = V_106 . V_108 ;
}
return V_48 ;
}
static T_2 F_69 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_101 * V_102 ;
struct V_105 V_106 ;
T_5 V_59 ;
int V_60 , V_14 ;
T_1 V_65 ;
memset ( & V_106 , 0 , sizeof( struct V_105 ) ) ;
memset ( V_11 , 0 , V_48 ) ;
V_102 = (struct V_101 * ) V_11 ;
V_65 = V_48 / sizeof( struct V_101 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 -> V_61 ; V_60 ++ ) {
if ( V_2 -> V_62 [ V_60 ] . V_59 >= V_65 ) {
F_50 ( V_8 , L_4 ,
V_79 , V_2 -> V_16 -> V_61 , V_65 ) ;
continue;
}
if ( ! V_2 -> V_62 [ V_60 ] . V_80 )
continue;
V_59 = V_2 -> V_62 [ V_60 ] . V_59 ;
if ( F_45 ( V_2 , V_59 ) < 0 )
continue;
V_14 = F_67 ( V_2 , & V_106 , V_59 ) ;
if ( V_14 )
return V_14 ;
V_102 [ V_59 ] . V_59 = V_59 ;
V_102 [ V_59 ] . V_45 = ( T_5 ) V_106 . V_45 ;
V_102 [ V_59 ] . V_109 = V_106 . V_110 ;
V_102 [ V_59 ] . V_111 = V_106 . V_17 ;
V_102 [ V_59 ] . V_103 = V_106 . V_107 ;
V_102 [ V_59 ] . V_104 = V_106 . V_108 ;
V_102 [ V_59 ] . V_112 = V_106 . V_113 ;
V_102 [ V_59 ] . V_114 = V_106 . V_115 ;
}
return V_48 ;
}
static T_2 F_70 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_116 V_117 ;
int V_14 ;
if ( F_31 ( V_2 ) )
return V_118 ;
if ( V_48 != sizeof( struct V_116 ) )
return V_40 ;
if ( V_47 >= V_2 -> V_16 -> V_86 )
return V_40 ;
memset ( & V_117 , 0 , V_48 ) ;
V_14 = F_71 ( V_2 , V_47 , V_119 ,
& V_117 . V_120 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_71 ( V_2 , V_47 , V_121 ,
& V_117 . V_122 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_117 , V_48 ) ;
return V_48 ;
}
static T_2 F_72 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_116 V_123 ;
int V_14 ;
if ( F_31 ( V_2 ) )
return V_118 ;
if ( V_48 != sizeof( struct V_116 ) )
return V_40 ;
if ( V_47 >= V_124 )
return V_40 ;
memset ( & V_123 , 0 , V_48 ) ;
V_14 = F_73 ( V_2 , V_47 , V_119 ,
& V_123 . V_120 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_73 ( V_2 , V_47 , V_121 ,
& V_123 . V_122 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_123 , V_48 ) ;
return V_48 ;
}
static T_2 F_74 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_31 ( V_2 ) )
return V_118 ;
if ( V_47 >= V_124 )
return V_40 ;
V_14 = F_75 ( V_2 , V_125 , V_47 ,
V_119 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_75 ( V_2 , V_125 , V_47 ,
V_121 ) ;
if ( V_14 )
return V_14 ;
return V_48 ;
}
static T_2 F_76 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_31 ( V_2 ) )
return V_118 ;
if ( V_47 >= V_2 -> V_16 -> V_86 )
return V_40 ;
V_14 = F_75 ( V_2 , V_126 , V_47 ,
V_119 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_75 ( V_2 , V_126 , V_47 ,
V_121 ) ;
if ( V_14 )
return V_14 ;
return V_48 ;
}
static T_2 F_77 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
int V_60 , V_14 ;
T_1 V_65 ;
V_130 = F_78 ( V_48 , sizeof( * V_130 ) , V_131 ) ;
if ( ! V_130 )
return - V_132 ;
V_14 = F_79 ( V_2 , V_130 ) ;
if ( V_14 ) {
F_80 ( V_130 ) ;
return V_14 ;
}
V_128 = (struct V_127 * ) V_11 ;
V_65 = V_48 / sizeof( struct V_127 ) ;
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_128 [ V_60 ] . V_59 = V_130 [ V_60 ] . V_74 ;
V_128 [ V_60 ] . V_133 = V_130 [ V_60 ] . type ;
V_128 [ V_60 ] . V_134 = 0 ;
V_128 [ V_60 ] . V_109 = V_130 [ V_60 ] . V_135 ;
V_128 [ V_60 ] . V_103 = V_130 [ V_60 ] . V_136 ;
V_128 [ V_60 ] . V_104 = V_130 [ V_60 ] . V_137 ;
memcpy ( & V_128 [ V_60 ] . V_138 , & V_130 [ V_60 ] . V_139 , V_140 ) ;
}
F_80 ( V_130 ) ;
return V_48 ;
}
static T_2 F_81 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
unsigned char * V_141 ;
int V_14 , V_65 ;
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_48 )
return V_40 ;
if ( ! V_11 )
return V_40 ;
V_65 = V_48 / sizeof( T_1 ) ;
if ( V_48 % sizeof( T_1 ) )
V_65 ++ ;
V_141 = F_78 ( V_48 , sizeof( unsigned char ) , V_131 ) ;
if ( ! V_141 )
return - V_132 ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_141 ) ;
return - V_33 ;
}
V_14 = F_83 ( V_2 , V_47 , V_141 ,
V_65 ) ;
if ( V_14 ) {
F_84 ( V_2 ) ;
F_80 ( V_141 ) ;
return V_14 ;
}
F_84 ( V_2 ) ;
memcpy ( V_11 , V_141 , V_48 ) ;
F_80 ( V_141 ) ;
return V_48 ;
}
static int F_85 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
int V_60 , V_14 , V_65 ;
unsigned char * V_142 , * V_143 ;
V_142 = F_78 ( V_48 , sizeof( unsigned char ) , V_131 ) ;
if ( ! V_142 )
return - V_132 ;
memcpy ( V_142 , V_11 , V_48 ) ;
V_143 = V_142 ;
V_65 = V_48 / sizeof( T_1 ) ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_142 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_144 . V_145 == V_2 -> V_146 ) {
V_14 = F_86 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_60 = 0 ; V_60 < V_65 / V_147 ; V_60 ++ ) {
V_14 = F_87 ( V_2 , V_47 ,
( T_1 * ) V_143 ,
V_147 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_144 . V_145 == V_2 -> V_146 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
V_143 = V_143 + sizeof( T_1 ) * V_147 ;
V_47 = V_47 + sizeof( T_1 ) * V_147 ;
}
if ( V_2 -> V_16 -> V_144 . V_145 == V_2 -> V_146 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_47 , T_3 V_48 )
{
int V_60 , V_14 , V_65 ;
unsigned char * V_142 , * V_143 ;
V_142 = F_78 ( V_48 , sizeof( unsigned char ) , V_131 ) ;
if ( ! V_142 )
return - V_132 ;
memcpy ( V_142 , V_11 , V_48 ) ;
V_143 = V_142 ;
V_65 = V_48 / sizeof( T_1 ) ;
if ( F_82 ( V_2 ) != 0 ) {
F_80 ( V_142 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_144 . V_145 == V_2 -> V_146 ) {
V_14 = F_86 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_60 = 0 ; V_60 < V_65 ; V_60 ++ ) {
V_14 = F_90 ( V_2 , V_47 , ( T_1 * ) V_143 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_144 . V_145 == V_2 -> V_146 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
V_143 = V_143 + sizeof( T_1 ) ;
V_47 = V_47 + sizeof( T_1 ) ;
}
if ( V_2 -> V_16 -> V_144 . V_145 == V_2 -> V_146 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return - V_33 ;
}
}
F_80 ( V_142 ) ;
F_84 ( V_2 ) ;
return 0 ;
}
static T_2 F_91 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
int V_14 ;
static int V_148 ;
unsigned long V_58 ;
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_11 )
return V_40 ;
V_14 = F_6 ( V_11 , 16 , & V_58 ) ;
switch ( V_58 ) {
case V_149 :
V_148 = V_150 ;
V_14 = F_92 ( V_2 , V_47 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_151 -> V_8 ,
L_5 , V_79 , __LINE__ ) ;
return - V_33 ;
}
break;
case V_152 :
V_148 = V_153 ;
break;
case V_154 :
V_148 = V_155 ;
break;
default:
if ( V_148 == V_153 ) {
V_14 = F_85 ( V_2 , V_11 ,
V_47 , V_48 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_151 -> V_8 ,
L_5 ,
V_79 , __LINE__ ) ;
return - V_33 ;
}
}
if ( V_148 == V_155 ) {
V_14 = F_89 ( V_2 , V_11 ,
V_47 , V_48 ) ;
if ( V_14 ) {
F_93 ( & V_2 -> V_151 -> V_8 ,
L_5 , V_79 ,
__LINE__ ) ;
return - V_33 ;
}
}
}
return V_48 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_151 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
if ( F_95 ( V_8 , & V_156 ) )
F_29 ( V_8 ,
L_6 ) ;
}
void F_96 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_151 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
F_97 ( V_8 , & V_156 ) ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_151 -> V_8 ;
if ( F_99 ( V_8 , & V_157 ) )
F_100 ( V_8 , L_7 ) ;
if ( V_2 -> V_16 -> V_45 == V_46 )
return;
if ( F_95 ( V_8 , & V_158 ) )
F_100 ( V_8 , L_8 ) ;
if ( F_99 ( V_8 , & V_159 ) )
F_100 ( V_8 , L_9 ) ;
if ( F_99 ( V_8 , & V_160 ) )
F_100 ( V_8 , L_10 ) ;
if ( F_5 ( V_161 , & V_2 -> V_5 ) )
return;
if ( F_99 ( V_8 , & V_162 ) )
F_100 ( V_8 , L_11 ) ;
if ( F_95 ( V_8 , & V_163 ) )
F_100 ( V_8 , L_12 ) ;
if ( ! ( V_2 -> V_22 & V_164 ) )
return;
if ( F_99 ( V_8 , & V_165 ) )
F_100 ( V_8 , L_13 ) ;
if ( V_2 -> V_16 -> V_45 != V_87 )
return;
if ( F_99 ( V_8 , & V_166 ) )
F_100 ( V_8 , L_14 ) ;
if ( F_99 ( V_8 , & V_167 ) )
F_100 ( V_8 , L_15 ) ;
if ( F_99 ( V_8 , & V_168 ) )
F_100 ( V_8 , L_16 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_151 -> V_8 ;
F_102 ( V_8 , & V_157 ) ;
if ( V_2 -> V_16 -> V_45 == V_46 )
return;
F_97 ( V_8 , & V_158 ) ;
F_102 ( V_8 , & V_159 ) ;
F_102 ( V_8 , & V_160 ) ;
if ( F_5 ( V_161 , & V_2 -> V_5 ) )
return;
F_102 ( V_8 , & V_162 ) ;
F_97 ( V_8 , & V_163 ) ;
if ( ! ( V_2 -> V_22 & V_164 ) )
return;
F_102 ( V_8 , & V_165 ) ;
if ( V_2 -> V_16 -> V_45 != V_87 )
return;
F_102 ( V_8 , & V_166 ) ;
F_102 ( V_8 , & V_167 ) ;
F_102 ( V_8 , & V_168 ) ;
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
struct V_7 * V_8 = & V_2 -> V_151 -> V_8 ;
F_98 ( V_2 ) ;
if ( F_106 ( & V_8 -> V_56 , & V_169 ) )
F_100 ( V_8 , L_17 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_151 -> V_8 ;
F_101 ( V_2 ) ;
F_108 ( & V_8 -> V_56 , & V_169 ) ;
}

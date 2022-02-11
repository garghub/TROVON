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
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
return V_48 ;
}
static T_2 F_39 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_33 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
F_40 ( V_2 , V_11 , V_47 , V_48 ) ;
return V_48 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_6 V_47 , T_3 V_48 )
{
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_33 ;
if ( ( V_48 != 8 ) || ( V_47 & 0x7 ) )
return - V_33 ;
return 0 ;
}
static T_2 F_42 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_58 ;
int V_14 ;
V_14 = F_41 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_43 ( V_2 , V_47 , & V_58 ) )
return - V_33 ;
memcpy ( V_11 , & V_58 , V_48 ) ;
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
return V_48 ;
}
static T_2 F_44 ( struct V_53 * V_54 , struct V_55 * V_56 ,
struct V_57 * V_10 , char * V_11 ,
T_6 V_47 , T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_58 ;
int V_14 ;
V_14 = F_41 ( V_2 , V_47 , V_48 ) ;
if ( V_14 != 0 )
return V_14 ;
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
memcpy ( & V_58 , V_11 , V_48 ) ;
if ( F_45 ( V_2 , V_47 , V_58 ) )
return - V_33 ;
return V_48 ;
}
int F_46 ( struct V_1 * V_2 , T_5 V_59 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 -> V_61 ; V_60 ++ ) {
if ( V_2 -> V_62 [ V_60 ] . V_59 == V_59 )
return V_60 ;
}
F_47 ( & V_2 -> V_63 -> V_8 , L_4 , V_64 ) ;
return - V_15 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_65 * V_66 , int V_67 )
{
T_5 V_68 , V_69 , V_70 ;
T_5 V_71 ;
int V_60 , V_72 , V_73 ;
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_68 = V_66 [ V_60 ] . V_59 ;
V_71 = V_66 [ V_60 ] . V_74 ;
V_72 = F_46 ( V_2 , V_68 ) ;
if ( V_72 < 0 )
return V_40 ;
V_73 = F_46 ( V_2 , V_71 ) ;
if ( V_73 < 0 )
return V_40 ;
V_69 = V_2 -> V_62 [ V_72 ] . V_75 ;
V_70 = V_2 -> V_62 [ V_73 ] . V_75 ;
if ( V_69 != V_70 )
return V_40 ;
}
return 0 ;
}
static T_2 F_49 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_65 * V_66 ;
T_1 V_76 , V_77 , V_59 ;
int V_67 , V_78 , V_60 , V_14 , V_79 ;
V_67 = V_48 / sizeof( struct V_65 ) ;
V_78 = V_48 % sizeof( struct V_65 ) ;
if ( V_78 )
return V_40 ;
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
V_66 = (struct V_65 * ) V_11 ;
V_14 = F_48 ( V_2 , V_66 , V_67 ) ;
if ( V_14 )
return V_14 ;
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_59 = V_66 [ V_60 ] . V_59 ;
V_77 = ! ! V_66 [ V_60 ] . V_77 ;
V_79 = F_46 ( V_2 , V_59 ) ;
if ( V_79 < 0 )
return V_40 ;
V_76 = V_2 -> V_62 [ V_79 ] . V_75 ;
V_14 = F_50 ( V_2 , V_76 ,
V_77 , V_59 ) ;
if ( V_14 )
return V_14 ;
}
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_59 = V_66 [ V_60 ] . V_59 ;
V_79 = F_46 ( V_2 , V_59 ) ;
if ( V_79 < 0 )
return V_40 ;
V_76 = V_2 -> V_62 [ V_79 ] . V_75 ;
V_2 -> V_62 [ V_79 ] . V_80 = ! ! V_66 [ V_60 ] . V_77 ;
V_2 -> V_62 [ V_79 ] . V_74 = V_76 ;
}
return V_48 ;
}
static T_2 F_51 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_65 * V_66 ;
T_5 V_59 ;
T_1 V_67 ;
int V_60 ;
memset ( V_11 , 0 , V_48 ) ;
V_66 = (struct V_65 * ) V_11 ;
V_67 = V_48 / sizeof( struct V_65 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 -> V_61 ; V_60 ++ ) {
V_59 = V_2 -> V_62 [ V_60 ] . V_59 ;
if ( V_59 >= V_67 ) {
F_52 ( V_8 , L_5 ,
V_64 , V_2 -> V_16 -> V_61 , V_67 ) ;
continue;
}
if ( ! V_2 -> V_62 [ V_60 ] . V_81 )
continue;
V_66 [ V_59 ] . V_77 = V_2 -> V_62 [ V_60 ] . V_80 ;
V_66 [ V_59 ] . V_74 = 0 ;
V_66 [ V_59 ] . V_59 = V_60 ;
}
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
return V_48 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_82 * V_83 , int V_67 )
{
struct V_29 * V_16 = V_2 -> V_16 ;
int V_60 , V_14 ;
T_1 V_45 ;
T_5 V_59 ;
if ( F_30 ( V_2 ) )
V_45 = F_54 ( V_16 -> V_84 + V_85 ) ;
else
V_45 = F_55 ( V_16 , V_86 ) ;
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_59 = V_83 [ V_60 ] . V_59 ;
if ( V_59 >= V_16 -> V_87 )
return V_40 ;
if ( V_2 -> V_16 -> V_45 == V_88 )
if ( F_46 ( V_2 , V_59 ) < 0 )
return V_40 ;
switch ( V_83 [ V_60 ] . V_45 ) {
case V_89 :
if ( F_30 ( V_2 ) ) {
V_14 = F_56 ( V_45 , V_59 ) ;
} else {
V_14 = F_57 ( V_45 ,
V_59 ) ;
V_83 [ V_60 ] . V_90 = 0 ;
}
if ( V_14 != V_46 ) {
if ( V_83 [ V_60 ] . V_91 != 0 )
return V_40 ;
if ( V_83 [ V_60 ] . V_92 != 1 )
return V_40 ;
if ( V_83 [ V_60 ] . V_93 != 1 )
return V_40 ;
}
break;
case V_94 :
if ( ! F_58 ( V_83 [ V_60 ] . V_95 ) )
return V_40 ;
if ( ! V_83 [ V_60 ] . V_96 )
return V_40 ;
break;
case V_97 :
if ( ! V_83 [ V_60 ] . V_96 )
return V_40 ;
break;
default:
return V_40 ;
}
}
return 0 ;
}
static T_2 F_59 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_82 * V_83 ;
struct V_98 * V_99 ;
int V_67 , V_78 , V_60 , V_14 ;
int V_79 ;
T_5 V_45 = 0 , V_59 ;
V_67 = V_48 / sizeof( struct V_82 ) ;
V_78 = V_48 % sizeof( struct V_82 ) ;
if ( V_78 )
return V_40 ;
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
V_83 = (struct V_82 * ) V_11 ;
V_14 = F_53 ( V_2 , V_83 , V_67 ) ;
if ( V_14 )
return V_14 ;
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
if ( V_2 -> V_16 -> V_45 == V_88 )
if ( F_60 ( V_2 , & V_83 [ V_60 ] ) )
return V_40 ;
if ( V_2 -> V_16 -> V_59 != V_83 [ V_60 ] . V_59 )
continue;
V_45 = V_83 [ V_60 ] . V_45 ;
F_61 ( V_2 , & V_83 [ V_60 ] ) ;
V_83 [ V_60 ] . V_45 = V_45 ;
V_83 [ V_60 ] . V_59 = V_2 -> V_16 -> V_59 ;
switch ( V_83 [ V_60 ] . V_45 ) {
case V_89 :
F_62 ( V_2 , & V_83 [ V_60 ] ) ;
F_17 () ;
F_63 ( V_2 , & V_83 [ V_60 ] ) ;
F_19 () ;
break;
case V_94 :
F_64 ( V_2 , & V_83 [ V_60 ] ) ;
break;
case V_97 :
V_83 [ V_60 ] . V_95 = 0 ;
F_64 ( V_2 , & V_83 [ V_60 ] ) ;
break;
}
}
if ( V_2 -> V_16 -> V_45 != V_88 )
goto V_41;
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_59 = V_83 [ V_60 ] . V_59 ;
V_79 = F_46 ( V_2 , V_59 ) ;
if ( V_79 < 0 )
return V_40 ;
V_99 = & V_2 -> V_62 [ V_79 ] ;
switch ( V_83 [ V_60 ] . V_45 ) {
case V_89 :
V_99 -> V_93 = V_83 [ V_60 ] . V_93 ;
V_99 -> V_92 = V_83 [ V_60 ] . V_92 ;
V_99 -> V_90 = V_83 [ V_60 ] . V_90 ;
V_99 -> V_91 = V_83 [ V_60 ] . V_91 ;
V_99 -> V_100 = V_83 [ V_60 ] . V_100 ;
break;
case V_94 :
V_99 -> V_101 = V_83 [ V_60 ] . V_95 ;
break;
case V_97 :
V_99 -> V_101 = 0 ;
break;
}
}
V_41:
return V_48 ;
}
static T_2 F_65 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_82 * V_83 ;
T_5 V_59 ;
T_1 V_67 ;
int V_60 ;
memset ( V_11 , 0 , V_48 ) ;
V_83 = (struct V_82 * ) V_11 ;
V_67 = V_48 / sizeof( struct V_82 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 -> V_61 ; V_60 ++ ) {
V_59 = V_2 -> V_62 [ V_60 ] . V_59 ;
if ( V_59 >= V_67 ) {
F_52 ( V_8 , L_5 ,
V_64 , V_2 -> V_16 -> V_61 , V_67 ) ;
continue;
}
if ( ! V_2 -> V_62 [ V_60 ] . V_81 )
continue;
V_83 [ V_59 ] . V_59 = V_59 ;
if ( F_61 ( V_2 , & V_83 [ V_59 ] ) )
return V_40 ;
}
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
return V_48 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_102 * V_103 ,
int V_67 )
{
T_5 V_59 , V_60 ;
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_59 = V_103 [ V_60 ] . V_59 ;
if ( F_46 ( V_2 , V_59 ) < 0 )
return V_40 ;
if ( ! F_67 ( V_103 [ V_60 ] . V_104 ) ||
! F_67 ( V_103 [ V_60 ] . V_105 ) )
return V_40 ;
}
return 0 ;
}
static T_2 F_68 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_106 V_107 ;
struct V_102 * V_103 ;
int V_60 , V_67 , V_78 , V_14 , V_79 ;
T_5 V_59 ;
V_67 = V_48 / sizeof( struct V_102 ) ;
V_78 = V_48 % sizeof( struct V_102 ) ;
if ( V_78 )
return V_40 ;
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
V_103 = (struct V_102 * ) V_11 ;
V_14 = F_66 ( V_2 , V_103 , V_67 ) ;
if ( V_14 )
return V_14 ;
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_59 = V_103 [ V_60 ] . V_59 ;
memset ( & V_107 , 0 , sizeof( struct V_106 ) ) ;
V_14 = F_69 ( V_2 , & V_107 , V_59 ) ;
if ( V_14 )
return V_14 ;
V_107 . V_59 = V_59 ;
V_107 . V_108 = V_103 [ V_60 ] . V_104 ;
V_107 . V_109 = V_103 [ V_60 ] . V_105 ;
V_14 = F_70 ( V_2 , & V_107 ) ;
if ( V_14 )
return V_14 ;
V_79 = F_46 ( V_2 , V_59 ) ;
if ( V_79 < 0 )
return V_40 ;
V_2 -> V_62 [ V_79 ] . V_104 = V_107 . V_108 ;
V_2 -> V_62 [ V_79 ] . V_105 = V_107 . V_109 ;
}
return V_48 ;
}
static T_2 F_71 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_102 * V_103 ;
struct V_106 V_107 ;
T_5 V_59 ;
int V_60 , V_14 ;
T_1 V_67 ;
memset ( & V_107 , 0 , sizeof( struct V_106 ) ) ;
memset ( V_11 , 0 , V_48 ) ;
V_103 = (struct V_102 * ) V_11 ;
V_67 = V_48 / sizeof( struct V_102 ) ;
for ( V_60 = 0 ; V_60 < V_2 -> V_16 -> V_61 ; V_60 ++ ) {
if ( V_2 -> V_62 [ V_60 ] . V_59 >= V_67 ) {
F_52 ( V_8 , L_5 ,
V_64 , V_2 -> V_16 -> V_61 , V_67 ) ;
continue;
}
if ( ! V_2 -> V_62 [ V_60 ] . V_81 )
continue;
V_59 = V_2 -> V_62 [ V_60 ] . V_59 ;
if ( F_46 ( V_2 , V_59 ) < 0 )
continue;
V_14 = F_69 ( V_2 , & V_107 , V_59 ) ;
if ( V_14 )
return V_14 ;
V_103 [ V_59 ] . V_59 = V_59 ;
V_103 [ V_59 ] . V_45 = ( T_5 ) V_107 . V_45 ;
V_103 [ V_59 ] . V_110 = V_107 . V_111 ;
V_103 [ V_59 ] . V_112 = V_107 . V_17 ;
V_103 [ V_59 ] . V_104 = V_107 . V_108 ;
V_103 [ V_59 ] . V_105 = V_107 . V_109 ;
V_103 [ V_59 ] . V_113 = V_107 . V_114 ;
V_103 [ V_59 ] . V_115 = V_107 . V_116 ;
}
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
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
struct V_117 V_118 ;
int V_14 ;
if ( F_31 ( V_2 ) )
return V_119 ;
if ( V_48 != sizeof( struct V_117 ) )
return V_40 ;
if ( V_47 >= V_2 -> V_16 -> V_87 )
return V_40 ;
memset ( & V_118 , 0 , V_48 ) ;
V_14 = F_73 ( V_2 , V_47 , V_120 ,
& V_118 . V_121 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_73 ( V_2 , V_47 , V_122 ,
& V_118 . V_123 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_118 , V_48 ) ;
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
struct V_117 V_124 ;
int V_14 ;
if ( F_31 ( V_2 ) )
return V_119 ;
if ( V_48 != sizeof( struct V_117 ) )
return V_40 ;
if ( V_47 >= V_125 )
return V_40 ;
memset ( & V_124 , 0 , V_48 ) ;
V_14 = F_75 ( V_2 , V_47 , V_120 ,
& V_124 . V_121 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_75 ( V_2 , V_47 , V_122 ,
& V_124 . V_123 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_124 , V_48 ) ;
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
return V_119 ;
if ( V_47 >= V_125 )
return V_40 ;
V_14 = F_77 ( V_2 , V_126 , V_47 ,
V_120 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_77 ( V_2 , V_126 , V_47 ,
V_122 ) ;
if ( V_14 )
return V_14 ;
return V_48 ;
}
static T_2 F_78 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_31 ( V_2 ) )
return V_119 ;
if ( V_47 >= V_2 -> V_16 -> V_87 )
return V_40 ;
V_14 = F_77 ( V_2 , V_127 , V_47 ,
V_120 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_77 ( V_2 , V_127 , V_47 ,
V_122 ) ;
if ( V_14 )
return V_14 ;
return V_48 ;
}
static T_2 F_79 ( struct V_53 * V_53 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_128 * V_129 ;
struct V_130 * V_131 ;
int V_60 , V_14 ;
T_1 V_67 ;
V_131 = F_80 ( V_48 , sizeof( * V_131 ) , V_132 ) ;
if ( ! V_131 )
return - V_133 ;
V_14 = F_81 ( V_2 , V_131 ) ;
if ( V_14 ) {
F_82 ( V_131 ) ;
return V_14 ;
}
V_129 = (struct V_128 * ) V_11 ;
V_67 = V_48 / sizeof( struct V_128 ) ;
F_38 ( ( T_1 * ) V_131 , V_48 / sizeof( T_1 ) ) ;
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_129 [ V_60 ] . V_59 = V_131 [ V_60 ] . V_76 ;
V_129 [ V_60 ] . V_134 = V_131 [ V_60 ] . type ;
V_129 [ V_60 ] . V_135 = 0 ;
V_129 [ V_60 ] . V_110 = V_131 [ V_60 ] . V_136 ;
V_129 [ V_60 ] . V_104 = V_131 [ V_60 ] . V_137 ;
V_129 [ V_60 ] . V_105 = V_131 [ V_60 ] . V_138 ;
memcpy ( & V_129 [ V_60 ] . V_139 , & V_131 [ V_60 ] . V_140 , V_141 ) ;
}
F_82 ( V_131 ) ;
return V_48 ;
}
static T_2 F_83 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
unsigned char * V_142 ;
int V_14 , V_67 ;
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_48 )
return V_40 ;
if ( ! V_11 )
return V_40 ;
V_67 = V_48 / sizeof( T_1 ) ;
if ( V_48 % sizeof( T_1 ) )
V_67 ++ ;
V_142 = F_80 ( V_48 , sizeof( unsigned char ) , V_132 ) ;
if ( ! V_142 )
return - V_133 ;
if ( F_84 ( V_2 ) != 0 ) {
F_82 ( V_142 ) ;
return - V_33 ;
}
V_14 = F_85 ( V_2 , V_47 , V_142 ,
V_67 ) ;
if ( V_14 ) {
F_86 ( V_2 ) ;
F_82 ( V_142 ) ;
return V_14 ;
}
F_86 ( V_2 ) ;
F_38 ( ( T_1 * ) V_142 , V_67 ) ;
memcpy ( V_11 , V_142 , V_48 ) ;
F_82 ( V_142 ) ;
return V_48 ;
}
static int F_87 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
int V_60 , V_14 , V_67 ;
unsigned char * V_143 , * V_144 ;
V_143 = F_80 ( V_48 , sizeof( unsigned char ) , V_132 ) ;
if ( ! V_143 )
return - V_133 ;
V_67 = V_48 / sizeof( T_1 ) ;
F_38 ( ( T_1 * ) V_11 , V_67 ) ;
memcpy ( V_143 , V_11 , V_48 ) ;
V_144 = V_143 ;
if ( F_84 ( V_2 ) != 0 ) {
F_82 ( V_143 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_145 . V_146 == V_2 -> V_147 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_60 = 0 ; V_60 < V_67 / V_148 ; V_60 ++ ) {
V_14 = F_89 ( V_2 , V_47 ,
( T_1 * ) V_144 ,
V_148 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_145 . V_146 == V_2 -> V_147 ) {
V_14 = F_90 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
V_144 = V_144 + sizeof( T_1 ) * V_148 ;
V_47 = V_47 + sizeof( T_1 ) * V_148 ;
}
if ( V_2 -> V_16 -> V_145 . V_146 == V_2 -> V_147 ) {
V_14 = F_90 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_47 , T_3 V_48 )
{
int V_60 , V_14 , V_67 ;
unsigned char * V_143 , * V_144 ;
V_143 = F_80 ( V_48 , sizeof( unsigned char ) , V_132 ) ;
if ( ! V_143 )
return - V_133 ;
F_38 ( ( T_1 * ) V_11 , V_48 / sizeof( T_1 ) ) ;
memcpy ( V_143 , V_11 , V_48 ) ;
V_144 = V_143 ;
V_67 = V_48 / sizeof( T_1 ) ;
if ( F_84 ( V_2 ) != 0 ) {
F_82 ( V_143 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_145 . V_146 == V_2 -> V_147 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_60 = 0 ; V_60 < V_67 ; V_60 ++ ) {
V_14 = F_92 ( V_2 , V_47 , ( T_1 * ) V_144 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_145 . V_146 == V_2 -> V_147 ) {
V_14 = F_90 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
V_144 = V_144 + sizeof( T_1 ) ;
V_47 = V_47 + sizeof( T_1 ) ;
}
if ( V_2 -> V_16 -> V_145 . V_146 == V_2 -> V_147 ) {
V_14 = F_90 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
F_82 ( V_143 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
static T_2 F_93 ( struct V_53 * V_54 ,
struct V_55 * V_56 ,
struct V_57 * V_10 ,
char * V_11 , T_6 V_47 ,
T_3 V_48 )
{
int V_14 ;
static int V_149 ;
unsigned long V_58 ;
struct V_7 * V_8 = F_36 ( V_56 , struct V_7 , V_56 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_11 )
return V_40 ;
V_14 = F_6 ( V_11 , 16 , & V_58 ) ;
switch ( V_58 ) {
case V_150 :
V_149 = V_151 ;
V_14 = F_94 ( V_2 , V_47 ) ;
if ( V_14 ) {
F_47 ( & V_2 -> V_63 -> V_8 ,
L_6 , V_64 , __LINE__ ) ;
return - V_33 ;
}
break;
case V_152 :
V_149 = V_153 ;
break;
case V_154 :
V_149 = V_155 ;
break;
default:
if ( V_149 == V_153 ) {
V_14 = F_87 ( V_2 , V_11 ,
V_47 , V_48 ) ;
if ( V_14 ) {
F_47 ( & V_2 -> V_63 -> V_8 ,
L_6 ,
V_64 , __LINE__ ) ;
return - V_33 ;
}
}
if ( V_149 == V_155 ) {
V_14 = F_91 ( V_2 , V_11 ,
V_47 , V_48 ) ;
if ( V_14 ) {
F_47 ( & V_2 -> V_63 -> V_8 ,
L_6 , V_64 ,
__LINE__ ) ;
return - V_33 ;
}
}
}
return V_48 ;
}
static T_2 F_95 ( struct V_7 * V_8 ,
struct V_9 * V_156 ,
char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned int V_157 = 0 , V_158 = 0 ;
if ( F_31 ( V_2 ) )
V_158 = F_55 ( V_2 -> V_16 , V_159 ) ;
else if ( F_30 ( V_2 ) )
V_158 = F_96 ( V_2 , V_160 ) ;
V_157 = F_97 ( V_158 ) ;
V_157 *= 1000 ;
return sprintf ( V_11 , L_7 , V_157 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_63 -> V_8 ;
struct V_7 * V_161 ;
if ( F_99 ( V_2 ) ) {
V_2 -> V_16 -> V_161 = NULL ;
return;
}
V_161 = F_100 ( V_8 , V_162 ,
V_2 ,
V_163 ) ;
if ( F_101 ( V_161 ) ) {
F_47 ( V_8 , L_8 ,
F_102 ( V_161 ) ) ;
V_161 = NULL ;
}
V_2 -> V_16 -> V_161 = V_161 ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_7 * V_161 = V_2 -> V_16 -> V_161 ;
if ( V_161 ) {
F_104 ( V_161 ) ;
V_2 -> V_16 -> V_161 = NULL ;
}
}
void F_105 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_63 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
if ( F_106 ( V_8 , & V_164 ) )
F_29 ( V_8 ,
L_9 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_63 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
F_108 ( V_8 , & V_164 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_63 -> V_8 ;
if ( F_110 ( V_8 , & V_165 ) )
F_111 ( V_8 , L_10 ) ;
if ( V_2 -> V_16 -> V_45 == V_46 )
return;
if ( F_106 ( V_8 , & V_166 ) )
F_111 ( V_8 , L_11 ) ;
if ( F_110 ( V_8 , & V_167 ) )
F_111 ( V_8 , L_12 ) ;
if ( F_110 ( V_8 , & V_168 ) )
F_111 ( V_8 , L_13 ) ;
if ( F_5 ( V_169 , & V_2 -> V_5 ) )
return;
if ( F_110 ( V_8 , & V_170 ) )
F_111 ( V_8 , L_14 ) ;
if ( F_106 ( V_8 , & V_171 ) )
F_111 ( V_8 , L_15 ) ;
if ( ! ( V_2 -> V_22 & V_172 ) )
return;
if ( F_110 ( V_8 , & V_173 ) )
F_111 ( V_8 , L_16 ) ;
if ( V_2 -> V_16 -> V_45 != V_88 )
return;
if ( F_110 ( V_8 , & V_174 ) )
F_111 ( V_8 , L_17 ) ;
if ( F_110 ( V_8 , & V_175 ) )
F_111 ( V_8 , L_18 ) ;
if ( F_110 ( V_8 , & V_176 ) )
F_111 ( V_8 , L_19 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_63 -> V_8 ;
F_113 ( V_8 , & V_165 ) ;
if ( V_2 -> V_16 -> V_45 == V_46 )
return;
F_108 ( V_8 , & V_166 ) ;
F_113 ( V_8 , & V_167 ) ;
F_113 ( V_8 , & V_168 ) ;
if ( F_5 ( V_169 , & V_2 -> V_5 ) )
return;
F_113 ( V_8 , & V_170 ) ;
F_108 ( V_8 , & V_171 ) ;
if ( ! ( V_2 -> V_22 & V_172 ) )
return;
F_113 ( V_8 , & V_173 ) ;
if ( V_2 -> V_16 -> V_45 != V_88 )
return;
F_113 ( V_8 , & V_174 ) ;
F_113 ( V_8 , & V_175 ) ;
F_113 ( V_8 , & V_176 ) ;
}
void F_114 ( struct V_1 * V_2 )
{
F_109 ( V_2 ) ;
}
void F_115 ( struct V_1 * V_2 )
{
F_112 ( V_2 ) ;
}
void F_116 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_63 -> V_8 ;
F_109 ( V_2 ) ;
if ( F_117 ( & V_8 -> V_56 , & V_177 ) )
F_111 ( V_8 , L_20 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_63 -> V_8 ;
F_112 ( V_2 ) ;
F_119 ( & V_8 -> V_56 , & V_177 ) ;
}

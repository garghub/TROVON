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
return - V_15 ;
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
goto V_40;
}
if ( ! F_5 ( V_20 , & V_2 -> V_5 ) ) {
V_31 = F_23 ( V_2 -> V_41 , V_42 ) ;
if ( V_31 )
goto V_40;
F_24 ( V_43 , & V_2 -> V_5 ) ;
}
V_31 = F_25 ( V_2 , V_38 , V_39 ) ;
if ( ! V_31 ) {
V_31 = V_12 ;
V_16 -> V_34 = V_38 ;
}
if ( F_26 ( V_43 , & V_2 -> V_5 ) )
F_27 ( V_2 -> V_41 , V_37 ) ;
V_40:
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
if ( V_2 -> V_16 -> V_44 == V_45 ) {
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
T_6 V_46 , T_3 V_47 )
{
T_3 V_48 = 4 ;
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_33 ;
if ( V_46 < V_49 ) {
if ( F_34 ( V_46 , V_50 ,
V_51 ) )
V_48 = 8 ;
else
return - V_15 ;
}
if ( ( V_47 != V_48 ) || ( V_46 & ( V_48 - 1 ) ) )
return - V_15 ;
return 0 ;
}
static T_2 F_35 ( struct V_52 * V_53 , struct V_54 * V_55 ,
struct V_56 * V_10 , char * V_11 ,
T_6 V_46 , T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_33 ( V_2 , V_46 , V_47 ) ;
if ( V_14 != 0 )
return V_14 ;
F_37 ( V_2 , V_11 , V_46 , V_47 ) ;
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
return V_47 ;
}
static T_2 F_39 ( struct V_52 * V_53 , struct V_54 * V_55 ,
struct V_56 * V_10 , char * V_11 ,
T_6 V_46 , T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_33 ( V_2 , V_46 , V_47 ) ;
if ( V_14 != 0 )
return V_14 ;
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
F_40 ( V_2 , V_11 , V_46 , V_47 ) ;
return V_47 ;
}
static int F_41 ( struct V_1 * V_2 ,
T_6 V_46 , T_3 V_47 )
{
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_33 ;
if ( ( V_47 != 8 ) || ( V_46 & 0x7 ) )
return - V_33 ;
return 0 ;
}
static T_2 F_42 ( struct V_52 * V_53 , struct V_54 * V_55 ,
struct V_56 * V_10 , char * V_11 ,
T_6 V_46 , T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_57 ;
int V_14 ;
V_14 = F_41 ( V_2 , V_46 , V_47 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_43 ( V_2 , V_46 , & V_57 ) )
return - V_33 ;
memcpy ( V_11 , & V_57 , V_47 ) ;
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
return V_47 ;
}
static T_2 F_44 ( struct V_52 * V_53 , struct V_54 * V_55 ,
struct V_56 * V_10 , char * V_11 ,
T_6 V_46 , T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_57 ;
int V_14 ;
V_14 = F_41 ( V_2 , V_46 , V_47 ) ;
if ( V_14 != 0 )
return V_14 ;
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
memcpy ( & V_57 , V_11 , V_47 ) ;
if ( F_45 ( V_2 , V_46 , V_57 ) )
return - V_33 ;
return V_47 ;
}
int F_46 ( struct V_1 * V_2 , T_5 V_58 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_2 -> V_16 -> V_60 ; V_59 ++ ) {
if ( V_2 -> V_61 [ V_59 ] . V_58 == V_58 )
return V_59 ;
}
F_47 ( & V_2 -> V_62 -> V_8 , L_4 , V_63 ) ;
return - V_15 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_64 * V_65 , int V_66 )
{
T_5 V_67 , V_68 , V_69 ;
T_5 V_70 ;
int V_59 , V_71 , V_72 ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_67 = V_65 [ V_59 ] . V_58 ;
V_70 = V_65 [ V_59 ] . V_73 ;
V_71 = F_46 ( V_2 , V_67 ) ;
if ( V_71 < 0 )
return - V_15 ;
V_72 = F_46 ( V_2 , V_70 ) ;
if ( V_72 < 0 )
return - V_15 ;
V_68 = V_2 -> V_61 [ V_71 ] . V_74 ;
V_69 = V_2 -> V_61 [ V_72 ] . V_74 ;
if ( V_68 != V_69 )
return - V_15 ;
}
return 0 ;
}
static T_2 F_49 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_64 * V_65 ;
T_1 V_75 , V_76 , V_58 ;
int V_66 , V_77 , V_59 , V_14 , V_78 ;
V_66 = V_47 / sizeof( struct V_64 ) ;
V_77 = V_47 % sizeof( struct V_64 ) ;
if ( V_77 )
return - V_15 ;
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
V_65 = (struct V_64 * ) V_11 ;
V_14 = F_48 ( V_2 , V_65 , V_66 ) ;
if ( V_14 )
return V_14 ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_58 = V_65 [ V_59 ] . V_58 ;
V_76 = ! ! V_65 [ V_59 ] . V_76 ;
V_78 = F_46 ( V_2 , V_58 ) ;
if ( V_78 < 0 )
return - V_15 ;
V_75 = V_2 -> V_61 [ V_78 ] . V_74 ;
V_14 = F_50 ( V_2 , V_75 ,
V_76 , V_58 ) ;
if ( V_14 )
return V_14 ;
}
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_58 = V_65 [ V_59 ] . V_58 ;
V_78 = F_46 ( V_2 , V_58 ) ;
if ( V_78 < 0 )
return - V_15 ;
V_75 = V_2 -> V_61 [ V_78 ] . V_74 ;
V_2 -> V_61 [ V_78 ] . V_79 = ! ! V_65 [ V_59 ] . V_76 ;
V_2 -> V_61 [ V_78 ] . V_73 = V_75 ;
}
return V_47 ;
}
static T_2 F_51 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_64 * V_65 ;
T_5 V_58 ;
T_1 V_66 ;
int V_59 ;
memset ( V_11 , 0 , V_47 ) ;
V_65 = (struct V_64 * ) V_11 ;
V_66 = V_47 / sizeof( struct V_64 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_16 -> V_60 ; V_59 ++ ) {
V_58 = V_2 -> V_61 [ V_59 ] . V_58 ;
if ( V_58 >= V_66 ) {
F_52 ( V_8 , L_5 ,
V_63 , V_2 -> V_16 -> V_60 , V_66 ) ;
continue;
}
if ( ! V_2 -> V_61 [ V_59 ] . V_80 )
continue;
V_65 [ V_58 ] . V_76 = V_2 -> V_61 [ V_59 ] . V_79 ;
V_65 [ V_58 ] . V_73 = 0 ;
V_65 [ V_58 ] . V_58 = V_59 ;
}
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
return V_47 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_81 * V_82 , int V_66 )
{
struct V_29 * V_16 = V_2 -> V_16 ;
int V_59 , V_14 ;
T_1 V_44 ;
T_5 V_58 ;
if ( F_30 ( V_2 ) )
V_44 = F_54 ( V_16 -> V_83 + V_84 ) ;
else
V_44 = F_55 ( V_16 , V_85 ) ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_58 = V_82 [ V_59 ] . V_58 ;
if ( V_58 >= V_16 -> V_86 )
return - V_15 ;
if ( V_2 -> V_16 -> V_44 == V_87 )
if ( F_46 ( V_2 , V_58 ) < 0 )
return - V_15 ;
switch ( V_82 [ V_59 ] . V_44 ) {
case V_88 :
if ( F_30 ( V_2 ) ) {
V_14 = F_56 ( V_44 , V_58 ) ;
} else {
V_14 = F_57 ( V_44 ,
V_58 ) ;
V_82 [ V_59 ] . V_89 = 0 ;
}
if ( V_14 != V_45 ) {
if ( V_82 [ V_59 ] . V_90 != 0 )
return - V_15 ;
if ( V_82 [ V_59 ] . V_91 != 1 )
return - V_15 ;
if ( V_82 [ V_59 ] . V_92 != 1 )
return - V_15 ;
}
break;
case V_93 :
if ( ! F_58 ( V_82 [ V_59 ] . V_94 ) )
return - V_15 ;
if ( ! V_82 [ V_59 ] . V_95 )
return - V_15 ;
break;
case V_96 :
if ( ! V_82 [ V_59 ] . V_95 )
return - V_15 ;
break;
default:
return - V_15 ;
}
}
return 0 ;
}
static T_2 F_59 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_81 * V_82 ;
struct V_97 * V_98 ;
int V_66 , V_77 , V_59 , V_14 ;
int V_78 ;
T_5 V_44 = 0 , V_58 ;
V_66 = V_47 / sizeof( struct V_81 ) ;
V_77 = V_47 % sizeof( struct V_81 ) ;
if ( V_77 )
return - V_15 ;
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
V_82 = (struct V_81 * ) V_11 ;
V_14 = F_53 ( V_2 , V_82 , V_66 ) ;
if ( V_14 )
return V_14 ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
if ( V_2 -> V_16 -> V_44 == V_87 )
if ( F_60 ( V_2 , & V_82 [ V_59 ] ) )
return - V_15 ;
if ( V_2 -> V_16 -> V_58 != V_82 [ V_59 ] . V_58 )
continue;
V_44 = V_82 [ V_59 ] . V_44 ;
F_61 ( V_2 , & V_82 [ V_59 ] ) ;
V_82 [ V_59 ] . V_44 = V_44 ;
V_82 [ V_59 ] . V_58 = V_2 -> V_16 -> V_58 ;
switch ( V_82 [ V_59 ] . V_44 ) {
case V_88 :
F_62 ( V_2 , & V_82 [ V_59 ] ) ;
F_17 () ;
F_63 ( V_2 , & V_82 [ V_59 ] ) ;
F_19 () ;
break;
case V_93 :
F_64 ( V_2 , & V_82 [ V_59 ] ) ;
break;
case V_96 :
V_82 [ V_59 ] . V_94 = 0 ;
F_64 ( V_2 , & V_82 [ V_59 ] ) ;
break;
}
}
if ( V_2 -> V_16 -> V_44 != V_87 )
goto V_40;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_58 = V_82 [ V_59 ] . V_58 ;
V_78 = F_46 ( V_2 , V_58 ) ;
if ( V_78 < 0 )
return - V_15 ;
V_98 = & V_2 -> V_61 [ V_78 ] ;
switch ( V_82 [ V_59 ] . V_44 ) {
case V_88 :
V_98 -> V_92 = V_82 [ V_59 ] . V_92 ;
V_98 -> V_91 = V_82 [ V_59 ] . V_91 ;
V_98 -> V_89 = V_82 [ V_59 ] . V_89 ;
V_98 -> V_90 = V_82 [ V_59 ] . V_90 ;
V_98 -> V_99 = V_82 [ V_59 ] . V_99 ;
break;
case V_93 :
V_98 -> V_100 = V_82 [ V_59 ] . V_94 ;
break;
case V_96 :
V_98 -> V_100 = 0 ;
break;
}
}
V_40:
return V_47 ;
}
static T_2 F_65 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_81 * V_82 ;
T_5 V_58 ;
T_1 V_66 ;
int V_59 ;
memset ( V_11 , 0 , V_47 ) ;
V_82 = (struct V_81 * ) V_11 ;
V_66 = V_47 / sizeof( struct V_81 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_16 -> V_60 ; V_59 ++ ) {
V_58 = V_2 -> V_61 [ V_59 ] . V_58 ;
if ( V_58 >= V_66 ) {
F_52 ( V_8 , L_5 ,
V_63 , V_2 -> V_16 -> V_60 , V_66 ) ;
continue;
}
if ( ! V_2 -> V_61 [ V_59 ] . V_80 )
continue;
V_82 [ V_58 ] . V_58 = V_58 ;
if ( F_61 ( V_2 , & V_82 [ V_58 ] ) )
return - V_15 ;
}
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
return V_47 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_101 * V_102 ,
int V_66 )
{
T_5 V_58 , V_59 ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_58 = V_102 [ V_59 ] . V_58 ;
if ( F_46 ( V_2 , V_58 ) < 0 )
return - V_15 ;
if ( ! F_67 ( V_102 [ V_59 ] . V_103 ) ||
! F_67 ( V_102 [ V_59 ] . V_104 ) )
return - V_15 ;
}
return 0 ;
}
static T_2 F_68 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_105 V_106 ;
struct V_101 * V_102 ;
int V_59 , V_66 , V_77 , V_14 , V_78 ;
T_5 V_58 ;
V_66 = V_47 / sizeof( struct V_101 ) ;
V_77 = V_47 % sizeof( struct V_101 ) ;
if ( V_77 )
return - V_15 ;
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
V_102 = (struct V_101 * ) V_11 ;
V_14 = F_66 ( V_2 , V_102 , V_66 ) ;
if ( V_14 )
return V_14 ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_58 = V_102 [ V_59 ] . V_58 ;
memset ( & V_106 , 0 , sizeof( struct V_105 ) ) ;
V_14 = F_69 ( V_2 , & V_106 , V_58 ) ;
if ( V_14 )
return V_14 ;
V_106 . V_58 = V_58 ;
V_106 . V_107 = V_102 [ V_59 ] . V_103 ;
V_106 . V_108 = V_102 [ V_59 ] . V_104 ;
V_14 = F_70 ( V_2 , & V_106 ) ;
if ( V_14 )
return V_14 ;
V_78 = F_46 ( V_2 , V_58 ) ;
if ( V_78 < 0 )
return - V_15 ;
V_2 -> V_61 [ V_78 ] . V_103 = V_106 . V_107 ;
V_2 -> V_61 [ V_78 ] . V_104 = V_106 . V_108 ;
}
return V_47 ;
}
static T_2 F_71 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_101 * V_102 ;
struct V_105 V_106 ;
T_5 V_58 ;
int V_59 , V_14 ;
T_1 V_66 ;
memset ( & V_106 , 0 , sizeof( struct V_105 ) ) ;
memset ( V_11 , 0 , V_47 ) ;
V_102 = (struct V_101 * ) V_11 ;
V_66 = V_47 / sizeof( struct V_101 ) ;
for ( V_59 = 0 ; V_59 < V_2 -> V_16 -> V_60 ; V_59 ++ ) {
if ( V_2 -> V_61 [ V_59 ] . V_58 >= V_66 ) {
F_52 ( V_8 , L_5 ,
V_63 , V_2 -> V_16 -> V_60 , V_66 ) ;
continue;
}
if ( ! V_2 -> V_61 [ V_59 ] . V_80 )
continue;
V_58 = V_2 -> V_61 [ V_59 ] . V_58 ;
if ( F_46 ( V_2 , V_58 ) < 0 )
continue;
V_14 = F_69 ( V_2 , & V_106 , V_58 ) ;
if ( V_14 )
return V_14 ;
V_102 [ V_58 ] . V_58 = V_58 ;
V_102 [ V_58 ] . V_44 = ( T_5 ) V_106 . V_44 ;
V_102 [ V_58 ] . V_109 = V_106 . V_110 ;
V_102 [ V_58 ] . V_111 = V_106 . V_17 ;
V_102 [ V_58 ] . V_103 = V_106 . V_107 ;
V_102 [ V_58 ] . V_104 = V_106 . V_108 ;
V_102 [ V_58 ] . V_112 = V_106 . V_113 ;
V_102 [ V_58 ] . V_114 = V_106 . V_115 ;
}
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
return V_47 ;
}
static T_2 F_72 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_116 V_117 ;
int V_14 ;
if ( F_31 ( V_2 ) )
return - V_4 ;
if ( V_47 != sizeof( struct V_116 ) )
return - V_15 ;
if ( V_46 >= V_2 -> V_16 -> V_86 )
return - V_15 ;
memset ( & V_117 , 0 , V_47 ) ;
V_14 = F_73 ( V_2 , V_46 , V_118 ,
& V_117 . V_119 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_73 ( V_2 , V_46 , V_120 ,
& V_117 . V_121 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_117 , V_47 ) ;
return V_47 ;
}
static T_2 F_74 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_116 V_122 ;
int V_14 ;
if ( F_31 ( V_2 ) )
return - V_4 ;
if ( V_47 != sizeof( struct V_116 ) )
return - V_15 ;
if ( V_46 >= V_123 )
return - V_15 ;
memset ( & V_122 , 0 , V_47 ) ;
V_14 = F_75 ( V_2 , V_46 , V_118 ,
& V_122 . V_119 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_75 ( V_2 , V_46 , V_120 ,
& V_122 . V_121 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_122 , V_47 ) ;
return V_47 ;
}
static T_2 F_76 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_31 ( V_2 ) )
return - V_4 ;
if ( V_46 >= V_123 )
return - V_15 ;
V_14 = F_77 ( V_2 , V_124 , V_46 ,
V_118 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_77 ( V_2 , V_124 , V_46 ,
V_120 ) ;
if ( V_14 )
return V_14 ;
return V_47 ;
}
static T_2 F_78 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_31 ( V_2 ) )
return - V_4 ;
if ( V_46 >= V_2 -> V_16 -> V_86 )
return - V_15 ;
V_14 = F_77 ( V_2 , V_125 , V_46 ,
V_118 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_77 ( V_2 , V_125 , V_46 ,
V_120 ) ;
if ( V_14 )
return V_14 ;
return V_47 ;
}
static T_2 F_79 ( struct V_52 * V_52 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_126 * V_127 ;
struct V_128 * V_129 ;
int V_59 , V_14 ;
T_1 V_66 ;
V_129 = F_80 ( V_47 , sizeof( * V_129 ) , V_130 ) ;
if ( ! V_129 )
return - V_131 ;
V_14 = F_81 ( V_2 , V_129 ) ;
if ( V_14 ) {
F_82 ( V_129 ) ;
return V_14 ;
}
V_127 = (struct V_126 * ) V_11 ;
V_66 = V_47 / sizeof( struct V_126 ) ;
F_38 ( ( T_1 * ) V_129 , V_47 / sizeof( T_1 ) ) ;
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_127 [ V_59 ] . V_58 = V_129 [ V_59 ] . V_75 ;
V_127 [ V_59 ] . V_132 = V_129 [ V_59 ] . type ;
V_127 [ V_59 ] . V_133 = 0 ;
V_127 [ V_59 ] . V_109 = V_129 [ V_59 ] . V_134 ;
V_127 [ V_59 ] . V_103 = V_129 [ V_59 ] . V_135 ;
V_127 [ V_59 ] . V_104 = V_129 [ V_59 ] . V_136 ;
memcpy ( & V_127 [ V_59 ] . V_137 , & V_129 [ V_59 ] . V_138 , V_139 ) ;
}
F_82 ( V_129 ) ;
return V_47 ;
}
static T_2 F_83 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
unsigned char * V_140 ;
int V_14 , V_66 ;
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
if ( ! V_47 )
return - V_15 ;
V_66 = V_47 / sizeof( T_1 ) ;
if ( V_47 % sizeof( T_1 ) )
V_66 ++ ;
V_140 = F_80 ( V_47 , sizeof( unsigned char ) , V_130 ) ;
if ( ! V_140 )
return - V_131 ;
if ( F_84 ( V_2 ) != 0 ) {
F_82 ( V_140 ) ;
return - V_33 ;
}
V_14 = F_85 ( V_2 , V_46 , V_140 ,
V_66 ) ;
if ( V_14 ) {
F_86 ( V_2 ) ;
F_82 ( V_140 ) ;
return V_14 ;
}
F_86 ( V_2 ) ;
F_38 ( ( T_1 * ) V_140 , V_66 ) ;
memcpy ( V_11 , V_140 , V_47 ) ;
F_82 ( V_140 ) ;
return V_47 ;
}
static int F_87 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
int V_59 , V_14 , V_66 ;
unsigned char * V_141 , * V_142 ;
V_141 = F_80 ( V_47 , sizeof( unsigned char ) , V_130 ) ;
if ( ! V_141 )
return - V_131 ;
V_66 = V_47 / sizeof( T_1 ) ;
F_38 ( ( T_1 * ) V_11 , V_66 ) ;
memcpy ( V_141 , V_11 , V_47 ) ;
V_142 = V_141 ;
if ( F_84 ( V_2 ) != 0 ) {
F_82 ( V_141 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_143 . V_144 == V_2 -> V_145 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_59 = 0 ; V_59 < V_66 / V_146 ; V_59 ++ ) {
V_14 = F_89 ( V_2 , V_46 ,
( T_1 * ) V_142 ,
V_146 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_143 . V_144 == V_2 -> V_145 ) {
V_14 = F_90 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
V_142 = V_142 + sizeof( T_1 ) * V_146 ;
V_46 = V_46 + sizeof( T_1 ) * V_146 ;
}
if ( V_2 -> V_16 -> V_143 . V_144 == V_2 -> V_145 ) {
V_14 = F_90 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
static int F_91 ( struct V_1 * V_2 ,
char * V_11 , T_6 V_46 , T_3 V_47 )
{
int V_59 , V_14 , V_66 ;
unsigned char * V_141 , * V_142 ;
V_141 = F_80 ( V_47 , sizeof( unsigned char ) , V_130 ) ;
if ( ! V_141 )
return - V_131 ;
F_38 ( ( T_1 * ) V_11 , V_47 / sizeof( T_1 ) ) ;
memcpy ( V_141 , V_11 , V_47 ) ;
V_142 = V_141 ;
V_66 = V_47 / sizeof( T_1 ) ;
if ( F_84 ( V_2 ) != 0 ) {
F_82 ( V_141 ) ;
return - V_33 ;
}
if ( V_2 -> V_16 -> V_143 . V_144 == V_2 -> V_145 ) {
V_14 = F_88 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
for ( V_59 = 0 ; V_59 < V_66 ; V_59 ++ ) {
V_14 = F_92 ( V_2 , V_46 , ( T_1 * ) V_142 ) ;
if ( V_14 ) {
if ( V_2 -> V_16 -> V_143 . V_144 == V_2 -> V_145 ) {
V_14 = F_90 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
V_142 = V_142 + sizeof( T_1 ) ;
V_46 = V_46 + sizeof( T_1 ) ;
}
if ( V_2 -> V_16 -> V_143 . V_144 == V_2 -> V_145 ) {
V_14 = F_90 ( V_2 ) ;
if ( V_14 ) {
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return - V_33 ;
}
}
F_82 ( V_141 ) ;
F_86 ( V_2 ) ;
return 0 ;
}
static T_2 F_93 ( struct V_52 * V_53 ,
struct V_54 * V_55 ,
struct V_56 * V_10 ,
char * V_11 , T_6 V_46 ,
T_3 V_47 )
{
int V_14 ;
static int V_147 ;
unsigned long V_57 ;
struct V_7 * V_8 = F_36 ( V_55 , struct V_7 , V_55 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
V_14 = F_6 ( V_11 , 16 , & V_57 ) ;
switch ( V_57 ) {
case V_148 :
V_147 = V_149 ;
V_14 = F_94 ( V_2 , V_46 ) ;
if ( V_14 ) {
F_47 ( & V_2 -> V_62 -> V_8 ,
L_6 , V_63 , __LINE__ ) ;
return - V_33 ;
}
break;
case V_150 :
V_147 = V_151 ;
break;
case V_152 :
V_147 = V_153 ;
break;
default:
if ( V_147 == V_151 ) {
V_14 = F_87 ( V_2 , V_11 ,
V_46 , V_47 ) ;
if ( V_14 ) {
F_47 ( & V_2 -> V_62 -> V_8 ,
L_6 ,
V_63 , __LINE__ ) ;
return - V_33 ;
}
}
if ( V_147 == V_153 ) {
V_14 = F_91 ( V_2 , V_11 ,
V_46 , V_47 ) ;
if ( V_14 ) {
F_47 ( & V_2 -> V_62 -> V_8 ,
L_6 , V_63 ,
__LINE__ ) ;
return - V_33 ;
}
}
}
return V_47 ;
}
static T_2 F_95 ( struct V_7 * V_8 ,
struct V_9 * V_154 ,
char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned int V_155 = 0 , V_156 = 0 ;
if ( F_31 ( V_2 ) )
V_156 = F_55 ( V_2 -> V_16 , V_157 ) ;
else if ( F_30 ( V_2 ) )
V_156 = F_96 ( V_2 , V_158 ) ;
V_155 = F_97 ( V_156 ) ;
V_155 *= 1000 ;
return sprintf ( V_11 , L_7 , V_155 ) ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_62 -> V_8 ;
struct V_7 * V_159 ;
if ( F_99 ( V_2 ) ) {
V_2 -> V_16 -> V_159 = NULL ;
return;
}
V_159 = F_100 ( V_8 , V_160 ,
V_2 ,
V_161 ) ;
if ( F_101 ( V_159 ) ) {
F_47 ( V_8 , L_8 ,
F_102 ( V_159 ) ) ;
V_159 = NULL ;
}
V_2 -> V_16 -> V_159 = V_159 ;
}
void F_103 ( struct V_1 * V_2 )
{
struct V_7 * V_159 = V_2 -> V_16 -> V_159 ;
if ( V_159 ) {
F_104 ( V_159 ) ;
V_2 -> V_16 -> V_159 = NULL ;
}
}
void F_105 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_62 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
if ( F_106 ( V_8 , & V_162 ) )
F_29 ( V_8 ,
L_9 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_62 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
F_108 ( V_8 , & V_162 ) ;
}
static void F_109 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_62 -> V_8 ;
if ( F_110 ( V_8 , & V_163 ) )
F_111 ( V_8 , L_10 ) ;
if ( V_2 -> V_16 -> V_44 == V_45 )
return;
if ( F_106 ( V_8 , & V_164 ) )
F_111 ( V_8 , L_11 ) ;
if ( F_110 ( V_8 , & V_165 ) )
F_111 ( V_8 , L_12 ) ;
if ( F_110 ( V_8 , & V_166 ) )
F_111 ( V_8 , L_13 ) ;
if ( F_5 ( V_167 , & V_2 -> V_5 ) )
return;
if ( F_110 ( V_8 , & V_168 ) )
F_111 ( V_8 , L_14 ) ;
if ( F_106 ( V_8 , & V_169 ) )
F_111 ( V_8 , L_15 ) ;
if ( ! ( V_2 -> V_22 & V_170 ) )
return;
if ( F_110 ( V_8 , & V_171 ) )
F_111 ( V_8 , L_16 ) ;
if ( V_2 -> V_16 -> V_44 != V_87 )
return;
if ( F_110 ( V_8 , & V_172 ) )
F_111 ( V_8 , L_17 ) ;
if ( F_110 ( V_8 , & V_173 ) )
F_111 ( V_8 , L_18 ) ;
if ( F_110 ( V_8 , & V_174 ) )
F_111 ( V_8 , L_19 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_62 -> V_8 ;
F_113 ( V_8 , & V_163 ) ;
if ( V_2 -> V_16 -> V_44 == V_45 )
return;
F_108 ( V_8 , & V_164 ) ;
F_113 ( V_8 , & V_165 ) ;
F_113 ( V_8 , & V_166 ) ;
if ( F_5 ( V_167 , & V_2 -> V_5 ) )
return;
F_113 ( V_8 , & V_168 ) ;
F_108 ( V_8 , & V_169 ) ;
if ( ! ( V_2 -> V_22 & V_170 ) )
return;
F_113 ( V_8 , & V_171 ) ;
if ( V_2 -> V_16 -> V_44 != V_87 )
return;
F_113 ( V_8 , & V_172 ) ;
F_113 ( V_8 , & V_173 ) ;
F_113 ( V_8 , & V_174 ) ;
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
struct V_7 * V_8 = & V_2 -> V_62 -> V_8 ;
F_109 ( V_2 ) ;
if ( F_117 ( & V_8 -> V_55 , & V_175 ) )
F_111 ( V_8 , L_20 ) ;
}
void F_118 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_62 -> V_8 ;
F_112 ( V_2 ) ;
F_119 ( & V_8 -> V_55 , & V_175 ) ;
}

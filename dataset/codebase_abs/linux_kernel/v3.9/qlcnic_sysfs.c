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
static T_2 F_15 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
const char * V_11 , T_3 V_12 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_29 * V_16 = V_2 -> V_16 ;
int V_30 , V_31 = V_2 -> V_31 ;
T_4 V_25 ;
T_5 V_32 , V_33 ;
unsigned long V_34 ;
if ( V_2 -> V_16 -> V_35 == V_36 ) {
F_16 ( V_8 ,
L_3 ) ;
return - V_4 ;
}
if ( F_17 ( V_2 ) &&
! F_5 ( V_37 , & V_2 -> V_5 ) ) {
if ( F_18 ( V_11 , 2 , & V_34 ) )
return - V_15 ;
if ( V_16 -> V_38 == V_34 )
return V_12 ;
F_19 () ;
if ( ! V_16 -> V_38 ) {
if ( F_20 ( V_39 ,
& V_2 -> V_5 ) ) {
F_21 () ;
return - V_40 ;
}
}
if ( V_34 ) {
V_30 = F_22 ( V_2 , 1 , V_34 ) ;
if ( V_30 )
goto V_41;
} else {
V_30 = F_22 ( V_2 , 0 , ! V_34 ) ;
if ( V_30 )
goto V_41;
}
V_16 -> V_38 = V_34 ;
V_41:
if ( ! V_16 -> V_38 )
F_23 ( V_39 , & V_2 -> V_5 ) ;
F_21 () ;
return V_12 ;
}
if ( V_12 != sizeof( T_4 ) )
return V_42 ;
memcpy ( & V_25 , V_11 , sizeof( T_4 ) ) ;
V_30 = F_11 ( V_2 , V_25 , & V_32 , & V_33 ) ;
if ( V_30 )
return V_30 ;
if ( V_2 -> V_16 -> V_38 == V_32 )
return V_12 ;
F_19 () ;
if ( ! V_2 -> V_16 -> V_38 )
if ( F_20 ( V_39 , & V_2 -> V_5 ) ) {
F_21 () ;
return - V_40 ;
}
if ( F_5 ( V_37 , & V_2 -> V_5 ) ) {
V_30 = - V_43 ;
goto V_44;
}
if ( ! F_5 ( V_20 , & V_2 -> V_5 ) ) {
V_30 = F_24 ( V_2 -> V_45 , V_46 ) ;
if ( V_30 )
goto V_44;
F_25 ( V_47 , & V_2 -> V_5 ) ;
}
V_30 = F_26 ( V_2 , V_32 , V_33 ) ;
if ( ! V_30 ) {
V_30 = V_12 ;
V_16 -> V_38 = V_32 ;
}
if ( F_27 ( V_47 , & V_2 -> V_5 ) )
F_28 ( V_2 -> V_45 , V_31 ) ;
V_44:
if ( ! V_2 -> V_16 -> V_38 )
F_23 ( V_39 , & V_2 -> V_5 ) ;
F_21 () ;
return V_30 ;
}
static T_2 F_29 ( struct V_7 * V_8 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
return sprintf ( V_11 , L_1 , V_2 -> V_16 -> V_38 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
T_6 V_48 , T_3 V_49 )
{
T_3 V_50 = 4 ;
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_43 ;
if ( V_48 < V_51 ) {
if ( F_31 ( V_48 , V_52 ,
V_53 ) )
V_50 = 8 ;
else
return - V_15 ;
}
if ( ( V_49 != V_50 ) || ( V_48 & ( V_50 - 1 ) ) )
return - V_15 ;
return 0 ;
}
static T_2 F_32 ( struct V_54 * V_55 , struct V_56 * V_57 ,
struct V_58 * V_10 , char * V_11 ,
T_6 V_48 , T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_30 ( V_2 , V_48 , V_49 ) ;
if ( V_14 != 0 )
return V_14 ;
F_34 ( V_2 , V_11 , V_48 , V_49 ) ;
return V_49 ;
}
static T_2 F_35 ( struct V_54 * V_55 , struct V_56 * V_57 ,
struct V_58 * V_10 , char * V_11 ,
T_6 V_48 , T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
V_14 = F_30 ( V_2 , V_48 , V_49 ) ;
if ( V_14 != 0 )
return V_14 ;
F_36 ( V_2 , V_11 , V_48 , V_49 ) ;
return V_49 ;
}
static int F_37 ( struct V_1 * V_2 ,
T_6 V_48 , T_3 V_49 )
{
if ( ! ( V_2 -> V_22 & V_24 ) )
return - V_43 ;
if ( ( V_49 != 8 ) || ( V_48 & 0x7 ) )
return - V_43 ;
return 0 ;
}
static T_2 F_38 ( struct V_54 * V_55 , struct V_56 * V_57 ,
struct V_58 * V_10 , char * V_11 ,
T_6 V_48 , T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_59 ;
int V_14 ;
V_14 = F_37 ( V_2 , V_48 , V_49 ) ;
if ( V_14 != 0 )
return V_14 ;
if ( F_39 ( V_2 , V_48 , & V_59 ) )
return - V_43 ;
memcpy ( V_11 , & V_59 , V_49 ) ;
return V_49 ;
}
static T_2 F_40 ( struct V_54 * V_55 , struct V_56 * V_57 ,
struct V_58 * V_10 , char * V_11 ,
T_6 V_48 , T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
T_7 V_59 ;
int V_14 ;
V_14 = F_37 ( V_2 , V_48 , V_49 ) ;
if ( V_14 != 0 )
return V_14 ;
memcpy ( & V_59 , V_11 , V_49 ) ;
if ( F_41 ( V_2 , V_48 , V_59 ) )
return - V_43 ;
return V_49 ;
}
static int F_42 ( struct V_1 * V_2 , T_5 V_60 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_2 -> V_16 -> V_62 ; V_61 ++ ) {
if ( V_2 -> V_63 [ V_61 ] . V_60 == V_60 )
return V_61 ;
}
return - 1 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_64 * V_65 , int V_66 )
{
T_5 V_67 , V_68 , V_69 ;
T_5 V_70 ;
int V_61 , V_71 , V_72 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
V_67 = V_65 [ V_61 ] . V_60 ;
V_70 = V_65 [ V_61 ] . V_73 ;
V_71 = F_42 ( V_2 , V_67 ) ;
if ( V_71 < 0 )
return V_42 ;
V_72 = F_42 ( V_2 , V_70 ) ;
if ( V_72 < 0 )
return V_42 ;
V_68 = V_2 -> V_63 [ V_71 ] . V_74 ;
V_69 = V_2 -> V_63 [ V_72 ] . V_74 ;
if ( V_68 != V_69 )
return V_42 ;
}
return 0 ;
}
static T_2 F_44 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_64 * V_65 ;
T_1 V_75 , V_76 , V_60 ;
int V_66 , V_77 , V_61 , V_14 , V_78 ;
V_66 = V_49 / sizeof( struct V_64 ) ;
V_77 = V_49 % sizeof( struct V_64 ) ;
if ( V_77 )
return V_42 ;
V_65 = (struct V_64 * ) V_11 ;
V_14 = F_43 ( V_2 , V_65 , V_66 ) ;
if ( V_14 )
return V_14 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
V_60 = V_65 [ V_61 ] . V_60 ;
V_76 = ! ! V_65 [ V_61 ] . V_76 ;
V_78 = F_42 ( V_2 , V_60 ) ;
if ( V_78 < 0 )
return V_42 ;
V_75 = V_2 -> V_63 [ V_78 ] . V_74 ;
V_14 = F_45 ( V_2 , V_75 ,
V_76 , V_60 ) ;
if ( V_14 )
return V_14 ;
}
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
V_60 = V_65 [ V_61 ] . V_60 ;
V_78 = F_42 ( V_2 , V_60 ) ;
V_75 = V_2 -> V_63 [ V_78 ] . V_74 ;
V_2 -> V_63 [ V_78 ] . V_79 = ! ! V_65 [ V_61 ] . V_76 ;
V_2 -> V_63 [ V_78 ] . V_73 = V_75 ;
}
return V_49 ;
}
static T_2 F_46 ( struct V_54 * V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_64 V_65 [ V_80 ] ;
int V_61 ;
T_5 V_60 ;
if ( V_49 != sizeof( V_65 ) )
return V_42 ;
memset ( & V_65 , 0 ,
sizeof( struct V_64 ) * V_80 ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_16 -> V_62 ; V_61 ++ ) {
V_60 = V_2 -> V_63 [ V_61 ] . V_60 ;
V_65 [ V_60 ] . V_76 = V_2 -> V_63 [ V_61 ] . V_79 ;
V_65 [ V_60 ] . V_73 = 0 ;
V_65 [ V_60 ] . V_60 = V_61 ;
}
memcpy ( V_11 , & V_65 , V_49 ) ;
return V_49 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_81 * V_82 , int V_66 )
{
T_1 V_35 ;
T_5 V_60 ;
int V_61 , V_14 ;
if ( F_48 ( V_2 ) )
V_35 = F_49 ( V_2 -> V_16 -> V_83 + V_84 ) ;
else
V_35 = F_50 ( V_2 -> V_16 , V_85 ) ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
V_60 = V_82 [ V_61 ] . V_60 ;
if ( V_60 >= V_80 )
return V_42 ;
if ( V_2 -> V_16 -> V_35 == V_86 )
if ( F_42 ( V_2 , V_60 ) < 0 )
return V_42 ;
switch ( V_82 [ V_61 ] . V_35 ) {
case V_87 :
if ( F_48 ( V_2 ) ) {
V_14 = F_51 ( V_35 , V_60 ) ;
} else {
V_14 = F_52 ( V_35 ,
V_60 ) ;
V_82 [ V_61 ] . V_88 = 0 ;
}
if ( V_14 != V_36 ) {
if ( V_82 [ V_61 ] . V_89 != 0 )
return V_42 ;
if ( V_82 [ V_61 ] . V_90 != 1 )
return V_42 ;
if ( V_82 [ V_61 ] . V_91 != 1 )
return V_42 ;
}
break;
case V_92 :
if ( ! F_53 ( V_82 [ V_61 ] . V_93 ) )
return V_42 ;
if ( ! V_82 [ V_61 ] . V_94 )
return V_42 ;
break;
case V_95 :
if ( ! V_82 [ V_61 ] . V_94 )
return V_42 ;
break;
default:
return V_42 ;
}
}
return 0 ;
}
static T_2 F_54 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_81 * V_82 ;
struct V_96 * V_97 ;
int V_66 , V_77 , V_61 , V_14 ;
int V_78 ;
T_5 V_35 = 0 , V_60 ;
V_66 = V_49 / sizeof( struct V_81 ) ;
V_77 = V_49 % sizeof( struct V_81 ) ;
if ( V_77 )
return V_42 ;
V_82 = (struct V_81 * ) V_11 ;
V_14 = F_47 ( V_2 , V_82 , V_66 ) ;
if ( V_14 )
return V_14 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
if ( V_2 -> V_16 -> V_35 == V_86 )
if ( F_55 ( V_2 , & V_82 [ V_61 ] ) )
return V_42 ;
if ( V_2 -> V_16 -> V_60 != V_82 [ V_61 ] . V_60 )
continue;
V_35 = V_82 [ V_61 ] . V_35 ;
F_56 ( V_2 , & V_82 [ V_61 ] ) ;
V_82 [ V_61 ] . V_35 = V_35 ;
V_82 [ V_61 ] . V_60 = V_2 -> V_16 -> V_60 ;
switch ( V_82 [ V_61 ] . V_35 ) {
case V_87 :
F_57 ( V_2 , & V_82 [ V_61 ] ) ;
break;
case V_92 :
F_58 ( V_2 , & V_82 [ V_61 ] ) ;
break;
case V_95 :
V_82 [ V_61 ] . V_93 = 0 ;
F_58 ( V_2 , & V_82 [ V_61 ] ) ;
break;
}
}
if ( V_2 -> V_16 -> V_35 != V_86 )
goto V_44;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
V_60 = V_82 [ V_61 ] . V_60 ;
V_78 = F_42 ( V_2 , V_60 ) ;
V_97 = & V_2 -> V_63 [ V_78 ] ;
switch ( V_82 [ V_61 ] . V_35 ) {
case V_87 :
V_97 -> V_91 = V_82 [ V_61 ] . V_91 ;
V_97 -> V_90 = V_82 [ V_61 ] . V_90 ;
V_97 -> V_88 = V_82 [ V_61 ] . V_88 ;
V_97 -> V_89 = V_82 [ V_61 ] . V_89 ;
V_97 -> V_98 = V_82 [ V_61 ] . V_98 ;
break;
case V_92 :
V_97 -> V_99 = V_82 [ V_61 ] . V_93 ;
break;
case V_95 :
V_97 -> V_99 = 0 ;
break;
}
}
V_44:
return V_49 ;
}
static T_2 F_59 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_81 V_82 [ V_80 ] ;
T_5 V_61 , V_60 ;
if ( V_49 != sizeof( V_82 ) )
return V_42 ;
memset ( & V_82 , 0 ,
sizeof( struct V_81 ) * V_80 ) ;
for ( V_61 = 0 ; V_61 < V_2 -> V_16 -> V_62 ; V_61 ++ ) {
V_60 = V_2 -> V_63 [ V_61 ] . V_60 ;
V_82 [ V_60 ] . V_60 = V_60 ;
if ( F_56 ( V_2 , & V_82 [ V_60 ] ) )
return V_42 ;
}
memcpy ( V_11 , & V_82 , V_49 ) ;
return V_49 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_100 * V_101 ,
int V_66 )
{
T_5 V_60 , V_61 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
V_60 = V_101 [ V_61 ] . V_60 ;
if ( F_42 ( V_2 , V_60 ) < 0 )
return V_42 ;
if ( ! F_61 ( V_101 [ V_61 ] . V_102 ) ||
! F_61 ( V_101 [ V_61 ] . V_103 ) )
return V_42 ;
}
return 0 ;
}
static T_2 F_62 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_104 V_105 ;
struct V_100 * V_101 ;
int V_61 , V_66 , V_77 , V_14 , V_78 ;
T_5 V_60 ;
V_66 = V_49 / sizeof( struct V_100 ) ;
V_77 = V_49 % sizeof( struct V_100 ) ;
if ( V_77 )
return V_42 ;
V_101 = (struct V_100 * ) V_11 ;
V_14 = F_60 ( V_2 , V_101 , V_66 ) ;
if ( V_14 )
return V_14 ;
for ( V_61 = 0 ; V_61 < V_66 ; V_61 ++ ) {
V_60 = V_101 [ V_61 ] . V_60 ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
V_14 = F_63 ( V_2 , & V_105 , V_60 ) ;
if ( V_14 )
return V_14 ;
V_105 . V_60 = V_60 ;
V_105 . V_106 = V_101 [ V_61 ] . V_102 ;
V_105 . V_107 = V_101 [ V_61 ] . V_103 ;
V_14 = F_64 ( V_2 , & V_105 ) ;
if ( V_14 )
return V_14 ;
V_78 = F_42 ( V_2 , V_60 ) ;
V_2 -> V_63 [ V_78 ] . V_102 = V_105 . V_106 ;
V_2 -> V_63 [ V_78 ] . V_103 = V_105 . V_107 ;
}
return V_49 ;
}
static T_2 F_65 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_104 V_105 ;
struct V_100 V_101 [ V_80 ] ;
int V_61 , V_14 ;
if ( V_49 != sizeof( V_101 ) )
return V_42 ;
memset ( & V_105 , 0 , sizeof( struct V_104 ) ) ;
memset ( & V_101 , 0 ,
sizeof( struct V_100 ) * V_80 ) ;
for ( V_61 = 0 ; V_61 < V_80 ; V_61 ++ ) {
if ( F_42 ( V_2 , V_61 ) < 0 )
continue;
V_14 = F_63 ( V_2 , & V_105 , V_61 ) ;
if ( V_14 )
return V_14 ;
V_101 [ V_61 ] . V_60 = V_61 ;
V_101 [ V_61 ] . V_35 = ( T_5 ) V_105 . V_35 ;
V_101 [ V_61 ] . V_108 = V_105 . V_109 ;
V_101 [ V_61 ] . V_110 = V_105 . V_17 ;
V_101 [ V_61 ] . V_102 = V_105 . V_106 ;
V_101 [ V_61 ] . V_103 = V_105 . V_107 ;
V_101 [ V_61 ] . V_111 = V_105 . V_112 ;
V_101 [ V_61 ] . V_113 = V_105 . V_114 ;
}
memcpy ( V_11 , & V_101 , V_49 ) ;
return V_49 ;
}
static T_2 F_66 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_115 V_116 ;
int V_14 ;
if ( F_17 ( V_2 ) )
return V_117 ;
if ( V_49 != sizeof( struct V_115 ) )
return V_42 ;
if ( V_48 >= V_80 )
return V_42 ;
memset ( & V_116 , 0 , V_49 ) ;
V_14 = F_67 ( V_2 , V_48 , V_118 ,
& V_116 . V_119 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_67 ( V_2 , V_48 , V_120 ,
& V_116 . V_121 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_116 , V_49 ) ;
return V_49 ;
}
static T_2 F_68 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_115 V_122 ;
int V_14 ;
if ( F_17 ( V_2 ) )
return V_117 ;
if ( V_49 != sizeof( struct V_115 ) )
return V_42 ;
if ( V_48 >= V_123 )
return V_42 ;
memset ( & V_122 , 0 , V_49 ) ;
V_14 = F_69 ( V_2 , V_48 , V_118 ,
& V_122 . V_119 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( V_2 , V_48 , V_120 ,
& V_122 . V_121 ) ;
if ( V_14 )
return V_14 ;
memcpy ( V_11 , & V_122 , V_49 ) ;
return V_49 ;
}
static T_2 F_70 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_17 ( V_2 ) )
return V_117 ;
if ( V_48 >= V_123 )
return V_42 ;
V_14 = F_71 ( V_2 , V_124 , V_48 ,
V_118 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_71 ( V_2 , V_124 , V_48 ,
V_120 ) ;
if ( V_14 )
return V_14 ;
return V_49 ;
}
static T_2 F_72 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
int V_14 ;
if ( F_17 ( V_2 ) )
return V_117 ;
if ( V_48 >= V_80 )
return V_42 ;
V_14 = F_71 ( V_2 , V_125 , V_48 ,
V_118 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_71 ( V_2 , V_125 , V_48 ,
V_120 ) ;
if ( V_14 )
return V_14 ;
return V_49 ;
}
static T_2 F_73 ( struct V_54 * V_54 ,
struct V_56 * V_57 ,
struct V_58 * V_10 ,
char * V_11 , T_6 V_48 ,
T_3 V_49 )
{
struct V_7 * V_8 = F_33 ( V_57 , struct V_7 , V_57 ) ;
struct V_1 * V_2 = F_4 ( V_8 ) ;
struct V_126 V_127 [ V_80 ] ;
struct V_128 * V_129 ;
int V_61 , V_14 ;
if ( V_49 != sizeof( V_127 ) )
return V_42 ;
V_129 = F_74 ( V_80 , sizeof( * V_129 ) , V_130 ) ;
if ( ! V_129 )
return - V_131 ;
V_14 = F_75 ( V_2 , V_129 ) ;
if ( V_14 ) {
F_76 ( V_129 ) ;
return V_14 ;
}
memset ( & V_127 , 0 ,
sizeof( struct V_126 ) * V_80 ) ;
for ( V_61 = 0 ; V_61 < V_80 ; V_61 ++ ) {
V_127 [ V_61 ] . V_60 = V_129 [ V_61 ] . V_75 ;
V_127 [ V_61 ] . V_132 = V_129 [ V_61 ] . type ;
V_127 [ V_61 ] . V_108 = V_129 [ V_61 ] . V_133 ;
V_127 [ V_61 ] . V_102 = V_129 [ V_61 ] . V_134 ;
V_127 [ V_61 ] . V_103 = V_129 [ V_61 ] . V_135 ;
memcpy ( & V_127 [ V_61 ] . V_136 , & V_129 [ V_61 ] . V_137 , V_138 ) ;
}
memcpy ( V_11 , & V_127 , V_49 ) ;
F_76 ( V_129 ) ;
return V_49 ;
}
void F_77 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_139 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
if ( F_78 ( V_8 , & V_140 ) )
F_16 ( V_8 ,
L_4 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_139 -> V_8 ;
if ( V_2 -> V_16 -> V_17 & V_18 )
F_80 ( V_8 , & V_140 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_139 -> V_8 ;
if ( F_82 ( V_8 , & V_141 ) )
F_83 ( V_8 , L_5 ) ;
if ( V_2 -> V_16 -> V_35 == V_36 )
return;
if ( F_78 ( V_8 , & V_142 ) )
F_83 ( V_8 , L_6 ) ;
if ( F_82 ( V_8 , & V_143 ) )
F_83 ( V_8 , L_7 ) ;
if ( F_82 ( V_8 , & V_144 ) )
F_83 ( V_8 , L_8 ) ;
if ( F_82 ( V_8 , & V_145 ) )
F_83 ( V_8 , L_9 ) ;
if ( F_78 ( V_8 , & V_146 ) )
F_83 ( V_8 , L_10 ) ;
if ( ! ( V_2 -> V_22 & V_147 ) )
return;
if ( F_82 ( V_8 , & V_148 ) )
F_83 ( V_8 , L_11 ) ;
if ( V_2 -> V_16 -> V_35 != V_86 )
return;
if ( F_82 ( V_8 , & V_149 ) )
F_83 ( V_8 , L_12 ) ;
if ( F_82 ( V_8 , & V_150 ) )
F_83 ( V_8 , L_13 ) ;
if ( F_82 ( V_8 , & V_151 ) )
F_83 ( V_8 , L_14 ) ;
}
void F_84 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = & V_2 -> V_139 -> V_8 ;
F_85 ( V_8 , & V_141 ) ;
if ( V_2 -> V_16 -> V_35 == V_36 )
return;
F_80 ( V_8 , & V_142 ) ;
F_85 ( V_8 , & V_143 ) ;
F_85 ( V_8 , & V_144 ) ;
F_85 ( V_8 , & V_145 ) ;
F_80 ( V_8 , & V_146 ) ;
if ( ! ( V_2 -> V_22 & V_147 ) )
return;
F_85 ( V_8 , & V_148 ) ;
if ( V_2 -> V_16 -> V_35 != V_86 )
return;
F_85 ( V_8 , & V_149 ) ;
F_85 ( V_8 , & V_150 ) ;
F_85 ( V_8 , & V_151 ) ;
}
void F_86 ( struct V_1 * V_2 )
{
F_81 ( V_2 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
F_84 ( V_2 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
F_81 ( V_2 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
F_84 ( V_2 ) ;
}

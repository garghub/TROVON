static int F_1 ( void )
{
return V_1 || V_2 ;
}
static int F_2 ( struct V_3 * V_4 )
{
unsigned long long V_5 ;
T_1 V_6 ;
V_6 = F_3 ( V_4 -> V_7 -> V_8 , L_1 ,
NULL , & V_5 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_2 ) ) ;
return - V_10 ;
}
V_4 -> V_11 = V_5 ;
return 0 ;
}
static T_2 F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
F_8 ( & V_4 -> V_19 ) ;
F_2 ( V_4 ) ;
F_9 ( & V_4 -> V_19 ) ;
return sprintf ( V_16 , L_3 , V_4 -> V_11 ) ;
}
static T_2 F_10 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_3 V_20 )
{
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
union V_21 V_22 = { V_23 } ;
struct V_24 args = { 1 , & V_22 } ;
int V_25 ;
unsigned long V_26 ;
unsigned long long V_5 ;
T_1 V_6 ;
V_25 = F_11 ( V_16 , 10 , & V_26 ) ;
if ( V_25 )
return V_25 ;
if ( V_26 > V_4 -> V_27 . V_28 ||
V_26 < V_4 -> V_27 . V_29 )
return - V_30 ;
V_22 . integer . V_31 = V_26 ;
F_8 ( & V_4 -> V_19 ) ;
V_6 = F_3 ( V_4 -> V_7 -> V_8 , L_4 ,
& args , & V_5 ) ;
if ( ! F_4 ( V_6 ) )
V_4 -> V_11 = V_26 ;
F_9 ( & V_4 -> V_19 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_5 ) ) ;
return - V_30 ;
}
if ( V_5 )
return - V_30 ;
return V_20 ;
}
static int F_12 ( struct V_3 * V_4 )
{
unsigned long long V_5 ;
T_1 V_6 ;
V_6 = F_3 ( V_4 -> V_7 -> V_8 , L_6 ,
NULL , & V_5 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_7 ) ) ;
return - V_10 ;
}
V_4 -> V_32 = V_5 ;
return 0 ;
}
static T_2 F_13 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
F_8 ( & V_4 -> V_19 ) ;
F_12 ( V_4 ) ;
F_9 ( & V_4 -> V_19 ) ;
return sprintf ( V_16 , L_3 , V_4 -> V_32 * 1000 ) ;
}
static T_2 F_14 ( struct V_12 * V_13 , struct V_14 * V_15 ,
const char * V_16 , T_3 V_20 )
{
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
union V_21 V_22 = { V_23 } ;
struct V_24 args = { 1 , & V_22 } ;
int V_25 ;
unsigned long V_26 ;
unsigned long long V_5 ;
T_1 V_6 ;
V_25 = F_11 ( V_16 , 10 , & V_26 ) ;
if ( V_25 )
return V_25 ;
V_26 /= 1000 ;
if ( V_26 > V_4 -> V_27 . V_33 || V_26 < V_4 -> V_27 . V_34 )
return - V_30 ;
V_22 . integer . V_31 = V_26 ;
F_8 ( & V_4 -> V_19 ) ;
V_6 = F_3 ( V_4 -> V_7 -> V_8 , L_8 ,
& args , & V_5 ) ;
if ( ! F_4 ( V_6 ) )
V_4 -> V_32 = V_26 ;
F_9 ( & V_4 -> V_19 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_9 ) ) ;
return - V_30 ;
}
if ( V_5 )
return - V_30 ;
return V_20 ;
}
static int F_15 ( struct V_3 * V_4 )
{
union V_21 V_35 [] = {
{ V_23 } ,
{ V_23 }
} ;
struct V_24 args = { 2 , V_35 } ;
unsigned long long V_5 ;
T_1 V_6 ;
if ( V_4 -> V_36 [ 0 ] < 0 || V_4 -> V_36 [ 1 ] < 0 )
return 0 ;
V_35 [ 0 ] . integer . V_31 = V_4 -> V_36 [ 1 ] ;
V_35 [ 1 ] . integer . V_31 = V_4 -> V_36 [ 0 ] ;
V_6 = F_3 ( V_4 -> V_7 -> V_8 , L_10 ,
& args , & V_5 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_11 ) ) ;
return - V_30 ;
}
if ( V_5 )
return - V_30 ;
return 0 ;
}
static T_2 F_16 ( struct V_12 * V_13 , struct V_14 * V_15 ,
const char * V_16 , T_3 V_20 )
{
struct V_37 * V_38 = F_17 ( V_15 ) ;
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
int V_25 ;
unsigned long V_26 ;
V_25 = F_11 ( V_16 , 10 , & V_26 ) ;
if ( V_25 )
return V_25 ;
V_26 /= 1000 ;
if ( V_26 < 0 )
return - V_30 ;
F_8 ( & V_4 -> V_19 ) ;
V_4 -> V_36 [ V_38 -> V_39 - 7 ] = V_26 ;
V_25 = F_15 ( V_4 ) ;
F_9 ( & V_4 -> V_19 ) ;
if ( V_25 )
return V_25 ;
return V_20 ;
}
static int F_18 ( struct V_3 * V_4 )
{
unsigned long long V_5 ;
T_1 V_6 ;
unsigned long V_40 = V_41 ;
if ( F_19 ( V_40 , V_4 -> V_42 +
F_20 ( V_4 -> V_27 . V_43 ) ) &&
V_4 -> V_44 )
return 0 ;
V_6 = F_3 ( V_4 -> V_7 -> V_8 , L_12 ,
NULL , & V_5 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_13 ) ) ;
return - V_10 ;
}
V_4 -> V_45 = V_5 ;
V_4 -> V_44 = 1 ;
V_4 -> V_42 = V_41 ;
return 0 ;
}
static T_2 F_21 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
F_8 ( & V_4 -> V_19 ) ;
F_18 ( V_4 ) ;
F_9 ( & V_4 -> V_19 ) ;
return sprintf ( V_16 , L_3 , V_4 -> V_45 * 1000 ) ;
}
static T_2 F_22 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_37 * V_38 = F_17 ( V_15 ) ;
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
T_4 V_46 ;
switch ( V_38 -> V_39 ) {
case 0 :
V_46 = V_4 -> V_47 ;
break;
case 1 :
V_46 = V_4 -> V_48 ;
break;
case 2 :
V_46 = V_4 -> V_49 ;
break;
default:
F_23 () ;
}
return sprintf ( V_16 , L_14 , V_46 ) ;
}
static T_2 F_24 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_37 * V_38 = F_17 ( V_15 ) ;
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
T_5 V_46 = 0 ;
switch ( V_38 -> V_39 ) {
case 0 :
V_46 = V_4 -> V_27 . V_29 ;
break;
case 1 :
V_46 = V_4 -> V_27 . V_28 ;
break;
case 2 :
V_46 = V_4 -> V_27 . V_34 * 1000 ;
break;
case 3 :
V_46 = V_4 -> V_27 . V_33 * 1000 ;
break;
case 4 :
if ( V_4 -> V_27 . V_50 == V_51 )
return sprintf ( V_16 , L_15 ) ;
V_46 = V_4 -> V_27 . V_50 * 1000 ;
break;
case 5 :
if ( V_4 -> V_27 . V_52 & V_53 )
V_46 = 1 ;
else
V_46 = 0 ;
break;
case 6 :
if ( V_4 -> V_45 > V_4 -> V_32 )
V_46 = 1 ;
else
V_46 = 0 ;
break;
case 7 :
case 8 :
if ( V_4 -> V_36 [ V_38 -> V_39 - 7 ] < 0 )
return sprintf ( V_16 , L_15 ) ;
V_46 = V_4 -> V_36 [ V_38 -> V_39 - 7 ] * 1000 ;
break;
default:
F_23 () ;
}
return sprintf ( V_16 , L_3 , V_46 ) ;
}
static T_2 F_25 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
unsigned int V_54 = V_4 -> V_27 . V_55 ;
return sprintf ( V_16 , L_16 , V_54 / 1000 , V_54 % 1000 ) ;
}
static T_2 F_26 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
return sprintf ( V_16 , L_14 , V_56 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
int V_57 ;
if ( ! V_4 -> V_58 )
return;
for ( V_57 = 0 ; V_57 < V_4 -> V_58 ; V_57 ++ ) {
struct V_17 * V_59 = V_4 -> V_60 [ V_57 ] ;
if ( ! V_59 )
continue;
F_28 ( V_4 -> V_61 ,
F_29 ( & V_59 -> V_13 . V_62 ) ) ;
F_30 ( & V_59 -> V_13 ) ;
}
F_31 ( V_4 -> V_60 ) ;
F_32 ( V_4 -> V_61 ) ;
V_4 -> V_58 = 0 ;
}
static int F_33 ( struct V_3 * V_4 )
{
int V_25 = 0 ;
int V_57 ;
struct V_63 V_64 = { V_65 , NULL } ;
union V_21 * V_66 ;
T_1 V_6 ;
V_6 = F_34 ( V_4 -> V_7 -> V_8 , L_17 , NULL ,
& V_64 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_18 ) ) ;
return - V_10 ;
}
V_66 = V_64 . V_67 ;
if ( ! V_66 ||
V_66 -> type != V_68 ) {
F_35 ( & V_4 -> V_7 -> V_13 , V_56
L_19 ) ;
V_25 = - V_69 ;
goto V_70;
}
if ( ! V_66 -> V_71 . V_20 )
goto V_70;
V_4 -> V_60 = F_36 ( sizeof( struct V_17 * ) *
V_66 -> V_71 . V_20 , V_72 ) ;
if ( ! V_4 -> V_60 ) {
V_25 = - V_73 ;
goto V_70;
}
V_4 -> V_61 = F_37 ( L_20 ,
& V_4 -> V_7 -> V_13 . V_62 ) ;
if ( ! V_4 -> V_61 ) {
V_25 = - V_73 ;
goto V_74;
}
V_4 -> V_58 = V_66 -> V_71 . V_20 ;
for ( V_57 = 0 ; V_57 < V_66 -> V_71 . V_20 ; V_57 ++ ) {
struct V_17 * V_59 ;
union V_21 * V_75 = & ( V_66 -> V_71 . V_76 [ V_57 ] ) ;
if ( V_75 -> type != V_77 )
continue;
V_4 -> V_60 [ V_57 ] = NULL ;
V_6 = F_38 ( V_75 -> V_78 . V_8 ,
& V_4 -> V_60 [ V_57 ] ) ;
if ( F_4 ( V_6 ) )
continue;
V_59 = V_4 -> V_60 [ V_57 ] ;
F_39 ( & V_59 -> V_13 ) ;
V_25 = F_40 ( V_4 -> V_61 , & V_59 -> V_13 . V_62 ,
F_29 ( & V_59 -> V_13 . V_62 ) ) ;
if ( V_25 ) {
F_30 ( & V_59 -> V_13 ) ;
V_4 -> V_60 [ V_57 ] = NULL ;
}
}
V_25 = 0 ;
goto V_70;
V_74:
F_31 ( V_4 -> V_60 ) ;
V_70:
F_31 ( V_64 . V_67 ) ;
return V_25 ;
}
static int F_41 ( struct V_3 * V_4 ,
struct V_79 * V_80 )
{
struct V_12 * V_13 = & V_4 -> V_7 -> V_13 ;
struct V_37 * V_81 =
& V_4 -> V_81 [ V_4 -> V_82 ] ;
int V_25 = 0 ;
while ( V_80 -> V_83 ) {
V_81 -> V_84 . V_38 . V_85 = V_80 -> V_83 ;
V_81 -> V_84 . V_38 . V_86 = V_87 ;
V_81 -> V_84 . V_88 = V_80 -> V_88 ;
V_81 -> V_39 = V_80 -> V_39 ;
V_25 = F_42 ( V_13 , & V_81 -> V_84 ) ;
if ( V_25 ) {
V_81 -> V_84 . V_38 . V_85 = NULL ;
goto error;
}
V_81 ++ ;
V_4 -> V_82 ++ ;
V_80 ++ ;
}
error:
return V_25 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_89 * V_90 )
{
struct V_12 * V_13 = & V_4 -> V_7 -> V_13 ;
struct V_37 * V_81 =
& V_4 -> V_81 [ V_4 -> V_82 ] ;
int V_25 = 0 ;
while ( V_90 -> V_83 ) {
V_81 -> V_84 . V_38 . V_85 = V_90 -> V_83 ;
V_81 -> V_84 . V_38 . V_86 = V_87 | V_91 ;
V_81 -> V_84 . V_88 = V_90 -> V_88 ;
V_81 -> V_84 . V_92 = V_90 -> V_93 ;
V_81 -> V_39 = V_90 -> V_39 ;
V_25 = F_42 ( V_13 , & V_81 -> V_84 ) ;
if ( V_25 ) {
V_81 -> V_84 . V_38 . V_85 = NULL ;
goto error;
}
V_81 ++ ;
V_4 -> V_82 ++ ;
V_90 ++ ;
}
error:
return V_25 ;
}
static void F_44 ( struct V_3 * V_4 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_82 ; V_57 ++ ) {
if ( ! V_4 -> V_81 [ V_57 ] . V_84 . V_38 . V_85 )
continue;
F_45 ( & V_4 -> V_7 -> V_13 ,
& V_4 -> V_81 [ V_57 ] . V_84 ) ;
}
F_27 ( V_4 ) ;
V_4 -> V_82 = 0 ;
}
static int F_46 ( struct V_3 * V_4 )
{
int V_25 = 0 ;
V_25 = F_33 ( V_4 ) ;
if ( V_25 )
return V_25 ;
if ( V_4 -> V_27 . V_52 & V_94 ) {
V_25 = F_41 ( V_4 , V_95 ) ;
if ( V_25 )
goto error;
V_25 = F_43 ( V_4 , V_96 ) ;
if ( V_25 )
goto error;
}
if ( V_4 -> V_27 . V_52 & V_97 ) {
if ( ! F_1 () ) {
F_35 ( & V_4 -> V_7 -> V_13 ,
L_21 ) ;
goto V_98;
}
if ( V_4 -> V_27 . V_99 ) {
V_25 = F_43 ( V_4 , V_100 ) ;
if ( V_25 )
goto error;
} else {
V_25 = F_41 ( V_4 , V_101 ) ;
if ( V_25 )
goto error;
}
V_25 = F_41 ( V_4 , V_102 ) ;
if ( V_25 )
goto error;
}
V_98:
if ( V_4 -> V_27 . V_52 & V_103 ) {
V_25 = F_43 ( V_4 , V_104 ) ;
if ( V_25 )
goto error;
}
V_25 = F_41 ( V_4 , V_105 ) ;
if ( V_25 )
goto error;
return V_25 ;
error:
F_44 ( V_4 ) ;
return V_25 ;
}
static void F_47 ( struct V_3 * V_4 )
{
T_4 * V_106 ;
int V_57 ;
V_106 = & V_4 -> V_47 ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ , V_106 ++ )
F_31 ( * V_106 ) ;
}
static int F_48 ( struct V_3 * V_4 )
{
int V_25 = 0 ;
int V_57 ;
struct V_63 V_64 = { V_65 , NULL } ;
struct V_63 V_107 = { 0 , NULL } ;
struct V_63 V_108 = { sizeof( L_22 ) , L_22 } ;
union V_21 * V_66 ;
T_4 * V_106 ;
T_1 V_6 ;
V_6 = F_34 ( V_4 -> V_7 -> V_8 , L_23 , NULL ,
& V_64 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_24 ) ) ;
return - V_10 ;
}
V_66 = V_64 . V_67 ;
if ( ! V_66 ||
V_66 -> type != V_68 ||
V_66 -> V_71 . V_20 != 14 ) {
F_35 ( & V_4 -> V_7 -> V_13 , V_56
L_25 ) ;
V_25 = - V_69 ;
goto V_70;
}
V_107 . V_109 = sizeof( struct V_110 ) ;
V_107 . V_67 = & V_4 -> V_27 ;
V_6 = F_49 ( V_66 , & V_108 , & V_107 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_26 ) ) ;
V_25 = - V_69 ;
goto V_70;
}
if ( V_4 -> V_27 . V_111 ) {
F_35 ( & V_4 -> V_7 -> V_13 , V_56
L_27 ,
V_4 -> V_27 . V_111 ) ;
V_25 = - V_30 ;
goto V_70;
}
V_106 = & V_4 -> V_47 ;
for ( V_57 = 11 ; V_57 < 14 ; V_57 ++ ) {
union V_21 * V_75 = & ( V_66 -> V_71 . V_76 [ V_57 ] ) ;
if ( V_75 -> type != V_112 ) {
V_25 = - V_30 ;
goto error;
}
* V_106 = F_36 ( sizeof( V_113 ) * ( V_75 -> string . V_109 + 1 ) ,
V_72 ) ;
if ( ! * V_106 ) {
V_25 = - V_73 ;
goto error;
}
strncpy ( * V_106 , V_75 -> string . V_67 , V_75 -> string . V_109 ) ;
V_106 ++ ;
}
F_50 ( & V_4 -> V_7 -> V_13 , L_28 ) ;
goto V_70;
error:
V_106 = & V_4 -> V_47 ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ , V_106 ++ )
F_31 ( * V_106 ) ;
V_70:
F_31 ( V_64 . V_67 ) ;
return V_25 ;
}
static void F_51 ( struct V_17 * V_12 , T_6 V_114 )
{
struct V_3 * V_4 ;
int V_25 ;
if ( ! V_12 || ! F_52 ( V_12 ) )
return;
V_4 = F_52 ( V_12 ) ;
F_8 ( & V_4 -> V_19 ) ;
switch ( V_114 ) {
case V_115 :
F_47 ( V_4 ) ;
V_25 = F_48 ( V_4 ) ;
if ( V_25 )
break;
F_44 ( V_4 ) ;
F_46 ( V_4 ) ;
break;
case V_116 :
F_53 ( & V_12 -> V_13 . V_62 , NULL , V_117 ) ;
F_18 ( V_4 ) ;
break;
case V_118 :
F_53 ( & V_12 -> V_13 . V_62 , NULL , V_119 ) ;
F_12 ( V_4 ) ;
break;
case V_120 :
F_53 ( & V_12 -> V_13 . V_62 , NULL , V_121 ) ;
F_2 ( V_4 ) ;
break;
case V_122 :
F_53 ( & V_12 -> V_13 . V_62 , NULL , V_123 ) ;
F_50 ( & V_12 -> V_13 , L_29 ) ;
break;
default:
F_23 () ;
}
F_9 ( & V_4 -> V_19 ) ;
F_54 ( V_124 ,
F_55 ( & V_12 -> V_13 ) , V_114 , 0 ) ;
}
static int F_56 ( struct V_17 * V_12 )
{
int V_25 ;
struct V_3 * V_4 ;
if ( ! V_12 )
return - V_30 ;
V_4 = F_36 ( sizeof( struct V_3 ) ,
V_72 ) ;
if ( ! V_4 )
return - V_73 ;
V_4 -> V_44 = 0 ;
V_4 -> V_7 = V_12 ;
F_57 ( & V_4 -> V_19 ) ;
strcpy ( F_58 ( V_12 ) , V_125 ) ;
strcpy ( F_59 ( V_12 ) , V_124 ) ;
V_12 -> V_18 = V_4 ;
F_47 ( V_4 ) ;
V_25 = F_48 ( V_4 ) ;
if ( V_25 )
goto V_74;
V_4 -> V_36 [ 0 ] = V_4 -> V_36 [ 1 ] = - 1 ;
V_25 = F_46 ( V_4 ) ;
if ( V_25 )
goto V_74;
V_4 -> V_126 = F_60 ( & V_12 -> V_13 ) ;
if ( F_61 ( V_4 -> V_126 ) ) {
V_25 = F_62 ( V_4 -> V_126 ) ;
goto V_127;
}
V_25 = 0 ;
goto exit;
V_127:
F_44 ( V_4 ) ;
V_74:
F_31 ( V_4 ) ;
exit:
return V_25 ;
}
static int F_63 ( struct V_17 * V_12 , int type )
{
struct V_3 * V_4 ;
if ( ! V_12 || ! F_52 ( V_12 ) )
return - V_30 ;
V_4 = F_52 ( V_12 ) ;
F_64 ( V_4 -> V_126 ) ;
F_47 ( V_4 ) ;
F_44 ( V_4 ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static int F_65 ( struct V_17 * V_12 )
{
struct V_3 * V_4 ;
if ( ! V_12 || ! F_52 ( V_12 ) )
return - V_30 ;
V_4 = F_52 ( V_12 ) ;
F_47 ( V_4 ) ;
F_48 ( V_4 ) ;
return 0 ;
}
static int T_7 F_66 ( const struct V_128 * V_129 )
{
V_2 = 1 ;
return 0 ;
}
static int T_7 F_67 ( void )
{
int V_130 ;
if ( V_131 )
return - V_10 ;
F_68 ( V_132 ) ;
V_130 = F_69 ( & V_133 ) ;
if ( V_130 < 0 )
return - V_10 ;
return 0 ;
}
static void T_8 F_70 ( void )
{
F_71 ( & V_133 ) ;
}

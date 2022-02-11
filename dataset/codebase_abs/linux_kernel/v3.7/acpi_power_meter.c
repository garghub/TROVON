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
V_26 = F_15 ( V_26 , 1000 ) ;
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
static int F_16 ( struct V_3 * V_4 )
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
static T_2 F_17 ( struct V_12 * V_13 , struct V_14 * V_15 ,
const char * V_16 , T_3 V_20 )
{
struct V_37 * V_38 = F_18 ( V_15 ) ;
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
int V_25 ;
unsigned long V_26 ;
V_25 = F_11 ( V_16 , 10 , & V_26 ) ;
if ( V_25 )
return V_25 ;
V_26 = F_15 ( V_26 , 1000 ) ;
F_8 ( & V_4 -> V_19 ) ;
V_4 -> V_36 [ V_38 -> V_39 - 7 ] = V_26 ;
V_25 = F_16 ( V_4 ) ;
F_9 ( & V_4 -> V_19 ) ;
if ( V_25 )
return V_25 ;
return V_20 ;
}
static int F_19 ( struct V_3 * V_4 )
{
unsigned long long V_5 ;
T_1 V_6 ;
unsigned long V_40 = V_41 ;
if ( F_20 ( V_40 , V_4 -> V_42 +
F_21 ( V_4 -> V_27 . V_43 ) ) &&
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
static T_2 F_22 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
F_8 ( & V_4 -> V_19 ) ;
F_19 ( V_4 ) ;
F_9 ( & V_4 -> V_19 ) ;
return sprintf ( V_16 , L_3 , V_4 -> V_45 * 1000 ) ;
}
static T_2 F_23 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_37 * V_38 = F_18 ( V_15 ) ;
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
F_24 () ;
V_46 = L_14 ;
}
return sprintf ( V_16 , L_15 , V_46 ) ;
}
static T_2 F_25 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_37 * V_38 = F_18 ( V_15 ) ;
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
return sprintf ( V_16 , L_16 ) ;
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
return sprintf ( V_16 , L_16 ) ;
V_46 = V_4 -> V_36 [ V_38 -> V_39 - 7 ] * 1000 ;
break;
default:
F_24 () ;
}
return sprintf ( V_16 , L_3 , V_46 ) ;
}
static T_2 F_26 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_7 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_7 -> V_18 ;
unsigned int V_54 = V_4 -> V_27 . V_55 ;
return sprintf ( V_16 , L_17 , V_54 / 1000 , V_54 % 1000 ) ;
}
static T_2 F_27 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
return sprintf ( V_16 , L_15 , V_56 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
int V_57 ;
if ( ! V_4 -> V_58 )
return;
for ( V_57 = 0 ; V_57 < V_4 -> V_58 ; V_57 ++ ) {
struct V_17 * V_59 = V_4 -> V_60 [ V_57 ] ;
if ( ! V_59 )
continue;
F_29 ( V_4 -> V_61 ,
F_30 ( & V_59 -> V_13 . V_62 ) ) ;
F_31 ( & V_59 -> V_13 ) ;
}
F_32 ( V_4 -> V_60 ) ;
F_33 ( V_4 -> V_61 ) ;
V_4 -> V_58 = 0 ;
}
static int F_34 ( struct V_3 * V_4 )
{
int V_25 = 0 ;
int V_57 ;
struct V_63 V_64 = { V_65 , NULL } ;
union V_21 * V_66 ;
T_1 V_6 ;
V_6 = F_35 ( V_4 -> V_7 -> V_8 , L_18 , NULL ,
& V_64 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_19 ) ) ;
return - V_10 ;
}
V_66 = V_64 . V_67 ;
if ( ! V_66 ||
V_66 -> type != V_68 ) {
F_36 ( & V_4 -> V_7 -> V_13 , V_56
L_20 ) ;
V_25 = - V_69 ;
goto V_70;
}
if ( ! V_66 -> V_71 . V_20 )
goto V_70;
V_4 -> V_60 = F_37 ( sizeof( struct V_17 * ) *
V_66 -> V_71 . V_20 , V_72 ) ;
if ( ! V_4 -> V_60 ) {
V_25 = - V_73 ;
goto V_70;
}
V_4 -> V_61 = F_38 ( L_21 ,
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
V_6 = F_39 ( V_75 -> V_78 . V_8 ,
& V_4 -> V_60 [ V_57 ] ) ;
if ( F_4 ( V_6 ) )
continue;
V_59 = V_4 -> V_60 [ V_57 ] ;
F_40 ( & V_59 -> V_13 ) ;
V_25 = F_41 ( V_4 -> V_61 , & V_59 -> V_13 . V_62 ,
F_30 ( & V_59 -> V_13 . V_62 ) ) ;
if ( V_25 ) {
F_31 ( & V_59 -> V_13 ) ;
V_4 -> V_60 [ V_57 ] = NULL ;
}
}
V_25 = 0 ;
goto V_70;
V_74:
F_32 ( V_4 -> V_60 ) ;
V_70:
F_32 ( V_64 . V_67 ) ;
return V_25 ;
}
static int F_42 ( struct V_3 * V_4 ,
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
if ( V_80 -> V_89 ) {
V_81 -> V_84 . V_38 . V_86 |= V_90 ;
V_81 -> V_84 . V_91 = V_80 -> V_89 ;
}
F_43 ( & V_81 -> V_84 . V_38 ) ;
V_25 = F_44 ( V_13 , & V_81 -> V_84 ) ;
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
static void F_45 ( struct V_3 * V_4 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_4 -> V_82 ; V_57 ++ ) {
if ( ! V_4 -> V_81 [ V_57 ] . V_84 . V_38 . V_85 )
continue;
F_46 ( & V_4 -> V_7 -> V_13 ,
& V_4 -> V_81 [ V_57 ] . V_84 ) ;
}
F_28 ( V_4 ) ;
V_4 -> V_82 = 0 ;
}
static int F_47 ( struct V_3 * V_4 )
{
int V_25 = 0 ;
V_25 = F_34 ( V_4 ) ;
if ( V_25 )
return V_25 ;
if ( V_4 -> V_27 . V_52 & V_92 ) {
V_25 = F_42 ( V_4 , V_93 ) ;
if ( V_25 )
goto error;
}
if ( V_4 -> V_27 . V_52 & V_94 ) {
if ( ! F_1 () ) {
F_36 ( & V_4 -> V_7 -> V_13 ,
L_22 ) ;
goto V_95;
}
if ( V_4 -> V_27 . V_96 )
V_25 = F_42 ( V_4 , V_97 ) ;
else
V_25 = F_42 ( V_4 , V_98 ) ;
if ( V_25 )
goto error;
V_25 = F_42 ( V_4 , V_99 ) ;
if ( V_25 )
goto error;
}
V_95:
if ( V_4 -> V_27 . V_52 & V_100 ) {
V_25 = F_42 ( V_4 , V_101 ) ;
if ( V_25 )
goto error;
}
V_25 = F_42 ( V_4 , V_102 ) ;
if ( V_25 )
goto error;
return V_25 ;
error:
F_45 ( V_4 ) ;
return V_25 ;
}
static void F_48 ( struct V_3 * V_4 )
{
T_4 * V_103 ;
int V_57 ;
V_103 = & V_4 -> V_47 ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ , V_103 ++ )
F_32 ( * V_103 ) ;
}
static int F_49 ( struct V_3 * V_4 )
{
int V_25 = 0 ;
int V_57 ;
struct V_63 V_64 = { V_65 , NULL } ;
struct V_63 V_104 = { 0 , NULL } ;
struct V_63 V_105 = { sizeof( L_23 ) , L_23 } ;
union V_21 * V_66 ;
T_4 * V_103 ;
T_1 V_6 ;
V_6 = F_35 ( V_4 -> V_7 -> V_8 , L_24 , NULL ,
& V_64 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_25 ) ) ;
return - V_10 ;
}
V_66 = V_64 . V_67 ;
if ( ! V_66 ||
V_66 -> type != V_68 ||
V_66 -> V_71 . V_20 != 14 ) {
F_36 ( & V_4 -> V_7 -> V_13 , V_56
L_26 ) ;
V_25 = - V_69 ;
goto V_70;
}
V_104 . V_106 = sizeof( struct V_107 ) ;
V_104 . V_67 = & V_4 -> V_27 ;
V_6 = F_50 ( V_66 , & V_105 , & V_104 ) ;
if ( F_4 ( V_6 ) ) {
F_5 ( ( V_9 , V_6 , L_27 ) ) ;
V_25 = - V_69 ;
goto V_70;
}
if ( V_4 -> V_27 . V_108 ) {
F_36 ( & V_4 -> V_7 -> V_13 , V_56
L_28 ,
V_4 -> V_27 . V_108 ) ;
V_25 = - V_30 ;
goto V_70;
}
V_103 = & V_4 -> V_47 ;
for ( V_57 = 11 ; V_57 < 14 ; V_57 ++ ) {
union V_21 * V_75 = & ( V_66 -> V_71 . V_76 [ V_57 ] ) ;
if ( V_75 -> type != V_109 ) {
V_25 = - V_30 ;
goto error;
}
* V_103 = F_37 ( sizeof( V_110 ) * ( V_75 -> string . V_106 + 1 ) ,
V_72 ) ;
if ( ! * V_103 ) {
V_25 = - V_73 ;
goto error;
}
strncpy ( * V_103 , V_75 -> string . V_67 , V_75 -> string . V_106 ) ;
V_103 ++ ;
}
F_51 ( & V_4 -> V_7 -> V_13 , L_29 ) ;
goto V_70;
error:
V_103 = & V_4 -> V_47 ;
for ( V_57 = 0 ; V_57 < 3 ; V_57 ++ , V_103 ++ )
F_32 ( * V_103 ) ;
V_70:
F_32 ( V_64 . V_67 ) ;
return V_25 ;
}
static void F_52 ( struct V_17 * V_12 , T_6 V_111 )
{
struct V_3 * V_4 ;
int V_25 ;
if ( ! V_12 || ! F_53 ( V_12 ) )
return;
V_4 = F_53 ( V_12 ) ;
F_8 ( & V_4 -> V_19 ) ;
switch ( V_111 ) {
case V_112 :
F_48 ( V_4 ) ;
V_25 = F_49 ( V_4 ) ;
if ( V_25 )
break;
F_45 ( V_4 ) ;
F_47 ( V_4 ) ;
break;
case V_113 :
F_54 ( & V_12 -> V_13 . V_62 , NULL , V_114 ) ;
F_19 ( V_4 ) ;
break;
case V_115 :
F_54 ( & V_12 -> V_13 . V_62 , NULL , V_116 ) ;
F_12 ( V_4 ) ;
break;
case V_117 :
F_54 ( & V_12 -> V_13 . V_62 , NULL , V_118 ) ;
F_2 ( V_4 ) ;
break;
case V_119 :
F_54 ( & V_12 -> V_13 . V_62 , NULL , V_120 ) ;
F_51 ( & V_12 -> V_13 , L_30 ) ;
break;
default:
F_24 () ;
}
F_9 ( & V_4 -> V_19 ) ;
F_55 ( V_121 ,
F_56 ( & V_12 -> V_13 ) , V_111 , 0 ) ;
}
static int F_57 ( struct V_17 * V_12 )
{
int V_25 ;
struct V_3 * V_4 ;
if ( ! V_12 )
return - V_30 ;
V_4 = F_37 ( sizeof( struct V_3 ) ,
V_72 ) ;
if ( ! V_4 )
return - V_73 ;
V_4 -> V_44 = 0 ;
V_4 -> V_7 = V_12 ;
F_58 ( & V_4 -> V_19 ) ;
strcpy ( F_59 ( V_12 ) , V_122 ) ;
strcpy ( F_60 ( V_12 ) , V_121 ) ;
V_12 -> V_18 = V_4 ;
F_48 ( V_4 ) ;
V_25 = F_49 ( V_4 ) ;
if ( V_25 )
goto V_74;
V_4 -> V_36 [ 0 ] = V_4 -> V_36 [ 1 ] = - 1 ;
V_25 = F_47 ( V_4 ) ;
if ( V_25 )
goto V_74;
V_4 -> V_123 = F_61 ( & V_12 -> V_13 ) ;
if ( F_62 ( V_4 -> V_123 ) ) {
V_25 = F_63 ( V_4 -> V_123 ) ;
goto V_124;
}
V_25 = 0 ;
goto exit;
V_124:
F_45 ( V_4 ) ;
V_74:
F_32 ( V_4 ) ;
exit:
return V_25 ;
}
static int F_64 ( struct V_17 * V_12 , int type )
{
struct V_3 * V_4 ;
if ( ! V_12 || ! F_53 ( V_12 ) )
return - V_30 ;
V_4 = F_53 ( V_12 ) ;
F_65 ( V_4 -> V_123 ) ;
F_48 ( V_4 ) ;
F_45 ( V_4 ) ;
F_32 ( V_4 ) ;
return 0 ;
}
static int F_66 ( struct V_12 * V_13 )
{
struct V_3 * V_4 ;
if ( ! V_13 )
return - V_30 ;
V_4 = F_53 ( F_7 ( V_13 ) ) ;
if ( ! V_4 )
return - V_30 ;
F_48 ( V_4 ) ;
F_49 ( V_4 ) ;
return 0 ;
}
static int T_7 F_67 ( const struct V_125 * V_126 )
{
V_2 = 1 ;
return 0 ;
}
static int T_7 F_68 ( void )
{
int V_127 ;
if ( V_128 )
return - V_10 ;
F_69 ( V_129 ) ;
V_127 = F_70 ( & V_130 ) ;
if ( V_127 < 0 )
return - V_10 ;
return 0 ;
}
static void T_8 F_71 ( void )
{
F_72 ( & V_130 ) ;
}

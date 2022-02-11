static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_7 , unsigned int V_8 ,
const char * V_9 , unsigned int V_10 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
struct V_15 * V_16 ;
unsigned int V_17 ;
if ( F_3 ( V_14 ) == V_18 ) {
V_16 = (struct V_15 * ) ( V_2 -> V_19 + V_3 ) ;
V_17 = V_3 + V_16 -> V_20 * 4 ;
V_7 += V_4 - V_17 ;
if ( ! F_4 ( V_2 , V_14 , V_12 ,
V_3 , V_7 , V_8 ,
V_9 , V_10 , false ) )
return 0 ;
} else {
V_17 = V_3 + sizeof( struct V_21 ) ;
V_7 += V_4 - V_17 ;
if ( ! F_5 ( V_2 , V_14 , V_12 ,
V_3 , V_7 , V_8 ,
V_9 , V_10 ) )
return 0 ;
}
* V_5 = V_2 -> V_19 + V_4 ;
* V_6 += V_10 - V_8 ;
return 1 ;
}
static int F_6 ( const struct V_13 * V_14 , char * V_9 ,
const union V_22 * V_23 , bool V_24 )
{
if ( F_7 ( V_14 ) == V_25 )
return sprintf ( V_9 , L_1 , & V_23 -> V_26 ) ;
else {
if ( V_24 )
return sprintf ( V_9 , L_2 , & V_23 -> V_27 ) ;
else
return sprintf ( V_9 , L_3 , & V_23 -> V_27 ) ;
}
}
static int F_8 ( const struct V_13 * V_14 , char * V_9 ,
const union V_22 * V_23 , T_1 V_28 )
{
if ( F_7 ( V_14 ) == V_25 )
return sprintf ( V_9 , L_4 , & V_23 -> V_26 , V_28 ) ;
else
return sprintf ( V_9 , L_5 , & V_23 -> V_27 , V_28 ) ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_7 , unsigned int V_8 ,
union V_22 * V_23 , T_2 V_28 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
enum V_29 V_30 = F_10 ( V_12 ) ;
char V_9 [ V_31 + sizeof( L_6 ) ] ;
unsigned int V_10 ;
union V_22 V_32 ;
T_2 V_33 ;
if ( F_11 ( & V_14 -> V_34 [ V_30 ] . V_35 . V_36 . V_37 , V_23 ) &&
V_14 -> V_34 [ V_30 ] . V_35 . V_36 . V_38 . V_39 . V_28 == V_28 ) {
V_32 = V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_37 ;
V_33 = V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_38 . V_39 . V_28 ;
} else if ( F_11 ( & V_14 -> V_34 [ V_30 ] . V_35 . V_40 . V_37 , V_23 ) &&
V_14 -> V_34 [ V_30 ] . V_35 . V_40 . V_38 . V_39 . V_28 == V_28 ) {
V_32 = V_14 -> V_34 [ ! V_30 ] . V_35 . V_36 . V_37 ;
V_33 = V_14 -> V_34 [ ! V_30 ] . V_35 . V_36 . V_38 . V_39 . V_28 ;
} else
return 1 ;
if ( F_11 ( & V_32 , V_23 ) && V_33 == V_28 )
return 1 ;
V_10 = F_8 ( V_14 , V_9 , & V_32 , F_12 ( V_33 ) ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
enum V_41 type )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
unsigned int V_8 , V_7 ;
union V_22 V_23 ;
T_2 V_28 ;
if ( F_14 ( V_14 , * V_5 , NULL , * V_6 , type , NULL ,
& V_7 , & V_8 , & V_23 , & V_28 ) <= 0 )
return 1 ;
return F_9 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , & V_23 , V_28 ) ;
}
static unsigned int F_15 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
enum V_29 V_30 = F_10 ( V_12 ) ;
unsigned int V_42 , V_7 , V_8 ;
enum V_41 V_43 ;
union V_22 V_23 ;
T_2 V_28 ;
int V_44 , V_45 ;
if ( F_16 ( * V_5 , L_7 , strlen ( L_7 ) ) != 0 ) {
if ( F_17 ( V_14 , * V_5 , * V_6 ,
& V_7 , & V_8 ,
& V_23 , & V_28 ) > 0 &&
! F_9 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , & V_23 , V_28 ) )
return V_46 ;
V_44 = 1 ;
} else
V_44 = 0 ;
if ( F_3 ( V_14 ) == V_18 )
V_43 = V_47 ;
else
V_43 = V_48 ;
if ( F_14 ( V_14 , * V_5 , NULL , * V_6 ,
V_43 , NULL , & V_7 , & V_8 ,
& V_23 , & V_28 ) > 0 ) {
unsigned int V_49 , V_50 , V_51 , V_52 , V_10 , V_53 ;
char V_9 [ V_31 + sizeof( L_6 ) ] ;
if ( V_44 ) {
if ( ! F_11 ( & V_23 ,
& V_14 -> V_34 [ V_30 ] . V_35 . V_36 . V_37 ) ||
V_28 != V_14 -> V_34 [ V_30 ] . V_35 . V_36 . V_38 . V_39 . V_28 )
goto V_54;
} else {
if ( ! F_11 ( & V_23 ,
& V_14 -> V_34 [ V_30 ] . V_35 . V_40 . V_37 ) ||
V_28 != V_14 -> V_34 [ V_30 ] . V_35 . V_40 . V_38 . V_39 . V_28 )
goto V_54;
}
V_49 = * V_6 ;
if ( ! F_9 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , & V_23 , V_28 ) )
return V_46 ;
V_50 = V_7 + V_8 + * V_6 - V_49 ;
if ( F_18 ( V_14 , * V_5 , V_50 , * V_6 ,
L_8 , & V_51 , & V_52 ,
& V_23 , true ) > 0 &&
F_11 ( & V_23 , & V_14 -> V_34 [ V_30 ] . V_35 . V_36 . V_37 ) &&
! F_11 ( & V_23 , & V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_37 ) ) {
V_10 = F_6 ( V_14 , V_9 ,
& V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_37 ,
true ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_51 , V_52 , V_9 , V_10 ) )
return V_46 ;
}
if ( F_18 ( V_14 , * V_5 , V_50 , * V_6 ,
L_9 , & V_51 , & V_52 ,
& V_23 , false ) > 0 &&
F_11 ( & V_23 , & V_14 -> V_34 [ V_30 ] . V_35 . V_40 . V_37 ) &&
! F_11 ( & V_23 , & V_14 -> V_34 [ ! V_30 ] . V_35 . V_36 . V_37 ) ) {
V_10 = F_6 ( V_14 , V_9 ,
& V_14 -> V_34 [ ! V_30 ] . V_35 . V_36 . V_37 ,
false ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_51 , V_52 , V_9 , V_10 ) )
return V_46 ;
}
if ( F_19 ( V_14 , * V_5 , V_50 , * V_6 ,
L_10 , & V_51 , & V_52 ,
& V_53 ) > 0 &&
F_20 ( V_53 ) == V_14 -> V_34 [ V_30 ] . V_35 . V_40 . V_38 . V_39 . V_28 &&
F_20 ( V_53 ) != V_14 -> V_34 [ ! V_30 ] . V_35 . V_36 . V_38 . V_39 . V_28 ) {
T_2 V_55 = V_14 -> V_34 [ ! V_30 ] . V_35 . V_36 . V_38 . V_39 . V_28 ;
V_10 = sprintf ( V_9 , L_11 , F_12 ( V_55 ) ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_51 , V_52 , V_9 , V_10 ) )
return V_46 ;
}
}
V_54:
V_42 = 0 ;
V_45 = 0 ;
while ( F_14 ( V_14 , * V_5 , & V_42 , * V_6 ,
V_56 , & V_45 ,
& V_7 , & V_8 ,
& V_23 , & V_28 ) > 0 ) {
if ( ! F_9 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 ,
& V_23 , V_28 ) )
return V_46 ;
}
if ( ! F_13 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_57 ) ||
! F_13 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_58 ) )
return V_46 ;
return V_59 ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int V_3 ,
T_3 V_60 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
const struct V_15 * V_16 ;
if ( F_3 ( V_14 ) != V_18 || V_60 == 0 )
return;
V_16 = (struct V_15 * ) ( V_2 -> V_19 + V_3 ) ;
F_22 ( V_14 , V_12 , V_16 -> V_61 , V_60 ) ;
}
static void F_23 ( struct V_13 * V_14 ,
struct V_62 * exp )
{
struct V_63 V_64 ;
F_24 ( V_14 -> V_65 & V_66 ) ;
V_64 . V_67 = ( V_68 | V_69 ) ;
V_64 . V_70 = V_64 . V_71 = exp -> V_72 ;
V_64 . V_73 = V_64 . V_74 = exp -> V_75 ;
F_25 ( V_14 , & V_64 , V_76 ) ;
if ( F_11 ( & V_14 -> V_34 [ V_77 ] . V_35 . V_36 . V_37 ,
& V_14 -> V_78 -> V_34 [ exp -> V_30 ] . V_35 . V_36 . V_37 ) ) {
V_64 . V_67 = V_68 ;
V_64 . V_73 = V_64 . V_74
= V_14 -> V_78 -> V_34 [ ! exp -> V_30 ] . V_35 . V_40 . V_37 ;
F_25 ( V_14 , & V_64 , V_79 ) ;
}
}
static unsigned int F_26 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
struct V_62 * exp ,
unsigned int V_7 ,
unsigned int V_8 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
enum V_29 V_30 = F_10 ( V_12 ) ;
union V_22 V_32 ;
T_4 V_28 ;
char V_9 [ V_31 + sizeof( L_6 ) ] ;
unsigned int V_10 ;
if ( F_11 ( & V_14 -> V_34 [ V_30 ] . V_35 . V_36 . V_37 ,
& V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_37 ) )
V_32 = exp -> V_35 . V_40 . V_37 ;
else
V_32 = V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_37 ;
if ( exp -> V_35 . V_40 . V_38 . V_39 . V_28 ==
V_14 -> V_34 [ V_30 ] . V_35 . V_36 . V_38 . V_39 . V_28 )
V_28 = F_12 ( V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_38 . V_39 . V_28 ) ;
else
V_28 = F_12 ( exp -> V_35 . V_40 . V_38 . V_39 . V_28 ) ;
exp -> V_75 = exp -> V_35 . V_40 . V_37 ;
exp -> V_35 . V_40 . V_37 = V_32 ;
exp -> V_72 . V_39 . V_28 = exp -> V_35 . V_40 . V_38 . V_39 . V_28 ;
exp -> V_30 = ! V_30 ;
exp -> V_80 = F_23 ;
for (; V_28 != 0 ; V_28 ++ ) {
int V_81 ;
exp -> V_35 . V_40 . V_38 . V_39 . V_28 = F_20 ( V_28 ) ;
V_81 = F_27 ( exp ) ;
if ( V_81 == 0 )
break;
else if ( V_81 != - V_82 ) {
V_28 = 0 ;
break;
}
}
if ( V_28 == 0 )
return V_46 ;
if ( ! F_11 ( & exp -> V_35 . V_40 . V_37 , & exp -> V_75 ) ||
exp -> V_35 . V_40 . V_38 . V_39 . V_28 != exp -> V_72 . V_39 . V_28 ) {
V_10 = F_8 ( V_14 , V_9 , & V_32 , V_28 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) )
goto V_83;
}
return V_59 ;
V_83:
F_28 ( exp ) ;
return V_46 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
unsigned int V_7 , V_8 ;
char V_9 [ sizeof( L_12 ) ] ;
int V_10 , V_84 ;
if ( F_30 ( V_14 , * V_5 , 0 , * V_6 ,
V_85 , V_86 ,
& V_7 , & V_8 ) <= 0 )
return 0 ;
V_84 = * V_6 - V_7 + strlen ( L_13 ) ;
if ( F_31 ( V_14 , * V_5 , 0 , * V_6 , V_87 ,
& V_7 , & V_8 ) <= 0 )
return 0 ;
V_10 = sprintf ( V_9 , L_11 , V_84 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_88 ,
enum V_89 type ,
enum V_89 V_90 ,
char * V_9 , int V_10 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
unsigned int V_8 , V_7 ;
if ( F_30 ( V_14 , * V_5 , V_88 , * V_6 , type , V_90 ,
& V_7 , & V_8 ) <= 0 )
return - V_91 ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ? 0 : - V_92 ;
}
static unsigned int F_33 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_88 ,
enum V_89 type ,
enum V_89 V_90 ,
const union V_22 * V_23 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
char V_9 [ V_31 ] ;
unsigned int V_10 ;
V_10 = F_6 ( V_14 , V_9 , V_23 , false ) ;
if ( F_32 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_88 , type , V_90 , V_9 , V_10 ) )
return 0 ;
return F_29 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static unsigned int F_34 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_7 ,
unsigned int V_8 ,
T_4 V_28 )
{
char V_9 [ sizeof( L_14 ) ] ;
unsigned int V_10 ;
V_10 = sprintf ( V_9 , L_11 , V_28 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) )
return 0 ;
return F_29 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static unsigned int F_35 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_88 ,
const union V_22 * V_23 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
char V_9 [ V_31 ] ;
unsigned int V_10 ;
V_10 = F_6 ( V_14 , V_9 , V_23 , false ) ;
if ( F_32 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_88 ,
V_93 , V_94 , V_9 , V_10 ) )
return 0 ;
switch ( F_32 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_88 ,
V_95 , V_94 ,
V_9 , V_10 ) ) {
case 0 :
case - V_91 :
break;
default:
return 0 ;
}
return F_29 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static unsigned int F_36 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
struct V_62 * V_96 ,
struct V_62 * V_97 ,
unsigned int V_98 ,
unsigned int V_99 ,
union V_22 * V_100 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
enum V_29 V_30 = F_10 ( V_12 ) ;
T_4 V_28 ;
if ( F_11 ( & V_14 -> V_34 [ V_30 ] . V_35 . V_36 . V_37 ,
& V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_37 ) )
* V_100 = V_96 -> V_35 . V_40 . V_37 ;
else
* V_100 = V_14 -> V_34 [ ! V_30 ] . V_35 . V_40 . V_37 ;
V_96 -> V_75 = V_96 -> V_35 . V_40 . V_37 ;
V_96 -> V_35 . V_40 . V_37 = * V_100 ;
V_96 -> V_72 . V_39 . V_28 = V_96 -> V_35 . V_40 . V_38 . V_39 . V_28 ;
V_96 -> V_30 = ! V_30 ;
V_96 -> V_80 = F_23 ;
V_97 -> V_75 = V_97 -> V_35 . V_40 . V_37 ;
V_97 -> V_35 . V_40 . V_37 = * V_100 ;
V_97 -> V_72 . V_39 . V_28 = V_97 -> V_35 . V_40 . V_38 . V_39 . V_28 ;
V_97 -> V_30 = ! V_30 ;
V_97 -> V_80 = F_23 ;
for ( V_28 = F_12 ( V_96 -> V_35 . V_40 . V_38 . V_39 . V_28 ) ;
V_28 != 0 ; V_28 += 2 ) {
int V_81 ;
V_96 -> V_35 . V_40 . V_38 . V_39 . V_28 = F_20 ( V_28 ) ;
V_81 = F_27 ( V_96 ) ;
if ( V_81 == - V_82 )
continue;
else if ( V_81 < 0 ) {
V_28 = 0 ;
break;
}
V_97 -> V_35 . V_40 . V_38 . V_39 . V_28 = F_20 ( V_28 + 1 ) ;
V_81 = F_27 ( V_97 ) ;
if ( V_81 == 0 )
break;
else if ( V_81 == - V_82 ) {
F_28 ( V_96 ) ;
continue;
} else if ( V_81 < 0 ) {
F_28 ( V_96 ) ;
V_28 = 0 ;
break;
}
}
if ( V_28 == 0 )
goto V_101;
if ( V_96 -> V_35 . V_40 . V_38 . V_39 . V_28 != V_96 -> V_72 . V_39 . V_28 &&
! F_34 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_98 , V_99 , V_28 ) )
goto V_102;
return V_59 ;
V_102:
F_28 ( V_96 ) ;
F_28 ( V_97 ) ;
V_101:
return V_46 ;
}
static void T_5 F_37 ( void )
{
F_38 ( V_103 , NULL ) ;
F_38 ( V_104 , NULL ) ;
F_38 ( V_105 , NULL ) ;
F_38 ( V_106 , NULL ) ;
F_38 ( V_107 , NULL ) ;
F_38 ( V_108 , NULL ) ;
F_38 ( V_109 , NULL ) ;
F_39 ( & V_110 ) ;
F_40 () ;
}
static int T_6 F_41 ( void )
{
F_24 ( V_103 != NULL ) ;
F_24 ( V_104 != NULL ) ;
F_24 ( V_105 != NULL ) ;
F_24 ( V_106 != NULL ) ;
F_24 ( V_107 != NULL ) ;
F_24 ( V_108 != NULL ) ;
F_24 ( V_109 != NULL ) ;
F_38 ( V_103 , F_15 ) ;
F_38 ( V_104 , F_21 ) ;
F_38 ( V_105 , F_26 ) ;
F_38 ( V_106 , F_33 ) ;
F_38 ( V_107 , F_34 ) ;
F_38 ( V_108 , F_35 ) ;
F_38 ( V_109 , F_36 ) ;
F_42 ( & V_110 ) ;
return 0 ;
}

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
struct V_31 * V_32 = F_11 ( V_14 ) ;
char V_9 [ V_33 + sizeof( L_6 ) ] ;
unsigned int V_10 ;
union V_22 V_34 ;
T_2 V_35 ;
if ( F_12 ( & V_14 -> V_36 [ V_30 ] . V_37 . V_38 . V_39 , V_23 ) &&
V_14 -> V_36 [ V_30 ] . V_37 . V_38 . V_40 . V_41 . V_28 == V_28 ) {
V_34 = V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_39 ;
V_35 = V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_40 . V_41 . V_28 ;
} else if ( F_12 ( & V_14 -> V_36 [ V_30 ] . V_37 . V_42 . V_39 , V_23 ) &&
V_14 -> V_36 [ V_30 ] . V_37 . V_42 . V_40 . V_41 . V_28 == V_28 ) {
V_34 = V_14 -> V_36 [ ! V_30 ] . V_37 . V_38 . V_39 ;
V_35 = V_32 -> V_43 ? :
V_14 -> V_36 [ ! V_30 ] . V_37 . V_38 . V_40 . V_41 . V_28 ;
} else
return 1 ;
if ( F_12 ( & V_34 , V_23 ) && V_35 == V_28 )
return 1 ;
V_10 = F_8 ( V_14 , V_9 , & V_34 , F_13 ( V_35 ) ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
enum V_44 type )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
unsigned int V_8 , V_7 ;
union V_22 V_23 ;
T_2 V_28 ;
if ( F_15 ( V_14 , * V_5 , NULL , * V_6 , type , NULL ,
& V_7 , & V_8 , & V_23 , & V_28 ) <= 0 )
return 1 ;
return F_9 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , & V_23 , V_28 ) ;
}
static unsigned int F_16 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
enum V_29 V_30 = F_10 ( V_12 ) ;
struct V_31 * V_32 = F_11 ( V_14 ) ;
unsigned int V_45 , V_7 , V_8 ;
enum V_44 V_46 ;
union V_22 V_23 ;
T_2 V_28 ;
int V_47 , V_48 ;
if ( F_17 ( * V_5 , L_7 , strlen ( L_7 ) ) != 0 ) {
if ( F_18 ( V_14 , * V_5 , * V_6 ,
& V_7 , & V_8 ,
& V_23 , & V_28 ) > 0 &&
! F_9 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , & V_23 , V_28 ) ) {
F_19 ( V_2 , V_14 , L_8 ) ;
return V_49 ;
}
V_47 = 1 ;
} else
V_47 = 0 ;
if ( F_3 ( V_14 ) == V_18 )
V_46 = V_50 ;
else
V_46 = V_51 ;
if ( F_15 ( V_14 , * V_5 , NULL , * V_6 ,
V_46 , NULL , & V_7 , & V_8 ,
& V_23 , & V_28 ) > 0 ) {
unsigned int V_52 , V_53 , V_54 , V_55 , V_10 , V_56 ;
char V_9 [ V_33 + sizeof( L_6 ) ] ;
if ( V_47 ) {
if ( ! F_12 ( & V_23 ,
& V_14 -> V_36 [ V_30 ] . V_37 . V_38 . V_39 ) ||
V_28 != V_14 -> V_36 [ V_30 ] . V_37 . V_38 . V_40 . V_41 . V_28 )
goto V_57;
} else {
if ( ! F_12 ( & V_23 ,
& V_14 -> V_36 [ V_30 ] . V_37 . V_42 . V_39 ) ||
V_28 != V_14 -> V_36 [ V_30 ] . V_37 . V_42 . V_40 . V_41 . V_28 )
goto V_57;
}
V_52 = * V_6 ;
if ( ! F_9 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , & V_23 , V_28 ) ) {
F_19 ( V_2 , V_14 , L_9 ) ;
return V_49 ;
}
V_53 = V_7 + V_8 + * V_6 - V_52 ;
if ( F_20 ( V_14 , * V_5 , V_53 , * V_6 ,
L_10 , & V_54 , & V_55 ,
& V_23 , true ) > 0 &&
F_12 ( & V_23 , & V_14 -> V_36 [ V_30 ] . V_37 . V_38 . V_39 ) &&
! F_12 ( & V_23 , & V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_39 ) ) {
V_10 = F_6 ( V_14 , V_9 ,
& V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_39 ,
true ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_54 , V_55 , V_9 , V_10 ) ) {
F_19 ( V_2 , V_14 , L_11 ) ;
return V_49 ;
}
}
if ( F_20 ( V_14 , * V_5 , V_53 , * V_6 ,
L_12 , & V_54 , & V_55 ,
& V_23 , false ) > 0 &&
F_12 ( & V_23 , & V_14 -> V_36 [ V_30 ] . V_37 . V_42 . V_39 ) &&
! F_12 ( & V_23 , & V_14 -> V_36 [ ! V_30 ] . V_37 . V_38 . V_39 ) ) {
V_10 = F_6 ( V_14 , V_9 ,
& V_14 -> V_36 [ ! V_30 ] . V_37 . V_38 . V_39 ,
false ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_54 , V_55 , V_9 , V_10 ) )
F_19 ( V_2 , V_14 , L_13 ) ;
return V_49 ;
}
if ( F_21 ( V_14 , * V_5 , V_53 , * V_6 ,
L_14 , & V_54 , & V_55 ,
& V_56 ) > 0 &&
F_22 ( V_56 ) == V_14 -> V_36 [ V_30 ] . V_37 . V_42 . V_40 . V_41 . V_28 &&
F_22 ( V_56 ) != V_14 -> V_36 [ ! V_30 ] . V_37 . V_38 . V_40 . V_41 . V_28 ) {
T_2 V_58 = V_14 -> V_36 [ ! V_30 ] . V_37 . V_38 . V_40 . V_41 . V_28 ;
V_10 = sprintf ( V_9 , L_15 , F_13 ( V_58 ) ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_54 , V_55 , V_9 , V_10 ) ) {
F_19 ( V_2 , V_14 , L_16 ) ;
return V_49 ;
}
}
}
V_57:
V_45 = 0 ;
V_48 = 0 ;
while ( F_15 ( V_14 , * V_5 , & V_45 , * V_6 ,
V_59 , & V_48 ,
& V_7 , & V_8 ,
& V_23 , & V_28 ) > 0 ) {
if ( ! F_9 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 ,
& V_23 , V_28 ) ) {
F_19 ( V_2 , V_14 , L_17 ) ;
return V_49 ;
}
}
if ( ! F_14 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_60 ) ||
! F_14 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_61 ) ) {
F_19 ( V_2 , V_14 , L_18 ) ;
return V_49 ;
}
if ( V_30 == V_62 && V_32 -> V_43 ) {
struct V_21 * V_63 ;
if ( ! F_23 ( V_2 , V_2 -> V_64 ) ) {
F_19 ( V_2 , V_14 , L_19 ) ;
return V_49 ;
}
V_63 = ( void * ) V_2 -> V_19 + V_3 ;
V_63 -> V_65 = V_32 -> V_43 ;
if ( ! F_5 ( V_2 , V_14 , V_12 , V_3 ,
0 , 0 , NULL , 0 ) ) {
F_19 ( V_2 , V_14 , L_19 ) ;
return V_49 ;
}
}
return V_66 ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_3 ,
T_3 V_67 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
const struct V_15 * V_16 ;
if ( F_3 ( V_14 ) != V_18 || V_67 == 0 )
return;
V_16 = (struct V_15 * ) ( V_2 -> V_19 + V_3 ) ;
F_25 ( V_14 , V_12 , V_16 -> V_68 , V_67 ) ;
}
static void F_26 ( struct V_13 * V_14 ,
struct V_69 * exp )
{
struct V_70 V_71 ;
F_27 ( V_14 -> V_72 & V_73 ) ;
V_71 . V_74 = ( V_75 | V_76 ) ;
V_71 . V_77 = V_71 . V_78 = exp -> V_79 ;
V_71 . V_80 = V_71 . V_81 = exp -> V_82 ;
F_28 ( V_14 , & V_71 , V_83 ) ;
if ( F_12 ( & V_14 -> V_36 [ V_84 ] . V_37 . V_38 . V_39 ,
& V_14 -> V_85 -> V_36 [ exp -> V_30 ] . V_37 . V_38 . V_39 ) ) {
V_71 . V_74 = V_75 ;
V_71 . V_80 = V_71 . V_81
= V_14 -> V_85 -> V_36 [ ! exp -> V_30 ] . V_37 . V_42 . V_39 ;
F_28 ( V_14 , & V_71 , V_86 ) ;
}
}
static unsigned int F_29 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
struct V_69 * exp ,
unsigned int V_7 ,
unsigned int V_8 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
enum V_29 V_30 = F_10 ( V_12 ) ;
struct V_31 * V_32 = F_11 ( V_14 ) ;
union V_22 V_34 ;
T_4 V_28 ;
T_2 V_87 ;
char V_9 [ V_33 + sizeof( L_6 ) ] ;
unsigned int V_10 ;
if ( F_12 ( & V_14 -> V_36 [ V_30 ] . V_37 . V_38 . V_39 ,
& V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_39 ) )
V_34 = exp -> V_37 . V_42 . V_39 ;
else
V_34 = V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_39 ;
V_87 = V_32 -> V_43 ? :
V_14 -> V_36 [ V_30 ] . V_37 . V_38 . V_40 . V_41 . V_28 ;
if ( exp -> V_37 . V_42 . V_40 . V_41 . V_28 == V_87 )
V_28 = F_13 ( V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_40 . V_41 . V_28 ) ;
else
V_28 = F_13 ( exp -> V_37 . V_42 . V_40 . V_41 . V_28 ) ;
exp -> V_82 = exp -> V_37 . V_42 . V_39 ;
exp -> V_37 . V_42 . V_39 = V_34 ;
exp -> V_79 . V_41 . V_28 = exp -> V_37 . V_42 . V_40 . V_41 . V_28 ;
exp -> V_30 = ! V_30 ;
exp -> V_88 = F_26 ;
for (; V_28 != 0 ; V_28 ++ ) {
int V_89 ;
exp -> V_37 . V_42 . V_40 . V_41 . V_28 = F_22 ( V_28 ) ;
V_89 = F_30 ( exp ) ;
if ( V_89 == 0 )
break;
else if ( V_89 != - V_90 ) {
V_28 = 0 ;
break;
}
}
if ( V_28 == 0 ) {
F_19 ( V_2 , V_14 , L_20 ) ;
return V_49 ;
}
if ( ! F_12 ( & exp -> V_37 . V_42 . V_39 , & exp -> V_82 ) ||
exp -> V_37 . V_42 . V_40 . V_41 . V_28 != exp -> V_79 . V_41 . V_28 ) {
V_10 = F_8 ( V_14 , V_9 , & V_34 , V_28 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ) {
F_19 ( V_2 , V_14 , L_19 ) ;
goto V_91;
}
}
return V_66 ;
V_91:
F_31 ( exp ) ;
return V_49 ;
}
static int F_32 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
unsigned int V_7 , V_8 ;
char V_9 [ sizeof( L_21 ) ] ;
int V_10 , V_92 ;
if ( F_33 ( V_14 , * V_5 , 0 , * V_6 ,
V_93 , V_94 ,
& V_7 , & V_8 ) <= 0 )
return 0 ;
V_92 = * V_6 - V_7 + strlen ( L_22 ) ;
if ( F_34 ( V_14 , * V_5 , 0 , * V_6 , V_95 ,
& V_7 , & V_8 ) <= 0 )
return 0 ;
V_10 = sprintf ( V_9 , L_15 , V_92 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ;
}
static int F_35 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_96 ,
enum V_97 type ,
enum V_97 V_98 ,
char * V_9 , int V_10 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
unsigned int V_8 , V_7 ;
if ( F_33 ( V_14 , * V_5 , V_96 , * V_6 , type , V_98 ,
& V_7 , & V_8 ) <= 0 )
return - V_99 ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) ? 0 : - V_100 ;
}
static unsigned int F_36 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_96 ,
enum V_97 type ,
enum V_97 V_98 ,
const union V_22 * V_23 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
char V_9 [ V_33 ] ;
unsigned int V_10 ;
V_10 = F_6 ( V_14 , V_9 , V_23 , false ) ;
if ( F_35 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_96 , type , V_98 , V_9 , V_10 ) )
return 0 ;
return F_32 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static unsigned int F_37 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_7 ,
unsigned int V_8 ,
T_4 V_28 )
{
char V_9 [ sizeof( L_23 ) ] ;
unsigned int V_10 ;
V_10 = sprintf ( V_9 , L_15 , V_28 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_7 , V_8 , V_9 , V_10 ) )
return 0 ;
return F_32 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static unsigned int F_38 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
unsigned int V_96 ,
const union V_22 * V_23 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
char V_9 [ V_33 ] ;
unsigned int V_10 ;
V_10 = F_6 ( V_14 , V_9 , V_23 , false ) ;
if ( F_35 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_96 ,
V_101 , V_102 , V_9 , V_10 ) )
return 0 ;
switch ( F_35 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_96 ,
V_103 , V_102 ,
V_9 , V_10 ) ) {
case 0 :
case - V_99 :
break;
default:
return 0 ;
}
return F_32 ( V_2 , V_3 , V_4 , V_5 , V_6 ) ;
}
static unsigned int F_39 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 ,
const char * * V_5 , unsigned int * V_6 ,
struct V_69 * V_104 ,
struct V_69 * V_105 ,
unsigned int V_106 ,
unsigned int V_107 ,
union V_22 * V_108 )
{
enum V_11 V_12 ;
struct V_13 * V_14 = F_2 ( V_2 , & V_12 ) ;
enum V_29 V_30 = F_10 ( V_12 ) ;
T_4 V_28 ;
if ( F_12 ( & V_14 -> V_36 [ V_30 ] . V_37 . V_38 . V_39 ,
& V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_39 ) )
* V_108 = V_104 -> V_37 . V_42 . V_39 ;
else
* V_108 = V_14 -> V_36 [ ! V_30 ] . V_37 . V_42 . V_39 ;
V_104 -> V_82 = V_104 -> V_37 . V_42 . V_39 ;
V_104 -> V_37 . V_42 . V_39 = * V_108 ;
V_104 -> V_79 . V_41 . V_28 = V_104 -> V_37 . V_42 . V_40 . V_41 . V_28 ;
V_104 -> V_30 = ! V_30 ;
V_104 -> V_88 = F_26 ;
V_105 -> V_82 = V_105 -> V_37 . V_42 . V_39 ;
V_105 -> V_37 . V_42 . V_39 = * V_108 ;
V_105 -> V_79 . V_41 . V_28 = V_105 -> V_37 . V_42 . V_40 . V_41 . V_28 ;
V_105 -> V_30 = ! V_30 ;
V_105 -> V_88 = F_26 ;
for ( V_28 = F_13 ( V_104 -> V_37 . V_42 . V_40 . V_41 . V_28 ) ;
V_28 != 0 ; V_28 += 2 ) {
int V_89 ;
V_104 -> V_37 . V_42 . V_40 . V_41 . V_28 = F_22 ( V_28 ) ;
V_89 = F_30 ( V_104 ) ;
if ( V_89 == - V_90 )
continue;
else if ( V_89 < 0 ) {
V_28 = 0 ;
break;
}
V_105 -> V_37 . V_42 . V_40 . V_41 . V_28 = F_22 ( V_28 + 1 ) ;
V_89 = F_30 ( V_105 ) ;
if ( V_89 == 0 )
break;
else if ( V_89 == - V_90 ) {
F_31 ( V_104 ) ;
continue;
} else if ( V_89 < 0 ) {
F_31 ( V_104 ) ;
V_28 = 0 ;
break;
}
}
if ( V_28 == 0 ) {
F_19 ( V_2 , V_14 , L_24 ) ;
goto V_109;
}
if ( V_104 -> V_37 . V_42 . V_40 . V_41 . V_28 != V_104 -> V_79 . V_41 . V_28 &&
! F_37 ( V_2 , V_3 , V_4 , V_5 , V_6 ,
V_106 , V_107 , V_28 ) ) {
F_19 ( V_2 , V_14 , L_25 ) ;
goto V_110;
}
return V_66 ;
V_110:
F_31 ( V_104 ) ;
F_31 ( V_105 ) ;
V_109:
return V_49 ;
}
static void T_5 F_40 ( void )
{
F_41 ( V_111 , NULL ) ;
F_41 ( V_112 , NULL ) ;
F_41 ( V_113 , NULL ) ;
F_41 ( V_114 , NULL ) ;
F_41 ( V_115 , NULL ) ;
F_41 ( V_116 , NULL ) ;
F_41 ( V_117 , NULL ) ;
F_42 ( & V_118 ) ;
F_43 () ;
}
static int T_6 F_44 ( void )
{
F_27 ( V_111 != NULL ) ;
F_27 ( V_112 != NULL ) ;
F_27 ( V_113 != NULL ) ;
F_27 ( V_114 != NULL ) ;
F_27 ( V_115 != NULL ) ;
F_27 ( V_116 != NULL ) ;
F_27 ( V_117 != NULL ) ;
F_41 ( V_111 , F_16 ) ;
F_41 ( V_112 , F_24 ) ;
F_41 ( V_113 , F_29 ) ;
F_41 ( V_114 , F_36 ) ;
F_41 ( V_115 , F_37 ) ;
F_41 ( V_116 , F_38 ) ;
F_41 ( V_117 , F_39 ) ;
F_45 ( & V_118 ) ;
return 0 ;
}

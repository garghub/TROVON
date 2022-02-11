static unsigned int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
unsigned int V_6 , unsigned int V_7 ,
const char * V_8 , unsigned int V_9 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
struct V_14 * V_15 ;
unsigned int V_16 ;
if ( F_3 ( V_13 ) == V_17 ) {
V_15 = (struct V_14 * ) ( V_2 -> V_18 + F_4 ( V_2 ) ) ;
V_16 = F_4 ( V_2 ) + V_15 -> V_19 * 4 ;
V_6 += V_3 - V_16 ;
if ( ! F_5 ( V_2 , V_13 , V_11 ,
V_6 , V_7 ,
V_8 , V_9 , false ) )
return 0 ;
} else {
V_16 = F_4 ( V_2 ) + sizeof( struct V_20 ) ;
V_6 += V_3 - V_16 ;
if ( ! F_6 ( V_2 , V_13 , V_11 ,
V_6 , V_7 ,
V_8 , V_9 ) )
return 0 ;
}
* V_4 = V_2 -> V_18 + V_3 ;
* V_5 += V_9 - V_7 ;
return 1 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
unsigned int V_6 , unsigned int V_7 ,
union V_21 * V_22 , T_1 V_23 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
enum V_24 V_25 = F_8 ( V_11 ) ;
char V_8 [ sizeof( L_1 ) ] ;
unsigned int V_9 ;
T_2 V_26 ;
T_1 V_27 ;
if ( V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 == V_22 -> V_32 &&
V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 == V_23 ) {
V_26 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ;
V_27 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_33 . V_34 . V_23 ;
} else if ( V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_31 . V_32 == V_22 -> V_32 &&
V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_33 . V_34 . V_23 == V_23 ) {
V_26 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_31 . V_32 ;
V_27 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 ;
} else
return 1 ;
if ( V_26 == V_22 -> V_32 && V_27 == V_23 )
return 1 ;
V_9 = sprintf ( V_8 , L_2 , & V_26 , F_9 ( V_27 ) ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
enum V_36 type )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
unsigned int V_7 , V_6 ;
union V_21 V_22 ;
T_1 V_23 ;
if ( F_11 ( V_13 , * V_4 , NULL , * V_5 , type , NULL ,
& V_6 , & V_7 , & V_22 , & V_23 ) <= 0 )
return 1 ;
return F_7 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
& V_22 , V_23 ) ;
}
static unsigned int F_12 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
enum V_24 V_25 = F_8 ( V_11 ) ;
unsigned int V_37 , V_6 , V_7 ;
enum V_36 V_38 ;
union V_21 V_22 ;
T_1 V_23 ;
int V_39 , V_40 ;
if ( F_13 ( * V_4 , L_3 , strlen ( L_3 ) ) != 0 ) {
if ( F_14 ( V_13 , * V_4 , * V_5 ,
& V_6 , & V_7 ,
& V_22 , & V_23 ) > 0 &&
! F_7 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
& V_22 , V_23 ) )
return V_41 ;
V_39 = 1 ;
} else
V_39 = 0 ;
if ( F_3 ( V_13 ) == V_17 )
V_38 = V_42 ;
else
V_38 = V_43 ;
if ( F_11 ( V_13 , * V_4 , NULL , * V_5 ,
V_38 , NULL , & V_6 , & V_7 ,
& V_22 , & V_23 ) > 0 ) {
unsigned int V_44 , V_45 , V_46 , V_47 , V_9 , V_48 ;
char V_8 [ sizeof( L_1 ) ] ;
if ( V_39 ) {
if ( V_22 . V_32 != V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 ||
V_23 != V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 )
goto V_49;
} else {
if ( V_22 . V_32 != V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_31 . V_32 ||
V_23 != V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_33 . V_34 . V_23 )
goto V_49;
}
V_44 = * V_5 ;
if ( ! F_7 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
& V_22 , V_23 ) )
return V_41 ;
V_45 = V_6 + V_7 + * V_5 - V_44 ;
if ( F_15 ( V_13 , * V_4 , V_45 , * V_5 ,
L_4 , & V_46 , & V_47 ,
& V_22 , true ) > 0 &&
V_22 . V_32 == V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 &&
V_22 . V_32 != V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ) {
V_9 = sprintf ( V_8 , L_5 ,
& V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_46 , V_47 , V_8 , V_9 ) )
return V_41 ;
}
if ( F_15 ( V_13 , * V_4 , V_45 , * V_5 ,
L_6 , & V_46 , & V_47 ,
& V_22 , false ) > 0 &&
V_22 . V_32 == V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_31 . V_32 &&
V_22 . V_32 != V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_31 . V_32 ) {
V_9 = sprintf ( V_8 , L_5 ,
& V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_31 . V_32 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_46 , V_47 , V_8 , V_9 ) )
return V_41 ;
}
if ( F_16 ( V_13 , * V_4 , V_45 , * V_5 ,
L_7 , & V_46 , & V_47 ,
& V_48 ) > 0 &&
F_17 ( V_48 ) == V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_33 . V_34 . V_23 &&
F_17 ( V_48 ) != V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 ) {
T_1 V_50 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 ;
V_9 = sprintf ( V_8 , L_8 , F_9 ( V_50 ) ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_46 , V_47 , V_8 , V_9 ) )
return V_41 ;
}
}
V_49:
V_37 = 0 ;
V_40 = 0 ;
while ( F_11 ( V_13 , * V_4 , & V_37 , * V_5 ,
V_51 , & V_40 ,
& V_6 , & V_7 ,
& V_22 , & V_23 ) > 0 ) {
if ( ! F_7 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
& V_22 , V_23 ) )
return V_41 ;
}
if ( ! F_10 ( V_2 , V_3 , V_4 , V_5 , V_52 ) ||
! F_10 ( V_2 , V_3 , V_4 , V_5 , V_53 ) )
return V_41 ;
return V_54 ;
}
static void F_18 ( struct V_1 * V_2 , T_3 V_55 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
const struct V_14 * V_15 ;
if ( F_3 ( V_13 ) != V_17 || V_55 == 0 )
return;
V_15 = (struct V_14 * ) ( V_2 -> V_18 + F_4 ( V_2 ) ) ;
F_19 ( V_13 , V_11 , V_15 -> V_56 , V_55 ) ;
}
static void F_20 ( struct V_12 * V_13 ,
struct V_57 * exp )
{
struct V_58 V_59 ;
F_21 ( V_13 -> V_60 & V_61 ) ;
V_59 . V_62 = ( V_63 | V_64 ) ;
V_59 . V_65 = V_59 . V_66 = exp -> V_67 ;
V_59 . V_68 = V_59 . V_69 = exp -> V_70 ;
F_22 ( V_13 , & V_59 , V_71 ) ;
if ( V_13 -> V_28 [ V_72 ] . V_29 . V_30 . V_31 . V_32 ==
V_13 -> V_73 -> V_28 [ exp -> V_25 ] . V_29 . V_30 . V_31 . V_32 ) {
V_59 . V_62 = V_63 ;
V_59 . V_68 = V_59 . V_69
= V_13 -> V_73 -> V_28 [ ! exp -> V_25 ] . V_29 . V_35 . V_31 . V_32 ;
F_22 ( V_13 , & V_59 , V_74 ) ;
}
}
static unsigned int F_23 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
struct V_57 * exp ,
unsigned int V_6 ,
unsigned int V_7 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
enum V_24 V_25 = F_8 ( V_11 ) ;
T_2 V_75 ;
T_4 V_23 ;
char V_8 [ sizeof( L_1 ) ] ;
unsigned int V_9 ;
if ( V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 == V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 )
V_75 = exp -> V_29 . V_35 . V_31 . V_32 ;
else
V_75 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ;
if ( exp -> V_29 . V_35 . V_33 . V_34 . V_23 ==
V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 )
V_23 = F_9 ( V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_33 . V_34 . V_23 ) ;
else
V_23 = F_9 ( exp -> V_29 . V_35 . V_33 . V_34 . V_23 ) ;
exp -> V_70 = exp -> V_29 . V_35 . V_31 . V_32 ;
exp -> V_29 . V_35 . V_31 . V_32 = V_75 ;
exp -> V_67 . V_34 . V_23 = exp -> V_29 . V_35 . V_33 . V_34 . V_23 ;
exp -> V_25 = ! V_25 ;
exp -> V_76 = F_20 ;
for (; V_23 != 0 ; V_23 ++ ) {
int V_77 ;
exp -> V_29 . V_35 . V_33 . V_34 . V_23 = F_17 ( V_23 ) ;
V_77 = F_24 ( exp ) ;
if ( V_77 == 0 )
break;
else if ( V_77 != - V_78 ) {
V_23 = 0 ;
break;
}
}
if ( V_23 == 0 )
return V_41 ;
if ( exp -> V_29 . V_35 . V_31 . V_32 != exp -> V_70 ||
exp -> V_29 . V_35 . V_33 . V_34 . V_23 != exp -> V_67 . V_34 . V_23 ) {
V_9 = sprintf ( V_8 , L_2 , & V_75 , V_23 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 , V_9 ) )
goto V_79;
}
return V_54 ;
V_79:
F_25 ( exp ) ;
return V_41 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
unsigned int V_6 , V_7 ;
char V_8 [ sizeof( L_9 ) ] ;
int V_9 , V_80 ;
if ( F_27 ( V_13 , * V_4 , 0 , * V_5 ,
V_81 , V_82 ,
& V_6 , & V_7 ) <= 0 )
return 0 ;
V_80 = * V_5 - V_6 + strlen ( L_10 ) ;
if ( F_28 ( V_13 , * V_4 , 0 , * V_5 , V_83 ,
& V_6 , & V_7 ) <= 0 )
return 0 ;
V_9 = sprintf ( V_8 , L_8 , V_80 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
unsigned int V_84 ,
enum V_85 type ,
enum V_85 V_86 ,
char * V_8 , int V_9 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
unsigned int V_7 , V_6 ;
if ( F_27 ( V_13 , * V_4 , V_84 , * V_5 , type , V_86 ,
& V_6 , & V_7 ) <= 0 )
return - V_87 ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 ) ? 0 : - V_88 ;
}
static unsigned int F_30 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
unsigned int V_84 ,
enum V_85 type ,
enum V_85 V_86 ,
const union V_21 * V_22 )
{
char V_8 [ sizeof( L_11 ) ] ;
unsigned int V_9 ;
V_9 = sprintf ( V_8 , L_5 , & V_22 -> V_32 ) ;
if ( F_29 ( V_2 , V_3 , V_4 , V_5 , V_84 , type , V_86 ,
V_8 , V_9 ) )
return 0 ;
return F_26 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static unsigned int F_31 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
unsigned int V_6 ,
unsigned int V_7 ,
T_4 V_23 )
{
char V_8 [ sizeof( L_12 ) ] ;
unsigned int V_9 ;
V_9 = sprintf ( V_8 , L_8 , V_23 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 ) )
return 0 ;
return F_26 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static unsigned int F_32 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
unsigned int V_84 ,
const union V_21 * V_22 )
{
char V_8 [ sizeof( L_11 ) ] ;
unsigned int V_9 ;
V_9 = sprintf ( V_8 , L_5 , & V_22 -> V_32 ) ;
if ( F_29 ( V_2 , V_3 , V_4 , V_5 , V_84 ,
V_89 , V_90 ,
V_8 , V_9 ) )
return 0 ;
switch ( F_29 ( V_2 , V_3 , V_4 , V_5 , V_84 ,
V_91 , V_90 ,
V_8 , V_9 ) ) {
case 0 :
case - V_87 :
break;
default:
return 0 ;
}
return F_26 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static unsigned int F_33 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
struct V_57 * V_92 ,
struct V_57 * V_93 ,
unsigned int V_94 ,
unsigned int V_95 ,
union V_21 * V_96 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
enum V_24 V_25 = F_8 ( V_11 ) ;
T_4 V_23 ;
if ( V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 ==
V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 )
V_96 -> V_32 = V_92 -> V_29 . V_35 . V_31 . V_32 ;
else
V_96 -> V_32 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ;
V_92 -> V_70 = V_92 -> V_29 . V_35 . V_31 . V_32 ;
V_92 -> V_29 . V_35 . V_31 . V_32 = V_96 -> V_32 ;
V_92 -> V_67 . V_34 . V_23 = V_92 -> V_29 . V_35 . V_33 . V_34 . V_23 ;
V_92 -> V_25 = ! V_25 ;
V_92 -> V_76 = F_20 ;
V_93 -> V_70 = V_93 -> V_29 . V_35 . V_31 . V_32 ;
V_93 -> V_29 . V_35 . V_31 . V_32 = V_96 -> V_32 ;
V_93 -> V_67 . V_34 . V_23 = V_93 -> V_29 . V_35 . V_33 . V_34 . V_23 ;
V_93 -> V_25 = ! V_25 ;
V_93 -> V_76 = F_20 ;
for ( V_23 = F_9 ( V_92 -> V_29 . V_35 . V_33 . V_34 . V_23 ) ;
V_23 != 0 ; V_23 += 2 ) {
int V_77 ;
V_92 -> V_29 . V_35 . V_33 . V_34 . V_23 = F_17 ( V_23 ) ;
V_77 = F_24 ( V_92 ) ;
if ( V_77 == - V_78 )
continue;
else if ( V_77 < 0 ) {
V_23 = 0 ;
break;
}
V_93 -> V_29 . V_35 . V_33 . V_34 . V_23 = F_17 ( V_23 + 1 ) ;
V_77 = F_24 ( V_93 ) ;
if ( V_77 == 0 )
break;
else if ( V_77 == - V_78 ) {
F_25 ( V_92 ) ;
continue;
} else if ( V_77 < 0 ) {
F_25 ( V_92 ) ;
V_23 = 0 ;
break;
}
}
if ( V_23 == 0 )
goto V_97;
if ( V_92 -> V_29 . V_35 . V_33 . V_34 . V_23 != V_92 -> V_67 . V_34 . V_23 &&
! F_31 ( V_2 , V_3 , V_4 , V_5 ,
V_94 , V_95 , V_23 ) )
goto V_98;
return V_54 ;
V_98:
F_25 ( V_92 ) ;
F_25 ( V_93 ) ;
V_97:
return V_41 ;
}
static void T_5 F_34 ( void )
{
F_35 ( V_99 , NULL ) ;
F_35 ( V_100 , NULL ) ;
F_35 ( V_101 , NULL ) ;
F_35 ( V_102 , NULL ) ;
F_35 ( V_103 , NULL ) ;
F_35 ( V_104 , NULL ) ;
F_35 ( V_105 , NULL ) ;
F_36 ( & V_106 ) ;
F_37 () ;
}
static int T_6 F_38 ( void )
{
F_21 ( V_99 != NULL ) ;
F_21 ( V_100 != NULL ) ;
F_21 ( V_101 != NULL ) ;
F_21 ( V_102 != NULL ) ;
F_21 ( V_103 != NULL ) ;
F_21 ( V_104 != NULL ) ;
F_21 ( V_105 != NULL ) ;
F_35 ( V_99 , F_12 ) ;
F_35 ( V_100 , F_18 ) ;
F_35 ( V_101 , F_23 ) ;
F_35 ( V_102 , F_30 ) ;
F_35 ( V_103 , F_31 ) ;
F_35 ( V_104 , F_32 ) ;
F_35 ( V_105 , F_33 ) ;
F_39 ( & V_106 ) ;
return 0 ;
}

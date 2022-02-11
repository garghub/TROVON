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
unsigned int V_44 , V_45 , V_46 , V_9 , V_47 ;
char V_8 [ sizeof( L_1 ) ] ;
if ( V_39 ) {
if ( V_22 . V_32 != V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 ||
V_23 != V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 )
goto V_48;
} else {
if ( V_22 . V_32 != V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_31 . V_32 ||
V_23 != V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_33 . V_34 . V_23 )
goto V_48;
}
if ( ! F_7 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
& V_22 , V_23 ) )
return V_41 ;
V_44 = V_6 + V_7 ;
if ( F_15 ( V_13 , * V_4 , V_44 , * V_5 ,
L_4 , & V_45 , & V_46 ,
& V_22 ) > 0 &&
V_22 . V_32 == V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 &&
V_22 . V_32 != V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ) {
V_9 = sprintf ( V_8 , L_5 ,
& V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_45 , V_46 , V_8 , V_9 ) )
return V_41 ;
}
if ( F_15 ( V_13 , * V_4 , V_44 , * V_5 ,
L_6 , & V_45 , & V_46 ,
& V_22 ) > 0 &&
V_22 . V_32 == V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_31 . V_32 &&
V_22 . V_32 != V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_31 . V_32 ) {
V_9 = sprintf ( V_8 , L_5 ,
& V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_31 . V_32 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_45 , V_46 , V_8 , V_9 ) )
return V_41 ;
}
if ( F_16 ( V_13 , * V_4 , V_44 , * V_5 ,
L_7 , & V_45 , & V_46 ,
& V_47 ) > 0 &&
F_17 ( V_47 ) == V_13 -> V_28 [ V_25 ] . V_29 . V_35 . V_33 . V_34 . V_23 &&
F_17 ( V_47 ) != V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 ) {
T_1 V_49 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 ;
V_9 = sprintf ( V_8 , L_8 , F_9 ( V_49 ) ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_45 , V_46 , V_8 , V_9 ) )
return V_41 ;
}
}
V_48:
V_37 = 0 ;
V_40 = 0 ;
while ( F_11 ( V_13 , * V_4 , & V_37 , * V_5 ,
V_50 , & V_40 ,
& V_6 , & V_7 ,
& V_22 , & V_23 ) > 0 ) {
if ( ! F_7 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
& V_22 , V_23 ) )
return V_41 ;
}
if ( ! F_10 ( V_2 , V_3 , V_4 , V_5 , V_51 ) ||
! F_10 ( V_2 , V_3 , V_4 , V_5 , V_52 ) )
return V_41 ;
return V_53 ;
}
static void F_18 ( struct V_1 * V_2 , T_3 V_54 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
const struct V_14 * V_15 ;
if ( F_3 ( V_13 ) != V_17 || V_54 == 0 )
return;
V_15 = (struct V_14 * ) ( V_2 -> V_18 + F_4 ( V_2 ) ) ;
F_19 ( V_13 , V_11 , V_15 -> V_55 , V_54 ) ;
}
static void F_20 ( struct V_12 * V_13 ,
struct V_56 * exp )
{
struct V_57 V_58 ;
F_21 ( V_13 -> V_59 & V_60 ) ;
V_58 . V_61 = ( V_62 | V_63 ) ;
V_58 . V_64 = V_58 . V_65 = exp -> V_66 ;
V_58 . V_67 = V_58 . V_68 = exp -> V_69 ;
F_22 ( V_13 , & V_58 , V_70 ) ;
if ( V_13 -> V_28 [ V_71 ] . V_29 . V_30 . V_31 . V_32 ==
V_13 -> V_72 -> V_28 [ exp -> V_25 ] . V_29 . V_30 . V_31 . V_32 ) {
V_58 . V_61 = V_62 ;
V_58 . V_67 = V_58 . V_68
= V_13 -> V_72 -> V_28 [ ! exp -> V_25 ] . V_29 . V_35 . V_31 . V_32 ;
F_22 ( V_13 , & V_58 , V_73 ) ;
}
}
static unsigned int F_23 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
struct V_56 * exp ,
unsigned int V_6 ,
unsigned int V_7 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
enum V_24 V_25 = F_8 ( V_11 ) ;
T_2 V_74 ;
T_4 V_23 ;
char V_8 [ sizeof( L_1 ) ] ;
unsigned int V_9 ;
if ( V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 == V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 )
V_74 = exp -> V_29 . V_35 . V_31 . V_32 ;
else
V_74 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ;
if ( exp -> V_29 . V_35 . V_33 . V_34 . V_23 ==
V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_33 . V_34 . V_23 )
V_23 = F_9 ( V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_33 . V_34 . V_23 ) ;
else
V_23 = F_9 ( exp -> V_29 . V_35 . V_33 . V_34 . V_23 ) ;
exp -> V_69 = exp -> V_29 . V_35 . V_31 . V_32 ;
exp -> V_29 . V_35 . V_31 . V_32 = V_74 ;
exp -> V_66 . V_34 . V_23 = exp -> V_29 . V_35 . V_33 . V_34 . V_23 ;
exp -> V_25 = ! V_25 ;
exp -> V_75 = F_20 ;
for (; V_23 != 0 ; V_23 ++ ) {
int V_76 ;
exp -> V_29 . V_35 . V_33 . V_34 . V_23 = F_17 ( V_23 ) ;
V_76 = F_24 ( exp ) ;
if ( V_76 == 0 )
break;
else if ( V_76 != - V_77 ) {
V_23 = 0 ;
break;
}
}
if ( V_23 == 0 )
return V_41 ;
if ( exp -> V_29 . V_35 . V_31 . V_32 != exp -> V_69 ||
exp -> V_29 . V_35 . V_33 . V_34 . V_23 != exp -> V_66 . V_34 . V_23 ) {
V_9 = sprintf ( V_8 , L_2 , & V_74 , V_23 ) ;
if ( ! F_1 ( V_2 , V_3 , V_4 , V_5 ,
V_6 , V_7 , V_8 , V_9 ) )
goto V_78;
}
return V_53 ;
V_78:
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
int V_9 , V_79 ;
if ( F_27 ( V_13 , * V_4 , 0 , * V_5 ,
V_80 , V_81 ,
& V_6 , & V_7 ) <= 0 )
return 0 ;
V_79 = * V_5 - V_6 + strlen ( L_10 ) ;
if ( F_28 ( V_13 , * V_4 , 0 , * V_5 , V_82 ,
& V_6 , & V_7 ) <= 0 )
return 0 ;
V_9 = sprintf ( V_8 , L_8 , V_79 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
unsigned int V_83 ,
enum V_84 type ,
enum V_84 V_85 ,
char * V_8 , int V_9 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
unsigned int V_7 , V_6 ;
if ( F_27 ( V_13 , * V_4 , V_83 , * V_5 , type , V_85 ,
& V_6 , & V_7 ) <= 0 )
return - V_86 ;
return F_1 ( V_2 , V_3 , V_4 , V_5 , V_6 , V_7 ,
V_8 , V_9 ) ? 0 : - V_87 ;
}
static unsigned int F_30 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
unsigned int V_83 ,
enum V_84 type ,
enum V_84 V_85 ,
const union V_21 * V_22 )
{
char V_8 [ sizeof( L_11 ) ] ;
unsigned int V_9 ;
V_9 = sprintf ( V_8 , L_5 , & V_22 -> V_32 ) ;
if ( F_29 ( V_2 , V_3 , V_4 , V_5 , V_83 , type , V_85 ,
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
unsigned int V_83 ,
const union V_21 * V_22 )
{
char V_8 [ sizeof( L_11 ) ] ;
unsigned int V_9 ;
V_9 = sprintf ( V_8 , L_5 , & V_22 -> V_32 ) ;
if ( F_29 ( V_2 , V_3 , V_4 , V_5 , V_83 ,
V_88 , V_89 ,
V_8 , V_9 ) )
return 0 ;
switch ( F_29 ( V_2 , V_3 , V_4 , V_5 , V_83 ,
V_90 , V_89 ,
V_8 , V_9 ) ) {
case 0 :
case - V_86 :
break;
default:
return 0 ;
}
return F_26 ( V_2 , V_3 , V_4 , V_5 ) ;
}
static unsigned int F_33 ( struct V_1 * V_2 , unsigned int V_3 ,
const char * * V_4 , unsigned int * V_5 ,
struct V_56 * V_91 ,
struct V_56 * V_92 ,
unsigned int V_93 ,
unsigned int V_94 ,
union V_21 * V_95 )
{
enum V_10 V_11 ;
struct V_12 * V_13 = F_2 ( V_2 , & V_11 ) ;
enum V_24 V_25 = F_8 ( V_11 ) ;
T_4 V_23 ;
if ( V_13 -> V_28 [ V_25 ] . V_29 . V_30 . V_31 . V_32 ==
V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 )
V_95 -> V_32 = V_91 -> V_29 . V_35 . V_31 . V_32 ;
else
V_95 -> V_32 = V_13 -> V_28 [ ! V_25 ] . V_29 . V_35 . V_31 . V_32 ;
V_91 -> V_69 = V_91 -> V_29 . V_35 . V_31 . V_32 ;
V_91 -> V_29 . V_35 . V_31 . V_32 = V_95 -> V_32 ;
V_91 -> V_66 . V_34 . V_23 = V_91 -> V_29 . V_35 . V_33 . V_34 . V_23 ;
V_91 -> V_25 = ! V_25 ;
V_91 -> V_75 = F_20 ;
V_92 -> V_69 = V_92 -> V_29 . V_35 . V_31 . V_32 ;
V_92 -> V_29 . V_35 . V_31 . V_32 = V_95 -> V_32 ;
V_92 -> V_66 . V_34 . V_23 = V_92 -> V_29 . V_35 . V_33 . V_34 . V_23 ;
V_92 -> V_25 = ! V_25 ;
V_92 -> V_75 = F_20 ;
for ( V_23 = F_9 ( V_91 -> V_29 . V_35 . V_33 . V_34 . V_23 ) ;
V_23 != 0 ; V_23 += 2 ) {
int V_76 ;
V_91 -> V_29 . V_35 . V_33 . V_34 . V_23 = F_17 ( V_23 ) ;
V_76 = F_24 ( V_91 ) ;
if ( V_76 == - V_77 )
continue;
else if ( V_76 < 0 ) {
V_23 = 0 ;
break;
}
V_92 -> V_29 . V_35 . V_33 . V_34 . V_23 = F_17 ( V_23 + 1 ) ;
V_76 = F_24 ( V_92 ) ;
if ( V_76 == 0 )
break;
else if ( V_76 != - V_77 ) {
F_25 ( V_91 ) ;
V_23 = 0 ;
break;
}
}
if ( V_23 == 0 )
goto V_96;
if ( V_91 -> V_29 . V_35 . V_33 . V_34 . V_23 != V_91 -> V_66 . V_34 . V_23 &&
! F_31 ( V_2 , V_3 , V_4 , V_5 ,
V_93 , V_94 , V_23 ) )
goto V_97;
return V_53 ;
V_97:
F_25 ( V_91 ) ;
F_25 ( V_92 ) ;
V_96:
return V_41 ;
}
static void T_5 F_34 ( void )
{
F_35 ( V_98 , NULL ) ;
F_35 ( V_99 , NULL ) ;
F_35 ( V_100 , NULL ) ;
F_35 ( V_101 , NULL ) ;
F_35 ( V_102 , NULL ) ;
F_35 ( V_103 , NULL ) ;
F_35 ( V_104 , NULL ) ;
F_36 ( & V_105 ) ;
F_37 () ;
}
static int T_6 F_38 ( void )
{
F_21 ( V_98 != NULL ) ;
F_21 ( V_99 != NULL ) ;
F_21 ( V_100 != NULL ) ;
F_21 ( V_101 != NULL ) ;
F_21 ( V_102 != NULL ) ;
F_21 ( V_103 != NULL ) ;
F_21 ( V_104 != NULL ) ;
F_35 ( V_98 , F_12 ) ;
F_35 ( V_99 , F_18 ) ;
F_35 ( V_100 , F_23 ) ;
F_35 ( V_101 , F_30 ) ;
F_35 ( V_102 , F_31 ) ;
F_35 ( V_103 , F_32 ) ;
F_35 ( V_104 , F_33 ) ;
F_39 ( & V_105 ) ;
return 0 ;
}

static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_1 , V_10 , V_4 ) ;
switch ( V_5 ) {
case V_11 :
F_3 ( V_12 , & V_4 -> V_13 ) ;
break;
case V_14 :
F_3 ( V_15 , & V_4 -> V_13 ) ;
F_4 (ireq, &idev->reqs_in_process, dev_node) {
F_2 ( & V_2 -> V_8 -> V_9 ,
L_2 ,
V_10 , V_4 , V_7 ) ;
F_5 ( V_2 ,
V_4 ,
V_7 ) ;
}
default:
F_6 ( V_16 , & V_4 -> V_13 ) ;
break;
}
}
static void F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_8 -> V_9 ,
L_3 , V_10 , V_4 ) ;
F_6 ( V_15 , & V_4 -> V_13 ) ;
F_3 ( V_16 , & V_4 -> V_13 ) ;
if ( F_8 ( V_17 , & V_4 -> V_13 ) )
F_9 ( & V_2 -> V_18 ) ;
}
static void F_10 ( void * V_19 )
{
struct V_3 * V_4 = V_19 ;
F_11 ( V_4 -> V_20 != 0 ) ;
F_12 ( & V_4 -> V_21 , V_22 ) ;
}
static enum V_23 F_13 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
enum V_23 V_26 = V_27 ;
T_1 V_28 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
struct V_6 * V_7 = V_2 -> V_30 [ V_28 ] ;
enum V_23 V_31 ;
if ( ! F_14 ( V_32 , & V_7 -> V_13 ) ||
V_7 -> V_33 != V_4 )
continue;
V_31 = F_5 ( V_2 , V_4 , V_7 ) ;
if ( V_31 != V_27 )
V_26 = V_31 ;
}
return V_26 ;
}
enum V_23 F_15 ( struct V_3 * V_4 ,
T_1 V_34 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
switch ( V_37 ) {
case V_39 :
case V_40 :
case V_41 :
default:
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
case V_22 :
return V_27 ;
case V_43 :
F_11 ( V_4 -> V_20 != 0 ) ;
F_18 ( & V_4 -> V_44 ,
F_10 , V_4 ) ;
F_12 ( V_21 , V_45 ) ;
return V_27 ;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
F_12 ( V_21 , V_45 ) ;
if ( V_4 -> V_20 == 0 ) {
F_18 ( & V_4 -> V_44 ,
F_10 , V_4 ) ;
return V_27 ;
} else
return F_13 ( V_4 ) ;
break;
case V_45 :
return F_13 ( V_4 ) ;
case V_54 :
F_12 ( V_21 , V_45 ) ;
return V_27 ;
}
}
enum V_23 F_19 ( struct V_3 * V_4 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
switch ( V_37 ) {
case V_39 :
case V_22 :
case V_43 :
case V_52 :
case V_53 :
case V_45 :
case V_40 :
case V_54 :
case V_41 :
default:
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
F_12 ( V_21 , V_54 ) ;
return V_27 ;
}
}
enum V_23 F_20 ( struct V_3 * V_4 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
if ( V_37 != V_54 ) {
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
}
F_12 ( V_21 , V_46 ) ;
return V_27 ;
}
enum V_23 F_21 ( struct V_3 * V_4 ,
T_1 V_55 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
if ( V_37 != V_48 ) {
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
}
return F_22 ( & V_4 -> V_44 ,
V_55 , NULL , NULL ) ;
}
enum V_23 F_23 ( struct V_3 * V_4 ,
T_1 V_56 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
enum V_23 V_26 ;
switch ( V_37 ) {
case V_39 :
case V_22 :
case V_43 :
case V_47 :
case V_52 :
case V_41 :
default:
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
F_24 ( V_2 , V_56 ) ;
return V_42 ;
case V_46 :
case V_50 :
case V_51 :
case V_45 :
case V_40 :
case V_54 : {
struct V_6 * V_7 ;
struct V_57 V_58 ;
void * V_59 ;
T_2 V_60 ;
V_26 = F_25 ( & V_2 -> V_61 ,
V_56 ,
& V_59 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_60 = sizeof( V_58 ) / sizeof( T_1 ) ;
F_26 ( & V_58 , V_59 , V_60 ) ;
V_7 = F_27 ( V_2 , F_28 ( V_58 . V_62 ) ) ;
if ( V_7 && V_7 -> V_33 == V_4 ) {
V_26 = F_29 ( V_7 , V_56 ) ;
} else {
F_24 ( V_2 , V_56 ) ;
}
break;
}
case V_49 : {
struct V_63 * V_58 ;
V_26 = F_25 ( & V_2 -> V_61 ,
V_56 ,
( void * * ) & V_58 ) ;
if ( V_26 != V_27 )
return V_26 ;
if ( V_58 -> V_64 == V_65 &&
( V_58 -> V_26 & V_66 ) ) {
V_4 -> V_67 = V_14 ;
F_12 ( V_21 , V_50 ) ;
} else if ( V_58 -> V_64 == V_68 &&
( V_58 -> V_26 & V_66 ) ) {
V_4 -> V_67 = V_14 ;
F_12 ( & V_4 -> V_21 , V_50 ) ;
} else
V_26 = V_69 ;
F_24 ( V_2 , V_56 ) ;
break;
}
case V_48 :
case V_53 :
V_26 = F_29 ( V_4 -> V_70 , V_56 ) ;
break;
}
return V_26 ;
}
static bool F_30 ( struct V_3 * V_4 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
switch ( V_37 ) {
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return true ;
default:
return false ;
}
}
static void F_31 ( void * V_19 )
{
struct V_3 * V_4 = V_19 ;
struct V_6 * V_7 = V_4 -> V_70 ;
F_12 ( & V_7 -> V_21 , V_71 ) ;
}
enum V_23 F_32 ( struct V_3 * V_4 ,
T_1 V_72 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
enum V_23 V_26 ;
switch ( F_33 ( V_72 ) ) {
case V_73 :
case V_74 :
case V_75 :
V_26 = F_34 ( & V_4 -> V_44 , V_72 ) ;
break;
case V_76 :
if ( F_35 ( V_72 ) == V_77 ) {
V_26 = V_27 ;
F_22 ( & V_4 -> V_44 ,
V_78 ,
NULL , NULL ) ;
F_2 ( F_17 ( V_4 ) ,
L_5 ,
V_10 , V_4 , V_72 ,
F_30 ( V_4 )
? L_6
: L_7 ) ;
break;
}
default:
F_2 ( F_17 ( V_4 ) ,
L_5 ,
V_10 , V_4 , V_72 ,
F_30 ( V_4 )
? L_8
: L_9 ) ;
V_26 = V_42 ;
break;
}
if ( V_26 != V_27 )
return V_26 ;
if ( V_37 == V_79 ) {
if ( F_33 ( V_72 ) == V_74 ||
F_33 ( V_72 ) == V_75 ) {
return F_36 ( & V_4 -> V_44 ,
F_31 ,
V_4 ) ;
}
}
if ( V_37 == V_47 ) {
if ( F_33 ( V_72 ) == V_74 ||
F_33 ( V_72 ) == V_75 )
V_26 = F_36 ( & V_4 -> V_44 , NULL , NULL ) ;
}
return V_26 ;
}
static void F_37 ( struct V_3 * V_4 ,
struct V_6 * V_7 ,
enum V_23 V_26 )
{
struct V_80 * V_81 = V_4 -> V_24 ;
if ( V_26 != V_27 )
F_38 ( V_81 , V_4 , V_7 ) ;
else {
F_39 ( & V_4 -> V_82 ) ;
V_4 -> V_20 ++ ;
}
}
enum V_23 F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
struct V_80 * V_81 = V_4 -> V_24 ;
enum V_23 V_26 ;
switch ( V_37 ) {
case V_39 :
case V_22 :
case V_43 :
case V_50 :
case V_45 :
case V_40 :
case V_54 :
case V_41 :
default:
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
case V_46 :
V_26 = F_41 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_42 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_43 ( V_7 ) ;
break;
case V_47 : {
enum V_36 V_83 ;
struct V_84 * V_85 = F_44 ( V_7 ) ;
V_26 = F_41 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_42 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_43 ( V_7 ) ;
if ( V_26 != V_27 )
break;
if ( V_85 -> V_86 . V_87 )
V_83 = V_49 ;
else {
V_4 -> V_70 = V_7 ;
V_83 = V_48 ;
}
F_12 ( V_21 , V_83 ) ;
break;
}
case V_49 : {
struct V_84 * V_85 = F_44 ( V_7 ) ;
if ( V_85 -> V_86 . V_87 ) {
V_26 = F_41 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_42 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_43 ( V_7 ) ;
} else
return V_42 ;
break;
}
case V_51 :
return V_88 ;
case V_52 :
V_26 = F_41 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_42 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_43 ( V_7 ) ;
if ( V_26 != V_27 )
break;
V_4 -> V_70 = V_7 ;
F_12 ( & V_4 -> V_21 , V_53 ) ;
break;
case V_48 :
case V_53 :
return V_42 ;
}
F_37 ( V_4 , V_7 , V_26 ) ;
return V_26 ;
}
static enum V_23 F_45 ( struct V_80 * V_81 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
enum V_23 V_26 ;
V_26 = F_46 ( V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_38 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
F_47 ( V_4 ) ;
return V_26 ;
}
enum V_23 F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
struct V_80 * V_81 = V_4 -> V_24 ;
enum V_23 V_26 ;
switch ( V_37 ) {
case V_39 :
case V_22 :
case V_43 :
case V_47 :
case V_52 :
case V_40 :
case V_41 :
default:
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
case V_46 :
case V_51 :
case V_54 :
V_26 = F_45 ( V_81 , V_4 , V_7 ) ;
break;
case V_48 :
case V_49 :
case V_50 :
case V_79 :
V_26 = F_45 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
break;
if ( V_7 -> V_23 == V_88 ) {
F_12 ( V_21 , V_51 ) ;
} else if ( V_4 -> V_20 == 0 )
F_12 ( V_21 , V_47 ) ;
break;
case V_53 :
V_26 = F_45 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
break;
F_12 ( V_21 , V_52 ) ;
break;
case V_45 :
V_26 = F_45 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
break;
if ( V_4 -> V_20 == 0 )
F_18 ( & V_4 -> V_44 ,
F_10 ,
V_4 ) ;
break;
}
if ( V_26 != V_27 )
F_49 ( F_17 ( V_4 ) ,
L_10
L_11 , V_10 , V_81 ,
V_4 , V_7 , V_26 ) ;
else
F_50 ( V_4 ) ;
return V_26 ;
}
static void F_51 ( void * V_9 )
{
struct V_3 * V_4 = V_9 ;
if ( V_4 -> V_70 )
F_52 ( V_4 -> V_70 ) ;
}
enum V_23 F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
struct V_80 * V_81 = V_4 -> V_24 ;
enum V_23 V_26 ;
switch ( V_37 ) {
case V_39 :
case V_22 :
case V_43 :
case V_52 :
case V_53 :
case V_45 :
case V_40 :
case V_54 :
case V_41 :
default:
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
V_26 = F_41 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_54 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
goto V_89;
V_26 = F_43 ( V_7 ) ;
if ( V_26 != V_27 )
goto V_89;
V_4 -> V_70 = V_7 ;
F_12 ( V_21 , V_48 ) ;
F_22 ( & V_4 -> V_44 ,
V_78 , NULL , NULL ) ;
F_36 ( & V_4 -> V_44 ,
F_51 ,
V_4 ) ;
V_89:
F_37 ( V_4 , V_7 , V_26 ) ;
return V_90 ;
case V_46 :
V_26 = F_41 ( V_81 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_54 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_43 ( V_7 ) ;
break;
}
F_37 ( V_4 , V_7 , V_26 ) ;
return V_26 ;
}
void F_55 ( struct V_3 * V_4 , T_1 V_91 )
{
struct V_80 * V_81 = V_4 -> V_24 ;
T_1 V_92 ;
V_92 = V_91 |
( V_93 << V_94 ) |
( V_81 -> V_95 << V_96 ) |
V_4 -> V_44 . V_97 ;
F_56 ( V_81 -> V_25 , V_92 ) ;
}
static void F_57 ( void * V_19 )
{
struct V_3 * V_4 = V_19 ;
if ( F_30 ( V_4 ) )
return;
F_12 ( & V_4 -> V_21 , V_46 ) ;
}
static void F_58 ( void * V_19 )
{
struct V_3 * V_4 = V_19 ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
if ( V_4 -> V_21 . V_98 != V_49 )
F_7 ( V_2 , V_4 ) ;
}
static void F_59 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
F_12 ( & V_4 -> V_21 , V_22 ) ;
}
static enum V_23 F_62 ( struct V_3 * V_4 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
struct V_1 * V_2 ;
if ( V_37 != V_22 ) {
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
}
V_2 = V_4 -> V_24 -> V_25 ;
F_63 ( V_2 , V_4 ,
V_4 -> V_44 . V_97 ) ;
V_4 -> V_44 . V_97 = V_99 ;
F_12 ( V_21 , V_41 ) ;
return V_27 ;
}
static void F_64 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_8 -> V_9 ,
L_1 , V_10 , V_4 ) ;
F_11 ( ! F_65 ( & V_4 -> V_100 ) ) ;
F_62 ( V_4 ) ;
F_66 ( & V_4 -> V_101 ) ;
F_50 ( V_4 ) ;
}
static void F_67 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
T_1 V_102 ;
V_102 = V_4 -> V_21 . V_98 ;
if ( V_102 == V_45 )
F_64 ( V_2 , V_4 ) ;
F_68 ( V_2 , V_4 ) ;
}
static void F_69 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_1 ( V_2 , V_4 ,
V_103 ) ;
}
static void F_70 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
struct V_104 * V_9 = V_4 -> V_105 ;
if ( V_9 -> V_106 == V_107 || ( V_9 -> V_108 & V_109 ) ) {
F_12 ( & V_4 -> V_21 , V_47 ) ;
} else if ( F_71 ( V_9 ) ) {
F_12 ( & V_4 -> V_21 , V_52 ) ;
} else
F_7 ( V_2 , V_4 ) ;
}
static void F_72 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
struct V_104 * V_9 = V_4 -> V_105 ;
if ( V_9 -> V_106 == V_110 ) {
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_1 ( V_2 , V_4 ,
V_11 ) ;
}
}
static void F_73 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
F_22 (
& V_4 -> V_44 , V_78 , NULL , NULL ) ;
}
static void F_74 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
F_36 ( & V_4 -> V_44 , NULL , NULL ) ;
}
static void F_75 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
V_4 -> V_70 = NULL ;
if ( F_76 ( & V_4 -> V_44 ) ) {
F_58 ( V_4 ) ;
} else {
F_36 ( & V_4 -> V_44 ,
F_58 ,
V_4 ) ;
}
}
static void F_77 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_11 ( V_4 -> V_70 == NULL ) ;
F_1 ( V_2 , V_4 ,
V_111 ) ;
}
static void F_78 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
if ( V_4 -> V_67 == V_14 )
F_1 ( V_2 , V_4 ,
V_4 -> V_67 ) ;
}
static void F_79 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_7 ( V_2 , V_4 ) ;
}
static void F_80 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_11 ( V_4 -> V_70 == NULL ) ;
F_1 ( V_2 , V_4 ,
V_112 ) ;
}
static void F_81 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_60 ( V_21 , F_61 ( * V_4 ) , V_21 ) ;
V_4 -> V_70 = NULL ;
}
static void F_82 ( struct V_80 * V_81 ,
struct V_3 * V_4 )
{
V_4 -> V_24 = V_81 ;
V_4 -> V_20 = 0 ;
F_83 ( & V_4 -> V_21 , V_113 , V_39 ) ;
F_84 ( & V_4 -> V_44 ,
V_99 ) ;
}
static enum V_23 F_85 ( struct V_80 * V_81 ,
struct V_3 * V_4 )
{
enum V_23 V_26 ;
struct V_114 V_115 ;
struct V_104 * V_9 = V_4 -> V_105 ;
F_82 ( V_81 , V_4 ) ;
V_4 -> V_116 = true ;
F_86 ( V_81 , & V_115 ) ;
V_4 -> V_117 = F_87 ( V_115 . V_118 ) ;
V_26 = F_88 ( V_81 -> V_25 ,
V_4 ,
& V_4 -> V_44 . V_97 ) ;
if ( V_26 != V_27 )
return V_26 ;
if ( V_9 -> V_106 == V_110 || V_9 -> V_106 == V_107 ||
( V_9 -> V_108 & V_119 ) || F_71 ( V_9 ) )
;
else
return V_120 ;
V_4 -> V_121 = F_89 ( V_81 ) ;
return V_27 ;
}
static enum V_23 F_90 ( struct V_80 * V_81 ,
struct V_3 * V_4 )
{
struct V_104 * V_9 = V_4 -> V_105 ;
enum V_23 V_26 ;
F_82 ( V_81 , V_4 ) ;
V_26 = F_88 ( V_81 -> V_25 ,
V_4 ,
& V_4 -> V_44 . V_97 ) ;
if ( V_26 != V_27 )
return V_26 ;
if ( V_9 -> V_106 == V_110 || V_9 -> V_106 == V_107 ||
( V_9 -> V_108 & V_119 ) || F_71 ( V_9 ) )
;
else
return V_120 ;
V_4 -> V_121 = F_91 ( V_122 , F_89 ( V_81 ) ,
V_9 -> V_123 ) ;
V_4 -> V_117 = 1 ;
return V_27 ;
}
static enum V_23 F_92 ( struct V_3 * V_4 ,
T_1 V_34 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
enum V_23 V_26 ;
if ( V_37 != V_22 ) {
F_16 ( F_17 ( V_4 ) , L_4 ,
V_10 , V_37 ) ;
return V_42 ;
}
V_26 = F_36 ( & V_4 -> V_44 ,
F_57 ,
V_4 ) ;
if ( V_26 != V_27 )
return V_26 ;
F_12 ( V_21 , V_43 ) ;
return V_27 ;
}
static enum V_23 F_93 ( struct V_80 * V_81 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_81 -> V_1 ;
struct V_104 * V_9 = V_4 -> V_105 ;
enum V_23 V_26 ;
if ( V_9 -> V_124 && F_71 ( V_9 -> V_124 ) )
V_26 = F_90 ( V_81 , V_4 ) ;
else
V_26 = F_85 ( V_81 , V_4 ) ;
if ( V_26 != V_27 ) {
F_2 ( & V_2 -> V_8 -> V_9 , L_12 ,
V_10 , V_26 ) ;
return V_26 ;
}
V_26 = F_92 ( V_4 , V_125 ) ;
if ( V_26 != V_27 )
F_16 ( & V_2 -> V_8 -> V_9 , L_13 ,
V_26 ) ;
return V_26 ;
}
void F_94 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_95 ( V_126 ) ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_3 , V_10 , V_4 ) ;
F_96 ( V_2 , V_4 ) ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_14 , V_10 , V_4 ) ;
}
static struct V_3 *
F_97 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_3 * V_4 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_127 ; V_28 ++ ) {
V_4 = & V_2 -> V_128 [ V_28 ] ;
if ( ! F_98 ( V_129 , & V_4 -> V_13 ) )
break;
}
if ( V_28 >= V_127 ) {
F_16 ( & V_2 -> V_8 -> V_9 , L_15 , V_10 ) ;
return NULL ;
}
if ( F_99 ( ! F_65 ( & V_4 -> V_100 ) , L_16 ) )
return NULL ;
if ( F_99 ( ! F_65 ( & V_4 -> V_101 ) , L_17 ) )
return NULL ;
return V_4 ;
}
void F_100 ( struct V_82 * V_82 )
{
struct V_3 * V_4 = F_60 ( V_82 , F_61 ( * V_4 ) , V_82 ) ;
struct V_1 * V_2 = V_4 -> V_80 -> V_1 ;
V_4 -> V_105 = NULL ;
V_4 -> V_80 = NULL ;
F_6 ( V_17 , & V_4 -> V_13 ) ;
F_6 ( V_130 , & V_4 -> V_13 ) ;
F_6 ( V_16 , & V_4 -> V_13 ) ;
F_6 ( V_12 , & V_4 -> V_13 ) ;
F_6 ( V_131 , & V_4 -> V_13 ) ;
F_101 () ;
F_6 ( V_129 , & V_4 -> V_13 ) ;
F_9 ( & V_2 -> V_18 ) ;
}
enum V_23 F_102 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
enum V_23 V_26 ;
unsigned long V_13 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_1 , V_10 , V_4 ) ;
F_103 ( & V_2 -> V_132 , V_13 ) ;
V_4 -> V_105 -> V_133 = NULL ;
F_3 ( V_12 , & V_4 -> V_13 ) ;
F_104 ( & V_2 -> V_132 , V_13 ) ;
F_94 ( V_2 , V_4 ) ;
F_3 ( V_130 , & V_4 -> V_13 ) ;
F_103 ( & V_2 -> V_132 , V_13 ) ;
V_26 = F_15 ( V_4 , 50 ) ;
F_104 ( & V_2 -> V_132 , V_13 ) ;
if ( F_99 ( V_26 != V_27 , L_18 ) )
;
else
F_105 ( V_2 , V_4 ) ;
return V_26 ;
}
void F_106 ( struct V_104 * V_9 )
{
struct V_1 * V_2 = F_107 ( V_9 ) ;
struct V_3 * V_4 = V_9 -> V_133 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_19 ,
V_10 , V_9 , V_4 , V_4 -> V_80 ) ;
F_102 ( V_2 , V_4 ) ;
}
int F_108 ( struct V_104 * V_105 )
{
struct V_1 * V_1 = F_107 ( V_105 ) ;
struct V_80 * V_80 ;
struct V_134 * V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_3 * V_139 ;
enum V_23 V_26 ;
F_2 ( & V_1 -> V_8 -> V_9 ,
L_20 , V_10 , V_105 ) ;
F_109 ( V_1 ) ;
V_136 = V_105 -> V_140 ;
V_138 = F_110 ( & V_136 -> V_141 , struct V_137 ,
V_142 ) ;
V_134 = F_111 ( V_138 ) ;
V_80 = V_134 -> V_80 ;
F_112 ( & V_80 -> V_143 ) ;
if ( ( V_144 == F_113 ( V_80 ) ) ||
( V_145 == F_113 ( V_80 ) ) )
return - V_146 ;
V_139 = F_97 ( V_1 , V_80 ) ;
if ( ! V_139 )
return - V_146 ;
F_114 ( & V_139 -> V_82 ) ;
F_115 ( & V_139 -> V_101 ) ;
F_116 ( & V_1 -> V_132 ) ;
V_139 -> V_105 = V_105 ;
V_139 -> V_80 = V_80 ;
F_117 ( & V_139 -> V_101 , & V_80 -> V_147 ) ;
F_3 ( V_17 , & V_139 -> V_13 ) ;
V_26 = F_93 ( V_80 , V_139 ) ;
F_2 ( & V_1 -> V_8 -> V_9 ,
L_1 ,
V_10 , V_139 ) ;
if ( V_26 == V_27 ) {
V_105 -> V_133 = V_139 ;
} else
F_50 ( V_139 ) ;
F_118 ( & V_1 -> V_132 ) ;
F_119 ( V_1 , V_139 ) ;
return V_26 == V_27 ? 0 : - V_146 ;
}

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
enum V_23 F_31 ( struct V_3 * V_4 ,
T_1 V_71 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
enum V_23 V_26 ;
switch ( F_32 ( V_71 ) ) {
case V_72 :
case V_73 :
case V_74 :
V_26 = F_33 ( & V_4 -> V_44 , V_71 ) ;
break;
case V_75 :
if ( F_34 ( V_71 ) == V_76 ) {
V_26 = V_27 ;
F_22 ( & V_4 -> V_44 ,
V_77 ,
NULL , NULL ) ;
F_2 ( F_17 ( V_4 ) ,
L_5 ,
V_10 , V_4 , V_71 ,
F_30 ( V_4 )
? L_6
: L_7 ) ;
break;
}
default:
F_2 ( F_17 ( V_4 ) ,
L_5 ,
V_10 , V_4 , V_71 ,
F_30 ( V_4 )
? L_8
: L_9 ) ;
V_26 = V_42 ;
break;
}
if ( V_26 != V_27 )
return V_26 ;
if ( V_37 == V_47 ) {
if ( F_32 ( V_71 ) == V_73 ||
F_32 ( V_71 ) == V_74 )
V_26 = F_35 ( & V_4 -> V_44 , NULL , NULL ) ;
}
return V_26 ;
}
static void F_36 ( struct V_3 * V_4 ,
struct V_6 * V_7 ,
enum V_23 V_26 )
{
struct V_78 * V_79 = V_4 -> V_24 ;
if ( V_26 != V_27 )
F_37 ( V_79 , V_4 , V_7 ) ;
else {
F_38 ( & V_4 -> V_80 ) ;
V_4 -> V_20 ++ ;
}
}
enum V_23 F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
struct V_78 * V_79 = V_4 -> V_24 ;
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
V_26 = F_40 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_41 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_42 ( V_7 ) ;
break;
case V_47 : {
enum V_36 V_81 ;
struct V_82 * V_83 = F_43 ( V_7 ) ;
V_26 = F_40 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_41 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_42 ( V_7 ) ;
if ( V_26 != V_27 )
break;
if ( V_83 -> V_84 . V_85 )
V_81 = V_49 ;
else {
V_4 -> V_70 = V_7 ;
V_81 = V_48 ;
}
F_12 ( V_21 , V_81 ) ;
break;
}
case V_49 : {
struct V_82 * V_83 = F_43 ( V_7 ) ;
if ( V_83 -> V_84 . V_85 ) {
V_26 = F_40 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_41 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_42 ( V_7 ) ;
} else
return V_42 ;
break;
}
case V_51 :
return V_86 ;
case V_52 :
V_26 = F_40 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_41 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_42 ( V_7 ) ;
if ( V_26 != V_27 )
break;
V_4 -> V_70 = V_7 ;
F_12 ( & V_4 -> V_21 , V_53 ) ;
break;
case V_48 :
case V_53 :
return V_42 ;
}
F_36 ( V_4 , V_7 , V_26 ) ;
return V_26 ;
}
static enum V_23 F_44 ( struct V_78 * V_79 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
enum V_23 V_26 ;
V_26 = F_45 ( V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_37 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
F_46 ( V_4 ) ;
return V_26 ;
}
enum V_23 F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
struct V_78 * V_79 = V_4 -> V_24 ;
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
V_26 = F_44 ( V_79 , V_4 , V_7 ) ;
break;
case V_48 :
case V_49 :
case V_50 :
V_26 = F_44 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
break;
if ( V_7 -> V_23 == V_86 ) {
F_12 ( V_21 , V_51 ) ;
} else if ( V_4 -> V_20 == 0 )
F_12 ( V_21 , V_47 ) ;
break;
case V_53 :
V_26 = F_44 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
break;
F_12 ( V_21 , V_52 ) ;
break;
case V_45 :
V_26 = F_44 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
break;
if ( V_4 -> V_20 == 0 )
F_18 ( & V_4 -> V_44 ,
F_10 ,
V_4 ) ;
break;
}
if ( V_26 != V_27 )
F_48 ( F_17 ( V_4 ) ,
L_10
L_11 , V_10 , V_79 ,
V_4 , V_7 , V_26 ) ;
else
F_49 ( V_4 ) ;
return V_26 ;
}
static void F_50 ( void * V_9 )
{
struct V_3 * V_4 = V_9 ;
if ( V_4 -> V_70 )
F_51 ( V_4 -> V_70 ) ;
}
enum V_23 F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_6 * V_7 )
{
struct V_35 * V_21 = & V_4 -> V_21 ;
enum V_36 V_37 = V_21 -> V_38 ;
struct V_78 * V_79 = V_4 -> V_24 ;
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
V_26 = F_40 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_53 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
goto V_87;
V_26 = F_42 ( V_7 ) ;
if ( V_26 != V_27 )
goto V_87;
V_4 -> V_70 = V_7 ;
F_12 ( V_21 , V_48 ) ;
F_22 ( & V_4 -> V_44 ,
V_77 , NULL , NULL ) ;
F_35 ( & V_4 -> V_44 ,
F_50 ,
V_4 ) ;
V_87:
F_36 ( V_4 , V_7 , V_26 ) ;
return V_88 ;
case V_46 :
V_26 = F_40 ( V_79 , V_4 , V_7 ) ;
if ( V_26 != V_27 )
return V_26 ;
V_26 = F_53 ( & V_4 -> V_44 , V_7 ) ;
if ( V_26 != V_27 )
break;
V_26 = F_42 ( V_7 ) ;
break;
}
F_36 ( V_4 , V_7 , V_26 ) ;
return V_26 ;
}
void F_54 ( struct V_3 * V_4 , T_1 V_89 )
{
struct V_78 * V_79 = V_4 -> V_24 ;
T_1 V_90 ;
V_90 = V_89 |
( V_91 << V_92 ) |
( V_79 -> V_93 << V_94 ) |
V_4 -> V_44 . V_95 ;
F_55 ( V_79 -> V_25 , V_90 ) ;
}
static void F_56 ( void * V_19 )
{
struct V_3 * V_4 = V_19 ;
if ( F_30 ( V_4 ) )
return;
F_12 ( & V_4 -> V_21 , V_46 ) ;
}
static void F_57 ( void * V_19 )
{
struct V_3 * V_4 = V_19 ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
if ( V_4 -> V_21 . V_96 != V_49 )
F_7 ( V_2 , V_4 ) ;
}
static void F_58 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
F_12 ( & V_4 -> V_21 , V_22 ) ;
}
static enum V_23 F_61 ( struct V_3 * V_4 )
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
F_62 ( V_2 , V_4 ,
V_4 -> V_44 . V_95 ) ;
V_4 -> V_44 . V_95 = V_97 ;
F_12 ( V_21 , V_41 ) ;
return V_27 ;
}
static void F_63 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_8 -> V_9 ,
L_1 , V_10 , V_4 ) ;
F_11 ( ! F_64 ( & V_4 -> V_98 ) ) ;
F_61 ( V_4 ) ;
F_65 ( & V_4 -> V_99 ) ;
F_49 ( V_4 ) ;
}
static void F_66 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
T_1 V_100 ;
V_100 = V_4 -> V_21 . V_96 ;
if ( V_100 == V_45 )
F_63 ( V_2 , V_4 ) ;
F_67 ( V_2 , V_4 ) ;
}
static void F_68 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_1 ( V_2 , V_4 ,
V_101 ) ;
}
static void F_69 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
struct V_102 * V_9 = V_4 -> V_103 ;
if ( V_9 -> V_104 == V_105 || ( V_9 -> V_106 & V_107 ) ) {
F_12 ( & V_4 -> V_21 , V_47 ) ;
} else if ( F_70 ( V_9 ) ) {
F_12 ( & V_4 -> V_21 , V_52 ) ;
} else
F_7 ( V_2 , V_4 ) ;
}
static void F_71 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
struct V_102 * V_9 = V_4 -> V_103 ;
if ( V_9 -> V_104 == V_108 ) {
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_1 ( V_2 , V_4 ,
V_11 ) ;
}
}
static void F_72 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
F_22 (
& V_4 -> V_44 , V_77 , NULL , NULL ) ;
}
static void F_73 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
F_35 ( & V_4 -> V_44 , NULL , NULL ) ;
}
static void F_74 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
V_4 -> V_70 = NULL ;
if ( F_75 ( & V_4 -> V_44 ) ) {
F_57 ( V_4 ) ;
} else {
F_35 ( & V_4 -> V_44 ,
F_57 ,
V_4 ) ;
}
}
static void F_76 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_11 ( V_4 -> V_70 == NULL ) ;
F_1 ( V_2 , V_4 ,
V_109 ) ;
}
static void F_77 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
if ( V_4 -> V_67 == V_14 )
F_1 ( V_2 , V_4 ,
V_4 -> V_67 ) ;
}
static void F_78 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_7 ( V_2 , V_4 ) ;
}
static void F_79 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
struct V_1 * V_2 = V_4 -> V_24 -> V_25 ;
F_11 ( V_4 -> V_70 == NULL ) ;
F_1 ( V_2 , V_4 ,
V_110 ) ;
}
static void F_80 ( struct V_35 * V_21 )
{
struct V_3 * V_4 = F_59 ( V_21 , F_60 ( * V_4 ) , V_21 ) ;
V_4 -> V_70 = NULL ;
}
static void F_81 ( struct V_78 * V_79 ,
struct V_3 * V_4 )
{
V_4 -> V_24 = V_79 ;
V_4 -> V_20 = 0 ;
F_82 ( & V_4 -> V_21 , V_111 , V_39 ) ;
F_83 ( & V_4 -> V_44 ,
V_97 ) ;
}
static enum V_23 F_84 ( struct V_78 * V_79 ,
struct V_3 * V_4 )
{
enum V_23 V_26 ;
struct V_102 * V_9 = V_4 -> V_103 ;
F_81 ( V_79 , V_4 ) ;
V_4 -> V_112 = true ;
V_26 = F_85 ( V_79 -> V_25 ,
V_4 ,
& V_4 -> V_44 . V_95 ) ;
if ( V_26 != V_27 )
return V_26 ;
if ( V_9 -> V_104 == V_108 || V_9 -> V_104 == V_105 ||
( V_9 -> V_106 & V_113 ) || F_70 ( V_9 ) )
;
else
return V_114 ;
V_4 -> V_115 = F_86 ( V_79 ) ;
V_4 -> V_116 = 1 ;
return V_27 ;
}
static enum V_23 F_87 ( struct V_78 * V_79 ,
struct V_3 * V_4 )
{
struct V_102 * V_9 = V_4 -> V_103 ;
enum V_23 V_26 ;
F_81 ( V_79 , V_4 ) ;
V_26 = F_85 ( V_79 -> V_25 ,
V_4 ,
& V_4 -> V_44 . V_95 ) ;
if ( V_26 != V_27 )
return V_26 ;
if ( V_9 -> V_104 == V_108 || V_9 -> V_104 == V_105 ||
( V_9 -> V_106 & V_113 ) || F_70 ( V_9 ) )
;
else
return V_114 ;
V_4 -> V_115 = F_88 ( V_117 , F_86 ( V_79 ) ,
V_9 -> V_118 ) ;
V_4 -> V_116 = 1 ;
return V_27 ;
}
static enum V_23 F_89 ( struct V_3 * V_4 ,
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
V_26 = F_35 ( & V_4 -> V_44 ,
F_56 ,
V_4 ) ;
if ( V_26 != V_27 )
return V_26 ;
F_12 ( V_21 , V_43 ) ;
return V_27 ;
}
static enum V_23 F_90 ( struct V_78 * V_79 ,
struct V_3 * V_4 )
{
struct V_1 * V_2 = V_79 -> V_1 ;
struct V_102 * V_9 = V_4 -> V_103 ;
enum V_23 V_26 ;
if ( V_9 -> V_119 && F_70 ( V_9 -> V_119 ) )
V_26 = F_87 ( V_79 , V_4 ) ;
else
V_26 = F_84 ( V_79 , V_4 ) ;
if ( V_26 != V_27 ) {
F_2 ( & V_2 -> V_8 -> V_9 , L_12 ,
V_10 , V_26 ) ;
return V_26 ;
}
V_26 = F_89 ( V_4 , V_120 ) ;
if ( V_26 != V_27 )
F_16 ( & V_2 -> V_8 -> V_9 , L_13 ,
V_26 ) ;
return V_26 ;
}
void F_91 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_92 ( V_121 ) ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_3 , V_10 , V_4 ) ;
F_93 ( V_2 , V_4 ) ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_14 , V_10 , V_4 ) ;
}
static struct V_3 *
F_94 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_3 * V_4 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_122 ; V_28 ++ ) {
V_4 = & V_2 -> V_123 [ V_28 ] ;
if ( ! F_95 ( V_124 , & V_4 -> V_13 ) )
break;
}
if ( V_28 >= V_122 ) {
F_16 ( & V_2 -> V_8 -> V_9 , L_15 , V_10 ) ;
return NULL ;
}
if ( F_96 ( ! F_64 ( & V_4 -> V_98 ) , L_16 ) )
return NULL ;
if ( F_96 ( ! F_64 ( & V_4 -> V_99 ) , L_17 ) )
return NULL ;
return V_4 ;
}
void F_97 ( struct V_80 * V_80 )
{
struct V_3 * V_4 = F_59 ( V_80 , F_60 ( * V_4 ) , V_80 ) ;
struct V_1 * V_2 = V_4 -> V_78 -> V_1 ;
V_4 -> V_103 = NULL ;
V_4 -> V_78 = NULL ;
F_6 ( V_17 , & V_4 -> V_13 ) ;
F_6 ( V_125 , & V_4 -> V_13 ) ;
F_6 ( V_16 , & V_4 -> V_13 ) ;
F_6 ( V_12 , & V_4 -> V_13 ) ;
F_6 ( V_126 , & V_4 -> V_13 ) ;
F_98 () ;
F_6 ( V_124 , & V_4 -> V_13 ) ;
F_9 ( & V_2 -> V_18 ) ;
}
enum V_23 F_99 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
enum V_23 V_26 ;
unsigned long V_13 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_1 , V_10 , V_4 ) ;
F_100 ( & V_2 -> V_127 , V_13 ) ;
V_4 -> V_103 -> V_128 = NULL ;
F_3 ( V_12 , & V_4 -> V_13 ) ;
F_101 ( & V_2 -> V_127 , V_13 ) ;
F_91 ( V_2 , V_4 ) ;
F_3 ( V_125 , & V_4 -> V_13 ) ;
F_100 ( & V_2 -> V_127 , V_13 ) ;
V_26 = F_15 ( V_4 , 50 ) ;
F_101 ( & V_2 -> V_127 , V_13 ) ;
if ( F_96 ( V_26 != V_27 , L_18 ) )
;
else
F_102 ( V_2 , V_4 ) ;
return V_26 ;
}
void F_103 ( struct V_102 * V_9 )
{
struct V_1 * V_2 = F_104 ( V_9 ) ;
struct V_3 * V_4 = V_9 -> V_128 ;
F_2 ( & V_2 -> V_8 -> V_9 ,
L_19 ,
V_10 , V_9 , V_4 , V_4 -> V_78 ) ;
F_99 ( V_2 , V_4 ) ;
}
int F_105 ( struct V_102 * V_103 )
{
struct V_1 * V_1 = F_104 ( V_103 ) ;
struct V_78 * V_78 ;
struct V_129 * V_129 ;
struct V_130 * V_131 ;
struct V_132 * V_133 ;
struct V_3 * V_134 ;
enum V_23 V_26 ;
F_2 ( & V_1 -> V_8 -> V_9 ,
L_20 , V_10 , V_103 ) ;
F_106 ( V_1 ) ;
V_131 = V_103 -> V_135 ;
V_133 = F_107 ( & V_131 -> V_136 , struct V_132 ,
V_137 ) ;
V_129 = F_108 ( V_133 ) ;
V_78 = V_129 -> V_78 ;
F_109 ( & V_78 -> V_138 ) ;
if ( ( V_139 == F_110 ( V_78 ) ) ||
( V_140 == F_110 ( V_78 ) ) )
return - V_141 ;
V_134 = F_94 ( V_1 , V_78 ) ;
if ( ! V_134 )
return - V_141 ;
F_111 ( & V_134 -> V_80 ) ;
F_112 ( & V_134 -> V_99 ) ;
F_113 ( & V_1 -> V_127 ) ;
V_134 -> V_103 = V_103 ;
V_134 -> V_78 = V_78 ;
F_114 ( & V_134 -> V_99 , & V_78 -> V_142 ) ;
F_3 ( V_17 , & V_134 -> V_13 ) ;
V_26 = F_90 ( V_78 , V_134 ) ;
F_2 ( & V_1 -> V_8 -> V_9 ,
L_1 ,
V_10 , V_134 ) ;
if ( V_26 == V_27 ) {
V_103 -> V_128 = V_134 ;
} else
F_49 ( V_134 ) ;
F_115 ( & V_1 -> V_127 ) ;
F_116 ( V_1 , V_134 ) ;
return V_26 == V_27 ? 0 : - V_141 ;
}
bool F_117 (
struct V_1 * V_1 ,
struct V_3 * V_134 )
{
struct V_6 * V_6 ;
struct V_6 * V_143 ;
bool V_144 = false ;
unsigned long V_13 ;
F_2 ( & V_1 -> V_8 -> V_9 ,
L_1 , V_10 , V_134 ) ;
F_100 ( & V_1 -> V_127 , V_13 ) ;
F_118 (isci_request, tmp_req,
&isci_device->reqs_in_process, dev_node) {
F_2 ( & V_1 -> V_8 -> V_9 ,
L_2 ,
V_10 , V_134 , V_6 ) ;
if ( V_6 -> V_145 == V_146 ) {
struct V_82 * V_83 = F_43 (
V_6 ) ;
F_119 ( & V_83 -> V_147 ) ;
if ( V_83 -> V_148 & V_149 )
V_144 = true ;
F_120 ( & V_83 -> V_147 ) ;
}
}
F_101 ( & V_1 -> V_127 , V_13 ) ;
F_2 ( & V_1 -> V_8 -> V_9 ,
L_21 ,
V_10 , V_134 , V_144 ) ;
return V_144 ;
}
void F_121 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_6 ;
struct V_6 * V_143 ;
unsigned long V_13 = 0 ;
F_2 ( & V_2 -> V_8 -> V_9 , L_22 ,
V_10 , V_4 , V_2 ) ;
F_100 ( & V_2 -> V_127 , V_13 ) ;
F_118 (isci_request, tmp_req,
&idev->reqs_in_process, dev_node) {
F_2 ( & V_2 -> V_8 -> V_9 , L_23 ,
V_10 , V_4 , V_6 ) ;
if ( V_6 -> V_145 == V_146 ) {
unsigned long V_150 ;
struct V_82 * V_83 = F_43 (
V_6 ) ;
F_100 ( & V_83 -> V_147 , V_150 ) ;
V_83 -> V_148 &= ~ V_149 ;
F_101 ( & V_83 -> V_147 , V_150 ) ;
}
}
F_101 ( & V_2 -> V_127 , V_13 ) ;
}

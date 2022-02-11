static bool F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
bool V_5 = false ;
int V_6 , V_7 ;
switch ( V_2 -> V_8 -> V_9 ) {
case V_10 :
V_7 = V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_13 , & V_4 ) ;
if ( V_7 == 0 && V_4 . V_14 )
V_5 = true ;
break;
case V_15 :
for ( V_6 = 0 ; V_2 -> V_16 [ V_6 ] ; V_6 ++ ) {
V_7 = V_2 -> V_16 [ V_6 ] -> V_12 (
V_2 -> V_16 [ V_6 ] ,
V_13 , & V_4 ) ;
if ( V_7 == 0 && V_4 . V_14 ) {
V_5 = true ;
break;
}
}
break;
}
return V_5 ;
}
static bool F_2 ( struct V_1 * V_2 )
{
union V_3 V_4 ;
bool V_17 = false ;
int V_6 , V_7 ;
for ( V_6 = 0 ; V_2 -> V_16 [ V_6 ] ; V_6 ++ ) {
V_7 = V_2 -> V_16 [ V_6 ] -> V_12 (
V_2 -> V_16 [ V_6 ] ,
V_18 , & V_4 ) ;
if ( V_7 == 0 && V_4 . V_14 ) {
V_17 = true ;
break;
}
}
return V_17 ;
}
static int F_3 ( struct V_1 * V_2 , int * V_19 )
{
union V_3 V_4 ;
int V_7 ;
if ( V_2 -> V_11 )
V_7 = V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_20 , & V_4 ) ;
else
return - V_21 ;
if ( V_7 )
return V_7 ;
* V_19 = V_4 . V_14 ;
return 0 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
int V_6 , V_7 ;
bool V_22 = false ;
union V_3 V_4 ;
if ( ! F_1 ( V_2 ) )
return false ;
for ( V_6 = 0 ; V_2 -> V_16 [ V_6 ] ; V_6 ++ ) {
if ( V_2 -> V_23 )
continue;
if ( ! V_2 -> V_24 )
continue;
V_7 = V_2 -> V_16 [ V_6 ] -> V_12 (
V_2 -> V_16 [ V_6 ] ,
V_18 , & V_4 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_25 , L_1 ,
V_2 -> V_8 -> V_26 [ V_6 ] ) ;
continue;
}
if ( V_4 . V_14 == 0 )
continue;
V_7 = V_2 -> V_16 [ V_6 ] -> V_12 (
V_2 -> V_16 [ V_6 ] ,
V_27 , & V_4 ) ;
if ( V_7 ) {
F_5 ( V_2 -> V_25 , L_2 ,
V_2 -> V_8 -> V_26 [ V_6 ] ) ;
continue;
}
if ( V_4 . V_14 == V_28 ||
V_4 . V_14 == V_29 ||
V_4 . V_14 == V_30 )
continue;
V_22 = true ;
break;
}
return V_22 ;
}
static bool F_6 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_8 -> V_31 ) {
case V_32 :
return false ;
case V_33 :
return true ;
case V_34 :
return F_2 ( V_2 ) ;
case V_35 :
return F_4 ( V_2 ) ;
default:
F_5 ( V_2 -> V_25 , L_3 ,
V_2 -> V_8 -> V_31 ) ;
}
return false ;
}
static int F_7 ( struct V_1 * V_2 , bool V_36 )
{
int V_37 = 0 , V_6 ;
struct V_38 * V_8 = V_2 -> V_8 ;
if ( V_36 && V_2 -> V_24 )
return 0 ;
if ( ! V_36 && ! V_2 -> V_24 )
return 0 ;
if ( V_36 ) {
if ( V_2 -> V_23 )
return - V_39 ;
V_37 = F_8 ( V_8 -> V_40 ,
V_8 -> V_41 ) ;
} else {
V_37 = F_9 ( V_8 -> V_40 ,
V_8 -> V_41 ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_40 ; V_6 ++ ) {
if ( F_10 (
V_8 -> V_41 [ V_6 ] . V_42 ) ) {
F_11 (
V_8 -> V_41 [ V_6 ] . V_42 ) ;
F_5 ( V_2 -> V_25 ,
L_4 ,
V_8 -> V_41 [ V_6 ] . V_43 ) ;
}
}
}
if ( ! V_37 )
V_2 -> V_24 = V_36 ;
return V_37 ;
}
static void F_12 ( struct V_1 * V_2 , const char * V_44 )
{
static char V_45 [ V_46 + 1 ] = L_5 ;
static char V_47 [ V_46 + 1 ] = L_5 ;
if ( V_48 ) {
if ( V_47 [ 0 ] == 0 ) {
if ( ! strncmp ( V_45 , V_44 , V_46 ) )
return;
strncpy ( V_47 , V_44 , V_46 ) ;
return;
}
if ( ! strncmp ( V_47 , V_44 , V_46 ) )
return;
else
strncpy ( V_47 , V_44 , V_46 ) ;
return;
}
if ( V_44 == NULL ) {
if ( ! V_47 [ 0 ] )
return;
strncpy ( V_45 , V_47 , V_46 ) ;
F_13 ( & V_2 -> V_25 -> V_49 , V_50 ) ;
V_47 [ 0 ] = 0 ;
return;
}
if ( ! strncmp ( V_45 , V_44 , V_46 ) )
return;
strncpy ( V_45 , V_44 , V_46 ) ;
F_13 ( & V_2 -> V_25 -> V_49 , V_50 ) ;
F_14 ( V_2 -> V_25 , V_44 ) ;
}
static bool F_15 ( struct V_1 * V_2 )
{
struct V_38 * V_8 = V_2 -> V_8 ;
int V_51 = V_8 -> V_52 ( & V_2 -> V_53 ) ;
F_16 ( V_2 -> V_25 , L_6 ,
V_2 -> V_53 / 1000 , V_2 -> V_53 % 1000 ) ;
if ( ! ! V_51 == ! ! V_2 -> V_23 )
return false ;
if ( V_51 ) {
V_2 -> V_23 = V_51 ;
if ( ! F_7 ( V_2 , false ) ) {
if ( V_51 > 0 )
F_12 ( V_2 , L_7 ) ;
else
F_12 ( V_2 , L_8 ) ;
}
} else {
V_2 -> V_23 = 0 ;
if ( ! F_7 ( V_2 , true ) )
F_12 ( V_2 , L_9 ) ;
}
return true ;
}
static bool F_17 ( void )
{
bool V_54 = false ;
struct V_1 * V_2 ;
F_18 ( & V_55 ) ;
F_19 (cm, &cm_list, entry)
V_54 = V_54 || F_15 ( V_2 ) ;
F_20 ( & V_55 ) ;
return V_54 ;
}
static int F_21 ( struct V_56 * V_57 ,
enum V_58 V_59 ,
union V_3 * V_4 )
{
struct V_1 * V_2 = F_22 ( V_57 ,
struct V_1 , V_60 ) ;
struct V_38 * V_8 = V_2 -> V_8 ;
int V_6 , V_7 = 0 , V_19 ;
switch ( V_59 ) {
case V_27 :
if ( F_4 ( V_2 ) )
V_4 -> V_14 = V_61 ;
else if ( F_2 ( V_2 ) )
V_4 -> V_14 = V_30 ;
else
V_4 -> V_14 = V_29 ;
break;
case V_62 :
if ( V_2 -> V_23 > 0 )
V_4 -> V_14 = V_63 ;
else if ( V_2 -> V_23 < 0 )
V_4 -> V_14 = V_64 ;
else
V_4 -> V_14 = V_65 ;
break;
case V_13 :
if ( F_1 ( V_2 ) )
V_4 -> V_14 = 1 ;
else
V_4 -> V_14 = 0 ;
break;
case V_20 :
V_7 = F_3 ( V_2 , & V_6 ) ;
V_4 -> V_14 = V_6 ;
break;
case V_66 :
V_7 = V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_66 , V_4 ) ;
break;
case V_67 :
if ( V_2 -> V_53 == V_68 )
V_8 -> V_52 ( & V_2 -> V_53 ) ;
V_4 -> V_14 = V_2 -> V_53 / 100 ;
if ( ! V_8 -> V_69 )
V_7 = - V_21 ;
break;
case V_70 :
if ( V_2 -> V_53 == V_68 )
V_8 -> V_52 ( & V_2 -> V_53 ) ;
V_4 -> V_14 = V_2 -> V_53 / 100 ;
if ( V_8 -> V_69 )
V_7 = - V_21 ;
break;
case V_71 :
if ( ! V_2 -> V_11 ) {
V_7 = - V_21 ;
break;
}
if ( ! F_1 ( V_2 ) ) {
V_4 -> V_14 = 100 ;
break;
}
V_7 = V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_71 , V_4 ) ;
if ( V_7 )
break;
if ( V_4 -> V_14 > 100 ) {
V_4 -> V_14 = 100 ;
break;
}
if ( V_4 -> V_14 < 0 )
V_4 -> V_14 = 0 ;
if ( F_4 ( V_2 ) )
break;
V_7 = F_3 ( V_2 , & V_19 ) ;
if ( V_7 ) {
V_7 = 0 ;
break;
}
if ( V_8 -> V_72 > 0 && V_19 >= V_8 -> V_72 &&
! F_4 ( V_2 ) ) {
V_4 -> V_14 = 100 ;
break;
}
break;
case V_18 :
if ( F_2 ( V_2 ) )
V_4 -> V_14 = 1 ;
else
V_4 -> V_14 = 0 ;
break;
case V_73 :
if ( V_2 -> V_11 ) {
if ( V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_73 , V_4 ) == 0 )
break;
}
if ( F_2 ( V_2 ) ) {
if ( F_4 ( V_2 ) ) {
V_4 -> V_14 = 0 ;
break;
}
if ( ! V_2 -> V_23 ) {
V_4 -> V_14 = 1 ;
break;
}
}
V_7 = F_3 ( V_2 , & V_19 ) ;
if ( ! V_7 && V_8 -> V_72 > 0 && V_19 >= V_8 -> V_72 &&
! F_4 ( V_2 ) ) {
V_4 -> V_14 = 1 ;
break;
}
if ( V_2 -> V_11 ) {
V_7 = V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_71 , V_4 ) ;
if ( ! V_7 && V_4 -> V_14 >= 100 && ! F_4 ( V_2 ) ) {
V_4 -> V_14 = 1 ;
break;
}
}
V_4 -> V_14 = 0 ;
V_7 = 0 ;
break;
case V_74 :
if ( F_4 ( V_2 ) ) {
V_7 = V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_74 ,
V_4 ) ;
if ( V_7 ) {
V_4 -> V_14 = 1 ;
V_7 = 0 ;
} else {
V_4 -> V_14 = ( V_4 -> V_14 > 0 ) ?
V_4 -> V_14 : 1 ;
}
} else {
V_4 -> V_14 = 0 ;
}
break;
default:
return - V_75 ;
}
return V_7 ;
}
static bool F_23 ( void )
{
struct V_1 * V_2 ;
unsigned int V_76 = V_77 ;
bool V_7 = false ;
F_18 ( & V_55 ) ;
F_19 (cm, &cm_list, entry) {
if ( ! F_6 ( V_2 ) && ! V_2 -> V_23 )
continue;
if ( V_2 -> V_8 -> V_78 == 0 )
continue;
F_24 ( V_76 , V_2 -> V_8 -> V_78 ) ;
}
F_20 ( & V_55 ) ;
if ( V_76 < V_77 && V_76 > 0 ) {
F_25 ( L_10 , V_76 ) ;
if ( V_79 ) {
struct V_80 V_81 ;
unsigned long time , V_82 ;
unsigned long V_83 = F_26 ( V_76 , 1000 ) ;
V_81 . V_84 = 1 ;
F_27 ( V_79 , & V_81 . time ) ;
F_28 ( & V_81 . time , & V_82 ) ;
if ( V_83 < V_85 )
V_83 = V_85 ;
time = V_82 + V_83 ;
V_7 = true ;
if ( V_86 . V_84 &&
V_87 &&
V_87 < time ) {
if ( V_87 < V_82 + V_85 )
time = V_82 + V_85 ;
else
time = V_87 ;
V_7 = false ;
}
F_25 ( L_11 ,
time - V_82 ) ;
F_29 ( time , & V_81 . time ) ;
F_30 ( V_79 , & V_81 ) ;
V_88 += V_76 ;
return V_7 ;
}
}
if ( V_79 )
F_30 ( V_79 , & V_86 ) ;
return false ;
}
bool F_31 ( void )
{
struct V_1 * V_2 ;
bool V_7 = false ;
if ( ! V_89 || ! V_89 -> V_90 || ! V_89 -> V_90 () ||
! V_91 )
return false ;
if ( F_17 () )
goto V_92;
V_7 = true ;
F_18 ( & V_55 ) ;
F_19 (cm, &cm_list, entry) {
if ( V_2 -> V_93 != F_2 ( V_2 ) ||
V_2 -> V_94 != F_1 ( V_2 ) )
V_7 = false ;
}
F_20 ( & V_55 ) ;
V_91 = F_23 () ;
V_92:
if ( V_86 . V_84 ) {
unsigned long V_82 ;
struct V_95 V_81 ;
F_27 ( V_79 , & V_81 ) ;
F_28 ( & V_81 , & V_82 ) ;
if ( V_87 &&
V_82 + V_85 >= V_87 )
return false ;
}
return V_7 ;
}
int F_32 ( struct V_96 * V_97 )
{
if ( ! V_97 )
return - V_75 ;
if ( V_79 )
F_33 ( V_79 ) ;
V_79 = NULL ;
V_89 = NULL ;
if ( ! V_97 -> V_90 ) {
F_34 ( L_12 ) ;
return - V_75 ;
}
if ( V_97 -> V_98 ) {
V_79 = F_35 ( V_97 -> V_98 ) ;
if ( F_36 ( V_79 ) ) {
V_79 = NULL ;
}
} else {
F_37 ( L_13
L_14 ) ;
}
V_89 = V_97 ;
return 0 ;
}
static int F_38 ( struct V_99 * V_100 )
{
struct V_38 * V_8 = F_39 ( & V_100 -> V_25 ) ;
struct V_1 * V_2 ;
int V_7 = 0 , V_6 = 0 ;
union V_3 V_4 ;
if ( V_89 && ! V_79 && V_89 -> V_98 ) {
V_79 = F_35 ( V_89 -> V_98 ) ;
if ( F_36 ( V_79 ) ) {
V_79 = NULL ;
F_40 ( & V_100 -> V_25 , L_15 ,
V_89 -> V_98 ) ;
V_7 = - V_21 ;
goto V_101;
}
}
if ( ! V_8 ) {
F_40 ( & V_100 -> V_25 , L_16 ) ;
V_7 = - V_21 ;
goto V_101;
}
V_2 = F_41 ( sizeof( struct V_1 ) , V_102 ) ;
if ( ! V_2 ) {
F_40 ( & V_100 -> V_25 , L_17 ) ;
V_7 = - V_103 ;
goto V_101;
}
V_2 -> V_25 = & V_100 -> V_25 ;
V_2 -> V_8 = F_41 ( sizeof( struct V_38 ) , V_102 ) ;
if ( ! V_2 -> V_8 ) {
F_40 ( & V_100 -> V_25 , L_17 ) ;
V_7 = - V_103 ;
goto V_104;
}
memcpy ( V_2 -> V_8 , V_8 , sizeof( struct V_38 ) ) ;
V_2 -> V_53 = V_68 ;
if ( ! V_8 -> V_41 || V_8 -> V_40 < 1 ) {
V_7 = - V_75 ;
F_40 ( & V_100 -> V_25 , L_18 ) ;
goto V_105;
}
if ( ! V_8 -> V_26 || ! V_8 -> V_26 [ 0 ] ) {
F_40 ( & V_100 -> V_25 , L_19 ) ;
V_7 = - V_75 ;
goto V_106;
}
while ( V_8 -> V_26 [ V_6 ] )
V_6 ++ ;
V_2 -> V_16 = F_41 ( sizeof( struct V_56 * ) * ( V_6 + 1 ) ,
V_102 ) ;
if ( ! V_2 -> V_16 ) {
V_7 = - V_103 ;
goto V_106;
}
for ( V_6 = 0 ; V_8 -> V_26 [ V_6 ] ; V_6 ++ ) {
V_2 -> V_16 [ V_6 ] = F_42 (
V_8 -> V_26 [ V_6 ] ) ;
if ( ! V_2 -> V_16 [ V_6 ] ) {
F_40 ( & V_100 -> V_25 , L_20
L_21 ,
V_8 -> V_26 [ V_6 ] ) ;
V_7 = - V_21 ;
goto V_107;
}
}
V_2 -> V_11 = F_42 ( V_8 -> V_108 ) ;
if ( ! V_2 -> V_11 ) {
F_40 ( & V_100 -> V_25 , L_22 ,
V_8 -> V_108 ) ;
V_7 = - V_21 ;
goto V_107;
}
if ( V_8 -> V_78 == 0 ||
F_43 ( V_8 -> V_78 ) <= V_109 ) {
F_40 ( & V_100 -> V_25 , L_23 ) ;
V_7 = - V_75 ;
goto V_107;
}
if ( ! V_8 -> V_52 ) {
F_40 ( & V_100 -> V_25 , L_24 ) ;
V_7 = - V_75 ;
goto V_107;
}
F_44 ( V_100 , V_2 ) ;
memcpy ( & V_2 -> V_60 , & V_110 ,
sizeof( V_110 ) ) ;
if ( ! V_8 -> V_111 ) {
strncpy ( V_2 -> V_112 , V_110 . V_113 ,
V_114 ) ;
} else {
strncpy ( V_2 -> V_112 , V_8 -> V_111 , V_114 ) ;
}
V_2 -> V_60 . V_113 = V_2 -> V_112 ;
V_2 -> V_60 . V_115 = F_41 ( sizeof( enum V_58 )
* ( F_45 ( V_116 ) +
V_117 ) ,
V_102 ) ;
if ( ! V_2 -> V_60 . V_115 ) {
F_40 ( & V_100 -> V_25 , L_25 ) ;
V_7 = - V_103 ;
goto V_107;
}
memcpy ( V_2 -> V_60 . V_115 , V_116 ,
sizeof( enum V_58 ) *
F_45 ( V_116 ) ) ;
V_2 -> V_60 . V_118 = V_110 . V_118 ;
if ( ! V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_74 , & V_4 ) ) {
V_2 -> V_60 . V_115 [ V_2 -> V_60 . V_118 ] =
V_74 ;
V_2 -> V_60 . V_118 ++ ;
}
if ( ! V_2 -> V_11 -> V_12 ( V_2 -> V_11 ,
V_66 ,
& V_4 ) ) {
V_2 -> V_60 . V_115 [ V_2 -> V_60 . V_118 ] =
V_66 ;
V_2 -> V_60 . V_118 ++ ;
}
if ( ! V_8 -> V_69 ) {
V_2 -> V_60 . V_115 [ V_2 -> V_60 . V_118 ] =
V_70 ;
V_2 -> V_60 . V_118 ++ ;
}
if ( V_8 -> V_69 ) {
V_2 -> V_60 . V_115 [ V_2 -> V_60 . V_118 ] =
V_67 ;
V_2 -> V_60 . V_118 ++ ;
}
V_7 = F_46 ( NULL , & V_2 -> V_60 ) ;
if ( V_7 ) {
F_40 ( & V_100 -> V_25 , L_26
L_27 , V_2 -> V_60 . V_113 ) ;
goto V_119;
}
V_7 = F_47 ( & V_100 -> V_25 , V_8 -> V_40 ,
V_8 -> V_41 ) ;
if ( V_7 ) {
F_40 ( & V_100 -> V_25 , L_28 ) ;
goto V_120;
}
V_7 = F_7 ( V_2 , true ) ;
if ( V_7 ) {
F_40 ( & V_100 -> V_25 , L_29 ) ;
goto V_121;
}
F_18 ( & V_55 ) ;
F_48 ( & V_2 -> V_122 , & V_123 ) ;
F_20 ( & V_55 ) ;
return 0 ;
V_121:
if ( V_8 -> V_41 )
F_49 ( V_8 -> V_40 ,
V_8 -> V_41 ) ;
V_120:
F_50 ( & V_2 -> V_60 ) ;
V_119:
F_51 ( V_2 -> V_60 . V_115 ) ;
V_107:
F_51 ( V_2 -> V_16 ) ;
V_106:
V_105:
F_51 ( V_2 -> V_8 ) ;
V_104:
F_51 ( V_2 ) ;
V_101:
return V_7 ;
}
static int T_1 F_52 ( struct V_99 * V_100 )
{
struct V_1 * V_2 = F_53 ( V_100 ) ;
struct V_38 * V_8 = V_2 -> V_8 ;
F_18 ( & V_55 ) ;
F_54 ( & V_2 -> V_122 ) ;
F_20 ( & V_55 ) ;
if ( V_8 -> V_41 )
F_49 ( V_8 -> V_40 ,
V_8 -> V_41 ) ;
F_50 ( & V_2 -> V_60 ) ;
F_51 ( V_2 -> V_60 . V_115 ) ;
F_51 ( V_2 -> V_16 ) ;
F_51 ( V_2 -> V_8 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static int F_55 ( struct V_124 * V_25 )
{
struct V_99 * V_100 = F_22 ( V_25 , struct V_99 ,
V_25 ) ;
struct V_1 * V_2 = F_53 ( V_100 ) ;
if ( ! V_48 ) {
if ( V_79 ) {
struct V_95 V_81 ;
unsigned long V_82 ;
F_56 ( V_79 , & V_86 ) ;
F_27 ( V_79 , & V_81 ) ;
if ( V_86 . V_84 ) {
F_28 ( & V_86 . time ,
& V_87 ) ;
F_28 ( & V_81 , & V_82 ) ;
if ( V_82 > V_87 )
V_87 = 0 ;
} else {
V_87 = 0 ;
}
}
V_48 = true ;
}
V_2 -> V_93 = F_2 ( V_2 ) ;
V_2 -> V_94 = F_1 ( V_2 ) ;
if ( ! V_91 ) {
V_88 = 0 ;
V_91 = F_23 () ;
}
return 0 ;
}
static void F_57 ( struct V_124 * V_25 )
{
struct V_99 * V_100 = F_22 ( V_25 , struct V_99 ,
V_25 ) ;
struct V_1 * V_2 = F_53 ( V_100 ) ;
if ( V_48 ) {
if ( V_79 ) {
struct V_80 V_81 ;
F_56 ( V_79 , & V_81 ) ;
V_86 . V_125 = V_81 . V_125 ;
F_30 ( V_79 , & V_86 ) ;
}
V_48 = false ;
V_91 = false ;
}
F_12 ( V_2 , NULL ) ;
}
static int T_2 F_58 ( void )
{
return F_59 ( & V_126 ) ;
}
static void T_3 F_60 ( void )
{
F_61 ( & V_126 ) ;
}

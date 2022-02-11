static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( & V_6 -> V_7 -> V_8 ) ;
V_3 = V_6 -> V_9 + V_6 -> V_10 + V_6 -> V_11 ;
F_3 ( V_3 > 0 ) ;
if ( V_3 > 1 ) {
F_4 ( L_1 , V_3 , V_6 -> V_12 ) ;
V_4 = - V_13 ;
} else {
V_6 -> V_9 = V_6 -> V_10 = 0 ;
V_6 -> V_11 = 1 ;
V_4 = V_2 -> V_14 ;
V_2 -> V_14 = V_15 ;
}
F_5 ( & V_6 -> V_7 -> V_8 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , int V_14 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( & V_6 -> V_7 -> V_8 ) ;
F_3 ( V_6 -> V_9 == 0 && V_6 -> V_10 == 0 ) ;
F_3 ( V_6 -> V_11 == 1 && V_2 -> V_14 == V_15 ) ;
V_6 -> V_11 = 0 ;
if ( V_14 == V_16 )
V_6 -> V_9 = 1 ;
else if ( V_14 == V_17 )
V_6 -> V_10 = 1 ;
else
V_6 -> V_11 = 1 ;
F_5 ( & V_6 -> V_7 -> V_8 ) ;
V_2 -> V_14 = V_14 ;
}
static int F_7 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
struct V_1 * V_2 ;
int V_12 = F_8 ( V_18 ) - 1 , V_14 , V_20 ;
V_20 = F_9 ( F_10 ( V_18 ) ) ;
if ( V_20 < 0 )
return V_20 ;
if ( V_19 -> V_21 & V_22 )
V_14 = V_17 ;
else
V_14 = V_16 ;
F_11 ( L_2 ,
V_20 , V_12 , V_14 ) ;
V_2 = F_12 ( V_20 , V_12 , V_14 ) ;
if ( F_13 ( V_2 ) )
return F_14 ( V_2 ) ;
V_19 -> V_23 = V_2 ;
return 0 ;
}
static int F_15 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_11 ( L_3 ,
V_6 -> V_7 -> V_20 , V_6 -> V_12 , V_2 -> V_14 ) ;
if ( V_6 -> V_24 ) {
F_16 ( L_4 ,
V_6 -> V_12 ) ;
F_3 ( ! V_6 -> V_25 ) ;
V_6 -> V_24 = 0 ;
F_17 ( V_6 -> V_26 ) ;
} else if ( V_6 -> V_25 ) {
F_11 ( L_5
L_6 , V_6 -> V_27 ,
V_6 -> V_28 , V_6 -> V_7 -> V_20 , V_6 -> V_12 ) ;
V_6 -> V_25 = 0 ;
F_17 ( V_6 -> V_26 ) ;
}
F_18 ( V_2 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_19 * V_19 , T_1 V_29 , int V_30 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_31 ;
if ( V_6 -> V_24 ) {
F_4 ( L_7 ) ;
return - V_13 ;
}
switch ( V_30 ) {
case 0 :
V_31 = V_29 ;
break;
case 1 :
V_31 = V_19 -> V_32 + V_29 ;
break;
case 2 :
V_31 = V_6 -> V_33 + V_29 ;
break;
default:
return - V_34 ;
}
if ( V_31 < 0 || V_31 > V_6 -> V_33 ) {
F_4 ( L_8 , V_31 ) ;
return - V_34 ;
}
F_11 ( L_9 ,
V_6 -> V_12 , V_29 , V_30 , V_31 ) ;
V_19 -> V_32 = V_31 ;
return V_31 ;
}
static int F_20 ( struct V_19 * V_19 , T_1 V_35 , T_1 V_36 , int V_37 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_38 * V_7 = V_2 -> V_6 -> V_7 ;
struct V_18 * V_18 = V_19 -> V_39 . V_40 -> V_41 ;
int V_4 ;
F_21 ( & V_18 -> V_42 ) ;
V_4 = F_22 ( V_7 -> V_20 ) ;
F_23 ( & V_18 -> V_42 ) ;
return V_4 ;
}
static T_2 F_24 ( struct V_19 * V_19 , T_3 char * V_43 , T_4 V_44 ,
T_1 * V_45 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
int V_4 , V_46 , V_47 , V_48 , V_49 ;
T_4 V_50 = V_44 ;
void * V_51 ;
F_11 ( L_10 ,
V_44 , * V_45 , V_6 -> V_12 ) ;
if ( V_6 -> V_24 ) {
F_4 ( L_7 ) ;
return - V_13 ;
}
if ( V_6 -> V_52 ) {
F_4 ( L_11 ) ;
return - V_53 ;
}
if ( * V_45 == V_6 -> V_33 || V_44 == 0 )
return 0 ;
if ( V_6 -> V_54 )
F_11 ( L_12 , V_6 -> V_12 ) ;
if ( * V_45 + V_44 > V_6 -> V_33 )
V_50 = V_44 = V_6 -> V_33 - * V_45 ;
V_49 = V_6 -> V_55 ;
if ( V_44 < V_49 )
V_49 = F_25 ( V_44 , V_7 -> V_56 ) ;
V_51 = F_26 ( V_49 ) ;
if ( ! V_51 )
return - V_57 ;
V_48 = V_44 > V_49 ? V_49 : V_44 ;
V_46 = F_27 ( * V_45 , V_6 -> V_55 , & V_47 ) ;
do {
F_28 () ;
if ( V_47 + V_48 >= V_6 -> V_55 )
V_48 = V_6 -> V_55 - V_47 ;
V_4 = F_29 ( V_7 , V_6 , V_46 , V_51 , V_47 , V_48 , 0 ) ;
if ( V_4 )
break;
V_47 += V_48 ;
if ( V_47 == V_6 -> V_55 ) {
V_46 += 1 ;
V_47 -= V_6 -> V_55 ;
}
V_44 -= V_48 ;
* V_45 += V_48 ;
V_4 = F_30 ( V_43 , V_51 , V_48 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_43 += V_48 ;
V_48 = V_44 > V_49 ? V_49 : V_44 ;
} while ( V_44 );
F_17 ( V_51 ) ;
return V_4 ? V_4 : V_50 - V_44 ;
}
static T_2 F_31 ( struct V_19 * V_19 , const char T_3 * V_43 ,
T_4 V_44 , T_1 * V_45 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
int V_46 , V_47 , V_48 , V_49 , V_4 = 0 ;
T_4 V_50 = V_44 ;
char * V_51 ;
if ( ! V_6 -> V_59 )
return - V_60 ;
F_11 ( L_13 ,
V_44 , * V_45 , V_6 -> V_12 ) ;
if ( V_6 -> V_61 == V_62 )
return - V_63 ;
V_46 = F_27 ( * V_45 , V_6 -> V_55 , & V_47 ) ;
if ( V_47 & ( V_7 -> V_56 - 1 ) ) {
F_4 ( L_14 ) ;
return - V_34 ;
}
if ( * V_45 + V_44 > V_6 -> V_33 )
V_50 = V_44 = V_6 -> V_33 - * V_45 ;
if ( V_44 & ( V_7 -> V_56 - 1 ) ) {
F_4 ( L_15 ) ;
return - V_34 ;
}
V_49 = V_6 -> V_55 ;
if ( V_44 < V_49 )
V_49 = F_25 ( V_44 , V_7 -> V_56 ) ;
V_51 = F_26 ( V_49 ) ;
if ( ! V_51 )
return - V_57 ;
V_48 = V_44 > V_49 ? V_49 : V_44 ;
while ( V_44 ) {
F_28 () ;
if ( V_47 + V_48 >= V_6 -> V_55 )
V_48 = V_6 -> V_55 - V_47 ;
V_4 = F_32 ( V_51 , V_43 , V_48 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_33 ( V_7 , V_6 , V_46 , V_51 , V_47 , V_48 ,
V_64 ) ;
if ( V_4 )
break;
V_47 += V_48 ;
if ( V_47 == V_6 -> V_55 ) {
V_46 += 1 ;
V_47 -= V_6 -> V_55 ;
}
V_44 -= V_48 ;
* V_45 += V_48 ;
V_43 += V_48 ;
V_48 = V_44 > V_49 ? V_49 : V_44 ;
}
F_17 ( V_51 ) ;
return V_4 ? V_4 : V_50 - V_44 ;
}
static T_2 F_34 ( struct V_19 * V_19 , const char T_3 * V_43 ,
T_4 V_44 , T_1 * V_45 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
if ( ! V_6 -> V_24 && ! V_6 -> V_25 )
return F_31 ( V_19 , V_43 , V_44 , V_45 ) ;
if ( V_6 -> V_24 )
V_4 = F_35 ( V_7 , V_6 , V_43 , V_44 ) ;
else
V_4 = F_36 ( V_7 , V_6 , V_43 , V_44 ) ;
if ( V_4 < 0 ) {
F_37 ( L_16 ,
V_44 , V_4 ) ;
return V_4 ;
}
if ( V_4 ) {
V_44 = V_4 ;
if ( V_6 -> V_25 ) {
F_6 ( V_2 , V_17 ) ;
return V_44 ;
}
V_4 = F_38 ( V_7 , V_6 -> V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 ) {
F_16 ( L_17 ,
V_6 -> V_12 , V_7 -> V_20 ) ;
V_6 -> V_54 = 1 ;
}
V_6 -> V_65 = 1 ;
F_39 ( V_7 , V_6 , V_66 ) ;
F_6 ( V_2 , V_17 ) ;
}
return V_44 ;
}
static long F_40 ( struct V_19 * V_19 , unsigned int V_67 ,
unsigned long V_68 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
void T_3 * V_69 = ( void T_3 * ) V_68 ;
switch ( V_67 ) {
case V_70 :
{
T_5 V_71 , V_72 ;
if ( ! F_41 ( V_73 ) ) {
V_4 = - V_60 ;
break;
}
V_4 = F_32 ( & V_71 , V_69 , sizeof( T_5 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
if ( V_2 -> V_14 == V_16 ) {
V_4 = - V_63 ;
break;
}
V_72 = ( long long ) V_6 -> V_74 *
V_7 -> V_75 - V_6 -> V_76 ;
if ( V_71 < 0 || V_71 > V_72 ) {
V_4 = - V_34 ;
break;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_42 ( V_7 , V_6 , V_71 ) ;
if ( V_71 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_77 :
{
struct V_78 V_79 ;
V_4 = F_32 ( & V_79 , V_69 ,
sizeof( struct V_78 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
if ( V_2 -> V_14 == V_16 ||
V_6 -> V_61 == V_62 ) {
V_4 = - V_63 ;
break;
}
V_4 = - V_34 ;
if ( V_79 . V_46 < 0 || V_79 . V_46 >= V_6 -> V_74 ||
V_79 . V_71 < 0 || V_79 . V_46 >= V_6 -> V_55 )
break;
if ( V_79 . V_80 != V_81 && V_79 . V_80 != V_82 &&
V_79 . V_80 != V_64 )
break;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_43 ( V_7 , V_6 , & V_79 ) ;
if ( V_79 . V_71 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_83 :
{
T_6 V_46 ;
V_4 = F_44 ( V_46 , ( T_3 T_6 * ) V_69 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
if ( V_2 -> V_14 == V_16 ||
V_6 -> V_61 == V_62 ) {
V_4 = - V_63 ;
break;
}
if ( V_46 < 0 || V_46 >= V_6 -> V_74 ) {
V_4 = - V_34 ;
break;
}
F_11 ( L_18 , V_6 -> V_12 , V_46 ) ;
V_4 = F_45 ( V_7 , V_6 , V_46 ) ;
if ( V_4 )
break;
V_4 = F_46 ( V_7 ) ;
break;
}
case V_84 :
{
struct V_85 V_79 ;
V_4 = F_32 ( & V_79 , V_69 , sizeof( struct V_85 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_47 ( V_2 , V_79 . V_46 , V_79 . V_80 ) ;
break;
}
case V_86 :
{
T_6 V_46 ;
V_4 = F_44 ( V_46 , ( T_3 T_6 * ) V_69 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_48 ( V_2 , V_46 ) ;
break;
}
case V_87 :
{
T_6 V_46 ;
V_4 = F_44 ( V_46 , ( T_3 T_6 * ) V_69 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_49 ( V_2 , V_46 ) ;
break;
}
case V_88 :
{
struct V_89 V_79 ;
V_4 = F_32 ( & V_79 , V_69 ,
sizeof( struct V_89 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
switch ( V_79 . V_90 ) {
case V_91 :
F_21 ( & V_7 -> V_92 ) ;
V_2 -> V_6 -> V_59 = ! ! V_79 . V_93 ;
F_23 ( & V_7 -> V_92 ) ;
break;
default:
V_4 = - V_34 ;
break;
}
break;
}
default:
V_4 = - V_94 ;
break;
}
return V_4 ;
}
static int F_50 ( const struct V_38 * V_7 ,
const struct V_95 * V_79 )
{
int V_96 , V_4 = - V_34 ;
if ( V_79 -> V_71 < 0 || V_79 -> V_97 < 0 || V_79 -> V_61 < 0 ||
V_79 -> V_98 < 0 )
goto V_99;
if ( ( V_79 -> V_12 < 0 || V_79 -> V_12 >= V_7 -> V_100 ) &&
V_79 -> V_12 != V_101 )
goto V_99;
if ( V_79 -> V_97 == 0 )
goto V_99;
if ( V_79 -> V_71 == 0 )
goto V_99;
if ( V_79 -> V_61 != V_102 &&
V_79 -> V_61 != V_62 )
goto V_99;
if ( V_79 -> V_97 > V_7 -> V_75 )
goto V_99;
V_96 = V_79 -> V_97 & ( V_7 -> V_56 - 1 ) ;
if ( V_79 -> V_97 != 1 && V_96 )
goto V_99;
if ( ! V_79 -> V_103 [ 0 ] || ! V_79 -> V_98 )
goto V_99;
if ( V_79 -> V_98 > V_104 ) {
V_4 = - V_105 ;
goto V_99;
}
V_96 = F_51 ( V_79 -> V_103 , V_79 -> V_98 + 1 ) ;
if ( V_96 != V_79 -> V_98 )
goto V_99;
return 0 ;
V_99:
F_4 ( L_19 ) ;
F_52 ( V_79 ) ;
return V_4 ;
}
static int F_53 ( const struct V_38 * V_7 ,
const struct V_106 * V_79 )
{
if ( V_79 -> V_71 <= 0 )
return - V_34 ;
if ( V_79 -> V_12 < 0 || V_79 -> V_12 >= V_7 -> V_100 )
return - V_34 ;
return 0 ;
}
static int F_54 ( struct V_38 * V_7 ,
struct V_107 * V_79 )
{
int V_108 , V_96 , V_4 ;
struct V_109 V_110 ;
struct V_111 * V_112 , * V_113 ;
if ( V_79 -> V_44 < 0 || V_79 -> V_44 > V_114 )
return - V_34 ;
if ( V_79 -> V_44 == 0 )
return 0 ;
for ( V_108 = 0 ; V_108 < V_79 -> V_44 ; V_108 ++ ) {
if ( V_79 -> V_115 [ V_108 ] . V_12 < 0 ||
V_79 -> V_115 [ V_108 ] . V_12 >= V_7 -> V_100 )
return - V_34 ;
if ( V_79 -> V_115 [ V_108 ] . V_98 < 0 )
return - V_34 ;
if ( V_79 -> V_115 [ V_108 ] . V_98 > V_104 )
return - V_105 ;
V_79 -> V_115 [ V_108 ] . V_103 [ V_79 -> V_115 [ V_108 ] . V_98 ] = '\0' ;
V_96 = strlen ( V_79 -> V_115 [ V_108 ] . V_103 ) ;
if ( V_96 != V_79 -> V_115 [ V_108 ] . V_98 )
V_4 = - V_34 ;
}
for ( V_108 = 0 ; V_108 < V_79 -> V_44 - 1 ; V_108 ++ ) {
for ( V_96 = V_108 + 1 ; V_96 < V_79 -> V_44 ; V_96 ++ ) {
if ( V_79 -> V_115 [ V_108 ] . V_12 == V_79 -> V_115 [ V_96 ] . V_12 ) {
F_4 ( L_20 ,
V_79 -> V_115 [ V_108 ] . V_12 ) ;
return - V_34 ;
}
if ( ! strcmp ( V_79 -> V_115 [ V_108 ] . V_103 , V_79 -> V_115 [ V_96 ] . V_103 ) ) {
F_4 ( L_21 ,
V_79 -> V_115 [ V_108 ] . V_103 ) ;
return - V_34 ;
}
}
}
F_55 ( & V_110 ) ;
for ( V_108 = 0 ; V_108 < V_79 -> V_44 ; V_108 ++ ) {
int V_12 = V_79 -> V_115 [ V_108 ] . V_12 ;
int V_98 = V_79 -> V_115 [ V_108 ] . V_98 ;
const char * V_103 = V_79 -> V_115 [ V_108 ] . V_103 ;
V_112 = F_56 ( sizeof( struct V_111 ) , V_116 ) ;
if ( ! V_112 ) {
V_4 = - V_57 ;
goto V_117;
}
V_112 -> V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_112 -> V_2 ) ) {
V_4 = F_14 ( V_112 -> V_2 ) ;
F_4 ( L_22 , V_12 , V_4 ) ;
F_57 ( V_112 ) ;
goto V_117;
}
if ( V_112 -> V_2 -> V_6 -> V_98 == V_98 &&
! memcmp ( V_112 -> V_2 -> V_6 -> V_103 , V_103 , V_98 ) ) {
F_18 ( V_112 -> V_2 ) ;
F_57 ( V_112 ) ;
continue;
}
V_112 -> V_118 = V_98 ;
memcpy ( V_112 -> V_119 , V_103 , V_98 ) ;
F_58 ( & V_112 -> V_120 , & V_110 ) ;
F_59 ( L_23 ,
V_12 , V_112 -> V_2 -> V_6 -> V_103 , V_103 ) ;
}
if ( F_60 ( & V_110 ) )
return 0 ;
F_61 (re, &rename_list, list) {
struct V_1 * V_2 ;
int V_121 = 0 ;
F_61 (re1, &rename_list, list) {
if ( V_112 -> V_118 == V_113 -> V_2 -> V_6 -> V_98 &&
! memcmp ( V_112 -> V_119 , V_113 -> V_2 -> V_6 -> V_103 ,
V_113 -> V_2 -> V_6 -> V_98 ) ) {
V_121 = 1 ;
break;
}
}
if ( V_121 )
continue;
V_2 = F_62 ( V_7 -> V_20 , V_112 -> V_119 ,
V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 == - V_122 )
continue;
F_4 ( L_24 ,
V_112 -> V_119 , V_4 ) ;
goto V_117;
}
V_113 = F_56 ( sizeof( struct V_111 ) , V_116 ) ;
if ( ! V_113 ) {
V_4 = - V_57 ;
F_18 ( V_2 ) ;
goto V_117;
}
V_113 -> remove = 1 ;
V_113 -> V_2 = V_2 ;
F_63 ( & V_113 -> V_120 , & V_110 ) ;
F_59 ( L_25 ,
V_113 -> V_2 -> V_6 -> V_12 , V_113 -> V_2 -> V_6 -> V_103 ) ;
}
F_21 ( & V_7 -> V_92 ) ;
V_4 = F_64 ( V_7 , & V_110 ) ;
F_23 ( & V_7 -> V_92 ) ;
V_117:
F_65 (re, re1, &rename_list, list) {
F_18 ( V_112 -> V_2 ) ;
F_66 ( & V_112 -> V_120 ) ;
F_57 ( V_112 ) ;
}
return V_4 ;
}
static long F_67 ( struct V_19 * V_19 , unsigned int V_67 ,
unsigned long V_68 )
{
int V_4 = 0 ;
struct V_38 * V_7 ;
struct V_1 * V_2 ;
void T_3 * V_69 = ( void T_3 * ) V_68 ;
if ( ! F_41 ( V_73 ) )
return - V_60 ;
V_7 = F_68 ( F_10 ( V_19 -> V_123 -> V_124 ) ) ;
if ( ! V_7 )
return - V_122 ;
switch ( V_67 ) {
case V_125 :
{
struct V_95 V_79 ;
F_11 ( L_26 ) ;
V_4 = F_32 ( & V_79 , V_69 , sizeof( struct V_95 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_50 ( V_7 , & V_79 ) ;
if ( V_4 )
break;
F_21 ( & V_7 -> V_92 ) ;
V_4 = F_69 ( V_7 , & V_79 ) ;
F_23 ( & V_7 -> V_92 ) ;
if ( V_4 )
break;
V_4 = F_70 ( V_79 . V_12 , ( T_3 T_6 * ) V_69 ) ;
if ( V_4 )
V_4 = - V_58 ;
break;
}
case V_126 :
{
int V_12 ;
F_11 ( L_27 ) ;
V_4 = F_44 ( V_12 , ( T_3 T_6 * ) V_69 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
F_21 ( & V_7 -> V_92 ) ;
V_4 = F_71 ( V_2 , 0 ) ;
F_23 ( & V_7 -> V_92 ) ;
F_18 ( V_2 ) ;
break;
}
case V_127 :
{
int V_128 ;
struct V_106 V_79 ;
F_11 ( L_28 ) ;
V_4 = F_32 ( & V_79 , V_69 , sizeof( struct V_106 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_53 ( V_7 , & V_79 ) ;
if ( V_4 )
break;
V_2 = F_12 ( V_7 -> V_20 , V_79 . V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
V_128 = F_72 ( V_79 . V_71 + V_2 -> V_6 -> V_55 - 1 ,
V_2 -> V_6 -> V_55 ) ;
F_21 ( & V_7 -> V_92 ) ;
V_4 = F_73 ( V_2 , V_128 ) ;
F_23 ( & V_7 -> V_92 ) ;
F_18 ( V_2 ) ;
break;
}
case V_129 :
{
struct V_107 * V_79 ;
F_59 ( L_29 ) ;
V_79 = F_74 ( sizeof( struct V_107 ) , V_116 ) ;
if ( ! V_79 ) {
V_4 = - V_57 ;
break;
} ;
V_4 = F_32 ( V_79 , V_69 , sizeof( struct V_107 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
F_57 ( V_79 ) ;
break;
}
V_4 = F_54 ( V_7 , V_79 ) ;
F_57 ( V_79 ) ;
break;
}
default:
V_4 = - V_94 ;
break;
}
F_75 ( V_7 ) ;
return V_4 ;
}
static long F_76 ( struct V_19 * V_19 , unsigned int V_67 ,
unsigned long V_68 )
{
int V_4 = 0 ;
void T_3 * V_69 = ( void T_3 * ) V_68 ;
if ( ! F_41 ( V_73 ) )
return - V_60 ;
switch ( V_67 ) {
case V_130 :
{
struct V_131 V_79 ;
struct V_132 * V_133 ;
F_11 ( L_30 ) ;
V_4 = F_32 ( & V_79 , V_69 , sizeof( struct V_131 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
if ( V_79 . V_134 < 0 ||
( V_79 . V_20 < 0 && V_79 . V_20 != V_135 ) ) {
V_4 = - V_34 ;
break;
}
V_133 = F_77 ( NULL , V_79 . V_134 ) ;
if ( F_13 ( V_133 ) ) {
V_4 = F_14 ( V_133 ) ;
break;
}
F_21 ( & V_136 ) ;
V_4 = F_78 ( V_133 , V_79 . V_20 , V_79 . V_137 ) ;
F_23 ( & V_136 ) ;
if ( V_4 < 0 )
F_79 ( V_133 ) ;
else
V_4 = F_70 ( V_4 , ( T_3 T_6 * ) V_69 ) ;
break;
}
case V_138 :
{
int V_20 ;
F_11 ( L_31 ) ;
V_4 = F_44 ( V_20 , ( T_3 T_6 * ) V_69 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
F_21 ( & V_136 ) ;
V_4 = F_80 ( V_20 , 0 ) ;
F_23 ( & V_136 ) ;
break;
}
default:
V_4 = - V_94 ;
break;
}
return V_4 ;
}
static long F_81 ( struct V_19 * V_19 , unsigned int V_67 ,
unsigned long V_68 )
{
unsigned long V_139 = ( unsigned long ) F_82 ( V_68 ) ;
return F_40 ( V_19 , V_67 , V_139 ) ;
}
static long F_83 ( struct V_19 * V_19 , unsigned int V_67 ,
unsigned long V_68 )
{
unsigned long V_139 = ( unsigned long ) F_82 ( V_68 ) ;
return F_67 ( V_19 , V_67 , V_139 ) ;
}
static long F_84 ( struct V_19 * V_19 , unsigned int V_67 ,
unsigned long V_68 )
{
unsigned long V_139 = ( unsigned long ) F_82 ( V_68 ) ;
return F_76 ( V_19 , V_67 , V_139 ) ;
}

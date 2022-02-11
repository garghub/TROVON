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
F_11 ( L_5 ,
V_6 -> V_27 , V_6 -> V_28 , V_6 -> V_7 -> V_20 ,
V_6 -> V_12 ) ;
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
F_4 ( L_6 ) ;
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
F_4 ( L_7 , V_31 ) ;
return - V_34 ;
}
F_11 ( L_8 ,
V_6 -> V_12 , V_29 , V_30 , V_31 ) ;
V_19 -> V_32 = V_31 ;
return V_31 ;
}
static int F_20 ( struct V_19 * V_19 , T_1 V_35 , T_1 V_36 ,
int V_37 )
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
F_11 ( L_9 ,
V_44 , * V_45 , V_6 -> V_12 ) ;
if ( V_6 -> V_24 ) {
F_4 ( L_6 ) ;
return - V_13 ;
}
if ( V_6 -> V_52 ) {
F_4 ( L_10 ) ;
return - V_53 ;
}
if ( * V_45 == V_6 -> V_33 || V_44 == 0 )
return 0 ;
if ( V_6 -> V_54 )
F_11 ( L_11 , V_6 -> V_12 ) ;
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
F_11 ( L_12 ,
V_44 , * V_45 , V_6 -> V_12 ) ;
if ( V_6 -> V_61 == V_62 )
return - V_63 ;
V_46 = F_27 ( * V_45 , V_6 -> V_55 , & V_47 ) ;
if ( V_47 & ( V_7 -> V_56 - 1 ) ) {
F_4 ( L_13 ) ;
return - V_34 ;
}
if ( * V_45 + V_44 > V_6 -> V_33 )
V_50 = V_44 = V_6 -> V_33 - * V_45 ;
if ( V_44 & ( V_7 -> V_56 - 1 ) ) {
F_4 ( L_14 ) ;
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
V_4 = F_33 ( V_7 , V_6 , V_46 , V_51 , V_47 , V_48 ) ;
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
F_4 ( L_15 ,
V_44 , V_4 ) ;
return V_4 ;
}
if ( V_4 ) {
V_44 = V_4 ;
if ( V_6 -> V_25 ) {
F_6 ( V_2 , V_17 ) ;
return V_44 ;
}
V_4 = F_37 ( V_7 , V_6 -> V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 ) {
F_16 ( L_16 ,
V_6 -> V_12 , V_7 -> V_20 ) ;
V_6 -> V_54 = 1 ;
}
V_6 -> V_64 = 1 ;
F_38 ( V_7 , V_6 , V_65 ) ;
F_6 ( V_2 , V_17 ) ;
}
return V_44 ;
}
static long F_39 ( struct V_19 * V_19 , unsigned int V_66 ,
unsigned long V_67 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
void T_3 * V_68 = ( void T_3 * ) V_67 ;
switch ( V_66 ) {
case V_69 :
{
T_5 V_70 , V_71 ;
if ( ! F_40 ( V_72 ) ) {
V_4 = - V_60 ;
break;
}
V_4 = F_32 ( & V_70 , V_68 , sizeof( T_5 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
if ( V_2 -> V_14 == V_16 ) {
V_4 = - V_63 ;
break;
}
V_71 = ( long long ) V_6 -> V_73 *
V_7 -> V_74 - V_6 -> V_75 ;
if ( V_70 < 0 || V_70 > V_71 ) {
V_4 = - V_34 ;
break;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_41 ( V_7 , V_6 , V_70 ) ;
if ( V_70 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_76 :
{
struct V_77 V_78 ;
V_4 = F_32 ( & V_78 , V_68 ,
sizeof( struct V_77 ) ) ;
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
if ( V_78 . V_46 < 0 || V_78 . V_46 >= V_6 -> V_73 ||
V_78 . V_70 < 0 || V_78 . V_46 >= V_6 -> V_55 )
break;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_42 ( V_7 , V_6 , & V_78 ) ;
if ( V_78 . V_70 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_79 :
{
T_6 V_46 ;
V_4 = F_43 ( V_46 , ( T_3 T_6 * ) V_68 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
if ( V_2 -> V_14 == V_16 ||
V_6 -> V_61 == V_62 ) {
V_4 = - V_63 ;
break;
}
if ( V_46 < 0 || V_46 >= V_6 -> V_73 ) {
V_4 = - V_34 ;
break;
}
F_11 ( L_17 , V_6 -> V_12 , V_46 ) ;
V_4 = F_44 ( V_7 , V_6 , V_46 ) ;
if ( V_4 )
break;
V_4 = F_45 ( V_7 , V_80 , V_80 ) ;
break;
}
case V_81 :
{
struct V_82 V_78 ;
V_4 = F_32 ( & V_78 , V_68 , sizeof( struct V_82 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_46 ( V_2 , V_78 . V_46 ) ;
break;
}
case V_83 :
{
T_6 V_46 ;
V_4 = F_43 ( V_46 , ( T_3 T_6 * ) V_68 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_47 ( V_2 , V_46 ) ;
break;
}
case V_84 :
{
T_6 V_46 ;
V_4 = F_43 ( V_46 , ( T_3 T_6 * ) V_68 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_48 ( V_2 , V_46 ) ;
break;
}
case V_85 :
{
struct V_86 V_78 ;
V_4 = F_32 ( & V_78 , V_68 ,
sizeof( struct V_86 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
switch ( V_78 . V_87 ) {
case V_88 :
F_21 ( & V_7 -> V_89 ) ;
V_2 -> V_6 -> V_59 = ! ! V_78 . V_90 ;
F_23 ( & V_7 -> V_89 ) ;
break;
default:
V_4 = - V_34 ;
break;
}
break;
}
default:
V_4 = - V_91 ;
break;
}
return V_4 ;
}
static int F_49 ( const struct V_38 * V_7 ,
const struct V_92 * V_78 )
{
int V_93 , V_4 = - V_34 ;
if ( V_78 -> V_70 < 0 || V_78 -> V_94 < 0 || V_78 -> V_61 < 0 ||
V_78 -> V_95 < 0 )
goto V_96;
if ( ( V_78 -> V_12 < 0 || V_78 -> V_12 >= V_7 -> V_97 ) &&
V_78 -> V_12 != V_98 )
goto V_96;
if ( V_78 -> V_94 == 0 )
goto V_96;
if ( V_78 -> V_70 == 0 )
goto V_96;
if ( V_78 -> V_61 != V_99 &&
V_78 -> V_61 != V_62 )
goto V_96;
if ( V_78 -> V_94 > V_7 -> V_74 )
goto V_96;
V_93 = V_78 -> V_94 & ( V_7 -> V_56 - 1 ) ;
if ( V_78 -> V_94 != 1 && V_93 )
goto V_96;
if ( ! V_78 -> V_100 [ 0 ] || ! V_78 -> V_95 )
goto V_96;
if ( V_78 -> V_95 > V_101 ) {
V_4 = - V_102 ;
goto V_96;
}
V_93 = F_50 ( V_78 -> V_100 , V_78 -> V_95 + 1 ) ;
if ( V_93 != V_78 -> V_95 )
goto V_96;
return 0 ;
V_96:
F_4 ( L_18 ) ;
F_51 ( V_78 ) ;
return V_4 ;
}
static int F_52 ( const struct V_38 * V_7 ,
const struct V_103 * V_78 )
{
if ( V_78 -> V_70 <= 0 )
return - V_34 ;
if ( V_78 -> V_12 < 0 || V_78 -> V_12 >= V_7 -> V_97 )
return - V_34 ;
return 0 ;
}
static int F_53 ( struct V_38 * V_7 ,
struct V_104 * V_78 )
{
int V_105 , V_93 , V_4 ;
struct V_106 V_107 ;
struct V_108 * V_109 , * V_110 ;
if ( V_78 -> V_44 < 0 || V_78 -> V_44 > V_111 )
return - V_34 ;
if ( V_78 -> V_44 == 0 )
return 0 ;
for ( V_105 = 0 ; V_105 < V_78 -> V_44 ; V_105 ++ ) {
if ( V_78 -> V_112 [ V_105 ] . V_12 < 0 ||
V_78 -> V_112 [ V_105 ] . V_12 >= V_7 -> V_97 )
return - V_34 ;
if ( V_78 -> V_112 [ V_105 ] . V_95 < 0 )
return - V_34 ;
if ( V_78 -> V_112 [ V_105 ] . V_95 > V_101 )
return - V_102 ;
V_78 -> V_112 [ V_105 ] . V_100 [ V_78 -> V_112 [ V_105 ] . V_95 ] = '\0' ;
V_93 = strlen ( V_78 -> V_112 [ V_105 ] . V_100 ) ;
if ( V_93 != V_78 -> V_112 [ V_105 ] . V_95 )
V_4 = - V_34 ;
}
for ( V_105 = 0 ; V_105 < V_78 -> V_44 - 1 ; V_105 ++ ) {
for ( V_93 = V_105 + 1 ; V_93 < V_78 -> V_44 ; V_93 ++ ) {
if ( V_78 -> V_112 [ V_105 ] . V_12 == V_78 -> V_112 [ V_93 ] . V_12 ) {
F_4 ( L_19 ,
V_78 -> V_112 [ V_105 ] . V_12 ) ;
return - V_34 ;
}
if ( ! strcmp ( V_78 -> V_112 [ V_105 ] . V_100 , V_78 -> V_112 [ V_93 ] . V_100 ) ) {
F_4 ( L_20 ,
V_78 -> V_112 [ V_105 ] . V_100 ) ;
return - V_34 ;
}
}
}
F_54 ( & V_107 ) ;
for ( V_105 = 0 ; V_105 < V_78 -> V_44 ; V_105 ++ ) {
int V_12 = V_78 -> V_112 [ V_105 ] . V_12 ;
int V_95 = V_78 -> V_112 [ V_105 ] . V_95 ;
const char * V_100 = V_78 -> V_112 [ V_105 ] . V_100 ;
V_109 = F_55 ( sizeof( struct V_108 ) , V_113 ) ;
if ( ! V_109 ) {
V_4 = - V_57 ;
goto V_114;
}
V_109 -> V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_109 -> V_2 ) ) {
V_4 = F_14 ( V_109 -> V_2 ) ;
F_4 ( L_21 , V_12 , V_4 ) ;
F_56 ( V_109 ) ;
goto V_114;
}
if ( V_109 -> V_2 -> V_6 -> V_95 == V_95 &&
! memcmp ( V_109 -> V_2 -> V_6 -> V_100 , V_100 , V_95 ) ) {
F_18 ( V_109 -> V_2 ) ;
F_56 ( V_109 ) ;
continue;
}
V_109 -> V_115 = V_95 ;
memcpy ( V_109 -> V_116 , V_100 , V_95 ) ;
F_57 ( & V_109 -> V_117 , & V_107 ) ;
F_11 ( L_22 ,
V_12 , V_109 -> V_2 -> V_6 -> V_100 , V_100 ) ;
}
if ( F_58 ( & V_107 ) )
return 0 ;
F_59 (re, &rename_list, list) {
struct V_1 * V_2 ;
int V_118 = 0 ;
F_59 (re1, &rename_list, list) {
if ( V_109 -> V_115 == V_110 -> V_2 -> V_6 -> V_95 &&
! memcmp ( V_109 -> V_116 , V_110 -> V_2 -> V_6 -> V_100 ,
V_110 -> V_2 -> V_6 -> V_95 ) ) {
V_118 = 1 ;
break;
}
}
if ( V_118 )
continue;
V_2 = F_60 ( V_7 -> V_20 , V_109 -> V_116 ,
V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 == - V_119 )
continue;
F_4 ( L_23 ,
V_109 -> V_116 , V_4 ) ;
goto V_114;
}
V_110 = F_55 ( sizeof( struct V_108 ) , V_113 ) ;
if ( ! V_110 ) {
V_4 = - V_57 ;
F_18 ( V_2 ) ;
goto V_114;
}
V_110 -> remove = 1 ;
V_110 -> V_2 = V_2 ;
F_61 ( & V_110 -> V_117 , & V_107 ) ;
F_11 ( L_24 ,
V_110 -> V_2 -> V_6 -> V_12 , V_110 -> V_2 -> V_6 -> V_100 ) ;
}
F_21 ( & V_7 -> V_89 ) ;
V_4 = F_62 ( V_7 , & V_107 ) ;
F_23 ( & V_7 -> V_89 ) ;
V_114:
F_63 (re, re1, &rename_list, list) {
F_18 ( V_109 -> V_2 ) ;
F_64 ( & V_109 -> V_117 ) ;
F_56 ( V_109 ) ;
}
return V_4 ;
}
static long F_65 ( struct V_19 * V_19 , unsigned int V_66 ,
unsigned long V_67 )
{
int V_4 = 0 ;
struct V_38 * V_7 ;
struct V_1 * V_2 ;
void T_3 * V_68 = ( void T_3 * ) V_67 ;
if ( ! F_40 ( V_72 ) )
return - V_60 ;
V_7 = F_66 ( F_10 ( V_19 -> V_120 -> V_121 ) ) ;
if ( ! V_7 )
return - V_119 ;
switch ( V_66 ) {
case V_122 :
{
struct V_92 V_78 ;
F_11 ( L_25 ) ;
V_4 = F_32 ( & V_78 , V_68 , sizeof( struct V_92 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_49 ( V_7 , & V_78 ) ;
if ( V_4 )
break;
F_21 ( & V_7 -> V_89 ) ;
V_4 = F_67 ( V_7 , & V_78 ) ;
F_23 ( & V_7 -> V_89 ) ;
if ( V_4 )
break;
V_4 = F_68 ( V_78 . V_12 , ( T_3 T_6 * ) V_68 ) ;
if ( V_4 )
V_4 = - V_58 ;
break;
}
case V_123 :
{
int V_12 ;
F_11 ( L_26 ) ;
V_4 = F_43 ( V_12 , ( T_3 T_6 * ) V_68 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
F_21 ( & V_7 -> V_89 ) ;
V_4 = F_69 ( V_2 , 0 ) ;
F_23 ( & V_7 -> V_89 ) ;
F_18 ( V_2 ) ;
break;
}
case V_124 :
{
int V_125 ;
struct V_103 V_78 ;
F_11 ( L_27 ) ;
V_4 = F_32 ( & V_78 , V_68 , sizeof( struct V_103 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_52 ( V_7 , & V_78 ) ;
if ( V_4 )
break;
V_2 = F_12 ( V_7 -> V_20 , V_78 . V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
V_125 = F_70 ( V_78 . V_70 + V_2 -> V_6 -> V_55 - 1 ,
V_2 -> V_6 -> V_55 ) ;
F_21 ( & V_7 -> V_89 ) ;
V_4 = F_71 ( V_2 , V_125 ) ;
F_23 ( & V_7 -> V_89 ) ;
F_18 ( V_2 ) ;
break;
}
case V_126 :
{
struct V_104 * V_78 ;
F_11 ( L_28 ) ;
V_78 = F_72 ( sizeof( struct V_104 ) , V_113 ) ;
if ( ! V_78 ) {
V_4 = - V_57 ;
break;
} ;
V_4 = F_32 ( V_78 , V_68 , sizeof( struct V_104 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
F_56 ( V_78 ) ;
break;
}
V_4 = F_53 ( V_7 , V_78 ) ;
F_56 ( V_78 ) ;
break;
}
default:
V_4 = - V_91 ;
break;
}
F_73 ( V_7 ) ;
return V_4 ;
}
static long F_74 ( struct V_19 * V_19 , unsigned int V_66 ,
unsigned long V_67 )
{
int V_4 = 0 ;
void T_3 * V_68 = ( void T_3 * ) V_67 ;
if ( ! F_40 ( V_72 ) )
return - V_60 ;
switch ( V_66 ) {
case V_127 :
{
struct V_128 V_78 ;
struct V_129 * V_130 ;
F_11 ( L_29 ) ;
V_4 = F_32 ( & V_78 , V_68 , sizeof( struct V_128 ) ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
if ( V_78 . V_131 < 0 ||
( V_78 . V_20 < 0 && V_78 . V_20 != V_132 ) ) {
V_4 = - V_34 ;
break;
}
V_130 = F_75 ( NULL , V_78 . V_131 ) ;
if ( F_13 ( V_130 ) ) {
V_4 = F_14 ( V_130 ) ;
break;
}
F_21 ( & V_133 ) ;
V_4 = F_76 ( V_130 , V_78 . V_20 , V_78 . V_134 ,
V_78 . V_135 ) ;
F_23 ( & V_133 ) ;
if ( V_4 < 0 )
F_77 ( V_130 ) ;
else
V_4 = F_68 ( V_4 , ( T_3 T_6 * ) V_68 ) ;
break;
}
case V_136 :
{
int V_20 ;
F_11 ( L_30 ) ;
V_4 = F_43 ( V_20 , ( T_3 T_6 * ) V_68 ) ;
if ( V_4 ) {
V_4 = - V_58 ;
break;
}
F_21 ( & V_133 ) ;
V_4 = F_78 ( V_20 , 0 ) ;
F_23 ( & V_133 ) ;
break;
}
default:
V_4 = - V_91 ;
break;
}
return V_4 ;
}
static long F_79 ( struct V_19 * V_19 , unsigned int V_66 ,
unsigned long V_67 )
{
unsigned long V_137 = ( unsigned long ) F_80 ( V_67 ) ;
return F_39 ( V_19 , V_66 , V_137 ) ;
}
static long F_81 ( struct V_19 * V_19 , unsigned int V_66 ,
unsigned long V_67 )
{
unsigned long V_137 = ( unsigned long ) F_80 ( V_67 ) ;
return F_65 ( V_19 , V_66 , V_137 ) ;
}
static long F_82 ( struct V_19 * V_19 , unsigned int V_66 ,
unsigned long V_67 )
{
unsigned long V_137 = ( unsigned long ) F_80 ( V_67 ) ;
return F_74 ( V_19 , V_66 , V_137 ) ;
}

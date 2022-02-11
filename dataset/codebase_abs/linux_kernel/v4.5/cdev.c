static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( & V_6 -> V_7 -> V_8 ) ;
V_3 = V_6 -> V_9 + V_6 -> V_10 + V_6 -> V_11 + V_6 -> V_12 ;
F_3 ( V_3 > 0 ) ;
if ( V_3 > 1 ) {
F_4 ( V_6 -> V_7 , L_1 , V_3 , V_6 -> V_13 ) ;
V_4 = - V_14 ;
} else {
V_6 -> V_9 = V_6 -> V_10 = V_6 -> V_12 = 0 ;
V_6 -> V_11 = 1 ;
V_4 = V_2 -> V_15 ;
V_2 -> V_15 = V_16 ;
}
F_5 ( & V_6 -> V_7 -> V_8 ) ;
return V_4 ;
}
static void F_6 ( struct V_1 * V_2 , int V_15 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_2 ( & V_6 -> V_7 -> V_8 ) ;
F_3 ( V_6 -> V_9 == 0 && V_6 -> V_10 == 0 && V_6 -> V_12 == 0 ) ;
F_3 ( V_6 -> V_11 == 1 && V_2 -> V_15 == V_16 ) ;
V_6 -> V_11 = 0 ;
if ( V_15 == V_17 )
V_6 -> V_9 = 1 ;
else if ( V_15 == V_18 )
V_6 -> V_10 = 1 ;
else if ( V_15 == V_19 )
V_6 -> V_12 = 1 ;
else
V_6 -> V_11 = 1 ;
F_5 ( & V_6 -> V_7 -> V_8 ) ;
V_2 -> V_15 = V_15 ;
}
static int F_7 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
struct V_1 * V_2 ;
int V_13 = F_8 ( V_20 ) - 1 , V_15 , V_22 ;
V_22 = F_9 ( F_10 ( V_20 ) ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_21 -> V_23 & V_24 )
V_15 = V_18 ;
else
V_15 = V_17 ;
F_11 ( L_2 ,
V_22 , V_13 , V_15 ) ;
V_2 = F_12 ( V_22 , V_13 , V_15 ) ;
if ( F_13 ( V_2 ) )
return F_14 ( V_2 ) ;
V_21 -> V_25 = V_2 ;
return 0 ;
}
static int F_15 ( struct V_20 * V_20 , struct V_21 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_11 ( L_3 ,
V_6 -> V_7 -> V_22 , V_6 -> V_13 , V_2 -> V_15 ) ;
if ( V_6 -> V_26 ) {
F_16 ( V_6 -> V_7 , L_4 ,
V_6 -> V_13 ) ;
F_3 ( ! V_6 -> V_27 ) ;
V_6 -> V_26 = 0 ;
F_17 ( V_6 -> V_28 ) ;
} else if ( V_6 -> V_27 ) {
F_11 ( L_5 ,
V_6 -> V_29 , V_6 -> V_30 , V_6 -> V_7 -> V_22 ,
V_6 -> V_13 ) ;
V_6 -> V_27 = 0 ;
F_17 ( V_6 -> V_28 ) ;
}
F_18 ( V_2 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_21 * V_21 , T_1 V_31 , int V_32 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_26 ) {
F_4 ( V_6 -> V_7 , L_6 ) ;
return - V_14 ;
}
return F_20 ( V_21 , V_31 , V_32 , V_6 -> V_33 ) ;
}
static int F_21 ( struct V_21 * V_21 , T_1 V_34 , T_1 V_35 ,
int V_36 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_37 * V_7 = V_2 -> V_6 -> V_7 ;
struct V_20 * V_20 = F_22 ( V_21 ) ;
int V_4 ;
F_23 ( V_20 ) ;
V_4 = F_24 ( V_7 -> V_22 ) ;
F_25 ( V_20 ) ;
return V_4 ;
}
static T_2 F_26 ( struct V_21 * V_21 , T_3 char * V_38 , T_4 V_39 ,
T_1 * V_40 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_7 = V_6 -> V_7 ;
int V_4 , V_41 , V_42 , V_43 , V_44 ;
T_4 V_45 = V_39 ;
void * V_46 ;
F_11 ( L_7 ,
V_39 , * V_40 , V_6 -> V_13 ) ;
if ( V_6 -> V_26 ) {
F_4 ( V_6 -> V_7 , L_6 ) ;
return - V_14 ;
}
if ( V_6 -> V_47 ) {
F_4 ( V_6 -> V_7 , L_8 ) ;
return - V_48 ;
}
if ( * V_40 == V_6 -> V_33 || V_39 == 0 )
return 0 ;
if ( V_6 -> V_49 )
F_11 ( L_9 , V_6 -> V_13 ) ;
if ( * V_40 + V_39 > V_6 -> V_33 )
V_45 = V_39 = V_6 -> V_33 - * V_40 ;
V_44 = V_6 -> V_50 ;
if ( V_39 < V_44 )
V_44 = F_27 ( V_39 , V_7 -> V_51 ) ;
V_46 = F_28 ( V_44 ) ;
if ( ! V_46 )
return - V_52 ;
V_43 = V_39 > V_44 ? V_44 : V_39 ;
V_41 = F_29 ( * V_40 , V_6 -> V_50 , & V_42 ) ;
do {
F_30 () ;
if ( V_42 + V_43 >= V_6 -> V_50 )
V_43 = V_6 -> V_50 - V_42 ;
V_4 = F_31 ( V_7 , V_6 , V_41 , V_46 , V_42 , V_43 , 0 ) ;
if ( V_4 )
break;
V_42 += V_43 ;
if ( V_42 == V_6 -> V_50 ) {
V_41 += 1 ;
V_42 -= V_6 -> V_50 ;
}
V_39 -= V_43 ;
* V_40 += V_43 ;
V_4 = F_32 ( V_38 , V_46 , V_43 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_38 += V_43 ;
V_43 = V_39 > V_44 ? V_44 : V_39 ;
} while ( V_39 );
F_17 ( V_46 ) ;
return V_4 ? V_4 : V_45 - V_39 ;
}
static T_2 F_33 ( struct V_21 * V_21 , const char T_3 * V_38 ,
T_4 V_39 , T_1 * V_40 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_7 = V_6 -> V_7 ;
int V_41 , V_42 , V_43 , V_44 , V_4 = 0 ;
T_4 V_45 = V_39 ;
char * V_46 ;
if ( ! V_6 -> V_54 )
return - V_55 ;
F_11 ( L_10 ,
V_39 , * V_40 , V_6 -> V_13 ) ;
if ( V_6 -> V_56 == V_57 )
return - V_58 ;
V_41 = F_29 ( * V_40 , V_6 -> V_50 , & V_42 ) ;
if ( V_42 & ( V_7 -> V_51 - 1 ) ) {
F_4 ( V_7 , L_11 ) ;
return - V_59 ;
}
if ( * V_40 + V_39 > V_6 -> V_33 )
V_45 = V_39 = V_6 -> V_33 - * V_40 ;
if ( V_39 & ( V_7 -> V_51 - 1 ) ) {
F_4 ( V_7 , L_12 ) ;
return - V_59 ;
}
V_44 = V_6 -> V_50 ;
if ( V_39 < V_44 )
V_44 = F_27 ( V_39 , V_7 -> V_51 ) ;
V_46 = F_28 ( V_44 ) ;
if ( ! V_46 )
return - V_52 ;
V_43 = V_39 > V_44 ? V_44 : V_39 ;
while ( V_39 ) {
F_30 () ;
if ( V_42 + V_43 >= V_6 -> V_50 )
V_43 = V_6 -> V_50 - V_42 ;
V_4 = F_34 ( V_46 , V_38 , V_43 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_35 ( V_7 , V_6 , V_41 , V_46 , V_42 , V_43 ) ;
if ( V_4 )
break;
V_42 += V_43 ;
if ( V_42 == V_6 -> V_50 ) {
V_41 += 1 ;
V_42 -= V_6 -> V_50 ;
}
V_39 -= V_43 ;
* V_40 += V_43 ;
V_38 += V_43 ;
V_43 = V_39 > V_44 ? V_44 : V_39 ;
}
F_17 ( V_46 ) ;
return V_4 ? V_4 : V_45 - V_39 ;
}
static T_2 F_36 ( struct V_21 * V_21 , const char T_3 * V_38 ,
T_4 V_39 , T_1 * V_40 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_7 = V_6 -> V_7 ;
if ( ! V_6 -> V_26 && ! V_6 -> V_27 )
return F_33 ( V_21 , V_38 , V_39 , V_40 ) ;
if ( V_6 -> V_26 )
V_4 = F_37 ( V_7 , V_6 , V_38 , V_39 ) ;
else
V_4 = F_38 ( V_7 , V_6 , V_38 , V_39 ) ;
if ( V_4 < 0 ) {
F_4 ( V_7 , L_13 ,
V_39 , V_4 ) ;
return V_4 ;
}
if ( V_4 ) {
V_39 = V_4 ;
if ( V_6 -> V_27 ) {
F_6 ( V_2 , V_18 ) ;
return V_39 ;
}
V_4 = F_39 ( V_7 , V_6 -> V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 ) {
F_16 ( V_7 , L_14 ,
V_6 -> V_13 , V_7 -> V_22 ) ;
V_6 -> V_49 = 1 ;
}
V_6 -> V_60 = 1 ;
F_40 ( V_7 , V_6 , V_61 ) ;
F_6 ( V_2 , V_18 ) ;
}
return V_39 ;
}
static long F_41 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_7 = V_6 -> V_7 ;
void T_3 * V_64 = ( void T_3 * ) V_63 ;
switch ( V_62 ) {
case V_65 :
{
T_5 V_66 , V_67 ;
if ( ! F_42 ( V_68 ) ) {
V_4 = - V_55 ;
break;
}
V_4 = F_34 ( & V_66 , V_64 , sizeof( T_5 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
if ( V_2 -> V_15 == V_17 ) {
V_4 = - V_58 ;
break;
}
V_67 = ( long long ) V_6 -> V_69 *
V_7 -> V_70 - V_6 -> V_71 ;
if ( V_66 < 0 || V_66 > V_67 ) {
V_4 = - V_59 ;
break;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_43 ( V_7 , V_6 , V_66 ) ;
if ( V_66 == 0 ) {
F_40 ( V_7 , V_6 , V_61 ) ;
F_6 ( V_2 , V_18 ) ;
}
break;
}
case V_72 :
{
struct V_73 V_74 ;
V_4 = F_34 ( & V_74 , V_64 ,
sizeof( struct V_73 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
if ( V_2 -> V_15 == V_17 ||
V_6 -> V_56 == V_57 ) {
V_4 = - V_58 ;
break;
}
V_4 = - V_59 ;
if ( V_74 . V_41 < 0 || V_74 . V_41 >= V_6 -> V_69 ||
V_74 . V_66 < 0 || V_74 . V_66 > V_6 -> V_50 )
break;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_44 ( V_7 , V_6 , & V_74 ) ;
if ( V_74 . V_66 == 0 )
F_6 ( V_2 , V_18 ) ;
break;
}
case V_75 :
{
T_6 V_41 ;
V_4 = F_45 ( V_41 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
if ( V_2 -> V_15 == V_17 ||
V_6 -> V_56 == V_57 ) {
V_4 = - V_58 ;
break;
}
if ( V_41 < 0 || V_41 >= V_6 -> V_69 ) {
V_4 = - V_59 ;
break;
}
F_11 ( L_15 , V_6 -> V_13 , V_41 ) ;
V_4 = F_46 ( V_7 , V_6 , V_41 ) ;
if ( V_4 )
break;
V_4 = F_47 ( V_7 , V_76 , V_76 ) ;
break;
}
case V_77 :
{
struct V_78 V_74 ;
V_4 = F_34 ( & V_74 , V_64 , sizeof( struct V_78 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_48 ( V_2 , V_74 . V_41 ) ;
break;
}
case V_79 :
{
T_6 V_41 ;
V_4 = F_45 ( V_41 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_49 ( V_2 , V_41 ) ;
break;
}
case V_80 :
{
T_6 V_41 ;
V_4 = F_45 ( V_41 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_50 ( V_2 , V_41 ) ;
break;
}
case V_81 :
{
struct V_82 V_74 ;
V_4 = F_34 ( & V_74 , V_64 ,
sizeof( struct V_82 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
switch ( V_74 . V_83 ) {
case V_84 :
F_51 ( & V_7 -> V_85 ) ;
V_2 -> V_6 -> V_54 = ! ! V_74 . V_86 ;
F_52 ( & V_7 -> V_85 ) ;
break;
default:
V_4 = - V_59 ;
break;
}
break;
}
case V_87 :
{
struct V_88 V_89 ;
F_53 ( V_2 , & V_89 ) ;
V_4 = F_54 ( & V_89 ) ;
break;
}
case V_90 :
{
struct V_88 V_89 ;
F_53 ( V_2 , & V_89 ) ;
V_4 = F_55 ( & V_89 ) ;
break;
}
default:
V_4 = - V_91 ;
break;
}
return V_4 ;
}
static int F_56 ( const struct V_37 * V_7 ,
const struct V_92 * V_74 )
{
int V_93 , V_4 = - V_59 ;
if ( V_74 -> V_66 < 0 || V_74 -> V_94 < 0 || V_74 -> V_56 < 0 ||
V_74 -> V_95 < 0 )
goto V_96;
if ( ( V_74 -> V_13 < 0 || V_74 -> V_13 >= V_7 -> V_97 ) &&
V_74 -> V_13 != V_98 )
goto V_96;
if ( V_74 -> V_94 == 0 )
goto V_96;
if ( V_74 -> V_66 == 0 )
goto V_96;
if ( V_74 -> V_56 != V_99 &&
V_74 -> V_56 != V_57 )
goto V_96;
if ( V_74 -> V_94 > V_7 -> V_70 )
goto V_96;
V_93 = V_74 -> V_94 & ( V_7 -> V_51 - 1 ) ;
if ( V_74 -> V_94 != 1 && V_93 )
goto V_96;
if ( ! V_74 -> V_100 [ 0 ] || ! V_74 -> V_95 )
goto V_96;
if ( V_74 -> V_95 > V_101 ) {
V_4 = - V_102 ;
goto V_96;
}
V_93 = F_57 ( V_74 -> V_100 , V_74 -> V_95 + 1 ) ;
if ( V_93 != V_74 -> V_95 )
goto V_96;
return 0 ;
V_96:
F_4 ( V_7 , L_16 ) ;
F_58 ( V_74 ) ;
return V_4 ;
}
static int F_59 ( const struct V_37 * V_7 ,
const struct V_103 * V_74 )
{
if ( V_74 -> V_66 <= 0 )
return - V_59 ;
if ( V_74 -> V_13 < 0 || V_74 -> V_13 >= V_7 -> V_97 )
return - V_59 ;
return 0 ;
}
static int F_60 ( struct V_37 * V_7 ,
struct V_104 * V_74 )
{
int V_105 , V_93 , V_4 ;
struct V_106 V_107 ;
struct V_108 * V_109 , * V_110 ;
if ( V_74 -> V_39 < 0 || V_74 -> V_39 > V_111 )
return - V_59 ;
if ( V_74 -> V_39 == 0 )
return 0 ;
for ( V_105 = 0 ; V_105 < V_74 -> V_39 ; V_105 ++ ) {
if ( V_74 -> V_112 [ V_105 ] . V_13 < 0 ||
V_74 -> V_112 [ V_105 ] . V_13 >= V_7 -> V_97 )
return - V_59 ;
if ( V_74 -> V_112 [ V_105 ] . V_95 < 0 )
return - V_59 ;
if ( V_74 -> V_112 [ V_105 ] . V_95 > V_101 )
return - V_102 ;
V_74 -> V_112 [ V_105 ] . V_100 [ V_74 -> V_112 [ V_105 ] . V_95 ] = '\0' ;
V_93 = strlen ( V_74 -> V_112 [ V_105 ] . V_100 ) ;
if ( V_93 != V_74 -> V_112 [ V_105 ] . V_95 )
return - V_59 ;
}
for ( V_105 = 0 ; V_105 < V_74 -> V_39 - 1 ; V_105 ++ ) {
for ( V_93 = V_105 + 1 ; V_93 < V_74 -> V_39 ; V_93 ++ ) {
if ( V_74 -> V_112 [ V_105 ] . V_13 == V_74 -> V_112 [ V_93 ] . V_13 ) {
F_4 ( V_7 , L_17 ,
V_74 -> V_112 [ V_105 ] . V_13 ) ;
return - V_59 ;
}
if ( ! strcmp ( V_74 -> V_112 [ V_105 ] . V_100 , V_74 -> V_112 [ V_93 ] . V_100 ) ) {
F_4 ( V_7 , L_18 ,
V_74 -> V_112 [ V_105 ] . V_100 ) ;
return - V_59 ;
}
}
}
F_61 ( & V_107 ) ;
for ( V_105 = 0 ; V_105 < V_74 -> V_39 ; V_105 ++ ) {
int V_13 = V_74 -> V_112 [ V_105 ] . V_13 ;
int V_95 = V_74 -> V_112 [ V_105 ] . V_95 ;
const char * V_100 = V_74 -> V_112 [ V_105 ] . V_100 ;
V_109 = F_62 ( sizeof( struct V_108 ) , V_113 ) ;
if ( ! V_109 ) {
V_4 = - V_52 ;
goto V_114;
}
V_109 -> V_2 = F_12 ( V_7 -> V_22 , V_13 , V_19 ) ;
if ( F_13 ( V_109 -> V_2 ) ) {
V_4 = F_14 ( V_109 -> V_2 ) ;
F_4 ( V_7 , L_19 ,
V_13 , V_4 ) ;
F_63 ( V_109 ) ;
goto V_114;
}
if ( V_109 -> V_2 -> V_6 -> V_95 == V_95 &&
! memcmp ( V_109 -> V_2 -> V_6 -> V_100 , V_100 , V_95 ) ) {
F_18 ( V_109 -> V_2 ) ;
F_63 ( V_109 ) ;
continue;
}
V_109 -> V_115 = V_95 ;
memcpy ( V_109 -> V_116 , V_100 , V_95 ) ;
F_64 ( & V_109 -> V_117 , & V_107 ) ;
F_11 ( L_20 ,
V_13 , V_109 -> V_2 -> V_6 -> V_100 , V_100 ) ;
}
if ( F_65 ( & V_107 ) )
return 0 ;
F_66 (re, &rename_list, list) {
struct V_1 * V_2 ;
int V_118 = 0 ;
F_66 (re1, &rename_list, list) {
if ( V_109 -> V_115 == V_110 -> V_2 -> V_6 -> V_95 &&
! memcmp ( V_109 -> V_116 , V_110 -> V_2 -> V_6 -> V_100 ,
V_110 -> V_2 -> V_6 -> V_95 ) ) {
V_118 = 1 ;
break;
}
}
if ( V_118 )
continue;
V_2 = F_67 ( V_7 -> V_22 , V_109 -> V_116 ,
V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 == - V_119 )
continue;
F_4 ( V_7 , L_21 ,
V_109 -> V_116 , V_4 ) ;
goto V_114;
}
V_110 = F_62 ( sizeof( struct V_108 ) , V_113 ) ;
if ( ! V_110 ) {
V_4 = - V_52 ;
F_18 ( V_2 ) ;
goto V_114;
}
V_110 -> remove = 1 ;
V_110 -> V_2 = V_2 ;
F_68 ( & V_110 -> V_117 , & V_107 ) ;
F_11 ( L_22 ,
V_110 -> V_2 -> V_6 -> V_13 , V_110 -> V_2 -> V_6 -> V_100 ) ;
}
F_51 ( & V_7 -> V_85 ) ;
V_4 = F_69 ( V_7 , & V_107 ) ;
F_52 ( & V_7 -> V_85 ) ;
V_114:
F_70 (re, re1, &rename_list, list) {
F_18 ( V_109 -> V_2 ) ;
F_71 ( & V_109 -> V_117 ) ;
F_63 ( V_109 ) ;
}
return V_4 ;
}
static long F_72 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
int V_4 = 0 ;
struct V_37 * V_7 ;
struct V_1 * V_2 ;
void T_3 * V_64 = ( void T_3 * ) V_63 ;
if ( ! F_42 ( V_68 ) )
return - V_55 ;
V_7 = F_73 ( F_10 ( V_21 -> V_120 -> V_121 ) ) ;
if ( ! V_7 )
return - V_119 ;
switch ( V_62 ) {
case V_122 :
{
struct V_92 V_74 ;
F_11 ( L_23 ) ;
V_4 = F_34 ( & V_74 , V_64 , sizeof( struct V_92 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_56 ( V_7 , & V_74 ) ;
if ( V_4 )
break;
F_51 ( & V_7 -> V_85 ) ;
V_4 = F_74 ( V_7 , & V_74 ) ;
F_52 ( & V_7 -> V_85 ) ;
if ( V_4 )
break;
V_4 = F_75 ( V_74 . V_13 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 )
V_4 = - V_53 ;
break;
}
case V_123 :
{
int V_13 ;
F_11 ( L_24 ) ;
V_4 = F_45 ( V_13 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_2 = F_12 ( V_7 -> V_22 , V_13 , V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
F_51 ( & V_7 -> V_85 ) ;
V_4 = F_76 ( V_2 , 0 ) ;
F_52 ( & V_7 -> V_85 ) ;
F_18 ( V_2 ) ;
break;
}
case V_124 :
{
int V_125 ;
struct V_103 V_74 ;
F_11 ( L_25 ) ;
V_4 = F_34 ( & V_74 , V_64 , sizeof( struct V_103 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_59 ( V_7 , & V_74 ) ;
if ( V_4 )
break;
V_2 = F_12 ( V_7 -> V_22 , V_74 . V_13 , V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
V_125 = F_77 ( V_74 . V_66 + V_2 -> V_6 -> V_50 - 1 ,
V_2 -> V_6 -> V_50 ) ;
F_51 ( & V_7 -> V_85 ) ;
V_4 = F_78 ( V_2 , V_125 ) ;
F_52 ( & V_7 -> V_85 ) ;
F_18 ( V_2 ) ;
break;
}
case V_126 :
{
struct V_104 * V_74 ;
F_11 ( L_26 ) ;
V_74 = F_79 ( sizeof( struct V_104 ) , V_113 ) ;
if ( ! V_74 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_34 ( V_74 , V_64 , sizeof( struct V_104 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
F_63 ( V_74 ) ;
break;
}
V_4 = F_60 ( V_7 , V_74 ) ;
F_63 ( V_74 ) ;
break;
}
default:
V_4 = - V_91 ;
break;
}
F_80 ( V_7 ) ;
return V_4 ;
}
static long F_81 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
int V_4 = 0 ;
void T_3 * V_64 = ( void T_3 * ) V_63 ;
if ( ! F_42 ( V_68 ) )
return - V_55 ;
switch ( V_62 ) {
case V_127 :
{
struct V_128 V_74 ;
struct V_129 * V_130 ;
F_11 ( L_27 ) ;
V_4 = F_34 ( & V_74 , V_64 , sizeof( struct V_128 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
if ( V_74 . V_131 < 0 ||
( V_74 . V_22 < 0 && V_74 . V_22 != V_132 ) ) {
V_4 = - V_59 ;
break;
}
V_130 = F_82 ( NULL , V_74 . V_131 ) ;
if ( F_13 ( V_130 ) ) {
V_4 = F_14 ( V_130 ) ;
break;
}
F_51 ( & V_133 ) ;
V_4 = F_83 ( V_130 , V_74 . V_22 , V_74 . V_134 ,
V_74 . V_135 ) ;
F_52 ( & V_133 ) ;
if ( V_4 < 0 )
F_84 ( V_130 ) ;
else
V_4 = F_75 ( V_4 , ( T_3 T_6 * ) V_64 ) ;
break;
}
case V_136 :
{
int V_22 ;
F_11 ( L_28 ) ;
V_4 = F_45 ( V_22 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
F_51 ( & V_133 ) ;
V_4 = F_85 ( V_22 , 0 ) ;
F_52 ( & V_133 ) ;
break;
}
default:
V_4 = - V_91 ;
break;
}
return V_4 ;
}
static long F_86 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
unsigned long V_137 = ( unsigned long ) F_87 ( V_63 ) ;
return F_41 ( V_21 , V_62 , V_137 ) ;
}
static long F_88 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
unsigned long V_137 = ( unsigned long ) F_87 ( V_63 ) ;
return F_72 ( V_21 , V_62 , V_137 ) ;
}
static long F_89 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
unsigned long V_137 = ( unsigned long ) F_87 ( V_63 ) ;
return F_81 ( V_21 , V_62 , V_137 ) ;
}

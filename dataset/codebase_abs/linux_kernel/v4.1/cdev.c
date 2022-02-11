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
F_23 ( & V_20 -> V_38 ) ;
V_4 = F_24 ( V_7 -> V_22 ) ;
F_25 ( & V_20 -> V_38 ) ;
return V_4 ;
}
static T_2 F_26 ( struct V_21 * V_21 , T_3 char * V_39 , T_4 V_40 ,
T_1 * V_41 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_7 = V_6 -> V_7 ;
int V_4 , V_42 , V_43 , V_44 , V_45 ;
T_4 V_46 = V_40 ;
void * V_47 ;
F_11 ( L_7 ,
V_40 , * V_41 , V_6 -> V_13 ) ;
if ( V_6 -> V_26 ) {
F_4 ( V_6 -> V_7 , L_6 ) ;
return - V_14 ;
}
if ( V_6 -> V_48 ) {
F_4 ( V_6 -> V_7 , L_8 ) ;
return - V_49 ;
}
if ( * V_41 == V_6 -> V_33 || V_40 == 0 )
return 0 ;
if ( V_6 -> V_50 )
F_11 ( L_9 , V_6 -> V_13 ) ;
if ( * V_41 + V_40 > V_6 -> V_33 )
V_46 = V_40 = V_6 -> V_33 - * V_41 ;
V_45 = V_6 -> V_51 ;
if ( V_40 < V_45 )
V_45 = F_27 ( V_40 , V_7 -> V_52 ) ;
V_47 = F_28 ( V_45 ) ;
if ( ! V_47 )
return - V_53 ;
V_44 = V_40 > V_45 ? V_45 : V_40 ;
V_42 = F_29 ( * V_41 , V_6 -> V_51 , & V_43 ) ;
do {
F_30 () ;
if ( V_43 + V_44 >= V_6 -> V_51 )
V_44 = V_6 -> V_51 - V_43 ;
V_4 = F_31 ( V_7 , V_6 , V_42 , V_47 , V_43 , V_44 , 0 ) ;
if ( V_4 )
break;
V_43 += V_44 ;
if ( V_43 == V_6 -> V_51 ) {
V_42 += 1 ;
V_43 -= V_6 -> V_51 ;
}
V_40 -= V_44 ;
* V_41 += V_44 ;
V_4 = F_32 ( V_39 , V_47 , V_44 ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
V_39 += V_44 ;
V_44 = V_40 > V_45 ? V_45 : V_40 ;
} while ( V_40 );
F_17 ( V_47 ) ;
return V_4 ? V_4 : V_46 - V_40 ;
}
static T_2 F_33 ( struct V_21 * V_21 , const char T_3 * V_39 ,
T_4 V_40 , T_1 * V_41 )
{
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_7 = V_6 -> V_7 ;
int V_42 , V_43 , V_44 , V_45 , V_4 = 0 ;
T_4 V_46 = V_40 ;
char * V_47 ;
if ( ! V_6 -> V_55 )
return - V_56 ;
F_11 ( L_10 ,
V_40 , * V_41 , V_6 -> V_13 ) ;
if ( V_6 -> V_57 == V_58 )
return - V_59 ;
V_42 = F_29 ( * V_41 , V_6 -> V_51 , & V_43 ) ;
if ( V_43 & ( V_7 -> V_52 - 1 ) ) {
F_4 ( V_7 , L_11 ) ;
return - V_60 ;
}
if ( * V_41 + V_40 > V_6 -> V_33 )
V_46 = V_40 = V_6 -> V_33 - * V_41 ;
if ( V_40 & ( V_7 -> V_52 - 1 ) ) {
F_4 ( V_7 , L_12 ) ;
return - V_60 ;
}
V_45 = V_6 -> V_51 ;
if ( V_40 < V_45 )
V_45 = F_27 ( V_40 , V_7 -> V_52 ) ;
V_47 = F_28 ( V_45 ) ;
if ( ! V_47 )
return - V_53 ;
V_44 = V_40 > V_45 ? V_45 : V_40 ;
while ( V_40 ) {
F_30 () ;
if ( V_43 + V_44 >= V_6 -> V_51 )
V_44 = V_6 -> V_51 - V_43 ;
V_4 = F_34 ( V_47 , V_39 , V_44 ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
V_4 = F_35 ( V_7 , V_6 , V_42 , V_47 , V_43 , V_44 ) ;
if ( V_4 )
break;
V_43 += V_44 ;
if ( V_43 == V_6 -> V_51 ) {
V_42 += 1 ;
V_43 -= V_6 -> V_51 ;
}
V_40 -= V_44 ;
* V_41 += V_44 ;
V_39 += V_44 ;
V_44 = V_40 > V_45 ? V_45 : V_40 ;
}
F_17 ( V_47 ) ;
return V_4 ? V_4 : V_46 - V_40 ;
}
static T_2 F_36 ( struct V_21 * V_21 , const char T_3 * V_39 ,
T_4 V_40 , T_1 * V_41 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_7 = V_6 -> V_7 ;
if ( ! V_6 -> V_26 && ! V_6 -> V_27 )
return F_33 ( V_21 , V_39 , V_40 , V_41 ) ;
if ( V_6 -> V_26 )
V_4 = F_37 ( V_7 , V_6 , V_39 , V_40 ) ;
else
V_4 = F_38 ( V_7 , V_6 , V_39 , V_40 ) ;
if ( V_4 < 0 ) {
F_4 ( V_7 , L_13 ,
V_40 , V_4 ) ;
return V_4 ;
}
if ( V_4 ) {
V_40 = V_4 ;
if ( V_6 -> V_27 ) {
F_6 ( V_2 , V_18 ) ;
return V_40 ;
}
V_4 = F_39 ( V_7 , V_6 -> V_13 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 ) {
F_16 ( V_7 , L_14 ,
V_6 -> V_13 , V_7 -> V_22 ) ;
V_6 -> V_50 = 1 ;
}
V_6 -> V_61 = 1 ;
F_40 ( V_7 , V_6 , V_62 ) ;
F_6 ( V_2 , V_18 ) ;
}
return V_40 ;
}
static long F_41 ( struct V_21 * V_21 , unsigned int V_63 ,
unsigned long V_64 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_21 -> V_25 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_37 * V_7 = V_6 -> V_7 ;
void T_3 * V_65 = ( void T_3 * ) V_64 ;
switch ( V_63 ) {
case V_66 :
{
T_5 V_67 , V_68 ;
if ( ! F_42 ( V_69 ) ) {
V_4 = - V_56 ;
break;
}
V_4 = F_34 ( & V_67 , V_65 , sizeof( T_5 ) ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
if ( V_2 -> V_15 == V_17 ) {
V_4 = - V_59 ;
break;
}
V_68 = ( long long ) V_6 -> V_70 *
V_7 -> V_71 - V_6 -> V_72 ;
if ( V_67 < 0 || V_67 > V_68 ) {
V_4 = - V_60 ;
break;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_43 ( V_7 , V_6 , V_67 ) ;
if ( V_67 == 0 ) {
F_40 ( V_7 , V_6 , V_62 ) ;
F_6 ( V_2 , V_18 ) ;
}
break;
}
case V_73 :
{
struct V_74 V_75 ;
V_4 = F_34 ( & V_75 , V_65 ,
sizeof( struct V_74 ) ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
if ( V_2 -> V_15 == V_17 ||
V_6 -> V_57 == V_58 ) {
V_4 = - V_59 ;
break;
}
V_4 = - V_60 ;
if ( V_75 . V_42 < 0 || V_75 . V_42 >= V_6 -> V_70 ||
V_75 . V_67 < 0 || V_75 . V_67 > V_6 -> V_51 )
break;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_44 ( V_7 , V_6 , & V_75 ) ;
if ( V_75 . V_67 == 0 )
F_6 ( V_2 , V_18 ) ;
break;
}
case V_76 :
{
T_6 V_42 ;
V_4 = F_45 ( V_42 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
if ( V_2 -> V_15 == V_17 ||
V_6 -> V_57 == V_58 ) {
V_4 = - V_59 ;
break;
}
if ( V_42 < 0 || V_42 >= V_6 -> V_70 ) {
V_4 = - V_60 ;
break;
}
F_11 ( L_15 , V_6 -> V_13 , V_42 ) ;
V_4 = F_46 ( V_7 , V_6 , V_42 ) ;
if ( V_4 )
break;
V_4 = F_47 ( V_7 , V_77 , V_77 ) ;
break;
}
case V_78 :
{
struct V_79 V_75 ;
V_4 = F_34 ( & V_75 , V_65 , sizeof( struct V_79 ) ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
V_4 = F_48 ( V_2 , V_75 . V_42 ) ;
break;
}
case V_80 :
{
T_6 V_42 ;
V_4 = F_45 ( V_42 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
V_4 = F_49 ( V_2 , V_42 ) ;
break;
}
case V_81 :
{
T_6 V_42 ;
V_4 = F_45 ( V_42 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
V_4 = F_50 ( V_2 , V_42 ) ;
break;
}
case V_82 :
{
struct V_83 V_75 ;
V_4 = F_34 ( & V_75 , V_65 ,
sizeof( struct V_83 ) ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
switch ( V_75 . V_84 ) {
case V_85 :
F_23 ( & V_7 -> V_86 ) ;
V_2 -> V_6 -> V_55 = ! ! V_75 . V_87 ;
F_25 ( & V_7 -> V_86 ) ;
break;
default:
V_4 = - V_60 ;
break;
}
break;
}
case V_88 :
{
struct V_89 V_90 ;
F_51 ( V_2 , & V_90 ) ;
V_4 = F_52 ( & V_90 ) ;
break;
}
case V_91 :
{
struct V_89 V_90 ;
F_51 ( V_2 , & V_90 ) ;
V_4 = F_53 ( & V_90 ) ;
break;
}
default:
V_4 = - V_92 ;
break;
}
return V_4 ;
}
static int F_54 ( const struct V_37 * V_7 ,
const struct V_93 * V_75 )
{
int V_94 , V_4 = - V_60 ;
if ( V_75 -> V_67 < 0 || V_75 -> V_95 < 0 || V_75 -> V_57 < 0 ||
V_75 -> V_96 < 0 )
goto V_97;
if ( ( V_75 -> V_13 < 0 || V_75 -> V_13 >= V_7 -> V_98 ) &&
V_75 -> V_13 != V_99 )
goto V_97;
if ( V_75 -> V_95 == 0 )
goto V_97;
if ( V_75 -> V_67 == 0 )
goto V_97;
if ( V_75 -> V_57 != V_100 &&
V_75 -> V_57 != V_58 )
goto V_97;
if ( V_75 -> V_95 > V_7 -> V_71 )
goto V_97;
V_94 = V_75 -> V_95 & ( V_7 -> V_52 - 1 ) ;
if ( V_75 -> V_95 != 1 && V_94 )
goto V_97;
if ( ! V_75 -> V_101 [ 0 ] || ! V_75 -> V_96 )
goto V_97;
if ( V_75 -> V_96 > V_102 ) {
V_4 = - V_103 ;
goto V_97;
}
V_94 = F_55 ( V_75 -> V_101 , V_75 -> V_96 + 1 ) ;
if ( V_94 != V_75 -> V_96 )
goto V_97;
return 0 ;
V_97:
F_4 ( V_7 , L_16 ) ;
F_56 ( V_75 ) ;
return V_4 ;
}
static int F_57 ( const struct V_37 * V_7 ,
const struct V_104 * V_75 )
{
if ( V_75 -> V_67 <= 0 )
return - V_60 ;
if ( V_75 -> V_13 < 0 || V_75 -> V_13 >= V_7 -> V_98 )
return - V_60 ;
return 0 ;
}
static int F_58 ( struct V_37 * V_7 ,
struct V_105 * V_75 )
{
int V_106 , V_94 , V_4 ;
struct V_107 V_108 ;
struct V_109 * V_110 , * V_111 ;
if ( V_75 -> V_40 < 0 || V_75 -> V_40 > V_112 )
return - V_60 ;
if ( V_75 -> V_40 == 0 )
return 0 ;
for ( V_106 = 0 ; V_106 < V_75 -> V_40 ; V_106 ++ ) {
if ( V_75 -> V_113 [ V_106 ] . V_13 < 0 ||
V_75 -> V_113 [ V_106 ] . V_13 >= V_7 -> V_98 )
return - V_60 ;
if ( V_75 -> V_113 [ V_106 ] . V_96 < 0 )
return - V_60 ;
if ( V_75 -> V_113 [ V_106 ] . V_96 > V_102 )
return - V_103 ;
V_75 -> V_113 [ V_106 ] . V_101 [ V_75 -> V_113 [ V_106 ] . V_96 ] = '\0' ;
V_94 = strlen ( V_75 -> V_113 [ V_106 ] . V_101 ) ;
if ( V_94 != V_75 -> V_113 [ V_106 ] . V_96 )
return - V_60 ;
}
for ( V_106 = 0 ; V_106 < V_75 -> V_40 - 1 ; V_106 ++ ) {
for ( V_94 = V_106 + 1 ; V_94 < V_75 -> V_40 ; V_94 ++ ) {
if ( V_75 -> V_113 [ V_106 ] . V_13 == V_75 -> V_113 [ V_94 ] . V_13 ) {
F_4 ( V_7 , L_17 ,
V_75 -> V_113 [ V_106 ] . V_13 ) ;
return - V_60 ;
}
if ( ! strcmp ( V_75 -> V_113 [ V_106 ] . V_101 , V_75 -> V_113 [ V_94 ] . V_101 ) ) {
F_4 ( V_7 , L_18 ,
V_75 -> V_113 [ V_106 ] . V_101 ) ;
return - V_60 ;
}
}
}
F_59 ( & V_108 ) ;
for ( V_106 = 0 ; V_106 < V_75 -> V_40 ; V_106 ++ ) {
int V_13 = V_75 -> V_113 [ V_106 ] . V_13 ;
int V_96 = V_75 -> V_113 [ V_106 ] . V_96 ;
const char * V_101 = V_75 -> V_113 [ V_106 ] . V_101 ;
V_110 = F_60 ( sizeof( struct V_109 ) , V_114 ) ;
if ( ! V_110 ) {
V_4 = - V_53 ;
goto V_115;
}
V_110 -> V_2 = F_12 ( V_7 -> V_22 , V_13 , V_19 ) ;
if ( F_13 ( V_110 -> V_2 ) ) {
V_4 = F_14 ( V_110 -> V_2 ) ;
F_4 ( V_7 , L_19 ,
V_13 , V_4 ) ;
F_61 ( V_110 ) ;
goto V_115;
}
if ( V_110 -> V_2 -> V_6 -> V_96 == V_96 &&
! memcmp ( V_110 -> V_2 -> V_6 -> V_101 , V_101 , V_96 ) ) {
F_18 ( V_110 -> V_2 ) ;
F_61 ( V_110 ) ;
continue;
}
V_110 -> V_116 = V_96 ;
memcpy ( V_110 -> V_117 , V_101 , V_96 ) ;
F_62 ( & V_110 -> V_118 , & V_108 ) ;
F_11 ( L_20 ,
V_13 , V_110 -> V_2 -> V_6 -> V_101 , V_101 ) ;
}
if ( F_63 ( & V_108 ) )
return 0 ;
F_64 (re, &rename_list, list) {
struct V_1 * V_2 ;
int V_119 = 0 ;
F_64 (re1, &rename_list, list) {
if ( V_110 -> V_116 == V_111 -> V_2 -> V_6 -> V_96 &&
! memcmp ( V_110 -> V_117 , V_111 -> V_2 -> V_6 -> V_101 ,
V_111 -> V_2 -> V_6 -> V_96 ) ) {
V_119 = 1 ;
break;
}
}
if ( V_119 )
continue;
V_2 = F_65 ( V_7 -> V_22 , V_110 -> V_117 ,
V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 == - V_120 )
continue;
F_4 ( V_7 , L_21 ,
V_110 -> V_117 , V_4 ) ;
goto V_115;
}
V_111 = F_60 ( sizeof( struct V_109 ) , V_114 ) ;
if ( ! V_111 ) {
V_4 = - V_53 ;
F_18 ( V_2 ) ;
goto V_115;
}
V_111 -> remove = 1 ;
V_111 -> V_2 = V_2 ;
F_66 ( & V_111 -> V_118 , & V_108 ) ;
F_11 ( L_22 ,
V_111 -> V_2 -> V_6 -> V_13 , V_111 -> V_2 -> V_6 -> V_101 ) ;
}
F_23 ( & V_7 -> V_86 ) ;
V_4 = F_67 ( V_7 , & V_108 ) ;
F_25 ( & V_7 -> V_86 ) ;
V_115:
F_68 (re, re1, &rename_list, list) {
F_18 ( V_110 -> V_2 ) ;
F_69 ( & V_110 -> V_118 ) ;
F_61 ( V_110 ) ;
}
return V_4 ;
}
static long F_70 ( struct V_21 * V_21 , unsigned int V_63 ,
unsigned long V_64 )
{
int V_4 = 0 ;
struct V_37 * V_7 ;
struct V_1 * V_2 ;
void T_3 * V_65 = ( void T_3 * ) V_64 ;
if ( ! F_42 ( V_69 ) )
return - V_56 ;
V_7 = F_71 ( F_10 ( V_21 -> V_121 -> V_122 ) ) ;
if ( ! V_7 )
return - V_120 ;
switch ( V_63 ) {
case V_123 :
{
struct V_93 V_75 ;
F_11 ( L_23 ) ;
V_4 = F_34 ( & V_75 , V_65 , sizeof( struct V_93 ) ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
V_4 = F_54 ( V_7 , & V_75 ) ;
if ( V_4 )
break;
F_23 ( & V_7 -> V_86 ) ;
V_4 = F_72 ( V_7 , & V_75 ) ;
F_25 ( & V_7 -> V_86 ) ;
if ( V_4 )
break;
V_4 = F_73 ( V_75 . V_13 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 )
V_4 = - V_54 ;
break;
}
case V_124 :
{
int V_13 ;
F_11 ( L_24 ) ;
V_4 = F_45 ( V_13 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
V_2 = F_12 ( V_7 -> V_22 , V_13 , V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
F_23 ( & V_7 -> V_86 ) ;
V_4 = F_74 ( V_2 , 0 ) ;
F_25 ( & V_7 -> V_86 ) ;
F_18 ( V_2 ) ;
break;
}
case V_125 :
{
int V_126 ;
struct V_104 V_75 ;
F_11 ( L_25 ) ;
V_4 = F_34 ( & V_75 , V_65 , sizeof( struct V_104 ) ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
V_4 = F_57 ( V_7 , & V_75 ) ;
if ( V_4 )
break;
V_2 = F_12 ( V_7 -> V_22 , V_75 . V_13 , V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
V_126 = F_75 ( V_75 . V_67 + V_2 -> V_6 -> V_51 - 1 ,
V_2 -> V_6 -> V_51 ) ;
F_23 ( & V_7 -> V_86 ) ;
V_4 = F_76 ( V_2 , V_126 ) ;
F_25 ( & V_7 -> V_86 ) ;
F_18 ( V_2 ) ;
break;
}
case V_127 :
{
struct V_105 * V_75 ;
F_11 ( L_26 ) ;
V_75 = F_77 ( sizeof( struct V_105 ) , V_114 ) ;
if ( ! V_75 ) {
V_4 = - V_53 ;
break;
} ;
V_4 = F_34 ( V_75 , V_65 , sizeof( struct V_105 ) ) ;
if ( V_4 ) {
V_4 = - V_54 ;
F_61 ( V_75 ) ;
break;
}
V_4 = F_58 ( V_7 , V_75 ) ;
F_61 ( V_75 ) ;
break;
}
default:
V_4 = - V_92 ;
break;
}
F_78 ( V_7 ) ;
return V_4 ;
}
static long F_79 ( struct V_21 * V_21 , unsigned int V_63 ,
unsigned long V_64 )
{
int V_4 = 0 ;
void T_3 * V_65 = ( void T_3 * ) V_64 ;
if ( ! F_42 ( V_69 ) )
return - V_56 ;
switch ( V_63 ) {
case V_128 :
{
struct V_129 V_75 ;
struct V_130 * V_131 ;
F_11 ( L_27 ) ;
V_4 = F_34 ( & V_75 , V_65 , sizeof( struct V_129 ) ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
if ( V_75 . V_132 < 0 ||
( V_75 . V_22 < 0 && V_75 . V_22 != V_133 ) ) {
V_4 = - V_60 ;
break;
}
V_131 = F_80 ( NULL , V_75 . V_132 ) ;
if ( F_13 ( V_131 ) ) {
V_4 = F_14 ( V_131 ) ;
break;
}
F_23 ( & V_134 ) ;
V_4 = F_81 ( V_131 , V_75 . V_22 , V_75 . V_135 ,
V_75 . V_136 ) ;
F_25 ( & V_134 ) ;
if ( V_4 < 0 )
F_82 ( V_131 ) ;
else
V_4 = F_73 ( V_4 , ( T_3 T_6 * ) V_65 ) ;
break;
}
case V_137 :
{
int V_22 ;
F_11 ( L_28 ) ;
V_4 = F_45 ( V_22 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_54 ;
break;
}
F_23 ( & V_134 ) ;
V_4 = F_83 ( V_22 , 0 ) ;
F_25 ( & V_134 ) ;
break;
}
default:
V_4 = - V_92 ;
break;
}
return V_4 ;
}
static long F_84 ( struct V_21 * V_21 , unsigned int V_63 ,
unsigned long V_64 )
{
unsigned long V_138 = ( unsigned long ) F_85 ( V_64 ) ;
return F_41 ( V_21 , V_63 , V_138 ) ;
}
static long F_86 ( struct V_21 * V_21 , unsigned int V_63 ,
unsigned long V_64 )
{
unsigned long V_138 = ( unsigned long ) F_85 ( V_64 ) ;
return F_70 ( V_21 , V_63 , V_138 ) ;
}
static long F_87 ( struct V_21 * V_21 , unsigned int V_63 ,
unsigned long V_64 )
{
unsigned long V_138 = ( unsigned long ) F_85 ( V_64 ) ;
return F_79 ( V_21 , V_63 , V_138 ) ;
}

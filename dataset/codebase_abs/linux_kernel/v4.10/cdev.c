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
V_6 -> V_50 ;
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
case V_70 :
{
struct V_71 V_72 ;
V_4 = F_34 ( & V_72 , V_64 ,
sizeof( struct V_71 ) ) ;
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
if ( ! F_44 ( V_6 , V_72 . V_41 ) ||
V_72 . V_66 < 0 || V_72 . V_66 > V_6 -> V_50 )
break;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_45 ( V_7 , V_6 , & V_72 ) ;
if ( V_72 . V_66 == 0 )
F_6 ( V_2 , V_18 ) ;
break;
}
case V_73 :
{
T_6 V_41 ;
V_4 = F_46 ( V_41 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
if ( V_2 -> V_15 == V_17 ||
V_6 -> V_56 == V_57 ) {
V_4 = - V_58 ;
break;
}
if ( ! F_44 ( V_6 , V_41 ) ) {
V_4 = - V_59 ;
break;
}
F_11 ( L_15 , V_6 -> V_13 , V_41 ) ;
V_4 = F_47 ( V_7 , V_6 , V_41 ) ;
if ( V_4 )
break;
V_4 = F_48 ( V_7 , V_74 , V_74 ) ;
break;
}
case V_75 :
{
struct V_76 V_72 ;
V_4 = F_34 ( & V_72 , V_64 , sizeof( struct V_76 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_49 ( V_2 , V_72 . V_41 ) ;
break;
}
case V_77 :
{
T_6 V_41 ;
V_4 = F_46 ( V_41 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_50 ( V_2 , V_41 ) ;
break;
}
case V_78 :
{
T_6 V_41 ;
V_4 = F_46 ( V_41 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_51 ( V_2 , V_41 ) ;
break;
}
case V_79 :
{
struct V_80 V_72 ;
V_4 = F_34 ( & V_72 , V_64 ,
sizeof( struct V_80 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
switch ( V_72 . V_81 ) {
case V_82 :
F_52 ( & V_7 -> V_83 ) ;
V_2 -> V_6 -> V_54 = ! ! V_72 . V_84 ;
F_53 ( & V_7 -> V_83 ) ;
break;
default:
V_4 = - V_59 ;
break;
}
break;
}
case V_85 :
{
struct V_86 V_87 ;
F_54 ( V_2 , & V_87 ) ;
V_4 = F_55 ( & V_87 ) ;
break;
}
case V_88 :
{
struct V_86 V_87 ;
F_54 ( V_2 , & V_87 ) ;
V_4 = F_56 ( & V_87 ) ;
break;
}
default:
V_4 = - V_89 ;
break;
}
return V_4 ;
}
static int F_57 ( const struct V_37 * V_7 ,
const struct V_90 * V_72 )
{
int V_91 , V_4 = - V_59 ;
if ( V_72 -> V_66 < 0 || V_72 -> V_92 < 0 || V_72 -> V_56 < 0 ||
V_72 -> V_93 < 0 )
goto V_94;
if ( ( V_72 -> V_13 < 0 || V_72 -> V_13 >= V_7 -> V_95 ) &&
V_72 -> V_13 != V_96 )
goto V_94;
if ( V_72 -> V_92 == 0 )
goto V_94;
if ( V_72 -> V_66 == 0 )
goto V_94;
if ( V_72 -> V_56 != V_97 &&
V_72 -> V_56 != V_57 )
goto V_94;
if ( V_72 -> V_92 > V_7 -> V_98 )
goto V_94;
V_91 = V_72 -> V_92 & ( V_7 -> V_51 - 1 ) ;
if ( V_72 -> V_92 != 1 && V_91 )
goto V_94;
if ( ! V_72 -> V_99 [ 0 ] || ! V_72 -> V_93 )
goto V_94;
if ( V_72 -> V_93 > V_100 ) {
V_4 = - V_101 ;
goto V_94;
}
V_91 = F_58 ( V_72 -> V_99 , V_72 -> V_93 + 1 ) ;
if ( V_91 != V_72 -> V_93 )
goto V_94;
return 0 ;
V_94:
F_4 ( V_7 , L_16 ) ;
F_59 ( V_72 ) ;
return V_4 ;
}
static int F_60 ( const struct V_37 * V_7 ,
const struct V_102 * V_72 )
{
if ( V_72 -> V_66 <= 0 )
return - V_59 ;
if ( V_72 -> V_13 < 0 || V_72 -> V_13 >= V_7 -> V_95 )
return - V_59 ;
return 0 ;
}
static int F_61 ( struct V_37 * V_7 ,
struct V_103 * V_72 )
{
int V_104 , V_91 , V_4 ;
struct V_105 V_106 ;
struct V_107 * V_108 , * V_109 ;
if ( V_72 -> V_39 < 0 || V_72 -> V_39 > V_110 )
return - V_59 ;
if ( V_72 -> V_39 == 0 )
return 0 ;
for ( V_104 = 0 ; V_104 < V_72 -> V_39 ; V_104 ++ ) {
if ( V_72 -> V_111 [ V_104 ] . V_13 < 0 ||
V_72 -> V_111 [ V_104 ] . V_13 >= V_7 -> V_95 )
return - V_59 ;
if ( V_72 -> V_111 [ V_104 ] . V_93 < 0 )
return - V_59 ;
if ( V_72 -> V_111 [ V_104 ] . V_93 > V_100 )
return - V_101 ;
V_72 -> V_111 [ V_104 ] . V_99 [ V_72 -> V_111 [ V_104 ] . V_93 ] = '\0' ;
V_91 = strlen ( V_72 -> V_111 [ V_104 ] . V_99 ) ;
if ( V_91 != V_72 -> V_111 [ V_104 ] . V_93 )
return - V_59 ;
}
for ( V_104 = 0 ; V_104 < V_72 -> V_39 - 1 ; V_104 ++ ) {
for ( V_91 = V_104 + 1 ; V_91 < V_72 -> V_39 ; V_91 ++ ) {
if ( V_72 -> V_111 [ V_104 ] . V_13 == V_72 -> V_111 [ V_91 ] . V_13 ) {
F_4 ( V_7 , L_17 ,
V_72 -> V_111 [ V_104 ] . V_13 ) ;
return - V_59 ;
}
if ( ! strcmp ( V_72 -> V_111 [ V_104 ] . V_99 , V_72 -> V_111 [ V_91 ] . V_99 ) ) {
F_4 ( V_7 , L_18 ,
V_72 -> V_111 [ V_104 ] . V_99 ) ;
return - V_59 ;
}
}
}
F_62 ( & V_106 ) ;
for ( V_104 = 0 ; V_104 < V_72 -> V_39 ; V_104 ++ ) {
int V_13 = V_72 -> V_111 [ V_104 ] . V_13 ;
int V_93 = V_72 -> V_111 [ V_104 ] . V_93 ;
const char * V_99 = V_72 -> V_111 [ V_104 ] . V_99 ;
V_108 = F_63 ( sizeof( struct V_107 ) , V_112 ) ;
if ( ! V_108 ) {
V_4 = - V_52 ;
goto V_113;
}
V_108 -> V_2 = F_12 ( V_7 -> V_22 , V_13 , V_19 ) ;
if ( F_13 ( V_108 -> V_2 ) ) {
V_4 = F_14 ( V_108 -> V_2 ) ;
F_4 ( V_7 , L_19 ,
V_13 , V_4 ) ;
F_64 ( V_108 ) ;
goto V_113;
}
if ( V_108 -> V_2 -> V_6 -> V_93 == V_93 &&
! memcmp ( V_108 -> V_2 -> V_6 -> V_99 , V_99 , V_93 ) ) {
F_18 ( V_108 -> V_2 ) ;
F_64 ( V_108 ) ;
continue;
}
V_108 -> V_114 = V_93 ;
memcpy ( V_108 -> V_115 , V_99 , V_93 ) ;
F_65 ( & V_108 -> V_116 , & V_106 ) ;
F_11 ( L_20 ,
V_13 , V_108 -> V_2 -> V_6 -> V_99 , V_99 ) ;
}
if ( F_66 ( & V_106 ) )
return 0 ;
F_67 (re, &rename_list, list) {
struct V_1 * V_2 ;
int V_117 = 0 ;
F_67 (re1, &rename_list, list) {
if ( V_108 -> V_114 == V_109 -> V_2 -> V_6 -> V_93 &&
! memcmp ( V_108 -> V_115 , V_109 -> V_2 -> V_6 -> V_99 ,
V_109 -> V_2 -> V_6 -> V_93 ) ) {
V_117 = 1 ;
break;
}
}
if ( V_117 )
continue;
V_2 = F_68 ( V_7 -> V_22 , V_108 -> V_115 ,
V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 == - V_118 )
continue;
F_4 ( V_7 , L_21 ,
V_108 -> V_115 , V_4 ) ;
goto V_113;
}
V_109 = F_63 ( sizeof( struct V_107 ) , V_112 ) ;
if ( ! V_109 ) {
V_4 = - V_52 ;
F_18 ( V_2 ) ;
goto V_113;
}
V_109 -> remove = 1 ;
V_109 -> V_2 = V_2 ;
F_69 ( & V_109 -> V_116 , & V_106 ) ;
F_11 ( L_22 ,
V_109 -> V_2 -> V_6 -> V_13 , V_109 -> V_2 -> V_6 -> V_99 ) ;
}
F_52 ( & V_7 -> V_83 ) ;
V_4 = F_70 ( V_7 , & V_106 ) ;
F_53 ( & V_7 -> V_83 ) ;
V_113:
F_71 (re, re1, &rename_list, list) {
F_18 ( V_108 -> V_2 ) ;
F_72 ( & V_108 -> V_116 ) ;
F_64 ( V_108 ) ;
}
return V_4 ;
}
static long F_73 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
int V_4 = 0 ;
struct V_37 * V_7 ;
struct V_1 * V_2 ;
void T_3 * V_64 = ( void T_3 * ) V_63 ;
if ( ! F_42 ( V_68 ) )
return - V_55 ;
V_7 = F_74 ( F_10 ( V_21 -> V_119 -> V_120 ) ) ;
if ( ! V_7 )
return - V_118 ;
switch ( V_62 ) {
case V_121 :
{
struct V_90 V_72 ;
F_11 ( L_23 ) ;
V_4 = F_34 ( & V_72 , V_64 , sizeof( struct V_90 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_57 ( V_7 , & V_72 ) ;
if ( V_4 )
break;
F_52 ( & V_7 -> V_83 ) ;
V_4 = F_75 ( V_7 , & V_72 ) ;
F_53 ( & V_7 -> V_83 ) ;
if ( V_4 )
break;
V_4 = F_76 ( V_72 . V_13 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 )
V_4 = - V_53 ;
break;
}
case V_122 :
{
int V_13 ;
F_11 ( L_24 ) ;
V_4 = F_46 ( V_13 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_2 = F_12 ( V_7 -> V_22 , V_13 , V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
F_52 ( & V_7 -> V_83 ) ;
V_4 = F_77 ( V_2 , 0 ) ;
F_53 ( & V_7 -> V_83 ) ;
F_18 ( V_2 ) ;
break;
}
case V_123 :
{
int V_124 ;
struct V_102 V_72 ;
F_11 ( L_25 ) ;
V_4 = F_34 ( & V_72 , V_64 , sizeof( struct V_102 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
V_4 = F_60 ( V_7 , & V_72 ) ;
if ( V_4 )
break;
V_2 = F_12 ( V_7 -> V_22 , V_72 . V_13 , V_16 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
V_124 = F_78 ( V_72 . V_66 + V_2 -> V_6 -> V_50 - 1 ,
V_2 -> V_6 -> V_50 ) ;
F_52 ( & V_7 -> V_83 ) ;
V_4 = F_79 ( V_2 , V_124 ) ;
F_53 ( & V_7 -> V_83 ) ;
F_18 ( V_2 ) ;
break;
}
case V_125 :
{
struct V_103 * V_72 ;
F_11 ( L_26 ) ;
V_72 = F_80 ( sizeof( struct V_103 ) , V_112 ) ;
if ( ! V_72 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_34 ( V_72 , V_64 , sizeof( struct V_103 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
F_64 ( V_72 ) ;
break;
}
V_4 = F_61 ( V_7 , V_72 ) ;
F_64 ( V_72 ) ;
break;
}
default:
V_4 = - V_89 ;
break;
}
F_81 ( V_7 ) ;
return V_4 ;
}
static long F_82 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
int V_4 = 0 ;
void T_3 * V_64 = ( void T_3 * ) V_63 ;
if ( ! F_42 ( V_68 ) )
return - V_55 ;
switch ( V_62 ) {
case V_126 :
{
struct V_127 V_72 ;
struct V_128 * V_129 ;
F_11 ( L_27 ) ;
V_4 = F_34 ( & V_72 , V_64 , sizeof( struct V_127 ) ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
if ( V_72 . V_130 < 0 ||
( V_72 . V_22 < 0 && V_72 . V_22 != V_131 ) ) {
V_4 = - V_59 ;
break;
}
V_129 = F_83 ( NULL , V_72 . V_130 ) ;
if ( F_13 ( V_129 ) ) {
V_4 = F_14 ( V_129 ) ;
break;
}
F_52 ( & V_132 ) ;
V_4 = F_84 ( V_129 , V_72 . V_22 , V_72 . V_133 ,
V_72 . V_134 ) ;
F_53 ( & V_132 ) ;
if ( V_4 < 0 )
F_85 ( V_129 ) ;
else
V_4 = F_76 ( V_4 , ( T_3 T_6 * ) V_64 ) ;
break;
}
case V_135 :
{
int V_22 ;
F_11 ( L_28 ) ;
V_4 = F_46 ( V_22 , ( T_3 T_6 * ) V_64 ) ;
if ( V_4 ) {
V_4 = - V_53 ;
break;
}
F_52 ( & V_132 ) ;
V_4 = F_86 ( V_22 , 0 ) ;
F_53 ( & V_132 ) ;
break;
}
default:
V_4 = - V_89 ;
break;
}
return V_4 ;
}
static long F_87 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
unsigned long V_136 = ( unsigned long ) F_88 ( V_63 ) ;
return F_41 ( V_21 , V_62 , V_136 ) ;
}
static long F_89 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
unsigned long V_136 = ( unsigned long ) F_88 ( V_63 ) ;
return F_73 ( V_21 , V_62 , V_136 ) ;
}
static long F_90 ( struct V_21 * V_21 , unsigned int V_62 ,
unsigned long V_63 )
{
unsigned long V_136 = ( unsigned long ) F_88 ( V_63 ) ;
return F_82 ( V_21 , V_62 , V_136 ) ;
}

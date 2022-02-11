static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 ;
struct V_7 * V_8 = V_4 -> V_8 ;
F_2 ( & V_8 -> V_2 -> V_9 ) ;
V_5 = V_8 -> V_10 + V_8 -> V_11 + V_8 -> V_12 ;
F_3 ( V_5 > 0 ) ;
if ( V_5 > 1 ) {
F_4 ( V_2 , L_1 , V_5 , V_8 -> V_13 ) ;
V_6 = - V_14 ;
} else {
V_8 -> V_10 = V_8 -> V_11 = 0 ;
V_8 -> V_12 = 1 ;
V_6 = V_4 -> V_15 ;
V_4 -> V_15 = V_16 ;
}
F_5 ( & V_8 -> V_2 -> V_9 ) ;
return V_6 ;
}
static void F_6 ( struct V_3 * V_4 , int V_15 )
{
struct V_7 * V_8 = V_4 -> V_8 ;
F_2 ( & V_8 -> V_2 -> V_9 ) ;
F_3 ( V_8 -> V_10 == 0 && V_8 -> V_11 == 0 ) ;
F_3 ( V_8 -> V_12 == 1 && V_4 -> V_15 == V_16 ) ;
V_8 -> V_12 = 0 ;
if ( V_15 == V_17 )
V_8 -> V_10 = 1 ;
else if ( V_15 == V_18 )
V_8 -> V_11 = 1 ;
else
V_8 -> V_12 = 1 ;
F_5 ( & V_8 -> V_2 -> V_9 ) ;
V_4 -> V_15 = V_15 ;
}
static int F_7 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_3 * V_4 ;
int V_13 = F_8 ( V_19 ) - 1 , V_15 , V_21 ;
V_21 = F_9 ( F_10 ( V_19 ) ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_20 -> V_22 & V_23 )
V_15 = V_18 ;
else
V_15 = V_17 ;
F_11 ( L_2 ,
V_21 , V_13 , V_15 ) ;
V_4 = F_12 ( V_21 , V_13 , V_15 ) ;
if ( F_13 ( V_4 ) )
return F_14 ( V_4 ) ;
V_20 -> V_24 = V_4 ;
return 0 ;
}
static int F_15 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_3 * V_4 = V_20 -> V_24 ;
struct V_7 * V_8 = V_4 -> V_8 ;
F_11 ( L_3 ,
V_8 -> V_2 -> V_21 , V_8 -> V_13 , V_4 -> V_15 ) ;
if ( V_8 -> V_25 ) {
F_16 ( V_8 -> V_2 , L_4 ,
V_8 -> V_13 ) ;
F_3 ( ! V_8 -> V_26 ) ;
V_8 -> V_25 = 0 ;
F_17 ( V_8 -> V_27 ) ;
} else if ( V_8 -> V_26 ) {
F_11 ( L_5 ,
V_8 -> V_28 , V_8 -> V_29 , V_8 -> V_2 -> V_21 ,
V_8 -> V_13 ) ;
V_8 -> V_26 = 0 ;
F_17 ( V_8 -> V_27 ) ;
}
F_18 ( V_4 ) ;
return 0 ;
}
static T_1 F_19 ( struct V_20 * V_20 , T_1 V_30 , int V_31 )
{
struct V_3 * V_4 = V_20 -> V_24 ;
struct V_7 * V_8 = V_4 -> V_8 ;
if ( V_8 -> V_25 ) {
F_4 ( V_8 -> V_2 , L_6 ) ;
return - V_14 ;
}
return F_20 ( V_20 , V_30 , V_31 , V_8 -> V_32 ) ;
}
static int F_21 ( struct V_20 * V_20 , T_1 V_33 , T_1 V_34 ,
int V_35 )
{
struct V_3 * V_4 = V_20 -> V_24 ;
struct V_1 * V_2 = V_4 -> V_8 -> V_2 ;
struct V_19 * V_19 = F_22 ( V_20 ) ;
int V_6 ;
F_23 ( & V_19 -> V_36 ) ;
V_6 = F_24 ( V_2 -> V_21 ) ;
F_25 ( & V_19 -> V_36 ) ;
return V_6 ;
}
static T_2 F_26 ( struct V_20 * V_20 , T_3 char * V_37 , T_4 V_38 ,
T_1 * V_39 )
{
struct V_3 * V_4 = V_20 -> V_24 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_6 , V_40 , V_41 , V_42 , V_43 ;
T_4 V_44 = V_38 ;
void * V_45 ;
F_11 ( L_7 ,
V_38 , * V_39 , V_8 -> V_13 ) ;
if ( V_8 -> V_25 ) {
F_4 ( V_8 -> V_2 , L_6 ) ;
return - V_14 ;
}
if ( V_8 -> V_46 ) {
F_4 ( V_8 -> V_2 , L_8 ) ;
return - V_47 ;
}
if ( * V_39 == V_8 -> V_32 || V_38 == 0 )
return 0 ;
if ( V_8 -> V_48 )
F_11 ( L_9 , V_8 -> V_13 ) ;
if ( * V_39 + V_38 > V_8 -> V_32 )
V_44 = V_38 = V_8 -> V_32 - * V_39 ;
V_43 = V_8 -> V_49 ;
if ( V_38 < V_43 )
V_43 = F_27 ( V_38 , V_2 -> V_50 ) ;
V_45 = F_28 ( V_43 ) ;
if ( ! V_45 )
return - V_51 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
V_40 = F_29 ( * V_39 , V_8 -> V_49 , & V_41 ) ;
do {
F_30 () ;
if ( V_41 + V_42 >= V_8 -> V_49 )
V_42 = V_8 -> V_49 - V_41 ;
V_6 = F_31 ( V_2 , V_8 , V_40 , V_45 , V_41 , V_42 , 0 ) ;
if ( V_6 )
break;
V_41 += V_42 ;
if ( V_41 == V_8 -> V_49 ) {
V_40 += 1 ;
V_41 -= V_8 -> V_49 ;
}
V_38 -= V_42 ;
* V_39 += V_42 ;
V_6 = F_32 ( V_37 , V_45 , V_42 ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
V_37 += V_42 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
} while ( V_38 );
F_17 ( V_45 ) ;
return V_6 ? V_6 : V_44 - V_38 ;
}
static T_2 F_33 ( struct V_20 * V_20 , const char T_3 * V_37 ,
T_4 V_38 , T_1 * V_39 )
{
struct V_3 * V_4 = V_20 -> V_24 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_2 ;
int V_40 , V_41 , V_42 , V_43 , V_6 = 0 ;
T_4 V_44 = V_38 ;
char * V_45 ;
if ( ! V_8 -> V_53 )
return - V_54 ;
F_11 ( L_10 ,
V_38 , * V_39 , V_8 -> V_13 ) ;
if ( V_8 -> V_55 == V_56 )
return - V_57 ;
V_40 = F_29 ( * V_39 , V_8 -> V_49 , & V_41 ) ;
if ( V_41 & ( V_2 -> V_50 - 1 ) ) {
F_4 ( V_2 , L_11 ) ;
return - V_58 ;
}
if ( * V_39 + V_38 > V_8 -> V_32 )
V_44 = V_38 = V_8 -> V_32 - * V_39 ;
if ( V_38 & ( V_2 -> V_50 - 1 ) ) {
F_4 ( V_2 , L_12 ) ;
return - V_58 ;
}
V_43 = V_8 -> V_49 ;
if ( V_38 < V_43 )
V_43 = F_27 ( V_38 , V_2 -> V_50 ) ;
V_45 = F_28 ( V_43 ) ;
if ( ! V_45 )
return - V_51 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
while ( V_38 ) {
F_30 () ;
if ( V_41 + V_42 >= V_8 -> V_49 )
V_42 = V_8 -> V_49 - V_41 ;
V_6 = F_34 ( V_45 , V_37 , V_42 ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
V_6 = F_35 ( V_2 , V_8 , V_40 , V_45 , V_41 , V_42 ) ;
if ( V_6 )
break;
V_41 += V_42 ;
if ( V_41 == V_8 -> V_49 ) {
V_40 += 1 ;
V_41 -= V_8 -> V_49 ;
}
V_38 -= V_42 ;
* V_39 += V_42 ;
V_37 += V_42 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
}
F_17 ( V_45 ) ;
return V_6 ? V_6 : V_44 - V_38 ;
}
static T_2 F_36 ( struct V_20 * V_20 , const char T_3 * V_37 ,
T_4 V_38 , T_1 * V_39 )
{
int V_6 = 0 ;
struct V_3 * V_4 = V_20 -> V_24 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_2 ;
if ( ! V_8 -> V_25 && ! V_8 -> V_26 )
return F_33 ( V_20 , V_37 , V_38 , V_39 ) ;
if ( V_8 -> V_25 )
V_6 = F_37 ( V_2 , V_8 , V_37 , V_38 ) ;
else
V_6 = F_38 ( V_2 , V_8 , V_37 , V_38 ) ;
if ( V_6 < 0 ) {
F_4 ( V_2 , L_13 ,
V_38 , V_6 ) ;
return V_6 ;
}
if ( V_6 ) {
V_38 = V_6 ;
if ( V_8 -> V_26 ) {
F_6 ( V_4 , V_18 ) ;
return V_38 ;
}
V_6 = F_39 ( V_2 , V_8 -> V_13 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_6 ) {
F_16 ( V_2 , L_14 ,
V_8 -> V_13 , V_2 -> V_21 ) ;
V_8 -> V_48 = 1 ;
}
V_8 -> V_59 = 1 ;
F_40 ( V_2 , V_8 , V_60 ) ;
F_6 ( V_4 , V_18 ) ;
}
return V_38 ;
}
static long F_41 ( struct V_20 * V_20 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_6 = 0 ;
struct V_3 * V_4 = V_20 -> V_24 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_1 * V_2 = V_8 -> V_2 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
switch ( V_61 ) {
case V_64 :
{
T_5 V_65 , V_66 ;
if ( ! F_42 ( V_67 ) ) {
V_6 = - V_54 ;
break;
}
V_6 = F_34 ( & V_65 , V_63 , sizeof( T_5 ) ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
if ( V_4 -> V_15 == V_17 ) {
V_6 = - V_57 ;
break;
}
V_66 = ( long long ) V_8 -> V_68 *
V_2 -> V_69 - V_8 -> V_70 ;
if ( V_65 < 0 || V_65 > V_66 ) {
V_6 = - V_58 ;
break;
}
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 < 0 )
break;
V_6 = F_43 ( V_2 , V_8 , V_65 ) ;
if ( V_65 == 0 ) {
F_40 ( V_2 , V_8 , V_60 ) ;
F_6 ( V_4 , V_18 ) ;
}
break;
}
case V_71 :
{
struct V_72 V_73 ;
V_6 = F_34 ( & V_73 , V_63 ,
sizeof( struct V_72 ) ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
if ( V_4 -> V_15 == V_17 ||
V_8 -> V_55 == V_56 ) {
V_6 = - V_57 ;
break;
}
V_6 = - V_58 ;
if ( V_73 . V_40 < 0 || V_73 . V_40 >= V_8 -> V_68 ||
V_73 . V_65 < 0 || V_73 . V_40 >= V_8 -> V_49 )
break;
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 < 0 )
break;
V_6 = F_44 ( V_2 , V_8 , & V_73 ) ;
if ( V_73 . V_65 == 0 )
F_6 ( V_4 , V_18 ) ;
break;
}
case V_74 :
{
T_6 V_40 ;
V_6 = F_45 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
if ( V_4 -> V_15 == V_17 ||
V_8 -> V_55 == V_56 ) {
V_6 = - V_57 ;
break;
}
if ( V_40 < 0 || V_40 >= V_8 -> V_68 ) {
V_6 = - V_58 ;
break;
}
F_11 ( L_15 , V_8 -> V_13 , V_40 ) ;
V_6 = F_46 ( V_2 , V_8 , V_40 ) ;
if ( V_6 )
break;
V_6 = F_47 ( V_2 , V_75 , V_75 ) ;
break;
}
case V_76 :
{
struct V_77 V_73 ;
V_6 = F_34 ( & V_73 , V_63 , sizeof( struct V_77 ) ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
V_6 = F_48 ( V_4 , V_73 . V_40 ) ;
break;
}
case V_78 :
{
T_6 V_40 ;
V_6 = F_45 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
V_6 = F_49 ( V_4 , V_40 ) ;
break;
}
case V_79 :
{
T_6 V_40 ;
V_6 = F_45 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
V_6 = F_50 ( V_4 , V_40 ) ;
break;
}
case V_80 :
{
struct V_81 V_73 ;
V_6 = F_34 ( & V_73 , V_63 ,
sizeof( struct V_81 ) ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
switch ( V_73 . V_82 ) {
case V_83 :
F_23 ( & V_2 -> V_84 ) ;
V_4 -> V_8 -> V_53 = ! ! V_73 . V_85 ;
F_25 ( & V_2 -> V_84 ) ;
break;
default:
V_6 = - V_58 ;
break;
}
break;
}
case V_86 :
{
struct V_87 V_88 ;
F_51 ( V_4 , & V_88 ) ;
V_6 = F_52 ( & V_88 ) ;
break;
}
case V_89 :
{
struct V_87 V_88 ;
F_51 ( V_4 , & V_88 ) ;
V_6 = F_53 ( & V_88 ) ;
break;
}
default:
V_6 = - V_90 ;
break;
}
return V_6 ;
}
static int F_54 ( const struct V_1 * V_2 ,
const struct V_91 * V_73 )
{
int V_92 , V_6 = - V_58 ;
if ( V_73 -> V_65 < 0 || V_73 -> V_93 < 0 || V_73 -> V_55 < 0 ||
V_73 -> V_94 < 0 )
goto V_95;
if ( ( V_73 -> V_13 < 0 || V_73 -> V_13 >= V_2 -> V_96 ) &&
V_73 -> V_13 != V_97 )
goto V_95;
if ( V_73 -> V_93 == 0 )
goto V_95;
if ( V_73 -> V_65 == 0 )
goto V_95;
if ( V_73 -> V_55 != V_98 &&
V_73 -> V_55 != V_56 )
goto V_95;
if ( V_73 -> V_93 > V_2 -> V_69 )
goto V_95;
V_92 = V_73 -> V_93 & ( V_2 -> V_50 - 1 ) ;
if ( V_73 -> V_93 != 1 && V_92 )
goto V_95;
if ( ! V_73 -> V_99 [ 0 ] || ! V_73 -> V_94 )
goto V_95;
if ( V_73 -> V_94 > V_100 ) {
V_6 = - V_101 ;
goto V_95;
}
V_92 = F_55 ( V_73 -> V_99 , V_73 -> V_94 + 1 ) ;
if ( V_92 != V_73 -> V_94 )
goto V_95;
return 0 ;
V_95:
F_4 ( V_2 , L_16 ) ;
F_56 ( V_73 ) ;
return V_6 ;
}
static int F_57 ( const struct V_1 * V_2 ,
const struct V_102 * V_73 )
{
if ( V_73 -> V_65 <= 0 )
return - V_58 ;
if ( V_73 -> V_13 < 0 || V_73 -> V_13 >= V_2 -> V_96 )
return - V_58 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_103 * V_73 )
{
int V_104 , V_92 , V_6 ;
struct V_105 V_106 ;
struct V_107 * V_108 , * V_109 ;
if ( V_73 -> V_38 < 0 || V_73 -> V_38 > V_110 )
return - V_58 ;
if ( V_73 -> V_38 == 0 )
return 0 ;
for ( V_104 = 0 ; V_104 < V_73 -> V_38 ; V_104 ++ ) {
if ( V_73 -> V_111 [ V_104 ] . V_13 < 0 ||
V_73 -> V_111 [ V_104 ] . V_13 >= V_2 -> V_96 )
return - V_58 ;
if ( V_73 -> V_111 [ V_104 ] . V_94 < 0 )
return - V_58 ;
if ( V_73 -> V_111 [ V_104 ] . V_94 > V_100 )
return - V_101 ;
V_73 -> V_111 [ V_104 ] . V_99 [ V_73 -> V_111 [ V_104 ] . V_94 ] = '\0' ;
V_92 = strlen ( V_73 -> V_111 [ V_104 ] . V_99 ) ;
if ( V_92 != V_73 -> V_111 [ V_104 ] . V_94 )
return - V_58 ;
}
for ( V_104 = 0 ; V_104 < V_73 -> V_38 - 1 ; V_104 ++ ) {
for ( V_92 = V_104 + 1 ; V_92 < V_73 -> V_38 ; V_92 ++ ) {
if ( V_73 -> V_111 [ V_104 ] . V_13 == V_73 -> V_111 [ V_92 ] . V_13 ) {
F_4 ( V_2 , L_17 ,
V_73 -> V_111 [ V_104 ] . V_13 ) ;
return - V_58 ;
}
if ( ! strcmp ( V_73 -> V_111 [ V_104 ] . V_99 , V_73 -> V_111 [ V_92 ] . V_99 ) ) {
F_4 ( V_2 , L_18 ,
V_73 -> V_111 [ V_104 ] . V_99 ) ;
return - V_58 ;
}
}
}
F_59 ( & V_106 ) ;
for ( V_104 = 0 ; V_104 < V_73 -> V_38 ; V_104 ++ ) {
int V_13 = V_73 -> V_111 [ V_104 ] . V_13 ;
int V_94 = V_73 -> V_111 [ V_104 ] . V_94 ;
const char * V_99 = V_73 -> V_111 [ V_104 ] . V_99 ;
V_108 = F_60 ( sizeof( struct V_107 ) , V_112 ) ;
if ( ! V_108 ) {
V_6 = - V_51 ;
goto V_113;
}
V_108 -> V_4 = F_12 ( V_2 -> V_21 , V_13 , V_18 ) ;
if ( F_13 ( V_108 -> V_4 ) ) {
V_6 = F_14 ( V_108 -> V_4 ) ;
F_4 ( V_2 , L_19 ,
V_13 , V_6 ) ;
F_61 ( V_108 ) ;
goto V_113;
}
if ( V_108 -> V_4 -> V_8 -> V_94 == V_94 &&
! memcmp ( V_108 -> V_4 -> V_8 -> V_99 , V_99 , V_94 ) ) {
F_18 ( V_108 -> V_4 ) ;
F_61 ( V_108 ) ;
continue;
}
V_108 -> V_114 = V_94 ;
memcpy ( V_108 -> V_115 , V_99 , V_94 ) ;
F_62 ( & V_108 -> V_116 , & V_106 ) ;
F_11 ( L_20 ,
V_13 , V_108 -> V_4 -> V_8 -> V_99 , V_99 ) ;
}
if ( F_63 ( & V_106 ) )
return 0 ;
F_64 (re, &rename_list, list) {
struct V_3 * V_4 ;
int V_117 = 0 ;
F_64 (re1, &rename_list, list) {
if ( V_108 -> V_114 == V_109 -> V_4 -> V_8 -> V_94 &&
! memcmp ( V_108 -> V_115 , V_109 -> V_4 -> V_8 -> V_99 ,
V_109 -> V_4 -> V_8 -> V_94 ) ) {
V_117 = 1 ;
break;
}
}
if ( V_117 )
continue;
V_4 = F_65 ( V_2 -> V_21 , V_108 -> V_115 ,
V_16 ) ;
if ( F_13 ( V_4 ) ) {
V_6 = F_14 ( V_4 ) ;
if ( V_6 == - V_118 )
continue;
F_4 ( V_2 , L_21 ,
V_108 -> V_115 , V_6 ) ;
goto V_113;
}
V_109 = F_60 ( sizeof( struct V_107 ) , V_112 ) ;
if ( ! V_109 ) {
V_6 = - V_51 ;
F_18 ( V_4 ) ;
goto V_113;
}
V_109 -> remove = 1 ;
V_109 -> V_4 = V_4 ;
F_66 ( & V_109 -> V_116 , & V_106 ) ;
F_11 ( L_22 ,
V_109 -> V_4 -> V_8 -> V_13 , V_109 -> V_4 -> V_8 -> V_99 ) ;
}
F_23 ( & V_2 -> V_84 ) ;
V_6 = F_67 ( V_2 , & V_106 ) ;
F_25 ( & V_2 -> V_84 ) ;
V_113:
F_68 (re, re1, &rename_list, list) {
F_18 ( V_108 -> V_4 ) ;
F_69 ( & V_108 -> V_116 ) ;
F_61 ( V_108 ) ;
}
return V_6 ;
}
static long F_70 ( struct V_20 * V_20 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_6 = 0 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
if ( ! F_42 ( V_67 ) )
return - V_54 ;
V_2 = F_71 ( F_10 ( V_20 -> V_119 -> V_120 ) ) ;
if ( ! V_2 )
return - V_118 ;
switch ( V_61 ) {
case V_121 :
{
struct V_91 V_73 ;
F_11 ( L_23 ) ;
V_6 = F_34 ( & V_73 , V_63 , sizeof( struct V_91 ) ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
V_6 = F_54 ( V_2 , & V_73 ) ;
if ( V_6 )
break;
F_23 ( & V_2 -> V_84 ) ;
V_6 = F_72 ( V_2 , & V_73 ) ;
F_25 ( & V_2 -> V_84 ) ;
if ( V_6 )
break;
V_6 = F_73 ( V_73 . V_13 , ( T_3 T_6 * ) V_63 ) ;
if ( V_6 )
V_6 = - V_52 ;
break;
}
case V_122 :
{
int V_13 ;
F_11 ( L_24 ) ;
V_6 = F_45 ( V_13 , ( T_3 T_6 * ) V_63 ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
V_4 = F_12 ( V_2 -> V_21 , V_13 , V_16 ) ;
if ( F_13 ( V_4 ) ) {
V_6 = F_14 ( V_4 ) ;
break;
}
F_23 ( & V_2 -> V_84 ) ;
V_6 = F_74 ( V_4 , 0 ) ;
F_25 ( & V_2 -> V_84 ) ;
F_18 ( V_4 ) ;
break;
}
case V_123 :
{
int V_124 ;
struct V_102 V_73 ;
F_11 ( L_25 ) ;
V_6 = F_34 ( & V_73 , V_63 , sizeof( struct V_102 ) ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
V_6 = F_57 ( V_2 , & V_73 ) ;
if ( V_6 )
break;
V_4 = F_12 ( V_2 -> V_21 , V_73 . V_13 , V_16 ) ;
if ( F_13 ( V_4 ) ) {
V_6 = F_14 ( V_4 ) ;
break;
}
V_124 = F_75 ( V_73 . V_65 + V_4 -> V_8 -> V_49 - 1 ,
V_4 -> V_8 -> V_49 ) ;
F_23 ( & V_2 -> V_84 ) ;
V_6 = F_76 ( V_4 , V_124 ) ;
F_25 ( & V_2 -> V_84 ) ;
F_18 ( V_4 ) ;
break;
}
case V_125 :
{
struct V_103 * V_73 ;
F_11 ( L_26 ) ;
V_73 = F_77 ( sizeof( struct V_103 ) , V_112 ) ;
if ( ! V_73 ) {
V_6 = - V_51 ;
break;
} ;
V_6 = F_34 ( V_73 , V_63 , sizeof( struct V_103 ) ) ;
if ( V_6 ) {
V_6 = - V_52 ;
F_61 ( V_73 ) ;
break;
}
V_6 = F_58 ( V_2 , V_73 ) ;
F_61 ( V_73 ) ;
break;
}
default:
V_6 = - V_90 ;
break;
}
F_78 ( V_2 ) ;
return V_6 ;
}
static long F_79 ( struct V_20 * V_20 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_6 = 0 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
if ( ! F_42 ( V_67 ) )
return - V_54 ;
switch ( V_61 ) {
case V_126 :
{
struct V_127 V_73 ;
struct V_128 * V_129 ;
F_11 ( L_27 ) ;
V_6 = F_34 ( & V_73 , V_63 , sizeof( struct V_127 ) ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
if ( V_73 . V_130 < 0 ||
( V_73 . V_21 < 0 && V_73 . V_21 != V_131 ) ) {
V_6 = - V_58 ;
break;
}
V_129 = F_80 ( NULL , V_73 . V_130 ) ;
if ( F_13 ( V_129 ) ) {
V_6 = F_14 ( V_129 ) ;
break;
}
F_23 ( & V_132 ) ;
V_6 = F_81 ( V_129 , V_73 . V_21 , V_73 . V_133 ,
V_73 . V_134 ) ;
F_25 ( & V_132 ) ;
if ( V_6 < 0 )
F_82 ( V_129 ) ;
else
V_6 = F_73 ( V_6 , ( T_3 T_6 * ) V_63 ) ;
break;
}
case V_135 :
{
int V_21 ;
F_11 ( L_28 ) ;
V_6 = F_45 ( V_21 , ( T_3 T_6 * ) V_63 ) ;
if ( V_6 ) {
V_6 = - V_52 ;
break;
}
F_23 ( & V_132 ) ;
V_6 = F_83 ( V_21 , 0 ) ;
F_25 ( & V_132 ) ;
break;
}
default:
V_6 = - V_90 ;
break;
}
return V_6 ;
}
static long F_84 ( struct V_20 * V_20 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_136 = ( unsigned long ) F_85 ( V_62 ) ;
return F_41 ( V_20 , V_61 , V_136 ) ;
}
static long F_86 ( struct V_20 * V_20 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_136 = ( unsigned long ) F_85 ( V_62 ) ;
return F_70 ( V_20 , V_61 , V_136 ) ;
}
static long F_87 ( struct V_20 * V_20 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_136 = ( unsigned long ) F_85 ( V_62 ) ;
return F_79 ( V_20 , V_61 , V_136 ) ;
}

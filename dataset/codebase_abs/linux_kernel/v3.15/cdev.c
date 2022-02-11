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
if ( V_6 -> V_24 ) {
F_4 ( L_6 ) ;
return - V_13 ;
}
return F_20 ( V_19 , V_29 , V_30 , V_6 -> V_31 ) ;
}
static int F_21 ( struct V_19 * V_19 , T_1 V_32 , T_1 V_33 ,
int V_34 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_35 * V_7 = V_2 -> V_6 -> V_7 ;
struct V_18 * V_18 = F_22 ( V_19 ) ;
int V_4 ;
F_23 ( & V_18 -> V_36 ) ;
V_4 = F_24 ( V_7 -> V_20 ) ;
F_25 ( & V_18 -> V_36 ) ;
return V_4 ;
}
static T_2 F_26 ( struct V_19 * V_19 , T_3 char * V_37 , T_4 V_38 ,
T_1 * V_39 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_35 * V_7 = V_6 -> V_7 ;
int V_4 , V_40 , V_41 , V_42 , V_43 ;
T_4 V_44 = V_38 ;
void * V_45 ;
F_11 ( L_7 ,
V_38 , * V_39 , V_6 -> V_12 ) ;
if ( V_6 -> V_24 ) {
F_4 ( L_6 ) ;
return - V_13 ;
}
if ( V_6 -> V_46 ) {
F_4 ( L_8 ) ;
return - V_47 ;
}
if ( * V_39 == V_6 -> V_31 || V_38 == 0 )
return 0 ;
if ( V_6 -> V_48 )
F_11 ( L_9 , V_6 -> V_12 ) ;
if ( * V_39 + V_38 > V_6 -> V_31 )
V_44 = V_38 = V_6 -> V_31 - * V_39 ;
V_43 = V_6 -> V_49 ;
if ( V_38 < V_43 )
V_43 = F_27 ( V_38 , V_7 -> V_50 ) ;
V_45 = F_28 ( V_43 ) ;
if ( ! V_45 )
return - V_51 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
V_40 = F_29 ( * V_39 , V_6 -> V_49 , & V_41 ) ;
do {
F_30 () ;
if ( V_41 + V_42 >= V_6 -> V_49 )
V_42 = V_6 -> V_49 - V_41 ;
V_4 = F_31 ( V_7 , V_6 , V_40 , V_45 , V_41 , V_42 , 0 ) ;
if ( V_4 )
break;
V_41 += V_42 ;
if ( V_41 == V_6 -> V_49 ) {
V_40 += 1 ;
V_41 -= V_6 -> V_49 ;
}
V_38 -= V_42 ;
* V_39 += V_42 ;
V_4 = F_32 ( V_37 , V_45 , V_42 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_37 += V_42 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
} while ( V_38 );
F_17 ( V_45 ) ;
return V_4 ? V_4 : V_44 - V_38 ;
}
static T_2 F_33 ( struct V_19 * V_19 , const char T_3 * V_37 ,
T_4 V_38 , T_1 * V_39 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_35 * V_7 = V_6 -> V_7 ;
int V_40 , V_41 , V_42 , V_43 , V_4 = 0 ;
T_4 V_44 = V_38 ;
char * V_45 ;
if ( ! V_6 -> V_53 )
return - V_54 ;
F_11 ( L_10 ,
V_38 , * V_39 , V_6 -> V_12 ) ;
if ( V_6 -> V_55 == V_56 )
return - V_57 ;
V_40 = F_29 ( * V_39 , V_6 -> V_49 , & V_41 ) ;
if ( V_41 & ( V_7 -> V_50 - 1 ) ) {
F_4 ( L_11 ) ;
return - V_58 ;
}
if ( * V_39 + V_38 > V_6 -> V_31 )
V_44 = V_38 = V_6 -> V_31 - * V_39 ;
if ( V_38 & ( V_7 -> V_50 - 1 ) ) {
F_4 ( L_12 ) ;
return - V_58 ;
}
V_43 = V_6 -> V_49 ;
if ( V_38 < V_43 )
V_43 = F_27 ( V_38 , V_7 -> V_50 ) ;
V_45 = F_28 ( V_43 ) ;
if ( ! V_45 )
return - V_51 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
while ( V_38 ) {
F_30 () ;
if ( V_41 + V_42 >= V_6 -> V_49 )
V_42 = V_6 -> V_49 - V_41 ;
V_4 = F_34 ( V_45 , V_37 , V_42 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_35 ( V_7 , V_6 , V_40 , V_45 , V_41 , V_42 ) ;
if ( V_4 )
break;
V_41 += V_42 ;
if ( V_41 == V_6 -> V_49 ) {
V_40 += 1 ;
V_41 -= V_6 -> V_49 ;
}
V_38 -= V_42 ;
* V_39 += V_42 ;
V_37 += V_42 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
}
F_17 ( V_45 ) ;
return V_4 ? V_4 : V_44 - V_38 ;
}
static T_2 F_36 ( struct V_19 * V_19 , const char T_3 * V_37 ,
T_4 V_38 , T_1 * V_39 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_35 * V_7 = V_6 -> V_7 ;
if ( ! V_6 -> V_24 && ! V_6 -> V_25 )
return F_33 ( V_19 , V_37 , V_38 , V_39 ) ;
if ( V_6 -> V_24 )
V_4 = F_37 ( V_7 , V_6 , V_37 , V_38 ) ;
else
V_4 = F_38 ( V_7 , V_6 , V_37 , V_38 ) ;
if ( V_4 < 0 ) {
F_4 ( L_13 ,
V_38 , V_4 ) ;
return V_4 ;
}
if ( V_4 ) {
V_38 = V_4 ;
if ( V_6 -> V_25 ) {
F_6 ( V_2 , V_17 ) ;
return V_38 ;
}
V_4 = F_39 ( V_7 , V_6 -> V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 ) {
F_16 ( L_14 ,
V_6 -> V_12 , V_7 -> V_20 ) ;
V_6 -> V_48 = 1 ;
}
V_6 -> V_59 = 1 ;
F_40 ( V_7 , V_6 , V_60 ) ;
F_6 ( V_2 , V_17 ) ;
}
return V_38 ;
}
static long F_41 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_35 * V_7 = V_6 -> V_7 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
switch ( V_61 ) {
case V_64 :
{
T_5 V_65 , V_66 ;
if ( ! F_42 ( V_67 ) ) {
V_4 = - V_54 ;
break;
}
V_4 = F_34 ( & V_65 , V_63 , sizeof( T_5 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
if ( V_2 -> V_14 == V_16 ) {
V_4 = - V_57 ;
break;
}
V_66 = ( long long ) V_6 -> V_68 *
V_7 -> V_69 - V_6 -> V_70 ;
if ( V_65 < 0 || V_65 > V_66 ) {
V_4 = - V_58 ;
break;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_43 ( V_7 , V_6 , V_65 ) ;
if ( V_65 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_71 :
{
struct V_72 V_73 ;
V_4 = F_34 ( & V_73 , V_63 ,
sizeof( struct V_72 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
if ( V_2 -> V_14 == V_16 ||
V_6 -> V_55 == V_56 ) {
V_4 = - V_57 ;
break;
}
V_4 = - V_58 ;
if ( V_73 . V_40 < 0 || V_73 . V_40 >= V_6 -> V_68 ||
V_73 . V_65 < 0 || V_73 . V_40 >= V_6 -> V_49 )
break;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_44 ( V_7 , V_6 , & V_73 ) ;
if ( V_73 . V_65 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_74 :
{
T_6 V_40 ;
V_4 = F_45 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
if ( V_2 -> V_14 == V_16 ||
V_6 -> V_55 == V_56 ) {
V_4 = - V_57 ;
break;
}
if ( V_40 < 0 || V_40 >= V_6 -> V_68 ) {
V_4 = - V_58 ;
break;
}
F_11 ( L_15 , V_6 -> V_12 , V_40 ) ;
V_4 = F_46 ( V_7 , V_6 , V_40 ) ;
if ( V_4 )
break;
V_4 = F_47 ( V_7 , V_75 , V_75 ) ;
break;
}
case V_76 :
{
struct V_77 V_73 ;
V_4 = F_34 ( & V_73 , V_63 , sizeof( struct V_77 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_48 ( V_2 , V_73 . V_40 ) ;
break;
}
case V_78 :
{
T_6 V_40 ;
V_4 = F_45 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_49 ( V_2 , V_40 ) ;
break;
}
case V_79 :
{
T_6 V_40 ;
V_4 = F_45 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_50 ( V_2 , V_40 ) ;
break;
}
case V_80 :
{
struct V_81 V_73 ;
V_4 = F_34 ( & V_73 , V_63 ,
sizeof( struct V_81 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
switch ( V_73 . V_82 ) {
case V_83 :
F_23 ( & V_7 -> V_84 ) ;
V_2 -> V_6 -> V_53 = ! ! V_73 . V_85 ;
F_25 ( & V_7 -> V_84 ) ;
break;
default:
V_4 = - V_58 ;
break;
}
break;
}
case V_86 :
{
struct V_87 V_88 ;
F_51 ( V_2 , & V_88 ) ;
V_4 = F_52 ( & V_88 ) ;
break;
}
case V_89 :
{
struct V_87 V_88 ;
F_51 ( V_2 , & V_88 ) ;
V_4 = F_53 ( & V_88 ) ;
break;
}
default:
V_4 = - V_90 ;
break;
}
return V_4 ;
}
static int F_54 ( const struct V_35 * V_7 ,
const struct V_91 * V_73 )
{
int V_92 , V_4 = - V_58 ;
if ( V_73 -> V_65 < 0 || V_73 -> V_93 < 0 || V_73 -> V_55 < 0 ||
V_73 -> V_94 < 0 )
goto V_95;
if ( ( V_73 -> V_12 < 0 || V_73 -> V_12 >= V_7 -> V_96 ) &&
V_73 -> V_12 != V_97 )
goto V_95;
if ( V_73 -> V_93 == 0 )
goto V_95;
if ( V_73 -> V_65 == 0 )
goto V_95;
if ( V_73 -> V_55 != V_98 &&
V_73 -> V_55 != V_56 )
goto V_95;
if ( V_73 -> V_93 > V_7 -> V_69 )
goto V_95;
V_92 = V_73 -> V_93 & ( V_7 -> V_50 - 1 ) ;
if ( V_73 -> V_93 != 1 && V_92 )
goto V_95;
if ( ! V_73 -> V_99 [ 0 ] || ! V_73 -> V_94 )
goto V_95;
if ( V_73 -> V_94 > V_100 ) {
V_4 = - V_101 ;
goto V_95;
}
V_92 = F_55 ( V_73 -> V_99 , V_73 -> V_94 + 1 ) ;
if ( V_92 != V_73 -> V_94 )
goto V_95;
return 0 ;
V_95:
F_4 ( L_16 ) ;
F_56 ( V_73 ) ;
return V_4 ;
}
static int F_57 ( const struct V_35 * V_7 ,
const struct V_102 * V_73 )
{
if ( V_73 -> V_65 <= 0 )
return - V_58 ;
if ( V_73 -> V_12 < 0 || V_73 -> V_12 >= V_7 -> V_96 )
return - V_58 ;
return 0 ;
}
static int F_58 ( struct V_35 * V_7 ,
struct V_103 * V_73 )
{
int V_104 , V_92 , V_4 ;
struct V_105 V_106 ;
struct V_107 * V_108 , * V_109 ;
if ( V_73 -> V_38 < 0 || V_73 -> V_38 > V_110 )
return - V_58 ;
if ( V_73 -> V_38 == 0 )
return 0 ;
for ( V_104 = 0 ; V_104 < V_73 -> V_38 ; V_104 ++ ) {
if ( V_73 -> V_111 [ V_104 ] . V_12 < 0 ||
V_73 -> V_111 [ V_104 ] . V_12 >= V_7 -> V_96 )
return - V_58 ;
if ( V_73 -> V_111 [ V_104 ] . V_94 < 0 )
return - V_58 ;
if ( V_73 -> V_111 [ V_104 ] . V_94 > V_100 )
return - V_101 ;
V_73 -> V_111 [ V_104 ] . V_99 [ V_73 -> V_111 [ V_104 ] . V_94 ] = '\0' ;
V_92 = strlen ( V_73 -> V_111 [ V_104 ] . V_99 ) ;
if ( V_92 != V_73 -> V_111 [ V_104 ] . V_94 )
V_4 = - V_58 ;
}
for ( V_104 = 0 ; V_104 < V_73 -> V_38 - 1 ; V_104 ++ ) {
for ( V_92 = V_104 + 1 ; V_92 < V_73 -> V_38 ; V_92 ++ ) {
if ( V_73 -> V_111 [ V_104 ] . V_12 == V_73 -> V_111 [ V_92 ] . V_12 ) {
F_4 ( L_17 ,
V_73 -> V_111 [ V_104 ] . V_12 ) ;
return - V_58 ;
}
if ( ! strcmp ( V_73 -> V_111 [ V_104 ] . V_99 , V_73 -> V_111 [ V_92 ] . V_99 ) ) {
F_4 ( L_18 ,
V_73 -> V_111 [ V_104 ] . V_99 ) ;
return - V_58 ;
}
}
}
F_59 ( & V_106 ) ;
for ( V_104 = 0 ; V_104 < V_73 -> V_38 ; V_104 ++ ) {
int V_12 = V_73 -> V_111 [ V_104 ] . V_12 ;
int V_94 = V_73 -> V_111 [ V_104 ] . V_94 ;
const char * V_99 = V_73 -> V_111 [ V_104 ] . V_99 ;
V_108 = F_60 ( sizeof( struct V_107 ) , V_112 ) ;
if ( ! V_108 ) {
V_4 = - V_51 ;
goto V_113;
}
V_108 -> V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_108 -> V_2 ) ) {
V_4 = F_14 ( V_108 -> V_2 ) ;
F_4 ( L_19 , V_12 , V_4 ) ;
F_61 ( V_108 ) ;
goto V_113;
}
if ( V_108 -> V_2 -> V_6 -> V_94 == V_94 &&
! memcmp ( V_108 -> V_2 -> V_6 -> V_99 , V_99 , V_94 ) ) {
F_18 ( V_108 -> V_2 ) ;
F_61 ( V_108 ) ;
continue;
}
V_108 -> V_114 = V_94 ;
memcpy ( V_108 -> V_115 , V_99 , V_94 ) ;
F_62 ( & V_108 -> V_116 , & V_106 ) ;
F_11 ( L_20 ,
V_12 , V_108 -> V_2 -> V_6 -> V_99 , V_99 ) ;
}
if ( F_63 ( & V_106 ) )
return 0 ;
F_64 (re, &rename_list, list) {
struct V_1 * V_2 ;
int V_117 = 0 ;
F_64 (re1, &rename_list, list) {
if ( V_108 -> V_114 == V_109 -> V_2 -> V_6 -> V_94 &&
! memcmp ( V_108 -> V_115 , V_109 -> V_2 -> V_6 -> V_99 ,
V_109 -> V_2 -> V_6 -> V_94 ) ) {
V_117 = 1 ;
break;
}
}
if ( V_117 )
continue;
V_2 = F_65 ( V_7 -> V_20 , V_108 -> V_115 ,
V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 == - V_118 )
continue;
F_4 ( L_21 ,
V_108 -> V_115 , V_4 ) ;
goto V_113;
}
V_109 = F_60 ( sizeof( struct V_107 ) , V_112 ) ;
if ( ! V_109 ) {
V_4 = - V_51 ;
F_18 ( V_2 ) ;
goto V_113;
}
V_109 -> remove = 1 ;
V_109 -> V_2 = V_2 ;
F_66 ( & V_109 -> V_116 , & V_106 ) ;
F_11 ( L_22 ,
V_109 -> V_2 -> V_6 -> V_12 , V_109 -> V_2 -> V_6 -> V_99 ) ;
}
F_23 ( & V_7 -> V_84 ) ;
V_4 = F_67 ( V_7 , & V_106 ) ;
F_25 ( & V_7 -> V_84 ) ;
V_113:
F_68 (re, re1, &rename_list, list) {
F_18 ( V_108 -> V_2 ) ;
F_69 ( & V_108 -> V_116 ) ;
F_61 ( V_108 ) ;
}
return V_4 ;
}
static long F_70 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_4 = 0 ;
struct V_35 * V_7 ;
struct V_1 * V_2 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
if ( ! F_42 ( V_67 ) )
return - V_54 ;
V_7 = F_71 ( F_10 ( V_19 -> V_119 -> V_120 ) ) ;
if ( ! V_7 )
return - V_118 ;
switch ( V_61 ) {
case V_121 :
{
struct V_91 V_73 ;
F_11 ( L_23 ) ;
V_4 = F_34 ( & V_73 , V_63 , sizeof( struct V_91 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_54 ( V_7 , & V_73 ) ;
if ( V_4 )
break;
F_23 ( & V_7 -> V_84 ) ;
V_4 = F_72 ( V_7 , & V_73 ) ;
F_25 ( & V_7 -> V_84 ) ;
if ( V_4 )
break;
V_4 = F_73 ( V_73 . V_12 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 )
V_4 = - V_52 ;
break;
}
case V_122 :
{
int V_12 ;
F_11 ( L_24 ) ;
V_4 = F_45 ( V_12 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
F_23 ( & V_7 -> V_84 ) ;
V_4 = F_74 ( V_2 , 0 ) ;
F_25 ( & V_7 -> V_84 ) ;
F_18 ( V_2 ) ;
break;
}
case V_123 :
{
int V_124 ;
struct V_102 V_73 ;
F_11 ( L_25 ) ;
V_4 = F_34 ( & V_73 , V_63 , sizeof( struct V_102 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_57 ( V_7 , & V_73 ) ;
if ( V_4 )
break;
V_2 = F_12 ( V_7 -> V_20 , V_73 . V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
V_124 = F_75 ( V_73 . V_65 + V_2 -> V_6 -> V_49 - 1 ,
V_2 -> V_6 -> V_49 ) ;
F_23 ( & V_7 -> V_84 ) ;
V_4 = F_76 ( V_2 , V_124 ) ;
F_25 ( & V_7 -> V_84 ) ;
F_18 ( V_2 ) ;
break;
}
case V_125 :
{
struct V_103 * V_73 ;
F_11 ( L_26 ) ;
V_73 = F_77 ( sizeof( struct V_103 ) , V_112 ) ;
if ( ! V_73 ) {
V_4 = - V_51 ;
break;
} ;
V_4 = F_34 ( V_73 , V_63 , sizeof( struct V_103 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
F_61 ( V_73 ) ;
break;
}
V_4 = F_58 ( V_7 , V_73 ) ;
F_61 ( V_73 ) ;
break;
}
default:
V_4 = - V_90 ;
break;
}
F_78 ( V_7 ) ;
return V_4 ;
}
static long F_79 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_4 = 0 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
if ( ! F_42 ( V_67 ) )
return - V_54 ;
switch ( V_61 ) {
case V_126 :
{
struct V_127 V_73 ;
struct V_128 * V_129 ;
F_11 ( L_27 ) ;
V_4 = F_34 ( & V_73 , V_63 , sizeof( struct V_127 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
if ( V_73 . V_130 < 0 ||
( V_73 . V_20 < 0 && V_73 . V_20 != V_131 ) ) {
V_4 = - V_58 ;
break;
}
V_129 = F_80 ( NULL , V_73 . V_130 ) ;
if ( F_13 ( V_129 ) ) {
V_4 = F_14 ( V_129 ) ;
break;
}
F_23 ( & V_132 ) ;
V_4 = F_81 ( V_129 , V_73 . V_20 , V_73 . V_133 ,
V_73 . V_134 ) ;
F_25 ( & V_132 ) ;
if ( V_4 < 0 )
F_82 ( V_129 ) ;
else
V_4 = F_73 ( V_4 , ( T_3 T_6 * ) V_63 ) ;
break;
}
case V_135 :
{
int V_20 ;
F_11 ( L_28 ) ;
V_4 = F_45 ( V_20 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
F_23 ( & V_132 ) ;
V_4 = F_83 ( V_20 , 0 ) ;
F_25 ( & V_132 ) ;
break;
}
default:
V_4 = - V_90 ;
break;
}
return V_4 ;
}
static long F_84 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_136 = ( unsigned long ) F_85 ( V_62 ) ;
return F_41 ( V_19 , V_61 , V_136 ) ;
}
static long F_86 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_136 = ( unsigned long ) F_85 ( V_62 ) ;
return F_70 ( V_19 , V_61 , V_136 ) ;
}
static long F_87 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_136 = ( unsigned long ) F_85 ( V_62 ) ;
return F_79 ( V_19 , V_61 , V_136 ) ;
}

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
static int F_20 ( struct V_19 * V_19 , int V_35 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_36 * V_7 = V_2 -> V_6 -> V_7 ;
return F_21 ( V_7 -> V_20 ) ;
}
static T_2 F_22 ( struct V_19 * V_19 , T_3 char * V_37 , T_4 V_38 ,
T_1 * V_39 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_36 * V_7 = V_6 -> V_7 ;
int V_4 , V_40 , V_41 , V_42 , V_43 ;
T_4 V_44 = V_38 ;
void * V_45 ;
F_11 ( L_10 ,
V_38 , * V_39 , V_6 -> V_12 ) ;
if ( V_6 -> V_24 ) {
F_4 ( L_7 ) ;
return - V_13 ;
}
if ( V_6 -> V_46 ) {
F_4 ( L_11 ) ;
return - V_47 ;
}
if ( * V_39 == V_6 -> V_33 || V_38 == 0 )
return 0 ;
if ( V_6 -> V_48 )
F_11 ( L_12 , V_6 -> V_12 ) ;
if ( * V_39 + V_38 > V_6 -> V_33 )
V_44 = V_38 = V_6 -> V_33 - * V_39 ;
V_43 = V_6 -> V_49 ;
if ( V_38 < V_43 )
V_43 = F_23 ( V_38 , V_7 -> V_50 ) ;
V_45 = F_24 ( V_43 ) ;
if ( ! V_45 )
return - V_51 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
V_40 = F_25 ( * V_39 , V_6 -> V_49 , & V_41 ) ;
do {
F_26 () ;
if ( V_41 + V_42 >= V_6 -> V_49 )
V_42 = V_6 -> V_49 - V_41 ;
V_4 = F_27 ( V_7 , V_6 , V_40 , V_45 , V_41 , V_42 , 0 ) ;
if ( V_4 )
break;
V_41 += V_42 ;
if ( V_41 == V_6 -> V_49 ) {
V_40 += 1 ;
V_41 -= V_6 -> V_49 ;
}
V_38 -= V_42 ;
* V_39 += V_42 ;
V_4 = F_28 ( V_37 , V_45 , V_42 ) ;
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
static T_2 F_29 ( struct V_19 * V_19 , const char T_3 * V_37 ,
T_4 V_38 , T_1 * V_39 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_36 * V_7 = V_6 -> V_7 ;
int V_40 , V_41 , V_42 , V_43 , V_4 = 0 ;
T_4 V_44 = V_38 ;
char * V_45 ;
if ( ! V_6 -> V_53 )
return - V_54 ;
F_11 ( L_13 ,
V_38 , * V_39 , V_6 -> V_12 ) ;
if ( V_6 -> V_55 == V_56 )
return - V_57 ;
V_40 = F_25 ( * V_39 , V_6 -> V_49 , & V_41 ) ;
if ( V_41 & ( V_7 -> V_50 - 1 ) ) {
F_4 ( L_14 ) ;
return - V_34 ;
}
if ( * V_39 + V_38 > V_6 -> V_33 )
V_44 = V_38 = V_6 -> V_33 - * V_39 ;
if ( V_38 & ( V_7 -> V_50 - 1 ) ) {
F_4 ( L_15 ) ;
return - V_34 ;
}
V_43 = V_6 -> V_49 ;
if ( V_38 < V_43 )
V_43 = F_23 ( V_38 , V_7 -> V_50 ) ;
V_45 = F_24 ( V_43 ) ;
if ( ! V_45 )
return - V_51 ;
V_42 = V_38 > V_43 ? V_43 : V_38 ;
while ( V_38 ) {
F_26 () ;
if ( V_41 + V_42 >= V_6 -> V_49 )
V_42 = V_6 -> V_49 - V_41 ;
V_4 = F_30 ( V_45 , V_37 , V_42 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_31 ( V_7 , V_6 , V_40 , V_45 , V_41 , V_42 ,
V_58 ) ;
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
static T_2 F_32 ( struct V_19 * V_19 , const char T_3 * V_37 ,
T_4 V_38 , T_1 * V_39 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_36 * V_7 = V_6 -> V_7 ;
if ( ! V_6 -> V_24 && ! V_6 -> V_25 )
return F_29 ( V_19 , V_37 , V_38 , V_39 ) ;
if ( V_6 -> V_24 )
V_4 = F_33 ( V_7 , V_6 , V_37 , V_38 ) ;
else
V_4 = F_34 ( V_7 , V_6 , V_37 , V_38 ) ;
if ( V_4 < 0 ) {
F_35 ( L_16 ,
V_38 , V_4 ) ;
return V_4 ;
}
if ( V_4 ) {
V_38 = V_4 ;
if ( V_6 -> V_25 ) {
F_6 ( V_2 , V_17 ) ;
return V_38 ;
}
V_4 = F_36 ( V_7 , V_6 -> V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 ) {
F_16 ( L_17 ,
V_6 -> V_12 , V_7 -> V_20 ) ;
V_6 -> V_48 = 1 ;
}
V_6 -> V_59 = 1 ;
F_37 ( V_7 , V_6 , V_60 ) ;
F_6 ( V_2 , V_17 ) ;
}
return V_38 ;
}
static long F_38 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_36 * V_7 = V_6 -> V_7 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
switch ( V_61 ) {
case V_64 :
{
T_5 V_65 , V_66 ;
if ( ! F_39 ( V_67 ) ) {
V_4 = - V_54 ;
break;
}
V_4 = F_30 ( & V_65 , V_63 , sizeof( T_5 ) ) ;
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
V_4 = - V_34 ;
break;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_40 ( V_7 , V_6 , V_65 ) ;
if ( V_65 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_71 :
{
struct V_72 V_73 ;
V_4 = F_30 ( & V_73 , V_63 ,
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
V_4 = - V_34 ;
if ( V_73 . V_40 < 0 || V_73 . V_40 >= V_6 -> V_68 ||
V_73 . V_65 < 0 || V_73 . V_40 >= V_6 -> V_49 )
break;
if ( V_73 . V_74 != V_75 && V_73 . V_74 != V_76 &&
V_73 . V_74 != V_58 )
break;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_41 ( V_7 , V_6 , & V_73 ) ;
if ( V_73 . V_65 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_77 :
{
T_6 V_40 ;
V_4 = F_42 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
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
V_4 = - V_34 ;
break;
}
F_11 ( L_18 , V_6 -> V_12 , V_40 ) ;
V_4 = F_43 ( V_7 , V_6 , V_40 ) ;
if ( V_4 )
break;
V_4 = F_44 ( V_7 ) ;
break;
}
case V_78 :
{
struct V_79 V_73 ;
V_4 = F_30 ( & V_73 , V_63 , sizeof( struct V_79 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_45 ( V_2 , V_73 . V_40 , V_73 . V_74 ) ;
break;
}
case V_80 :
{
T_6 V_40 ;
V_4 = F_42 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_46 ( V_2 , V_40 ) ;
break;
}
case V_81 :
{
T_6 V_40 ;
V_4 = F_42 ( V_40 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_47 ( V_2 , V_40 ) ;
break;
}
case V_82 :
{
struct V_83 V_73 ;
V_4 = F_30 ( & V_73 , V_63 ,
sizeof( struct V_83 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
switch ( V_73 . V_84 ) {
case V_85 :
F_48 ( & V_7 -> V_86 ) ;
V_2 -> V_6 -> V_53 = ! ! V_73 . V_87 ;
F_49 ( & V_7 -> V_86 ) ;
break;
default:
V_4 = - V_34 ;
break;
}
break;
}
default:
V_4 = - V_88 ;
break;
}
return V_4 ;
}
static int F_50 ( const struct V_36 * V_7 ,
const struct V_89 * V_73 )
{
int V_90 , V_4 = - V_34 ;
if ( V_73 -> V_65 < 0 || V_73 -> V_91 < 0 || V_73 -> V_55 < 0 ||
V_73 -> V_92 < 0 )
goto V_93;
if ( ( V_73 -> V_12 < 0 || V_73 -> V_12 >= V_7 -> V_94 ) &&
V_73 -> V_12 != V_95 )
goto V_93;
if ( V_73 -> V_91 == 0 )
goto V_93;
if ( V_73 -> V_65 == 0 )
goto V_93;
if ( V_73 -> V_55 != V_96 &&
V_73 -> V_55 != V_56 )
goto V_93;
if ( V_73 -> V_91 > V_7 -> V_69 )
goto V_93;
V_90 = V_73 -> V_91 & ( V_7 -> V_50 - 1 ) ;
if ( V_73 -> V_91 != 1 && V_90 )
goto V_93;
if ( V_73 -> V_92 > V_97 ) {
V_4 = - V_98 ;
goto V_93;
}
V_90 = F_51 ( V_73 -> V_99 , V_73 -> V_92 + 1 ) ;
if ( V_90 != V_73 -> V_92 )
goto V_93;
return 0 ;
V_93:
F_4 ( L_19 ) ;
F_52 ( V_73 ) ;
return V_4 ;
}
static int F_53 ( const struct V_36 * V_7 ,
const struct V_100 * V_73 )
{
if ( V_73 -> V_65 <= 0 )
return - V_34 ;
if ( V_73 -> V_12 < 0 || V_73 -> V_12 >= V_7 -> V_94 )
return - V_34 ;
return 0 ;
}
static int F_54 ( struct V_36 * V_7 ,
struct V_101 * V_73 )
{
int V_102 , V_90 , V_4 ;
struct V_103 V_104 ;
struct V_105 * V_106 , * V_107 ;
if ( V_73 -> V_38 < 0 || V_73 -> V_38 > V_108 )
return - V_34 ;
if ( V_73 -> V_38 == 0 )
return 0 ;
for ( V_102 = 0 ; V_102 < V_73 -> V_38 ; V_102 ++ ) {
if ( V_73 -> V_109 [ V_102 ] . V_12 < 0 ||
V_73 -> V_109 [ V_102 ] . V_12 >= V_7 -> V_94 )
return - V_34 ;
if ( V_73 -> V_109 [ V_102 ] . V_92 < 0 )
return - V_34 ;
if ( V_73 -> V_109 [ V_102 ] . V_92 > V_97 )
return - V_98 ;
V_73 -> V_109 [ V_102 ] . V_99 [ V_73 -> V_109 [ V_102 ] . V_92 ] = '\0' ;
V_90 = strlen ( V_73 -> V_109 [ V_102 ] . V_99 ) ;
if ( V_90 != V_73 -> V_109 [ V_102 ] . V_92 )
V_4 = - V_34 ;
}
for ( V_102 = 0 ; V_102 < V_73 -> V_38 - 1 ; V_102 ++ ) {
for ( V_90 = V_102 + 1 ; V_90 < V_73 -> V_38 ; V_90 ++ ) {
if ( V_73 -> V_109 [ V_102 ] . V_12 == V_73 -> V_109 [ V_90 ] . V_12 ) {
F_4 ( L_20 ,
V_73 -> V_109 [ V_102 ] . V_12 ) ;
return - V_34 ;
}
if ( ! strcmp ( V_73 -> V_109 [ V_102 ] . V_99 , V_73 -> V_109 [ V_90 ] . V_99 ) ) {
F_4 ( L_21 ,
V_73 -> V_109 [ V_102 ] . V_99 ) ;
return - V_34 ;
}
}
}
F_55 ( & V_104 ) ;
for ( V_102 = 0 ; V_102 < V_73 -> V_38 ; V_102 ++ ) {
int V_12 = V_73 -> V_109 [ V_102 ] . V_12 ;
int V_92 = V_73 -> V_109 [ V_102 ] . V_92 ;
const char * V_99 = V_73 -> V_109 [ V_102 ] . V_99 ;
V_106 = F_56 ( sizeof( struct V_105 ) , V_110 ) ;
if ( ! V_106 ) {
V_4 = - V_51 ;
goto V_111;
}
V_106 -> V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_106 -> V_2 ) ) {
V_4 = F_14 ( V_106 -> V_2 ) ;
F_4 ( L_22 , V_12 , V_4 ) ;
F_57 ( V_106 ) ;
goto V_111;
}
if ( V_106 -> V_2 -> V_6 -> V_92 == V_92 &&
! memcmp ( V_106 -> V_2 -> V_6 -> V_99 , V_99 , V_92 ) ) {
F_18 ( V_106 -> V_2 ) ;
F_57 ( V_106 ) ;
continue;
}
V_106 -> V_112 = V_92 ;
memcpy ( V_106 -> V_113 , V_99 , V_92 ) ;
F_58 ( & V_106 -> V_114 , & V_104 ) ;
F_59 ( L_23 ,
V_12 , V_106 -> V_2 -> V_6 -> V_99 , V_99 ) ;
}
if ( F_60 ( & V_104 ) )
return 0 ;
F_61 (re, &rename_list, list) {
struct V_1 * V_2 ;
int V_115 = 0 ;
F_61 (re1, &rename_list, list) {
if ( V_106 -> V_112 == V_107 -> V_2 -> V_6 -> V_92 &&
! memcmp ( V_106 -> V_113 , V_107 -> V_2 -> V_6 -> V_99 ,
V_107 -> V_2 -> V_6 -> V_92 ) ) {
V_115 = 1 ;
break;
}
}
if ( V_115 )
continue;
V_2 = F_62 ( V_7 -> V_20 , V_106 -> V_113 ,
V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 == - V_116 )
continue;
F_4 ( L_24 ,
V_106 -> V_113 , V_4 ) ;
goto V_111;
}
V_107 = F_56 ( sizeof( struct V_105 ) , V_110 ) ;
if ( ! V_107 ) {
V_4 = - V_51 ;
F_18 ( V_2 ) ;
goto V_111;
}
V_107 -> remove = 1 ;
V_107 -> V_2 = V_2 ;
F_63 ( & V_107 -> V_114 , & V_104 ) ;
F_59 ( L_25 ,
V_107 -> V_2 -> V_6 -> V_12 , V_107 -> V_2 -> V_6 -> V_99 ) ;
}
F_48 ( & V_7 -> V_86 ) ;
V_4 = F_64 ( V_7 , & V_104 ) ;
F_49 ( & V_7 -> V_86 ) ;
V_111:
F_65 (re, re1, &rename_list, list) {
F_18 ( V_106 -> V_2 ) ;
F_66 ( & V_106 -> V_114 ) ;
F_57 ( V_106 ) ;
}
return V_4 ;
}
static long F_67 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_4 = 0 ;
struct V_36 * V_7 ;
struct V_1 * V_2 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
if ( ! F_39 ( V_67 ) )
return - V_54 ;
V_7 = F_68 ( F_10 ( V_19 -> V_117 -> V_118 ) ) ;
if ( ! V_7 )
return - V_116 ;
switch ( V_61 ) {
case V_119 :
{
struct V_89 V_73 ;
F_11 ( L_26 ) ;
V_4 = F_30 ( & V_73 , V_63 , sizeof( struct V_89 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_50 ( V_7 , & V_73 ) ;
if ( V_4 )
break;
F_48 ( & V_7 -> V_86 ) ;
V_4 = F_69 ( V_7 , & V_73 ) ;
F_49 ( & V_7 -> V_86 ) ;
if ( V_4 )
break;
V_4 = F_70 ( V_73 . V_12 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 )
V_4 = - V_52 ;
break;
}
case V_120 :
{
int V_12 ;
F_11 ( L_27 ) ;
V_4 = F_42 ( V_12 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
F_48 ( & V_7 -> V_86 ) ;
V_4 = F_71 ( V_2 , 0 ) ;
F_49 ( & V_7 -> V_86 ) ;
F_18 ( V_2 ) ;
break;
}
case V_121 :
{
int V_122 ;
struct V_100 V_73 ;
F_11 ( L_28 ) ;
V_4 = F_30 ( & V_73 , V_63 , sizeof( struct V_100 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
V_4 = F_53 ( V_7 , & V_73 ) ;
if ( V_4 )
break;
V_2 = F_12 ( V_7 -> V_20 , V_73 . V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
V_122 = F_72 ( V_73 . V_65 + V_2 -> V_6 -> V_49 - 1 ,
V_2 -> V_6 -> V_49 ) ;
F_48 ( & V_7 -> V_86 ) ;
V_4 = F_73 ( V_2 , V_122 ) ;
F_49 ( & V_7 -> V_86 ) ;
F_18 ( V_2 ) ;
break;
}
case V_123 :
{
struct V_101 * V_73 ;
F_59 ( L_29 ) ;
V_73 = F_74 ( sizeof( struct V_101 ) , V_110 ) ;
if ( ! V_73 ) {
V_4 = - V_51 ;
break;
} ;
V_4 = F_30 ( V_73 , V_63 , sizeof( struct V_101 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
F_57 ( V_73 ) ;
break;
}
V_4 = F_54 ( V_7 , V_73 ) ;
F_57 ( V_73 ) ;
break;
}
default:
V_4 = - V_88 ;
break;
}
F_75 ( V_7 ) ;
return V_4 ;
}
static long F_76 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
int V_4 = 0 ;
void T_3 * V_63 = ( void T_3 * ) V_62 ;
if ( ! F_39 ( V_67 ) )
return - V_54 ;
switch ( V_61 ) {
case V_124 :
{
struct V_125 V_73 ;
struct V_126 * V_127 ;
F_11 ( L_30 ) ;
V_4 = F_30 ( & V_73 , V_63 , sizeof( struct V_125 ) ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
if ( V_73 . V_128 < 0 ||
( V_73 . V_20 < 0 && V_73 . V_20 != V_129 ) ) {
V_4 = - V_34 ;
break;
}
V_127 = F_77 ( NULL , V_73 . V_128 ) ;
if ( F_13 ( V_127 ) ) {
V_4 = F_14 ( V_127 ) ;
break;
}
F_48 ( & V_130 ) ;
V_4 = F_78 ( V_127 , V_73 . V_20 , V_73 . V_131 ) ;
F_49 ( & V_130 ) ;
if ( V_4 < 0 )
F_79 ( V_127 ) ;
else
V_4 = F_70 ( V_4 , ( T_3 T_6 * ) V_63 ) ;
break;
}
case V_132 :
{
int V_20 ;
F_11 ( L_31 ) ;
V_4 = F_42 ( V_20 , ( T_3 T_6 * ) V_63 ) ;
if ( V_4 ) {
V_4 = - V_52 ;
break;
}
F_48 ( & V_130 ) ;
V_4 = F_80 ( V_20 , 0 ) ;
F_49 ( & V_130 ) ;
break;
}
default:
V_4 = - V_88 ;
break;
}
return V_4 ;
}
static long F_81 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_133 = ( unsigned long ) F_82 ( V_62 ) ;
return F_38 ( V_19 , V_61 , V_133 ) ;
}
static long F_83 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_133 = ( unsigned long ) F_82 ( V_62 ) ;
return F_67 ( V_19 , V_61 , V_133 ) ;
}
static long F_84 ( struct V_19 * V_19 , unsigned int V_61 ,
unsigned long V_62 )
{
unsigned long V_133 = ( unsigned long ) F_82 ( V_62 ) ;
return F_76 ( V_19 , V_61 , V_133 ) ;
}

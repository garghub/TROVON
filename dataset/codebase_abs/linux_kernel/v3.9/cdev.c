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
struct V_18 * V_18 = F_21 ( V_19 ) ;
int V_4 ;
F_22 ( & V_18 -> V_39 ) ;
V_4 = F_23 ( V_7 -> V_20 ) ;
F_24 ( & V_18 -> V_39 ) ;
return V_4 ;
}
static T_2 F_25 ( struct V_19 * V_19 , T_3 char * V_40 , T_4 V_41 ,
T_1 * V_42 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
int V_4 , V_43 , V_44 , V_45 , V_46 ;
T_4 V_47 = V_41 ;
void * V_48 ;
F_11 ( L_9 ,
V_41 , * V_42 , V_6 -> V_12 ) ;
if ( V_6 -> V_24 ) {
F_4 ( L_6 ) ;
return - V_13 ;
}
if ( V_6 -> V_49 ) {
F_4 ( L_10 ) ;
return - V_50 ;
}
if ( * V_42 == V_6 -> V_33 || V_41 == 0 )
return 0 ;
if ( V_6 -> V_51 )
F_11 ( L_11 , V_6 -> V_12 ) ;
if ( * V_42 + V_41 > V_6 -> V_33 )
V_47 = V_41 = V_6 -> V_33 - * V_42 ;
V_46 = V_6 -> V_52 ;
if ( V_41 < V_46 )
V_46 = F_26 ( V_41 , V_7 -> V_53 ) ;
V_48 = F_27 ( V_46 ) ;
if ( ! V_48 )
return - V_54 ;
V_45 = V_41 > V_46 ? V_46 : V_41 ;
V_43 = F_28 ( * V_42 , V_6 -> V_52 , & V_44 ) ;
do {
F_29 () ;
if ( V_44 + V_45 >= V_6 -> V_52 )
V_45 = V_6 -> V_52 - V_44 ;
V_4 = F_30 ( V_7 , V_6 , V_43 , V_48 , V_44 , V_45 , 0 ) ;
if ( V_4 )
break;
V_44 += V_45 ;
if ( V_44 == V_6 -> V_52 ) {
V_43 += 1 ;
V_44 -= V_6 -> V_52 ;
}
V_41 -= V_45 ;
* V_42 += V_45 ;
V_4 = F_31 ( V_40 , V_48 , V_45 ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
V_40 += V_45 ;
V_45 = V_41 > V_46 ? V_46 : V_41 ;
} while ( V_41 );
F_17 ( V_48 ) ;
return V_4 ? V_4 : V_47 - V_41 ;
}
static T_2 F_32 ( struct V_19 * V_19 , const char T_3 * V_40 ,
T_4 V_41 , T_1 * V_42 )
{
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
int V_43 , V_44 , V_45 , V_46 , V_4 = 0 ;
T_4 V_47 = V_41 ;
char * V_48 ;
if ( ! V_6 -> V_56 )
return - V_57 ;
F_11 ( L_12 ,
V_41 , * V_42 , V_6 -> V_12 ) ;
if ( V_6 -> V_58 == V_59 )
return - V_60 ;
V_43 = F_28 ( * V_42 , V_6 -> V_52 , & V_44 ) ;
if ( V_44 & ( V_7 -> V_53 - 1 ) ) {
F_4 ( L_13 ) ;
return - V_34 ;
}
if ( * V_42 + V_41 > V_6 -> V_33 )
V_47 = V_41 = V_6 -> V_33 - * V_42 ;
if ( V_41 & ( V_7 -> V_53 - 1 ) ) {
F_4 ( L_14 ) ;
return - V_34 ;
}
V_46 = V_6 -> V_52 ;
if ( V_41 < V_46 )
V_46 = F_26 ( V_41 , V_7 -> V_53 ) ;
V_48 = F_27 ( V_46 ) ;
if ( ! V_48 )
return - V_54 ;
V_45 = V_41 > V_46 ? V_46 : V_41 ;
while ( V_41 ) {
F_29 () ;
if ( V_44 + V_45 >= V_6 -> V_52 )
V_45 = V_6 -> V_52 - V_44 ;
V_4 = F_33 ( V_48 , V_40 , V_45 ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
V_4 = F_34 ( V_7 , V_6 , V_43 , V_48 , V_44 , V_45 ) ;
if ( V_4 )
break;
V_44 += V_45 ;
if ( V_44 == V_6 -> V_52 ) {
V_43 += 1 ;
V_44 -= V_6 -> V_52 ;
}
V_41 -= V_45 ;
* V_42 += V_45 ;
V_40 += V_45 ;
V_45 = V_41 > V_46 ? V_46 : V_41 ;
}
F_17 ( V_48 ) ;
return V_4 ? V_4 : V_47 - V_41 ;
}
static T_2 F_35 ( struct V_19 * V_19 , const char T_3 * V_40 ,
T_4 V_41 , T_1 * V_42 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
if ( ! V_6 -> V_24 && ! V_6 -> V_25 )
return F_32 ( V_19 , V_40 , V_41 , V_42 ) ;
if ( V_6 -> V_24 )
V_4 = F_36 ( V_7 , V_6 , V_40 , V_41 ) ;
else
V_4 = F_37 ( V_7 , V_6 , V_40 , V_41 ) ;
if ( V_4 < 0 ) {
F_4 ( L_15 ,
V_41 , V_4 ) ;
return V_4 ;
}
if ( V_4 ) {
V_41 = V_4 ;
if ( V_6 -> V_25 ) {
F_6 ( V_2 , V_17 ) ;
return V_41 ;
}
V_4 = F_38 ( V_7 , V_6 -> V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_4 ) {
F_16 ( L_16 ,
V_6 -> V_12 , V_7 -> V_20 ) ;
V_6 -> V_51 = 1 ;
}
V_6 -> V_61 = 1 ;
F_39 ( V_7 , V_6 , V_62 ) ;
F_6 ( V_2 , V_17 ) ;
}
return V_41 ;
}
static long F_40 ( struct V_19 * V_19 , unsigned int V_63 ,
unsigned long V_64 )
{
int V_4 = 0 ;
struct V_1 * V_2 = V_19 -> V_23 ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_38 * V_7 = V_6 -> V_7 ;
void T_3 * V_65 = ( void T_3 * ) V_64 ;
switch ( V_63 ) {
case V_66 :
{
T_5 V_67 , V_68 ;
if ( ! F_41 ( V_69 ) ) {
V_4 = - V_57 ;
break;
}
V_4 = F_33 ( & V_67 , V_65 , sizeof( T_5 ) ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
if ( V_2 -> V_14 == V_16 ) {
V_4 = - V_60 ;
break;
}
V_68 = ( long long ) V_6 -> V_70 *
V_7 -> V_71 - V_6 -> V_72 ;
if ( V_67 < 0 || V_67 > V_68 ) {
V_4 = - V_34 ;
break;
}
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_42 ( V_7 , V_6 , V_67 ) ;
if ( V_67 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_73 :
{
struct V_74 V_75 ;
V_4 = F_33 ( & V_75 , V_65 ,
sizeof( struct V_74 ) ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
if ( V_2 -> V_14 == V_16 ||
V_6 -> V_58 == V_59 ) {
V_4 = - V_60 ;
break;
}
V_4 = - V_34 ;
if ( V_75 . V_43 < 0 || V_75 . V_43 >= V_6 -> V_70 ||
V_75 . V_67 < 0 || V_75 . V_43 >= V_6 -> V_52 )
break;
V_4 = F_1 ( V_2 ) ;
if ( V_4 < 0 )
break;
V_4 = F_43 ( V_7 , V_6 , & V_75 ) ;
if ( V_75 . V_67 == 0 )
F_6 ( V_2 , V_17 ) ;
break;
}
case V_76 :
{
T_6 V_43 ;
V_4 = F_44 ( V_43 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
if ( V_2 -> V_14 == V_16 ||
V_6 -> V_58 == V_59 ) {
V_4 = - V_60 ;
break;
}
if ( V_43 < 0 || V_43 >= V_6 -> V_70 ) {
V_4 = - V_34 ;
break;
}
F_11 ( L_17 , V_6 -> V_12 , V_43 ) ;
V_4 = F_45 ( V_7 , V_6 , V_43 ) ;
if ( V_4 )
break;
V_4 = F_46 ( V_7 , V_77 , V_77 ) ;
break;
}
case V_78 :
{
struct V_79 V_75 ;
V_4 = F_33 ( & V_75 , V_65 , sizeof( struct V_79 ) ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
V_4 = F_47 ( V_2 , V_75 . V_43 ) ;
break;
}
case V_80 :
{
T_6 V_43 ;
V_4 = F_44 ( V_43 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
V_4 = F_48 ( V_2 , V_43 ) ;
break;
}
case V_81 :
{
T_6 V_43 ;
V_4 = F_44 ( V_43 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
V_4 = F_49 ( V_2 , V_43 ) ;
break;
}
case V_82 :
{
struct V_83 V_75 ;
V_4 = F_33 ( & V_75 , V_65 ,
sizeof( struct V_83 ) ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
switch ( V_75 . V_84 ) {
case V_85 :
F_22 ( & V_7 -> V_86 ) ;
V_2 -> V_6 -> V_56 = ! ! V_75 . V_87 ;
F_24 ( & V_7 -> V_86 ) ;
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
static int F_50 ( const struct V_38 * V_7 ,
const struct V_89 * V_75 )
{
int V_90 , V_4 = - V_34 ;
if ( V_75 -> V_67 < 0 || V_75 -> V_91 < 0 || V_75 -> V_58 < 0 ||
V_75 -> V_92 < 0 )
goto V_93;
if ( ( V_75 -> V_12 < 0 || V_75 -> V_12 >= V_7 -> V_94 ) &&
V_75 -> V_12 != V_95 )
goto V_93;
if ( V_75 -> V_91 == 0 )
goto V_93;
if ( V_75 -> V_67 == 0 )
goto V_93;
if ( V_75 -> V_58 != V_96 &&
V_75 -> V_58 != V_59 )
goto V_93;
if ( V_75 -> V_91 > V_7 -> V_71 )
goto V_93;
V_90 = V_75 -> V_91 & ( V_7 -> V_53 - 1 ) ;
if ( V_75 -> V_91 != 1 && V_90 )
goto V_93;
if ( ! V_75 -> V_97 [ 0 ] || ! V_75 -> V_92 )
goto V_93;
if ( V_75 -> V_92 > V_98 ) {
V_4 = - V_99 ;
goto V_93;
}
V_90 = F_51 ( V_75 -> V_97 , V_75 -> V_92 + 1 ) ;
if ( V_90 != V_75 -> V_92 )
goto V_93;
return 0 ;
V_93:
F_4 ( L_18 ) ;
F_52 ( V_75 ) ;
return V_4 ;
}
static int F_53 ( const struct V_38 * V_7 ,
const struct V_100 * V_75 )
{
if ( V_75 -> V_67 <= 0 )
return - V_34 ;
if ( V_75 -> V_12 < 0 || V_75 -> V_12 >= V_7 -> V_94 )
return - V_34 ;
return 0 ;
}
static int F_54 ( struct V_38 * V_7 ,
struct V_101 * V_75 )
{
int V_102 , V_90 , V_4 ;
struct V_103 V_104 ;
struct V_105 * V_106 , * V_107 ;
if ( V_75 -> V_41 < 0 || V_75 -> V_41 > V_108 )
return - V_34 ;
if ( V_75 -> V_41 == 0 )
return 0 ;
for ( V_102 = 0 ; V_102 < V_75 -> V_41 ; V_102 ++ ) {
if ( V_75 -> V_109 [ V_102 ] . V_12 < 0 ||
V_75 -> V_109 [ V_102 ] . V_12 >= V_7 -> V_94 )
return - V_34 ;
if ( V_75 -> V_109 [ V_102 ] . V_92 < 0 )
return - V_34 ;
if ( V_75 -> V_109 [ V_102 ] . V_92 > V_98 )
return - V_99 ;
V_75 -> V_109 [ V_102 ] . V_97 [ V_75 -> V_109 [ V_102 ] . V_92 ] = '\0' ;
V_90 = strlen ( V_75 -> V_109 [ V_102 ] . V_97 ) ;
if ( V_90 != V_75 -> V_109 [ V_102 ] . V_92 )
V_4 = - V_34 ;
}
for ( V_102 = 0 ; V_102 < V_75 -> V_41 - 1 ; V_102 ++ ) {
for ( V_90 = V_102 + 1 ; V_90 < V_75 -> V_41 ; V_90 ++ ) {
if ( V_75 -> V_109 [ V_102 ] . V_12 == V_75 -> V_109 [ V_90 ] . V_12 ) {
F_4 ( L_19 ,
V_75 -> V_109 [ V_102 ] . V_12 ) ;
return - V_34 ;
}
if ( ! strcmp ( V_75 -> V_109 [ V_102 ] . V_97 , V_75 -> V_109 [ V_90 ] . V_97 ) ) {
F_4 ( L_20 ,
V_75 -> V_109 [ V_102 ] . V_97 ) ;
return - V_34 ;
}
}
}
F_55 ( & V_104 ) ;
for ( V_102 = 0 ; V_102 < V_75 -> V_41 ; V_102 ++ ) {
int V_12 = V_75 -> V_109 [ V_102 ] . V_12 ;
int V_92 = V_75 -> V_109 [ V_102 ] . V_92 ;
const char * V_97 = V_75 -> V_109 [ V_102 ] . V_97 ;
V_106 = F_56 ( sizeof( struct V_105 ) , V_110 ) ;
if ( ! V_106 ) {
V_4 = - V_54 ;
goto V_111;
}
V_106 -> V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_106 -> V_2 ) ) {
V_4 = F_14 ( V_106 -> V_2 ) ;
F_4 ( L_21 , V_12 , V_4 ) ;
F_57 ( V_106 ) ;
goto V_111;
}
if ( V_106 -> V_2 -> V_6 -> V_92 == V_92 &&
! memcmp ( V_106 -> V_2 -> V_6 -> V_97 , V_97 , V_92 ) ) {
F_18 ( V_106 -> V_2 ) ;
F_57 ( V_106 ) ;
continue;
}
V_106 -> V_112 = V_92 ;
memcpy ( V_106 -> V_113 , V_97 , V_92 ) ;
F_58 ( & V_106 -> V_114 , & V_104 ) ;
F_11 ( L_22 ,
V_12 , V_106 -> V_2 -> V_6 -> V_97 , V_97 ) ;
}
if ( F_59 ( & V_104 ) )
return 0 ;
F_60 (re, &rename_list, list) {
struct V_1 * V_2 ;
int V_115 = 0 ;
F_60 (re1, &rename_list, list) {
if ( V_106 -> V_112 == V_107 -> V_2 -> V_6 -> V_92 &&
! memcmp ( V_106 -> V_113 , V_107 -> V_2 -> V_6 -> V_97 ,
V_107 -> V_2 -> V_6 -> V_92 ) ) {
V_115 = 1 ;
break;
}
}
if ( V_115 )
continue;
V_2 = F_61 ( V_7 -> V_20 , V_106 -> V_113 ,
V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
if ( V_4 == - V_116 )
continue;
F_4 ( L_23 ,
V_106 -> V_113 , V_4 ) ;
goto V_111;
}
V_107 = F_56 ( sizeof( struct V_105 ) , V_110 ) ;
if ( ! V_107 ) {
V_4 = - V_54 ;
F_18 ( V_2 ) ;
goto V_111;
}
V_107 -> remove = 1 ;
V_107 -> V_2 = V_2 ;
F_62 ( & V_107 -> V_114 , & V_104 ) ;
F_11 ( L_24 ,
V_107 -> V_2 -> V_6 -> V_12 , V_107 -> V_2 -> V_6 -> V_97 ) ;
}
F_22 ( & V_7 -> V_86 ) ;
V_4 = F_63 ( V_7 , & V_104 ) ;
F_24 ( & V_7 -> V_86 ) ;
V_111:
F_64 (re, re1, &rename_list, list) {
F_18 ( V_106 -> V_2 ) ;
F_65 ( & V_106 -> V_114 ) ;
F_57 ( V_106 ) ;
}
return V_4 ;
}
static long F_66 ( struct V_19 * V_19 , unsigned int V_63 ,
unsigned long V_64 )
{
int V_4 = 0 ;
struct V_38 * V_7 ;
struct V_1 * V_2 ;
void T_3 * V_65 = ( void T_3 * ) V_64 ;
if ( ! F_41 ( V_69 ) )
return - V_57 ;
V_7 = F_67 ( F_10 ( V_19 -> V_117 -> V_118 ) ) ;
if ( ! V_7 )
return - V_116 ;
switch ( V_63 ) {
case V_119 :
{
struct V_89 V_75 ;
F_11 ( L_25 ) ;
V_4 = F_33 ( & V_75 , V_65 , sizeof( struct V_89 ) ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
V_4 = F_50 ( V_7 , & V_75 ) ;
if ( V_4 )
break;
F_22 ( & V_7 -> V_86 ) ;
V_4 = F_68 ( V_7 , & V_75 ) ;
F_24 ( & V_7 -> V_86 ) ;
if ( V_4 )
break;
V_4 = F_69 ( V_75 . V_12 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 )
V_4 = - V_55 ;
break;
}
case V_120 :
{
int V_12 ;
F_11 ( L_26 ) ;
V_4 = F_44 ( V_12 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
V_2 = F_12 ( V_7 -> V_20 , V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
F_22 ( & V_7 -> V_86 ) ;
V_4 = F_70 ( V_2 , 0 ) ;
F_24 ( & V_7 -> V_86 ) ;
F_18 ( V_2 ) ;
break;
}
case V_121 :
{
int V_122 ;
struct V_100 V_75 ;
F_11 ( L_27 ) ;
V_4 = F_33 ( & V_75 , V_65 , sizeof( struct V_100 ) ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
V_4 = F_53 ( V_7 , & V_75 ) ;
if ( V_4 )
break;
V_2 = F_12 ( V_7 -> V_20 , V_75 . V_12 , V_15 ) ;
if ( F_13 ( V_2 ) ) {
V_4 = F_14 ( V_2 ) ;
break;
}
V_122 = F_71 ( V_75 . V_67 + V_2 -> V_6 -> V_52 - 1 ,
V_2 -> V_6 -> V_52 ) ;
F_22 ( & V_7 -> V_86 ) ;
V_4 = F_72 ( V_2 , V_122 ) ;
F_24 ( & V_7 -> V_86 ) ;
F_18 ( V_2 ) ;
break;
}
case V_123 :
{
struct V_101 * V_75 ;
F_11 ( L_28 ) ;
V_75 = F_73 ( sizeof( struct V_101 ) , V_110 ) ;
if ( ! V_75 ) {
V_4 = - V_54 ;
break;
} ;
V_4 = F_33 ( V_75 , V_65 , sizeof( struct V_101 ) ) ;
if ( V_4 ) {
V_4 = - V_55 ;
F_57 ( V_75 ) ;
break;
}
V_4 = F_54 ( V_7 , V_75 ) ;
F_57 ( V_75 ) ;
break;
}
default:
V_4 = - V_88 ;
break;
}
F_74 ( V_7 ) ;
return V_4 ;
}
static long F_75 ( struct V_19 * V_19 , unsigned int V_63 ,
unsigned long V_64 )
{
int V_4 = 0 ;
void T_3 * V_65 = ( void T_3 * ) V_64 ;
if ( ! F_41 ( V_69 ) )
return - V_57 ;
switch ( V_63 ) {
case V_124 :
{
struct V_125 V_75 ;
struct V_126 * V_127 ;
F_11 ( L_29 ) ;
V_4 = F_33 ( & V_75 , V_65 , sizeof( struct V_125 ) ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
if ( V_75 . V_128 < 0 ||
( V_75 . V_20 < 0 && V_75 . V_20 != V_129 ) ) {
V_4 = - V_34 ;
break;
}
V_127 = F_76 ( NULL , V_75 . V_128 ) ;
if ( F_13 ( V_127 ) ) {
V_4 = F_14 ( V_127 ) ;
break;
}
F_22 ( & V_130 ) ;
V_4 = F_77 ( V_127 , V_75 . V_20 , V_75 . V_131 ,
V_75 . V_132 ) ;
F_24 ( & V_130 ) ;
if ( V_4 < 0 )
F_78 ( V_127 ) ;
else
V_4 = F_69 ( V_4 , ( T_3 T_6 * ) V_65 ) ;
break;
}
case V_133 :
{
int V_20 ;
F_11 ( L_30 ) ;
V_4 = F_44 ( V_20 , ( T_3 T_6 * ) V_65 ) ;
if ( V_4 ) {
V_4 = - V_55 ;
break;
}
F_22 ( & V_130 ) ;
V_4 = F_79 ( V_20 , 0 ) ;
F_24 ( & V_130 ) ;
break;
}
default:
V_4 = - V_88 ;
break;
}
return V_4 ;
}
static long F_80 ( struct V_19 * V_19 , unsigned int V_63 ,
unsigned long V_64 )
{
unsigned long V_134 = ( unsigned long ) F_81 ( V_64 ) ;
return F_40 ( V_19 , V_63 , V_134 ) ;
}
static long F_82 ( struct V_19 * V_19 , unsigned int V_63 ,
unsigned long V_64 )
{
unsigned long V_134 = ( unsigned long ) F_81 ( V_64 ) ;
return F_66 ( V_19 , V_63 , V_134 ) ;
}
static long F_83 ( struct V_19 * V_19 , unsigned int V_63 ,
unsigned long V_64 )
{
unsigned long V_134 = ( unsigned long ) F_81 ( V_64 ) ;
return F_75 ( V_19 , V_63 , V_134 ) ;
}

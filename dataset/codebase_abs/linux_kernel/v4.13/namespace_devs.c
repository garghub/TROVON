static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
if ( V_6 -> V_9 >= 0 )
F_7 ( & V_7 -> V_10 , V_6 -> V_9 ) ;
F_3 ( V_6 -> V_11 ) ;
F_3 ( V_6 -> V_12 ) ;
F_3 ( V_6 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_9 ( V_2 ) ;
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
if ( V_14 -> V_9 >= 0 )
F_7 ( & V_7 -> V_10 , V_14 -> V_9 ) ;
F_3 ( V_14 -> V_11 ) ;
F_3 ( V_14 -> V_12 ) ;
F_3 ( V_14 -> V_15 ) ;
F_3 ( V_14 ) ;
}
static bool F_10 ( const struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_16 : false ;
}
static bool F_11 ( const struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_17 : false ;
}
static bool F_12 ( const struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_18 : false ;
}
static int F_13 ( struct V_1 * V_2 , void * V_19 )
{
T_1 * V_20 = V_19 , * V_21 = NULL ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_21 = V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_21 = V_14 -> V_12 ;
} else if ( F_14 ( V_2 ) ) {
struct V_22 * V_22 = F_15 ( V_2 ) ;
V_21 = V_22 -> V_12 ;
} else if ( F_16 ( V_2 ) ) {
struct V_23 * V_23 = F_17 ( V_2 ) ;
V_21 = V_23 -> V_12 ;
}
if ( V_21 && memcmp ( V_20 , V_21 , V_24 ) == 0 )
return - V_25 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_19 )
{
if ( F_19 ( V_2 ) )
return F_20 ( V_2 , V_19 , F_13 ) ;
return 0 ;
}
bool F_21 ( struct V_1 * V_2 , T_1 * V_12 )
{
struct V_26 * V_26 = F_22 ( V_2 ) ;
if ( ! V_26 )
return false ;
F_23 ( ! F_24 ( & V_26 -> V_2 ) ) ;
if ( F_20 ( & V_26 -> V_2 , V_12 ,
F_18 ) != 0 )
return false ;
return true ;
}
bool F_25 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
struct V_3 * V_4 ;
if ( ! F_26 ( V_27 ) )
return false ;
if ( ! F_27 ( V_28 , & V_7 -> V_29 ) )
return false ;
if ( F_16 ( V_2 ) || F_14 ( V_2 ) )
return false ;
V_4 = F_2 ( V_2 ) ;
if ( F_28 ( V_4 -> V_15 . V_30 , F_29 ( & V_4 -> V_15 ) ,
V_31 ,
V_32 ) == V_33 )
return false ;
return V_34 == V_35 ;
}
unsigned int F_30 ( struct V_36 * V_37 )
{
if ( F_10 ( & V_37 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_37 -> V_2 ) ;
if ( V_6 -> V_38 == 0 || V_6 -> V_38 == 512 )
;
else if ( V_6 -> V_38 == 4096 )
return 4096 ;
else
F_31 ( & V_37 -> V_2 , L_1 ,
V_6 -> V_38 ) ;
}
return 512 ;
}
const char * F_32 ( struct V_36 * V_37 ,
char * V_39 )
{
struct V_7 * V_7 = F_6 ( V_37 -> V_2 . V_8 ) ;
const char * V_40 = NULL ;
if ( V_37 -> V_41 && F_14 ( V_37 -> V_41 ) )
V_40 = L_2 ;
if ( F_10 ( & V_37 -> V_2 ) || F_12 ( & V_37 -> V_2 ) ) {
int V_42 = 0 ;
if ( F_10 ( & V_37 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_37 -> V_2 ) ;
V_42 = V_6 -> V_9 ;
}
if ( V_42 )
sprintf ( V_39 , L_3 , V_7 -> V_9 , V_42 ,
V_40 ? V_40 : L_4 ) ;
else
sprintf ( V_39 , L_5 , V_7 -> V_9 ,
V_40 ? V_40 : L_4 ) ;
} else if ( F_11 ( & V_37 -> V_2 ) ) {
struct V_13 * V_14 ;
V_14 = F_9 ( & V_37 -> V_2 ) ;
sprintf ( V_39 , L_6 , V_7 -> V_9 , V_14 -> V_9 ,
V_40 ? V_40 : L_4 ) ;
} else {
return NULL ;
}
return V_39 ;
}
const T_1 * F_33 ( struct V_1 * V_2 )
{
static const T_1 V_43 [ 16 ] ;
if ( ! V_2 )
return V_43 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
return V_14 -> V_12 ;
} else
return V_43 ;
}
static T_2 F_34 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
return sprintf ( V_46 , L_7 , F_35 ( V_7 ) ) ;
}
static T_2 F_36 ( struct V_1 * V_2 , const char * V_46 ,
const T_3 V_47 )
{
char * V_48 , * V_49 , * V_11 , * * V_50 ;
T_2 V_51 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_50 = & V_6 -> V_11 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_50 = & V_14 -> V_11 ;
} else
return - V_52 ;
if ( V_2 -> V_53 || F_37 ( V_2 ) -> V_41 )
return - V_25 ;
V_48 = F_38 ( V_46 , V_47 + 1 , V_54 ) ;
if ( ! V_48 )
return - V_55 ;
V_48 [ V_47 ] = '\0' ;
V_49 = F_39 ( V_48 ) ;
if ( strlen ( V_49 ) + 1 > V_56 ) {
V_51 = - V_57 ;
goto V_58;
}
V_11 = F_40 ( V_56 , V_54 ) ;
if ( ! V_11 ) {
V_51 = - V_55 ;
goto V_58;
}
F_3 ( * V_50 ) ;
* V_50 = V_11 ;
sprintf ( * V_50 , L_8 , V_49 ) ;
V_51 = V_47 ;
V_58:
F_3 ( V_48 ) ;
return V_51 ;
}
static T_4 F_41 ( struct V_13 * V_14 )
{
struct V_7 * V_7 = F_6 ( V_14 -> V_59 . V_2 . V_8 ) ;
struct V_60 * V_60 = & V_7 -> V_61 [ 0 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_64 V_65 ;
T_4 V_66 = 0 ;
struct V_67 * V_15 ;
if ( ! V_14 -> V_12 )
return 0 ;
F_43 ( & V_65 , V_14 -> V_12 , V_68 ) ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_39 , V_65 . V_9 ) == 0 )
V_66 += F_29 ( V_15 ) ;
return V_66 ;
}
static bool F_45 ( struct V_13 * V_14 )
{
struct V_7 * V_7 = F_6 ( V_14 -> V_59 . V_2 . V_8 ) ;
struct V_60 * V_60 = & V_7 -> V_61 [ 0 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_64 V_65 ;
struct V_67 * V_15 ;
int V_69 , V_70 ;
if ( ! V_14 -> V_12 || ! V_14 -> V_38 || ! V_63 )
return false ;
V_69 = 0 ;
F_43 ( & V_65 , V_14 -> V_12 , V_68 ) ;
F_44 (ndd, res) {
if ( strcmp ( V_15 -> V_39 , V_65 . V_9 ) != 0 )
continue;
if ( V_15 -> V_29 & V_71 )
return false ;
V_69 ++ ;
}
if ( V_69 != V_14 -> V_72 )
return false ;
for ( V_70 = 0 ; V_70 < V_14 -> V_72 ; V_70 ++ ) {
struct V_67 * V_73 = NULL ;
F_44 (ndd, res)
if ( V_15 == V_14 -> V_15 [ V_70 ] ) {
V_73 = V_15 ;
break;
}
if ( ! V_73 )
return false ;
}
return true ;
}
T_4 F_46 ( struct V_13 * V_14 )
{
T_4 V_66 ;
F_47 ( & V_14 -> V_59 . V_2 ) ;
V_66 = F_45 ( V_14 ) ;
F_48 ( & V_14 -> V_59 . V_2 ) ;
return V_66 ;
}
static int F_49 ( struct V_7 * V_7 ,
struct V_1 * V_2 )
{
F_50 ( V_2 , V_2 -> V_53 || F_37 ( V_2 ) -> V_41 ,
L_9 ) ;
if ( V_2 -> V_53 || F_37 ( V_2 ) -> V_41 )
return 0 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_4 V_66 = F_29 ( & V_6 -> V_4 . V_15 ) ;
if ( V_66 == 0 && V_6 -> V_12 )
;
else if ( ! V_6 -> V_12 )
return 0 ;
return F_51 ( V_7 , V_6 , V_66 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
T_4 V_66 = F_41 ( V_14 ) ;
if ( V_66 == 0 && V_14 -> V_12 )
;
else if ( ! V_14 -> V_12 || ! V_14 -> V_38 )
return 0 ;
return F_52 ( V_7 , V_14 , V_66 ) ;
} else
return - V_52 ;
}
static T_2 F_53 ( struct V_1 * V_2 ,
struct V_44 * V_45 , const char * V_46 , T_3 V_47 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
T_2 V_51 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
V_51 = F_36 ( V_2 , V_46 , V_47 ) ;
if ( V_51 >= 0 )
V_51 = F_49 ( V_7 , V_2 ) ;
F_56 ( V_2 , L_10 , V_74 , V_51 < 0 ? L_11 : L_4 , V_51 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_51 < 0 ? V_51 : V_47 ;
}
static T_2 F_58 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
char * V_50 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_50 = V_6 -> V_11 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_50 = V_14 -> V_11 ;
} else
return - V_52 ;
return sprintf ( V_46 , L_12 , V_50 ? V_50 : L_4 ) ;
}
static int F_59 ( struct V_7 * V_7 ,
struct V_60 * V_60 , struct V_64 * V_65 ,
T_4 V_75 )
{
bool V_76 = strncmp ( V_65 -> V_9 , L_13 , 3 ) == 0 ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
int V_51 = 0 ;
while ( V_75 ) {
struct V_67 * V_15 , * V_77 ;
T_4 V_78 ;
V_77 = NULL ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_39 , V_65 -> V_9 ) == 0 )
V_77 = V_15 ;
V_15 = V_77 ;
if ( ! V_15 )
return 0 ;
if ( V_75 >= F_29 ( V_15 ) ) {
V_75 -= F_29 ( V_15 ) ;
F_60 ( V_7 , V_63 , V_15 , L_14 , V_51 ) ;
F_61 ( V_63 , V_15 ) ;
continue;
}
if ( V_76 )
V_78 = V_15 -> V_30 + V_75 ;
else
V_78 = V_15 -> V_30 ;
V_51 = F_62 ( V_15 , V_78 , F_29 ( V_15 ) - V_75 ) ;
if ( V_51 == 0 )
V_15 -> V_29 |= V_71 ;
F_60 ( V_7 , V_63 , V_15 , L_15 , V_51 ) ;
break;
}
return V_51 ;
}
static int F_63 ( struct V_7 * V_7 ,
struct V_64 * V_65 , T_4 V_75 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
int V_51 ;
V_51 = F_59 ( V_7 , V_60 , V_65 , V_75 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static T_4 F_64 ( struct V_64 * V_65 ,
struct V_7 * V_7 , struct V_60 * V_60 ,
T_4 V_75 )
{
bool V_76 = strncmp ( V_65 -> V_9 , L_13 , 3 ) == 0 ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
T_4 V_80 ;
struct V_67 * V_15 ;
int V_51 = 0 ;
if ( V_76 )
V_80 = V_60 -> V_30 + V_60 -> V_66 - V_75 ;
else
V_80 = V_60 -> V_30 ;
V_15 = F_65 ( V_63 , V_65 , V_80 , V_75 ) ;
if ( ! V_15 )
V_51 = - V_25 ;
F_60 ( V_7 , V_63 , V_15 , L_16 , V_51 ) ;
return V_51 ? V_75 : 0 ;
}
static void F_66 ( struct V_7 * V_7 , struct V_62 * V_63 ,
struct V_64 * V_65 , struct V_67 * V_81 ,
struct V_67 * V_82 , struct V_67 * V_83 ,
T_4 V_75 , struct V_67 * V_84 )
{
bool V_85 = strcmp ( V_65 -> V_9 , L_17 ) == 0 ;
bool V_86 = strncmp ( V_65 -> V_9 , L_18 , 4 ) == 0 ;
if ( V_84 -> V_30 >= V_84 -> V_87 )
goto V_88;
if ( V_85 )
return;
if ( ! V_86 ) {
struct V_60 * V_60 = & V_7 -> V_61 [ 0 ] ;
struct V_26 * V_26 ;
struct V_89 V_90 = {
. V_60 = V_60 ,
. V_91 = V_60 -> V_66 ,
. V_15 = V_84 ,
} ;
F_67 ( ! F_68 ( & V_7 -> V_2 ) ) ;
V_26 = F_22 ( & V_7 -> V_2 ) ;
F_20 ( & V_26 -> V_2 , & V_90 , V_92 ) ;
return;
}
if ( F_29 ( V_84 ) < V_75 )
goto V_88;
if ( ! V_83 )
return;
if ( V_84 -> V_30 == V_83 -> V_87 + 1
|| V_84 -> V_87 == V_83 -> V_30 - 1 )
return;
V_88:
V_84 -> V_87 = V_84 -> V_30 - 1 ;
}
static T_4 F_69 ( struct V_7 * V_7 ,
struct V_60 * V_60 , struct V_64 * V_65 ,
T_4 V_75 )
{
T_4 V_93 = V_60 -> V_30 + V_60 -> V_66 - 1 ;
bool V_86 = strncmp ( V_65 -> V_9 , L_18 , 4 ) == 0 ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_67 * V_15 , * V_83 = NULL , V_84 ;
const T_4 V_94 = V_75 ;
int V_95 ;
F_44 (ndd, res)
if ( strcmp ( V_65 -> V_9 , V_15 -> V_39 ) == 0 )
V_83 = V_15 ;
V_84 . V_30 = V_60 -> V_30 ;
V_84 . V_87 = V_93 ;
V_84 . V_39 = L_19 ;
V_96:
V_95 = 0 ;
F_44 (ndd, res) {
struct V_67 * V_82 = V_15 -> V_97 , * V_98 = NULL ;
T_4 V_99 , V_91 = 0 ;
enum V_100 V_101 = V_102 ;
const char * V_103 ;
int V_51 = 0 ;
if ( V_15 -> V_30 > V_93 )
continue;
if ( V_15 -> V_87 < V_60 -> V_30 )
continue;
if ( ! V_95 ++ && V_15 -> V_30 > V_60 -> V_30 ) {
V_84 . V_30 = V_60 -> V_30 ;
V_84 . V_87 = V_15 -> V_30 - 1 ;
F_66 ( V_7 , V_63 , V_65 , NULL , V_82 , V_83 ,
V_94 , & V_84 ) ;
V_91 = F_29 ( & V_84 ) ;
if ( V_91 )
V_101 = V_104 ;
}
if ( ! V_101 && V_82 ) {
V_84 . V_30 = V_15 -> V_30 + F_29 ( V_15 ) ;
V_84 . V_87 = F_70 ( V_93 , V_82 -> V_30 - 1 ) ;
F_66 ( V_7 , V_63 , V_65 , V_15 , V_82 , V_83 ,
V_94 , & V_84 ) ;
V_91 = F_29 ( & V_84 ) ;
if ( V_91 )
V_101 = V_105 ;
}
if ( ! V_101 && ! V_82 ) {
V_84 . V_30 = V_15 -> V_30 + F_29 ( V_15 ) ;
V_84 . V_87 = V_93 ;
F_66 ( V_7 , V_63 , V_65 , V_15 , V_82 , V_83 ,
V_94 , & V_84 ) ;
V_91 = F_29 ( & V_84 ) ;
if ( V_91 )
V_101 = V_106 ;
}
if ( ! V_101 || ! V_91 )
continue;
V_99 = F_70 ( V_91 , V_75 ) ;
switch ( V_101 ) {
case V_104 :
if ( strcmp ( V_15 -> V_39 , V_65 -> V_9 ) == 0 ) {
V_51 = F_62 ( V_15 , V_15 -> V_30 - V_99 ,
F_29 ( V_15 ) + V_99 ) ;
V_103 = L_20 ;
} else
V_103 = L_21 ;
break;
case V_105 :
if ( strcmp ( V_82 -> V_39 , V_65 -> V_9 ) == 0 ) {
V_51 = F_62 ( V_82 , V_82 -> V_30
- V_99 , F_29 ( V_82 )
+ V_99 ) ;
V_98 = V_82 ;
V_103 = L_22 ;
} else if ( strcmp ( V_15 -> V_39 , V_65 -> V_9 ) == 0 ) {
V_103 = L_23 ;
} else
V_103 = L_21 ;
break;
case V_106 :
if ( strcmp ( V_15 -> V_39 , V_65 -> V_9 ) == 0 )
V_103 = L_23 ;
else
V_103 = L_21 ;
break;
default:
return V_75 ;
}
if ( strcmp ( V_103 , L_21 ) == 0 ) {
if ( ! V_86 )
V_84 . V_30 += V_91 - V_99 ;
V_98 = F_65 ( V_63 , V_65 ,
V_84 . V_30 , V_99 ) ;
if ( ! V_98 )
V_51 = - V_25 ;
} else if ( strcmp ( V_103 , L_23 ) == 0 ) {
V_51 = F_62 ( V_15 , V_15 -> V_30 , F_29 ( V_15 )
+ V_99 ) ;
if ( V_51 == 0 )
V_15 -> V_29 |= V_71 ;
}
if ( ! V_98 )
V_98 = V_15 ;
F_60 ( V_7 , V_63 , V_98 , L_24 ,
V_103 , V_101 , V_51 ) ;
if ( V_51 )
return V_75 ;
V_75 -= V_99 ;
if ( V_75 ) {
goto V_96;
} else
return 0 ;
}
if ( ( V_86 || ! V_63 -> V_107 . V_108 ) && V_75 == V_94 )
return F_64 ( V_65 , V_7 , V_60 , V_75 ) ;
return V_75 ;
}
static int F_71 ( struct V_7 * V_7 ,
struct V_60 * V_60 , struct V_64 * V_65 )
{
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_67 * V_15 ;
if ( strncmp ( L_18 , V_65 -> V_9 , 4 ) == 0 )
return 0 ;
V_96:
F_44 (ndd, res) {
int V_51 ;
struct V_67 * V_82 = V_15 -> V_97 ;
T_4 V_87 = V_15 -> V_30 + F_29 ( V_15 ) ;
if ( ! V_82 || strcmp ( V_15 -> V_39 , V_65 -> V_9 ) != 0
|| strcmp ( V_82 -> V_39 , V_65 -> V_9 ) != 0
|| V_87 != V_82 -> V_30 )
continue;
V_87 += F_29 ( V_82 ) ;
F_61 ( V_63 , V_82 ) ;
V_51 = F_62 ( V_15 , V_15 -> V_30 , V_87 - V_15 -> V_30 ) ;
F_60 ( V_7 , V_63 , V_15 , L_25 , V_51 ) ;
if ( V_51 )
return V_51 ;
V_15 -> V_29 |= V_71 ;
goto V_96;
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 , void * V_19 )
{
struct V_109 * V_109 = V_19 ;
struct V_7 * V_7 ;
struct V_64 V_65 ;
int V_70 ;
if ( ! F_73 ( V_2 ) )
return 0 ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 -> V_79 == 0 )
return 0 ;
memset ( & V_65 , 0 , sizeof( V_65 ) ) ;
strcat ( V_65 . V_9 , L_17 ) ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
T_4 V_75 , V_110 = 0 ;
if ( V_60 -> V_109 != V_109 )
continue;
V_75 = F_74 ( V_7 , V_60 , & V_110 ) ;
if ( V_75 == 0 )
return 0 ;
V_110 = F_69 ( V_7 , V_60 , & V_65 , V_75 ) ;
F_50 ( & V_7 -> V_2 , V_110 ,
L_26 ,
( unsigned long long ) V_75 - V_110 ,
( unsigned long long ) V_75 ) ;
return V_110 ? - V_52 : 0 ;
}
return 0 ;
}
static void F_75 ( struct V_26 * V_26 ,
struct V_60 * V_60 )
{
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_67 * V_15 , * V_111 ;
F_76 (ndd, res, _res)
if ( strcmp ( V_15 -> V_39 , L_17 ) == 0 )
F_61 ( V_63 , V_15 ) ;
}
static int F_77 ( struct V_26 * V_26 ,
struct V_60 * V_60 )
{
struct V_109 * V_109 = V_60 -> V_109 ;
int V_51 ;
V_51 = F_20 ( & V_26 -> V_2 , V_109 ,
F_72 ) ;
if ( V_51 )
F_75 ( V_26 , V_60 ) ;
return V_51 ;
}
static int F_78 ( struct V_7 * V_7 ,
struct V_64 * V_65 , T_4 V_75 )
{
struct V_26 * V_26 = F_22 ( & V_7 -> V_2 ) ;
bool V_86 = strncmp ( V_65 -> V_9 , L_18 , 4 ) == 0 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
T_4 V_110 = V_75 ;
int V_51 , V_112 ;
for ( V_112 = V_86 ; V_112 < 2 ; V_112 ++ ) {
bool V_113 = V_112 == 0 ;
if ( V_113 ) {
V_51 = F_77 ( V_26 , V_60 ) ;
if ( V_51 )
return V_51 ;
}
V_110 = F_69 ( V_7 , V_60 ,
V_65 , V_110 ) ;
if ( V_113 )
F_75 ( V_26 , V_60 ) ;
if ( V_110 == 0 )
break;
}
F_50 ( & V_7 -> V_2 , V_110 ,
L_27 ,
( unsigned long long ) V_75 - V_110 ,
( unsigned long long ) V_75 ) ;
if ( V_110 )
return - V_52 ;
V_51 = F_71 ( V_7 , V_60 , V_65 ) ;
if ( V_51 )
return V_51 ;
}
return 0 ;
}
static void F_79 ( struct V_7 * V_7 ,
struct V_5 * V_6 , T_4 V_66 )
{
struct V_67 * V_15 = & V_6 -> V_4 . V_15 ;
T_4 V_114 = 0 ;
if ( V_66 && ! V_6 -> V_12 ) {
F_23 ( 1 ) ;
V_66 = 0 ;
}
if ( V_66 && V_6 -> V_12 ) {
struct V_60 * V_60 = & V_7 -> V_61 [ 0 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_64 V_65 ;
struct V_67 * V_15 ;
if ( ! V_63 ) {
V_66 = 0 ;
goto V_58;
}
F_43 ( & V_65 , V_6 -> V_12 , 0 ) ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_39 , V_65 . V_9 ) == 0 ) {
V_114 = ( V_15 -> V_30 - V_60 -> V_30 )
* V_7 -> V_79 ;
goto V_58;
}
F_23 ( 1 ) ;
V_66 = 0 ;
}
V_58:
V_15 -> V_30 = V_7 -> V_115 + V_114 ;
V_15 -> V_87 = V_15 -> V_30 + V_66 - 1 ;
}
static bool F_80 ( const T_1 * V_12 , struct V_1 * V_2 , const char * V_116 )
{
if ( ! V_12 ) {
F_56 ( V_2 , L_28 , V_116 ) ;
return true ;
}
return false ;
}
static T_2 F_81 ( struct V_1 * V_2 , unsigned long long V_117 )
{
T_4 V_118 = 0 , V_91 = 0 ;
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
struct V_36 * V_37 = F_37 ( V_2 ) ;
struct V_60 * V_60 ;
struct V_62 * V_63 ;
struct V_64 V_65 ;
T_5 V_29 = 0 , V_119 ;
int V_51 , V_70 , V_9 = - 1 ;
T_1 * V_12 = NULL ;
if ( V_2 -> V_53 || V_37 -> V_41 )
return - V_25 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_12 = V_6 -> V_12 ;
V_9 = V_6 -> V_9 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_12 = V_14 -> V_12 ;
V_29 = V_68 ;
V_9 = V_14 -> V_9 ;
}
if ( F_80 ( V_12 , V_2 , V_74 ) )
return - V_52 ;
if ( V_7 -> V_79 == 0 ) {
F_56 ( V_2 , L_29 , V_74 ) ;
return - V_52 ;
}
F_82 ( V_117 , V_120 * V_7 -> V_79 , & V_119 ) ;
if ( V_119 ) {
F_56 ( V_2 , L_30 , V_117 ,
( V_120 * V_7 -> V_79 ) / V_121 ) ;
return - V_57 ;
}
F_43 ( & V_65 , V_12 , V_29 ) ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
V_60 = & V_7 -> V_61 [ V_70 ] ;
V_63 = F_42 ( V_60 ) ;
if ( ! V_63 )
return - V_52 ;
V_118 += F_83 ( V_63 , & V_65 ) ;
}
V_91 = F_84 ( V_7 ) ;
if ( V_117 > V_91 + V_118 )
return - V_122 ;
if ( V_117 == V_118 )
return 0 ;
V_117 = F_85 ( V_117 , V_7 -> V_79 ) ;
V_118 = F_85 ( V_118 , V_7 -> V_79 ) ;
if ( V_117 < V_118 )
V_51 = F_63 ( V_7 , & V_65 ,
V_118 - V_117 ) ;
else
V_51 = F_78 ( V_7 , & V_65 , V_117 - V_118 ) ;
if ( V_51 )
return V_51 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_79 ( V_7 , V_6 ,
V_117 * V_7 -> V_79 ) ;
}
if ( V_117 == 0 && V_9 != 0 && V_7 -> V_123 != V_2 && ! V_37 -> V_41 )
F_86 ( V_2 , V_124 ) ;
return V_51 ;
}
static T_2 F_87 ( struct V_1 * V_2 ,
struct V_44 * V_45 , const char * V_46 , T_3 V_47 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
unsigned long long V_117 ;
T_1 * * V_12 = NULL ;
int V_51 ;
V_51 = F_88 ( V_46 , 0 , & V_117 ) ;
if ( V_51 )
return V_51 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
V_51 = F_81 ( V_2 , V_117 ) ;
if ( V_51 >= 0 )
V_51 = F_49 ( V_7 , V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_12 = & V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_12 = & V_14 -> V_12 ;
}
if ( V_51 == 0 && V_117 == 0 && V_12 ) {
F_3 ( * V_12 ) ;
* V_12 = NULL ;
}
F_56 ( V_2 , L_31 , V_74 , V_117 , V_51 < 0
? L_32 : L_33 , V_51 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_51 < 0 ? V_51 : V_47 ;
}
T_4 F_89 ( struct V_36 * V_37 )
{
struct V_1 * V_2 = & V_37 -> V_2 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return F_29 ( & V_6 -> V_4 . V_15 ) ;
} else if ( F_11 ( V_2 ) ) {
return F_41 ( F_9 ( V_2 ) ) ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_29 ( & V_4 -> V_15 ) ;
} else
F_90 ( 1 , L_34 ) ;
return 0 ;
}
T_4 F_91 ( struct V_36 * V_37 )
{
T_4 V_66 ;
F_47 ( & V_37 -> V_2 ) ;
V_66 = F_89 ( V_37 ) ;
F_48 ( & V_37 -> V_2 ) ;
return V_66 ;
}
static T_2 F_92 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_35 , ( unsigned long long )
F_91 ( F_37 ( V_2 ) ) ) ;
}
static T_1 * F_93 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
return V_14 -> V_12 ;
} else
return F_94 ( - V_52 ) ;
}
static T_2 F_95 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
T_1 * V_12 = F_93 ( V_2 ) ;
if ( F_96 ( V_12 ) )
return F_97 ( V_12 ) ;
if ( V_12 )
return sprintf ( V_46 , L_36 , V_12 ) ;
return sprintf ( V_46 , L_37 ) ;
}
static int F_98 ( struct V_7 * V_7 ,
struct V_1 * V_2 , T_1 * V_125 , T_1 * * V_126 )
{
T_5 V_29 = F_11 ( V_2 ) ? V_68 : 0 ;
struct V_64 V_127 ;
struct V_64 V_128 ;
int V_70 ;
if ( ! F_21 ( V_2 , V_125 ) )
return - V_57 ;
if ( * V_126 == NULL )
goto V_58;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
if ( F_99 ( & V_60 -> V_129 ) )
return - V_25 ;
}
F_43 ( & V_127 , * V_126 , V_29 ) ;
F_43 ( & V_128 , V_125 , V_29 ) ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_67 * V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_39 , V_127 . V_9 ) == 0 )
sprintf ( ( void * ) V_15 -> V_39 , L_8 ,
V_128 . V_9 ) ;
}
F_3 ( * V_126 ) ;
V_58:
* V_126 = V_125 ;
return 0 ;
}
static T_2 F_100 ( struct V_1 * V_2 ,
struct V_44 * V_45 , const char * V_46 , T_3 V_47 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
T_1 * V_12 = NULL ;
T_2 V_51 = 0 ;
T_1 * * V_130 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_130 = & V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_130 = & V_14 -> V_12 ;
} else
return - V_52 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( F_37 ( V_2 ) -> V_41 )
V_51 = - V_25 ;
if ( V_51 >= 0 )
V_51 = F_101 ( V_2 , & V_12 , V_46 , V_47 ) ;
if ( V_51 >= 0 )
V_51 = F_98 ( V_7 , V_2 , V_12 , V_130 ) ;
if ( V_51 >= 0 )
V_51 = F_49 ( V_7 , V_2 ) ;
else
F_3 ( V_12 ) ;
F_56 ( V_2 , L_38 , V_74 ,
V_51 , V_46 , V_46 [ V_47 - 1 ] == '\n' ? L_4 : L_37 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_51 < 0 ? V_51 : V_47 ;
}
static T_2 F_102 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_67 * V_15 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_15 = & V_6 -> V_4 . V_15 ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 = & V_4 -> V_15 ;
} else
return - V_52 ;
if ( F_29 ( V_15 ) == 0 )
return - V_52 ;
return sprintf ( V_46 , L_39 , ( unsigned long long ) V_15 -> V_30 ) ;
}
static T_2 F_103 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
return F_104 ( V_14 -> V_38 ,
V_131 , V_46 ) ;
}
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return F_104 ( V_6 -> V_38 ,
V_132 , V_46 ) ;
}
return - V_52 ;
}
static T_2 F_105 ( struct V_1 * V_2 ,
struct V_44 * V_45 , const char * V_46 , T_3 V_47 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
const unsigned long * V_133 ;
unsigned long * V_38 ;
T_2 V_51 = 0 ;
if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_38 = & V_14 -> V_38 ;
V_133 = V_131 ;
} else if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_38 = & V_6 -> V_38 ;
V_133 = V_132 ;
} else
return - V_52 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( F_37 ( V_2 ) -> V_41 )
V_51 = - V_25 ;
if ( V_51 >= 0 )
V_51 = F_106 ( V_2 , V_46 , V_38 , V_133 ) ;
if ( V_51 >= 0 )
V_51 = F_49 ( V_7 , V_2 ) ;
F_56 ( V_2 , L_40 , V_74 ,
V_51 , V_51 < 0 ? L_41 : L_42 , V_46 ,
V_46 [ V_47 - 1 ] == '\n' ? L_4 : L_37 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_51 ? V_51 : V_47 ;
}
static T_2 F_107 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
struct V_64 V_65 ;
int V_69 = 0 , V_70 ;
T_1 * V_12 = NULL ;
T_5 V_29 = 0 ;
F_47 ( V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_12 = V_6 -> V_12 ;
V_29 = 0 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_12 = V_14 -> V_12 ;
V_29 = V_68 ;
}
if ( ! V_12 )
goto V_58;
F_43 ( & V_65 , V_12 , V_29 ) ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_67 * V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_39 , V_65 . V_9 ) == 0 )
V_69 ++ ;
}
V_58:
F_48 ( V_2 ) ;
return sprintf ( V_46 , L_7 , V_69 ) ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
int V_70 , V_134 = 0 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_135 * V_136 ;
V_136 = F_109 ( V_63 , V_63 -> V_137 ) ;
if ( V_136 == NULL )
V_134 |= 1 ;
else {
if ( F_110 ( V_136 -> V_138 ) == 1
&& F_110 ( V_136 -> V_139 ) == 1 )
V_134 |= 2 ;
else
V_134 |= 4 ;
}
}
switch ( V_134 ) {
case 0 :
case 2 :
return V_140 ;
case 1 :
case 4 :
return V_141 ;
default:
return - V_52 ;
}
}
static T_2 F_111 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_36 * V_37 = F_37 ( V_2 ) ;
T_2 V_51 ;
F_54 ( V_2 ) ;
V_51 = sprintf ( V_46 , L_12 , V_37 -> V_41 ? F_112 ( V_37 -> V_41 ) : L_4 ) ;
F_57 ( V_2 ) ;
return V_51 ;
}
static T_2 F_113 ( struct V_1 * V_2 , const char * V_46 )
{
struct V_36 * V_37 = F_37 ( V_2 ) ;
if ( V_2 -> V_53 || V_37 -> V_41 )
return - V_25 ;
if ( strcmp ( V_46 , L_43 ) == 0 || strcmp ( V_46 , L_44 ) == 0 )
V_37 -> V_142 = F_108 ( V_2 ) ;
else if ( strcmp ( V_46 , L_45 ) == 0 || strcmp ( V_46 , L_46 ) == 0 )
V_37 -> V_142 = V_143 ;
else if ( strcmp ( V_46 , L_47 ) == 0 || strcmp ( V_46 , L_48 ) == 0 )
V_37 -> V_142 = V_144 ;
else if ( strcmp ( V_46 , L_4 ) == 0 || strcmp ( V_46 , L_37 ) == 0 )
V_37 -> V_142 = V_145 ;
else
return - V_57 ;
if ( V_37 -> V_142 < 0 )
return V_37 -> V_142 ;
return 0 ;
}
static T_2 F_114 ( struct V_1 * V_2 ,
struct V_44 * V_45 , const char * V_46 , T_3 V_47 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
T_2 V_51 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
V_51 = F_113 ( V_2 , V_46 ) ;
if ( V_51 >= 0 )
V_51 = F_49 ( V_7 , V_2 ) ;
F_56 ( V_2 , L_10 , V_74 , V_51 < 0 ? L_11 : L_4 , V_51 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_51 < 0 ? V_51 : V_47 ;
}
static T_2 F_115 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_36 * V_37 = F_37 ( V_2 ) ;
T_2 V_51 ;
F_54 ( V_2 ) ;
if ( V_37 -> V_142 == V_145 )
V_51 = sprintf ( V_46 , L_37 ) ;
else if ( ( V_37 -> V_142 == V_140 ) ||
( V_37 -> V_142 == V_141 ) )
V_51 = sprintf ( V_46 , L_44 ) ;
else if ( V_37 -> V_142 == V_143 )
V_51 = sprintf ( V_46 , L_46 ) ;
else if ( V_37 -> V_142 == V_144 )
V_51 = sprintf ( V_46 , L_48 ) ;
else
V_51 = sprintf ( V_46 , L_49 ) ;
F_57 ( V_2 ) ;
return V_51 ;
}
static T_2 F_116 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
struct V_36 * V_37 = F_37 ( V_2 ) ;
struct V_1 * V_41 ;
char * V_146 ;
T_2 V_51 ;
F_54 ( V_2 ) ;
V_41 = V_37 -> V_41 ;
if ( V_41 && F_14 ( V_41 ) )
V_146 = L_50 ;
else if ( V_41 && F_16 ( V_41 ) )
V_146 = L_51 ;
else if ( V_41 && F_117 ( V_41 ) )
V_146 = L_47 ;
else if ( ! V_41 && F_25 ( V_2 ) )
V_146 = L_51 ;
else
V_146 = L_52 ;
V_51 = sprintf ( V_46 , L_12 , V_146 ) ;
F_57 ( V_2 ) ;
return V_51 ;
}
static T_2 F_118 ( struct V_1 * V_2 ,
struct V_44 * V_45 , const char * V_46 , T_3 V_47 )
{
bool V_147 ;
int V_51 = F_119 ( V_46 , & V_147 ) ;
if ( V_51 )
return V_51 ;
F_37 ( V_2 ) -> V_147 = V_147 ;
return V_47 ;
}
static T_2 F_120 ( struct V_1 * V_2 ,
struct V_44 * V_45 , char * V_46 )
{
return sprintf ( V_46 , L_7 , F_37 ( V_2 ) -> V_147 ) ;
}
static T_6 F_121 ( struct V_148 * V_149 ,
struct V_150 * V_151 , int V_75 )
{
struct V_1 * V_2 = F_122 ( V_149 , struct V_1 , V_149 ) ;
if ( V_151 == & V_152 . V_45 ) {
if ( F_11 ( V_2 ) )
return 0 ;
return V_151 -> V_146 ;
}
if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
if ( V_151 == & V_153 . V_45 )
return 0644 ;
return V_151 -> V_146 ;
}
if ( V_151 == & V_154 . V_45 || V_151 == & V_153 . V_45
|| V_151 == & V_155 . V_45
|| V_151 == & V_156 . V_45
|| V_151 == & V_157 . V_45
|| V_151 == & V_158 . V_45 )
return V_151 -> V_146 ;
return 0 ;
}
struct V_36 * F_123 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_14 ( V_2 ) ? F_15 ( V_2 ) : NULL ;
struct V_23 * V_23 = F_16 ( V_2 ) ? F_17 ( V_2 ) : NULL ;
struct V_159 * V_159 = F_117 ( V_2 ) ? F_124 ( V_2 ) : NULL ;
struct V_36 * V_37 = NULL ;
T_4 V_66 ;
if ( V_22 || V_23 || V_159 ) {
if ( V_22 )
V_37 = V_22 -> V_37 ;
else if ( V_23 )
V_37 = V_23 -> V_37 ;
else if ( V_159 )
V_37 = V_159 -> V_23 . V_37 ;
if ( ! V_37 )
return F_94 ( - V_160 ) ;
F_54 ( & V_37 -> V_2 ) ;
F_57 ( & V_37 -> V_2 ) ;
if ( V_37 -> V_2 . V_53 ) {
F_56 ( & V_37 -> V_2 , L_53 ,
F_112 ( V_2 ) ) ;
return F_94 ( - V_25 ) ;
}
if ( F_50 ( & V_37 -> V_2 , V_37 -> V_41 != V_2 ,
L_54 ,
F_112 ( V_2 ) ,
F_112 ( V_37 -> V_41 ) ) )
return F_94 ( - V_52 ) ;
} else {
V_37 = F_37 ( V_2 ) ;
if ( V_37 -> V_41 ) {
F_56 ( V_2 , L_55 ,
F_112 ( V_37 -> V_41 ) ) ;
return F_94 ( - V_52 ) ;
}
}
V_66 = F_91 ( V_37 ) ;
if ( V_66 < V_161 ) {
F_56 ( & V_37 -> V_2 , L_56 ,
& V_66 , V_161 ) ;
return F_94 ( - V_160 ) ;
}
if ( F_10 ( & V_37 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_37 -> V_2 ) ;
if ( F_80 ( V_6 -> V_12 , & V_37 -> V_2 , V_74 ) )
return F_94 ( - V_160 ) ;
} else if ( F_11 ( & V_37 -> V_2 ) ) {
struct V_13 * V_14 ;
V_14 = F_9 ( & V_37 -> V_2 ) ;
if ( F_80 ( V_14 -> V_12 , & V_37 -> V_2 , V_74 ) )
return F_94 ( - V_160 ) ;
if ( ! V_14 -> V_38 ) {
F_56 ( & V_37 -> V_2 , L_57 ,
V_74 ) ;
return F_94 ( - V_160 ) ;
}
if ( ! F_46 ( V_14 ) )
return F_94 ( - V_160 ) ;
}
return V_37 ;
}
static struct V_1 * * F_125 ( struct V_7 * V_7 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 , * * V_162 ;
struct V_67 * V_15 ;
V_4 = F_40 ( sizeof( * V_4 ) , V_54 ) ;
if ( ! V_4 )
return NULL ;
V_162 = F_126 ( 2 , sizeof( struct V_1 * ) , V_54 ) ;
if ( ! V_162 ) {
F_3 ( V_4 ) ;
return NULL ;
}
V_2 = & V_4 -> V_59 . V_2 ;
V_2 -> type = & V_18 ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_15 = & V_4 -> V_15 ;
V_15 -> V_39 = F_112 ( & V_7 -> V_2 ) ;
V_15 -> V_29 = V_163 ;
V_15 -> V_30 = V_7 -> V_115 ;
V_15 -> V_87 = V_15 -> V_30 + V_7 -> V_164 - 1 ;
V_162 [ 0 ] = V_2 ;
return V_162 ;
}
static bool F_127 ( struct V_7 * V_7 , T_1 * V_12 ,
T_7 V_165 , T_8 V_49 )
{
struct V_166 * V_73 = NULL ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
struct V_167 * V_168 = V_7 -> V_168 ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_169 * V_170 ;
bool V_171 = false ;
F_128 (label_ent, &nd_mapping->labels, list) {
struct V_166 * V_172 = V_170 -> V_173 ;
T_8 V_174 , V_175 ;
T_7 V_176 ;
if ( ! V_172 )
continue;
V_176 = F_129 ( V_172 -> V_176 ) ;
V_174 = F_110 ( V_172 -> V_174 ) ;
V_175 = F_110 ( V_172 -> V_175 ) ;
if ( V_176 != V_165 )
continue;
if ( memcmp ( V_172 -> V_12 , V_12 , V_24 ) != 0 )
continue;
if ( F_130 ( V_63 , V_177 )
&& ! F_131 ( & V_168 -> V_177 ,
& V_172 -> V_177 ) ) {
F_56 ( V_63 -> V_2 , L_58 ,
V_168 -> V_177 . V_178 ,
V_172 -> V_177 . V_178 ) ;
continue;
}
if ( V_171 ) {
F_56 ( V_63 -> V_2 ,
L_59 ,
V_74 ) ;
return false ;
}
V_171 = true ;
if ( V_175 != V_7 -> V_79 )
continue;
if ( V_174 != V_49 )
continue;
V_73 = V_172 ;
break;
}
if ( V_73 )
break;
}
return V_73 != NULL ;
}
static int F_132 ( struct V_7 * V_7 , T_1 * V_179 )
{
int V_70 ;
if ( ! V_179 )
return - V_160 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_166 * V_172 = NULL ;
T_7 V_180 , V_181 , V_182 , V_183 ;
struct V_169 * V_170 ;
F_133 ( & V_60 -> V_184 ) ;
F_128 (label_ent, &nd_mapping->labels, list) {
V_172 = V_170 -> V_173 ;
if ( ! V_172 )
continue;
if ( memcmp ( V_172 -> V_12 , V_179 , V_24 ) == 0 )
break;
V_172 = NULL ;
}
if ( ! V_172 ) {
F_67 ( 1 ) ;
return - V_57 ;
}
V_180 = V_60 -> V_30 ;
V_181 = V_180 + V_60 -> V_66 ;
V_182 = F_129 ( V_172 -> V_107 ) ;
V_183 = V_182 + F_129 ( V_172 -> V_185 ) ;
if ( V_182 >= V_180 && V_182 < V_181
&& V_183 <= V_181 && V_183 > V_180 )
;
else {
F_56 ( & V_7 -> V_2 , L_60 ,
F_112 ( V_63 -> V_2 ) , V_172 -> V_12 ) ;
return - V_57 ;
}
F_134 ( & V_170 -> V_186 , & V_60 -> V_129 ) ;
}
return 0 ;
}
struct V_1 * F_135 ( struct V_7 * V_7 ,
struct V_135 * V_136 ,
struct V_166 * V_172 )
{
T_7 V_165 = F_136 ( V_7 , V_136 ) ;
T_7 V_187 = F_137 ( V_7 ) ;
struct V_169 * V_170 ;
struct V_5 * V_6 ;
struct V_60 * V_60 ;
T_4 V_66 = 0 ;
struct V_67 * V_15 ;
struct V_1 * V_2 ;
int V_51 = 0 ;
T_8 V_70 ;
if ( V_165 == 0 ) {
F_56 ( & V_7 -> V_2 , L_61 ) ;
return F_94 ( - V_52 ) ;
}
if ( F_129 ( V_172 -> V_176 ) != V_165 ) {
F_56 ( & V_7 -> V_2 , L_62 ,
V_172 -> V_12 ) ;
if ( F_129 ( V_172 -> V_176 ) != V_187 )
return F_94 ( - V_188 ) ;
F_56 ( & V_7 -> V_2 , L_63 ,
V_172 -> V_12 ) ;
}
V_6 = F_40 ( sizeof( * V_6 ) , V_54 ) ;
if ( ! V_6 )
return F_94 ( - V_55 ) ;
V_6 -> V_9 = - 1 ;
V_2 = & V_6 -> V_4 . V_59 . V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_39 = F_112 ( & V_7 -> V_2 ) ;
V_15 -> V_29 = V_163 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
if ( F_127 ( V_7 , V_172 -> V_12 , V_165 , V_70 ) )
continue;
if ( F_127 ( V_7 , V_172 -> V_12 , V_187 , V_70 ) )
continue;
break;
}
if ( V_70 < V_7 -> V_79 ) {
struct V_62 * V_63 = F_42 ( & V_7 -> V_61 [ V_70 ] ) ;
F_138 ( & V_7 -> V_2 , L_64 ,
F_112 ( V_63 -> V_2 ) , V_172 -> V_12 ) ;
V_51 = - V_57 ;
goto V_189;
}
V_51 = F_132 ( V_7 , V_172 -> V_12 ) ;
if ( V_51 )
goto V_189;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_166 * V_190 ;
struct V_62 * V_63 ;
V_60 = & V_7 -> V_61 [ V_70 ] ;
V_170 = F_139 ( & V_60 -> V_129 ,
F_140 ( * V_170 ) , V_186 ) ;
V_190 = V_170 ? V_170 -> V_173 : 0 ;
if ( ! V_190 ) {
F_67 ( 1 ) ;
continue;
}
V_66 += F_129 ( V_190 -> V_185 ) ;
if ( F_110 ( V_190 -> V_174 ) != 0 )
continue;
F_67 ( V_6 -> V_11 || V_6 -> V_12 ) ;
V_6 -> V_11 = F_38 ( ( void V_191 * ) V_190 -> V_39 ,
V_56 , V_54 ) ;
V_6 -> V_12 = F_38 ( ( void V_191 * ) V_190 -> V_12 ,
V_24 , V_54 ) ;
V_6 -> V_38 = F_129 ( V_190 -> V_38 ) ;
V_63 = F_42 ( V_60 ) ;
if ( F_130 ( V_63 , V_192 ) )
V_6 -> V_4 . V_59 . V_142
= F_141 ( & V_190 -> V_192 ) ;
}
if ( ! V_6 -> V_11 || ! V_6 -> V_12 ) {
V_51 = - V_55 ;
goto V_189;
}
F_79 ( V_7 , V_6 , V_66 ) ;
return V_2 ;
V_189:
F_4 ( V_2 ) ;
switch ( V_51 ) {
case - V_57 :
F_56 ( & V_7 -> V_2 , L_65 , V_74 ) ;
break;
case - V_160 :
F_56 ( & V_7 -> V_2 , L_66 , V_74 ) ;
break;
default:
F_56 ( & V_7 -> V_2 , L_67 ,
V_74 , V_51 ) ;
break;
}
return F_94 ( V_51 ) ;
}
struct V_67 * F_142 ( struct V_7 * V_7 ,
struct V_62 * V_63 , struct V_13 * V_14 ,
T_4 V_30 )
{
struct V_64 V_65 ;
struct V_67 * V_15 ;
F_43 ( & V_65 , V_14 -> V_12 , V_68 ) ;
V_15 = F_143 ( V_14 -> V_15 ,
sizeof( void * ) * ( V_14 -> V_72 + 1 ) ,
V_54 ) ;
if ( ! V_15 )
return NULL ;
V_14 -> V_15 = (struct V_67 * * ) V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_39 , V_65 . V_9 ) == 0
&& V_15 -> V_30 == V_30 ) {
V_14 -> V_15 [ V_14 -> V_72 ++ ] = V_15 ;
return V_15 ;
}
return NULL ;
}
static struct V_1 * F_144 ( struct V_7 * V_7 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
if ( ! F_68 ( & V_7 -> V_2 ) )
return NULL ;
V_14 = F_40 ( sizeof( * V_14 ) , V_54 ) ;
if ( ! V_14 )
return NULL ;
V_2 = & V_14 -> V_59 . V_2 ;
V_2 -> type = & V_17 ;
V_14 -> V_9 = F_145 ( & V_7 -> V_10 , 0 , 0 , V_54 ) ;
if ( V_14 -> V_9 < 0 ) {
F_3 ( V_14 ) ;
return NULL ;
}
F_146 ( V_2 , L_68 , V_7 -> V_9 , V_14 -> V_9 ) ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_2 -> V_193 = V_194 ;
return & V_14 -> V_59 . V_2 ;
}
static struct V_1 * F_147 ( struct V_7 * V_7 )
{
struct V_5 * V_6 ;
struct V_67 * V_15 ;
struct V_1 * V_2 ;
if ( ! F_73 ( & V_7 -> V_2 ) )
return NULL ;
V_6 = F_40 ( sizeof( * V_6 ) , V_54 ) ;
if ( ! V_6 )
return NULL ;
V_2 = & V_6 -> V_4 . V_59 . V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_39 = F_112 ( & V_7 -> V_2 ) ;
V_15 -> V_29 = V_163 ;
V_6 -> V_9 = F_145 ( & V_7 -> V_10 , 0 , 0 , V_54 ) ;
if ( V_6 -> V_9 < 0 ) {
F_3 ( V_6 ) ;
return NULL ;
}
F_146 ( V_2 , L_68 , V_7 -> V_9 , V_6 -> V_9 ) ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_2 -> V_193 = V_194 ;
F_79 ( V_7 , V_6 , 0 ) ;
return V_2 ;
}
void F_148 ( struct V_7 * V_7 )
{
F_67 ( ! F_24 ( & V_7 -> V_2 ) ) ;
if ( F_35 ( V_7 ) == V_195 )
return;
if ( F_68 ( & V_7 -> V_2 ) )
V_7 -> V_123 = F_144 ( V_7 ) ;
else
V_7 -> V_123 = F_147 ( V_7 ) ;
if ( ! V_7 -> V_123 )
F_138 ( & V_7 -> V_2 , L_69 ,
F_68 ( & V_7 -> V_2 ) ? L_13 : L_18 ) ;
else
F_149 ( V_7 -> V_123 ) ;
}
void F_150 ( struct V_7 * V_7 )
{
F_67 ( ! F_24 ( & V_7 -> V_2 ) ) ;
V_7 -> V_196 = F_151 ( V_7 ) ;
if ( ! V_7 -> V_196 )
F_138 ( & V_7 -> V_2 , L_70 ) ;
}
void F_152 ( struct V_7 * V_7 )
{
F_67 ( ! F_24 ( & V_7 -> V_2 ) ) ;
V_7 -> V_197 = F_153 ( V_7 ) ;
if ( ! V_7 -> V_197 )
F_138 ( & V_7 -> V_2 , L_71 ) ;
}
void F_154 ( struct V_7 * V_7 )
{
F_67 ( ! F_24 ( & V_7 -> V_2 ) ) ;
V_7 -> V_198 = F_155 ( V_7 ) ;
if ( ! V_7 -> V_198 )
F_138 ( & V_7 -> V_2 , L_72 ) ;
}
static int F_156 ( struct V_7 * V_7 ,
struct V_166 * V_172 , struct V_1 * * V_162 ,
int V_69 )
{
struct V_60 * V_60 = & V_7 -> V_61 [ 0 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
T_1 * V_12 = F_93 ( V_162 [ V_70 ] ) ;
struct V_67 * V_15 ;
if ( F_157 ( V_12 ) ) {
F_67 ( 1 ) ;
continue;
}
if ( memcmp ( V_12 , V_172 -> V_12 , V_24 ) != 0 )
continue;
if ( F_11 ( V_162 [ V_70 ] ) ) {
V_15 = F_142 ( V_7 , V_63 ,
F_9 ( V_162 [ V_70 ] ) ,
F_129 ( V_172 -> V_107 ) ) ;
if ( ! V_15 )
return - V_52 ;
F_60 ( V_7 , V_63 , V_15 , L_73 , V_69 ) ;
} else {
F_138 ( & V_7 -> V_2 ,
L_74 ,
V_172 -> V_12 ) ;
return - V_52 ;
}
break;
}
return V_70 ;
}
struct V_1 * F_158 ( struct V_7 * V_7 ,
struct V_166 * V_172 , int V_69 )
{
struct V_60 * V_60 = & V_7 -> V_61 [ 0 ] ;
struct V_167 * V_168 = V_7 -> V_168 ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_13 * V_14 ;
char V_39 [ V_56 ] ;
struct V_1 * V_2 = NULL ;
struct V_67 * V_15 ;
if ( F_130 ( V_63 , V_177 ) ) {
if ( ! F_131 ( & V_168 -> V_177 , & V_172 -> V_177 ) ) {
F_56 ( V_63 -> V_2 , L_58 ,
V_168 -> V_177 . V_178 ,
V_172 -> V_177 . V_178 ) ;
return F_94 ( - V_188 ) ;
}
if ( V_172 -> V_176 != F_159 ( V_168 -> V_199 ) ) {
F_56 ( V_63 -> V_2 , L_75 ,
V_168 -> V_199 ,
F_129 ( V_172 -> V_176 ) ) ;
return F_94 ( - V_188 ) ;
}
}
V_14 = F_40 ( sizeof( * V_14 ) , V_54 ) ;
if ( ! V_14 )
return F_94 ( - V_55 ) ;
V_2 = & V_14 -> V_59 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_14 -> V_9 = - 1 ;
V_14 -> V_38 = F_129 ( V_172 -> V_38 ) ;
V_14 -> V_12 = F_38 ( V_172 -> V_12 , V_24 ,
V_54 ) ;
if ( F_130 ( V_63 , V_192 ) )
V_14 -> V_59 . V_142
= F_141 ( & V_172 -> V_192 ) ;
if ( ! V_14 -> V_12 )
goto V_200;
memcpy ( V_39 , V_172 -> V_39 , V_56 ) ;
if ( V_39 [ 0 ] )
V_14 -> V_11 = F_38 ( V_39 , V_56 ,
V_54 ) ;
V_15 = F_142 ( V_7 , V_63 , V_14 ,
F_129 ( V_172 -> V_107 ) ) ;
if ( ! V_15 )
goto V_200;
F_60 ( V_7 , V_63 , V_15 , L_76 , V_69 ) ;
return V_2 ;
V_200:
F_8 ( V_2 ) ;
return F_94 ( - V_52 ) ;
}
static int F_160 ( const void * V_151 , const void * V_178 )
{
const struct V_1 * V_201 = * ( const struct V_1 * * ) V_151 ;
const struct V_1 * V_202 = * ( const struct V_1 * * ) V_178 ;
struct V_13 * V_203 , * V_204 ;
struct V_5 * V_205 , * V_206 ;
if ( F_12 ( V_201 ) )
return 0 ;
if ( F_11 ( V_201 ) ) {
V_203 = F_9 ( V_201 ) ;
V_204 = F_9 ( V_202 ) ;
return memcmp ( & V_203 -> V_15 [ 0 ] -> V_30 , & V_204 -> V_15 [ 0 ] -> V_30 ,
sizeof( T_4 ) ) ;
}
V_205 = F_5 ( V_201 ) ;
V_206 = F_5 ( V_202 ) ;
return memcmp ( & V_205 -> V_4 . V_15 . V_30 , & V_206 -> V_4 . V_15 . V_30 ,
sizeof( T_4 ) ) ;
}
static struct V_1 * * F_161 ( struct V_7 * V_7 )
{
int V_70 , V_69 = 0 ;
struct V_1 * V_2 , * * V_162 = NULL ;
struct V_169 * V_170 , * V_207 ;
struct V_60 * V_60 = & V_7 -> V_61 [ 0 ] ;
T_4 V_208 = V_60 -> V_30 + V_60 -> V_66 - 1 ;
F_162 (label_ent, e, &nd_mapping->labels, list) {
struct V_166 * V_172 = V_170 -> V_173 ;
struct V_1 * * V_209 ;
T_5 V_29 ;
if ( ! V_172 )
continue;
V_29 = F_163 ( V_172 -> V_29 ) ;
if ( F_68 ( & V_7 -> V_2 )
== ! ! ( V_29 & V_68 ) )
;
else
continue;
if ( V_172 -> V_107 < V_60 -> V_30 || V_172 -> V_107 > V_208 )
continue;
V_70 = F_156 ( V_7 , V_172 , V_162 , V_69 ) ;
if ( V_70 < 0 )
goto V_189;
if ( V_70 < V_69 )
continue;
V_209 = F_126 ( V_69 + 2 , sizeof( V_2 ) , V_54 ) ;
if ( ! V_209 )
goto V_189;
memcpy ( V_209 , V_162 , sizeof( V_2 ) * V_69 ) ;
F_3 ( V_162 ) ;
V_162 = V_209 ;
if ( F_68 ( & V_7 -> V_2 ) )
V_2 = F_158 ( V_7 , V_172 , V_69 ) ;
else {
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_135 * V_136 ;
V_136 = F_109 ( V_63 , V_63 -> V_137 ) ;
V_2 = F_135 ( V_7 , V_136 , V_172 ) ;
}
if ( F_96 ( V_2 ) ) {
switch ( F_97 ( V_2 ) ) {
case - V_188 :
continue;
case - V_160 :
break;
default:
goto V_189;
}
} else
V_162 [ V_69 ++ ] = V_2 ;
}
F_56 ( & V_7 -> V_2 , L_77 ,
V_74 , V_69 , F_68 ( & V_7 -> V_2 )
? L_13 : L_18 , V_69 == 1 ? L_4 : L_2 ) ;
if ( V_69 == 0 ) {
F_164 ( V_60 ) ;
V_162 = F_126 ( 2 , sizeof( V_2 ) , V_54 ) ;
if ( ! V_162 )
goto V_189;
if ( F_68 ( & V_7 -> V_2 ) ) {
struct V_13 * V_14 ;
V_14 = F_40 ( sizeof( * V_14 ) , V_54 ) ;
if ( ! V_14 )
goto V_189;
V_2 = & V_14 -> V_59 . V_2 ;
V_2 -> type = & V_17 ;
} else {
struct V_5 * V_6 ;
V_6 = F_40 ( sizeof( * V_6 ) , V_54 ) ;
if ( ! V_6 )
goto V_189;
V_2 = & V_6 -> V_4 . V_59 . V_2 ;
V_2 -> type = & V_16 ;
F_79 ( V_7 , V_6 , 0 ) ;
}
V_2 -> V_8 = & V_7 -> V_2 ;
V_162 [ V_69 ++ ] = V_2 ;
} else if ( F_73 ( & V_7 -> V_2 ) ) {
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_210 * V_211 , * V_207 ;
F_165 ( V_186 ) ;
int V_112 ;
V_60 = & V_7 -> V_61 [ V_70 ] ;
if ( F_99 ( & V_60 -> V_129 ) ) {
F_67 ( 1 ) ;
continue;
}
V_112 = V_69 ;
F_166 (l, e, &nd_mapping->labels) {
if ( ! V_112 -- )
break;
F_167 ( V_211 , & V_186 ) ;
}
F_164 ( V_60 ) ;
F_168 ( & V_186 , & V_60 -> V_129 ) ;
}
}
if ( V_69 > 1 )
F_169 ( V_162 , V_69 , sizeof( struct V_1 * ) , F_160 , NULL ) ;
return V_162 ;
V_189:
if ( V_162 ) {
for ( V_70 = 0 ; V_162 [ V_70 ] ; V_70 ++ )
if ( F_68 ( & V_7 -> V_2 ) )
F_8 ( V_162 [ V_70 ] ) ;
else
F_4 ( V_162 [ V_70 ] ) ;
F_3 ( V_162 ) ;
}
return NULL ;
}
static struct V_1 * * F_170 ( struct V_7 * V_7 )
{
struct V_60 * V_60 = & V_7 -> V_61 [ 0 ] ;
struct V_1 * * V_162 ;
int V_70 ;
if ( V_7 -> V_79 == 0 )
return NULL ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
V_60 = & V_7 -> V_61 [ V_70 ] ;
F_171 ( & V_60 -> V_184 , V_70 ) ;
}
V_162 = F_161 ( V_7 ) ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
int V_212 = V_7 -> V_79 - 1 - V_70 ;
V_60 = & V_7 -> V_61 [ V_212 ] ;
F_172 ( & V_60 -> V_184 ) ;
}
return V_162 ;
}
static int F_173 ( struct V_7 * V_7 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_7 -> V_79 ; V_70 ++ ) {
struct V_60 * V_60 = & V_7 -> V_61 [ V_70 ] ;
struct V_62 * V_63 = F_42 ( V_60 ) ;
struct V_109 * V_109 = V_60 -> V_109 ;
struct V_169 * V_170 ;
int V_69 , V_112 ;
if ( ! V_63 ) {
if ( F_27 ( V_213 , & V_109 -> V_29 ) )
;
else if ( F_27 ( V_214 , & V_109 -> V_29 ) )
;
else
return 0 ;
F_138 ( & V_7 -> V_2 , L_78 ,
F_112 ( & V_60 -> V_109 -> V_2 ) ,
F_27 ( V_213 , & V_109 -> V_29 )
? L_79 : L_80 ) ;
return - V_52 ;
}
V_60 -> V_63 = V_63 ;
F_174 ( & V_109 -> V_215 ) ;
F_175 ( V_63 ) ;
V_69 = F_176 ( V_63 ) ;
F_56 ( V_63 -> V_2 , L_81 , V_74 , V_69 ) ;
if ( ! V_69 )
continue;
for ( V_112 = 0 ; V_112 < V_69 ; V_112 ++ ) {
struct V_166 * V_173 ;
V_170 = F_40 ( sizeof( * V_170 ) , V_54 ) ;
if ( ! V_170 )
break;
V_173 = F_177 ( V_63 , V_112 ) ;
V_170 -> V_173 = V_173 ;
F_178 ( & V_60 -> V_184 ) ;
F_179 ( & V_170 -> V_186 , & V_60 -> V_129 ) ;
F_172 ( & V_60 -> V_184 ) ;
}
if ( V_112 >= V_69 )
continue;
F_178 ( & V_60 -> V_184 ) ;
F_164 ( V_60 ) ;
F_172 ( & V_60 -> V_184 ) ;
return - V_55 ;
}
return 0 ;
}
int F_180 ( struct V_7 * V_7 , int * V_189 )
{
struct V_1 * * V_162 = NULL ;
int V_70 , V_51 = 0 , type ;
* V_189 = 0 ;
F_47 ( & V_7 -> V_2 ) ;
V_51 = F_173 ( V_7 ) ;
if ( V_51 ) {
F_48 ( & V_7 -> V_2 ) ;
return V_51 ;
}
type = F_35 ( V_7 ) ;
switch ( type ) {
case V_195 :
V_162 = F_125 ( V_7 ) ;
break;
case V_216 :
case V_217 :
V_162 = F_170 ( V_7 ) ;
break;
default:
break;
}
F_48 ( & V_7 -> V_2 ) ;
if ( ! V_162 )
return - V_160 ;
for ( V_70 = 0 ; V_162 [ V_70 ] ; V_70 ++ ) {
struct V_1 * V_2 = V_162 [ V_70 ] ;
int V_9 ;
if ( type == V_217 ) {
struct V_13 * V_14 ;
V_14 = F_9 ( V_2 ) ;
V_9 = F_145 ( & V_7 -> V_10 , 0 , 0 ,
V_54 ) ;
V_14 -> V_9 = V_9 ;
} else if ( type == V_216 ) {
struct V_5 * V_6 ;
V_6 = F_5 ( V_2 ) ;
V_9 = F_145 ( & V_7 -> V_10 , 0 , 0 ,
V_54 ) ;
V_6 -> V_9 = V_9 ;
} else
V_9 = V_70 ;
if ( V_9 < 0 )
break;
F_146 ( V_2 , L_68 , V_7 -> V_9 , V_9 ) ;
V_2 -> V_193 = V_194 ;
F_149 ( V_2 ) ;
}
if ( V_70 )
V_7 -> V_123 = V_162 [ 0 ] ;
if ( V_162 [ V_70 ] ) {
int V_112 ;
for ( V_112 = V_70 ; V_162 [ V_112 ] ; V_112 ++ ) {
struct V_1 * V_2 = V_162 [ V_112 ] ;
F_181 ( V_2 ) ;
F_182 ( V_2 ) ;
}
* V_189 = V_112 - V_70 ;
if ( * V_189 == 0 )
V_51 = - V_160 ;
}
F_3 ( V_162 ) ;
if ( V_51 == - V_160 )
return V_51 ;
return V_70 ;
}

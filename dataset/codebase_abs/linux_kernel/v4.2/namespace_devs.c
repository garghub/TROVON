static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_3 ( V_6 -> V_7 ) ;
F_3 ( V_6 -> V_8 ) ;
F_3 ( V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
if ( V_10 -> V_13 >= 0 )
F_9 ( & V_11 -> V_14 , V_10 -> V_13 ) ;
F_3 ( V_10 -> V_7 ) ;
F_3 ( V_10 -> V_8 ) ;
F_3 ( V_10 -> V_15 ) ;
F_3 ( V_10 ) ;
}
static bool F_10 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_16 : false ;
}
static bool F_11 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_17 : false ;
}
static bool F_12 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> type == & V_18 : false ;
}
const char * F_13 ( struct V_19 * V_20 ,
char * V_21 )
{
struct V_11 * V_11 = F_8 ( V_20 -> V_2 . V_12 ) ;
const char * V_22 = L_1 ;
if ( V_20 -> V_23 && F_14 ( V_20 -> V_23 ) )
V_22 = L_2 ;
if ( F_10 ( & V_20 -> V_2 ) || F_12 ( & V_20 -> V_2 ) )
sprintf ( V_21 , L_3 , V_11 -> V_13 , V_22 ) ;
else if ( F_11 ( & V_20 -> V_2 ) ) {
struct V_9 * V_10 ;
V_10 = F_7 ( & V_20 -> V_2 ) ;
sprintf ( V_21 , L_4 , V_11 -> V_13 , V_10 -> V_13 , V_22 ) ;
} else {
return NULL ;
}
return V_21 ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
return sprintf ( V_26 , L_5 , F_16 ( V_11 ) ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , const char * V_26 ,
const T_2 V_27 )
{
char * V_28 , * V_29 , * V_7 , * * V_30 ;
T_1 V_31 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_30 = & V_6 -> V_7 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_30 = & V_10 -> V_7 ;
} else
return - V_32 ;
if ( V_2 -> V_33 || F_18 ( V_2 ) -> V_23 )
return - V_34 ;
V_28 = F_19 ( V_26 , V_27 + 1 , V_35 ) ;
if ( ! V_28 )
return - V_36 ;
V_28 [ V_27 ] = '\0' ;
V_29 = F_20 ( V_28 ) ;
if ( strlen ( V_29 ) + 1 > V_37 ) {
V_31 = - V_38 ;
goto V_39;
}
V_7 = F_21 ( V_37 , V_35 ) ;
if ( ! V_7 ) {
V_31 = - V_36 ;
goto V_39;
}
F_3 ( * V_30 ) ;
* V_30 = V_7 ;
sprintf ( * V_30 , L_6 , V_29 ) ;
V_31 = V_27 ;
V_39:
F_3 ( V_28 ) ;
return V_31 ;
}
static T_3 F_22 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 -> V_40 . V_2 . V_12 ) ;
struct V_41 * V_41 = & V_11 -> V_42 [ 0 ] ;
struct V_43 * V_44 = F_23 ( V_41 ) ;
struct V_45 V_46 ;
T_3 V_47 = 0 ;
struct V_48 * V_15 ;
if ( ! V_10 -> V_8 )
return 0 ;
F_24 ( & V_46 , V_10 -> V_8 , V_49 ) ;
F_25 (ndd, res)
if ( strcmp ( V_15 -> V_21 , V_46 . V_13 ) == 0 )
V_47 += F_26 ( V_15 ) ;
return V_47 ;
}
static bool F_27 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 -> V_40 . V_2 . V_12 ) ;
struct V_41 * V_41 = & V_11 -> V_42 [ 0 ] ;
struct V_43 * V_44 = F_23 ( V_41 ) ;
struct V_45 V_46 ;
struct V_48 * V_15 ;
int V_50 , V_51 ;
if ( ! V_10 -> V_8 || ! V_10 -> V_52 || ! V_44 )
return false ;
V_50 = 0 ;
F_24 ( & V_46 , V_10 -> V_8 , V_49 ) ;
F_25 (ndd, res) {
if ( strcmp ( V_15 -> V_21 , V_46 . V_13 ) != 0 )
continue;
if ( V_15 -> V_53 & V_54 )
return false ;
V_50 ++ ;
}
if ( V_50 != V_10 -> V_55 )
return false ;
for ( V_51 = 0 ; V_51 < V_10 -> V_55 ; V_51 ++ ) {
struct V_48 * V_56 = NULL ;
F_25 (ndd, res)
if ( V_15 == V_10 -> V_15 [ V_51 ] ) {
V_56 = V_15 ;
break;
}
if ( ! V_56 )
return false ;
}
return true ;
}
T_3 F_28 ( struct V_9 * V_10 )
{
T_3 V_47 ;
F_29 ( & V_10 -> V_40 . V_2 ) ;
V_47 = F_27 ( V_10 ) ;
F_30 ( & V_10 -> V_40 . V_2 ) ;
return V_47 ;
}
static int F_31 ( struct V_11 * V_11 ,
struct V_1 * V_2 )
{
F_32 ( V_2 , V_2 -> V_33 || F_18 ( V_2 ) -> V_23 ,
L_7 ) ;
if ( V_2 -> V_33 || F_18 ( V_2 ) -> V_23 )
return 0 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_3 V_47 = F_26 ( & V_6 -> V_4 . V_15 ) ;
if ( V_47 == 0 && V_6 -> V_8 )
;
else if ( ! V_6 -> V_8 )
return 0 ;
return F_33 ( V_11 , V_6 , V_47 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
T_3 V_47 = F_22 ( V_10 ) ;
if ( V_47 == 0 && V_10 -> V_8 )
;
else if ( ! V_10 -> V_8 || ! V_10 -> V_52 )
return 0 ;
return F_34 ( V_11 , V_10 , V_47 ) ;
} else
return - V_32 ;
}
static T_1 F_35 ( struct V_1 * V_2 ,
struct V_24 * V_25 , const char * V_26 , T_2 V_27 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_1 V_31 ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
F_37 ( V_2 ) ;
V_31 = F_17 ( V_2 , V_26 , V_27 ) ;
if ( V_31 >= 0 )
V_31 = F_31 ( V_11 , V_2 ) ;
F_38 ( V_2 , L_8 , V_57 , V_31 < 0 ? L_9 : L_1 , V_31 ) ;
F_30 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_31 < 0 ? V_31 : V_27 ;
}
static T_1 F_40 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
char * V_30 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_30 = V_6 -> V_7 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_30 = V_10 -> V_7 ;
} else
return - V_32 ;
return sprintf ( V_26 , L_10 , V_30 ? V_30 : L_1 ) ;
}
static int F_41 ( struct V_11 * V_11 ,
struct V_41 * V_41 , struct V_45 * V_46 ,
T_3 V_58 )
{
bool V_59 = strncmp ( V_46 -> V_13 , L_11 , 3 ) == 0 ;
struct V_43 * V_44 = F_23 ( V_41 ) ;
int V_31 = 0 ;
while ( V_58 ) {
struct V_48 * V_15 , * V_60 ;
T_3 V_61 ;
V_60 = NULL ;
F_25 (ndd, res)
if ( strcmp ( V_15 -> V_21 , V_46 -> V_13 ) == 0 )
V_60 = V_15 ;
V_15 = V_60 ;
if ( ! V_15 )
return 0 ;
if ( V_58 >= F_26 ( V_15 ) ) {
V_58 -= F_26 ( V_15 ) ;
F_42 ( V_11 , V_44 , V_15 , L_12 , V_31 ) ;
F_43 ( V_44 , V_15 ) ;
continue;
}
if ( V_59 )
V_61 = V_15 -> V_62 + V_58 ;
else
V_61 = V_15 -> V_62 ;
V_31 = F_44 ( V_15 , V_61 , F_26 ( V_15 ) - V_58 ) ;
if ( V_31 == 0 )
V_15 -> V_53 |= V_54 ;
F_42 ( V_11 , V_44 , V_15 , L_13 , V_31 ) ;
break;
}
return V_31 ;
}
static int F_45 ( struct V_11 * V_11 ,
struct V_45 * V_46 , T_3 V_58 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
int V_31 ;
V_31 = F_41 ( V_11 , V_41 , V_46 , V_58 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static T_3 F_46 ( struct V_45 * V_46 ,
struct V_11 * V_11 , struct V_41 * V_41 ,
T_3 V_58 )
{
bool V_59 = strncmp ( V_46 -> V_13 , L_11 , 3 ) == 0 ;
struct V_43 * V_44 = F_23 ( V_41 ) ;
T_3 V_64 ;
struct V_48 * V_15 ;
int V_31 = 0 ;
if ( V_59 )
V_64 = V_41 -> V_62 + V_41 -> V_47 - V_58 ;
else
V_64 = V_41 -> V_62 ;
V_15 = F_47 ( V_44 , V_46 , V_64 , V_58 ) ;
if ( ! V_15 )
V_31 = - V_34 ;
F_42 ( V_11 , V_44 , V_15 , L_14 , V_31 ) ;
return V_31 ? V_58 : 0 ;
}
static bool F_48 ( bool V_65 , bool V_66 ,
struct V_45 * V_46 , struct V_48 * V_15 )
{
if ( V_66 || ! V_65 )
return true ;
if ( ! V_15 || strcmp ( V_15 -> V_21 , V_46 -> V_13 ) == 0 )
return true ;
return false ;
}
static T_3 F_49 ( struct V_11 * V_11 ,
struct V_41 * V_41 , struct V_45 * V_46 ,
T_3 V_58 )
{
T_3 V_67 = V_41 -> V_62 + V_41 -> V_47 - 1 ;
bool V_66 = strcmp ( V_46 -> V_13 , L_15 ) == 0 ;
bool V_65 = strncmp ( V_46 -> V_13 , L_16 , 4 ) == 0 ;
struct V_43 * V_44 = F_23 ( V_41 ) ;
const T_3 V_68 = V_58 ;
struct V_48 * V_15 ;
int V_69 ;
V_70:
V_69 = 0 ;
F_25 (ndd, res) {
T_3 V_71 , V_72 = 0 , V_73 , V_74 ;
struct V_48 * V_75 = V_15 -> V_76 , * V_77 = NULL ;
enum V_78 V_79 = V_80 ;
const char * V_81 ;
int V_31 = 0 ;
if ( V_15 -> V_62 > V_67 )
continue;
if ( V_15 -> V_82 < V_41 -> V_62 )
continue;
if ( ! V_69 ++ && V_15 -> V_62 > V_41 -> V_62 ) {
V_73 = V_41 -> V_62 ;
V_72 = V_15 -> V_62 - V_73 ;
if ( F_48 ( V_65 , V_66 , V_46 , NULL ) )
V_79 = V_83 ;
}
if ( ! V_79 && V_75 ) {
V_73 = V_15 -> V_62 + F_26 ( V_15 ) ;
V_74 = F_50 ( V_67 , V_75 -> V_62 - 1 ) ;
if ( F_48 ( V_65 , V_66 , V_46 , V_15 )
&& V_73 < V_74 ) {
V_72 = V_74 + 1 - V_73 ;
V_79 = V_84 ;
}
}
if ( ! V_79 && ! V_75 ) {
V_73 = V_15 -> V_62 + F_26 ( V_15 ) ;
V_74 = V_67 ;
if ( F_48 ( V_65 , V_66 , V_46 , V_15 )
&& V_73 < V_74 ) {
V_72 = V_74 + 1 - V_73 ;
V_79 = V_85 ;
}
}
if ( ! V_79 || ! V_72 )
continue;
V_71 = F_50 ( V_72 , V_58 ) ;
switch ( V_79 ) {
case V_83 :
if ( strcmp ( V_15 -> V_21 , V_46 -> V_13 ) == 0 ) {
if ( V_65 && ! V_66 )
return V_58 ;
V_31 = F_44 ( V_15 , V_15 -> V_62 - V_71 ,
F_26 ( V_15 ) + V_71 ) ;
V_81 = L_17 ;
} else
V_81 = L_18 ;
break;
case V_84 :
if ( strcmp ( V_75 -> V_21 , V_46 -> V_13 ) == 0 ) {
if ( V_65 && ! V_66 )
return V_58 ;
V_31 = F_44 ( V_75 , V_75 -> V_62
- V_71 , F_26 ( V_75 )
+ V_71 ) ;
V_77 = V_75 ;
V_81 = L_19 ;
} else if ( strcmp ( V_15 -> V_21 , V_46 -> V_13 ) == 0 ) {
V_81 = L_20 ;
} else
V_81 = L_18 ;
break;
case V_85 :
if ( strcmp ( V_15 -> V_21 , V_46 -> V_13 ) == 0 )
V_81 = L_20 ;
else
V_81 = L_18 ;
break;
default:
return V_58 ;
}
if ( strcmp ( V_81 , L_18 ) == 0 ) {
if ( ! V_65 )
V_73 += V_72 - V_71 ;
else if ( ! V_66 && V_73 != V_41 -> V_62 )
return V_58 ;
V_77 = F_47 ( V_44 , V_46 ,
V_73 , V_71 ) ;
if ( ! V_77 )
V_31 = - V_34 ;
} else if ( strcmp ( V_81 , L_20 ) == 0 ) {
V_31 = F_44 ( V_15 , V_15 -> V_62 , F_26 ( V_15 )
+ V_71 ) ;
if ( V_31 == 0 )
V_15 -> V_53 |= V_54 ;
}
if ( ! V_77 )
V_77 = V_15 ;
F_42 ( V_11 , V_44 , V_77 , L_21 ,
V_81 , V_79 , V_31 ) ;
if ( V_31 )
return V_58 ;
V_58 -= V_71 ;
if ( V_58 ) {
goto V_70;
} else
return 0 ;
}
if ( ( V_65 || ! V_44 -> V_86 . V_87 ) && V_58 == V_68 )
return F_46 ( V_46 , V_11 , V_41 , V_58 ) ;
return V_58 ;
}
static int F_51 ( struct V_11 * V_11 ,
struct V_41 * V_41 , struct V_45 * V_46 )
{
struct V_43 * V_44 = F_23 ( V_41 ) ;
struct V_48 * V_15 ;
if ( strncmp ( L_16 , V_46 -> V_13 , 4 ) == 0 )
return 0 ;
V_70:
F_25 (ndd, res) {
int V_31 ;
struct V_48 * V_75 = V_15 -> V_76 ;
T_3 V_82 = V_15 -> V_62 + F_26 ( V_15 ) ;
if ( ! V_75 || strcmp ( V_15 -> V_21 , V_46 -> V_13 ) != 0
|| strcmp ( V_75 -> V_21 , V_46 -> V_13 ) != 0
|| V_82 != V_75 -> V_62 )
continue;
V_82 += F_26 ( V_75 ) ;
F_43 ( V_44 , V_75 ) ;
V_31 = F_44 ( V_15 , V_15 -> V_62 , V_82 - V_15 -> V_62 ) ;
F_42 ( V_11 , V_44 , V_15 , L_22 , V_31 ) ;
if ( V_31 )
return V_31 ;
V_15 -> V_53 |= V_54 ;
goto V_70;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , void * V_88 )
{
struct V_89 * V_89 = V_88 ;
struct V_11 * V_11 ;
struct V_45 V_46 ;
int V_51 ;
if ( ! F_53 ( V_2 ) )
return 0 ;
V_11 = F_8 ( V_2 ) ;
if ( V_11 -> V_63 == 0 )
return 0 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
strcat ( V_46 . V_13 , L_15 ) ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
T_3 V_58 , V_90 = 0 ;
if ( V_41 -> V_89 != V_89 )
continue;
V_58 = F_54 ( V_11 , V_41 , & V_90 ) ;
if ( V_58 == 0 )
return 0 ;
V_90 = F_49 ( V_11 , V_41 , & V_46 , V_58 ) ;
F_32 ( & V_11 -> V_2 , V_90 ,
L_23 ,
( unsigned long long ) V_58 - V_90 ,
( unsigned long long ) V_58 ) ;
return V_90 ? - V_32 : 0 ;
}
return 0 ;
}
static void F_55 ( struct V_91 * V_91 ,
struct V_41 * V_41 )
{
struct V_43 * V_44 = F_23 ( V_41 ) ;
struct V_48 * V_15 , * V_92 ;
F_56 (ndd, res, _res)
if ( strcmp ( V_15 -> V_21 , L_15 ) == 0 )
F_43 ( V_44 , V_15 ) ;
}
static int F_57 ( struct V_91 * V_91 ,
struct V_41 * V_41 )
{
struct V_89 * V_89 = V_41 -> V_89 ;
int V_31 ;
V_31 = F_58 ( & V_91 -> V_2 , V_89 ,
F_52 ) ;
if ( V_31 )
F_55 ( V_91 , V_41 ) ;
return V_31 ;
}
static int F_59 ( struct V_11 * V_11 ,
struct V_45 * V_46 , T_3 V_58 )
{
struct V_91 * V_91 = F_60 ( & V_11 -> V_2 ) ;
bool V_65 = strncmp ( V_46 -> V_13 , L_16 , 4 ) == 0 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
T_3 V_90 = V_58 ;
int V_31 , V_93 ;
for ( V_93 = V_65 ; V_93 < 2 ; V_93 ++ ) {
bool V_94 = V_93 == 0 ;
if ( V_94 ) {
V_31 = F_57 ( V_91 , V_41 ) ;
if ( V_31 )
return V_31 ;
}
V_90 = F_49 ( V_11 , V_41 ,
V_46 , V_90 ) ;
if ( V_94 )
F_55 ( V_91 , V_41 ) ;
if ( V_90 == 0 )
break;
}
F_32 ( & V_11 -> V_2 , V_90 ,
L_24 ,
( unsigned long long ) V_58 - V_90 ,
( unsigned long long ) V_58 ) ;
if ( V_90 )
return - V_32 ;
V_31 = F_51 ( V_11 , V_41 , V_46 ) ;
if ( V_31 )
return V_31 ;
}
return 0 ;
}
static void F_61 ( struct V_11 * V_11 ,
struct V_5 * V_6 , T_3 V_47 )
{
struct V_48 * V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_62 = V_11 -> V_95 ;
V_15 -> V_82 = V_11 -> V_95 + V_47 - 1 ;
}
static T_1 F_62 ( struct V_1 * V_2 , unsigned long long V_96 )
{
T_3 V_97 = 0 , V_72 = 0 ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_41 * V_41 ;
struct V_43 * V_44 ;
struct V_45 V_46 ;
T_4 V_53 = 0 , V_98 ;
T_5 * V_8 = NULL ;
int V_31 , V_51 ;
if ( V_2 -> V_33 || F_18 ( V_2 ) -> V_23 )
return - V_34 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_53 = V_49 ;
}
if ( ! V_8 || V_11 -> V_63 == 0 )
return - V_32 ;
F_63 ( V_96 , V_99 * V_11 -> V_63 , & V_98 ) ;
if ( V_98 ) {
F_38 ( V_2 , L_25 , V_96 ,
( V_99 * V_11 -> V_63 ) / V_100 ) ;
return - V_38 ;
}
F_24 ( & V_46 , V_8 , V_53 ) ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
V_41 = & V_11 -> V_42 [ V_51 ] ;
V_44 = F_23 ( V_41 ) ;
if ( ! V_44 )
return - V_32 ;
V_97 += F_64 ( V_44 , & V_46 ) ;
}
V_72 = F_65 ( V_11 ) ;
if ( V_96 > V_72 + V_97 )
return - V_101 ;
if ( V_96 == V_97 )
return 0 ;
V_96 = F_66 ( V_96 , V_11 -> V_63 ) ;
V_97 = F_66 ( V_97 , V_11 -> V_63 ) ;
if ( V_96 < V_97 )
V_31 = F_45 ( V_11 , & V_46 ,
V_97 - V_96 ) ;
else
V_31 = F_59 ( V_11 , & V_46 , V_96 - V_97 ) ;
if ( V_31 )
return V_31 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_61 ( V_11 , V_6 ,
V_96 * V_11 -> V_63 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( V_96 == 0 && V_11 -> V_102 != V_2
&& ! V_10 -> V_40 . V_23 )
F_67 ( V_2 , V_103 ) ;
}
return V_31 ;
}
static T_1 F_68 ( struct V_1 * V_2 ,
struct V_24 * V_25 , const char * V_26 , T_2 V_27 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
unsigned long long V_96 ;
T_5 * * V_8 = NULL ;
int V_31 ;
V_31 = F_69 ( V_26 , 0 , & V_96 ) ;
if ( V_31 )
return V_31 ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
F_37 ( V_2 ) ;
V_31 = F_62 ( V_2 , V_96 ) ;
if ( V_31 >= 0 )
V_31 = F_31 ( V_11 , V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = & V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = & V_10 -> V_8 ;
}
if ( V_31 == 0 && V_96 == 0 && V_8 ) {
F_3 ( * V_8 ) ;
* V_8 = NULL ;
}
F_38 ( V_2 , L_26 , V_57 , V_96 , V_31 < 0
? L_27 : L_28 , V_31 ) ;
F_30 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_31 < 0 ? V_31 : V_27 ;
}
T_3 F_70 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = & V_20 -> V_2 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return F_26 ( & V_6 -> V_4 . V_15 ) ;
} else if ( F_11 ( V_2 ) ) {
return F_22 ( F_7 ( V_2 ) ) ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_26 ( & V_4 -> V_15 ) ;
} else
F_71 ( 1 , L_29 ) ;
return 0 ;
}
T_3 F_72 ( struct V_19 * V_20 )
{
T_3 V_47 ;
F_29 ( & V_20 -> V_2 ) ;
V_47 = F_70 ( V_20 ) ;
F_30 ( & V_20 -> V_2 ) ;
return V_47 ;
}
static T_1 F_73 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
return sprintf ( V_26 , L_30 , ( unsigned long long )
F_72 ( F_18 ( V_2 ) ) ) ;
}
static T_1 F_74 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
T_5 * V_8 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
} else
return - V_32 ;
if ( V_8 )
return sprintf ( V_26 , L_31 , V_8 ) ;
return sprintf ( V_26 , L_32 ) ;
}
static int F_75 ( struct V_11 * V_11 ,
struct V_1 * V_2 , T_5 * V_104 , T_5 * * V_105 )
{
T_4 V_53 = F_11 ( V_2 ) ? V_49 : 0 ;
struct V_45 V_106 ;
struct V_45 V_107 ;
int V_51 ;
if ( ! F_76 ( V_2 , V_104 ) )
return - V_38 ;
if ( * V_105 == NULL )
goto V_39;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
if ( V_41 -> V_108 )
return - V_34 ;
}
F_24 ( & V_106 , * V_105 , V_53 ) ;
F_24 ( & V_107 , V_104 , V_53 ) ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
struct V_43 * V_44 = F_23 ( V_41 ) ;
struct V_48 * V_15 ;
F_25 (ndd, res)
if ( strcmp ( V_15 -> V_21 , V_106 . V_13 ) == 0 )
sprintf ( ( void * ) V_15 -> V_21 , L_6 ,
V_107 . V_13 ) ;
}
F_3 ( * V_105 ) ;
V_39:
* V_105 = V_104 ;
return 0 ;
}
static T_1 F_77 ( struct V_1 * V_2 ,
struct V_24 * V_25 , const char * V_26 , T_2 V_27 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_5 * V_8 = NULL ;
T_1 V_31 = 0 ;
T_5 * * V_109 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_109 = & V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_109 = & V_10 -> V_8 ;
} else
return - V_32 ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( F_18 ( V_2 ) -> V_23 )
V_31 = - V_34 ;
if ( V_31 >= 0 )
V_31 = F_78 ( V_2 , & V_8 , V_26 , V_27 ) ;
if ( V_31 >= 0 )
V_31 = F_75 ( V_11 , V_2 , V_8 , V_109 ) ;
if ( V_31 >= 0 )
V_31 = F_31 ( V_11 , V_2 ) ;
else
F_3 ( V_8 ) ;
F_38 ( V_2 , L_33 , V_57 ,
V_31 , V_26 , V_26 [ V_27 - 1 ] == '\n' ? L_1 : L_32 ) ;
F_30 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_31 < 0 ? V_31 : V_27 ;
}
static T_1 F_79 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_48 * V_15 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_15 = & V_6 -> V_4 . V_15 ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 = & V_4 -> V_15 ;
} else
return - V_32 ;
if ( F_26 ( V_15 ) == 0 )
return - V_32 ;
return sprintf ( V_26 , L_34 , ( unsigned long long ) V_15 -> V_62 ) ;
}
static T_1 F_80 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
return - V_32 ;
return F_81 ( V_10 -> V_52 , V_110 , V_26 ) ;
}
static T_1 F_82 ( struct V_1 * V_2 ,
struct V_24 * V_25 , const char * V_26 , T_2 V_27 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_1 V_31 = 0 ;
if ( ! F_11 ( V_2 ) )
return - V_32 ;
F_36 ( V_2 ) ;
F_29 ( V_2 ) ;
if ( F_18 ( V_2 ) -> V_23 )
V_31 = - V_34 ;
if ( V_31 >= 0 )
V_31 = F_83 ( V_2 , V_26 , & V_10 -> V_52 ,
V_110 ) ;
if ( V_31 >= 0 )
V_31 = F_31 ( V_11 , V_2 ) ;
F_38 ( V_2 , L_35 , V_57 ,
V_31 , V_31 < 0 ? L_36 : L_37 , V_26 ,
V_26 [ V_27 - 1 ] == '\n' ? L_1 : L_32 ) ;
F_30 ( V_2 ) ;
F_39 ( V_2 ) ;
return V_31 ? V_31 : V_27 ;
}
static T_1 F_84 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_45 V_46 ;
int V_50 = 0 , V_51 ;
T_5 * V_8 = NULL ;
T_4 V_53 = 0 ;
F_29 ( V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
V_53 = 0 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_53 = V_49 ;
}
if ( ! V_8 )
goto V_39;
F_24 ( & V_46 , V_8 , V_53 ) ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
struct V_43 * V_44 = F_23 ( V_41 ) ;
struct V_48 * V_15 ;
F_25 (ndd, res)
if ( strcmp ( V_15 -> V_21 , V_46 . V_13 ) == 0 )
V_50 ++ ;
}
V_39:
F_30 ( V_2 ) ;
return sprintf ( V_26 , L_5 , V_50 ) ;
}
static T_1 F_85 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_19 * V_20 = F_18 ( V_2 ) ;
T_1 V_31 ;
F_36 ( V_2 ) ;
V_31 = sprintf ( V_26 , L_10 , V_20 -> V_23 ? F_86 ( V_20 -> V_23 ) : L_1 ) ;
F_39 ( V_2 ) ;
return V_31 ;
}
static T_1 F_87 ( struct V_1 * V_2 ,
struct V_24 * V_25 , const char * V_26 , T_2 V_27 )
{
bool V_111 ;
int V_31 = F_88 ( V_26 , & V_111 ) ;
if ( V_31 )
return V_31 ;
F_18 ( V_2 ) -> V_111 = V_111 ;
return V_27 ;
}
static T_1 F_89 ( struct V_1 * V_2 ,
struct V_24 * V_25 , char * V_26 )
{
return sprintf ( V_26 , L_5 , F_18 ( V_2 ) -> V_111 ) ;
}
static T_6 F_90 ( struct V_112 * V_113 ,
struct V_114 * V_115 , int V_58 )
{
struct V_1 * V_2 = F_91 ( V_113 , struct V_1 , V_113 ) ;
if ( V_115 == & V_116 . V_25 ) {
if ( F_11 ( V_2 ) )
return 0 ;
return V_115 -> V_117 ;
}
if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
if ( V_115 == & V_118 . V_25 )
return V_119 | V_120 ;
if ( F_10 ( V_2 ) && V_115 == & V_121 . V_25 )
return 0 ;
return V_115 -> V_117 ;
}
if ( V_115 == & V_122 . V_25 || V_115 == & V_118 . V_25
|| V_115 == & V_123 . V_25
|| V_115 == & V_124 . V_25 )
return V_115 -> V_117 ;
return 0 ;
}
struct V_19 * F_92 ( struct V_1 * V_2 )
{
struct V_125 * V_125 = F_14 ( V_2 ) ? F_93 ( V_2 ) : NULL ;
struct V_19 * V_20 ;
T_3 V_47 ;
if ( V_125 ) {
V_20 = V_125 -> V_20 ;
if ( ! V_20 )
return F_94 ( - V_126 ) ;
F_36 ( & V_20 -> V_2 ) ;
F_39 ( & V_20 -> V_2 ) ;
if ( V_20 -> V_2 . V_33 ) {
F_38 ( & V_20 -> V_2 , L_38 ,
F_86 ( & V_125 -> V_2 ) ) ;
return F_94 ( - V_34 ) ;
}
if ( F_32 ( & V_20 -> V_2 , V_20 -> V_23 != & V_125 -> V_2 ,
L_39 ,
F_86 ( & V_125 -> V_2 ) ,
F_86 ( V_20 -> V_23 ) ) )
return F_94 ( - V_32 ) ;
} else {
V_20 = F_18 ( V_2 ) ;
if ( V_20 -> V_23 ) {
F_38 ( V_2 , L_40 ,
F_86 ( V_20 -> V_23 ) ) ;
return F_94 ( - V_32 ) ;
}
}
V_47 = F_72 ( V_20 ) ;
if ( V_47 < V_127 ) {
F_38 ( & V_20 -> V_2 , L_41 ,
& V_47 , V_127 ) ;
return F_94 ( - V_126 ) ;
}
if ( F_10 ( & V_20 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_20 -> V_2 ) ;
if ( ! V_6 -> V_8 ) {
F_38 ( & V_20 -> V_2 , L_42 , V_57 ) ;
return F_94 ( - V_126 ) ;
}
} else if ( F_11 ( & V_20 -> V_2 ) ) {
struct V_9 * V_10 ;
V_10 = F_7 ( & V_20 -> V_2 ) ;
if ( ! F_28 ( V_10 ) )
return F_94 ( - V_126 ) ;
}
return V_20 ;
}
static struct V_1 * * F_95 ( struct V_11 * V_11 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 , * * V_128 ;
struct V_48 * V_15 ;
V_4 = F_21 ( sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 )
return NULL ;
V_128 = F_96 ( 2 , sizeof( struct V_1 * ) , V_35 ) ;
if ( ! V_128 ) {
F_3 ( V_4 ) ;
return NULL ;
}
V_2 = & V_4 -> V_40 . V_2 ;
V_2 -> type = & V_18 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_15 = & V_4 -> V_15 ;
V_15 -> V_21 = F_86 ( & V_11 -> V_2 ) ;
V_15 -> V_53 = V_129 ;
V_15 -> V_62 = V_11 -> V_95 ;
V_15 -> V_82 = V_15 -> V_62 + V_11 -> V_130 - 1 ;
V_128 [ 0 ] = V_2 ;
return V_128 ;
}
static bool F_97 ( struct V_11 * V_11 , T_5 * V_8 ,
T_7 V_131 , T_8 V_29 )
{
struct V_132 * V_56 = NULL ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
struct V_132 * V_133 ;
bool V_134 = false ;
int V_135 ;
F_98 (l, nd_label, nd_mapping->labels) {
T_7 V_136 = F_99 ( V_133 -> V_136 ) ;
T_8 V_137 = F_100 ( V_133 -> V_137 ) ;
T_8 V_138 = F_100 ( V_133 -> V_138 ) ;
if ( V_136 != V_131 )
continue;
if ( memcmp ( V_133 -> V_8 , V_8 , V_139 ) != 0 )
continue;
if ( V_134 ) {
F_38 ( F_23 ( V_41 ) -> V_2 ,
L_43 ,
V_57 ) ;
return false ;
}
V_134 = true ;
if ( V_138 != V_11 -> V_63 )
continue;
if ( V_137 != V_29 )
continue;
V_56 = V_133 ;
break;
}
if ( V_56 )
break;
}
return V_56 != NULL ;
}
static int F_101 ( struct V_11 * V_11 , T_5 * V_140 )
{
struct V_132 * V_141 = NULL ;
int V_51 ;
if ( ! V_140 )
return - V_126 ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
struct V_132 * V_133 ;
T_7 V_142 , V_143 , V_144 , V_145 ;
int V_135 ;
F_98 (l, nd_label, nd_mapping->labels)
if ( memcmp ( V_133 -> V_8 , V_140 , V_139 ) == 0 )
break;
if ( ! V_133 ) {
F_102 ( 1 ) ;
return - V_38 ;
}
V_141 = V_133 ;
V_142 = V_41 -> V_62 ;
V_143 = V_142 + V_41 -> V_47 ;
V_144 = F_99 ( V_141 -> V_86 ) ;
V_145 = V_144 + F_99 ( V_141 -> V_146 ) ;
if ( V_144 == V_142 && V_145 <= V_143 )
;
else
return - V_38 ;
V_41 -> V_108 [ 0 ] = V_141 ;
V_41 -> V_108 [ 1 ] = NULL ;
}
return 0 ;
}
static int F_103 ( struct V_11 * V_11 ,
struct V_5 * V_6 )
{
T_7 V_131 = F_104 ( V_11 ) ;
struct V_132 * V_133 ;
T_5 V_147 [ V_139 ] ;
T_3 V_47 = 0 ;
T_5 * V_140 = NULL ;
int V_31 = - V_126 , V_135 ;
T_8 V_51 ;
if ( V_131 == 0 )
return - V_32 ;
F_98 (l, nd_label, nd_region->mapping[0].labels) {
T_7 V_136 = F_99 ( V_133 -> V_136 ) ;
if ( V_136 != V_131 )
continue;
for ( V_51 = 0 ; V_11 -> V_63 ; V_51 ++ )
if ( ! F_97 ( V_11 , V_133 -> V_8 ,
V_131 , V_51 ) )
break;
if ( V_51 < V_11 -> V_63 ) {
V_31 = - V_38 ;
goto V_148;
} else if ( V_140 ) {
V_31 = - V_34 ;
goto V_148;
}
memcpy ( V_147 , V_133 -> V_8 , V_139 ) ;
V_140 = V_147 ;
}
V_31 = F_101 ( V_11 , V_140 ) ;
if ( V_31 )
goto V_148;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
struct V_132 * V_149 = V_41 -> V_108 [ 0 ] ;
V_47 += F_99 ( V_149 -> V_146 ) ;
if ( F_100 ( V_149 -> V_137 ) != 0 )
continue;
F_102 ( V_6 -> V_7 || V_6 -> V_8 ) ;
V_6 -> V_7 = F_19 ( ( void V_150 * ) V_149 -> V_21 ,
V_37 , V_35 ) ;
V_6 -> V_8 = F_19 ( ( void V_150 * ) V_149 -> V_8 ,
V_139 , V_35 ) ;
}
if ( ! V_6 -> V_7 || ! V_6 -> V_8 ) {
V_31 = - V_36 ;
goto V_148;
}
F_61 ( V_11 , V_6 , V_47 ) ;
return 0 ;
V_148:
switch ( V_31 ) {
case - V_38 :
F_38 ( & V_11 -> V_2 , L_44 , V_57 ) ;
break;
case - V_126 :
F_38 ( & V_11 -> V_2 , L_45 , V_57 ) ;
break;
default:
F_38 ( & V_11 -> V_2 , L_46 ,
V_57 , V_31 ) ;
break;
}
return V_31 ;
}
static struct V_1 * * F_105 ( struct V_11 * V_11 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 , * * V_128 ;
struct V_48 * V_15 ;
int V_31 ;
V_6 = F_21 ( sizeof( * V_6 ) , V_35 ) ;
if ( ! V_6 )
return NULL ;
V_2 = & V_6 -> V_4 . V_40 . V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_21 = F_86 ( & V_11 -> V_2 ) ;
V_15 -> V_53 = V_129 ;
V_31 = F_103 ( V_11 , V_6 ) ;
if ( V_31 == - V_126 ) {
int V_51 ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
F_3 ( V_41 -> V_108 ) ;
V_41 -> V_108 = NULL ;
}
F_61 ( V_11 , V_6 , 0 ) ;
V_31 = 0 ;
} else if ( V_31 )
goto V_148;
V_128 = F_96 ( 2 , sizeof( struct V_1 * ) , V_35 ) ;
if ( ! V_128 )
goto V_148;
V_128 [ 0 ] = V_2 ;
return V_128 ;
V_148:
F_4 ( & V_6 -> V_4 . V_40 . V_2 ) ;
return NULL ;
}
struct V_48 * F_106 ( struct V_11 * V_11 ,
struct V_43 * V_44 , struct V_9 * V_10 ,
T_3 V_62 )
{
struct V_45 V_46 ;
struct V_48 * V_15 ;
F_24 ( & V_46 , V_10 -> V_8 , V_49 ) ;
V_15 = F_107 ( V_10 -> V_15 ,
sizeof( void * ) * ( V_10 -> V_55 + 1 ) ,
V_35 ) ;
if ( ! V_15 )
return NULL ;
V_10 -> V_15 = (struct V_48 * * ) V_15 ;
F_25 (ndd, res)
if ( strcmp ( V_15 -> V_21 , V_46 . V_13 ) == 0
&& V_15 -> V_62 == V_62 ) {
V_10 -> V_15 [ V_10 -> V_55 ++ ] = V_15 ;
return V_15 ;
}
return NULL ;
}
static struct V_1 * F_108 ( struct V_11 * V_11 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
if ( ! F_109 ( & V_11 -> V_2 ) )
return NULL ;
V_10 = F_21 ( sizeof( * V_10 ) , V_35 ) ;
if ( ! V_10 )
return NULL ;
V_2 = & V_10 -> V_40 . V_2 ;
V_2 -> type = & V_17 ;
V_10 -> V_13 = F_110 ( & V_11 -> V_14 , 0 , 0 , V_35 ) ;
if ( V_10 -> V_13 < 0 ) {
F_3 ( V_10 ) ;
return NULL ;
}
F_111 ( V_2 , L_47 , V_11 -> V_13 , V_10 -> V_13 ) ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_2 -> V_151 = V_152 ;
return & V_10 -> V_40 . V_2 ;
}
void F_112 ( struct V_11 * V_11 )
{
F_102 ( ! F_113 ( & V_11 -> V_2 ) ) ;
V_11 -> V_102 = F_108 ( V_11 ) ;
if ( ! V_11 -> V_102 )
F_114 ( & V_11 -> V_2 , L_48 ) ;
else
F_115 ( V_11 -> V_102 ) ;
}
void F_116 ( struct V_11 * V_11 )
{
F_102 ( ! F_113 ( & V_11 -> V_2 ) ) ;
V_11 -> V_153 = F_117 ( V_11 ) ;
if ( ! V_11 -> V_153 )
F_114 ( & V_11 -> V_2 , L_49 ) ;
}
static struct V_1 * * F_118 ( struct V_11 * V_11 )
{
struct V_41 * V_41 = & V_11 -> V_42 [ 0 ] ;
struct V_132 * V_133 ;
struct V_1 * V_2 , * * V_128 = NULL ;
struct V_9 * V_10 ;
struct V_43 * V_44 ;
int V_51 , V_135 , V_50 = 0 ;
struct V_48 * V_15 ;
if ( V_11 -> V_63 == 0 )
return NULL ;
V_44 = F_23 ( V_41 ) ;
F_98 (l, nd_label, nd_mapping->labels) {
T_4 V_53 = F_119 ( V_133 -> V_53 ) ;
char * V_21 [ V_37 ] ;
struct V_1 * * V_154 ;
if ( V_53 & V_49 )
;
else
continue;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_10 = F_7 ( V_128 [ V_51 ] ) ;
if ( memcmp ( V_10 -> V_8 , V_133 -> V_8 ,
V_139 ) == 0 ) {
V_15 = F_106 ( V_11 , V_44 , V_10 ,
F_99 ( V_133 -> V_86 ) ) ;
if ( ! V_15 )
goto V_148;
F_42 ( V_11 , V_44 , V_15 , L_50 ,
F_86 ( & V_10 -> V_40 . V_2 ) ) ;
break;
}
}
if ( V_51 < V_50 )
continue;
V_154 = F_96 ( V_50 + 2 , sizeof( V_2 ) , V_35 ) ;
if ( ! V_154 )
goto V_148;
memcpy ( V_154 , V_128 , sizeof( V_2 ) * V_50 ) ;
F_3 ( V_128 ) ;
V_128 = V_154 ;
V_10 = F_21 ( sizeof( * V_10 ) , V_35 ) ;
if ( ! V_10 )
goto V_148;
V_2 = & V_10 -> V_40 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_12 = & V_11 -> V_2 ;
F_111 ( V_2 , L_47 , V_11 -> V_13 , V_50 ) ;
V_128 [ V_50 ++ ] = V_2 ;
V_10 -> V_13 = - 1 ;
V_10 -> V_52 = F_99 ( V_133 -> V_52 ) ;
V_10 -> V_8 = F_19 ( V_133 -> V_8 , V_139 ,
V_35 ) ;
if ( ! V_10 -> V_8 )
goto V_148;
memcpy ( V_21 , V_133 -> V_21 , V_37 ) ;
if ( V_21 [ 0 ] )
V_10 -> V_7 = F_19 ( V_21 , V_37 ,
V_35 ) ;
V_15 = F_106 ( V_11 , V_44 , V_10 ,
F_99 ( V_133 -> V_86 ) ) ;
if ( ! V_15 )
goto V_148;
F_42 ( V_11 , V_44 , V_15 , L_50 ,
F_86 ( & V_10 -> V_40 . V_2 ) ) ;
}
F_38 ( & V_11 -> V_2 , L_51 ,
V_57 , V_50 , V_50 == 1 ? L_1 : L_2 ) ;
if ( V_50 == 0 ) {
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
F_3 ( V_41 -> V_108 ) ;
V_41 -> V_108 = NULL ;
}
V_128 = F_96 ( 2 , sizeof( V_2 ) , V_35 ) ;
if ( ! V_128 )
goto V_148;
V_10 = F_21 ( sizeof( * V_10 ) , V_35 ) ;
if ( ! V_10 )
goto V_148;
V_2 = & V_10 -> V_40 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_128 [ V_50 ++ ] = V_2 ;
}
return V_128 ;
V_148:
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_10 = F_7 ( V_128 [ V_51 ] ) ;
F_6 ( & V_10 -> V_40 . V_2 ) ;
}
F_3 ( V_128 ) ;
return NULL ;
}
static int F_120 ( struct V_11 * V_11 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_11 -> V_63 ; V_51 ++ ) {
struct V_41 * V_41 = & V_11 -> V_42 [ V_51 ] ;
struct V_43 * V_44 = F_23 ( V_41 ) ;
struct V_89 * V_89 = V_41 -> V_89 ;
int V_50 , V_93 ;
if ( ! V_44 ) {
if ( ( V_89 -> V_53 & V_155 ) == 0 )
return 0 ;
F_38 ( & V_11 -> V_2 , L_52 ,
F_86 ( & V_41 -> V_89 -> V_2 ) ) ;
return - V_32 ;
}
V_41 -> V_44 = V_44 ;
F_121 ( & V_89 -> V_156 ) ;
F_122 ( V_44 ) ;
V_50 = F_123 ( V_44 ) ;
F_38 ( V_44 -> V_2 , L_53 , V_57 , V_50 ) ;
if ( ! V_50 )
continue;
V_41 -> V_108 = F_96 ( V_50 + 1 , sizeof( void * ) ,
V_35 ) ;
if ( ! V_41 -> V_108 )
return - V_36 ;
for ( V_93 = 0 ; V_93 < V_50 ; V_93 ++ ) {
struct V_132 * V_157 ;
V_157 = F_124 ( V_44 , V_93 ) ;
V_41 -> V_108 [ V_93 ] = V_157 ;
}
}
return 0 ;
}
int F_125 ( struct V_11 * V_11 , int * V_148 )
{
struct V_1 * * V_128 = NULL ;
int V_51 , V_31 = 0 , type ;
* V_148 = 0 ;
F_29 ( & V_11 -> V_2 ) ;
V_31 = F_120 ( V_11 ) ;
if ( V_31 ) {
F_30 ( & V_11 -> V_2 ) ;
return V_31 ;
}
type = F_16 ( V_11 ) ;
switch ( type ) {
case V_158 :
V_128 = F_95 ( V_11 ) ;
break;
case V_159 :
V_128 = F_105 ( V_11 ) ;
break;
case V_160 :
V_128 = F_118 ( V_11 ) ;
break;
default:
break;
}
F_30 ( & V_11 -> V_2 ) ;
if ( ! V_128 )
return - V_126 ;
for ( V_51 = 0 ; V_128 [ V_51 ] ; V_51 ++ ) {
struct V_1 * V_2 = V_128 [ V_51 ] ;
int V_13 ;
if ( type == V_160 ) {
struct V_9 * V_10 ;
V_10 = F_7 ( V_2 ) ;
V_13 = F_110 ( & V_11 -> V_14 , 0 , 0 ,
V_35 ) ;
V_10 -> V_13 = V_13 ;
} else
V_13 = V_51 ;
if ( V_13 < 0 )
break;
F_111 ( V_2 , L_47 , V_11 -> V_13 , V_13 ) ;
V_2 -> V_151 = V_152 ;
F_115 ( V_2 ) ;
}
if ( V_51 )
V_11 -> V_102 = V_128 [ 0 ] ;
if ( V_128 [ V_51 ] ) {
int V_93 ;
for ( V_93 = V_51 ; V_128 [ V_93 ] ; V_93 ++ ) {
struct V_1 * V_2 = V_128 [ V_93 ] ;
F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
}
* V_148 = V_93 - V_51 ;
if ( * V_148 == 0 )
V_31 = - V_126 ;
}
F_3 ( V_128 ) ;
if ( V_31 == - V_126 )
return V_31 ;
return V_51 ;
}

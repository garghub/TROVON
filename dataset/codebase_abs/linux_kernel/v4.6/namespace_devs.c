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
static int F_13 ( struct V_1 * V_2 , void * V_19 )
{
T_1 * V_20 = V_19 , * V_21 = NULL ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_21 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_21 = V_10 -> V_8 ;
} else if ( F_14 ( V_2 ) ) {
struct V_22 * V_22 = F_15 ( V_2 ) ;
V_21 = V_22 -> V_8 ;
} else if ( F_16 ( V_2 ) ) {
struct V_23 * V_23 = F_17 ( V_2 ) ;
V_21 = V_23 -> V_8 ;
}
if ( V_21 && memcmp ( V_20 , V_21 , V_24 ) == 0 )
return - V_25 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , void * V_19 )
{
if ( F_19 ( V_2 ) || F_20 ( V_2 ) )
return F_21 ( V_2 , V_19 , F_13 ) ;
return 0 ;
}
bool F_22 ( struct V_1 * V_2 , T_1 * V_8 )
{
struct V_26 * V_26 = F_23 ( V_2 ) ;
if ( ! V_26 )
return false ;
F_24 ( ! F_25 ( & V_26 -> V_2 ) ) ;
if ( F_21 ( & V_26 -> V_2 , V_8 ,
F_18 ) != 0 )
return false ;
return true ;
}
bool F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_3 * V_4 ;
if ( ! F_27 ( V_27 ) )
return false ;
if ( ! F_28 ( V_28 , & V_11 -> V_29 ) )
return false ;
if ( F_16 ( V_2 ) || F_14 ( V_2 ) )
return false ;
V_4 = F_2 ( V_2 ) ;
if ( F_29 ( V_4 -> V_15 . V_30 , F_30 ( & V_4 -> V_15 ) ,
V_31 ,
V_32 ) == V_33 )
return false ;
#ifdef F_31
return F_31 == V_34 ;
#else
return false ;
#endif
}
const char * F_32 ( struct V_35 * V_36 ,
char * V_37 )
{
struct V_11 * V_11 = F_8 ( V_36 -> V_2 . V_12 ) ;
const char * V_38 = NULL ;
if ( V_36 -> V_39 && F_14 ( V_36 -> V_39 ) )
V_38 = L_1 ;
if ( F_10 ( & V_36 -> V_2 ) || F_12 ( & V_36 -> V_2 ) ) {
sprintf ( V_37 , L_2 , V_11 -> V_13 , V_38 ? V_38 : L_3 ) ;
} else if ( F_11 ( & V_36 -> V_2 ) ) {
struct V_9 * V_10 ;
V_10 = F_7 ( & V_36 -> V_2 ) ;
sprintf ( V_37 , L_4 , V_11 -> V_13 , V_10 -> V_13 ,
V_38 ? V_38 : L_3 ) ;
} else {
return NULL ;
}
return V_37 ;
}
const T_1 * F_33 ( struct V_1 * V_2 )
{
static const T_1 V_40 [ 16 ] ;
if ( ! V_2 )
return V_40 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
return V_10 -> V_8 ;
} else
return V_40 ;
}
static T_2 F_34 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
return sprintf ( V_43 , L_5 , F_35 ( V_11 ) ) ;
}
static T_2 F_36 ( struct V_1 * V_2 , const char * V_43 ,
const T_3 V_44 )
{
char * V_45 , * V_46 , * V_7 , * * V_47 ;
T_2 V_48 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_47 = & V_6 -> V_7 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_47 = & V_10 -> V_7 ;
} else
return - V_49 ;
if ( V_2 -> V_50 || F_37 ( V_2 ) -> V_39 )
return - V_25 ;
V_45 = F_38 ( V_43 , V_44 + 1 , V_51 ) ;
if ( ! V_45 )
return - V_52 ;
V_45 [ V_44 ] = '\0' ;
V_46 = F_39 ( V_45 ) ;
if ( strlen ( V_46 ) + 1 > V_53 ) {
V_48 = - V_54 ;
goto V_55;
}
V_7 = F_40 ( V_53 , V_51 ) ;
if ( ! V_7 ) {
V_48 = - V_52 ;
goto V_55;
}
F_3 ( * V_47 ) ;
* V_47 = V_7 ;
sprintf ( * V_47 , L_6 , V_46 ) ;
V_48 = V_44 ;
V_55:
F_3 ( V_45 ) ;
return V_48 ;
}
static T_4 F_41 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 -> V_56 . V_2 . V_12 ) ;
struct V_57 * V_57 = & V_11 -> V_58 [ 0 ] ;
struct V_59 * V_60 = F_42 ( V_57 ) ;
struct V_61 V_62 ;
T_4 V_63 = 0 ;
struct V_64 * V_15 ;
if ( ! V_10 -> V_8 )
return 0 ;
F_43 ( & V_62 , V_10 -> V_8 , V_65 ) ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_62 . V_13 ) == 0 )
V_63 += F_30 ( V_15 ) ;
return V_63 ;
}
static bool F_45 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 -> V_56 . V_2 . V_12 ) ;
struct V_57 * V_57 = & V_11 -> V_58 [ 0 ] ;
struct V_59 * V_60 = F_42 ( V_57 ) ;
struct V_61 V_62 ;
struct V_64 * V_15 ;
int V_66 , V_67 ;
if ( ! V_10 -> V_8 || ! V_10 -> V_68 || ! V_60 )
return false ;
V_66 = 0 ;
F_43 ( & V_62 , V_10 -> V_8 , V_65 ) ;
F_44 (ndd, res) {
if ( strcmp ( V_15 -> V_37 , V_62 . V_13 ) != 0 )
continue;
if ( V_15 -> V_29 & V_69 )
return false ;
V_66 ++ ;
}
if ( V_66 != V_10 -> V_70 )
return false ;
for ( V_67 = 0 ; V_67 < V_10 -> V_70 ; V_67 ++ ) {
struct V_64 * V_71 = NULL ;
F_44 (ndd, res)
if ( V_15 == V_10 -> V_15 [ V_67 ] ) {
V_71 = V_15 ;
break;
}
if ( ! V_71 )
return false ;
}
return true ;
}
T_4 F_46 ( struct V_9 * V_10 )
{
T_4 V_63 ;
F_47 ( & V_10 -> V_56 . V_2 ) ;
V_63 = F_45 ( V_10 ) ;
F_48 ( & V_10 -> V_56 . V_2 ) ;
return V_63 ;
}
static int F_49 ( struct V_11 * V_11 ,
struct V_1 * V_2 )
{
F_50 ( V_2 , V_2 -> V_50 || F_37 ( V_2 ) -> V_39 ,
L_7 ) ;
if ( V_2 -> V_50 || F_37 ( V_2 ) -> V_39 )
return 0 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_4 V_63 = F_30 ( & V_6 -> V_4 . V_15 ) ;
if ( V_63 == 0 && V_6 -> V_8 )
;
else if ( ! V_6 -> V_8 )
return 0 ;
return F_51 ( V_11 , V_6 , V_63 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
T_4 V_63 = F_41 ( V_10 ) ;
if ( V_63 == 0 && V_10 -> V_8 )
;
else if ( ! V_10 -> V_8 || ! V_10 -> V_68 )
return 0 ;
return F_52 ( V_11 , V_10 , V_63 ) ;
} else
return - V_49 ;
}
static T_2 F_53 ( struct V_1 * V_2 ,
struct V_41 * V_42 , const char * V_43 , T_3 V_44 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_2 V_48 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
V_48 = F_36 ( V_2 , V_43 , V_44 ) ;
if ( V_48 >= 0 )
V_48 = F_49 ( V_11 , V_2 ) ;
F_56 ( V_2 , L_8 , V_72 , V_48 < 0 ? L_9 : L_3 , V_48 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_48 < 0 ? V_48 : V_44 ;
}
static T_2 F_58 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
char * V_47 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_47 = V_6 -> V_7 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_47 = V_10 -> V_7 ;
} else
return - V_49 ;
return sprintf ( V_43 , L_10 , V_47 ? V_47 : L_3 ) ;
}
static int F_59 ( struct V_11 * V_11 ,
struct V_57 * V_57 , struct V_61 * V_62 ,
T_4 V_73 )
{
bool V_74 = strncmp ( V_62 -> V_13 , L_11 , 3 ) == 0 ;
struct V_59 * V_60 = F_42 ( V_57 ) ;
int V_48 = 0 ;
while ( V_73 ) {
struct V_64 * V_15 , * V_75 ;
T_4 V_76 ;
V_75 = NULL ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_62 -> V_13 ) == 0 )
V_75 = V_15 ;
V_15 = V_75 ;
if ( ! V_15 )
return 0 ;
if ( V_73 >= F_30 ( V_15 ) ) {
V_73 -= F_30 ( V_15 ) ;
F_60 ( V_11 , V_60 , V_15 , L_12 , V_48 ) ;
F_61 ( V_60 , V_15 ) ;
continue;
}
if ( V_74 )
V_76 = V_15 -> V_30 + V_73 ;
else
V_76 = V_15 -> V_30 ;
V_48 = F_62 ( V_15 , V_76 , F_30 ( V_15 ) - V_73 ) ;
if ( V_48 == 0 )
V_15 -> V_29 |= V_69 ;
F_60 ( V_11 , V_60 , V_15 , L_13 , V_48 ) ;
break;
}
return V_48 ;
}
static int F_63 ( struct V_11 * V_11 ,
struct V_61 * V_62 , T_4 V_73 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
int V_48 ;
V_48 = F_59 ( V_11 , V_57 , V_62 , V_73 ) ;
if ( V_48 )
return V_48 ;
}
return 0 ;
}
static T_4 F_64 ( struct V_61 * V_62 ,
struct V_11 * V_11 , struct V_57 * V_57 ,
T_4 V_73 )
{
bool V_74 = strncmp ( V_62 -> V_13 , L_11 , 3 ) == 0 ;
struct V_59 * V_60 = F_42 ( V_57 ) ;
T_4 V_78 ;
struct V_64 * V_15 ;
int V_48 = 0 ;
if ( V_74 )
V_78 = V_57 -> V_30 + V_57 -> V_63 - V_73 ;
else
V_78 = V_57 -> V_30 ;
V_15 = F_65 ( V_60 , V_62 , V_78 , V_73 ) ;
if ( ! V_15 )
V_48 = - V_25 ;
F_60 ( V_11 , V_60 , V_15 , L_14 , V_48 ) ;
return V_48 ? V_73 : 0 ;
}
static bool F_66 ( bool V_79 , bool V_80 ,
struct V_61 * V_62 , struct V_64 * V_15 )
{
if ( V_80 || ! V_79 )
return true ;
if ( ! V_15 || strcmp ( V_15 -> V_37 , V_62 -> V_13 ) == 0 )
return true ;
return false ;
}
static T_4 F_67 ( struct V_11 * V_11 ,
struct V_57 * V_57 , struct V_61 * V_62 ,
T_4 V_73 )
{
T_4 V_81 = V_57 -> V_30 + V_57 -> V_63 - 1 ;
bool V_80 = strcmp ( V_62 -> V_13 , L_15 ) == 0 ;
bool V_79 = strncmp ( V_62 -> V_13 , L_16 , 4 ) == 0 ;
struct V_59 * V_60 = F_42 ( V_57 ) ;
const T_4 V_82 = V_73 ;
struct V_64 * V_15 ;
int V_83 ;
V_84:
V_83 = 0 ;
F_44 (ndd, res) {
T_4 V_85 , V_86 = 0 , V_87 , V_88 ;
struct V_64 * V_89 = V_15 -> V_90 , * V_91 = NULL ;
enum V_92 V_93 = V_94 ;
const char * V_95 ;
int V_48 = 0 ;
if ( V_15 -> V_30 > V_81 )
continue;
if ( V_15 -> V_96 < V_57 -> V_30 )
continue;
if ( ! V_83 ++ && V_15 -> V_30 > V_57 -> V_30 ) {
V_87 = V_57 -> V_30 ;
V_86 = V_15 -> V_30 - V_87 ;
if ( F_66 ( V_79 , V_80 , V_62 , NULL ) )
V_93 = V_97 ;
}
if ( ! V_93 && V_89 ) {
V_87 = V_15 -> V_30 + F_30 ( V_15 ) ;
V_88 = F_68 ( V_81 , V_89 -> V_30 - 1 ) ;
if ( F_66 ( V_79 , V_80 , V_62 , V_15 )
&& V_87 < V_88 ) {
V_86 = V_88 + 1 - V_87 ;
V_93 = V_98 ;
}
}
if ( ! V_93 && ! V_89 ) {
V_87 = V_15 -> V_30 + F_30 ( V_15 ) ;
V_88 = V_81 ;
if ( F_66 ( V_79 , V_80 , V_62 , V_15 )
&& V_87 < V_88 ) {
V_86 = V_88 + 1 - V_87 ;
V_93 = V_99 ;
}
}
if ( ! V_93 || ! V_86 )
continue;
V_85 = F_68 ( V_86 , V_73 ) ;
switch ( V_93 ) {
case V_97 :
if ( strcmp ( V_15 -> V_37 , V_62 -> V_13 ) == 0 ) {
if ( V_79 && ! V_80 )
return V_73 ;
V_48 = F_62 ( V_15 , V_15 -> V_30 - V_85 ,
F_30 ( V_15 ) + V_85 ) ;
V_95 = L_17 ;
} else
V_95 = L_18 ;
break;
case V_98 :
if ( strcmp ( V_89 -> V_37 , V_62 -> V_13 ) == 0 ) {
if ( V_79 && ! V_80 )
return V_73 ;
V_48 = F_62 ( V_89 , V_89 -> V_30
- V_85 , F_30 ( V_89 )
+ V_85 ) ;
V_91 = V_89 ;
V_95 = L_19 ;
} else if ( strcmp ( V_15 -> V_37 , V_62 -> V_13 ) == 0 ) {
V_95 = L_20 ;
} else
V_95 = L_18 ;
break;
case V_99 :
if ( strcmp ( V_15 -> V_37 , V_62 -> V_13 ) == 0 )
V_95 = L_20 ;
else
V_95 = L_18 ;
break;
default:
return V_73 ;
}
if ( strcmp ( V_95 , L_18 ) == 0 ) {
if ( ! V_79 )
V_87 += V_86 - V_85 ;
else if ( ! V_80 && V_87 != V_57 -> V_30 )
return V_73 ;
V_91 = F_65 ( V_60 , V_62 ,
V_87 , V_85 ) ;
if ( ! V_91 )
V_48 = - V_25 ;
} else if ( strcmp ( V_95 , L_20 ) == 0 ) {
V_48 = F_62 ( V_15 , V_15 -> V_30 , F_30 ( V_15 )
+ V_85 ) ;
if ( V_48 == 0 )
V_15 -> V_29 |= V_69 ;
}
if ( ! V_91 )
V_91 = V_15 ;
F_60 ( V_11 , V_60 , V_91 , L_21 ,
V_95 , V_93 , V_48 ) ;
if ( V_48 )
return V_73 ;
V_73 -= V_85 ;
if ( V_73 ) {
goto V_84;
} else
return 0 ;
}
if ( ( V_79 || ! V_60 -> V_100 . V_101 ) && V_73 == V_82 )
return F_64 ( V_62 , V_11 , V_57 , V_73 ) ;
return V_73 ;
}
static int F_69 ( struct V_11 * V_11 ,
struct V_57 * V_57 , struct V_61 * V_62 )
{
struct V_59 * V_60 = F_42 ( V_57 ) ;
struct V_64 * V_15 ;
if ( strncmp ( L_16 , V_62 -> V_13 , 4 ) == 0 )
return 0 ;
V_84:
F_44 (ndd, res) {
int V_48 ;
struct V_64 * V_89 = V_15 -> V_90 ;
T_4 V_96 = V_15 -> V_30 + F_30 ( V_15 ) ;
if ( ! V_89 || strcmp ( V_15 -> V_37 , V_62 -> V_13 ) != 0
|| strcmp ( V_89 -> V_37 , V_62 -> V_13 ) != 0
|| V_96 != V_89 -> V_30 )
continue;
V_96 += F_30 ( V_89 ) ;
F_61 ( V_60 , V_89 ) ;
V_48 = F_62 ( V_15 , V_15 -> V_30 , V_96 - V_15 -> V_30 ) ;
F_60 ( V_11 , V_60 , V_15 , L_22 , V_48 ) ;
if ( V_48 )
return V_48 ;
V_15 -> V_29 |= V_69 ;
goto V_84;
}
return 0 ;
}
static int F_70 ( struct V_1 * V_2 , void * V_19 )
{
struct V_102 * V_102 = V_19 ;
struct V_11 * V_11 ;
struct V_61 V_62 ;
int V_67 ;
if ( ! F_19 ( V_2 ) )
return 0 ;
V_11 = F_8 ( V_2 ) ;
if ( V_11 -> V_77 == 0 )
return 0 ;
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
strcat ( V_62 . V_13 , L_15 ) ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
T_4 V_73 , V_103 = 0 ;
if ( V_57 -> V_102 != V_102 )
continue;
V_73 = F_71 ( V_11 , V_57 , & V_103 ) ;
if ( V_73 == 0 )
return 0 ;
V_103 = F_67 ( V_11 , V_57 , & V_62 , V_73 ) ;
F_50 ( & V_11 -> V_2 , V_103 ,
L_23 ,
( unsigned long long ) V_73 - V_103 ,
( unsigned long long ) V_73 ) ;
return V_103 ? - V_49 : 0 ;
}
return 0 ;
}
static void F_72 ( struct V_26 * V_26 ,
struct V_57 * V_57 )
{
struct V_59 * V_60 = F_42 ( V_57 ) ;
struct V_64 * V_15 , * V_104 ;
F_73 (ndd, res, _res)
if ( strcmp ( V_15 -> V_37 , L_15 ) == 0 )
F_61 ( V_60 , V_15 ) ;
}
static int F_74 ( struct V_26 * V_26 ,
struct V_57 * V_57 )
{
struct V_102 * V_102 = V_57 -> V_102 ;
int V_48 ;
V_48 = F_21 ( & V_26 -> V_2 , V_102 ,
F_70 ) ;
if ( V_48 )
F_72 ( V_26 , V_57 ) ;
return V_48 ;
}
static int F_75 ( struct V_11 * V_11 ,
struct V_61 * V_62 , T_4 V_73 )
{
struct V_26 * V_26 = F_23 ( & V_11 -> V_2 ) ;
bool V_79 = strncmp ( V_62 -> V_13 , L_16 , 4 ) == 0 ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
T_4 V_103 = V_73 ;
int V_48 , V_105 ;
for ( V_105 = V_79 ; V_105 < 2 ; V_105 ++ ) {
bool V_106 = V_105 == 0 ;
if ( V_106 ) {
V_48 = F_74 ( V_26 , V_57 ) ;
if ( V_48 )
return V_48 ;
}
V_103 = F_67 ( V_11 , V_57 ,
V_62 , V_103 ) ;
if ( V_106 )
F_72 ( V_26 , V_57 ) ;
if ( V_103 == 0 )
break;
}
F_50 ( & V_11 -> V_2 , V_103 ,
L_24 ,
( unsigned long long ) V_73 - V_103 ,
( unsigned long long ) V_73 ) ;
if ( V_103 )
return - V_49 ;
V_48 = F_69 ( V_11 , V_57 , V_62 ) ;
if ( V_48 )
return V_48 ;
}
return 0 ;
}
static void F_76 ( struct V_11 * V_11 ,
struct V_5 * V_6 , T_4 V_63 )
{
struct V_64 * V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_30 = V_11 -> V_107 ;
V_15 -> V_96 = V_11 -> V_107 + V_63 - 1 ;
}
static bool F_77 ( const T_1 * V_8 , struct V_1 * V_2 , const char * V_108 )
{
if ( ! V_8 ) {
F_56 ( V_2 , L_25 , V_108 ) ;
return true ;
}
return false ;
}
static T_2 F_78 ( struct V_1 * V_2 , unsigned long long V_109 )
{
T_4 V_110 = 0 , V_86 = 0 ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_57 * V_57 ;
struct V_59 * V_60 ;
struct V_61 V_62 ;
T_5 V_29 = 0 , V_111 ;
T_1 * V_8 = NULL ;
int V_48 , V_67 ;
if ( V_2 -> V_50 || F_37 ( V_2 ) -> V_39 )
return - V_25 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_29 = V_65 ;
}
if ( F_77 ( V_8 , V_2 , V_72 ) )
return - V_49 ;
if ( V_11 -> V_77 == 0 ) {
F_56 ( V_2 , L_26 , V_72 ) ;
return - V_49 ;
}
F_79 ( V_109 , V_112 * V_11 -> V_77 , & V_111 ) ;
if ( V_111 ) {
F_56 ( V_2 , L_27 , V_109 ,
( V_112 * V_11 -> V_77 ) / V_113 ) ;
return - V_54 ;
}
F_43 ( & V_62 , V_8 , V_29 ) ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
V_57 = & V_11 -> V_58 [ V_67 ] ;
V_60 = F_42 ( V_57 ) ;
if ( ! V_60 )
return - V_49 ;
V_110 += F_80 ( V_60 , & V_62 ) ;
}
V_86 = F_81 ( V_11 ) ;
if ( V_109 > V_86 + V_110 )
return - V_114 ;
if ( V_109 == V_110 )
return 0 ;
V_109 = F_82 ( V_109 , V_11 -> V_77 ) ;
V_110 = F_82 ( V_110 , V_11 -> V_77 ) ;
if ( V_109 < V_110 )
V_48 = F_63 ( V_11 , & V_62 ,
V_110 - V_109 ) ;
else
V_48 = F_75 ( V_11 , & V_62 , V_109 - V_110 ) ;
if ( V_48 )
return V_48 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_76 ( V_11 , V_6 ,
V_109 * V_11 -> V_77 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( V_109 == 0 && V_11 -> V_115 != V_2
&& ! V_10 -> V_56 . V_39 )
F_83 ( V_2 , V_116 ) ;
}
return V_48 ;
}
static T_2 F_84 ( struct V_1 * V_2 ,
struct V_41 * V_42 , const char * V_43 , T_3 V_44 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
unsigned long long V_109 ;
T_1 * * V_8 = NULL ;
int V_48 ;
V_48 = F_85 ( V_43 , 0 , & V_109 ) ;
if ( V_48 )
return V_48 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
V_48 = F_78 ( V_2 , V_109 ) ;
if ( V_48 >= 0 )
V_48 = F_49 ( V_11 , V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = & V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = & V_10 -> V_8 ;
}
if ( V_48 == 0 && V_109 == 0 && V_8 ) {
F_3 ( * V_8 ) ;
* V_8 = NULL ;
}
F_56 ( V_2 , L_28 , V_72 , V_109 , V_48 < 0
? L_29 : L_30 , V_48 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_48 < 0 ? V_48 : V_44 ;
}
T_4 F_86 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = & V_36 -> V_2 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return F_30 ( & V_6 -> V_4 . V_15 ) ;
} else if ( F_11 ( V_2 ) ) {
return F_41 ( F_7 ( V_2 ) ) ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_30 ( & V_4 -> V_15 ) ;
} else
F_87 ( 1 , L_31 ) ;
return 0 ;
}
T_4 F_88 ( struct V_35 * V_36 )
{
T_4 V_63 ;
F_47 ( & V_36 -> V_2 ) ;
V_63 = F_86 ( V_36 ) ;
F_48 ( & V_36 -> V_2 ) ;
return V_63 ;
}
static T_2 F_89 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
return sprintf ( V_43 , L_32 , ( unsigned long long )
F_88 ( F_37 ( V_2 ) ) ) ;
}
static T_2 F_90 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
T_1 * V_8 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
} else
return - V_49 ;
if ( V_8 )
return sprintf ( V_43 , L_33 , V_8 ) ;
return sprintf ( V_43 , L_34 ) ;
}
static int F_91 ( struct V_11 * V_11 ,
struct V_1 * V_2 , T_1 * V_117 , T_1 * * V_118 )
{
T_5 V_29 = F_11 ( V_2 ) ? V_65 : 0 ;
struct V_61 V_119 ;
struct V_61 V_120 ;
int V_67 ;
if ( ! F_22 ( V_2 , V_117 ) )
return - V_54 ;
if ( * V_118 == NULL )
goto V_55;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
if ( V_57 -> V_121 )
return - V_25 ;
}
F_43 ( & V_119 , * V_118 , V_29 ) ;
F_43 ( & V_120 , V_117 , V_29 ) ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
struct V_59 * V_60 = F_42 ( V_57 ) ;
struct V_64 * V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_119 . V_13 ) == 0 )
sprintf ( ( void * ) V_15 -> V_37 , L_6 ,
V_120 . V_13 ) ;
}
F_3 ( * V_118 ) ;
V_55:
* V_118 = V_117 ;
return 0 ;
}
static T_2 F_92 ( struct V_1 * V_2 ,
struct V_41 * V_42 , const char * V_43 , T_3 V_44 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_1 * V_8 = NULL ;
T_2 V_48 = 0 ;
T_1 * * V_122 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_122 = & V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_122 = & V_10 -> V_8 ;
} else
return - V_49 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( F_37 ( V_2 ) -> V_39 )
V_48 = - V_25 ;
if ( V_48 >= 0 )
V_48 = F_93 ( V_2 , & V_8 , V_43 , V_44 ) ;
if ( V_48 >= 0 )
V_48 = F_91 ( V_11 , V_2 , V_8 , V_122 ) ;
if ( V_48 >= 0 )
V_48 = F_49 ( V_11 , V_2 ) ;
else
F_3 ( V_8 ) ;
F_56 ( V_2 , L_35 , V_72 ,
V_48 , V_43 , V_43 [ V_44 - 1 ] == '\n' ? L_3 : L_34 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_48 < 0 ? V_48 : V_44 ;
}
static T_2 F_94 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_64 * V_15 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_15 = & V_6 -> V_4 . V_15 ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 = & V_4 -> V_15 ;
} else
return - V_49 ;
if ( F_30 ( V_15 ) == 0 )
return - V_49 ;
return sprintf ( V_43 , L_36 , ( unsigned long long ) V_15 -> V_30 ) ;
}
static T_2 F_95 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
return - V_49 ;
return F_96 ( V_10 -> V_68 , V_123 , V_43 ) ;
}
static T_2 F_97 ( struct V_1 * V_2 ,
struct V_41 * V_42 , const char * V_43 , T_3 V_44 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_2 V_48 = 0 ;
if ( ! F_11 ( V_2 ) )
return - V_49 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( F_37 ( V_2 ) -> V_39 )
V_48 = - V_25 ;
if ( V_48 >= 0 )
V_48 = F_98 ( V_2 , V_43 , & V_10 -> V_68 ,
V_123 ) ;
if ( V_48 >= 0 )
V_48 = F_49 ( V_11 , V_2 ) ;
F_56 ( V_2 , L_37 , V_72 ,
V_48 , V_48 < 0 ? L_38 : L_39 , V_43 ,
V_43 [ V_44 - 1 ] == '\n' ? L_3 : L_34 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_48 ? V_48 : V_44 ;
}
static T_2 F_99 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_61 V_62 ;
int V_66 = 0 , V_67 ;
T_1 * V_8 = NULL ;
T_5 V_29 = 0 ;
F_47 ( V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
V_29 = 0 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_29 = V_65 ;
}
if ( ! V_8 )
goto V_55;
F_43 ( & V_62 , V_8 , V_29 ) ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
struct V_59 * V_60 = F_42 ( V_57 ) ;
struct V_64 * V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_62 . V_13 ) == 0 )
V_66 ++ ;
}
V_55:
F_48 ( V_2 ) ;
return sprintf ( V_43 , L_5 , V_66 ) ;
}
static T_2 F_100 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_35 * V_36 = F_37 ( V_2 ) ;
T_2 V_48 ;
F_54 ( V_2 ) ;
V_48 = sprintf ( V_43 , L_10 , V_36 -> V_39 ? F_101 ( V_36 -> V_39 ) : L_3 ) ;
F_57 ( V_2 ) ;
return V_48 ;
}
static T_2 F_102 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
struct V_35 * V_36 = F_37 ( V_2 ) ;
struct V_1 * V_39 ;
char * V_124 ;
T_2 V_48 ;
F_54 ( V_2 ) ;
V_39 = V_36 -> V_39 ;
if ( V_39 && F_14 ( V_39 ) )
V_124 = L_40 ;
else if ( V_39 && F_16 ( V_39 ) )
V_124 = L_41 ;
else if ( ! V_39 && F_26 ( V_2 ) )
V_124 = L_41 ;
else
V_124 = L_42 ;
V_48 = sprintf ( V_43 , L_10 , V_124 ) ;
F_57 ( V_2 ) ;
return V_48 ;
}
static T_2 F_103 ( struct V_1 * V_2 ,
struct V_41 * V_42 , const char * V_43 , T_3 V_44 )
{
bool V_125 ;
int V_48 = F_104 ( V_43 , & V_125 ) ;
if ( V_48 )
return V_48 ;
F_37 ( V_2 ) -> V_125 = V_125 ;
return V_44 ;
}
static T_2 F_105 ( struct V_1 * V_2 ,
struct V_41 * V_42 , char * V_43 )
{
return sprintf ( V_43 , L_5 , F_37 ( V_2 ) -> V_125 ) ;
}
static T_6 F_106 ( struct V_126 * V_127 ,
struct V_128 * V_129 , int V_73 )
{
struct V_1 * V_2 = F_107 ( V_127 , struct V_1 , V_127 ) ;
if ( V_129 == & V_130 . V_42 ) {
if ( F_11 ( V_2 ) )
return 0 ;
return V_129 -> V_124 ;
}
if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
if ( V_129 == & V_131 . V_42 )
return V_132 | V_133 ;
if ( F_10 ( V_2 ) && V_129 == & V_134 . V_42 )
return 0 ;
return V_129 -> V_124 ;
}
if ( V_129 == & V_135 . V_42 || V_129 == & V_131 . V_42
|| V_129 == & V_136 . V_42
|| V_129 == & V_137 . V_42
|| V_129 == & V_138 . V_42 )
return V_129 -> V_124 ;
return 0 ;
}
struct V_35 * F_108 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_14 ( V_2 ) ? F_15 ( V_2 ) : NULL ;
struct V_23 * V_23 = F_16 ( V_2 ) ? F_17 ( V_2 ) : NULL ;
struct V_35 * V_36 ;
T_4 V_63 ;
if ( V_22 || V_23 ) {
struct V_1 * V_139 = NULL ;
if ( V_22 ) {
V_139 = & V_22 -> V_2 ;
V_36 = V_22 -> V_36 ;
} else if ( V_23 ) {
V_139 = & V_23 -> V_2 ;
V_36 = V_23 -> V_36 ;
}
if ( ! V_36 || ! V_139 )
return F_109 ( - V_140 ) ;
F_54 ( & V_36 -> V_2 ) ;
F_57 ( & V_36 -> V_2 ) ;
if ( V_36 -> V_2 . V_50 ) {
F_56 ( & V_36 -> V_2 , L_43 ,
F_101 ( V_139 ) ) ;
return F_109 ( - V_25 ) ;
}
if ( F_50 ( & V_36 -> V_2 , V_36 -> V_39 != V_139 ,
L_44 ,
F_101 ( V_139 ) ,
F_101 ( V_36 -> V_39 ) ) )
return F_109 ( - V_49 ) ;
} else {
V_36 = F_37 ( V_2 ) ;
if ( V_36 -> V_39 ) {
F_56 ( V_2 , L_45 ,
F_101 ( V_36 -> V_39 ) ) ;
return F_109 ( - V_49 ) ;
}
}
V_63 = F_88 ( V_36 ) ;
if ( V_63 < V_141 ) {
F_56 ( & V_36 -> V_2 , L_46 ,
& V_63 , V_141 ) ;
return F_109 ( - V_140 ) ;
}
if ( F_10 ( & V_36 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_36 -> V_2 ) ;
if ( F_77 ( V_6 -> V_8 , & V_36 -> V_2 , V_72 ) )
return F_109 ( - V_140 ) ;
} else if ( F_11 ( & V_36 -> V_2 ) ) {
struct V_9 * V_10 ;
V_10 = F_7 ( & V_36 -> V_2 ) ;
if ( F_77 ( V_10 -> V_8 , & V_36 -> V_2 , V_72 ) )
return F_109 ( - V_140 ) ;
if ( ! V_10 -> V_68 ) {
F_56 ( & V_36 -> V_2 , L_47 ,
V_72 ) ;
return F_109 ( - V_140 ) ;
}
if ( ! F_46 ( V_10 ) )
return F_109 ( - V_140 ) ;
}
return V_36 ;
}
static struct V_1 * * F_110 ( struct V_11 * V_11 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 , * * V_142 ;
struct V_64 * V_15 ;
V_4 = F_40 ( sizeof( * V_4 ) , V_51 ) ;
if ( ! V_4 )
return NULL ;
V_142 = F_111 ( 2 , sizeof( struct V_1 * ) , V_51 ) ;
if ( ! V_142 ) {
F_3 ( V_4 ) ;
return NULL ;
}
V_2 = & V_4 -> V_56 . V_2 ;
V_2 -> type = & V_18 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_15 = & V_4 -> V_15 ;
V_15 -> V_37 = F_101 ( & V_11 -> V_2 ) ;
V_15 -> V_29 = V_143 ;
V_15 -> V_30 = V_11 -> V_107 ;
V_15 -> V_96 = V_15 -> V_30 + V_11 -> V_144 - 1 ;
V_142 [ 0 ] = V_2 ;
return V_142 ;
}
static bool F_112 ( struct V_11 * V_11 , T_1 * V_8 ,
T_7 V_145 , T_8 V_46 )
{
struct V_146 * V_71 = NULL ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
struct V_146 * V_147 ;
bool V_148 = false ;
int V_149 ;
F_113 (l, nd_label, nd_mapping->labels) {
T_7 V_150 = F_114 ( V_147 -> V_150 ) ;
T_8 V_151 = F_115 ( V_147 -> V_151 ) ;
T_8 V_152 = F_115 ( V_147 -> V_152 ) ;
if ( V_150 != V_145 )
continue;
if ( memcmp ( V_147 -> V_8 , V_8 , V_24 ) != 0 )
continue;
if ( V_148 ) {
F_56 ( F_42 ( V_57 ) -> V_2 ,
L_48 ,
V_72 ) ;
return false ;
}
V_148 = true ;
if ( V_152 != V_11 -> V_77 )
continue;
if ( V_151 != V_46 )
continue;
V_71 = V_147 ;
break;
}
if ( V_71 )
break;
}
return V_71 != NULL ;
}
static int F_116 ( struct V_11 * V_11 , T_1 * V_153 )
{
struct V_146 * V_154 = NULL ;
int V_67 ;
if ( ! V_153 )
return - V_140 ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
struct V_146 * V_147 ;
T_7 V_155 , V_156 , V_157 , V_158 ;
int V_149 ;
F_113 (l, nd_label, nd_mapping->labels)
if ( memcmp ( V_147 -> V_8 , V_153 , V_24 ) == 0 )
break;
if ( ! V_147 ) {
F_117 ( 1 ) ;
return - V_54 ;
}
V_154 = V_147 ;
V_155 = V_57 -> V_30 ;
V_156 = V_155 + V_57 -> V_63 ;
V_157 = F_114 ( V_154 -> V_100 ) ;
V_158 = V_157 + F_114 ( V_154 -> V_159 ) ;
if ( V_157 == V_155 && V_158 <= V_156 )
;
else
return - V_54 ;
V_57 -> V_121 [ 0 ] = V_154 ;
V_57 -> V_121 [ 1 ] = NULL ;
}
return 0 ;
}
static int F_118 ( struct V_11 * V_11 ,
struct V_5 * V_6 )
{
T_7 V_145 = F_119 ( V_11 ) ;
struct V_146 * V_147 ;
T_1 V_160 [ V_24 ] ;
T_4 V_63 = 0 ;
T_1 * V_153 = NULL ;
int V_48 = - V_140 , V_149 ;
T_8 V_67 ;
if ( V_145 == 0 )
return - V_49 ;
F_113 (l, nd_label, nd_region->mapping[0].labels) {
T_7 V_150 = F_114 ( V_147 -> V_150 ) ;
if ( V_150 != V_145 )
continue;
for ( V_67 = 0 ; V_11 -> V_77 ; V_67 ++ )
if ( ! F_112 ( V_11 , V_147 -> V_8 ,
V_145 , V_67 ) )
break;
if ( V_67 < V_11 -> V_77 ) {
V_48 = - V_54 ;
goto V_161;
} else if ( V_153 ) {
V_48 = - V_25 ;
goto V_161;
}
memcpy ( V_160 , V_147 -> V_8 , V_24 ) ;
V_153 = V_160 ;
}
V_48 = F_116 ( V_11 , V_153 ) ;
if ( V_48 )
goto V_161;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
struct V_146 * V_162 = V_57 -> V_121 [ 0 ] ;
V_63 += F_114 ( V_162 -> V_159 ) ;
if ( F_115 ( V_162 -> V_151 ) != 0 )
continue;
F_117 ( V_6 -> V_7 || V_6 -> V_8 ) ;
V_6 -> V_7 = F_38 ( ( void V_163 * ) V_162 -> V_37 ,
V_53 , V_51 ) ;
V_6 -> V_8 = F_38 ( ( void V_163 * ) V_162 -> V_8 ,
V_24 , V_51 ) ;
}
if ( ! V_6 -> V_7 || ! V_6 -> V_8 ) {
V_48 = - V_52 ;
goto V_161;
}
F_76 ( V_11 , V_6 , V_63 ) ;
return 0 ;
V_161:
switch ( V_48 ) {
case - V_54 :
F_56 ( & V_11 -> V_2 , L_49 , V_72 ) ;
break;
case - V_140 :
F_56 ( & V_11 -> V_2 , L_50 , V_72 ) ;
break;
default:
F_56 ( & V_11 -> V_2 , L_51 ,
V_72 , V_48 ) ;
break;
}
return V_48 ;
}
static struct V_1 * * F_120 ( struct V_11 * V_11 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 , * * V_142 ;
struct V_64 * V_15 ;
int V_48 ;
V_6 = F_40 ( sizeof( * V_6 ) , V_51 ) ;
if ( ! V_6 )
return NULL ;
V_2 = & V_6 -> V_4 . V_56 . V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_37 = F_101 ( & V_11 -> V_2 ) ;
V_15 -> V_29 = V_143 ;
V_48 = F_118 ( V_11 , V_6 ) ;
if ( V_48 == - V_140 ) {
int V_67 ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
F_3 ( V_57 -> V_121 ) ;
V_57 -> V_121 = NULL ;
}
F_76 ( V_11 , V_6 , 0 ) ;
V_48 = 0 ;
} else if ( V_48 )
goto V_161;
V_142 = F_111 ( 2 , sizeof( struct V_1 * ) , V_51 ) ;
if ( ! V_142 )
goto V_161;
V_142 [ 0 ] = V_2 ;
return V_142 ;
V_161:
F_4 ( & V_6 -> V_4 . V_56 . V_2 ) ;
return NULL ;
}
struct V_64 * F_121 ( struct V_11 * V_11 ,
struct V_59 * V_60 , struct V_9 * V_10 ,
T_4 V_30 )
{
struct V_61 V_62 ;
struct V_64 * V_15 ;
F_43 ( & V_62 , V_10 -> V_8 , V_65 ) ;
V_15 = F_122 ( V_10 -> V_15 ,
sizeof( void * ) * ( V_10 -> V_70 + 1 ) ,
V_51 ) ;
if ( ! V_15 )
return NULL ;
V_10 -> V_15 = (struct V_64 * * ) V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_62 . V_13 ) == 0
&& V_15 -> V_30 == V_30 ) {
V_10 -> V_15 [ V_10 -> V_70 ++ ] = V_15 ;
return V_15 ;
}
return NULL ;
}
static struct V_1 * F_123 ( struct V_11 * V_11 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
if ( ! F_20 ( & V_11 -> V_2 ) )
return NULL ;
V_10 = F_40 ( sizeof( * V_10 ) , V_51 ) ;
if ( ! V_10 )
return NULL ;
V_2 = & V_10 -> V_56 . V_2 ;
V_2 -> type = & V_17 ;
V_10 -> V_13 = F_124 ( & V_11 -> V_14 , 0 , 0 , V_51 ) ;
if ( V_10 -> V_13 < 0 ) {
F_3 ( V_10 ) ;
return NULL ;
}
F_125 ( V_2 , L_52 , V_11 -> V_13 , V_10 -> V_13 ) ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_2 -> V_164 = V_165 ;
return & V_10 -> V_56 . V_2 ;
}
void F_126 ( struct V_11 * V_11 )
{
F_117 ( ! F_25 ( & V_11 -> V_2 ) ) ;
V_11 -> V_115 = F_123 ( V_11 ) ;
if ( ! V_11 -> V_115 )
F_127 ( & V_11 -> V_2 , L_53 ) ;
else
F_128 ( V_11 -> V_115 ) ;
}
void F_129 ( struct V_11 * V_11 )
{
F_117 ( ! F_25 ( & V_11 -> V_2 ) ) ;
V_11 -> V_166 = F_130 ( V_11 ) ;
if ( ! V_11 -> V_166 )
F_127 ( & V_11 -> V_2 , L_54 ) ;
}
void F_131 ( struct V_11 * V_11 )
{
F_117 ( ! F_25 ( & V_11 -> V_2 ) ) ;
V_11 -> V_167 = F_132 ( V_11 ) ;
if ( ! V_11 -> V_167 )
F_127 ( & V_11 -> V_2 , L_55 ) ;
}
static struct V_1 * * F_133 ( struct V_11 * V_11 )
{
struct V_57 * V_57 = & V_11 -> V_58 [ 0 ] ;
struct V_146 * V_147 ;
struct V_1 * V_2 , * * V_142 = NULL ;
struct V_9 * V_10 ;
struct V_59 * V_60 ;
int V_67 , V_149 , V_66 = 0 ;
struct V_64 * V_15 ;
if ( V_11 -> V_77 == 0 )
return NULL ;
V_60 = F_42 ( V_57 ) ;
F_113 (l, nd_label, nd_mapping->labels) {
T_5 V_29 = F_134 ( V_147 -> V_29 ) ;
char * V_37 [ V_53 ] ;
struct V_1 * * V_168 ;
if ( V_29 & V_65 )
;
else
continue;
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
V_10 = F_7 ( V_142 [ V_67 ] ) ;
if ( memcmp ( V_10 -> V_8 , V_147 -> V_8 ,
V_24 ) == 0 ) {
V_15 = F_121 ( V_11 , V_60 , V_10 ,
F_114 ( V_147 -> V_100 ) ) ;
if ( ! V_15 )
goto V_161;
F_60 ( V_11 , V_60 , V_15 , L_56 ,
F_101 ( & V_10 -> V_56 . V_2 ) ) ;
break;
}
}
if ( V_67 < V_66 )
continue;
V_168 = F_111 ( V_66 + 2 , sizeof( V_2 ) , V_51 ) ;
if ( ! V_168 )
goto V_161;
memcpy ( V_168 , V_142 , sizeof( V_2 ) * V_66 ) ;
F_3 ( V_142 ) ;
V_142 = V_168 ;
V_10 = F_40 ( sizeof( * V_10 ) , V_51 ) ;
if ( ! V_10 )
goto V_161;
V_2 = & V_10 -> V_56 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_12 = & V_11 -> V_2 ;
F_125 ( V_2 , L_52 , V_11 -> V_13 , V_66 ) ;
V_142 [ V_66 ++ ] = V_2 ;
V_10 -> V_13 = - 1 ;
V_10 -> V_68 = F_114 ( V_147 -> V_68 ) ;
V_10 -> V_8 = F_38 ( V_147 -> V_8 , V_24 ,
V_51 ) ;
if ( ! V_10 -> V_8 )
goto V_161;
memcpy ( V_37 , V_147 -> V_37 , V_53 ) ;
if ( V_37 [ 0 ] )
V_10 -> V_7 = F_38 ( V_37 , V_53 ,
V_51 ) ;
V_15 = F_121 ( V_11 , V_60 , V_10 ,
F_114 ( V_147 -> V_100 ) ) ;
if ( ! V_15 )
goto V_161;
F_60 ( V_11 , V_60 , V_15 , L_56 ,
F_101 ( & V_10 -> V_56 . V_2 ) ) ;
}
F_56 ( & V_11 -> V_2 , L_57 ,
V_72 , V_66 , V_66 == 1 ? L_3 : L_1 ) ;
if ( V_66 == 0 ) {
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
F_3 ( V_57 -> V_121 ) ;
V_57 -> V_121 = NULL ;
}
V_142 = F_111 ( 2 , sizeof( V_2 ) , V_51 ) ;
if ( ! V_142 )
goto V_161;
V_10 = F_40 ( sizeof( * V_10 ) , V_51 ) ;
if ( ! V_10 )
goto V_161;
V_2 = & V_10 -> V_56 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_142 [ V_66 ++ ] = V_2 ;
}
return V_142 ;
V_161:
for ( V_67 = 0 ; V_67 < V_66 ; V_67 ++ ) {
V_10 = F_7 ( V_142 [ V_67 ] ) ;
F_6 ( & V_10 -> V_56 . V_2 ) ;
}
F_3 ( V_142 ) ;
return NULL ;
}
static int F_135 ( struct V_11 * V_11 )
{
int V_67 ;
for ( V_67 = 0 ; V_67 < V_11 -> V_77 ; V_67 ++ ) {
struct V_57 * V_57 = & V_11 -> V_58 [ V_67 ] ;
struct V_59 * V_60 = F_42 ( V_57 ) ;
struct V_102 * V_102 = V_57 -> V_102 ;
int V_66 , V_105 ;
if ( ! V_60 ) {
if ( ( V_102 -> V_29 & V_169 ) == 0 )
return 0 ;
F_56 ( & V_11 -> V_2 , L_58 ,
F_101 ( & V_57 -> V_102 -> V_2 ) ) ;
return - V_49 ;
}
V_57 -> V_60 = V_60 ;
F_136 ( & V_102 -> V_170 ) ;
F_137 ( V_60 ) ;
V_66 = F_138 ( V_60 ) ;
F_56 ( V_60 -> V_2 , L_59 , V_72 , V_66 ) ;
if ( ! V_66 )
continue;
V_57 -> V_121 = F_111 ( V_66 + 1 , sizeof( void * ) ,
V_51 ) ;
if ( ! V_57 -> V_121 )
return - V_52 ;
for ( V_105 = 0 ; V_105 < V_66 ; V_105 ++ ) {
struct V_146 * V_171 ;
V_171 = F_139 ( V_60 , V_105 ) ;
V_57 -> V_121 [ V_105 ] = V_171 ;
}
}
return 0 ;
}
int F_140 ( struct V_11 * V_11 , int * V_161 )
{
struct V_1 * * V_142 = NULL ;
int V_67 , V_48 = 0 , type ;
* V_161 = 0 ;
F_47 ( & V_11 -> V_2 ) ;
V_48 = F_135 ( V_11 ) ;
if ( V_48 ) {
F_48 ( & V_11 -> V_2 ) ;
return V_48 ;
}
type = F_35 ( V_11 ) ;
switch ( type ) {
case V_172 :
V_142 = F_110 ( V_11 ) ;
break;
case V_173 :
V_142 = F_120 ( V_11 ) ;
break;
case V_174 :
V_142 = F_133 ( V_11 ) ;
break;
default:
break;
}
F_48 ( & V_11 -> V_2 ) ;
if ( ! V_142 )
return - V_140 ;
for ( V_67 = 0 ; V_142 [ V_67 ] ; V_67 ++ ) {
struct V_1 * V_2 = V_142 [ V_67 ] ;
int V_13 ;
if ( type == V_174 ) {
struct V_9 * V_10 ;
V_10 = F_7 ( V_2 ) ;
V_13 = F_124 ( & V_11 -> V_14 , 0 , 0 ,
V_51 ) ;
V_10 -> V_13 = V_13 ;
} else
V_13 = V_67 ;
if ( V_13 < 0 )
break;
F_125 ( V_2 , L_52 , V_11 -> V_13 , V_13 ) ;
V_2 -> V_164 = V_165 ;
F_128 ( V_2 ) ;
}
if ( V_67 )
V_11 -> V_115 = V_142 [ 0 ] ;
if ( V_142 [ V_67 ] ) {
int V_105 ;
for ( V_105 = V_67 ; V_142 [ V_105 ] ; V_105 ++ ) {
struct V_1 * V_2 = V_142 [ V_105 ] ;
F_141 ( V_2 ) ;
F_142 ( V_2 ) ;
}
* V_161 = V_105 - V_67 ;
if ( * V_161 == 0 )
V_48 = - V_140 ;
}
F_3 ( V_142 ) ;
if ( V_48 == - V_140 )
return V_48 ;
return V_67 ;
}

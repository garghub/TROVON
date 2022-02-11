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
if ( ! F_27 ( V_27 ) )
return false ;
if ( ! F_28 ( V_28 , & V_11 -> V_29 ) )
return false ;
if ( F_16 ( V_2 ) || F_14 ( V_2 ) )
return false ;
#ifdef F_29
return F_29 == V_30 ;
#else
return false ;
#endif
}
const char * F_30 ( struct V_31 * V_32 ,
char * V_33 )
{
struct V_11 * V_11 = F_8 ( V_32 -> V_2 . V_12 ) ;
const char * V_34 = NULL ;
if ( V_32 -> V_35 && F_14 ( V_32 -> V_35 ) )
V_34 = L_1 ;
if ( F_10 ( & V_32 -> V_2 ) || F_12 ( & V_32 -> V_2 ) ) {
sprintf ( V_33 , L_2 , V_11 -> V_13 , V_34 ? V_34 : L_3 ) ;
} else if ( F_11 ( & V_32 -> V_2 ) ) {
struct V_9 * V_10 ;
V_10 = F_7 ( & V_32 -> V_2 ) ;
sprintf ( V_33 , L_4 , V_11 -> V_13 , V_10 -> V_13 ,
V_34 ? V_34 : L_3 ) ;
} else {
return NULL ;
}
return V_33 ;
}
const T_1 * F_31 ( struct V_1 * V_2 )
{
static const T_1 V_36 [ 16 ] ;
if ( ! V_2 )
return V_36 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
return V_10 -> V_8 ;
} else
return V_36 ;
}
static T_2 F_32 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
return sprintf ( V_39 , L_5 , F_33 ( V_11 ) ) ;
}
static T_2 F_34 ( struct V_1 * V_2 , const char * V_39 ,
const T_3 V_40 )
{
char * V_41 , * V_42 , * V_7 , * * V_43 ;
T_2 V_44 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_43 = & V_6 -> V_7 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_43 = & V_10 -> V_7 ;
} else
return - V_45 ;
if ( V_2 -> V_46 || F_35 ( V_2 ) -> V_35 )
return - V_25 ;
V_41 = F_36 ( V_39 , V_40 + 1 , V_47 ) ;
if ( ! V_41 )
return - V_48 ;
V_41 [ V_40 ] = '\0' ;
V_42 = F_37 ( V_41 ) ;
if ( strlen ( V_42 ) + 1 > V_49 ) {
V_44 = - V_50 ;
goto V_51;
}
V_7 = F_38 ( V_49 , V_47 ) ;
if ( ! V_7 ) {
V_44 = - V_48 ;
goto V_51;
}
F_3 ( * V_43 ) ;
* V_43 = V_7 ;
sprintf ( * V_43 , L_6 , V_42 ) ;
V_44 = V_40 ;
V_51:
F_3 ( V_41 ) ;
return V_44 ;
}
static T_4 F_39 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 -> V_52 . V_2 . V_12 ) ;
struct V_53 * V_53 = & V_11 -> V_54 [ 0 ] ;
struct V_55 * V_56 = F_40 ( V_53 ) ;
struct V_57 V_58 ;
T_4 V_59 = 0 ;
struct V_60 * V_15 ;
if ( ! V_10 -> V_8 )
return 0 ;
F_41 ( & V_58 , V_10 -> V_8 , V_61 ) ;
F_42 (ndd, res)
if ( strcmp ( V_15 -> V_33 , V_58 . V_13 ) == 0 )
V_59 += F_43 ( V_15 ) ;
return V_59 ;
}
static bool F_44 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 -> V_52 . V_2 . V_12 ) ;
struct V_53 * V_53 = & V_11 -> V_54 [ 0 ] ;
struct V_55 * V_56 = F_40 ( V_53 ) ;
struct V_57 V_58 ;
struct V_60 * V_15 ;
int V_62 , V_63 ;
if ( ! V_10 -> V_8 || ! V_10 -> V_64 || ! V_56 )
return false ;
V_62 = 0 ;
F_41 ( & V_58 , V_10 -> V_8 , V_61 ) ;
F_42 (ndd, res) {
if ( strcmp ( V_15 -> V_33 , V_58 . V_13 ) != 0 )
continue;
if ( V_15 -> V_29 & V_65 )
return false ;
V_62 ++ ;
}
if ( V_62 != V_10 -> V_66 )
return false ;
for ( V_63 = 0 ; V_63 < V_10 -> V_66 ; V_63 ++ ) {
struct V_60 * V_67 = NULL ;
F_42 (ndd, res)
if ( V_15 == V_10 -> V_15 [ V_63 ] ) {
V_67 = V_15 ;
break;
}
if ( ! V_67 )
return false ;
}
return true ;
}
T_4 F_45 ( struct V_9 * V_10 )
{
T_4 V_59 ;
F_46 ( & V_10 -> V_52 . V_2 ) ;
V_59 = F_44 ( V_10 ) ;
F_47 ( & V_10 -> V_52 . V_2 ) ;
return V_59 ;
}
static int F_48 ( struct V_11 * V_11 ,
struct V_1 * V_2 )
{
F_49 ( V_2 , V_2 -> V_46 || F_35 ( V_2 ) -> V_35 ,
L_7 ) ;
if ( V_2 -> V_46 || F_35 ( V_2 ) -> V_35 )
return 0 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_4 V_59 = F_43 ( & V_6 -> V_4 . V_15 ) ;
if ( V_59 == 0 && V_6 -> V_8 )
;
else if ( ! V_6 -> V_8 )
return 0 ;
return F_50 ( V_11 , V_6 , V_59 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
T_4 V_59 = F_39 ( V_10 ) ;
if ( V_59 == 0 && V_10 -> V_8 )
;
else if ( ! V_10 -> V_8 || ! V_10 -> V_64 )
return 0 ;
return F_51 ( V_11 , V_10 , V_59 ) ;
} else
return - V_45 ;
}
static T_2 F_52 ( struct V_1 * V_2 ,
struct V_37 * V_38 , const char * V_39 , T_3 V_40 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_2 V_44 ;
F_53 ( V_2 ) ;
F_46 ( V_2 ) ;
F_54 ( V_2 ) ;
V_44 = F_34 ( V_2 , V_39 , V_40 ) ;
if ( V_44 >= 0 )
V_44 = F_48 ( V_11 , V_2 ) ;
F_55 ( V_2 , L_8 , V_68 , V_44 < 0 ? L_9 : L_3 , V_44 ) ;
F_47 ( V_2 ) ;
F_56 ( V_2 ) ;
return V_44 < 0 ? V_44 : V_40 ;
}
static T_2 F_57 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
char * V_43 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_43 = V_6 -> V_7 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_43 = V_10 -> V_7 ;
} else
return - V_45 ;
return sprintf ( V_39 , L_10 , V_43 ? V_43 : L_3 ) ;
}
static int F_58 ( struct V_11 * V_11 ,
struct V_53 * V_53 , struct V_57 * V_58 ,
T_4 V_69 )
{
bool V_70 = strncmp ( V_58 -> V_13 , L_11 , 3 ) == 0 ;
struct V_55 * V_56 = F_40 ( V_53 ) ;
int V_44 = 0 ;
while ( V_69 ) {
struct V_60 * V_15 , * V_71 ;
T_4 V_72 ;
V_71 = NULL ;
F_42 (ndd, res)
if ( strcmp ( V_15 -> V_33 , V_58 -> V_13 ) == 0 )
V_71 = V_15 ;
V_15 = V_71 ;
if ( ! V_15 )
return 0 ;
if ( V_69 >= F_43 ( V_15 ) ) {
V_69 -= F_43 ( V_15 ) ;
F_59 ( V_11 , V_56 , V_15 , L_12 , V_44 ) ;
F_60 ( V_56 , V_15 ) ;
continue;
}
if ( V_70 )
V_72 = V_15 -> V_73 + V_69 ;
else
V_72 = V_15 -> V_73 ;
V_44 = F_61 ( V_15 , V_72 , F_43 ( V_15 ) - V_69 ) ;
if ( V_44 == 0 )
V_15 -> V_29 |= V_65 ;
F_59 ( V_11 , V_56 , V_15 , L_13 , V_44 ) ;
break;
}
return V_44 ;
}
static int F_62 ( struct V_11 * V_11 ,
struct V_57 * V_58 , T_4 V_69 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
int V_44 ;
V_44 = F_58 ( V_11 , V_53 , V_58 , V_69 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static T_4 F_63 ( struct V_57 * V_58 ,
struct V_11 * V_11 , struct V_53 * V_53 ,
T_4 V_69 )
{
bool V_70 = strncmp ( V_58 -> V_13 , L_11 , 3 ) == 0 ;
struct V_55 * V_56 = F_40 ( V_53 ) ;
T_4 V_75 ;
struct V_60 * V_15 ;
int V_44 = 0 ;
if ( V_70 )
V_75 = V_53 -> V_73 + V_53 -> V_59 - V_69 ;
else
V_75 = V_53 -> V_73 ;
V_15 = F_64 ( V_56 , V_58 , V_75 , V_69 ) ;
if ( ! V_15 )
V_44 = - V_25 ;
F_59 ( V_11 , V_56 , V_15 , L_14 , V_44 ) ;
return V_44 ? V_69 : 0 ;
}
static bool F_65 ( bool V_76 , bool V_77 ,
struct V_57 * V_58 , struct V_60 * V_15 )
{
if ( V_77 || ! V_76 )
return true ;
if ( ! V_15 || strcmp ( V_15 -> V_33 , V_58 -> V_13 ) == 0 )
return true ;
return false ;
}
static T_4 F_66 ( struct V_11 * V_11 ,
struct V_53 * V_53 , struct V_57 * V_58 ,
T_4 V_69 )
{
T_4 V_78 = V_53 -> V_73 + V_53 -> V_59 - 1 ;
bool V_77 = strcmp ( V_58 -> V_13 , L_15 ) == 0 ;
bool V_76 = strncmp ( V_58 -> V_13 , L_16 , 4 ) == 0 ;
struct V_55 * V_56 = F_40 ( V_53 ) ;
const T_4 V_79 = V_69 ;
struct V_60 * V_15 ;
int V_80 ;
V_81:
V_80 = 0 ;
F_42 (ndd, res) {
T_4 V_82 , V_83 = 0 , V_84 , V_85 ;
struct V_60 * V_86 = V_15 -> V_87 , * V_88 = NULL ;
enum V_89 V_90 = V_91 ;
const char * V_92 ;
int V_44 = 0 ;
if ( V_15 -> V_73 > V_78 )
continue;
if ( V_15 -> V_93 < V_53 -> V_73 )
continue;
if ( ! V_80 ++ && V_15 -> V_73 > V_53 -> V_73 ) {
V_84 = V_53 -> V_73 ;
V_83 = V_15 -> V_73 - V_84 ;
if ( F_65 ( V_76 , V_77 , V_58 , NULL ) )
V_90 = V_94 ;
}
if ( ! V_90 && V_86 ) {
V_84 = V_15 -> V_73 + F_43 ( V_15 ) ;
V_85 = F_67 ( V_78 , V_86 -> V_73 - 1 ) ;
if ( F_65 ( V_76 , V_77 , V_58 , V_15 )
&& V_84 < V_85 ) {
V_83 = V_85 + 1 - V_84 ;
V_90 = V_95 ;
}
}
if ( ! V_90 && ! V_86 ) {
V_84 = V_15 -> V_73 + F_43 ( V_15 ) ;
V_85 = V_78 ;
if ( F_65 ( V_76 , V_77 , V_58 , V_15 )
&& V_84 < V_85 ) {
V_83 = V_85 + 1 - V_84 ;
V_90 = V_96 ;
}
}
if ( ! V_90 || ! V_83 )
continue;
V_82 = F_67 ( V_83 , V_69 ) ;
switch ( V_90 ) {
case V_94 :
if ( strcmp ( V_15 -> V_33 , V_58 -> V_13 ) == 0 ) {
if ( V_76 && ! V_77 )
return V_69 ;
V_44 = F_61 ( V_15 , V_15 -> V_73 - V_82 ,
F_43 ( V_15 ) + V_82 ) ;
V_92 = L_17 ;
} else
V_92 = L_18 ;
break;
case V_95 :
if ( strcmp ( V_86 -> V_33 , V_58 -> V_13 ) == 0 ) {
if ( V_76 && ! V_77 )
return V_69 ;
V_44 = F_61 ( V_86 , V_86 -> V_73
- V_82 , F_43 ( V_86 )
+ V_82 ) ;
V_88 = V_86 ;
V_92 = L_19 ;
} else if ( strcmp ( V_15 -> V_33 , V_58 -> V_13 ) == 0 ) {
V_92 = L_20 ;
} else
V_92 = L_18 ;
break;
case V_96 :
if ( strcmp ( V_15 -> V_33 , V_58 -> V_13 ) == 0 )
V_92 = L_20 ;
else
V_92 = L_18 ;
break;
default:
return V_69 ;
}
if ( strcmp ( V_92 , L_18 ) == 0 ) {
if ( ! V_76 )
V_84 += V_83 - V_82 ;
else if ( ! V_77 && V_84 != V_53 -> V_73 )
return V_69 ;
V_88 = F_64 ( V_56 , V_58 ,
V_84 , V_82 ) ;
if ( ! V_88 )
V_44 = - V_25 ;
} else if ( strcmp ( V_92 , L_20 ) == 0 ) {
V_44 = F_61 ( V_15 , V_15 -> V_73 , F_43 ( V_15 )
+ V_82 ) ;
if ( V_44 == 0 )
V_15 -> V_29 |= V_65 ;
}
if ( ! V_88 )
V_88 = V_15 ;
F_59 ( V_11 , V_56 , V_88 , L_21 ,
V_92 , V_90 , V_44 ) ;
if ( V_44 )
return V_69 ;
V_69 -= V_82 ;
if ( V_69 ) {
goto V_81;
} else
return 0 ;
}
if ( ( V_76 || ! V_56 -> V_97 . V_98 ) && V_69 == V_79 )
return F_63 ( V_58 , V_11 , V_53 , V_69 ) ;
return V_69 ;
}
static int F_68 ( struct V_11 * V_11 ,
struct V_53 * V_53 , struct V_57 * V_58 )
{
struct V_55 * V_56 = F_40 ( V_53 ) ;
struct V_60 * V_15 ;
if ( strncmp ( L_16 , V_58 -> V_13 , 4 ) == 0 )
return 0 ;
V_81:
F_42 (ndd, res) {
int V_44 ;
struct V_60 * V_86 = V_15 -> V_87 ;
T_4 V_93 = V_15 -> V_73 + F_43 ( V_15 ) ;
if ( ! V_86 || strcmp ( V_15 -> V_33 , V_58 -> V_13 ) != 0
|| strcmp ( V_86 -> V_33 , V_58 -> V_13 ) != 0
|| V_93 != V_86 -> V_73 )
continue;
V_93 += F_43 ( V_86 ) ;
F_60 ( V_56 , V_86 ) ;
V_44 = F_61 ( V_15 , V_15 -> V_73 , V_93 - V_15 -> V_73 ) ;
F_59 ( V_11 , V_56 , V_15 , L_22 , V_44 ) ;
if ( V_44 )
return V_44 ;
V_15 -> V_29 |= V_65 ;
goto V_81;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , void * V_19 )
{
struct V_99 * V_99 = V_19 ;
struct V_11 * V_11 ;
struct V_57 V_58 ;
int V_63 ;
if ( ! F_19 ( V_2 ) )
return 0 ;
V_11 = F_8 ( V_2 ) ;
if ( V_11 -> V_74 == 0 )
return 0 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
strcat ( V_58 . V_13 , L_15 ) ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
T_4 V_69 , V_100 = 0 ;
if ( V_53 -> V_99 != V_99 )
continue;
V_69 = F_70 ( V_11 , V_53 , & V_100 ) ;
if ( V_69 == 0 )
return 0 ;
V_100 = F_66 ( V_11 , V_53 , & V_58 , V_69 ) ;
F_49 ( & V_11 -> V_2 , V_100 ,
L_23 ,
( unsigned long long ) V_69 - V_100 ,
( unsigned long long ) V_69 ) ;
return V_100 ? - V_45 : 0 ;
}
return 0 ;
}
static void F_71 ( struct V_26 * V_26 ,
struct V_53 * V_53 )
{
struct V_55 * V_56 = F_40 ( V_53 ) ;
struct V_60 * V_15 , * V_101 ;
F_72 (ndd, res, _res)
if ( strcmp ( V_15 -> V_33 , L_15 ) == 0 )
F_60 ( V_56 , V_15 ) ;
}
static int F_73 ( struct V_26 * V_26 ,
struct V_53 * V_53 )
{
struct V_99 * V_99 = V_53 -> V_99 ;
int V_44 ;
V_44 = F_21 ( & V_26 -> V_2 , V_99 ,
F_69 ) ;
if ( V_44 )
F_71 ( V_26 , V_53 ) ;
return V_44 ;
}
static int F_74 ( struct V_11 * V_11 ,
struct V_57 * V_58 , T_4 V_69 )
{
struct V_26 * V_26 = F_23 ( & V_11 -> V_2 ) ;
bool V_76 = strncmp ( V_58 -> V_13 , L_16 , 4 ) == 0 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
T_4 V_100 = V_69 ;
int V_44 , V_102 ;
for ( V_102 = V_76 ; V_102 < 2 ; V_102 ++ ) {
bool V_103 = V_102 == 0 ;
if ( V_103 ) {
V_44 = F_73 ( V_26 , V_53 ) ;
if ( V_44 )
return V_44 ;
}
V_100 = F_66 ( V_11 , V_53 ,
V_58 , V_100 ) ;
if ( V_103 )
F_71 ( V_26 , V_53 ) ;
if ( V_100 == 0 )
break;
}
F_49 ( & V_11 -> V_2 , V_100 ,
L_24 ,
( unsigned long long ) V_69 - V_100 ,
( unsigned long long ) V_69 ) ;
if ( V_100 )
return - V_45 ;
V_44 = F_68 ( V_11 , V_53 , V_58 ) ;
if ( V_44 )
return V_44 ;
}
return 0 ;
}
static void F_75 ( struct V_11 * V_11 ,
struct V_5 * V_6 , T_4 V_59 )
{
struct V_60 * V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_73 = V_11 -> V_104 ;
V_15 -> V_93 = V_11 -> V_104 + V_59 - 1 ;
}
static bool F_76 ( const T_1 * V_8 , struct V_1 * V_2 , const char * V_105 )
{
if ( ! V_8 ) {
F_55 ( V_2 , L_25 , V_105 ) ;
return true ;
}
return false ;
}
static T_2 F_77 ( struct V_1 * V_2 , unsigned long long V_106 )
{
T_4 V_107 = 0 , V_83 = 0 ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_53 * V_53 ;
struct V_55 * V_56 ;
struct V_57 V_58 ;
T_5 V_29 = 0 , V_108 ;
T_1 * V_8 = NULL ;
int V_44 , V_63 ;
if ( V_2 -> V_46 || F_35 ( V_2 ) -> V_35 )
return - V_25 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_29 = V_61 ;
}
if ( F_76 ( V_8 , V_2 , V_68 ) )
return - V_45 ;
if ( V_11 -> V_74 == 0 ) {
F_55 ( V_2 , L_26 , V_68 ) ;
return - V_45 ;
}
F_78 ( V_106 , V_109 * V_11 -> V_74 , & V_108 ) ;
if ( V_108 ) {
F_55 ( V_2 , L_27 , V_106 ,
( V_109 * V_11 -> V_74 ) / V_110 ) ;
return - V_50 ;
}
F_41 ( & V_58 , V_8 , V_29 ) ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
V_53 = & V_11 -> V_54 [ V_63 ] ;
V_56 = F_40 ( V_53 ) ;
if ( ! V_56 )
return - V_45 ;
V_107 += F_79 ( V_56 , & V_58 ) ;
}
V_83 = F_80 ( V_11 ) ;
if ( V_106 > V_83 + V_107 )
return - V_111 ;
if ( V_106 == V_107 )
return 0 ;
V_106 = F_81 ( V_106 , V_11 -> V_74 ) ;
V_107 = F_81 ( V_107 , V_11 -> V_74 ) ;
if ( V_106 < V_107 )
V_44 = F_62 ( V_11 , & V_58 ,
V_107 - V_106 ) ;
else
V_44 = F_74 ( V_11 , & V_58 , V_106 - V_107 ) ;
if ( V_44 )
return V_44 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_75 ( V_11 , V_6 ,
V_106 * V_11 -> V_74 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( V_106 == 0 && V_11 -> V_112 != V_2
&& ! V_10 -> V_52 . V_35 )
F_82 ( V_2 , V_113 ) ;
}
return V_44 ;
}
static T_2 F_83 ( struct V_1 * V_2 ,
struct V_37 * V_38 , const char * V_39 , T_3 V_40 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
unsigned long long V_106 ;
T_1 * * V_8 = NULL ;
int V_44 ;
V_44 = F_84 ( V_39 , 0 , & V_106 ) ;
if ( V_44 )
return V_44 ;
F_53 ( V_2 ) ;
F_46 ( V_2 ) ;
F_54 ( V_2 ) ;
V_44 = F_77 ( V_2 , V_106 ) ;
if ( V_44 >= 0 )
V_44 = F_48 ( V_11 , V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = & V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = & V_10 -> V_8 ;
}
if ( V_44 == 0 && V_106 == 0 && V_8 ) {
F_3 ( * V_8 ) ;
* V_8 = NULL ;
}
F_55 ( V_2 , L_28 , V_68 , V_106 , V_44 < 0
? L_29 : L_30 , V_44 ) ;
F_47 ( V_2 ) ;
F_56 ( V_2 ) ;
return V_44 < 0 ? V_44 : V_40 ;
}
T_4 F_85 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = & V_32 -> V_2 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return F_43 ( & V_6 -> V_4 . V_15 ) ;
} else if ( F_11 ( V_2 ) ) {
return F_39 ( F_7 ( V_2 ) ) ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_43 ( & V_4 -> V_15 ) ;
} else
F_86 ( 1 , L_31 ) ;
return 0 ;
}
T_4 F_87 ( struct V_31 * V_32 )
{
T_4 V_59 ;
F_46 ( & V_32 -> V_2 ) ;
V_59 = F_85 ( V_32 ) ;
F_47 ( & V_32 -> V_2 ) ;
return V_59 ;
}
static T_2 F_88 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
return sprintf ( V_39 , L_32 , ( unsigned long long )
F_87 ( F_35 ( V_2 ) ) ) ;
}
static T_2 F_89 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
T_1 * V_8 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
} else
return - V_45 ;
if ( V_8 )
return sprintf ( V_39 , L_33 , V_8 ) ;
return sprintf ( V_39 , L_34 ) ;
}
static int F_90 ( struct V_11 * V_11 ,
struct V_1 * V_2 , T_1 * V_114 , T_1 * * V_115 )
{
T_5 V_29 = F_11 ( V_2 ) ? V_61 : 0 ;
struct V_57 V_116 ;
struct V_57 V_117 ;
int V_63 ;
if ( ! F_22 ( V_2 , V_114 ) )
return - V_50 ;
if ( * V_115 == NULL )
goto V_51;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
if ( V_53 -> V_118 )
return - V_25 ;
}
F_41 ( & V_116 , * V_115 , V_29 ) ;
F_41 ( & V_117 , V_114 , V_29 ) ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
struct V_55 * V_56 = F_40 ( V_53 ) ;
struct V_60 * V_15 ;
F_42 (ndd, res)
if ( strcmp ( V_15 -> V_33 , V_116 . V_13 ) == 0 )
sprintf ( ( void * ) V_15 -> V_33 , L_6 ,
V_117 . V_13 ) ;
}
F_3 ( * V_115 ) ;
V_51:
* V_115 = V_114 ;
return 0 ;
}
static T_2 F_91 ( struct V_1 * V_2 ,
struct V_37 * V_38 , const char * V_39 , T_3 V_40 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_1 * V_8 = NULL ;
T_2 V_44 = 0 ;
T_1 * * V_119 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_119 = & V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_119 = & V_10 -> V_8 ;
} else
return - V_45 ;
F_53 ( V_2 ) ;
F_46 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( F_35 ( V_2 ) -> V_35 )
V_44 = - V_25 ;
if ( V_44 >= 0 )
V_44 = F_92 ( V_2 , & V_8 , V_39 , V_40 ) ;
if ( V_44 >= 0 )
V_44 = F_90 ( V_11 , V_2 , V_8 , V_119 ) ;
if ( V_44 >= 0 )
V_44 = F_48 ( V_11 , V_2 ) ;
else
F_3 ( V_8 ) ;
F_55 ( V_2 , L_35 , V_68 ,
V_44 , V_39 , V_39 [ V_40 - 1 ] == '\n' ? L_3 : L_34 ) ;
F_47 ( V_2 ) ;
F_56 ( V_2 ) ;
return V_44 < 0 ? V_44 : V_40 ;
}
static T_2 F_93 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_60 * V_15 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_15 = & V_6 -> V_4 . V_15 ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 = & V_4 -> V_15 ;
} else
return - V_45 ;
if ( F_43 ( V_15 ) == 0 )
return - V_45 ;
return sprintf ( V_39 , L_36 , ( unsigned long long ) V_15 -> V_73 ) ;
}
static T_2 F_94 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
return - V_45 ;
return F_95 ( V_10 -> V_64 , V_120 , V_39 ) ;
}
static T_2 F_96 ( struct V_1 * V_2 ,
struct V_37 * V_38 , const char * V_39 , T_3 V_40 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_2 V_44 = 0 ;
if ( ! F_11 ( V_2 ) )
return - V_45 ;
F_53 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( F_35 ( V_2 ) -> V_35 )
V_44 = - V_25 ;
if ( V_44 >= 0 )
V_44 = F_97 ( V_2 , V_39 , & V_10 -> V_64 ,
V_120 ) ;
if ( V_44 >= 0 )
V_44 = F_48 ( V_11 , V_2 ) ;
F_55 ( V_2 , L_37 , V_68 ,
V_44 , V_44 < 0 ? L_38 : L_39 , V_39 ,
V_39 [ V_40 - 1 ] == '\n' ? L_3 : L_34 ) ;
F_47 ( V_2 ) ;
F_56 ( V_2 ) ;
return V_44 ? V_44 : V_40 ;
}
static T_2 F_98 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_57 V_58 ;
int V_62 = 0 , V_63 ;
T_1 * V_8 = NULL ;
T_5 V_29 = 0 ;
F_46 ( V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
V_29 = 0 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_29 = V_61 ;
}
if ( ! V_8 )
goto V_51;
F_41 ( & V_58 , V_8 , V_29 ) ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
struct V_55 * V_56 = F_40 ( V_53 ) ;
struct V_60 * V_15 ;
F_42 (ndd, res)
if ( strcmp ( V_15 -> V_33 , V_58 . V_13 ) == 0 )
V_62 ++ ;
}
V_51:
F_47 ( V_2 ) ;
return sprintf ( V_39 , L_5 , V_62 ) ;
}
static T_2 F_99 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_31 * V_32 = F_35 ( V_2 ) ;
T_2 V_44 ;
F_53 ( V_2 ) ;
V_44 = sprintf ( V_39 , L_10 , V_32 -> V_35 ? F_100 ( V_32 -> V_35 ) : L_3 ) ;
F_56 ( V_2 ) ;
return V_44 ;
}
static T_2 F_101 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
struct V_31 * V_32 = F_35 ( V_2 ) ;
struct V_1 * V_35 ;
char * V_121 ;
T_2 V_44 ;
F_53 ( V_2 ) ;
V_35 = V_32 -> V_35 ;
if ( V_35 && F_14 ( V_35 ) )
V_121 = L_40 ;
else if ( V_35 && F_16 ( V_35 ) )
V_121 = L_41 ;
else if ( ! V_35 && F_26 ( V_2 ) )
V_121 = L_41 ;
else
V_121 = L_42 ;
V_44 = sprintf ( V_39 , L_10 , V_121 ) ;
F_56 ( V_2 ) ;
return V_44 ;
}
static T_2 F_102 ( struct V_1 * V_2 ,
struct V_37 * V_38 , const char * V_39 , T_3 V_40 )
{
bool V_122 ;
int V_44 = F_103 ( V_39 , & V_122 ) ;
if ( V_44 )
return V_44 ;
F_35 ( V_2 ) -> V_122 = V_122 ;
return V_40 ;
}
static T_2 F_104 ( struct V_1 * V_2 ,
struct V_37 * V_38 , char * V_39 )
{
return sprintf ( V_39 , L_5 , F_35 ( V_2 ) -> V_122 ) ;
}
static T_6 F_105 ( struct V_123 * V_124 ,
struct V_125 * V_126 , int V_69 )
{
struct V_1 * V_2 = F_106 ( V_124 , struct V_1 , V_124 ) ;
if ( V_126 == & V_127 . V_38 ) {
if ( F_11 ( V_2 ) )
return 0 ;
return V_126 -> V_121 ;
}
if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
if ( V_126 == & V_128 . V_38 )
return V_129 | V_130 ;
if ( F_10 ( V_2 ) && V_126 == & V_131 . V_38 )
return 0 ;
return V_126 -> V_121 ;
}
if ( V_126 == & V_132 . V_38 || V_126 == & V_128 . V_38
|| V_126 == & V_133 . V_38
|| V_126 == & V_134 . V_38
|| V_126 == & V_135 . V_38 )
return V_126 -> V_121 ;
return 0 ;
}
struct V_31 * F_107 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_14 ( V_2 ) ? F_15 ( V_2 ) : NULL ;
struct V_23 * V_23 = F_16 ( V_2 ) ? F_17 ( V_2 ) : NULL ;
struct V_31 * V_32 ;
T_4 V_59 ;
if ( V_22 || V_23 ) {
struct V_1 * V_136 = NULL ;
if ( V_22 ) {
V_136 = & V_22 -> V_2 ;
V_32 = V_22 -> V_32 ;
} else if ( V_23 ) {
V_136 = & V_23 -> V_2 ;
V_32 = V_23 -> V_32 ;
}
if ( ! V_32 || ! V_136 )
return F_108 ( - V_137 ) ;
F_53 ( & V_32 -> V_2 ) ;
F_56 ( & V_32 -> V_2 ) ;
if ( V_32 -> V_2 . V_46 ) {
F_55 ( & V_32 -> V_2 , L_43 ,
F_100 ( V_136 ) ) ;
return F_108 ( - V_25 ) ;
}
if ( F_49 ( & V_32 -> V_2 , V_32 -> V_35 != V_136 ,
L_44 ,
F_100 ( V_136 ) ,
F_100 ( V_32 -> V_35 ) ) )
return F_108 ( - V_45 ) ;
} else {
V_32 = F_35 ( V_2 ) ;
if ( V_32 -> V_35 ) {
F_55 ( V_2 , L_45 ,
F_100 ( V_32 -> V_35 ) ) ;
return F_108 ( - V_45 ) ;
}
}
V_59 = F_87 ( V_32 ) ;
if ( V_59 < V_138 ) {
F_55 ( & V_32 -> V_2 , L_46 ,
& V_59 , V_138 ) ;
return F_108 ( - V_137 ) ;
}
if ( F_10 ( & V_32 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_32 -> V_2 ) ;
if ( F_76 ( V_6 -> V_8 , & V_32 -> V_2 , V_68 ) )
return F_108 ( - V_137 ) ;
} else if ( F_11 ( & V_32 -> V_2 ) ) {
struct V_9 * V_10 ;
V_10 = F_7 ( & V_32 -> V_2 ) ;
if ( F_76 ( V_10 -> V_8 , & V_32 -> V_2 , V_68 ) )
return F_108 ( - V_137 ) ;
if ( ! V_10 -> V_64 ) {
F_55 ( & V_32 -> V_2 , L_47 ,
V_68 ) ;
return F_108 ( - V_137 ) ;
}
if ( ! F_45 ( V_10 ) )
return F_108 ( - V_137 ) ;
}
return V_32 ;
}
static struct V_1 * * F_109 ( struct V_11 * V_11 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 , * * V_139 ;
struct V_60 * V_15 ;
V_4 = F_38 ( sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return NULL ;
V_139 = F_110 ( 2 , sizeof( struct V_1 * ) , V_47 ) ;
if ( ! V_139 ) {
F_3 ( V_4 ) ;
return NULL ;
}
V_2 = & V_4 -> V_52 . V_2 ;
V_2 -> type = & V_18 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_15 = & V_4 -> V_15 ;
V_15 -> V_33 = F_100 ( & V_11 -> V_2 ) ;
V_15 -> V_29 = V_140 ;
V_15 -> V_73 = V_11 -> V_104 ;
V_15 -> V_93 = V_15 -> V_73 + V_11 -> V_141 - 1 ;
V_139 [ 0 ] = V_2 ;
return V_139 ;
}
static bool F_111 ( struct V_11 * V_11 , T_1 * V_8 ,
T_7 V_142 , T_8 V_42 )
{
struct V_143 * V_67 = NULL ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
struct V_143 * V_144 ;
bool V_145 = false ;
int V_146 ;
F_112 (l, nd_label, nd_mapping->labels) {
T_7 V_147 = F_113 ( V_144 -> V_147 ) ;
T_8 V_148 = F_114 ( V_144 -> V_148 ) ;
T_8 V_149 = F_114 ( V_144 -> V_149 ) ;
if ( V_147 != V_142 )
continue;
if ( memcmp ( V_144 -> V_8 , V_8 , V_24 ) != 0 )
continue;
if ( V_145 ) {
F_55 ( F_40 ( V_53 ) -> V_2 ,
L_48 ,
V_68 ) ;
return false ;
}
V_145 = true ;
if ( V_149 != V_11 -> V_74 )
continue;
if ( V_148 != V_42 )
continue;
V_67 = V_144 ;
break;
}
if ( V_67 )
break;
}
return V_67 != NULL ;
}
static int F_115 ( struct V_11 * V_11 , T_1 * V_150 )
{
struct V_143 * V_151 = NULL ;
int V_63 ;
if ( ! V_150 )
return - V_137 ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
struct V_143 * V_144 ;
T_7 V_152 , V_153 , V_154 , V_155 ;
int V_146 ;
F_112 (l, nd_label, nd_mapping->labels)
if ( memcmp ( V_144 -> V_8 , V_150 , V_24 ) == 0 )
break;
if ( ! V_144 ) {
F_116 ( 1 ) ;
return - V_50 ;
}
V_151 = V_144 ;
V_152 = V_53 -> V_73 ;
V_153 = V_152 + V_53 -> V_59 ;
V_154 = F_113 ( V_151 -> V_97 ) ;
V_155 = V_154 + F_113 ( V_151 -> V_156 ) ;
if ( V_154 == V_152 && V_155 <= V_153 )
;
else
return - V_50 ;
V_53 -> V_118 [ 0 ] = V_151 ;
V_53 -> V_118 [ 1 ] = NULL ;
}
return 0 ;
}
static int F_117 ( struct V_11 * V_11 ,
struct V_5 * V_6 )
{
T_7 V_142 = F_118 ( V_11 ) ;
struct V_143 * V_144 ;
T_1 V_157 [ V_24 ] ;
T_4 V_59 = 0 ;
T_1 * V_150 = NULL ;
int V_44 = - V_137 , V_146 ;
T_8 V_63 ;
if ( V_142 == 0 )
return - V_45 ;
F_112 (l, nd_label, nd_region->mapping[0].labels) {
T_7 V_147 = F_113 ( V_144 -> V_147 ) ;
if ( V_147 != V_142 )
continue;
for ( V_63 = 0 ; V_11 -> V_74 ; V_63 ++ )
if ( ! F_111 ( V_11 , V_144 -> V_8 ,
V_142 , V_63 ) )
break;
if ( V_63 < V_11 -> V_74 ) {
V_44 = - V_50 ;
goto V_158;
} else if ( V_150 ) {
V_44 = - V_25 ;
goto V_158;
}
memcpy ( V_157 , V_144 -> V_8 , V_24 ) ;
V_150 = V_157 ;
}
V_44 = F_115 ( V_11 , V_150 ) ;
if ( V_44 )
goto V_158;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
struct V_143 * V_159 = V_53 -> V_118 [ 0 ] ;
V_59 += F_113 ( V_159 -> V_156 ) ;
if ( F_114 ( V_159 -> V_148 ) != 0 )
continue;
F_116 ( V_6 -> V_7 || V_6 -> V_8 ) ;
V_6 -> V_7 = F_36 ( ( void V_160 * ) V_159 -> V_33 ,
V_49 , V_47 ) ;
V_6 -> V_8 = F_36 ( ( void V_160 * ) V_159 -> V_8 ,
V_24 , V_47 ) ;
}
if ( ! V_6 -> V_7 || ! V_6 -> V_8 ) {
V_44 = - V_48 ;
goto V_158;
}
F_75 ( V_11 , V_6 , V_59 ) ;
return 0 ;
V_158:
switch ( V_44 ) {
case - V_50 :
F_55 ( & V_11 -> V_2 , L_49 , V_68 ) ;
break;
case - V_137 :
F_55 ( & V_11 -> V_2 , L_50 , V_68 ) ;
break;
default:
F_55 ( & V_11 -> V_2 , L_51 ,
V_68 , V_44 ) ;
break;
}
return V_44 ;
}
static struct V_1 * * F_119 ( struct V_11 * V_11 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 , * * V_139 ;
struct V_60 * V_15 ;
int V_44 ;
V_6 = F_38 ( sizeof( * V_6 ) , V_47 ) ;
if ( ! V_6 )
return NULL ;
V_2 = & V_6 -> V_4 . V_52 . V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_33 = F_100 ( & V_11 -> V_2 ) ;
V_15 -> V_29 = V_140 ;
V_44 = F_117 ( V_11 , V_6 ) ;
if ( V_44 == - V_137 ) {
int V_63 ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
F_3 ( V_53 -> V_118 ) ;
V_53 -> V_118 = NULL ;
}
F_75 ( V_11 , V_6 , 0 ) ;
V_44 = 0 ;
} else if ( V_44 )
goto V_158;
V_139 = F_110 ( 2 , sizeof( struct V_1 * ) , V_47 ) ;
if ( ! V_139 )
goto V_158;
V_139 [ 0 ] = V_2 ;
return V_139 ;
V_158:
F_4 ( & V_6 -> V_4 . V_52 . V_2 ) ;
return NULL ;
}
struct V_60 * F_120 ( struct V_11 * V_11 ,
struct V_55 * V_56 , struct V_9 * V_10 ,
T_4 V_73 )
{
struct V_57 V_58 ;
struct V_60 * V_15 ;
F_41 ( & V_58 , V_10 -> V_8 , V_61 ) ;
V_15 = F_121 ( V_10 -> V_15 ,
sizeof( void * ) * ( V_10 -> V_66 + 1 ) ,
V_47 ) ;
if ( ! V_15 )
return NULL ;
V_10 -> V_15 = (struct V_60 * * ) V_15 ;
F_42 (ndd, res)
if ( strcmp ( V_15 -> V_33 , V_58 . V_13 ) == 0
&& V_15 -> V_73 == V_73 ) {
V_10 -> V_15 [ V_10 -> V_66 ++ ] = V_15 ;
return V_15 ;
}
return NULL ;
}
static struct V_1 * F_122 ( struct V_11 * V_11 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
if ( ! F_20 ( & V_11 -> V_2 ) )
return NULL ;
V_10 = F_38 ( sizeof( * V_10 ) , V_47 ) ;
if ( ! V_10 )
return NULL ;
V_2 = & V_10 -> V_52 . V_2 ;
V_2 -> type = & V_17 ;
V_10 -> V_13 = F_123 ( & V_11 -> V_14 , 0 , 0 , V_47 ) ;
if ( V_10 -> V_13 < 0 ) {
F_3 ( V_10 ) ;
return NULL ;
}
F_124 ( V_2 , L_52 , V_11 -> V_13 , V_10 -> V_13 ) ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_2 -> V_161 = V_162 ;
return & V_10 -> V_52 . V_2 ;
}
void F_125 ( struct V_11 * V_11 )
{
F_116 ( ! F_25 ( & V_11 -> V_2 ) ) ;
V_11 -> V_112 = F_122 ( V_11 ) ;
if ( ! V_11 -> V_112 )
F_126 ( & V_11 -> V_2 , L_53 ) ;
else
F_127 ( V_11 -> V_112 ) ;
}
void F_128 ( struct V_11 * V_11 )
{
F_116 ( ! F_25 ( & V_11 -> V_2 ) ) ;
V_11 -> V_163 = F_129 ( V_11 ) ;
if ( ! V_11 -> V_163 )
F_126 ( & V_11 -> V_2 , L_54 ) ;
}
void F_130 ( struct V_11 * V_11 )
{
F_116 ( ! F_25 ( & V_11 -> V_2 ) ) ;
V_11 -> V_164 = F_131 ( V_11 ) ;
if ( ! V_11 -> V_164 )
F_126 ( & V_11 -> V_2 , L_55 ) ;
}
static struct V_1 * * F_132 ( struct V_11 * V_11 )
{
struct V_53 * V_53 = & V_11 -> V_54 [ 0 ] ;
struct V_143 * V_144 ;
struct V_1 * V_2 , * * V_139 = NULL ;
struct V_9 * V_10 ;
struct V_55 * V_56 ;
int V_63 , V_146 , V_62 = 0 ;
struct V_60 * V_15 ;
if ( V_11 -> V_74 == 0 )
return NULL ;
V_56 = F_40 ( V_53 ) ;
F_112 (l, nd_label, nd_mapping->labels) {
T_5 V_29 = F_133 ( V_144 -> V_29 ) ;
char * V_33 [ V_49 ] ;
struct V_1 * * V_165 ;
if ( V_29 & V_61 )
;
else
continue;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
V_10 = F_7 ( V_139 [ V_63 ] ) ;
if ( memcmp ( V_10 -> V_8 , V_144 -> V_8 ,
V_24 ) == 0 ) {
V_15 = F_120 ( V_11 , V_56 , V_10 ,
F_113 ( V_144 -> V_97 ) ) ;
if ( ! V_15 )
goto V_158;
F_59 ( V_11 , V_56 , V_15 , L_56 ,
F_100 ( & V_10 -> V_52 . V_2 ) ) ;
break;
}
}
if ( V_63 < V_62 )
continue;
V_165 = F_110 ( V_62 + 2 , sizeof( V_2 ) , V_47 ) ;
if ( ! V_165 )
goto V_158;
memcpy ( V_165 , V_139 , sizeof( V_2 ) * V_62 ) ;
F_3 ( V_139 ) ;
V_139 = V_165 ;
V_10 = F_38 ( sizeof( * V_10 ) , V_47 ) ;
if ( ! V_10 )
goto V_158;
V_2 = & V_10 -> V_52 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_12 = & V_11 -> V_2 ;
F_124 ( V_2 , L_52 , V_11 -> V_13 , V_62 ) ;
V_139 [ V_62 ++ ] = V_2 ;
V_10 -> V_13 = - 1 ;
V_10 -> V_64 = F_113 ( V_144 -> V_64 ) ;
V_10 -> V_8 = F_36 ( V_144 -> V_8 , V_24 ,
V_47 ) ;
if ( ! V_10 -> V_8 )
goto V_158;
memcpy ( V_33 , V_144 -> V_33 , V_49 ) ;
if ( V_33 [ 0 ] )
V_10 -> V_7 = F_36 ( V_33 , V_49 ,
V_47 ) ;
V_15 = F_120 ( V_11 , V_56 , V_10 ,
F_113 ( V_144 -> V_97 ) ) ;
if ( ! V_15 )
goto V_158;
F_59 ( V_11 , V_56 , V_15 , L_56 ,
F_100 ( & V_10 -> V_52 . V_2 ) ) ;
}
F_55 ( & V_11 -> V_2 , L_57 ,
V_68 , V_62 , V_62 == 1 ? L_3 : L_1 ) ;
if ( V_62 == 0 ) {
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
F_3 ( V_53 -> V_118 ) ;
V_53 -> V_118 = NULL ;
}
V_139 = F_110 ( 2 , sizeof( V_2 ) , V_47 ) ;
if ( ! V_139 )
goto V_158;
V_10 = F_38 ( sizeof( * V_10 ) , V_47 ) ;
if ( ! V_10 )
goto V_158;
V_2 = & V_10 -> V_52 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_139 [ V_62 ++ ] = V_2 ;
}
return V_139 ;
V_158:
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
V_10 = F_7 ( V_139 [ V_63 ] ) ;
F_6 ( & V_10 -> V_52 . V_2 ) ;
}
F_3 ( V_139 ) ;
return NULL ;
}
static int F_134 ( struct V_11 * V_11 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_11 -> V_74 ; V_63 ++ ) {
struct V_53 * V_53 = & V_11 -> V_54 [ V_63 ] ;
struct V_55 * V_56 = F_40 ( V_53 ) ;
struct V_99 * V_99 = V_53 -> V_99 ;
int V_62 , V_102 ;
if ( ! V_56 ) {
if ( ( V_99 -> V_29 & V_166 ) == 0 )
return 0 ;
F_55 ( & V_11 -> V_2 , L_58 ,
F_100 ( & V_53 -> V_99 -> V_2 ) ) ;
return - V_45 ;
}
V_53 -> V_56 = V_56 ;
F_135 ( & V_99 -> V_167 ) ;
F_136 ( V_56 ) ;
V_62 = F_137 ( V_56 ) ;
F_55 ( V_56 -> V_2 , L_59 , V_68 , V_62 ) ;
if ( ! V_62 )
continue;
V_53 -> V_118 = F_110 ( V_62 + 1 , sizeof( void * ) ,
V_47 ) ;
if ( ! V_53 -> V_118 )
return - V_48 ;
for ( V_102 = 0 ; V_102 < V_62 ; V_102 ++ ) {
struct V_143 * V_168 ;
V_168 = F_138 ( V_56 , V_102 ) ;
V_53 -> V_118 [ V_102 ] = V_168 ;
}
}
return 0 ;
}
int F_139 ( struct V_11 * V_11 , int * V_158 )
{
struct V_1 * * V_139 = NULL ;
int V_63 , V_44 = 0 , type ;
* V_158 = 0 ;
F_46 ( & V_11 -> V_2 ) ;
V_44 = F_134 ( V_11 ) ;
if ( V_44 ) {
F_47 ( & V_11 -> V_2 ) ;
return V_44 ;
}
type = F_33 ( V_11 ) ;
switch ( type ) {
case V_169 :
V_139 = F_109 ( V_11 ) ;
break;
case V_170 :
V_139 = F_119 ( V_11 ) ;
break;
case V_171 :
V_139 = F_132 ( V_11 ) ;
break;
default:
break;
}
F_47 ( & V_11 -> V_2 ) ;
if ( ! V_139 )
return - V_137 ;
for ( V_63 = 0 ; V_139 [ V_63 ] ; V_63 ++ ) {
struct V_1 * V_2 = V_139 [ V_63 ] ;
int V_13 ;
if ( type == V_171 ) {
struct V_9 * V_10 ;
V_10 = F_7 ( V_2 ) ;
V_13 = F_123 ( & V_11 -> V_14 , 0 , 0 ,
V_47 ) ;
V_10 -> V_13 = V_13 ;
} else
V_13 = V_63 ;
if ( V_13 < 0 )
break;
F_124 ( V_2 , L_52 , V_11 -> V_13 , V_13 ) ;
V_2 -> V_161 = V_162 ;
F_127 ( V_2 ) ;
}
if ( V_63 )
V_11 -> V_112 = V_139 [ 0 ] ;
if ( V_139 [ V_63 ] ) {
int V_102 ;
for ( V_102 = V_63 ; V_139 [ V_102 ] ; V_102 ++ ) {
struct V_1 * V_2 = V_139 [ V_102 ] ;
F_140 ( V_2 ) ;
F_141 ( V_2 ) ;
}
* V_158 = V_102 - V_63 ;
if ( * V_158 == 0 )
V_44 = - V_137 ;
}
F_3 ( V_139 ) ;
if ( V_44 == - V_137 )
return V_44 ;
return V_63 ;
}

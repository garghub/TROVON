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
if ( F_19 ( V_2 ) || F_20 ( V_2 ) )
return F_21 ( V_2 , V_19 , F_13 ) ;
return 0 ;
}
bool F_22 ( struct V_1 * V_2 , T_1 * V_12 )
{
struct V_26 * V_26 = F_23 ( V_2 ) ;
if ( ! V_26 )
return false ;
F_24 ( ! F_25 ( & V_26 -> V_2 ) ) ;
if ( F_21 ( & V_26 -> V_2 , V_12 ,
F_18 ) != 0 )
return false ;
return true ;
}
bool F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
struct V_3 * V_4 ;
if ( ! F_27 ( V_27 ) )
return false ;
if ( ! F_28 ( V_28 , & V_7 -> V_29 ) )
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
struct V_7 * V_7 = F_6 ( V_36 -> V_2 . V_8 ) ;
const char * V_38 = NULL ;
if ( V_36 -> V_39 && F_14 ( V_36 -> V_39 ) )
V_38 = L_1 ;
if ( F_10 ( & V_36 -> V_2 ) || F_12 ( & V_36 -> V_2 ) ) {
int V_40 = 0 ;
if ( F_10 ( & V_36 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_36 -> V_2 ) ;
V_40 = V_6 -> V_9 ;
}
if ( V_40 )
sprintf ( V_37 , L_2 , V_7 -> V_9 , V_40 ,
V_38 ? V_38 : L_3 ) ;
else
sprintf ( V_37 , L_4 , V_7 -> V_9 ,
V_38 ? V_38 : L_3 ) ;
} else if ( F_11 ( & V_36 -> V_2 ) ) {
struct V_13 * V_14 ;
V_14 = F_9 ( & V_36 -> V_2 ) ;
sprintf ( V_37 , L_5 , V_7 -> V_9 , V_14 -> V_9 ,
V_38 ? V_38 : L_3 ) ;
} else {
return NULL ;
}
return V_37 ;
}
const T_1 * F_33 ( struct V_1 * V_2 )
{
static const T_1 V_41 [ 16 ] ;
if ( ! V_2 )
return V_41 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
return V_14 -> V_12 ;
} else
return V_41 ;
}
static T_2 F_34 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
return sprintf ( V_44 , L_6 , F_35 ( V_7 ) ) ;
}
static T_2 F_36 ( struct V_1 * V_2 , const char * V_44 ,
const T_3 V_45 )
{
char * V_46 , * V_47 , * V_11 , * * V_48 ;
T_2 V_49 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_48 = & V_6 -> V_11 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_48 = & V_14 -> V_11 ;
} else
return - V_50 ;
if ( V_2 -> V_51 || F_37 ( V_2 ) -> V_39 )
return - V_25 ;
V_46 = F_38 ( V_44 , V_45 + 1 , V_52 ) ;
if ( ! V_46 )
return - V_53 ;
V_46 [ V_45 ] = '\0' ;
V_47 = F_39 ( V_46 ) ;
if ( strlen ( V_47 ) + 1 > V_54 ) {
V_49 = - V_55 ;
goto V_56;
}
V_11 = F_40 ( V_54 , V_52 ) ;
if ( ! V_11 ) {
V_49 = - V_53 ;
goto V_56;
}
F_3 ( * V_48 ) ;
* V_48 = V_11 ;
sprintf ( * V_48 , L_7 , V_47 ) ;
V_49 = V_45 ;
V_56:
F_3 ( V_46 ) ;
return V_49 ;
}
static T_4 F_41 ( struct V_13 * V_14 )
{
struct V_7 * V_7 = F_6 ( V_14 -> V_57 . V_2 . V_8 ) ;
struct V_58 * V_58 = & V_7 -> V_59 [ 0 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_62 V_63 ;
T_4 V_64 = 0 ;
struct V_65 * V_15 ;
if ( ! V_14 -> V_12 )
return 0 ;
F_43 ( & V_63 , V_14 -> V_12 , V_66 ) ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_63 . V_9 ) == 0 )
V_64 += F_30 ( V_15 ) ;
return V_64 ;
}
static bool F_45 ( struct V_13 * V_14 )
{
struct V_7 * V_7 = F_6 ( V_14 -> V_57 . V_2 . V_8 ) ;
struct V_58 * V_58 = & V_7 -> V_59 [ 0 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_62 V_63 ;
struct V_65 * V_15 ;
int V_67 , V_68 ;
if ( ! V_14 -> V_12 || ! V_14 -> V_69 || ! V_61 )
return false ;
V_67 = 0 ;
F_43 ( & V_63 , V_14 -> V_12 , V_66 ) ;
F_44 (ndd, res) {
if ( strcmp ( V_15 -> V_37 , V_63 . V_9 ) != 0 )
continue;
if ( V_15 -> V_29 & V_70 )
return false ;
V_67 ++ ;
}
if ( V_67 != V_14 -> V_71 )
return false ;
for ( V_68 = 0 ; V_68 < V_14 -> V_71 ; V_68 ++ ) {
struct V_65 * V_72 = NULL ;
F_44 (ndd, res)
if ( V_15 == V_14 -> V_15 [ V_68 ] ) {
V_72 = V_15 ;
break;
}
if ( ! V_72 )
return false ;
}
return true ;
}
T_4 F_46 ( struct V_13 * V_14 )
{
T_4 V_64 ;
F_47 ( & V_14 -> V_57 . V_2 ) ;
V_64 = F_45 ( V_14 ) ;
F_48 ( & V_14 -> V_57 . V_2 ) ;
return V_64 ;
}
static int F_49 ( struct V_7 * V_7 ,
struct V_1 * V_2 )
{
F_50 ( V_2 , V_2 -> V_51 || F_37 ( V_2 ) -> V_39 ,
L_8 ) ;
if ( V_2 -> V_51 || F_37 ( V_2 ) -> V_39 )
return 0 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_4 V_64 = F_30 ( & V_6 -> V_4 . V_15 ) ;
if ( V_64 == 0 && V_6 -> V_12 )
;
else if ( ! V_6 -> V_12 )
return 0 ;
return F_51 ( V_7 , V_6 , V_64 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
T_4 V_64 = F_41 ( V_14 ) ;
if ( V_64 == 0 && V_14 -> V_12 )
;
else if ( ! V_14 -> V_12 || ! V_14 -> V_69 )
return 0 ;
return F_52 ( V_7 , V_14 , V_64 ) ;
} else
return - V_50 ;
}
static T_2 F_53 ( struct V_1 * V_2 ,
struct V_42 * V_43 , const char * V_44 , T_3 V_45 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
T_2 V_49 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
V_49 = F_36 ( V_2 , V_44 , V_45 ) ;
if ( V_49 >= 0 )
V_49 = F_49 ( V_7 , V_2 ) ;
F_56 ( V_2 , L_9 , V_73 , V_49 < 0 ? L_10 : L_3 , V_49 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_49 < 0 ? V_49 : V_45 ;
}
static T_2 F_58 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
char * V_48 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_48 = V_6 -> V_11 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_48 = V_14 -> V_11 ;
} else
return - V_50 ;
return sprintf ( V_44 , L_11 , V_48 ? V_48 : L_3 ) ;
}
static int F_59 ( struct V_7 * V_7 ,
struct V_58 * V_58 , struct V_62 * V_63 ,
T_4 V_74 )
{
bool V_75 = strncmp ( V_63 -> V_9 , L_12 , 3 ) == 0 ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
int V_49 = 0 ;
while ( V_74 ) {
struct V_65 * V_15 , * V_76 ;
T_4 V_77 ;
V_76 = NULL ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_63 -> V_9 ) == 0 )
V_76 = V_15 ;
V_15 = V_76 ;
if ( ! V_15 )
return 0 ;
if ( V_74 >= F_30 ( V_15 ) ) {
V_74 -= F_30 ( V_15 ) ;
F_60 ( V_7 , V_61 , V_15 , L_13 , V_49 ) ;
F_61 ( V_61 , V_15 ) ;
continue;
}
if ( V_75 )
V_77 = V_15 -> V_30 + V_74 ;
else
V_77 = V_15 -> V_30 ;
V_49 = F_62 ( V_15 , V_77 , F_30 ( V_15 ) - V_74 ) ;
if ( V_49 == 0 )
V_15 -> V_29 |= V_70 ;
F_60 ( V_7 , V_61 , V_15 , L_14 , V_49 ) ;
break;
}
return V_49 ;
}
static int F_63 ( struct V_7 * V_7 ,
struct V_62 * V_63 , T_4 V_74 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
int V_49 ;
V_49 = F_59 ( V_7 , V_58 , V_63 , V_74 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static T_4 F_64 ( struct V_62 * V_63 ,
struct V_7 * V_7 , struct V_58 * V_58 ,
T_4 V_74 )
{
bool V_75 = strncmp ( V_63 -> V_9 , L_12 , 3 ) == 0 ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
T_4 V_79 ;
struct V_65 * V_15 ;
int V_49 = 0 ;
if ( V_75 )
V_79 = V_58 -> V_30 + V_58 -> V_64 - V_74 ;
else
V_79 = V_58 -> V_30 ;
V_15 = F_65 ( V_61 , V_63 , V_79 , V_74 ) ;
if ( ! V_15 )
V_49 = - V_25 ;
F_60 ( V_7 , V_61 , V_15 , L_15 , V_49 ) ;
return V_49 ? V_74 : 0 ;
}
static void F_66 ( struct V_7 * V_7 , struct V_60 * V_61 ,
struct V_62 * V_63 , struct V_65 * V_80 ,
struct V_65 * V_81 , struct V_65 * V_82 ,
T_4 V_74 , struct V_65 * V_83 )
{
bool V_84 = strcmp ( V_63 -> V_9 , L_16 ) == 0 ;
bool V_85 = strncmp ( V_63 -> V_9 , L_17 , 4 ) == 0 ;
if ( V_83 -> V_30 >= V_83 -> V_86 )
goto V_87;
if ( V_84 )
return;
if ( ! V_85 ) {
struct V_58 * V_58 = & V_7 -> V_59 [ 0 ] ;
struct V_26 * V_26 ;
struct V_88 V_89 = {
. V_58 = V_58 ,
. V_90 = V_58 -> V_64 ,
. V_15 = V_83 ,
} ;
F_67 ( ! F_20 ( & V_7 -> V_2 ) ) ;
V_26 = F_23 ( & V_7 -> V_2 ) ;
F_21 ( & V_26 -> V_2 , & V_89 , V_91 ) ;
return;
}
if ( F_30 ( V_83 ) < V_74 )
goto V_87;
if ( ! V_82 )
return;
if ( V_83 -> V_30 == V_82 -> V_86 + 1
|| V_83 -> V_86 == V_82 -> V_30 - 1 )
return;
V_87:
V_83 -> V_86 = V_83 -> V_30 - 1 ;
}
static T_4 F_68 ( struct V_7 * V_7 ,
struct V_58 * V_58 , struct V_62 * V_63 ,
T_4 V_74 )
{
T_4 V_92 = V_58 -> V_30 + V_58 -> V_64 - 1 ;
bool V_85 = strncmp ( V_63 -> V_9 , L_17 , 4 ) == 0 ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_65 * V_15 , * V_82 = NULL , V_83 ;
const T_4 V_93 = V_74 ;
int V_94 ;
F_44 (ndd, res)
if ( strcmp ( V_63 -> V_9 , V_15 -> V_37 ) == 0 )
V_82 = V_15 ;
V_83 . V_30 = V_58 -> V_30 ;
V_83 . V_86 = V_92 ;
V_83 . V_37 = L_18 ;
V_95:
V_94 = 0 ;
F_44 (ndd, res) {
struct V_65 * V_81 = V_15 -> V_96 , * V_97 = NULL ;
T_4 V_98 , V_90 = 0 ;
enum V_99 V_100 = V_101 ;
const char * V_102 ;
int V_49 = 0 ;
if ( V_15 -> V_30 > V_92 )
continue;
if ( V_15 -> V_86 < V_58 -> V_30 )
continue;
if ( ! V_94 ++ && V_15 -> V_30 > V_58 -> V_30 ) {
V_83 . V_30 = V_58 -> V_30 ;
V_83 . V_86 = V_15 -> V_30 - 1 ;
F_66 ( V_7 , V_61 , V_63 , NULL , V_81 , V_82 ,
V_93 , & V_83 ) ;
V_90 = F_30 ( & V_83 ) ;
if ( V_90 )
V_100 = V_103 ;
}
if ( ! V_100 && V_81 ) {
V_83 . V_30 = V_15 -> V_30 + F_30 ( V_15 ) ;
V_83 . V_86 = F_69 ( V_92 , V_81 -> V_30 - 1 ) ;
F_66 ( V_7 , V_61 , V_63 , V_15 , V_81 , V_82 ,
V_93 , & V_83 ) ;
V_90 = F_30 ( & V_83 ) ;
if ( V_90 )
V_100 = V_104 ;
}
if ( ! V_100 && ! V_81 ) {
V_83 . V_30 = V_15 -> V_30 + F_30 ( V_15 ) ;
V_83 . V_86 = V_92 ;
F_66 ( V_7 , V_61 , V_63 , V_15 , V_81 , V_82 ,
V_93 , & V_83 ) ;
V_90 = F_30 ( & V_83 ) ;
if ( V_90 )
V_100 = V_105 ;
}
if ( ! V_100 || ! V_90 )
continue;
V_98 = F_69 ( V_90 , V_74 ) ;
switch ( V_100 ) {
case V_103 :
if ( strcmp ( V_15 -> V_37 , V_63 -> V_9 ) == 0 ) {
V_49 = F_62 ( V_15 , V_15 -> V_30 - V_98 ,
F_30 ( V_15 ) + V_98 ) ;
V_102 = L_19 ;
} else
V_102 = L_20 ;
break;
case V_104 :
if ( strcmp ( V_81 -> V_37 , V_63 -> V_9 ) == 0 ) {
V_49 = F_62 ( V_81 , V_81 -> V_30
- V_98 , F_30 ( V_81 )
+ V_98 ) ;
V_97 = V_81 ;
V_102 = L_21 ;
} else if ( strcmp ( V_15 -> V_37 , V_63 -> V_9 ) == 0 ) {
V_102 = L_22 ;
} else
V_102 = L_20 ;
break;
case V_105 :
if ( strcmp ( V_15 -> V_37 , V_63 -> V_9 ) == 0 )
V_102 = L_22 ;
else
V_102 = L_20 ;
break;
default:
return V_74 ;
}
if ( strcmp ( V_102 , L_20 ) == 0 ) {
if ( ! V_85 )
V_83 . V_30 += V_90 - V_98 ;
V_97 = F_65 ( V_61 , V_63 ,
V_83 . V_30 , V_98 ) ;
if ( ! V_97 )
V_49 = - V_25 ;
} else if ( strcmp ( V_102 , L_22 ) == 0 ) {
V_49 = F_62 ( V_15 , V_15 -> V_30 , F_30 ( V_15 )
+ V_98 ) ;
if ( V_49 == 0 )
V_15 -> V_29 |= V_70 ;
}
if ( ! V_97 )
V_97 = V_15 ;
F_60 ( V_7 , V_61 , V_97 , L_23 ,
V_102 , V_100 , V_49 ) ;
if ( V_49 )
return V_74 ;
V_74 -= V_98 ;
if ( V_74 ) {
goto V_95;
} else
return 0 ;
}
if ( ( V_85 || ! V_61 -> V_106 . V_107 ) && V_74 == V_93 )
return F_64 ( V_63 , V_7 , V_58 , V_74 ) ;
return V_74 ;
}
static int F_70 ( struct V_7 * V_7 ,
struct V_58 * V_58 , struct V_62 * V_63 )
{
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_65 * V_15 ;
if ( strncmp ( L_17 , V_63 -> V_9 , 4 ) == 0 )
return 0 ;
V_95:
F_44 (ndd, res) {
int V_49 ;
struct V_65 * V_81 = V_15 -> V_96 ;
T_4 V_86 = V_15 -> V_30 + F_30 ( V_15 ) ;
if ( ! V_81 || strcmp ( V_15 -> V_37 , V_63 -> V_9 ) != 0
|| strcmp ( V_81 -> V_37 , V_63 -> V_9 ) != 0
|| V_86 != V_81 -> V_30 )
continue;
V_86 += F_30 ( V_81 ) ;
F_61 ( V_61 , V_81 ) ;
V_49 = F_62 ( V_15 , V_15 -> V_30 , V_86 - V_15 -> V_30 ) ;
F_60 ( V_7 , V_61 , V_15 , L_24 , V_49 ) ;
if ( V_49 )
return V_49 ;
V_15 -> V_29 |= V_70 ;
goto V_95;
}
return 0 ;
}
static int F_71 ( struct V_1 * V_2 , void * V_19 )
{
struct V_108 * V_108 = V_19 ;
struct V_7 * V_7 ;
struct V_62 V_63 ;
int V_68 ;
if ( ! F_19 ( V_2 ) )
return 0 ;
V_7 = F_6 ( V_2 ) ;
if ( V_7 -> V_78 == 0 )
return 0 ;
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
strcat ( V_63 . V_9 , L_16 ) ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
T_4 V_74 , V_109 = 0 ;
if ( V_58 -> V_108 != V_108 )
continue;
V_74 = F_72 ( V_7 , V_58 , & V_109 ) ;
if ( V_74 == 0 )
return 0 ;
V_109 = F_68 ( V_7 , V_58 , & V_63 , V_74 ) ;
F_50 ( & V_7 -> V_2 , V_109 ,
L_25 ,
( unsigned long long ) V_74 - V_109 ,
( unsigned long long ) V_74 ) ;
return V_109 ? - V_50 : 0 ;
}
return 0 ;
}
static void F_73 ( struct V_26 * V_26 ,
struct V_58 * V_58 )
{
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_65 * V_15 , * V_110 ;
F_74 (ndd, res, _res)
if ( strcmp ( V_15 -> V_37 , L_16 ) == 0 )
F_61 ( V_61 , V_15 ) ;
}
static int F_75 ( struct V_26 * V_26 ,
struct V_58 * V_58 )
{
struct V_108 * V_108 = V_58 -> V_108 ;
int V_49 ;
V_49 = F_21 ( & V_26 -> V_2 , V_108 ,
F_71 ) ;
if ( V_49 )
F_73 ( V_26 , V_58 ) ;
return V_49 ;
}
static int F_76 ( struct V_7 * V_7 ,
struct V_62 * V_63 , T_4 V_74 )
{
struct V_26 * V_26 = F_23 ( & V_7 -> V_2 ) ;
bool V_85 = strncmp ( V_63 -> V_9 , L_17 , 4 ) == 0 ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
T_4 V_109 = V_74 ;
int V_49 , V_111 ;
for ( V_111 = V_85 ; V_111 < 2 ; V_111 ++ ) {
bool V_112 = V_111 == 0 ;
if ( V_112 ) {
V_49 = F_75 ( V_26 , V_58 ) ;
if ( V_49 )
return V_49 ;
}
V_109 = F_68 ( V_7 , V_58 ,
V_63 , V_109 ) ;
if ( V_112 )
F_73 ( V_26 , V_58 ) ;
if ( V_109 == 0 )
break;
}
F_50 ( & V_7 -> V_2 , V_109 ,
L_26 ,
( unsigned long long ) V_74 - V_109 ,
( unsigned long long ) V_74 ) ;
if ( V_109 )
return - V_50 ;
V_49 = F_70 ( V_7 , V_58 , V_63 ) ;
if ( V_49 )
return V_49 ;
}
return 0 ;
}
static void F_77 ( struct V_7 * V_7 ,
struct V_5 * V_6 , T_4 V_64 )
{
struct V_65 * V_15 = & V_6 -> V_4 . V_15 ;
T_4 V_113 = 0 ;
if ( V_64 && ! V_6 -> V_12 ) {
F_24 ( 1 ) ;
V_64 = 0 ;
}
if ( V_64 && V_6 -> V_12 ) {
struct V_58 * V_58 = & V_7 -> V_59 [ 0 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_62 V_63 ;
struct V_65 * V_15 ;
if ( ! V_61 ) {
V_64 = 0 ;
goto V_56;
}
F_43 ( & V_63 , V_6 -> V_12 , 0 ) ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_63 . V_9 ) == 0 ) {
V_113 = ( V_15 -> V_30 - V_58 -> V_30 )
* V_7 -> V_78 ;
goto V_56;
}
F_24 ( 1 ) ;
V_64 = 0 ;
}
V_56:
V_15 -> V_30 = V_7 -> V_114 + V_113 ;
V_15 -> V_86 = V_15 -> V_30 + V_64 - 1 ;
}
static bool F_78 ( const T_1 * V_12 , struct V_1 * V_2 , const char * V_115 )
{
if ( ! V_12 ) {
F_56 ( V_2 , L_27 , V_115 ) ;
return true ;
}
return false ;
}
static T_2 F_79 ( struct V_1 * V_2 , unsigned long long V_116 )
{
T_4 V_117 = 0 , V_90 = 0 ;
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
struct V_35 * V_36 = F_37 ( V_2 ) ;
struct V_58 * V_58 ;
struct V_60 * V_61 ;
struct V_62 V_63 ;
T_5 V_29 = 0 , V_118 ;
int V_49 , V_68 , V_9 = - 1 ;
T_1 * V_12 = NULL ;
if ( V_2 -> V_51 || V_36 -> V_39 )
return - V_25 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_12 = V_6 -> V_12 ;
V_9 = V_6 -> V_9 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_12 = V_14 -> V_12 ;
V_29 = V_66 ;
V_9 = V_14 -> V_9 ;
}
if ( F_78 ( V_12 , V_2 , V_73 ) )
return - V_50 ;
if ( V_7 -> V_78 == 0 ) {
F_56 ( V_2 , L_28 , V_73 ) ;
return - V_50 ;
}
F_80 ( V_116 , V_119 * V_7 -> V_78 , & V_118 ) ;
if ( V_118 ) {
F_56 ( V_2 , L_29 , V_116 ,
( V_119 * V_7 -> V_78 ) / V_120 ) ;
return - V_55 ;
}
F_43 ( & V_63 , V_12 , V_29 ) ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
V_58 = & V_7 -> V_59 [ V_68 ] ;
V_61 = F_42 ( V_58 ) ;
if ( ! V_61 )
return - V_50 ;
V_117 += F_81 ( V_61 , & V_63 ) ;
}
V_90 = F_82 ( V_7 ) ;
if ( V_116 > V_90 + V_117 )
return - V_121 ;
if ( V_116 == V_117 )
return 0 ;
V_116 = F_83 ( V_116 , V_7 -> V_78 ) ;
V_117 = F_83 ( V_117 , V_7 -> V_78 ) ;
if ( V_116 < V_117 )
V_49 = F_63 ( V_7 , & V_63 ,
V_117 - V_116 ) ;
else
V_49 = F_76 ( V_7 , & V_63 , V_116 - V_117 ) ;
if ( V_49 )
return V_49 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_77 ( V_7 , V_6 ,
V_116 * V_7 -> V_78 ) ;
}
if ( V_116 == 0 && V_9 != 0 && V_7 -> V_122 != V_2 && ! V_36 -> V_39 )
F_84 ( V_2 , V_123 ) ;
return V_49 ;
}
static T_2 F_85 ( struct V_1 * V_2 ,
struct V_42 * V_43 , const char * V_44 , T_3 V_45 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
unsigned long long V_116 ;
T_1 * * V_12 = NULL ;
int V_49 ;
V_49 = F_86 ( V_44 , 0 , & V_116 ) ;
if ( V_49 )
return V_49 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
V_49 = F_79 ( V_2 , V_116 ) ;
if ( V_49 >= 0 )
V_49 = F_49 ( V_7 , V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_12 = & V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_12 = & V_14 -> V_12 ;
}
if ( V_49 == 0 && V_116 == 0 && V_12 ) {
F_3 ( * V_12 ) ;
* V_12 = NULL ;
}
F_56 ( V_2 , L_30 , V_73 , V_116 , V_49 < 0
? L_31 : L_32 , V_49 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_49 < 0 ? V_49 : V_45 ;
}
T_4 F_87 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = & V_36 -> V_2 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return F_30 ( & V_6 -> V_4 . V_15 ) ;
} else if ( F_11 ( V_2 ) ) {
return F_41 ( F_9 ( V_2 ) ) ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_30 ( & V_4 -> V_15 ) ;
} else
F_88 ( 1 , L_33 ) ;
return 0 ;
}
T_4 F_89 ( struct V_35 * V_36 )
{
T_4 V_64 ;
F_47 ( & V_36 -> V_2 ) ;
V_64 = F_87 ( V_36 ) ;
F_48 ( & V_36 -> V_2 ) ;
return V_64 ;
}
static T_2 F_90 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
return sprintf ( V_44 , L_34 , ( unsigned long long )
F_89 ( F_37 ( V_2 ) ) ) ;
}
static T_1 * F_91 ( struct V_1 * V_2 )
{
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
return V_14 -> V_12 ;
} else
return F_92 ( - V_50 ) ;
}
static T_2 F_93 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
T_1 * V_12 = F_91 ( V_2 ) ;
if ( F_94 ( V_12 ) )
return F_95 ( V_12 ) ;
if ( V_12 )
return sprintf ( V_44 , L_35 , V_12 ) ;
return sprintf ( V_44 , L_36 ) ;
}
static int F_96 ( struct V_7 * V_7 ,
struct V_1 * V_2 , T_1 * V_124 , T_1 * * V_125 )
{
T_5 V_29 = F_11 ( V_2 ) ? V_66 : 0 ;
struct V_62 V_126 ;
struct V_62 V_127 ;
int V_68 ;
if ( ! F_22 ( V_2 , V_124 ) )
return - V_55 ;
if ( * V_125 == NULL )
goto V_56;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
if ( F_97 ( & V_58 -> V_128 ) )
return - V_25 ;
}
F_43 ( & V_126 , * V_125 , V_29 ) ;
F_43 ( & V_127 , V_124 , V_29 ) ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_65 * V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_126 . V_9 ) == 0 )
sprintf ( ( void * ) V_15 -> V_37 , L_7 ,
V_127 . V_9 ) ;
}
F_3 ( * V_125 ) ;
V_56:
* V_125 = V_124 ;
return 0 ;
}
static T_2 F_98 ( struct V_1 * V_2 ,
struct V_42 * V_43 , const char * V_44 , T_3 V_45 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
T_1 * V_12 = NULL ;
T_2 V_49 = 0 ;
T_1 * * V_129 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_129 = & V_6 -> V_12 ;
} else if ( F_11 ( V_2 ) ) {
struct V_13 * V_14 = F_9 ( V_2 ) ;
V_129 = & V_14 -> V_12 ;
} else
return - V_50 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
F_55 ( V_2 ) ;
if ( F_37 ( V_2 ) -> V_39 )
V_49 = - V_25 ;
if ( V_49 >= 0 )
V_49 = F_99 ( V_2 , & V_12 , V_44 , V_45 ) ;
if ( V_49 >= 0 )
V_49 = F_96 ( V_7 , V_2 , V_12 , V_129 ) ;
if ( V_49 >= 0 )
V_49 = F_49 ( V_7 , V_2 ) ;
else
F_3 ( V_12 ) ;
F_56 ( V_2 , L_37 , V_73 ,
V_49 , V_44 , V_44 [ V_45 - 1 ] == '\n' ? L_3 : L_36 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_49 < 0 ? V_49 : V_45 ;
}
static T_2 F_100 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_65 * V_15 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_15 = & V_6 -> V_4 . V_15 ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 = & V_4 -> V_15 ;
} else
return - V_50 ;
if ( F_30 ( V_15 ) == 0 )
return - V_50 ;
return sprintf ( V_44 , L_38 , ( unsigned long long ) V_15 -> V_30 ) ;
}
static T_2 F_101 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_13 * V_14 = F_9 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
return - V_50 ;
return F_102 ( V_14 -> V_69 , V_130 , V_44 ) ;
}
static T_2 F_103 ( struct V_1 * V_2 ,
struct V_42 * V_43 , const char * V_44 , T_3 V_45 )
{
struct V_13 * V_14 = F_9 ( V_2 ) ;
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
T_2 V_49 = 0 ;
if ( ! F_11 ( V_2 ) )
return - V_50 ;
F_54 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( F_37 ( V_2 ) -> V_39 )
V_49 = - V_25 ;
if ( V_49 >= 0 )
V_49 = F_104 ( V_2 , V_44 , & V_14 -> V_69 ,
V_130 ) ;
if ( V_49 >= 0 )
V_49 = F_49 ( V_7 , V_2 ) ;
F_56 ( V_2 , L_39 , V_73 ,
V_49 , V_49 < 0 ? L_40 : L_41 , V_44 ,
V_44 [ V_45 - 1 ] == '\n' ? L_3 : L_36 ) ;
F_48 ( V_2 ) ;
F_57 ( V_2 ) ;
return V_49 ? V_49 : V_45 ;
}
static T_2 F_105 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_7 * V_7 = F_6 ( V_2 -> V_8 ) ;
struct V_62 V_63 ;
int V_67 = 0 , V_68 ;
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
V_29 = V_66 ;
}
if ( ! V_12 )
goto V_56;
F_43 ( & V_63 , V_12 , V_29 ) ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_65 * V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_63 . V_9 ) == 0 )
V_67 ++ ;
}
V_56:
F_48 ( V_2 ) ;
return sprintf ( V_44 , L_6 , V_67 ) ;
}
static T_2 F_106 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_35 * V_36 = F_37 ( V_2 ) ;
T_2 V_49 ;
F_54 ( V_2 ) ;
V_49 = sprintf ( V_44 , L_11 , V_36 -> V_39 ? F_107 ( V_36 -> V_39 ) : L_3 ) ;
F_57 ( V_2 ) ;
return V_49 ;
}
static T_2 F_108 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
struct V_35 * V_36 = F_37 ( V_2 ) ;
struct V_1 * V_39 ;
char * V_131 ;
T_2 V_49 ;
F_54 ( V_2 ) ;
V_39 = V_36 -> V_39 ;
if ( V_39 && F_14 ( V_39 ) )
V_131 = L_42 ;
else if ( V_39 && F_16 ( V_39 ) )
V_131 = L_43 ;
else if ( V_39 && F_109 ( V_39 ) )
V_131 = L_44 ;
else if ( ! V_39 && F_26 ( V_2 ) )
V_131 = L_43 ;
else
V_131 = L_45 ;
V_49 = sprintf ( V_44 , L_11 , V_131 ) ;
F_57 ( V_2 ) ;
return V_49 ;
}
static T_2 F_110 ( struct V_1 * V_2 ,
struct V_42 * V_43 , const char * V_44 , T_3 V_45 )
{
bool V_132 ;
int V_49 = F_111 ( V_44 , & V_132 ) ;
if ( V_49 )
return V_49 ;
F_37 ( V_2 ) -> V_132 = V_132 ;
return V_45 ;
}
static T_2 F_112 ( struct V_1 * V_2 ,
struct V_42 * V_43 , char * V_44 )
{
return sprintf ( V_44 , L_6 , F_37 ( V_2 ) -> V_132 ) ;
}
static T_6 F_113 ( struct V_133 * V_134 ,
struct V_135 * V_136 , int V_74 )
{
struct V_1 * V_2 = F_114 ( V_134 , struct V_1 , V_134 ) ;
if ( V_136 == & V_137 . V_43 ) {
if ( F_11 ( V_2 ) )
return 0 ;
return V_136 -> V_131 ;
}
if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
if ( V_136 == & V_138 . V_43 )
return 0644 ;
if ( F_10 ( V_2 ) && V_136 == & V_139 . V_43 )
return 0 ;
return V_136 -> V_131 ;
}
if ( V_136 == & V_140 . V_43 || V_136 == & V_138 . V_43
|| V_136 == & V_141 . V_43
|| V_136 == & V_142 . V_43
|| V_136 == & V_143 . V_43 )
return V_136 -> V_131 ;
return 0 ;
}
struct V_35 * F_115 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_14 ( V_2 ) ? F_15 ( V_2 ) : NULL ;
struct V_23 * V_23 = F_16 ( V_2 ) ? F_17 ( V_2 ) : NULL ;
struct V_144 * V_144 = F_109 ( V_2 ) ? F_116 ( V_2 ) : NULL ;
struct V_35 * V_36 = NULL ;
T_4 V_64 ;
if ( V_22 || V_23 || V_144 ) {
if ( V_22 )
V_36 = V_22 -> V_36 ;
else if ( V_23 )
V_36 = V_23 -> V_36 ;
else if ( V_144 )
V_36 = V_144 -> V_23 . V_36 ;
if ( ! V_36 )
return F_92 ( - V_145 ) ;
F_54 ( & V_36 -> V_2 ) ;
F_57 ( & V_36 -> V_2 ) ;
if ( V_36 -> V_2 . V_51 ) {
F_56 ( & V_36 -> V_2 , L_46 ,
F_107 ( V_2 ) ) ;
return F_92 ( - V_25 ) ;
}
if ( F_50 ( & V_36 -> V_2 , V_36 -> V_39 != V_2 ,
L_47 ,
F_107 ( V_2 ) ,
F_107 ( V_36 -> V_39 ) ) )
return F_92 ( - V_50 ) ;
} else {
V_36 = F_37 ( V_2 ) ;
if ( V_36 -> V_39 ) {
F_56 ( V_2 , L_48 ,
F_107 ( V_36 -> V_39 ) ) ;
return F_92 ( - V_50 ) ;
}
}
V_64 = F_89 ( V_36 ) ;
if ( V_64 < V_146 ) {
F_56 ( & V_36 -> V_2 , L_49 ,
& V_64 , V_146 ) ;
return F_92 ( - V_145 ) ;
}
if ( F_10 ( & V_36 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_36 -> V_2 ) ;
if ( F_78 ( V_6 -> V_12 , & V_36 -> V_2 , V_73 ) )
return F_92 ( - V_145 ) ;
} else if ( F_11 ( & V_36 -> V_2 ) ) {
struct V_13 * V_14 ;
V_14 = F_9 ( & V_36 -> V_2 ) ;
if ( F_78 ( V_14 -> V_12 , & V_36 -> V_2 , V_73 ) )
return F_92 ( - V_145 ) ;
if ( ! V_14 -> V_69 ) {
F_56 ( & V_36 -> V_2 , L_50 ,
V_73 ) ;
return F_92 ( - V_145 ) ;
}
if ( ! F_46 ( V_14 ) )
return F_92 ( - V_145 ) ;
}
return V_36 ;
}
static struct V_1 * * F_117 ( struct V_7 * V_7 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 , * * V_147 ;
struct V_65 * V_15 ;
V_4 = F_40 ( sizeof( * V_4 ) , V_52 ) ;
if ( ! V_4 )
return NULL ;
V_147 = F_118 ( 2 , sizeof( struct V_1 * ) , V_52 ) ;
if ( ! V_147 ) {
F_3 ( V_4 ) ;
return NULL ;
}
V_2 = & V_4 -> V_57 . V_2 ;
V_2 -> type = & V_18 ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_15 = & V_4 -> V_15 ;
V_15 -> V_37 = F_107 ( & V_7 -> V_2 ) ;
V_15 -> V_29 = V_148 ;
V_15 -> V_30 = V_7 -> V_114 ;
V_15 -> V_86 = V_15 -> V_30 + V_7 -> V_149 - 1 ;
V_147 [ 0 ] = V_2 ;
return V_147 ;
}
static bool F_119 ( struct V_7 * V_7 , T_1 * V_12 ,
T_7 V_150 , T_8 V_47 )
{
struct V_151 * V_72 = NULL ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
struct V_152 * V_153 ;
bool V_154 = false ;
F_120 (label_ent, &nd_mapping->labels, list) {
struct V_151 * V_155 = V_153 -> V_156 ;
T_8 V_157 , V_158 ;
T_7 V_159 ;
if ( ! V_155 )
continue;
V_159 = F_121 ( V_155 -> V_159 ) ;
V_157 = F_122 ( V_155 -> V_157 ) ;
V_158 = F_122 ( V_155 -> V_158 ) ;
if ( V_159 != V_150 )
continue;
if ( memcmp ( V_155 -> V_12 , V_12 , V_24 ) != 0 )
continue;
if ( V_154 ) {
F_56 ( F_42 ( V_58 ) -> V_2 ,
L_51 ,
V_73 ) ;
return false ;
}
V_154 = true ;
if ( V_158 != V_7 -> V_78 )
continue;
if ( V_157 != V_47 )
continue;
V_72 = V_155 ;
break;
}
if ( V_72 )
break;
}
return V_72 != NULL ;
}
static int F_123 ( struct V_7 * V_7 , T_1 * V_160 )
{
int V_68 ;
if ( ! V_160 )
return - V_145 ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_151 * V_155 = NULL ;
T_7 V_161 , V_162 , V_163 , V_164 ;
struct V_152 * V_153 ;
F_124 ( & V_58 -> V_165 ) ;
F_120 (label_ent, &nd_mapping->labels, list) {
V_155 = V_153 -> V_156 ;
if ( ! V_155 )
continue;
if ( memcmp ( V_155 -> V_12 , V_160 , V_24 ) == 0 )
break;
V_155 = NULL ;
}
if ( ! V_155 ) {
F_67 ( 1 ) ;
return - V_55 ;
}
V_161 = V_58 -> V_30 ;
V_162 = V_161 + V_58 -> V_64 ;
V_163 = F_121 ( V_155 -> V_106 ) ;
V_164 = V_163 + F_121 ( V_155 -> V_166 ) ;
if ( V_163 >= V_161 && V_163 < V_162
&& V_164 <= V_162 && V_164 > V_161 )
;
else {
F_56 ( & V_7 -> V_2 , L_52 ,
F_107 ( V_61 -> V_2 ) , V_155 -> V_12 ) ;
return - V_55 ;
}
F_125 ( & V_153 -> V_167 , & V_58 -> V_128 ) ;
}
return 0 ;
}
struct V_1 * F_126 ( struct V_7 * V_7 ,
struct V_151 * V_155 )
{
T_7 V_168 = F_127 ( V_7 ) ;
T_7 V_150 = F_128 ( V_7 ) ;
struct V_152 * V_153 ;
struct V_5 * V_6 ;
struct V_58 * V_58 ;
T_4 V_64 = 0 ;
struct V_65 * V_15 ;
struct V_1 * V_2 ;
int V_49 = 0 ;
T_8 V_68 ;
if ( V_150 == 0 ) {
F_56 ( & V_7 -> V_2 , L_53 ) ;
return F_92 ( - V_50 ) ;
}
if ( F_121 ( V_155 -> V_159 ) != V_150 ) {
F_56 ( & V_7 -> V_2 , L_54 ,
V_155 -> V_12 ) ;
if ( F_121 ( V_155 -> V_159 ) != V_168 )
return F_92 ( - V_169 ) ;
F_56 ( & V_7 -> V_2 , L_55 ,
V_155 -> V_12 ) ;
}
V_6 = F_40 ( sizeof( * V_6 ) , V_52 ) ;
if ( ! V_6 )
return F_92 ( - V_53 ) ;
V_6 -> V_9 = - 1 ;
V_2 = & V_6 -> V_4 . V_57 . V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_37 = F_107 ( & V_7 -> V_2 ) ;
V_15 -> V_29 = V_148 ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
if ( F_119 ( V_7 , V_155 -> V_12 , V_150 , V_68 ) )
continue;
if ( F_119 ( V_7 , V_155 -> V_12 , V_168 , V_68 ) )
continue;
break;
}
if ( V_68 < V_7 -> V_78 ) {
struct V_60 * V_61 = F_42 ( & V_7 -> V_59 [ V_68 ] ) ;
F_129 ( & V_7 -> V_2 , L_56 ,
F_107 ( V_61 -> V_2 ) , V_155 -> V_12 ) ;
V_49 = - V_55 ;
goto V_170;
}
V_49 = F_123 ( V_7 , V_155 -> V_12 ) ;
if ( V_49 )
goto V_170;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_151 * V_171 ;
V_58 = & V_7 -> V_59 [ V_68 ] ;
V_153 = F_130 ( & V_58 -> V_128 ,
F_131 ( * V_153 ) , V_167 ) ;
V_171 = V_153 ? V_153 -> V_156 : 0 ;
if ( ! V_171 ) {
F_67 ( 1 ) ;
continue;
}
V_64 += F_121 ( V_171 -> V_166 ) ;
if ( F_122 ( V_171 -> V_157 ) != 0 )
continue;
F_67 ( V_6 -> V_11 || V_6 -> V_12 ) ;
V_6 -> V_11 = F_38 ( ( void V_172 * ) V_171 -> V_37 ,
V_54 , V_52 ) ;
V_6 -> V_12 = F_38 ( ( void V_172 * ) V_171 -> V_12 ,
V_24 , V_52 ) ;
}
if ( ! V_6 -> V_11 || ! V_6 -> V_12 ) {
V_49 = - V_53 ;
goto V_170;
}
F_77 ( V_7 , V_6 , V_64 ) ;
return V_2 ;
V_170:
F_4 ( V_2 ) ;
switch ( V_49 ) {
case - V_55 :
F_56 ( & V_7 -> V_2 , L_57 , V_73 ) ;
break;
case - V_145 :
F_56 ( & V_7 -> V_2 , L_58 , V_73 ) ;
break;
default:
F_56 ( & V_7 -> V_2 , L_59 ,
V_73 , V_49 ) ;
break;
}
return F_92 ( V_49 ) ;
}
struct V_65 * F_132 ( struct V_7 * V_7 ,
struct V_60 * V_61 , struct V_13 * V_14 ,
T_4 V_30 )
{
struct V_62 V_63 ;
struct V_65 * V_15 ;
F_43 ( & V_63 , V_14 -> V_12 , V_66 ) ;
V_15 = F_133 ( V_14 -> V_15 ,
sizeof( void * ) * ( V_14 -> V_71 + 1 ) ,
V_52 ) ;
if ( ! V_15 )
return NULL ;
V_14 -> V_15 = (struct V_65 * * ) V_15 ;
F_44 (ndd, res)
if ( strcmp ( V_15 -> V_37 , V_63 . V_9 ) == 0
&& V_15 -> V_30 == V_30 ) {
V_14 -> V_15 [ V_14 -> V_71 ++ ] = V_15 ;
return V_15 ;
}
return NULL ;
}
static struct V_1 * F_134 ( struct V_7 * V_7 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
if ( ! F_20 ( & V_7 -> V_2 ) )
return NULL ;
V_14 = F_40 ( sizeof( * V_14 ) , V_52 ) ;
if ( ! V_14 )
return NULL ;
V_2 = & V_14 -> V_57 . V_2 ;
V_2 -> type = & V_17 ;
V_14 -> V_9 = F_135 ( & V_7 -> V_10 , 0 , 0 , V_52 ) ;
if ( V_14 -> V_9 < 0 ) {
F_3 ( V_14 ) ;
return NULL ;
}
F_136 ( V_2 , L_60 , V_7 -> V_9 , V_14 -> V_9 ) ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_2 -> V_173 = V_174 ;
return & V_14 -> V_57 . V_2 ;
}
static struct V_1 * F_137 ( struct V_7 * V_7 )
{
struct V_5 * V_6 ;
struct V_65 * V_15 ;
struct V_1 * V_2 ;
if ( ! F_19 ( & V_7 -> V_2 ) )
return NULL ;
V_6 = F_40 ( sizeof( * V_6 ) , V_52 ) ;
if ( ! V_6 )
return NULL ;
V_2 = & V_6 -> V_4 . V_57 . V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_37 = F_107 ( & V_7 -> V_2 ) ;
V_15 -> V_29 = V_148 ;
V_6 -> V_9 = F_135 ( & V_7 -> V_10 , 0 , 0 , V_52 ) ;
if ( V_6 -> V_9 < 0 ) {
F_3 ( V_6 ) ;
return NULL ;
}
F_136 ( V_2 , L_60 , V_7 -> V_9 , V_6 -> V_9 ) ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_2 -> V_173 = V_174 ;
F_77 ( V_7 , V_6 , 0 ) ;
return V_2 ;
}
void F_138 ( struct V_7 * V_7 )
{
F_67 ( ! F_25 ( & V_7 -> V_2 ) ) ;
if ( F_35 ( V_7 ) == V_175 )
return;
if ( F_20 ( & V_7 -> V_2 ) )
V_7 -> V_122 = F_134 ( V_7 ) ;
else
V_7 -> V_122 = F_137 ( V_7 ) ;
if ( ! V_7 -> V_122 )
F_129 ( & V_7 -> V_2 , L_61 ,
F_20 ( & V_7 -> V_2 ) ? L_12 : L_17 ) ;
else
F_139 ( V_7 -> V_122 ) ;
}
void F_140 ( struct V_7 * V_7 )
{
F_67 ( ! F_25 ( & V_7 -> V_2 ) ) ;
V_7 -> V_176 = F_141 ( V_7 ) ;
if ( ! V_7 -> V_176 )
F_129 ( & V_7 -> V_2 , L_62 ) ;
}
void F_142 ( struct V_7 * V_7 )
{
F_67 ( ! F_25 ( & V_7 -> V_2 ) ) ;
V_7 -> V_177 = F_143 ( V_7 ) ;
if ( ! V_7 -> V_177 )
F_129 ( & V_7 -> V_2 , L_63 ) ;
}
void F_144 ( struct V_7 * V_7 )
{
F_67 ( ! F_25 ( & V_7 -> V_2 ) ) ;
V_7 -> V_178 = F_145 ( V_7 ) ;
if ( ! V_7 -> V_178 )
F_129 ( & V_7 -> V_2 , L_64 ) ;
}
static int F_146 ( struct V_7 * V_7 ,
struct V_151 * V_155 , struct V_1 * * V_147 ,
int V_67 )
{
struct V_58 * V_58 = & V_7 -> V_59 [ 0 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
int V_68 ;
for ( V_68 = 0 ; V_68 < V_67 ; V_68 ++ ) {
T_1 * V_12 = F_91 ( V_147 [ V_68 ] ) ;
struct V_65 * V_15 ;
if ( F_147 ( V_12 ) ) {
F_67 ( 1 ) ;
continue;
}
if ( memcmp ( V_12 , V_155 -> V_12 , V_24 ) != 0 )
continue;
if ( F_11 ( V_147 [ V_68 ] ) ) {
V_15 = F_132 ( V_7 , V_61 ,
F_9 ( V_147 [ V_68 ] ) ,
F_121 ( V_155 -> V_106 ) ) ;
if ( ! V_15 )
return - V_50 ;
F_60 ( V_7 , V_61 , V_15 , L_65 , V_67 ) ;
} else {
F_129 ( & V_7 -> V_2 ,
L_66 ,
V_155 -> V_12 ) ;
return - V_50 ;
}
break;
}
return V_68 ;
}
struct V_1 * F_148 ( struct V_7 * V_7 ,
struct V_151 * V_155 , int V_67 )
{
struct V_58 * V_58 = & V_7 -> V_59 [ 0 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_13 * V_14 ;
char V_37 [ V_54 ] ;
struct V_1 * V_2 = NULL ;
struct V_65 * V_15 ;
V_14 = F_40 ( sizeof( * V_14 ) , V_52 ) ;
if ( ! V_14 )
return F_92 ( - V_53 ) ;
V_2 = & V_14 -> V_57 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_8 = & V_7 -> V_2 ;
V_14 -> V_9 = - 1 ;
V_14 -> V_69 = F_121 ( V_155 -> V_69 ) ;
V_14 -> V_12 = F_38 ( V_155 -> V_12 , V_24 ,
V_52 ) ;
if ( ! V_14 -> V_12 )
goto V_179;
memcpy ( V_37 , V_155 -> V_37 , V_54 ) ;
if ( V_37 [ 0 ] )
V_14 -> V_11 = F_38 ( V_37 , V_54 ,
V_52 ) ;
V_15 = F_132 ( V_7 , V_61 , V_14 ,
F_121 ( V_155 -> V_106 ) ) ;
if ( ! V_15 )
goto V_179;
F_60 ( V_7 , V_61 , V_15 , L_67 , V_67 ) ;
return V_2 ;
V_179:
F_8 ( V_2 ) ;
return F_92 ( - V_50 ) ;
}
static int F_149 ( const void * V_136 , const void * V_180 )
{
const struct V_1 * V_181 = * ( const struct V_1 * * ) V_136 ;
const struct V_1 * V_182 = * ( const struct V_1 * * ) V_180 ;
struct V_13 * V_183 , * V_184 ;
struct V_5 * V_185 , * V_186 ;
if ( F_12 ( V_181 ) )
return 0 ;
if ( F_11 ( V_181 ) ) {
V_183 = F_9 ( V_181 ) ;
V_184 = F_9 ( V_182 ) ;
return memcmp ( & V_183 -> V_15 [ 0 ] -> V_30 , & V_184 -> V_15 [ 0 ] -> V_30 ,
sizeof( T_4 ) ) ;
}
V_185 = F_5 ( V_181 ) ;
V_186 = F_5 ( V_182 ) ;
return memcmp ( & V_185 -> V_4 . V_15 . V_30 , & V_186 -> V_4 . V_15 . V_30 ,
sizeof( T_4 ) ) ;
}
static struct V_1 * * F_150 ( struct V_7 * V_7 )
{
int V_68 , V_67 = 0 ;
struct V_1 * V_2 , * * V_147 = NULL ;
struct V_152 * V_153 , * V_187 ;
struct V_58 * V_58 = & V_7 -> V_59 [ 0 ] ;
T_4 V_188 = V_58 -> V_30 + V_58 -> V_64 - 1 ;
F_151 (label_ent, e, &nd_mapping->labels, list) {
struct V_151 * V_155 = V_153 -> V_156 ;
struct V_1 * * V_189 ;
T_5 V_29 ;
if ( ! V_155 )
continue;
V_29 = F_152 ( V_155 -> V_29 ) ;
if ( F_20 ( & V_7 -> V_2 )
== ! ! ( V_29 & V_66 ) )
;
else
continue;
if ( V_155 -> V_106 < V_58 -> V_30 || V_155 -> V_106 > V_188 )
continue;
V_68 = F_146 ( V_7 , V_155 , V_147 , V_67 ) ;
if ( V_68 < 0 )
goto V_170;
if ( V_68 < V_67 )
continue;
V_189 = F_118 ( V_67 + 2 , sizeof( V_2 ) , V_52 ) ;
if ( ! V_189 )
goto V_170;
memcpy ( V_189 , V_147 , sizeof( V_2 ) * V_67 ) ;
F_3 ( V_147 ) ;
V_147 = V_189 ;
if ( F_20 ( & V_7 -> V_2 ) ) {
V_2 = F_148 ( V_7 , V_155 , V_67 ) ;
if ( F_94 ( V_2 ) )
goto V_170;
V_147 [ V_67 ++ ] = V_2 ;
} else {
V_2 = F_126 ( V_7 , V_155 ) ;
if ( F_94 ( V_2 ) ) {
switch ( F_95 ( V_2 ) ) {
case - V_169 :
continue;
case - V_145 :
break;
default:
goto V_170;
}
} else
V_147 [ V_67 ++ ] = V_2 ;
}
}
F_56 ( & V_7 -> V_2 , L_68 ,
V_73 , V_67 , F_20 ( & V_7 -> V_2 )
? L_12 : L_17 , V_67 == 1 ? L_3 : L_1 ) ;
if ( V_67 == 0 ) {
F_153 ( V_58 ) ;
V_147 = F_118 ( 2 , sizeof( V_2 ) , V_52 ) ;
if ( ! V_147 )
goto V_170;
if ( F_20 ( & V_7 -> V_2 ) ) {
struct V_13 * V_14 ;
V_14 = F_40 ( sizeof( * V_14 ) , V_52 ) ;
if ( ! V_14 )
goto V_170;
V_2 = & V_14 -> V_57 . V_2 ;
V_2 -> type = & V_17 ;
} else {
struct V_5 * V_6 ;
V_6 = F_40 ( sizeof( * V_6 ) , V_52 ) ;
if ( ! V_6 )
goto V_170;
V_2 = & V_6 -> V_4 . V_57 . V_2 ;
V_2 -> type = & V_16 ;
F_77 ( V_7 , V_6 , 0 ) ;
}
V_2 -> V_8 = & V_7 -> V_2 ;
V_147 [ V_67 ++ ] = V_2 ;
} else if ( F_19 ( & V_7 -> V_2 ) ) {
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_190 * V_191 , * V_187 ;
F_154 ( V_167 ) ;
int V_111 ;
V_58 = & V_7 -> V_59 [ V_68 ] ;
if ( F_97 ( & V_58 -> V_128 ) ) {
F_67 ( 1 ) ;
continue;
}
V_111 = V_67 ;
F_155 (l, e, &nd_mapping->labels) {
if ( ! V_111 -- )
break;
F_156 ( V_191 , & V_167 ) ;
}
F_153 ( V_58 ) ;
F_157 ( & V_167 , & V_58 -> V_128 ) ;
}
}
if ( V_67 > 1 )
F_158 ( V_147 , V_67 , sizeof( struct V_1 * ) , F_149 , NULL ) ;
return V_147 ;
V_170:
if ( V_147 ) {
for ( V_68 = 0 ; V_147 [ V_68 ] ; V_68 ++ )
if ( F_20 ( & V_7 -> V_2 ) )
F_8 ( V_147 [ V_68 ] ) ;
else
F_4 ( V_147 [ V_68 ] ) ;
F_3 ( V_147 ) ;
}
return NULL ;
}
static struct V_1 * * F_159 ( struct V_7 * V_7 )
{
struct V_58 * V_58 = & V_7 -> V_59 [ 0 ] ;
struct V_1 * * V_147 ;
int V_68 ;
if ( V_7 -> V_78 == 0 )
return NULL ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
V_58 = & V_7 -> V_59 [ V_68 ] ;
F_160 ( & V_58 -> V_165 , V_68 ) ;
}
V_147 = F_150 ( V_7 ) ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
int V_192 = V_7 -> V_78 - 1 - V_68 ;
V_58 = & V_7 -> V_59 [ V_192 ] ;
F_161 ( & V_58 -> V_165 ) ;
}
return V_147 ;
}
static int F_162 ( struct V_7 * V_7 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_7 -> V_78 ; V_68 ++ ) {
struct V_58 * V_58 = & V_7 -> V_59 [ V_68 ] ;
struct V_60 * V_61 = F_42 ( V_58 ) ;
struct V_108 * V_108 = V_58 -> V_108 ;
struct V_152 * V_153 ;
int V_67 , V_111 ;
if ( ! V_61 ) {
if ( F_28 ( V_193 , & V_108 -> V_29 ) )
;
else if ( F_28 ( V_194 , & V_108 -> V_29 ) )
;
else
return 0 ;
F_129 ( & V_7 -> V_2 , L_69 ,
F_107 ( & V_58 -> V_108 -> V_2 ) ,
F_28 ( V_193 , & V_108 -> V_29 )
? L_70 : L_71 ) ;
return - V_50 ;
}
V_58 -> V_61 = V_61 ;
F_163 ( & V_108 -> V_195 ) ;
F_164 ( V_61 ) ;
V_67 = F_165 ( V_61 ) ;
F_56 ( V_61 -> V_2 , L_72 , V_73 , V_67 ) ;
if ( ! V_67 )
continue;
for ( V_111 = 0 ; V_111 < V_67 ; V_111 ++ ) {
struct V_151 * V_156 ;
V_153 = F_40 ( sizeof( * V_153 ) , V_52 ) ;
if ( ! V_153 )
break;
V_156 = F_166 ( V_61 , V_111 ) ;
V_153 -> V_156 = V_156 ;
F_167 ( & V_58 -> V_165 ) ;
F_168 ( & V_153 -> V_167 , & V_58 -> V_128 ) ;
F_161 ( & V_58 -> V_165 ) ;
}
if ( V_111 >= V_67 )
continue;
F_167 ( & V_58 -> V_165 ) ;
F_153 ( V_58 ) ;
F_161 ( & V_58 -> V_165 ) ;
return - V_53 ;
}
return 0 ;
}
int F_169 ( struct V_7 * V_7 , int * V_170 )
{
struct V_1 * * V_147 = NULL ;
int V_68 , V_49 = 0 , type ;
* V_170 = 0 ;
F_47 ( & V_7 -> V_2 ) ;
V_49 = F_162 ( V_7 ) ;
if ( V_49 ) {
F_48 ( & V_7 -> V_2 ) ;
return V_49 ;
}
type = F_35 ( V_7 ) ;
switch ( type ) {
case V_175 :
V_147 = F_117 ( V_7 ) ;
break;
case V_196 :
case V_197 :
V_147 = F_159 ( V_7 ) ;
break;
default:
break;
}
F_48 ( & V_7 -> V_2 ) ;
if ( ! V_147 )
return - V_145 ;
for ( V_68 = 0 ; V_147 [ V_68 ] ; V_68 ++ ) {
struct V_1 * V_2 = V_147 [ V_68 ] ;
int V_9 ;
if ( type == V_197 ) {
struct V_13 * V_14 ;
V_14 = F_9 ( V_2 ) ;
V_9 = F_135 ( & V_7 -> V_10 , 0 , 0 ,
V_52 ) ;
V_14 -> V_9 = V_9 ;
} else if ( type == V_196 ) {
struct V_5 * V_6 ;
V_6 = F_5 ( V_2 ) ;
V_9 = F_135 ( & V_7 -> V_10 , 0 , 0 ,
V_52 ) ;
V_6 -> V_9 = V_9 ;
} else
V_9 = V_68 ;
if ( V_9 < 0 )
break;
F_136 ( V_2 , L_60 , V_7 -> V_9 , V_9 ) ;
V_2 -> V_173 = V_174 ;
F_139 ( V_2 ) ;
}
if ( V_68 )
V_7 -> V_122 = V_147 [ 0 ] ;
if ( V_147 [ V_68 ] ) {
int V_111 ;
for ( V_111 = V_68 ; V_147 [ V_111 ] ; V_111 ++ ) {
struct V_1 * V_2 = V_147 [ V_111 ] ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
}
* V_170 = V_111 - V_68 ;
if ( * V_170 == 0 )
V_49 = - V_145 ;
}
F_3 ( V_147 ) ;
if ( V_49 == - V_145 )
return V_49 ;
return V_68 ;
}

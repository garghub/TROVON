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
bool F_13 ( struct V_1 * V_2 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
if ( ! F_14 ( V_19 ) )
return false ;
if ( ! F_15 ( V_20 , & V_11 -> V_21 ) )
return false ;
if ( F_16 ( V_2 ) || F_17 ( V_2 ) )
return false ;
#ifdef F_18
return F_18 == V_22 ;
#else
return false ;
#endif
}
const char * F_19 ( struct V_23 * V_24 ,
char * V_25 )
{
struct V_11 * V_11 = F_8 ( V_24 -> V_2 . V_12 ) ;
const char * V_26 = NULL ;
if ( V_24 -> V_27 ) {
if ( F_17 ( V_24 -> V_27 ) )
V_26 = L_1 ;
else if ( F_16 ( V_24 -> V_27 ) )
V_26 = L_2 ;
else
F_20 ( & V_24 -> V_2 , 1 ,
L_3 ,
F_21 ( V_24 -> V_27 ) ) ;
}
if ( F_10 ( & V_24 -> V_2 ) || F_12 ( & V_24 -> V_2 ) ) {
if ( ! V_26 && F_13 ( & V_24 -> V_2 ) )
V_26 = L_2 ;
sprintf ( V_25 , L_4 , V_11 -> V_13 , V_26 ? V_26 : L_5 ) ;
} else if ( F_11 ( & V_24 -> V_2 ) ) {
struct V_9 * V_10 ;
V_10 = F_7 ( & V_24 -> V_2 ) ;
sprintf ( V_25 , L_6 , V_11 -> V_13 , V_10 -> V_13 ,
V_26 ? V_26 : L_5 ) ;
} else {
return NULL ;
}
return V_25 ;
}
const T_1 * F_22 ( struct V_1 * V_2 )
{
static const T_1 V_28 [ 16 ] ;
if ( ! V_2 )
return V_28 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
return V_10 -> V_8 ;
} else
return V_28 ;
}
static T_2 F_23 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
return sprintf ( V_31 , L_7 , F_24 ( V_11 ) ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , const char * V_31 ,
const T_3 V_32 )
{
char * V_33 , * V_34 , * V_7 , * * V_35 ;
T_2 V_36 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_35 = & V_6 -> V_7 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_35 = & V_10 -> V_7 ;
} else
return - V_37 ;
if ( V_2 -> V_38 || F_26 ( V_2 ) -> V_27 )
return - V_39 ;
V_33 = F_27 ( V_31 , V_32 + 1 , V_40 ) ;
if ( ! V_33 )
return - V_41 ;
V_33 [ V_32 ] = '\0' ;
V_34 = F_28 ( V_33 ) ;
if ( strlen ( V_34 ) + 1 > V_42 ) {
V_36 = - V_43 ;
goto V_44;
}
V_7 = F_29 ( V_42 , V_40 ) ;
if ( ! V_7 ) {
V_36 = - V_41 ;
goto V_44;
}
F_3 ( * V_35 ) ;
* V_35 = V_7 ;
sprintf ( * V_35 , L_8 , V_34 ) ;
V_36 = V_32 ;
V_44:
F_3 ( V_33 ) ;
return V_36 ;
}
static T_4 F_30 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 -> V_45 . V_2 . V_12 ) ;
struct V_46 * V_46 = & V_11 -> V_47 [ 0 ] ;
struct V_48 * V_49 = F_31 ( V_46 ) ;
struct V_50 V_51 ;
T_4 V_52 = 0 ;
struct V_53 * V_15 ;
if ( ! V_10 -> V_8 )
return 0 ;
F_32 ( & V_51 , V_10 -> V_8 , V_54 ) ;
F_33 (ndd, res)
if ( strcmp ( V_15 -> V_25 , V_51 . V_13 ) == 0 )
V_52 += F_34 ( V_15 ) ;
return V_52 ;
}
static bool F_35 ( struct V_9 * V_10 )
{
struct V_11 * V_11 = F_8 ( V_10 -> V_45 . V_2 . V_12 ) ;
struct V_46 * V_46 = & V_11 -> V_47 [ 0 ] ;
struct V_48 * V_49 = F_31 ( V_46 ) ;
struct V_50 V_51 ;
struct V_53 * V_15 ;
int V_55 , V_56 ;
if ( ! V_10 -> V_8 || ! V_10 -> V_57 || ! V_49 )
return false ;
V_55 = 0 ;
F_32 ( & V_51 , V_10 -> V_8 , V_54 ) ;
F_33 (ndd, res) {
if ( strcmp ( V_15 -> V_25 , V_51 . V_13 ) != 0 )
continue;
if ( V_15 -> V_21 & V_58 )
return false ;
V_55 ++ ;
}
if ( V_55 != V_10 -> V_59 )
return false ;
for ( V_56 = 0 ; V_56 < V_10 -> V_59 ; V_56 ++ ) {
struct V_53 * V_60 = NULL ;
F_33 (ndd, res)
if ( V_15 == V_10 -> V_15 [ V_56 ] ) {
V_60 = V_15 ;
break;
}
if ( ! V_60 )
return false ;
}
return true ;
}
T_4 F_36 ( struct V_9 * V_10 )
{
T_4 V_52 ;
F_37 ( & V_10 -> V_45 . V_2 ) ;
V_52 = F_35 ( V_10 ) ;
F_38 ( & V_10 -> V_45 . V_2 ) ;
return V_52 ;
}
static int F_39 ( struct V_11 * V_11 ,
struct V_1 * V_2 )
{
F_20 ( V_2 , V_2 -> V_38 || F_26 ( V_2 ) -> V_27 ,
L_9 ) ;
if ( V_2 -> V_38 || F_26 ( V_2 ) -> V_27 )
return 0 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
T_4 V_52 = F_34 ( & V_6 -> V_4 . V_15 ) ;
if ( V_52 == 0 && V_6 -> V_8 )
;
else if ( ! V_6 -> V_8 )
return 0 ;
return F_40 ( V_11 , V_6 , V_52 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
T_4 V_52 = F_30 ( V_10 ) ;
if ( V_52 == 0 && V_10 -> V_8 )
;
else if ( ! V_10 -> V_8 || ! V_10 -> V_57 )
return 0 ;
return F_41 ( V_11 , V_10 , V_52 ) ;
} else
return - V_37 ;
}
static T_2 F_42 ( struct V_1 * V_2 ,
struct V_29 * V_30 , const char * V_31 , T_3 V_32 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_2 V_36 ;
F_43 ( V_2 ) ;
F_37 ( V_2 ) ;
F_44 ( V_2 ) ;
V_36 = F_25 ( V_2 , V_31 , V_32 ) ;
if ( V_36 >= 0 )
V_36 = F_39 ( V_11 , V_2 ) ;
F_45 ( V_2 , L_10 , V_61 , V_36 < 0 ? L_11 : L_5 , V_36 ) ;
F_38 ( V_2 ) ;
F_46 ( V_2 ) ;
return V_36 < 0 ? V_36 : V_32 ;
}
static T_2 F_47 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
char * V_35 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_35 = V_6 -> V_7 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_35 = V_10 -> V_7 ;
} else
return - V_37 ;
return sprintf ( V_31 , L_12 , V_35 ? V_35 : L_5 ) ;
}
static int F_48 ( struct V_11 * V_11 ,
struct V_46 * V_46 , struct V_50 * V_51 ,
T_4 V_62 )
{
bool V_63 = strncmp ( V_51 -> V_13 , L_13 , 3 ) == 0 ;
struct V_48 * V_49 = F_31 ( V_46 ) ;
int V_36 = 0 ;
while ( V_62 ) {
struct V_53 * V_15 , * V_64 ;
T_4 V_65 ;
V_64 = NULL ;
F_33 (ndd, res)
if ( strcmp ( V_15 -> V_25 , V_51 -> V_13 ) == 0 )
V_64 = V_15 ;
V_15 = V_64 ;
if ( ! V_15 )
return 0 ;
if ( V_62 >= F_34 ( V_15 ) ) {
V_62 -= F_34 ( V_15 ) ;
F_49 ( V_11 , V_49 , V_15 , L_14 , V_36 ) ;
F_50 ( V_49 , V_15 ) ;
continue;
}
if ( V_63 )
V_65 = V_15 -> V_66 + V_62 ;
else
V_65 = V_15 -> V_66 ;
V_36 = F_51 ( V_15 , V_65 , F_34 ( V_15 ) - V_62 ) ;
if ( V_36 == 0 )
V_15 -> V_21 |= V_58 ;
F_49 ( V_11 , V_49 , V_15 , L_15 , V_36 ) ;
break;
}
return V_36 ;
}
static int F_52 ( struct V_11 * V_11 ,
struct V_50 * V_51 , T_4 V_62 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
int V_36 ;
V_36 = F_48 ( V_11 , V_46 , V_51 , V_62 ) ;
if ( V_36 )
return V_36 ;
}
return 0 ;
}
static T_4 F_53 ( struct V_50 * V_51 ,
struct V_11 * V_11 , struct V_46 * V_46 ,
T_4 V_62 )
{
bool V_63 = strncmp ( V_51 -> V_13 , L_13 , 3 ) == 0 ;
struct V_48 * V_49 = F_31 ( V_46 ) ;
T_4 V_68 ;
struct V_53 * V_15 ;
int V_36 = 0 ;
if ( V_63 )
V_68 = V_46 -> V_66 + V_46 -> V_52 - V_62 ;
else
V_68 = V_46 -> V_66 ;
V_15 = F_54 ( V_49 , V_51 , V_68 , V_62 ) ;
if ( ! V_15 )
V_36 = - V_39 ;
F_49 ( V_11 , V_49 , V_15 , L_16 , V_36 ) ;
return V_36 ? V_62 : 0 ;
}
static bool F_55 ( bool V_69 , bool V_70 ,
struct V_50 * V_51 , struct V_53 * V_15 )
{
if ( V_70 || ! V_69 )
return true ;
if ( ! V_15 || strcmp ( V_15 -> V_25 , V_51 -> V_13 ) == 0 )
return true ;
return false ;
}
static T_4 F_56 ( struct V_11 * V_11 ,
struct V_46 * V_46 , struct V_50 * V_51 ,
T_4 V_62 )
{
T_4 V_71 = V_46 -> V_66 + V_46 -> V_52 - 1 ;
bool V_70 = strcmp ( V_51 -> V_13 , L_17 ) == 0 ;
bool V_69 = strncmp ( V_51 -> V_13 , L_18 , 4 ) == 0 ;
struct V_48 * V_49 = F_31 ( V_46 ) ;
const T_4 V_72 = V_62 ;
struct V_53 * V_15 ;
int V_73 ;
V_74:
V_73 = 0 ;
F_33 (ndd, res) {
T_4 V_75 , V_76 = 0 , V_77 , V_78 ;
struct V_53 * V_79 = V_15 -> V_80 , * V_81 = NULL ;
enum V_82 V_83 = V_84 ;
const char * V_85 ;
int V_36 = 0 ;
if ( V_15 -> V_66 > V_71 )
continue;
if ( V_15 -> V_86 < V_46 -> V_66 )
continue;
if ( ! V_73 ++ && V_15 -> V_66 > V_46 -> V_66 ) {
V_77 = V_46 -> V_66 ;
V_76 = V_15 -> V_66 - V_77 ;
if ( F_55 ( V_69 , V_70 , V_51 , NULL ) )
V_83 = V_87 ;
}
if ( ! V_83 && V_79 ) {
V_77 = V_15 -> V_66 + F_34 ( V_15 ) ;
V_78 = F_57 ( V_71 , V_79 -> V_66 - 1 ) ;
if ( F_55 ( V_69 , V_70 , V_51 , V_15 )
&& V_77 < V_78 ) {
V_76 = V_78 + 1 - V_77 ;
V_83 = V_88 ;
}
}
if ( ! V_83 && ! V_79 ) {
V_77 = V_15 -> V_66 + F_34 ( V_15 ) ;
V_78 = V_71 ;
if ( F_55 ( V_69 , V_70 , V_51 , V_15 )
&& V_77 < V_78 ) {
V_76 = V_78 + 1 - V_77 ;
V_83 = V_89 ;
}
}
if ( ! V_83 || ! V_76 )
continue;
V_75 = F_57 ( V_76 , V_62 ) ;
switch ( V_83 ) {
case V_87 :
if ( strcmp ( V_15 -> V_25 , V_51 -> V_13 ) == 0 ) {
if ( V_69 && ! V_70 )
return V_62 ;
V_36 = F_51 ( V_15 , V_15 -> V_66 - V_75 ,
F_34 ( V_15 ) + V_75 ) ;
V_85 = L_19 ;
} else
V_85 = L_20 ;
break;
case V_88 :
if ( strcmp ( V_79 -> V_25 , V_51 -> V_13 ) == 0 ) {
if ( V_69 && ! V_70 )
return V_62 ;
V_36 = F_51 ( V_79 , V_79 -> V_66
- V_75 , F_34 ( V_79 )
+ V_75 ) ;
V_81 = V_79 ;
V_85 = L_21 ;
} else if ( strcmp ( V_15 -> V_25 , V_51 -> V_13 ) == 0 ) {
V_85 = L_22 ;
} else
V_85 = L_20 ;
break;
case V_89 :
if ( strcmp ( V_15 -> V_25 , V_51 -> V_13 ) == 0 )
V_85 = L_22 ;
else
V_85 = L_20 ;
break;
default:
return V_62 ;
}
if ( strcmp ( V_85 , L_20 ) == 0 ) {
if ( ! V_69 )
V_77 += V_76 - V_75 ;
else if ( ! V_70 && V_77 != V_46 -> V_66 )
return V_62 ;
V_81 = F_54 ( V_49 , V_51 ,
V_77 , V_75 ) ;
if ( ! V_81 )
V_36 = - V_39 ;
} else if ( strcmp ( V_85 , L_22 ) == 0 ) {
V_36 = F_51 ( V_15 , V_15 -> V_66 , F_34 ( V_15 )
+ V_75 ) ;
if ( V_36 == 0 )
V_15 -> V_21 |= V_58 ;
}
if ( ! V_81 )
V_81 = V_15 ;
F_49 ( V_11 , V_49 , V_81 , L_23 ,
V_85 , V_83 , V_36 ) ;
if ( V_36 )
return V_62 ;
V_62 -= V_75 ;
if ( V_62 ) {
goto V_74;
} else
return 0 ;
}
if ( ( V_69 || ! V_49 -> V_90 . V_91 ) && V_62 == V_72 )
return F_53 ( V_51 , V_11 , V_46 , V_62 ) ;
return V_62 ;
}
static int F_58 ( struct V_11 * V_11 ,
struct V_46 * V_46 , struct V_50 * V_51 )
{
struct V_48 * V_49 = F_31 ( V_46 ) ;
struct V_53 * V_15 ;
if ( strncmp ( L_18 , V_51 -> V_13 , 4 ) == 0 )
return 0 ;
V_74:
F_33 (ndd, res) {
int V_36 ;
struct V_53 * V_79 = V_15 -> V_80 ;
T_4 V_86 = V_15 -> V_66 + F_34 ( V_15 ) ;
if ( ! V_79 || strcmp ( V_15 -> V_25 , V_51 -> V_13 ) != 0
|| strcmp ( V_79 -> V_25 , V_51 -> V_13 ) != 0
|| V_86 != V_79 -> V_66 )
continue;
V_86 += F_34 ( V_79 ) ;
F_50 ( V_49 , V_79 ) ;
V_36 = F_51 ( V_15 , V_15 -> V_66 , V_86 - V_15 -> V_66 ) ;
F_49 ( V_11 , V_49 , V_15 , L_24 , V_36 ) ;
if ( V_36 )
return V_36 ;
V_15 -> V_21 |= V_58 ;
goto V_74;
}
return 0 ;
}
static int F_59 ( struct V_1 * V_2 , void * V_92 )
{
struct V_93 * V_93 = V_92 ;
struct V_11 * V_11 ;
struct V_50 V_51 ;
int V_56 ;
if ( ! F_60 ( V_2 ) )
return 0 ;
V_11 = F_8 ( V_2 ) ;
if ( V_11 -> V_67 == 0 )
return 0 ;
memset ( & V_51 , 0 , sizeof( V_51 ) ) ;
strcat ( V_51 . V_13 , L_17 ) ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
T_4 V_62 , V_94 = 0 ;
if ( V_46 -> V_93 != V_93 )
continue;
V_62 = F_61 ( V_11 , V_46 , & V_94 ) ;
if ( V_62 == 0 )
return 0 ;
V_94 = F_56 ( V_11 , V_46 , & V_51 , V_62 ) ;
F_20 ( & V_11 -> V_2 , V_94 ,
L_25 ,
( unsigned long long ) V_62 - V_94 ,
( unsigned long long ) V_62 ) ;
return V_94 ? - V_37 : 0 ;
}
return 0 ;
}
static void F_62 ( struct V_95 * V_95 ,
struct V_46 * V_46 )
{
struct V_48 * V_49 = F_31 ( V_46 ) ;
struct V_53 * V_15 , * V_96 ;
F_63 (ndd, res, _res)
if ( strcmp ( V_15 -> V_25 , L_17 ) == 0 )
F_50 ( V_49 , V_15 ) ;
}
static int F_64 ( struct V_95 * V_95 ,
struct V_46 * V_46 )
{
struct V_93 * V_93 = V_46 -> V_93 ;
int V_36 ;
V_36 = F_65 ( & V_95 -> V_2 , V_93 ,
F_59 ) ;
if ( V_36 )
F_62 ( V_95 , V_46 ) ;
return V_36 ;
}
static int F_66 ( struct V_11 * V_11 ,
struct V_50 * V_51 , T_4 V_62 )
{
struct V_95 * V_95 = F_67 ( & V_11 -> V_2 ) ;
bool V_69 = strncmp ( V_51 -> V_13 , L_18 , 4 ) == 0 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
T_4 V_94 = V_62 ;
int V_36 , V_97 ;
for ( V_97 = V_69 ; V_97 < 2 ; V_97 ++ ) {
bool V_98 = V_97 == 0 ;
if ( V_98 ) {
V_36 = F_64 ( V_95 , V_46 ) ;
if ( V_36 )
return V_36 ;
}
V_94 = F_56 ( V_11 , V_46 ,
V_51 , V_94 ) ;
if ( V_98 )
F_62 ( V_95 , V_46 ) ;
if ( V_94 == 0 )
break;
}
F_20 ( & V_11 -> V_2 , V_94 ,
L_26 ,
( unsigned long long ) V_62 - V_94 ,
( unsigned long long ) V_62 ) ;
if ( V_94 )
return - V_37 ;
V_36 = F_58 ( V_11 , V_46 , V_51 ) ;
if ( V_36 )
return V_36 ;
}
return 0 ;
}
static void F_68 ( struct V_11 * V_11 ,
struct V_5 * V_6 , T_4 V_52 )
{
struct V_53 * V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_66 = V_11 -> V_99 ;
V_15 -> V_86 = V_11 -> V_99 + V_52 - 1 ;
}
static T_2 F_69 ( struct V_1 * V_2 , unsigned long long V_100 )
{
T_4 V_101 = 0 , V_76 = 0 ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_46 * V_46 ;
struct V_48 * V_49 ;
struct V_50 V_51 ;
T_5 V_21 = 0 , V_102 ;
T_1 * V_8 = NULL ;
int V_36 , V_56 ;
if ( V_2 -> V_38 || F_26 ( V_2 ) -> V_27 )
return - V_39 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_21 = V_54 ;
}
if ( ! V_8 || V_11 -> V_67 == 0 )
return - V_37 ;
F_70 ( V_100 , V_103 * V_11 -> V_67 , & V_102 ) ;
if ( V_102 ) {
F_45 ( V_2 , L_27 , V_100 ,
( V_103 * V_11 -> V_67 ) / V_104 ) ;
return - V_43 ;
}
F_32 ( & V_51 , V_8 , V_21 ) ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
V_46 = & V_11 -> V_47 [ V_56 ] ;
V_49 = F_31 ( V_46 ) ;
if ( ! V_49 )
return - V_37 ;
V_101 += F_71 ( V_49 , & V_51 ) ;
}
V_76 = F_72 ( V_11 ) ;
if ( V_100 > V_76 + V_101 )
return - V_105 ;
if ( V_100 == V_101 )
return 0 ;
V_100 = F_73 ( V_100 , V_11 -> V_67 ) ;
V_101 = F_73 ( V_101 , V_11 -> V_67 ) ;
if ( V_100 < V_101 )
V_36 = F_52 ( V_11 , & V_51 ,
V_101 - V_100 ) ;
else
V_36 = F_66 ( V_11 , & V_51 , V_100 - V_101 ) ;
if ( V_36 )
return V_36 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
F_68 ( V_11 , V_6 ,
V_100 * V_11 -> V_67 ) ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( V_100 == 0 && V_11 -> V_106 != V_2
&& ! V_10 -> V_45 . V_27 )
F_74 ( V_2 , V_107 ) ;
}
return V_36 ;
}
static T_2 F_75 ( struct V_1 * V_2 ,
struct V_29 * V_30 , const char * V_31 , T_3 V_32 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
unsigned long long V_100 ;
T_1 * * V_8 = NULL ;
int V_36 ;
V_36 = F_76 ( V_31 , 0 , & V_100 ) ;
if ( V_36 )
return V_36 ;
F_43 ( V_2 ) ;
F_37 ( V_2 ) ;
F_44 ( V_2 ) ;
V_36 = F_69 ( V_2 , V_100 ) ;
if ( V_36 >= 0 )
V_36 = F_39 ( V_11 , V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = & V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = & V_10 -> V_8 ;
}
if ( V_36 == 0 && V_100 == 0 && V_8 ) {
F_3 ( * V_8 ) ;
* V_8 = NULL ;
}
F_45 ( V_2 , L_28 , V_61 , V_100 , V_36 < 0
? L_29 : L_30 , V_36 ) ;
F_38 ( V_2 ) ;
F_46 ( V_2 ) ;
return V_36 < 0 ? V_36 : V_32 ;
}
T_4 F_77 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = & V_24 -> V_2 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
return F_34 ( & V_6 -> V_4 . V_15 ) ;
} else if ( F_11 ( V_2 ) ) {
return F_30 ( F_7 ( V_2 ) ) ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_34 ( & V_4 -> V_15 ) ;
} else
F_78 ( 1 , L_31 ) ;
return 0 ;
}
T_4 F_79 ( struct V_23 * V_24 )
{
T_4 V_52 ;
F_37 ( & V_24 -> V_2 ) ;
V_52 = F_77 ( V_24 ) ;
F_38 ( & V_24 -> V_2 ) ;
return V_52 ;
}
static T_2 F_80 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
return sprintf ( V_31 , L_32 , ( unsigned long long )
F_79 ( F_26 ( V_2 ) ) ) ;
}
static T_2 F_81 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
T_1 * V_8 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
} else
return - V_37 ;
if ( V_8 )
return sprintf ( V_31 , L_33 , V_8 ) ;
return sprintf ( V_31 , L_34 ) ;
}
static int F_82 ( struct V_11 * V_11 ,
struct V_1 * V_2 , T_1 * V_108 , T_1 * * V_109 )
{
T_5 V_21 = F_11 ( V_2 ) ? V_54 : 0 ;
struct V_50 V_110 ;
struct V_50 V_111 ;
int V_56 ;
if ( ! F_83 ( V_2 , V_108 ) )
return - V_43 ;
if ( * V_109 == NULL )
goto V_44;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
if ( V_46 -> V_112 )
return - V_39 ;
}
F_32 ( & V_110 , * V_109 , V_21 ) ;
F_32 ( & V_111 , V_108 , V_21 ) ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
struct V_48 * V_49 = F_31 ( V_46 ) ;
struct V_53 * V_15 ;
F_33 (ndd, res)
if ( strcmp ( V_15 -> V_25 , V_110 . V_13 ) == 0 )
sprintf ( ( void * ) V_15 -> V_25 , L_8 ,
V_111 . V_13 ) ;
}
F_3 ( * V_109 ) ;
V_44:
* V_109 = V_108 ;
return 0 ;
}
static T_2 F_84 ( struct V_1 * V_2 ,
struct V_29 * V_30 , const char * V_31 , T_3 V_32 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_1 * V_8 = NULL ;
T_2 V_36 = 0 ;
T_1 * * V_113 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_113 = & V_6 -> V_8 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_113 = & V_10 -> V_8 ;
} else
return - V_37 ;
F_43 ( V_2 ) ;
F_37 ( V_2 ) ;
F_44 ( V_2 ) ;
if ( F_26 ( V_2 ) -> V_27 )
V_36 = - V_39 ;
if ( V_36 >= 0 )
V_36 = F_85 ( V_2 , & V_8 , V_31 , V_32 ) ;
if ( V_36 >= 0 )
V_36 = F_82 ( V_11 , V_2 , V_8 , V_113 ) ;
if ( V_36 >= 0 )
V_36 = F_39 ( V_11 , V_2 ) ;
else
F_3 ( V_8 ) ;
F_45 ( V_2 , L_35 , V_61 ,
V_36 , V_31 , V_31 [ V_32 - 1 ] == '\n' ? L_5 : L_34 ) ;
F_38 ( V_2 ) ;
F_46 ( V_2 ) ;
return V_36 < 0 ? V_36 : V_32 ;
}
static T_2 F_86 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_53 * V_15 ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_15 = & V_6 -> V_4 . V_15 ;
} else if ( F_12 ( V_2 ) ) {
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_15 = & V_4 -> V_15 ;
} else
return - V_37 ;
if ( F_34 ( V_15 ) == 0 )
return - V_37 ;
return sprintf ( V_31 , L_36 , ( unsigned long long ) V_15 -> V_66 ) ;
}
static T_2 F_87 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
if ( ! F_11 ( V_2 ) )
return - V_37 ;
return F_88 ( V_10 -> V_57 , V_114 , V_31 ) ;
}
static T_2 F_89 ( struct V_1 * V_2 ,
struct V_29 * V_30 , const char * V_31 , T_3 V_32 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
T_2 V_36 = 0 ;
if ( ! F_11 ( V_2 ) )
return - V_37 ;
F_43 ( V_2 ) ;
F_37 ( V_2 ) ;
if ( F_26 ( V_2 ) -> V_27 )
V_36 = - V_39 ;
if ( V_36 >= 0 )
V_36 = F_90 ( V_2 , V_31 , & V_10 -> V_57 ,
V_114 ) ;
if ( V_36 >= 0 )
V_36 = F_39 ( V_11 , V_2 ) ;
F_45 ( V_2 , L_37 , V_61 ,
V_36 , V_36 < 0 ? L_38 : L_39 , V_31 ,
V_31 [ V_32 - 1 ] == '\n' ? L_5 : L_34 ) ;
F_38 ( V_2 ) ;
F_46 ( V_2 ) ;
return V_36 ? V_36 : V_32 ;
}
static T_2 F_91 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_11 * V_11 = F_8 ( V_2 -> V_12 ) ;
struct V_50 V_51 ;
int V_55 = 0 , V_56 ;
T_1 * V_8 = NULL ;
T_5 V_21 = 0 ;
F_37 ( V_2 ) ;
if ( F_10 ( V_2 ) ) {
struct V_5 * V_6 = F_5 ( V_2 ) ;
V_8 = V_6 -> V_8 ;
V_21 = 0 ;
} else if ( F_11 ( V_2 ) ) {
struct V_9 * V_10 = F_7 ( V_2 ) ;
V_8 = V_10 -> V_8 ;
V_21 = V_54 ;
}
if ( ! V_8 )
goto V_44;
F_32 ( & V_51 , V_8 , V_21 ) ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
struct V_48 * V_49 = F_31 ( V_46 ) ;
struct V_53 * V_15 ;
F_33 (ndd, res)
if ( strcmp ( V_15 -> V_25 , V_51 . V_13 ) == 0 )
V_55 ++ ;
}
V_44:
F_38 ( V_2 ) ;
return sprintf ( V_31 , L_7 , V_55 ) ;
}
static T_2 F_92 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
struct V_23 * V_24 = F_26 ( V_2 ) ;
T_2 V_36 ;
F_43 ( V_2 ) ;
V_36 = sprintf ( V_31 , L_12 , V_24 -> V_27 ? F_21 ( V_24 -> V_27 ) : L_5 ) ;
F_46 ( V_2 ) ;
return V_36 ;
}
static T_2 F_93 ( struct V_1 * V_2 ,
struct V_29 * V_30 , const char * V_31 , T_3 V_32 )
{
bool V_115 ;
int V_36 = F_94 ( V_31 , & V_115 ) ;
if ( V_36 )
return V_36 ;
F_26 ( V_2 ) -> V_115 = V_115 ;
return V_32 ;
}
static T_2 F_95 ( struct V_1 * V_2 ,
struct V_29 * V_30 , char * V_31 )
{
return sprintf ( V_31 , L_7 , F_26 ( V_2 ) -> V_115 ) ;
}
static T_6 F_96 ( struct V_116 * V_117 ,
struct V_118 * V_119 , int V_62 )
{
struct V_1 * V_2 = F_97 ( V_117 , struct V_1 , V_117 ) ;
if ( V_119 == & V_120 . V_30 ) {
if ( F_11 ( V_2 ) )
return 0 ;
return V_119 -> V_121 ;
}
if ( F_10 ( V_2 ) || F_11 ( V_2 ) ) {
if ( V_119 == & V_122 . V_30 )
return V_123 | V_124 ;
if ( F_10 ( V_2 ) && V_119 == & V_125 . V_30 )
return 0 ;
return V_119 -> V_121 ;
}
if ( V_119 == & V_126 . V_30 || V_119 == & V_122 . V_30
|| V_119 == & V_127 . V_30
|| V_119 == & V_128 . V_30 )
return V_119 -> V_121 ;
return 0 ;
}
struct V_23 * F_98 ( struct V_1 * V_2 )
{
struct V_129 * V_129 = F_17 ( V_2 ) ? F_99 ( V_2 ) : NULL ;
struct V_130 * V_130 = F_16 ( V_2 ) ? F_100 ( V_2 ) : NULL ;
struct V_23 * V_24 ;
T_4 V_52 ;
if ( V_129 || V_130 ) {
struct V_1 * V_131 = NULL ;
if ( V_129 ) {
V_131 = & V_129 -> V_2 ;
V_24 = V_129 -> V_24 ;
} else if ( V_130 ) {
V_131 = & V_130 -> V_2 ;
V_24 = V_130 -> V_24 ;
}
if ( ! V_24 || ! V_131 )
return F_101 ( - V_132 ) ;
F_43 ( & V_24 -> V_2 ) ;
F_46 ( & V_24 -> V_2 ) ;
if ( V_24 -> V_2 . V_38 ) {
F_45 ( & V_24 -> V_2 , L_40 ,
F_21 ( V_131 ) ) ;
return F_101 ( - V_39 ) ;
}
if ( F_20 ( & V_24 -> V_2 , V_24 -> V_27 != V_131 ,
L_41 ,
F_21 ( V_131 ) ,
F_21 ( V_24 -> V_27 ) ) )
return F_101 ( - V_37 ) ;
} else {
V_24 = F_26 ( V_2 ) ;
if ( V_24 -> V_27 ) {
F_45 ( V_2 , L_42 ,
F_21 ( V_24 -> V_27 ) ) ;
return F_101 ( - V_37 ) ;
}
}
V_52 = F_79 ( V_24 ) ;
if ( V_52 < V_133 ) {
F_45 ( & V_24 -> V_2 , L_43 ,
& V_52 , V_133 ) ;
return F_101 ( - V_132 ) ;
}
if ( F_10 ( & V_24 -> V_2 ) ) {
struct V_5 * V_6 ;
V_6 = F_5 ( & V_24 -> V_2 ) ;
if ( ! V_6 -> V_8 ) {
F_45 ( & V_24 -> V_2 , L_44 , V_61 ) ;
return F_101 ( - V_132 ) ;
}
} else if ( F_11 ( & V_24 -> V_2 ) ) {
struct V_9 * V_10 ;
V_10 = F_7 ( & V_24 -> V_2 ) ;
if ( ! F_36 ( V_10 ) )
return F_101 ( - V_132 ) ;
}
return V_24 ;
}
static struct V_1 * * F_102 ( struct V_11 * V_11 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 , * * V_134 ;
struct V_53 * V_15 ;
V_4 = F_29 ( sizeof( * V_4 ) , V_40 ) ;
if ( ! V_4 )
return NULL ;
V_134 = F_103 ( 2 , sizeof( struct V_1 * ) , V_40 ) ;
if ( ! V_134 ) {
F_3 ( V_4 ) ;
return NULL ;
}
V_2 = & V_4 -> V_45 . V_2 ;
V_2 -> type = & V_18 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_15 = & V_4 -> V_15 ;
V_15 -> V_25 = F_21 ( & V_11 -> V_2 ) ;
V_15 -> V_21 = V_135 ;
V_15 -> V_66 = V_11 -> V_99 ;
V_15 -> V_86 = V_15 -> V_66 + V_11 -> V_136 - 1 ;
V_134 [ 0 ] = V_2 ;
return V_134 ;
}
static bool F_104 ( struct V_11 * V_11 , T_1 * V_8 ,
T_7 V_137 , T_8 V_34 )
{
struct V_138 * V_60 = NULL ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
struct V_138 * V_139 ;
bool V_140 = false ;
int V_141 ;
F_105 (l, nd_label, nd_mapping->labels) {
T_7 V_142 = F_106 ( V_139 -> V_142 ) ;
T_8 V_143 = F_107 ( V_139 -> V_143 ) ;
T_8 V_144 = F_107 ( V_139 -> V_144 ) ;
if ( V_142 != V_137 )
continue;
if ( memcmp ( V_139 -> V_8 , V_8 , V_145 ) != 0 )
continue;
if ( V_140 ) {
F_45 ( F_31 ( V_46 ) -> V_2 ,
L_45 ,
V_61 ) ;
return false ;
}
V_140 = true ;
if ( V_144 != V_11 -> V_67 )
continue;
if ( V_143 != V_34 )
continue;
V_60 = V_139 ;
break;
}
if ( V_60 )
break;
}
return V_60 != NULL ;
}
static int F_108 ( struct V_11 * V_11 , T_1 * V_146 )
{
struct V_138 * V_147 = NULL ;
int V_56 ;
if ( ! V_146 )
return - V_132 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
struct V_138 * V_139 ;
T_7 V_148 , V_149 , V_150 , V_151 ;
int V_141 ;
F_105 (l, nd_label, nd_mapping->labels)
if ( memcmp ( V_139 -> V_8 , V_146 , V_145 ) == 0 )
break;
if ( ! V_139 ) {
F_109 ( 1 ) ;
return - V_43 ;
}
V_147 = V_139 ;
V_148 = V_46 -> V_66 ;
V_149 = V_148 + V_46 -> V_52 ;
V_150 = F_106 ( V_147 -> V_90 ) ;
V_151 = V_150 + F_106 ( V_147 -> V_152 ) ;
if ( V_150 == V_148 && V_151 <= V_149 )
;
else
return - V_43 ;
V_46 -> V_112 [ 0 ] = V_147 ;
V_46 -> V_112 [ 1 ] = NULL ;
}
return 0 ;
}
static int F_110 ( struct V_11 * V_11 ,
struct V_5 * V_6 )
{
T_7 V_137 = F_111 ( V_11 ) ;
struct V_138 * V_139 ;
T_1 V_153 [ V_145 ] ;
T_4 V_52 = 0 ;
T_1 * V_146 = NULL ;
int V_36 = - V_132 , V_141 ;
T_8 V_56 ;
if ( V_137 == 0 )
return - V_37 ;
F_105 (l, nd_label, nd_region->mapping[0].labels) {
T_7 V_142 = F_106 ( V_139 -> V_142 ) ;
if ( V_142 != V_137 )
continue;
for ( V_56 = 0 ; V_11 -> V_67 ; V_56 ++ )
if ( ! F_104 ( V_11 , V_139 -> V_8 ,
V_137 , V_56 ) )
break;
if ( V_56 < V_11 -> V_67 ) {
V_36 = - V_43 ;
goto V_154;
} else if ( V_146 ) {
V_36 = - V_39 ;
goto V_154;
}
memcpy ( V_153 , V_139 -> V_8 , V_145 ) ;
V_146 = V_153 ;
}
V_36 = F_108 ( V_11 , V_146 ) ;
if ( V_36 )
goto V_154;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
struct V_138 * V_155 = V_46 -> V_112 [ 0 ] ;
V_52 += F_106 ( V_155 -> V_152 ) ;
if ( F_107 ( V_155 -> V_143 ) != 0 )
continue;
F_109 ( V_6 -> V_7 || V_6 -> V_8 ) ;
V_6 -> V_7 = F_27 ( ( void V_156 * ) V_155 -> V_25 ,
V_42 , V_40 ) ;
V_6 -> V_8 = F_27 ( ( void V_156 * ) V_155 -> V_8 ,
V_145 , V_40 ) ;
}
if ( ! V_6 -> V_7 || ! V_6 -> V_8 ) {
V_36 = - V_41 ;
goto V_154;
}
F_68 ( V_11 , V_6 , V_52 ) ;
return 0 ;
V_154:
switch ( V_36 ) {
case - V_43 :
F_45 ( & V_11 -> V_2 , L_46 , V_61 ) ;
break;
case - V_132 :
F_45 ( & V_11 -> V_2 , L_47 , V_61 ) ;
break;
default:
F_45 ( & V_11 -> V_2 , L_48 ,
V_61 , V_36 ) ;
break;
}
return V_36 ;
}
static struct V_1 * * F_112 ( struct V_11 * V_11 )
{
struct V_5 * V_6 ;
struct V_1 * V_2 , * * V_134 ;
struct V_53 * V_15 ;
int V_36 ;
V_6 = F_29 ( sizeof( * V_6 ) , V_40 ) ;
if ( ! V_6 )
return NULL ;
V_2 = & V_6 -> V_4 . V_45 . V_2 ;
V_2 -> type = & V_16 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_15 = & V_6 -> V_4 . V_15 ;
V_15 -> V_25 = F_21 ( & V_11 -> V_2 ) ;
V_15 -> V_21 = V_135 ;
V_36 = F_110 ( V_11 , V_6 ) ;
if ( V_36 == - V_132 ) {
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
F_3 ( V_46 -> V_112 ) ;
V_46 -> V_112 = NULL ;
}
F_68 ( V_11 , V_6 , 0 ) ;
V_36 = 0 ;
} else if ( V_36 )
goto V_154;
V_134 = F_103 ( 2 , sizeof( struct V_1 * ) , V_40 ) ;
if ( ! V_134 )
goto V_154;
V_134 [ 0 ] = V_2 ;
return V_134 ;
V_154:
F_4 ( & V_6 -> V_4 . V_45 . V_2 ) ;
return NULL ;
}
struct V_53 * F_113 ( struct V_11 * V_11 ,
struct V_48 * V_49 , struct V_9 * V_10 ,
T_4 V_66 )
{
struct V_50 V_51 ;
struct V_53 * V_15 ;
F_32 ( & V_51 , V_10 -> V_8 , V_54 ) ;
V_15 = F_114 ( V_10 -> V_15 ,
sizeof( void * ) * ( V_10 -> V_59 + 1 ) ,
V_40 ) ;
if ( ! V_15 )
return NULL ;
V_10 -> V_15 = (struct V_53 * * ) V_15 ;
F_33 (ndd, res)
if ( strcmp ( V_15 -> V_25 , V_51 . V_13 ) == 0
&& V_15 -> V_66 == V_66 ) {
V_10 -> V_15 [ V_10 -> V_59 ++ ] = V_15 ;
return V_15 ;
}
return NULL ;
}
static struct V_1 * F_115 ( struct V_11 * V_11 )
{
struct V_9 * V_10 ;
struct V_1 * V_2 ;
if ( ! F_116 ( & V_11 -> V_2 ) )
return NULL ;
V_10 = F_29 ( sizeof( * V_10 ) , V_40 ) ;
if ( ! V_10 )
return NULL ;
V_2 = & V_10 -> V_45 . V_2 ;
V_2 -> type = & V_17 ;
V_10 -> V_13 = F_117 ( & V_11 -> V_14 , 0 , 0 , V_40 ) ;
if ( V_10 -> V_13 < 0 ) {
F_3 ( V_10 ) ;
return NULL ;
}
F_118 ( V_2 , L_49 , V_11 -> V_13 , V_10 -> V_13 ) ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_2 -> V_157 = V_158 ;
return & V_10 -> V_45 . V_2 ;
}
void F_119 ( struct V_11 * V_11 )
{
F_109 ( ! F_120 ( & V_11 -> V_2 ) ) ;
V_11 -> V_106 = F_115 ( V_11 ) ;
if ( ! V_11 -> V_106 )
F_121 ( & V_11 -> V_2 , L_50 ) ;
else
F_122 ( V_11 -> V_106 ) ;
}
void F_123 ( struct V_11 * V_11 )
{
F_109 ( ! F_120 ( & V_11 -> V_2 ) ) ;
V_11 -> V_159 = F_124 ( V_11 ) ;
if ( ! V_11 -> V_159 )
F_121 ( & V_11 -> V_2 , L_51 ) ;
}
static struct V_1 * * F_125 ( struct V_11 * V_11 )
{
struct V_46 * V_46 = & V_11 -> V_47 [ 0 ] ;
struct V_138 * V_139 ;
struct V_1 * V_2 , * * V_134 = NULL ;
struct V_9 * V_10 ;
struct V_48 * V_49 ;
int V_56 , V_141 , V_55 = 0 ;
struct V_53 * V_15 ;
if ( V_11 -> V_67 == 0 )
return NULL ;
V_49 = F_31 ( V_46 ) ;
F_105 (l, nd_label, nd_mapping->labels) {
T_5 V_21 = F_126 ( V_139 -> V_21 ) ;
char * V_25 [ V_42 ] ;
struct V_1 * * V_160 ;
if ( V_21 & V_54 )
;
else
continue;
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
V_10 = F_7 ( V_134 [ V_56 ] ) ;
if ( memcmp ( V_10 -> V_8 , V_139 -> V_8 ,
V_145 ) == 0 ) {
V_15 = F_113 ( V_11 , V_49 , V_10 ,
F_106 ( V_139 -> V_90 ) ) ;
if ( ! V_15 )
goto V_154;
F_49 ( V_11 , V_49 , V_15 , L_52 ,
F_21 ( & V_10 -> V_45 . V_2 ) ) ;
break;
}
}
if ( V_56 < V_55 )
continue;
V_160 = F_103 ( V_55 + 2 , sizeof( V_2 ) , V_40 ) ;
if ( ! V_160 )
goto V_154;
memcpy ( V_160 , V_134 , sizeof( V_2 ) * V_55 ) ;
F_3 ( V_134 ) ;
V_134 = V_160 ;
V_10 = F_29 ( sizeof( * V_10 ) , V_40 ) ;
if ( ! V_10 )
goto V_154;
V_2 = & V_10 -> V_45 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_12 = & V_11 -> V_2 ;
F_118 ( V_2 , L_49 , V_11 -> V_13 , V_55 ) ;
V_134 [ V_55 ++ ] = V_2 ;
V_10 -> V_13 = - 1 ;
V_10 -> V_57 = F_106 ( V_139 -> V_57 ) ;
V_10 -> V_8 = F_27 ( V_139 -> V_8 , V_145 ,
V_40 ) ;
if ( ! V_10 -> V_8 )
goto V_154;
memcpy ( V_25 , V_139 -> V_25 , V_42 ) ;
if ( V_25 [ 0 ] )
V_10 -> V_7 = F_27 ( V_25 , V_42 ,
V_40 ) ;
V_15 = F_113 ( V_11 , V_49 , V_10 ,
F_106 ( V_139 -> V_90 ) ) ;
if ( ! V_15 )
goto V_154;
F_49 ( V_11 , V_49 , V_15 , L_52 ,
F_21 ( & V_10 -> V_45 . V_2 ) ) ;
}
F_45 ( & V_11 -> V_2 , L_53 ,
V_61 , V_55 , V_55 == 1 ? L_5 : L_1 ) ;
if ( V_55 == 0 ) {
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
F_3 ( V_46 -> V_112 ) ;
V_46 -> V_112 = NULL ;
}
V_134 = F_103 ( 2 , sizeof( V_2 ) , V_40 ) ;
if ( ! V_134 )
goto V_154;
V_10 = F_29 ( sizeof( * V_10 ) , V_40 ) ;
if ( ! V_10 )
goto V_154;
V_2 = & V_10 -> V_45 . V_2 ;
V_2 -> type = & V_17 ;
V_2 -> V_12 = & V_11 -> V_2 ;
V_134 [ V_55 ++ ] = V_2 ;
}
return V_134 ;
V_154:
for ( V_56 = 0 ; V_56 < V_55 ; V_56 ++ ) {
V_10 = F_7 ( V_134 [ V_56 ] ) ;
F_6 ( & V_10 -> V_45 . V_2 ) ;
}
F_3 ( V_134 ) ;
return NULL ;
}
static int F_127 ( struct V_11 * V_11 )
{
int V_56 ;
for ( V_56 = 0 ; V_56 < V_11 -> V_67 ; V_56 ++ ) {
struct V_46 * V_46 = & V_11 -> V_47 [ V_56 ] ;
struct V_48 * V_49 = F_31 ( V_46 ) ;
struct V_93 * V_93 = V_46 -> V_93 ;
int V_55 , V_97 ;
if ( ! V_49 ) {
if ( ( V_93 -> V_21 & V_161 ) == 0 )
return 0 ;
F_45 ( & V_11 -> V_2 , L_54 ,
F_21 ( & V_46 -> V_93 -> V_2 ) ) ;
return - V_37 ;
}
V_46 -> V_49 = V_49 ;
F_128 ( & V_93 -> V_162 ) ;
F_129 ( V_49 ) ;
V_55 = F_130 ( V_49 ) ;
F_45 ( V_49 -> V_2 , L_55 , V_61 , V_55 ) ;
if ( ! V_55 )
continue;
V_46 -> V_112 = F_103 ( V_55 + 1 , sizeof( void * ) ,
V_40 ) ;
if ( ! V_46 -> V_112 )
return - V_41 ;
for ( V_97 = 0 ; V_97 < V_55 ; V_97 ++ ) {
struct V_138 * V_163 ;
V_163 = F_131 ( V_49 , V_97 ) ;
V_46 -> V_112 [ V_97 ] = V_163 ;
}
}
return 0 ;
}
int F_132 ( struct V_11 * V_11 , int * V_154 )
{
struct V_1 * * V_134 = NULL ;
int V_56 , V_36 = 0 , type ;
* V_154 = 0 ;
F_37 ( & V_11 -> V_2 ) ;
V_36 = F_127 ( V_11 ) ;
if ( V_36 ) {
F_38 ( & V_11 -> V_2 ) ;
return V_36 ;
}
type = F_24 ( V_11 ) ;
switch ( type ) {
case V_164 :
V_134 = F_102 ( V_11 ) ;
break;
case V_165 :
V_134 = F_112 ( V_11 ) ;
break;
case V_166 :
V_134 = F_125 ( V_11 ) ;
break;
default:
break;
}
F_38 ( & V_11 -> V_2 ) ;
if ( ! V_134 )
return - V_132 ;
for ( V_56 = 0 ; V_134 [ V_56 ] ; V_56 ++ ) {
struct V_1 * V_2 = V_134 [ V_56 ] ;
int V_13 ;
if ( type == V_166 ) {
struct V_9 * V_10 ;
V_10 = F_7 ( V_2 ) ;
V_13 = F_117 ( & V_11 -> V_14 , 0 , 0 ,
V_40 ) ;
V_10 -> V_13 = V_13 ;
} else
V_13 = V_56 ;
if ( V_13 < 0 )
break;
F_118 ( V_2 , L_49 , V_11 -> V_13 , V_13 ) ;
V_2 -> V_157 = V_158 ;
F_122 ( V_2 ) ;
}
if ( V_56 )
V_11 -> V_106 = V_134 [ 0 ] ;
if ( V_134 [ V_56 ] ) {
int V_97 ;
for ( V_97 = V_56 ; V_134 [ V_97 ] ; V_97 ++ ) {
struct V_1 * V_2 = V_134 [ V_97 ] ;
F_133 ( V_2 ) ;
F_134 ( V_2 ) ;
}
* V_154 = V_97 - V_56 ;
if ( * V_154 == 0 )
V_36 = - V_132 ;
}
F_3 ( V_134 ) ;
if ( V_36 == - V_132 )
return V_36 ;
return V_56 ;
}

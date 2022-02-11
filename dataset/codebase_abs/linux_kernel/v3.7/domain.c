void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 ) {
if ( ! V_2 -> V_4 )
return;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
F_2 ( V_2 -> V_4 [ V_3 ] ) ;
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
}
static int F_3 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_6 * V_10 ;
const struct V_11 * V_11 = NULL ;
struct V_8 * V_12 = NULL ;
int error = 0 ;
F_4 () ;
V_10 = F_5 ( V_7 ) ;
if ( V_10 ) {
V_11 = F_6 ( V_10 ) ;
V_12 = F_7 ( V_11 ) ;
}
if ( ! V_10 || F_8 ( V_12 ) )
goto V_13;
error = F_9 ( V_10 , V_12 , V_9 , V_14 ) ;
V_13:
F_10 () ;
if ( V_11 )
F_11 ( V_11 ) ;
return error ;
}
static struct V_15 F_12 ( struct V_8 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_1 V_20 ,
unsigned int V_21 )
{
struct V_15 V_22 ;
struct V_23 V_24 = { } ;
unsigned int V_25 ;
if ( F_8 ( V_16 ) ) {
V_22 . V_26 = V_27 | V_28 ;
V_22 . V_29 = V_22 . V_30 = V_22 . V_31 = 0 ;
return V_22 ;
} else if ( ! V_16 -> V_32 . V_33 ) {
return V_34 ;
} else if ( ( V_18 == V_16 -> V_18 ) ) {
F_13 ( V_16 -> V_32 . V_33 , V_21 , V_19 , & V_24 , & V_22 ) ;
if ( F_14 ( V_22 ) & V_20 )
return V_22 ;
}
V_25 = F_15 ( V_16 -> V_32 . V_33 , V_21 , V_18 -> V_35 . V_19 ) ;
V_25 = F_16 ( V_16 -> V_32 . V_33 , V_25 , L_1 , 1 ) ;
F_13 ( V_16 -> V_32 . V_33 , V_25 , V_19 , & V_24 , & V_22 ) ;
return V_22 ;
}
static struct V_8 * F_17 ( const char * V_19 ,
struct V_36 * V_37 )
{
int V_38 = 0 ;
struct V_8 * V_16 , * V_39 = NULL ;
F_18 (profile, head, base.list) {
if ( V_16 -> V_40 & V_41 )
continue;
if ( V_16 -> V_42 && V_16 -> V_43 > V_38 ) {
unsigned int V_25 = F_15 ( V_16 -> V_42 ,
V_44 , V_19 ) ;
T_1 V_45 = F_19 ( V_16 -> V_42 , V_25 ) ;
if ( V_45 & V_46 ) {
V_39 = V_16 ;
V_38 = V_16 -> V_43 ;
}
} else if ( ! strcmp ( V_16 -> V_35 . V_19 , V_19 ) )
return V_16 ;
}
return V_39 ;
}
static struct V_8 * F_20 ( struct V_17 * V_18 ,
struct V_36 * V_47 , const char * V_19 )
{
struct V_8 * V_16 ;
F_21 ( & V_18 -> V_48 ) ;
V_16 = F_22 ( F_17 ( V_19 , V_47 ) ) ;
F_23 ( & V_18 -> V_48 ) ;
return V_16 ;
}
static const char * F_24 ( const char * V_49 , const char * * V_50 )
{
const char * V_19 ;
if ( V_49 [ 0 ] == ':' ) {
* V_50 = V_49 + 1 ;
V_19 = * V_50 + strlen ( * V_50 ) + 1 ;
if ( ! * V_19 )
V_19 = NULL ;
} else {
* V_50 = NULL ;
V_19 = V_49 ;
}
return V_19 ;
}
static const char * F_25 ( int V_51 , const char * V_19 )
{
return NULL ;
}
static struct V_8 * F_26 ( struct V_8 * V_16 , T_1 V_52 )
{
struct V_8 * V_53 = NULL ;
struct V_17 * V_18 = V_16 -> V_18 ;
T_1 V_51 = V_52 & V_54 ;
int V_55 = V_52 & V_56 ;
const char * V_19 ;
for ( V_19 = V_16 -> V_32 . V_57 . V_4 [ V_55 ] ; ! V_53 && V_19 ;
V_19 = F_25 ( V_51 , V_19 ) ) {
struct V_17 * V_58 ;
const char * V_59 = NULL ;
V_58 = NULL ;
if ( V_52 & V_60 ) {
V_53 = F_27 ( V_16 , V_19 ) ;
continue;
} else if ( * V_19 == ':' ) {
const char * V_50 ;
V_59 = V_19 = F_24 ( V_19 , & V_50 ) ;
if ( ! V_59 )
V_59 = V_16 -> V_35 . V_61 ;
if ( * V_50 == '@' ) {
;
}
V_58 = F_28 ( V_18 , V_50 ) ;
if ( ! V_58 )
continue;
} else if ( * V_19 == '@' ) {
continue;
} else {
V_59 = V_19 ;
}
V_53 = F_29 ( V_58 ? V_58 : V_18 , V_59 ) ;
F_30 ( V_58 ) ;
}
return V_53 ;
}
static struct V_8 * F_31 ( struct V_8 * V_16 ,
const char * V_19 , T_1 V_52 )
{
struct V_8 * V_53 = NULL ;
struct V_17 * V_18 = V_16 -> V_18 ;
T_1 V_51 = V_52 & V_54 ;
switch ( V_51 ) {
case V_62 :
return NULL ;
case V_63 :
if ( V_52 & V_60 )
V_53 = F_20 ( V_18 , & V_16 -> V_35 . V_64 ,
V_19 ) ;
else
V_53 = F_20 ( V_18 , & V_18 -> V_35 . V_64 ,
V_19 ) ;
break;
case V_65 :
V_53 = F_26 ( V_16 , V_52 ) ;
break;
}
return V_53 ;
}
int F_32 ( struct V_66 * V_67 )
{
struct V_68 * V_69 ;
struct V_8 * V_16 , * V_53 = NULL ;
struct V_17 * V_18 ;
char * V_70 = NULL ;
unsigned int V_25 ;
struct V_15 V_22 = {} ;
struct V_23 V_24 = {
V_67 -> V_32 -> V_71 . V_72 -> V_73 -> V_74 ,
V_67 -> V_32 -> V_71 . V_72 -> V_73 -> V_75
} ;
const char * V_19 = NULL , * V_76 = NULL , * V_77 = NULL ;
int error = F_33 ( V_67 ) ;
if ( error )
return error ;
if ( V_67 -> V_78 )
return 0 ;
V_69 = V_67 -> V_11 -> V_79 ;
F_34 ( ! V_69 ) ;
V_16 = F_22 ( F_35 ( V_69 -> V_16 ) ) ;
V_18 = V_16 -> V_18 ;
V_25 = V_16 -> V_32 . V_21 ;
error = F_36 ( & V_67 -> V_32 -> V_71 , V_16 -> V_80 , & V_70 ,
& V_19 , & V_77 ) ;
if ( error ) {
if ( V_16 -> V_40 &
( V_81 | V_82 ) )
error = 0 ;
V_19 = V_67 -> V_83 ;
goto V_29;
}
if ( F_8 ( V_16 ) ) {
if ( V_69 -> V_84 )
V_53 = F_22 ( V_69 -> V_84 ) ;
else
V_53 = F_20 ( V_18 , & V_18 -> V_35 . V_64 , V_19 ) ;
if ( ! V_53 )
goto V_85;
goto V_86;
}
V_25 = F_13 ( V_16 -> V_32 . V_33 , V_25 , V_19 , & V_24 , & V_22 ) ;
if ( V_69 -> V_84 ) {
struct V_15 V_87 ;
V_77 = L_2 ;
if ( ! ( V_22 . V_26 & V_28 ) )
goto V_29;
V_25 = F_37 ( V_16 -> V_32 . V_33 , V_25 ) ;
V_87 = F_12 ( V_16 , V_69 -> V_84 -> V_18 ,
V_69 -> V_84 -> V_35 . V_19 ,
V_28 , V_25 ) ;
if ( ! ( V_87 . V_26 & V_28 ) )
goto V_29;
V_53 = F_22 ( F_35 ( V_69 -> V_84 ) ) ;
goto V_86;
}
if ( V_22 . V_26 & V_46 ) {
V_53 = F_31 ( V_16 , V_19 , V_22 . V_52 ) ;
if ( ! V_53 ) {
if ( V_22 . V_52 & V_88 ) {
V_77 = L_3 ;
V_53 = F_22 ( V_16 ) ;
goto V_89;
} else if ( V_22 . V_52 & V_90 ) {
V_53 = F_22 ( V_18 -> F_8 ) ;
V_77 = L_4 ;
} else {
error = - V_91 ;
V_77 = L_5 ;
}
}
} else if ( F_38 ( V_16 ) ) {
V_53 = F_39 ( V_16 , 0 ) ;
if ( ! V_53 ) {
error = - V_92 ;
V_77 = L_6 ;
} else {
error = - V_93 ;
V_76 = V_53 -> V_35 . V_61 ;
}
V_22 . V_52 |= V_94 ;
} else
error = - V_93 ;
if ( V_67 -> V_95 & V_96 ) {
F_40 ( V_53 ) ;
error = - V_97 ;
goto V_85;
}
if ( ! V_53 )
goto V_29;
if ( V_67 -> V_95 & V_98 ) {
;
}
if ( V_67 -> V_95 & ( V_99 | V_100 ) ) {
error = F_3 ( V_101 , V_53 ) ;
if ( error ) {
F_40 ( V_53 ) ;
goto V_29;
}
}
if ( ! ( V_22 . V_52 & V_94 ) ) {
F_41 ( L_7 ,
V_19 , V_53 -> V_35 . V_61 ) ;
V_67 -> V_95 |= V_102 ;
}
V_86:
V_76 = V_53 -> V_35 . V_61 ;
V_67 -> V_103 |= V_104 ;
V_89:
F_40 ( V_69 -> V_16 ) ;
V_69 -> V_16 = V_53 ;
F_40 ( V_69 -> V_105 ) ;
F_40 ( V_69 -> V_84 ) ;
V_69 -> V_105 = NULL ;
V_69 -> V_84 = NULL ;
V_69 -> V_106 = 0 ;
V_29:
error = F_42 ( V_16 , & V_22 , V_107 , V_108 , V_46 ,
V_19 , V_76 , V_24 . V_109 , V_77 , error ) ;
V_85:
F_40 ( V_16 ) ;
F_43 ( V_70 ) ;
return error ;
}
int F_44 ( struct V_66 * V_67 )
{
int V_110 = F_45 ( V_67 ) ;
if ( ! V_110 && ( V_67 -> V_95 & V_102 ) )
V_110 = 1 ;
return V_110 ;
}
void F_46 ( struct V_66 * V_67 )
{
struct V_8 * V_16 = F_47 () ;
struct V_68 * V_111 = V_67 -> V_11 -> V_79 ;
if ( ( V_111 -> V_16 == V_16 ) ||
( F_8 ( V_111 -> V_16 ) ) )
return;
V_101 -> V_112 = 0 ;
F_48 ( V_16 , V_111 -> V_16 ) ;
}
void F_49 ( struct V_66 * V_67 )
{
return;
}
static char * F_50 ( const char * V_113 , const char * V_114 )
{
char * V_19 = F_51 ( strlen ( V_113 ) + strlen ( V_114 ) + 3 , V_107 ) ;
if ( V_19 )
sprintf ( V_19 , L_8 , V_113 , V_114 ) ;
return V_19 ;
}
int F_52 ( const char * V_115 [] , int V_116 , T_2 V_106 , bool V_117 )
{
const struct V_11 * V_11 ;
struct V_68 * V_69 ;
struct V_8 * V_16 , * V_118 , * V_119 = NULL ;
char * V_19 = NULL ;
int V_3 ;
struct V_15 V_22 = {} ;
const char * V_76 = NULL , * V_77 = NULL ;
int error = 0 ;
if ( V_101 -> V_120 )
return - V_97 ;
V_11 = F_53 () ;
V_69 = V_11 -> V_79 ;
V_16 = F_7 ( V_11 ) ;
V_118 = V_69 -> V_105 ;
if ( F_8 ( V_16 ) ) {
V_77 = L_9 ;
error = - V_97 ;
goto V_29;
}
if ( V_116 ) {
struct V_8 * V_121 ;
V_121 = F_54 ( V_16 ) ? V_16 -> V_122 : V_16 ;
for ( V_3 = 0 ; V_3 < V_116 && ! V_119 ; V_3 ++ )
V_119 = F_27 ( V_121 , V_115 [ V_3 ] ) ;
if ( ! V_119 ) {
if ( ! F_38 ( V_121 ) || V_117 ) {
if ( F_55 ( & V_121 -> V_35 . V_64 ) )
error = - V_123 ;
else
error = - V_91 ;
goto V_13;
}
V_19 = F_50 ( V_121 -> V_35 . V_61 , V_115 [ 0 ] ) ;
V_76 = V_19 ;
V_119 = F_39 ( V_16 , 1 ) ;
if ( ! V_119 ) {
V_77 = L_10 ;
error = - V_92 ;
goto V_29;
}
} else {
V_76 = V_119 -> V_35 . V_61 ;
if ( ! F_54 ( V_119 ) ) {
V_77 = L_11 ;
error = - V_97 ;
goto V_29;
}
}
error = F_3 ( V_101 , V_119 ) ;
if ( error ) {
V_77 = L_12 ;
error = - V_97 ;
goto V_29;
}
if ( ! V_117 ) {
error = F_56 ( V_119 , V_106 ) ;
if ( error == - V_93 )
V_22 . V_31 = V_124 ;
else if ( V_19 && ! error )
error = - V_91 ;
}
} else if ( V_118 ) {
V_76 = V_118 -> V_35 . V_61 ;
error = F_57 ( V_106 ) ;
V_22 . V_31 = V_124 ;
} else
goto V_13;
V_29:
if ( ! V_117 )
error = F_42 ( V_16 , & V_22 , V_107 ,
V_125 , V_124 , NULL ,
V_76 , V_126 , V_77 , error ) ;
V_13:
F_40 ( V_119 ) ;
F_43 ( V_19 ) ;
F_11 ( V_11 ) ;
return error ;
}
int F_58 ( const char * V_50 , const char * V_61 , bool V_84 ,
bool V_117 )
{
const struct V_11 * V_11 ;
struct V_68 * V_69 ;
struct V_8 * V_16 , * V_76 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_15 V_22 = {} ;
const char * V_19 = NULL , * V_77 = NULL ;
int V_127 , error = 0 ;
T_1 V_20 ;
if ( ! V_61 && ! V_50 )
return - V_128 ;
if ( V_84 ) {
V_20 = V_28 ;
V_127 = V_129 ;
} else {
V_20 = V_27 ;
V_127 = V_130 ;
}
V_11 = F_53 () ;
V_69 = V_11 -> V_79 ;
V_16 = F_7 ( V_11 ) ;
if ( V_101 -> V_120 && ! F_8 ( V_16 ) ) {
F_11 ( V_11 ) ;
return - V_97 ;
}
if ( V_50 ) {
V_18 = F_28 ( V_16 -> V_18 , V_50 ) ;
if ( ! V_18 ) {
V_19 = V_50 ;
V_77 = L_13 ;
error = - V_91 ;
goto V_29;
}
} else
V_18 = F_59 ( V_16 -> V_18 ) ;
if ( ! V_61 ) {
if ( F_8 ( V_16 ) )
V_61 = V_18 -> F_8 -> V_35 . V_61 ;
else
V_61 = V_16 -> V_35 . V_61 ;
}
V_22 = F_12 ( V_16 , V_18 , V_61 , V_20 ,
V_16 -> V_32 . V_21 ) ;
if ( ! ( V_22 . V_26 & V_20 ) ) {
error = - V_93 ;
goto V_29;
}
V_76 = F_29 ( V_18 , V_61 ) ;
if ( ! V_76 ) {
V_77 = L_5 ;
error = - V_91 ;
if ( V_117 || ! F_38 ( V_16 ) )
goto V_29;
V_76 = F_39 ( V_16 , 0 ) ;
if ( ! V_76 ) {
V_77 = L_10 ;
error = - V_92 ;
goto V_29;
}
}
error = F_3 ( V_101 , V_76 ) ;
if ( error ) {
V_77 = L_14 ;
goto V_29;
}
if ( V_117 )
goto V_29;
if ( V_84 )
error = F_60 ( V_76 ) ;
else
error = F_61 ( V_76 ) ;
V_29:
if ( ! V_117 )
error = F_42 ( V_16 , & V_22 , V_107 , V_127 , V_20 ,
V_19 , V_61 , V_126 , V_77 , error ) ;
F_30 ( V_18 ) ;
F_40 ( V_76 ) ;
F_11 ( V_11 ) ;
return error ;
}

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
F_33 ( V_67 -> V_32 ) -> V_71 ,
F_33 ( V_67 -> V_32 ) -> V_72
} ;
const char * V_19 = NULL , * V_73 = NULL , * V_74 = NULL ;
int error = F_34 ( V_67 ) ;
if ( error )
return error ;
if ( V_67 -> V_75 )
return 0 ;
V_69 = V_67 -> V_11 -> V_76 ;
F_35 ( ! V_69 ) ;
V_16 = F_22 ( F_36 ( V_69 -> V_16 ) ) ;
V_18 = V_16 -> V_18 ;
V_25 = V_16 -> V_32 . V_21 ;
error = F_37 ( & V_67 -> V_32 -> V_77 , V_16 -> V_78 , & V_70 ,
& V_19 , & V_74 ) ;
if ( error ) {
if ( V_16 -> V_40 &
( V_79 | V_80 ) )
error = 0 ;
V_19 = V_67 -> V_81 ;
goto V_29;
}
if ( F_8 ( V_16 ) ) {
if ( V_69 -> V_82 )
V_53 = F_22 ( V_69 -> V_82 ) ;
else
V_53 = F_20 ( V_18 , & V_18 -> V_35 . V_64 , V_19 ) ;
if ( ! V_53 )
goto V_83;
goto V_84;
}
V_25 = F_13 ( V_16 -> V_32 . V_33 , V_25 , V_19 , & V_24 , & V_22 ) ;
if ( V_69 -> V_82 ) {
struct V_15 V_85 ;
V_74 = L_2 ;
if ( ! ( V_22 . V_26 & V_28 ) )
goto V_29;
V_25 = F_38 ( V_16 -> V_32 . V_33 , V_25 ) ;
V_85 = F_12 ( V_16 , V_69 -> V_82 -> V_18 ,
V_69 -> V_82 -> V_35 . V_19 ,
V_28 , V_25 ) ;
if ( ! ( V_85 . V_26 & V_28 ) )
goto V_29;
V_53 = F_22 ( F_36 ( V_69 -> V_82 ) ) ;
goto V_84;
}
if ( V_22 . V_26 & V_46 ) {
V_53 = F_31 ( V_16 , V_19 , V_22 . V_52 ) ;
if ( ! V_53 ) {
if ( V_22 . V_52 & V_86 ) {
V_74 = L_3 ;
V_53 = F_22 ( V_16 ) ;
goto V_87;
} else if ( V_22 . V_52 & V_88 ) {
V_53 = F_22 ( V_18 -> F_8 ) ;
V_74 = L_4 ;
} else {
error = - V_89 ;
V_74 = L_5 ;
}
}
} else if ( F_39 ( V_16 ) ) {
V_53 = F_40 ( V_16 , 0 ) ;
if ( ! V_53 ) {
error = - V_90 ;
V_74 = L_6 ;
} else {
error = - V_91 ;
V_73 = V_53 -> V_35 . V_61 ;
}
V_22 . V_52 |= V_92 ;
} else
error = - V_91 ;
if ( V_67 -> V_93 & V_94 ) {
F_41 ( V_53 ) ;
error = - V_95 ;
goto V_83;
}
if ( ! V_53 )
goto V_29;
if ( V_67 -> V_93 & V_96 ) {
;
}
if ( V_67 -> V_93 & ( V_97 | V_98 ) ) {
error = F_3 ( V_99 , V_53 ) ;
if ( error ) {
F_41 ( V_53 ) ;
goto V_29;
}
}
if ( ! ( V_22 . V_52 & V_92 ) ) {
F_42 ( L_7 ,
V_19 , V_53 -> V_35 . V_61 ) ;
V_67 -> V_93 |= V_100 ;
}
V_84:
V_73 = V_53 -> V_35 . V_61 ;
V_67 -> V_101 |= V_102 ;
V_87:
F_41 ( V_69 -> V_16 ) ;
V_69 -> V_16 = V_53 ;
F_41 ( V_69 -> V_103 ) ;
F_41 ( V_69 -> V_82 ) ;
V_69 -> V_103 = NULL ;
V_69 -> V_82 = NULL ;
V_69 -> V_104 = 0 ;
V_29:
error = F_43 ( V_16 , & V_22 , V_105 , V_106 , V_46 ,
V_19 , V_73 , V_24 . V_107 , V_74 , error ) ;
V_83:
F_41 ( V_16 ) ;
F_44 ( V_70 ) ;
return error ;
}
int F_45 ( struct V_66 * V_67 )
{
int V_108 = F_46 ( V_67 ) ;
if ( ! V_108 && ( V_67 -> V_93 & V_100 ) )
V_108 = 1 ;
return V_108 ;
}
void F_47 ( struct V_66 * V_67 )
{
struct V_8 * V_16 = F_48 () ;
struct V_68 * V_109 = V_67 -> V_11 -> V_76 ;
if ( ( V_109 -> V_16 == V_16 ) ||
( F_8 ( V_109 -> V_16 ) ) )
return;
V_99 -> V_110 = 0 ;
F_49 ( V_16 , V_109 -> V_16 ) ;
}
void F_50 ( struct V_66 * V_67 )
{
return;
}
static char * F_51 ( const char * V_111 , const char * V_112 )
{
char * V_19 = F_52 ( strlen ( V_111 ) + strlen ( V_112 ) + 3 , V_105 ) ;
if ( V_19 )
sprintf ( V_19 , L_8 , V_111 , V_112 ) ;
return V_19 ;
}
int F_53 ( const char * V_113 [] , int V_114 , T_2 V_104 , bool V_115 )
{
const struct V_11 * V_11 ;
struct V_68 * V_69 ;
struct V_8 * V_16 , * V_116 , * V_117 = NULL ;
char * V_19 = NULL ;
int V_3 ;
struct V_15 V_22 = {} ;
const char * V_73 = NULL , * V_74 = NULL ;
int error = 0 ;
if ( V_99 -> V_118 )
return - V_95 ;
V_11 = F_54 () ;
V_69 = V_11 -> V_76 ;
V_16 = F_7 ( V_11 ) ;
V_116 = V_69 -> V_103 ;
if ( F_8 ( V_16 ) ) {
V_74 = L_9 ;
error = - V_95 ;
goto V_29;
}
if ( V_114 ) {
struct V_8 * V_119 ;
V_119 = F_55 ( V_16 ) ? V_16 -> V_120 : V_16 ;
for ( V_3 = 0 ; V_3 < V_114 && ! V_117 ; V_3 ++ )
V_117 = F_27 ( V_119 , V_113 [ V_3 ] ) ;
if ( ! V_117 ) {
if ( ! F_39 ( V_119 ) || V_115 ) {
if ( F_56 ( & V_119 -> V_35 . V_64 ) )
error = - V_121 ;
else
error = - V_89 ;
goto V_13;
}
V_19 = F_51 ( V_119 -> V_35 . V_61 , V_113 [ 0 ] ) ;
V_73 = V_19 ;
V_117 = F_40 ( V_16 , 1 ) ;
if ( ! V_117 ) {
V_74 = L_10 ;
error = - V_90 ;
goto V_29;
}
} else {
V_73 = V_117 -> V_35 . V_61 ;
if ( ! F_55 ( V_117 ) ) {
V_74 = L_11 ;
error = - V_95 ;
goto V_29;
}
}
error = F_3 ( V_99 , V_117 ) ;
if ( error ) {
V_74 = L_12 ;
error = - V_95 ;
goto V_29;
}
if ( ! V_115 ) {
error = F_57 ( V_117 , V_104 ) ;
if ( error == - V_91 )
V_22 . V_31 = V_122 ;
else if ( V_19 && ! error )
error = - V_89 ;
}
} else if ( V_116 ) {
V_73 = V_116 -> V_35 . V_61 ;
error = F_58 ( V_104 ) ;
V_22 . V_31 = V_122 ;
} else
goto V_13;
V_29:
if ( ! V_115 )
error = F_43 ( V_16 , & V_22 , V_105 ,
V_123 , V_122 , NULL ,
V_73 , V_124 , V_74 , error ) ;
V_13:
F_41 ( V_117 ) ;
F_44 ( V_19 ) ;
F_11 ( V_11 ) ;
return error ;
}
int F_59 ( const char * V_50 , const char * V_61 , bool V_82 ,
bool V_115 )
{
const struct V_11 * V_11 ;
struct V_68 * V_69 ;
struct V_8 * V_16 , * V_73 = NULL ;
struct V_17 * V_18 = NULL ;
struct V_15 V_22 = {} ;
const char * V_19 = NULL , * V_74 = NULL ;
int V_125 , error = 0 ;
T_1 V_20 ;
if ( ! V_61 && ! V_50 )
return - V_126 ;
if ( V_82 ) {
V_20 = V_28 ;
V_125 = V_127 ;
} else {
V_20 = V_27 ;
V_125 = V_128 ;
}
V_11 = F_54 () ;
V_69 = V_11 -> V_76 ;
V_16 = F_7 ( V_11 ) ;
if ( V_99 -> V_118 && ! F_8 ( V_16 ) ) {
F_11 ( V_11 ) ;
return - V_95 ;
}
if ( V_50 ) {
V_18 = F_28 ( V_16 -> V_18 , V_50 ) ;
if ( ! V_18 ) {
V_19 = V_50 ;
V_74 = L_13 ;
error = - V_89 ;
goto V_29;
}
} else
V_18 = F_60 ( V_16 -> V_18 ) ;
if ( ! V_61 ) {
if ( F_8 ( V_16 ) )
V_61 = V_18 -> F_8 -> V_35 . V_61 ;
else
V_61 = V_16 -> V_35 . V_61 ;
}
V_22 = F_12 ( V_16 , V_18 , V_61 , V_20 ,
V_16 -> V_32 . V_21 ) ;
if ( ! ( V_22 . V_26 & V_20 ) ) {
error = - V_91 ;
goto V_29;
}
V_73 = F_29 ( V_18 , V_61 ) ;
if ( ! V_73 ) {
V_74 = L_5 ;
error = - V_89 ;
if ( V_115 || ! F_39 ( V_16 ) )
goto V_29;
V_73 = F_40 ( V_16 , 0 ) ;
if ( ! V_73 ) {
V_74 = L_10 ;
error = - V_90 ;
goto V_29;
}
}
error = F_3 ( V_99 , V_73 ) ;
if ( error ) {
V_74 = L_14 ;
goto V_29;
}
if ( V_115 )
goto V_29;
if ( V_82 )
error = F_61 ( V_73 ) ;
else
error = F_62 ( V_73 ) ;
V_29:
if ( ! V_115 )
error = F_43 ( V_16 , & V_22 , V_105 , V_125 , V_20 ,
V_19 , V_61 , V_124 , V_74 , error ) ;
F_30 ( V_18 ) ;
F_41 ( V_73 ) ;
F_11 ( V_11 ) ;
return error ;
}

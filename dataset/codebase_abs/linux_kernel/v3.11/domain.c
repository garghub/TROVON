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
struct V_8 * V_11 = NULL ;
int error = 0 ;
F_4 () ;
V_10 = F_5 ( V_7 ) ;
if ( V_10 )
V_11 = F_6 ( V_10 ) ;
if ( ! V_10 || F_7 ( V_11 ) )
goto V_12;
error = F_8 ( V_10 , V_11 , V_9 , V_13 ) ;
V_12:
F_9 () ;
F_10 ( V_11 ) ;
return error ;
}
static struct V_14 F_11 ( struct V_8 * V_15 ,
struct V_16 * V_17 ,
const char * V_18 , T_1 V_19 ,
unsigned int V_20 )
{
struct V_14 V_21 ;
struct V_22 V_23 = { } ;
unsigned int V_24 ;
if ( F_7 ( V_15 ) ) {
V_21 . V_25 = V_26 | V_27 ;
V_21 . V_28 = V_21 . V_29 = V_21 . V_30 = 0 ;
return V_21 ;
} else if ( ! V_15 -> V_31 . V_32 ) {
return V_33 ;
} else if ( ( V_17 == V_15 -> V_17 ) ) {
F_12 ( V_15 -> V_31 . V_32 , V_20 , V_18 , & V_23 , & V_21 ) ;
if ( F_13 ( V_21 ) & V_19 )
return V_21 ;
}
V_24 = F_14 ( V_15 -> V_31 . V_32 , V_20 , V_17 -> V_34 . V_18 ) ;
V_24 = F_15 ( V_15 -> V_31 . V_32 , V_24 , L_1 , 1 ) ;
F_12 ( V_15 -> V_31 . V_32 , V_24 , V_18 , & V_23 , & V_21 ) ;
return V_21 ;
}
static struct V_8 * F_16 ( const char * V_18 ,
struct V_35 * V_36 )
{
int V_37 = 0 ;
struct V_8 * V_15 , * V_38 = NULL ;
F_17 (profile, head, base.list) {
if ( V_15 -> V_39 & V_40 )
continue;
if ( V_15 -> V_41 && V_15 -> V_42 > V_37 ) {
unsigned int V_24 = F_14 ( V_15 -> V_41 ,
V_43 , V_18 ) ;
T_1 V_44 = F_18 ( V_15 -> V_41 , V_24 ) ;
if ( V_44 & V_45 ) {
V_38 = V_15 ;
V_37 = V_15 -> V_42 ;
}
} else if ( ! strcmp ( V_15 -> V_34 . V_18 , V_18 ) )
return V_15 ;
}
return V_38 ;
}
static struct V_8 * F_19 ( struct V_16 * V_17 ,
struct V_35 * V_46 , const char * V_18 )
{
struct V_8 * V_15 ;
F_20 ( & V_17 -> V_47 ) ;
V_15 = F_21 ( F_16 ( V_18 , V_46 ) ) ;
F_22 ( & V_17 -> V_47 ) ;
return V_15 ;
}
static const char * F_23 ( const char * V_48 , const char * * V_49 )
{
const char * V_18 ;
if ( V_48 [ 0 ] == ':' ) {
* V_49 = V_48 + 1 ;
V_18 = * V_49 + strlen ( * V_49 ) + 1 ;
if ( ! * V_18 )
V_18 = NULL ;
} else {
* V_49 = NULL ;
V_18 = V_48 ;
}
return V_18 ;
}
static const char * F_24 ( int V_50 , const char * V_18 )
{
return NULL ;
}
static struct V_8 * F_25 ( struct V_8 * V_15 , T_1 V_51 )
{
struct V_8 * V_52 = NULL ;
struct V_16 * V_17 = V_15 -> V_17 ;
T_1 V_50 = V_51 & V_53 ;
int V_54 = V_51 & V_55 ;
const char * V_18 ;
for ( V_18 = V_15 -> V_31 . V_56 . V_4 [ V_54 ] ; ! V_52 && V_18 ;
V_18 = F_24 ( V_50 , V_18 ) ) {
struct V_16 * V_57 ;
const char * V_58 = NULL ;
V_57 = NULL ;
if ( V_51 & V_59 ) {
V_52 = F_26 ( V_15 , V_18 ) ;
continue;
} else if ( * V_18 == ':' ) {
const char * V_49 ;
V_58 = V_18 = F_23 ( V_18 , & V_49 ) ;
if ( ! V_58 )
V_58 = V_15 -> V_34 . V_60 ;
if ( * V_49 == '@' ) {
;
}
V_57 = F_27 ( V_17 , V_49 ) ;
if ( ! V_57 )
continue;
} else if ( * V_18 == '@' ) {
continue;
} else {
V_58 = V_18 ;
}
V_52 = F_28 ( V_57 ? V_57 : V_17 , V_58 ) ;
F_29 ( V_57 ) ;
}
return V_52 ;
}
static struct V_8 * F_30 ( struct V_8 * V_15 ,
const char * V_18 , T_1 V_51 )
{
struct V_8 * V_52 = NULL ;
struct V_16 * V_17 = V_15 -> V_17 ;
T_1 V_50 = V_51 & V_53 ;
switch ( V_50 ) {
case V_61 :
return NULL ;
case V_62 :
if ( V_51 & V_59 )
V_52 = F_19 ( V_17 , & V_15 -> V_34 . V_63 ,
V_18 ) ;
else
V_52 = F_19 ( V_17 , & V_17 -> V_34 . V_63 ,
V_18 ) ;
break;
case V_64 :
V_52 = F_25 ( V_15 , V_51 ) ;
break;
}
return V_52 ;
}
int F_31 ( struct V_65 * V_66 )
{
struct V_67 * V_68 ;
struct V_8 * V_15 , * V_52 = NULL ;
struct V_16 * V_17 ;
char * V_69 = NULL ;
unsigned int V_24 ;
struct V_14 V_21 = {} ;
struct V_22 V_23 = {
F_32 ( V_66 -> V_31 ) -> V_70 ,
F_32 ( V_66 -> V_31 ) -> V_71
} ;
const char * V_18 = NULL , * V_72 = NULL , * V_73 = NULL ;
int error = F_33 ( V_66 ) ;
if ( error )
return error ;
if ( V_66 -> V_74 )
return 0 ;
V_68 = F_34 ( V_66 -> V_75 ) ;
F_35 ( ! V_68 ) ;
V_15 = F_21 ( F_36 ( V_68 -> V_15 ) ) ;
V_17 = V_15 -> V_17 ;
V_24 = V_15 -> V_31 . V_20 ;
error = F_37 ( & V_66 -> V_31 -> V_76 , V_15 -> V_77 , & V_69 ,
& V_18 , & V_73 ) ;
if ( error ) {
if ( V_15 -> V_39 &
( V_78 | V_79 ) )
error = 0 ;
V_18 = V_66 -> V_80 ;
goto V_28;
}
if ( F_7 ( V_15 ) ) {
if ( V_68 -> V_81 )
V_52 = F_21 ( V_68 -> V_81 ) ;
else
V_52 = F_19 ( V_17 , & V_17 -> V_34 . V_63 , V_18 ) ;
if ( ! V_52 )
goto V_82;
goto V_83;
}
V_24 = F_12 ( V_15 -> V_31 . V_32 , V_24 , V_18 , & V_23 , & V_21 ) ;
if ( V_68 -> V_81 ) {
struct V_14 V_84 ;
V_73 = L_2 ;
if ( ! ( V_21 . V_25 & V_27 ) )
goto V_28;
V_24 = F_38 ( V_15 -> V_31 . V_32 , V_24 ) ;
V_84 = F_11 ( V_15 , V_68 -> V_81 -> V_17 ,
V_68 -> V_81 -> V_34 . V_18 ,
V_27 , V_24 ) ;
if ( ! ( V_84 . V_25 & V_27 ) )
goto V_28;
V_52 = F_21 ( F_36 ( V_68 -> V_81 ) ) ;
goto V_83;
}
if ( V_21 . V_25 & V_45 ) {
V_52 = F_30 ( V_15 , V_18 , V_21 . V_51 ) ;
if ( ! V_52 ) {
if ( V_21 . V_51 & V_85 ) {
V_73 = L_3 ;
V_52 = F_21 ( V_15 ) ;
goto V_86;
} else if ( V_21 . V_51 & V_87 ) {
V_52 = F_21 ( V_17 -> F_7 ) ;
V_73 = L_4 ;
} else {
error = - V_88 ;
V_73 = L_5 ;
V_21 . V_25 &= ~ V_45 ;
}
}
} else if ( F_39 ( V_15 ) ) {
V_52 = F_40 ( V_15 , 0 ) ;
if ( ! V_52 ) {
error = - V_89 ;
V_73 = L_6 ;
} else {
error = - V_90 ;
V_72 = V_52 -> V_34 . V_60 ;
}
V_21 . V_51 |= V_91 ;
} else
error = - V_90 ;
if ( V_66 -> V_92 & V_93 ) {
F_10 ( V_52 ) ;
error = - V_94 ;
goto V_82;
}
if ( ! V_52 )
goto V_28;
if ( V_66 -> V_92 & V_95 ) {
;
}
if ( V_66 -> V_92 & ( V_96 | V_97 ) ) {
error = F_3 ( V_98 , V_52 ) ;
if ( error ) {
F_10 ( V_52 ) ;
goto V_28;
}
}
if ( ! ( V_21 . V_51 & V_91 ) ) {
F_41 ( L_7 ,
V_18 , V_52 -> V_34 . V_60 ) ;
V_66 -> V_92 |= V_99 ;
}
V_83:
V_72 = V_52 -> V_34 . V_60 ;
V_66 -> V_100 |= V_101 ;
V_86:
F_10 ( V_68 -> V_15 ) ;
V_68 -> V_15 = V_52 ;
F_42 ( V_68 ) ;
V_28:
error = F_43 ( V_15 , & V_21 , V_102 , V_103 , V_45 ,
V_18 , V_72 , V_23 . V_104 , V_73 , error ) ;
V_82:
F_10 ( V_15 ) ;
F_44 ( V_69 ) ;
return error ;
}
int F_45 ( struct V_65 * V_66 )
{
int V_105 = F_46 ( V_66 ) ;
if ( ! V_105 && ( V_66 -> V_92 & V_99 ) )
V_105 = 1 ;
return V_105 ;
}
void F_47 ( struct V_65 * V_66 )
{
struct V_8 * V_15 = F_48 () ;
struct V_67 * V_106 = F_34 ( V_66 -> V_75 ) ;
if ( ( V_106 -> V_15 == V_15 ) ||
( F_7 ( V_106 -> V_15 ) ) )
return;
V_98 -> V_107 = 0 ;
F_49 ( V_15 , V_106 -> V_15 ) ;
}
void F_50 ( struct V_65 * V_66 )
{
return;
}
static char * F_51 ( const char * V_108 , const char * V_109 )
{
char * V_18 = F_52 ( strlen ( V_108 ) + strlen ( V_109 ) + 3 , V_102 ) ;
if ( V_18 )
sprintf ( V_18 , L_8 , V_108 , V_109 ) ;
return V_18 ;
}
int F_53 ( const char * V_110 [] , int V_111 , T_2 V_112 , bool V_113 )
{
const struct V_75 * V_75 ;
struct V_67 * V_68 ;
struct V_8 * V_15 , * V_114 , * V_115 = NULL ;
char * V_18 = NULL ;
int V_3 ;
struct V_14 V_21 = {} ;
const char * V_72 = NULL , * V_73 = NULL ;
int error = 0 ;
if ( V_98 -> V_116 )
return - V_94 ;
V_75 = F_54 () ;
V_68 = F_34 ( V_75 ) ;
V_15 = F_55 ( V_75 ) ;
V_114 = V_68 -> V_117 ;
if ( F_7 ( V_15 ) ) {
V_73 = L_9 ;
error = - V_94 ;
goto V_28;
}
if ( V_111 ) {
struct V_8 * V_118 ;
V_118 = F_56 ( V_15 ) ? V_15 -> V_119 : V_15 ;
for ( V_3 = 0 ; V_3 < V_111 && ! V_115 ; V_3 ++ )
V_115 = F_26 ( V_118 , V_110 [ V_3 ] ) ;
if ( ! V_115 ) {
if ( ! F_39 ( V_118 ) || V_113 ) {
if ( F_57 ( & V_118 -> V_34 . V_63 ) )
error = - V_120 ;
else
error = - V_88 ;
goto V_12;
}
V_18 = F_51 ( V_118 -> V_34 . V_60 , V_110 [ 0 ] ) ;
V_72 = V_18 ;
V_115 = F_40 ( V_15 , 1 ) ;
if ( ! V_115 ) {
V_73 = L_10 ;
error = - V_89 ;
goto V_28;
}
} else {
V_72 = V_115 -> V_34 . V_60 ;
if ( ! F_56 ( V_115 ) ) {
V_73 = L_11 ;
error = - V_94 ;
goto V_28;
}
}
error = F_3 ( V_98 , V_115 ) ;
if ( error ) {
V_73 = L_12 ;
error = - V_94 ;
goto V_28;
}
if ( ! V_113 ) {
error = F_58 ( V_115 , V_112 ) ;
if ( error == - V_90 )
V_21 . V_30 = V_121 ;
else if ( V_18 && ! error )
error = - V_88 ;
}
} else if ( V_114 ) {
V_72 = V_114 -> V_34 . V_60 ;
error = F_59 ( V_112 ) ;
V_21 . V_30 = V_121 ;
} else
goto V_12;
V_28:
if ( ! V_113 )
error = F_43 ( V_15 , & V_21 , V_102 ,
V_122 , V_121 , NULL ,
V_72 , V_123 , V_73 , error ) ;
V_12:
F_10 ( V_115 ) ;
F_44 ( V_18 ) ;
F_60 ( V_75 ) ;
return error ;
}
int F_61 ( const char * V_49 , const char * V_60 , bool V_81 ,
bool V_113 )
{
const struct V_75 * V_75 ;
struct V_8 * V_15 , * V_72 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_14 V_21 = {} ;
const char * V_18 = NULL , * V_73 = NULL ;
int V_124 , error = 0 ;
T_1 V_19 ;
if ( ! V_60 && ! V_49 )
return - V_125 ;
if ( V_81 ) {
V_19 = V_27 ;
V_124 = V_126 ;
} else {
V_19 = V_26 ;
V_124 = V_127 ;
}
V_75 = F_54 () ;
V_15 = F_55 ( V_75 ) ;
if ( V_98 -> V_116 && ! F_7 ( V_15 ) ) {
F_60 ( V_75 ) ;
return - V_94 ;
}
if ( V_49 ) {
V_17 = F_27 ( V_15 -> V_17 , V_49 ) ;
if ( ! V_17 ) {
V_18 = V_49 ;
V_73 = L_13 ;
error = - V_88 ;
goto V_28;
}
} else
V_17 = F_62 ( V_15 -> V_17 ) ;
if ( ! V_60 ) {
if ( F_7 ( V_15 ) )
V_60 = V_17 -> F_7 -> V_34 . V_60 ;
else
V_60 = V_15 -> V_34 . V_60 ;
}
V_21 = F_11 ( V_15 , V_17 , V_60 , V_19 ,
V_15 -> V_31 . V_20 ) ;
if ( ! ( V_21 . V_25 & V_19 ) ) {
error = - V_90 ;
goto V_28;
}
V_72 = F_28 ( V_17 , V_60 ) ;
if ( ! V_72 ) {
V_73 = L_5 ;
error = - V_88 ;
if ( V_113 || ! F_39 ( V_15 ) )
goto V_28;
V_72 = F_40 ( V_15 , 0 ) ;
if ( ! V_72 ) {
V_73 = L_10 ;
error = - V_89 ;
goto V_28;
}
}
error = F_3 ( V_98 , V_72 ) ;
if ( error ) {
V_73 = L_14 ;
goto V_28;
}
if ( V_113 )
goto V_28;
if ( V_81 )
error = F_63 ( V_72 ) ;
else
error = F_64 ( V_72 ) ;
V_28:
if ( ! V_113 )
error = F_43 ( V_15 , & V_21 , V_102 , V_124 , V_19 ,
V_18 , V_60 , V_123 , V_73 , error ) ;
F_29 ( V_17 ) ;
F_10 ( V_72 ) ;
F_60 ( V_75 ) ;
return error ;
}

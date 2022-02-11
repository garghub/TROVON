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
static int F_3 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_6 * V_10 = NULL ;
int error = 0 ;
F_4 () ;
V_9 = F_5 ( V_11 ) ;
if ( V_9 )
V_10 = F_6 ( V_9 ) ;
if ( ! V_9 || F_7 ( V_10 ) )
goto V_12;
error = F_8 ( V_10 , V_7 , V_13 ) ;
V_12:
F_9 () ;
F_10 ( V_10 ) ;
return error ;
}
static struct V_14 F_11 ( struct V_6 * V_15 ,
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
static struct V_6 * F_16 ( const char * V_18 ,
struct V_35 * V_36 )
{
int V_37 = 0 ;
struct V_6 * V_15 , * V_38 = NULL ;
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
static struct V_6 * F_19 ( struct V_16 * V_17 ,
struct V_35 * V_46 , const char * V_18 )
{
struct V_6 * V_15 ;
F_4 () ;
V_15 = F_20 ( F_16 ( V_18 , V_46 ) ) ;
F_9 () ;
return V_15 ;
}
static const char * F_21 ( const char * V_47 , const char * * V_48 )
{
const char * V_18 ;
if ( V_47 [ 0 ] == ':' ) {
* V_48 = V_47 + 1 ;
V_18 = * V_48 + strlen ( * V_48 ) + 1 ;
if ( ! * V_18 )
V_18 = NULL ;
} else {
* V_48 = NULL ;
V_18 = V_47 ;
}
return V_18 ;
}
static const char * F_22 ( int V_49 , const char * V_18 )
{
return NULL ;
}
static struct V_6 * F_23 ( struct V_6 * V_15 , T_1 V_50 )
{
struct V_6 * V_51 = NULL ;
struct V_16 * V_17 = V_15 -> V_17 ;
T_1 V_49 = V_50 & V_52 ;
int V_53 = V_50 & V_54 ;
const char * V_18 ;
for ( V_18 = V_15 -> V_31 . V_55 . V_4 [ V_53 ] ; ! V_51 && V_18 ;
V_18 = F_22 ( V_49 , V_18 ) ) {
struct V_16 * V_56 ;
const char * V_57 = NULL ;
V_56 = NULL ;
if ( V_50 & V_58 ) {
V_51 = F_24 ( V_15 , V_18 ) ;
continue;
} else if ( * V_18 == ':' ) {
const char * V_48 ;
V_57 = V_18 = F_21 ( V_18 , & V_48 ) ;
if ( ! V_57 )
V_57 = V_15 -> V_34 . V_59 ;
if ( * V_48 == '@' ) {
;
}
V_56 = F_25 ( V_17 , V_48 ) ;
if ( ! V_56 )
continue;
} else if ( * V_18 == '@' ) {
continue;
} else {
V_57 = V_18 ;
}
V_51 = F_26 ( V_56 ? V_56 : V_17 , V_57 ) ;
F_27 ( V_56 ) ;
}
return V_51 ;
}
static struct V_6 * F_28 ( struct V_6 * V_15 ,
const char * V_18 , T_1 V_50 )
{
struct V_6 * V_51 = NULL ;
struct V_16 * V_17 = V_15 -> V_17 ;
T_1 V_49 = V_50 & V_52 ;
switch ( V_49 ) {
case V_60 :
return NULL ;
case V_61 :
if ( V_50 & V_58 )
V_51 = F_19 ( V_17 , & V_15 -> V_34 . V_62 ,
V_18 ) ;
else
V_51 = F_19 ( V_17 , & V_17 -> V_34 . V_62 ,
V_18 ) ;
break;
case V_63 :
V_51 = F_23 ( V_15 , V_50 ) ;
break;
}
return V_51 ;
}
int F_29 ( struct V_64 * V_65 )
{
struct V_66 * V_67 ;
struct V_6 * V_15 , * V_51 = NULL ;
struct V_16 * V_17 ;
char * V_68 = NULL ;
unsigned int V_24 ;
struct V_14 V_21 = {} ;
struct V_22 V_23 = {
F_30 ( V_65 -> V_31 ) -> V_69 ,
F_30 ( V_65 -> V_31 ) -> V_70
} ;
const char * V_18 = NULL , * V_71 = NULL ;
int error = 0 ;
if ( V_65 -> V_72 )
return 0 ;
V_67 = F_31 ( V_65 -> V_73 ) ;
F_32 ( ! V_67 ) ;
V_15 = F_33 ( V_67 -> V_15 ) ;
V_17 = V_15 -> V_17 ;
V_24 = V_15 -> V_31 . V_20 ;
error = F_34 ( & V_65 -> V_31 -> V_74 , V_15 -> V_75 , & V_68 ,
& V_18 , & V_71 ) ;
if ( error ) {
if ( F_7 ( V_15 ) ||
( V_15 -> V_39 & V_76 ) )
error = 0 ;
V_18 = V_65 -> V_77 ;
goto V_28;
}
if ( F_7 ( V_15 ) ) {
if ( V_67 -> V_78 )
V_51 = F_20 ( V_67 -> V_78 ) ;
else
V_51 = F_19 ( V_17 , & V_17 -> V_34 . V_62 , V_18 ) ;
if ( ! V_51 )
goto V_79;
goto V_80;
}
V_24 = F_12 ( V_15 -> V_31 . V_32 , V_24 , V_18 , & V_23 , & V_21 ) ;
if ( V_67 -> V_78 ) {
struct V_14 V_81 ;
V_71 = L_2 ;
V_51 = F_33 ( V_67 -> V_78 ) ;
if ( ! ( V_21 . V_25 & V_27 ) )
goto V_28;
V_24 = F_35 ( V_15 -> V_31 . V_32 , V_24 ) ;
V_81 = F_11 ( V_15 , V_67 -> V_78 -> V_17 ,
V_67 -> V_78 -> V_34 . V_18 ,
V_27 , V_24 ) ;
if ( ! ( V_81 . V_25 & V_27 ) )
goto V_28;
goto V_80;
}
if ( V_21 . V_25 & V_45 ) {
V_51 = F_28 ( V_15 , V_18 , V_21 . V_50 ) ;
if ( ! V_51 ) {
if ( V_21 . V_50 & V_82 ) {
V_71 = L_3 ;
V_51 = F_20 ( V_15 ) ;
goto V_83;
} else if ( V_21 . V_50 & V_84 ) {
V_51 = F_33 ( V_17 -> F_7 ) ;
V_71 = L_4 ;
} else {
error = - V_85 ;
V_71 = L_5 ;
V_21 . V_25 &= ~ V_45 ;
}
}
} else if ( F_36 ( V_15 ) ) {
V_51 = F_37 ( V_15 , 0 ) ;
if ( ! V_51 ) {
error = - V_86 ;
V_71 = L_6 ;
} else
error = - V_85 ;
V_21 . V_50 |= V_87 ;
} else
error = - V_85 ;
if ( V_65 -> V_88 & V_89 ) {
error = - V_90 ;
goto V_79;
}
if ( ! V_51 )
goto V_28;
if ( V_65 -> V_88 & V_91 ) {
;
}
if ( V_65 -> V_88 & ( V_92 | V_93 ) ) {
error = F_3 ( V_51 ) ;
if ( error )
goto V_28;
}
if ( ! ( V_21 . V_50 & V_87 ) ) {
F_38 ( L_7 ,
V_18 , V_51 -> V_34 . V_59 ) ;
V_65 -> V_88 |= V_94 ;
}
V_80:
V_65 -> V_95 |= V_96 ;
V_83:
F_10 ( V_67 -> V_15 ) ;
V_67 -> V_15 = V_51 ;
V_51 = NULL ;
F_39 ( V_67 ) ;
V_28:
error = F_40 ( V_15 , & V_21 , V_97 , V_98 , V_45 ,
V_18 ,
V_51 ? V_51 -> V_34 . V_59 : NULL ,
V_23 . V_99 , V_71 , error ) ;
V_79:
F_10 ( V_51 ) ;
F_10 ( V_15 ) ;
F_41 ( V_68 ) ;
return error ;
}
int F_42 ( struct V_64 * V_65 )
{
if ( V_65 -> V_88 & V_94 )
return 1 ;
return 0 ;
}
void F_43 ( struct V_64 * V_65 )
{
struct V_6 * V_15 = F_44 () ;
struct V_66 * V_100 = F_31 ( V_65 -> V_73 ) ;
if ( ( V_100 -> V_15 == V_15 ) ||
( F_7 ( V_100 -> V_15 ) ) )
return;
V_11 -> V_101 = 0 ;
F_45 ( V_15 , V_100 -> V_15 ) ;
}
void F_46 ( struct V_64 * V_65 )
{
return;
}
static char * F_47 ( const char * V_102 , const char * V_103 )
{
char * V_18 = F_48 ( strlen ( V_102 ) + strlen ( V_103 ) + 3 , V_97 ) ;
if ( V_18 )
sprintf ( V_18 , L_8 , V_102 , V_103 ) ;
return V_18 ;
}
int F_49 ( const char * V_104 [] , int V_105 , T_2 V_106 , bool V_107 )
{
const struct V_73 * V_73 ;
struct V_66 * V_67 ;
struct V_6 * V_15 , * V_108 , * V_109 = NULL ;
char * V_18 = NULL ;
int V_3 ;
struct V_14 V_21 = {} ;
const char * V_110 = NULL , * V_71 = NULL ;
int error = 0 ;
if ( F_50 ( V_11 ) )
return - V_90 ;
V_73 = F_51 () ;
V_67 = F_31 ( V_73 ) ;
V_15 = F_33 ( F_52 ( V_73 ) ) ;
V_108 = F_33 ( V_67 -> V_111 ) ;
if ( F_7 ( V_15 ) ) {
V_71 = L_9 ;
error = - V_90 ;
goto V_28;
}
if ( V_105 ) {
struct V_6 * V_112 ;
if ( F_53 ( V_15 ) )
V_112 = F_54 ( & V_15 -> V_113 ) ;
else
V_112 = F_20 ( V_15 ) ;
for ( V_3 = 0 ; V_3 < V_105 && ! V_109 ; V_3 ++ )
V_109 = F_24 ( V_112 , V_104 [ V_3 ] ) ;
if ( ! V_109 ) {
if ( ! F_36 ( V_112 ) || V_107 ) {
if ( F_55 ( & V_112 -> V_34 . V_62 ) )
error = - V_114 ;
else
error = - V_115 ;
F_10 ( V_112 ) ;
goto V_12;
}
V_18 = F_47 ( V_112 -> V_34 . V_59 , V_104 [ 0 ] ) ;
F_10 ( V_112 ) ;
V_110 = V_18 ;
V_109 = F_37 ( V_15 , 1 ) ;
if ( ! V_109 ) {
V_71 = L_10 ;
error = - V_86 ;
goto V_28;
}
} else {
F_10 ( V_112 ) ;
V_110 = V_109 -> V_34 . V_59 ;
if ( ! F_53 ( V_109 ) ) {
V_71 = L_11 ;
error = - V_90 ;
goto V_28;
}
}
error = F_3 ( V_109 ) ;
if ( error ) {
V_71 = L_12 ;
error = - V_90 ;
goto V_28;
}
if ( ! V_107 ) {
error = F_56 ( V_109 , V_106 ) ;
if ( error == - V_85 )
V_21 . V_30 = V_116 ;
else if ( V_18 && ! error )
error = - V_115 ;
}
} else if ( V_108 ) {
V_110 = V_108 -> V_34 . V_59 ;
error = F_57 ( V_106 ) ;
V_21 . V_30 = V_116 ;
} else
goto V_12;
V_28:
if ( ! V_107 )
error = F_40 ( V_15 , & V_21 , V_97 ,
V_117 , V_116 , NULL ,
V_110 , V_118 , V_71 , error ) ;
V_12:
F_10 ( V_109 ) ;
F_41 ( V_18 ) ;
F_10 ( V_15 ) ;
F_10 ( V_108 ) ;
F_58 ( V_73 ) ;
return error ;
}
int F_59 ( const char * V_48 , const char * V_59 , bool V_78 ,
bool V_107 )
{
const struct V_73 * V_73 ;
struct V_6 * V_15 , * V_110 = NULL ;
struct V_16 * V_17 = NULL ;
struct V_14 V_21 = {} ;
const char * V_18 = NULL , * V_71 = NULL ;
int V_119 , error = 0 ;
T_1 V_19 ;
if ( ! V_59 && ! V_48 )
return - V_120 ;
if ( V_78 ) {
V_19 = V_27 ;
V_119 = V_121 ;
} else {
V_19 = V_26 ;
V_119 = V_122 ;
}
V_73 = F_51 () ;
V_15 = F_52 ( V_73 ) ;
if ( F_50 ( V_11 ) && ! F_7 ( V_15 ) ) {
F_58 ( V_73 ) ;
return - V_90 ;
}
if ( V_48 ) {
V_17 = F_25 ( V_15 -> V_17 , V_48 ) ;
if ( ! V_17 ) {
V_18 = V_48 ;
V_71 = L_13 ;
error = - V_115 ;
goto V_28;
}
} else
V_17 = F_60 ( V_15 -> V_17 ) ;
if ( ! V_59 ) {
if ( F_7 ( V_15 ) )
V_59 = V_17 -> F_7 -> V_34 . V_59 ;
else
V_59 = V_15 -> V_34 . V_59 ;
}
V_21 = F_11 ( V_15 , V_17 , V_59 , V_19 ,
V_15 -> V_31 . V_20 ) ;
if ( ! ( V_21 . V_25 & V_19 ) ) {
error = - V_85 ;
goto V_28;
}
V_110 = F_26 ( V_17 , V_59 ) ;
if ( ! V_110 ) {
V_71 = L_5 ;
error = - V_115 ;
if ( V_107 || ! F_36 ( V_15 ) )
goto V_28;
V_110 = F_37 ( V_15 , 0 ) ;
if ( ! V_110 ) {
V_71 = L_10 ;
error = - V_86 ;
goto V_28;
}
}
error = F_3 ( V_110 ) ;
if ( error ) {
V_71 = L_14 ;
goto V_28;
}
if ( V_107 )
goto V_28;
if ( V_78 )
error = F_61 ( V_110 ) ;
else
error = F_62 ( V_110 ) ;
V_28:
if ( ! V_107 )
error = F_40 ( V_15 , & V_21 , V_97 , V_119 , V_19 ,
V_18 , V_59 , V_118 , V_71 , error ) ;
F_27 ( V_17 ) ;
F_10 ( V_110 ) ;
F_58 ( V_73 ) ;
return error ;
}

static int F_1 ( T_1 * V_1 , char * V_2 , ... )
{
T_2 args ;
int V_3 ;
if ( V_1 -> V_4 || V_1 -> error )
return 0 ;
va_start ( args , V_2 ) ;
V_3 = vsnprintf ( V_1 -> V_5 , V_1 -> V_6 - V_1 -> V_7 , V_2 , args ) ;
va_end ( args ) ;
if ( V_1 -> V_7 + V_3 >= V_1 -> V_6 ) {
V_1 -> V_4 = 1 ;
return 0 ;
}
V_1 -> V_5 += V_3 ;
V_1 -> V_7 += V_3 ;
return V_3 ;
}
static void F_2 ( T_1 * V_1 , char * V_8 ,
struct V_9 * V_10 )
{
F_1 ( V_1 , L_1
L_2 , V_8 ,
( unsigned long long ) V_10 -> V_11 ,
( unsigned long long ) V_10 -> V_12 ,
V_10 -> V_13 ? ( ( unsigned long long ) V_10 -> V_13 - 1 ) : 0 ,
( unsigned long long ) V_10 -> V_7 ,
V_10 -> V_14 & V_15 ? 16 : 10 ) ;
}
static void F_3 ( T_1 * V_1 , char * V_8 ,
struct V_16 * V_17 )
{
int V_18 = 1 , V_19 ;
F_1 ( V_1 , L_3 , V_8 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
if ( F_4 ( V_19 , V_17 -> V_21 . V_22 ) ) {
if ( ! V_18 ) {
F_1 ( V_1 , L_4 ) ;
} else {
V_18 = 0 ;
}
if ( V_19 == 2 || V_19 == 9 )
F_1 ( V_1 , L_5 ) ;
else
F_1 ( V_1 , L_6 , V_19 ) ;
}
if ( F_5 ( V_17 -> V_21 . V_22 , V_20 ) )
F_1 ( V_1 , L_7 ) ;
if ( V_17 -> V_14 & V_23 )
F_1 ( V_1 , L_8 ) ;
if ( V_17 -> V_14 & V_24 )
F_1 ( V_1 , L_9 ) ;
if ( V_17 -> V_14 & V_25 )
F_1 ( V_1 , L_10 ) ;
if ( V_17 -> V_14 & V_26 )
F_1 ( V_1 , L_11 ) ;
if ( V_17 -> V_14 & V_27 )
F_1 ( V_1 , L_12 ) ;
F_1 ( V_1 , L_13 ) ;
}
static void F_6 ( T_1 * V_1 , char * V_8 ,
struct V_28 * V_29 )
{
int V_18 = 1 , V_19 ;
char * V_30 ;
F_1 ( V_1 , L_14 , V_8 ) ;
for ( V_19 = 0 ; V_19 < 8 ; V_19 ++ )
if ( V_29 -> V_21 & ( 1 << V_19 ) ) {
if ( ! V_18 ) {
F_1 ( V_1 , L_4 ) ;
} else {
V_18 = 0 ;
}
F_1 ( V_1 , L_6 , V_19 ) ;
}
if ( ! V_29 -> V_21 )
F_1 ( V_1 , L_7 ) ;
switch ( V_29 -> V_14 & V_31 ) {
case V_32 :
V_30 = L_15 ;
break;
case V_33 :
V_30 = L_16 ;
break;
default:
V_30 = L_17 ;
}
F_1 ( V_1 , L_18 , V_30 ) ;
if ( V_29 -> V_14 & V_34 )
F_1 ( V_1 , L_19 ) ;
if ( V_29 -> V_14 & V_35 )
F_1 ( V_1 , L_20 ) ;
if ( V_29 -> V_14 & V_36 )
F_1 ( V_1 , L_21 ) ;
switch ( V_29 -> V_14 & V_37 ) {
case V_38 :
V_30 = L_22 ;
break;
case V_39 :
V_30 = L_23 ;
break;
case V_40 :
V_30 = L_24 ;
break;
default:
V_30 = L_25 ;
break;
}
F_1 ( V_1 , L_26 , V_30 ) ;
}
static void F_7 ( T_1 * V_1 , char * V_8 ,
struct V_41 * V_42 )
{
char * V_30 ;
F_1 ( V_1 , L_27 ,
V_8 , ( unsigned long long ) V_42 -> V_11 ,
( unsigned long long ) V_42 -> V_12 ,
( unsigned long long ) V_42 -> V_13 ,
( unsigned long long ) V_42 -> V_7 ) ;
if ( V_42 -> V_14 & V_43 )
F_1 ( V_1 , L_28 ) ;
if ( V_42 -> V_14 & V_44 )
F_1 ( V_1 , L_29 ) ;
if ( V_42 -> V_14 & V_45 )
F_1 ( V_1 , L_30 ) ;
if ( V_42 -> V_14 & V_46 )
F_1 ( V_1 , L_31 ) ;
if ( V_42 -> V_14 & V_47 )
F_1 ( V_1 , L_32 ) ;
switch ( V_42 -> V_14 & V_48 ) {
case V_49 :
V_30 = L_15 ;
break;
case V_50 :
V_30 = L_16 ;
break;
case V_51 :
V_30 = L_33 ;
break;
default:
V_30 = L_17 ;
}
F_1 ( V_1 , L_34 , V_30 ) ;
}
static void F_8 ( T_1 * V_1 , char * V_8 ,
struct V_52 * V_53 )
{
switch ( V_53 -> type ) {
case V_54 :
F_2 ( V_1 , V_8 , & V_53 -> V_55 . V_10 ) ;
break;
case V_56 :
F_7 ( V_1 , V_8 , & V_53 -> V_55 . V_42 ) ;
break;
case V_57 :
F_3 ( V_1 , V_8 , & V_53 -> V_55 . V_17 ) ;
break;
case V_58 :
F_6 ( V_1 , V_8 , & V_53 -> V_55 . V_29 ) ;
break;
}
}
static T_3 F_9 ( struct V_59 * V_60 , struct V_61 * V_62 ,
char * V_63 )
{
struct V_64 * V_65 = F_10 ( V_60 ) ;
T_1 * V_1 ;
struct V_52 * V_53 ;
int V_66 , V_67 = 0 , V_68 = 0 ;
char * V_69 ;
V_1 = F_11 ( sizeof( T_1 ) ) ;
if ( ! V_1 )
return - V_70 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_1 = V_63 ;
V_1 -> V_5 = V_1 -> V_1 ;
F_12 (option, &dev->options, list) {
if ( F_13 ( V_53 ) ) {
V_69 = L_35 ;
if ( ! V_67 || F_14 ( V_53 ) != V_68 ) {
V_68 = F_14 ( V_53 ) ;
V_67 = 1 ;
F_1 ( V_1 , L_36
L_37 , V_68 ,
F_15 ( V_53 ) ) ;
}
} else {
V_67 = 0 ;
V_69 = L_38 ;
}
F_8 ( V_1 , V_69 , V_53 ) ;
}
V_66 = ( V_1 -> V_5 - V_63 ) ;
F_16 ( V_1 ) ;
return V_66 ;
}
static T_3 F_17 ( struct V_59 * V_60 ,
struct V_61 * V_62 , char * V_63 )
{
struct V_64 * V_65 = F_10 ( V_60 ) ;
T_1 * V_1 ;
struct V_72 * V_73 ;
struct V_74 * V_3 ;
int V_66 ;
if ( ! V_65 )
return - V_75 ;
V_1 = F_11 ( sizeof( T_1 ) ) ;
if ( ! V_1 )
return - V_70 ;
V_1 -> V_6 = V_71 ;
V_1 -> V_1 = V_63 ;
V_1 -> V_5 = V_1 -> V_1 ;
F_1 ( V_1 , L_39 , V_65 -> V_76 ? L_40 : L_41 ) ;
F_12 (pnp_res, &dev->resources, list) {
V_3 = & V_73 -> V_3 ;
F_1 ( V_1 , F_18 ( V_3 ) ) ;
if ( V_3 -> V_14 & V_77 ) {
F_1 ( V_1 , L_42 ) ;
continue;
}
switch ( F_19 ( V_3 ) ) {
case V_54 :
case V_56 :
case V_78 :
F_1 ( V_1 , L_43 ,
( unsigned long long ) V_3 -> V_79 ,
( unsigned long long ) V_3 -> V_80 ,
V_3 -> V_14 & V_81 ?
L_44 : L_38 ) ;
break;
case V_57 :
case V_58 :
F_1 ( V_1 , L_45 ,
( unsigned long long ) V_3 -> V_79 ) ;
break;
}
}
V_66 = ( V_1 -> V_5 - V_63 ) ;
F_16 ( V_1 ) ;
return V_66 ;
}
static char * F_20 ( char * V_63 ,
unsigned long type ,
T_4 * V_79 ,
T_4 * V_80 ,
unsigned long * V_14 )
{
if ( V_79 )
* V_79 = 0 ;
if ( V_80 )
* V_80 = 0 ;
if ( V_14 )
* V_14 = 0 ;
V_63 = F_21 ( V_63 ) ;
if ( V_79 ) {
* V_79 = F_22 ( V_63 , & V_63 , 0 ) ;
if ( V_80 ) {
V_63 = F_21 ( V_63 ) ;
if ( * V_63 == '-' ) {
V_63 = F_21 ( V_63 + 1 ) ;
* V_80 = F_22 ( V_63 , & V_63 , 0 ) ;
} else
* V_80 = * V_79 ;
}
}
return V_63 ;
}
static T_3 F_23 ( struct V_59 * V_60 ,
struct V_61 * V_62 , const char * V_82 ,
T_5 V_83 )
{
struct V_64 * V_65 = F_10 ( V_60 ) ;
char * V_63 = ( void * ) V_82 ;
int V_84 = 0 ;
if ( V_65 -> V_85 & V_86 ) {
V_84 = - V_87 ;
F_24 ( & V_65 -> V_65 , L_46 ) ;
goto V_88;
}
V_63 = F_21 ( V_63 ) ;
if ( ! strncasecmp ( V_63 , L_47 , 7 ) ) {
V_84 = F_25 ( V_65 ) ;
goto V_88;
}
if ( ! strncasecmp ( V_63 , L_48 , 8 ) ) {
V_84 = F_26 ( V_65 ) ;
goto V_88;
}
if ( ! strncasecmp ( V_63 , L_49 , 4 ) ) {
if ( V_65 -> V_76 )
goto V_88;
V_84 = F_27 ( V_65 ) ;
goto V_88;
}
if ( ! strncasecmp ( V_63 , L_50 , 4 ) ) {
if ( V_65 -> V_76 )
goto V_88;
F_28 ( V_65 ) ;
V_84 = F_27 ( V_65 ) ;
goto V_88;
}
if ( ! strncasecmp ( V_63 , L_51 , 5 ) ) {
if ( V_65 -> V_76 )
goto V_88;
F_28 ( V_65 ) ;
goto V_88;
}
if ( ! strncasecmp ( V_63 , L_52 , 3 ) ) {
F_29 ( & V_89 ) ;
if ( F_30 ( V_65 ) )
V_65 -> V_90 -> V_91 ( V_65 ) ;
F_31 ( & V_89 ) ;
goto V_88;
}
if ( ! strncasecmp ( V_63 , L_53 , 3 ) ) {
T_4 V_79 ;
T_4 V_80 ;
unsigned long V_14 ;
if ( V_65 -> V_76 )
goto V_88;
V_63 += 3 ;
F_28 ( V_65 ) ;
F_29 ( & V_89 ) ;
while ( 1 ) {
V_63 = F_21 ( V_63 ) ;
if ( ! strncasecmp ( V_63 , L_54 , 2 ) ) {
V_63 = F_20 ( V_63 + 2 ,
V_54 ,
& V_79 , & V_80 ,
& V_14 ) ;
F_32 ( V_65 , V_79 , V_80 , V_14 ) ;
} else if ( ! strncasecmp ( V_63 , L_55 , 3 ) ) {
V_63 = F_20 ( V_63 + 3 ,
V_56 ,
& V_79 , & V_80 ,
& V_14 ) ;
F_33 ( V_65 , V_79 , V_80 , V_14 ) ;
} else if ( ! strncasecmp ( V_63 , L_56 , 3 ) ) {
V_63 = F_20 ( V_63 + 3 ,
V_57 ,
& V_79 , NULL ,
& V_14 ) ;
F_34 ( V_65 , V_79 , V_14 ) ;
} else if ( ! strncasecmp ( V_63 , L_57 , 3 ) ) {
V_63 = F_20 ( V_63 + 3 ,
V_58 ,
& V_79 , NULL ,
& V_14 ) ;
F_35 ( V_65 , V_79 , V_14 ) ;
} else if ( ! strncasecmp ( V_63 , L_58 , 3 ) ) {
V_63 = F_20 ( V_63 + 3 ,
V_78 ,
& V_79 , & V_80 ,
NULL ) ;
F_36 ( V_65 , V_79 , V_80 ) ;
} else
break;
}
F_31 ( & V_89 ) ;
goto V_88;
}
V_88:
if ( V_84 < 0 )
return V_84 ;
return V_83 ;
}
static T_3 F_37 ( struct V_59 * V_60 , struct V_61 * V_62 ,
char * V_63 )
{
char * V_92 = V_63 ;
struct V_64 * V_65 = F_10 ( V_60 ) ;
struct V_93 * V_94 = V_65 -> V_95 ;
while ( V_94 ) {
V_92 += sprintf ( V_92 , L_59 , V_94 -> V_95 ) ;
V_94 = V_94 -> V_96 ;
}
return ( V_92 - V_63 ) ;
}

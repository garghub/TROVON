void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_2 ( V_2 ) ;
}
static struct V_1 * F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
char * V_3 ;
char * V_4 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_7 ) ;
if ( ! V_2 )
return NULL ;
V_3 = ( char * ) V_6 + F_5 ( V_6 -> V_8 ) ;
V_2 -> V_3 = F_6 ( V_3 , V_7 ) ;
V_2 -> V_9 = F_5 ( V_6 -> V_10 ) ;
V_4 = ( char * ) V_6 + F_5 ( V_6 -> V_11 ) ;
V_2 -> V_4 = F_7 ( V_4 , V_2 -> V_9 , V_7 ) ;
if ( ! V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_12 * F_8 ( struct V_5 * V_6 ,
const char * V_13 )
{
struct V_12 * V_14 ;
char * V_3 ;
if ( ! V_13 [ 1 ] )
V_13 ++ ;
V_14 = F_4 ( sizeof( * V_14 ) , V_7 ) ;
if ( ! V_14 )
return NULL ;
V_3 = ( char * ) V_6 + F_5 ( V_6 -> V_8 ) ;
V_14 -> V_15 = F_9 ( V_7 , L_1 , V_13 , V_3 ) ;
if ( ! V_14 -> V_15 ) {
F_2 ( V_14 ) ;
return NULL ;
}
F_10 ( V_14 , V_16 ) ;
F_11 ( V_14 ) ;
return V_14 ;
}
static void F_12 ( struct V_12 * V_14 )
{
struct V_1 * V_2 ;
while ( V_14 -> V_17 ) {
V_2 = V_14 -> V_17 ;
V_14 -> V_17 = V_2 -> V_18 ;
F_1 ( V_2 ) ;
}
F_2 ( V_14 -> V_15 ) ;
F_2 ( V_14 ) ;
}
void F_13 ( struct V_12 * V_14 )
{
if ( V_14 -> V_19 )
F_13 ( V_14 -> V_19 ) ;
if ( V_14 -> V_20 )
F_13 ( V_14 -> V_20 ) ;
F_12 ( V_14 ) ;
}
struct V_12 * F_14 ( T_1 V_21 ,
struct V_12 * V_22 )
{
struct V_12 * V_14 ;
struct V_12 * V_23 = NULL ;
struct V_12 * V_24 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_25 = NULL ;
struct V_5 * V_6 ;
char * V_26 ;
const char * V_27 = V_22 -> V_15 ;
int V_28 ;
int V_29 = - 1 ;
V_28 = F_15 ( L_2 ) ;
if ( V_28 == V_30 )
return NULL ;
V_26 = F_4 ( V_31 , V_7 ) ;
if ( ! V_26 )
return NULL ;
V_6 = (struct V_5 * ) & V_26 [ 0 ] ;
V_6 -> V_21 = V_21 ;
V_6 -> V_32 = 0 ;
do {
F_16 ( & V_33 ) ;
memcpy ( V_34 , V_26 , V_31 ) ;
V_29 = F_17 ( V_28 , 2 , 1 , NULL , V_34 , NULL ) ;
memcpy ( V_26 , V_34 , V_31 ) ;
F_18 ( & V_33 ) ;
switch ( V_29 ) {
case V_35 :
break;
case V_36 :
V_14 = F_8 ( V_6 , V_27 ) ;
if ( ! V_14 )
goto V_37;
V_14 -> V_22 = V_24 -> V_22 ;
V_24 -> V_20 = V_14 ;
V_24 = V_14 ;
break;
case V_38 :
if ( V_23 )
V_27 = V_24 -> V_15 ;
V_14 = F_8 ( V_6 , V_27 ) ;
if ( ! V_14 )
goto V_37;
if ( ! V_23 ) {
V_14 -> V_22 = V_22 ;
V_23 = V_14 ;
} else {
V_14 -> V_22 = V_24 ;
if ( V_24 )
V_24 -> V_19 = V_14 ;
}
V_24 = V_14 ;
break;
case V_39 :
V_1 = F_3 ( V_6 ) ;
if ( ! V_1 )
goto V_37;
if ( ! V_24 -> V_17 )
V_24 -> V_17 = V_1 ;
else
V_25 -> V_18 = V_1 ;
V_25 = V_1 ;
break;
case V_40 :
V_24 = V_24 -> V_22 ;
V_27 = V_24 -> V_22 -> V_15 ;
break;
case V_41 :
break;
case V_42 :
case V_43 :
default:
F_19 ( V_44 L_3
L_4 , V_29 ) ;
goto V_37;
}
} while ( V_29 );
V_37:
F_2 ( V_26 ) ;
if ( V_29 ) {
if ( V_23 )
F_13 ( V_23 ) ;
return NULL ;
}
return V_23 ;
}
int F_20 ( struct V_12 * V_14 )
{
int V_29 ;
V_14 -> V_22 = F_21 ( V_14 -> V_15 ) ;
if ( F_22 ( V_14 -> V_22 ) )
return F_23 ( V_14 -> V_22 ) ;
V_29 = F_24 ( V_14 ) ;
if ( V_29 ) {
F_19 ( V_44 L_5 ,
V_14 -> V_15 ) ;
return V_29 ;
}
F_25 ( V_14 -> V_22 ) ;
return 0 ;
}
int F_26 ( struct V_12 * V_14 )
{
struct V_12 * V_19 ;
int V_29 ;
V_19 = F_27 ( V_14 , NULL ) ;
while ( V_19 ) {
F_26 ( V_19 ) ;
V_19 = F_27 ( V_14 , V_19 ) ;
}
V_29 = F_28 ( V_14 ) ;
if ( V_29 )
return V_29 ;
F_25 ( V_14 ) ;
return 0 ;
}
int F_29 ( T_2 V_21 )
{
int V_45 , V_29 ;
V_29 = F_17 ( F_15 ( L_6 ) , 2 , 2 , & V_45 ,
V_46 , V_21 ) ;
if ( V_29 || V_45 != V_47 )
return - 1 ;
V_29 = F_30 ( V_48 , V_21 , V_49 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_30 ( V_50 , V_21 , V_51 ) ;
if ( V_29 ) {
F_30 ( V_48 , V_21 , V_52 ) ;
return V_29 ;
}
return 0 ;
}
int F_31 ( T_2 V_21 )
{
int V_45 , V_29 ;
V_29 = F_17 ( F_15 ( L_6 ) , 2 , 2 , & V_45 ,
V_46 , V_21 ) ;
if ( V_29 || V_45 != V_53 )
return - 1 ;
V_29 = F_30 ( V_50 , V_21 , V_54 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_30 ( V_48 , V_21 , V_52 ) ;
if ( V_29 ) {
F_30 ( V_50 , V_21 , V_51 ) ;
return V_29 ;
}
return 0 ;
}
static int F_32 ( struct V_12 * V_14 )
{
int V_29 = 0 ;
unsigned int V_55 ;
int V_56 , V_57 , V_58 ;
const T_1 * V_59 ;
T_2 V_60 ;
V_59 = F_33 ( V_14 , L_7 , & V_56 ) ;
if ( ! V_59 )
return - V_61 ;
V_57 = V_56 / sizeof( T_2 ) ;
F_34 () ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_60 = F_5 ( V_59 [ V_58 ] ) ;
F_35 (cpu) {
if ( F_36 ( V_55 ) != V_60 )
continue;
F_37 ( F_38 ( V_55 )
!= V_62 ) ;
F_39 () ;
V_29 = F_40 ( F_41 ( V_55 ) ) ;
if ( V_29 )
goto V_63;
F_34 () ;
break;
}
if ( V_55 == F_42 () )
F_19 ( V_64 L_8
L_9 , V_60 ) ;
}
F_39 () ;
V_63:
return V_29 ;
}
static T_3 F_43 ( const char * V_65 , T_4 V_66 )
{
struct V_12 * V_14 , * V_22 ;
T_2 V_21 ;
int V_29 ;
V_29 = F_44 ( V_65 , 0 , & V_21 ) ;
if ( V_29 )
return - V_61 ;
V_29 = F_29 ( V_21 ) ;
if ( V_29 )
return - V_61 ;
V_22 = F_45 ( L_10 ) ;
if ( ! V_22 )
return - V_67 ;
V_14 = F_14 ( F_46 ( V_21 ) , V_22 ) ;
F_25 ( V_22 ) ;
if ( ! V_14 ) {
F_31 ( V_21 ) ;
return - V_61 ;
}
V_29 = F_20 ( V_14 ) ;
if ( V_29 ) {
F_31 ( V_21 ) ;
F_13 ( V_14 ) ;
return V_29 ;
}
V_29 = F_32 ( V_14 ) ;
if ( V_29 )
return V_29 ;
return V_66 ;
}
static int F_47 ( struct V_12 * V_14 )
{
int V_29 = 0 ;
unsigned int V_55 ;
int V_56 , V_57 , V_58 ;
const T_1 * V_59 ;
T_2 V_60 ;
V_59 = F_33 ( V_14 , L_7 , & V_56 ) ;
if ( ! V_59 )
return - V_61 ;
V_57 = V_56 / sizeof( T_2 ) ;
F_34 () ;
for ( V_58 = 0 ; V_58 < V_57 ; V_58 ++ ) {
V_60 = F_5 ( V_59 [ V_58 ] ) ;
F_35 (cpu) {
if ( F_36 ( V_55 ) != V_60 )
continue;
if ( F_38 ( V_55 ) == V_62 )
break;
if ( F_38 ( V_55 ) == V_68 ) {
F_48 ( V_55 , V_62 ) ;
F_39 () ;
V_29 = F_49 ( F_41 ( V_55 ) ) ;
if ( V_29 )
goto V_63;
F_34 () ;
break;
}
F_48 ( V_55 , V_62 ) ;
F_37 ( F_50 ( V_69 , V_60 )
!= V_70 ) ;
F_51 ( V_55 ) ;
break;
}
if ( V_55 == F_42 () )
F_19 ( V_64 L_11
L_9 , V_60 ) ;
}
F_39 () ;
V_63:
return V_29 ;
}
static T_3 F_52 ( const char * V_65 , T_4 V_66 )
{
struct V_12 * V_14 ;
T_2 V_21 ;
int V_29 ;
V_14 = F_45 ( V_65 ) ;
if ( ! V_14 )
return - V_61 ;
V_29 = F_53 ( V_14 , L_12 , & V_21 ) ;
if ( V_29 ) {
F_25 ( V_14 ) ;
return - V_61 ;
}
V_29 = F_47 ( V_14 ) ;
if ( V_29 ) {
F_25 ( V_14 ) ;
return - V_61 ;
}
V_29 = F_31 ( V_21 ) ;
if ( V_29 ) {
F_25 ( V_14 ) ;
return V_29 ;
}
V_29 = F_26 ( V_14 ) ;
if ( V_29 ) {
F_29 ( V_21 ) ;
return V_29 ;
}
F_25 ( V_14 ) ;
return V_66 ;
}
static int F_54 ( struct V_71 * V_72 )
{
int V_29 ;
switch ( V_72 -> V_73 ) {
case V_74 :
V_72 -> V_75 . V_76 =
F_5 ( V_72 -> V_75 . V_76 ) ;
break;
case V_77 :
V_72 -> V_75 . V_21 =
F_5 ( V_72 -> V_75 . V_21 ) ;
}
switch ( V_72 -> V_78 ) {
case V_79 :
V_29 = F_55 ( V_72 ) ;
break;
default:
F_56 ( L_13 ,
V_72 -> V_78 ) ;
V_29 = - V_61 ;
}
return V_29 ;
}
static T_3 F_57 ( struct V_80 * V_80 , struct V_81 * V_82 ,
const char * V_65 , T_4 V_66 )
{
struct V_71 * V_72 ;
const char * V_83 ;
int V_29 ;
V_72 = F_4 ( sizeof( * V_72 ) , V_7 ) ;
if ( ! V_72 ) {
V_29 = - V_84 ;
goto V_85;
}
V_83 = V_65 ;
if ( ! strncmp ( V_83 , L_14 , 6 ) ) {
V_72 -> V_78 = V_79 ;
V_83 += strlen ( L_15 ) ;
} else {
F_58 ( L_16 , V_65 ) ;
V_29 = - V_61 ;
goto V_85;
}
if ( ! strncmp ( V_83 , L_17 , 3 ) ) {
V_72 -> V_86 = V_87 ;
V_83 += strlen ( L_18 ) ;
} else if ( ! strncmp ( V_83 , L_19 , 6 ) ) {
V_72 -> V_86 = V_88 ;
V_83 += strlen ( L_20 ) ;
} else {
F_58 ( L_21 , V_65 ) ;
V_29 = - V_61 ;
goto V_85;
}
if ( ! strncmp ( V_83 , L_22 , 5 ) ) {
T_2 V_89 ;
V_72 -> V_73 = V_77 ;
V_83 += strlen ( L_23 ) ;
if ( F_44 ( V_83 , 0 , & V_89 ) ) {
V_29 = - V_61 ;
F_58 ( L_24 , V_65 ) ;
goto V_85;
}
V_72 -> V_75 . V_21 = F_46 ( V_89 ) ;
} else if ( ! strncmp ( V_83 , L_25 , 5 ) ) {
T_2 V_66 ;
V_72 -> V_73 = V_74 ;
V_83 += strlen ( L_26 ) ;
if ( F_44 ( V_83 , 0 , & V_66 ) ) {
V_29 = - V_61 ;
F_58 ( L_27 , V_65 ) ;
goto V_85;
}
V_72 -> V_75 . V_76 = F_46 ( V_66 ) ;
} else {
F_58 ( L_28 , V_65 ) ;
V_29 = - V_61 ;
goto V_85;
}
V_29 = F_54 ( V_72 ) ;
V_85:
F_2 ( V_72 ) ;
return V_29 ? V_29 : V_66 ;
}
static int T_5 F_59 ( void )
{
int V_29 ;
#ifdef F_60
V_90 . V_91 = F_43 ;
V_90 . V_92 = F_52 ;
#endif
V_29 = F_61 ( V_93 , & V_94 . V_82 ) ;
return V_29 ;
}

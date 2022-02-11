static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_2 ) ;
F_3 ( V_4 , V_5 ) ;
F_4 ( V_4 ) ;
if ( V_4 -> V_6 ) {
F_5 ( & V_2 -> V_2 . V_7 , V_8 ) ;
F_6 ( V_9 , V_2 -> V_10 , L_1 ) ;
F_7 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
F_8 ( V_4 ) ;
F_9 ( & V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_11 * V_12 )
{
const char * V_13 ;
struct V_14 V_15 ;
int V_16 ;
int V_17 ;
struct V_3 * V_4 = F_11 ( sizeof( struct V_3 ) ,
V_18 ) ;
if ( ! V_4 ) {
F_12 ( V_2 , - V_19 ,
L_2 ) ;
return - V_19 ;
}
V_4 -> V_2 = V_2 ;
F_9 ( & V_2 -> V_2 , V_4 ) ;
V_17 = 1 ;
do {
V_16 = F_13 ( & V_15 ) ;
if ( V_16 ) {
F_12 ( V_2 , V_16 , L_3 ) ;
goto V_20;
}
V_16 = F_14 ( V_15 , V_2 -> V_10 , L_4 , L_5 , V_17 ) ;
if ( V_16 ) {
V_13 = L_6 ;
goto V_21;
}
V_16 = F_14 ( V_15 , V_2 -> V_10 , L_7 ,
L_5 , V_17 ) ;
if ( V_16 ) {
V_13 = L_8 ;
goto V_21;
}
V_16 = F_14 ( V_15 , V_2 -> V_10 , L_9 ,
L_5 , V_17 ) ;
if ( V_16 ) {
V_13 = L_10 ;
goto V_21;
}
V_16 = F_14 ( V_15 , V_2 -> V_10 ,
L_11 ,
L_5 , 1 ) ;
if ( V_16 ) {
V_13 = L_12 ;
goto V_21;
}
V_16 = F_14 ( V_15 , V_2 -> V_10 ,
L_13 , L_5 , 1 ) ;
if ( V_16 ) {
V_13 = L_14 ;
goto V_21;
}
V_16 = F_14 ( V_15 , V_2 -> V_10 ,
L_15 , L_5 , 0 ) ;
if ( V_16 ) {
V_13 = L_16 ;
goto V_21;
}
V_16 = F_15 ( V_15 , 0 ) ;
} while ( V_16 == - V_22 );
if ( V_16 ) {
F_12 ( V_2 , V_16 , L_17 ) ;
goto V_20;
}
V_16 = F_14 ( V_9 , V_2 -> V_10 ,
L_18 ,
L_19 , V_23 ) ;
if ( V_16 )
F_16 ( L_20 ) ;
V_16 = F_14 ( V_9 , V_2 -> V_10 ,
L_21 , L_19 , V_24 ) ;
if ( V_16 )
F_16 ( L_22 ) ;
V_16 = F_17 ( V_2 , V_25 ) ;
if ( V_16 )
goto V_20;
V_4 -> V_26 = V_25 ;
F_18 ( V_4 ) ;
return 0 ;
V_21:
F_15 ( V_15 , 1 ) ;
F_12 ( V_2 , V_16 , L_23 , V_13 ) ;
V_20:
F_16 ( L_24 ) ;
F_1 ( V_2 ) ;
return V_16 ;
}
static int F_19 ( struct V_1 * V_27 ,
struct V_28 * V_29 )
{
struct V_3 * V_4 = F_2 ( & V_27 -> V_2 ) ;
char * V_30 ;
V_30 = F_20 ( V_9 , V_27 -> V_10 , L_25 , NULL ) ;
if ( F_21 ( V_30 ) ) {
int V_16 = F_22 ( V_30 ) ;
F_12 ( V_27 , V_16 , L_26 ) ;
return V_16 ;
} else {
if ( F_23 ( V_29 , L_27 , V_30 ) ) {
F_8 ( V_30 ) ;
return - V_19 ;
}
F_8 ( V_30 ) ;
}
if ( ! V_4 || ! V_4 -> V_6 )
return 0 ;
return F_23 ( V_29 , L_28 , V_4 -> V_6 -> V_2 -> V_31 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
int V_16 ;
long V_32 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_4 -> V_6 != NULL )
return;
V_16 = F_24 ( V_9 , V_2 -> V_10 , L_29 , L_30 , & V_32 ) ;
if ( V_16 != 1 ) {
F_12 ( V_2 , V_16 , L_31 ) ;
return;
}
V_4 -> V_6 = F_25 ( & V_2 -> V_2 , V_2 -> V_33 , V_32 ) ;
if ( F_21 ( V_4 -> V_6 ) ) {
V_16 = F_22 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
F_12 ( V_2 , V_16 , L_32 ) ;
return;
}
F_5 ( & V_2 -> V_2 . V_7 , V_34 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 )
F_27 ( V_4 -> V_6 ) ;
}
static void F_28 ( struct V_3 * V_4 )
{
if ( V_4 -> V_6 )
F_29 ( V_4 ) ;
}
static inline void F_30 ( struct V_3 * V_4 ,
enum V_35 V_26 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_16 ( L_33 , V_2 -> V_10 , F_31 ( V_26 ) ) ;
V_4 -> V_26 = V_26 ;
if ( ! V_4 -> V_36 )
F_17 ( V_2 , V_26 ) ;
}
static void F_3 ( struct V_3 * V_4 ,
enum V_35 V_26 )
{
while ( V_4 -> V_26 != V_26 ) {
switch ( V_4 -> V_26 ) {
case V_5 :
switch ( V_26 ) {
case V_25 :
case V_37 :
F_32 ( L_34 ,
V_4 -> V_2 -> V_10 ) ;
F_30 ( V_4 , V_25 ) ;
break;
case V_38 :
F_30 ( V_4 , V_38 ) ;
break;
default:
F_33 () ;
}
break;
case V_25 :
switch ( V_26 ) {
case V_37 :
F_28 ( V_4 ) ;
F_30 ( V_4 , V_37 ) ;
break;
case V_38 :
case V_5 :
F_30 ( V_4 , V_38 ) ;
break;
default:
F_33 () ;
}
break;
case V_37 :
switch ( V_26 ) {
case V_25 :
case V_38 :
case V_5 :
F_26 ( V_4 ) ;
F_30 ( V_4 , V_38 ) ;
break;
default:
F_33 () ;
}
break;
case V_38 :
switch ( V_26 ) {
case V_25 :
case V_37 :
case V_5 :
F_30 ( V_4 , V_5 ) ;
break;
default:
F_33 () ;
}
break;
default:
F_33 () ;
}
}
}
static void F_34 ( struct V_1 * V_2 ,
enum V_35 V_39 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_2 ) ;
F_16 ( L_33 , V_2 -> V_40 , F_31 ( V_39 ) ) ;
V_4 -> V_39 = V_39 ;
switch ( V_39 ) {
case V_41 :
F_3 ( V_4 , V_25 ) ;
break;
case V_42 :
break;
case V_37 :
F_3 ( V_4 , V_37 ) ;
break;
case V_38 :
F_3 ( V_4 , V_38 ) ;
break;
case V_5 :
F_3 ( V_4 , V_5 ) ;
if ( F_35 ( V_2 ) )
break;
case V_43 :
F_3 ( V_4 , V_5 ) ;
F_36 ( & V_2 -> V_2 ) ;
break;
default:
F_12 ( V_2 , - V_44 , L_35 ,
V_39 ) ;
break;
}
}
static void F_37 ( struct V_1 * V_2 ,
unsigned long * V_45 , unsigned long * V_46 )
{
char * V_47 , * V_48 ;
unsigned long V_49 , V_50 ;
char * V_51 ;
* V_45 = ~ 0UL ;
* V_46 = 0 ;
V_51 = F_20 ( V_9 , V_2 -> V_10 , L_36 , NULL ) ;
if ( F_21 ( V_51 ) )
return;
V_47 = V_51 ;
V_49 = F_38 ( V_47 , & V_48 , 10 ) ;
if ( ( V_47 == V_48 ) || ( * V_48 != ',' ) )
goto V_20;
V_47 = V_48 + 1 ;
V_50 = F_38 ( V_47 , & V_48 , 10 ) ;
if ( ( V_47 == V_48 ) || ( * V_48 != '\0' ) )
goto V_20;
* V_45 = V_49 ;
* V_46 = V_50 ;
F_8 ( V_51 ) ;
return;
V_20:
F_39 ( L_37 ) ;
F_8 ( V_51 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_52 [] )
{
char * V_47 , * V_48 , * V_53 ;
int V_54 ;
V_53 = V_47 = F_20 ( V_9 , V_2 -> V_10 , L_38 , NULL ) ;
if ( F_21 ( V_53 ) )
return F_22 ( V_53 ) ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
V_52 [ V_54 ] = F_38 ( V_47 , & V_48 , 16 ) ;
if ( ( V_47 == V_48 ) || ( * V_48 != ( ( V_54 == V_55 - 1 ) ? '\0' : ':' ) ) ) {
F_8 ( V_53 ) ;
return - V_56 ;
}
V_47 = V_48 + 1 ;
}
F_8 ( V_53 ) ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 )
{
if ( V_4 -> V_36 ) {
F_41 ( & V_4 -> V_57 ) ;
F_8 ( V_4 -> V_57 . V_58 ) ;
}
V_4 -> V_36 = 0 ;
}
static void F_42 ( struct V_59 * V_60 ,
const char * * V_61 ,
unsigned int V_62 )
{
struct V_3 * V_4 = F_43 ( V_60 ,
struct V_3 ,
V_57 ) ;
char * V_63 ;
unsigned int V_64 ;
V_63 = F_20 ( V_9 , V_4 -> V_2 -> V_10 , L_1 , & V_64 ) ;
if ( F_21 ( V_63 ) )
return;
if ( V_64 == sizeof( L_39 ) - 1 && ! memcmp ( V_63 , L_39 , V_64 ) ) {
F_17 ( V_4 -> V_2 , V_4 -> V_26 ) ;
F_4 ( V_4 ) ;
}
F_8 ( V_63 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
int V_16 ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_65 , V_66 ;
unsigned int V_67 ;
unsigned int V_68 ;
struct V_69 * V_70 ;
V_16 = F_24 ( V_9 , V_2 -> V_40 ,
L_40 ,
L_19 , & V_68 ) ;
if ( V_16 < 0 ) {
V_68 = 1 ;
} else if ( V_68 > V_24 ) {
F_12 ( V_2 , V_16 ,
L_41 ,
V_68 , V_24 ) ;
return;
}
V_16 = F_40 ( V_2 , V_4 -> V_6 -> V_71 ) ;
if ( V_16 ) {
F_12 ( V_2 , V_16 , L_42 , V_2 -> V_10 ) ;
return;
}
F_37 ( V_2 , & V_65 , & V_66 ) ;
F_44 ( V_4 ) ;
V_4 -> V_6 -> V_72 = F_45 ( V_68 *
sizeof( struct V_69 ) ) ;
V_4 -> V_6 -> V_73 = V_68 ;
for ( V_67 = 0 ; V_67 < V_68 ; ++ V_67 ) {
V_70 = & V_4 -> V_6 -> V_72 [ V_67 ] ;
V_70 -> V_6 = V_4 -> V_6 ;
V_70 -> V_12 = V_67 ;
snprintf ( V_70 -> V_31 , sizeof( V_70 -> V_31 ) , L_43 ,
V_4 -> V_6 -> V_2 -> V_31 , V_70 -> V_12 ) ;
V_16 = F_46 ( V_70 ) ;
if ( V_16 ) {
V_4 -> V_6 -> V_73 = V_67 ;
goto V_16;
}
V_70 -> V_74 = V_65 ;
V_16 = F_47 ( V_4 , V_70 ) ;
if ( V_16 ) {
F_48 ( V_70 ) ;
V_4 -> V_6 -> V_73 = V_67 ;
goto V_16;
}
}
F_49 () ;
F_50 ( V_4 -> V_6 -> V_2 , V_68 ) ;
F_51 ( V_4 -> V_6 -> V_2 , V_68 ) ;
F_52 () ;
F_53 ( V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
V_16 = F_54 ( V_2 , & V_4 -> V_57 ,
F_42 ,
L_44 , V_2 -> V_10 , L_1 ) ;
if ( ! V_16 )
V_4 -> V_36 = 1 ;
F_55 ( V_4 -> V_6 -> V_2 ) ;
return;
V_16:
if ( V_4 -> V_6 -> V_73 > 0 )
F_27 ( V_4 -> V_6 ) ;
F_56 ( V_4 -> V_6 -> V_72 ) ;
V_4 -> V_6 -> V_72 = NULL ;
V_4 -> V_6 -> V_73 = 0 ;
return;
}
static int F_47 ( struct V_3 * V_4 , struct V_69 * V_70 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_73 = V_70 -> V_6 -> V_73 ;
unsigned long V_75 , V_76 ;
unsigned int V_77 , V_78 ;
int V_16 ;
char * V_79 ;
T_2 V_80 ;
const T_2 V_81 = 11 ;
if ( V_73 == 1 ) {
V_79 = F_11 ( strlen ( V_2 -> V_40 ) + 1 , V_18 ) ;
if ( ! V_79 ) {
F_12 ( V_2 , - V_19 ,
L_45 ) ;
return - V_19 ;
}
strcpy ( V_79 , V_2 -> V_40 ) ;
} else {
V_80 = strlen ( V_2 -> V_40 ) + V_81 ;
V_79 = F_11 ( V_80 , V_18 ) ;
if ( ! V_79 ) {
F_12 ( V_2 , - V_19 ,
L_45 ) ;
return - V_19 ;
}
snprintf ( V_79 , V_80 , L_46 , V_2 -> V_40 ,
V_70 -> V_12 ) ;
}
V_16 = F_57 ( V_9 , V_79 ,
L_47 , L_48 , & V_75 ,
L_49 , L_48 , & V_76 , NULL ) ;
if ( V_16 ) {
F_12 ( V_2 , V_16 ,
L_50 ,
V_79 ) ;
goto V_16;
}
V_16 = F_57 ( V_9 , V_79 ,
L_51 , L_19 , & V_77 ,
L_52 , L_19 , & V_78 , NULL ) ;
if ( V_16 < 0 ) {
V_16 = F_24 ( V_9 , V_79 ,
L_53 , L_19 , & V_77 ) ;
if ( V_16 < 0 ) {
F_12 ( V_2 , V_16 ,
L_54 ,
V_79 ) ;
goto V_16;
}
V_78 = V_77 ;
}
V_16 = F_58 ( V_70 , V_75 , V_76 ,
V_77 , V_78 ) ;
if ( V_16 ) {
F_12 ( V_2 , V_16 ,
L_55 ,
V_75 , V_76 ,
V_77 , V_78 ) ;
goto V_16;
}
V_16 = 0 ;
V_16:
F_8 ( V_79 ) ;
return V_16 ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_82 * V_6 = V_4 -> V_6 ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned int V_83 ;
int V_16 , V_30 ;
V_16 = F_24 ( V_9 , V_2 -> V_40 , L_56 , L_19 ,
& V_83 ) ;
if ( V_16 == - V_56 ) {
V_16 = 0 ;
V_83 = 0 ;
}
if ( V_16 < 0 ) {
F_12 ( V_2 , V_16 , L_57 ,
V_2 -> V_40 ) ;
return V_16 ;
}
if ( ! V_83 )
return - V_84 ;
if ( V_6 -> V_2 -> V_85 != 0 ) {
if ( F_24 ( V_9 , V_2 -> V_40 ,
L_58 , L_5 , & V_30 ) < 0 )
V_30 = 0 ;
if ( V_30 )
V_6 -> V_86 = 1 ;
else
V_6 -> V_2 -> V_85 = 1 ;
}
if ( F_24 ( V_9 , V_2 -> V_40 , L_4 ,
L_5 , & V_30 ) < 0 )
V_30 = 0 ;
V_6 -> V_87 = ! ! V_30 ;
V_6 -> V_88 = 0 ;
V_6 -> V_89 = 0 ;
if ( F_24 ( V_9 , V_2 -> V_40 , L_7 ,
L_5 , & V_30 ) < 0 )
V_30 = 0 ;
if ( V_30 )
V_6 -> V_88 |= F_59 ( V_90 ) ;
if ( F_24 ( V_9 , V_2 -> V_40 , L_59 ,
L_5 , & V_30 ) < 0 )
V_30 = 0 ;
if ( V_30 )
V_6 -> V_89 |= F_59 ( V_90 ) ;
if ( F_24 ( V_9 , V_2 -> V_40 , L_9 ,
L_5 , & V_30 ) < 0 )
V_30 = 0 ;
if ( V_30 )
V_6 -> V_88 |= F_59 ( V_91 ) ;
if ( F_24 ( V_9 , V_2 -> V_40 , L_60 ,
L_5 , & V_30 ) < 0 )
V_30 = 0 ;
if ( V_30 )
V_6 -> V_89 |= F_59 ( V_91 ) ;
if ( V_6 -> V_88 & V_6 -> V_89 ) {
F_12 ( V_2 , V_16 ,
L_61
L_62 ,
V_2 -> V_40 ) ;
return - V_84 ;
}
if ( F_24 ( V_9 , V_2 -> V_40 , L_63 ,
L_5 , & V_30 ) < 0 )
V_30 = 0 ;
V_6 -> V_92 = ! V_30 ;
if ( F_24 ( V_9 , V_2 -> V_40 , L_11 ,
L_5 , & V_30 ) < 0 )
V_30 = 0 ;
V_6 -> V_93 = ! ! V_30 ;
return 0 ;
}
int F_60 ( void )
{
return F_61 ( & V_94 ) ;
}
void F_62 ( void )
{
return F_63 ( & V_94 ) ;
}

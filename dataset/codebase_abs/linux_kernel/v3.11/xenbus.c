static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_2 ) ;
F_3 ( V_4 ) ;
if ( V_4 -> V_5 ) {
F_4 ( & V_2 -> V_2 . V_6 , V_7 ) ;
F_5 ( V_8 , V_2 -> V_9 , L_1 ) ;
F_6 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
}
F_7 ( V_4 ) ;
F_8 ( & V_2 -> V_2 , NULL ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const struct V_10 * V_11 )
{
const char * V_12 ;
struct V_13 V_14 ;
int V_15 ;
int V_16 ;
struct V_3 * V_4 = F_10 ( sizeof( struct V_3 ) ,
V_17 ) ;
if ( ! V_4 ) {
F_11 ( V_2 , - V_18 ,
L_2 ) ;
return - V_18 ;
}
V_4 -> V_2 = V_2 ;
F_8 ( & V_2 -> V_2 , V_4 ) ;
V_16 = 1 ;
do {
V_15 = F_12 ( & V_14 ) ;
if ( V_15 ) {
F_11 ( V_2 , V_15 , L_3 ) ;
goto V_19;
}
V_15 = F_13 ( V_14 , V_2 -> V_9 , L_4 , L_5 , V_16 ) ;
if ( V_15 ) {
V_12 = L_6 ;
goto V_20;
}
V_15 = F_13 ( V_14 , V_2 -> V_9 , L_7 ,
L_5 , V_16 ) ;
if ( V_15 ) {
V_12 = L_8 ;
goto V_20;
}
V_15 = F_13 ( V_14 , V_2 -> V_9 ,
L_9 , L_5 , 1 ) ;
if ( V_15 ) {
V_12 = L_10 ;
goto V_20;
}
V_15 = F_13 ( V_14 , V_2 -> V_9 ,
L_11 , L_5 , 0 ) ;
if ( V_15 ) {
V_12 = L_12 ;
goto V_20;
}
V_15 = F_14 ( V_14 , 0 ) ;
} while ( V_15 == - V_21 );
if ( V_15 ) {
F_11 ( V_2 , V_15 , L_13 ) ;
goto V_19;
}
V_15 = F_13 ( V_8 , V_2 -> V_9 ,
L_14 ,
L_15 , V_22 ) ;
if ( V_15 )
F_15 ( L_16 ) ;
V_15 = F_16 ( V_2 , V_23 ) ;
if ( V_15 )
goto V_19;
F_17 ( V_4 ) ;
return 0 ;
V_20:
F_14 ( V_14 , 1 ) ;
F_11 ( V_2 , V_15 , L_17 , V_12 ) ;
V_19:
F_15 ( L_18 ) ;
F_1 ( V_2 ) ;
return V_15 ;
}
static int F_18 ( struct V_1 * V_24 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 = F_2 ( & V_24 -> V_2 ) ;
char * V_27 ;
V_27 = F_19 ( V_8 , V_24 -> V_9 , L_19 , NULL ) ;
if ( F_20 ( V_27 ) ) {
int V_15 = F_21 ( V_27 ) ;
F_11 ( V_24 , V_15 , L_20 ) ;
return V_15 ;
} else {
if ( F_22 ( V_26 , L_21 , V_27 ) ) {
F_7 ( V_27 ) ;
return - V_18 ;
}
F_7 ( V_27 ) ;
}
if ( ! V_4 || ! V_4 -> V_5 )
return 0 ;
return F_22 ( V_26 , L_22 , V_4 -> V_5 -> V_2 -> V_28 ) ;
}
static void F_17 ( struct V_3 * V_4 )
{
int V_15 ;
long V_29 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_4 -> V_5 != NULL )
return;
V_15 = F_23 ( V_8 , V_2 -> V_9 , L_23 , L_24 , & V_29 ) ;
if ( V_15 != 1 ) {
F_11 ( V_2 , V_15 , L_25 ) ;
return;
}
V_4 -> V_5 = F_24 ( & V_2 -> V_2 , V_2 -> V_30 , V_29 ) ;
if ( F_20 ( V_4 -> V_5 ) ) {
V_15 = F_21 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
F_11 ( V_2 , V_15 , L_26 ) ;
return;
}
F_4 ( & V_2 -> V_2 . V_6 , V_31 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_2 ) ;
if ( V_4 -> V_5 ) {
F_5 ( V_8 , V_2 -> V_9 , L_1 ) ;
F_6 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
}
}
static void F_26 ( struct V_1 * V_2 ,
enum V_32 V_33 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_2 ) ;
F_15 ( L_27 , F_27 ( V_33 ) ) ;
V_4 -> V_33 = V_33 ;
switch ( V_33 ) {
case V_34 :
if ( V_2 -> V_35 == V_36 ) {
F_28 ( L_28 , V_2 -> V_9 ) ;
F_16 ( V_2 , V_23 ) ;
}
break;
case V_37 :
break;
case V_38 :
if ( V_2 -> V_35 == V_38 )
break;
F_17 ( V_4 ) ;
if ( V_4 -> V_5 )
F_29 ( V_4 ) ;
break;
case V_39 :
if ( V_4 -> V_5 )
F_4 ( & V_2 -> V_2 . V_6 , V_7 ) ;
F_25 ( V_2 ) ;
F_16 ( V_2 , V_39 ) ;
break;
case V_36 :
F_16 ( V_2 , V_36 ) ;
if ( F_30 ( V_2 ) )
break;
case V_40 :
F_31 ( & V_2 -> V_2 ) ;
break;
default:
F_11 ( V_2 , - V_41 , L_29 ,
V_33 ) ;
break;
}
}
static void F_32 ( struct V_1 * V_2 ,
unsigned long * V_42 , unsigned long * V_43 )
{
char * V_44 , * V_45 ;
unsigned long V_46 , V_47 ;
char * V_48 ;
* V_42 = ~ 0UL ;
* V_43 = 0 ;
V_48 = F_19 ( V_8 , V_2 -> V_9 , L_30 , NULL ) ;
if ( F_20 ( V_48 ) )
return;
V_44 = V_48 ;
V_46 = F_33 ( V_44 , & V_45 , 10 ) ;
if ( ( V_44 == V_45 ) || ( * V_45 != ',' ) )
goto V_19;
V_44 = V_45 + 1 ;
V_47 = F_33 ( V_44 , & V_45 , 10 ) ;
if ( ( V_44 == V_45 ) || ( * V_45 != '\0' ) )
goto V_19;
* V_42 = V_46 ;
* V_43 = V_47 ;
F_7 ( V_48 ) ;
return;
V_19:
F_34 ( L_31 ) ;
F_7 ( V_48 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_49 [] )
{
char * V_44 , * V_45 , * V_50 ;
int V_51 ;
V_50 = V_44 = F_19 ( V_8 , V_2 -> V_9 , L_32 , NULL ) ;
if ( F_20 ( V_50 ) )
return F_21 ( V_50 ) ;
for ( V_51 = 0 ; V_51 < V_52 ; V_51 ++ ) {
V_49 [ V_51 ] = F_33 ( V_44 , & V_45 , 16 ) ;
if ( ( V_44 == V_45 ) || ( * V_45 != ( ( V_51 == V_52 - 1 ) ? '\0' : ':' ) ) ) {
F_7 ( V_50 ) ;
return - V_53 ;
}
V_44 = V_45 + 1 ;
}
F_7 ( V_50 ) ;
return 0 ;
}
static void F_3 ( struct V_3 * V_4 )
{
if ( V_4 -> V_54 ) {
F_36 ( & V_4 -> V_55 ) ;
F_7 ( V_4 -> V_55 . V_56 ) ;
}
V_4 -> V_54 = 0 ;
}
static void F_37 ( struct V_57 * V_58 ,
const char * * V_59 ,
unsigned int V_60 )
{
struct V_3 * V_4 = F_38 ( V_58 ,
struct V_3 ,
V_55 ) ;
char * V_61 ;
unsigned int V_62 ;
V_61 = F_19 ( V_8 , V_4 -> V_2 -> V_9 , L_1 , & V_62 ) ;
if ( F_20 ( V_61 ) )
return;
if ( V_62 == sizeof( L_33 ) - 1 && ! memcmp ( V_61 , L_33 , V_62 ) ) {
F_16 ( V_4 -> V_2 , V_38 ) ;
F_3 ( V_4 ) ;
}
F_7 ( V_61 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
int V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
V_15 = F_39 ( V_4 ) ;
if ( V_15 )
return;
V_15 = F_35 ( V_2 , V_4 -> V_5 -> V_63 ) ;
if ( V_15 ) {
F_11 ( V_2 , V_15 , L_34 , V_2 -> V_9 ) ;
return;
}
F_32 ( V_2 , & V_4 -> V_5 -> V_64 ,
& V_4 -> V_5 -> V_65 ) ;
V_4 -> V_5 -> V_66 = V_4 -> V_5 -> V_64 ;
F_3 ( V_4 ) ;
V_15 = F_40 ( V_2 , & V_4 -> V_55 ,
F_37 ,
L_35 , V_2 -> V_9 , L_1 ) ;
if ( V_15 ) {
F_16 ( V_2 , V_38 ) ;
} else {
V_4 -> V_54 = 1 ;
}
F_41 ( V_4 -> V_5 -> V_2 ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_67 * V_5 = V_4 -> V_5 ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_68 , V_69 ;
unsigned int V_70 , V_71 , V_72 ;
int V_15 ;
int V_27 ;
V_15 = F_42 ( V_8 , V_2 -> V_73 ,
L_36 , L_37 , & V_68 ,
L_38 , L_37 , & V_69 , NULL ) ;
if ( V_15 ) {
F_11 ( V_2 , V_15 ,
L_39 ,
V_2 -> V_73 ) ;
return V_15 ;
}
V_15 = F_42 ( V_8 , V_2 -> V_73 ,
L_40 , L_15 , & V_70 ,
L_41 , L_15 , & V_71 , NULL ) ;
if ( V_15 < 0 ) {
V_15 = F_23 ( V_8 , V_2 -> V_73 ,
L_42 , L_15 , & V_70 ) ;
if ( V_15 < 0 ) {
F_11 ( V_2 , V_15 ,
L_43 ,
V_2 -> V_73 ) ;
return V_15 ;
}
V_71 = V_70 ;
}
V_15 = F_23 ( V_8 , V_2 -> V_73 , L_44 , L_15 ,
& V_72 ) ;
if ( V_15 == - V_53 ) {
V_15 = 0 ;
V_72 = 0 ;
}
if ( V_15 < 0 ) {
F_11 ( V_2 , V_15 , L_45 ,
V_2 -> V_73 ) ;
return V_15 ;
}
if ( ! V_72 )
return - V_74 ;
if ( V_5 -> V_2 -> V_75 != 0 ) {
if ( F_23 ( V_8 , V_2 -> V_73 ,
L_46 , L_5 , & V_27 ) < 0 )
V_27 = 0 ;
if ( V_27 )
V_5 -> V_76 = 1 ;
else
V_5 -> V_2 -> V_75 = 1 ;
}
if ( F_23 ( V_8 , V_2 -> V_73 , L_4 ,
L_5 , & V_27 ) < 0 )
V_27 = 0 ;
V_5 -> V_77 = ! ! V_27 ;
if ( F_23 ( V_8 , V_2 -> V_73 , L_7 ,
L_5 , & V_27 ) < 0 )
V_27 = 0 ;
V_5 -> V_78 = ! ! V_27 ;
if ( F_23 ( V_8 , V_2 -> V_73 , L_47 ,
L_5 , & V_27 ) < 0 )
V_27 = 0 ;
V_5 -> V_79 = ! ! V_27 ;
if ( F_23 ( V_8 , V_2 -> V_73 , L_48 ,
L_5 , & V_27 ) < 0 )
V_27 = 0 ;
V_5 -> V_80 = ! V_27 ;
V_15 = F_43 ( V_5 , V_68 , V_69 ,
V_70 , V_71 ) ;
if ( V_15 ) {
F_11 ( V_2 , V_15 ,
L_49 ,
V_68 , V_69 ,
V_70 , V_71 ) ;
return V_15 ;
}
return 0 ;
}
int F_44 ( void )
{
return F_45 ( & V_81 ) ;
}
void F_46 ( void )
{
return F_47 ( & V_81 ) ;
}

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
V_15 = F_15 ( V_2 , V_22 ) ;
if ( V_15 )
goto V_19;
F_16 ( V_4 ) ;
return 0 ;
V_20:
F_14 ( V_14 , 1 ) ;
F_11 ( V_2 , V_15 , L_14 , V_12 ) ;
V_19:
F_17 ( L_15 ) ;
F_1 ( V_2 ) ;
return V_15 ;
}
static int F_18 ( struct V_1 * V_23 ,
struct V_24 * V_25 )
{
struct V_3 * V_4 = F_2 ( & V_23 -> V_2 ) ;
char * V_26 ;
V_26 = F_19 ( V_8 , V_23 -> V_9 , L_16 , NULL ) ;
if ( F_20 ( V_26 ) ) {
int V_15 = F_21 ( V_26 ) ;
F_11 ( V_23 , V_15 , L_17 ) ;
return V_15 ;
} else {
if ( F_22 ( V_25 , L_18 , V_26 ) ) {
F_7 ( V_26 ) ;
return - V_18 ;
}
F_7 ( V_26 ) ;
}
if ( ! V_4 || ! V_4 -> V_5 )
return 0 ;
return F_22 ( V_25 , L_19 , V_4 -> V_5 -> V_2 -> V_27 ) ;
}
static void F_16 ( struct V_3 * V_4 )
{
int V_15 ;
long V_28 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_4 -> V_5 != NULL )
return;
V_15 = F_23 ( V_8 , V_2 -> V_9 , L_20 , L_21 , & V_28 ) ;
if ( V_15 != 1 ) {
F_11 ( V_2 , V_15 , L_22 ) ;
return;
}
V_4 -> V_5 = F_24 ( & V_2 -> V_2 , V_2 -> V_29 , V_28 ) ;
if ( F_20 ( V_4 -> V_5 ) ) {
V_15 = F_21 ( V_4 -> V_5 ) ;
V_4 -> V_5 = NULL ;
F_11 ( V_2 , V_15 , L_23 ) ;
return;
}
F_4 ( & V_2 -> V_2 . V_6 , V_30 ) ;
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
enum V_31 V_32 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_2 ) ;
F_17 ( L_24 , F_27 ( V_32 ) ) ;
V_4 -> V_32 = V_32 ;
switch ( V_32 ) {
case V_33 :
if ( V_2 -> V_34 == V_35 ) {
F_28 ( V_36 L_25 ,
V_37 , V_2 -> V_9 ) ;
F_15 ( V_2 , V_22 ) ;
}
break;
case V_38 :
break;
case V_39 :
if ( V_2 -> V_34 == V_39 )
break;
F_16 ( V_4 ) ;
if ( V_4 -> V_5 )
F_29 ( V_4 ) ;
break;
case V_40 :
if ( V_4 -> V_5 )
F_4 ( & V_2 -> V_2 . V_6 , V_7 ) ;
F_25 ( V_2 ) ;
F_15 ( V_2 , V_40 ) ;
break;
case V_35 :
F_15 ( V_2 , V_35 ) ;
if ( F_30 ( V_2 ) )
break;
case V_41 :
F_31 ( & V_2 -> V_2 ) ;
break;
default:
F_11 ( V_2 , - V_42 , L_26 ,
V_32 ) ;
break;
}
}
static void F_32 ( struct V_1 * V_2 ,
unsigned long * V_43 , unsigned long * V_44 )
{
char * V_45 , * V_46 ;
unsigned long V_47 , V_48 ;
char * V_49 ;
* V_43 = ~ 0UL ;
* V_44 = 0 ;
V_49 = F_19 ( V_8 , V_2 -> V_9 , L_27 , NULL ) ;
if ( F_20 ( V_49 ) )
return;
V_45 = V_49 ;
V_47 = F_33 ( V_45 , & V_46 , 10 ) ;
if ( ( V_45 == V_46 ) || ( * V_46 != ',' ) )
goto V_19;
V_45 = V_46 + 1 ;
V_48 = F_33 ( V_45 , & V_46 , 10 ) ;
if ( ( V_45 == V_46 ) || ( * V_46 != '\0' ) )
goto V_19;
* V_43 = V_47 ;
* V_44 = V_48 ;
F_7 ( V_49 ) ;
return;
V_19:
F_34 ( L_28 ) ;
F_7 ( V_49 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_1 V_50 [] )
{
char * V_45 , * V_46 , * V_51 ;
int V_52 ;
V_51 = V_45 = F_19 ( V_8 , V_2 -> V_9 , L_29 , NULL ) ;
if ( F_20 ( V_51 ) )
return F_21 ( V_51 ) ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
V_50 [ V_52 ] = F_33 ( V_45 , & V_46 , 16 ) ;
if ( ( V_45 == V_46 ) || ( * V_46 != ( ( V_52 == V_53 - 1 ) ? '\0' : ':' ) ) ) {
F_7 ( V_51 ) ;
return - V_54 ;
}
V_45 = V_46 + 1 ;
}
F_7 ( V_51 ) ;
return 0 ;
}
static void F_3 ( struct V_3 * V_4 )
{
if ( V_4 -> V_55 ) {
F_36 ( & V_4 -> V_56 ) ;
F_7 ( V_4 -> V_56 . V_57 ) ;
}
V_4 -> V_55 = 0 ;
}
static void F_37 ( struct V_58 * V_59 ,
const char * * V_60 ,
unsigned int V_61 )
{
struct V_3 * V_4 = F_38 ( V_59 ,
struct V_3 ,
V_56 ) ;
char * V_62 ;
unsigned int V_63 ;
V_62 = F_19 ( V_8 , V_4 -> V_2 -> V_9 , L_1 , & V_63 ) ;
if ( F_20 ( V_62 ) )
return;
if ( V_63 == sizeof( L_30 ) - 1 && ! memcmp ( V_62 , L_30 , V_63 ) ) {
F_15 ( V_4 -> V_2 , V_39 ) ;
F_3 ( V_4 ) ;
}
F_7 ( V_62 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
int V_15 ;
struct V_1 * V_2 = V_4 -> V_2 ;
V_15 = F_39 ( V_4 ) ;
if ( V_15 )
return;
V_15 = F_35 ( V_2 , V_4 -> V_5 -> V_64 ) ;
if ( V_15 ) {
F_11 ( V_2 , V_15 , L_31 , V_2 -> V_9 ) ;
return;
}
F_32 ( V_2 , & V_4 -> V_5 -> V_65 ,
& V_4 -> V_5 -> V_66 ) ;
V_4 -> V_5 -> V_67 = V_4 -> V_5 -> V_65 ;
F_3 ( V_4 ) ;
V_15 = F_40 ( V_2 , & V_4 -> V_56 ,
F_37 ,
L_32 , V_2 -> V_9 , L_1 ) ;
if ( V_15 ) {
F_15 ( V_2 , V_39 ) ;
} else {
V_4 -> V_55 = 1 ;
}
F_41 ( V_4 -> V_5 -> V_2 ) ;
}
static int F_39 ( struct V_3 * V_4 )
{
struct V_68 * V_5 = V_4 -> V_5 ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_69 , V_70 ;
unsigned int V_71 , V_72 ;
int V_15 ;
int V_26 ;
V_15 = F_42 ( V_8 , V_2 -> V_73 ,
L_33 , L_34 , & V_69 ,
L_35 , L_34 , & V_70 ,
L_36 , L_37 , & V_71 , NULL ) ;
if ( V_15 ) {
F_11 ( V_2 , V_15 ,
L_38 ,
V_2 -> V_73 ) ;
return V_15 ;
}
V_15 = F_23 ( V_8 , V_2 -> V_73 , L_39 , L_37 ,
& V_72 ) ;
if ( V_15 == - V_54 ) {
V_15 = 0 ;
V_72 = 0 ;
}
if ( V_15 < 0 ) {
F_11 ( V_2 , V_15 , L_40 ,
V_2 -> V_73 ) ;
return V_15 ;
}
if ( ! V_72 )
return - V_74 ;
if ( V_5 -> V_2 -> V_75 != 0 ) {
if ( F_23 ( V_8 , V_2 -> V_73 ,
L_41 , L_5 , & V_26 ) < 0 )
V_26 = 0 ;
if ( V_26 )
V_5 -> V_76 = 1 ;
else
V_5 -> V_2 -> V_75 = 1 ;
}
if ( F_23 ( V_8 , V_2 -> V_73 , L_4 ,
L_5 , & V_26 ) < 0 )
V_26 = 0 ;
V_5 -> V_77 = ! ! V_26 ;
if ( F_23 ( V_8 , V_2 -> V_73 , L_7 ,
L_5 , & V_26 ) < 0 )
V_26 = 0 ;
V_5 -> V_78 = ! ! V_26 ;
if ( F_23 ( V_8 , V_2 -> V_73 , L_42 ,
L_5 , & V_26 ) < 0 )
V_26 = 0 ;
V_5 -> V_79 = ! ! V_26 ;
if ( F_23 ( V_8 , V_2 -> V_73 , L_43 ,
L_5 , & V_26 ) < 0 )
V_26 = 0 ;
V_5 -> V_80 = ! V_26 ;
V_15 = F_43 ( V_5 , V_69 , V_70 , V_71 ) ;
if ( V_15 ) {
F_11 ( V_2 , V_15 ,
L_44 ,
V_69 , V_70 , V_71 ) ;
return V_15 ;
}
return 0 ;
}
int F_44 ( void )
{
return F_45 ( & V_81 ) ;
}

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
V_16 = F_17 ( V_2 , V_24 ) ;
if ( V_16 )
goto V_20;
V_4 -> V_25 = V_24 ;
F_18 ( V_4 ) ;
return 0 ;
V_21:
F_15 ( V_15 , 1 ) ;
F_12 ( V_2 , V_16 , L_21 , V_13 ) ;
V_20:
F_16 ( L_22 ) ;
F_1 ( V_2 ) ;
return V_16 ;
}
static int F_19 ( struct V_1 * V_26 ,
struct V_27 * V_28 )
{
struct V_3 * V_4 = F_2 ( & V_26 -> V_2 ) ;
char * V_29 ;
V_29 = F_20 ( V_9 , V_26 -> V_10 , L_23 , NULL ) ;
if ( F_21 ( V_29 ) ) {
int V_16 = F_22 ( V_29 ) ;
F_12 ( V_26 , V_16 , L_24 ) ;
return V_16 ;
} else {
if ( F_23 ( V_28 , L_25 , V_29 ) ) {
F_8 ( V_29 ) ;
return - V_19 ;
}
F_8 ( V_29 ) ;
}
if ( ! V_4 || ! V_4 -> V_6 )
return 0 ;
return F_23 ( V_28 , L_26 , V_4 -> V_6 -> V_2 -> V_30 ) ;
}
static void F_18 ( struct V_3 * V_4 )
{
int V_16 ;
long V_31 ;
struct V_1 * V_2 = V_4 -> V_2 ;
if ( V_4 -> V_6 != NULL )
return;
V_16 = F_24 ( V_9 , V_2 -> V_10 , L_27 , L_28 , & V_31 ) ;
if ( V_16 != 1 ) {
F_12 ( V_2 , V_16 , L_29 ) ;
return;
}
V_4 -> V_6 = F_25 ( & V_2 -> V_2 , V_2 -> V_32 , V_31 ) ;
if ( F_21 ( V_4 -> V_6 ) ) {
V_16 = F_22 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
F_12 ( V_2 , V_16 , L_30 ) ;
return;
}
F_5 ( & V_2 -> V_2 . V_7 , V_33 ) ;
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
enum V_34 V_25 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
F_16 ( L_31 , V_2 -> V_10 , F_31 ( V_25 ) ) ;
V_4 -> V_25 = V_25 ;
if ( ! V_4 -> V_35 )
F_17 ( V_2 , V_25 ) ;
}
static void F_3 ( struct V_3 * V_4 ,
enum V_34 V_25 )
{
while ( V_4 -> V_25 != V_25 ) {
switch ( V_4 -> V_25 ) {
case V_5 :
switch ( V_25 ) {
case V_24 :
case V_36 :
F_32 ( L_32 ,
V_4 -> V_2 -> V_10 ) ;
F_30 ( V_4 , V_24 ) ;
break;
case V_37 :
F_30 ( V_4 , V_37 ) ;
break;
default:
F_33 () ;
}
break;
case V_24 :
switch ( V_25 ) {
case V_36 :
F_28 ( V_4 ) ;
F_30 ( V_4 , V_36 ) ;
break;
case V_37 :
case V_5 :
F_30 ( V_4 , V_37 ) ;
break;
default:
F_33 () ;
}
break;
case V_36 :
switch ( V_25 ) {
case V_24 :
case V_37 :
case V_5 :
F_26 ( V_4 ) ;
F_30 ( V_4 , V_37 ) ;
break;
default:
F_33 () ;
}
break;
case V_37 :
switch ( V_25 ) {
case V_24 :
case V_36 :
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
enum V_34 V_38 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_2 ) ;
F_16 ( L_31 , V_2 -> V_39 , F_31 ( V_38 ) ) ;
V_4 -> V_38 = V_38 ;
switch ( V_38 ) {
case V_40 :
F_3 ( V_4 , V_24 ) ;
break;
case V_41 :
break;
case V_36 :
F_3 ( V_4 , V_36 ) ;
break;
case V_37 :
F_3 ( V_4 , V_37 ) ;
break;
case V_5 :
F_3 ( V_4 , V_5 ) ;
if ( F_35 ( V_2 ) )
break;
case V_42 :
F_3 ( V_4 , V_5 ) ;
F_36 ( & V_2 -> V_2 ) ;
break;
default:
F_12 ( V_2 , - V_43 , L_33 ,
V_38 ) ;
break;
}
}
static void F_37 ( struct V_1 * V_2 ,
unsigned long * V_44 , unsigned long * V_45 )
{
char * V_46 , * V_47 ;
unsigned long V_48 , V_49 ;
char * V_50 ;
* V_44 = ~ 0UL ;
* V_45 = 0 ;
V_50 = F_20 ( V_9 , V_2 -> V_10 , L_34 , NULL ) ;
if ( F_21 ( V_50 ) )
return;
V_46 = V_50 ;
V_48 = F_38 ( V_46 , & V_47 , 10 ) ;
if ( ( V_46 == V_47 ) || ( * V_47 != ',' ) )
goto V_20;
V_46 = V_47 + 1 ;
V_49 = F_38 ( V_46 , & V_47 , 10 ) ;
if ( ( V_46 == V_47 ) || ( * V_47 != '\0' ) )
goto V_20;
* V_44 = V_48 ;
* V_45 = V_49 ;
F_8 ( V_50 ) ;
return;
V_20:
F_39 ( L_35 ) ;
F_8 ( V_50 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_51 [] )
{
char * V_46 , * V_47 , * V_52 ;
int V_53 ;
V_52 = V_46 = F_20 ( V_9 , V_2 -> V_10 , L_36 , NULL ) ;
if ( F_21 ( V_52 ) )
return F_22 ( V_52 ) ;
for ( V_53 = 0 ; V_53 < V_54 ; V_53 ++ ) {
V_51 [ V_53 ] = F_38 ( V_46 , & V_47 , 16 ) ;
if ( ( V_46 == V_47 ) || ( * V_47 != ( ( V_53 == V_54 - 1 ) ? '\0' : ':' ) ) ) {
F_8 ( V_52 ) ;
return - V_55 ;
}
V_46 = V_47 + 1 ;
}
F_8 ( V_52 ) ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 )
{
if ( V_4 -> V_35 ) {
F_41 ( & V_4 -> V_56 ) ;
F_8 ( V_4 -> V_56 . V_57 ) ;
}
V_4 -> V_35 = 0 ;
}
static void F_42 ( struct V_58 * V_59 ,
const char * * V_60 ,
unsigned int V_61 )
{
struct V_3 * V_4 = F_43 ( V_59 ,
struct V_3 ,
V_56 ) ;
char * V_62 ;
unsigned int V_63 ;
V_62 = F_20 ( V_9 , V_4 -> V_2 -> V_10 , L_1 , & V_63 ) ;
if ( F_21 ( V_62 ) )
return;
if ( V_63 == sizeof( L_37 ) - 1 && ! memcmp ( V_62 , L_37 , V_63 ) ) {
F_17 ( V_4 -> V_2 , V_4 -> V_25 ) ;
F_4 ( V_4 ) ;
}
F_8 ( V_62 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
int V_16 ;
struct V_1 * V_2 = V_4 -> V_2 ;
V_16 = F_44 ( V_4 ) ;
if ( V_16 )
return;
V_16 = F_40 ( V_2 , V_4 -> V_6 -> V_64 ) ;
if ( V_16 ) {
F_12 ( V_2 , V_16 , L_38 , V_2 -> V_10 ) ;
return;
}
F_37 ( V_2 , & V_4 -> V_6 -> V_65 ,
& V_4 -> V_6 -> V_66 ) ;
V_4 -> V_6 -> V_67 = V_4 -> V_6 -> V_65 ;
F_4 ( V_4 ) ;
V_16 = F_45 ( V_2 , & V_4 -> V_56 ,
F_42 ,
L_39 , V_2 -> V_10 , L_1 ) ;
if ( ! V_16 )
V_4 -> V_35 = 1 ;
F_46 ( V_4 -> V_6 -> V_2 ) ;
}
static int F_44 ( struct V_3 * V_4 )
{
struct V_68 * V_6 = V_4 -> V_6 ;
struct V_1 * V_2 = V_4 -> V_2 ;
unsigned long V_69 , V_70 ;
unsigned int V_71 , V_72 , V_73 ;
int V_16 ;
int V_29 ;
V_16 = F_47 ( V_9 , V_2 -> V_39 ,
L_40 , L_41 , & V_69 ,
L_42 , L_41 , & V_70 , NULL ) ;
if ( V_16 ) {
F_12 ( V_2 , V_16 ,
L_43 ,
V_2 -> V_39 ) ;
return V_16 ;
}
V_16 = F_47 ( V_9 , V_2 -> V_39 ,
L_44 , L_19 , & V_71 ,
L_45 , L_19 , & V_72 , NULL ) ;
if ( V_16 < 0 ) {
V_16 = F_24 ( V_9 , V_2 -> V_39 ,
L_46 , L_19 , & V_71 ) ;
if ( V_16 < 0 ) {
F_12 ( V_2 , V_16 ,
L_47 ,
V_2 -> V_39 ) ;
return V_16 ;
}
V_72 = V_71 ;
}
V_16 = F_24 ( V_9 , V_2 -> V_39 , L_48 , L_19 ,
& V_73 ) ;
if ( V_16 == - V_55 ) {
V_16 = 0 ;
V_73 = 0 ;
}
if ( V_16 < 0 ) {
F_12 ( V_2 , V_16 , L_49 ,
V_2 -> V_39 ) ;
return V_16 ;
}
if ( ! V_73 )
return - V_74 ;
if ( V_6 -> V_2 -> V_75 != 0 ) {
if ( F_24 ( V_9 , V_2 -> V_39 ,
L_50 , L_5 , & V_29 ) < 0 )
V_29 = 0 ;
if ( V_29 )
V_6 -> V_76 = 1 ;
else
V_6 -> V_2 -> V_75 = 1 ;
}
if ( F_24 ( V_9 , V_2 -> V_39 , L_4 ,
L_5 , & V_29 ) < 0 )
V_29 = 0 ;
V_6 -> V_77 = ! ! V_29 ;
V_6 -> V_78 = 0 ;
V_6 -> V_79 = 0 ;
if ( F_24 ( V_9 , V_2 -> V_39 , L_7 ,
L_5 , & V_29 ) < 0 )
V_29 = 0 ;
if ( V_29 )
V_6 -> V_78 |= F_48 ( V_80 ) ;
if ( F_24 ( V_9 , V_2 -> V_39 , L_51 ,
L_5 , & V_29 ) < 0 )
V_29 = 0 ;
if ( V_29 )
V_6 -> V_79 |= F_48 ( V_80 ) ;
if ( F_24 ( V_9 , V_2 -> V_39 , L_9 ,
L_5 , & V_29 ) < 0 )
V_29 = 0 ;
if ( V_29 )
V_6 -> V_78 |= F_48 ( V_81 ) ;
if ( F_24 ( V_9 , V_2 -> V_39 , L_52 ,
L_5 , & V_29 ) < 0 )
V_29 = 0 ;
if ( V_29 )
V_6 -> V_79 |= F_48 ( V_81 ) ;
if ( V_6 -> V_78 & V_6 -> V_79 ) {
F_12 ( V_2 , V_16 ,
L_53
L_54 ,
V_2 -> V_39 ) ;
return - V_74 ;
}
if ( F_24 ( V_9 , V_2 -> V_39 , L_55 ,
L_5 , & V_29 ) < 0 )
V_29 = 0 ;
V_6 -> V_82 = ! V_29 ;
if ( F_24 ( V_9 , V_2 -> V_39 , L_11 ,
L_5 , & V_29 ) < 0 )
V_29 = 0 ;
V_6 -> V_83 = ! ! V_29 ;
V_16 = F_49 ( V_6 , V_69 , V_70 ,
V_71 , V_72 ) ;
if ( V_16 ) {
F_12 ( V_2 , V_16 ,
L_56 ,
V_69 , V_70 ,
V_71 , V_72 ) ;
return V_16 ;
}
return 0 ;
}
int F_50 ( void )
{
return F_51 ( & V_84 ) ;
}
void F_52 ( void )
{
return F_53 ( & V_84 ) ;
}

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
V_3 = ( char * ) V_6 + V_6 -> V_8 ;
V_2 -> V_3 = F_5 ( V_3 , V_7 ) ;
V_2 -> V_9 = V_6 -> V_10 ;
V_4 = ( char * ) V_6 + V_6 -> V_11 ;
V_2 -> V_4 = F_6 ( V_4 , V_2 -> V_9 , V_7 ) ;
if ( ! V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
static struct V_12 * F_7 ( struct V_5 * V_6 )
{
struct V_12 * V_13 ;
char * V_3 ;
V_13 = F_4 ( sizeof( * V_13 ) , V_7 ) ;
if ( ! V_13 )
return NULL ;
V_3 = ( char * ) V_6 + V_6 -> V_8 ;
V_13 -> V_14 = F_8 ( V_7 , L_1 , V_3 ) ;
if ( ! V_13 -> V_14 ) {
F_2 ( V_13 ) ;
return NULL ;
}
return V_13 ;
}
static void F_9 ( struct V_12 * V_13 )
{
struct V_1 * V_2 ;
while ( V_13 -> V_15 ) {
V_2 = V_13 -> V_15 ;
V_13 -> V_15 = V_2 -> V_16 ;
F_1 ( V_2 ) ;
}
F_2 ( V_13 -> V_14 ) ;
F_2 ( V_13 ) ;
}
void F_10 ( struct V_12 * V_13 )
{
if ( V_13 -> V_17 )
F_10 ( V_13 -> V_17 ) ;
if ( V_13 -> V_18 )
F_10 ( V_13 -> V_18 ) ;
F_9 ( V_13 ) ;
}
struct V_12 * F_11 ( T_1 V_19 )
{
struct V_12 * V_13 ;
struct V_12 * V_20 = NULL ;
struct V_12 * V_21 = NULL ;
struct V_1 * V_1 ;
struct V_1 * V_22 = NULL ;
struct V_5 * V_6 ;
char * V_23 ;
int V_24 ;
int V_25 = - 1 ;
V_24 = F_12 ( L_2 ) ;
if ( V_24 == V_26 )
return NULL ;
V_23 = F_4 ( V_27 , V_7 ) ;
if ( ! V_23 )
return NULL ;
V_6 = (struct V_5 * ) & V_23 [ 0 ] ;
V_6 -> V_19 = V_19 ;
V_6 -> V_28 = 0 ;
do {
F_13 ( & V_29 ) ;
memcpy ( V_30 , V_23 , V_27 ) ;
V_25 = F_14 ( V_24 , 2 , 1 , NULL , V_30 , NULL ) ;
memcpy ( V_23 , V_30 , V_27 ) ;
F_15 ( & V_29 ) ;
switch ( V_25 ) {
case V_31 :
break;
case V_32 :
V_13 = F_7 ( V_6 ) ;
if ( ! V_13 )
goto V_33;
V_13 -> V_34 = V_21 -> V_34 ;
V_21 -> V_18 = V_13 ;
V_21 = V_13 ;
break;
case V_35 :
V_13 = F_7 ( V_6 ) ;
if ( ! V_13 )
goto V_33;
if ( ! V_20 )
V_20 = V_13 ;
else {
V_13 -> V_34 = V_21 ;
if ( V_21 )
V_21 -> V_17 = V_13 ;
}
V_21 = V_13 ;
break;
case V_36 :
V_1 = F_3 ( V_6 ) ;
if ( ! V_1 )
goto V_33;
if ( ! V_21 -> V_15 )
V_21 -> V_15 = V_1 ;
else
V_22 -> V_16 = V_1 ;
V_22 = V_1 ;
break;
case V_37 :
V_21 = V_21 -> V_34 ;
break;
case V_38 :
break;
case V_39 :
case V_40 :
default:
F_16 ( V_41 L_3
L_4 , V_25 ) ;
goto V_33;
}
} while ( V_25 );
V_33:
F_2 ( V_23 ) ;
if ( V_25 ) {
if ( V_20 )
F_10 ( V_20 ) ;
return NULL ;
}
return V_20 ;
}
static struct V_12 * F_17 ( const char * V_42 )
{
struct V_12 * V_34 ;
char * V_43 ;
V_43 = strrchr ( V_42 , '/' ) ;
if ( V_43 == V_42 ) {
V_34 = F_18 ( L_5 ) ;
} else {
char * V_44 ;
int V_45 = V_43 - V_42 + 1 ;
V_44 = F_19 ( V_45 , V_7 ) ;
if ( ! V_44 )
return NULL ;
F_20 ( V_44 , V_42 , V_45 ) ;
V_34 = F_18 ( V_44 ) ;
F_2 ( V_44 ) ;
}
return V_34 ;
}
int F_21 ( struct V_12 * V_13 )
{
int V_25 ;
F_22 ( V_13 , V_46 ) ;
F_23 ( & V_13 -> V_47 ) ;
V_13 -> V_34 = F_17 ( V_13 -> V_14 ) ;
if ( ! V_13 -> V_34 )
return - V_48 ;
V_25 = F_24 ( V_13 ) ;
if ( V_25 ) {
F_16 ( V_41 L_6 ,
V_13 -> V_14 ) ;
return V_25 ;
}
F_25 ( V_13 -> V_34 ) ;
return 0 ;
}
int F_26 ( struct V_12 * V_13 )
{
int V_25 ;
V_25 = F_27 ( V_13 ) ;
if ( V_25 )
return V_25 ;
F_25 ( V_13 ) ;
return 0 ;
}
int F_28 ( T_1 V_19 )
{
int V_49 , V_25 ;
V_25 = F_14 ( F_12 ( L_7 ) , 2 , 2 , & V_49 ,
V_50 , V_19 ) ;
if ( V_25 || V_49 != V_51 )
return - 1 ;
V_25 = F_29 ( V_52 , V_19 , V_53 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_54 , V_19 , V_55 ) ;
if ( V_25 ) {
F_29 ( V_52 , V_19 , V_56 ) ;
return V_25 ;
}
return 0 ;
}
int F_30 ( T_1 V_19 )
{
int V_49 , V_25 ;
V_25 = F_14 ( F_12 ( L_7 ) , 2 , 2 , & V_49 ,
V_50 , V_19 ) ;
if ( V_25 || V_49 != V_57 )
return - 1 ;
V_25 = F_29 ( V_54 , V_19 , V_58 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_29 ( V_52 , V_19 , V_56 ) ;
if ( V_25 ) {
F_29 ( V_54 , V_19 , V_55 ) ;
return V_25 ;
}
return 0 ;
}
static int F_31 ( struct V_12 * V_13 )
{
int V_25 = 0 ;
unsigned int V_59 ;
int V_60 , V_61 , V_62 ;
const T_1 * V_63 ;
V_63 = F_32 ( V_13 , L_8 , & V_60 ) ;
if ( ! V_63 )
return - V_64 ;
V_61 = V_60 / sizeof( T_1 ) ;
F_33 () ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
F_34 (cpu) {
if ( F_35 ( V_59 ) != V_63 [ V_62 ] )
continue;
F_36 ( F_37 ( V_59 )
!= V_65 ) ;
F_38 () ;
V_25 = F_39 ( V_59 ) ;
if ( V_25 )
goto V_66;
F_33 () ;
break;
}
if ( V_59 == F_40 () )
F_16 ( V_67 L_9
L_10 , V_63 [ V_62 ] ) ;
}
F_38 () ;
V_66:
return V_25 ;
}
static T_2 F_41 ( const char * V_68 , T_3 V_69 )
{
struct V_12 * V_13 ;
unsigned long V_19 ;
char * V_70 ;
int V_25 ;
F_42 () ;
V_25 = F_43 ( V_68 , 0 , & V_19 ) ;
if ( V_25 ) {
V_25 = - V_64 ;
goto V_66;
}
V_13 = F_11 ( V_19 ) ;
if ( ! V_13 ) {
V_25 = - V_64 ;
goto V_66;
}
V_70 = F_8 ( V_7 , L_11 , V_13 -> V_14 ) ;
if ( ! V_70 ) {
F_10 ( V_13 ) ;
V_25 = - V_48 ;
goto V_66;
}
F_2 ( V_13 -> V_14 ) ;
V_13 -> V_14 = V_70 ;
V_25 = F_28 ( V_19 ) ;
if ( V_25 ) {
F_10 ( V_13 ) ;
V_25 = - V_64 ;
goto V_66;
}
V_25 = F_21 ( V_13 ) ;
if ( V_25 ) {
F_30 ( V_19 ) ;
F_10 ( V_13 ) ;
goto V_66;
}
V_25 = F_31 ( V_13 ) ;
V_66:
F_44 () ;
return V_25 ? V_25 : V_69 ;
}
static int F_45 ( struct V_12 * V_13 )
{
int V_25 = 0 ;
unsigned int V_59 ;
int V_60 , V_61 , V_62 ;
const T_1 * V_63 ;
V_63 = F_32 ( V_13 , L_8 , & V_60 ) ;
if ( ! V_63 )
return - V_64 ;
V_61 = V_60 / sizeof( T_1 ) ;
F_33 () ;
for ( V_62 = 0 ; V_62 < V_61 ; V_62 ++ ) {
F_34 (cpu) {
if ( F_35 ( V_59 ) != V_63 [ V_62 ] )
continue;
if ( F_37 ( V_59 ) == V_65 )
break;
if ( F_37 ( V_59 ) == V_71 ) {
F_46 ( V_59 , V_65 ) ;
F_38 () ;
V_25 = F_47 ( V_59 ) ;
if ( V_25 )
goto V_66;
F_33 () ;
break;
}
F_46 ( V_59 , V_65 ) ;
F_36 ( F_48 ( V_72 , V_63 [ V_62 ] )
!= V_73 ) ;
F_49 ( V_59 ) ;
break;
}
if ( V_59 == F_40 () )
F_16 ( V_67 L_12
L_10 , V_63 [ V_62 ] ) ;
}
F_38 () ;
V_66:
return V_25 ;
}
static T_2 F_50 ( const char * V_68 , T_3 V_69 )
{
struct V_12 * V_13 ;
const T_1 * V_19 ;
int V_25 ;
V_13 = F_18 ( V_68 ) ;
if ( ! V_13 )
return - V_64 ;
V_19 = F_32 ( V_13 , L_13 , NULL ) ;
if ( ! V_19 ) {
F_25 ( V_13 ) ;
return - V_64 ;
}
F_42 () ;
V_25 = F_45 ( V_13 ) ;
if ( V_25 ) {
F_25 ( V_13 ) ;
V_25 = - V_64 ;
goto V_66;
}
V_25 = F_30 ( * V_19 ) ;
if ( V_25 ) {
F_25 ( V_13 ) ;
goto V_66;
}
V_25 = F_26 ( V_13 ) ;
if ( V_25 ) {
F_28 ( * V_19 ) ;
goto V_66;
}
F_25 ( V_13 ) ;
V_66:
F_44 () ;
return V_25 ? V_25 : V_69 ;
}
static int T_4 F_51 ( void )
{
V_74 . V_75 = F_41 ;
V_74 . V_76 = F_50 ;
return 0 ;
}

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
static struct V_12 * F_20 ( const char * V_13 )
{
struct V_12 * V_22 ;
char * V_45 ;
V_45 = strrchr ( V_13 , '/' ) ;
if ( V_45 == V_13 ) {
V_22 = F_21 ( L_5 ) ;
} else {
char * V_27 ;
int V_46 = V_45 - V_13 + 1 ;
V_27 = F_22 ( V_46 , V_7 ) ;
if ( ! V_27 )
return NULL ;
F_23 ( V_27 , V_13 , V_46 ) ;
V_22 = F_21 ( V_27 ) ;
F_2 ( V_27 ) ;
}
return V_22 ;
}
int F_24 ( struct V_12 * V_14 )
{
int V_29 ;
V_14 -> V_22 = F_20 ( V_14 -> V_15 ) ;
if ( ! V_14 -> V_22 )
return - V_47 ;
V_29 = F_25 ( V_14 ) ;
if ( V_29 ) {
F_19 ( V_44 L_6 ,
V_14 -> V_15 ) ;
return V_29 ;
}
F_26 ( V_14 -> V_22 ) ;
return 0 ;
}
int F_27 ( struct V_12 * V_14 )
{
struct V_12 * V_19 ;
int V_29 ;
V_19 = F_28 ( V_14 , NULL ) ;
while ( V_19 ) {
F_27 ( V_19 ) ;
V_19 = F_28 ( V_14 , V_19 ) ;
}
V_29 = F_29 ( V_14 ) ;
if ( V_29 )
return V_29 ;
F_26 ( V_14 ) ;
return 0 ;
}
int F_30 ( T_2 V_21 )
{
int V_48 , V_29 ;
V_29 = F_17 ( F_15 ( L_7 ) , 2 , 2 , & V_48 ,
V_49 , V_21 ) ;
if ( V_29 || V_48 != V_50 )
return - 1 ;
V_29 = F_31 ( V_51 , V_21 , V_52 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_31 ( V_53 , V_21 , V_54 ) ;
if ( V_29 ) {
F_31 ( V_51 , V_21 , V_55 ) ;
return V_29 ;
}
return 0 ;
}
int F_32 ( T_2 V_21 )
{
int V_48 , V_29 ;
V_29 = F_17 ( F_15 ( L_7 ) , 2 , 2 , & V_48 ,
V_49 , V_21 ) ;
if ( V_29 || V_48 != V_56 )
return - 1 ;
V_29 = F_31 ( V_53 , V_21 , V_57 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_31 ( V_51 , V_21 , V_55 ) ;
if ( V_29 ) {
F_31 ( V_53 , V_21 , V_54 ) ;
return V_29 ;
}
return 0 ;
}
static int F_33 ( struct V_12 * V_14 )
{
int V_29 = 0 ;
unsigned int V_58 ;
int V_59 , V_60 , V_61 ;
const T_1 * V_62 ;
T_2 V_63 ;
V_62 = F_34 ( V_14 , L_8 , & V_59 ) ;
if ( ! V_62 )
return - V_64 ;
V_60 = V_59 / sizeof( T_2 ) ;
F_35 () ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
V_63 = F_5 ( V_62 [ V_61 ] ) ;
F_36 (cpu) {
if ( F_37 ( V_58 ) != V_63 )
continue;
F_38 ( F_39 ( V_58 )
!= V_65 ) ;
F_40 () ;
V_29 = F_41 ( F_42 ( V_58 ) ) ;
if ( V_29 )
goto V_66;
F_35 () ;
break;
}
if ( V_58 == F_43 () )
F_19 ( V_67 L_9
L_10 , V_63 ) ;
}
F_40 () ;
V_66:
return V_29 ;
}
static T_3 F_44 ( const char * V_68 , T_4 V_69 )
{
struct V_12 * V_14 , * V_22 ;
T_2 V_21 ;
int V_29 ;
V_29 = F_45 ( V_68 , 0 , & V_21 ) ;
if ( V_29 )
return - V_64 ;
V_22 = F_21 ( L_11 ) ;
if ( ! V_22 )
return - V_70 ;
V_14 = F_14 ( F_46 ( V_21 ) , V_22 ) ;
if ( ! V_14 )
return - V_64 ;
F_26 ( V_22 ) ;
V_29 = F_30 ( V_21 ) ;
if ( V_29 ) {
F_13 ( V_14 ) ;
return - V_64 ;
}
V_29 = F_24 ( V_14 ) ;
if ( V_29 ) {
F_32 ( V_21 ) ;
F_13 ( V_14 ) ;
return V_29 ;
}
V_29 = F_33 ( V_14 ) ;
if ( V_29 )
return V_29 ;
return V_69 ;
}
static int F_47 ( struct V_12 * V_14 )
{
int V_29 = 0 ;
unsigned int V_58 ;
int V_59 , V_60 , V_61 ;
const T_1 * V_62 ;
T_2 V_63 ;
V_62 = F_34 ( V_14 , L_8 , & V_59 ) ;
if ( ! V_62 )
return - V_64 ;
V_60 = V_59 / sizeof( T_2 ) ;
F_35 () ;
for ( V_61 = 0 ; V_61 < V_60 ; V_61 ++ ) {
V_63 = F_5 ( V_62 [ V_61 ] ) ;
F_36 (cpu) {
if ( F_37 ( V_58 ) != V_63 )
continue;
if ( F_39 ( V_58 ) == V_65 )
break;
if ( F_39 ( V_58 ) == V_71 ) {
F_48 ( V_58 , V_65 ) ;
F_40 () ;
V_29 = F_49 ( F_42 ( V_58 ) ) ;
if ( V_29 )
goto V_66;
F_35 () ;
break;
}
F_48 ( V_58 , V_65 ) ;
F_38 ( F_50 ( V_72 , V_63 )
!= V_73 ) ;
F_51 ( V_58 ) ;
break;
}
if ( V_58 == F_43 () )
F_19 ( V_67 L_12
L_10 , V_63 ) ;
}
F_40 () ;
V_66:
return V_29 ;
}
static T_3 F_52 ( const char * V_68 , T_4 V_69 )
{
struct V_12 * V_14 ;
T_2 V_21 ;
int V_29 ;
V_14 = F_21 ( V_68 ) ;
if ( ! V_14 )
return - V_64 ;
V_29 = F_53 ( V_14 , L_13 , & V_21 ) ;
if ( V_29 ) {
F_26 ( V_14 ) ;
return - V_64 ;
}
V_29 = F_47 ( V_14 ) ;
if ( V_29 ) {
F_26 ( V_14 ) ;
return - V_64 ;
}
V_29 = F_32 ( V_21 ) ;
if ( V_29 ) {
F_26 ( V_14 ) ;
return V_29 ;
}
V_29 = F_27 ( V_14 ) ;
if ( V_29 ) {
F_30 ( V_21 ) ;
return V_29 ;
}
F_26 ( V_14 ) ;
return V_69 ;
}
static int T_5 F_54 ( void )
{
V_74 . V_75 = F_44 ;
V_74 . V_76 = F_52 ;
return 0 ;
}

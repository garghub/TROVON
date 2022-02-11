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
V_13 = F_7 ( V_6 ) ;
if ( ! V_13 )
goto V_32;
V_13 -> V_33 = V_21 -> V_33 ;
V_21 -> V_18 = V_13 ;
V_21 = V_13 ;
break;
case V_34 :
V_13 = F_7 ( V_6 ) ;
if ( ! V_13 )
goto V_32;
if ( ! V_20 )
V_20 = V_13 ;
else {
V_13 -> V_33 = V_21 ;
if ( V_21 )
V_21 -> V_17 = V_13 ;
}
V_21 = V_13 ;
break;
case V_35 :
V_1 = F_3 ( V_6 ) ;
if ( ! V_1 )
goto V_32;
if ( ! V_21 -> V_15 )
V_21 -> V_15 = V_1 ;
else
V_22 -> V_16 = V_1 ;
V_22 = V_1 ;
break;
case V_36 :
V_21 = V_21 -> V_33 ;
break;
case V_37 :
break;
case V_38 :
case V_39 :
default:
F_16 ( V_40 L_3
L_4 , V_25 ) ;
goto V_32;
}
} while ( V_25 );
V_32:
F_2 ( V_23 ) ;
if ( V_25 ) {
if ( V_20 )
F_10 ( V_20 ) ;
return NULL ;
}
return V_20 ;
}
static struct V_12 * F_17 ( const char * V_41 )
{
struct V_12 * V_33 ;
char * V_42 ;
V_42 = strrchr ( V_41 , '/' ) ;
if ( V_42 == V_41 ) {
V_33 = F_18 ( L_5 ) ;
} else {
char * V_43 ;
int V_44 = V_42 - V_41 + 1 ;
V_43 = F_19 ( V_44 , V_7 ) ;
if ( ! V_43 )
return NULL ;
F_20 ( V_43 , V_41 , V_44 ) ;
V_33 = F_18 ( V_43 ) ;
F_2 ( V_43 ) ;
}
return V_33 ;
}
int F_21 ( struct V_12 * V_13 )
{
#ifdef F_22
struct V_45 * V_46 ;
#endif
int V_25 ;
F_23 ( V_13 , V_47 ) ;
F_24 ( & V_13 -> V_48 ) ;
V_13 -> V_33 = F_17 ( V_13 -> V_14 ) ;
if ( ! V_13 -> V_33 )
return - V_49 ;
V_25 = F_25 ( V_50 , V_13 ) ;
if ( V_25 ) {
F_16 ( V_40 L_6 ,
V_13 -> V_14 ) ;
return V_25 ;
}
F_26 ( V_13 ) ;
#ifdef F_22
V_46 = F_27 ( strrchr ( V_13 -> V_14 , '/' ) + 1 , V_13 -> V_33 -> V_51 ) ;
if ( V_46 )
F_28 ( V_13 , V_46 ) ;
#endif
F_29 ( V_13 -> V_33 ) ;
return 0 ;
}
int F_30 ( struct V_12 * V_13 )
{
#ifdef F_22
struct V_12 * V_33 = V_13 -> V_33 ;
struct V_1 * V_2 = V_13 -> V_15 ;
while ( V_2 ) {
F_31 ( V_2 -> V_3 , V_13 -> V_51 ) ;
V_2 = V_2 -> V_16 ;
}
if ( V_13 -> V_51 )
F_31 ( V_13 -> V_51 -> V_3 , V_33 -> V_51 ) ;
#endif
F_25 ( V_52 , V_13 ) ;
F_32 ( V_13 ) ;
F_29 ( V_13 ) ;
return 0 ;
}
int F_33 ( T_1 V_19 )
{
int V_53 , V_25 ;
V_25 = F_14 ( F_12 ( L_7 ) , 2 , 2 , & V_53 ,
V_54 , V_19 ) ;
if ( V_25 || V_53 != V_55 )
return - 1 ;
V_25 = F_34 ( V_56 , V_19 , V_57 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_34 ( V_58 , V_19 , V_59 ) ;
if ( V_25 ) {
F_34 ( V_56 , V_19 , V_60 ) ;
return V_25 ;
}
return 0 ;
}
int F_35 ( T_1 V_19 )
{
int V_53 , V_25 ;
V_25 = F_14 ( F_12 ( L_7 ) , 2 , 2 , & V_53 ,
V_54 , V_19 ) ;
if ( V_25 || V_53 != V_61 )
return - 1 ;
V_25 = F_34 ( V_58 , V_19 , V_62 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_34 ( V_56 , V_19 , V_60 ) ;
if ( V_25 ) {
F_34 ( V_58 , V_19 , V_59 ) ;
return V_25 ;
}
return 0 ;
}
static int F_36 ( struct V_12 * V_13 )
{
int V_25 = 0 ;
unsigned int V_63 ;
int V_64 , V_65 , V_66 ;
const T_1 * V_67 ;
V_67 = F_37 ( V_13 , L_8 , & V_64 ) ;
if ( ! V_67 )
return - V_68 ;
V_65 = V_64 / sizeof( T_1 ) ;
F_38 () ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
F_39 (cpu) {
if ( F_40 ( V_63 ) != V_67 [ V_66 ] )
continue;
F_41 ( F_42 ( V_63 )
!= V_69 ) ;
F_43 () ;
V_25 = F_44 ( V_63 ) ;
if ( V_25 )
goto V_70;
F_38 () ;
break;
}
if ( V_63 == F_45 () )
F_16 ( V_71 L_9
L_10 , V_67 [ V_66 ] ) ;
}
F_43 () ;
V_70:
return V_25 ;
}
static T_2 F_46 ( const char * V_72 , T_3 V_73 )
{
struct V_12 * V_13 ;
unsigned long V_19 ;
char * V_74 ;
int V_25 ;
F_47 () ;
V_25 = F_48 ( V_72 , 0 , & V_19 ) ;
if ( V_25 ) {
V_25 = - V_68 ;
goto V_70;
}
V_13 = F_11 ( V_19 ) ;
if ( ! V_13 ) {
V_25 = - V_68 ;
goto V_70;
}
V_74 = F_8 ( V_7 , L_11 , V_13 -> V_14 ) ;
if ( ! V_74 ) {
F_10 ( V_13 ) ;
V_25 = - V_49 ;
goto V_70;
}
F_2 ( V_13 -> V_14 ) ;
V_13 -> V_14 = V_74 ;
V_25 = F_33 ( V_19 ) ;
if ( V_25 ) {
F_10 ( V_13 ) ;
V_25 = - V_68 ;
goto V_70;
}
V_25 = F_21 ( V_13 ) ;
if ( V_25 ) {
F_35 ( V_19 ) ;
F_10 ( V_13 ) ;
goto V_70;
}
V_25 = F_36 ( V_13 ) ;
V_70:
F_49 () ;
return V_25 ? V_25 : V_73 ;
}
static int F_50 ( struct V_12 * V_13 )
{
int V_25 = 0 ;
unsigned int V_63 ;
int V_64 , V_65 , V_66 ;
const T_1 * V_67 ;
V_67 = F_37 ( V_13 , L_8 , & V_64 ) ;
if ( ! V_67 )
return - V_68 ;
V_65 = V_64 / sizeof( T_1 ) ;
F_38 () ;
for ( V_66 = 0 ; V_66 < V_65 ; V_66 ++ ) {
F_39 (cpu) {
if ( F_40 ( V_63 ) != V_67 [ V_66 ] )
continue;
if ( F_42 ( V_63 ) == V_69 )
break;
if ( F_42 ( V_63 ) == V_75 ) {
F_51 ( V_63 , V_69 ) ;
F_43 () ;
V_25 = F_52 ( V_63 ) ;
if ( V_25 )
goto V_70;
F_38 () ;
break;
}
F_51 ( V_63 , V_69 ) ;
F_41 ( F_53 ( V_76 , V_67 [ V_66 ] )
!= V_77 ) ;
F_54 ( V_63 ) ;
break;
}
if ( V_63 == F_45 () )
F_16 ( V_71 L_12
L_10 , V_67 [ V_66 ] ) ;
}
F_43 () ;
V_70:
return V_25 ;
}
static T_2 F_55 ( const char * V_72 , T_3 V_73 )
{
struct V_12 * V_13 ;
const T_1 * V_19 ;
int V_25 ;
V_13 = F_18 ( V_72 ) ;
if ( ! V_13 )
return - V_68 ;
V_19 = F_37 ( V_13 , L_13 , NULL ) ;
if ( ! V_19 ) {
F_29 ( V_13 ) ;
return - V_68 ;
}
F_47 () ;
V_25 = F_50 ( V_13 ) ;
if ( V_25 ) {
F_29 ( V_13 ) ;
V_25 = - V_68 ;
goto V_70;
}
V_25 = F_35 ( * V_19 ) ;
if ( V_25 ) {
F_29 ( V_13 ) ;
goto V_70;
}
V_25 = F_30 ( V_13 ) ;
if ( V_25 ) {
F_33 ( * V_19 ) ;
goto V_70;
}
F_29 ( V_13 ) ;
V_70:
F_49 () ;
return V_25 ? V_25 : V_73 ;
}
static int T_4 F_56 ( void )
{
V_78 . V_79 = F_46 ;
V_78 . V_80 = F_55 ;
return 0 ;
}

void F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 , * V_4 , * V_5 ;
F_2 ( & V_6 ) ;
V_5 = V_7 ;
while ( V_5 != NULL ) {
V_3 = V_5 ;
V_5 = V_5 -> V_8 ;
if ( V_3 -> V_2 == V_2 ) {
if ( V_7 == V_3 ) {
V_7 = V_3 -> V_8 ;
F_3 ( V_3 -> V_9 ) ;
F_3 ( V_3 ) ;
} else {
for ( V_4 = V_7 ; V_4 != NULL ; V_4 = V_4 -> V_8 ) {
if ( V_4 -> V_8 == V_3 ) {
V_4 -> V_8 = V_3 -> V_8 ;
F_3 ( V_3 -> V_9 ) ;
F_3 ( V_3 ) ;
break;
}
}
}
}
}
F_4 ( & V_6 ) ;
}
static int T_2 F_5 ( struct V_10 * V_11 )
{
T_1 * V_5 ;
T_3 * T_3 ;
int V_12 ;
if ( ( T_3 = F_6 ( & V_11 -> V_13 ) ) == NULL )
return - V_14 ;
if ( V_11 -> V_15 > V_16 )
return - V_14 ;
F_2 ( & V_6 ) ;
V_5 = V_7 ;
while ( V_5 != NULL ) {
if ( F_7 ( & V_5 -> V_17 , & V_11 -> V_18 ) == 0 &&
V_5 -> V_2 == T_3 -> V_2 ) {
F_3 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
if ( V_11 -> V_15 != 0 ) {
if ( ( V_5 -> V_9 = F_8 ( sizeof( V_19 ) , V_20 ) ) == NULL ) {
F_4 ( & V_6 ) ;
return - V_21 ;
}
V_5 -> V_9 -> V_22 = - 1 ;
V_5 -> V_9 -> V_23 = V_11 -> V_15 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_15 ; V_12 ++ ) {
V_5 -> V_9 -> V_24 [ V_12 ] = 0 ;
V_5 -> V_9 -> V_25 [ V_12 ] = V_11 -> V_26 [ V_12 ] ;
}
}
F_4 ( & V_6 ) ;
return 0 ;
}
V_5 = V_5 -> V_8 ;
}
if ( ( V_5 = F_8 ( sizeof( T_1 ) , V_20 ) ) == NULL ) {
F_4 ( & V_6 ) ;
return - V_21 ;
}
F_9 ( & V_5 -> V_27 , 1 ) ;
V_5 -> V_17 = V_11 -> V_18 ;
V_5 -> V_2 = T_3 -> V_2 ;
V_5 -> V_9 = NULL ;
V_5 -> V_28 = ' ' ;
if ( V_11 -> V_15 != 0 ) {
if ( ( V_5 -> V_9 = F_8 ( sizeof( V_19 ) , V_20 ) ) == NULL ) {
F_4 ( & V_6 ) ;
F_3 ( V_5 ) ;
return - V_21 ;
}
V_5 -> V_9 -> V_22 = - 1 ;
V_5 -> V_9 -> V_23 = V_11 -> V_15 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_15 ; V_12 ++ ) {
V_5 -> V_9 -> V_24 [ V_12 ] = 0 ;
V_5 -> V_9 -> V_25 [ V_12 ] = V_11 -> V_26 [ V_12 ] ;
}
}
V_5 -> V_8 = V_7 ;
V_7 = V_5 ;
F_4 ( & V_6 ) ;
return 0 ;
}
void F_10 ( T_1 * V_5 )
{
F_3 ( V_5 -> V_9 ) ;
F_3 ( V_5 ) ;
}
static int F_11 ( struct V_10 * V_11 )
{
T_1 * V_3 , * V_4 , * V_5 ;
T_3 * T_3 ;
if ( ( T_3 = F_6 ( & V_11 -> V_13 ) ) == NULL )
return - V_14 ;
F_2 ( & V_6 ) ;
V_5 = V_7 ;
while ( V_5 != NULL ) {
V_3 = V_5 ;
V_5 = V_5 -> V_8 ;
if ( V_3 -> V_2 == T_3 -> V_2 &&
F_7 ( & V_11 -> V_18 , & V_3 -> V_17 ) == 0 ) {
if ( V_7 == V_3 ) {
V_7 = V_3 -> V_8 ;
F_12 ( V_3 ) ;
} else {
for ( V_4 = V_7 ; V_4 != NULL ; V_4 = V_4 -> V_8 ) {
if ( V_4 -> V_8 == V_3 ) {
V_4 -> V_8 = V_3 -> V_8 ;
F_12 ( V_3 ) ;
break;
}
}
}
}
}
F_4 ( & V_6 ) ;
return 0 ;
}
static int F_13 ( struct V_29 * V_30 )
{
T_1 * V_5 ;
T_3 * T_3 ;
int V_31 = 0 ;
if ( ( T_3 = F_6 ( & V_30 -> V_13 ) ) == NULL )
return - V_14 ;
F_2 ( & V_6 ) ;
V_5 = V_7 ;
while ( V_5 != NULL ) {
if ( V_5 -> V_2 == T_3 -> V_2 &&
F_7 ( & V_30 -> V_18 , & V_5 -> V_17 ) == 0 ) {
switch ( V_30 -> V_32 ) {
case V_33 :
switch ( V_30 -> V_34 ) {
case ' ' :
case 'D' :
case 'V' :
V_5 -> V_28 = V_30 -> V_34 ;
break;
default:
V_31 = - V_14 ;
goto V_35;
}
break;
default:
V_31 = - V_14 ;
goto V_35;
}
}
V_5 = V_5 -> V_8 ;
}
V_35:
F_4 ( & V_6 ) ;
return V_31 ;
}
int F_14 ( unsigned int V_32 , void T_4 * V_34 )
{
struct V_29 V_30 ;
struct V_10 V_11 ;
switch ( V_32 ) {
case V_36 :
if ( F_15 ( & V_11 , V_34 , sizeof( V_11 ) ) )
return - V_37 ;
return F_5 ( & V_11 ) ;
case V_38 :
if ( F_15 ( & V_11 , V_34 , sizeof( V_11 ) ) )
return - V_37 ;
return F_11 ( & V_11 ) ;
case V_39 :
if ( F_15 ( & V_30 , V_34 , sizeof( V_30 ) ) )
return - V_37 ;
return F_13 ( & V_30 ) ;
default:
return - V_14 ;
}
}
static void * F_16 ( struct V_40 * V_41 , T_5 * V_42 )
__acquires( V_6 )
{
struct T_1 * V_5 ;
int V_12 = 1 ;
F_17 ( & V_6 ) ;
if ( * V_42 == 0 )
return V_43 ;
for ( V_5 = V_7 ; V_5 != NULL ; V_5 = V_5 -> V_8 ) {
if ( V_12 == * V_42 )
return V_5 ;
++ V_12 ;
}
return NULL ;
}
static void * F_18 ( struct V_40 * V_41 , void * V_44 , T_5 * V_42 )
{
++ * V_42 ;
return ( V_44 == V_43 ) ? V_7 :
( (struct T_1 * ) V_44 ) -> V_8 ;
}
static void F_19 ( struct V_40 * V_41 , void * V_44 )
__releases( V_6 )
{
F_20 ( & V_6 ) ;
}
static int F_21 ( struct V_40 * V_41 , void * V_44 )
{
char V_45 [ 11 ] ;
if ( V_44 == V_43 )
F_22 ( V_41 , L_1 ) ;
else {
struct T_1 * V_5 = V_44 ;
const char * V_17 ;
int V_12 ;
if ( F_7 ( & V_5 -> V_17 , & V_46 ) == 0 )
V_17 = L_2 ;
else
V_17 = F_23 ( V_45 , & V_5 -> V_17 ) ;
F_24 ( V_41 , L_3 ,
V_17 ,
V_5 -> V_2 ? V_5 -> V_2 -> V_47 : L_4 ) ;
switch ( V_5 -> V_28 ) {
case 'V' :
F_22 ( V_41 , L_5 ) ;
break;
case 'D' :
F_22 ( V_41 , L_6 ) ;
break;
default:
F_22 ( V_41 , L_7 ) ;
break;
}
if ( V_5 -> V_9 != NULL )
for ( V_12 = 0 ; V_12 < V_5 -> V_9 -> V_23 ; V_12 ++ )
F_24 ( V_41 , L_8 ,
F_23 ( V_45 , & V_5 -> V_9 -> V_25 [ V_12 ] ) ) ;
F_22 ( V_41 , L_9 ) ;
}
return 0 ;
}
static int F_25 ( struct V_48 * V_48 , struct V_49 * V_49 )
{
return F_26 ( V_49 , & V_50 ) ;
}
T_1 * F_27 ( T_6 * V_51 , struct V_1 * V_2 )
{
T_1 * V_52 = NULL ;
T_1 * V_53 = NULL ;
T_1 * V_5 ;
F_17 ( & V_6 ) ;
for ( V_5 = V_7 ; V_5 != NULL ; V_5 = V_5 -> V_8 ) {
if ( V_2 == NULL ) {
if ( F_7 ( & V_5 -> V_17 , V_51 ) == 0 && V_5 -> V_2 != NULL )
V_52 = V_5 ;
if ( F_7 ( & V_5 -> V_17 , & V_46 ) == 0 && V_5 -> V_2 != NULL )
V_53 = V_5 ;
} else {
if ( F_7 ( & V_5 -> V_17 , V_51 ) == 0 && V_5 -> V_2 == V_2 )
V_52 = V_5 ;
if ( F_7 ( & V_5 -> V_17 , & V_46 ) == 0 && V_5 -> V_2 == V_2 )
V_53 = V_5 ;
}
}
V_5 = V_53 ;
if ( V_52 != NULL )
V_5 = V_52 ;
if ( V_5 != NULL )
F_28 ( V_5 ) ;
F_20 ( & V_6 ) ;
return V_5 ;
}
static inline void F_29 ( T_6 * V_51 , V_19 * V_9 )
{
int V_54 ;
for ( V_54 = 0 ; V_54 < V_9 -> V_23 ; V_54 ++ ) {
if ( F_7 ( V_51 , & V_9 -> V_25 [ V_54 ] ) == 0 )
break;
}
V_9 -> V_23 = V_54 ;
}
int F_30 ( T_7 * V_55 , T_6 * V_51 )
{
T_8 * V_56 ;
T_1 * V_5 ;
int V_31 = 0 ;
if ( ( V_5 = F_27 ( V_51 , NULL ) ) == NULL )
return - V_57 ;
if ( ( V_55 -> T_3 = F_31 ( V_5 -> V_2 ) ) == NULL ) {
V_31 = - V_57 ;
goto V_58;
}
V_56 = F_32 ( F_33 () ) ;
if ( V_56 ) {
V_55 -> V_59 = V_56 -> V_60 ;
F_34 ( V_56 ) ;
} else {
if ( V_61 && ! F_35 ( V_62 ) ) {
V_31 = - V_63 ;
goto V_58;
}
V_55 -> V_59 = * ( T_6 * ) V_55 -> T_3 -> V_2 -> V_64 ;
}
if ( V_5 -> V_9 != NULL ) {
V_55 -> V_9 = F_36 ( V_5 -> V_9 , sizeof( V_19 ) ,
V_20 ) ;
if ( V_55 -> V_9 == NULL ) {
V_31 = - V_21 ;
goto V_58;
}
F_29 ( V_51 , V_55 -> V_9 ) ;
}
if ( V_55 -> V_65 != NULL ) {
F_37 ( V_55 -> V_65 ) ;
F_38 ( V_55 -> V_65 , V_66 ) ;
F_39 ( V_55 -> V_65 ) ;
}
V_58:
F_12 ( V_5 ) ;
return V_31 ;
}
struct V_67 * F_40 ( struct V_67 * V_68 , T_6 * V_69 ,
T_6 * V_70 , V_19 * V_71 )
{
struct V_67 * V_72 ;
unsigned char * V_73 ;
int V_74 ;
V_74 = V_71 -> V_23 * V_75 ;
if ( F_41 ( V_68 ) < V_74 ) {
if ( ( V_72 = F_42 ( V_68 , V_74 ) ) == NULL ) {
F_43 ( V_76 L_10 ) ;
return NULL ;
}
if ( V_68 -> V_65 != NULL )
F_44 ( V_72 , V_68 -> V_65 ) ;
F_45 ( V_68 ) ;
V_68 = V_72 ;
}
V_73 = F_46 ( V_68 , V_74 ) ;
F_47 ( V_73 , V_69 , V_70 , V_71 , V_77 , V_78 ) ;
return V_68 ;
}
void T_9 F_48 ( void )
{
T_1 * V_3 , * V_5 = V_7 ;
F_2 ( & V_6 ) ;
while ( V_5 != NULL ) {
V_3 = V_5 ;
V_5 = V_5 -> V_8 ;
F_3 ( V_3 -> V_9 ) ;
F_3 ( V_3 ) ;
}
F_4 ( & V_6 ) ;
}

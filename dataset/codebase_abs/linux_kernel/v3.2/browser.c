static int F_1 ( struct V_1 * V_2 ,
double V_3 , bool V_4 )
{
if ( V_4 && ( ! V_2 -> V_5 || V_2 -> V_6 ) )
return V_7 ;
if ( V_3 >= V_8 )
return V_9 ;
if ( V_3 >= V_10 )
return V_11 ;
return V_12 ;
}
void F_2 ( struct V_1 * T_1 V_13 , int V_14 )
{
F_3 ( V_14 ) ;
}
void F_4 ( struct V_1 * T_1 ,
double V_3 , bool V_4 )
{
int V_14 = F_1 ( T_1 , V_3 , V_4 ) ;
F_2 ( T_1 , V_14 ) ;
}
void F_5 ( struct V_1 * T_1 , int V_15 , int V_16 )
{
F_6 ( T_1 -> V_15 + V_15 , T_1 -> V_16 + V_16 ) ;
}
static struct V_17 *
F_7 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
do {
if ( ! V_2 -> V_19 || ! V_2 -> V_19 ( V_2 , V_18 ) )
return V_18 ;
V_18 = V_18 -> V_20 ;
} while ( V_18 != V_2 -> V_21 );
return NULL ;
}
static struct V_17 *
F_8 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
do {
if ( ! V_2 -> V_19 || ! V_2 -> V_19 ( V_2 , V_18 ) )
return V_18 ;
V_18 = V_18 -> V_22 ;
} while ( V_18 != V_2 -> V_21 );
return NULL ;
}
void F_9 ( struct V_1 * T_1 , T_2 V_23 , int V_24 )
{
struct V_17 * V_25 = T_1 -> V_21 ;
struct V_17 * V_18 ;
if ( T_1 -> V_26 == 0 )
return;
switch ( V_24 ) {
case V_27 :
V_18 = F_7 ( T_1 , V_25 -> V_20 ) ;
break;
case V_28 :
V_18 = T_1 -> V_29 ;
break;
case V_30 :
V_18 = F_8 ( T_1 , V_25 -> V_22 ) ;
break;
default:
return;
}
assert ( V_18 != NULL ) ;
if ( V_23 > 0 ) {
while ( V_23 -- != 0 )
V_18 = F_7 ( T_1 , V_18 -> V_20 ) ;
} else {
while ( V_23 ++ != 0 )
V_18 = F_8 ( T_1 , V_18 -> V_22 ) ;
}
T_1 -> V_29 = V_18 ;
}
void F_10 ( struct V_1 * T_1 , T_2 V_23 , int V_24 )
{
struct V_31 * V_32 = T_1 -> V_21 ;
struct V_33 * V_34 ;
switch ( V_24 ) {
case V_27 :
V_34 = F_11 ( V_32 ) ;
break;
case V_28 :
V_34 = T_1 -> V_29 ;
break;
case V_30 :
V_34 = F_12 ( V_32 ) ;
break;
default:
return;
}
if ( V_23 > 0 ) {
while ( V_23 -- != 0 )
V_34 = F_13 ( V_34 ) ;
} else {
while ( V_23 ++ != 0 )
V_34 = F_14 ( V_34 ) ;
}
T_1 -> V_29 = V_34 ;
}
unsigned int F_15 ( struct V_1 * T_1 )
{
struct V_33 * V_34 ;
int V_35 = 0 ;
if ( T_1 -> V_29 == NULL )
T_1 -> V_29 = F_11 ( T_1 -> V_21 ) ;
V_34 = T_1 -> V_29 ;
while ( V_34 != NULL ) {
F_5 ( T_1 , V_35 , 0 ) ;
T_1 -> V_36 ( T_1 , V_34 , V_35 ) ;
if ( ++ V_35 == T_1 -> V_37 )
break;
V_34 = F_13 ( V_34 ) ;
}
return V_35 ;
}
bool F_16 ( struct V_1 * T_1 , unsigned V_35 )
{
return T_1 -> V_38 + V_35 == T_1 -> V_39 ;
}
void F_17 ( struct V_1 * T_1 )
{
T_1 -> V_40 = V_41 - 1 ;
T_1 -> V_37 = V_42 - 2 ;
T_1 -> V_15 = 1 ;
T_1 -> V_16 = 0 ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( false ) ;
F_20 ( V_2 , V_2 -> V_43 , V_44 ) ;
F_21 ( V_2 ) ;
}
int F_22 ( struct V_1 * V_2 , int V_45 ,
const char * V_46 , ... )
{
T_3 args ;
char * V_47 ;
int V_48 = 0 , V_49 ;
va_start ( args , V_46 ) ;
V_49 = F_23 ( & V_47 , V_46 , args ) ;
va_end ( args ) ;
if ( V_49 < 0 ) {
va_start ( args , V_46 ) ;
F_24 ( V_46 , args ) ;
va_end ( args ) ;
} else {
while ( ( V_48 == F_25 ( L_1 , V_47 ,
L_2 ,
V_45 ) ) == V_50 )
F_18 ( V_2 ) ;
free ( V_47 ) ;
}
return V_48 ;
}
int F_26 ( struct V_1 * V_2 , const char * V_47 )
{
int V_48 ;
while ( ( V_48 = F_27 ( V_47 ) ) == V_50 )
F_18 ( V_2 ) ;
return V_48 ;
}
bool F_28 ( struct V_1 * V_2 , const char * V_47 )
{
int V_48 ;
while ( ( V_48 = F_29 ( V_47 ) ) == V_50 )
F_18 ( V_2 ) ;
return V_48 == V_51 || toupper ( V_48 ) == 'Y' ;
}
void F_30 ( struct V_1 * T_1 )
{
T_1 -> V_39 = T_1 -> V_38 = 0 ;
T_1 -> V_52 ( T_1 , 0 , V_27 ) ;
}
void F_31 ( struct V_1 * V_2 , const char * V_43 )
{
F_6 ( 0 , 0 ) ;
F_2 ( V_2 , V_53 ) ;
F_32 ( V_43 , V_2 -> V_40 + 1 ) ;
}
void F_33 ( struct V_1 * V_2 , const char * V_43 )
{
F_34 ( & V_54 ) ;
F_31 ( V_2 , V_43 ) ;
F_35 ( & V_54 ) ;
}
int F_20 ( struct V_1 * T_1 , const char * V_43 ,
const char * V_55 , ... )
{
int V_49 ;
T_3 V_56 ;
F_17 ( T_1 ) ;
F_34 ( & V_54 ) ;
F_31 ( T_1 , V_43 ) ;
T_1 -> V_43 = V_43 ;
free ( T_1 -> V_55 ) ;
T_1 -> V_55 = NULL ;
va_start ( V_56 , V_55 ) ;
V_49 = F_23 ( & T_1 -> V_55 , V_55 , V_56 ) ;
va_end ( V_56 ) ;
if ( V_49 > 0 )
F_36 ( T_1 -> V_55 ) ;
F_35 ( & V_54 ) ;
return V_49 ? 0 : - 1 ;
}
void F_37 ( struct V_1 * V_2 V_13 )
{
F_34 ( & V_54 ) ;
F_38 () ;
F_35 ( & V_54 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
int V_37 = V_2 -> V_37 , V_57 = 0 , V_58 = 0 ,
V_59 = V_2 -> V_40 ,
V_35 = V_2 -> V_15 - 1 ;
if ( V_2 -> V_26 > 1 ) {
V_58 = ( ( V_2 -> V_39 * ( V_2 -> V_37 - 1 ) ) /
( V_2 -> V_26 - 1 ) ) ;
}
F_40 ( 1 ) ;
while ( V_57 < V_37 ) {
F_5 ( V_2 , V_35 ++ , V_59 ) ;
F_41 ( V_57 == V_58 ? V_60 : V_61 ) ;
++ V_57 ;
}
F_40 ( 0 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_35 ;
int V_40 = V_2 -> V_40 ;
V_35 = V_2 -> V_62 ( V_2 ) ;
F_2 ( V_2 , V_12 ) ;
if ( ! V_2 -> V_5 || V_2 -> V_6 )
F_39 ( V_2 ) ;
else
V_40 += 1 ;
F_43 ( V_2 -> V_15 + V_35 , V_2 -> V_16 ,
V_2 -> V_37 - V_35 , V_40 , ' ' ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 )
{
F_34 ( & V_54 ) ;
F_42 ( V_2 ) ;
F_35 ( & V_54 ) ;
return 0 ;
}
void F_44 ( struct V_1 * V_2 , T_4 V_26 )
{
T_2 V_23 = V_26 - V_2 -> V_26 ;
V_2 -> V_26 = V_26 ;
if ( V_23 < 0 ) {
if ( V_2 -> V_38 < ( V_63 ) - V_23 )
V_23 = - V_2 -> V_38 ;
V_2 -> V_39 += V_23 ;
V_2 -> V_38 += V_23 ;
}
V_2 -> V_29 = NULL ;
V_2 -> V_52 ( V_2 , V_2 -> V_38 , V_27 ) ;
}
int F_45 ( struct V_1 * T_1 , int V_64 )
{
int V_49 , V_48 ;
while ( 1 ) {
T_2 V_23 ;
F_34 ( & V_54 ) ;
V_49 = F_42 ( T_1 ) ;
F_46 () ;
F_35 ( & V_54 ) ;
if ( V_49 < 0 )
break;
V_48 = F_47 ( V_64 ) ;
if ( V_48 == V_50 ) {
F_19 ( false ) ;
F_17 ( T_1 ) ;
F_31 ( T_1 , T_1 -> V_43 ) ;
F_48 ( T_1 -> V_55 ) ;
continue;
}
if ( T_1 -> V_5 && ! T_1 -> V_6 ) {
if ( V_48 == V_65 || V_48 == V_66 ||
V_48 == V_67 || V_48 == V_68 ||
V_48 == V_69 || V_48 == V_70 ||
V_48 == ' ' ) {
T_1 -> V_6 = true ;
continue;
} else
return V_48 ;
}
switch ( V_48 ) {
case V_65 :
if ( T_1 -> V_39 == T_1 -> V_26 - 1 )
break;
++ T_1 -> V_39 ;
if ( T_1 -> V_39 == T_1 -> V_38 + T_1 -> V_37 ) {
++ T_1 -> V_38 ;
T_1 -> V_52 ( T_1 , + 1 , V_28 ) ;
}
break;
case V_66 :
if ( T_1 -> V_39 == 0 )
break;
-- T_1 -> V_39 ;
if ( T_1 -> V_39 < T_1 -> V_38 ) {
-- T_1 -> V_38 ;
T_1 -> V_52 ( T_1 , - 1 , V_28 ) ;
}
break;
case V_67 :
case ' ' :
if ( T_1 -> V_38 + T_1 -> V_37 > T_1 -> V_26 - 1 )
break;
V_23 = T_1 -> V_37 ;
if ( T_1 -> V_39 + V_23 > T_1 -> V_26 - 1 )
V_23 = T_1 -> V_26 - 1 - T_1 -> V_39 ;
T_1 -> V_39 += V_23 ;
T_1 -> V_38 += V_23 ;
T_1 -> V_52 ( T_1 , + V_23 , V_28 ) ;
break;
case V_68 :
if ( T_1 -> V_38 == 0 )
break;
if ( T_1 -> V_38 < T_1 -> V_37 )
V_23 = T_1 -> V_38 ;
else
V_23 = T_1 -> V_37 ;
T_1 -> V_39 -= V_23 ;
T_1 -> V_38 -= V_23 ;
T_1 -> V_52 ( T_1 , - V_23 , V_28 ) ;
break;
case V_69 :
F_30 ( T_1 ) ;
break;
case V_70 :
V_23 = T_1 -> V_37 - 1 ;
if ( V_23 >= T_1 -> V_26 )
V_23 = T_1 -> V_26 - 1 ;
T_1 -> V_39 = T_1 -> V_26 - 1 ;
T_1 -> V_38 = T_1 -> V_39 - V_23 ;
T_1 -> V_52 ( T_1 , - V_23 , V_30 ) ;
break;
default:
return V_48 ;
}
}
return - 1 ;
}
unsigned int F_49 ( struct V_1 * T_1 )
{
struct V_17 * V_18 ;
struct V_17 * V_25 = T_1 -> V_21 ;
int V_35 = 0 ;
if ( T_1 -> V_29 == NULL || T_1 -> V_29 == T_1 -> V_21 )
T_1 -> V_29 = F_7 ( T_1 , V_25 -> V_20 ) ;
V_18 = T_1 -> V_29 ;
F_50 (pos, head) {
if ( ! T_1 -> V_19 || ! T_1 -> V_19 ( T_1 , V_18 ) ) {
F_5 ( T_1 , V_35 , 0 ) ;
T_1 -> V_36 ( T_1 , V_18 , V_35 ) ;
if ( ++ V_35 == T_1 -> V_37 )
break;
}
}
return V_35 ;
}
static int F_51 ( const char * V_71 , const char * V_72 ,
void * T_5 V_13 )
{
char * V_73 = NULL , * V_74 ;
int V_75 ;
if ( F_52 ( V_71 , L_3 ) != 0 )
return 0 ;
for ( V_75 = 0 ; V_76 [ V_75 ] . V_77 != NULL ; ++ V_75 ) {
const char * V_77 = V_71 + 7 ;
if ( strcmp ( V_76 [ V_75 ] . V_77 , V_77 ) != 0 )
continue;
V_73 = F_53 ( V_72 ) ;
if ( V_73 == NULL )
break;
V_74 = strchr ( V_73 , ',' ) ;
if ( V_74 == NULL )
break;
* V_74 = '\0' ;
while ( isspace ( * ++ V_74 ) ) ;
V_76 [ V_75 ] . V_74 = V_74 ;
V_76 [ V_75 ] . V_73 = V_73 ;
return 0 ;
}
free ( V_73 ) ;
return - 1 ;
}
void F_54 ( struct V_1 * V_2 , T_2 V_23 , int V_24 )
{
switch ( V_24 ) {
case V_27 :
V_2 -> V_29 = V_2 -> V_21 ;
break;
case V_28 :
V_2 -> V_29 = V_2 -> V_29 + V_2 -> V_38 + V_23 ;
break;
case V_30 :
V_2 -> V_29 = V_2 -> V_29 + V_2 -> V_26 + V_23 ;
break;
default:
return;
}
}
unsigned int F_55 ( struct V_1 * V_2 )
{
unsigned int V_35 = 0 , V_78 = V_2 -> V_38 ;
char * * V_18 ;
if ( V_2 -> V_29 == NULL )
V_2 -> V_29 = V_2 -> V_21 ;
V_18 = ( char * * ) V_2 -> V_29 ;
while ( V_78 < V_2 -> V_26 ) {
if ( ! V_2 -> V_19 || ! V_2 -> V_19 ( V_2 , * V_18 ) ) {
F_5 ( V_2 , V_35 , 0 ) ;
V_2 -> V_36 ( V_2 , V_18 , V_35 ) ;
if ( ++ V_35 == V_2 -> V_37 )
break;
}
++ V_78 ;
++ V_18 ;
}
return V_35 ;
}
void F_56 ( void )
{
int V_75 = 0 ;
F_57 ( F_51 , NULL ) ;
while ( V_76 [ V_75 ] . V_77 ) {
struct V_79 * V_80 = & V_76 [ V_75 ++ ] ;
F_58 ( V_80 -> V_81 , V_80 -> V_77 , V_80 -> V_73 , V_80 -> V_74 ) ;
}
}

static T_1 F_1 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
return - V_6 ;
}
static T_1 F_2 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_1 V_7 , V_8 = 0 ;
if ( V_2 && V_3 ) {
char T_2 * V_9 ;
T_4 V_10 = 0 ;
int V_11 ;
V_7 = F_3 ( V_1 , V_2 , V_3 , & V_10 ) ;
if ( V_7 < 0 )
goto V_12;
V_8 = V_7 ;
V_9 = V_2 + V_8 - 1 ;
V_7 = - V_13 ;
if ( F_4 ( V_11 , V_9 ) )
goto V_12;
if ( V_11 == '\n' ) {
V_7 = - V_13 ;
if ( F_5 ( '\0' , V_9 ) )
goto V_12;
V_8 -= 1 ;
}
}
if ( V_4 && V_5 ) {
T_4 V_10 = 0 ;
V_7 = F_6 ( V_1 , V_4 , V_5 , & V_10 ) ;
if ( V_7 < 0 )
goto V_12;
}
V_7 = V_8 ;
V_12:
return V_7 ;
}
static T_1 F_7 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_1 V_8 = 0 ;
char * V_14 ;
T_1 V_7 ;
V_7 = - V_15 ;
V_14 = F_8 ( V_16 , V_17 ) ;
if ( ! V_14 )
goto V_12;
if ( V_2 && V_3 ) {
unsigned T_2 * V_18 = V_2 ;
T_3 V_19 = V_3 / sizeof( * V_18 ) ;
char * V_20 , * V_21 ;
int V_22 ;
V_7 = F_9 ( V_1 , 0 , V_14 , V_16 - 1 ) ;
if ( V_7 < 0 )
goto V_23;
V_20 = V_14 ;
V_21 = V_20 + V_7 ;
* V_21 ++ = '\0' ;
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ ) {
unsigned long V_24 ;
V_24 = F_10 ( V_20 , & V_20 , 10 ) ;
while ( isspace ( * V_20 ) )
V_20 ++ ;
V_7 = - V_13 ;
if ( F_5 ( V_24 , V_18 + V_22 ) )
goto V_23;
V_8 += sizeof( * V_18 ) ;
if ( ! isdigit ( * V_20 ) )
break;
}
}
if ( V_4 && V_5 ) {
unsigned T_2 * V_18 = V_4 ;
T_3 V_19 = V_5 / sizeof( * V_18 ) ;
char * V_20 , * V_21 ;
int V_22 ;
V_20 = V_14 ;
V_21 = V_20 + V_16 ;
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ ) {
unsigned long V_24 ;
V_7 = - V_13 ;
if ( F_4 ( V_24 , V_18 + V_22 ) )
goto V_23;
V_20 += snprintf ( V_20 , V_21 - V_20 , L_1 , V_24 ) ;
}
V_7 = F_11 ( V_1 , V_14 , V_20 - V_14 , 0 ) ;
if ( V_7 < 0 )
goto V_23;
}
V_7 = V_8 ;
V_23:
F_12 ( V_14 ) ;
V_12:
return V_7 ;
}
static T_1 F_13 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_1 V_8 = 0 ;
char * V_14 ;
T_1 V_7 ;
V_7 = - V_15 ;
V_14 = F_8 ( V_16 , V_17 ) ;
if ( ! V_14 )
goto V_12;
if ( V_2 && V_3 ) {
unsigned long T_2 * V_18 = V_2 ;
T_3 V_19 = V_3 / sizeof( * V_18 ) ;
char * V_20 , * V_21 ;
int V_22 ;
V_7 = F_9 ( V_1 , 0 , V_14 , V_16 - 1 ) ;
if ( V_7 < 0 )
goto V_23;
V_20 = V_14 ;
V_21 = V_20 + V_7 ;
* V_21 ++ = '\0' ;
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ ) {
unsigned long V_24 ;
V_24 = F_10 ( V_20 , & V_20 , 10 ) ;
while ( isspace ( * V_20 ) )
V_20 ++ ;
V_7 = - V_13 ;
if ( F_5 ( V_24 , V_18 + V_22 ) )
goto V_23;
V_8 += sizeof( * V_18 ) ;
if ( ! isdigit ( * V_20 ) )
break;
}
}
if ( V_4 && V_5 ) {
unsigned long T_2 * V_18 = V_4 ;
T_3 V_19 = V_5 / sizeof( * V_18 ) ;
char * V_20 , * V_21 ;
int V_22 ;
V_20 = V_14 ;
V_21 = V_20 + V_16 ;
for ( V_22 = 0 ; V_22 < V_19 ; V_22 ++ ) {
unsigned long V_24 ;
V_7 = - V_13 ;
if ( F_4 ( V_24 , V_18 + V_22 ) )
goto V_23;
V_20 += snprintf ( V_20 , V_21 - V_20 , L_1 , V_24 ) ;
}
V_7 = F_11 ( V_1 , V_14 , V_20 - V_14 , 0 ) ;
if ( V_7 < 0 )
goto V_23;
}
V_7 = V_8 ;
V_23:
F_12 ( V_14 ) ;
V_12:
return V_7 ;
}
static T_1 F_14 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_1 V_7 , V_8 = 0 ;
if ( V_2 && V_3 ) {
char V_25 [ 40 ] , * V_20 = V_25 ;
unsigned char V_26 [ 16 ] ;
int V_22 ;
V_7 = F_9 ( V_1 , 0 , V_25 , sizeof( V_25 ) - 1 ) ;
if ( V_7 < 0 )
goto V_12;
V_25 [ V_7 ] = '\0' ;
for ( V_22 = 0 ; V_22 < 16 ; V_22 ++ ) {
V_7 = - V_27 ;
if ( ! isxdigit ( V_20 [ 0 ] ) || ! isxdigit ( V_20 [ 1 ] ) )
goto V_12;
V_26 [ V_22 ] = ( F_15 ( V_20 [ 0 ] ) << 4 ) |
F_15 ( V_20 [ 1 ] ) ;
V_20 += 2 ;
if ( * V_20 == '-' )
V_20 ++ ;
}
if ( V_3 > 16 )
V_3 = 16 ;
V_7 = - V_13 ;
if ( F_16 ( V_2 , V_26 , V_3 ) )
goto V_12;
V_8 = V_3 ;
}
V_7 = V_8 ;
V_12:
return V_7 ;
}
static T_1 F_17 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_1 V_7 , V_8 = 0 ;
if ( V_2 && V_3 ) {
char V_25 [ 15 ] , * V_28 ;
unsigned long V_29 , V_30 ;
T_5 V_31 ;
V_7 = F_9 ( V_1 , 0 , V_25 , sizeof( V_25 ) - 1 ) ;
if ( V_7 < 0 )
goto V_12;
V_25 [ V_7 ] = '\0' ;
V_7 = - V_27 ;
V_28 = strchr ( V_25 , '.' ) ;
if ( ! V_28 )
goto V_12;
++ V_28 ;
V_29 = F_10 ( V_25 , NULL , 10 ) ;
V_30 = F_10 ( V_28 , NULL , 10 ) ;
V_7 = - V_27 ;
if ( ( V_29 > 63 ) || ( V_30 > 1023 ) )
goto V_12;
V_31 = F_18 ( ( V_29 << 10 ) | V_30 ) ;
V_7 = - V_13 ;
if ( F_5 ( V_31 , ( T_5 T_2 * ) V_2 ) )
goto V_12;
V_8 = sizeof( V_31 ) ;
}
if ( V_4 && V_5 ) {
T_5 V_31 ;
char V_25 [ 15 ] ;
int V_32 ;
V_7 = - V_33 ;
if ( V_5 != sizeof( V_31 ) )
goto V_12;
V_7 = - V_13 ;
if ( F_4 ( V_31 , ( T_5 T_2 * ) V_4 ) )
goto V_12;
V_32 = snprintf ( V_25 , sizeof( V_25 ) , L_2 ,
F_19 ( V_31 ) >> 10 ,
F_19 ( V_31 ) & 0x3ff ) ;
V_7 = F_11 ( V_1 , V_25 , V_32 , 0 ) ;
if ( V_7 < 0 )
goto V_12;
}
V_7 = V_8 ;
V_12:
return V_7 ;
}
static const struct V_34 * F_20 ( const int * V_35 , int V_36 , char * V_37 )
{
const struct V_34 * V_38 = & V_39 [ 0 ] ;
int V_40 ;
memcpy ( V_37 , L_3 , 4 ) ;
V_37 += 4 ;
V_41:
if ( ! V_36 )
return F_21 ( - V_6 ) ;
V_40 = * V_35 ;
V_35 ++ ;
V_36 -- ;
for ( ; V_38 -> V_42 ; V_38 ++ ) {
int V_32 = 0 ;
if ( ! V_38 -> V_40 ) {
#ifdef F_22
struct V_43 * V_43 = V_44 -> V_45 -> V_46 ;
struct V_47 * V_48 ;
V_48 = F_23 ( V_43 , V_40 ) ;
if ( V_48 ) {
V_32 = strlen ( V_48 -> V_35 ) ;
memcpy ( V_37 , V_48 -> V_35 , V_32 ) ;
F_24 ( V_48 ) ;
}
#endif
} else if ( V_40 == V_38 -> V_40 ) {
V_32 = strlen ( V_38 -> V_49 ) ;
memcpy ( V_37 , V_38 -> V_49 , V_32 ) ;
}
if ( V_32 ) {
V_37 += V_32 ;
if ( V_38 -> V_50 ) {
* V_37 ++ = '/' ;
V_38 = V_38 -> V_50 ;
goto V_41;
}
* V_37 = '\0' ;
return V_38 ;
}
}
return F_21 ( - V_6 ) ;
}
static char * F_25 ( const int * V_35 , int V_36 , const struct V_34 * * V_51 )
{
char * V_52 , * V_7 ;
V_7 = F_21 ( - V_15 ) ;
V_52 = F_26 () ;
if ( V_52 ) {
const struct V_34 * V_38 = F_20 ( V_35 , V_36 , V_52 ) ;
V_7 = V_52 ;
* V_51 = V_38 ;
if ( F_27 ( V_38 ) ) {
F_28 ( V_52 ) ;
V_7 = F_29 ( V_38 ) ;
}
}
return V_7 ;
}
static T_1 F_30 ( const int * V_35 , int V_36 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
const struct V_34 * V_38 = NULL ;
struct V_53 * V_54 ;
struct V_1 * V_1 ;
T_1 V_7 ;
char * V_55 ;
int V_56 ;
V_55 = F_25 ( V_35 , V_36 , & V_38 ) ;
V_7 = F_31 ( V_55 ) ;
if ( F_27 ( V_55 ) )
goto V_12;
if ( V_2 && V_3 && V_4 && V_5 ) {
V_56 = V_57 ;
} else if ( V_4 && V_5 ) {
V_56 = V_58 ;
} else if ( V_2 && V_3 ) {
V_56 = V_59 ;
} else {
V_7 = 0 ;
goto V_60;
}
V_54 = F_32 ( V_44 ) -> V_61 ;
V_1 = F_33 ( V_54 -> V_62 , V_54 , V_55 , V_56 ) ;
V_7 = F_31 ( V_1 ) ;
if ( F_27 ( V_1 ) )
goto V_60;
V_7 = V_38 -> V_42 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_34 ( V_1 ) ;
V_60:
F_28 ( V_55 ) ;
V_12:
return V_7 ;
}
static T_1 F_30 ( const int * V_35 , int V_36 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
return - V_63 ;
}
static void F_35 ( const int * V_35 , int V_36 )
{
int V_22 ;
if ( V_35 [ 0 ] == V_64 && V_35 [ 1 ] == V_65 )
return;
if ( F_36 () ) {
F_37 ( V_66
L_4
L_5 , V_44 -> V_67 ) ;
for ( V_22 = 0 ; V_22 < V_36 ; V_22 ++ )
F_37 ( L_6 , V_35 [ V_22 ] ) ;
F_37 ( L_7 ) ;
}
return;
}
static void F_38 ( const int * V_35 , int V_36 )
{
int V_22 ;
T_6 V_68 = V_69 ;
for ( V_22 = 0 ; V_22 < V_36 ; V_22 ++ )
V_68 = ( V_68 ^ V_35 [ V_22 ] ) * V_70 ;
V_68 %= V_71 ;
if ( F_39 ( V_68 , V_72 ) )
return;
F_35 ( V_35 , V_36 ) ;
}
static T_1 F_40 ( int T_2 * V_73 , int V_36 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
int V_35 [ V_74 ] ;
int V_22 ;
if ( V_36 < 0 || V_36 > V_74 )
return - V_6 ;
for ( V_22 = 0 ; V_22 < V_36 ; V_22 ++ )
if ( F_4 ( V_35 [ V_22 ] , V_73 + V_22 ) )
return - V_13 ;
F_38 ( V_35 , V_36 ) ;
return F_30 ( V_35 , V_36 , V_2 , V_3 , V_4 , V_5 ) ;
}
T_7 long F_41 ( struct V_75 T_2 * args )
{
struct V_75 V_52 ;
T_8 T_2 * V_76 ;
T_3 V_3 = 0 ;
T_1 V_7 ;
if ( F_42 ( & V_52 , args , sizeof( V_52 ) ) )
return - V_13 ;
if ( V_52 . V_2 && ! V_52 . V_77 )
return - V_13 ;
V_76 = F_43 ( V_52 . V_77 ) ;
if ( V_76 && F_4 ( V_3 , V_76 ) )
return - V_13 ;
V_7 = F_40 ( F_43 ( V_52 . V_35 ) , V_52 . V_36 ,
F_43 ( V_52 . V_2 ) , V_3 ,
F_43 ( V_52 . V_4 ) , V_52 . V_5 ) ;
if ( V_7 >= 0 ) {
V_3 = V_7 ;
V_7 = 0 ;
}
if ( V_76 && F_5 ( V_3 , V_76 ) )
return - V_13 ;
return V_7 ;
}

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
T_5 V_14 = F_8 () ;
T_1 V_8 = 0 ;
char * V_15 ;
T_1 V_7 ;
V_7 = - V_16 ;
V_15 = F_9 ( V_17 , V_18 ) ;
if ( ! V_15 )
goto V_12;
if ( V_2 && V_3 ) {
unsigned T_2 * V_19 = V_2 ;
T_3 V_20 = V_3 / sizeof( * V_19 ) ;
T_4 V_10 = 0 ;
char * V_21 , * V_22 ;
int V_23 ;
F_10 ( V_24 ) ;
V_7 = F_3 ( V_1 , V_15 , V_17 - 1 , & V_10 ) ;
F_10 ( V_14 ) ;
if ( V_7 < 0 )
goto V_25;
V_21 = V_15 ;
V_22 = V_21 + V_7 ;
* V_22 ++ = '\0' ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
unsigned long V_26 ;
V_26 = F_11 ( V_21 , & V_21 , 10 ) ;
while ( isspace ( * V_21 ) )
V_21 ++ ;
V_7 = - V_13 ;
if ( F_5 ( V_26 , V_19 + V_23 ) )
goto V_25;
V_8 += sizeof( * V_19 ) ;
if ( ! isdigit ( * V_21 ) )
break;
}
}
if ( V_4 && V_5 ) {
unsigned T_2 * V_19 = V_4 ;
T_3 V_20 = V_5 / sizeof( * V_19 ) ;
T_4 V_10 = 0 ;
char * V_21 , * V_22 ;
int V_23 ;
V_21 = V_15 ;
V_22 = V_21 + V_17 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
unsigned long V_26 ;
V_7 = - V_13 ;
if ( F_4 ( V_26 , V_19 + V_23 ) )
goto V_25;
V_21 += snprintf ( V_21 , V_22 - V_21 , L_1 , V_26 ) ;
}
F_10 ( V_24 ) ;
V_7 = F_6 ( V_1 , V_15 , V_21 - V_15 , & V_10 ) ;
F_10 ( V_14 ) ;
if ( V_7 < 0 )
goto V_25;
}
V_7 = V_8 ;
V_25:
F_12 ( V_15 ) ;
V_12:
return V_7 ;
}
static T_1 F_13 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_5 V_14 = F_8 () ;
T_1 V_8 = 0 ;
char * V_15 ;
T_1 V_7 ;
V_7 = - V_16 ;
V_15 = F_9 ( V_17 , V_18 ) ;
if ( ! V_15 )
goto V_12;
if ( V_2 && V_3 ) {
unsigned long T_2 * V_19 = V_2 ;
T_3 V_20 = V_3 / sizeof( * V_19 ) ;
T_4 V_10 = 0 ;
char * V_21 , * V_22 ;
int V_23 ;
F_10 ( V_24 ) ;
V_7 = F_3 ( V_1 , V_15 , V_17 - 1 , & V_10 ) ;
F_10 ( V_14 ) ;
if ( V_7 < 0 )
goto V_25;
V_21 = V_15 ;
V_22 = V_21 + V_7 ;
* V_22 ++ = '\0' ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
unsigned long V_26 ;
V_26 = F_11 ( V_21 , & V_21 , 10 ) ;
while ( isspace ( * V_21 ) )
V_21 ++ ;
V_7 = - V_13 ;
if ( F_5 ( V_26 , V_19 + V_23 ) )
goto V_25;
V_8 += sizeof( * V_19 ) ;
if ( ! isdigit ( * V_21 ) )
break;
}
}
if ( V_4 && V_5 ) {
unsigned long T_2 * V_19 = V_4 ;
T_3 V_20 = V_5 / sizeof( * V_19 ) ;
T_4 V_10 = 0 ;
char * V_21 , * V_22 ;
int V_23 ;
V_21 = V_15 ;
V_22 = V_21 + V_17 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) {
unsigned long V_26 ;
V_7 = - V_13 ;
if ( F_4 ( V_26 , V_19 + V_23 ) )
goto V_25;
V_21 += snprintf ( V_21 , V_22 - V_21 , L_1 , V_26 ) ;
}
F_10 ( V_24 ) ;
V_7 = F_6 ( V_1 , V_15 , V_21 - V_15 , & V_10 ) ;
F_10 ( V_14 ) ;
if ( V_7 < 0 )
goto V_25;
}
V_7 = V_8 ;
V_25:
F_12 ( V_15 ) ;
V_12:
return V_7 ;
}
static T_1 F_14 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_5 V_14 = F_8 () ;
T_1 V_7 , V_8 = 0 ;
if ( V_2 && V_3 ) {
T_4 V_10 = 0 ;
char V_27 [ 40 ] , * V_21 = V_27 ;
unsigned char V_28 [ 16 ] ;
int V_23 ;
F_10 ( V_24 ) ;
V_7 = F_3 ( V_1 , V_27 , sizeof( V_27 ) - 1 , & V_10 ) ;
F_10 ( V_14 ) ;
if ( V_7 < 0 )
goto V_12;
V_27 [ V_7 ] = '\0' ;
for ( V_23 = 0 ; V_23 < 16 ; V_23 ++ ) {
V_7 = - V_29 ;
if ( ! isxdigit ( V_21 [ 0 ] ) || ! isxdigit ( V_21 [ 1 ] ) )
goto V_12;
V_28 [ V_23 ] = ( F_15 ( V_21 [ 0 ] ) << 4 ) |
F_15 ( V_21 [ 1 ] ) ;
V_21 += 2 ;
if ( * V_21 == '-' )
V_21 ++ ;
}
if ( V_3 > 16 )
V_3 = 16 ;
V_7 = - V_13 ;
if ( F_16 ( V_2 , V_28 , V_3 ) )
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
T_5 V_14 = F_8 () ;
T_1 V_7 , V_8 = 0 ;
if ( V_2 && V_3 ) {
T_4 V_10 = 0 ;
char V_27 [ 15 ] , * V_30 ;
unsigned long V_31 , V_32 ;
T_6 V_33 ;
F_10 ( V_24 ) ;
V_7 = F_3 ( V_1 , V_27 , sizeof( V_27 ) - 1 , & V_10 ) ;
F_10 ( V_14 ) ;
if ( V_7 < 0 )
goto V_12;
V_27 [ V_7 ] = '\0' ;
V_7 = - V_29 ;
V_30 = strchr ( V_27 , '.' ) + 1 ;
if ( ! V_30 )
goto V_12;
V_31 = F_11 ( V_27 , NULL , 10 ) ;
V_32 = F_11 ( V_30 , NULL , 10 ) ;
V_7 = - V_29 ;
if ( ( V_31 > 63 ) || ( V_32 > 1023 ) )
goto V_12;
V_33 = F_18 ( ( V_31 << 10 ) | V_32 ) ;
V_7 = - V_13 ;
if ( F_5 ( V_33 , ( T_6 T_2 * ) V_2 ) )
goto V_12;
V_8 = sizeof( V_33 ) ;
}
if ( V_4 && V_5 ) {
T_4 V_10 = 0 ;
T_6 V_33 ;
char V_27 [ 15 ] ;
int V_34 ;
V_7 = - V_35 ;
if ( V_5 != sizeof( V_33 ) )
goto V_12;
V_7 = - V_13 ;
if ( F_4 ( V_33 , ( T_6 T_2 * ) V_4 ) )
goto V_12;
V_34 = snprintf ( V_27 , sizeof( V_27 ) , L_2 ,
F_19 ( V_33 ) >> 10 ,
F_19 ( V_33 ) & 0x3ff ) ;
F_10 ( V_24 ) ;
V_7 = F_6 ( V_1 , V_27 , V_34 , & V_10 ) ;
F_10 ( V_14 ) ;
if ( V_7 < 0 )
goto V_12;
}
V_7 = V_8 ;
V_12:
return V_7 ;
}
static const struct V_36 * F_20 ( const int * V_37 , int V_38 , char * V_39 )
{
const struct V_36 * V_40 = & V_41 [ 0 ] ;
int V_42 ;
memcpy ( V_39 , L_3 , 4 ) ;
V_39 += 4 ;
V_43:
if ( ! V_38 )
return F_21 ( - V_6 ) ;
V_42 = * V_37 ;
V_37 ++ ;
V_38 -- ;
for ( ; V_40 -> V_44 ; V_40 ++ ) {
int V_34 = 0 ;
if ( ! V_40 -> V_42 ) {
#ifdef F_22
struct V_45 * V_45 = V_46 -> V_47 -> V_48 ;
struct V_49 * V_50 ;
V_50 = F_23 ( V_45 , V_42 ) ;
if ( V_50 ) {
V_34 = strlen ( V_50 -> V_37 ) ;
memcpy ( V_39 , V_50 -> V_37 , V_34 ) ;
F_24 ( V_50 ) ;
}
#endif
} else if ( V_42 == V_40 -> V_42 ) {
V_34 = strlen ( V_40 -> V_51 ) ;
memcpy ( V_39 , V_40 -> V_51 , V_34 ) ;
}
if ( V_34 ) {
V_39 += V_34 ;
if ( V_40 -> V_52 ) {
* V_39 ++ = '/' ;
V_40 = V_40 -> V_52 ;
goto V_43;
}
* V_39 = '\0' ;
return V_40 ;
}
}
return F_21 ( - V_6 ) ;
}
static char * F_25 ( const int * V_37 , int V_38 , const struct V_36 * * V_53 )
{
char * V_54 , * V_7 ;
V_7 = F_21 ( - V_16 ) ;
V_54 = F_26 () ;
if ( V_54 ) {
const struct V_36 * V_40 = F_20 ( V_37 , V_38 , V_54 ) ;
V_7 = V_54 ;
* V_53 = V_40 ;
if ( F_27 ( V_40 ) ) {
F_28 ( V_54 ) ;
V_7 = F_29 ( V_40 ) ;
}
}
return V_7 ;
}
static T_1 F_30 ( const int * V_37 , int V_38 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
const struct V_36 * V_40 = NULL ;
struct V_55 * V_56 ;
struct V_1 * V_1 ;
T_1 V_7 ;
char * V_57 ;
int V_58 ;
V_57 = F_25 ( V_37 , V_38 , & V_40 ) ;
V_7 = F_31 ( V_57 ) ;
if ( F_27 ( V_57 ) )
goto V_12;
if ( V_2 && V_3 && V_4 && V_5 ) {
V_58 = V_59 ;
} else if ( V_4 && V_5 ) {
V_58 = V_60 ;
} else if ( V_2 && V_3 ) {
V_58 = V_61 ;
} else {
V_7 = 0 ;
goto V_62;
}
V_56 = V_46 -> V_47 -> V_63 -> V_64 ;
V_1 = F_32 ( V_56 -> V_65 , V_56 , V_57 , V_58 ) ;
V_7 = F_31 ( V_1 ) ;
if ( F_27 ( V_1 ) )
goto V_62;
V_7 = V_40 -> V_44 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_33 ( V_1 ) ;
V_62:
F_28 ( V_57 ) ;
V_12:
return V_7 ;
}
static T_1 F_30 ( const int * V_37 , int V_38 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
return - V_66 ;
}
static void F_34 ( const int * V_37 , int V_38 )
{
int V_23 ;
if ( V_37 [ 0 ] == V_67 && V_37 [ 1 ] == V_68 )
return;
if ( F_35 () ) {
F_36 ( V_69
L_4
L_5 , V_46 -> V_70 ) ;
for ( V_23 = 0 ; V_23 < V_38 ; V_23 ++ )
F_36 ( L_6 , V_37 [ V_23 ] ) ;
F_36 ( L_7 ) ;
}
return;
}
static void F_37 ( const int * V_37 , int V_38 )
{
int V_23 ;
T_7 V_71 = V_72 ;
for ( V_23 = 0 ; V_23 < V_38 ; V_23 ++ )
V_71 = ( V_71 ^ V_37 [ V_23 ] ) * V_73 ;
V_71 %= V_74 ;
if ( F_38 ( V_71 , V_75 ) )
return;
F_34 ( V_37 , V_38 ) ;
}
static T_1 F_39 ( int T_2 * V_76 , int V_38 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
int V_37 [ V_77 ] ;
int V_23 ;
if ( V_38 < 0 || V_38 > V_77 )
return - V_6 ;
for ( V_23 = 0 ; V_23 < V_38 ; V_23 ++ )
if ( F_4 ( V_37 [ V_23 ] , V_76 + V_23 ) )
return - V_13 ;
F_37 ( V_37 , V_38 ) ;
return F_30 ( V_37 , V_38 , V_2 , V_3 , V_4 , V_5 ) ;
}
T_8 long F_40 ( struct V_78 T_2 * args )
{
struct V_78 V_54 ;
T_9 T_2 * V_79 ;
T_3 V_3 = 0 ;
T_1 V_7 ;
if ( F_41 ( & V_54 , args , sizeof( V_54 ) ) )
return - V_13 ;
if ( V_54 . V_2 && ! V_54 . V_80 )
return - V_13 ;
V_79 = F_42 ( V_54 . V_80 ) ;
if ( V_79 && F_4 ( V_3 , V_79 ) )
return - V_13 ;
V_7 = F_39 ( F_42 ( V_54 . V_37 ) , V_54 . V_38 ,
F_42 ( V_54 . V_2 ) , V_3 ,
F_42 ( V_54 . V_4 ) , V_54 . V_5 ) ;
if ( V_7 >= 0 ) {
V_3 = V_7 ;
V_7 = 0 ;
}
if ( V_79 && F_5 ( V_3 , V_79 ) )
return - V_13 ;
return V_7 ;
}

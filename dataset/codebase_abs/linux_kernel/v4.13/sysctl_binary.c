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
V_20 += F_11 ( V_20 , V_21 - V_20 , L_1 , V_24 ) ;
}
V_7 = F_12 ( V_1 , V_14 , V_20 - V_14 , 0 ) ;
if ( V_7 < 0 )
goto V_23;
}
V_7 = V_8 ;
V_23:
F_13 ( V_14 ) ;
V_12:
return V_7 ;
}
static T_1 F_14 ( struct V_1 * V_1 ,
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
V_20 += F_11 ( V_20 , V_21 - V_20 , L_1 , V_24 ) ;
}
V_7 = F_12 ( V_1 , V_14 , V_20 - V_14 , 0 ) ;
if ( V_7 < 0 )
goto V_23;
}
V_7 = V_8 ;
V_23:
F_13 ( V_14 ) ;
V_12:
return V_7 ;
}
static T_1 F_15 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_1 V_7 , V_8 = 0 ;
if ( V_2 && V_3 ) {
char V_25 [ V_26 + 1 ] ;
T_5 V_27 ;
V_7 = F_9 ( V_1 , 0 , V_25 , sizeof( V_25 ) - 1 ) ;
if ( V_7 < 0 )
goto V_12;
V_25 [ V_7 ] = '\0' ;
V_7 = - V_28 ;
if ( F_16 ( V_25 , & V_27 ) )
goto V_12;
if ( V_3 > 16 )
V_3 = 16 ;
V_7 = - V_13 ;
if ( F_17 ( V_2 , & V_27 , V_3 ) )
goto V_12;
V_8 = V_3 ;
}
V_7 = V_8 ;
V_12:
return V_7 ;
}
static T_1 F_18 ( struct V_1 * V_1 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
T_1 V_7 , V_8 = 0 ;
if ( V_2 && V_3 ) {
char V_25 [ 15 ] , * V_29 ;
unsigned long V_30 , V_31 ;
T_6 V_32 ;
V_7 = F_9 ( V_1 , 0 , V_25 , sizeof( V_25 ) - 1 ) ;
if ( V_7 < 0 )
goto V_12;
V_25 [ V_7 ] = '\0' ;
V_7 = - V_28 ;
V_29 = strchr ( V_25 , '.' ) ;
if ( ! V_29 )
goto V_12;
++ V_29 ;
V_30 = F_10 ( V_25 , NULL , 10 ) ;
V_31 = F_10 ( V_29 , NULL , 10 ) ;
V_7 = - V_28 ;
if ( ( V_30 > 63 ) || ( V_31 > 1023 ) )
goto V_12;
V_32 = F_19 ( ( V_30 << 10 ) | V_31 ) ;
V_7 = - V_13 ;
if ( F_5 ( V_32 , ( T_6 T_2 * ) V_2 ) )
goto V_12;
V_8 = sizeof( V_32 ) ;
}
if ( V_4 && V_5 ) {
T_6 V_32 ;
char V_25 [ 15 ] ;
int V_33 ;
V_7 = - V_34 ;
if ( V_5 != sizeof( V_32 ) )
goto V_12;
V_7 = - V_13 ;
if ( F_4 ( V_32 , ( T_6 T_2 * ) V_4 ) )
goto V_12;
V_33 = F_11 ( V_25 , sizeof( V_25 ) , L_2 ,
F_20 ( V_32 ) >> 10 ,
F_20 ( V_32 ) & 0x3ff ) ;
V_7 = F_12 ( V_1 , V_25 , V_33 , 0 ) ;
if ( V_7 < 0 )
goto V_12;
}
V_7 = V_8 ;
V_12:
return V_7 ;
}
static const struct V_35 * F_21 ( const int * V_36 , int V_37 , char * V_38 )
{
const struct V_35 * V_39 = & V_40 [ 0 ] ;
int V_41 ;
memcpy ( V_38 , L_3 , 4 ) ;
V_38 += 4 ;
V_42:
if ( ! V_37 )
return F_22 ( - V_6 ) ;
V_41 = * V_36 ;
V_36 ++ ;
V_37 -- ;
for ( ; V_39 -> V_43 ; V_39 ++ ) {
int V_33 = 0 ;
if ( ! V_39 -> V_41 ) {
#ifdef F_23
struct V_44 * V_44 = V_45 -> V_46 -> V_47 ;
struct V_48 * V_49 ;
V_49 = F_24 ( V_44 , V_41 ) ;
if ( V_49 ) {
V_33 = strlen ( V_49 -> V_36 ) ;
memcpy ( V_38 , V_49 -> V_36 , V_33 ) ;
F_25 ( V_49 ) ;
}
#endif
} else if ( V_41 == V_39 -> V_41 ) {
V_33 = strlen ( V_39 -> V_50 ) ;
memcpy ( V_38 , V_39 -> V_50 , V_33 ) ;
}
if ( V_33 ) {
V_38 += V_33 ;
if ( V_39 -> V_51 ) {
* V_38 ++ = '/' ;
V_39 = V_39 -> V_51 ;
goto V_42;
}
* V_38 = '\0' ;
return V_39 ;
}
}
return F_22 ( - V_6 ) ;
}
static char * F_26 ( const int * V_36 , int V_37 , const struct V_35 * * V_52 )
{
char * V_53 , * V_7 ;
V_7 = F_22 ( - V_15 ) ;
V_53 = F_27 () ;
if ( V_53 ) {
const struct V_35 * V_39 = F_21 ( V_36 , V_37 , V_53 ) ;
V_7 = V_53 ;
* V_52 = V_39 ;
if ( F_28 ( V_39 ) ) {
F_29 ( V_53 ) ;
V_7 = F_30 ( V_39 ) ;
}
}
return V_7 ;
}
static T_1 F_31 ( const int * V_36 , int V_37 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
const struct V_35 * V_39 = NULL ;
struct V_54 * V_55 ;
struct V_1 * V_1 ;
T_1 V_7 ;
char * V_56 ;
int V_57 ;
V_56 = F_26 ( V_36 , V_37 , & V_39 ) ;
V_7 = F_32 ( V_56 ) ;
if ( F_28 ( V_56 ) )
goto V_12;
if ( V_2 && V_3 && V_4 && V_5 ) {
V_57 = V_58 ;
} else if ( V_4 && V_5 ) {
V_57 = V_59 ;
} else if ( V_2 && V_3 ) {
V_57 = V_60 ;
} else {
V_7 = 0 ;
goto V_61;
}
V_55 = F_33 ( V_45 ) -> V_62 ;
V_1 = F_34 ( V_55 -> V_63 , V_55 , V_56 , V_57 , 0 ) ;
V_7 = F_32 ( V_1 ) ;
if ( F_28 ( V_1 ) )
goto V_61;
V_7 = V_39 -> V_43 ( V_1 , V_2 , V_3 , V_4 , V_5 ) ;
F_35 ( V_1 ) ;
V_61:
F_29 ( V_56 ) ;
V_12:
return V_7 ;
}
static T_1 F_31 ( const int * V_36 , int V_37 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
return - V_64 ;
}
static void F_36 ( const int * V_36 , int V_37 )
{
int V_22 ;
if ( V_37 >= 2 && V_36 [ 0 ] == V_65 && V_36 [ 1 ] == V_66 )
return;
if ( F_37 () ) {
F_38 ( V_67
L_4
L_5 , V_45 -> V_68 ) ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ )
F_38 ( V_69 L_6 , V_36 [ V_22 ] ) ;
F_38 ( V_69 L_7 ) ;
}
return;
}
static void F_39 ( const int * V_36 , int V_37 )
{
int V_22 ;
T_7 V_70 = V_71 ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ )
V_70 = ( V_70 ^ V_36 [ V_22 ] ) * V_72 ;
V_70 %= V_73 ;
if ( F_40 ( V_70 , V_74 ) )
return;
F_36 ( V_36 , V_37 ) ;
}
static T_1 F_41 ( int T_2 * V_75 , int V_37 ,
void T_2 * V_2 , T_3 V_3 , void T_2 * V_4 , T_3 V_5 )
{
int V_36 [ V_76 ] ;
int V_22 ;
if ( V_37 < 0 || V_37 > V_76 )
return - V_6 ;
for ( V_22 = 0 ; V_22 < V_37 ; V_22 ++ )
if ( F_4 ( V_36 [ V_22 ] , V_75 + V_22 ) )
return - V_13 ;
F_39 ( V_36 , V_37 ) ;
return F_31 ( V_36 , V_37 , V_2 , V_3 , V_4 , V_5 ) ;
}

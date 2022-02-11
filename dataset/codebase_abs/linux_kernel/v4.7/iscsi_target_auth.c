static int F_1 ( unsigned char * V_1 , unsigned char * V_2 , int V_3 )
{
int V_4 = F_2 ( V_3 , 2 ) , V_5 ;
V_5 = F_3 ( V_1 , V_2 , V_4 ) ;
if ( V_5 < 0 )
F_4 ( L_1 ) ;
V_1 [ V_4 ] = '\0' ;
return V_4 ;
}
static void F_5 ( char * V_1 , char * V_2 , int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ ) {
sprintf ( & V_1 [ V_7 * 2 ] , L_2 , ( int ) V_2 [ V_7 ] & 0xff ) ;
}
}
static void F_6 (
struct V_8 * V_9 ,
int V_10 ,
char * V_11 ,
unsigned int * V_12 )
{
unsigned char V_13 [ V_14 * 2 + 1 ] ;
struct V_15 * V_16 = V_9 -> V_17 ;
memset ( V_13 , 0 , V_14 * 2 + 1 ) ;
F_7 ( V_16 -> V_18 , V_14 ) ;
F_5 ( V_13 , V_16 -> V_18 ,
V_14 ) ;
* V_12 += sprintf ( V_11 + * V_12 , L_3 , V_13 ) ;
* V_12 += 1 ;
F_4 ( L_4 , ( V_10 ) ? L_5 : L_6 ,
V_13 ) ;
}
static int F_8 ( const char * V_19 )
{
char * V_20 , * V_21 , * V_22 ;
V_20 = F_9 ( V_19 , V_23 ) ;
if ( ! V_20 ) {
F_10 ( L_7 ) ;
return V_24 ;
}
V_21 = V_20 ;
V_22 = F_11 ( & V_20 , L_8 ) ;
if ( ! V_22 )
goto V_25;
if ( strcmp ( V_22 , L_9 ) ) {
F_10 ( L_10 ) ;
goto V_25;
}
while ( V_22 ) {
V_22 = F_11 ( & V_20 , L_11 ) ;
if ( ! V_22 )
goto V_25;
if ( ! strncmp ( V_22 , L_12 , 1 ) ) {
F_4 ( L_13 ) ;
F_12 ( V_21 ) ;
return V_26 ;
}
}
V_25:
F_12 ( V_21 ) ;
return V_24 ;
}
static struct V_15 * F_13 (
struct V_8 * V_9 ,
struct V_27 * V_28 ,
const char * V_19 ,
char * V_29 ,
unsigned int * V_30 )
{
int V_31 ;
struct V_15 * V_16 ;
if ( ! ( V_28 -> V_32 & V_33 ) ||
! ( V_28 -> V_32 & V_34 ) ) {
F_10 ( L_14
L_15 ) ;
return NULL ;
}
V_9 -> V_17 = F_14 ( sizeof( struct V_15 ) , V_23 ) ;
if ( ! V_9 -> V_17 )
return NULL ;
V_16 = V_9 -> V_17 ;
V_31 = F_8 ( V_19 ) ;
switch ( V_31 ) {
case V_26 :
F_4 ( L_16 ) ;
* V_30 = sprintf ( V_29 , L_17 ) ;
* V_30 += 1 ;
V_16 -> V_35 = V_26 ;
F_4 ( L_18 , V_16 -> V_35 ) ;
break;
case V_24 :
default:
F_10 ( L_19 ) ;
return NULL ;
}
V_16 -> V_36 = V_9 -> V_37 -> V_38 ++ ;
* V_30 += sprintf ( V_29 + * V_30 , L_20 , V_16 -> V_36 ) ;
* V_30 += 1 ;
F_4 ( L_21 , V_16 -> V_36 ) ;
F_6 ( V_9 , 1 , V_29 , V_30 ) ;
return V_16 ;
}
static void F_15 ( struct V_8 * V_9 )
{
F_12 ( V_9 -> V_17 ) ;
V_9 -> V_17 = NULL ;
}
static int F_16 (
struct V_8 * V_9 ,
struct V_27 * V_28 ,
char * V_39 ,
char * V_40 ,
unsigned int * V_41 )
{
unsigned long V_36 ;
unsigned char V_42 ;
unsigned char V_43 [ V_44 ] ;
unsigned char type , V_45 [ V_44 * 2 + 2 ] ;
unsigned char V_46 [ 10 ] , * V_18 = NULL ;
unsigned char * V_47 = NULL ;
unsigned char V_48 [ V_44 ] ;
unsigned char V_49 [ V_44 ] ;
unsigned char V_50 [ V_51 ] , V_52 [ V_53 ] ;
T_1 V_54 ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_55 * V_56 = NULL ;
struct V_57 * V_58 = NULL ;
int V_59 = - 1 , V_31 , V_60 ;
memset ( V_46 , 0 , 10 ) ;
memset ( V_50 , 0 , V_51 ) ;
memset ( V_52 , 0 , V_53 ) ;
memset ( V_43 , 0 , V_44 ) ;
memset ( V_45 , 0 , V_44 * 2 + 2 ) ;
memset ( V_48 , 0 , V_44 ) ;
memset ( V_49 , 0 , V_44 ) ;
V_18 = F_14 ( V_61 , V_23 ) ;
if ( ! V_18 ) {
F_10 ( L_22 ) ;
goto V_25;
}
V_47 = F_14 ( V_61 , V_23 ) ;
if ( ! V_47 ) {
F_10 ( L_23 ) ;
goto V_25;
}
if ( F_17 ( V_39 , L_24 , V_51 , V_50 ,
& type ) < 0 ) {
F_10 ( L_25 ) ;
goto V_25;
}
if ( type == V_62 ) {
F_10 ( L_25 ) ;
goto V_25;
}
V_54 = strlen ( V_28 -> V_63 ) + 1 ;
if ( strncmp ( V_50 , V_28 -> V_63 , V_54 ) != 0 ) {
F_10 ( L_26 ) ;
goto V_25;
}
F_4 ( L_27 , V_50 ) ;
if ( F_17 ( V_39 , L_28 , V_53 , V_52 ,
& type ) < 0 ) {
F_10 ( L_29 ) ;
goto V_25;
}
if ( type != V_62 ) {
F_10 ( L_29 ) ;
goto V_25;
}
F_4 ( L_30 , V_52 ) ;
F_1 ( V_48 , V_52 , strlen ( V_52 ) ) ;
V_56 = F_18 ( L_31 , 0 , 0 ) ;
if ( F_19 ( V_56 ) ) {
V_56 = NULL ;
F_10 ( L_32 ) ;
goto V_25;
}
V_58 = F_20 ( sizeof( * V_58 ) + F_21 ( V_56 ) , V_23 ) ;
if ( ! V_58 ) {
F_10 ( L_33 ) ;
goto V_25;
}
V_58 -> V_56 = V_56 ;
V_58 -> V_64 = 0 ;
V_31 = F_22 ( V_58 ) ;
if ( V_31 < 0 ) {
F_10 ( L_34 ) ;
goto V_25;
}
V_31 = F_23 ( V_58 , & V_16 -> V_36 , 1 ) ;
if ( V_31 < 0 ) {
F_10 ( L_35 ) ;
goto V_25;
}
V_31 = F_23 ( V_58 , ( char * ) & V_28 -> V_65 ,
strlen ( V_28 -> V_65 ) ) ;
if ( V_31 < 0 ) {
F_10 ( L_36 ) ;
goto V_25;
}
V_31 = F_24 ( V_58 , V_16 -> V_18 ,
V_14 , V_49 ) ;
if ( V_31 < 0 ) {
F_10 ( L_37 ) ;
goto V_25;
}
F_5 ( V_45 , V_49 , V_44 ) ;
F_4 ( L_38 , V_45 ) ;
if ( memcmp ( V_49 , V_48 , V_44 ) != 0 ) {
F_4 ( L_39 ) ;
goto V_25;
} else
F_4 ( L_40
L_41 ) ;
if ( ! V_28 -> V_66 ) {
V_59 = 0 ;
goto V_25;
}
if ( F_17 ( V_39 , L_42 , 10 , V_46 , & type ) < 0 ) {
F_10 ( L_43 ) ;
goto V_25;
}
if ( type == V_62 )
V_31 = F_25 ( & V_46 [ 2 ] , 0 , & V_36 ) ;
else
V_31 = F_25 ( V_46 , 0 , & V_36 ) ;
if ( V_31 < 0 ) {
F_10 ( L_44 , V_31 ) ;
goto V_25;
}
if ( V_36 > 255 ) {
F_10 ( L_45 , V_36 ) ;
goto V_25;
}
F_4 ( L_46 , V_36 ) ;
if ( F_17 ( V_39 , L_47 , V_61 ,
V_18 , & type ) < 0 ) {
F_10 ( L_48 ) ;
goto V_25;
}
if ( type != V_62 ) {
F_10 ( L_48 ) ;
goto V_25;
}
F_4 ( L_49 , V_18 ) ;
V_60 = F_1 ( V_47 , V_18 ,
strlen ( V_18 ) ) ;
if ( ! V_60 ) {
F_10 ( L_50 ) ;
goto V_25;
}
if ( V_60 > 1024 ) {
F_10 ( L_51 ) ;
goto V_25;
}
if ( ! memcmp ( V_47 , V_16 -> V_18 , V_14 ) ) {
F_10 ( L_52
L_53 ) ;
goto V_25;
}
V_31 = F_22 ( V_58 ) ;
if ( V_31 < 0 ) {
F_10 ( L_34 ) ;
goto V_25;
}
V_42 = V_36 ;
V_31 = F_23 ( V_58 , & V_42 , 1 ) ;
if ( V_31 < 0 ) {
F_10 ( L_35 ) ;
goto V_25;
}
V_31 = F_23 ( V_58 , V_28 -> V_67 ,
strlen ( V_28 -> V_67 ) ) ;
if ( V_31 < 0 ) {
F_10 ( L_54
L_55 ) ;
goto V_25;
}
V_31 = F_24 ( V_58 , V_47 , V_60 ,
V_43 ) ;
if ( V_31 < 0 ) {
F_10 ( L_56 ) ;
goto V_25;
}
* V_41 = sprintf ( V_40 , L_57 , V_28 -> V_68 ) ;
* V_41 += 1 ;
F_4 ( L_58 , V_28 -> V_68 ) ;
F_5 ( V_45 , V_43 , V_44 ) ;
* V_41 += sprintf ( V_40 + * V_41 , L_59 ,
V_45 ) ;
* V_41 += 1 ;
F_4 ( L_60 , V_45 ) ;
V_59 = 0 ;
V_25:
F_26 ( V_58 ) ;
F_27 ( V_56 ) ;
F_12 ( V_18 ) ;
F_12 ( V_47 ) ;
return V_59 ;
}
static int F_28 (
struct V_8 * V_9 ,
struct V_27 * V_28 ,
char * V_39 ,
char * V_40 ,
unsigned int * V_41 )
{
struct V_15 * V_16 = V_9 -> V_17 ;
switch ( V_16 -> V_35 ) {
case V_26 :
if ( F_16 ( V_9 , V_28 , V_39 ,
V_40 , V_41 ) < 0 )
return - 1 ;
return 0 ;
default:
F_10 ( L_61 ,
V_16 -> V_35 ) ;
return - 1 ;
}
}
T_2 F_29 (
struct V_8 * V_9 ,
struct V_27 * V_28 ,
char * V_69 ,
char * V_70 ,
int * V_71 ,
int * V_72 )
{
struct V_15 * V_16 = V_9 -> V_17 ;
if ( ! V_16 ) {
V_16 = F_13 ( V_9 , V_28 , V_69 , V_70 , V_72 ) ;
if ( ! V_16 )
return 2 ;
V_16 -> V_73 = V_74 ;
return 0 ;
} else if ( V_16 -> V_73 == V_74 ) {
F_30 ( V_69 , * V_71 ) ;
if ( F_28 ( V_9 , V_28 , V_69 , V_70 ,
V_72 ) < 0 ) {
F_15 ( V_9 ) ;
return 2 ;
}
if ( V_28 -> V_66 )
V_16 -> V_73 = V_75 ;
else
* V_72 = 0 ;
F_15 ( V_9 ) ;
return 1 ;
}
return 2 ;
}

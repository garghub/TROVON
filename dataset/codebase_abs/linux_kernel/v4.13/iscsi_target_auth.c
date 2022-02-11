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
static int F_6 (
struct V_8 * V_9 ,
int V_10 ,
char * V_11 ,
unsigned int * V_12 )
{
int V_13 ;
unsigned char V_14 [ V_15 * 2 + 1 ] ;
struct V_16 * V_17 = V_9 -> V_18 ;
memset ( V_14 , 0 , V_15 * 2 + 1 ) ;
V_13 = F_7 ( V_17 -> V_19 , V_15 ) ;
if ( F_8 ( V_13 ) )
return V_13 ;
F_5 ( V_14 , V_17 -> V_19 ,
V_15 ) ;
* V_12 += sprintf ( V_11 + * V_12 , L_3 , V_14 ) ;
* V_12 += 1 ;
F_4 ( L_4 , ( V_10 ) ? L_5 : L_6 ,
V_14 ) ;
return 0 ;
}
static int F_9 ( const char * V_20 )
{
char * V_21 , * V_22 , * V_23 ;
V_21 = F_10 ( V_20 , V_24 ) ;
if ( ! V_21 ) {
F_11 ( L_7 ) ;
return V_25 ;
}
V_22 = V_21 ;
V_23 = F_12 ( & V_21 , L_8 ) ;
if ( ! V_23 )
goto V_26;
if ( strcmp ( V_23 , L_9 ) ) {
F_11 ( L_10 ) ;
goto V_26;
}
while ( V_23 ) {
V_23 = F_12 ( & V_21 , L_11 ) ;
if ( ! V_23 )
goto V_26;
if ( ! strncmp ( V_23 , L_12 , 1 ) ) {
F_4 ( L_13 ) ;
F_13 ( V_22 ) ;
return V_27 ;
}
}
V_26:
F_13 ( V_22 ) ;
return V_25 ;
}
static struct V_16 * F_14 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
const char * V_20 ,
char * V_30 ,
unsigned int * V_31 )
{
int V_13 ;
struct V_16 * V_17 ;
if ( ! ( V_29 -> V_32 & V_33 ) ||
! ( V_29 -> V_32 & V_34 ) ) {
F_11 ( L_14
L_15 ) ;
return NULL ;
}
V_9 -> V_18 = F_15 ( sizeof( struct V_16 ) , V_24 ) ;
if ( ! V_9 -> V_18 )
return NULL ;
V_17 = V_9 -> V_18 ;
V_13 = F_9 ( V_20 ) ;
switch ( V_13 ) {
case V_27 :
F_4 ( L_16 ) ;
* V_31 = sprintf ( V_30 , L_17 ) ;
* V_31 += 1 ;
V_17 -> V_35 = V_27 ;
F_4 ( L_18 , V_17 -> V_35 ) ;
break;
case V_25 :
default:
F_11 ( L_19 ) ;
F_13 ( V_9 -> V_18 ) ;
return NULL ;
}
V_17 -> V_36 = V_9 -> V_37 -> V_38 ++ ;
* V_31 += sprintf ( V_30 + * V_31 , L_20 , V_17 -> V_36 ) ;
* V_31 += 1 ;
F_4 ( L_21 , V_17 -> V_36 ) ;
if ( F_6 ( V_9 , 1 , V_30 , V_31 ) < 0 ) {
F_13 ( V_9 -> V_18 ) ;
return NULL ;
}
return V_17 ;
}
static void F_16 ( struct V_8 * V_9 )
{
F_13 ( V_9 -> V_18 ) ;
V_9 -> V_18 = NULL ;
}
static int F_17 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
char * V_39 ,
char * V_40 ,
unsigned int * V_41 )
{
unsigned long V_36 ;
unsigned char V_42 ;
unsigned char V_43 [ V_44 ] ;
unsigned char type , V_45 [ V_44 * 2 + 2 ] ;
unsigned char V_46 [ 10 ] , * V_19 = NULL ;
unsigned char * V_47 = NULL ;
unsigned char V_48 [ V_44 ] ;
unsigned char V_49 [ V_44 ] ;
unsigned char V_50 [ V_51 ] , V_52 [ V_53 ] ;
T_1 V_54 ;
struct V_16 * V_17 = V_9 -> V_18 ;
struct V_55 * V_56 = NULL ;
struct V_57 * V_58 = NULL ;
int V_59 = - 1 , V_13 , V_60 ;
memset ( V_46 , 0 , 10 ) ;
memset ( V_50 , 0 , V_51 ) ;
memset ( V_52 , 0 , V_53 ) ;
memset ( V_43 , 0 , V_44 ) ;
memset ( V_45 , 0 , V_44 * 2 + 2 ) ;
memset ( V_48 , 0 , V_44 ) ;
memset ( V_49 , 0 , V_44 ) ;
V_19 = F_15 ( V_61 , V_24 ) ;
if ( ! V_19 ) {
F_11 ( L_22 ) ;
goto V_26;
}
V_47 = F_15 ( V_61 , V_24 ) ;
if ( ! V_47 ) {
F_11 ( L_23 ) ;
goto V_26;
}
if ( F_18 ( V_39 , L_24 , V_51 , V_50 ,
& type ) < 0 ) {
F_11 ( L_25 ) ;
goto V_26;
}
if ( type == V_62 ) {
F_11 ( L_25 ) ;
goto V_26;
}
V_54 = strlen ( V_29 -> V_63 ) + 1 ;
if ( strncmp ( V_50 , V_29 -> V_63 , V_54 ) != 0 ) {
F_11 ( L_26 ) ;
goto V_26;
}
F_4 ( L_27 , V_50 ) ;
if ( F_18 ( V_39 , L_28 , V_53 , V_52 ,
& type ) < 0 ) {
F_11 ( L_29 ) ;
goto V_26;
}
if ( type != V_62 ) {
F_11 ( L_29 ) ;
goto V_26;
}
F_4 ( L_30 , V_52 ) ;
F_1 ( V_48 , V_52 , strlen ( V_52 ) ) ;
V_56 = F_19 ( L_31 , 0 , 0 ) ;
if ( F_20 ( V_56 ) ) {
V_56 = NULL ;
F_11 ( L_32 ) ;
goto V_26;
}
V_58 = F_21 ( sizeof( * V_58 ) + F_22 ( V_56 ) , V_24 ) ;
if ( ! V_58 ) {
F_11 ( L_33 ) ;
goto V_26;
}
V_58 -> V_56 = V_56 ;
V_58 -> V_64 = 0 ;
V_13 = F_23 ( V_58 ) ;
if ( V_13 < 0 ) {
F_11 ( L_34 ) ;
goto V_26;
}
V_13 = F_24 ( V_58 , & V_17 -> V_36 , 1 ) ;
if ( V_13 < 0 ) {
F_11 ( L_35 ) ;
goto V_26;
}
V_13 = F_24 ( V_58 , ( char * ) & V_29 -> V_65 ,
strlen ( V_29 -> V_65 ) ) ;
if ( V_13 < 0 ) {
F_11 ( L_36 ) ;
goto V_26;
}
V_13 = F_25 ( V_58 , V_17 -> V_19 ,
V_15 , V_49 ) ;
if ( V_13 < 0 ) {
F_11 ( L_37 ) ;
goto V_26;
}
F_5 ( V_45 , V_49 , V_44 ) ;
F_4 ( L_38 , V_45 ) ;
if ( memcmp ( V_49 , V_48 , V_44 ) != 0 ) {
F_4 ( L_39 ) ;
goto V_26;
} else
F_4 ( L_40
L_41 ) ;
if ( ! V_29 -> V_66 ) {
V_59 = 0 ;
goto V_26;
}
if ( F_18 ( V_39 , L_42 , 10 , V_46 , & type ) < 0 ) {
F_11 ( L_43 ) ;
goto V_26;
}
if ( type == V_62 )
V_13 = F_26 ( & V_46 [ 2 ] , 0 , & V_36 ) ;
else
V_13 = F_26 ( V_46 , 0 , & V_36 ) ;
if ( V_13 < 0 ) {
F_11 ( L_44 , V_13 ) ;
goto V_26;
}
if ( V_36 > 255 ) {
F_11 ( L_45 , V_36 ) ;
goto V_26;
}
F_4 ( L_46 , V_36 ) ;
if ( F_18 ( V_39 , L_47 , V_61 ,
V_19 , & type ) < 0 ) {
F_11 ( L_48 ) ;
goto V_26;
}
if ( type != V_62 ) {
F_11 ( L_48 ) ;
goto V_26;
}
F_4 ( L_49 , V_19 ) ;
V_60 = F_1 ( V_47 , V_19 ,
strlen ( V_19 ) ) ;
if ( ! V_60 ) {
F_11 ( L_50 ) ;
goto V_26;
}
if ( V_60 > 1024 ) {
F_11 ( L_51 ) ;
goto V_26;
}
if ( ! memcmp ( V_47 , V_17 -> V_19 , V_15 ) ) {
F_11 ( L_52
L_53 ) ;
goto V_26;
}
V_13 = F_23 ( V_58 ) ;
if ( V_13 < 0 ) {
F_11 ( L_34 ) ;
goto V_26;
}
V_42 = V_36 ;
V_13 = F_24 ( V_58 , & V_42 , 1 ) ;
if ( V_13 < 0 ) {
F_11 ( L_35 ) ;
goto V_26;
}
V_13 = F_24 ( V_58 , V_29 -> V_67 ,
strlen ( V_29 -> V_67 ) ) ;
if ( V_13 < 0 ) {
F_11 ( L_54
L_55 ) ;
goto V_26;
}
V_13 = F_25 ( V_58 , V_47 , V_60 ,
V_43 ) ;
if ( V_13 < 0 ) {
F_11 ( L_56 ) ;
goto V_26;
}
* V_41 = sprintf ( V_40 , L_57 , V_29 -> V_68 ) ;
* V_41 += 1 ;
F_4 ( L_58 , V_29 -> V_68 ) ;
F_5 ( V_45 , V_43 , V_44 ) ;
* V_41 += sprintf ( V_40 + * V_41 , L_59 ,
V_45 ) ;
* V_41 += 1 ;
F_4 ( L_60 , V_45 ) ;
V_59 = 0 ;
V_26:
F_27 ( V_58 ) ;
F_28 ( V_56 ) ;
F_13 ( V_19 ) ;
F_13 ( V_47 ) ;
return V_59 ;
}
static int F_29 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
char * V_39 ,
char * V_40 ,
unsigned int * V_41 )
{
struct V_16 * V_17 = V_9 -> V_18 ;
switch ( V_17 -> V_35 ) {
case V_27 :
if ( F_17 ( V_9 , V_29 , V_39 ,
V_40 , V_41 ) < 0 )
return - 1 ;
return 0 ;
default:
F_11 ( L_61 ,
V_17 -> V_35 ) ;
return - 1 ;
}
}
T_2 F_30 (
struct V_8 * V_9 ,
struct V_28 * V_29 ,
char * V_69 ,
char * V_70 ,
int * V_71 ,
int * V_72 )
{
struct V_16 * V_17 = V_9 -> V_18 ;
if ( ! V_17 ) {
V_17 = F_14 ( V_9 , V_29 , V_69 , V_70 , V_72 ) ;
if ( ! V_17 )
return 2 ;
V_17 -> V_73 = V_74 ;
return 0 ;
} else if ( V_17 -> V_73 == V_74 ) {
F_31 ( V_69 , * V_71 ) ;
if ( F_29 ( V_9 , V_29 , V_69 , V_70 ,
V_72 ) < 0 ) {
F_16 ( V_9 ) ;
return 2 ;
}
if ( V_29 -> V_66 )
V_17 -> V_73 = V_75 ;
else
* V_72 = 0 ;
F_16 ( V_9 ) ;
return 1 ;
}
return 2 ;
}

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
static struct V_15 * F_8 (
struct V_8 * V_9 ,
struct V_19 * V_20 ,
const char * V_21 ,
char * V_22 ,
unsigned int * V_23 )
{
struct V_15 * V_16 ;
if ( ! ( V_20 -> V_24 & V_25 ) ||
! ( V_20 -> V_24 & V_26 ) ) {
F_9 ( L_7
L_8 ) ;
return NULL ;
}
V_9 -> V_17 = F_10 ( sizeof( struct V_15 ) , V_27 ) ;
if ( ! V_9 -> V_17 )
return NULL ;
V_16 = V_9 -> V_17 ;
if ( strncmp ( V_21 , L_9 , 8 ) ) {
F_9 ( L_10 ) ;
return NULL ;
}
F_4 ( L_11 ) ;
* V_23 = sprintf ( V_22 , L_9 ) ;
* V_23 += 1 ;
V_16 -> V_28 = V_29 ;
F_4 ( L_12 , V_16 -> V_28 ) ;
V_16 -> V_30 = F_11 ( V_9 ) -> V_31 ++ ;
* V_23 += sprintf ( V_22 + * V_23 , L_13 , V_16 -> V_30 ) ;
* V_23 += 1 ;
F_4 ( L_14 , V_16 -> V_30 ) ;
F_6 ( V_9 , 1 , V_22 , V_23 ) ;
return V_16 ;
}
static void F_12 ( struct V_8 * V_9 )
{
F_13 ( V_9 -> V_17 ) ;
V_9 -> V_17 = NULL ;
}
static int F_14 (
struct V_8 * V_9 ,
struct V_19 * V_20 ,
char * V_32 ,
char * V_33 ,
unsigned int * V_34 )
{
char * V_35 ;
unsigned long V_30 ;
unsigned char V_36 ;
unsigned char V_37 [ V_38 ] ;
unsigned char type , V_39 [ V_38 * 2 + 2 ] ;
unsigned char V_40 [ 10 ] , * V_18 = NULL ;
unsigned char * V_41 = NULL ;
unsigned char V_42 [ V_38 ] ;
unsigned char V_43 [ V_38 ] ;
unsigned char V_44 [ V_45 ] , V_46 [ V_47 ] ;
struct V_15 * V_16 = V_9 -> V_17 ;
struct V_48 * V_49 ;
struct V_50 V_51 ;
struct V_52 V_53 ;
int V_54 = - 1 , V_55 , V_56 ;
memset ( V_40 , 0 , 10 ) ;
memset ( V_44 , 0 , V_45 ) ;
memset ( V_46 , 0 , V_47 ) ;
memset ( V_37 , 0 , V_38 ) ;
memset ( V_39 , 0 , V_38 * 2 + 2 ) ;
memset ( V_42 , 0 , V_38 ) ;
memset ( V_43 , 0 , V_38 ) ;
V_18 = F_10 ( V_57 , V_27 ) ;
if ( ! V_18 ) {
F_9 ( L_15 ) ;
goto V_58;
}
V_41 = F_10 ( V_57 , V_27 ) ;
if ( ! V_41 ) {
F_9 ( L_16 ) ;
goto V_58;
}
if ( F_15 ( V_32 , L_17 , V_45 , V_44 ,
& type ) < 0 ) {
F_9 ( L_18 ) ;
goto V_58;
}
if ( type == V_59 ) {
F_9 ( L_18 ) ;
goto V_58;
}
if ( memcmp ( V_44 , V_20 -> V_60 , strlen ( V_20 -> V_60 ) ) != 0 ) {
F_9 ( L_19 ) ;
goto V_58;
}
F_4 ( L_20 , V_44 ) ;
if ( F_15 ( V_32 , L_21 , V_47 , V_46 ,
& type ) < 0 ) {
F_9 ( L_22 ) ;
goto V_58;
}
if ( type != V_59 ) {
F_9 ( L_22 ) ;
goto V_58;
}
F_4 ( L_23 , V_46 ) ;
F_1 ( V_42 , V_46 , strlen ( V_46 ) ) ;
V_49 = F_16 ( L_24 , 0 , V_61 ) ;
if ( F_17 ( V_49 ) ) {
F_9 ( L_25 ) ;
goto V_58;
}
V_51 . V_49 = V_49 ;
V_51 . V_62 = 0 ;
V_55 = F_18 ( & V_51 ) ;
if ( V_55 < 0 ) {
F_9 ( L_26 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
F_20 ( & V_53 , & V_16 -> V_30 , 1 ) ;
V_55 = F_21 ( & V_51 , & V_53 , 1 ) ;
if ( V_55 < 0 ) {
F_9 ( L_27 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
F_20 ( & V_53 , & V_20 -> V_63 , strlen ( V_20 -> V_63 ) ) ;
V_55 = F_21 ( & V_51 , & V_53 , strlen ( V_20 -> V_63 ) ) ;
if ( V_55 < 0 ) {
F_9 ( L_28 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
F_20 ( & V_53 , V_16 -> V_18 , V_14 ) ;
V_55 = F_21 ( & V_51 , & V_53 , V_14 ) ;
if ( V_55 < 0 ) {
F_9 ( L_29 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
V_55 = F_22 ( & V_51 , V_43 ) ;
if ( V_55 < 0 ) {
F_9 ( L_30 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
F_19 ( V_49 ) ;
F_5 ( V_39 , V_43 , V_38 ) ;
F_4 ( L_31 , V_39 ) ;
if ( memcmp ( V_43 , V_42 , V_38 ) != 0 ) {
F_4 ( L_32 ) ;
goto V_58;
} else
F_4 ( L_33
L_34 ) ;
if ( ! V_20 -> V_64 ) {
F_13 ( V_18 ) ;
F_13 ( V_41 ) ;
return 0 ;
}
if ( F_15 ( V_32 , L_35 , 10 , V_40 , & type ) < 0 ) {
F_9 ( L_36 ) ;
goto V_58;
}
if ( type == V_59 )
V_30 = F_23 ( & V_40 [ 2 ] , & V_35 , 0 ) ;
else
V_30 = F_23 ( V_40 , & V_35 , 0 ) ;
if ( V_30 > 255 ) {
F_9 ( L_37 , V_30 ) ;
goto V_58;
}
F_4 ( L_38 , V_30 ) ;
if ( F_15 ( V_32 , L_39 , V_57 ,
V_18 , & type ) < 0 ) {
F_9 ( L_40 ) ;
goto V_58;
}
if ( type != V_59 ) {
F_9 ( L_40 ) ;
goto V_58;
}
F_4 ( L_41 , V_18 ) ;
V_56 = F_1 ( V_41 , V_18 ,
strlen ( V_18 ) ) ;
if ( ! V_56 ) {
F_9 ( L_42 ) ;
goto V_58;
}
V_49 = F_16 ( L_24 , 0 , V_61 ) ;
if ( F_17 ( V_49 ) ) {
F_9 ( L_25 ) ;
goto V_58;
}
V_51 . V_49 = V_49 ;
V_51 . V_62 = 0 ;
V_55 = F_18 ( & V_51 ) ;
if ( V_55 < 0 ) {
F_9 ( L_26 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
V_36 = V_30 ;
F_20 ( & V_53 , & V_36 , 1 ) ;
V_55 = F_21 ( & V_51 , & V_53 , 1 ) ;
if ( V_55 < 0 ) {
F_9 ( L_27 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
F_20 ( & V_53 , V_20 -> V_65 ,
strlen ( V_20 -> V_65 ) ) ;
V_55 = F_21 ( & V_51 , & V_53 , strlen ( V_20 -> V_65 ) ) ;
if ( V_55 < 0 ) {
F_9 ( L_43
L_44 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
F_20 ( & V_53 , V_41 , V_56 ) ;
V_55 = F_21 ( & V_51 , & V_53 , V_56 ) ;
if ( V_55 < 0 ) {
F_9 ( L_45 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
V_55 = F_22 ( & V_51 , V_37 ) ;
if ( V_55 < 0 ) {
F_9 ( L_46 ) ;
F_19 ( V_49 ) ;
goto V_58;
}
F_19 ( V_49 ) ;
* V_34 = sprintf ( V_33 , L_47 , V_20 -> V_66 ) ;
* V_34 += 1 ;
F_4 ( L_48 , V_20 -> V_66 ) ;
F_5 ( V_39 , V_37 , V_38 ) ;
* V_34 += sprintf ( V_33 + * V_34 , L_49 ,
V_39 ) ;
* V_34 += 1 ;
F_4 ( L_50 , V_39 ) ;
V_54 = 0 ;
V_58:
F_13 ( V_18 ) ;
F_13 ( V_41 ) ;
return V_54 ;
}
static int F_24 (
struct V_8 * V_9 ,
struct V_19 * V_20 ,
char * V_32 ,
char * V_33 ,
unsigned int * V_34 )
{
struct V_15 * V_16 = V_9 -> V_17 ;
switch ( V_16 -> V_28 ) {
case V_29 :
if ( F_14 ( V_9 , V_20 , V_32 ,
V_33 , V_34 ) < 0 )
return - 1 ;
return 0 ;
default:
F_9 ( L_51 ,
V_16 -> V_28 ) ;
return - 1 ;
}
}
T_1 F_25 (
struct V_8 * V_9 ,
struct V_19 * V_20 ,
char * V_67 ,
char * V_68 ,
int * V_69 ,
int * V_70 )
{
struct V_15 * V_16 = V_9 -> V_17 ;
if ( ! V_16 ) {
V_16 = F_8 ( V_9 , V_20 , V_67 , V_68 , V_70 ) ;
if ( ! V_16 )
return 2 ;
V_16 -> V_71 = V_72 ;
return 0 ;
} else if ( V_16 -> V_71 == V_72 ) {
F_26 ( V_67 , * V_69 ) ;
if ( F_24 ( V_9 , V_20 , V_67 , V_68 ,
V_70 ) < 0 ) {
F_12 ( V_9 ) ;
return 2 ;
}
if ( V_20 -> V_64 )
V_16 -> V_71 = V_73 ;
else
* V_70 = 0 ;
F_12 ( V_9 ) ;
return 1 ;
}
return 2 ;
}

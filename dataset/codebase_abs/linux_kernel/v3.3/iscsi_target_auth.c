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
static void F_6 ( char * V_8 , int V_9 )
{
long V_10 ;
unsigned V_11 ;
while ( V_9 > 0 ) {
F_7 ( & V_10 , sizeof( long ) ) ;
V_10 = V_10 ^ ( V_10 >> 8 ) ;
V_10 = V_10 ^ ( V_10 >> 4 ) ;
V_11 = V_10 & 0x7 ;
F_7 ( & V_10 , sizeof( long ) ) ;
V_10 = V_10 ^ ( V_10 >> 8 ) ;
V_10 = V_10 ^ ( V_10 >> 5 ) ;
V_11 = ( V_11 << 3 ) | ( V_10 & 0x7 ) ;
F_7 ( & V_10 , sizeof( long ) ) ;
V_10 = V_10 ^ ( V_10 >> 8 ) ;
V_10 = V_10 ^ ( V_10 >> 5 ) ;
V_11 = ( V_11 << 2 ) | ( V_10 & 0x3 ) ;
* V_8 ++ = V_11 ;
V_9 -- ;
}
}
static void F_8 (
struct V_12 * V_13 ,
int V_14 ,
char * V_15 ,
unsigned int * V_16 )
{
unsigned char V_17 [ V_18 * 2 + 1 ] ;
struct V_19 * V_20 = V_13 -> V_21 ;
memset ( V_17 , 0 , V_18 * 2 + 1 ) ;
F_6 ( V_20 -> V_22 , V_18 ) ;
F_5 ( V_17 , V_20 -> V_22 ,
V_18 ) ;
* V_16 += sprintf ( V_15 + * V_16 , L_3 , V_17 ) ;
* V_16 += 1 ;
F_4 ( L_4 , ( V_14 ) ? L_5 : L_6 ,
V_17 ) ;
}
static struct V_19 * F_9 (
struct V_12 * V_13 ,
struct V_23 * V_24 ,
const char * V_25 ,
char * V_26 ,
unsigned int * V_27 )
{
struct V_19 * V_20 ;
if ( ! ( V_24 -> V_28 & V_29 ) ||
! ( V_24 -> V_28 & V_30 ) ) {
F_10 ( L_7
L_8 ) ;
return NULL ;
}
V_13 -> V_21 = F_11 ( sizeof( struct V_19 ) , V_31 ) ;
if ( ! V_13 -> V_21 )
return NULL ;
V_20 = V_13 -> V_21 ;
if ( strncmp ( V_25 , L_9 , 8 ) ) {
F_10 ( L_10 ) ;
return NULL ;
}
F_4 ( L_11 ) ;
* V_27 = sprintf ( V_26 , L_9 ) ;
* V_27 += 1 ;
V_20 -> V_32 = V_33 ;
F_4 ( L_12 , V_20 -> V_32 ) ;
V_20 -> V_34 = F_12 ( V_13 ) -> V_35 ++ ;
* V_27 += sprintf ( V_26 + * V_27 , L_13 , V_20 -> V_34 ) ;
* V_27 += 1 ;
F_4 ( L_14 , V_20 -> V_34 ) ;
F_8 ( V_13 , 1 , V_26 , V_27 ) ;
return V_20 ;
}
static void F_13 ( struct V_12 * V_13 )
{
F_14 ( V_13 -> V_21 ) ;
V_13 -> V_21 = NULL ;
}
static int F_15 (
struct V_12 * V_13 ,
struct V_23 * V_24 ,
char * V_36 ,
char * V_37 ,
unsigned int * V_38 )
{
char * V_39 ;
unsigned long V_34 ;
unsigned char V_40 [ V_41 ] ;
unsigned char type , V_42 [ V_41 * 2 + 2 ] ;
unsigned char V_43 [ 10 ] , * V_22 = NULL ;
unsigned char * V_44 = NULL ;
unsigned char V_45 [ V_41 ] ;
unsigned char V_46 [ V_41 ] ;
unsigned char V_47 [ V_48 ] , V_49 [ V_50 ] ;
struct V_19 * V_20 = V_13 -> V_21 ;
struct V_51 * V_52 ;
struct V_53 V_54 ;
struct V_55 V_56 ;
int V_57 = - 1 , V_58 , V_59 ;
memset ( V_43 , 0 , 10 ) ;
memset ( V_47 , 0 , V_48 ) ;
memset ( V_49 , 0 , V_50 ) ;
memset ( V_40 , 0 , V_41 ) ;
memset ( V_42 , 0 , V_41 * 2 + 2 ) ;
memset ( V_45 , 0 , V_41 ) ;
memset ( V_46 , 0 , V_41 ) ;
V_22 = F_11 ( V_60 , V_31 ) ;
if ( ! V_22 ) {
F_10 ( L_15 ) ;
goto V_61;
}
V_44 = F_11 ( V_60 , V_31 ) ;
if ( ! V_44 ) {
F_10 ( L_16 ) ;
goto V_61;
}
if ( F_16 ( V_36 , L_17 , V_48 , V_47 ,
& type ) < 0 ) {
F_10 ( L_18 ) ;
goto V_61;
}
if ( type == V_62 ) {
F_10 ( L_18 ) ;
goto V_61;
}
if ( memcmp ( V_47 , V_24 -> V_63 , strlen ( V_24 -> V_63 ) ) != 0 ) {
F_10 ( L_19 ) ;
goto V_61;
}
F_4 ( L_20 , V_47 ) ;
if ( F_16 ( V_36 , L_21 , V_50 , V_49 ,
& type ) < 0 ) {
F_10 ( L_22 ) ;
goto V_61;
}
if ( type != V_62 ) {
F_10 ( L_22 ) ;
goto V_61;
}
F_4 ( L_23 , V_49 ) ;
F_1 ( V_45 , V_49 , strlen ( V_49 ) ) ;
V_52 = F_17 ( L_24 , 0 , V_64 ) ;
if ( F_18 ( V_52 ) ) {
F_10 ( L_25 ) ;
goto V_61;
}
V_54 . V_52 = V_52 ;
V_54 . V_65 = 0 ;
V_58 = F_19 ( & V_54 ) ;
if ( V_58 < 0 ) {
F_10 ( L_26 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
F_21 ( & V_56 , & V_20 -> V_34 , 1 ) ;
V_58 = F_22 ( & V_54 , & V_56 , 1 ) ;
if ( V_58 < 0 ) {
F_10 ( L_27 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
F_21 ( & V_56 , & V_24 -> V_66 , strlen ( V_24 -> V_66 ) ) ;
V_58 = F_22 ( & V_54 , & V_56 , strlen ( V_24 -> V_66 ) ) ;
if ( V_58 < 0 ) {
F_10 ( L_28 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
F_21 ( & V_56 , V_20 -> V_22 , V_18 ) ;
V_58 = F_22 ( & V_54 , & V_56 , V_18 ) ;
if ( V_58 < 0 ) {
F_10 ( L_29 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
V_58 = F_23 ( & V_54 , V_46 ) ;
if ( V_58 < 0 ) {
F_10 ( L_30 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
F_20 ( V_52 ) ;
F_5 ( V_42 , V_46 , V_41 ) ;
F_4 ( L_31 , V_42 ) ;
if ( memcmp ( V_46 , V_45 , V_41 ) != 0 ) {
F_4 ( L_32 ) ;
goto V_61;
} else
F_4 ( L_33
L_34 ) ;
if ( ! V_24 -> V_67 ) {
F_14 ( V_22 ) ;
F_14 ( V_44 ) ;
return 0 ;
}
if ( F_16 ( V_36 , L_35 , 10 , V_43 , & type ) < 0 ) {
F_10 ( L_36 ) ;
goto V_61;
}
if ( type == V_62 )
V_34 = F_24 ( & V_43 [ 2 ] , & V_39 , 0 ) ;
else
V_34 = F_24 ( V_43 , & V_39 , 0 ) ;
if ( V_34 > 255 ) {
F_10 ( L_37 , V_34 ) ;
goto V_61;
}
F_4 ( L_38 , V_34 ) ;
if ( F_16 ( V_36 , L_39 , V_60 ,
V_22 , & type ) < 0 ) {
F_10 ( L_40 ) ;
goto V_61;
}
if ( type != V_62 ) {
F_10 ( L_40 ) ;
goto V_61;
}
F_4 ( L_41 , V_22 ) ;
V_59 = F_1 ( V_44 , V_22 ,
strlen ( V_22 ) ) ;
if ( ! V_59 ) {
F_10 ( L_42 ) ;
goto V_61;
}
V_52 = F_17 ( L_24 , 0 , V_64 ) ;
if ( F_18 ( V_52 ) ) {
F_10 ( L_25 ) ;
goto V_61;
}
V_54 . V_52 = V_52 ;
V_54 . V_65 = 0 ;
V_58 = F_19 ( & V_54 ) ;
if ( V_58 < 0 ) {
F_10 ( L_26 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
F_21 ( & V_56 , & V_34 , 1 ) ;
V_58 = F_22 ( & V_54 , & V_56 , 1 ) ;
if ( V_58 < 0 ) {
F_10 ( L_27 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
F_21 ( & V_56 , V_24 -> V_68 ,
strlen ( V_24 -> V_68 ) ) ;
V_58 = F_22 ( & V_54 , & V_56 , strlen ( V_24 -> V_68 ) ) ;
if ( V_58 < 0 ) {
F_10 ( L_43
L_44 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
F_21 ( & V_56 , V_44 , V_59 ) ;
V_58 = F_22 ( & V_54 , & V_56 , V_59 ) ;
if ( V_58 < 0 ) {
F_10 ( L_45 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
V_58 = F_23 ( & V_54 , V_40 ) ;
if ( V_58 < 0 ) {
F_10 ( L_46 ) ;
F_20 ( V_52 ) ;
goto V_61;
}
F_20 ( V_52 ) ;
* V_38 = sprintf ( V_37 , L_47 , V_24 -> V_69 ) ;
* V_38 += 1 ;
F_4 ( L_48 , V_24 -> V_69 ) ;
F_5 ( V_42 , V_40 , V_41 ) ;
* V_38 += sprintf ( V_37 + * V_38 , L_49 ,
V_42 ) ;
* V_38 += 1 ;
F_4 ( L_50 , V_42 ) ;
V_57 = 0 ;
V_61:
F_14 ( V_22 ) ;
F_14 ( V_44 ) ;
return V_57 ;
}
static int F_25 (
struct V_12 * V_13 ,
struct V_23 * V_24 ,
char * V_36 ,
char * V_37 ,
unsigned int * V_38 )
{
struct V_19 * V_20 = V_13 -> V_21 ;
switch ( V_20 -> V_32 ) {
case V_33 :
if ( F_15 ( V_13 , V_24 , V_36 ,
V_37 , V_38 ) < 0 )
return - 1 ;
return 0 ;
default:
F_10 ( L_51 ,
V_20 -> V_32 ) ;
return - 1 ;
}
}
T_1 F_26 (
struct V_12 * V_13 ,
struct V_23 * V_24 ,
char * V_70 ,
char * V_71 ,
int * V_72 ,
int * V_73 )
{
struct V_19 * V_20 = V_13 -> V_21 ;
if ( ! V_20 ) {
V_20 = F_9 ( V_13 , V_24 , V_70 , V_71 , V_73 ) ;
if ( ! V_20 )
return 2 ;
V_20 -> V_74 = V_75 ;
return 0 ;
} else if ( V_20 -> V_74 == V_75 ) {
F_27 ( V_70 , * V_72 ) ;
if ( F_25 ( V_13 , V_24 , V_70 , V_71 ,
V_73 ) < 0 ) {
F_13 ( V_13 ) ;
return 2 ;
}
if ( V_24 -> V_67 )
V_20 -> V_74 = V_76 ;
else
* V_73 = 0 ;
F_13 ( V_13 ) ;
return 1 ;
}
return 2 ;
}

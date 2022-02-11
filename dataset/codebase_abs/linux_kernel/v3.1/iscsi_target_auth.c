static unsigned char F_1 ( unsigned char V_1 [ 2 ] )
{
unsigned char V_2 = 0 ;
if ( ( V_1 [ 0 ] >= 'a' ) && ( V_1 [ 0 ] <= 'f' ) )
V_2 = ( ( V_1 [ 0 ] - 'a' + 10 ) & 0xf ) << 4 ;
else
if ( ( V_1 [ 0 ] >= 'A' ) && ( V_1 [ 0 ] <= 'F' ) )
V_2 = ( ( V_1 [ 0 ] - 'A' + 10 ) & 0xf ) << 4 ;
else
V_2 = ( ( V_1 [ 0 ] - '0' ) & 0xf ) << 4 ;
if ( ( V_1 [ 1 ] >= 'a' ) && ( V_1 [ 1 ] <= 'f' ) )
V_2 |= ( ( V_1 [ 1 ] - 'a' + 10 ) & 0xf ) ;
else
if ( ( V_1 [ 1 ] >= 'A' ) && ( V_1 [ 1 ] <= 'F' ) )
V_2 |= ( ( V_1 [ 1 ] - 'A' + 10 ) & 0xf ) ;
else
V_2 |= ( ( V_1 [ 1 ] - '0' ) & 0xf ) ;
return V_2 ;
}
static int F_2 ( unsigned char * V_3 , unsigned char * V_4 , int V_5 )
{
int V_6 , V_7 = 0 ;
for ( V_6 = 0 ; V_6 < V_5 ; V_6 += 2 ) {
V_3 [ V_7 ++ ] = ( unsigned char ) F_1 ( & V_4 [ V_6 ] ) ;
}
V_3 [ V_7 ] = '\0' ;
return V_7 ;
}
static void F_3 ( char * V_3 , char * V_4 , int V_8 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ ) {
sprintf ( & V_3 [ V_6 * 2 ] , L_1 , ( int ) V_4 [ V_6 ] & 0xff ) ;
}
}
static void F_4 ( char * V_9 , int V_10 )
{
long V_11 ;
unsigned V_12 ;
while ( V_10 > 0 ) {
F_5 ( & V_11 , sizeof( long ) ) ;
V_11 = V_11 ^ ( V_11 >> 8 ) ;
V_11 = V_11 ^ ( V_11 >> 4 ) ;
V_12 = V_11 & 0x7 ;
F_5 ( & V_11 , sizeof( long ) ) ;
V_11 = V_11 ^ ( V_11 >> 8 ) ;
V_11 = V_11 ^ ( V_11 >> 5 ) ;
V_12 = ( V_12 << 3 ) | ( V_11 & 0x7 ) ;
F_5 ( & V_11 , sizeof( long ) ) ;
V_11 = V_11 ^ ( V_11 >> 8 ) ;
V_11 = V_11 ^ ( V_11 >> 5 ) ;
V_12 = ( V_12 << 2 ) | ( V_11 & 0x3 ) ;
* V_9 ++ = V_12 ;
V_10 -- ;
}
}
static void F_6 (
struct V_13 * V_14 ,
int V_15 ,
char * V_16 ,
unsigned int * V_17 )
{
unsigned char V_18 [ V_19 * 2 + 1 ] ;
struct V_20 * V_21 = (struct V_20 * ) V_14 -> V_22 ;
memset ( V_18 , 0 , V_19 * 2 + 1 ) ;
F_4 ( V_21 -> V_23 , V_19 ) ;
F_3 ( V_18 , V_21 -> V_23 ,
V_19 ) ;
* V_17 += sprintf ( V_16 + * V_17 , L_2 , V_18 ) ;
* V_17 += 1 ;
F_7 ( L_3 , ( V_15 ) ? L_4 : L_5 ,
V_18 ) ;
}
static struct V_20 * F_8 (
struct V_13 * V_14 ,
struct V_24 * V_25 ,
const char * V_26 ,
char * V_27 ,
unsigned int * V_28 )
{
struct V_20 * V_21 ;
if ( ! ( V_25 -> V_29 & V_30 ) ||
! ( V_25 -> V_29 & V_31 ) ) {
F_9 ( L_6
L_7 ) ;
return NULL ;
}
V_14 -> V_22 = F_10 ( sizeof( struct V_20 ) , V_32 ) ;
if ( ! V_14 -> V_22 )
return NULL ;
V_21 = (struct V_20 * ) V_14 -> V_22 ;
if ( strncmp ( V_26 , L_8 , 8 ) ) {
F_9 ( L_9 ) ;
return NULL ;
}
F_7 ( L_10 ) ;
* V_28 = sprintf ( V_27 , L_8 ) ;
* V_28 += 1 ;
V_21 -> V_33 = V_34 ;
F_7 ( L_11 , V_21 -> V_33 ) ;
V_21 -> V_35 = F_11 ( V_14 ) -> V_36 ++ ;
* V_28 += sprintf ( V_27 + * V_28 , L_12 , V_21 -> V_35 ) ;
* V_28 += 1 ;
F_7 ( L_13 , V_21 -> V_35 ) ;
F_6 ( V_14 , 1 , V_27 , V_28 ) ;
return V_21 ;
}
static void F_12 ( struct V_13 * V_14 )
{
F_13 ( V_14 -> V_22 ) ;
V_14 -> V_22 = NULL ;
}
static int F_14 (
struct V_13 * V_14 ,
struct V_24 * V_25 ,
char * V_37 ,
char * V_38 ,
unsigned int * V_39 )
{
char * V_40 ;
unsigned char V_35 , V_41 [ V_42 ] ;
unsigned char type , V_43 [ V_42 * 2 + 2 ] ;
unsigned char V_44 [ 10 ] , * V_23 = NULL ;
unsigned char * V_45 = NULL ;
unsigned char V_46 [ V_42 ] ;
unsigned char V_47 [ V_42 ] ;
unsigned char V_48 [ V_49 ] , V_50 [ V_51 ] ;
struct V_20 * V_21 = (struct V_20 * ) V_14 -> V_22 ;
struct V_52 * V_53 ;
struct V_54 V_55 ;
struct V_56 V_57 ;
int V_58 = - 1 , V_59 , V_60 ;
memset ( V_44 , 0 , 10 ) ;
memset ( V_48 , 0 , V_49 ) ;
memset ( V_50 , 0 , V_51 ) ;
memset ( V_41 , 0 , V_42 ) ;
memset ( V_43 , 0 , V_42 * 2 + 2 ) ;
memset ( V_46 , 0 , V_42 ) ;
memset ( V_47 , 0 , V_42 ) ;
V_23 = F_10 ( V_61 , V_32 ) ;
if ( ! V_23 ) {
F_9 ( L_14 ) ;
goto V_62;
}
V_45 = F_10 ( V_61 , V_32 ) ;
if ( ! V_45 ) {
F_9 ( L_15 ) ;
goto V_62;
}
if ( F_15 ( V_37 , L_16 , V_49 , V_48 ,
& type ) < 0 ) {
F_9 ( L_17 ) ;
goto V_62;
}
if ( type == V_63 ) {
F_9 ( L_17 ) ;
goto V_62;
}
if ( memcmp ( V_48 , V_25 -> V_64 , strlen ( V_25 -> V_64 ) ) != 0 ) {
F_9 ( L_18 ) ;
goto V_62;
}
F_7 ( L_19 , V_48 ) ;
if ( F_15 ( V_37 , L_20 , V_51 , V_50 ,
& type ) < 0 ) {
F_9 ( L_21 ) ;
goto V_62;
}
if ( type != V_63 ) {
F_9 ( L_21 ) ;
goto V_62;
}
F_7 ( L_22 , V_50 ) ;
F_2 ( V_46 , V_50 , strlen ( V_50 ) ) ;
V_53 = F_16 ( L_23 , 0 , V_65 ) ;
if ( F_17 ( V_53 ) ) {
F_9 ( L_24 ) ;
goto V_62;
}
V_55 . V_53 = V_53 ;
V_55 . V_66 = 0 ;
V_59 = F_18 ( & V_55 ) ;
if ( V_59 < 0 ) {
F_9 ( L_25 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
F_20 ( & V_57 , ( void * ) & V_21 -> V_35 , 1 ) ;
V_59 = F_21 ( & V_55 , & V_57 , 1 ) ;
if ( V_59 < 0 ) {
F_9 ( L_26 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
F_20 ( & V_57 , ( void * ) & V_25 -> V_67 , strlen ( V_25 -> V_67 ) ) ;
V_59 = F_21 ( & V_55 , & V_57 , strlen ( V_25 -> V_67 ) ) ;
if ( V_59 < 0 ) {
F_9 ( L_27 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
F_20 ( & V_57 , ( void * ) V_21 -> V_23 , V_19 ) ;
V_59 = F_21 ( & V_55 , & V_57 , V_19 ) ;
if ( V_59 < 0 ) {
F_9 ( L_28 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
V_59 = F_22 ( & V_55 , V_47 ) ;
if ( V_59 < 0 ) {
F_9 ( L_29 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
F_19 ( V_53 ) ;
F_3 ( V_43 , V_47 , V_42 ) ;
F_7 ( L_30 , V_43 ) ;
if ( memcmp ( V_47 , V_46 , V_42 ) != 0 ) {
F_7 ( L_31 ) ;
goto V_62;
} else
F_7 ( L_32
L_33 ) ;
if ( ! V_25 -> V_68 ) {
F_13 ( V_23 ) ;
F_13 ( V_45 ) ;
return 0 ;
}
if ( F_15 ( V_37 , L_34 , 10 , V_44 , & type ) < 0 ) {
F_9 ( L_35 ) ;
goto V_62;
}
if ( type == V_63 )
V_35 = ( unsigned char ) F_23 ( ( char * ) & V_44 [ 2 ] ,
& V_40 , 0 ) ;
else
V_35 = ( unsigned char ) F_23 ( V_44 , & V_40 , 0 ) ;
F_7 ( L_36 , V_35 ) ;
if ( F_15 ( V_37 , L_37 , V_61 ,
V_23 , & type ) < 0 ) {
F_9 ( L_38 ) ;
goto V_62;
}
if ( type != V_63 ) {
F_9 ( L_38 ) ;
goto V_62;
}
F_7 ( L_39 , V_23 ) ;
V_60 = F_2 ( V_45 , V_23 ,
strlen ( V_23 ) ) ;
if ( ! V_60 ) {
F_9 ( L_40 ) ;
goto V_62;
}
V_53 = F_16 ( L_23 , 0 , V_65 ) ;
if ( F_17 ( V_53 ) ) {
F_9 ( L_24 ) ;
goto V_62;
}
V_55 . V_53 = V_53 ;
V_55 . V_66 = 0 ;
V_59 = F_18 ( & V_55 ) ;
if ( V_59 < 0 ) {
F_9 ( L_25 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
F_20 ( & V_57 , ( void * ) & V_35 , 1 ) ;
V_59 = F_21 ( & V_55 , & V_57 , 1 ) ;
if ( V_59 < 0 ) {
F_9 ( L_26 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
F_20 ( & V_57 , ( void * ) V_25 -> V_69 ,
strlen ( V_25 -> V_69 ) ) ;
V_59 = F_21 ( & V_55 , & V_57 , strlen ( V_25 -> V_69 ) ) ;
if ( V_59 < 0 ) {
F_9 ( L_41
L_42 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
F_20 ( & V_57 , ( void * ) V_45 , V_60 ) ;
V_59 = F_21 ( & V_55 , & V_57 , V_60 ) ;
if ( V_59 < 0 ) {
F_9 ( L_43 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
V_59 = F_22 ( & V_55 , V_41 ) ;
if ( V_59 < 0 ) {
F_9 ( L_44 ) ;
F_19 ( V_53 ) ;
goto V_62;
}
F_19 ( V_53 ) ;
* V_39 = sprintf ( V_38 , L_45 , V_25 -> V_70 ) ;
* V_39 += 1 ;
F_7 ( L_46 , V_25 -> V_70 ) ;
F_3 ( V_43 , V_41 , V_42 ) ;
* V_39 += sprintf ( V_38 + * V_39 , L_47 ,
V_43 ) ;
* V_39 += 1 ;
F_7 ( L_48 , V_43 ) ;
V_58 = 0 ;
V_62:
F_13 ( V_23 ) ;
F_13 ( V_45 ) ;
return V_58 ;
}
static int F_24 (
struct V_13 * V_14 ,
struct V_24 * V_25 ,
char * V_37 ,
char * V_38 ,
unsigned int * V_39 )
{
struct V_20 * V_21 = (struct V_20 * ) V_14 -> V_22 ;
switch ( V_21 -> V_33 ) {
case V_34 :
if ( F_14 ( V_14 , V_25 , V_37 ,
V_38 , V_39 ) < 0 )
return - 1 ;
return 0 ;
default:
F_9 ( L_49 ,
V_21 -> V_33 ) ;
return - 1 ;
}
}
T_1 F_25 (
struct V_13 * V_14 ,
struct V_24 * V_25 ,
char * V_71 ,
char * V_72 ,
int * V_73 ,
int * V_74 )
{
struct V_20 * V_21 = (struct V_20 * ) V_14 -> V_22 ;
if ( ! V_21 ) {
V_21 = F_8 ( V_14 , V_25 , V_71 , V_72 , V_74 ) ;
if ( ! V_21 )
return 2 ;
V_21 -> V_75 = V_76 ;
return 0 ;
} else if ( V_21 -> V_75 == V_76 ) {
F_26 ( V_71 , * V_73 ) ;
if ( F_24 ( V_14 , V_25 , V_71 , V_72 ,
V_74 ) < 0 ) {
F_12 ( V_14 ) ;
return 2 ;
}
if ( V_25 -> V_68 )
V_21 -> V_75 = V_77 ;
else
* V_74 = 0 ;
F_12 ( V_14 ) ;
return 1 ;
}
return 2 ;
}

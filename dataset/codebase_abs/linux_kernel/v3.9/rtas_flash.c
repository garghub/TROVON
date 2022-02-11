static int F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 ;
int V_4 ;
unsigned long V_5 , V_6 ;
V_6 = 0 ;
for ( V_3 = V_2 ; V_3 ; V_3 = V_3 -> V_7 ) {
for ( V_4 = 0 ; V_4 < V_3 -> V_8 ; V_4 ++ ) {
if ( V_3 -> V_9 [ V_4 ] . V_10 == NULL ) {
return V_11 ;
}
V_5 = V_3 -> V_9 [ V_4 ] . V_12 ;
if ( V_5 <= 0 || V_5 > V_13 ) {
return V_14 ;
}
V_6 += V_5 ;
}
}
if ( V_6 < ( 256 << 10 ) ) {
if ( V_6 < 2 )
return V_15 ;
}
F_2 ( V_16 L_1 , V_6 ) ;
return V_17 ;
}
static void F_3 ( struct V_1 * V_3 )
{
struct V_1 * V_7 ;
int V_4 ;
while ( V_3 ) {
for ( V_4 = 0 ; V_4 < V_3 -> V_8 ; V_4 ++ )
F_4 ( V_18 , V_3 -> V_9 [ V_4 ] . V_10 ) ;
V_7 = V_3 -> V_7 ;
F_4 ( V_18 , V_3 ) ;
V_3 = V_7 ;
}
}
static int F_5 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_21 * V_22 = F_6 ( F_7 ( V_20 ) ) ;
struct V_23 * V_24 ;
V_24 = (struct V_23 * ) V_22 -> V_10 ;
if ( V_24 -> V_2 ) {
if ( V_25 ) {
F_3 ( V_25 ) ;
V_25 = NULL ;
}
if ( V_24 -> V_26 != V_27 )
V_24 -> V_26 = F_1 ( V_24 -> V_2 ) ;
if ( V_24 -> V_26 == V_17 )
V_25 = V_24 -> V_2 ;
else
F_3 ( V_24 -> V_2 ) ;
V_24 -> V_2 = NULL ;
}
F_8 ( & V_22 -> V_28 ) ;
return 0 ;
}
static void F_9 ( int V_26 , char * V_29 )
{
char * V_30 ;
switch ( V_26 ) {
case V_27 :
V_30 = L_2 ;
break;
case V_15 :
V_30 = L_3 ;
break;
case V_31 :
V_30 = L_4 ;
break;
case V_14 :
V_30 = L_5 ;
break;
case V_11 :
V_30 = L_6 ;
break;
case V_17 :
V_30 = L_7 ;
break;
default:
sprintf ( V_29 , L_8 , V_26 ) ;
return;
}
strcpy ( V_29 , V_30 ) ;
}
static T_1 F_10 ( struct V_20 * V_20 , char T_2 * V_29 ,
T_3 V_28 , T_4 * V_32 )
{
struct V_21 * V_22 = F_6 ( F_7 ( V_20 ) ) ;
struct V_23 * V_24 ;
char V_30 [ V_33 ] ;
V_24 = V_22 -> V_10 ;
if ( ! strcmp ( V_22 -> V_34 , V_35 ) ) {
F_9 ( V_24 -> V_26 , V_30 ) ;
} else {
sprintf ( V_30 , L_9 , V_24 -> V_26 ) ;
}
return F_11 ( V_29 , V_28 , V_32 , V_30 , strlen ( V_30 ) ) ;
}
void F_12 ( void * V_36 )
{
memset ( V_36 , 0 , V_13 ) ;
}
static T_1 F_13 ( struct V_20 * V_20 , const char T_2 * V_37 ,
T_3 V_28 , T_4 * V_38 )
{
struct V_21 * V_22 = F_6 ( F_7 ( V_20 ) ) ;
struct V_23 * V_24 ;
char * V_39 ;
int V_40 ;
struct V_1 * V_41 ;
V_24 = (struct V_23 * ) V_22 -> V_10 ;
if ( V_24 -> V_26 == V_27 || V_28 == 0 )
return V_28 ;
if ( V_24 -> V_2 == NULL ) {
V_24 -> V_2 = F_14 ( V_18 , V_42 ) ;
if ( ! V_24 -> V_2 )
return - V_43 ;
}
V_41 = V_24 -> V_2 ;
while ( V_41 -> V_7 )
V_41 = V_41 -> V_7 ;
V_40 = V_41 -> V_8 ;
if ( V_40 == V_44 ) {
V_41 -> V_7 = F_14 ( V_18 , V_42 ) ;
if ( ! V_41 -> V_7 )
return - V_43 ;
V_41 = V_41 -> V_7 ;
V_40 = 0 ;
}
if ( V_28 > V_13 )
V_28 = V_13 ;
V_39 = F_14 ( V_18 , V_42 ) ;
if ( ! V_39 )
return - V_43 ;
if( F_15 ( V_39 , V_37 , V_28 ) ) {
F_4 ( V_18 , V_39 ) ;
return - V_45 ;
}
V_41 -> V_9 [ V_40 ] . V_10 = V_39 ;
V_41 -> V_9 [ V_40 ] . V_12 = V_28 ;
V_41 -> V_8 ++ ;
return V_28 ;
}
static int F_16 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
F_17 ( & V_46 ) ;
if ( F_18 ( & V_22 -> V_28 ) > 2 ) {
F_19 ( & V_46 ) ;
return - V_47 ;
}
F_20 ( & V_22 -> V_28 ) ;
F_19 ( & V_46 ) ;
return 0 ;
}
static int F_21 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
F_8 ( & V_22 -> V_28 ) ;
return 0 ;
}
static void F_22 ( struct V_48 * V_49 )
{
T_5 V_50 ;
do {
V_50 = F_23 ( F_24 ( L_10 ) , 1 ,
1 , NULL , V_49 -> V_51 ) ;
} while ( F_25 ( V_50 ) );
V_49 -> V_26 = V_50 ;
}
static T_1 F_26 ( struct V_20 * V_20 , char T_2 * V_29 ,
T_3 V_28 , T_4 * V_32 )
{
struct V_21 * V_22 = F_6 ( F_7 ( V_20 ) ) ;
struct V_48 * V_49 ;
char V_30 [ V_33 ] ;
int V_52 ;
V_49 = V_22 -> V_10 ;
if ( V_49 == NULL )
return 0 ;
V_52 = sprintf ( V_30 , L_9 , V_49 -> V_26 ) ;
return F_11 ( V_29 , V_28 , V_32 , V_30 , V_52 ) ;
}
static T_1 F_27 ( struct V_20 * V_20 , const char T_2 * V_29 ,
T_3 V_28 , T_4 * V_38 )
{
struct V_21 * V_22 = F_6 ( F_7 ( V_20 ) ) ;
struct V_48 * V_49 ;
const char V_53 [] = L_11 ;
const char V_54 [] = L_12 ;
char V_55 [ 10 ] ;
int V_51 ;
V_49 = (struct V_48 * ) V_22 -> V_10 ;
if ( ( V_49 -> V_26 == V_56 ) || ( V_28 == 0 ) )
return V_28 ;
V_51 = - 1 ;
if ( V_29 ) {
if ( V_28 > 9 ) V_28 = 9 ;
if ( F_15 ( V_55 , V_29 , V_28 ) ) {
return - V_45 ;
}
if ( strncmp ( V_55 , V_53 , strlen ( V_53 ) ) == 0 )
V_51 = V_57 ;
else if ( strncmp ( V_55 , V_54 , strlen ( V_54 ) ) == 0 )
V_51 = V_58 ;
}
if ( V_51 == - 1 )
return - V_59 ;
V_49 -> V_51 = V_51 ;
F_22 ( V_49 ) ;
return V_28 ;
}
static void F_28 ( struct V_60 * V_49 )
{
int V_61 = F_24 ( L_13 ) ;
int V_62 ;
T_5 V_50 ;
V_50 = 0 ;
do {
F_17 ( & V_63 ) ;
memcpy ( V_64 , V_49 -> V_29 , V_65 ) ;
V_50 = F_23 ( V_61 , 2 , 2 , & V_62 ,
( V_66 ) F_29 ( V_64 ) , V_49 -> V_67 ) ;
memcpy ( V_49 -> V_29 , V_64 , V_65 ) ;
F_19 ( & V_63 ) ;
} while ( F_25 ( V_50 ) );
V_49 -> V_26 = V_50 ;
V_49 -> V_62 = V_62 ;
}
static int F_30 ( struct V_60 * V_49 ,
char * V_30 )
{
int V_68 ;
if ( V_49 -> V_26 >= V_69 ) {
V_68 = sprintf ( V_30 , L_9 , V_49 -> V_62 ) ;
if ( ( V_49 -> V_62 >= V_70 ) ||
( V_49 -> V_62 == V_69 ) )
V_68 += sprintf ( V_30 + V_68 , L_14 , V_49 -> V_29 ) ;
} else {
V_68 = sprintf ( V_30 , L_9 , V_49 -> V_26 ) ;
}
return V_68 ;
}
static T_1 F_31 ( struct V_20 * V_20 , char T_2 * V_29 ,
T_3 V_28 , T_4 * V_32 )
{
struct V_21 * V_22 = F_6 ( F_7 ( V_20 ) ) ;
struct V_60 * V_49 ;
char V_30 [ V_33 ] ;
int V_52 ;
V_49 = V_22 -> V_10 ;
V_52 = F_30 ( V_49 , V_30 ) ;
return F_11 ( V_29 , V_28 , V_32 , V_30 , V_52 ) ;
}
static T_1 F_32 ( struct V_20 * V_20 , const char T_2 * V_29 ,
T_3 V_28 , T_4 * V_38 )
{
struct V_21 * V_22 = F_6 ( F_7 ( V_20 ) ) ;
struct V_60 * V_49 ;
int V_50 ;
V_49 = (struct V_60 * ) V_22 -> V_10 ;
if ( V_22 -> V_10 == NULL ) {
V_22 -> V_10 = F_33 ( sizeof( struct V_60 ) ,
V_42 ) ;
if ( V_22 -> V_10 == NULL )
return - V_43 ;
}
if ( ( * V_38 >= V_65 ) ||
( V_49 -> V_26 == V_71 ) ) {
* V_38 += V_28 ;
return V_28 ;
}
if ( * V_38 + V_28 >= V_65 ) {
V_28 = V_65 - * V_38 ;
V_49 -> V_26 = V_72 ;
} else {
V_49 -> V_26 = V_73 ;
}
if ( ! F_34 ( V_74 , V_29 , V_28 ) ) {
V_50 = - V_45 ;
goto V_75;
}
if ( F_15 ( V_49 -> V_29 + * V_38 , V_29 , V_28 ) ) {
V_50 = - V_45 ;
goto V_75;
}
* V_38 += V_28 ;
V_50 = V_28 ;
V_75:
if ( V_50 < 0 ) {
F_35 ( V_22 -> V_10 ) ;
V_22 -> V_10 = NULL ;
}
return V_50 ;
}
static int F_36 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_21 * V_22 = F_6 ( F_7 ( V_20 ) ) ;
struct V_60 * V_49 ;
V_49 = (struct V_60 * ) V_22 -> V_10 ;
if ( V_49 -> V_26 == V_72 ) {
V_49 -> V_67 = V_65 ;
F_28 ( V_49 ) ;
}
F_8 ( & V_22 -> V_28 ) ;
return 0 ;
}
static void F_37 ( int V_76 )
{
unsigned long V_6 ;
struct V_1 * V_3 , * V_7 , * V_2 ;
unsigned long V_77 ;
int V_4 , V_26 , V_78 ;
if ( V_25 == NULL )
return;
if ( V_76 != V_79 ) {
F_2 ( V_80 L_15 ) ;
F_2 ( V_80 L_16 ) ;
return;
}
V_78 = F_24 ( L_17 ) ;
if ( V_78 == V_81 ) {
F_2 ( V_80 L_18
L_19 ) ;
F_2 ( V_80 L_20 ) ;
return;
}
F_38 () ;
F_17 ( & V_63 ) ;
V_2 = (struct V_1 * ) & V_64 [ 0 ] ;
V_2 -> V_8 = 0 ;
V_2 -> V_7 = V_25 ;
V_77 = F_29 ( V_2 ) ;
if ( V_77 >= 4UL * 1024 * 1024 * 1024 ) {
F_2 ( V_80 L_21 ) ;
F_19 ( & V_63 ) ;
return;
}
F_2 ( V_80 L_22 ) ;
V_25 = NULL ;
V_6 = 0 ;
for ( V_3 = V_2 ; V_3 ; V_3 = V_7 ) {
for ( V_4 = 0 ; V_4 < V_3 -> V_8 ; V_4 ++ ) {
V_3 -> V_9 [ V_4 ] . V_10 = ( char * ) F_29 ( V_3 -> V_9 [ V_4 ] . V_10 ) ;
V_6 += V_3 -> V_9 [ V_4 ] . V_12 ;
}
V_7 = V_3 -> V_7 ;
if ( V_3 -> V_7 )
V_3 -> V_7 = (struct V_1 * ) F_29 ( V_3 -> V_7 ) ;
else
V_3 -> V_7 = NULL ;
V_3 -> V_8 = ( V_82 << 56 ) | ( ( V_3 -> V_8 + 1 ) * 16 ) ;
}
F_2 ( V_80 L_23 , V_6 ) ;
F_2 ( V_80 L_24 ) ;
F_39 ( L_25 , 0x0 ) ;
F_39 ( L_26 , 0x0 ) ;
F_2 ( V_80 L_27 ) ;
V_26 = F_23 ( V_78 , 1 , 1 , NULL , V_77 ) ;
switch ( V_26 ) {
case 0 :
F_2 ( V_80 L_28 ) ;
break;
case - 1 :
F_2 ( V_80 L_29 ) ;
break;
case - 3 :
F_2 ( V_80 L_30 ) ;
break;
case - 4 :
F_2 ( V_80 L_31 ) ;
break;
default:
F_2 ( V_80 L_32 , V_26 ) ;
break;
}
F_19 ( & V_63 ) ;
}
static void F_40 ( struct V_21 * V_22 )
{
if ( V_22 ) {
F_35 ( V_22 -> V_10 ) ;
F_41 ( V_22 -> V_34 , V_22 -> V_83 ) ;
}
}
static int F_42 ( const char * V_84 ,
T_3 V_67 ,
struct V_21 * V_22 )
{
int * V_26 ;
int V_61 ;
V_22 -> V_10 = F_43 ( V_67 , V_42 ) ;
if ( V_22 -> V_10 == NULL )
return - V_43 ;
V_26 = ( int * ) V_22 -> V_10 ;
V_61 = F_24 ( V_84 ) ;
if ( V_61 == V_81 )
* V_26 = V_27 ;
else
* V_26 = V_15 ;
return 0 ;
}
static struct V_21 * F_44 ( const char * V_85 ,
const struct V_86 * V_87 )
{
return F_45 ( V_85 , V_88 | V_89 , NULL , V_87 ) ;
}
static int T_6 F_46 ( void )
{
int V_50 ;
if ( F_24 ( L_17 ) ==
V_81 ) {
F_47 ( L_33 ) ;
return 1 ;
}
V_90 = F_44 ( L_34
V_35 ,
& V_91 ) ;
if ( V_90 == NULL ) {
V_50 = - V_43 ;
goto V_92;
}
V_50 = F_42 ( L_17 ,
sizeof( struct V_23 ) ,
V_90 ) ;
if ( V_50 != 0 )
goto V_92;
V_93 = F_44 ( L_34
V_94 ,
& V_91 ) ;
if ( V_93 == NULL ) {
V_50 = - V_43 ;
goto V_92;
}
V_50 = F_42 ( L_17 ,
sizeof( struct V_23 ) ,
V_93 ) ;
if ( V_50 != 0 )
goto V_92;
V_95 = F_44 ( L_34 V_96 ,
& V_97 ) ;
if ( V_95 == NULL ) {
V_50 = - V_43 ;
goto V_92;
}
V_50 = F_42 ( L_13 ,
sizeof( struct V_60 ) ,
V_95 ) ;
if ( V_50 != 0 )
goto V_92;
V_98 = F_44 ( L_34 V_99 ,
& V_100 ) ;
if ( V_98 == NULL ) {
V_50 = - V_43 ;
goto V_92;
}
V_50 = F_42 ( L_10 ,
sizeof( struct V_48 ) ,
V_98 ) ;
if ( V_50 != 0 )
goto V_92;
V_101 = F_37 ;
V_18 = F_48 ( L_35 ,
V_13 , V_13 , 0 ,
F_12 ) ;
if ( ! V_18 ) {
F_2 ( V_102 L_36 ,
V_103 ) ;
V_50 = - V_43 ;
goto V_92;
}
return 0 ;
V_92:
F_40 ( V_90 ) ;
F_40 ( V_93 ) ;
F_40 ( V_95 ) ;
F_40 ( V_98 ) ;
return V_50 ;
}
static void T_7 F_49 ( void )
{
V_101 = NULL ;
if ( V_18 )
F_50 ( V_18 ) ;
F_40 ( V_90 ) ;
F_40 ( V_93 ) ;
F_40 ( V_95 ) ;
F_40 ( V_98 ) ;
}

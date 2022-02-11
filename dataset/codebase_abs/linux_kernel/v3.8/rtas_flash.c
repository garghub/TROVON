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
struct V_21 * V_22 = F_6 ( V_20 -> V_23 . V_24 -> V_25 ) ;
struct V_26 * V_27 ;
V_27 = (struct V_26 * ) V_22 -> V_10 ;
if ( V_27 -> V_2 ) {
if ( V_28 ) {
F_3 ( V_28 ) ;
V_28 = NULL ;
}
if ( V_27 -> V_29 != V_30 )
V_27 -> V_29 = F_1 ( V_27 -> V_2 ) ;
if ( V_27 -> V_29 == V_17 )
V_28 = V_27 -> V_2 ;
else
F_3 ( V_27 -> V_2 ) ;
V_27 -> V_2 = NULL ;
}
F_7 ( & V_22 -> V_31 ) ;
return 0 ;
}
static void F_8 ( int V_29 , char * V_32 )
{
char * V_33 ;
switch ( V_29 ) {
case V_30 :
V_33 = L_2 ;
break;
case V_15 :
V_33 = L_3 ;
break;
case V_34 :
V_33 = L_4 ;
break;
case V_14 :
V_33 = L_5 ;
break;
case V_11 :
V_33 = L_6 ;
break;
case V_17 :
V_33 = L_7 ;
break;
default:
sprintf ( V_32 , L_8 , V_29 ) ;
return;
}
strcpy ( V_32 , V_33 ) ;
}
static T_1 F_9 ( struct V_20 * V_20 , char T_2 * V_32 ,
T_3 V_31 , T_4 * V_35 )
{
struct V_21 * V_22 = F_6 ( V_20 -> V_23 . V_24 -> V_25 ) ;
struct V_26 * V_27 ;
char V_33 [ V_36 ] ;
V_27 = V_22 -> V_10 ;
if ( ! strcmp ( V_22 -> V_37 , V_38 ) ) {
F_8 ( V_27 -> V_29 , V_33 ) ;
} else {
sprintf ( V_33 , L_9 , V_27 -> V_29 ) ;
}
return F_10 ( V_32 , V_31 , V_35 , V_33 , strlen ( V_33 ) ) ;
}
void F_11 ( void * V_39 )
{
memset ( V_39 , 0 , V_13 ) ;
}
static T_1 F_12 ( struct V_20 * V_20 , const char T_2 * V_40 ,
T_3 V_31 , T_4 * V_41 )
{
struct V_21 * V_22 = F_6 ( V_20 -> V_23 . V_24 -> V_25 ) ;
struct V_26 * V_27 ;
char * V_42 ;
int V_43 ;
struct V_1 * V_44 ;
V_27 = (struct V_26 * ) V_22 -> V_10 ;
if ( V_27 -> V_29 == V_30 || V_31 == 0 )
return V_31 ;
if ( V_27 -> V_2 == NULL ) {
V_27 -> V_2 = F_13 ( V_18 , V_45 ) ;
if ( ! V_27 -> V_2 )
return - V_46 ;
}
V_44 = V_27 -> V_2 ;
while ( V_44 -> V_7 )
V_44 = V_44 -> V_7 ;
V_43 = V_44 -> V_8 ;
if ( V_43 == V_47 ) {
V_44 -> V_7 = F_13 ( V_18 , V_45 ) ;
if ( ! V_44 -> V_7 )
return - V_46 ;
V_44 = V_44 -> V_7 ;
V_43 = 0 ;
}
if ( V_31 > V_13 )
V_31 = V_13 ;
V_42 = F_13 ( V_18 , V_45 ) ;
if ( ! V_42 )
return - V_46 ;
if( F_14 ( V_42 , V_40 , V_31 ) ) {
F_4 ( V_18 , V_42 ) ;
return - V_48 ;
}
V_44 -> V_9 [ V_43 ] . V_10 = V_42 ;
V_44 -> V_9 [ V_43 ] . V_12 = V_31 ;
V_44 -> V_8 ++ ;
return V_31 ;
}
static int F_15 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
F_16 ( & V_49 ) ;
if ( F_17 ( & V_22 -> V_31 ) > 2 ) {
F_18 ( & V_49 ) ;
return - V_50 ;
}
F_19 ( & V_22 -> V_31 ) ;
F_18 ( & V_49 ) ;
return 0 ;
}
static int F_20 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_19 ) ;
F_7 ( & V_22 -> V_31 ) ;
return 0 ;
}
static void F_21 ( struct V_51 * V_52 )
{
T_5 V_53 ;
do {
V_53 = F_22 ( F_23 ( L_10 ) , 1 ,
1 , NULL , V_52 -> V_54 ) ;
} while ( F_24 ( V_53 ) );
V_52 -> V_29 = V_53 ;
}
static T_1 F_25 ( struct V_20 * V_20 , char T_2 * V_32 ,
T_3 V_31 , T_4 * V_35 )
{
struct V_21 * V_22 = F_6 ( V_20 -> V_23 . V_24 -> V_25 ) ;
struct V_51 * V_52 ;
char V_33 [ V_36 ] ;
int V_55 ;
V_52 = V_22 -> V_10 ;
if ( V_52 == NULL )
return 0 ;
V_55 = sprintf ( V_33 , L_9 , V_52 -> V_29 ) ;
return F_10 ( V_32 , V_31 , V_35 , V_33 , V_55 ) ;
}
static T_1 F_26 ( struct V_20 * V_20 , const char T_2 * V_32 ,
T_3 V_31 , T_4 * V_41 )
{
struct V_21 * V_22 = F_6 ( V_20 -> V_23 . V_24 -> V_25 ) ;
struct V_51 * V_52 ;
const char V_56 [] = L_11 ;
const char V_57 [] = L_12 ;
char V_58 [ 10 ] ;
int V_54 ;
V_52 = (struct V_51 * ) V_22 -> V_10 ;
if ( ( V_52 -> V_29 == V_59 ) || ( V_31 == 0 ) )
return V_31 ;
V_54 = - 1 ;
if ( V_32 ) {
if ( V_31 > 9 ) V_31 = 9 ;
if ( F_14 ( V_58 , V_32 , V_31 ) ) {
return - V_48 ;
}
if ( strncmp ( V_58 , V_56 , strlen ( V_56 ) ) == 0 )
V_54 = V_60 ;
else if ( strncmp ( V_58 , V_57 , strlen ( V_57 ) ) == 0 )
V_54 = V_61 ;
}
if ( V_54 == - 1 )
return - V_62 ;
V_52 -> V_54 = V_54 ;
F_21 ( V_52 ) ;
return V_31 ;
}
static void F_27 ( struct V_63 * V_52 )
{
int V_64 = F_23 ( L_13 ) ;
int V_65 ;
T_5 V_53 ;
V_53 = 0 ;
do {
F_16 ( & V_66 ) ;
memcpy ( V_67 , V_52 -> V_32 , V_68 ) ;
V_53 = F_22 ( V_64 , 2 , 2 , & V_65 ,
( V_69 ) F_28 ( V_67 ) , V_52 -> V_70 ) ;
memcpy ( V_52 -> V_32 , V_67 , V_68 ) ;
F_18 ( & V_66 ) ;
} while ( F_24 ( V_53 ) );
V_52 -> V_29 = V_53 ;
V_52 -> V_65 = V_65 ;
}
static int F_29 ( struct V_63 * V_52 ,
char * V_33 )
{
int V_71 ;
if ( V_52 -> V_29 >= V_72 ) {
V_71 = sprintf ( V_33 , L_9 , V_52 -> V_65 ) ;
if ( ( V_52 -> V_65 >= V_73 ) ||
( V_52 -> V_65 == V_72 ) )
V_71 += sprintf ( V_33 + V_71 , L_14 , V_52 -> V_32 ) ;
} else {
V_71 = sprintf ( V_33 , L_9 , V_52 -> V_29 ) ;
}
return V_71 ;
}
static T_1 F_30 ( struct V_20 * V_20 , char T_2 * V_32 ,
T_3 V_31 , T_4 * V_35 )
{
struct V_21 * V_22 = F_6 ( V_20 -> V_23 . V_24 -> V_25 ) ;
struct V_63 * V_52 ;
char V_33 [ V_36 ] ;
int V_55 ;
V_52 = V_22 -> V_10 ;
V_55 = F_29 ( V_52 , V_33 ) ;
return F_10 ( V_32 , V_31 , V_35 , V_33 , V_55 ) ;
}
static T_1 F_31 ( struct V_20 * V_20 , const char T_2 * V_32 ,
T_3 V_31 , T_4 * V_41 )
{
struct V_21 * V_22 = F_6 ( V_20 -> V_23 . V_24 -> V_25 ) ;
struct V_63 * V_52 ;
int V_53 ;
V_52 = (struct V_63 * ) V_22 -> V_10 ;
if ( V_22 -> V_10 == NULL ) {
V_22 -> V_10 = F_32 ( sizeof( struct V_63 ) ,
V_45 ) ;
if ( V_22 -> V_10 == NULL )
return - V_46 ;
}
if ( ( * V_41 >= V_68 ) ||
( V_52 -> V_29 == V_74 ) ) {
* V_41 += V_31 ;
return V_31 ;
}
if ( * V_41 + V_31 >= V_68 ) {
V_31 = V_68 - * V_41 ;
V_52 -> V_29 = V_75 ;
} else {
V_52 -> V_29 = V_76 ;
}
if ( ! F_33 ( V_77 , V_32 , V_31 ) ) {
V_53 = - V_48 ;
goto V_78;
}
if ( F_14 ( V_52 -> V_32 + * V_41 , V_32 , V_31 ) ) {
V_53 = - V_48 ;
goto V_78;
}
* V_41 += V_31 ;
V_53 = V_31 ;
V_78:
if ( V_53 < 0 ) {
F_34 ( V_22 -> V_10 ) ;
V_22 -> V_10 = NULL ;
}
return V_53 ;
}
static int F_35 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_21 * V_22 = F_6 ( V_20 -> V_23 . V_24 -> V_25 ) ;
struct V_63 * V_52 ;
V_52 = (struct V_63 * ) V_22 -> V_10 ;
if ( V_52 -> V_29 == V_75 ) {
V_52 -> V_70 = V_68 ;
F_27 ( V_52 ) ;
}
F_7 ( & V_22 -> V_31 ) ;
return 0 ;
}
static void F_36 ( int V_79 )
{
unsigned long V_6 ;
struct V_1 * V_3 , * V_7 , * V_2 ;
unsigned long V_80 ;
int V_4 , V_29 , V_81 ;
if ( V_28 == NULL )
return;
if ( V_79 != V_82 ) {
F_2 ( V_83 L_15 ) ;
F_2 ( V_83 L_16 ) ;
return;
}
V_81 = F_23 ( L_17 ) ;
if ( V_81 == V_84 ) {
F_2 ( V_83 L_18
L_19 ) ;
F_2 ( V_83 L_20 ) ;
return;
}
F_37 () ;
F_16 ( & V_66 ) ;
V_2 = (struct V_1 * ) & V_67 [ 0 ] ;
V_2 -> V_8 = 0 ;
V_2 -> V_7 = V_28 ;
V_80 = F_28 ( V_2 ) ;
if ( V_80 >= 4UL * 1024 * 1024 * 1024 ) {
F_2 ( V_83 L_21 ) ;
F_18 ( & V_66 ) ;
return;
}
F_2 ( V_83 L_22 ) ;
V_28 = NULL ;
V_6 = 0 ;
for ( V_3 = V_2 ; V_3 ; V_3 = V_7 ) {
for ( V_4 = 0 ; V_4 < V_3 -> V_8 ; V_4 ++ ) {
V_3 -> V_9 [ V_4 ] . V_10 = ( char * ) F_28 ( V_3 -> V_9 [ V_4 ] . V_10 ) ;
V_6 += V_3 -> V_9 [ V_4 ] . V_12 ;
}
V_7 = V_3 -> V_7 ;
if ( V_3 -> V_7 )
V_3 -> V_7 = (struct V_1 * ) F_28 ( V_3 -> V_7 ) ;
else
V_3 -> V_7 = NULL ;
V_3 -> V_8 = ( V_85 << 56 ) | ( ( V_3 -> V_8 + 1 ) * 16 ) ;
}
F_2 ( V_83 L_23 , V_6 ) ;
F_2 ( V_83 L_24 ) ;
F_38 ( L_25 , 0x0 ) ;
F_38 ( L_26 , 0x0 ) ;
F_2 ( V_83 L_27 ) ;
V_29 = F_22 ( V_81 , 1 , 1 , NULL , V_80 ) ;
switch ( V_29 ) {
case 0 :
F_2 ( V_83 L_28 ) ;
break;
case - 1 :
F_2 ( V_83 L_29 ) ;
break;
case - 3 :
F_2 ( V_83 L_30 ) ;
break;
case - 4 :
F_2 ( V_83 L_31 ) ;
break;
default:
F_2 ( V_83 L_32 , V_29 ) ;
break;
}
F_18 ( & V_66 ) ;
}
static void F_39 ( struct V_21 * V_22 )
{
if ( V_22 ) {
F_34 ( V_22 -> V_10 ) ;
F_40 ( V_22 -> V_37 , V_22 -> V_86 ) ;
}
}
static int F_41 ( const char * V_87 ,
T_3 V_70 ,
struct V_21 * V_22 )
{
int * V_29 ;
int V_64 ;
V_22 -> V_10 = F_42 ( V_70 , V_45 ) ;
if ( V_22 -> V_10 == NULL )
return - V_46 ;
V_29 = ( int * ) V_22 -> V_10 ;
V_64 = F_23 ( V_87 ) ;
if ( V_64 == V_84 )
* V_29 = V_30 ;
else
* V_29 = V_15 ;
return 0 ;
}
static struct V_21 * F_43 ( const char * V_88 ,
const struct V_89 * V_90 )
{
return F_44 ( V_88 , V_91 | V_92 , NULL , V_90 ) ;
}
static int T_6 F_45 ( void )
{
int V_53 ;
if ( F_23 ( L_17 ) ==
V_84 ) {
F_46 ( L_33 ) ;
return 1 ;
}
V_93 = F_43 ( L_34
V_38 ,
& V_94 ) ;
if ( V_93 == NULL ) {
V_53 = - V_46 ;
goto V_95;
}
V_53 = F_41 ( L_17 ,
sizeof( struct V_26 ) ,
V_93 ) ;
if ( V_53 != 0 )
goto V_95;
V_96 = F_43 ( L_34
V_97 ,
& V_94 ) ;
if ( V_96 == NULL ) {
V_53 = - V_46 ;
goto V_95;
}
V_53 = F_41 ( L_17 ,
sizeof( struct V_26 ) ,
V_96 ) ;
if ( V_53 != 0 )
goto V_95;
V_98 = F_43 ( L_34 V_99 ,
& V_100 ) ;
if ( V_98 == NULL ) {
V_53 = - V_46 ;
goto V_95;
}
V_53 = F_41 ( L_13 ,
sizeof( struct V_63 ) ,
V_98 ) ;
if ( V_53 != 0 )
goto V_95;
V_101 = F_43 ( L_34 V_102 ,
& V_103 ) ;
if ( V_101 == NULL ) {
V_53 = - V_46 ;
goto V_95;
}
V_53 = F_41 ( L_10 ,
sizeof( struct V_51 ) ,
V_101 ) ;
if ( V_53 != 0 )
goto V_95;
V_104 = F_36 ;
V_18 = F_47 ( L_35 ,
V_13 , V_13 , 0 ,
F_11 ) ;
if ( ! V_18 ) {
F_2 ( V_105 L_36 ,
V_106 ) ;
V_53 = - V_46 ;
goto V_95;
}
return 0 ;
V_95:
F_39 ( V_93 ) ;
F_39 ( V_96 ) ;
F_39 ( V_98 ) ;
F_39 ( V_101 ) ;
return V_53 ;
}
static void T_7 F_48 ( void )
{
V_104 = NULL ;
if ( V_18 )
F_49 ( V_18 ) ;
F_39 ( V_93 ) ;
F_39 ( V_96 ) ;
F_39 ( V_98 ) ;
F_39 ( V_101 ) ;
}

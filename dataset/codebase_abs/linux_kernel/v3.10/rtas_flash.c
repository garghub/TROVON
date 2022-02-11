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
struct V_21 * const V_22 = & V_23 ;
F_6 ( & V_24 ) ;
if ( V_22 -> V_2 ) {
if ( V_25 ) {
F_3 ( V_25 ) ;
V_25 = NULL ;
}
if ( V_22 -> V_26 != V_27 )
V_22 -> V_26 = F_1 ( V_22 -> V_2 ) ;
if ( V_22 -> V_26 == V_17 )
V_25 = V_22 -> V_2 ;
else
F_3 ( V_22 -> V_2 ) ;
V_22 -> V_2 = NULL ;
}
F_7 ( & V_24 ) ;
return 0 ;
}
static T_1 F_8 ( int V_26 , char * V_28 )
{
const char * V_29 ;
T_1 V_30 ;
switch ( V_26 ) {
case V_27 :
V_29 = L_2 ;
break;
case V_15 :
V_29 = L_3 ;
break;
case V_31 :
V_29 = L_4 ;
break;
case V_14 :
V_29 = L_5 ;
break;
case V_11 :
V_29 = L_6 ;
break;
case V_17 :
V_29 = L_7 ;
break;
default:
return sprintf ( V_28 , L_8 ,
V_26 ) ;
}
V_30 = strlen ( V_29 ) ;
memcpy ( V_28 , V_29 , V_30 + 1 ) ;
return V_30 ;
}
static T_2 F_9 ( struct V_20 * V_20 , char T_3 * V_28 ,
T_1 V_32 , T_4 * V_33 )
{
struct V_21 * const V_22 = & V_23 ;
char V_29 [ V_34 ] ;
T_1 V_30 ;
int V_26 ;
F_6 ( & V_24 ) ;
V_26 = V_22 -> V_26 ;
F_7 ( & V_24 ) ;
V_30 = F_8 ( V_26 , V_29 ) ;
return F_10 ( V_28 , V_32 , V_33 , V_29 , V_30 ) ;
}
static T_2 F_11 ( struct V_20 * V_20 , char T_3 * V_28 ,
T_1 V_32 , T_4 * V_33 )
{
struct V_21 * const V_22 = & V_23 ;
char V_29 [ V_34 ] ;
int V_26 ;
F_6 ( & V_24 ) ;
V_26 = V_22 -> V_26 ;
F_7 ( & V_24 ) ;
sprintf ( V_29 , L_9 , V_26 ) ;
return F_10 ( V_28 , V_32 , V_33 , V_29 , strlen ( V_29 ) ) ;
}
static T_2 F_12 ( struct V_20 * V_20 , const char T_3 * V_35 ,
T_1 V_32 , T_4 * V_36 )
{
struct V_21 * const V_22 = & V_23 ;
char * V_37 ;
int V_38 , V_39 ;
struct V_1 * V_40 ;
F_6 ( & V_24 ) ;
if ( V_22 -> V_26 == V_27 || V_32 == 0 )
goto V_41;
if ( V_22 -> V_2 == NULL ) {
V_22 -> V_2 = F_13 ( V_18 , V_42 ) ;
if ( ! V_22 -> V_2 )
goto V_43;
}
V_40 = V_22 -> V_2 ;
while ( V_40 -> V_7 )
V_40 = V_40 -> V_7 ;
V_38 = V_40 -> V_8 ;
if ( V_38 == V_44 ) {
V_40 -> V_7 = F_13 ( V_18 , V_42 ) ;
if ( ! V_40 -> V_7 )
goto V_43;
V_40 = V_40 -> V_7 ;
V_38 = 0 ;
}
if ( V_32 > V_13 )
V_32 = V_13 ;
V_37 = F_13 ( V_18 , V_42 ) ;
if ( ! V_37 )
goto V_43;
if( F_14 ( V_37 , V_35 , V_32 ) ) {
F_4 ( V_18 , V_37 ) ;
V_39 = - V_45 ;
goto error;
}
V_40 -> V_9 [ V_38 ] . V_10 = V_37 ;
V_40 -> V_9 [ V_38 ] . V_12 = V_32 ;
V_40 -> V_8 ++ ;
V_41:
F_7 ( & V_24 ) ;
return V_32 ;
V_43:
V_39 = - V_46 ;
error:
F_7 ( & V_24 ) ;
return V_39 ;
}
static void F_15 ( struct V_47 * V_48 , unsigned int V_49 )
{
T_5 V_39 ;
do {
V_39 = F_16 ( F_17 ( L_10 ) , 1 , 1 ,
NULL , V_49 ) ;
} while ( F_18 ( V_39 ) );
V_48 -> V_26 = V_39 ;
}
static T_2 F_19 ( struct V_20 * V_20 , char T_3 * V_28 ,
T_1 V_32 , T_4 * V_33 )
{
struct V_47 * const V_48 = & V_50 ;
char V_29 [ V_34 ] ;
int V_51 , V_26 ;
F_6 ( & V_52 ) ;
V_26 = V_48 -> V_26 ;
F_7 ( & V_52 ) ;
V_51 = sprintf ( V_29 , L_9 , V_26 ) ;
return F_10 ( V_28 , V_32 , V_33 , V_29 , V_51 ) ;
}
static T_2 F_20 ( struct V_20 * V_20 , const char T_3 * V_28 ,
T_1 V_32 , T_4 * V_36 )
{
struct V_47 * const V_48 = & V_50 ;
static const char V_53 [] = L_11 ;
static const char V_54 [] = L_12 ;
char V_55 [ 10 ] ;
int V_49 , V_39 ;
F_6 ( & V_52 ) ;
if ( ( V_48 -> V_26 == V_56 ) || ( V_32 == 0 ) )
goto V_41;
V_49 = - 1 ;
if ( V_28 ) {
if ( V_32 > 9 ) V_32 = 9 ;
V_39 = - V_45 ;
if ( F_14 ( V_55 , V_28 , V_32 ) )
goto error;
if ( strncmp ( V_55 , V_53 , strlen ( V_53 ) ) == 0 )
V_49 = V_57 ;
else if ( strncmp ( V_55 , V_54 , strlen ( V_54 ) ) == 0 )
V_49 = V_58 ;
}
if ( V_49 == - 1 ) {
V_39 = - V_59 ;
goto error;
}
F_15 ( V_48 , V_49 ) ;
V_41:
F_7 ( & V_52 ) ;
return V_32 ;
error:
F_7 ( & V_52 ) ;
return V_39 ;
}
static void F_21 ( struct V_60 * V_48 )
{
int V_61 = F_17 ( L_13 ) ;
int V_62 ;
T_5 V_39 ;
V_39 = 0 ;
do {
F_22 ( & V_63 ) ;
memcpy ( V_64 , V_48 -> V_28 , V_65 ) ;
V_39 = F_16 ( V_61 , 2 , 2 , & V_62 ,
( V_66 ) F_23 ( V_64 ) , V_48 -> V_67 ) ;
memcpy ( V_48 -> V_28 , V_64 , V_65 ) ;
F_24 ( & V_63 ) ;
} while ( F_18 ( V_39 ) );
V_48 -> V_26 = V_39 ;
V_48 -> V_62 = V_62 ;
}
static int F_25 ( struct V_60 * V_48 ,
char * V_29 , int V_51 )
{
int V_68 ;
if ( V_48 -> V_26 >= V_69 ) {
V_68 = sprintf ( V_29 , L_9 , V_48 -> V_62 ) ;
if ( ( V_48 -> V_62 >= V_70 ) ||
( V_48 -> V_62 == V_69 ) )
V_68 += snprintf ( V_29 + V_68 , V_51 - V_68 , L_14 ,
V_48 -> V_28 ) ;
} else {
V_68 = sprintf ( V_29 , L_9 , V_48 -> V_26 ) ;
}
return V_68 ;
}
static T_2 F_26 ( struct V_20 * V_20 , char T_3 * V_28 ,
T_1 V_32 , T_4 * V_33 )
{
struct V_60 * const V_48 =
& V_71 ;
char V_29 [ V_72 ] ;
int V_51 ;
F_6 ( & V_73 ) ;
V_51 = F_25 ( V_48 , V_29 , V_72 ) ;
F_7 ( & V_73 ) ;
return F_10 ( V_28 , V_32 , V_33 , V_29 , V_51 ) ;
}
static T_2 F_27 ( struct V_20 * V_20 , const char T_3 * V_28 ,
T_1 V_32 , T_4 * V_36 )
{
struct V_60 * const V_48 =
& V_71 ;
int V_39 ;
F_6 ( & V_73 ) ;
if ( ( * V_36 >= V_65 ) ||
( V_48 -> V_26 == V_74 ) ) {
* V_36 += V_32 ;
F_7 ( & V_73 ) ;
return V_32 ;
}
if ( * V_36 + V_32 >= V_65 ) {
V_32 = V_65 - * V_36 ;
V_48 -> V_26 = V_75 ;
} else {
V_48 -> V_26 = V_76 ;
}
if ( ! F_28 ( V_77 , V_28 , V_32 ) ) {
V_39 = - V_45 ;
goto V_78;
}
if ( F_14 ( V_48 -> V_28 + * V_36 , V_28 , V_32 ) ) {
V_39 = - V_45 ;
goto V_78;
}
* V_36 += V_32 ;
V_39 = V_32 ;
V_78:
F_7 ( & V_73 ) ;
return V_39 ;
}
static int F_29 ( struct V_19 * V_19 , struct V_20 * V_20 )
{
struct V_60 * const V_48 =
& V_71 ;
F_6 ( & V_73 ) ;
if ( V_48 -> V_26 == V_75 ) {
V_48 -> V_67 = V_65 ;
F_21 ( V_48 ) ;
}
F_7 ( & V_73 ) ;
return 0 ;
}
static void F_30 ( int V_79 )
{
unsigned long V_6 ;
struct V_1 * V_3 , * V_7 , * V_2 ;
unsigned long V_80 ;
int V_4 , V_26 , V_81 ;
if ( V_25 == NULL )
return;
if ( V_79 != V_82 ) {
F_2 ( V_83 L_15 ) ;
F_2 ( V_83 L_16 ) ;
return;
}
V_81 = F_17 ( L_17 ) ;
if ( V_81 == V_84 ) {
F_2 ( V_83 L_18
L_19 ) ;
F_2 ( V_83 L_20 ) ;
return;
}
F_31 () ;
F_22 ( & V_63 ) ;
V_2 = (struct V_1 * ) & V_64 [ 0 ] ;
V_2 -> V_8 = 0 ;
V_2 -> V_7 = V_25 ;
V_80 = F_23 ( V_2 ) ;
if ( V_80 >= 4UL * 1024 * 1024 * 1024 ) {
F_2 ( V_83 L_21 ) ;
F_24 ( & V_63 ) ;
return;
}
F_2 ( V_83 L_22 ) ;
V_25 = NULL ;
V_6 = 0 ;
for ( V_3 = V_2 ; V_3 ; V_3 = V_7 ) {
for ( V_4 = 0 ; V_4 < V_3 -> V_8 ; V_4 ++ ) {
V_3 -> V_9 [ V_4 ] . V_10 = ( char * ) F_23 ( V_3 -> V_9 [ V_4 ] . V_10 ) ;
V_6 += V_3 -> V_9 [ V_4 ] . V_12 ;
}
V_7 = V_3 -> V_7 ;
if ( V_3 -> V_7 )
V_3 -> V_7 = (struct V_1 * ) F_23 ( V_3 -> V_7 ) ;
else
V_3 -> V_7 = NULL ;
V_3 -> V_8 = ( V_85 << 56 ) | ( ( V_3 -> V_8 + 1 ) * 16 ) ;
}
F_2 ( V_83 L_23 , V_6 ) ;
F_2 ( V_83 L_24 ) ;
F_32 ( L_25 , 0x0 ) ;
F_32 ( L_26 , 0x0 ) ;
F_2 ( V_83 L_27 ) ;
V_26 = F_16 ( V_81 , 1 , 1 , NULL , V_80 ) ;
switch ( V_26 ) {
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
F_2 ( V_83 L_32 , V_26 ) ;
break;
}
F_24 ( & V_63 ) ;
}
static int T_6 F_33 ( void )
{
int V_4 ;
if ( F_17 ( L_17 ) ==
V_84 ) {
F_34 ( L_33 ) ;
return 1 ;
}
V_71 . V_28 = F_35 ( V_65 , V_42 ) ;
if ( ! V_71 . V_28 )
return - V_46 ;
V_18 = F_36 ( L_34 ,
V_13 , V_13 , 0 ,
NULL ) ;
if ( ! V_18 ) {
F_2 ( V_86 L_35 ,
V_87 ) ;
goto V_88;
}
for ( V_4 = 0 ; V_4 < F_37 ( V_89 ) ; V_4 ++ ) {
const struct V_90 * V_3 = & V_89 [ V_4 ] ;
int V_61 ;
if ( ! F_38 ( V_3 -> V_91 , V_92 | V_93 , NULL , & V_3 -> V_94 ) )
goto V_95;
V_61 = F_17 ( V_3 -> V_96 ) ;
if ( V_61 == V_84 )
* V_3 -> V_26 = V_27 ;
else
* V_3 -> V_26 = V_15 ;
}
V_97 = F_30 ;
return 0 ;
V_95:
while ( -- V_4 >= 0 ) {
const struct V_90 * V_3 = & V_89 [ V_4 ] ;
F_39 ( V_3 -> V_91 , NULL ) ;
}
F_40 ( V_18 ) ;
V_88:
F_41 ( V_71 . V_28 ) ;
return - V_46 ;
}
static void T_7 F_42 ( void )
{
int V_4 ;
V_97 = NULL ;
if ( V_25 ) {
F_3 ( V_25 ) ;
V_25 = NULL ;
}
for ( V_4 = 0 ; V_4 < F_37 ( V_89 ) ; V_4 ++ ) {
const struct V_90 * V_3 = & V_89 [ V_4 ] ;
F_39 ( V_3 -> V_91 , NULL ) ;
}
F_40 ( V_18 ) ;
F_41 ( V_71 . V_28 ) ;
}

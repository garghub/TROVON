static void
F_1 ( T_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = & V_1 -> V_5 [ V_2 ] ;
F_2 ( V_4 ) ;
V_1 -> V_6 [ V_2 ] = 0 ;
}
static void
F_3 ( T_1 * V_1 , int V_7 )
{
T_1 * V_8 = V_1 -> V_8 [ V_7 ] ;
int V_9 = V_1 -> V_9 [ V_7 ] , V_10 , V_11 ;
struct V_12 * V_13 ;
T_2 V_14 ;
while ( V_1 -> V_6 [ V_7 ] ) {
if ( ( V_13 = F_4 ( & V_1 -> V_5 [ V_7 ] ) ) ) {
V_10 = V_13 -> V_10 ;
V_1 -> V_6 [ V_7 ] -= V_10 ;
V_11 = * ( V_13 -> V_15 ) ;
V_14 . V_16 = V_1 -> V_17 ;
V_14 . V_18 = V_7 ;
if ( V_8 ) {
V_8 -> V_19 . V_20 ( V_8 -> V_17 , V_9 , V_13 ) ;
} else {
F_5 ( V_21 L_1 ) ;
F_6 ( V_13 ) ;
} ;
V_14 . V_22 = V_23 ;
V_14 . V_24 . V_25 = V_10 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
} else
V_1 -> V_6 [ V_7 ] = 0 ;
}
}
static void
F_7 ( unsigned long V_27 )
{
T_1 * V_1 = ( T_1 * ) V_27 ;
unsigned long V_28 ;
if ( V_1 -> V_28 & V_29 )
F_3 ( V_1 , 0 ) ;
if ( V_1 -> V_28 & V_30 )
F_3 ( V_1 , 1 ) ;
if ( V_1 -> V_28 & ( V_29 | V_30 ) ) {
F_8 ( & V_1 -> V_31 , V_28 ) ;
V_1 -> V_32 . V_33 = V_34 + V_35 ;
F_9 ( & V_1 -> V_32 ) ;
V_1 -> V_28 |= V_36 ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
} else
V_1 -> V_28 &= ~ V_36 ;
}
static void
F_11 ( char * V_37 , T_2 * V_14 )
{
char * V_38 = V_37 ;
char * V_39 = strchr ( V_38 , ',' ) ;
* V_39 ++ = '\0' ;
F_12 ( V_14 -> V_24 . V_37 . V_40 , V_38 , sizeof( V_14 -> V_24 . V_37 . V_40 ) ) ;
V_39 = strchr ( V_38 = V_39 , ',' ) ;
* V_39 ++ = '\0' ;
if ( ! strlen ( V_38 ) )
V_14 -> V_24 . V_37 . V_41 = 0 ;
else
V_14 -> V_24 . V_37 . V_41 = F_13 ( V_38 , NULL , 10 ) ;
V_39 = strchr ( V_38 = V_39 , ',' ) ;
* V_39 ++ = '\0' ;
if ( ! strlen ( V_38 ) )
V_14 -> V_24 . V_37 . V_42 = 0 ;
else
V_14 -> V_24 . V_37 . V_42 =
F_13 ( V_38 , NULL , 10 ) ;
F_12 ( V_14 -> V_24 . V_37 . V_43 , V_39 , sizeof( V_14 -> V_24 . V_37 . V_43 ) ) ;
V_14 -> V_24 . V_37 . V_44 = 0 ;
V_14 -> V_24 . V_37 . V_45 = 0 ;
}
static void
F_14 ( T_3 * V_46 , int V_2 , T_1 * V_1 )
{
T_4 * V_39 = V_47 ;
int V_48 = - 1 ;
T_2 V_14 ;
while ( V_39 -> V_49 ) {
if ( ! strncmp ( V_46 , V_39 -> V_49 , strlen ( V_39 -> V_49 ) ) ) {
V_14 . V_22 = V_39 -> V_22 ;
V_48 = V_39 -> V_48 ;
break;
}
V_39 ++ ;
}
if ( V_48 == - 1 )
return;
V_14 . V_16 = V_1 -> V_17 ;
V_14 . V_18 = V_2 ;
switch ( V_48 ) {
case 1 :
V_1 -> V_28 |= ( V_2 ) ?
V_30 : V_29 ;
break;
case 2 :
V_1 -> V_28 &= ~ ( ( V_2 ) ?
V_30 : V_29 ) ;
F_1 ( V_1 , V_2 ) ;
break;
case 3 :
F_11 ( V_46 + 6 , & V_14 ) ;
break;
case 4 :
sprintf ( V_14 . V_24 . V_37 . V_40 , L_2 , V_1 -> V_17 ) ;
sprintf ( V_14 . V_24 . V_37 . V_43 , L_3 , V_2 + 1 ) ;
V_14 . V_24 . V_37 . V_41 = 7 ;
V_14 . V_24 . V_37 . V_42 = 0 ;
V_14 . V_24 . V_37 . V_44 = 0 ;
V_14 . V_24 . V_37 . V_45 = 0 ;
break;
case 5 :
F_12 ( V_14 . V_24 . V_50 , V_46 + 3 , sizeof( V_14 . V_24 . V_50 ) ) ;
break;
case 6 :
snprintf ( V_14 . V_24 . V_50 , sizeof( V_14 . V_24 . V_50 ) , L_3 ,
( int ) F_13 ( V_46 + 7 , NULL , 16 ) ) ;
break;
case 7 :
V_46 += 3 ;
if ( strlen ( V_46 ) == 4 )
snprintf ( V_14 . V_24 . V_50 , sizeof( V_14 . V_24 . V_50 ) , L_4 ,
V_46 + 2 , * V_46 , * ( V_46 + 1 ) ) ;
else
F_12 ( V_14 . V_24 . V_50 , V_46 + 1 , sizeof( V_14 . V_24 . V_50 ) ) ;
break;
case 8 :
V_1 -> V_28 &= ~ V_29 ;
F_1 ( V_1 , 0 ) ;
V_14 . V_18 = 0 ;
V_14 . V_16 = V_1 -> V_17 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
V_14 . V_22 = V_51 ;
V_14 . V_18 = 0 ;
V_14 . V_16 = V_1 -> V_17 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
V_14 . V_22 = V_52 ;
V_1 -> V_28 &= ~ V_30 ;
F_1 ( V_1 , 1 ) ;
V_14 . V_18 = 1 ;
V_14 . V_16 = V_1 -> V_17 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
V_14 . V_22 = V_51 ;
V_14 . V_18 = 1 ;
V_14 . V_16 = V_1 -> V_17 ;
break;
}
V_1 -> V_19 . V_26 ( & V_14 ) ;
}
static void
F_15 ( T_1 * V_1 , unsigned char V_53 )
{
T_5 V_28 ;
F_8 ( & V_1 -> V_31 , V_28 ) ;
* V_1 -> V_54 ++ = ( V_53 == 0xff ) ? '\n' : V_53 ;
if ( V_1 -> V_54 == V_1 -> V_55 ) {
if ( ++ V_1 -> V_55 > V_1 -> V_56 )
V_1 -> V_55 = V_1 -> V_57 ;
}
if ( V_1 -> V_54 > V_1 -> V_56 )
V_1 -> V_54 = V_1 -> V_57 ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
}
static void
F_16 ( unsigned long V_27 )
{
T_1 * V_1 = ( T_1 * ) V_27 ;
struct V_12 * V_13 ;
int V_58 ;
int V_59 ;
T_3 V_53 ;
int V_7 ;
unsigned long V_28 ;
T_3 * V_60 ;
T_2 V_14 ;
if ( ( V_13 = F_4 ( & V_1 -> V_61 ) ) )
V_58 = V_13 -> V_10 ;
else
V_58 = 0 ;
for ( V_59 = V_58 ; V_59 > 0 ; V_59 -- ) {
V_53 = * V_13 -> V_27 ;
F_17 ( V_13 , 1 ) ;
F_15 ( V_1 , V_53 ) ;
V_1 -> V_62 [ V_1 -> V_63 ] = V_53 ;
if ( V_1 -> V_63 < 59 )
V_1 -> V_63 ++ ;
if ( ! V_13 -> V_10 ) {
V_58 ++ ;
F_15 ( V_1 , '\n' ) ;
V_1 -> V_62 [ V_1 -> V_63 ] = 0 ;
V_1 -> V_63 = 0 ;
if ( V_1 -> V_62 [ 0 ] == '0' && V_1 -> V_62 [ 1 ] >= '0' &&
V_1 -> V_62 [ 1 ] <= '2' && V_1 -> V_62 [ 2 ] == ';' ) {
V_7 = ( V_1 -> V_62 [ 1 ] - '0' ) - 1 ;
V_60 = & V_1 -> V_62 [ 3 ] ;
F_14 ( V_60 , V_7 , V_1 ) ;
} else {
V_60 = V_1 -> V_62 ;
if ( ! strncmp ( V_60 , L_5 , 5 ) ) {
F_5 ( V_64 L_6 , V_65 , V_60 ) ;
if ( ! strncmp ( V_60 + 7 , L_7 , 2 ) ) {
V_1 -> V_66 = V_67 ;
V_1 -> V_19 . V_68 |= V_69 ;
F_5 ( V_64
L_8 , V_65 ) ;
}
if ( ! strncmp ( V_60 + 7 , L_9 , 2 ) ) {
V_1 -> V_66 = V_70 ;
V_1 -> V_19 . V_68 |= V_71 ;
F_5 ( V_64
L_10 , V_65 ) ;
}
continue;
}
}
}
}
if ( V_58 ) {
V_14 . V_22 = V_72 ;
V_14 . V_16 = V_1 -> V_17 ;
V_14 . V_18 = V_58 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
}
if ( V_1 -> V_28 & ( V_29 | V_30 ) )
if ( ! ( V_1 -> V_28 & V_36 ) ) {
V_1 -> V_28 |= V_36 ;
F_8 ( & V_1 -> V_31 , V_28 ) ;
F_18 ( & V_1 -> V_32 ) ;
V_1 -> V_32 . V_73 = F_7 ;
V_1 -> V_32 . V_27 = ( unsigned long ) V_1 ;
V_1 -> V_32 . V_33 = V_34 + V_35 ;
F_9 ( & V_1 -> V_32 ) ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
}
F_8 ( & V_1 -> V_31 , V_28 ) ;
V_1 -> V_74 . V_33 = V_34 + V_75 ;
F_9 ( & V_1 -> V_74 ) ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
}
static int
F_19 ( int V_2 , struct V_12 * V_13 , T_1 * V_1 )
{
int V_10 = V_13 -> V_10 ;
unsigned long V_28 ;
struct V_12 * V_76 ;
if ( V_10 > 4000 ) {
F_5 ( V_21
L_11 ) ;
return - V_77 ;
}
if ( V_10 ) {
if ( ! ( V_1 -> V_28 & ( V_2 ) ? V_30 : V_29 ) )
return 0 ;
if ( V_1 -> V_6 [ V_2 ] > V_78 )
return 0 ;
F_8 ( & V_1 -> V_31 , V_28 ) ;
V_76 = F_20 ( V_13 -> V_10 ) ;
if ( V_76 ) {
F_21 ( V_13 ,
F_22 ( V_76 , V_10 ) , V_10 ) ;
F_23 ( & V_1 -> V_5 [ V_2 ] , V_76 ) ;
F_6 ( V_13 ) ;
} else
V_10 = 0 ;
V_1 -> V_6 [ V_2 ] += V_10 ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
}
return V_10 ;
}
static int
F_24 ( T_3 T_6 * V_79 , int V_10 , T_1 * V_1 )
{
int V_80 ;
T_3 T_6 * V_60 ;
for ( V_60 = V_79 , V_80 = 0 ; V_80 < V_10 ; V_60 ++ , V_80 ++ ) {
if ( V_1 -> V_55 == V_1 -> V_54 )
return V_80 ;
if ( F_25 ( * V_1 -> V_55 ++ , V_60 ) )
return - V_81 ;
if ( V_1 -> V_55 > V_1 -> V_56 )
V_1 -> V_55 = V_1 -> V_57 ;
}
return V_80 ;
}
static int
F_26 ( T_1 * V_1 , char * V_39 , int V_7 )
{
struct V_12 * V_13 ;
int V_10 = strlen ( V_39 ) + ( ( V_7 >= 0 ) ? 3 : 0 ) ;
if ( ! ( V_13 = F_20 ( V_10 ) ) ) {
F_5 ( V_21 L_12 ) ;
return 1 ;
}
if ( V_7 >= 0 )
sprintf ( F_22 ( V_13 , 3 ) , L_13 , V_7 ) ;
memcpy ( F_22 ( V_13 , strlen ( V_39 ) ) , V_39 , strlen ( V_39 ) ) ;
F_23 ( & V_1 -> V_61 , V_13 ) ;
return 0 ;
}
static void
F_27 ( T_1 * V_1 )
{
char V_79 [ 60 ] ;
sprintf ( V_79 , L_14 , V_1 -> V_82 ) ;
F_26 ( V_1 , V_79 , - 1 ) ;
F_26 ( V_1 , L_15 , - 1 ) ;
}
static char *
F_28 ( T_1 * V_1 , int V_83 , int V_84 )
{
static char V_79 [ 6 ] ;
switch ( V_1 -> V_66 ) {
case V_70 :
sprintf ( V_79 , L_16 , ( V_83 ) ? 4 : 2 , V_85 [ V_84 ] ) ;
break;
case V_67 :
sprintf ( V_79 , L_17 , V_86 [ V_84 ] ) ;
break;
default:
return ( L_18 ) ;
}
return ( V_79 ) ;
}
static void
F_29 ( T_1 * V_1 , int V_7 )
{
unsigned long V_28 ;
char V_79 [ 60 ] ;
F_8 ( & V_1 -> V_31 , V_28 ) ;
if ( V_1 -> V_8 ) {
F_26 ( V_1 -> V_8 [ V_7 ] , L_19 , V_1 -> V_9 [ V_7 ] + 1 ) ;
V_1 -> V_8 [ V_7 ] -> V_8 [ V_1 -> V_9 [ V_7 ] ] = NULL ;
V_1 -> V_8 [ V_7 ] = NULL ;
}
F_26 ( V_1 , L_19 , V_7 + 1 ) ;
sprintf ( V_79 , L_20 , F_28 ( V_1 , 1 , 3 ) ) ;
F_26 ( V_1 , V_79 , V_7 + 1 ) ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
}
static void
F_30 ( unsigned long V_27 )
{
T_1 * V_1 = ( T_1 * ) V_27 ;
F_29 ( V_1 , 0 ) ;
}
static void
F_31 ( unsigned long V_27 )
{
T_1 * V_1 = ( T_1 * ) V_27 ;
F_29 ( V_1 , 1 ) ;
}
static void
F_32 ( T_1 * V_1 , int V_7 )
{
unsigned long V_28 ;
F_8 ( & V_1 -> V_31 , V_28 ) ;
F_33 ( & V_1 -> V_87 [ V_7 ] ) ;
V_1 -> V_87 [ V_7 ] . V_33 = V_34 + V_88 ;
if ( V_7 )
V_1 -> V_87 [ V_7 ] . V_73 = F_31 ;
else
V_1 -> V_87 [ V_7 ] . V_73 = F_30 ;
V_1 -> V_87 [ V_7 ] . V_27 = ( unsigned long ) V_1 ;
F_9 ( & V_1 -> V_87 [ V_7 ] ) ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
}
static void
F_34 ( T_1 * V_1 , int V_7 )
{
unsigned long V_28 ;
F_8 ( & V_1 -> V_31 , V_28 ) ;
F_18 ( & V_1 -> V_87 [ V_7 ] ) ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
}
static int
F_35 ( T_1 * V_1 , char * V_60 , int V_89 , T_2 * V_14 )
{
T_1 * V_90 = V_91 ;
unsigned long V_28 ;
int V_7 ;
int V_92 ;
int V_93 ;
char * V_94 ;
char V_95 [ 32 ] ;
F_11 ( V_60 , V_14 ) ;
while ( V_90 ) {
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
if ( ( V_90 == V_1 ) && ( V_7 == V_89 ) )
continue;
V_92 = 0 ;
switch ( V_90 -> V_66 ) {
case V_70 :
for ( V_93 = 0 ; V_93 < 3 ; V_93 ++ )
if ( ! ( strcmp ( V_90 -> V_96 [ V_93 ] , V_14 -> V_24 . V_37 . V_40 ) ) )
V_92 = 1 ;
break;
case V_67 :
V_94 = V_90 -> V_97 [ V_7 ] ;
while ( * V_94 ) {
sprintf ( V_95 , L_21 , V_90 -> V_96 [ 0 ] , * V_94 ) ;
if ( ! ( strcmp ( V_95 , V_14 -> V_24 . V_37 . V_40 ) ) )
V_92 = 1 ;
V_94 ++ ;
}
}
if ( V_92 ) {
F_8 ( & V_1 -> V_31 , V_28 ) ;
if ( ! ( V_90 -> V_8 [ V_7 ] ) ) {
if ( ! ( V_98 [ V_14 -> V_24 . V_37 . V_41 ] & V_90 -> V_99 [ V_7 ] ) ) {
F_10 ( & V_1 -> V_31 , V_28 ) ;
return 3 ;
}
V_90 -> V_8 [ V_7 ] = V_1 ;
V_90 -> V_9 [ V_7 ] = V_89 ;
V_1 -> V_8 [ V_89 ] = V_90 ;
V_1 -> V_9 [ V_89 ] = V_7 ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
return 0 ;
} else {
F_10 ( & V_1 -> V_31 , V_28 ) ;
if ( V_7 == 1 )
return 1 ;
}
}
}
V_90 = V_90 -> V_100 ;
}
return 2 ;
}
static char *
F_36 ( T_1 * V_1 , char * V_40 , int V_101 )
{
int V_93 ;
static char V_102 [ 30 ] ;
if ( ! V_1 ) {
F_5 ( L_22 ) ;
return L_23 ;
}
switch ( V_1 -> V_66 ) {
case V_70 :
if ( V_101 ) {
for ( V_93 = 0 ; V_93 < 2 ; V_93 ++ )
if ( ! ( strcmp ( V_1 -> V_96 [ V_93 ] , V_40 ) ) )
return ( V_40 ) ;
return ( V_1 -> V_96 [ 0 ] ) ;
}
return ( V_40 ) ;
break;
case V_67 :
if ( V_101 ) {
sprintf ( V_102 , L_21 , V_1 -> V_96 [ 0 ] , V_40 [ 0 ] ) ;
return ( V_102 ) ;
} else
return ( & V_40 [ strlen ( V_40 ) - 1 ] ) ;
break;
}
return L_23 ;
}
static void
F_37 ( T_1 * V_1 )
{
char * V_60 = V_1 -> V_82 ;
T_2 V_14 ;
char V_79 [ 60 ] ;
T_4 * V_39 = V_103 ;
int V_48 = - 1 ;
int V_93 ;
int V_7 ;
if ( ( V_1 -> V_82 [ 0 ] != '0' ) && ( V_1 -> V_82 [ 2 ] != ';' ) ) {
F_27 ( V_1 ) ;
return;
}
V_7 = V_1 -> V_82 [ 1 ] - '0' ;
if ( ( V_7 < 0 ) || ( V_7 > 2 ) ) {
F_27 ( V_1 ) ;
return;
}
V_60 += 3 ;
while ( V_39 -> V_49 ) {
if ( ! strncmp ( V_60 , V_39 -> V_49 , strlen ( V_39 -> V_49 ) ) ) {
V_48 = V_39 -> V_48 ;
if ( V_39 -> V_22 && ( V_7 != 0 ) ) {
F_27 ( V_1 ) ;
return;
}
break;
}
V_39 ++ ;
}
if ( V_48 == - 1 )
return;
switch ( V_48 ) {
case 1 :
if ( V_1 -> V_8 [ V_7 - 1 ] ) {
F_26 ( V_1 -> V_8 [ V_7 - 1 ] , L_24 ,
V_1 -> V_9 [ V_7 - 1 ] + 1 ) ;
F_26 ( V_1 , L_25 , V_7 ) ;
}
break;
case 17 :
if ( V_1 -> V_8 [ V_7 - 1 ] ) {
F_26 ( V_1 -> V_8 [ V_7 - 1 ] , L_25 ,
V_1 -> V_9 [ V_7 - 1 ] + 1 ) ;
}
break;
case 2 :
F_26 ( V_1 , L_26 , V_7 ) ;
if ( V_1 -> V_8 [ V_7 - 1 ] ) {
F_26 ( V_1 -> V_8 [ V_7 - 1 ] , L_27 ,
V_1 -> V_9 [ V_7 - 1 ] + 1 ) ;
}
break;
case 16 :
F_34 ( V_1 , V_7 - 1 ) ;
if ( V_1 -> V_8 [ V_7 - 1 ] ) {
F_34 ( V_1 -> V_8 [ V_7 - 1 ] , V_1 -> V_9 [ V_7 - 1 ] ) ;
F_26 ( V_1 -> V_8 [ V_7 - 1 ] , L_28 ,
V_1 -> V_9 [ V_7 - 1 ] + 1 ) ;
F_26 ( V_1 , L_28 , V_7 ) ;
}
break;
case 3 :
F_34 ( V_1 , V_7 - 1 ) ;
if ( V_1 -> V_8 [ V_7 - 1 ] ) {
F_34 ( V_1 -> V_8 [ V_7 - 1 ] , V_1 -> V_9 [ V_7 - 1 ] ) ;
F_26 ( V_1 -> V_8 [ V_7 - 1 ] , L_19 ,
V_1 -> V_9 [ V_7 - 1 ] + 1 ) ;
V_1 -> V_8 [ V_7 - 1 ] = NULL ;
}
F_26 ( V_1 , L_29 , V_7 ) ;
break;
case 4 :
if ( V_1 -> V_66 != V_67 ) {
F_27 ( V_1 ) ;
return;
}
case 5 :
V_60 += 6 ;
switch ( F_35 ( V_1 , V_60 , V_7 - 1 , & V_14 ) ) {
case 0 :
sprintf ( V_79 , L_30 ,
( V_48 == 4 ) ? L_31 : L_32 ,
F_36 ( V_1 , V_14 . V_24 . V_37 . V_43 , 1 ) ,
V_14 . V_24 . V_37 . V_41 ,
V_14 . V_24 . V_37 . V_42 ,
F_36 ( V_1 -> V_8 [ V_7 - 1 ] ,
V_14 . V_24 . V_37 . V_40 , 0 ) ) ;
F_26 ( V_1 -> V_8 [ V_7 - 1 ] , V_79 , V_1 -> V_9 [ V_7 - 1 ] + 1 ) ;
case 3 :
F_32 ( V_1 , V_7 - 1 ) ;
break;
case 1 :
F_26 ( V_1 , L_19 , V_7 ) ;
sprintf ( V_79 , L_20 , F_28 ( V_1 , 1 , 1 ) ) ;
F_26 ( V_1 , V_79 , V_7 ) ;
break;
case 2 :
F_26 ( V_1 , L_19 , V_7 ) ;
sprintf ( V_79 , L_20 , F_28 ( V_1 , 1 , 2 ) ) ;
F_26 ( V_1 , V_79 , V_7 ) ;
break;
}
break;
case 6 :
V_1 -> V_97 [ V_7 - 1 ] [ 0 ] = '\0' ;
break;
case 7 :
V_60 += 3 ;
strcpy ( V_1 -> V_97 [ V_7 - 1 ] , V_60 ) ;
break;
case 8 :
sprintf ( V_79 , L_33 , V_1 -> V_97 [ V_7 - 1 ] ) ;
F_26 ( V_1 , V_79 , V_7 + 1 ) ;
break;
case 9 :
break;
case 10 :
break;
case 11 :
V_60 += 6 ;
V_93 = 0 ;
while ( strchr ( L_34 , * V_60 ) ) {
if ( V_93 )
V_1 -> V_99 [ V_7 - 1 ] |= V_98 [ * V_60 - '0' ] ;
V_93 = ( * V_60 ++ == '0' ) ;
}
if ( * V_60 )
F_27 ( V_1 ) ;
break;
case 12 :
sprintf ( V_79 , L_35 ) ;
V_60 = V_79 + 10 ;
for ( V_93 = 0 ; V_93 < 3 ; V_93 ++ )
if ( V_1 -> V_99 [ V_7 - 1 ] & ( 1 << V_93 ) )
V_60 += sprintf ( V_60 , L_36 , V_104 [ V_93 ] ) ;
F_26 ( V_1 , V_79 , V_7 + 1 ) ;
break;
case 13 :
V_1 -> V_99 [ V_7 - 1 ] = 0 ;
break;
case 14 :
break;
case 15 :
break;
}
}
static int
F_38 ( const T_3 * V_79 , int V_10 , int V_105 , T_1 * V_1 )
{
int V_106 = 0 ;
int V_107 = 1 ;
T_2 V_14 ;
while ( V_10 ) {
int V_80 = V_10 ;
T_3 * V_60 ;
T_3 V_108 [ 0x100 ] ;
if ( V_80 > 255 )
V_80 = 255 ;
if ( V_105 ) {
if ( F_39 ( V_108 , V_79 , V_80 ) )
return - V_81 ;
} else
memcpy ( V_108 , V_79 , V_80 ) ;
F_15 ( V_1 , '>' ) ;
for ( V_60 = V_108 ; V_80 > 0 ; V_80 -- , V_60 ++ ) {
V_10 -- ;
V_106 ++ ;
F_15 ( V_1 , * V_60 ) ;
V_1 -> V_82 [ V_1 -> V_109 ] = * V_60 ;
if ( * V_60 == '\n' ) {
V_1 -> V_82 [ V_1 -> V_109 ] = '\0' ;
V_1 -> V_109 = 0 ;
F_37 ( V_1 ) ;
if ( V_10 ) {
F_15 ( V_1 , '>' ) ;
V_107 ++ ;
}
} else {
if ( V_1 -> V_109 < 59 )
V_1 -> V_109 ++ ;
}
V_107 ++ ;
}
}
V_14 . V_22 = V_72 ;
V_14 . V_16 = V_1 -> V_17 ;
V_14 . V_18 = V_107 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
return V_106 ;
}
static void
F_40 ( T_1 * V_1 )
{
unsigned long V_28 ;
T_2 V_14 ;
F_8 ( & V_1 -> V_31 , V_28 ) ;
if ( V_1 -> V_28 & V_110 ) {
V_1 -> V_28 &= ~ V_110 ;
F_18 ( & V_1 -> V_74 ) ;
F_18 ( & V_1 -> V_32 ) ;
F_18 ( & V_1 -> V_87 [ 0 ] ) ;
F_18 ( & V_1 -> V_87 [ 1 ] ) ;
V_14 . V_22 = V_111 ;
V_14 . V_16 = V_1 -> V_17 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
}
F_10 ( & V_1 -> V_31 , V_28 ) ;
}
static void
F_41 ( void )
{
T_1 * V_60 = V_91 ;
while ( V_60 ) {
F_40 ( V_60 ) ;
V_60 = V_60 -> V_100 ;
}
}
static int
F_42 ( T_1 * V_1 , T_7 * V_112 )
{
unsigned long V_28 ;
T_7 V_113 ;
int V_93 ;
if ( V_1 -> V_28 & V_110 )
return - V_114 ;
if ( F_39 ( ( char * ) & V_113 , ( char * ) V_112 , sizeof( V_113 ) ) )
return - V_81 ;
F_8 ( & V_1 -> V_31 , V_28 ) ;
switch ( V_113 . V_66 ) {
case V_70 :
if ( F_26 ( V_1 , L_37 ,
- 1 ) ) {
F_10 ( & V_1 -> V_31 , V_28 ) ;
return - V_115 ;
}
V_1 -> V_99 [ 0 ] = V_1 -> V_99 [ 1 ] = 4 ;
if ( F_26 ( V_1 , L_38 , 0 ) ) {
F_10 ( & V_1 -> V_31 , V_28 ) ;
return - V_115 ;
}
for ( V_93 = 0 ; V_93 < 3 ; V_93 ++ ) {
F_12 ( V_1 -> V_96 [ V_93 ] , V_113 . V_50 [ V_93 ] ,
sizeof( V_1 -> V_96 [ 0 ] ) ) ;
}
break;
case V_67 :
if ( F_26 ( V_1 , L_39 ,
- 1 ) ) {
F_10 ( & V_1 -> V_31 , V_28 ) ;
return - V_115 ;
}
V_1 -> V_99 [ 0 ] = V_1 -> V_99 [ 1 ] = 4 ;
if ( F_26 ( V_1 , L_38 , 0 ) ) {
F_10 ( & V_1 -> V_31 , V_28 ) ;
return - V_115 ;
}
F_12 ( V_1 -> V_96 [ 0 ] , V_113 . V_50 [ 0 ] , sizeof( V_1 -> V_96 [ 0 ] ) ) ;
V_1 -> V_96 [ 1 ] [ 0 ] = '\0' ;
V_1 -> V_96 [ 2 ] [ 0 ] = '\0' ;
break;
default:
F_10 ( & V_1 -> V_31 , V_28 ) ;
F_5 ( V_21 L_40 ,
V_113 . V_66 ) ;
return - V_77 ;
}
F_33 ( & V_1 -> V_74 ) ;
V_1 -> V_74 . V_33 = V_34 + V_75 ;
V_1 -> V_74 . V_73 = F_16 ;
V_1 -> V_74 . V_27 = ( unsigned long ) V_1 ;
F_9 ( & V_1 -> V_74 ) ;
V_1 -> V_28 |= V_110 ;
F_10 ( & V_1 -> V_31 , V_28 ) ;
return 0 ;
}
static int
F_43 ( T_2 * V_53 , T_1 * V_1 )
{
T_5 V_116 ;
int V_93 ;
char V_117 [ 60 ] ;
T_2 V_14 ;
T_8 V_118 ;
switch ( V_53 -> V_22 ) {
case V_119 :
memcpy ( & V_116 , V_53 -> V_24 . V_50 , sizeof( T_5 ) ) ;
switch ( V_53 -> V_18 ) {
case V_120 :
return ( T_5 ) V_1 ;
case V_121 :
if ( ! F_44 ( V_122 , ( void * ) V_116 , sizeof( T_7 ) ) )
return - V_81 ;
return ( F_42 ( V_1 , ( T_7 * ) V_116 ) ) ;
break;
case V_123 :
if ( F_39 ( ( char * ) & V_118 ,
( char * ) V_116 ,
sizeof( V_118 ) ) )
return - V_81 ;
return ( F_45 ( V_118 . V_124 ) ) ;
break;
case V_125 :
if ( V_116 ) {
if ( ! V_1 -> V_126 ) {
V_1 -> V_126 = 1 ;
while ( V_1 -> V_66 == V_127 )
F_46 ( 10 ) ;
F_46 ( 10 ) ;
sprintf ( V_117 , L_41 ) ;
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
F_5 ( V_64
L_42 ,
V_65 ) ;
V_14 . V_22 = V_128 ;
V_14 . V_16 = V_1 -> V_17 ;
V_14 . V_18 = 0 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
}
} else {
if ( V_1 -> V_126 ) {
V_1 -> V_126 = 0 ;
sprintf ( V_117 , L_43 ) ;
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
F_5 ( V_64
L_44 ,
V_65 ) ;
V_14 . V_22 = V_128 ;
V_14 . V_16 = V_1 -> V_17 ;
V_14 . V_18 = 0 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
}
}
return 0 ;
default:
return - V_77 ;
}
break;
case V_129 :
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
if ( V_1 -> V_126 )
break;
if ( ( V_53 -> V_18 & 255 ) < V_131 ) {
char * V_60 ;
char V_132 [ 50 ] ;
char V_133 [ 4 ] ;
V_116 = V_53 -> V_18 ;
V_60 = V_53 -> V_24 . V_37 . V_40 ;
if ( * V_60 == 's' || * V_60 == 'S' ) {
V_60 ++ ;
strcpy ( V_133 , L_31 ) ;
} else
strcpy ( V_133 , L_32 ) ;
strcpy ( V_132 , V_60 ) ;
sprintf ( V_117 , L_45 , ( int ) ( V_116 + 1 ) ,
V_133 , V_132 , V_53 -> V_24 . V_37 . V_41 ,
V_53 -> V_24 . V_37 . V_42 , V_53 -> V_24 . V_37 . V_43 ) ;
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
}
break;
case V_134 :
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
if ( V_53 -> V_18 < V_131 ) {
V_116 = V_53 -> V_18 + 1 ;
V_117 [ 0 ] = 0 ;
switch ( V_1 -> V_135 [ V_116 - 1 ] ) {
case V_136 :
sprintf ( V_117 , L_46 , ( int ) V_116 ) ;
break;
#ifdef F_47
case V_137 :
sprintf ( V_117 , L_47 , ( int ) V_116 ) ;
break;
case V_138 :
sprintf ( V_117 , L_48 , ( int ) V_116 ) ;
break;
#endif
case V_139 :
sprintf ( V_117 , L_49 , ( int ) V_116 ) ;
break;
}
if ( strlen ( V_117 ) )
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
sprintf ( V_117 , L_50 , ( int ) V_116 ) ;
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
}
break;
case V_140 :
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
if ( V_53 -> V_18 < V_131 ) {
V_116 = V_53 -> V_18 + 1 ;
switch ( V_1 -> V_135 [ V_116 - 1 ] ) {
case V_136 :
sprintf ( V_117 , L_51 , ( int ) V_116 ) ;
break;
#ifdef F_47
case V_137 :
sprintf ( V_117 , L_52 , ( int ) V_116 ) ;
break;
case V_138 :
sprintf ( V_117 , L_53 , ( int ) V_116 ) ;
break;
#endif
case V_139 :
sprintf ( V_117 , L_54 , ( int ) V_116 ) ;
break;
default:
sprintf ( V_117 , L_55 , ( int ) V_116 ) ;
}
F_5 ( V_141 L_56 , V_117 ) ;
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
break;
case V_142 :
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
if ( V_53 -> V_18 < V_131 ) {
V_116 = V_53 -> V_18 + 1 ;
sprintf ( V_117 , L_57 , ( int ) V_116 , ( int ) V_116 ) ;
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
}
break;
case V_143 :
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
if ( V_1 -> V_126 )
break;
if ( V_53 -> V_18 < V_131 ) {
V_116 = V_53 -> V_18 + 1 ;
if ( V_1 -> V_66 == V_70 ) {
sprintf ( V_117 , L_58 , ( int ) V_116 ,
V_53 -> V_24 . V_50 [ 0 ] ? L_59 : L_60 , V_53 -> V_24 . V_50 ) ;
} else
sprintf ( V_117 , L_61 , ( int ) V_116 ,
V_53 -> V_24 . V_50 [ 0 ] ? V_53 -> V_24 . V_50 : ( T_3 * ) L_62 ) ;
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
}
break;
case V_144 :
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
if ( V_1 -> V_126 )
break;
if ( V_53 -> V_18 < V_131 ) {
V_116 = V_53 -> V_18 + 1 ;
if ( V_1 -> V_66 == V_70 )
sprintf ( V_117 , L_63 , ( int ) V_116 ) ;
else
sprintf ( V_117 , L_64 , ( int ) V_116 ) ;
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
}
break;
case V_145 :
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
if ( ( V_53 -> V_18 & 255 ) < V_131 ) {
V_116 = V_53 -> V_18 ;
switch ( V_116 >> 8 ) {
case V_136 :
sprintf ( V_117 , L_46 , ( int ) ( V_116 & 255 ) + 1 ) ;
break;
#ifdef F_47
case V_137 :
sprintf ( V_117 , L_47 , ( int ) ( V_116 & 255 ) + 1 ) ;
break;
case V_138 :
sprintf ( V_117 , L_48 , ( int ) ( V_116 & 255 ) + 1 ) ;
break;
#endif
case V_139 :
sprintf ( V_117 , L_49 , ( int ) ( V_116 & 255 ) + 1 ) ;
break;
case V_146 :
sprintf ( V_117 , L_49 , ( int ) ( V_116 & 255 ) + 1 ) ;
break;
default:
return - V_77 ;
}
V_93 = F_38 ( V_117 , strlen ( V_117 ) , 0 , V_1 ) ;
V_1 -> V_135 [ V_116 & 255 ] = ( V_116 >> 8 ) ;
}
break;
case V_147 :
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
return 0 ;
default:
return - V_77 ;
}
}
return 0 ;
}
static inline T_1 *
F_48 ( int V_148 )
{
T_1 * V_60 = V_91 ;
while ( V_60 ) {
if ( V_60 -> V_17 == V_148 )
return V_60 ;
V_60 = V_60 -> V_100 ;
}
return ( T_1 * ) 0 ;
}
static int
F_49 ( T_2 * V_53 )
{
T_1 * V_1 = F_48 ( V_53 -> V_16 ) ;
if ( V_1 )
return ( F_43 ( V_53 , V_1 ) ) ;
F_5 ( V_149
L_65 ) ;
return - V_130 ;
}
static int
F_50 ( const T_3 T_6 * V_79 , int V_10 , int V_150 , int V_2 )
{
T_1 * V_1 = F_48 ( V_150 ) ;
if ( V_1 ) {
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
return ( F_38 ( V_79 , V_10 , 1 , V_1 ) ) ;
}
F_5 ( V_149
L_66 ) ;
return - V_130 ;
}
static int
F_51 ( T_3 T_6 * V_79 , int V_10 , int V_150 , int V_2 )
{
T_1 * V_1 = F_48 ( V_150 ) ;
if ( V_1 ) {
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
return ( F_24 ( V_79 , V_10 , V_1 ) ) ;
}
F_5 ( V_149
L_67 ) ;
return - V_130 ;
}
static int
F_52 ( int V_150 , int V_2 , int V_11 , struct V_12 * V_13 )
{
T_1 * V_1 = F_48 ( V_150 ) ;
if ( V_1 ) {
if ( ! ( V_1 -> V_28 & V_110 ) )
return - V_130 ;
* ( V_13 -> V_15 ) = V_11 ;
return ( F_19 ( V_2 , V_13 , V_1 ) ) ;
}
F_5 ( V_149
L_68 ) ;
return - V_130 ;
}
static T_1 *
F_53 ( char * V_150 )
{
T_1 * V_1 ;
int V_93 ;
if ( ! ( V_1 = F_54 ( sizeof( T_1 ) , V_151 ) ) ) {
F_5 ( V_21
L_69 , V_150 ) ;
return ( T_1 * ) 0 ;
}
V_1 -> V_19 . V_152 = V_153 ;
V_1 -> V_19 . V_154 = V_131 ;
V_1 -> V_19 . V_155 = 1 ;
V_1 -> V_19 . V_156 = 4000 ;
V_1 -> V_19 . V_22 = F_49 ;
V_1 -> V_19 . V_157 = F_52 ;
V_1 -> V_19 . V_158 = F_50 ;
V_1 -> V_19 . V_159 = F_51 ;
V_1 -> V_19 . V_68 = V_160 |
#ifdef F_47
V_161 |
V_162 |
#endif
V_163 |
V_164 |
V_165 ;
V_1 -> V_66 = V_127 ;
F_12 ( V_1 -> V_19 . V_150 , V_150 , sizeof( V_1 -> V_19 . V_150 ) ) ;
V_1 -> V_54 = V_1 -> V_57 ;
V_1 -> V_55 = V_1 -> V_57 ;
V_1 -> V_56 = & V_1 -> V_57 [ sizeof( V_1 -> V_57 ) - 1 ] ;
for ( V_93 = 0 ; V_93 < V_131 ; V_93 ++ ) {
V_1 -> V_135 [ V_93 ] = V_136 ;
F_55 ( & V_1 -> V_5 [ V_93 ] ) ;
}
F_55 ( & V_1 -> V_61 ) ;
F_56 ( & V_1 -> V_31 ) ;
V_1 -> V_100 = V_91 ;
V_91 = V_1 ;
if ( ! F_57 ( & V_1 -> V_19 ) ) {
V_91 = V_91 -> V_100 ;
F_5 ( V_21
L_70 , V_150 ) ;
F_58 ( V_1 ) ;
return ( T_1 * ) 0 ;
}
V_1 -> V_17 = V_1 -> V_19 . V_154 ;
return V_1 ;
}
static int
F_45 ( char * V_124 )
{
T_1 * V_1 ;
if ( ! ( V_1 = F_53 ( V_124 ) ) ) {
return - V_166 ;
}
F_5 ( V_64
L_71 ,
V_1 -> V_19 . V_150 ) ;
return 0 ;
}
static int T_9
F_59 ( void )
{
if ( V_167 )
return ( F_45 ( V_167 ) ) ;
return 0 ;
}
static void T_10
F_60 ( void )
{
T_2 V_14 ;
T_1 * V_1 = V_91 ;
T_1 * V_168 ;
int V_93 ;
F_41 () ;
while ( V_1 ) {
V_14 . V_22 = V_169 ;
V_14 . V_16 = V_1 -> V_17 ;
V_1 -> V_19 . V_26 ( & V_14 ) ;
for ( V_93 = 0 ; V_93 < V_131 ; V_93 ++ )
F_1 ( V_1 , V_93 ) ;
V_1 = V_1 -> V_100 ;
}
V_1 = V_91 ;
while ( V_1 ) {
V_168 = V_1 ;
F_2 ( & V_1 -> V_61 ) ;
V_1 = V_1 -> V_100 ;
F_58 ( V_168 ) ;
}
F_5 ( V_170 L_72 ) ;
}

static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
unsigned long * V_4 = F_2 ( V_3 -> V_5 ) ;
return (struct V_1 * ) * V_4 ;
}
static inline struct V_1 * F_3 ( struct V_6 * V_7 )
{
unsigned long * V_4 = F_2 ( V_7 ) ;
return (struct V_1 * ) * V_4 ;
}
static int F_4 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_12 [ 2 ] != V_13 )
return 0 ;
switch ( V_10 -> V_11 -> V_12 [ 12 ] ) {
case V_14 :
F_5 ( & V_8 -> V_15 -> V_16 , L_1
L_2 , V_8 -> V_17 ) ;
break;
case V_18 :
F_5 ( & V_8 -> V_15 -> V_16 , L_3
L_4 , V_8 -> V_17 ) ;
break;
case V_19 :
F_5 ( & V_8 -> V_15 -> V_16 , L_5
L_6 , V_8 -> V_17 ) ;
break;
case V_20 :
F_5 ( & V_8 -> V_15 -> V_16 , L_7
L_8 , V_8 -> V_17 ) ;
break;
case V_21 :
F_5 ( & V_8 -> V_15 -> V_16 , L_9
L_10 , V_8 -> V_17 ) ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_11
L_12 , V_8 -> V_17 ) ;
break;
}
return 1 ;
}
static T_1 F_6 ( struct V_22 * V_16 ,
struct V_23 * V_24 ,
const char * V_25 , T_2 V_26 )
{
struct V_1 * V_8 ;
struct V_6 * V_27 = F_7 ( V_16 ) ;
V_8 = F_3 ( V_27 ) ;
F_8 ( V_8 -> V_28 ) ;
return V_26 ;
}
static T_1 F_9 ( struct V_22 * V_16 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_1 * V_8 ;
struct V_6 * V_27 = F_7 ( V_16 ) ;
unsigned char * V_29 ;
V_8 = F_3 ( V_27 ) ;
if ( ! V_8 -> V_30 )
return 0 ;
V_29 = & V_8 -> V_30 [ 32 ] ;
return snprintf ( V_25 , 20 , L_13 ,
V_29 [ 0 ] , V_29 [ 1 ] , V_29 [ 2 ] , V_29 [ 3 ] ) ;
}
static T_1 F_10 ( struct V_22 * V_16 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_6 * V_27 = F_7 ( V_16 ) ;
struct V_1 * V_8 = F_3 ( V_27 ) ;
return snprintf ( V_25 , 20 , L_14 , V_8 -> V_31 ) ;
}
static T_1 F_11 ( struct V_22 * V_16 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_1 * V_8 ;
struct V_6 * V_27 = F_7 ( V_16 ) ;
V_8 = F_3 ( V_27 ) ;
return snprintf ( V_25 , 20 , L_15 ,
V_8 -> V_32 & V_33 ?
L_16 : L_17 ) ;
}
static int F_12 ( T_3 V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_13 ( V_36 ) ; V_35 ++ )
if ( V_36 [ V_35 ] == V_34 )
return 0 ;
return 1 ;
}
static int F_14 ( T_3 V_34 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_13 ( V_37 ) ; V_35 ++ )
if ( V_37 [ V_35 ] == V_34 )
return 0 ;
return 1 ;
}
static int F_15 ( T_3 V_34 )
{
return F_12 ( V_34 ) ||
F_14 ( V_34 ) ;
}
static T_1 F_16 ( struct V_22 * V_16 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_1 * V_8 ;
struct V_6 * V_27 = F_7 ( V_16 ) ;
V_8 = F_3 ( V_27 ) ;
return snprintf ( V_25 , 20 , L_14 , F_15 ( V_8 -> V_34 ) ) ;
}
static inline int F_17 ( unsigned char V_38 [] )
{
return ( V_38 [ 3 ] & 0xC0 ) == 0x40 ;
}
static T_1 F_18 ( struct V_22 * V_16 ,
struct V_23 * V_24 , char * V_25 )
{
T_1 V_39 = 0 ;
unsigned char V_40 ;
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_41 * V_42 ;
unsigned long V_43 ;
V_3 = F_19 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_42 = V_3 -> V_45 ;
if ( ! V_42 ) {
F_21 ( & V_8 -> V_44 , V_43 ) ;
return - V_46 ;
}
if ( ! F_17 ( V_42 -> V_38 ) ) {
F_21 ( & V_8 -> V_44 , V_43 ) ;
V_39 = snprintf ( V_25 , V_47 , L_18 ) ;
return V_39 ;
}
V_40 = V_42 -> V_48 ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
if ( V_40 > V_49 )
V_40 = V_49 ;
V_39 = snprintf ( V_25 , V_47 , L_19 , V_50 [ V_40 ] ) ;
return V_39 ;
}
static T_1 F_22 ( struct V_22 * V_16 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_41 * V_42 ;
unsigned long V_43 ;
unsigned char V_51 [ 8 ] ;
V_3 = F_19 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_42 = V_3 -> V_45 ;
if ( ! V_42 ) {
F_21 ( & V_8 -> V_44 , V_43 ) ;
return - V_46 ;
}
memcpy ( V_51 , V_42 -> V_38 , sizeof( V_51 ) ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
return snprintf ( V_25 , 20 , L_20 ,
V_51 [ 0 ] , V_51 [ 1 ] , V_51 [ 2 ] , V_51 [ 3 ] ,
V_51 [ 4 ] , V_51 [ 5 ] , V_51 [ 6 ] , V_51 [ 7 ] ) ;
}
static T_1 F_23 ( struct V_22 * V_16 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_41 * V_42 ;
unsigned long V_43 ;
unsigned char V_52 [ 16 ] ;
V_3 = F_19 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_42 = V_3 -> V_45 ;
if ( ! V_42 ) {
F_21 ( & V_8 -> V_44 , V_43 ) ;
return - V_46 ;
}
memcpy ( V_52 , V_42 -> V_53 , sizeof( V_52 ) ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
return snprintf ( V_25 , 16 * 2 + 2 ,
L_21
L_22 ,
V_52 [ 0 ] , V_52 [ 1 ] , V_52 [ 2 ] , V_52 [ 3 ] ,
V_52 [ 4 ] , V_52 [ 5 ] , V_52 [ 6 ] , V_52 [ 7 ] ,
V_52 [ 8 ] , V_52 [ 9 ] , V_52 [ 10 ] , V_52 [ 11 ] ,
V_52 [ 12 ] , V_52 [ 13 ] , V_52 [ 14 ] , V_52 [ 15 ] ) ;
}
static inline void F_24 ( struct V_54 * V_55 , struct V_9 * V_10 )
{
F_25 ( & V_10 -> V_55 , V_55 ) ;
}
static inline T_3 F_26 ( struct V_1 * V_8 )
{
T_3 V_56 ;
if ( F_27 ( ! ( V_8 -> V_32 & V_33 ) ) )
return V_8 -> V_57 . V_58 ( V_8 ) ;
if ( ( * ( V_8 -> V_59 ) & 1 ) == ( V_8 -> V_60 ) ) {
V_56 = * ( V_8 -> V_59 ) ;
( V_8 -> V_59 ) ++ ;
V_8 -> V_31 -- ;
} else {
V_56 = V_61 ;
}
if ( V_8 -> V_59 == ( V_8 -> V_62 + V_8 -> V_63 ) ) {
V_8 -> V_59 = V_8 -> V_62 ;
V_8 -> V_60 ^= 1 ;
}
return V_56 ;
}
static void F_28 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( F_29 ( V_8 -> V_32 & V_33 ) )
V_10 -> V_64 |= 1 | ( V_8 -> V_65 [ V_10 -> V_66 . V_67 ] << 1 ) ;
}
static void F_30 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_43 ;
F_28 ( V_8 , V_10 ) ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
F_24 ( & V_8 -> V_68 , V_10 ) ;
V_8 -> V_69 ++ ;
F_31 ( V_8 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
}
static inline void F_32 ( struct V_9 * V_10 )
{
if ( F_33 ( F_34 ( & V_10 -> V_55 ) ) )
return;
F_35 ( & V_10 -> V_55 ) ;
}
static inline int F_36 ( unsigned char V_38 [] )
{
return memcmp ( V_38 , V_70 , 8 ) == 0 ;
}
static inline int F_37 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_30 )
return 0 ;
if ( ( V_8 -> V_30 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_8 ,
unsigned char V_38 [] , int V_71 , int * V_72 , int * V_73 )
{
int V_35 , V_74 = 0 ;
F_39 ( V_75 , V_76 ) ;
memset ( & V_75 [ 0 ] , 0 , V_76 >> 3 ) ;
for ( V_35 = 0 ; V_35 < V_8 -> V_77 ; V_35 ++ ) {
if ( V_8 -> V_16 [ V_35 ] -> V_71 == V_71 && V_8 -> V_16 [ V_35 ] -> V_72 != - 1 )
F_40 ( V_8 -> V_16 [ V_35 ] -> V_72 , V_75 ) ;
}
for ( V_35 = 0 ; V_35 < V_76 ; V_35 ++ ) {
if ( ! F_41 ( V_35 , V_75 ) ) {
* V_72 = V_35 ;
* V_73 = 0 ;
V_74 = 1 ;
break;
}
}
return ! V_74 ;
}
static int F_42 ( struct V_1 * V_8 , int V_78 ,
struct V_41 * V_22 ,
struct V_41 * V_79 [] , int * V_80 )
{
int V_81 = V_8 -> V_77 ;
int V_35 ;
unsigned char V_82 [ 8 ] , V_83 [ 8 ] ;
struct V_41 * V_84 ;
if ( V_81 >= V_76 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_23
L_24 ) ;
return - 1 ;
}
if ( V_22 -> V_73 != - 1 )
goto V_85;
if ( V_22 -> V_38 [ 4 ] == 0 ) {
if ( F_38 ( V_8 , V_22 -> V_38 ,
V_22 -> V_71 , & V_22 -> V_72 , & V_22 -> V_73 ) != 0 )
return - 1 ;
goto V_85;
}
memcpy ( V_82 , V_22 -> V_38 , 8 ) ;
V_82 [ 4 ] = 0 ;
for ( V_35 = 0 ; V_35 < V_81 ; V_35 ++ ) {
V_84 = V_8 -> V_16 [ V_35 ] ;
memcpy ( V_83 , V_84 -> V_38 , 8 ) ;
V_83 [ 4 ] = 0 ;
if ( memcmp ( V_82 , V_83 , 8 ) == 0 ) {
V_22 -> V_71 = V_84 -> V_71 ;
V_22 -> V_72 = V_84 -> V_72 ;
V_22 -> V_73 = V_22 -> V_38 [ 4 ] ;
break;
}
}
if ( V_22 -> V_73 == - 1 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_25
L_26
L_27 ) ;
return - 1 ;
}
V_85:
V_8 -> V_16 [ V_81 ] = V_22 ;
V_8 -> V_77 ++ ;
V_79 [ * V_80 ] = V_22 ;
( * V_80 ) ++ ;
F_44 ( & V_8 -> V_15 -> V_16 , L_28 ,
F_45 ( V_22 -> V_86 ) , V_78 ,
V_22 -> V_71 , V_22 -> V_72 , V_22 -> V_73 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_8 , int V_78 ,
int V_87 , struct V_41 * V_88 ,
struct V_41 * V_79 [] , int * V_80 ,
struct V_41 * V_89 [] , int * V_90 )
{
F_47 ( V_87 < 0 || V_87 >= V_76 ) ;
V_89 [ * V_90 ] = V_8 -> V_16 [ V_87 ] ;
( * V_90 ) ++ ;
if ( V_88 -> V_72 == - 1 ) {
V_88 -> V_72 = V_8 -> V_16 [ V_87 ] -> V_72 ;
V_88 -> V_73 = V_8 -> V_16 [ V_87 ] -> V_73 ;
}
V_8 -> V_16 [ V_87 ] = V_88 ;
V_79 [ * V_80 ] = V_88 ;
( * V_80 ) ++ ;
F_44 ( & V_8 -> V_15 -> V_16 , L_29 ,
F_45 ( V_88 -> V_86 ) , V_78 , V_88 -> V_71 ,
V_88 -> V_72 , V_88 -> V_73 ) ;
}
static void F_48 ( struct V_1 * V_8 , int V_78 , int V_87 ,
struct V_41 * V_89 [] , int * V_90 )
{
int V_35 ;
struct V_41 * V_84 ;
F_47 ( V_87 < 0 || V_87 >= V_76 ) ;
V_84 = V_8 -> V_16 [ V_87 ] ;
V_89 [ * V_90 ] = V_8 -> V_16 [ V_87 ] ;
( * V_90 ) ++ ;
for ( V_35 = V_87 ; V_35 < V_8 -> V_77 - 1 ; V_35 ++ )
V_8 -> V_16 [ V_35 ] = V_8 -> V_16 [ V_35 + 1 ] ;
V_8 -> V_77 -- ;
F_44 ( & V_8 -> V_15 -> V_16 , L_30 ,
F_45 ( V_84 -> V_86 ) , V_78 , V_84 -> V_71 , V_84 -> V_72 ,
V_84 -> V_73 ) ;
}
static void F_49 ( struct V_1 * V_8 ,
struct V_41 * V_79 )
{
unsigned long V_43 ;
int V_35 , V_91 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
for ( V_35 = 0 ; V_35 < V_8 -> V_77 ; V_35 ++ ) {
if ( V_8 -> V_16 [ V_35 ] == V_79 ) {
for ( V_91 = V_35 ; V_91 < V_8 -> V_77 - 1 ; V_91 ++ )
V_8 -> V_16 [ V_91 ] = V_8 -> V_16 [ V_91 + 1 ] ;
V_8 -> V_77 -- ;
break;
}
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
F_50 ( V_79 ) ;
}
static inline int F_51 ( struct V_41 * V_92 ,
struct V_41 * V_93 )
{
if ( memcmp ( V_92 -> V_38 , V_93 -> V_38 ,
sizeof( V_92 -> V_38 ) ) != 0 )
return 0 ;
if ( memcmp ( V_92 -> V_53 , V_93 -> V_53 ,
sizeof( V_92 -> V_53 ) ) != 0 )
return 0 ;
if ( memcmp ( V_92 -> V_94 , V_93 -> V_94 , sizeof( V_92 -> V_94 ) ) != 0 )
return 0 ;
if ( memcmp ( V_92 -> V_95 , V_93 -> V_95 , sizeof( V_92 -> V_95 ) ) != 0 )
return 0 ;
if ( V_92 -> V_86 != V_93 -> V_86 )
return 0 ;
if ( V_92 -> V_71 != V_93 -> V_71 )
return 0 ;
return 1 ;
}
static int F_52 ( struct V_41 * V_96 ,
struct V_41 * V_97 [] , int V_98 ,
int * V_99 )
{
int V_35 ;
#define F_53 0
#define F_54 1
#define F_55 2
for ( V_35 = 0 ; V_35 < V_98 ; V_35 ++ ) {
if ( V_97 [ V_35 ] == NULL )
continue;
if ( F_56 ( V_96 -> V_38 , V_97 [ V_35 ] -> V_38 ) ) {
* V_99 = V_35 ;
if ( F_51 ( V_96 , V_97 [ V_35 ] ) )
return F_55 ;
else
return F_54 ;
}
}
* V_99 = - 1 ;
return F_53 ;
}
static void F_57 ( struct V_1 * V_8 , int V_78 ,
struct V_41 * V_84 [] , int V_100 )
{
int V_35 , V_87 , V_101 , V_102 = 0 ;
struct V_41 * V_103 ;
unsigned long V_43 ;
struct V_41 * * V_79 , * * V_89 ;
int V_80 , V_90 ;
struct V_6 * V_7 = NULL ;
V_79 = F_58 ( sizeof( * V_79 ) * V_76 ,
V_104 ) ;
V_89 = F_58 ( sizeof( * V_89 ) * V_76 ,
V_104 ) ;
if ( ! V_79 || ! V_89 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_31
L_32 ) ;
goto V_105;
}
F_20 ( & V_8 -> V_106 , V_43 ) ;
V_35 = 0 ;
V_90 = 0 ;
V_80 = 0 ;
while ( V_35 < V_8 -> V_77 ) {
V_103 = V_8 -> V_16 [ V_35 ] ;
V_101 = F_52 ( V_103 , V_84 , V_100 , & V_87 ) ;
if ( V_101 == F_53 ) {
V_102 ++ ;
F_48 ( V_8 , V_78 , V_35 ,
V_89 , & V_90 ) ;
continue;
} else if ( V_101 == F_54 ) {
V_102 ++ ;
F_46 ( V_8 , V_78 , V_35 , V_84 [ V_87 ] ,
V_79 , & V_80 , V_89 , & V_90 ) ;
V_84 [ V_87 ] = NULL ;
}
V_35 ++ ;
}
for ( V_35 = 0 ; V_35 < V_100 ; V_35 ++ ) {
if ( ! V_84 [ V_35 ] )
continue;
V_101 = F_52 ( V_84 [ V_35 ] , V_8 -> V_16 ,
V_8 -> V_77 , & V_87 ) ;
if ( V_101 == F_53 ) {
V_102 ++ ;
if ( F_42 ( V_8 , V_78 , V_84 [ V_35 ] ,
V_79 , & V_80 ) != 0 )
break;
V_84 [ V_35 ] = NULL ;
} else if ( V_101 == F_54 ) {
V_102 ++ ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_33 ) ;
}
}
F_21 ( & V_8 -> V_106 , V_43 ) ;
if ( V_78 == - 1 || ! V_102 )
goto V_105;
V_7 = V_8 -> V_28 ;
for ( V_35 = 0 ; V_35 < V_90 ; V_35 ++ ) {
struct V_2 * V_3 =
F_59 ( V_7 , V_89 [ V_35 ] -> V_71 ,
V_89 [ V_35 ] -> V_72 , V_89 [ V_35 ] -> V_73 ) ;
if ( V_3 != NULL ) {
F_60 ( V_3 ) ;
F_61 ( V_3 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_34
L_35 , V_78 , V_89 [ V_35 ] -> V_71 ,
V_89 [ V_35 ] -> V_72 , V_89 [ V_35 ] -> V_73 ) ;
}
F_50 ( V_89 [ V_35 ] ) ;
V_89 [ V_35 ] = NULL ;
}
for ( V_35 = 0 ; V_35 < V_80 ; V_35 ++ ) {
if ( F_62 ( V_7 , V_79 [ V_35 ] -> V_71 ,
V_79 [ V_35 ] -> V_72 , V_79 [ V_35 ] -> V_73 ) == 0 )
continue;
F_5 ( & V_8 -> V_15 -> V_16 , L_36
L_37 , V_78 , V_79 [ V_35 ] -> V_71 ,
V_79 [ V_35 ] -> V_72 , V_79 [ V_35 ] -> V_73 ) ;
F_49 ( V_8 , V_79 [ V_35 ] ) ;
}
V_105:
F_50 ( V_79 ) ;
F_50 ( V_89 ) ;
}
static struct V_41 * F_63 ( struct V_1 * V_8 ,
int V_71 , int V_72 , int V_73 )
{
int V_35 ;
struct V_41 * V_84 ;
for ( V_35 = 0 ; V_35 < V_8 -> V_77 ; V_35 ++ ) {
V_84 = V_8 -> V_16 [ V_35 ] ;
if ( V_84 -> V_71 == V_71 && V_84 -> V_72 == V_72 && V_84 -> V_73 == V_73 )
return V_84 ;
}
return NULL ;
}
static int F_64 ( struct V_2 * V_3 )
{
struct V_41 * V_84 ;
unsigned long V_43 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 ) ;
F_20 ( & V_8 -> V_106 , V_43 ) ;
V_84 = F_63 ( V_8 , F_65 ( V_3 ) ,
F_66 ( V_3 ) , V_3 -> V_73 ) ;
if ( V_84 != NULL )
V_3 -> V_45 = V_84 ;
F_21 ( & V_8 -> V_106 , V_43 ) ;
return 0 ;
}
static void F_67 ( struct V_2 * V_3 )
{
}
static void F_68 ( struct V_1 * V_8 )
{
int V_35 ;
if ( ! V_8 -> V_107 )
return;
for ( V_35 = 0 ; V_35 < V_8 -> V_108 ; V_35 ++ ) {
F_50 ( V_8 -> V_107 [ V_35 ] ) ;
V_8 -> V_107 [ V_35 ] = NULL ;
}
F_50 ( V_8 -> V_107 ) ;
V_8 -> V_107 = NULL ;
}
static int F_69 ( struct V_1 * V_8 )
{
int V_35 ;
if ( V_8 -> V_109 <= 0 )
return 0 ;
V_8 -> V_107 = F_58 ( sizeof( * V_8 -> V_107 ) * V_8 -> V_108 ,
V_104 ) ;
if ( ! V_8 -> V_107 )
return - V_110 ;
for ( V_35 = 0 ; V_35 < V_8 -> V_108 ; V_35 ++ ) {
V_8 -> V_107 [ V_35 ] = F_70 ( sizeof( * V_8 -> V_107 [ V_35 ] ) *
V_8 -> V_109 , V_104 ) ;
if ( ! V_8 -> V_107 [ V_35 ] )
goto V_111;
}
return 0 ;
V_111:
F_68 ( V_8 ) ;
return - V_110 ;
}
static void F_71 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_112 * V_113 , * V_114 ;
T_4 V_115 ;
V_113 = & V_10 -> V_116 [ V_8 -> V_117 - 1 ] ;
V_114 = V_8 -> V_107 [ V_10 -> V_118 ] ;
V_113 -> V_119 = V_120 ;
V_113 -> V_121 = sizeof( * V_113 ) *
( V_10 -> V_66 . V_122 - V_8 -> V_117 ) ;
V_115 = F_72 ( V_8 -> V_15 , V_114 , V_113 -> V_121 ,
V_123 ) ;
V_113 -> V_124 . V_125 = ( T_3 ) ( V_115 & 0x0FFFFFFFFULL ) ;
V_113 -> V_124 . V_126 = ( T_3 ) ( ( V_115 >> 32 ) & 0x0FFFFFFFFULL ) ;
}
static void F_73 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_112 * V_113 ;
union V_127 V_115 ;
if ( V_10 -> V_66 . V_122 <= V_8 -> V_117 )
return;
V_113 = & V_10 -> V_116 [ V_8 -> V_117 - 1 ] ;
V_115 . V_128 . V_125 = V_113 -> V_124 . V_125 ;
V_115 . V_128 . V_126 = V_113 -> V_124 . V_126 ;
F_74 ( V_8 -> V_15 , V_115 . V_129 , V_113 -> V_121 , V_123 ) ;
}
static void F_75 ( struct V_9 * V_130 )
{
struct V_131 * V_132 ;
struct V_1 * V_8 ;
struct V_133 * V_134 ;
unsigned char V_135 ;
unsigned char V_136 ;
unsigned char V_137 ;
unsigned long V_138 ;
V_134 = V_130 -> V_11 ;
V_132 = (struct V_131 * ) V_130 -> V_139 ;
V_8 = V_130 -> V_8 ;
F_76 ( V_132 ) ;
if ( V_130 -> V_66 . V_122 > V_8 -> V_117 )
F_73 ( V_8 , V_130 ) ;
V_132 -> V_140 = ( V_141 << 16 ) ;
V_132 -> V_140 |= ( V_142 << 8 ) ;
V_132 -> V_140 |= V_134 -> V_143 ;
if ( V_144 < sizeof( V_134 -> V_12 ) )
V_138 = V_144 ;
else
V_138 = sizeof( V_134 -> V_12 ) ;
if ( V_134 -> V_145 < V_138 )
V_138 = V_134 -> V_145 ;
memcpy ( V_132 -> V_146 , V_134 -> V_12 , V_138 ) ;
F_77 ( V_132 , V_134 -> V_147 ) ;
if ( V_134 -> V_148 == 0 ) {
V_132 -> V_149 ( V_132 ) ;
F_78 ( V_8 , V_130 ) ;
return;
}
switch ( V_134 -> V_148 ) {
case V_150 :
if ( V_134 -> V_143 ) {
V_135 = 0xf & V_134 -> V_12 [ 2 ] ;
V_136 = V_134 -> V_12 [ 12 ] ;
V_137 = V_134 -> V_12 [ 13 ] ;
}
if ( V_134 -> V_143 == V_151 ) {
if ( F_4 ( V_8 , V_130 ) ) {
V_132 -> V_140 = V_152 << 16 ;
break;
}
if ( V_135 == V_153 ) {
if ( V_130 -> V_154 . V_155 [ 0 ] == V_156 )
break;
if ( ( V_136 == 0x25 ) && ( V_137 == 0x0 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_38
L_39 , V_130 ) ;
break;
}
}
if ( V_135 == V_157 ) {
if ( ( V_136 == 0x04 ) && ( V_137 == 0x03 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_38
L_40
L_41
L_42 , V_130 ) ;
break;
}
}
if ( V_135 == V_158 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_38
L_43
L_44 ,
V_130 , V_136 , V_137 ) ;
V_132 -> V_140 = V_152 << 16 ;
break;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_45
L_46
L_47
L_48
L_49
L_50
L_51 ,
V_130 , V_135 , V_136 , V_137 ,
V_132 -> V_140 ,
V_132 -> V_159 [ 0 ] , V_132 -> V_159 [ 1 ] ,
V_132 -> V_159 [ 2 ] , V_132 -> V_159 [ 3 ] ,
V_132 -> V_159 [ 4 ] , V_132 -> V_159 [ 5 ] ,
V_132 -> V_159 [ 6 ] , V_132 -> V_159 [ 7 ] ,
V_132 -> V_159 [ 8 ] , V_132 -> V_159 [ 9 ] ,
V_132 -> V_159 [ 10 ] , V_132 -> V_159 [ 11 ] ,
V_132 -> V_159 [ 12 ] , V_132 -> V_159 [ 13 ] ,
V_132 -> V_159 [ 14 ] , V_132 -> V_159 [ 15 ] ) ;
break;
}
if ( V_134 -> V_143 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_52
L_47
L_53 ,
V_130 , V_134 -> V_143 ,
V_135 , V_136 , V_137 ,
V_132 -> V_140 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_54
L_55 , V_130 ) ,
V_132 -> V_140 = V_160 << 16 ;
}
break;
case V_161 :
break;
case V_162 :
F_5 ( & V_8 -> V_15 -> V_16 , L_56
L_57
L_58 , V_130 ) ;
break;
case V_163 : {
V_132 -> V_140 = V_160 << 16 ;
}
break;
case V_164 :
F_5 ( & V_8 -> V_15 -> V_16 , L_59
L_60 , V_130 ) ;
break;
case V_165 :
V_132 -> V_140 = V_166 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_61 , V_130 ) ;
break;
case V_167 :
V_132 -> V_140 = V_166 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_62 , V_130 ) ;
break;
case V_168 :
V_132 -> V_140 = V_169 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_63 ,
V_130 , V_134 -> V_143 ) ;
break;
case V_170 :
V_132 -> V_140 = V_166 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_64 , V_130 ) ;
break;
case V_171 :
V_132 -> V_140 = V_152 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_65
L_66 , V_130 ) ;
break;
case V_172 :
V_132 -> V_140 = V_173 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_67 , V_130 ) ;
break;
case V_174 :
V_132 -> V_140 = V_166 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_68 ) ;
break;
default:
V_132 -> V_140 = V_166 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_69 ,
V_130 , V_134 -> V_148 ) ;
}
V_132 -> V_149 ( V_132 ) ;
F_78 ( V_8 , V_130 ) ;
}
static int F_79 ( struct V_1 * V_8 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_80 ( & V_175 , sizeof( V_8 ) ) ;
if ( V_7 == NULL )
goto V_176;
V_7 -> V_177 = 0 ;
V_7 -> V_178 = 0 ;
V_7 -> V_179 = - 1 ;
V_7 -> V_180 = 3 ;
V_7 -> V_181 = V_182 ;
V_7 -> V_183 = V_184 ;
V_7 -> V_185 = V_184 ;
V_7 -> V_186 = V_8 -> V_108 ;
V_7 -> V_187 = V_8 -> V_108 ;
V_7 -> V_188 = V_8 -> V_189 ;
V_8 -> V_28 = V_7 ;
V_7 -> V_45 [ 0 ] = ( unsigned long ) V_8 ;
V_7 -> V_190 = V_8 -> V_191 [ V_8 -> V_192 ] ;
V_7 -> V_193 = V_7 -> V_190 ;
error = F_81 ( V_7 , & V_8 -> V_15 -> V_16 ) ;
if ( error )
goto V_194;
F_82 ( V_7 ) ;
return 0 ;
V_194:
F_43 ( & V_8 -> V_15 -> V_16 , L_70
L_71 , V_8 -> V_17 ) ;
F_83 ( V_7 ) ;
return error ;
V_176:
F_43 ( & V_8 -> V_15 -> V_16 , L_72
L_71 , V_8 -> V_17 ) ;
return - V_110 ;
}
static void F_84 ( struct V_195 * V_15 ,
struct V_9 * V_10 , int V_196 , int V_197 )
{
int V_35 ;
union V_127 V_198 ;
for ( V_35 = 0 ; V_35 < V_196 ; V_35 ++ ) {
V_198 . V_128 . V_125 = V_10 -> V_116 [ V_35 ] . V_124 . V_125 ;
V_198 . V_128 . V_126 = V_10 -> V_116 [ V_35 ] . V_124 . V_126 ;
F_74 ( V_15 , ( V_199 ) V_198 . V_129 , V_10 -> V_116 [ V_35 ] . V_121 ,
V_197 ) ;
}
}
static void F_85 ( struct V_195 * V_15 ,
struct V_9 * V_130 ,
unsigned char * V_25 ,
T_2 V_200 ,
int V_197 )
{
T_4 V_198 ;
if ( V_200 == 0 || V_197 == V_201 ) {
V_130 -> V_66 . V_67 = 0 ;
V_130 -> V_66 . V_122 = 0 ;
return;
}
V_198 = ( T_4 ) F_72 ( V_15 , V_25 , V_200 , V_197 ) ;
V_130 -> V_116 [ 0 ] . V_124 . V_125 =
( T_3 ) ( V_198 & ( T_4 ) 0x00000000FFFFFFFF ) ;
V_130 -> V_116 [ 0 ] . V_124 . V_126 =
( T_3 ) ( ( V_198 >> 32 ) & ( T_4 ) 0x00000000FFFFFFFF ) ;
V_130 -> V_116 [ 0 ] . V_121 = V_200 ;
V_130 -> V_66 . V_67 = ( V_202 ) 1 ;
V_130 -> V_66 . V_122 = ( V_203 ) 1 ;
}
static inline void F_86 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_87 ( V_204 ) ;
V_10 -> V_205 = & V_204 ;
F_30 ( V_8 , V_10 ) ;
F_88 ( & V_204 ) ;
}
static void F_89 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_197 )
{
int V_206 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_86 ( V_8 , V_10 ) ;
V_206 ++ ;
} while ( F_4 ( V_8 , V_10 ) && V_206 <= 3 );
F_84 ( V_8 -> V_15 , V_10 , 1 , V_197 ) ;
}
static void F_90 ( struct V_9 * V_130 )
{
struct V_133 * V_134 ;
struct V_22 * V_207 = & V_130 -> V_8 -> V_15 -> V_16 ;
V_134 = V_130 -> V_11 ;
switch ( V_134 -> V_148 ) {
case V_150 :
F_5 ( V_207 , L_73 , V_130 ) ;
F_5 ( V_207 , L_74 , V_130 ,
V_134 -> V_143 ) ;
if ( V_134 -> V_143 == 0 )
F_5 ( V_207 , L_75
L_76
L_77
L_78 ) ;
break;
case V_161 :
F_44 ( V_207 , L_79 ) ;
break;
case V_162 :
F_5 ( V_207 , L_80 , V_130 ) ;
break;
case V_163 : {
F_5 ( V_207 , L_81
L_82 , V_130 ) ;
}
break;
case V_164 :
F_5 ( V_207 , L_83 , V_130 ) ;
break;
case V_165 :
F_5 ( V_207 , L_84 , V_130 ) ;
break;
case V_167 :
F_5 ( V_207 , L_62 , V_130 ) ;
break;
case V_168 :
F_5 ( V_207 , L_85 , V_130 ) ;
break;
case V_170 :
F_5 ( V_207 , L_64 , V_130 ) ;
break;
case V_171 :
F_5 ( V_207 , L_86 , V_130 ) ;
break;
case V_172 :
F_5 ( V_207 , L_87 , V_130 ) ;
break;
case V_174 :
F_5 ( V_207 , L_68 ) ;
break;
default:
F_5 ( V_207 , L_69 , V_130 ,
V_134 -> V_148 ) ;
}
}
static int F_91 ( struct V_1 * V_8 , unsigned char * V_38 ,
unsigned char V_208 , unsigned char * V_25 ,
unsigned char V_209 )
{
int V_210 = V_211 ;
struct V_9 * V_10 ;
struct V_133 * V_134 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - V_110 ;
}
F_93 ( V_10 , V_212 , V_8 , V_25 , V_209 , V_208 , V_38 , V_213 ) ;
F_89 ( V_8 , V_10 , V_214 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 && V_134 -> V_148 != V_161 ) {
F_90 ( V_10 ) ;
V_210 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_210 ;
}
static int F_95 ( struct V_1 * V_8 , unsigned char * V_38 )
{
int V_210 = V_211 ;
struct V_9 * V_10 ;
struct V_133 * V_134 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - V_110 ;
}
F_93 ( V_10 , V_215 , V_8 , NULL , 0 , 0 , V_38 , V_216 ) ;
F_86 ( V_8 , V_10 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 ) {
F_90 ( V_10 ) ;
V_210 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_210 ;
}
static void F_96 ( struct V_1 * V_8 ,
unsigned char * V_38 , unsigned char * V_48 )
{
int V_210 ;
unsigned char * V_25 ;
* V_48 = V_49 ;
V_25 = F_58 ( 64 , V_104 ) ;
if ( ! V_25 )
return;
V_210 = F_91 ( V_8 , V_38 , 0xC1 , V_25 , 64 ) ;
if ( V_210 == 0 )
* V_48 = V_25 [ 8 ] ;
if ( * V_48 > V_49 )
* V_48 = V_49 ;
F_50 ( V_25 ) ;
return;
}
static int F_97 ( struct V_1 * V_8 , unsigned char * V_38 ,
unsigned char * V_53 , int V_200 )
{
int V_210 ;
unsigned char * V_25 ;
if ( V_200 > 16 )
V_200 = 16 ;
V_25 = F_58 ( 64 , V_104 ) ;
if ( ! V_25 )
return - 1 ;
V_210 = F_91 ( V_8 , V_38 , 0x83 , V_25 , 64 ) ;
if ( V_210 == 0 )
memcpy ( V_53 , & V_25 [ 8 ] , V_200 ) ;
F_50 ( V_25 ) ;
return V_210 != 0 ;
}
static int F_98 ( struct V_1 * V_8 , int V_217 ,
struct V_218 * V_25 , int V_209 ,
int V_219 )
{
int V_210 = V_211 ;
struct V_9 * V_10 ;
unsigned char V_38 [ 8 ] ;
struct V_133 * V_134 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - 1 ;
}
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
F_93 ( V_10 , V_217 ? V_220 : V_221 , V_8 ,
V_25 , V_209 , 0 , V_38 , V_213 ) ;
if ( V_219 )
V_10 -> V_154 . V_155 [ 1 ] = V_219 ;
F_89 ( V_8 , V_10 , V_214 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 &&
V_134 -> V_148 != V_161 ) {
F_90 ( V_10 ) ;
V_210 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_210 ;
}
static inline int F_99 ( struct V_1 * V_8 ,
struct V_218 * V_25 ,
int V_209 , int V_219 )
{
return F_98 ( V_8 , 0 , V_25 , V_209 , V_219 ) ;
}
static inline int F_100 ( struct V_1 * V_8 ,
struct V_218 * V_25 , int V_209 )
{
return F_98 ( V_8 , 1 , V_25 , V_209 , 0 ) ;
}
static inline void F_101 ( struct V_41 * V_22 ,
int V_71 , int V_72 , int V_73 )
{
V_22 -> V_71 = V_71 ;
V_22 -> V_72 = V_72 ;
V_22 -> V_73 = V_73 ;
}
static int F_102 ( struct V_1 * V_8 ,
unsigned char V_38 [] , struct V_41 * V_222 ,
unsigned char * V_223 )
{
#define F_103 43
#define F_104 "$DR-10"
#define F_105 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_106 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_224 ;
unsigned char * V_225 ;
V_224 = F_58 ( F_106 , V_104 ) ;
if ( ! V_224 )
goto V_226;
if ( F_91 ( V_8 , V_38 , 0 , V_224 ,
( unsigned char ) F_106 ) != 0 ) {
F_43 ( & V_8 -> V_15 -> V_16 ,
L_89 ) ;
goto V_226;
}
V_222 -> V_86 = ( V_224 [ 0 ] & 0x1f ) ;
memcpy ( V_222 -> V_38 , V_38 , 8 ) ;
memcpy ( V_222 -> V_95 , & V_224 [ 8 ] ,
sizeof( V_222 -> V_95 ) ) ;
memcpy ( V_222 -> V_94 , & V_224 [ 16 ] ,
sizeof( V_222 -> V_94 ) ) ;
memset ( V_222 -> V_53 , 0 ,
sizeof( V_222 -> V_53 ) ) ;
F_97 ( V_8 , V_38 , V_222 -> V_53 ,
sizeof( V_222 -> V_53 ) ) ;
if ( V_222 -> V_86 == V_227 &&
F_17 ( V_38 ) )
F_96 ( V_8 , V_38 , & V_222 -> V_48 ) ;
else
V_222 -> V_48 = V_49 ;
if ( V_223 ) {
V_225 = & V_224 [ F_103 ] ;
* V_223 = ( V_222 -> V_86 == V_228 &&
strncmp ( V_225 , F_104 ,
F_105 ) == 0 ) ;
}
F_50 ( V_224 ) ;
return 0 ;
V_226:
F_50 ( V_224 ) ;
return 1 ;
}
static int F_107 ( struct V_1 * V_8 , struct V_41 * V_22 )
{
int V_35 ;
for ( V_35 = 0 ; V_229 [ V_35 ] ; V_35 ++ )
if ( strncmp ( V_22 -> V_94 , V_229 [ V_35 ] ,
strlen ( V_229 [ V_35 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_108 ( struct V_1 * V_8 ,
V_202 * V_230 , int * V_71 , int * V_72 , int * V_73 ,
struct V_41 * V_22 )
{
T_3 V_51 ;
if ( F_17 ( V_230 ) ) {
if ( F_27 ( F_37 ( V_8 ) ) ) {
V_51 = F_109 ( * ( ( V_231 * ) V_230 ) ) ;
* V_71 = 0 ;
* V_72 = 0 ;
* V_73 = ( V_51 & 0x3fff ) + 1 ;
} else {
V_51 = F_109 ( * ( ( V_231 * ) V_230 ) ) ;
if ( F_107 ( V_8 , V_22 ) ) {
* V_71 = 1 ;
* V_72 = ( V_51 >> 16 ) & 0x3fff ;
* V_73 = V_51 & 0x00ff ;
} else {
* V_71 = 0 ;
* V_73 = 0 ;
* V_72 = V_51 & 0x3fff ;
}
}
} else {
if ( F_36 ( V_230 ) )
if ( F_27 ( F_37 ( V_8 ) ) ) {
* V_71 = 0 ;
* V_72 = 0 ;
* V_73 = 0 ;
return;
} else
* V_71 = 3 ;
else
* V_71 = 2 ;
* V_72 = - 1 ;
* V_73 = - 1 ;
}
}
static int F_110 ( struct V_1 * V_8 ,
struct V_41 * V_232 ,
struct V_41 * V_222 , V_202 * V_230 ,
int V_71 , int V_72 , int V_73 , unsigned long V_233 [] ,
int * V_234 )
{
unsigned char V_38 [ 8 ] ;
if ( F_41 ( V_72 , V_233 ) )
return 0 ;
if ( ! F_17 ( V_230 ) )
return 0 ;
if ( ! F_107 ( V_8 , V_232 ) )
return 0 ;
if ( V_73 == 0 )
return 0 ;
memset ( V_38 , 0 , 8 ) ;
V_38 [ 3 ] = V_72 ;
if ( F_36 ( V_38 ) )
return 0 ;
if ( F_37 ( V_8 ) )
return 0 ;
#define F_111 32
if ( * V_234 >= F_111 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_90
L_91
L_92 ) ;
return 0 ;
}
if ( F_102 ( V_8 , V_38 , V_222 , NULL ) )
return 0 ;
( * V_234 ) ++ ;
F_101 ( V_222 , V_71 , V_72 , 0 ) ;
F_40 ( V_72 , V_233 ) ;
return 1 ;
}
static int F_112 ( struct V_1 * V_8 ,
int V_235 ,
struct V_218 * V_236 , T_3 * V_237 ,
struct V_218 * V_238 , T_3 * V_239 )
{
if ( F_99 ( V_8 , V_236 , V_235 , 0 ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_93 ) ;
return - 1 ;
}
* V_237 = F_113 ( * ( ( V_240 * ) V_236 -> V_241 ) ) / 8 ;
if ( * V_237 > V_242 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_94
L_95 , V_242 ,
* V_237 - V_242 ) ;
* V_237 = V_242 ;
}
if ( F_100 ( V_8 , V_238 , V_235 ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_96 ) ;
return - 1 ;
}
* V_239 = F_113 ( * ( ( V_240 * ) V_238 -> V_241 ) ) / 8 ;
if ( * V_239 > V_184 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_97
L_98 , V_184 ,
* V_239 - V_184 ) ;
* V_239 = V_184 ;
}
if ( * V_239 + * V_237 > V_242 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_99
L_98 , V_242 ,
* V_237 + * V_239 - V_242 ) ;
* V_239 = V_242 - * V_237 ;
}
return 0 ;
}
V_202 * F_114 ( struct V_1 * V_8 , int V_243 , int V_35 ,
int V_237 , int V_239 , struct V_218 * V_244 ,
struct V_218 * V_245 )
{
int V_246 = V_237 + ( V_243 == 0 ) ;
int V_247 = V_237 + V_239 + ( V_243 == 0 ) ;
if ( V_35 == V_243 )
return V_70 ;
if ( V_35 < V_246 )
return & V_244 -> V_248 [ V_35 - ( V_243 == 0 ) ] [ 0 ] ;
if ( V_35 < V_247 )
return & V_245 -> V_248 [ V_35 - V_237 -
( V_243 == 0 ) ] [ 0 ] ;
F_115 () ;
return NULL ;
}
static void F_116 ( struct V_1 * V_8 , int V_78 )
{
struct V_218 * V_244 = NULL ;
struct V_218 * V_245 = NULL ;
T_3 V_237 = 0 ;
T_3 V_239 = 0 ;
T_3 V_249 = 0 ;
struct V_41 * * V_250 , * V_222 , * V_232 ;
int V_251 = 0 ;
int V_235 = sizeof( * V_244 ) + V_242 * 8 ;
int V_35 , V_234 , V_252 ;
int V_71 , V_72 , V_73 ;
int V_243 ;
F_39 ( V_233 , V_253 ) ;
V_250 = F_58 ( sizeof( * V_250 ) * V_76 ,
V_104 ) ;
V_244 = F_58 ( V_235 , V_104 ) ;
V_245 = F_58 ( V_235 , V_104 ) ;
V_232 = F_58 ( sizeof( * V_232 ) , V_104 ) ;
if ( ! V_250 || ! V_244 || ! V_245 || ! V_232 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_100 ) ;
goto V_254;
}
memset ( V_233 , 0 , sizeof( V_233 ) ) ;
if ( F_112 ( V_8 , V_235 , V_244 , & V_237 ,
V_245 , & V_239 ) )
goto V_254;
V_252 = V_237 + V_239 + F_111 + 1 ;
for ( V_35 = 0 ; V_35 < V_252 ; V_35 ++ ) {
V_250 [ V_35 ] = F_58 ( sizeof( * V_250 [ V_35 ] ) , V_104 ) ;
if ( ! V_250 [ V_35 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_101 ,
__FILE__ , __LINE__ ) ;
goto V_254;
}
V_249 ++ ;
}
if ( F_27 ( F_37 ( V_8 ) ) )
V_243 = 0 ;
else
V_243 = V_237 + V_239 ;
V_234 = 0 ;
for ( V_35 = 0 ; V_35 < V_237 + V_239 + 1 ; V_35 ++ ) {
V_202 * V_230 , V_255 = 0 ;
V_230 = F_114 ( V_8 , V_243 ,
V_35 , V_237 , V_239 , V_244 , V_245 ) ;
if ( V_230 [ 3 ] & 0xC0 &&
V_35 < V_237 + ( V_243 == 0 ) )
continue;
if ( F_102 ( V_8 , V_230 , V_232 ,
& V_255 ) )
continue;
F_108 ( V_8 , V_230 , & V_71 , & V_72 , & V_73 ,
V_232 ) ;
V_222 = V_250 [ V_251 ] ;
if ( F_110 ( V_8 , V_232 , V_222 ,
V_230 , V_71 , V_72 , V_73 , V_233 ,
& V_234 ) ) {
V_251 ++ ;
V_222 = V_250 [ V_251 ] ;
}
* V_222 = * V_232 ;
F_101 ( V_222 , V_71 , V_72 , V_73 ) ;
switch ( V_222 -> V_86 ) {
case V_228 :
if ( V_255 )
V_251 ++ ;
break;
case V_227 :
if ( V_35 < V_237 )
break;
V_251 ++ ;
break;
case V_256 :
case V_257 :
V_251 ++ ;
break;
case V_258 :
if ( ! F_36 ( V_230 ) )
break;
V_251 ++ ;
break;
default:
break;
}
if ( V_251 >= V_76 )
break;
}
F_57 ( V_8 , V_78 , V_250 , V_251 ) ;
V_254:
F_50 ( V_232 ) ;
for ( V_35 = 0 ; V_35 < V_249 ; V_35 ++ )
F_50 ( V_250 [ V_35 ] ) ;
F_50 ( V_250 ) ;
F_50 ( V_244 ) ;
F_50 ( V_245 ) ;
}
static int F_117 ( struct V_1 * V_8 ,
struct V_9 * V_130 ,
struct V_131 * V_132 )
{
unsigned int V_259 ;
struct V_260 * V_261 ;
T_4 V_198 ;
int V_262 , V_35 , V_263 , V_264 ;
struct V_112 * V_265 ;
F_47 ( F_118 ( V_132 ) > V_8 -> V_189 ) ;
V_262 = F_119 ( V_132 ) ;
if ( V_262 < 0 )
return V_262 ;
if ( ! V_262 )
goto V_266;
V_265 = V_130 -> V_116 ;
V_264 = 0 ;
V_263 = 0 ;
F_120 (cmd, sg, use_sg, i) {
if ( V_35 == V_8 -> V_117 - 1 &&
V_262 > V_8 -> V_117 ) {
V_264 = 1 ;
V_265 = V_8 -> V_107 [ V_130 -> V_118 ] ;
V_263 = 0 ;
}
V_198 = ( T_4 ) F_121 ( V_261 ) ;
V_259 = F_122 ( V_261 ) ;
V_265 -> V_124 . V_125 = ( T_3 ) ( V_198 & 0x0FFFFFFFFULL ) ;
V_265 -> V_124 . V_126 = ( T_3 ) ( ( V_198 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_265 -> V_121 = V_259 ;
V_265 -> V_119 = 0 ;
V_265 ++ ;
}
if ( V_262 + V_264 > V_8 -> V_267 )
V_8 -> V_267 = V_262 + V_264 ;
if ( V_264 ) {
V_130 -> V_66 . V_67 = V_8 -> V_117 ;
V_130 -> V_66 . V_122 = ( V_203 ) ( V_262 + 1 ) ;
F_71 ( V_8 , V_130 ) ;
return 0 ;
}
V_266:
V_130 -> V_66 . V_67 = ( V_202 ) V_262 ;
V_130 -> V_66 . V_122 = ( V_203 ) V_262 ;
return 0 ;
}
static int F_123 ( struct V_131 * V_132 ,
void (* F_124)( struct V_131 * ) )
{
struct V_1 * V_8 ;
struct V_41 * V_16 ;
unsigned char V_38 [ 8 ] ;
struct V_9 * V_10 ;
unsigned long V_43 ;
V_8 = F_1 ( V_132 -> V_22 ) ;
V_16 = V_132 -> V_22 -> V_45 ;
if ( ! V_16 ) {
V_132 -> V_140 = V_160 << 16 ;
F_124 ( V_132 ) ;
return 0 ;
}
memcpy ( V_38 , V_16 -> V_38 , sizeof( V_38 ) ) ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_10 = F_125 ( V_8 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
if ( V_10 == NULL ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_102 ) ;
return V_268 ;
}
V_132 -> V_149 = F_124 ;
V_132 -> V_269 = ( unsigned char * ) V_10 ;
V_10 -> V_270 = V_271 ;
V_10 -> V_139 = V_132 ;
V_10 -> V_66 . V_272 = 0 ;
memcpy ( & V_10 -> V_66 . V_248 . V_273 [ 0 ] , & V_38 [ 0 ] , 8 ) ;
V_10 -> V_66 . V_274 . V_125 = ( V_10 -> V_118 << V_275 ) ;
V_10 -> V_66 . V_274 . V_125 |= V_276 ;
V_10 -> V_154 . V_277 = 0 ;
memset ( V_10 -> V_154 . V_155 , 0 , sizeof( V_10 -> V_154 . V_155 ) ) ;
F_47 ( V_132 -> V_278 > sizeof( V_10 -> V_154 . V_155 ) ) ;
V_10 -> V_154 . V_279 = V_132 -> V_278 ;
memcpy ( V_10 -> V_154 . V_155 , V_132 -> V_159 , V_132 -> V_278 ) ;
V_10 -> V_154 . Type . Type = V_213 ;
V_10 -> V_154 . Type . V_280 = V_281 ;
switch ( V_132 -> V_282 ) {
case V_283 :
V_10 -> V_154 . Type . V_284 = V_285 ;
break;
case V_286 :
V_10 -> V_154 . Type . V_284 = V_287 ;
break;
case V_288 :
V_10 -> V_154 . Type . V_284 = V_289 ;
break;
case V_290 :
V_10 -> V_154 . Type . V_284 = V_291 ;
break;
default:
F_43 ( & V_8 -> V_15 -> V_16 , L_103 ,
V_132 -> V_282 ) ;
F_115 () ;
break;
}
if ( F_117 ( V_8 , V_10 , V_132 ) < 0 ) {
F_78 ( V_8 , V_10 ) ;
return V_268 ;
}
F_30 ( V_8 , V_10 ) ;
return 0 ;
}
int F_126 ( struct V_6 * V_7 ,
unsigned long V_292 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_43 ;
int V_293 ;
F_20 ( & V_8 -> V_294 , V_43 ) ;
V_293 = V_8 -> V_295 ;
F_21 ( & V_8 -> V_294 , V_43 ) ;
return V_293 ;
}
static int F_127 ( struct V_2 * V_3 ,
int V_296 , int V_297 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_297 != V_298 )
return - V_299 ;
if ( V_296 < 1 )
V_296 = 1 ;
else
if ( V_296 > V_8 -> V_108 )
V_296 = V_8 -> V_108 ;
F_128 ( V_3 , F_129 ( V_3 ) , V_296 ) ;
return V_3 -> V_300 ;
}
static void F_130 ( struct V_1 * V_8 )
{
F_131 ( V_8 -> V_28 ) ;
F_83 ( V_8 -> V_28 ) ;
V_8 -> V_28 = NULL ;
}
static int F_132 ( struct V_1 * V_8 )
{
int V_210 ;
V_210 = F_79 ( V_8 ) ;
if ( V_210 != 0 )
F_43 ( & V_8 -> V_15 -> V_16 , L_104
L_105 , V_210 ) ;
return V_210 ;
}
static int F_133 ( struct V_1 * V_8 ,
unsigned char V_301 [] )
{
int V_210 = 0 ;
int V_26 = 0 ;
int V_302 = 1 ;
struct V_9 * V_10 ;
V_10 = F_92 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_31
L_106 ) ;
return V_303 ;
}
while ( V_26 < V_304 ) {
F_134 ( 1000 * V_302 ) ;
V_26 ++ ;
if ( V_302 < V_305 )
V_302 = V_302 * 2 ;
F_93 ( V_10 , V_306 , V_8 , NULL , 0 , 0 , V_301 , V_213 ) ;
F_86 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_148 == V_307 )
break;
if ( V_10 -> V_11 -> V_148 == V_150 &&
V_10 -> V_11 -> V_143 == V_151 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_308 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_107
L_108 , V_302 ) ;
V_210 = 1 ;
}
if ( V_210 )
F_5 ( & V_8 -> V_15 -> V_16 , L_109 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
F_94 ( V_8 , V_10 ) ;
return V_210 ;
}
static int F_135 ( struct V_131 * V_309 )
{
int V_210 ;
struct V_1 * V_8 ;
struct V_41 * V_16 ;
V_8 = F_1 ( V_309 -> V_22 ) ;
if ( V_8 == NULL )
return V_310 ;
V_16 = V_309 -> V_22 -> V_45 ;
if ( ! V_16 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_111
L_112 ) ;
return V_310 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_113 ,
V_8 -> V_28 -> V_311 , V_16 -> V_71 , V_16 -> V_72 , V_16 -> V_73 ) ;
V_210 = F_95 ( V_8 , V_16 -> V_38 ) ;
if ( V_210 == 0 && F_133 ( V_8 , V_16 -> V_38 ) == 0 )
return V_312 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_114 ) ;
return V_310 ;
}
static struct V_9 * F_125 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_35 ;
union V_127 V_115 ;
V_199 V_313 , V_314 ;
do {
V_35 = F_136 ( V_8 -> V_315 , V_8 -> V_108 ) ;
if ( V_35 == V_8 -> V_108 )
return NULL ;
} while ( F_137
( V_35 & ( V_316 - 1 ) ,
V_8 -> V_315 + ( V_35 / V_316 ) ) != 0 );
V_10 = V_8 -> V_317 + V_35 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_313 = V_8 -> V_318
+ V_35 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_319 + V_35 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_314 = V_8 -> V_320
+ V_35 * sizeof( * V_10 -> V_11 ) ;
V_8 -> V_321 ++ ;
V_10 -> V_118 = V_35 ;
F_138 ( & V_10 -> V_55 ) ;
V_10 -> V_64 = ( T_3 ) V_313 ;
V_115 . V_129 = ( T_4 ) V_314 ;
V_10 -> V_322 . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_322 . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_322 . V_121 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static struct V_9 * F_92 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
union V_127 V_115 ;
V_199 V_313 , V_314 ;
V_10 = F_139 ( V_8 -> V_15 , sizeof( * V_10 ) , & V_313 ) ;
if ( V_10 == NULL )
return NULL ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_118 = - 1 ;
V_10 -> V_11 = F_139 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
& V_314 ) ;
if ( V_10 -> V_11 == NULL ) {
F_140 ( V_8 -> V_15 ,
sizeof( * V_10 ) , V_10 , V_313 ) ;
return NULL ;
}
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_138 ( & V_10 -> V_55 ) ;
V_10 -> V_64 = ( T_3 ) V_313 ;
V_115 . V_129 = ( T_4 ) V_314 ;
V_10 -> V_322 . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_322 . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_322 . V_121 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_78 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
int V_35 ;
V_35 = V_10 - V_8 -> V_317 ;
F_141 ( V_35 & ( V_316 - 1 ) ,
V_8 -> V_315 + ( V_35 / V_316 ) ) ;
V_8 -> V_323 ++ ;
}
static void F_94 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
union V_127 V_115 ;
V_115 . V_128 . V_125 = V_10 -> V_322 . V_124 . V_125 ;
V_115 . V_128 . V_126 = V_10 -> V_322 . V_124 . V_126 ;
F_140 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
V_10 -> V_11 , ( V_199 ) V_115 . V_129 ) ;
F_140 ( V_8 -> V_15 , sizeof( * V_10 ) ,
V_10 , ( V_199 ) ( V_10 -> V_64 & V_324 ) ) ;
}
static int F_142 ( struct V_2 * V_16 , int V_132 , void * V_325 )
{
T_5 T_6 * V_326 =
( T_5 T_6 * ) V_325 ;
T_7 V_327 ;
T_7 T_6 * V_328 = F_143 ( sizeof( V_327 ) ) ;
int V_329 ;
T_3 V_130 ;
memset ( & V_327 , 0 , sizeof( V_327 ) ) ;
V_329 = 0 ;
V_329 |= F_144 ( & V_327 . V_330 , & V_326 -> V_330 ,
sizeof( V_327 . V_330 ) ) ;
V_329 |= F_144 ( & V_327 . V_154 , & V_326 -> V_154 ,
sizeof( V_327 . V_154 ) ) ;
V_329 |= F_144 ( & V_327 . V_331 , & V_326 -> V_331 ,
sizeof( V_327 . V_331 ) ) ;
V_329 |= F_145 ( V_327 . V_332 , & V_326 -> V_332 ) ;
V_329 |= F_145 ( V_130 , & V_326 -> V_25 ) ;
V_327 . V_25 = F_146 ( V_130 ) ;
V_329 |= F_147 ( V_328 , & V_327 , sizeof( V_327 ) ) ;
if ( V_329 )
return - V_333 ;
V_329 = F_148 ( V_16 , V_334 , ( void * ) V_328 ) ;
if ( V_329 )
return V_329 ;
V_329 |= F_149 ( & V_326 -> V_331 , & V_328 -> V_331 ,
sizeof( V_326 -> V_331 ) ) ;
if ( V_329 )
return - V_333 ;
return V_329 ;
}
static int F_150 ( struct V_2 * V_16 ,
int V_132 , void * V_325 )
{
T_8 T_6 * V_326 =
( T_8 T_6 * ) V_325 ;
T_9 V_327 ;
T_9 T_6 * V_328 =
F_143 ( sizeof( V_327 ) ) ;
int V_329 ;
T_3 V_130 ;
memset ( & V_327 , 0 , sizeof( V_327 ) ) ;
V_329 = 0 ;
V_329 |= F_144 ( & V_327 . V_330 , & V_326 -> V_330 ,
sizeof( V_327 . V_330 ) ) ;
V_329 |= F_144 ( & V_327 . V_154 , & V_326 -> V_154 ,
sizeof( V_327 . V_154 ) ) ;
V_329 |= F_144 ( & V_327 . V_331 , & V_326 -> V_331 ,
sizeof( V_327 . V_331 ) ) ;
V_329 |= F_145 ( V_327 . V_332 , & V_326 -> V_332 ) ;
V_329 |= F_145 ( V_327 . V_335 , & V_326 -> V_335 ) ;
V_329 |= F_145 ( V_130 , & V_326 -> V_25 ) ;
V_327 . V_25 = F_146 ( V_130 ) ;
V_329 |= F_147 ( V_328 , & V_327 , sizeof( V_327 ) ) ;
if ( V_329 )
return - V_333 ;
V_329 = F_148 ( V_16 , V_336 , ( void * ) V_328 ) ;
if ( V_329 )
return V_329 ;
V_329 |= F_149 ( & V_326 -> V_331 , & V_328 -> V_331 ,
sizeof( V_326 -> V_331 ) ) ;
if ( V_329 )
return - V_333 ;
return V_329 ;
}
static int F_151 ( struct V_2 * V_16 , int V_132 , void * V_325 )
{
switch ( V_132 ) {
case V_337 :
case V_338 :
case V_339 :
case V_340 :
case V_341 :
case V_342 :
case V_343 :
case V_344 :
case V_345 :
case V_346 :
case V_347 :
case V_348 :
case V_349 :
case V_350 :
case V_351 :
return F_148 ( V_16 , V_132 , V_325 ) ;
case V_352 :
return F_142 ( V_16 , V_132 , V_325 ) ;
case V_353 :
return F_150 ( V_16 , V_132 , V_325 ) ;
default:
return - V_354 ;
}
}
static int F_152 ( struct V_1 * V_8 , void T_6 * V_355 )
{
struct V_356 V_357 ;
if ( ! V_355 )
return - V_358 ;
V_357 . V_359 = F_153 ( V_8 -> V_15 -> V_71 ) ;
V_357 . V_71 = V_8 -> V_15 -> V_71 -> V_360 ;
V_357 . V_361 = V_8 -> V_15 -> V_362 ;
V_357 . V_34 = V_8 -> V_34 ;
if ( F_147 ( V_355 , & V_357 , sizeof( V_357 ) ) )
return - V_333 ;
return 0 ;
}
static int F_154 ( struct V_1 * V_8 , void T_6 * V_355 )
{
T_10 V_363 ;
unsigned char V_364 , V_365 , V_366 ;
int V_210 ;
V_210 = sscanf ( V_367 , L_115 ,
& V_364 , & V_365 , & V_366 ) ;
if ( V_210 != 3 ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_116
L_117 , V_367 ) ;
V_364 = 0 ;
V_365 = 0 ;
V_366 = 0 ;
}
V_363 = ( V_364 << 16 ) | ( V_365 << 8 ) | V_366 ;
if ( ! V_355 )
return - V_358 ;
if ( F_147 ( V_355 , & V_363 , sizeof( T_10 ) ) )
return - V_333 ;
return 0 ;
}
static int F_155 ( struct V_1 * V_8 , void T_6 * V_355 )
{
T_7 V_368 ;
struct V_9 * V_10 ;
char * V_369 = NULL ;
union V_127 V_115 ;
if ( ! V_355 )
return - V_358 ;
if ( ! F_156 ( V_370 ) )
return - V_371 ;
if ( F_144 ( & V_368 , V_355 , sizeof( V_368 ) ) )
return - V_333 ;
if ( ( V_368 . V_332 < 1 ) &&
( V_368 . V_154 . Type . V_284 != V_289 ) ) {
return - V_358 ;
}
if ( V_368 . V_332 > 0 ) {
V_369 = F_70 ( V_368 . V_332 , V_104 ) ;
if ( V_369 == NULL )
return - V_333 ;
if ( V_368 . V_154 . Type . V_284 == V_285 ) {
if ( F_144 ( V_369 , V_368 . V_25 ,
V_368 . V_332 ) ) {
F_50 ( V_369 ) ;
return - V_333 ;
}
} else {
memset ( V_369 , 0 , V_368 . V_332 ) ;
}
}
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_50 ( V_369 ) ;
return - V_110 ;
}
V_10 -> V_270 = V_372 ;
V_10 -> V_66 . V_272 = 0 ;
if ( V_368 . V_332 > 0 ) {
V_10 -> V_66 . V_67 = 1 ;
V_10 -> V_66 . V_122 = 1 ;
} else {
V_10 -> V_66 . V_67 = 0 ;
V_10 -> V_66 . V_122 = 0 ;
}
memcpy ( & V_10 -> V_66 . V_248 , & V_368 . V_330 , sizeof( V_10 -> V_66 . V_248 ) ) ;
V_10 -> V_66 . V_274 . V_125 = V_10 -> V_64 ;
memcpy ( & V_10 -> V_154 , & V_368 . V_154 ,
sizeof( V_10 -> V_154 ) ) ;
if ( V_368 . V_332 > 0 ) {
V_115 . V_129 = F_72 ( V_8 -> V_15 , V_369 ,
V_368 . V_332 , V_373 ) ;
V_10 -> V_116 [ 0 ] . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_116 [ 0 ] . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_116 [ 0 ] . V_121 = V_368 . V_332 ;
V_10 -> V_116 [ 0 ] . V_119 = 0 ;
}
F_86 ( V_8 , V_10 ) ;
if ( V_368 . V_332 > 0 )
F_84 ( V_8 -> V_15 , V_10 , 1 , V_373 ) ;
F_157 ( V_8 , V_10 ) ;
memcpy ( & V_368 . V_331 , V_10 -> V_11 ,
sizeof( V_368 . V_331 ) ) ;
if ( F_147 ( V_355 , & V_368 , sizeof( V_368 ) ) ) {
F_50 ( V_369 ) ;
F_94 ( V_8 , V_10 ) ;
return - V_333 ;
}
if ( V_368 . V_154 . Type . V_284 == V_287 &&
V_368 . V_332 > 0 ) {
if ( F_147 ( V_368 . V_25 , V_369 , V_368 . V_332 ) ) {
F_50 ( V_369 ) ;
F_94 ( V_8 , V_10 ) ;
return - V_333 ;
}
}
F_50 ( V_369 ) ;
F_94 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_158 ( struct V_1 * V_8 , void T_6 * V_355 )
{
T_9 * V_374 ;
struct V_9 * V_10 ;
unsigned char * * V_369 = NULL ;
int * V_375 = NULL ;
union V_127 V_115 ;
T_11 V_196 = 0 ;
int V_376 = 0 ;
int V_35 ;
T_3 V_377 ;
T_3 V_378 ;
T_11 T_6 * V_379 ;
if ( ! V_355 )
return - V_358 ;
if ( ! F_156 ( V_370 ) )
return - V_371 ;
V_374 = ( T_9 * )
F_70 ( sizeof( * V_374 ) , V_104 ) ;
if ( ! V_374 ) {
V_376 = - V_110 ;
goto V_380;
}
if ( F_144 ( V_374 , V_355 , sizeof( * V_374 ) ) ) {
V_376 = - V_333 ;
goto V_380;
}
if ( ( V_374 -> V_332 < 1 ) &&
( V_374 -> V_154 . Type . V_284 != V_289 ) ) {
V_376 = - V_358 ;
goto V_380;
}
if ( V_374 -> V_335 > V_381 ) {
V_376 = - V_358 ;
goto V_380;
}
if ( V_374 -> V_332 > V_374 -> V_335 * V_382 ) {
V_376 = - V_358 ;
goto V_380;
}
V_369 = F_58 ( V_382 * sizeof( char * ) , V_104 ) ;
if ( ! V_369 ) {
V_376 = - V_110 ;
goto V_380;
}
V_375 = F_70 ( V_382 * sizeof( int ) , V_104 ) ;
if ( ! V_375 ) {
V_376 = - V_110 ;
goto V_380;
}
V_377 = V_374 -> V_332 ;
V_379 = V_374 -> V_25 ;
while ( V_377 ) {
V_378 = ( V_377 > V_374 -> V_335 ) ? V_374 -> V_335 : V_377 ;
V_375 [ V_196 ] = V_378 ;
V_369 [ V_196 ] = F_70 ( V_378 , V_104 ) ;
if ( V_369 [ V_196 ] == NULL ) {
V_376 = - V_110 ;
goto V_380;
}
if ( V_374 -> V_154 . Type . V_284 == V_285 ) {
if ( F_144 ( V_369 [ V_196 ] , V_379 , V_378 ) ) {
V_376 = - V_110 ;
goto V_380;
}
} else
memset ( V_369 [ V_196 ] , 0 , V_378 ) ;
V_377 -= V_378 ;
V_379 += V_378 ;
V_196 ++ ;
}
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
V_376 = - V_110 ;
goto V_380;
}
V_10 -> V_270 = V_372 ;
V_10 -> V_66 . V_272 = 0 ;
V_10 -> V_66 . V_67 = V_10 -> V_66 . V_122 = V_196 ;
memcpy ( & V_10 -> V_66 . V_248 , & V_374 -> V_330 , sizeof( V_10 -> V_66 . V_248 ) ) ;
V_10 -> V_66 . V_274 . V_125 = V_10 -> V_64 ;
memcpy ( & V_10 -> V_154 , & V_374 -> V_154 , sizeof( V_10 -> V_154 ) ) ;
if ( V_374 -> V_332 > 0 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < V_196 ; V_35 ++ ) {
V_115 . V_129 = F_72 ( V_8 -> V_15 , V_369 [ V_35 ] ,
V_375 [ V_35 ] , V_373 ) ;
V_10 -> V_116 [ V_35 ] . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_116 [ V_35 ] . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_116 [ V_35 ] . V_121 = V_375 [ V_35 ] ;
V_10 -> V_116 [ V_35 ] . V_119 = 0 ;
}
}
F_86 ( V_8 , V_10 ) ;
if ( V_196 )
F_84 ( V_8 -> V_15 , V_10 , V_196 , V_373 ) ;
F_157 ( V_8 , V_10 ) ;
memcpy ( & V_374 -> V_331 , V_10 -> V_11 , sizeof( V_374 -> V_331 ) ) ;
if ( F_147 ( V_355 , V_374 , sizeof( * V_374 ) ) ) {
F_94 ( V_8 , V_10 ) ;
V_376 = - V_333 ;
goto V_380;
}
if ( V_374 -> V_154 . Type . V_284 == V_287 && V_374 -> V_332 > 0 ) {
T_11 T_6 * V_383 = V_374 -> V_25 ;
for ( V_35 = 0 ; V_35 < V_196 ; V_35 ++ ) {
if ( F_147 ( V_383 , V_369 [ V_35 ] , V_375 [ V_35 ] ) ) {
F_94 ( V_8 , V_10 ) ;
V_376 = - V_333 ;
goto V_380;
}
V_383 += V_375 [ V_35 ] ;
}
}
F_94 ( V_8 , V_10 ) ;
V_376 = 0 ;
V_380:
if ( V_369 ) {
for ( V_35 = 0 ; V_35 < V_196 ; V_35 ++ )
F_50 ( V_369 [ V_35 ] ) ;
F_50 ( V_369 ) ;
}
F_50 ( V_375 ) ;
F_50 ( V_374 ) ;
return V_376 ;
}
static void F_157 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_148 == V_150 &&
V_10 -> V_11 -> V_143 != V_151 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_148 ( struct V_2 * V_16 , int V_132 , void * V_325 )
{
struct V_1 * V_8 ;
void T_6 * V_355 = ( void T_6 * ) V_325 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_132 ) {
case V_347 :
case V_348 :
case V_349 :
F_8 ( V_8 -> V_28 ) ;
return 0 ;
case V_337 :
return F_152 ( V_8 , V_355 ) ;
case V_345 :
return F_154 ( V_8 , V_355 ) ;
case V_334 :
return F_155 ( V_8 , V_355 ) ;
case V_336 :
return F_158 ( V_8 , V_355 ) ;
default:
return - V_384 ;
}
}
static int T_12 F_159 ( struct V_1 * V_8 ,
unsigned char * V_38 , V_202 V_385 )
{
struct V_9 * V_10 ;
V_10 = F_125 ( V_8 ) ;
if ( ! V_10 )
return - V_110 ;
F_93 ( V_10 , V_215 , V_8 , NULL , 0 , 0 ,
V_70 , V_216 ) ;
V_10 -> V_154 . V_155 [ 1 ] = V_385 ;
V_10 -> V_205 = NULL ;
F_30 ( V_8 , V_10 ) ;
return 0 ;
}
static void F_93 ( struct V_9 * V_10 , V_202 V_132 , struct V_1 * V_8 ,
void * V_369 , T_2 V_386 , V_202 V_387 , unsigned char * V_38 ,
int V_270 )
{
int V_388 = V_289 ;
V_10 -> V_270 = V_372 ;
V_10 -> V_66 . V_272 = 0 ;
if ( V_369 != NULL && V_386 > 0 ) {
V_10 -> V_66 . V_67 = 1 ;
V_10 -> V_66 . V_122 = 1 ;
} else {
V_10 -> V_66 . V_67 = 0 ;
V_10 -> V_66 . V_122 = 0 ;
}
V_10 -> V_66 . V_274 . V_125 = V_10 -> V_64 ;
memcpy ( V_10 -> V_66 . V_248 . V_273 , V_38 , 8 ) ;
V_10 -> V_154 . Type . Type = V_270 ;
if ( V_270 == V_213 ) {
switch ( V_132 ) {
case V_212 :
if ( V_387 != 0 ) {
V_10 -> V_154 . V_155 [ 1 ] = 0x01 ;
V_10 -> V_154 . V_155 [ 2 ] = V_387 ;
}
V_10 -> V_154 . V_279 = 6 ;
V_10 -> V_154 . Type . V_280 = V_281 ;
V_10 -> V_154 . Type . V_284 = V_287 ;
V_10 -> V_154 . V_277 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_212 ;
V_10 -> V_154 . V_155 [ 4 ] = V_386 & 0xFF ;
break;
case V_220 :
case V_221 :
V_10 -> V_154 . V_279 = 12 ;
V_10 -> V_154 . Type . V_280 = V_281 ;
V_10 -> V_154 . Type . V_284 = V_287 ;
V_10 -> V_154 . V_277 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_132 ;
V_10 -> V_154 . V_155 [ 6 ] = ( V_386 >> 24 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 7 ] = ( V_386 >> 16 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 8 ] = ( V_386 >> 8 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 9 ] = V_386 & 0xFF ;
break;
case V_389 :
V_10 -> V_154 . V_279 = 12 ;
V_10 -> V_154 . Type . V_280 = V_281 ;
V_10 -> V_154 . Type . V_284 = V_285 ;
V_10 -> V_154 . V_277 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_390 ;
V_10 -> V_154 . V_155 [ 6 ] = V_391 ;
break;
case V_306 :
V_10 -> V_154 . V_279 = 6 ;
V_10 -> V_154 . Type . V_280 = V_281 ;
V_10 -> V_154 . Type . V_284 = V_289 ;
V_10 -> V_154 . V_277 = 0 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_118 , V_132 ) ;
F_115 () ;
return;
}
} else if ( V_270 == V_216 ) {
switch ( V_132 ) {
case V_215 :
V_10 -> V_154 . V_279 = 16 ;
V_10 -> V_154 . Type . Type = 1 ;
V_10 -> V_154 . Type . V_280 = V_281 ;
V_10 -> V_154 . Type . V_284 = V_289 ;
V_10 -> V_154 . V_277 = 0 ;
memset ( & V_10 -> V_154 . V_155 [ 0 ] , 0 , sizeof( V_10 -> V_154 . V_155 ) ) ;
V_10 -> V_154 . V_155 [ 0 ] = V_132 ;
V_10 -> V_154 . V_155 [ 1 ] = 0x03 ;
V_10 -> V_154 . V_155 [ 4 ] = 0x00 ;
V_10 -> V_154 . V_155 [ 5 ] = 0x00 ;
V_10 -> V_154 . V_155 [ 6 ] = 0x00 ;
V_10 -> V_154 . V_155 [ 7 ] = 0x00 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_119 ,
V_132 ) ;
F_115 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_120 , V_270 ) ;
F_115 () ;
}
switch ( V_10 -> V_154 . Type . V_284 ) {
case V_287 :
V_388 = V_214 ;
break;
case V_285 :
V_388 = V_123 ;
break;
case V_289 :
V_388 = V_201 ;
break;
default:
V_388 = V_373 ;
}
F_85 ( V_8 -> V_15 , V_10 , V_369 , V_386 , V_388 ) ;
return;
}
static void T_13 * F_160 ( T_14 V_392 , T_14 V_386 )
{
T_14 V_393 = ( ( T_14 ) V_392 ) & V_394 ;
T_14 V_395 = ( ( T_14 ) V_392 ) - V_393 ;
void T_13 * V_396 = F_161 ( V_393 , V_395 + V_386 ) ;
return V_396 ? ( V_396 + V_395 ) : NULL ;
}
static void F_31 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
while ( ! F_34 ( & V_8 -> V_68 ) ) {
V_10 = F_162 ( V_8 -> V_68 . V_397 , struct V_9 , V_55 ) ;
if ( ( V_8 -> V_57 . V_398 ( V_8 ) ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_121 ) ;
break;
}
F_32 ( V_10 ) ;
V_8 -> V_69 -- ;
V_8 -> V_57 . V_399 ( V_8 , V_10 ) ;
F_24 ( & V_8 -> V_400 , V_10 ) ;
}
}
static inline unsigned long F_163 ( struct V_1 * V_8 )
{
return V_8 -> V_57 . V_58 ( V_8 ) ;
}
static inline bool F_164 ( struct V_1 * V_8 )
{
return V_8 -> V_57 . V_401 ( V_8 ) ;
}
static inline long F_165 ( struct V_1 * V_8 )
{
return ( V_8 -> V_57 . V_401 ( V_8 ) == 0 ) ||
( V_8 -> V_402 == 0 ) ;
}
static inline int F_166 ( struct V_1 * V_8 , T_3 V_403 ,
T_3 V_404 )
{
if ( F_27 ( V_403 >= V_8 -> V_108 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_122 , V_404 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_167 ( struct V_9 * V_10 , T_3 V_404 )
{
F_32 ( V_10 ) ;
if ( F_29 ( V_10 -> V_270 == V_271 ) )
F_75 ( V_10 ) ;
else if ( V_10 -> V_270 == V_372 )
F_168 ( V_10 -> V_205 ) ;
}
static inline T_3 F_169 ( T_3 V_405 )
{
return V_405 & V_276 ;
}
static inline T_3 F_170 ( T_3 V_405 )
{
return V_405 >> V_275 ;
}
static inline T_3 F_171 ( struct V_1 * V_8 , T_3 V_405 )
{
#define F_172 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_173 0x03
if ( F_27 ( ! ( V_8 -> V_32 & V_33 ) ) )
return V_405 & ~ F_173 ;
return V_405 & ~ F_172 ;
}
static inline T_3 F_174 ( struct V_1 * V_8 ,
T_3 V_404 )
{
T_3 V_403 ;
struct V_9 * V_10 ;
V_403 = F_170 ( V_404 ) ;
if ( F_166 ( V_8 , V_403 , V_404 ) )
return F_26 ( V_8 ) ;
V_10 = V_8 -> V_317 + V_403 ;
F_167 ( V_10 , V_404 ) ;
return F_26 ( V_8 ) ;
}
static inline T_3 F_175 ( struct V_1 * V_8 ,
T_3 V_404 )
{
T_3 V_405 ;
struct V_9 * V_10 = NULL ;
V_405 = F_171 ( V_8 , V_404 ) ;
F_176 (c, &h->cmpQ, list) {
if ( ( V_10 -> V_64 & 0xFFFFFFE0 ) == ( V_405 & 0xFFFFFFE0 ) ) {
F_167 ( V_10 , V_404 ) ;
return F_26 ( V_8 ) ;
}
}
F_166 ( V_8 , V_8 -> V_108 + 1 , V_404 ) ;
return F_26 ( V_8 ) ;
}
static int F_177 ( struct V_1 * V_8 )
{
if ( F_29 ( ! V_406 ) )
return 0 ;
if ( F_29 ( V_8 -> V_402 ) )
return 0 ;
F_44 ( & V_8 -> V_15 -> V_16 , L_123
L_124 ) ;
return 1 ;
}
static T_15 F_178 ( int V_190 , void * V_407 )
{
struct V_1 * V_8 = V_407 ;
unsigned long V_43 ;
T_3 V_404 ;
if ( F_177 ( V_8 ) )
return V_408 ;
if ( F_165 ( V_8 ) )
return V_408 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
while ( F_164 ( V_8 ) ) {
V_404 = F_163 ( V_8 ) ;
while ( V_404 != V_61 )
V_404 = F_26 ( V_8 ) ;
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_409 ;
}
static T_15 F_179 ( int V_190 , void * V_407 )
{
struct V_1 * V_8 = V_407 ;
unsigned long V_43 ;
T_3 V_404 ;
if ( F_177 ( V_8 ) )
return V_408 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_404 = F_163 ( V_8 ) ;
while ( V_404 != V_61 )
V_404 = F_26 ( V_8 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_409 ;
}
static T_15 F_180 ( int V_190 , void * V_407 )
{
struct V_1 * V_8 = V_407 ;
unsigned long V_43 ;
T_3 V_404 ;
if ( F_165 ( V_8 ) )
return V_408 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
while ( F_164 ( V_8 ) ) {
V_404 = F_163 ( V_8 ) ;
while ( V_404 != V_61 ) {
if ( F_169 ( V_404 ) )
V_404 = F_174 ( V_8 , V_404 ) ;
else
V_404 = F_175 ( V_8 , V_404 ) ;
}
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_409 ;
}
static T_15 F_181 ( int V_190 , void * V_407 )
{
struct V_1 * V_8 = V_407 ;
unsigned long V_43 ;
T_3 V_404 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_404 = F_163 ( V_8 ) ;
while ( V_404 != V_61 ) {
if ( F_169 ( V_404 ) )
V_404 = F_174 ( V_8 , V_404 ) ;
else
V_404 = F_175 ( V_8 , V_404 ) ;
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_409 ;
}
static T_12 int F_182 ( struct V_195 * V_15 , unsigned char V_410 ,
unsigned char type )
{
struct V_411 {
struct V_412 V_413 ;
struct V_414 V_154 ;
struct V_415 V_416 ;
};
struct V_411 * V_132 ;
static const T_2 V_417 = sizeof( * V_132 ) +
sizeof( V_132 -> V_416 ) ;
V_199 V_418 ;
T_16 V_419 , V_405 ;
void T_13 * V_420 ;
int V_35 , V_329 ;
V_420 = F_183 ( V_15 , 0 ) ;
if ( V_420 == NULL )
return - V_110 ;
V_329 = F_184 ( V_15 , F_185 ( 32 ) ) ;
if ( V_329 ) {
F_186 ( V_420 ) ;
return - V_110 ;
}
V_132 = F_139 ( V_15 , V_417 , & V_418 ) ;
if ( V_132 == NULL ) {
F_186 ( V_420 ) ;
return - V_110 ;
}
V_419 = V_418 ;
V_132 -> V_413 . V_272 = 0 ;
V_132 -> V_413 . V_67 = 0 ;
V_132 -> V_413 . V_122 = 0 ;
V_132 -> V_413 . V_274 . V_125 = V_419 ;
V_132 -> V_413 . V_274 . V_126 = 0 ;
memset ( & V_132 -> V_413 . V_248 . V_273 , 0 , 8 ) ;
V_132 -> V_154 . V_279 = 16 ;
V_132 -> V_154 . Type . Type = V_216 ;
V_132 -> V_154 . Type . V_280 = V_421 ;
V_132 -> V_154 . Type . V_284 = V_289 ;
V_132 -> V_154 . V_277 = 0 ;
V_132 -> V_154 . V_155 [ 0 ] = V_410 ;
V_132 -> V_154 . V_155 [ 1 ] = type ;
memset ( & V_132 -> V_154 . V_155 [ 2 ] , 0 , 14 ) ;
V_132 -> V_416 . V_124 . V_125 = V_419 + sizeof( * V_132 ) ;
V_132 -> V_416 . V_124 . V_126 = 0 ;
V_132 -> V_416 . V_121 = sizeof( struct V_133 ) ;
F_187 ( V_419 , V_420 + V_422 ) ;
for ( V_35 = 0 ; V_35 < V_423 ; V_35 ++ ) {
V_405 = F_188 ( V_420 + V_424 ) ;
if ( ( V_405 & ~ F_173 ) == V_419 )
break;
F_134 ( V_425 ) ;
}
F_186 ( V_420 ) ;
if ( V_35 == V_423 ) {
F_43 ( & V_15 -> V_16 , L_125 ,
V_410 , type ) ;
return - V_426 ;
}
F_140 ( V_15 , V_417 , V_132 , V_418 ) ;
if ( V_405 & V_427 ) {
F_43 ( & V_15 -> V_16 , L_126 ,
V_410 , type ) ;
return - V_428 ;
}
F_44 ( & V_15 -> V_16 , L_127 ,
V_410 , type ) ;
return 0 ;
}
static int F_189 ( struct V_195 * V_15 ,
void * T_13 V_420 , T_3 V_429 )
{
V_203 V_430 ;
int V_431 ;
if ( V_429 ) {
F_44 ( & V_15 -> V_16 , L_128 ) ;
F_187 ( V_429 , V_420 + V_432 ) ;
} else {
V_431 = F_190 ( V_15 , V_433 ) ;
if ( V_431 == 0 ) {
F_43 ( & V_15 -> V_16 ,
L_129
L_130 ) ;
return - V_46 ;
}
F_44 ( & V_15 -> V_16 , L_131 ) ;
F_191 ( V_15 , V_431 + V_434 , & V_430 ) ;
V_430 &= ~ V_435 ;
V_430 |= V_436 ;
F_192 ( V_15 , V_431 + V_434 , V_430 ) ;
F_134 ( 500 ) ;
V_430 &= ~ V_435 ;
V_430 |= V_437 ;
F_192 ( V_15 , V_431 + V_434 , V_430 ) ;
}
return 0 ;
}
static T_12 void F_193 ( char * V_438 , int V_259 )
{
memset ( V_438 , 0 , V_259 ) ;
strncpy ( V_438 , L_132 V_367 , V_259 - 1 ) ;
}
static T_12 int F_194 (
struct V_439 T_13 * V_440 )
{
char * V_438 ;
int V_35 , V_386 = sizeof( V_440 -> V_438 ) ;
V_438 = F_70 ( V_386 , V_104 ) ;
if ( ! V_438 )
return - V_110 ;
F_193 ( V_438 , V_386 ) ;
for ( V_35 = 0 ; V_35 < V_386 ; V_35 ++ )
F_195 ( V_438 [ V_35 ] , & V_440 -> V_438 [ V_35 ] ) ;
F_50 ( V_438 ) ;
return 0 ;
}
static T_12 void F_196 (
struct V_439 T_13 * V_440 , unsigned char * V_441 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < sizeof( V_440 -> V_438 ) ; V_35 ++ )
V_441 [ V_35 ] = F_197 ( & V_440 -> V_438 [ V_35 ] ) ;
}
static T_12 int F_198 (
struct V_439 T_13 * V_440 )
{
char * V_441 , * V_442 ;
int V_210 , V_386 = sizeof( V_440 -> V_438 ) ;
V_442 = F_70 ( 2 * V_386 , V_104 ) ;
if ( ! V_442 )
return - V_110 ;
V_441 = V_442 + V_386 ;
F_193 ( V_442 , V_386 ) ;
F_196 ( V_440 , V_441 ) ;
V_210 = ! memcmp ( V_441 , V_442 , V_386 ) ;
F_50 ( V_442 ) ;
return V_210 ;
}
static T_12 int F_199 ( struct V_195 * V_15 )
{
T_4 V_443 ;
T_3 V_444 ;
T_4 V_445 ;
void T_13 * V_420 ;
unsigned long V_446 ;
T_3 V_447 ;
int V_210 ;
struct V_439 T_13 * V_440 ;
T_3 V_429 ;
T_3 V_34 ;
V_203 V_448 ;
V_210 = F_200 ( V_15 , & V_34 ) ;
if ( V_210 < 0 || ! F_15 ( V_34 ) ) {
F_5 ( & V_15 -> V_16 , L_133 ) ;
return - V_46 ;
}
if ( ! F_12 ( V_34 ) )
return - V_299 ;
F_191 ( V_15 , 4 , & V_448 ) ;
F_201 ( V_15 ) ;
F_202 ( V_15 ) ;
V_210 = F_203 ( V_15 , & V_446 ) ;
if ( V_210 )
return V_210 ;
V_420 = F_160 ( V_446 , 0x250 ) ;
if ( ! V_420 )
return - V_110 ;
V_210 = F_204 ( V_15 , V_420 , & V_444 ,
& V_445 , & V_443 ) ;
if ( V_210 )
goto V_449;
V_440 = F_160 ( F_205 ( V_15 ,
V_445 ) + V_443 , sizeof( * V_440 ) ) ;
if ( ! V_440 ) {
V_210 = - V_110 ;
goto V_449;
}
V_210 = F_194 ( V_440 ) ;
if ( V_210 )
goto V_449;
V_447 = F_188 ( & V_440 -> V_447 ) ;
V_429 = V_447 & V_450 ;
if ( V_429 ) {
V_429 = V_451 ;
} else {
V_429 = V_447 & V_452 ;
if ( V_429 ) {
F_5 ( & V_15 -> V_16 , L_134
L_135
L_136
L_137 ) ;
V_210 = - V_299 ;
goto V_453;
}
}
V_210 = F_189 ( V_15 , V_420 , V_429 ) ;
if ( V_210 )
goto V_453;
F_206 ( V_15 ) ;
V_210 = F_207 ( V_15 ) ;
if ( V_210 ) {
F_5 ( & V_15 -> V_16 , L_138 ) ;
goto V_453;
}
F_192 ( V_15 , 4 , V_448 ) ;
F_134 ( V_454 ) ;
F_44 ( & V_15 -> V_16 , L_139 ) ;
V_210 = F_208 ( V_15 , V_420 , V_455 ) ;
if ( V_210 ) {
F_5 ( & V_15 -> V_16 ,
L_140
L_141 ) ;
V_210 = - V_299 ;
goto V_453;
}
V_210 = F_208 ( V_15 , V_420 , V_456 ) ;
if ( V_210 ) {
F_5 ( & V_15 -> V_16 ,
L_142
L_143 ) ;
goto V_453;
}
V_210 = F_198 ( V_420 ) ;
if ( V_210 < 0 )
goto V_453;
if ( V_210 ) {
F_5 ( & V_15 -> V_16 , L_144
L_145 ) ;
V_210 = - V_299 ;
} else {
F_44 ( & V_15 -> V_16 , L_146 ) ;
}
V_453:
F_186 ( V_440 ) ;
V_449:
F_186 ( V_420 ) ;
return V_210 ;
}
static void F_209 ( struct V_22 * V_16 , struct V_439 * V_457 )
{
#ifdef F_210
int V_35 ;
char V_458 [ 17 ] ;
F_44 ( V_16 , L_147 ) ;
F_44 ( V_16 , L_148 ) ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ )
V_458 [ V_35 ] = F_197 ( & ( V_457 -> V_459 [ V_35 ] ) ) ;
V_458 [ 4 ] = '\0' ;
F_44 ( V_16 , L_149 , V_458 ) ;
F_44 ( V_16 , L_150 , F_188 ( & ( V_457 -> V_460 ) ) ) ;
F_44 ( V_16 , L_151 ,
F_188 ( & ( V_457 -> V_461 ) ) ) ;
F_44 ( V_16 , L_152 ,
F_188 ( & ( V_457 -> V_462 ) ) ) ;
F_44 ( V_16 , L_153 ,
F_188 ( & ( V_457 -> V_463 . V_464 ) ) ) ;
F_44 ( V_16 , L_154 ,
F_188 ( & ( V_457 -> V_463 . V_465 ) ) ) ;
F_44 ( V_16 , L_155 ,
F_188 ( & ( V_457 -> V_463 . V_466 ) ) ) ;
F_44 ( V_16 , L_156 ,
F_188 ( & ( V_457 -> V_467 ) ) ) ;
F_44 ( V_16 , L_157 , F_188 ( & ( V_457 -> V_468 ) ) ) ;
for ( V_35 = 0 ; V_35 < 16 ; V_35 ++ )
V_458 [ V_35 ] = F_197 ( & ( V_457 -> V_469 [ V_35 ] ) ) ;
V_458 [ 16 ] = '\0' ;
F_44 ( V_16 , L_158 , V_458 ) ;
F_44 ( V_16 , L_159 ,
F_188 ( & ( V_457 -> V_470 ) ) ) ;
#endif
}
static int F_211 ( struct V_195 * V_15 , unsigned long V_471 )
{
int V_35 , V_472 , V_473 , V_474 ;
if ( V_471 == V_475 )
return 0 ;
V_472 = 0 ;
for ( V_35 = 0 ; V_35 < V_476 ; V_35 ++ ) {
V_474 = F_212 ( V_15 , V_35 ) & V_477 ;
if ( V_474 == V_478 )
V_472 += 4 ;
else {
V_473 = F_212 ( V_15 , V_35 ) &
V_479 ;
switch ( V_473 ) {
case V_480 :
case V_481 :
V_472 += 4 ;
break;
case V_482 :
V_472 += 8 ;
break;
default:
F_5 ( & V_15 -> V_16 ,
L_160 ) ;
return - 1 ;
break;
}
}
if ( V_472 == V_471 - V_475 )
return V_35 + 1 ;
}
return - 1 ;
}
static void T_12 F_213 ( struct V_1 * V_8 )
{
#ifdef F_214
int V_329 ;
struct V_483 V_484 [ 4 ] = { { 0 , 0 } , { 0 , 1 } ,
{ 0 , 2 } , { 0 , 3 }
} ;
if ( ( V_8 -> V_34 == 0x40700E11 ) || ( V_8 -> V_34 == 0x40800E11 ) ||
( V_8 -> V_34 == 0x40820E11 ) || ( V_8 -> V_34 == 0x40830E11 ) )
goto V_485;
if ( F_190 ( V_8 -> V_15 , V_486 ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_161 ) ;
V_329 = F_215 ( V_8 -> V_15 , V_484 , 4 ) ;
if ( ! V_329 ) {
V_8 -> V_191 [ 0 ] = V_484 [ 0 ] . V_487 ;
V_8 -> V_191 [ 1 ] = V_484 [ 1 ] . V_487 ;
V_8 -> V_191 [ 2 ] = V_484 [ 2 ] . V_487 ;
V_8 -> V_191 [ 3 ] = V_484 [ 3 ] . V_487 ;
V_8 -> V_488 = 1 ;
return;
}
if ( V_329 > 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_162
L_163 , V_329 ) ;
goto V_485;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_164 ,
V_329 ) ;
goto V_485;
}
}
if ( F_190 ( V_8 -> V_15 , V_489 ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_165 ) ;
if ( ! F_216 ( V_8 -> V_15 ) )
V_8 -> V_490 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_166 ) ;
}
V_485:
#endif
V_8 -> V_191 [ V_8 -> V_192 ] = V_8 -> V_15 -> V_190 ;
}
static int T_12 F_200 ( struct V_195 * V_15 , T_3 * V_34 )
{
int V_35 ;
T_3 V_491 , V_492 ;
V_491 = V_15 -> V_493 ;
V_492 = V_15 -> V_494 ;
* V_34 = ( ( V_492 << 16 ) & 0xffff0000 ) |
V_491 ;
for ( V_35 = 0 ; V_35 < F_13 ( V_495 ) ; V_35 ++ )
if ( * V_34 == V_495 [ V_35 ] . V_34 )
return V_35 ;
if ( ( V_491 != V_496 &&
V_491 != V_497 ) ||
! V_498 ) {
F_5 ( & V_15 -> V_16 , L_167
L_168 , * V_34 ) ;
return - V_46 ;
}
return F_13 ( V_495 ) - 1 ;
}
static inline bool F_217 ( struct V_195 * V_15 )
{
V_203 V_499 ;
( void ) F_191 ( V_15 , V_500 , & V_499 ) ;
return ( ( V_499 & V_501 ) == 0 ) ;
}
static int T_12 F_203 ( struct V_195 * V_15 ,
unsigned long * V_502 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_476 ; V_35 ++ )
if ( F_212 ( V_15 , V_35 ) & V_503 ) {
* V_502 = F_205 ( V_15 , V_35 ) ;
F_218 ( & V_15 -> V_16 , L_169 ,
* V_502 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_170 ) ;
return - V_46 ;
}
static int T_12 F_208 ( struct V_195 * V_15 ,
void T_13 * V_420 , int V_504 )
{
int V_35 , V_505 ;
T_3 V_506 ;
if ( V_504 )
V_505 = V_507 ;
else
V_505 = V_508 ;
for ( V_35 = 0 ; V_35 < V_505 ; V_35 ++ ) {
V_506 = F_188 ( V_420 + V_509 ) ;
if ( V_504 ) {
if ( V_506 == V_510 )
return 0 ;
} else {
if ( V_506 != V_510 )
return 0 ;
}
F_134 ( V_511 ) ;
}
F_5 ( & V_15 -> V_16 , L_171 ) ;
return - V_46 ;
}
static int T_12 F_204 ( struct V_195 * V_15 ,
void T_13 * V_420 , T_3 * V_444 , T_4 * V_445 ,
T_4 * V_443 )
{
* V_444 = F_188 ( V_420 + V_512 ) ;
* V_443 = F_188 ( V_420 + V_513 ) ;
* V_444 &= ( T_3 ) 0x0000ffff ;
* V_445 = F_211 ( V_15 , * V_444 ) ;
if ( * V_445 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_172 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_12 F_219 ( struct V_1 * V_8 )
{
T_4 V_443 ;
T_3 V_444 ;
T_4 V_445 ;
T_3 V_514 ;
int V_210 ;
V_210 = F_204 ( V_8 -> V_15 , V_8 -> V_420 , & V_444 ,
& V_445 , & V_443 ) ;
if ( V_210 )
return V_210 ;
V_8 -> V_440 = F_160 ( F_205 ( V_8 -> V_15 ,
V_445 ) + V_443 , sizeof( * V_8 -> V_440 ) ) ;
if ( ! V_8 -> V_440 )
return - V_110 ;
V_210 = F_194 ( V_8 -> V_440 ) ;
if ( V_210 )
return V_210 ;
V_514 = F_188 ( & V_8 -> V_440 -> V_515 ) ;
V_8 -> V_516 = F_160 ( F_205 ( V_8 -> V_15 ,
V_445 ) + V_443 + V_514 ,
sizeof( * V_8 -> V_516 ) ) ;
if ( ! V_8 -> V_516 )
return - V_110 ;
return 0 ;
}
static void T_12 F_220 ( struct V_1 * V_8 )
{
V_8 -> V_63 = F_188 ( & ( V_8 -> V_440 -> V_517 ) ) ;
if ( V_406 && V_8 -> V_63 > 32 )
V_8 -> V_63 = 32 ;
if ( V_8 -> V_63 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_173
L_174
L_175 ,
V_8 -> V_63 ) ;
V_8 -> V_63 = 16 ;
}
}
static void T_12 F_221 ( struct V_1 * V_8 )
{
F_220 ( V_8 ) ;
V_8 -> V_108 = V_8 -> V_63 - 4 ;
V_8 -> V_189 = F_188 ( & ( V_8 -> V_440 -> V_518 ) ) ;
V_8 -> V_117 = 31 ;
if ( V_8 -> V_189 > 512 ) {
V_8 -> V_117 = 32 ;
V_8 -> V_109 = V_8 -> V_189 - V_8 -> V_117 + 1 ;
V_8 -> V_189 -- ;
} else {
V_8 -> V_189 = 31 ;
V_8 -> V_109 = 0 ;
}
}
static inline bool F_222 ( struct V_1 * V_8 )
{
if ( ( F_197 ( & V_8 -> V_440 -> V_459 [ 0 ] ) != 'C' ) ||
( F_197 ( & V_8 -> V_440 -> V_459 [ 1 ] ) != 'I' ) ||
( F_197 ( & V_8 -> V_440 -> V_459 [ 2 ] ) != 'S' ) ||
( F_197 ( & V_8 -> V_440 -> V_459 [ 3 ] ) != 'S' ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_176 ) ;
return false ;
}
return true ;
}
static inline void F_223 ( struct V_1 * V_8 )
{
#ifdef F_224
T_3 V_519 ;
V_519 = F_188 ( & ( V_8 -> V_440 -> V_520 ) ) ;
V_519 |= 0x100 ;
F_187 ( V_519 , & ( V_8 -> V_440 -> V_520 ) ) ;
#endif
}
static inline void F_225 ( struct V_1 * V_8 )
{
T_3 V_521 ;
if ( V_8 -> V_34 != 0x3225103C )
return;
V_521 = F_188 ( V_8 -> V_420 + V_522 ) ;
V_521 |= 0x8000 ;
F_187 ( V_521 , V_8 -> V_420 + V_522 ) ;
}
static void T_12 F_226 ( struct V_1 * V_8 )
{
int V_35 ;
T_3 V_523 ;
unsigned long V_43 ;
for ( V_35 = 0 ; V_35 < V_524 ; V_35 ++ ) {
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_523 = F_188 ( V_8 -> V_420 + V_432 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
if ( ! ( V_523 & V_525 ) )
break;
F_227 ( 10000 , 20000 ) ;
}
}
static int T_12 F_228 ( struct V_1 * V_8 )
{
T_3 V_526 ;
V_526 = F_188 ( & ( V_8 -> V_440 -> V_461 ) ) ;
if ( ! ( V_526 & V_527 ) )
return - V_299 ;
V_8 -> V_63 = F_188 ( & ( V_8 -> V_440 -> V_467 ) ) ;
F_187 ( V_528 , & ( V_8 -> V_440 -> V_463 . V_464 ) ) ;
F_187 ( V_525 , V_8 -> V_420 + V_432 ) ;
F_226 ( V_8 ) ;
F_209 ( & V_8 -> V_15 -> V_16 , V_8 -> V_440 ) ;
if ( ! ( F_188 ( & ( V_8 -> V_440 -> V_462 ) ) & V_528 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_177 ) ;
return - V_46 ;
}
V_8 -> V_32 = V_528 ;
return 0 ;
}
static int T_12 F_229 ( struct V_1 * V_8 )
{
int V_529 , V_329 ;
V_529 = F_200 ( V_8 -> V_15 , & V_8 -> V_34 ) ;
if ( V_529 < 0 )
return - V_46 ;
V_8 -> V_530 = V_495 [ V_529 ] . V_530 ;
V_8 -> V_57 = * ( V_495 [ V_529 ] . V_57 ) ;
if ( F_217 ( V_8 -> V_15 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_178 ) ;
return - V_46 ;
}
V_329 = F_207 ( V_8 -> V_15 ) ;
if ( V_329 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_179 ) ;
return V_329 ;
}
V_329 = F_230 ( V_8 -> V_15 , L_180 ) ;
if ( V_329 ) {
F_43 ( & V_8 -> V_15 -> V_16 ,
L_181 ) ;
return V_329 ;
}
F_213 ( V_8 ) ;
V_329 = F_203 ( V_8 -> V_15 , & V_8 -> V_446 ) ;
if ( V_329 )
goto V_531;
V_8 -> V_420 = F_160 ( V_8 -> V_446 , 0x250 ) ;
if ( ! V_8 -> V_420 ) {
V_329 = - V_110 ;
goto V_531;
}
V_329 = F_208 ( V_8 -> V_15 , V_8 -> V_420 , V_456 ) ;
if ( V_329 )
goto V_531;
V_329 = F_219 ( V_8 ) ;
if ( V_329 )
goto V_531;
F_221 ( V_8 ) ;
if ( ! F_222 ( V_8 ) ) {
V_329 = - V_46 ;
goto V_531;
}
F_223 ( V_8 ) ;
F_225 ( V_8 ) ;
V_329 = F_228 ( V_8 ) ;
if ( V_329 )
goto V_531;
return 0 ;
V_531:
if ( V_8 -> V_516 )
F_186 ( V_8 -> V_516 ) ;
if ( V_8 -> V_440 )
F_186 ( V_8 -> V_440 ) ;
if ( V_8 -> V_420 )
F_186 ( V_8 -> V_420 ) ;
F_231 ( V_8 -> V_15 ) ;
return V_329 ;
}
static void T_12 F_232 ( struct V_1 * V_8 )
{
int V_210 ;
#define F_233 64
V_8 -> V_30 = F_70 ( F_233 , V_104 ) ;
if ( ! V_8 -> V_30 )
return;
V_210 = F_91 ( V_8 , V_70 , 0 ,
V_8 -> V_30 , F_233 ) ;
if ( V_210 != 0 ) {
F_50 ( V_8 -> V_30 ) ;
V_8 -> V_30 = NULL ;
}
}
static T_12 int F_234 ( struct V_195 * V_15 )
{
int V_210 , V_35 ;
if ( ! V_406 )
return 0 ;
V_210 = F_199 ( V_15 ) ;
if ( V_210 == - V_299 )
return V_210 ;
if ( V_210 )
return - V_46 ;
F_5 ( & V_15 -> V_16 , L_182 ) ;
for ( V_35 = 0 ; V_35 < V_532 ; V_35 ++ ) {
if ( F_235 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_183 ,
( V_35 < 11 ? L_184 : L_185 ) ) ;
}
return 0 ;
}
static T_12 int F_236 ( struct V_1 * V_8 )
{
V_8 -> V_315 = F_58 (
F_237 ( V_8 -> V_108 , V_316 ) *
sizeof( unsigned long ) , V_104 ) ;
V_8 -> V_317 = F_139 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( * V_8 -> V_317 ) ,
& ( V_8 -> V_318 ) ) ;
V_8 -> V_319 = F_139 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( * V_8 -> V_319 ) ,
& ( V_8 -> V_320 ) ) ;
if ( ( V_8 -> V_315 == NULL )
|| ( V_8 -> V_317 == NULL )
|| ( V_8 -> V_319 == NULL ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_186 , V_533 ) ;
return - V_110 ;
}
return 0 ;
}
static void F_238 ( struct V_1 * V_8 )
{
F_50 ( V_8 -> V_315 ) ;
if ( V_8 -> V_317 )
F_140 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_9 ) ,
V_8 -> V_317 , V_8 -> V_318 ) ;
if ( V_8 -> V_319 )
F_140 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_133 ) ,
V_8 -> V_319 ,
V_8 -> V_320 ) ;
}
static int F_239 ( struct V_1 * V_8 ,
T_15 (* F_240)( int , void * ) ,
T_15 (* F_241)( int , void * ) )
{
int V_210 ;
if ( V_8 -> V_488 || V_8 -> V_490 )
V_210 = F_242 ( V_8 -> V_191 [ V_8 -> V_192 ] , F_240 ,
V_534 , V_8 -> V_535 , V_8 ) ;
else
V_210 = F_242 ( V_8 -> V_191 [ V_8 -> V_192 ] , F_241 ,
V_534 , V_8 -> V_535 , V_8 ) ;
if ( V_210 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_187 ,
V_8 -> V_191 [ V_8 -> V_192 ] , V_8 -> V_535 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_12 F_243 ( struct V_1 * V_8 )
{
if ( F_159 ( V_8 , V_70 ,
V_536 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_188 ) ;
return - V_428 ;
}
F_44 ( & V_8 -> V_15 -> V_16 , L_189 ) ;
if ( F_208 ( V_8 -> V_15 , V_8 -> V_420 , V_455 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_190 ) ;
return - 1 ;
}
F_44 ( & V_8 -> V_15 -> V_16 , L_191 ) ;
if ( F_208 ( V_8 -> V_15 , V_8 -> V_420 , V_456 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_192
L_193 ) ;
return - 1 ;
}
return 0 ;
}
static void F_244 ( struct V_1 * V_8 )
{
F_245 ( V_8 -> V_191 [ V_8 -> V_192 ] , V_8 ) ;
#ifdef F_214
if ( V_8 -> V_488 )
F_246 ( V_8 -> V_15 ) ;
else if ( V_8 -> V_490 )
F_247 ( V_8 -> V_15 ) ;
#endif
F_68 ( V_8 ) ;
F_238 ( V_8 ) ;
F_50 ( V_8 -> V_65 ) ;
F_140 ( V_8 -> V_15 , V_8 -> V_537 ,
V_8 -> V_62 , V_8 -> V_538 ) ;
if ( V_8 -> V_420 )
F_186 ( V_8 -> V_420 ) ;
if ( V_8 -> V_516 )
F_186 ( V_8 -> V_516 ) ;
if ( V_8 -> V_440 )
F_186 ( V_8 -> V_440 ) ;
F_231 ( V_8 -> V_15 ) ;
F_50 ( V_8 ) ;
}
static int T_12 F_248 ( struct V_195 * V_15 ,
const struct V_539 * V_540 )
{
int V_541 , V_210 ;
struct V_1 * V_8 ;
int V_542 = 0 ;
unsigned long V_43 ;
if ( V_543 == 0 )
F_249 (KERN_INFO DRIVER_NAME L_194 ) ;
V_210 = F_234 ( V_15 ) ;
if ( V_210 ) {
if ( V_210 != - V_299 )
return V_210 ;
V_542 = 1 ;
V_210 = 0 ;
}
V_544:
#define F_250 32
F_251 ( sizeof( struct V_9 ) % F_250 ) ;
V_8 = F_58 ( sizeof( * V_8 ) , V_104 ) ;
if ( ! V_8 )
return - V_110 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_545 = 1 ;
V_8 -> V_192 = V_546 ? V_547 : V_548 ;
F_138 ( & V_8 -> V_400 ) ;
F_138 ( & V_8 -> V_68 ) ;
F_252 ( & V_8 -> V_44 ) ;
F_252 ( & V_8 -> V_294 ) ;
V_210 = F_229 ( V_8 ) ;
if ( V_210 != 0 )
goto V_549;
sprintf ( V_8 -> V_535 , L_195 , V_543 ) ;
V_8 -> V_17 = V_543 ;
V_543 ++ ;
V_210 = F_253 ( V_15 , F_185 ( 64 ) ) ;
if ( V_210 == 0 ) {
V_541 = 1 ;
} else {
V_210 = F_253 ( V_15 , F_185 ( 32 ) ) ;
if ( V_210 == 0 ) {
V_541 = 0 ;
} else {
F_43 ( & V_15 -> V_16 , L_196 ) ;
goto V_549;
}
}
V_8 -> V_57 . V_550 ( V_8 , V_551 ) ;
if ( F_239 ( V_8 , F_181 , F_180 ) )
goto V_552;
F_44 ( & V_15 -> V_16 , L_197 ,
V_8 -> V_535 , V_15 -> V_22 ,
V_8 -> V_191 [ V_8 -> V_192 ] , V_541 ? L_185 : L_198 ) ;
if ( F_236 ( V_8 ) )
goto V_553;
if ( F_69 ( V_8 ) )
goto V_553;
F_254 ( & V_8 -> V_554 ) ;
V_8 -> V_295 = 1 ;
F_255 ( V_15 , V_8 ) ;
V_8 -> V_77 = 0 ;
V_8 -> V_28 = NULL ;
F_252 ( & V_8 -> V_106 ) ;
F_256 ( V_8 ) ;
if ( V_542 ) {
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_8 -> V_57 . V_550 ( V_8 , V_551 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
F_245 ( V_8 -> V_191 [ V_8 -> V_192 ] , V_8 ) ;
V_210 = F_239 ( V_8 , F_179 ,
F_178 ) ;
if ( V_210 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_199
L_200 ) ;
goto V_553;
}
V_210 = F_243 ( V_8 ) ;
if ( V_210 )
goto V_553;
F_44 ( & V_8 -> V_15 -> V_16 , L_201 ) ;
F_44 ( & V_8 -> V_15 -> V_16 ,
L_202 ) ;
V_8 -> V_57 . V_550 ( V_8 , V_555 ) ;
F_134 ( 10000 ) ;
V_8 -> V_57 . V_550 ( V_8 , V_551 ) ;
V_210 = F_198 ( V_8 -> V_440 ) ;
if ( V_210 )
F_44 ( & V_8 -> V_15 -> V_16 ,
L_203 ) ;
F_244 ( V_8 ) ;
V_542 = 0 ;
if ( V_210 )
return - V_46 ;
goto V_544;
}
V_8 -> V_57 . V_550 ( V_8 , V_555 ) ;
F_232 ( V_8 ) ;
F_132 ( V_8 ) ;
V_8 -> V_545 = 0 ;
return 1 ;
V_553:
F_68 ( V_8 ) ;
F_238 ( V_8 ) ;
F_245 ( V_8 -> V_191 [ V_8 -> V_192 ] , V_8 ) ;
V_552:
V_549:
V_8 -> V_545 = 0 ;
F_50 ( V_8 ) ;
return V_210 ;
}
static void F_257 ( struct V_1 * V_8 )
{
char * V_556 ;
struct V_9 * V_10 ;
V_556 = F_58 ( 4 , V_104 ) ;
if ( ! V_556 )
return;
V_10 = F_92 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
goto V_557;
}
F_93 ( V_10 , V_389 , V_8 , V_556 , 4 , 0 ,
V_70 , V_213 ) ;
F_89 ( V_8 , V_10 , V_123 ) ;
if ( V_10 -> V_11 -> V_148 != 0 )
F_5 ( & V_8 -> V_15 -> V_16 ,
L_204 ) ;
F_94 ( V_8 , V_10 ) ;
V_557:
F_50 ( V_556 ) ;
}
static void F_258 ( struct V_195 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_259 ( V_15 ) ;
F_257 ( V_8 ) ;
V_8 -> V_57 . V_550 ( V_8 , V_551 ) ;
F_245 ( V_8 -> V_191 [ V_8 -> V_192 ] , V_8 ) ;
#ifdef F_214
if ( V_8 -> V_488 )
F_246 ( V_8 -> V_15 ) ;
else if ( V_8 -> V_490 )
F_247 ( V_8 -> V_15 ) ;
#endif
}
static void T_17 F_260 ( struct V_195 * V_15 )
{
struct V_1 * V_8 ;
if ( F_259 ( V_15 ) == NULL ) {
F_43 ( & V_15 -> V_16 , L_205 ) ;
return;
}
V_8 = F_259 ( V_15 ) ;
F_130 ( V_8 ) ;
F_258 ( V_15 ) ;
F_186 ( V_8 -> V_420 ) ;
F_186 ( V_8 -> V_516 ) ;
F_186 ( V_8 -> V_440 ) ;
F_68 ( V_8 ) ;
F_140 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_9 ) ,
V_8 -> V_317 , V_8 -> V_318 ) ;
F_140 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_133 ) ,
V_8 -> V_319 , V_8 -> V_320 ) ;
F_140 ( V_8 -> V_15 , V_8 -> V_537 ,
V_8 -> V_62 , V_8 -> V_538 ) ;
F_50 ( V_8 -> V_315 ) ;
F_50 ( V_8 -> V_65 ) ;
F_50 ( V_8 -> V_30 ) ;
F_231 ( V_15 ) ;
F_255 ( V_15 , NULL ) ;
F_50 ( V_8 ) ;
}
static void F_261 ( int V_558 [] , int V_559 ,
int V_560 , int * V_561 )
{
int V_35 , V_91 , V_562 , V_386 ;
#define F_262 4
#define F_263 8
for ( V_35 = 0 ; V_35 <= V_560 ; V_35 ++ ) {
V_386 = V_35 + F_262 ;
V_562 = V_559 ;
for ( V_91 = 0 ; V_91 < 8 ; V_91 ++ ) {
if ( V_558 [ V_91 ] >= V_386 ) {
V_562 = V_91 ;
break;
}
}
V_561 [ V_35 ] = V_562 ;
}
}
static T_12 void F_264 ( struct V_1 * V_8 ,
T_3 V_563 )
{
int V_35 ;
unsigned long V_564 ;
int V_565 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_382 + 4 } ;
F_251 ( 28 > V_382 + 4 ) ;
V_8 -> V_60 = 1 ;
memset ( V_8 -> V_62 , 0 , V_8 -> V_537 ) ;
V_8 -> V_59 = V_8 -> V_62 ;
V_565 [ 7 ] = V_8 -> V_566 + 4 ;
F_261 ( V_565 , F_13 ( V_565 ) , 32 , V_8 -> V_65 ) ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ )
F_187 ( V_565 [ V_35 ] , & V_8 -> V_516 -> V_567 [ V_35 ] ) ;
F_187 ( V_8 -> V_63 , & V_8 -> V_516 -> V_568 ) ;
F_187 ( 1 , & V_8 -> V_516 -> V_569 ) ;
F_187 ( 0 , & V_8 -> V_516 -> V_570 ) ;
F_187 ( 0 , & V_8 -> V_516 -> V_571 ) ;
F_187 ( V_8 -> V_538 , & V_8 -> V_516 -> V_572 ) ;
F_187 ( 0 , & V_8 -> V_516 -> V_573 ) ;
F_187 ( V_33 | V_563 ,
& ( V_8 -> V_440 -> V_463 . V_464 ) ) ;
F_187 ( V_525 , V_8 -> V_420 + V_432 ) ;
F_226 ( V_8 ) ;
V_564 = F_188 ( & ( V_8 -> V_440 -> V_462 ) ) ;
if ( ! ( V_564 & V_33 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_206
L_207 ) ;
return;
}
V_8 -> V_57 = V_574 ;
V_8 -> V_32 = V_33 ;
}
static T_12 void F_256 ( struct V_1 * V_8 )
{
T_3 V_526 ;
if ( V_546 )
return;
V_526 = F_188 ( & ( V_8 -> V_440 -> V_461 ) ) ;
if ( ! ( V_526 & V_575 ) )
return;
F_220 ( V_8 ) ;
V_8 -> V_566 = 32 ;
V_8 -> V_537 = V_8 -> V_63 * sizeof( T_4 ) ;
V_8 -> V_62 = F_139 ( V_8 -> V_15 , V_8 -> V_537 ,
& ( V_8 -> V_538 ) ) ;
V_8 -> V_65 = F_70 ( ( ( V_8 -> V_566 + 1 ) *
sizeof( T_3 ) ) , V_104 ) ;
if ( ( V_8 -> V_62 == NULL )
|| ( V_8 -> V_65 == NULL ) )
goto V_576;
F_264 ( V_8 ,
V_526 & V_577 ) ;
return;
V_576:
if ( V_8 -> V_62 )
F_140 ( V_8 -> V_15 , V_8 -> V_537 ,
V_8 -> V_62 , V_8 -> V_538 ) ;
F_50 ( V_8 -> V_65 ) ;
}
static int T_18 F_265 ( void )
{
return F_266 ( & V_578 ) ;
}
static void T_19 F_267 ( void )
{
F_268 ( & V_578 ) ;
}

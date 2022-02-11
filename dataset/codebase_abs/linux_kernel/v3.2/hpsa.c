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
V_79 = F_58 ( sizeof( * V_79 ) * V_76 , V_104 ) ;
V_89 = F_58 ( sizeof( * V_89 ) * V_76 , V_104 ) ;
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
struct V_9 * V_10 )
{
unsigned long V_43 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
if ( F_27 ( V_8 -> V_206 ) ) {
F_21 ( & V_8 -> V_44 , V_43 ) ;
V_10 -> V_11 -> V_148 = V_165 ;
} else {
F_21 ( & V_8 -> V_44 , V_43 ) ;
F_86 ( V_8 , V_10 ) ;
}
}
static void F_90 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_197 )
{
int V_207 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_86 ( V_8 , V_10 ) ;
V_207 ++ ;
} while ( F_4 ( V_8 , V_10 ) && V_207 <= 3 );
F_84 ( V_8 -> V_15 , V_10 , 1 , V_197 ) ;
}
static void F_91 ( struct V_9 * V_130 )
{
struct V_133 * V_134 ;
struct V_22 * V_208 = & V_130 -> V_8 -> V_15 -> V_16 ;
V_134 = V_130 -> V_11 ;
switch ( V_134 -> V_148 ) {
case V_150 :
F_5 ( V_208 , L_73 , V_130 ) ;
F_5 ( V_208 , L_74 , V_130 ,
V_134 -> V_143 ) ;
if ( V_134 -> V_143 == 0 )
F_5 ( V_208 , L_75
L_76
L_77
L_78 ) ;
break;
case V_161 :
F_44 ( V_208 , L_79 ) ;
break;
case V_162 :
F_5 ( V_208 , L_80 , V_130 ) ;
break;
case V_163 : {
F_5 ( V_208 , L_81
L_82 , V_130 ) ;
}
break;
case V_164 :
F_5 ( V_208 , L_83 , V_130 ) ;
break;
case V_165 :
F_5 ( V_208 , L_84 , V_130 ) ;
break;
case V_167 :
F_5 ( V_208 , L_62 , V_130 ) ;
break;
case V_168 :
F_5 ( V_208 , L_85 , V_130 ) ;
break;
case V_170 :
F_5 ( V_208 , L_64 , V_130 ) ;
break;
case V_171 :
F_5 ( V_208 , L_86 , V_130 ) ;
break;
case V_172 :
F_5 ( V_208 , L_87 , V_130 ) ;
break;
case V_174 :
F_5 ( V_208 , L_68 ) ;
break;
default:
F_5 ( V_208 , L_69 , V_130 ,
V_134 -> V_148 ) ;
}
}
static int F_92 ( struct V_1 * V_8 , unsigned char * V_38 ,
unsigned char V_209 , unsigned char * V_25 ,
unsigned char V_210 )
{
int V_211 = V_212 ;
struct V_9 * V_10 ;
struct V_133 * V_134 ;
V_10 = F_93 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - V_110 ;
}
F_94 ( V_10 , V_213 , V_8 , V_25 , V_210 , V_209 , V_38 , V_214 ) ;
F_90 ( V_8 , V_10 , V_215 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 && V_134 -> V_148 != V_161 ) {
F_91 ( V_10 ) ;
V_211 = - 1 ;
}
F_95 ( V_8 , V_10 ) ;
return V_211 ;
}
static int F_96 ( struct V_1 * V_8 , unsigned char * V_38 )
{
int V_211 = V_212 ;
struct V_9 * V_10 ;
struct V_133 * V_134 ;
V_10 = F_93 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - V_110 ;
}
F_94 ( V_10 , V_216 , V_8 , NULL , 0 , 0 , V_38 , V_217 ) ;
F_86 ( V_8 , V_10 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 ) {
F_91 ( V_10 ) ;
V_211 = - 1 ;
}
F_95 ( V_8 , V_10 ) ;
return V_211 ;
}
static void F_97 ( struct V_1 * V_8 ,
unsigned char * V_38 , unsigned char * V_48 )
{
int V_211 ;
unsigned char * V_25 ;
* V_48 = V_49 ;
V_25 = F_58 ( 64 , V_104 ) ;
if ( ! V_25 )
return;
V_211 = F_92 ( V_8 , V_38 , 0xC1 , V_25 , 64 ) ;
if ( V_211 == 0 )
* V_48 = V_25 [ 8 ] ;
if ( * V_48 > V_49 )
* V_48 = V_49 ;
F_50 ( V_25 ) ;
return;
}
static int F_98 ( struct V_1 * V_8 , unsigned char * V_38 ,
unsigned char * V_53 , int V_200 )
{
int V_211 ;
unsigned char * V_25 ;
if ( V_200 > 16 )
V_200 = 16 ;
V_25 = F_58 ( 64 , V_104 ) ;
if ( ! V_25 )
return - 1 ;
V_211 = F_92 ( V_8 , V_38 , 0x83 , V_25 , 64 ) ;
if ( V_211 == 0 )
memcpy ( V_53 , & V_25 [ 8 ] , V_200 ) ;
F_50 ( V_25 ) ;
return V_211 != 0 ;
}
static int F_99 ( struct V_1 * V_8 , int V_218 ,
struct V_219 * V_25 , int V_210 ,
int V_220 )
{
int V_211 = V_212 ;
struct V_9 * V_10 ;
unsigned char V_38 [ 8 ] ;
struct V_133 * V_134 ;
V_10 = F_93 ( V_8 ) ;
if ( V_10 == NULL ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - 1 ;
}
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
F_94 ( V_10 , V_218 ? V_221 : V_222 , V_8 ,
V_25 , V_210 , 0 , V_38 , V_214 ) ;
if ( V_220 )
V_10 -> V_154 . V_155 [ 1 ] = V_220 ;
F_90 ( V_8 , V_10 , V_215 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 &&
V_134 -> V_148 != V_161 ) {
F_91 ( V_10 ) ;
V_211 = - 1 ;
}
F_95 ( V_8 , V_10 ) ;
return V_211 ;
}
static inline int F_100 ( struct V_1 * V_8 ,
struct V_219 * V_25 ,
int V_210 , int V_220 )
{
return F_99 ( V_8 , 0 , V_25 , V_210 , V_220 ) ;
}
static inline int F_101 ( struct V_1 * V_8 ,
struct V_219 * V_25 , int V_210 )
{
return F_99 ( V_8 , 1 , V_25 , V_210 , 0 ) ;
}
static inline void F_102 ( struct V_41 * V_22 ,
int V_71 , int V_72 , int V_73 )
{
V_22 -> V_71 = V_71 ;
V_22 -> V_72 = V_72 ;
V_22 -> V_73 = V_73 ;
}
static int F_103 ( struct V_1 * V_8 ,
unsigned char V_38 [] , struct V_41 * V_223 ,
unsigned char * V_224 )
{
#define F_104 43
#define F_105 "$DR-10"
#define F_106 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_107 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_225 ;
unsigned char * V_226 ;
V_225 = F_58 ( F_107 , V_104 ) ;
if ( ! V_225 )
goto V_227;
if ( F_92 ( V_8 , V_38 , 0 , V_225 ,
( unsigned char ) F_107 ) != 0 ) {
F_43 ( & V_8 -> V_15 -> V_16 ,
L_89 ) ;
goto V_227;
}
V_223 -> V_86 = ( V_225 [ 0 ] & 0x1f ) ;
memcpy ( V_223 -> V_38 , V_38 , 8 ) ;
memcpy ( V_223 -> V_95 , & V_225 [ 8 ] ,
sizeof( V_223 -> V_95 ) ) ;
memcpy ( V_223 -> V_94 , & V_225 [ 16 ] ,
sizeof( V_223 -> V_94 ) ) ;
memset ( V_223 -> V_53 , 0 ,
sizeof( V_223 -> V_53 ) ) ;
F_98 ( V_8 , V_38 , V_223 -> V_53 ,
sizeof( V_223 -> V_53 ) ) ;
if ( V_223 -> V_86 == V_228 &&
F_17 ( V_38 ) )
F_97 ( V_8 , V_38 , & V_223 -> V_48 ) ;
else
V_223 -> V_48 = V_49 ;
if ( V_224 ) {
V_226 = & V_225 [ F_104 ] ;
* V_224 = ( V_223 -> V_86 == V_229 &&
strncmp ( V_226 , F_105 ,
F_106 ) == 0 ) ;
}
F_50 ( V_225 ) ;
return 0 ;
V_227:
F_50 ( V_225 ) ;
return 1 ;
}
static int F_108 ( struct V_1 * V_8 , struct V_41 * V_22 )
{
int V_35 ;
for ( V_35 = 0 ; V_230 [ V_35 ] ; V_35 ++ )
if ( strncmp ( V_22 -> V_94 , V_230 [ V_35 ] ,
strlen ( V_230 [ V_35 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_109 ( struct V_1 * V_8 ,
V_202 * V_231 , int * V_71 , int * V_72 , int * V_73 ,
struct V_41 * V_22 )
{
T_3 V_51 ;
if ( F_17 ( V_231 ) ) {
if ( F_27 ( F_37 ( V_8 ) ) ) {
V_51 = F_110 ( * ( ( V_232 * ) V_231 ) ) ;
* V_71 = 0 ;
* V_72 = 0 ;
* V_73 = ( V_51 & 0x3fff ) + 1 ;
} else {
V_51 = F_110 ( * ( ( V_232 * ) V_231 ) ) ;
if ( F_108 ( V_8 , V_22 ) ) {
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
if ( F_36 ( V_231 ) )
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
static int F_111 ( struct V_1 * V_8 ,
struct V_41 * V_233 ,
struct V_41 * V_223 , V_202 * V_231 ,
int V_71 , int V_72 , int V_73 , unsigned long V_234 [] ,
int * V_235 )
{
unsigned char V_38 [ 8 ] ;
if ( F_41 ( V_72 , V_234 ) )
return 0 ;
if ( ! F_17 ( V_231 ) )
return 0 ;
if ( ! F_108 ( V_8 , V_233 ) )
return 0 ;
if ( V_73 == 0 )
return 0 ;
memset ( V_38 , 0 , 8 ) ;
V_38 [ 3 ] = V_72 ;
if ( F_36 ( V_38 ) )
return 0 ;
if ( F_37 ( V_8 ) )
return 0 ;
if ( * V_235 >= V_236 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_90
L_91
L_92 ) ;
return 0 ;
}
if ( F_103 ( V_8 , V_38 , V_223 , NULL ) )
return 0 ;
( * V_235 ) ++ ;
F_102 ( V_223 , V_71 , V_72 , 0 ) ;
F_40 ( V_72 , V_234 ) ;
return 1 ;
}
static int F_112 ( struct V_1 * V_8 ,
int V_237 ,
struct V_219 * V_238 , T_3 * V_239 ,
struct V_219 * V_240 , T_3 * V_241 )
{
if ( F_100 ( V_8 , V_238 , V_237 , 0 ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_93 ) ;
return - 1 ;
}
* V_239 = F_113 ( * ( ( V_242 * ) V_238 -> V_243 ) ) / 8 ;
if ( * V_239 > V_244 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_94
L_95 , V_244 ,
* V_239 - V_244 ) ;
* V_239 = V_244 ;
}
if ( F_101 ( V_8 , V_240 , V_237 ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_96 ) ;
return - 1 ;
}
* V_241 = F_113 ( * ( ( V_242 * ) V_240 -> V_243 ) ) / 8 ;
if ( * V_241 > V_184 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_97
L_98 , V_184 ,
* V_241 - V_184 ) ;
* V_241 = V_184 ;
}
if ( * V_241 + * V_239 > V_244 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_99
L_98 , V_244 ,
* V_239 + * V_241 - V_244 ) ;
* V_241 = V_244 - * V_239 ;
}
return 0 ;
}
V_202 * F_114 ( struct V_1 * V_8 , int V_245 , int V_35 ,
int V_239 , int V_241 , struct V_219 * V_246 ,
struct V_219 * V_247 )
{
int V_248 = V_239 + ( V_245 == 0 ) ;
int V_249 = V_239 + V_241 + ( V_245 == 0 ) ;
if ( V_35 == V_245 )
return V_70 ;
if ( V_35 < V_248 )
return & V_246 -> V_250 [ V_35 - ( V_245 == 0 ) ] [ 0 ] ;
if ( V_35 < V_249 )
return & V_247 -> V_250 [ V_35 - V_239 -
( V_245 == 0 ) ] [ 0 ] ;
F_115 () ;
return NULL ;
}
static void F_116 ( struct V_1 * V_8 , int V_78 )
{
struct V_219 * V_246 = NULL ;
struct V_219 * V_247 = NULL ;
T_3 V_239 = 0 ;
T_3 V_241 = 0 ;
T_3 V_251 = 0 ;
struct V_41 * * V_252 , * V_223 , * V_233 ;
int V_253 = 0 ;
int V_237 = sizeof( * V_246 ) + V_244 * 8 ;
int V_35 , V_235 , V_254 ;
int V_71 , V_72 , V_73 ;
int V_245 ;
F_39 ( V_234 , V_255 ) ;
V_252 = F_58 ( sizeof( * V_252 ) * V_76 , V_104 ) ;
V_246 = F_58 ( V_237 , V_104 ) ;
V_247 = F_58 ( V_237 , V_104 ) ;
V_233 = F_58 ( sizeof( * V_233 ) , V_104 ) ;
if ( ! V_252 || ! V_246 || ! V_247 || ! V_233 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_100 ) ;
goto V_256;
}
memset ( V_234 , 0 , sizeof( V_234 ) ) ;
if ( F_112 ( V_8 , V_237 , V_246 , & V_239 ,
V_247 , & V_241 ) )
goto V_256;
V_254 = V_239 + V_241 + V_236 + 1 ;
for ( V_35 = 0 ; V_35 < V_254 ; V_35 ++ ) {
if ( V_35 >= V_76 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_101
L_102 , V_76 ,
V_254 - V_76 ) ;
break;
}
V_252 [ V_35 ] = F_58 ( sizeof( * V_252 [ V_35 ] ) , V_104 ) ;
if ( ! V_252 [ V_35 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_103 ,
__FILE__ , __LINE__ ) ;
goto V_256;
}
V_251 ++ ;
}
if ( F_27 ( F_37 ( V_8 ) ) )
V_245 = 0 ;
else
V_245 = V_239 + V_241 ;
V_235 = 0 ;
for ( V_35 = 0 ; V_35 < V_239 + V_241 + 1 ; V_35 ++ ) {
V_202 * V_231 , V_257 = 0 ;
V_231 = F_114 ( V_8 , V_245 ,
V_35 , V_239 , V_241 , V_246 , V_247 ) ;
if ( V_231 [ 3 ] & 0xC0 &&
V_35 < V_239 + ( V_245 == 0 ) )
continue;
if ( F_103 ( V_8 , V_231 , V_233 ,
& V_257 ) )
continue;
F_109 ( V_8 , V_231 , & V_71 , & V_72 , & V_73 ,
V_233 ) ;
V_223 = V_252 [ V_253 ] ;
if ( F_111 ( V_8 , V_233 , V_223 ,
V_231 , V_71 , V_72 , V_73 , V_234 ,
& V_235 ) ) {
V_253 ++ ;
V_223 = V_252 [ V_253 ] ;
}
* V_223 = * V_233 ;
F_102 ( V_223 , V_71 , V_72 , V_73 ) ;
switch ( V_223 -> V_86 ) {
case V_229 :
if ( V_257 )
V_253 ++ ;
break;
case V_228 :
if ( V_35 < V_239 )
break;
V_253 ++ ;
break;
case V_258 :
case V_259 :
V_253 ++ ;
break;
case V_260 :
if ( ! F_36 ( V_231 ) )
break;
V_253 ++ ;
break;
default:
break;
}
if ( V_253 >= V_76 )
break;
}
F_57 ( V_8 , V_78 , V_252 , V_253 ) ;
V_256:
F_50 ( V_233 ) ;
for ( V_35 = 0 ; V_35 < V_251 ; V_35 ++ )
F_50 ( V_252 [ V_35 ] ) ;
F_50 ( V_252 ) ;
F_50 ( V_246 ) ;
F_50 ( V_247 ) ;
}
static int F_117 ( struct V_1 * V_8 ,
struct V_9 * V_130 ,
struct V_131 * V_132 )
{
unsigned int V_261 ;
struct V_262 * V_263 ;
T_4 V_198 ;
int V_264 , V_35 , V_265 , V_266 ;
struct V_112 * V_267 ;
F_47 ( F_118 ( V_132 ) > V_8 -> V_189 ) ;
V_264 = F_119 ( V_132 ) ;
if ( V_264 < 0 )
return V_264 ;
if ( ! V_264 )
goto V_268;
V_267 = V_130 -> V_116 ;
V_266 = 0 ;
V_265 = 0 ;
F_120 (cmd, sg, use_sg, i) {
if ( V_35 == V_8 -> V_117 - 1 &&
V_264 > V_8 -> V_117 ) {
V_266 = 1 ;
V_267 = V_8 -> V_107 [ V_130 -> V_118 ] ;
V_265 = 0 ;
}
V_198 = ( T_4 ) F_121 ( V_263 ) ;
V_261 = F_122 ( V_263 ) ;
V_267 -> V_124 . V_125 = ( T_3 ) ( V_198 & 0x0FFFFFFFFULL ) ;
V_267 -> V_124 . V_126 = ( T_3 ) ( ( V_198 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_267 -> V_121 = V_261 ;
V_267 -> V_119 = 0 ;
V_267 ++ ;
}
if ( V_264 + V_266 > V_8 -> V_269 )
V_8 -> V_269 = V_264 + V_266 ;
if ( V_266 ) {
V_130 -> V_66 . V_67 = V_8 -> V_117 ;
V_130 -> V_66 . V_122 = ( V_203 ) ( V_264 + 1 ) ;
F_71 ( V_8 , V_130 ) ;
return 0 ;
}
V_268:
V_130 -> V_66 . V_67 = ( V_202 ) V_264 ;
V_130 -> V_66 . V_122 = ( V_203 ) V_264 ;
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
if ( F_27 ( V_8 -> V_206 ) ) {
F_21 ( & V_8 -> V_44 , V_43 ) ;
V_132 -> V_140 = V_166 << 16 ;
F_124 ( V_132 ) ;
return 0 ;
}
V_10 = F_125 ( V_8 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
if ( V_10 == NULL ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_104 ) ;
return V_270 ;
}
V_132 -> V_149 = F_124 ;
V_132 -> V_271 = ( unsigned char * ) V_10 ;
V_10 -> V_272 = V_273 ;
V_10 -> V_139 = V_132 ;
V_10 -> V_66 . V_274 = 0 ;
memcpy ( & V_10 -> V_66 . V_250 . V_275 [ 0 ] , & V_38 [ 0 ] , 8 ) ;
V_10 -> V_66 . V_276 . V_125 = ( V_10 -> V_118 << V_277 ) ;
V_10 -> V_66 . V_276 . V_125 |= V_278 ;
V_10 -> V_154 . V_279 = 0 ;
memset ( V_10 -> V_154 . V_155 , 0 , sizeof( V_10 -> V_154 . V_155 ) ) ;
F_47 ( V_132 -> V_280 > sizeof( V_10 -> V_154 . V_155 ) ) ;
V_10 -> V_154 . V_281 = V_132 -> V_280 ;
memcpy ( V_10 -> V_154 . V_155 , V_132 -> V_159 , V_132 -> V_280 ) ;
V_10 -> V_154 . Type . Type = V_214 ;
V_10 -> V_154 . Type . V_282 = V_283 ;
switch ( V_132 -> V_284 ) {
case V_285 :
V_10 -> V_154 . Type . V_286 = V_287 ;
break;
case V_288 :
V_10 -> V_154 . Type . V_286 = V_289 ;
break;
case V_290 :
V_10 -> V_154 . Type . V_286 = V_291 ;
break;
case V_292 :
V_10 -> V_154 . Type . V_286 = V_293 ;
break;
default:
F_43 ( & V_8 -> V_15 -> V_16 , L_105 ,
V_132 -> V_284 ) ;
F_115 () ;
break;
}
if ( F_117 ( V_8 , V_10 , V_132 ) < 0 ) {
F_78 ( V_8 , V_10 ) ;
return V_270 ;
}
F_30 ( V_8 , V_10 ) ;
return 0 ;
}
int F_126 ( struct V_6 * V_7 ,
unsigned long V_294 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_43 ;
int V_295 ;
F_20 ( & V_8 -> V_296 , V_43 ) ;
V_295 = V_8 -> V_297 ;
F_21 ( & V_8 -> V_296 , V_43 ) ;
return V_295 ;
}
static int F_127 ( struct V_2 * V_3 ,
int V_298 , int V_299 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_299 != V_300 )
return - V_301 ;
if ( V_298 < 1 )
V_298 = 1 ;
else
if ( V_298 > V_8 -> V_108 )
V_298 = V_8 -> V_108 ;
F_128 ( V_3 , F_129 ( V_3 ) , V_298 ) ;
return V_3 -> V_302 ;
}
static void F_130 ( struct V_1 * V_8 )
{
F_131 ( V_8 -> V_28 ) ;
F_83 ( V_8 -> V_28 ) ;
V_8 -> V_28 = NULL ;
}
static int F_132 ( struct V_1 * V_8 )
{
int V_211 ;
V_211 = F_79 ( V_8 ) ;
if ( V_211 != 0 )
F_43 ( & V_8 -> V_15 -> V_16 , L_106
L_107 , V_211 ) ;
return V_211 ;
}
static int F_133 ( struct V_1 * V_8 ,
unsigned char V_303 [] )
{
int V_211 = 0 ;
int V_26 = 0 ;
int V_304 = 1 ;
struct V_9 * V_10 ;
V_10 = F_93 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_31
L_108 ) ;
return V_305 ;
}
while ( V_26 < V_306 ) {
F_134 ( 1000 * V_304 ) ;
V_26 ++ ;
if ( V_304 < V_307 )
V_304 = V_304 * 2 ;
F_94 ( V_10 , V_308 , V_8 , NULL , 0 , 0 , V_303 , V_214 ) ;
F_86 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_148 == V_309 )
break;
if ( V_10 -> V_11 -> V_148 == V_150 &&
V_10 -> V_11 -> V_143 == V_151 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_310 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_109
L_110 , V_304 ) ;
V_211 = 1 ;
}
if ( V_211 )
F_5 ( & V_8 -> V_15 -> V_16 , L_111 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_112 ) ;
F_95 ( V_8 , V_10 ) ;
return V_211 ;
}
static int F_135 ( struct V_131 * V_311 )
{
int V_211 ;
struct V_1 * V_8 ;
struct V_41 * V_16 ;
V_8 = F_1 ( V_311 -> V_22 ) ;
if ( V_8 == NULL )
return V_312 ;
V_16 = V_311 -> V_22 -> V_45 ;
if ( ! V_16 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_113
L_114 ) ;
return V_312 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_115 ,
V_8 -> V_28 -> V_313 , V_16 -> V_71 , V_16 -> V_72 , V_16 -> V_73 ) ;
V_211 = F_96 ( V_8 , V_16 -> V_38 ) ;
if ( V_211 == 0 && F_133 ( V_8 , V_16 -> V_38 ) == 0 )
return V_314 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_116 ) ;
return V_312 ;
}
static struct V_9 * F_125 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_35 ;
union V_127 V_115 ;
V_199 V_315 , V_316 ;
do {
V_35 = F_136 ( V_8 -> V_317 , V_8 -> V_108 ) ;
if ( V_35 == V_8 -> V_108 )
return NULL ;
} while ( F_137
( V_35 & ( V_318 - 1 ) ,
V_8 -> V_317 + ( V_35 / V_318 ) ) != 0 );
V_10 = V_8 -> V_319 + V_35 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_315 = V_8 -> V_320
+ V_35 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_321 + V_35 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_316 = V_8 -> V_322
+ V_35 * sizeof( * V_10 -> V_11 ) ;
V_8 -> V_323 ++ ;
V_10 -> V_118 = V_35 ;
F_138 ( & V_10 -> V_55 ) ;
V_10 -> V_64 = ( T_3 ) V_315 ;
V_115 . V_129 = ( T_4 ) V_316 ;
V_10 -> V_324 . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_324 . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_324 . V_121 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static struct V_9 * F_93 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
union V_127 V_115 ;
V_199 V_315 , V_316 ;
V_10 = F_139 ( V_8 -> V_15 , sizeof( * V_10 ) , & V_315 ) ;
if ( V_10 == NULL )
return NULL ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_118 = - 1 ;
V_10 -> V_11 = F_139 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
& V_316 ) ;
if ( V_10 -> V_11 == NULL ) {
F_140 ( V_8 -> V_15 ,
sizeof( * V_10 ) , V_10 , V_315 ) ;
return NULL ;
}
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_138 ( & V_10 -> V_55 ) ;
V_10 -> V_64 = ( T_3 ) V_315 ;
V_115 . V_129 = ( T_4 ) V_316 ;
V_10 -> V_324 . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_324 . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_324 . V_121 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_78 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
int V_35 ;
V_35 = V_10 - V_8 -> V_319 ;
F_141 ( V_35 & ( V_318 - 1 ) ,
V_8 -> V_317 + ( V_35 / V_318 ) ) ;
V_8 -> V_325 ++ ;
}
static void F_95 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
union V_127 V_115 ;
V_115 . V_128 . V_125 = V_10 -> V_324 . V_124 . V_125 ;
V_115 . V_128 . V_126 = V_10 -> V_324 . V_124 . V_126 ;
F_140 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
V_10 -> V_11 , ( V_199 ) V_115 . V_129 ) ;
F_140 ( V_8 -> V_15 , sizeof( * V_10 ) ,
V_10 , ( V_199 ) ( V_10 -> V_64 & V_326 ) ) ;
}
static int F_142 ( struct V_2 * V_16 , int V_132 , void * V_327 )
{
T_5 T_6 * V_328 =
( T_5 T_6 * ) V_327 ;
T_7 V_329 ;
T_7 T_6 * V_330 = F_143 ( sizeof( V_329 ) ) ;
int V_331 ;
T_3 V_130 ;
memset ( & V_329 , 0 , sizeof( V_329 ) ) ;
V_331 = 0 ;
V_331 |= F_144 ( & V_329 . V_332 , & V_328 -> V_332 ,
sizeof( V_329 . V_332 ) ) ;
V_331 |= F_144 ( & V_329 . V_154 , & V_328 -> V_154 ,
sizeof( V_329 . V_154 ) ) ;
V_331 |= F_144 ( & V_329 . V_333 , & V_328 -> V_333 ,
sizeof( V_329 . V_333 ) ) ;
V_331 |= F_145 ( V_329 . V_334 , & V_328 -> V_334 ) ;
V_331 |= F_145 ( V_130 , & V_328 -> V_25 ) ;
V_329 . V_25 = F_146 ( V_130 ) ;
V_331 |= F_147 ( V_330 , & V_329 , sizeof( V_329 ) ) ;
if ( V_331 )
return - V_335 ;
V_331 = F_148 ( V_16 , V_336 , ( void * ) V_330 ) ;
if ( V_331 )
return V_331 ;
V_331 |= F_149 ( & V_328 -> V_333 , & V_330 -> V_333 ,
sizeof( V_328 -> V_333 ) ) ;
if ( V_331 )
return - V_335 ;
return V_331 ;
}
static int F_150 ( struct V_2 * V_16 ,
int V_132 , void * V_327 )
{
T_8 T_6 * V_328 =
( T_8 T_6 * ) V_327 ;
T_9 V_329 ;
T_9 T_6 * V_330 =
F_143 ( sizeof( V_329 ) ) ;
int V_331 ;
T_3 V_130 ;
memset ( & V_329 , 0 , sizeof( V_329 ) ) ;
V_331 = 0 ;
V_331 |= F_144 ( & V_329 . V_332 , & V_328 -> V_332 ,
sizeof( V_329 . V_332 ) ) ;
V_331 |= F_144 ( & V_329 . V_154 , & V_328 -> V_154 ,
sizeof( V_329 . V_154 ) ) ;
V_331 |= F_144 ( & V_329 . V_333 , & V_328 -> V_333 ,
sizeof( V_329 . V_333 ) ) ;
V_331 |= F_145 ( V_329 . V_334 , & V_328 -> V_334 ) ;
V_331 |= F_145 ( V_329 . V_337 , & V_328 -> V_337 ) ;
V_331 |= F_145 ( V_130 , & V_328 -> V_25 ) ;
V_329 . V_25 = F_146 ( V_130 ) ;
V_331 |= F_147 ( V_330 , & V_329 , sizeof( V_329 ) ) ;
if ( V_331 )
return - V_335 ;
V_331 = F_148 ( V_16 , V_338 , ( void * ) V_330 ) ;
if ( V_331 )
return V_331 ;
V_331 |= F_149 ( & V_328 -> V_333 , & V_330 -> V_333 ,
sizeof( V_328 -> V_333 ) ) ;
if ( V_331 )
return - V_335 ;
return V_331 ;
}
static int F_151 ( struct V_2 * V_16 , int V_132 , void * V_327 )
{
switch ( V_132 ) {
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
case V_352 :
case V_353 :
return F_148 ( V_16 , V_132 , V_327 ) ;
case V_354 :
return F_142 ( V_16 , V_132 , V_327 ) ;
case V_355 :
return F_150 ( V_16 , V_132 , V_327 ) ;
default:
return - V_356 ;
}
}
static int F_152 ( struct V_1 * V_8 , void T_6 * V_357 )
{
struct V_358 V_359 ;
if ( ! V_357 )
return - V_360 ;
V_359 . V_361 = F_153 ( V_8 -> V_15 -> V_71 ) ;
V_359 . V_71 = V_8 -> V_15 -> V_71 -> V_362 ;
V_359 . V_363 = V_8 -> V_15 -> V_364 ;
V_359 . V_34 = V_8 -> V_34 ;
if ( F_147 ( V_357 , & V_359 , sizeof( V_359 ) ) )
return - V_335 ;
return 0 ;
}
static int F_154 ( struct V_1 * V_8 , void T_6 * V_357 )
{
T_10 V_365 ;
unsigned char V_366 , V_367 , V_368 ;
int V_211 ;
V_211 = sscanf ( V_369 , L_117 ,
& V_366 , & V_367 , & V_368 ) ;
if ( V_211 != 3 ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_118
L_119 , V_369 ) ;
V_366 = 0 ;
V_367 = 0 ;
V_368 = 0 ;
}
V_365 = ( V_366 << 16 ) | ( V_367 << 8 ) | V_368 ;
if ( ! V_357 )
return - V_360 ;
if ( F_147 ( V_357 , & V_365 , sizeof( T_10 ) ) )
return - V_335 ;
return 0 ;
}
static int F_155 ( struct V_1 * V_8 , void T_6 * V_357 )
{
T_7 V_370 ;
struct V_9 * V_10 ;
char * V_371 = NULL ;
union V_127 V_115 ;
if ( ! V_357 )
return - V_360 ;
if ( ! F_156 ( V_372 ) )
return - V_373 ;
if ( F_144 ( & V_370 , V_357 , sizeof( V_370 ) ) )
return - V_335 ;
if ( ( V_370 . V_334 < 1 ) &&
( V_370 . V_154 . Type . V_286 != V_291 ) ) {
return - V_360 ;
}
if ( V_370 . V_334 > 0 ) {
V_371 = F_70 ( V_370 . V_334 , V_104 ) ;
if ( V_371 == NULL )
return - V_335 ;
if ( V_370 . V_154 . Type . V_286 == V_287 ) {
if ( F_144 ( V_371 , V_370 . V_25 ,
V_370 . V_334 ) ) {
F_50 ( V_371 ) ;
return - V_335 ;
}
} else {
memset ( V_371 , 0 , V_370 . V_334 ) ;
}
}
V_10 = F_93 ( V_8 ) ;
if ( V_10 == NULL ) {
F_50 ( V_371 ) ;
return - V_110 ;
}
V_10 -> V_272 = V_374 ;
V_10 -> V_66 . V_274 = 0 ;
if ( V_370 . V_334 > 0 ) {
V_10 -> V_66 . V_67 = 1 ;
V_10 -> V_66 . V_122 = 1 ;
} else {
V_10 -> V_66 . V_67 = 0 ;
V_10 -> V_66 . V_122 = 0 ;
}
memcpy ( & V_10 -> V_66 . V_250 , & V_370 . V_332 , sizeof( V_10 -> V_66 . V_250 ) ) ;
V_10 -> V_66 . V_276 . V_125 = V_10 -> V_64 ;
memcpy ( & V_10 -> V_154 , & V_370 . V_154 ,
sizeof( V_10 -> V_154 ) ) ;
if ( V_370 . V_334 > 0 ) {
V_115 . V_129 = F_72 ( V_8 -> V_15 , V_371 ,
V_370 . V_334 , V_375 ) ;
V_10 -> V_116 [ 0 ] . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_116 [ 0 ] . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_116 [ 0 ] . V_121 = V_370 . V_334 ;
V_10 -> V_116 [ 0 ] . V_119 = 0 ;
}
F_89 ( V_8 , V_10 ) ;
if ( V_370 . V_334 > 0 )
F_84 ( V_8 -> V_15 , V_10 , 1 , V_375 ) ;
F_157 ( V_8 , V_10 ) ;
memcpy ( & V_370 . V_333 , V_10 -> V_11 ,
sizeof( V_370 . V_333 ) ) ;
if ( F_147 ( V_357 , & V_370 , sizeof( V_370 ) ) ) {
F_50 ( V_371 ) ;
F_95 ( V_8 , V_10 ) ;
return - V_335 ;
}
if ( V_370 . V_154 . Type . V_286 == V_289 &&
V_370 . V_334 > 0 ) {
if ( F_147 ( V_370 . V_25 , V_371 , V_370 . V_334 ) ) {
F_50 ( V_371 ) ;
F_95 ( V_8 , V_10 ) ;
return - V_335 ;
}
}
F_50 ( V_371 ) ;
F_95 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_158 ( struct V_1 * V_8 , void T_6 * V_357 )
{
T_9 * V_376 ;
struct V_9 * V_10 ;
unsigned char * * V_371 = NULL ;
int * V_377 = NULL ;
union V_127 V_115 ;
T_11 V_196 = 0 ;
int V_378 = 0 ;
int V_35 ;
T_3 V_379 ;
T_3 V_380 ;
T_11 T_6 * V_381 ;
if ( ! V_357 )
return - V_360 ;
if ( ! F_156 ( V_372 ) )
return - V_373 ;
V_376 = ( T_9 * )
F_70 ( sizeof( * V_376 ) , V_104 ) ;
if ( ! V_376 ) {
V_378 = - V_110 ;
goto V_382;
}
if ( F_144 ( V_376 , V_357 , sizeof( * V_376 ) ) ) {
V_378 = - V_335 ;
goto V_382;
}
if ( ( V_376 -> V_334 < 1 ) &&
( V_376 -> V_154 . Type . V_286 != V_291 ) ) {
V_378 = - V_360 ;
goto V_382;
}
if ( V_376 -> V_337 > V_383 ) {
V_378 = - V_360 ;
goto V_382;
}
if ( V_376 -> V_334 > V_376 -> V_337 * V_384 ) {
V_378 = - V_360 ;
goto V_382;
}
V_371 = F_58 ( V_384 * sizeof( char * ) , V_104 ) ;
if ( ! V_371 ) {
V_378 = - V_110 ;
goto V_382;
}
V_377 = F_70 ( V_384 * sizeof( int ) , V_104 ) ;
if ( ! V_377 ) {
V_378 = - V_110 ;
goto V_382;
}
V_379 = V_376 -> V_334 ;
V_381 = V_376 -> V_25 ;
while ( V_379 ) {
V_380 = ( V_379 > V_376 -> V_337 ) ? V_376 -> V_337 : V_379 ;
V_377 [ V_196 ] = V_380 ;
V_371 [ V_196 ] = F_70 ( V_380 , V_104 ) ;
if ( V_371 [ V_196 ] == NULL ) {
V_378 = - V_110 ;
goto V_382;
}
if ( V_376 -> V_154 . Type . V_286 == V_287 ) {
if ( F_144 ( V_371 [ V_196 ] , V_381 , V_380 ) ) {
V_378 = - V_110 ;
goto V_382;
}
} else
memset ( V_371 [ V_196 ] , 0 , V_380 ) ;
V_379 -= V_380 ;
V_381 += V_380 ;
V_196 ++ ;
}
V_10 = F_93 ( V_8 ) ;
if ( V_10 == NULL ) {
V_378 = - V_110 ;
goto V_382;
}
V_10 -> V_272 = V_374 ;
V_10 -> V_66 . V_274 = 0 ;
V_10 -> V_66 . V_67 = V_10 -> V_66 . V_122 = V_196 ;
memcpy ( & V_10 -> V_66 . V_250 , & V_376 -> V_332 , sizeof( V_10 -> V_66 . V_250 ) ) ;
V_10 -> V_66 . V_276 . V_125 = V_10 -> V_64 ;
memcpy ( & V_10 -> V_154 , & V_376 -> V_154 , sizeof( V_10 -> V_154 ) ) ;
if ( V_376 -> V_334 > 0 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < V_196 ; V_35 ++ ) {
V_115 . V_129 = F_72 ( V_8 -> V_15 , V_371 [ V_35 ] ,
V_377 [ V_35 ] , V_375 ) ;
V_10 -> V_116 [ V_35 ] . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_116 [ V_35 ] . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_116 [ V_35 ] . V_121 = V_377 [ V_35 ] ;
V_10 -> V_116 [ V_35 ] . V_119 = 0 ;
}
}
F_89 ( V_8 , V_10 ) ;
if ( V_196 )
F_84 ( V_8 -> V_15 , V_10 , V_196 , V_375 ) ;
F_157 ( V_8 , V_10 ) ;
memcpy ( & V_376 -> V_333 , V_10 -> V_11 , sizeof( V_376 -> V_333 ) ) ;
if ( F_147 ( V_357 , V_376 , sizeof( * V_376 ) ) ) {
F_95 ( V_8 , V_10 ) ;
V_378 = - V_335 ;
goto V_382;
}
if ( V_376 -> V_154 . Type . V_286 == V_289 && V_376 -> V_334 > 0 ) {
T_11 T_6 * V_385 = V_376 -> V_25 ;
for ( V_35 = 0 ; V_35 < V_196 ; V_35 ++ ) {
if ( F_147 ( V_385 , V_371 [ V_35 ] , V_377 [ V_35 ] ) ) {
F_95 ( V_8 , V_10 ) ;
V_378 = - V_335 ;
goto V_382;
}
V_385 += V_377 [ V_35 ] ;
}
}
F_95 ( V_8 , V_10 ) ;
V_378 = 0 ;
V_382:
if ( V_371 ) {
for ( V_35 = 0 ; V_35 < V_196 ; V_35 ++ )
F_50 ( V_371 [ V_35 ] ) ;
F_50 ( V_371 ) ;
}
F_50 ( V_377 ) ;
F_50 ( V_376 ) ;
return V_378 ;
}
static void F_157 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_148 == V_150 &&
V_10 -> V_11 -> V_143 != V_151 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_148 ( struct V_2 * V_16 , int V_132 , void * V_327 )
{
struct V_1 * V_8 ;
void T_6 * V_357 = ( void T_6 * ) V_327 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_132 ) {
case V_349 :
case V_350 :
case V_351 :
F_8 ( V_8 -> V_28 ) ;
return 0 ;
case V_339 :
return F_152 ( V_8 , V_357 ) ;
case V_347 :
return F_154 ( V_8 , V_357 ) ;
case V_336 :
return F_155 ( V_8 , V_357 ) ;
case V_338 :
return F_158 ( V_8 , V_357 ) ;
default:
return - V_386 ;
}
}
static int T_12 F_159 ( struct V_1 * V_8 ,
unsigned char * V_38 , V_202 V_387 )
{
struct V_9 * V_10 ;
V_10 = F_125 ( V_8 ) ;
if ( ! V_10 )
return - V_110 ;
F_94 ( V_10 , V_216 , V_8 , NULL , 0 , 0 ,
V_70 , V_217 ) ;
V_10 -> V_154 . V_155 [ 1 ] = V_387 ;
V_10 -> V_205 = NULL ;
F_30 ( V_8 , V_10 ) ;
return 0 ;
}
static void F_94 ( struct V_9 * V_10 , V_202 V_132 , struct V_1 * V_8 ,
void * V_371 , T_2 V_388 , V_202 V_389 , unsigned char * V_38 ,
int V_272 )
{
int V_390 = V_291 ;
V_10 -> V_272 = V_374 ;
V_10 -> V_66 . V_274 = 0 ;
if ( V_371 != NULL && V_388 > 0 ) {
V_10 -> V_66 . V_67 = 1 ;
V_10 -> V_66 . V_122 = 1 ;
} else {
V_10 -> V_66 . V_67 = 0 ;
V_10 -> V_66 . V_122 = 0 ;
}
V_10 -> V_66 . V_276 . V_125 = V_10 -> V_64 ;
memcpy ( V_10 -> V_66 . V_250 . V_275 , V_38 , 8 ) ;
V_10 -> V_154 . Type . Type = V_272 ;
if ( V_272 == V_214 ) {
switch ( V_132 ) {
case V_213 :
if ( V_389 != 0 ) {
V_10 -> V_154 . V_155 [ 1 ] = 0x01 ;
V_10 -> V_154 . V_155 [ 2 ] = V_389 ;
}
V_10 -> V_154 . V_281 = 6 ;
V_10 -> V_154 . Type . V_282 = V_283 ;
V_10 -> V_154 . Type . V_286 = V_289 ;
V_10 -> V_154 . V_279 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_213 ;
V_10 -> V_154 . V_155 [ 4 ] = V_388 & 0xFF ;
break;
case V_221 :
case V_222 :
V_10 -> V_154 . V_281 = 12 ;
V_10 -> V_154 . Type . V_282 = V_283 ;
V_10 -> V_154 . Type . V_286 = V_289 ;
V_10 -> V_154 . V_279 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_132 ;
V_10 -> V_154 . V_155 [ 6 ] = ( V_388 >> 24 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 7 ] = ( V_388 >> 16 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 8 ] = ( V_388 >> 8 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 9 ] = V_388 & 0xFF ;
break;
case V_391 :
V_10 -> V_154 . V_281 = 12 ;
V_10 -> V_154 . Type . V_282 = V_283 ;
V_10 -> V_154 . Type . V_286 = V_287 ;
V_10 -> V_154 . V_279 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_392 ;
V_10 -> V_154 . V_155 [ 6 ] = V_393 ;
V_10 -> V_154 . V_155 [ 7 ] = ( V_388 >> 8 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 8 ] = V_388 & 0xFF ;
break;
case V_308 :
V_10 -> V_154 . V_281 = 6 ;
V_10 -> V_154 . Type . V_282 = V_283 ;
V_10 -> V_154 . Type . V_286 = V_291 ;
V_10 -> V_154 . V_279 = 0 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_120 , V_132 ) ;
F_115 () ;
return;
}
} else if ( V_272 == V_217 ) {
switch ( V_132 ) {
case V_216 :
V_10 -> V_154 . V_281 = 16 ;
V_10 -> V_154 . Type . Type = 1 ;
V_10 -> V_154 . Type . V_282 = V_283 ;
V_10 -> V_154 . Type . V_286 = V_291 ;
V_10 -> V_154 . V_279 = 0 ;
memset ( & V_10 -> V_154 . V_155 [ 0 ] , 0 , sizeof( V_10 -> V_154 . V_155 ) ) ;
V_10 -> V_154 . V_155 [ 0 ] = V_132 ;
V_10 -> V_154 . V_155 [ 1 ] = 0x03 ;
V_10 -> V_154 . V_155 [ 4 ] = 0x00 ;
V_10 -> V_154 . V_155 [ 5 ] = 0x00 ;
V_10 -> V_154 . V_155 [ 6 ] = 0x00 ;
V_10 -> V_154 . V_155 [ 7 ] = 0x00 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_121 ,
V_132 ) ;
F_115 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_122 , V_272 ) ;
F_115 () ;
}
switch ( V_10 -> V_154 . Type . V_286 ) {
case V_289 :
V_390 = V_215 ;
break;
case V_287 :
V_390 = V_123 ;
break;
case V_291 :
V_390 = V_201 ;
break;
default:
V_390 = V_375 ;
}
F_85 ( V_8 -> V_15 , V_10 , V_371 , V_388 , V_390 ) ;
return;
}
static void T_13 * F_160 ( T_14 V_394 , T_14 V_388 )
{
T_14 V_395 = ( ( T_14 ) V_394 ) & V_396 ;
T_14 V_397 = ( ( T_14 ) V_394 ) - V_395 ;
void T_13 * V_398 = F_161 ( V_395 , V_397 + V_388 ) ;
return V_398 ? ( V_398 + V_397 ) : NULL ;
}
static void F_31 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
while ( ! F_34 ( & V_8 -> V_68 ) ) {
V_10 = F_162 ( V_8 -> V_68 . V_399 , struct V_9 , V_55 ) ;
if ( ( V_8 -> V_57 . V_400 ( V_8 ) ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_123 ) ;
break;
}
F_32 ( V_10 ) ;
V_8 -> V_69 -- ;
V_8 -> V_57 . V_401 ( V_8 , V_10 ) ;
F_24 ( & V_8 -> V_402 , V_10 ) ;
}
}
static inline unsigned long F_163 ( struct V_1 * V_8 )
{
return V_8 -> V_57 . V_58 ( V_8 ) ;
}
static inline bool F_164 ( struct V_1 * V_8 )
{
return V_8 -> V_57 . V_403 ( V_8 ) ;
}
static inline long F_165 ( struct V_1 * V_8 )
{
return ( V_8 -> V_57 . V_403 ( V_8 ) == 0 ) ||
( V_8 -> V_404 == 0 ) ;
}
static inline int F_166 ( struct V_1 * V_8 , T_3 V_405 ,
T_3 V_406 )
{
if ( F_27 ( V_405 >= V_8 -> V_108 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_124 , V_406 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_167 ( struct V_9 * V_10 , T_3 V_406 )
{
F_32 ( V_10 ) ;
if ( F_29 ( V_10 -> V_272 == V_273 ) )
F_75 ( V_10 ) ;
else if ( V_10 -> V_272 == V_374 )
F_168 ( V_10 -> V_205 ) ;
}
static inline T_3 F_169 ( T_3 V_407 )
{
return V_407 & V_278 ;
}
static inline T_3 F_170 ( T_3 V_407 )
{
return V_407 >> V_277 ;
}
static inline T_3 F_171 ( struct V_1 * V_8 , T_3 V_407 )
{
#define F_172 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_173 0x03
if ( F_27 ( ! ( V_8 -> V_32 & V_33 ) ) )
return V_407 & ~ F_173 ;
return V_407 & ~ F_172 ;
}
static inline T_3 F_174 ( struct V_1 * V_8 ,
T_3 V_406 )
{
T_3 V_405 ;
struct V_9 * V_10 ;
V_405 = F_170 ( V_406 ) ;
if ( F_166 ( V_8 , V_405 , V_406 ) )
return F_26 ( V_8 ) ;
V_10 = V_8 -> V_319 + V_405 ;
F_167 ( V_10 , V_406 ) ;
return F_26 ( V_8 ) ;
}
static inline T_3 F_175 ( struct V_1 * V_8 ,
T_3 V_406 )
{
T_3 V_407 ;
struct V_9 * V_10 = NULL ;
V_407 = F_171 ( V_8 , V_406 ) ;
F_176 (c, &h->cmpQ, list) {
if ( ( V_10 -> V_64 & 0xFFFFFFE0 ) == ( V_407 & 0xFFFFFFE0 ) ) {
F_167 ( V_10 , V_406 ) ;
return F_26 ( V_8 ) ;
}
}
F_166 ( V_8 , V_8 -> V_108 + 1 , V_406 ) ;
return F_26 ( V_8 ) ;
}
static int F_177 ( struct V_1 * V_8 )
{
if ( F_29 ( ! V_408 ) )
return 0 ;
if ( F_29 ( V_8 -> V_404 ) )
return 0 ;
F_44 ( & V_8 -> V_15 -> V_16 , L_125
L_126 ) ;
return 1 ;
}
static T_15 F_178 ( int V_190 , void * V_409 )
{
struct V_1 * V_8 = V_409 ;
unsigned long V_43 ;
T_3 V_406 ;
if ( F_177 ( V_8 ) )
return V_410 ;
if ( F_165 ( V_8 ) )
return V_410 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_8 -> V_411 = F_179 () ;
while ( F_164 ( V_8 ) ) {
V_406 = F_163 ( V_8 ) ;
while ( V_406 != V_61 )
V_406 = F_26 ( V_8 ) ;
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_412 ;
}
static T_15 F_180 ( int V_190 , void * V_409 )
{
struct V_1 * V_8 = V_409 ;
unsigned long V_43 ;
T_3 V_406 ;
if ( F_177 ( V_8 ) )
return V_410 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_8 -> V_411 = F_179 () ;
V_406 = F_163 ( V_8 ) ;
while ( V_406 != V_61 )
V_406 = F_26 ( V_8 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_412 ;
}
static T_15 F_181 ( int V_190 , void * V_409 )
{
struct V_1 * V_8 = V_409 ;
unsigned long V_43 ;
T_3 V_406 ;
if ( F_165 ( V_8 ) )
return V_410 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_8 -> V_411 = F_179 () ;
while ( F_164 ( V_8 ) ) {
V_406 = F_163 ( V_8 ) ;
while ( V_406 != V_61 ) {
if ( F_169 ( V_406 ) )
V_406 = F_174 ( V_8 , V_406 ) ;
else
V_406 = F_175 ( V_8 , V_406 ) ;
}
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_412 ;
}
static T_15 F_182 ( int V_190 , void * V_409 )
{
struct V_1 * V_8 = V_409 ;
unsigned long V_43 ;
T_3 V_406 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_8 -> V_411 = F_179 () ;
V_406 = F_163 ( V_8 ) ;
while ( V_406 != V_61 ) {
if ( F_169 ( V_406 ) )
V_406 = F_174 ( V_8 , V_406 ) ;
else
V_406 = F_175 ( V_8 , V_406 ) ;
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_412 ;
}
static T_12 int F_183 ( struct V_195 * V_15 , unsigned char V_413 ,
unsigned char type )
{
struct V_414 {
struct V_415 V_416 ;
struct V_417 V_154 ;
struct V_418 V_419 ;
};
struct V_414 * V_132 ;
static const T_2 V_420 = sizeof( * V_132 ) +
sizeof( V_132 -> V_419 ) ;
V_199 V_421 ;
T_16 V_422 , V_407 ;
void T_13 * V_423 ;
int V_35 , V_331 ;
V_423 = F_184 ( V_15 , 0 ) ;
if ( V_423 == NULL )
return - V_110 ;
V_331 = F_185 ( V_15 , F_186 ( 32 ) ) ;
if ( V_331 ) {
F_187 ( V_423 ) ;
return - V_110 ;
}
V_132 = F_139 ( V_15 , V_420 , & V_421 ) ;
if ( V_132 == NULL ) {
F_187 ( V_423 ) ;
return - V_110 ;
}
V_422 = V_421 ;
V_132 -> V_416 . V_274 = 0 ;
V_132 -> V_416 . V_67 = 0 ;
V_132 -> V_416 . V_122 = 0 ;
V_132 -> V_416 . V_276 . V_125 = V_422 ;
V_132 -> V_416 . V_276 . V_126 = 0 ;
memset ( & V_132 -> V_416 . V_250 . V_275 , 0 , 8 ) ;
V_132 -> V_154 . V_281 = 16 ;
V_132 -> V_154 . Type . Type = V_217 ;
V_132 -> V_154 . Type . V_282 = V_424 ;
V_132 -> V_154 . Type . V_286 = V_291 ;
V_132 -> V_154 . V_279 = 0 ;
V_132 -> V_154 . V_155 [ 0 ] = V_413 ;
V_132 -> V_154 . V_155 [ 1 ] = type ;
memset ( & V_132 -> V_154 . V_155 [ 2 ] , 0 , 14 ) ;
V_132 -> V_419 . V_124 . V_125 = V_422 + sizeof( * V_132 ) ;
V_132 -> V_419 . V_124 . V_126 = 0 ;
V_132 -> V_419 . V_121 = sizeof( struct V_133 ) ;
F_188 ( V_422 , V_423 + V_425 ) ;
for ( V_35 = 0 ; V_35 < V_426 ; V_35 ++ ) {
V_407 = F_189 ( V_423 + V_427 ) ;
if ( ( V_407 & ~ F_173 ) == V_422 )
break;
F_134 ( V_428 ) ;
}
F_187 ( V_423 ) ;
if ( V_35 == V_426 ) {
F_43 ( & V_15 -> V_16 , L_127 ,
V_413 , type ) ;
return - V_429 ;
}
F_140 ( V_15 , V_420 , V_132 , V_421 ) ;
if ( V_407 & V_430 ) {
F_43 ( & V_15 -> V_16 , L_128 ,
V_413 , type ) ;
return - V_431 ;
}
F_44 ( & V_15 -> V_16 , L_129 ,
V_413 , type ) ;
return 0 ;
}
static int F_190 ( struct V_195 * V_15 ,
void * T_13 V_423 , T_3 V_432 )
{
V_203 V_433 ;
int V_434 ;
if ( V_432 ) {
F_44 ( & V_15 -> V_16 , L_130 ) ;
F_188 ( V_432 , V_423 + V_435 ) ;
} else {
V_434 = F_191 ( V_15 , V_436 ) ;
if ( V_434 == 0 ) {
F_43 ( & V_15 -> V_16 ,
L_131
L_132 ) ;
return - V_46 ;
}
F_44 ( & V_15 -> V_16 , L_133 ) ;
F_192 ( V_15 , V_434 + V_437 , & V_433 ) ;
V_433 &= ~ V_438 ;
V_433 |= V_439 ;
F_193 ( V_15 , V_434 + V_437 , V_433 ) ;
F_134 ( 500 ) ;
V_433 &= ~ V_438 ;
V_433 |= V_440 ;
F_193 ( V_15 , V_434 + V_437 , V_433 ) ;
F_134 ( 500 ) ;
}
return 0 ;
}
static T_12 void F_194 ( char * V_441 , int V_261 )
{
memset ( V_441 , 0 , V_261 ) ;
strncpy ( V_441 , L_134 V_369 , V_261 - 1 ) ;
}
static T_12 int F_195 (
struct V_442 T_13 * V_443 )
{
char * V_441 ;
int V_35 , V_388 = sizeof( V_443 -> V_441 ) ;
V_441 = F_70 ( V_388 , V_104 ) ;
if ( ! V_441 )
return - V_110 ;
F_194 ( V_441 , V_388 ) ;
for ( V_35 = 0 ; V_35 < V_388 ; V_35 ++ )
F_196 ( V_441 [ V_35 ] , & V_443 -> V_441 [ V_35 ] ) ;
F_50 ( V_441 ) ;
return 0 ;
}
static T_12 void F_197 (
struct V_442 T_13 * V_443 , unsigned char * V_444 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < sizeof( V_443 -> V_441 ) ; V_35 ++ )
V_444 [ V_35 ] = F_198 ( & V_443 -> V_441 [ V_35 ] ) ;
}
static T_12 int F_199 (
struct V_442 T_13 * V_443 )
{
char * V_444 , * V_445 ;
int V_211 , V_388 = sizeof( V_443 -> V_441 ) ;
V_445 = F_70 ( 2 * V_388 , V_104 ) ;
if ( ! V_445 )
return - V_110 ;
V_444 = V_445 + V_388 ;
F_194 ( V_445 , V_388 ) ;
F_197 ( V_443 , V_444 ) ;
V_211 = ! memcmp ( V_444 , V_445 , V_388 ) ;
F_50 ( V_445 ) ;
return V_211 ;
}
static T_12 int F_200 ( struct V_195 * V_15 )
{
T_4 V_446 ;
T_3 V_447 ;
T_4 V_448 ;
void T_13 * V_423 ;
unsigned long V_449 ;
T_3 V_450 ;
int V_211 ;
struct V_442 T_13 * V_443 ;
T_3 V_432 ;
T_3 V_34 ;
V_203 V_451 ;
V_211 = F_201 ( V_15 , & V_34 ) ;
if ( V_211 < 0 || ! F_15 ( V_34 ) ) {
F_5 ( & V_15 -> V_16 , L_135 ) ;
return - V_46 ;
}
if ( ! F_12 ( V_34 ) )
return - V_301 ;
F_192 ( V_15 , 4 , & V_451 ) ;
F_202 ( V_15 ) ;
F_203 ( V_15 ) ;
V_211 = F_204 ( V_15 , & V_449 ) ;
if ( V_211 )
return V_211 ;
V_423 = F_160 ( V_449 , 0x250 ) ;
if ( ! V_423 )
return - V_110 ;
V_211 = F_205 ( V_15 , V_423 , & V_447 ,
& V_448 , & V_446 ) ;
if ( V_211 )
goto V_452;
V_443 = F_160 ( F_206 ( V_15 ,
V_448 ) + V_446 , sizeof( * V_443 ) ) ;
if ( ! V_443 ) {
V_211 = - V_110 ;
goto V_452;
}
V_211 = F_195 ( V_443 ) ;
if ( V_211 )
goto V_452;
V_450 = F_189 ( & V_443 -> V_450 ) ;
V_432 = V_450 & V_453 ;
if ( V_432 ) {
V_432 = V_454 ;
} else {
V_432 = V_450 & V_455 ;
if ( V_432 ) {
F_5 ( & V_15 -> V_16 , L_136
L_137 ) ;
V_211 = - V_301 ;
goto V_456;
}
}
V_211 = F_190 ( V_15 , V_423 , V_432 ) ;
if ( V_211 )
goto V_456;
F_207 ( V_15 ) ;
V_211 = F_208 ( V_15 ) ;
if ( V_211 ) {
F_5 ( & V_15 -> V_16 , L_138 ) ;
goto V_456;
}
F_193 ( V_15 , 4 , V_451 ) ;
F_134 ( V_457 ) ;
F_44 ( & V_15 -> V_16 , L_139 ) ;
V_211 = F_209 ( V_15 , V_423 , V_458 ) ;
if ( V_211 ) {
F_5 ( & V_15 -> V_16 ,
L_140
L_141 ) ;
V_211 = - V_301 ;
goto V_456;
}
V_211 = F_209 ( V_15 , V_423 , V_459 ) ;
if ( V_211 ) {
F_5 ( & V_15 -> V_16 ,
L_142
L_143 ) ;
goto V_456;
}
V_211 = F_199 ( V_423 ) ;
if ( V_211 < 0 )
goto V_456;
if ( V_211 ) {
F_5 ( & V_15 -> V_16 , L_144
L_145 ) ;
V_211 = - V_301 ;
} else {
F_44 ( & V_15 -> V_16 , L_146 ) ;
}
V_456:
F_187 ( V_443 ) ;
V_452:
F_187 ( V_423 ) ;
return V_211 ;
}
static void F_210 ( struct V_22 * V_16 , struct V_442 * V_460 )
{
#ifdef F_211
int V_35 ;
char V_461 [ 17 ] ;
F_44 ( V_16 , L_147 ) ;
F_44 ( V_16 , L_148 ) ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ )
V_461 [ V_35 ] = F_198 ( & ( V_460 -> V_462 [ V_35 ] ) ) ;
V_461 [ 4 ] = '\0' ;
F_44 ( V_16 , L_149 , V_461 ) ;
F_44 ( V_16 , L_150 , F_189 ( & ( V_460 -> V_463 ) ) ) ;
F_44 ( V_16 , L_151 ,
F_189 ( & ( V_460 -> V_464 ) ) ) ;
F_44 ( V_16 , L_152 ,
F_189 ( & ( V_460 -> V_465 ) ) ) ;
F_44 ( V_16 , L_153 ,
F_189 ( & ( V_460 -> V_466 . V_467 ) ) ) ;
F_44 ( V_16 , L_154 ,
F_189 ( & ( V_460 -> V_466 . V_468 ) ) ) ;
F_44 ( V_16 , L_155 ,
F_189 ( & ( V_460 -> V_466 . V_469 ) ) ) ;
F_44 ( V_16 , L_156 ,
F_189 ( & ( V_460 -> V_470 ) ) ) ;
F_44 ( V_16 , L_157 , F_189 ( & ( V_460 -> V_471 ) ) ) ;
for ( V_35 = 0 ; V_35 < 16 ; V_35 ++ )
V_461 [ V_35 ] = F_198 ( & ( V_460 -> V_472 [ V_35 ] ) ) ;
V_461 [ 16 ] = '\0' ;
F_44 ( V_16 , L_158 , V_461 ) ;
F_44 ( V_16 , L_159 ,
F_189 ( & ( V_460 -> V_473 ) ) ) ;
#endif
}
static int F_212 ( struct V_195 * V_15 , unsigned long V_474 )
{
int V_35 , V_475 , V_476 , V_477 ;
if ( V_474 == V_478 )
return 0 ;
V_475 = 0 ;
for ( V_35 = 0 ; V_35 < V_479 ; V_35 ++ ) {
V_477 = F_213 ( V_15 , V_35 ) & V_480 ;
if ( V_477 == V_481 )
V_475 += 4 ;
else {
V_476 = F_213 ( V_15 , V_35 ) &
V_482 ;
switch ( V_476 ) {
case V_483 :
case V_484 :
V_475 += 4 ;
break;
case V_485 :
V_475 += 8 ;
break;
default:
F_5 ( & V_15 -> V_16 ,
L_160 ) ;
return - 1 ;
break;
}
}
if ( V_475 == V_474 - V_478 )
return V_35 + 1 ;
}
return - 1 ;
}
static void T_12 F_214 ( struct V_1 * V_8 )
{
#ifdef F_215
int V_331 ;
struct V_486 V_487 [ 4 ] = { { 0 , 0 } , { 0 , 1 } ,
{ 0 , 2 } , { 0 , 3 }
} ;
if ( ( V_8 -> V_34 == 0x40700E11 ) || ( V_8 -> V_34 == 0x40800E11 ) ||
( V_8 -> V_34 == 0x40820E11 ) || ( V_8 -> V_34 == 0x40830E11 ) )
goto V_488;
if ( F_191 ( V_8 -> V_15 , V_489 ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_161 ) ;
V_331 = F_216 ( V_8 -> V_15 , V_487 , 4 ) ;
if ( ! V_331 ) {
V_8 -> V_191 [ 0 ] = V_487 [ 0 ] . V_490 ;
V_8 -> V_191 [ 1 ] = V_487 [ 1 ] . V_490 ;
V_8 -> V_191 [ 2 ] = V_487 [ 2 ] . V_490 ;
V_8 -> V_191 [ 3 ] = V_487 [ 3 ] . V_490 ;
V_8 -> V_491 = 1 ;
return;
}
if ( V_331 > 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_162
L_163 , V_331 ) ;
goto V_488;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_164 ,
V_331 ) ;
goto V_488;
}
}
if ( F_191 ( V_8 -> V_15 , V_492 ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_165 ) ;
if ( ! F_217 ( V_8 -> V_15 ) )
V_8 -> V_493 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_166 ) ;
}
V_488:
#endif
V_8 -> V_191 [ V_8 -> V_192 ] = V_8 -> V_15 -> V_190 ;
}
static int T_12 F_201 ( struct V_195 * V_15 , T_3 * V_34 )
{
int V_35 ;
T_3 V_494 , V_495 ;
V_494 = V_15 -> V_496 ;
V_495 = V_15 -> V_497 ;
* V_34 = ( ( V_495 << 16 ) & 0xffff0000 ) |
V_494 ;
for ( V_35 = 0 ; V_35 < F_13 ( V_498 ) ; V_35 ++ )
if ( * V_34 == V_498 [ V_35 ] . V_34 )
return V_35 ;
if ( ( V_494 != V_499 &&
V_494 != V_500 ) ||
! V_501 ) {
F_5 ( & V_15 -> V_16 , L_167
L_168 , * V_34 ) ;
return - V_46 ;
}
return F_13 ( V_498 ) - 1 ;
}
static inline bool F_218 ( struct V_195 * V_15 )
{
V_203 V_502 ;
( void ) F_192 ( V_15 , V_503 , & V_502 ) ;
return ( ( V_502 & V_504 ) == 0 ) ;
}
static int T_12 F_204 ( struct V_195 * V_15 ,
unsigned long * V_505 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_479 ; V_35 ++ )
if ( F_213 ( V_15 , V_35 ) & V_506 ) {
* V_505 = F_206 ( V_15 , V_35 ) ;
F_219 ( & V_15 -> V_16 , L_169 ,
* V_505 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_170 ) ;
return - V_46 ;
}
static int T_12 F_209 ( struct V_195 * V_15 ,
void T_13 * V_423 , int V_507 )
{
int V_35 , V_508 ;
T_3 V_509 ;
if ( V_507 )
V_508 = V_510 ;
else
V_508 = V_511 ;
for ( V_35 = 0 ; V_35 < V_508 ; V_35 ++ ) {
V_509 = F_189 ( V_423 + V_512 ) ;
if ( V_507 ) {
if ( V_509 == V_513 )
return 0 ;
} else {
if ( V_509 != V_513 )
return 0 ;
}
F_134 ( V_514 ) ;
}
F_5 ( & V_15 -> V_16 , L_171 ) ;
return - V_46 ;
}
static int T_12 F_205 ( struct V_195 * V_15 ,
void T_13 * V_423 , T_3 * V_447 , T_4 * V_448 ,
T_4 * V_446 )
{
* V_447 = F_189 ( V_423 + V_515 ) ;
* V_446 = F_189 ( V_423 + V_516 ) ;
* V_447 &= ( T_3 ) 0x0000ffff ;
* V_448 = F_212 ( V_15 , * V_447 ) ;
if ( * V_448 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_172 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_12 F_220 ( struct V_1 * V_8 )
{
T_4 V_446 ;
T_3 V_447 ;
T_4 V_448 ;
T_3 V_517 ;
int V_211 ;
V_211 = F_205 ( V_8 -> V_15 , V_8 -> V_423 , & V_447 ,
& V_448 , & V_446 ) ;
if ( V_211 )
return V_211 ;
V_8 -> V_443 = F_160 ( F_206 ( V_8 -> V_15 ,
V_448 ) + V_446 , sizeof( * V_8 -> V_443 ) ) ;
if ( ! V_8 -> V_443 )
return - V_110 ;
V_211 = F_195 ( V_8 -> V_443 ) ;
if ( V_211 )
return V_211 ;
V_517 = F_189 ( & V_8 -> V_443 -> V_518 ) ;
V_8 -> V_519 = F_160 ( F_206 ( V_8 -> V_15 ,
V_448 ) + V_446 + V_517 ,
sizeof( * V_8 -> V_519 ) ) ;
if ( ! V_8 -> V_519 )
return - V_110 ;
return 0 ;
}
static void T_12 F_221 ( struct V_1 * V_8 )
{
V_8 -> V_63 = F_189 ( & ( V_8 -> V_443 -> V_520 ) ) ;
if ( V_408 && V_8 -> V_63 > 32 )
V_8 -> V_63 = 32 ;
if ( V_8 -> V_63 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_173
L_174
L_175 ,
V_8 -> V_63 ) ;
V_8 -> V_63 = 16 ;
}
}
static void T_12 F_222 ( struct V_1 * V_8 )
{
F_221 ( V_8 ) ;
V_8 -> V_108 = V_8 -> V_63 - 4 ;
V_8 -> V_189 = F_189 ( & ( V_8 -> V_443 -> V_521 ) ) ;
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
static inline bool F_223 ( struct V_1 * V_8 )
{
if ( ( F_198 ( & V_8 -> V_443 -> V_462 [ 0 ] ) != 'C' ) ||
( F_198 ( & V_8 -> V_443 -> V_462 [ 1 ] ) != 'I' ) ||
( F_198 ( & V_8 -> V_443 -> V_462 [ 2 ] ) != 'S' ) ||
( F_198 ( & V_8 -> V_443 -> V_462 [ 3 ] ) != 'S' ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_176 ) ;
return false ;
}
return true ;
}
static inline void F_224 ( struct V_1 * V_8 )
{
#ifdef F_225
T_3 V_522 ;
V_522 = F_189 ( & ( V_8 -> V_443 -> V_523 ) ) ;
V_522 |= 0x100 ;
F_188 ( V_522 , & ( V_8 -> V_443 -> V_523 ) ) ;
#endif
}
static inline void F_226 ( struct V_1 * V_8 )
{
T_3 V_524 ;
if ( V_8 -> V_34 != 0x3225103C )
return;
V_524 = F_189 ( V_8 -> V_423 + V_525 ) ;
V_524 |= 0x8000 ;
F_188 ( V_524 , V_8 -> V_423 + V_525 ) ;
}
static void T_12 F_227 ( struct V_1 * V_8 )
{
int V_35 ;
T_3 V_526 ;
unsigned long V_43 ;
for ( V_35 = 0 ; V_35 < V_527 ; V_35 ++ ) {
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_526 = F_189 ( V_8 -> V_423 + V_435 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
if ( ! ( V_526 & V_528 ) )
break;
F_228 ( 10000 , 20000 ) ;
}
}
static int T_12 F_229 ( struct V_1 * V_8 )
{
T_3 V_529 ;
V_529 = F_189 ( & ( V_8 -> V_443 -> V_464 ) ) ;
if ( ! ( V_529 & V_530 ) )
return - V_301 ;
V_8 -> V_63 = F_189 ( & ( V_8 -> V_443 -> V_470 ) ) ;
F_188 ( V_531 , & ( V_8 -> V_443 -> V_466 . V_467 ) ) ;
F_188 ( V_528 , V_8 -> V_423 + V_435 ) ;
F_227 ( V_8 ) ;
F_210 ( & V_8 -> V_15 -> V_16 , V_8 -> V_443 ) ;
if ( ! ( F_189 ( & ( V_8 -> V_443 -> V_465 ) ) & V_531 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_177 ) ;
return - V_46 ;
}
V_8 -> V_32 = V_531 ;
return 0 ;
}
static int T_12 F_230 ( struct V_1 * V_8 )
{
int V_532 , V_331 ;
V_532 = F_201 ( V_8 -> V_15 , & V_8 -> V_34 ) ;
if ( V_532 < 0 )
return - V_46 ;
V_8 -> V_533 = V_498 [ V_532 ] . V_533 ;
V_8 -> V_57 = * ( V_498 [ V_532 ] . V_57 ) ;
if ( F_218 ( V_8 -> V_15 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_178 ) ;
return - V_46 ;
}
F_231 ( V_8 -> V_15 , V_534 |
V_535 | V_536 ) ;
V_331 = F_208 ( V_8 -> V_15 ) ;
if ( V_331 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_179 ) ;
return V_331 ;
}
V_331 = F_232 ( V_8 -> V_15 , L_180 ) ;
if ( V_331 ) {
F_43 ( & V_8 -> V_15 -> V_16 ,
L_181 ) ;
return V_331 ;
}
F_214 ( V_8 ) ;
V_331 = F_204 ( V_8 -> V_15 , & V_8 -> V_449 ) ;
if ( V_331 )
goto V_537;
V_8 -> V_423 = F_160 ( V_8 -> V_449 , 0x250 ) ;
if ( ! V_8 -> V_423 ) {
V_331 = - V_110 ;
goto V_537;
}
V_331 = F_209 ( V_8 -> V_15 , V_8 -> V_423 , V_459 ) ;
if ( V_331 )
goto V_537;
V_331 = F_220 ( V_8 ) ;
if ( V_331 )
goto V_537;
F_222 ( V_8 ) ;
if ( ! F_223 ( V_8 ) ) {
V_331 = - V_46 ;
goto V_537;
}
F_224 ( V_8 ) ;
F_226 ( V_8 ) ;
V_331 = F_229 ( V_8 ) ;
if ( V_331 )
goto V_537;
return 0 ;
V_537:
if ( V_8 -> V_519 )
F_187 ( V_8 -> V_519 ) ;
if ( V_8 -> V_443 )
F_187 ( V_8 -> V_443 ) ;
if ( V_8 -> V_423 )
F_187 ( V_8 -> V_423 ) ;
F_233 ( V_8 -> V_15 ) ;
return V_331 ;
}
static void T_12 F_234 ( struct V_1 * V_8 )
{
int V_211 ;
#define F_235 64
V_8 -> V_30 = F_70 ( F_235 , V_104 ) ;
if ( ! V_8 -> V_30 )
return;
V_211 = F_92 ( V_8 , V_70 , 0 ,
V_8 -> V_30 , F_235 ) ;
if ( V_211 != 0 ) {
F_50 ( V_8 -> V_30 ) ;
V_8 -> V_30 = NULL ;
}
}
static T_12 int F_236 ( struct V_195 * V_15 )
{
int V_211 , V_35 ;
if ( ! V_408 )
return 0 ;
V_211 = F_200 ( V_15 ) ;
if ( V_211 == - V_301 )
return V_211 ;
if ( V_211 )
return - V_46 ;
F_5 ( & V_15 -> V_16 , L_182 ) ;
for ( V_35 = 0 ; V_35 < V_538 ; V_35 ++ ) {
if ( F_237 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_183 ,
( V_35 < 11 ? L_184 : L_185 ) ) ;
}
return 0 ;
}
static T_12 int F_238 ( struct V_1 * V_8 )
{
V_8 -> V_317 = F_58 (
F_239 ( V_8 -> V_108 , V_318 ) *
sizeof( unsigned long ) , V_104 ) ;
V_8 -> V_319 = F_139 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( * V_8 -> V_319 ) ,
& ( V_8 -> V_320 ) ) ;
V_8 -> V_321 = F_139 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( * V_8 -> V_321 ) ,
& ( V_8 -> V_322 ) ) ;
if ( ( V_8 -> V_317 == NULL )
|| ( V_8 -> V_319 == NULL )
|| ( V_8 -> V_321 == NULL ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_186 , V_539 ) ;
return - V_110 ;
}
return 0 ;
}
static void F_240 ( struct V_1 * V_8 )
{
F_50 ( V_8 -> V_317 ) ;
if ( V_8 -> V_319 )
F_140 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_9 ) ,
V_8 -> V_319 , V_8 -> V_320 ) ;
if ( V_8 -> V_321 )
F_140 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_133 ) ,
V_8 -> V_321 ,
V_8 -> V_322 ) ;
}
static int F_241 ( struct V_1 * V_8 ,
T_15 (* F_242)( int , void * ) ,
T_15 (* F_243)( int , void * ) )
{
int V_211 ;
if ( V_8 -> V_491 || V_8 -> V_493 )
V_211 = F_244 ( V_8 -> V_191 [ V_8 -> V_192 ] , F_242 ,
V_540 , V_8 -> V_541 , V_8 ) ;
else
V_211 = F_244 ( V_8 -> V_191 [ V_8 -> V_192 ] , F_243 ,
V_540 , V_8 -> V_541 , V_8 ) ;
if ( V_211 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_187 ,
V_8 -> V_191 [ V_8 -> V_192 ] , V_8 -> V_541 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_12 F_245 ( struct V_1 * V_8 )
{
if ( F_159 ( V_8 , V_70 ,
V_542 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_188 ) ;
return - V_431 ;
}
F_44 ( & V_8 -> V_15 -> V_16 , L_189 ) ;
if ( F_209 ( V_8 -> V_15 , V_8 -> V_423 , V_458 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_190 ) ;
return - 1 ;
}
F_44 ( & V_8 -> V_15 -> V_16 , L_191 ) ;
if ( F_209 ( V_8 -> V_15 , V_8 -> V_423 , V_459 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_192
L_193 ) ;
return - 1 ;
}
return 0 ;
}
static void F_246 ( struct V_1 * V_8 )
{
F_247 ( V_8 -> V_191 [ V_8 -> V_192 ] , V_8 ) ;
#ifdef F_215
if ( V_8 -> V_491 )
F_248 ( V_8 -> V_15 ) ;
else if ( V_8 -> V_493 )
F_249 ( V_8 -> V_15 ) ;
#endif
F_68 ( V_8 ) ;
F_240 ( V_8 ) ;
F_50 ( V_8 -> V_65 ) ;
F_140 ( V_8 -> V_15 , V_8 -> V_543 ,
V_8 -> V_62 , V_8 -> V_544 ) ;
if ( V_8 -> V_423 )
F_187 ( V_8 -> V_423 ) ;
if ( V_8 -> V_519 )
F_187 ( V_8 -> V_519 ) ;
if ( V_8 -> V_443 )
F_187 ( V_8 -> V_443 ) ;
F_233 ( V_8 -> V_15 ) ;
F_50 ( V_8 ) ;
}
static void F_250 ( struct V_1 * V_8 )
{
F_251 ( & V_545 ) ;
if ( ! V_546 )
return;
if ( V_8 -> V_206 )
return;
F_252 ( & V_8 -> V_547 ) ;
}
static void F_253 ( struct V_1 * V_8 , struct V_54 * V_55 )
{
struct V_9 * V_10 = NULL ;
F_251 ( & V_8 -> V_44 ) ;
while ( ! F_34 ( V_55 ) ) {
V_10 = F_162 ( V_55 -> V_399 , struct V_9 , V_55 ) ;
V_10 -> V_11 -> V_148 = V_165 ;
F_167 ( V_10 , V_10 -> V_66 . V_276 . V_125 ) ;
}
}
static void F_254 ( struct V_1 * V_8 )
{
unsigned long V_43 ;
F_251 ( & V_545 ) ;
F_250 ( V_8 ) ;
V_8 -> V_57 . V_548 ( V_8 , V_549 ) ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_8 -> V_206 = F_189 ( V_8 -> V_423 + V_512 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_194 ,
V_8 -> V_206 ) ;
F_202 ( V_8 -> V_15 ) ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
F_253 ( V_8 , & V_8 -> V_402 ) ;
F_253 ( V_8 , & V_8 -> V_68 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
}
static void F_255 ( struct V_1 * V_8 )
{
T_4 V_550 ;
T_3 V_551 ;
unsigned long V_43 ;
F_251 ( & V_545 ) ;
V_550 = F_179 () ;
if ( F_256 ( V_8 -> V_411 +
( V_552 ) , V_550 ) )
return;
if ( F_256 ( V_8 -> V_553 +
( V_552 ) , V_550 ) )
return;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_551 = F_189 ( & V_8 -> V_443 -> V_473 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
if ( V_8 -> V_554 == V_551 ) {
F_254 ( V_8 ) ;
return;
}
V_8 -> V_554 = V_551 ;
V_8 -> V_553 = V_550 ;
}
static int F_257 ( void * V_555 )
{
struct V_1 * V_8 ;
unsigned long V_43 ;
while ( 1 ) {
struct V_54 * V_556 , * V_557 ;
F_258 ( V_558 ) ;
if ( F_259 () )
break;
F_20 ( & V_545 , V_43 ) ;
F_260 (this, tmp, &hpsa_ctlr_list) {
V_8 = F_162 ( V_556 , struct V_1 , V_547 ) ;
F_255 ( V_8 ) ;
}
F_21 ( & V_545 , V_43 ) ;
}
return 0 ;
}
static void F_261 ( struct V_1 * V_8 )
{
unsigned long V_43 ;
F_20 ( & V_545 , V_43 ) ;
F_25 ( & V_8 -> V_547 , & V_559 ) ;
F_21 ( & V_545 , V_43 ) ;
}
static void F_262 ( struct V_1 * V_8 )
{
if ( ! V_546 ) {
F_263 ( & V_545 ) ;
V_546 =
F_264 ( F_257 ,
NULL , L_180 ) ;
}
if ( ! V_546 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_195 ) ;
return;
}
F_261 ( V_8 ) ;
}
static void F_265 ( struct V_1 * V_8 )
{
unsigned long V_43 ;
F_20 ( & V_545 , V_43 ) ;
F_250 ( V_8 ) ;
if ( F_34 ( & V_559 ) ) {
F_266 ( V_546 ) ;
V_546 = NULL ;
}
F_21 ( & V_545 , V_43 ) ;
}
static int T_12 F_267 ( struct V_195 * V_15 ,
const struct V_560 * V_561 )
{
int V_562 , V_211 ;
struct V_1 * V_8 ;
int V_563 = 0 ;
unsigned long V_43 ;
if ( V_564 == 0 )
F_268 (KERN_INFO DRIVER_NAME L_196 ) ;
V_211 = F_236 ( V_15 ) ;
if ( V_211 ) {
if ( V_211 != - V_301 )
return V_211 ;
V_563 = 1 ;
V_211 = 0 ;
}
V_565:
#define F_269 32
F_270 ( sizeof( struct V_9 ) % F_269 ) ;
V_8 = F_58 ( sizeof( * V_8 ) , V_104 ) ;
if ( ! V_8 )
return - V_110 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_192 = V_566 ? V_567 : V_568 ;
F_138 ( & V_8 -> V_402 ) ;
F_138 ( & V_8 -> V_68 ) ;
F_263 ( & V_8 -> V_44 ) ;
F_263 ( & V_8 -> V_296 ) ;
V_211 = F_230 ( V_8 ) ;
if ( V_211 != 0 )
goto V_569;
sprintf ( V_8 -> V_541 , L_197 , V_564 ) ;
V_8 -> V_17 = V_564 ;
V_564 ++ ;
V_211 = F_271 ( V_15 , F_186 ( 64 ) ) ;
if ( V_211 == 0 ) {
V_562 = 1 ;
} else {
V_211 = F_271 ( V_15 , F_186 ( 32 ) ) ;
if ( V_211 == 0 ) {
V_562 = 0 ;
} else {
F_43 ( & V_15 -> V_16 , L_198 ) ;
goto V_569;
}
}
V_8 -> V_57 . V_548 ( V_8 , V_549 ) ;
if ( F_241 ( V_8 , F_182 , F_181 ) )
goto V_570;
F_44 ( & V_15 -> V_16 , L_199 ,
V_8 -> V_541 , V_15 -> V_22 ,
V_8 -> V_191 [ V_8 -> V_192 ] , V_562 ? L_185 : L_200 ) ;
if ( F_238 ( V_8 ) )
goto V_571;
if ( F_69 ( V_8 ) )
goto V_571;
F_272 ( & V_8 -> V_572 ) ;
V_8 -> V_297 = 1 ;
F_273 ( V_15 , V_8 ) ;
V_8 -> V_77 = 0 ;
V_8 -> V_28 = NULL ;
F_263 ( & V_8 -> V_106 ) ;
F_274 ( V_8 ) ;
if ( V_563 ) {
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_8 -> V_57 . V_548 ( V_8 , V_549 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
F_247 ( V_8 -> V_191 [ V_8 -> V_192 ] , V_8 ) ;
V_211 = F_241 ( V_8 , F_180 ,
F_178 ) ;
if ( V_211 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_201
L_202 ) ;
goto V_571;
}
V_211 = F_245 ( V_8 ) ;
if ( V_211 )
goto V_571;
F_44 ( & V_8 -> V_15 -> V_16 , L_203 ) ;
F_44 ( & V_8 -> V_15 -> V_16 ,
L_204 ) ;
V_8 -> V_57 . V_548 ( V_8 , V_573 ) ;
F_134 ( 10000 ) ;
V_8 -> V_57 . V_548 ( V_8 , V_549 ) ;
V_211 = F_199 ( V_8 -> V_443 ) ;
if ( V_211 )
F_44 ( & V_8 -> V_15 -> V_16 ,
L_205 ) ;
F_246 ( V_8 ) ;
V_563 = 0 ;
if ( V_211 )
return - V_46 ;
goto V_565;
}
V_8 -> V_57 . V_548 ( V_8 , V_573 ) ;
F_234 ( V_8 ) ;
F_132 ( V_8 ) ;
F_262 ( V_8 ) ;
return 1 ;
V_571:
F_68 ( V_8 ) ;
F_240 ( V_8 ) ;
F_247 ( V_8 -> V_191 [ V_8 -> V_192 ] , V_8 ) ;
V_570:
V_569:
F_50 ( V_8 ) ;
return V_211 ;
}
static void F_275 ( struct V_1 * V_8 )
{
char * V_574 ;
struct V_9 * V_10 ;
V_574 = F_58 ( 4 , V_104 ) ;
if ( ! V_574 )
return;
V_10 = F_93 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
goto V_575;
}
F_94 ( V_10 , V_391 , V_8 , V_574 , 4 , 0 ,
V_70 , V_214 ) ;
F_90 ( V_8 , V_10 , V_123 ) ;
if ( V_10 -> V_11 -> V_148 != 0 )
F_5 ( & V_8 -> V_15 -> V_16 ,
L_206 ) ;
F_95 ( V_8 , V_10 ) ;
V_575:
F_50 ( V_574 ) ;
}
static void F_276 ( struct V_195 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_277 ( V_15 ) ;
F_275 ( V_8 ) ;
V_8 -> V_57 . V_548 ( V_8 , V_549 ) ;
F_247 ( V_8 -> V_191 [ V_8 -> V_192 ] , V_8 ) ;
#ifdef F_215
if ( V_8 -> V_491 )
F_248 ( V_8 -> V_15 ) ;
else if ( V_8 -> V_493 )
F_249 ( V_8 -> V_15 ) ;
#endif
}
static void T_17 F_278 ( struct V_195 * V_15 )
{
struct V_1 * V_8 ;
if ( F_277 ( V_15 ) == NULL ) {
F_43 ( & V_15 -> V_16 , L_207 ) ;
return;
}
V_8 = F_277 ( V_15 ) ;
F_265 ( V_8 ) ;
F_130 ( V_8 ) ;
F_276 ( V_15 ) ;
F_187 ( V_8 -> V_423 ) ;
F_187 ( V_8 -> V_519 ) ;
F_187 ( V_8 -> V_443 ) ;
F_68 ( V_8 ) ;
F_140 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_9 ) ,
V_8 -> V_319 , V_8 -> V_320 ) ;
F_140 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_133 ) ,
V_8 -> V_321 , V_8 -> V_322 ) ;
F_140 ( V_8 -> V_15 , V_8 -> V_543 ,
V_8 -> V_62 , V_8 -> V_544 ) ;
F_50 ( V_8 -> V_317 ) ;
F_50 ( V_8 -> V_65 ) ;
F_50 ( V_8 -> V_30 ) ;
F_233 ( V_15 ) ;
F_273 ( V_15 , NULL ) ;
F_50 ( V_8 ) ;
}
static void F_279 ( int V_576 [] , int V_577 ,
int V_578 , int * V_579 )
{
int V_35 , V_91 , V_580 , V_388 ;
#define F_280 4
#define F_281 8
for ( V_35 = 0 ; V_35 <= V_578 ; V_35 ++ ) {
V_388 = V_35 + F_280 ;
V_580 = V_577 ;
for ( V_91 = 0 ; V_91 < 8 ; V_91 ++ ) {
if ( V_576 [ V_91 ] >= V_388 ) {
V_580 = V_91 ;
break;
}
}
V_579 [ V_35 ] = V_580 ;
}
}
static T_12 void F_282 ( struct V_1 * V_8 ,
T_3 V_581 )
{
int V_35 ;
unsigned long V_582 ;
int V_583 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_384 + 4 } ;
F_270 ( 28 > V_384 + 4 ) ;
V_8 -> V_60 = 1 ;
memset ( V_8 -> V_62 , 0 , V_8 -> V_543 ) ;
V_8 -> V_59 = V_8 -> V_62 ;
V_583 [ 7 ] = V_8 -> V_584 + 4 ;
F_279 ( V_583 , F_13 ( V_583 ) , 32 , V_8 -> V_65 ) ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ )
F_188 ( V_583 [ V_35 ] , & V_8 -> V_519 -> V_585 [ V_35 ] ) ;
F_188 ( V_8 -> V_63 , & V_8 -> V_519 -> V_586 ) ;
F_188 ( 1 , & V_8 -> V_519 -> V_587 ) ;
F_188 ( 0 , & V_8 -> V_519 -> V_588 ) ;
F_188 ( 0 , & V_8 -> V_519 -> V_589 ) ;
F_188 ( V_8 -> V_544 , & V_8 -> V_519 -> V_590 ) ;
F_188 ( 0 , & V_8 -> V_519 -> V_591 ) ;
F_188 ( V_33 | V_581 ,
& ( V_8 -> V_443 -> V_466 . V_467 ) ) ;
F_188 ( V_528 , V_8 -> V_423 + V_435 ) ;
F_227 ( V_8 ) ;
V_582 = F_189 ( & ( V_8 -> V_443 -> V_465 ) ) ;
if ( ! ( V_582 & V_33 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_208
L_209 ) ;
return;
}
V_8 -> V_57 = V_592 ;
V_8 -> V_32 = V_33 ;
}
static T_12 void F_274 ( struct V_1 * V_8 )
{
T_3 V_529 ;
if ( V_566 )
return;
V_529 = F_189 ( & ( V_8 -> V_443 -> V_464 ) ) ;
if ( ! ( V_529 & V_593 ) )
return;
F_221 ( V_8 ) ;
V_8 -> V_584 = 32 ;
V_8 -> V_543 = V_8 -> V_63 * sizeof( T_4 ) ;
V_8 -> V_62 = F_139 ( V_8 -> V_15 , V_8 -> V_543 ,
& ( V_8 -> V_544 ) ) ;
V_8 -> V_65 = F_70 ( ( ( V_8 -> V_584 + 1 ) *
sizeof( T_3 ) ) , V_104 ) ;
if ( ( V_8 -> V_62 == NULL )
|| ( V_8 -> V_65 == NULL ) )
goto V_594;
F_282 ( V_8 ,
V_529 & V_595 ) ;
return;
V_594:
if ( V_8 -> V_62 )
F_140 ( V_8 -> V_15 , V_8 -> V_543 ,
V_8 -> V_62 , V_8 -> V_544 ) ;
F_50 ( V_8 -> V_65 ) ;
}
static int T_18 F_283 ( void )
{
return F_284 ( & V_596 ) ;
}
static void T_19 F_285 ( void )
{
F_286 ( & V_596 ) ;
}

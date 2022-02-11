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
V_132 -> V_140 = V_172 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_65
L_66 , V_130 ) ;
break;
case V_173 :
V_132 -> V_140 = V_174 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_67 , V_130 ) ;
break;
case V_175 :
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
V_7 = F_80 ( & V_176 , sizeof( V_8 ) ) ;
if ( V_7 == NULL )
goto V_177;
V_7 -> V_178 = 0 ;
V_7 -> V_179 = 0 ;
V_7 -> V_180 = - 1 ;
V_7 -> V_181 = 3 ;
V_7 -> V_182 = V_183 ;
V_7 -> V_184 = V_185 ;
V_7 -> V_186 = V_185 ;
V_7 -> V_187 = V_8 -> V_108 ;
V_7 -> V_188 = V_8 -> V_108 ;
V_7 -> V_189 = V_8 -> V_190 ;
V_8 -> V_28 = V_7 ;
V_7 -> V_45 [ 0 ] = ( unsigned long ) V_8 ;
V_7 -> V_191 = V_8 -> V_192 [ V_8 -> V_193 ] ;
V_7 -> V_194 = V_7 -> V_191 ;
error = F_81 ( V_7 , & V_8 -> V_15 -> V_16 ) ;
if ( error )
goto V_195;
F_82 ( V_7 ) ;
return 0 ;
V_195:
F_43 ( & V_8 -> V_15 -> V_16 , L_70
L_71 , V_8 -> V_17 ) ;
F_83 ( V_7 ) ;
return error ;
V_177:
F_43 ( & V_8 -> V_15 -> V_16 , L_72
L_71 , V_8 -> V_17 ) ;
return - V_110 ;
}
static void F_84 ( struct V_196 * V_15 ,
struct V_9 * V_10 , int V_197 , int V_198 )
{
int V_35 ;
union V_127 V_199 ;
for ( V_35 = 0 ; V_35 < V_197 ; V_35 ++ ) {
V_199 . V_128 . V_125 = V_10 -> V_116 [ V_35 ] . V_124 . V_125 ;
V_199 . V_128 . V_126 = V_10 -> V_116 [ V_35 ] . V_124 . V_126 ;
F_74 ( V_15 , ( V_200 ) V_199 . V_129 , V_10 -> V_116 [ V_35 ] . V_121 ,
V_198 ) ;
}
}
static void F_85 ( struct V_196 * V_15 ,
struct V_9 * V_130 ,
unsigned char * V_25 ,
T_2 V_201 ,
int V_198 )
{
T_4 V_199 ;
if ( V_201 == 0 || V_198 == V_202 ) {
V_130 -> V_66 . V_67 = 0 ;
V_130 -> V_66 . V_122 = 0 ;
return;
}
V_199 = ( T_4 ) F_72 ( V_15 , V_25 , V_201 , V_198 ) ;
V_130 -> V_116 [ 0 ] . V_124 . V_125 =
( T_3 ) ( V_199 & ( T_4 ) 0x00000000FFFFFFFF ) ;
V_130 -> V_116 [ 0 ] . V_124 . V_126 =
( T_3 ) ( ( V_199 >> 32 ) & ( T_4 ) 0x00000000FFFFFFFF ) ;
V_130 -> V_116 [ 0 ] . V_121 = V_201 ;
V_130 -> V_66 . V_67 = ( V_203 ) 1 ;
V_130 -> V_66 . V_122 = ( V_204 ) 1 ;
}
static inline void F_86 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_87 ( V_205 ) ;
V_10 -> V_206 = & V_205 ;
F_30 ( V_8 , V_10 ) ;
F_88 ( & V_205 ) ;
}
static void F_89 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_198 )
{
int V_207 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_86 ( V_8 , V_10 ) ;
V_207 ++ ;
} while ( F_4 ( V_8 , V_10 ) && V_207 <= 3 );
F_84 ( V_8 -> V_15 , V_10 , 1 , V_198 ) ;
}
static void F_90 ( struct V_9 * V_130 )
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
case V_173 :
F_5 ( V_208 , L_87 , V_130 ) ;
break;
case V_175 :
F_5 ( V_208 , L_68 ) ;
break;
default:
F_5 ( V_208 , L_69 , V_130 ,
V_134 -> V_148 ) ;
}
}
static int F_91 ( struct V_1 * V_8 , unsigned char * V_38 ,
unsigned char V_209 , unsigned char * V_25 ,
unsigned char V_210 )
{
int V_211 = V_212 ;
struct V_9 * V_10 ;
struct V_133 * V_134 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - V_110 ;
}
F_93 ( V_10 , V_213 , V_8 , V_25 , V_210 , V_209 , V_38 , V_214 ) ;
F_89 ( V_8 , V_10 , V_215 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 && V_134 -> V_148 != V_161 ) {
F_90 ( V_10 ) ;
V_211 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_211 ;
}
static int F_95 ( struct V_1 * V_8 , unsigned char * V_38 )
{
int V_211 = V_212 ;
struct V_9 * V_10 ;
struct V_133 * V_134 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - V_110 ;
}
F_93 ( V_10 , V_216 , V_8 , NULL , 0 , 0 , V_38 , V_217 ) ;
F_86 ( V_8 , V_10 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 ) {
F_90 ( V_10 ) ;
V_211 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_211 ;
}
static void F_96 ( struct V_1 * V_8 ,
unsigned char * V_38 , unsigned char * V_48 )
{
int V_211 ;
unsigned char * V_25 ;
* V_48 = V_49 ;
V_25 = F_58 ( 64 , V_104 ) ;
if ( ! V_25 )
return;
V_211 = F_91 ( V_8 , V_38 , 0xC1 , V_25 , 64 ) ;
if ( V_211 == 0 )
* V_48 = V_25 [ 8 ] ;
if ( * V_48 > V_49 )
* V_48 = V_49 ;
F_50 ( V_25 ) ;
return;
}
static int F_97 ( struct V_1 * V_8 , unsigned char * V_38 ,
unsigned char * V_53 , int V_201 )
{
int V_211 ;
unsigned char * V_25 ;
if ( V_201 > 16 )
V_201 = 16 ;
V_25 = F_58 ( 64 , V_104 ) ;
if ( ! V_25 )
return - 1 ;
V_211 = F_91 ( V_8 , V_38 , 0x83 , V_25 , 64 ) ;
if ( V_211 == 0 )
memcpy ( V_53 , & V_25 [ 8 ] , V_201 ) ;
F_50 ( V_25 ) ;
return V_211 != 0 ;
}
static int F_98 ( struct V_1 * V_8 , int V_218 ,
struct V_219 * V_25 , int V_210 ,
int V_220 )
{
int V_211 = V_212 ;
struct V_9 * V_10 ;
unsigned char V_38 [ 8 ] ;
struct V_133 * V_134 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
return - 1 ;
}
memset ( V_38 , 0 , sizeof( V_38 ) ) ;
F_93 ( V_10 , V_218 ? V_221 : V_222 , V_8 ,
V_25 , V_210 , 0 , V_38 , V_214 ) ;
if ( V_220 )
V_10 -> V_154 . V_155 [ 1 ] = V_220 ;
F_89 ( V_8 , V_10 , V_215 ) ;
V_134 = V_10 -> V_11 ;
if ( V_134 -> V_148 != 0 &&
V_134 -> V_148 != V_161 ) {
F_90 ( V_10 ) ;
V_211 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_211 ;
}
static inline int F_99 ( struct V_1 * V_8 ,
struct V_219 * V_25 ,
int V_210 , int V_220 )
{
return F_98 ( V_8 , 0 , V_25 , V_210 , V_220 ) ;
}
static inline int F_100 ( struct V_1 * V_8 ,
struct V_219 * V_25 , int V_210 )
{
return F_98 ( V_8 , 1 , V_25 , V_210 , 0 ) ;
}
static inline void F_101 ( struct V_41 * V_22 ,
int V_71 , int V_72 , int V_73 )
{
V_22 -> V_71 = V_71 ;
V_22 -> V_72 = V_72 ;
V_22 -> V_73 = V_73 ;
}
static int F_102 ( struct V_1 * V_8 ,
unsigned char V_38 [] , struct V_41 * V_223 )
{
#define F_103 49
unsigned char * V_224 ;
V_224 = F_58 ( F_103 , V_104 ) ;
if ( ! V_224 )
goto V_225;
if ( F_91 ( V_8 , V_38 , 0 , V_224 ,
( unsigned char ) F_103 ) != 0 ) {
F_43 ( & V_8 -> V_15 -> V_16 ,
L_89 ) ;
goto V_225;
}
V_223 -> V_86 = ( V_224 [ 0 ] & 0x1f ) ;
memcpy ( V_223 -> V_38 , V_38 , 8 ) ;
memcpy ( V_223 -> V_95 , & V_224 [ 8 ] ,
sizeof( V_223 -> V_95 ) ) ;
memcpy ( V_223 -> V_94 , & V_224 [ 16 ] ,
sizeof( V_223 -> V_94 ) ) ;
memset ( V_223 -> V_53 , 0 ,
sizeof( V_223 -> V_53 ) ) ;
F_97 ( V_8 , V_38 , V_223 -> V_53 ,
sizeof( V_223 -> V_53 ) ) ;
if ( V_223 -> V_86 == V_226 &&
F_17 ( V_38 ) )
F_96 ( V_8 , V_38 , & V_223 -> V_48 ) ;
else
V_223 -> V_48 = V_49 ;
F_50 ( V_224 ) ;
return 0 ;
V_225:
F_50 ( V_224 ) ;
return 1 ;
}
static int F_104 ( struct V_1 * V_8 , struct V_41 * V_22 )
{
int V_35 ;
for ( V_35 = 0 ; V_227 [ V_35 ] ; V_35 ++ )
if ( strncmp ( V_22 -> V_94 , V_227 [ V_35 ] ,
strlen ( V_227 [ V_35 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_105 ( struct V_1 * V_8 ,
V_203 * V_228 , int * V_71 , int * V_72 , int * V_73 ,
struct V_41 * V_22 )
{
T_3 V_51 ;
if ( F_17 ( V_228 ) ) {
if ( F_27 ( F_37 ( V_8 ) ) ) {
V_51 = F_106 ( * ( ( V_229 * ) V_228 ) ) ;
* V_71 = 0 ;
* V_72 = 0 ;
* V_73 = ( V_51 & 0x3fff ) + 1 ;
} else {
V_51 = F_106 ( * ( ( V_229 * ) V_228 ) ) ;
if ( F_104 ( V_8 , V_22 ) ) {
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
if ( F_36 ( V_228 ) )
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
static int F_107 ( struct V_1 * V_8 ,
struct V_41 * V_230 ,
struct V_41 * V_223 , V_203 * V_228 ,
int V_71 , int V_72 , int V_73 , unsigned long V_231 [] ,
int * V_232 )
{
unsigned char V_38 [ 8 ] ;
if ( F_41 ( V_72 , V_231 ) )
return 0 ;
if ( ! F_17 ( V_228 ) )
return 0 ;
if ( ! F_104 ( V_8 , V_230 ) )
return 0 ;
if ( V_73 == 0 )
return 0 ;
memset ( V_38 , 0 , 8 ) ;
V_38 [ 3 ] = V_72 ;
if ( F_36 ( V_38 ) )
return 0 ;
if ( F_37 ( V_8 ) )
return 0 ;
#define F_108 32
if ( * V_232 >= F_108 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_90
L_91
L_92 ) ;
return 0 ;
}
if ( F_102 ( V_8 , V_38 , V_223 ) )
return 0 ;
( * V_232 ) ++ ;
F_101 ( V_223 , V_71 , V_72 , 0 ) ;
F_40 ( V_72 , V_231 ) ;
return 1 ;
}
static int F_109 ( struct V_1 * V_8 ,
int V_233 ,
struct V_219 * V_234 , T_3 * V_235 ,
struct V_219 * V_236 , T_3 * V_237 )
{
if ( F_99 ( V_8 , V_234 , V_233 , 0 ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_93 ) ;
return - 1 ;
}
* V_235 = F_110 ( * ( ( V_238 * ) V_234 -> V_239 ) ) / 8 ;
if ( * V_235 > V_240 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_94
L_95 , V_240 ,
* V_235 - V_240 ) ;
* V_235 = V_240 ;
}
if ( F_100 ( V_8 , V_236 , V_233 ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_96 ) ;
return - 1 ;
}
* V_237 = F_110 ( * ( ( V_238 * ) V_236 -> V_239 ) ) / 8 ;
if ( * V_237 > V_185 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_97
L_98 , V_185 ,
* V_237 - V_185 ) ;
* V_237 = V_185 ;
}
if ( * V_237 + * V_235 > V_240 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_99
L_98 , V_240 ,
* V_235 + * V_237 - V_240 ) ;
* V_237 = V_240 - * V_235 ;
}
return 0 ;
}
V_203 * F_111 ( struct V_1 * V_8 , int V_241 , int V_35 ,
int V_235 , int V_237 , struct V_219 * V_242 ,
struct V_219 * V_243 )
{
int V_244 = V_235 + ( V_241 == 0 ) ;
int V_245 = V_235 + V_237 + ( V_241 == 0 ) ;
if ( V_35 == V_241 )
return V_70 ;
if ( V_35 < V_244 )
return & V_242 -> V_246 [ V_35 - ( V_241 == 0 ) ] [ 0 ] ;
if ( V_35 < V_245 )
return & V_243 -> V_246 [ V_35 - V_235 -
( V_241 == 0 ) ] [ 0 ] ;
F_112 () ;
return NULL ;
}
static void F_113 ( struct V_1 * V_8 , int V_78 )
{
struct V_219 * V_242 = NULL ;
struct V_219 * V_243 = NULL ;
unsigned char * V_224 = NULL ;
T_3 V_235 = 0 ;
T_3 V_237 = 0 ;
T_3 V_247 = 0 ;
struct V_41 * * V_248 , * V_223 , * V_230 ;
int V_249 = 0 ;
int V_233 = sizeof( * V_242 ) + V_240 * 8 ;
int V_35 , V_232 , V_250 ;
int V_71 , V_72 , V_73 ;
int V_241 ;
F_39 ( V_231 , V_251 ) ;
V_248 = F_58 ( sizeof( * V_248 ) * V_76 ,
V_104 ) ;
V_242 = F_58 ( V_233 , V_104 ) ;
V_243 = F_58 ( V_233 , V_104 ) ;
V_224 = F_70 ( F_103 , V_104 ) ;
V_230 = F_58 ( sizeof( * V_230 ) , V_104 ) ;
if ( ! V_248 || ! V_242 || ! V_243 ||
! V_224 || ! V_230 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_100 ) ;
goto V_252;
}
memset ( V_231 , 0 , sizeof( V_231 ) ) ;
if ( F_109 ( V_8 , V_233 , V_242 , & V_235 ,
V_243 , & V_237 ) )
goto V_252;
V_250 = V_235 + V_237 + F_108 + 1 ;
for ( V_35 = 0 ; V_35 < V_250 ; V_35 ++ ) {
V_248 [ V_35 ] = F_58 ( sizeof( * V_248 [ V_35 ] ) , V_104 ) ;
if ( ! V_248 [ V_35 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_101 ,
__FILE__ , __LINE__ ) ;
goto V_252;
}
V_247 ++ ;
}
if ( F_27 ( F_37 ( V_8 ) ) )
V_241 = 0 ;
else
V_241 = V_235 + V_237 ;
V_232 = 0 ;
for ( V_35 = 0 ; V_35 < V_235 + V_237 + 1 ; V_35 ++ ) {
V_203 * V_228 ;
V_228 = F_111 ( V_8 , V_241 ,
V_35 , V_235 , V_237 , V_242 , V_243 ) ;
if ( V_228 [ 3 ] & 0xC0 &&
V_35 < V_235 + ( V_241 == 0 ) )
continue;
if ( F_102 ( V_8 , V_228 , V_230 ) )
continue;
F_105 ( V_8 , V_228 , & V_71 , & V_72 , & V_73 ,
V_230 ) ;
V_223 = V_248 [ V_249 ] ;
if ( F_107 ( V_8 , V_230 , V_223 ,
V_228 , V_71 , V_72 , V_73 , V_231 ,
& V_232 ) ) {
V_249 ++ ;
V_223 = V_248 [ V_249 ] ;
}
* V_223 = * V_230 ;
F_101 ( V_223 , V_71 , V_72 , V_73 ) ;
switch ( V_223 -> V_86 ) {
case V_253 : {
char V_254 [ 7 ] ;
#define F_114 "$DR-10"
strncpy ( V_254 , & V_224 [ 43 ] , 6 ) ;
V_254 [ 6 ] = '\0' ;
if ( strncmp ( V_254 , F_114 , 6 ) != 0 )
break;
}
V_249 ++ ;
break;
case V_226 :
if ( V_35 < V_235 )
break;
V_249 ++ ;
break;
case V_255 :
case V_256 :
V_249 ++ ;
break;
case V_257 :
if ( ! F_36 ( V_228 ) )
break;
V_249 ++ ;
break;
default:
break;
}
if ( V_249 >= V_76 )
break;
}
F_57 ( V_8 , V_78 , V_248 , V_249 ) ;
V_252:
F_50 ( V_230 ) ;
for ( V_35 = 0 ; V_35 < V_247 ; V_35 ++ )
F_50 ( V_248 [ V_35 ] ) ;
F_50 ( V_248 ) ;
F_50 ( V_224 ) ;
F_50 ( V_242 ) ;
F_50 ( V_243 ) ;
}
static int F_115 ( struct V_1 * V_8 ,
struct V_9 * V_130 ,
struct V_131 * V_132 )
{
unsigned int V_258 ;
struct V_259 * V_260 ;
T_4 V_199 ;
int V_261 , V_35 , V_262 , V_263 ;
struct V_112 * V_264 ;
F_47 ( F_116 ( V_132 ) > V_8 -> V_190 ) ;
V_261 = F_117 ( V_132 ) ;
if ( V_261 < 0 )
return V_261 ;
if ( ! V_261 )
goto V_265;
V_264 = V_130 -> V_116 ;
V_263 = 0 ;
V_262 = 0 ;
F_118 (cmd, sg, use_sg, i) {
if ( V_35 == V_8 -> V_117 - 1 &&
V_261 > V_8 -> V_117 ) {
V_263 = 1 ;
V_264 = V_8 -> V_107 [ V_130 -> V_118 ] ;
V_262 = 0 ;
}
V_199 = ( T_4 ) F_119 ( V_260 ) ;
V_258 = F_120 ( V_260 ) ;
V_264 -> V_124 . V_125 = ( T_3 ) ( V_199 & 0x0FFFFFFFFULL ) ;
V_264 -> V_124 . V_126 = ( T_3 ) ( ( V_199 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_264 -> V_121 = V_258 ;
V_264 -> V_119 = 0 ;
V_264 ++ ;
}
if ( V_261 + V_263 > V_8 -> V_266 )
V_8 -> V_266 = V_261 + V_263 ;
if ( V_263 ) {
V_130 -> V_66 . V_67 = V_8 -> V_117 ;
V_130 -> V_66 . V_122 = ( V_204 ) ( V_261 + 1 ) ;
F_71 ( V_8 , V_130 ) ;
return 0 ;
}
V_265:
V_130 -> V_66 . V_67 = ( V_203 ) V_261 ;
V_130 -> V_66 . V_122 = ( V_204 ) V_261 ;
return 0 ;
}
static int F_121 ( struct V_131 * V_132 ,
void (* F_122)( struct V_131 * ) )
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
F_122 ( V_132 ) ;
return 0 ;
}
memcpy ( V_38 , V_16 -> V_38 , sizeof( V_38 ) ) ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_10 = F_123 ( V_8 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
if ( V_10 == NULL ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_102 ) ;
return V_267 ;
}
V_132 -> V_149 = F_122 ;
V_132 -> V_268 = ( unsigned char * ) V_10 ;
V_10 -> V_269 = V_270 ;
V_10 -> V_139 = V_132 ;
V_10 -> V_66 . V_271 = 0 ;
memcpy ( & V_10 -> V_66 . V_246 . V_272 [ 0 ] , & V_38 [ 0 ] , 8 ) ;
V_10 -> V_66 . V_273 . V_125 = ( V_10 -> V_118 << V_274 ) ;
V_10 -> V_66 . V_273 . V_125 |= V_275 ;
V_10 -> V_154 . V_276 = 0 ;
memset ( V_10 -> V_154 . V_155 , 0 , sizeof( V_10 -> V_154 . V_155 ) ) ;
F_47 ( V_132 -> V_277 > sizeof( V_10 -> V_154 . V_155 ) ) ;
V_10 -> V_154 . V_278 = V_132 -> V_277 ;
memcpy ( V_10 -> V_154 . V_155 , V_132 -> V_159 , V_132 -> V_277 ) ;
V_10 -> V_154 . Type . Type = V_214 ;
V_10 -> V_154 . Type . V_279 = V_280 ;
switch ( V_132 -> V_281 ) {
case V_282 :
V_10 -> V_154 . Type . V_283 = V_284 ;
break;
case V_285 :
V_10 -> V_154 . Type . V_283 = V_286 ;
break;
case V_287 :
V_10 -> V_154 . Type . V_283 = V_288 ;
break;
case V_289 :
V_10 -> V_154 . Type . V_283 = V_290 ;
break;
default:
F_43 ( & V_8 -> V_15 -> V_16 , L_103 ,
V_132 -> V_281 ) ;
F_112 () ;
break;
}
if ( F_115 ( V_8 , V_10 , V_132 ) < 0 ) {
F_78 ( V_8 , V_10 ) ;
return V_267 ;
}
F_30 ( V_8 , V_10 ) ;
return 0 ;
}
int F_124 ( struct V_6 * V_7 ,
unsigned long V_291 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_43 ;
int V_292 ;
F_20 ( & V_8 -> V_293 , V_43 ) ;
V_292 = V_8 -> V_294 ;
F_21 ( & V_8 -> V_293 , V_43 ) ;
return V_292 ;
}
static int F_125 ( struct V_2 * V_3 ,
int V_295 , int V_296 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_296 != V_297 )
return - V_298 ;
if ( V_295 < 1 )
V_295 = 1 ;
else
if ( V_295 > V_8 -> V_108 )
V_295 = V_8 -> V_108 ;
F_126 ( V_3 , F_127 ( V_3 ) , V_295 ) ;
return V_3 -> V_299 ;
}
static void F_128 ( struct V_1 * V_8 )
{
F_129 ( V_8 -> V_28 ) ;
F_83 ( V_8 -> V_28 ) ;
V_8 -> V_28 = NULL ;
}
static int F_130 ( struct V_1 * V_8 )
{
int V_211 ;
V_211 = F_79 ( V_8 ) ;
if ( V_211 != 0 )
F_43 ( & V_8 -> V_15 -> V_16 , L_104
L_105 , V_211 ) ;
return V_211 ;
}
static int F_131 ( struct V_1 * V_8 ,
unsigned char V_300 [] )
{
int V_211 = 0 ;
int V_26 = 0 ;
int V_301 = 1 ;
struct V_9 * V_10 ;
V_10 = F_92 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_31
L_106 ) ;
return V_302 ;
}
while ( V_26 < V_303 ) {
F_132 ( 1000 * V_301 ) ;
V_26 ++ ;
if ( V_301 < V_304 )
V_301 = V_301 * 2 ;
F_93 ( V_10 , V_305 , V_8 , NULL , 0 , 0 , V_300 , V_214 ) ;
F_86 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_148 == V_306 )
break;
if ( V_10 -> V_11 -> V_148 == V_150 &&
V_10 -> V_11 -> V_143 == V_151 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_307 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_107
L_108 , V_301 ) ;
V_211 = 1 ;
}
if ( V_211 )
F_5 ( & V_8 -> V_15 -> V_16 , L_109 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
F_94 ( V_8 , V_10 ) ;
return V_211 ;
}
static int F_133 ( struct V_131 * V_308 )
{
int V_211 ;
struct V_1 * V_8 ;
struct V_41 * V_16 ;
V_8 = F_1 ( V_308 -> V_22 ) ;
if ( V_8 == NULL )
return V_309 ;
V_16 = V_308 -> V_22 -> V_45 ;
if ( ! V_16 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_111
L_112 ) ;
return V_309 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_113 ,
V_8 -> V_28 -> V_310 , V_16 -> V_71 , V_16 -> V_72 , V_16 -> V_73 ) ;
V_211 = F_95 ( V_8 , V_16 -> V_38 ) ;
if ( V_211 == 0 && F_131 ( V_8 , V_16 -> V_38 ) == 0 )
return V_311 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_114 ) ;
return V_309 ;
}
static struct V_9 * F_123 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_35 ;
union V_127 V_115 ;
V_200 V_312 , V_313 ;
do {
V_35 = F_134 ( V_8 -> V_314 , V_8 -> V_108 ) ;
if ( V_35 == V_8 -> V_108 )
return NULL ;
} while ( F_135
( V_35 & ( V_315 - 1 ) ,
V_8 -> V_314 + ( V_35 / V_315 ) ) != 0 );
V_10 = V_8 -> V_316 + V_35 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_312 = V_8 -> V_317
+ V_35 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_318 + V_35 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_313 = V_8 -> V_319
+ V_35 * sizeof( * V_10 -> V_11 ) ;
V_8 -> V_320 ++ ;
V_10 -> V_118 = V_35 ;
F_136 ( & V_10 -> V_55 ) ;
V_10 -> V_64 = ( T_3 ) V_312 ;
V_115 . V_129 = ( T_4 ) V_313 ;
V_10 -> V_321 . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_321 . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_321 . V_121 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static struct V_9 * F_92 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
union V_127 V_115 ;
V_200 V_312 , V_313 ;
V_10 = F_137 ( V_8 -> V_15 , sizeof( * V_10 ) , & V_312 ) ;
if ( V_10 == NULL )
return NULL ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_118 = - 1 ;
V_10 -> V_11 = F_137 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
& V_313 ) ;
if ( V_10 -> V_11 == NULL ) {
F_138 ( V_8 -> V_15 ,
sizeof( * V_10 ) , V_10 , V_312 ) ;
return NULL ;
}
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_136 ( & V_10 -> V_55 ) ;
V_10 -> V_64 = ( T_3 ) V_312 ;
V_115 . V_129 = ( T_4 ) V_313 ;
V_10 -> V_321 . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_321 . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_321 . V_121 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_78 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
int V_35 ;
V_35 = V_10 - V_8 -> V_316 ;
F_139 ( V_35 & ( V_315 - 1 ) ,
V_8 -> V_314 + ( V_35 / V_315 ) ) ;
V_8 -> V_322 ++ ;
}
static void F_94 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
union V_127 V_115 ;
V_115 . V_128 . V_125 = V_10 -> V_321 . V_124 . V_125 ;
V_115 . V_128 . V_126 = V_10 -> V_321 . V_124 . V_126 ;
F_138 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
V_10 -> V_11 , ( V_200 ) V_115 . V_129 ) ;
F_138 ( V_8 -> V_15 , sizeof( * V_10 ) ,
V_10 , ( V_200 ) ( V_10 -> V_64 & V_323 ) ) ;
}
static int F_140 ( struct V_2 * V_16 , int V_132 , void * V_324 )
{
T_5 T_6 * V_325 =
( T_5 T_6 * ) V_324 ;
T_7 V_326 ;
T_7 T_6 * V_327 = F_141 ( sizeof( V_326 ) ) ;
int V_328 ;
T_3 V_130 ;
memset ( & V_326 , 0 , sizeof( V_326 ) ) ;
V_328 = 0 ;
V_328 |= F_142 ( & V_326 . V_329 , & V_325 -> V_329 ,
sizeof( V_326 . V_329 ) ) ;
V_328 |= F_142 ( & V_326 . V_154 , & V_325 -> V_154 ,
sizeof( V_326 . V_154 ) ) ;
V_328 |= F_142 ( & V_326 . V_330 , & V_325 -> V_330 ,
sizeof( V_326 . V_330 ) ) ;
V_328 |= F_143 ( V_326 . V_331 , & V_325 -> V_331 ) ;
V_328 |= F_143 ( V_130 , & V_325 -> V_25 ) ;
V_326 . V_25 = F_144 ( V_130 ) ;
V_328 |= F_145 ( V_327 , & V_326 , sizeof( V_326 ) ) ;
if ( V_328 )
return - V_332 ;
V_328 = F_146 ( V_16 , V_333 , ( void * ) V_327 ) ;
if ( V_328 )
return V_328 ;
V_328 |= F_147 ( & V_325 -> V_330 , & V_327 -> V_330 ,
sizeof( V_325 -> V_330 ) ) ;
if ( V_328 )
return - V_332 ;
return V_328 ;
}
static int F_148 ( struct V_2 * V_16 ,
int V_132 , void * V_324 )
{
T_8 T_6 * V_325 =
( T_8 T_6 * ) V_324 ;
T_9 V_326 ;
T_9 T_6 * V_327 =
F_141 ( sizeof( V_326 ) ) ;
int V_328 ;
T_3 V_130 ;
memset ( & V_326 , 0 , sizeof( V_326 ) ) ;
V_328 = 0 ;
V_328 |= F_142 ( & V_326 . V_329 , & V_325 -> V_329 ,
sizeof( V_326 . V_329 ) ) ;
V_328 |= F_142 ( & V_326 . V_154 , & V_325 -> V_154 ,
sizeof( V_326 . V_154 ) ) ;
V_328 |= F_142 ( & V_326 . V_330 , & V_325 -> V_330 ,
sizeof( V_326 . V_330 ) ) ;
V_328 |= F_143 ( V_326 . V_331 , & V_325 -> V_331 ) ;
V_328 |= F_143 ( V_326 . V_334 , & V_325 -> V_334 ) ;
V_328 |= F_143 ( V_130 , & V_325 -> V_25 ) ;
V_326 . V_25 = F_144 ( V_130 ) ;
V_328 |= F_145 ( V_327 , & V_326 , sizeof( V_326 ) ) ;
if ( V_328 )
return - V_332 ;
V_328 = F_146 ( V_16 , V_335 , ( void * ) V_327 ) ;
if ( V_328 )
return V_328 ;
V_328 |= F_147 ( & V_325 -> V_330 , & V_327 -> V_330 ,
sizeof( V_325 -> V_330 ) ) ;
if ( V_328 )
return - V_332 ;
return V_328 ;
}
static int F_149 ( struct V_2 * V_16 , int V_132 , void * V_324 )
{
switch ( V_132 ) {
case V_336 :
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
return F_146 ( V_16 , V_132 , V_324 ) ;
case V_351 :
return F_140 ( V_16 , V_132 , V_324 ) ;
case V_352 :
return F_148 ( V_16 , V_132 , V_324 ) ;
default:
return - V_353 ;
}
}
static int F_150 ( struct V_1 * V_8 , void T_6 * V_354 )
{
struct V_355 V_356 ;
if ( ! V_354 )
return - V_357 ;
V_356 . V_358 = F_151 ( V_8 -> V_15 -> V_71 ) ;
V_356 . V_71 = V_8 -> V_15 -> V_71 -> V_359 ;
V_356 . V_360 = V_8 -> V_15 -> V_361 ;
V_356 . V_34 = V_8 -> V_34 ;
if ( F_145 ( V_354 , & V_356 , sizeof( V_356 ) ) )
return - V_332 ;
return 0 ;
}
static int F_152 ( struct V_1 * V_8 , void T_6 * V_354 )
{
T_10 V_362 ;
unsigned char V_363 , V_364 , V_365 ;
int V_211 ;
V_211 = sscanf ( V_366 , L_115 ,
& V_363 , & V_364 , & V_365 ) ;
if ( V_211 != 3 ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_116
L_117 , V_366 ) ;
V_363 = 0 ;
V_364 = 0 ;
V_365 = 0 ;
}
V_362 = ( V_363 << 16 ) | ( V_364 << 8 ) | V_365 ;
if ( ! V_354 )
return - V_357 ;
if ( F_145 ( V_354 , & V_362 , sizeof( T_10 ) ) )
return - V_332 ;
return 0 ;
}
static int F_153 ( struct V_1 * V_8 , void T_6 * V_354 )
{
T_7 V_367 ;
struct V_9 * V_10 ;
char * V_368 = NULL ;
union V_127 V_115 ;
if ( ! V_354 )
return - V_357 ;
if ( ! F_154 ( V_369 ) )
return - V_370 ;
if ( F_142 ( & V_367 , V_354 , sizeof( V_367 ) ) )
return - V_332 ;
if ( ( V_367 . V_331 < 1 ) &&
( V_367 . V_154 . Type . V_283 != V_288 ) ) {
return - V_357 ;
}
if ( V_367 . V_331 > 0 ) {
V_368 = F_70 ( V_367 . V_331 , V_104 ) ;
if ( V_368 == NULL )
return - V_332 ;
if ( V_367 . V_154 . Type . V_283 == V_284 ) {
if ( F_142 ( V_368 , V_367 . V_25 ,
V_367 . V_331 ) ) {
F_50 ( V_368 ) ;
return - V_332 ;
}
} else {
memset ( V_368 , 0 , V_367 . V_331 ) ;
}
}
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_50 ( V_368 ) ;
return - V_110 ;
}
V_10 -> V_269 = V_371 ;
V_10 -> V_66 . V_271 = 0 ;
if ( V_367 . V_331 > 0 ) {
V_10 -> V_66 . V_67 = 1 ;
V_10 -> V_66 . V_122 = 1 ;
} else {
V_10 -> V_66 . V_67 = 0 ;
V_10 -> V_66 . V_122 = 0 ;
}
memcpy ( & V_10 -> V_66 . V_246 , & V_367 . V_329 , sizeof( V_10 -> V_66 . V_246 ) ) ;
V_10 -> V_66 . V_273 . V_125 = V_10 -> V_64 ;
memcpy ( & V_10 -> V_154 , & V_367 . V_154 ,
sizeof( V_10 -> V_154 ) ) ;
if ( V_367 . V_331 > 0 ) {
V_115 . V_129 = F_72 ( V_8 -> V_15 , V_368 ,
V_367 . V_331 , V_372 ) ;
V_10 -> V_116 [ 0 ] . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_116 [ 0 ] . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_116 [ 0 ] . V_121 = V_367 . V_331 ;
V_10 -> V_116 [ 0 ] . V_119 = 0 ;
}
F_86 ( V_8 , V_10 ) ;
if ( V_367 . V_331 > 0 )
F_84 ( V_8 -> V_15 , V_10 , 1 , V_372 ) ;
F_155 ( V_8 , V_10 ) ;
memcpy ( & V_367 . V_330 , V_10 -> V_11 ,
sizeof( V_367 . V_330 ) ) ;
if ( F_145 ( V_354 , & V_367 , sizeof( V_367 ) ) ) {
F_50 ( V_368 ) ;
F_94 ( V_8 , V_10 ) ;
return - V_332 ;
}
if ( V_367 . V_154 . Type . V_283 == V_286 &&
V_367 . V_331 > 0 ) {
if ( F_145 ( V_367 . V_25 , V_368 , V_367 . V_331 ) ) {
F_50 ( V_368 ) ;
F_94 ( V_8 , V_10 ) ;
return - V_332 ;
}
}
F_50 ( V_368 ) ;
F_94 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_156 ( struct V_1 * V_8 , void T_6 * V_354 )
{
T_9 * V_373 ;
struct V_9 * V_10 ;
unsigned char * * V_368 = NULL ;
int * V_374 = NULL ;
union V_127 V_115 ;
T_11 V_197 = 0 ;
int V_375 = 0 ;
int V_35 ;
T_3 V_376 ;
T_3 V_377 ;
T_11 T_6 * V_378 ;
if ( ! V_354 )
return - V_357 ;
if ( ! F_154 ( V_369 ) )
return - V_370 ;
V_373 = ( T_9 * )
F_70 ( sizeof( * V_373 ) , V_104 ) ;
if ( ! V_373 ) {
V_375 = - V_110 ;
goto V_379;
}
if ( F_142 ( V_373 , V_354 , sizeof( * V_373 ) ) ) {
V_375 = - V_332 ;
goto V_379;
}
if ( ( V_373 -> V_331 < 1 ) &&
( V_373 -> V_154 . Type . V_283 != V_288 ) ) {
V_375 = - V_357 ;
goto V_379;
}
if ( V_373 -> V_334 > V_380 ) {
V_375 = - V_357 ;
goto V_379;
}
if ( V_373 -> V_331 > V_373 -> V_334 * V_381 ) {
V_375 = - V_357 ;
goto V_379;
}
V_368 = F_58 ( V_381 * sizeof( char * ) , V_104 ) ;
if ( ! V_368 ) {
V_375 = - V_110 ;
goto V_379;
}
V_374 = F_70 ( V_381 * sizeof( int ) , V_104 ) ;
if ( ! V_374 ) {
V_375 = - V_110 ;
goto V_379;
}
V_376 = V_373 -> V_331 ;
V_378 = V_373 -> V_25 ;
while ( V_376 ) {
V_377 = ( V_376 > V_373 -> V_334 ) ? V_373 -> V_334 : V_376 ;
V_374 [ V_197 ] = V_377 ;
V_368 [ V_197 ] = F_70 ( V_377 , V_104 ) ;
if ( V_368 [ V_197 ] == NULL ) {
V_375 = - V_110 ;
goto V_379;
}
if ( V_373 -> V_154 . Type . V_283 == V_284 ) {
if ( F_142 ( V_368 [ V_197 ] , V_378 , V_377 ) ) {
V_375 = - V_110 ;
goto V_379;
}
} else
memset ( V_368 [ V_197 ] , 0 , V_377 ) ;
V_376 -= V_377 ;
V_378 += V_377 ;
V_197 ++ ;
}
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
V_375 = - V_110 ;
goto V_379;
}
V_10 -> V_269 = V_371 ;
V_10 -> V_66 . V_271 = 0 ;
V_10 -> V_66 . V_67 = V_10 -> V_66 . V_122 = V_197 ;
memcpy ( & V_10 -> V_66 . V_246 , & V_373 -> V_329 , sizeof( V_10 -> V_66 . V_246 ) ) ;
V_10 -> V_66 . V_273 . V_125 = V_10 -> V_64 ;
memcpy ( & V_10 -> V_154 , & V_373 -> V_154 , sizeof( V_10 -> V_154 ) ) ;
if ( V_373 -> V_331 > 0 ) {
int V_35 ;
for ( V_35 = 0 ; V_35 < V_197 ; V_35 ++ ) {
V_115 . V_129 = F_72 ( V_8 -> V_15 , V_368 [ V_35 ] ,
V_374 [ V_35 ] , V_372 ) ;
V_10 -> V_116 [ V_35 ] . V_124 . V_125 = V_115 . V_128 . V_125 ;
V_10 -> V_116 [ V_35 ] . V_124 . V_126 = V_115 . V_128 . V_126 ;
V_10 -> V_116 [ V_35 ] . V_121 = V_374 [ V_35 ] ;
V_10 -> V_116 [ V_35 ] . V_119 = 0 ;
}
}
F_86 ( V_8 , V_10 ) ;
if ( V_197 )
F_84 ( V_8 -> V_15 , V_10 , V_197 , V_372 ) ;
F_155 ( V_8 , V_10 ) ;
memcpy ( & V_373 -> V_330 , V_10 -> V_11 , sizeof( V_373 -> V_330 ) ) ;
if ( F_145 ( V_354 , V_373 , sizeof( * V_373 ) ) ) {
F_94 ( V_8 , V_10 ) ;
V_375 = - V_332 ;
goto V_379;
}
if ( V_373 -> V_154 . Type . V_283 == V_286 && V_373 -> V_331 > 0 ) {
T_11 T_6 * V_382 = V_373 -> V_25 ;
for ( V_35 = 0 ; V_35 < V_197 ; V_35 ++ ) {
if ( F_145 ( V_382 , V_368 [ V_35 ] , V_374 [ V_35 ] ) ) {
F_94 ( V_8 , V_10 ) ;
V_375 = - V_332 ;
goto V_379;
}
V_382 += V_374 [ V_35 ] ;
}
}
F_94 ( V_8 , V_10 ) ;
V_375 = 0 ;
V_379:
if ( V_368 ) {
for ( V_35 = 0 ; V_35 < V_197 ; V_35 ++ )
F_50 ( V_368 [ V_35 ] ) ;
F_50 ( V_368 ) ;
}
F_50 ( V_374 ) ;
F_50 ( V_373 ) ;
return V_375 ;
}
static void F_155 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_148 == V_150 &&
V_10 -> V_11 -> V_143 != V_151 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_146 ( struct V_2 * V_16 , int V_132 , void * V_324 )
{
struct V_1 * V_8 ;
void T_6 * V_354 = ( void T_6 * ) V_324 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_132 ) {
case V_346 :
case V_347 :
case V_348 :
F_8 ( V_8 -> V_28 ) ;
return 0 ;
case V_336 :
return F_150 ( V_8 , V_354 ) ;
case V_344 :
return F_152 ( V_8 , V_354 ) ;
case V_333 :
return F_153 ( V_8 , V_354 ) ;
case V_335 :
return F_156 ( V_8 , V_354 ) ;
default:
return - V_383 ;
}
}
static int T_12 F_157 ( struct V_1 * V_8 ,
unsigned char * V_38 , V_203 V_384 )
{
struct V_9 * V_10 ;
V_10 = F_123 ( V_8 ) ;
if ( ! V_10 )
return - V_110 ;
F_93 ( V_10 , V_216 , V_8 , NULL , 0 , 0 ,
V_70 , V_217 ) ;
V_10 -> V_154 . V_155 [ 1 ] = V_384 ;
V_10 -> V_206 = NULL ;
F_30 ( V_8 , V_10 ) ;
return 0 ;
}
static void F_93 ( struct V_9 * V_10 , V_203 V_132 , struct V_1 * V_8 ,
void * V_368 , T_2 V_385 , V_203 V_386 , unsigned char * V_38 ,
int V_269 )
{
int V_387 = V_288 ;
V_10 -> V_269 = V_371 ;
V_10 -> V_66 . V_271 = 0 ;
if ( V_368 != NULL && V_385 > 0 ) {
V_10 -> V_66 . V_67 = 1 ;
V_10 -> V_66 . V_122 = 1 ;
} else {
V_10 -> V_66 . V_67 = 0 ;
V_10 -> V_66 . V_122 = 0 ;
}
V_10 -> V_66 . V_273 . V_125 = V_10 -> V_64 ;
memcpy ( V_10 -> V_66 . V_246 . V_272 , V_38 , 8 ) ;
V_10 -> V_154 . Type . Type = V_269 ;
if ( V_269 == V_214 ) {
switch ( V_132 ) {
case V_213 :
if ( V_386 != 0 ) {
V_10 -> V_154 . V_155 [ 1 ] = 0x01 ;
V_10 -> V_154 . V_155 [ 2 ] = V_386 ;
}
V_10 -> V_154 . V_278 = 6 ;
V_10 -> V_154 . Type . V_279 = V_280 ;
V_10 -> V_154 . Type . V_283 = V_286 ;
V_10 -> V_154 . V_276 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_213 ;
V_10 -> V_154 . V_155 [ 4 ] = V_385 & 0xFF ;
break;
case V_221 :
case V_222 :
V_10 -> V_154 . V_278 = 12 ;
V_10 -> V_154 . Type . V_279 = V_280 ;
V_10 -> V_154 . Type . V_283 = V_286 ;
V_10 -> V_154 . V_276 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_132 ;
V_10 -> V_154 . V_155 [ 6 ] = ( V_385 >> 24 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 7 ] = ( V_385 >> 16 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 8 ] = ( V_385 >> 8 ) & 0xFF ;
V_10 -> V_154 . V_155 [ 9 ] = V_385 & 0xFF ;
break;
case V_388 :
V_10 -> V_154 . V_278 = 12 ;
V_10 -> V_154 . Type . V_279 = V_280 ;
V_10 -> V_154 . Type . V_283 = V_284 ;
V_10 -> V_154 . V_276 = 0 ;
V_10 -> V_154 . V_155 [ 0 ] = V_389 ;
V_10 -> V_154 . V_155 [ 6 ] = V_390 ;
break;
case V_305 :
V_10 -> V_154 . V_278 = 6 ;
V_10 -> V_154 . Type . V_279 = V_280 ;
V_10 -> V_154 . Type . V_283 = V_288 ;
V_10 -> V_154 . V_276 = 0 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_118 , V_132 ) ;
F_112 () ;
return;
}
} else if ( V_269 == V_217 ) {
switch ( V_132 ) {
case V_216 :
V_10 -> V_154 . V_278 = 16 ;
V_10 -> V_154 . Type . Type = 1 ;
V_10 -> V_154 . Type . V_279 = V_280 ;
V_10 -> V_154 . Type . V_283 = V_288 ;
V_10 -> V_154 . V_276 = 0 ;
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
F_112 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_120 , V_269 ) ;
F_112 () ;
}
switch ( V_10 -> V_154 . Type . V_283 ) {
case V_286 :
V_387 = V_215 ;
break;
case V_284 :
V_387 = V_123 ;
break;
case V_288 :
V_387 = V_202 ;
break;
default:
V_387 = V_372 ;
}
F_85 ( V_8 -> V_15 , V_10 , V_368 , V_385 , V_387 ) ;
return;
}
static void T_13 * F_158 ( T_14 V_391 , T_14 V_385 )
{
T_14 V_392 = ( ( T_14 ) V_391 ) & V_393 ;
T_14 V_394 = ( ( T_14 ) V_391 ) - V_392 ;
void T_13 * V_395 = F_159 ( V_392 , V_394 + V_385 ) ;
return V_395 ? ( V_395 + V_394 ) : NULL ;
}
static void F_31 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
while ( ! F_34 ( & V_8 -> V_68 ) ) {
V_10 = F_160 ( V_8 -> V_68 . V_396 , struct V_9 , V_55 ) ;
if ( ( V_8 -> V_57 . V_397 ( V_8 ) ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_121 ) ;
break;
}
F_32 ( V_10 ) ;
V_8 -> V_69 -- ;
V_8 -> V_57 . V_398 ( V_8 , V_10 ) ;
F_24 ( & V_8 -> V_399 , V_10 ) ;
}
}
static inline unsigned long F_161 ( struct V_1 * V_8 )
{
return V_8 -> V_57 . V_58 ( V_8 ) ;
}
static inline bool F_162 ( struct V_1 * V_8 )
{
return V_8 -> V_57 . V_400 ( V_8 ) ;
}
static inline long F_163 ( struct V_1 * V_8 )
{
return ( V_8 -> V_57 . V_400 ( V_8 ) == 0 ) ||
( V_8 -> V_401 == 0 ) ;
}
static inline int F_164 ( struct V_1 * V_8 , T_3 V_402 ,
T_3 V_403 )
{
if ( F_27 ( V_402 >= V_8 -> V_108 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_122 , V_403 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_165 ( struct V_9 * V_10 , T_3 V_403 )
{
F_32 ( V_10 ) ;
if ( F_29 ( V_10 -> V_269 == V_270 ) )
F_75 ( V_10 ) ;
else if ( V_10 -> V_269 == V_371 )
F_166 ( V_10 -> V_206 ) ;
}
static inline T_3 F_167 ( T_3 V_404 )
{
return V_404 & V_275 ;
}
static inline T_3 F_168 ( T_3 V_404 )
{
return V_404 >> V_274 ;
}
static inline T_3 F_169 ( struct V_1 * V_8 , T_3 V_404 )
{
#define F_170 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_171 0x03
if ( F_27 ( ! ( V_8 -> V_32 & V_33 ) ) )
return V_404 & ~ F_171 ;
return V_404 & ~ F_170 ;
}
static inline T_3 F_172 ( struct V_1 * V_8 ,
T_3 V_403 )
{
T_3 V_402 ;
struct V_9 * V_10 ;
V_402 = F_168 ( V_403 ) ;
if ( F_164 ( V_8 , V_402 , V_403 ) )
return F_26 ( V_8 ) ;
V_10 = V_8 -> V_316 + V_402 ;
F_165 ( V_10 , V_403 ) ;
return F_26 ( V_8 ) ;
}
static inline T_3 F_173 ( struct V_1 * V_8 ,
T_3 V_403 )
{
T_3 V_404 ;
struct V_9 * V_10 = NULL ;
V_404 = F_169 ( V_8 , V_403 ) ;
F_174 (c, &h->cmpQ, list) {
if ( ( V_10 -> V_64 & 0xFFFFFFE0 ) == ( V_404 & 0xFFFFFFE0 ) ) {
F_165 ( V_10 , V_403 ) ;
return F_26 ( V_8 ) ;
}
}
F_164 ( V_8 , V_8 -> V_108 + 1 , V_403 ) ;
return F_26 ( V_8 ) ;
}
static int F_175 ( struct V_1 * V_8 )
{
if ( F_29 ( ! V_405 ) )
return 0 ;
if ( F_29 ( V_8 -> V_401 ) )
return 0 ;
F_44 ( & V_8 -> V_15 -> V_16 , L_123
L_124 ) ;
return 1 ;
}
static T_15 F_176 ( int V_191 , void * V_406 )
{
struct V_1 * V_8 = V_406 ;
unsigned long V_43 ;
T_3 V_403 ;
if ( F_175 ( V_8 ) )
return V_407 ;
if ( F_163 ( V_8 ) )
return V_407 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
while ( F_162 ( V_8 ) ) {
V_403 = F_161 ( V_8 ) ;
while ( V_403 != V_61 )
V_403 = F_26 ( V_8 ) ;
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_408 ;
}
static T_15 F_177 ( int V_191 , void * V_406 )
{
struct V_1 * V_8 = V_406 ;
unsigned long V_43 ;
T_3 V_403 ;
if ( F_175 ( V_8 ) )
return V_407 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_403 = F_161 ( V_8 ) ;
while ( V_403 != V_61 )
V_403 = F_26 ( V_8 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_408 ;
}
static T_15 F_178 ( int V_191 , void * V_406 )
{
struct V_1 * V_8 = V_406 ;
unsigned long V_43 ;
T_3 V_403 ;
if ( F_163 ( V_8 ) )
return V_407 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
while ( F_162 ( V_8 ) ) {
V_403 = F_161 ( V_8 ) ;
while ( V_403 != V_61 ) {
if ( F_167 ( V_403 ) )
V_403 = F_172 ( V_8 , V_403 ) ;
else
V_403 = F_173 ( V_8 , V_403 ) ;
}
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_408 ;
}
static T_15 F_179 ( int V_191 , void * V_406 )
{
struct V_1 * V_8 = V_406 ;
unsigned long V_43 ;
T_3 V_403 ;
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_403 = F_161 ( V_8 ) ;
while ( V_403 != V_61 ) {
if ( F_167 ( V_403 ) )
V_403 = F_172 ( V_8 , V_403 ) ;
else
V_403 = F_173 ( V_8 , V_403 ) ;
}
F_21 ( & V_8 -> V_44 , V_43 ) ;
return V_408 ;
}
static T_12 int F_180 ( struct V_196 * V_15 , unsigned char V_409 ,
unsigned char type )
{
struct V_410 {
struct V_411 V_412 ;
struct V_413 V_154 ;
struct V_414 V_415 ;
};
struct V_410 * V_132 ;
static const T_2 V_416 = sizeof( * V_132 ) +
sizeof( V_132 -> V_415 ) ;
V_200 V_417 ;
T_16 V_418 , V_404 ;
void T_13 * V_419 ;
int V_35 , V_328 ;
V_419 = F_181 ( V_15 , 0 ) ;
if ( V_419 == NULL )
return - V_110 ;
V_328 = F_182 ( V_15 , F_183 ( 32 ) ) ;
if ( V_328 ) {
F_184 ( V_419 ) ;
return - V_110 ;
}
V_132 = F_137 ( V_15 , V_416 , & V_417 ) ;
if ( V_132 == NULL ) {
F_184 ( V_419 ) ;
return - V_110 ;
}
V_418 = V_417 ;
V_132 -> V_412 . V_271 = 0 ;
V_132 -> V_412 . V_67 = 0 ;
V_132 -> V_412 . V_122 = 0 ;
V_132 -> V_412 . V_273 . V_125 = V_418 ;
V_132 -> V_412 . V_273 . V_126 = 0 ;
memset ( & V_132 -> V_412 . V_246 . V_272 , 0 , 8 ) ;
V_132 -> V_154 . V_278 = 16 ;
V_132 -> V_154 . Type . Type = V_217 ;
V_132 -> V_154 . Type . V_279 = V_420 ;
V_132 -> V_154 . Type . V_283 = V_288 ;
V_132 -> V_154 . V_276 = 0 ;
V_132 -> V_154 . V_155 [ 0 ] = V_409 ;
V_132 -> V_154 . V_155 [ 1 ] = type ;
memset ( & V_132 -> V_154 . V_155 [ 2 ] , 0 , 14 ) ;
V_132 -> V_415 . V_124 . V_125 = V_418 + sizeof( * V_132 ) ;
V_132 -> V_415 . V_124 . V_126 = 0 ;
V_132 -> V_415 . V_121 = sizeof( struct V_133 ) ;
F_185 ( V_418 , V_419 + V_421 ) ;
for ( V_35 = 0 ; V_35 < V_422 ; V_35 ++ ) {
V_404 = F_186 ( V_419 + V_423 ) ;
if ( ( V_404 & ~ F_171 ) == V_418 )
break;
F_132 ( V_424 ) ;
}
F_184 ( V_419 ) ;
if ( V_35 == V_422 ) {
F_43 ( & V_15 -> V_16 , L_125 ,
V_409 , type ) ;
return - V_425 ;
}
F_138 ( V_15 , V_416 , V_132 , V_417 ) ;
if ( V_404 & V_426 ) {
F_43 ( & V_15 -> V_16 , L_126 ,
V_409 , type ) ;
return - V_427 ;
}
F_44 ( & V_15 -> V_16 , L_127 ,
V_409 , type ) ;
return 0 ;
}
static int F_187 ( struct V_196 * V_15 ,
void * T_13 V_419 , T_3 V_428 )
{
V_204 V_429 ;
int V_430 ;
if ( V_428 ) {
F_44 ( & V_15 -> V_16 , L_128 ) ;
F_185 ( V_428 , V_419 + V_431 ) ;
} else {
V_430 = F_188 ( V_15 , V_432 ) ;
if ( V_430 == 0 ) {
F_43 ( & V_15 -> V_16 ,
L_129
L_130 ) ;
return - V_46 ;
}
F_44 ( & V_15 -> V_16 , L_131 ) ;
F_189 ( V_15 , V_430 + V_433 , & V_429 ) ;
V_429 &= ~ V_434 ;
V_429 |= V_435 ;
F_190 ( V_15 , V_430 + V_433 , V_429 ) ;
F_132 ( 500 ) ;
V_429 &= ~ V_434 ;
V_429 |= V_436 ;
F_190 ( V_15 , V_430 + V_433 , V_429 ) ;
}
return 0 ;
}
static T_12 void F_191 ( char * V_437 , int V_258 )
{
memset ( V_437 , 0 , V_258 ) ;
strncpy ( V_437 , L_132 V_366 , V_258 - 1 ) ;
}
static T_12 int F_192 (
struct V_438 T_13 * V_439 )
{
char * V_437 ;
int V_35 , V_385 = sizeof( V_439 -> V_437 ) ;
V_437 = F_70 ( V_385 , V_104 ) ;
if ( ! V_437 )
return - V_110 ;
F_191 ( V_437 , V_385 ) ;
for ( V_35 = 0 ; V_35 < V_385 ; V_35 ++ )
F_193 ( V_437 [ V_35 ] , & V_439 -> V_437 [ V_35 ] ) ;
F_50 ( V_437 ) ;
return 0 ;
}
static T_12 void F_194 (
struct V_438 T_13 * V_439 , unsigned char * V_440 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < sizeof( V_439 -> V_437 ) ; V_35 ++ )
V_440 [ V_35 ] = F_195 ( & V_439 -> V_437 [ V_35 ] ) ;
}
static T_12 int F_196 (
struct V_438 T_13 * V_439 )
{
char * V_440 , * V_441 ;
int V_211 , V_385 = sizeof( V_439 -> V_437 ) ;
V_441 = F_70 ( 2 * V_385 , V_104 ) ;
if ( ! V_441 )
return - V_110 ;
V_440 = V_441 + V_385 ;
F_191 ( V_441 , V_385 ) ;
F_194 ( V_439 , V_440 ) ;
V_211 = ! memcmp ( V_440 , V_441 , V_385 ) ;
F_50 ( V_441 ) ;
return V_211 ;
}
static T_12 int F_197 ( struct V_196 * V_15 )
{
T_4 V_442 ;
T_3 V_443 ;
T_4 V_444 ;
void T_13 * V_419 ;
unsigned long V_445 ;
T_3 V_446 ;
int V_211 ;
struct V_438 T_13 * V_439 ;
T_3 V_428 ;
T_3 V_34 ;
V_204 V_447 ;
V_211 = F_198 ( V_15 , & V_34 ) ;
if ( V_211 < 0 || ! F_15 ( V_34 ) ) {
F_5 ( & V_15 -> V_16 , L_133 ) ;
return - V_46 ;
}
if ( ! F_12 ( V_34 ) )
return - V_298 ;
F_189 ( V_15 , 4 , & V_447 ) ;
F_199 ( V_15 ) ;
F_200 ( V_15 ) ;
V_211 = F_201 ( V_15 , & V_445 ) ;
if ( V_211 )
return V_211 ;
V_419 = F_158 ( V_445 , 0x250 ) ;
if ( ! V_419 )
return - V_110 ;
V_211 = F_202 ( V_15 , V_419 , & V_443 ,
& V_444 , & V_442 ) ;
if ( V_211 )
goto V_448;
V_439 = F_158 ( F_203 ( V_15 ,
V_444 ) + V_442 , sizeof( * V_439 ) ) ;
if ( ! V_439 ) {
V_211 = - V_110 ;
goto V_448;
}
V_211 = F_192 ( V_439 ) ;
if ( V_211 )
goto V_448;
V_446 = F_186 ( & V_439 -> V_446 ) ;
V_428 = V_446 & V_449 ;
if ( V_428 ) {
V_428 = V_450 ;
} else {
V_428 = V_446 & V_451 ;
if ( V_428 ) {
F_5 ( & V_15 -> V_16 , L_134
L_135
L_136
L_137 ) ;
V_211 = - V_298 ;
goto V_452;
}
}
V_211 = F_187 ( V_15 , V_419 , V_428 ) ;
if ( V_211 )
goto V_452;
F_204 ( V_15 ) ;
V_211 = F_205 ( V_15 ) ;
if ( V_211 ) {
F_5 ( & V_15 -> V_16 , L_138 ) ;
goto V_452;
}
F_190 ( V_15 , 4 , V_447 ) ;
F_132 ( V_453 ) ;
F_44 ( & V_15 -> V_16 , L_139 ) ;
V_211 = F_206 ( V_15 , V_419 , V_454 ) ;
if ( V_211 ) {
F_5 ( & V_15 -> V_16 ,
L_140
L_141 ) ;
V_211 = - V_298 ;
goto V_452;
}
V_211 = F_206 ( V_15 , V_419 , V_455 ) ;
if ( V_211 ) {
F_5 ( & V_15 -> V_16 ,
L_142
L_143 ) ;
goto V_452;
}
V_211 = F_196 ( V_419 ) ;
if ( V_211 < 0 )
goto V_452;
if ( V_211 ) {
F_5 ( & V_15 -> V_16 , L_144
L_145 ) ;
V_211 = - V_298 ;
} else {
F_44 ( & V_15 -> V_16 , L_146 ) ;
}
V_452:
F_184 ( V_439 ) ;
V_448:
F_184 ( V_419 ) ;
return V_211 ;
}
static void F_207 ( struct V_22 * V_16 , struct V_438 * V_456 )
{
#ifdef F_208
int V_35 ;
char V_457 [ 17 ] ;
F_44 ( V_16 , L_147 ) ;
F_44 ( V_16 , L_148 ) ;
for ( V_35 = 0 ; V_35 < 4 ; V_35 ++ )
V_457 [ V_35 ] = F_195 ( & ( V_456 -> V_458 [ V_35 ] ) ) ;
V_457 [ 4 ] = '\0' ;
F_44 ( V_16 , L_149 , V_457 ) ;
F_44 ( V_16 , L_150 , F_186 ( & ( V_456 -> V_459 ) ) ) ;
F_44 ( V_16 , L_151 ,
F_186 ( & ( V_456 -> V_460 ) ) ) ;
F_44 ( V_16 , L_152 ,
F_186 ( & ( V_456 -> V_461 ) ) ) ;
F_44 ( V_16 , L_153 ,
F_186 ( & ( V_456 -> V_462 . V_463 ) ) ) ;
F_44 ( V_16 , L_154 ,
F_186 ( & ( V_456 -> V_462 . V_464 ) ) ) ;
F_44 ( V_16 , L_155 ,
F_186 ( & ( V_456 -> V_462 . V_465 ) ) ) ;
F_44 ( V_16 , L_156 ,
F_186 ( & ( V_456 -> V_466 ) ) ) ;
F_44 ( V_16 , L_157 , F_186 ( & ( V_456 -> V_467 ) ) ) ;
for ( V_35 = 0 ; V_35 < 16 ; V_35 ++ )
V_457 [ V_35 ] = F_195 ( & ( V_456 -> V_468 [ V_35 ] ) ) ;
V_457 [ 16 ] = '\0' ;
F_44 ( V_16 , L_158 , V_457 ) ;
F_44 ( V_16 , L_159 ,
F_186 ( & ( V_456 -> V_469 ) ) ) ;
#endif
}
static int F_209 ( struct V_196 * V_15 , unsigned long V_470 )
{
int V_35 , V_471 , V_472 , V_473 ;
if ( V_470 == V_474 )
return 0 ;
V_471 = 0 ;
for ( V_35 = 0 ; V_35 < V_475 ; V_35 ++ ) {
V_473 = F_210 ( V_15 , V_35 ) & V_476 ;
if ( V_473 == V_477 )
V_471 += 4 ;
else {
V_472 = F_210 ( V_15 , V_35 ) &
V_478 ;
switch ( V_472 ) {
case V_479 :
case V_480 :
V_471 += 4 ;
break;
case V_481 :
V_471 += 8 ;
break;
default:
F_5 ( & V_15 -> V_16 ,
L_160 ) ;
return - 1 ;
break;
}
}
if ( V_471 == V_470 - V_474 )
return V_35 + 1 ;
}
return - 1 ;
}
static void T_12 F_211 ( struct V_1 * V_8 )
{
#ifdef F_212
int V_328 ;
struct V_482 V_483 [ 4 ] = { { 0 , 0 } , { 0 , 1 } ,
{ 0 , 2 } , { 0 , 3 }
} ;
if ( ( V_8 -> V_34 == 0x40700E11 ) || ( V_8 -> V_34 == 0x40800E11 ) ||
( V_8 -> V_34 == 0x40820E11 ) || ( V_8 -> V_34 == 0x40830E11 ) )
goto V_484;
if ( F_188 ( V_8 -> V_15 , V_485 ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_161 ) ;
V_328 = F_213 ( V_8 -> V_15 , V_483 , 4 ) ;
if ( ! V_328 ) {
V_8 -> V_192 [ 0 ] = V_483 [ 0 ] . V_486 ;
V_8 -> V_192 [ 1 ] = V_483 [ 1 ] . V_486 ;
V_8 -> V_192 [ 2 ] = V_483 [ 2 ] . V_486 ;
V_8 -> V_192 [ 3 ] = V_483 [ 3 ] . V_486 ;
V_8 -> V_487 = 1 ;
return;
}
if ( V_328 > 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_162
L_163 , V_328 ) ;
goto V_484;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_164 ,
V_328 ) ;
goto V_484;
}
}
if ( F_188 ( V_8 -> V_15 , V_488 ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_165 ) ;
if ( ! F_214 ( V_8 -> V_15 ) )
V_8 -> V_489 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_166 ) ;
}
V_484:
#endif
V_8 -> V_192 [ V_8 -> V_193 ] = V_8 -> V_15 -> V_191 ;
}
static int T_12 F_198 ( struct V_196 * V_15 , T_3 * V_34 )
{
int V_35 ;
T_3 V_490 , V_491 ;
V_490 = V_15 -> V_492 ;
V_491 = V_15 -> V_493 ;
* V_34 = ( ( V_491 << 16 ) & 0xffff0000 ) |
V_490 ;
for ( V_35 = 0 ; V_35 < F_13 ( V_494 ) ; V_35 ++ )
if ( * V_34 == V_494 [ V_35 ] . V_34 )
return V_35 ;
if ( ( V_490 != V_495 &&
V_490 != V_496 ) ||
! V_497 ) {
F_5 ( & V_15 -> V_16 , L_167
L_168 , * V_34 ) ;
return - V_46 ;
}
return F_13 ( V_494 ) - 1 ;
}
static inline bool F_215 ( struct V_196 * V_15 )
{
V_204 V_498 ;
( void ) F_189 ( V_15 , V_499 , & V_498 ) ;
return ( ( V_498 & V_500 ) == 0 ) ;
}
static int T_12 F_201 ( struct V_196 * V_15 ,
unsigned long * V_501 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_475 ; V_35 ++ )
if ( F_210 ( V_15 , V_35 ) & V_502 ) {
* V_501 = F_203 ( V_15 , V_35 ) ;
F_216 ( & V_15 -> V_16 , L_169 ,
* V_501 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_170 ) ;
return - V_46 ;
}
static int T_12 F_206 ( struct V_196 * V_15 ,
void T_13 * V_419 , int V_503 )
{
int V_35 , V_504 ;
T_3 V_505 ;
if ( V_503 )
V_504 = V_506 ;
else
V_504 = V_507 ;
for ( V_35 = 0 ; V_35 < V_504 ; V_35 ++ ) {
V_505 = F_186 ( V_419 + V_508 ) ;
if ( V_503 ) {
if ( V_505 == V_509 )
return 0 ;
} else {
if ( V_505 != V_509 )
return 0 ;
}
F_132 ( V_510 ) ;
}
F_5 ( & V_15 -> V_16 , L_171 ) ;
return - V_46 ;
}
static int T_12 F_202 ( struct V_196 * V_15 ,
void T_13 * V_419 , T_3 * V_443 , T_4 * V_444 ,
T_4 * V_442 )
{
* V_443 = F_186 ( V_419 + V_511 ) ;
* V_442 = F_186 ( V_419 + V_512 ) ;
* V_443 &= ( T_3 ) 0x0000ffff ;
* V_444 = F_209 ( V_15 , * V_443 ) ;
if ( * V_444 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_172 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_12 F_217 ( struct V_1 * V_8 )
{
T_4 V_442 ;
T_3 V_443 ;
T_4 V_444 ;
T_3 V_513 ;
int V_211 ;
V_211 = F_202 ( V_8 -> V_15 , V_8 -> V_419 , & V_443 ,
& V_444 , & V_442 ) ;
if ( V_211 )
return V_211 ;
V_8 -> V_439 = F_158 ( F_203 ( V_8 -> V_15 ,
V_444 ) + V_442 , sizeof( * V_8 -> V_439 ) ) ;
if ( ! V_8 -> V_439 )
return - V_110 ;
V_211 = F_192 ( V_8 -> V_439 ) ;
if ( V_211 )
return V_211 ;
V_513 = F_186 ( & V_8 -> V_439 -> V_514 ) ;
V_8 -> V_515 = F_158 ( F_203 ( V_8 -> V_15 ,
V_444 ) + V_442 + V_513 ,
sizeof( * V_8 -> V_515 ) ) ;
if ( ! V_8 -> V_515 )
return - V_110 ;
return 0 ;
}
static void T_12 F_218 ( struct V_1 * V_8 )
{
V_8 -> V_63 = F_186 ( & ( V_8 -> V_439 -> V_516 ) ) ;
if ( V_405 && V_8 -> V_63 > 32 )
V_8 -> V_63 = 32 ;
if ( V_8 -> V_63 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_173
L_174
L_175 ,
V_8 -> V_63 ) ;
V_8 -> V_63 = 16 ;
}
}
static void T_12 F_219 ( struct V_1 * V_8 )
{
F_218 ( V_8 ) ;
V_8 -> V_108 = V_8 -> V_63 - 4 ;
V_8 -> V_190 = F_186 ( & ( V_8 -> V_439 -> V_517 ) ) ;
V_8 -> V_117 = 31 ;
if ( V_8 -> V_190 > 512 ) {
V_8 -> V_117 = 32 ;
V_8 -> V_109 = V_8 -> V_190 - V_8 -> V_117 + 1 ;
V_8 -> V_190 -- ;
} else {
V_8 -> V_190 = 31 ;
V_8 -> V_109 = 0 ;
}
}
static inline bool F_220 ( struct V_1 * V_8 )
{
if ( ( F_195 ( & V_8 -> V_439 -> V_458 [ 0 ] ) != 'C' ) ||
( F_195 ( & V_8 -> V_439 -> V_458 [ 1 ] ) != 'I' ) ||
( F_195 ( & V_8 -> V_439 -> V_458 [ 2 ] ) != 'S' ) ||
( F_195 ( & V_8 -> V_439 -> V_458 [ 3 ] ) != 'S' ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_176 ) ;
return false ;
}
return true ;
}
static inline void F_221 ( struct V_1 * V_8 )
{
#ifdef F_222
T_3 V_518 ;
V_518 = F_186 ( & ( V_8 -> V_439 -> V_519 ) ) ;
V_518 |= 0x100 ;
F_185 ( V_518 , & ( V_8 -> V_439 -> V_519 ) ) ;
#endif
}
static inline void F_223 ( struct V_1 * V_8 )
{
T_3 V_520 ;
if ( V_8 -> V_34 != 0x3225103C )
return;
V_520 = F_186 ( V_8 -> V_419 + V_521 ) ;
V_520 |= 0x8000 ;
F_185 ( V_520 , V_8 -> V_419 + V_521 ) ;
}
static void T_12 F_224 ( struct V_1 * V_8 )
{
int V_35 ;
T_3 V_522 ;
unsigned long V_43 ;
for ( V_35 = 0 ; V_35 < V_523 ; V_35 ++ ) {
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_522 = F_186 ( V_8 -> V_419 + V_431 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
if ( ! ( V_522 & V_524 ) )
break;
F_225 ( 10000 , 20000 ) ;
}
}
static int T_12 F_226 ( struct V_1 * V_8 )
{
T_3 V_525 ;
V_525 = F_186 ( & ( V_8 -> V_439 -> V_460 ) ) ;
if ( ! ( V_525 & V_526 ) )
return - V_298 ;
V_8 -> V_63 = F_186 ( & ( V_8 -> V_439 -> V_466 ) ) ;
F_185 ( V_527 , & ( V_8 -> V_439 -> V_462 . V_463 ) ) ;
F_185 ( V_524 , V_8 -> V_419 + V_431 ) ;
F_224 ( V_8 ) ;
F_207 ( & V_8 -> V_15 -> V_16 , V_8 -> V_439 ) ;
if ( ! ( F_186 ( & ( V_8 -> V_439 -> V_461 ) ) & V_527 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_177 ) ;
return - V_46 ;
}
V_8 -> V_32 = V_527 ;
return 0 ;
}
static int T_12 F_227 ( struct V_1 * V_8 )
{
int V_528 , V_328 ;
V_528 = F_198 ( V_8 -> V_15 , & V_8 -> V_34 ) ;
if ( V_528 < 0 )
return - V_46 ;
V_8 -> V_529 = V_494 [ V_528 ] . V_529 ;
V_8 -> V_57 = * ( V_494 [ V_528 ] . V_57 ) ;
if ( F_215 ( V_8 -> V_15 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_178 ) ;
return - V_46 ;
}
V_328 = F_205 ( V_8 -> V_15 ) ;
if ( V_328 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_179 ) ;
return V_328 ;
}
V_328 = F_228 ( V_8 -> V_15 , L_180 ) ;
if ( V_328 ) {
F_43 ( & V_8 -> V_15 -> V_16 ,
L_181 ) ;
return V_328 ;
}
F_211 ( V_8 ) ;
V_328 = F_201 ( V_8 -> V_15 , & V_8 -> V_445 ) ;
if ( V_328 )
goto V_530;
V_8 -> V_419 = F_158 ( V_8 -> V_445 , 0x250 ) ;
if ( ! V_8 -> V_419 ) {
V_328 = - V_110 ;
goto V_530;
}
V_328 = F_206 ( V_8 -> V_15 , V_8 -> V_419 , V_455 ) ;
if ( V_328 )
goto V_530;
V_328 = F_217 ( V_8 ) ;
if ( V_328 )
goto V_530;
F_219 ( V_8 ) ;
if ( ! F_220 ( V_8 ) ) {
V_328 = - V_46 ;
goto V_530;
}
F_221 ( V_8 ) ;
F_223 ( V_8 ) ;
V_328 = F_226 ( V_8 ) ;
if ( V_328 )
goto V_530;
return 0 ;
V_530:
if ( V_8 -> V_515 )
F_184 ( V_8 -> V_515 ) ;
if ( V_8 -> V_439 )
F_184 ( V_8 -> V_439 ) ;
if ( V_8 -> V_419 )
F_184 ( V_8 -> V_419 ) ;
F_229 ( V_8 -> V_15 ) ;
return V_328 ;
}
static void T_12 F_230 ( struct V_1 * V_8 )
{
int V_211 ;
#define F_231 64
V_8 -> V_30 = F_70 ( F_231 , V_104 ) ;
if ( ! V_8 -> V_30 )
return;
V_211 = F_91 ( V_8 , V_70 , 0 ,
V_8 -> V_30 , F_231 ) ;
if ( V_211 != 0 ) {
F_50 ( V_8 -> V_30 ) ;
V_8 -> V_30 = NULL ;
}
}
static T_12 int F_232 ( struct V_196 * V_15 )
{
int V_211 , V_35 ;
if ( ! V_405 )
return 0 ;
V_211 = F_197 ( V_15 ) ;
if ( V_211 == - V_298 )
return V_211 ;
if ( V_211 )
return - V_46 ;
F_5 ( & V_15 -> V_16 , L_182 ) ;
for ( V_35 = 0 ; V_35 < V_531 ; V_35 ++ ) {
if ( F_233 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_183 ,
( V_35 < 11 ? L_184 : L_185 ) ) ;
}
return 0 ;
}
static T_12 int F_234 ( struct V_1 * V_8 )
{
V_8 -> V_314 = F_58 (
F_235 ( V_8 -> V_108 , V_315 ) *
sizeof( unsigned long ) , V_104 ) ;
V_8 -> V_316 = F_137 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( * V_8 -> V_316 ) ,
& ( V_8 -> V_317 ) ) ;
V_8 -> V_318 = F_137 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( * V_8 -> V_318 ) ,
& ( V_8 -> V_319 ) ) ;
if ( ( V_8 -> V_314 == NULL )
|| ( V_8 -> V_316 == NULL )
|| ( V_8 -> V_318 == NULL ) ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_186 , V_532 ) ;
return - V_110 ;
}
return 0 ;
}
static void F_236 ( struct V_1 * V_8 )
{
F_50 ( V_8 -> V_314 ) ;
if ( V_8 -> V_316 )
F_138 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_9 ) ,
V_8 -> V_316 , V_8 -> V_317 ) ;
if ( V_8 -> V_318 )
F_138 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_133 ) ,
V_8 -> V_318 ,
V_8 -> V_319 ) ;
}
static int F_237 ( struct V_1 * V_8 ,
T_15 (* F_238)( int , void * ) ,
T_15 (* F_239)( int , void * ) )
{
int V_211 ;
if ( V_8 -> V_487 || V_8 -> V_489 )
V_211 = F_240 ( V_8 -> V_192 [ V_8 -> V_193 ] , F_238 ,
V_533 , V_8 -> V_534 , V_8 ) ;
else
V_211 = F_240 ( V_8 -> V_192 [ V_8 -> V_193 ] , F_239 ,
V_533 , V_8 -> V_534 , V_8 ) ;
if ( V_211 ) {
F_43 ( & V_8 -> V_15 -> V_16 , L_187 ,
V_8 -> V_192 [ V_8 -> V_193 ] , V_8 -> V_534 ) ;
return - V_46 ;
}
return 0 ;
}
static int T_12 F_241 ( struct V_1 * V_8 )
{
if ( F_157 ( V_8 , V_70 ,
V_535 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_188 ) ;
return - V_427 ;
}
F_44 ( & V_8 -> V_15 -> V_16 , L_189 ) ;
if ( F_206 ( V_8 -> V_15 , V_8 -> V_419 , V_454 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_190 ) ;
return - 1 ;
}
F_44 ( & V_8 -> V_15 -> V_16 , L_191 ) ;
if ( F_206 ( V_8 -> V_15 , V_8 -> V_419 , V_455 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_192
L_193 ) ;
return - 1 ;
}
return 0 ;
}
static void F_242 ( struct V_1 * V_8 )
{
F_243 ( V_8 -> V_192 [ V_8 -> V_193 ] , V_8 ) ;
#ifdef F_212
if ( V_8 -> V_487 )
F_244 ( V_8 -> V_15 ) ;
else if ( V_8 -> V_489 )
F_245 ( V_8 -> V_15 ) ;
#endif
F_68 ( V_8 ) ;
F_236 ( V_8 ) ;
F_50 ( V_8 -> V_65 ) ;
F_138 ( V_8 -> V_15 , V_8 -> V_536 ,
V_8 -> V_62 , V_8 -> V_537 ) ;
if ( V_8 -> V_419 )
F_184 ( V_8 -> V_419 ) ;
if ( V_8 -> V_515 )
F_184 ( V_8 -> V_515 ) ;
if ( V_8 -> V_439 )
F_184 ( V_8 -> V_439 ) ;
F_229 ( V_8 -> V_15 ) ;
F_50 ( V_8 ) ;
}
static int T_12 F_246 ( struct V_196 * V_15 ,
const struct V_538 * V_539 )
{
int V_540 , V_211 ;
struct V_1 * V_8 ;
int V_541 = 0 ;
unsigned long V_43 ;
if ( V_542 == 0 )
F_247 (KERN_INFO DRIVER_NAME L_194 ) ;
V_211 = F_232 ( V_15 ) ;
if ( V_211 ) {
if ( V_211 != - V_298 )
return V_211 ;
V_541 = 1 ;
V_211 = 0 ;
}
V_543:
#define F_248 32
F_249 ( sizeof( struct V_9 ) % F_248 ) ;
V_8 = F_58 ( sizeof( * V_8 ) , V_104 ) ;
if ( ! V_8 )
return - V_110 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_544 = 1 ;
V_8 -> V_193 = V_545 ? V_546 : V_547 ;
F_136 ( & V_8 -> V_399 ) ;
F_136 ( & V_8 -> V_68 ) ;
F_250 ( & V_8 -> V_44 ) ;
F_250 ( & V_8 -> V_293 ) ;
V_211 = F_227 ( V_8 ) ;
if ( V_211 != 0 )
goto V_548;
sprintf ( V_8 -> V_534 , L_195 , V_542 ) ;
V_8 -> V_17 = V_542 ;
V_542 ++ ;
V_211 = F_251 ( V_15 , F_183 ( 64 ) ) ;
if ( V_211 == 0 ) {
V_540 = 1 ;
} else {
V_211 = F_251 ( V_15 , F_183 ( 32 ) ) ;
if ( V_211 == 0 ) {
V_540 = 0 ;
} else {
F_43 ( & V_15 -> V_16 , L_196 ) ;
goto V_548;
}
}
V_8 -> V_57 . V_549 ( V_8 , V_550 ) ;
if ( F_237 ( V_8 , F_179 , F_178 ) )
goto V_551;
F_44 ( & V_15 -> V_16 , L_197 ,
V_8 -> V_534 , V_15 -> V_22 ,
V_8 -> V_192 [ V_8 -> V_193 ] , V_540 ? L_185 : L_198 ) ;
if ( F_234 ( V_8 ) )
goto V_552;
if ( F_69 ( V_8 ) )
goto V_552;
F_252 ( & V_8 -> V_553 ) ;
V_8 -> V_294 = 1 ;
F_253 ( V_15 , V_8 ) ;
V_8 -> V_77 = 0 ;
V_8 -> V_28 = NULL ;
F_250 ( & V_8 -> V_106 ) ;
F_254 ( V_8 ) ;
if ( V_541 ) {
F_20 ( & V_8 -> V_44 , V_43 ) ;
V_8 -> V_57 . V_549 ( V_8 , V_550 ) ;
F_21 ( & V_8 -> V_44 , V_43 ) ;
F_243 ( V_8 -> V_192 [ V_8 -> V_193 ] , V_8 ) ;
V_211 = F_237 ( V_8 , F_177 ,
F_176 ) ;
if ( V_211 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_199
L_200 ) ;
goto V_552;
}
V_211 = F_241 ( V_8 ) ;
if ( V_211 )
goto V_552;
F_44 ( & V_8 -> V_15 -> V_16 , L_201 ) ;
F_44 ( & V_8 -> V_15 -> V_16 ,
L_202 ) ;
V_8 -> V_57 . V_549 ( V_8 , V_554 ) ;
F_132 ( 10000 ) ;
V_8 -> V_57 . V_549 ( V_8 , V_550 ) ;
V_211 = F_196 ( V_8 -> V_439 ) ;
if ( V_211 )
F_44 ( & V_8 -> V_15 -> V_16 ,
L_203 ) ;
F_242 ( V_8 ) ;
V_541 = 0 ;
if ( V_211 )
return - V_46 ;
goto V_543;
}
V_8 -> V_57 . V_549 ( V_8 , V_554 ) ;
F_230 ( V_8 ) ;
F_130 ( V_8 ) ;
V_8 -> V_544 = 0 ;
return 1 ;
V_552:
F_68 ( V_8 ) ;
F_236 ( V_8 ) ;
F_243 ( V_8 -> V_192 [ V_8 -> V_193 ] , V_8 ) ;
V_551:
V_548:
V_8 -> V_544 = 0 ;
F_50 ( V_8 ) ;
return V_211 ;
}
static void F_255 ( struct V_1 * V_8 )
{
char * V_555 ;
struct V_9 * V_10 ;
V_555 = F_58 ( 4 , V_104 ) ;
if ( ! V_555 )
return;
V_10 = F_92 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88 ) ;
goto V_556;
}
F_93 ( V_10 , V_388 , V_8 , V_555 , 4 , 0 ,
V_70 , V_214 ) ;
F_89 ( V_8 , V_10 , V_123 ) ;
if ( V_10 -> V_11 -> V_148 != 0 )
F_5 ( & V_8 -> V_15 -> V_16 ,
L_204 ) ;
F_94 ( V_8 , V_10 ) ;
V_556:
F_50 ( V_555 ) ;
}
static void F_256 ( struct V_196 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_257 ( V_15 ) ;
F_255 ( V_8 ) ;
V_8 -> V_57 . V_549 ( V_8 , V_550 ) ;
F_243 ( V_8 -> V_192 [ V_8 -> V_193 ] , V_8 ) ;
#ifdef F_212
if ( V_8 -> V_487 )
F_244 ( V_8 -> V_15 ) ;
else if ( V_8 -> V_489 )
F_245 ( V_8 -> V_15 ) ;
#endif
}
static void T_17 F_258 ( struct V_196 * V_15 )
{
struct V_1 * V_8 ;
if ( F_257 ( V_15 ) == NULL ) {
F_43 ( & V_15 -> V_16 , L_205 ) ;
return;
}
V_8 = F_257 ( V_15 ) ;
F_128 ( V_8 ) ;
F_256 ( V_15 ) ;
F_184 ( V_8 -> V_419 ) ;
F_184 ( V_8 -> V_515 ) ;
F_184 ( V_8 -> V_439 ) ;
F_68 ( V_8 ) ;
F_138 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_9 ) ,
V_8 -> V_316 , V_8 -> V_317 ) ;
F_138 ( V_8 -> V_15 ,
V_8 -> V_108 * sizeof( struct V_133 ) ,
V_8 -> V_318 , V_8 -> V_319 ) ;
F_138 ( V_8 -> V_15 , V_8 -> V_536 ,
V_8 -> V_62 , V_8 -> V_537 ) ;
F_50 ( V_8 -> V_314 ) ;
F_50 ( V_8 -> V_65 ) ;
F_50 ( V_8 -> V_30 ) ;
F_229 ( V_15 ) ;
F_253 ( V_15 , NULL ) ;
F_50 ( V_8 ) ;
}
static void F_259 ( int V_557 [] , int V_558 ,
int V_559 , int * V_560 )
{
int V_35 , V_91 , V_561 , V_385 ;
#define F_260 4
#define F_261 8
for ( V_35 = 0 ; V_35 <= V_559 ; V_35 ++ ) {
V_385 = V_35 + F_260 ;
V_561 = V_558 ;
for ( V_91 = 0 ; V_91 < 8 ; V_91 ++ ) {
if ( V_557 [ V_91 ] >= V_385 ) {
V_561 = V_91 ;
break;
}
}
V_560 [ V_35 ] = V_561 ;
}
}
static T_12 void F_262 ( struct V_1 * V_8 ,
T_3 V_562 )
{
int V_35 ;
unsigned long V_563 ;
int V_564 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_381 + 4 } ;
F_249 ( 28 > V_381 + 4 ) ;
V_8 -> V_60 = 1 ;
memset ( V_8 -> V_62 , 0 , V_8 -> V_536 ) ;
V_8 -> V_59 = V_8 -> V_62 ;
V_564 [ 7 ] = V_8 -> V_565 + 4 ;
F_259 ( V_564 , F_13 ( V_564 ) , 32 , V_8 -> V_65 ) ;
for ( V_35 = 0 ; V_35 < 8 ; V_35 ++ )
F_185 ( V_564 [ V_35 ] , & V_8 -> V_515 -> V_566 [ V_35 ] ) ;
F_185 ( V_8 -> V_63 , & V_8 -> V_515 -> V_567 ) ;
F_185 ( 1 , & V_8 -> V_515 -> V_568 ) ;
F_185 ( 0 , & V_8 -> V_515 -> V_569 ) ;
F_185 ( 0 , & V_8 -> V_515 -> V_570 ) ;
F_185 ( V_8 -> V_537 , & V_8 -> V_515 -> V_571 ) ;
F_185 ( 0 , & V_8 -> V_515 -> V_572 ) ;
F_185 ( V_33 | V_562 ,
& ( V_8 -> V_439 -> V_462 . V_463 ) ) ;
F_185 ( V_524 , V_8 -> V_419 + V_431 ) ;
F_224 ( V_8 ) ;
V_563 = F_186 ( & ( V_8 -> V_439 -> V_461 ) ) ;
if ( ! ( V_563 & V_33 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_206
L_207 ) ;
return;
}
V_8 -> V_57 = V_573 ;
V_8 -> V_32 = V_33 ;
}
static T_12 void F_254 ( struct V_1 * V_8 )
{
T_3 V_525 ;
if ( V_545 )
return;
V_525 = F_186 ( & ( V_8 -> V_439 -> V_460 ) ) ;
if ( ! ( V_525 & V_574 ) )
return;
F_218 ( V_8 ) ;
V_8 -> V_565 = 32 ;
V_8 -> V_536 = V_8 -> V_63 * sizeof( T_4 ) ;
V_8 -> V_62 = F_137 ( V_8 -> V_15 , V_8 -> V_536 ,
& ( V_8 -> V_537 ) ) ;
V_8 -> V_65 = F_70 ( ( ( V_8 -> V_565 + 1 ) *
sizeof( T_3 ) ) , V_104 ) ;
if ( ( V_8 -> V_62 == NULL )
|| ( V_8 -> V_65 == NULL ) )
goto V_575;
F_262 ( V_8 ,
V_525 & V_576 ) ;
return;
V_575:
if ( V_8 -> V_62 )
F_138 ( V_8 -> V_15 , V_8 -> V_536 ,
V_8 -> V_62 , V_8 -> V_537 ) ;
F_50 ( V_8 -> V_65 ) ;
}
static int T_18 F_263 ( void )
{
return F_264 ( & V_577 ) ;
}
static void T_19 F_265 ( void )
{
F_266 ( & V_577 ) ;
}

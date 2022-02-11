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
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_1
L_2 , V_8 -> V_18 ) ;
break;
case V_19 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_3
L_4 , V_8 -> V_18 ) ;
break;
case V_20 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_5
L_6 , V_8 -> V_18 ) ;
break;
case V_21 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_7
L_8 , V_8 -> V_18 ) ;
break;
case V_22 :
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_9
L_10 , V_8 -> V_18 ) ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , V_17 L_11
L_12 , V_8 -> V_18 ) ;
break;
}
return 1 ;
}
static T_1 F_6 ( struct V_23 * V_16 ,
struct V_24 * V_25 ,
const char * V_26 , T_2 V_27 )
{
struct V_1 * V_8 ;
struct V_6 * V_28 = F_7 ( V_16 ) ;
V_8 = F_3 ( V_28 ) ;
F_8 ( V_8 -> V_29 ) ;
return V_27 ;
}
static T_1 F_9 ( struct V_23 * V_16 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_1 * V_8 ;
struct V_6 * V_28 = F_7 ( V_16 ) ;
unsigned char * V_30 ;
V_8 = F_3 ( V_28 ) ;
if ( ! V_8 -> V_31 )
return 0 ;
V_30 = & V_8 -> V_31 [ 32 ] ;
return snprintf ( V_26 , 20 , L_13 ,
V_30 [ 0 ] , V_30 [ 1 ] , V_30 [ 2 ] , V_30 [ 3 ] ) ;
}
static T_1 F_10 ( struct V_23 * V_16 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_6 * V_28 = F_7 ( V_16 ) ;
struct V_1 * V_8 = F_3 ( V_28 ) ;
return snprintf ( V_26 , 20 , L_14 , V_8 -> V_32 ) ;
}
static T_1 F_11 ( struct V_23 * V_16 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_1 * V_8 ;
struct V_6 * V_28 = F_7 ( V_16 ) ;
V_8 = F_3 ( V_28 ) ;
return snprintf ( V_26 , 20 , L_15 ,
V_8 -> V_33 & V_34 ?
L_16 : L_17 ) ;
}
static int F_12 ( T_3 V_35 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < F_13 ( V_37 ) ; V_36 ++ )
if ( V_37 [ V_36 ] == V_35 )
return 0 ;
return 1 ;
}
static int F_14 ( T_3 V_35 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < F_13 ( V_38 ) ; V_36 ++ )
if ( V_38 [ V_36 ] == V_35 )
return 0 ;
return 1 ;
}
static int F_15 ( T_3 V_35 )
{
return F_12 ( V_35 ) ||
F_14 ( V_35 ) ;
}
static T_1 F_16 ( struct V_23 * V_16 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_1 * V_8 ;
struct V_6 * V_28 = F_7 ( V_16 ) ;
V_8 = F_3 ( V_28 ) ;
return snprintf ( V_26 , 20 , L_14 , F_15 ( V_8 -> V_35 ) ) ;
}
static inline int F_17 ( unsigned char V_39 [] )
{
return ( V_39 [ 3 ] & 0xC0 ) == 0x40 ;
}
static T_1 F_18 ( struct V_23 * V_16 ,
struct V_24 * V_25 , char * V_26 )
{
T_1 V_40 = 0 ;
unsigned char V_41 ;
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_42 * V_43 ;
unsigned long V_44 ;
V_3 = F_19 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_43 = V_3 -> V_46 ;
if ( ! V_43 ) {
F_21 ( & V_8 -> V_45 , V_44 ) ;
return - V_47 ;
}
if ( ! F_17 ( V_43 -> V_39 ) ) {
F_21 ( & V_8 -> V_45 , V_44 ) ;
V_40 = snprintf ( V_26 , V_48 , L_18 ) ;
return V_40 ;
}
V_41 = V_43 -> V_49 ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
if ( V_41 > V_50 )
V_41 = V_50 ;
V_40 = snprintf ( V_26 , V_48 , L_19 , V_51 [ V_41 ] ) ;
return V_40 ;
}
static T_1 F_22 ( struct V_23 * V_16 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_42 * V_43 ;
unsigned long V_44 ;
unsigned char V_52 [ 8 ] ;
V_3 = F_19 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_43 = V_3 -> V_46 ;
if ( ! V_43 ) {
F_21 ( & V_8 -> V_45 , V_44 ) ;
return - V_47 ;
}
memcpy ( V_52 , V_43 -> V_39 , sizeof( V_52 ) ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
return snprintf ( V_26 , 20 , L_20 ,
V_52 [ 0 ] , V_52 [ 1 ] , V_52 [ 2 ] , V_52 [ 3 ] ,
V_52 [ 4 ] , V_52 [ 5 ] , V_52 [ 6 ] , V_52 [ 7 ] ) ;
}
static T_1 F_23 ( struct V_23 * V_16 ,
struct V_24 * V_25 , char * V_26 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_42 * V_43 ;
unsigned long V_44 ;
unsigned char V_53 [ 16 ] ;
V_3 = F_19 ( V_16 ) ;
V_8 = F_1 ( V_3 ) ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_43 = V_3 -> V_46 ;
if ( ! V_43 ) {
F_21 ( & V_8 -> V_45 , V_44 ) ;
return - V_47 ;
}
memcpy ( V_53 , V_43 -> V_54 , sizeof( V_53 ) ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
return snprintf ( V_26 , 16 * 2 + 2 ,
L_21
L_22 ,
V_53 [ 0 ] , V_53 [ 1 ] , V_53 [ 2 ] , V_53 [ 3 ] ,
V_53 [ 4 ] , V_53 [ 5 ] , V_53 [ 6 ] , V_53 [ 7 ] ,
V_53 [ 8 ] , V_53 [ 9 ] , V_53 [ 10 ] , V_53 [ 11 ] ,
V_53 [ 12 ] , V_53 [ 13 ] , V_53 [ 14 ] , V_53 [ 15 ] ) ;
}
static inline void F_24 ( struct V_55 * V_56 , struct V_9 * V_10 )
{
F_25 ( & V_10 -> V_56 , V_56 ) ;
}
static inline T_3 F_26 ( struct V_1 * V_8 )
{
T_3 V_57 ;
if ( F_27 ( ! ( V_8 -> V_33 & V_34 ) ) )
return V_8 -> V_58 . V_59 ( V_8 ) ;
if ( ( * ( V_8 -> V_60 ) & 1 ) == ( V_8 -> V_61 ) ) {
V_57 = * ( V_8 -> V_60 ) ;
( V_8 -> V_60 ) ++ ;
V_8 -> V_32 -- ;
} else {
V_57 = V_62 ;
}
if ( V_8 -> V_60 == ( V_8 -> V_63 + V_8 -> V_64 ) ) {
V_8 -> V_60 = V_8 -> V_63 ;
V_8 -> V_61 ^= 1 ;
}
return V_57 ;
}
static void F_28 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
if ( F_29 ( V_8 -> V_33 & V_34 ) )
V_10 -> V_65 |= 1 | ( V_8 -> V_66 [ V_10 -> V_67 . V_68 ] << 1 ) ;
}
static void F_30 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_44 ;
F_28 ( V_8 , V_10 ) ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
F_24 ( & V_8 -> V_69 , V_10 ) ;
V_8 -> V_70 ++ ;
F_31 ( V_8 ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
}
static inline void F_32 ( struct V_9 * V_10 )
{
if ( F_33 ( F_34 ( & V_10 -> V_56 ) ) )
return;
F_35 ( & V_10 -> V_56 ) ;
}
static inline int F_36 ( unsigned char V_39 [] )
{
return memcmp ( V_39 , V_71 , 8 ) == 0 ;
}
static inline int F_37 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_31 )
return 0 ;
if ( ( V_8 -> V_31 [ 2 ] & 0x07 ) == 5 )
return 1 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_8 ,
unsigned char V_39 [] , int V_72 , int * V_73 , int * V_74 )
{
int V_36 , V_75 = 0 ;
F_39 ( V_76 , V_77 ) ;
F_40 ( V_76 , V_77 ) ;
for ( V_36 = 0 ; V_36 < V_8 -> V_78 ; V_36 ++ ) {
if ( V_8 -> V_16 [ V_36 ] -> V_72 == V_72 && V_8 -> V_16 [ V_36 ] -> V_73 != - 1 )
F_41 ( V_8 -> V_16 [ V_36 ] -> V_73 , V_76 ) ;
}
V_36 = F_42 ( V_76 , V_77 ) ;
if ( V_36 < V_77 ) {
* V_73 = V_36 ;
* V_74 = 0 ;
V_75 = 1 ;
}
return ! V_75 ;
}
static int F_43 ( struct V_1 * V_8 , int V_79 ,
struct V_42 * V_23 ,
struct V_42 * V_80 [] , int * V_81 )
{
int V_82 = V_8 -> V_78 ;
int V_36 ;
unsigned char V_83 [ 8 ] , V_84 [ 8 ] ;
struct V_42 * V_85 ;
if ( V_82 >= V_77 ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_23
L_24 ) ;
return - 1 ;
}
if ( V_23 -> V_74 != - 1 )
goto V_86;
if ( V_23 -> V_39 [ 4 ] == 0 ) {
if ( F_38 ( V_8 , V_23 -> V_39 ,
V_23 -> V_72 , & V_23 -> V_73 , & V_23 -> V_74 ) != 0 )
return - 1 ;
goto V_86;
}
memcpy ( V_83 , V_23 -> V_39 , 8 ) ;
V_83 [ 4 ] = 0 ;
for ( V_36 = 0 ; V_36 < V_82 ; V_36 ++ ) {
V_85 = V_8 -> V_16 [ V_36 ] ;
memcpy ( V_84 , V_85 -> V_39 , 8 ) ;
V_84 [ 4 ] = 0 ;
if ( memcmp ( V_83 , V_84 , 8 ) == 0 ) {
V_23 -> V_72 = V_85 -> V_72 ;
V_23 -> V_73 = V_85 -> V_73 ;
V_23 -> V_74 = V_23 -> V_39 [ 4 ] ;
break;
}
}
if ( V_23 -> V_74 == - 1 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_25
L_26
L_27 ) ;
return - 1 ;
}
V_86:
V_8 -> V_16 [ V_82 ] = V_23 ;
V_8 -> V_78 ++ ;
V_80 [ * V_81 ] = V_23 ;
( * V_81 ) ++ ;
F_45 ( & V_8 -> V_15 -> V_16 , L_28 ,
F_46 ( V_23 -> V_87 ) , V_79 ,
V_23 -> V_72 , V_23 -> V_73 , V_23 -> V_74 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_8 , int V_79 ,
int V_88 , struct V_42 * V_89 )
{
F_48 ( V_88 < 0 || V_88 >= V_77 ) ;
V_8 -> V_16 [ V_88 ] -> V_49 = V_89 -> V_49 ;
F_45 ( & V_8 -> V_15 -> V_16 , L_29 ,
F_46 ( V_89 -> V_87 ) , V_79 , V_89 -> V_72 ,
V_89 -> V_73 , V_89 -> V_74 ) ;
}
static void F_49 ( struct V_1 * V_8 , int V_79 ,
int V_88 , struct V_42 * V_89 ,
struct V_42 * V_80 [] , int * V_81 ,
struct V_42 * V_90 [] , int * V_91 )
{
F_48 ( V_88 < 0 || V_88 >= V_77 ) ;
V_90 [ * V_91 ] = V_8 -> V_16 [ V_88 ] ;
( * V_91 ) ++ ;
if ( V_89 -> V_73 == - 1 ) {
V_89 -> V_73 = V_8 -> V_16 [ V_88 ] -> V_73 ;
V_89 -> V_74 = V_8 -> V_16 [ V_88 ] -> V_74 ;
}
V_8 -> V_16 [ V_88 ] = V_89 ;
V_80 [ * V_81 ] = V_89 ;
( * V_81 ) ++ ;
F_45 ( & V_8 -> V_15 -> V_16 , L_30 ,
F_46 ( V_89 -> V_87 ) , V_79 , V_89 -> V_72 ,
V_89 -> V_73 , V_89 -> V_74 ) ;
}
static void F_50 ( struct V_1 * V_8 , int V_79 , int V_88 ,
struct V_42 * V_90 [] , int * V_91 )
{
int V_36 ;
struct V_42 * V_85 ;
F_48 ( V_88 < 0 || V_88 >= V_77 ) ;
V_85 = V_8 -> V_16 [ V_88 ] ;
V_90 [ * V_91 ] = V_8 -> V_16 [ V_88 ] ;
( * V_91 ) ++ ;
for ( V_36 = V_88 ; V_36 < V_8 -> V_78 - 1 ; V_36 ++ )
V_8 -> V_16 [ V_36 ] = V_8 -> V_16 [ V_36 + 1 ] ;
V_8 -> V_78 -- ;
F_45 ( & V_8 -> V_15 -> V_16 , L_31 ,
F_46 ( V_85 -> V_87 ) , V_79 , V_85 -> V_72 , V_85 -> V_73 ,
V_85 -> V_74 ) ;
}
static void F_51 ( struct V_1 * V_8 ,
struct V_42 * V_80 )
{
unsigned long V_44 ;
int V_36 , V_92 ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
for ( V_36 = 0 ; V_36 < V_8 -> V_78 ; V_36 ++ ) {
if ( V_8 -> V_16 [ V_36 ] == V_80 ) {
for ( V_92 = V_36 ; V_92 < V_8 -> V_78 - 1 ; V_92 ++ )
V_8 -> V_16 [ V_92 ] = V_8 -> V_16 [ V_92 + 1 ] ;
V_8 -> V_78 -- ;
break;
}
}
F_21 ( & V_8 -> V_45 , V_44 ) ;
F_52 ( V_80 ) ;
}
static inline int F_53 ( struct V_42 * V_93 ,
struct V_42 * V_94 )
{
if ( memcmp ( V_93 -> V_39 , V_94 -> V_39 ,
sizeof( V_93 -> V_39 ) ) != 0 )
return 0 ;
if ( memcmp ( V_93 -> V_54 , V_94 -> V_54 ,
sizeof( V_93 -> V_54 ) ) != 0 )
return 0 ;
if ( memcmp ( V_93 -> V_95 , V_94 -> V_95 , sizeof( V_93 -> V_95 ) ) != 0 )
return 0 ;
if ( memcmp ( V_93 -> V_96 , V_94 -> V_96 , sizeof( V_93 -> V_96 ) ) != 0 )
return 0 ;
if ( V_93 -> V_87 != V_94 -> V_87 )
return 0 ;
if ( V_93 -> V_72 != V_94 -> V_72 )
return 0 ;
return 1 ;
}
static inline int F_54 ( struct V_42 * V_93 ,
struct V_42 * V_94 )
{
if ( V_93 -> V_49 != V_94 -> V_49 )
return 1 ;
return 0 ;
}
static int F_55 ( struct V_42 * V_97 ,
struct V_42 * V_98 [] , int V_99 ,
int * V_100 )
{
int V_36 ;
#define F_56 0
#define F_57 1
#define F_58 2
#define F_59 3
for ( V_36 = 0 ; V_36 < V_99 ; V_36 ++ ) {
if ( V_98 [ V_36 ] == NULL )
continue;
if ( F_60 ( V_97 -> V_39 , V_98 [ V_36 ] -> V_39 ) ) {
* V_100 = V_36 ;
if ( F_53 ( V_97 , V_98 [ V_36 ] ) ) {
if ( F_54 ( V_97 , V_98 [ V_36 ] ) )
return F_59 ;
return F_58 ;
} else {
return F_57 ;
}
}
}
* V_100 = - 1 ;
return F_56 ;
}
static void F_61 ( struct V_1 * V_8 , int V_79 ,
struct V_42 * V_85 [] , int V_101 )
{
int V_36 , V_88 , V_102 , V_103 = 0 ;
struct V_42 * V_104 ;
unsigned long V_44 ;
struct V_42 * * V_80 , * * V_90 ;
int V_81 , V_91 ;
struct V_6 * V_7 = NULL ;
V_80 = F_62 ( sizeof( * V_80 ) * V_77 , V_105 ) ;
V_90 = F_62 ( sizeof( * V_90 ) * V_77 , V_105 ) ;
if ( ! V_80 || ! V_90 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_32
L_33 ) ;
goto V_106;
}
F_20 ( & V_8 -> V_107 , V_44 ) ;
V_36 = 0 ;
V_91 = 0 ;
V_81 = 0 ;
while ( V_36 < V_8 -> V_78 ) {
V_104 = V_8 -> V_16 [ V_36 ] ;
V_102 = F_55 ( V_104 , V_85 , V_101 , & V_88 ) ;
if ( V_102 == F_56 ) {
V_103 ++ ;
F_50 ( V_8 , V_79 , V_36 ,
V_90 , & V_91 ) ;
continue;
} else if ( V_102 == F_57 ) {
V_103 ++ ;
F_49 ( V_8 , V_79 , V_36 , V_85 [ V_88 ] ,
V_80 , & V_81 , V_90 , & V_91 ) ;
V_85 [ V_88 ] = NULL ;
} else if ( V_102 == F_59 ) {
F_47 ( V_8 , V_79 , V_36 , V_85 [ V_88 ] ) ;
}
V_36 ++ ;
}
for ( V_36 = 0 ; V_36 < V_101 ; V_36 ++ ) {
if ( ! V_85 [ V_36 ] )
continue;
V_102 = F_55 ( V_85 [ V_36 ] , V_8 -> V_16 ,
V_8 -> V_78 , & V_88 ) ;
if ( V_102 == F_56 ) {
V_103 ++ ;
if ( F_43 ( V_8 , V_79 , V_85 [ V_36 ] ,
V_80 , & V_81 ) != 0 )
break;
V_85 [ V_36 ] = NULL ;
} else if ( V_102 == F_57 ) {
V_103 ++ ;
F_5 ( & V_8 -> V_15 -> V_16 ,
L_34 ) ;
}
}
F_21 ( & V_8 -> V_107 , V_44 ) ;
if ( V_79 == - 1 || ! V_103 )
goto V_106;
V_7 = V_8 -> V_29 ;
for ( V_36 = 0 ; V_36 < V_91 ; V_36 ++ ) {
struct V_2 * V_3 =
F_63 ( V_7 , V_90 [ V_36 ] -> V_72 ,
V_90 [ V_36 ] -> V_73 , V_90 [ V_36 ] -> V_74 ) ;
if ( V_3 != NULL ) {
F_64 ( V_3 ) ;
F_65 ( V_3 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_35
L_36 , V_79 , V_90 [ V_36 ] -> V_72 ,
V_90 [ V_36 ] -> V_73 , V_90 [ V_36 ] -> V_74 ) ;
}
F_52 ( V_90 [ V_36 ] ) ;
V_90 [ V_36 ] = NULL ;
}
for ( V_36 = 0 ; V_36 < V_81 ; V_36 ++ ) {
if ( F_66 ( V_7 , V_80 [ V_36 ] -> V_72 ,
V_80 [ V_36 ] -> V_73 , V_80 [ V_36 ] -> V_74 ) == 0 )
continue;
F_5 ( & V_8 -> V_15 -> V_16 , L_37
L_38 , V_79 , V_80 [ V_36 ] -> V_72 ,
V_80 [ V_36 ] -> V_73 , V_80 [ V_36 ] -> V_74 ) ;
F_51 ( V_8 , V_80 [ V_36 ] ) ;
}
V_106:
F_52 ( V_80 ) ;
F_52 ( V_90 ) ;
}
static struct V_42 * F_67 ( struct V_1 * V_8 ,
int V_72 , int V_73 , int V_74 )
{
int V_36 ;
struct V_42 * V_85 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_78 ; V_36 ++ ) {
V_85 = V_8 -> V_16 [ V_36 ] ;
if ( V_85 -> V_72 == V_72 && V_85 -> V_73 == V_73 && V_85 -> V_74 == V_74 )
return V_85 ;
}
return NULL ;
}
static int F_68 ( struct V_2 * V_3 )
{
struct V_42 * V_85 ;
unsigned long V_44 ;
struct V_1 * V_8 ;
V_8 = F_1 ( V_3 ) ;
F_20 ( & V_8 -> V_107 , V_44 ) ;
V_85 = F_67 ( V_8 , F_69 ( V_3 ) ,
F_70 ( V_3 ) , V_3 -> V_74 ) ;
if ( V_85 != NULL )
V_3 -> V_46 = V_85 ;
F_21 ( & V_8 -> V_107 , V_44 ) ;
return 0 ;
}
static void F_71 ( struct V_2 * V_3 )
{
}
static void F_72 ( struct V_1 * V_8 )
{
int V_36 ;
if ( ! V_8 -> V_108 )
return;
for ( V_36 = 0 ; V_36 < V_8 -> V_109 ; V_36 ++ ) {
F_52 ( V_8 -> V_108 [ V_36 ] ) ;
V_8 -> V_108 [ V_36 ] = NULL ;
}
F_52 ( V_8 -> V_108 ) ;
V_8 -> V_108 = NULL ;
}
static int F_73 ( struct V_1 * V_8 )
{
int V_36 ;
if ( V_8 -> V_110 <= 0 )
return 0 ;
V_8 -> V_108 = F_62 ( sizeof( * V_8 -> V_108 ) * V_8 -> V_109 ,
V_105 ) ;
if ( ! V_8 -> V_108 )
return - V_111 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_109 ; V_36 ++ ) {
V_8 -> V_108 [ V_36 ] = F_74 ( sizeof( * V_8 -> V_108 [ V_36 ] ) *
V_8 -> V_110 , V_105 ) ;
if ( ! V_8 -> V_108 [ V_36 ] )
goto V_112;
}
return 0 ;
V_112:
F_72 ( V_8 ) ;
return - V_111 ;
}
static void F_75 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_113 * V_114 , * V_115 ;
T_4 V_116 ;
V_114 = & V_10 -> V_117 [ V_8 -> V_118 - 1 ] ;
V_115 = V_8 -> V_108 [ V_10 -> V_119 ] ;
V_114 -> V_120 = V_121 ;
V_114 -> V_122 = sizeof( * V_114 ) *
( V_10 -> V_67 . V_123 - V_8 -> V_118 ) ;
V_116 = F_76 ( V_8 -> V_15 , V_115 , V_114 -> V_122 ,
V_124 ) ;
V_114 -> V_125 . V_126 = ( T_3 ) ( V_116 & 0x0FFFFFFFFULL ) ;
V_114 -> V_125 . V_127 = ( T_3 ) ( ( V_116 >> 32 ) & 0x0FFFFFFFFULL ) ;
}
static void F_77 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
struct V_113 * V_114 ;
union V_128 V_116 ;
if ( V_10 -> V_67 . V_123 <= V_8 -> V_118 )
return;
V_114 = & V_10 -> V_117 [ V_8 -> V_118 - 1 ] ;
V_116 . V_129 . V_126 = V_114 -> V_125 . V_126 ;
V_116 . V_129 . V_127 = V_114 -> V_125 . V_127 ;
F_78 ( V_8 -> V_15 , V_116 . V_130 , V_114 -> V_122 , V_124 ) ;
}
static void F_79 ( struct V_9 * V_131 )
{
struct V_132 * V_133 ;
struct V_1 * V_8 ;
struct V_134 * V_135 ;
unsigned char V_136 ;
unsigned char V_137 ;
unsigned char V_138 ;
unsigned long V_139 ;
V_135 = V_131 -> V_11 ;
V_133 = (struct V_132 * ) V_131 -> V_140 ;
V_8 = V_131 -> V_8 ;
F_80 ( V_133 ) ;
if ( V_131 -> V_67 . V_123 > V_8 -> V_118 )
F_77 ( V_8 , V_131 ) ;
V_133 -> V_141 = ( V_142 << 16 ) ;
V_133 -> V_141 |= ( V_143 << 8 ) ;
V_133 -> V_141 |= V_135 -> V_144 ;
if ( V_145 < sizeof( V_135 -> V_12 ) )
V_139 = V_145 ;
else
V_139 = sizeof( V_135 -> V_12 ) ;
if ( V_135 -> V_146 < V_139 )
V_139 = V_135 -> V_146 ;
memcpy ( V_133 -> V_147 , V_135 -> V_12 , V_139 ) ;
F_81 ( V_133 , V_135 -> V_148 ) ;
if ( V_135 -> V_149 == 0 ) {
V_133 -> V_150 ( V_133 ) ;
F_82 ( V_8 , V_131 ) ;
return;
}
switch ( V_135 -> V_149 ) {
case V_151 :
if ( V_135 -> V_144 ) {
V_136 = 0xf & V_135 -> V_12 [ 2 ] ;
V_137 = V_135 -> V_12 [ 12 ] ;
V_138 = V_135 -> V_12 [ 13 ] ;
}
if ( V_135 -> V_144 == V_152 ) {
if ( F_4 ( V_8 , V_131 ) ) {
V_133 -> V_141 = V_153 << 16 ;
break;
}
if ( V_136 == V_154 ) {
if ( V_131 -> V_155 . V_156 [ 0 ] == V_157 )
break;
if ( ( V_137 == 0x25 ) && ( V_138 == 0x0 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_39
L_40 , V_131 ) ;
break;
}
}
if ( V_136 == V_158 ) {
if ( ( V_137 == 0x04 ) && ( V_138 == 0x03 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_39
L_41
L_42
L_43 , V_131 ) ;
break;
}
}
if ( V_136 == V_159 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_39
L_44
L_45 ,
V_131 , V_137 , V_138 ) ;
V_133 -> V_141 = V_153 << 16 ;
break;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_46
L_47
L_48
L_49
L_50
L_51
L_52 ,
V_131 , V_136 , V_137 , V_138 ,
V_133 -> V_141 ,
V_133 -> V_160 [ 0 ] , V_133 -> V_160 [ 1 ] ,
V_133 -> V_160 [ 2 ] , V_133 -> V_160 [ 3 ] ,
V_133 -> V_160 [ 4 ] , V_133 -> V_160 [ 5 ] ,
V_133 -> V_160 [ 6 ] , V_133 -> V_160 [ 7 ] ,
V_133 -> V_160 [ 8 ] , V_133 -> V_160 [ 9 ] ,
V_133 -> V_160 [ 10 ] , V_133 -> V_160 [ 11 ] ,
V_133 -> V_160 [ 12 ] , V_133 -> V_160 [ 13 ] ,
V_133 -> V_160 [ 14 ] , V_133 -> V_160 [ 15 ] ) ;
break;
}
if ( V_135 -> V_144 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_53
L_48
L_54 ,
V_131 , V_135 -> V_144 ,
V_136 , V_137 , V_138 ,
V_133 -> V_141 ) ;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_55
L_56 , V_131 ) ,
V_133 -> V_141 = V_161 << 16 ;
}
break;
case V_162 :
break;
case V_163 :
F_5 ( & V_8 -> V_15 -> V_16 , L_57
L_58
L_59 , V_131 ) ;
break;
case V_164 : {
V_133 -> V_141 = V_161 << 16 ;
}
break;
case V_165 :
F_5 ( & V_8 -> V_15 -> V_16 , L_60
L_61 , V_131 ) ;
break;
case V_166 :
V_133 -> V_141 = V_167 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_62 , V_131 ) ;
break;
case V_168 :
V_133 -> V_141 = V_167 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_63 , V_131 ) ;
break;
case V_169 :
V_133 -> V_141 = V_170 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_64 ,
V_131 , V_135 -> V_144 ) ;
break;
case V_171 :
V_133 -> V_141 = V_167 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_65 , V_131 ) ;
break;
case V_172 :
V_133 -> V_141 = V_153 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_66
L_67 , V_131 ) ;
break;
case V_173 :
V_133 -> V_141 = V_174 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_68 , V_131 ) ;
break;
case V_175 :
V_133 -> V_141 = V_167 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_69 ) ;
break;
default:
V_133 -> V_141 = V_167 << 16 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_70 ,
V_131 , V_135 -> V_149 ) ;
}
V_133 -> V_150 ( V_133 ) ;
F_82 ( V_8 , V_131 ) ;
}
static void F_83 ( struct V_176 * V_15 ,
struct V_9 * V_10 , int V_177 , int V_178 )
{
int V_36 ;
union V_128 V_179 ;
for ( V_36 = 0 ; V_36 < V_177 ; V_36 ++ ) {
V_179 . V_129 . V_126 = V_10 -> V_117 [ V_36 ] . V_125 . V_126 ;
V_179 . V_129 . V_127 = V_10 -> V_117 [ V_36 ] . V_125 . V_127 ;
F_78 ( V_15 , ( V_180 ) V_179 . V_130 , V_10 -> V_117 [ V_36 ] . V_122 ,
V_178 ) ;
}
}
static void F_84 ( struct V_176 * V_15 ,
struct V_9 * V_131 ,
unsigned char * V_26 ,
T_2 V_181 ,
int V_178 )
{
T_4 V_179 ;
if ( V_181 == 0 || V_178 == V_182 ) {
V_131 -> V_67 . V_68 = 0 ;
V_131 -> V_67 . V_123 = 0 ;
return;
}
V_179 = ( T_4 ) F_76 ( V_15 , V_26 , V_181 , V_178 ) ;
V_131 -> V_117 [ 0 ] . V_125 . V_126 =
( T_3 ) ( V_179 & ( T_4 ) 0x00000000FFFFFFFF ) ;
V_131 -> V_117 [ 0 ] . V_125 . V_127 =
( T_3 ) ( ( V_179 >> 32 ) & ( T_4 ) 0x00000000FFFFFFFF ) ;
V_131 -> V_117 [ 0 ] . V_122 = V_181 ;
V_131 -> V_67 . V_68 = ( V_183 ) 1 ;
V_131 -> V_67 . V_123 = ( V_184 ) 1 ;
}
static inline void F_85 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
F_86 ( V_185 ) ;
V_10 -> V_186 = & V_185 ;
F_30 ( V_8 , V_10 ) ;
F_87 ( & V_185 ) ;
}
static void F_88 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
unsigned long V_44 ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
if ( F_27 ( V_8 -> V_187 ) ) {
F_21 ( & V_8 -> V_45 , V_44 ) ;
V_10 -> V_11 -> V_149 = V_166 ;
} else {
F_21 ( & V_8 -> V_45 , V_44 ) ;
F_85 ( V_8 , V_10 ) ;
}
}
static void F_89 ( struct V_1 * V_8 ,
struct V_9 * V_10 , int V_178 )
{
int V_188 = 0 ;
do {
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_85 ( V_8 , V_10 ) ;
V_188 ++ ;
} while ( F_4 ( V_8 , V_10 ) && V_188 <= 3 );
F_83 ( V_8 -> V_15 , V_10 , 1 , V_178 ) ;
}
static void F_90 ( struct V_9 * V_131 )
{
struct V_134 * V_135 ;
struct V_23 * V_189 = & V_131 -> V_8 -> V_15 -> V_16 ;
V_135 = V_131 -> V_11 ;
switch ( V_135 -> V_149 ) {
case V_151 :
F_5 ( V_189 , L_71 , V_131 ) ;
F_5 ( V_189 , L_72 , V_131 ,
V_135 -> V_144 ) ;
if ( V_135 -> V_144 == 0 )
F_5 ( V_189 , L_73
L_74
L_75
L_76 ) ;
break;
case V_162 :
F_45 ( V_189 , L_77 ) ;
break;
case V_163 :
F_5 ( V_189 , L_78 , V_131 ) ;
break;
case V_164 : {
F_5 ( V_189 , L_79
L_80 , V_131 ) ;
}
break;
case V_165 :
F_5 ( V_189 , L_81 , V_131 ) ;
break;
case V_166 :
F_5 ( V_189 , L_82 , V_131 ) ;
break;
case V_168 :
F_5 ( V_189 , L_63 , V_131 ) ;
break;
case V_169 :
F_5 ( V_189 , L_83 , V_131 ) ;
break;
case V_171 :
F_5 ( V_189 , L_65 , V_131 ) ;
break;
case V_172 :
F_5 ( V_189 , L_84 , V_131 ) ;
break;
case V_173 :
F_5 ( V_189 , L_85 , V_131 ) ;
break;
case V_175 :
F_5 ( V_189 , L_69 ) ;
break;
default:
F_5 ( V_189 , L_70 , V_131 ,
V_135 -> V_149 ) ;
}
}
static int F_91 ( struct V_1 * V_8 , unsigned char * V_39 ,
unsigned char V_190 , unsigned char * V_26 ,
unsigned char V_191 )
{
int V_192 = V_193 ;
struct V_9 * V_10 ;
struct V_134 * V_135 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_86 ) ;
return - V_111 ;
}
F_93 ( V_10 , V_194 , V_8 , V_26 , V_191 , V_190 , V_39 , V_195 ) ;
F_89 ( V_8 , V_10 , V_196 ) ;
V_135 = V_10 -> V_11 ;
if ( V_135 -> V_149 != 0 && V_135 -> V_149 != V_162 ) {
F_90 ( V_10 ) ;
V_192 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_192 ;
}
static int F_95 ( struct V_1 * V_8 , unsigned char * V_39 )
{
int V_192 = V_193 ;
struct V_9 * V_10 ;
struct V_134 * V_135 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_86 ) ;
return - V_111 ;
}
F_93 ( V_10 , V_197 , V_8 , NULL , 0 , 0 , V_39 , V_198 ) ;
F_85 ( V_8 , V_10 ) ;
V_135 = V_10 -> V_11 ;
if ( V_135 -> V_149 != 0 ) {
F_90 ( V_10 ) ;
V_192 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_192 ;
}
static void F_96 ( struct V_1 * V_8 ,
unsigned char * V_39 , unsigned char * V_49 )
{
int V_192 ;
unsigned char * V_26 ;
* V_49 = V_50 ;
V_26 = F_62 ( 64 , V_105 ) ;
if ( ! V_26 )
return;
V_192 = F_91 ( V_8 , V_39 , 0xC1 , V_26 , 64 ) ;
if ( V_192 == 0 )
* V_49 = V_26 [ 8 ] ;
if ( * V_49 > V_50 )
* V_49 = V_50 ;
F_52 ( V_26 ) ;
return;
}
static int F_97 ( struct V_1 * V_8 , unsigned char * V_39 ,
unsigned char * V_54 , int V_181 )
{
int V_192 ;
unsigned char * V_26 ;
if ( V_181 > 16 )
V_181 = 16 ;
V_26 = F_62 ( 64 , V_105 ) ;
if ( ! V_26 )
return - 1 ;
V_192 = F_91 ( V_8 , V_39 , 0x83 , V_26 , 64 ) ;
if ( V_192 == 0 )
memcpy ( V_54 , & V_26 [ 8 ] , V_181 ) ;
F_52 ( V_26 ) ;
return V_192 != 0 ;
}
static int F_98 ( struct V_1 * V_8 , int V_199 ,
struct V_200 * V_26 , int V_191 ,
int V_201 )
{
int V_192 = V_193 ;
struct V_9 * V_10 ;
unsigned char V_39 [ 8 ] ;
struct V_134 * V_135 ;
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_86 ) ;
return - 1 ;
}
memset ( V_39 , 0 , sizeof( V_39 ) ) ;
F_93 ( V_10 , V_199 ? V_202 : V_203 , V_8 ,
V_26 , V_191 , 0 , V_39 , V_195 ) ;
if ( V_201 )
V_10 -> V_155 . V_156 [ 1 ] = V_201 ;
F_89 ( V_8 , V_10 , V_196 ) ;
V_135 = V_10 -> V_11 ;
if ( V_135 -> V_149 != 0 &&
V_135 -> V_149 != V_162 ) {
F_90 ( V_10 ) ;
V_192 = - 1 ;
}
F_94 ( V_8 , V_10 ) ;
return V_192 ;
}
static inline int F_99 ( struct V_1 * V_8 ,
struct V_200 * V_26 ,
int V_191 , int V_201 )
{
return F_98 ( V_8 , 0 , V_26 , V_191 , V_201 ) ;
}
static inline int F_100 ( struct V_1 * V_8 ,
struct V_200 * V_26 , int V_191 )
{
return F_98 ( V_8 , 1 , V_26 , V_191 , 0 ) ;
}
static inline void F_101 ( struct V_42 * V_23 ,
int V_72 , int V_73 , int V_74 )
{
V_23 -> V_72 = V_72 ;
V_23 -> V_73 = V_73 ;
V_23 -> V_74 = V_74 ;
}
static int F_102 ( struct V_1 * V_8 ,
unsigned char V_39 [] , struct V_42 * V_204 ,
unsigned char * V_205 )
{
#define F_103 43
#define F_104 "$DR-10"
#define F_105 (sizeof(OBDR_TAPE_SIG) - 1)
#define F_106 (OBDR_SIG_OFFSET + OBDR_SIG_LEN)
unsigned char * V_206 ;
unsigned char * V_207 ;
V_206 = F_62 ( F_106 , V_105 ) ;
if ( ! V_206 )
goto V_208;
if ( F_91 ( V_8 , V_39 , 0 , V_206 ,
( unsigned char ) F_106 ) != 0 ) {
F_44 ( & V_8 -> V_15 -> V_16 ,
L_87 ) ;
goto V_208;
}
V_204 -> V_87 = ( V_206 [ 0 ] & 0x1f ) ;
memcpy ( V_204 -> V_39 , V_39 , 8 ) ;
memcpy ( V_204 -> V_96 , & V_206 [ 8 ] ,
sizeof( V_204 -> V_96 ) ) ;
memcpy ( V_204 -> V_95 , & V_206 [ 16 ] ,
sizeof( V_204 -> V_95 ) ) ;
memset ( V_204 -> V_54 , 0 ,
sizeof( V_204 -> V_54 ) ) ;
F_97 ( V_8 , V_39 , V_204 -> V_54 ,
sizeof( V_204 -> V_54 ) ) ;
if ( V_204 -> V_87 == V_209 &&
F_17 ( V_39 ) )
F_96 ( V_8 , V_39 , & V_204 -> V_49 ) ;
else
V_204 -> V_49 = V_50 ;
if ( V_205 ) {
V_207 = & V_206 [ F_103 ] ;
* V_205 = ( V_204 -> V_87 == V_210 &&
strncmp ( V_207 , F_104 ,
F_105 ) == 0 ) ;
}
F_52 ( V_206 ) ;
return 0 ;
V_208:
F_52 ( V_206 ) ;
return 1 ;
}
static int F_107 ( struct V_1 * V_8 , struct V_42 * V_23 )
{
int V_36 ;
for ( V_36 = 0 ; V_211 [ V_36 ] ; V_36 ++ )
if ( strncmp ( V_23 -> V_95 , V_211 [ V_36 ] ,
strlen ( V_211 [ V_36 ] ) ) == 0 )
return 1 ;
return 0 ;
}
static void F_108 ( struct V_1 * V_8 ,
V_183 * V_212 , struct V_42 * V_23 )
{
T_3 V_52 = F_109 ( * ( ( V_213 * ) V_212 ) ) ;
if ( ! F_17 ( V_212 ) ) {
if ( F_36 ( V_212 ) )
F_101 ( V_23 , 3 , 0 , V_52 & 0x3fff ) ;
else
F_101 ( V_23 , 2 , - 1 , - 1 ) ;
return;
}
if ( F_107 ( V_8 , V_23 ) ) {
F_101 ( V_23 ,
1 , ( V_52 >> 16 ) & 0x3fff , V_52 & 0x00ff ) ;
return;
}
F_101 ( V_23 , 0 , 0 , V_52 & 0x3fff ) ;
}
static int F_110 ( struct V_1 * V_8 ,
struct V_42 * V_214 ,
struct V_42 * V_204 , V_183 * V_212 ,
unsigned long V_215 [] , int * V_216 )
{
unsigned char V_39 [ 8 ] ;
if ( F_111 ( V_214 -> V_73 , V_215 ) )
return 0 ;
if ( ! F_17 ( V_212 ) )
return 0 ;
if ( ! F_107 ( V_8 , V_214 ) )
return 0 ;
if ( V_214 -> V_74 == 0 )
return 0 ;
memset ( V_39 , 0 , 8 ) ;
V_39 [ 3 ] = V_214 -> V_73 ;
if ( F_36 ( V_39 ) )
return 0 ;
if ( F_37 ( V_8 ) )
return 0 ;
if ( * V_216 >= V_217 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_88
L_89
L_90 ) ;
return 0 ;
}
if ( F_102 ( V_8 , V_39 , V_204 , NULL ) )
return 0 ;
( * V_216 ) ++ ;
F_101 ( V_204 ,
V_214 -> V_72 , V_214 -> V_73 , 0 ) ;
F_112 ( V_214 -> V_73 , V_215 ) ;
return 1 ;
}
static int F_113 ( struct V_1 * V_8 ,
int V_218 ,
struct V_200 * V_219 , T_3 * V_220 ,
struct V_200 * V_221 , T_3 * V_222 )
{
if ( F_99 ( V_8 , V_219 , V_218 , 0 ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_91 ) ;
return - 1 ;
}
* V_220 = F_114 ( * ( ( V_223 * ) V_219 -> V_224 ) ) / 8 ;
if ( * V_220 > V_225 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_92
L_93 , V_225 ,
* V_220 - V_225 ) ;
* V_220 = V_225 ;
}
if ( F_100 ( V_8 , V_221 , V_218 ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_94 ) ;
return - 1 ;
}
* V_222 = F_114 ( * ( ( V_223 * ) V_221 -> V_224 ) ) / 8 ;
if ( * V_222 > V_226 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_95
L_96 , V_226 ,
* V_222 - V_226 ) ;
* V_222 = V_226 ;
}
if ( * V_222 + * V_220 > V_225 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_97
L_96 , V_225 ,
* V_220 + * V_222 - V_225 ) ;
* V_222 = V_225 - * V_220 ;
}
return 0 ;
}
V_183 * F_115 ( struct V_1 * V_8 , int V_227 , int V_36 ,
int V_220 , int V_222 , struct V_200 * V_228 ,
struct V_200 * V_229 )
{
int V_230 = V_220 + ( V_227 == 0 ) ;
int V_231 = V_220 + V_222 + ( V_227 == 0 ) ;
if ( V_36 == V_227 )
return V_71 ;
if ( V_36 < V_230 )
return & V_228 -> V_232 [ V_36 - ( V_227 == 0 ) ] [ 0 ] ;
if ( V_36 < V_231 )
return & V_229 -> V_232 [ V_36 - V_220 -
( V_227 == 0 ) ] [ 0 ] ;
F_116 () ;
return NULL ;
}
static void F_117 ( struct V_1 * V_8 , int V_79 )
{
struct V_200 * V_228 = NULL ;
struct V_200 * V_229 = NULL ;
T_3 V_220 = 0 ;
T_3 V_222 = 0 ;
T_3 V_233 = 0 ;
struct V_42 * * V_234 , * V_204 , * V_214 ;
int V_235 = 0 ;
int V_218 = sizeof( * V_228 ) + V_225 * 8 ;
int V_36 , V_216 , V_236 ;
int V_227 ;
F_39 ( V_215 , V_217 ) ;
V_234 = F_62 ( sizeof( * V_234 ) * V_77 , V_105 ) ;
V_228 = F_62 ( V_218 , V_105 ) ;
V_229 = F_62 ( V_218 , V_105 ) ;
V_214 = F_62 ( sizeof( * V_214 ) , V_105 ) ;
if ( ! V_234 || ! V_228 || ! V_229 || ! V_214 ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_98 ) ;
goto V_237;
}
memset ( V_215 , 0 , sizeof( V_215 ) ) ;
if ( F_113 ( V_8 , V_218 , V_228 , & V_220 ,
V_229 , & V_222 ) )
goto V_237;
V_236 = V_220 + V_222 + V_217 + 1 ;
for ( V_36 = 0 ; V_36 < V_236 ; V_36 ++ ) {
if ( V_36 >= V_77 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_99
L_100 , V_77 ,
V_236 - V_77 ) ;
break;
}
V_234 [ V_36 ] = F_62 ( sizeof( * V_234 [ V_36 ] ) , V_105 ) ;
if ( ! V_234 [ V_36 ] ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_101 ,
__FILE__ , __LINE__ ) ;
goto V_237;
}
V_233 ++ ;
}
if ( F_27 ( F_37 ( V_8 ) ) )
V_227 = 0 ;
else
V_227 = V_220 + V_222 ;
V_216 = 0 ;
for ( V_36 = 0 ; V_36 < V_220 + V_222 + 1 ; V_36 ++ ) {
V_183 * V_212 , V_238 = 0 ;
V_212 = F_115 ( V_8 , V_227 ,
V_36 , V_220 , V_222 , V_228 , V_229 ) ;
if ( V_212 [ 3 ] & 0xC0 &&
V_36 < V_220 + ( V_227 == 0 ) )
continue;
if ( F_102 ( V_8 , V_212 , V_214 ,
& V_238 ) )
continue;
F_108 ( V_8 , V_212 , V_214 ) ;
V_204 = V_234 [ V_235 ] ;
if ( F_110 ( V_8 , V_214 , V_204 ,
V_212 , V_215 ,
& V_216 ) ) {
V_235 ++ ;
V_204 = V_234 [ V_235 ] ;
}
* V_204 = * V_214 ;
switch ( V_204 -> V_87 ) {
case V_210 :
if ( V_238 )
V_235 ++ ;
break;
case V_209 :
if ( V_36 < V_220 )
break;
V_235 ++ ;
break;
case V_239 :
case V_240 :
V_235 ++ ;
break;
case V_241 :
if ( ! F_36 ( V_212 ) )
break;
V_235 ++ ;
break;
default:
break;
}
if ( V_235 >= V_77 )
break;
}
F_61 ( V_8 , V_79 , V_234 , V_235 ) ;
V_237:
F_52 ( V_214 ) ;
for ( V_36 = 0 ; V_36 < V_233 ; V_36 ++ )
F_52 ( V_234 [ V_36 ] ) ;
F_52 ( V_234 ) ;
F_52 ( V_228 ) ;
F_52 ( V_229 ) ;
}
static int F_118 ( struct V_1 * V_8 ,
struct V_9 * V_131 ,
struct V_132 * V_133 )
{
unsigned int V_242 ;
struct V_243 * V_244 ;
T_4 V_179 ;
int V_245 , V_36 , V_246 , V_247 ;
struct V_113 * V_248 ;
F_48 ( F_119 ( V_133 ) > V_8 -> V_249 ) ;
V_245 = F_120 ( V_133 ) ;
if ( V_245 < 0 )
return V_245 ;
if ( ! V_245 )
goto V_250;
V_248 = V_131 -> V_117 ;
V_247 = 0 ;
V_246 = 0 ;
F_121 (cmd, sg, use_sg, i) {
if ( V_36 == V_8 -> V_118 - 1 &&
V_245 > V_8 -> V_118 ) {
V_247 = 1 ;
V_248 = V_8 -> V_108 [ V_131 -> V_119 ] ;
V_246 = 0 ;
}
V_179 = ( T_4 ) F_122 ( V_244 ) ;
V_242 = F_123 ( V_244 ) ;
V_248 -> V_125 . V_126 = ( T_3 ) ( V_179 & 0x0FFFFFFFFULL ) ;
V_248 -> V_125 . V_127 = ( T_3 ) ( ( V_179 >> 32 ) & 0x0FFFFFFFFULL ) ;
V_248 -> V_122 = V_242 ;
V_248 -> V_120 = 0 ;
V_248 ++ ;
}
if ( V_245 + V_247 > V_8 -> V_251 )
V_8 -> V_251 = V_245 + V_247 ;
if ( V_247 ) {
V_131 -> V_67 . V_68 = V_8 -> V_118 ;
V_131 -> V_67 . V_123 = ( V_184 ) ( V_245 + 1 ) ;
F_75 ( V_8 , V_131 ) ;
return 0 ;
}
V_250:
V_131 -> V_67 . V_68 = ( V_183 ) V_245 ;
V_131 -> V_67 . V_123 = ( V_184 ) V_245 ;
return 0 ;
}
static int F_124 ( struct V_132 * V_133 ,
void (* F_125)( struct V_132 * ) )
{
struct V_1 * V_8 ;
struct V_42 * V_16 ;
unsigned char V_39 [ 8 ] ;
struct V_9 * V_10 ;
unsigned long V_44 ;
V_8 = F_1 ( V_133 -> V_23 ) ;
V_16 = V_133 -> V_23 -> V_46 ;
if ( ! V_16 ) {
V_133 -> V_141 = V_161 << 16 ;
F_125 ( V_133 ) ;
return 0 ;
}
memcpy ( V_39 , V_16 -> V_39 , sizeof( V_39 ) ) ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
if ( F_27 ( V_8 -> V_187 ) ) {
F_21 ( & V_8 -> V_45 , V_44 ) ;
V_133 -> V_141 = V_167 << 16 ;
F_125 ( V_133 ) ;
return 0 ;
}
V_10 = F_126 ( V_8 ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
if ( V_10 == NULL ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_102 ) ;
return V_252 ;
}
V_133 -> V_150 = F_125 ;
V_133 -> V_253 = ( unsigned char * ) V_10 ;
V_10 -> V_254 = V_255 ;
V_10 -> V_140 = V_133 ;
V_10 -> V_67 . V_256 = 0 ;
memcpy ( & V_10 -> V_67 . V_232 . V_257 [ 0 ] , & V_39 [ 0 ] , 8 ) ;
V_10 -> V_67 . V_258 . V_126 = ( V_10 -> V_119 << V_259 ) ;
V_10 -> V_67 . V_258 . V_126 |= V_260 ;
V_10 -> V_155 . V_261 = 0 ;
memset ( V_10 -> V_155 . V_156 , 0 , sizeof( V_10 -> V_155 . V_156 ) ) ;
F_48 ( V_133 -> V_262 > sizeof( V_10 -> V_155 . V_156 ) ) ;
V_10 -> V_155 . V_263 = V_133 -> V_262 ;
memcpy ( V_10 -> V_155 . V_156 , V_133 -> V_160 , V_133 -> V_262 ) ;
V_10 -> V_155 . Type . Type = V_195 ;
V_10 -> V_155 . Type . V_264 = V_265 ;
switch ( V_133 -> V_266 ) {
case V_267 :
V_10 -> V_155 . Type . V_268 = V_269 ;
break;
case V_270 :
V_10 -> V_155 . Type . V_268 = V_271 ;
break;
case V_272 :
V_10 -> V_155 . Type . V_268 = V_273 ;
break;
case V_274 :
V_10 -> V_155 . Type . V_268 = V_275 ;
break;
default:
F_44 ( & V_8 -> V_15 -> V_16 , L_103 ,
V_133 -> V_266 ) ;
F_116 () ;
break;
}
if ( F_118 ( V_8 , V_10 , V_133 ) < 0 ) {
F_82 ( V_8 , V_10 ) ;
return V_252 ;
}
F_30 ( V_8 , V_10 ) ;
return 0 ;
}
int F_127 ( struct V_6 * V_7 ,
unsigned long V_276 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
unsigned long V_44 ;
int V_277 ;
F_20 ( & V_8 -> V_278 , V_44 ) ;
V_277 = V_8 -> V_279 ;
F_21 ( & V_8 -> V_278 , V_44 ) ;
return V_277 ;
}
static int F_128 ( struct V_2 * V_3 ,
int V_280 , int V_281 )
{
struct V_1 * V_8 = F_1 ( V_3 ) ;
if ( V_281 != V_282 )
return - V_283 ;
if ( V_280 < 1 )
V_280 = 1 ;
else
if ( V_280 > V_8 -> V_109 )
V_280 = V_8 -> V_109 ;
F_129 ( V_3 , F_130 ( V_3 ) , V_280 ) ;
return V_3 -> V_284 ;
}
static void F_131 ( struct V_1 * V_8 )
{
F_132 ( V_8 -> V_29 ) ;
F_133 ( V_8 -> V_29 ) ;
V_8 -> V_29 = NULL ;
}
static int F_134 ( struct V_1 * V_8 )
{
struct V_6 * V_7 ;
int error ;
V_7 = F_135 ( & V_285 , sizeof( V_8 ) ) ;
if ( V_7 == NULL )
goto V_286;
V_7 -> V_287 = 0 ;
V_7 -> V_288 = 0 ;
V_7 -> V_289 = - 1 ;
V_7 -> V_290 = 3 ;
V_7 -> V_291 = V_292 ;
V_7 -> V_293 = V_226 ;
V_7 -> V_294 = V_226 ;
V_7 -> V_295 = V_8 -> V_109 ;
V_7 -> V_296 = V_8 -> V_109 ;
V_7 -> V_297 = V_8 -> V_249 ;
V_8 -> V_29 = V_7 ;
V_7 -> V_46 [ 0 ] = ( unsigned long ) V_8 ;
V_7 -> V_298 = V_8 -> V_299 [ V_8 -> V_300 ] ;
V_7 -> V_301 = V_7 -> V_298 ;
error = F_136 ( V_7 , & V_8 -> V_15 -> V_16 ) ;
if ( error )
goto V_302;
F_137 ( V_7 ) ;
return 0 ;
V_302:
F_44 ( & V_8 -> V_15 -> V_16 , L_104
L_105 , V_303 , V_8 -> V_18 ) ;
F_133 ( V_7 ) ;
return error ;
V_286:
F_44 ( & V_8 -> V_15 -> V_16 , L_106
L_105 , V_303 , V_8 -> V_18 ) ;
return - V_111 ;
}
static int F_138 ( struct V_1 * V_8 ,
unsigned char V_304 [] )
{
int V_192 = 0 ;
int V_27 = 0 ;
int V_305 = 1 ;
struct V_9 * V_10 ;
V_10 = F_92 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_32
L_107 ) ;
return V_306 ;
}
while ( V_27 < V_307 ) {
F_139 ( 1000 * V_305 ) ;
V_27 ++ ;
if ( V_305 < V_308 )
V_305 = V_305 * 2 ;
F_93 ( V_10 , V_309 , V_8 , NULL , 0 , 0 , V_304 , V_195 ) ;
F_85 ( V_8 , V_10 ) ;
if ( V_10 -> V_11 -> V_149 == V_310 )
break;
if ( V_10 -> V_11 -> V_149 == V_151 &&
V_10 -> V_11 -> V_144 == V_152 &&
( V_10 -> V_11 -> V_12 [ 2 ] == V_311 ||
V_10 -> V_11 -> V_12 [ 2 ] == V_13 ) )
break;
F_5 ( & V_8 -> V_15 -> V_16 , L_108
L_109 , V_305 ) ;
V_192 = 1 ;
}
if ( V_192 )
F_5 ( & V_8 -> V_15 -> V_16 , L_110 ) ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_111 ) ;
F_94 ( V_8 , V_10 ) ;
return V_192 ;
}
static int F_140 ( struct V_132 * V_312 )
{
int V_192 ;
struct V_1 * V_8 ;
struct V_42 * V_16 ;
V_8 = F_1 ( V_312 -> V_23 ) ;
if ( V_8 == NULL )
return V_313 ;
V_16 = V_312 -> V_23 -> V_46 ;
if ( ! V_16 ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_112
L_113 ) ;
return V_313 ;
}
F_5 ( & V_8 -> V_15 -> V_16 , L_114 ,
V_8 -> V_29 -> V_314 , V_16 -> V_72 , V_16 -> V_73 , V_16 -> V_74 ) ;
V_192 = F_95 ( V_8 , V_16 -> V_39 ) ;
if ( V_192 == 0 && F_138 ( V_8 , V_16 -> V_39 ) == 0 )
return V_315 ;
F_5 ( & V_8 -> V_15 -> V_16 , L_115 ) ;
return V_313 ;
}
static struct V_9 * F_126 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_36 ;
union V_128 V_116 ;
V_180 V_316 , V_317 ;
do {
V_36 = F_42 ( V_8 -> V_318 , V_8 -> V_109 ) ;
if ( V_36 == V_8 -> V_109 )
return NULL ;
} while ( F_141
( V_36 & ( V_319 - 1 ) ,
V_8 -> V_318 + ( V_36 / V_319 ) ) != 0 );
V_10 = V_8 -> V_320 + V_36 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_316 = V_8 -> V_321
+ V_36 * sizeof( * V_10 ) ;
V_10 -> V_11 = V_8 -> V_322 + V_36 ;
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
V_317 = V_8 -> V_323
+ V_36 * sizeof( * V_10 -> V_11 ) ;
V_8 -> V_324 ++ ;
V_10 -> V_119 = V_36 ;
F_142 ( & V_10 -> V_56 ) ;
V_10 -> V_65 = ( T_3 ) V_316 ;
V_116 . V_130 = ( T_4 ) V_317 ;
V_10 -> V_325 . V_125 . V_126 = V_116 . V_129 . V_126 ;
V_10 -> V_325 . V_125 . V_127 = V_116 . V_129 . V_127 ;
V_10 -> V_325 . V_122 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static struct V_9 * F_92 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
union V_128 V_116 ;
V_180 V_316 , V_317 ;
V_10 = F_143 ( V_8 -> V_15 , sizeof( * V_10 ) , & V_316 ) ;
if ( V_10 == NULL )
return NULL ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_119 = - 1 ;
V_10 -> V_11 = F_143 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
& V_317 ) ;
if ( V_10 -> V_11 == NULL ) {
F_144 ( V_8 -> V_15 ,
sizeof( * V_10 ) , V_10 , V_316 ) ;
return NULL ;
}
memset ( V_10 -> V_11 , 0 , sizeof( * V_10 -> V_11 ) ) ;
F_142 ( & V_10 -> V_56 ) ;
V_10 -> V_65 = ( T_3 ) V_316 ;
V_116 . V_130 = ( T_4 ) V_317 ;
V_10 -> V_325 . V_125 . V_126 = V_116 . V_129 . V_126 ;
V_10 -> V_325 . V_125 . V_127 = V_116 . V_129 . V_127 ;
V_10 -> V_325 . V_122 = sizeof( * V_10 -> V_11 ) ;
V_10 -> V_8 = V_8 ;
return V_10 ;
}
static void F_82 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
int V_36 ;
V_36 = V_10 - V_8 -> V_320 ;
F_145 ( V_36 & ( V_319 - 1 ) ,
V_8 -> V_318 + ( V_36 / V_319 ) ) ;
V_8 -> V_326 ++ ;
}
static void F_94 ( struct V_1 * V_8 , struct V_9 * V_10 )
{
union V_128 V_116 ;
V_116 . V_129 . V_126 = V_10 -> V_325 . V_125 . V_126 ;
V_116 . V_129 . V_127 = V_10 -> V_325 . V_125 . V_127 ;
F_144 ( V_8 -> V_15 , sizeof( * V_10 -> V_11 ) ,
V_10 -> V_11 , ( V_180 ) V_116 . V_130 ) ;
F_144 ( V_8 -> V_15 , sizeof( * V_10 ) ,
V_10 , ( V_180 ) ( V_10 -> V_65 & V_327 ) ) ;
}
static int F_146 ( struct V_2 * V_16 , int V_133 , void * V_328 )
{
T_5 T_6 * V_329 =
( T_5 T_6 * ) V_328 ;
T_7 V_330 ;
T_7 T_6 * V_331 = F_147 ( sizeof( V_330 ) ) ;
int V_332 ;
T_3 V_131 ;
memset ( & V_330 , 0 , sizeof( V_330 ) ) ;
V_332 = 0 ;
V_332 |= F_148 ( & V_330 . V_333 , & V_329 -> V_333 ,
sizeof( V_330 . V_333 ) ) ;
V_332 |= F_148 ( & V_330 . V_155 , & V_329 -> V_155 ,
sizeof( V_330 . V_155 ) ) ;
V_332 |= F_148 ( & V_330 . V_334 , & V_329 -> V_334 ,
sizeof( V_330 . V_334 ) ) ;
V_332 |= F_149 ( V_330 . V_335 , & V_329 -> V_335 ) ;
V_332 |= F_149 ( V_131 , & V_329 -> V_26 ) ;
V_330 . V_26 = F_150 ( V_131 ) ;
V_332 |= F_151 ( V_331 , & V_330 , sizeof( V_330 ) ) ;
if ( V_332 )
return - V_336 ;
V_332 = F_152 ( V_16 , V_337 , ( void * ) V_331 ) ;
if ( V_332 )
return V_332 ;
V_332 |= F_153 ( & V_329 -> V_334 , & V_331 -> V_334 ,
sizeof( V_329 -> V_334 ) ) ;
if ( V_332 )
return - V_336 ;
return V_332 ;
}
static int F_154 ( struct V_2 * V_16 ,
int V_133 , void * V_328 )
{
T_8 T_6 * V_329 =
( T_8 T_6 * ) V_328 ;
T_9 V_330 ;
T_9 T_6 * V_331 =
F_147 ( sizeof( V_330 ) ) ;
int V_332 ;
T_3 V_131 ;
memset ( & V_330 , 0 , sizeof( V_330 ) ) ;
V_332 = 0 ;
V_332 |= F_148 ( & V_330 . V_333 , & V_329 -> V_333 ,
sizeof( V_330 . V_333 ) ) ;
V_332 |= F_148 ( & V_330 . V_155 , & V_329 -> V_155 ,
sizeof( V_330 . V_155 ) ) ;
V_332 |= F_148 ( & V_330 . V_334 , & V_329 -> V_334 ,
sizeof( V_330 . V_334 ) ) ;
V_332 |= F_149 ( V_330 . V_335 , & V_329 -> V_335 ) ;
V_332 |= F_149 ( V_330 . V_338 , & V_329 -> V_338 ) ;
V_332 |= F_149 ( V_131 , & V_329 -> V_26 ) ;
V_330 . V_26 = F_150 ( V_131 ) ;
V_332 |= F_151 ( V_331 , & V_330 , sizeof( V_330 ) ) ;
if ( V_332 )
return - V_336 ;
V_332 = F_152 ( V_16 , V_339 , ( void * ) V_331 ) ;
if ( V_332 )
return V_332 ;
V_332 |= F_153 ( & V_329 -> V_334 , & V_331 -> V_334 ,
sizeof( V_329 -> V_334 ) ) ;
if ( V_332 )
return - V_336 ;
return V_332 ;
}
static int F_155 ( struct V_2 * V_16 , int V_133 , void * V_328 )
{
switch ( V_133 ) {
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
case V_354 :
return F_152 ( V_16 , V_133 , V_328 ) ;
case V_355 :
return F_146 ( V_16 , V_133 , V_328 ) ;
case V_356 :
return F_154 ( V_16 , V_133 , V_328 ) ;
default:
return - V_357 ;
}
}
static int F_156 ( struct V_1 * V_8 , void T_6 * V_358 )
{
struct V_359 V_360 ;
if ( ! V_358 )
return - V_361 ;
V_360 . V_362 = F_157 ( V_8 -> V_15 -> V_72 ) ;
V_360 . V_72 = V_8 -> V_15 -> V_72 -> V_363 ;
V_360 . V_364 = V_8 -> V_15 -> V_365 ;
V_360 . V_35 = V_8 -> V_35 ;
if ( F_151 ( V_358 , & V_360 , sizeof( V_360 ) ) )
return - V_336 ;
return 0 ;
}
static int F_158 ( struct V_1 * V_8 , void T_6 * V_358 )
{
T_10 V_366 ;
unsigned char V_367 , V_368 , V_369 ;
int V_192 ;
V_192 = sscanf ( V_370 , L_116 ,
& V_367 , & V_368 , & V_369 ) ;
if ( V_192 != 3 ) {
F_45 ( & V_8 -> V_15 -> V_16 , L_117
L_118 , V_370 ) ;
V_367 = 0 ;
V_368 = 0 ;
V_369 = 0 ;
}
V_366 = ( V_367 << 16 ) | ( V_368 << 8 ) | V_369 ;
if ( ! V_358 )
return - V_361 ;
if ( F_151 ( V_358 , & V_366 , sizeof( T_10 ) ) )
return - V_336 ;
return 0 ;
}
static int F_159 ( struct V_1 * V_8 , void T_6 * V_358 )
{
T_7 V_371 ;
struct V_9 * V_10 ;
char * V_372 = NULL ;
union V_128 V_116 ;
if ( ! V_358 )
return - V_361 ;
if ( ! F_160 ( V_373 ) )
return - V_374 ;
if ( F_148 ( & V_371 , V_358 , sizeof( V_371 ) ) )
return - V_336 ;
if ( ( V_371 . V_335 < 1 ) &&
( V_371 . V_155 . Type . V_268 != V_273 ) ) {
return - V_361 ;
}
if ( V_371 . V_335 > 0 ) {
V_372 = F_74 ( V_371 . V_335 , V_105 ) ;
if ( V_372 == NULL )
return - V_336 ;
if ( V_371 . V_155 . Type . V_268 == V_269 ) {
if ( F_148 ( V_372 , V_371 . V_26 ,
V_371 . V_335 ) ) {
F_52 ( V_372 ) ;
return - V_336 ;
}
} else {
memset ( V_372 , 0 , V_371 . V_335 ) ;
}
}
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
F_52 ( V_372 ) ;
return - V_111 ;
}
V_10 -> V_254 = V_375 ;
V_10 -> V_67 . V_256 = 0 ;
if ( V_371 . V_335 > 0 ) {
V_10 -> V_67 . V_68 = 1 ;
V_10 -> V_67 . V_123 = 1 ;
} else {
V_10 -> V_67 . V_68 = 0 ;
V_10 -> V_67 . V_123 = 0 ;
}
memcpy ( & V_10 -> V_67 . V_232 , & V_371 . V_333 , sizeof( V_10 -> V_67 . V_232 ) ) ;
V_10 -> V_67 . V_258 . V_126 = V_10 -> V_65 ;
memcpy ( & V_10 -> V_155 , & V_371 . V_155 ,
sizeof( V_10 -> V_155 ) ) ;
if ( V_371 . V_335 > 0 ) {
V_116 . V_130 = F_76 ( V_8 -> V_15 , V_372 ,
V_371 . V_335 , V_376 ) ;
V_10 -> V_117 [ 0 ] . V_125 . V_126 = V_116 . V_129 . V_126 ;
V_10 -> V_117 [ 0 ] . V_125 . V_127 = V_116 . V_129 . V_127 ;
V_10 -> V_117 [ 0 ] . V_122 = V_371 . V_335 ;
V_10 -> V_117 [ 0 ] . V_120 = 0 ;
}
F_88 ( V_8 , V_10 ) ;
if ( V_371 . V_335 > 0 )
F_83 ( V_8 -> V_15 , V_10 , 1 , V_376 ) ;
F_161 ( V_8 , V_10 ) ;
memcpy ( & V_371 . V_334 , V_10 -> V_11 ,
sizeof( V_371 . V_334 ) ) ;
if ( F_151 ( V_358 , & V_371 , sizeof( V_371 ) ) ) {
F_52 ( V_372 ) ;
F_94 ( V_8 , V_10 ) ;
return - V_336 ;
}
if ( V_371 . V_155 . Type . V_268 == V_271 &&
V_371 . V_335 > 0 ) {
if ( F_151 ( V_371 . V_26 , V_372 , V_371 . V_335 ) ) {
F_52 ( V_372 ) ;
F_94 ( V_8 , V_10 ) ;
return - V_336 ;
}
}
F_52 ( V_372 ) ;
F_94 ( V_8 , V_10 ) ;
return 0 ;
}
static int F_162 ( struct V_1 * V_8 , void T_6 * V_358 )
{
T_9 * V_377 ;
struct V_9 * V_10 ;
unsigned char * * V_372 = NULL ;
int * V_378 = NULL ;
union V_128 V_116 ;
T_11 V_177 = 0 ;
int V_379 = 0 ;
int V_36 ;
T_3 V_380 ;
T_3 V_381 ;
T_11 T_6 * V_382 ;
if ( ! V_358 )
return - V_361 ;
if ( ! F_160 ( V_373 ) )
return - V_374 ;
V_377 = ( T_9 * )
F_74 ( sizeof( * V_377 ) , V_105 ) ;
if ( ! V_377 ) {
V_379 = - V_111 ;
goto V_383;
}
if ( F_148 ( V_377 , V_358 , sizeof( * V_377 ) ) ) {
V_379 = - V_336 ;
goto V_383;
}
if ( ( V_377 -> V_335 < 1 ) &&
( V_377 -> V_155 . Type . V_268 != V_273 ) ) {
V_379 = - V_361 ;
goto V_383;
}
if ( V_377 -> V_338 > V_384 ) {
V_379 = - V_361 ;
goto V_383;
}
if ( V_377 -> V_335 > V_377 -> V_338 * V_385 ) {
V_379 = - V_361 ;
goto V_383;
}
V_372 = F_62 ( V_385 * sizeof( char * ) , V_105 ) ;
if ( ! V_372 ) {
V_379 = - V_111 ;
goto V_383;
}
V_378 = F_74 ( V_385 * sizeof( int ) , V_105 ) ;
if ( ! V_378 ) {
V_379 = - V_111 ;
goto V_383;
}
V_380 = V_377 -> V_335 ;
V_382 = V_377 -> V_26 ;
while ( V_380 ) {
V_381 = ( V_380 > V_377 -> V_338 ) ? V_377 -> V_338 : V_380 ;
V_378 [ V_177 ] = V_381 ;
V_372 [ V_177 ] = F_74 ( V_381 , V_105 ) ;
if ( V_372 [ V_177 ] == NULL ) {
V_379 = - V_111 ;
goto V_383;
}
if ( V_377 -> V_155 . Type . V_268 == V_269 ) {
if ( F_148 ( V_372 [ V_177 ] , V_382 , V_381 ) ) {
V_379 = - V_111 ;
goto V_383;
}
} else
memset ( V_372 [ V_177 ] , 0 , V_381 ) ;
V_380 -= V_381 ;
V_382 += V_381 ;
V_177 ++ ;
}
V_10 = F_92 ( V_8 ) ;
if ( V_10 == NULL ) {
V_379 = - V_111 ;
goto V_383;
}
V_10 -> V_254 = V_375 ;
V_10 -> V_67 . V_256 = 0 ;
V_10 -> V_67 . V_68 = V_10 -> V_67 . V_123 = V_177 ;
memcpy ( & V_10 -> V_67 . V_232 , & V_377 -> V_333 , sizeof( V_10 -> V_67 . V_232 ) ) ;
V_10 -> V_67 . V_258 . V_126 = V_10 -> V_65 ;
memcpy ( & V_10 -> V_155 , & V_377 -> V_155 , sizeof( V_10 -> V_155 ) ) ;
if ( V_377 -> V_335 > 0 ) {
int V_36 ;
for ( V_36 = 0 ; V_36 < V_177 ; V_36 ++ ) {
V_116 . V_130 = F_76 ( V_8 -> V_15 , V_372 [ V_36 ] ,
V_378 [ V_36 ] , V_376 ) ;
V_10 -> V_117 [ V_36 ] . V_125 . V_126 = V_116 . V_129 . V_126 ;
V_10 -> V_117 [ V_36 ] . V_125 . V_127 = V_116 . V_129 . V_127 ;
V_10 -> V_117 [ V_36 ] . V_122 = V_378 [ V_36 ] ;
V_10 -> V_117 [ V_36 ] . V_120 = 0 ;
}
}
F_88 ( V_8 , V_10 ) ;
if ( V_177 )
F_83 ( V_8 -> V_15 , V_10 , V_177 , V_376 ) ;
F_161 ( V_8 , V_10 ) ;
memcpy ( & V_377 -> V_334 , V_10 -> V_11 , sizeof( V_377 -> V_334 ) ) ;
if ( F_151 ( V_358 , V_377 , sizeof( * V_377 ) ) ) {
F_94 ( V_8 , V_10 ) ;
V_379 = - V_336 ;
goto V_383;
}
if ( V_377 -> V_155 . Type . V_268 == V_271 && V_377 -> V_335 > 0 ) {
T_11 T_6 * V_386 = V_377 -> V_26 ;
for ( V_36 = 0 ; V_36 < V_177 ; V_36 ++ ) {
if ( F_151 ( V_386 , V_372 [ V_36 ] , V_378 [ V_36 ] ) ) {
F_94 ( V_8 , V_10 ) ;
V_379 = - V_336 ;
goto V_383;
}
V_386 += V_378 [ V_36 ] ;
}
}
F_94 ( V_8 , V_10 ) ;
V_379 = 0 ;
V_383:
if ( V_372 ) {
for ( V_36 = 0 ; V_36 < V_177 ; V_36 ++ )
F_52 ( V_372 [ V_36 ] ) ;
F_52 ( V_372 ) ;
}
F_52 ( V_378 ) ;
F_52 ( V_377 ) ;
return V_379 ;
}
static void F_161 ( struct V_1 * V_8 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_11 -> V_149 == V_151 &&
V_10 -> V_11 -> V_144 != V_152 )
( void ) F_4 ( V_8 , V_10 ) ;
}
static int F_152 ( struct V_2 * V_16 , int V_133 , void * V_328 )
{
struct V_1 * V_8 ;
void T_6 * V_358 = ( void T_6 * ) V_328 ;
V_8 = F_1 ( V_16 ) ;
switch ( V_133 ) {
case V_350 :
case V_351 :
case V_352 :
F_8 ( V_8 -> V_29 ) ;
return 0 ;
case V_340 :
return F_156 ( V_8 , V_358 ) ;
case V_348 :
return F_158 ( V_8 , V_358 ) ;
case V_337 :
return F_159 ( V_8 , V_358 ) ;
case V_339 :
return F_162 ( V_8 , V_358 ) ;
default:
return - V_387 ;
}
}
static int T_12 F_163 ( struct V_1 * V_8 ,
unsigned char * V_39 , V_183 V_388 )
{
struct V_9 * V_10 ;
V_10 = F_126 ( V_8 ) ;
if ( ! V_10 )
return - V_111 ;
F_93 ( V_10 , V_197 , V_8 , NULL , 0 , 0 ,
V_71 , V_198 ) ;
V_10 -> V_155 . V_156 [ 1 ] = V_388 ;
V_10 -> V_186 = NULL ;
F_30 ( V_8 , V_10 ) ;
return 0 ;
}
static void F_93 ( struct V_9 * V_10 , V_183 V_133 , struct V_1 * V_8 ,
void * V_372 , T_2 V_389 , V_183 V_390 , unsigned char * V_39 ,
int V_254 )
{
int V_391 = V_273 ;
V_10 -> V_254 = V_375 ;
V_10 -> V_67 . V_256 = 0 ;
if ( V_372 != NULL && V_389 > 0 ) {
V_10 -> V_67 . V_68 = 1 ;
V_10 -> V_67 . V_123 = 1 ;
} else {
V_10 -> V_67 . V_68 = 0 ;
V_10 -> V_67 . V_123 = 0 ;
}
V_10 -> V_67 . V_258 . V_126 = V_10 -> V_65 ;
memcpy ( V_10 -> V_67 . V_232 . V_257 , V_39 , 8 ) ;
V_10 -> V_155 . Type . Type = V_254 ;
if ( V_254 == V_195 ) {
switch ( V_133 ) {
case V_194 :
if ( V_390 != 0 ) {
V_10 -> V_155 . V_156 [ 1 ] = 0x01 ;
V_10 -> V_155 . V_156 [ 2 ] = V_390 ;
}
V_10 -> V_155 . V_263 = 6 ;
V_10 -> V_155 . Type . V_264 = V_265 ;
V_10 -> V_155 . Type . V_268 = V_271 ;
V_10 -> V_155 . V_261 = 0 ;
V_10 -> V_155 . V_156 [ 0 ] = V_194 ;
V_10 -> V_155 . V_156 [ 4 ] = V_389 & 0xFF ;
break;
case V_202 :
case V_203 :
V_10 -> V_155 . V_263 = 12 ;
V_10 -> V_155 . Type . V_264 = V_265 ;
V_10 -> V_155 . Type . V_268 = V_271 ;
V_10 -> V_155 . V_261 = 0 ;
V_10 -> V_155 . V_156 [ 0 ] = V_133 ;
V_10 -> V_155 . V_156 [ 6 ] = ( V_389 >> 24 ) & 0xFF ;
V_10 -> V_155 . V_156 [ 7 ] = ( V_389 >> 16 ) & 0xFF ;
V_10 -> V_155 . V_156 [ 8 ] = ( V_389 >> 8 ) & 0xFF ;
V_10 -> V_155 . V_156 [ 9 ] = V_389 & 0xFF ;
break;
case V_392 :
V_10 -> V_155 . V_263 = 12 ;
V_10 -> V_155 . Type . V_264 = V_265 ;
V_10 -> V_155 . Type . V_268 = V_269 ;
V_10 -> V_155 . V_261 = 0 ;
V_10 -> V_155 . V_156 [ 0 ] = V_393 ;
V_10 -> V_155 . V_156 [ 6 ] = V_394 ;
V_10 -> V_155 . V_156 [ 7 ] = ( V_389 >> 8 ) & 0xFF ;
V_10 -> V_155 . V_156 [ 8 ] = V_389 & 0xFF ;
break;
case V_309 :
V_10 -> V_155 . V_263 = 6 ;
V_10 -> V_155 . Type . V_264 = V_265 ;
V_10 -> V_155 . Type . V_268 = V_273 ;
V_10 -> V_155 . V_261 = 0 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_119 , V_133 ) ;
F_116 () ;
return;
}
} else if ( V_254 == V_198 ) {
switch ( V_133 ) {
case V_197 :
V_10 -> V_155 . V_263 = 16 ;
V_10 -> V_155 . Type . Type = 1 ;
V_10 -> V_155 . Type . V_264 = V_265 ;
V_10 -> V_155 . Type . V_268 = V_273 ;
V_10 -> V_155 . V_261 = 0 ;
memset ( & V_10 -> V_155 . V_156 [ 0 ] , 0 , sizeof( V_10 -> V_155 . V_156 ) ) ;
V_10 -> V_155 . V_156 [ 0 ] = V_133 ;
V_10 -> V_155 . V_156 [ 1 ] = 0x03 ;
V_10 -> V_155 . V_156 [ 4 ] = 0x00 ;
V_10 -> V_155 . V_156 [ 5 ] = 0x00 ;
V_10 -> V_155 . V_156 [ 6 ] = 0x00 ;
V_10 -> V_155 . V_156 [ 7 ] = 0x00 ;
break;
default:
F_5 ( & V_8 -> V_15 -> V_16 , L_120 ,
V_133 ) ;
F_116 () ;
}
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_121 , V_254 ) ;
F_116 () ;
}
switch ( V_10 -> V_155 . Type . V_268 ) {
case V_271 :
V_391 = V_196 ;
break;
case V_269 :
V_391 = V_124 ;
break;
case V_273 :
V_391 = V_182 ;
break;
default:
V_391 = V_376 ;
}
F_84 ( V_8 -> V_15 , V_10 , V_372 , V_389 , V_391 ) ;
return;
}
static void T_13 * F_164 ( T_14 V_395 , T_14 V_389 )
{
T_14 V_396 = ( ( T_14 ) V_395 ) & V_397 ;
T_14 V_398 = ( ( T_14 ) V_395 ) - V_396 ;
void T_13 * V_399 = F_165 ( V_396 , V_398 + V_389 ) ;
return V_399 ? ( V_399 + V_398 ) : NULL ;
}
static void F_31 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
while ( ! F_34 ( & V_8 -> V_69 ) ) {
V_10 = F_166 ( V_8 -> V_69 . V_400 , struct V_9 , V_56 ) ;
if ( ( V_8 -> V_58 . V_401 ( V_8 ) ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_122 ) ;
break;
}
F_32 ( V_10 ) ;
V_8 -> V_70 -- ;
V_8 -> V_58 . V_402 ( V_8 , V_10 ) ;
F_24 ( & V_8 -> V_403 , V_10 ) ;
}
}
static inline unsigned long F_167 ( struct V_1 * V_8 )
{
return V_8 -> V_58 . V_59 ( V_8 ) ;
}
static inline bool F_168 ( struct V_1 * V_8 )
{
return V_8 -> V_58 . V_404 ( V_8 ) ;
}
static inline long F_169 ( struct V_1 * V_8 )
{
return ( V_8 -> V_58 . V_404 ( V_8 ) == 0 ) ||
( V_8 -> V_405 == 0 ) ;
}
static inline int F_170 ( struct V_1 * V_8 , T_3 V_406 ,
T_3 V_407 )
{
if ( F_27 ( V_406 >= V_8 -> V_109 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_123 , V_407 ) ;
return 1 ;
}
return 0 ;
}
static inline void F_171 ( struct V_9 * V_10 , T_3 V_407 )
{
F_32 ( V_10 ) ;
if ( F_29 ( V_10 -> V_254 == V_255 ) )
F_79 ( V_10 ) ;
else if ( V_10 -> V_254 == V_375 )
F_172 ( V_10 -> V_186 ) ;
}
static inline T_3 F_173 ( T_3 V_408 )
{
return V_408 & V_260 ;
}
static inline T_3 F_174 ( T_3 V_408 )
{
return V_408 >> V_259 ;
}
static inline T_3 F_175 ( struct V_1 * V_8 , T_3 V_408 )
{
#define F_176 ((1 << DIRECT_LOOKUP_SHIFT) - 1)
#define F_177 0x03
if ( F_27 ( ! ( V_8 -> V_33 & V_34 ) ) )
return V_408 & ~ F_177 ;
return V_408 & ~ F_176 ;
}
static inline T_3 F_178 ( struct V_1 * V_8 ,
T_3 V_407 )
{
T_3 V_406 ;
struct V_9 * V_10 ;
V_406 = F_174 ( V_407 ) ;
if ( F_170 ( V_8 , V_406 , V_407 ) )
return F_26 ( V_8 ) ;
V_10 = V_8 -> V_320 + V_406 ;
F_171 ( V_10 , V_407 ) ;
return F_26 ( V_8 ) ;
}
static inline T_3 F_179 ( struct V_1 * V_8 ,
T_3 V_407 )
{
T_3 V_408 ;
struct V_9 * V_10 = NULL ;
V_408 = F_175 ( V_8 , V_407 ) ;
F_180 (c, &h->cmpQ, list) {
if ( ( V_10 -> V_65 & 0xFFFFFFE0 ) == ( V_408 & 0xFFFFFFE0 ) ) {
F_171 ( V_10 , V_407 ) ;
return F_26 ( V_8 ) ;
}
}
F_170 ( V_8 , V_8 -> V_109 + 1 , V_407 ) ;
return F_26 ( V_8 ) ;
}
static int F_181 ( struct V_1 * V_8 )
{
if ( F_29 ( ! V_409 ) )
return 0 ;
if ( F_29 ( V_8 -> V_405 ) )
return 0 ;
F_45 ( & V_8 -> V_15 -> V_16 , L_124
L_125 ) ;
return 1 ;
}
static T_15 F_182 ( int V_298 , void * V_410 )
{
struct V_1 * V_8 = V_410 ;
unsigned long V_44 ;
T_3 V_407 ;
if ( F_181 ( V_8 ) )
return V_411 ;
if ( F_169 ( V_8 ) )
return V_411 ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_8 -> V_412 = F_183 () ;
while ( F_168 ( V_8 ) ) {
V_407 = F_167 ( V_8 ) ;
while ( V_407 != V_62 )
V_407 = F_26 ( V_8 ) ;
}
F_21 ( & V_8 -> V_45 , V_44 ) ;
return V_413 ;
}
static T_15 F_184 ( int V_298 , void * V_410 )
{
struct V_1 * V_8 = V_410 ;
unsigned long V_44 ;
T_3 V_407 ;
if ( F_181 ( V_8 ) )
return V_411 ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_8 -> V_412 = F_183 () ;
V_407 = F_167 ( V_8 ) ;
while ( V_407 != V_62 )
V_407 = F_26 ( V_8 ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
return V_413 ;
}
static T_15 F_185 ( int V_298 , void * V_410 )
{
struct V_1 * V_8 = V_410 ;
unsigned long V_44 ;
T_3 V_407 ;
if ( F_169 ( V_8 ) )
return V_411 ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_8 -> V_412 = F_183 () ;
while ( F_168 ( V_8 ) ) {
V_407 = F_167 ( V_8 ) ;
while ( V_407 != V_62 ) {
if ( F_173 ( V_407 ) )
V_407 = F_178 ( V_8 , V_407 ) ;
else
V_407 = F_179 ( V_8 , V_407 ) ;
}
}
F_21 ( & V_8 -> V_45 , V_44 ) ;
return V_413 ;
}
static T_15 F_186 ( int V_298 , void * V_410 )
{
struct V_1 * V_8 = V_410 ;
unsigned long V_44 ;
T_3 V_407 ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_8 -> V_412 = F_183 () ;
V_407 = F_167 ( V_8 ) ;
while ( V_407 != V_62 ) {
if ( F_173 ( V_407 ) )
V_407 = F_178 ( V_8 , V_407 ) ;
else
V_407 = F_179 ( V_8 , V_407 ) ;
}
F_21 ( & V_8 -> V_45 , V_44 ) ;
return V_413 ;
}
static T_12 int F_187 ( struct V_176 * V_15 , unsigned char V_414 ,
unsigned char type )
{
struct V_415 {
struct V_416 V_417 ;
struct V_418 V_155 ;
struct V_419 V_420 ;
};
struct V_415 * V_133 ;
static const T_2 V_421 = sizeof( * V_133 ) +
sizeof( V_133 -> V_420 ) ;
V_180 V_422 ;
T_16 V_423 , V_408 ;
void T_13 * V_424 ;
int V_36 , V_332 ;
V_424 = F_188 ( V_15 , 0 ) ;
if ( V_424 == NULL )
return - V_111 ;
V_332 = F_189 ( V_15 , F_190 ( 32 ) ) ;
if ( V_332 ) {
F_191 ( V_424 ) ;
return - V_111 ;
}
V_133 = F_143 ( V_15 , V_421 , & V_422 ) ;
if ( V_133 == NULL ) {
F_191 ( V_424 ) ;
return - V_111 ;
}
V_423 = V_422 ;
V_133 -> V_417 . V_256 = 0 ;
V_133 -> V_417 . V_68 = 0 ;
V_133 -> V_417 . V_123 = 0 ;
V_133 -> V_417 . V_258 . V_126 = V_423 ;
V_133 -> V_417 . V_258 . V_127 = 0 ;
memset ( & V_133 -> V_417 . V_232 . V_257 , 0 , 8 ) ;
V_133 -> V_155 . V_263 = 16 ;
V_133 -> V_155 . Type . Type = V_198 ;
V_133 -> V_155 . Type . V_264 = V_425 ;
V_133 -> V_155 . Type . V_268 = V_273 ;
V_133 -> V_155 . V_261 = 0 ;
V_133 -> V_155 . V_156 [ 0 ] = V_414 ;
V_133 -> V_155 . V_156 [ 1 ] = type ;
memset ( & V_133 -> V_155 . V_156 [ 2 ] , 0 , 14 ) ;
V_133 -> V_420 . V_125 . V_126 = V_423 + sizeof( * V_133 ) ;
V_133 -> V_420 . V_125 . V_127 = 0 ;
V_133 -> V_420 . V_122 = sizeof( struct V_134 ) ;
F_192 ( V_423 , V_424 + V_426 ) ;
for ( V_36 = 0 ; V_36 < V_427 ; V_36 ++ ) {
V_408 = F_193 ( V_424 + V_428 ) ;
if ( ( V_408 & ~ F_177 ) == V_423 )
break;
F_139 ( V_429 ) ;
}
F_191 ( V_424 ) ;
if ( V_36 == V_427 ) {
F_44 ( & V_15 -> V_16 , L_126 ,
V_414 , type ) ;
return - V_430 ;
}
F_144 ( V_15 , V_421 , V_133 , V_422 ) ;
if ( V_408 & V_431 ) {
F_44 ( & V_15 -> V_16 , L_127 ,
V_414 , type ) ;
return - V_432 ;
}
F_45 ( & V_15 -> V_16 , L_128 ,
V_414 , type ) ;
return 0 ;
}
static int F_194 ( struct V_176 * V_15 ,
void * T_13 V_424 , T_3 V_433 )
{
V_184 V_434 ;
int V_435 ;
if ( V_433 ) {
F_45 ( & V_15 -> V_16 , L_129 ) ;
F_192 ( V_433 , V_424 + V_436 ) ;
} else {
V_435 = F_195 ( V_15 , V_437 ) ;
if ( V_435 == 0 ) {
F_44 ( & V_15 -> V_16 ,
L_130
L_131 ) ;
return - V_47 ;
}
F_45 ( & V_15 -> V_16 , L_132 ) ;
F_196 ( V_15 , V_435 + V_438 , & V_434 ) ;
V_434 &= ~ V_439 ;
V_434 |= V_440 ;
F_197 ( V_15 , V_435 + V_438 , V_434 ) ;
F_139 ( 500 ) ;
V_434 &= ~ V_439 ;
V_434 |= V_441 ;
F_197 ( V_15 , V_435 + V_438 , V_434 ) ;
F_139 ( 500 ) ;
}
return 0 ;
}
static T_12 void F_198 ( char * V_442 , int V_242 )
{
memset ( V_442 , 0 , V_242 ) ;
strncpy ( V_442 , V_17 L_133 V_370 , V_242 - 1 ) ;
}
static T_12 int F_199 (
struct V_443 T_13 * V_444 )
{
char * V_442 ;
int V_36 , V_389 = sizeof( V_444 -> V_442 ) ;
V_442 = F_74 ( V_389 , V_105 ) ;
if ( ! V_442 )
return - V_111 ;
F_198 ( V_442 , V_389 ) ;
for ( V_36 = 0 ; V_36 < V_389 ; V_36 ++ )
F_200 ( V_442 [ V_36 ] , & V_444 -> V_442 [ V_36 ] ) ;
F_52 ( V_442 ) ;
return 0 ;
}
static T_12 void F_201 (
struct V_443 T_13 * V_444 , unsigned char * V_445 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < sizeof( V_444 -> V_442 ) ; V_36 ++ )
V_445 [ V_36 ] = F_202 ( & V_444 -> V_442 [ V_36 ] ) ;
}
static T_12 int F_203 (
struct V_443 T_13 * V_444 )
{
char * V_445 , * V_446 ;
int V_192 , V_389 = sizeof( V_444 -> V_442 ) ;
V_446 = F_74 ( 2 * V_389 , V_105 ) ;
if ( ! V_446 )
return - V_111 ;
V_445 = V_446 + V_389 ;
F_198 ( V_446 , V_389 ) ;
F_201 ( V_444 , V_445 ) ;
V_192 = ! memcmp ( V_445 , V_446 , V_389 ) ;
F_52 ( V_446 ) ;
return V_192 ;
}
static T_12 int F_204 ( struct V_176 * V_15 )
{
T_4 V_447 ;
T_3 V_448 ;
T_4 V_449 ;
void T_13 * V_424 ;
unsigned long V_450 ;
T_3 V_451 ;
int V_192 ;
struct V_443 T_13 * V_444 ;
T_3 V_433 ;
T_3 V_35 ;
V_184 V_452 ;
V_192 = F_205 ( V_15 , & V_35 ) ;
if ( V_192 < 0 || ! F_15 ( V_35 ) ) {
F_5 ( & V_15 -> V_16 , L_134 ) ;
return - V_47 ;
}
if ( ! F_12 ( V_35 ) )
return - V_283 ;
F_196 ( V_15 , 4 , & V_452 ) ;
F_206 ( V_15 ) ;
F_207 ( V_15 ) ;
V_192 = F_208 ( V_15 , & V_450 ) ;
if ( V_192 )
return V_192 ;
V_424 = F_164 ( V_450 , 0x250 ) ;
if ( ! V_424 )
return - V_111 ;
V_192 = F_209 ( V_15 , V_424 , & V_448 ,
& V_449 , & V_447 ) ;
if ( V_192 )
goto V_453;
V_444 = F_164 ( F_210 ( V_15 ,
V_449 ) + V_447 , sizeof( * V_444 ) ) ;
if ( ! V_444 ) {
V_192 = - V_111 ;
goto V_453;
}
V_192 = F_199 ( V_444 ) ;
if ( V_192 )
goto V_453;
V_451 = F_193 ( & V_444 -> V_451 ) ;
V_433 = V_451 & V_454 ;
if ( V_433 ) {
V_433 = V_455 ;
} else {
V_433 = V_451 & V_456 ;
if ( V_433 ) {
F_5 ( & V_15 -> V_16 , L_135
L_136 ) ;
V_192 = - V_283 ;
goto V_457;
}
}
V_192 = F_194 ( V_15 , V_424 , V_433 ) ;
if ( V_192 )
goto V_457;
F_211 ( V_15 ) ;
V_192 = F_212 ( V_15 ) ;
if ( V_192 ) {
F_5 ( & V_15 -> V_16 , L_137 ) ;
goto V_457;
}
F_197 ( V_15 , 4 , V_452 ) ;
F_139 ( V_458 ) ;
F_45 ( & V_15 -> V_16 , L_138 ) ;
V_192 = F_213 ( V_15 , V_424 , V_459 ) ;
if ( V_192 ) {
F_5 ( & V_15 -> V_16 ,
L_139
L_140 ) ;
V_192 = - V_283 ;
goto V_457;
}
V_192 = F_213 ( V_15 , V_424 , V_460 ) ;
if ( V_192 ) {
F_5 ( & V_15 -> V_16 ,
L_141
L_142 ) ;
goto V_457;
}
V_192 = F_203 ( V_424 ) ;
if ( V_192 < 0 )
goto V_457;
if ( V_192 ) {
F_5 ( & V_15 -> V_16 , L_143
L_144 ) ;
V_192 = - V_283 ;
} else {
F_45 ( & V_15 -> V_16 , L_145 ) ;
}
V_457:
F_191 ( V_444 ) ;
V_453:
F_191 ( V_424 ) ;
return V_192 ;
}
static void F_214 ( struct V_23 * V_16 , struct V_443 * V_461 )
{
#ifdef F_215
int V_36 ;
char V_462 [ 17 ] ;
F_45 ( V_16 , L_146 ) ;
F_45 ( V_16 , L_147 ) ;
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ )
V_462 [ V_36 ] = F_202 ( & ( V_461 -> V_463 [ V_36 ] ) ) ;
V_462 [ 4 ] = '\0' ;
F_45 ( V_16 , L_148 , V_462 ) ;
F_45 ( V_16 , L_149 , F_193 ( & ( V_461 -> V_464 ) ) ) ;
F_45 ( V_16 , L_150 ,
F_193 ( & ( V_461 -> V_465 ) ) ) ;
F_45 ( V_16 , L_151 ,
F_193 ( & ( V_461 -> V_466 ) ) ) ;
F_45 ( V_16 , L_152 ,
F_193 ( & ( V_461 -> V_467 . V_468 ) ) ) ;
F_45 ( V_16 , L_153 ,
F_193 ( & ( V_461 -> V_467 . V_469 ) ) ) ;
F_45 ( V_16 , L_154 ,
F_193 ( & ( V_461 -> V_467 . V_470 ) ) ) ;
F_45 ( V_16 , L_155 ,
F_193 ( & ( V_461 -> V_471 ) ) ) ;
F_45 ( V_16 , L_156 , F_193 ( & ( V_461 -> V_472 ) ) ) ;
for ( V_36 = 0 ; V_36 < 16 ; V_36 ++ )
V_462 [ V_36 ] = F_202 ( & ( V_461 -> V_473 [ V_36 ] ) ) ;
V_462 [ 16 ] = '\0' ;
F_45 ( V_16 , L_157 , V_462 ) ;
F_45 ( V_16 , L_158 ,
F_193 ( & ( V_461 -> V_474 ) ) ) ;
#endif
}
static int F_216 ( struct V_176 * V_15 , unsigned long V_475 )
{
int V_36 , V_476 , V_477 , V_478 ;
if ( V_475 == V_479 )
return 0 ;
V_476 = 0 ;
for ( V_36 = 0 ; V_36 < V_480 ; V_36 ++ ) {
V_478 = F_217 ( V_15 , V_36 ) & V_481 ;
if ( V_478 == V_482 )
V_476 += 4 ;
else {
V_477 = F_217 ( V_15 , V_36 ) &
V_483 ;
switch ( V_477 ) {
case V_484 :
case V_485 :
V_476 += 4 ;
break;
case V_486 :
V_476 += 8 ;
break;
default:
F_5 ( & V_15 -> V_16 ,
L_159 ) ;
return - 1 ;
break;
}
}
if ( V_476 == V_475 - V_479 )
return V_36 + 1 ;
}
return - 1 ;
}
static void T_12 F_218 ( struct V_1 * V_8 )
{
#ifdef F_219
int V_332 ;
struct V_487 V_488 [ 4 ] = { { 0 , 0 } , { 0 , 1 } ,
{ 0 , 2 } , { 0 , 3 }
} ;
if ( ( V_8 -> V_35 == 0x40700E11 ) || ( V_8 -> V_35 == 0x40800E11 ) ||
( V_8 -> V_35 == 0x40820E11 ) || ( V_8 -> V_35 == 0x40830E11 ) )
goto V_489;
if ( F_195 ( V_8 -> V_15 , V_490 ) ) {
F_45 ( & V_8 -> V_15 -> V_16 , L_160 ) ;
V_332 = F_220 ( V_8 -> V_15 , V_488 , 4 ) ;
if ( ! V_332 ) {
V_8 -> V_299 [ 0 ] = V_488 [ 0 ] . V_491 ;
V_8 -> V_299 [ 1 ] = V_488 [ 1 ] . V_491 ;
V_8 -> V_299 [ 2 ] = V_488 [ 2 ] . V_491 ;
V_8 -> V_299 [ 3 ] = V_488 [ 3 ] . V_491 ;
V_8 -> V_492 = 1 ;
return;
}
if ( V_332 > 0 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_161
L_162 , V_332 ) ;
goto V_489;
} else {
F_5 ( & V_8 -> V_15 -> V_16 , L_163 ,
V_332 ) ;
goto V_489;
}
}
if ( F_195 ( V_8 -> V_15 , V_493 ) ) {
F_45 ( & V_8 -> V_15 -> V_16 , L_164 ) ;
if ( ! F_221 ( V_8 -> V_15 ) )
V_8 -> V_494 = 1 ;
else
F_5 ( & V_8 -> V_15 -> V_16 , L_165 ) ;
}
V_489:
#endif
V_8 -> V_299 [ V_8 -> V_300 ] = V_8 -> V_15 -> V_298 ;
}
static int T_12 F_205 ( struct V_176 * V_15 , T_3 * V_35 )
{
int V_36 ;
T_3 V_495 , V_496 ;
V_495 = V_15 -> V_497 ;
V_496 = V_15 -> V_498 ;
* V_35 = ( ( V_496 << 16 ) & 0xffff0000 ) |
V_495 ;
for ( V_36 = 0 ; V_36 < F_13 ( V_499 ) ; V_36 ++ )
if ( * V_35 == V_499 [ V_36 ] . V_35 )
return V_36 ;
if ( ( V_495 != V_500 &&
V_495 != V_501 ) ||
! V_502 ) {
F_5 ( & V_15 -> V_16 , L_166
L_167 , * V_35 ) ;
return - V_47 ;
}
return F_13 ( V_499 ) - 1 ;
}
static inline bool F_222 ( struct V_176 * V_15 )
{
V_184 V_503 ;
( void ) F_196 ( V_15 , V_504 , & V_503 ) ;
return ( ( V_503 & V_505 ) == 0 ) ;
}
static int T_12 F_208 ( struct V_176 * V_15 ,
unsigned long * V_506 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_480 ; V_36 ++ )
if ( F_217 ( V_15 , V_36 ) & V_507 ) {
* V_506 = F_210 ( V_15 , V_36 ) ;
F_223 ( & V_15 -> V_16 , L_168 ,
* V_506 ) ;
return 0 ;
}
F_5 ( & V_15 -> V_16 , L_169 ) ;
return - V_47 ;
}
static int T_12 F_213 ( struct V_176 * V_15 ,
void T_13 * V_424 , int V_508 )
{
int V_36 , V_509 ;
T_3 V_510 ;
if ( V_508 )
V_509 = V_511 ;
else
V_509 = V_512 ;
for ( V_36 = 0 ; V_36 < V_509 ; V_36 ++ ) {
V_510 = F_193 ( V_424 + V_513 ) ;
if ( V_508 ) {
if ( V_510 == V_514 )
return 0 ;
} else {
if ( V_510 != V_514 )
return 0 ;
}
F_139 ( V_515 ) ;
}
F_5 ( & V_15 -> V_16 , L_170 ) ;
return - V_47 ;
}
static int T_12 F_209 ( struct V_176 * V_15 ,
void T_13 * V_424 , T_3 * V_448 , T_4 * V_449 ,
T_4 * V_447 )
{
* V_448 = F_193 ( V_424 + V_516 ) ;
* V_447 = F_193 ( V_424 + V_517 ) ;
* V_448 &= ( T_3 ) 0x0000ffff ;
* V_449 = F_216 ( V_15 , * V_448 ) ;
if ( * V_449 == - 1 ) {
F_5 ( & V_15 -> V_16 , L_171 ) ;
return - V_47 ;
}
return 0 ;
}
static int T_12 F_224 ( struct V_1 * V_8 )
{
T_4 V_447 ;
T_3 V_448 ;
T_4 V_449 ;
T_3 V_518 ;
int V_192 ;
V_192 = F_209 ( V_8 -> V_15 , V_8 -> V_424 , & V_448 ,
& V_449 , & V_447 ) ;
if ( V_192 )
return V_192 ;
V_8 -> V_444 = F_164 ( F_210 ( V_8 -> V_15 ,
V_449 ) + V_447 , sizeof( * V_8 -> V_444 ) ) ;
if ( ! V_8 -> V_444 )
return - V_111 ;
V_192 = F_199 ( V_8 -> V_444 ) ;
if ( V_192 )
return V_192 ;
V_518 = F_193 ( & V_8 -> V_444 -> V_519 ) ;
V_8 -> V_520 = F_164 ( F_210 ( V_8 -> V_15 ,
V_449 ) + V_447 + V_518 ,
sizeof( * V_8 -> V_520 ) ) ;
if ( ! V_8 -> V_520 )
return - V_111 ;
return 0 ;
}
static void T_12 F_225 ( struct V_1 * V_8 )
{
V_8 -> V_64 = F_193 ( & ( V_8 -> V_444 -> V_521 ) ) ;
if ( V_409 && V_8 -> V_64 > 32 )
V_8 -> V_64 = 32 ;
if ( V_8 -> V_64 < 16 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_172
L_173
L_174 ,
V_8 -> V_64 ) ;
V_8 -> V_64 = 16 ;
}
}
static void T_12 F_226 ( struct V_1 * V_8 )
{
F_225 ( V_8 ) ;
V_8 -> V_109 = V_8 -> V_64 - 4 ;
V_8 -> V_249 = F_193 ( & ( V_8 -> V_444 -> V_522 ) ) ;
V_8 -> V_118 = 31 ;
if ( V_8 -> V_249 > 512 ) {
V_8 -> V_118 = 32 ;
V_8 -> V_110 = V_8 -> V_249 - V_8 -> V_118 + 1 ;
V_8 -> V_249 -- ;
} else {
V_8 -> V_249 = 31 ;
V_8 -> V_110 = 0 ;
}
}
static inline bool F_227 ( struct V_1 * V_8 )
{
if ( ( F_202 ( & V_8 -> V_444 -> V_463 [ 0 ] ) != 'C' ) ||
( F_202 ( & V_8 -> V_444 -> V_463 [ 1 ] ) != 'I' ) ||
( F_202 ( & V_8 -> V_444 -> V_463 [ 2 ] ) != 'S' ) ||
( F_202 ( & V_8 -> V_444 -> V_463 [ 3 ] ) != 'S' ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_175 ) ;
return false ;
}
return true ;
}
static inline void F_228 ( struct V_1 * V_8 )
{
#ifdef F_229
T_3 V_523 ;
V_523 = F_193 ( & ( V_8 -> V_444 -> V_524 ) ) ;
V_523 |= 0x100 ;
F_192 ( V_523 , & ( V_8 -> V_444 -> V_524 ) ) ;
#endif
}
static inline void F_230 ( struct V_1 * V_8 )
{
T_3 V_525 ;
if ( V_8 -> V_35 != 0x3225103C )
return;
V_525 = F_193 ( V_8 -> V_424 + V_526 ) ;
V_525 |= 0x8000 ;
F_192 ( V_525 , V_8 -> V_424 + V_526 ) ;
}
static void T_12 F_231 ( struct V_1 * V_8 )
{
int V_36 ;
T_3 V_527 ;
unsigned long V_44 ;
for ( V_36 = 0 ; V_36 < V_528 ; V_36 ++ ) {
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_527 = F_193 ( V_8 -> V_424 + V_436 ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
if ( ! ( V_527 & V_529 ) )
break;
F_232 ( 10000 , 20000 ) ;
}
}
static int T_12 F_233 ( struct V_1 * V_8 )
{
T_3 V_530 ;
V_530 = F_193 ( & ( V_8 -> V_444 -> V_465 ) ) ;
if ( ! ( V_530 & V_531 ) )
return - V_283 ;
V_8 -> V_64 = F_193 ( & ( V_8 -> V_444 -> V_471 ) ) ;
F_192 ( V_532 , & ( V_8 -> V_444 -> V_467 . V_468 ) ) ;
F_192 ( V_529 , V_8 -> V_424 + V_436 ) ;
F_231 ( V_8 ) ;
F_214 ( & V_8 -> V_15 -> V_16 , V_8 -> V_444 ) ;
if ( ! ( F_193 ( & ( V_8 -> V_444 -> V_466 ) ) & V_532 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_176 ) ;
return - V_47 ;
}
V_8 -> V_33 = V_532 ;
return 0 ;
}
static int T_12 F_234 ( struct V_1 * V_8 )
{
int V_533 , V_332 ;
V_533 = F_205 ( V_8 -> V_15 , & V_8 -> V_35 ) ;
if ( V_533 < 0 )
return - V_47 ;
V_8 -> V_534 = V_499 [ V_533 ] . V_534 ;
V_8 -> V_58 = * ( V_499 [ V_533 ] . V_58 ) ;
if ( F_222 ( V_8 -> V_15 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_177 ) ;
return - V_47 ;
}
F_235 ( V_8 -> V_15 , V_535 |
V_536 | V_537 ) ;
V_332 = F_212 ( V_8 -> V_15 ) ;
if ( V_332 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_178 ) ;
return V_332 ;
}
V_332 = F_236 ( V_8 -> V_15 , V_17 ) ;
if ( V_332 ) {
F_44 ( & V_8 -> V_15 -> V_16 ,
L_179 ) ;
return V_332 ;
}
F_218 ( V_8 ) ;
V_332 = F_208 ( V_8 -> V_15 , & V_8 -> V_450 ) ;
if ( V_332 )
goto V_538;
V_8 -> V_424 = F_164 ( V_8 -> V_450 , 0x250 ) ;
if ( ! V_8 -> V_424 ) {
V_332 = - V_111 ;
goto V_538;
}
V_332 = F_213 ( V_8 -> V_15 , V_8 -> V_424 , V_460 ) ;
if ( V_332 )
goto V_538;
V_332 = F_224 ( V_8 ) ;
if ( V_332 )
goto V_538;
F_226 ( V_8 ) ;
if ( ! F_227 ( V_8 ) ) {
V_332 = - V_47 ;
goto V_538;
}
F_228 ( V_8 ) ;
F_230 ( V_8 ) ;
V_332 = F_233 ( V_8 ) ;
if ( V_332 )
goto V_538;
return 0 ;
V_538:
if ( V_8 -> V_520 )
F_191 ( V_8 -> V_520 ) ;
if ( V_8 -> V_444 )
F_191 ( V_8 -> V_444 ) ;
if ( V_8 -> V_424 )
F_191 ( V_8 -> V_424 ) ;
F_237 ( V_8 -> V_15 ) ;
return V_332 ;
}
static void T_12 F_238 ( struct V_1 * V_8 )
{
int V_192 ;
#define F_239 64
V_8 -> V_31 = F_74 ( F_239 , V_105 ) ;
if ( ! V_8 -> V_31 )
return;
V_192 = F_91 ( V_8 , V_71 , 0 ,
V_8 -> V_31 , F_239 ) ;
if ( V_192 != 0 ) {
F_52 ( V_8 -> V_31 ) ;
V_8 -> V_31 = NULL ;
}
}
static T_12 int F_240 ( struct V_176 * V_15 )
{
int V_192 , V_36 ;
if ( ! V_409 )
return 0 ;
V_192 = F_204 ( V_15 ) ;
if ( V_192 == - V_283 )
return V_192 ;
if ( V_192 )
return - V_47 ;
F_5 ( & V_15 -> V_16 , L_180 ) ;
for ( V_36 = 0 ; V_36 < V_539 ; V_36 ++ ) {
if ( F_241 ( V_15 ) == 0 )
break;
else
F_5 ( & V_15 -> V_16 , L_181 ,
( V_36 < 11 ? L_182 : L_183 ) ) ;
}
return 0 ;
}
static T_12 int F_242 ( struct V_1 * V_8 )
{
V_8 -> V_318 = F_62 (
F_243 ( V_8 -> V_109 , V_319 ) *
sizeof( unsigned long ) , V_105 ) ;
V_8 -> V_320 = F_143 ( V_8 -> V_15 ,
V_8 -> V_109 * sizeof( * V_8 -> V_320 ) ,
& ( V_8 -> V_321 ) ) ;
V_8 -> V_322 = F_143 ( V_8 -> V_15 ,
V_8 -> V_109 * sizeof( * V_8 -> V_322 ) ,
& ( V_8 -> V_323 ) ) ;
if ( ( V_8 -> V_318 == NULL )
|| ( V_8 -> V_320 == NULL )
|| ( V_8 -> V_322 == NULL ) ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_184 , V_303 ) ;
return - V_111 ;
}
return 0 ;
}
static void F_244 ( struct V_1 * V_8 )
{
F_52 ( V_8 -> V_318 ) ;
if ( V_8 -> V_320 )
F_144 ( V_8 -> V_15 ,
V_8 -> V_109 * sizeof( struct V_9 ) ,
V_8 -> V_320 , V_8 -> V_321 ) ;
if ( V_8 -> V_322 )
F_144 ( V_8 -> V_15 ,
V_8 -> V_109 * sizeof( struct V_134 ) ,
V_8 -> V_322 ,
V_8 -> V_323 ) ;
}
static int F_245 ( struct V_1 * V_8 ,
T_15 (* F_246)( int , void * ) ,
T_15 (* F_247)( int , void * ) )
{
int V_192 ;
if ( V_8 -> V_492 || V_8 -> V_494 )
V_192 = F_248 ( V_8 -> V_299 [ V_8 -> V_300 ] , F_246 ,
0 , V_8 -> V_540 , V_8 ) ;
else
V_192 = F_248 ( V_8 -> V_299 [ V_8 -> V_300 ] , F_247 ,
V_541 , V_8 -> V_540 , V_8 ) ;
if ( V_192 ) {
F_44 ( & V_8 -> V_15 -> V_16 , L_185 ,
V_8 -> V_299 [ V_8 -> V_300 ] , V_8 -> V_540 ) ;
return - V_47 ;
}
return 0 ;
}
static int T_12 F_249 ( struct V_1 * V_8 )
{
if ( F_163 ( V_8 , V_71 ,
V_542 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_186 ) ;
return - V_432 ;
}
F_45 ( & V_8 -> V_15 -> V_16 , L_187 ) ;
if ( F_213 ( V_8 -> V_15 , V_8 -> V_424 , V_459 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_188 ) ;
return - 1 ;
}
F_45 ( & V_8 -> V_15 -> V_16 , L_189 ) ;
if ( F_213 ( V_8 -> V_15 , V_8 -> V_424 , V_460 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_190
L_191 ) ;
return - 1 ;
}
return 0 ;
}
static void F_250 ( struct V_1 * V_8 )
{
F_251 ( V_8 -> V_299 [ V_8 -> V_300 ] , V_8 ) ;
#ifdef F_219
if ( V_8 -> V_492 )
F_252 ( V_8 -> V_15 ) ;
else if ( V_8 -> V_494 )
F_253 ( V_8 -> V_15 ) ;
#endif
F_72 ( V_8 ) ;
F_244 ( V_8 ) ;
F_52 ( V_8 -> V_66 ) ;
F_144 ( V_8 -> V_15 , V_8 -> V_543 ,
V_8 -> V_63 , V_8 -> V_544 ) ;
if ( V_8 -> V_424 )
F_191 ( V_8 -> V_424 ) ;
if ( V_8 -> V_520 )
F_191 ( V_8 -> V_520 ) ;
if ( V_8 -> V_444 )
F_191 ( V_8 -> V_444 ) ;
F_237 ( V_8 -> V_15 ) ;
F_52 ( V_8 ) ;
}
static void F_254 ( struct V_1 * V_8 )
{
F_255 ( & V_545 ) ;
if ( ! V_546 )
return;
if ( V_8 -> V_187 )
return;
F_256 ( & V_8 -> V_547 ) ;
}
static void F_257 ( struct V_1 * V_8 , struct V_55 * V_56 )
{
struct V_9 * V_10 = NULL ;
F_255 ( & V_8 -> V_45 ) ;
while ( ! F_34 ( V_56 ) ) {
V_10 = F_166 ( V_56 -> V_400 , struct V_9 , V_56 ) ;
V_10 -> V_11 -> V_149 = V_166 ;
F_171 ( V_10 , V_10 -> V_67 . V_258 . V_126 ) ;
}
}
static void F_258 ( struct V_1 * V_8 )
{
unsigned long V_44 ;
F_255 ( & V_545 ) ;
F_254 ( V_8 ) ;
V_8 -> V_58 . V_548 ( V_8 , V_549 ) ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_8 -> V_187 = F_193 ( V_8 -> V_424 + V_513 ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
F_5 ( & V_8 -> V_15 -> V_16 , L_192 ,
V_8 -> V_187 ) ;
F_206 ( V_8 -> V_15 ) ;
F_20 ( & V_8 -> V_45 , V_44 ) ;
F_257 ( V_8 , & V_8 -> V_403 ) ;
F_257 ( V_8 , & V_8 -> V_69 ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
}
static void F_259 ( struct V_1 * V_8 )
{
T_4 V_550 ;
T_3 V_551 ;
unsigned long V_44 ;
F_255 ( & V_545 ) ;
V_550 = F_183 () ;
if ( F_260 ( V_8 -> V_412 +
( V_552 ) , V_550 ) )
return;
if ( F_260 ( V_8 -> V_553 +
( V_552 ) , V_550 ) )
return;
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_551 = F_193 ( & V_8 -> V_444 -> V_474 ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
if ( V_8 -> V_554 == V_551 ) {
F_258 ( V_8 ) ;
return;
}
V_8 -> V_554 = V_551 ;
V_8 -> V_553 = V_550 ;
}
static int F_261 ( void * V_555 )
{
struct V_1 * V_8 ;
unsigned long V_44 ;
while ( 1 ) {
struct V_55 * V_556 , * V_557 ;
F_262 ( V_558 ) ;
if ( F_263 () )
break;
F_20 ( & V_545 , V_44 ) ;
F_264 (this, tmp, &hpsa_ctlr_list) {
V_8 = F_166 ( V_556 , struct V_1 , V_547 ) ;
F_259 ( V_8 ) ;
}
F_21 ( & V_545 , V_44 ) ;
}
return 0 ;
}
static void F_265 ( struct V_1 * V_8 )
{
unsigned long V_44 ;
F_20 ( & V_545 , V_44 ) ;
F_25 ( & V_8 -> V_547 , & V_559 ) ;
F_21 ( & V_545 , V_44 ) ;
}
static void F_266 ( struct V_1 * V_8 )
{
if ( ! V_546 ) {
F_267 ( & V_545 ) ;
V_546 =
F_268 ( F_261 ,
NULL , V_17 ) ;
}
if ( ! V_546 ) {
F_5 ( & V_8 -> V_15 -> V_16 ,
L_193 ) ;
return;
}
F_265 ( V_8 ) ;
}
static void F_269 ( struct V_1 * V_8 )
{
unsigned long V_44 ;
F_20 ( & V_545 , V_44 ) ;
F_254 ( V_8 ) ;
if ( F_34 ( & V_559 ) ) {
F_21 ( & V_545 , V_44 ) ;
F_270 ( V_546 ) ;
F_20 ( & V_545 , V_44 ) ;
V_546 = NULL ;
}
F_21 ( & V_545 , V_44 ) ;
}
static int T_12 F_271 ( struct V_176 * V_15 ,
const struct V_560 * V_561 )
{
int V_562 , V_192 ;
struct V_1 * V_8 ;
int V_563 = 0 ;
unsigned long V_44 ;
if ( V_564 == 0 )
F_272 (KERN_INFO DRIVER_NAME L_194 ) ;
V_192 = F_240 ( V_15 ) ;
if ( V_192 ) {
if ( V_192 != - V_283 )
return V_192 ;
V_563 = 1 ;
V_192 = 0 ;
}
V_565:
#define F_273 32
F_274 ( sizeof( struct V_9 ) % F_273 ) ;
V_8 = F_62 ( sizeof( * V_8 ) , V_105 ) ;
if ( ! V_8 )
return - V_111 ;
V_8 -> V_15 = V_15 ;
V_8 -> V_300 = V_566 ? V_567 : V_568 ;
F_142 ( & V_8 -> V_403 ) ;
F_142 ( & V_8 -> V_69 ) ;
F_267 ( & V_8 -> V_45 ) ;
F_267 ( & V_8 -> V_278 ) ;
V_192 = F_234 ( V_8 ) ;
if ( V_192 != 0 )
goto V_569;
sprintf ( V_8 -> V_540 , V_17 L_195 , V_564 ) ;
V_8 -> V_18 = V_564 ;
V_564 ++ ;
V_192 = F_275 ( V_15 , F_190 ( 64 ) ) ;
if ( V_192 == 0 ) {
V_562 = 1 ;
} else {
V_192 = F_275 ( V_15 , F_190 ( 32 ) ) ;
if ( V_192 == 0 ) {
V_562 = 0 ;
} else {
F_44 ( & V_15 -> V_16 , L_196 ) ;
goto V_569;
}
}
V_8 -> V_58 . V_548 ( V_8 , V_549 ) ;
if ( F_245 ( V_8 , F_186 , F_185 ) )
goto V_570;
F_45 ( & V_15 -> V_16 , L_197 ,
V_8 -> V_540 , V_15 -> V_23 ,
V_8 -> V_299 [ V_8 -> V_300 ] , V_562 ? L_183 : L_198 ) ;
if ( F_242 ( V_8 ) )
goto V_571;
if ( F_73 ( V_8 ) )
goto V_571;
F_276 ( & V_8 -> V_572 ) ;
V_8 -> V_279 = 1 ;
F_277 ( V_15 , V_8 ) ;
V_8 -> V_78 = 0 ;
V_8 -> V_29 = NULL ;
F_267 ( & V_8 -> V_107 ) ;
F_278 ( V_8 ) ;
if ( V_563 ) {
F_20 ( & V_8 -> V_45 , V_44 ) ;
V_8 -> V_58 . V_548 ( V_8 , V_549 ) ;
F_21 ( & V_8 -> V_45 , V_44 ) ;
F_251 ( V_8 -> V_299 [ V_8 -> V_300 ] , V_8 ) ;
V_192 = F_245 ( V_8 , F_184 ,
F_182 ) ;
if ( V_192 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_199
L_200 ) ;
goto V_571;
}
V_192 = F_249 ( V_8 ) ;
if ( V_192 )
goto V_571;
F_45 ( & V_8 -> V_15 -> V_16 , L_201 ) ;
F_45 ( & V_8 -> V_15 -> V_16 ,
L_202 ) ;
V_8 -> V_58 . V_548 ( V_8 , V_573 ) ;
F_139 ( 10000 ) ;
V_8 -> V_58 . V_548 ( V_8 , V_549 ) ;
V_192 = F_203 ( V_8 -> V_444 ) ;
if ( V_192 )
F_45 ( & V_8 -> V_15 -> V_16 ,
L_203 ) ;
F_250 ( V_8 ) ;
V_563 = 0 ;
if ( V_192 )
return - V_47 ;
goto V_565;
}
V_8 -> V_58 . V_548 ( V_8 , V_573 ) ;
F_238 ( V_8 ) ;
F_134 ( V_8 ) ;
F_266 ( V_8 ) ;
return 1 ;
V_571:
F_72 ( V_8 ) ;
F_244 ( V_8 ) ;
F_251 ( V_8 -> V_299 [ V_8 -> V_300 ] , V_8 ) ;
V_570:
V_569:
F_52 ( V_8 ) ;
return V_192 ;
}
static void F_279 ( struct V_1 * V_8 )
{
char * V_574 ;
struct V_9 * V_10 ;
V_574 = F_62 ( 4 , V_105 ) ;
if ( ! V_574 )
return;
V_10 = F_92 ( V_8 ) ;
if ( ! V_10 ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_86 ) ;
goto V_575;
}
F_93 ( V_10 , V_392 , V_8 , V_574 , 4 , 0 ,
V_71 , V_195 ) ;
F_89 ( V_8 , V_10 , V_124 ) ;
if ( V_10 -> V_11 -> V_149 != 0 )
F_5 ( & V_8 -> V_15 -> V_16 ,
L_204 ) ;
F_94 ( V_8 , V_10 ) ;
V_575:
F_52 ( V_574 ) ;
}
static void F_280 ( struct V_176 * V_15 )
{
struct V_1 * V_8 ;
V_8 = F_281 ( V_15 ) ;
F_279 ( V_8 ) ;
V_8 -> V_58 . V_548 ( V_8 , V_549 ) ;
F_251 ( V_8 -> V_299 [ V_8 -> V_300 ] , V_8 ) ;
#ifdef F_219
if ( V_8 -> V_492 )
F_252 ( V_8 -> V_15 ) ;
else if ( V_8 -> V_494 )
F_253 ( V_8 -> V_15 ) ;
#endif
}
static void T_17 F_282 ( struct V_1 * V_8 )
{
int V_36 ;
for ( V_36 = 0 ; V_36 < V_8 -> V_78 ; V_36 ++ )
F_52 ( V_8 -> V_16 [ V_36 ] ) ;
}
static void T_17 F_283 ( struct V_176 * V_15 )
{
struct V_1 * V_8 ;
if ( F_281 ( V_15 ) == NULL ) {
F_44 ( & V_15 -> V_16 , L_205 ) ;
return;
}
V_8 = F_281 ( V_15 ) ;
F_269 ( V_8 ) ;
F_131 ( V_8 ) ;
F_280 ( V_15 ) ;
F_191 ( V_8 -> V_424 ) ;
F_191 ( V_8 -> V_520 ) ;
F_191 ( V_8 -> V_444 ) ;
F_282 ( V_8 ) ;
F_72 ( V_8 ) ;
F_144 ( V_8 -> V_15 ,
V_8 -> V_109 * sizeof( struct V_9 ) ,
V_8 -> V_320 , V_8 -> V_321 ) ;
F_144 ( V_8 -> V_15 ,
V_8 -> V_109 * sizeof( struct V_134 ) ,
V_8 -> V_322 , V_8 -> V_323 ) ;
F_144 ( V_8 -> V_15 , V_8 -> V_543 ,
V_8 -> V_63 , V_8 -> V_544 ) ;
F_52 ( V_8 -> V_318 ) ;
F_52 ( V_8 -> V_66 ) ;
F_52 ( V_8 -> V_31 ) ;
F_237 ( V_15 ) ;
F_277 ( V_15 , NULL ) ;
F_52 ( V_8 ) ;
}
static void F_284 ( int V_576 [] , int V_577 ,
int V_578 , int * V_579 )
{
int V_36 , V_92 , V_580 , V_389 ;
#define F_285 4
#define F_286 8
for ( V_36 = 0 ; V_36 <= V_578 ; V_36 ++ ) {
V_389 = V_36 + F_285 ;
V_580 = V_577 ;
for ( V_92 = 0 ; V_92 < 8 ; V_92 ++ ) {
if ( V_576 [ V_92 ] >= V_389 ) {
V_580 = V_92 ;
break;
}
}
V_579 [ V_36 ] = V_580 ;
}
}
static T_12 void F_287 ( struct V_1 * V_8 ,
T_3 V_581 )
{
int V_36 ;
unsigned long V_582 ;
int V_583 [ 8 ] = { 5 , 6 , 8 , 10 , 12 , 20 , 28 , V_385 + 4 } ;
F_274 ( 28 > V_385 + 4 ) ;
V_8 -> V_61 = 1 ;
memset ( V_8 -> V_63 , 0 , V_8 -> V_543 ) ;
V_8 -> V_60 = V_8 -> V_63 ;
V_583 [ 7 ] = V_385 + 4 ;
F_284 ( V_583 , F_13 ( V_583 ) ,
V_385 , V_8 -> V_66 ) ;
for ( V_36 = 0 ; V_36 < 8 ; V_36 ++ )
F_192 ( V_583 [ V_36 ] , & V_8 -> V_520 -> V_584 [ V_36 ] ) ;
F_192 ( V_8 -> V_64 , & V_8 -> V_520 -> V_585 ) ;
F_192 ( 1 , & V_8 -> V_520 -> V_586 ) ;
F_192 ( 0 , & V_8 -> V_520 -> V_587 ) ;
F_192 ( 0 , & V_8 -> V_520 -> V_588 ) ;
F_192 ( V_8 -> V_544 , & V_8 -> V_520 -> V_589 ) ;
F_192 ( 0 , & V_8 -> V_520 -> V_590 ) ;
F_192 ( V_34 | V_581 ,
& ( V_8 -> V_444 -> V_467 . V_468 ) ) ;
F_192 ( V_529 , V_8 -> V_424 + V_436 ) ;
F_231 ( V_8 ) ;
V_582 = F_193 ( & ( V_8 -> V_444 -> V_466 ) ) ;
if ( ! ( V_582 & V_34 ) ) {
F_5 ( & V_8 -> V_15 -> V_16 , L_206
L_207 ) ;
return;
}
V_8 -> V_58 = V_591 ;
V_8 -> V_33 = V_34 ;
}
static T_12 void F_278 ( struct V_1 * V_8 )
{
T_3 V_530 ;
if ( V_566 )
return;
V_530 = F_193 ( & ( V_8 -> V_444 -> V_465 ) ) ;
if ( ! ( V_530 & V_592 ) )
return;
F_225 ( V_8 ) ;
V_8 -> V_543 = V_8 -> V_64 * sizeof( T_4 ) ;
V_8 -> V_63 = F_143 ( V_8 -> V_15 , V_8 -> V_543 ,
& ( V_8 -> V_544 ) ) ;
V_8 -> V_66 = F_74 ( ( ( V_385 + 1 ) *
sizeof( T_3 ) ) , V_105 ) ;
if ( ( V_8 -> V_63 == NULL )
|| ( V_8 -> V_66 == NULL ) )
goto V_593;
F_287 ( V_8 ,
V_530 & V_594 ) ;
return;
V_593:
if ( V_8 -> V_63 )
F_144 ( V_8 -> V_15 , V_8 -> V_543 ,
V_8 -> V_63 , V_8 -> V_544 ) ;
F_52 ( V_8 -> V_66 ) ;
}
static int T_18 F_288 ( void )
{
return F_289 ( & V_595 ) ;
}
static void T_19 F_290 ( void )
{
F_291 ( & V_595 ) ;
}

static inline T_1 F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 ;
}
static inline unsigned char F_2 ( struct V_1 * V_2 , T_1 V_5 )
{
return V_2 -> F_2 [ V_5 & ( V_6 - 1 ) ] ;
}
static inline unsigned char * F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
return & V_2 -> F_2 [ V_5 & ( V_6 - 1 ) ] ;
}
static inline unsigned char F_4 ( struct V_1 * V_2 , T_1 V_5 )
{
return V_2 -> F_4 [ V_5 & ( V_6 - 1 ) ] ;
}
static inline unsigned char * F_5 ( struct V_1 * V_2 , T_1 V_5 )
{
return & V_2 -> F_4 [ V_5 & ( V_6 - 1 ) ] ;
}
static inline int F_6 ( struct V_7 * V_8 , unsigned char V_9 ,
unsigned char T_2 * V_10 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
F_7 ( V_8 , & V_9 , 1 , V_2 -> V_12 ) ;
return F_8 ( V_9 , V_10 ) ;
}
static int F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_13 ;
if ( F_10 ( V_8 ) ) {
V_13 = V_6 - F_1 ( V_2 ) * 3 - 1 ;
} else
V_13 = V_6 - F_1 ( V_2 ) - 1 ;
if ( V_13 <= 0 )
V_13 = V_2 -> V_12 && V_2 -> V_14 == V_2 -> V_4 ;
return V_13 ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_12 ( V_2 -> V_15 ) && F_9 ( V_8 ) ) {
V_2 -> V_15 = 0 ;
F_13 ( V_8 -> V_16 -> V_17 == NULL ,
L_1 ) ;
F_13 ( F_14 ( V_18 , & V_8 -> V_19 ) ,
L_2 ) ;
F_15 ( V_20 , & V_8 -> V_16 -> V_21 . V_22 ) ;
}
}
static T_3 F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_3 V_23 = 0 ;
if ( ! V_2 -> V_12 )
V_23 = F_1 ( V_2 ) ;
else
V_23 = V_2 -> V_14 - V_2 -> V_4 ;
return V_23 ;
}
static void F_17 ( struct V_7 * V_8 )
{
if ( V_8 -> V_24 && F_18 ( V_25 , & V_8 -> V_19 ) )
F_19 ( & V_8 -> V_24 , V_26 , V_27 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
if ( V_8 -> V_28 -> type == V_29 )
return;
while ( 1 ) {
int V_30 ;
F_21 ( V_8 , V_31 ) ;
if ( F_9 ( V_8 ) >= V_32 )
break;
V_30 = F_22 ( V_8 ) ;
if ( ! V_30 )
break;
}
F_23 ( V_8 , 0 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
if ( V_8 -> V_28 -> type == V_29 &&
V_8 -> V_33 -> V_34 -> V_35 -> V_36 == F_17 ) {
if ( F_16 ( V_8 ) > V_37 )
return;
if ( ! V_8 -> V_38 )
return;
F_11 ( V_8 ) ;
F_17 ( V_8 -> V_33 ) ;
if ( F_25 ( & V_8 -> V_33 -> V_39 ) )
F_26 ( & V_8 -> V_33 -> V_39 , V_40 ) ;
return;
}
while ( 1 ) {
int V_41 ;
F_21 ( V_8 , V_42 ) ;
if ( F_16 ( V_8 ) > V_37 )
break;
if ( ! V_8 -> V_38 )
break;
F_11 ( V_8 ) ;
V_41 = F_27 ( V_8 ) ;
if ( ! V_41 )
break;
}
F_23 ( V_8 , 0 ) ;
}
static inline void F_28 ( unsigned char V_43 , struct V_1 * V_2 )
{
* F_3 ( V_2 , V_2 -> V_3 ) = V_43 ;
V_2 -> V_3 ++ ;
}
static void F_29 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_14 = V_2 -> V_4 = 0 ;
V_2 -> V_44 = V_2 -> V_45 = V_2 -> V_46 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0 ;
F_30 ( V_2 -> V_50 , V_6 ) ;
V_2 -> V_51 = 0 ;
}
static void F_31 ( struct V_7 * V_8 )
{
unsigned long V_19 ;
if ( V_8 -> V_33 -> V_52 ) {
F_32 ( & V_8 -> V_53 , V_19 ) ;
V_8 -> V_54 |= V_55 ;
F_33 ( & V_8 -> V_53 , V_19 ) ;
if ( F_25 ( & V_8 -> V_33 -> V_56 ) )
F_34 ( & V_8 -> V_33 -> V_56 ) ;
}
}
static void F_35 ( struct V_7 * V_8 )
{
F_36 ( & V_8 -> V_57 ) ;
F_29 ( V_8 -> V_11 ) ;
F_11 ( V_8 ) ;
if ( V_8 -> V_33 )
F_31 ( V_8 ) ;
F_37 ( & V_8 -> V_57 ) ;
}
static T_3 F_38 ( struct V_7 * V_8 )
{
T_3 V_23 ;
F_39 ( 1 , L_3 , V_58 ) ;
F_36 ( & V_8 -> V_57 ) ;
V_23 = F_16 ( V_8 ) ;
F_37 ( & V_8 -> V_57 ) ;
return V_23 ;
}
static inline int F_40 ( unsigned char V_43 )
{
return ( V_43 & 0xc0 ) == 0x80 ;
}
static inline int F_41 ( unsigned char V_43 , struct V_7 * V_8 )
{
return F_42 ( V_8 ) && F_40 ( V_43 ) ;
}
static int F_43 ( unsigned char V_43 , struct V_7 * V_8 , int V_59 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_60 ;
if ( ! V_59 )
return - 1 ;
switch ( V_43 ) {
case '\n' :
if ( F_44 ( V_8 ) )
V_2 -> V_61 = 0 ;
if ( F_45 ( V_8 ) ) {
if ( V_59 < 2 )
return - 1 ;
V_2 -> V_62 = V_2 -> V_61 = 0 ;
V_8 -> V_35 -> V_63 ( V_8 , L_4 , 2 ) ;
return 2 ;
}
V_2 -> V_62 = V_2 -> V_61 ;
break;
case '\r' :
if ( F_46 ( V_8 ) && V_2 -> V_61 == 0 )
return 0 ;
if ( F_47 ( V_8 ) ) {
V_43 = '\n' ;
if ( F_44 ( V_8 ) )
V_2 -> V_62 = V_2 -> V_61 = 0 ;
break;
}
V_2 -> V_62 = V_2 -> V_61 = 0 ;
break;
case '\t' :
V_60 = 8 - ( V_2 -> V_61 & 7 ) ;
if ( F_48 ( V_8 ) == V_64 ) {
if ( V_59 < V_60 )
return - 1 ;
V_2 -> V_61 += V_60 ;
V_8 -> V_35 -> V_63 ( V_8 , L_5 , V_60 ) ;
return V_60 ;
}
V_2 -> V_61 += V_60 ;
break;
case '\b' :
if ( V_2 -> V_61 > 0 )
V_2 -> V_61 -- ;
break;
default:
if ( ! iscntrl ( V_43 ) ) {
if ( F_49 ( V_8 ) )
V_43 = toupper ( V_43 ) ;
if ( ! F_41 ( V_43 , V_8 ) )
V_2 -> V_61 ++ ;
}
break;
}
F_50 ( V_8 , V_43 ) ;
return 1 ;
}
static int F_51 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_59 , V_65 ;
F_52 ( & V_2 -> V_66 ) ;
V_59 = F_53 ( V_8 ) ;
V_65 = F_43 ( V_43 , V_8 , V_59 ) ;
F_54 ( & V_2 -> V_66 ) ;
if ( V_65 < 0 )
return - 1 ;
else
return 0 ;
}
static T_3 F_55 ( struct V_7 * V_8 ,
const unsigned char * V_21 , unsigned int V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_59 ;
int V_5 ;
const unsigned char * V_68 ;
F_52 ( & V_2 -> V_66 ) ;
V_59 = F_53 ( V_8 ) ;
if ( ! V_59 ) {
F_54 ( & V_2 -> V_66 ) ;
return 0 ;
}
if ( V_67 > V_59 )
V_67 = V_59 ;
for ( V_5 = 0 , V_68 = V_21 ; V_5 < V_67 ; V_5 ++ , V_68 ++ ) {
unsigned char V_43 = * V_68 ;
switch ( V_43 ) {
case '\n' :
if ( F_44 ( V_8 ) )
V_2 -> V_61 = 0 ;
if ( F_45 ( V_8 ) )
goto V_69;
V_2 -> V_62 = V_2 -> V_61 ;
break;
case '\r' :
if ( F_46 ( V_8 ) && V_2 -> V_61 == 0 )
goto V_69;
if ( F_47 ( V_8 ) )
goto V_69;
V_2 -> V_62 = V_2 -> V_61 = 0 ;
break;
case '\t' :
goto V_69;
case '\b' :
if ( V_2 -> V_61 > 0 )
V_2 -> V_61 -- ;
break;
default:
if ( ! iscntrl ( V_43 ) ) {
if ( F_49 ( V_8 ) )
goto V_69;
if ( ! F_41 ( V_43 , V_8 ) )
V_2 -> V_61 ++ ;
}
break;
}
}
V_69:
V_5 = V_8 -> V_35 -> V_63 ( V_8 , V_21 , V_5 ) ;
F_54 ( & V_2 -> V_66 ) ;
return V_5 ;
}
static T_1 F_56 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_59 , V_70 ;
T_1 V_71 ;
unsigned char V_43 ;
V_70 = V_59 = F_53 ( V_8 ) ;
V_71 = V_2 -> V_45 ;
while ( V_2 -> V_46 != V_71 ) {
V_43 = F_4 ( V_2 , V_71 ) ;
if ( V_43 == V_72 ) {
unsigned char V_73 ;
int V_74 = 0 ;
V_73 = F_4 ( V_2 , V_71 + 1 ) ;
switch ( V_73 ) {
unsigned int V_75 , V_76 ;
case V_77 :
V_75 = F_4 ( V_2 , V_71 + 2 ) ;
if ( ! ( V_75 & 0x80 ) )
V_75 += V_2 -> V_62 ;
V_76 = 8 - ( V_75 & 7 ) ;
if ( V_76 > V_59 ) {
V_74 = 1 ;
break;
}
V_59 -= V_76 ;
while ( V_76 -- ) {
F_50 ( V_8 , '\b' ) ;
if ( V_2 -> V_61 > 0 )
V_2 -> V_61 -- ;
}
V_71 += 3 ;
break;
case V_78 :
V_2 -> V_62 = V_2 -> V_61 ;
V_71 += 2 ;
break;
case V_79 :
if ( V_2 -> V_61 > 0 )
V_2 -> V_61 -- ;
V_71 += 2 ;
break;
case V_72 :
if ( ! V_59 ) {
V_74 = 1 ;
break;
}
F_50 ( V_8 , V_72 ) ;
V_2 -> V_61 ++ ;
V_59 -- ;
V_71 += 2 ;
break;
default:
if ( V_59 < 2 ) {
V_74 = 1 ;
break;
}
F_50 ( V_8 , '^' ) ;
F_50 ( V_8 , V_73 ^ 0100 ) ;
V_2 -> V_61 += 2 ;
V_59 -= 2 ;
V_71 += 2 ;
}
if ( V_74 )
break;
} else {
if ( F_57 ( V_8 ) ) {
int V_65 = F_43 ( V_43 , V_8 , V_59 ) ;
if ( V_65 < 0 )
break;
V_59 -= V_65 ;
} else {
if ( ! V_59 )
break;
F_50 ( V_8 , V_43 ) ;
V_59 -= 1 ;
}
V_71 += 1 ;
}
}
while ( V_2 -> V_46 - V_71 >= V_80 ) {
if ( F_4 ( V_2 , V_71 ) == V_72 ) {
if ( F_4 ( V_2 , V_71 + 1 ) == V_77 )
V_71 += 3 ;
else
V_71 += 2 ;
} else
V_71 ++ ;
}
V_2 -> V_45 = V_71 ;
return V_70 - V_59 ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_67 , V_81 , V_82 ;
T_1 V_83 ;
V_83 = V_2 -> V_44 ;
V_2 -> V_47 = V_83 ;
V_81 = V_2 -> V_46 - V_2 -> V_45 ;
V_67 = V_83 - V_2 -> V_45 ;
if ( V_67 < V_84 || ( V_67 % V_85 > V_81 % V_85 ) )
return;
F_52 ( & V_2 -> V_66 ) ;
V_2 -> V_46 = V_83 ;
V_82 = F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_66 ) ;
if ( V_82 && V_8 -> V_35 -> V_86 )
V_8 -> V_35 -> V_86 ( V_8 ) ;
}
static void F_59 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_82 ;
if ( V_2 -> V_47 == V_2 -> V_45 )
return;
F_52 ( & V_2 -> V_66 ) ;
V_2 -> V_46 = V_2 -> V_47 ;
V_82 = F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_66 ) ;
if ( V_82 && V_8 -> V_35 -> V_86 )
V_8 -> V_35 -> V_86 ( V_8 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ( ! F_61 ( V_8 ) && ! F_62 ( V_8 ) ) ||
V_2 -> V_46 == V_2 -> V_44 )
return;
F_52 ( & V_2 -> V_66 ) ;
V_2 -> V_46 = V_2 -> V_44 ;
F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_66 ) ;
}
static inline void F_63 ( unsigned char V_43 , struct V_1 * V_2 )
{
* F_5 ( V_2 , V_2 -> V_44 ++ ) = V_43 ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_63 ( V_72 , V_2 ) ;
F_63 ( V_79 , V_2 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_63 ( V_72 , V_2 ) ;
F_63 ( V_78 , V_2 ) ;
}
static void F_66 ( unsigned int V_75 , int V_87 ,
struct V_1 * V_2 )
{
F_63 ( V_72 , V_2 ) ;
F_63 ( V_77 , V_2 ) ;
V_75 &= 7 ;
if ( V_87 )
V_75 |= 0x80 ;
F_63 ( V_75 , V_2 ) ;
}
static void F_67 ( unsigned char V_43 , struct V_1 * V_2 )
{
if ( V_43 == V_72 ) {
F_63 ( V_72 , V_2 ) ;
F_63 ( V_72 , V_2 ) ;
} else {
F_63 ( V_43 , V_2 ) ;
}
}
static void F_68 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_43 == V_72 ) {
F_63 ( V_72 , V_2 ) ;
F_63 ( V_72 , V_2 ) ;
} else {
if ( F_69 ( V_8 ) && iscntrl ( V_43 ) && V_43 != '\t' )
F_63 ( V_72 , V_2 ) ;
F_63 ( V_43 , V_2 ) ;
}
}
static inline void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 ) {
F_67 ( '/' , V_2 ) ;
V_2 -> V_49 = 0 ;
}
}
static void F_71 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
enum { V_88 , V_89 , V_90 } V_91 ;
T_1 V_83 ;
T_1 V_92 ;
int V_93 ;
if ( V_2 -> V_3 == V_2 -> V_14 ) {
return;
}
if ( V_43 == F_72 ( V_8 ) )
V_91 = V_88 ;
else if ( V_43 == F_73 ( V_8 ) )
V_91 = V_89 ;
else {
if ( ! F_61 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_14 ;
return;
}
if ( ! F_74 ( V_8 ) || ! F_75 ( V_8 ) || ! F_76 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_14 ;
F_70 ( V_2 ) ;
F_68 ( F_77 ( V_8 ) , V_8 ) ;
if ( F_74 ( V_8 ) )
F_67 ( '\n' , V_2 ) ;
return;
}
V_91 = V_90 ;
}
V_93 = 0 ;
while ( V_2 -> V_3 != V_2 -> V_14 ) {
V_83 = V_2 -> V_3 ;
do {
V_83 -- ;
V_43 = F_2 ( V_2 , V_83 ) ;
} while ( F_41 ( V_43 , V_8 ) && V_83 != V_2 -> V_14 );
if ( F_41 ( V_43 , V_8 ) )
break;
if ( V_91 == V_89 ) {
if ( isalnum ( V_43 ) || V_43 == '_' )
V_93 ++ ;
else if ( V_93 )
break;
}
V_92 = V_2 -> V_3 - V_83 ;
V_2 -> V_3 = V_83 ;
if ( F_61 ( V_8 ) ) {
if ( F_78 ( V_8 ) ) {
if ( ! V_2 -> V_49 ) {
F_67 ( '\\' , V_2 ) ;
V_2 -> V_49 = 1 ;
}
F_68 ( V_43 , V_8 ) ;
while ( -- V_92 > 0 ) {
V_83 ++ ;
F_67 ( F_2 ( V_2 , V_83 ) , V_2 ) ;
F_64 ( V_2 ) ;
}
} else if ( V_91 == V_88 && ! F_76 ( V_8 ) ) {
F_68 ( F_72 ( V_8 ) , V_8 ) ;
} else if ( V_43 == '\t' ) {
unsigned int V_75 = 0 ;
int V_87 = 0 ;
T_1 V_71 = V_2 -> V_3 ;
while ( V_71 != V_2 -> V_14 ) {
V_71 -- ;
V_43 = F_2 ( V_2 , V_71 ) ;
if ( V_43 == '\t' ) {
V_87 = 1 ;
break;
} else if ( iscntrl ( V_43 ) ) {
if ( F_69 ( V_8 ) )
V_75 += 2 ;
} else if ( ! F_41 ( V_43 , V_8 ) ) {
V_75 ++ ;
}
}
F_66 ( V_75 , V_87 , V_2 ) ;
} else {
if ( iscntrl ( V_43 ) && F_69 ( V_8 ) ) {
F_67 ( '\b' , V_2 ) ;
F_67 ( ' ' , V_2 ) ;
F_67 ( '\b' , V_2 ) ;
}
if ( ! iscntrl ( V_43 ) || F_69 ( V_8 ) ) {
F_67 ( '\b' , V_2 ) ;
F_67 ( ' ' , V_2 ) ;
F_67 ( '\b' , V_2 ) ;
}
}
}
if ( V_91 == V_88 )
break;
}
if ( V_2 -> V_3 == V_2 -> V_14 && F_61 ( V_8 ) )
F_70 ( V_2 ) ;
}
static void F_79 ( int V_94 , struct V_7 * V_8 )
{
struct V_95 * V_96 = F_80 ( V_8 ) ;
if ( V_96 ) {
F_81 ( V_96 , V_94 , 1 ) ;
F_82 ( V_96 ) ;
}
}
static void F_83 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_84 ( V_8 ) )
return;
if ( F_85 ( V_8 ) ) {
F_79 ( V_97 , V_8 ) ;
if ( ! F_86 ( V_8 ) ) {
F_87 ( & V_8 -> V_57 ) ;
F_35 ( V_8 ) ;
F_88 ( V_8 ) ;
F_89 ( & V_8 -> V_57 ) ;
}
return;
}
if ( F_10 ( V_8 ) ) {
F_28 ( '\377' , V_2 ) ;
F_28 ( '\0' , V_2 ) ;
}
F_28 ( '\0' , V_2 ) ;
if ( F_25 ( & V_8 -> V_56 ) )
F_26 ( & V_8 -> V_56 , V_98 ) ;
}
static void F_90 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_21 [ 64 ] ;
V_2 -> V_99 ++ ;
if ( F_91 ( V_100 , V_2 -> V_101 + V_102 ) ||
F_91 ( V_2 -> V_101 , V_100 ) ) {
F_92 ( V_103 L_6 ,
F_93 ( V_8 , V_21 ) ,
V_2 -> V_99 ) ;
V_2 -> V_101 = V_100 ;
V_2 -> V_99 = 0 ;
}
}
static void F_94 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_95 ( V_8 ) ) {
if ( F_96 ( V_8 ) )
return;
if ( F_10 ( V_8 ) ) {
F_28 ( '\377' , V_2 ) ;
F_28 ( '\0' , V_2 ) ;
F_28 ( V_43 , V_2 ) ;
} else
F_28 ( '\0' , V_2 ) ;
} else
F_28 ( V_43 , V_2 ) ;
if ( F_25 ( & V_8 -> V_56 ) )
F_26 ( & V_8 -> V_56 , V_98 ) ;
}
static void
F_97 ( struct V_7 * V_8 , int signal , unsigned char V_43 )
{
if ( ! F_86 ( V_8 ) ) {
F_87 ( & V_8 -> V_57 ) ;
F_35 ( V_8 ) ;
F_88 ( V_8 ) ;
F_89 ( & V_8 -> V_57 ) ;
}
if ( F_98 ( V_8 ) )
F_99 ( V_8 ) ;
if ( F_61 ( V_8 ) ) {
F_68 ( V_43 , V_8 ) ;
F_58 ( V_8 ) ;
} else
F_59 ( V_8 ) ;
F_79 ( signal , V_8 ) ;
return;
}
static int
F_100 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_98 ( V_8 ) ) {
if ( V_43 == F_101 ( V_8 ) ) {
F_99 ( V_8 ) ;
F_59 ( V_8 ) ;
return 0 ;
}
if ( V_43 == F_102 ( V_8 ) ) {
F_103 ( V_8 ) ;
return 0 ;
}
}
if ( F_104 ( V_8 ) ) {
if ( V_43 == F_105 ( V_8 ) ) {
F_97 ( V_8 , V_97 , V_43 ) ;
return 0 ;
} else if ( V_43 == F_106 ( V_8 ) ) {
F_97 ( V_8 , V_104 , V_43 ) ;
return 0 ;
} else if ( V_43 == F_107 ( V_8 ) ) {
F_97 ( V_8 , V_105 , V_43 ) ;
return 0 ;
}
}
if ( V_8 -> V_106 && ! V_8 -> V_107 && F_98 ( V_8 ) && F_108 ( V_8 ) ) {
F_99 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( V_43 == '\r' ) {
if ( F_109 ( V_8 ) )
return 0 ;
if ( F_110 ( V_8 ) )
V_43 = '\n' ;
} else if ( V_43 == '\n' && F_111 ( V_8 ) )
V_43 = '\r' ;
if ( V_2 -> V_12 ) {
if ( V_43 == F_72 ( V_8 ) || V_43 == F_77 ( V_8 ) ||
( V_43 == F_73 ( V_8 ) && F_112 ( V_8 ) ) ) {
F_71 ( V_43 , V_8 ) ;
F_58 ( V_8 ) ;
return 0 ;
}
if ( V_43 == F_113 ( V_8 ) && F_112 ( V_8 ) ) {
V_2 -> V_108 = 1 ;
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( F_69 ( V_8 ) ) {
F_67 ( '^' , V_2 ) ;
F_67 ( '\b' , V_2 ) ;
F_58 ( V_8 ) ;
}
}
return 1 ;
}
if ( V_43 == F_114 ( V_8 ) && F_61 ( V_8 ) && F_112 ( V_8 ) ) {
T_1 V_71 = V_2 -> V_14 ;
F_70 ( V_2 ) ;
F_68 ( V_43 , V_8 ) ;
F_67 ( '\n' , V_2 ) ;
while ( V_71 != V_2 -> V_3 ) {
F_68 ( F_2 ( V_2 , V_71 ) , V_8 ) ;
V_71 ++ ;
}
F_58 ( V_8 ) ;
return 0 ;
}
if ( V_43 == '\n' ) {
if ( F_61 ( V_8 ) || F_62 ( V_8 ) ) {
F_67 ( '\n' , V_2 ) ;
F_58 ( V_8 ) ;
}
goto V_109;
}
if ( V_43 == F_115 ( V_8 ) ) {
V_43 = V_110 ;
goto V_109;
}
if ( ( V_43 == F_116 ( V_8 ) ) ||
( V_43 == F_117 ( V_8 ) && F_112 ( V_8 ) ) ) {
if ( F_61 ( V_8 ) ) {
if ( V_2 -> V_14 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_43 , V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) )
F_28 ( V_43 , V_2 ) ;
V_109:
F_118 ( V_2 -> V_3 & ( V_6 - 1 ) , V_2 -> V_50 ) ;
F_28 ( V_43 , V_2 ) ;
V_2 -> V_14 = V_2 -> V_3 ;
F_19 ( & V_8 -> V_24 , V_26 , V_111 ) ;
if ( F_25 ( & V_8 -> V_56 ) )
F_26 ( & V_8 -> V_56 , V_98 ) ;
return 0 ;
}
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_43 == '\n' )
F_67 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_14 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_43 , V_8 ) ;
}
F_58 ( V_8 ) ;
}
if ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) )
F_28 ( V_43 , V_2 ) ;
F_28 ( V_43 , V_2 ) ;
return 0 ;
}
static inline void
F_119 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_106 && ! V_8 -> V_107 && F_98 ( V_8 ) && F_108 ( V_8 ) ) {
F_99 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_2 -> V_14 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_43 , V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) )
F_28 ( V_43 , V_2 ) ;
F_28 ( V_43 , V_2 ) ;
}
static void F_120 ( struct V_7 * V_8 , unsigned char V_43 )
{
F_119 ( V_8 , V_43 ) ;
}
static inline void
F_121 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_106 && ! V_8 -> V_107 && F_98 ( V_8 ) && F_108 ( V_8 ) ) {
F_99 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_2 -> V_14 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_43 , V_8 ) ;
F_58 ( V_8 ) ;
}
F_28 ( V_43 , V_2 ) ;
}
static void F_122 ( struct V_7 * V_8 , unsigned char V_43 )
{
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_112 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
if ( F_98 ( V_8 ) ) {
if ( V_43 == F_102 ( V_8 ) )
F_103 ( V_8 ) ;
else if ( V_43 == F_101 ( V_8 ) ||
( V_8 -> V_106 && ! V_8 -> V_107 && F_108 ( V_8 ) &&
V_43 != F_105 ( V_8 ) && V_43 != F_106 ( V_8 ) &&
V_43 != F_107 ( V_8 ) ) ) {
F_99 ( V_8 ) ;
F_59 ( V_8 ) ;
}
}
}
static void
F_125 ( struct V_7 * V_8 , unsigned char V_43 , char V_112 )
{
char V_21 [ 64 ] ;
switch ( V_112 ) {
case V_113 :
F_83 ( V_8 ) ;
break;
case V_114 :
case V_115 :
F_94 ( V_8 , V_43 ) ;
break;
case V_116 :
F_90 ( V_8 ) ;
break;
default:
F_92 ( V_117 L_7 ,
F_93 ( V_8 , V_21 ) , V_112 ) ;
break;
}
}
static void
F_126 ( struct V_7 * V_8 , unsigned char V_43 , char V_112 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_108 = 0 ;
if ( F_127 ( V_112 == V_118 ) ) {
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_112 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
F_120 ( V_8 , V_43 ) ;
} else
F_125 ( V_8 , V_43 , V_112 ) ;
}
static void
F_128 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_23 , V_83 ;
V_83 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_23 = V_6 - F_129 ( F_1 ( V_2 ) , V_83 ) ;
V_23 = F_130 ( T_1 , V_38 , V_23 ) ;
memcpy ( F_3 ( V_2 , V_83 ) , V_68 , V_23 ) ;
V_2 -> V_3 += V_23 ;
V_68 += V_23 ;
V_38 -= V_23 ;
V_83 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_23 = V_6 - F_129 ( F_1 ( V_2 ) , V_83 ) ;
V_23 = F_130 ( T_1 , V_38 , V_23 ) ;
memcpy ( F_3 ( V_2 , V_83 ) , V_68 , V_23 ) ;
V_2 -> V_3 += V_23 ;
}
static void
F_131 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_112 = V_118 ;
while ( V_38 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_127 ( V_112 == V_118 ) )
F_28 ( * V_68 ++ , V_2 ) ;
else
F_125 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void
F_132 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
char V_112 = V_118 ;
while ( V_38 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_127 ( V_112 == V_118 ) )
F_122 ( V_8 , * V_68 ++ ) ;
else
F_125 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void
F_133 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_112 = V_118 ;
while ( V_38 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_127 ( V_112 == V_118 ) ) {
unsigned char V_43 = * V_68 ++ ;
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_112 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
if ( F_134 ( V_8 ) ) {
F_28 ( V_43 , V_2 ) ;
continue;
}
if ( ! F_14 ( V_43 , V_2 -> V_120 ) )
F_119 ( V_8 , V_43 ) ;
else if ( F_100 ( V_8 , V_43 ) && V_38 ) {
if ( V_119 )
V_112 = * V_119 ++ ;
F_126 ( V_8 , * V_68 ++ , V_112 ) ;
V_38 -- ;
}
} else
F_125 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void
F_135 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_112 = V_118 ;
while ( V_38 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_127 ( V_112 == V_118 ) ) {
unsigned char V_43 = * V_68 ++ ;
if ( ! F_14 ( V_43 , V_2 -> V_120 ) )
F_121 ( V_8 , V_43 ) ;
else if ( F_100 ( V_8 , V_43 ) && V_38 ) {
if ( V_119 )
V_112 = * V_119 ++ ;
F_126 ( V_8 , * V_68 ++ , V_112 ) ;
V_38 -- ;
}
} else
F_125 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void F_136 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
bool V_121 = F_123 ( V_8 ) || ( F_124 ( V_8 ) && F_112 ( V_8 ) ) ;
if ( V_2 -> V_122 )
F_128 ( V_8 , V_68 , V_119 , V_38 ) ;
else if ( V_2 -> V_123 || ( F_134 ( V_8 ) && ! V_121 ) )
F_131 ( V_8 , V_68 , V_119 , V_38 ) ;
else if ( V_8 -> V_124 && ! F_134 ( V_8 ) )
F_132 ( V_8 , V_68 , V_119 , V_38 ) ;
else {
if ( V_2 -> V_108 ) {
char V_112 = V_118 ;
if ( V_119 )
V_112 = * V_119 ++ ;
F_126 ( V_8 , * V_68 ++ , V_112 ) ;
V_38 -- ;
}
if ( ! V_121 && ! F_10 ( V_8 ) )
F_135 ( V_8 , V_68 , V_119 , V_38 ) ;
else
F_133 ( V_8 , V_68 , V_119 , V_38 ) ;
F_60 ( V_8 ) ;
if ( V_8 -> V_35 -> V_86 )
V_8 -> V_35 -> V_86 ( V_8 ) ;
}
if ( ( ! V_2 -> V_12 && ( F_1 ( V_2 ) >= V_2 -> V_125 ) ) ||
F_134 ( V_8 ) ) {
F_19 ( & V_8 -> V_24 , V_26 , V_111 ) ;
if ( F_25 ( & V_8 -> V_56 ) )
F_26 ( & V_8 -> V_56 , V_98 ) ;
}
}
static int
F_137 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 , int V_126 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_127 , V_23 , V_128 = 0 ;
F_89 ( & V_8 -> V_57 ) ;
while ( 1 ) {
V_127 = F_9 ( V_8 ) ;
V_23 = F_138 ( V_38 , V_127 ) ;
if ( ! V_23 ) {
if ( V_126 && ! V_127 )
V_2 -> V_15 = 1 ;
break;
}
F_136 ( V_8 , V_68 , V_119 , V_23 ) ;
V_68 += V_23 ;
if ( V_119 )
V_119 += V_23 ;
V_38 -= V_23 ;
V_128 += V_23 ;
}
V_8 -> F_9 = V_127 ;
F_20 ( V_8 ) ;
F_87 ( & V_8 -> V_57 ) ;
return V_128 ;
}
static void F_139 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
F_137 ( V_8 , V_68 , V_119 , V_38 , 0 ) ;
}
static int F_140 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
return F_137 ( V_8 , V_68 , V_119 , V_38 , 1 ) ;
}
int F_141 ( int V_94 )
{
return ( F_142 ( & V_129 -> V_130 , V_94 ) ||
V_129 -> V_131 -> V_132 [ V_94 - 1 ] . V_133 . V_134 == V_135 ) ;
}
static void F_143 ( struct V_7 * V_8 , struct V_136 * V_81 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! V_81 || ( V_81 -> V_137 ^ V_8 -> V_138 . V_137 ) & V_139 ) {
F_30 ( V_2 -> V_50 , V_6 ) ;
V_2 -> V_48 = V_2 -> V_4 ;
if ( ! F_144 ( V_8 ) || ! F_1 ( V_2 ) ) {
V_2 -> V_14 = V_2 -> V_4 ;
V_2 -> V_51 = 0 ;
} else {
F_118 ( ( V_2 -> V_3 - 1 ) & ( V_6 - 1 ) ,
V_2 -> V_50 ) ;
V_2 -> V_14 = V_2 -> V_3 ;
V_2 -> V_51 = 1 ;
}
V_2 -> V_49 = 0 ;
V_2 -> V_108 = 0 ;
}
V_2 -> V_12 = ( F_144 ( V_8 ) != 0 ) ;
if ( F_123 ( V_8 ) || F_124 ( V_8 ) || F_109 ( V_8 ) ||
F_110 ( V_8 ) || F_111 ( V_8 ) || F_144 ( V_8 ) ||
F_98 ( V_8 ) || F_104 ( V_8 ) || F_61 ( V_8 ) ||
F_10 ( V_8 ) ) {
F_30 ( V_2 -> V_120 , 256 ) ;
if ( F_109 ( V_8 ) || F_110 ( V_8 ) )
F_118 ( '\r' , V_2 -> V_120 ) ;
if ( F_111 ( V_8 ) )
F_118 ( '\n' , V_2 -> V_120 ) ;
if ( F_144 ( V_8 ) ) {
F_118 ( F_72 ( V_8 ) , V_2 -> V_120 ) ;
F_118 ( F_77 ( V_8 ) , V_2 -> V_120 ) ;
F_118 ( F_115 ( V_8 ) , V_2 -> V_120 ) ;
F_118 ( '\n' , V_2 -> V_120 ) ;
F_118 ( F_116 ( V_8 ) , V_2 -> V_120 ) ;
if ( F_112 ( V_8 ) ) {
F_118 ( F_73 ( V_8 ) , V_2 -> V_120 ) ;
F_118 ( F_113 ( V_8 ) , V_2 -> V_120 ) ;
F_118 ( F_117 ( V_8 ) , V_2 -> V_120 ) ;
if ( F_61 ( V_8 ) )
F_118 ( F_114 ( V_8 ) ,
V_2 -> V_120 ) ;
}
}
if ( F_98 ( V_8 ) ) {
F_118 ( F_101 ( V_8 ) , V_2 -> V_120 ) ;
F_118 ( F_102 ( V_8 ) , V_2 -> V_120 ) ;
}
if ( F_104 ( V_8 ) ) {
F_118 ( F_105 ( V_8 ) , V_2 -> V_120 ) ;
F_118 ( F_106 ( V_8 ) , V_2 -> V_120 ) ;
F_118 ( F_107 ( V_8 ) , V_2 -> V_120 ) ;
}
F_145 ( V_110 , V_2 -> V_120 ) ;
V_2 -> V_123 = 0 ;
V_2 -> V_122 = 0 ;
} else {
V_2 -> V_123 = 1 ;
if ( ( F_84 ( V_8 ) || ( ! F_85 ( V_8 ) && ! F_10 ( V_8 ) ) ) &&
( F_96 ( V_8 ) || ! F_95 ( V_8 ) ) &&
( V_8 -> V_28 -> V_19 & V_140 ) )
V_2 -> V_122 = 1 ;
else
V_2 -> V_122 = 0 ;
}
F_11 ( V_8 ) ;
if ( ! F_98 ( V_8 ) && V_81 && ( V_81 -> V_141 & V_142 ) && ! V_8 -> V_107 ) {
F_99 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( F_25 ( & V_8 -> V_39 ) )
F_34 ( & V_8 -> V_39 ) ;
if ( F_25 ( & V_8 -> V_56 ) )
F_34 ( & V_8 -> V_56 ) ;
}
static void F_146 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_33 )
F_31 ( V_8 ) ;
F_147 ( V_2 ) ;
V_8 -> V_11 = NULL ;
}
static int F_148 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_149 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_143;
V_2 -> V_101 = V_100 ;
F_150 ( & V_2 -> V_144 ) ;
F_150 ( & V_2 -> V_66 ) ;
V_8 -> V_11 = V_2 ;
F_29 ( V_8 -> V_11 ) ;
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
V_2 -> V_125 = 1 ;
V_2 -> V_99 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_108 = 0 ;
V_8 -> V_124 = 0 ;
F_145 ( V_18 , & V_8 -> V_19 ) ;
F_143 ( V_8 , NULL ) ;
F_151 ( V_8 ) ;
return 0 ;
V_143:
return - V_145 ;
}
static inline int F_152 ( struct V_7 * V_8 , int V_146 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_147 = V_146 && ! F_153 ( V_8 ) && F_154 ( V_8 ) ? F_154 ( V_8 ) : 1 ;
if ( V_2 -> V_12 && ! F_134 ( V_8 ) )
return V_2 -> V_14 != V_2 -> V_4 ;
else
return F_1 ( V_2 ) >= V_147 ;
}
static int F_155 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_148 ,
T_1 * V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_65 ;
T_1 V_23 ;
bool V_149 ;
T_1 V_71 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_65 = 0 ;
V_23 = F_138 ( F_1 ( V_2 ) , V_6 - V_71 ) ;
V_23 = F_138 ( * V_67 , V_23 ) ;
if ( V_23 ) {
V_65 = F_156 ( * V_148 , F_3 ( V_2 , V_71 ) , V_23 ) ;
V_23 -= V_65 ;
V_149 = V_23 == 1 && F_2 ( V_2 , V_71 ) == F_115 ( V_8 ) ;
F_7 ( V_8 , F_3 ( V_2 , V_71 ) , V_23 ,
V_2 -> V_12 ) ;
V_2 -> V_4 += V_23 ;
if ( F_134 ( V_8 ) && V_2 -> V_12 && V_149 && ! F_1 ( V_2 ) )
V_23 = 0 ;
* V_148 += V_23 ;
* V_67 -= V_23 ;
}
return V_65 ;
}
static int F_157 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_148 ,
T_1 * V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_23 , V_150 , V_151 , V_43 ;
T_1 V_152 ;
T_1 V_71 ;
int V_153 , V_154 = 0 ;
bool V_155 = 0 ;
V_23 = F_138 ( * V_67 , F_1 ( V_2 ) ) ;
if ( ! V_23 )
return 0 ;
V_71 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_150 = F_130 ( T_1 , V_71 + V_23 , V_6 ) ;
F_158 ( L_8 ,
V_58 , * V_67 , V_71 , V_23 , V_150 ) ;
V_152 = F_159 ( V_2 -> V_50 , V_150 , V_71 ) ;
V_151 = V_23 - ( V_150 - V_71 ) ;
if ( V_152 == V_6 && V_151 ) {
V_152 = F_159 ( V_2 -> V_50 , V_151 , 0 ) ;
if ( V_152 != V_151 )
V_154 = 1 ;
} else if ( V_152 != V_150 )
V_154 = 1 ;
V_150 = V_6 - V_71 ;
V_23 = V_152 - V_71 ;
if ( V_23 > 4096 )
V_23 += 4096 ;
V_23 += V_154 ;
V_43 = V_23 ;
if ( V_154 && ! V_2 -> V_51 && F_2 ( V_2 , V_152 ) == V_110 ) {
V_23 -- ;
V_155 = ! V_23 && V_2 -> V_4 != V_2 -> V_48 ;
}
F_158 ( L_9 ,
V_58 , V_152 , V_154 , V_23 , V_43 , V_150 , V_151 ) ;
if ( V_23 > V_150 ) {
V_153 = F_156 ( * V_148 , F_3 ( V_2 , V_71 ) , V_150 ) ;
if ( V_153 )
return - V_156 ;
V_153 = F_156 ( * V_148 + V_150 , V_2 -> F_2 , V_23 - V_150 ) ;
} else
V_153 = F_156 ( * V_148 , F_3 ( V_2 , V_71 ) , V_23 ) ;
if ( V_153 )
return - V_156 ;
* V_148 += V_23 ;
* V_67 -= V_23 ;
if ( V_154 )
F_145 ( V_152 , V_2 -> V_50 ) ;
F_160 () ;
V_2 -> V_4 += V_43 ;
if ( V_154 ) {
if ( ! V_2 -> V_51 )
V_2 -> V_48 = V_2 -> V_4 ;
else
V_2 -> V_51 = 0 ;
F_161 ( V_8 ) ;
}
return V_155 ? - V_157 : 0 ;
}
static int F_162 ( struct V_7 * V_8 , struct V_158 * V_158 )
{
if ( V_158 -> V_159 -> V_63 == V_160 ||
V_129 -> signal -> V_8 != V_8 )
return 0 ;
F_163 ( & V_8 -> V_53 ) ;
if ( ! V_8 -> V_161 )
F_92 ( V_117 L_10 ) ;
else if ( F_164 ( V_129 ) != V_8 -> V_161 ) {
F_165 ( & V_8 -> V_53 ) ;
if ( F_141 ( V_162 ) || F_166 () )
return - V_163 ;
F_81 ( F_164 ( V_129 ) , V_162 , 1 ) ;
F_167 ( V_164 ) ;
return - V_165 ;
}
F_165 ( & V_8 -> V_53 ) ;
return 0 ;
}
static T_3 F_168 ( struct V_7 * V_8 , struct V_158 * V_158 ,
unsigned char T_2 * V_21 , T_1 V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned char T_2 * V_148 = V_21 ;
F_169 ( V_166 , V_167 ) ;
int V_43 ;
int V_168 , time ;
T_3 V_65 = 0 ;
long V_169 ;
int V_52 ;
V_43 = F_162 ( V_8 , V_158 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_158 -> V_170 & V_171 ) {
if ( ! F_170 ( & V_2 -> V_144 ) )
return - V_157 ;
} else {
if ( F_171 ( & V_2 -> V_144 ) )
return - V_165 ;
}
F_89 ( & V_8 -> V_57 ) ;
V_168 = time = 0 ;
V_169 = V_172 ;
if ( ! V_2 -> V_12 ) {
V_168 = F_154 ( V_8 ) ;
if ( V_168 ) {
time = ( V_102 / 10 ) * F_153 ( V_8 ) ;
if ( time )
V_2 -> V_125 = 1 ;
else if ( ! F_25 ( & V_8 -> V_56 ) ||
( V_2 -> V_125 > V_168 ) )
V_2 -> V_125 = V_168 ;
} else {
V_169 = ( V_102 / 10 ) * F_153 ( V_8 ) ;
V_2 -> V_125 = V_168 = 1 ;
}
}
V_52 = V_8 -> V_52 ;
F_172 ( & V_8 -> V_56 , & V_166 ) ;
while ( V_67 ) {
if ( V_52 && V_8 -> V_33 -> V_54 ) {
unsigned char V_173 ;
if ( V_148 != V_21 )
break;
F_163 ( & V_8 -> V_33 -> V_53 ) ;
V_173 = V_8 -> V_33 -> V_54 ;
V_8 -> V_33 -> V_54 = 0 ;
F_165 ( & V_8 -> V_33 -> V_53 ) ;
if ( F_6 ( V_8 , V_173 , V_148 ++ ) ) {
V_65 = - V_156 ;
V_148 -- ;
break;
}
V_67 -- ;
break;
}
if ( ( ( V_168 - ( V_148 - V_21 ) ) < V_2 -> V_125 ) &&
( ( V_168 - ( V_148 - V_21 ) ) >= 1 ) )
V_2 -> V_125 = ( V_168 - ( V_148 - V_21 ) ) ;
if ( ! F_152 ( V_8 , 0 ) ) {
if ( F_14 ( V_174 , & V_8 -> V_19 ) ) {
V_65 = - V_163 ;
break;
}
if ( F_173 ( V_158 ) )
break;
if ( ! V_169 )
break;
if ( V_158 -> V_170 & V_171 ) {
V_65 = - V_157 ;
break;
}
if ( F_174 ( V_129 ) ) {
V_65 = - V_165 ;
break;
}
F_11 ( V_8 ) ;
F_87 ( & V_8 -> V_57 ) ;
V_169 = F_175 ( & V_166 , V_175 ,
V_169 ) ;
F_89 ( & V_8 -> V_57 ) ;
continue;
}
if ( V_2 -> V_12 && ! F_134 ( V_8 ) ) {
V_65 = F_157 ( V_8 , & V_148 , & V_67 ) ;
if ( V_65 == - V_157 ) {
V_65 = 0 ;
continue;
} else if ( V_65 )
break;
} else {
int V_176 ;
if ( V_52 && V_148 == V_21 ) {
if ( F_6 ( V_8 , V_177 , V_148 ++ ) ) {
V_65 = - V_156 ;
V_148 -- ;
break;
}
V_67 -- ;
}
V_176 = F_155 ( V_8 , & V_148 , & V_67 ) ;
V_176 += F_155 ( V_8 , & V_148 , & V_67 ) ;
if ( V_176 ) {
V_65 = - V_156 ;
break;
}
}
F_24 ( V_8 ) ;
if ( V_148 - V_21 >= V_168 )
break;
if ( time )
V_169 = time ;
}
F_11 ( V_8 ) ;
F_87 ( & V_8 -> V_57 ) ;
F_176 ( & V_8 -> V_56 , & V_166 ) ;
if ( ! F_25 ( & V_8 -> V_56 ) )
V_2 -> V_125 = V_168 ;
F_54 ( & V_2 -> V_144 ) ;
if ( V_148 - V_21 )
V_65 = V_148 - V_21 ;
return V_65 ;
}
static T_3 F_177 ( struct V_7 * V_8 , struct V_158 * V_158 ,
const unsigned char * V_21 , T_1 V_67 )
{
const unsigned char * V_148 = V_21 ;
F_169 ( V_166 , V_167 ) ;
int V_43 ;
T_3 V_65 = 0 ;
if ( F_178 ( V_8 ) && V_158 -> V_159 -> V_63 != V_160 ) {
V_65 = F_179 ( V_8 ) ;
if ( V_65 )
return V_65 ;
}
F_89 ( & V_8 -> V_57 ) ;
F_59 ( V_8 ) ;
F_172 ( & V_8 -> V_39 , & V_166 ) ;
while ( 1 ) {
if ( F_174 ( V_129 ) ) {
V_65 = - V_165 ;
break;
}
if ( F_173 ( V_158 ) || ( V_8 -> V_33 && ! V_8 -> V_33 -> V_38 ) ) {
V_65 = - V_163 ;
break;
}
if ( F_57 ( V_8 ) ) {
while ( V_67 > 0 ) {
T_3 V_178 = F_55 ( V_8 , V_148 , V_67 ) ;
if ( V_178 < 0 ) {
if ( V_178 == - V_157 )
break;
V_65 = V_178 ;
goto V_69;
}
V_148 += V_178 ;
V_67 -= V_178 ;
if ( V_67 == 0 )
break;
V_43 = * V_148 ;
if ( F_51 ( V_43 , V_8 ) < 0 )
break;
V_148 ++ ; V_67 -- ;
}
if ( V_8 -> V_35 -> V_86 )
V_8 -> V_35 -> V_86 ( V_8 ) ;
} else {
struct V_1 * V_2 = V_8 -> V_11 ;
while ( V_67 > 0 ) {
F_52 ( & V_2 -> V_66 ) ;
V_43 = V_8 -> V_35 -> V_63 ( V_8 , V_148 , V_67 ) ;
F_54 ( & V_2 -> V_66 ) ;
if ( V_43 < 0 ) {
V_65 = V_43 ;
goto V_69;
}
if ( ! V_43 )
break;
V_148 += V_43 ;
V_67 -= V_43 ;
}
}
if ( ! V_67 )
break;
if ( V_158 -> V_170 & V_171 ) {
V_65 = - V_157 ;
break;
}
F_87 ( & V_8 -> V_57 ) ;
F_175 ( & V_166 , V_175 , V_172 ) ;
F_89 ( & V_8 -> V_57 ) ;
}
V_69:
F_176 ( & V_8 -> V_39 , & V_166 ) ;
if ( V_148 - V_21 != V_67 && V_8 -> V_24 )
F_118 ( V_25 , & V_8 -> V_19 ) ;
F_87 ( & V_8 -> V_57 ) ;
return ( V_148 - V_21 ) ? V_148 - V_21 : V_65 ;
}
static unsigned int F_180 ( struct V_7 * V_8 , struct V_158 * V_158 ,
T_4 * V_166 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned int V_179 = 0 ;
F_181 ( V_158 , & V_8 -> V_56 , V_166 ) ;
F_181 ( V_158 , & V_8 -> V_39 , V_166 ) ;
if ( F_152 ( V_8 , 1 ) )
V_179 |= V_98 | V_180 ;
if ( V_8 -> V_52 && V_8 -> V_33 -> V_54 )
V_179 |= V_181 | V_98 | V_180 ;
if ( F_14 ( V_174 , & V_8 -> V_19 ) )
V_179 |= V_182 ;
if ( F_173 ( V_158 ) )
V_179 |= V_182 ;
if ( ! ( V_179 & ( V_182 | V_98 | V_180 ) ) ) {
if ( F_154 ( V_8 ) && ! F_153 ( V_8 ) )
V_2 -> V_125 = F_154 ( V_8 ) ;
else
V_2 -> V_125 = 1 ;
}
if ( V_8 -> V_35 -> V_63 && ! F_182 ( V_8 ) &&
F_183 ( V_8 ) < V_183 &&
F_53 ( V_8 ) > 0 )
V_179 |= V_40 | V_184 ;
return V_179 ;
}
static unsigned long F_184 ( struct V_1 * V_2 )
{
T_1 V_67 , V_83 , V_71 ;
if ( V_2 -> V_14 == V_2 -> V_4 )
return 0 ;
V_83 = V_2 -> V_14 ;
V_71 = V_2 -> V_4 ;
V_67 = V_83 - V_71 ;
while ( V_83 != V_71 ) {
if ( F_14 ( V_71 & ( V_6 - 1 ) , V_2 -> V_50 ) &&
F_2 ( V_2 , V_71 ) == V_110 )
V_67 -- ;
V_71 ++ ;
}
return V_67 ;
}
static int F_185 ( struct V_7 * V_8 , struct V_158 * V_158 ,
unsigned int V_185 , unsigned long V_186 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_65 ;
switch ( V_185 ) {
case V_187 :
return F_8 ( F_183 ( V_8 ) , ( int T_2 * ) V_186 ) ;
case V_188 :
F_36 ( & V_8 -> V_57 ) ;
if ( F_144 ( V_8 ) )
V_65 = F_184 ( V_2 ) ;
else
V_65 = F_1 ( V_2 ) ;
F_37 ( & V_8 -> V_57 ) ;
return F_8 ( V_65 , ( unsigned int T_2 * ) V_186 ) ;
default:
return F_186 ( V_8 , V_158 , V_185 , V_186 ) ;
}
}
static void F_187 ( struct V_7 * V_8 , int V_189 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! F_25 ( & V_8 -> V_56 ) ) {
if ( V_189 )
V_2 -> V_125 = 1 ;
else if ( ! V_8 -> V_24 )
V_2 -> V_125 = V_6 ;
}
}
void F_188 ( struct V_190 * V_35 )
{
* V_35 = V_191 ;
V_35 -> V_192 = NULL ;
V_35 -> V_193 = V_35 -> V_19 = 0 ;
}

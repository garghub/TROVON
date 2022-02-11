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
F_25 ( & V_8 -> V_33 -> V_39 , V_40 ) ;
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
V_41 = F_26 ( V_8 ) ;
if ( ! V_41 )
break;
}
F_23 ( V_8 , 0 ) ;
}
static inline void F_27 ( unsigned char V_43 , struct V_1 * V_2 )
{
* F_3 ( V_2 , V_2 -> V_3 ++ ) = V_43 ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_14 = V_2 -> V_4 = 0 ;
V_2 -> V_44 = V_2 -> V_45 = V_2 -> V_46 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0 ;
F_29 ( V_2 -> V_50 , V_6 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
unsigned long V_19 ;
F_31 ( & V_8 -> V_51 , V_19 ) ;
if ( V_8 -> V_33 -> V_52 ) {
V_8 -> V_53 |= V_54 ;
F_32 ( & V_8 -> V_33 -> V_55 ) ;
}
F_33 ( & V_8 -> V_51 , V_19 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
F_35 ( & V_8 -> V_56 ) ;
F_28 ( V_8 -> V_11 ) ;
F_11 ( V_8 ) ;
if ( V_8 -> V_33 )
F_30 ( V_8 ) ;
F_36 ( & V_8 -> V_56 ) ;
}
static T_3 F_37 ( struct V_7 * V_8 )
{
T_3 V_23 ;
F_38 ( 1 , L_3 , V_57 ) ;
F_35 ( & V_8 -> V_56 ) ;
V_23 = F_16 ( V_8 ) ;
F_36 ( & V_8 -> V_56 ) ;
return V_23 ;
}
static inline int F_39 ( unsigned char V_43 )
{
return ( V_43 & 0xc0 ) == 0x80 ;
}
static inline int F_40 ( unsigned char V_43 , struct V_7 * V_8 )
{
return F_41 ( V_8 ) && F_39 ( V_43 ) ;
}
static int F_42 ( unsigned char V_43 , struct V_7 * V_8 , int V_58 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_59 ;
if ( ! V_58 )
return - 1 ;
switch ( V_43 ) {
case '\n' :
if ( F_43 ( V_8 ) )
V_2 -> V_60 = 0 ;
if ( F_44 ( V_8 ) ) {
if ( V_58 < 2 )
return - 1 ;
V_2 -> V_61 = V_2 -> V_60 = 0 ;
V_8 -> V_35 -> V_62 ( V_8 , L_4 , 2 ) ;
return 2 ;
}
V_2 -> V_61 = V_2 -> V_60 ;
break;
case '\r' :
if ( F_45 ( V_8 ) && V_2 -> V_60 == 0 )
return 0 ;
if ( F_46 ( V_8 ) ) {
V_43 = '\n' ;
if ( F_43 ( V_8 ) )
V_2 -> V_61 = V_2 -> V_60 = 0 ;
break;
}
V_2 -> V_61 = V_2 -> V_60 = 0 ;
break;
case '\t' :
V_59 = 8 - ( V_2 -> V_60 & 7 ) ;
if ( F_47 ( V_8 ) == V_63 ) {
if ( V_58 < V_59 )
return - 1 ;
V_2 -> V_60 += V_59 ;
V_8 -> V_35 -> V_62 ( V_8 , L_5 , V_59 ) ;
return V_59 ;
}
V_2 -> V_60 += V_59 ;
break;
case '\b' :
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
break;
default:
if ( ! iscntrl ( V_43 ) ) {
if ( F_48 ( V_8 ) )
V_43 = toupper ( V_43 ) ;
if ( ! F_40 ( V_43 , V_8 ) )
V_2 -> V_60 ++ ;
}
break;
}
F_49 ( V_8 , V_43 ) ;
return 1 ;
}
static int F_50 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_58 , V_64 ;
F_51 ( & V_2 -> V_65 ) ;
V_58 = F_52 ( V_8 ) ;
V_64 = F_42 ( V_43 , V_8 , V_58 ) ;
F_53 ( & V_2 -> V_65 ) ;
if ( V_64 < 0 )
return - 1 ;
else
return 0 ;
}
static T_3 F_54 ( struct V_7 * V_8 ,
const unsigned char * V_21 , unsigned int V_66 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_58 ;
int V_5 ;
const unsigned char * V_67 ;
F_51 ( & V_2 -> V_65 ) ;
V_58 = F_52 ( V_8 ) ;
if ( ! V_58 ) {
F_53 ( & V_2 -> V_65 ) ;
return 0 ;
}
if ( V_66 > V_58 )
V_66 = V_58 ;
for ( V_5 = 0 , V_67 = V_21 ; V_5 < V_66 ; V_5 ++ , V_67 ++ ) {
unsigned char V_43 = * V_67 ;
switch ( V_43 ) {
case '\n' :
if ( F_43 ( V_8 ) )
V_2 -> V_60 = 0 ;
if ( F_44 ( V_8 ) )
goto V_68;
V_2 -> V_61 = V_2 -> V_60 ;
break;
case '\r' :
if ( F_45 ( V_8 ) && V_2 -> V_60 == 0 )
goto V_68;
if ( F_46 ( V_8 ) )
goto V_68;
V_2 -> V_61 = V_2 -> V_60 = 0 ;
break;
case '\t' :
goto V_68;
case '\b' :
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
break;
default:
if ( ! iscntrl ( V_43 ) ) {
if ( F_48 ( V_8 ) )
goto V_68;
if ( ! F_40 ( V_43 , V_8 ) )
V_2 -> V_60 ++ ;
}
break;
}
}
V_68:
V_5 = V_8 -> V_35 -> V_62 ( V_8 , V_21 , V_5 ) ;
F_53 ( & V_2 -> V_65 ) ;
return V_5 ;
}
static T_1 F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_58 , V_69 ;
T_1 V_70 ;
unsigned char V_43 ;
V_69 = V_58 = F_52 ( V_8 ) ;
V_70 = V_2 -> V_45 ;
while ( V_2 -> V_46 != V_70 ) {
V_43 = F_4 ( V_2 , V_70 ) ;
if ( V_43 == V_71 ) {
unsigned char V_72 ;
int V_73 = 0 ;
V_72 = F_4 ( V_2 , V_70 + 1 ) ;
switch ( V_72 ) {
unsigned int V_74 , V_75 ;
case V_76 :
V_74 = F_4 ( V_2 , V_70 + 2 ) ;
if ( ! ( V_74 & 0x80 ) )
V_74 += V_2 -> V_61 ;
V_75 = 8 - ( V_74 & 7 ) ;
if ( V_75 > V_58 ) {
V_73 = 1 ;
break;
}
V_58 -= V_75 ;
while ( V_75 -- ) {
F_49 ( V_8 , '\b' ) ;
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
}
V_70 += 3 ;
break;
case V_77 :
V_2 -> V_61 = V_2 -> V_60 ;
V_70 += 2 ;
break;
case V_78 :
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
V_70 += 2 ;
break;
case V_71 :
if ( ! V_58 ) {
V_73 = 1 ;
break;
}
F_49 ( V_8 , V_71 ) ;
V_2 -> V_60 ++ ;
V_58 -- ;
V_70 += 2 ;
break;
default:
if ( V_58 < 2 ) {
V_73 = 1 ;
break;
}
F_49 ( V_8 , '^' ) ;
F_49 ( V_8 , V_72 ^ 0100 ) ;
V_2 -> V_60 += 2 ;
V_58 -= 2 ;
V_70 += 2 ;
}
if ( V_73 )
break;
} else {
if ( F_56 ( V_8 ) ) {
int V_64 = F_42 ( V_43 , V_8 , V_58 ) ;
if ( V_64 < 0 )
break;
V_58 -= V_64 ;
} else {
if ( ! V_58 )
break;
F_49 ( V_8 , V_43 ) ;
V_58 -= 1 ;
}
V_70 += 1 ;
}
}
while ( V_2 -> V_46 - V_70 >= V_79 ) {
if ( F_4 ( V_2 , V_70 ) == V_71 ) {
if ( F_4 ( V_2 , V_70 + 1 ) == V_76 )
V_70 += 3 ;
else
V_70 += 2 ;
} else
V_70 ++ ;
}
V_2 -> V_45 = V_70 ;
return V_69 - V_58 ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_66 , V_80 , V_81 ;
T_1 V_82 ;
V_82 = V_2 -> V_44 ;
V_2 -> V_47 = V_82 ;
V_80 = V_2 -> V_46 - V_2 -> V_45 ;
V_66 = V_82 - V_2 -> V_45 ;
if ( V_66 < V_83 || ( V_66 % V_84 > V_80 % V_84 ) )
return;
F_51 ( & V_2 -> V_65 ) ;
V_2 -> V_46 = V_82 ;
V_81 = F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_65 ) ;
if ( V_81 && V_8 -> V_35 -> V_85 )
V_8 -> V_35 -> V_85 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_81 ;
if ( ( ! F_59 ( V_8 ) && ! F_60 ( V_8 ) ) ||
V_2 -> V_47 == V_2 -> V_45 )
return;
F_51 ( & V_2 -> V_65 ) ;
V_2 -> V_46 = V_2 -> V_47 ;
V_81 = F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_65 ) ;
if ( V_81 && V_8 -> V_35 -> V_85 )
V_8 -> V_35 -> V_85 ( V_8 ) ;
}
static void F_61 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ( ! F_59 ( V_8 ) && ! F_60 ( V_8 ) ) ||
V_2 -> V_46 == V_2 -> V_44 )
return;
F_51 ( & V_2 -> V_65 ) ;
V_2 -> V_46 = V_2 -> V_44 ;
F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_65 ) ;
}
static inline void F_62 ( unsigned char V_43 , struct V_1 * V_2 )
{
* F_5 ( V_2 , V_2 -> V_44 ++ ) = V_43 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_62 ( V_71 , V_2 ) ;
F_62 ( V_78 , V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_62 ( V_71 , V_2 ) ;
F_62 ( V_77 , V_2 ) ;
}
static void F_65 ( unsigned int V_74 , int V_86 ,
struct V_1 * V_2 )
{
F_62 ( V_71 , V_2 ) ;
F_62 ( V_76 , V_2 ) ;
V_74 &= 7 ;
if ( V_86 )
V_74 |= 0x80 ;
F_62 ( V_74 , V_2 ) ;
}
static void F_66 ( unsigned char V_43 , struct V_1 * V_2 )
{
if ( V_43 == V_71 ) {
F_62 ( V_71 , V_2 ) ;
F_62 ( V_71 , V_2 ) ;
} else {
F_62 ( V_43 , V_2 ) ;
}
}
static void F_67 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_43 == V_71 ) {
F_62 ( V_71 , V_2 ) ;
F_62 ( V_71 , V_2 ) ;
} else {
if ( F_68 ( V_8 ) && iscntrl ( V_43 ) && V_43 != '\t' )
F_62 ( V_71 , V_2 ) ;
F_62 ( V_43 , V_2 ) ;
}
}
static inline void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 ) {
F_66 ( '/' , V_2 ) ;
V_2 -> V_49 = 0 ;
}
}
static void F_70 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
enum { V_87 , V_88 , V_89 } V_90 ;
T_1 V_82 ;
T_1 V_91 ;
int V_92 ;
if ( V_2 -> V_3 == V_2 -> V_14 ) {
return;
}
if ( V_43 == F_71 ( V_8 ) )
V_90 = V_87 ;
else if ( V_43 == F_72 ( V_8 ) )
V_90 = V_88 ;
else {
if ( ! F_59 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_14 ;
return;
}
if ( ! F_73 ( V_8 ) || ! F_74 ( V_8 ) || ! F_75 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_14 ;
F_69 ( V_2 ) ;
F_67 ( F_76 ( V_8 ) , V_8 ) ;
if ( F_73 ( V_8 ) )
F_66 ( '\n' , V_2 ) ;
return;
}
V_90 = V_89 ;
}
V_92 = 0 ;
while ( V_2 -> V_3 != V_2 -> V_14 ) {
V_82 = V_2 -> V_3 ;
do {
V_82 -- ;
V_43 = F_2 ( V_2 , V_82 ) ;
} while ( F_40 ( V_43 , V_8 ) && V_82 != V_2 -> V_14 );
if ( F_40 ( V_43 , V_8 ) )
break;
if ( V_90 == V_88 ) {
if ( isalnum ( V_43 ) || V_43 == '_' )
V_92 ++ ;
else if ( V_92 )
break;
}
V_91 = V_2 -> V_3 - V_82 ;
V_2 -> V_3 = V_82 ;
if ( F_59 ( V_8 ) ) {
if ( F_77 ( V_8 ) ) {
if ( ! V_2 -> V_49 ) {
F_66 ( '\\' , V_2 ) ;
V_2 -> V_49 = 1 ;
}
F_67 ( V_43 , V_8 ) ;
while ( -- V_91 > 0 ) {
V_82 ++ ;
F_66 ( F_2 ( V_2 , V_82 ) , V_2 ) ;
F_63 ( V_2 ) ;
}
} else if ( V_90 == V_87 && ! F_75 ( V_8 ) ) {
F_67 ( F_71 ( V_8 ) , V_8 ) ;
} else if ( V_43 == '\t' ) {
unsigned int V_74 = 0 ;
int V_86 = 0 ;
T_1 V_70 = V_2 -> V_3 ;
while ( V_70 != V_2 -> V_14 ) {
V_70 -- ;
V_43 = F_2 ( V_2 , V_70 ) ;
if ( V_43 == '\t' ) {
V_86 = 1 ;
break;
} else if ( iscntrl ( V_43 ) ) {
if ( F_68 ( V_8 ) )
V_74 += 2 ;
} else if ( ! F_40 ( V_43 , V_8 ) ) {
V_74 ++ ;
}
}
F_65 ( V_74 , V_86 , V_2 ) ;
} else {
if ( iscntrl ( V_43 ) && F_68 ( V_8 ) ) {
F_66 ( '\b' , V_2 ) ;
F_66 ( ' ' , V_2 ) ;
F_66 ( '\b' , V_2 ) ;
}
if ( ! iscntrl ( V_43 ) || F_68 ( V_8 ) ) {
F_66 ( '\b' , V_2 ) ;
F_66 ( ' ' , V_2 ) ;
F_66 ( '\b' , V_2 ) ;
}
}
}
if ( V_90 == V_87 )
break;
}
if ( V_2 -> V_3 == V_2 -> V_14 && F_59 ( V_8 ) )
F_69 ( V_2 ) ;
}
static void F_78 ( int V_93 , struct V_7 * V_8 )
{
struct V_94 * V_95 = F_79 ( V_8 ) ;
if ( V_95 ) {
F_80 ( V_95 , V_93 , 1 ) ;
F_81 ( V_95 ) ;
}
}
static void F_82 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_83 ( V_8 ) )
return;
if ( F_84 ( V_8 ) ) {
F_78 ( V_96 , V_8 ) ;
if ( ! F_85 ( V_8 ) ) {
F_86 ( & V_8 -> V_56 ) ;
F_34 ( V_8 ) ;
F_87 ( V_8 ) ;
F_88 ( & V_8 -> V_56 ) ;
}
return;
}
if ( F_10 ( V_8 ) ) {
F_27 ( '\377' , V_2 ) ;
F_27 ( '\0' , V_2 ) ;
}
F_27 ( '\0' , V_2 ) ;
F_32 ( & V_8 -> V_55 ) ;
}
static void F_89 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_21 [ 64 ] ;
V_2 -> V_97 ++ ;
if ( F_90 ( V_98 , V_2 -> V_99 + V_100 ) ||
F_90 ( V_2 -> V_99 , V_98 ) ) {
F_91 ( V_101 L_6 ,
F_92 ( V_8 , V_21 ) ,
V_2 -> V_97 ) ;
V_2 -> V_99 = V_98 ;
V_2 -> V_97 = 0 ;
}
}
static void F_93 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_94 ( V_8 ) )
return;
if ( F_10 ( V_8 ) ) {
F_27 ( '\377' , V_2 ) ;
F_27 ( '\0' , V_2 ) ;
F_27 ( V_43 , V_2 ) ;
} else if ( F_95 ( V_8 ) )
F_27 ( '\0' , V_2 ) ;
else
F_27 ( V_43 , V_2 ) ;
F_32 ( & V_8 -> V_55 ) ;
}
static void
F_96 ( struct V_7 * V_8 , int signal , unsigned char V_43 )
{
if ( ! F_85 ( V_8 ) ) {
F_86 ( & V_8 -> V_56 ) ;
F_34 ( V_8 ) ;
F_87 ( V_8 ) ;
F_88 ( & V_8 -> V_56 ) ;
}
if ( F_97 ( V_8 ) )
F_98 ( V_8 ) ;
if ( F_59 ( V_8 ) ) {
F_67 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
}
F_78 ( signal , V_8 ) ;
return;
}
static int
F_99 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_102 ;
if ( F_97 ( V_8 ) ) {
if ( V_43 == F_100 ( V_8 ) ) {
F_98 ( V_8 ) ;
F_57 ( V_8 ) ;
return 0 ;
}
if ( V_43 == F_101 ( V_8 ) ) {
F_102 ( V_8 ) ;
return 0 ;
}
}
if ( F_103 ( V_8 ) ) {
if ( V_43 == F_104 ( V_8 ) ) {
F_96 ( V_8 , V_96 , V_43 ) ;
return 0 ;
} else if ( V_43 == F_105 ( V_8 ) ) {
F_96 ( V_8 , V_103 , V_43 ) ;
return 0 ;
} else if ( V_43 == F_106 ( V_8 ) ) {
F_96 ( V_8 , V_104 , V_43 ) ;
return 0 ;
}
}
if ( V_8 -> V_105 && ! V_8 -> V_106 && F_97 ( V_8 ) && F_107 ( V_8 ) ) {
F_98 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_43 == '\r' ) {
if ( F_108 ( V_8 ) )
return 0 ;
if ( F_109 ( V_8 ) )
V_43 = '\n' ;
} else if ( V_43 == '\n' && F_110 ( V_8 ) )
V_43 = '\r' ;
if ( V_2 -> V_12 ) {
if ( V_43 == F_71 ( V_8 ) || V_43 == F_76 ( V_8 ) ||
( V_43 == F_72 ( V_8 ) && F_111 ( V_8 ) ) ) {
F_70 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
return 0 ;
}
if ( V_43 == F_112 ( V_8 ) && F_111 ( V_8 ) ) {
V_2 -> V_107 = 1 ;
if ( F_59 ( V_8 ) ) {
F_69 ( V_2 ) ;
if ( F_68 ( V_8 ) ) {
F_66 ( '^' , V_2 ) ;
F_66 ( '\b' , V_2 ) ;
F_57 ( V_8 ) ;
}
}
return 1 ;
}
if ( V_43 == F_113 ( V_8 ) && F_59 ( V_8 ) && F_111 ( V_8 ) ) {
T_1 V_70 = V_2 -> V_14 ;
F_69 ( V_2 ) ;
F_67 ( V_43 , V_8 ) ;
F_66 ( '\n' , V_2 ) ;
while ( V_70 != V_2 -> V_3 ) {
F_67 ( F_2 ( V_2 , V_70 ) , V_8 ) ;
V_70 ++ ;
}
F_57 ( V_8 ) ;
return 0 ;
}
if ( V_43 == '\n' ) {
if ( F_59 ( V_8 ) || F_60 ( V_8 ) ) {
F_66 ( '\n' , V_2 ) ;
F_57 ( V_8 ) ;
}
goto V_108;
}
if ( V_43 == F_114 ( V_8 ) ) {
V_43 = V_109 ;
goto V_108;
}
if ( ( V_43 == F_115 ( V_8 ) ) ||
( V_43 == F_116 ( V_8 ) && F_111 ( V_8 ) ) ) {
V_102 = ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) )
? 1 : 0 ;
if ( F_59 ( V_8 ) ) {
if ( V_2 -> V_14 == V_2 -> V_3 )
F_64 ( V_2 ) ;
F_67 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
}
if ( V_102 )
F_27 ( V_43 , V_2 ) ;
V_108:
F_117 ( V_2 -> V_3 & ( V_6 - 1 ) , V_2 -> V_50 ) ;
F_27 ( V_43 , V_2 ) ;
V_2 -> V_14 = V_2 -> V_3 ;
F_19 ( & V_8 -> V_24 , V_26 , V_110 ) ;
if ( F_118 ( & V_8 -> V_55 ) )
F_32 ( & V_8 -> V_55 ) ;
return 0 ;
}
}
V_102 = ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) ) ? 1 : 0 ;
if ( F_59 ( V_8 ) ) {
F_69 ( V_2 ) ;
if ( V_43 == '\n' )
F_66 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_14 == V_2 -> V_3 )
F_64 ( V_2 ) ;
F_67 ( V_43 , V_8 ) ;
}
F_57 ( V_8 ) ;
}
if ( V_102 )
F_27 ( V_43 , V_2 ) ;
F_27 ( V_43 , V_2 ) ;
return 0 ;
}
static inline void
F_119 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_102 ;
if ( V_8 -> V_105 && ! V_8 -> V_106 && F_97 ( V_8 ) && F_107 ( V_8 ) ) {
F_98 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( F_59 ( V_8 ) ) {
F_69 ( V_2 ) ;
if ( V_2 -> V_14 == V_2 -> V_3 )
F_64 ( V_2 ) ;
F_67 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
}
V_102 = ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) ) ? 1 : 0 ;
if ( V_102 )
F_27 ( V_43 , V_2 ) ;
F_27 ( V_43 , V_2 ) ;
}
static inline void F_120 ( struct V_7 * V_8 , unsigned char V_43 )
{
F_119 ( V_8 , V_43 ) ;
}
static inline void
F_121 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_105 && ! V_8 -> V_106 && F_97 ( V_8 ) && F_107 ( V_8 ) ) {
F_98 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( F_59 ( V_8 ) ) {
F_69 ( V_2 ) ;
if ( V_2 -> V_14 == V_2 -> V_3 )
F_64 ( V_2 ) ;
F_67 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
}
F_27 ( V_43 , V_2 ) ;
}
static inline void
F_122 ( struct V_7 * V_8 , unsigned char V_43 )
{
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_111 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
if ( F_97 ( V_8 ) ) {
if ( V_43 == F_101 ( V_8 ) )
F_102 ( V_8 ) ;
else if ( V_43 == F_100 ( V_8 ) ||
( V_8 -> V_105 && ! V_8 -> V_106 && F_107 ( V_8 ) &&
V_43 != F_104 ( V_8 ) && V_43 != F_105 ( V_8 ) &&
V_43 != F_106 ( V_8 ) ) ) {
F_98 ( V_8 ) ;
F_58 ( V_8 ) ;
}
}
}
static void
F_125 ( struct V_7 * V_8 , unsigned char V_43 , char V_111 )
{
char V_21 [ 64 ] ;
switch ( V_111 ) {
case V_112 :
F_82 ( V_8 ) ;
break;
case V_113 :
case V_114 :
F_93 ( V_8 , V_43 ) ;
break;
case V_115 :
F_89 ( V_8 ) ;
break;
default:
F_91 ( V_116 L_7 ,
F_92 ( V_8 , V_21 ) , V_111 ) ;
break;
}
}
static void
F_126 ( struct V_7 * V_8 , unsigned char V_43 , char V_111 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_107 = 0 ;
if ( F_127 ( V_111 == V_117 ) ) {
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_111 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
F_120 ( V_8 , V_43 ) ;
} else
F_125 ( V_8 , V_43 , V_111 ) ;
}
static void
F_128 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_118 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_23 , V_82 ;
V_82 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_23 = V_6 - F_129 ( F_1 ( V_2 ) , V_82 ) ;
V_23 = F_130 ( T_1 , V_38 , V_23 ) ;
memcpy ( F_3 ( V_2 , V_82 ) , V_67 , V_23 ) ;
V_2 -> V_3 += V_23 ;
V_67 += V_23 ;
V_38 -= V_23 ;
V_82 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_23 = V_6 - F_129 ( F_1 ( V_2 ) , V_82 ) ;
V_23 = F_130 ( T_1 , V_38 , V_23 ) ;
memcpy ( F_3 ( V_2 , V_82 ) , V_67 , V_23 ) ;
V_2 -> V_3 += V_23 ;
}
static void
F_131 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_118 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_111 = V_117 ;
while ( V_38 -- ) {
if ( V_118 )
V_111 = * V_118 ++ ;
if ( F_127 ( V_111 == V_117 ) )
F_27 ( * V_67 ++ , V_2 ) ;
else
F_125 ( V_8 , * V_67 ++ , V_111 ) ;
}
}
static void
F_132 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_118 , int V_38 )
{
char V_111 = V_117 ;
while ( V_38 -- ) {
if ( V_118 )
V_111 = * V_118 ++ ;
if ( F_127 ( V_111 == V_117 ) )
F_122 ( V_8 , * V_67 ++ ) ;
else
F_125 ( V_8 , * V_67 ++ , V_111 ) ;
}
}
static void
F_133 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_118 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_111 = V_117 ;
while ( V_38 -- ) {
if ( V_118 )
V_111 = * V_118 ++ ;
if ( F_127 ( V_111 == V_117 ) ) {
unsigned char V_43 = * V_67 ++ ;
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_111 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
if ( F_134 ( V_8 ) ) {
F_27 ( V_43 , V_2 ) ;
continue;
}
if ( ! F_14 ( V_43 , V_2 -> V_119 ) )
F_119 ( V_8 , V_43 ) ;
else if ( F_99 ( V_8 , V_43 ) && V_38 ) {
if ( V_118 )
V_111 = * V_118 ++ ;
F_126 ( V_8 , * V_67 ++ , V_111 ) ;
V_38 -- ;
}
} else
F_125 ( V_8 , * V_67 ++ , V_111 ) ;
}
}
static void
F_135 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_118 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_111 = V_117 ;
while ( V_38 -- ) {
if ( V_118 )
V_111 = * V_118 ++ ;
if ( F_127 ( V_111 == V_117 ) ) {
unsigned char V_43 = * V_67 ++ ;
if ( ! F_14 ( V_43 , V_2 -> V_119 ) )
F_121 ( V_8 , V_43 ) ;
else if ( F_99 ( V_8 , V_43 ) && V_38 ) {
if ( V_118 )
V_111 = * V_118 ++ ;
F_126 ( V_8 , * V_67 ++ , V_111 ) ;
V_38 -- ;
}
} else
F_125 ( V_8 , * V_67 ++ , V_111 ) ;
}
}
static void F_136 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_118 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
bool V_120 = F_123 ( V_8 ) || ( F_124 ( V_8 ) && F_111 ( V_8 ) ) ;
if ( V_2 -> V_121 )
F_128 ( V_8 , V_67 , V_118 , V_38 ) ;
else if ( V_2 -> V_122 || ( F_134 ( V_8 ) && ! V_120 ) )
F_131 ( V_8 , V_67 , V_118 , V_38 ) ;
else if ( V_8 -> V_123 && ! F_134 ( V_8 ) )
F_132 ( V_8 , V_67 , V_118 , V_38 ) ;
else {
if ( V_2 -> V_107 ) {
char V_111 = V_117 ;
if ( V_118 )
V_111 = * V_118 ++ ;
F_126 ( V_8 , * V_67 ++ , V_111 ) ;
V_38 -- ;
}
if ( ! V_120 && ! F_10 ( V_8 ) )
F_135 ( V_8 , V_67 , V_118 , V_38 ) ;
else
F_133 ( V_8 , V_67 , V_118 , V_38 ) ;
F_61 ( V_8 ) ;
if ( V_8 -> V_35 -> V_85 )
V_8 -> V_35 -> V_85 ( V_8 ) ;
}
if ( ( ! V_2 -> V_12 && ( F_1 ( V_2 ) >= V_2 -> V_124 ) ) ||
F_134 ( V_8 ) ) {
F_19 ( & V_8 -> V_24 , V_26 , V_110 ) ;
if ( F_118 ( & V_8 -> V_55 ) )
F_32 ( & V_8 -> V_55 ) ;
}
}
static void F_137 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_118 , int V_38 )
{
int V_125 , V_23 ;
F_88 ( & V_8 -> V_56 ) ;
while ( 1 ) {
V_125 = F_9 ( V_8 ) ;
V_23 = F_138 ( V_38 , V_125 ) ;
if ( ! V_23 )
break;
F_136 ( V_8 , V_67 , V_118 , V_23 ) ;
V_67 += V_23 ;
if ( V_118 )
V_118 += V_23 ;
V_38 -= V_23 ;
}
V_8 -> F_9 = V_125 ;
F_20 ( V_8 ) ;
F_86 ( & V_8 -> V_56 ) ;
}
static int F_139 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_118 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_125 , V_23 , V_126 = 0 ;
F_88 ( & V_8 -> V_56 ) ;
while ( 1 ) {
V_125 = F_9 ( V_8 ) ;
V_23 = F_138 ( V_38 , V_125 ) ;
if ( ! V_23 ) {
if ( ! V_125 )
V_2 -> V_15 = 1 ;
break;
}
F_136 ( V_8 , V_67 , V_118 , V_23 ) ;
V_67 += V_23 ;
if ( V_118 )
V_118 += V_23 ;
V_38 -= V_23 ;
V_126 += V_23 ;
}
V_8 -> F_9 = V_125 ;
F_20 ( V_8 ) ;
F_86 ( & V_8 -> V_56 ) ;
return V_126 ;
}
int F_140 ( int V_93 )
{
return ( F_141 ( & V_127 -> V_128 , V_93 ) ||
V_127 -> V_129 -> V_130 [ V_93 - 1 ] . V_131 . V_132 == V_133 ) ;
}
static void F_142 ( struct V_7 * V_8 , struct V_134 * V_80 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! V_80 || ( V_80 -> V_135 ^ V_8 -> V_136 . V_135 ) & V_137 ) {
F_29 ( V_2 -> V_50 , V_6 ) ;
V_2 -> V_48 = V_2 -> V_14 = V_2 -> V_4 ;
V_2 -> V_49 = 0 ;
V_2 -> V_107 = 0 ;
}
V_2 -> V_12 = ( F_143 ( V_8 ) != 0 ) ;
if ( F_123 ( V_8 ) || F_124 ( V_8 ) || F_108 ( V_8 ) ||
F_109 ( V_8 ) || F_110 ( V_8 ) || F_143 ( V_8 ) ||
F_97 ( V_8 ) || F_103 ( V_8 ) || F_59 ( V_8 ) ||
F_10 ( V_8 ) ) {
F_29 ( V_2 -> V_119 , 256 ) ;
if ( F_108 ( V_8 ) || F_109 ( V_8 ) )
F_117 ( '\r' , V_2 -> V_119 ) ;
if ( F_110 ( V_8 ) )
F_117 ( '\n' , V_2 -> V_119 ) ;
if ( F_143 ( V_8 ) ) {
F_117 ( F_71 ( V_8 ) , V_2 -> V_119 ) ;
F_117 ( F_76 ( V_8 ) , V_2 -> V_119 ) ;
F_117 ( F_114 ( V_8 ) , V_2 -> V_119 ) ;
F_117 ( '\n' , V_2 -> V_119 ) ;
F_117 ( F_115 ( V_8 ) , V_2 -> V_119 ) ;
if ( F_111 ( V_8 ) ) {
F_117 ( F_72 ( V_8 ) , V_2 -> V_119 ) ;
F_117 ( F_112 ( V_8 ) , V_2 -> V_119 ) ;
F_117 ( F_116 ( V_8 ) , V_2 -> V_119 ) ;
if ( F_59 ( V_8 ) )
F_117 ( F_113 ( V_8 ) ,
V_2 -> V_119 ) ;
}
}
if ( F_97 ( V_8 ) ) {
F_117 ( F_100 ( V_8 ) , V_2 -> V_119 ) ;
F_117 ( F_101 ( V_8 ) , V_2 -> V_119 ) ;
}
if ( F_103 ( V_8 ) ) {
F_117 ( F_104 ( V_8 ) , V_2 -> V_119 ) ;
F_117 ( F_105 ( V_8 ) , V_2 -> V_119 ) ;
F_117 ( F_106 ( V_8 ) , V_2 -> V_119 ) ;
}
F_144 ( V_109 , V_2 -> V_119 ) ;
V_2 -> V_122 = 0 ;
V_2 -> V_121 = 0 ;
} else {
V_2 -> V_122 = 1 ;
if ( ( F_83 ( V_8 ) || ( ! F_84 ( V_8 ) && ! F_10 ( V_8 ) ) ) &&
( F_94 ( V_8 ) || ! F_95 ( V_8 ) ) &&
( V_8 -> V_28 -> V_19 & V_138 ) )
V_2 -> V_121 = 1 ;
else
V_2 -> V_121 = 0 ;
}
F_11 ( V_8 ) ;
if ( ! F_97 ( V_8 ) && V_80 && ( V_80 -> V_139 & V_140 ) && ! V_8 -> V_106 )
F_98 ( V_8 ) ;
F_32 ( & V_8 -> V_39 ) ;
F_32 ( & V_8 -> V_55 ) ;
}
static void F_145 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_33 )
F_30 ( V_8 ) ;
F_146 ( V_2 ) ;
V_8 -> V_11 = NULL ;
}
static int F_147 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_148 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_141;
V_2 -> V_99 = V_98 ;
F_149 ( & V_2 -> V_142 ) ;
F_149 ( & V_2 -> V_65 ) ;
V_8 -> V_11 = V_2 ;
F_28 ( V_8 -> V_11 ) ;
V_2 -> V_60 = 0 ;
V_2 -> V_61 = 0 ;
V_2 -> V_124 = 1 ;
V_2 -> V_97 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_107 = 0 ;
V_8 -> V_123 = 0 ;
F_144 ( V_18 , & V_8 -> V_19 ) ;
F_142 ( V_8 , NULL ) ;
F_150 ( V_8 ) ;
return 0 ;
V_141:
return - V_143 ;
}
static inline int F_151 ( struct V_7 * V_8 , int V_144 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_2 -> V_12 && ! F_134 ( V_8 ) ) {
if ( V_2 -> V_14 != V_2 -> V_4 )
return 1 ;
} else if ( F_1 ( V_2 ) >= ( V_144 ? V_144 : 1 ) )
return 1 ;
return 0 ;
}
static int F_152 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_145 ,
T_1 * V_66 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_64 ;
T_1 V_23 ;
bool V_146 ;
T_1 V_70 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_64 = 0 ;
V_23 = F_138 ( F_1 ( V_2 ) , V_6 - V_70 ) ;
V_23 = F_138 ( * V_66 , V_23 ) ;
if ( V_23 ) {
V_64 = F_153 ( * V_145 , F_3 ( V_2 , V_70 ) , V_23 ) ;
V_23 -= V_64 ;
V_146 = V_23 == 1 && F_2 ( V_2 , V_70 ) == F_114 ( V_8 ) ;
F_7 ( V_8 , F_3 ( V_2 , V_70 ) , V_23 ,
V_2 -> V_12 ) ;
V_2 -> V_4 += V_23 ;
if ( F_134 ( V_8 ) && V_2 -> V_12 && V_146 && ! F_1 ( V_2 ) )
V_23 = 0 ;
* V_145 += V_23 ;
* V_66 -= V_23 ;
}
return V_64 ;
}
static int F_154 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_145 ,
T_1 * V_66 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_23 , V_147 , V_148 , V_43 ;
T_1 V_149 ;
T_1 V_70 ;
int V_150 , V_151 = 0 ;
bool V_152 = 0 ;
V_23 = F_138 ( * V_66 , F_1 ( V_2 ) ) ;
if ( ! V_23 )
return 0 ;
V_70 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_147 = F_130 ( T_1 , V_70 + V_23 , V_6 ) ;
F_155 ( L_8 ,
V_57 , * V_66 , V_70 , V_23 , V_147 ) ;
V_149 = F_156 ( V_2 -> V_50 , V_147 , V_70 ) ;
V_148 = V_23 - ( V_147 - V_70 ) ;
if ( V_149 == V_6 && V_148 ) {
V_149 = F_156 ( V_2 -> V_50 , V_148 , 0 ) ;
if ( V_149 != V_148 )
V_151 = 1 ;
} else if ( V_149 != V_147 )
V_151 = 1 ;
V_147 = V_6 - V_70 ;
V_23 = V_149 - V_70 ;
if ( V_23 > 4096 )
V_23 += 4096 ;
V_23 += V_151 ;
V_43 = V_23 ;
if ( V_151 && F_2 ( V_2 , V_149 ) == V_109 ) {
V_23 -- ;
V_152 = ! V_23 && V_2 -> V_4 != V_2 -> V_48 ;
}
F_155 ( L_9 ,
V_57 , V_149 , V_151 , V_23 , V_43 , V_147 , V_148 ) ;
if ( V_23 > V_147 ) {
V_150 = F_153 ( * V_145 , F_3 ( V_2 , V_70 ) , V_147 ) ;
if ( V_150 )
return - V_153 ;
V_150 = F_153 ( * V_145 + V_147 , V_2 -> F_2 , V_23 - V_147 ) ;
} else
V_150 = F_153 ( * V_145 , F_3 ( V_2 , V_70 ) , V_23 ) ;
if ( V_150 )
return - V_153 ;
* V_145 += V_23 ;
* V_66 -= V_23 ;
if ( V_151 )
F_144 ( V_149 , V_2 -> V_50 ) ;
F_157 () ;
V_2 -> V_4 += V_43 ;
if ( V_151 ) {
V_2 -> V_48 = V_2 -> V_4 ;
F_158 ( V_8 ) ;
}
return V_152 ? - V_154 : 0 ;
}
static int F_159 ( struct V_7 * V_8 , struct V_155 * V_155 )
{
if ( V_155 -> V_156 -> V_62 == V_157 ||
V_127 -> signal -> V_8 != V_8 )
return 0 ;
F_160 ( & V_8 -> V_51 ) ;
if ( ! V_8 -> V_158 )
F_91 ( V_116 L_10 ) ;
else if ( F_161 ( V_127 ) != V_8 -> V_158 ) {
F_162 ( & V_8 -> V_51 ) ;
if ( F_140 ( V_159 ) || F_163 () )
return - V_160 ;
F_80 ( F_161 ( V_127 ) , V_159 , 1 ) ;
F_164 ( V_161 ) ;
return - V_162 ;
}
F_162 ( & V_8 -> V_51 ) ;
return 0 ;
}
static T_3 F_165 ( struct V_7 * V_8 , struct V_155 * V_155 ,
unsigned char T_2 * V_21 , T_1 V_66 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned char T_2 * V_145 = V_21 ;
F_166 ( V_163 , V_127 ) ;
int V_43 ;
int V_164 , time ;
T_3 V_64 = 0 ;
long V_165 ;
unsigned long V_19 ;
int V_52 ;
V_43 = F_159 ( V_8 , V_155 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_155 -> V_166 & V_167 ) {
if ( ! F_167 ( & V_2 -> V_142 ) )
return - V_154 ;
} else {
if ( F_168 ( & V_2 -> V_142 ) )
return - V_162 ;
}
F_88 ( & V_8 -> V_56 ) ;
V_164 = time = 0 ;
V_165 = V_168 ;
if ( ! V_2 -> V_12 ) {
V_164 = F_169 ( V_8 ) ;
if ( V_164 ) {
time = ( V_100 / 10 ) * F_170 ( V_8 ) ;
if ( time )
V_2 -> V_124 = 1 ;
else if ( ! F_118 ( & V_8 -> V_55 ) ||
( V_2 -> V_124 > V_164 ) )
V_2 -> V_124 = V_164 ;
} else {
V_165 = ( V_100 / 10 ) * F_170 ( V_8 ) ;
V_2 -> V_124 = V_164 = 1 ;
}
}
V_52 = V_8 -> V_52 ;
F_171 ( & V_8 -> V_55 , & V_163 ) ;
while ( V_66 ) {
if ( V_52 && V_8 -> V_33 -> V_53 ) {
unsigned char V_169 ;
if ( V_145 != V_21 )
break;
F_31 ( & V_8 -> V_33 -> V_51 , V_19 ) ;
V_169 = V_8 -> V_33 -> V_53 ;
V_8 -> V_33 -> V_53 = 0 ;
F_33 ( & V_8 -> V_33 -> V_51 , V_19 ) ;
if ( F_6 ( V_8 , V_169 , V_145 ++ ) ) {
V_64 = - V_153 ;
V_145 -- ;
break;
}
V_66 -- ;
break;
}
F_172 ( V_170 ) ;
if ( ( ( V_164 - ( V_145 - V_21 ) ) < V_2 -> V_124 ) &&
( ( V_164 - ( V_145 - V_21 ) ) >= 1 ) )
V_2 -> V_124 = ( V_164 - ( V_145 - V_21 ) ) ;
if ( ! F_151 ( V_8 , 0 ) ) {
if ( F_14 ( V_171 , & V_8 -> V_19 ) ) {
F_86 ( & V_8 -> V_56 ) ;
F_173 ( V_8 ) ;
F_88 ( & V_8 -> V_56 ) ;
if ( ! F_151 ( V_8 , 0 ) ) {
V_64 = - V_160 ;
break;
}
} else {
if ( F_174 ( V_155 ) )
break;
if ( ! V_165 )
break;
if ( V_155 -> V_166 & V_167 ) {
V_64 = - V_154 ;
break;
}
if ( F_175 ( V_127 ) ) {
V_64 = - V_162 ;
break;
}
F_11 ( V_8 ) ;
F_86 ( & V_8 -> V_56 ) ;
V_165 = F_176 ( V_165 ) ;
F_88 ( & V_8 -> V_56 ) ;
continue;
}
}
F_177 ( V_172 ) ;
if ( V_52 && V_145 == V_21 ) {
if ( F_6 ( V_8 , V_173 , V_145 ++ ) ) {
V_64 = - V_153 ;
V_145 -- ;
break;
}
V_66 -- ;
}
if ( V_2 -> V_12 && ! F_134 ( V_8 ) ) {
V_64 = F_154 ( V_8 , & V_145 , & V_66 ) ;
if ( V_64 == - V_154 ) {
V_64 = 0 ;
continue;
} else if ( V_64 )
break;
} else {
int V_174 ;
V_174 = F_152 ( V_8 , & V_145 , & V_66 ) ;
V_174 += F_152 ( V_8 , & V_145 , & V_66 ) ;
if ( V_174 ) {
V_64 = - V_153 ;
break;
}
}
F_24 ( V_8 ) ;
if ( V_145 - V_21 >= V_164 )
break;
if ( time )
V_165 = time ;
}
F_11 ( V_8 ) ;
F_86 ( & V_8 -> V_56 ) ;
F_178 ( & V_8 -> V_55 , & V_163 ) ;
if ( ! F_118 ( & V_8 -> V_55 ) )
V_2 -> V_124 = V_164 ;
F_53 ( & V_2 -> V_142 ) ;
F_177 ( V_172 ) ;
if ( V_145 - V_21 )
V_64 = V_145 - V_21 ;
return V_64 ;
}
static T_3 F_179 ( struct V_7 * V_8 , struct V_155 * V_155 ,
const unsigned char * V_21 , T_1 V_66 )
{
const unsigned char * V_145 = V_21 ;
F_166 ( V_163 , V_127 ) ;
int V_43 ;
T_3 V_64 = 0 ;
if ( F_180 ( V_8 ) && V_155 -> V_156 -> V_62 != V_157 ) {
V_64 = F_181 ( V_8 ) ;
if ( V_64 )
return V_64 ;
}
F_88 ( & V_8 -> V_56 ) ;
F_58 ( V_8 ) ;
F_171 ( & V_8 -> V_39 , & V_163 ) ;
while ( 1 ) {
F_172 ( V_170 ) ;
if ( F_175 ( V_127 ) ) {
V_64 = - V_162 ;
break;
}
if ( F_174 ( V_155 ) || ( V_8 -> V_33 && ! V_8 -> V_33 -> V_38 ) ) {
V_64 = - V_160 ;
break;
}
if ( F_56 ( V_8 ) ) {
while ( V_66 > 0 ) {
T_3 V_175 = F_54 ( V_8 , V_145 , V_66 ) ;
if ( V_175 < 0 ) {
if ( V_175 == - V_154 )
break;
V_64 = V_175 ;
goto V_68;
}
V_145 += V_175 ;
V_66 -= V_175 ;
if ( V_66 == 0 )
break;
V_43 = * V_145 ;
if ( F_50 ( V_43 , V_8 ) < 0 )
break;
V_145 ++ ; V_66 -- ;
}
if ( V_8 -> V_35 -> V_85 )
V_8 -> V_35 -> V_85 ( V_8 ) ;
} else {
while ( V_66 > 0 ) {
V_43 = V_8 -> V_35 -> V_62 ( V_8 , V_145 , V_66 ) ;
if ( V_43 < 0 ) {
V_64 = V_43 ;
goto V_68;
}
if ( ! V_43 )
break;
V_145 += V_43 ;
V_66 -= V_43 ;
}
}
if ( ! V_66 )
break;
if ( V_155 -> V_166 & V_167 ) {
V_64 = - V_154 ;
break;
}
F_86 ( & V_8 -> V_56 ) ;
F_182 () ;
F_88 ( & V_8 -> V_56 ) ;
}
V_68:
F_177 ( V_172 ) ;
F_178 ( & V_8 -> V_39 , & V_163 ) ;
if ( V_145 - V_21 != V_66 && V_8 -> V_24 )
F_117 ( V_25 , & V_8 -> V_19 ) ;
F_86 ( & V_8 -> V_56 ) ;
return ( V_145 - V_21 ) ? V_145 - V_21 : V_64 ;
}
static unsigned int F_183 ( struct V_7 * V_8 , struct V_155 * V_155 ,
T_4 * V_163 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned int V_176 = 0 ;
F_184 ( V_155 , & V_8 -> V_55 , V_163 ) ;
F_184 ( V_155 , & V_8 -> V_39 , V_163 ) ;
if ( F_151 ( V_8 , F_170 ( V_8 ) ? 0 : F_169 ( V_8 ) ) )
V_176 |= V_177 | V_178 ;
if ( V_8 -> V_52 && V_8 -> V_33 -> V_53 )
V_176 |= V_179 | V_177 | V_178 ;
if ( F_14 ( V_171 , & V_8 -> V_19 ) )
V_176 |= V_180 ;
if ( F_174 ( V_155 ) )
V_176 |= V_180 ;
if ( ! ( V_176 & ( V_180 | V_177 | V_178 ) ) ) {
if ( F_169 ( V_8 ) && ! F_170 ( V_8 ) )
V_2 -> V_124 = F_169 ( V_8 ) ;
else
V_2 -> V_124 = 1 ;
}
if ( V_8 -> V_35 -> V_62 && ! F_185 ( V_8 ) &&
F_186 ( V_8 ) < V_181 &&
F_52 ( V_8 ) > 0 )
V_176 |= V_40 | V_182 ;
return V_176 ;
}
static unsigned long F_187 ( struct V_1 * V_2 )
{
T_1 V_66 , V_82 , V_70 ;
if ( V_2 -> V_14 == V_2 -> V_4 )
return 0 ;
V_82 = V_2 -> V_14 ;
V_70 = V_2 -> V_4 ;
V_66 = V_82 - V_70 ;
while ( V_82 != V_70 ) {
if ( F_14 ( V_70 & ( V_6 - 1 ) , V_2 -> V_50 ) &&
F_2 ( V_2 , V_70 ) == V_109 )
V_66 -- ;
V_70 ++ ;
}
return V_66 ;
}
static int F_188 ( struct V_7 * V_8 , struct V_155 * V_155 ,
unsigned int V_183 , unsigned long V_184 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_64 ;
switch ( V_183 ) {
case V_185 :
return F_8 ( F_186 ( V_8 ) , ( int T_2 * ) V_184 ) ;
case V_186 :
F_35 ( & V_8 -> V_56 ) ;
if ( F_143 ( V_8 ) )
V_64 = F_187 ( V_2 ) ;
else
V_64 = F_1 ( V_2 ) ;
F_36 ( & V_8 -> V_56 ) ;
return F_8 ( V_64 , ( unsigned int T_2 * ) V_184 ) ;
default:
return F_189 ( V_8 , V_155 , V_183 , V_184 ) ;
}
}
static void F_190 ( struct V_7 * V_8 , int V_187 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! F_118 ( & V_8 -> V_55 ) ) {
if ( V_187 )
V_2 -> V_124 = 1 ;
else if ( ! V_8 -> V_24 )
V_2 -> V_124 = V_6 ;
}
}
void F_191 ( struct V_188 * V_35 )
{
* V_35 = V_189 ;
V_35 -> V_190 = NULL ;
V_35 -> V_191 = V_35 -> V_19 = 0 ;
}

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
F_29 ( V_2 -> V_49 , V_6 ) ;
}
static void F_30 ( struct V_7 * V_8 )
{
unsigned long V_19 ;
F_31 ( & V_8 -> V_50 , V_19 ) ;
if ( V_8 -> V_33 -> V_51 ) {
V_8 -> V_52 |= V_53 ;
F_32 ( & V_8 -> V_33 -> V_54 ) ;
}
F_33 ( & V_8 -> V_50 , V_19 ) ;
}
static void F_34 ( struct V_7 * V_8 )
{
F_35 ( & V_8 -> V_55 ) ;
F_28 ( V_8 -> V_11 ) ;
F_11 ( V_8 ) ;
if ( V_8 -> V_33 )
F_30 ( V_8 ) ;
F_36 ( & V_8 -> V_55 ) ;
}
static T_3 F_37 ( struct V_7 * V_8 )
{
T_3 V_23 ;
F_38 ( 1 , L_3 , V_56 ) ;
F_35 ( & V_8 -> V_55 ) ;
V_23 = F_16 ( V_8 ) ;
F_36 ( & V_8 -> V_55 ) ;
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
static int F_42 ( unsigned char V_43 , struct V_7 * V_8 , int V_57 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_58 ;
if ( ! V_57 )
return - 1 ;
switch ( V_43 ) {
case '\n' :
if ( F_43 ( V_8 ) )
V_2 -> V_59 = 0 ;
if ( F_44 ( V_8 ) ) {
if ( V_57 < 2 )
return - 1 ;
V_2 -> V_60 = V_2 -> V_59 = 0 ;
V_8 -> V_35 -> V_61 ( V_8 , L_4 , 2 ) ;
return 2 ;
}
V_2 -> V_60 = V_2 -> V_59 ;
break;
case '\r' :
if ( F_45 ( V_8 ) && V_2 -> V_59 == 0 )
return 0 ;
if ( F_46 ( V_8 ) ) {
V_43 = '\n' ;
if ( F_43 ( V_8 ) )
V_2 -> V_60 = V_2 -> V_59 = 0 ;
break;
}
V_2 -> V_60 = V_2 -> V_59 = 0 ;
break;
case '\t' :
V_58 = 8 - ( V_2 -> V_59 & 7 ) ;
if ( F_47 ( V_8 ) == V_62 ) {
if ( V_57 < V_58 )
return - 1 ;
V_2 -> V_59 += V_58 ;
V_8 -> V_35 -> V_61 ( V_8 , L_5 , V_58 ) ;
return V_58 ;
}
V_2 -> V_59 += V_58 ;
break;
case '\b' :
if ( V_2 -> V_59 > 0 )
V_2 -> V_59 -- ;
break;
default:
if ( ! iscntrl ( V_43 ) ) {
if ( F_48 ( V_8 ) )
V_43 = toupper ( V_43 ) ;
if ( ! F_40 ( V_43 , V_8 ) )
V_2 -> V_59 ++ ;
}
break;
}
F_49 ( V_8 , V_43 ) ;
return 1 ;
}
static int F_50 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_57 , V_63 ;
F_51 ( & V_2 -> V_64 ) ;
V_57 = F_52 ( V_8 ) ;
V_63 = F_42 ( V_43 , V_8 , V_57 ) ;
F_53 ( & V_2 -> V_64 ) ;
if ( V_63 < 0 )
return - 1 ;
else
return 0 ;
}
static T_3 F_54 ( struct V_7 * V_8 ,
const unsigned char * V_21 , unsigned int V_65 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_57 ;
int V_5 ;
const unsigned char * V_66 ;
F_51 ( & V_2 -> V_64 ) ;
V_57 = F_52 ( V_8 ) ;
if ( ! V_57 ) {
F_53 ( & V_2 -> V_64 ) ;
return 0 ;
}
if ( V_65 > V_57 )
V_65 = V_57 ;
for ( V_5 = 0 , V_66 = V_21 ; V_5 < V_65 ; V_5 ++ , V_66 ++ ) {
unsigned char V_43 = * V_66 ;
switch ( V_43 ) {
case '\n' :
if ( F_43 ( V_8 ) )
V_2 -> V_59 = 0 ;
if ( F_44 ( V_8 ) )
goto V_67;
V_2 -> V_60 = V_2 -> V_59 ;
break;
case '\r' :
if ( F_45 ( V_8 ) && V_2 -> V_59 == 0 )
goto V_67;
if ( F_46 ( V_8 ) )
goto V_67;
V_2 -> V_60 = V_2 -> V_59 = 0 ;
break;
case '\t' :
goto V_67;
case '\b' :
if ( V_2 -> V_59 > 0 )
V_2 -> V_59 -- ;
break;
default:
if ( ! iscntrl ( V_43 ) ) {
if ( F_48 ( V_8 ) )
goto V_67;
if ( ! F_40 ( V_43 , V_8 ) )
V_2 -> V_59 ++ ;
}
break;
}
}
V_67:
V_5 = V_8 -> V_35 -> V_61 ( V_8 , V_21 , V_5 ) ;
F_53 ( & V_2 -> V_64 ) ;
return V_5 ;
}
static T_1 F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_57 , V_68 ;
T_1 V_69 ;
unsigned char V_43 ;
V_68 = V_57 = F_52 ( V_8 ) ;
V_69 = V_2 -> V_45 ;
while ( V_2 -> V_46 != V_69 ) {
V_43 = F_4 ( V_2 , V_69 ) ;
if ( V_43 == V_70 ) {
unsigned char V_71 ;
int V_72 = 0 ;
V_71 = F_4 ( V_2 , V_69 + 1 ) ;
switch ( V_71 ) {
unsigned int V_73 , V_74 ;
case V_75 :
V_73 = F_4 ( V_2 , V_69 + 2 ) ;
if ( ! ( V_73 & 0x80 ) )
V_73 += V_2 -> V_60 ;
V_74 = 8 - ( V_73 & 7 ) ;
if ( V_74 > V_57 ) {
V_72 = 1 ;
break;
}
V_57 -= V_74 ;
while ( V_74 -- ) {
F_49 ( V_8 , '\b' ) ;
if ( V_2 -> V_59 > 0 )
V_2 -> V_59 -- ;
}
V_69 += 3 ;
break;
case V_76 :
V_2 -> V_60 = V_2 -> V_59 ;
V_69 += 2 ;
break;
case V_77 :
if ( V_2 -> V_59 > 0 )
V_2 -> V_59 -- ;
V_69 += 2 ;
break;
case V_70 :
if ( ! V_57 ) {
V_72 = 1 ;
break;
}
F_49 ( V_8 , V_70 ) ;
V_2 -> V_59 ++ ;
V_57 -- ;
V_69 += 2 ;
break;
default:
if ( V_57 < 2 ) {
V_72 = 1 ;
break;
}
F_49 ( V_8 , '^' ) ;
F_49 ( V_8 , V_71 ^ 0100 ) ;
V_2 -> V_59 += 2 ;
V_57 -= 2 ;
V_69 += 2 ;
}
if ( V_72 )
break;
} else {
if ( F_56 ( V_8 ) ) {
int V_63 = F_42 ( V_43 , V_8 , V_57 ) ;
if ( V_63 < 0 )
break;
V_57 -= V_63 ;
} else {
if ( ! V_57 )
break;
F_49 ( V_8 , V_43 ) ;
V_57 -= 1 ;
}
V_69 += 1 ;
}
}
while ( V_2 -> V_46 - V_69 >= V_78 ) {
if ( F_4 ( V_2 , V_69 == V_70 ) ) {
if ( F_4 ( V_2 , V_69 ) == V_75 )
V_69 += 3 ;
else
V_69 += 2 ;
} else
V_69 ++ ;
}
V_2 -> V_45 = V_69 ;
return V_68 - V_57 ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_65 , V_79 , V_80 ;
T_1 V_81 ;
V_81 = V_2 -> V_44 ;
V_79 = V_2 -> V_46 - V_2 -> V_45 ;
V_65 = V_81 - V_2 -> V_45 ;
if ( V_65 < V_82 || ( V_65 % V_83 > V_79 % V_83 ) )
return;
F_51 ( & V_2 -> V_64 ) ;
V_2 -> V_46 = V_81 ;
V_80 = F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_64 ) ;
if ( V_80 && V_8 -> V_35 -> V_84 )
V_8 -> V_35 -> V_84 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_80 ;
if ( ! F_59 ( V_8 ) || V_2 -> V_46 == V_2 -> V_45 )
return;
F_51 ( & V_2 -> V_64 ) ;
V_80 = F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_64 ) ;
if ( V_80 && V_8 -> V_35 -> V_84 )
V_8 -> V_35 -> V_84 ( V_8 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! F_59 ( V_8 ) || V_2 -> V_46 == V_2 -> V_44 )
return;
F_51 ( & V_2 -> V_64 ) ;
V_2 -> V_46 = V_2 -> V_44 ;
F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_64 ) ;
}
static inline void F_61 ( unsigned char V_43 , struct V_1 * V_2 )
{
* F_5 ( V_2 , V_2 -> V_44 ++ ) = V_43 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_61 ( V_70 , V_2 ) ;
F_61 ( V_77 , V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_61 ( V_70 , V_2 ) ;
F_61 ( V_76 , V_2 ) ;
}
static void F_64 ( unsigned int V_73 , int V_85 ,
struct V_1 * V_2 )
{
F_61 ( V_70 , V_2 ) ;
F_61 ( V_75 , V_2 ) ;
V_73 &= 7 ;
if ( V_85 )
V_73 |= 0x80 ;
F_61 ( V_73 , V_2 ) ;
}
static void F_65 ( unsigned char V_43 , struct V_1 * V_2 )
{
if ( V_43 == V_70 ) {
F_61 ( V_70 , V_2 ) ;
F_61 ( V_70 , V_2 ) ;
} else {
F_61 ( V_43 , V_2 ) ;
}
}
static void F_66 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_43 == V_70 ) {
F_61 ( V_70 , V_2 ) ;
F_61 ( V_70 , V_2 ) ;
} else {
if ( F_67 ( V_8 ) && iscntrl ( V_43 ) && V_43 != '\t' )
F_61 ( V_70 , V_2 ) ;
F_61 ( V_43 , V_2 ) ;
}
}
static inline void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_48 ) {
F_65 ( '/' , V_2 ) ;
V_2 -> V_48 = 0 ;
}
}
static void F_69 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
enum { V_86 , V_87 , V_88 } V_89 ;
T_1 V_81 ;
T_1 V_90 ;
int V_91 ;
if ( V_2 -> V_3 == V_2 -> V_14 ) {
return;
}
if ( V_43 == F_70 ( V_8 ) )
V_89 = V_86 ;
else if ( V_43 == F_71 ( V_8 ) )
V_89 = V_87 ;
else {
if ( ! F_59 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_14 ;
return;
}
if ( ! F_72 ( V_8 ) || ! F_73 ( V_8 ) || ! F_74 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_14 ;
F_68 ( V_2 ) ;
F_66 ( F_75 ( V_8 ) , V_8 ) ;
if ( F_72 ( V_8 ) )
F_65 ( '\n' , V_2 ) ;
return;
}
V_89 = V_88 ;
}
V_91 = 0 ;
while ( V_2 -> V_3 != V_2 -> V_14 ) {
V_81 = V_2 -> V_3 ;
do {
V_81 -- ;
V_43 = F_2 ( V_2 , V_81 ) ;
} while ( F_40 ( V_43 , V_8 ) && V_81 != V_2 -> V_14 );
if ( F_40 ( V_43 , V_8 ) )
break;
if ( V_89 == V_87 ) {
if ( isalnum ( V_43 ) || V_43 == '_' )
V_91 ++ ;
else if ( V_91 )
break;
}
V_90 = V_2 -> V_3 - V_81 ;
V_2 -> V_3 = V_81 ;
if ( F_59 ( V_8 ) ) {
if ( F_76 ( V_8 ) ) {
if ( ! V_2 -> V_48 ) {
F_65 ( '\\' , V_2 ) ;
V_2 -> V_48 = 1 ;
}
F_66 ( V_43 , V_8 ) ;
while ( -- V_90 > 0 ) {
V_81 ++ ;
F_65 ( F_2 ( V_2 , V_81 ) , V_2 ) ;
F_62 ( V_2 ) ;
}
} else if ( V_89 == V_86 && ! F_74 ( V_8 ) ) {
F_66 ( F_70 ( V_8 ) , V_8 ) ;
} else if ( V_43 == '\t' ) {
unsigned int V_73 = 0 ;
int V_85 = 0 ;
T_1 V_69 = V_2 -> V_3 ;
while ( V_69 != V_2 -> V_14 ) {
V_69 -- ;
V_43 = F_2 ( V_2 , V_69 ) ;
if ( V_43 == '\t' ) {
V_85 = 1 ;
break;
} else if ( iscntrl ( V_43 ) ) {
if ( F_67 ( V_8 ) )
V_73 += 2 ;
} else if ( ! F_40 ( V_43 , V_8 ) ) {
V_73 ++ ;
}
}
F_64 ( V_73 , V_85 , V_2 ) ;
} else {
if ( iscntrl ( V_43 ) && F_67 ( V_8 ) ) {
F_65 ( '\b' , V_2 ) ;
F_65 ( ' ' , V_2 ) ;
F_65 ( '\b' , V_2 ) ;
}
if ( ! iscntrl ( V_43 ) || F_67 ( V_8 ) ) {
F_65 ( '\b' , V_2 ) ;
F_65 ( ' ' , V_2 ) ;
F_65 ( '\b' , V_2 ) ;
}
}
}
if ( V_89 == V_86 )
break;
}
if ( V_2 -> V_3 == V_2 -> V_14 && F_59 ( V_8 ) )
F_68 ( V_2 ) ;
}
static void F_77 ( int V_92 , struct V_7 * V_8 )
{
struct V_93 * V_94 = F_78 ( V_8 ) ;
if ( V_94 ) {
F_79 ( V_94 , V_92 , 1 ) ;
F_80 ( V_94 ) ;
}
}
static void F_81 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_82 ( V_8 ) )
return;
if ( F_83 ( V_8 ) ) {
F_77 ( V_95 , V_8 ) ;
if ( ! F_84 ( V_8 ) ) {
F_85 ( & V_8 -> V_55 ) ;
F_34 ( V_8 ) ;
F_86 ( V_8 ) ;
F_87 ( & V_8 -> V_55 ) ;
}
return;
}
if ( F_10 ( V_8 ) ) {
F_27 ( '\377' , V_2 ) ;
F_27 ( '\0' , V_2 ) ;
}
F_27 ( '\0' , V_2 ) ;
F_32 ( & V_8 -> V_54 ) ;
}
static void F_88 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_21 [ 64 ] ;
V_2 -> V_96 ++ ;
if ( F_89 ( V_97 , V_2 -> V_98 + V_99 ) ||
F_89 ( V_2 -> V_98 , V_97 ) ) {
F_90 ( V_100 L_6 ,
F_91 ( V_8 , V_21 ) ,
V_2 -> V_96 ) ;
V_2 -> V_98 = V_97 ;
V_2 -> V_96 = 0 ;
}
}
static void F_92 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_93 ( V_8 ) )
return;
if ( F_10 ( V_8 ) ) {
F_27 ( '\377' , V_2 ) ;
F_27 ( '\0' , V_2 ) ;
F_27 ( V_43 , V_2 ) ;
} else if ( F_94 ( V_8 ) )
F_27 ( '\0' , V_2 ) ;
else
F_27 ( V_43 , V_2 ) ;
F_32 ( & V_8 -> V_54 ) ;
}
static void
F_95 ( struct V_7 * V_8 , int signal , unsigned char V_43 )
{
if ( ! F_84 ( V_8 ) ) {
F_85 ( & V_8 -> V_55 ) ;
F_34 ( V_8 ) ;
F_86 ( V_8 ) ;
F_87 ( & V_8 -> V_55 ) ;
}
if ( F_96 ( V_8 ) )
F_97 ( V_8 ) ;
if ( F_59 ( V_8 ) ) {
F_66 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
}
F_77 ( signal , V_8 ) ;
return;
}
static int
F_98 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_101 ;
if ( F_96 ( V_8 ) ) {
if ( V_43 == F_99 ( V_8 ) ) {
F_97 ( V_8 ) ;
F_57 ( V_8 ) ;
return 0 ;
}
if ( V_43 == F_100 ( V_8 ) ) {
F_101 ( V_8 ) ;
return 0 ;
}
}
if ( F_102 ( V_8 ) ) {
if ( V_43 == F_103 ( V_8 ) ) {
F_95 ( V_8 , V_95 , V_43 ) ;
return 0 ;
} else if ( V_43 == F_104 ( V_8 ) ) {
F_95 ( V_8 , V_102 , V_43 ) ;
return 0 ;
} else if ( V_43 == F_105 ( V_8 ) ) {
F_95 ( V_8 , V_103 , V_43 ) ;
return 0 ;
}
}
if ( V_8 -> V_104 && ! V_8 -> V_105 && F_96 ( V_8 ) && F_106 ( V_8 ) ) {
F_97 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_43 == '\r' ) {
if ( F_107 ( V_8 ) )
return 0 ;
if ( F_108 ( V_8 ) )
V_43 = '\n' ;
} else if ( V_43 == '\n' && F_109 ( V_8 ) )
V_43 = '\r' ;
if ( V_2 -> V_12 ) {
if ( V_43 == F_70 ( V_8 ) || V_43 == F_75 ( V_8 ) ||
( V_43 == F_71 ( V_8 ) && F_110 ( V_8 ) ) ) {
F_69 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
return 0 ;
}
if ( V_43 == F_111 ( V_8 ) && F_110 ( V_8 ) ) {
V_2 -> V_106 = 1 ;
if ( F_59 ( V_8 ) ) {
F_68 ( V_2 ) ;
if ( F_67 ( V_8 ) ) {
F_65 ( '^' , V_2 ) ;
F_65 ( '\b' , V_2 ) ;
F_57 ( V_8 ) ;
}
}
return 1 ;
}
if ( V_43 == F_112 ( V_8 ) && F_59 ( V_8 ) && F_110 ( V_8 ) ) {
T_1 V_69 = V_2 -> V_14 ;
F_68 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
F_65 ( '\n' , V_2 ) ;
while ( V_69 != V_2 -> V_3 ) {
F_66 ( F_2 ( V_2 , V_69 ) , V_8 ) ;
V_69 ++ ;
}
F_57 ( V_8 ) ;
return 0 ;
}
if ( V_43 == '\n' ) {
if ( F_59 ( V_8 ) || F_113 ( V_8 ) ) {
F_65 ( '\n' , V_2 ) ;
F_57 ( V_8 ) ;
}
goto V_107;
}
if ( V_43 == F_114 ( V_8 ) ) {
V_43 = V_108 ;
goto V_107;
}
if ( ( V_43 == F_115 ( V_8 ) ) ||
( V_43 == F_116 ( V_8 ) && F_110 ( V_8 ) ) ) {
V_101 = ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) )
? 1 : 0 ;
if ( F_59 ( V_8 ) ) {
if ( V_2 -> V_14 == V_2 -> V_3 )
F_63 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
}
if ( V_101 )
F_27 ( V_43 , V_2 ) ;
V_107:
F_117 ( V_2 -> V_3 & ( V_6 - 1 ) , V_2 -> V_49 ) ;
F_27 ( V_43 , V_2 ) ;
V_2 -> V_14 = V_2 -> V_3 ;
F_19 ( & V_8 -> V_24 , V_26 , V_109 ) ;
if ( F_118 ( & V_8 -> V_54 ) )
F_32 ( & V_8 -> V_54 ) ;
return 0 ;
}
}
V_101 = ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) ) ? 1 : 0 ;
if ( F_59 ( V_8 ) ) {
F_68 ( V_2 ) ;
if ( V_43 == '\n' )
F_65 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_14 == V_2 -> V_3 )
F_63 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
}
F_57 ( V_8 ) ;
}
if ( V_101 )
F_27 ( V_43 , V_2 ) ;
F_27 ( V_43 , V_2 ) ;
return 0 ;
}
static inline void
F_119 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_101 ;
if ( V_8 -> V_104 && ! V_8 -> V_105 && F_96 ( V_8 ) && F_106 ( V_8 ) ) {
F_97 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( F_59 ( V_8 ) ) {
F_68 ( V_2 ) ;
if ( V_2 -> V_14 == V_2 -> V_3 )
F_63 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
}
V_101 = ( V_43 == ( unsigned char ) '\377' && F_10 ( V_8 ) ) ? 1 : 0 ;
if ( V_101 )
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
if ( V_8 -> V_104 && ! V_8 -> V_105 && F_96 ( V_8 ) && F_106 ( V_8 ) ) {
F_97 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( F_59 ( V_8 ) ) {
F_68 ( V_2 ) ;
if ( V_2 -> V_14 == V_2 -> V_3 )
F_63 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
F_57 ( V_8 ) ;
}
F_27 ( V_43 , V_2 ) ;
}
static inline void
F_122 ( struct V_7 * V_8 , unsigned char V_43 )
{
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_110 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
if ( F_96 ( V_8 ) ) {
if ( V_43 == F_100 ( V_8 ) )
F_101 ( V_8 ) ;
else if ( V_43 == F_99 ( V_8 ) ||
( V_8 -> V_104 && ! V_8 -> V_105 && F_106 ( V_8 ) &&
V_43 != F_103 ( V_8 ) && V_43 != F_104 ( V_8 ) &&
V_43 != F_105 ( V_8 ) ) ) {
F_97 ( V_8 ) ;
F_58 ( V_8 ) ;
}
}
}
static void
F_125 ( struct V_7 * V_8 , unsigned char V_43 , char V_110 )
{
char V_21 [ 64 ] ;
switch ( V_110 ) {
case V_111 :
F_81 ( V_8 ) ;
break;
case V_112 :
case V_113 :
F_92 ( V_8 , V_43 ) ;
break;
case V_114 :
F_88 ( V_8 ) ;
break;
default:
F_90 ( V_115 L_7 ,
F_91 ( V_8 , V_21 ) , V_110 ) ;
break;
}
}
static void
F_126 ( struct V_7 * V_8 , unsigned char V_43 , char V_110 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_106 = 0 ;
if ( F_127 ( V_110 == V_116 ) ) {
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_110 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
F_120 ( V_8 , V_43 ) ;
} else
F_125 ( V_8 , V_43 , V_110 ) ;
}
static void
F_128 ( struct V_7 * V_8 , const unsigned char * V_66 ,
char * V_117 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_23 , V_81 ;
V_81 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_23 = V_6 - F_129 ( F_1 ( V_2 ) , V_81 ) ;
V_23 = F_130 ( T_1 , V_38 , V_23 ) ;
memcpy ( F_3 ( V_2 , V_81 ) , V_66 , V_23 ) ;
V_2 -> V_3 += V_23 ;
V_66 += V_23 ;
V_38 -= V_23 ;
V_81 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_23 = V_6 - F_129 ( F_1 ( V_2 ) , V_81 ) ;
V_23 = F_130 ( T_1 , V_38 , V_23 ) ;
memcpy ( F_3 ( V_2 , V_81 ) , V_66 , V_23 ) ;
V_2 -> V_3 += V_23 ;
}
static void
F_131 ( struct V_7 * V_8 , const unsigned char * V_66 ,
char * V_117 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_110 = V_116 ;
while ( V_38 -- ) {
if ( V_117 )
V_110 = * V_117 ++ ;
if ( F_127 ( V_110 == V_116 ) )
F_27 ( * V_66 ++ , V_2 ) ;
else
F_125 ( V_8 , * V_66 ++ , V_110 ) ;
}
}
static void
F_132 ( struct V_7 * V_8 , const unsigned char * V_66 ,
char * V_117 , int V_38 )
{
char V_110 = V_116 ;
while ( V_38 -- ) {
if ( V_117 )
V_110 = * V_117 ++ ;
if ( F_127 ( V_110 == V_116 ) )
F_122 ( V_8 , * V_66 ++ ) ;
else
F_125 ( V_8 , * V_66 ++ , V_110 ) ;
}
}
static void
F_133 ( struct V_7 * V_8 , const unsigned char * V_66 ,
char * V_117 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_110 = V_116 ;
while ( V_38 -- ) {
if ( V_117 )
V_110 = * V_117 ++ ;
if ( F_127 ( V_110 == V_116 ) ) {
unsigned char V_43 = * V_66 ++ ;
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_110 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
if ( F_134 ( V_8 ) ) {
F_27 ( V_43 , V_2 ) ;
continue;
}
if ( ! F_14 ( V_43 , V_2 -> V_118 ) )
F_119 ( V_8 , V_43 ) ;
else if ( F_98 ( V_8 , V_43 ) && V_38 ) {
if ( V_117 )
V_110 = * V_117 ++ ;
F_126 ( V_8 , * V_66 ++ , V_110 ) ;
V_38 -- ;
}
} else
F_125 ( V_8 , * V_66 ++ , V_110 ) ;
}
}
static void
F_135 ( struct V_7 * V_8 , const unsigned char * V_66 ,
char * V_117 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_110 = V_116 ;
while ( V_38 -- ) {
if ( V_117 )
V_110 = * V_117 ++ ;
if ( F_127 ( V_110 == V_116 ) ) {
unsigned char V_43 = * V_66 ++ ;
if ( ! F_14 ( V_43 , V_2 -> V_118 ) )
F_121 ( V_8 , V_43 ) ;
else if ( F_98 ( V_8 , V_43 ) && V_38 ) {
if ( V_117 )
V_110 = * V_117 ++ ;
F_126 ( V_8 , * V_66 ++ , V_110 ) ;
V_38 -- ;
}
} else
F_125 ( V_8 , * V_66 ++ , V_110 ) ;
}
}
static void F_136 ( struct V_7 * V_8 , const unsigned char * V_66 ,
char * V_117 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
bool V_119 = F_123 ( V_8 ) || ( F_124 ( V_8 ) && F_110 ( V_8 ) ) ;
if ( V_2 -> V_120 )
F_128 ( V_8 , V_66 , V_117 , V_38 ) ;
else if ( V_2 -> V_121 || ( F_134 ( V_8 ) && ! V_119 ) )
F_131 ( V_8 , V_66 , V_117 , V_38 ) ;
else if ( V_8 -> V_122 && ! F_134 ( V_8 ) )
F_132 ( V_8 , V_66 , V_117 , V_38 ) ;
else {
if ( V_2 -> V_106 ) {
char V_110 = V_116 ;
if ( V_117 )
V_110 = * V_117 ++ ;
F_126 ( V_8 , * V_66 ++ , V_110 ) ;
V_38 -- ;
}
if ( ! V_119 && ! F_10 ( V_8 ) )
F_135 ( V_8 , V_66 , V_117 , V_38 ) ;
else
F_133 ( V_8 , V_66 , V_117 , V_38 ) ;
F_60 ( V_8 ) ;
if ( V_8 -> V_35 -> V_84 )
V_8 -> V_35 -> V_84 ( V_8 ) ;
}
if ( ( ! V_2 -> V_12 && ( F_1 ( V_2 ) >= V_2 -> V_123 ) ) ||
F_134 ( V_8 ) ) {
F_19 ( & V_8 -> V_24 , V_26 , V_109 ) ;
if ( F_118 ( & V_8 -> V_54 ) )
F_32 ( & V_8 -> V_54 ) ;
}
}
static void F_137 ( struct V_7 * V_8 , const unsigned char * V_66 ,
char * V_117 , int V_38 )
{
int V_124 , V_23 ;
F_87 ( & V_8 -> V_55 ) ;
while ( 1 ) {
V_124 = F_9 ( V_8 ) ;
V_23 = F_138 ( V_38 , V_124 ) ;
if ( ! V_23 )
break;
F_136 ( V_8 , V_66 , V_117 , V_23 ) ;
V_66 += V_23 ;
if ( V_117 )
V_117 += V_23 ;
V_38 -= V_23 ;
}
V_8 -> F_9 = V_124 ;
F_20 ( V_8 ) ;
F_85 ( & V_8 -> V_55 ) ;
}
static int F_139 ( struct V_7 * V_8 , const unsigned char * V_66 ,
char * V_117 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_124 , V_23 , V_125 = 0 ;
F_87 ( & V_8 -> V_55 ) ;
while ( 1 ) {
V_124 = F_9 ( V_8 ) ;
V_23 = F_138 ( V_38 , V_124 ) ;
if ( ! V_23 ) {
if ( ! V_124 )
V_2 -> V_15 = 1 ;
break;
}
F_136 ( V_8 , V_66 , V_117 , V_23 ) ;
V_66 += V_23 ;
if ( V_117 )
V_117 += V_23 ;
V_38 -= V_23 ;
V_125 += V_23 ;
}
V_8 -> F_9 = V_124 ;
F_20 ( V_8 ) ;
F_85 ( & V_8 -> V_55 ) ;
return V_125 ;
}
int F_140 ( int V_92 )
{
return ( F_141 ( & V_126 -> V_127 , V_92 ) ||
V_126 -> V_128 -> V_129 [ V_92 - 1 ] . V_130 . V_131 == V_132 ) ;
}
static void F_142 ( struct V_7 * V_8 , struct V_133 * V_79 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_134 = 1 ;
if ( V_79 )
V_134 = ( V_79 -> V_135 ^ V_8 -> V_136 . V_135 ) & V_137 ;
if ( V_134 ) {
F_29 ( V_2 -> V_49 , V_6 ) ;
V_2 -> V_47 = V_2 -> V_14 = V_2 -> V_4 ;
V_2 -> V_48 = 0 ;
V_2 -> V_106 = 0 ;
}
if ( V_134 && ! F_143 ( V_8 ) && F_1 ( V_2 ) )
F_32 ( & V_8 -> V_54 ) ;
V_2 -> V_12 = ( F_143 ( V_8 ) != 0 ) ;
if ( F_123 ( V_8 ) || F_124 ( V_8 ) || F_107 ( V_8 ) ||
F_108 ( V_8 ) || F_109 ( V_8 ) || F_143 ( V_8 ) ||
F_96 ( V_8 ) || F_102 ( V_8 ) || F_59 ( V_8 ) ||
F_10 ( V_8 ) ) {
F_29 ( V_2 -> V_118 , 256 ) ;
if ( F_107 ( V_8 ) || F_108 ( V_8 ) )
F_117 ( '\r' , V_2 -> V_118 ) ;
if ( F_109 ( V_8 ) )
F_117 ( '\n' , V_2 -> V_118 ) ;
if ( F_143 ( V_8 ) ) {
F_117 ( F_70 ( V_8 ) , V_2 -> V_118 ) ;
F_117 ( F_75 ( V_8 ) , V_2 -> V_118 ) ;
F_117 ( F_114 ( V_8 ) , V_2 -> V_118 ) ;
F_117 ( '\n' , V_2 -> V_118 ) ;
F_117 ( F_115 ( V_8 ) , V_2 -> V_118 ) ;
if ( F_110 ( V_8 ) ) {
F_117 ( F_71 ( V_8 ) , V_2 -> V_118 ) ;
F_117 ( F_111 ( V_8 ) , V_2 -> V_118 ) ;
F_117 ( F_116 ( V_8 ) , V_2 -> V_118 ) ;
if ( F_59 ( V_8 ) )
F_117 ( F_112 ( V_8 ) ,
V_2 -> V_118 ) ;
}
}
if ( F_96 ( V_8 ) ) {
F_117 ( F_99 ( V_8 ) , V_2 -> V_118 ) ;
F_117 ( F_100 ( V_8 ) , V_2 -> V_118 ) ;
}
if ( F_102 ( V_8 ) ) {
F_117 ( F_103 ( V_8 ) , V_2 -> V_118 ) ;
F_117 ( F_104 ( V_8 ) , V_2 -> V_118 ) ;
F_117 ( F_105 ( V_8 ) , V_2 -> V_118 ) ;
}
F_144 ( V_108 , V_2 -> V_118 ) ;
V_2 -> V_121 = 0 ;
V_2 -> V_120 = 0 ;
} else {
V_2 -> V_121 = 1 ;
if ( ( F_82 ( V_8 ) || ( ! F_83 ( V_8 ) && ! F_10 ( V_8 ) ) ) &&
( F_93 ( V_8 ) || ! F_94 ( V_8 ) ) &&
( V_8 -> V_28 -> V_19 & V_138 ) )
V_2 -> V_120 = 1 ;
else
V_2 -> V_120 = 0 ;
}
F_11 ( V_8 ) ;
if ( ! F_96 ( V_8 ) && V_79 && ( V_79 -> V_139 & V_140 ) && ! V_8 -> V_105 ) {
F_97 ( V_8 ) ;
}
F_32 ( & V_8 -> V_39 ) ;
F_32 ( & V_8 -> V_54 ) ;
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
V_2 -> V_98 = V_97 ;
F_149 ( & V_2 -> V_142 ) ;
F_149 ( & V_2 -> V_64 ) ;
V_8 -> V_11 = V_2 ;
F_28 ( V_8 -> V_11 ) ;
V_2 -> V_59 = 0 ;
V_2 -> V_60 = 0 ;
V_2 -> V_123 = 1 ;
V_2 -> V_96 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_106 = 0 ;
V_8 -> V_122 = 0 ;
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
T_1 * V_65 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_63 ;
T_1 V_23 ;
bool V_146 ;
T_1 V_69 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_63 = 0 ;
V_23 = F_138 ( F_1 ( V_2 ) , V_6 - V_69 ) ;
V_23 = F_138 ( * V_65 , V_23 ) ;
if ( V_23 ) {
V_63 = F_153 ( * V_145 , F_3 ( V_2 , V_69 ) , V_23 ) ;
V_23 -= V_63 ;
V_146 = V_23 == 1 && F_2 ( V_2 , V_69 ) == F_114 ( V_8 ) ;
F_7 ( V_8 , F_3 ( V_2 , V_69 ) , V_23 ,
V_2 -> V_12 ) ;
V_2 -> V_4 += V_23 ;
if ( F_134 ( V_8 ) && V_2 -> V_12 && V_146 && ! F_1 ( V_2 ) )
V_23 = 0 ;
* V_145 += V_23 ;
* V_65 -= V_23 ;
}
return V_63 ;
}
static int F_154 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_145 ,
T_1 * V_65 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_23 , V_147 , V_148 , V_43 ;
T_1 V_149 ;
T_1 V_69 ;
int V_150 , V_151 = 0 ;
bool V_152 = 0 ;
V_23 = F_138 ( * V_65 , F_1 ( V_2 ) ) ;
if ( ! V_23 )
return 0 ;
V_69 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_147 = F_130 ( T_1 , V_69 + V_23 , V_6 ) ;
F_155 ( L_8 ,
V_56 , * V_65 , V_69 , V_23 , V_147 ) ;
V_149 = F_156 ( V_2 -> V_49 , V_147 , V_69 ) ;
V_148 = V_23 - ( V_147 - V_69 ) ;
if ( V_149 == V_6 && V_148 ) {
V_149 = F_156 ( V_2 -> V_49 , V_148 , 0 ) ;
if ( V_149 != V_148 )
V_151 = 1 ;
} else if ( V_149 != V_147 )
V_151 = 1 ;
V_147 = V_6 - V_69 ;
V_23 = ( V_151 + V_149 + V_147 ) & ( V_6 - 1 ) ;
V_43 = V_23 ;
if ( V_151 && F_2 ( V_2 , V_149 ) == V_108 ) {
V_23 -- ;
V_152 = ! V_23 && V_2 -> V_4 != V_2 -> V_47 ;
}
F_155 ( L_9 ,
V_56 , V_149 , V_151 , V_23 , V_43 , V_147 , V_148 ) ;
if ( V_23 > V_147 ) {
V_150 = F_153 ( * V_145 , F_3 ( V_2 , V_69 ) , V_147 ) ;
if ( V_150 )
return - V_153 ;
V_150 = F_153 ( * V_145 + V_147 , V_2 -> F_2 , V_23 - V_147 ) ;
} else
V_150 = F_153 ( * V_145 , F_3 ( V_2 , V_69 ) , V_23 ) ;
if ( V_150 )
return - V_153 ;
* V_145 += V_23 ;
* V_65 -= V_23 ;
if ( V_151 )
F_144 ( V_149 , V_2 -> V_49 ) ;
F_157 () ;
V_2 -> V_4 += V_43 ;
if ( V_151 ) {
V_2 -> V_47 = V_2 -> V_4 ;
F_158 ( V_8 ) ;
}
return V_152 ? - V_154 : 0 ;
}
static int F_159 ( struct V_7 * V_8 , struct V_155 * V_155 )
{
if ( V_155 -> V_156 -> V_61 == V_157 ||
V_126 -> signal -> V_8 != V_8 )
return 0 ;
F_160 ( & V_8 -> V_50 ) ;
if ( ! V_8 -> V_158 )
F_90 ( V_115 L_10 ) ;
else if ( F_161 ( V_126 ) != V_8 -> V_158 ) {
F_162 ( & V_8 -> V_50 ) ;
if ( F_140 ( V_159 ) || F_163 () )
return - V_160 ;
F_79 ( F_161 ( V_126 ) , V_159 , 1 ) ;
F_164 ( V_161 ) ;
return - V_162 ;
}
F_162 ( & V_8 -> V_50 ) ;
return 0 ;
}
static T_3 F_165 ( struct V_7 * V_8 , struct V_155 * V_155 ,
unsigned char T_2 * V_21 , T_1 V_65 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned char T_2 * V_145 = V_21 ;
F_166 ( V_163 , V_126 ) ;
int V_43 ;
int V_164 , time ;
T_3 V_63 = 0 ;
long V_165 ;
unsigned long V_19 ;
int V_51 ;
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
F_87 ( & V_8 -> V_55 ) ;
V_164 = time = 0 ;
V_165 = V_168 ;
if ( ! V_2 -> V_12 ) {
V_164 = F_169 ( V_8 ) ;
if ( V_164 ) {
time = ( V_99 / 10 ) * F_170 ( V_8 ) ;
if ( time )
V_2 -> V_123 = 1 ;
else if ( ! F_118 ( & V_8 -> V_54 ) ||
( V_2 -> V_123 > V_164 ) )
V_2 -> V_123 = V_164 ;
} else {
V_165 = ( V_99 / 10 ) * F_170 ( V_8 ) ;
V_2 -> V_123 = V_164 = 1 ;
}
}
V_51 = V_8 -> V_51 ;
F_171 ( & V_8 -> V_54 , & V_163 ) ;
while ( V_65 ) {
if ( V_51 && V_8 -> V_33 -> V_52 ) {
unsigned char V_169 ;
if ( V_145 != V_21 )
break;
F_31 ( & V_8 -> V_33 -> V_50 , V_19 ) ;
V_169 = V_8 -> V_33 -> V_52 ;
V_8 -> V_33 -> V_52 = 0 ;
F_33 ( & V_8 -> V_33 -> V_50 , V_19 ) ;
if ( F_6 ( V_8 , V_169 , V_145 ++ ) ) {
V_63 = - V_153 ;
V_145 -- ;
break;
}
V_65 -- ;
break;
}
F_172 ( V_170 ) ;
if ( ( ( V_164 - ( V_145 - V_21 ) ) < V_2 -> V_123 ) &&
( ( V_164 - ( V_145 - V_21 ) ) >= 1 ) )
V_2 -> V_123 = ( V_164 - ( V_145 - V_21 ) ) ;
if ( ! F_151 ( V_8 , 0 ) ) {
if ( F_14 ( V_171 , & V_8 -> V_19 ) ) {
F_85 ( & V_8 -> V_55 ) ;
F_173 ( V_8 ) ;
F_87 ( & V_8 -> V_55 ) ;
if ( ! F_151 ( V_8 , 0 ) ) {
V_63 = - V_160 ;
break;
}
} else {
if ( F_174 ( V_155 ) )
break;
if ( ! V_165 )
break;
if ( V_155 -> V_166 & V_167 ) {
V_63 = - V_154 ;
break;
}
if ( F_175 ( V_126 ) ) {
V_63 = - V_162 ;
break;
}
F_11 ( V_8 ) ;
F_85 ( & V_8 -> V_55 ) ;
V_165 = F_176 ( V_165 ) ;
F_87 ( & V_8 -> V_55 ) ;
continue;
}
}
F_177 ( V_172 ) ;
if ( V_51 && V_145 == V_21 ) {
if ( F_6 ( V_8 , V_173 , V_145 ++ ) ) {
V_63 = - V_153 ;
V_145 -- ;
break;
}
V_65 -- ;
}
if ( V_2 -> V_12 && ! F_134 ( V_8 ) ) {
V_63 = F_154 ( V_8 , & V_145 , & V_65 ) ;
if ( V_63 == - V_154 ) {
V_63 = 0 ;
continue;
} else if ( V_63 )
break;
} else {
int V_174 ;
V_174 = F_152 ( V_8 , & V_145 , & V_65 ) ;
V_174 += F_152 ( V_8 , & V_145 , & V_65 ) ;
if ( V_174 ) {
V_63 = - V_153 ;
break;
}
}
F_24 ( V_8 ) ;
if ( V_145 - V_21 >= V_164 )
break;
if ( time )
V_165 = time ;
}
F_53 ( & V_2 -> V_142 ) ;
F_178 ( & V_8 -> V_54 , & V_163 ) ;
if ( ! F_118 ( & V_8 -> V_54 ) )
V_2 -> V_123 = V_164 ;
F_177 ( V_172 ) ;
if ( V_145 - V_21 )
V_63 = V_145 - V_21 ;
F_11 ( V_8 ) ;
F_85 ( & V_8 -> V_55 ) ;
return V_63 ;
}
static T_3 F_179 ( struct V_7 * V_8 , struct V_155 * V_155 ,
const unsigned char * V_21 , T_1 V_65 )
{
const unsigned char * V_145 = V_21 ;
F_166 ( V_163 , V_126 ) ;
int V_43 ;
T_3 V_63 = 0 ;
if ( F_180 ( V_8 ) && V_155 -> V_156 -> V_61 != V_157 ) {
V_63 = F_181 ( V_8 ) ;
if ( V_63 )
return V_63 ;
}
F_87 ( & V_8 -> V_55 ) ;
F_58 ( V_8 ) ;
F_171 ( & V_8 -> V_39 , & V_163 ) ;
while ( 1 ) {
F_172 ( V_170 ) ;
if ( F_175 ( V_126 ) ) {
V_63 = - V_162 ;
break;
}
if ( F_174 ( V_155 ) || ( V_8 -> V_33 && ! V_8 -> V_33 -> V_38 ) ) {
V_63 = - V_160 ;
break;
}
if ( F_56 ( V_8 ) ) {
while ( V_65 > 0 ) {
T_3 V_175 = F_54 ( V_8 , V_145 , V_65 ) ;
if ( V_175 < 0 ) {
if ( V_175 == - V_154 )
break;
V_63 = V_175 ;
goto V_67;
}
V_145 += V_175 ;
V_65 -= V_175 ;
if ( V_65 == 0 )
break;
V_43 = * V_145 ;
if ( F_50 ( V_43 , V_8 ) < 0 )
break;
V_145 ++ ; V_65 -- ;
}
if ( V_8 -> V_35 -> V_84 )
V_8 -> V_35 -> V_84 ( V_8 ) ;
} else {
while ( V_65 > 0 ) {
V_43 = V_8 -> V_35 -> V_61 ( V_8 , V_145 , V_65 ) ;
if ( V_43 < 0 ) {
V_63 = V_43 ;
goto V_67;
}
if ( ! V_43 )
break;
V_145 += V_43 ;
V_65 -= V_43 ;
}
}
if ( ! V_65 )
break;
if ( V_155 -> V_166 & V_167 ) {
V_63 = - V_154 ;
break;
}
F_85 ( & V_8 -> V_55 ) ;
F_182 () ;
F_87 ( & V_8 -> V_55 ) ;
}
V_67:
F_177 ( V_172 ) ;
F_178 ( & V_8 -> V_39 , & V_163 ) ;
if ( V_145 - V_21 != V_65 && V_8 -> V_24 )
F_117 ( V_25 , & V_8 -> V_19 ) ;
F_85 ( & V_8 -> V_55 ) ;
return ( V_145 - V_21 ) ? V_145 - V_21 : V_63 ;
}
static unsigned int F_183 ( struct V_7 * V_8 , struct V_155 * V_155 ,
T_4 * V_163 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned int V_176 = 0 ;
F_184 ( V_155 , & V_8 -> V_54 , V_163 ) ;
F_184 ( V_155 , & V_8 -> V_39 , V_163 ) ;
if ( F_151 ( V_8 , F_170 ( V_8 ) ? 0 : F_169 ( V_8 ) ) )
V_176 |= V_177 | V_178 ;
if ( V_8 -> V_51 && V_8 -> V_33 -> V_52 )
V_176 |= V_179 | V_177 | V_178 ;
if ( F_14 ( V_171 , & V_8 -> V_19 ) )
V_176 |= V_180 ;
if ( F_174 ( V_155 ) )
V_176 |= V_180 ;
if ( ! ( V_176 & ( V_180 | V_177 | V_178 ) ) ) {
if ( F_169 ( V_8 ) && ! F_170 ( V_8 ) )
V_2 -> V_123 = F_169 ( V_8 ) ;
else
V_2 -> V_123 = 1 ;
}
if ( V_8 -> V_35 -> V_61 && ! F_185 ( V_8 ) &&
F_186 ( V_8 ) < V_181 &&
F_52 ( V_8 ) > 0 )
V_176 |= V_40 | V_182 ;
return V_176 ;
}
static unsigned long F_187 ( struct V_1 * V_2 )
{
T_1 V_65 , V_81 , V_69 ;
if ( V_2 -> V_14 == V_2 -> V_4 )
return 0 ;
V_81 = V_2 -> V_14 ;
V_69 = V_2 -> V_4 ;
V_65 = V_81 - V_69 ;
while ( V_81 != V_69 ) {
if ( F_14 ( V_69 & ( V_6 - 1 ) , V_2 -> V_49 ) &&
F_2 ( V_2 , V_69 ) == V_108 )
V_65 -- ;
V_69 ++ ;
}
return V_65 ;
}
static int F_188 ( struct V_7 * V_8 , struct V_155 * V_155 ,
unsigned int V_183 , unsigned long V_184 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_63 ;
switch ( V_183 ) {
case V_185 :
return F_8 ( F_186 ( V_8 ) , ( int T_2 * ) V_184 ) ;
case V_186 :
F_35 ( & V_8 -> V_55 ) ;
if ( F_143 ( V_8 ) )
V_63 = F_187 ( V_2 ) ;
else
V_63 = F_1 ( V_2 ) ;
F_36 ( & V_8 -> V_55 ) ;
return F_8 ( V_63 , ( unsigned int T_2 * ) V_184 ) ;
default:
return F_189 ( V_8 , V_155 , V_183 , V_184 ) ;
}
}
static void F_190 ( struct V_7 * V_8 , int V_187 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! F_118 ( & V_8 -> V_54 ) ) {
if ( V_187 )
V_2 -> V_123 = 1 ;
else if ( ! V_8 -> V_24 )
V_2 -> V_123 = V_6 ;
}
}
void F_191 ( struct V_188 * V_35 )
{
* V_35 = V_189 ;
V_35 -> V_190 = NULL ;
V_35 -> V_191 = V_35 -> V_19 = 0 ;
}

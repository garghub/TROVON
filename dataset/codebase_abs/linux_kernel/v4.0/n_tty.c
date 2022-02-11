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
static void F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_10 ( V_2 -> V_13 ) ) {
V_2 -> V_13 = 0 ;
F_11 ( V_8 -> V_14 -> V_15 == NULL ,
L_1 ) ;
F_11 ( F_12 ( V_16 , & V_8 -> V_17 ) ,
L_2 ) ;
F_13 ( V_18 , & V_8 -> V_14 -> V_19 . V_20 ) ;
}
}
static T_3 F_14 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_3 V_21 = 0 ;
if ( ! V_2 -> V_12 )
V_21 = V_2 -> V_22 - V_2 -> V_4 ;
else
V_21 = V_2 -> V_23 - V_2 -> V_4 ;
return V_21 ;
}
static void F_15 ( struct V_7 * V_8 )
{
if ( V_8 -> V_24 && F_16 ( V_25 , & V_8 -> V_17 ) )
F_17 ( & V_8 -> V_24 , V_26 , V_27 ) ;
}
static void F_18 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_2 -> V_12 && V_2 -> V_23 == V_2 -> V_4 )
return;
while ( 1 ) {
int V_28 ;
F_19 ( V_8 , V_29 ) ;
if ( V_6 - F_1 ( V_2 ) >= V_30 )
break;
V_28 = F_20 ( V_8 ) ;
if ( ! V_28 )
break;
}
F_21 ( V_8 , 0 ) ;
}
static void F_22 ( struct V_7 * V_8 )
{
if ( V_8 -> V_31 -> type == V_32 &&
V_8 -> V_33 -> V_34 -> V_35 -> V_36 == F_15 ) {
if ( F_14 ( V_8 ) > V_37 )
return;
if ( ! V_8 -> V_38 )
return;
F_9 ( V_8 ) ;
F_15 ( V_8 -> V_33 ) ;
if ( F_23 ( & V_8 -> V_33 -> V_39 ) )
F_24 ( & V_8 -> V_33 -> V_39 , V_40 ) ;
return;
}
while ( 1 ) {
int V_41 ;
F_19 ( V_8 , V_42 ) ;
if ( F_14 ( V_8 ) > V_37 )
break;
if ( ! V_8 -> V_38 )
break;
F_9 ( V_8 ) ;
V_41 = F_25 ( V_8 ) ;
if ( ! V_41 )
break;
}
F_21 ( V_8 , 0 ) ;
}
static inline void F_26 ( unsigned char V_43 , struct V_1 * V_2 )
{
* F_3 ( V_2 , V_2 -> V_3 ) = V_43 ;
V_2 -> V_3 ++ ;
}
static void F_27 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_23 = V_2 -> V_4 = 0 ;
V_2 -> V_44 = V_2 -> V_45 = V_2 -> V_46 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_49 = 0 ;
F_28 ( V_2 -> V_50 , V_6 ) ;
V_2 -> V_51 = 0 ;
}
static void F_29 ( struct V_7 * V_8 )
{
unsigned long V_17 ;
if ( V_8 -> V_33 -> V_52 ) {
F_30 ( & V_8 -> V_53 , V_17 ) ;
V_8 -> V_54 |= V_55 ;
F_31 ( & V_8 -> V_53 , V_17 ) ;
if ( F_23 ( & V_8 -> V_33 -> V_56 ) )
F_32 ( & V_8 -> V_33 -> V_56 ) ;
}
}
static void F_33 ( struct V_7 * V_8 )
{
F_34 ( & V_8 -> V_57 ) ;
F_27 ( V_8 -> V_11 ) ;
F_9 ( V_8 ) ;
if ( V_8 -> V_33 )
F_29 ( V_8 ) ;
F_35 ( & V_8 -> V_57 ) ;
}
static T_3 F_36 ( struct V_7 * V_8 )
{
T_3 V_21 ;
F_37 ( 1 , L_3 , V_58 ) ;
F_34 ( & V_8 -> V_57 ) ;
V_21 = F_14 ( V_8 ) ;
F_35 ( & V_8 -> V_57 ) ;
return V_21 ;
}
static inline int F_38 ( unsigned char V_43 )
{
return ( V_43 & 0xc0 ) == 0x80 ;
}
static inline int F_39 ( unsigned char V_43 , struct V_7 * V_8 )
{
return F_40 ( V_8 ) && F_38 ( V_43 ) ;
}
static int F_41 ( unsigned char V_43 , struct V_7 * V_8 , int V_59 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_60 ;
if ( ! V_59 )
return - 1 ;
switch ( V_43 ) {
case '\n' :
if ( F_42 ( V_8 ) )
V_2 -> V_61 = 0 ;
if ( F_43 ( V_8 ) ) {
if ( V_59 < 2 )
return - 1 ;
V_2 -> V_62 = V_2 -> V_61 = 0 ;
V_8 -> V_35 -> V_63 ( V_8 , L_4 , 2 ) ;
return 2 ;
}
V_2 -> V_62 = V_2 -> V_61 ;
break;
case '\r' :
if ( F_44 ( V_8 ) && V_2 -> V_61 == 0 )
return 0 ;
if ( F_45 ( V_8 ) ) {
V_43 = '\n' ;
if ( F_42 ( V_8 ) )
V_2 -> V_62 = V_2 -> V_61 = 0 ;
break;
}
V_2 -> V_62 = V_2 -> V_61 = 0 ;
break;
case '\t' :
V_60 = 8 - ( V_2 -> V_61 & 7 ) ;
if ( F_46 ( V_8 ) == V_64 ) {
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
if ( F_47 ( V_8 ) )
V_43 = toupper ( V_43 ) ;
if ( ! F_39 ( V_43 , V_8 ) )
V_2 -> V_61 ++ ;
}
break;
}
F_48 ( V_8 , V_43 ) ;
return 1 ;
}
static int F_49 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_59 , V_65 ;
F_50 ( & V_2 -> V_66 ) ;
V_59 = F_51 ( V_8 ) ;
V_65 = F_41 ( V_43 , V_8 , V_59 ) ;
F_52 ( & V_2 -> V_66 ) ;
if ( V_65 < 0 )
return - 1 ;
else
return 0 ;
}
static T_3 F_53 ( struct V_7 * V_8 ,
const unsigned char * V_19 , unsigned int V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_59 ;
int V_5 ;
const unsigned char * V_68 ;
F_50 ( & V_2 -> V_66 ) ;
V_59 = F_51 ( V_8 ) ;
if ( ! V_59 ) {
F_52 ( & V_2 -> V_66 ) ;
return 0 ;
}
if ( V_67 > V_59 )
V_67 = V_59 ;
for ( V_5 = 0 , V_68 = V_19 ; V_5 < V_67 ; V_5 ++ , V_68 ++ ) {
unsigned char V_43 = * V_68 ;
switch ( V_43 ) {
case '\n' :
if ( F_42 ( V_8 ) )
V_2 -> V_61 = 0 ;
if ( F_43 ( V_8 ) )
goto V_69;
V_2 -> V_62 = V_2 -> V_61 ;
break;
case '\r' :
if ( F_44 ( V_8 ) && V_2 -> V_61 == 0 )
goto V_69;
if ( F_45 ( V_8 ) )
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
if ( F_47 ( V_8 ) )
goto V_69;
if ( ! F_39 ( V_43 , V_8 ) )
V_2 -> V_61 ++ ;
}
break;
}
}
V_69:
V_5 = V_8 -> V_35 -> V_63 ( V_8 , V_19 , V_5 ) ;
F_52 ( & V_2 -> V_66 ) ;
return V_5 ;
}
static T_1 F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_59 , V_70 ;
T_1 V_71 ;
unsigned char V_43 ;
V_70 = V_59 = F_51 ( V_8 ) ;
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
F_48 ( V_8 , '\b' ) ;
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
F_48 ( V_8 , V_72 ) ;
V_2 -> V_61 ++ ;
V_59 -- ;
V_71 += 2 ;
break;
default:
if ( V_59 < 2 ) {
V_74 = 1 ;
break;
}
F_48 ( V_8 , '^' ) ;
F_48 ( V_8 , V_73 ^ 0100 ) ;
V_2 -> V_61 += 2 ;
V_59 -= 2 ;
V_71 += 2 ;
}
if ( V_74 )
break;
} else {
if ( F_55 ( V_8 ) ) {
int V_65 = F_41 ( V_43 , V_8 , V_59 ) ;
if ( V_65 < 0 )
break;
V_59 -= V_65 ;
} else {
if ( ! V_59 )
break;
F_48 ( V_8 , V_43 ) ;
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
static void F_56 ( struct V_7 * V_8 )
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
F_50 ( & V_2 -> V_66 ) ;
V_2 -> V_46 = V_83 ;
V_82 = F_54 ( V_8 ) ;
F_52 ( & V_2 -> V_66 ) ;
if ( V_82 && V_8 -> V_35 -> V_86 )
V_8 -> V_35 -> V_86 ( V_8 ) ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_82 ;
if ( V_2 -> V_47 == V_2 -> V_45 )
return;
F_50 ( & V_2 -> V_66 ) ;
V_2 -> V_46 = V_2 -> V_47 ;
V_82 = F_54 ( V_8 ) ;
F_52 ( & V_2 -> V_66 ) ;
if ( V_82 && V_8 -> V_35 -> V_86 )
V_8 -> V_35 -> V_86 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ( ! F_59 ( V_8 ) && ! F_60 ( V_8 ) ) ||
V_2 -> V_46 == V_2 -> V_44 )
return;
F_50 ( & V_2 -> V_66 ) ;
V_2 -> V_46 = V_2 -> V_44 ;
F_54 ( V_8 ) ;
F_52 ( & V_2 -> V_66 ) ;
}
static inline void F_61 ( unsigned char V_43 , struct V_1 * V_2 )
{
* F_5 ( V_2 , V_2 -> V_44 ++ ) = V_43 ;
}
static void F_62 ( struct V_1 * V_2 )
{
F_61 ( V_72 , V_2 ) ;
F_61 ( V_79 , V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_61 ( V_72 , V_2 ) ;
F_61 ( V_78 , V_2 ) ;
}
static void F_64 ( unsigned int V_75 , int V_87 ,
struct V_1 * V_2 )
{
F_61 ( V_72 , V_2 ) ;
F_61 ( V_77 , V_2 ) ;
V_75 &= 7 ;
if ( V_87 )
V_75 |= 0x80 ;
F_61 ( V_75 , V_2 ) ;
}
static void F_65 ( unsigned char V_43 , struct V_1 * V_2 )
{
if ( V_43 == V_72 ) {
F_61 ( V_72 , V_2 ) ;
F_61 ( V_72 , V_2 ) ;
} else {
F_61 ( V_43 , V_2 ) ;
}
}
static void F_66 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_43 == V_72 ) {
F_61 ( V_72 , V_2 ) ;
F_61 ( V_72 , V_2 ) ;
} else {
if ( F_67 ( V_8 ) && iscntrl ( V_43 ) && V_43 != '\t' )
F_61 ( V_72 , V_2 ) ;
F_61 ( V_43 , V_2 ) ;
}
}
static inline void F_68 ( struct V_1 * V_2 )
{
if ( V_2 -> V_49 ) {
F_65 ( '/' , V_2 ) ;
V_2 -> V_49 = 0 ;
}
}
static void F_69 ( unsigned char V_43 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
enum { V_88 , V_89 , V_90 } V_91 ;
T_1 V_83 ;
T_1 V_92 ;
int V_93 ;
if ( V_2 -> V_3 == V_2 -> V_23 ) {
return;
}
if ( V_43 == F_70 ( V_8 ) )
V_91 = V_88 ;
else if ( V_43 == F_71 ( V_8 ) )
V_91 = V_89 ;
else {
if ( ! F_59 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_23 ;
return;
}
if ( ! F_72 ( V_8 ) || ! F_73 ( V_8 ) || ! F_74 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_23 ;
F_68 ( V_2 ) ;
F_66 ( F_75 ( V_8 ) , V_8 ) ;
if ( F_72 ( V_8 ) )
F_65 ( '\n' , V_2 ) ;
return;
}
V_91 = V_90 ;
}
V_93 = 0 ;
while ( V_2 -> V_3 != V_2 -> V_23 ) {
V_83 = V_2 -> V_3 ;
do {
V_83 -- ;
V_43 = F_2 ( V_2 , V_83 ) ;
} while ( F_39 ( V_43 , V_8 ) && V_83 != V_2 -> V_23 );
if ( F_39 ( V_43 , V_8 ) )
break;
if ( V_91 == V_89 ) {
if ( isalnum ( V_43 ) || V_43 == '_' )
V_93 ++ ;
else if ( V_93 )
break;
}
V_92 = V_2 -> V_3 - V_83 ;
V_2 -> V_3 = V_83 ;
if ( F_59 ( V_8 ) ) {
if ( F_76 ( V_8 ) ) {
if ( ! V_2 -> V_49 ) {
F_65 ( '\\' , V_2 ) ;
V_2 -> V_49 = 1 ;
}
F_66 ( V_43 , V_8 ) ;
while ( -- V_92 > 0 ) {
V_83 ++ ;
F_65 ( F_2 ( V_2 , V_83 ) , V_2 ) ;
F_62 ( V_2 ) ;
}
} else if ( V_91 == V_88 && ! F_74 ( V_8 ) ) {
F_66 ( F_70 ( V_8 ) , V_8 ) ;
} else if ( V_43 == '\t' ) {
unsigned int V_75 = 0 ;
int V_87 = 0 ;
T_1 V_71 = V_2 -> V_3 ;
while ( V_71 != V_2 -> V_23 ) {
V_71 -- ;
V_43 = F_2 ( V_2 , V_71 ) ;
if ( V_43 == '\t' ) {
V_87 = 1 ;
break;
} else if ( iscntrl ( V_43 ) ) {
if ( F_67 ( V_8 ) )
V_75 += 2 ;
} else if ( ! F_39 ( V_43 , V_8 ) ) {
V_75 ++ ;
}
}
F_64 ( V_75 , V_87 , V_2 ) ;
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
if ( V_91 == V_88 )
break;
}
if ( V_2 -> V_3 == V_2 -> V_23 && F_59 ( V_8 ) )
F_68 ( V_2 ) ;
}
static void F_77 ( int V_94 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
struct V_95 * V_96 = F_78 ( V_8 ) ;
if ( V_96 ) {
F_79 ( V_96 , V_94 , 1 ) ;
F_80 ( V_96 ) ;
}
if ( ! F_81 ( V_8 ) ) {
F_82 ( & V_8 -> V_57 ) ;
F_34 ( & V_8 -> V_57 ) ;
F_50 ( & V_2 -> V_66 ) ;
V_2 -> V_44 = V_2 -> V_45 = 0 ;
V_2 -> V_47 = V_2 -> V_46 = 0 ;
F_52 ( & V_2 -> V_66 ) ;
F_83 ( V_8 ) ;
F_27 ( V_8 -> V_11 ) ;
if ( V_8 -> V_33 )
F_29 ( V_8 ) ;
F_35 ( & V_8 -> V_57 ) ;
F_84 ( & V_8 -> V_57 ) ;
}
}
static void F_85 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_86 ( V_8 ) )
return;
if ( F_87 ( V_8 ) ) {
F_77 ( V_97 , V_8 ) ;
return;
}
if ( F_88 ( V_8 ) ) {
F_26 ( '\377' , V_2 ) ;
F_26 ( '\0' , V_2 ) ;
}
F_26 ( '\0' , V_2 ) ;
if ( F_23 ( & V_8 -> V_56 ) )
F_24 ( & V_8 -> V_56 , V_98 ) ;
}
static void F_89 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_19 [ 64 ] ;
V_2 -> V_99 ++ ;
if ( F_90 ( V_100 , V_2 -> V_101 + V_102 ) ||
F_90 ( V_2 -> V_101 , V_100 ) ) {
F_91 ( V_103 L_6 ,
F_92 ( V_8 , V_19 ) ,
V_2 -> V_99 ) ;
V_2 -> V_101 = V_100 ;
V_2 -> V_99 = 0 ;
}
}
static void F_93 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_94 ( V_8 ) ) {
if ( F_95 ( V_8 ) )
return;
if ( F_88 ( V_8 ) ) {
F_26 ( '\377' , V_2 ) ;
F_26 ( '\0' , V_2 ) ;
F_26 ( V_43 , V_2 ) ;
} else
F_26 ( '\0' , V_2 ) ;
} else
F_26 ( V_43 , V_2 ) ;
if ( F_23 ( & V_8 -> V_56 ) )
F_24 ( & V_8 -> V_56 , V_98 ) ;
}
static void
F_96 ( struct V_7 * V_8 , int signal , unsigned char V_43 )
{
F_77 ( signal , V_8 ) ;
if ( F_97 ( V_8 ) )
F_98 ( V_8 ) ;
if ( F_59 ( V_8 ) ) {
F_66 ( V_43 , V_8 ) ;
F_56 ( V_8 ) ;
} else
F_57 ( V_8 ) ;
return;
}
static int
F_99 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
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
F_96 ( V_8 , V_97 , V_43 ) ;
return 0 ;
} else if ( V_43 == F_105 ( V_8 ) ) {
F_96 ( V_8 , V_104 , V_43 ) ;
return 0 ;
} else if ( V_43 == F_106 ( V_8 ) ) {
F_96 ( V_8 , V_105 , V_43 ) ;
return 0 ;
}
}
if ( V_8 -> V_106 && ! V_8 -> V_107 && F_97 ( V_8 ) && F_107 ( V_8 ) ) {
F_98 ( V_8 ) ;
F_57 ( V_8 ) ;
}
if ( V_43 == '\r' ) {
if ( F_108 ( V_8 ) )
return 0 ;
if ( F_109 ( V_8 ) )
V_43 = '\n' ;
} else if ( V_43 == '\n' && F_110 ( V_8 ) )
V_43 = '\r' ;
if ( V_2 -> V_12 ) {
if ( V_43 == F_70 ( V_8 ) || V_43 == F_75 ( V_8 ) ||
( V_43 == F_71 ( V_8 ) && F_111 ( V_8 ) ) ) {
F_69 ( V_43 , V_8 ) ;
F_56 ( V_8 ) ;
return 0 ;
}
if ( V_43 == F_112 ( V_8 ) && F_111 ( V_8 ) ) {
V_2 -> V_108 = 1 ;
if ( F_59 ( V_8 ) ) {
F_68 ( V_2 ) ;
if ( F_67 ( V_8 ) ) {
F_65 ( '^' , V_2 ) ;
F_65 ( '\b' , V_2 ) ;
F_56 ( V_8 ) ;
}
}
return 1 ;
}
if ( V_43 == F_113 ( V_8 ) && F_59 ( V_8 ) && F_111 ( V_8 ) ) {
T_1 V_71 = V_2 -> V_23 ;
F_68 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
F_65 ( '\n' , V_2 ) ;
while ( V_71 != V_2 -> V_3 ) {
F_66 ( F_2 ( V_2 , V_71 ) , V_8 ) ;
V_71 ++ ;
}
F_56 ( V_8 ) ;
return 0 ;
}
if ( V_43 == '\n' ) {
if ( F_59 ( V_8 ) || F_60 ( V_8 ) ) {
F_65 ( '\n' , V_2 ) ;
F_56 ( V_8 ) ;
}
goto V_109;
}
if ( V_43 == F_114 ( V_8 ) ) {
V_43 = V_110 ;
goto V_109;
}
if ( ( V_43 == F_115 ( V_8 ) ) ||
( V_43 == F_116 ( V_8 ) && F_111 ( V_8 ) ) ) {
if ( F_59 ( V_8 ) ) {
if ( V_2 -> V_23 == V_2 -> V_3 )
F_63 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
F_56 ( V_8 ) ;
}
if ( V_43 == ( unsigned char ) '\377' && F_88 ( V_8 ) )
F_26 ( V_43 , V_2 ) ;
V_109:
F_117 ( V_2 -> V_3 & ( V_6 - 1 ) , V_2 -> V_50 ) ;
F_26 ( V_43 , V_2 ) ;
F_118 ( & V_2 -> V_23 , V_2 -> V_3 ) ;
F_17 ( & V_8 -> V_24 , V_26 , V_111 ) ;
if ( F_23 ( & V_8 -> V_56 ) )
F_24 ( & V_8 -> V_56 , V_98 ) ;
return 0 ;
}
}
if ( F_59 ( V_8 ) ) {
F_68 ( V_2 ) ;
if ( V_43 == '\n' )
F_65 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_23 == V_2 -> V_3 )
F_63 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
}
F_56 ( V_8 ) ;
}
if ( V_43 == ( unsigned char ) '\377' && F_88 ( V_8 ) )
F_26 ( V_43 , V_2 ) ;
F_26 ( V_43 , V_2 ) ;
return 0 ;
}
static inline void
F_119 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_106 && ! V_8 -> V_107 && F_97 ( V_8 ) && F_107 ( V_8 ) ) {
F_98 ( V_8 ) ;
F_57 ( V_8 ) ;
}
if ( F_59 ( V_8 ) ) {
F_68 ( V_2 ) ;
if ( V_2 -> V_23 == V_2 -> V_3 )
F_63 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
F_56 ( V_8 ) ;
}
if ( V_43 == ( unsigned char ) '\377' && F_88 ( V_8 ) )
F_26 ( V_43 , V_2 ) ;
F_26 ( V_43 , V_2 ) ;
}
static void F_120 ( struct V_7 * V_8 , unsigned char V_43 )
{
F_119 ( V_8 , V_43 ) ;
}
static inline void
F_121 ( struct V_7 * V_8 , unsigned char V_43 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_106 && ! V_8 -> V_107 && F_97 ( V_8 ) && F_107 ( V_8 ) ) {
F_98 ( V_8 ) ;
F_57 ( V_8 ) ;
}
if ( F_59 ( V_8 ) ) {
F_68 ( V_2 ) ;
if ( V_2 -> V_23 == V_2 -> V_3 )
F_63 ( V_2 ) ;
F_66 ( V_43 , V_8 ) ;
F_56 ( V_8 ) ;
}
F_26 ( V_43 , V_2 ) ;
}
static void F_122 ( struct V_7 * V_8 , unsigned char V_43 )
{
if ( F_123 ( V_8 ) )
V_43 &= 0x7f ;
if ( F_124 ( V_8 ) && F_111 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
if ( F_97 ( V_8 ) ) {
if ( V_43 == F_101 ( V_8 ) )
F_102 ( V_8 ) ;
else if ( V_43 == F_100 ( V_8 ) ||
( V_8 -> V_106 && ! V_8 -> V_107 && F_107 ( V_8 ) &&
V_43 != F_104 ( V_8 ) && V_43 != F_105 ( V_8 ) &&
V_43 != F_106 ( V_8 ) ) ) {
F_98 ( V_8 ) ;
F_57 ( V_8 ) ;
}
}
}
static void
F_125 ( struct V_7 * V_8 , unsigned char V_43 , char V_112 )
{
char V_19 [ 64 ] ;
switch ( V_112 ) {
case V_113 :
F_85 ( V_8 ) ;
break;
case V_114 :
case V_115 :
F_93 ( V_8 , V_43 ) ;
break;
case V_116 :
F_89 ( V_8 ) ;
break;
default:
F_91 ( V_117 L_7 ,
F_92 ( V_8 , V_19 ) , V_112 ) ;
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
if ( F_124 ( V_8 ) && F_111 ( V_8 ) )
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
T_1 V_21 , V_83 ;
V_83 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_21 = F_129 ( T_1 , V_38 , V_6 - V_83 ) ;
memcpy ( F_3 ( V_2 , V_83 ) , V_68 , V_21 ) ;
V_2 -> V_3 += V_21 ;
V_68 += V_21 ;
V_38 -= V_21 ;
V_83 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_21 = F_129 ( T_1 , V_38 , V_6 - V_83 ) ;
memcpy ( F_3 ( V_2 , V_83 ) , V_68 , V_21 ) ;
V_2 -> V_3 += V_21 ;
}
static void
F_130 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_112 = V_118 ;
while ( V_38 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_127 ( V_112 == V_118 ) )
F_26 ( * V_68 ++ , V_2 ) ;
else
F_125 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void
F_131 ( struct V_7 * V_8 , const unsigned char * V_68 ,
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
F_132 ( struct V_7 * V_8 , const unsigned char * V_68 ,
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
if ( F_124 ( V_8 ) && F_111 ( V_8 ) )
V_43 = tolower ( V_43 ) ;
if ( F_133 ( V_8 ) ) {
F_26 ( V_43 , V_2 ) ;
continue;
}
if ( ! F_12 ( V_43 , V_2 -> V_120 ) )
F_119 ( V_8 , V_43 ) ;
else if ( F_99 ( V_8 , V_43 ) && V_38 ) {
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
F_134 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_112 = V_118 ;
while ( V_38 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_127 ( V_112 == V_118 ) ) {
unsigned char V_43 = * V_68 ++ ;
if ( ! F_12 ( V_43 , V_2 -> V_120 ) )
F_121 ( V_8 , V_43 ) ;
else if ( F_99 ( V_8 , V_43 ) && V_38 ) {
if ( V_119 )
V_112 = * V_119 ++ ;
F_126 ( V_8 , * V_68 ++ , V_112 ) ;
V_38 -- ;
}
} else
F_125 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void F_135 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
bool V_121 = F_123 ( V_8 ) || ( F_124 ( V_8 ) && F_111 ( V_8 ) ) ;
if ( V_2 -> V_122 )
F_128 ( V_8 , V_68 , V_119 , V_38 ) ;
else if ( V_2 -> V_123 || ( F_133 ( V_8 ) && ! V_121 ) )
F_130 ( V_8 , V_68 , V_119 , V_38 ) ;
else if ( V_8 -> V_124 && ! F_133 ( V_8 ) )
F_131 ( V_8 , V_68 , V_119 , V_38 ) ;
else {
if ( V_2 -> V_108 ) {
char V_112 = V_118 ;
if ( V_119 )
V_112 = * V_119 ++ ;
F_126 ( V_8 , * V_68 ++ , V_112 ) ;
V_38 -- ;
}
if ( ! V_121 && ! F_88 ( V_8 ) )
F_134 ( V_8 , V_68 , V_119 , V_38 ) ;
else
F_132 ( V_8 , V_68 , V_119 , V_38 ) ;
F_58 ( V_8 ) ;
if ( V_8 -> V_35 -> V_86 )
V_8 -> V_35 -> V_86 ( V_8 ) ;
}
if ( V_2 -> V_12 && ! F_133 ( V_8 ) )
return;
F_118 ( & V_2 -> V_22 , V_2 -> V_3 ) ;
if ( ( F_1 ( V_2 ) >= V_2 -> V_125 ) || F_133 ( V_8 ) ) {
F_17 ( & V_8 -> V_24 , V_26 , V_111 ) ;
if ( F_23 ( & V_8 -> V_56 ) )
F_24 ( & V_8 -> V_56 , V_98 ) ;
}
}
static int
F_136 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 , int V_126 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_127 , V_21 , V_128 = 0 , V_129 ;
F_84 ( & V_8 -> V_57 ) ;
while ( 1 ) {
T_1 V_71 = F_137 ( & V_2 -> V_4 ) ;
V_127 = V_6 - ( V_2 -> V_3 - V_71 ) ;
if ( F_88 ( V_8 ) )
V_127 = ( V_127 + 2 ) / 3 ;
V_127 -- ;
if ( V_127 <= 0 ) {
V_129 = V_2 -> V_12 && V_2 -> V_23 == V_71 ;
if ( V_129 && V_127 < 0 )
V_2 -> V_3 -- ;
V_127 = V_129 ;
V_2 -> V_13 = V_126 && ! V_127 ;
} else
V_129 = 0 ;
V_21 = F_138 ( V_38 , V_127 ) ;
if ( ! V_21 )
break;
if ( ! V_129 || ! V_119 || * V_119 != V_114 )
F_135 ( V_8 , V_68 , V_119 , V_21 ) ;
V_68 += V_21 ;
if ( V_119 )
V_119 += V_21 ;
V_38 -= V_21 ;
V_128 += V_21 ;
}
V_8 -> V_130 = V_127 ;
if ( V_8 -> V_31 -> type == V_32 ) {
if ( V_129 ) {
F_19 ( V_8 , V_42 ) ;
F_25 ( V_8 ) ;
F_21 ( V_8 , 0 ) ;
}
} else
F_18 ( V_8 ) ;
F_82 ( & V_8 -> V_57 ) ;
return V_128 ;
}
static void F_139 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
F_136 ( V_8 , V_68 , V_119 , V_38 , 0 ) ;
}
static int F_140 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_38 )
{
return F_136 ( V_8 , V_68 , V_119 , V_38 , 1 ) ;
}
int F_141 ( int V_94 )
{
return ( F_142 ( & V_131 -> V_132 , V_94 ) ||
V_131 -> V_133 -> V_134 [ V_94 - 1 ] . V_135 . V_136 == V_137 ) ;
}
static void F_143 ( struct V_7 * V_8 , struct V_138 * V_81 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! V_81 || ( V_81 -> V_139 ^ V_8 -> V_140 . V_139 ) & V_141 ) {
F_28 ( V_2 -> V_50 , V_6 ) ;
V_2 -> V_48 = V_2 -> V_4 ;
if ( ! F_144 ( V_8 ) || ! F_1 ( V_2 ) ) {
V_2 -> V_23 = V_2 -> V_4 ;
V_2 -> V_51 = 0 ;
} else {
F_117 ( ( V_2 -> V_3 - 1 ) & ( V_6 - 1 ) ,
V_2 -> V_50 ) ;
V_2 -> V_23 = V_2 -> V_3 ;
V_2 -> V_51 = 1 ;
}
V_2 -> V_22 = V_2 -> V_3 ;
V_2 -> V_49 = 0 ;
V_2 -> V_108 = 0 ;
}
V_2 -> V_12 = ( F_144 ( V_8 ) != 0 ) ;
if ( F_123 ( V_8 ) || F_124 ( V_8 ) || F_108 ( V_8 ) ||
F_109 ( V_8 ) || F_110 ( V_8 ) || F_144 ( V_8 ) ||
F_97 ( V_8 ) || F_103 ( V_8 ) || F_59 ( V_8 ) ||
F_88 ( V_8 ) ) {
F_28 ( V_2 -> V_120 , 256 ) ;
if ( F_108 ( V_8 ) || F_109 ( V_8 ) )
F_117 ( '\r' , V_2 -> V_120 ) ;
if ( F_110 ( V_8 ) )
F_117 ( '\n' , V_2 -> V_120 ) ;
if ( F_144 ( V_8 ) ) {
F_117 ( F_70 ( V_8 ) , V_2 -> V_120 ) ;
F_117 ( F_75 ( V_8 ) , V_2 -> V_120 ) ;
F_117 ( F_114 ( V_8 ) , V_2 -> V_120 ) ;
F_117 ( '\n' , V_2 -> V_120 ) ;
F_117 ( F_115 ( V_8 ) , V_2 -> V_120 ) ;
if ( F_111 ( V_8 ) ) {
F_117 ( F_71 ( V_8 ) , V_2 -> V_120 ) ;
F_117 ( F_112 ( V_8 ) , V_2 -> V_120 ) ;
F_117 ( F_116 ( V_8 ) , V_2 -> V_120 ) ;
if ( F_59 ( V_8 ) )
F_117 ( F_113 ( V_8 ) ,
V_2 -> V_120 ) ;
}
}
if ( F_97 ( V_8 ) ) {
F_117 ( F_100 ( V_8 ) , V_2 -> V_120 ) ;
F_117 ( F_101 ( V_8 ) , V_2 -> V_120 ) ;
}
if ( F_103 ( V_8 ) ) {
F_117 ( F_104 ( V_8 ) , V_2 -> V_120 ) ;
F_117 ( F_105 ( V_8 ) , V_2 -> V_120 ) ;
F_117 ( F_106 ( V_8 ) , V_2 -> V_120 ) ;
}
F_145 ( V_110 , V_2 -> V_120 ) ;
V_2 -> V_123 = 0 ;
V_2 -> V_122 = 0 ;
} else {
V_2 -> V_123 = 1 ;
if ( ( F_86 ( V_8 ) || ( ! F_87 ( V_8 ) && ! F_88 ( V_8 ) ) ) &&
( F_95 ( V_8 ) || ! F_94 ( V_8 ) ) &&
( V_8 -> V_31 -> V_17 & V_142 ) )
V_2 -> V_122 = 1 ;
else
V_2 -> V_122 = 0 ;
}
if ( ! F_97 ( V_8 ) && V_81 && ( V_81 -> V_143 & V_144 ) && ! V_8 -> V_107 ) {
F_98 ( V_8 ) ;
F_57 ( V_8 ) ;
}
if ( F_23 ( & V_8 -> V_39 ) )
F_32 ( & V_8 -> V_39 ) ;
if ( F_23 ( & V_8 -> V_56 ) )
F_32 ( & V_8 -> V_56 ) ;
}
static void F_146 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_33 )
F_29 ( V_8 ) ;
F_147 ( V_2 ) ;
V_8 -> V_11 = NULL ;
}
static int F_148 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_149 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_145;
V_2 -> V_101 = V_100 ;
F_150 ( & V_2 -> V_146 ) ;
F_150 ( & V_2 -> V_66 ) ;
V_8 -> V_11 = V_2 ;
F_27 ( V_8 -> V_11 ) ;
V_2 -> V_61 = 0 ;
V_2 -> V_62 = 0 ;
V_2 -> V_125 = 1 ;
V_2 -> V_99 = 0 ;
V_2 -> V_13 = 0 ;
V_2 -> V_108 = 0 ;
V_8 -> V_124 = 0 ;
F_145 ( V_16 , & V_8 -> V_17 ) ;
F_143 ( V_8 , NULL ) ;
F_151 ( V_8 ) ;
return 0 ;
V_145:
return - V_147 ;
}
static inline int F_152 ( struct V_7 * V_8 , int V_148 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_149 = V_148 && ! F_153 ( V_8 ) && F_154 ( V_8 ) ? F_154 ( V_8 ) : 1 ;
if ( V_2 -> V_12 && ! F_133 ( V_8 ) )
return V_2 -> V_23 != V_2 -> V_4 ;
else
return V_2 -> V_22 - V_2 -> V_4 >= V_149 ;
}
static int F_155 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_150 ,
T_1 * V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_65 ;
T_1 V_21 ;
bool V_151 ;
T_1 V_83 = F_137 ( & V_2 -> V_22 ) ;
T_1 V_71 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_65 = 0 ;
V_21 = F_138 ( V_83 - V_2 -> V_4 , V_6 - V_71 ) ;
V_21 = F_138 ( * V_67 , V_21 ) ;
if ( V_21 ) {
V_65 = F_156 ( * V_150 , F_3 ( V_2 , V_71 ) , V_21 ) ;
V_21 -= V_65 ;
V_151 = V_21 == 1 && F_2 ( V_2 , V_71 ) == F_114 ( V_8 ) ;
F_7 ( V_8 , F_3 ( V_2 , V_71 ) , V_21 ,
V_2 -> V_12 ) ;
F_118 ( & V_2 -> V_4 , V_2 -> V_4 + V_21 ) ;
if ( F_133 ( V_8 ) && V_2 -> V_12 && V_151 &&
( V_83 == V_2 -> V_4 ) )
V_21 = 0 ;
* V_150 += V_21 ;
* V_67 -= V_21 ;
}
return V_65 ;
}
static int F_157 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_150 ,
T_1 * V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_21 , V_152 , V_153 , V_43 ;
T_1 V_154 ;
T_1 V_71 ;
int V_155 , V_156 = 0 ;
bool V_157 = 0 ;
V_21 = F_138 ( * V_67 , F_137 ( & V_2 -> V_23 ) - V_2 -> V_4 ) ;
if ( ! V_21 )
return 0 ;
V_71 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_152 = F_129 ( T_1 , V_71 + V_21 , V_6 ) ;
F_158 ( L_8 ,
V_58 , * V_67 , V_71 , V_21 , V_152 ) ;
V_154 = F_159 ( V_2 -> V_50 , V_152 , V_71 ) ;
V_153 = V_21 - ( V_152 - V_71 ) ;
if ( V_154 == V_6 && V_153 ) {
V_154 = F_159 ( V_2 -> V_50 , V_153 , 0 ) ;
if ( V_154 != V_153 )
V_156 = 1 ;
} else if ( V_154 != V_152 )
V_156 = 1 ;
V_152 = V_6 - V_71 ;
V_21 = V_154 - V_71 ;
if ( V_21 > 4096 )
V_21 += 4096 ;
V_21 += V_156 ;
V_43 = V_21 ;
if ( V_156 && ! V_2 -> V_51 && F_2 ( V_2 , V_154 ) == V_110 ) {
V_21 -- ;
V_157 = ! V_21 && V_2 -> V_4 != V_2 -> V_48 ;
}
F_158 ( L_9 ,
V_58 , V_154 , V_156 , V_21 , V_43 , V_152 , V_153 ) ;
if ( V_21 > V_152 ) {
V_155 = F_156 ( * V_150 , F_3 ( V_2 , V_71 ) , V_152 ) ;
if ( V_155 )
return - V_158 ;
V_155 = F_156 ( * V_150 + V_152 , V_2 -> F_2 , V_21 - V_152 ) ;
} else
V_155 = F_156 ( * V_150 , F_3 ( V_2 , V_71 ) , V_21 ) ;
if ( V_155 )
return - V_158 ;
* V_150 += V_21 ;
* V_67 -= V_21 ;
if ( V_156 )
F_145 ( V_154 , V_2 -> V_50 ) ;
F_118 ( & V_2 -> V_4 , V_2 -> V_4 + V_43 ) ;
if ( V_156 ) {
if ( ! V_2 -> V_51 )
V_2 -> V_48 = V_2 -> V_4 ;
else
V_2 -> V_51 = 0 ;
F_160 ( V_8 ) ;
}
return V_157 ? - V_159 : 0 ;
}
static int F_161 ( struct V_7 * V_8 , struct V_160 * V_160 )
{
if ( V_160 -> V_161 -> V_63 == V_162 ||
V_131 -> signal -> V_8 != V_8 )
return 0 ;
F_162 ( & V_8 -> V_53 ) ;
if ( ! V_8 -> V_163 )
F_91 ( V_117 L_10 ) ;
else if ( F_163 ( V_131 ) != V_8 -> V_163 ) {
F_164 ( & V_8 -> V_53 ) ;
if ( F_141 ( V_164 ) || F_165 () )
return - V_165 ;
F_79 ( F_163 ( V_131 ) , V_164 , 1 ) ;
F_166 ( V_166 ) ;
return - V_167 ;
}
F_164 ( & V_8 -> V_53 ) ;
return 0 ;
}
static T_3 F_167 ( struct V_7 * V_8 , struct V_160 * V_160 ,
unsigned char T_2 * V_19 , T_1 V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned char T_2 * V_150 = V_19 ;
F_168 ( V_168 , V_169 ) ;
int V_43 ;
int V_170 , time ;
T_3 V_65 = 0 ;
long V_171 ;
int V_52 ;
T_1 V_71 ;
V_43 = F_161 ( V_8 , V_160 ) ;
if ( V_43 < 0 )
return V_43 ;
if ( V_160 -> V_172 & V_173 ) {
if ( ! F_169 ( & V_2 -> V_146 ) )
return - V_159 ;
} else {
if ( F_170 ( & V_2 -> V_146 ) )
return - V_167 ;
}
F_84 ( & V_8 -> V_57 ) ;
V_170 = time = 0 ;
V_171 = V_174 ;
if ( ! V_2 -> V_12 ) {
V_170 = F_154 ( V_8 ) ;
if ( V_170 ) {
time = ( V_102 / 10 ) * F_153 ( V_8 ) ;
if ( time )
V_2 -> V_125 = 1 ;
else if ( ! F_23 ( & V_8 -> V_56 ) ||
( V_2 -> V_125 > V_170 ) )
V_2 -> V_125 = V_170 ;
} else {
V_171 = ( V_102 / 10 ) * F_153 ( V_8 ) ;
V_2 -> V_125 = V_170 = 1 ;
}
}
V_52 = V_8 -> V_52 ;
V_71 = V_2 -> V_4 ;
F_171 ( & V_8 -> V_56 , & V_168 ) ;
while ( V_67 ) {
if ( V_52 && V_8 -> V_33 -> V_54 ) {
unsigned char V_175 ;
if ( V_150 != V_19 )
break;
F_162 ( & V_8 -> V_33 -> V_53 ) ;
V_175 = V_8 -> V_33 -> V_54 ;
V_8 -> V_33 -> V_54 = 0 ;
F_164 ( & V_8 -> V_33 -> V_53 ) ;
if ( F_6 ( V_8 , V_175 , V_150 ++ ) ) {
V_65 = - V_158 ;
V_150 -- ;
break;
}
V_67 -- ;
break;
}
if ( ( ( V_170 - ( V_150 - V_19 ) ) < V_2 -> V_125 ) &&
( ( V_170 - ( V_150 - V_19 ) ) >= 1 ) )
V_2 -> V_125 = ( V_170 - ( V_150 - V_19 ) ) ;
if ( ! F_152 ( V_8 , 0 ) ) {
if ( F_12 ( V_176 , & V_8 -> V_17 ) ) {
V_65 = - V_165 ;
break;
}
if ( F_172 ( V_160 ) )
break;
if ( ! V_171 )
break;
if ( V_160 -> V_172 & V_173 ) {
V_65 = - V_159 ;
break;
}
if ( F_173 ( V_131 ) ) {
V_65 = - V_167 ;
break;
}
F_82 ( & V_8 -> V_57 ) ;
V_171 = F_174 ( & V_168 , V_177 ,
V_171 ) ;
F_84 ( & V_8 -> V_57 ) ;
continue;
}
if ( V_2 -> V_12 && ! F_133 ( V_8 ) ) {
V_65 = F_157 ( V_8 , & V_150 , & V_67 ) ;
if ( V_65 == - V_159 ) {
V_65 = 0 ;
continue;
} else if ( V_65 )
break;
} else {
int V_178 ;
if ( V_52 && V_150 == V_19 ) {
if ( F_6 ( V_8 , V_179 , V_150 ++ ) ) {
V_65 = - V_158 ;
V_150 -- ;
break;
}
V_67 -- ;
}
V_178 = F_155 ( V_8 , & V_150 , & V_67 ) ;
V_178 += F_155 ( V_8 , & V_150 , & V_67 ) ;
if ( V_178 ) {
V_65 = - V_158 ;
break;
}
}
F_22 ( V_8 ) ;
if ( V_150 - V_19 >= V_170 )
break;
if ( time )
V_171 = time ;
}
if ( V_71 != V_2 -> V_4 )
F_9 ( V_8 ) ;
F_82 ( & V_8 -> V_57 ) ;
F_175 ( & V_8 -> V_56 , & V_168 ) ;
if ( ! F_23 ( & V_8 -> V_56 ) )
V_2 -> V_125 = V_170 ;
F_52 ( & V_2 -> V_146 ) ;
if ( V_150 - V_19 )
V_65 = V_150 - V_19 ;
return V_65 ;
}
static T_3 F_176 ( struct V_7 * V_8 , struct V_160 * V_160 ,
const unsigned char * V_19 , T_1 V_67 )
{
const unsigned char * V_150 = V_19 ;
F_168 ( V_168 , V_169 ) ;
int V_43 ;
T_3 V_65 = 0 ;
if ( F_177 ( V_8 ) && V_160 -> V_161 -> V_63 != V_162 ) {
V_65 = F_178 ( V_8 ) ;
if ( V_65 )
return V_65 ;
}
F_84 ( & V_8 -> V_57 ) ;
F_57 ( V_8 ) ;
F_171 ( & V_8 -> V_39 , & V_168 ) ;
while ( 1 ) {
if ( F_173 ( V_131 ) ) {
V_65 = - V_167 ;
break;
}
if ( F_172 ( V_160 ) || ( V_8 -> V_33 && ! V_8 -> V_33 -> V_38 ) ) {
V_65 = - V_165 ;
break;
}
if ( F_55 ( V_8 ) ) {
while ( V_67 > 0 ) {
T_3 V_180 = F_53 ( V_8 , V_150 , V_67 ) ;
if ( V_180 < 0 ) {
if ( V_180 == - V_159 )
break;
V_65 = V_180 ;
goto V_69;
}
V_150 += V_180 ;
V_67 -= V_180 ;
if ( V_67 == 0 )
break;
V_43 = * V_150 ;
if ( F_49 ( V_43 , V_8 ) < 0 )
break;
V_150 ++ ; V_67 -- ;
}
if ( V_8 -> V_35 -> V_86 )
V_8 -> V_35 -> V_86 ( V_8 ) ;
} else {
struct V_1 * V_2 = V_8 -> V_11 ;
while ( V_67 > 0 ) {
F_50 ( & V_2 -> V_66 ) ;
V_43 = V_8 -> V_35 -> V_63 ( V_8 , V_150 , V_67 ) ;
F_52 ( & V_2 -> V_66 ) ;
if ( V_43 < 0 ) {
V_65 = V_43 ;
goto V_69;
}
if ( ! V_43 )
break;
V_150 += V_43 ;
V_67 -= V_43 ;
}
}
if ( ! V_67 )
break;
if ( V_160 -> V_172 & V_173 ) {
V_65 = - V_159 ;
break;
}
F_82 ( & V_8 -> V_57 ) ;
F_174 ( & V_168 , V_177 , V_174 ) ;
F_84 ( & V_8 -> V_57 ) ;
}
V_69:
F_175 ( & V_8 -> V_39 , & V_168 ) ;
if ( V_150 - V_19 != V_67 && V_8 -> V_24 )
F_117 ( V_25 , & V_8 -> V_17 ) ;
F_82 ( & V_8 -> V_57 ) ;
return ( V_150 - V_19 ) ? V_150 - V_19 : V_65 ;
}
static unsigned int F_179 ( struct V_7 * V_8 , struct V_160 * V_160 ,
T_4 * V_168 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned int V_181 = 0 ;
F_180 ( V_160 , & V_8 -> V_56 , V_168 ) ;
F_180 ( V_160 , & V_8 -> V_39 , V_168 ) ;
if ( F_152 ( V_8 , 1 ) )
V_181 |= V_98 | V_182 ;
if ( V_8 -> V_52 && V_8 -> V_33 -> V_54 )
V_181 |= V_183 | V_98 | V_182 ;
if ( F_12 ( V_176 , & V_8 -> V_17 ) )
V_181 |= V_184 ;
if ( F_172 ( V_160 ) )
V_181 |= V_184 ;
if ( ! ( V_181 & ( V_184 | V_98 | V_182 ) ) ) {
if ( F_154 ( V_8 ) && ! F_153 ( V_8 ) )
V_2 -> V_125 = F_154 ( V_8 ) ;
else
V_2 -> V_125 = 1 ;
}
if ( V_8 -> V_35 -> V_63 && ! F_181 ( V_8 ) &&
F_182 ( V_8 ) < V_185 &&
F_51 ( V_8 ) > 0 )
V_181 |= V_40 | V_186 ;
return V_181 ;
}
static unsigned long F_183 ( struct V_1 * V_2 )
{
T_1 V_67 , V_83 , V_71 ;
if ( V_2 -> V_23 == V_2 -> V_4 )
return 0 ;
V_83 = V_2 -> V_23 ;
V_71 = V_2 -> V_4 ;
V_67 = V_83 - V_71 ;
while ( V_83 != V_71 ) {
if ( F_12 ( V_71 & ( V_6 - 1 ) , V_2 -> V_50 ) &&
F_2 ( V_2 , V_71 ) == V_110 )
V_67 -- ;
V_71 ++ ;
}
return V_67 ;
}
static int F_184 ( struct V_7 * V_8 , struct V_160 * V_160 ,
unsigned int V_187 , unsigned long V_188 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_65 ;
switch ( V_187 ) {
case V_189 :
return F_8 ( F_182 ( V_8 ) , ( int T_2 * ) V_188 ) ;
case V_190 :
F_34 ( & V_8 -> V_57 ) ;
if ( F_144 ( V_8 ) )
V_65 = F_183 ( V_2 ) ;
else
V_65 = F_1 ( V_2 ) ;
F_35 ( & V_8 -> V_57 ) ;
return F_8 ( V_65 , ( unsigned int T_2 * ) V_188 ) ;
default:
return F_185 ( V_8 , V_160 , V_187 , V_188 ) ;
}
}
static void F_186 ( struct V_7 * V_8 , int V_191 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! F_23 ( & V_8 -> V_56 ) ) {
if ( V_191 )
V_2 -> V_125 = 1 ;
else if ( ! V_8 -> V_24 )
V_2 -> V_125 = V_6 ;
}
}
void F_187 ( struct V_192 * V_35 )
{
* V_35 = V_193 ;
V_35 -> V_194 = NULL ;
V_35 -> V_195 = V_35 -> V_17 = 0 ;
}

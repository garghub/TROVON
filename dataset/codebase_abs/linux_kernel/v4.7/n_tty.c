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
static int F_6 ( struct V_7 * V_8 , void T_2 * V_9 ,
T_1 V_10 , T_1 V_11 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
T_1 V_13 = V_6 - V_10 ;
const void * V_14 = F_3 ( V_2 , V_10 ) ;
int V_15 ;
if ( V_11 > V_13 ) {
F_7 ( V_8 , V_14 , V_13 ) ;
V_15 = F_8 ( V_9 , V_14 , V_13 ) ;
if ( V_15 )
return V_15 ;
V_9 += V_13 ;
V_11 -= V_13 ;
V_14 = V_2 -> F_2 ;
}
F_7 ( V_8 , V_14 , V_11 ) ;
return F_8 ( V_9 , V_14 , V_11 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( F_10 ( V_2 -> V_16 ) ) {
V_2 -> V_16 = 0 ;
F_11 ( V_8 -> V_17 -> V_18 == NULL ,
L_1 ) ;
F_11 ( F_12 ( V_19 , & V_8 -> V_20 ) ,
L_2 ) ;
F_13 ( V_8 -> V_17 ) ;
}
}
static T_3 F_14 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
T_3 V_11 = 0 ;
if ( ! V_2 -> V_21 )
V_11 = V_2 -> V_22 - V_2 -> V_4 ;
else
V_11 = V_2 -> V_23 - V_2 -> V_4 ;
return V_11 ;
}
static void F_15 ( struct V_7 * V_8 )
{
F_16 ( V_24 , & V_8 -> V_20 ) ;
F_17 ( & V_8 -> V_25 , V_26 , V_27 ) ;
}
static void F_18 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( V_2 -> V_21 && V_2 -> V_23 == V_2 -> V_4 )
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
if ( V_8 -> V_31 -> type == V_32 ) {
if ( F_14 ( V_8 ) > V_33 )
return;
F_9 ( V_8 ) ;
F_23 ( V_8 -> V_34 ) ;
return;
}
while ( 1 ) {
int V_35 ;
F_19 ( V_8 , V_36 ) ;
if ( F_14 ( V_8 ) > V_33 )
break;
F_9 ( V_8 ) ;
V_35 = F_24 ( V_8 ) ;
if ( ! V_35 )
break;
}
F_21 ( V_8 , 0 ) ;
}
static inline void F_25 ( unsigned char V_37 , struct V_1 * V_2 )
{
* F_3 ( V_2 , V_2 -> V_3 ) = V_37 ;
V_2 -> V_3 ++ ;
}
static void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_23 = V_2 -> V_4 = 0 ;
V_2 -> V_38 = V_2 -> V_39 = V_2 -> V_40 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_41 = 0 ;
V_2 -> V_42 = 0 ;
V_2 -> V_43 = 0 ;
F_27 ( V_2 -> V_44 , V_6 ) ;
V_2 -> V_45 = 0 ;
}
static void F_28 ( struct V_7 * V_8 )
{
unsigned long V_20 ;
if ( V_8 -> V_34 -> V_46 ) {
F_29 ( & V_8 -> V_47 , V_20 ) ;
V_8 -> V_48 |= V_49 ;
F_30 ( & V_8 -> V_47 , V_20 ) ;
F_31 ( & V_8 -> V_34 -> V_50 ) ;
}
}
static void F_32 ( struct V_7 * V_8 )
{
F_33 ( & V_8 -> V_51 ) ;
F_26 ( V_8 -> V_12 ) ;
F_9 ( V_8 ) ;
if ( V_8 -> V_34 )
F_28 ( V_8 ) ;
F_34 ( & V_8 -> V_51 ) ;
}
static inline int F_35 ( unsigned char V_37 )
{
return ( V_37 & 0xc0 ) == 0x80 ;
}
static inline int F_36 ( unsigned char V_37 , struct V_7 * V_8 )
{
return F_37 ( V_8 ) && F_35 ( V_37 ) ;
}
static int F_38 ( unsigned char V_37 , struct V_7 * V_8 , int V_52 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_53 ;
if ( ! V_52 )
return - 1 ;
switch ( V_37 ) {
case '\n' :
if ( F_39 ( V_8 ) )
V_2 -> V_54 = 0 ;
if ( F_40 ( V_8 ) ) {
if ( V_52 < 2 )
return - 1 ;
V_2 -> V_55 = V_2 -> V_54 = 0 ;
V_8 -> V_56 -> V_57 ( V_8 , L_3 , 2 ) ;
return 2 ;
}
V_2 -> V_55 = V_2 -> V_54 ;
break;
case '\r' :
if ( F_41 ( V_8 ) && V_2 -> V_54 == 0 )
return 0 ;
if ( F_42 ( V_8 ) ) {
V_37 = '\n' ;
if ( F_39 ( V_8 ) )
V_2 -> V_55 = V_2 -> V_54 = 0 ;
break;
}
V_2 -> V_55 = V_2 -> V_54 = 0 ;
break;
case '\t' :
V_53 = 8 - ( V_2 -> V_54 & 7 ) ;
if ( F_43 ( V_8 ) == V_58 ) {
if ( V_52 < V_53 )
return - 1 ;
V_2 -> V_54 += V_53 ;
V_8 -> V_56 -> V_57 ( V_8 , L_4 , V_53 ) ;
return V_53 ;
}
V_2 -> V_54 += V_53 ;
break;
case '\b' :
if ( V_2 -> V_54 > 0 )
V_2 -> V_54 -- ;
break;
default:
if ( ! iscntrl ( V_37 ) ) {
if ( F_44 ( V_8 ) )
V_37 = toupper ( V_37 ) ;
if ( ! F_36 ( V_37 , V_8 ) )
V_2 -> V_54 ++ ;
}
break;
}
F_45 ( V_8 , V_37 ) ;
return 1 ;
}
static int F_46 ( unsigned char V_37 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_52 , V_59 ;
F_47 ( & V_2 -> V_60 ) ;
V_52 = F_48 ( V_8 ) ;
V_59 = F_38 ( V_37 , V_8 , V_52 ) ;
F_49 ( & V_2 -> V_60 ) ;
if ( V_59 < 0 )
return - 1 ;
else
return 0 ;
}
static T_3 F_50 ( struct V_7 * V_8 ,
const unsigned char * V_61 , unsigned int V_62 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_52 ;
int V_5 ;
const unsigned char * V_63 ;
F_47 ( & V_2 -> V_60 ) ;
V_52 = F_48 ( V_8 ) ;
if ( ! V_52 ) {
F_49 ( & V_2 -> V_60 ) ;
return 0 ;
}
if ( V_62 > V_52 )
V_62 = V_52 ;
for ( V_5 = 0 , V_63 = V_61 ; V_5 < V_62 ; V_5 ++ , V_63 ++ ) {
unsigned char V_37 = * V_63 ;
switch ( V_37 ) {
case '\n' :
if ( F_39 ( V_8 ) )
V_2 -> V_54 = 0 ;
if ( F_40 ( V_8 ) )
goto V_64;
V_2 -> V_55 = V_2 -> V_54 ;
break;
case '\r' :
if ( F_41 ( V_8 ) && V_2 -> V_54 == 0 )
goto V_64;
if ( F_42 ( V_8 ) )
goto V_64;
V_2 -> V_55 = V_2 -> V_54 = 0 ;
break;
case '\t' :
goto V_64;
case '\b' :
if ( V_2 -> V_54 > 0 )
V_2 -> V_54 -- ;
break;
default:
if ( ! iscntrl ( V_37 ) ) {
if ( F_44 ( V_8 ) )
goto V_64;
if ( ! F_36 ( V_37 , V_8 ) )
V_2 -> V_54 ++ ;
}
break;
}
}
V_64:
V_5 = V_8 -> V_56 -> V_57 ( V_8 , V_61 , V_5 ) ;
F_49 ( & V_2 -> V_60 ) ;
return V_5 ;
}
static T_1 F_51 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_52 , V_65 ;
T_1 V_10 ;
unsigned char V_37 ;
V_65 = V_52 = F_48 ( V_8 ) ;
V_10 = V_2 -> V_39 ;
while ( V_2 -> V_40 != V_10 ) {
V_37 = F_4 ( V_2 , V_10 ) ;
if ( V_37 == V_66 ) {
unsigned char V_67 ;
int V_68 = 0 ;
V_67 = F_4 ( V_2 , V_10 + 1 ) ;
switch ( V_67 ) {
unsigned int V_69 , V_70 ;
case V_71 :
V_69 = F_4 ( V_2 , V_10 + 2 ) ;
if ( ! ( V_69 & 0x80 ) )
V_69 += V_2 -> V_55 ;
V_70 = 8 - ( V_69 & 7 ) ;
if ( V_70 > V_52 ) {
V_68 = 1 ;
break;
}
V_52 -= V_70 ;
while ( V_70 -- ) {
F_45 ( V_8 , '\b' ) ;
if ( V_2 -> V_54 > 0 )
V_2 -> V_54 -- ;
}
V_10 += 3 ;
break;
case V_72 :
V_2 -> V_55 = V_2 -> V_54 ;
V_10 += 2 ;
break;
case V_73 :
if ( V_2 -> V_54 > 0 )
V_2 -> V_54 -- ;
V_10 += 2 ;
break;
case V_66 :
if ( ! V_52 ) {
V_68 = 1 ;
break;
}
F_45 ( V_8 , V_66 ) ;
V_2 -> V_54 ++ ;
V_52 -- ;
V_10 += 2 ;
break;
default:
if ( V_52 < 2 ) {
V_68 = 1 ;
break;
}
F_45 ( V_8 , '^' ) ;
F_45 ( V_8 , V_67 ^ 0100 ) ;
V_2 -> V_54 += 2 ;
V_52 -= 2 ;
V_10 += 2 ;
}
if ( V_68 )
break;
} else {
if ( F_52 ( V_8 ) ) {
int V_59 = F_38 ( V_37 , V_8 , V_52 ) ;
if ( V_59 < 0 )
break;
V_52 -= V_59 ;
} else {
if ( ! V_52 )
break;
F_45 ( V_8 , V_37 ) ;
V_52 -= 1 ;
}
V_10 += 1 ;
}
}
while ( V_2 -> V_40 - V_10 >= V_74 ) {
if ( F_4 ( V_2 , V_10 ) == V_66 ) {
if ( F_4 ( V_2 , V_10 + 1 ) == V_71 )
V_10 += 3 ;
else
V_10 += 2 ;
} else
V_10 ++ ;
}
V_2 -> V_39 = V_10 ;
return V_65 - V_52 ;
}
static void F_53 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
T_1 V_62 , V_75 , V_76 ;
T_1 V_77 ;
V_77 = V_2 -> V_38 ;
V_2 -> V_41 = V_77 ;
V_75 = V_2 -> V_40 - V_2 -> V_39 ;
V_62 = V_77 - V_2 -> V_39 ;
if ( V_62 < V_78 || ( V_62 % V_79 > V_75 % V_79 ) )
return;
F_47 ( & V_2 -> V_60 ) ;
V_2 -> V_40 = V_77 ;
V_76 = F_51 ( V_8 ) ;
F_49 ( & V_2 -> V_60 ) ;
if ( V_76 && V_8 -> V_56 -> V_80 )
V_8 -> V_56 -> V_80 ( V_8 ) ;
}
static void F_54 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
T_1 V_76 ;
if ( V_2 -> V_41 == V_2 -> V_39 )
return;
F_47 ( & V_2 -> V_60 ) ;
V_2 -> V_40 = V_2 -> V_41 ;
V_76 = F_51 ( V_8 ) ;
F_49 ( & V_2 -> V_60 ) ;
if ( V_76 && V_8 -> V_56 -> V_80 )
V_8 -> V_56 -> V_80 ( V_8 ) ;
}
static void F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( ( ! F_56 ( V_8 ) && ! F_57 ( V_8 ) ) ||
V_2 -> V_40 == V_2 -> V_38 )
return;
F_47 ( & V_2 -> V_60 ) ;
V_2 -> V_40 = V_2 -> V_38 ;
F_51 ( V_8 ) ;
F_49 ( & V_2 -> V_60 ) ;
}
static inline void F_58 ( unsigned char V_37 , struct V_1 * V_2 )
{
* F_5 ( V_2 , V_2 -> V_38 ++ ) = V_37 ;
}
static void F_59 ( struct V_1 * V_2 )
{
F_58 ( V_66 , V_2 ) ;
F_58 ( V_73 , V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
F_58 ( V_66 , V_2 ) ;
F_58 ( V_72 , V_2 ) ;
}
static void F_61 ( unsigned int V_69 , int V_81 ,
struct V_1 * V_2 )
{
F_58 ( V_66 , V_2 ) ;
F_58 ( V_71 , V_2 ) ;
V_69 &= 7 ;
if ( V_81 )
V_69 |= 0x80 ;
F_58 ( V_69 , V_2 ) ;
}
static void F_62 ( unsigned char V_37 , struct V_1 * V_2 )
{
if ( V_37 == V_66 ) {
F_58 ( V_66 , V_2 ) ;
F_58 ( V_66 , V_2 ) ;
} else {
F_58 ( V_37 , V_2 ) ;
}
}
static void F_63 ( unsigned char V_37 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( V_37 == V_66 ) {
F_58 ( V_66 , V_2 ) ;
F_58 ( V_66 , V_2 ) ;
} else {
if ( F_64 ( V_8 ) && iscntrl ( V_37 ) && V_37 != '\t' )
F_58 ( V_66 , V_2 ) ;
F_58 ( V_37 , V_2 ) ;
}
}
static inline void F_65 ( struct V_1 * V_2 )
{
if ( V_2 -> V_43 ) {
F_62 ( '/' , V_2 ) ;
V_2 -> V_43 = 0 ;
}
}
static void F_66 ( unsigned char V_37 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
enum { V_82 , V_83 , V_84 } V_85 ;
T_1 V_77 ;
T_1 V_86 ;
int V_87 ;
if ( V_2 -> V_3 == V_2 -> V_23 ) {
return;
}
if ( V_37 == F_67 ( V_8 ) )
V_85 = V_82 ;
else if ( V_37 == F_68 ( V_8 ) )
V_85 = V_83 ;
else {
if ( ! F_56 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_23 ;
return;
}
if ( ! F_69 ( V_8 ) || ! F_70 ( V_8 ) || ! F_71 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_23 ;
F_65 ( V_2 ) ;
F_63 ( F_72 ( V_8 ) , V_8 ) ;
if ( F_69 ( V_8 ) )
F_62 ( '\n' , V_2 ) ;
return;
}
V_85 = V_84 ;
}
V_87 = 0 ;
while ( V_2 -> V_3 != V_2 -> V_23 ) {
V_77 = V_2 -> V_3 ;
do {
V_77 -- ;
V_37 = F_2 ( V_2 , V_77 ) ;
} while ( F_36 ( V_37 , V_8 ) && V_77 != V_2 -> V_23 );
if ( F_36 ( V_37 , V_8 ) )
break;
if ( V_85 == V_83 ) {
if ( isalnum ( V_37 ) || V_37 == '_' )
V_87 ++ ;
else if ( V_87 )
break;
}
V_86 = V_2 -> V_3 - V_77 ;
V_2 -> V_3 = V_77 ;
if ( F_56 ( V_8 ) ) {
if ( F_73 ( V_8 ) ) {
if ( ! V_2 -> V_43 ) {
F_62 ( '\\' , V_2 ) ;
V_2 -> V_43 = 1 ;
}
F_63 ( V_37 , V_8 ) ;
while ( -- V_86 > 0 ) {
V_77 ++ ;
F_62 ( F_2 ( V_2 , V_77 ) , V_2 ) ;
F_59 ( V_2 ) ;
}
} else if ( V_85 == V_82 && ! F_71 ( V_8 ) ) {
F_63 ( F_67 ( V_8 ) , V_8 ) ;
} else if ( V_37 == '\t' ) {
unsigned int V_69 = 0 ;
int V_81 = 0 ;
T_1 V_10 = V_2 -> V_3 ;
while ( V_10 != V_2 -> V_23 ) {
V_10 -- ;
V_37 = F_2 ( V_2 , V_10 ) ;
if ( V_37 == '\t' ) {
V_81 = 1 ;
break;
} else if ( iscntrl ( V_37 ) ) {
if ( F_64 ( V_8 ) )
V_69 += 2 ;
} else if ( ! F_36 ( V_37 , V_8 ) ) {
V_69 ++ ;
}
}
F_61 ( V_69 , V_81 , V_2 ) ;
} else {
if ( iscntrl ( V_37 ) && F_64 ( V_8 ) ) {
F_62 ( '\b' , V_2 ) ;
F_62 ( ' ' , V_2 ) ;
F_62 ( '\b' , V_2 ) ;
}
if ( ! iscntrl ( V_37 ) || F_64 ( V_8 ) ) {
F_62 ( '\b' , V_2 ) ;
F_62 ( ' ' , V_2 ) ;
F_62 ( '\b' , V_2 ) ;
}
}
}
if ( V_85 == V_82 )
break;
}
if ( V_2 -> V_3 == V_2 -> V_23 && F_56 ( V_8 ) )
F_65 ( V_2 ) ;
}
static void F_74 ( int V_88 , struct V_7 * V_8 )
{
struct V_89 * V_90 = F_75 ( V_8 ) ;
if ( V_90 ) {
F_76 ( V_90 , V_88 , 1 ) ;
F_77 ( V_90 ) ;
}
}
static void F_78 ( int V_88 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( F_79 ( V_8 ) ) {
F_74 ( V_88 , V_8 ) ;
} else {
F_80 ( & V_8 -> V_51 ) ;
F_33 ( & V_8 -> V_51 ) ;
F_74 ( V_88 , V_8 ) ;
F_47 ( & V_2 -> V_60 ) ;
V_2 -> V_38 = V_2 -> V_39 = 0 ;
V_2 -> V_41 = V_2 -> V_40 = 0 ;
F_49 ( & V_2 -> V_60 ) ;
F_81 ( V_8 ) ;
F_26 ( V_8 -> V_12 ) ;
if ( V_8 -> V_34 )
F_28 ( V_8 ) ;
F_34 ( & V_8 -> V_51 ) ;
F_82 ( & V_8 -> V_51 ) ;
}
}
static void F_83 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( F_84 ( V_8 ) )
return;
if ( F_85 ( V_8 ) ) {
F_78 ( V_91 , V_8 ) ;
return;
}
if ( F_86 ( V_8 ) ) {
F_25 ( '\377' , V_2 ) ;
F_25 ( '\0' , V_2 ) ;
}
F_25 ( '\0' , V_2 ) ;
}
static void F_87 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
V_2 -> V_92 ++ ;
if ( F_88 ( V_93 , V_2 -> V_94 + V_95 ) ||
F_88 ( V_2 -> V_94 , V_93 ) ) {
F_89 ( V_8 , L_5 , V_2 -> V_92 ) ;
V_2 -> V_94 = V_93 ;
V_2 -> V_92 = 0 ;
}
}
static void F_90 ( struct V_7 * V_8 , unsigned char V_37 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( F_91 ( V_8 ) ) {
if ( F_92 ( V_8 ) )
return;
if ( F_86 ( V_8 ) ) {
F_25 ( '\377' , V_2 ) ;
F_25 ( '\0' , V_2 ) ;
F_25 ( V_37 , V_2 ) ;
} else
F_25 ( '\0' , V_2 ) ;
} else
F_25 ( V_37 , V_2 ) ;
}
static void
F_93 ( struct V_7 * V_8 , int signal , unsigned char V_37 )
{
F_78 ( signal , V_8 ) ;
if ( F_94 ( V_8 ) )
F_95 ( V_8 ) ;
if ( F_56 ( V_8 ) ) {
F_63 ( V_37 , V_8 ) ;
F_53 ( V_8 ) ;
} else
F_54 ( V_8 ) ;
return;
}
static int
F_96 ( struct V_7 * V_8 , unsigned char V_37 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( F_94 ( V_8 ) ) {
if ( V_37 == F_97 ( V_8 ) ) {
F_95 ( V_8 ) ;
F_54 ( V_8 ) ;
return 0 ;
}
if ( V_37 == F_98 ( V_8 ) ) {
F_99 ( V_8 ) ;
return 0 ;
}
}
if ( F_100 ( V_8 ) ) {
if ( V_37 == F_101 ( V_8 ) ) {
F_93 ( V_8 , V_91 , V_37 ) ;
return 0 ;
} else if ( V_37 == F_102 ( V_8 ) ) {
F_93 ( V_8 , V_96 , V_37 ) ;
return 0 ;
} else if ( V_37 == F_103 ( V_8 ) ) {
F_93 ( V_8 , V_97 , V_37 ) ;
return 0 ;
}
}
if ( V_8 -> V_98 && ! V_8 -> V_99 && F_94 ( V_8 ) && F_104 ( V_8 ) ) {
F_95 ( V_8 ) ;
F_54 ( V_8 ) ;
}
if ( V_37 == '\r' ) {
if ( F_105 ( V_8 ) )
return 0 ;
if ( F_106 ( V_8 ) )
V_37 = '\n' ;
} else if ( V_37 == '\n' && F_107 ( V_8 ) )
V_37 = '\r' ;
if ( V_2 -> V_21 ) {
if ( V_37 == F_67 ( V_8 ) || V_37 == F_72 ( V_8 ) ||
( V_37 == F_68 ( V_8 ) && F_108 ( V_8 ) ) ) {
F_66 ( V_37 , V_8 ) ;
F_53 ( V_8 ) ;
return 0 ;
}
if ( V_37 == F_109 ( V_8 ) && F_108 ( V_8 ) ) {
V_2 -> V_100 = 1 ;
if ( F_56 ( V_8 ) ) {
F_65 ( V_2 ) ;
if ( F_64 ( V_8 ) ) {
F_62 ( '^' , V_2 ) ;
F_62 ( '\b' , V_2 ) ;
F_53 ( V_8 ) ;
}
}
return 1 ;
}
if ( V_37 == F_110 ( V_8 ) && F_56 ( V_8 ) && F_108 ( V_8 ) ) {
T_1 V_10 = V_2 -> V_23 ;
F_65 ( V_2 ) ;
F_63 ( V_37 , V_8 ) ;
F_62 ( '\n' , V_2 ) ;
while ( V_10 != V_2 -> V_3 ) {
F_63 ( F_2 ( V_2 , V_10 ) , V_8 ) ;
V_10 ++ ;
}
F_53 ( V_8 ) ;
return 0 ;
}
if ( V_37 == '\n' ) {
if ( F_56 ( V_8 ) || F_57 ( V_8 ) ) {
F_62 ( '\n' , V_2 ) ;
F_53 ( V_8 ) ;
}
goto V_101;
}
if ( V_37 == F_111 ( V_8 ) ) {
V_37 = V_102 ;
goto V_101;
}
if ( ( V_37 == F_112 ( V_8 ) ) ||
( V_37 == F_113 ( V_8 ) && F_108 ( V_8 ) ) ) {
if ( F_56 ( V_8 ) ) {
if ( V_2 -> V_23 == V_2 -> V_3 )
F_60 ( V_2 ) ;
F_63 ( V_37 , V_8 ) ;
F_53 ( V_8 ) ;
}
if ( V_37 == ( unsigned char ) '\377' && F_86 ( V_8 ) )
F_25 ( V_37 , V_2 ) ;
V_101:
F_114 ( V_2 -> V_3 & ( V_6 - 1 ) , V_2 -> V_44 ) ;
F_25 ( V_37 , V_2 ) ;
F_115 ( & V_2 -> V_23 , V_2 -> V_3 ) ;
F_17 ( & V_8 -> V_25 , V_26 , V_103 ) ;
F_116 ( & V_8 -> V_50 , V_104 ) ;
return 0 ;
}
}
if ( F_56 ( V_8 ) ) {
F_65 ( V_2 ) ;
if ( V_37 == '\n' )
F_62 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_23 == V_2 -> V_3 )
F_60 ( V_2 ) ;
F_63 ( V_37 , V_8 ) ;
}
F_53 ( V_8 ) ;
}
if ( V_37 == ( unsigned char ) '\377' && F_86 ( V_8 ) )
F_25 ( V_37 , V_2 ) ;
F_25 ( V_37 , V_2 ) ;
return 0 ;
}
static inline void
F_117 ( struct V_7 * V_8 , unsigned char V_37 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( V_8 -> V_98 && ! V_8 -> V_99 && F_94 ( V_8 ) && F_104 ( V_8 ) ) {
F_95 ( V_8 ) ;
F_54 ( V_8 ) ;
}
if ( F_56 ( V_8 ) ) {
F_65 ( V_2 ) ;
if ( V_2 -> V_23 == V_2 -> V_3 )
F_60 ( V_2 ) ;
F_63 ( V_37 , V_8 ) ;
F_53 ( V_8 ) ;
}
if ( V_37 == ( unsigned char ) '\377' && F_86 ( V_8 ) )
F_25 ( V_37 , V_2 ) ;
F_25 ( V_37 , V_2 ) ;
}
static void F_118 ( struct V_7 * V_8 , unsigned char V_37 )
{
F_117 ( V_8 , V_37 ) ;
}
static inline void
F_119 ( struct V_7 * V_8 , unsigned char V_37 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( V_8 -> V_98 && ! V_8 -> V_99 && F_94 ( V_8 ) && F_104 ( V_8 ) ) {
F_95 ( V_8 ) ;
F_54 ( V_8 ) ;
}
if ( F_56 ( V_8 ) ) {
F_65 ( V_2 ) ;
if ( V_2 -> V_23 == V_2 -> V_3 )
F_60 ( V_2 ) ;
F_63 ( V_37 , V_8 ) ;
F_53 ( V_8 ) ;
}
F_25 ( V_37 , V_2 ) ;
}
static void F_120 ( struct V_7 * V_8 , unsigned char V_37 )
{
if ( F_121 ( V_8 ) )
V_37 &= 0x7f ;
if ( F_122 ( V_8 ) && F_108 ( V_8 ) )
V_37 = tolower ( V_37 ) ;
if ( F_94 ( V_8 ) ) {
if ( V_37 == F_98 ( V_8 ) )
F_99 ( V_8 ) ;
else if ( V_37 == F_97 ( V_8 ) ||
( V_8 -> V_98 && ! V_8 -> V_99 && F_104 ( V_8 ) &&
V_37 != F_101 ( V_8 ) && V_37 != F_102 ( V_8 ) &&
V_37 != F_103 ( V_8 ) ) ) {
F_95 ( V_8 ) ;
F_54 ( V_8 ) ;
}
}
}
static void
F_123 ( struct V_7 * V_8 , unsigned char V_37 , char V_105 )
{
switch ( V_105 ) {
case V_106 :
F_83 ( V_8 ) ;
break;
case V_107 :
case V_108 :
F_90 ( V_8 , V_37 ) ;
break;
case V_109 :
F_87 ( V_8 ) ;
break;
default:
F_124 ( V_8 , L_6 , V_105 ) ;
break;
}
}
static void
F_125 ( struct V_7 * V_8 , unsigned char V_37 , char V_105 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
V_2 -> V_100 = 0 ;
if ( F_126 ( V_105 == V_110 ) ) {
if ( F_121 ( V_8 ) )
V_37 &= 0x7f ;
if ( F_122 ( V_8 ) && F_108 ( V_8 ) )
V_37 = tolower ( V_37 ) ;
F_118 ( V_8 , V_37 ) ;
} else
F_123 ( V_8 , V_37 , V_105 ) ;
}
static void
F_127 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
T_1 V_11 , V_77 ;
V_77 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_11 = F_128 ( T_1 , V_112 , V_6 - V_77 ) ;
memcpy ( F_3 ( V_2 , V_77 ) , V_63 , V_11 ) ;
V_2 -> V_3 += V_11 ;
V_63 += V_11 ;
V_112 -= V_11 ;
V_77 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_11 = F_128 ( T_1 , V_112 , V_6 - V_77 ) ;
memcpy ( F_3 ( V_2 , V_77 ) , V_63 , V_11 ) ;
V_2 -> V_3 += V_11 ;
}
static void
F_129 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
char V_105 = V_110 ;
while ( V_112 -- ) {
if ( V_111 )
V_105 = * V_111 ++ ;
if ( F_126 ( V_105 == V_110 ) )
F_25 ( * V_63 ++ , V_2 ) ;
else
F_123 ( V_8 , * V_63 ++ , V_105 ) ;
}
}
static void
F_130 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 )
{
char V_105 = V_110 ;
while ( V_112 -- ) {
if ( V_111 )
V_105 = * V_111 ++ ;
if ( F_126 ( V_105 == V_110 ) )
F_120 ( V_8 , * V_63 ++ ) ;
}
}
static void
F_131 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
char V_105 = V_110 ;
while ( V_112 -- ) {
if ( V_111 )
V_105 = * V_111 ++ ;
if ( F_126 ( V_105 == V_110 ) ) {
unsigned char V_37 = * V_63 ++ ;
if ( F_121 ( V_8 ) )
V_37 &= 0x7f ;
if ( F_122 ( V_8 ) && F_108 ( V_8 ) )
V_37 = tolower ( V_37 ) ;
if ( F_132 ( V_8 ) ) {
F_25 ( V_37 , V_2 ) ;
continue;
}
if ( ! F_12 ( V_37 , V_2 -> V_113 ) )
F_117 ( V_8 , V_37 ) ;
else if ( F_96 ( V_8 , V_37 ) && V_112 ) {
if ( V_111 )
V_105 = * V_111 ++ ;
F_125 ( V_8 , * V_63 ++ , V_105 ) ;
V_112 -- ;
}
} else
F_123 ( V_8 , * V_63 ++ , V_105 ) ;
}
}
static void
F_133 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
char V_105 = V_110 ;
while ( V_112 -- ) {
if ( V_111 )
V_105 = * V_111 ++ ;
if ( F_126 ( V_105 == V_110 ) ) {
unsigned char V_37 = * V_63 ++ ;
if ( ! F_12 ( V_37 , V_2 -> V_113 ) )
F_119 ( V_8 , V_37 ) ;
else if ( F_96 ( V_8 , V_37 ) && V_112 ) {
if ( V_111 )
V_105 = * V_111 ++ ;
F_125 ( V_8 , * V_63 ++ , V_105 ) ;
V_112 -- ;
}
} else
F_123 ( V_8 , * V_63 ++ , V_105 ) ;
}
}
static void F_134 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
bool V_114 = F_121 ( V_8 ) || ( F_122 ( V_8 ) && F_108 ( V_8 ) ) ;
if ( V_2 -> V_115 )
F_127 ( V_8 , V_63 , V_111 , V_112 ) ;
else if ( V_2 -> V_116 || ( F_132 ( V_8 ) && ! V_114 ) )
F_129 ( V_8 , V_63 , V_111 , V_112 ) ;
else if ( V_8 -> V_117 && ! F_132 ( V_8 ) )
F_130 ( V_8 , V_63 , V_111 , V_112 ) ;
else {
if ( V_2 -> V_100 ) {
char V_105 = V_110 ;
if ( V_111 )
V_105 = * V_111 ++ ;
F_125 ( V_8 , * V_63 ++ , V_105 ) ;
V_112 -- ;
}
if ( ! V_114 && ! F_86 ( V_8 ) )
F_133 ( V_8 , V_63 , V_111 , V_112 ) ;
else
F_131 ( V_8 , V_63 , V_111 , V_112 ) ;
F_55 ( V_8 ) ;
if ( V_8 -> V_56 -> V_80 )
V_8 -> V_56 -> V_80 ( V_8 ) ;
}
if ( V_2 -> V_21 && ! F_132 ( V_8 ) )
return;
F_115 ( & V_2 -> V_22 , V_2 -> V_3 ) ;
if ( F_1 ( V_2 ) ) {
F_17 ( & V_8 -> V_25 , V_26 , V_103 ) ;
F_116 ( & V_8 -> V_50 , V_104 ) ;
}
}
static int
F_135 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 , int V_118 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_119 , V_11 , V_120 = 0 , V_121 ;
F_82 ( & V_8 -> V_51 ) ;
while ( 1 ) {
T_1 V_10 = F_136 ( & V_2 -> V_4 ) ;
V_119 = V_6 - ( V_2 -> V_3 - V_10 ) ;
if ( F_86 ( V_8 ) )
V_119 = ( V_119 + 2 ) / 3 ;
V_119 -- ;
if ( V_119 <= 0 ) {
V_121 = V_2 -> V_21 && V_2 -> V_23 == V_10 ;
if ( V_121 && V_119 < 0 )
V_2 -> V_3 -- ;
V_119 = V_121 ;
V_2 -> V_16 = V_118 && ! V_119 ;
} else
V_121 = 0 ;
V_11 = F_137 ( V_112 , V_119 ) ;
if ( ! V_11 )
break;
if ( ! V_121 || ! V_111 || * V_111 != V_107 )
F_134 ( V_8 , V_63 , V_111 , V_11 ) ;
V_63 += V_11 ;
if ( V_111 )
V_111 += V_11 ;
V_112 -= V_11 ;
V_120 += V_11 ;
}
V_8 -> V_122 = V_119 ;
if ( V_8 -> V_31 -> type == V_32 ) {
if ( V_121 ) {
F_19 ( V_8 , V_36 ) ;
F_24 ( V_8 ) ;
F_21 ( V_8 , 0 ) ;
}
} else
F_18 ( V_8 ) ;
F_80 ( & V_8 -> V_51 ) ;
return V_120 ;
}
static void F_138 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 )
{
F_135 ( V_8 , V_63 , V_111 , V_112 , 0 ) ;
}
static int F_139 ( struct V_7 * V_8 , const unsigned char * V_63 ,
char * V_111 , int V_112 )
{
return F_135 ( V_8 , V_63 , V_111 , V_112 , 1 ) ;
}
static void F_140 ( struct V_7 * V_8 , struct V_123 * V_75 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( ! V_75 || ( V_75 -> V_124 ^ V_8 -> V_125 . V_124 ) & V_126 ) {
F_27 ( V_2 -> V_44 , V_6 ) ;
V_2 -> V_42 = V_2 -> V_4 ;
if ( ! F_141 ( V_8 ) || ! F_1 ( V_2 ) ) {
V_2 -> V_23 = V_2 -> V_4 ;
V_2 -> V_45 = 0 ;
} else {
F_114 ( ( V_2 -> V_3 - 1 ) & ( V_6 - 1 ) ,
V_2 -> V_44 ) ;
V_2 -> V_23 = V_2 -> V_3 ;
V_2 -> V_45 = 1 ;
}
V_2 -> V_22 = V_2 -> V_3 ;
V_2 -> V_43 = 0 ;
V_2 -> V_100 = 0 ;
}
V_2 -> V_21 = ( F_141 ( V_8 ) != 0 ) ;
if ( F_121 ( V_8 ) || F_122 ( V_8 ) || F_105 ( V_8 ) ||
F_106 ( V_8 ) || F_107 ( V_8 ) || F_141 ( V_8 ) ||
F_94 ( V_8 ) || F_100 ( V_8 ) || F_56 ( V_8 ) ||
F_86 ( V_8 ) ) {
F_27 ( V_2 -> V_113 , 256 ) ;
if ( F_105 ( V_8 ) || F_106 ( V_8 ) )
F_114 ( '\r' , V_2 -> V_113 ) ;
if ( F_107 ( V_8 ) )
F_114 ( '\n' , V_2 -> V_113 ) ;
if ( F_141 ( V_8 ) ) {
F_114 ( F_67 ( V_8 ) , V_2 -> V_113 ) ;
F_114 ( F_72 ( V_8 ) , V_2 -> V_113 ) ;
F_114 ( F_111 ( V_8 ) , V_2 -> V_113 ) ;
F_114 ( '\n' , V_2 -> V_113 ) ;
F_114 ( F_112 ( V_8 ) , V_2 -> V_113 ) ;
if ( F_108 ( V_8 ) ) {
F_114 ( F_68 ( V_8 ) , V_2 -> V_113 ) ;
F_114 ( F_109 ( V_8 ) , V_2 -> V_113 ) ;
F_114 ( F_113 ( V_8 ) , V_2 -> V_113 ) ;
if ( F_56 ( V_8 ) )
F_114 ( F_110 ( V_8 ) ,
V_2 -> V_113 ) ;
}
}
if ( F_94 ( V_8 ) ) {
F_114 ( F_97 ( V_8 ) , V_2 -> V_113 ) ;
F_114 ( F_98 ( V_8 ) , V_2 -> V_113 ) ;
}
if ( F_100 ( V_8 ) ) {
F_114 ( F_101 ( V_8 ) , V_2 -> V_113 ) ;
F_114 ( F_102 ( V_8 ) , V_2 -> V_113 ) ;
F_114 ( F_103 ( V_8 ) , V_2 -> V_113 ) ;
}
F_16 ( V_102 , V_2 -> V_113 ) ;
V_2 -> V_116 = 0 ;
V_2 -> V_115 = 0 ;
} else {
V_2 -> V_116 = 1 ;
if ( ( F_84 ( V_8 ) || ( ! F_85 ( V_8 ) && ! F_86 ( V_8 ) ) ) &&
( F_92 ( V_8 ) || ! F_91 ( V_8 ) ) &&
( V_8 -> V_31 -> V_20 & V_127 ) )
V_2 -> V_115 = 1 ;
else
V_2 -> V_115 = 0 ;
}
if ( ! F_94 ( V_8 ) && V_75 && ( V_75 -> V_128 & V_129 ) && ! V_8 -> V_99 ) {
F_95 ( V_8 ) ;
F_54 ( V_8 ) ;
}
F_31 ( & V_8 -> V_130 ) ;
F_31 ( & V_8 -> V_50 ) ;
}
static void F_142 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
if ( V_8 -> V_34 )
F_28 ( V_8 ) ;
F_143 ( V_2 ) ;
V_8 -> V_12 = NULL ;
}
static int F_144 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_145 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_131;
V_2 -> V_94 = V_93 ;
F_146 ( & V_2 -> V_132 ) ;
F_146 ( & V_2 -> V_60 ) ;
V_8 -> V_12 = V_2 ;
F_26 ( V_8 -> V_12 ) ;
V_2 -> V_54 = 0 ;
V_2 -> V_55 = 0 ;
V_2 -> V_92 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_100 = 0 ;
V_8 -> V_117 = 0 ;
F_16 ( V_19 , & V_8 -> V_20 ) ;
F_140 ( V_8 , NULL ) ;
F_147 ( V_8 ) ;
return 0 ;
V_131:
return - V_133 ;
}
static inline int F_148 ( struct V_7 * V_8 , int V_134 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_135 = V_134 && ! F_149 ( V_8 ) && F_150 ( V_8 ) ? F_150 ( V_8 ) : 1 ;
if ( V_2 -> V_21 && ! F_132 ( V_8 ) )
return V_2 -> V_23 != V_2 -> V_4 ;
else
return V_2 -> V_22 - V_2 -> V_4 >= V_135 ;
}
static int F_151 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_136 ,
T_1 * V_62 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_59 ;
T_1 V_11 ;
bool V_137 ;
T_1 V_77 = F_136 ( & V_2 -> V_22 ) ;
T_1 V_10 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_59 = 0 ;
V_11 = F_137 ( V_77 - V_2 -> V_4 , V_6 - V_10 ) ;
V_11 = F_137 ( * V_62 , V_11 ) ;
if ( V_11 ) {
const unsigned char * V_14 = F_3 ( V_2 , V_10 ) ;
V_59 = F_8 ( * V_136 , V_14 , V_11 ) ;
V_11 -= V_59 ;
V_137 = V_11 == 1 && * V_14 == F_111 ( V_8 ) ;
F_7 ( V_8 , V_14 , V_11 ) ;
F_115 ( & V_2 -> V_4 , V_2 -> V_4 + V_11 ) ;
if ( F_132 ( V_8 ) && V_2 -> V_21 && V_137 &&
( V_77 == V_2 -> V_4 ) )
V_11 = 0 ;
* V_136 += V_11 ;
* V_62 -= V_11 ;
}
return V_59 ;
}
static int F_152 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_136 ,
T_1 * V_62 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
T_1 V_11 , V_13 , V_138 , V_37 ;
T_1 V_139 ;
T_1 V_10 ;
int V_140 , V_141 = 0 ;
if ( ! * V_62 )
return 0 ;
V_11 = F_137 ( * V_62 + 1 , F_136 ( & V_2 -> V_23 ) - V_2 -> V_4 ) ;
V_10 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_13 = F_128 ( T_1 , V_10 + V_11 , V_6 ) ;
F_153 ( L_7 ,
V_142 , * V_62 , V_10 , V_11 , V_13 ) ;
V_139 = F_154 ( V_2 -> V_44 , V_13 , V_10 ) ;
V_138 = V_11 - ( V_13 - V_10 ) ;
if ( V_139 == V_6 && V_138 ) {
V_139 = F_154 ( V_2 -> V_44 , V_138 , 0 ) ;
V_141 = V_139 != V_138 ;
} else
V_141 = V_139 != V_13 ;
V_11 = V_139 - V_10 ;
if ( V_11 > V_6 )
V_11 += V_6 ;
V_37 = V_11 + V_141 ;
if ( ! V_141 || F_2 ( V_2 , V_139 ) != V_102 ) {
V_37 = F_137 ( * V_62 , V_37 ) ;
V_11 = V_37 ;
}
F_153 ( L_8 ,
V_142 , V_139 , V_141 , V_11 , V_37 , V_10 , V_138 ) ;
V_140 = F_6 ( V_8 , * V_136 , V_10 , V_11 ) ;
if ( V_140 )
return - V_143 ;
* V_136 += V_11 ;
* V_62 -= V_11 ;
if ( V_141 )
F_16 ( V_139 , V_2 -> V_44 ) ;
F_115 ( & V_2 -> V_4 , V_2 -> V_4 + V_37 ) ;
if ( V_141 ) {
if ( ! V_2 -> V_45 )
V_2 -> V_42 = V_2 -> V_4 ;
else
V_2 -> V_45 = 0 ;
F_155 () ;
}
return 0 ;
}
static int F_156 ( struct V_7 * V_8 , struct V_144 * V_144 )
{
if ( V_144 -> V_145 -> V_57 == V_146 )
return 0 ;
return F_157 ( V_8 , V_147 ) ;
}
static T_3 F_158 ( struct V_7 * V_8 , struct V_144 * V_144 ,
unsigned char T_2 * V_61 , T_1 V_62 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
unsigned char T_2 * V_136 = V_61 ;
F_159 ( V_148 , V_149 ) ;
int V_37 ;
int V_150 , time ;
T_3 V_59 = 0 ;
long V_151 ;
int V_46 ;
T_1 V_10 ;
V_37 = F_156 ( V_8 , V_144 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_144 -> V_152 & V_153 ) {
if ( ! F_160 ( & V_2 -> V_132 ) )
return - V_154 ;
} else {
if ( F_161 ( & V_2 -> V_132 ) )
return - V_155 ;
}
F_82 ( & V_8 -> V_51 ) ;
V_150 = time = 0 ;
V_151 = V_156 ;
if ( ! V_2 -> V_21 ) {
V_150 = F_150 ( V_8 ) ;
if ( V_150 ) {
time = ( V_95 / 10 ) * F_149 ( V_8 ) ;
} else {
V_151 = ( V_95 / 10 ) * F_149 ( V_8 ) ;
V_150 = 1 ;
}
}
V_46 = V_8 -> V_46 ;
V_10 = V_2 -> V_4 ;
F_162 ( & V_8 -> V_50 , & V_148 ) ;
while ( V_62 ) {
if ( V_46 && V_8 -> V_34 -> V_48 ) {
unsigned char V_157 ;
if ( V_136 != V_61 )
break;
F_163 ( & V_8 -> V_34 -> V_47 ) ;
V_157 = V_8 -> V_34 -> V_48 ;
V_8 -> V_34 -> V_48 = 0 ;
F_164 ( & V_8 -> V_34 -> V_47 ) ;
if ( F_165 ( V_157 , V_136 ) ) {
V_59 = - V_143 ;
break;
}
V_136 ++ ;
V_62 -- ;
break;
}
if ( ! F_148 ( V_8 , 0 ) ) {
F_80 ( & V_8 -> V_51 ) ;
F_166 ( V_8 -> V_17 ) ;
F_82 ( & V_8 -> V_51 ) ;
if ( ! F_148 ( V_8 , 0 ) ) {
if ( F_12 ( V_158 , & V_8 -> V_20 ) ) {
V_59 = - V_159 ;
break;
}
if ( F_167 ( V_144 ) )
break;
if ( ! V_151 )
break;
if ( V_144 -> V_152 & V_153 ) {
V_59 = - V_154 ;
break;
}
if ( F_168 ( V_160 ) ) {
V_59 = - V_155 ;
break;
}
F_80 ( & V_8 -> V_51 ) ;
V_151 = F_169 ( & V_148 , V_161 ,
V_151 ) ;
F_82 ( & V_8 -> V_51 ) ;
continue;
}
}
if ( V_2 -> V_21 && ! F_132 ( V_8 ) ) {
V_59 = F_152 ( V_8 , & V_136 , & V_62 ) ;
if ( V_59 )
break;
} else {
int V_15 ;
if ( V_46 && V_136 == V_61 ) {
if ( F_165 ( V_162 , V_136 ) ) {
V_59 = - V_143 ;
break;
}
V_136 ++ ;
V_62 -- ;
}
V_15 = F_151 ( V_8 , & V_136 , & V_62 ) ;
V_15 += F_151 ( V_8 , & V_136 , & V_62 ) ;
if ( V_15 ) {
V_59 = - V_143 ;
break;
}
}
F_22 ( V_8 ) ;
if ( V_136 - V_61 >= V_150 )
break;
if ( time )
V_151 = time ;
}
if ( V_10 != V_2 -> V_4 )
F_9 ( V_8 ) ;
F_80 ( & V_8 -> V_51 ) ;
F_170 ( & V_8 -> V_50 , & V_148 ) ;
F_49 ( & V_2 -> V_132 ) ;
if ( V_136 - V_61 )
V_59 = V_136 - V_61 ;
return V_59 ;
}
static T_3 F_171 ( struct V_7 * V_8 , struct V_144 * V_144 ,
const unsigned char * V_61 , T_1 V_62 )
{
const unsigned char * V_136 = V_61 ;
F_159 ( V_148 , V_149 ) ;
int V_37 ;
T_3 V_59 = 0 ;
if ( F_172 ( V_8 ) && V_144 -> V_145 -> V_57 != V_146 ) {
V_59 = F_173 ( V_8 ) ;
if ( V_59 )
return V_59 ;
}
F_82 ( & V_8 -> V_51 ) ;
F_54 ( V_8 ) ;
F_162 ( & V_8 -> V_130 , & V_148 ) ;
while ( 1 ) {
if ( F_168 ( V_160 ) ) {
V_59 = - V_155 ;
break;
}
if ( F_167 ( V_144 ) || ( V_8 -> V_34 && ! V_8 -> V_34 -> V_112 ) ) {
V_59 = - V_159 ;
break;
}
if ( F_52 ( V_8 ) ) {
while ( V_62 > 0 ) {
T_3 V_163 = F_50 ( V_8 , V_136 , V_62 ) ;
if ( V_163 < 0 ) {
if ( V_163 == - V_154 )
break;
V_59 = V_163 ;
goto V_64;
}
V_136 += V_163 ;
V_62 -= V_163 ;
if ( V_62 == 0 )
break;
V_37 = * V_136 ;
if ( F_46 ( V_37 , V_8 ) < 0 )
break;
V_136 ++ ; V_62 -- ;
}
if ( V_8 -> V_56 -> V_80 )
V_8 -> V_56 -> V_80 ( V_8 ) ;
} else {
struct V_1 * V_2 = V_8 -> V_12 ;
while ( V_62 > 0 ) {
F_47 ( & V_2 -> V_60 ) ;
V_37 = V_8 -> V_56 -> V_57 ( V_8 , V_136 , V_62 ) ;
F_49 ( & V_2 -> V_60 ) ;
if ( V_37 < 0 ) {
V_59 = V_37 ;
goto V_64;
}
if ( ! V_37 )
break;
V_136 += V_37 ;
V_62 -= V_37 ;
}
}
if ( ! V_62 )
break;
if ( V_144 -> V_152 & V_153 ) {
V_59 = - V_154 ;
break;
}
F_80 ( & V_8 -> V_51 ) ;
F_169 ( & V_148 , V_161 , V_156 ) ;
F_82 ( & V_8 -> V_51 ) ;
}
V_64:
F_170 ( & V_8 -> V_130 , & V_148 ) ;
if ( V_62 && V_8 -> V_25 )
F_114 ( V_24 , & V_8 -> V_20 ) ;
F_80 ( & V_8 -> V_51 ) ;
return ( V_136 - V_61 ) ? V_136 - V_61 : V_59 ;
}
static unsigned int F_174 ( struct V_7 * V_8 , struct V_144 * V_144 ,
T_4 * V_148 )
{
unsigned int V_164 = 0 ;
F_175 ( V_144 , & V_8 -> V_50 , V_148 ) ;
F_175 ( V_144 , & V_8 -> V_130 , V_148 ) ;
if ( F_148 ( V_8 , 1 ) )
V_164 |= V_104 | V_165 ;
else {
F_166 ( V_8 -> V_17 ) ;
if ( F_148 ( V_8 , 1 ) )
V_164 |= V_104 | V_165 ;
}
if ( V_8 -> V_46 && V_8 -> V_34 -> V_48 )
V_164 |= V_166 | V_104 | V_165 ;
if ( F_12 ( V_158 , & V_8 -> V_20 ) )
V_164 |= V_167 ;
if ( F_167 ( V_144 ) )
V_164 |= V_167 ;
if ( V_8 -> V_56 -> V_57 && ! F_176 ( V_8 ) &&
F_177 ( V_8 ) < V_168 &&
F_48 ( V_8 ) > 0 )
V_164 |= V_169 | V_170 ;
return V_164 ;
}
static unsigned long F_178 ( struct V_1 * V_2 )
{
T_1 V_62 , V_77 , V_10 ;
if ( V_2 -> V_23 == V_2 -> V_4 )
return 0 ;
V_77 = V_2 -> V_23 ;
V_10 = V_2 -> V_4 ;
V_62 = V_77 - V_10 ;
while ( V_77 != V_10 ) {
if ( F_12 ( V_10 & ( V_6 - 1 ) , V_2 -> V_44 ) &&
F_2 ( V_2 , V_10 ) == V_102 )
V_62 -- ;
V_10 ++ ;
}
return V_62 ;
}
static int F_179 ( struct V_7 * V_8 , struct V_144 * V_144 ,
unsigned int V_171 , unsigned long V_172 )
{
struct V_1 * V_2 = V_8 -> V_12 ;
int V_59 ;
switch ( V_171 ) {
case V_173 :
return F_165 ( F_177 ( V_8 ) , ( int T_2 * ) V_172 ) ;
case V_174 :
F_33 ( & V_8 -> V_51 ) ;
if ( F_141 ( V_8 ) )
V_59 = F_178 ( V_2 ) ;
else
V_59 = F_1 ( V_2 ) ;
F_34 ( & V_8 -> V_51 ) ;
return F_165 ( V_59 , ( unsigned int T_2 * ) V_172 ) ;
default:
return F_180 ( V_8 , V_144 , V_171 , V_172 ) ;
}
}
void F_181 ( struct V_175 * V_56 )
{
* V_56 = V_176 ;
V_56 -> V_177 = NULL ;
V_56 -> V_178 = V_56 -> V_20 = 0 ;
}
void T_5 F_182 ( void )
{
F_183 ( V_179 , & V_176 ) ;
}

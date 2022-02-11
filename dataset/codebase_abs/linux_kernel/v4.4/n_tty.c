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
static inline int F_9 ( struct V_7 * V_8 ,
void T_2 * V_13 ,
const void * V_14 ,
unsigned long V_15 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
F_7 ( V_8 , V_14 , V_15 , V_2 -> V_12 ) ;
return F_10 ( V_13 , V_14 , V_15 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_12 ( V_2 -> V_16 ) ) {
V_2 -> V_16 = 0 ;
F_13 ( V_8 -> V_17 -> V_18 == NULL ,
L_1 ) ;
F_13 ( F_14 ( V_19 , & V_8 -> V_20 ) ,
L_2 ) ;
F_15 ( V_8 -> V_17 ) ;
}
}
static T_3 F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_3 V_15 = 0 ;
if ( ! V_2 -> V_12 )
V_15 = V_2 -> V_21 - V_2 -> V_4 ;
else
V_15 = V_2 -> V_22 - V_2 -> V_4 ;
return V_15 ;
}
static void F_17 ( struct V_7 * V_8 )
{
if ( V_8 -> V_23 && F_18 ( V_24 , & V_8 -> V_20 ) )
F_19 ( & V_8 -> V_23 , V_25 , V_26 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_2 -> V_12 && V_2 -> V_22 == V_2 -> V_4 )
return;
while ( 1 ) {
int V_27 ;
F_21 ( V_8 , V_28 ) ;
if ( V_6 - F_1 ( V_2 ) >= V_29 )
break;
V_27 = F_22 ( V_8 ) ;
if ( ! V_27 )
break;
}
F_23 ( V_8 , 0 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
if ( V_8 -> V_30 -> type == V_31 &&
V_8 -> V_32 -> V_33 -> V_34 -> V_35 == F_17 ) {
if ( F_16 ( V_8 ) > V_36 )
return;
if ( ! V_8 -> V_37 )
return;
F_11 ( V_8 ) ;
F_17 ( V_8 -> V_32 ) ;
if ( F_25 ( & V_8 -> V_32 -> V_38 ) )
F_26 ( & V_8 -> V_32 -> V_38 , V_39 ) ;
return;
}
while ( 1 ) {
int V_40 ;
F_21 ( V_8 , V_41 ) ;
if ( F_16 ( V_8 ) > V_36 )
break;
if ( ! V_8 -> V_37 )
break;
F_11 ( V_8 ) ;
V_40 = F_27 ( V_8 ) ;
if ( ! V_40 )
break;
}
F_23 ( V_8 , 0 ) ;
}
static inline void F_28 ( unsigned char V_42 , struct V_1 * V_2 )
{
* F_3 ( V_2 , V_2 -> V_3 ) = V_42 ;
V_2 -> V_3 ++ ;
}
static void F_29 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_22 = V_2 -> V_4 = 0 ;
V_2 -> V_43 = V_2 -> V_44 = V_2 -> V_45 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_46 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
F_30 ( V_2 -> V_49 , V_6 ) ;
V_2 -> V_50 = 0 ;
}
static void F_31 ( struct V_7 * V_8 )
{
unsigned long V_20 ;
if ( V_8 -> V_32 -> V_51 ) {
F_32 ( & V_8 -> V_52 , V_20 ) ;
V_8 -> V_53 |= V_54 ;
F_33 ( & V_8 -> V_52 , V_20 ) ;
F_34 ( & V_8 -> V_32 -> V_55 ) ;
}
}
static void F_35 ( struct V_7 * V_8 )
{
F_36 ( & V_8 -> V_56 ) ;
F_29 ( V_8 -> V_11 ) ;
F_11 ( V_8 ) ;
if ( V_8 -> V_32 )
F_31 ( V_8 ) ;
F_37 ( & V_8 -> V_56 ) ;
}
static T_3 F_38 ( struct V_7 * V_8 )
{
T_3 V_15 ;
F_39 ( 1 , L_3 , V_57 ) ;
F_36 ( & V_8 -> V_56 ) ;
V_15 = F_16 ( V_8 ) ;
F_37 ( & V_8 -> V_56 ) ;
return V_15 ;
}
static inline int F_40 ( unsigned char V_42 )
{
return ( V_42 & 0xc0 ) == 0x80 ;
}
static inline int F_41 ( unsigned char V_42 , struct V_7 * V_8 )
{
return F_42 ( V_8 ) && F_40 ( V_42 ) ;
}
static int F_43 ( unsigned char V_42 , struct V_7 * V_8 , int V_58 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_59 ;
if ( ! V_58 )
return - 1 ;
switch ( V_42 ) {
case '\n' :
if ( F_44 ( V_8 ) )
V_2 -> V_60 = 0 ;
if ( F_45 ( V_8 ) ) {
if ( V_58 < 2 )
return - 1 ;
V_2 -> V_61 = V_2 -> V_60 = 0 ;
V_8 -> V_34 -> V_62 ( V_8 , L_4 , 2 ) ;
return 2 ;
}
V_2 -> V_61 = V_2 -> V_60 ;
break;
case '\r' :
if ( F_46 ( V_8 ) && V_2 -> V_60 == 0 )
return 0 ;
if ( F_47 ( V_8 ) ) {
V_42 = '\n' ;
if ( F_44 ( V_8 ) )
V_2 -> V_61 = V_2 -> V_60 = 0 ;
break;
}
V_2 -> V_61 = V_2 -> V_60 = 0 ;
break;
case '\t' :
V_59 = 8 - ( V_2 -> V_60 & 7 ) ;
if ( F_48 ( V_8 ) == V_63 ) {
if ( V_58 < V_59 )
return - 1 ;
V_2 -> V_60 += V_59 ;
V_8 -> V_34 -> V_62 ( V_8 , L_5 , V_59 ) ;
return V_59 ;
}
V_2 -> V_60 += V_59 ;
break;
case '\b' :
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
break;
default:
if ( ! iscntrl ( V_42 ) ) {
if ( F_49 ( V_8 ) )
V_42 = toupper ( V_42 ) ;
if ( ! F_41 ( V_42 , V_8 ) )
V_2 -> V_60 ++ ;
}
break;
}
F_50 ( V_8 , V_42 ) ;
return 1 ;
}
static int F_51 ( unsigned char V_42 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_58 , V_64 ;
F_52 ( & V_2 -> V_65 ) ;
V_58 = F_53 ( V_8 ) ;
V_64 = F_43 ( V_42 , V_8 , V_58 ) ;
F_54 ( & V_2 -> V_65 ) ;
if ( V_64 < 0 )
return - 1 ;
else
return 0 ;
}
static T_3 F_55 ( struct V_7 * V_8 ,
const unsigned char * V_66 , unsigned int V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_58 ;
int V_5 ;
const unsigned char * V_68 ;
F_52 ( & V_2 -> V_65 ) ;
V_58 = F_53 ( V_8 ) ;
if ( ! V_58 ) {
F_54 ( & V_2 -> V_65 ) ;
return 0 ;
}
if ( V_67 > V_58 )
V_67 = V_58 ;
for ( V_5 = 0 , V_68 = V_66 ; V_5 < V_67 ; V_5 ++ , V_68 ++ ) {
unsigned char V_42 = * V_68 ;
switch ( V_42 ) {
case '\n' :
if ( F_44 ( V_8 ) )
V_2 -> V_60 = 0 ;
if ( F_45 ( V_8 ) )
goto V_69;
V_2 -> V_61 = V_2 -> V_60 ;
break;
case '\r' :
if ( F_46 ( V_8 ) && V_2 -> V_60 == 0 )
goto V_69;
if ( F_47 ( V_8 ) )
goto V_69;
V_2 -> V_61 = V_2 -> V_60 = 0 ;
break;
case '\t' :
goto V_69;
case '\b' :
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
break;
default:
if ( ! iscntrl ( V_42 ) ) {
if ( F_49 ( V_8 ) )
goto V_69;
if ( ! F_41 ( V_42 , V_8 ) )
V_2 -> V_60 ++ ;
}
break;
}
}
V_69:
V_5 = V_8 -> V_34 -> V_62 ( V_8 , V_66 , V_5 ) ;
F_54 ( & V_2 -> V_65 ) ;
return V_5 ;
}
static T_1 F_56 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_58 , V_70 ;
T_1 V_71 ;
unsigned char V_42 ;
V_70 = V_58 = F_53 ( V_8 ) ;
V_71 = V_2 -> V_44 ;
while ( V_2 -> V_45 != V_71 ) {
V_42 = F_4 ( V_2 , V_71 ) ;
if ( V_42 == V_72 ) {
unsigned char V_73 ;
int V_74 = 0 ;
V_73 = F_4 ( V_2 , V_71 + 1 ) ;
switch ( V_73 ) {
unsigned int V_75 , V_76 ;
case V_77 :
V_75 = F_4 ( V_2 , V_71 + 2 ) ;
if ( ! ( V_75 & 0x80 ) )
V_75 += V_2 -> V_61 ;
V_76 = 8 - ( V_75 & 7 ) ;
if ( V_76 > V_58 ) {
V_74 = 1 ;
break;
}
V_58 -= V_76 ;
while ( V_76 -- ) {
F_50 ( V_8 , '\b' ) ;
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
}
V_71 += 3 ;
break;
case V_78 :
V_2 -> V_61 = V_2 -> V_60 ;
V_71 += 2 ;
break;
case V_79 :
if ( V_2 -> V_60 > 0 )
V_2 -> V_60 -- ;
V_71 += 2 ;
break;
case V_72 :
if ( ! V_58 ) {
V_74 = 1 ;
break;
}
F_50 ( V_8 , V_72 ) ;
V_2 -> V_60 ++ ;
V_58 -- ;
V_71 += 2 ;
break;
default:
if ( V_58 < 2 ) {
V_74 = 1 ;
break;
}
F_50 ( V_8 , '^' ) ;
F_50 ( V_8 , V_73 ^ 0100 ) ;
V_2 -> V_60 += 2 ;
V_58 -= 2 ;
V_71 += 2 ;
}
if ( V_74 )
break;
} else {
if ( F_57 ( V_8 ) ) {
int V_64 = F_43 ( V_42 , V_8 , V_58 ) ;
if ( V_64 < 0 )
break;
V_58 -= V_64 ;
} else {
if ( ! V_58 )
break;
F_50 ( V_8 , V_42 ) ;
V_58 -= 1 ;
}
V_71 += 1 ;
}
}
while ( V_2 -> V_45 - V_71 >= V_80 ) {
if ( F_4 ( V_2 , V_71 ) == V_72 ) {
if ( F_4 ( V_2 , V_71 + 1 ) == V_77 )
V_71 += 3 ;
else
V_71 += 2 ;
} else
V_71 ++ ;
}
V_2 -> V_44 = V_71 ;
return V_70 - V_58 ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_67 , V_81 , V_82 ;
T_1 V_83 ;
V_83 = V_2 -> V_43 ;
V_2 -> V_46 = V_83 ;
V_81 = V_2 -> V_45 - V_2 -> V_44 ;
V_67 = V_83 - V_2 -> V_44 ;
if ( V_67 < V_84 || ( V_67 % V_85 > V_81 % V_85 ) )
return;
F_52 ( & V_2 -> V_65 ) ;
V_2 -> V_45 = V_83 ;
V_82 = F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_65 ) ;
if ( V_82 && V_8 -> V_34 -> V_86 )
V_8 -> V_34 -> V_86 ( V_8 ) ;
}
static void F_59 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_82 ;
if ( V_2 -> V_46 == V_2 -> V_44 )
return;
F_52 ( & V_2 -> V_65 ) ;
V_2 -> V_45 = V_2 -> V_46 ;
V_82 = F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_65 ) ;
if ( V_82 && V_8 -> V_34 -> V_86 )
V_8 -> V_34 -> V_86 ( V_8 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ( ! F_61 ( V_8 ) && ! F_62 ( V_8 ) ) ||
V_2 -> V_45 == V_2 -> V_43 )
return;
F_52 ( & V_2 -> V_65 ) ;
V_2 -> V_45 = V_2 -> V_43 ;
F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_65 ) ;
}
static inline void F_63 ( unsigned char V_42 , struct V_1 * V_2 )
{
* F_5 ( V_2 , V_2 -> V_43 ++ ) = V_42 ;
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
static void F_67 ( unsigned char V_42 , struct V_1 * V_2 )
{
if ( V_42 == V_72 ) {
F_63 ( V_72 , V_2 ) ;
F_63 ( V_72 , V_2 ) ;
} else {
F_63 ( V_42 , V_2 ) ;
}
}
static void F_68 ( unsigned char V_42 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_42 == V_72 ) {
F_63 ( V_72 , V_2 ) ;
F_63 ( V_72 , V_2 ) ;
} else {
if ( F_69 ( V_8 ) && iscntrl ( V_42 ) && V_42 != '\t' )
F_63 ( V_72 , V_2 ) ;
F_63 ( V_42 , V_2 ) ;
}
}
static inline void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_48 ) {
F_67 ( '/' , V_2 ) ;
V_2 -> V_48 = 0 ;
}
}
static void F_71 ( unsigned char V_42 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
enum { V_88 , V_89 , V_90 } V_91 ;
T_1 V_83 ;
T_1 V_92 ;
int V_93 ;
if ( V_2 -> V_3 == V_2 -> V_22 ) {
return;
}
if ( V_42 == F_72 ( V_8 ) )
V_91 = V_88 ;
else if ( V_42 == F_73 ( V_8 ) )
V_91 = V_89 ;
else {
if ( ! F_61 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_22 ;
return;
}
if ( ! F_74 ( V_8 ) || ! F_75 ( V_8 ) || ! F_76 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_22 ;
F_70 ( V_2 ) ;
F_68 ( F_77 ( V_8 ) , V_8 ) ;
if ( F_74 ( V_8 ) )
F_67 ( '\n' , V_2 ) ;
return;
}
V_91 = V_90 ;
}
V_93 = 0 ;
while ( V_2 -> V_3 != V_2 -> V_22 ) {
V_83 = V_2 -> V_3 ;
do {
V_83 -- ;
V_42 = F_2 ( V_2 , V_83 ) ;
} while ( F_41 ( V_42 , V_8 ) && V_83 != V_2 -> V_22 );
if ( F_41 ( V_42 , V_8 ) )
break;
if ( V_91 == V_89 ) {
if ( isalnum ( V_42 ) || V_42 == '_' )
V_93 ++ ;
else if ( V_93 )
break;
}
V_92 = V_2 -> V_3 - V_83 ;
V_2 -> V_3 = V_83 ;
if ( F_61 ( V_8 ) ) {
if ( F_78 ( V_8 ) ) {
if ( ! V_2 -> V_48 ) {
F_67 ( '\\' , V_2 ) ;
V_2 -> V_48 = 1 ;
}
F_68 ( V_42 , V_8 ) ;
while ( -- V_92 > 0 ) {
V_83 ++ ;
F_67 ( F_2 ( V_2 , V_83 ) , V_2 ) ;
F_64 ( V_2 ) ;
}
} else if ( V_91 == V_88 && ! F_76 ( V_8 ) ) {
F_68 ( F_72 ( V_8 ) , V_8 ) ;
} else if ( V_42 == '\t' ) {
unsigned int V_75 = 0 ;
int V_87 = 0 ;
T_1 V_71 = V_2 -> V_3 ;
while ( V_71 != V_2 -> V_22 ) {
V_71 -- ;
V_42 = F_2 ( V_2 , V_71 ) ;
if ( V_42 == '\t' ) {
V_87 = 1 ;
break;
} else if ( iscntrl ( V_42 ) ) {
if ( F_69 ( V_8 ) )
V_75 += 2 ;
} else if ( ! F_41 ( V_42 , V_8 ) ) {
V_75 ++ ;
}
}
F_66 ( V_75 , V_87 , V_2 ) ;
} else {
if ( iscntrl ( V_42 ) && F_69 ( V_8 ) ) {
F_67 ( '\b' , V_2 ) ;
F_67 ( ' ' , V_2 ) ;
F_67 ( '\b' , V_2 ) ;
}
if ( ! iscntrl ( V_42 ) || F_69 ( V_8 ) ) {
F_67 ( '\b' , V_2 ) ;
F_67 ( ' ' , V_2 ) ;
F_67 ( '\b' , V_2 ) ;
}
}
}
if ( V_91 == V_88 )
break;
}
if ( V_2 -> V_3 == V_2 -> V_22 && F_61 ( V_8 ) )
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
static void F_83 ( int V_94 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_84 ( V_8 ) ) {
F_79 ( V_94 , V_8 ) ;
} else {
F_85 ( & V_8 -> V_56 ) ;
F_36 ( & V_8 -> V_56 ) ;
F_79 ( V_94 , V_8 ) ;
F_52 ( & V_2 -> V_65 ) ;
V_2 -> V_43 = V_2 -> V_44 = 0 ;
V_2 -> V_46 = V_2 -> V_45 = 0 ;
F_54 ( & V_2 -> V_65 ) ;
F_86 ( V_8 ) ;
F_29 ( V_8 -> V_11 ) ;
if ( V_8 -> V_32 )
F_31 ( V_8 ) ;
F_37 ( & V_8 -> V_56 ) ;
F_87 ( & V_8 -> V_56 ) ;
}
}
static void F_88 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_89 ( V_8 ) )
return;
if ( F_90 ( V_8 ) ) {
F_83 ( V_97 , V_8 ) ;
return;
}
if ( F_91 ( V_8 ) ) {
F_28 ( '\377' , V_2 ) ;
F_28 ( '\0' , V_2 ) ;
}
F_28 ( '\0' , V_2 ) ;
}
static void F_92 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_98 ++ ;
if ( F_93 ( V_99 , V_2 -> V_100 + V_101 ) ||
F_93 ( V_2 -> V_100 , V_99 ) ) {
F_94 ( V_102 L_6 ,
F_95 ( V_8 ) ,
V_2 -> V_98 ) ;
V_2 -> V_100 = V_99 ;
V_2 -> V_98 = 0 ;
}
}
static void F_96 ( struct V_7 * V_8 , unsigned char V_42 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_97 ( V_8 ) ) {
if ( F_98 ( V_8 ) )
return;
if ( F_91 ( V_8 ) ) {
F_28 ( '\377' , V_2 ) ;
F_28 ( '\0' , V_2 ) ;
F_28 ( V_42 , V_2 ) ;
} else
F_28 ( '\0' , V_2 ) ;
} else
F_28 ( V_42 , V_2 ) ;
}
static void
F_99 ( struct V_7 * V_8 , int signal , unsigned char V_42 )
{
F_83 ( signal , V_8 ) ;
if ( F_100 ( V_8 ) )
F_101 ( V_8 ) ;
if ( F_61 ( V_8 ) ) {
F_68 ( V_42 , V_8 ) ;
F_58 ( V_8 ) ;
} else
F_59 ( V_8 ) ;
return;
}
static int
F_102 ( struct V_7 * V_8 , unsigned char V_42 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_100 ( V_8 ) ) {
if ( V_42 == F_103 ( V_8 ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
return 0 ;
}
if ( V_42 == F_104 ( V_8 ) ) {
F_105 ( V_8 ) ;
return 0 ;
}
}
if ( F_106 ( V_8 ) ) {
if ( V_42 == F_107 ( V_8 ) ) {
F_99 ( V_8 , V_97 , V_42 ) ;
return 0 ;
} else if ( V_42 == F_108 ( V_8 ) ) {
F_99 ( V_8 , V_103 , V_42 ) ;
return 0 ;
} else if ( V_42 == F_109 ( V_8 ) ) {
F_99 ( V_8 , V_104 , V_42 ) ;
return 0 ;
}
}
if ( V_8 -> V_105 && ! V_8 -> V_106 && F_100 ( V_8 ) && F_110 ( V_8 ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( V_42 == '\r' ) {
if ( F_111 ( V_8 ) )
return 0 ;
if ( F_112 ( V_8 ) )
V_42 = '\n' ;
} else if ( V_42 == '\n' && F_113 ( V_8 ) )
V_42 = '\r' ;
if ( V_2 -> V_12 ) {
if ( V_42 == F_72 ( V_8 ) || V_42 == F_77 ( V_8 ) ||
( V_42 == F_73 ( V_8 ) && F_114 ( V_8 ) ) ) {
F_71 ( V_42 , V_8 ) ;
F_58 ( V_8 ) ;
return 0 ;
}
if ( V_42 == F_115 ( V_8 ) && F_114 ( V_8 ) ) {
V_2 -> V_107 = 1 ;
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
if ( V_42 == F_116 ( V_8 ) && F_61 ( V_8 ) && F_114 ( V_8 ) ) {
T_1 V_71 = V_2 -> V_22 ;
F_70 ( V_2 ) ;
F_68 ( V_42 , V_8 ) ;
F_67 ( '\n' , V_2 ) ;
while ( V_71 != V_2 -> V_3 ) {
F_68 ( F_2 ( V_2 , V_71 ) , V_8 ) ;
V_71 ++ ;
}
F_58 ( V_8 ) ;
return 0 ;
}
if ( V_42 == '\n' ) {
if ( F_61 ( V_8 ) || F_62 ( V_8 ) ) {
F_67 ( '\n' , V_2 ) ;
F_58 ( V_8 ) ;
}
goto V_108;
}
if ( V_42 == F_117 ( V_8 ) ) {
V_42 = V_109 ;
goto V_108;
}
if ( ( V_42 == F_118 ( V_8 ) ) ||
( V_42 == F_119 ( V_8 ) && F_114 ( V_8 ) ) ) {
if ( F_61 ( V_8 ) ) {
if ( V_2 -> V_22 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_42 , V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_42 == ( unsigned char ) '\377' && F_91 ( V_8 ) )
F_28 ( V_42 , V_2 ) ;
V_108:
F_120 ( V_2 -> V_3 & ( V_6 - 1 ) , V_2 -> V_49 ) ;
F_28 ( V_42 , V_2 ) ;
F_121 ( & V_2 -> V_22 , V_2 -> V_3 ) ;
F_19 ( & V_8 -> V_23 , V_25 , V_110 ) ;
F_26 ( & V_8 -> V_55 , V_111 ) ;
return 0 ;
}
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_42 == '\n' )
F_67 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_22 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_42 , V_8 ) ;
}
F_58 ( V_8 ) ;
}
if ( V_42 == ( unsigned char ) '\377' && F_91 ( V_8 ) )
F_28 ( V_42 , V_2 ) ;
F_28 ( V_42 , V_2 ) ;
return 0 ;
}
static inline void
F_122 ( struct V_7 * V_8 , unsigned char V_42 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_105 && ! V_8 -> V_106 && F_100 ( V_8 ) && F_110 ( V_8 ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_2 -> V_22 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_42 , V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_42 == ( unsigned char ) '\377' && F_91 ( V_8 ) )
F_28 ( V_42 , V_2 ) ;
F_28 ( V_42 , V_2 ) ;
}
static void F_123 ( struct V_7 * V_8 , unsigned char V_42 )
{
F_122 ( V_8 , V_42 ) ;
}
static inline void
F_124 ( struct V_7 * V_8 , unsigned char V_42 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_105 && ! V_8 -> V_106 && F_100 ( V_8 ) && F_110 ( V_8 ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_2 -> V_22 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_42 , V_8 ) ;
F_58 ( V_8 ) ;
}
F_28 ( V_42 , V_2 ) ;
}
static void F_125 ( struct V_7 * V_8 , unsigned char V_42 )
{
if ( F_126 ( V_8 ) )
V_42 &= 0x7f ;
if ( F_127 ( V_8 ) && F_114 ( V_8 ) )
V_42 = tolower ( V_42 ) ;
if ( F_100 ( V_8 ) ) {
if ( V_42 == F_104 ( V_8 ) )
F_105 ( V_8 ) ;
else if ( V_42 == F_103 ( V_8 ) ||
( V_8 -> V_105 && ! V_8 -> V_106 && F_110 ( V_8 ) &&
V_42 != F_107 ( V_8 ) && V_42 != F_108 ( V_8 ) &&
V_42 != F_109 ( V_8 ) ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
}
}
static void
F_128 ( struct V_7 * V_8 , unsigned char V_42 , char V_112 )
{
switch ( V_112 ) {
case V_113 :
F_88 ( V_8 ) ;
break;
case V_114 :
case V_115 :
F_96 ( V_8 , V_42 ) ;
break;
case V_116 :
F_92 ( V_8 ) ;
break;
default:
F_94 ( V_117 L_7 ,
F_95 ( V_8 ) , V_112 ) ;
break;
}
}
static void
F_129 ( struct V_7 * V_8 , unsigned char V_42 , char V_112 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_107 = 0 ;
if ( F_130 ( V_112 == V_118 ) ) {
if ( F_126 ( V_8 ) )
V_42 &= 0x7f ;
if ( F_127 ( V_8 ) && F_114 ( V_8 ) )
V_42 = tolower ( V_42 ) ;
F_123 ( V_8 , V_42 ) ;
} else
F_128 ( V_8 , V_42 , V_112 ) ;
}
static void
F_131 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_15 , V_83 ;
V_83 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_15 = F_132 ( T_1 , V_37 , V_6 - V_83 ) ;
memcpy ( F_3 ( V_2 , V_83 ) , V_68 , V_15 ) ;
V_2 -> V_3 += V_15 ;
V_68 += V_15 ;
V_37 -= V_15 ;
V_83 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_15 = F_132 ( T_1 , V_37 , V_6 - V_83 ) ;
memcpy ( F_3 ( V_2 , V_83 ) , V_68 , V_15 ) ;
V_2 -> V_3 += V_15 ;
}
static void
F_133 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_112 = V_118 ;
while ( V_37 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_130 ( V_112 == V_118 ) )
F_28 ( * V_68 ++ , V_2 ) ;
else
F_128 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void
F_134 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 )
{
char V_112 = V_118 ;
while ( V_37 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_130 ( V_112 == V_118 ) )
F_125 ( V_8 , * V_68 ++ ) ;
else
F_128 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void
F_135 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_112 = V_118 ;
while ( V_37 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_130 ( V_112 == V_118 ) ) {
unsigned char V_42 = * V_68 ++ ;
if ( F_126 ( V_8 ) )
V_42 &= 0x7f ;
if ( F_127 ( V_8 ) && F_114 ( V_8 ) )
V_42 = tolower ( V_42 ) ;
if ( F_136 ( V_8 ) ) {
F_28 ( V_42 , V_2 ) ;
continue;
}
if ( ! F_14 ( V_42 , V_2 -> V_120 ) )
F_122 ( V_8 , V_42 ) ;
else if ( F_102 ( V_8 , V_42 ) && V_37 ) {
if ( V_119 )
V_112 = * V_119 ++ ;
F_129 ( V_8 , * V_68 ++ , V_112 ) ;
V_37 -- ;
}
} else
F_128 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void
F_137 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_112 = V_118 ;
while ( V_37 -- ) {
if ( V_119 )
V_112 = * V_119 ++ ;
if ( F_130 ( V_112 == V_118 ) ) {
unsigned char V_42 = * V_68 ++ ;
if ( ! F_14 ( V_42 , V_2 -> V_120 ) )
F_124 ( V_8 , V_42 ) ;
else if ( F_102 ( V_8 , V_42 ) && V_37 ) {
if ( V_119 )
V_112 = * V_119 ++ ;
F_129 ( V_8 , * V_68 ++ , V_112 ) ;
V_37 -- ;
}
} else
F_128 ( V_8 , * V_68 ++ , V_112 ) ;
}
}
static void F_138 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
bool V_121 = F_126 ( V_8 ) || ( F_127 ( V_8 ) && F_114 ( V_8 ) ) ;
if ( V_2 -> V_122 )
F_131 ( V_8 , V_68 , V_119 , V_37 ) ;
else if ( V_2 -> V_123 || ( F_136 ( V_8 ) && ! V_121 ) )
F_133 ( V_8 , V_68 , V_119 , V_37 ) ;
else if ( V_8 -> V_124 && ! F_136 ( V_8 ) )
F_134 ( V_8 , V_68 , V_119 , V_37 ) ;
else {
if ( V_2 -> V_107 ) {
char V_112 = V_118 ;
if ( V_119 )
V_112 = * V_119 ++ ;
F_129 ( V_8 , * V_68 ++ , V_112 ) ;
V_37 -- ;
}
if ( ! V_121 && ! F_91 ( V_8 ) )
F_137 ( V_8 , V_68 , V_119 , V_37 ) ;
else
F_135 ( V_8 , V_68 , V_119 , V_37 ) ;
F_60 ( V_8 ) ;
if ( V_8 -> V_34 -> V_86 )
V_8 -> V_34 -> V_86 ( V_8 ) ;
}
if ( V_2 -> V_12 && ! F_136 ( V_8 ) )
return;
F_121 ( & V_2 -> V_21 , V_2 -> V_3 ) ;
if ( ( F_1 ( V_2 ) >= V_2 -> V_125 ) || F_136 ( V_8 ) ) {
F_19 ( & V_8 -> V_23 , V_25 , V_110 ) ;
F_26 ( & V_8 -> V_55 , V_111 ) ;
}
}
static int
F_139 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 , int V_126 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_127 , V_15 , V_128 = 0 , V_129 ;
F_87 ( & V_8 -> V_56 ) ;
while ( 1 ) {
T_1 V_71 = F_140 ( & V_2 -> V_4 ) ;
V_127 = V_6 - ( V_2 -> V_3 - V_71 ) ;
if ( F_91 ( V_8 ) )
V_127 = ( V_127 + 2 ) / 3 ;
V_127 -- ;
if ( V_127 <= 0 ) {
V_129 = V_2 -> V_12 && V_2 -> V_22 == V_71 ;
if ( V_129 && V_127 < 0 )
V_2 -> V_3 -- ;
V_127 = V_129 ;
V_2 -> V_16 = V_126 && ! V_127 ;
} else
V_129 = 0 ;
V_15 = F_141 ( V_37 , V_127 ) ;
if ( ! V_15 )
break;
if ( ! V_129 || ! V_119 || * V_119 != V_114 )
F_138 ( V_8 , V_68 , V_119 , V_15 ) ;
V_68 += V_15 ;
if ( V_119 )
V_119 += V_15 ;
V_37 -= V_15 ;
V_128 += V_15 ;
}
V_8 -> V_130 = V_127 ;
if ( V_8 -> V_30 -> type == V_31 ) {
if ( V_129 ) {
F_21 ( V_8 , V_41 ) ;
F_27 ( V_8 ) ;
F_23 ( V_8 , 0 ) ;
}
} else
F_20 ( V_8 ) ;
F_85 ( & V_8 -> V_56 ) ;
return V_128 ;
}
static void F_142 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 )
{
F_139 ( V_8 , V_68 , V_119 , V_37 , 0 ) ;
}
static int F_143 ( struct V_7 * V_8 , const unsigned char * V_68 ,
char * V_119 , int V_37 )
{
return F_139 ( V_8 , V_68 , V_119 , V_37 , 1 ) ;
}
int F_144 ( int V_94 )
{
return ( F_145 ( & V_131 -> V_132 , V_94 ) ||
V_131 -> V_133 -> V_134 [ V_94 - 1 ] . V_135 . V_136 == V_137 ) ;
}
static void F_146 ( struct V_7 * V_8 , struct V_138 * V_81 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! V_81 || ( V_81 -> V_139 ^ V_8 -> V_140 . V_139 ) & V_141 ) {
F_30 ( V_2 -> V_49 , V_6 ) ;
V_2 -> V_47 = V_2 -> V_4 ;
if ( ! F_147 ( V_8 ) || ! F_1 ( V_2 ) ) {
V_2 -> V_22 = V_2 -> V_4 ;
V_2 -> V_50 = 0 ;
} else {
F_120 ( ( V_2 -> V_3 - 1 ) & ( V_6 - 1 ) ,
V_2 -> V_49 ) ;
V_2 -> V_22 = V_2 -> V_3 ;
V_2 -> V_50 = 1 ;
}
V_2 -> V_21 = V_2 -> V_3 ;
V_2 -> V_48 = 0 ;
V_2 -> V_107 = 0 ;
}
V_2 -> V_12 = ( F_147 ( V_8 ) != 0 ) ;
if ( F_126 ( V_8 ) || F_127 ( V_8 ) || F_111 ( V_8 ) ||
F_112 ( V_8 ) || F_113 ( V_8 ) || F_147 ( V_8 ) ||
F_100 ( V_8 ) || F_106 ( V_8 ) || F_61 ( V_8 ) ||
F_91 ( V_8 ) ) {
F_30 ( V_2 -> V_120 , 256 ) ;
if ( F_111 ( V_8 ) || F_112 ( V_8 ) )
F_120 ( '\r' , V_2 -> V_120 ) ;
if ( F_113 ( V_8 ) )
F_120 ( '\n' , V_2 -> V_120 ) ;
if ( F_147 ( V_8 ) ) {
F_120 ( F_72 ( V_8 ) , V_2 -> V_120 ) ;
F_120 ( F_77 ( V_8 ) , V_2 -> V_120 ) ;
F_120 ( F_117 ( V_8 ) , V_2 -> V_120 ) ;
F_120 ( '\n' , V_2 -> V_120 ) ;
F_120 ( F_118 ( V_8 ) , V_2 -> V_120 ) ;
if ( F_114 ( V_8 ) ) {
F_120 ( F_73 ( V_8 ) , V_2 -> V_120 ) ;
F_120 ( F_115 ( V_8 ) , V_2 -> V_120 ) ;
F_120 ( F_119 ( V_8 ) , V_2 -> V_120 ) ;
if ( F_61 ( V_8 ) )
F_120 ( F_116 ( V_8 ) ,
V_2 -> V_120 ) ;
}
}
if ( F_100 ( V_8 ) ) {
F_120 ( F_103 ( V_8 ) , V_2 -> V_120 ) ;
F_120 ( F_104 ( V_8 ) , V_2 -> V_120 ) ;
}
if ( F_106 ( V_8 ) ) {
F_120 ( F_107 ( V_8 ) , V_2 -> V_120 ) ;
F_120 ( F_108 ( V_8 ) , V_2 -> V_120 ) ;
F_120 ( F_109 ( V_8 ) , V_2 -> V_120 ) ;
}
F_148 ( V_109 , V_2 -> V_120 ) ;
V_2 -> V_123 = 0 ;
V_2 -> V_122 = 0 ;
} else {
V_2 -> V_123 = 1 ;
if ( ( F_89 ( V_8 ) || ( ! F_90 ( V_8 ) && ! F_91 ( V_8 ) ) ) &&
( F_98 ( V_8 ) || ! F_97 ( V_8 ) ) &&
( V_8 -> V_30 -> V_20 & V_142 ) )
V_2 -> V_122 = 1 ;
else
V_2 -> V_122 = 0 ;
}
if ( ! F_100 ( V_8 ) && V_81 && ( V_81 -> V_143 & V_144 ) && ! V_8 -> V_106 ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
F_34 ( & V_8 -> V_38 ) ;
F_34 ( & V_8 -> V_55 ) ;
}
static void F_149 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_32 )
F_31 ( V_8 ) ;
F_150 ( V_2 ) ;
V_8 -> V_11 = NULL ;
}
static int F_151 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_152 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_145;
V_2 -> V_100 = V_99 ;
F_153 ( & V_2 -> V_146 ) ;
F_153 ( & V_2 -> V_65 ) ;
V_8 -> V_11 = V_2 ;
F_29 ( V_8 -> V_11 ) ;
V_2 -> V_60 = 0 ;
V_2 -> V_61 = 0 ;
V_2 -> V_125 = 1 ;
V_2 -> V_98 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_107 = 0 ;
V_8 -> V_124 = 0 ;
F_148 ( V_19 , & V_8 -> V_20 ) ;
F_146 ( V_8 , NULL ) ;
F_154 ( V_8 ) ;
return 0 ;
V_145:
return - V_147 ;
}
static inline int F_155 ( struct V_7 * V_8 , int V_148 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_149 = V_148 && ! F_156 ( V_8 ) && F_157 ( V_8 ) ? F_157 ( V_8 ) : 1 ;
if ( V_2 -> V_12 && ! F_136 ( V_8 ) )
return V_2 -> V_22 != V_2 -> V_4 ;
else
return V_2 -> V_21 - V_2 -> V_4 >= V_149 ;
}
static inline int F_158 ( struct V_7 * V_8 )
{
int V_150 = F_14 ( V_151 , & V_8 -> V_20 ) ;
if ( V_150 ) {
F_159 () ;
}
return V_150 ;
}
static int F_160 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_152 ,
T_1 * V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_64 ;
T_1 V_15 ;
bool V_153 ;
T_1 V_83 = F_140 ( & V_2 -> V_21 ) ;
T_1 V_71 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_64 = 0 ;
V_15 = F_141 ( V_83 - V_2 -> V_4 , V_6 - V_71 ) ;
V_15 = F_141 ( * V_67 , V_15 ) ;
if ( V_15 ) {
V_64 = F_10 ( * V_152 , F_3 ( V_2 , V_71 ) , V_15 ) ;
V_15 -= V_64 ;
V_153 = V_15 == 1 && F_2 ( V_2 , V_71 ) == F_117 ( V_8 ) ;
F_7 ( V_8 , F_3 ( V_2 , V_71 ) , V_15 ,
V_2 -> V_12 ) ;
F_121 ( & V_2 -> V_4 , V_2 -> V_4 + V_15 ) ;
if ( F_136 ( V_8 ) && V_2 -> V_12 && V_153 &&
( V_83 == V_2 -> V_4 ) )
V_15 = 0 ;
* V_152 += V_15 ;
* V_67 -= V_15 ;
}
return V_64 ;
}
static int F_161 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_152 ,
T_1 * V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_15 , V_154 , V_155 , V_42 ;
T_1 V_156 ;
T_1 V_71 ;
int V_157 , V_158 = 0 ;
if ( ! * V_67 )
return 0 ;
V_15 = F_141 ( * V_67 + 1 , F_140 ( & V_2 -> V_22 ) - V_2 -> V_4 ) ;
V_71 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_154 = F_132 ( T_1 , V_71 + V_15 , V_6 ) ;
F_162 ( L_8 ,
V_57 , * V_67 , V_71 , V_15 , V_154 ) ;
V_156 = F_163 ( V_2 -> V_49 , V_154 , V_71 ) ;
V_155 = V_15 - ( V_154 - V_71 ) ;
if ( V_156 == V_6 && V_155 ) {
V_156 = F_163 ( V_2 -> V_49 , V_155 , 0 ) ;
if ( V_156 != V_155 )
V_158 = 1 ;
} else if ( V_156 != V_154 )
V_158 = 1 ;
V_154 = V_6 - V_71 ;
V_15 = V_156 - V_71 ;
if ( V_15 > V_6 )
V_15 += V_6 ;
V_42 = V_15 + V_158 ;
if ( ! V_158 || F_2 ( V_2 , V_156 ) != V_109 ) {
V_42 = F_141 ( * V_67 , V_42 ) ;
V_15 = V_42 ;
}
F_162 ( L_9 ,
V_57 , V_156 , V_158 , V_15 , V_42 , V_154 , V_155 ) ;
if ( V_15 > V_154 ) {
V_157 = F_9 ( V_8 , * V_152 , F_3 ( V_2 , V_71 ) , V_154 ) ;
if ( V_157 )
return - V_159 ;
V_157 = F_9 ( V_8 , * V_152 + V_154 , V_2 -> F_2 , V_15 - V_154 ) ;
} else
V_157 = F_9 ( V_8 , * V_152 , F_3 ( V_2 , V_71 ) , V_15 ) ;
if ( V_157 )
return - V_159 ;
* V_152 += V_15 ;
* V_67 -= V_15 ;
if ( V_158 )
F_148 ( V_156 , V_2 -> V_49 ) ;
F_121 ( & V_2 -> V_4 , V_2 -> V_4 + V_42 ) ;
if ( V_158 ) {
if ( ! V_2 -> V_50 )
V_2 -> V_47 = V_2 -> V_4 ;
else
V_2 -> V_50 = 0 ;
F_164 ( V_8 ) ;
}
return 0 ;
}
static int F_165 ( struct V_7 * V_8 , struct V_160 * V_160 )
{
if ( V_160 -> V_161 -> V_62 == V_162 )
return 0 ;
return F_166 ( V_8 , V_163 ) ;
}
static T_3 F_167 ( struct V_7 * V_8 , struct V_160 * V_160 ,
unsigned char T_2 * V_66 , T_1 V_67 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned char T_2 * V_152 = V_66 ;
F_168 ( V_164 , V_165 ) ;
int V_42 , V_150 ;
int V_166 , time ;
T_3 V_64 = 0 ;
long V_167 ;
int V_51 ;
T_1 V_71 ;
V_42 = F_165 ( V_8 , V_160 ) ;
if ( V_42 < 0 )
return V_42 ;
if ( V_160 -> V_168 & V_169 ) {
if ( ! F_169 ( & V_2 -> V_146 ) )
return - V_170 ;
} else {
if ( F_170 ( & V_2 -> V_146 ) )
return - V_171 ;
}
F_87 ( & V_8 -> V_56 ) ;
V_166 = time = 0 ;
V_167 = V_172 ;
if ( ! V_2 -> V_12 ) {
V_166 = F_157 ( V_8 ) ;
if ( V_166 ) {
time = ( V_101 / 10 ) * F_156 ( V_8 ) ;
if ( time )
V_2 -> V_125 = 1 ;
else if ( ! F_25 ( & V_8 -> V_55 ) ||
( V_2 -> V_125 > V_166 ) )
V_2 -> V_125 = V_166 ;
} else {
V_167 = ( V_101 / 10 ) * F_156 ( V_8 ) ;
V_2 -> V_125 = V_166 = 1 ;
}
}
V_51 = V_8 -> V_51 ;
V_71 = V_2 -> V_4 ;
F_171 ( & V_8 -> V_55 , & V_164 ) ;
while ( V_67 ) {
if ( V_51 && V_8 -> V_32 -> V_53 ) {
unsigned char V_173 ;
if ( V_152 != V_66 )
break;
F_172 ( & V_8 -> V_32 -> V_52 ) ;
V_173 = V_8 -> V_32 -> V_53 ;
V_8 -> V_32 -> V_53 = 0 ;
F_173 ( & V_8 -> V_32 -> V_52 ) ;
if ( F_6 ( V_8 , V_173 , V_152 ++ ) ) {
V_64 = - V_159 ;
V_152 -- ;
break;
}
V_67 -- ;
break;
}
if ( ( ( V_166 - ( V_152 - V_66 ) ) < V_2 -> V_125 ) &&
( ( V_166 - ( V_152 - V_66 ) ) >= 1 ) )
V_2 -> V_125 = ( V_166 - ( V_152 - V_66 ) ) ;
V_150 = F_158 ( V_8 ) ;
if ( ! F_155 ( V_8 , 0 ) ) {
if ( V_150 ) {
V_64 = - V_174 ;
break;
}
if ( F_174 ( V_160 ) )
break;
if ( ! V_167 )
break;
if ( V_160 -> V_168 & V_169 ) {
V_64 = - V_170 ;
break;
}
if ( F_175 ( V_131 ) ) {
V_64 = - V_171 ;
break;
}
F_85 ( & V_8 -> V_56 ) ;
V_167 = F_176 ( & V_164 , V_175 ,
V_167 ) ;
F_87 ( & V_8 -> V_56 ) ;
continue;
}
if ( V_2 -> V_12 && ! F_136 ( V_8 ) ) {
V_64 = F_161 ( V_8 , & V_152 , & V_67 ) ;
if ( V_64 )
break;
} else {
int V_176 ;
if ( V_51 && V_152 == V_66 ) {
if ( F_6 ( V_8 , V_177 , V_152 ++ ) ) {
V_64 = - V_159 ;
V_152 -- ;
break;
}
V_67 -- ;
}
V_176 = F_160 ( V_8 , & V_152 , & V_67 ) ;
V_176 += F_160 ( V_8 , & V_152 , & V_67 ) ;
if ( V_176 ) {
V_64 = - V_159 ;
break;
}
}
F_24 ( V_8 ) ;
if ( V_152 - V_66 >= V_166 )
break;
if ( time )
V_167 = time ;
}
if ( V_71 != V_2 -> V_4 )
F_11 ( V_8 ) ;
F_85 ( & V_8 -> V_56 ) ;
F_177 ( & V_8 -> V_55 , & V_164 ) ;
if ( ! F_25 ( & V_8 -> V_55 ) )
V_2 -> V_125 = V_166 ;
F_54 ( & V_2 -> V_146 ) ;
if ( V_152 - V_66 )
V_64 = V_152 - V_66 ;
return V_64 ;
}
static T_3 F_178 ( struct V_7 * V_8 , struct V_160 * V_160 ,
const unsigned char * V_66 , T_1 V_67 )
{
const unsigned char * V_152 = V_66 ;
F_168 ( V_164 , V_165 ) ;
int V_42 ;
T_3 V_64 = 0 ;
if ( F_179 ( V_8 ) && V_160 -> V_161 -> V_62 != V_162 ) {
V_64 = F_180 ( V_8 ) ;
if ( V_64 )
return V_64 ;
}
F_87 ( & V_8 -> V_56 ) ;
F_59 ( V_8 ) ;
F_171 ( & V_8 -> V_38 , & V_164 ) ;
while ( 1 ) {
if ( F_175 ( V_131 ) ) {
V_64 = - V_171 ;
break;
}
if ( F_174 ( V_160 ) || ( V_8 -> V_32 && ! V_8 -> V_32 -> V_37 ) ) {
V_64 = - V_174 ;
break;
}
if ( F_57 ( V_8 ) ) {
while ( V_67 > 0 ) {
T_3 V_178 = F_55 ( V_8 , V_152 , V_67 ) ;
if ( V_178 < 0 ) {
if ( V_178 == - V_170 )
break;
V_64 = V_178 ;
goto V_69;
}
V_152 += V_178 ;
V_67 -= V_178 ;
if ( V_67 == 0 )
break;
V_42 = * V_152 ;
if ( F_51 ( V_42 , V_8 ) < 0 )
break;
V_152 ++ ; V_67 -- ;
}
if ( V_8 -> V_34 -> V_86 )
V_8 -> V_34 -> V_86 ( V_8 ) ;
} else {
struct V_1 * V_2 = V_8 -> V_11 ;
while ( V_67 > 0 ) {
F_52 ( & V_2 -> V_65 ) ;
V_42 = V_8 -> V_34 -> V_62 ( V_8 , V_152 , V_67 ) ;
F_54 ( & V_2 -> V_65 ) ;
if ( V_42 < 0 ) {
V_64 = V_42 ;
goto V_69;
}
if ( ! V_42 )
break;
V_152 += V_42 ;
V_67 -= V_42 ;
}
}
if ( ! V_67 )
break;
if ( V_160 -> V_168 & V_169 ) {
V_64 = - V_170 ;
break;
}
F_85 ( & V_8 -> V_56 ) ;
F_176 ( & V_164 , V_175 , V_172 ) ;
F_87 ( & V_8 -> V_56 ) ;
}
V_69:
F_177 ( & V_8 -> V_38 , & V_164 ) ;
if ( V_152 - V_66 != V_67 && V_8 -> V_23 )
F_120 ( V_24 , & V_8 -> V_20 ) ;
F_85 ( & V_8 -> V_56 ) ;
return ( V_152 - V_66 ) ? V_152 - V_66 : V_64 ;
}
static unsigned int F_181 ( struct V_7 * V_8 , struct V_160 * V_160 ,
T_4 * V_164 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned int V_179 = 0 ;
F_182 ( V_160 , & V_8 -> V_55 , V_164 ) ;
F_182 ( V_160 , & V_8 -> V_38 , V_164 ) ;
if ( F_158 ( V_8 ) )
V_179 |= V_180 ;
if ( F_155 ( V_8 , 1 ) )
V_179 |= V_111 | V_181 ;
if ( V_8 -> V_51 && V_8 -> V_32 -> V_53 )
V_179 |= V_182 | V_111 | V_181 ;
if ( F_174 ( V_160 ) )
V_179 |= V_180 ;
if ( ! ( V_179 & ( V_180 | V_111 | V_181 ) ) ) {
if ( F_157 ( V_8 ) && ! F_156 ( V_8 ) )
V_2 -> V_125 = F_157 ( V_8 ) ;
else
V_2 -> V_125 = 1 ;
}
if ( V_8 -> V_34 -> V_62 && ! F_183 ( V_8 ) &&
F_184 ( V_8 ) < V_183 &&
F_53 ( V_8 ) > 0 )
V_179 |= V_39 | V_184 ;
return V_179 ;
}
static unsigned long F_185 ( struct V_1 * V_2 )
{
T_1 V_67 , V_83 , V_71 ;
if ( V_2 -> V_22 == V_2 -> V_4 )
return 0 ;
V_83 = V_2 -> V_22 ;
V_71 = V_2 -> V_4 ;
V_67 = V_83 - V_71 ;
while ( V_83 != V_71 ) {
if ( F_14 ( V_71 & ( V_6 - 1 ) , V_2 -> V_49 ) &&
F_2 ( V_2 , V_71 ) == V_109 )
V_67 -- ;
V_71 ++ ;
}
return V_67 ;
}
static int F_186 ( struct V_7 * V_8 , struct V_160 * V_160 ,
unsigned int V_185 , unsigned long V_186 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_64 ;
switch ( V_185 ) {
case V_187 :
return F_8 ( F_184 ( V_8 ) , ( int T_2 * ) V_186 ) ;
case V_188 :
F_36 ( & V_8 -> V_56 ) ;
if ( F_147 ( V_8 ) )
V_64 = F_185 ( V_2 ) ;
else
V_64 = F_1 ( V_2 ) ;
F_37 ( & V_8 -> V_56 ) ;
return F_8 ( V_64 , ( unsigned int T_2 * ) V_186 ) ;
default:
return F_187 ( V_8 , V_160 , V_185 , V_186 ) ;
}
}
static void F_188 ( struct V_7 * V_8 , int V_189 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! F_25 ( & V_8 -> V_55 ) ) {
if ( V_189 )
V_2 -> V_125 = 1 ;
else if ( ! V_8 -> V_23 )
V_2 -> V_125 = V_6 ;
}
}
void F_189 ( struct V_190 * V_34 )
{
* V_34 = V_191 ;
V_34 -> V_192 = NULL ;
V_34 -> V_193 = V_34 -> V_20 = 0 ;
}

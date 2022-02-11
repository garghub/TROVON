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
static int F_9 ( struct V_7 * V_8 , void T_2 * V_13 ,
T_1 V_14 , T_1 V_15 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_16 = V_6 - V_14 ;
const void * V_17 = F_3 ( V_2 , V_14 ) ;
int V_18 ;
if ( V_15 > V_16 ) {
F_7 ( V_8 , V_17 , V_16 , V_2 -> V_12 ) ;
V_18 = F_10 ( V_13 , V_17 , V_16 ) ;
if ( V_18 )
return V_18 ;
V_13 += V_16 ;
V_15 -= V_16 ;
V_17 = V_2 -> F_2 ;
}
F_7 ( V_8 , V_17 , V_15 , V_2 -> V_12 ) ;
return F_10 ( V_13 , V_17 , V_15 ) ;
}
static void F_11 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_12 ( V_2 -> V_19 ) ) {
V_2 -> V_19 = 0 ;
F_13 ( V_8 -> V_20 -> V_21 == NULL ,
L_1 ) ;
F_13 ( F_14 ( V_22 , & V_8 -> V_23 ) ,
L_2 ) ;
F_15 ( V_8 -> V_20 ) ;
}
}
static T_3 F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_3 V_15 = 0 ;
if ( ! V_2 -> V_12 )
V_15 = V_2 -> V_24 - V_2 -> V_4 ;
else
V_15 = V_2 -> V_25 - V_2 -> V_4 ;
return V_15 ;
}
static void F_17 ( struct V_7 * V_8 )
{
if ( V_8 -> V_26 && F_18 ( V_27 , & V_8 -> V_23 ) )
F_19 ( & V_8 -> V_26 , V_28 , V_29 ) ;
}
static void F_20 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_2 -> V_12 && V_2 -> V_25 == V_2 -> V_4 )
return;
while ( 1 ) {
int V_30 ;
F_21 ( V_8 , V_31 ) ;
if ( V_6 - F_1 ( V_2 ) >= V_32 )
break;
V_30 = F_22 ( V_8 ) ;
if ( ! V_30 )
break;
}
F_23 ( V_8 , 0 ) ;
}
static void F_24 ( struct V_7 * V_8 )
{
if ( V_8 -> V_33 -> type == V_34 ) {
if ( F_16 ( V_8 ) > V_35 )
return;
if ( ! V_8 -> V_36 )
return;
F_11 ( V_8 ) ;
F_25 ( V_8 -> V_37 ) ;
return;
}
while ( 1 ) {
int V_38 ;
F_21 ( V_8 , V_39 ) ;
if ( F_16 ( V_8 ) > V_35 )
break;
if ( ! V_8 -> V_36 )
break;
F_11 ( V_8 ) ;
V_38 = F_26 ( V_8 ) ;
if ( ! V_38 )
break;
}
F_23 ( V_8 , 0 ) ;
}
static inline void F_27 ( unsigned char V_40 , struct V_1 * V_2 )
{
* F_3 ( V_2 , V_2 -> V_3 ) = V_40 ;
V_2 -> V_3 ++ ;
}
static void F_28 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_25 = V_2 -> V_4 = 0 ;
V_2 -> V_41 = V_2 -> V_42 = V_2 -> V_43 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_44 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0 ;
F_29 ( V_2 -> V_47 , V_6 ) ;
V_2 -> V_48 = 0 ;
}
static void F_30 ( struct V_7 * V_8 )
{
unsigned long V_23 ;
if ( V_8 -> V_37 -> V_49 ) {
F_31 ( & V_8 -> V_50 , V_23 ) ;
V_8 -> V_51 |= V_52 ;
F_32 ( & V_8 -> V_50 , V_23 ) ;
F_33 ( & V_8 -> V_37 -> V_53 ) ;
}
}
static void F_34 ( struct V_7 * V_8 )
{
F_35 ( & V_8 -> V_54 ) ;
F_28 ( V_8 -> V_11 ) ;
F_11 ( V_8 ) ;
if ( V_8 -> V_37 )
F_30 ( V_8 ) ;
F_36 ( & V_8 -> V_54 ) ;
}
static T_3 F_37 ( struct V_7 * V_8 )
{
T_3 V_15 ;
F_38 ( 1 , L_3 , V_55 ) ;
F_35 ( & V_8 -> V_54 ) ;
V_15 = F_16 ( V_8 ) ;
F_36 ( & V_8 -> V_54 ) ;
return V_15 ;
}
static inline int F_39 ( unsigned char V_40 )
{
return ( V_40 & 0xc0 ) == 0x80 ;
}
static inline int F_40 ( unsigned char V_40 , struct V_7 * V_8 )
{
return F_41 ( V_8 ) && F_39 ( V_40 ) ;
}
static int F_42 ( unsigned char V_40 , struct V_7 * V_8 , int V_56 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_57 ;
if ( ! V_56 )
return - 1 ;
switch ( V_40 ) {
case '\n' :
if ( F_43 ( V_8 ) )
V_2 -> V_58 = 0 ;
if ( F_44 ( V_8 ) ) {
if ( V_56 < 2 )
return - 1 ;
V_2 -> V_59 = V_2 -> V_58 = 0 ;
V_8 -> V_60 -> V_61 ( V_8 , L_4 , 2 ) ;
return 2 ;
}
V_2 -> V_59 = V_2 -> V_58 ;
break;
case '\r' :
if ( F_45 ( V_8 ) && V_2 -> V_58 == 0 )
return 0 ;
if ( F_46 ( V_8 ) ) {
V_40 = '\n' ;
if ( F_43 ( V_8 ) )
V_2 -> V_59 = V_2 -> V_58 = 0 ;
break;
}
V_2 -> V_59 = V_2 -> V_58 = 0 ;
break;
case '\t' :
V_57 = 8 - ( V_2 -> V_58 & 7 ) ;
if ( F_47 ( V_8 ) == V_62 ) {
if ( V_56 < V_57 )
return - 1 ;
V_2 -> V_58 += V_57 ;
V_8 -> V_60 -> V_61 ( V_8 , L_5 , V_57 ) ;
return V_57 ;
}
V_2 -> V_58 += V_57 ;
break;
case '\b' :
if ( V_2 -> V_58 > 0 )
V_2 -> V_58 -- ;
break;
default:
if ( ! iscntrl ( V_40 ) ) {
if ( F_48 ( V_8 ) )
V_40 = toupper ( V_40 ) ;
if ( ! F_40 ( V_40 , V_8 ) )
V_2 -> V_58 ++ ;
}
break;
}
F_49 ( V_8 , V_40 ) ;
return 1 ;
}
static int F_50 ( unsigned char V_40 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_56 , V_63 ;
F_51 ( & V_2 -> V_64 ) ;
V_56 = F_52 ( V_8 ) ;
V_63 = F_42 ( V_40 , V_8 , V_56 ) ;
F_53 ( & V_2 -> V_64 ) ;
if ( V_63 < 0 )
return - 1 ;
else
return 0 ;
}
static T_3 F_54 ( struct V_7 * V_8 ,
const unsigned char * V_65 , unsigned int V_66 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_56 ;
int V_5 ;
const unsigned char * V_67 ;
F_51 ( & V_2 -> V_64 ) ;
V_56 = F_52 ( V_8 ) ;
if ( ! V_56 ) {
F_53 ( & V_2 -> V_64 ) ;
return 0 ;
}
if ( V_66 > V_56 )
V_66 = V_56 ;
for ( V_5 = 0 , V_67 = V_65 ; V_5 < V_66 ; V_5 ++ , V_67 ++ ) {
unsigned char V_40 = * V_67 ;
switch ( V_40 ) {
case '\n' :
if ( F_43 ( V_8 ) )
V_2 -> V_58 = 0 ;
if ( F_44 ( V_8 ) )
goto V_68;
V_2 -> V_59 = V_2 -> V_58 ;
break;
case '\r' :
if ( F_45 ( V_8 ) && V_2 -> V_58 == 0 )
goto V_68;
if ( F_46 ( V_8 ) )
goto V_68;
V_2 -> V_59 = V_2 -> V_58 = 0 ;
break;
case '\t' :
goto V_68;
case '\b' :
if ( V_2 -> V_58 > 0 )
V_2 -> V_58 -- ;
break;
default:
if ( ! iscntrl ( V_40 ) ) {
if ( F_48 ( V_8 ) )
goto V_68;
if ( ! F_40 ( V_40 , V_8 ) )
V_2 -> V_58 ++ ;
}
break;
}
}
V_68:
V_5 = V_8 -> V_60 -> V_61 ( V_8 , V_65 , V_5 ) ;
F_53 ( & V_2 -> V_64 ) ;
return V_5 ;
}
static T_1 F_55 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_56 , V_69 ;
T_1 V_14 ;
unsigned char V_40 ;
V_69 = V_56 = F_52 ( V_8 ) ;
V_14 = V_2 -> V_42 ;
while ( V_2 -> V_43 != V_14 ) {
V_40 = F_4 ( V_2 , V_14 ) ;
if ( V_40 == V_70 ) {
unsigned char V_71 ;
int V_72 = 0 ;
V_71 = F_4 ( V_2 , V_14 + 1 ) ;
switch ( V_71 ) {
unsigned int V_73 , V_74 ;
case V_75 :
V_73 = F_4 ( V_2 , V_14 + 2 ) ;
if ( ! ( V_73 & 0x80 ) )
V_73 += V_2 -> V_59 ;
V_74 = 8 - ( V_73 & 7 ) ;
if ( V_74 > V_56 ) {
V_72 = 1 ;
break;
}
V_56 -= V_74 ;
while ( V_74 -- ) {
F_49 ( V_8 , '\b' ) ;
if ( V_2 -> V_58 > 0 )
V_2 -> V_58 -- ;
}
V_14 += 3 ;
break;
case V_76 :
V_2 -> V_59 = V_2 -> V_58 ;
V_14 += 2 ;
break;
case V_77 :
if ( V_2 -> V_58 > 0 )
V_2 -> V_58 -- ;
V_14 += 2 ;
break;
case V_70 :
if ( ! V_56 ) {
V_72 = 1 ;
break;
}
F_49 ( V_8 , V_70 ) ;
V_2 -> V_58 ++ ;
V_56 -- ;
V_14 += 2 ;
break;
default:
if ( V_56 < 2 ) {
V_72 = 1 ;
break;
}
F_49 ( V_8 , '^' ) ;
F_49 ( V_8 , V_71 ^ 0100 ) ;
V_2 -> V_58 += 2 ;
V_56 -= 2 ;
V_14 += 2 ;
}
if ( V_72 )
break;
} else {
if ( F_56 ( V_8 ) ) {
int V_63 = F_42 ( V_40 , V_8 , V_56 ) ;
if ( V_63 < 0 )
break;
V_56 -= V_63 ;
} else {
if ( ! V_56 )
break;
F_49 ( V_8 , V_40 ) ;
V_56 -= 1 ;
}
V_14 += 1 ;
}
}
while ( V_2 -> V_43 - V_14 >= V_78 ) {
if ( F_4 ( V_2 , V_14 ) == V_70 ) {
if ( F_4 ( V_2 , V_14 + 1 ) == V_75 )
V_14 += 3 ;
else
V_14 += 2 ;
} else
V_14 ++ ;
}
V_2 -> V_42 = V_14 ;
return V_69 - V_56 ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_66 , V_79 , V_80 ;
T_1 V_81 ;
V_81 = V_2 -> V_41 ;
V_2 -> V_44 = V_81 ;
V_79 = V_2 -> V_43 - V_2 -> V_42 ;
V_66 = V_81 - V_2 -> V_42 ;
if ( V_66 < V_82 || ( V_66 % V_83 > V_79 % V_83 ) )
return;
F_51 ( & V_2 -> V_64 ) ;
V_2 -> V_43 = V_81 ;
V_80 = F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_64 ) ;
if ( V_80 && V_8 -> V_60 -> V_84 )
V_8 -> V_60 -> V_84 ( V_8 ) ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_80 ;
if ( V_2 -> V_44 == V_2 -> V_42 )
return;
F_51 ( & V_2 -> V_64 ) ;
V_2 -> V_43 = V_2 -> V_44 ;
V_80 = F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_64 ) ;
if ( V_80 && V_8 -> V_60 -> V_84 )
V_8 -> V_60 -> V_84 ( V_8 ) ;
}
static void F_59 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ( ! F_60 ( V_8 ) && ! F_61 ( V_8 ) ) ||
V_2 -> V_43 == V_2 -> V_41 )
return;
F_51 ( & V_2 -> V_64 ) ;
V_2 -> V_43 = V_2 -> V_41 ;
F_55 ( V_8 ) ;
F_53 ( & V_2 -> V_64 ) ;
}
static inline void F_62 ( unsigned char V_40 , struct V_1 * V_2 )
{
* F_5 ( V_2 , V_2 -> V_41 ++ ) = V_40 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_62 ( V_70 , V_2 ) ;
F_62 ( V_77 , V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_62 ( V_70 , V_2 ) ;
F_62 ( V_76 , V_2 ) ;
}
static void F_65 ( unsigned int V_73 , int V_85 ,
struct V_1 * V_2 )
{
F_62 ( V_70 , V_2 ) ;
F_62 ( V_75 , V_2 ) ;
V_73 &= 7 ;
if ( V_85 )
V_73 |= 0x80 ;
F_62 ( V_73 , V_2 ) ;
}
static void F_66 ( unsigned char V_40 , struct V_1 * V_2 )
{
if ( V_40 == V_70 ) {
F_62 ( V_70 , V_2 ) ;
F_62 ( V_70 , V_2 ) ;
} else {
F_62 ( V_40 , V_2 ) ;
}
}
static void F_67 ( unsigned char V_40 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_40 == V_70 ) {
F_62 ( V_70 , V_2 ) ;
F_62 ( V_70 , V_2 ) ;
} else {
if ( F_68 ( V_8 ) && iscntrl ( V_40 ) && V_40 != '\t' )
F_62 ( V_70 , V_2 ) ;
F_62 ( V_40 , V_2 ) ;
}
}
static inline void F_69 ( struct V_1 * V_2 )
{
if ( V_2 -> V_46 ) {
F_66 ( '/' , V_2 ) ;
V_2 -> V_46 = 0 ;
}
}
static void F_70 ( unsigned char V_40 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
enum { V_86 , V_87 , V_88 } V_89 ;
T_1 V_81 ;
T_1 V_90 ;
int V_91 ;
if ( V_2 -> V_3 == V_2 -> V_25 ) {
return;
}
if ( V_40 == F_71 ( V_8 ) )
V_89 = V_86 ;
else if ( V_40 == F_72 ( V_8 ) )
V_89 = V_87 ;
else {
if ( ! F_60 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_25 ;
return;
}
if ( ! F_73 ( V_8 ) || ! F_74 ( V_8 ) || ! F_75 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_25 ;
F_69 ( V_2 ) ;
F_67 ( F_76 ( V_8 ) , V_8 ) ;
if ( F_73 ( V_8 ) )
F_66 ( '\n' , V_2 ) ;
return;
}
V_89 = V_88 ;
}
V_91 = 0 ;
while ( V_2 -> V_3 != V_2 -> V_25 ) {
V_81 = V_2 -> V_3 ;
do {
V_81 -- ;
V_40 = F_2 ( V_2 , V_81 ) ;
} while ( F_40 ( V_40 , V_8 ) && V_81 != V_2 -> V_25 );
if ( F_40 ( V_40 , V_8 ) )
break;
if ( V_89 == V_87 ) {
if ( isalnum ( V_40 ) || V_40 == '_' )
V_91 ++ ;
else if ( V_91 )
break;
}
V_90 = V_2 -> V_3 - V_81 ;
V_2 -> V_3 = V_81 ;
if ( F_60 ( V_8 ) ) {
if ( F_77 ( V_8 ) ) {
if ( ! V_2 -> V_46 ) {
F_66 ( '\\' , V_2 ) ;
V_2 -> V_46 = 1 ;
}
F_67 ( V_40 , V_8 ) ;
while ( -- V_90 > 0 ) {
V_81 ++ ;
F_66 ( F_2 ( V_2 , V_81 ) , V_2 ) ;
F_63 ( V_2 ) ;
}
} else if ( V_89 == V_86 && ! F_75 ( V_8 ) ) {
F_67 ( F_71 ( V_8 ) , V_8 ) ;
} else if ( V_40 == '\t' ) {
unsigned int V_73 = 0 ;
int V_85 = 0 ;
T_1 V_14 = V_2 -> V_3 ;
while ( V_14 != V_2 -> V_25 ) {
V_14 -- ;
V_40 = F_2 ( V_2 , V_14 ) ;
if ( V_40 == '\t' ) {
V_85 = 1 ;
break;
} else if ( iscntrl ( V_40 ) ) {
if ( F_68 ( V_8 ) )
V_73 += 2 ;
} else if ( ! F_40 ( V_40 , V_8 ) ) {
V_73 ++ ;
}
}
F_65 ( V_73 , V_85 , V_2 ) ;
} else {
if ( iscntrl ( V_40 ) && F_68 ( V_8 ) ) {
F_66 ( '\b' , V_2 ) ;
F_66 ( ' ' , V_2 ) ;
F_66 ( '\b' , V_2 ) ;
}
if ( ! iscntrl ( V_40 ) || F_68 ( V_8 ) ) {
F_66 ( '\b' , V_2 ) ;
F_66 ( ' ' , V_2 ) ;
F_66 ( '\b' , V_2 ) ;
}
}
}
if ( V_89 == V_86 )
break;
}
if ( V_2 -> V_3 == V_2 -> V_25 && F_60 ( V_8 ) )
F_69 ( V_2 ) ;
}
static void F_78 ( int V_92 , struct V_7 * V_8 )
{
struct V_93 * V_94 = F_79 ( V_8 ) ;
if ( V_94 ) {
F_80 ( V_94 , V_92 , 1 ) ;
F_81 ( V_94 ) ;
}
}
static void F_82 ( int V_92 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_83 ( V_8 ) ) {
F_78 ( V_92 , V_8 ) ;
} else {
F_84 ( & V_8 -> V_54 ) ;
F_35 ( & V_8 -> V_54 ) ;
F_78 ( V_92 , V_8 ) ;
F_51 ( & V_2 -> V_64 ) ;
V_2 -> V_41 = V_2 -> V_42 = 0 ;
V_2 -> V_44 = V_2 -> V_43 = 0 ;
F_53 ( & V_2 -> V_64 ) ;
F_85 ( V_8 ) ;
F_28 ( V_8 -> V_11 ) ;
if ( V_8 -> V_37 )
F_30 ( V_8 ) ;
F_36 ( & V_8 -> V_54 ) ;
F_86 ( & V_8 -> V_54 ) ;
}
}
static void F_87 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_88 ( V_8 ) )
return;
if ( F_89 ( V_8 ) ) {
F_82 ( V_95 , V_8 ) ;
return;
}
if ( F_90 ( V_8 ) ) {
F_27 ( '\377' , V_2 ) ;
F_27 ( '\0' , V_2 ) ;
}
F_27 ( '\0' , V_2 ) ;
}
static void F_91 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_96 ++ ;
if ( F_92 ( V_97 , V_2 -> V_98 + V_99 ) ||
F_92 ( V_2 -> V_98 , V_97 ) ) {
F_93 ( V_8 , L_6 , V_2 -> V_96 ) ;
V_2 -> V_98 = V_97 ;
V_2 -> V_96 = 0 ;
}
}
static void F_94 ( struct V_7 * V_8 , unsigned char V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_95 ( V_8 ) ) {
if ( F_96 ( V_8 ) )
return;
if ( F_90 ( V_8 ) ) {
F_27 ( '\377' , V_2 ) ;
F_27 ( '\0' , V_2 ) ;
F_27 ( V_40 , V_2 ) ;
} else
F_27 ( '\0' , V_2 ) ;
} else
F_27 ( V_40 , V_2 ) ;
}
static void
F_97 ( struct V_7 * V_8 , int signal , unsigned char V_40 )
{
F_82 ( signal , V_8 ) ;
if ( F_98 ( V_8 ) )
F_99 ( V_8 ) ;
if ( F_60 ( V_8 ) ) {
F_67 ( V_40 , V_8 ) ;
F_57 ( V_8 ) ;
} else
F_58 ( V_8 ) ;
return;
}
static int
F_100 ( struct V_7 * V_8 , unsigned char V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_98 ( V_8 ) ) {
if ( V_40 == F_101 ( V_8 ) ) {
F_99 ( V_8 ) ;
F_58 ( V_8 ) ;
return 0 ;
}
if ( V_40 == F_102 ( V_8 ) ) {
F_103 ( V_8 ) ;
return 0 ;
}
}
if ( F_104 ( V_8 ) ) {
if ( V_40 == F_105 ( V_8 ) ) {
F_97 ( V_8 , V_95 , V_40 ) ;
return 0 ;
} else if ( V_40 == F_106 ( V_8 ) ) {
F_97 ( V_8 , V_100 , V_40 ) ;
return 0 ;
} else if ( V_40 == F_107 ( V_8 ) ) {
F_97 ( V_8 , V_101 , V_40 ) ;
return 0 ;
}
}
if ( V_8 -> V_102 && ! V_8 -> V_103 && F_98 ( V_8 ) && F_108 ( V_8 ) ) {
F_99 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_40 == '\r' ) {
if ( F_109 ( V_8 ) )
return 0 ;
if ( F_110 ( V_8 ) )
V_40 = '\n' ;
} else if ( V_40 == '\n' && F_111 ( V_8 ) )
V_40 = '\r' ;
if ( V_2 -> V_12 ) {
if ( V_40 == F_71 ( V_8 ) || V_40 == F_76 ( V_8 ) ||
( V_40 == F_72 ( V_8 ) && F_112 ( V_8 ) ) ) {
F_70 ( V_40 , V_8 ) ;
F_57 ( V_8 ) ;
return 0 ;
}
if ( V_40 == F_113 ( V_8 ) && F_112 ( V_8 ) ) {
V_2 -> V_104 = 1 ;
if ( F_60 ( V_8 ) ) {
F_69 ( V_2 ) ;
if ( F_68 ( V_8 ) ) {
F_66 ( '^' , V_2 ) ;
F_66 ( '\b' , V_2 ) ;
F_57 ( V_8 ) ;
}
}
return 1 ;
}
if ( V_40 == F_114 ( V_8 ) && F_60 ( V_8 ) && F_112 ( V_8 ) ) {
T_1 V_14 = V_2 -> V_25 ;
F_69 ( V_2 ) ;
F_67 ( V_40 , V_8 ) ;
F_66 ( '\n' , V_2 ) ;
while ( V_14 != V_2 -> V_3 ) {
F_67 ( F_2 ( V_2 , V_14 ) , V_8 ) ;
V_14 ++ ;
}
F_57 ( V_8 ) ;
return 0 ;
}
if ( V_40 == '\n' ) {
if ( F_60 ( V_8 ) || F_61 ( V_8 ) ) {
F_66 ( '\n' , V_2 ) ;
F_57 ( V_8 ) ;
}
goto V_105;
}
if ( V_40 == F_115 ( V_8 ) ) {
V_40 = V_106 ;
goto V_105;
}
if ( ( V_40 == F_116 ( V_8 ) ) ||
( V_40 == F_117 ( V_8 ) && F_112 ( V_8 ) ) ) {
if ( F_60 ( V_8 ) ) {
if ( V_2 -> V_25 == V_2 -> V_3 )
F_64 ( V_2 ) ;
F_67 ( V_40 , V_8 ) ;
F_57 ( V_8 ) ;
}
if ( V_40 == ( unsigned char ) '\377' && F_90 ( V_8 ) )
F_27 ( V_40 , V_2 ) ;
V_105:
F_118 ( V_2 -> V_3 & ( V_6 - 1 ) , V_2 -> V_47 ) ;
F_27 ( V_40 , V_2 ) ;
F_119 ( & V_2 -> V_25 , V_2 -> V_3 ) ;
F_19 ( & V_8 -> V_26 , V_28 , V_107 ) ;
F_120 ( & V_8 -> V_53 , V_108 ) ;
return 0 ;
}
}
if ( F_60 ( V_8 ) ) {
F_69 ( V_2 ) ;
if ( V_40 == '\n' )
F_66 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_25 == V_2 -> V_3 )
F_64 ( V_2 ) ;
F_67 ( V_40 , V_8 ) ;
}
F_57 ( V_8 ) ;
}
if ( V_40 == ( unsigned char ) '\377' && F_90 ( V_8 ) )
F_27 ( V_40 , V_2 ) ;
F_27 ( V_40 , V_2 ) ;
return 0 ;
}
static inline void
F_121 ( struct V_7 * V_8 , unsigned char V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_102 && ! V_8 -> V_103 && F_98 ( V_8 ) && F_108 ( V_8 ) ) {
F_99 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( F_60 ( V_8 ) ) {
F_69 ( V_2 ) ;
if ( V_2 -> V_25 == V_2 -> V_3 )
F_64 ( V_2 ) ;
F_67 ( V_40 , V_8 ) ;
F_57 ( V_8 ) ;
}
if ( V_40 == ( unsigned char ) '\377' && F_90 ( V_8 ) )
F_27 ( V_40 , V_2 ) ;
F_27 ( V_40 , V_2 ) ;
}
static void F_122 ( struct V_7 * V_8 , unsigned char V_40 )
{
F_121 ( V_8 , V_40 ) ;
}
static inline void
F_123 ( struct V_7 * V_8 , unsigned char V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_102 && ! V_8 -> V_103 && F_98 ( V_8 ) && F_108 ( V_8 ) ) {
F_99 ( V_8 ) ;
F_58 ( V_8 ) ;
}
if ( F_60 ( V_8 ) ) {
F_69 ( V_2 ) ;
if ( V_2 -> V_25 == V_2 -> V_3 )
F_64 ( V_2 ) ;
F_67 ( V_40 , V_8 ) ;
F_57 ( V_8 ) ;
}
F_27 ( V_40 , V_2 ) ;
}
static void F_124 ( struct V_7 * V_8 , unsigned char V_40 )
{
if ( F_125 ( V_8 ) )
V_40 &= 0x7f ;
if ( F_126 ( V_8 ) && F_112 ( V_8 ) )
V_40 = tolower ( V_40 ) ;
if ( F_98 ( V_8 ) ) {
if ( V_40 == F_102 ( V_8 ) )
F_103 ( V_8 ) ;
else if ( V_40 == F_101 ( V_8 ) ||
( V_8 -> V_102 && ! V_8 -> V_103 && F_108 ( V_8 ) &&
V_40 != F_105 ( V_8 ) && V_40 != F_106 ( V_8 ) &&
V_40 != F_107 ( V_8 ) ) ) {
F_99 ( V_8 ) ;
F_58 ( V_8 ) ;
}
}
}
static void
F_127 ( struct V_7 * V_8 , unsigned char V_40 , char V_109 )
{
switch ( V_109 ) {
case V_110 :
F_87 ( V_8 ) ;
break;
case V_111 :
case V_112 :
F_94 ( V_8 , V_40 ) ;
break;
case V_113 :
F_91 ( V_8 ) ;
break;
default:
F_128 ( V_8 , L_7 , V_109 ) ;
break;
}
}
static void
F_129 ( struct V_7 * V_8 , unsigned char V_40 , char V_109 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_104 = 0 ;
if ( F_130 ( V_109 == V_114 ) ) {
if ( F_125 ( V_8 ) )
V_40 &= 0x7f ;
if ( F_126 ( V_8 ) && F_112 ( V_8 ) )
V_40 = tolower ( V_40 ) ;
F_122 ( V_8 , V_40 ) ;
} else
F_127 ( V_8 , V_40 , V_109 ) ;
}
static void
F_131 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_15 , V_81 ;
V_81 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_15 = F_132 ( T_1 , V_36 , V_6 - V_81 ) ;
memcpy ( F_3 ( V_2 , V_81 ) , V_67 , V_15 ) ;
V_2 -> V_3 += V_15 ;
V_67 += V_15 ;
V_36 -= V_15 ;
V_81 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_15 = F_132 ( T_1 , V_36 , V_6 - V_81 ) ;
memcpy ( F_3 ( V_2 , V_81 ) , V_67 , V_15 ) ;
V_2 -> V_3 += V_15 ;
}
static void
F_133 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_109 = V_114 ;
while ( V_36 -- ) {
if ( V_115 )
V_109 = * V_115 ++ ;
if ( F_130 ( V_109 == V_114 ) )
F_27 ( * V_67 ++ , V_2 ) ;
else
F_127 ( V_8 , * V_67 ++ , V_109 ) ;
}
}
static void
F_134 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 )
{
char V_109 = V_114 ;
while ( V_36 -- ) {
if ( V_115 )
V_109 = * V_115 ++ ;
if ( F_130 ( V_109 == V_114 ) )
F_124 ( V_8 , * V_67 ++ ) ;
else
F_127 ( V_8 , * V_67 ++ , V_109 ) ;
}
}
static void
F_135 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_109 = V_114 ;
while ( V_36 -- ) {
if ( V_115 )
V_109 = * V_115 ++ ;
if ( F_130 ( V_109 == V_114 ) ) {
unsigned char V_40 = * V_67 ++ ;
if ( F_125 ( V_8 ) )
V_40 &= 0x7f ;
if ( F_126 ( V_8 ) && F_112 ( V_8 ) )
V_40 = tolower ( V_40 ) ;
if ( F_136 ( V_8 ) ) {
F_27 ( V_40 , V_2 ) ;
continue;
}
if ( ! F_14 ( V_40 , V_2 -> V_116 ) )
F_121 ( V_8 , V_40 ) ;
else if ( F_100 ( V_8 , V_40 ) && V_36 ) {
if ( V_115 )
V_109 = * V_115 ++ ;
F_129 ( V_8 , * V_67 ++ , V_109 ) ;
V_36 -- ;
}
} else
F_127 ( V_8 , * V_67 ++ , V_109 ) ;
}
}
static void
F_137 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_109 = V_114 ;
while ( V_36 -- ) {
if ( V_115 )
V_109 = * V_115 ++ ;
if ( F_130 ( V_109 == V_114 ) ) {
unsigned char V_40 = * V_67 ++ ;
if ( ! F_14 ( V_40 , V_2 -> V_116 ) )
F_123 ( V_8 , V_40 ) ;
else if ( F_100 ( V_8 , V_40 ) && V_36 ) {
if ( V_115 )
V_109 = * V_115 ++ ;
F_129 ( V_8 , * V_67 ++ , V_109 ) ;
V_36 -- ;
}
} else
F_127 ( V_8 , * V_67 ++ , V_109 ) ;
}
}
static void F_138 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
bool V_117 = F_125 ( V_8 ) || ( F_126 ( V_8 ) && F_112 ( V_8 ) ) ;
if ( V_2 -> V_118 )
F_131 ( V_8 , V_67 , V_115 , V_36 ) ;
else if ( V_2 -> V_119 || ( F_136 ( V_8 ) && ! V_117 ) )
F_133 ( V_8 , V_67 , V_115 , V_36 ) ;
else if ( V_8 -> V_120 && ! F_136 ( V_8 ) )
F_134 ( V_8 , V_67 , V_115 , V_36 ) ;
else {
if ( V_2 -> V_104 ) {
char V_109 = V_114 ;
if ( V_115 )
V_109 = * V_115 ++ ;
F_129 ( V_8 , * V_67 ++ , V_109 ) ;
V_36 -- ;
}
if ( ! V_117 && ! F_90 ( V_8 ) )
F_137 ( V_8 , V_67 , V_115 , V_36 ) ;
else
F_135 ( V_8 , V_67 , V_115 , V_36 ) ;
F_59 ( V_8 ) ;
if ( V_8 -> V_60 -> V_84 )
V_8 -> V_60 -> V_84 ( V_8 ) ;
}
if ( V_2 -> V_12 && ! F_136 ( V_8 ) )
return;
F_119 ( & V_2 -> V_24 , V_2 -> V_3 ) ;
if ( ( F_1 ( V_2 ) >= V_2 -> V_121 ) || F_136 ( V_8 ) ) {
F_19 ( & V_8 -> V_26 , V_28 , V_107 ) ;
F_120 ( & V_8 -> V_53 , V_108 ) ;
}
}
static int
F_139 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 , int V_122 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_123 , V_15 , V_124 = 0 , V_125 ;
F_86 ( & V_8 -> V_54 ) ;
while ( 1 ) {
T_1 V_14 = F_140 ( & V_2 -> V_4 ) ;
V_123 = V_6 - ( V_2 -> V_3 - V_14 ) ;
if ( F_90 ( V_8 ) )
V_123 = ( V_123 + 2 ) / 3 ;
V_123 -- ;
if ( V_123 <= 0 ) {
V_125 = V_2 -> V_12 && V_2 -> V_25 == V_14 ;
if ( V_125 && V_123 < 0 )
V_2 -> V_3 -- ;
V_123 = V_125 ;
V_2 -> V_19 = V_122 && ! V_123 ;
} else
V_125 = 0 ;
V_15 = F_141 ( V_36 , V_123 ) ;
if ( ! V_15 )
break;
if ( ! V_125 || ! V_115 || * V_115 != V_111 )
F_138 ( V_8 , V_67 , V_115 , V_15 ) ;
V_67 += V_15 ;
if ( V_115 )
V_115 += V_15 ;
V_36 -= V_15 ;
V_124 += V_15 ;
}
V_8 -> V_126 = V_123 ;
if ( V_8 -> V_33 -> type == V_34 ) {
if ( V_125 ) {
F_21 ( V_8 , V_39 ) ;
F_26 ( V_8 ) ;
F_23 ( V_8 , 0 ) ;
}
} else
F_20 ( V_8 ) ;
F_84 ( & V_8 -> V_54 ) ;
return V_124 ;
}
static void F_142 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 )
{
F_139 ( V_8 , V_67 , V_115 , V_36 , 0 ) ;
}
static int F_143 ( struct V_7 * V_8 , const unsigned char * V_67 ,
char * V_115 , int V_36 )
{
return F_139 ( V_8 , V_67 , V_115 , V_36 , 1 ) ;
}
int F_144 ( int V_92 )
{
return ( F_145 ( & V_127 -> V_128 , V_92 ) ||
V_127 -> V_129 -> V_130 [ V_92 - 1 ] . V_131 . V_132 == V_133 ) ;
}
static void F_146 ( struct V_7 * V_8 , struct V_134 * V_79 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! V_79 || ( V_79 -> V_135 ^ V_8 -> V_136 . V_135 ) & V_137 ) {
F_29 ( V_2 -> V_47 , V_6 ) ;
V_2 -> V_45 = V_2 -> V_4 ;
if ( ! F_147 ( V_8 ) || ! F_1 ( V_2 ) ) {
V_2 -> V_25 = V_2 -> V_4 ;
V_2 -> V_48 = 0 ;
} else {
F_118 ( ( V_2 -> V_3 - 1 ) & ( V_6 - 1 ) ,
V_2 -> V_47 ) ;
V_2 -> V_25 = V_2 -> V_3 ;
V_2 -> V_48 = 1 ;
}
V_2 -> V_24 = V_2 -> V_3 ;
V_2 -> V_46 = 0 ;
V_2 -> V_104 = 0 ;
}
V_2 -> V_12 = ( F_147 ( V_8 ) != 0 ) ;
if ( F_125 ( V_8 ) || F_126 ( V_8 ) || F_109 ( V_8 ) ||
F_110 ( V_8 ) || F_111 ( V_8 ) || F_147 ( V_8 ) ||
F_98 ( V_8 ) || F_104 ( V_8 ) || F_60 ( V_8 ) ||
F_90 ( V_8 ) ) {
F_29 ( V_2 -> V_116 , 256 ) ;
if ( F_109 ( V_8 ) || F_110 ( V_8 ) )
F_118 ( '\r' , V_2 -> V_116 ) ;
if ( F_111 ( V_8 ) )
F_118 ( '\n' , V_2 -> V_116 ) ;
if ( F_147 ( V_8 ) ) {
F_118 ( F_71 ( V_8 ) , V_2 -> V_116 ) ;
F_118 ( F_76 ( V_8 ) , V_2 -> V_116 ) ;
F_118 ( F_115 ( V_8 ) , V_2 -> V_116 ) ;
F_118 ( '\n' , V_2 -> V_116 ) ;
F_118 ( F_116 ( V_8 ) , V_2 -> V_116 ) ;
if ( F_112 ( V_8 ) ) {
F_118 ( F_72 ( V_8 ) , V_2 -> V_116 ) ;
F_118 ( F_113 ( V_8 ) , V_2 -> V_116 ) ;
F_118 ( F_117 ( V_8 ) , V_2 -> V_116 ) ;
if ( F_60 ( V_8 ) )
F_118 ( F_114 ( V_8 ) ,
V_2 -> V_116 ) ;
}
}
if ( F_98 ( V_8 ) ) {
F_118 ( F_101 ( V_8 ) , V_2 -> V_116 ) ;
F_118 ( F_102 ( V_8 ) , V_2 -> V_116 ) ;
}
if ( F_104 ( V_8 ) ) {
F_118 ( F_105 ( V_8 ) , V_2 -> V_116 ) ;
F_118 ( F_106 ( V_8 ) , V_2 -> V_116 ) ;
F_118 ( F_107 ( V_8 ) , V_2 -> V_116 ) ;
}
F_148 ( V_106 , V_2 -> V_116 ) ;
V_2 -> V_119 = 0 ;
V_2 -> V_118 = 0 ;
} else {
V_2 -> V_119 = 1 ;
if ( ( F_88 ( V_8 ) || ( ! F_89 ( V_8 ) && ! F_90 ( V_8 ) ) ) &&
( F_96 ( V_8 ) || ! F_95 ( V_8 ) ) &&
( V_8 -> V_33 -> V_23 & V_138 ) )
V_2 -> V_118 = 1 ;
else
V_2 -> V_118 = 0 ;
}
if ( ! F_98 ( V_8 ) && V_79 && ( V_79 -> V_139 & V_140 ) && ! V_8 -> V_103 ) {
F_99 ( V_8 ) ;
F_58 ( V_8 ) ;
}
F_33 ( & V_8 -> V_141 ) ;
F_33 ( & V_8 -> V_53 ) ;
}
static void F_149 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_37 )
F_30 ( V_8 ) ;
F_150 ( V_2 ) ;
V_8 -> V_11 = NULL ;
}
static int F_151 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_152 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_142;
V_2 -> V_98 = V_97 ;
F_153 ( & V_2 -> V_143 ) ;
F_153 ( & V_2 -> V_64 ) ;
V_8 -> V_11 = V_2 ;
F_28 ( V_8 -> V_11 ) ;
V_2 -> V_58 = 0 ;
V_2 -> V_59 = 0 ;
V_2 -> V_121 = 1 ;
V_2 -> V_96 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_104 = 0 ;
V_8 -> V_120 = 0 ;
F_148 ( V_22 , & V_8 -> V_23 ) ;
F_146 ( V_8 , NULL ) ;
F_154 ( V_8 ) ;
return 0 ;
V_142:
return - V_144 ;
}
static inline int F_155 ( struct V_7 * V_8 , int V_145 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_146 = V_145 && ! F_156 ( V_8 ) && F_157 ( V_8 ) ? F_157 ( V_8 ) : 1 ;
if ( V_2 -> V_12 && ! F_136 ( V_8 ) )
return V_2 -> V_25 != V_2 -> V_4 ;
else
return V_2 -> V_24 - V_2 -> V_4 >= V_146 ;
}
static inline int F_158 ( struct V_7 * V_8 )
{
int V_147 = F_14 ( V_148 , & V_8 -> V_23 ) ;
if ( V_147 ) {
F_159 () ;
}
return V_147 ;
}
static int F_160 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_149 ,
T_1 * V_66 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_63 ;
T_1 V_15 ;
bool V_150 ;
T_1 V_81 = F_140 ( & V_2 -> V_24 ) ;
T_1 V_14 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_63 = 0 ;
V_15 = F_141 ( V_81 - V_2 -> V_4 , V_6 - V_14 ) ;
V_15 = F_141 ( * V_66 , V_15 ) ;
if ( V_15 ) {
const unsigned char * V_17 = F_3 ( V_2 , V_14 ) ;
V_63 = F_10 ( * V_149 , V_17 , V_15 ) ;
V_15 -= V_63 ;
V_150 = V_15 == 1 && * V_17 == F_115 ( V_8 ) ;
F_7 ( V_8 , V_17 , V_15 , V_2 -> V_12 ) ;
F_119 ( & V_2 -> V_4 , V_2 -> V_4 + V_15 ) ;
if ( F_136 ( V_8 ) && V_2 -> V_12 && V_150 &&
( V_81 == V_2 -> V_4 ) )
V_15 = 0 ;
* V_149 += V_15 ;
* V_66 -= V_15 ;
}
return V_63 ;
}
static int F_161 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_149 ,
T_1 * V_66 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_15 , V_16 , V_151 , V_40 ;
T_1 V_152 ;
T_1 V_14 ;
int V_153 , V_154 = 0 ;
if ( ! * V_66 )
return 0 ;
V_15 = F_141 ( * V_66 + 1 , F_140 ( & V_2 -> V_25 ) - V_2 -> V_4 ) ;
V_14 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_16 = F_132 ( T_1 , V_14 + V_15 , V_6 ) ;
F_162 ( L_8 ,
V_55 , * V_66 , V_14 , V_15 , V_16 ) ;
V_152 = F_163 ( V_2 -> V_47 , V_16 , V_14 ) ;
V_151 = V_15 - ( V_16 - V_14 ) ;
if ( V_152 == V_6 && V_151 ) {
V_152 = F_163 ( V_2 -> V_47 , V_151 , 0 ) ;
V_154 = V_152 != V_151 ;
} else
V_154 = V_152 != V_16 ;
V_15 = V_152 - V_14 ;
if ( V_15 > V_6 )
V_15 += V_6 ;
V_40 = V_15 + V_154 ;
if ( ! V_154 || F_2 ( V_2 , V_152 ) != V_106 ) {
V_40 = F_141 ( * V_66 , V_40 ) ;
V_15 = V_40 ;
}
F_162 ( L_9 ,
V_55 , V_152 , V_154 , V_15 , V_40 , V_14 , V_151 ) ;
V_153 = F_9 ( V_8 , * V_149 , V_14 , V_15 ) ;
if ( V_153 )
return - V_155 ;
* V_149 += V_15 ;
* V_66 -= V_15 ;
if ( V_154 )
F_148 ( V_152 , V_2 -> V_47 ) ;
F_119 ( & V_2 -> V_4 , V_2 -> V_4 + V_40 ) ;
if ( V_154 ) {
if ( ! V_2 -> V_48 )
V_2 -> V_45 = V_2 -> V_4 ;
else
V_2 -> V_48 = 0 ;
F_164 ( V_8 ) ;
}
return 0 ;
}
static int F_165 ( struct V_7 * V_8 , struct V_156 * V_156 )
{
if ( V_156 -> V_157 -> V_61 == V_158 )
return 0 ;
return F_166 ( V_8 , V_159 ) ;
}
static T_3 F_167 ( struct V_7 * V_8 , struct V_156 * V_156 ,
unsigned char T_2 * V_65 , T_1 V_66 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned char T_2 * V_149 = V_65 ;
F_168 ( V_160 , V_161 ) ;
int V_40 , V_147 ;
int V_162 , time ;
T_3 V_63 = 0 ;
long V_163 ;
int V_49 ;
T_1 V_14 ;
V_40 = F_165 ( V_8 , V_156 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_156 -> V_164 & V_165 ) {
if ( ! F_169 ( & V_2 -> V_143 ) )
return - V_166 ;
} else {
if ( F_170 ( & V_2 -> V_143 ) )
return - V_167 ;
}
F_86 ( & V_8 -> V_54 ) ;
V_162 = time = 0 ;
V_163 = V_168 ;
if ( ! V_2 -> V_12 ) {
V_162 = F_157 ( V_8 ) ;
if ( V_162 ) {
time = ( V_99 / 10 ) * F_156 ( V_8 ) ;
if ( time )
V_2 -> V_121 = 1 ;
else if ( ! F_171 ( & V_8 -> V_53 ) ||
( V_2 -> V_121 > V_162 ) )
V_2 -> V_121 = V_162 ;
} else {
V_163 = ( V_99 / 10 ) * F_156 ( V_8 ) ;
V_2 -> V_121 = V_162 = 1 ;
}
}
V_49 = V_8 -> V_49 ;
V_14 = V_2 -> V_4 ;
F_172 ( & V_8 -> V_53 , & V_160 ) ;
while ( V_66 ) {
if ( V_49 && V_8 -> V_37 -> V_51 ) {
unsigned char V_169 ;
if ( V_149 != V_65 )
break;
F_173 ( & V_8 -> V_37 -> V_50 ) ;
V_169 = V_8 -> V_37 -> V_51 ;
V_8 -> V_37 -> V_51 = 0 ;
F_174 ( & V_8 -> V_37 -> V_50 ) ;
if ( F_6 ( V_8 , V_169 , V_149 ++ ) ) {
V_63 = - V_155 ;
V_149 -- ;
break;
}
V_66 -- ;
break;
}
if ( ( ( V_162 - ( V_149 - V_65 ) ) < V_2 -> V_121 ) &&
( ( V_162 - ( V_149 - V_65 ) ) >= 1 ) )
V_2 -> V_121 = ( V_162 - ( V_149 - V_65 ) ) ;
V_147 = F_158 ( V_8 ) ;
if ( ! F_155 ( V_8 , 0 ) ) {
if ( V_147 ) {
V_63 = - V_170 ;
break;
}
if ( F_175 ( V_156 ) )
break;
if ( ! V_163 )
break;
if ( V_156 -> V_164 & V_165 ) {
V_63 = - V_166 ;
break;
}
if ( F_176 ( V_127 ) ) {
V_63 = - V_167 ;
break;
}
F_84 ( & V_8 -> V_54 ) ;
V_163 = F_177 ( & V_160 , V_171 ,
V_163 ) ;
F_86 ( & V_8 -> V_54 ) ;
continue;
}
if ( V_2 -> V_12 && ! F_136 ( V_8 ) ) {
V_63 = F_161 ( V_8 , & V_149 , & V_66 ) ;
if ( V_63 )
break;
} else {
int V_18 ;
if ( V_49 && V_149 == V_65 ) {
if ( F_6 ( V_8 , V_172 , V_149 ++ ) ) {
V_63 = - V_155 ;
V_149 -- ;
break;
}
V_66 -- ;
}
V_18 = F_160 ( V_8 , & V_149 , & V_66 ) ;
V_18 += F_160 ( V_8 , & V_149 , & V_66 ) ;
if ( V_18 ) {
V_63 = - V_155 ;
break;
}
}
F_24 ( V_8 ) ;
if ( V_149 - V_65 >= V_162 )
break;
if ( time )
V_163 = time ;
}
if ( V_14 != V_2 -> V_4 )
F_11 ( V_8 ) ;
F_84 ( & V_8 -> V_54 ) ;
F_178 ( & V_8 -> V_53 , & V_160 ) ;
if ( ! F_171 ( & V_8 -> V_53 ) )
V_2 -> V_121 = V_162 ;
F_53 ( & V_2 -> V_143 ) ;
if ( V_149 - V_65 )
V_63 = V_149 - V_65 ;
return V_63 ;
}
static T_3 F_179 ( struct V_7 * V_8 , struct V_156 * V_156 ,
const unsigned char * V_65 , T_1 V_66 )
{
const unsigned char * V_149 = V_65 ;
F_168 ( V_160 , V_161 ) ;
int V_40 ;
T_3 V_63 = 0 ;
if ( F_180 ( V_8 ) && V_156 -> V_157 -> V_61 != V_158 ) {
V_63 = F_181 ( V_8 ) ;
if ( V_63 )
return V_63 ;
}
F_86 ( & V_8 -> V_54 ) ;
F_58 ( V_8 ) ;
F_172 ( & V_8 -> V_141 , & V_160 ) ;
while ( 1 ) {
if ( F_176 ( V_127 ) ) {
V_63 = - V_167 ;
break;
}
if ( F_175 ( V_156 ) || ( V_8 -> V_37 && ! V_8 -> V_37 -> V_36 ) ) {
V_63 = - V_170 ;
break;
}
if ( F_56 ( V_8 ) ) {
while ( V_66 > 0 ) {
T_3 V_173 = F_54 ( V_8 , V_149 , V_66 ) ;
if ( V_173 < 0 ) {
if ( V_173 == - V_166 )
break;
V_63 = V_173 ;
goto V_68;
}
V_149 += V_173 ;
V_66 -= V_173 ;
if ( V_66 == 0 )
break;
V_40 = * V_149 ;
if ( F_50 ( V_40 , V_8 ) < 0 )
break;
V_149 ++ ; V_66 -- ;
}
if ( V_8 -> V_60 -> V_84 )
V_8 -> V_60 -> V_84 ( V_8 ) ;
} else {
struct V_1 * V_2 = V_8 -> V_11 ;
while ( V_66 > 0 ) {
F_51 ( & V_2 -> V_64 ) ;
V_40 = V_8 -> V_60 -> V_61 ( V_8 , V_149 , V_66 ) ;
F_53 ( & V_2 -> V_64 ) ;
if ( V_40 < 0 ) {
V_63 = V_40 ;
goto V_68;
}
if ( ! V_40 )
break;
V_149 += V_40 ;
V_66 -= V_40 ;
}
}
if ( ! V_66 )
break;
if ( V_156 -> V_164 & V_165 ) {
V_63 = - V_166 ;
break;
}
F_84 ( & V_8 -> V_54 ) ;
F_177 ( & V_160 , V_171 , V_168 ) ;
F_86 ( & V_8 -> V_54 ) ;
}
V_68:
F_178 ( & V_8 -> V_141 , & V_160 ) ;
if ( V_149 - V_65 != V_66 && V_8 -> V_26 )
F_118 ( V_27 , & V_8 -> V_23 ) ;
F_84 ( & V_8 -> V_54 ) ;
return ( V_149 - V_65 ) ? V_149 - V_65 : V_63 ;
}
static unsigned int F_182 ( struct V_7 * V_8 , struct V_156 * V_156 ,
T_4 * V_160 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned int V_174 = 0 ;
F_183 ( V_156 , & V_8 -> V_53 , V_160 ) ;
F_183 ( V_156 , & V_8 -> V_141 , V_160 ) ;
if ( F_158 ( V_8 ) )
V_174 |= V_175 ;
if ( F_155 ( V_8 , 1 ) )
V_174 |= V_108 | V_176 ;
if ( V_8 -> V_49 && V_8 -> V_37 -> V_51 )
V_174 |= V_177 | V_108 | V_176 ;
if ( F_175 ( V_156 ) )
V_174 |= V_175 ;
if ( ! ( V_174 & ( V_175 | V_108 | V_176 ) ) ) {
if ( F_157 ( V_8 ) && ! F_156 ( V_8 ) )
V_2 -> V_121 = F_157 ( V_8 ) ;
else
V_2 -> V_121 = 1 ;
}
if ( V_8 -> V_60 -> V_61 && ! F_184 ( V_8 ) &&
F_185 ( V_8 ) < V_178 &&
F_52 ( V_8 ) > 0 )
V_174 |= V_179 | V_180 ;
return V_174 ;
}
static unsigned long F_186 ( struct V_1 * V_2 )
{
T_1 V_66 , V_81 , V_14 ;
if ( V_2 -> V_25 == V_2 -> V_4 )
return 0 ;
V_81 = V_2 -> V_25 ;
V_14 = V_2 -> V_4 ;
V_66 = V_81 - V_14 ;
while ( V_81 != V_14 ) {
if ( F_14 ( V_14 & ( V_6 - 1 ) , V_2 -> V_47 ) &&
F_2 ( V_2 , V_14 ) == V_106 )
V_66 -- ;
V_14 ++ ;
}
return V_66 ;
}
static int F_187 ( struct V_7 * V_8 , struct V_156 * V_156 ,
unsigned int V_181 , unsigned long V_182 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_63 ;
switch ( V_181 ) {
case V_183 :
return F_8 ( F_185 ( V_8 ) , ( int T_2 * ) V_182 ) ;
case V_184 :
F_35 ( & V_8 -> V_54 ) ;
if ( F_147 ( V_8 ) )
V_63 = F_186 ( V_2 ) ;
else
V_63 = F_1 ( V_2 ) ;
F_36 ( & V_8 -> V_54 ) ;
return F_8 ( V_63 , ( unsigned int T_2 * ) V_182 ) ;
default:
return F_188 ( V_8 , V_156 , V_181 , V_182 ) ;
}
}
static void F_189 ( struct V_7 * V_8 , int V_185 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! F_171 ( & V_8 -> V_53 ) ) {
if ( V_185 )
V_2 -> V_121 = 1 ;
else if ( ! V_8 -> V_26 )
V_2 -> V_121 = V_6 ;
}
}
void F_190 ( struct V_186 * V_60 )
{
* V_60 = V_187 ;
V_60 -> V_188 = NULL ;
V_60 -> V_189 = V_60 -> V_23 = 0 ;
}

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
F_7 ( V_8 , V_13 , V_15 , V_2 -> V_12 ) ;
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
F_15 ( V_21 , & V_8 -> V_17 -> V_22 . V_23 ) ;
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
if ( V_8 -> V_26 && F_18 ( V_27 , & V_8 -> V_20 ) )
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
if ( V_8 -> V_33 -> type == V_34 &&
V_8 -> V_35 -> V_36 -> V_37 -> V_38 == F_17 ) {
if ( F_16 ( V_8 ) > V_39 )
return;
if ( ! V_8 -> V_40 )
return;
F_11 ( V_8 ) ;
F_17 ( V_8 -> V_35 ) ;
if ( F_25 ( & V_8 -> V_35 -> V_41 ) )
F_26 ( & V_8 -> V_35 -> V_41 , V_42 ) ;
return;
}
while ( 1 ) {
int V_43 ;
F_21 ( V_8 , V_44 ) ;
if ( F_16 ( V_8 ) > V_39 )
break;
if ( ! V_8 -> V_40 )
break;
F_11 ( V_8 ) ;
V_43 = F_27 ( V_8 ) ;
if ( ! V_43 )
break;
}
F_23 ( V_8 , 0 ) ;
}
static inline void F_28 ( unsigned char V_45 , struct V_1 * V_2 )
{
* F_3 ( V_2 , V_2 -> V_3 ) = V_45 ;
V_2 -> V_3 ++ ;
}
static void F_29 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_25 = V_2 -> V_4 = 0 ;
V_2 -> V_46 = V_2 -> V_47 = V_2 -> V_48 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_49 = 0 ;
V_2 -> V_50 = 0 ;
V_2 -> V_51 = 0 ;
F_30 ( V_2 -> V_52 , V_6 ) ;
V_2 -> V_53 = 0 ;
}
static void F_31 ( struct V_7 * V_8 )
{
unsigned long V_20 ;
if ( V_8 -> V_35 -> V_54 ) {
F_32 ( & V_8 -> V_55 , V_20 ) ;
V_8 -> V_56 |= V_57 ;
F_33 ( & V_8 -> V_55 , V_20 ) ;
F_34 ( & V_8 -> V_35 -> V_58 ) ;
}
}
static void F_35 ( struct V_7 * V_8 )
{
F_36 ( & V_8 -> V_59 ) ;
F_29 ( V_8 -> V_11 ) ;
F_11 ( V_8 ) ;
if ( V_8 -> V_35 )
F_31 ( V_8 ) ;
F_37 ( & V_8 -> V_59 ) ;
}
static T_3 F_38 ( struct V_7 * V_8 )
{
T_3 V_15 ;
F_39 ( 1 , L_3 , V_60 ) ;
F_36 ( & V_8 -> V_59 ) ;
V_15 = F_16 ( V_8 ) ;
F_37 ( & V_8 -> V_59 ) ;
return V_15 ;
}
static inline int F_40 ( unsigned char V_45 )
{
return ( V_45 & 0xc0 ) == 0x80 ;
}
static inline int F_41 ( unsigned char V_45 , struct V_7 * V_8 )
{
return F_42 ( V_8 ) && F_40 ( V_45 ) ;
}
static int F_43 ( unsigned char V_45 , struct V_7 * V_8 , int V_61 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_62 ;
if ( ! V_61 )
return - 1 ;
switch ( V_45 ) {
case '\n' :
if ( F_44 ( V_8 ) )
V_2 -> V_63 = 0 ;
if ( F_45 ( V_8 ) ) {
if ( V_61 < 2 )
return - 1 ;
V_2 -> V_64 = V_2 -> V_63 = 0 ;
V_8 -> V_37 -> V_65 ( V_8 , L_4 , 2 ) ;
return 2 ;
}
V_2 -> V_64 = V_2 -> V_63 ;
break;
case '\r' :
if ( F_46 ( V_8 ) && V_2 -> V_63 == 0 )
return 0 ;
if ( F_47 ( V_8 ) ) {
V_45 = '\n' ;
if ( F_44 ( V_8 ) )
V_2 -> V_64 = V_2 -> V_63 = 0 ;
break;
}
V_2 -> V_64 = V_2 -> V_63 = 0 ;
break;
case '\t' :
V_62 = 8 - ( V_2 -> V_63 & 7 ) ;
if ( F_48 ( V_8 ) == V_66 ) {
if ( V_61 < V_62 )
return - 1 ;
V_2 -> V_63 += V_62 ;
V_8 -> V_37 -> V_65 ( V_8 , L_5 , V_62 ) ;
return V_62 ;
}
V_2 -> V_63 += V_62 ;
break;
case '\b' :
if ( V_2 -> V_63 > 0 )
V_2 -> V_63 -- ;
break;
default:
if ( ! iscntrl ( V_45 ) ) {
if ( F_49 ( V_8 ) )
V_45 = toupper ( V_45 ) ;
if ( ! F_41 ( V_45 , V_8 ) )
V_2 -> V_63 ++ ;
}
break;
}
F_50 ( V_8 , V_45 ) ;
return 1 ;
}
static int F_51 ( unsigned char V_45 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_61 , V_67 ;
F_52 ( & V_2 -> V_68 ) ;
V_61 = F_53 ( V_8 ) ;
V_67 = F_43 ( V_45 , V_8 , V_61 ) ;
F_54 ( & V_2 -> V_68 ) ;
if ( V_67 < 0 )
return - 1 ;
else
return 0 ;
}
static T_3 F_55 ( struct V_7 * V_8 ,
const unsigned char * V_22 , unsigned int V_69 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_61 ;
int V_5 ;
const unsigned char * V_70 ;
F_52 ( & V_2 -> V_68 ) ;
V_61 = F_53 ( V_8 ) ;
if ( ! V_61 ) {
F_54 ( & V_2 -> V_68 ) ;
return 0 ;
}
if ( V_69 > V_61 )
V_69 = V_61 ;
for ( V_5 = 0 , V_70 = V_22 ; V_5 < V_69 ; V_5 ++ , V_70 ++ ) {
unsigned char V_45 = * V_70 ;
switch ( V_45 ) {
case '\n' :
if ( F_44 ( V_8 ) )
V_2 -> V_63 = 0 ;
if ( F_45 ( V_8 ) )
goto V_71;
V_2 -> V_64 = V_2 -> V_63 ;
break;
case '\r' :
if ( F_46 ( V_8 ) && V_2 -> V_63 == 0 )
goto V_71;
if ( F_47 ( V_8 ) )
goto V_71;
V_2 -> V_64 = V_2 -> V_63 = 0 ;
break;
case '\t' :
goto V_71;
case '\b' :
if ( V_2 -> V_63 > 0 )
V_2 -> V_63 -- ;
break;
default:
if ( ! iscntrl ( V_45 ) ) {
if ( F_49 ( V_8 ) )
goto V_71;
if ( ! F_41 ( V_45 , V_8 ) )
V_2 -> V_63 ++ ;
}
break;
}
}
V_71:
V_5 = V_8 -> V_37 -> V_65 ( V_8 , V_22 , V_5 ) ;
F_54 ( & V_2 -> V_68 ) ;
return V_5 ;
}
static T_1 F_56 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_61 , V_72 ;
T_1 V_73 ;
unsigned char V_45 ;
V_72 = V_61 = F_53 ( V_8 ) ;
V_73 = V_2 -> V_47 ;
while ( V_2 -> V_48 != V_73 ) {
V_45 = F_4 ( V_2 , V_73 ) ;
if ( V_45 == V_74 ) {
unsigned char V_75 ;
int V_76 = 0 ;
V_75 = F_4 ( V_2 , V_73 + 1 ) ;
switch ( V_75 ) {
unsigned int V_77 , V_78 ;
case V_79 :
V_77 = F_4 ( V_2 , V_73 + 2 ) ;
if ( ! ( V_77 & 0x80 ) )
V_77 += V_2 -> V_64 ;
V_78 = 8 - ( V_77 & 7 ) ;
if ( V_78 > V_61 ) {
V_76 = 1 ;
break;
}
V_61 -= V_78 ;
while ( V_78 -- ) {
F_50 ( V_8 , '\b' ) ;
if ( V_2 -> V_63 > 0 )
V_2 -> V_63 -- ;
}
V_73 += 3 ;
break;
case V_80 :
V_2 -> V_64 = V_2 -> V_63 ;
V_73 += 2 ;
break;
case V_81 :
if ( V_2 -> V_63 > 0 )
V_2 -> V_63 -- ;
V_73 += 2 ;
break;
case V_74 :
if ( ! V_61 ) {
V_76 = 1 ;
break;
}
F_50 ( V_8 , V_74 ) ;
V_2 -> V_63 ++ ;
V_61 -- ;
V_73 += 2 ;
break;
default:
if ( V_61 < 2 ) {
V_76 = 1 ;
break;
}
F_50 ( V_8 , '^' ) ;
F_50 ( V_8 , V_75 ^ 0100 ) ;
V_2 -> V_63 += 2 ;
V_61 -= 2 ;
V_73 += 2 ;
}
if ( V_76 )
break;
} else {
if ( F_57 ( V_8 ) ) {
int V_67 = F_43 ( V_45 , V_8 , V_61 ) ;
if ( V_67 < 0 )
break;
V_61 -= V_67 ;
} else {
if ( ! V_61 )
break;
F_50 ( V_8 , V_45 ) ;
V_61 -= 1 ;
}
V_73 += 1 ;
}
}
while ( V_2 -> V_48 - V_73 >= V_82 ) {
if ( F_4 ( V_2 , V_73 ) == V_74 ) {
if ( F_4 ( V_2 , V_73 + 1 ) == V_79 )
V_73 += 3 ;
else
V_73 += 2 ;
} else
V_73 ++ ;
}
V_2 -> V_47 = V_73 ;
return V_72 - V_61 ;
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_69 , V_83 , V_84 ;
T_1 V_85 ;
V_85 = V_2 -> V_46 ;
V_2 -> V_49 = V_85 ;
V_83 = V_2 -> V_48 - V_2 -> V_47 ;
V_69 = V_85 - V_2 -> V_47 ;
if ( V_69 < V_86 || ( V_69 % V_87 > V_83 % V_87 ) )
return;
F_52 ( & V_2 -> V_68 ) ;
V_2 -> V_48 = V_85 ;
V_84 = F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_68 ) ;
if ( V_84 && V_8 -> V_37 -> V_88 )
V_8 -> V_37 -> V_88 ( V_8 ) ;
}
static void F_59 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_84 ;
if ( V_2 -> V_49 == V_2 -> V_47 )
return;
F_52 ( & V_2 -> V_68 ) ;
V_2 -> V_48 = V_2 -> V_49 ;
V_84 = F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_68 ) ;
if ( V_84 && V_8 -> V_37 -> V_88 )
V_8 -> V_37 -> V_88 ( V_8 ) ;
}
static void F_60 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ( ! F_61 ( V_8 ) && ! F_62 ( V_8 ) ) ||
V_2 -> V_48 == V_2 -> V_46 )
return;
F_52 ( & V_2 -> V_68 ) ;
V_2 -> V_48 = V_2 -> V_46 ;
F_56 ( V_8 ) ;
F_54 ( & V_2 -> V_68 ) ;
}
static inline void F_63 ( unsigned char V_45 , struct V_1 * V_2 )
{
* F_5 ( V_2 , V_2 -> V_46 ++ ) = V_45 ;
}
static void F_64 ( struct V_1 * V_2 )
{
F_63 ( V_74 , V_2 ) ;
F_63 ( V_81 , V_2 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_63 ( V_74 , V_2 ) ;
F_63 ( V_80 , V_2 ) ;
}
static void F_66 ( unsigned int V_77 , int V_89 ,
struct V_1 * V_2 )
{
F_63 ( V_74 , V_2 ) ;
F_63 ( V_79 , V_2 ) ;
V_77 &= 7 ;
if ( V_89 )
V_77 |= 0x80 ;
F_63 ( V_77 , V_2 ) ;
}
static void F_67 ( unsigned char V_45 , struct V_1 * V_2 )
{
if ( V_45 == V_74 ) {
F_63 ( V_74 , V_2 ) ;
F_63 ( V_74 , V_2 ) ;
} else {
F_63 ( V_45 , V_2 ) ;
}
}
static void F_68 ( unsigned char V_45 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_45 == V_74 ) {
F_63 ( V_74 , V_2 ) ;
F_63 ( V_74 , V_2 ) ;
} else {
if ( F_69 ( V_8 ) && iscntrl ( V_45 ) && V_45 != '\t' )
F_63 ( V_74 , V_2 ) ;
F_63 ( V_45 , V_2 ) ;
}
}
static inline void F_70 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 ) {
F_67 ( '/' , V_2 ) ;
V_2 -> V_51 = 0 ;
}
}
static void F_71 ( unsigned char V_45 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
enum { V_90 , V_91 , V_92 } V_93 ;
T_1 V_85 ;
T_1 V_94 ;
int V_95 ;
if ( V_2 -> V_3 == V_2 -> V_25 ) {
return;
}
if ( V_45 == F_72 ( V_8 ) )
V_93 = V_90 ;
else if ( V_45 == F_73 ( V_8 ) )
V_93 = V_91 ;
else {
if ( ! F_61 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_25 ;
return;
}
if ( ! F_74 ( V_8 ) || ! F_75 ( V_8 ) || ! F_76 ( V_8 ) ) {
V_2 -> V_3 = V_2 -> V_25 ;
F_70 ( V_2 ) ;
F_68 ( F_77 ( V_8 ) , V_8 ) ;
if ( F_74 ( V_8 ) )
F_67 ( '\n' , V_2 ) ;
return;
}
V_93 = V_92 ;
}
V_95 = 0 ;
while ( V_2 -> V_3 != V_2 -> V_25 ) {
V_85 = V_2 -> V_3 ;
do {
V_85 -- ;
V_45 = F_2 ( V_2 , V_85 ) ;
} while ( F_41 ( V_45 , V_8 ) && V_85 != V_2 -> V_25 );
if ( F_41 ( V_45 , V_8 ) )
break;
if ( V_93 == V_91 ) {
if ( isalnum ( V_45 ) || V_45 == '_' )
V_95 ++ ;
else if ( V_95 )
break;
}
V_94 = V_2 -> V_3 - V_85 ;
V_2 -> V_3 = V_85 ;
if ( F_61 ( V_8 ) ) {
if ( F_78 ( V_8 ) ) {
if ( ! V_2 -> V_51 ) {
F_67 ( '\\' , V_2 ) ;
V_2 -> V_51 = 1 ;
}
F_68 ( V_45 , V_8 ) ;
while ( -- V_94 > 0 ) {
V_85 ++ ;
F_67 ( F_2 ( V_2 , V_85 ) , V_2 ) ;
F_64 ( V_2 ) ;
}
} else if ( V_93 == V_90 && ! F_76 ( V_8 ) ) {
F_68 ( F_72 ( V_8 ) , V_8 ) ;
} else if ( V_45 == '\t' ) {
unsigned int V_77 = 0 ;
int V_89 = 0 ;
T_1 V_73 = V_2 -> V_3 ;
while ( V_73 != V_2 -> V_25 ) {
V_73 -- ;
V_45 = F_2 ( V_2 , V_73 ) ;
if ( V_45 == '\t' ) {
V_89 = 1 ;
break;
} else if ( iscntrl ( V_45 ) ) {
if ( F_69 ( V_8 ) )
V_77 += 2 ;
} else if ( ! F_41 ( V_45 , V_8 ) ) {
V_77 ++ ;
}
}
F_66 ( V_77 , V_89 , V_2 ) ;
} else {
if ( iscntrl ( V_45 ) && F_69 ( V_8 ) ) {
F_67 ( '\b' , V_2 ) ;
F_67 ( ' ' , V_2 ) ;
F_67 ( '\b' , V_2 ) ;
}
if ( ! iscntrl ( V_45 ) || F_69 ( V_8 ) ) {
F_67 ( '\b' , V_2 ) ;
F_67 ( ' ' , V_2 ) ;
F_67 ( '\b' , V_2 ) ;
}
}
}
if ( V_93 == V_90 )
break;
}
if ( V_2 -> V_3 == V_2 -> V_25 && F_61 ( V_8 ) )
F_70 ( V_2 ) ;
}
static void F_79 ( int V_96 , struct V_7 * V_8 )
{
struct V_97 * V_98 = F_80 ( V_8 ) ;
if ( V_98 ) {
F_81 ( V_98 , V_96 , 1 ) ;
F_82 ( V_98 ) ;
}
}
static void F_83 ( int V_96 , struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_84 ( V_8 ) ) {
F_79 ( V_96 , V_8 ) ;
} else {
F_85 ( & V_8 -> V_59 ) ;
F_36 ( & V_8 -> V_59 ) ;
F_79 ( V_96 , V_8 ) ;
F_52 ( & V_2 -> V_68 ) ;
V_2 -> V_46 = V_2 -> V_47 = 0 ;
V_2 -> V_49 = V_2 -> V_48 = 0 ;
F_54 ( & V_2 -> V_68 ) ;
F_86 ( V_8 ) ;
F_29 ( V_8 -> V_11 ) ;
if ( V_8 -> V_35 )
F_31 ( V_8 ) ;
F_37 ( & V_8 -> V_59 ) ;
F_87 ( & V_8 -> V_59 ) ;
}
}
static void F_88 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_89 ( V_8 ) )
return;
if ( F_90 ( V_8 ) ) {
F_83 ( V_99 , V_8 ) ;
return;
}
if ( F_91 ( V_8 ) ) {
F_28 ( '\377' , V_2 ) ;
F_28 ( '\0' , V_2 ) ;
}
F_28 ( '\0' , V_2 ) ;
if ( F_25 ( & V_8 -> V_58 ) )
F_26 ( & V_8 -> V_58 , V_100 ) ;
}
static void F_92 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_101 ++ ;
if ( F_93 ( V_102 , V_2 -> V_103 + V_104 ) ||
F_93 ( V_2 -> V_103 , V_102 ) ) {
F_94 ( V_105 L_6 ,
F_95 ( V_8 ) ,
V_2 -> V_101 ) ;
V_2 -> V_103 = V_102 ;
V_2 -> V_101 = 0 ;
}
}
static void F_96 ( struct V_7 * V_8 , unsigned char V_45 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_97 ( V_8 ) ) {
if ( F_98 ( V_8 ) )
return;
if ( F_91 ( V_8 ) ) {
F_28 ( '\377' , V_2 ) ;
F_28 ( '\0' , V_2 ) ;
F_28 ( V_45 , V_2 ) ;
} else
F_28 ( '\0' , V_2 ) ;
} else
F_28 ( V_45 , V_2 ) ;
if ( F_25 ( & V_8 -> V_58 ) )
F_26 ( & V_8 -> V_58 , V_100 ) ;
}
static void
F_99 ( struct V_7 * V_8 , int signal , unsigned char V_45 )
{
F_83 ( signal , V_8 ) ;
if ( F_100 ( V_8 ) )
F_101 ( V_8 ) ;
if ( F_61 ( V_8 ) ) {
F_68 ( V_45 , V_8 ) ;
F_58 ( V_8 ) ;
} else
F_59 ( V_8 ) ;
return;
}
static int
F_102 ( struct V_7 * V_8 , unsigned char V_45 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( F_100 ( V_8 ) ) {
if ( V_45 == F_103 ( V_8 ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
return 0 ;
}
if ( V_45 == F_104 ( V_8 ) ) {
F_105 ( V_8 ) ;
return 0 ;
}
}
if ( F_106 ( V_8 ) ) {
if ( V_45 == F_107 ( V_8 ) ) {
F_99 ( V_8 , V_99 , V_45 ) ;
return 0 ;
} else if ( V_45 == F_108 ( V_8 ) ) {
F_99 ( V_8 , V_106 , V_45 ) ;
return 0 ;
} else if ( V_45 == F_109 ( V_8 ) ) {
F_99 ( V_8 , V_107 , V_45 ) ;
return 0 ;
}
}
if ( V_8 -> V_108 && ! V_8 -> V_109 && F_100 ( V_8 ) && F_110 ( V_8 ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( V_45 == '\r' ) {
if ( F_111 ( V_8 ) )
return 0 ;
if ( F_112 ( V_8 ) )
V_45 = '\n' ;
} else if ( V_45 == '\n' && F_113 ( V_8 ) )
V_45 = '\r' ;
if ( V_2 -> V_12 ) {
if ( V_45 == F_72 ( V_8 ) || V_45 == F_77 ( V_8 ) ||
( V_45 == F_73 ( V_8 ) && F_114 ( V_8 ) ) ) {
F_71 ( V_45 , V_8 ) ;
F_58 ( V_8 ) ;
return 0 ;
}
if ( V_45 == F_115 ( V_8 ) && F_114 ( V_8 ) ) {
V_2 -> V_110 = 1 ;
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
if ( V_45 == F_116 ( V_8 ) && F_61 ( V_8 ) && F_114 ( V_8 ) ) {
T_1 V_73 = V_2 -> V_25 ;
F_70 ( V_2 ) ;
F_68 ( V_45 , V_8 ) ;
F_67 ( '\n' , V_2 ) ;
while ( V_73 != V_2 -> V_3 ) {
F_68 ( F_2 ( V_2 , V_73 ) , V_8 ) ;
V_73 ++ ;
}
F_58 ( V_8 ) ;
return 0 ;
}
if ( V_45 == '\n' ) {
if ( F_61 ( V_8 ) || F_62 ( V_8 ) ) {
F_67 ( '\n' , V_2 ) ;
F_58 ( V_8 ) ;
}
goto V_111;
}
if ( V_45 == F_117 ( V_8 ) ) {
V_45 = V_112 ;
goto V_111;
}
if ( ( V_45 == F_118 ( V_8 ) ) ||
( V_45 == F_119 ( V_8 ) && F_114 ( V_8 ) ) ) {
if ( F_61 ( V_8 ) ) {
if ( V_2 -> V_25 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_45 , V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_45 == ( unsigned char ) '\377' && F_91 ( V_8 ) )
F_28 ( V_45 , V_2 ) ;
V_111:
F_120 ( V_2 -> V_3 & ( V_6 - 1 ) , V_2 -> V_52 ) ;
F_28 ( V_45 , V_2 ) ;
F_121 ( & V_2 -> V_25 , V_2 -> V_3 ) ;
F_19 ( & V_8 -> V_26 , V_28 , V_113 ) ;
F_26 ( & V_8 -> V_58 , V_100 ) ;
return 0 ;
}
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_45 == '\n' )
F_67 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_25 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_45 , V_8 ) ;
}
F_58 ( V_8 ) ;
}
if ( V_45 == ( unsigned char ) '\377' && F_91 ( V_8 ) )
F_28 ( V_45 , V_2 ) ;
F_28 ( V_45 , V_2 ) ;
return 0 ;
}
static inline void
F_122 ( struct V_7 * V_8 , unsigned char V_45 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_108 && ! V_8 -> V_109 && F_100 ( V_8 ) && F_110 ( V_8 ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_2 -> V_25 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_45 , V_8 ) ;
F_58 ( V_8 ) ;
}
if ( V_45 == ( unsigned char ) '\377' && F_91 ( V_8 ) )
F_28 ( V_45 , V_2 ) ;
F_28 ( V_45 , V_2 ) ;
}
static void F_123 ( struct V_7 * V_8 , unsigned char V_45 )
{
F_122 ( V_8 , V_45 ) ;
}
static inline void
F_124 ( struct V_7 * V_8 , unsigned char V_45 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_108 && ! V_8 -> V_109 && F_100 ( V_8 ) && F_110 ( V_8 ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
if ( F_61 ( V_8 ) ) {
F_70 ( V_2 ) ;
if ( V_2 -> V_25 == V_2 -> V_3 )
F_65 ( V_2 ) ;
F_68 ( V_45 , V_8 ) ;
F_58 ( V_8 ) ;
}
F_28 ( V_45 , V_2 ) ;
}
static void F_125 ( struct V_7 * V_8 , unsigned char V_45 )
{
if ( F_126 ( V_8 ) )
V_45 &= 0x7f ;
if ( F_127 ( V_8 ) && F_114 ( V_8 ) )
V_45 = tolower ( V_45 ) ;
if ( F_100 ( V_8 ) ) {
if ( V_45 == F_104 ( V_8 ) )
F_105 ( V_8 ) ;
else if ( V_45 == F_103 ( V_8 ) ||
( V_8 -> V_108 && ! V_8 -> V_109 && F_110 ( V_8 ) &&
V_45 != F_107 ( V_8 ) && V_45 != F_108 ( V_8 ) &&
V_45 != F_109 ( V_8 ) ) ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
}
}
static void
F_128 ( struct V_7 * V_8 , unsigned char V_45 , char V_114 )
{
switch ( V_114 ) {
case V_115 :
F_88 ( V_8 ) ;
break;
case V_116 :
case V_117 :
F_96 ( V_8 , V_45 ) ;
break;
case V_118 :
F_92 ( V_8 ) ;
break;
default:
F_94 ( V_119 L_7 ,
F_95 ( V_8 ) , V_114 ) ;
break;
}
}
static void
F_129 ( struct V_7 * V_8 , unsigned char V_45 , char V_114 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
V_2 -> V_110 = 0 ;
if ( F_130 ( V_114 == V_120 ) ) {
if ( F_126 ( V_8 ) )
V_45 &= 0x7f ;
if ( F_127 ( V_8 ) && F_114 ( V_8 ) )
V_45 = tolower ( V_45 ) ;
F_123 ( V_8 , V_45 ) ;
} else
F_128 ( V_8 , V_45 , V_114 ) ;
}
static void
F_131 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_15 , V_85 ;
V_85 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_15 = F_132 ( T_1 , V_40 , V_6 - V_85 ) ;
memcpy ( F_3 ( V_2 , V_85 ) , V_70 , V_15 ) ;
V_2 -> V_3 += V_15 ;
V_70 += V_15 ;
V_40 -= V_15 ;
V_85 = V_2 -> V_3 & ( V_6 - 1 ) ;
V_15 = F_132 ( T_1 , V_40 , V_6 - V_85 ) ;
memcpy ( F_3 ( V_2 , V_85 ) , V_70 , V_15 ) ;
V_2 -> V_3 += V_15 ;
}
static void
F_133 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_114 = V_120 ;
while ( V_40 -- ) {
if ( V_121 )
V_114 = * V_121 ++ ;
if ( F_130 ( V_114 == V_120 ) )
F_28 ( * V_70 ++ , V_2 ) ;
else
F_128 ( V_8 , * V_70 ++ , V_114 ) ;
}
}
static void
F_134 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 )
{
char V_114 = V_120 ;
while ( V_40 -- ) {
if ( V_121 )
V_114 = * V_121 ++ ;
if ( F_130 ( V_114 == V_120 ) )
F_125 ( V_8 , * V_70 ++ ) ;
else
F_128 ( V_8 , * V_70 ++ , V_114 ) ;
}
}
static void
F_135 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_114 = V_120 ;
while ( V_40 -- ) {
if ( V_121 )
V_114 = * V_121 ++ ;
if ( F_130 ( V_114 == V_120 ) ) {
unsigned char V_45 = * V_70 ++ ;
if ( F_126 ( V_8 ) )
V_45 &= 0x7f ;
if ( F_127 ( V_8 ) && F_114 ( V_8 ) )
V_45 = tolower ( V_45 ) ;
if ( F_136 ( V_8 ) ) {
F_28 ( V_45 , V_2 ) ;
continue;
}
if ( ! F_14 ( V_45 , V_2 -> V_122 ) )
F_122 ( V_8 , V_45 ) ;
else if ( F_102 ( V_8 , V_45 ) && V_40 ) {
if ( V_121 )
V_114 = * V_121 ++ ;
F_129 ( V_8 , * V_70 ++ , V_114 ) ;
V_40 -- ;
}
} else
F_128 ( V_8 , * V_70 ++ , V_114 ) ;
}
}
static void
F_137 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
char V_114 = V_120 ;
while ( V_40 -- ) {
if ( V_121 )
V_114 = * V_121 ++ ;
if ( F_130 ( V_114 == V_120 ) ) {
unsigned char V_45 = * V_70 ++ ;
if ( ! F_14 ( V_45 , V_2 -> V_122 ) )
F_124 ( V_8 , V_45 ) ;
else if ( F_102 ( V_8 , V_45 ) && V_40 ) {
if ( V_121 )
V_114 = * V_121 ++ ;
F_129 ( V_8 , * V_70 ++ , V_114 ) ;
V_40 -- ;
}
} else
F_128 ( V_8 , * V_70 ++ , V_114 ) ;
}
}
static void F_138 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
bool V_123 = F_126 ( V_8 ) || ( F_127 ( V_8 ) && F_114 ( V_8 ) ) ;
if ( V_2 -> V_124 )
F_131 ( V_8 , V_70 , V_121 , V_40 ) ;
else if ( V_2 -> V_125 || ( F_136 ( V_8 ) && ! V_123 ) )
F_133 ( V_8 , V_70 , V_121 , V_40 ) ;
else if ( V_8 -> V_126 && ! F_136 ( V_8 ) )
F_134 ( V_8 , V_70 , V_121 , V_40 ) ;
else {
if ( V_2 -> V_110 ) {
char V_114 = V_120 ;
if ( V_121 )
V_114 = * V_121 ++ ;
F_129 ( V_8 , * V_70 ++ , V_114 ) ;
V_40 -- ;
}
if ( ! V_123 && ! F_91 ( V_8 ) )
F_137 ( V_8 , V_70 , V_121 , V_40 ) ;
else
F_135 ( V_8 , V_70 , V_121 , V_40 ) ;
F_60 ( V_8 ) ;
if ( V_8 -> V_37 -> V_88 )
V_8 -> V_37 -> V_88 ( V_8 ) ;
}
if ( V_2 -> V_12 && ! F_136 ( V_8 ) )
return;
F_121 ( & V_2 -> V_24 , V_2 -> V_3 ) ;
if ( ( F_1 ( V_2 ) >= V_2 -> V_127 ) || F_136 ( V_8 ) ) {
F_19 ( & V_8 -> V_26 , V_28 , V_113 ) ;
F_26 ( & V_8 -> V_58 , V_100 ) ;
}
}
static int
F_139 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 , int V_128 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_129 , V_15 , V_130 = 0 , V_131 ;
F_87 ( & V_8 -> V_59 ) ;
while ( 1 ) {
T_1 V_73 = F_140 ( & V_2 -> V_4 ) ;
V_129 = V_6 - ( V_2 -> V_3 - V_73 ) ;
if ( F_91 ( V_8 ) )
V_129 = ( V_129 + 2 ) / 3 ;
V_129 -- ;
if ( V_129 <= 0 ) {
V_131 = V_2 -> V_12 && V_2 -> V_25 == V_73 ;
if ( V_131 && V_129 < 0 )
V_2 -> V_3 -- ;
V_129 = V_131 ;
V_2 -> V_16 = V_128 && ! V_129 ;
} else
V_131 = 0 ;
V_15 = F_141 ( V_40 , V_129 ) ;
if ( ! V_15 )
break;
if ( ! V_131 || ! V_121 || * V_121 != V_116 )
F_138 ( V_8 , V_70 , V_121 , V_15 ) ;
V_70 += V_15 ;
if ( V_121 )
V_121 += V_15 ;
V_40 -= V_15 ;
V_130 += V_15 ;
}
V_8 -> V_132 = V_129 ;
if ( V_8 -> V_33 -> type == V_34 ) {
if ( V_131 ) {
F_21 ( V_8 , V_44 ) ;
F_27 ( V_8 ) ;
F_23 ( V_8 , 0 ) ;
}
} else
F_20 ( V_8 ) ;
F_85 ( & V_8 -> V_59 ) ;
return V_130 ;
}
static void F_142 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 )
{
F_139 ( V_8 , V_70 , V_121 , V_40 , 0 ) ;
}
static int F_143 ( struct V_7 * V_8 , const unsigned char * V_70 ,
char * V_121 , int V_40 )
{
return F_139 ( V_8 , V_70 , V_121 , V_40 , 1 ) ;
}
int F_144 ( int V_96 )
{
return ( F_145 ( & V_133 -> V_134 , V_96 ) ||
V_133 -> V_135 -> V_136 [ V_96 - 1 ] . V_137 . V_138 == V_139 ) ;
}
static void F_146 ( struct V_7 * V_8 , struct V_140 * V_83 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! V_83 || ( V_83 -> V_141 ^ V_8 -> V_142 . V_141 ) & V_143 ) {
F_30 ( V_2 -> V_52 , V_6 ) ;
V_2 -> V_50 = V_2 -> V_4 ;
if ( ! F_147 ( V_8 ) || ! F_1 ( V_2 ) ) {
V_2 -> V_25 = V_2 -> V_4 ;
V_2 -> V_53 = 0 ;
} else {
F_120 ( ( V_2 -> V_3 - 1 ) & ( V_6 - 1 ) ,
V_2 -> V_52 ) ;
V_2 -> V_25 = V_2 -> V_3 ;
V_2 -> V_53 = 1 ;
}
V_2 -> V_24 = V_2 -> V_3 ;
V_2 -> V_51 = 0 ;
V_2 -> V_110 = 0 ;
}
V_2 -> V_12 = ( F_147 ( V_8 ) != 0 ) ;
if ( F_126 ( V_8 ) || F_127 ( V_8 ) || F_111 ( V_8 ) ||
F_112 ( V_8 ) || F_113 ( V_8 ) || F_147 ( V_8 ) ||
F_100 ( V_8 ) || F_106 ( V_8 ) || F_61 ( V_8 ) ||
F_91 ( V_8 ) ) {
F_30 ( V_2 -> V_122 , 256 ) ;
if ( F_111 ( V_8 ) || F_112 ( V_8 ) )
F_120 ( '\r' , V_2 -> V_122 ) ;
if ( F_113 ( V_8 ) )
F_120 ( '\n' , V_2 -> V_122 ) ;
if ( F_147 ( V_8 ) ) {
F_120 ( F_72 ( V_8 ) , V_2 -> V_122 ) ;
F_120 ( F_77 ( V_8 ) , V_2 -> V_122 ) ;
F_120 ( F_117 ( V_8 ) , V_2 -> V_122 ) ;
F_120 ( '\n' , V_2 -> V_122 ) ;
F_120 ( F_118 ( V_8 ) , V_2 -> V_122 ) ;
if ( F_114 ( V_8 ) ) {
F_120 ( F_73 ( V_8 ) , V_2 -> V_122 ) ;
F_120 ( F_115 ( V_8 ) , V_2 -> V_122 ) ;
F_120 ( F_119 ( V_8 ) , V_2 -> V_122 ) ;
if ( F_61 ( V_8 ) )
F_120 ( F_116 ( V_8 ) ,
V_2 -> V_122 ) ;
}
}
if ( F_100 ( V_8 ) ) {
F_120 ( F_103 ( V_8 ) , V_2 -> V_122 ) ;
F_120 ( F_104 ( V_8 ) , V_2 -> V_122 ) ;
}
if ( F_106 ( V_8 ) ) {
F_120 ( F_107 ( V_8 ) , V_2 -> V_122 ) ;
F_120 ( F_108 ( V_8 ) , V_2 -> V_122 ) ;
F_120 ( F_109 ( V_8 ) , V_2 -> V_122 ) ;
}
F_148 ( V_112 , V_2 -> V_122 ) ;
V_2 -> V_125 = 0 ;
V_2 -> V_124 = 0 ;
} else {
V_2 -> V_125 = 1 ;
if ( ( F_89 ( V_8 ) || ( ! F_90 ( V_8 ) && ! F_91 ( V_8 ) ) ) &&
( F_98 ( V_8 ) || ! F_97 ( V_8 ) ) &&
( V_8 -> V_33 -> V_20 & V_144 ) )
V_2 -> V_124 = 1 ;
else
V_2 -> V_124 = 0 ;
}
if ( ! F_100 ( V_8 ) && V_83 && ( V_83 -> V_145 & V_146 ) && ! V_8 -> V_109 ) {
F_101 ( V_8 ) ;
F_59 ( V_8 ) ;
}
F_34 ( & V_8 -> V_41 ) ;
F_34 ( & V_8 -> V_58 ) ;
}
static void F_149 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( V_8 -> V_35 )
F_31 ( V_8 ) ;
F_150 ( V_2 ) ;
V_8 -> V_11 = NULL ;
}
static int F_151 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
V_2 = F_152 ( sizeof( * V_2 ) ) ;
if ( ! V_2 )
goto V_147;
V_2 -> V_103 = V_102 ;
F_153 ( & V_2 -> V_148 ) ;
F_153 ( & V_2 -> V_68 ) ;
V_8 -> V_11 = V_2 ;
F_29 ( V_8 -> V_11 ) ;
V_2 -> V_63 = 0 ;
V_2 -> V_64 = 0 ;
V_2 -> V_127 = 1 ;
V_2 -> V_101 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_110 = 0 ;
V_8 -> V_126 = 0 ;
F_148 ( V_19 , & V_8 -> V_20 ) ;
F_146 ( V_8 , NULL ) ;
F_154 ( V_8 ) ;
return 0 ;
V_147:
return - V_149 ;
}
static inline int F_155 ( struct V_7 * V_8 , int V_150 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_151 = V_150 && ! F_156 ( V_8 ) && F_157 ( V_8 ) ? F_157 ( V_8 ) : 1 ;
if ( V_2 -> V_12 && ! F_136 ( V_8 ) )
return V_2 -> V_25 != V_2 -> V_4 ;
else
return V_2 -> V_24 - V_2 -> V_4 >= V_151 ;
}
static inline int F_158 ( struct V_7 * V_8 )
{
int V_152 = F_14 ( V_153 , & V_8 -> V_20 ) ;
if ( V_152 ) {
F_159 () ;
}
return V_152 ;
}
static int F_160 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_154 ,
T_1 * V_69 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_67 ;
T_1 V_15 ;
bool V_155 ;
T_1 V_85 = F_140 ( & V_2 -> V_24 ) ;
T_1 V_73 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_67 = 0 ;
V_15 = F_141 ( V_85 - V_2 -> V_4 , V_6 - V_73 ) ;
V_15 = F_141 ( * V_69 , V_15 ) ;
if ( V_15 ) {
V_67 = F_10 ( * V_154 , F_3 ( V_2 , V_73 ) , V_15 ) ;
V_15 -= V_67 ;
V_155 = V_15 == 1 && F_2 ( V_2 , V_73 ) == F_117 ( V_8 ) ;
F_7 ( V_8 , F_3 ( V_2 , V_73 ) , V_15 ,
V_2 -> V_12 ) ;
F_121 ( & V_2 -> V_4 , V_2 -> V_4 + V_15 ) ;
if ( F_136 ( V_8 ) && V_2 -> V_12 && V_155 &&
( V_85 == V_2 -> V_4 ) )
V_15 = 0 ;
* V_154 += V_15 ;
* V_69 -= V_15 ;
}
return V_67 ;
}
static int F_161 ( struct V_7 * V_8 ,
unsigned char T_2 * * V_154 ,
T_1 * V_69 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
T_1 V_15 , V_156 , V_157 , V_45 ;
T_1 V_158 ;
T_1 V_73 ;
int V_159 , V_160 = 0 ;
bool V_161 = 0 ;
V_15 = F_141 ( * V_69 , F_140 ( & V_2 -> V_25 ) - V_2 -> V_4 ) ;
if ( ! V_15 )
return 0 ;
V_73 = V_2 -> V_4 & ( V_6 - 1 ) ;
V_156 = F_132 ( T_1 , V_73 + V_15 , V_6 ) ;
F_162 ( L_8 ,
V_60 , * V_69 , V_73 , V_15 , V_156 ) ;
V_158 = F_163 ( V_2 -> V_52 , V_156 , V_73 ) ;
V_157 = V_15 - ( V_156 - V_73 ) ;
if ( V_158 == V_6 && V_157 ) {
V_158 = F_163 ( V_2 -> V_52 , V_157 , 0 ) ;
if ( V_158 != V_157 )
V_160 = 1 ;
} else if ( V_158 != V_156 )
V_160 = 1 ;
V_156 = V_6 - V_73 ;
V_15 = V_158 - V_73 ;
if ( V_15 > V_6 )
V_15 += V_6 ;
V_15 += V_160 ;
V_45 = V_15 ;
if ( V_160 && ! V_2 -> V_53 && F_2 ( V_2 , V_158 ) == V_112 ) {
V_15 -- ;
V_161 = ! V_15 && V_2 -> V_4 != V_2 -> V_50 ;
}
F_162 ( L_9 ,
V_60 , V_158 , V_160 , V_15 , V_45 , V_156 , V_157 ) ;
if ( V_15 > V_156 ) {
V_159 = F_9 ( V_8 , * V_154 , F_3 ( V_2 , V_73 ) , V_156 ) ;
if ( V_159 )
return - V_162 ;
V_159 = F_9 ( V_8 , * V_154 + V_156 , V_2 -> F_2 , V_15 - V_156 ) ;
} else
V_159 = F_9 ( V_8 , * V_154 , F_3 ( V_2 , V_73 ) , V_15 ) ;
if ( V_159 )
return - V_162 ;
* V_154 += V_15 ;
* V_69 -= V_15 ;
if ( V_160 )
F_148 ( V_158 , V_2 -> V_52 ) ;
F_121 ( & V_2 -> V_4 , V_2 -> V_4 + V_45 ) ;
if ( V_160 ) {
if ( ! V_2 -> V_53 )
V_2 -> V_50 = V_2 -> V_4 ;
else
V_2 -> V_53 = 0 ;
F_164 ( V_8 ) ;
}
return V_161 ? - V_163 : 0 ;
}
static int F_165 ( struct V_7 * V_8 , struct V_164 * V_164 )
{
struct V_97 * V_165 ;
if ( V_164 -> V_166 -> V_65 == V_167 ||
V_133 -> signal -> V_8 != V_8 )
return 0 ;
F_166 () ;
V_165 = F_167 ( V_133 ) ;
F_168 ( & V_8 -> V_55 ) ;
if ( ! V_8 -> V_165 )
F_94 ( V_119 L_10 ) ;
else if ( V_165 != V_8 -> V_165 ) {
F_169 ( & V_8 -> V_55 ) ;
if ( F_144 ( V_168 ) || F_170 () ) {
F_171 () ;
return - V_169 ;
}
F_81 ( V_165 , V_168 , 1 ) ;
F_171 () ;
F_172 ( V_170 ) ;
return - V_171 ;
}
F_169 ( & V_8 -> V_55 ) ;
F_171 () ;
return 0 ;
}
static T_3 F_173 ( struct V_7 * V_8 , struct V_164 * V_164 ,
unsigned char T_2 * V_22 , T_1 V_69 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned char T_2 * V_154 = V_22 ;
F_174 ( V_172 , V_173 ) ;
int V_45 , V_152 ;
int V_174 , time ;
T_3 V_67 = 0 ;
long V_175 ;
int V_54 ;
T_1 V_73 ;
V_45 = F_165 ( V_8 , V_164 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_164 -> V_176 & V_177 ) {
if ( ! F_175 ( & V_2 -> V_148 ) )
return - V_163 ;
} else {
if ( F_176 ( & V_2 -> V_148 ) )
return - V_171 ;
}
F_87 ( & V_8 -> V_59 ) ;
V_174 = time = 0 ;
V_175 = V_178 ;
if ( ! V_2 -> V_12 ) {
V_174 = F_157 ( V_8 ) ;
if ( V_174 ) {
time = ( V_104 / 10 ) * F_156 ( V_8 ) ;
if ( time )
V_2 -> V_127 = 1 ;
else if ( ! F_25 ( & V_8 -> V_58 ) ||
( V_2 -> V_127 > V_174 ) )
V_2 -> V_127 = V_174 ;
} else {
V_175 = ( V_104 / 10 ) * F_156 ( V_8 ) ;
V_2 -> V_127 = V_174 = 1 ;
}
}
V_54 = V_8 -> V_54 ;
V_73 = V_2 -> V_4 ;
F_177 ( & V_8 -> V_58 , & V_172 ) ;
while ( V_69 ) {
if ( V_54 && V_8 -> V_35 -> V_56 ) {
unsigned char V_179 ;
if ( V_154 != V_22 )
break;
F_168 ( & V_8 -> V_35 -> V_55 ) ;
V_179 = V_8 -> V_35 -> V_56 ;
V_8 -> V_35 -> V_56 = 0 ;
F_169 ( & V_8 -> V_35 -> V_55 ) ;
if ( F_6 ( V_8 , V_179 , V_154 ++ ) ) {
V_67 = - V_162 ;
V_154 -- ;
break;
}
V_69 -- ;
break;
}
if ( ( ( V_174 - ( V_154 - V_22 ) ) < V_2 -> V_127 ) &&
( ( V_174 - ( V_154 - V_22 ) ) >= 1 ) )
V_2 -> V_127 = ( V_174 - ( V_154 - V_22 ) ) ;
V_152 = F_158 ( V_8 ) ;
if ( ! F_155 ( V_8 , 0 ) ) {
if ( V_152 ) {
V_67 = - V_169 ;
break;
}
if ( F_178 ( V_164 ) )
break;
if ( ! V_175 )
break;
if ( V_164 -> V_176 & V_177 ) {
V_67 = - V_163 ;
break;
}
if ( F_179 ( V_133 ) ) {
V_67 = - V_171 ;
break;
}
F_85 ( & V_8 -> V_59 ) ;
V_175 = F_180 ( & V_172 , V_180 ,
V_175 ) ;
F_87 ( & V_8 -> V_59 ) ;
continue;
}
if ( V_2 -> V_12 && ! F_136 ( V_8 ) ) {
V_67 = F_161 ( V_8 , & V_154 , & V_69 ) ;
if ( V_67 == - V_163 ) {
V_67 = 0 ;
continue;
} else if ( V_67 )
break;
} else {
int V_181 ;
if ( V_54 && V_154 == V_22 ) {
if ( F_6 ( V_8 , V_182 , V_154 ++ ) ) {
V_67 = - V_162 ;
V_154 -- ;
break;
}
V_69 -- ;
}
V_181 = F_160 ( V_8 , & V_154 , & V_69 ) ;
V_181 += F_160 ( V_8 , & V_154 , & V_69 ) ;
if ( V_181 ) {
V_67 = - V_162 ;
break;
}
}
F_24 ( V_8 ) ;
if ( V_154 - V_22 >= V_174 )
break;
if ( time )
V_175 = time ;
}
if ( V_73 != V_2 -> V_4 )
F_11 ( V_8 ) ;
F_85 ( & V_8 -> V_59 ) ;
F_181 ( & V_8 -> V_58 , & V_172 ) ;
if ( ! F_25 ( & V_8 -> V_58 ) )
V_2 -> V_127 = V_174 ;
F_54 ( & V_2 -> V_148 ) ;
if ( V_154 - V_22 )
V_67 = V_154 - V_22 ;
return V_67 ;
}
static T_3 F_182 ( struct V_7 * V_8 , struct V_164 * V_164 ,
const unsigned char * V_22 , T_1 V_69 )
{
const unsigned char * V_154 = V_22 ;
F_174 ( V_172 , V_173 ) ;
int V_45 ;
T_3 V_67 = 0 ;
if ( F_183 ( V_8 ) && V_164 -> V_166 -> V_65 != V_167 ) {
V_67 = F_184 ( V_8 ) ;
if ( V_67 )
return V_67 ;
}
F_87 ( & V_8 -> V_59 ) ;
F_59 ( V_8 ) ;
F_177 ( & V_8 -> V_41 , & V_172 ) ;
while ( 1 ) {
if ( F_179 ( V_133 ) ) {
V_67 = - V_171 ;
break;
}
if ( F_178 ( V_164 ) || ( V_8 -> V_35 && ! V_8 -> V_35 -> V_40 ) ) {
V_67 = - V_169 ;
break;
}
if ( F_57 ( V_8 ) ) {
while ( V_69 > 0 ) {
T_3 V_183 = F_55 ( V_8 , V_154 , V_69 ) ;
if ( V_183 < 0 ) {
if ( V_183 == - V_163 )
break;
V_67 = V_183 ;
goto V_71;
}
V_154 += V_183 ;
V_69 -= V_183 ;
if ( V_69 == 0 )
break;
V_45 = * V_154 ;
if ( F_51 ( V_45 , V_8 ) < 0 )
break;
V_154 ++ ; V_69 -- ;
}
if ( V_8 -> V_37 -> V_88 )
V_8 -> V_37 -> V_88 ( V_8 ) ;
} else {
struct V_1 * V_2 = V_8 -> V_11 ;
while ( V_69 > 0 ) {
F_52 ( & V_2 -> V_68 ) ;
V_45 = V_8 -> V_37 -> V_65 ( V_8 , V_154 , V_69 ) ;
F_54 ( & V_2 -> V_68 ) ;
if ( V_45 < 0 ) {
V_67 = V_45 ;
goto V_71;
}
if ( ! V_45 )
break;
V_154 += V_45 ;
V_69 -= V_45 ;
}
}
if ( ! V_69 )
break;
if ( V_164 -> V_176 & V_177 ) {
V_67 = - V_163 ;
break;
}
F_85 ( & V_8 -> V_59 ) ;
F_180 ( & V_172 , V_180 , V_178 ) ;
F_87 ( & V_8 -> V_59 ) ;
}
V_71:
F_181 ( & V_8 -> V_41 , & V_172 ) ;
if ( V_154 - V_22 != V_69 && V_8 -> V_26 )
F_120 ( V_27 , & V_8 -> V_20 ) ;
F_85 ( & V_8 -> V_59 ) ;
return ( V_154 - V_22 ) ? V_154 - V_22 : V_67 ;
}
static unsigned int F_185 ( struct V_7 * V_8 , struct V_164 * V_164 ,
T_4 * V_172 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
unsigned int V_184 = 0 ;
F_186 ( V_164 , & V_8 -> V_58 , V_172 ) ;
F_186 ( V_164 , & V_8 -> V_41 , V_172 ) ;
if ( F_158 ( V_8 ) )
V_184 |= V_185 ;
if ( F_155 ( V_8 , 1 ) )
V_184 |= V_100 | V_186 ;
if ( V_8 -> V_54 && V_8 -> V_35 -> V_56 )
V_184 |= V_187 | V_100 | V_186 ;
if ( F_178 ( V_164 ) )
V_184 |= V_185 ;
if ( ! ( V_184 & ( V_185 | V_100 | V_186 ) ) ) {
if ( F_157 ( V_8 ) && ! F_156 ( V_8 ) )
V_2 -> V_127 = F_157 ( V_8 ) ;
else
V_2 -> V_127 = 1 ;
}
if ( V_8 -> V_37 -> V_65 && ! F_187 ( V_8 ) &&
F_188 ( V_8 ) < V_188 &&
F_53 ( V_8 ) > 0 )
V_184 |= V_42 | V_189 ;
return V_184 ;
}
static unsigned long F_189 ( struct V_1 * V_2 )
{
T_1 V_69 , V_85 , V_73 ;
if ( V_2 -> V_25 == V_2 -> V_4 )
return 0 ;
V_85 = V_2 -> V_25 ;
V_73 = V_2 -> V_4 ;
V_69 = V_85 - V_73 ;
while ( V_85 != V_73 ) {
if ( F_14 ( V_73 & ( V_6 - 1 ) , V_2 -> V_52 ) &&
F_2 ( V_2 , V_73 ) == V_112 )
V_69 -- ;
V_73 ++ ;
}
return V_69 ;
}
static int F_190 ( struct V_7 * V_8 , struct V_164 * V_164 ,
unsigned int V_190 , unsigned long V_191 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
int V_67 ;
switch ( V_190 ) {
case V_192 :
return F_8 ( F_188 ( V_8 ) , ( int T_2 * ) V_191 ) ;
case V_193 :
F_36 ( & V_8 -> V_59 ) ;
if ( F_147 ( V_8 ) )
V_67 = F_189 ( V_2 ) ;
else
V_67 = F_1 ( V_2 ) ;
F_37 ( & V_8 -> V_59 ) ;
return F_8 ( V_67 , ( unsigned int T_2 * ) V_191 ) ;
default:
return F_191 ( V_8 , V_164 , V_190 , V_191 ) ;
}
}
static void F_192 ( struct V_7 * V_8 , int V_194 )
{
struct V_1 * V_2 = V_8 -> V_11 ;
if ( ! F_25 ( & V_8 -> V_58 ) ) {
if ( V_194 )
V_2 -> V_127 = 1 ;
else if ( ! V_8 -> V_26 )
V_2 -> V_127 = V_6 ;
}
}
void F_193 ( struct V_195 * V_37 )
{
* V_37 = V_196 ;
V_37 -> V_197 = NULL ;
V_37 -> V_198 = V_37 -> V_20 = 0 ;
}

static inline int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_2 , & V_3 , 1 , V_6 -> V_8 ) ;
return F_3 ( V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_9 ;
int V_10 ;
if ( F_5 ( V_2 ) ) {
V_9 = V_11 - V_6 -> V_12 * 3 - 1 ;
} else
V_9 = V_11 - V_6 -> V_12 - 1 ;
if ( V_9 <= 0 )
V_9 = V_6 -> V_8 && ! V_6 -> V_13 ;
V_10 = V_2 -> V_14 ;
V_2 -> V_14 = V_9 ;
if ( V_9 && ! V_10 ) {
F_6 ( V_2 -> V_15 -> V_16 == NULL ,
L_1 ) ;
F_7 ( & V_2 -> V_15 -> V_17 . V_18 ) ;
}
}
static void F_8 ( unsigned char V_19 , struct V_5 * V_6 )
{
if ( V_6 -> V_12 < V_11 ) {
V_6 -> V_20 [ V_6 -> V_21 ] = V_19 ;
V_6 -> V_21 = ( V_6 -> V_21 + 1 ) & ( V_11 - 1 ) ;
V_6 -> V_12 ++ ;
}
}
static void F_9 ( unsigned char V_19 , struct V_5 * V_6 )
{
unsigned long V_22 ;
F_10 ( & V_6 -> V_23 , V_22 ) ;
F_8 ( V_19 , V_6 ) ;
F_11 ( & V_6 -> V_23 , V_22 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 )
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_22 ;
F_10 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_21 = V_6 -> V_25 = V_6 -> V_12 = 0 ;
F_11 ( & V_6 -> V_23 , V_22 ) ;
F_15 ( & V_6 -> V_26 ) ;
V_6 -> V_27 = V_6 -> V_28 = V_6 -> V_29 = 0 ;
F_16 ( & V_6 -> V_26 ) ;
V_6 -> V_30 = V_6 -> V_13 = V_6 -> V_31 = 0 ;
F_17 ( V_6 -> V_32 , V_11 ) ;
F_4 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned long V_22 ;
F_14 ( V_2 ) ;
if ( ! V_2 -> V_33 )
return;
F_10 ( & V_2 -> V_34 , V_22 ) ;
if ( V_2 -> V_33 -> V_35 ) {
V_2 -> V_36 |= V_37 ;
F_19 ( & V_2 -> V_33 -> V_38 ) ;
}
F_11 ( & V_2 -> V_34 , V_22 ) ;
}
static T_2 F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_22 ;
T_2 V_39 = 0 ;
F_10 ( & V_6 -> V_23 , V_22 ) ;
if ( ! V_6 -> V_8 ) {
V_39 = V_6 -> V_12 ;
} else if ( V_6 -> V_13 ) {
V_39 = ( V_6 -> V_30 > V_6 -> V_25 ) ?
V_6 -> V_30 - V_6 -> V_25 :
V_6 -> V_30 + ( V_11 - V_6 -> V_25 ) ;
}
F_11 ( & V_6 -> V_23 , V_22 ) ;
return V_39 ;
}
static inline int F_21 ( unsigned char V_19 )
{
return ( V_19 & 0xc0 ) == 0x80 ;
}
static inline int F_22 ( unsigned char V_19 , struct V_1 * V_2 )
{
return F_23 ( V_2 ) && F_21 ( V_19 ) ;
}
static int F_24 ( unsigned char V_19 , struct V_1 * V_2 , int V_40 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_41 ;
if ( ! V_40 )
return - 1 ;
switch ( V_19 ) {
case '\n' :
if ( F_25 ( V_2 ) )
V_6 -> V_42 = 0 ;
if ( F_26 ( V_2 ) ) {
if ( V_40 < 2 )
return - 1 ;
V_6 -> V_43 = V_6 -> V_42 = 0 ;
V_2 -> V_44 -> V_45 ( V_2 , L_2 , 2 ) ;
return 2 ;
}
V_6 -> V_43 = V_6 -> V_42 ;
break;
case '\r' :
if ( F_27 ( V_2 ) && V_6 -> V_42 == 0 )
return 0 ;
if ( F_28 ( V_2 ) ) {
V_19 = '\n' ;
if ( F_25 ( V_2 ) )
V_6 -> V_43 = V_6 -> V_42 = 0 ;
break;
}
V_6 -> V_43 = V_6 -> V_42 = 0 ;
break;
case '\t' :
V_41 = 8 - ( V_6 -> V_42 & 7 ) ;
if ( F_29 ( V_2 ) == V_46 ) {
if ( V_40 < V_41 )
return - 1 ;
V_6 -> V_42 += V_41 ;
V_2 -> V_44 -> V_45 ( V_2 , L_3 , V_41 ) ;
return V_41 ;
}
V_6 -> V_42 += V_41 ;
break;
case '\b' :
if ( V_6 -> V_42 > 0 )
V_6 -> V_42 -- ;
break;
default:
if ( ! iscntrl ( V_19 ) ) {
if ( F_30 ( V_2 ) )
V_19 = toupper ( V_19 ) ;
if ( ! F_22 ( V_19 , V_2 ) )
V_6 -> V_42 ++ ;
}
break;
}
F_31 ( V_2 , V_19 ) ;
return 1 ;
}
static int F_32 ( unsigned char V_19 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 , V_47 ;
F_15 ( & V_6 -> V_48 ) ;
V_40 = F_33 ( V_2 ) ;
V_47 = F_24 ( V_19 , V_2 , V_40 ) ;
F_16 ( & V_6 -> V_48 ) ;
if ( V_47 < 0 )
return - 1 ;
else
return 0 ;
}
static T_2 F_34 ( struct V_1 * V_2 ,
const unsigned char * V_17 , unsigned int V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 ;
int V_50 ;
const unsigned char * V_51 ;
F_15 ( & V_6 -> V_48 ) ;
V_40 = F_33 ( V_2 ) ;
if ( ! V_40 ) {
F_16 ( & V_6 -> V_48 ) ;
return 0 ;
}
if ( V_49 > V_40 )
V_49 = V_40 ;
for ( V_50 = 0 , V_51 = V_17 ; V_50 < V_49 ; V_50 ++ , V_51 ++ ) {
unsigned char V_19 = * V_51 ;
switch ( V_19 ) {
case '\n' :
if ( F_25 ( V_2 ) )
V_6 -> V_42 = 0 ;
if ( F_26 ( V_2 ) )
goto V_52;
V_6 -> V_43 = V_6 -> V_42 ;
break;
case '\r' :
if ( F_27 ( V_2 ) && V_6 -> V_42 == 0 )
goto V_52;
if ( F_28 ( V_2 ) )
goto V_52;
V_6 -> V_43 = V_6 -> V_42 = 0 ;
break;
case '\t' :
goto V_52;
case '\b' :
if ( V_6 -> V_42 > 0 )
V_6 -> V_42 -- ;
break;
default:
if ( ! iscntrl ( V_19 ) ) {
if ( F_30 ( V_2 ) )
goto V_52;
if ( ! F_22 ( V_19 , V_2 ) )
V_6 -> V_42 ++ ;
}
break;
}
}
V_52:
V_50 = V_2 -> V_44 -> V_45 ( V_2 , V_17 , V_50 ) ;
F_16 ( & V_6 -> V_48 ) ;
return V_50 ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 , V_49 ;
unsigned char V_19 ;
unsigned char * V_51 , * V_53 ;
if ( ! V_6 -> V_28 )
return;
F_15 ( & V_6 -> V_48 ) ;
F_15 ( & V_6 -> V_26 ) ;
V_40 = F_33 ( V_2 ) ;
V_53 = V_6 -> V_54 + V_11 ;
V_51 = V_6 -> V_54 + V_6 -> V_27 ;
V_49 = V_6 -> V_28 ;
while ( V_49 > 0 ) {
V_19 = * V_51 ;
if ( V_19 == V_55 ) {
unsigned char V_56 ;
unsigned char * V_57 ;
int V_58 = 0 ;
V_57 = V_51 + 1 ;
if ( V_57 == V_53 )
V_57 -= V_11 ;
V_56 = * V_57 ;
switch ( V_56 ) {
unsigned int V_59 , V_60 ;
case V_61 :
if ( ++ V_57 == V_53 )
V_57 -= V_11 ;
V_59 = * V_57 ;
if ( ! ( V_59 & 0x80 ) )
V_59 += V_6 -> V_43 ;
V_60 = 8 - ( V_59 & 7 ) ;
if ( V_60 > V_40 ) {
V_58 = 1 ;
break;
}
V_40 -= V_60 ;
while ( V_60 -- ) {
F_31 ( V_2 , '\b' ) ;
if ( V_6 -> V_42 > 0 )
V_6 -> V_42 -- ;
}
V_51 += 3 ;
V_49 -= 3 ;
break;
case V_62 :
V_6 -> V_43 = V_6 -> V_42 ;
V_51 += 2 ;
V_49 -= 2 ;
break;
case V_63 :
if ( V_6 -> V_42 > 0 )
V_6 -> V_42 -- ;
V_51 += 2 ;
V_49 -= 2 ;
break;
case V_55 :
if ( ! V_40 ) {
V_58 = 1 ;
break;
}
F_31 ( V_2 , V_55 ) ;
V_6 -> V_42 ++ ;
V_40 -- ;
V_51 += 2 ;
V_49 -= 2 ;
break;
default:
if ( V_40 < 2 ) {
V_58 = 1 ;
break;
}
F_31 ( V_2 , '^' ) ;
F_31 ( V_2 , V_56 ^ 0100 ) ;
V_6 -> V_42 += 2 ;
V_40 -= 2 ;
V_51 += 2 ;
V_49 -= 2 ;
}
if ( V_58 )
break;
} else {
if ( F_36 ( V_2 ) &&
! ( F_37 ( V_64 , & V_2 -> V_22 ) ) ) {
int V_47 = F_24 ( V_19 , V_2 , V_40 ) ;
if ( V_47 < 0 )
break;
V_40 -= V_47 ;
} else {
if ( ! V_40 )
break;
F_31 ( V_2 , V_19 ) ;
V_40 -= 1 ;
}
V_51 += 1 ;
V_49 -= 1 ;
}
if ( V_51 >= V_53 )
V_51 -= V_11 ;
}
if ( V_49 == 0 ) {
V_6 -> V_27 = 0 ;
V_6 -> V_28 = 0 ;
V_6 -> V_29 = 0 ;
} else {
int V_65 = V_6 -> V_28 - V_49 ;
V_6 -> V_27 += V_65 ;
V_6 -> V_27 &= V_11 - 1 ;
V_6 -> V_28 = V_49 ;
if ( V_65 > 0 )
V_6 -> V_29 = 0 ;
}
F_16 ( & V_6 -> V_26 ) ;
F_16 ( & V_6 -> V_48 ) ;
if ( V_2 -> V_44 -> V_66 )
V_2 -> V_44 -> V_66 ( V_2 ) ;
}
static void F_38 ( unsigned char V_19 , struct V_5 * V_6 )
{
int V_67 ;
if ( V_6 -> V_28 == V_11 ) {
V_67 = V_6 -> V_27 ;
if ( V_6 -> V_54 [ V_6 -> V_27 ] == V_55 ) {
if ( V_6 -> V_54 [ ( V_6 -> V_27 + 1 ) &
( V_11 - 1 ) ] ==
V_61 ) {
V_6 -> V_27 += 3 ;
V_6 -> V_28 -= 2 ;
} else {
V_6 -> V_27 += 2 ;
V_6 -> V_28 -= 1 ;
}
} else {
V_6 -> V_27 ++ ;
}
V_6 -> V_27 &= V_11 - 1 ;
V_6 -> V_29 = 1 ;
} else {
V_67 = V_6 -> V_27 + V_6 -> V_28 ;
V_67 &= V_11 - 1 ;
V_6 -> V_28 ++ ;
}
V_6 -> V_54 [ V_67 ] = V_19 ;
}
static void F_39 ( struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_26 ) ;
F_38 ( V_55 , V_6 ) ;
F_38 ( V_63 , V_6 ) ;
F_16 ( & V_6 -> V_26 ) ;
}
static void F_40 ( struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_26 ) ;
F_38 ( V_55 , V_6 ) ;
F_38 ( V_62 , V_6 ) ;
F_16 ( & V_6 -> V_26 ) ;
}
static void F_41 ( unsigned int V_59 , int V_68 ,
struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_26 ) ;
F_38 ( V_55 , V_6 ) ;
F_38 ( V_61 , V_6 ) ;
V_59 &= 7 ;
if ( V_68 )
V_59 |= 0x80 ;
F_38 ( V_59 , V_6 ) ;
F_16 ( & V_6 -> V_26 ) ;
}
static void F_42 ( unsigned char V_19 , struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_26 ) ;
if ( V_19 == V_55 ) {
F_38 ( V_55 , V_6 ) ;
F_38 ( V_55 , V_6 ) ;
} else {
F_38 ( V_19 , V_6 ) ;
}
F_16 ( & V_6 -> V_26 ) ;
}
static void F_43 ( unsigned char V_19 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_15 ( & V_6 -> V_26 ) ;
if ( V_19 == V_55 ) {
F_38 ( V_55 , V_6 ) ;
F_38 ( V_55 , V_6 ) ;
} else {
if ( F_44 ( V_2 ) && iscntrl ( V_19 ) && V_19 != '\t' )
F_38 ( V_55 , V_6 ) ;
F_38 ( V_19 , V_6 ) ;
}
F_16 ( & V_6 -> V_26 ) ;
}
static inline void F_45 ( struct V_5 * V_6 )
{
if ( V_6 -> V_31 ) {
F_42 ( '/' , V_6 ) ;
V_6 -> V_31 = 0 ;
}
}
static void F_46 ( unsigned char V_19 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
enum { V_69 , V_70 , V_71 } V_72 ;
int V_73 , V_74 , V_75 ;
unsigned long V_22 ;
if ( V_6 -> V_21 == V_6 -> V_30 ) {
return;
}
if ( V_19 == F_47 ( V_2 ) )
V_72 = V_69 ;
else if ( V_19 == F_48 ( V_2 ) )
V_72 = V_70 ;
else {
if ( ! F_49 ( V_2 ) ) {
F_10 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_12 -= ( ( V_6 -> V_21 - V_6 -> V_30 ) &
( V_11 - 1 ) ) ;
V_6 -> V_21 = V_6 -> V_30 ;
F_11 ( & V_6 -> V_23 , V_22 ) ;
return;
}
if ( ! F_50 ( V_2 ) || ! F_51 ( V_2 ) || ! F_52 ( V_2 ) ) {
F_10 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_12 -= ( ( V_6 -> V_21 - V_6 -> V_30 ) &
( V_11 - 1 ) ) ;
V_6 -> V_21 = V_6 -> V_30 ;
F_11 ( & V_6 -> V_23 , V_22 ) ;
F_45 ( V_6 ) ;
F_43 ( F_53 ( V_2 ) , V_2 ) ;
if ( F_50 ( V_2 ) )
F_42 ( '\n' , V_6 ) ;
return;
}
V_72 = V_71 ;
}
V_74 = 0 ;
while ( V_6 -> V_21 != V_6 -> V_30 ) {
V_73 = V_6 -> V_21 ;
do {
V_73 = ( V_73 - 1 ) & ( V_11 - 1 ) ;
V_19 = V_6 -> V_20 [ V_73 ] ;
} while ( F_22 ( V_19 , V_2 ) && V_73 != V_6 -> V_30 );
if ( F_22 ( V_19 , V_2 ) )
break;
if ( V_72 == V_70 ) {
if ( isalnum ( V_19 ) || V_19 == '_' )
V_74 ++ ;
else if ( V_74 )
break;
}
V_75 = ( V_6 -> V_21 - V_73 ) & ( V_11 - 1 ) ;
F_10 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_21 = V_73 ;
V_6 -> V_12 -= V_75 ;
F_11 ( & V_6 -> V_23 , V_22 ) ;
if ( F_49 ( V_2 ) ) {
if ( F_54 ( V_2 ) ) {
if ( ! V_6 -> V_31 ) {
F_42 ( '\\' , V_6 ) ;
V_6 -> V_31 = 1 ;
}
F_43 ( V_19 , V_2 ) ;
while ( -- V_75 > 0 ) {
V_73 = ( V_73 + 1 ) & ( V_11 - 1 ) ;
F_42 ( V_6 -> V_20 [ V_73 ] ,
V_6 ) ;
F_39 ( V_6 ) ;
}
} else if ( V_72 == V_69 && ! F_52 ( V_2 ) ) {
F_43 ( F_47 ( V_2 ) , V_2 ) ;
} else if ( V_19 == '\t' ) {
unsigned int V_59 = 0 ;
int V_68 = 0 ;
unsigned long V_76 = V_6 -> V_21 ;
while ( V_76 != V_6 -> V_30 ) {
V_76 = ( V_76 - 1 ) & ( V_11 - 1 ) ;
V_19 = V_6 -> V_20 [ V_76 ] ;
if ( V_19 == '\t' ) {
V_68 = 1 ;
break;
} else if ( iscntrl ( V_19 ) ) {
if ( F_44 ( V_2 ) )
V_59 += 2 ;
} else if ( ! F_22 ( V_19 , V_2 ) ) {
V_59 ++ ;
}
}
F_41 ( V_59 , V_68 , V_6 ) ;
} else {
if ( iscntrl ( V_19 ) && F_44 ( V_2 ) ) {
F_42 ( '\b' , V_6 ) ;
F_42 ( ' ' , V_6 ) ;
F_42 ( '\b' , V_6 ) ;
}
if ( ! iscntrl ( V_19 ) || F_44 ( V_2 ) ) {
F_42 ( '\b' , V_6 ) ;
F_42 ( ' ' , V_6 ) ;
F_42 ( '\b' , V_6 ) ;
}
}
}
if ( V_72 == V_69 )
break;
}
if ( V_6 -> V_21 == V_6 -> V_30 && F_49 ( V_2 ) )
F_45 ( V_6 ) ;
}
static inline void F_55 ( int V_77 , struct V_1 * V_2 , int V_78 )
{
if ( V_2 -> V_79 )
F_56 ( V_2 -> V_79 , V_77 , 1 ) ;
if ( V_78 || ! F_57 ( V_2 ) ) {
F_18 ( V_2 ) ;
F_58 ( V_2 ) ;
}
}
static inline void F_59 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_60 ( V_2 ) )
return;
if ( F_61 ( V_2 ) ) {
F_55 ( V_80 , V_2 , 1 ) ;
return;
}
if ( F_5 ( V_2 ) ) {
F_9 ( '\377' , V_6 ) ;
F_9 ( '\0' , V_6 ) ;
}
F_9 ( '\0' , V_6 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static inline void F_62 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
char V_17 [ 64 ] ;
V_6 -> V_81 ++ ;
if ( F_63 ( V_82 , V_6 -> V_83 + V_84 ) ||
F_63 ( V_6 -> V_83 , V_82 ) ) {
F_64 ( V_85 L_4 ,
F_65 ( V_2 , V_17 ) ,
V_6 -> V_81 ) ;
V_6 -> V_83 = V_82 ;
V_6 -> V_81 = 0 ;
}
}
static inline void F_66 ( struct V_1 * V_2 ,
unsigned char V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_67 ( V_2 ) )
return;
if ( F_5 ( V_2 ) ) {
F_9 ( '\377' , V_6 ) ;
F_9 ( '\0' , V_6 ) ;
F_9 ( V_19 , V_6 ) ;
} else if ( F_68 ( V_2 ) )
F_9 ( '\0' , V_6 ) ;
else
F_9 ( V_19 , V_6 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static inline void F_69 ( struct V_1 * V_2 , unsigned char V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_22 ;
int V_86 ;
if ( V_6 -> V_87 ) {
F_9 ( V_19 , V_6 ) ;
return;
}
if ( F_70 ( V_2 ) )
V_19 &= 0x7f ;
if ( F_71 ( V_2 ) && F_72 ( V_2 ) )
V_19 = tolower ( V_19 ) ;
if ( F_73 ( V_2 ) ) {
F_9 ( V_19 , V_6 ) ;
return;
}
if ( V_2 -> V_88 && ! V_2 -> V_89 && F_74 ( V_2 ) &&
F_75 ( V_2 ) && V_19 != F_76 ( V_2 ) && V_19 != F_77 ( V_2 ) &&
V_19 != F_78 ( V_2 ) && V_19 != F_79 ( V_2 ) && V_19 != F_80 ( V_2 ) ) {
F_81 ( V_2 ) ;
F_35 ( V_2 ) ;
}
if ( V_2 -> V_90 ) {
if ( F_74 ( V_2 ) ) {
if ( V_19 == F_76 ( V_2 ) ) {
F_81 ( V_2 ) ;
F_35 ( V_2 ) ;
} else if ( V_19 == F_77 ( V_2 ) )
F_82 ( V_2 ) ;
}
return;
}
if ( ! F_37 ( V_19 , V_6 -> V_91 ) || V_6 -> V_92 ) {
V_6 -> V_92 = 0 ;
V_86 = ( V_19 == ( unsigned char ) '\377' && F_5 ( V_2 ) ) ? 1 : 0 ;
if ( V_6 -> V_12 >= ( V_11 - V_86 - 1 ) ) {
if ( F_49 ( V_2 ) )
F_32 ( '\a' , V_2 ) ;
return;
}
if ( F_49 ( V_2 ) ) {
F_45 ( V_6 ) ;
if ( V_6 -> V_30 == V_6 -> V_21 )
F_40 ( V_6 ) ;
F_43 ( V_19 , V_2 ) ;
F_35 ( V_2 ) ;
}
if ( V_86 )
F_9 ( V_19 , V_6 ) ;
F_9 ( V_19 , V_6 ) ;
return;
}
if ( F_74 ( V_2 ) ) {
if ( V_19 == F_76 ( V_2 ) ) {
F_81 ( V_2 ) ;
F_35 ( V_2 ) ;
return;
}
if ( V_19 == F_77 ( V_2 ) ) {
F_82 ( V_2 ) ;
return;
}
}
if ( F_83 ( V_2 ) ) {
int signal ;
signal = V_80 ;
if ( V_19 == F_78 ( V_2 ) )
goto V_93;
signal = V_94 ;
if ( V_19 == F_79 ( V_2 ) )
goto V_93;
signal = V_95 ;
if ( V_19 == F_80 ( V_2 ) ) {
V_93:
if ( ! F_57 ( V_2 ) ) {
F_18 ( V_2 ) ;
F_58 ( V_2 ) ;
}
if ( F_74 ( V_2 ) )
F_81 ( V_2 ) ;
if ( F_49 ( V_2 ) ) {
F_43 ( V_19 , V_2 ) ;
F_35 ( V_2 ) ;
}
if ( V_2 -> V_79 )
F_56 ( V_2 -> V_79 , signal , 1 ) ;
return;
}
}
if ( V_19 == '\r' ) {
if ( F_84 ( V_2 ) )
return;
if ( F_85 ( V_2 ) )
V_19 = '\n' ;
} else if ( V_19 == '\n' && F_86 ( V_2 ) )
V_19 = '\r' ;
if ( V_6 -> V_8 ) {
if ( V_19 == F_47 ( V_2 ) || V_19 == F_53 ( V_2 ) ||
( V_19 == F_48 ( V_2 ) && F_72 ( V_2 ) ) ) {
F_46 ( V_19 , V_2 ) ;
F_35 ( V_2 ) ;
return;
}
if ( V_19 == F_87 ( V_2 ) && F_72 ( V_2 ) ) {
V_6 -> V_92 = 1 ;
if ( F_49 ( V_2 ) ) {
F_45 ( V_6 ) ;
if ( F_44 ( V_2 ) ) {
F_42 ( '^' , V_6 ) ;
F_42 ( '\b' , V_6 ) ;
F_35 ( V_2 ) ;
}
}
return;
}
if ( V_19 == F_88 ( V_2 ) && F_49 ( V_2 ) &&
F_72 ( V_2 ) ) {
unsigned long V_76 = V_6 -> V_30 ;
F_45 ( V_6 ) ;
F_43 ( V_19 , V_2 ) ;
F_42 ( '\n' , V_6 ) ;
while ( V_76 != V_6 -> V_21 ) {
F_43 ( V_6 -> V_20 [ V_76 ] , V_2 ) ;
V_76 = ( V_76 + 1 ) & ( V_11 - 1 ) ;
}
F_35 ( V_2 ) ;
return;
}
if ( V_19 == '\n' ) {
if ( V_6 -> V_12 >= V_11 ) {
if ( F_49 ( V_2 ) )
F_32 ( '\a' , V_2 ) ;
return;
}
if ( F_49 ( V_2 ) || F_89 ( V_2 ) ) {
F_42 ( '\n' , V_6 ) ;
F_35 ( V_2 ) ;
}
goto V_96;
}
if ( V_19 == F_90 ( V_2 ) ) {
if ( V_6 -> V_12 >= V_11 )
return;
if ( V_6 -> V_30 != V_6 -> V_21 )
F_91 ( V_97 , & V_2 -> V_22 ) ;
V_19 = V_98 ;
goto V_96;
}
if ( ( V_19 == F_92 ( V_2 ) ) ||
( V_19 == F_93 ( V_2 ) && F_72 ( V_2 ) ) ) {
V_86 = ( V_19 == ( unsigned char ) '\377' && F_5 ( V_2 ) )
? 1 : 0 ;
if ( V_6 -> V_12 >= ( V_11 - V_86 ) ) {
if ( F_49 ( V_2 ) )
F_32 ( '\a' , V_2 ) ;
return;
}
if ( F_49 ( V_2 ) ) {
if ( V_6 -> V_30 == V_6 -> V_21 )
F_40 ( V_6 ) ;
F_43 ( V_19 , V_2 ) ;
F_35 ( V_2 ) ;
}
if ( V_86 )
F_9 ( V_19 , V_6 ) ;
V_96:
F_10 ( & V_6 -> V_23 , V_22 ) ;
F_91 ( V_6 -> V_21 , V_6 -> V_32 ) ;
F_8 ( V_19 , V_6 ) ;
V_6 -> V_30 = V_6 -> V_21 ;
V_6 -> V_13 ++ ;
F_11 ( & V_6 -> V_23 , V_22 ) ;
F_94 ( & V_2 -> V_99 , V_100 , V_101 ) ;
if ( F_95 ( & V_2 -> V_38 ) )
F_19 ( & V_2 -> V_38 ) ;
return;
}
}
V_86 = ( V_19 == ( unsigned char ) '\377' && F_5 ( V_2 ) ) ? 1 : 0 ;
if ( V_6 -> V_12 >= ( V_11 - V_86 - 1 ) ) {
if ( F_49 ( V_2 ) )
F_32 ( '\a' , V_2 ) ;
return;
}
if ( F_49 ( V_2 ) ) {
F_45 ( V_6 ) ;
if ( V_19 == '\n' )
F_42 ( '\n' , V_6 ) ;
else {
if ( V_6 -> V_30 == V_6 -> V_21 )
F_40 ( V_6 ) ;
F_43 ( V_19 , V_2 ) ;
}
F_35 ( V_2 ) ;
}
if ( V_86 )
F_9 ( V_19 , V_6 ) ;
F_9 ( V_19 , V_6 ) ;
}
static void F_96 ( struct V_1 * V_2 )
{
if ( V_2 -> V_99 && F_97 ( V_102 , & V_2 -> V_22 ) )
F_94 ( & V_2 -> V_99 , V_100 , V_103 ) ;
}
static void F_98 ( struct V_1 * V_2 , const unsigned char * V_51 ,
char * V_104 , int V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const unsigned char * V_105 ;
char * V_106 , V_22 = V_107 ;
int V_50 ;
char V_17 [ 64 ] ;
unsigned long V_108 ;
if ( V_6 -> V_109 ) {
F_10 ( & V_6 -> V_23 , V_108 ) ;
V_50 = F_99 ( V_11 - V_6 -> V_12 ,
V_11 - V_6 -> V_21 ) ;
V_50 = F_99 ( V_24 , V_50 ) ;
memcpy ( V_6 -> V_20 + V_6 -> V_21 , V_51 , V_50 ) ;
V_6 -> V_21 = ( V_6 -> V_21 + V_50 ) & ( V_11 - 1 ) ;
V_6 -> V_12 += V_50 ;
V_51 += V_50 ;
V_24 -= V_50 ;
V_50 = F_99 ( V_11 - V_6 -> V_12 ,
V_11 - V_6 -> V_21 ) ;
V_50 = F_99 ( V_24 , V_50 ) ;
memcpy ( V_6 -> V_20 + V_6 -> V_21 , V_51 , V_50 ) ;
V_6 -> V_21 = ( V_6 -> V_21 + V_50 ) & ( V_11 - 1 ) ;
V_6 -> V_12 += V_50 ;
F_11 ( & V_6 -> V_23 , V_108 ) ;
} else {
for ( V_50 = V_24 , V_105 = V_51 , V_106 = V_104 ; V_50 ; V_50 -- , V_105 ++ ) {
if ( V_106 )
V_22 = * V_106 ++ ;
switch ( V_22 ) {
case V_107 :
F_69 ( V_2 , * V_105 ) ;
break;
case V_110 :
F_59 ( V_2 ) ;
break;
case V_111 :
case V_112 :
F_66 ( V_2 , * V_105 ) ;
break;
case V_113 :
F_62 ( V_2 ) ;
break;
default:
F_64 ( V_114 L_5 ,
F_65 ( V_2 , V_17 ) , V_22 ) ;
break;
}
}
if ( V_2 -> V_44 -> V_66 )
V_2 -> V_44 -> V_66 ( V_2 ) ;
}
F_4 ( V_2 ) ;
if ( ( ! V_6 -> V_8 && ( V_6 -> V_12 >= V_2 -> V_115 ) ) ||
F_73 ( V_2 ) ) {
F_94 ( & V_2 -> V_99 , V_100 , V_101 ) ;
if ( F_95 ( & V_2 -> V_38 ) )
F_19 ( & V_2 -> V_38 ) ;
}
if ( V_2 -> V_14 < V_116 )
F_100 ( V_2 ) ;
}
int F_101 ( int V_77 )
{
return ( F_102 ( & V_117 -> V_118 , V_77 ) ||
V_117 -> V_119 -> V_120 [ V_77 - 1 ] . V_121 . V_122 == V_123 ) ;
}
static void F_103 ( struct V_1 * V_2 , struct V_124 * V_125 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_126 = 1 ;
if ( V_125 )
V_126 = ( V_125 -> V_127 ^ V_2 -> V_128 . V_127 ) & V_129 ;
if ( V_126 ) {
F_17 ( V_6 -> V_32 , V_11 ) ;
V_6 -> V_30 = V_6 -> V_25 ;
V_6 -> V_13 = 0 ;
V_6 -> V_31 = 0 ;
}
if ( V_126 && ! F_104 ( V_2 ) && V_6 -> V_12 )
F_19 ( & V_2 -> V_38 ) ;
V_6 -> V_8 = ( F_104 ( V_2 ) != 0 ) ;
if ( F_37 ( V_130 , & V_2 -> V_22 ) ) {
V_6 -> V_87 = 1 ;
V_6 -> V_109 = 1 ;
F_4 ( V_2 ) ;
return;
}
if ( F_70 ( V_2 ) || F_71 ( V_2 ) || F_84 ( V_2 ) ||
F_85 ( V_2 ) || F_86 ( V_2 ) || F_104 ( V_2 ) ||
F_74 ( V_2 ) || F_83 ( V_2 ) || F_49 ( V_2 ) ||
F_5 ( V_2 ) ) {
F_17 ( V_6 -> V_91 , 256 ) ;
if ( F_84 ( V_2 ) || F_85 ( V_2 ) )
F_91 ( '\r' , V_6 -> V_91 ) ;
if ( F_86 ( V_2 ) )
F_91 ( '\n' , V_6 -> V_91 ) ;
if ( F_104 ( V_2 ) ) {
F_91 ( F_47 ( V_2 ) , V_6 -> V_91 ) ;
F_91 ( F_53 ( V_2 ) , V_6 -> V_91 ) ;
F_91 ( F_90 ( V_2 ) , V_6 -> V_91 ) ;
F_91 ( '\n' , V_6 -> V_91 ) ;
F_91 ( F_92 ( V_2 ) , V_6 -> V_91 ) ;
if ( F_72 ( V_2 ) ) {
F_91 ( F_48 ( V_2 ) ,
V_6 -> V_91 ) ;
F_91 ( F_87 ( V_2 ) ,
V_6 -> V_91 ) ;
F_91 ( F_93 ( V_2 ) ,
V_6 -> V_91 ) ;
if ( F_49 ( V_2 ) )
F_91 ( F_88 ( V_2 ) ,
V_6 -> V_91 ) ;
}
}
if ( F_74 ( V_2 ) ) {
F_91 ( F_76 ( V_2 ) , V_6 -> V_91 ) ;
F_91 ( F_77 ( V_2 ) , V_6 -> V_91 ) ;
}
if ( F_83 ( V_2 ) ) {
F_91 ( F_78 ( V_2 ) , V_6 -> V_91 ) ;
F_91 ( F_79 ( V_2 ) , V_6 -> V_91 ) ;
F_91 ( F_80 ( V_2 ) , V_6 -> V_91 ) ;
}
F_105 ( V_98 , V_6 -> V_91 ) ;
V_6 -> V_87 = 0 ;
V_6 -> V_109 = 0 ;
} else {
V_6 -> V_87 = 1 ;
if ( ( F_60 ( V_2 ) || ( ! F_61 ( V_2 ) && ! F_5 ( V_2 ) ) ) &&
( F_67 ( V_2 ) || ! F_68 ( V_2 ) ) &&
( V_2 -> V_131 -> V_22 & V_132 ) )
V_6 -> V_109 = 1 ;
else
V_6 -> V_109 = 0 ;
}
F_4 ( V_2 ) ;
F_19 ( & V_2 -> V_133 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_18 ( V_2 ) ;
F_107 ( V_6 -> V_20 ) ;
F_107 ( V_6 -> V_54 ) ;
F_107 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_109 ( sizeof( * V_6 ) , V_134 ) ;
if ( ! V_6 )
goto V_135;
V_6 -> V_83 = V_82 ;
F_110 ( & V_6 -> V_136 ) ;
F_110 ( & V_6 -> V_48 ) ;
F_110 ( & V_6 -> V_26 ) ;
F_111 ( & V_6 -> V_23 ) ;
V_6 -> V_20 = F_109 ( V_11 , V_134 ) ;
V_6 -> V_54 = F_109 ( V_11 , V_134 ) ;
if ( ! V_6 -> V_20 || ! V_6 -> V_54 )
goto V_137;
V_2 -> V_7 = V_6 ;
F_14 ( V_2 ) ;
F_13 ( V_2 ) ;
V_6 -> V_42 = 0 ;
F_103 ( V_2 , NULL ) ;
V_2 -> V_115 = 1 ;
V_2 -> V_90 = 0 ;
return 0 ;
V_137:
F_107 ( V_6 -> V_20 ) ;
F_107 ( V_6 -> V_54 ) ;
F_107 ( V_6 ) ;
V_135:
return - V_138 ;
}
static inline int F_112 ( struct V_1 * V_2 , int V_139 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_113 ( V_2 ) ;
if ( V_6 -> V_8 && ! F_73 ( V_2 ) ) {
if ( V_6 -> V_13 )
return 1 ;
} else if ( V_6 -> V_12 >= ( V_139 ? V_139 : 1 ) )
return 1 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 ,
unsigned char T_1 * * V_140 ,
T_3 * V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_47 ;
T_3 V_39 ;
unsigned long V_22 ;
bool V_141 ;
V_47 = 0 ;
F_10 ( & V_6 -> V_23 , V_22 ) ;
V_39 = F_99 ( V_6 -> V_12 , V_11 - V_6 -> V_25 ) ;
V_39 = F_99 ( * V_49 , V_39 ) ;
F_11 ( & V_6 -> V_23 , V_22 ) ;
if ( V_39 ) {
V_47 = F_115 ( * V_140 , & V_6 -> V_20 [ V_6 -> V_25 ] , V_39 ) ;
V_39 -= V_47 ;
V_141 = V_39 == 1 &&
V_6 -> V_20 [ V_6 -> V_25 ] == F_90 ( V_2 ) ;
F_2 ( V_2 , & V_6 -> V_20 [ V_6 -> V_25 ] , V_39 ,
V_6 -> V_8 ) ;
F_10 ( & V_6 -> V_23 , V_22 ) ;
V_6 -> V_25 = ( V_6 -> V_25 + V_39 ) & ( V_11 - 1 ) ;
V_6 -> V_12 -= V_39 ;
if ( F_73 ( V_2 ) && V_6 -> V_8 && V_141 && ! V_6 -> V_12 )
V_39 = 0 ;
F_11 ( & V_6 -> V_23 , V_22 ) ;
* V_140 += V_39 ;
* V_49 -= V_39 ;
}
return V_47 ;
}
static int F_116 ( struct V_1 * V_2 , struct V_142 * V_142 )
{
if ( V_142 -> V_143 -> V_45 != V_144 &&
V_117 -> signal -> V_2 == V_2 ) {
if ( ! V_2 -> V_79 )
F_64 ( V_114 L_6 ) ;
else if ( F_117 ( V_117 ) != V_2 -> V_79 ) {
if ( F_101 ( V_145 ) ||
F_118 () )
return - V_146 ;
F_56 ( F_117 ( V_117 ) , V_145 , 1 ) ;
F_119 ( V_147 ) ;
return - V_148 ;
}
}
return 0 ;
}
static T_2 F_120 ( struct V_1 * V_2 , struct V_142 * V_142 ,
unsigned char T_1 * V_17 , T_3 V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char T_1 * V_140 = V_17 ;
F_121 ( V_149 , V_117 ) ;
int V_19 ;
int V_150 , time ;
T_2 V_47 = 0 ;
T_2 V_151 ;
long V_152 ;
unsigned long V_22 ;
int V_35 ;
V_153:
V_19 = F_116 ( V_2 , V_142 ) ;
if ( V_19 < 0 )
return V_19 ;
V_150 = time = 0 ;
V_152 = V_154 ;
if ( ! V_6 -> V_8 ) {
time = ( V_84 / 10 ) * F_122 ( V_2 ) ;
V_150 = F_123 ( V_2 ) ;
if ( V_150 ) {
if ( time )
V_2 -> V_115 = 1 ;
else if ( ! F_95 ( & V_2 -> V_38 ) ||
( V_2 -> V_115 > V_150 ) )
V_2 -> V_115 = V_150 ;
} else {
V_152 = 0 ;
if ( time ) {
V_152 = time ;
time = 0 ;
}
V_2 -> V_115 = V_150 = 1 ;
}
}
if ( V_142 -> V_155 & V_156 ) {
if ( ! F_124 ( & V_6 -> V_136 ) )
return - V_157 ;
} else {
if ( F_125 ( & V_6 -> V_136 ) )
return - V_148 ;
}
V_35 = V_2 -> V_35 ;
F_126 ( & V_2 -> V_38 , & V_149 ) ;
while ( V_49 ) {
if ( V_35 && V_2 -> V_33 -> V_36 ) {
unsigned char V_158 ;
if ( V_140 != V_17 )
break;
F_10 ( & V_2 -> V_33 -> V_34 , V_22 ) ;
V_158 = V_2 -> V_33 -> V_36 ;
V_2 -> V_33 -> V_36 = 0 ;
F_11 ( & V_2 -> V_33 -> V_34 , V_22 ) ;
if ( F_1 ( V_2 , V_158 , V_140 ++ ) ) {
V_47 = - V_159 ;
V_140 -- ;
break;
}
V_49 -- ;
break;
}
F_127 ( V_160 ) ;
if ( ( ( V_150 - ( V_140 - V_17 ) ) < V_2 -> V_115 ) &&
( ( V_150 - ( V_140 - V_17 ) ) >= 1 ) )
V_2 -> V_115 = ( V_150 - ( V_140 - V_17 ) ) ;
if ( ! F_112 ( V_2 , 0 ) ) {
if ( F_37 ( V_161 , & V_2 -> V_22 ) ) {
V_47 = - V_146 ;
break;
}
if ( F_128 ( V_142 ) )
break;
if ( ! V_152 )
break;
if ( V_142 -> V_155 & V_156 ) {
V_47 = - V_157 ;
break;
}
if ( F_129 ( V_117 ) ) {
V_47 = - V_148 ;
break;
}
F_4 ( V_2 ) ;
V_152 = F_130 ( V_152 ) ;
continue;
}
F_131 ( V_162 ) ;
if ( V_35 && V_140 == V_17 ) {
if ( F_1 ( V_2 , V_163 , V_140 ++ ) ) {
V_47 = - V_159 ;
V_140 -- ;
break;
}
V_49 -- ;
}
if ( V_6 -> V_8 && ! F_73 ( V_2 ) ) {
F_10 ( & V_6 -> V_23 , V_22 ) ;
while ( V_49 && V_6 -> V_12 ) {
int V_164 ;
V_164 = F_97 ( V_6 -> V_25 ,
V_6 -> V_32 ) ;
V_19 = V_6 -> V_20 [ V_6 -> V_25 ] ;
V_6 -> V_25 = ( ( V_6 -> V_25 + 1 ) &
( V_11 - 1 ) ) ;
V_6 -> V_12 -- ;
if ( V_164 ) {
if ( -- V_6 -> V_13 < 0 )
V_6 -> V_13 = 0 ;
}
F_11 ( & V_6 -> V_23 , V_22 ) ;
if ( ! V_164 || ( V_19 != V_98 ) ) {
if ( F_1 ( V_2 , V_19 , V_140 ++ ) ) {
V_47 = - V_159 ;
V_140 -- ;
F_10 ( & V_6 -> V_23 , V_22 ) ;
break;
}
V_49 -- ;
}
if ( V_164 ) {
F_132 ( V_2 ) ;
F_10 ( & V_6 -> V_23 , V_22 ) ;
break;
}
F_10 ( & V_6 -> V_23 , V_22 ) ;
}
F_11 ( & V_6 -> V_23 , V_22 ) ;
if ( V_47 )
break;
} else {
int V_165 ;
V_165 = F_114 ( V_2 , & V_140 , & V_49 ) ;
V_165 += F_114 ( V_2 , & V_140 , & V_49 ) ;
if ( V_165 ) {
V_47 = - V_159 ;
break;
}
}
if ( F_20 ( V_2 ) <= V_166 ) {
F_4 ( V_2 ) ;
F_12 ( V_2 ) ;
}
if ( V_140 - V_17 >= V_150 )
break;
if ( time )
V_152 = time ;
}
F_16 ( & V_6 -> V_136 ) ;
F_133 ( & V_2 -> V_38 , & V_149 ) ;
if ( ! F_95 ( & V_2 -> V_38 ) )
V_2 -> V_115 = V_150 ;
F_131 ( V_162 ) ;
V_151 = V_140 - V_17 ;
if ( V_151 ) {
V_47 = V_151 ;
if ( V_49 )
F_105 ( V_97 , & V_2 -> V_22 ) ;
} else if ( F_97 ( V_97 , & V_2 -> V_22 ) )
goto V_153;
F_4 ( V_2 ) ;
return V_47 ;
}
static T_2 F_134 ( struct V_1 * V_2 , struct V_142 * V_142 ,
const unsigned char * V_17 , T_3 V_49 )
{
const unsigned char * V_140 = V_17 ;
F_121 ( V_149 , V_117 ) ;
int V_19 ;
T_2 V_47 = 0 ;
if ( F_135 ( V_2 ) && V_142 -> V_143 -> V_45 != V_144 ) {
V_47 = F_136 ( V_2 ) ;
if ( V_47 )
return V_47 ;
}
F_35 ( V_2 ) ;
F_126 ( & V_2 -> V_133 , & V_149 ) ;
while ( 1 ) {
F_127 ( V_160 ) ;
if ( F_129 ( V_117 ) ) {
V_47 = - V_148 ;
break;
}
if ( F_128 ( V_142 ) || ( V_2 -> V_33 && ! V_2 -> V_33 -> V_24 ) ) {
V_47 = - V_146 ;
break;
}
if ( F_36 ( V_2 ) && ! ( F_37 ( V_64 , & V_2 -> V_22 ) ) ) {
while ( V_49 > 0 ) {
T_2 V_167 = F_34 ( V_2 , V_140 , V_49 ) ;
if ( V_167 < 0 ) {
if ( V_167 == - V_157 )
break;
V_47 = V_167 ;
goto V_52;
}
V_140 += V_167 ;
V_49 -= V_167 ;
if ( V_49 == 0 )
break;
V_19 = * V_140 ;
if ( F_32 ( V_19 , V_2 ) < 0 )
break;
V_140 ++ ; V_49 -- ;
}
if ( V_2 -> V_44 -> V_66 )
V_2 -> V_44 -> V_66 ( V_2 ) ;
} else {
while ( V_49 > 0 ) {
V_19 = V_2 -> V_44 -> V_45 ( V_2 , V_140 , V_49 ) ;
if ( V_19 < 0 ) {
V_47 = V_19 ;
goto V_52;
}
if ( ! V_19 )
break;
V_140 += V_19 ;
V_49 -= V_19 ;
}
}
if ( ! V_49 )
break;
if ( V_142 -> V_155 & V_156 ) {
V_47 = - V_157 ;
break;
}
F_137 () ;
}
V_52:
F_131 ( V_162 ) ;
F_133 ( & V_2 -> V_133 , & V_149 ) ;
if ( V_140 - V_17 != V_49 && V_2 -> V_99 )
F_91 ( V_102 , & V_2 -> V_22 ) ;
return ( V_140 - V_17 ) ? V_140 - V_17 : V_47 ;
}
static unsigned int F_138 ( struct V_1 * V_2 , struct V_142 * V_142 ,
T_4 * V_149 )
{
unsigned int V_168 = 0 ;
F_139 ( V_142 , & V_2 -> V_38 , V_149 ) ;
F_139 ( V_142 , & V_2 -> V_133 , V_149 ) ;
if ( F_112 ( V_2 , F_122 ( V_2 ) ? 0 : F_123 ( V_2 ) ) )
V_168 |= V_169 | V_170 ;
if ( V_2 -> V_35 && V_2 -> V_33 -> V_36 )
V_168 |= V_171 | V_169 | V_170 ;
if ( F_37 ( V_161 , & V_2 -> V_22 ) )
V_168 |= V_172 ;
if ( F_128 ( V_142 ) )
V_168 |= V_172 ;
if ( ! ( V_168 & ( V_172 | V_169 | V_170 ) ) ) {
if ( F_123 ( V_2 ) && ! F_122 ( V_2 ) )
V_2 -> V_115 = F_123 ( V_2 ) ;
else
V_2 -> V_115 = 1 ;
}
if ( V_2 -> V_44 -> V_45 && ! F_140 ( V_2 ) &&
F_141 ( V_2 ) < V_173 &&
F_33 ( V_2 ) > 0 )
V_168 |= V_174 | V_175 ;
return V_168 ;
}
static unsigned long F_142 ( struct V_5 * V_6 )
{
int V_49 , V_73 , V_76 ;
if ( ! V_6 -> V_13 )
return 0 ;
V_73 = V_6 -> V_30 ;
V_76 = V_6 -> V_25 ;
V_49 = ( V_73 - V_76 ) & ( V_11 - 1 ) ;
while ( V_73 != V_76 ) {
if ( F_37 ( V_76 , V_6 -> V_32 ) &&
V_6 -> V_20 [ V_76 ] == V_98 )
V_49 -- ;
V_76 = ( V_76 + 1 ) & ( V_11 - 1 ) ;
}
return V_49 ;
}
static int F_143 ( struct V_1 * V_2 , struct V_142 * V_142 ,
unsigned int V_176 , unsigned long V_177 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_47 ;
switch ( V_176 ) {
case V_178 :
return F_3 ( F_141 ( V_2 ) , ( int T_1 * ) V_177 ) ;
case V_179 :
V_47 = V_6 -> V_12 ;
if ( F_104 ( V_2 ) )
V_47 = F_142 ( V_6 ) ;
return F_3 ( V_47 , ( unsigned int T_1 * ) V_177 ) ;
default:
return F_144 ( V_2 , V_142 , V_176 , V_177 ) ;
}
}
void F_145 ( struct V_180 * V_44 )
{
* V_44 = V_181 ;
V_44 -> V_182 = NULL ;
V_44 -> V_183 = V_44 -> V_22 = 0 ;
}

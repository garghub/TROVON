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
F_6 ( F_7 ( V_17 , & V_2 -> V_18 ) ,
L_2 ) ;
F_8 ( & V_2 -> V_15 -> V_19 . V_20 ) ;
}
}
static void F_9 ( unsigned char V_21 , struct V_5 * V_6 )
{
if ( V_6 -> V_12 < V_11 ) {
V_6 -> V_22 [ V_6 -> V_23 ] = V_21 ;
V_6 -> V_23 = ( V_6 -> V_23 + 1 ) & ( V_11 - 1 ) ;
V_6 -> V_12 ++ ;
}
}
static void F_10 ( unsigned char V_21 , struct V_5 * V_6 )
{
unsigned long V_18 ;
F_11 ( & V_6 -> V_24 , V_18 ) ;
F_9 ( V_21 , V_6 ) ;
F_12 ( & V_6 -> V_24 , V_18 ) ;
}
static void F_13 ( struct V_5 * V_6 )
{
unsigned long V_18 ;
F_11 ( & V_6 -> V_24 , V_18 ) ;
V_6 -> V_23 = V_6 -> V_25 = V_6 -> V_12 = 0 ;
F_12 ( & V_6 -> V_24 , V_18 ) ;
F_14 ( & V_6 -> V_26 ) ;
V_6 -> V_27 = V_6 -> V_28 = V_6 -> V_29 = 0 ;
F_15 ( & V_6 -> V_26 ) ;
V_6 -> V_30 = V_6 -> V_13 = V_6 -> V_31 = 0 ;
F_16 ( V_6 -> V_32 , V_11 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
F_18 ( & V_2 -> V_33 , V_18 ) ;
if ( V_2 -> V_34 -> V_35 ) {
V_2 -> V_36 |= V_37 ;
F_19 ( & V_2 -> V_34 -> V_38 ) ;
}
F_20 ( & V_2 -> V_33 , V_18 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_7 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_34 )
F_17 ( V_2 ) ;
}
static T_2 F_22 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_18 ;
T_2 V_39 = 0 ;
F_11 ( & V_6 -> V_24 , V_18 ) ;
if ( ! V_6 -> V_8 ) {
V_39 = V_6 -> V_12 ;
} else if ( V_6 -> V_13 ) {
V_39 = ( V_6 -> V_30 > V_6 -> V_25 ) ?
V_6 -> V_30 - V_6 -> V_25 :
V_6 -> V_30 + ( V_11 - V_6 -> V_25 ) ;
}
F_12 ( & V_6 -> V_24 , V_18 ) ;
return V_39 ;
}
static inline int F_23 ( unsigned char V_21 )
{
return ( V_21 & 0xc0 ) == 0x80 ;
}
static inline int F_24 ( unsigned char V_21 , struct V_1 * V_2 )
{
return F_25 ( V_2 ) && F_23 ( V_21 ) ;
}
static int F_26 ( unsigned char V_21 , struct V_1 * V_2 , int V_40 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_41 ;
if ( ! V_40 )
return - 1 ;
switch ( V_21 ) {
case '\n' :
if ( F_27 ( V_2 ) )
V_6 -> V_42 = 0 ;
if ( F_28 ( V_2 ) ) {
if ( V_40 < 2 )
return - 1 ;
V_6 -> V_43 = V_6 -> V_42 = 0 ;
V_2 -> V_44 -> V_45 ( V_2 , L_3 , 2 ) ;
return 2 ;
}
V_6 -> V_43 = V_6 -> V_42 ;
break;
case '\r' :
if ( F_29 ( V_2 ) && V_6 -> V_42 == 0 )
return 0 ;
if ( F_30 ( V_2 ) ) {
V_21 = '\n' ;
if ( F_27 ( V_2 ) )
V_6 -> V_43 = V_6 -> V_42 = 0 ;
break;
}
V_6 -> V_43 = V_6 -> V_42 = 0 ;
break;
case '\t' :
V_41 = 8 - ( V_6 -> V_42 & 7 ) ;
if ( F_31 ( V_2 ) == V_46 ) {
if ( V_40 < V_41 )
return - 1 ;
V_6 -> V_42 += V_41 ;
V_2 -> V_44 -> V_45 ( V_2 , L_4 , V_41 ) ;
return V_41 ;
}
V_6 -> V_42 += V_41 ;
break;
case '\b' :
if ( V_6 -> V_42 > 0 )
V_6 -> V_42 -- ;
break;
default:
if ( ! iscntrl ( V_21 ) ) {
if ( F_32 ( V_2 ) )
V_21 = toupper ( V_21 ) ;
if ( ! F_24 ( V_21 , V_2 ) )
V_6 -> V_42 ++ ;
}
break;
}
F_33 ( V_2 , V_21 ) ;
return 1 ;
}
static int F_34 ( unsigned char V_21 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 , V_47 ;
F_14 ( & V_6 -> V_48 ) ;
V_40 = F_35 ( V_2 ) ;
V_47 = F_26 ( V_21 , V_2 , V_40 ) ;
F_15 ( & V_6 -> V_48 ) ;
if ( V_47 < 0 )
return - 1 ;
else
return 0 ;
}
static T_2 F_36 ( struct V_1 * V_2 ,
const unsigned char * V_19 , unsigned int V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 ;
int V_50 ;
const unsigned char * V_51 ;
F_14 ( & V_6 -> V_48 ) ;
V_40 = F_35 ( V_2 ) ;
if ( ! V_40 ) {
F_15 ( & V_6 -> V_48 ) ;
return 0 ;
}
if ( V_49 > V_40 )
V_49 = V_40 ;
for ( V_50 = 0 , V_51 = V_19 ; V_50 < V_49 ; V_50 ++ , V_51 ++ ) {
unsigned char V_21 = * V_51 ;
switch ( V_21 ) {
case '\n' :
if ( F_27 ( V_2 ) )
V_6 -> V_42 = 0 ;
if ( F_28 ( V_2 ) )
goto V_52;
V_6 -> V_43 = V_6 -> V_42 ;
break;
case '\r' :
if ( F_29 ( V_2 ) && V_6 -> V_42 == 0 )
goto V_52;
if ( F_30 ( V_2 ) )
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
if ( ! iscntrl ( V_21 ) ) {
if ( F_32 ( V_2 ) )
goto V_52;
if ( ! F_24 ( V_21 , V_2 ) )
V_6 -> V_42 ++ ;
}
break;
}
}
V_52:
V_50 = V_2 -> V_44 -> V_45 ( V_2 , V_19 , V_50 ) ;
F_15 ( & V_6 -> V_48 ) ;
return V_50 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 , V_49 ;
unsigned char V_21 ;
unsigned char * V_51 , * V_53 ;
if ( ! V_6 -> V_28 )
return;
F_14 ( & V_6 -> V_48 ) ;
F_14 ( & V_6 -> V_26 ) ;
V_40 = F_35 ( V_2 ) ;
V_53 = V_6 -> V_54 + V_11 ;
V_51 = V_6 -> V_54 + V_6 -> V_27 ;
V_49 = V_6 -> V_28 ;
while ( V_49 > 0 ) {
V_21 = * V_51 ;
if ( V_21 == V_55 ) {
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
F_33 ( V_2 , '\b' ) ;
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
F_33 ( V_2 , V_55 ) ;
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
F_33 ( V_2 , '^' ) ;
F_33 ( V_2 , V_56 ^ 0100 ) ;
V_6 -> V_42 += 2 ;
V_40 -= 2 ;
V_51 += 2 ;
V_49 -= 2 ;
}
if ( V_58 )
break;
} else {
if ( F_38 ( V_2 ) &&
! ( F_7 ( V_64 , & V_2 -> V_18 ) ) ) {
int V_47 = F_26 ( V_21 , V_2 , V_40 ) ;
if ( V_47 < 0 )
break;
V_40 -= V_47 ;
} else {
if ( ! V_40 )
break;
F_33 ( V_2 , V_21 ) ;
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
F_15 ( & V_6 -> V_26 ) ;
F_15 ( & V_6 -> V_48 ) ;
if ( V_2 -> V_44 -> V_66 )
V_2 -> V_44 -> V_66 ( V_2 ) ;
}
static void F_39 ( unsigned char V_21 , struct V_5 * V_6 )
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
V_6 -> V_54 [ V_67 ] = V_21 ;
}
static void F_40 ( struct V_5 * V_6 )
{
F_14 ( & V_6 -> V_26 ) ;
F_39 ( V_55 , V_6 ) ;
F_39 ( V_63 , V_6 ) ;
F_15 ( & V_6 -> V_26 ) ;
}
static void F_41 ( struct V_5 * V_6 )
{
F_14 ( & V_6 -> V_26 ) ;
F_39 ( V_55 , V_6 ) ;
F_39 ( V_62 , V_6 ) ;
F_15 ( & V_6 -> V_26 ) ;
}
static void F_42 ( unsigned int V_59 , int V_68 ,
struct V_5 * V_6 )
{
F_14 ( & V_6 -> V_26 ) ;
F_39 ( V_55 , V_6 ) ;
F_39 ( V_61 , V_6 ) ;
V_59 &= 7 ;
if ( V_68 )
V_59 |= 0x80 ;
F_39 ( V_59 , V_6 ) ;
F_15 ( & V_6 -> V_26 ) ;
}
static void F_43 ( unsigned char V_21 , struct V_5 * V_6 )
{
F_14 ( & V_6 -> V_26 ) ;
if ( V_21 == V_55 ) {
F_39 ( V_55 , V_6 ) ;
F_39 ( V_55 , V_6 ) ;
} else {
F_39 ( V_21 , V_6 ) ;
}
F_15 ( & V_6 -> V_26 ) ;
}
static void F_44 ( unsigned char V_21 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_14 ( & V_6 -> V_26 ) ;
if ( V_21 == V_55 ) {
F_39 ( V_55 , V_6 ) ;
F_39 ( V_55 , V_6 ) ;
} else {
if ( F_45 ( V_2 ) && iscntrl ( V_21 ) && V_21 != '\t' )
F_39 ( V_55 , V_6 ) ;
F_39 ( V_21 , V_6 ) ;
}
F_15 ( & V_6 -> V_26 ) ;
}
static inline void F_46 ( struct V_5 * V_6 )
{
if ( V_6 -> V_31 ) {
F_43 ( '/' , V_6 ) ;
V_6 -> V_31 = 0 ;
}
}
static void F_47 ( unsigned char V_21 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
enum { V_69 , V_70 , V_71 } V_72 ;
int V_73 , V_74 , V_75 ;
unsigned long V_18 ;
if ( V_6 -> V_23 == V_6 -> V_30 ) {
return;
}
if ( V_21 == F_48 ( V_2 ) )
V_72 = V_69 ;
else if ( V_21 == F_49 ( V_2 ) )
V_72 = V_70 ;
else {
if ( ! F_50 ( V_2 ) ) {
F_11 ( & V_6 -> V_24 , V_18 ) ;
V_6 -> V_12 -= ( ( V_6 -> V_23 - V_6 -> V_30 ) &
( V_11 - 1 ) ) ;
V_6 -> V_23 = V_6 -> V_30 ;
F_12 ( & V_6 -> V_24 , V_18 ) ;
return;
}
if ( ! F_51 ( V_2 ) || ! F_52 ( V_2 ) || ! F_53 ( V_2 ) ) {
F_11 ( & V_6 -> V_24 , V_18 ) ;
V_6 -> V_12 -= ( ( V_6 -> V_23 - V_6 -> V_30 ) &
( V_11 - 1 ) ) ;
V_6 -> V_23 = V_6 -> V_30 ;
F_12 ( & V_6 -> V_24 , V_18 ) ;
F_46 ( V_6 ) ;
F_44 ( F_54 ( V_2 ) , V_2 ) ;
if ( F_51 ( V_2 ) )
F_43 ( '\n' , V_6 ) ;
return;
}
V_72 = V_71 ;
}
V_74 = 0 ;
while ( V_6 -> V_23 != V_6 -> V_30 ) {
V_73 = V_6 -> V_23 ;
do {
V_73 = ( V_73 - 1 ) & ( V_11 - 1 ) ;
V_21 = V_6 -> V_22 [ V_73 ] ;
} while ( F_24 ( V_21 , V_2 ) && V_73 != V_6 -> V_30 );
if ( F_24 ( V_21 , V_2 ) )
break;
if ( V_72 == V_70 ) {
if ( isalnum ( V_21 ) || V_21 == '_' )
V_74 ++ ;
else if ( V_74 )
break;
}
V_75 = ( V_6 -> V_23 - V_73 ) & ( V_11 - 1 ) ;
F_11 ( & V_6 -> V_24 , V_18 ) ;
V_6 -> V_23 = V_73 ;
V_6 -> V_12 -= V_75 ;
F_12 ( & V_6 -> V_24 , V_18 ) ;
if ( F_50 ( V_2 ) ) {
if ( F_55 ( V_2 ) ) {
if ( ! V_6 -> V_31 ) {
F_43 ( '\\' , V_6 ) ;
V_6 -> V_31 = 1 ;
}
F_44 ( V_21 , V_2 ) ;
while ( -- V_75 > 0 ) {
V_73 = ( V_73 + 1 ) & ( V_11 - 1 ) ;
F_43 ( V_6 -> V_22 [ V_73 ] ,
V_6 ) ;
F_40 ( V_6 ) ;
}
} else if ( V_72 == V_69 && ! F_53 ( V_2 ) ) {
F_44 ( F_48 ( V_2 ) , V_2 ) ;
} else if ( V_21 == '\t' ) {
unsigned int V_59 = 0 ;
int V_68 = 0 ;
unsigned long V_76 = V_6 -> V_23 ;
while ( V_76 != V_6 -> V_30 ) {
V_76 = ( V_76 - 1 ) & ( V_11 - 1 ) ;
V_21 = V_6 -> V_22 [ V_76 ] ;
if ( V_21 == '\t' ) {
V_68 = 1 ;
break;
} else if ( iscntrl ( V_21 ) ) {
if ( F_45 ( V_2 ) )
V_59 += 2 ;
} else if ( ! F_24 ( V_21 , V_2 ) ) {
V_59 ++ ;
}
}
F_42 ( V_59 , V_68 , V_6 ) ;
} else {
if ( iscntrl ( V_21 ) && F_45 ( V_2 ) ) {
F_43 ( '\b' , V_6 ) ;
F_43 ( ' ' , V_6 ) ;
F_43 ( '\b' , V_6 ) ;
}
if ( ! iscntrl ( V_21 ) || F_45 ( V_2 ) ) {
F_43 ( '\b' , V_6 ) ;
F_43 ( ' ' , V_6 ) ;
F_43 ( '\b' , V_6 ) ;
}
}
}
if ( V_72 == V_69 )
break;
}
if ( V_6 -> V_23 == V_6 -> V_30 && F_50 ( V_2 ) )
F_46 ( V_6 ) ;
}
static inline void F_56 ( int V_77 , struct V_1 * V_2 )
{
struct V_78 * V_79 = F_57 ( V_2 ) ;
if ( V_79 ) {
F_58 ( V_79 , V_77 , 1 ) ;
F_59 ( V_79 ) ;
}
}
static inline void F_60 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_61 ( V_2 ) )
return;
if ( F_62 ( V_2 ) ) {
F_56 ( V_80 , V_2 ) ;
if ( ! F_63 ( V_2 ) ) {
F_21 ( V_2 ) ;
F_64 ( V_2 ) ;
}
return;
}
if ( F_5 ( V_2 ) ) {
F_10 ( '\377' , V_6 ) ;
F_10 ( '\0' , V_6 ) ;
}
F_10 ( '\0' , V_6 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static inline void F_65 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
char V_19 [ 64 ] ;
V_6 -> V_81 ++ ;
if ( F_66 ( V_82 , V_6 -> V_83 + V_84 ) ||
F_66 ( V_6 -> V_83 , V_82 ) ) {
F_67 ( V_85 L_5 ,
F_68 ( V_2 , V_19 ) ,
V_6 -> V_81 ) ;
V_6 -> V_83 = V_82 ;
V_6 -> V_81 = 0 ;
}
}
static inline void F_69 ( struct V_1 * V_2 ,
unsigned char V_21 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_70 ( V_2 ) )
return;
if ( F_5 ( V_2 ) ) {
F_10 ( '\377' , V_6 ) ;
F_10 ( '\0' , V_6 ) ;
F_10 ( V_21 , V_6 ) ;
} else if ( F_71 ( V_2 ) )
F_10 ( '\0' , V_6 ) ;
else
F_10 ( V_21 , V_6 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static inline void F_72 ( struct V_1 * V_2 , unsigned char V_21 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_18 ;
int V_86 ;
if ( V_6 -> V_87 ) {
F_10 ( V_21 , V_6 ) ;
return;
}
if ( F_73 ( V_2 ) )
V_21 &= 0x7f ;
if ( F_74 ( V_2 ) && F_75 ( V_2 ) )
V_21 = tolower ( V_21 ) ;
if ( F_76 ( V_2 ) ) {
F_10 ( V_21 , V_6 ) ;
return;
}
if ( V_2 -> V_88 && ! V_2 -> V_89 && F_77 ( V_2 ) &&
F_78 ( V_2 ) && V_21 != F_79 ( V_2 ) && V_21 != F_80 ( V_2 ) &&
V_21 != F_81 ( V_2 ) && V_21 != F_82 ( V_2 ) && V_21 != F_83 ( V_2 ) ) {
F_84 ( V_2 ) ;
F_37 ( V_2 ) ;
}
if ( V_2 -> V_90 ) {
if ( F_77 ( V_2 ) ) {
if ( V_21 == F_79 ( V_2 ) ) {
F_84 ( V_2 ) ;
F_37 ( V_2 ) ;
} else if ( V_21 == F_80 ( V_2 ) )
F_85 ( V_2 ) ;
}
return;
}
if ( ! F_7 ( V_21 , V_6 -> V_91 ) || V_6 -> V_92 ) {
V_6 -> V_92 = 0 ;
V_86 = ( V_21 == ( unsigned char ) '\377' && F_5 ( V_2 ) ) ? 1 : 0 ;
if ( V_6 -> V_12 >= ( V_11 - V_86 - 1 ) ) {
if ( F_50 ( V_2 ) )
F_34 ( '\a' , V_2 ) ;
return;
}
if ( F_50 ( V_2 ) ) {
F_46 ( V_6 ) ;
if ( V_6 -> V_30 == V_6 -> V_23 )
F_41 ( V_6 ) ;
F_44 ( V_21 , V_2 ) ;
F_37 ( V_2 ) ;
}
if ( V_86 )
F_10 ( V_21 , V_6 ) ;
F_10 ( V_21 , V_6 ) ;
return;
}
if ( F_77 ( V_2 ) ) {
if ( V_21 == F_79 ( V_2 ) ) {
F_84 ( V_2 ) ;
F_37 ( V_2 ) ;
return;
}
if ( V_21 == F_80 ( V_2 ) ) {
F_85 ( V_2 ) ;
return;
}
}
if ( F_86 ( V_2 ) ) {
int signal ;
signal = V_80 ;
if ( V_21 == F_81 ( V_2 ) )
goto V_93;
signal = V_94 ;
if ( V_21 == F_82 ( V_2 ) )
goto V_93;
signal = V_95 ;
if ( V_21 == F_83 ( V_2 ) ) {
V_93:
if ( ! F_63 ( V_2 ) ) {
F_21 ( V_2 ) ;
F_64 ( V_2 ) ;
}
if ( F_77 ( V_2 ) )
F_84 ( V_2 ) ;
if ( F_50 ( V_2 ) ) {
F_44 ( V_21 , V_2 ) ;
F_37 ( V_2 ) ;
}
F_56 ( signal , V_2 ) ;
return;
}
}
if ( V_21 == '\r' ) {
if ( F_87 ( V_2 ) )
return;
if ( F_88 ( V_2 ) )
V_21 = '\n' ;
} else if ( V_21 == '\n' && F_89 ( V_2 ) )
V_21 = '\r' ;
if ( V_6 -> V_8 ) {
if ( V_21 == F_48 ( V_2 ) || V_21 == F_54 ( V_2 ) ||
( V_21 == F_49 ( V_2 ) && F_75 ( V_2 ) ) ) {
F_47 ( V_21 , V_2 ) ;
F_37 ( V_2 ) ;
return;
}
if ( V_21 == F_90 ( V_2 ) && F_75 ( V_2 ) ) {
V_6 -> V_92 = 1 ;
if ( F_50 ( V_2 ) ) {
F_46 ( V_6 ) ;
if ( F_45 ( V_2 ) ) {
F_43 ( '^' , V_6 ) ;
F_43 ( '\b' , V_6 ) ;
F_37 ( V_2 ) ;
}
}
return;
}
if ( V_21 == F_91 ( V_2 ) && F_50 ( V_2 ) &&
F_75 ( V_2 ) ) {
unsigned long V_76 = V_6 -> V_30 ;
F_46 ( V_6 ) ;
F_44 ( V_21 , V_2 ) ;
F_43 ( '\n' , V_6 ) ;
while ( V_76 != V_6 -> V_23 ) {
F_44 ( V_6 -> V_22 [ V_76 ] , V_2 ) ;
V_76 = ( V_76 + 1 ) & ( V_11 - 1 ) ;
}
F_37 ( V_2 ) ;
return;
}
if ( V_21 == '\n' ) {
if ( V_6 -> V_12 >= V_11 ) {
if ( F_50 ( V_2 ) )
F_34 ( '\a' , V_2 ) ;
return;
}
if ( F_50 ( V_2 ) || F_92 ( V_2 ) ) {
F_43 ( '\n' , V_6 ) ;
F_37 ( V_2 ) ;
}
goto V_96;
}
if ( V_21 == F_93 ( V_2 ) ) {
if ( V_6 -> V_12 >= V_11 )
return;
if ( V_6 -> V_30 != V_6 -> V_23 )
F_94 ( V_97 , & V_2 -> V_18 ) ;
V_21 = V_98 ;
goto V_96;
}
if ( ( V_21 == F_95 ( V_2 ) ) ||
( V_21 == F_96 ( V_2 ) && F_75 ( V_2 ) ) ) {
V_86 = ( V_21 == ( unsigned char ) '\377' && F_5 ( V_2 ) )
? 1 : 0 ;
if ( V_6 -> V_12 >= ( V_11 - V_86 ) ) {
if ( F_50 ( V_2 ) )
F_34 ( '\a' , V_2 ) ;
return;
}
if ( F_50 ( V_2 ) ) {
if ( V_6 -> V_30 == V_6 -> V_23 )
F_41 ( V_6 ) ;
F_44 ( V_21 , V_2 ) ;
F_37 ( V_2 ) ;
}
if ( V_86 )
F_10 ( V_21 , V_6 ) ;
V_96:
F_11 ( & V_6 -> V_24 , V_18 ) ;
F_94 ( V_6 -> V_23 , V_6 -> V_32 ) ;
F_9 ( V_21 , V_6 ) ;
V_6 -> V_30 = V_6 -> V_23 ;
V_6 -> V_13 ++ ;
F_12 ( & V_6 -> V_24 , V_18 ) ;
F_97 ( & V_2 -> V_99 , V_100 , V_101 ) ;
if ( F_98 ( & V_2 -> V_38 ) )
F_19 ( & V_2 -> V_38 ) ;
return;
}
}
V_86 = ( V_21 == ( unsigned char ) '\377' && F_5 ( V_2 ) ) ? 1 : 0 ;
if ( V_6 -> V_12 >= ( V_11 - V_86 - 1 ) ) {
if ( F_50 ( V_2 ) )
F_34 ( '\a' , V_2 ) ;
return;
}
if ( F_50 ( V_2 ) ) {
F_46 ( V_6 ) ;
if ( V_21 == '\n' )
F_43 ( '\n' , V_6 ) ;
else {
if ( V_6 -> V_30 == V_6 -> V_23 )
F_41 ( V_6 ) ;
F_44 ( V_21 , V_2 ) ;
}
F_37 ( V_2 ) ;
}
if ( V_86 )
F_10 ( V_21 , V_6 ) ;
F_10 ( V_21 , V_6 ) ;
}
static void F_99 ( struct V_1 * V_2 )
{
if ( V_2 -> V_99 && F_100 ( V_102 , & V_2 -> V_18 ) )
F_97 ( & V_2 -> V_99 , V_100 , V_103 ) ;
}
static void F_101 ( struct V_1 * V_2 , const unsigned char * V_51 ,
char * V_104 , int V_105 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const unsigned char * V_106 ;
char * V_107 , V_18 = V_108 ;
int V_50 ;
char V_19 [ 64 ] ;
unsigned long V_109 ;
if ( V_6 -> V_110 ) {
F_11 ( & V_6 -> V_24 , V_109 ) ;
V_50 = F_102 ( V_11 - V_6 -> V_12 ,
V_11 - V_6 -> V_23 ) ;
V_50 = F_102 ( V_105 , V_50 ) ;
memcpy ( V_6 -> V_22 + V_6 -> V_23 , V_51 , V_50 ) ;
V_6 -> V_23 = ( V_6 -> V_23 + V_50 ) & ( V_11 - 1 ) ;
V_6 -> V_12 += V_50 ;
V_51 += V_50 ;
V_105 -= V_50 ;
V_50 = F_102 ( V_11 - V_6 -> V_12 ,
V_11 - V_6 -> V_23 ) ;
V_50 = F_102 ( V_105 , V_50 ) ;
memcpy ( V_6 -> V_22 + V_6 -> V_23 , V_51 , V_50 ) ;
V_6 -> V_23 = ( V_6 -> V_23 + V_50 ) & ( V_11 - 1 ) ;
V_6 -> V_12 += V_50 ;
F_12 ( & V_6 -> V_24 , V_109 ) ;
} else {
for ( V_50 = V_105 , V_106 = V_51 , V_107 = V_104 ; V_50 ; V_50 -- , V_106 ++ ) {
if ( V_107 )
V_18 = * V_107 ++ ;
switch ( V_18 ) {
case V_108 :
F_72 ( V_2 , * V_106 ) ;
break;
case V_111 :
F_60 ( V_2 ) ;
break;
case V_112 :
case V_113 :
F_69 ( V_2 , * V_106 ) ;
break;
case V_114 :
F_65 ( V_2 ) ;
break;
default:
F_67 ( V_115 L_6 ,
F_68 ( V_2 , V_19 ) , V_18 ) ;
break;
}
}
if ( V_2 -> V_44 -> V_66 )
V_2 -> V_44 -> V_66 ( V_2 ) ;
}
F_4 ( V_2 ) ;
if ( ( ! V_6 -> V_8 && ( V_6 -> V_12 >= V_2 -> V_116 ) ) ||
F_76 ( V_2 ) ) {
F_97 ( & V_2 -> V_99 , V_100 , V_101 ) ;
if ( F_98 ( & V_2 -> V_38 ) )
F_19 ( & V_2 -> V_38 ) ;
}
while ( 1 ) {
F_103 ( V_2 , V_117 ) ;
if ( V_2 -> V_14 >= V_118 )
break;
if ( ! F_104 ( V_2 ) )
break;
}
F_105 ( V_2 , 0 ) ;
}
int F_106 ( int V_77 )
{
return ( F_107 ( & V_119 -> V_120 , V_77 ) ||
V_119 -> V_121 -> V_122 [ V_77 - 1 ] . V_123 . V_124 == V_125 ) ;
}
static void F_108 ( struct V_1 * V_2 , struct V_126 * V_127 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_128 = 1 ;
if ( V_127 )
V_128 = ( V_127 -> V_129 ^ V_2 -> V_130 . V_129 ) & V_131 ;
if ( V_128 ) {
F_16 ( V_6 -> V_32 , V_11 ) ;
V_6 -> V_30 = V_6 -> V_25 ;
V_6 -> V_13 = 0 ;
V_6 -> V_31 = 0 ;
}
if ( V_128 && ! F_109 ( V_2 ) && V_6 -> V_12 )
F_19 ( & V_2 -> V_38 ) ;
V_6 -> V_8 = ( F_109 ( V_2 ) != 0 ) ;
if ( F_7 ( V_132 , & V_2 -> V_18 ) ) {
V_6 -> V_87 = 1 ;
V_6 -> V_110 = 1 ;
F_4 ( V_2 ) ;
return;
}
if ( F_73 ( V_2 ) || F_74 ( V_2 ) || F_87 ( V_2 ) ||
F_88 ( V_2 ) || F_89 ( V_2 ) || F_109 ( V_2 ) ||
F_77 ( V_2 ) || F_86 ( V_2 ) || F_50 ( V_2 ) ||
F_5 ( V_2 ) ) {
F_16 ( V_6 -> V_91 , 256 ) ;
if ( F_87 ( V_2 ) || F_88 ( V_2 ) )
F_94 ( '\r' , V_6 -> V_91 ) ;
if ( F_89 ( V_2 ) )
F_94 ( '\n' , V_6 -> V_91 ) ;
if ( F_109 ( V_2 ) ) {
F_94 ( F_48 ( V_2 ) , V_6 -> V_91 ) ;
F_94 ( F_54 ( V_2 ) , V_6 -> V_91 ) ;
F_94 ( F_93 ( V_2 ) , V_6 -> V_91 ) ;
F_94 ( '\n' , V_6 -> V_91 ) ;
F_94 ( F_95 ( V_2 ) , V_6 -> V_91 ) ;
if ( F_75 ( V_2 ) ) {
F_94 ( F_49 ( V_2 ) ,
V_6 -> V_91 ) ;
F_94 ( F_90 ( V_2 ) ,
V_6 -> V_91 ) ;
F_94 ( F_96 ( V_2 ) ,
V_6 -> V_91 ) ;
if ( F_50 ( V_2 ) )
F_94 ( F_91 ( V_2 ) ,
V_6 -> V_91 ) ;
}
}
if ( F_77 ( V_2 ) ) {
F_94 ( F_79 ( V_2 ) , V_6 -> V_91 ) ;
F_94 ( F_80 ( V_2 ) , V_6 -> V_91 ) ;
}
if ( F_86 ( V_2 ) ) {
F_94 ( F_81 ( V_2 ) , V_6 -> V_91 ) ;
F_94 ( F_82 ( V_2 ) , V_6 -> V_91 ) ;
F_94 ( F_83 ( V_2 ) , V_6 -> V_91 ) ;
}
F_110 ( V_98 , V_6 -> V_91 ) ;
V_6 -> V_87 = 0 ;
V_6 -> V_110 = 0 ;
} else {
V_6 -> V_87 = 1 ;
if ( ( F_61 ( V_2 ) || ( ! F_62 ( V_2 ) && ! F_5 ( V_2 ) ) ) &&
( F_70 ( V_2 ) || ! F_71 ( V_2 ) ) &&
( V_2 -> V_133 -> V_18 & V_134 ) )
V_6 -> V_110 = 1 ;
else
V_6 -> V_110 = 0 ;
}
F_4 ( V_2 ) ;
if ( ! F_77 ( V_2 ) && V_127 && ( V_127 -> V_135 & V_136 ) && ! V_2 -> V_89 ) {
F_84 ( V_2 ) ;
}
F_19 ( & V_2 -> V_137 ) ;
F_19 ( & V_2 -> V_38 ) ;
}
static void F_111 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_2 -> V_34 )
F_17 ( V_2 ) ;
F_112 ( V_6 -> V_22 ) ;
F_112 ( V_6 -> V_54 ) ;
F_112 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_114 ( sizeof( * V_6 ) , V_138 ) ;
if ( ! V_6 )
goto V_139;
V_6 -> V_83 = V_82 ;
F_115 ( & V_6 -> V_140 ) ;
F_115 ( & V_6 -> V_48 ) ;
F_115 ( & V_6 -> V_26 ) ;
F_116 ( & V_6 -> V_24 ) ;
V_6 -> V_22 = F_114 ( V_11 , V_138 ) ;
V_6 -> V_54 = F_114 ( V_11 , V_138 ) ;
if ( ! V_6 -> V_22 || ! V_6 -> V_54 )
goto V_141;
V_2 -> V_7 = V_6 ;
F_13 ( V_2 -> V_7 ) ;
V_6 -> V_42 = 0 ;
V_2 -> V_116 = 1 ;
V_2 -> V_90 = 0 ;
F_110 ( V_17 , & V_2 -> V_18 ) ;
F_108 ( V_2 , NULL ) ;
F_117 ( V_2 ) ;
return 0 ;
V_141:
F_112 ( V_6 -> V_22 ) ;
F_112 ( V_6 -> V_54 ) ;
F_112 ( V_6 ) ;
V_139:
return - V_142 ;
}
static inline int F_118 ( struct V_1 * V_2 , int V_143 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_119 ( V_2 ) ;
if ( V_6 -> V_8 && ! F_76 ( V_2 ) ) {
if ( V_6 -> V_13 )
return 1 ;
} else if ( V_6 -> V_12 >= ( V_143 ? V_143 : 1 ) )
return 1 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 ,
unsigned char T_1 * * V_144 ,
T_3 * V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_47 ;
T_3 V_39 ;
unsigned long V_18 ;
bool V_145 ;
V_47 = 0 ;
F_11 ( & V_6 -> V_24 , V_18 ) ;
V_39 = F_102 ( V_6 -> V_12 , V_11 - V_6 -> V_25 ) ;
V_39 = F_102 ( * V_49 , V_39 ) ;
F_12 ( & V_6 -> V_24 , V_18 ) ;
if ( V_39 ) {
V_47 = F_121 ( * V_144 , & V_6 -> V_22 [ V_6 -> V_25 ] , V_39 ) ;
V_39 -= V_47 ;
V_145 = V_39 == 1 &&
V_6 -> V_22 [ V_6 -> V_25 ] == F_93 ( V_2 ) ;
F_2 ( V_2 , & V_6 -> V_22 [ V_6 -> V_25 ] , V_39 ,
V_6 -> V_8 ) ;
F_11 ( & V_6 -> V_24 , V_18 ) ;
V_6 -> V_25 = ( V_6 -> V_25 + V_39 ) & ( V_11 - 1 ) ;
V_6 -> V_12 -= V_39 ;
if ( F_76 ( V_2 ) && V_6 -> V_8 && V_145 && ! V_6 -> V_12 )
V_39 = 0 ;
F_12 ( & V_6 -> V_24 , V_18 ) ;
* V_144 += V_39 ;
* V_49 -= V_39 ;
}
return V_47 ;
}
static int F_122 ( struct V_1 * V_2 , struct V_146 * V_146 )
{
if ( V_146 -> V_147 -> V_45 == V_148 ||
V_119 -> signal -> V_2 != V_2 )
return 0 ;
F_123 ( & V_2 -> V_33 ) ;
if ( ! V_2 -> V_149 )
F_67 ( V_115 L_7 ) ;
else if ( F_124 ( V_119 ) != V_2 -> V_149 ) {
F_125 ( & V_2 -> V_33 ) ;
if ( F_106 ( V_150 ) || F_126 () )
return - V_151 ;
F_58 ( F_124 ( V_119 ) , V_150 , 1 ) ;
F_127 ( V_152 ) ;
return - V_153 ;
}
F_125 ( & V_2 -> V_33 ) ;
return 0 ;
}
static T_2 F_128 ( struct V_1 * V_2 , struct V_146 * V_146 ,
unsigned char T_1 * V_19 , T_3 V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char T_1 * V_144 = V_19 ;
F_129 ( V_154 , V_119 ) ;
int V_21 ;
int V_155 , time ;
T_2 V_47 = 0 ;
T_2 V_156 ;
long V_157 ;
unsigned long V_18 ;
int V_35 ;
V_158:
V_21 = F_122 ( V_2 , V_146 ) ;
if ( V_21 < 0 )
return V_21 ;
V_155 = time = 0 ;
V_157 = V_159 ;
if ( ! V_6 -> V_8 ) {
time = ( V_84 / 10 ) * F_130 ( V_2 ) ;
V_155 = F_131 ( V_2 ) ;
if ( V_155 ) {
if ( time )
V_2 -> V_116 = 1 ;
else if ( ! F_98 ( & V_2 -> V_38 ) ||
( V_2 -> V_116 > V_155 ) )
V_2 -> V_116 = V_155 ;
} else {
V_157 = 0 ;
if ( time ) {
V_157 = time ;
time = 0 ;
}
V_2 -> V_116 = V_155 = 1 ;
}
}
if ( V_146 -> V_160 & V_161 ) {
if ( ! F_132 ( & V_6 -> V_140 ) )
return - V_162 ;
} else {
if ( F_133 ( & V_6 -> V_140 ) )
return - V_153 ;
}
V_35 = V_2 -> V_35 ;
F_134 ( & V_2 -> V_38 , & V_154 ) ;
while ( V_49 ) {
if ( V_35 && V_2 -> V_34 -> V_36 ) {
unsigned char V_163 ;
if ( V_144 != V_19 )
break;
F_18 ( & V_2 -> V_34 -> V_33 , V_18 ) ;
V_163 = V_2 -> V_34 -> V_36 ;
V_2 -> V_34 -> V_36 = 0 ;
F_20 ( & V_2 -> V_34 -> V_33 , V_18 ) ;
if ( F_1 ( V_2 , V_163 , V_144 ++ ) ) {
V_47 = - V_164 ;
V_144 -- ;
break;
}
V_49 -- ;
break;
}
F_135 ( V_165 ) ;
if ( ( ( V_155 - ( V_144 - V_19 ) ) < V_2 -> V_116 ) &&
( ( V_155 - ( V_144 - V_19 ) ) >= 1 ) )
V_2 -> V_116 = ( V_155 - ( V_144 - V_19 ) ) ;
if ( ! F_118 ( V_2 , 0 ) ) {
if ( F_7 ( V_166 , & V_2 -> V_18 ) ) {
V_47 = - V_151 ;
break;
}
if ( F_136 ( V_146 ) )
break;
if ( ! V_157 )
break;
if ( V_146 -> V_160 & V_161 ) {
V_47 = - V_162 ;
break;
}
if ( F_137 ( V_119 ) ) {
V_47 = - V_153 ;
break;
}
F_4 ( V_2 ) ;
V_157 = F_138 ( V_157 ) ;
continue;
}
F_139 ( V_167 ) ;
if ( V_35 && V_144 == V_19 ) {
if ( F_1 ( V_2 , V_168 , V_144 ++ ) ) {
V_47 = - V_164 ;
V_144 -- ;
break;
}
V_49 -- ;
}
if ( V_6 -> V_8 && ! F_76 ( V_2 ) ) {
F_11 ( & V_6 -> V_24 , V_18 ) ;
while ( V_49 && V_6 -> V_12 ) {
int V_169 ;
V_169 = F_100 ( V_6 -> V_25 ,
V_6 -> V_32 ) ;
V_21 = V_6 -> V_22 [ V_6 -> V_25 ] ;
V_6 -> V_25 = ( ( V_6 -> V_25 + 1 ) &
( V_11 - 1 ) ) ;
V_6 -> V_12 -- ;
if ( V_169 ) {
if ( -- V_6 -> V_13 < 0 )
V_6 -> V_13 = 0 ;
}
F_12 ( & V_6 -> V_24 , V_18 ) ;
if ( ! V_169 || ( V_21 != V_98 ) ) {
if ( F_1 ( V_2 , V_21 , V_144 ++ ) ) {
V_47 = - V_164 ;
V_144 -- ;
F_11 ( & V_6 -> V_24 , V_18 ) ;
break;
}
V_49 -- ;
}
if ( V_169 ) {
F_140 ( V_2 ) ;
F_11 ( & V_6 -> V_24 , V_18 ) ;
break;
}
F_11 ( & V_6 -> V_24 , V_18 ) ;
}
F_12 ( & V_6 -> V_24 , V_18 ) ;
if ( V_47 )
break;
} else {
int V_170 ;
V_170 = F_120 ( V_2 , & V_144 , & V_49 ) ;
V_170 += F_120 ( V_2 , & V_144 , & V_49 ) ;
if ( V_170 ) {
V_47 = - V_164 ;
break;
}
}
while ( 1 ) {
F_103 ( V_2 , V_171 ) ;
if ( F_22 ( V_2 ) > V_172 )
break;
if ( ! V_2 -> V_105 )
break;
F_4 ( V_2 ) ;
if ( ! F_141 ( V_2 ) )
break;
}
F_105 ( V_2 , 0 ) ;
if ( V_144 - V_19 >= V_155 )
break;
if ( time )
V_157 = time ;
}
F_15 ( & V_6 -> V_140 ) ;
F_142 ( & V_2 -> V_38 , & V_154 ) ;
if ( ! F_98 ( & V_2 -> V_38 ) )
V_2 -> V_116 = V_155 ;
F_139 ( V_167 ) ;
V_156 = V_144 - V_19 ;
if ( V_156 ) {
V_47 = V_156 ;
if ( V_49 )
F_110 ( V_97 , & V_2 -> V_18 ) ;
} else if ( F_100 ( V_97 , & V_2 -> V_18 ) )
goto V_158;
F_4 ( V_2 ) ;
return V_47 ;
}
static T_2 F_143 ( struct V_1 * V_2 , struct V_146 * V_146 ,
const unsigned char * V_19 , T_3 V_49 )
{
const unsigned char * V_144 = V_19 ;
F_129 ( V_154 , V_119 ) ;
int V_21 ;
T_2 V_47 = 0 ;
if ( F_144 ( V_2 ) && V_146 -> V_147 -> V_45 != V_148 ) {
V_47 = F_145 ( V_2 ) ;
if ( V_47 )
return V_47 ;
}
F_37 ( V_2 ) ;
F_134 ( & V_2 -> V_137 , & V_154 ) ;
while ( 1 ) {
F_135 ( V_165 ) ;
if ( F_137 ( V_119 ) ) {
V_47 = - V_153 ;
break;
}
if ( F_136 ( V_146 ) || ( V_2 -> V_34 && ! V_2 -> V_34 -> V_105 ) ) {
V_47 = - V_151 ;
break;
}
if ( F_38 ( V_2 ) && ! ( F_7 ( V_64 , & V_2 -> V_18 ) ) ) {
while ( V_49 > 0 ) {
T_2 V_173 = F_36 ( V_2 , V_144 , V_49 ) ;
if ( V_173 < 0 ) {
if ( V_173 == - V_162 )
break;
V_47 = V_173 ;
goto V_52;
}
V_144 += V_173 ;
V_49 -= V_173 ;
if ( V_49 == 0 )
break;
V_21 = * V_144 ;
if ( F_34 ( V_21 , V_2 ) < 0 )
break;
V_144 ++ ; V_49 -- ;
}
if ( V_2 -> V_44 -> V_66 )
V_2 -> V_44 -> V_66 ( V_2 ) ;
} else {
while ( V_49 > 0 ) {
V_21 = V_2 -> V_44 -> V_45 ( V_2 , V_144 , V_49 ) ;
if ( V_21 < 0 ) {
V_47 = V_21 ;
goto V_52;
}
if ( ! V_21 )
break;
V_144 += V_21 ;
V_49 -= V_21 ;
}
}
if ( ! V_49 )
break;
if ( V_146 -> V_160 & V_161 ) {
V_47 = - V_162 ;
break;
}
F_146 () ;
}
V_52:
F_139 ( V_167 ) ;
F_142 ( & V_2 -> V_137 , & V_154 ) ;
if ( V_144 - V_19 != V_49 && V_2 -> V_99 )
F_94 ( V_102 , & V_2 -> V_18 ) ;
return ( V_144 - V_19 ) ? V_144 - V_19 : V_47 ;
}
static unsigned int F_147 ( struct V_1 * V_2 , struct V_146 * V_146 ,
T_4 * V_154 )
{
unsigned int V_174 = 0 ;
F_148 ( V_146 , & V_2 -> V_38 , V_154 ) ;
F_148 ( V_146 , & V_2 -> V_137 , V_154 ) ;
if ( F_118 ( V_2 , F_130 ( V_2 ) ? 0 : F_131 ( V_2 ) ) )
V_174 |= V_175 | V_176 ;
if ( V_2 -> V_35 && V_2 -> V_34 -> V_36 )
V_174 |= V_177 | V_175 | V_176 ;
if ( F_7 ( V_166 , & V_2 -> V_18 ) )
V_174 |= V_178 ;
if ( F_136 ( V_146 ) )
V_174 |= V_178 ;
if ( ! ( V_174 & ( V_178 | V_175 | V_176 ) ) ) {
if ( F_131 ( V_2 ) && ! F_130 ( V_2 ) )
V_2 -> V_116 = F_131 ( V_2 ) ;
else
V_2 -> V_116 = 1 ;
}
if ( V_2 -> V_44 -> V_45 && ! F_149 ( V_2 ) &&
F_150 ( V_2 ) < V_179 &&
F_35 ( V_2 ) > 0 )
V_174 |= V_180 | V_181 ;
return V_174 ;
}
static unsigned long F_151 ( struct V_5 * V_6 )
{
int V_49 , V_73 , V_76 ;
if ( ! V_6 -> V_13 )
return 0 ;
V_73 = V_6 -> V_30 ;
V_76 = V_6 -> V_25 ;
V_49 = ( V_73 - V_76 ) & ( V_11 - 1 ) ;
while ( V_73 != V_76 ) {
if ( F_7 ( V_76 , V_6 -> V_32 ) &&
V_6 -> V_22 [ V_76 ] == V_98 )
V_49 -- ;
V_76 = ( V_76 + 1 ) & ( V_11 - 1 ) ;
}
return V_49 ;
}
static int F_152 ( struct V_1 * V_2 , struct V_146 * V_146 ,
unsigned int V_182 , unsigned long V_183 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_47 ;
switch ( V_182 ) {
case V_184 :
return F_3 ( F_150 ( V_2 ) , ( int T_1 * ) V_183 ) ;
case V_185 :
V_47 = V_6 -> V_12 ;
if ( F_109 ( V_2 ) )
V_47 = F_151 ( V_6 ) ;
return F_3 ( V_47 , ( unsigned int T_1 * ) V_183 ) ;
default:
return F_153 ( V_2 , V_146 , V_182 , V_183 ) ;
}
}
void F_154 ( struct V_186 * V_44 )
{
* V_44 = V_187 ;
V_44 -> V_188 = NULL ;
V_44 -> V_189 = V_44 -> V_18 = 0 ;
}

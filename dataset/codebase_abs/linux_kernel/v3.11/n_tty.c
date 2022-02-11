static inline int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_2 , & V_3 , 1 , V_6 -> V_8 ) ;
return F_3 ( V_3 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_9 ;
int V_10 ;
unsigned long V_11 ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
if ( F_6 ( V_2 ) ) {
V_9 = V_13 - V_6 -> V_14 * 3 - 1 ;
} else
V_9 = V_13 - V_6 -> V_14 - 1 ;
if ( V_9 <= 0 )
V_9 = V_6 -> V_8 && ! V_6 -> V_15 ;
V_10 = V_2 -> V_16 ;
V_2 -> V_16 = V_9 ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
return V_9 && ! V_10 ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) ) {
F_9 ( V_2 -> V_17 -> V_18 == NULL ,
L_1 ) ;
F_9 ( F_10 ( V_19 , & V_2 -> V_11 ) ,
L_2 ) ;
F_11 ( & V_2 -> V_17 -> V_20 . V_21 ) ;
}
}
static void F_12 ( unsigned char V_22 , struct V_5 * V_6 )
{
if ( V_6 -> V_14 < V_13 ) {
V_6 -> V_23 [ V_6 -> V_24 ] = V_22 ;
V_6 -> V_24 = ( V_6 -> V_24 + 1 ) & ( V_13 - 1 ) ;
V_6 -> V_14 ++ ;
}
}
static void F_13 ( unsigned char V_22 , struct V_5 * V_6 )
{
unsigned long V_11 ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
F_12 ( V_22 , V_6 ) ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
}
static void F_14 ( struct V_5 * V_6 )
{
unsigned long V_11 ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
V_6 -> V_24 = V_6 -> V_25 = V_6 -> V_14 = 0 ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
F_15 ( & V_6 -> V_26 ) ;
V_6 -> V_27 = V_6 -> V_28 = V_6 -> V_29 = 0 ;
F_16 ( & V_6 -> V_26 ) ;
V_6 -> V_30 = V_6 -> V_15 = V_6 -> V_31 = 0 ;
F_17 ( V_6 -> V_32 , V_13 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned long V_11 ;
F_19 ( & V_2 -> V_33 , V_11 ) ;
if ( V_2 -> V_34 -> V_35 ) {
V_2 -> V_36 |= V_37 ;
F_20 ( & V_2 -> V_34 -> V_38 ) ;
}
F_21 ( & V_2 -> V_33 , V_11 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_14 ( V_2 -> V_7 ) ;
F_8 ( V_2 ) ;
if ( V_2 -> V_34 )
F_18 ( V_2 ) ;
}
static T_2 F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_11 ;
T_2 V_39 = 0 ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
if ( ! V_6 -> V_8 ) {
V_39 = V_6 -> V_14 ;
} else if ( V_6 -> V_15 ) {
V_39 = ( V_6 -> V_30 > V_6 -> V_25 ) ?
V_6 -> V_30 - V_6 -> V_25 :
V_6 -> V_30 + ( V_13 - V_6 -> V_25 ) ;
}
F_7 ( & V_6 -> V_12 , V_11 ) ;
return V_39 ;
}
static inline int F_24 ( unsigned char V_22 )
{
return ( V_22 & 0xc0 ) == 0x80 ;
}
static inline int F_25 ( unsigned char V_22 , struct V_1 * V_2 )
{
return F_26 ( V_2 ) && F_24 ( V_22 ) ;
}
static int F_27 ( unsigned char V_22 , struct V_1 * V_2 , int V_40 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_41 ;
if ( ! V_40 )
return - 1 ;
switch ( V_22 ) {
case '\n' :
if ( F_28 ( V_2 ) )
V_6 -> V_42 = 0 ;
if ( F_29 ( V_2 ) ) {
if ( V_40 < 2 )
return - 1 ;
V_6 -> V_43 = V_6 -> V_42 = 0 ;
V_2 -> V_44 -> V_45 ( V_2 , L_3 , 2 ) ;
return 2 ;
}
V_6 -> V_43 = V_6 -> V_42 ;
break;
case '\r' :
if ( F_30 ( V_2 ) && V_6 -> V_42 == 0 )
return 0 ;
if ( F_31 ( V_2 ) ) {
V_22 = '\n' ;
if ( F_28 ( V_2 ) )
V_6 -> V_43 = V_6 -> V_42 = 0 ;
break;
}
V_6 -> V_43 = V_6 -> V_42 = 0 ;
break;
case '\t' :
V_41 = 8 - ( V_6 -> V_42 & 7 ) ;
if ( F_32 ( V_2 ) == V_46 ) {
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
if ( ! iscntrl ( V_22 ) ) {
if ( F_33 ( V_2 ) )
V_22 = toupper ( V_22 ) ;
if ( ! F_25 ( V_22 , V_2 ) )
V_6 -> V_42 ++ ;
}
break;
}
F_34 ( V_2 , V_22 ) ;
return 1 ;
}
static int F_35 ( unsigned char V_22 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 , V_47 ;
F_15 ( & V_6 -> V_48 ) ;
V_40 = F_36 ( V_2 ) ;
V_47 = F_27 ( V_22 , V_2 , V_40 ) ;
F_16 ( & V_6 -> V_48 ) ;
if ( V_47 < 0 )
return - 1 ;
else
return 0 ;
}
static T_2 F_37 ( struct V_1 * V_2 ,
const unsigned char * V_20 , unsigned int V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 ;
int V_50 ;
const unsigned char * V_51 ;
F_15 ( & V_6 -> V_48 ) ;
V_40 = F_36 ( V_2 ) ;
if ( ! V_40 ) {
F_16 ( & V_6 -> V_48 ) ;
return 0 ;
}
if ( V_49 > V_40 )
V_49 = V_40 ;
for ( V_50 = 0 , V_51 = V_20 ; V_50 < V_49 ; V_50 ++ , V_51 ++ ) {
unsigned char V_22 = * V_51 ;
switch ( V_22 ) {
case '\n' :
if ( F_28 ( V_2 ) )
V_6 -> V_42 = 0 ;
if ( F_29 ( V_2 ) )
goto V_52;
V_6 -> V_43 = V_6 -> V_42 ;
break;
case '\r' :
if ( F_30 ( V_2 ) && V_6 -> V_42 == 0 )
goto V_52;
if ( F_31 ( V_2 ) )
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
if ( ! iscntrl ( V_22 ) ) {
if ( F_33 ( V_2 ) )
goto V_52;
if ( ! F_25 ( V_22 , V_2 ) )
V_6 -> V_42 ++ ;
}
break;
}
}
V_52:
V_50 = V_2 -> V_44 -> V_45 ( V_2 , V_20 , V_50 ) ;
F_16 ( & V_6 -> V_48 ) ;
return V_50 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_40 , V_49 ;
unsigned char V_22 ;
unsigned char * V_51 , * V_53 ;
if ( ! V_6 -> V_28 )
return;
F_15 ( & V_6 -> V_48 ) ;
F_15 ( & V_6 -> V_26 ) ;
V_40 = F_36 ( V_2 ) ;
V_53 = V_6 -> V_54 + V_13 ;
V_51 = V_6 -> V_54 + V_6 -> V_27 ;
V_49 = V_6 -> V_28 ;
while ( V_49 > 0 ) {
V_22 = * V_51 ;
if ( V_22 == V_55 ) {
unsigned char V_56 ;
unsigned char * V_57 ;
int V_58 = 0 ;
V_57 = V_51 + 1 ;
if ( V_57 == V_53 )
V_57 -= V_13 ;
V_56 = * V_57 ;
switch ( V_56 ) {
unsigned int V_59 , V_60 ;
case V_61 :
if ( ++ V_57 == V_53 )
V_57 -= V_13 ;
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
F_34 ( V_2 , '\b' ) ;
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
F_34 ( V_2 , V_55 ) ;
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
F_34 ( V_2 , '^' ) ;
F_34 ( V_2 , V_56 ^ 0100 ) ;
V_6 -> V_42 += 2 ;
V_40 -= 2 ;
V_51 += 2 ;
V_49 -= 2 ;
}
if ( V_58 )
break;
} else {
if ( F_39 ( V_2 ) ) {
int V_47 = F_27 ( V_22 , V_2 , V_40 ) ;
if ( V_47 < 0 )
break;
V_40 -= V_47 ;
} else {
if ( ! V_40 )
break;
F_34 ( V_2 , V_22 ) ;
V_40 -= 1 ;
}
V_51 += 1 ;
V_49 -= 1 ;
}
if ( V_51 >= V_53 )
V_51 -= V_13 ;
}
if ( V_49 == 0 ) {
V_6 -> V_27 = 0 ;
V_6 -> V_28 = 0 ;
V_6 -> V_29 = 0 ;
} else {
int V_64 = V_6 -> V_28 - V_49 ;
V_6 -> V_27 += V_64 ;
V_6 -> V_27 &= V_13 - 1 ;
V_6 -> V_28 = V_49 ;
if ( V_64 > 0 )
V_6 -> V_29 = 0 ;
}
F_16 ( & V_6 -> V_26 ) ;
F_16 ( & V_6 -> V_48 ) ;
if ( V_2 -> V_44 -> V_65 )
V_2 -> V_44 -> V_65 ( V_2 ) ;
}
static void F_40 ( unsigned char V_22 , struct V_5 * V_6 )
{
int V_66 ;
if ( V_6 -> V_28 == V_13 ) {
V_66 = V_6 -> V_27 ;
if ( V_6 -> V_54 [ V_6 -> V_27 ] == V_55 ) {
if ( V_6 -> V_54 [ ( V_6 -> V_27 + 1 ) &
( V_13 - 1 ) ] ==
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
V_6 -> V_27 &= V_13 - 1 ;
V_6 -> V_29 = 1 ;
} else {
V_66 = V_6 -> V_27 + V_6 -> V_28 ;
V_66 &= V_13 - 1 ;
V_6 -> V_28 ++ ;
}
V_6 -> V_54 [ V_66 ] = V_22 ;
}
static void F_41 ( struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_26 ) ;
F_40 ( V_55 , V_6 ) ;
F_40 ( V_63 , V_6 ) ;
F_16 ( & V_6 -> V_26 ) ;
}
static void F_42 ( struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_26 ) ;
F_40 ( V_55 , V_6 ) ;
F_40 ( V_62 , V_6 ) ;
F_16 ( & V_6 -> V_26 ) ;
}
static void F_43 ( unsigned int V_59 , int V_67 ,
struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_26 ) ;
F_40 ( V_55 , V_6 ) ;
F_40 ( V_61 , V_6 ) ;
V_59 &= 7 ;
if ( V_67 )
V_59 |= 0x80 ;
F_40 ( V_59 , V_6 ) ;
F_16 ( & V_6 -> V_26 ) ;
}
static void F_44 ( unsigned char V_22 , struct V_5 * V_6 )
{
F_15 ( & V_6 -> V_26 ) ;
if ( V_22 == V_55 ) {
F_40 ( V_55 , V_6 ) ;
F_40 ( V_55 , V_6 ) ;
} else {
F_40 ( V_22 , V_6 ) ;
}
F_16 ( & V_6 -> V_26 ) ;
}
static void F_45 ( unsigned char V_22 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_15 ( & V_6 -> V_26 ) ;
if ( V_22 == V_55 ) {
F_40 ( V_55 , V_6 ) ;
F_40 ( V_55 , V_6 ) ;
} else {
if ( F_46 ( V_2 ) && iscntrl ( V_22 ) && V_22 != '\t' )
F_40 ( V_55 , V_6 ) ;
F_40 ( V_22 , V_6 ) ;
}
F_16 ( & V_6 -> V_26 ) ;
}
static inline void F_47 ( struct V_5 * V_6 )
{
if ( V_6 -> V_31 ) {
F_44 ( '/' , V_6 ) ;
V_6 -> V_31 = 0 ;
}
}
static void F_48 ( unsigned char V_22 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
enum { V_68 , V_69 , V_70 } V_71 ;
int V_72 , V_73 , V_74 ;
unsigned long V_11 ;
if ( V_6 -> V_24 == V_6 -> V_30 ) {
return;
}
if ( V_22 == F_49 ( V_2 ) )
V_71 = V_68 ;
else if ( V_22 == F_50 ( V_2 ) )
V_71 = V_69 ;
else {
if ( ! F_51 ( V_2 ) ) {
F_5 ( & V_6 -> V_12 , V_11 ) ;
V_6 -> V_14 -= ( ( V_6 -> V_24 - V_6 -> V_30 ) &
( V_13 - 1 ) ) ;
V_6 -> V_24 = V_6 -> V_30 ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
return;
}
if ( ! F_52 ( V_2 ) || ! F_53 ( V_2 ) || ! F_54 ( V_2 ) ) {
F_5 ( & V_6 -> V_12 , V_11 ) ;
V_6 -> V_14 -= ( ( V_6 -> V_24 - V_6 -> V_30 ) &
( V_13 - 1 ) ) ;
V_6 -> V_24 = V_6 -> V_30 ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
F_47 ( V_6 ) ;
F_45 ( F_55 ( V_2 ) , V_2 ) ;
if ( F_52 ( V_2 ) )
F_44 ( '\n' , V_6 ) ;
return;
}
V_71 = V_70 ;
}
V_73 = 0 ;
while ( V_6 -> V_24 != V_6 -> V_30 ) {
V_72 = V_6 -> V_24 ;
do {
V_72 = ( V_72 - 1 ) & ( V_13 - 1 ) ;
V_22 = V_6 -> V_23 [ V_72 ] ;
} while ( F_25 ( V_22 , V_2 ) && V_72 != V_6 -> V_30 );
if ( F_25 ( V_22 , V_2 ) )
break;
if ( V_71 == V_69 ) {
if ( isalnum ( V_22 ) || V_22 == '_' )
V_73 ++ ;
else if ( V_73 )
break;
}
V_74 = ( V_6 -> V_24 - V_72 ) & ( V_13 - 1 ) ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
V_6 -> V_24 = V_72 ;
V_6 -> V_14 -= V_74 ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
if ( F_51 ( V_2 ) ) {
if ( F_56 ( V_2 ) ) {
if ( ! V_6 -> V_31 ) {
F_44 ( '\\' , V_6 ) ;
V_6 -> V_31 = 1 ;
}
F_45 ( V_22 , V_2 ) ;
while ( -- V_74 > 0 ) {
V_72 = ( V_72 + 1 ) & ( V_13 - 1 ) ;
F_44 ( V_6 -> V_23 [ V_72 ] ,
V_6 ) ;
F_41 ( V_6 ) ;
}
} else if ( V_71 == V_68 && ! F_54 ( V_2 ) ) {
F_45 ( F_49 ( V_2 ) , V_2 ) ;
} else if ( V_22 == '\t' ) {
unsigned int V_59 = 0 ;
int V_67 = 0 ;
unsigned long V_75 = V_6 -> V_24 ;
while ( V_75 != V_6 -> V_30 ) {
V_75 = ( V_75 - 1 ) & ( V_13 - 1 ) ;
V_22 = V_6 -> V_23 [ V_75 ] ;
if ( V_22 == '\t' ) {
V_67 = 1 ;
break;
} else if ( iscntrl ( V_22 ) ) {
if ( F_46 ( V_2 ) )
V_59 += 2 ;
} else if ( ! F_25 ( V_22 , V_2 ) ) {
V_59 ++ ;
}
}
F_43 ( V_59 , V_67 , V_6 ) ;
} else {
if ( iscntrl ( V_22 ) && F_46 ( V_2 ) ) {
F_44 ( '\b' , V_6 ) ;
F_44 ( ' ' , V_6 ) ;
F_44 ( '\b' , V_6 ) ;
}
if ( ! iscntrl ( V_22 ) || F_46 ( V_2 ) ) {
F_44 ( '\b' , V_6 ) ;
F_44 ( ' ' , V_6 ) ;
F_44 ( '\b' , V_6 ) ;
}
}
}
if ( V_71 == V_68 )
break;
}
if ( V_6 -> V_24 == V_6 -> V_30 && F_51 ( V_2 ) )
F_47 ( V_6 ) ;
}
static inline void F_57 ( int V_76 , struct V_1 * V_2 )
{
struct V_77 * V_78 = F_58 ( V_2 ) ;
if ( V_78 ) {
F_59 ( V_78 , V_76 , 1 ) ;
F_60 ( V_78 ) ;
}
}
static inline void F_61 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_62 ( V_2 ) )
return;
if ( F_63 ( V_2 ) ) {
F_57 ( V_79 , V_2 ) ;
if ( ! F_64 ( V_2 ) ) {
F_22 ( V_2 ) ;
F_65 ( V_2 ) ;
}
return;
}
if ( F_6 ( V_2 ) ) {
F_13 ( '\377' , V_6 ) ;
F_13 ( '\0' , V_6 ) ;
}
F_13 ( '\0' , V_6 ) ;
F_20 ( & V_2 -> V_38 ) ;
}
static inline void F_66 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
char V_20 [ 64 ] ;
V_6 -> V_80 ++ ;
if ( F_67 ( V_81 , V_6 -> V_82 + V_83 ) ||
F_67 ( V_6 -> V_82 , V_81 ) ) {
F_68 ( V_84 L_5 ,
F_69 ( V_2 , V_20 ) ,
V_6 -> V_80 ) ;
V_6 -> V_82 = V_81 ;
V_6 -> V_80 = 0 ;
}
}
static inline void F_70 ( struct V_1 * V_2 ,
unsigned char V_22 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_71 ( V_2 ) )
return;
if ( F_6 ( V_2 ) ) {
F_13 ( '\377' , V_6 ) ;
F_13 ( '\0' , V_6 ) ;
F_13 ( V_22 , V_6 ) ;
} else if ( F_72 ( V_2 ) )
F_13 ( '\0' , V_6 ) ;
else
F_13 ( V_22 , V_6 ) ;
F_20 ( & V_2 -> V_38 ) ;
}
static inline void F_73 ( struct V_1 * V_2 , unsigned char V_22 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_11 ;
int V_85 ;
if ( V_6 -> V_86 ) {
F_13 ( V_22 , V_6 ) ;
return;
}
if ( F_74 ( V_2 ) )
V_22 &= 0x7f ;
if ( F_75 ( V_2 ) && F_76 ( V_2 ) )
V_22 = tolower ( V_22 ) ;
if ( F_77 ( V_2 ) ) {
F_13 ( V_22 , V_6 ) ;
return;
}
if ( V_2 -> V_87 && ! V_2 -> V_88 && F_78 ( V_2 ) &&
F_79 ( V_2 ) && V_22 != F_80 ( V_2 ) && V_22 != F_81 ( V_2 ) &&
V_22 != F_82 ( V_2 ) && V_22 != F_83 ( V_2 ) && V_22 != F_84 ( V_2 ) ) {
F_85 ( V_2 ) ;
F_38 ( V_2 ) ;
}
if ( V_2 -> V_89 ) {
if ( F_78 ( V_2 ) ) {
if ( V_22 == F_80 ( V_2 ) ) {
F_85 ( V_2 ) ;
F_38 ( V_2 ) ;
} else if ( V_22 == F_81 ( V_2 ) )
F_86 ( V_2 ) ;
}
return;
}
if ( ! F_10 ( V_22 , V_6 -> V_90 ) || V_6 -> V_91 ) {
V_6 -> V_91 = 0 ;
V_85 = ( V_22 == ( unsigned char ) '\377' && F_6 ( V_2 ) ) ? 1 : 0 ;
if ( V_6 -> V_14 >= ( V_13 - V_85 - 1 ) ) {
if ( F_51 ( V_2 ) )
F_35 ( '\a' , V_2 ) ;
return;
}
if ( F_51 ( V_2 ) ) {
F_47 ( V_6 ) ;
if ( V_6 -> V_30 == V_6 -> V_24 )
F_42 ( V_6 ) ;
F_45 ( V_22 , V_2 ) ;
F_38 ( V_2 ) ;
}
if ( V_85 )
F_13 ( V_22 , V_6 ) ;
F_13 ( V_22 , V_6 ) ;
return;
}
if ( F_78 ( V_2 ) ) {
if ( V_22 == F_80 ( V_2 ) ) {
F_85 ( V_2 ) ;
F_38 ( V_2 ) ;
return;
}
if ( V_22 == F_81 ( V_2 ) ) {
F_86 ( V_2 ) ;
return;
}
}
if ( F_87 ( V_2 ) ) {
int signal ;
signal = V_79 ;
if ( V_22 == F_82 ( V_2 ) )
goto V_92;
signal = V_93 ;
if ( V_22 == F_83 ( V_2 ) )
goto V_92;
signal = V_94 ;
if ( V_22 == F_84 ( V_2 ) ) {
V_92:
if ( ! F_64 ( V_2 ) ) {
F_22 ( V_2 ) ;
F_65 ( V_2 ) ;
}
if ( F_78 ( V_2 ) )
F_85 ( V_2 ) ;
if ( F_51 ( V_2 ) ) {
F_45 ( V_22 , V_2 ) ;
F_38 ( V_2 ) ;
}
F_57 ( signal , V_2 ) ;
return;
}
}
if ( V_22 == '\r' ) {
if ( F_88 ( V_2 ) )
return;
if ( F_89 ( V_2 ) )
V_22 = '\n' ;
} else if ( V_22 == '\n' && F_90 ( V_2 ) )
V_22 = '\r' ;
if ( V_6 -> V_8 ) {
if ( V_22 == F_49 ( V_2 ) || V_22 == F_55 ( V_2 ) ||
( V_22 == F_50 ( V_2 ) && F_76 ( V_2 ) ) ) {
F_48 ( V_22 , V_2 ) ;
F_38 ( V_2 ) ;
return;
}
if ( V_22 == F_91 ( V_2 ) && F_76 ( V_2 ) ) {
V_6 -> V_91 = 1 ;
if ( F_51 ( V_2 ) ) {
F_47 ( V_6 ) ;
if ( F_46 ( V_2 ) ) {
F_44 ( '^' , V_6 ) ;
F_44 ( '\b' , V_6 ) ;
F_38 ( V_2 ) ;
}
}
return;
}
if ( V_22 == F_92 ( V_2 ) && F_51 ( V_2 ) &&
F_76 ( V_2 ) ) {
unsigned long V_75 = V_6 -> V_30 ;
F_47 ( V_6 ) ;
F_45 ( V_22 , V_2 ) ;
F_44 ( '\n' , V_6 ) ;
while ( V_75 != V_6 -> V_24 ) {
F_45 ( V_6 -> V_23 [ V_75 ] , V_2 ) ;
V_75 = ( V_75 + 1 ) & ( V_13 - 1 ) ;
}
F_38 ( V_2 ) ;
return;
}
if ( V_22 == '\n' ) {
if ( V_6 -> V_14 >= V_13 ) {
if ( F_51 ( V_2 ) )
F_35 ( '\a' , V_2 ) ;
return;
}
if ( F_51 ( V_2 ) || F_93 ( V_2 ) ) {
F_44 ( '\n' , V_6 ) ;
F_38 ( V_2 ) ;
}
goto V_95;
}
if ( V_22 == F_94 ( V_2 ) ) {
if ( V_6 -> V_14 >= V_13 )
return;
if ( V_6 -> V_30 != V_6 -> V_24 )
F_95 ( V_96 , & V_2 -> V_11 ) ;
V_22 = V_97 ;
goto V_95;
}
if ( ( V_22 == F_96 ( V_2 ) ) ||
( V_22 == F_97 ( V_2 ) && F_76 ( V_2 ) ) ) {
V_85 = ( V_22 == ( unsigned char ) '\377' && F_6 ( V_2 ) )
? 1 : 0 ;
if ( V_6 -> V_14 >= ( V_13 - V_85 ) ) {
if ( F_51 ( V_2 ) )
F_35 ( '\a' , V_2 ) ;
return;
}
if ( F_51 ( V_2 ) ) {
if ( V_6 -> V_30 == V_6 -> V_24 )
F_42 ( V_6 ) ;
F_45 ( V_22 , V_2 ) ;
F_38 ( V_2 ) ;
}
if ( V_85 )
F_13 ( V_22 , V_6 ) ;
V_95:
F_5 ( & V_6 -> V_12 , V_11 ) ;
F_95 ( V_6 -> V_24 , V_6 -> V_32 ) ;
F_12 ( V_22 , V_6 ) ;
V_6 -> V_30 = V_6 -> V_24 ;
V_6 -> V_15 ++ ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
F_98 ( & V_2 -> V_98 , V_99 , V_100 ) ;
if ( F_99 ( & V_2 -> V_38 ) )
F_20 ( & V_2 -> V_38 ) ;
return;
}
}
V_85 = ( V_22 == ( unsigned char ) '\377' && F_6 ( V_2 ) ) ? 1 : 0 ;
if ( V_6 -> V_14 >= ( V_13 - V_85 - 1 ) ) {
if ( F_51 ( V_2 ) )
F_35 ( '\a' , V_2 ) ;
return;
}
if ( F_51 ( V_2 ) ) {
F_47 ( V_6 ) ;
if ( V_22 == '\n' )
F_44 ( '\n' , V_6 ) ;
else {
if ( V_6 -> V_30 == V_6 -> V_24 )
F_42 ( V_6 ) ;
F_45 ( V_22 , V_2 ) ;
}
F_38 ( V_2 ) ;
}
if ( V_85 )
F_13 ( V_22 , V_6 ) ;
F_13 ( V_22 , V_6 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
if ( V_2 -> V_98 && F_101 ( V_101 , & V_2 -> V_11 ) )
F_98 ( & V_2 -> V_98 , V_99 , V_102 ) ;
}
static void F_102 ( struct V_1 * V_2 , const unsigned char * V_51 ,
char * V_103 , int V_104 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
const unsigned char * V_105 ;
char * V_106 , V_11 = V_107 ;
int V_50 ;
char V_20 [ 64 ] ;
unsigned long V_108 ;
if ( V_6 -> V_109 ) {
F_5 ( & V_6 -> V_12 , V_108 ) ;
V_50 = F_103 ( V_13 - V_6 -> V_14 ,
V_13 - V_6 -> V_24 ) ;
V_50 = F_103 ( V_104 , V_50 ) ;
memcpy ( V_6 -> V_23 + V_6 -> V_24 , V_51 , V_50 ) ;
V_6 -> V_24 = ( V_6 -> V_24 + V_50 ) & ( V_13 - 1 ) ;
V_6 -> V_14 += V_50 ;
V_51 += V_50 ;
V_104 -= V_50 ;
V_50 = F_103 ( V_13 - V_6 -> V_14 ,
V_13 - V_6 -> V_24 ) ;
V_50 = F_103 ( V_104 , V_50 ) ;
memcpy ( V_6 -> V_23 + V_6 -> V_24 , V_51 , V_50 ) ;
V_6 -> V_24 = ( V_6 -> V_24 + V_50 ) & ( V_13 - 1 ) ;
V_6 -> V_14 += V_50 ;
F_7 ( & V_6 -> V_12 , V_108 ) ;
} else {
for ( V_50 = V_104 , V_105 = V_51 , V_106 = V_103 ; V_50 ; V_50 -- , V_105 ++ ) {
if ( V_106 )
V_11 = * V_106 ++ ;
switch ( V_11 ) {
case V_107 :
F_73 ( V_2 , * V_105 ) ;
break;
case V_110 :
F_61 ( V_2 ) ;
break;
case V_111 :
case V_112 :
F_70 ( V_2 , * V_105 ) ;
break;
case V_113 :
F_66 ( V_2 ) ;
break;
default:
F_68 ( V_114 L_6 ,
F_69 ( V_2 , V_20 ) , V_11 ) ;
break;
}
}
if ( V_2 -> V_44 -> V_65 )
V_2 -> V_44 -> V_65 ( V_2 ) ;
}
F_4 ( V_2 ) ;
if ( ( ! V_6 -> V_8 && ( V_6 -> V_14 >= V_6 -> V_115 ) ) ||
F_77 ( V_2 ) ) {
F_98 ( & V_2 -> V_98 , V_99 , V_100 ) ;
if ( F_99 ( & V_2 -> V_38 ) )
F_20 ( & V_2 -> V_38 ) ;
}
while ( 1 ) {
F_104 ( V_2 , V_116 ) ;
if ( V_2 -> V_16 >= V_117 )
break;
if ( ! F_105 ( V_2 ) )
break;
}
F_106 ( V_2 , 0 ) ;
}
int F_107 ( int V_76 )
{
return ( F_108 ( & V_118 -> V_119 , V_76 ) ||
V_118 -> V_120 -> V_121 [ V_76 - 1 ] . V_122 . V_123 == V_124 ) ;
}
static void F_109 ( struct V_1 * V_2 , struct V_125 * V_126 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_127 = 1 ;
if ( V_126 )
V_127 = ( V_126 -> V_128 ^ V_2 -> V_129 . V_128 ) & V_130 ;
if ( V_127 ) {
F_17 ( V_6 -> V_32 , V_13 ) ;
V_6 -> V_30 = V_6 -> V_25 ;
V_6 -> V_15 = 0 ;
V_6 -> V_31 = 0 ;
}
if ( V_127 && ! F_110 ( V_2 ) && V_6 -> V_14 )
F_20 ( & V_2 -> V_38 ) ;
V_6 -> V_8 = ( F_110 ( V_2 ) != 0 ) ;
if ( F_74 ( V_2 ) || F_75 ( V_2 ) || F_88 ( V_2 ) ||
F_89 ( V_2 ) || F_90 ( V_2 ) || F_110 ( V_2 ) ||
F_78 ( V_2 ) || F_87 ( V_2 ) || F_51 ( V_2 ) ||
F_6 ( V_2 ) ) {
F_17 ( V_6 -> V_90 , 256 ) ;
if ( F_88 ( V_2 ) || F_89 ( V_2 ) )
F_95 ( '\r' , V_6 -> V_90 ) ;
if ( F_90 ( V_2 ) )
F_95 ( '\n' , V_6 -> V_90 ) ;
if ( F_110 ( V_2 ) ) {
F_95 ( F_49 ( V_2 ) , V_6 -> V_90 ) ;
F_95 ( F_55 ( V_2 ) , V_6 -> V_90 ) ;
F_95 ( F_94 ( V_2 ) , V_6 -> V_90 ) ;
F_95 ( '\n' , V_6 -> V_90 ) ;
F_95 ( F_96 ( V_2 ) , V_6 -> V_90 ) ;
if ( F_76 ( V_2 ) ) {
F_95 ( F_50 ( V_2 ) ,
V_6 -> V_90 ) ;
F_95 ( F_91 ( V_2 ) ,
V_6 -> V_90 ) ;
F_95 ( F_97 ( V_2 ) ,
V_6 -> V_90 ) ;
if ( F_51 ( V_2 ) )
F_95 ( F_92 ( V_2 ) ,
V_6 -> V_90 ) ;
}
}
if ( F_78 ( V_2 ) ) {
F_95 ( F_80 ( V_2 ) , V_6 -> V_90 ) ;
F_95 ( F_81 ( V_2 ) , V_6 -> V_90 ) ;
}
if ( F_87 ( V_2 ) ) {
F_95 ( F_82 ( V_2 ) , V_6 -> V_90 ) ;
F_95 ( F_83 ( V_2 ) , V_6 -> V_90 ) ;
F_95 ( F_84 ( V_2 ) , V_6 -> V_90 ) ;
}
F_111 ( V_97 , V_6 -> V_90 ) ;
V_6 -> V_86 = 0 ;
V_6 -> V_109 = 0 ;
} else {
V_6 -> V_86 = 1 ;
if ( ( F_62 ( V_2 ) || ( ! F_63 ( V_2 ) && ! F_6 ( V_2 ) ) ) &&
( F_71 ( V_2 ) || ! F_72 ( V_2 ) ) &&
( V_2 -> V_131 -> V_11 & V_132 ) )
V_6 -> V_109 = 1 ;
else
V_6 -> V_109 = 0 ;
}
F_8 ( V_2 ) ;
if ( ! F_78 ( V_2 ) && V_126 && ( V_126 -> V_133 & V_134 ) && ! V_2 -> V_88 ) {
F_85 ( V_2 ) ;
}
F_20 ( & V_2 -> V_135 ) ;
F_20 ( & V_2 -> V_38 ) ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_2 -> V_34 )
F_18 ( V_2 ) ;
F_113 ( V_6 -> V_23 ) ;
F_113 ( V_6 -> V_54 ) ;
F_113 ( V_6 ) ;
V_2 -> V_7 = NULL ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_115 ( sizeof( * V_6 ) , V_136 ) ;
if ( ! V_6 )
goto V_137;
V_6 -> V_82 = V_81 ;
F_116 ( & V_6 -> V_138 ) ;
F_116 ( & V_6 -> V_48 ) ;
F_116 ( & V_6 -> V_26 ) ;
F_117 ( & V_6 -> V_12 ) ;
V_6 -> V_23 = F_115 ( V_13 , V_136 ) ;
V_6 -> V_54 = F_115 ( V_13 , V_136 ) ;
if ( ! V_6 -> V_23 || ! V_6 -> V_54 )
goto V_139;
V_2 -> V_7 = V_6 ;
F_14 ( V_2 -> V_7 ) ;
V_6 -> V_42 = 0 ;
V_6 -> V_115 = 1 ;
V_2 -> V_89 = 0 ;
F_111 ( V_19 , & V_2 -> V_11 ) ;
F_109 ( V_2 , NULL ) ;
F_118 ( V_2 ) ;
return 0 ;
V_139:
F_113 ( V_6 -> V_23 ) ;
F_113 ( V_6 -> V_54 ) ;
F_113 ( V_6 ) ;
V_137:
return - V_140 ;
}
static inline int F_119 ( struct V_1 * V_2 , int V_141 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_120 ( V_2 ) ;
if ( V_6 -> V_8 && ! F_77 ( V_2 ) ) {
if ( V_6 -> V_15 )
return 1 ;
} else if ( V_6 -> V_14 >= ( V_141 ? V_141 : 1 ) )
return 1 ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 ,
unsigned char T_1 * * V_142 ,
T_3 * V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_47 ;
T_3 V_39 ;
unsigned long V_11 ;
bool V_143 ;
V_47 = 0 ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
V_39 = F_103 ( V_6 -> V_14 , V_13 - V_6 -> V_25 ) ;
V_39 = F_103 ( * V_49 , V_39 ) ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
if ( V_39 ) {
V_47 = F_122 ( * V_142 , & V_6 -> V_23 [ V_6 -> V_25 ] , V_39 ) ;
V_39 -= V_47 ;
V_143 = V_39 == 1 &&
V_6 -> V_23 [ V_6 -> V_25 ] == F_94 ( V_2 ) ;
F_2 ( V_2 , & V_6 -> V_23 [ V_6 -> V_25 ] , V_39 ,
V_6 -> V_8 ) ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
V_6 -> V_25 = ( V_6 -> V_25 + V_39 ) & ( V_13 - 1 ) ;
V_6 -> V_14 -= V_39 ;
if ( F_77 ( V_2 ) && V_6 -> V_8 && V_143 && ! V_6 -> V_14 )
V_39 = 0 ;
F_7 ( & V_6 -> V_12 , V_11 ) ;
* V_142 += V_39 ;
* V_49 -= V_39 ;
}
return V_47 ;
}
static int F_123 ( struct V_1 * V_2 , struct V_144 * V_144 )
{
if ( V_144 -> V_145 -> V_45 == V_146 ||
V_118 -> signal -> V_2 != V_2 )
return 0 ;
F_124 ( & V_2 -> V_33 ) ;
if ( ! V_2 -> V_147 )
F_68 ( V_114 L_7 ) ;
else if ( F_125 ( V_118 ) != V_2 -> V_147 ) {
F_126 ( & V_2 -> V_33 ) ;
if ( F_107 ( V_148 ) || F_127 () )
return - V_149 ;
F_59 ( F_125 ( V_118 ) , V_148 , 1 ) ;
F_128 ( V_150 ) ;
return - V_151 ;
}
F_126 ( & V_2 -> V_33 ) ;
return 0 ;
}
static T_2 F_129 ( struct V_1 * V_2 , struct V_144 * V_144 ,
unsigned char T_1 * V_20 , T_3 V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned char T_1 * V_142 = V_20 ;
F_130 ( V_152 , V_118 ) ;
int V_22 ;
int V_153 , time ;
T_2 V_47 = 0 ;
T_2 V_154 ;
long V_155 ;
unsigned long V_11 ;
int V_35 ;
V_156:
V_22 = F_123 ( V_2 , V_144 ) ;
if ( V_22 < 0 )
return V_22 ;
V_153 = time = 0 ;
V_155 = V_157 ;
if ( ! V_6 -> V_8 ) {
V_153 = F_131 ( V_2 ) ;
if ( V_153 ) {
time = ( V_83 / 10 ) * F_132 ( V_2 ) ;
if ( time )
V_6 -> V_115 = 1 ;
else if ( ! F_99 ( & V_2 -> V_38 ) ||
( V_6 -> V_115 > V_153 ) )
V_6 -> V_115 = V_153 ;
} else {
V_155 = ( V_83 / 10 ) * F_132 ( V_2 ) ;
V_6 -> V_115 = V_153 = 1 ;
}
}
if ( V_144 -> V_158 & V_159 ) {
if ( ! F_133 ( & V_6 -> V_138 ) )
return - V_160 ;
} else {
if ( F_134 ( & V_6 -> V_138 ) )
return - V_151 ;
}
V_35 = V_2 -> V_35 ;
F_135 ( & V_2 -> V_38 , & V_152 ) ;
while ( V_49 ) {
if ( V_35 && V_2 -> V_34 -> V_36 ) {
unsigned char V_161 ;
if ( V_142 != V_20 )
break;
F_19 ( & V_2 -> V_34 -> V_33 , V_11 ) ;
V_161 = V_2 -> V_34 -> V_36 ;
V_2 -> V_34 -> V_36 = 0 ;
F_21 ( & V_2 -> V_34 -> V_33 , V_11 ) ;
if ( F_1 ( V_2 , V_161 , V_142 ++ ) ) {
V_47 = - V_162 ;
V_142 -- ;
break;
}
V_49 -- ;
break;
}
F_136 ( V_163 ) ;
if ( ( ( V_153 - ( V_142 - V_20 ) ) < V_6 -> V_115 ) &&
( ( V_153 - ( V_142 - V_20 ) ) >= 1 ) )
V_6 -> V_115 = ( V_153 - ( V_142 - V_20 ) ) ;
if ( ! F_119 ( V_2 , 0 ) ) {
if ( F_10 ( V_164 , & V_2 -> V_11 ) ) {
V_47 = - V_149 ;
break;
}
if ( F_137 ( V_144 ) )
break;
if ( ! V_155 )
break;
if ( V_144 -> V_158 & V_159 ) {
V_47 = - V_160 ;
break;
}
if ( F_138 ( V_118 ) ) {
V_47 = - V_151 ;
break;
}
F_8 ( V_2 ) ;
V_155 = F_139 ( V_155 ) ;
continue;
}
F_140 ( V_165 ) ;
if ( V_35 && V_142 == V_20 ) {
if ( F_1 ( V_2 , V_166 , V_142 ++ ) ) {
V_47 = - V_162 ;
V_142 -- ;
break;
}
V_49 -- ;
}
if ( V_6 -> V_8 && ! F_77 ( V_2 ) ) {
F_5 ( & V_6 -> V_12 , V_11 ) ;
while ( V_49 && V_6 -> V_14 ) {
int V_167 ;
V_167 = F_101 ( V_6 -> V_25 ,
V_6 -> V_32 ) ;
V_22 = V_6 -> V_23 [ V_6 -> V_25 ] ;
V_6 -> V_25 = ( ( V_6 -> V_25 + 1 ) &
( V_13 - 1 ) ) ;
V_6 -> V_14 -- ;
if ( V_167 ) {
if ( -- V_6 -> V_15 < 0 )
V_6 -> V_15 = 0 ;
}
F_7 ( & V_6 -> V_12 , V_11 ) ;
if ( ! V_167 || ( V_22 != V_97 ) ) {
if ( F_1 ( V_2 , V_22 , V_142 ++ ) ) {
V_47 = - V_162 ;
V_142 -- ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
break;
}
V_49 -- ;
}
if ( V_167 ) {
F_141 ( V_2 ) ;
F_5 ( & V_6 -> V_12 , V_11 ) ;
break;
}
F_5 ( & V_6 -> V_12 , V_11 ) ;
}
F_7 ( & V_6 -> V_12 , V_11 ) ;
if ( V_47 )
break;
} else {
int V_168 ;
V_168 = F_121 ( V_2 , & V_142 , & V_49 ) ;
V_168 += F_121 ( V_2 , & V_142 , & V_49 ) ;
if ( V_168 ) {
V_47 = - V_162 ;
break;
}
}
while ( 1 ) {
F_104 ( V_2 , V_169 ) ;
if ( F_23 ( V_2 ) > V_170 )
break;
if ( ! V_2 -> V_104 )
break;
F_8 ( V_2 ) ;
if ( ! F_142 ( V_2 ) )
break;
}
F_106 ( V_2 , 0 ) ;
if ( V_142 - V_20 >= V_153 )
break;
if ( time )
V_155 = time ;
}
F_16 ( & V_6 -> V_138 ) ;
F_143 ( & V_2 -> V_38 , & V_152 ) ;
if ( ! F_99 ( & V_2 -> V_38 ) )
V_6 -> V_115 = V_153 ;
F_140 ( V_165 ) ;
V_154 = V_142 - V_20 ;
if ( V_154 ) {
V_47 = V_154 ;
if ( V_49 )
F_111 ( V_96 , & V_2 -> V_11 ) ;
} else if ( F_101 ( V_96 , & V_2 -> V_11 ) )
goto V_156;
F_8 ( V_2 ) ;
return V_47 ;
}
static T_2 F_144 ( struct V_1 * V_2 , struct V_144 * V_144 ,
const unsigned char * V_20 , T_3 V_49 )
{
const unsigned char * V_142 = V_20 ;
F_130 ( V_152 , V_118 ) ;
int V_22 ;
T_2 V_47 = 0 ;
if ( F_145 ( V_2 ) && V_144 -> V_145 -> V_45 != V_146 ) {
V_47 = F_146 ( V_2 ) ;
if ( V_47 )
return V_47 ;
}
F_38 ( V_2 ) ;
F_135 ( & V_2 -> V_135 , & V_152 ) ;
while ( 1 ) {
F_136 ( V_163 ) ;
if ( F_138 ( V_118 ) ) {
V_47 = - V_151 ;
break;
}
if ( F_137 ( V_144 ) || ( V_2 -> V_34 && ! V_2 -> V_34 -> V_104 ) ) {
V_47 = - V_149 ;
break;
}
if ( F_39 ( V_2 ) ) {
while ( V_49 > 0 ) {
T_2 V_171 = F_37 ( V_2 , V_142 , V_49 ) ;
if ( V_171 < 0 ) {
if ( V_171 == - V_160 )
break;
V_47 = V_171 ;
goto V_52;
}
V_142 += V_171 ;
V_49 -= V_171 ;
if ( V_49 == 0 )
break;
V_22 = * V_142 ;
if ( F_35 ( V_22 , V_2 ) < 0 )
break;
V_142 ++ ; V_49 -- ;
}
if ( V_2 -> V_44 -> V_65 )
V_2 -> V_44 -> V_65 ( V_2 ) ;
} else {
while ( V_49 > 0 ) {
V_22 = V_2 -> V_44 -> V_45 ( V_2 , V_142 , V_49 ) ;
if ( V_22 < 0 ) {
V_47 = V_22 ;
goto V_52;
}
if ( ! V_22 )
break;
V_142 += V_22 ;
V_49 -= V_22 ;
}
}
if ( ! V_49 )
break;
if ( V_144 -> V_158 & V_159 ) {
V_47 = - V_160 ;
break;
}
F_147 () ;
}
V_52:
F_140 ( V_165 ) ;
F_143 ( & V_2 -> V_135 , & V_152 ) ;
if ( V_142 - V_20 != V_49 && V_2 -> V_98 )
F_95 ( V_101 , & V_2 -> V_11 ) ;
return ( V_142 - V_20 ) ? V_142 - V_20 : V_47 ;
}
static unsigned int F_148 ( struct V_1 * V_2 , struct V_144 * V_144 ,
T_4 * V_152 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_172 = 0 ;
F_149 ( V_144 , & V_2 -> V_38 , V_152 ) ;
F_149 ( V_144 , & V_2 -> V_135 , V_152 ) ;
if ( F_119 ( V_2 , F_132 ( V_2 ) ? 0 : F_131 ( V_2 ) ) )
V_172 |= V_173 | V_174 ;
if ( V_2 -> V_35 && V_2 -> V_34 -> V_36 )
V_172 |= V_175 | V_173 | V_174 ;
if ( F_10 ( V_164 , & V_2 -> V_11 ) )
V_172 |= V_176 ;
if ( F_137 ( V_144 ) )
V_172 |= V_176 ;
if ( ! ( V_172 & ( V_176 | V_173 | V_174 ) ) ) {
if ( F_131 ( V_2 ) && ! F_132 ( V_2 ) )
V_6 -> V_115 = F_131 ( V_2 ) ;
else
V_6 -> V_115 = 1 ;
}
if ( V_2 -> V_44 -> V_45 && ! F_150 ( V_2 ) &&
F_151 ( V_2 ) < V_177 &&
F_36 ( V_2 ) > 0 )
V_172 |= V_178 | V_179 ;
return V_172 ;
}
static unsigned long F_152 ( struct V_5 * V_6 )
{
int V_49 , V_72 , V_75 ;
if ( ! V_6 -> V_15 )
return 0 ;
V_72 = V_6 -> V_30 ;
V_75 = V_6 -> V_25 ;
V_49 = ( V_72 - V_75 ) & ( V_13 - 1 ) ;
while ( V_72 != V_75 ) {
if ( F_10 ( V_75 , V_6 -> V_32 ) &&
V_6 -> V_23 [ V_75 ] == V_97 )
V_49 -- ;
V_75 = ( V_75 + 1 ) & ( V_13 - 1 ) ;
}
return V_49 ;
}
static int F_153 ( struct V_1 * V_2 , struct V_144 * V_144 ,
unsigned int V_180 , unsigned long V_181 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_47 ;
switch ( V_180 ) {
case V_182 :
return F_3 ( F_151 ( V_2 ) , ( int T_1 * ) V_181 ) ;
case V_183 :
V_47 = V_6 -> V_14 ;
if ( F_110 ( V_2 ) )
V_47 = F_152 ( V_6 ) ;
return F_3 ( V_47 , ( unsigned int T_1 * ) V_181 ) ;
default:
return F_154 ( V_2 , V_144 , V_180 , V_181 ) ;
}
}
static void F_155 ( struct V_1 * V_2 , int V_184 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! F_99 ( & V_2 -> V_38 ) ) {
if ( V_184 )
V_6 -> V_115 = 1 ;
else if ( ! V_2 -> V_98 )
V_6 -> V_115 = V_13 ;
}
}
void F_156 ( struct V_185 * V_44 )
{
* V_44 = V_186 ;
V_44 -> V_187 = NULL ;
V_44 -> V_188 = V_44 -> V_11 = 0 ;
}

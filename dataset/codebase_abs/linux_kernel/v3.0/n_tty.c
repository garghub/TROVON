static inline int F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned char T_1 * V_4 )
{
F_2 ( V_2 , & V_3 , 1 ) ;
return F_3 ( V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_5 = V_6 - V_2 -> V_7 - 1 ;
int V_8 ;
if ( V_5 <= 0 )
V_5 = V_2 -> V_9 && ! V_2 -> V_10 ;
V_8 = V_2 -> V_11 ;
V_2 -> V_11 = V_5 ;
if ( V_5 && ! V_8 )
F_5 ( & V_2 -> V_12 . V_13 ) ;
}
static void F_6 ( unsigned char V_14 , struct V_1 * V_2 )
{
if ( V_2 -> V_7 < V_6 ) {
V_2 -> V_15 [ V_2 -> V_16 ] = V_14 ;
V_2 -> V_16 = ( V_2 -> V_16 + 1 ) & ( V_6 - 1 ) ;
V_2 -> V_7 ++ ;
}
}
static void F_7 ( unsigned char V_14 , struct V_1 * V_2 )
{
unsigned long V_17 ;
F_8 ( & V_2 -> V_18 , V_17 ) ;
F_6 ( V_14 , V_2 ) ;
F_9 ( & V_2 -> V_18 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 )
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
F_8 ( & V_2 -> V_18 , V_17 ) ;
V_2 -> V_16 = V_2 -> V_20 = V_2 -> V_7 = 0 ;
F_9 ( & V_2 -> V_18 , V_17 ) ;
F_13 ( & V_2 -> V_21 ) ;
V_2 -> V_22 = V_2 -> V_23 = V_2 -> V_24 = 0 ;
F_14 ( & V_2 -> V_21 ) ;
V_2 -> V_25 = V_2 -> V_10 = V_2 -> V_26 = 0 ;
memset ( & V_2 -> V_27 , 0 , sizeof V_2 -> V_27 ) ;
F_4 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
F_12 ( V_2 ) ;
if ( ! V_2 -> V_28 )
return;
F_8 ( & V_2 -> V_29 , V_17 ) ;
if ( V_2 -> V_28 -> V_30 ) {
V_2 -> V_31 |= V_32 ;
F_16 ( & V_2 -> V_28 -> V_33 ) ;
}
F_9 ( & V_2 -> V_29 , V_17 ) ;
}
static T_2 F_17 ( struct V_1 * V_2 )
{
unsigned long V_17 ;
T_2 V_34 = 0 ;
F_8 ( & V_2 -> V_18 , V_17 ) ;
if ( ! V_2 -> V_9 ) {
V_34 = V_2 -> V_7 ;
} else if ( V_2 -> V_10 ) {
V_34 = ( V_2 -> V_25 > V_2 -> V_20 ) ?
V_2 -> V_25 - V_2 -> V_20 :
V_2 -> V_25 + ( V_6 - V_2 -> V_20 ) ;
}
F_9 ( & V_2 -> V_18 , V_17 ) ;
return V_34 ;
}
static inline int F_18 ( unsigned char V_14 )
{
return ( V_14 & 0xc0 ) == 0x80 ;
}
static inline int F_19 ( unsigned char V_14 , struct V_1 * V_2 )
{
return F_20 ( V_2 ) && F_18 ( V_14 ) ;
}
static int F_21 ( unsigned char V_14 , struct V_1 * V_2 , int V_35 )
{
int V_36 ;
if ( ! V_35 )
return - 1 ;
switch ( V_14 ) {
case '\n' :
if ( F_22 ( V_2 ) )
V_2 -> V_37 = 0 ;
if ( F_23 ( V_2 ) ) {
if ( V_35 < 2 )
return - 1 ;
V_2 -> V_38 = V_2 -> V_37 = 0 ;
V_2 -> V_39 -> V_40 ( V_2 , L_1 , 2 ) ;
return 2 ;
}
V_2 -> V_38 = V_2 -> V_37 ;
break;
case '\r' :
if ( F_24 ( V_2 ) && V_2 -> V_37 == 0 )
return 0 ;
if ( F_25 ( V_2 ) ) {
V_14 = '\n' ;
if ( F_22 ( V_2 ) )
V_2 -> V_38 = V_2 -> V_37 = 0 ;
break;
}
V_2 -> V_38 = V_2 -> V_37 = 0 ;
break;
case '\t' :
V_36 = 8 - ( V_2 -> V_37 & 7 ) ;
if ( F_26 ( V_2 ) == V_41 ) {
if ( V_35 < V_36 )
return - 1 ;
V_2 -> V_37 += V_36 ;
V_2 -> V_39 -> V_40 ( V_2 , L_2 , V_36 ) ;
return V_36 ;
}
V_2 -> V_37 += V_36 ;
break;
case '\b' :
if ( V_2 -> V_37 > 0 )
V_2 -> V_37 -- ;
break;
default:
if ( ! iscntrl ( V_14 ) ) {
if ( F_27 ( V_2 ) )
V_14 = toupper ( V_14 ) ;
if ( ! F_19 ( V_14 , V_2 ) )
V_2 -> V_37 ++ ;
}
break;
}
F_28 ( V_2 , V_14 ) ;
return 1 ;
}
static int F_29 ( unsigned char V_14 , struct V_1 * V_2 )
{
int V_35 , V_42 ;
F_13 ( & V_2 -> V_43 ) ;
V_35 = F_30 ( V_2 ) ;
V_42 = F_21 ( V_14 , V_2 , V_35 ) ;
F_14 ( & V_2 -> V_43 ) ;
if ( V_42 < 0 )
return - 1 ;
else
return 0 ;
}
static T_2 F_31 ( struct V_1 * V_2 ,
const unsigned char * V_12 , unsigned int V_44 )
{
int V_35 ;
int V_45 ;
const unsigned char * V_46 ;
F_13 ( & V_2 -> V_43 ) ;
V_35 = F_30 ( V_2 ) ;
if ( ! V_35 ) {
F_14 ( & V_2 -> V_43 ) ;
return 0 ;
}
if ( V_44 > V_35 )
V_44 = V_35 ;
for ( V_45 = 0 , V_46 = V_12 ; V_45 < V_44 ; V_45 ++ , V_46 ++ ) {
unsigned char V_14 = * V_46 ;
switch ( V_14 ) {
case '\n' :
if ( F_22 ( V_2 ) )
V_2 -> V_37 = 0 ;
if ( F_23 ( V_2 ) )
goto V_47;
V_2 -> V_38 = V_2 -> V_37 ;
break;
case '\r' :
if ( F_24 ( V_2 ) && V_2 -> V_37 == 0 )
goto V_47;
if ( F_25 ( V_2 ) )
goto V_47;
V_2 -> V_38 = V_2 -> V_37 = 0 ;
break;
case '\t' :
goto V_47;
case '\b' :
if ( V_2 -> V_37 > 0 )
V_2 -> V_37 -- ;
break;
default:
if ( ! iscntrl ( V_14 ) ) {
if ( F_27 ( V_2 ) )
goto V_47;
if ( ! F_19 ( V_14 , V_2 ) )
V_2 -> V_37 ++ ;
}
break;
}
}
V_47:
V_45 = V_2 -> V_39 -> V_40 ( V_2 , V_12 , V_45 ) ;
F_14 ( & V_2 -> V_43 ) ;
return V_45 ;
}
static void F_32 ( struct V_1 * V_2 )
{
int V_35 , V_44 ;
unsigned char V_14 ;
unsigned char * V_46 , * V_48 ;
if ( ! V_2 -> V_23 )
return;
F_13 ( & V_2 -> V_43 ) ;
F_13 ( & V_2 -> V_21 ) ;
V_35 = F_30 ( V_2 ) ;
V_48 = V_2 -> V_49 + V_6 ;
V_46 = V_2 -> V_49 + V_2 -> V_22 ;
V_44 = V_2 -> V_23 ;
while ( V_44 > 0 ) {
V_14 = * V_46 ;
if ( V_14 == V_50 ) {
unsigned char V_51 ;
unsigned char * V_52 ;
int V_53 = 0 ;
V_52 = V_46 + 1 ;
if ( V_52 == V_48 )
V_52 -= V_6 ;
V_51 = * V_52 ;
switch ( V_51 ) {
unsigned int V_54 , V_55 ;
case V_56 :
if ( ++ V_52 == V_48 )
V_52 -= V_6 ;
V_54 = * V_52 ;
if ( ! ( V_54 & 0x80 ) )
V_54 += V_2 -> V_38 ;
V_55 = 8 - ( V_54 & 7 ) ;
if ( V_55 > V_35 ) {
V_53 = 1 ;
break;
}
V_35 -= V_55 ;
while ( V_55 -- ) {
F_28 ( V_2 , '\b' ) ;
if ( V_2 -> V_37 > 0 )
V_2 -> V_37 -- ;
}
V_46 += 3 ;
V_44 -= 3 ;
break;
case V_57 :
V_2 -> V_38 = V_2 -> V_37 ;
V_46 += 2 ;
V_44 -= 2 ;
break;
case V_58 :
if ( V_2 -> V_37 > 0 )
V_2 -> V_37 -- ;
V_46 += 2 ;
V_44 -= 2 ;
break;
case V_50 :
if ( ! V_35 ) {
V_53 = 1 ;
break;
}
F_28 ( V_2 , V_50 ) ;
V_2 -> V_37 ++ ;
V_35 -- ;
V_46 += 2 ;
V_44 -= 2 ;
break;
default:
if ( V_35 < 2 ) {
V_53 = 1 ;
break;
}
F_28 ( V_2 , '^' ) ;
F_28 ( V_2 , V_51 ^ 0100 ) ;
V_2 -> V_37 += 2 ;
V_35 -= 2 ;
V_46 += 2 ;
V_44 -= 2 ;
}
if ( V_53 )
break;
} else {
if ( F_33 ( V_2 ) &&
! ( F_34 ( V_59 , & V_2 -> V_17 ) ) ) {
int V_42 = F_21 ( V_14 , V_2 , V_35 ) ;
if ( V_42 < 0 )
break;
V_35 -= V_42 ;
} else {
if ( ! V_35 )
break;
F_28 ( V_2 , V_14 ) ;
V_35 -= 1 ;
}
V_46 += 1 ;
V_44 -= 1 ;
}
if ( V_46 >= V_48 )
V_46 -= V_6 ;
}
if ( V_44 == 0 ) {
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
} else {
int V_60 = V_2 -> V_23 - V_44 ;
V_2 -> V_22 += V_60 ;
V_2 -> V_22 &= V_6 - 1 ;
V_2 -> V_23 = V_44 ;
if ( V_60 > 0 )
V_2 -> V_24 = 0 ;
}
F_14 ( & V_2 -> V_21 ) ;
F_14 ( & V_2 -> V_43 ) ;
if ( V_2 -> V_39 -> V_61 )
V_2 -> V_39 -> V_61 ( V_2 ) ;
}
static void F_35 ( unsigned char V_14 , struct V_1 * V_2 )
{
int V_62 ;
if ( V_2 -> V_23 == V_6 ) {
V_62 = V_2 -> V_22 ;
if ( V_2 -> V_49 [ V_2 -> V_22 ] == V_50 ) {
if ( V_2 -> V_49 [ ( V_2 -> V_22 + 1 ) &
( V_6 - 1 ) ] ==
V_56 ) {
V_2 -> V_22 += 3 ;
V_2 -> V_23 -= 2 ;
} else {
V_2 -> V_22 += 2 ;
V_2 -> V_23 -= 1 ;
}
} else {
V_2 -> V_22 ++ ;
}
V_2 -> V_22 &= V_6 - 1 ;
V_2 -> V_24 = 1 ;
} else {
V_62 = V_2 -> V_22 + V_2 -> V_23 ;
V_62 &= V_6 - 1 ;
V_2 -> V_23 ++ ;
}
V_2 -> V_49 [ V_62 ] = V_14 ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_21 ) ;
F_35 ( V_50 , V_2 ) ;
F_35 ( V_58 , V_2 ) ;
F_14 ( & V_2 -> V_21 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_21 ) ;
F_35 ( V_50 , V_2 ) ;
F_35 ( V_57 , V_2 ) ;
F_14 ( & V_2 -> V_21 ) ;
}
static void F_38 ( unsigned int V_54 , int V_63 ,
struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_21 ) ;
F_35 ( V_50 , V_2 ) ;
F_35 ( V_56 , V_2 ) ;
V_54 &= 7 ;
if ( V_63 )
V_54 |= 0x80 ;
F_35 ( V_54 , V_2 ) ;
F_14 ( & V_2 -> V_21 ) ;
}
static void F_39 ( unsigned char V_14 , struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_21 ) ;
if ( V_14 == V_50 ) {
F_35 ( V_50 , V_2 ) ;
F_35 ( V_50 , V_2 ) ;
} else {
F_35 ( V_14 , V_2 ) ;
}
F_14 ( & V_2 -> V_21 ) ;
}
static void F_40 ( unsigned char V_14 , struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_21 ) ;
if ( V_14 == V_50 ) {
F_35 ( V_50 , V_2 ) ;
F_35 ( V_50 , V_2 ) ;
} else {
if ( F_41 ( V_2 ) && iscntrl ( V_14 ) && V_14 != '\t' )
F_35 ( V_50 , V_2 ) ;
F_35 ( V_14 , V_2 ) ;
}
F_14 ( & V_2 -> V_21 ) ;
}
static inline void F_42 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 ) {
F_39 ( '/' , V_2 ) ;
V_2 -> V_26 = 0 ;
}
}
static void F_43 ( unsigned char V_14 , struct V_1 * V_2 )
{
enum { V_64 , V_65 , V_66 } V_67 ;
int V_68 , V_69 , V_70 ;
unsigned long V_17 ;
if ( V_2 -> V_16 == V_2 -> V_25 ) {
return;
}
if ( V_14 == F_44 ( V_2 ) )
V_67 = V_64 ;
else if ( V_14 == F_45 ( V_2 ) )
V_67 = V_65 ;
else {
if ( ! F_46 ( V_2 ) ) {
F_8 ( & V_2 -> V_18 , V_17 ) ;
V_2 -> V_7 -= ( ( V_2 -> V_16 - V_2 -> V_25 ) &
( V_6 - 1 ) ) ;
V_2 -> V_16 = V_2 -> V_25 ;
F_9 ( & V_2 -> V_18 , V_17 ) ;
return;
}
if ( ! F_47 ( V_2 ) || ! F_48 ( V_2 ) || ! F_49 ( V_2 ) ) {
F_8 ( & V_2 -> V_18 , V_17 ) ;
V_2 -> V_7 -= ( ( V_2 -> V_16 - V_2 -> V_25 ) &
( V_6 - 1 ) ) ;
V_2 -> V_16 = V_2 -> V_25 ;
F_9 ( & V_2 -> V_18 , V_17 ) ;
F_42 ( V_2 ) ;
F_40 ( F_50 ( V_2 ) , V_2 ) ;
if ( F_47 ( V_2 ) )
F_39 ( '\n' , V_2 ) ;
return;
}
V_67 = V_66 ;
}
V_69 = 0 ;
while ( V_2 -> V_16 != V_2 -> V_25 ) {
V_68 = V_2 -> V_16 ;
do {
V_68 = ( V_68 - 1 ) & ( V_6 - 1 ) ;
V_14 = V_2 -> V_15 [ V_68 ] ;
} while ( F_19 ( V_14 , V_2 ) && V_68 != V_2 -> V_25 );
if ( F_19 ( V_14 , V_2 ) )
break;
if ( V_67 == V_65 ) {
if ( isalnum ( V_14 ) || V_14 == '_' )
V_69 ++ ;
else if ( V_69 )
break;
}
V_70 = ( V_2 -> V_16 - V_68 ) & ( V_6 - 1 ) ;
F_8 ( & V_2 -> V_18 , V_17 ) ;
V_2 -> V_16 = V_68 ;
V_2 -> V_7 -= V_70 ;
F_9 ( & V_2 -> V_18 , V_17 ) ;
if ( F_46 ( V_2 ) ) {
if ( F_51 ( V_2 ) ) {
if ( ! V_2 -> V_26 ) {
F_39 ( '\\' , V_2 ) ;
V_2 -> V_26 = 1 ;
}
F_40 ( V_14 , V_2 ) ;
while ( -- V_70 > 0 ) {
V_68 = ( V_68 + 1 ) & ( V_6 - 1 ) ;
F_39 ( V_2 -> V_15 [ V_68 ] , V_2 ) ;
F_36 ( V_2 ) ;
}
} else if ( V_67 == V_64 && ! F_49 ( V_2 ) ) {
F_40 ( F_44 ( V_2 ) , V_2 ) ;
} else if ( V_14 == '\t' ) {
unsigned int V_54 = 0 ;
int V_63 = 0 ;
unsigned long V_71 = V_2 -> V_16 ;
while ( V_71 != V_2 -> V_25 ) {
V_71 = ( V_71 - 1 ) & ( V_6 - 1 ) ;
V_14 = V_2 -> V_15 [ V_71 ] ;
if ( V_14 == '\t' ) {
V_63 = 1 ;
break;
} else if ( iscntrl ( V_14 ) ) {
if ( F_41 ( V_2 ) )
V_54 += 2 ;
} else if ( ! F_19 ( V_14 , V_2 ) ) {
V_54 ++ ;
}
}
F_38 ( V_54 , V_63 , V_2 ) ;
} else {
if ( iscntrl ( V_14 ) && F_41 ( V_2 ) ) {
F_39 ( '\b' , V_2 ) ;
F_39 ( ' ' , V_2 ) ;
F_39 ( '\b' , V_2 ) ;
}
if ( ! iscntrl ( V_14 ) || F_41 ( V_2 ) ) {
F_39 ( '\b' , V_2 ) ;
F_39 ( ' ' , V_2 ) ;
F_39 ( '\b' , V_2 ) ;
}
}
}
if ( V_67 == V_64 )
break;
}
if ( V_2 -> V_16 == V_2 -> V_25 && F_46 ( V_2 ) )
F_42 ( V_2 ) ;
}
static inline void F_52 ( int V_72 , struct V_1 * V_2 , int V_73 )
{
if ( V_2 -> V_74 )
F_53 ( V_2 -> V_74 , V_72 , 1 ) ;
if ( V_73 || ! F_54 ( V_2 ) ) {
F_15 ( V_2 ) ;
F_55 ( V_2 ) ;
}
}
static inline void F_56 ( struct V_1 * V_2 )
{
if ( F_57 ( V_2 ) )
return;
if ( F_58 ( V_2 ) ) {
F_52 ( V_75 , V_2 , 1 ) ;
return;
}
if ( F_59 ( V_2 ) ) {
F_7 ( '\377' , V_2 ) ;
F_7 ( '\0' , V_2 ) ;
}
F_7 ( '\0' , V_2 ) ;
F_16 ( & V_2 -> V_33 ) ;
}
static inline void F_60 ( struct V_1 * V_2 )
{
char V_12 [ 64 ] ;
V_2 -> V_76 ++ ;
if ( F_61 ( V_2 -> V_77 , V_78 - V_79 ) ||
F_62 ( V_2 -> V_77 , V_78 ) ) {
F_63 ( V_80 L_3 ,
F_64 ( V_2 , V_12 ) ,
V_2 -> V_76 ) ;
V_2 -> V_77 = V_78 ;
V_2 -> V_76 = 0 ;
}
}
static inline void F_65 ( struct V_1 * V_2 ,
unsigned char V_14 )
{
if ( F_66 ( V_2 ) )
return;
if ( F_59 ( V_2 ) ) {
F_7 ( '\377' , V_2 ) ;
F_7 ( '\0' , V_2 ) ;
F_7 ( V_14 , V_2 ) ;
} else if ( F_67 ( V_2 ) )
F_7 ( '\0' , V_2 ) ;
else
F_7 ( V_14 , V_2 ) ;
F_16 ( & V_2 -> V_33 ) ;
}
static inline void F_68 ( struct V_1 * V_2 , unsigned char V_14 )
{
unsigned long V_17 ;
int V_81 ;
if ( V_2 -> V_82 ) {
F_7 ( V_14 , V_2 ) ;
return;
}
if ( F_69 ( V_2 ) )
V_14 &= 0x7f ;
if ( F_70 ( V_2 ) && F_71 ( V_2 ) )
V_14 = tolower ( V_14 ) ;
if ( F_72 ( V_2 ) ) {
F_7 ( V_14 , V_2 ) ;
return;
}
if ( V_2 -> V_83 && ! V_2 -> V_84 && F_73 ( V_2 ) &&
F_74 ( V_2 ) && V_14 != F_75 ( V_2 ) && V_14 != F_76 ( V_2 ) &&
V_14 != F_77 ( V_2 ) && V_14 != F_78 ( V_2 ) && V_14 != F_79 ( V_2 ) ) {
F_80 ( V_2 ) ;
F_32 ( V_2 ) ;
}
if ( V_2 -> V_85 ) {
if ( F_73 ( V_2 ) ) {
if ( V_14 == F_75 ( V_2 ) ) {
F_80 ( V_2 ) ;
F_32 ( V_2 ) ;
} else if ( V_14 == F_76 ( V_2 ) )
F_81 ( V_2 ) ;
}
return;
}
if ( ! F_34 ( V_14 , V_2 -> V_86 ) || V_2 -> V_87 ) {
V_2 -> V_87 = 0 ;
V_81 = ( V_14 == ( unsigned char ) '\377' && F_59 ( V_2 ) ) ? 1 : 0 ;
if ( V_2 -> V_7 >= ( V_6 - V_81 - 1 ) ) {
if ( F_46 ( V_2 ) )
F_29 ( '\a' , V_2 ) ;
return;
}
if ( F_46 ( V_2 ) ) {
F_42 ( V_2 ) ;
if ( V_2 -> V_25 == V_2 -> V_16 )
F_37 ( V_2 ) ;
F_40 ( V_14 , V_2 ) ;
F_32 ( V_2 ) ;
}
if ( V_81 )
F_7 ( V_14 , V_2 ) ;
F_7 ( V_14 , V_2 ) ;
return;
}
if ( F_73 ( V_2 ) ) {
if ( V_14 == F_75 ( V_2 ) ) {
F_80 ( V_2 ) ;
F_32 ( V_2 ) ;
return;
}
if ( V_14 == F_76 ( V_2 ) ) {
F_81 ( V_2 ) ;
return;
}
}
if ( F_82 ( V_2 ) ) {
int signal ;
signal = V_75 ;
if ( V_14 == F_77 ( V_2 ) )
goto V_88;
signal = V_89 ;
if ( V_14 == F_78 ( V_2 ) )
goto V_88;
signal = V_90 ;
if ( V_14 == F_79 ( V_2 ) ) {
V_88:
if ( ! F_54 ( V_2 ) ) {
F_15 ( V_2 ) ;
F_55 ( V_2 ) ;
}
if ( F_73 ( V_2 ) )
F_80 ( V_2 ) ;
if ( F_46 ( V_2 ) ) {
F_40 ( V_14 , V_2 ) ;
F_32 ( V_2 ) ;
}
if ( V_2 -> V_74 )
F_53 ( V_2 -> V_74 , signal , 1 ) ;
return;
}
}
if ( V_14 == '\r' ) {
if ( F_83 ( V_2 ) )
return;
if ( F_84 ( V_2 ) )
V_14 = '\n' ;
} else if ( V_14 == '\n' && F_85 ( V_2 ) )
V_14 = '\r' ;
if ( V_2 -> V_9 ) {
if ( V_14 == F_44 ( V_2 ) || V_14 == F_50 ( V_2 ) ||
( V_14 == F_45 ( V_2 ) && F_71 ( V_2 ) ) ) {
F_43 ( V_14 , V_2 ) ;
F_32 ( V_2 ) ;
return;
}
if ( V_14 == F_86 ( V_2 ) && F_71 ( V_2 ) ) {
V_2 -> V_87 = 1 ;
if ( F_46 ( V_2 ) ) {
F_42 ( V_2 ) ;
if ( F_41 ( V_2 ) ) {
F_39 ( '^' , V_2 ) ;
F_39 ( '\b' , V_2 ) ;
F_32 ( V_2 ) ;
}
}
return;
}
if ( V_14 == F_87 ( V_2 ) && F_46 ( V_2 ) &&
F_71 ( V_2 ) ) {
unsigned long V_71 = V_2 -> V_25 ;
F_42 ( V_2 ) ;
F_40 ( V_14 , V_2 ) ;
F_39 ( '\n' , V_2 ) ;
while ( V_71 != V_2 -> V_16 ) {
F_40 ( V_2 -> V_15 [ V_71 ] , V_2 ) ;
V_71 = ( V_71 + 1 ) & ( V_6 - 1 ) ;
}
F_32 ( V_2 ) ;
return;
}
if ( V_14 == '\n' ) {
if ( V_2 -> V_7 >= V_6 ) {
if ( F_46 ( V_2 ) )
F_29 ( '\a' , V_2 ) ;
return;
}
if ( F_46 ( V_2 ) || F_88 ( V_2 ) ) {
F_39 ( '\n' , V_2 ) ;
F_32 ( V_2 ) ;
}
goto V_91;
}
if ( V_14 == F_89 ( V_2 ) ) {
if ( V_2 -> V_7 >= V_6 )
return;
if ( V_2 -> V_25 != V_2 -> V_16 )
F_90 ( V_92 , & V_2 -> V_17 ) ;
V_14 = V_93 ;
goto V_91;
}
if ( ( V_14 == F_91 ( V_2 ) ) ||
( V_14 == F_92 ( V_2 ) && F_71 ( V_2 ) ) ) {
V_81 = ( V_14 == ( unsigned char ) '\377' && F_59 ( V_2 ) )
? 1 : 0 ;
if ( V_2 -> V_7 >= ( V_6 - V_81 ) ) {
if ( F_46 ( V_2 ) )
F_29 ( '\a' , V_2 ) ;
return;
}
if ( F_46 ( V_2 ) ) {
if ( V_2 -> V_25 == V_2 -> V_16 )
F_37 ( V_2 ) ;
F_40 ( V_14 , V_2 ) ;
F_32 ( V_2 ) ;
}
if ( V_81 )
F_7 ( V_14 , V_2 ) ;
V_91:
F_8 ( & V_2 -> V_18 , V_17 ) ;
F_90 ( V_2 -> V_16 , V_2 -> V_27 ) ;
F_6 ( V_14 , V_2 ) ;
V_2 -> V_25 = V_2 -> V_16 ;
V_2 -> V_10 ++ ;
F_9 ( & V_2 -> V_18 , V_17 ) ;
F_93 ( & V_2 -> V_94 , V_95 , V_96 ) ;
if ( F_94 ( & V_2 -> V_33 ) )
F_16 ( & V_2 -> V_33 ) ;
return;
}
}
V_81 = ( V_14 == ( unsigned char ) '\377' && F_59 ( V_2 ) ) ? 1 : 0 ;
if ( V_2 -> V_7 >= ( V_6 - V_81 - 1 ) ) {
if ( F_46 ( V_2 ) )
F_29 ( '\a' , V_2 ) ;
return;
}
if ( F_46 ( V_2 ) ) {
F_42 ( V_2 ) ;
if ( V_14 == '\n' )
F_39 ( '\n' , V_2 ) ;
else {
if ( V_2 -> V_25 == V_2 -> V_16 )
F_37 ( V_2 ) ;
F_40 ( V_14 , V_2 ) ;
}
F_32 ( V_2 ) ;
}
if ( V_81 )
F_7 ( V_14 , V_2 ) ;
F_7 ( V_14 , V_2 ) ;
}
static void F_95 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 && F_96 ( V_97 , & V_2 -> V_17 ) )
F_93 ( & V_2 -> V_94 , V_95 , V_98 ) ;
}
static void F_97 ( struct V_1 * V_2 , const unsigned char * V_46 ,
char * V_99 , int V_19 )
{
const unsigned char * V_100 ;
char * V_101 , V_17 = V_102 ;
int V_45 ;
char V_12 [ 64 ] ;
unsigned long V_103 ;
if ( ! V_2 -> V_15 )
return;
if ( V_2 -> V_104 ) {
F_8 ( & V_2 -> V_18 , V_103 ) ;
V_45 = F_98 ( V_6 - V_2 -> V_7 ,
V_6 - V_2 -> V_16 ) ;
V_45 = F_98 ( V_19 , V_45 ) ;
memcpy ( V_2 -> V_15 + V_2 -> V_16 , V_46 , V_45 ) ;
V_2 -> V_16 = ( V_2 -> V_16 + V_45 ) & ( V_6 - 1 ) ;
V_2 -> V_7 += V_45 ;
V_46 += V_45 ;
V_19 -= V_45 ;
V_45 = F_98 ( V_6 - V_2 -> V_7 ,
V_6 - V_2 -> V_16 ) ;
V_45 = F_98 ( V_19 , V_45 ) ;
memcpy ( V_2 -> V_15 + V_2 -> V_16 , V_46 , V_45 ) ;
V_2 -> V_16 = ( V_2 -> V_16 + V_45 ) & ( V_6 - 1 ) ;
V_2 -> V_7 += V_45 ;
F_9 ( & V_2 -> V_18 , V_103 ) ;
} else {
for ( V_45 = V_19 , V_100 = V_46 , V_101 = V_99 ; V_45 ; V_45 -- , V_100 ++ ) {
if ( V_101 )
V_17 = * V_101 ++ ;
switch ( V_17 ) {
case V_102 :
F_68 ( V_2 , * V_100 ) ;
break;
case V_105 :
F_56 ( V_2 ) ;
break;
case V_106 :
case V_107 :
F_65 ( V_2 , * V_100 ) ;
break;
case V_108 :
F_60 ( V_2 ) ;
break;
default:
F_63 ( V_109 L_4 ,
F_64 ( V_2 , V_12 ) , V_17 ) ;
break;
}
}
if ( V_2 -> V_39 -> V_61 )
V_2 -> V_39 -> V_61 ( V_2 ) ;
}
F_4 ( V_2 ) ;
if ( ( ! V_2 -> V_9 && ( V_2 -> V_7 >= V_2 -> V_110 ) ) ||
F_72 ( V_2 ) ) {
F_93 ( & V_2 -> V_94 , V_95 , V_96 ) ;
if ( F_94 ( & V_2 -> V_33 ) )
F_16 ( & V_2 -> V_33 ) ;
}
if ( V_2 -> V_11 < V_111 )
F_99 ( V_2 ) ;
}
int F_100 ( int V_72 )
{
return ( F_101 ( & V_112 -> V_113 , V_72 ) ||
V_112 -> V_114 -> V_115 [ V_72 - 1 ] . V_116 . V_117 == V_118 ) ;
}
static void F_102 ( struct V_1 * V_2 , struct V_119 * V_120 )
{
int V_121 = 1 ;
F_103 ( ! V_2 ) ;
if ( V_120 )
V_121 = ( V_120 -> V_122 ^ V_2 -> V_123 -> V_122 ) & V_124 ;
if ( V_121 ) {
memset ( & V_2 -> V_27 , 0 , sizeof V_2 -> V_27 ) ;
V_2 -> V_25 = V_2 -> V_20 ;
V_2 -> V_10 = 0 ;
V_2 -> V_26 = 0 ;
}
if ( V_121 && ! F_104 ( V_2 ) && V_2 -> V_7 )
F_16 ( & V_2 -> V_33 ) ;
V_2 -> V_9 = ( F_104 ( V_2 ) != 0 ) ;
if ( F_34 ( V_125 , & V_2 -> V_17 ) ) {
V_2 -> V_82 = 1 ;
V_2 -> V_104 = 1 ;
F_4 ( V_2 ) ;
return;
}
if ( F_69 ( V_2 ) || F_70 ( V_2 ) || F_83 ( V_2 ) ||
F_84 ( V_2 ) || F_85 ( V_2 ) || F_104 ( V_2 ) ||
F_73 ( V_2 ) || F_82 ( V_2 ) || F_46 ( V_2 ) ||
F_59 ( V_2 ) ) {
memset ( V_2 -> V_86 , 0 , 256 / 8 ) ;
if ( F_83 ( V_2 ) || F_84 ( V_2 ) )
F_90 ( '\r' , V_2 -> V_86 ) ;
if ( F_85 ( V_2 ) )
F_90 ( '\n' , V_2 -> V_86 ) ;
if ( F_104 ( V_2 ) ) {
F_90 ( F_44 ( V_2 ) , V_2 -> V_86 ) ;
F_90 ( F_50 ( V_2 ) , V_2 -> V_86 ) ;
F_90 ( F_89 ( V_2 ) , V_2 -> V_86 ) ;
F_90 ( '\n' , V_2 -> V_86 ) ;
F_90 ( F_91 ( V_2 ) , V_2 -> V_86 ) ;
if ( F_71 ( V_2 ) ) {
F_90 ( F_45 ( V_2 ) ,
V_2 -> V_86 ) ;
F_90 ( F_86 ( V_2 ) ,
V_2 -> V_86 ) ;
F_90 ( F_92 ( V_2 ) ,
V_2 -> V_86 ) ;
if ( F_46 ( V_2 ) )
F_90 ( F_87 ( V_2 ) ,
V_2 -> V_86 ) ;
}
}
if ( F_73 ( V_2 ) ) {
F_90 ( F_75 ( V_2 ) , V_2 -> V_86 ) ;
F_90 ( F_76 ( V_2 ) , V_2 -> V_86 ) ;
}
if ( F_82 ( V_2 ) ) {
F_90 ( F_77 ( V_2 ) , V_2 -> V_86 ) ;
F_90 ( F_78 ( V_2 ) , V_2 -> V_86 ) ;
F_90 ( F_79 ( V_2 ) , V_2 -> V_86 ) ;
}
F_105 ( V_93 , V_2 -> V_86 ) ;
V_2 -> V_82 = 0 ;
V_2 -> V_104 = 0 ;
} else {
V_2 -> V_82 = 1 ;
if ( ( F_57 ( V_2 ) || ( ! F_58 ( V_2 ) && ! F_59 ( V_2 ) ) ) &&
( F_66 ( V_2 ) || ! F_67 ( V_2 ) ) &&
( V_2 -> V_126 -> V_17 & V_127 ) )
V_2 -> V_104 = 1 ;
else
V_2 -> V_104 = 0 ;
}
F_4 ( V_2 ) ;
F_16 ( & V_2 -> V_128 ) ;
F_16 ( & V_2 -> V_33 ) ;
}
static void F_106 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
if ( V_2 -> V_15 ) {
F_107 ( V_2 -> V_15 ) ;
V_2 -> V_15 = NULL ;
}
if ( V_2 -> V_49 ) {
F_107 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
}
}
static int F_108 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return - V_129 ;
if ( ! V_2 -> V_15 ) {
V_2 -> V_15 = F_109 ( V_6 , V_130 ) ;
if ( ! V_2 -> V_15 )
return - V_131 ;
}
if ( ! V_2 -> V_49 ) {
V_2 -> V_49 = F_109 ( V_6 , V_130 ) ;
if ( ! V_2 -> V_49 )
return - V_131 ;
}
F_12 ( V_2 ) ;
V_2 -> V_37 = 0 ;
F_102 ( V_2 , NULL ) ;
V_2 -> V_110 = 1 ;
V_2 -> V_85 = 0 ;
return 0 ;
}
static inline int F_110 ( struct V_1 * V_2 , int V_132 )
{
F_111 ( V_2 ) ;
if ( V_2 -> V_9 && ! F_72 ( V_2 ) ) {
if ( V_2 -> V_10 )
return 1 ;
} else if ( V_2 -> V_7 >= ( V_132 ? V_132 : 1 ) )
return 1 ;
return 0 ;
}
static int F_112 ( struct V_1 * V_2 ,
unsigned char T_1 * * V_133 ,
T_3 * V_44 )
{
int V_42 ;
T_3 V_34 ;
unsigned long V_17 ;
V_42 = 0 ;
F_8 ( & V_2 -> V_18 , V_17 ) ;
V_34 = F_98 ( V_2 -> V_7 , V_6 - V_2 -> V_20 ) ;
V_34 = F_98 ( * V_44 , V_34 ) ;
F_9 ( & V_2 -> V_18 , V_17 ) ;
if ( V_34 ) {
V_42 = F_113 ( * V_133 , & V_2 -> V_15 [ V_2 -> V_20 ] , V_34 ) ;
V_34 -= V_42 ;
F_2 ( V_2 , & V_2 -> V_15 [ V_2 -> V_20 ] , V_34 ) ;
F_8 ( & V_2 -> V_18 , V_17 ) ;
V_2 -> V_20 = ( V_2 -> V_20 + V_34 ) & ( V_6 - 1 ) ;
V_2 -> V_7 -= V_34 ;
if ( F_72 ( V_2 ) && V_2 -> V_9 && V_34 == 1 ) {
if ( ! V_2 -> V_7 && ( * V_133 ) [ V_34 - 1 ] == F_89 ( V_2 ) )
V_34 -- ;
}
F_9 ( & V_2 -> V_18 , V_17 ) ;
* V_133 += V_34 ;
* V_44 -= V_34 ;
}
return V_42 ;
}
static int F_114 ( struct V_1 * V_2 , struct V_134 * V_134 )
{
if ( V_134 -> V_135 -> V_40 != V_136 &&
V_112 -> signal -> V_2 == V_2 ) {
if ( ! V_2 -> V_74 )
F_63 ( V_109 L_5 ) ;
else if ( F_115 ( V_112 ) != V_2 -> V_74 ) {
if ( F_100 ( V_137 ) ||
F_116 () )
return - V_138 ;
F_53 ( F_115 ( V_112 ) , V_137 , 1 ) ;
F_117 ( V_139 ) ;
return - V_140 ;
}
}
return 0 ;
}
static T_2 F_118 ( struct V_1 * V_2 , struct V_134 * V_134 ,
unsigned char T_1 * V_12 , T_3 V_44 )
{
unsigned char T_1 * V_133 = V_12 ;
F_119 ( V_141 , V_112 ) ;
int V_14 ;
int V_142 , time ;
T_2 V_42 = 0 ;
T_2 V_143 ;
long V_144 ;
unsigned long V_17 ;
int V_30 ;
V_145:
F_103 ( ! V_2 -> V_15 ) ;
V_14 = F_114 ( V_2 , V_134 ) ;
if ( V_14 < 0 )
return V_14 ;
V_142 = time = 0 ;
V_144 = V_146 ;
if ( ! V_2 -> V_9 ) {
time = ( V_79 / 10 ) * F_120 ( V_2 ) ;
V_142 = F_121 ( V_2 ) ;
if ( V_142 ) {
if ( time )
V_2 -> V_110 = 1 ;
else if ( ! F_94 ( & V_2 -> V_33 ) ||
( V_2 -> V_110 > V_142 ) )
V_2 -> V_110 = V_142 ;
} else {
V_144 = 0 ;
if ( time ) {
V_144 = time ;
time = 0 ;
}
V_2 -> V_110 = V_142 = 1 ;
}
}
if ( V_134 -> V_147 & V_148 ) {
if ( ! F_122 ( & V_2 -> V_149 ) )
return - V_150 ;
} else {
if ( F_123 ( & V_2 -> V_149 ) )
return - V_140 ;
}
V_30 = V_2 -> V_30 ;
F_124 ( & V_2 -> V_33 , & V_141 ) ;
while ( V_44 ) {
if ( V_30 && V_2 -> V_28 -> V_31 ) {
unsigned char V_151 ;
if ( V_133 != V_12 )
break;
F_8 ( & V_2 -> V_28 -> V_29 , V_17 ) ;
V_151 = V_2 -> V_28 -> V_31 ;
V_2 -> V_28 -> V_31 = 0 ;
F_9 ( & V_2 -> V_28 -> V_29 , V_17 ) ;
if ( F_1 ( V_2 , V_151 , V_133 ++ ) ) {
V_42 = - V_152 ;
V_133 -- ;
break;
}
V_44 -- ;
break;
}
F_125 ( V_153 ) ;
if ( ( ( V_142 - ( V_133 - V_12 ) ) < V_2 -> V_110 ) &&
( ( V_142 - ( V_133 - V_12 ) ) >= 1 ) )
V_2 -> V_110 = ( V_142 - ( V_133 - V_12 ) ) ;
if ( ! F_110 ( V_2 , 0 ) ) {
if ( F_34 ( V_154 , & V_2 -> V_17 ) ) {
V_42 = - V_138 ;
break;
}
if ( F_126 ( V_134 ) )
break;
if ( ! V_144 )
break;
if ( V_134 -> V_147 & V_148 ) {
V_42 = - V_150 ;
break;
}
if ( F_127 ( V_112 ) ) {
V_42 = - V_140 ;
break;
}
F_4 ( V_2 ) ;
V_144 = F_128 ( V_144 ) ;
F_103 ( ! V_2 -> V_15 ) ;
continue;
}
F_129 ( V_155 ) ;
if ( V_30 && V_133 == V_12 ) {
if ( F_1 ( V_2 , V_156 , V_133 ++ ) ) {
V_42 = - V_152 ;
V_133 -- ;
break;
}
V_44 -- ;
}
if ( V_2 -> V_9 && ! F_72 ( V_2 ) ) {
while ( V_44 && V_2 -> V_7 ) {
int V_157 ;
V_157 = F_96 ( V_2 -> V_20 ,
V_2 -> V_27 ) ;
V_14 = V_2 -> V_15 [ V_2 -> V_20 ] ;
F_8 ( & V_2 -> V_18 , V_17 ) ;
V_2 -> V_20 = ( ( V_2 -> V_20 + 1 ) &
( V_6 - 1 ) ) ;
V_2 -> V_7 -- ;
if ( V_157 ) {
if ( -- V_2 -> V_10 < 0 )
V_2 -> V_10 = 0 ;
}
F_9 ( & V_2 -> V_18 , V_17 ) ;
if ( ! V_157 || ( V_14 != V_93 ) ) {
if ( F_1 ( V_2 , V_14 , V_133 ++ ) ) {
V_42 = - V_152 ;
V_133 -- ;
break;
}
V_44 -- ;
}
if ( V_157 ) {
F_130 ( V_2 ) ;
break;
}
}
if ( V_42 )
break;
} else {
int V_158 ;
V_158 = F_112 ( V_2 , & V_133 , & V_44 ) ;
V_158 += F_112 ( V_2 , & V_133 , & V_44 ) ;
if ( V_158 ) {
V_42 = - V_152 ;
break;
}
}
if ( F_17 ( V_2 ) <= V_159 ) {
F_4 ( V_2 ) ;
F_10 ( V_2 ) ;
}
if ( V_133 - V_12 >= V_142 )
break;
if ( time )
V_144 = time ;
}
F_14 ( & V_2 -> V_149 ) ;
F_131 ( & V_2 -> V_33 , & V_141 ) ;
if ( ! F_94 ( & V_2 -> V_33 ) )
V_2 -> V_110 = V_142 ;
F_129 ( V_155 ) ;
V_143 = V_133 - V_12 ;
if ( V_143 ) {
V_42 = V_143 ;
if ( V_44 )
F_105 ( V_92 , & V_2 -> V_17 ) ;
} else if ( F_96 ( V_92 , & V_2 -> V_17 ) )
goto V_145;
F_4 ( V_2 ) ;
return V_42 ;
}
static T_2 F_132 ( struct V_1 * V_2 , struct V_134 * V_134 ,
const unsigned char * V_12 , T_3 V_44 )
{
const unsigned char * V_133 = V_12 ;
F_119 ( V_141 , V_112 ) ;
int V_14 ;
T_2 V_42 = 0 ;
if ( F_133 ( V_2 ) && V_134 -> V_135 -> V_40 != V_136 ) {
V_42 = F_134 ( V_2 ) ;
if ( V_42 )
return V_42 ;
}
F_32 ( V_2 ) ;
F_124 ( & V_2 -> V_128 , & V_141 ) ;
while ( 1 ) {
F_125 ( V_153 ) ;
if ( F_127 ( V_112 ) ) {
V_42 = - V_140 ;
break;
}
if ( F_126 ( V_134 ) || ( V_2 -> V_28 && ! V_2 -> V_28 -> V_19 ) ) {
V_42 = - V_138 ;
break;
}
if ( F_33 ( V_2 ) && ! ( F_34 ( V_59 , & V_2 -> V_17 ) ) ) {
while ( V_44 > 0 ) {
T_2 V_160 = F_31 ( V_2 , V_133 , V_44 ) ;
if ( V_160 < 0 ) {
if ( V_160 == - V_150 )
break;
V_42 = V_160 ;
goto V_47;
}
V_133 += V_160 ;
V_44 -= V_160 ;
if ( V_44 == 0 )
break;
V_14 = * V_133 ;
if ( F_29 ( V_14 , V_2 ) < 0 )
break;
V_133 ++ ; V_44 -- ;
}
if ( V_2 -> V_39 -> V_61 )
V_2 -> V_39 -> V_61 ( V_2 ) ;
} else {
while ( V_44 > 0 ) {
V_14 = V_2 -> V_39 -> V_40 ( V_2 , V_133 , V_44 ) ;
if ( V_14 < 0 ) {
V_42 = V_14 ;
goto V_47;
}
if ( ! V_14 )
break;
V_133 += V_14 ;
V_44 -= V_14 ;
}
}
if ( ! V_44 )
break;
if ( V_134 -> V_147 & V_148 ) {
V_42 = - V_150 ;
break;
}
F_135 () ;
}
V_47:
F_129 ( V_155 ) ;
F_131 ( & V_2 -> V_128 , & V_141 ) ;
if ( V_133 - V_12 != V_44 && V_2 -> V_94 )
F_90 ( V_97 , & V_2 -> V_17 ) ;
return ( V_133 - V_12 ) ? V_133 - V_12 : V_42 ;
}
static unsigned int F_136 ( struct V_1 * V_2 , struct V_134 * V_134 ,
T_4 * V_141 )
{
unsigned int V_161 = 0 ;
F_137 ( V_134 , & V_2 -> V_33 , V_141 ) ;
F_137 ( V_134 , & V_2 -> V_128 , V_141 ) ;
if ( F_110 ( V_2 , F_120 ( V_2 ) ? 0 : F_121 ( V_2 ) ) )
V_161 |= V_162 | V_163 ;
if ( V_2 -> V_30 && V_2 -> V_28 -> V_31 )
V_161 |= V_164 | V_162 | V_163 ;
if ( F_34 ( V_154 , & V_2 -> V_17 ) )
V_161 |= V_165 ;
if ( F_126 ( V_134 ) )
V_161 |= V_165 ;
if ( ! ( V_161 & ( V_165 | V_162 | V_163 ) ) ) {
if ( F_121 ( V_2 ) && ! F_120 ( V_2 ) )
V_2 -> V_110 = F_121 ( V_2 ) ;
else
V_2 -> V_110 = 1 ;
}
if ( V_2 -> V_39 -> V_40 && ! F_138 ( V_2 ) &&
F_139 ( V_2 ) < V_166 &&
F_30 ( V_2 ) > 0 )
V_161 |= V_167 | V_168 ;
return V_161 ;
}
static unsigned long F_140 ( struct V_1 * V_2 )
{
int V_44 , V_68 , V_71 ;
if ( ! V_2 -> V_10 )
return 0 ;
V_68 = V_2 -> V_25 ;
V_71 = V_2 -> V_20 ;
V_44 = ( V_68 - V_71 ) & ( V_6 - 1 ) ;
while ( V_68 != V_71 ) {
if ( F_34 ( V_71 , V_2 -> V_27 ) &&
V_2 -> V_15 [ V_71 ] == V_93 )
V_44 -- ;
V_71 = ( V_71 + 1 ) & ( V_6 - 1 ) ;
}
return V_44 ;
}
static int F_141 ( struct V_1 * V_2 , struct V_134 * V_134 ,
unsigned int V_169 , unsigned long V_170 )
{
int V_42 ;
switch ( V_169 ) {
case V_171 :
return F_3 ( F_139 ( V_2 ) , ( int T_1 * ) V_170 ) ;
case V_172 :
V_42 = V_2 -> V_7 ;
if ( F_104 ( V_2 ) )
V_42 = F_140 ( V_2 ) ;
return F_3 ( V_42 , ( unsigned int T_1 * ) V_170 ) ;
default:
return F_142 ( V_2 , V_134 , V_169 , V_170 ) ;
}
}
void F_143 ( struct V_173 * V_39 )
{
* V_39 = V_174 ;
V_39 -> V_175 = NULL ;
V_39 -> V_176 = V_39 -> V_17 = 0 ;
}

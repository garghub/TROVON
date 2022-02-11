bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 && V_3 > V_2 -> V_4 )
return false ;
if ( V_2 -> V_5 )
return V_2 -> V_5 ( V_2 -> V_6 , V_3 ) ;
return true ;
}
bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 && V_3 > V_2 -> V_4 )
return false ;
if ( V_2 -> V_7 . V_8 )
return false ;
if ( V_2 -> V_9 )
return V_2 -> V_9 ( V_2 -> V_6 , V_3 ) ;
return true ;
}
bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ! F_2 ( V_2 , V_3 ) )
return false ;
if ( V_2 -> V_10 )
return V_2 -> V_10 ( V_2 -> V_6 , V_3 ) ;
return true ;
}
bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( ! F_2 ( V_2 , V_3 ) )
return false ;
if ( V_2 -> V_11 )
return V_2 -> V_11 ( V_2 -> V_6 , V_3 ) ;
return false ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_12 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < V_12 ; V_13 ++ )
if ( ! F_3 ( V_2 , V_3 + V_13 ) )
return false ;
return true ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_14 )
{
T_1 * V_15 = V_2 -> V_16 ;
* V_15 = ( V_3 << 6 ) | V_14 ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_14 )
{
T_2 * V_15 = V_2 -> V_16 ;
* V_15 = F_8 ( ( V_3 << 12 ) | V_14 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_14 )
{
T_2 * V_15 = V_2 -> V_16 ;
* V_15 = F_8 ( ( V_3 << 9 ) | V_14 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_14 )
{
T_1 * V_15 = V_2 -> V_16 ;
V_15 [ 2 ] = V_14 ;
V_15 [ 1 ] = ( V_14 >> 8 ) | ( V_3 << 6 ) ;
V_15 [ 0 ] = V_3 >> 2 ;
}
static void F_11 ( void * V_17 , unsigned int V_14 , unsigned int V_18 )
{
T_1 * V_19 = V_17 ;
V_19 [ 0 ] = V_14 << V_18 ;
}
static void F_12 ( void * V_17 , unsigned int V_14 , unsigned int V_18 )
{
T_2 * V_19 = V_17 ;
V_19 [ 0 ] = F_8 ( V_14 << V_18 ) ;
}
static void F_13 ( void * V_17 , unsigned int V_14 , unsigned int V_18 )
{
T_1 * V_19 = V_17 ;
V_14 <<= V_18 ;
V_19 [ 0 ] = V_14 >> 16 ;
V_19 [ 1 ] = V_14 >> 8 ;
V_19 [ 2 ] = V_14 ;
}
static void F_14 ( void * V_17 , unsigned int V_14 , unsigned int V_18 )
{
T_3 * V_19 = V_17 ;
V_19 [ 0 ] = F_15 ( V_14 << V_18 ) ;
}
static unsigned int F_16 ( void * V_17 )
{
T_1 * V_19 = V_17 ;
return V_19 [ 0 ] ;
}
static unsigned int F_17 ( void * V_17 )
{
T_2 * V_19 = V_17 ;
V_19 [ 0 ] = F_18 ( V_19 [ 0 ] ) ;
return V_19 [ 0 ] ;
}
static unsigned int F_19 ( void * V_17 )
{
T_1 * V_19 = V_17 ;
unsigned int V_20 = V_19 [ 2 ] ;
V_20 |= ( ( unsigned int ) V_19 [ 1 ] ) << 8 ;
V_20 |= ( ( unsigned int ) V_19 [ 0 ] ) << 16 ;
return V_20 ;
}
static unsigned int F_20 ( void * V_17 )
{
T_3 * V_19 = V_17 ;
V_19 [ 0 ] = F_21 ( V_19 [ 0 ] ) ;
return V_19 [ 0 ] ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_21 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_21 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_22 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_22 ) ;
}
static void F_30 ( struct V_23 * V_6 , void * V_24 )
{
}
struct V_1 * F_31 ( struct V_23 * V_6 ,
const struct V_25 * V_26 ,
void * V_27 ,
const struct V_28 * V_29 )
{
struct V_1 * V_2 , * * V_30 ;
int V_20 = - V_31 ;
if ( ! V_26 || ! V_29 )
goto V_32;
V_2 = F_32 ( sizeof( * V_2 ) , V_33 ) ;
if ( V_2 == NULL ) {
V_20 = - V_34 ;
goto V_32;
}
if ( V_26 -> V_35 ) {
F_33 ( & V_2 -> V_22 ) ;
V_2 -> V_36 = F_26 ;
V_2 -> V_37 = F_28 ;
} else {
F_34 ( & V_2 -> V_21 ) ;
V_2 -> V_36 = F_22 ;
V_2 -> V_37 = F_24 ;
}
V_2 -> V_7 . V_38 = F_35 ( V_29 -> V_39 , 8 ) ;
V_2 -> V_7 . V_40 = V_29 -> V_41 / 8 ;
V_2 -> V_7 . V_42 = F_35 ( V_29 -> V_43 , 8 ) ;
V_2 -> V_7 . V_44 = F_35 ( V_29 -> V_39 +
V_29 -> V_43 + V_29 -> V_41 , 8 ) ;
V_2 -> V_45 = V_29 -> V_41 % 8 ;
if ( V_29 -> V_46 )
V_2 -> V_46 = V_29 -> V_46 ;
else
V_2 -> V_46 = 1 ;
V_2 -> V_47 = V_29 -> V_47 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_27 = V_27 ;
V_2 -> V_4 = V_29 -> V_4 ;
V_2 -> V_5 = V_29 -> V_5 ;
V_2 -> V_9 = V_29 -> V_9 ;
V_2 -> V_10 = V_29 -> V_10 ;
V_2 -> V_11 = V_29 -> V_11 ;
V_2 -> V_48 = V_29 -> V_48 ;
V_2 -> V_49 = V_29 -> V_49 ;
if ( V_29 -> V_50 || V_29 -> V_51 ) {
V_2 -> V_50 = V_29 -> V_50 ;
V_2 -> V_51 = V_29 -> V_51 ;
} else {
V_2 -> V_50 = V_26 -> V_50 ;
}
switch ( V_29 -> V_39 + V_2 -> V_45 ) {
case 2 :
switch ( V_29 -> V_43 ) {
case 6 :
V_2 -> V_7 . V_8 = F_6 ;
break;
default:
goto V_52;
}
break;
case 4 :
switch ( V_29 -> V_43 ) {
case 12 :
V_2 -> V_7 . V_8 = F_7 ;
break;
default:
goto V_52;
}
break;
case 7 :
switch ( V_29 -> V_43 ) {
case 9 :
V_2 -> V_7 . V_8 = F_9 ;
break;
default:
goto V_52;
}
break;
case 10 :
switch ( V_29 -> V_43 ) {
case 14 :
V_2 -> V_7 . V_8 = F_10 ;
break;
default:
goto V_52;
}
break;
case 8 :
V_2 -> V_7 . V_53 = F_11 ;
break;
case 16 :
V_2 -> V_7 . V_53 = F_12 ;
break;
case 32 :
V_2 -> V_7 . V_53 = F_14 ;
break;
default:
goto V_52;
}
switch ( V_29 -> V_43 ) {
case 8 :
V_2 -> V_7 . V_54 = F_11 ;
V_2 -> V_7 . V_55 = F_16 ;
break;
case 16 :
V_2 -> V_7 . V_54 = F_12 ;
V_2 -> V_7 . V_55 = F_17 ;
break;
case 24 :
V_2 -> V_7 . V_54 = F_13 ;
V_2 -> V_7 . V_55 = F_19 ;
break;
case 32 :
V_2 -> V_7 . V_54 = F_14 ;
V_2 -> V_7 . V_55 = F_20 ;
break;
}
if ( V_2 -> V_7 . V_8 )
V_2 -> V_47 = true ;
if ( ! V_2 -> V_7 . V_8 &&
! ( V_2 -> V_7 . V_53 && V_2 -> V_7 . V_54 ) )
goto V_52;
V_2 -> V_16 = F_32 ( V_2 -> V_7 . V_44 , V_33 ) ;
if ( V_2 -> V_16 == NULL ) {
V_20 = - V_34 ;
goto V_52;
}
F_36 ( V_2 , V_29 -> V_49 ) ;
V_20 = F_37 ( V_2 , V_29 ) ;
if ( V_20 < 0 )
goto V_56;
V_30 = F_38 ( F_30 , sizeof( * V_30 ) , V_33 ) ;
if ( ! V_30 ) {
V_20 = - V_34 ;
goto V_57;
}
* V_30 = V_2 ;
F_39 ( V_6 , V_30 ) ;
return V_2 ;
V_57:
F_40 ( V_2 ) ;
V_56:
F_41 ( V_2 ) ;
F_42 ( V_2 -> V_16 ) ;
V_52:
F_42 ( V_2 ) ;
V_32:
return F_43 ( V_20 ) ;
}
static void F_44 ( struct V_23 * V_6 , void * V_24 )
{
F_45 ( * (struct V_1 * * ) V_24 ) ;
}
struct V_1 * F_46 ( struct V_23 * V_6 ,
const struct V_25 * V_26 ,
void * V_27 ,
const struct V_28 * V_29 )
{
struct V_1 * * V_58 , * V_1 ;
V_58 = F_38 ( F_44 , sizeof( * V_58 ) , V_33 ) ;
if ( ! V_58 )
return F_43 ( - V_34 ) ;
V_1 = F_31 ( V_6 , V_26 , V_27 , V_29 ) ;
if ( ! F_47 ( V_1 ) ) {
* V_58 = V_1 ;
F_39 ( V_6 , V_58 ) ;
} else {
F_48 ( V_58 ) ;
}
return V_1 ;
}
int F_49 ( struct V_1 * V_2 , const struct V_28 * V_29 )
{
int V_20 ;
V_2 -> V_36 ( V_2 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
V_2 -> V_4 = V_29 -> V_4 ;
V_2 -> V_5 = V_29 -> V_5 ;
V_2 -> V_9 = V_29 -> V_9 ;
V_2 -> V_10 = V_29 -> V_10 ;
V_2 -> V_11 = V_29 -> V_11 ;
V_2 -> V_48 = V_29 -> V_48 ;
F_36 ( V_2 , V_29 -> V_49 ) ;
V_2 -> V_59 = false ;
V_2 -> V_60 = false ;
V_20 = F_37 ( V_2 , V_29 ) ;
V_2 -> V_37 ( V_2 ) ;
return V_20 ;
}
void F_45 ( struct V_1 * V_2 )
{
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
if ( V_2 -> V_26 -> V_61 )
V_2 -> V_26 -> V_61 ( V_2 -> V_27 ) ;
F_42 ( V_2 -> V_16 ) ;
F_42 ( V_2 ) ;
}
static int F_50 ( struct V_23 * V_6 , void * V_24 , void * V_62 )
{
struct V_1 * * V_63 = V_24 ;
if ( ! V_63 || ! * V_63 ) {
F_51 ( ! V_63 || ! * V_63 ) ;
return 0 ;
}
if ( V_62 )
return ( * V_63 ) -> V_49 == V_62 ;
else
return 1 ;
}
struct V_1 * F_52 ( struct V_23 * V_6 , const char * V_49 )
{
struct V_1 * * V_63 = F_53 ( V_6 , F_30 ,
F_50 , ( void * ) V_49 ) ;
if ( ! V_63 )
return NULL ;
return * V_63 ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_14 , T_4 V_64 )
{
T_1 * T_1 = V_2 -> V_16 ;
void * V_17 ;
int V_20 = - V_65 ;
T_4 V_66 ;
int V_13 ;
if ( V_2 -> V_5 )
for ( V_13 = 0 ; V_13 < V_64 / V_2 -> V_7 . V_42 ; V_13 ++ )
if ( ! V_2 -> V_5 ( V_2 -> V_6 ,
V_3 + ( V_13 * V_2 -> V_46 ) ) )
return - V_31 ;
if ( ! V_2 -> V_59 && V_2 -> V_7 . V_55 ) {
unsigned int V_67 ;
int V_42 = V_2 -> V_7 . V_42 ;
for ( V_13 = 0 ; V_13 < V_64 / V_42 ; V_13 ++ ) {
memcpy ( V_2 -> V_16 , V_14 + ( V_13 * V_42 ) , V_42 ) ;
V_67 = V_2 -> V_7 . V_55 ( V_2 -> V_16 ) ;
V_20 = F_55 ( V_2 , V_3 + ( V_13 * V_2 -> V_46 ) ,
V_67 ) ;
if ( V_20 ) {
F_56 ( V_2 -> V_6 ,
L_1 ,
V_3 + V_13 , V_20 ) ;
return V_20 ;
}
}
if ( V_2 -> V_60 ) {
V_2 -> V_68 = true ;
return 0 ;
}
}
V_2 -> V_7 . V_53 ( V_2 -> V_16 , V_3 , V_2 -> V_45 ) ;
T_1 [ 0 ] |= V_2 -> V_51 ;
F_57 ( V_2 -> V_6 , V_3 ,
V_64 / V_2 -> V_7 . V_42 ) ;
if ( V_14 == ( V_2 -> V_16 + V_2 -> V_7 . V_40 +
V_2 -> V_7 . V_38 ) )
V_20 = V_2 -> V_26 -> V_69 ( V_2 -> V_27 , V_2 -> V_16 ,
V_2 -> V_7 . V_38 +
V_2 -> V_7 . V_40 +
V_64 ) ;
else if ( V_2 -> V_26 -> V_70 )
V_20 = V_2 -> V_26 -> V_70 ( V_2 -> V_27 , V_2 -> V_16 ,
V_2 -> V_7 . V_38 +
V_2 -> V_7 . V_40 ,
V_14 , V_64 ) ;
if ( V_20 == - V_65 ) {
V_66 = V_2 -> V_7 . V_38 + V_2 -> V_7 . V_40 + V_64 ;
V_17 = F_32 ( V_66 , V_33 ) ;
if ( ! V_17 )
return - V_34 ;
memcpy ( V_17 , V_2 -> V_16 , V_2 -> V_7 . V_38 ) ;
memcpy ( V_17 + V_2 -> V_7 . V_38 + V_2 -> V_7 . V_40 ,
V_14 , V_64 ) ;
V_20 = V_2 -> V_26 -> V_69 ( V_2 -> V_27 , V_17 , V_66 ) ;
F_42 ( V_17 ) ;
}
F_58 ( V_2 -> V_6 , V_3 ,
V_64 / V_2 -> V_7 . V_42 ) ;
return V_20 ;
}
int F_59 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 )
{
int V_20 ;
F_60 ( ! V_2 -> V_7 . V_8 && ! V_2 -> V_7 . V_54 ) ;
if ( ! V_2 -> V_59 && V_2 -> V_7 . V_8 ) {
V_20 = F_55 ( V_2 , V_3 , V_14 ) ;
if ( V_20 != 0 )
return V_20 ;
if ( V_2 -> V_60 ) {
V_2 -> V_68 = true ;
return 0 ;
}
}
F_61 ( V_2 -> V_6 , V_3 , V_14 ) ;
if ( V_2 -> V_7 . V_8 ) {
V_2 -> V_7 . V_8 ( V_2 , V_3 , V_14 ) ;
F_57 ( V_2 -> V_6 , V_3 , 1 ) ;
V_20 = V_2 -> V_26 -> V_69 ( V_2 -> V_27 , V_2 -> V_16 ,
V_2 -> V_7 . V_44 ) ;
F_58 ( V_2 -> V_6 , V_3 , 1 ) ;
return V_20 ;
} else {
V_2 -> V_7 . V_54 ( V_2 -> V_16 + V_2 -> V_7 . V_38
+ V_2 -> V_7 . V_40 , V_14 , 0 ) ;
return F_54 ( V_2 , V_3 ,
V_2 -> V_16 +
V_2 -> V_7 . V_38 +
V_2 -> V_7 . V_40 ,
V_2 -> V_7 . V_42 ) ;
}
}
int F_62 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_14 )
{
int V_20 ;
if ( V_3 % V_2 -> V_46 )
return - V_31 ;
V_2 -> V_36 ( V_2 ) ;
V_20 = F_59 ( V_2 , V_3 , V_14 ) ;
V_2 -> V_37 ( V_2 ) ;
return V_20 ;
}
int F_63 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_14 , T_4 V_64 )
{
int V_20 ;
if ( V_64 % V_2 -> V_7 . V_42 )
return - V_31 ;
if ( V_3 % V_2 -> V_46 )
return - V_31 ;
V_2 -> V_36 ( V_2 ) ;
V_20 = F_54 ( V_2 , V_3 , V_14 , V_64 ) ;
V_2 -> V_37 ( V_2 ) ;
return V_20 ;
}
int F_64 ( struct V_1 * V_2 , unsigned int V_3 , const void * V_14 ,
T_4 V_71 )
{
int V_20 = 0 , V_13 ;
T_4 V_42 = V_2 -> V_7 . V_42 ;
void * V_72 ;
if ( ! V_2 -> V_7 . V_55 )
return - V_31 ;
if ( V_3 % V_2 -> V_46 )
return - V_31 ;
V_2 -> V_36 ( V_2 ) ;
if ( V_42 == 1 ) {
V_72 = ( void * ) V_14 ;
} else {
V_72 = F_65 ( V_14 , V_71 * V_42 , V_33 ) ;
if ( ! V_72 ) {
V_20 = - V_34 ;
F_56 ( V_2 -> V_6 , L_2 ) ;
goto V_15;
}
for ( V_13 = 0 ; V_13 < V_71 * V_42 ; V_13 += V_42 )
V_2 -> V_7 . V_55 ( V_72 + V_13 ) ;
}
if ( V_2 -> V_47 ) {
for ( V_13 = 0 ; V_13 < V_71 ; V_13 ++ ) {
V_20 = F_63 ( V_2 ,
V_3 + ( V_13 * V_2 -> V_46 ) ,
V_14 + ( V_13 * V_42 ) ,
V_42 ) ;
if ( V_20 != 0 )
return V_20 ;
}
} else {
V_20 = F_54 ( V_2 , V_3 , V_72 , V_42 * V_71 ) ;
}
if ( V_42 != 1 )
F_42 ( V_72 ) ;
V_15:
V_2 -> V_37 ( V_2 ) ;
return V_20 ;
}
static int F_66 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
unsigned int V_64 )
{
T_1 * T_1 = V_2 -> V_16 ;
int V_20 ;
V_2 -> V_7 . V_53 ( V_2 -> V_16 , V_3 , V_2 -> V_45 ) ;
T_1 [ 0 ] |= V_2 -> V_50 ;
F_67 ( V_2 -> V_6 , V_3 ,
V_64 / V_2 -> V_7 . V_42 ) ;
V_20 = V_2 -> V_26 -> V_73 ( V_2 -> V_27 , V_2 -> V_16 ,
V_2 -> V_7 . V_38 + V_2 -> V_7 . V_40 ,
V_14 , V_64 ) ;
F_68 ( V_2 -> V_6 , V_3 ,
V_64 / V_2 -> V_7 . V_42 ) ;
return V_20 ;
}
static int F_69 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_14 )
{
int V_20 ;
if ( ! V_2 -> V_59 ) {
V_20 = F_70 ( V_2 , V_3 , V_14 ) ;
if ( V_20 == 0 )
return 0 ;
}
if ( ! V_2 -> V_7 . V_55 )
return - V_31 ;
if ( V_2 -> V_60 )
return - V_74 ;
V_20 = F_66 ( V_2 , V_3 , V_2 -> V_16 , V_2 -> V_7 . V_42 ) ;
if ( V_20 == 0 ) {
* V_14 = V_2 -> V_7 . V_55 ( V_2 -> V_16 ) ;
F_71 ( V_2 -> V_6 , V_3 , * V_14 ) ;
}
if ( V_20 == 0 && ! V_2 -> V_59 )
F_55 ( V_2 , V_3 , * V_14 ) ;
return V_20 ;
}
int F_72 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int * V_14 )
{
int V_20 ;
if ( V_3 % V_2 -> V_46 )
return - V_31 ;
V_2 -> V_36 ( V_2 ) ;
V_20 = F_69 ( V_2 , V_3 , V_14 ) ;
V_2 -> V_37 ( V_2 ) ;
return V_20 ;
}
int F_73 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
T_4 V_64 )
{
T_4 V_42 = V_2 -> V_7 . V_42 ;
T_4 V_71 = V_64 / V_42 ;
unsigned int V_75 ;
int V_20 , V_13 ;
if ( V_64 % V_2 -> V_7 . V_42 )
return - V_31 ;
if ( V_3 % V_2 -> V_46 )
return - V_31 ;
V_2 -> V_36 ( V_2 ) ;
if ( F_5 ( V_2 , V_3 , V_71 ) || V_2 -> V_59 ||
V_2 -> V_48 == V_76 ) {
V_20 = F_66 ( V_2 , V_3 , V_14 , V_64 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_71 ; V_13 ++ ) {
V_20 = F_69 ( V_2 , V_3 + ( V_13 * V_2 -> V_46 ) ,
& V_75 ) ;
if ( V_20 != 0 )
goto V_15;
V_2 -> V_7 . V_54 ( V_14 + ( V_13 * V_42 ) , V_75 , 0 ) ;
}
}
V_15:
V_2 -> V_37 ( V_2 ) ;
return V_20 ;
}
int F_74 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
T_4 V_71 )
{
int V_20 , V_13 ;
T_4 V_42 = V_2 -> V_7 . V_42 ;
bool V_77 = F_5 ( V_2 , V_3 , V_71 ) ;
if ( ! V_2 -> V_7 . V_55 )
return - V_31 ;
if ( V_3 % V_2 -> V_46 )
return - V_31 ;
if ( V_77 || V_2 -> V_48 == V_76 ) {
if ( V_2 -> V_47 ) {
for ( V_13 = 0 ; V_13 < V_71 ; V_13 ++ ) {
V_20 = F_73 ( V_2 ,
V_3 + ( V_13 * V_2 -> V_46 ) ,
V_14 + ( V_13 * V_42 ) ,
V_42 ) ;
if ( V_20 != 0 )
return V_20 ;
}
} else {
V_20 = F_73 ( V_2 , V_3 , V_14 ,
V_42 * V_71 ) ;
if ( V_20 != 0 )
return V_20 ;
}
for ( V_13 = 0 ; V_13 < V_71 * V_42 ; V_13 += V_42 )
V_2 -> V_7 . V_55 ( V_14 + V_13 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_71 ; V_13 ++ ) {
unsigned int V_67 ;
V_20 = F_72 ( V_2 , V_3 + ( V_13 * V_2 -> V_46 ) ,
& V_67 ) ;
if ( V_20 != 0 )
return V_20 ;
memcpy ( V_14 + ( V_13 * V_42 ) , & V_67 , V_42 ) ;
}
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_78 , unsigned int V_14 ,
bool * V_79 )
{
int V_20 ;
unsigned int V_80 , V_81 ;
V_2 -> V_36 ( V_2 ) ;
V_20 = F_69 ( V_2 , V_3 , & V_81 ) ;
if ( V_20 != 0 )
goto V_15;
V_80 = V_81 & ~ V_78 ;
V_80 |= V_14 & V_78 ;
if ( V_80 != V_81 ) {
V_20 = F_59 ( V_2 , V_3 , V_80 ) ;
* V_79 = true ;
} else {
* V_79 = false ;
}
V_15:
V_2 -> V_37 ( V_2 ) ;
return V_20 ;
}
int F_76 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_78 , unsigned int V_14 )
{
bool V_79 ;
return F_75 ( V_2 , V_3 , V_78 , V_14 , & V_79 ) ;
}
int F_77 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_78 , unsigned int V_14 ,
bool * V_79 )
{
return F_75 ( V_2 , V_3 , V_78 , V_14 , V_79 ) ;
}
int F_78 ( struct V_1 * V_2 , const struct V_82 * V_83 ,
int V_84 )
{
int V_13 , V_20 ;
bool V_85 ;
if ( V_2 -> V_86 )
return - V_74 ;
V_2 -> V_36 ( V_2 ) ;
V_85 = V_2 -> V_59 ;
V_2 -> V_59 = true ;
for ( V_13 = 0 ; V_13 < V_84 ; V_13 ++ ) {
V_20 = F_59 ( V_2 , V_83 [ V_13 ] . V_3 , V_83 [ V_13 ] . V_87 ) ;
if ( V_20 != 0 ) {
F_56 ( V_2 -> V_6 , L_3 ,
V_83 [ V_13 ] . V_3 , V_83 [ V_13 ] . V_87 , V_20 ) ;
goto V_15;
}
}
V_2 -> V_86 = F_79 ( V_84 , sizeof( struct V_82 ) , V_33 ) ;
if ( V_2 -> V_86 != NULL ) {
memcpy ( V_2 -> V_86 , V_83 ,
V_84 * sizeof( struct V_82 ) ) ;
V_2 -> V_88 = V_84 ;
} else {
V_20 = - V_34 ;
}
V_15:
V_2 -> V_59 = V_85 ;
V_2 -> V_37 ( V_2 ) ;
return V_20 ;
}
int F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 . V_8 )
return - V_31 ;
return V_2 -> V_7 . V_42 ;
}
static int T_5 F_81 ( void )
{
F_82 () ;
return 0 ;
}

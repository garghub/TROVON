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
static void F_11 ( void * V_17 , unsigned int V_14 )
{
T_1 * V_18 = V_17 ;
V_18 [ 0 ] = V_14 ;
}
static void F_12 ( void * V_17 , unsigned int V_14 )
{
T_2 * V_18 = V_17 ;
V_18 [ 0 ] = F_8 ( V_14 ) ;
}
static void F_13 ( void * V_17 , unsigned int V_14 )
{
T_3 * V_18 = V_17 ;
V_18 [ 0 ] = F_14 ( V_14 ) ;
}
static unsigned int F_15 ( void * V_17 )
{
T_1 * V_18 = V_17 ;
return V_18 [ 0 ] ;
}
static unsigned int F_16 ( void * V_17 )
{
T_2 * V_18 = V_17 ;
V_18 [ 0 ] = F_17 ( V_18 [ 0 ] ) ;
return V_18 [ 0 ] ;
}
static unsigned int F_18 ( void * V_17 )
{
T_3 * V_18 = V_17 ;
V_18 [ 0 ] = F_19 ( V_18 [ 0 ] ) ;
return V_18 [ 0 ] ;
}
struct V_1 * F_20 ( struct V_19 * V_6 ,
const struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_1 * V_2 ;
int V_24 = - V_25 ;
if ( ! V_21 || ! V_23 )
goto V_26;
V_2 = F_21 ( sizeof( * V_2 ) , V_27 ) ;
if ( V_2 == NULL ) {
V_24 = - V_28 ;
goto V_26;
}
F_22 ( & V_2 -> V_29 ) ;
V_2 -> V_7 . V_30 = ( V_23 -> V_31 + V_23 -> V_32 ) / 8 ;
V_2 -> V_7 . V_33 = F_23 ( V_23 -> V_31 , 8 ) ;
V_2 -> V_7 . V_34 = V_23 -> V_35 / 8 ;
V_2 -> V_7 . V_36 = F_23 ( V_23 -> V_32 , 8 ) ;
V_2 -> V_7 . V_30 += V_2 -> V_7 . V_34 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_4 = V_23 -> V_4 ;
V_2 -> V_5 = V_23 -> V_5 ;
V_2 -> V_9 = V_23 -> V_9 ;
V_2 -> V_10 = V_23 -> V_10 ;
V_2 -> V_11 = V_23 -> V_11 ;
V_2 -> V_37 = V_23 -> V_37 ;
if ( V_23 -> V_38 || V_23 -> V_39 ) {
V_2 -> V_38 = V_23 -> V_38 ;
V_2 -> V_39 = V_23 -> V_39 ;
} else {
V_2 -> V_38 = V_21 -> V_38 ;
}
switch ( V_23 -> V_31 ) {
case 2 :
switch ( V_23 -> V_32 ) {
case 6 :
V_2 -> V_7 . V_8 = F_6 ;
break;
default:
goto V_40;
}
break;
case 4 :
switch ( V_23 -> V_32 ) {
case 12 :
V_2 -> V_7 . V_8 = F_7 ;
break;
default:
goto V_40;
}
break;
case 7 :
switch ( V_23 -> V_32 ) {
case 9 :
V_2 -> V_7 . V_8 = F_9 ;
break;
default:
goto V_40;
}
break;
case 10 :
switch ( V_23 -> V_32 ) {
case 14 :
V_2 -> V_7 . V_8 = F_10 ;
break;
default:
goto V_40;
}
break;
case 8 :
V_2 -> V_7 . V_41 = F_11 ;
break;
case 16 :
V_2 -> V_7 . V_41 = F_12 ;
break;
case 32 :
V_2 -> V_7 . V_41 = F_13 ;
break;
default:
goto V_40;
}
switch ( V_23 -> V_32 ) {
case 8 :
V_2 -> V_7 . V_42 = F_11 ;
V_2 -> V_7 . V_43 = F_15 ;
break;
case 16 :
V_2 -> V_7 . V_42 = F_12 ;
V_2 -> V_7 . V_43 = F_16 ;
break;
case 32 :
V_2 -> V_7 . V_42 = F_13 ;
V_2 -> V_7 . V_43 = F_18 ;
break;
}
if ( ! V_2 -> V_7 . V_8 &&
! ( V_2 -> V_7 . V_41 && V_2 -> V_7 . V_42 ) )
goto V_40;
V_2 -> V_16 = F_21 ( V_2 -> V_7 . V_30 , V_27 ) ;
if ( V_2 -> V_16 == NULL ) {
V_24 = - V_28 ;
goto V_40;
}
F_24 ( V_2 ) ;
V_24 = F_25 ( V_2 , V_23 ) ;
if ( V_24 < 0 )
goto V_44;
return V_2 ;
V_44:
F_26 ( V_2 -> V_16 ) ;
V_40:
F_26 ( V_2 ) ;
V_26:
return F_27 ( V_24 ) ;
}
static void F_28 ( struct V_19 * V_6 , void * V_45 )
{
F_29 ( * (struct V_1 * * ) V_45 ) ;
}
struct V_1 * F_30 ( struct V_19 * V_6 ,
const struct V_20 * V_21 ,
const struct V_22 * V_23 )
{
struct V_1 * * V_46 , * V_1 ;
V_46 = F_31 ( F_28 , sizeof( * V_46 ) , V_27 ) ;
if ( ! V_46 )
return F_27 ( - V_28 ) ;
V_1 = F_20 ( V_6 , V_21 , V_23 ) ;
if ( ! F_32 ( V_1 ) ) {
* V_46 = V_1 ;
F_33 ( V_6 , V_46 ) ;
} else {
F_34 ( V_46 ) ;
}
return V_1 ;
}
int F_35 ( struct V_1 * V_2 , const struct V_22 * V_23 )
{
int V_24 ;
F_36 ( & V_2 -> V_29 ) ;
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
V_2 -> V_4 = V_23 -> V_4 ;
V_2 -> V_5 = V_23 -> V_5 ;
V_2 -> V_9 = V_23 -> V_9 ;
V_2 -> V_10 = V_23 -> V_10 ;
V_2 -> V_11 = V_23 -> V_11 ;
V_2 -> V_37 = V_23 -> V_37 ;
F_24 ( V_2 ) ;
V_2 -> V_47 = false ;
V_2 -> V_48 = false ;
V_24 = F_25 ( V_2 , V_23 ) ;
F_39 ( & V_2 -> V_29 ) ;
return V_24 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
F_26 ( V_2 -> V_16 ) ;
F_26 ( V_2 ) ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_14 , T_4 V_49 )
{
T_1 * T_1 = V_2 -> V_16 ;
void * V_17 ;
int V_24 = - V_50 ;
T_4 V_51 ;
int V_13 ;
if ( V_2 -> V_5 )
for ( V_13 = 0 ; V_13 < V_49 / V_2 -> V_7 . V_36 ; V_13 ++ )
if ( ! V_2 -> V_5 ( V_2 -> V_6 , V_3 + V_13 ) )
return - V_25 ;
if ( ! V_2 -> V_47 && V_2 -> V_7 . V_43 ) {
unsigned int V_52 ;
int V_36 = V_2 -> V_7 . V_36 ;
for ( V_13 = 0 ; V_13 < V_49 / V_36 ; V_13 ++ ) {
memcpy ( V_2 -> V_16 , V_14 + ( V_13 * V_36 ) , V_36 ) ;
V_52 = V_2 -> V_7 . V_43 ( V_2 -> V_16 ) ;
V_24 = F_41 ( V_2 , V_3 + V_13 , V_52 ) ;
if ( V_24 ) {
F_42 ( V_2 -> V_6 ,
L_1 ,
V_3 + V_13 , V_24 ) ;
return V_24 ;
}
}
if ( V_2 -> V_48 ) {
V_2 -> V_53 = true ;
return 0 ;
}
}
V_2 -> V_7 . V_41 ( V_2 -> V_16 , V_3 ) ;
T_1 [ 0 ] |= V_2 -> V_39 ;
F_43 ( V_2 -> V_6 , V_3 ,
V_49 / V_2 -> V_7 . V_36 ) ;
if ( V_14 == ( V_2 -> V_16 + V_2 -> V_7 . V_34 +
V_2 -> V_7 . V_33 ) )
V_24 = V_2 -> V_21 -> V_54 ( V_2 -> V_6 , V_2 -> V_16 ,
V_2 -> V_7 . V_33 +
V_2 -> V_7 . V_34 +
V_49 ) ;
else if ( V_2 -> V_21 -> V_55 )
V_24 = V_2 -> V_21 -> V_55 ( V_2 -> V_6 , V_2 -> V_16 ,
V_2 -> V_7 . V_33 +
V_2 -> V_7 . V_34 ,
V_14 , V_49 ) ;
if ( V_24 == - V_50 ) {
V_51 = V_2 -> V_7 . V_33 + V_2 -> V_7 . V_34 + V_49 ;
V_17 = F_21 ( V_51 , V_27 ) ;
if ( ! V_17 )
return - V_28 ;
memcpy ( V_17 , V_2 -> V_16 , V_2 -> V_7 . V_33 ) ;
memcpy ( V_17 + V_2 -> V_7 . V_33 + V_2 -> V_7 . V_34 ,
V_14 , V_49 ) ;
V_24 = V_2 -> V_21 -> V_54 ( V_2 -> V_6 , V_17 , V_51 ) ;
F_26 ( V_17 ) ;
}
F_44 ( V_2 -> V_6 , V_3 ,
V_49 / V_2 -> V_7 . V_36 ) ;
return V_24 ;
}
int F_45 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_14 )
{
int V_24 ;
F_46 ( ! V_2 -> V_7 . V_8 && ! V_2 -> V_7 . V_42 ) ;
if ( ! V_2 -> V_47 && V_2 -> V_7 . V_8 ) {
V_24 = F_41 ( V_2 , V_3 , V_14 ) ;
if ( V_24 != 0 )
return V_24 ;
if ( V_2 -> V_48 ) {
V_2 -> V_53 = true ;
return 0 ;
}
}
F_47 ( V_2 -> V_6 , V_3 , V_14 ) ;
if ( V_2 -> V_7 . V_8 ) {
V_2 -> V_7 . V_8 ( V_2 , V_3 , V_14 ) ;
F_43 ( V_2 -> V_6 , V_3 , 1 ) ;
V_24 = V_2 -> V_21 -> V_54 ( V_2 -> V_6 , V_2 -> V_16 ,
V_2 -> V_7 . V_30 ) ;
F_44 ( V_2 -> V_6 , V_3 , 1 ) ;
return V_24 ;
} else {
V_2 -> V_7 . V_42 ( V_2 -> V_16 + V_2 -> V_7 . V_33
+ V_2 -> V_7 . V_34 , V_14 ) ;
return F_40 ( V_2 , V_3 ,
V_2 -> V_16 +
V_2 -> V_7 . V_33 +
V_2 -> V_7 . V_34 ,
V_2 -> V_7 . V_36 ) ;
}
}
int F_48 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_14 )
{
int V_24 ;
F_36 ( & V_2 -> V_29 ) ;
V_24 = F_45 ( V_2 , V_3 , V_14 ) ;
F_39 ( & V_2 -> V_29 ) ;
return V_24 ;
}
int F_49 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_14 , T_4 V_49 )
{
int V_24 ;
F_36 ( & V_2 -> V_29 ) ;
V_24 = F_40 ( V_2 , V_3 , V_14 , V_49 ) ;
F_39 ( & V_2 -> V_29 ) ;
return V_24 ;
}
int F_50 ( struct V_1 * V_2 , unsigned int V_3 , const void * V_14 ,
T_4 V_56 )
{
int V_24 = 0 , V_13 ;
T_4 V_36 = V_2 -> V_7 . V_36 ;
void * V_57 ;
if ( ! V_2 -> V_7 . V_43 )
return - V_25 ;
F_36 ( & V_2 -> V_29 ) ;
if ( V_36 == 1 ) {
V_57 = ( void * ) V_14 ;
} else {
V_57 = F_51 ( V_14 , V_56 * V_36 , V_27 ) ;
if ( ! V_57 ) {
V_24 = - V_28 ;
F_42 ( V_2 -> V_6 , L_2 ) ;
goto V_15;
}
for ( V_13 = 0 ; V_13 < V_56 * V_36 ; V_13 += V_36 )
V_2 -> V_7 . V_43 ( V_57 + V_13 ) ;
}
V_24 = F_40 ( V_2 , V_3 , V_57 , V_36 * V_56 ) ;
if ( V_36 != 1 )
F_26 ( V_57 ) ;
V_15:
F_39 ( & V_2 -> V_29 ) ;
return V_24 ;
}
static int F_52 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
unsigned int V_49 )
{
T_1 * T_1 = V_2 -> V_16 ;
int V_24 ;
V_2 -> V_7 . V_41 ( V_2 -> V_16 , V_3 ) ;
T_1 [ 0 ] |= V_2 -> V_38 ;
F_53 ( V_2 -> V_6 , V_3 ,
V_49 / V_2 -> V_7 . V_36 ) ;
V_24 = V_2 -> V_21 -> V_58 ( V_2 -> V_6 , V_2 -> V_16 ,
V_2 -> V_7 . V_33 + V_2 -> V_7 . V_34 ,
V_14 , V_49 ) ;
F_54 ( V_2 -> V_6 , V_3 ,
V_49 / V_2 -> V_7 . V_36 ) ;
return V_24 ;
}
static int F_55 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_14 )
{
int V_24 ;
if ( ! V_2 -> V_47 ) {
V_24 = F_56 ( V_2 , V_3 , V_14 ) ;
if ( V_24 == 0 )
return 0 ;
}
if ( ! V_2 -> V_7 . V_43 )
return - V_25 ;
if ( V_2 -> V_48 )
return - V_59 ;
V_24 = F_52 ( V_2 , V_3 , V_2 -> V_16 , V_2 -> V_7 . V_36 ) ;
if ( V_24 == 0 ) {
* V_14 = V_2 -> V_7 . V_43 ( V_2 -> V_16 ) ;
F_57 ( V_2 -> V_6 , V_3 , * V_14 ) ;
}
return V_24 ;
}
int F_58 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int * V_14 )
{
int V_24 ;
F_36 ( & V_2 -> V_29 ) ;
V_24 = F_55 ( V_2 , V_3 , V_14 ) ;
F_39 ( & V_2 -> V_29 ) ;
return V_24 ;
}
int F_59 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
T_4 V_49 )
{
T_4 V_36 = V_2 -> V_7 . V_36 ;
T_4 V_56 = V_49 / V_36 ;
unsigned int V_60 ;
int V_24 , V_13 ;
F_36 ( & V_2 -> V_29 ) ;
if ( F_5 ( V_2 , V_3 , V_56 ) || V_2 -> V_47 ||
V_2 -> V_37 == V_61 ) {
V_24 = F_52 ( V_2 , V_3 , V_14 , V_49 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_56 ; V_13 ++ ) {
V_24 = F_55 ( V_2 , V_3 + V_13 , & V_60 ) ;
if ( V_24 != 0 )
goto V_15;
V_2 -> V_7 . V_42 ( V_14 + ( V_13 * V_36 ) , V_60 ) ;
}
}
V_15:
F_39 ( & V_2 -> V_29 ) ;
return V_24 ;
}
int F_60 ( struct V_1 * V_2 , unsigned int V_3 , void * V_14 ,
T_4 V_56 )
{
int V_24 , V_13 ;
T_4 V_36 = V_2 -> V_7 . V_36 ;
bool V_62 = F_5 ( V_2 , V_3 , V_56 ) ;
if ( ! V_2 -> V_7 . V_43 )
return - V_25 ;
if ( V_62 || V_2 -> V_37 == V_61 ) {
V_24 = F_59 ( V_2 , V_3 , V_14 , V_36 * V_56 ) ;
if ( V_24 != 0 )
return V_24 ;
for ( V_13 = 0 ; V_13 < V_56 * V_36 ; V_13 += V_36 )
V_2 -> V_7 . V_43 ( V_14 + V_13 ) ;
} else {
for ( V_13 = 0 ; V_13 < V_56 ; V_13 ++ ) {
unsigned int V_52 ;
V_24 = F_58 ( V_2 , V_3 + V_13 , & V_52 ) ;
if ( V_24 != 0 )
return V_24 ;
memcpy ( V_14 + ( V_13 * V_36 ) , & V_52 , V_36 ) ;
}
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_63 , unsigned int V_14 ,
bool * V_64 )
{
int V_24 ;
unsigned int V_65 , V_66 ;
F_36 ( & V_2 -> V_29 ) ;
V_24 = F_55 ( V_2 , V_3 , & V_66 ) ;
if ( V_24 != 0 )
goto V_15;
V_65 = V_66 & ~ V_63 ;
V_65 |= V_14 & V_63 ;
if ( V_65 != V_66 ) {
V_24 = F_45 ( V_2 , V_3 , V_65 ) ;
* V_64 = true ;
} else {
* V_64 = false ;
}
V_15:
F_39 ( & V_2 -> V_29 ) ;
return V_24 ;
}
int F_62 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_63 , unsigned int V_14 )
{
bool V_64 ;
return F_61 ( V_2 , V_3 , V_63 , V_14 , & V_64 ) ;
}
int F_63 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_63 , unsigned int V_14 ,
bool * V_64 )
{
return F_61 ( V_2 , V_3 , V_63 , V_14 , V_64 ) ;
}
int F_64 ( struct V_1 * V_2 , const struct V_67 * V_68 ,
int V_69 )
{
int V_13 , V_24 ;
bool V_70 ;
if ( V_2 -> V_71 )
return - V_59 ;
F_36 ( & V_2 -> V_29 ) ;
V_70 = V_2 -> V_47 ;
V_2 -> V_47 = true ;
for ( V_13 = 0 ; V_13 < V_69 ; V_13 ++ ) {
V_24 = F_45 ( V_2 , V_68 [ V_13 ] . V_3 , V_68 [ V_13 ] . V_72 ) ;
if ( V_24 != 0 ) {
F_42 ( V_2 -> V_6 , L_3 ,
V_68 [ V_13 ] . V_3 , V_68 [ V_13 ] . V_72 , V_24 ) ;
goto V_15;
}
}
V_2 -> V_71 = F_65 ( V_69 , sizeof( struct V_67 ) , V_27 ) ;
if ( V_2 -> V_71 != NULL ) {
memcpy ( V_2 -> V_71 , V_68 ,
V_69 * sizeof( struct V_67 ) ) ;
V_2 -> V_73 = V_69 ;
} else {
V_24 = - V_28 ;
}
V_15:
V_2 -> V_47 = V_70 ;
F_39 ( & V_2 -> V_29 ) ;
return V_24 ;
}
int F_66 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 . V_8 )
return - V_25 ;
return V_2 -> V_7 . V_36 ;
}
static int T_5 F_67 ( void )
{
F_68 () ;
return 0 ;
}

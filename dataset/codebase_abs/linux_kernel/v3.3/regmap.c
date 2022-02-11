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
if ( V_2 -> V_7 )
return V_2 -> V_7 ( V_2 -> V_6 , V_3 ) ;
return true ;
}
bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 && V_3 > V_2 -> V_4 )
return false ;
if ( V_2 -> V_8 )
return V_2 -> V_8 ( V_2 -> V_6 , V_3 ) ;
return true ;
}
bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 && V_3 > V_2 -> V_4 )
return false ;
if ( V_2 -> V_9 )
return V_2 -> V_9 ( V_2 -> V_6 , V_3 ) ;
return false ;
}
static bool F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_10 )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_10 ; V_11 ++ )
if ( ! F_3 ( V_2 , V_3 + V_11 ) )
return false ;
return true ;
}
static void F_6 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_12 )
{
T_1 * V_13 = V_2 -> V_14 ;
* V_13 = F_7 ( ( V_3 << 12 ) | V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_12 )
{
T_1 * V_13 = V_2 -> V_14 ;
* V_13 = F_7 ( ( V_3 << 9 ) | V_12 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_12 )
{
T_2 * V_13 = V_2 -> V_14 ;
V_13 [ 2 ] = V_12 ;
V_13 [ 1 ] = ( V_12 >> 8 ) | ( V_3 << 6 ) ;
V_13 [ 0 ] = V_3 >> 2 ;
}
static void F_10 ( void * V_15 , unsigned int V_12 )
{
T_2 * V_16 = V_15 ;
V_16 [ 0 ] = V_12 ;
}
static void F_11 ( void * V_15 , unsigned int V_12 )
{
T_1 * V_16 = V_15 ;
V_16 [ 0 ] = F_7 ( V_12 ) ;
}
static unsigned int F_12 ( void * V_15 )
{
T_2 * V_16 = V_15 ;
return V_16 [ 0 ] ;
}
static unsigned int F_13 ( void * V_15 )
{
T_1 * V_16 = V_15 ;
V_16 [ 0 ] = F_14 ( V_16 [ 0 ] ) ;
return V_16 [ 0 ] ;
}
struct V_1 * F_15 ( struct V_17 * V_6 ,
const struct V_18 * V_19 ,
const struct V_20 * V_21 )
{
struct V_1 * V_2 ;
int V_22 = - V_23 ;
if ( ! V_19 || ! V_21 )
goto V_24;
V_2 = F_16 ( sizeof( * V_2 ) , V_25 ) ;
if ( V_2 == NULL ) {
V_22 = - V_26 ;
goto V_24;
}
F_17 ( & V_2 -> V_27 ) ;
V_2 -> V_28 . V_29 = ( V_21 -> V_30 + V_21 -> V_31 ) / 8 ;
V_2 -> V_28 . V_32 = V_21 -> V_30 / 8 ;
V_2 -> V_28 . V_33 = V_21 -> V_31 / 8 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_4 = V_21 -> V_4 ;
V_2 -> V_5 = V_21 -> V_5 ;
V_2 -> V_7 = V_21 -> V_7 ;
V_2 -> V_8 = V_21 -> V_8 ;
V_2 -> V_9 = V_21 -> V_9 ;
V_2 -> V_34 = V_21 -> V_34 ;
if ( V_21 -> V_35 || V_21 -> V_36 ) {
V_2 -> V_35 = V_21 -> V_35 ;
V_2 -> V_36 = V_21 -> V_36 ;
} else {
V_2 -> V_35 = V_19 -> V_35 ;
}
switch ( V_21 -> V_30 ) {
case 4 :
switch ( V_21 -> V_31 ) {
case 12 :
V_2 -> V_28 . V_37 = F_6 ;
break;
default:
goto V_38;
}
break;
case 7 :
switch ( V_21 -> V_31 ) {
case 9 :
V_2 -> V_28 . V_37 = F_8 ;
break;
default:
goto V_38;
}
break;
case 10 :
switch ( V_21 -> V_31 ) {
case 14 :
V_2 -> V_28 . V_37 = F_9 ;
break;
default:
goto V_38;
}
break;
case 8 :
V_2 -> V_28 . V_39 = F_10 ;
break;
case 16 :
V_2 -> V_28 . V_39 = F_11 ;
break;
default:
goto V_38;
}
switch ( V_21 -> V_31 ) {
case 8 :
V_2 -> V_28 . V_40 = F_10 ;
V_2 -> V_28 . V_41 = F_12 ;
break;
case 16 :
V_2 -> V_28 . V_40 = F_11 ;
V_2 -> V_28 . V_41 = F_13 ;
break;
}
if ( ! V_2 -> V_28 . V_37 &&
! ( V_2 -> V_28 . V_39 && V_2 -> V_28 . V_40 ) )
goto V_38;
V_2 -> V_14 = F_18 ( V_2 -> V_28 . V_29 , V_25 ) ;
if ( V_2 -> V_14 == NULL ) {
V_22 = - V_26 ;
goto V_38;
}
F_19 ( V_2 ) ;
V_22 = F_20 ( V_2 , V_21 ) ;
if ( V_22 < 0 )
goto V_42;
return V_2 ;
V_42:
F_21 ( V_2 -> V_14 ) ;
V_38:
F_21 ( V_2 ) ;
V_24:
return F_22 ( V_22 ) ;
}
int F_23 ( struct V_1 * V_2 , const struct V_20 * V_21 )
{
int V_22 ;
F_24 ( & V_2 -> V_27 ) ;
F_25 ( V_2 ) ;
V_2 -> V_4 = V_21 -> V_4 ;
V_2 -> V_5 = V_21 -> V_5 ;
V_2 -> V_7 = V_21 -> V_7 ;
V_2 -> V_8 = V_21 -> V_8 ;
V_2 -> V_9 = V_21 -> V_9 ;
V_2 -> V_34 = V_21 -> V_34 ;
V_2 -> V_43 = false ;
V_2 -> V_44 = false ;
V_22 = F_20 ( V_2 , V_21 ) ;
F_26 ( & V_2 -> V_27 ) ;
return V_22 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_28 ( V_2 ) ;
F_21 ( V_2 -> V_14 ) ;
F_21 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_12 , T_3 V_45 )
{
T_2 * T_2 = V_2 -> V_14 ;
void * V_15 ;
int V_22 = - V_46 ;
T_3 V_47 ;
int V_11 ;
if ( V_2 -> V_5 )
for ( V_11 = 0 ; V_11 < V_45 / V_2 -> V_28 . V_33 ; V_11 ++ )
if ( ! V_2 -> V_5 ( V_2 -> V_6 , V_3 + V_11 ) )
return - V_23 ;
V_2 -> V_28 . V_39 ( V_2 -> V_14 , V_3 ) ;
T_2 [ 0 ] |= V_2 -> V_36 ;
F_30 ( V_2 -> V_6 , V_3 ,
V_45 / V_2 -> V_28 . V_33 ) ;
if ( V_12 == V_2 -> V_14 + V_2 -> V_28 . V_32 )
V_22 = V_2 -> V_19 -> V_48 ( V_2 -> V_6 , V_2 -> V_14 ,
V_2 -> V_28 . V_32 + V_45 ) ;
else if ( V_2 -> V_19 -> V_49 )
V_22 = V_2 -> V_19 -> V_49 ( V_2 -> V_6 , V_2 -> V_14 ,
V_2 -> V_28 . V_32 ,
V_12 , V_45 ) ;
if ( V_22 == - V_46 ) {
V_47 = V_2 -> V_28 . V_32 + V_45 ;
V_15 = F_18 ( V_47 , V_25 ) ;
if ( ! V_15 )
return - V_26 ;
memcpy ( V_15 , V_2 -> V_14 , V_2 -> V_28 . V_32 ) ;
memcpy ( V_15 + V_2 -> V_28 . V_32 , V_12 , V_45 ) ;
V_22 = V_2 -> V_19 -> V_48 ( V_2 -> V_6 , V_15 , V_47 ) ;
F_21 ( V_15 ) ;
}
F_31 ( V_2 -> V_6 , V_3 ,
V_45 / V_2 -> V_28 . V_33 ) ;
return V_22 ;
}
int F_32 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_12 )
{
int V_22 ;
F_33 ( ! V_2 -> V_28 . V_37 && ! V_2 -> V_28 . V_40 ) ;
if ( ! V_2 -> V_43 ) {
V_22 = F_34 ( V_2 , V_3 , V_12 ) ;
if ( V_22 != 0 )
return V_22 ;
if ( V_2 -> V_44 ) {
V_2 -> V_50 = true ;
return 0 ;
}
}
F_35 ( V_2 -> V_6 , V_3 , V_12 ) ;
if ( V_2 -> V_28 . V_37 ) {
V_2 -> V_28 . V_37 ( V_2 , V_3 , V_12 ) ;
F_30 ( V_2 -> V_6 , V_3 , 1 ) ;
V_22 = V_2 -> V_19 -> V_48 ( V_2 -> V_6 , V_2 -> V_14 ,
V_2 -> V_28 . V_29 ) ;
F_31 ( V_2 -> V_6 , V_3 , 1 ) ;
return V_22 ;
} else {
V_2 -> V_28 . V_40 ( V_2 -> V_14 + V_2 -> V_28 . V_32 ,
V_12 ) ;
return F_29 ( V_2 , V_3 ,
V_2 -> V_14 + V_2 -> V_28 . V_32 ,
V_2 -> V_28 . V_33 ) ;
}
}
int F_36 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_12 )
{
int V_22 ;
F_24 ( & V_2 -> V_27 ) ;
V_22 = F_32 ( V_2 , V_3 , V_12 ) ;
F_26 ( & V_2 -> V_27 ) ;
return V_22 ;
}
int F_37 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_12 , T_3 V_45 )
{
T_3 V_51 = V_45 / V_2 -> V_28 . V_33 ;
int V_22 ;
F_38 ( ! F_5 ( V_2 , V_3 , V_51 ) &&
V_2 -> V_34 != V_52 ) ;
F_24 ( & V_2 -> V_27 ) ;
V_22 = F_29 ( V_2 , V_3 , V_12 , V_45 ) ;
F_26 ( & V_2 -> V_27 ) ;
return V_22 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_3 , void * V_12 ,
unsigned int V_45 )
{
T_2 * T_2 = V_2 -> V_14 ;
int V_22 ;
V_2 -> V_28 . V_39 ( V_2 -> V_14 , V_3 ) ;
T_2 [ 0 ] |= V_2 -> V_35 ;
F_40 ( V_2 -> V_6 , V_3 ,
V_45 / V_2 -> V_28 . V_33 ) ;
V_22 = V_2 -> V_19 -> V_53 ( V_2 -> V_6 , V_2 -> V_14 , V_2 -> V_28 . V_32 ,
V_12 , V_45 ) ;
F_41 ( V_2 -> V_6 , V_3 ,
V_45 / V_2 -> V_28 . V_33 ) ;
return V_22 ;
}
static int F_42 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_12 )
{
int V_22 ;
if ( ! V_2 -> V_43 ) {
V_22 = F_43 ( V_2 , V_3 , V_12 ) ;
if ( V_22 == 0 )
return 0 ;
}
if ( ! V_2 -> V_28 . V_41 )
return - V_23 ;
if ( V_2 -> V_44 )
return - V_54 ;
V_22 = F_39 ( V_2 , V_3 , V_2 -> V_14 , V_2 -> V_28 . V_33 ) ;
if ( V_22 == 0 ) {
* V_12 = V_2 -> V_28 . V_41 ( V_2 -> V_14 ) ;
F_44 ( V_2 -> V_6 , V_3 , * V_12 ) ;
}
return V_22 ;
}
int F_45 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int * V_12 )
{
int V_22 ;
F_24 ( & V_2 -> V_27 ) ;
V_22 = F_42 ( V_2 , V_3 , V_12 ) ;
F_26 ( & V_2 -> V_27 ) ;
return V_22 ;
}
int F_46 ( struct V_1 * V_2 , unsigned int V_3 , void * V_12 ,
T_3 V_45 )
{
T_3 V_51 = V_45 / V_2 -> V_28 . V_33 ;
int V_22 ;
F_38 ( ! F_5 ( V_2 , V_3 , V_51 ) &&
V_2 -> V_34 != V_52 ) ;
F_24 ( & V_2 -> V_27 ) ;
V_22 = F_39 ( V_2 , V_3 , V_12 , V_45 ) ;
F_26 ( & V_2 -> V_27 ) ;
return V_22 ;
}
int F_47 ( struct V_1 * V_2 , unsigned int V_3 , void * V_12 ,
T_3 V_51 )
{
int V_22 , V_11 ;
T_3 V_33 = V_2 -> V_28 . V_33 ;
bool V_55 = F_5 ( V_2 , V_3 , V_51 ) ;
if ( ! V_2 -> V_28 . V_41 )
return - V_23 ;
if ( V_55 || V_2 -> V_34 == V_52 ) {
V_22 = F_46 ( V_2 , V_3 , V_12 , V_33 * V_51 ) ;
if ( V_22 != 0 )
return V_22 ;
for ( V_11 = 0 ; V_11 < V_51 * V_33 ; V_11 += V_33 )
V_2 -> V_28 . V_41 ( V_12 + V_11 ) ;
} else {
for ( V_11 = 0 ; V_11 < V_51 ; V_11 ++ ) {
V_22 = F_45 ( V_2 , V_3 + V_11 , V_12 + ( V_11 * V_33 ) ) ;
if ( V_22 != 0 )
return V_22 ;
}
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_56 , unsigned int V_12 ,
bool * V_57 )
{
int V_22 ;
unsigned int V_58 , V_59 ;
F_24 ( & V_2 -> V_27 ) ;
V_22 = F_42 ( V_2 , V_3 , & V_59 ) ;
if ( V_22 != 0 )
goto V_13;
V_58 = V_59 & ~ V_56 ;
V_58 |= V_12 & V_56 ;
if ( V_58 != V_59 ) {
V_22 = F_32 ( V_2 , V_3 , V_58 ) ;
* V_57 = true ;
} else {
* V_57 = false ;
}
V_13:
F_26 ( & V_2 -> V_27 ) ;
return V_22 ;
}
int F_49 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_56 , unsigned int V_12 )
{
bool V_57 ;
return F_48 ( V_2 , V_3 , V_56 , V_12 , & V_57 ) ;
}
int F_50 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_56 , unsigned int V_12 ,
bool * V_57 )
{
return F_48 ( V_2 , V_3 , V_56 , V_12 , V_57 ) ;
}
static int T_4 F_51 ( void )
{
F_52 () ;
return 0 ;
}

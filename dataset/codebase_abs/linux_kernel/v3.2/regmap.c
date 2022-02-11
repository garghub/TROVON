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
static void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_10 )
{
T_1 * V_11 = V_2 -> V_12 ;
* V_11 = F_6 ( ( V_3 << 12 ) | V_10 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_10 )
{
T_1 * V_11 = V_2 -> V_12 ;
* V_11 = F_6 ( ( V_3 << 9 ) | V_10 ) ;
}
static void F_8 ( void * V_13 , unsigned int V_10 )
{
T_2 * V_14 = V_13 ;
V_14 [ 0 ] = V_10 ;
}
static void F_9 ( void * V_13 , unsigned int V_10 )
{
T_1 * V_14 = V_13 ;
V_14 [ 0 ] = F_6 ( V_10 ) ;
}
static unsigned int F_10 ( void * V_13 )
{
T_2 * V_14 = V_13 ;
return V_14 [ 0 ] ;
}
static unsigned int F_11 ( void * V_13 )
{
T_1 * V_14 = V_13 ;
V_14 [ 0 ] = F_12 ( V_14 [ 0 ] ) ;
return V_14 [ 0 ] ;
}
struct V_1 * F_13 ( struct V_15 * V_6 ,
const struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_1 * V_2 ;
int V_20 = - V_21 ;
if ( ! V_17 || ! V_19 )
return NULL ;
V_2 = F_14 ( sizeof( * V_2 ) , V_22 ) ;
if ( V_2 == NULL ) {
V_20 = - V_23 ;
goto V_24;
}
F_15 ( & V_2 -> V_25 ) ;
V_2 -> V_26 . V_27 = ( V_19 -> V_28 + V_19 -> V_29 ) / 8 ;
V_2 -> V_26 . V_30 = V_19 -> V_28 / 8 ;
V_2 -> V_26 . V_31 = V_19 -> V_29 / 8 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_4 = V_19 -> V_4 ;
V_2 -> V_5 = V_19 -> V_5 ;
V_2 -> V_7 = V_19 -> V_7 ;
V_2 -> V_8 = V_19 -> V_8 ;
V_2 -> V_9 = V_19 -> V_9 ;
V_2 -> V_32 = V_19 -> V_32 ;
V_2 -> V_33 = V_19 -> V_33 ;
V_2 -> V_34 = V_19 -> V_34 ;
V_2 -> V_35 = V_19 -> V_35 ;
V_2 -> V_36 = V_19 -> V_36 ;
V_2 -> V_37 = ( V_19 -> V_29 / 8 ) * V_19 -> V_35 ;
V_2 -> V_38 = V_19 -> V_29 / 8 ;
if ( V_19 -> V_39 || V_19 -> V_40 ) {
V_2 -> V_39 = V_19 -> V_39 ;
V_2 -> V_40 = V_19 -> V_40 ;
} else {
V_2 -> V_39 = V_17 -> V_39 ;
}
switch ( V_19 -> V_28 ) {
case 4 :
switch ( V_19 -> V_29 ) {
case 12 :
V_2 -> V_26 . V_41 = F_5 ;
break;
default:
goto V_42;
}
break;
case 7 :
switch ( V_19 -> V_29 ) {
case 9 :
V_2 -> V_26 . V_41 = F_7 ;
break;
default:
goto V_42;
}
break;
case 8 :
V_2 -> V_26 . V_43 = F_8 ;
break;
case 16 :
V_2 -> V_26 . V_43 = F_9 ;
break;
default:
goto V_42;
}
switch ( V_19 -> V_29 ) {
case 8 :
V_2 -> V_26 . V_44 = F_8 ;
V_2 -> V_26 . V_45 = F_10 ;
break;
case 16 :
V_2 -> V_26 . V_44 = F_9 ;
V_2 -> V_26 . V_45 = F_11 ;
break;
}
if ( ! V_2 -> V_26 . V_41 &&
! ( V_2 -> V_26 . V_43 && V_2 -> V_26 . V_44 ) )
goto V_42;
V_2 -> V_12 = F_16 ( V_2 -> V_26 . V_27 , V_22 ) ;
if ( V_2 -> V_12 == NULL ) {
V_20 = - V_23 ;
goto V_42;
}
V_20 = F_17 ( V_2 ) ;
if ( V_20 < 0 )
goto V_42;
F_18 ( V_2 ) ;
return V_2 ;
V_42:
F_19 ( V_2 ) ;
V_24:
return F_20 ( V_20 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_23 ( V_2 ) ;
F_19 ( V_2 -> V_12 ) ;
F_19 ( V_2 ) ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_10 , T_3 V_46 )
{
T_2 * T_2 = V_2 -> V_12 ;
void * V_13 ;
int V_20 = - V_47 ;
T_3 V_48 ;
int V_49 ;
if ( V_2 -> V_5 )
for ( V_49 = 0 ; V_49 < V_46 / V_2 -> V_26 . V_31 ; V_49 ++ )
if ( ! V_2 -> V_5 ( V_2 -> V_6 , V_3 + V_49 ) )
return - V_21 ;
V_2 -> V_26 . V_43 ( V_2 -> V_12 , V_3 ) ;
T_2 [ 0 ] |= V_2 -> V_40 ;
F_25 ( V_2 -> V_6 , V_3 ,
V_46 / V_2 -> V_26 . V_31 ) ;
if ( V_10 == V_2 -> V_12 + V_2 -> V_26 . V_30 )
V_20 = V_2 -> V_17 -> V_50 ( V_2 -> V_6 , V_2 -> V_12 ,
V_2 -> V_26 . V_30 + V_46 ) ;
else if ( V_2 -> V_17 -> V_51 )
V_20 = V_2 -> V_17 -> V_51 ( V_2 -> V_6 , V_2 -> V_12 ,
V_2 -> V_26 . V_30 ,
V_10 , V_46 ) ;
if ( V_20 == - V_47 ) {
V_48 = V_2 -> V_26 . V_30 + V_46 ;
V_13 = F_16 ( V_48 , V_22 ) ;
if ( ! V_13 )
return - V_23 ;
memcpy ( V_13 , V_2 -> V_12 , V_2 -> V_26 . V_30 ) ;
memcpy ( V_13 + V_2 -> V_26 . V_30 , V_10 , V_46 ) ;
V_20 = V_2 -> V_17 -> V_50 ( V_2 -> V_6 , V_13 , V_48 ) ;
F_19 ( V_13 ) ;
}
F_26 ( V_2 -> V_6 , V_3 ,
V_46 / V_2 -> V_26 . V_31 ) ;
return V_20 ;
}
int F_27 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_10 )
{
int V_20 ;
F_28 ( ! V_2 -> V_26 . V_41 && ! V_2 -> V_26 . V_44 ) ;
if ( ! V_2 -> V_52 ) {
V_20 = F_29 ( V_2 , V_3 , V_10 ) ;
if ( V_20 != 0 )
return V_20 ;
if ( V_2 -> V_53 )
return 0 ;
}
F_30 ( V_2 -> V_6 , V_3 , V_10 ) ;
if ( V_2 -> V_26 . V_41 ) {
V_2 -> V_26 . V_41 ( V_2 , V_3 , V_10 ) ;
F_25 ( V_2 -> V_6 , V_3 , 1 ) ;
V_20 = V_2 -> V_17 -> V_50 ( V_2 -> V_6 , V_2 -> V_12 ,
V_2 -> V_26 . V_27 ) ;
F_26 ( V_2 -> V_6 , V_3 , 1 ) ;
return V_20 ;
} else {
V_2 -> V_26 . V_44 ( V_2 -> V_12 + V_2 -> V_26 . V_30 ,
V_10 ) ;
return F_24 ( V_2 , V_3 ,
V_2 -> V_12 + V_2 -> V_26 . V_30 ,
V_2 -> V_26 . V_31 ) ;
}
}
int F_31 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_10 )
{
int V_20 ;
F_32 ( & V_2 -> V_25 ) ;
V_20 = F_27 ( V_2 , V_3 , V_10 ) ;
F_33 ( & V_2 -> V_25 ) ;
return V_20 ;
}
int F_34 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_10 , T_3 V_46 )
{
int V_20 ;
F_35 ( V_2 -> V_32 != V_54 ) ;
F_32 ( & V_2 -> V_25 ) ;
V_20 = F_24 ( V_2 , V_3 , V_10 , V_46 ) ;
F_33 ( & V_2 -> V_25 ) ;
return V_20 ;
}
static int F_36 ( struct V_1 * V_2 , unsigned int V_3 , void * V_10 ,
unsigned int V_46 )
{
T_2 * T_2 = V_2 -> V_12 ;
int V_20 ;
V_2 -> V_26 . V_43 ( V_2 -> V_12 , V_3 ) ;
T_2 [ 0 ] |= V_2 -> V_39 ;
F_37 ( V_2 -> V_6 , V_3 ,
V_46 / V_2 -> V_26 . V_31 ) ;
V_20 = V_2 -> V_17 -> V_55 ( V_2 -> V_6 , V_2 -> V_12 , V_2 -> V_26 . V_30 ,
V_10 , V_46 ) ;
F_38 ( V_2 -> V_6 , V_3 ,
V_46 / V_2 -> V_26 . V_31 ) ;
return V_20 ;
}
static int F_39 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_10 )
{
int V_20 ;
if ( ! V_2 -> V_26 . V_45 )
return - V_21 ;
if ( ! V_2 -> V_52 ) {
V_20 = F_40 ( V_2 , V_3 , V_10 ) ;
if ( V_20 == 0 )
return 0 ;
}
if ( V_2 -> V_53 )
return - V_56 ;
V_20 = F_36 ( V_2 , V_3 , V_2 -> V_12 , V_2 -> V_26 . V_31 ) ;
if ( V_20 == 0 ) {
* V_10 = V_2 -> V_26 . V_45 ( V_2 -> V_12 ) ;
F_41 ( V_2 -> V_6 , V_3 , * V_10 ) ;
}
return V_20 ;
}
int F_42 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int * V_10 )
{
int V_20 ;
F_32 ( & V_2 -> V_25 ) ;
V_20 = F_39 ( V_2 , V_3 , V_10 ) ;
F_33 ( & V_2 -> V_25 ) ;
return V_20 ;
}
int F_43 ( struct V_1 * V_2 , unsigned int V_3 , void * V_10 ,
T_3 V_46 )
{
int V_20 ;
int V_49 ;
bool V_57 = true ;
for ( V_49 = 0 ; V_49 < V_46 / V_2 -> V_26 . V_31 ; V_49 ++ )
if ( ! F_3 ( V_2 , V_3 + V_49 ) )
V_57 = false ;
F_35 ( ! V_57 && V_2 -> V_32 != V_54 ) ;
F_32 ( & V_2 -> V_25 ) ;
V_20 = F_36 ( V_2 , V_3 , V_10 , V_46 ) ;
F_33 ( & V_2 -> V_25 ) ;
return V_20 ;
}
int F_44 ( struct V_1 * V_2 , unsigned int V_3 , void * V_10 ,
T_3 V_58 )
{
int V_20 , V_49 ;
T_3 V_31 = V_2 -> V_26 . V_31 ;
bool V_57 = true ;
if ( ! V_2 -> V_26 . V_45 )
return - V_21 ;
for ( V_49 = 0 ; V_49 < V_58 ; V_49 ++ )
if ( ! F_3 ( V_2 , V_3 + V_49 ) )
V_57 = false ;
if ( V_57 || V_2 -> V_32 == V_54 ) {
V_20 = F_43 ( V_2 , V_3 , V_10 , V_31 * V_58 ) ;
if ( V_20 != 0 )
return V_20 ;
for ( V_49 = 0 ; V_49 < V_58 * V_31 ; V_49 += V_31 )
V_2 -> V_26 . V_45 ( V_10 + V_49 ) ;
} else {
for ( V_49 = 0 ; V_49 < V_58 ; V_49 ++ ) {
V_20 = F_42 ( V_2 , V_3 + V_49 , V_10 + ( V_49 * V_31 ) ) ;
if ( V_20 != 0 )
return V_20 ;
}
}
return 0 ;
}
int F_45 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_59 , unsigned int V_10 )
{
int V_20 ;
unsigned int V_60 ;
F_32 ( & V_2 -> V_25 ) ;
V_20 = F_39 ( V_2 , V_3 , & V_60 ) ;
if ( V_20 != 0 )
goto V_11;
V_60 &= ~ V_59 ;
V_60 |= V_10 & V_59 ;
V_20 = F_27 ( V_2 , V_3 , V_60 ) ;
V_11:
F_33 ( & V_2 -> V_25 ) ;
return V_20 ;
}
static int T_4 F_46 ( void )
{
F_47 () ;
return 0 ;
}

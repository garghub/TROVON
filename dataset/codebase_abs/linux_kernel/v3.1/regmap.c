static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
T_1 * V_5 = V_2 -> V_6 ;
* V_5 = F_2 ( ( V_3 << 12 ) | V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
T_1 * V_5 = V_2 -> V_6 ;
* V_5 = F_2 ( ( V_3 << 9 ) | V_4 ) ;
}
static void F_4 ( void * V_7 , unsigned int V_4 )
{
T_2 * V_8 = V_7 ;
V_8 [ 0 ] = V_4 ;
}
static void F_5 ( void * V_7 , unsigned int V_4 )
{
T_1 * V_8 = V_7 ;
V_8 [ 0 ] = F_2 ( V_4 ) ;
}
static unsigned int F_6 ( void * V_7 )
{
T_2 * V_8 = V_7 ;
return V_8 [ 0 ] ;
}
static unsigned int F_7 ( void * V_7 )
{
T_1 * V_8 = V_7 ;
V_8 [ 0 ] = F_8 ( V_8 [ 0 ] ) ;
return V_8 [ 0 ] ;
}
struct V_1 * F_9 ( struct V_9 * V_10 ,
const struct V_11 * V_12 ,
const struct V_13 * V_14 )
{
struct V_1 * V_2 ;
int V_15 = - V_16 ;
if ( ! V_12 || ! V_14 )
return NULL ;
V_2 = F_10 ( sizeof( * V_2 ) , V_17 ) ;
if ( V_2 == NULL ) {
V_15 = - V_18 ;
goto V_19;
}
F_11 ( & V_2 -> V_20 ) ;
V_2 -> V_21 . V_22 = ( V_14 -> V_23 + V_14 -> V_24 ) / 8 ;
V_2 -> V_21 . V_25 = V_14 -> V_23 / 8 ;
V_2 -> V_21 . V_26 = V_14 -> V_24 / 8 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_12 = V_12 ;
switch ( V_14 -> V_23 ) {
case 4 :
switch ( V_14 -> V_24 ) {
case 12 :
V_2 -> V_21 . V_27 = F_1 ;
break;
default:
goto V_28;
}
break;
case 7 :
switch ( V_14 -> V_24 ) {
case 9 :
V_2 -> V_21 . V_27 = F_3 ;
break;
default:
goto V_28;
}
break;
case 8 :
V_2 -> V_21 . V_29 = F_4 ;
break;
case 16 :
V_2 -> V_21 . V_29 = F_5 ;
break;
default:
goto V_28;
}
switch ( V_14 -> V_24 ) {
case 8 :
V_2 -> V_21 . V_30 = F_4 ;
V_2 -> V_21 . V_31 = F_6 ;
break;
case 16 :
V_2 -> V_21 . V_30 = F_5 ;
V_2 -> V_21 . V_31 = F_7 ;
break;
}
if ( ! V_2 -> V_21 . V_27 &&
! ( V_2 -> V_21 . V_29 && V_2 -> V_21 . V_30 ) )
goto V_28;
V_2 -> V_6 = F_12 ( V_2 -> V_21 . V_22 , V_17 ) ;
if ( V_2 -> V_6 == NULL ) {
V_15 = - V_18 ;
goto V_28;
}
return V_2 ;
V_28:
F_13 ( V_2 ) ;
V_19:
return F_14 ( V_15 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_6 ) ;
F_13 ( V_2 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_4 , T_3 V_32 )
{
void * V_7 ;
int V_15 = - V_33 ;
T_3 V_34 ;
V_2 -> V_21 . V_29 ( V_2 -> V_6 , V_3 ) ;
if ( V_2 -> V_12 -> V_35 )
V_15 = V_2 -> V_12 -> V_35 ( V_2 -> V_10 , V_2 -> V_6 ,
V_2 -> V_21 . V_25 ,
V_4 , V_32 ) ;
if ( V_15 == - V_33 ) {
V_34 = V_2 -> V_21 . V_25 + V_32 ;
V_7 = F_12 ( V_34 , V_17 ) ;
if ( ! V_7 )
return - V_18 ;
memcpy ( V_7 , V_2 -> V_6 , V_2 -> V_21 . V_25 ) ;
memcpy ( V_7 + V_2 -> V_21 . V_25 , V_4 , V_32 ) ;
V_15 = V_2 -> V_12 -> V_36 ( V_2 -> V_10 , V_7 , V_34 ) ;
F_13 ( V_7 ) ;
}
return V_15 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
F_18 ( ! V_2 -> V_21 . V_27 && ! V_2 -> V_21 . V_30 ) ;
if ( V_2 -> V_21 . V_27 ) {
V_2 -> V_21 . V_27 ( V_2 , V_3 , V_4 ) ;
return V_2 -> V_12 -> V_36 ( V_2 -> V_10 , V_2 -> V_6 ,
V_2 -> V_21 . V_22 ) ;
} else {
V_2 -> V_21 . V_30 ( V_2 -> V_6 + V_2 -> V_21 . V_25 ,
V_4 ) ;
return F_16 ( V_2 , V_3 ,
V_2 -> V_6 + V_2 -> V_21 . V_25 ,
V_2 -> V_21 . V_26 ) ;
}
}
int F_19 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_4 )
{
int V_15 ;
F_20 ( & V_2 -> V_20 ) ;
V_15 = F_17 ( V_2 , V_3 , V_4 ) ;
F_21 ( & V_2 -> V_20 ) ;
return V_15 ;
}
int F_22 ( struct V_1 * V_2 , unsigned int V_3 ,
const void * V_4 , T_3 V_32 )
{
int V_15 ;
F_20 ( & V_2 -> V_20 ) ;
V_15 = F_16 ( V_2 , V_3 , V_4 , V_32 ) ;
F_21 ( & V_2 -> V_20 ) ;
return V_15 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int V_3 , void * V_4 ,
unsigned int V_32 )
{
T_2 * T_2 = V_2 -> V_6 ;
int V_15 ;
V_2 -> V_21 . V_29 ( V_2 -> V_6 , V_3 ) ;
if ( V_2 -> V_12 -> V_37 )
T_2 [ 0 ] |= V_2 -> V_12 -> V_37 ;
V_15 = V_2 -> V_12 -> V_38 ( V_2 -> V_10 , V_2 -> V_6 , V_2 -> V_21 . V_25 ,
V_4 , V_32 ) ;
if ( V_15 != 0 )
return V_15 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
int V_15 ;
if ( ! V_2 -> V_21 . V_31 )
return - V_16 ;
V_15 = F_23 ( V_2 , V_3 , V_2 -> V_6 , V_2 -> V_21 . V_26 ) ;
if ( V_15 == 0 )
* V_4 = V_2 -> V_21 . V_31 ( V_2 -> V_6 ) ;
return V_15 ;
}
int F_25 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int * V_4 )
{
int V_15 ;
F_20 ( & V_2 -> V_20 ) ;
V_15 = F_24 ( V_2 , V_3 , V_4 ) ;
F_21 ( & V_2 -> V_20 ) ;
return V_15 ;
}
int F_26 ( struct V_1 * V_2 , unsigned int V_3 , void * V_4 ,
T_3 V_32 )
{
int V_15 ;
F_20 ( & V_2 -> V_20 ) ;
V_15 = F_23 ( V_2 , V_3 , V_4 , V_32 ) ;
F_21 ( & V_2 -> V_20 ) ;
return V_15 ;
}
int F_27 ( struct V_1 * V_2 , unsigned int V_3 , void * V_4 ,
T_3 V_39 )
{
int V_15 , V_40 ;
T_3 V_26 = V_2 -> V_21 . V_26 ;
if ( ! V_2 -> V_21 . V_31 )
return - V_16 ;
V_15 = F_26 ( V_2 , V_3 , V_4 , V_26 * V_39 ) ;
if ( V_15 != 0 )
return V_15 ;
for ( V_40 = 0 ; V_40 < V_39 * V_26 ; V_40 += V_26 )
V_2 -> V_21 . V_31 ( V_4 + V_40 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_41 , unsigned int V_4 )
{
int V_15 ;
unsigned int V_42 ;
F_20 ( & V_2 -> V_20 ) ;
V_15 = F_24 ( V_2 , V_3 , & V_42 ) ;
if ( V_15 != 0 )
goto V_5;
V_42 &= ~ V_41 ;
V_42 |= V_4 & V_41 ;
V_15 = F_17 ( V_2 , V_3 , V_42 ) ;
V_5:
F_21 ( & V_2 -> V_20 ) ;
return V_15 ;
}

static unsigned char F_1 ( const struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) )
return ( V_2 -> V_3 != V_2 -> V_4 ?
V_5 : V_6 ) ;
if ( F_3 ( V_2 ) )
return V_7 ;
return V_8 ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned char V_9 = F_1 ( V_2 ) ;
if ( V_9 == V_2 -> V_9 )
return;
F_5 ( & V_10 ) ;
switch( V_2 -> V_11 ) {
case V_12 :
if ( V_9 == V_8 )
V_9 = V_7 ;
break;
case V_13 :
default:
break;
}
V_2 -> V_9 = V_9 ;
F_6 ( & V_10 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 ) || F_3 ( V_2 ) )
F_4 ( V_2 ) ;
}
static bool F_8 ( struct V_1 * V_2 )
{
if ( ! F_9 ( V_2 ) )
return false ;
if ( V_2 -> V_3 != V_2 -> V_4 )
return true ;
return F_2 ( V_2 ) && F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
F_12 ( & V_15 , V_14 ) ;
if ( F_13 ( & V_2 -> V_16 ) ) {
F_14 ( & V_2 -> V_16 , & V_17 ) ;
F_15 ( V_2 ) ;
}
F_16 ( & V_15 , V_14 ) ;
}
static void F_17 ( int V_18 )
{
unsigned long V_19 = V_20 - V_21 ;
if ( F_18 ( V_22 , & V_23 ) )
return;
if ( V_18 ) {
if ( F_19 ( V_22 , & V_23 ) )
return;
V_19 = 0 ;
}
if ( V_19 > V_24 )
V_19 = 0 ;
if ( F_18 ( V_22 , & V_23 ) )
F_20 ( V_25 , & V_26 , 0 ) ;
else
F_21 ( & V_26 , V_19 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 () ;
F_24 ( V_27 , & V_2 -> V_28 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_14 & V_29 ) {
if ( F_2 ( V_2 ) )
F_25 ( V_2 ) ;
else
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
}
F_28 ( V_2 ) ;
}
static void F_29 ( int V_30 )
{
struct V_1 * V_2 ;
F_30 ( V_31 ) ;
if ( ! V_30 )
V_20 = V_21 + V_24 ;
else if ( F_31 ( V_20 , V_21 + V_24 ) )
V_20 = V_21 ;
F_24 ( V_22 , & V_23 ) ;
F_32 ( & V_15 ) ;
F_33 ( & V_17 , & V_31 ) ;
while ( ! F_13 ( & V_31 ) ) {
V_2 = F_34 ( & V_31 , struct V_1 , V_16 ) ;
F_35 ( & V_2 -> V_16 ) ;
if ( V_30 && ! F_8 ( V_2 ) ) {
F_14 ( & V_2 -> V_16 , & V_17 ) ;
continue;
}
F_36 ( & V_15 ) ;
F_22 ( V_2 ) ;
F_32 ( & V_15 ) ;
}
if ( ! F_13 ( & V_17 ) )
F_17 ( 0 ) ;
F_36 ( & V_15 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
int V_32 = 0 ;
F_12 ( & V_15 , V_14 ) ;
if ( ! F_13 ( & V_2 -> V_16 ) ) {
F_35 ( & V_2 -> V_16 ) ;
V_32 = 1 ;
}
F_16 ( & V_15 , V_14 ) ;
if ( V_32 )
F_22 ( V_2 ) ;
}
void F_38 ( void )
{
F_29 ( 0 ) ;
}
static void F_39 ( struct V_33 * V_34 )
{
F_40 () ;
F_29 ( F_31 ( V_20 , V_21 ) ) ;
F_41 () ;
}
void F_42 ( struct V_1 * V_2 )
{
bool V_18 = F_8 ( V_2 ) ;
if ( ! F_19 ( V_27 , & V_2 -> V_28 ) ) {
F_11 ( V_2 ) ;
} else if ( ! V_18 )
return;
F_17 ( V_18 ) ;
}

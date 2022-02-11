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
if ( V_2 -> V_14 & V_15 )
return true ;
return F_2 ( V_2 ) && F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
F_12 ( & V_17 , V_16 ) ;
if ( F_13 ( & V_2 -> V_18 ) ) {
F_14 ( & V_2 -> V_18 , & V_19 ) ;
F_15 ( V_2 ) ;
}
F_16 ( & V_17 , V_16 ) ;
}
static void F_17 ( int V_20 )
{
unsigned long V_21 = V_22 - V_23 ;
if ( F_18 ( V_24 , & V_25 ) )
return;
if ( V_20 ) {
if ( F_19 ( V_24 , & V_25 ) )
return;
V_21 = 0 ;
}
if ( V_21 > V_26 )
V_21 = 0 ;
if ( F_18 ( V_24 , & V_25 ) )
F_20 ( V_27 , & V_28 , 0 ) ;
else
F_21 ( & V_28 , V_21 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 () ;
F_24 ( V_29 , & V_2 -> V_30 ) ;
F_4 ( V_2 ) ;
if ( V_2 -> V_16 & V_31 ) {
if ( F_2 ( V_2 ) )
F_25 ( V_2 ) ;
else
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
}
F_28 ( V_2 ) ;
}
static void F_29 ( int V_32 )
{
struct V_1 * V_2 ;
F_30 ( V_33 ) ;
if ( ! V_32 )
V_22 = V_23 + V_26 ;
else if ( F_31 ( V_22 , V_23 + V_26 ) )
V_22 = V_23 ;
F_24 ( V_24 , & V_25 ) ;
F_32 ( & V_17 ) ;
F_33 ( & V_19 , & V_33 ) ;
while ( ! F_13 ( & V_33 ) ) {
V_2 = F_34 ( & V_33 , struct V_1 , V_18 ) ;
F_35 ( & V_2 -> V_18 ) ;
if ( V_32 && ! F_8 ( V_2 ) ) {
F_14 ( & V_2 -> V_18 , & V_19 ) ;
continue;
}
F_36 ( & V_17 ) ;
F_22 ( V_2 ) ;
F_32 ( & V_17 ) ;
}
if ( ! F_13 ( & V_19 ) )
F_17 ( 0 ) ;
F_36 ( & V_17 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
int V_34 = 0 ;
F_12 ( & V_17 , V_16 ) ;
if ( ! F_13 ( & V_2 -> V_18 ) ) {
F_35 ( & V_2 -> V_18 ) ;
V_34 = 1 ;
}
F_16 ( & V_17 , V_16 ) ;
if ( V_34 )
F_22 ( V_2 ) ;
}
void F_38 ( void )
{
F_29 ( 0 ) ;
}
static void F_39 ( struct V_35 * V_36 )
{
F_40 () ;
F_29 ( F_31 ( V_22 , V_23 ) ) ;
F_41 () ;
}
void F_42 ( struct V_1 * V_2 )
{
bool V_20 = F_8 ( V_2 ) ;
if ( ! F_19 ( V_29 , & V_2 -> V_30 ) ) {
F_11 ( V_2 ) ;
} else if ( ! V_20 )
return;
F_17 ( V_20 ) ;
}

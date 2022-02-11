static unsigned int
F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 ) ;
if ( V_4 -> V_5 == V_6 && V_4 -> V_7 >= 0x4c )
F_3 ( V_4 , 0x088060 , V_2 ) ;
else if ( V_4 -> V_7 >= 0x40 )
F_3 ( V_4 , 0x088054 , V_2 ) ;
else
F_3 ( V_4 , 0x001854 , V_2 ) ;
if ( V_2 )
return V_8 | V_9 |
V_10 | V_11 ;
else
return V_10 | V_11 ;
}
static void
F_4 ( struct V_12 * V_13 ,
enum V_14 V_2 )
{
struct V_15 * V_16 = F_5 ( V_13 ) ;
if ( ( F_6 () || F_7 () ) && V_2 == V_17 )
return;
if ( V_2 == V_18 ) {
F_8 ( V_19 L_1 ) ;
V_16 -> V_20 = V_21 ;
F_9 ( & V_13 -> V_16 ) ;
F_10 ( V_16 ) ;
V_16 -> V_20 = V_22 ;
} else {
F_8 ( V_19 L_2 ) ;
V_16 -> V_20 = V_21 ;
F_11 ( V_16 ) ;
F_12 () ;
F_13 ( & V_13 -> V_16 ) ;
V_16 -> V_20 = V_23 ;
}
}
static void
F_14 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = F_5 ( V_13 ) ;
F_15 ( V_16 ) ;
}
static bool
F_16 ( struct V_12 * V_13 )
{
struct V_15 * V_16 = F_5 ( V_13 ) ;
bool V_24 ;
F_17 ( & V_16 -> V_25 ) ;
V_24 = ( V_16 -> V_26 == 0 ) ;
F_18 ( & V_16 -> V_25 ) ;
return V_24 ;
}
void
F_19 ( struct V_27 * V_28 )
{
struct V_15 * V_16 = V_28 -> V_16 ;
bool V_29 = false ;
if ( ! V_16 -> V_13 )
return;
F_20 ( V_16 -> V_13 , V_16 , NULL , F_1 ) ;
if ( V_30 == 1 )
V_29 = true ;
if ( ( V_30 == - 1 ) && ( F_6 () || F_7 () ) )
V_29 = true ;
F_21 ( V_16 -> V_13 , & V_31 , V_29 ) ;
if ( V_29 && F_7 () && ! F_6 () )
F_22 ( V_28 -> V_16 -> V_16 , & V_28 -> V_32 ) ;
}
void
F_23 ( struct V_27 * V_28 )
{
struct V_15 * V_16 = V_28 -> V_16 ;
F_24 ( V_16 -> V_13 ) ;
F_20 ( V_16 -> V_13 , NULL , NULL , NULL ) ;
}
void
F_25 ( struct V_15 * V_16 )
{
F_26 () ;
}

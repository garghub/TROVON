static unsigned int
F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_3 ( V_1 ) ;
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
if ( V_4 -> V_6 . V_8 . V_9 == V_10 &&
V_4 -> V_6 . V_8 . V_11 >= 0x4c )
F_2 ( V_6 , 0x088060 , V_2 ) ;
else
if ( V_4 -> V_6 . V_8 . V_11 >= 0x40 )
F_2 ( V_6 , 0x088054 , V_2 ) ;
else
F_2 ( V_6 , 0x001854 , V_2 ) ;
if ( V_2 )
return V_12 | V_13 |
V_14 | V_15 ;
else
return V_14 | V_15 ;
}
static void
F_3 ( struct V_16 * V_17 ,
enum V_18 V_2 )
{
struct V_19 * V_20 = F_4 ( V_17 ) ;
if ( ( F_5 () || F_6 () ) && V_2 == V_21 )
return;
if ( V_2 == V_22 ) {
F_7 ( V_23 L_1 ) ;
V_20 -> V_24 = V_25 ;
F_8 ( & V_17 -> V_20 ) ;
F_9 ( V_20 ) ;
V_20 -> V_24 = V_26 ;
} else {
F_7 ( V_23 L_2 ) ;
V_20 -> V_24 = V_25 ;
F_10 ( V_20 ) ;
F_11 () ;
F_12 ( & V_17 -> V_20 ) ;
V_20 -> V_24 = V_27 ;
}
}
static void
F_13 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_4 ( V_17 ) ;
F_14 ( V_20 ) ;
}
static bool
F_15 ( struct V_16 * V_17 )
{
struct V_19 * V_20 = F_4 ( V_17 ) ;
return V_20 -> V_28 == 0 ;
}
void
F_16 ( struct V_3 * V_4 )
{
struct V_19 * V_20 = V_4 -> V_20 ;
bool V_29 = false ;
if ( ! V_20 -> V_17 )
return;
F_17 ( V_20 -> V_17 , V_20 , NULL , F_1 ) ;
if ( V_30 == 1 )
V_29 = true ;
if ( ( V_30 == - 1 ) && ( F_5 () || F_6 () ) )
V_29 = true ;
F_18 ( V_20 -> V_17 , & V_31 , V_29 ) ;
if ( V_29 && F_6 () && ! F_5 () )
F_19 ( V_4 -> V_20 -> V_20 , & V_4 -> V_32 ) ;
}
void
F_20 ( struct V_3 * V_4 )
{
struct V_19 * V_20 = V_4 -> V_20 ;
bool V_29 = false ;
if ( V_30 == 1 )
V_29 = true ;
if ( ( V_30 == - 1 ) && ( F_5 () || F_6 () ) )
V_29 = true ;
F_21 ( V_20 -> V_17 ) ;
if ( V_29 && F_6 () && ! F_5 () )
F_22 ( V_4 -> V_20 -> V_20 ) ;
F_17 ( V_20 -> V_17 , NULL , NULL , NULL ) ;
}
void
F_23 ( struct V_19 * V_20 )
{
F_24 () ;
}

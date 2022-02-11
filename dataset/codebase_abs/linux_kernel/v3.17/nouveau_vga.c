static unsigned int
F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = & F_2 ( V_1 ) -> V_4 ;
if ( V_4 -> V_5 . V_6 == V_7 &&
V_4 -> V_5 . V_8 >= 0x4c )
F_3 ( V_4 , 0x088060 , V_2 ) ;
else
if ( V_4 -> V_5 . V_8 >= 0x40 )
F_3 ( V_4 , 0x088054 , V_2 ) ;
else
F_3 ( V_4 , 0x001854 , V_2 ) ;
if ( V_2 )
return V_9 | V_10 |
V_11 | V_12 ;
else
return V_11 | V_12 ;
}
static void
F_4 ( struct V_13 * V_14 ,
enum V_15 V_2 )
{
struct V_16 * V_17 = F_5 ( V_14 ) ;
if ( ( F_6 () || F_7 () ) && V_2 == V_18 )
return;
if ( V_2 == V_19 ) {
F_8 ( V_20 L_1 ) ;
V_17 -> V_21 = V_22 ;
F_9 ( & V_14 -> V_17 ) ;
F_10 ( V_17 ) ;
V_17 -> V_21 = V_23 ;
} else {
F_8 ( V_20 L_2 ) ;
V_17 -> V_21 = V_22 ;
F_11 ( V_17 ) ;
F_12 () ;
F_13 ( & V_14 -> V_17 ) ;
V_17 -> V_21 = V_24 ;
}
}
static void
F_14 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = F_5 ( V_14 ) ;
F_15 ( V_17 ) ;
}
static bool
F_16 ( struct V_13 * V_14 )
{
struct V_16 * V_17 = F_5 ( V_14 ) ;
return V_17 -> V_25 == 0 ;
}
void
F_17 ( struct F_2 * V_26 )
{
struct V_16 * V_17 = V_26 -> V_17 ;
bool V_27 = false ;
if ( ! V_17 -> V_14 )
return;
F_18 ( V_17 -> V_14 , V_17 , NULL , F_1 ) ;
if ( V_28 == 1 )
V_27 = true ;
if ( ( V_28 == - 1 ) && ( F_6 () || F_7 () ) )
V_27 = true ;
F_19 ( V_17 -> V_14 , & V_29 , V_27 ) ;
if ( V_27 && F_7 () && ! F_6 () )
F_20 ( V_26 -> V_17 -> V_17 , & V_26 -> V_30 ) ;
}
void
F_21 ( struct F_2 * V_26 )
{
struct V_16 * V_17 = V_26 -> V_17 ;
bool V_27 = false ;
if ( V_28 == 1 )
V_27 = true ;
if ( ( V_28 == - 1 ) && ( F_6 () || F_7 () ) )
V_27 = true ;
F_22 ( V_17 -> V_14 ) ;
if ( V_27 && F_7 () && ! F_6 () )
F_23 ( V_26 -> V_17 -> V_17 ) ;
F_18 ( V_17 -> V_14 , NULL , NULL , NULL ) ;
}
void
F_24 ( struct V_16 * V_17 )
{
F_25 () ;
}

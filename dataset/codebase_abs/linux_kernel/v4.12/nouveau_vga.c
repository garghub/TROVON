static unsigned int
F_1 ( void * V_1 , bool V_2 )
{
struct V_3 * V_4 = V_3 ( V_1 ) ;
struct V_5 * V_6 = & V_4 -> V_7 . V_6 . V_8 ;
if ( V_4 -> V_7 . V_6 . V_9 . V_10 == V_11 &&
V_4 -> V_7 . V_6 . V_9 . V_12 >= 0x4c )
F_2 ( V_6 , 0x088060 , V_2 ) ;
else
if ( V_4 -> V_7 . V_6 . V_9 . V_12 >= 0x40 )
F_2 ( V_6 , 0x088054 , V_2 ) ;
else
F_2 ( V_6 , 0x001854 , V_2 ) ;
if ( V_2 )
return V_13 | V_14 |
V_15 | V_16 ;
else
return V_15 | V_16 ;
}
static void
F_3 ( struct V_17 * V_18 ,
enum V_19 V_2 )
{
struct V_20 * V_21 = F_4 ( V_18 ) ;
if ( ( F_5 () || F_6 () ) && V_2 == V_22 )
return;
if ( V_2 == V_23 ) {
F_7 ( L_1 ) ;
V_21 -> V_24 = V_25 ;
F_8 ( & V_18 -> V_21 ) ;
F_9 ( V_21 ) ;
V_21 -> V_24 = V_26 ;
} else {
F_7 ( L_2 ) ;
V_21 -> V_24 = V_25 ;
F_10 ( V_21 ) ;
F_11 () ;
F_12 ( & V_18 -> V_21 ) ;
V_21 -> V_24 = V_27 ;
}
}
static void
F_13 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = F_4 ( V_18 ) ;
F_14 ( V_21 ) ;
}
static bool
F_15 ( struct V_17 * V_18 )
{
struct V_20 * V_21 = F_4 ( V_18 ) ;
return V_21 -> V_28 == 0 ;
}
void
F_16 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_21 ;
bool V_29 = F_17 () ;
if ( ! V_21 -> V_18 )
return;
F_18 ( V_21 -> V_18 , V_21 , NULL , F_1 ) ;
if ( F_19 ( V_21 -> V_18 ) )
return;
F_20 ( V_21 -> V_18 , & V_30 , V_29 ) ;
if ( V_29 && F_6 () && ! F_5 () )
F_21 ( V_4 -> V_21 -> V_21 , & V_4 -> V_31 ) ;
}
void
F_22 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = V_4 -> V_21 ;
bool V_29 = F_17 () ;
F_18 ( V_21 -> V_18 , NULL , NULL , NULL ) ;
if ( F_19 ( V_21 -> V_18 ) )
return;
F_23 ( V_21 -> V_18 ) ;
if ( V_29 && F_6 () && ! F_5 () )
F_24 ( V_4 -> V_21 -> V_21 ) ;
}
void
F_25 ( struct V_20 * V_21 )
{
F_26 () ;
}

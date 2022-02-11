bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & ( V_4 | V_5 ) )
return false ;
if ( V_6 || F_2 ( V_2 ) )
return true ;
if ( V_7 && ! ( V_2 -> V_3 & V_8 ) )
return true ;
return false ;
}
bool F_3 ( bool V_9 )
{
bool V_10 = false ;
long V_11 = V_12 -> V_13 ;
F_4 ( L_1 , V_12 -> V_14 ) ;
for (; ; ) {
F_5 ( V_15 ) ;
F_6 ( & V_16 ) ;
V_12 -> V_3 |= V_17 ;
if ( ! F_7 ( V_12 ) ||
( V_9 && F_8 () ) )
V_12 -> V_3 &= ~ V_17 ;
F_9 ( & V_16 ) ;
if ( ! ( V_12 -> V_3 & V_17 ) )
break;
V_10 = true ;
F_10 () ;
}
F_4 ( L_2 , V_12 -> V_14 ) ;
F_5 ( V_11 ) ;
return V_10 ;
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( F_12 ( V_2 , & V_3 ) ) {
F_13 ( V_2 , 0 ) ;
F_14 ( V_2 , & V_3 ) ;
}
}
bool F_15 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( F_16 ( V_2 ) )
return false ;
F_17 ( & V_16 , V_3 ) ;
if ( ! F_7 ( V_2 ) || F_18 ( V_2 ) ) {
F_19 ( & V_16 , V_3 ) ;
return false ;
}
if ( ! ( V_2 -> V_3 & V_8 ) )
F_11 ( V_2 ) ;
else
F_20 ( V_2 , V_18 ) ;
F_19 ( & V_16 , V_3 ) ;
return true ;
}
void F_21 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_17 ( & V_16 , V_3 ) ;
if ( F_18 ( V_2 ) )
F_22 ( V_2 ) ;
F_19 ( & V_16 , V_3 ) ;
}
bool F_23 ( void )
{
F_24 () ;
F_6 ( & V_16 ) ;
V_12 -> V_3 &= ~ V_4 ;
F_9 ( & V_16 ) ;
return F_25 () ;
}

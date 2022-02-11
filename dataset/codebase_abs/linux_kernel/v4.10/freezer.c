bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & ( V_4 | V_5 ) )
return false ;
if ( F_2 ( V_2 , V_6 ) )
return false ;
if ( V_7 || F_3 ( V_2 ) )
return true ;
if ( V_8 && ! ( V_2 -> V_3 & V_9 ) )
return true ;
return false ;
}
bool F_4 ( bool V_10 )
{
bool V_11 = false ;
long V_12 = V_13 -> V_14 ;
F_5 ( L_1 , V_13 -> V_15 ) ;
for (; ; ) {
F_6 ( V_16 ) ;
F_7 ( & V_17 ) ;
V_13 -> V_3 |= V_18 ;
if ( ! F_8 ( V_13 ) ||
( V_10 && F_9 () ) )
V_13 -> V_3 &= ~ V_18 ;
F_10 ( & V_17 ) ;
if ( ! ( V_13 -> V_3 & V_18 ) )
break;
V_11 = true ;
F_11 () ;
}
F_5 ( L_2 , V_13 -> V_15 ) ;
F_6 ( V_12 ) ;
return V_11 ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( F_13 ( V_2 , & V_3 ) ) {
F_14 ( V_2 , 0 ) ;
F_15 ( V_2 , & V_3 ) ;
}
}
bool F_16 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( F_17 ( V_2 ) )
return false ;
F_18 ( & V_17 , V_3 ) ;
if ( ! F_8 ( V_2 ) || F_19 ( V_2 ) ) {
F_20 ( & V_17 , V_3 ) ;
return false ;
}
if ( ! ( V_2 -> V_3 & V_9 ) )
F_12 ( V_2 ) ;
else
F_21 ( V_2 , V_19 ) ;
F_20 ( & V_17 , V_3 ) ;
return true ;
}
void F_22 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_18 ( & V_17 , V_3 ) ;
if ( F_19 ( V_2 ) )
F_23 ( V_2 ) ;
F_20 ( & V_17 , V_3 ) ;
}
bool F_24 ( void )
{
F_25 () ;
F_7 ( & V_17 ) ;
V_13 -> V_3 &= ~ V_4 ;
F_10 ( & V_17 ) ;
return F_26 () ;
}

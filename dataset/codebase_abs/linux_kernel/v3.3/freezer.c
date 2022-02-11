bool F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 & V_4 )
return false ;
if ( V_5 || F_2 ( V_2 ) )
return true ;
if ( V_6 && ! ( V_2 -> V_3 & V_7 ) )
return true ;
return false ;
}
bool F_3 ( bool V_8 )
{
bool V_9 = false ;
long V_10 = V_11 -> V_12 ;
F_4 ( L_1 , V_11 -> V_13 ) ;
for (; ; ) {
F_5 ( V_14 ) ;
F_6 ( & V_15 ) ;
V_11 -> V_3 |= V_16 ;
if ( ! F_7 ( V_11 ) ||
( V_8 && F_8 () ) )
V_11 -> V_3 &= ~ V_16 ;
F_9 ( & V_15 ) ;
if ( ! ( V_11 -> V_3 & V_16 ) )
break;
V_9 = true ;
F_10 () ;
}
F_4 ( L_2 , V_11 -> V_13 ) ;
F_5 ( V_10 ) ;
return V_9 ;
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
F_16 ( & V_15 , V_3 ) ;
if ( ! F_7 ( V_2 ) || F_17 ( V_2 ) ) {
F_18 ( & V_15 , V_3 ) ;
return false ;
}
if ( ! ( V_2 -> V_3 & V_7 ) ) {
F_11 ( V_2 ) ;
} else {
F_19 ( V_2 , V_17 ) ;
}
F_18 ( & V_15 , V_3 ) ;
return true ;
}
void F_20 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
F_16 ( & V_15 , V_3 ) ;
if ( F_17 ( V_2 ) )
F_21 ( V_2 ) ;
F_18 ( & V_15 , V_3 ) ;
}
bool F_22 ( void )
{
F_23 () ;
F_6 ( & V_15 ) ;
V_11 -> V_3 &= ~ V_4 ;
F_9 ( & V_15 ) ;
return F_24 () ;
}

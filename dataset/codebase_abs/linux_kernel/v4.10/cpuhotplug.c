static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_7 -> V_6 ;
struct V_8 * V_9 ;
bool V_10 = false ;
if ( F_3 ( V_4 ) ||
! F_4 ( F_5 () , V_6 ) )
return false ;
if ( F_6 ( V_6 , V_11 ) >= V_12 ) {
V_6 = V_11 ;
V_10 = true ;
}
V_9 = F_7 ( V_4 ) ;
if ( ! V_9 -> V_13 ) {
F_8 ( L_1 , V_4 -> V_14 ) ;
} else {
int V_15 = F_9 ( V_4 , V_6 , false ) ;
if ( V_15 )
F_10 ( L_2 ,
V_4 -> V_14 , V_15 ) ;
}
return V_10 ;
}
void F_11 ( void )
{
unsigned int V_14 ;
struct V_1 * V_2 ;
unsigned long V_16 ;
F_12 ( V_16 ) ;
F_13 (irq) {
bool V_17 ;
V_2 = F_14 ( V_14 ) ;
F_15 ( & V_2 -> V_18 ) ;
V_17 = F_1 ( V_2 ) ;
F_16 ( & V_2 -> V_18 ) ;
if ( V_17 )
F_10 ( L_3 ,
V_14 , F_5 () ) ;
}
F_17 ( V_16 ) ;
}

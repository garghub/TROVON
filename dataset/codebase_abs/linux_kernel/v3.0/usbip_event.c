static int F_1 ( struct V_1 * V_2 )
{
F_2 ( L_1 ) ;
while ( F_3 ( V_2 ) ) {
F_2 ( L_2 , V_2 -> V_3 ) ;
if ( V_2 -> V_3 & V_4 ) {
V_2 -> V_5 . V_6 ( V_2 ) ;
V_2 -> V_3 &= ~ V_4 ;
}
if ( V_2 -> V_3 & V_7 ) {
V_2 -> V_5 . V_8 ( V_2 ) ;
V_2 -> V_3 &= ~ V_7 ;
}
if ( V_2 -> V_3 & V_9 ) {
V_2 -> V_5 . V_10 ( V_2 ) ;
V_2 -> V_3 &= ~ V_9 ;
}
if ( V_2 -> V_3 & V_11 )
return - 1 ;
}
return 0 ;
}
static int F_4 ( void * V_12 )
{
struct V_1 * V_2 = V_12 ;
while ( ! F_5 () ) {
F_6 ( V_2 -> V_13 ,
F_3 ( V_2 ) ||
F_5 () ) ;
F_2 ( L_3 ) ;
if ( F_1 ( V_2 ) < 0 )
break;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_13 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_14 = F_9 ( F_4 , V_2 , L_4 ) ;
if ( F_10 ( V_2 -> V_14 ) ) {
F_11 ( L_5 ) ;
return F_12 ( V_2 -> V_14 ) ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_14 == V_15 )
return;
F_14 ( V_2 -> V_14 ) ;
F_2 ( L_6 ) ;
}
void F_15 ( struct V_1 * V_2 , unsigned long V_3 )
{
F_16 ( & V_2 -> V_16 ) ;
V_2 -> V_3 |= V_3 ;
F_17 ( & V_2 -> V_13 ) ;
F_18 ( & V_2 -> V_16 ) ;
}
int F_3 ( struct V_1 * V_2 )
{
int V_17 = 0 ;
F_16 ( & V_2 -> V_16 ) ;
if ( V_2 -> V_3 != 0 )
V_17 = 1 ;
F_18 ( & V_2 -> V_16 ) ;
return V_17 ;
}

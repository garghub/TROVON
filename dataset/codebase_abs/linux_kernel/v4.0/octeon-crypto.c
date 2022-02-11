unsigned long F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
F_2 ( V_4 ) ;
V_3 = F_3 () ;
F_4 ( V_3 | V_5 ) ;
if ( F_5 ( V_6 ) & V_5 ) {
F_6 ( & ( V_6 -> V_7 . V_8 ) ) ;
F_5 ( V_6 ) &= ~ V_5 ;
V_3 &= ~ V_5 ;
} else if ( V_3 & V_5 ) {
F_6 ( V_2 ) ;
}
F_7 ( V_4 ) ;
return V_3 & V_5 ;
}
void F_8 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
unsigned long V_4 ;
F_2 ( V_4 ) ;
if ( V_9 & V_5 )
F_9 ( V_2 ) ;
else
F_4 ( F_3 () & ~ V_5 ) ;
F_7 ( V_4 ) ;
}

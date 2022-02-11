unsigned long F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
F_2 () ;
F_3 ( V_4 ) ;
V_3 = F_4 () ;
F_5 ( V_3 | V_5 ) ;
if ( F_6 ( V_6 ) & V_5 ) {
F_7 ( & ( V_6 -> V_7 . V_8 ) ) ;
F_6 ( V_6 ) &= ~ V_5 ;
V_3 &= ~ V_5 ;
} else if ( V_3 & V_5 ) {
F_7 ( V_2 ) ;
}
F_8 ( V_4 ) ;
return V_3 & V_5 ;
}
void F_9 ( struct V_1 * V_2 ,
unsigned long V_9 )
{
unsigned long V_4 ;
F_3 ( V_4 ) ;
if ( V_9 & V_5 )
F_10 ( V_2 ) ;
else
F_5 ( F_4 () & ~ V_5 ) ;
F_8 ( V_4 ) ;
F_11 () ;
}

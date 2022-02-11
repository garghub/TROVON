int F_1 ( const struct V_1 * V_2 )
{
unsigned int signal = V_2 -> V_3 , V_4 ;
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
if ( V_7 [ signal ] . V_8 &&
( V_7 [ signal ] . V_4 != V_2 -> V_9 ) ) {
F_3 ( & V_6 , V_5 ) ;
return - V_10 ;
}
if ( ! V_7 [ signal ] . V_8 ) {
V_4 = F_4 ( V_11 ) ;
V_4 &= ~ ( 0x3 << ( signal * 2 ) ) ;
V_4 |= V_2 -> V_9 << ( signal * 2 ) ;
F_5 ( V_4 , V_11 ) ;
}
V_7 [ signal ] . V_8 ++ ;
V_7 [ signal ] . V_4 = V_2 -> V_9 ;
F_3 ( & V_6 , V_5 ) ;
return signal ;
}
void F_6 ( const struct V_1 * V_2 , int signal )
{
unsigned long V_5 ;
F_2 ( & V_6 , V_5 ) ;
if ( ! V_7 [ signal ] . V_8 )
F_7 () ;
V_7 [ signal ] . V_8 -- ;
F_3 ( & V_6 , V_5 ) ;
}

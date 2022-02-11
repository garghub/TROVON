int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int signal = V_4 -> V_5 , V_6 ;
unsigned long V_7 ;
F_2 ( & V_8 , V_7 ) ;
if ( V_9 [ signal ] . V_10 &&
( V_9 [ signal ] . V_6 != V_4 -> V_11 ) ) {
F_3 ( & V_8 , V_7 ) ;
return - V_12 ;
}
if ( ! V_9 [ signal ] . V_10 ) {
V_6 = F_4 ( V_13 ) ;
V_6 &= ~ ( 0x3 << ( signal * 2 ) ) ;
V_6 |= V_4 -> V_11 << ( signal * 2 ) ;
F_5 ( V_6 , V_13 ) ;
}
V_9 [ signal ] . V_10 ++ ;
V_9 [ signal ] . V_6 = V_4 -> V_11 ;
F_3 ( & V_8 , V_7 ) ;
return signal ;
}
void F_6 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_4 ;
unsigned long V_7 ;
F_2 ( & V_8 , V_7 ) ;
if ( ! V_9 [ V_4 -> V_5 ] . V_10 )
F_7 () ;
V_9 [ V_4 -> V_5 ] . V_10 -- ;
F_3 ( & V_8 , V_7 ) ;
}

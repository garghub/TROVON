int F_1 ( struct V_1 * V_2 )
{
unsigned char V_3 , V_4 ;
unsigned long V_5 ;
unsigned int V_6 ;
struct V_7 * V_8 =
F_2 ( V_2 , struct V_7 , V_2 ) ;
F_3 ( & V_8 -> V_2 . V_9 , V_5 ) ;
V_6 = V_2 -> V_10 ( V_2 , V_11 ) ;
if ( V_6 & V_12 ) {
F_4 ( & V_8 -> V_2 . V_9 , V_5 ) ;
return 0 ;
}
if ( F_5 ( V_8 -> V_13 & V_14 ) ) {
V_8 -> V_13 &= ~ V_14 ;
V_2 -> V_10 ( V_2 , V_15 ) ;
F_4 ( & V_8 -> V_2 . V_9 , V_5 ) ;
return 1 ;
}
V_3 = V_4 = V_8 -> V_2 . V_10 ( & V_8 -> V_2 , V_16 ) ;
if ( V_3 & ( V_17 | V_14 ) )
V_3 = F_6 ( V_8 , V_3 ) ;
F_7 ( V_8 ) ;
if ( V_3 & V_18 )
F_8 ( V_8 ) ;
V_8 -> V_13 = V_4 ;
F_4 ( & V_8 -> V_2 . V_9 , V_5 ) ;
return 1 ;
}

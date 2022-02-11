int F_1 ( struct V_1 * V_2 , const char * V_3 )
{
unsigned long V_4 ;
int V_5 ;
if ( ! V_2 -> V_6 )
return 1 ;
if ( ! F_2 ( & V_2 -> V_7 , V_4 ) )
return 0 ;
if ( ! V_2 -> V_8 )
V_2 -> V_8 = V_9 ;
if ( F_3 ( V_2 -> V_8 + V_2 -> V_6 ) ) {
if ( V_2 -> V_10 ) {
if ( ! ( V_2 -> V_4 & V_11 ) ) {
F_4 ( L_1 , V_3 , V_2 -> V_10 ) ;
V_2 -> V_10 = 0 ;
}
}
V_2 -> V_8 = V_9 ;
V_2 -> V_12 = 0 ;
}
if ( V_2 -> V_13 && V_2 -> V_13 > V_2 -> V_12 ) {
V_2 -> V_12 ++ ;
V_5 = 1 ;
} else {
V_2 -> V_10 ++ ;
V_5 = 0 ;
}
F_5 ( & V_2 -> V_7 , V_4 ) ;
return V_5 ;
}

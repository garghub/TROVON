struct V_1 * F_1 ( const char * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( strcmp ( V_4 [ V_3 ] -> V_5 . V_2 , V_2 ) == 0 )
break;
if ( V_3 < F_2 ( V_4 ) )
return V_4 [ V_3 ] ;
F_3 ( L_1 , V_2 ) ;
return NULL ;
}
int F_4 ( struct V_6 * V_7 , unsigned long V_8 )
{
T_1 V_9 ;
V_7 -> V_7 . V_10 = F_5 ( & V_7 -> V_11 -> V_11 , V_8 ,
& V_9 , V_12 ) ;
if ( ! V_7 -> V_7 . V_10 ) {
F_3 ( L_2 ) ;
return - V_13 ;
}
V_7 -> V_7 . V_14 . V_15 = V_9 ;
V_7 -> V_7 . V_14 . V_16 = V_8 ;
return 0 ;
}
int F_6 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
return F_7 ( & V_7 -> V_11 -> V_11 , V_18 ,
V_7 -> V_7 . V_10 ,
V_7 -> V_7 . V_14 . V_15 ,
V_7 -> V_7 . V_14 . V_16 ) ;
}
void F_8 ( struct V_6 * V_7 )
{
F_9 ( & V_7 -> V_11 -> V_11 , V_7 -> V_7 . V_14 . V_16 ,
V_7 -> V_7 . V_10 , V_7 -> V_7 . V_14 . V_15 ) ;
}

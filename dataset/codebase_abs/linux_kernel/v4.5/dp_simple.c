union V_1 F_1 ( union V_1 V_2 )
{
union V_1 V_3 ;
if ( V_4 . V_5 ) {
V_3 = V_2 ;
F_2 ( V_3 ) = ! F_2 ( V_2 ) ;
} else {
unsigned int V_6 ;
V_6 = V_4 . V_7 ;
V_4 . V_7 = V_8 ;
V_3 = F_3 ( F_4 ( 0 ) , V_2 ) ;
V_4 . V_7 = V_6 ;
}
return V_3 ;
}
union V_1 F_5 ( union V_1 V_2 )
{
union V_1 V_3 ;
if ( V_4 . V_5 ) {
V_3 = V_2 ;
F_2 ( V_3 ) = 0 ;
} else {
unsigned int V_6 ;
V_6 = V_4 . V_7 ;
V_4 . V_7 = V_8 ;
if ( F_2 ( V_2 ) )
V_3 = F_3 ( F_4 ( 0 ) , V_2 ) ;
else
V_3 = F_6 ( F_4 ( 0 ) , V_2 ) ;
V_4 . V_7 = V_6 ;
}
return V_3 ;
}

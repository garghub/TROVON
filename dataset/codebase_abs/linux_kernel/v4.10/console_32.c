static int F_1 ( const char * V_1 )
{
unsigned long V_2 ;
int V_3 = - 1 ;
F_2 ( & V_4 , V_2 ) ;
switch( V_5 ) {
case V_6 :
if ( ( * ( V_7 -> V_8 ) ) ( * V_1 ) )
V_3 = 1 ;
break;
case V_9 :
case V_10 :
if ( ( * ( V_7 -> V_11 ) . V_12 ) ( * V_7 -> V_13 . V_14 ,
V_1 , 0x1 ) == 1 )
V_3 = 1 ;
break;
default:
break;
}
F_3 () ;
F_4 ( & V_4 , V_2 ) ;
return V_3 ;
}
void F_5 ( const char * V_1 , int V_15 )
{
while ( V_15 ) {
int V_16 = F_1 ( V_1 ) ;
if ( V_16 < 0 )
continue;
V_15 -- ;
V_1 ++ ;
}
}

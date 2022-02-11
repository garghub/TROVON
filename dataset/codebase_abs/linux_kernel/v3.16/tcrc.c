unsigned long F_1 ( unsigned char * V_1 , unsigned int V_2 , unsigned long V_3 )
{
unsigned long V_4 ;
V_4 = V_3 ;
while ( V_2 -- ) {
V_4 = V_5 [ ( unsigned char ) ( ( V_4 ^ ( * V_1 ) ) & 0xFF ) ] ^ ( V_4 >> 8 ) ;
V_1 ++ ;
}
return V_4 ;
}
unsigned long F_2 ( unsigned char * V_1 , unsigned int V_2 )
{
return ~ F_1 ( V_1 , V_2 , 0xFFFFFFFFL ) ;
}
unsigned long F_3 ( unsigned char * V_1 , unsigned int V_2 , unsigned long V_6 )
{
return F_1 ( V_1 , V_2 , V_6 ) ;
}

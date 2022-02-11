void F_1 ( unsigned long V_1 , T_1 V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_1 ) ;
F_2 ( V_3 , V_1 + 1 ) ;
}
T_1 F_3 ( unsigned long V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_4 ( V_1 + 1 ) ;
}
void F_5 ( unsigned long V_1 , T_1 V_2 ,
unsigned V_4 , unsigned V_5 )
{
T_1 V_6 ;
V_6 = F_3 ( V_1 , V_2 ) ;
V_6 = ( V_6 & V_4 ) | V_5 ;
F_1 ( V_1 , V_2 , V_6 ) ;
}
void F_6 ( unsigned long V_1 , T_1 V_2 , unsigned V_4 )
{
T_1 V_6 ;
V_6 = F_3 ( V_1 , V_2 ) ;
V_6 &= V_4 ;
F_1 ( V_1 , V_2 , V_6 ) ;
}
void F_7 ( unsigned long V_1 , T_1 V_2 , unsigned V_5 )
{
T_1 V_6 ;
V_6 = F_3 ( V_1 , V_2 ) ;
V_6 |= V_5 ;
F_1 ( V_1 , V_2 , V_6 ) ;
}

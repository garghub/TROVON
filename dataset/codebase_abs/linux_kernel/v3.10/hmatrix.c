static inline void F_1 ( unsigned long V_1 , T_1 V_2 )
{
F_2 ( V_2 , ( void V_3 V_4 * ) ( V_5 + V_1 ) ) ;
}
static inline T_1 F_3 ( unsigned long V_1 )
{
return F_4 ( ( void V_3 V_4 * ) ( V_5 + V_1 ) ) ;
}
void F_5 ( unsigned long V_1 , T_1 V_2 )
{
F_6 ( & V_6 ) ;
F_1 ( V_1 , V_2 ) ;
F_3 ( V_1 ) ;
F_7 ( & V_6 ) ;
}
T_1 F_8 ( unsigned long V_1 )
{
T_1 V_2 ;
F_6 ( & V_6 ) ;
V_2 = F_3 ( V_1 ) ;
F_7 ( & V_6 ) ;
return V_2 ;
}
void F_9 ( unsigned int V_7 , T_1 V_8 )
{
T_1 V_2 ;
F_6 ( & V_6 ) ;
V_2 = F_3 ( F_10 ( V_7 ) ) ;
V_2 |= V_8 ;
F_1 ( F_10 ( V_7 ) , V_2 ) ;
F_3 ( F_10 ( V_7 ) ) ;
F_7 ( & V_6 ) ;
}
void F_11 ( unsigned int V_7 , T_1 V_8 )
{
T_1 V_2 ;
F_6 ( & V_6 ) ;
V_2 = F_3 ( F_10 ( V_7 ) ) ;
V_2 &= ~ V_8 ;
F_1 ( F_10 ( V_7 ) , V_2 ) ;
F_3 ( F_10 ( V_7 ) ) ;
F_7 ( & V_6 ) ;
}

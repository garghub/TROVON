static int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + F_2 ( V_5 ) ;
T_1 V_6 ;
while ( F_3 ( V_3 ) ) {
F_4 ( V_2 , V_7 , & V_6 ) ;
if ( ! ( V_6 & ( V_8 | V_9 ) ) )
return 0 ;
F_5 ( 50 , 100 ) ;
}
F_6 ( L_1 ) ;
return - V_10 ;
}
static void F_7 ( struct V_1 * V_2 , T_2 V_11 , T_2 V_6 )
{
F_8 ( V_2 , V_12 , V_11 ) ;
F_8 ( V_2 , V_13 , V_6 & 0xff ) ;
F_8 ( V_2 , V_13 + 1 , ( V_6 & 0xff00 ) >> 8 ) ;
F_8 ( V_2 , V_7 , 0x8c ) ;
F_1 ( V_2 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 , T_2 V_11 )
{
T_1 V_14 = 0 ;
T_1 V_15 = 0 ;
F_8 ( V_2 , V_12 , V_11 ) ;
F_8 ( V_2 , V_7 , 0x8b ) ;
if ( F_1 ( V_2 ) < 0 )
return 0 ;
F_4 ( V_2 , V_13 , & V_14 ) ;
F_4 ( V_2 , V_13 + 1 , & V_15 ) ;
return ( V_15 << 8 ) | V_14 ;
}
void F_10 ( struct V_1 * V_2 )
{
T_2 V_6 ;
V_6 = F_9 ( V_2 , 0x12 ) ;
F_11 ( L_2 , V_6 ) ;
V_6 = F_9 ( V_2 , 0x10 ) ;
F_11 ( L_3 , V_6 ) ;
V_6 = F_9 ( V_2 , 0x0e ) ;
F_11 ( L_4 , V_6 ) ;
V_6 = F_9 ( V_2 , 0x16 ) ;
F_11 ( L_5 , V_6 ) ;
V_6 = F_9 ( V_2 , 0x1a ) ;
F_11 ( L_6 , V_6 ) ;
V_6 = F_9 ( V_2 , 0x02 ) ;
F_11 ( L_7 , V_6 ) ;
V_6 = F_9 ( V_2 , 0x1c ) ;
F_11 ( L_8 , V_6 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_6 ;
F_4 ( V_2 , V_16 , & V_6 ) ;
return ! ( V_6 & V_17 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
T_1 V_6 ;
F_4 ( V_2 , V_16 , & V_6 ) ;
return ! ( V_6 & V_18 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( ! F_12 ( V_2 ) ) {
F_15 ( L_9 ) ;
return;
}
if ( ! F_13 ( V_2 ) ) {
F_15 ( L_10 ) ;
return;
}
F_8 ( V_2 , V_7 , 0x94 ) ;
F_8 ( V_2 , V_7 , 0x8c ) ;
F_8 ( V_2 , V_19 + 2 , 0x01 ) ;
F_8 ( V_2 , V_19 + 3 , 0x00 ) ;
F_7 ( V_2 , 0x12 , 0x8808 ) ;
F_7 ( V_2 , 0x10 , 0x0808 ) ;
F_7 ( V_2 , 0x0e , 0x0008 ) ;
F_7 ( V_2 , 0x16 , 0x0808 ) ;
F_7 ( V_2 , 0x1a , 0x0404 ) ;
F_7 ( V_2 , 0x02 , 0x0000 ) ;
F_7 ( V_2 , 0x1c , 0x0808 ) ;
#ifdef F_16
F_10 ( V_2 ) ;
#endif
}

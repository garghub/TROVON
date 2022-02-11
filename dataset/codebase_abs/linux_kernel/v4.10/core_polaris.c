static int
F_1 ( struct V_1 * V_2 , unsigned int V_3 , int V_4 ,
unsigned long * V_5 , T_1 * V_6 )
{
T_1 V_7 = V_2 -> V_8 ;
* V_6 = ( V_7 == 0 ) ? 0 : 1 ;
* V_5 = ( V_7 << 16 ) | ( V_3 << 8 ) | ( V_4 ) |
V_9 ;
F_2 ( ( L_1
L_2
V_7 , V_3 , V_4 , * V_5 ) ) ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_7 , unsigned int V_10 , int V_4 ,
int V_11 , T_2 * V_12 )
{
unsigned long V_13 ;
unsigned char V_6 ;
if ( F_1 ( V_7 , V_10 , V_4 , & V_13 , & V_6 ) )
return V_14 ;
switch ( V_11 ) {
case 1 :
* V_12 = F_4 ( * ( V_15 ) V_13 ) ;
break;
case 2 :
* V_12 = F_5 ( * ( V_16 ) V_13 ) ;
break;
case 4 :
* V_12 = * ( V_17 ) V_13 ;
break;
}
return V_18 ;
}
static int
F_6 ( struct V_1 * V_7 , unsigned int V_10 , int V_4 ,
int V_11 , T_2 V_12 )
{
unsigned long V_13 ;
unsigned char V_6 ;
if ( F_1 ( V_7 , V_10 , V_4 , & V_13 , & V_6 ) )
return V_14 ;
switch ( V_11 ) {
case 1 :
F_7 ( V_12 , * ( V_15 ) V_13 ) ;
F_8 () ;
F_4 ( * ( V_15 ) V_13 ) ;
break;
case 2 :
F_9 ( V_12 , * ( V_16 ) V_13 ) ;
F_8 () ;
F_5 ( * ( V_16 ) V_13 ) ;
break;
case 4 :
* ( V_17 ) V_13 = V_12 ;
F_8 () ;
* ( V_17 ) V_13 ;
break;
}
return V_18 ;
}
void T_3
F_10 ( void )
{
struct V_19 * V_20 ;
#if 0
printk("polaris_init_arch(): trusting firmware for setup\n");
#endif
V_21 = V_20 = F_11 () ;
V_20 -> V_22 = & V_23 ;
V_20 -> V_24 = & V_25 ;
V_20 -> V_26 = 0 ;
V_20 -> V_27 = 0 ;
V_20 -> V_28 = V_29 - V_30 ;
V_20 -> V_31 = 0 ;
V_20 -> V_32 = V_33 - V_30 ;
V_20 -> V_34 = V_20 -> V_35 = NULL ;
V_36 = 0x80000000 ;
V_37 = 0x80000000 ;
}
static inline void
F_12 ( void )
{
* ( V_16 ) V_38 ;
* ( V_16 ) V_38 = 0x7800 ;
F_8 () ;
* ( V_16 ) V_38 ;
}
void
F_13 ( unsigned long V_39 , unsigned long V_40 )
{
F_8 () ;
F_8 () ;
F_14 () ;
F_12 () ;
F_15 ( 0x7 ) ;
F_8 () ;
F_16 ( V_39 , V_40 , L_3 ,
F_17 ( 0 ) ) ;
}

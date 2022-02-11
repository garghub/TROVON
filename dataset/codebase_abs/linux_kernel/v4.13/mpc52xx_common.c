void T_1
F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 T_2 * V_4 ;
V_2 = F_2 ( NULL , V_5 ) ;
V_4 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
if ( ! V_4 ) {
F_5 (KERN_ERR __FILE__ L_1
L_2
L_3 ) ;
return;
}
F_6 ( & V_4 -> V_6 , 0xff ) ;
F_6 ( & V_4 -> V_7 , 0x11111111 ) ;
if ( ( F_7 ( V_8 ) & V_9 ) == V_10 )
F_6 ( & V_4 -> V_11 , F_8 ( & V_4 -> V_11 ) | V_12 ) ;
F_9 ( V_4 ) ;
}
void T_1 F_10 ( void )
{
if ( F_11 ( NULL , V_13 , NULL , NULL ) )
F_12 ( __FILE__ L_4 ) ;
}
void T_1
F_13 ( void )
{
struct V_1 * V_2 ;
F_14 (np, mpc52xx_gpt_ids) {
if ( F_15 ( V_2 , L_5 , NULL ) ||
F_15 ( V_2 , L_6 , NULL ) ) {
V_14 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
break;
}
}
V_2 = F_2 ( NULL , V_15 ) ;
V_16 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
V_2 = F_2 ( NULL , V_17 ) ;
V_18 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
V_2 = F_2 ( NULL , V_19 ) ;
V_20 = F_3 ( V_2 , 0 ) ;
F_4 ( V_2 ) ;
}
int F_16 ( int V_21 , int V_22 )
{
unsigned long V_23 ;
T_3 T_2 * V_24 ;
T_4 V_25 ;
T_4 V_26 ;
T_4 V_27 ;
if ( ! V_16 )
return - V_28 ;
V_27 = 0x8000 | ( V_22 & 0x1FF ) ;
switch ( V_21 ) {
case 1 : V_24 = & V_16 -> V_29 ; V_26 = 0x20 ; break;
case 2 : V_24 = & V_16 -> V_30 ; V_26 = 0x40 ; break;
case 3 : V_24 = & V_16 -> V_31 ; V_26 = 0x80 ; break;
case 6 : V_24 = & V_16 -> V_32 ; V_26 = 0x10 ; break;
default:
return - V_28 ;
}
F_17 ( & V_33 , V_23 ) ;
F_18 ( V_24 , V_27 ) ;
V_25 = F_8 ( & V_16 -> V_34 ) ;
F_6 ( & V_16 -> V_34 , V_25 | V_26 ) ;
F_19 ( & V_33 , V_23 ) ;
return 0 ;
}
unsigned int F_20 ( struct V_1 * V_35 )
{
T_4 V_25 ;
unsigned int V_36 ;
if ( ! V_16 )
return 0 ;
V_36 = F_21 ( V_35 ) ;
if ( ! V_36 )
return 0 ;
if ( F_22 ( & V_16 -> V_37 ) & 0x1 )
V_36 *= 2 ;
V_25 = F_8 ( & V_16 -> V_38 ) ;
if ( V_25 & ( 1 << 5 ) )
V_36 *= 8 ;
else
V_36 *= 4 ;
if ( V_25 & ( 1 << 6 ) )
V_36 /= 12 ;
else
V_36 /= 16 ;
return V_36 ;
}
void T_5 F_23 ( char * V_39 )
{
F_24 () ;
if ( V_14 ) {
F_6 ( & V_14 -> V_40 , 0x00000000 ) ;
F_6 ( & V_14 -> V_41 , 0x000000ff ) ;
F_6 ( & V_14 -> V_40 , 0x00009004 ) ;
} else
F_5 (KERN_ERR __FILE__ L_1
L_7
L_8 ) ;
while ( 1 ) ;
}
int F_25 ( int V_42 )
{
unsigned long V_23 ;
T_4 V_43 ;
T_4 V_44 ;
int V_45 ;
int V_46 ;
int V_47 ;
if ( ( ! V_18 ) || ( ! V_20 ) )
return - V_28 ;
switch ( V_42 ) {
case 0 :
V_46 = V_48 ;
V_47 = V_49 ;
V_45 = V_50 ;
V_43 = V_51 ;
break;
case 1 :
V_46 = V_52 ;
V_47 = V_53 ;
V_45 = V_54 ;
V_43 = V_55 ;
break;
default:
F_12 ( __FILE__ L_9
L_10 ) ;
return - V_28 ;
}
F_17 ( & V_56 , V_23 ) ;
V_44 = F_8 ( & V_18 -> V_57 ) ;
F_6 ( & V_18 -> V_57 , V_44 & ( ~ V_43 ) ) ;
F_26 ( & V_20 -> V_58 , V_46 ) ;
F_27 ( & V_18 -> V_59 , V_47 | V_45 ) ;
F_26 ( & V_20 -> V_60 , V_46 ) ;
F_27 ( & V_18 -> V_61 , V_47 | V_45 ) ;
F_28 ( & V_18 -> V_62 , V_47 | V_45 ) ;
F_29 ( & V_20 -> V_63 , V_46 ) ;
F_30 ( 1 ) ;
F_26 ( & V_20 -> V_63 , V_46 ) ;
F_31 ( 7 ) ;
F_6 ( & V_18 -> V_57 , V_44 ) ;
F_19 ( & V_56 , V_23 ) ;
return 0 ;
}

static int F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
return 1 ;
default:
return 0 ;
}
}
int F_2 ( T_2 V_3 , T_2 V_4 )
{
T_3 V_5 ;
F_3 ( & V_6 -> V_7 , F_4 ( & V_6 -> V_7 ) | ( 1 << V_3 ) ) ;
F_3 ( & V_6 -> V_8 , F_4 ( & V_6 -> V_8 ) & ~ ( 1 << V_3 ) ) ;
F_3 ( & V_6 -> V_9 , F_4 ( & V_6 -> V_9 ) | ( 1 << V_3 ) ) ;
V_5 = F_5 ( & V_6 -> V_10 ) ;
V_5 &= ~ ( 0x3 << ( V_3 * 2 ) ) ;
V_5 |= ( ! V_4 + 1 ) << ( V_3 * 2 ) ;
F_6 ( & V_6 -> V_10 , V_5 ) ;
F_3 ( & V_6 -> V_11 , 1 ) ;
return 0 ;
}
int F_7 ( void )
{
struct V_12 * V_13 ;
const struct V_14 V_15 [] = {
{ . V_16 = L_1 , } ,
{ . V_16 = L_2 , } ,
{ . type = L_3 , . V_16 = L_4 , } ,
{ . type = L_5 , . V_16 = L_4 , } ,
{}
} ;
struct V_17 V_18 ;
V_13 = F_8 ( NULL , V_15 ) ;
if ( F_9 ( V_13 , 0 , & V_18 ) ) {
F_10 ( L_6 ) ;
F_11 ( V_13 ) ;
return - V_19 ;
}
V_20 = F_12 ( V_18 . V_21 , 0xc000 ) ;
F_11 ( V_13 ) ;
if ( ! V_20 ) {
F_10 ( L_7 ) ;
return - V_19 ;
}
V_22 = V_20 + 0x100 ;
V_23 = V_20 + 0x200 ;
V_24 = V_20 + 0x500 ;
V_6 = V_20 + 0xc00 ;
V_25 = V_20 + 0x8000 ;
V_26 = 0x4000 ;
if ( V_27 . V_28 )
V_27 . V_28 ( V_20 ) ;
else {
F_13 ( V_29 L_8 ,
V_30 , __LINE__ ) ;
goto V_31;
}
return 0 ;
V_31:
F_14 ( V_20 ) ;
return - V_19 ;
}
int F_15 ( T_1 V_1 )
{
T_4 V_32 ;
T_4 V_33 , V_34 ;
T_4 V_35 ;
void T_5 * V_36 = ( void T_5 * ) V_37 + 0x500 ;
unsigned long V_38 = ( unsigned long ) V_36 + V_39 ;
char V_40 [ V_39 ] ;
V_35 = F_16 ( & V_24 -> V_41 ) ;
F_17 ( & V_24 -> V_41 , V_35 | 0x1ffff ) ;
F_18 ( V_42 , 0x7fffffff ) ;
memcpy ( V_43 , V_25 , V_26 ) ;
memcpy ( V_25 , V_44 , V_45 ) ;
F_3 ( & V_23 -> V_46 , 1 ) ;
F_3 ( & V_23 -> V_47 , 1 ) ;
F_3 ( & V_23 -> V_48 , 1 ) ;
V_32 = F_16 ( & V_23 -> V_32 ) ;
F_17 ( & V_23 -> V_32 , V_32 & 0x00088000 ) ;
V_33 = F_19 () ;
F_20 ( V_33 & ~ V_49 ) ;
V_34 = F_21 ( V_50 ) ;
F_18 ( V_50 , ( V_34 & ~ ( V_51 | V_52 | V_53 ) ) | V_54 ) ;
memcpy ( V_40 , V_36 , V_39 ) ;
memcpy ( V_36 , V_55 , V_39 ) ;
F_22 ( ( unsigned long ) V_36 , V_38 ) ;
F_23 ( V_25 , V_22 , V_23 , V_24 ) ;
memcpy ( V_36 , V_40 , V_39 ) ;
F_22 ( ( unsigned long ) V_36 , V_38 ) ;
F_20 ( V_33 & ~ V_49 ) ;
F_18 ( V_50 , V_34 ) ;
F_20 ( V_33 ) ;
F_17 ( & V_23 -> V_32 , V_32 ) ;
F_3 ( & V_23 -> V_46 , 0 ) ;
F_3 ( & V_23 -> V_47 , 0 ) ;
memcpy ( V_25 , V_43 , V_26 ) ;
F_17 ( & V_24 -> V_41 , V_35 ) ;
return 0 ;
}
void F_24 ( void )
{
if ( V_27 . V_56 )
V_27 . V_56 ( V_20 ) ;
F_14 ( V_20 ) ;
}
int T_6 F_25 ( void )
{
F_26 ( & V_57 ) ;
return 0 ;
}

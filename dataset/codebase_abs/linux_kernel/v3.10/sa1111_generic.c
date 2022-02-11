void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 = F_3 ( V_6 -> V_8 -> V_9 + V_10 ) ;
switch ( V_2 -> V_11 ) {
case 0 :
V_4 -> V_12 = V_7 & V_13 ? 0 : 1 ;
V_4 -> V_14 = V_7 & V_15 ? 1 : 0 ;
V_4 -> V_16 = V_7 & V_17 ? 1 : 0 ;
V_4 -> V_18 = V_7 & V_19 ? 1 : 0 ;
V_4 -> V_20 = V_7 & V_21 ? 1 : 0 ;
V_4 -> V_22 = V_7 & V_23 ? 0 : 1 ;
V_4 -> V_24 = V_7 & V_25 ? 0 : 1 ;
break;
case 1 :
V_4 -> V_12 = V_7 & V_26 ? 0 : 1 ;
V_4 -> V_14 = V_7 & V_27 ? 1 : 0 ;
V_4 -> V_16 = V_7 & V_28 ? 1 : 0 ;
V_4 -> V_18 = V_7 & V_29 ? 1 : 0 ;
V_4 -> V_20 = V_7 & V_30 ? 1 : 0 ;
V_4 -> V_22 = V_7 & V_31 ? 0 : 1 ;
V_4 -> V_24 = V_7 & V_32 ? 0 : 1 ;
break;
}
}
int F_4 ( struct V_1 * V_2 , const T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_33 , V_34 , V_35 ;
unsigned long V_36 ;
switch ( V_2 -> V_11 ) {
case 0 :
V_33 = V_37 | V_38 | V_39 | V_40 ;
break;
case 1 :
V_33 = V_41 | V_42 | V_43 | V_44 ;
break;
default:
return - 1 ;
}
V_34 = 0 ;
if ( V_4 -> V_45 != 0 )
V_34 |= V_39 | V_43 ;
if ( V_4 -> V_45 == 50 )
V_34 |= V_40 | V_44 ;
if ( V_4 -> V_36 & V_46 )
V_34 |= V_37 | V_41 ;
if ( V_4 -> V_36 & V_47 )
V_34 |= V_38 | V_42 ;
F_5 ( V_36 ) ;
V_35 = F_3 ( V_6 -> V_8 -> V_9 + V_48 ) ;
V_35 &= ~ V_33 ;
V_35 |= V_34 & V_33 ;
F_6 ( V_35 , V_6 -> V_8 -> V_9 + V_48 ) ;
F_7 ( V_36 ) ;
return 0 ;
}
int F_8 ( struct V_49 * V_8 , struct V_50 * V_51 ,
int (* F_9)( struct V_1 * ) )
{
struct V_5 * V_6 ;
int V_52 , V_53 = 0 ;
V_51 -> V_54 = F_1 ;
for ( V_52 = 0 ; V_52 < V_51 -> V_11 ; V_52 ++ ) {
V_6 = F_10 ( sizeof( * V_6 ) , V_55 ) ;
if ( ! V_6 )
return - V_56 ;
V_6 -> V_57 . V_11 = V_51 -> V_58 + V_52 ;
F_11 ( & V_6 -> V_57 , V_51 , & V_8 -> V_8 ) ;
V_6 -> V_8 = V_8 ;
if ( V_6 -> V_57 . V_11 ) {
V_6 -> V_57 . V_59 . V_60 = V_8 -> V_61 [ V_62 ] ;
V_6 -> V_57 . V_63 [ V_64 ] . V_61 = V_8 -> V_61 [ V_65 ] ;
V_6 -> V_57 . V_63 [ V_64 ] . V_66 = L_1 ;
V_6 -> V_57 . V_63 [ V_67 ] . V_61 = V_8 -> V_61 [ V_68 ] ;
V_6 -> V_57 . V_63 [ V_67 ] . V_66 = L_2 ;
} else {
V_6 -> V_57 . V_59 . V_60 = V_8 -> V_61 [ V_69 ] ;
V_6 -> V_57 . V_63 [ V_64 ] . V_61 = V_8 -> V_61 [ V_70 ] ;
V_6 -> V_57 . V_63 [ V_64 ] . V_66 = L_3 ;
V_6 -> V_57 . V_63 [ V_67 ] . V_61 = V_8 -> V_61 [ V_71 ] ;
V_6 -> V_57 . V_63 [ V_67 ] . V_66 = L_4 ;
}
V_53 = F_9 ( & V_6 -> V_57 ) ;
if ( V_53 == 0 ) {
V_6 -> V_72 = F_12 ( & V_8 -> V_8 ) ;
F_13 ( & V_8 -> V_8 , V_6 ) ;
} else
F_14 ( V_6 ) ;
}
return V_53 ;
}
static int F_15 ( struct V_49 * V_8 )
{
void T_2 * V_73 ;
int V_53 ;
V_53 = F_16 ( V_8 ) ;
if ( V_53 )
return V_53 ;
F_13 ( & V_8 -> V_8 , NULL ) ;
if ( ! F_17 ( V_8 -> V_74 . V_75 , 512 , F_18 ( V_8 ) ) ) {
F_19 ( V_8 ) ;
return - V_76 ;
}
V_73 = V_8 -> V_9 ;
F_6 ( V_77 | V_78 , V_73 + V_79 ) ;
F_6 ( V_38 | V_42 , V_73 + V_48 ) ;
#ifdef F_20
F_21 ( & V_8 -> V_8 ) ;
#endif
#ifdef F_22
F_23 ( & V_8 -> V_8 ) ;
#endif
#ifdef F_24
F_25 ( V_8 ) ;
#endif
#ifdef F_26
F_27 ( V_8 ) ;
#endif
return 0 ;
}
static int F_28 ( struct V_49 * V_8 )
{
struct V_5 * V_72 , * V_6 = F_12 ( & V_8 -> V_8 ) ;
F_13 ( & V_8 -> V_8 , NULL ) ;
for (; V_6 ; V_6 = V_72 ) {
V_72 = V_6 -> V_72 ;
F_29 ( & V_6 -> V_57 ) ;
F_14 ( V_6 ) ;
}
F_30 ( V_8 -> V_74 . V_75 , 512 ) ;
F_19 ( V_8 ) ;
return 0 ;
}
static int T_3 F_31 ( void )
{
return F_32 ( & V_80 ) ;
}
static void T_4 F_33 ( void )
{
F_34 ( & V_80 ) ;
}

static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , F_3 ( V_3 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , V_3 , F_3 ( V_3 ) ) ;
}
void F_6 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_6 * V_7 = F_7 ( V_2 ) ;
unsigned long V_8 = F_8 ( V_7 -> V_9 -> V_10 + V_11 ) ;
switch ( V_2 -> V_12 ) {
case 0 :
V_5 -> V_13 = V_8 & V_14 ? 0 : 1 ;
V_5 -> V_15 = V_8 & V_16 ? 1 : 0 ;
V_5 -> V_17 = V_8 & V_18 ? 1 : 0 ;
V_5 -> V_19 = V_8 & V_20 ? 1 : 0 ;
V_5 -> V_21 = V_8 & V_22 ? 1 : 0 ;
V_5 -> V_23 = V_8 & V_24 ? 0 : 1 ;
V_5 -> V_25 = V_8 & V_26 ? 0 : 1 ;
break;
case 1 :
V_5 -> V_13 = V_8 & V_27 ? 0 : 1 ;
V_5 -> V_15 = V_8 & V_28 ? 1 : 0 ;
V_5 -> V_17 = V_8 & V_29 ? 1 : 0 ;
V_5 -> V_19 = V_8 & V_30 ? 1 : 0 ;
V_5 -> V_21 = V_8 & V_31 ? 1 : 0 ;
V_5 -> V_23 = V_8 & V_32 ? 0 : 1 ;
V_5 -> V_25 = V_8 & V_33 ? 0 : 1 ;
break;
}
}
int F_9 ( struct V_1 * V_2 , const T_1 * V_5 )
{
struct V_6 * V_7 = F_7 ( V_2 ) ;
unsigned int V_34 , V_35 , V_36 ;
unsigned long V_37 ;
switch ( V_2 -> V_12 ) {
case 0 :
V_34 = V_38 | V_39 | V_40 | V_41 ;
break;
case 1 :
V_34 = V_42 | V_43 | V_44 | V_45 ;
break;
default:
return - 1 ;
}
V_35 = 0 ;
if ( V_5 -> V_46 != 0 )
V_35 |= V_40 | V_44 ;
if ( V_5 -> V_46 == 50 )
V_35 |= V_41 | V_45 ;
if ( V_5 -> V_37 & V_47 )
V_35 |= V_38 | V_42 ;
if ( V_5 -> V_37 & V_48 )
V_35 |= V_39 | V_43 ;
F_10 ( V_37 ) ;
V_36 = F_8 ( V_7 -> V_9 -> V_10 + V_49 ) ;
V_36 &= ~ V_34 ;
V_36 |= V_35 & V_34 ;
F_11 ( V_36 , V_7 -> V_9 -> V_10 + V_49 ) ;
F_12 ( V_37 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 , V_3 , F_3 ( V_3 ) ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_3 , F_3 ( V_3 ) ) ;
}
int F_17 ( struct V_50 * V_9 , struct V_51 * V_52 ,
int (* F_18)( struct V_1 * ) )
{
struct V_6 * V_7 ;
int V_53 , V_54 = 0 ;
V_52 -> V_55 = F_1 ;
V_52 -> V_56 = F_4 ;
V_52 -> V_57 = F_6 ;
V_52 -> V_58 = F_15 ;
for ( V_53 = 0 ; V_53 < V_52 -> V_12 ; V_53 ++ ) {
V_7 = F_19 ( sizeof( * V_7 ) , V_59 ) ;
if ( ! V_7 )
return - V_60 ;
V_7 -> V_61 . V_12 = V_52 -> V_62 + V_53 ;
V_7 -> V_61 . V_52 = V_52 ;
V_7 -> V_61 . V_63 . V_64 = V_52 -> V_64 ;
V_7 -> V_61 . V_63 . V_9 . V_65 = & V_9 -> V_9 ;
V_7 -> V_61 . V_63 . V_66 = V_7 -> V_61 . V_12 ?
V_9 -> V_67 [ V_68 ] :
V_9 -> V_67 [ V_69 ] ;
V_7 -> V_9 = V_9 ;
V_54 = F_18 ( & V_7 -> V_61 ) ;
if ( V_54 == 0 ) {
V_7 -> V_70 = F_20 ( & V_9 -> V_9 ) ;
F_21 ( & V_9 -> V_9 , V_7 ) ;
} else
F_22 ( V_7 ) ;
}
return V_54 ;
}
static int F_23 ( struct V_50 * V_9 )
{
void T_2 * V_71 ;
F_21 ( & V_9 -> V_9 , NULL ) ;
if ( ! F_24 ( V_9 -> V_72 . V_73 , 512 ,
F_25 ( V_9 ) ) )
return - V_74 ;
V_71 = V_9 -> V_10 ;
V_3 [ 0 ] . V_67 = V_9 -> V_67 [ V_75 ] ;
V_3 [ 1 ] . V_67 = V_9 -> V_67 [ V_76 ] ;
V_3 [ 2 ] . V_67 = V_9 -> V_67 [ V_77 ] ;
V_3 [ 3 ] . V_67 = V_9 -> V_67 [ V_78 ] ;
F_11 ( V_79 | V_80 , V_71 + V_81 ) ;
F_11 ( V_39 | V_43 , V_71 + V_49 ) ;
#ifdef F_26
F_27 ( & V_9 -> V_9 ) ;
#endif
#ifdef F_28
F_29 ( & V_9 -> V_9 ) ;
#endif
#ifdef F_30
F_31 ( V_9 ) ;
#endif
#ifdef F_32
F_33 ( V_9 ) ;
#endif
return 0 ;
}
static int T_3 F_34 ( struct V_50 * V_9 )
{
struct V_6 * V_70 , * V_7 = F_20 ( & V_9 -> V_9 ) ;
F_21 ( & V_9 -> V_9 , NULL ) ;
for (; V_7 ; V_7 = V_70 ) {
V_70 = V_7 -> V_70 ;
F_35 ( & V_7 -> V_61 ) ;
F_22 ( V_7 ) ;
}
F_36 ( V_9 -> V_72 . V_73 , 512 ) ;
return 0 ;
}
static int T_4 F_37 ( void )
{
return F_38 ( & V_82 ) ;
}
static void T_5 F_39 ( void )
{
F_40 ( & V_82 ) ;
}

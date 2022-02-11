static int F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_3 * V_5 = & V_2 -> V_6 [ 0 ] ;
struct V_3 * V_7 = & V_2 -> V_6 [ 1 ] ;
if ( ! F_2 ( V_5 ) || ! F_2 ( V_7 ) )
return F_3 ( V_2 , V_4 ) ;
if ( memcmp ( V_5 -> V_8 + V_9 , V_7 -> V_8 + V_9 ,
V_10 + V_11 ) == 0 ) {
if ( memcmp ( V_5 -> V_8 + V_12 , V_7 -> V_8 + V_12 ,
V_13 ) == 0 && V_5 -> V_8 [ V_12 ] >> 8 ) {
F_4 ( V_7 , V_14 , L_1 ) ;
F_5 ( V_7 ) ;
}
}
return F_3 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
return 0 ;
}
static unsigned int F_7 ( struct V_3 * V_15 ,
unsigned char * V_16 , unsigned int V_17 , int V_18 )
{
struct V_19 * V_20 = V_15 -> V_2 -> V_20 ;
if ( V_18 == V_21 )
F_8 ( V_20 -> V_22 . V_23 , V_16 , V_17 ) ;
else
F_9 ( V_20 -> V_22 . V_23 , V_16 , V_17 ) ;
return V_17 ;
}
static void F_10 ( struct V_24 * V_25 )
{
int V_26 ;
struct V_19 * V_20 ;
if ( V_25 == NULL || V_25 -> V_27 == V_28 )
return;
V_20 = V_25 -> V_20 ;
for ( V_26 = 0 ; ( V_20 -> V_29 -> V_30 ( V_20 ) & V_31 )
&& V_26 ++ < 65536 ; )
F_11 ( V_20 -> V_22 . V_23 ) ;
if ( V_26 )
F_12 ( V_20 , V_14 , L_2 ,
V_26 ) ;
}
static int F_13 ( struct V_32 * V_33 , void * V_34 )
{
int * V_35 = V_34 ;
if ( ! ( V_33 -> V_36 [ 0 ] -> V_37 & V_38 ) ) {
V_33 -> V_36 [ 0 ] -> V_37 &= ~ V_39 ;
V_33 -> V_36 [ 0 ] -> V_37 |= V_40 ;
}
V_33 -> V_36 [ 1 ] -> V_37 &= ~ V_39 ;
V_33 -> V_36 [ 1 ] -> V_37 |= V_38 ;
if ( V_33 -> V_36 [ 1 ] -> V_41 ) {
V_33 -> V_36 [ 0 ] -> V_41 = 8 ;
V_33 -> V_36 [ 1 ] -> V_41 = ( * V_35 ) ? 2 : 1 ;
} else {
if ( V_33 -> V_36 [ 0 ] -> V_41 < 16 )
return - V_42 ;
}
return F_14 ( V_33 ) ;
}
static int F_15 ( struct V_32 * V_33 )
{
struct V_43 * V_44 ;
struct V_19 * V_20 ;
int V_35 = 0 , V_45 = - V_46 , V_47 ;
unsigned long V_48 , V_49 ;
void T_1 * V_50 , * V_51 ;
int V_52 = 1 ;
struct V_53 * V_29 = & V_54 ;
V_33 -> V_55 |= V_56 | V_57 |
V_58 | V_59 ;
V_35 = ( ( V_33 -> V_60 == V_61 ) &&
( ( V_33 -> V_62 == V_63 ) ||
( V_33 -> V_62 == V_64 ) ) ) ;
if ( F_16 ( V_33 , F_13 , & V_35 ) ) {
V_33 -> V_55 &= ~ V_59 ;
if ( F_16 ( V_33 , F_13 , & V_35 ) )
goto V_65;
}
V_48 = V_33 -> V_36 [ 0 ] -> V_66 ;
if ( V_33 -> V_36 [ 1 ] -> V_41 )
V_49 = V_33 -> V_36 [ 1 ] -> V_66 ;
else
V_49 = V_33 -> V_36 [ 0 ] -> V_66 + 0x0e ;
if ( ! V_33 -> V_67 )
goto V_65;
V_45 = F_17 ( V_33 ) ;
if ( V_45 )
goto V_65;
V_45 = - V_46 ;
V_50 = F_18 ( & V_33 -> V_15 , V_48 , 8 ) ;
V_51 = F_18 ( & V_33 -> V_15 , V_49 , 1 ) ;
if ( ! V_50 || ! V_51 )
goto V_65;
F_19 ( 0x02 , V_51 ) ;
if ( V_35 )
F_19 ( 0x81 , V_51 + 0x01 ) ;
if ( F_20 ( V_33 -> V_36 [ 0 ] ) >= 0x20 )
V_52 = 2 ;
if ( V_33 -> V_60 == 0x0097 && V_33 -> V_62 == 0x1620 )
V_29 = & V_68 ;
V_45 = - V_46 ;
V_44 = F_21 ( & V_33 -> V_15 , V_52 ) ;
if ( ! V_44 )
goto V_65;
for ( V_47 = 0 ; V_47 < V_52 ; V_47 ++ ) {
V_20 = V_44 -> V_69 [ V_47 ] ;
V_20 -> V_29 = V_29 ;
V_20 -> V_70 = V_71 ;
V_20 -> V_37 |= V_72 ;
V_20 -> V_22 . V_73 = V_50 + 0x10 * V_47 ;
V_20 -> V_22 . V_74 = V_51 + 0x10 * V_47 ;
V_20 -> V_22 . V_51 = V_51 + 0x10 * V_47 ;
F_22 ( & V_20 -> V_22 ) ;
F_23 ( V_20 , L_3 , V_48 , V_49 ) ;
}
V_45 = F_24 ( V_44 , V_33 -> V_67 , V_75 ,
V_76 , & V_77 ) ;
if ( V_45 )
goto V_65;
V_33 -> V_78 = V_44 ;
return 0 ;
V_65:
F_25 ( V_33 ) ;
return V_45 ;
}
static void F_26 ( struct V_32 * V_33 )
{
struct V_43 * V_44 = V_33 -> V_78 ;
if ( V_44 )
F_27 ( V_44 ) ;
F_25 ( V_33 ) ;
}
static int T_2 F_28 ( void )
{
return F_29 ( & V_79 ) ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_79 ) ;
}

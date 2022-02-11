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
F_4 ( V_7 , L_1 ) ;
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
static unsigned int F_7 ( struct V_3 * V_14 ,
unsigned char * V_15 , unsigned int V_16 , int V_17 )
{
struct V_18 * V_19 = V_14 -> V_2 -> V_19 ;
if ( V_17 == V_20 )
F_8 ( V_19 -> V_21 . V_22 , V_15 , V_16 ) ;
else
F_9 ( V_19 -> V_21 . V_22 , V_15 , V_16 ) ;
return V_16 ;
}
static void F_10 ( struct V_23 * V_24 )
{
int V_25 ;
struct V_18 * V_19 ;
if ( V_24 == NULL || V_24 -> V_26 == V_27 )
return;
V_19 = V_24 -> V_19 ;
for ( V_25 = 0 ; ( V_19 -> V_28 -> V_29 ( V_19 ) & V_30 )
&& V_25 ++ < 65536 ; )
F_11 ( V_19 -> V_21 . V_22 ) ;
if ( V_25 )
F_12 ( V_19 , L_2 , V_25 ) ;
}
static int F_13 ( struct V_31 * V_32 , void * V_33 )
{
int * V_34 = V_33 ;
if ( ( V_32 -> V_35 [ 0 ] -> V_36 & V_37 )
!= V_38 ) {
V_32 -> V_35 [ 0 ] -> V_36 &= ~ V_37 ;
V_32 -> V_35 [ 0 ] -> V_36 |= V_39 ;
}
V_32 -> V_35 [ 1 ] -> V_36 &= ~ V_37 ;
V_32 -> V_35 [ 1 ] -> V_36 |= V_38 ;
if ( V_32 -> V_35 [ 1 ] -> V_40 ) {
V_32 -> V_35 [ 0 ] -> V_40 = 8 ;
V_32 -> V_35 [ 1 ] -> V_40 = ( * V_34 ) ? 2 : 1 ;
} else {
if ( V_32 -> V_35 [ 0 ] -> V_40 < 16 )
return - V_41 ;
}
return F_14 ( V_32 ) ;
}
static int F_15 ( struct V_31 * V_32 )
{
struct V_42 * V_43 ;
struct V_18 * V_19 ;
int V_34 = 0 , V_44 = - V_45 , V_46 ;
unsigned long V_47 , V_48 ;
void T_1 * V_49 , * V_50 ;
int V_51 = 1 ;
struct V_52 * V_28 = & V_53 ;
V_32 -> V_54 |= V_55 | V_56 |
V_57 | V_58 ;
V_34 = ( ( V_32 -> V_59 == V_60 ) &&
( ( V_32 -> V_61 == V_62 ) ||
( V_32 -> V_61 == V_63 ) ) ) ;
if ( F_16 ( V_32 , F_13 , & V_34 ) ) {
V_32 -> V_54 &= ~ V_58 ;
if ( F_16 ( V_32 , F_13 , & V_34 ) )
goto V_64;
}
V_47 = V_32 -> V_35 [ 0 ] -> V_65 ;
if ( V_32 -> V_35 [ 1 ] -> V_40 )
V_48 = V_32 -> V_35 [ 1 ] -> V_65 ;
else
V_48 = V_32 -> V_35 [ 0 ] -> V_65 + 0x0e ;
if ( ! V_32 -> V_66 )
goto V_64;
V_44 = F_17 ( V_32 ) ;
if ( V_44 )
goto V_64;
V_44 = - V_45 ;
V_49 = F_18 ( & V_32 -> V_14 , V_47 , 8 ) ;
V_50 = F_18 ( & V_32 -> V_14 , V_48 , 1 ) ;
if ( ! V_49 || ! V_50 )
goto V_64;
F_19 ( 0x02 , V_50 ) ;
if ( V_34 )
F_19 ( 0x81 , V_50 + 0x01 ) ;
if ( F_20 ( V_32 -> V_35 [ 0 ] ) >= 0x20 )
V_51 = 2 ;
if ( V_32 -> V_59 == 0x0097 && V_32 -> V_61 == 0x1620 )
V_28 = & V_67 ;
V_44 = - V_45 ;
V_43 = F_21 ( & V_32 -> V_14 , V_51 ) ;
if ( ! V_43 )
goto V_64;
for ( V_46 = 0 ; V_46 < V_51 ; V_46 ++ ) {
V_19 = V_43 -> V_68 [ V_46 ] ;
V_19 -> V_28 = V_28 ;
V_19 -> V_69 = V_70 ;
V_19 -> V_36 |= V_71 ;
V_19 -> V_21 . V_72 = V_49 + 0x10 * V_46 ;
V_19 -> V_21 . V_73 = V_50 + 0x10 * V_46 ;
V_19 -> V_21 . V_50 = V_50 + 0x10 * V_46 ;
F_22 ( & V_19 -> V_21 ) ;
F_23 ( V_19 , L_3 , V_47 , V_48 ) ;
}
V_44 = F_24 ( V_43 , V_32 -> V_66 , V_74 ,
V_75 , & V_76 ) ;
if ( V_44 )
goto V_64;
V_32 -> V_77 = V_43 ;
return 0 ;
V_64:
F_25 ( V_32 ) ;
return V_44 ;
}
static void F_26 ( struct V_31 * V_32 )
{
struct V_42 * V_43 = V_32 -> V_77 ;
if ( V_43 )
F_27 ( V_43 ) ;
F_25 ( V_32 ) ;
}

static int F_1 ( struct V_1 * V_2 )
{
T_1 * V_3 ;
F_2 ( & V_2 -> V_4 , L_1 ) ;
V_3 = F_3 ( sizeof( * V_3 ) , V_5 ) ;
if ( ! V_3 )
return - V_6 ;
V_3 -> V_7 = V_2 ;
V_2 -> V_8 = V_3 ;
V_2 -> V_9 |= V_10 | V_11 |
V_12 | V_13 ;
return F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
F_2 ( & V_2 -> V_4 , L_2 , V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_3 ) ;
}
static struct V_14 * F_8 ( unsigned long V_15 , unsigned long V_16 ,
unsigned long V_17 , struct V_1 * V_18 )
{
struct V_14 * V_19 ;
T_2 * V_20 ;
int V_21 , V_22 ;
struct V_23 V_24 , * V_25 [] = { & V_24 } ;
if ( ! F_9 ( V_15 , 8 , V_26 ) ) {
F_10 ( V_27 L_3 ,
V_26 , V_15 , V_15 + 7 ) ;
return NULL ;
}
if ( ! F_9 ( V_16 , 1 , V_26 ) ) {
F_10 ( V_27 L_4 ,
V_26 , V_16 ) ;
F_11 ( V_15 , 8 ) ;
return NULL ;
}
memset ( & V_24 , 0 , sizeof( V_24 ) ) ;
F_12 ( & V_24 , V_15 , V_16 ) ;
V_24 . V_17 = V_17 ;
V_24 . V_4 = & V_18 -> V_4 ;
V_22 = F_13 ( & V_28 , V_25 , 1 , & V_19 ) ;
if ( V_22 )
goto V_29;
V_20 = V_19 -> V_30 [ 0 ] ;
if ( V_20 -> V_31 )
return V_19 ;
for ( V_21 = 0 ; V_21 < 10 ; V_21 ++ ) {
F_14 ( 100 ) ;
F_15 ( V_20 ) ;
if ( V_20 -> V_31 )
return V_19 ;
}
return V_19 ;
V_29:
F_11 ( V_16 , 1 ) ;
F_11 ( V_15 , 8 ) ;
return NULL ;
}
static int F_16 ( struct V_1 * V_32 , void * V_33 )
{
int * V_34 = V_33 ;
if ( ! ( V_32 -> V_35 [ 0 ] -> V_36 & V_37 ) ) {
V_32 -> V_35 [ 0 ] -> V_36 &= ~ V_38 ;
V_32 -> V_35 [ 0 ] -> V_36 |= V_39 ;
}
V_32 -> V_35 [ 1 ] -> V_36 &= ~ V_38 ;
V_32 -> V_35 [ 1 ] -> V_36 |= V_37 ;
if ( V_32 -> V_35 [ 1 ] -> V_40 ) {
V_32 -> V_35 [ 0 ] -> V_40 = 8 ;
V_32 -> V_35 [ 1 ] -> V_40 = ( * V_34 ) ? 2 : 1 ;
} else {
if ( V_32 -> V_35 [ 0 ] -> V_40 < 16 )
return - V_41 ;
}
return F_17 ( V_32 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
int V_42 = 0 , V_34 = 0 ;
unsigned long V_43 , V_44 ;
struct V_14 * V_19 ;
F_2 ( & V_2 -> V_4 , L_5 , V_2 ) ;
V_34 = ( ( V_2 -> V_45 == V_46 ) &&
( ( V_2 -> V_47 == V_48 ) ||
( V_2 -> V_47 == V_49 ) ) ) ;
if ( F_18 ( V_2 , F_16 , & V_34 ) ) {
V_2 -> V_9 &= ~ V_13 ;
if ( F_18 ( V_2 , F_16 , & V_34 ) )
goto V_50;
}
V_43 = V_2 -> V_35 [ 0 ] -> V_51 ;
if ( V_2 -> V_35 [ 1 ] -> V_40 )
V_44 = V_2 -> V_35 [ 1 ] -> V_51 ;
else
V_44 = V_2 -> V_35 [ 0 ] -> V_51 + 0x0e ;
if ( ! V_2 -> V_17 )
goto V_50;
V_42 = F_19 ( V_2 ) ;
if ( V_42 )
goto V_50;
F_20 ( 0x02 , V_44 ) ;
if ( V_34 )
F_20 ( 0x81 , V_44 + 1 ) ;
V_19 = F_8 ( V_43 , V_44 , V_2 -> V_17 , V_2 ) ;
if ( V_19 == NULL && F_21 ( V_2 -> V_35 [ 0 ] ) == 0x20 ) {
F_20 ( 0x02 , V_44 + 0x10 ) ;
V_19 = F_8 ( V_43 + 0x10 , V_44 + 0x10 ,
V_2 -> V_17 , V_2 ) ;
}
if ( V_19 == NULL )
goto V_50;
V_3 -> V_52 = 1 ;
V_3 -> V_19 = V_19 ;
F_22 ( & V_2 -> V_4 , L_6 ,
'a' + V_19 -> V_30 [ 0 ] -> V_53 * 2 ,
V_2 -> V_54 / 10 , V_2 -> V_54 % 10 ) ;
return 0 ;
V_50:
F_6 ( V_2 ) ;
return - V_41 ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 * V_3 = V_2 -> V_8 ;
struct V_14 * V_19 = V_3 -> V_19 ;
F_2 ( & V_2 -> V_4 , L_7 , V_2 ) ;
if ( V_3 -> V_52 ) {
T_2 * V_20 = V_19 -> V_30 [ 0 ] ;
unsigned long V_55 , V_56 ;
V_55 = V_20 -> V_57 . V_55 ;
V_56 = V_20 -> V_57 . V_56 ;
F_23 ( V_19 ) ;
V_3 -> V_52 = 0 ;
F_11 ( V_56 , 1 ) ;
F_11 ( V_55 , 8 ) ;
}
F_24 ( V_2 ) ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_58 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_58 ) ;
}

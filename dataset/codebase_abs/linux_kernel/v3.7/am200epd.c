static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ ) {
V_4 = F_3 ( V_5 [ V_3 ] , V_6 [ V_3 ] ) ;
if ( V_4 ) {
F_4 ( & V_7 -> V_8 , L_1
L_2 , V_6 [ V_3 ] , V_4 ) ;
goto V_9;
}
}
F_5 ( V_10 , 0 ) ;
F_5 ( V_11 , 0 ) ;
F_5 ( V_12 , 0 ) ;
F_6 ( V_13 ) ;
F_6 ( V_14 ) ;
F_5 ( V_15 , 0 ) ;
return 0 ;
V_9:
while ( -- V_3 >= 0 )
F_7 ( V_5 [ V_3 ] ) ;
return V_4 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_3 ;
F_9 ( F_10 ( V_13 ) , V_2 ) ;
for ( V_3 = 0 ; V_3 < F_2 ( V_5 ) ; V_3 ++ )
F_7 ( V_5 [ V_3 ] ) ;
}
static int F_11 ( struct V_16 * V_17 )
{
if ( ( V_17 -> V_18 . V_19 != V_20 . V_21 -> V_19 )
|| ( V_17 -> V_18 . V_22 != V_20 . V_21 -> V_22 ) )
return 0 ;
V_23 . V_24 = V_17 -> V_25 ;
V_23 . V_26 = V_17 ;
if ( ! F_12 ( V_17 -> V_27 -> V_28 ) )
return - V_29 ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 )
{
F_14 ( & V_7 -> V_8 , L_3 , V_30 ) ;
if ( V_17 != V_23 . V_26 )
return 0 ;
F_15 ( V_23 . V_26 -> V_27 -> V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_34 )
{
struct V_35 * V_36 = V_34 ;
struct V_16 * V_17 = V_36 -> V_17 ;
F_14 ( & V_7 -> V_8 , L_3 , V_30 ) ;
if ( V_33 == V_37 )
return F_11 ( V_17 ) ;
else if ( V_33 == V_38 )
return F_13 ( V_17 ) ;
return 0 ;
}
static void T_1 F_17 ( void )
{
int V_39 ;
int V_40 ;
int V_41 ;
int V_42 ;
switch ( V_43 ) {
case 6 :
V_20 . V_21 = & V_44 ;
break;
case 8 :
V_20 . V_21 = & V_45 ;
break;
case 97 :
V_20 . V_21 = & V_46 ;
break;
default:
F_4 ( & V_7 -> V_8 , L_4
L_5 ) ;
V_20 . V_21 = & V_44 ;
break;
}
V_39 = V_20 . V_21 -> V_19 ;
V_40 = V_20 . V_21 -> V_22 ;
V_23 . V_47 = F_18 ( 16 * 1024 + 2 , V_39 ) ;
V_41 = V_48 + ( 4 * V_39 ) ;
V_42 = V_39 + V_23 . V_47 + V_41 + ( V_39 * V_40 ) ;
V_23 . V_39 = V_39 ;
V_23 . V_40 = V_40 ;
V_20 . V_21 -> V_22 = F_19 ( V_42 , V_39 ) ;
V_20 . V_21 -> V_19 /= 2 ;
F_20 ( NULL , & V_20 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_39 ;
int V_40 ;
V_39 = V_23 . V_39 ;
V_40 = V_23 . V_40 ;
V_2 -> V_49 = (struct V_49 * ) V_23 . V_24 ;
V_2 -> V_50 = V_23 . V_24 + V_39 ;
V_2 -> V_51 = V_2 -> V_50 + V_23 . V_47 ;
V_2 -> V_52 = ( V_53 * ) ( V_2 -> V_51 + ( V_39 * V_40 ) ) ;
V_2 -> V_54 = V_23 . V_26 -> V_55 . V_56 ;
return 0 ;
}
static int F_22 ( void )
{
return V_43 ;
}
static T_2 F_23 ( int V_57 , void * V_58 )
{
struct V_1 * V_2 = V_58 ;
F_24 ( & V_2 -> V_59 ) ;
return V_60 ;
}
static int F_25 ( struct V_16 * V_17 )
{
int V_61 ;
V_61 = F_26 ( F_10 ( V_13 ) , F_23 ,
V_62 | V_63 ,
L_6 , V_17 -> V_2 ) ;
if ( V_61 )
F_4 ( & V_7 -> V_8 , L_7 , V_61 ) ;
return V_61 ;
}
static void F_27 ( struct V_1 * V_2 , int V_64 )
{
F_28 ( V_12 , V_64 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_64 )
{
F_28 ( V_11 , V_64 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
return F_31 ( V_2 -> V_59 , F_32 ( V_13 ) , V_65 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
return F_34 ( V_2 -> V_59 ,
F_32 ( V_13 ) , V_65 ) ;
}
int T_1 F_35 ( void )
{
int V_61 ;
F_36 ( & V_66 ) ;
F_37 ( F_38 ( V_67 ) ) ;
F_39 ( L_8 ) ;
V_7 = F_40 ( L_8 , - 1 ) ;
if ( ! V_7 )
return - V_68 ;
F_41 ( V_7 , & V_23 ,
sizeof( V_23 ) ) ;
V_61 = F_42 ( V_7 ) ;
if ( V_61 ) {
F_43 ( V_7 ) ;
F_44 ( & V_66 ) ;
return V_61 ;
}
F_17 () ;
return 0 ;
}

static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
int V_3 = V_2 -> V_4 ;
int V_5 ;
F_3 ( V_2 , L_1 ) ;
for ( V_5 = V_3 ; V_5 < V_3 + 16 ; V_5 ++ )
{
if ( ! ( V_5 % 16 ) )
F_4 ( L_2 , V_5 ) ;
F_4 ( L_3 , F_5 ( V_5 ) ) ;
}
F_4 ( L_4 ) ;
F_3 ( V_2 , L_5 ) ;
V_5 = 0 ;
F_6 ( ( V_5 >> 8 ) | V_6 | V_7 , V_8 ) ;
F_6 ( V_5 & 0xff , V_9 ) ;
for ( V_5 = 0 ; V_5 < 256 + 32 ; V_5 ++ )
{
if ( ! ( V_5 % 16 ) )
F_4 ( L_2 , V_5 ) ;
F_4 ( L_3 , F_5 ( V_10 ) ) ;
}
F_4 ( L_4 ) ;
#endif
}
static int F_7 ( struct V_11 * V_12 )
{
T_1 * V_13 ;
struct V_1 * V_2 ;
struct V_14 * V_15 ;
F_8 ( & V_12 -> V_2 , L_6 ) ;
V_13 = F_9 ( sizeof( struct T_1 ) , V_16 ) ;
if ( ! V_13 )
goto V_17;
V_2 = F_10 ( L_7 ) ;
if ( ! V_2 )
goto V_18;
V_15 = F_11 ( V_2 ) ;
V_15 -> V_19 = V_19 ;
V_15 -> V_20 = V_20 ;
V_15 -> V_21 = V_21 ;
V_15 -> V_22 = V_22 & 3 ;
V_15 -> V_23 . V_24 = V_25 ;
V_2 -> V_26 [ 0 ] = V_27 ;
V_12 -> V_28 [ 0 ] -> V_29 |= V_30 ;
V_12 -> V_28 [ 0 ] -> V_31 = 16 ;
V_12 -> V_32 |= V_33 ;
V_13 -> V_2 = V_2 ;
V_12 -> V_34 = V_13 ;
return F_12 ( V_12 ) ;
V_18:
F_13 ( V_13 ) ;
V_17:
return - V_35 ;
}
static void F_14 ( struct V_11 * V_36 )
{
struct T_1 * V_13 = V_36 -> V_34 ;
struct V_1 * V_2 = V_13 -> V_2 ;
F_8 ( & V_36 -> V_2 , L_8 ) ;
F_8 ( & V_36 -> V_2 , L_9 ) ;
F_8 ( & V_36 -> V_2 , L_10 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_37 )
F_16 ( V_2 -> V_37 , V_2 ) ;
F_17 ( V_36 ) ;
F_8 ( & V_36 -> V_2 , L_11 ) ;
if ( V_36 -> V_34 )
{
V_2 = V_13 -> V_2 ;
if ( V_2 )
{
F_8 ( & V_36 -> V_2 , L_12 ) ;
F_18 ( V_2 ) ;
}
F_8 ( & V_36 -> V_2 , L_13 ) ;
F_13 ( V_13 ) ;
}
}
static int F_12 ( struct V_11 * V_36 )
{
struct V_14 * V_15 ;
T_1 * V_13 ;
struct V_1 * V_2 ;
int V_38 , V_39 ;
int V_3 ;
V_13 = V_36 -> V_34 ;
V_2 = V_13 -> V_2 ;
F_8 ( & V_36 -> V_2 , L_14 ) ;
F_8 ( & V_36 -> V_2 , L_15 ) ;
F_8 ( & V_36 -> V_2 , L_16 ,
( unsigned int ) V_36 -> V_28 [ 0 ] -> V_40 ) ;
V_38 = - V_41 ;
V_36 -> V_42 = 16 ;
if ( ! V_36 -> V_28 [ 0 ] -> V_40 )
{
for ( V_3 = 0x100 ; V_3 < 0x400 ; V_3 += 0x10 )
{
V_36 -> V_28 [ 0 ] -> V_40 = V_3 ;
V_38 = F_19 ( V_36 ) ;
if ( V_38 == 0 )
break;
}
}
else
V_38 = F_19 ( V_36 ) ;
if ( V_38 != 0 )
{
F_8 ( & V_36 -> V_2 , L_17 ) ;
goto V_43;
}
V_3 = V_2 -> V_4 = V_36 -> V_28 [ 0 ] -> V_40 ;
F_8 ( & V_36 -> V_2 , L_18 , V_3 ) ;
F_8 ( & V_36 -> V_2 , L_19 ,
V_36 -> V_37 ) ;
if ( ! V_36 -> V_37 )
{
F_8 ( & V_36 -> V_2 , L_20 ) ;
goto V_43;
}
V_2 -> V_37 = V_36 -> V_37 ;
V_39 = F_20 ( V_36 ) ;
if ( V_39 )
goto V_43;
if ( F_21 ( V_2 ) )
{
F_1 ( V_2 ) ;
goto V_43;
}
V_15 = F_11 ( V_2 ) ;
V_15 -> V_44 = L_21 ;
V_15 -> V_45 = V_46 ;
F_22 ( V_2 , & V_36 -> V_2 ) ;
V_38 = F_23 ( V_2 , 0 ) ;
if ( V_38 != 0 ) {
F_24 ( & V_36 -> V_2 ,
L_22 ) ;
goto V_43;
}
F_3 ( V_2 , L_23 ,
V_2 -> V_4 , V_2 -> V_37 ) ;
return 0 ;
V_43:
F_8 ( & V_36 -> V_2 , L_24 ) ;
F_17 ( V_36 ) ;
return - V_41 ;
}
static void F_17 ( struct V_11 * V_36 )
{
F_8 ( & V_36 -> V_2 , L_25 ) ;
F_25 ( V_36 ) ;
}
static int F_26 ( struct V_11 * V_36 )
{
T_1 * V_13 = V_36 -> V_34 ;
struct V_1 * V_2 = V_13 -> V_2 ;
if ( V_36 -> V_47 )
F_27 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_11 * V_36 )
{
T_1 * V_13 = V_36 -> V_34 ;
struct V_1 * V_2 = V_13 -> V_2 ;
if ( V_36 -> V_47 ) {
int V_3 = V_2 -> V_4 ;
struct V_14 * V_15 = F_11 ( V_2 ) ;
V_48 ;
}
return 0 ;
}

static void F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
int V_3 = V_2 -> V_4 ;
int V_5 ;
F_3 ( V_2 , L_1 ) ;
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
if ( ! ( V_5 % 16 ) )
F_4 ( L_2 , V_3 + V_5 ) ;
F_4 ( L_3 , F_5 ( V_3 , V_5 ) ) ;
}
F_4 ( L_4 ) ;
F_3 ( V_2 , L_5 ) ;
V_5 = 0 ;
F_6 ( ( V_5 >> 8 ) | V_6 | V_7 ,
V_3 , V_8 ) ;
F_6 ( V_5 & 0xff , V_3 , V_9 ) ;
for ( V_5 = 0 ; V_5 < 256 + 32 ; V_5 ++ ) {
if ( ! ( V_5 % 16 ) )
F_4 ( L_2 , V_5 ) ;
F_4 ( L_3 , F_5 ( V_3 , V_10 ) ) ;
}
F_4 ( L_4 ) ;
#endif
}
static int F_7 ( struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
F_8 ( & V_12 -> V_2 , L_6 ) ;
V_14 = F_9 ( sizeof( * V_14 ) , V_17 ) ;
if ( ! V_14 )
goto V_18;
V_2 = F_10 ( L_7 ) ;
if ( ! V_2 )
goto V_19;
V_16 = F_11 ( V_2 ) ;
V_16 -> V_20 = V_20 ;
V_16 -> V_21 = V_21 ;
V_16 -> V_22 = V_22 ;
V_16 -> V_23 = V_23 & 3 ;
V_16 -> V_24 . V_25 = V_26 ;
V_2 -> V_27 [ 0 ] = V_28 ;
V_12 -> V_29 [ 0 ] -> V_30 |= V_31 ;
V_12 -> V_29 [ 0 ] -> V_32 = 16 ;
V_12 -> V_33 |= V_34 ;
V_14 -> V_2 = V_2 ;
V_12 -> V_35 = V_14 ;
return F_12 ( V_12 ) ;
V_19:
F_13 ( V_14 ) ;
V_18:
return - V_36 ;
}
static void F_14 ( struct V_11 * V_37 )
{
struct V_13 * V_14 = V_37 -> V_35 ;
struct V_1 * V_2 = V_14 -> V_2 ;
F_8 ( & V_37 -> V_2 , L_8 ) ;
F_8 ( & V_37 -> V_2 , L_9 ) ;
F_8 ( & V_37 -> V_2 , L_10 ) ;
F_15 ( V_2 ) ;
if ( V_2 -> V_38 )
F_16 ( V_2 -> V_38 , V_2 ) ;
F_17 ( V_37 ) ;
F_8 ( & V_37 -> V_2 , L_11 ) ;
if ( V_37 -> V_35 ) {
V_2 = V_14 -> V_2 ;
if ( V_2 ) {
F_8 ( & V_37 -> V_2 , L_12 ) ;
F_18 ( V_2 ) ;
}
F_8 ( & V_37 -> V_2 , L_13 ) ;
F_13 ( V_14 ) ;
}
}
static int F_12 ( struct V_11 * V_37 )
{
struct V_15 * V_16 ;
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_39 , V_40 ;
int V_3 ;
V_14 = V_37 -> V_35 ;
V_2 = V_14 -> V_2 ;
F_8 ( & V_37 -> V_2 , L_14 ) ;
F_8 ( & V_37 -> V_2 , L_15 ) ;
F_8 ( & V_37 -> V_2 , L_16 ,
( unsigned int ) V_37 -> V_29 [ 0 ] -> V_41 ) ;
V_39 = - V_42 ;
V_37 -> V_43 = 16 ;
if ( ! V_37 -> V_29 [ 0 ] -> V_41 ) {
for ( V_3 = 0x100 ; V_3 < 0x400 ; V_3 += 0x10 ) {
V_37 -> V_29 [ 0 ] -> V_41 = V_3 ;
V_39 = F_19 ( V_37 ) ;
if ( V_39 == 0 )
break;
}
} else {
V_39 = F_19 ( V_37 ) ;
}
if ( V_39 != 0 ) {
F_8 ( & V_37 -> V_2 , L_17 ) ;
goto V_44;
}
V_3 = V_2 -> V_4 = V_37 -> V_29 [ 0 ] -> V_41 ;
F_8 ( & V_37 -> V_2 , L_18 , V_3 ) ;
F_8 ( & V_37 -> V_2 , L_19 ,
V_37 -> V_38 ) ;
if ( ! V_37 -> V_38 ) {
F_8 ( & V_37 -> V_2 , L_20 ) ;
goto V_44;
}
V_2 -> V_38 = V_37 -> V_38 ;
V_40 = F_20 ( V_37 ) ;
if ( V_40 )
goto V_44;
if ( F_21 ( V_2 ) ) {
F_1 ( V_2 ) ;
goto V_44;
}
V_16 = F_11 ( V_2 ) ;
V_16 -> V_45 = L_21 ;
V_16 -> V_46 = V_47 ;
F_22 ( V_2 , & V_37 -> V_2 ) ;
V_39 = F_23 ( V_2 , 0 ) ;
if ( V_39 != 0 ) {
F_24 ( & V_37 -> V_2 ,
L_22 ) ;
goto V_44;
}
F_3 ( V_2 , L_23 ,
V_2 -> V_4 , V_2 -> V_38 ) ;
return 0 ;
V_44:
F_8 ( & V_37 -> V_2 , L_24 ) ;
F_17 ( V_37 ) ;
return - V_42 ;
}
static void F_17 ( struct V_11 * V_37 )
{
F_8 ( & V_37 -> V_2 , L_25 ) ;
F_25 ( V_37 ) ;
}
static int F_26 ( struct V_11 * V_37 )
{
struct V_13 * V_14 = V_37 -> V_35 ;
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_37 -> V_48 )
F_27 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_11 * V_37 )
{
struct V_13 * V_14 = V_37 -> V_35 ;
struct V_1 * V_2 = V_14 -> V_2 ;
if ( V_37 -> V_48 ) {
int V_3 = V_2 -> V_4 ;
struct V_15 * V_16 = F_11 ( V_2 ) ;
F_6 ( V_16 -> V_49 | 0x80 , V_3 , V_50 ) ;
F_29 ( 5 ) ;
F_6 ( V_16 -> V_49 , V_3 , V_50 ) ;
}
return 0 ;
}

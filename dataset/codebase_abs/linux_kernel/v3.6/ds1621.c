static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 , V_4 ;
V_4 = V_3 = F_2 ( V_2 , V_5 ) ;
V_4 &= ~ V_6 ;
if ( V_7 == 0 )
V_4 &= ~ V_8 ;
else if ( V_7 == 1 )
V_4 |= V_8 ;
if ( V_3 != V_4 )
F_3 ( V_2 , V_5 , V_4 ) ;
F_4 ( V_2 , V_9 ) ;
}
static struct V_10 * F_5 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_10 * V_13 = F_7 ( V_2 ) ;
T_1 V_4 ;
F_8 ( & V_13 -> V_14 ) ;
if ( F_9 ( V_15 , V_13 -> V_16 + V_17 + V_17 / 2 )
|| ! V_13 -> V_18 ) {
int V_19 ;
F_10 ( & V_2 -> V_12 , L_1 ) ;
V_13 -> V_3 = F_2 ( V_2 , V_5 ) ;
for ( V_19 = 0 ; V_19 < F_11 ( V_13 -> V_20 ) ; V_19 ++ )
V_13 -> V_20 [ V_19 ] = F_12 ( V_2 ,
V_21 [ V_19 ] ) ;
V_4 = V_13 -> V_3 ;
if ( V_13 -> V_20 [ 0 ] > V_13 -> V_20 [ 1 ] )
V_4 &= ~ V_22 ;
if ( V_13 -> V_20 [ 0 ] < V_13 -> V_20 [ 2 ] )
V_4 &= ~ V_23 ;
if ( V_13 -> V_3 != V_4 )
F_3 ( V_2 , V_5 ,
V_4 ) ;
V_13 -> V_16 = V_15 ;
V_13 -> V_18 = 1 ;
}
F_13 ( & V_13 -> V_14 ) ;
return V_13 ;
}
static T_2 F_14 ( struct V_11 * V_12 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_15 ( V_25 ) ;
struct V_10 * V_13 = F_5 ( V_12 ) ;
return sprintf ( V_26 , L_2 ,
F_16 ( V_13 -> V_20 [ V_28 -> V_29 ] ) ) ;
}
static T_2 F_17 ( struct V_11 * V_12 , struct V_24 * V_25 ,
const char * V_26 , T_3 V_30 )
{
struct V_27 * V_28 = F_15 ( V_25 ) ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_10 * V_13 = F_7 ( V_2 ) ;
long V_31 ;
int V_32 ;
V_32 = F_18 ( V_26 , 10 , & V_31 ) ;
if ( V_32 )
return V_32 ;
F_8 ( & V_13 -> V_14 ) ;
V_13 -> V_20 [ V_28 -> V_29 ] = F_19 ( V_31 ) ;
F_20 ( V_2 , V_21 [ V_28 -> V_29 ] ,
V_13 -> V_20 [ V_28 -> V_29 ] ) ;
F_13 ( & V_13 -> V_14 ) ;
return V_30 ;
}
static T_2 F_21 ( struct V_11 * V_12 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_10 * V_13 = F_5 ( V_12 ) ;
return sprintf ( V_26 , L_2 , F_22 ( V_13 -> V_3 ) ) ;
}
static T_2 F_23 ( struct V_11 * V_12 , struct V_24 * V_25 ,
char * V_26 )
{
struct V_27 * V_28 = F_15 ( V_25 ) ;
struct V_10 * V_13 = F_5 ( V_12 ) ;
return sprintf ( V_26 , L_2 , ! ! ( V_13 -> V_3 & V_28 -> V_29 ) ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_33 * V_34 )
{
struct V_35 * V_36 = V_2 -> V_36 ;
int V_3 , V_20 ;
int V_19 ;
if ( ! F_25 ( V_36 , V_37
| V_38
| V_39 ) )
return - V_40 ;
V_3 = F_2 ( V_2 , V_5 ) ;
if ( V_3 < 0 || V_3 & V_41 )
return - V_40 ;
for ( V_19 = 0 ; V_19 < F_11 ( V_21 ) ; V_19 ++ ) {
V_20 = F_26 ( V_2 , V_21 [ V_19 ] ) ;
if ( V_20 < 0 || ( V_20 & 0x7f00 ) )
return - V_40 ;
}
F_27 ( V_34 -> type , L_3 , V_42 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
const struct V_43 * V_44 )
{
struct V_10 * V_13 ;
int V_32 ;
V_13 = F_29 ( & V_2 -> V_12 , sizeof( struct V_10 ) ,
V_45 ) ;
if ( ! V_13 )
return - V_46 ;
F_30 ( V_2 , V_13 ) ;
F_31 ( & V_13 -> V_14 ) ;
F_1 ( V_2 ) ;
V_32 = F_32 ( & V_2 -> V_12 . V_47 , & V_48 ) ;
if ( V_32 )
return V_32 ;
V_13 -> V_49 = F_33 ( & V_2 -> V_12 ) ;
if ( F_34 ( V_13 -> V_49 ) ) {
V_32 = F_35 ( V_13 -> V_49 ) ;
goto V_50;
}
return 0 ;
V_50:
F_36 ( & V_2 -> V_12 . V_47 , & V_48 ) ;
return V_32 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_10 * V_13 = F_7 ( V_2 ) ;
F_38 ( V_13 -> V_49 ) ;
F_36 ( & V_2 -> V_12 . V_47 , & V_48 ) ;
return 0 ;
}

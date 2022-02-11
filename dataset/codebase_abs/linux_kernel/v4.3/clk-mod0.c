static void F_1 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
T_2 div , V_7 , V_8 ;
if ( * V_1 > V_2 )
* V_1 = V_2 ;
div = F_2 ( V_2 , * V_1 ) ;
if ( div < 16 )
V_8 = 0 ;
else if ( div / 2 < 16 )
V_8 = 1 ;
else if ( div / 4 < 16 )
V_8 = 2 ;
else
V_8 = 3 ;
V_7 = F_2 ( div , 1 << V_8 ) ;
* V_1 = ( V_2 >> V_8 ) / V_7 ;
if ( V_3 == NULL )
return;
* V_5 = V_7 - 1 ;
* V_6 = V_8 ;
}
static void T_3 F_3 ( struct V_9 * V_10 )
{
void T_4 * V_11 ;
V_11 = F_4 ( V_10 , 0 ) ;
if ( ! V_11 ) {
return;
}
F_5 ( V_10 , & V_12 ,
& V_13 , V_11 ) ;
}
static int F_6 ( struct V_14 * V_15 )
{
struct V_9 * V_16 = V_15 -> V_17 . V_18 ;
struct V_19 * V_20 ;
void T_4 * V_11 ;
if ( ! V_16 )
return - V_21 ;
V_20 = F_7 ( V_15 , V_22 , 0 ) ;
V_11 = F_8 ( & V_15 -> V_17 , V_20 ) ;
if ( F_9 ( V_11 ) )
return F_10 ( V_11 ) ;
F_5 ( V_16 , & V_12 ,
& V_13 , V_11 ) ;
return 0 ;
}
static void T_3 F_11 ( struct V_9 * V_10 )
{
void T_4 * V_11 ;
V_11 = F_12 ( V_10 , 0 , F_13 ( V_10 ) ) ;
if ( F_9 ( V_11 ) ) {
F_14 ( L_1 ,
V_10 -> V_23 ) ;
return;
}
F_5 ( V_10 , & V_24 ,
& V_13 , V_11 ) ;
}
static void T_3 F_15 ( struct V_9 * V_10 )
{
struct V_25 * V_26 ;
void T_4 * V_11 ;
V_11 = F_4 ( V_10 , 0 ) ;
if ( ! V_11 ) {
F_14 ( L_2 ) ;
return;
}
V_26 = F_5 ( V_10 , & V_12 ,
& V_27 , V_11 ) ;
F_16 ( V_26 ) ;
F_17 ( V_26 ) ;
}
static int F_18 ( struct V_28 * V_29 )
{
struct V_25 * V_30 , * V_31 , * V_25 = V_29 -> V_25 ;
struct V_32 * V_33 = F_19 ( V_29 ) ;
unsigned int V_34 , V_35 ;
T_5 V_36 , V_37 ;
T_1 V_38 ;
T_2 V_39 ;
V_38 = F_20 ( V_33 -> V_11 ) ;
V_39 = ( V_38 >> V_33 -> V_40 ) & 0x3 ;
if ( ! V_39 )
return 180 ;
V_30 = F_21 ( V_25 ) ;
if ( ! V_30 )
return - V_41 ;
V_34 = F_22 ( V_30 ) ;
if ( ! V_34 )
return - V_41 ;
V_31 = F_21 ( V_30 ) ;
if ( ! V_31 )
return - V_41 ;
V_35 = F_22 ( V_31 ) ;
if ( ! V_35 )
return - V_41 ;
V_37 = V_35 / V_34 ;
V_36 = F_23 ( 360 , V_37 ) ;
return V_39 * V_36 ;
}
static int F_24 ( struct V_28 * V_29 , int V_42 )
{
struct V_25 * V_30 , * V_31 , * V_25 = V_29 -> V_25 ;
struct V_32 * V_33 = F_19 ( V_29 ) ;
unsigned int V_34 , V_35 ;
unsigned long V_43 ;
T_1 V_38 ;
T_2 V_39 ;
V_30 = F_21 ( V_25 ) ;
if ( ! V_30 )
return - V_41 ;
V_34 = F_22 ( V_30 ) ;
if ( ! V_34 )
return - V_41 ;
V_31 = F_21 ( V_30 ) ;
if ( ! V_31 )
return - V_41 ;
V_35 = F_22 ( V_31 ) ;
if ( ! V_35 )
return - V_41 ;
if ( V_42 != 180 ) {
T_5 V_36 , V_37 ;
V_37 = V_35 / V_34 ;
V_36 = F_23 ( 360 , V_37 ) ;
V_39 = F_23 ( V_42 , V_36 ) ;
} else {
V_39 = 0 ;
}
F_25 ( V_33 -> V_44 , V_43 ) ;
V_38 = F_20 ( V_33 -> V_11 ) ;
V_38 &= ~ F_26 ( V_33 -> V_40 + 3 , V_33 -> V_40 ) ;
V_38 |= V_39 << V_33 -> V_40 ;
F_27 ( V_38 , V_33 -> V_11 ) ;
F_28 ( V_33 -> V_44 , V_43 ) ;
return 0 ;
}
static void T_3 F_29 ( struct V_9 * V_10 ,
const struct V_45 * V_46 ,
T_6 * V_44 )
{
struct V_47 * V_48 ;
const char * V_49 ;
void T_4 * V_11 ;
int V_50 ;
V_11 = F_12 ( V_10 , 0 , F_13 ( V_10 ) ) ;
if ( F_9 ( V_11 ) ) {
F_14 ( L_3 , V_10 -> V_23 ) ;
return;
}
V_48 = F_30 ( sizeof( * V_48 ) , V_51 ) ;
if ( ! V_48 )
return;
V_48 -> V_52 = F_31 ( 3 , sizeof( * V_48 -> V_52 ) , V_51 ) ;
if ( ! V_48 -> V_52 )
goto V_53;
V_48 -> V_54 = 3 ;
V_48 -> V_52 [ 0 ] = F_5 ( V_10 , V_46 , V_44 , V_11 ) ;
if ( ! V_48 -> V_52 [ 0 ] )
goto V_55;
V_49 = F_32 ( V_48 -> V_52 [ 0 ] ) ;
for ( V_50 = 1 ; V_50 < 3 ; V_50 ++ ) {
struct V_56 V_57 = {
. V_58 = 1 ,
. V_59 = & V_49 ,
. V_60 = & V_61 ,
} ;
struct V_32 * V_33 ;
V_33 = F_30 ( sizeof( * V_33 ) , V_51 ) ;
if ( ! V_33 )
continue;
V_33 -> V_29 . V_57 = & V_57 ;
V_33 -> V_11 = V_11 ;
V_33 -> V_44 = V_44 ;
if ( V_50 == 1 )
V_33 -> V_40 = 8 ;
else
V_33 -> V_40 = 20 ;
if ( F_33 ( V_10 , L_4 ,
V_50 , & V_57 . V_23 ) )
V_57 . V_23 = V_10 -> V_23 ;
V_48 -> V_52 [ V_50 ] = F_34 ( NULL , & V_33 -> V_29 ) ;
if ( F_9 ( V_48 -> V_52 [ V_50 ] ) ) {
F_35 ( V_33 ) ;
continue;
}
}
F_36 ( V_10 , V_62 , V_48 ) ;
return;
V_55:
F_35 ( V_48 -> V_52 ) ;
V_53:
F_35 ( V_48 ) ;
}
static void T_3 F_37 ( struct V_9 * V_10 )
{
F_29 ( V_10 , & V_12 , & V_63 ) ;
}
static void T_3 F_38 ( struct V_9 * V_10 )
{
F_29 ( V_10 , & V_24 , & V_64 ) ;
}

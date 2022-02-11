static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 () ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ ) {
struct V_7 * V_8 = & V_4 -> V_9 [ V_5 ] ;
const struct V_10 * V_11 =
V_8 -> V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_3 ( V_11 -> V_13 ) ; V_12 ++ ) {
if ( V_11 -> V_13 [ V_12 ] == V_2 -> V_14 )
break;
}
if ( V_12 == F_3 ( V_11 -> V_13 ) )
continue;
V_2 -> V_15 =
V_4 -> V_16 + V_11 -> V_17 + F_4 ( V_12 ) ;
F_5 ( V_2 , V_8 -> V_18 ) ;
}
V_2 -> V_19 . V_20 = 300 * 1000 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
struct V_22 * V_23 = V_2 -> V_24 + V_21 ;
void T_1 * V_25 = V_2 -> V_15 ;
T_2 V_26 = V_23 -> V_15 ;
F_7 ( V_26 , V_25 ) ;
return 0 ;
}
static struct V_22 * F_8 (
struct V_27 * V_28 , struct V_29 * V_30 ,
unsigned int V_31 )
{
struct V_22 * V_18 ;
struct V_32 V_33 ;
struct V_34 V_35 ;
struct V_36 * V_4 ;
int V_37 , V_5 , V_38 , V_39 = 0 ;
T_3 V_40 ;
void * V_41 ;
V_41 = F_9 ( V_30 -> V_42 , sizeof( * V_4 ) , & V_40 ,
V_43 | V_44 ) ;
if ( ! V_41 )
return F_10 ( - V_45 ) ;
V_4 = (struct V_36 * ) V_41 ;
memset ( & V_33 , 0 , sizeof( V_33 ) ) ;
V_33 . V_46 = V_40 ;
V_33 . V_31 = V_31 ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_47 = V_48 ;
V_35 . V_49 . V_4 = & V_33 ;
V_35 . V_49 . V_50 = sizeof( V_33 ) ;
V_37 = F_11 ( V_30 , & V_35 ) ;
if ( V_37 ) {
V_18 = F_10 ( V_37 ) ;
goto free;
}
for ( V_5 = V_4 -> V_51 ; V_5 <= V_4 -> V_52 ; V_5 ++ ) {
T_4 V_53 = V_4 -> V_53 [ V_5 ] ;
if ( V_53 < V_4 -> V_54 || V_53 > V_4 -> V_55 )
continue;
if ( V_5 > 0 && V_53 == V_4 -> V_53 [ V_5 - 1 ] )
continue;
V_39 ++ ;
}
V_18 = F_12 ( & V_28 -> V_42 , V_39 + 1 , sizeof( * V_18 ) ,
V_43 ) ;
if ( ! V_18 ) {
V_18 = F_10 ( - V_45 ) ;
goto free;
}
for ( V_5 = V_4 -> V_51 , V_38 = 0 ; V_5 <= V_4 -> V_52 ; V_5 ++ ) {
struct V_22 * V_56 ;
T_4 V_53 = V_4 -> V_53 [ V_5 ] ;
T_2 V_26 = 0 ;
if ( V_53 < V_4 -> V_54 || V_53 > V_4 -> V_55 )
continue;
if ( V_5 > 0 && V_53 == V_4 -> V_53 [ V_5 - 1 ] )
continue;
V_26 |= V_5 << V_57 ;
V_26 |= V_53 << V_58 ;
V_56 = & V_18 [ V_38 ++ ] ;
V_56 -> V_15 = V_26 ;
V_56 -> V_59 = V_4 -> V_60 * V_53 / V_4 -> V_61 /
V_4 -> V_62 / 1000 ;
}
V_18 [ V_38 ] . V_59 = V_63 ;
free:
F_13 ( V_30 -> V_42 , sizeof( * V_4 ) , V_41 , V_40 ) ;
return V_18 ;
}
static int F_14 ( struct V_27 * V_28 )
{
struct V_3 * V_4 ;
struct V_29 * V_30 ;
struct V_64 * V_65 ;
unsigned int V_5 = 0 , V_37 ;
V_4 = F_15 ( & V_28 -> V_42 , sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return - V_45 ;
V_4 -> V_9 = F_12 ( & V_28 -> V_42 , F_3 ( V_66 ) ,
sizeof( * V_4 -> V_9 ) , V_43 ) ;
if ( ! V_4 -> V_9 )
return - V_45 ;
V_4 -> V_6 = F_3 ( V_66 ) ;
V_30 = F_16 ( & V_28 -> V_42 ) ;
if ( F_17 ( V_30 ) )
return F_18 ( V_30 ) ;
V_65 = F_19 ( V_28 , V_67 , 0 ) ;
V_4 -> V_16 = F_20 ( & V_28 -> V_42 , V_65 ) ;
if ( F_17 ( V_4 -> V_16 ) ) {
V_37 = F_18 ( V_4 -> V_16 ) ;
goto V_68;
}
for ( V_5 = 0 ; V_5 < V_4 -> V_6 ; V_5 ++ ) {
struct V_7 * V_8 = & V_4 -> V_9 [ V_5 ] ;
V_8 -> V_11 = & V_66 [ V_5 ] ;
V_8 -> V_18 = F_8 (
V_28 , V_30 , V_8 -> V_11 -> V_69 ) ;
if ( F_17 ( V_8 -> V_18 ) ) {
V_37 = F_18 ( V_8 -> V_18 ) ;
goto V_68;
}
}
F_21 ( V_30 ) ;
V_70 . V_15 = V_4 ;
V_37 = F_22 ( & V_70 ) ;
if ( V_37 )
return V_37 ;
return 0 ;
V_68:
F_21 ( V_30 ) ;
return V_37 ;
}
static int F_23 ( struct V_27 * V_28 )
{
F_24 ( & V_70 ) ;
return 0 ;
}

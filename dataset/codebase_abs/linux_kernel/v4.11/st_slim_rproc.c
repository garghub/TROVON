static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 , V_6 ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_2 -> V_8 [ V_5 ] = F_2 ( V_4 -> V_9 , V_5 ) ;
if ( F_3 ( V_2 -> V_8 [ V_5 ] ) ) {
V_6 = F_4 ( V_2 -> V_8 [ V_5 ] ) ;
if ( V_6 == - V_10 )
goto V_11;
V_2 -> V_8 [ V_5 ] = NULL ;
break;
}
}
return 0 ;
V_11:
while ( -- V_5 >= 0 )
F_5 ( V_2 -> V_8 [ V_5 ] ) ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_7 && V_2 -> V_8 [ V_5 ] ; V_5 ++ )
F_7 ( V_2 -> V_8 [ V_5 ] ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_5 , V_12 ;
for ( V_5 = 0 ; V_5 < V_7 && V_2 -> V_8 [ V_5 ] ; V_5 ++ ) {
V_12 = F_9 ( V_2 -> V_8 [ V_5 ] ) ;
if ( V_12 )
goto V_13;
}
return 0 ;
V_13:
while ( -- V_5 >= 0 )
F_7 ( V_2 -> V_8 [ V_5 ] ) ;
return V_12 ;
}
static int F_10 ( struct V_14 * V_14 )
{
struct V_3 * V_4 = & V_14 -> V_4 ;
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_16 , V_17 , V_18 ;
T_1 V_19 ;
V_19 = V_20 | V_21 ;
F_11 ( V_19 , V_2 -> V_22 + V_23 ) ;
F_11 ( V_24 , V_2 -> V_25 + V_26 ) ;
F_11 ( ! V_20 ,
V_2 -> V_22 + V_23 ) ;
F_11 ( ~ 0U , V_2 -> V_25 + V_27 ) ;
F_11 ( ~ 0U , V_2 -> V_25 + V_28 ) ;
F_11 ( ~ 0U , V_2 -> V_25 + V_29 ) ;
F_11 ( ~ 0U , V_2 -> V_25 + V_30 ) ;
F_11 ( V_31 , V_2 -> V_22 + V_32 ) ;
V_16 = F_12 ( V_2 -> V_22 + V_33 ) ;
V_17 = F_12 ( V_2 -> V_22 + V_34 ) ;
V_18 = F_13 ( V_2 -> V_35 [ V_36 ] . V_37 +
V_38 ) ;
F_14 ( V_4 , L_1 ,
F_15 ( V_18 ) , F_16 ( V_18 ) ,
V_16 , V_17 ) ;
return 0 ;
}
static int F_17 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_19 ;
F_11 ( 0UL , V_2 -> V_25 + V_29 ) ;
F_11 ( 0UL , V_2 -> V_25 + V_30 ) ;
F_11 ( V_20 , V_2 -> V_22 + V_23 ) ;
F_11 ( ! V_31 , V_2 -> V_22 + V_32 ) ;
V_19 = F_13 ( V_2 -> V_22 + V_32 ) ;
if ( V_19 & V_31 )
F_18 ( & V_14 -> V_4 , L_2 ) ;
F_19 ( & V_14 -> V_4 , L_3 ) ;
return 0 ;
}
static void * F_20 ( struct V_14 * V_14 , T_2 V_39 , int V_40 )
{
struct V_1 * V_2 = V_14 -> V_15 ;
void * V_41 = NULL ;
int V_42 ;
for ( V_42 = 0 ; V_42 < V_43 ; V_42 ++ ) {
if ( V_39 != V_2 -> V_35 [ V_42 ] . V_44 )
continue;
if ( V_40 <= V_2 -> V_35 [ V_42 ] . V_45 ) {
V_41 = ( V_46 void * ) V_2 -> V_35 [ V_42 ] . V_37 ;
break;
}
}
F_19 ( & V_14 -> V_4 , L_4 , V_39 , V_40 , V_41 ) ;
return V_41 ;
}
static struct V_47 * F_21 ( struct V_14 * V_14 ,
const struct V_48 * V_49 ,
int * V_50 )
{
* V_50 = sizeof( V_51 ) ;
return & V_51 ;
}
struct V_1 * F_22 ( struct V_52 * V_53 ,
char * V_54 )
{
struct V_3 * V_4 = & V_53 -> V_4 ;
struct V_1 * V_2 ;
struct V_55 * V_56 = V_4 -> V_9 ;
struct V_14 * V_14 ;
struct V_57 * V_58 ;
int V_6 , V_42 ;
const struct V_59 * V_60 ;
if ( ! V_54 )
return F_23 ( - V_61 ) ;
if ( ! F_24 ( V_56 , L_5 ) )
return F_23 ( - V_61 ) ;
V_14 = F_25 ( V_4 , V_56 -> V_62 , & V_63 ,
V_54 , sizeof( * V_2 ) ) ;
if ( ! V_14 )
return F_23 ( - V_64 ) ;
V_14 -> V_65 = false ;
V_2 = V_14 -> V_15 ;
V_2 -> V_14 = V_14 ;
V_60 = V_14 -> V_66 ;
V_67 . V_68 = V_60 -> V_68 ;
V_67 . V_69 = V_60 -> V_69 ;
V_14 -> V_66 = & V_67 ;
for ( V_42 = 0 ; V_42 < F_26 ( V_70 ) ; V_42 ++ ) {
V_58 = F_27 ( V_53 , V_71 ,
V_70 [ V_42 ] ) ;
V_2 -> V_35 [ V_42 ] . V_37 = F_28 ( V_4 , V_58 ) ;
if ( F_3 ( V_2 -> V_35 [ V_42 ] . V_37 ) ) {
F_29 ( & V_53 -> V_4 , L_6 ) ;
V_6 = F_4 ( V_2 -> V_35 [ V_42 ] . V_37 ) ;
goto V_6;
}
V_2 -> V_35 [ V_42 ] . V_44 = V_58 -> V_72 ;
V_2 -> V_35 [ V_42 ] . V_45 = F_30 ( V_58 ) ;
}
V_58 = F_27 ( V_53 , V_71 , L_7 ) ;
V_2 -> V_22 = F_28 ( V_4 , V_58 ) ;
if ( F_3 ( V_2 -> V_22 ) ) {
F_29 ( & V_53 -> V_4 , L_8 ) ;
V_6 = F_4 ( V_2 -> V_22 ) ;
goto V_6;
}
V_58 = F_27 ( V_53 , V_71 , L_9 ) ;
V_2 -> V_25 = F_28 ( V_4 , V_58 ) ;
if ( F_3 ( V_2 -> V_25 ) ) {
F_29 ( & V_53 -> V_4 , L_10 ) ;
V_6 = F_4 ( V_2 -> V_25 ) ;
goto V_6;
}
V_6 = F_1 ( V_2 , V_4 ) ;
if ( V_6 )
goto V_6;
V_6 = F_8 ( V_2 ) ;
if ( V_6 ) {
F_29 ( V_4 , L_11 ) ;
goto V_73;
}
V_6 = F_31 ( V_14 ) ;
if ( V_6 ) {
F_29 ( V_4 , L_12 ) ;
goto V_74;
}
return V_2 ;
V_74:
F_6 ( V_2 ) ;
V_73:
for ( V_42 = 0 ; V_42 < V_7 && V_2 -> V_8 [ V_42 ] ; V_42 ++ )
F_5 ( V_2 -> V_8 [ V_42 ] ) ;
V_6:
F_32 ( V_14 ) ;
return F_23 ( V_6 ) ;
}
void F_33 ( struct V_1 * V_2 )
{
int V_5 ;
if ( ! V_2 )
return;
F_6 ( V_2 ) ;
for ( V_5 = 0 ; V_5 < V_7 && V_2 -> V_8 [ V_5 ] ; V_5 ++ )
F_5 ( V_2 -> V_8 [ V_5 ] ) ;
F_34 ( V_2 -> V_14 ) ;
F_32 ( V_2 -> V_14 ) ;
}

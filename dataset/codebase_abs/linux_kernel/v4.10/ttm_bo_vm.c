static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
if ( F_2 ( ! V_2 -> V_8 ) )
goto V_9;
if ( F_3 ( V_2 -> V_8 ) )
goto V_10;
if ( V_6 -> V_11 & V_12 ) {
V_7 = V_13 ;
if ( V_6 -> V_11 & V_14 )
goto V_9;
F_4 ( & V_4 -> V_15 -> V_16 ) ;
( void ) F_5 ( V_2 -> V_8 , true ) ;
goto V_9;
}
V_7 = F_5 ( V_2 -> V_8 , true ) ;
if ( F_6 ( V_7 != 0 ) ) {
V_7 = ( V_7 != - V_17 ) ? V_18 :
V_19 ;
goto V_9;
}
V_10:
F_7 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
V_9:
return V_7 ;
}
static int F_8 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_2 = (struct V_1 * )
V_4 -> V_20 ;
struct V_21 * V_22 = V_2 -> V_22 ;
unsigned long V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
struct V_26 * V_27 = NULL ;
struct V_28 * V_28 ;
int V_7 ;
int V_29 ;
unsigned long V_30 = V_6 -> V_30 ;
int V_31 = V_19 ;
struct V_32 * V_33 =
& V_22 -> V_33 [ V_2 -> V_34 . V_35 ] ;
struct V_3 V_36 ;
V_7 = F_9 ( V_2 , true , true , NULL ) ;
if ( F_6 ( V_7 != 0 ) ) {
if ( V_7 != - V_37 )
return V_19 ;
if ( V_6 -> V_11 & V_12 ) {
if ( ! ( V_6 -> V_11 & V_14 ) ) {
F_4 ( & V_4 -> V_15 -> V_16 ) ;
( void ) F_10 ( V_2 ) ;
}
return V_13 ;
}
return V_19 ;
}
if ( V_2 -> V_27 && ( V_2 -> V_27 -> V_38 & V_39 ) ) {
V_31 = V_18 ;
goto V_9;
}
if ( V_22 -> V_40 -> V_41 ) {
V_7 = V_22 -> V_40 -> V_41 ( V_2 ) ;
switch ( V_7 ) {
case 0 :
break;
case - V_37 :
case - V_17 :
V_31 = V_19 ;
goto V_9;
default:
V_31 = V_18 ;
goto V_9;
}
}
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( F_6 ( V_7 != 0 ) ) {
V_31 = V_7 ;
goto V_9;
}
V_7 = F_11 ( V_33 , true ) ;
if ( F_6 ( V_7 != 0 ) ) {
V_31 = V_19 ;
goto V_9;
}
V_7 = F_12 ( V_2 ) ;
if ( F_6 ( V_7 != 0 ) ) {
V_31 = V_18 ;
goto V_42;
}
V_23 = ( ( V_30 - V_4 -> V_43 ) >> V_44 ) +
V_4 -> V_45 - F_13 ( & V_2 -> V_46 ) ;
V_24 = F_14 ( V_4 ) + V_4 -> V_45 -
F_13 ( & V_2 -> V_46 ) ;
if ( F_6 ( V_23 >= V_2 -> V_47 ) ) {
V_31 = V_18 ;
goto V_42;
}
V_36 = * V_4 ;
V_36 . V_48 = F_15 ( V_36 . V_49 ) ;
if ( V_2 -> V_34 . V_50 . V_51 ) {
V_36 . V_48 = F_16 ( V_2 -> V_34 . V_52 ,
V_36 . V_48 ) ;
} else {
V_27 = V_2 -> V_27 ;
V_36 . V_48 = F_16 ( V_2 -> V_34 . V_52 ,
V_36 . V_48 ) ;
if ( V_27 -> V_22 -> V_40 -> V_53 ( V_27 ) ) {
V_31 = V_54 ;
goto V_42;
}
}
for ( V_29 = 0 ; V_29 < V_55 ; ++ V_29 ) {
if ( V_2 -> V_34 . V_50 . V_51 )
V_25 = ( ( V_2 -> V_34 . V_50 . V_56 + V_2 -> V_34 . V_50 . V_57 ) >> V_44 ) + V_23 ;
else {
V_28 = V_27 -> V_58 [ V_23 ] ;
if ( F_6 ( ! V_28 && V_29 == 0 ) ) {
V_31 = V_54 ;
goto V_42;
} else if ( F_6 ( ! V_28 ) ) {
break;
}
V_28 -> V_59 = V_4 -> V_60 -> V_61 ;
V_28 -> V_62 = F_13 ( & V_2 -> V_46 ) +
V_23 ;
V_25 = F_17 ( V_28 ) ;
}
if ( V_4 -> V_49 & V_63 )
V_7 = F_18 ( & V_36 , V_30 ,
F_19 ( V_25 , V_64 ) ) ;
else
V_7 = F_20 ( & V_36 , V_30 , V_25 ) ;
if ( F_6 ( ( V_7 == - V_37 ) || ( V_7 != 0 && V_29 > 0 ) ) )
break;
else if ( F_6 ( V_7 != 0 ) ) {
V_31 =
( V_7 == - V_65 ) ? V_54 : V_18 ;
goto V_42;
}
V_30 += V_66 ;
if ( F_6 ( ++ V_23 >= V_24 ) )
break;
}
V_42:
F_21 ( V_33 ) ;
V_9:
F_22 ( V_2 ) ;
return V_31 ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_4 -> V_20 ;
F_24 ( V_2 -> V_22 -> V_67 != V_4 -> V_60 -> V_61 ) ;
( void ) F_25 ( V_2 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_20 ;
F_27 ( & V_2 ) ;
V_4 -> V_20 = NULL ;
}
static struct V_1 * F_28 ( struct V_21 * V_22 ,
unsigned long V_57 ,
unsigned long V_58 )
{
struct V_68 * V_69 ;
struct V_1 * V_2 = NULL ;
F_29 ( & V_22 -> V_70 ) ;
V_69 = F_30 ( & V_22 -> V_70 , V_57 , V_58 ) ;
if ( F_2 ( V_69 ) ) {
V_2 = F_31 ( V_69 , struct V_1 , V_46 ) ;
if ( ! F_32 ( & V_2 -> V_71 ) )
V_2 = NULL ;
}
F_33 ( & V_22 -> V_70 ) ;
if ( ! V_2 )
F_34 ( L_1 ) ;
return V_2 ;
}
int F_35 ( struct V_72 * V_73 , struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_74 * V_40 ;
struct V_1 * V_2 ;
int V_7 ;
V_2 = F_28 ( V_22 , V_4 -> V_45 , F_14 ( V_4 ) ) ;
if ( F_6 ( ! V_2 ) )
return - V_75 ;
V_40 = V_2 -> V_22 -> V_40 ;
if ( F_6 ( ! V_40 -> V_76 ) ) {
V_7 = - V_77 ;
goto V_78;
}
V_7 = V_40 -> V_76 ( V_2 , V_73 ) ;
if ( F_6 ( V_7 != 0 ) )
goto V_78;
V_4 -> V_79 = & V_80 ;
V_4 -> V_20 = V_2 ;
V_4 -> V_49 |= V_63 ;
V_4 -> V_49 |= V_81 | V_82 | V_83 ;
return 0 ;
V_78:
F_27 ( & V_2 ) ;
return V_7 ;
}
int F_36 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
if ( V_4 -> V_45 != 0 )
return - V_84 ;
V_4 -> V_79 = & V_80 ;
V_4 -> V_20 = F_25 ( V_2 ) ;
V_4 -> V_49 |= V_63 ;
V_4 -> V_49 |= V_81 | V_82 ;
return 0 ;
}

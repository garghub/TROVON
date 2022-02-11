static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
if ( F_2 ( ! V_2 -> V_6 ) )
goto V_7;
if ( F_3 ( V_2 -> V_6 ) )
goto V_8;
if ( V_4 -> V_9 & V_10 ) {
V_5 = V_11 ;
if ( V_4 -> V_9 & V_12 )
goto V_7;
F_4 ( V_2 ) ;
F_5 ( & V_4 -> V_13 -> V_14 -> V_15 ) ;
( void ) F_6 ( V_2 -> V_6 , true ) ;
F_7 ( V_2 ) ;
F_8 ( & V_2 ) ;
goto V_7;
}
V_5 = F_6 ( V_2 -> V_6 , true ) ;
if ( F_9 ( V_5 != 0 ) ) {
V_5 = ( V_5 != - V_16 ) ? V_17 :
V_18 ;
goto V_7;
}
V_8:
F_10 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
V_7:
return V_5 ;
}
static int F_11 ( struct V_3 * V_4 )
{
struct V_19 * V_13 = V_4 -> V_13 ;
struct V_1 * V_2 = (struct V_1 * )
V_13 -> V_20 ;
struct V_21 * V_22 = V_2 -> V_22 ;
unsigned long V_23 ;
unsigned long V_24 ;
unsigned long V_25 ;
struct V_26 * V_27 = NULL ;
struct V_28 * V_28 ;
int V_5 ;
int V_29 ;
unsigned long V_30 = V_4 -> V_30 ;
int V_31 = V_18 ;
struct V_32 * V_33 =
& V_22 -> V_33 [ V_2 -> V_34 . V_35 ] ;
struct V_19 V_36 ;
V_5 = F_12 ( V_2 , true , true , NULL ) ;
if ( F_9 ( V_5 != 0 ) ) {
if ( V_5 != - V_37 )
return V_18 ;
if ( V_4 -> V_9 & V_10 ) {
if ( ! ( V_4 -> V_9 & V_12 ) ) {
F_4 ( V_2 ) ;
F_5 ( & V_4 -> V_13 -> V_14 -> V_15 ) ;
( void ) F_13 ( V_2 ) ;
F_8 ( & V_2 ) ;
}
return V_11 ;
}
return V_18 ;
}
if ( V_2 -> V_27 && ( V_2 -> V_27 -> V_38 & V_39 ) ) {
V_31 = V_17 ;
goto V_7;
}
if ( V_22 -> V_40 -> V_41 ) {
V_5 = V_22 -> V_40 -> V_41 ( V_2 ) ;
switch ( V_5 ) {
case 0 :
break;
case - V_37 :
case - V_16 :
V_31 = V_18 ;
goto V_7;
default:
V_31 = V_17 ;
goto V_7;
}
}
V_5 = F_1 ( V_2 , V_4 ) ;
if ( F_9 ( V_5 != 0 ) ) {
V_31 = V_5 ;
if ( V_31 == V_11 &&
! ( V_4 -> V_9 & V_12 ) ) {
return V_31 ;
}
goto V_7;
}
V_5 = F_14 ( V_33 , true ) ;
if ( F_9 ( V_5 != 0 ) ) {
V_31 = V_18 ;
goto V_7;
}
V_5 = F_15 ( V_2 ) ;
if ( F_9 ( V_5 != 0 ) ) {
V_31 = V_17 ;
goto V_42;
}
V_23 = ( ( V_30 - V_13 -> V_43 ) >> V_44 ) +
V_13 -> V_45 - F_16 ( & V_2 -> V_46 ) ;
V_24 = F_17 ( V_13 ) + V_13 -> V_45 -
F_16 ( & V_2 -> V_46 ) ;
if ( F_9 ( V_23 >= V_2 -> V_47 ) ) {
V_31 = V_17 ;
goto V_42;
}
V_36 = * V_13 ;
V_36 . V_48 = F_18 ( V_36 . V_49 ) ;
if ( V_2 -> V_34 . V_50 . V_51 ) {
V_36 . V_48 = F_19 ( V_2 -> V_34 . V_52 ,
V_36 . V_48 ) ;
} else {
V_27 = V_2 -> V_27 ;
V_36 . V_48 = F_19 ( V_2 -> V_34 . V_52 ,
V_36 . V_48 ) ;
if ( V_27 -> V_22 -> V_40 -> V_53 ( V_27 ) ) {
V_31 = V_54 ;
goto V_42;
}
}
for ( V_29 = 0 ; V_29 < V_55 ; ++ V_29 ) {
if ( V_2 -> V_34 . V_50 . V_51 )
V_25 = V_22 -> V_40 -> V_56 ( V_2 , V_23 ) ;
else {
V_28 = V_27 -> V_57 [ V_23 ] ;
if ( F_9 ( ! V_28 && V_29 == 0 ) ) {
V_31 = V_54 ;
goto V_42;
} else if ( F_9 ( ! V_28 ) ) {
break;
}
V_28 -> V_58 = V_13 -> V_59 -> V_60 ;
V_28 -> V_61 = F_16 ( & V_2 -> V_46 ) +
V_23 ;
V_25 = F_20 ( V_28 ) ;
}
if ( V_13 -> V_49 & V_62 )
V_5 = F_21 ( & V_36 , V_30 ,
F_22 ( V_25 , V_63 ) ) ;
else
V_5 = F_23 ( & V_36 , V_30 , V_25 ) ;
if ( F_9 ( ( V_5 == - V_37 ) || ( V_5 != 0 && V_29 > 0 ) ) )
break;
else if ( F_9 ( V_5 != 0 ) ) {
V_31 =
( V_5 == - V_64 ) ? V_54 : V_17 ;
goto V_42;
}
V_30 += V_65 ;
if ( F_9 ( ++ V_23 >= V_24 ) )
break;
}
V_42:
F_24 ( V_33 ) ;
V_7:
F_7 ( V_2 ) ;
return V_31 ;
}
static void F_25 ( struct V_19 * V_13 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_13 -> V_20 ;
F_26 ( V_2 -> V_22 -> V_66 != V_13 -> V_59 -> V_60 ) ;
( void ) F_4 ( V_2 ) ;
}
static void F_27 ( struct V_19 * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_20 ;
F_8 ( & V_2 ) ;
V_13 -> V_20 = NULL ;
}
static struct V_1 * F_28 ( struct V_21 * V_22 ,
unsigned long V_67 ,
unsigned long V_57 )
{
struct V_68 * V_69 ;
struct V_1 * V_2 = NULL ;
F_29 ( & V_22 -> V_70 ) ;
V_69 = F_30 ( & V_22 -> V_70 , V_67 , V_57 ) ;
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
unsigned long F_35 ( struct V_1 * V_2 ,
unsigned long V_23 )
{
return ( ( V_2 -> V_34 . V_50 . V_72 + V_2 -> V_34 . V_50 . V_67 ) >> V_44 )
+ V_23 ;
}
int F_36 ( struct V_73 * V_74 , struct V_19 * V_13 ,
struct V_21 * V_22 )
{
struct V_75 * V_40 ;
struct V_1 * V_2 ;
int V_5 ;
V_2 = F_28 ( V_22 , V_13 -> V_45 , F_17 ( V_13 ) ) ;
if ( F_9 ( ! V_2 ) )
return - V_76 ;
V_40 = V_2 -> V_22 -> V_40 ;
if ( F_9 ( ! V_40 -> V_77 ) ) {
V_5 = - V_78 ;
goto V_79;
}
V_5 = V_40 -> V_77 ( V_2 , V_74 ) ;
if ( F_9 ( V_5 != 0 ) )
goto V_79;
V_13 -> V_80 = & V_81 ;
V_13 -> V_20 = V_2 ;
V_13 -> V_49 |= V_62 ;
V_13 -> V_49 |= V_82 | V_83 | V_84 ;
return 0 ;
V_79:
F_8 ( & V_2 ) ;
return V_5 ;
}
int F_37 ( struct V_19 * V_13 , struct V_1 * V_2 )
{
if ( V_13 -> V_45 != 0 )
return - V_85 ;
V_13 -> V_80 = & V_81 ;
V_13 -> V_20 = F_4 ( V_2 ) ;
V_13 -> V_49 |= V_62 ;
V_13 -> V_49 |= V_82 | V_83 ;
return 0 ;
}

static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * )
V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
unsigned long V_10 ;
unsigned long V_11 ;
unsigned long V_12 ;
struct V_13 * V_14 = NULL ;
struct V_15 * V_15 ;
int V_16 ;
int V_17 ;
unsigned long V_18 = ( unsigned long ) V_4 -> V_19 ;
int V_20 = V_21 ;
struct V_22 * V_23 =
& V_9 -> V_23 [ V_6 -> V_24 . V_25 ] ;
V_16 = F_2 ( V_6 , true , true , false , 0 ) ;
if ( F_3 ( V_16 != 0 ) ) {
if ( V_16 == - V_26 )
F_4 () ;
return V_21 ;
}
if ( V_9 -> V_27 -> V_28 ) {
V_16 = V_9 -> V_27 -> V_28 ( V_6 ) ;
switch ( V_16 ) {
case 0 :
break;
case - V_26 :
F_4 () ;
case - V_29 :
V_20 = V_21 ;
goto V_30;
default:
V_20 = V_31 ;
goto V_30;
}
}
F_5 ( & V_9 -> V_32 ) ;
if ( F_6 ( V_33 , & V_6 -> V_34 ) ) {
V_16 = F_7 ( V_6 , false , true , false ) ;
F_8 ( & V_9 -> V_32 ) ;
if ( F_3 ( V_16 != 0 ) ) {
V_20 = ( V_16 != - V_29 ) ?
V_31 : V_21 ;
goto V_30;
}
} else
F_8 ( & V_9 -> V_32 ) ;
V_16 = F_9 ( V_23 , true ) ;
if ( F_3 ( V_16 != 0 ) ) {
V_20 = V_21 ;
goto V_30;
}
V_16 = F_10 ( V_6 ) ;
if ( F_3 ( V_16 != 0 ) ) {
V_20 = V_31 ;
goto V_35;
}
V_10 = ( ( V_18 - V_2 -> V_36 ) >> V_37 ) +
F_11 ( & V_6 -> V_38 ) - V_2 -> V_39 ;
V_11 = F_12 ( V_2 ) +
F_11 ( & V_6 -> V_38 ) - V_2 -> V_39 ;
if ( F_3 ( V_10 >= V_6 -> V_40 ) ) {
V_20 = V_31 ;
goto V_35;
}
if ( V_6 -> V_24 . V_41 . V_42 ) {
V_2 -> V_43 = F_13 ( V_6 -> V_24 . V_44 ,
V_2 -> V_43 ) ;
} else {
V_14 = V_6 -> V_14 ;
V_2 -> V_43 = ( V_6 -> V_24 . V_44 & V_45 ) ?
F_14 ( V_2 -> V_46 ) :
F_13 ( V_6 -> V_24 . V_44 , V_2 -> V_43 ) ;
if ( V_14 -> V_9 -> V_27 -> V_47 ( V_14 ) ) {
V_20 = V_48 ;
goto V_35;
}
}
for ( V_17 = 0 ; V_17 < V_49 ; ++ V_17 ) {
if ( V_6 -> V_24 . V_41 . V_42 )
V_12 = ( ( V_6 -> V_24 . V_41 . V_50 + V_6 -> V_24 . V_41 . V_51 ) >> V_37 ) + V_10 ;
else {
V_15 = V_14 -> V_52 [ V_10 ] ;
if ( F_3 ( ! V_15 && V_17 == 0 ) ) {
V_20 = V_48 ;
goto V_35;
} else if ( F_3 ( ! V_15 ) ) {
break;
}
V_12 = F_15 ( V_15 ) ;
}
V_16 = F_16 ( V_2 , V_18 , V_12 ) ;
if ( F_3 ( ( V_16 == - V_26 ) || ( V_16 != 0 && V_17 > 0 ) ) )
break;
else if ( F_3 ( V_16 != 0 ) ) {
V_20 =
( V_16 == - V_53 ) ? V_48 : V_31 ;
goto V_35;
}
V_18 += V_54 ;
if ( F_3 ( ++ V_10 >= V_11 ) )
break;
}
V_35:
F_17 ( V_23 ) ;
V_30:
F_18 ( V_6 ) ;
return V_20 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 =
(struct V_5 * ) V_2 -> V_7 ;
( void ) F_20 ( V_6 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
F_22 ( & V_6 ) ;
V_2 -> V_7 = NULL ;
}
static struct V_5 * F_23 ( struct V_8 * V_9 ,
unsigned long V_51 ,
unsigned long V_52 )
{
struct V_55 * V_56 ;
struct V_5 * V_6 = NULL ;
F_24 ( & V_9 -> V_57 ) ;
V_56 = F_25 ( & V_9 -> V_57 , V_51 , V_52 ) ;
if ( F_26 ( V_56 ) ) {
V_6 = F_27 ( V_56 , struct V_5 , V_38 ) ;
if ( ! F_28 ( & V_6 -> V_58 ) )
V_6 = NULL ;
}
F_29 ( & V_9 -> V_57 ) ;
if ( ! V_6 )
F_30 ( L_1 ) ;
return V_6 ;
}
int F_31 ( struct V_59 * V_60 , struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_61 * V_27 ;
struct V_5 * V_6 ;
int V_16 ;
V_6 = F_23 ( V_9 , V_2 -> V_39 , F_12 ( V_2 ) ) ;
if ( F_3 ( ! V_6 ) )
return - V_62 ;
V_27 = V_6 -> V_9 -> V_27 ;
if ( F_3 ( ! V_27 -> V_63 ) ) {
V_16 = - V_64 ;
goto V_65;
}
V_16 = V_27 -> V_63 ( V_6 , V_60 ) ;
if ( F_3 ( V_16 != 0 ) )
goto V_65;
V_2 -> V_66 = & V_67 ;
V_2 -> V_7 = V_6 ;
V_2 -> V_46 |= V_68 | V_69 | V_70 | V_71 ;
return 0 ;
V_65:
F_22 ( & V_6 ) ;
return V_16 ;
}
int F_32 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
if ( V_2 -> V_39 != 0 )
return - V_72 ;
V_2 -> V_66 = & V_67 ;
V_2 -> V_7 = F_20 ( V_6 ) ;
V_2 -> V_46 |= V_68 | V_69 | V_70 ;
return 0 ;
}

static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 = 0 ;
if ( F_2 ( ! F_3 ( V_8 , & V_2 -> V_9 ) ) )
goto V_10;
V_7 = F_4 ( V_2 , false , false , true ) ;
if ( F_2 ( V_7 == 0 ) )
goto V_10;
if ( V_6 -> V_11 & V_12 ) {
V_7 = V_13 ;
if ( V_6 -> V_11 & V_14 )
goto V_10;
F_5 ( & V_4 -> V_15 -> V_16 ) ;
( void ) F_4 ( V_2 , false , true , false ) ;
goto V_10;
}
V_7 = F_4 ( V_2 , false , true , false ) ;
if ( F_6 ( V_7 != 0 ) )
V_7 = ( V_7 != - V_17 ) ? V_18 :
V_19 ;
V_10:
return V_7 ;
}
static int F_7 ( struct V_3 * V_4 , struct V_5 * V_6 )
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
unsigned long V_30 = ( unsigned long ) V_6 -> V_31 ;
int V_32 = V_19 ;
struct V_33 * V_34 =
& V_22 -> V_34 [ V_2 -> V_35 . V_36 ] ;
struct V_3 V_37 ;
V_7 = F_8 ( V_2 , true , true , false , NULL ) ;
if ( F_6 ( V_7 != 0 ) ) {
if ( V_7 != - V_38 )
return V_19 ;
if ( V_6 -> V_11 & V_12 ) {
if ( ! ( V_6 -> V_11 & V_14 ) ) {
F_5 ( & V_4 -> V_15 -> V_16 ) ;
( void ) F_9 ( V_2 ) ;
}
return V_13 ;
}
return V_19 ;
}
if ( V_2 -> V_27 && ( V_2 -> V_27 -> V_39 & V_40 ) ) {
V_32 = V_18 ;
goto V_10;
}
if ( V_22 -> V_41 -> V_42 ) {
V_7 = V_22 -> V_41 -> V_42 ( V_2 ) ;
switch ( V_7 ) {
case 0 :
break;
case - V_38 :
case - V_17 :
V_32 = V_19 ;
goto V_10;
default:
V_32 = V_18 ;
goto V_10;
}
}
V_7 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( F_6 ( V_7 != 0 ) ) {
V_32 = V_7 ;
goto V_10;
}
V_7 = F_10 ( V_34 , true ) ;
if ( F_6 ( V_7 != 0 ) ) {
V_32 = V_19 ;
goto V_10;
}
V_7 = F_11 ( V_2 ) ;
if ( F_6 ( V_7 != 0 ) ) {
V_32 = V_18 ;
goto V_43;
}
V_23 = ( ( V_30 - V_4 -> V_44 ) >> V_45 ) +
V_4 -> V_46 - F_12 ( & V_2 -> V_47 ) ;
V_24 = F_13 ( V_4 ) + V_4 -> V_46 -
F_12 ( & V_2 -> V_47 ) ;
if ( F_6 ( V_23 >= V_2 -> V_48 ) ) {
V_32 = V_18 ;
goto V_43;
}
V_37 = * V_4 ;
V_37 . V_49 = F_14 ( V_37 . V_50 ) ;
if ( V_2 -> V_35 . V_51 . V_52 ) {
V_37 . V_49 = F_15 ( V_2 -> V_35 . V_53 ,
V_37 . V_49 ) ;
} else {
V_27 = V_2 -> V_27 ;
V_37 . V_49 = F_15 ( V_2 -> V_35 . V_53 ,
V_37 . V_49 ) ;
if ( V_27 -> V_22 -> V_41 -> V_54 ( V_27 ) ) {
V_32 = V_55 ;
goto V_43;
}
}
for ( V_29 = 0 ; V_29 < V_56 ; ++ V_29 ) {
if ( V_2 -> V_35 . V_51 . V_52 )
V_25 = ( ( V_2 -> V_35 . V_51 . V_57 + V_2 -> V_35 . V_51 . V_58 ) >> V_45 ) + V_23 ;
else {
V_28 = V_27 -> V_59 [ V_23 ] ;
if ( F_6 ( ! V_28 && V_29 == 0 ) ) {
V_32 = V_55 ;
goto V_43;
} else if ( F_6 ( ! V_28 ) ) {
break;
}
V_28 -> V_60 = V_4 -> V_61 -> V_62 ;
V_28 -> V_63 = F_12 ( & V_2 -> V_47 ) +
V_23 ;
V_25 = F_16 ( V_28 ) ;
}
if ( V_4 -> V_50 & V_64 )
V_7 = F_17 ( & V_37 , V_30 ,
F_18 ( V_25 , V_65 ) ) ;
else
V_7 = F_19 ( & V_37 , V_30 , V_25 ) ;
if ( F_6 ( ( V_7 == - V_38 ) || ( V_7 != 0 && V_29 > 0 ) ) )
break;
else if ( F_6 ( V_7 != 0 ) ) {
V_32 =
( V_7 == - V_66 ) ? V_55 : V_18 ;
goto V_43;
}
V_30 += V_67 ;
if ( F_6 ( ++ V_23 >= V_24 ) )
break;
}
V_43:
F_20 ( V_34 ) ;
V_10:
F_21 ( V_2 ) ;
return V_32 ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_4 -> V_20 ;
F_23 ( V_2 -> V_22 -> V_68 != V_4 -> V_61 -> V_62 ) ;
( void ) F_24 ( V_2 ) ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_20 ;
F_26 ( & V_2 ) ;
V_4 -> V_20 = NULL ;
}
static struct V_1 * F_27 ( struct V_21 * V_22 ,
unsigned long V_58 ,
unsigned long V_59 )
{
struct V_69 * V_70 ;
struct V_1 * V_2 = NULL ;
F_28 ( & V_22 -> V_71 ) ;
V_70 = F_29 ( & V_22 -> V_71 , V_58 , V_59 ) ;
if ( F_2 ( V_70 ) ) {
V_2 = F_30 ( V_70 , struct V_1 , V_47 ) ;
if ( ! F_31 ( & V_2 -> V_72 ) )
V_2 = NULL ;
}
F_32 ( & V_22 -> V_71 ) ;
if ( ! V_2 )
F_33 ( L_1 ) ;
return V_2 ;
}
int F_34 ( struct V_73 * V_74 , struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_75 * V_41 ;
struct V_1 * V_2 ;
int V_7 ;
V_2 = F_27 ( V_22 , V_4 -> V_46 , F_13 ( V_4 ) ) ;
if ( F_6 ( ! V_2 ) )
return - V_76 ;
V_41 = V_2 -> V_22 -> V_41 ;
if ( F_6 ( ! V_41 -> V_77 ) ) {
V_7 = - V_78 ;
goto V_79;
}
V_7 = V_41 -> V_77 ( V_2 , V_74 ) ;
if ( F_6 ( V_7 != 0 ) )
goto V_79;
V_4 -> V_80 = & V_81 ;
V_4 -> V_20 = V_2 ;
V_4 -> V_50 |= V_64 ;
V_4 -> V_50 |= V_82 | V_83 | V_84 ;
return 0 ;
V_79:
F_26 ( & V_2 ) ;
return V_7 ;
}
int F_35 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
if ( V_4 -> V_46 != 0 )
return - V_85 ;
V_4 -> V_80 = & V_81 ;
V_4 -> V_20 = F_24 ( V_2 ) ;
V_4 -> V_50 |= V_64 ;
V_4 -> V_50 |= V_82 | V_83 ;
return 0 ;
}

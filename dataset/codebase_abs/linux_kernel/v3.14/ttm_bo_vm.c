static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = V_2 -> V_8 ;
int V_9 = 0 ;
F_2 ( & V_8 -> V_10 ) ;
if ( F_3 ( ! F_4 ( V_11 , & V_2 -> V_12 ) ) )
goto V_13;
V_9 = F_5 ( V_2 , false , false , true ) ;
if ( F_3 ( V_9 == 0 ) )
goto V_13;
if ( V_6 -> V_14 & V_15 ) {
V_9 = V_16 ;
if ( V_6 -> V_14 & V_17 )
goto V_13;
F_6 ( & V_4 -> V_18 -> V_19 ) ;
( void ) F_5 ( V_2 , false , true , false ) ;
goto V_13;
}
V_9 = F_5 ( V_2 , false , true , false ) ;
if ( F_7 ( V_9 != 0 ) )
V_9 = ( V_9 != - V_20 ) ? V_21 :
V_22 ;
V_13:
F_8 ( & V_8 -> V_10 ) ;
return V_9 ;
}
static int F_9 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_1 * V_2 = (struct V_1 * )
V_4 -> V_23 ;
struct V_7 * V_8 = V_2 -> V_8 ;
unsigned long V_24 ;
unsigned long V_25 ;
unsigned long V_26 ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_29 ;
int V_9 ;
int V_30 ;
unsigned long V_31 = ( unsigned long ) V_6 -> V_32 ;
int V_33 = V_22 ;
struct V_34 * V_35 =
& V_8 -> V_35 [ V_2 -> V_36 . V_37 ] ;
struct V_3 V_38 ;
V_9 = F_10 ( V_2 , true , true , false , NULL ) ;
if ( F_7 ( V_9 != 0 ) ) {
if ( V_9 != - V_39 )
return V_22 ;
if ( V_6 -> V_14 & V_15 ) {
if ( ! ( V_6 -> V_14 & V_17 ) ) {
F_6 ( & V_4 -> V_18 -> V_19 ) ;
( void ) F_11 ( V_2 ) ;
}
return V_16 ;
}
return V_22 ;
}
if ( V_2 -> V_28 && ( V_2 -> V_28 -> V_40 & V_41 ) ) {
V_33 = V_21 ;
goto V_13;
}
if ( V_8 -> V_42 -> V_43 ) {
V_9 = V_8 -> V_42 -> V_43 ( V_2 ) ;
switch ( V_9 ) {
case 0 :
break;
case - V_39 :
case - V_20 :
V_33 = V_22 ;
goto V_13;
default:
V_33 = V_21 ;
goto V_13;
}
}
V_9 = F_1 ( V_2 , V_4 , V_6 ) ;
if ( F_7 ( V_9 != 0 ) ) {
V_33 = V_9 ;
goto V_13;
}
V_9 = F_12 ( V_35 , true ) ;
if ( F_7 ( V_9 != 0 ) ) {
V_33 = V_22 ;
goto V_13;
}
V_9 = F_13 ( V_2 ) ;
if ( F_7 ( V_9 != 0 ) ) {
V_33 = V_21 ;
goto V_44;
}
V_24 = ( ( V_31 - V_4 -> V_45 ) >> V_46 ) +
V_4 -> V_47 - F_14 ( & V_2 -> V_48 ) ;
V_25 = F_15 ( V_4 ) + V_4 -> V_47 -
F_14 ( & V_2 -> V_48 ) ;
if ( F_7 ( V_24 >= V_2 -> V_49 ) ) {
V_33 = V_21 ;
goto V_44;
}
V_38 = * V_4 ;
V_38 . V_50 = F_16 ( V_38 . V_51 ) ;
if ( V_2 -> V_36 . V_52 . V_53 ) {
V_38 . V_50 = F_17 ( V_2 -> V_36 . V_54 ,
V_38 . V_50 ) ;
} else {
V_28 = V_2 -> V_28 ;
if ( ! ( V_2 -> V_36 . V_54 & V_55 ) )
V_38 . V_50 = F_17 ( V_2 -> V_36 . V_54 ,
V_38 . V_50 ) ;
if ( V_28 -> V_8 -> V_42 -> V_56 ( V_28 ) ) {
V_33 = V_57 ;
goto V_44;
}
}
for ( V_30 = 0 ; V_30 < V_58 ; ++ V_30 ) {
if ( V_2 -> V_36 . V_52 . V_53 )
V_26 = ( ( V_2 -> V_36 . V_52 . V_59 + V_2 -> V_36 . V_52 . V_60 ) >> V_46 ) + V_24 ;
else {
V_29 = V_28 -> V_61 [ V_24 ] ;
if ( F_7 ( ! V_29 && V_30 == 0 ) ) {
V_33 = V_57 ;
goto V_44;
} else if ( F_7 ( ! V_29 ) ) {
break;
}
V_29 -> V_62 = V_4 -> V_63 -> V_64 ;
V_29 -> V_65 = F_14 ( & V_2 -> V_48 ) +
V_24 ;
V_26 = F_18 ( V_29 ) ;
}
if ( V_4 -> V_51 & V_66 )
V_9 = F_19 ( & V_38 , V_31 , V_26 ) ;
else
V_9 = F_20 ( & V_38 , V_31 , V_26 ) ;
if ( F_7 ( ( V_9 == - V_39 ) || ( V_9 != 0 && V_30 > 0 ) ) )
break;
else if ( F_7 ( V_9 != 0 ) ) {
V_33 =
( V_9 == - V_67 ) ? V_57 : V_21 ;
goto V_44;
}
V_31 += V_68 ;
if ( F_7 ( ++ V_24 >= V_25 ) )
break;
}
V_44:
F_21 ( V_35 ) ;
V_13:
F_22 ( V_2 ) ;
return V_33 ;
}
static void F_23 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_4 -> V_23 ;
F_24 ( V_2 -> V_8 -> V_69 != V_4 -> V_63 -> V_64 ) ;
( void ) F_25 ( V_2 ) ;
}
static void F_26 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_23 ;
F_27 ( & V_2 ) ;
V_4 -> V_23 = NULL ;
}
static struct V_1 * F_28 ( struct V_7 * V_8 ,
unsigned long V_60 ,
unsigned long V_61 )
{
struct V_70 * V_71 ;
struct V_1 * V_2 = NULL ;
F_29 ( & V_8 -> V_72 ) ;
V_71 = F_30 ( & V_8 -> V_72 , V_60 , V_61 ) ;
if ( F_3 ( V_71 ) ) {
V_2 = F_31 ( V_71 , struct V_1 , V_48 ) ;
if ( ! F_32 ( & V_2 -> V_73 ) )
V_2 = NULL ;
}
F_33 ( & V_8 -> V_72 ) ;
if ( ! V_2 )
F_34 ( L_1 ) ;
return V_2 ;
}
int F_35 ( struct V_74 * V_75 , struct V_3 * V_4 ,
struct V_7 * V_8 )
{
struct V_76 * V_42 ;
struct V_1 * V_2 ;
int V_9 ;
V_2 = F_28 ( V_8 , V_4 -> V_47 , F_15 ( V_4 ) ) ;
if ( F_7 ( ! V_2 ) )
return - V_77 ;
V_42 = V_2 -> V_8 -> V_42 ;
if ( F_7 ( ! V_42 -> V_78 ) ) {
V_9 = - V_79 ;
goto V_80;
}
V_9 = V_42 -> V_78 ( V_2 , V_75 ) ;
if ( F_7 ( V_9 != 0 ) )
goto V_80;
V_4 -> V_81 = & V_82 ;
V_4 -> V_23 = V_2 ;
V_4 -> V_51 |= V_66 ;
V_4 -> V_51 |= V_83 | V_84 | V_85 ;
return 0 ;
V_80:
F_27 ( & V_2 ) ;
return V_9 ;
}
int F_36 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
if ( V_4 -> V_47 != 0 )
return - V_86 ;
V_4 -> V_81 = & V_82 ;
V_4 -> V_23 = F_25 ( V_2 ) ;
V_4 -> V_51 |= V_66 ;
V_4 -> V_51 |= V_83 | V_84 ;
return 0 ;
}

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
if ( V_8 -> V_40 -> V_41 ) {
V_9 = V_8 -> V_40 -> V_41 ( V_2 ) ;
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
goto V_42;
}
V_24 = ( ( V_31 - V_4 -> V_43 ) >> V_44 ) +
V_4 -> V_45 - F_14 ( & V_2 -> V_46 ) ;
V_25 = F_15 ( V_4 ) + V_4 -> V_45 -
F_14 ( & V_2 -> V_46 ) ;
if ( F_7 ( V_24 >= V_2 -> V_47 ) ) {
V_33 = V_21 ;
goto V_42;
}
V_38 = * V_4 ;
V_38 . V_48 = F_16 ( V_38 . V_49 ) ;
if ( V_2 -> V_36 . V_50 . V_51 ) {
V_38 . V_48 = F_17 ( V_2 -> V_36 . V_52 ,
V_38 . V_48 ) ;
} else {
V_28 = V_2 -> V_28 ;
if ( ! ( V_2 -> V_36 . V_52 & V_53 ) )
V_38 . V_48 = F_17 ( V_2 -> V_36 . V_52 ,
V_38 . V_48 ) ;
if ( V_28 -> V_8 -> V_40 -> V_54 ( V_28 ) ) {
V_33 = V_55 ;
goto V_42;
}
}
for ( V_30 = 0 ; V_30 < V_56 ; ++ V_30 ) {
if ( V_2 -> V_36 . V_50 . V_51 )
V_26 = ( ( V_2 -> V_36 . V_50 . V_57 + V_2 -> V_36 . V_50 . V_58 ) >> V_44 ) + V_24 ;
else {
V_29 = V_28 -> V_59 [ V_24 ] ;
if ( F_7 ( ! V_29 && V_30 == 0 ) ) {
V_33 = V_55 ;
goto V_42;
} else if ( F_7 ( ! V_29 ) ) {
break;
}
V_26 = F_18 ( V_29 ) ;
}
V_9 = F_19 ( & V_38 , V_31 , V_26 ) ;
if ( F_7 ( ( V_9 == - V_39 ) || ( V_9 != 0 && V_30 > 0 ) ) )
break;
else if ( F_7 ( V_9 != 0 ) ) {
V_33 =
( V_9 == - V_60 ) ? V_55 : V_21 ;
goto V_42;
}
V_31 += V_61 ;
if ( F_7 ( ++ V_24 >= V_25 ) )
break;
}
V_42:
F_20 ( V_35 ) ;
V_13:
F_21 ( V_2 ) ;
return V_33 ;
}
static void F_22 ( struct V_3 * V_4 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_4 -> V_23 ;
( void ) F_23 ( V_2 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 -> V_23 ;
F_25 ( & V_2 ) ;
V_4 -> V_23 = NULL ;
}
static struct V_1 * F_26 ( struct V_7 * V_8 ,
unsigned long V_58 ,
unsigned long V_59 )
{
struct V_62 * V_63 ;
struct V_1 * V_2 = NULL ;
F_27 ( & V_8 -> V_64 ) ;
V_63 = F_28 ( & V_8 -> V_64 , V_58 , V_59 ) ;
if ( F_3 ( V_63 ) ) {
V_2 = F_29 ( V_63 , struct V_1 , V_46 ) ;
if ( ! F_30 ( & V_2 -> V_65 ) )
V_2 = NULL ;
}
F_31 ( & V_8 -> V_64 ) ;
if ( ! V_2 )
F_32 ( L_1 ) ;
return V_2 ;
}
int F_33 ( struct V_66 * V_67 , struct V_3 * V_4 ,
struct V_7 * V_8 )
{
struct V_68 * V_40 ;
struct V_1 * V_2 ;
int V_9 ;
V_2 = F_26 ( V_8 , V_4 -> V_45 , F_15 ( V_4 ) ) ;
if ( F_7 ( ! V_2 ) )
return - V_69 ;
V_40 = V_2 -> V_8 -> V_40 ;
if ( F_7 ( ! V_40 -> V_70 ) ) {
V_9 = - V_71 ;
goto V_72;
}
V_9 = V_40 -> V_70 ( V_2 , V_67 ) ;
if ( F_7 ( V_9 != 0 ) )
goto V_72;
V_4 -> V_73 = & V_74 ;
V_4 -> V_23 = V_2 ;
V_4 -> V_49 |= V_75 | V_76 | V_77 | V_78 ;
return 0 ;
V_72:
F_25 ( & V_2 ) ;
return V_9 ;
}
int F_34 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
if ( V_4 -> V_45 != 0 )
return - V_79 ;
V_4 -> V_73 = & V_74 ;
V_4 -> V_23 = F_23 ( V_2 ) ;
V_4 -> V_49 |= V_75 | V_76 | V_77 ;
return 0 ;
}

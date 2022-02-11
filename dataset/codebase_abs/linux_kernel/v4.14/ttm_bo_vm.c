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
if ( V_2 -> V_34 . V_50 . V_51 ) {
V_36 . V_48 = F_20 ( V_36 . V_48 ) ;
V_25 = V_22 -> V_40 -> V_56 ( V_2 , V_23 ) ;
} else {
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
V_25 = F_21 ( V_28 ) ;
}
if ( V_13 -> V_49 & V_62 )
V_5 = F_22 ( & V_36 , V_30 ,
F_23 ( V_25 , V_63 ) ) ;
else
V_5 = F_24 ( & V_36 , V_30 , V_25 ) ;
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
F_25 ( V_33 ) ;
V_7:
F_7 ( V_2 ) ;
return V_31 ;
}
static void F_26 ( struct V_19 * V_13 )
{
struct V_1 * V_2 =
(struct V_1 * ) V_13 -> V_20 ;
F_27 ( V_2 -> V_22 -> V_66 != V_13 -> V_59 -> V_60 ) ;
( void ) F_4 ( V_2 ) ;
}
static void F_28 ( struct V_19 * V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_13 -> V_20 ;
F_8 ( & V_2 ) ;
V_13 -> V_20 = NULL ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned long V_67 ,
void * V_68 , int V_69 , int V_70 )
{
unsigned long V_28 = V_67 >> V_44 ;
unsigned long V_71 = V_69 ;
int V_5 ;
V_67 -= V_28 << V_44 ;
do {
unsigned long V_72 = F_30 ( V_71 , V_65 - V_67 ) ;
struct V_73 V_74 ;
void * V_75 ;
bool V_51 ;
V_5 = F_31 ( V_2 , V_28 , 1 , & V_74 ) ;
if ( V_5 )
return V_5 ;
V_75 = ( V_76 * ) F_32 ( & V_74 , & V_51 ) + V_67 ;
F_33 ( V_51 ) ;
if ( V_70 )
memcpy ( V_75 , V_68 , V_72 ) ;
else
memcpy ( V_68 , V_75 , V_72 ) ;
F_34 ( & V_74 ) ;
V_28 ++ ;
V_71 -= V_72 ;
V_67 = 0 ;
} while ( V_71 );
return V_69 ;
}
static int F_35 ( struct V_19 * V_13 , unsigned long V_77 ,
void * V_68 , int V_69 , int V_70 )
{
unsigned long V_67 = ( V_77 ) - V_13 -> V_43 ;
struct V_1 * V_2 = V_13 -> V_20 ;
int V_5 ;
if ( V_69 < 1 || ( V_67 + V_69 ) > > V_44 > V_2 -> V_47 )
return - V_78 ;
V_5 = F_12 ( V_2 , true , false , NULL ) ;
if ( V_5 )
return V_5 ;
switch ( V_2 -> V_34 . V_35 ) {
case V_79 :
if ( F_9 ( V_2 -> V_27 -> V_38 & V_80 ) ) {
V_5 = F_36 ( V_2 -> V_27 ) ;
if ( F_9 ( V_5 != 0 ) )
return V_5 ;
}
case V_81 :
V_5 = F_29 ( V_2 , V_67 , V_68 , V_69 , V_70 ) ;
break;
default:
if ( V_2 -> V_22 -> V_40 -> V_82 )
V_5 = V_2 -> V_22 -> V_40 -> V_82 (
V_2 , V_67 , V_68 , V_69 , V_70 ) ;
else
V_5 = - V_78 ;
}
F_7 ( V_2 ) ;
return V_5 ;
}
static struct V_1 * F_37 ( struct V_21 * V_22 ,
unsigned long V_67 ,
unsigned long V_57 )
{
struct V_83 * V_84 ;
struct V_1 * V_2 = NULL ;
F_38 ( & V_22 -> V_85 ) ;
V_84 = F_39 ( & V_22 -> V_85 , V_67 , V_57 ) ;
if ( F_2 ( V_84 ) ) {
V_2 = F_40 ( V_84 , struct V_1 , V_46 ) ;
if ( ! F_41 ( & V_2 -> V_86 ) )
V_2 = NULL ;
}
F_42 ( & V_22 -> V_85 ) ;
if ( ! V_2 )
F_43 ( L_1 ) ;
return V_2 ;
}
unsigned long F_44 ( struct V_1 * V_2 ,
unsigned long V_23 )
{
return ( ( V_2 -> V_34 . V_50 . V_87 + V_2 -> V_34 . V_50 . V_67 ) >> V_44 )
+ V_23 ;
}
int F_45 ( struct V_88 * V_89 , struct V_19 * V_13 ,
struct V_21 * V_22 )
{
struct V_90 * V_40 ;
struct V_1 * V_2 ;
int V_5 ;
V_2 = F_37 ( V_22 , V_13 -> V_45 , F_17 ( V_13 ) ) ;
if ( F_9 ( ! V_2 ) )
return - V_91 ;
V_40 = V_2 -> V_22 -> V_40 ;
if ( F_9 ( ! V_40 -> V_92 ) ) {
V_5 = - V_93 ;
goto V_94;
}
V_5 = V_40 -> V_92 ( V_2 , V_89 ) ;
if ( F_9 ( V_5 != 0 ) )
goto V_94;
V_13 -> V_95 = & V_96 ;
V_13 -> V_20 = V_2 ;
V_13 -> V_49 |= V_62 ;
V_13 -> V_49 |= V_97 | V_98 | V_99 ;
return 0 ;
V_94:
F_8 ( & V_2 ) ;
return V_5 ;
}
int F_46 ( struct V_19 * V_13 , struct V_1 * V_2 )
{
if ( V_13 -> V_45 != 0 )
return - V_100 ;
V_13 -> V_95 = & V_96 ;
V_13 -> V_20 = F_4 ( V_2 ) ;
V_13 -> V_49 |= V_62 ;
V_13 -> V_49 |= V_97 | V_98 ;
return 0 ;
}

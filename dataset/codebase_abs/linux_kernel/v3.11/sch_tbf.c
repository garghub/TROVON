static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_7 , * V_8 ;
T_1 V_9 = F_3 ( V_2 ) ;
int V_10 , V_11 ;
V_7 = F_4 ( V_2 , V_9 & ~ V_12 ) ;
if ( F_5 ( V_7 ) )
return F_6 ( V_2 , V_4 ) ;
V_11 = 0 ;
while ( V_7 ) {
V_8 = V_7 -> V_13 ;
V_7 -> V_13 = NULL ;
if ( F_7 ( V_7 -> V_14 <= V_6 -> V_15 ) ) {
F_8 ( V_7 ) -> V_16 = V_7 -> V_14 ;
V_10 = F_9 ( V_7 , V_6 -> V_17 ) ;
} else {
V_10 = F_6 ( V_2 , V_4 ) ;
}
if ( V_10 != V_18 ) {
if ( F_10 ( V_10 ) )
V_4 -> V_19 . V_20 ++ ;
} else {
V_11 ++ ;
}
V_7 = V_8 ;
}
V_4 -> V_6 . V_21 += V_11 ;
if ( V_11 > 1 )
F_11 ( V_4 , 1 - V_11 ) ;
F_12 ( V_2 ) ;
return V_11 > 0 ? V_18 : V_22 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_10 ;
if ( F_14 ( V_2 ) > V_6 -> V_15 ) {
if ( F_15 ( V_2 ) )
return F_1 ( V_2 , V_4 ) ;
return F_6 ( V_2 , V_4 ) ;
}
V_10 = F_9 ( V_2 , V_6 -> V_17 ) ;
if ( V_10 != V_18 ) {
if ( F_10 ( V_10 ) )
V_4 -> V_19 . V_20 ++ ;
return V_10 ;
}
V_4 -> V_6 . V_21 ++ ;
return V_18 ;
}
static unsigned int F_16 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_14 = 0 ;
if ( V_6 -> V_17 -> V_23 -> V_24 && ( V_14 = V_6 -> V_17 -> V_23 -> V_24 ( V_6 -> V_17 ) ) != 0 ) {
V_4 -> V_6 . V_21 -- ;
V_4 -> V_19 . V_20 ++ ;
}
return V_14 ;
}
static struct V_1 * F_17 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 ;
V_2 = V_6 -> V_17 -> V_23 -> V_25 ( V_6 -> V_17 ) ;
if ( V_2 ) {
T_2 V_26 ;
T_2 V_27 ;
T_2 V_28 = 0 ;
unsigned int V_14 = F_14 ( V_2 ) ;
V_26 = F_18 ( F_19 () ) ;
V_27 = F_20 ( T_2 , V_26 - V_6 -> V_29 , V_6 -> V_30 ) ;
if ( V_6 -> V_31 ) {
V_28 = V_27 + V_6 -> V_32 ;
if ( V_28 > V_6 -> V_33 )
V_28 = V_6 -> V_33 ;
V_28 -= ( T_2 ) F_21 ( & V_6 -> V_34 , V_14 ) ;
}
V_27 += V_6 -> V_35 ;
if ( V_27 > V_6 -> V_30 )
V_27 = V_6 -> V_30 ;
V_27 -= ( T_2 ) F_21 ( & V_6 -> V_36 , V_14 ) ;
if ( ( V_27 | V_28 ) >= 0 ) {
V_2 = F_22 ( V_6 -> V_17 ) ;
if ( F_23 ( ! V_2 ) )
return NULL ;
V_6 -> V_29 = V_26 ;
V_6 -> V_35 = V_27 ;
V_6 -> V_32 = V_28 ;
V_4 -> V_6 . V_21 -- ;
F_24 ( V_4 ) ;
F_25 ( V_4 , V_2 ) ;
return V_2 ;
}
F_26 ( & V_6 -> V_37 ,
V_26 + F_27 ( long , - V_27 , - V_28 ) ) ;
V_4 -> V_19 . V_38 ++ ;
}
return NULL ;
}
static void F_28 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_29 ( V_6 -> V_17 ) ;
V_4 -> V_6 . V_21 = 0 ;
V_6 -> V_29 = F_18 ( F_19 () ) ;
V_6 -> V_35 = V_6 -> V_30 ;
V_6 -> V_32 = V_6 -> V_33 ;
F_30 ( & V_6 -> V_37 ) ;
}
static int F_31 ( struct V_3 * V_4 , struct V_39 * V_40 )
{
int V_41 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_39 * V_42 [ V_43 + 1 ] ;
struct V_44 * V_45 ;
struct V_46 * V_47 = NULL ;
struct V_46 * V_48 = NULL ;
struct V_3 * V_49 = NULL ;
int V_15 , V_50 ;
V_41 = F_32 ( V_42 , V_43 , V_40 , V_51 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = - V_52 ;
if ( V_42 [ V_53 ] == NULL )
goto V_54;
V_45 = F_33 ( V_42 [ V_53 ] ) ;
V_47 = F_34 ( & V_45 -> V_36 , V_42 [ V_55 ] ) ;
if ( V_47 == NULL )
goto V_54;
if ( V_45 -> V_56 . V_36 ) {
if ( V_45 -> V_56 . V_36 > V_45 -> V_36 . V_36 )
V_48 = F_34 ( & V_45 -> V_56 , V_42 [ V_43 ] ) ;
if ( V_48 == NULL )
goto V_54;
}
for ( V_50 = 0 ; V_50 < 256 ; V_50 ++ )
if ( V_47 -> V_57 [ V_50 ] > V_45 -> V_30 )
break;
V_15 = ( V_50 << V_45 -> V_36 . V_58 ) - 1 ;
if ( V_48 ) {
int V_59 ;
for ( V_50 = 0 ; V_50 < 256 ; V_50 ++ )
if ( V_48 -> V_57 [ V_50 ] > V_45 -> V_33 )
break;
V_59 = ( V_50 << V_45 -> V_56 . V_58 ) - 1 ;
if ( V_59 < V_15 )
V_15 = V_59 ;
}
if ( V_15 < 0 )
goto V_54;
if ( V_6 -> V_17 != & V_60 ) {
V_41 = F_35 ( V_6 -> V_17 , V_45 -> V_61 ) ;
if ( V_41 )
goto V_54;
} else if ( V_45 -> V_61 > 0 ) {
V_49 = F_36 ( V_4 , & V_62 , V_45 -> V_61 ) ;
if ( F_37 ( V_49 ) ) {
V_41 = F_38 ( V_49 ) ;
goto V_54;
}
}
F_39 ( V_4 ) ;
if ( V_49 ) {
F_11 ( V_6 -> V_17 , V_6 -> V_17 -> V_6 . V_21 ) ;
F_40 ( V_6 -> V_17 ) ;
V_6 -> V_17 = V_49 ;
}
V_6 -> V_61 = V_45 -> V_61 ;
V_6 -> V_33 = F_41 ( V_45 -> V_33 ) ;
V_6 -> V_15 = V_15 ;
V_6 -> V_30 = F_41 ( V_45 -> V_30 ) ;
V_6 -> V_35 = V_6 -> V_30 ;
V_6 -> V_32 = V_6 -> V_33 ;
F_42 ( & V_6 -> V_36 , & V_47 -> V_36 ) ;
if ( V_48 ) {
F_42 ( & V_6 -> V_34 , & V_48 -> V_36 ) ;
V_6 -> V_31 = true ;
} else {
V_6 -> V_31 = false ;
}
F_43 ( V_4 ) ;
V_41 = 0 ;
V_54:
if ( V_47 )
F_44 ( V_47 ) ;
if ( V_48 )
F_44 ( V_48 ) ;
return V_41 ;
}
static int F_45 ( struct V_3 * V_4 , struct V_39 * V_40 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_40 == NULL )
return - V_52 ;
V_6 -> V_29 = F_18 ( F_19 () ) ;
F_46 ( & V_6 -> V_37 , V_4 ) ;
V_6 -> V_17 = & V_60 ;
return F_31 ( V_4 , V_40 ) ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_30 ( & V_6 -> V_37 ) ;
F_40 ( V_6 -> V_17 ) ;
}
static int F_48 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_39 * V_63 ;
struct V_44 V_40 ;
V_4 -> V_19 . V_64 = V_6 -> V_17 -> V_19 . V_64 ;
V_63 = F_49 ( V_2 , V_65 ) ;
if ( V_63 == NULL )
goto V_66;
V_40 . V_61 = V_6 -> V_61 ;
F_50 ( & V_40 . V_36 , & V_6 -> V_36 ) ;
if ( V_6 -> V_31 )
F_50 ( & V_40 . V_56 , & V_6 -> V_34 ) ;
else
memset ( & V_40 . V_56 , 0 , sizeof( V_40 . V_56 ) ) ;
V_40 . V_33 = F_51 ( V_6 -> V_33 ) ;
V_40 . V_30 = F_51 ( V_6 -> V_30 ) ;
if ( F_52 ( V_2 , V_53 , sizeof( V_40 ) , & V_40 ) )
goto V_66;
F_53 ( V_2 , V_63 ) ;
return V_2 -> V_14 ;
V_66:
F_54 ( V_2 , V_63 ) ;
return - 1 ;
}
static int F_55 ( struct V_3 * V_4 , unsigned long V_67 ,
struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_69 -> V_70 |= F_56 ( 1 ) ;
V_69 -> V_71 = V_6 -> V_17 -> V_72 ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 , unsigned long V_73 , struct V_3 * V_74 ,
struct V_3 * * V_75 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_74 == NULL )
V_74 = & V_60 ;
F_39 ( V_4 ) ;
* V_75 = V_6 -> V_17 ;
V_6 -> V_17 = V_74 ;
F_11 ( * V_75 , ( * V_75 ) -> V_6 . V_21 ) ;
F_29 ( * V_75 ) ;
F_43 ( V_4 ) ;
return 0 ;
}
static struct V_3 * F_58 ( struct V_3 * V_4 , unsigned long V_73 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return V_6 -> V_17 ;
}
static unsigned long F_59 ( struct V_3 * V_4 , T_3 V_76 )
{
return 1 ;
}
static void F_60 ( struct V_3 * V_4 , unsigned long V_73 )
{
}
static void F_61 ( struct V_3 * V_4 , struct V_77 * V_78 )
{
if ( ! V_78 -> V_79 ) {
if ( V_78 -> V_80 >= V_78 -> V_81 )
if ( V_78 -> V_82 ( V_4 , 1 , V_78 ) < 0 ) {
V_78 -> V_79 = 1 ;
return;
}
V_78 -> V_80 ++ ;
}
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_83 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_83 ) ;
}

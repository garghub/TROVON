static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 ;
if ( F_3 ( V_2 ) > V_6 -> V_8 )
return F_4 ( V_2 , V_4 ) ;
V_7 = F_5 ( V_2 , V_6 -> V_9 ) ;
if ( V_7 != V_10 ) {
if ( F_6 ( V_7 ) )
V_4 -> V_11 . V_12 ++ ;
return V_7 ;
}
V_4 -> V_6 . V_13 ++ ;
return V_10 ;
}
static unsigned int F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
unsigned int V_14 = 0 ;
if ( V_6 -> V_9 -> V_15 -> V_16 && ( V_14 = V_6 -> V_9 -> V_15 -> V_16 ( V_6 -> V_9 ) ) != 0 ) {
V_4 -> V_6 . V_13 -- ;
V_4 -> V_11 . V_12 ++ ;
}
return V_14 ;
}
static struct V_1 * F_8 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_1 * V_2 ;
V_2 = V_6 -> V_9 -> V_15 -> V_17 ( V_6 -> V_9 ) ;
if ( V_2 ) {
T_1 V_18 ;
T_1 V_19 ;
T_1 V_20 = 0 ;
unsigned int V_14 = F_3 ( V_2 ) ;
V_18 = F_9 ( F_10 () ) ;
V_19 = F_11 ( T_1 , V_18 - V_6 -> V_21 , V_6 -> V_22 ) ;
if ( V_6 -> V_23 ) {
V_20 = V_19 + V_6 -> V_24 ;
if ( V_20 > V_6 -> V_25 )
V_20 = V_6 -> V_25 ;
V_20 -= ( T_1 ) F_12 ( & V_6 -> V_26 , V_14 ) ;
}
V_19 += V_6 -> V_27 ;
if ( V_19 > V_6 -> V_22 )
V_19 = V_6 -> V_22 ;
V_19 -= ( T_1 ) F_12 ( & V_6 -> V_28 , V_14 ) ;
if ( ( V_19 | V_20 ) >= 0 ) {
V_2 = F_13 ( V_6 -> V_9 ) ;
if ( F_14 ( ! V_2 ) )
return NULL ;
V_6 -> V_21 = V_18 ;
V_6 -> V_27 = V_19 ;
V_6 -> V_24 = V_20 ;
V_4 -> V_6 . V_13 -- ;
F_15 ( V_4 ) ;
F_16 ( V_4 , V_2 ) ;
return V_2 ;
}
F_17 ( & V_6 -> V_29 ,
V_18 + F_18 ( long , - V_19 , - V_20 ) ) ;
V_4 -> V_11 . V_30 ++ ;
}
return NULL ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_20 ( V_6 -> V_9 ) ;
V_4 -> V_6 . V_13 = 0 ;
V_6 -> V_21 = F_9 ( F_10 () ) ;
V_6 -> V_27 = V_6 -> V_22 ;
V_6 -> V_24 = V_6 -> V_25 ;
F_21 ( & V_6 -> V_29 ) ;
}
static int F_22 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
int V_33 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_31 * V_34 [ V_35 + 1 ] ;
struct V_36 * V_37 ;
struct V_38 * V_39 = NULL ;
struct V_38 * V_40 = NULL ;
struct V_3 * V_41 = NULL ;
int V_8 , V_42 ;
V_33 = F_23 ( V_34 , V_35 , V_32 , V_43 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = - V_44 ;
if ( V_34 [ V_45 ] == NULL )
goto V_46;
V_37 = F_24 ( V_34 [ V_45 ] ) ;
V_39 = F_25 ( & V_37 -> V_28 , V_34 [ V_47 ] ) ;
if ( V_39 == NULL )
goto V_46;
if ( V_37 -> V_48 . V_28 ) {
if ( V_37 -> V_48 . V_28 > V_37 -> V_28 . V_28 )
V_40 = F_25 ( & V_37 -> V_48 , V_34 [ V_35 ] ) ;
if ( V_40 == NULL )
goto V_46;
}
for ( V_42 = 0 ; V_42 < 256 ; V_42 ++ )
if ( V_39 -> V_49 [ V_42 ] > V_37 -> V_22 )
break;
V_8 = ( V_42 << V_37 -> V_28 . V_50 ) - 1 ;
if ( V_40 ) {
int V_51 ;
for ( V_42 = 0 ; V_42 < 256 ; V_42 ++ )
if ( V_40 -> V_49 [ V_42 ] > V_37 -> V_25 )
break;
V_51 = ( V_42 << V_37 -> V_48 . V_50 ) - 1 ;
if ( V_51 < V_8 )
V_8 = V_51 ;
}
if ( V_8 < 0 )
goto V_46;
if ( V_6 -> V_9 != & V_52 ) {
V_33 = F_26 ( V_6 -> V_9 , V_37 -> V_53 ) ;
if ( V_33 )
goto V_46;
} else if ( V_37 -> V_53 > 0 ) {
V_41 = F_27 ( V_4 , & V_54 , V_37 -> V_53 ) ;
if ( F_28 ( V_41 ) ) {
V_33 = F_29 ( V_41 ) ;
goto V_46;
}
}
F_30 ( V_4 ) ;
if ( V_41 ) {
F_31 ( V_6 -> V_9 , V_6 -> V_9 -> V_6 . V_13 ) ;
F_32 ( V_6 -> V_9 ) ;
V_6 -> V_9 = V_41 ;
}
V_6 -> V_53 = V_37 -> V_53 ;
V_6 -> V_25 = F_33 ( V_37 -> V_25 ) ;
V_6 -> V_8 = V_8 ;
V_6 -> V_22 = F_33 ( V_37 -> V_22 ) ;
V_6 -> V_27 = V_6 -> V_22 ;
V_6 -> V_24 = V_6 -> V_25 ;
F_34 ( & V_6 -> V_28 , & V_39 -> V_28 ) ;
if ( V_40 ) {
F_34 ( & V_6 -> V_26 , & V_40 -> V_28 ) ;
V_6 -> V_23 = true ;
} else {
V_6 -> V_23 = false ;
}
F_35 ( V_4 ) ;
V_33 = 0 ;
V_46:
if ( V_39 )
F_36 ( V_39 ) ;
if ( V_40 )
F_36 ( V_40 ) ;
return V_33 ;
}
static int F_37 ( struct V_3 * V_4 , struct V_31 * V_32 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_32 == NULL )
return - V_44 ;
V_6 -> V_21 = F_9 ( F_10 () ) ;
F_38 ( & V_6 -> V_29 , V_4 ) ;
V_6 -> V_9 = & V_52 ;
return F_22 ( V_4 , V_32 ) ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_21 ( & V_6 -> V_29 ) ;
F_32 ( V_6 -> V_9 ) ;
}
static int F_40 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_31 * V_55 ;
struct V_36 V_32 ;
V_4 -> V_11 . V_56 = V_6 -> V_9 -> V_11 . V_56 ;
V_55 = F_41 ( V_2 , V_57 ) ;
if ( V_55 == NULL )
goto V_58;
V_32 . V_53 = V_6 -> V_53 ;
F_42 ( & V_32 . V_28 , & V_6 -> V_28 ) ;
if ( V_6 -> V_23 )
F_42 ( & V_32 . V_48 , & V_6 -> V_26 ) ;
else
memset ( & V_32 . V_48 , 0 , sizeof( V_32 . V_48 ) ) ;
V_32 . V_25 = F_43 ( V_6 -> V_25 ) ;
V_32 . V_22 = F_43 ( V_6 -> V_22 ) ;
if ( F_44 ( V_2 , V_45 , sizeof( V_32 ) , & V_32 ) )
goto V_58;
F_45 ( V_2 , V_55 ) ;
return V_2 -> V_14 ;
V_58:
F_46 ( V_2 , V_55 ) ;
return - 1 ;
}
static int F_47 ( struct V_3 * V_4 , unsigned long V_59 ,
struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_61 -> V_62 |= F_48 ( 1 ) ;
V_61 -> V_63 = V_6 -> V_9 -> V_64 ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , unsigned long V_65 , struct V_3 * V_66 ,
struct V_3 * * V_67 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_66 == NULL )
V_66 = & V_52 ;
F_30 ( V_4 ) ;
* V_67 = V_6 -> V_9 ;
V_6 -> V_9 = V_66 ;
F_31 ( * V_67 , ( * V_67 ) -> V_6 . V_13 ) ;
F_20 ( * V_67 ) ;
F_35 ( V_4 ) ;
return 0 ;
}
static struct V_3 * F_50 ( struct V_3 * V_4 , unsigned long V_65 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return V_6 -> V_9 ;
}
static unsigned long F_51 ( struct V_3 * V_4 , T_2 V_68 )
{
return 1 ;
}
static void F_52 ( struct V_3 * V_4 , unsigned long V_65 )
{
}
static void F_53 ( struct V_3 * V_4 , struct V_69 * V_70 )
{
if ( ! V_70 -> V_71 ) {
if ( V_70 -> V_72 >= V_70 -> V_73 )
if ( V_70 -> V_74 ( V_4 , 1 , V_70 ) < 0 ) {
V_70 -> V_71 = 1 ;
return;
}
V_70 -> V_72 ++ ;
}
}
static int T_3 F_54 ( void )
{
return F_55 ( & V_75 ) ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_75 ) ;
}

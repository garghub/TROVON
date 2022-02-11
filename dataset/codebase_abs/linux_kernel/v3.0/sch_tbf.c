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
long V_19 ;
long V_20 = 0 ;
unsigned int V_14 = F_3 ( V_2 ) ;
V_18 = F_9 () ;
V_19 = F_10 ( V_18 , V_6 -> V_21 , V_6 -> V_22 ) ;
if ( V_6 -> V_23 ) {
V_20 = V_19 + V_6 -> V_24 ;
if ( V_20 > ( long ) V_6 -> V_25 )
V_20 = V_6 -> V_25 ;
V_20 -= F_11 ( V_6 , V_14 ) ;
}
V_19 += V_6 -> V_26 ;
if ( V_19 > ( long ) V_6 -> V_22 )
V_19 = V_6 -> V_22 ;
V_19 -= F_12 ( V_6 , V_14 ) ;
if ( ( V_19 | V_20 ) >= 0 ) {
V_2 = F_13 ( V_6 -> V_9 ) ;
if ( F_14 ( ! V_2 ) )
return NULL ;
V_6 -> V_21 = V_18 ;
V_6 -> V_26 = V_19 ;
V_6 -> V_24 = V_20 ;
V_4 -> V_6 . V_13 -- ;
F_15 ( V_4 ) ;
F_16 ( V_4 , V_2 ) ;
return V_2 ;
}
F_17 ( & V_6 -> V_27 ,
V_18 + F_18 ( long , - V_19 , - V_20 ) ) ;
V_4 -> V_11 . V_28 ++ ;
}
return NULL ;
}
static void F_19 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_20 ( V_6 -> V_9 ) ;
V_4 -> V_6 . V_13 = 0 ;
V_6 -> V_21 = F_9 () ;
V_6 -> V_26 = V_6 -> V_22 ;
V_6 -> V_24 = V_6 -> V_25 ;
F_21 ( & V_6 -> V_27 ) ;
}
static int F_22 ( struct V_3 * V_4 , struct V_29 * V_30 )
{
int V_31 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_29 * V_32 [ V_33 + 1 ] ;
struct V_34 * V_35 ;
struct V_36 * V_37 = NULL ;
struct V_36 * V_38 = NULL ;
struct V_3 * V_39 = NULL ;
int V_8 , V_40 ;
V_31 = F_23 ( V_32 , V_33 , V_30 , V_41 ) ;
if ( V_31 < 0 )
return V_31 ;
V_31 = - V_42 ;
if ( V_32 [ V_43 ] == NULL )
goto V_44;
V_35 = F_24 ( V_32 [ V_43 ] ) ;
V_37 = F_25 ( & V_35 -> V_45 , V_32 [ V_46 ] ) ;
if ( V_37 == NULL )
goto V_44;
if ( V_35 -> V_47 . V_45 ) {
if ( V_35 -> V_47 . V_45 > V_35 -> V_45 . V_45 )
V_38 = F_25 ( & V_35 -> V_47 , V_32 [ V_33 ] ) ;
if ( V_38 == NULL )
goto V_44;
}
for ( V_40 = 0 ; V_40 < 256 ; V_40 ++ )
if ( V_37 -> V_48 [ V_40 ] > V_35 -> V_22 )
break;
V_8 = ( V_40 << V_35 -> V_45 . V_49 ) - 1 ;
if ( V_38 ) {
int V_50 ;
for ( V_40 = 0 ; V_40 < 256 ; V_40 ++ )
if ( V_38 -> V_48 [ V_40 ] > V_35 -> V_25 )
break;
V_50 = ( V_40 << V_35 -> V_47 . V_49 ) - 1 ;
if ( V_50 < V_8 )
V_8 = V_50 ;
}
if ( V_8 < 0 )
goto V_44;
if ( V_6 -> V_9 != & V_51 ) {
V_31 = F_26 ( V_6 -> V_9 , V_35 -> V_52 ) ;
if ( V_31 )
goto V_44;
} else if ( V_35 -> V_52 > 0 ) {
V_39 = F_27 ( V_4 , & V_53 , V_35 -> V_52 ) ;
if ( F_28 ( V_39 ) ) {
V_31 = F_29 ( V_39 ) ;
goto V_44;
}
}
F_30 ( V_4 ) ;
if ( V_39 ) {
F_31 ( V_6 -> V_9 , V_6 -> V_9 -> V_6 . V_13 ) ;
F_32 ( V_6 -> V_9 ) ;
V_6 -> V_9 = V_39 ;
}
V_6 -> V_52 = V_35 -> V_52 ;
V_6 -> V_25 = V_35 -> V_25 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_22 = V_35 -> V_22 ;
V_6 -> V_26 = V_6 -> V_22 ;
V_6 -> V_24 = V_6 -> V_25 ;
F_33 ( V_6 -> V_54 , V_37 ) ;
F_33 ( V_6 -> V_23 , V_38 ) ;
F_34 ( V_4 ) ;
V_31 = 0 ;
V_44:
if ( V_37 )
F_35 ( V_37 ) ;
if ( V_38 )
F_35 ( V_38 ) ;
return V_31 ;
}
static int F_36 ( struct V_3 * V_4 , struct V_29 * V_30 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_30 == NULL )
return - V_42 ;
V_6 -> V_21 = F_9 () ;
F_37 ( & V_6 -> V_27 , V_4 ) ;
V_6 -> V_9 = & V_51 ;
return F_22 ( V_4 , V_30 ) ;
}
static void F_38 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_21 ( & V_6 -> V_27 ) ;
if ( V_6 -> V_23 )
F_35 ( V_6 -> V_23 ) ;
if ( V_6 -> V_54 )
F_35 ( V_6 -> V_54 ) ;
F_32 ( V_6 -> V_9 ) ;
}
static int F_39 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_29 * V_55 ;
struct V_34 V_30 ;
V_55 = F_40 ( V_2 , V_56 ) ;
if ( V_55 == NULL )
goto V_57;
V_30 . V_52 = V_6 -> V_52 ;
V_30 . V_45 = V_6 -> V_54 -> V_45 ;
if ( V_6 -> V_23 )
V_30 . V_47 = V_6 -> V_23 -> V_45 ;
else
memset ( & V_30 . V_47 , 0 , sizeof( V_30 . V_47 ) ) ;
V_30 . V_25 = V_6 -> V_25 ;
V_30 . V_22 = V_6 -> V_22 ;
F_41 ( V_2 , V_43 , sizeof( V_30 ) , & V_30 ) ;
F_42 ( V_2 , V_55 ) ;
return V_2 -> V_14 ;
V_57:
F_43 ( V_2 , V_55 ) ;
return - 1 ;
}
static int F_44 ( struct V_3 * V_4 , unsigned long V_58 ,
struct V_1 * V_2 , struct V_59 * V_60 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
V_60 -> V_61 |= F_45 ( 1 ) ;
V_60 -> V_62 = V_6 -> V_9 -> V_63 ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 , unsigned long V_64 , struct V_3 * V_65 ,
struct V_3 * * V_66 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
if ( V_65 == NULL )
V_65 = & V_51 ;
F_30 ( V_4 ) ;
* V_66 = V_6 -> V_9 ;
V_6 -> V_9 = V_65 ;
F_31 ( * V_66 , ( * V_66 ) -> V_6 . V_13 ) ;
F_20 ( * V_66 ) ;
F_34 ( V_4 ) ;
return 0 ;
}
static struct V_3 * F_47 ( struct V_3 * V_4 , unsigned long V_64 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return V_6 -> V_9 ;
}
static unsigned long F_48 ( struct V_3 * V_4 , T_2 V_67 )
{
return 1 ;
}
static void F_49 ( struct V_3 * V_4 , unsigned long V_64 )
{
}
static void F_50 ( struct V_3 * V_4 , struct V_68 * V_69 )
{
if ( ! V_69 -> V_70 ) {
if ( V_69 -> V_71 >= V_69 -> V_72 )
if ( V_69 -> V_73 ( V_4 , 1 , V_69 ) < 0 ) {
V_69 -> V_70 = 1 ;
return;
}
V_69 -> V_71 ++ ;
}
}
static int T_3 F_51 ( void )
{
return F_52 ( & V_74 ) ;
}
static void T_4 F_53 ( void )
{
F_54 ( & V_74 ) ;
}

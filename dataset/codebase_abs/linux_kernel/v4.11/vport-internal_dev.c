static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , struct V_2 * V_3 )
{
int V_6 , V_7 ;
V_6 = V_5 -> V_6 ;
F_4 () ;
V_7 = F_5 ( F_1 ( V_3 ) -> V_8 , V_5 , NULL ) ;
F_6 () ;
if ( F_7 ( ! V_7 ) ) {
struct V_9 * V_10 = F_8 ( V_3 -> V_10 ) ;
F_9 ( & V_10 -> V_11 ) ;
V_10 -> V_12 += V_6 ;
V_10 -> V_13 ++ ;
F_10 ( & V_10 -> V_11 ) ;
} else {
V_3 -> V_14 . V_15 ++ ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
F_12 ( V_3 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
F_14 ( V_3 ) ;
return 0 ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_16 * V_17 )
{
F_16 ( V_17 -> V_18 , L_1 , sizeof( V_17 -> V_18 ) ) ;
}
static void F_17 ( struct V_2 * V_19 )
{
struct V_8 * V_8 = F_18 ( V_19 ) ;
F_19 ( V_8 ) ;
F_20 ( V_19 ) ;
}
static void
F_21 ( struct V_2 * V_19 , struct V_20 * V_14 )
{
int V_21 ;
memset ( V_14 , 0 , sizeof( * V_14 ) ) ;
V_14 -> V_22 = V_19 -> V_14 . V_22 ;
V_14 -> V_15 = V_19 -> V_14 . V_15 ;
V_14 -> V_23 = V_19 -> V_14 . V_23 ;
V_14 -> V_24 = V_19 -> V_14 . V_24 ;
F_22 (i) {
const struct V_9 * V_25 ;
struct V_9 V_26 ;
unsigned int V_27 ;
V_25 = F_23 ( V_19 -> V_10 , V_21 ) ;
do {
V_27 = F_24 ( & V_25 -> V_11 ) ;
V_26 = * V_25 ;
} while ( F_25 ( & V_25 -> V_11 , V_27 ) );
V_14 -> V_28 += V_26 . V_28 ;
V_14 -> V_29 += V_26 . V_29 ;
V_14 -> V_12 += V_26 . V_12 ;
V_14 -> V_13 += V_26 . V_13 ;
}
}
static void F_26 ( struct V_2 * V_19 , int V_30 )
{
V_19 -> V_31 = V_30 < 0 ? 0 : V_30 ;
}
static void F_27 ( struct V_2 * V_3 )
{
F_28 ( V_3 ) ;
V_3 -> V_32 = V_33 ;
V_3 -> V_34 = & V_35 ;
V_3 -> V_36 &= ~ V_37 ;
V_3 -> V_36 |= V_38 | V_39 |
V_40 | V_41 ;
V_3 -> V_42 = F_17 ;
V_3 -> V_43 = & V_44 ;
V_3 -> V_45 = & V_46 ;
V_3 -> V_47 = V_48 | V_49 | V_50 |
V_51 | V_52 |
V_53 | V_54 ;
V_3 -> V_55 = V_3 -> V_47 ;
V_3 -> V_56 = V_3 -> V_47 ;
V_3 -> V_47 |= V_57 | V_58 ;
V_3 -> V_59 = V_3 -> V_47 & ~ V_48 ;
F_29 ( V_3 ) ;
}
static struct V_8 * F_30 ( const struct V_60 * V_61 )
{
struct V_8 * V_8 ;
struct V_1 * V_1 ;
int V_7 ;
V_8 = F_31 ( 0 , & V_62 , V_61 ) ;
if ( F_32 ( V_8 ) ) {
V_7 = F_33 ( V_8 ) ;
goto error;
}
V_8 -> V_19 = F_34 ( sizeof( struct V_1 ) ,
V_61 -> V_63 , V_64 , F_27 ) ;
if ( ! V_8 -> V_19 ) {
V_7 = - V_65 ;
goto V_66;
}
V_8 -> V_19 -> V_10 = F_35 ( struct V_9 ) ;
if ( ! V_8 -> V_19 -> V_10 ) {
V_7 = - V_65 ;
goto V_67;
}
V_8 -> V_19 -> V_31 = V_8 -> V_68 -> V_69 ;
F_36 ( V_8 -> V_19 , F_37 ( V_8 -> V_68 ) ) ;
V_1 = F_1 ( V_8 -> V_19 ) ;
V_1 -> V_8 = V_8 ;
if ( V_8 -> V_70 == V_71 )
V_8 -> V_19 -> V_47 |= V_72 ;
F_38 () ;
V_7 = F_39 ( V_8 -> V_19 ) ;
if ( V_7 )
goto V_73;
F_40 ( V_8 -> V_19 , 1 ) ;
F_41 () ;
F_12 ( V_8 -> V_19 ) ;
return V_8 ;
V_73:
F_41 () ;
F_42 ( V_8 -> V_19 -> V_10 ) ;
V_67:
F_20 ( V_8 -> V_19 ) ;
V_66:
F_19 ( V_8 ) ;
error:
return F_43 ( V_7 ) ;
}
static void F_44 ( struct V_8 * V_8 )
{
F_14 ( V_8 -> V_19 ) ;
F_38 () ;
F_40 ( V_8 -> V_19 , - 1 ) ;
F_45 ( V_8 -> V_19 ) ;
F_42 ( V_8 -> V_19 -> V_10 ) ;
F_41 () ;
}
static T_1 F_46 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_19 ;
struct V_9 * V_14 ;
if ( F_47 ( ! ( V_3 -> V_74 & V_75 ) ) ) {
F_48 ( V_5 ) ;
V_3 -> V_14 . V_24 ++ ;
return V_76 ;
}
F_49 ( V_5 ) ;
F_50 ( V_5 ) ;
F_51 ( V_5 ) ;
V_5 -> V_77 = V_78 ;
V_5 -> V_79 = F_52 ( V_5 , V_3 ) ;
F_53 ( V_5 , F_54 ( V_5 ) , V_80 ) ;
V_14 = F_8 ( V_3 -> V_10 ) ;
F_9 ( & V_14 -> V_11 ) ;
V_14 -> V_29 ++ ;
V_14 -> V_28 += V_5 -> V_6 ;
F_10 ( & V_14 -> V_11 ) ;
F_55 ( V_5 ) ;
return V_76 ;
}
int F_56 ( const struct V_2 * V_3 )
{
return V_3 -> V_34 == & V_35 ;
}
struct V_8 * F_18 ( struct V_2 * V_3 )
{
if ( ! F_56 ( V_3 ) )
return NULL ;
return F_1 ( V_3 ) -> V_8 ;
}
int F_57 ( void )
{
int V_7 ;
V_7 = F_58 ( & V_46 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_59 ( & V_62 ) ;
if ( V_7 < 0 )
F_60 ( & V_46 ) ;
return V_7 ;
}
void F_61 ( void )
{
F_62 ( & V_62 ) ;
F_60 ( & V_46 ) ;
}

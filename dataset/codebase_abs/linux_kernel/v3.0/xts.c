static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_9 ;
T_2 * V_10 = & V_2 -> V_11 ;
int V_12 ;
if ( V_4 % 2 ) {
* V_10 |= V_13 ;
return - V_14 ;
}
F_3 ( V_8 , V_15 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_15 ) ;
V_12 = F_6 ( V_8 , V_3 + V_4 / 2 , V_4 / 2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_16 ) ;
V_8 = V_6 -> V_8 ;
F_3 ( V_8 , V_15 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_15 ) ;
V_12 = F_6 ( V_8 , V_3 , V_4 / 2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_16 ) ;
return 0 ;
}
static inline void F_9 ( struct V_17 * V_18 , void * V_19 , const void * V_20 )
{
F_10 ( V_19 , V_18 -> V_21 , V_20 ) ;
V_18 -> V_22 ( V_18 -> V_23 , V_19 , V_19 ) ;
F_10 ( V_19 , V_19 , V_18 -> V_21 ) ;
}
static int F_11 ( struct V_24 * V_25 ,
struct V_26 * V_27 , struct V_5 * V_6 ,
void (* F_12)( struct V_1 * , T_1 * , const T_1 * ) ,
void (* V_22)( struct V_1 * , T_1 * , const T_1 * ) )
{
int V_12 ;
unsigned int V_28 ;
const int V_29 = F_13 ( V_6 -> V_8 ) ;
struct V_17 V_18 = {
. V_23 = F_14 ( V_6 -> V_8 ) ,
. V_22 = V_22
} ;
T_1 * V_30 ;
T_1 * V_31 ;
V_12 = F_15 ( V_25 , V_27 ) ;
if ( ! V_27 -> V_32 )
return V_12 ;
V_18 . V_21 = ( V_33 * ) V_27 -> V_34 ;
V_28 = V_27 -> V_32 ;
V_30 = V_27 -> V_20 . V_35 . V_36 ;
V_31 = V_27 -> V_19 . V_35 . V_36 ;
F_12 ( F_14 ( V_6 -> V_9 ) , V_27 -> V_34 , V_27 -> V_34 ) ;
goto V_37;
for (; ; ) {
do {
F_16 ( V_18 . V_21 , V_18 . V_21 ) ;
V_37:
F_9 ( & V_18 , V_31 , V_30 ) ;
V_30 += V_29 ;
V_31 += V_29 ;
} while ( ( V_28 -= V_29 ) >= V_29 );
V_12 = F_17 ( V_25 , V_27 , V_28 ) ;
if ( ! V_27 -> V_32 )
break;
V_28 = V_27 -> V_32 ;
V_30 = V_27 -> V_20 . V_35 . V_36 ;
V_31 = V_27 -> V_19 . V_35 . V_36 ;
}
return V_12 ;
}
static int F_18 ( struct V_24 * V_38 , struct V_39 * V_19 ,
struct V_39 * V_20 , unsigned int V_32 )
{
struct V_5 * V_6 = F_19 ( V_38 -> V_23 ) ;
struct V_26 V_27 ;
F_20 ( & V_27 , V_19 , V_20 , V_32 ) ;
return F_11 ( V_38 , & V_27 , V_6 , F_21 ( V_6 -> V_9 ) -> V_40 ,
F_21 ( V_6 -> V_8 ) -> V_40 ) ;
}
static int F_22 ( struct V_24 * V_38 , struct V_39 * V_19 ,
struct V_39 * V_20 , unsigned int V_32 )
{
struct V_5 * V_6 = F_19 ( V_38 -> V_23 ) ;
struct V_26 V_27 ;
F_20 ( & V_27 , V_19 , V_20 , V_32 ) ;
return F_11 ( V_38 , & V_27 , V_6 , F_21 ( V_6 -> V_9 ) -> V_40 ,
F_21 ( V_6 -> V_8 ) -> V_41 ) ;
}
static int F_23 ( struct V_1 * V_23 )
{
struct V_7 * V_42 ;
struct V_43 * V_44 = ( void * ) V_23 -> V_45 ;
struct V_46 * V_47 = F_24 ( V_44 ) ;
struct V_5 * V_6 = F_2 ( V_23 ) ;
T_2 * V_10 = & V_23 -> V_11 ;
V_42 = F_25 ( V_47 ) ;
if ( F_26 ( V_42 ) )
return F_27 ( V_42 ) ;
if ( F_13 ( V_42 ) != 16 ) {
* V_10 |= V_48 ;
F_28 ( V_42 ) ;
return - V_14 ;
}
V_6 -> V_8 = V_42 ;
V_42 = F_25 ( V_47 ) ;
if ( F_26 ( V_42 ) ) {
F_28 ( V_6 -> V_8 ) ;
return F_27 ( V_42 ) ;
}
if ( F_13 ( V_42 ) != 16 ) {
F_28 ( V_42 ) ;
F_28 ( V_6 -> V_8 ) ;
* V_10 |= V_48 ;
return - V_14 ;
}
V_6 -> V_9 = V_42 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_23 )
{
struct V_5 * V_6 = F_2 ( V_23 ) ;
F_28 ( V_6 -> V_8 ) ;
F_28 ( V_6 -> V_9 ) ;
}
static struct V_43 * F_30 ( struct V_49 * * V_50 )
{
struct V_43 * V_44 ;
struct V_51 * V_52 ;
int V_12 ;
V_12 = F_31 ( V_50 , V_53 ) ;
if ( V_12 )
return F_32 ( V_12 ) ;
V_52 = F_33 ( V_50 , V_54 ,
V_55 ) ;
if ( F_26 ( V_52 ) )
return F_34 ( V_52 ) ;
V_44 = F_35 ( L_1 , V_52 ) ;
if ( F_26 ( V_44 ) )
goto V_56;
V_44 -> V_52 . V_57 = V_53 ;
V_44 -> V_52 . V_58 = V_52 -> V_58 ;
V_44 -> V_52 . V_59 = V_52 -> V_59 ;
if ( V_52 -> V_60 < 7 )
V_44 -> V_52 . V_60 = 7 ;
else
V_44 -> V_52 . V_60 = V_52 -> V_60 ;
V_44 -> V_52 . V_61 = & V_62 ;
V_44 -> V_52 . V_63 . V_64 = V_52 -> V_59 ;
V_44 -> V_52 . V_63 . V_65 =
2 * V_52 -> V_66 . V_67 ;
V_44 -> V_52 . V_63 . V_68 =
2 * V_52 -> V_66 . V_69 ;
V_44 -> V_52 . V_70 = sizeof( struct V_5 ) ;
V_44 -> V_52 . V_71 = F_23 ;
V_44 -> V_52 . V_72 = F_29 ;
V_44 -> V_52 . V_63 . F_1 = F_1 ;
V_44 -> V_52 . V_63 . F_18 = F_18 ;
V_44 -> V_52 . V_63 . F_22 = F_22 ;
V_56:
F_36 ( V_52 ) ;
return V_44 ;
}
static void free ( struct V_43 * V_44 )
{
F_37 ( F_24 ( V_44 ) ) ;
F_38 ( V_44 ) ;
}
static int T_3 F_39 ( void )
{
return F_40 ( & V_73 ) ;
}
static void T_4 F_41 ( void )
{
F_42 ( & V_73 ) ;
}

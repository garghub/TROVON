static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
memcpy ( V_2 -> V_7 , F_4 ( ( V_8 * ) V_6 -> V_9 ,
F_5 ( V_4 ) + 1 ) ,
F_6 ( V_4 ) ) ;
}
static void F_7 ( struct V_10 * V_11 , int V_12 )
{
struct V_1 * V_2 = V_11 -> V_13 ;
if ( V_12 )
goto V_14;
F_1 ( V_2 ) ;
V_14:
F_8 ( V_2 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_10 ( V_4 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_17 * V_18 ;
T_1 V_19 ;
void * V_13 ;
struct V_20 * V_21 , * V_22 ;
struct V_20 * V_23 ;
struct V_24 * V_25 ;
struct V_24 * V_26 ;
V_8 * V_7 ;
V_8 * V_27 ;
V_8 * V_28 ;
T_2 V_29 ;
unsigned int V_30 ;
unsigned int V_31 ;
int V_12 ;
V_18 = ( void * ) ( V_6 -> V_9 + V_16 -> V_32 ) ;
F_11 ( V_18 , F_12 ( V_4 ) ) ;
V_7 = V_2 -> V_7 ;
V_19 = V_2 -> V_33 . V_11 . V_34 ;
V_13 = V_2 -> V_33 . V_11 . V_13 ;
V_21 = V_2 -> V_33 . V_35 ;
V_22 = V_2 -> V_33 . V_23 ;
V_25 = F_13 ( V_21 ) ;
V_26 = F_13 ( V_22 ) ;
V_27 = F_14 ( V_25 ) ? NULL : F_15 ( V_25 ) + V_21 -> V_36 ;
V_28 = F_14 ( V_26 ) ? NULL : F_15 ( V_26 ) + V_22 -> V_36 ;
V_30 = F_6 ( V_4 ) ;
if ( V_27 != V_7 + V_30 && V_28 != V_7 + V_30 ) {
V_7 = F_4 ( ( V_8 * ) V_6 -> V_9 ,
F_5 ( V_4 ) + 1 ) ;
V_19 = F_7 ;
V_13 = V_2 ;
}
F_16 ( V_18 , V_2 -> V_33 . V_11 . V_37 , V_19 ,
V_13 ) ;
F_17 ( V_6 -> V_35 , 2 ) ;
F_18 ( V_6 -> V_35 , V_7 , V_30 ) ;
F_19 ( V_6 -> V_35 , V_21 , V_27 == V_7 + V_30 , 2 ) ;
V_23 = V_6 -> V_35 ;
if ( V_21 != V_22 ) {
F_17 ( V_6 -> V_23 , 2 ) ;
F_18 ( V_6 -> V_23 , V_7 , V_30 ) ;
F_19 ( V_6 -> V_23 , V_22 , V_28 == V_7 + V_30 , 2 ) ;
V_23 = V_6 -> V_23 ;
}
F_20 ( V_18 , V_6 -> V_35 , V_23 ,
V_2 -> V_33 . V_38 + V_30 ,
V_2 -> V_33 . V_39 ) ;
memcpy ( V_2 -> V_33 . V_39 , V_16 -> V_40 , V_30 ) ;
V_31 = V_30 ;
if ( V_30 > sizeof( V_41 ) ) {
memset ( V_2 -> V_7 , 0 , V_30 - sizeof( V_41 ) ) ;
V_31 = sizeof( V_41 ) ;
}
V_29 = F_21 ( V_2 -> V_29 ) ;
memcpy ( V_2 -> V_7 + V_30 - V_31 , & V_29 , V_31 ) ;
V_12 = F_22 ( V_18 ) ;
if ( V_12 )
goto V_14;
if ( V_7 != V_2 -> V_7 )
F_1 ( V_2 ) ;
V_14:
return V_12 ;
}
static int F_23 ( struct V_42 * V_43 )
{
struct V_3 * V_4 = F_24 ( V_43 ) ;
struct V_15 * V_16 = F_10 ( V_4 ) ;
unsigned long V_44 ;
unsigned int V_45 ;
int V_12 ;
F_25 ( & V_16 -> V_46 ) ;
V_44 = F_26 () - 1 ;
V_45 = sizeof( struct V_5 ) ;
if ( V_44 & V_45 ) {
V_44 &= V_45 ;
V_44 -- ;
}
V_44 = ~ V_44 ;
V_44 &= F_5 ( V_4 ) ;
V_45 += V_44 ;
V_45 += F_6 ( V_4 ) ;
V_45 = F_27 ( V_45 , F_26 () ) ;
V_16 -> V_32 = V_45 - sizeof( struct V_5 ) ;
V_43 -> V_47 . V_45 = V_45 +
sizeof( struct V_17 ) ;
V_12 = 0 ;
if ( ! F_28 () ) {
F_29 ( V_4 ) -> V_48 = F_9 ;
V_12 = F_30 ( V_49 , V_16 -> V_40 ,
F_6 ( V_4 ) ) ;
F_31 () ;
}
return V_12 ? : F_32 ( V_43 ) ;
}
static struct V_50 * F_33 ( struct V_51 * * V_52 )
{
struct V_50 * V_53 ;
int V_12 ;
V_53 = F_34 ( & V_54 , V_52 , 0 , 0 ) ;
if ( F_35 ( V_53 ) )
goto V_14;
V_12 = - V_55 ;
if ( V_53 -> V_56 . V_57 . V_30 != V_53 -> V_56 . V_58 )
goto V_59;
V_53 -> V_56 . V_60 = F_23 ;
V_53 -> V_56 . V_61 = V_62 ;
V_53 -> V_56 . V_63 = sizeof( struct V_15 ) ;
V_53 -> V_56 . V_63 += V_53 -> V_56 . V_57 . V_30 ;
V_14:
return V_53 ;
V_59:
F_36 ( V_53 ) ;
V_53 = F_37 ( V_12 ) ;
goto V_14;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_54 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_54 ) ;
}

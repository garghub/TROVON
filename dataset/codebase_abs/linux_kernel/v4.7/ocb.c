void F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , const T_1 * V_4 ,
T_2 V_5 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
enum V_16 V_17 ;
struct V_18 * V_19 ;
int V_20 ;
if ( V_11 -> V_21 >= V_22 ) {
F_2 ( L_1 ,
V_2 -> V_23 , V_4 ) ;
return;
}
F_3 ( V_2 , L_2 , V_4 ) ;
F_4 () ;
V_13 = F_5 ( V_2 -> V_24 . V_13 ) ;
if ( F_6 ( ! V_13 ) ) {
F_7 () ;
return;
}
V_20 = V_13 -> V_25 . V_26 -> V_20 ;
V_17 = F_8 ( & V_13 -> V_25 ) ;
F_7 () ;
V_19 = F_9 ( V_2 , V_4 , V_27 ) ;
if ( ! V_19 )
return;
V_15 = V_11 -> V_28 . V_29 -> V_30 [ V_20 ] ;
V_19 -> V_19 . V_5 [ V_20 ] =
F_10 ( V_15 , V_17 ) ;
F_11 ( & V_7 -> V_31 ) ;
F_12 ( & V_19 -> V_32 , & V_7 -> V_33 ) ;
F_13 ( & V_7 -> V_31 ) ;
F_14 ( & V_11 -> V_28 , & V_2 -> V_34 ) ;
}
static struct V_18 * F_15 ( struct V_18 * V_19 )
__acquires( T_3 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 V_4 [ V_35 ] ;
memcpy ( V_4 , V_19 -> V_19 . V_4 , V_35 ) ;
F_3 ( V_2 , L_3 ,
V_4 , V_2 -> V_23 ) ;
F_16 ( V_19 , V_36 ) ;
F_16 ( V_19 , V_37 ) ;
F_16 ( V_19 , V_38 ) ;
F_17 ( V_19 ) ;
if ( F_18 ( V_19 ) )
return F_19 ( V_2 , V_4 ) ;
return V_19 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
F_3 ( V_2 , L_4 ) ;
F_21 ( V_2 , V_39 ) ;
F_22 ( & V_7 -> V_40 ,
F_23 ( V_41 + V_42 ) ) ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_18 * V_19 ;
if ( V_7 -> V_43 != true )
return;
F_25 ( V_2 ) ;
F_26 ( & V_7 -> V_31 ) ;
while ( ! F_27 ( & V_7 -> V_33 ) ) {
V_19 = F_28 ( & V_7 -> V_33 ,
struct V_18 , V_32 ) ;
F_29 ( & V_19 -> V_32 ) ;
F_30 ( & V_7 -> V_31 ) ;
F_15 ( V_19 ) ;
F_7 () ;
F_26 ( & V_7 -> V_31 ) ;
}
F_30 ( & V_7 -> V_31 ) ;
if ( F_31 ( V_44 , & V_7 -> V_45 ) )
F_20 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static void F_33 ( unsigned long V_46 )
{
struct V_1 * V_2 = ( void * ) V_46 ;
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
F_34 ( V_44 , & V_7 -> V_45 ) ;
F_14 ( & V_11 -> V_28 , & V_2 -> V_34 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
F_36 ( & V_7 -> V_40 ,
F_33 ,
( unsigned long ) V_2 ) ;
F_37 ( & V_7 -> V_33 ) ;
F_38 ( & V_7 -> V_31 ) ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
T_2 V_49 = V_50 | V_51 ;
int V_52 ;
if ( V_7 -> V_43 == true )
return - V_53 ;
V_2 -> V_54 |= V_55 ;
V_2 -> V_56 = V_57 ;
V_2 -> V_58 = V_2 -> V_11 -> V_59 ;
F_40 ( & V_2 -> V_11 -> V_60 ) ;
V_52 = F_41 ( V_2 , & V_48 -> V_61 ,
V_62 ) ;
F_42 ( & V_2 -> V_11 -> V_60 ) ;
if ( V_52 )
return V_52 ;
F_43 ( V_2 , V_49 ) ;
V_7 -> V_43 = true ;
F_34 ( V_44 , & V_7 -> V_45 ) ;
F_14 ( & V_11 -> V_28 , & V_2 -> V_34 ) ;
F_44 ( V_2 -> V_63 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_18 * V_19 ;
V_7 -> V_43 = false ;
F_46 ( V_2 ) ;
F_26 ( & V_7 -> V_31 ) ;
while ( ! F_27 ( & V_7 -> V_33 ) ) {
V_19 = F_28 ( & V_7 -> V_33 ,
struct V_18 , V_32 ) ;
F_29 ( & V_19 -> V_32 ) ;
F_30 ( & V_7 -> V_31 ) ;
F_47 ( V_11 , V_19 ) ;
F_26 ( & V_7 -> V_31 ) ;
}
F_30 ( & V_7 -> V_31 ) ;
F_48 ( V_2 -> V_63 ) ;
F_49 ( V_64 , & V_2 -> V_65 ) ;
F_43 ( V_2 , V_50 ) ;
F_40 ( & V_2 -> V_11 -> V_60 ) ;
F_50 ( V_2 ) ;
F_42 ( & V_2 -> V_11 -> V_60 ) ;
F_51 ( & V_2 -> V_66 ) ;
F_52 ( & V_2 -> V_8 . V_9 . V_40 ) ;
return 0 ;
}

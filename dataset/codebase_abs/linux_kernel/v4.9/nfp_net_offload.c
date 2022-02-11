void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
struct V_4 V_5 ;
F_2 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_7 & V_8 )
F_3 ( & V_3 -> V_9 ,
V_10 + V_11 ) ;
F_4 ( & V_3 -> V_6 ) ;
V_5 . V_12 = F_5 ( V_3 , V_13 ) ;
V_5 . V_14 = F_5 ( V_3 , V_15 ) ;
if ( V_5 . V_12 != V_3 -> V_16 . V_12 )
V_3 -> V_17 = V_10 ;
V_3 -> V_16 = V_5 ;
}
static void F_6 ( struct V_2 * V_3 )
{
V_3 -> V_16 . V_12 = F_5 ( V_3 , V_13 ) ;
V_3 -> V_16 . V_14 = F_5 ( V_3 , V_15 ) ;
V_3 -> V_18 = V_3 -> V_16 ;
V_3 -> V_17 = V_10 ;
}
static int
F_7 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_21 * V_22 ;
F_8 ( V_23 ) ;
T_1 V_14 , V_12 ;
V_12 = V_3 -> V_16 . V_12 - V_3 -> V_18 . V_12 ;
V_14 = V_3 -> V_16 . V_14 - V_3 -> V_18 . V_14 ;
V_14 -= V_12 * V_24 ;
V_3 -> V_18 = V_3 -> V_16 ;
F_9 () ;
F_10 ( V_20 -> V_25 , & V_23 ) ;
F_11 (a, &actions, list)
F_12 ( V_22 , V_14 , V_12 , V_3 -> V_17 ) ;
F_13 () ;
return 0 ;
}
static int
F_14 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
const struct V_21 * V_22 ;
F_8 ( V_23 ) ;
if ( V_20 -> V_26 ) {
if ( F_15 ( V_20 -> V_25 ) )
return V_27 ;
return - V_28 ;
}
if ( ! F_16 ( V_20 -> V_25 ) )
return - V_28 ;
F_10 ( V_20 -> V_25 , & V_23 ) ;
F_11 (a, &actions, list) {
if ( F_17 ( V_22 ) )
return V_29 ;
if ( F_18 ( V_22 ) &&
F_19 ( V_22 ) == V_3 -> V_30 -> V_31 )
return V_32 ;
}
return - V_28 ;
}
static int
F_20 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
struct V_33 * V_34 ,
void * * V_35 , T_2 * V_36 , T_3 V_37 )
{
unsigned int V_38 = V_37 * sizeof( T_1 ) ;
enum V_39 V_40 ;
T_3 V_41 , V_42 ;
unsigned int V_43 ;
int V_44 ;
if ( ! F_21 ( V_45 ) )
return - V_28 ;
V_44 = F_14 ( V_3 , V_20 ) ;
if ( V_44 < 0 )
return V_44 ;
V_40 = V_44 ;
V_43 = F_22 ( V_3 , V_46 ) * 64 - 32 ;
if ( V_43 < V_3 -> V_30 -> V_47 ) {
F_23 ( V_3 , L_1 ) ;
return - V_28 ;
}
V_41 = F_24 ( V_3 , V_48 ) ;
V_42 = F_24 ( V_3 , V_49 ) ;
* V_35 = F_25 ( & V_3 -> V_50 -> V_51 , V_38 , V_36 ,
V_52 ) ;
if ( ! * V_35 )
return - V_53 ;
V_44 = F_26 ( V_20 -> V_54 , * V_35 , V_40 , V_41 , V_42 ,
V_37 , V_34 ) ;
if ( V_44 )
goto V_55;
return 0 ;
V_55:
F_27 ( & V_3 -> V_50 -> V_51 , V_38 , * V_35 , * V_36 ) ;
return V_44 ;
}
static void
F_28 ( struct V_2 * V_3 , T_4 V_56 ,
void * V_35 , T_2 V_36 ,
unsigned int V_38 , unsigned int V_57 ,
bool V_58 )
{
T_1 V_59 = V_36 ;
int V_60 ;
V_3 -> V_61 = ! ! ( V_56 & V_62 ) ;
if ( V_58 )
V_59 |= V_63 ;
F_29 ( V_3 , V_64 , V_57 ) ;
F_30 ( V_3 , V_65 , V_59 ) ;
V_60 = F_31 ( V_3 , V_66 ) ;
if ( V_60 )
F_32 ( V_3 , L_2 , V_60 ) ;
V_3 -> V_7 |= V_8 ;
F_33 ( V_3 , V_67 , V_3 -> V_7 ) ;
V_60 = F_31 ( V_3 , V_68 ) ;
if ( V_60 )
F_32 ( V_3 , L_3 , V_60 ) ;
F_27 ( & V_3 -> V_50 -> V_51 , V_38 , V_35 , V_36 ) ;
F_6 ( V_3 ) ;
F_3 ( & V_3 -> V_9 , V_10 + V_11 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
if ( ! ( V_3 -> V_7 & V_8 ) )
return 0 ;
F_2 ( & V_3 -> V_6 ) ;
V_3 -> V_7 &= ~ V_8 ;
F_4 ( & V_3 -> V_6 ) ;
F_33 ( V_3 , V_67 , V_3 -> V_7 ) ;
F_35 ( & V_3 -> V_9 ) ;
V_3 -> V_61 = 0 ;
return F_31 ( V_3 , V_68 ) ;
}
int
F_36 ( struct V_2 * V_3 , T_4 V_69 , T_5 V_70 ,
struct V_19 * V_20 )
{
struct V_33 V_34 ;
T_2 V_36 ;
T_3 V_37 ;
void * V_35 ;
int V_60 ;
V_37 = F_24 ( V_3 , V_71 ) ;
switch ( V_20 -> V_72 ) {
case V_73 :
if ( V_3 -> V_61 )
return - V_74 ;
V_60 = F_20 ( V_3 , V_20 , & V_34 , & V_35 ,
& V_36 , V_37 ) ;
if ( V_60 )
return V_60 ;
F_34 ( V_3 ) ;
F_28 ( V_3 , V_20 -> V_75 , V_35 ,
V_36 , V_37 * sizeof( T_1 ) ,
V_34 . V_57 , V_34 . V_58 ) ;
return 0 ;
case V_76 :
if ( V_3 -> V_7 & V_8 )
return - V_74 ;
V_60 = F_20 ( V_3 , V_20 , & V_34 , & V_35 ,
& V_36 , V_37 ) ;
if ( V_60 )
return V_60 ;
F_28 ( V_3 , V_20 -> V_75 , V_35 ,
V_36 , V_37 * sizeof( T_1 ) ,
V_34 . V_57 , V_34 . V_58 ) ;
return 0 ;
case V_77 :
return F_34 ( V_3 ) ;
case V_78 :
return F_7 ( V_3 , V_20 ) ;
default:
return - V_28 ;
}
}

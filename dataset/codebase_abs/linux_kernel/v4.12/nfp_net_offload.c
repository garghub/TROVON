void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
struct V_4 V_5 ;
F_2 ( & V_3 -> V_6 ) ;
if ( V_3 -> V_7 . V_8 & V_9 )
F_3 ( & V_3 -> V_10 ,
V_11 + V_12 ) ;
F_4 ( & V_3 -> V_6 ) ;
V_5 . V_13 = F_5 ( V_3 , V_14 ) ;
V_5 . V_15 = F_5 ( V_3 , V_16 ) ;
if ( V_5 . V_13 != V_3 -> V_17 . V_13 )
V_3 -> V_18 = V_11 ;
V_3 -> V_17 = V_5 ;
}
static void F_6 ( struct V_2 * V_3 )
{
V_3 -> V_17 . V_13 = F_5 ( V_3 , V_14 ) ;
V_3 -> V_17 . V_15 = F_5 ( V_3 , V_16 ) ;
V_3 -> V_19 = V_3 -> V_17 ;
V_3 -> V_18 = V_11 ;
}
static int
F_7 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
struct V_22 * V_23 ;
F_8 ( V_24 ) ;
T_1 V_15 , V_13 ;
V_13 = V_3 -> V_17 . V_13 - V_3 -> V_19 . V_13 ;
V_15 = V_3 -> V_17 . V_15 - V_3 -> V_19 . V_15 ;
V_15 -= V_13 * V_25 ;
V_3 -> V_19 = V_3 -> V_17 ;
F_9 () ;
F_10 ( V_21 -> V_26 , & V_24 ) ;
F_11 (a, &actions, list)
F_12 ( V_23 , V_15 , V_13 , V_3 -> V_18 ) ;
F_13 () ;
return 0 ;
}
static int
F_14 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
const struct V_22 * V_23 ;
F_8 ( V_24 ) ;
if ( ! V_21 -> V_26 )
return V_27 ;
if ( V_21 -> V_28 ) {
if ( F_15 ( V_21 -> V_26 ) )
return V_29 ;
return - V_30 ;
}
if ( ! F_16 ( V_21 -> V_26 ) )
return - V_30 ;
F_10 ( V_21 -> V_26 , & V_24 ) ;
F_11 (a, &actions, list) {
if ( F_17 ( V_23 ) )
return V_31 ;
if ( F_18 ( V_23 ) &&
F_19 ( V_23 ) == V_3 -> V_7 . V_32 -> V_33 )
return V_34 ;
}
return - V_30 ;
}
static int
F_20 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
struct V_35 * V_36 ,
void * * V_37 , T_2 * V_38 , T_3 V_39 )
{
unsigned int V_40 = V_39 * sizeof( T_1 ) ;
enum V_41 V_42 ;
T_3 V_43 , V_44 ;
unsigned int V_45 ;
int V_46 ;
if ( ! F_21 ( V_47 ) )
return - V_30 ;
V_46 = F_14 ( V_3 , V_21 ) ;
if ( V_46 < 0 )
return V_46 ;
V_42 = V_46 ;
V_45 = F_22 ( V_3 , V_48 ) * 64 - 32 ;
if ( V_45 < V_3 -> V_7 . V_32 -> V_49 ) {
F_23 ( V_3 , L_1 ) ;
return - V_30 ;
}
V_43 = F_24 ( V_3 , V_50 ) ;
V_44 = F_24 ( V_3 , V_51 ) ;
* V_37 = F_25 ( V_3 -> V_7 . V_52 , V_40 , V_38 , V_53 ) ;
if ( ! * V_37 )
return - V_54 ;
V_46 = F_26 ( V_21 -> V_55 , * V_37 , V_42 , V_43 , V_44 ,
V_39 , V_36 ) ;
if ( V_46 )
goto V_56;
return 0 ;
V_56:
F_27 ( V_3 -> V_7 . V_52 , V_40 , * V_37 , * V_38 ) ;
return V_46 ;
}
static void
F_28 ( struct V_2 * V_3 , T_4 V_57 ,
void * V_37 , T_2 V_38 ,
unsigned int V_40 , unsigned int V_58 ,
bool V_59 )
{
T_1 V_60 = V_38 ;
int V_61 ;
V_3 -> V_7 . V_62 = ! ! ( V_57 & V_63 ) ;
if ( V_59 )
V_60 |= V_64 ;
F_29 ( V_3 , V_65 , V_58 ) ;
F_30 ( V_3 , V_66 , V_60 ) ;
V_61 = F_31 ( V_3 , V_67 ) ;
if ( V_61 )
F_32 ( V_3 , L_2 , V_61 ) ;
V_3 -> V_7 . V_8 |= V_9 ;
F_33 ( V_3 , V_68 , V_3 -> V_7 . V_8 ) ;
V_61 = F_31 ( V_3 , V_69 ) ;
if ( V_61 )
F_32 ( V_3 , L_3 , V_61 ) ;
F_27 ( V_3 -> V_7 . V_52 , V_40 , V_37 , V_38 ) ;
F_6 ( V_3 ) ;
F_3 ( & V_3 -> V_10 , V_11 + V_12 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
if ( ! ( V_3 -> V_7 . V_8 & V_9 ) )
return 0 ;
F_2 ( & V_3 -> V_6 ) ;
V_3 -> V_7 . V_8 &= ~ V_9 ;
F_4 ( & V_3 -> V_6 ) ;
F_33 ( V_3 , V_68 , V_3 -> V_7 . V_8 ) ;
F_35 ( & V_3 -> V_10 ) ;
V_3 -> V_7 . V_62 = 0 ;
return F_31 ( V_3 , V_69 ) ;
}
int F_36 ( struct V_2 * V_3 , struct V_20 * V_21 )
{
struct V_35 V_36 ;
T_2 V_38 ;
T_3 V_39 ;
void * V_37 ;
int V_61 ;
V_39 = F_24 ( V_3 , V_70 ) ;
switch ( V_21 -> V_71 ) {
case V_72 :
if ( V_3 -> V_7 . V_62 )
return - V_73 ;
V_61 = F_20 ( V_3 , V_21 , & V_36 , & V_37 ,
& V_38 , V_39 ) ;
if ( V_61 )
return V_61 ;
F_34 ( V_3 ) ;
F_28 ( V_3 , V_21 -> V_74 , V_37 ,
V_38 , V_39 * sizeof( T_1 ) ,
V_36 . V_58 , V_36 . V_59 ) ;
return 0 ;
case V_75 :
if ( V_3 -> V_7 . V_8 & V_9 )
return - V_73 ;
V_61 = F_20 ( V_3 , V_21 , & V_36 , & V_37 ,
& V_38 , V_39 ) ;
if ( V_61 )
return V_61 ;
F_28 ( V_3 , V_21 -> V_74 , V_37 ,
V_38 , V_39 * sizeof( T_1 ) ,
V_36 . V_58 , V_36 . V_59 ) ;
return 0 ;
case V_76 :
return F_34 ( V_3 ) ;
case V_77 :
return F_7 ( V_3 , V_21 ) ;
default:
return - V_30 ;
}
}

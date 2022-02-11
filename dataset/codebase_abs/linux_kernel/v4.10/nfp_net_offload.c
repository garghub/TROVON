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
if ( ! V_20 -> V_25 )
return V_26 ;
if ( V_20 -> V_27 ) {
if ( F_15 ( V_20 -> V_25 ) )
return V_28 ;
return - V_29 ;
}
if ( ! F_16 ( V_20 -> V_25 ) )
return - V_29 ;
F_10 ( V_20 -> V_25 , & V_23 ) ;
F_11 (a, &actions, list) {
if ( F_17 ( V_22 ) )
return V_30 ;
if ( F_18 ( V_22 ) &&
F_19 ( V_22 ) == V_3 -> V_31 -> V_32 )
return V_33 ;
}
return - V_29 ;
}
static int
F_20 ( struct V_2 * V_3 ,
struct V_19 * V_20 ,
struct V_34 * V_35 ,
void * * V_36 , T_2 * V_37 , T_3 V_38 )
{
unsigned int V_39 = V_38 * sizeof( T_1 ) ;
enum V_40 V_41 ;
T_3 V_42 , V_43 ;
unsigned int V_44 ;
int V_45 ;
if ( ! F_21 ( V_46 ) )
return - V_29 ;
V_45 = F_14 ( V_3 , V_20 ) ;
if ( V_45 < 0 )
return V_45 ;
V_41 = V_45 ;
V_44 = F_22 ( V_3 , V_47 ) * 64 - 32 ;
if ( V_44 < V_3 -> V_31 -> V_48 ) {
F_23 ( V_3 , L_1 ) ;
return - V_29 ;
}
V_42 = F_24 ( V_3 , V_49 ) ;
V_43 = F_24 ( V_3 , V_50 ) ;
* V_36 = F_25 ( & V_3 -> V_51 -> V_52 , V_39 , V_37 ,
V_53 ) ;
if ( ! * V_36 )
return - V_54 ;
V_45 = F_26 ( V_20 -> V_55 , * V_36 , V_41 , V_42 , V_43 ,
V_38 , V_35 ) ;
if ( V_45 )
goto V_56;
return 0 ;
V_56:
F_27 ( & V_3 -> V_51 -> V_52 , V_39 , * V_36 , * V_37 ) ;
return V_45 ;
}
static void
F_28 ( struct V_2 * V_3 , T_4 V_57 ,
void * V_36 , T_2 V_37 ,
unsigned int V_39 , unsigned int V_58 ,
bool V_59 )
{
T_1 V_60 = V_37 ;
int V_61 ;
V_3 -> V_62 = ! ! ( V_57 & V_63 ) ;
if ( V_59 )
V_60 |= V_64 ;
F_29 ( V_3 , V_65 , V_58 ) ;
F_30 ( V_3 , V_66 , V_60 ) ;
V_61 = F_31 ( V_3 , V_67 ) ;
if ( V_61 )
F_32 ( V_3 , L_2 , V_61 ) ;
V_3 -> V_7 |= V_8 ;
F_33 ( V_3 , V_68 , V_3 -> V_7 ) ;
V_61 = F_31 ( V_3 , V_69 ) ;
if ( V_61 )
F_32 ( V_3 , L_3 , V_61 ) ;
F_27 ( & V_3 -> V_51 -> V_52 , V_39 , V_36 , V_37 ) ;
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
F_33 ( V_3 , V_68 , V_3 -> V_7 ) ;
F_35 ( & V_3 -> V_9 ) ;
V_3 -> V_62 = 0 ;
return F_31 ( V_3 , V_69 ) ;
}
int F_36 ( struct V_2 * V_3 , struct V_19 * V_20 )
{
struct V_34 V_35 ;
T_2 V_37 ;
T_3 V_38 ;
void * V_36 ;
int V_61 ;
V_38 = F_24 ( V_3 , V_70 ) ;
switch ( V_20 -> V_71 ) {
case V_72 :
if ( V_3 -> V_62 )
return - V_73 ;
V_61 = F_20 ( V_3 , V_20 , & V_35 , & V_36 ,
& V_37 , V_38 ) ;
if ( V_61 )
return V_61 ;
F_34 ( V_3 ) ;
F_28 ( V_3 , V_20 -> V_74 , V_36 ,
V_37 , V_38 * sizeof( T_1 ) ,
V_35 . V_58 , V_35 . V_59 ) ;
return 0 ;
case V_75 :
if ( V_3 -> V_7 & V_8 )
return - V_73 ;
V_61 = F_20 ( V_3 , V_20 , & V_35 , & V_36 ,
& V_37 , V_38 ) ;
if ( V_61 )
return V_61 ;
F_28 ( V_3 , V_20 -> V_74 , V_36 ,
V_37 , V_38 * sizeof( T_1 ) ,
V_35 . V_58 , V_35 . V_59 ) ;
return 0 ;
case V_76 :
return F_34 ( V_3 ) ;
case V_77 :
return F_7 ( V_3 , V_20 ) ;
default:
return - V_29 ;
}
}

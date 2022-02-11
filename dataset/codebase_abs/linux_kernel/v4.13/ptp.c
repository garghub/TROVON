static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_1 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
bool V_8 = false ;
unsigned long V_9 ;
T_2 V_10 ;
T_3 V_11 , V_12 ;
T_1 V_13 ;
if ( ( V_3 > V_2 -> V_14 ) || ( V_3 <= - 1000000000 ) )
return - V_15 ;
if ( V_3 < 0 ) {
V_8 = true ;
V_3 = - V_3 ;
}
V_13 = F_3 ( V_5 , & V_11 ) ;
if ( V_13 )
return V_13 ;
F_4 ( & V_5 -> V_16 , V_9 ) ;
V_12 = V_11 & V_17 ;
V_10 = V_12 ;
V_10 *= V_3 ;
V_10 = F_5 ( V_10 , 1000000000 ) ;
V_12 = V_8 ? ( V_12 - V_10 ) : ( V_12 + V_10 ) ;
V_11 &= ~ V_17 ;
V_11 |= V_12 ;
F_6 ( V_18 , V_11 ) ;
V_5 -> V_19 = V_3 ;
F_7 ( & V_5 -> V_16 , V_9 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_4 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_1 ) ;
unsigned long V_9 ;
F_4 ( & V_5 -> V_16 , V_9 ) ;
F_9 ( & V_5 -> V_20 , V_3 ) ;
F_7 ( & V_5 -> V_16 , V_9 ) ;
return 0 ;
}
static int F_10 ( T_5 * V_21 ,
struct V_22 * system ,
void * V_23 )
{
struct V_4 * V_5 = (struct V_4 * ) V_23 ;
struct V_6 * V_7 = & V_5 -> V_7 ;
unsigned long V_9 ;
int V_24 ;
T_3 V_25 ;
T_2 V_26 ;
T_2 V_27 ;
V_25 = F_11 ( V_28 ) ;
V_25 |= V_29 |
V_30 ;
F_6 ( V_28 , V_25 ) ;
for ( V_24 = 0 ; V_24 < V_31 ; ++ V_24 ) {
F_12 ( 1 ) ;
V_25 = F_11 ( V_28 ) ;
if ( V_25 & V_32 )
break;
}
if ( V_24 == V_31 )
return - V_33 ;
V_26 = F_11 ( V_34 ) ;
V_26 <<= 32 ;
V_26 |= F_11 ( V_35 ) ;
F_4 ( & V_5 -> V_16 , V_9 ) ;
* V_21 = F_13 ( F_14 ( & V_5 -> V_20 , V_26 ) ) ;
F_7 ( & V_5 -> V_16 , V_9 ) ;
V_27 = F_11 ( V_36 ) ;
V_27 <<= 32 ;
V_27 |= F_11 ( V_37 ) ;
* system = F_15 ( V_27 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_1 ) ;
return F_17 ( F_10 ,
V_5 , NULL , V_39 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_1 ) ;
unsigned long V_9 ;
T_2 V_42 ;
F_4 ( & V_5 -> V_16 , V_9 ) ;
V_42 = F_19 ( & V_5 -> V_20 ) ;
F_7 ( & V_5 -> V_16 , V_9 ) ;
* V_41 = F_20 ( V_42 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
const struct V_40 * V_41 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 ,
V_1 ) ;
unsigned long V_9 ;
T_2 V_42 ;
V_42 = F_22 ( V_41 ) ;
F_4 ( & V_5 -> V_16 , V_9 ) ;
F_23 ( & V_5 -> V_20 , & V_5 -> V_43 , V_42 ) ;
F_7 ( & V_5 -> V_16 , V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_1 T_6 * V_2 ,
struct V_44 T_6 * V_45 ,
int T_6 V_46 )
{
return - V_47 ;
}
static void F_25 ( struct V_48 * V_49 )
{
struct V_4 * V_5 = F_2 ( V_49 , struct V_4 ,
V_50 . V_49 ) ;
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_40 V_41 ;
V_5 -> V_1 . V_51 ( & V_5 -> V_1 , & V_41 ) ;
F_26 ( L_1 ,
( long long ) V_41 . V_52 , V_41 . V_53 ) ;
F_27 ( & V_5 -> V_50 ,
V_54 ) ;
}
void F_28 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
V_5 -> V_55 = NULL ;
if ( ! ( V_5 -> V_9 & V_56 ) )
return;
V_5 -> V_1 = V_57 ;
snprintf ( V_5 -> V_1 . V_58 ,
sizeof( V_5 -> V_1 . V_58 ) , L_2 ,
V_5 -> V_59 -> V_60 ) ;
switch ( V_7 -> V_61 . type ) {
case V_62 :
case V_63 :
case V_64 :
case V_65 :
if ( ( V_7 -> V_61 . type < V_63 ) ||
( F_11 ( V_66 ) & V_67 ) ) {
V_5 -> V_1 . V_14 = 24000000 - 1 ;
break;
}
case V_68 :
case V_69 :
V_5 -> V_1 . V_14 = 600000000 - 1 ;
break;
default:
break;
}
#ifdef F_29
if ( V_7 -> V_61 . type >= V_64 && F_30 ( V_70 ) )
V_5 -> V_1 . V_71 =
F_16 ;
#endif
F_31 ( & V_5 -> V_50 ,
F_25 ) ;
F_27 ( & V_5 -> V_50 ,
V_54 ) ;
V_5 -> V_55 = F_32 ( & V_5 -> V_1 ,
& V_5 -> V_72 -> V_73 ) ;
if ( F_33 ( V_5 -> V_55 ) ) {
V_5 -> V_55 = NULL ;
F_34 ( L_3 ) ;
} else if ( V_5 -> V_55 ) {
F_35 ( L_4 ) ;
}
}
void F_36 ( struct V_4 * V_5 )
{
if ( ! ( V_5 -> V_9 & V_56 ) )
return;
F_37 ( & V_5 -> V_50 ) ;
if ( V_5 -> V_55 ) {
F_38 ( V_5 -> V_55 ) ;
V_5 -> V_55 = NULL ;
F_35 ( L_5 ) ;
}
}

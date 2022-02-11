static T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
return F_3 ( V_7 ) & V_2 -> V_8 ;
}
T_2 F_4 ( struct V_9 * V_10 )
{
T_2 V_11 , V_12 ;
struct V_13 * V_14 = (struct V_13 * ) V_10 ;
V_12 = ( T_2 ) F_5 ( V_14 -> V_15 ) ;
V_11 = ( ( T_2 ) F_6 ( V_14 -> V_16 ) + ! V_12 ) << 16 ;
return V_11 | V_12 ;
}
void F_7 ( struct V_3 * V_4 ,
struct V_17 * V_18 ,
T_2 V_19 )
{
unsigned long V_20 ;
T_2 V_21 ;
F_8 ( & V_4 -> V_22 , V_20 ) ;
V_21 = F_9 ( & V_4 -> clock , V_19 ) ;
F_10 ( & V_4 -> V_22 , V_20 ) ;
memset ( V_18 , 0 , sizeof( struct V_17 ) ) ;
V_18 -> V_23 = F_11 ( V_21 ) ;
}
void F_12 ( struct V_3 * V_4 )
{
if ( V_4 -> V_24 ) {
F_13 ( V_4 -> V_24 ) ;
V_4 -> V_24 = NULL ;
F_14 ( V_4 , L_1 ) ;
}
}
void F_15 ( struct V_3 * V_4 )
{
bool V_25 = F_16 ( V_4 -> V_26 +
V_4 -> V_27 ) ;
unsigned long V_20 ;
if ( V_25 ) {
F_17 ( & V_4 -> V_22 , V_20 ) ;
F_18 ( & V_4 -> clock ) ;
F_19 ( & V_4 -> V_22 , V_20 ) ;
V_4 -> V_26 = V_28 ;
}
}
static int F_20 ( struct V_29 * V_30 , T_3 V_31 )
{
T_2 V_32 ;
T_4 V_33 , V_34 ;
int V_35 = 0 ;
unsigned long V_20 ;
struct V_3 * V_4 = F_2 ( V_30 , struct V_3 ,
V_29 ) ;
if ( V_31 < 0 ) {
V_35 = 1 ;
V_31 = - V_31 ;
}
V_34 = V_4 -> V_36 ;
V_32 = V_34 ;
V_32 *= V_31 ;
V_33 = F_21 ( V_32 , 1000000000ULL ) ;
F_17 ( & V_4 -> V_22 , V_20 ) ;
F_18 ( & V_4 -> clock ) ;
V_4 -> V_5 . V_34 = V_35 ? V_34 - V_33 : V_34 + V_33 ;
F_19 ( & V_4 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_22 ( struct V_29 * V_30 , T_5 V_31 )
{
struct V_3 * V_4 = F_2 ( V_30 , struct V_3 ,
V_29 ) ;
unsigned long V_20 ;
T_5 V_37 ;
F_17 ( & V_4 -> V_22 , V_20 ) ;
V_37 = F_18 ( & V_4 -> clock ) ;
V_37 += V_31 ;
F_23 ( & V_4 -> clock , & V_4 -> V_5 , V_37 ) ;
F_19 ( & V_4 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_24 ( struct V_29 * V_30 , struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_30 , struct V_3 ,
V_29 ) ;
unsigned long V_20 ;
T_4 V_40 ;
T_2 V_41 ;
F_17 ( & V_4 -> V_22 , V_20 ) ;
V_41 = F_18 ( & V_4 -> clock ) ;
F_19 ( & V_4 -> V_22 , V_20 ) ;
V_39 -> V_42 = F_25 ( V_41 , V_43 , & V_40 ) ;
V_39 -> V_44 = V_40 ;
return 0 ;
}
static int F_26 ( struct V_29 * V_30 ,
const struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_30 , struct V_3 ,
V_29 ) ;
T_2 V_41 = F_27 ( V_39 ) ;
unsigned long V_20 ;
F_17 ( & V_4 -> V_22 , V_20 ) ;
F_23 ( & V_4 -> clock , & V_4 -> V_5 , V_41 ) ;
F_19 ( & V_4 -> V_22 , V_20 ) ;
return 0 ;
}
static int F_28 ( struct V_29 T_6 * V_30 ,
struct V_45 T_6 * V_46 ,
int T_6 V_47 )
{
return - V_48 ;
}
void F_29 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned long V_20 ;
T_2 V_41 ;
F_30 ( & V_4 -> V_22 ) ;
memset ( & V_4 -> V_5 , 0 , sizeof( V_4 -> V_5 ) ) ;
V_4 -> V_5 . V_49 = F_1 ;
V_4 -> V_5 . V_8 = F_31 ( 48 ) ;
V_4 -> V_5 . V_50 = 14 ;
V_4 -> V_5 . V_34 =
F_32 ( 1000 * V_7 -> V_51 . V_52 , V_4 -> V_5 . V_50 ) ;
V_4 -> V_36 = V_4 -> V_5 . V_34 ;
F_17 ( & V_4 -> V_22 , V_20 ) ;
F_23 ( & V_4 -> clock , & V_4 -> V_5 ,
F_33 ( F_34 () ) ) ;
F_19 ( & V_4 -> V_22 , V_20 ) ;
V_41 = F_35 ( & V_4 -> V_5 , V_4 -> V_5 . V_8 ) ;
F_36 ( V_41 , V_43 / 2 / V_53 ) ;
V_4 -> V_27 = V_41 ;
V_4 -> V_29 = V_54 ;
snprintf ( V_4 -> V_29 . V_55 , 16 , L_2 ) ;
V_4 -> V_24 = F_37 ( & V_4 -> V_29 ,
& V_4 -> V_56 -> V_7 ) ;
if ( F_38 ( V_4 -> V_24 ) ) {
V_4 -> V_24 = NULL ;
F_39 ( V_4 , L_3 ) ;
} else {
F_14 ( V_4 , L_4 ) ;
}
}

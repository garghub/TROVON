static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_2 ( & V_2 -> V_4 [ V_3 ] ) & 0xf ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned int V_5 ,
unsigned int V_3 )
{
F_4 ( V_5 , & V_2 -> V_4 [ V_3 ] ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_6 , V_7 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_8 | V_9 ,
V_7 ) ;
}
static int F_7 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
F_9 ( & V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
V_13 -> V_15 = F_1 ( V_2 , V_16 ) * 10 +
F_1 ( V_2 , V_17 ) ;
V_13 -> V_18 = F_1 ( V_2 , V_19 ) * 10 +
F_1 ( V_2 , V_20 ) ;
V_13 -> V_21 = F_1 ( V_2 , V_22 ) * 10 +
F_1 ( V_2 , V_23 ) ;
V_13 -> V_24 = F_1 ( V_2 , V_25 ) * 10 +
F_1 ( V_2 , V_26 ) ;
V_13 -> V_27 = F_1 ( V_2 , V_28 ) ;
V_13 -> V_29 = F_1 ( V_2 , V_30 ) * 10 +
F_1 ( V_2 , V_31 ) - 1 ;
V_13 -> V_32 = F_1 ( V_2 , V_33 ) * 10 +
F_1 ( V_2 , V_34 ) ;
if ( V_13 -> V_32 <= 69 )
V_13 -> V_32 += 100 ;
F_6 ( V_2 ) ;
F_10 ( & V_2 -> V_14 ) ;
return F_11 ( V_13 ) ;
}
static int F_12 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_8 ( V_11 ) ;
F_9 ( & V_2 -> V_14 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_13 -> V_15 / 10 , V_16 ) ;
F_3 ( V_2 , V_13 -> V_15 % 10 , V_17 ) ;
F_3 ( V_2 , V_13 -> V_18 / 10 , V_19 ) ;
F_3 ( V_2 , V_13 -> V_18 % 10 , V_20 ) ;
F_3 ( V_2 , V_13 -> V_21 / 10 , V_22 ) ;
F_3 ( V_2 , V_13 -> V_21 % 10 , V_23 ) ;
F_3 ( V_2 , V_13 -> V_24 / 10 , V_25 ) ;
F_3 ( V_2 , V_13 -> V_24 % 10 , V_26 ) ;
if ( V_13 -> V_27 != - 1 )
F_3 ( V_2 , V_13 -> V_27 , V_28 ) ;
F_3 ( V_2 , ( V_13 -> V_29 + 1 ) / 10 , V_30 ) ;
F_3 ( V_2 , ( V_13 -> V_29 + 1 ) % 10 , V_31 ) ;
if ( V_13 -> V_32 >= 100 )
V_13 -> V_32 -= 100 ;
F_3 ( V_2 , V_13 -> V_32 / 10 , V_33 ) ;
F_3 ( V_2 , V_13 -> V_32 % 10 , V_34 ) ;
F_6 ( V_2 ) ;
F_10 ( & V_2 -> V_14 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_35 * V_36 , struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 , T_2 V_42 , T_3 V_43 )
{
struct V_10 * V_11 = F_14 ( V_38 , struct V_10 , V_38 ) ;
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_1 V_44 ;
F_9 ( & V_2 -> V_14 ) ;
for ( V_44 = 0 ; V_43 > 0 && V_42 < V_7 ; V_44 ++ , V_43 -- ) {
T_4 V_45 ;
F_3 ( V_2 ,
V_8 | V_46 ,
V_7 ) ;
V_45 = F_1 ( V_2 , V_42 ) << 4 ;
F_3 ( V_2 ,
V_8 | V_47 ,
V_7 ) ;
V_45 |= F_1 ( V_2 , V_42 ++ ) ;
F_3 ( V_2 , V_8 | V_9 ,
V_7 ) ;
* V_41 ++ = V_45 ;
}
F_10 ( & V_2 -> V_14 ) ;
return V_44 ;
}
static T_1 F_15 ( struct V_35 * V_36 , struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_41 , T_2 V_42 , T_3 V_43 )
{
struct V_10 * V_11 = F_14 ( V_38 , struct V_10 , V_38 ) ;
struct V_1 * V_2 = F_8 ( V_11 ) ;
T_1 V_44 ;
F_9 ( & V_2 -> V_14 ) ;
for ( V_44 = 0 ; V_43 > 0 && V_42 < V_7 ; V_44 ++ , V_43 -- ) {
T_4 V_45 = * V_41 ++ ;
F_3 ( V_2 ,
V_8 | V_46 ,
V_7 ) ;
F_3 ( V_2 , V_45 >> 4 , V_42 ) ;
F_3 ( V_2 ,
V_8 | V_47 ,
V_7 ) ;
F_3 ( V_2 , V_45 & 0xf , V_42 ++ ) ;
F_3 ( V_2 , V_8 | V_9 ,
V_7 ) ;
}
F_10 ( & V_2 -> V_14 ) ;
return V_44 ;
}
static int T_5 F_16 ( struct V_48 * V_11 )
{
struct V_49 * V_50 ;
struct V_1 * V_2 ;
struct V_51 * V_52 ;
int error ;
V_50 = F_17 ( V_11 , V_53 , 0 ) ;
if ( ! V_50 )
return - V_54 ;
V_2 = F_18 ( & V_11 -> V_11 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_56 ;
V_2 -> V_4 = F_19 ( & V_11 -> V_11 , V_50 -> V_57 , F_20 ( V_50 ) ) ;
if ( ! V_2 -> V_4 )
return - V_56 ;
F_21 ( & V_2 -> V_58 ) ;
V_2 -> V_58 . V_59 . V_60 = L_1 ;
V_2 -> V_58 . V_59 . V_61 = V_62 | V_63 ;
V_2 -> V_58 . V_64 = F_13 ;
V_2 -> V_58 . V_65 = F_15 ;
V_2 -> V_58 . V_43 = V_7 ;
F_22 ( & V_2 -> V_14 ) ;
F_23 ( V_11 , V_2 ) ;
V_52 = F_24 ( & V_11 -> V_11 , L_2 , & V_66 ,
V_67 ) ;
if ( F_25 ( V_52 ) ) {
error = F_26 ( V_52 ) ;
goto V_68;
}
V_2 -> V_52 = V_52 ;
error = F_27 ( & V_11 -> V_11 . V_38 , & V_2 -> V_58 ) ;
if ( error )
goto V_68;
return 0 ;
V_68:
F_23 ( V_11 , NULL ) ;
return error ;
}
static int T_6 F_28 ( struct V_48 * V_11 )
{
struct V_1 * V_2 = F_29 ( V_11 ) ;
F_30 ( & V_11 -> V_11 . V_38 , & V_2 -> V_58 ) ;
return 0 ;
}

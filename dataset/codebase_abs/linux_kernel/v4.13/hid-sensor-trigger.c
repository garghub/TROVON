static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int integer , V_11 , V_12 ;
int V_13 ;
V_12 = F_4 ( V_5 , 100000 , & integer , & V_11 ) ;
if ( V_12 )
return V_12 ;
V_13 = integer * 1000 + V_11 / 1000 ;
V_12 = F_5 ( V_10 , V_13 ) ;
if ( V_12 < 0 )
return V_6 ;
V_10 -> V_14 = F_6 ( V_10 ) ;
return V_6 ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_13 ;
V_13 = F_6 ( V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_5 , L_1 , V_13 / 1000 , ( V_13 % 1000 ) * 1000 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
int V_13 ;
V_13 = F_6 ( V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
return sprintf ( V_5 , L_2 , ! ! V_13 ) ;
}
static void F_9 ( struct V_7 * V_8 ,
struct V_9 * V_15 )
{
if ( ! F_10 ( V_15 ) )
return;
F_11 ( V_8 -> V_16 , V_17 ) ;
}
static int F_12 ( struct V_9 * V_15 , bool V_18 )
{
int V_19 ;
int V_20 ;
T_3 V_21 = 0 ;
if ( V_18 ) {
if ( F_13 ( V_15 -> V_22 ) )
return - V_23 ;
F_14 ( & V_15 -> V_24 ) ;
V_19 = F_15 ( V_15 -> V_22 ,
V_15 -> V_25 . V_26 ,
V_15 -> V_25 . V_27 ,
V_28 ) ;
V_20 = F_15 ( V_15 -> V_22 ,
V_15 -> V_29 . V_26 ,
V_15 -> V_29 . V_27 ,
V_30 ) ;
V_21 = F_16 ( V_15 ) ;
} else {
int V_31 ;
V_31 = F_17 ( & V_15 -> V_24 ) ;
if ( V_31 < 0 )
return 0 ;
F_18 ( V_15 -> V_22 ) ;
V_19 = F_15 ( V_15 -> V_22 ,
V_15 -> V_25 . V_26 ,
V_15 -> V_25 . V_27 ,
V_32 ) ;
V_20 = F_15 ( V_15 -> V_22 ,
V_15 -> V_29 . V_26 ,
V_15 -> V_29 . V_27 ,
V_33 ) ;
}
if ( V_19 >= 0 ) {
V_19 += V_15 -> V_25 . V_34 ;
F_19 ( V_15 -> V_22 , V_15 -> V_25 . V_26 ,
V_15 -> V_25 . V_27 , sizeof( V_19 ) ,
& V_19 ) ;
}
if ( V_20 >= 0 ) {
V_20 += V_15 -> V_29 . V_34 ;
F_19 ( V_15 -> V_22 , V_15 -> V_29 . V_26 ,
V_15 -> V_29 . V_27 ,
sizeof( V_20 ) ,
& V_20 ) ;
}
F_20 ( L_3 ,
V_15 -> V_35 -> V_36 , V_19 , V_20 ) ;
F_21 ( V_15 -> V_22 , V_15 -> V_25 . V_26 ,
V_15 -> V_25 . V_27 ,
sizeof( V_19 ) , & V_19 ) ;
if ( V_18 && V_21 )
F_22 ( V_21 * 2 ) ;
return 0 ;
}
int F_23 ( struct V_9 * V_15 , bool V_18 )
{
#ifdef F_24
int V_12 ;
F_25 ( & V_15 -> V_37 , V_18 ) ;
if ( V_18 )
V_12 = F_26 ( & V_15 -> V_35 -> V_2 ) ;
else {
F_27 ( & V_15 -> V_35 -> V_2 ) ;
F_28 ( & V_15 -> V_35 -> V_2 ) ;
V_12 = F_29 ( & V_15 -> V_35 -> V_2 ) ;
}
if ( V_12 < 0 ) {
if ( V_18 )
F_30 ( & V_15 -> V_35 -> V_2 ) ;
return V_12 ;
}
return 0 ;
#else
F_25 ( & V_15 -> V_37 , V_18 ) ;
return F_12 ( V_15 , V_18 ) ;
#endif
}
static void F_31 ( struct V_38 * V_39 )
{
struct V_9 * V_10 = F_32 ( V_39 ,
struct V_9 ,
V_39 ) ;
if ( V_10 -> V_40 >= 0 )
F_19 ( V_10 -> V_22 , V_10 -> V_41 . V_26 ,
V_10 -> V_41 . V_27 ,
sizeof( V_10 -> V_40 ) ,
& V_10 -> V_40 ) ;
if ( V_10 -> V_42 >= 0 )
F_19 ( V_10 -> V_22 ,
V_10 -> V_43 . V_26 ,
V_10 -> V_43 . V_27 ,
sizeof( V_10 -> V_42 ) ,
& V_10 -> V_42 ) ;
if ( V_10 -> V_14 > 0 )
F_5 ( V_10 , V_10 -> V_14 ) ;
F_12 ( V_10 , true ) ;
}
static int F_33 ( struct V_44 * V_45 ,
bool V_18 )
{
return F_23 ( F_34 ( V_45 ) , V_18 ) ;
}
void F_35 ( struct V_9 * V_10 )
{
F_36 ( & V_10 -> V_35 -> V_2 ) ;
F_37 ( & V_10 -> V_35 -> V_2 ) ;
F_30 ( & V_10 -> V_35 -> V_2 ) ;
F_38 ( & V_10 -> V_39 ) ;
F_39 ( V_10 -> V_46 ) ;
F_40 ( V_10 -> V_46 ) ;
}
int F_41 ( struct V_7 * V_8 , const char * V_36 ,
struct V_9 * V_10 )
{
int V_12 ;
struct V_44 * V_45 ;
V_45 = F_42 ( L_4 , V_36 , V_8 -> V_47 ) ;
if ( V_45 == NULL ) {
F_43 ( & V_8 -> V_2 , L_5 ) ;
V_12 = - V_48 ;
goto V_49;
}
V_45 -> V_2 . V_50 = V_8 -> V_2 . V_50 ;
F_44 ( V_45 , V_10 ) ;
V_45 -> V_51 = & V_52 ;
V_12 = F_45 ( V_45 ) ;
if ( V_12 ) {
F_43 ( & V_8 -> V_2 , L_6 ) ;
goto V_53;
}
V_10 -> V_46 = V_45 ;
V_8 -> V_45 = F_46 ( V_45 ) ;
F_9 ( V_8 , V_10 ) ;
V_12 = F_47 ( & V_8 -> V_2 ) ;
if ( V_12 )
goto V_54;
F_48 ( V_8 , V_10 ) ;
F_49 ( & V_10 -> V_39 , F_31 ) ;
F_50 ( & V_10 -> V_35 -> V_2 , true ) ;
F_51 ( & V_10 -> V_35 -> V_2 ) ;
F_52 ( & V_10 -> V_35 -> V_2 ,
3000 ) ;
return V_12 ;
V_54:
F_39 ( V_45 ) ;
V_53:
F_40 ( V_45 ) ;
V_49:
return V_12 ;
}
static int T_4 F_53 ( struct V_1 * V_2 )
{
struct V_55 * V_35 = F_54 ( V_2 ) ;
struct V_7 * V_8 = F_55 ( V_35 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
return F_12 ( V_10 , false ) ;
}
static int T_4 F_56 ( struct V_1 * V_2 )
{
struct V_55 * V_35 = F_54 ( V_2 ) ;
struct V_7 * V_8 = F_55 ( V_35 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
F_57 ( & V_10 -> V_39 ) ;
return 0 ;
}
static int T_4 F_58 ( struct V_1 * V_2 )
{
struct V_55 * V_35 = F_54 ( V_2 ) ;
struct V_7 * V_8 = F_55 ( V_35 ) ;
struct V_9 * V_10 = F_3 ( V_8 ) ;
return F_12 ( V_10 , true ) ;
}

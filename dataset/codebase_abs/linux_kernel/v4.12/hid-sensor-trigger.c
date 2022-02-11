static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
int V_5 ;
T_1 V_6 = 0 ;
if ( V_3 ) {
if ( ! F_2 ( & V_2 -> V_7 ) )
return 0 ;
if ( F_3 ( V_2 -> V_8 ) )
return - V_9 ;
F_4 ( & V_2 -> V_10 ) ;
V_4 = F_5 ( V_2 -> V_8 ,
V_2 -> V_11 . V_12 ,
V_2 -> V_11 . V_13 ,
V_14 ) ;
V_5 = F_5 ( V_2 -> V_8 ,
V_2 -> V_15 . V_12 ,
V_2 -> V_15 . V_13 ,
V_16 ) ;
V_6 = F_6 ( V_2 ) ;
} else {
int V_17 ;
V_17 = F_7 ( & V_2 -> V_10 ) ;
if ( V_17 < 0 )
return 0 ;
F_8 ( V_2 -> V_8 ) ;
V_4 = F_5 ( V_2 -> V_8 ,
V_2 -> V_11 . V_12 ,
V_2 -> V_11 . V_13 ,
V_18 ) ;
V_5 = F_5 ( V_2 -> V_8 ,
V_2 -> V_15 . V_12 ,
V_2 -> V_15 . V_13 ,
V_19 ) ;
}
if ( V_4 >= 0 ) {
V_4 += V_2 -> V_11 . V_20 ;
F_9 ( V_2 -> V_8 , V_2 -> V_11 . V_12 ,
V_2 -> V_11 . V_13 , sizeof( V_4 ) ,
& V_4 ) ;
}
if ( V_5 >= 0 ) {
V_5 += V_2 -> V_15 . V_20 ;
F_9 ( V_2 -> V_8 , V_2 -> V_15 . V_12 ,
V_2 -> V_15 . V_13 ,
sizeof( V_5 ) ,
& V_5 ) ;
}
F_10 ( V_2 -> V_8 , V_2 -> V_11 . V_12 ,
V_2 -> V_11 . V_13 ,
sizeof( V_4 ) , & V_4 ) ;
if ( V_3 && V_6 )
F_11 ( V_6 * 2 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , bool V_3 )
{
#ifdef F_13
int V_21 ;
F_14 ( & V_2 -> V_7 , V_3 ) ;
if ( V_3 )
V_21 = F_15 ( & V_2 -> V_22 -> V_23 ) ;
else {
F_16 ( & V_2 -> V_22 -> V_23 ) ;
V_21 = F_17 ( & V_2 -> V_22 -> V_23 ) ;
}
if ( V_21 < 0 ) {
if ( V_3 )
F_18 ( & V_2 -> V_22 -> V_23 ) ;
return V_21 ;
}
return 0 ;
#else
F_14 ( & V_2 -> V_7 , V_3 ) ;
return F_1 ( V_2 , V_3 ) ;
#endif
}
static void F_19 ( struct V_24 * V_25 )
{
struct V_1 * V_26 = F_20 ( V_25 ,
struct V_1 ,
V_25 ) ;
if ( V_26 -> V_27 >= 0 )
F_9 ( V_26 -> V_8 , V_26 -> V_28 . V_12 ,
V_26 -> V_28 . V_13 ,
sizeof( V_26 -> V_27 ) ,
& V_26 -> V_27 ) ;
if ( V_26 -> V_29 >= 0 )
F_9 ( V_26 -> V_8 ,
V_26 -> V_30 . V_12 ,
V_26 -> V_30 . V_13 ,
sizeof( V_26 -> V_29 ) ,
& V_26 -> V_29 ) ;
F_1 ( V_26 , true ) ;
}
static int F_21 ( struct V_31 * V_32 ,
bool V_3 )
{
return F_12 ( F_22 ( V_32 ) , V_3 ) ;
}
void F_23 ( struct V_1 * V_26 )
{
F_24 ( & V_26 -> V_22 -> V_23 ) ;
F_25 ( & V_26 -> V_22 -> V_23 ) ;
F_18 ( & V_26 -> V_22 -> V_23 ) ;
F_26 ( & V_26 -> V_25 ) ;
F_27 ( V_26 -> V_33 ) ;
F_28 ( V_26 -> V_33 ) ;
}
int F_29 ( struct V_34 * V_35 , const char * V_36 ,
struct V_1 * V_26 )
{
int V_21 ;
struct V_31 * V_32 ;
V_32 = F_30 ( L_1 , V_36 , V_35 -> V_37 ) ;
if ( V_32 == NULL ) {
F_31 ( & V_35 -> V_23 , L_2 ) ;
V_21 = - V_38 ;
goto V_39;
}
V_32 -> V_23 . V_40 = V_35 -> V_23 . V_40 ;
F_32 ( V_32 , V_26 ) ;
V_32 -> V_41 = & V_42 ;
V_21 = F_33 ( V_32 ) ;
if ( V_21 ) {
F_31 ( & V_35 -> V_23 , L_3 ) ;
goto V_43;
}
V_26 -> V_33 = V_32 ;
V_35 -> V_32 = F_34 ( V_32 ) ;
V_21 = F_35 ( & V_35 -> V_23 ) ;
if ( V_21 )
goto V_44;
F_36 ( V_35 , V_26 ) ;
F_37 ( & V_26 -> V_25 , F_19 ) ;
F_38 ( & V_26 -> V_22 -> V_23 , true ) ;
F_39 ( & V_26 -> V_22 -> V_23 ) ;
F_40 ( & V_26 -> V_22 -> V_23 ,
3000 ) ;
F_41 ( & V_26 -> V_22 -> V_23 ) ;
return V_21 ;
V_44:
F_27 ( V_32 ) ;
V_43:
F_28 ( V_32 ) ;
V_39:
return V_21 ;
}
static int T_2 F_42 ( struct V_45 * V_23 )
{
struct V_46 * V_22 = F_43 ( V_23 ) ;
struct V_34 * V_35 = F_44 ( V_22 ) ;
struct V_1 * V_26 = F_45 ( V_35 ) ;
return F_1 ( V_26 , false ) ;
}
static int T_2 F_46 ( struct V_45 * V_23 )
{
struct V_46 * V_22 = F_43 ( V_23 ) ;
struct V_34 * V_35 = F_44 ( V_22 ) ;
struct V_1 * V_26 = F_45 ( V_35 ) ;
F_47 ( & V_26 -> V_25 ) ;
return 0 ;
}
static int T_2 F_48 ( struct V_45 * V_23 )
{
struct V_46 * V_22 = F_43 ( V_23 ) ;
struct V_34 * V_35 = F_44 ( V_22 ) ;
struct V_1 * V_26 = F_45 ( V_35 ) ;
return F_1 ( V_26 , true ) ;
}

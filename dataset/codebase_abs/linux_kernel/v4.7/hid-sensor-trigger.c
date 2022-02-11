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
static int F_19 ( struct V_24 * V_25 ,
bool V_3 )
{
return F_12 ( F_20 ( V_25 ) , V_3 ) ;
}
void F_21 ( struct V_1 * V_26 )
{
F_22 ( V_26 -> V_27 ) ;
F_23 ( V_26 -> V_27 ) ;
}
int F_24 ( struct V_28 * V_29 , const char * V_30 ,
struct V_1 * V_26 )
{
int V_21 ;
struct V_24 * V_25 ;
V_25 = F_25 ( L_1 , V_30 , V_29 -> V_31 ) ;
if ( V_25 == NULL ) {
F_26 ( & V_29 -> V_23 , L_2 ) ;
V_21 = - V_32 ;
goto V_33;
}
V_25 -> V_23 . V_34 = V_29 -> V_23 . V_34 ;
F_27 ( V_25 , V_26 ) ;
V_25 -> V_35 = & V_36 ;
V_21 = F_28 ( V_25 ) ;
if ( V_21 ) {
F_26 ( & V_29 -> V_23 , L_3 ) ;
goto V_37;
}
V_26 -> V_27 = V_25 ;
V_29 -> V_25 = F_29 ( V_25 ) ;
V_21 = F_30 ( & V_29 -> V_23 ) ;
if ( V_21 )
goto V_38;
F_31 ( V_29 , V_26 ) ;
F_32 ( & V_26 -> V_22 -> V_23 , true ) ;
F_33 ( & V_26 -> V_22 -> V_23 ) ;
F_34 ( & V_26 -> V_22 -> V_23 ,
3000 ) ;
F_35 ( & V_26 -> V_22 -> V_23 ) ;
return V_21 ;
V_38:
F_22 ( V_25 ) ;
V_37:
F_23 ( V_25 ) ;
V_33:
return V_21 ;
}
static int F_36 ( struct V_39 * V_23 )
{
struct V_40 * V_22 = F_37 ( V_23 ) ;
struct V_28 * V_29 = F_38 ( V_22 ) ;
struct V_1 * V_26 = F_39 ( V_29 ) ;
return F_1 ( V_26 , false ) ;
}
static int F_40 ( struct V_39 * V_23 )
{
struct V_40 * V_22 = F_37 ( V_23 ) ;
struct V_28 * V_29 = F_38 ( V_22 ) ;
struct V_1 * V_26 = F_39 ( V_29 ) ;
return F_1 ( V_26 , true ) ;
}

static int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
int V_5 ;
T_1 V_6 = 0 ;
if ( V_3 ) {
if ( F_2 ( V_2 -> V_7 ) )
return - V_8 ;
F_3 ( & V_2 -> V_9 ) ;
V_4 = F_4 ( V_2 -> V_7 ,
V_2 -> V_10 . V_11 ,
V_2 -> V_10 . V_12 ,
V_13 ) ;
V_5 = F_4 ( V_2 -> V_7 ,
V_2 -> V_14 . V_11 ,
V_2 -> V_14 . V_12 ,
V_15 ) ;
V_6 = F_5 ( V_2 ) ;
} else {
if ( ! F_6 ( & V_2 -> V_9 ) )
return 0 ;
F_7 ( V_2 -> V_7 ) ;
V_4 = F_4 ( V_2 -> V_7 ,
V_2 -> V_10 . V_11 ,
V_2 -> V_10 . V_12 ,
V_16 ) ;
V_5 = F_4 ( V_2 -> V_7 ,
V_2 -> V_14 . V_11 ,
V_2 -> V_14 . V_12 ,
V_17 ) ;
}
if ( V_4 >= 0 ) {
V_4 += V_2 -> V_10 . V_18 ;
F_8 ( V_2 -> V_7 , V_2 -> V_10 . V_11 ,
V_2 -> V_10 . V_12 , sizeof( V_4 ) ,
& V_4 ) ;
}
if ( V_5 >= 0 ) {
V_5 += V_2 -> V_14 . V_18 ;
F_8 ( V_2 -> V_7 , V_2 -> V_14 . V_11 ,
V_2 -> V_14 . V_12 ,
sizeof( V_5 ) ,
& V_5 ) ;
}
F_9 ( V_2 -> V_7 , V_2 -> V_10 . V_11 ,
V_2 -> V_10 . V_12 ,
sizeof( V_4 ) , & V_4 ) ;
if ( V_3 && V_6 )
F_10 ( V_6 * 2 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , bool V_3 )
{
#ifdef F_12
int V_19 ;
if ( V_3 )
V_19 = F_13 ( & V_2 -> V_20 -> V_21 ) ;
else {
F_14 ( & V_2 -> V_20 -> V_21 ) ;
V_19 = F_15 ( & V_2 -> V_20 -> V_21 ) ;
}
if ( V_19 < 0 ) {
if ( V_3 )
F_16 ( & V_2 -> V_20 -> V_21 ) ;
return V_19 ;
}
return 0 ;
#else
return F_1 ( V_2 , V_3 ) ;
#endif
}
static int F_17 ( struct V_22 * V_23 ,
bool V_3 )
{
return F_11 ( F_18 ( V_23 ) , V_3 ) ;
}
void F_19 ( struct V_1 * V_24 )
{
F_20 ( V_24 -> V_25 ) ;
F_21 ( V_24 -> V_25 ) ;
}
int F_22 ( struct V_26 * V_27 , const char * V_28 ,
struct V_1 * V_24 )
{
int V_19 ;
struct V_22 * V_23 ;
V_23 = F_23 ( L_1 , V_28 , V_27 -> V_29 ) ;
if ( V_23 == NULL ) {
F_24 ( & V_27 -> V_21 , L_2 ) ;
V_19 = - V_30 ;
goto V_31;
}
V_23 -> V_21 . V_32 = V_27 -> V_21 . V_32 ;
F_25 ( V_23 , V_24 ) ;
V_23 -> V_33 = & V_34 ;
V_19 = F_26 ( V_23 ) ;
if ( V_19 ) {
F_24 ( & V_27 -> V_21 , L_3 ) ;
goto V_35;
}
V_24 -> V_25 = V_23 ;
V_27 -> V_23 = F_27 ( V_23 ) ;
V_19 = F_28 ( & V_27 -> V_21 ) ;
if ( V_19 )
goto V_36;
F_29 ( V_27 , V_24 ) ;
F_30 ( & V_24 -> V_20 -> V_21 , true ) ;
F_31 ( & V_24 -> V_20 -> V_21 ) ;
F_32 ( & V_24 -> V_20 -> V_21 ,
3000 ) ;
F_33 ( & V_24 -> V_20 -> V_21 ) ;
return V_19 ;
V_36:
F_20 ( V_23 ) ;
V_35:
F_21 ( V_23 ) ;
V_31:
return V_19 ;
}
static int F_34 ( struct V_37 * V_21 )
{
struct V_38 * V_20 = F_35 ( V_21 ) ;
struct V_26 * V_27 = F_36 ( V_20 ) ;
struct V_1 * V_24 = F_37 ( V_27 ) ;
return F_1 ( V_24 , false ) ;
}
static int F_38 ( struct V_37 * V_21 )
{
struct V_38 * V_20 = F_35 ( V_21 ) ;
struct V_26 * V_27 = F_36 ( V_20 ) ;
struct V_1 * V_24 = F_37 ( V_27 ) ;
return F_1 ( V_24 , true ) ;
}

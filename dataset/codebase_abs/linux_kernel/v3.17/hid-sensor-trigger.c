int F_1 ( struct V_1 * V_2 , bool V_3 )
{
int V_4 ;
int V_5 ;
if ( V_3 ) {
if ( F_2 ( V_2 -> V_6 ) )
return - V_7 ;
F_3 ( & V_2 -> V_8 ) ;
V_4 = F_4 ( V_2 -> V_6 ,
V_2 -> V_9 . V_10 ,
V_2 -> V_9 . V_11 ,
V_12 ) ;
V_5 = F_4 ( V_2 -> V_6 ,
V_2 -> V_13 . V_10 ,
V_2 -> V_13 . V_11 ,
V_14 ) ;
} else {
if ( ! F_5 ( & V_2 -> V_8 ) )
return 0 ;
F_6 ( V_2 -> V_6 ) ;
V_4 = F_4 ( V_2 -> V_6 ,
V_2 -> V_9 . V_10 ,
V_2 -> V_9 . V_11 ,
V_15 ) ;
V_5 = F_4 ( V_2 -> V_6 ,
V_2 -> V_13 . V_10 ,
V_2 -> V_13 . V_11 ,
V_16 ) ;
}
if ( V_4 >= 0 ) {
V_4 += V_2 -> V_9 . V_17 ;
F_7 ( V_2 -> V_6 , V_2 -> V_9 . V_10 ,
V_2 -> V_9 . V_11 ,
( V_18 ) V_4 ) ;
}
if ( V_5 >= 0 ) {
V_5 += V_2 -> V_13 . V_17 ;
F_7 ( V_2 -> V_6 , V_2 -> V_13 . V_10 ,
V_2 -> V_13 . V_11 ,
( V_18 ) V_5 ) ;
}
F_8 ( V_2 -> V_6 , V_2 -> V_9 . V_10 ,
V_2 -> V_9 . V_11 ,
& V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 ,
bool V_3 )
{
return F_1 ( F_10 ( V_20 ) , V_3 ) ;
}
void F_11 ( struct V_1 * V_21 )
{
F_12 ( V_21 -> V_22 ) ;
F_13 ( V_21 -> V_22 ) ;
}
int F_14 ( struct V_23 * V_24 , const char * V_25 ,
struct V_1 * V_21 )
{
int V_26 ;
struct V_19 * V_20 ;
V_20 = F_15 ( L_1 , V_25 , V_24 -> V_27 ) ;
if ( V_20 == NULL ) {
F_16 ( & V_24 -> V_28 , L_2 ) ;
V_26 = - V_29 ;
goto V_30;
}
V_20 -> V_28 . V_31 = V_24 -> V_28 . V_31 ;
F_17 ( V_20 , V_21 ) ;
V_20 -> V_32 = & V_33 ;
V_26 = F_18 ( V_20 ) ;
if ( V_26 ) {
F_16 ( & V_24 -> V_28 , L_3 ) ;
goto V_34;
}
V_21 -> V_22 = V_20 ;
V_24 -> V_20 = F_19 ( V_20 ) ;
return V_26 ;
V_34:
F_13 ( V_20 ) ;
V_30:
return V_26 ;
}

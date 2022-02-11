bool F_1 ( struct V_1 * * V_2 )
{
struct V_1 * V_3 = * V_2 ;
T_1 V_4 = V_3 -> V_5 & V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
V_8 = F_2 ( V_3 -> V_11 , V_4 ) ;
if ( ! V_8 ) {
if ( V_4 )
V_3 -> V_12 = V_13 ;
return false ;
}
V_3 = * V_2 = F_3 ( V_3 , V_14 ) ;
if ( F_4 ( ! V_3 ) )
return false ;
V_3 -> V_11 = V_8 ;
if ( V_3 -> V_12 == V_13 ) {
if ( ! F_5 ( F_6 ( V_3 ) -> V_15 ,
V_8 -> V_16 ) )
V_3 -> V_12 = V_17 ;
}
if ( ! ( F_7 ( V_8 ) -> V_18 & V_19 ) ) {
unsigned int V_20 = V_3 -> V_21 - F_8 ( V_3 ) ;
F_9 ( V_3 , V_20 ) ;
V_3 = * V_2 = F_10 ( V_3 , V_3 -> V_5 ) ;
if ( ! V_3 )
return false ;
F_11 ( V_3 , V_20 + V_22 ) ;
F_12 ( V_3 ) ;
}
V_3 -> V_23 = F_13 ( V_8 , V_3 -> V_5 ) ;
V_3 -> V_5 = 0 ;
V_10 = F_14 ( F_7 ( V_8 ) -> V_9 ) ;
F_15 ( & V_10 -> V_24 ) ;
V_10 -> V_25 ++ ;
V_10 -> V_26 += V_3 -> V_27 ;
if ( V_3 -> V_12 == V_28 )
V_10 -> V_29 ++ ;
F_16 ( & V_10 -> V_24 ) ;
return true ;
}
struct V_7 * F_17 ( const struct V_7 * V_11 )
{
return F_7 ( V_11 ) -> V_30 ;
}
T_1 F_18 ( const struct V_7 * V_11 )
{
return F_7 ( V_11 ) -> V_4 ;
}
int F_19 ( struct V_1 * V_3 , struct V_31 * V_32 ,
T_1 V_5 , int V_33 )
{
F_20 ( V_3 , V_5 ) ;
return V_33 ? F_21 ( V_3 ) : F_22 ( V_3 ) ;
}
T_2 F_23 ( struct V_34 * V_35 , struct V_31 * V_32 ,
unsigned int V_5 , struct V_1 * V_3 )
{
F_20 ( V_3 , V_5 ) ;
return F_24 ( V_35 , V_3 ) ;
}
T_2 F_25 ( struct V_34 * V_35 , struct V_31 * V_32 ,
unsigned int V_5 )
{
F_20 ( V_35 -> V_3 , V_5 ) ;
return F_26 ( V_35 ) ;
}
static struct V_1 * F_27 ( struct V_1 * V_3 )
{
if ( F_28 ( V_3 , F_29 ( V_3 ) ) < 0 )
return NULL ;
memmove ( V_3 -> V_21 - V_36 , V_3 -> V_21 - V_37 , 2 * V_38 ) ;
V_3 -> V_39 += V_22 ;
F_12 ( V_3 ) ;
return V_3 ;
}
static void F_30 ( struct V_1 * V_3 , struct V_40 * V_41 )
{
T_3 V_42 ;
unsigned char * V_43 ;
V_42 = V_41 -> V_44 ;
if ( F_31 ( V_42 ) >= 1536 ) {
V_3 -> V_45 = V_42 ;
return;
}
V_43 = V_3 -> V_21 ;
if ( * ( unsigned short * ) V_43 == 0xFFFF )
V_3 -> V_45 = F_32 ( V_46 ) ;
else
V_3 -> V_45 = F_32 ( V_47 ) ;
}
struct V_1 * F_33 ( struct V_1 * V_3 )
{
struct V_40 * V_41 ;
T_1 V_5 ;
if ( F_4 ( F_34 ( V_3 ) ) ) {
return V_3 ;
}
V_3 = F_3 ( V_3 , V_14 ) ;
if ( F_4 ( ! V_3 ) )
goto V_48;
if ( F_4 ( ! F_35 ( V_3 , V_22 ) ) )
goto V_48;
V_41 = (struct V_40 * ) V_3 -> V_21 ;
V_5 = F_31 ( V_41 -> V_49 ) ;
F_20 ( V_3 , V_5 ) ;
F_36 ( V_3 , V_22 ) ;
F_30 ( V_3 , V_41 ) ;
V_3 = F_27 ( V_3 ) ;
if ( F_4 ( ! V_3 ) )
goto V_48;
return V_3 ;
V_48:
F_37 ( V_3 ) ;
return NULL ;
}

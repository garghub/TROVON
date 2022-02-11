bool F_1 ( struct V_1 * * V_2 , bool V_3 )
{
struct V_1 * V_4 = * V_2 ;
T_1 V_5 = V_4 -> V_6 & V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_2 ( V_4 -> V_12 , V_5 ) ;
if ( ! V_9 ) {
if ( V_5 && V_3 )
V_4 -> V_13 = V_14 ;
return false ;
}
V_4 = * V_2 = F_3 ( V_4 , V_15 ) ;
if ( F_4 ( ! V_4 ) )
return false ;
V_4 -> V_12 = V_9 ;
if ( V_4 -> V_13 == V_14 ) {
if ( ! F_5 ( F_6 ( V_4 ) -> V_16 ,
V_9 -> V_17 ) )
V_4 -> V_13 = V_18 ;
}
if ( ! ( F_7 ( V_9 ) -> V_19 & V_20 ) ) {
unsigned int V_21 = V_4 -> V_22 - F_8 ( V_4 ) ;
F_9 ( V_4 , V_21 ) ;
V_4 = * V_2 = F_10 ( V_4 , V_4 -> V_6 ) ;
if ( ! V_4 )
return false ;
F_11 ( V_4 , V_21 + V_23 ) ;
F_12 ( V_4 ) ;
}
V_4 -> V_24 = F_13 ( V_9 , V_4 -> V_6 ) ;
V_4 -> V_6 = 0 ;
V_11 = F_14 ( F_7 ( V_9 ) -> V_10 ) ;
F_15 ( & V_11 -> V_25 ) ;
V_11 -> V_26 ++ ;
V_11 -> V_27 += V_4 -> V_28 ;
if ( V_4 -> V_13 == V_29 )
V_11 -> V_30 ++ ;
F_16 ( & V_11 -> V_25 ) ;
return true ;
}
struct V_8 * F_17 ( struct V_8 * V_31 ,
T_1 V_5 )
{
struct V_32 * V_33 = F_18 ( V_31 -> V_34 ) ;
if ( V_33 ) {
return F_19 ( V_33 , V_5 ) ;
} else {
if ( F_20 ( V_31 ) )
return F_17 ( V_31 -> V_35 , V_5 ) ;
}
return NULL ;
}
struct V_8 * F_21 ( const struct V_8 * V_12 )
{
return F_7 ( V_12 ) -> V_31 ;
}
T_1 F_22 ( const struct V_8 * V_12 )
{
return F_7 ( V_12 ) -> V_5 ;
}
static struct V_1 * F_23 ( struct V_1 * V_4 )
{
if ( F_24 ( V_4 , F_25 ( V_4 ) ) < 0 )
return NULL ;
memmove ( V_4 -> V_22 - V_36 , V_4 -> V_22 - V_37 , 2 * V_38 ) ;
V_4 -> V_39 += V_23 ;
F_12 ( V_4 ) ;
return V_4 ;
}
static void F_26 ( struct V_1 * V_4 , struct V_40 * V_41 )
{
T_2 V_42 ;
unsigned char * V_43 ;
V_42 = V_41 -> V_44 ;
if ( F_27 ( V_42 ) >= 1536 ) {
V_4 -> V_45 = V_42 ;
return;
}
V_43 = V_4 -> V_22 ;
if ( * ( unsigned short * ) V_43 == 0xFFFF )
V_4 -> V_45 = F_28 ( V_46 ) ;
else
V_4 -> V_45 = F_28 ( V_47 ) ;
}
struct V_1 * F_29 ( struct V_1 * V_4 )
{
struct V_40 * V_41 ;
T_1 V_6 ;
if ( F_4 ( F_30 ( V_4 ) ) ) {
return V_4 ;
}
V_4 = F_3 ( V_4 , V_15 ) ;
if ( F_4 ( ! V_4 ) )
goto V_48;
if ( F_4 ( ! F_31 ( V_4 , V_23 ) ) )
goto V_48;
V_41 = (struct V_40 * ) V_4 -> V_22 ;
V_6 = F_27 ( V_41 -> V_49 ) ;
F_32 ( V_4 , V_6 ) ;
F_33 ( V_4 , V_23 ) ;
F_26 ( V_4 , V_41 ) ;
V_4 = F_23 ( V_4 ) ;
if ( F_4 ( ! V_4 ) )
goto V_48;
F_34 ( V_4 ) ;
F_35 ( V_4 ) ;
return V_4 ;
V_48:
F_36 ( V_4 ) ;
return NULL ;
}

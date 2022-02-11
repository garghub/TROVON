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
struct V_7 * F_17 ( struct V_7 * V_30 ,
T_1 V_4 )
{
struct V_31 * V_32 = F_18 ( V_30 -> V_33 ) ;
if ( V_32 ) {
return F_19 ( V_32 , V_4 ) ;
} else {
if ( F_20 ( V_30 ) )
return F_17 ( V_30 -> V_34 , V_4 ) ;
}
return NULL ;
}
struct V_7 * F_21 ( const struct V_7 * V_11 )
{
return F_7 ( V_11 ) -> V_30 ;
}
T_1 F_22 ( const struct V_7 * V_11 )
{
return F_7 ( V_11 ) -> V_4 ;
}
static struct V_1 * F_23 ( struct V_1 * V_3 )
{
if ( F_24 ( V_3 , F_25 ( V_3 ) ) < 0 )
return NULL ;
memmove ( V_3 -> V_21 - V_35 , V_3 -> V_21 - V_36 , 2 * V_37 ) ;
V_3 -> V_38 += V_22 ;
F_12 ( V_3 ) ;
return V_3 ;
}
static void F_26 ( struct V_1 * V_3 , struct V_39 * V_40 )
{
T_2 V_41 ;
unsigned char * V_42 ;
V_41 = V_40 -> V_43 ;
if ( F_27 ( V_41 ) >= 1536 ) {
V_3 -> V_44 = V_41 ;
return;
}
V_42 = V_3 -> V_21 ;
if ( * ( unsigned short * ) V_42 == 0xFFFF )
V_3 -> V_44 = F_28 ( V_45 ) ;
else
V_3 -> V_44 = F_28 ( V_46 ) ;
}
struct V_1 * F_29 ( struct V_1 * V_3 )
{
struct V_39 * V_40 ;
T_1 V_5 ;
if ( F_4 ( F_30 ( V_3 ) ) ) {
return V_3 ;
}
V_3 = F_3 ( V_3 , V_14 ) ;
if ( F_4 ( ! V_3 ) )
goto V_47;
if ( F_4 ( ! F_31 ( V_3 , V_22 ) ) )
goto V_47;
V_40 = (struct V_39 * ) V_3 -> V_21 ;
V_5 = F_27 ( V_40 -> V_48 ) ;
F_32 ( V_3 , V_5 ) ;
F_33 ( V_3 , V_22 ) ;
F_26 ( V_3 , V_40 ) ;
V_3 = F_23 ( V_3 ) ;
if ( F_4 ( ! V_3 ) )
goto V_47;
F_34 ( V_3 ) ;
F_35 ( V_3 ) ;
return V_3 ;
V_47:
F_36 ( V_3 ) ;
return NULL ;
}

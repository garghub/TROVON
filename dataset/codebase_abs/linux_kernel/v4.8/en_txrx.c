struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = & V_3 -> V_5 ;
T_1 V_6 = F_2 ( V_5 ) ;
struct V_1 * V_7 = F_3 ( V_5 , V_6 ) ;
int V_8 = V_7 -> V_9 & V_10 ;
int V_11 = F_4 ( V_5 ) & 1 ;
if ( V_8 != V_11 )
return NULL ;
F_5 () ;
return V_7 ;
}
static void F_6 ( struct V_2 * V_3 )
{
struct V_12 * V_13 = F_7 ( V_3 , struct V_12 , V_3 ) ;
struct V_14 * V_5 ;
struct V_1 * V_7 ;
T_2 V_15 ;
if ( F_8 ( F_9 ( V_16 , & V_13 -> V_17 ) ) )
return;
V_7 = F_1 ( V_3 ) ;
if ( F_10 ( ! V_7 ) )
return;
V_5 = & V_13 -> V_5 ;
V_15 = V_13 -> V_18 ;
do {
T_2 V_6 = F_11 ( V_7 -> V_19 ) & V_5 -> V_20 ;
struct V_21 * V_22 = & V_13 -> V_23 [ V_6 ] ;
F_12 ( & V_3 -> V_5 ) ;
V_15 += V_22 -> V_24 ;
if ( F_8 ( ( V_7 -> V_9 >> 4 ) != V_25 ) ) {
F_13 ( true , L_1 ,
V_7 -> V_9 ) ;
break;
}
switch ( V_22 -> V_26 ) {
case V_27 :
break;
case V_28 :
F_14 ( & V_13 -> V_29 -> V_30 ) ;
break;
default:
F_13 ( true ,
L_2 ,
V_22 -> V_26 ) ;
}
} while ( ( V_7 = F_1 ( V_3 ) ) );
F_15 ( & V_3 -> V_5 ) ;
F_16 () ;
V_13 -> V_18 = V_15 ;
}
int F_17 ( struct V_31 * V_32 , int V_33 )
{
struct V_34 * V_35 = F_7 ( V_32 , struct V_34 ,
V_32 ) ;
bool V_36 = false ;
int V_37 ;
int V_38 ;
F_18 ( V_39 , & V_35 -> V_40 ) ;
for ( V_38 = 0 ; V_38 < V_35 -> V_41 ; V_38 ++ )
V_36 |= F_19 ( & V_35 -> V_13 [ V_38 ] . V_3 , V_33 ) ;
V_37 = F_20 ( & V_35 -> V_30 . V_3 , V_33 ) ;
V_36 |= V_37 == V_33 ;
F_6 ( & V_35 -> V_42 . V_3 ) ;
V_36 |= F_21 ( & V_35 -> V_30 ) ;
if ( V_36 )
return V_33 ;
F_22 ( V_32 , V_37 ) ;
if ( F_9 ( V_39 , & V_35 -> V_40 ) ) {
F_23 ( V_32 ) ;
return V_37 ;
}
for ( V_38 = 0 ; V_38 < V_35 -> V_41 ; V_38 ++ )
F_24 ( & V_35 -> V_13 [ V_38 ] . V_3 ) ;
if ( F_9 ( V_43 , & V_35 -> V_30 . V_17 ) )
F_25 ( & V_35 -> V_30 ) ;
F_24 ( & V_35 -> V_30 . V_3 ) ;
F_24 ( & V_35 -> V_42 . V_3 ) ;
return V_37 ;
}
void F_26 ( struct V_44 * V_45 )
{
struct V_2 * V_3 = F_7 ( V_45 , struct V_2 , V_45 ) ;
V_3 -> V_46 ++ ;
F_27 ( V_39 , & V_3 -> V_29 -> V_40 ) ;
F_23 ( V_3 -> V_32 ) ;
}
void F_28 ( struct V_44 * V_45 , enum V_47 V_48 )
{
struct V_2 * V_3 = F_7 ( V_45 , struct V_2 , V_45 ) ;
struct V_34 * V_35 = V_3 -> V_29 ;
struct V_49 * V_50 = V_35 -> V_50 ;
struct V_51 * V_52 = V_50 -> V_52 ;
F_29 ( V_52 , L_3 ,
V_53 , V_45 -> V_54 , V_48 ) ;
}

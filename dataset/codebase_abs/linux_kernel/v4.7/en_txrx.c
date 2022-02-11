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
struct V_12 * V_5 ;
struct V_1 * V_7 ;
struct V_13 * V_14 ;
T_2 V_15 ;
V_7 = F_1 ( V_3 ) ;
if ( F_7 ( ! V_7 ) )
return;
V_14 = F_8 ( V_3 , struct V_13 , V_3 ) ;
V_5 = & V_14 -> V_5 ;
V_15 = V_14 -> V_16 ;
do {
T_2 V_6 = F_9 ( V_7 -> V_17 ) & V_5 -> V_18 ;
struct V_19 * V_20 = & V_14 -> V_21 [ V_6 ] ;
F_10 ( & V_3 -> V_5 ) ;
V_15 += V_20 -> V_22 ;
if ( F_11 ( ( V_7 -> V_9 >> 4 ) != V_23 ) ) {
F_12 ( true , L_1 ,
V_7 -> V_9 ) ;
break;
}
switch ( V_20 -> V_24 ) {
case V_25 :
break;
case V_26 :
F_13 ( & V_14 -> V_27 -> V_28 ) ;
break;
default:
F_12 ( true ,
L_2 ,
V_20 -> V_24 ) ;
}
} while ( ( V_7 = F_1 ( V_3 ) ) );
F_14 ( & V_3 -> V_5 ) ;
F_15 () ;
V_14 -> V_16 = V_15 ;
}
int F_16 ( struct V_29 * V_30 , int V_31 )
{
struct V_32 * V_33 = F_8 ( V_30 , struct V_32 ,
V_30 ) ;
bool V_34 = false ;
int V_35 ;
int V_36 ;
F_17 ( V_37 , & V_33 -> V_38 ) ;
for ( V_36 = 0 ; V_36 < V_33 -> V_39 ; V_36 ++ )
V_34 |= F_18 ( & V_33 -> V_14 [ V_36 ] . V_3 , V_31 ) ;
V_35 = F_19 ( & V_33 -> V_28 . V_3 , V_31 ) ;
V_34 |= V_35 == V_31 ;
F_6 ( & V_33 -> V_40 . V_3 ) ;
V_34 |= F_20 ( & V_33 -> V_28 ) ;
if ( V_34 )
return V_31 ;
F_21 ( V_30 , V_35 ) ;
if ( F_22 ( V_37 , & V_33 -> V_38 ) ) {
F_23 ( V_30 ) ;
return V_35 ;
}
for ( V_36 = 0 ; V_36 < V_33 -> V_39 ; V_36 ++ )
F_24 ( & V_33 -> V_14 [ V_36 ] . V_3 ) ;
F_24 ( & V_33 -> V_28 . V_3 ) ;
F_24 ( & V_33 -> V_40 . V_3 ) ;
return V_35 ;
}
void F_25 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = F_8 ( V_42 , struct V_2 , V_42 ) ;
F_26 ( V_37 , & V_3 -> V_27 -> V_38 ) ;
F_23 ( V_3 -> V_30 ) ;
}
void F_27 ( struct V_41 * V_42 , enum V_43 V_44 )
{
struct V_2 * V_3 = F_8 ( V_42 , struct V_2 , V_42 ) ;
struct V_32 * V_33 = V_3 -> V_27 ;
struct V_45 * V_46 = V_33 -> V_46 ;
struct V_47 * V_48 = V_46 -> V_48 ;
F_28 ( V_48 , L_3 ,
V_49 , V_42 -> V_50 , V_44 ) ;
}

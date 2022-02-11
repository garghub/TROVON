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
if ( F_8 ( ! F_9 ( V_16 , & V_13 -> V_17 ) ) )
return;
V_7 = F_1 ( V_3 ) ;
if ( F_10 ( ! V_7 ) )
return;
V_5 = & V_13 -> V_5 ;
V_15 = V_13 -> V_18 ;
do {
T_2 V_6 = F_11 ( V_7 -> V_19 ) & V_5 -> V_20 ;
struct V_21 * V_22 = & V_13 -> V_23 . V_24 [ V_6 ] ;
F_12 ( & V_3 -> V_5 ) ;
V_15 += V_22 -> V_25 ;
if ( F_8 ( ( V_7 -> V_9 >> 4 ) != V_26 ) ) {
F_13 ( true , L_1 ,
V_7 -> V_9 ) ;
break;
}
switch ( V_22 -> V_27 ) {
case V_28 :
break;
case V_29 :
F_14 ( & V_13 -> V_30 -> V_31 ) ;
break;
default:
F_13 ( true ,
L_2 ,
V_22 -> V_27 ) ;
}
} while ( ( V_7 = F_1 ( V_3 ) ) );
F_15 ( & V_3 -> V_5 ) ;
F_16 () ;
V_13 -> V_18 = V_15 ;
}
static inline bool F_17 ( struct V_2 * V_3 )
{
struct V_12 * V_13 ;
T_2 V_15 ;
int V_32 ;
V_13 = F_7 ( V_3 , struct V_12 , V_3 ) ;
if ( F_8 ( ! F_9 ( V_16 , & V_13 -> V_17 ) ) )
return false ;
V_15 = V_13 -> V_18 ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ ) {
struct V_1 * V_7 ;
T_2 V_19 ;
bool V_34 ;
V_7 = F_1 ( V_3 ) ;
if ( ! V_7 )
break;
F_12 ( & V_3 -> V_5 ) ;
V_19 = F_11 ( V_7 -> V_19 ) ;
do {
struct V_21 * V_35 ;
struct V_36 * V_37 ;
T_2 V_6 ;
V_34 = ( V_15 == V_19 ) ;
V_6 = V_15 & V_13 -> V_5 . V_20 ;
V_37 = & V_13 -> V_23 . V_38 . V_37 [ V_6 ] ;
V_35 = & V_13 -> V_23 . V_38 . V_39 [ V_6 ] ;
if ( F_8 ( V_35 -> V_27 == V_28 ) ) {
V_15 ++ ;
continue;
}
V_15 += V_35 -> V_25 ;
F_18 ( & V_13 -> V_30 -> V_31 , V_37 , true ) ;
} while ( ! V_34 );
}
F_15 ( & V_3 -> V_5 ) ;
F_16 () ;
V_13 -> V_18 = V_15 ;
return ( V_32 == V_33 ) ;
}
int F_19 ( struct V_40 * V_41 , int V_42 )
{
struct V_43 * V_44 = F_7 ( V_41 , struct V_43 ,
V_41 ) ;
bool V_45 = false ;
int V_46 ;
int V_32 ;
F_20 ( V_47 , & V_44 -> V_48 ) ;
for ( V_32 = 0 ; V_32 < V_44 -> V_49 ; V_32 ++ )
V_45 |= F_21 ( & V_44 -> V_13 [ V_32 ] . V_3 , V_42 ) ;
V_46 = F_22 ( & V_44 -> V_31 . V_3 , V_42 ) ;
V_45 |= V_46 == V_42 ;
if ( V_44 -> V_38 )
V_45 |= F_17 ( & V_44 -> V_50 . V_3 ) ;
F_6 ( & V_44 -> V_51 . V_3 ) ;
V_45 |= F_23 ( & V_44 -> V_31 ) ;
if ( V_45 )
return V_42 ;
F_24 ( V_41 , V_46 ) ;
if ( F_9 ( V_47 , & V_44 -> V_48 ) ) {
F_25 ( V_41 ) ;
return V_46 ;
}
for ( V_32 = 0 ; V_32 < V_44 -> V_49 ; V_32 ++ )
F_26 ( & V_44 -> V_13 [ V_32 ] . V_3 ) ;
if ( F_9 ( V_52 , & V_44 -> V_31 . V_17 ) )
F_27 ( & V_44 -> V_31 ) ;
F_26 ( & V_44 -> V_31 . V_3 ) ;
F_26 ( & V_44 -> V_51 . V_3 ) ;
return V_46 ;
}
void F_28 ( struct V_53 * V_54 )
{
struct V_2 * V_3 = F_7 ( V_54 , struct V_2 , V_54 ) ;
V_3 -> V_55 ++ ;
F_29 ( V_47 , & V_3 -> V_30 -> V_48 ) ;
F_25 ( V_3 -> V_41 ) ;
}
void F_30 ( struct V_53 * V_54 , enum V_56 V_57 )
{
struct V_2 * V_3 = F_7 ( V_54 , struct V_2 , V_54 ) ;
struct V_43 * V_44 = V_3 -> V_30 ;
struct V_58 * V_59 = V_44 -> V_59 ;
struct V_60 * V_61 = V_59 -> V_61 ;
F_31 ( V_61 , L_3 ,
V_62 , V_54 -> V_63 , V_57 ) ;
}

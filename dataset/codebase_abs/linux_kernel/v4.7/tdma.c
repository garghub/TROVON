bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int V_5 )
{
if ( ! V_4 -> V_6 )
return false ;
V_4 -> V_7 += V_5 ;
V_4 -> V_8 += V_5 ;
if ( V_4 -> V_8 == F_2 ( V_4 -> V_6 ) ) {
if ( F_3 ( V_4 -> V_6 ) )
return false ;
V_4 -> V_8 = 0 ;
V_4 -> V_6 = F_4 ( V_4 -> V_6 ) ;
}
if ( V_4 -> V_7 == V_2 -> V_9 )
return false ;
return true ;
}
void F_5 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_14 . V_13 ;
F_6 ( 0 , V_13 -> V_15 + V_16 ) ;
F_7 ( V_13 , V_17 ) ;
F_6 ( V_18 | V_19 |
V_20 | V_21 ,
V_13 -> V_15 + V_22 ) ;
F_6 ( V_23 | V_24 |
V_25 | V_26 ,
V_13 -> V_15 + V_16 ) ;
F_6 ( V_11 -> V_27 . V_28 -> V_29 ,
V_13 -> V_15 + V_30 ) ;
F_8 ( V_31 , V_13 -> V_15 + V_32 ) ;
}
void F_9 ( struct V_10 * V_11 )
{
struct V_33 * V_34 ;
for ( V_34 = V_11 -> V_27 . V_28 ; V_34 ; ) {
struct V_33 * V_35 = V_34 ;
if ( V_34 -> V_36 & V_37 )
F_10 ( V_38 -> V_39 -> V_40 , V_34 -> V_41 ,
F_11 ( V_34 -> V_42 ) ) ;
V_34 = V_34 -> V_43 ;
F_10 ( V_38 -> V_39 -> V_44 , V_35 ,
V_35 -> V_29 ) ;
}
V_11 -> V_27 . V_28 = NULL ;
V_11 -> V_27 . V_45 = NULL ;
}
void F_12 ( struct V_10 * V_11 ,
struct V_12 * V_13 )
{
struct V_33 * V_34 ;
for ( V_34 = V_11 -> V_27 . V_28 ; V_34 ; V_34 = V_34 -> V_43 ) {
if ( V_34 -> V_36 & V_46 )
V_34 -> V_47 = F_13 ( V_34 -> V_47 + V_13 -> V_48 ) ;
if ( V_34 -> V_36 & V_49 )
V_34 -> V_42 = F_13 ( V_34 -> V_42 + V_13 -> V_48 ) ;
if ( V_34 -> V_36 & V_37 )
F_14 ( V_13 , V_34 -> V_41 ) ;
}
}
static struct V_33 *
F_15 ( struct V_50 * V_27 , T_1 V_36 )
{
struct V_33 * V_51 = NULL ;
T_2 V_52 ;
V_51 = F_16 ( V_38 -> V_39 -> V_44 , V_36 ,
& V_52 ) ;
if ( ! V_51 )
return F_17 ( - V_53 ) ;
V_51 -> V_29 = V_52 ;
if ( V_27 -> V_45 ) {
V_27 -> V_45 -> V_54 = F_13 ( V_52 ) ;
V_27 -> V_45 -> V_43 = V_51 ;
} else {
V_27 -> V_28 = V_51 ;
}
V_27 -> V_45 = V_51 ;
return V_51 ;
}
struct V_55 * F_18 ( struct V_50 * V_27 ,
const struct V_55 * V_56 ,
bool V_57 ,
T_1 V_36 )
{
struct V_33 * V_34 ;
struct V_55 * V_41 ;
T_2 V_52 ;
unsigned int V_58 ;
V_34 = F_15 ( V_27 , V_36 ) ;
if ( F_19 ( V_34 ) )
return F_20 ( V_34 ) ;
V_41 = F_21 ( V_38 -> V_39 -> V_40 , V_36 , & V_52 ) ;
if ( ! V_41 )
return F_17 ( - V_53 ) ;
* V_41 = * V_56 ;
V_58 = V_57 ? sizeof( V_41 -> V_59 ) : sizeof( * V_41 ) ;
V_34 = V_27 -> V_45 ;
V_34 -> V_41 = V_41 ;
V_34 -> V_60 = F_13 ( V_58 | F_22 ( 31 ) ) ;
V_34 -> V_42 = F_13 ( V_52 ) ;
V_34 -> V_36 = V_46 | V_37 ;
return V_41 ;
}
int F_23 ( struct V_50 * V_27 ,
T_2 V_47 , T_2 V_42 , T_3 V_58 ,
T_3 V_36 , T_1 V_61 )
{
struct V_33 * V_34 ;
V_34 = F_15 ( V_27 , V_61 ) ;
if ( F_19 ( V_34 ) )
return F_24 ( V_34 ) ;
V_34 -> V_60 = F_13 ( V_58 | F_22 ( 31 ) ) ;
V_34 -> V_42 = V_42 ;
V_34 -> V_47 = V_47 ;
V_36 &= ( V_46 | V_49 ) ;
V_34 -> V_36 = V_36 | V_62 ;
return 0 ;
}
int F_25 ( struct V_50 * V_27 , T_1 V_36 )
{
struct V_33 * V_34 ;
V_34 = F_15 ( V_27 , V_36 ) ;
if ( F_19 ( V_34 ) )
return F_24 ( V_34 ) ;
return 0 ;
}
int F_26 ( struct V_50 * V_27 , T_1 V_36 )
{
struct V_33 * V_34 ;
V_34 = F_15 ( V_27 , V_36 ) ;
if ( F_19 ( V_34 ) )
return F_24 ( V_34 ) ;
V_34 -> V_60 = F_13 ( F_22 ( 31 ) ) ;
return 0 ;
}
int F_27 ( struct V_50 * V_27 ,
struct V_1 * V_63 ,
struct V_3 * V_4 ,
T_1 V_61 )
{
T_3 V_36 = V_4 -> V_64 == V_65 ?
V_46 : V_49 ;
unsigned int V_5 ;
do {
T_2 V_47 , V_42 ;
int V_66 ;
V_5 = F_28 ( V_63 , V_4 ) ;
if ( V_4 -> V_64 == V_65 ) {
V_47 = V_67 + V_4 -> V_7 ;
V_42 = F_29 ( V_4 -> V_6 ) + V_4 -> V_8 ;
} else {
V_47 = F_29 ( V_4 -> V_6 ) + V_4 -> V_8 ;
V_42 = V_67 + V_4 -> V_7 ;
}
V_66 = F_23 ( V_27 , V_47 , V_42 , V_5 ,
V_36 , V_61 ) ;
if ( V_66 )
return V_66 ;
} while ( F_1 ( V_63 , V_4 , V_5 ) );
return 0 ;
}
